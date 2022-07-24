#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "game/title.h"
#include "lib/vi.h"
#include "lib/dma.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

Mtx *var8009cc80;
Mtx *var8009cc84;
Mtx *var8009cc88;
f32 var8009cc8c;
void *var8009cc90;

u32 var80062410 = 0x00000000;
u8 var80062414 = 3;
u32 var80062418 = 0x00dc0000;
u32 var8006241c = 0x00dc0000;
u32 var80062420 = 0x00ff0000;
u32 var80062424 = 0x00ff0000;
u32 var80062428 = 0x007f0000;
u32 var8006242c = 0x00000000;
u32 var80062430 = 0xdcdcdc00;
u32 var80062434 = 0xdcdcdc00;
u32 var80062438 = 0xffffff00;
u32 var8006243c = 0xffffff00;
u32 var80062440 = 0x007f0000;
u32 var80062444 = 0x00000000;
Lights1 var80062448 = gdSPDefLights1(0xff, 0xff, 0xff, 0, 0, 0, 0, 0, 0);
struct coord g_GetitleCamPos = {0, 0, 4883};
struct coord g_GetitleCamLook = {0, 0, -1};
struct coord g_GetitleCamUp = {0, 1, 0};
f32 var80062484 = 0;
struct coord var80062488 = {1, 0, 0};
u32 var80062494 = 0x00000001;
s32 var80062498 = 0;
u32 var8006249c = 0x00000000;

extern u8 var020043f8;
extern u8 var02004468;
extern u8 var02004700;
extern u8 var02004d28;
extern u8 var02004dc8;
extern u8 var02005dd0;

/**
 * This is a dirty, dirty hack. getitle0f0155f0 only matches if arg2 is a u8.
 * But if arg2 is a u8, the caller casts it which creates a mismatch in the
 * caller. To work around this, we declare a dummy function using u32, then
 * the linker is configured to link the dummy function to the same address as
 * the real one, and we make the caller call the dummy function.
 *
 * @TODO figure out how to fix this properly.
 */
Gfx *getitle0f0155f0_hack(Gfx *gdl, s32 arg1, u32 arg2);

Gfx *getitle0f0155f0(Gfx *gdl, s32 arg1, u8 arg2)
{
	g_GetitleCamPos.z = arg1;

	gSPDisplayList(gdl++, &var80061360);

	if (var80062494) {
		gdl = titleClear(gdl);
		var80062494 = 0;
	} else {
		gDPSetCycleType(gdl++, G_CYC_FILL);
		gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viGetWidth(), osVirtualToPhysical(viGetBackBuffer()));
		gDPSetFillColor(gdl++, 0x00010001);
		gDPFillRectangle(gdl++, 200, 100, 439, 379);
	}

	{
		u16 perspnorm;
		guPerspective(&var8009cc80[var80062410], &perspnorm, 60, 320.0f / 240.0f, 100, 5000, 1);
		gSPPerspNormalize(gdl++, perspnorm);
	}

	gSPMatrix(gdl++, osVirtualToPhysical(&var8009cc80[var80062410]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
	gSPClearGeometryMode(gdl++, 0xffffffff);
	gSPSetGeometryMode(gdl++, G_SHADE | G_CULL_BACK | G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH);

	guLookAt(&var8009cc84[var80062410],
			g_GetitleCamPos.x, g_GetitleCamPos.y, g_GetitleCamPos.z,
			g_GetitleCamLook.x + g_GetitleCamPos.x, g_GetitleCamLook.y + g_GetitleCamPos.y, g_GetitleCamLook.z + g_GetitleCamPos.z,
			g_GetitleCamUp.x, g_GetitleCamUp.y, g_GetitleCamUp.z);

	gSPMatrix(gdl++, osVirtualToPhysical(&var8009cc84[var80062410]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPMatrix(gdl++, osVirtualToPhysical(&var8009cc88[var80062410]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

	gSPSetLights1(gdl++, var80062448);

	{
		struct coord dir = var80062488;

		guNormalize(&dir.x, &dir.y, &dir.z);

		var80062448.a.l.col[0] = 0;
		var80062448.a.l.col[1] = 0;
		var80062448.a.l.col[2] = 0;
		var80062448.a.l.colc[0] = 0;
		var80062448.a.l.colc[1] = 0;
		var80062448.a.l.colc[2] = 0;

		var80062448.l[0].l.col[0] = arg2;
		var80062448.l[0].l.col[1] = arg2;
		var80062448.l[0].l.col[2] = arg2;
		var80062448.l[0].l.colc[0] = var80062448.l[0].l.col[0];
		var80062448.l[0].l.colc[1] = var80062448.l[0].l.col[0];
		var80062448.l[0].l.colc[2] = var80062448.l[0].l.col[0];

		var80062448.l[0].l.dir[0] = (u32)(dir.x * 127.0f);
		var80062448.l[0].l.dir[1] = (u32)(dir.y * 127.0f);
		var80062448.l[0].l.dir[2] = (u32)(dir.z * 127.0f);

		gDPPipeSync(gdl++);
		gDPPipeSync(gdl++);
		gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
		gDPSetTexturePersp(gdl++, G_TP_PERSP);
		gDPSetTextureDetail(gdl++, G_TD_CLAMP);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureLUT(gdl++, G_TT_NONE);
		gDPSetTextureFilter(gdl++, G_TF_BILERP);
		gDPSetTextureConvert(gdl++, G_TC_FILT);
		gDPPipeSync(gdl++);
		gDPPipeSync(gdl++);
		gSPTexture(gdl++, 0x0800, 0x0800, 0, G_TX_RENDERTILE, G_ON);
		gDPLoadTextureBlock(gdl++, &var02004dc8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
		gSPDisplayList(gdl++, &var020043f8);
		gSPDisplayList(gdl++, &var02004468);
		gDPLoadTextureBlock(gdl++, &var02005dd0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
		gSPDisplayList(gdl++, &var02004700);
		gSPDisplayList(gdl++, &var02004d28);
	}

	return gdl;
}

extern u8 _getitleSegmentRomStart;
extern u8 _getitleSegmentStart;
extern u8 _getitleSegmentEnd;

void getitleLoad(void *addr, u32 arg1)
{
	u32 len = (u32)&_getitleSegmentEnd - (u32)&_getitleSegmentStart;

	var80062414 = 0;
	var8009cc8c = 880;
	var80062484 = -40;
	var80062498 = 0;
	var8009cc90 = addr;

	dmaExec(var8009cc90, (u32) &_getitleSegmentRomStart, ALIGN64(len));
}

Gfx *getitleRender(Gfx *gdl)
{
	var80062410 = 1 - var80062410;

	gSPSegment(gdl++, SPSEGMENT_GETITLE, osVirtualToPhysical(var8009cc90));

	if (var80062414 == 0 || var80062414 == 1) {
		s32 sp30;
		s32 sp2c;

		var80062498 += g_Vars.lvupdate240;

		sp30 = (var80062498 * 255) / (PAL ? 233 : 280);

		if (sp30 > 255) {
			sp30 = 255;
		}

		if (sp30 < 0) {
			sp30 = 0;
		}

		sp2c = 255 - (var80062498 * 255 - (PAL ? 135915 : 163200)) / (PAL ? 233 : 280);

		if (sp2c > 255) {
			sp2c = 255;
		}

		if (sp2c < 0) {
			sp2c = 0;
		}

#if PAL
		var80062484 += 2.4f * g_Vars.lvupdate240f;
#else
		var80062484 += g_Vars.lvupdate240f + g_Vars.lvupdate240f;
#endif

		guRotate(&var8009cc88[var80062410], var80062484, 0, 1, 0);

		gdl = getitle0f0155f0_hack(gdl, var8009cc8c, (sp30 * sp2c) / 255);

		if (var80062498 >= TICKS(1040) && var80062498 >= TICKS(1160)) {
			var80062498 = 0;
			var80062414++;
			var80062414++;
		}
	}

	return gdl;
}

bool getitle0f0160e8(void)
{
	return (var80062414 ^ 2) == 0;
}
