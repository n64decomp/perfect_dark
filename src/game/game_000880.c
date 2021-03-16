#include <ultra64.h>
#include "constants.h"
#include "game/game_000880.h"
#include "bss.h"
#include "data.h"
#include "types.h"

// These three gfx arrays probably don't belong here,
// but there's no obvious place for them to live.

Gfx var80061360[] = {
	gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
	gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
	gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
	gsSPEndDisplayList(),
};

Gfx var80061380[] = {
	gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
	gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
	gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
	gsSPEndDisplayList(),
};

Gfx var800613a0[] = {
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPPipelineMode(G_PM_1PRIMITIVE),
	gsDPSetTextureLOD(G_TL_TILE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsDPSetTextureDetail(G_TD_CLAMP),
	gsDPSetTexturePersp(G_TP_PERSP),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureConvert(G_TC_FILT),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineKey(G_CK_NONE),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
	gsDPSetColorDither(G_CD_MAGICSQ),
	gsDPSetAlphaDither(G_AD_PATTERN),
	gsDPPipeSync(),
	gsSPEndDisplayList(),
};

void func0f000880(void)
{
	guScale(&var800a3448, 0.1, 0.1, 0.1);
	guScale(&var800a3488, 0.2, 0.2, 0.2);
}
