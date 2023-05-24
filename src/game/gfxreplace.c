#include <ultra64.h>
#include "constants.h"
#include "game/tex.h"
#include "game/bg.h"
#include "game/gfxreplace.h"
#include "bss.h"
#include "lib/vi.h"
#include "data.h"
#include "types.h"

Gfx gbi_26a40[] = {
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_CUSTOM_05, G_CC_PASS2),
	0,
};

Gfx gbi_26a58[] = {
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

Gfx gbi_26b90[] = {
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

Gfx gbi_26c78[] = {
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_06),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_07, G_CC_CUSTOM_07),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_08),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_09, G_CC_CUSTOM_09),
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

Gfx gbi_26d20[] = {
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_06),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineMode(G_CC_CUSTOM_07, G_CC_CUSTOM_07),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_CUSTOM_08),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_CUSTOM_09, G_CC_CUSTOM_09),
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

Gfx gbi_26dc8[] = {
	gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
	0,
};

Gfx gbi_26df0[] = {
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_TERR, G_RM_AA_ZB_OPA_TERR2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_TERR2),
	0,
};

Gfx gbi_26e18[] = {
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
	0,
};

Gfx gbi_26e30[] = {
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_AA_OPA_TERR, G_RM_AA_OPA_TERR2),
	gsDPSetRenderMode(GBL_c1(G_BL_CLR_IN, G_BL_A_SHADE, G_BL_CLR_FOG, G_BL_1MA), G_RM_AA_OPA_TERR2),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
	0,
};

Gfx gbi_26e68[] = {
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

Gfx gbi_26f50[] = {
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

Gfx *var80081018[] = {
	gbi_26a40,
	gbi_26a58,
	gbi_26dc8,
	gbi_26df0,
	gbi_26e18,
	gbi_26b90,
	gbi_26c78,
	gbi_26d20,
	gbi_26e30,
	gbi_26e68,
	gbi_26f50,
};

void gfxReplaceGbiCommands(Gfx *startgdl, Gfx *endgdl, s32 type)
{
	Gfx *gdl = startgdl;

	while ((endgdl && gdl < endgdl) || (!endgdl && *(s8 *)gdl != G_ENDDL)) {
		Gfx *src = var80081018[type];

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
