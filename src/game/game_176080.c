#include <ultra64.h>
#include "constants.h"
#include "lib/sched.h"
#include "game/player.h"
#include "game/game_176080.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

u32 var800ab7c0;
u32 var800ab7c4;
u16 var800ab7c8[0x180];
u16 var800abac8[0x180];
u16 var800abdc8[0x180];

u16 *var800844f0 = NULL;
void *var800844f4 = NULL;

static void mblurAllocate(void);

void *mblurGetAllocation(void)
{
	return var800844f0;
}

void mblurReset(s32 stagenum)
{
	var800844f0 = 0;
	var800844f4 = 0;

	if (stagenum != STAGE_TITLE) {
		mblurAllocate();
	}
}

static void mblurAllocate(void)
{
	var800ab7c0 = 640;

	if (g_Vars.normmplayerisrunning && PLAYERCOUNT() >= 2) {
		var800ab7c4 = 220;
	} else {
		var800ab7c4 = 220;
	}

	var800844f0 = mempAlloc(var800ab7c0 * var800ab7c4 * 2 + 0x40, MEMPOOL_STAGE);
	var800844f0 = (void *)(((u32) var800844f0 + 0x3f) & ~0x3f);
	var800844f4 = var800844f0;
}

void mblur0f176298(void)
{
	var800844f4 = var800844f0;
}

Gfx *mblur0f1762ac(Gfx *gdl)
{
	u32 subamount;
	u32 addr;

	if (g_Vars.normmplayerisrunning
			&& (g_Vars.currentplayernum >= 2 || (PLAYERCOUNT() == 2 && g_Vars.currentplayernum == 1))) {
		subamount = playerGetFbWidth() * playerGetFbHeight();

		if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
			subamount = 0;
		}
	} else {
		subamount = 0;
	}

	addr = (u32)var800844f4 - subamount;
	addr &= ~0x3f;

	gDPPipeSync(gdl++);
	gDPSetDepthImage(gdl++, addr);

	return gdl;
}

Gfx *mblur0f1763f4(Gfx *gdl)
{
	s32 left;
	s32 right;

	gDPPipeSync(gdl++);
	gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
	gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viGetWidth(), OS_PHYSICAL_TO_K0(var800844f4));
	gDPSetCycleType(gdl++, G_CYC_FILL);
	gDPSetFillColor(gdl++, 0xfffcfffc);
	gDPSetScissorFrac(gdl++, G_SC_NON_INTERLACE, 0, 0, playerGetFbWidth() * 4.0f, playerGetFbHeight() * 4.0f);

	if (PLAYERCOUNT() <= 2) {
		left = 0;
		right = playerGetFbWidth() - 1;
	} else if (g_Vars.currentplayernum == 0 || g_Vars.currentplayernum == 2) {
		left = 0;
		right = playerGetFbWidth() / 2 - 1;
	} else {
		left = playerGetFbWidth() / 2;
		right = playerGetFbWidth() - 1;
	}

	gDPFillRectangle(gdl++, left, 0, right, playerGetFbHeight() - 1);
	gDPPipeSync(gdl++);

	return gdl;
}

static u16 *mblur0f176668(s32 arg0)
{
	u16 *addr;

	if (arg0 == 0) {
		addr = var800ab7c8;
	}

	if (arg0 == 1) {
		addr = var800abac8;
	}

	if (arg0 == 2) {
		addr = var800abdc8;
	}

	addr = (u16 *)(((u32)addr + 0x3f) & ~0x3f);

	return addr;
}

Gfx *mblurRender(Gfx *gdl)
{
	struct artifact *artifacts = g_ArtifactLists[g_SchedWriteArtifactsIndex];
	u32 stack;
	u16 *sp4c = var800844f0;
	u32 s4 = 0;
	u16 *sp44;
	u16 *s2;
	u16 *image;
	s32 i;

	viGetBackBuffer();
	sp44 = mblur0f176668(g_SchedWriteArtifactsIndex);
	g_SchedSpecialArtifactIndexes[g_SchedWriteArtifactsIndex] = 1;

	gDPPipeSync(gdl++);
	gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viGetBufWidth(), OS_PHYSICAL_TO_K0(sp44));
	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
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
	gDPTileSync(gdl++);

	for (i = 0; i < MAX_ARTIFACTS; i++) {
		if (1);

		if (artifacts[i].type != ARTIFACTTYPE_FREE) {
			s2 = &sp44[s4];
			image = &sp4c[artifacts[i].unk0c.u16_1 * viGetWidth()];

			gDPPipeSync(gdl++);
			gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, image);
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, 5, 0, 0, viGetWidth() - 1, 0);
			gDPPipeSync(gdl++);

			gSPTextureRectangle(gdl++,
					s4 << 2, 0,
					(s4 + 3) << 2, 0,
					G_TX_RENDERTILE, (artifacts[i].unk0c.u16_2 * 32) + 16, 0x0010, 0x1000, 0);

			artifacts[i].unk0c.u16p = s2;
			s4++;

			if (s2);
		}
	}

	gDPPipeSync(gdl++);
	gDPLoadSync(gdl++);
	gDPTileSync(gdl++);
	gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viGetBufWidth(), OS_PHYSICAL_TO_K0(viGetBackBuffer()));
	gDPSetScissorFrac(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetWidth() * 4.0f, viGetHeight() * 4.0f);
	gSPSetGeometryMode(gdl++, G_ZBUFFER);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);
	gDPSetColorDither(gdl++, G_CD_BAYER);

	if (sp44);

	return gdl;
}
