#include <ultra64.h>
#include "constants.h"
#include "game/game_096700.h"
#include "game/acosfasinf.h"
#include "game/quaternion.h"
#include "game/camera.h"
#include "game/floor.h"
#include "game/ceil.h"
#include "game/tex.h"
#include "game/gfxmemory.h"
#include "game/bg.h"
#include "game/file.h"
#include "bss.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/model.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_PAL_BETA
u8 var8005efb0_2 = 0;
#endif

u32 var8005efb0 = 0;

bool g_ModelDistanceDisabled = false;
f32 g_ModelDistanceScale = 1;
bool var8005efbc = false;
f32 var8005efc0 = 0;
bool (*var8005efc4)(struct model *model, struct modelnode *node) = NULL;

#if VERSION >= VERSION_PAL_BETA
bool var8005efd8_2 = false;
#endif

struct gfxvtx *(*g_ModelVtxAllocatorFunc)(s32 numvertices) = NULL;
void (*g_ModelJointPositionedFunc)(s32 mtxindex, Mtxf *mtx) = NULL;

void modelSetDistanceChecksDisabled(bool disabled)
{
	g_ModelDistanceDisabled = disabled;
}

void modelSetDistanceScale(f32 scale)
{
	g_ModelDistanceScale = scale;
}

void modelSetVtxAllocatorFunc(struct gfxvtx *(*fn)(s32 numvertices))
{
	g_ModelVtxAllocatorFunc = fn;
}

s32 model0001a524(struct modelnode *node, s32 arg1)
{
	s32 index;
	union modelrodata *rodata1;
	union modelrodata *rodata2;
	union modelrodata *rodata3;

	while (node) {
		switch (node->type & 0xff) {
		case MODELNODETYPE_CHRINFO:
			rodata1 = node->rodata;
			return rodata1->chrinfo.mtxindex;
		case MODELNODETYPE_POSITION:
			rodata2 = node->rodata;
			return rodata2->position.mtxindexes[arg1 == 0x200 ? 2 : (arg1 == 0x100 ? 1 : 0)];
		case MODELNODETYPE_POSITIONHELD:
			rodata3 = node->rodata;
			return rodata3->positionheld.mtxindex;
		}

		node = node->parent;
	}

	return -1;
}

Mtxf *model0001a5cc(struct model *model, struct modelnode *node, s32 arg2)
{
	s32 index = model0001a524(node, arg2);

	if (index >= 0) {
		return &model->matrices[index];
	}

	return NULL;
}

Mtxf *model0001a60c(struct model *model)
{
	return model0001a5cc(model, model->filedata->rootnode, 0);
}

struct modelnode *model0001a634(struct model *model, s32 mtxindex)
{
	struct modelnode *node = model->filedata->rootnode;
	union modelrodata *rodata1;
	union modelrodata *rodata2;
	union modelrodata *rodata3;

	while (node) {
		switch (node->type & 0xff) {
		case MODELNODETYPE_CHRINFO:
			rodata1 = node->rodata;
			if (mtxindex == rodata1->chrinfo.mtxindex) {
				return node;
			}
			break;
		case MODELNODETYPE_POSITION:
			rodata2 = node->rodata;
			if (mtxindex == rodata2->position.mtxindexes[0]
					|| mtxindex == rodata2->position.mtxindexes[1]
					|| mtxindex == rodata2->position.mtxindexes[2]) {
				return node;
			}
			break;
		case MODELNODETYPE_POSITIONHELD:
			rodata3 = node->rodata;
			if (mtxindex == rodata3->positionheld.mtxindex) {
				return node;
			}
			break;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node && node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	return NULL;
}

struct modelnode *model0001a740(struct modelnode *node)
{
	while (node) {
		u32 type = node->type & 0xff;

		if (type == MODELNODETYPE_CHRINFO
				|| type == MODELNODETYPE_POSITION
				|| type == MODELNODETYPE_POSITIONHELD) {
			break;
		}

		node = node->parent;
	}

	return node;
}

struct modelnode *model0001a784(struct modelnode *node)
{
	while ((node = node->parent)) {
		u32 type = node->type & 0xff;

		if (type == MODELNODETYPE_CHRINFO
				|| type == MODELNODETYPE_POSITION
				|| type == MODELNODETYPE_POSITIONHELD) {
			break;
		}
	}

	return node;
}

struct modelnode *model0001a7cc(struct modelnode *basenode)
{
	struct modelnode *node = basenode->child;

	while (node) {
		u32 type = node->type & 0xff;

		if (type == MODELNODETYPE_CHRINFO
				|| type == MODELNODETYPE_POSITION
				|| type == MODELNODETYPE_POSITIONHELD) {
			break;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node == basenode) {
					node = NULL;
					break;
				}

				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	return node;
}

struct modelnode *model0001a85c(struct modelnode *basenode)
{
	struct modelnode *node = basenode;
	struct modelnode *next;
	u32 type;

	while (node) {
		if (node != basenode && node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node != basenode) {
					type = node->type & 0xff;

					if (type == MODELNODETYPE_CHRINFO
							|| type == MODELNODETYPE_POSITION
							|| type == MODELNODETYPE_POSITIONHELD) {
						node = NULL;
						break;
					}
				}

				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}

			if (!node) {
				break;
			}
		}

		type = node->type & 0xff;

		if (type == MODELNODETYPE_CHRINFO
				|| type == MODELNODETYPE_POSITION
				|| type == MODELNODETYPE_POSITIONHELD) {
			break;
		}
	}

	return node;
}

struct modelnode *modelGetPart(struct modelfiledata *modelfiledata, s32 partnum)
{
	s32 upper;
	s32 lower;
	u32 i;
	s16 *partnums;

	if (modelfiledata->numparts == 0) {
		return NULL;
	}

	partnums = (s16 *)&modelfiledata->parts[modelfiledata->numparts];
	lower = 0;
	upper = modelfiledata->numparts;

	while (upper >= lower) {
		i = (lower + upper) / 2;

		if (partnum == partnums[i]) {
			return modelfiledata->parts[i];
		}

		if (partnum < partnums[i]) {
			upper = i - 1;
		} else {
			lower = i + 1;
		}
	}

	return NULL;
}

void *modelGetPartRodata(struct modelfiledata *modelfiledata, s32 partnum)
{
	struct modelnode *node = modelGetPart(modelfiledata, partnum);

	if (node) {
		return node->rodata;
	}

	return NULL;
}

f32 model0001a9e8(struct model *model)
{
	Mtxf *mtx = model0001a60c(model);

	if (mtx) {
		return -mtx->m[3][2];
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
// ntsc-beta has this function in another file
void *modelGetNodeRwData(struct model *model, struct modelnode *node)
{
	u32 index = 0;
	union modelrwdata **rwdatas = model->rwdatas;

	switch (node->type & 0xff) {
	case MODELNODETYPE_CHRINFO:
		index = node->rodata->chrinfo.rwdataindex;
		break;
	case MODELNODETYPE_DL:
		index = node->rodata->dl.rwdataindex;
		break;
	case MODELNODETYPE_DISTANCE:
		index = node->rodata->distance.rwdataindex;
		break;
	case MODELNODETYPE_TOGGLE:
		index = node->rodata->toggle.rwdataindex;
		break;
	case MODELNODETYPE_REORDER:
		index = node->rodata->reorder.rwdataindex;
		break;
	case MODELNODETYPE_0B:
		index = node->rodata->type0b.rwdataindex;
		break;
	case MODELNODETYPE_CHRGUNFIRE:
		index = node->rodata->chrgunfire.rwdataindex;
		break;
	case MODELNODETYPE_HEADSPOT:
		index = node->rodata->headspot.rwdataindex;
		break;
	}

	while (node->parent) {
		node = node->parent;

		if ((node->type & 0xff) == MODELNODETYPE_HEADSPOT) {
			struct modelrwdata_headspot *tmp = modelGetNodeRwData(model, node);
			rwdatas = tmp->rwdatas;
			break;
		}
	}

	return &rwdatas[index];
}
#endif

void modelNodeGetPosition(struct model *model, struct modelnode *node, struct coord *pos)
{
	switch (node->type & 0xff) {
	case MODELNODETYPE_CHRINFO:
		{
			struct modelrwdata_chrinfo *rwdata = modelGetNodeRwData(model, node);
			*pos = rwdata->pos;
		}
		break;
	case MODELNODETYPE_POSITION:
		{
			struct modelrodata_position *rodata = &node->rodata->position;
			*pos = rodata->pos;
		}
		break;
	case MODELNODETYPE_POSITIONHELD:
		{
			struct modelrodata_positionheld *rodata = &node->rodata->positionheld;
			*pos = rodata->pos;
		}
		break;
	default:
		pos->x = 0;
		pos->y = 0;
		pos->z = 0;
		break;
	}
}

void modelNodeSetPosition(struct model *model, struct modelnode *node, struct coord *pos)
{
	switch (node->type & 0xff) {
	case MODELNODETYPE_CHRINFO:
		{
			struct modelrwdata_chrinfo *rwdata = modelGetNodeRwData(model, node);
			struct coord diff[1];

			diff[0].x = pos->x - rwdata->pos.x;
			diff[0].z = pos->z - rwdata->pos.z;

			rwdata->pos = *pos;

			rwdata->unk24.x += diff[0].x; rwdata->unk24.z += diff[0].z;
			rwdata->unk34.x += diff[0].x; rwdata->unk34.z += diff[0].z;
			rwdata->unk40.x += diff[0].x; rwdata->unk40.z += diff[0].z;
			rwdata->unk4c.x += diff[0].x; rwdata->unk4c.z += diff[0].z;
		}
		break;
	case MODELNODETYPE_POSITION:
		{
			struct modelrodata_position *rodata = &node->rodata->position;
			rodata->pos = *pos;
		}
		break;
	case MODELNODETYPE_POSITIONHELD:
		{
			struct modelrodata_positionheld *rodata = &node->rodata->positionheld;
			rodata->pos = *pos;
		}
		break;
	}
}

void modelGetRootPosition(struct model *model, struct coord *pos)
{
	modelNodeGetPosition(model, model->filedata->rootnode, pos);
}

void modelSetRootPosition(struct model *model, struct coord *pos)
{
	modelNodeSetPosition(model, model->filedata->rootnode, pos);
}

void modelNodeGetModelRelativePosition(struct model *model, struct modelnode *node, struct coord *pos)
{
	pos->x = 0;
	pos->y = 0;
	pos->z = 0;

	while (node) {
		struct coord nodepos;
		u32 type = node->type & 0xff;

		if (type == MODELNODETYPE_CHRINFO
				|| type == MODELNODETYPE_POSITION
				|| type == MODELNODETYPE_POSITIONHELD) {
			modelNodeGetPosition(model, node, &nodepos);
			pos->x += nodepos.x;
			pos->y += nodepos.y;
			pos->z += nodepos.z;
		}

		node = node->parent;
	}
}

f32 model0001ae44(struct model *model)
{
	if ((model->filedata->rootnode->type & 0xff) == MODELNODETYPE_CHRINFO) {
		union modelrwdata *rwdata = modelGetNodeRwData(model, model->filedata->rootnode);
		return rwdata->chrinfo.unk14;
	}

	return 0;
}

void model0001ae90(struct model *model, f32 angle)
{
	if ((model->filedata->rootnode->type & 0xff) == MODELNODETYPE_CHRINFO) {
		struct modelrwdata_chrinfo *rwdata = modelGetNodeRwData(model, model->filedata->rootnode);
		f32 diff = angle - rwdata->unk14;

		if (diff < 0) {
			diff += M_BADTAU;
		}

		rwdata->unk30 += diff;

		if (rwdata->unk30 >= M_BADTAU) {
			rwdata->unk30 -= M_BADTAU;
		}

		rwdata->unk20 += diff;

		if (rwdata->unk20 >= M_BADTAU) {
			rwdata->unk20 -= M_BADTAU;
		}

		rwdata->unk14 = angle;
	}
}

void modelSetScale(struct model *model, f32 scale)
{
	model->scale = scale;
}

void modelSetAnimScale(struct model *model, f32 scale)
{
	if (model->anim) {
		model->anim->animscale = scale;
	}
}

f32 model0001af80(struct model *model)
{
	return model->filedata->unk10 * model->scale;
}

void model0001af98(struct coord *arg0, struct coord *arg1, f32 frac)
{
	arg0->x += (arg1->x - arg0->x) * frac;
	arg0->y += (arg1->y - arg0->y) * frac;
	arg0->z += (arg1->z - arg0->z) * frac;
}

f32 model0001afe8(f32 arg0, f32 angle, f32 mult)
{
	f32 value = angle - arg0;

	if (angle < arg0) {
		value += M_BADTAU;
	}

	if (value < M_PI) {
		arg0 += value * mult;

		if (arg0 >= M_BADTAU) {
			arg0 -= M_BADTAU;
		}
	} else {
		arg0 -= (M_BADTAU - value) * mult;

		if (arg0 < 0) {
			arg0 += M_BADTAU;
		}
	}

	return arg0;
}

void model0001b07c(struct coord *arg0, struct coord *arg1, f32 mult)
{
	arg0->x = model0001afe8(arg0->x, arg1->x, mult);
	arg0->y = model0001afe8(arg0->y, arg1->y, mult);
	arg0->z = model0001afe8(arg0->z, arg1->z, mult);
}

void model0001b0e8(struct model *model, struct modelnode *node)
{
	union modelrwdata *rwdata;
	struct anim *anim = model->anim;
	struct coord sp34;
	struct coord sp28;
	f32 frac;

	if (!anim) {
		return;
	}

	rwdata = modelGetNodeRwData(model, node);

	if (rwdata->chrinfo.unk00) {
		return;
	}

	sp34 = rwdata->chrinfo.unk34;

	rwdata->chrinfo.unk14 = rwdata->chrinfo.unk30;

	if (g_Vars.in_cutscene && anim->speed > 0.0f) {
#if VERSION >= VERSION_PAL_BETA
		frac = floorf(anim->frac / anim->speed + 0.01f) * anim->speed;
#else
		frac = floorf(anim->frac / anim->speed) * anim->speed;
#endif
	} else {
		frac = anim->frac;
	}

	if (frac != 0.0f && rwdata->chrinfo.unk01) {
		model0001af98(&sp34, &rwdata->chrinfo.unk24, frac);

		rwdata->chrinfo.unk14 = model0001afe8(rwdata->chrinfo.unk30, rwdata->chrinfo.unk20, frac);
	}

	if (anim->animnum2 || anim->fracmerge) {
		if (rwdata->chrinfo.unk02) {
			f32 y = rwdata->chrinfo.unk4c.y;

			if (anim->frac2 != 0.0f) {
				y += (rwdata->chrinfo.unk40.y - y) * anim->frac2;
			}

			sp34.y += (y - sp34.y) * anim->fracmerge;
		}
	}

	if (anim->unk70 == NULL) {
		rwdata->chrinfo.pos.x = sp34.x;
		rwdata->chrinfo.pos.y = rwdata->chrinfo.ground + sp34.f[1];
		rwdata->chrinfo.pos.z = sp34.z;
	} else {
		sp28 = sp34;

		if (anim->unk70(model, &rwdata->chrinfo.pos, &sp28, &rwdata->chrinfo.ground)) {
			rwdata->chrinfo.pos.x = sp28.x;
			rwdata->chrinfo.pos.y = rwdata->chrinfo.ground + sp28.f[1];
			rwdata->chrinfo.pos.z = sp28.z;

			sp34.x = sp28.x - sp34.x;
			sp34.z = sp28.z - sp34.z;

			rwdata->chrinfo.unk34.x += sp34.x;
			rwdata->chrinfo.unk34.z += sp34.z;

			if (rwdata->chrinfo.unk01) {
				rwdata->chrinfo.unk24.x += sp34.x;
				rwdata->chrinfo.unk24.z += sp34.z;
			}

			if (rwdata->chrinfo.unk02) {
				rwdata->chrinfo.unk4c.x += sp34.x;
				rwdata->chrinfo.unk4c.z += sp34.z;

				rwdata->chrinfo.unk40.x += sp34.x;
				rwdata->chrinfo.unk40.z += sp34.z;
			}
		}
	}
}

void model0001b3bc(struct model *model)
{
	struct modelnode *node = model->filedata->rootnode;

	if (node && (node->type & 0xff) == MODELNODETYPE_CHRINFO) {
		model0001b0e8(model, node);
	}
}

void model0001b400(struct modelrenderdata *arg0, struct model *model, struct modelnode *node)
{
	struct anim *anim = model->anim;
	union modelrodata *rodata = node->rodata;
	union modelrwdata *rwdata = modelGetNodeRwData(model, node);
	f32 scale = model->scale;
	struct coord *sp254 = &rwdata->chrinfo.pos;
	f32 sp250 = rwdata->chrinfo.unk14;
	Mtxf *sp24c;
	u32 stack1;
	Mtxf *mtx = &model->matrices[rodata->chrinfo.mtxindex];
	s32 sp240 = rodata->chrinfo.unk00;
	struct skeleton *skel = model->filedata->skel;
	struct coord sp230;
	struct coord sp224;
	struct coord sp218;
	Mtxf sp1d8;
	Mtxf sp198;
	Mtxf sp158;
	f32 sp154;
	struct coord sp148;
	struct coord sp13c;
	struct coord sp130;
	struct coord sp124;
	struct coord sp118;
	struct coord sp10c;
	f32 spfc[4];
	f32 spec[4];
	f32 spdc[4];
	struct coord spd0;
	struct coord spc4;
	struct coord spb8;
	Mtxf sp78;
	Mtxf sp38;

	if (rodata->chrinfo.mtxindex);

	if (node->parent) {
		sp24c = model0001a5cc(model, node->parent, 0);
	} else {
		sp24c = arg0->unk00;
	}

	anim00024050(sp240, anim->flip, skel, anim->animnum, anim->unk04, &sp230, &sp224, &sp218);

	if (g_Vars.in_cutscene && anim->speed > 0) {
#if VERSION >= VERSION_PAL_BETA
		sp154 = floorf(anim->frac / anim->speed + 0.01f) * anim->speed;
#else
		sp154 = floorf(anim->frac / anim->speed) * anim->speed;
#endif
	} else {
		sp154 = anim->frac;
	}

	if (sp154 != 0.0f) {
		anim00024050(sp240, anim->flip, skel, anim->animnum, anim->unk05, &sp148, &sp13c, &sp130);
		model0001b07c(&sp230, &sp148, sp154);
	}

	if (anim->fracmerge != 0.0f) {
		anim00024050(sp240, anim->flip2, skel, anim->animnum2, anim->unk06, &sp124, &sp118, &sp10c);

		if (anim->frac2 != 0.0f) {
			anim00024050(sp240, anim->flip2, skel, anim->animnum2, anim->unk07, &spd0, &spc4, &spb8);
			model0001b07c(&sp124, &spd0, anim->frac2);
		}

		if ((g_Anims[anim->animnum].flags & ANIMFLAG_02) && (g_Anims[anim->animnum2].flags & ANIMFLAG_02) == 0) {
			mtx4LoadYRotation(rwdata->chrinfo.unk14, &sp78);
			mtx4LoadRotation(&sp124, &sp38);
			mtx00015be0(&sp78, &sp38);
			quaternion0f097044(&sp38, spec);
		} else {
			quaternion0f096ca0(&sp124, spec);
		}

		quaternion0f096ca0(&sp230, spfc);
		quaternion0f0976c0(spfc, spec);
		quaternionSlerp(spfc, spec, anim->fracmerge, spdc);
		quaternionToMtx(spdc, &sp1d8);
	} else {
		mtx4LoadRotation(&sp230, &sp1d8);
	}

	if (g_Anims[anim->animnum].flags & ANIMFLAG_02) {
		mtx4LoadTranslation(sp254, &sp198);
	} else {
		if (rwdata->chrinfo.unk18 != 0.0f) {
			sp250 = model0001afe8(sp250, rwdata->chrinfo.unk1c, rwdata->chrinfo.unk18);
		}

		mtx4LoadYRotationWithTranslation(sp254, sp250, &sp198);
	}

	mtx00015be4(&sp198, &sp1d8, &sp158);

	if (scale != 1.0f) {
		mtx00015f4c(scale, &sp158);
	}

	if (sp24c) {
		mtx00015be4(sp24c, &sp158, mtx);
	} else {
		mtx4Copy(&sp158, mtx);
	}
}

void modelPositionJointUsingVecRot(struct modelrenderdata *renderdata, struct model *model, struct modelnode *node, struct coord *rot, struct coord *pos, bool allowscale, struct coord *arg6)
{
	s32 nodetype = node->type;
	struct modelrodata_position *rodata = &node->rodata->position;
	Mtxf *rendermtx;
	u32 stack;
	Mtxf mtx68;
	s32 mtxindex0 = rodata->mtxindex0;
	s32 mtxindex1 = rodata->mtxindex1;
	s32 mtxindex2 = rodata->mtxindex2;
	Mtxf *matrices = model->matrices;

	if (node->parent != NULL) {
		rendermtx = model0001a5cc(model, node->parent, 0);
	} else {
		rendermtx = renderdata->unk00;
	}

	if (rendermtx != NULL) {
		Mtxf *nodemtx = &matrices[mtxindex0];

		mtx4LoadRotationAndTranslation(pos, rot, &mtx68);

		if (allowscale && model->scale != 1.0f) {
			mtx00015f04(model->scale, &mtx68);
		}

		if (arg6->x != 1.0f) {
			mtx00015df0(arg6->x, &mtx68);
		}

		if (arg6->y != 1.0f) {
			mtx00015e4c(arg6->y, &mtx68);
		}

		if (arg6->z != 1.0f) {
			mtx00015ea8(arg6->z, &mtx68);
		}

		mtx00015be4(rendermtx, &mtx68, nodemtx);

		if (g_ModelJointPositionedFunc != NULL) {
			g_ModelJointPositionedFunc(mtxindex0, nodemtx);
		}
	} else {
		Mtxf *nodemtx = &matrices[mtxindex0];

		mtx4LoadRotationAndTranslation(pos, rot, nodemtx);

		if (allowscale && model->scale != 1.0f) {
			mtx00015f04(model->scale, nodemtx);
		}

		if (arg6->x != 1.0f) {
			mtx00015df0(arg6->x, nodemtx);
		}

		if (arg6->y != 1.0f) {
			mtx00015e4c(arg6->y, nodemtx);
		}

		if (arg6->z != 1.0f) {
			mtx00015ea8(arg6->z, nodemtx);
		}
	}

	if (nodetype & MODELNODETYPE_0100) {
		Mtxf *nodemtx = &matrices[mtxindex1];
		f32 sp3c[4];
		f32 sp2c[4];

		quaternion0f096ca0(rot, sp3c);
		quaternion0f097518(sp3c, 0.5f, sp2c);

		if (rendermtx != NULL) {
			quaternionToTransformMtx(pos, sp2c, &mtx68);
			mtx00015be4(rendermtx, &mtx68, nodemtx);
		} else {
			quaternionToTransformMtx(pos, sp2c, nodemtx);
		}
	}

	if (nodetype & MODELNODETYPE_0200) {
		Mtxf *finalmtx = rendermtx ? &mtx68 : &matrices[mtxindex2];
		f32 roty = rot->y;

		if (roty < M_PI) {
			roty *= 0.5f;
		} else {
			roty = M_BADTAU - (M_BADTAU - roty) * 0.5f;
		}

		mtx4LoadYRotation(roty, finalmtx);

		if (roty >= M_PI) {
			roty = M_BADTAU - roty;
		}

		if (roty < 0.890118f) { // 51 degrees
			roty = func0f096700(roty);
		} else {
			roty = 1.5f;
		}

		mtx00015edc(roty, finalmtx);
		mtx4SetTranslation(pos, finalmtx);

		if (rendermtx != NULL) {
			Mtxf *nodemtx = &matrices[mtxindex2];
			mtx00015be4(rendermtx, finalmtx, nodemtx);
		}
	}
}

void modelPositionJointUsingQuatRot(struct modelrenderdata *renderdata, struct model *model, struct modelnode *node, f32 rot[4], struct coord *pos, struct coord *arg5)
{
	s32 nodetype = node->type;
	struct modelrodata_position *rodata = &node->rodata->position;
	Mtxf *rendermtx;
	u32 stack;
	Mtxf mtx58;
	s32 mtxindex0 = rodata->mtxindex0;
	s32 mtxindex1 = rodata->mtxindex1;
	s32 mtxindex2 = rodata->mtxindex2;
	Mtxf *matrices = model->matrices;

	if (node->parent != NULL) {
		rendermtx = model0001a5cc(model, node->parent, 0);
	} else {
		rendermtx = renderdata->unk00;
	}

	if (rendermtx != NULL) {
		Mtxf *nodemtx = &matrices[mtxindex0];

		quaternionToTransformMtx(pos, rot, &mtx58);

		if (arg5->x != 1.0f) {
			mtx00015df0(arg5->x, &mtx58);
		}

		if (arg5->y != 1.0f) {
			mtx00015e4c(arg5->y, &mtx58);
		}

		if (arg5->z != 1.0f) {
			mtx00015ea8(arg5->z, &mtx58);
		}

		mtx00015be4(rendermtx, &mtx58, nodemtx);

		if (g_ModelJointPositionedFunc != NULL) {
			g_ModelJointPositionedFunc(mtxindex0, nodemtx);
		}
	} else {
		Mtxf *nodemtx = &matrices[mtxindex0];

		quaternionToTransformMtx(pos, rot, nodemtx);

		if (arg5->x != 1.0f) {
			mtx00015df0(arg5->x, nodemtx);
		}

		if (arg5->y != 1.0f) {
			mtx00015e4c(arg5->y, nodemtx);
		}

		if (arg5->z != 1.0f) {
			mtx00015ea8(arg5->z, nodemtx);
		}
	}

	if (nodetype & MODELNODETYPE_0100) {
		Mtxf *nodemtx = &matrices[mtxindex1];
		f32 sp2c[4];

		quaternion0f097518(rot, 0.5f, sp2c);

		if (rendermtx != NULL) {
			quaternionToTransformMtx(pos, sp2c, &mtx58);
			mtx00015be4(rendermtx, &mtx58, nodemtx);
		} else {
			quaternionToTransformMtx(pos, sp2c, nodemtx);
		}
	}

	if (nodetype & MODELNODETYPE_0200) {
		Mtxf *finalmtx = rendermtx ? &mtx58 : &matrices[mtxindex2];
		f32 roty = 2.0f * acosf(rot[0]);

		if (roty < M_PI) {
			roty *= 0.5f;
		} else {
			roty = M_BADTAU - (M_BADTAU - roty) * 0.5f;
		}

		mtx4LoadYRotation(roty, finalmtx);

		if (roty >= M_PI) {
			roty = M_BADTAU - roty;
		}

		if (roty < 0.890118f) { // 51 degrees
			roty = func0f096700(roty);
		} else {
			roty = 1.5f;
		}

		mtx00015edc(roty, finalmtx);
		mtx4SetTranslation(pos, finalmtx);

		if (rendermtx != NULL) {
			Mtxf *nodemtx = &matrices[mtxindex2];
			mtx00015be4(rendermtx, finalmtx, nodemtx);
		}
	}
}

void model0001bfa8(struct modelrenderdata *renderdata, struct model *model, struct modelnode *node)
{
	struct anim *anim;
	struct modelrodata_position *rodata = &node->rodata->position;
	s32 partnum;
	struct skeleton *skel;
	struct coord sp144;
	struct coord sp138;
	struct coord sp12c;
	bool sp128;
	Mtxf spe8;
	Mtxf *mtx;
	f32 spe0;
	struct coord spd4;
	struct coord spc8;
	struct coord spbc;
	struct coord spb0;
	struct coord spa4;
	struct coord sp98;
	f32 sp88[4];
	f32 sp78[4];
	f32 sp68[4];
	struct coord sp5c;
	struct coord sp50;
	struct coord sp44;

	anim = model->anim;

	if (anim != NULL) {
		partnum = rodata->part;
		skel = model->filedata->skel;

		if (anim->animnum != 0) {
			sp128 = (g_Anims[anim->animnum].flags & ANIMFLAG_02) && node == model->filedata->rootnode;

			anim00024050(partnum, anim->flip, skel, anim->animnum, anim->unk04, &sp144, &sp138, &sp12c);

			if (g_Vars.in_cutscene && anim->speed > 0.0f) {
#if VERSION >= VERSION_PAL_BETA
				spe0 = floorf(anim->frac / anim->speed + 0.0099999997764826f) * anim->speed;
#else
				spe0 = floorf(anim->frac / anim->speed) * anim->speed;
#endif
			} else {
				spe0 = anim->frac;
			}

			if (spe0 != 0.0f) {
				anim00024050(partnum, anim->flip, skel, anim->animnum, anim->unk05, &spd4, &spc8, &spbc);
				model0001b07c(&sp144, &spd4, spe0);

#if VERSION >= VERSION_PAL_BETA
				if (sp128 || var8005efd8_2)
#else
				if (sp128)
#endif
				{
					model0001af98(&sp138, &spc8, spe0);
				}
			}
		} else {
			sp138.f[0] = sp138.f[1] = sp138.f[2] = 0.0f;
			sp144.f[0] = sp144.f[1] = sp144.f[2] = 0.0f;
			sp12c.f[0] = sp12c.f[1] = sp12c.f[2] = 1.0f;

			sp128 = false;
		}

		if (anim->fracmerge != 0.0f) {
			anim00024050(partnum, anim->flip2, skel, anim->animnum2, anim->unk06, &spb0, &spa4, &sp98);

			if (anim->frac2 != 0.0f) {
				anim00024050(partnum, anim->flip2, skel, anim->animnum2, anim->unk07, &sp5c, &sp50, &sp44);
				model0001b07c(&spb0, &sp5c, anim->frac2);
			}

			quaternion0f096ca0(&sp144, sp88);
			quaternion0f096ca0(&spb0, sp78);
			quaternion0f0976c0(sp88, sp78);
			quaternionSlerp(sp88, sp78, anim->fracmerge, sp68);

			if (sp138.f[0] != 0.0f || sp138.f[1] != 0.0f || sp138.f[2] != 0.0f) {
				sp138.x *= anim->animscale;
				sp138.y *= anim->animscale;
				sp138.z *= anim->animscale;

				if (node != model->filedata->rootnode) {
					sp138.x += rodata->pos.x;
					sp138.y += rodata->pos.y;
					sp138.z += rodata->pos.z;
				}

				modelPositionJointUsingQuatRot(renderdata, model, node, sp68, &sp138, &sp12c);
			} else if (node != model->filedata->rootnode) {
				modelPositionJointUsingQuatRot(renderdata, model, node, sp68, &rodata->pos, &sp12c);
			} else {
				modelPositionJointUsingQuatRot(renderdata, model, node, sp68, &sp138, &sp12c);
			}
		} else if (sp128) {
			f32 mult = func0f15c888();

			sp138.x *= mult;
			sp138.y *= mult;
			sp138.z *= mult;

			modelPositionJointUsingVecRot(renderdata, model, node, &sp144, &sp138, true, &sp12c);
		} else if (sp138.f[0] != 0.0f || sp138.f[1] != 0.0f || sp138.f[2] != 0.0f) {
			sp138.x *= anim->animscale;
			sp138.y *= anim->animscale;
			sp138.z *= anim->animscale;

			if (node != model->filedata->rootnode) {
				sp138.x += rodata->pos.x;
				sp138.y += rodata->pos.y;
				sp138.z += rodata->pos.z;
			}

			modelPositionJointUsingVecRot(renderdata, model, node, &sp144, &sp138, false, &sp12c);
		} else if (node != model->filedata->rootnode) {
			modelPositionJointUsingVecRot(renderdata, model, node, &sp144, &rodata->pos, false, &sp12c);
		} else {
			modelPositionJointUsingVecRot(renderdata, model, node, &sp144, &sp138, false, &sp12c);
		}
	} else {
		if (node->parent) {
			mtx = model0001a5cc(model, node->parent, 0);
		} else {
			mtx = renderdata->unk00;
		}

		if (mtx) {
			mtx4LoadTranslation(&rodata->pos, &spe8);
			mtx00015be4(mtx, &spe8, &model->matrices[rodata->mtxindex0]);
		} else {
			mtx4LoadTranslation(&rodata->pos, &model->matrices[rodata->mtxindex0]);
		}
	}
}

void model0001c5b4(struct modelrenderdata *arg0, struct model *model, struct modelnode *node)
{
	union modelrodata *rodata = node->rodata;
	Mtxf *sp68;
	Mtxf sp28;
	s32 mtxindex = rodata->positionheld.mtxindex;
	Mtxf *matrices = model->matrices;

	if (node->parent) {
		sp68 = model0001a5cc(model, node->parent, 0);
	} else {
		sp68 = arg0->unk00;
	}

	if (sp68) {
		mtx4LoadTranslation(&rodata->positionheld.pos, &sp28);
		mtx00015be4(sp68, &sp28, &matrices[mtxindex]);
	} else {
		mtx4LoadTranslation(&rodata->positionheld.pos, &matrices[mtxindex]);
	}
}

/**
 * For a distance node, set its target to visible based on distance.
 */
void model0001c664(struct model *model, struct modelnode *node)
{
	union modelrodata *rodata = node->rodata;
	union modelrwdata *rwdata = modelGetNodeRwData(model, node);
	Mtxf *mtx = model0001a5cc(model, node, 0);
	f32 distance;

	if (g_ModelDistanceDisabled || !mtx) {
		distance = 0;
	} else {
		distance = -mtx->m[3][2] * camGetLodScaleZ();

		if (g_ModelDistanceScale != 1) {
			distance *= g_ModelDistanceScale;
		}
	}

	if (distance > rodata->distance.near * model->scale || rodata->distance.near == 0) {
		if (distance <= rodata->distance.far * model->scale) {
			rwdata->distance.visible = true;
			node->child = rodata->distance.target;
			return;
		}
	}

	rwdata->distance.visible = false;
	node->child = NULL;
}

void model0001c784(struct model *model, struct modelnode *node)
{
	struct modelrodata_distance *rodata = &node->rodata->distance;
	struct modelrwdata_distance *rwdata = modelGetNodeRwData(model, node);

	if (rwdata->visible) {
		node->child = rodata->target;
	} else {
		node->child = NULL;
	}
}

void model0001c7d0(struct model *model, struct modelnode *node)
{
	struct modelrodata_toggle *rodata = &node->rodata->toggle;
	struct modelrwdata_toggle *rwdata = modelGetNodeRwData(model, node);

	if (rwdata->visible) {
		node->child = rodata->target;
	} else {
		node->child = NULL;
	}
}

/**
 * Attach a head model to its placeholder on the body model.
 *
 * The given modelnode is assumed to be of type MODELNODETYPE_HEADSPOT.
 */
void modelAttachHead(struct model *model, struct modelnode *bodynode)
{
	struct modelrwdata_headspot *rwdata = modelGetNodeRwData(model, bodynode);

	if (rwdata->modelfiledata) {
		struct modelnode *headnode = rwdata->modelfiledata->rootnode;

		bodynode->child = headnode;

		while (headnode) {
			headnode->parent = bodynode;
			headnode = headnode->next;
		}
	}
}

void model0001c868(struct modelnode *basenode, bool visible)
{
	union modelrodata *rodata = basenode->rodata;
	struct modelnode *node1;
	struct modelnode *node2;
	struct modelnode *loopnode;

	if (visible) {
		node1 = rodata->reorder.unk18;
		node2 = rodata->reorder.unk1c;
	} else {
		node1 = rodata->reorder.unk1c;
		node2 = rodata->reorder.unk18;
	}

	if (node1) {
		// I think what's happening here is there's two groups of siblings,
		// where node1 and node2 are the head nodes. Either group can be first,
		// and this is ensuring the node1 group is first.
		// Note that node2 might be NULL.

		basenode->child = node1;
		node1->prev = NULL;

		// Skip through node1's siblings until node2 is found or the end is
		// reached
		loopnode = node1;

		while (loopnode->next && loopnode->next != node2) {
			loopnode = loopnode->next;
		}

		loopnode->next = node2;

		if (node2) {
			// Append node2 and its siblings to node1's siblings
			node2->prev = loopnode;
			loopnode = node2;

			while (loopnode->next && loopnode->next != node1) {
				loopnode = loopnode->next;
			}

			loopnode->next = NULL;
		}
	} else {
		basenode->child = node2;

		if (node2) {
			node2->prev = NULL;
		}
	}
}

void modelRenderNodeReorder(struct model *model, struct modelnode *node)
{
	union modelrwdata *rwdata = modelGetNodeRwData(model, node);

	model0001c868(node, rwdata->reorder.visible);
}

void model0001c950(struct model *model, struct modelnode *node)
{
	union modelrodata *rodata = node->rodata;
	union modelrwdata *rwdata = modelGetNodeRwData(model, node);
	Mtxf *mtx = model0001a5cc(model, node, 0);
	struct coord sp38;
	struct coord sp2c;
	f32 tmp;

	if (rodata->reorder.unk20 == 0) {
		sp38.x = rodata->reorder.unk0c[0];
		sp38.y = rodata->reorder.unk0c[1];
		sp38.z = rodata->reorder.unk0c[2];
		mtx4RotateVecInPlace(mtx, &sp38);
	} else if (rodata->reorder.unk20 == 2) {
		sp38.x = mtx->m[1][0] * rodata->reorder.unk0c[1];
		sp38.y = mtx->m[1][1] * rodata->reorder.unk0c[1];
		sp38.z = mtx->m[1][2] * rodata->reorder.unk0c[1];
	} else if (rodata->reorder.unk20 == 3) {
		sp38.x = mtx->m[2][0] * rodata->reorder.unk0c[2];
		sp38.y = mtx->m[2][1] * rodata->reorder.unk0c[2];
		sp38.z = mtx->m[2][2] * rodata->reorder.unk0c[2];
	} else if (rodata->reorder.unk20 == 1) {
		sp38.x = mtx->m[0][0] * rodata->reorder.unk0c[0];
		sp38.y = mtx->m[0][1] * rodata->reorder.unk0c[0];
		sp38.z = mtx->m[0][2] * rodata->reorder.unk0c[0];
	}

	sp2c.x = rodata->reorder.unk00;
	sp2c.y = rodata->reorder.unk04;
	sp2c.z = rodata->reorder.unk08;

	mtx4TransformVecInPlace(mtx, &sp2c);

	tmp = sp38.f[0] * sp2c.f[0] + sp38.f[1] * sp2c.f[1] + sp38.f[2] * sp2c.f[2];

	if (tmp < 0) {
		rwdata->reorder.visible = true;
	} else {
		rwdata->reorder.visible = false;
	}

	modelRenderNodeReorder(model, node);
}

void model0001cb0c(struct model *model, struct modelnode *parent)
{
	struct modelnode *node = parent->child;

	if (parent);

	while (node) {
		s32 type = node->type & 0xff;
		bool dochildren = true;

		switch (type) {
		case MODELNODETYPE_CHRINFO:
		case MODELNODETYPE_POSITION:
		case MODELNODETYPE_0B:
		case MODELNODETYPE_CHRGUNFIRE:
		case MODELNODETYPE_0D:
		case MODELNODETYPE_0E:
		case MODELNODETYPE_0F:
		case MODELNODETYPE_POSITIONHELD:
			dochildren = false;
			break;
		case MODELNODETYPE_DISTANCE:
			model0001c664(model, node);
			break;
		case MODELNODETYPE_REORDER:
			model0001c950(model, node);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, node);
			break;
		case MODELNODETYPE_DL:
			break;
		}

		if (dochildren && node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node == parent->parent) {
					node = NULL;
					break;
				}

				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}
}

void model0001cc20(struct model *model)
{
	struct modelnode *node = model->filedata->rootnode;

	while (node) {
		u32 type = node->type & 0xff;

		switch (type) {
		case MODELNODETYPE_DISTANCE:
			model0001c664(model, node);
			break;
		case MODELNODETYPE_REORDER:
			model0001c950(model, node);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(model, node);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, node);
			break;
		case MODELNODETYPE_CHRINFO:
		case MODELNODETYPE_DL:
		default:
			break;
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
}

void model0001cd18(struct modelrenderdata *arg0, struct model *model)
{
	struct modelnode *node = model->filedata->rootnode;

	while (node) {
		u32 type = node->type & 0xff;

		switch (type) {
		case MODELNODETYPE_CHRINFO:
			model0001b400(arg0, model, node);
			break;
		case MODELNODETYPE_POSITION:
			model0001bfa8(arg0, model, node);
			break;
		case MODELNODETYPE_POSITIONHELD:
			model0001c5b4(arg0, model, node);
			break;
		case MODELNODETYPE_DISTANCE:
			model0001c664(model, node);
			break;
		case MODELNODETYPE_REORDER:
			model0001c950(model, node);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(model, node);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, node);
			break;
		case MODELNODETYPE_DL:
		default:
			break;
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
}

void model0001ce64(struct modelrenderdata *arg0, struct model *model)
{
	model->matrices = arg0->unk10;

	arg0->unk10 += model->filedata->nummatrices;

#if VERSION >= VERSION_PAL_BETA
	if (var8005efb0_2 || !model00018680()) {
		model0001cd18(arg0, model);
	}
#else
	if (!model00018680()) {
		model0001cd18(arg0, model);
	}
#endif
}

void model0001cebc(struct modelrenderdata *arg0, struct model *model)
{
	struct anim *anim = model->anim;
	f32 speed;
	f32 frac;
	f32 frac2;

	if (anim && anim->animnum) {
		if (PLAYERCOUNT() >= 2) {
			frac = anim->frac;
			frac2 = anim->frac2;
			speed = anim->speed;

			if (speed < 0) {
				speed = -speed;
			}

			if (speed > 0.5f) {
				anim->frac = 0;
				anim->frac2 = 0;
			}
		}

		anim00023d38(anim->animnum);
		anim->unk04 = anim00023ab0(anim->animnum, anim->framea);

		if (anim->frac != 0) {
			anim->unk05 = anim00023ab0(anim->animnum, anim->frameb);
		}

		if (anim->animnum2) {
			anim00023d38(anim->animnum2);
			anim->unk06 = anim00023ab0(anim->animnum2, anim->frame2a);

			if (anim->frac2 != 0) {
				anim->unk07 = anim00023ab0(anim->animnum2, anim->frame2b);
			}
		}

		anim00023d0c();
	}

	model0001ce64(arg0, model);

	if (PLAYERCOUNT() >= 2 && anim && anim->animnum) {
		anim->frac = frac;
		anim->frac2 = frac2;
	}
}

s16 modelGetAnimNum(struct model *model)
{
	if (model->anim) {
		return model->anim->animnum;
	}

	return 0;
}

bool modelIsFlipped(struct model *model)
{
	if (model->anim) {
		return model->anim->flip;
	}

	return false;
}

f32 modelGetCurAnimFrame(struct model *model)
{
	if (model->anim) {
		return model->anim->frame;
	}

	return 0;
}

f32 modelGetAnimEndFrame(struct model *model)
{
	struct anim *anim = model->anim;

	if (anim) {
		if (anim->endframe >= 0) {
			return anim->endframe;
		}

		if (anim->animnum) {
			return animGetNumFrames(anim->animnum) - 1;
		} else {
			return 0;
		}
	}

	return 0;
}

s32 modelGetNumAnimFrames(struct model *model)
{
	if (model->anim) {
		return animGetNumFrames(modelGetAnimNum(model));
	}

	return 0;
}

f32 modelGetAnimSpeed(struct model *model)
{
	if (model->anim) {
		return model->anim->speed;
	}

	return 1;
}

f32 modelGetAbsAnimSpeed(struct model *model)
{
	f32 speed;

	if (model->anim) {
		speed = model->anim->speed;

		if (speed < 0) {
			speed = -speed;
		}

		return speed;
	}

	return 1;
}

f32 modelGetEffectiveAnimSpeed(struct model *model)
{
	if (model->anim) {
		return modelGetAnimSpeed(model) * model->anim->playspeed;
	}

	return 1;
}

/**
 * Constrain the given frame number to the bounds of the animation, unless the
 * animation is looping in which case wrap it to the other side.
 */
s32 modelConstrainOrWrapAnimFrame(s32 frame, s16 animnum, f32 endframe)
{
	if (frame < 0) {
		if (var8005efbc || (g_Anims[animnum].flags & ANIMFLAG_LOOP)) {
			frame = animGetNumFrames(animnum) - (-frame % animGetNumFrames(animnum));
		} else {
			frame = 0;
		}
	} else if (endframe >= 0 && frame > (s32)endframe) {
		frame = ceil(endframe);
	} else if (frame >= animGetNumFrames(animnum)) {
		if (var8005efbc || (g_Anims[animnum].flags & ANIMFLAG_LOOP)) {
			frame = frame % animGetNumFrames(animnum);
		} else {
			frame = animGetNumFrames(animnum) - 1;
		}
	}

	return frame;
}

void modelCopyAnimForMerge(struct model *model, f32 merge)
{
	struct anim *anim = model->anim;
	struct modelnode *node;
	u32 nodetype;

	if (anim) {
		if (merge > 0 && anim->animnum) {
			if (anim->animnum2 && anim->fracmerge == 1) {
				return;
			}

			node = model->filedata->rootnode;
			nodetype = node->type & 0xff;

			anim->frame2 = anim->frame;
			anim->frac2 = anim->frac;
			anim->animnum2 = anim->animnum;
			anim->flip2 = anim->flip;
			anim->frame2a = anim->framea;
			anim->frame2b = anim->frameb;
			anim->speed2 = anim->speed;
			anim->newspeed2 = anim->newspeed;
			anim->oldspeed2 = anim->oldspeed;
			anim->timespeed2 = anim->timespeed;
			anim->elapsespeed2 = anim->elapsespeed;
			anim->endframe2 = anim->endframe;

			if (nodetype == MODELNODETYPE_CHRINFO) {
				struct modelrwdata_chrinfo *rwdata = modelGetNodeRwData(model, node);
				rwdata->unk02 = 1;
				rwdata->unk4c = rwdata->unk34;
				rwdata->unk40 = rwdata->unk24;
			}
		} else {
			anim->animnum2 = 0;
		}
	}
}

void model0001d62c(struct model *model, s16 animnum, s32 flip, f32 fstartframe, f32 speed, f32 merge)
{
	struct anim *anim = model->anim;

	if (anim) {
		s32 isfirstanim = !anim->animnum;
		s32 type;

		if (anim->animnum2) {
			anim->timemerge = merge;
			anim->elapsemerge = 0;
			anim->fracmerge = 1;
		} else {
			anim->timemerge = 0;
			anim->fracmerge = 0;
		}

		anim->animnum = animnum;
		anim->flip = flip;
		anim->endframe = -1;
		anim->speed = speed;
		anim->timespeed = 0;

		model0001e018(model, fstartframe);

		anim->looping = false;

		type = model->filedata->rootnode->type & 0xff;

		if (type == MODELNODETYPE_CHRINFO) {
			u32 stack;
			struct modelrodata_chrinfo *rodata = &model->filedata->rootnode->rodata->chrinfo;
			struct modelrwdata_chrinfo *rwdata = (struct modelrwdata_chrinfo *) modelGetNodeRwData(model, model->filedata->rootnode);
			s32 spa4 = rodata->unk00;
			struct skeleton *skel = model->filedata->skel;
			f32 scale;
			f32 sp98;
			f32 sp94;
			struct coord sp88 = {0, 0, 0};
			f32 sp84;
			u8 sp83;
			struct coord sp74;
			struct coord sp68;
			f32 sp64;
			struct coord sp58;
			struct coord sp4c;
			f32 angle;
			f32 y;
			f32 x;
			f32 z;

			if (g_Anims[anim->animnum].flags & ANIMFLAG_02) {
				sp64 = func0f15c888();
				anim00023d38(anim->animnum);
				sp83 = anim00023ab0(anim->animnum, anim->framea);
				anim00023d0c();
				anim00024050(spa4, anim->flip, skel, anim->animnum, sp83, &sp74, &sp88, &sp68);

				rwdata->unk34.x = sp88.x * sp64;
				rwdata->unk34.y = sp88.y * sp64;
				rwdata->unk34.z = sp88.z * sp64;
				rwdata->unk30 = rwdata->unk14;

				if (anim->frac == 0) {
					rwdata->unk01 = 0;
				} else {
					anim00023d38(anim->animnum);
					sp83 = anim00023ab0(anim->animnum, anim->frameb);
					anim00023d0c();
					anim00024050(spa4, anim->flip, skel, anim->animnum, sp83, &sp74, &sp88, &sp68);

					rwdata->unk24.x = sp88.x * sp64;
					rwdata->unk24.y = sp88.y * sp64;
					rwdata->unk24.z = sp88.z * sp64;
					rwdata->unk20 = rwdata->unk14;

					rwdata->unk01 = 1;
				}
			} else {
				sp84 = anim00024b64(spa4, anim->flip, skel, anim->animnum, anim->frameb, &sp88, anim->average);
				scale = model->scale * anim->animscale;

				if (scale != 1) {
					sp88.x *= scale;
					sp88.y *= scale;
					sp88.z *= scale;
				}

				if (anim->average) {
					sp88.y = rwdata->pos.y - rwdata->ground;
				}

				sp98 = cosf(rwdata->unk14);
				sp94 = sinf(rwdata->unk14);

				if (anim->frac == 0) {
					rwdata->unk34.x = rwdata->pos.f[0];
					rwdata->unk34.y = rwdata->pos.f[1] - rwdata->ground;
					rwdata->unk34.z = rwdata->pos.f[2];

					rwdata->unk30 = rwdata->unk14;

					sp58.x = rwdata->unk34.f[0] + sp88.f[0] * sp98 + sp88.f[2] * sp94;
					sp58.y = sp88.f[1];
					sp58.z = rwdata->unk34.f[2] - sp88.f[0] * sp94 + sp88.f[2] * sp98;

					rwdata->unk24.x = sp58.f[0];
					rwdata->unk24.y = sp58.f[1];
					rwdata->unk24.z = sp58.f[2];

					if (rwdata->unk18 == 0) {
						rwdata->unk20 = rwdata->unk30 + sp84;

						if (rwdata->unk20 >= M_BADTAU) {
							rwdata->unk20 -= M_BADTAU;
						}
					}

					rwdata->unk01 = 1;
				} else {
					x = sp88.f[0] * sp98 + sp88.f[2] * sp94;
					y = sp88.f[1];
					z = -sp88.f[0] * sp94 + sp88.f[2] * sp98;

					sp4c.f[0] = rwdata->pos.f[0] + x * (1 - anim->frac);
					sp4c.f[1] = y;
					sp4c.f[2] = rwdata->pos.f[2] + z * (1 - anim->frac);

					rwdata->unk24.f[0] = sp4c.f[0];
					rwdata->unk24.f[1] = sp4c.f[1];
					rwdata->unk24.f[2] = sp4c.f[2];

					rwdata->unk34.f[0] = rwdata->unk24.f[0] - x;
					rwdata->unk34.f[1] = (rwdata->pos.f[1] - rwdata->ground) - (y - (rwdata->pos.f[1] - rwdata->ground)) * anim->frac / (1 - anim->frac);
					rwdata->unk34.f[2] = rwdata->unk24.f[2] - z;

					angle = rwdata->unk14 - sp84;

					if (angle < 0) {
						angle += M_BADTAU;
					}

					rwdata->unk30 = model0001afe8(rwdata->unk14, angle, anim->frac);

					if (rwdata->unk18 == 0) {
						rwdata->unk20 = rwdata->unk30 + sp84;

						if (rwdata->unk20 >= M_BADTAU) {
							rwdata->unk20 -= M_BADTAU;
						}
					}

					rwdata->unk01 = 1;
				}

				if (isfirstanim) {
					rwdata->unk34.f[1] = rwdata->unk24.f[1];
				}
			}
		}
	}
}

bool modelIsAnimMerging(struct model *model)
{
	if (model && model->anim && model->anim->animnum2
			&& model->anim->fracmerge != 0 && model->anim->fracmerge != 1) {
		return true;
	}

	return false;
}

void modelSetAnimationWithMerge(struct model *model, s16 animnum, u32 flip, f32 startframe, f32 speed, f32 timemerge, bool domerge)
{
	if (model) {
		if (model->anim && model->anim->animnum
				&& (g_Anims[model->anim->animnum].flags & ANIMFLAG_02)
				&& (g_Anims[animnum].flags & ANIMFLAG_02) == 0) {
			timemerge = 0;
		}

		if (domerge) {
			modelCopyAnimForMerge(model, timemerge);
		}

		model0001d62c(model, animnum, flip, startframe, speed, timemerge);
	}
}

void modelSetAnimation(struct model *model, s16 animnum, s32 flip, f32 startframe, f32 speed, f32 merge)
{
	if (model) {
		if (model->anim && model->anim->animnum
				&& (g_Anims[model->anim->animnum].flags & ANIMFLAG_02)
				&& (g_Anims[animnum].flags & ANIMFLAG_02) == 0) {
			merge = 0;
		}

		modelCopyAnimForMerge(model, merge);
		model0001d62c(model, animnum, flip, startframe, speed, merge);
	}
}

void modelCopyAnimData(struct model *src, struct model *dst)
{
	if (src->anim && dst->anim) {
		*dst->anim = *src->anim;
	}
}

void modelSetAnimLooping(struct model *model, f32 loopframe, f32 loopmerge)
{
	if (model->anim) {
		model->anim->looping = true;
		model->anim->loopframe = loopframe;
		model->anim->loopmerge = loopmerge;
	}
}

void modelSetAnimEndFrame(struct model *model, f32 endframe)
{
	struct anim *anim = model->anim;

	if (anim) {
		if (anim->animnum && endframe < animGetNumFrames(anim->animnum) - 1) {
			anim->endframe = endframe;
		} else {
			anim->endframe = -1;
		}
	}
}

void modelSetAnimFlipFunction(struct model *model, void *callback)
{
	if (model->anim) {
		model->anim->flipfunc = callback;
	}
}

#if VERSION < VERSION_NTSC_1_0
void modelSetAnimUnk6c(struct model *model, s32 value)
{
	if (model->anim) {
		model->anim->unk6c = value;
	}
}
#endif

void modelSetAnimSpeed(struct model *model, f32 speed, f32 startframe)
{
	struct anim *anim = model->anim;

	if (anim) {
		if (startframe > 0) {
			anim->timespeed = startframe;
			anim->newspeed = speed;
			anim->elapsespeed = 0;
			anim->oldspeed = anim->speed;
		} else {
			anim->speed = speed;
			anim->timespeed = 0;
		}
	}
}

void modelSetAnimSpeedAuto(struct model *model, f32 arg1, f32 startframe)
{
	struct anim *anim = model->anim;
	f32 tmp;
	f32 speed;

	if (anim) {
		if (anim->frame <= arg1) {
			tmp = arg1 - anim->frame;
		} else {
			tmp = animGetNumFrames(anim->animnum) - anim->frame + arg1;
		}

		speed = anim->speed + (tmp + tmp) / startframe;

		modelSetAnimSpeed(model, speed, startframe);
	}
}

void modelSetAnimPlaySpeed(struct model *model, f32 speed, f32 startframe)
{
	struct anim *anim = model->anim;

	if (anim) {
		if (startframe > 0) {
			anim->timeplay = startframe;
			anim->newplay = speed;
			anim->elapseplay = 0;
			anim->oldplay = anim->playspeed;
		} else {
			anim->playspeed = speed;
			anim->timeplay = 0;
		}
	}
}

void modelSetAnim70(struct model *model, void *callback)
{
	if (model->anim) {
		model->anim->unk70 = callback;
	}
}

void model0001e018(struct model *model, f32 arg1)
{
	s32 sp28;
	s32 sp24;
	bool sp20;
	struct anim *anim = model->anim;

	if (anim) {
		sp28 = floor(arg1);
		sp20 = anim->speed >= 0;

		sp24 = (sp20 ? sp28 + 1 : sp28 - 1);

		anim->framea = modelConstrainOrWrapAnimFrame(sp28, anim->animnum, anim->endframe);
		anim->frameb = modelConstrainOrWrapAnimFrame(sp24, anim->animnum, anim->endframe);

		if (anim->framea == anim->frameb) {
			anim->frac = 0;
			anim->frame = anim->framea;
		} else if (sp20) {
			anim->frac = arg1 - sp28;
			anim->frame = anim->framea + anim->frac;
		} else {
			anim->frac = 1 - (arg1 - sp24);
			anim->frame = anim->frameb + (1 - anim->frac);
		}
	}
}

void model0001e14c(struct model *model, f32 arg1, f32 arg2)
{
	struct anim *anim = model->anim;

	if (anim) {
		model0001e018(model, arg1);

		if (anim->animnum2) {
			s32 sp28 = floor(arg2);
			s32 sp24;
			bool sp20 = anim->speed2 >= 0;

			sp24 = (sp20 ? sp28 + 1 : sp28 - 1);

			anim->frame2a = modelConstrainOrWrapAnimFrame(sp28, anim->animnum2, anim->endframe2);
			anim->frame2b = modelConstrainOrWrapAnimFrame(sp24, anim->animnum2, anim->endframe2);

			if (anim->frame2a == anim->frame2b) {
				anim->frac2 = 0;
				anim->frame2 = anim->frame2a;
			} else if (sp20) {
				anim->frac2 = arg2 - sp28;
				anim->frame2 = anim->frame2a + anim->frac2;
			} else {
				anim->frac2 = 1 - (arg2 - sp24);
				anim->frame2 = anim->frame2b + (1 - anim->frac2);
			}
		}
	}
}

bool var8005efdc = true;

void model0001e29c(bool value)
{
	var8005efdc = value;
}

bool model0001e2a8(void)
{
	return var8005efdc;
}

void model0001e2b4(struct model *model, f32 curframe, f32 endframe, f32 curframe2, f32 endframe2)
{
	struct anim *anim = model->anim;

	if (anim != NULL) {
		struct modelnode *rootnode = model->filedata->rootnode;
		u16 nodetype = rootnode->type;

		if ((nodetype & 0xff) == MODELNODETYPE_CHRINFO) {
			struct modelrodata_chrinfo *rodata = &rootnode->rodata->chrinfo;
			struct modelrwdata_chrinfo *rwdata = modelGetNodeRwData(model, rootnode);

			if (rwdata->unk00 == 0) {
				s32 sp118 = rodata->unk00;
				struct skeleton *skel = model->filedata->skel;
				f32 scale = model->scale * anim->animscale;
				f32 sine;
				f32 cosine;
				struct coord spfc = {0, 0, 0};
				u8 s0;
				f32 f20;
				s32 floorcur;
				s32 floorend;
				struct coord spe0;
				f32 f30;
				struct coord spd0;
				f32 spcc;
				s32 spc8;
				bool forwards;
				f32 absspeed;
				f32 absspeed2;
				f32 f22;
				s32 s0frame;
				struct coord spa8;
				struct coord sp9c;
				struct coord sp90;
				u32 stack;

				spe0 = rwdata->unk34;

				f30 = rwdata->unk30;

				spd0 = rwdata->unk24;

				spcc = rwdata->unk20;
				spc8 = rwdata->unk01;

				absspeed = anim->speed;

				if (absspeed < 0.0f) {
					absspeed = -absspeed;
				}

				absspeed2 = anim->speed2;

				if (absspeed2 < 0.0f) {
					absspeed2 = -absspeed2;
				}

				forwards = false;

				if (curframe <= endframe) {
					forwards = true;
				}

				if (forwards) {
					floorcur = floor(curframe) + 1;
					floorend = floor(endframe);
				} else {
					floorcur = ceil(curframe) - 1;
					floorend = ceil(endframe);
				}

				if (g_Anims[anim->animnum].flags & ANIMFLAG_02) {
					f20 = func0f15c888();

					if (floorend != anim->framea) {
						s0frame = modelConstrainOrWrapAnimFrame(floorend, anim->animnum, anim->endframe);

						anim->framea = s0frame;

						if (spc8 && floorend == anim->frameb) {
							spe0 = spd0;
						} else {
							anim00023d38(anim->animnum);
							s0 = anim00023ab0(anim->animnum, s0frame);
							anim00023d0c();
							anim00024050(sp118, anim->flip, skel, anim->animnum, s0, &spa8, &spfc, &sp9c);

							spe0.x = spfc.x * f20;
							spe0.y = spfc.y * f20;
							spe0.z = spfc.z * f20;
						}

						floorcur = floorend;

						if (forwards) {
							floorcur++;
						} else {
							floorcur--;
						}

						s0frame = modelConstrainOrWrapAnimFrame(floorcur, anim->animnum, anim->endframe);
						anim->frameb = s0frame;

						anim00023d38(anim->animnum);
						s0 = anim00023ab0(anim->animnum, s0frame);

						anim00023d0c();
						anim00024050(sp118, anim->flip, skel, anim->animnum, s0, &spa8, &spfc, &sp9c);

						spc8 = true;

						spd0.x = spfc.x * f20;
						spd0.y = spfc.y * f20;
						spd0.z = spfc.z * f20;
					}
				} else {
					while (true) {
						if (forwards) {
							if (floorend < floorcur) {
								break;
							}
						} else {
							if (floorend > floorcur) {
								break;
							}
						}

						s0frame = modelConstrainOrWrapAnimFrame(floorcur, anim->animnum, anim->endframe);

						anim->framea = s0frame;

						if (spc8) {
							spe0 = spd0;

							if (rwdata->unk18 == 0.0f) {
								f30 = spcc;
							}
						} else {
							f22 = anim00024b64(sp118, anim->flip, skel, anim->animnum, s0frame, &spfc, anim->average);

							if (scale != 1.0f) {
								spfc.x *= scale;
								spfc.y *= scale;
								spfc.z *= scale;
							}

							if (!forwards) {
								spfc.x = -spfc.x;
								spfc.z = -spfc.z;

								if (f22 > 0.0f) {
									f22 = M_BADTAU - f22;
								}
							}

							if (anim->average) {
								spfc.y = rwdata->pos.y - rwdata->ground;
							}

							cosine = cosf(rwdata->unk14);
							sine = sinf(rwdata->unk14);

							spe0.x += spfc.x * cosine + spfc.z * sine;
							spe0.y = spfc.y;
							spe0.z += (-spfc.x * sine) + (spfc.z * cosine);

							if (rwdata->unk18 == 0.0f) {
								f30 += f22;

								if (f30 >= M_BADTAU) {
									f30 -= M_BADTAU;
								}
							}
						}

						if (forwards) {
							floorcur++;
						} else {
							floorcur--;
						}

						s0frame = modelConstrainOrWrapAnimFrame(floorcur, anim->animnum, anim->endframe);
						anim->frameb = s0frame;

						if (anim->frameb != anim->framea) {
							f22 = anim00024b64(sp118, anim->flip, skel, anim->animnum, s0frame, &spfc, anim->average);

							spc8 = true;

							if (scale != 1.0f) {
								spfc.x *= scale;
								spfc.y *= scale;
								spfc.z *= scale;
							}

							if (!forwards) {
								spfc.x = -spfc.x;
								spfc.z = -spfc.z;

								if (f22 > 0.0f) {
									f22 = M_BADTAU - f22;
								}
							}

							if (anim->average) {
								spfc.y = rwdata->unk34.y;
							}

							cosine = cosf(rwdata->unk30);
							sine = sinf(rwdata->unk30);

							if (var8005efdc && anim->animnum2) {
								spd0.x = spfc.x * cosine + spfc.f[2] * sine;
								spd0.z = -spfc.x * sine + spfc.f[2] * cosine;

								if (absspeed > 0.0f) {
									f32 f0 = anim->fracmerge - anim->playspeed / (absspeed * anim->timemerge);

									if (f0 < 0.0f) {
										f0 = 0.0f;
									}

									f0 = (f0 + anim->fracmerge) / 2.0f;

									if (1);

									sp90.f[0] = (rwdata->unk40.x - rwdata->unk4c.x) * absspeed2 / absspeed;
									sp90.f[2] = (rwdata->unk40.z - rwdata->unk4c.z) * absspeed2 / absspeed;
									spd0.x += (sp90.x - spd0.x) * f0;
									spd0.z += (sp90.z - spd0.z) * f0;
								} else {
									spd0.x += (rwdata->unk40.x - rwdata->unk4c.x) * anim->fracmerge;
									spd0.z += (rwdata->unk40.z - rwdata->unk4c.z) * anim->fracmerge;
								}

								spd0.x += spe0.x;
								spd0.z += spe0.z;
								spd0.y = spfc.y;
							} else {
								spd0.x = spe0.x + spfc.x * cosine + spfc.f[2] * sine;
								spd0.y = spfc.y;
								spd0.z = spe0.z - spfc.x * sine + spfc.f[2] * cosine;
							}

							if (rwdata->unk5c > 0.0f && absspeed > 0.0f) {
								f32 increment = 1.0f / absspeed;

								if (increment > rwdata->unk5c) {
									increment = rwdata->unk5c;
									rwdata->unk5c = 0.0f;
								} else {
									rwdata->unk5c -= increment;
								}

								f22 += rwdata->unk58 * increment;

								if (f22 < 0.0f) {
									f22 += M_BADTAU;
								} else if (f22 >= M_BADTAU) {
									f22 -= M_BADTAU;
								}
							}

							if (rwdata->unk18 == 0.0f) {
								spcc = f30 + f22;

								if (spcc >= M_BADTAU) {
									spcc -= M_BADTAU;
								}
							}
						}
					}
				}

				rwdata->unk34 = spe0;

				rwdata->unk30 = f30;

				rwdata->unk24.x = spd0.f[0];
				rwdata->unk24.y = spd0.f[1];
				rwdata->unk24.z = spd0.f[2];

				rwdata->unk20 = spcc;
				rwdata->unk01 = spc8;

				if (anim->framea == anim->frameb) {
					anim->frac = 0.0f;
					anim->frame = anim->framea;
				} else if (forwards) {
					anim->frac = endframe - floorend;
					anim->frame = anim->framea + anim->frac;
				} else {
					anim->frac = floorend - endframe;
					anim->frame = anim->frameb + (1.0f - anim->frac);
				}

				if (anim->animnum2 && (g_Anims[anim->animnum].flags & ANIMFLAG_02) == 0) {
					s32 floorcur2 = floor(curframe2);
					s32 floorend2 = floor(endframe2);

					if ((forwards && floorcur2 < floorend2) || (!forwards && floorend2 < floorcur2)) {
						if (rwdata->unk02 != 0) {
							rwdata->unk4c.f[1] = rwdata->unk40.f[1];
						} else {
							rwdata->unk4c.f[1] = rwdata->unk34.f[1];
						}

						anim->frame2a = modelConstrainOrWrapAnimFrame(floorend2, anim->animnum2, anim->endframe2);

						s0frame = modelConstrainOrWrapAnimFrame(floorend2 + 1, anim->animnum2, anim->endframe2);
						anim->frame2b = s0frame;

						anim00024b64(sp118, anim->flip2, skel, anim->animnum2, s0frame, &spfc, anim->average);

						if (scale != 1.0f) {
							spfc.y *= scale;
						}

						if (anim->average) {
							spfc.y = rwdata->unk4c.y;
						}

						rwdata->unk40.y = spfc.y;
						rwdata->unk02 = 1;
					}

					if (forwards) {
						anim->frac2 = endframe2 - floorend2;
						anim->frame2 = anim->frame2a + anim->frac2;
					} else {
						anim->frac2 = 1.0f - (endframe2 - floorend2);
						anim->frame2 = anim->frame2b + (1.0f - anim->frac2);
					}
				} else {
					rwdata->unk02 = 0;
				}
			} else {
				model0001e14c(model, endframe, endframe2);
			}
		} else {
			model0001e14c(model, endframe, endframe2);
		}
	}
}

void model0001ee18(struct model *model, s32 lvupdate240, bool arg2)
{
	f32 frame;
	f32 frame2;
	f32 speed;
	f32 speed2;
	f32 startframe;
	f32 endframe;
	f32 realendframe;
	struct anim *anim = model->anim;

	if (anim && lvupdate240 > 0) {
		frame = anim->frame;
		frame2 = anim->frame2;

		for (; lvupdate240 > 0; lvupdate240--) {
			if (anim->timeplay > 0) {
				anim->elapseplay += 0.25f;

				if (anim->elapseplay < anim->timeplay) {
					anim->playspeed = anim->oldplay + (anim->newplay - anim->oldplay) * anim->elapseplay / anim->timeplay;
				} else {
					anim->timeplay = 0;
					anim->playspeed = anim->newplay;
				}
			}

			if (anim->timemerge > 0) {
				anim->elapsemerge += anim->playspeed * 0.25f;

				if (anim->elapsemerge == 0) {
					anim->fracmerge = 1;
				} else {
					if (anim->elapsemerge < anim->timemerge) {
						anim->fracmerge = (anim->timemerge - anim->elapsemerge) / anim->timemerge;
					} else {
						anim->timemerge = 0;
						anim->fracmerge = 0;
						anim->animnum2 = 0;
					}
				}
			}

			if (anim->timespeed > 0) {
				anim->elapsespeed += anim->playspeed * 0.25f;

				if (anim->elapsespeed < anim->timespeed) {
					anim->speed = anim->oldspeed + (anim->newspeed - anim->oldspeed) * anim->elapsespeed / anim->timespeed;
				} else {
					anim->timespeed = 0;
					anim->speed = anim->newspeed;
				}
			}

			speed = anim->speed;
			frame += anim->playspeed * speed * 0.25f;

			if (anim->animnum2) {
				if (anim->timespeed2 > 0) {
					anim->elapsespeed2 += anim->playspeed * 0.25f;

					if (anim->elapsespeed2 < anim->timespeed2) {
						anim->speed2 = anim->oldspeed2 + (anim->newspeed2 - anim->oldspeed2) * anim->elapsespeed2 / anim->timespeed2;
					} else {
						anim->timespeed2 = 0;
						anim->speed2 = anim->newspeed2;
					}
				}

				speed2 = anim->speed2;
				frame2 += anim->playspeed * speed2 * 0.25f;
			}

			if (anim->looping) {
				realendframe = anim->endframe;

				if (speed >= 0) {
					endframe = animGetNumFrames(anim->animnum) - 1;
					startframe = anim->loopframe;

					if (realendframe >= 0 && endframe > realendframe) {
						endframe = realendframe;
					}
				} else {
					endframe = anim->loopframe;
					startframe = animGetNumFrames(anim->animnum) - 1;

					if (realendframe >= 0 && startframe > realendframe) {
						startframe = realendframe;
					}
				}

				if ((speed >= 0 && frame >= endframe) || (speed < 0 && frame <= endframe)) {
					f32 prevnewspeed = anim->newspeed;
					f32 prevoldspeed = anim->oldspeed;
					f32 prevtimespeed = anim->timespeed;
					f32 prevelapsespeed = anim->elapsespeed;

					if (arg2) {
						model0001e2b4(model, anim->frame, endframe, 0, 0);
					} else {
						model0001e14c(model, endframe, 0);
					}

					modelSetAnimation(model, anim->animnum, anim->flip, startframe, anim->speed, anim->loopmerge);

					anim->looping = true;
					anim->endframe = realendframe;

					anim->newspeed = prevnewspeed;
					anim->oldspeed = prevoldspeed;
					anim->timespeed = prevtimespeed;
					anim->elapsespeed = prevelapsespeed;

					frame2 = frame;
					frame = startframe + frame - endframe;

					if (anim->flipfunc) {
						anim->flipfunc();
					}
				}
			}
		}

		if (arg2) {
			if (anim->animnum2) {
				model0001e2b4(model, anim->frame, frame, anim->frame2, frame2);
			} else {
				model0001e2b4(model, anim->frame, frame, 0, 0);
			}
		} else {
			if (anim->animnum2) {
				model0001e14c(model, frame, frame2);
			} else {
				model0001e14c(model, frame, 0);
			}
		}
	}
}

#if VERSION < VERSION_PAL_BETA
/**
 * This is identical to the above function but removes the 0.25f multipliers.
 */
void model0001f314(struct model *model, s32 lvupdate240, bool arg2)
{
	f32 frame;
	f32 frame2;
	f32 speed;
	f32 speed2;
	f32 startframe;
	f32 endframe;
	f32 realendframe;
	struct anim *anim = model->anim;

	if (anim && lvupdate240 > 0) {
		frame = anim->frame;
		frame2 = anim->frame2;

		for (; lvupdate240 > 0; lvupdate240--) {
			if (anim->timeplay > 0) {
				anim->elapseplay++;

				if (anim->elapseplay < anim->timeplay) {
					anim->playspeed = anim->oldplay + (anim->newplay - anim->oldplay) * anim->elapseplay / anim->timeplay;
				} else {
					anim->timeplay = 0;
					anim->playspeed = anim->newplay;
				}
			}

			if (anim->timemerge > 0) {
				anim->elapsemerge += anim->playspeed;

				if (anim->elapsemerge == 0) {
					anim->fracmerge = 1;
				} else {
					if (anim->elapsemerge < anim->timemerge) {
						anim->fracmerge = (anim->timemerge - anim->elapsemerge) / anim->timemerge;
					} else {
						anim->timemerge = 0;
						anim->fracmerge = 0;
						anim->animnum2 = 0;
					}
				}
			}

			if (anim->timespeed > 0) {
				anim->elapsespeed += anim->playspeed;

				if (anim->elapsespeed < anim->timespeed) {
					anim->speed = anim->oldspeed + (anim->newspeed - anim->oldspeed) * anim->elapsespeed / anim->timespeed;
				} else {
					anim->timespeed = 0;
					anim->speed = anim->newspeed;
				}
			}

			speed = anim->speed;
			frame += anim->playspeed * speed;

			if (anim->animnum2) {
				if (anim->timespeed2 > 0) {
					anim->elapsespeed2 += anim->playspeed;

					if (anim->elapsespeed2 < anim->timespeed2) {
						anim->speed2 = anim->oldspeed2 + (anim->newspeed2 - anim->oldspeed2) * anim->elapsespeed2 / anim->timespeed2;
					} else {
						anim->timespeed2 = 0;
						anim->speed2 = anim->newspeed2;
					}
				}

				speed2 = anim->speed2;
				frame2 += anim->playspeed * speed2;
			}

			if (anim->looping) {
				realendframe = anim->endframe;

				if (speed >= 0) {
					endframe = animGetNumFrames(anim->animnum) - 1;
					startframe = anim->loopframe;

					if (realendframe >= 0 && endframe > realendframe) {
						endframe = realendframe;
					}
				} else {
					endframe = anim->loopframe;
					startframe = animGetNumFrames(anim->animnum) - 1;

					if (realendframe >= 0 && startframe > realendframe) {
						startframe = realendframe;
					}
				}

				if ((speed >= 0 && frame >= endframe) || (speed < 0 && frame <= endframe)) {
					f32 prevnewspeed = anim->newspeed;
					f32 prevoldspeed = anim->oldspeed;
					f32 prevtimespeed = anim->timespeed;
					f32 prevelapsespeed = anim->elapsespeed;

					if (arg2) {
						model0001e2b4(model, anim->frame, endframe, 0, 0);
					} else {
						model0001e14c(model, endframe, 0);
					}

					modelSetAnimation(model, anim->animnum, anim->flip, startframe, anim->speed, anim->loopmerge);

					anim->looping = true;
					anim->endframe = realendframe;

					anim->newspeed = prevnewspeed;
					anim->oldspeed = prevoldspeed;
					anim->timespeed = prevtimespeed;
					anim->elapsespeed = prevelapsespeed;

					frame2 = frame;
					frame = startframe + frame - endframe;

					if (anim->flipfunc) {
						anim->flipfunc();
					}
				}
			}
		}

		if (arg2) {
			if (anim->animnum2) {
				model0001e2b4(model, anim->frame, frame, anim->frame2, frame2);
			} else {
				model0001e2b4(model, anim->frame, frame, 0, 0);
			}
		} else {
			if (anim->animnum2) {
				model0001e14c(model, frame, frame2);
			} else {
				model0001e14c(model, frame, 0);
			}
		}
	}
}
#endif

void model0001f7e0(struct modelrenderdata *renderdata)
{
	gDPPipeSync(renderdata->gdl++);
	gDPSetCycleType(renderdata->gdl++, G_CYC_1CYCLE);

	if (renderdata->zbufferenabled) {
		gDPSetRenderMode(renderdata->gdl++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
	} else {
		gDPSetRenderMode(renderdata->gdl++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
	}

	gDPSetCombineMode(renderdata->gdl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
}

void model0001f890(struct modelrenderdata *renderdata, bool arg1)
{
	if (renderdata->unk30 == 7) {
		if (arg1) {
			gDPPipeSync(renderdata->gdl++);
			gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
			gDPSetFogColorViaWord(renderdata->gdl++, renderdata->fogcolour);
			gDPSetEnvColorViaWord(renderdata->gdl++, renderdata->envcolour | 0xff);
			gDPSetCombineLERP(renderdata->gdl++, TEXEL0, ENVIRONMENT, SHADE_ALPHA, ENVIRONMENT, TEXEL0, ENVIRONMENT, SHADE, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);

			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
			}
		} else {
			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
			}
		}
	} else if (renderdata->unk30 == 8) {
		if (arg1) {
			gDPPipeSync(renderdata->gdl++);
			gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
			gDPSetFogColorViaWord(renderdata->gdl++, renderdata->fogcolour);
			gDPSetEnvColorViaWord(renderdata->gdl++, renderdata->envcolour);
			gDPSetCombineLERP(renderdata->gdl++, TEXEL0, ENVIRONMENT, SHADE_ALPHA, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);

			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
			}
		}
	} else if (renderdata->unk30 == 9) {
		if ((renderdata->envcolour & 0xff) == 0) {
			if (arg1) {
				gDPPipeSync(renderdata->gdl++);
				gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
				gDPSetFogColorViaWord(renderdata->gdl++, renderdata->fogcolour);
				gDPSetEnvColorViaWord(renderdata->gdl++, 0xffffffff);
				gDPSetPrimColor(renderdata->gdl++, 0, 0, 0, 0, 0, (renderdata->envcolour >> 8) & 0xff);
				gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, PRIMITIVE);

				if (renderdata->zbufferenabled) {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
				} else {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
				}
			} else {
				if (renderdata->zbufferenabled) {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
				} else {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
				}
			}
		} else {
			if (arg1) {
				gDPPipeSync(renderdata->gdl++);
				gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
				gDPSetFogColorViaWord(renderdata->gdl++, renderdata->fogcolour);
				gDPSetEnvColor(renderdata->gdl++, 0, 0, 0, renderdata->envcolour);
				gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, SHADE, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);

				if (renderdata->zbufferenabled) {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_TEX_EDGE2);
				} else {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_TEX_EDGE2);
				}
			} else {
				gDPSetPrimColor(renderdata->gdl++, 0, 0, 0, 0, 0, (renderdata->envcolour >> 8) & 0xff);
				gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, SHADE, ENVIRONMENT, TEXEL0, 0, COMBINED, 0, SHADE, 0, 1, 0, PRIMITIVE, COMBINED);

				if (renderdata->zbufferenabled) {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_TEX_EDGE2);
				} else {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_TEX_EDGE2);
				}
			}
		}
	} else if (renderdata->unk30 == 4) {
		if (arg1) {
			gDPPipeSync(renderdata->gdl++);
			gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
			gDPSetFogColorViaWord(renderdata->gdl++, renderdata->envcolour);
			gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);

			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
			}
		} else {
			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
			}
		}
	} else if (renderdata->unk30 == 5) {
		u8 alpha;

		if (arg1) {
			gDPPipeSync(renderdata->gdl++);
			gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
			gDPSetFogColorViaWord(renderdata->gdl++, renderdata->fogcolour);

			alpha = renderdata->envcolour & 0xff;

			if (alpha < 255) {
				gDPSetEnvColor(renderdata->gdl++, 0xff, 0xff, 0xff, alpha);

				if (renderdata->envcolour & 0xff00) {
					gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, SHADE, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
				} else {
					gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
				}
			} else {
				gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);
			}

			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
			}
		} else {
			alpha = renderdata->envcolour & 0xff;

			if (alpha < 255) {
				gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
			} else {
				gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);
			}
		}
	} else {
		if (arg1) {
			gDPPipeSync(renderdata->gdl++);
			gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
			gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);

			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_PASS, G_RM_AA_OPA_SURF2);
			}
		} else {
			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_PASS, G_RM_AA_XLU_SURF2);
			}
		}
	}
}

void model00020248(struct modelrenderdata *renderdata, bool arg1)
{
	if (renderdata->unk30 == 7) {
		gDPPipeSync(renderdata->gdl++);
		gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
		gDPSetFogColorViaWord(renderdata->gdl++, renderdata->fogcolour);
		gDPSetEnvColorViaWord(renderdata->gdl++, renderdata->envcolour | 0x000000ff);
		gDPSetCombineLERP(renderdata->gdl++, TEXEL0, ENVIRONMENT, SHADE_ALPHA, ENVIRONMENT, TEXEL0, ENVIRONMENT, SHADE, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);

		if (arg1) {
			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
			}
		} else {
			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
			}
		}
	} else if (renderdata->unk30 == 8) {
		gDPPipeSync(renderdata->gdl++);
		gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
		gDPSetFogColorViaWord(renderdata->gdl++, renderdata->fogcolour);
		gDPSetEnvColorViaWord(renderdata->gdl++, renderdata->envcolour);
		gDPSetCombineLERP(renderdata->gdl++, TEXEL0, ENVIRONMENT, SHADE_ALPHA, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);

		if (renderdata->zbufferenabled) {
			gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
		} else {
			gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
		}
	} else if (renderdata->unk30 == 9) {
		if ((renderdata->envcolour & 0xff) == 0) {
			gDPPipeSync(renderdata->gdl++);
			gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
			gDPSetFogColorViaWord(renderdata->gdl++, renderdata->fogcolour);
			gDPSetEnvColorViaWord(renderdata->gdl++, 0xffffffff);
			gDPSetPrimColor(renderdata->gdl++, 0, 0, 0, 0, 0, (renderdata->envcolour >> 8) & 0xff);

			if (arg1) {
				gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, PRIMITIVE);

				if (renderdata->zbufferenabled) {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
				} else {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
				}
			} else {
				gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, PRIMITIVE);

				if (renderdata->zbufferenabled) {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
				} else {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
				}
			}
		} else {
			gDPPipeSync(renderdata->gdl++);
			gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
			gDPSetFogColorViaWord(renderdata->gdl++, renderdata->fogcolour);
			gDPSetEnvColorViaWord(renderdata->gdl++, renderdata->envcolour & 0xff);

			if (arg1) {
				gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, SHADE, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);

				if (renderdata->zbufferenabled) {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_TEX_EDGE2);
				} else {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_TEX_EDGE2);
				}
			} else {
				gDPSetPrimColor(renderdata->gdl++, 0, 0, 0, 0, 0, (renderdata->envcolour >> 8) & 0xff);
				gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, SHADE, ENVIRONMENT, TEXEL0, 0, COMBINED, 0, SHADE, 0, 1, 0, PRIMITIVE, COMBINED);

				if (renderdata->zbufferenabled) {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_TEX_EDGE2);
				} else {
					gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_TEX_EDGE2);
				}
			}
		}
	} else if (renderdata->unk30 == 4) {
		gDPPipeSync(renderdata->gdl++);
		gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
		gDPSetFogColorViaWord(renderdata->gdl++, renderdata->envcolour);
		gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);

		if (arg1) {
			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
			}
		} else {
			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
			}
		}
	} else if (renderdata->unk30 == 5) {
		u8 alpha;

		gDPPipeSync(renderdata->gdl++);
		gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
		gDPSetFogColorViaWord(renderdata->gdl++, renderdata->fogcolour);

		alpha = renderdata->envcolour & 0xff;

		if (alpha < 255) {
			gDPSetEnvColor(renderdata->gdl++, 0xff, 0xff, 0xff, alpha);

			if (arg1) {
				if (renderdata->envcolour & 0xff00) {
					gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, SHADE, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
				} else {
					gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
				}
			} else {
				gDPSetCombineLERP(renderdata->gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
			}
		} else {
			gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);
		}

		if (renderdata->zbufferenabled) {
			gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
		} else {
			gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
		}
	} else {
		gDPPipeSync(renderdata->gdl++);
		gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);
		gDPSetFogColorViaWord(renderdata->gdl++, 0xffffff00);
		gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);

		if (arg1) {
			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_OPA_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_OPA_SURF2);
			}
		} else {
			if (renderdata->zbufferenabled) {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_ZB_XLU_SURF2);
			} else {
				gDPSetRenderMode(renderdata->gdl++, G_RM_FOG_PRIM_A, G_RM_AA_XLU_SURF2);
			}
		}
	}
}

void model00020bdc(struct modelrenderdata *renderdata)
{
	gDPPipeSync(renderdata->gdl++);
	gDPSetCycleType(renderdata->gdl++, G_CYC_2CYCLE);

	if (renderdata->zbufferenabled) {
		gDPSetRenderMode(renderdata->gdl++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
	} else {
		gDPSetRenderMode(renderdata->gdl++, G_RM_PASS, G_RM_AA_OPA_SURF2);
	}

	gDPSetCombineMode(renderdata->gdl++, G_CC_TRILERP, G_CC_MODULATEIA2);
}

void modelApplyCullMode(struct modelrenderdata *renderdata)
{
	if (renderdata->cullmode == CULLMODE_NONE) {
		gSPClearGeometryMode(renderdata->gdl++, G_CULL_BOTH);
	} else if (renderdata->cullmode == CULLMODE_FRONT) {
		gSPSetGeometryMode(renderdata->gdl++, G_CULL_FRONT);
	} else if (renderdata->cullmode == CULLMODE_BACK) {
		gSPSetGeometryMode(renderdata->gdl++, G_CULL_BACK);
	}
}

void modelRenderNodeGundl(struct modelrenderdata *renderdata, struct model *model, struct modelnode *node)
{
	struct modelrodata_gundl *rodata = &node->rodata->gundl;

	if (var8005efc4 && !var8005efc4(model, node)) {
		return;
	}

	if ((renderdata->flags & 1) && rodata->primary) {
		gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->baseaddr));

		if (renderdata->cullmode) {
			modelApplyCullMode(renderdata);
		}

		switch (rodata->unk12) {
		case 1:
			model0001f7e0(renderdata);
			break;
		case 3:
			model0001f890(renderdata, true);
			break;
		case 4:
			model00020248(renderdata, true);
			break;
		case 2:
			model00020bdc(renderdata);
			break;
		}

		gSPDisplayList(renderdata->gdl++, rodata->primary);

		if (rodata->unk12 == 3 && rodata->secondary) {
			model0001f890(renderdata, false);

			gSPDisplayList(renderdata->gdl++, rodata->secondary);
		}
	}

	if ((renderdata->flags & 2) && rodata->primary && rodata->unk12 == 4 && rodata->secondary) {
		gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->baseaddr));

		if (renderdata->cullmode) {
			modelApplyCullMode(renderdata);
		}

		model00020248(renderdata, false);

		gSPDisplayList(renderdata->gdl++, rodata->secondary);
	}
}

void modelRenderNodeDl(struct modelrenderdata *renderdata, struct model *model, struct modelnode *node)
{
	union modelrodata *rodata = node->rodata;

	if (var8005efc4 && !var8005efc4(model, node)) {
		return;
	}

	if (renderdata->flags & 1) {
		union modelrwdata *rwdata = modelGetNodeRwData(model, node);

		if (rwdata->dl.gdl) {
			gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->dl.colourtable));

			if (renderdata->cullmode) {
				modelApplyCullMode(renderdata);
			}

			switch (rodata->dl.mcount) {
			case 1:
				model0001f7e0(renderdata);
				break;
			case 3:
				model0001f890(renderdata, true);
				break;
			case 4:
				model00020248(renderdata, true);
				break;
			case 2:
				model00020bdc(renderdata);
				break;
			}

			gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_VTX, osVirtualToPhysical(rwdata->dl.vertices));
			gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL2, osVirtualToPhysical(rwdata->dl.colours));

			gSPDisplayList(renderdata->gdl++, rwdata->dl.gdl);

			if (rodata->dl.mcount == 3 && rodata->dl.secondary) {
				model0001f890(renderdata, false);

				gSPDisplayList(renderdata->gdl++, rodata->dl.secondary);
			}
		}
	}

	if (renderdata->flags & 2) {
		union modelrwdata *rwdata = modelGetNodeRwData(model, node);

		if (rwdata->dl.gdl && rodata->dl.mcount == 4 && rodata->dl.secondary) {
			gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->dl.colourtable));

			if (renderdata->cullmode) {
				modelApplyCullMode(renderdata);
			}

			gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_VTX, osVirtualToPhysical(rwdata->dl.vertices));
			gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL2, osVirtualToPhysical(rwdata->dl.colours));

			model00020248(renderdata, false);

			gSPDisplayList(renderdata->gdl++, rodata->dl.secondary);
		}
	}
}

/**
 * Star gunfire is a muzzle flash in a first person perspective, where the
 * muzzle flash has 3 or 4 "arms" that flare out from the main body.
 *
 * Some weapons that use this are the Cyclone, Dragon, K7 Avenger, AR34,
 * SuperDragon and RC-P45.
 *
 * This function reads vertices from the model definition, tweaks them randomly,
 * writes them to a newly allocated vertices table and queues the node's
 * displaylist to the renderdata's DL.
 */
void modelRenderNodeStarGunfire(struct modelrenderdata *renderdata, struct modelnode *node)
{
	if (renderdata->flags & 2) {
		struct modelrodata_stargunfire *rodata = &node->rodata->stargunfire;
		s32 i;

		if (rodata->gdl) {
			struct gfxvtx *src = (struct gfxvtx *) rodata->vertices;
			struct gfxvtx *dst = g_ModelVtxAllocatorFunc(rodata->unk00 * 4);

			gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_VTX, osVirtualToPhysical(dst));
			gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL2, osVirtualToPhysical((void *)ALIGN8((u32)&rodata->vertices[rodata->unk00 << 2])));
			gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->baseaddr));

			gDPSetFogColor(renderdata->gdl++, 0x00, 0x00, 0x00, 0x00);
			gSPDisplayList(renderdata->gdl++, rodata->gdl);

			for (i = 0; i < rodata->unk00; i++) {
				u16 rand1 = (random() << 10) & 0xffff;
				s32 s4 = ((coss(rand1) << 5) * 181) >> 18;
				s32 s3 = ((sins(rand1) << 5) * 181) >> 18;
				s32 s1 = random() >> 31;
				s32 mult = 0x10000 - (random() & 0x3fff);
				s32 corner1 = 0x200 + s3;
				s32 corner2 = 0x200 - s3;
				s32 corner3 = 0x200 - s4;
				s32 corner4 = 0x200 + s4;

				dst[0] = src[0];
				dst[1] = src[1];
				dst[2] = src[2];
				dst[3] = src[3];

				dst[0].s = corner3;
				dst[0].t = corner2;
				dst[0].x = (src[(s1 + 0) % 4].x * mult) >> 16;
				dst[0].y = (src[(s1 + 0) % 4].y * mult) >> 16;
				dst[0].z = (src[(s1 + 0) % 4].z * mult) >> 16;

				dst[1].s = corner1;
				dst[1].t = corner3;
				dst[1].x = (src[(s1 + 1) % 4].x * mult) >> 16;
				dst[1].y = (src[(s1 + 1) % 4].y * mult) >> 16;
				dst[1].z = (src[(s1 + 1) % 4].z * mult) >> 16;

				dst[2].s = corner4;
				dst[2].t = corner1;
				dst[2].x = (src[(s1 + 2) % 4].x * mult) >> 16;
				dst[2].y = (src[(s1 + 2) % 4].y * mult) >> 16;
				dst[2].z = (src[(s1 + 2) % 4].z * mult) >> 16;

				dst[3].s = corner2;
				dst[3].t = corner4;
				dst[3].x = (src[(s1 + 3) % 4].x * mult) >> 16;
				dst[3].y = (src[(s1 + 3) % 4].y * mult) >> 16;
				dst[3].z = (src[(s1 + 3) % 4].z * mult) >> 16;

				src += 4;
				dst += 4;
			}
		}
	}
}

void model000216cc(struct modelrenderdata *renderdata, struct textureconfig *tconfig, s32 arg2)
{
	texSelect(&renderdata->gdl, tconfig, arg2, renderdata->zbufferenabled, 2, 1, NULL);
}

void modelRenderNodeChrGunfire(struct modelrenderdata *renderdata, struct model *model, struct modelnode *node)
{
	u32 stack[3];
	f32 negspc0;
	struct modelrodata_chrgunfire *rodata = &node->rodata->chrgunfire;
	union modelrwdata *rwdata = modelGetNodeRwData(model, node);
	struct gfxvtx *vertices;
	f32 spf0;
	f32 spec;
	struct coord spe0;
	f32 spdc;
	f32 spd8;
	f32 spd4;
	f32 spd0;
	f32 spcc;
	f32 spc8;
	f32 spc4;
	f32 spc0;
	f32 spbc;
	f32 negspcc;
	f32 negspc8;
	f32 scale;
	Mtxf *mtx;
	f32 tmp;
	struct coord sp9c;
	struct coord sp90;
	struct gfxvtx vtxtemplate = {0};
	struct colour colourtemplate = {0xffffffff};
	struct textureconfig *tconfig;
	struct colour *colours;
	f32 distance;

	if ((renderdata->flags & 2) && rwdata->chrgunfire.visible) {
		s32 index = model0001a524(node, 0);
		mtx = &model->matrices[index];

		spe0.x = -(rodata->pos.f[0] * mtx->m[0][0] + rodata->pos.f[1] * mtx->m[1][0] + rodata->pos.f[2] * mtx->m[2][0] + mtx->m[3][0]);
		spe0.y = -(rodata->pos.f[0] * mtx->m[0][1] + rodata->pos.f[1] * mtx->m[1][1] + rodata->pos.f[2] * mtx->m[2][1] + mtx->m[3][1]);
		spe0.z = -(rodata->pos.f[0] * mtx->m[0][2] + rodata->pos.f[1] * mtx->m[1][2] + rodata->pos.f[2] * mtx->m[2][2] + mtx->m[3][2]);

		distance = sqrtf(spe0.f[0] * spe0.f[0] + spe0.f[1] * spe0.f[1] + spe0.f[2] * spe0.f[2]);

		if (distance > 0) {
			f32 tmp = 1 / (model->scale * distance);
			spe0.f[0] *= tmp;
			spe0.f[1] *= tmp;
			spe0.f[2] *= tmp;
		} else {
			spe0.f[0] = 0;
			spe0.f[1] = 0;
			spe0.f[2] = 1 / model->scale;
		}

		spec = acosf(spe0.f[0] * mtx->m[1][0] + spe0.f[1] * mtx->m[1][1] + spe0.f[2] * mtx->m[1][2]);
		spf0 = acosf(-(spe0.f[0] * mtx->m[2][0] + spe0.f[1] * mtx->m[2][1] + spe0.f[2] * mtx->m[2][2]) / sinf(spec));

		tmp = -(spe0.f[0] * mtx->m[0][0] + spe0.f[1] * mtx->m[0][1] + spe0.f[2] * mtx->m[0][2]);

		if (tmp < 0) {
			spf0 = M_BADTAU - spf0;
		}

		spdc = cosf(spf0);
		spd8 = sinf(spf0);
		spd4 = cosf(spec);
		spd0 = sinf(spec);

		scale = 0.75f + (random() % 128) * (1.0f / 256.0f); // 0.75 to 1.25

		sp9c.f[0] = rodata->dim.f[0] * scale;
		sp9c.f[1] = rodata->dim.f[1] * scale;
		sp9c.f[2] = rodata->dim.f[2] * scale;

		spcc = sp9c.f[0] * spdc * 0.5f;
		spc8 = sp9c.f[2] * spd8 * 0.5f;
		spc4 = sp9c.f[1] * spd0 * 0.5f;

		spc0 = sp9c.f[0] * spd4 * spd8 * 0.5f;
		spbc = sp9c.f[2] * spd4 * spdc * 0.5f;

		negspcc = -spcc;
		negspc8 = -spc8;
		negspc0 = -spc0;

		sp90.f[0] = rodata->pos.f[0] - sp9c.f[0] * 0.5f;
		sp90.f[1] = rodata->pos.f[1];
		sp90.f[2] = rodata->pos.f[2];

		vertices = g_ModelVtxAllocatorFunc(4);

		colours = (struct colour *) gfxAllocateColours(1);

		vertices[0] = vtxtemplate;
		vertices[1] = vtxtemplate;
		vertices[2] = vtxtemplate;
		vertices[3] = vtxtemplate;

		colours[0] = colourtemplate;

		vertices[0].x = sp90.f[0] + negspcc + negspc0;
		vertices[0].y = sp90.f[1] - spc4;
		vertices[0].z = sp90.f[2] - negspc8 + -spbc;
		vertices[1].x = sp90.f[0] + negspcc - negspc0;
		vertices[1].y = sp90.f[1] + spc4;
		vertices[1].z = sp90.f[2] - negspc8 - -spbc;
		vertices[2].x = sp90.f[0] - negspcc - negspc0;
		vertices[2].y = sp90.f[1] + spc4;
		vertices[2].z = sp90.f[2] + negspc8 - -spbc;
		vertices[3].x = sp90.f[0] - negspcc + negspc0;
		vertices[3].y = sp90.f[1] - spc4;
		vertices[3].z = sp90.f[2] + negspc8 + -spbc;

		gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_COL1, osVirtualToPhysical(rodata->baseaddr));

		if (rodata->texture) {
			s32 centre;
			u16 sp62;
			s32 sp5c;
			s32 sp58;

			tconfig = rodata->texture;

			sp62 = (random() * 1024) & 0xffff;
			sp5c = (coss(sp62) * tconfig->width * 0xb5) >> 18;
			sp58 = (sins(sp62) * tconfig->width * 0xb5) >> 18;

			centre = tconfig->width << 4;

			vertices[0].s = centre - sp5c;
			vertices[0].t = centre - sp58;
			vertices[1].s = centre + sp58;
			vertices[1].t = centre - sp5c;
			vertices[2].s = centre + sp5c;
			vertices[2].t = centre + sp58;
			vertices[3].s = centre - sp58;
			vertices[3].t = centre + sp5c;

			model000216cc(renderdata, tconfig, 4);
		} else {
			model000216cc(renderdata, NULL, 1);
		}

		gSPSetGeometryMode(renderdata->gdl++, G_CULL_BACK);
		gSPMatrix(renderdata->gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gDPSetColorArray(renderdata->gdl++, osVirtualToPhysical(colours), 1);
		gDPSetVerticeArray(renderdata->gdl++, osVirtualToPhysical(vertices), 4);
		gDPTri2(renderdata->gdl++, 0, 1, 2, 2, 3, 0);
	}
}

void modelRender(struct modelrenderdata *renderdata, struct model *model)
{
	union modelrodata *rodata;
	union modelrwdata *rwdata;
	u32 type;
	struct modelnode *node = model->filedata->rootnode;

	gSPSegment(renderdata->gdl++, SPSEGMENT_MODEL_MTX, osVirtualToPhysical(model->matrices));

	while (node) {
		type = node->type & 0xff;

		switch (type) {
		case MODELNODETYPE_DISTANCE:
		case MODELNODETYPE_TOGGLE:
			rodata = node->rodata;
			rwdata = modelGetNodeRwData(model, node);

			switch (type) {
			case MODELNODETYPE_DISTANCE:
				node->child = rwdata->distance.visible ? rodata->distance.target : NULL;
				break;
			case MODELNODETYPE_TOGGLE:
				node->child = rwdata->toggle.visible ? rodata->toggle.target : NULL;
				break;
			}
			break;
		case MODELNODETYPE_HEADSPOT:
			rwdata = modelGetNodeRwData(model, node);

			if (rwdata->headspot.modelfiledata) {
				struct modelnode *loopnode = rwdata->headspot.modelfiledata->rootnode;
				node->child = loopnode;

				while (loopnode) {
					loopnode->parent = node;
					loopnode = loopnode->next;
				}
			}
			break;
		case MODELNODETYPE_REORDER:
			modelRenderNodeReorder(model, node);
			break;
		case MODELNODETYPE_CHRGUNFIRE:
			modelRenderNodeChrGunfire(renderdata, model, node);
			break;
		case MODELNODETYPE_GUNDL:
			modelRenderNodeGundl(renderdata, model, node);
			break;
		case MODELNODETYPE_DL:
			modelRenderNodeDl(renderdata, model, node);
			break;
		case MODELNODETYPE_STARGUNFIRE:
			modelRenderNodeStarGunfire(renderdata, node);
			break;
		case MODELNODETYPE_CHRINFO:
		default:
			break;
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
}

bool model000220fc(struct modelrodata_bbox *bbox, Mtxf *mtx, struct coord *arg2, struct coord *arg3)
{
	f32 xthingx;
	f32 xthingy;
	f32 xthingz;
	u32 stack1[3];
	f32 xsum1;
	f32 xsum2;
	f32 xsum3;

	f32 f0;
	u32 stack;

	f32 ythingx;
	f32 ythingy;
	f32 ythingz;
	u32 stack2[3];
	f32 ysum1;
	f32 ysum2;
	f32 ysum3;

	f32 mult1;
	f32 mult2;

	f32 bestsum2;
	f32 bestsum1;
	f32 anotherbestsum3;
	f32 anotherbestsum1;

	f32 xmin = bbox->xmin;
	f32 xmax = bbox->xmax;
	f32 ymin = bbox->ymin;
	f32 ymax = bbox->ymax;
	f32 zmin = bbox->zmin;
	f32 zmax = bbox->zmax;

	f32 mult3;
	f32 mult4;

	f32 zthingx;
	f32 zthingy;
	f32 zthingz;
	u32 stack3[3];
	f32 zsum1;
	f32 zsum2;
	f32 zsum3;

	if (var8005efc0 != 0.0f) {
		xmin -= var8005efc0;
		xmax += var8005efc0;
		ymin -= var8005efc0;
		ymax += var8005efc0;
		zmin -= var8005efc0;
		zmax += var8005efc0;
	}

	// x
	xthingx = mtx->m[0][0] * mtx->m[0][0];
	xthingy = mtx->m[0][1] * mtx->m[0][1];
	xthingz = mtx->m[0][2] * mtx->m[0][2];

	xsum1 = mtx->m[0][0] * arg3->f[0] + mtx->m[0][1] * arg3->f[1] + mtx->m[0][2] * arg3->f[2];
	xsum2 = mtx->m[0][0] * (arg2->f[0] - mtx->m[3][0]) + mtx->m[0][1] * (arg2->f[1] - mtx->m[3][1]) + mtx->m[0][2] * (arg2->f[2] - mtx->m[3][2]);

	f0 = -(xthingx + xthingy + xthingz) * xmax;
	xsum3 = -(xsum2 + f0);
	f0 = -(xthingx + xthingy + xthingz) * xmin;
	xsum2 = -(xsum2 + f0);

	if (xsum1 < 0.0f) {
		xsum1 = -xsum1;
		xsum2 = -xsum2;
		xsum3 = -xsum3;
	}

	if (xsum2 < 0.0f && xsum3 < 0.0f) {
		return false;
	}

	if (xsum3 < xsum2) {
		f32 tmp = xsum2;
		xsum2 = xsum3;
		xsum3 = tmp;
	}

	// y
	ythingx = mtx->m[1][0] * mtx->m[1][0];
	ythingy = mtx->m[1][1] * mtx->m[1][1];
	ythingz = mtx->m[1][2] * mtx->m[1][2];

	ysum1 = mtx->m[1][0] * arg3->f[0] + mtx->m[1][1] * arg3->f[1] + mtx->m[1][2] * arg3->f[2];
	ysum2 = mtx->m[1][0] * (arg2->f[0] - mtx->m[3][0]) + mtx->m[1][1] * (arg2->f[1] - mtx->m[3][1]) + mtx->m[1][2] * (arg2->f[2] - mtx->m[3][2]);

	f0 = -(ythingx + ythingy + ythingz) * ymax;
	ysum3 = -(ysum2 + f0);
	f0 = -(ythingx + ythingy + ythingz) * ymin;
	ysum2 = -(ysum2 + f0);

	if (ysum1 < 0.0f) {
		ysum1 = -ysum1;
		ysum2 = -ysum2;
		ysum3 = -ysum3;
	}

	if (ysum2 < 0.0f && ysum3 < 0.0f) {
		return false;
	}

	if (ysum3 < ysum2) {
		f32 tmp = ysum2;
		ysum2 = ysum3;
		ysum3 = tmp;
	}

	// Do x and y comparison things
	mult1 = ysum2 * xsum1;
	mult2 = xsum2 * ysum1;
	mult3 = xsum3 * ysum1;
	mult4 = ysum3 * xsum1;

	if (mult1 < mult2) {
		if (mult4 < mult2) {
			return false;
		}

		bestsum2 = xsum2;
		bestsum1 = xsum1;
	} else {
		if (mult3 < mult1) {
			return false;
		}

		bestsum2 = ysum2;
		bestsum1 = ysum1;
	}

	if (mult3 < mult4) {
		anotherbestsum3 = xsum3;
		anotherbestsum1 = xsum1;
	} else {
		anotherbestsum3 = ysum3;
		anotherbestsum1 = ysum1;
	}

	// z
	zthingx = mtx->m[2][0] * mtx->m[2][0];
	zthingy = mtx->m[2][1] * mtx->m[2][1];
	zthingz = mtx->m[2][2] * mtx->m[2][2];

	zsum1 = mtx->m[2][0] * arg3->f[0] + mtx->m[2][1] * arg3->f[1] + mtx->m[2][2] * arg3->f[2];
	zsum2 = mtx->m[2][0] * (arg2->f[0] - mtx->m[3][0]) + mtx->m[2][1] * (arg2->f[1] - mtx->m[3][1]) + mtx->m[2][2] * (arg2->f[2] - mtx->m[3][2]);

	f0 = -(zthingx + zthingy + zthingz) * zmax;
	zsum3 = -(zsum2 + f0);
	f0 = -(zthingx + zthingy + zthingz) * zmin;
	zsum2 = -(zsum2 + f0);

	if (zsum1 < 0.0f) {
		zsum1 = -zsum1;
		zsum2 = -zsum2;
		zsum3 = -zsum3;
	}

	if (zsum2 < 0.0f && zsum3 < 0.0f) {
		return false;
	}

	if (zsum3 < zsum2) {
		f32 tmp = zsum2;
		zsum2 = zsum3;
		zsum3 = tmp;
	}

	// Do z comparison things with the result of the x/y comparison thing
	if (bestsum2 * zsum1 < zsum2 * bestsum1) {
		if (anotherbestsum3 * zsum1 < zsum2 * anotherbestsum1) {
			return false;
		}
	} else {
		if (zsum3 * bestsum1 < bestsum2 * zsum1) {
			return false;
		}
	}

	return true;
}

s32 model000225d4(struct model *model, struct coord *arg1, struct coord *arg2, struct modelnode **startnode)
{
	struct modelnode *node;
	bool dochildren = true;
	Mtxf *mtx;
	union modelrodata *rodata;
	union modelrwdata *rwdata;
	u32 type;

	if (model);

	if (*startnode) {
		node = *startnode;
		*startnode = NULL;
	} else {
		node = model->filedata->rootnode;
	}

	while (node) {
		if (dochildren && node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}

			if (!node) {
				break;
			}
		}

		dochildren = true;
		type = node->type & 0xff;

		switch (type) {
		case MODELNODETYPE_BBOX:
			rodata = node->rodata;
			mtx = model0001a5cc(model, node, 0);

			if (model000220fc(&rodata->bbox, mtx, arg1, arg2)) {
				*startnode = node;
				return rodata->bbox.hitpart;
			}

			dochildren = false;
			break;
		case MODELNODETYPE_DISTANCE:
			rodata = node->rodata;
			rwdata = modelGetNodeRwData(model, node);
			node->child = rwdata->distance.visible ? rodata->distance.target : NULL;
			break;
		case MODELNODETYPE_TOGGLE:
			rodata = node->rodata;
			rwdata = modelGetNodeRwData(model, node);
			node->child = rwdata->toggle.visible ? rodata->toggle.target : NULL;
			break;
		case MODELNODETYPE_HEADSPOT:
			rwdata = modelGetNodeRwData(model, node);

			if (rwdata->headspot.modelfiledata) {
				struct modelnode *loopnode = rwdata->headspot.modelfiledata->rootnode;

				node->child = loopnode;

				while (loopnode) {
					loopnode->parent = node;
					loopnode = loopnode->next;
				}
			}
			break;
		case MODELNODETYPE_CHRINFO:
		case MODELNODETYPE_DL:
		default:
			break;
		}
	}

	return 0;
}

#define PROMOTE(var) \
	if (var) \
		var = (void *)((u32)var + diff)

void modelPromoteNodeOffsetsToPointers(struct modelnode *node, u32 vma, u32 fileramaddr)
{
	union modelrodata *rodata;
	s32 diff = fileramaddr - vma;

	while (node) {
		u32 type = node->type & 0xff;

		PROMOTE(node->rodata);
		PROMOTE(node->parent);
		PROMOTE(node->next);
		PROMOTE(node->prev);
		PROMOTE(node->child);

		switch (type) {
		case MODELNODETYPE_CHRINFO:
			break;
		case MODELNODETYPE_POSITION:
			break;
		case MODELNODETYPE_GUNDL:
			rodata = node->rodata;
			PROMOTE(rodata->gundl.vertices);
			rodata->gundl.baseaddr = (void *)fileramaddr;
			break;
		case MODELNODETYPE_DL:
			rodata = node->rodata;
			PROMOTE(rodata->dl.vertices);
			rodata->dl.colourtable = (void *)fileramaddr;
			break;
		case MODELNODETYPE_DISTANCE:
			rodata = node->rodata;
			PROMOTE(rodata->distance.target);
			node->child = rodata->distance.target;
			break;
		case MODELNODETYPE_TOGGLE:
			rodata = node->rodata;
			PROMOTE(rodata->toggle.target);
			break;
		case MODELNODETYPE_REORDER:
			rodata = node->rodata;
			PROMOTE(rodata->reorder.unk18);
			PROMOTE(rodata->reorder.unk1c);
			break;
		case MODELNODETYPE_11:
			rodata = node->rodata;
			PROMOTE(rodata->type11.unk14);
			break;
		case MODELNODETYPE_0B:
			rodata = node->rodata;
			PROMOTE(rodata->type0b.unk3c);
			rodata->type0b.baseaddr = (void *)fileramaddr;
			break;
		case MODELNODETYPE_CHRGUNFIRE:
			rodata = node->rodata;
			PROMOTE(rodata->chrgunfire.texture);
			rodata->chrgunfire.baseaddr = (void *)fileramaddr;
			break;
		case MODELNODETYPE_0D:
			rodata = node->rodata;
			PROMOTE(rodata->type0d.unk10);
			PROMOTE(rodata->type0d.unk14);
			rodata->type0d.baseaddr = (void *)fileramaddr;
			break;
		case MODELNODETYPE_STARGUNFIRE:
			rodata = node->rodata;
			PROMOTE(rodata->stargunfire.vertices);
			rodata->stargunfire.baseaddr = (void *)fileramaddr;
			break;
		default:
			break;
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
}

/**
 * Convert a model file's file-relative offsets to global pointers,
 * and sort the part numbers list so they can be looked up using bisection.
 *
 * Offsets in model files are based from virtual memory address 0x0f000000.
 * This vma address is specified as an argument to the function.
 */
void modelPromoteOffsetsToPointers(struct modelfiledata *filedata, u32 vma, u32 fileramaddr)
{
	s32 diff = fileramaddr - vma;
	s32 i;
	s16 *partnums;

	PROMOTE(filedata->rootnode);
	PROMOTE(filedata->parts);
	PROMOTE(filedata->texconfigs);

	for (i = 0; i < filedata->numparts; i++) {
		PROMOTE(filedata->parts[i]);
	}

	modelPromoteNodeOffsetsToPointers(filedata->rootnode, vma, fileramaddr);

	// Sort parts by part number so they can be bisected during lookup
	partnums = (s16 *)&filedata->parts[filedata->numparts];

	if (filedata->numparts) {
		struct modelnode *tmpnode;
		s16 tmpnum;
		bool changed;

		do {
			changed = false;

			for (i = 0; i < filedata->numparts - 1; i++) {
				if (partnums[i] > partnums[i + 1]) {
					tmpnum = partnums[i];
					partnums[i] = partnums[i + 1];
					partnums[i + 1] = tmpnum;

					tmpnode = filedata->parts[i];
					filedata->parts[i] = filedata->parts[i + 1];
					filedata->parts[i + 1] = tmpnode;

					changed = true;
				}
			}
		} while (changed == true);
	}
}

s32 modelCalculateRwDataIndexes(struct modelnode *basenode)
{
	u16 len = 0;
	struct modelnode *node = basenode;
	union modelrodata *rodata;

	while (node) {
		u32 type = node->type & 0xff;

		switch (type) {
		case MODELNODETYPE_CHRINFO:
			rodata = node->rodata;
			rodata->chrinfo.rwdataindex = len;
			len += sizeof(struct modelrwdata_chrinfo) / 4;
			break;
		case MODELNODETYPE_DISTANCE:
			rodata = node->rodata;
			rodata->distance.rwdataindex = len;
			len += sizeof(struct modelrwdata_distance) / 4;
			node->child = rodata->distance.target;
			break;
		case MODELNODETYPE_TOGGLE:
			rodata = node->rodata;
			rodata->toggle.rwdataindex = len;
			len += sizeof(struct modelrwdata_toggle) / 4;
			node->child = rodata->toggle.target;
			break;
		case MODELNODETYPE_HEADSPOT:
			rodata = node->rodata;
			rodata->headspot.rwdataindex = len;
			len += sizeof(struct modelrwdata_headspot) / 4;
			node->child = NULL;
			break;
		case MODELNODETYPE_REORDER:
			rodata = node->rodata;
			rodata->reorder.rwdataindex = len;
			len += sizeof(struct modelrwdata_reorder) / 4;
			model0001c868(node, false);
			break;
		case MODELNODETYPE_0B:
			rodata = node->rodata;
			rodata->type0b.rwdataindex = len;
			len += sizeof(struct modelrwdata_0b) / 4;
			break;
		case MODELNODETYPE_CHRGUNFIRE:
			rodata = node->rodata;
			rodata->chrgunfire.rwdataindex = len;
			len += sizeof(struct modelrwdata_chrgunfire) / 4;
			break;
		case MODELNODETYPE_DL:
			rodata = node->rodata;
			rodata->dl.rwdataindex = len;
			len += sizeof(struct modelrwdata_dl) / 4;
			break;
		default:
			break;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node == basenode->parent) {
					node = NULL;
					break;
				}

				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	return len;
}

void modelCalculateRwDataLen(struct modelfiledata *filedata)
{
	filedata->rwdatalen = modelCalculateRwDataIndexes(filedata->rootnode);
}

void modelInitRwData(struct model *model, struct modelnode *startnode)
{
	struct modelnode *node = startnode;
	union modelrodata *rodata;
	union modelrwdata *rwdata;

	while (node) {
		u32 type = node->type & 0xff;

		switch (type) {
		case MODELNODETYPE_CHRINFO:
			rwdata = modelGetNodeRwData(model, node);

			rwdata->chrinfo.unk00 = 0;
			rwdata->chrinfo.ground = 0;
			rwdata->chrinfo.pos.x = 0;
			rwdata->chrinfo.pos.y = 0;
			rwdata->chrinfo.pos.z = 0;
			rwdata->chrinfo.unk14 = 0;
			rwdata->chrinfo.unk18 = 0;
			rwdata->chrinfo.unk1c = 0;

			rwdata->chrinfo.unk01 = 0;
			rwdata->chrinfo.unk34.x = 0;
			rwdata->chrinfo.unk34.y = 0;
			rwdata->chrinfo.unk34.z = 0;
			rwdata->chrinfo.unk30 = 0;
			rwdata->chrinfo.unk24.x = 0;
			rwdata->chrinfo.unk24.y = 0;
			rwdata->chrinfo.unk24.z = 0;
			rwdata->chrinfo.unk20 = 0;

			rwdata->chrinfo.unk02 = 0;
			rwdata->chrinfo.unk4c.x = 0;
			rwdata->chrinfo.unk4c.y = 0;
			rwdata->chrinfo.unk4c.z = 0;
			rwdata->chrinfo.unk40.x = 0;
			rwdata->chrinfo.unk40.y = 0;
			rwdata->chrinfo.unk40.z = 0;
			rwdata->chrinfo.unk5c = 0;
			break;
		case MODELNODETYPE_DISTANCE:
			rodata = node->rodata;
			rwdata = modelGetNodeRwData(model, node);
			rwdata->distance.visible = false;
			node->child = rodata->distance.target;
			break;
		case MODELNODETYPE_TOGGLE:
			rodata = node->rodata;
			rwdata = modelGetNodeRwData(model, node);
			rwdata->toggle.visible = true;
			node->child = rodata->toggle.target;
			break;
		case MODELNODETYPE_HEADSPOT:
			rwdata = modelGetNodeRwData(model, node);
			rwdata->headspot.modelfiledata = NULL;
			rwdata->headspot.rwdatas = NULL;
			break;
		case MODELNODETYPE_REORDER:
			rwdata = modelGetNodeRwData(model, node);
			rwdata->reorder.visible = false;
			modelRenderNodeReorder(model, node);
			break;
		case MODELNODETYPE_0B:
			rwdata = modelGetNodeRwData(model, node);
			rwdata->type0b.unk00 = 0;
			break;
		case MODELNODETYPE_CHRGUNFIRE:
			rwdata = modelGetNodeRwData(model, node);
			rwdata->chrgunfire.visible = false;
			break;
		case MODELNODETYPE_DL:
			rodata = node->rodata;
			rwdata = modelGetNodeRwData(model, node);
			rwdata->dl.vertices = rodata->dl.vertices;
			rwdata->dl.gdl = rodata->dl.primary;
			rwdata->dl.colours = (void *) ALIGN8((u32)(rodata->dl.vertices + rodata->dl.numvertices));
			if (rodata->dl.numvertices);
			if (rodata->dl.numvertices);
			if (rodata->dl.numvertices);
			break;
		default:
			break;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node == startnode->parent) {
					node = NULL;
					break;
				}

				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}
}

void modelInit(struct model *model, struct modelfiledata *filedata, union modelrwdata **rwdatas, bool resetanim)
{
	struct modelnode *node;

	model->unk00 = 0;
	model->filedata = filedata;
	model->rwdatas = rwdatas;
	model->rwdatalen = -1;
	model->scale = 1;
	model->attachedtomodel = NULL;
	model->attachedtonode = NULL;

	node = filedata->rootnode;

	while (node) {
		u32 type = node->type & 0xff;

		if (type == MODELNODETYPE_HEADSPOT) {
			model->unk00 |= 1;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node == filedata->rootnode->parent) {
					node = NULL;
					break;
				}

				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	if (rwdatas != NULL) {
		modelInitRwData(model, filedata->rootnode);
	}

	if (resetanim) {
		model->anim = NULL;
	}
}

void animInit(struct anim *anim)
{
	anim->animnum = 0;
	anim->animnum2 = 0;
	anim->looping = 0;
	anim->flipfunc = NULL;
	anim->unk6c = 0;
	anim->unk70 = NULL;
	anim->average = 0;
	anim->frac = 0;
	anim->timespeed = 0;
	anim->frac2 = 0;
	anim->timespeed2 = 0;
	anim->fracmerge = 0;
	anim->timemerge = 0;
	anim->timeplay = 0;
	anim->endframe = -1;
	anim->endframe2 = -1;
	anim->speed = 1;
	anim->speed2 = 1;
	anim->playspeed = 1;
	anim->animscale = 1;
}

void model00023108(struct model *pmodel, struct modelfiledata *pmodeldef, struct modelnode *pnode, struct modelfiledata *cmodeldef)
{
	struct modelrwdata_headspot *rwdata = modelGetNodeRwData(pmodel, pnode);
	struct modelnode *node;

	rwdata->modelfiledata = cmodeldef;
	rwdata->rwdatas = &pmodel->rwdatas[pmodeldef->rwdatalen];

	pnode->child = cmodeldef->rootnode;

	node = pnode->child;

	while (node) {
		node->parent = pnode;
		node = node->next;
	}

	pmodeldef->rwdatalen += modelCalculateRwDataIndexes(pnode->child);
}

/**
 * This function can be called repeatedly to iterate a model's display lists.
 *
 * On the first call, the value passed as nodeptr should point to a NULL value.
 * Each time the function is called, it will update *gdlptr to point to the next
 * display list, and will update *nodeptr to point to the current node. On
 * subsequent calls, the same values should be passed as nodeptr and gdlptr so
 * the function can continue correctly.
 *
 * Note that some node types support multiple display lists, so the function
 * may return the same node while it iterates the display lists for that node.
 */
void modelIterateDisplayLists(struct modelfiledata *filedata, struct modelnode **nodeptr, Gfx **gdlptr)
{
	struct modelnode *node = *nodeptr;
	union modelrodata *rodata;
	Gfx *gdl = NULL;

	if (node == NULL) {
		node = filedata->rootnode;
	}

	while (node) {
		u32 type = node->type & 0xff;

		switch (type) {
		case MODELNODETYPE_GUNDL:
			rodata = node->rodata;

			if (node != *nodeptr) {
				gdl = rodata->gundl.primary;
			} else if (rodata->gundl.secondary != *gdlptr) {
				gdl = rodata->gundl.secondary;
			}
			break;
		case MODELNODETYPE_DL:
			rodata = node->rodata;

			if (node != *nodeptr) {
				gdl = rodata->dl.primary;
			} else if (rodata->dl.secondary != *gdlptr) {
				gdl = rodata->dl.secondary;
			}
			break;
		case MODELNODETYPE_STARGUNFIRE:
			rodata = node->rodata;

			if (node != *nodeptr) {
				gdl = rodata->stargunfire.gdl;
			}
			break;
		case MODELNODETYPE_DISTANCE:
			rodata = node->rodata;
			node->child = rodata->distance.target;
			break;
		case MODELNODETYPE_TOGGLE:
			rodata = node->rodata;
			node->child = rodata->toggle.target;
			break;
		case MODELNODETYPE_REORDER:
			model0001c868(node, true);
			break;
		}

		if (gdl) {
			break;
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

	*gdlptr = gdl;
	*nodeptr = node;
}

void modelNodeReplaceGdl(struct modelfiledata *modeldef, struct modelnode *node, Gfx *find, Gfx *replacement)
{
	union modelrodata *rodata;
	u32 type = node->type & 0xff;

	switch (type) {
	case MODELNODETYPE_GUNDL:
		rodata = node->rodata;

		if (rodata->gundl.primary == find) {
			rodata->gundl.primary = replacement;
			return;
		}

		if (rodata->gundl.secondary == find) {
			rodata->gundl.secondary = replacement;
			return;
		}
		break;
	case MODELNODETYPE_DL:
		rodata = node->rodata;

		if (rodata->dl.primary == find) {
			rodata->dl.primary = replacement;
			return;
		}

		if (rodata->dl.secondary == find) {
			rodata->dl.secondary = replacement;
			return;
		}
		break;
	case MODELNODETYPE_STARGUNFIRE:
		rodata = node->rodata;

		if (rodata->stargunfire.gdl == find) {
			rodata->stargunfire.gdl = replacement;
			return;
		}
		break;
	}
}
