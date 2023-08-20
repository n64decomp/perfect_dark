#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

/**
 * This function is not linked in the N64 build. The N64 build appears to use
 * handwritten assembly for this function. The below is functionally equivalent
 * C that can be dropped in place of the handwritten function by linking the
 * different file.
 */
s32 portalConvertCoordinates(s32 portalnum, s32 *start, struct portalthing2 *things)
{
	Mtxf *mtx = g_Vars.currentplayer->worldtoscreenmtx;
	struct portalvertices *pvertices = (struct portalvertices *) ((uintptr_t) g_BgPortals + g_BgPortals[portalnum].verticesoffset);
	struct portalthing2 *left;
	struct portalthing2 *right = &things[39];
	bool anybehind = false;
	s32 i;

	for (i = 0; i < pvertices->count; i++) {
		f32 x = pvertices->vertices[i].x;
		f32 y = pvertices->vertices[i].y;
		f32 z = pvertices->vertices[i].z;

		right->coord.x = mtx->m[0][0] * x + mtx->m[1][0] * y + mtx->m[2][0] * z;
		right->coord.y = mtx->m[0][1] * x + mtx->m[1][1] * y + mtx->m[2][1] * z;
		right->coord.z = mtx->m[0][2] * x + mtx->m[1][2] * y + mtx->m[2][2] * z;

		right->coord.x += mtx->m[3][0];
		right->coord.y += mtx->m[3][1];
		right->coord.z += mtx->m[3][2];

		if (right->coord.z < 0.0f) {
			right->behind = false;
		} else {
			right->behind = true;
			anybehind = true;
		}

		right--;
	}

	if (anybehind) {
		s32 numfinalvertices = 0;

		right->coord.x = things[39].coord.x;
		right->coord.y = things[39].coord.y;
		right->coord.z = things[39].coord.z;
		right->behind = things[39].behind;

		left = &things[0];

		for (i = 0; i < pvertices->count; i++) {
			s32 value = right[1].behind * 2 + right[0].behind;
			f32 mult;

			if (value == 0) {
				left->coord.x = right[1].coord.x;
				left->coord.y = right[1].coord.y;
				left->coord.z = right[1].coord.z;
				left->behind = right[1].behind;
				left++;
				numfinalvertices++;
			} else if (value == 1) {
				left->coord.x = right[1].coord.x;
				left->coord.y = right[1].coord.y;
				left->coord.z = right[1].coord.z;
				left->behind = right[1].behind;
				left++;
				numfinalvertices++;

				mult = -right[0].coord.z / (right[1].coord.z - right[0].coord.z);
				left->coord.x = (right[1].coord.x - right[0].coord.x) * mult + right[0].coord.x;
				left->coord.y = (right[1].coord.y - right[0].coord.y) * mult + right[0].coord.y;
				left->coord.z = 0.0f;
				left++;
				numfinalvertices++;
			} else if (value == 2) {
				mult = -right[0].coord.z / (right[1].coord.z - right[0].coord.z);
				left->coord.x = (right[1].coord.x - right[0].coord.x) * mult + right[0].coord.x;
				left->coord.y = (right[1].coord.y - right[0].coord.y) * mult + right[0].coord.y;
				left->coord.z = 0.0f;
				left++;
				numfinalvertices++;
			}

			right++;
		}

		*start = 0;
		return numfinalvertices;
	}

	*start = 40 - pvertices->count;
	return pvertices->count;
}
