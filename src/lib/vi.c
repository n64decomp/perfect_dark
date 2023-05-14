#include <ultra64.h>
#include "constants.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/file.h"
#include "game/game_176080.h"
#include "game/gfxmemory.h"
#include "game/options.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/memp.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

#define TO_U16_A(x) ((u16)(x))
#define TO_U16_B(x) ((x) & 0xffff)
#define TO_U16_C(x) ((u16)((x) & 0xffff))

#define ADD_LOW_AND_HI_16_TRUNCATE(reg, add) ((TO_U16_B(TO_U16_A((reg) >> 16) + (add)) << 16) | TO_U16_B(TO_U16_A(reg) + (add)))
#define ADD_LOW_AND_HI_16_MOD(reg, add)      ((((((reg >> 16) & 0xffff) + (add)) % 0xffff) << 16) | (((((reg >> 0) & 0xffff) + (add)) % 0xffff) << 0))

Mtxf var80092830;
Mtx *var80092870;
u16 g_ViPerspScale;
u8 g_ViFrontIndex;
u8 g_ViBackIndex;
u16 *g_FrameBuffers[3];

struct rend_vidat g_ViDataArray[] = {
	{
		0, 0, 0, 0,
		320, 220,         // x and y
		60,               // fovy
		1.4545454978943f, // aspect
		30,               // znear
		10000,            // zfar
		320, 220,         // bufx and bufy
		320, 220,         // viewx and viewy
		0, 0,             // viewleft and viewtop
		true,             // usezbuf
		0,
	}, {
		0, 0, 0, 0,
		320, 220,         // x and y
		60,               // fovy
		1.4545454978943f, // aspect
		30,               // znear
		10000,            // zfar
		320, 220,         // bufx and bufy
		320, 220,         // viewx and viewy
		0, 0,             // viewleft and viewtop
		true,             // usezbuf
		0,
	}, {
		0, 0, 0, 0,
		320, 220,         // x and y
		60,               // fovy
		1.4545454978943f, // aspect
		30,               // znear
		10000,            // zfar
		320, 220,         // bufx and bufy
		320, 220,         // viewx and viewy
		0, 0,             // viewleft and viewtop
		true,             // usezbuf
		0,
	},
};

s32 var8005d588 = 0;
s32 var8005d58c = 0;
struct rend_vidat *g_ViFrontData = &g_ViDataArray[0];
struct rend_vidat *g_ViBackData = &g_ViDataArray[0];
bool g_ViReconfigured = false;
s32 g_ViSlot = 0;

void viConfigureForLogos(void)
{
	g_ViFrontIndex = 0;
	g_ViBackIndex = 1;

	g_ViFrontData = g_ViDataArray + g_ViFrontIndex;
	g_ViBackData = g_ViDataArray + g_ViBackIndex;

	var8005d588 = 0;
	var8005d58c = 0;
}

/**
 * Configure the VI to display the copyright or accessingpak texture.
 *
 * The texture is the first thing displayed after power on.
 *
 * Both textures are 507 x 48, but the framebuffer width is 576.
 */
void viConfigureForCopyright(u16 *texturedata)
{
	s32 i;

	for (i = 0; i < 3; i++) {
		g_FrameBuffers[i] = texturedata;

		g_ViDataArray[i].x = 576;
		g_ViDataArray[i].bufx = 576;
		g_ViDataArray[i].viewx = 576;

		g_ViDataArray[i].y = 48;
		g_ViDataArray[i].bufy = 48;
		g_ViDataArray[i].viewy = 48;
	}

	g_ViFrontData->fb = g_FrameBuffers[g_ViFrontIndex];
	g_ViBackData->fb = g_FrameBuffers[g_ViBackIndex];

	g_ViReconfigured = true;
}

/**
 * Configure the VI to display the legal screen.
 *
 * It's also used for the "check controllers" message
 * if controller 1 is not connected.
 */
void viConfigureForLegal(void)
{
	s32 i;

	for (i = 0; i < 3; i++) {
		g_ViDataArray[i].x = 320;
		g_ViDataArray[i].bufx = 320;
		g_ViDataArray[i].viewx = 320;

		g_ViDataArray[i].y = 220;
		g_ViDataArray[i].bufy = 220;
		g_ViDataArray[i].viewy = 220;
	}

#if PAL
	playerResetLoResIf4Mb();
#endif
}

const s16 g_ViModeWidths[] = {320, 320, 640};

#if PAL
const s16 g_ViModeHeights[] = {220, 220, 504};
#else
const s16 g_ViModeHeights[] = {220, 220, 440};
#endif

/**
 * Allocate the colour framebuffers for the given stage.
 *
 * Regardless of whether hi-res is being used or not, the buffers are allocated
 * for hi-res. This is because hi-res can be changed mid-stage, and the engine
 * cannot reallocate the frame buffer without clearing the stage's entire memory
 * pool.
 *
 * The same is probably true for wide and cinema modes.
 */
void viReset(s32 stagenum)
{
	s32 i;
	s32 fbsize;
	u8 *ptr;
	u8 *fb0;
	u8 *fb1;
	u8 *fb2;

	if (stagenum == STAGE_TITLE) {
		viSetMode(VIMODE_HI);
		fbsize = g_ViModeWidths[2] * g_ViModeHeights[2] * 2;

		ptr = mempAlloc(fbsize * 3 + 0x40, MEMPOOL_STAGE);
		ptr = (u8 *)(((u32)ptr + 0x3f) & 0xffffffc0);

		g_FrameBuffers[0] = (u16 *) ptr;
		g_FrameBuffers[1] = (u16 *) (ptr + fbsize);
		g_FrameBuffers[2] = (u16 *) (ptr + fbsize * 2);
	} else {
		viSetMode(VIMODE_LO);
		fbsize = FRAMEBUFFER_SIZE;

		g_FrameBuffers[0] = (void *) (0x80400000 - fbsize);
		g_FrameBuffers[1] = (void *) (0x80400000);
		g_FrameBuffers[2] = (void *) (0x80800000 - fbsize);
	}

	g_ViFrontData->fb = g_FrameBuffers[g_ViFrontIndex];
	g_ViBackData->fb = g_FrameBuffers[g_ViBackIndex];

	fb0 = (u8 *) g_FrameBuffers[0];
	fb1 = (u8 *) g_FrameBuffers[1];
	fb2 = (u8 *) g_FrameBuffers[2];

	for (i = 0; i < fbsize; i++) {
		fb0[i] = 0;
		fb1[i] = 0;
		fb2[i] = 0;
	}

	g_ViReconfigured = true;
}

/**
 * If black is true, set the video output to black indefinitely.
 * g_ViUnblackTimer is set to 3 which causes the timer to be paused.
 *
 * If black is false, set the timer to 2. This causes it to tick down once per
 * frame and unblack once it reaches 0.
 */
void viBlack(bool black)
{
	black += 3;
	g_ViUnblackTimer = black;
}

void vi00009ed4(void)
{
	s32 prevmask;
	s32 offset;
	s32 reg;
	u32 features;

	if (g_ViShakeTimer != 0) {
		g_ViShakeTimer--;

		if (g_ViShakeTimer == 0) {
			g_ViShakeIntensity = 0;
		}
	}

	offset = g_ViShakeDirection * g_ViShakeIntensity;
	g_ViShakeDirection = -g_ViShakeDirection;

	prevmask = osSetIntMask(1);

	reg = var8008de0c;
	var8008dd60[1 - var8005ce74]->fldRegs[0].vStart = ADD_LOW_AND_HI_16_TRUNCATE(reg, offset);

	reg = var8008de10;
	var8008dd60[1 - var8005ce74]->fldRegs[1].vStart = ADD_LOW_AND_HI_16_TRUNCATE(reg, offset);

	osSetIntMask(prevmask);

	osViSetMode(var8008dd60[1 - var8005ce74]);
	osViBlack(g_ViUnblackTimer);
	osViSetXScale(g_ViXScalesBySlot[1 - var8005ce74]);
	osViSetYScale(g_ViYScalesBySlot[1 - var8005ce74]);

#ifdef ANTIALIAS
	osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_DITHER_FILTER_ON);
#else
	osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_DITHER_FILTER_OFF);
#endif
}

void viUpdateMode(void)
{
	struct rend_vidat *prevdata;
	f32 x;
	f32 y;
	s32 reg;
	s32 v1;
	s32 tmp;

	if (g_ViBackData->mode != g_ViFrontData->mode) {
		switch (g_ViBackData->mode) {
		case 0:
			osViSetYScale(1);
			osViBlack(true);
			break;
		case 1:
			break;
		case 2:
			break;
		}
	}

	x = (f32)g_ViBackData->x / (f32)g_ViBackData->bufx;
	y = (f32)g_ViBackData->y / (f32)g_ViBackData->bufy;

	if (g_ViBackData->mode == VIMODE_NONE) {
		y = 1;
	}

	g_ViXScalesBySlot[g_ViSlot] = x;
	g_ViYScalesBySlot[g_ViSlot] = y;

	// 12c
	if (g_ViBackData->mode == VIMODE_LO) {
		if (osTvType == OS_TV_MPAL) {
			var8008dcc0[g_ViSlot] = osViModeTable[OS_VI_MPAL_LAN1];
		} else {
			var8008dcc0[g_ViSlot] = osViModeTable[OS_VI_NTSC_LAN1];
		}

		var8008dcc0[g_ViSlot].comRegs.width = g_ViBackData->bufx;
		var8008dcc0[g_ViSlot].comRegs.xScale = g_ViBackData->bufx * 1024 / 640;
		var8008dcc0[g_ViSlot].fldRegs[0].origin = g_ViBackData->bufx * 2;
		var8008dcc0[g_ViSlot].fldRegs[1].origin = g_ViBackData->bufx * 2;

		// 324
		var8008dcc0[g_ViSlot].fldRegs[0].yScale = g_ViBackData->bufy * 2048 / 440;
		var8008dcc0[g_ViSlot].fldRegs[1].yScale = g_ViBackData->bufy * 2048 / 440;

		// 3ac
		reg = var8008dcc0[g_ViSlot].comRegs.hStart;
		reg = ADD_LOW_AND_HI_16_MOD(reg, var8005d588);
		var8008dcc0[g_ViSlot].comRegs.hStart = reg;
		var8008dcc0[g_ViSlot].fldRegs[0].vStart = reg;
		var8008dcc0[g_ViSlot].fldRegs[1].vStart = reg;

		v1 = g_ViBackData->bufy * 1024 / var8008dcc0[g_ViSlot].fldRegs[0].yScale;

		// 458
		if (v1 > 300) {
			v1 >>= 1;
		}

		tmp = 277 - v1;
		reg = ((tmp + 2) << 16) | (tmp + ((v1 - 2) * 2) + 2);
		reg = ADD_LOW_AND_HI_16_MOD(reg, var8005d58c);
		var8008de0c = reg;
		var8008de10 = reg;

		g_SchedViModesPending[g_ViSlot] = true;
	} else /*534*/ if (g_ViBackData->mode == VIMODE_HI) {
		if (osTvType == OS_TV_MPAL) {
			var8008dcc0[g_ViSlot] = osViModeTable[OS_VI_MPAL_HAF1];
		} else {
			var8008dcc0[g_ViSlot] = osViModeTable[OS_VI_NTSC_HAF1];
		}

		var8008dcc0[g_ViSlot].comRegs.width = g_ViBackData->bufx;
		var8008dcc0[g_ViSlot].comRegs.xScale = g_ViBackData->bufx * 1024 / 640;
		var8008dcc0[g_ViSlot].fldRegs[0].yScale = 2048;
		var8008dcc0[g_ViSlot].fldRegs[1].yScale = 2048;
		var8008dcc0[g_ViSlot].fldRegs[0].origin = g_ViBackData->bufx * 2;
		var8008dcc0[g_ViSlot].fldRegs[1].origin = g_ViBackData->bufx * 4;

		reg = var8008dcc0[g_ViSlot].comRegs.hStart;
		reg = ADD_LOW_AND_HI_16_MOD(reg, var8005d588);
		var8008dcc0[g_ViSlot].comRegs.hStart = reg;

		reg = var8008dcc0[g_ViSlot].fldRegs[0].vStart;
		reg = ADD_LOW_AND_HI_16_MOD(reg, var8005d58c);
		var8008dcc0[g_ViSlot].fldRegs[0].vStart = reg;
		var8008de0c = reg;

		reg = var8008dcc0[g_ViSlot].fldRegs[1].vStart;
		reg = ADD_LOW_AND_HI_16_MOD(reg, var8005d58c);
		var8008dcc0[g_ViSlot].fldRegs[1].vStart = reg;
		var8008de10 = reg;

		// 7f8
		if (var8005dd18) {
			reg = var8005d58c;
			reg = (reg + 431) % 0xffff << 16 | (reg + 123) % 0xffff;
			var8008dcc0[g_ViSlot].fldRegs[0].vStart = reg;
			var8008de0c = reg;

			reg = var8005d58c;
			reg = (reg + 433) % 0xffff << 16 | (reg + 121) % 0xffff;
			var8008dcc0[g_ViSlot].fldRegs[1].vStart = reg;
			var8008de10 = reg;
		}

		g_SchedViModesPending[g_ViSlot] = true;
	} else {
		// 8f4
		g_SchedViModesPending[g_ViSlot] = false;
	}

	// 908
	g_ViSlot = (g_ViSlot + 1) % 2;

	g_RdpCurTask->framebuffer = g_ViBackData->fb;

	prevdata = g_ViBackData;

	g_ViFrontIndex++;
	g_ViBackIndex++;

	WRAP(g_ViFrontIndex, 3);
	WRAP(g_ViBackIndex, 3);

	g_ViFrontData = g_ViDataArray + g_ViFrontIndex;
	g_ViBackData = g_ViDataArray + g_ViBackIndex;

	bcopy(prevdata, g_ViBackData, sizeof(struct rend_vidat));

	g_ViBackData->fb = g_FrameBuffers[g_ViBackIndex];

	if (g_ViReconfigured) {
		g_ViReconfigured = false;
		viBlack(false);
	}
}

void viShake(f32 intensity)
{
	if (intensity > 14) {
		intensity = 14;
	}

	if (intensity < 0) {
		intensity = 0;
	}

	g_ViShakeIntensity = intensity;
	g_ViShakeTimer = 10;
}

void viSetMode(s32 mode)
{
	g_ViBackData->mode = mode;

	g_ViBackData->x = g_ViBackData->bufx = g_ViModeWidths[mode];
	g_ViBackData->y = g_ViBackData->bufy = g_ViModeHeights[mode];
}

Gfx *vi0000ab78(Gfx *gdl)
{
	Mtxf sp110;
	Mtxf spd0;
	Mtxf sp90;
	Mtxf sp50;
	Mtx *sp4c;
	Mtx *sp48;
	u16 sp46;

	guPerspectiveF(sp110.m, &sp46, g_ViBackData->fovy, g_ViBackData->aspect, g_ViBackData->znear, g_ViBackData->zfar + g_ViBackData->zfar, 1);
	mtx4Copy(g_Vars.currentplayer->worldtoscreenmtx, &sp90);

	sp90.m[3][0] = 0;
	sp90.m[3][1] = 0;
	sp90.m[3][2] = 0;

	mtx4MultMtx4(&sp110, &sp90, &spd0);
	sp4c = gfxAllocateMatrix();
	guMtxF2L(spd0.m, sp4c);

	mtx4LoadIdentity(&sp50);
	sp48 = gfxAllocateMatrix();
	guMtxF2L(sp50.m, sp48);

	gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(sp4c), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
	gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(sp48), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPPerspNormalize(gdl++, sp46);

	return gdl;
}

Gfx *vi0000aca4(Gfx *gdl, f32 znear, f32 zfar)
{
	u16 scale;
	Mtxf tmp;
	Mtx *mtx = gfxAllocateMatrix();

	guPerspectiveF(tmp.m, &scale, g_ViBackData->fovy, g_ViBackData->aspect, znear, zfar, 1);
	guMtxF2L(tmp.m, mtx);

	gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
	gSPPerspNormalize(gdl++, scale);

	return gdl;
}

static Gfx *vi0000ad5c(Gfx *gdl, Vp *vp)
{
	vp[g_ViBackIndex].vp.vscale[0] = g_ViBackData->viewx * 2;
	vp[g_ViBackIndex].vp.vtrans[0] = g_ViBackData->viewx * 2 + g_ViBackData->viewleft * 4;

	vp[g_ViBackIndex].vp.vscale[1] = g_ViBackData->viewy * 2;
	vp[g_ViBackIndex].vp.vtrans[1] = g_ViBackData->viewy * 2 + g_ViBackData->viewtop * 4;

	gSPViewport(gdl++, OS_K0_TO_PHYSICAL(&vp[g_ViBackIndex]));

	var80092870 = gfxAllocateMatrix();
	guPerspectiveF(var80092830.m, &g_ViPerspScale, g_ViBackData->fovy, g_ViBackData->aspect, g_ViBackData->znear, g_ViBackData->zfar, 1);
	guMtxF2L(var80092830.m, var80092870);

	gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(var80092870), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
	gSPPerspNormalize(gdl++, g_ViPerspScale);

	g_Vars.currentplayer->perspmtxl = var80092870;
	g_Vars.currentplayer->mtxf1754 = &var80092830;

	return gdl;
}

Gfx *vi0000af00(Gfx *gdl, Vp *vp)
{
	vp[g_ViBackIndex].vp.vscale[0] = g_ViBackData->viewx * 2;
	vp[g_ViBackIndex].vp.vtrans[0] = g_ViBackData->viewx * 2 + g_ViBackData->viewleft * 4;

	vp[g_ViBackIndex].vp.vscale[1] = g_ViBackData->viewy * 2;
	vp[g_ViBackIndex].vp.vtrans[1] = g_ViBackData->viewy * 2 + g_ViBackData->viewtop * 4;

	vp[g_ViBackIndex].vp.vscale[2] = 511;
	vp[g_ViBackIndex].vp.vtrans[2] = 511;

	vp[g_ViBackIndex].vp.vscale[3] = 0;
	vp[g_ViBackIndex].vp.vtrans[3] = 0;

	gSPViewport(gdl++, OS_K0_TO_PHYSICAL(&vp[g_ViBackIndex]));

	var80092870 = gfxAllocateMatrix();
	guPerspectiveF(var80092830.m, &g_ViPerspScale, g_ViBackData->fovy, g_ViBackData->aspect, g_ViBackData->znear, g_ViBackData->zfar, 1);
	guMtxF2L(var80092830.m, var80092870);

	gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(var80092870), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
	gSPPerspNormalize(gdl++, g_ViPerspScale);

	g_Vars.currentplayer->perspmtxl = var80092870;
	g_Vars.currentplayer->mtxf1754 = &var80092830;

	return gdl;
}

Gfx *vi0000b0e8(Gfx *gdl, f32 fovy, f32 aspect)
{
	Mtxf tmp;
	Mtx *mtx = gfxAllocateMatrix();

	guPerspectiveF(tmp.m, &g_ViPerspScale, fovy, aspect, g_ViBackData->znear, g_ViBackData->zfar, 1);
	guMtxF2L(tmp.m, mtx);

	gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
	gSPPerspNormalize(gdl++, g_ViPerspScale);

	return gdl;
}

Gfx *vi0000b1a8(Gfx *gdl)
{
	return vi0000ad5c(gdl, &g_Vars.currentplayer->viewport[0]);
}

Gfx *vi0000b1d0(Gfx *gdl)
{
	gdl = vi0000b1a8(gdl);

	gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, g_ViBackData->bufx, OS_K0_TO_PHYSICAL(g_ViBackData->fb));

	return gdl;
}

Gfx *vi0000b280(Gfx *gdl)
{
	if (g_ViBackData->usezbuf) {
		gdl = mblur0f1762ac(gdl);
		gdl = mblur0f1763f4(gdl);
	}

	return gdl;
}

Gfx *viFillBuffer(Gfx *gdl)
{
	gDPSetCycleType(gdl++, G_CYC_FILL);
	gDPFillRectangle(gdl++, 0, 0, g_ViBackData->bufx - 1, g_ViBackData->bufy - 1);
	gDPPipeSync(gdl++);

	return gdl;
}

Gfx *viRenderViewportEdges(Gfx *gdl)
{
	gDPSetCycleType(gdl++, G_CYC_FILL);
	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, g_ViBackData->x, g_ViBackData->y);
	gDPSetFillColor(gdl++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));

	if (PLAYERCOUNT() == 1
			|| ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
				&& playerHasSharedViewport() && g_Vars.currentplayernum == 0)) {
		// Single viewport
		if (g_ViBackData->viewtop > 0) {
			// Fill above
			gDPFillRectangle(gdl++, 0, 0, g_ViBackData->x - 1, g_ViBackData->viewtop - 1);
			gDPPipeSync(gdl++);
		}

		if (g_ViBackData->viewtop + g_ViBackData->viewy < g_ViBackData->y) {
			// Fill below
			gDPFillRectangle(gdl++,
					0, g_ViBackData->viewtop + g_ViBackData->viewy,
					g_ViBackData->x - 1, g_ViBackData->y - 1);
			gDPPipeSync(gdl++);
		}
	} else {
		if (g_Vars.currentplayerindex == 0) {
			s32 topplayernum = 0;
			s32 bottomplayernum = 0;
			s32 tmpplayernum = 0;

			if (PLAYERCOUNT() == 2) {
				bottomplayernum = 1;
				tmpplayernum = 1;
			} else if (PLAYERCOUNT() >= 3) {
				bottomplayernum = 2;
				tmpplayernum = 2;
			}

			if (g_Vars.players[topplayernum]->viewtop > 0) {
				// Fill above all viewports - full width
				gDPFillRectangle(gdl++, 0, 0, g_ViBackData->x - 1, g_Vars.players[topplayernum]->viewtop - 1);
				gDPPipeSync(gdl++);
			}

			if (g_Vars.players[bottomplayernum]->viewtop + g_Vars.players[bottomplayernum]->viewheight < g_ViBackData->y) {
				// Fill below all viewports - full width
				gDPFillRectangle(gdl++,
						0, g_Vars.players[bottomplayernum]->viewtop + g_Vars.players[bottomplayernum]->viewheight,
						g_ViBackData->x - 1, g_ViBackData->y - 1);
				gDPPipeSync(gdl++);
			}

			// Horizontal middle line
			gDPFillRectangle(gdl++,
					0, g_Vars.players[tmpplayernum]->viewtop - 1,
					g_ViBackData->x - 1, g_Vars.players[tmpplayernum]->viewtop - 1);
			gDPPipeSync(gdl++);

			if (PLAYERCOUNT() >= 3 ||
					(PLAYERCOUNT() == 2 && g_ScreenSplit == SCREENSPLIT_VERTICAL)) {
				if (PLAYERCOUNT() == 2) {
					tmpplayernum = 0;
				}

				// Vertical middle line
				gDPFillRectangle(gdl++,
						g_Vars.players[tmpplayernum]->viewleft + g_Vars.players[tmpplayernum]->viewwidth, 0,
						g_Vars.players[tmpplayernum]->viewleft + g_Vars.players[tmpplayernum]->viewwidth, g_ViBackData->y - 1);
				gDPPipeSync(gdl++);
			}

			if (PLAYERCOUNT() == 3) {
				// Blank square in P4 spot
				gDPFillRectangle(gdl++,
						g_Vars.players[tmpplayernum]->viewleft + g_Vars.players[tmpplayernum]->viewwidth + 1, g_Vars.players[tmpplayernum]->viewtop,
						g_ViBackData->x - 1, g_ViBackData->y - 1);
				gDPPipeSync(gdl++);
			}
		}
	}

	return gdl;
}

static void camSetScreenSize(f32 width, f32 height)
{
	struct player *player = g_Vars.currentplayer;

	player->c_screenwidth = width;
	player->c_screenheight = height;
	player->c_halfwidth = width * 0.5f;
	player->c_halfheight = height * 0.5f;
}

static void camSetScreenPosition(f32 left, f32 top)
{
	struct player *player = g_Vars.currentplayer;

	player->c_screenleft = left;
	player->c_screentop = top;
}

static void camSetPerspective(f32 near, f32 fovy, f32 aspect)
{
	struct player *player = g_Vars.currentplayer;

	player->c_perspnear = near;
	player->c_perspfovy = fovy;
	player->c_perspaspect = aspect;
}

void viSetBufSize(s16 width, s16 height)
{
	g_ViBackData->bufx = width;
	g_ViBackData->bufy = height;
}

void viSetSize(s16 width, s16 height)
{
	g_ViBackData->x = width;
	g_ViBackData->y = height;
}

void viSetViewSize(s16 width, s16 height)
{
	g_ViBackData->viewx = width;
	g_ViBackData->viewy = height;

	camSetScreenSize(g_ViBackData->viewx, g_ViBackData->viewy);
	camSetScale();
}

void viSetViewPosition(s16 left, s16 top)
{
	g_ViBackData->viewleft = left;
	g_ViBackData->viewtop = top;

	camSetScreenPosition(g_ViBackData->viewleft, g_ViBackData->viewtop);
}

void viSetFovY(f32 fovy)
{
	g_ViBackData->fovy = fovy;

	camSetPerspective(g_ViBackData->znear, g_ViBackData->fovy, g_ViBackData->aspect);
	camSetScale();
}

void viSetAspect(f32 aspect)
{
	g_ViBackData->aspect = aspect;

	camSetPerspective(g_ViBackData->znear, g_ViBackData->fovy, g_ViBackData->aspect);
	camSetScale();
}

void viSetFovAspectAndSize(f32 fovy, f32 aspect, s16 width, s16 height)
{
	g_ViBackData->fovy = fovy;
	g_ViBackData->aspect = aspect;
	g_ViBackData->viewx = width;
	g_ViBackData->viewy = height;

	camSetScreenSize(g_ViBackData->viewx, g_ViBackData->viewy);
	camSetPerspective(g_ViBackData->znear, g_ViBackData->fovy, g_ViBackData->aspect);
	camSetScale();
}

void viSetZRange(f32 near, f32 far)
{
	g_ViBackData->znear = near;
	g_ViBackData->zfar = far;

	camSetPerspective(g_ViBackData->znear, g_ViBackData->fovy, g_ViBackData->aspect);
	camSetScale();
}

void viGetZRange(struct zrange *zrange)
{
	zrange->near = g_ViBackData->znear;
	zrange->far = g_ViBackData->zfar;
}

Gfx *viSetFillColour(Gfx *gdl, s32 r, s32 g, s32 b)
{
	gDPSetFillColor(gdl++, (GPACK_RGBA5551(r, g, b, 1) << 16) | GPACK_RGBA5551(r, g, b, 1));

	return gdl;
}
