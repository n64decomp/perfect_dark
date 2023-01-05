#include <ultra64.h>
#include "constants.h"
#include "game/pad.h"
#include "bss.h"
#include "data.h"
#include "types.h"

struct padsfileheader *g_PadsFile;
u16 *g_PadOffsets;
u32 var800a2358;
u32 var800a235c;
u16 *g_CoverFlags;
s32 *g_CoverRooms;
struct covercandidate *g_CoverCandidates;
u16 g_NumSpecialCovers;
u16 *g_SpecialCoverNums;

void padUnpack(s32 padnum, u32 fields, struct pad *pad)
{
	s32 offset;
	u32 *header;
	f32 *fbuffer;
	u8 *ptr;

	if (pad);

	offset = g_PadOffsets[padnum];
	ptr = (u8 *) &g_StageSetup.padfiledata[offset];
	header = (u32 *) ptr;

	// Header format:
	// flags, room and liftnum
	// ffffffff ffffffff ffrrrrrr rrrrllll

	if (fields & PADFIELD_ROOM) {
		pad->room = (s32)(*header << 18) >> 22;
	}

	if (fields & PADFIELD_LIFT) {
		pad->liftnum = *header & 0x0000000f;
	}

	ptr += 4;

	if ((*header >> 14) & PADFLAG_INTPOS) {
		if (fields & PADFIELD_POS) {
			s16 *sbuffer = (s16 *) ptr;
			pad->pos.x = sbuffer[0];
			pad->pos.y = sbuffer[1];
			pad->pos.z = sbuffer[2];
		}
		ptr += 8;
	} else {
		if (fields & PADFIELD_POS) {
			fbuffer = (f32 *) ptr;
			pad->pos.x = fbuffer[0];
			pad->pos.y = fbuffer[1];
			pad->pos.z = fbuffer[2];
		}
		ptr += 12;
	}

	if ((*header >> 14) & (PADFLAG_UPALIGNTOX | PADFLAG_UPALIGNTOY | PADFLAG_UPALIGNTOZ)) {
		if (fields & (PADFIELD_UP | PADFIELD_NORMAL)) {
			if ((*header >> 14) & PADFLAG_UPALIGNTOX) {
				pad->up.x = ((*header >> 14) & PADFLAG_UPALIGNINVERT) ? -1 : 1;
				pad->up.y = 0;
				pad->up.z = 0;
			} else if ((*header >> 14) & PADFLAG_UPALIGNTOY) {
				pad->up.x = 0;
				pad->up.y = ((*header >> 14) & PADFLAG_UPALIGNINVERT) ? -1 : 1;
				pad->up.z = 0;
			} else {
				pad->up.x = 0;
				pad->up.y = 0;
				pad->up.z = ((*header >> 14) & PADFLAG_UPALIGNINVERT) ? -1 : 1;
			}
		}
	} else {
		if (fields & (PADFIELD_UP | PADFIELD_NORMAL)) {
			fbuffer = (f32 *) ptr;
			pad->up.x = fbuffer[0];
			pad->up.y = fbuffer[1];
			pad->up.z = fbuffer[2];
		}
		ptr += 12;
	}

	if ((*header >> 14) & (PADFLAG_LOOKALIGNTOX | PADFLAG_LOOKALIGNTOY | PADFLAG_LOOKALIGNTOZ)) {
		if (fields & (PADFIELD_LOOK | PADFIELD_NORMAL)) {
			if ((*header >> 14) & PADFLAG_LOOKALIGNTOX) {
				pad->look.x = ((*header >> 14) & PADFLAG_LOOKALIGNINVERT) ? -1 : 1;
				pad->look.y = 0;
				pad->look.z = 0;
			} else if ((*header >> 14) & PADFLAG_LOOKALIGNTOY) {
				pad->look.x = 0;
				pad->look.y = ((*header >> 14) & PADFLAG_LOOKALIGNINVERT) ? -1 : 1;
				pad->look.z = 0;
			} else {
				pad->look.x = 0;
				pad->look.y = 0;
				pad->look.z = ((*header >> 14) & PADFLAG_LOOKALIGNINVERT) ? -1 : 1;
			}
		}
	} else {
		if (fields & (PADFIELD_LOOK | PADFIELD_NORMAL)) {
			fbuffer = (f32 *) ptr;
			pad->look.x = fbuffer[0];
			pad->look.y = fbuffer[1];
			pad->look.z = fbuffer[2];
		}
		ptr += 12;
	}

	if (fields & PADFIELD_NORMAL) {
		pad->normal.x = pad->up.y * pad->look.z - pad->look.y * pad->up.z;
		pad->normal.y = pad->up.z * pad->look.x - pad->look.z * pad->up.x;
		pad->normal.z = pad->up.x * pad->look.y - pad->look.x * pad->up.y;
	}

	if ((*header >> 14) & PADFLAG_HASBBOXDATA) {
		if (fields & PADFIELD_BBOX) {
			fbuffer = (f32 *) ptr;
			pad->bbox.xmin = fbuffer[0];
			pad->bbox.xmax = fbuffer[1];
			pad->bbox.ymin = fbuffer[2];
			pad->bbox.ymax = fbuffer[3];
			pad->bbox.zmin = fbuffer[4];
			pad->bbox.zmax = fbuffer[5];
		}
		ptr += 4 * 6;
	} else {
		if (fields & PADFIELD_BBOX) {
			pad->bbox.xmin = -100;
			pad->bbox.ymin = -100;
			pad->bbox.zmin = -100;
			pad->bbox.xmax = 100;
			pad->bbox.ymax = 100;
			pad->bbox.zmax = 100;
		}
	}

	if (fields & PADFIELD_FLAGS) {
		pad->flags = (*header >> 14);
	}
}

bool padHasBboxData(s32 padnum)
{
	u32 offset = g_PadOffsets[padnum];
	u32 *header = (u32 *)&g_StageSetup.padfiledata[offset];

	return ((*header >> 14) & PADFLAG_HASBBOXDATA) != 0;
}

void padGetCentre(s32 padnum, struct coord *coord)
{
	struct pad pad;

	padUnpack(padnum, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP | PADFIELD_NORMAL | PADFIELD_BBOX, &pad);

	coord->x = pad.pos.f[0] + (
			(pad.bbox.xmin + pad.bbox.xmax) * pad.normal.f[0] +
			(pad.bbox.ymin + pad.bbox.ymax) * pad.up.f[0] +
			(pad.bbox.zmin + pad.bbox.zmax) * pad.look.f[0]) * 0.5f;

	coord->y = pad.pos.f[1] + (
			(pad.bbox.xmin + pad.bbox.xmax) * pad.normal.f[1] +
			(pad.bbox.ymin + pad.bbox.ymax) * pad.up.f[1] +
			(pad.bbox.zmin + pad.bbox.zmax) * pad.look.f[1]) * 0.5f;

	coord->z = pad.pos.f[2] + (
			(pad.bbox.xmin + pad.bbox.xmax) * pad.normal.f[2] +
			(pad.bbox.ymin + pad.bbox.ymax) * pad.up.f[2] +
			(pad.bbox.zmin + pad.bbox.zmax) * pad.look.f[2]) * 0.5f;
}

/**
 * Some door models are rotated weirdly - suspected to be designed using the
 * wrong coordinate system, then the developers implemented a fix here in the
 * code rather than fixing the models.
 *
 * When such a door is placed on a pad, this function is called. It adjusts the
 * pad's orientation to compensate for the model.
 */
void padRotateForDoor(s32 padnum)
{
	u32 stack;
	u32 *ptr;
	u32 *header;
	struct coord *look;
	struct coord *up;
	f32 scale;
	s32 offset;

	offset = g_PadOffsets[padnum];
	ptr = (u32 *) &g_StageSetup.padfiledata[offset];
	header = ptr;

	ptr++;

	if ((*header >> 14) & PADFLAG_INTPOS) {
		ptr += 2;
	} else {
		ptr += 3;
	}

	if (((*header >> 14) & (PADFLAG_UPALIGNTOX | PADFLAG_UPALIGNTOY | PADFLAG_UPALIGNTOZ)) == 0) {
		up = (struct coord *) ptr;
		up->y = 0;

		scale = 1 / sqrtf(up->f[0] * up->f[0] + up->f[2] * up->f[2]);

		up->x *= scale;
		up->z *= scale;

		ptr += 3;
	}

	if ((*header >> 14) & (PADFLAG_LOOKALIGNTOX | PADFLAG_LOOKALIGNTOY | PADFLAG_LOOKALIGNTOZ)) {
		// Unset the LOOKALIGN flags, then set LOOKALIGNTOY
		*header = *header ^ (((*header >> 14) ^ ((*header >> 14) & ~(PADFLAG_LOOKALIGNTOX | PADFLAG_LOOKALIGNTOY | PADFLAG_LOOKALIGNTOZ | PADFLAG_LOOKALIGNINVERT))) << 14);
		*header = *header ^ (((*header >> 14) ^ ((*header >> 14) | PADFLAG_LOOKALIGNTOY)) << 14);
	} else {
		look = (struct coord *) ptr;

		look->x = 0.0f;
		look->y = 1.0f;
		look->z = 0.0f;
	}
}

void padCopyBboxFromPad(s32 padnum, struct pad *src)
{
	u32 offset = g_PadOffsets[padnum];
	f32 *fbuffer = (f32 *)&g_StageSetup.padfiledata[offset];
	u32 *header = (u32 *)fbuffer;

	if ((*header >> 14) & PADFLAG_HASBBOXDATA) {
		fbuffer++;

		if ((*header >> 14) & PADFLAG_INTPOS) {
			fbuffer += 2;
		} else {
			fbuffer += 3;
		}

		if (((*header >> 14) & (PADFLAG_UPALIGNTOX | PADFLAG_UPALIGNTOY | PADFLAG_UPALIGNTOZ)) == 0) {
			fbuffer += 3;
		}

		if (((*header >> 14) & (PADFLAG_LOOKALIGNTOX | PADFLAG_LOOKALIGNTOY | PADFLAG_LOOKALIGNTOZ)) == 0) {
			fbuffer += 3;
		}

		fbuffer[0] = src->bbox.xmin;
		fbuffer[1] = src->bbox.xmax;
		fbuffer[2] = src->bbox.ymin;
		fbuffer[3] = src->bbox.ymax;
		fbuffer[4] = src->bbox.zmin;
		fbuffer[5] = src->bbox.zmax;
	}
}

void padSetFlag(s32 padnum, u32 flag)
{
	u32 offset = g_PadOffsets[padnum];
	u32 *header = (u32 *)&g_StageSetup.padfiledata[offset];

	*header = *header ^ ((*header >> 14) ^ ((*header >> 14) | flag)) << 14;
}

void padUnsetFlag(s32 padnum, u32 flag)
{
	u32 offset = g_PadOffsets[padnum];
	u32 *header = (u32 *)&g_StageSetup.padfiledata[offset];

	*header = *header ^ ((*header >> 14) ^ ((*header >> 14) & ~flag)) << 14;
}

bool func0f1162c4(s32 padnum, s32 arg1)
{
	return padnum;
}

s32 coverGetCount(void)
{
	return g_PadsFile->numcovers;
}

bool coverUnpack(s32 covernum, struct cover *cover)
{
	struct coverdefinition *def;

	if (covernum >= g_PadsFile->numcovers || covernum < 0 || !g_StageSetup.cover) {
		return false;
	}

	// @bug: Cast to u8 means it loads the pos, look and flags
	// from an incorrect cover if covernum is greater than 255.
	def = g_StageSetup.cover;
	def += (u8)covernum;

	cover->pos = &def->pos;
	cover->look = &def->look;

	g_CoverFlags[covernum] |= def->flags;

	cover->flags = g_CoverFlags[covernum];
	cover->rooms[0] = g_CoverRooms[covernum];
	cover->rooms[1] = -1;

	return true;
}

u16 getNumSpecialCovers(void)
{
	return g_NumSpecialCovers;
}

bool coverUnpackBySpecialNum(s32 index, struct cover *cover)
{
	// Probable @bug: last check should be index >= g_NumSpecialCovers
	// This function is never called though.
	if (!g_SpecialCoverNums || index < 0 || index > g_NumSpecialCovers) {
		return false;
	}

	if (coverUnpack(g_SpecialCoverNums[index], cover)) {
		return true;
	}

	return false;
}

s32 coverGetNumBySpecialNum(s32 index)
{
	// Probable @bug: last check should be index >= g_NumSpecialCovers
	// This function is never called though.
	if (!g_SpecialCoverNums || index < 0 || index > g_NumSpecialCovers) {
		return -1;
	}

	return g_SpecialCoverNums[index];
}

s32 func0f116450(s32 arg0, s32 arg1)
{
	return arg0;
}

bool coverIsInUse(s32 covernum)
{
	// @bug: Second condition should be >=
	if (covernum < 0 || covernum > g_PadsFile->numcovers) {
		return false;
	}

	return g_CoverFlags[covernum] & COVERFLAG_INUSE;
}

void coverSetInUse(s32 covernum, bool enable)
{
	if (covernum >= 0 && covernum < g_PadsFile->numcovers) {
		if (enable) {
			g_CoverFlags[covernum] |= COVERFLAG_INUSE;
		} else {
			g_CoverFlags[covernum] &= ~COVERFLAG_INUSE;
		}
	}
}

void coverSetFlag(s32 covernum, u32 flag)
{
	g_CoverFlags[covernum] |= flag;
}

void coverUnsetFlag(s32 covernum, u32 flag)
{
	g_CoverFlags[covernum] &= ~flag;
}

void coverSetOutOfSight(s32 covernum, bool enable)
{
	if (covernum >= 0 && covernum < g_PadsFile->numcovers) {
		if (enable) {
			g_CoverFlags[covernum] |= COVERFLAG_OUTOFSIGHT;
		} else {
			g_CoverFlags[covernum] &= ~COVERFLAG_OUTOFSIGHT;
		}
	}
}

bool coverIsSpecial(struct cover *cover)
{
	return (cover->flags & (COVERFLAG_SPECIAL1 | COVERFLAG_SPECIAL2 | COVERFLAG_SPECIAL3)) != 0;
}

s32 func0f1165c0(s32 arg0, s32 arg1)
{
	return arg0;
}
