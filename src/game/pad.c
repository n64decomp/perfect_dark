#include <ultra64.h>
#include "constants.h"
#include "game/pad.h"
#include "bss.h"
#include "data.h"
#include "types.h"

struct padsfileheader *g_PadsFile;
struct pad *g_Pads;
u32 var800a2358;
u32 var800a235c;
u16 *g_CoverFlags;
s32 *g_CoverRooms;
struct covercandidate *g_CoverCandidates;
u16 g_NumSpecialCovers;
u16 *g_SpecialCoverNums;

void padUnpack(s32 padnum, u32 fields, struct pad *pad)
{
	*pad = g_Pads[padnum];
}

bool padHasBboxData(s32 padnum)
{
	return (g_Pads[padnum].flags & PADFLAG_HASBBOXDATA) != 0;
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
	struct coord *up;
	f32 scale;

	if ((g_Pads[padnum].flags & (PADFLAG_UPALIGNTOX | PADFLAG_UPALIGNTOY | PADFLAG_UPALIGNTOZ)) == 0) {
		up = &g_Pads[padnum].up;
		up->y = 0;

		scale = 1 / sqrtf(up->f[0] * up->f[0] + up->f[2] * up->f[2]);

		up->x *= scale;
		up->z *= scale;
	}

	if (g_Pads[padnum].flags & (PADFLAG_LOOKALIGNTOX | PADFLAG_LOOKALIGNTOY | PADFLAG_LOOKALIGNTOZ)) {
		// Unset the LOOKALIGN flags, then set LOOKALIGNTOY
		g_Pads[padnum].flags &= ~PADFLAG_LOOKALIGNTOX;
		g_Pads[padnum].flags &= ~PADFLAG_LOOKALIGNTOZ;
		g_Pads[padnum].flags &= ~PADFLAG_LOOKALIGNINVERT;
		g_Pads[padnum].flags |= PADFLAG_LOOKALIGNTOY;
	} else {
		g_Pads[padnum].look.x = 0.0f;
		g_Pads[padnum].look.y = 1.0f;
		g_Pads[padnum].look.z = 0.0f;
	}
}

void padCopyBboxFromPad(s32 padnum, struct pad *src)
{
	if (g_Pads[padnum].flags & PADFLAG_HASBBOXDATA) {
		g_Pads[padnum].bbox = src->bbox;
	}
}

void padSetFlag(s32 padnum, u32 flag)
{
	g_Pads[padnum].flags |= flag;
}

void padUnsetFlag(s32 padnum, u32 flag)
{
	g_Pads[padnum].flags &= ~flag;
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

void coverSetFlag0001(s32 covernum, bool enable)
{
	if (covernum >= 0 && covernum < g_PadsFile->numcovers) {
		if (enable) {
			g_CoverFlags[covernum] |= COVERFLAG_0001;
		} else {
			g_CoverFlags[covernum] &= ~COVERFLAG_0001;
		}
	}
}

bool coverIsSpecial(struct cover *cover)
{
	return (cover->flags & (COVERFLAG_0080 | COVERFLAG_0040 | COVERFLAG_0020)) != 0;
}

s32 func0f1165c0(s32 arg0, s32 arg1)
{
	return arg0;
}
