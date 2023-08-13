#include <ultra64.h>
#include "constants.h"
#include "game/gfxreplace.h"
#include "bss.h"
#include "data.h"
#include "types.h"

/**
 * When loading rooms, the game can scan the room's displaylists find/replace
 * GBI commands.
 *
 * Each pair of elements in these groups are find/replace pairs.
 */

/**
 * Unused.
 */
Gfx g_GfxGroup00[] = {
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_CUSTOM_05, G_CC_PASS2),
	0,
};

/**
 * Enable fog (opaque displaylist)
 */
Gfx g_GfxGroup01[] = {
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_TERR2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_TERR2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_DECAL2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_DECAL2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_DECAL2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_OPA_SURF2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_OPA_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_OPA_TERR2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_OPA_TERR2),

	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_06),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_07, G_CC_CUSTOM_07),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_08),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_09, G_CC_CUSTOM_09),

	// This is a duplicate of the previous block
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_06),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_07, G_CC_CUSTOM_07),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_08),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_09, G_CC_CUSTOM_09),

	gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
	gsDPSetCombineMode(G_CC_CUSTOM_10, G_CC_PASS2),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineMode(G_CC_CUSTOM_10, G_CC_CUSTOM_10),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_CUSTOM_06),
	0,
};

/**
 * Enable fog (translucent displaylist)
 */
Gfx g_GfxGroup05[] = {
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_DECAL2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),

	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_06),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_07, G_CC_CUSTOM_07),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_08),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_09, G_CC_CUSTOM_09),

	// This is a duplicate of the previous block
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_06),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_07, G_CC_CUSTOM_07),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_08),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_09, G_CC_CUSTOM_09),

	gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
	gsDPSetCombineMode(G_CC_CUSTOM_10, G_CC_PASS2),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineMode(G_CC_CUSTOM_10, G_CC_CUSTOM_10),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_CUSTOM_06),
	0,
};

/**
 * Disable transparency effects (opaque displaylist).
 *
 * These are replacing SHADE with ENVIRONMENT in the alpha half of each mode.
 *
 * The source GBI commands use alpha transparency. The environment settings for
 * each stage determines whether they should be preserved or disabled.
 */
Gfx g_GfxGroup06[] = {
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_06),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_07, G_CC_CUSTOM_07),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_08),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_09, G_CC_CUSTOM_09),

	// This is a duplicate of the previous block
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_06),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_07, G_CC_CUSTOM_07),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_08),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_09, G_CC_CUSTOM_09),

	gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
	gsDPSetCombineMode(G_CC_CUSTOM_10, G_CC_PASS2),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineMode(G_CC_CUSTOM_10, G_CC_CUSTOM_10),
	0,
};

/**
 * Disable transparency effects (translucent displaylist).
 */
Gfx g_GfxGroup07[] = {
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_06),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_07, G_CC_CUSTOM_07),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_08),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_09, G_CC_CUSTOM_09),

	// This is a duplicate of the previous block
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_06),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_07, G_CC_CUSTOM_07),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_08),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_09, G_CC_CUSTOM_09),

	gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
	gsDPSetCombineMode(G_CC_CUSTOM_10, G_CC_PASS2),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineMode(G_CC_CUSTOM_10, G_CC_CUSTOM_10),
	0,
};

/**
 * Unused.
 */
Gfx g_GfxGroup02[] = {
	gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
	0,
};

/**
 * Unused.
 */
Gfx g_GfxGroup03[] = {
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_TERR, G_RM_AA_ZB_OPA_TERR2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_TERR2),
	0,
};

/**
 * Unused.
 */
Gfx g_GfxGroup04[] = {
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
	0,
};

/**
 * Unused.
 */
Gfx g_GfxGroup08[] = {
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_AA_OPA_TERR, G_RM_AA_OPA_TERR2),
	gsDPSetRenderMode(GBL_c1(G_BL_CLR_IN, G_BL_A_SHADE, G_BL_CLR_FOG, G_BL_1MA), G_RM_AA_OPA_TERR2),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
	0,
};

/**
 * Unused.
 */
Gfx g_GfxGroup09[] = {
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_12, G_CC_CUSTOM_12),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_13, G_CC_CUSTOM_13),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_12, G_CC_CUSTOM_12),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_13, G_CC_CUSTOM_13),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineMode(G_CC_CUSTOM_14, G_CC_CUSTOM_14),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_15),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_16),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_15),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_16),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_CUSTOM_15),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_CUSTOM_16),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_CUSTOM_15),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_CUSTOM_16),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
	gsDPSetCombineMode(G_CC_CUSTOM_14, G_CC_PASS2),
	0,
};

/**
 * Reverse of g_GfxGroup09.
 *
 * Unused.
 */
Gfx g_GfxGroup10[] = {
	gsDPSetCombineMode(G_CC_CUSTOM_12, G_CC_CUSTOM_12),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_13, G_CC_CUSTOM_13),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_12, G_CC_CUSTOM_12),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_13, G_CC_CUSTOM_13),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_14, G_CC_CUSTOM_14),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_15),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_16),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_15),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_16),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_CUSTOM_15),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_CUSTOM_16),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_CUSTOM_15),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_CUSTOM_16),
	gsDPSetCombineMode(G_CC_CUSTOM_11, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_CUSTOM_14, G_CC_PASS2),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
	0,
};

void gfxReplaceGbiCommands(Gfx *startgdl, Gfx *endgdl, s32 type)
{
	static Gfx *groups[] = {
		g_GfxGroup00,
		g_GfxGroup01,
		g_GfxGroup02,
		g_GfxGroup03,
		g_GfxGroup04,
		g_GfxGroup05,
		g_GfxGroup06,
		g_GfxGroup07,
		g_GfxGroup08,
		g_GfxGroup09,
		g_GfxGroup10,
	};

	Gfx *gdl = startgdl;

#ifdef PLATFORM_N64
	while ((endgdl && gdl < endgdl) || (!endgdl && *(s8 *)gdl != G_ENDDL)) {
#else
	while ((endgdl && gdl < endgdl) || (!endgdl && (s8)gdl->bytes[GFX_W0_BYTE(0)] != G_ENDDL)) {
#endif
		Gfx *src = groups[type];

		while (src->words.w0 != 0) {
			if (src->words.w0 == gdl->words.w0 && src->words.w1 == gdl->words.w1) {
				*gdl = src[1];
			}

			src += 2;
		}

		gdl++;
	}
}

void gfxReplaceGbiCommandsRecursively(struct roomblock *block, s32 type)
{
	if (block->type == ROOMBLOCKTYPE_PARENT);

	while (true) {
		if (!block) {
			return;
		}

		switch (block->type) {
		case ROOMBLOCKTYPE_LEAF:
			gfxReplaceGbiCommands(block->gdl, NULL, type);
			block = block->next;
			break;
		case ROOMBLOCKTYPE_PARENT:
			gfxReplaceGbiCommandsRecursively(block->child, type);
			block = block->next;
			break;
		default:
			return;
		}
	}
}
