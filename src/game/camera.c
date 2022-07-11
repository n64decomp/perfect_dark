#include <ultra64.h>
#include "constants.h"
#include "game/atan2f.h"
#include "game/camera.h"
#include "game/tex.h"
#include "game/playermgr.h"
#include "game/bg.h"
#include "game/texdecompress.h"
#include "bss.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

struct coord var8009dd20;
f32 var8009dd2c;
struct coord var8009dd30;
f32 var8009dd3c;
struct coord var8009dd40;
f32 var8009dd4c;
struct coord var8009dd50;
f32 var8009dd5c;
struct coord var8009dd60;
f32 var8009dd6c;

void cam0f0b4950(void)
{
	// empty
}

void camSetScreenSize(f32 width, f32 height)
{
	struct player *player = g_Vars.currentplayer;

	player->c_screenwidth = width;
	player->c_screenheight = height;
	player->c_halfwidth = width * 0.5f;
	player->c_halfheight = height * 0.5f;
}

void camSetScreenPosition(f32 left, f32 top)
{
	struct player *player = g_Vars.currentplayer;

	player->c_screenleft = left;
	player->c_screentop = top;
}

void camSetPerspective(f32 near, f32 fovy, f32 aspect)
{
	struct player *player = g_Vars.currentplayer;

	player->c_perspnear = near;
	player->c_perspfovy = fovy;
	player->c_perspaspect = aspect;
}

f32 cam0f0b49b8(f32 arg0)
{
	f32 result = atan2f(g_Vars.currentplayer->c_scalelod60 * arg0 * g_Vars.currentplayer->c_halfheight, 1.0f);
	result *= 114.591552f;

	if (result < 0) {
		result = -result;
	}

	return result;
}

void camSetScale(void)
{
	struct player *player = g_Vars.currentplayer;
	f32 fVar4;
	f32 tmp;
	f32 fVar5;
	f32 fVar2;

	player->c_scaley = sinf(player->c_perspfovy * (M_PI / 360.0f)) / (cosf(player->c_perspfovy * (M_PI / 360.0f)) * player->c_halfheight);
	player->c_scalelod = player->c_scaley;
	player->c_scalex = (player->c_scaley * player->c_perspaspect * player->c_halfheight) / player->c_halfwidth;

	player->c_recipscalex = 1.0f / player->c_scalex;
	player->c_recipscaley = 1.0f / player->c_scaley;

	fVar4 = sinf(0.52359879016876f) / (cosf(0.52359879016876f) * 120.0f);
	player->c_scalelod60 = fVar4;
	player->c_lodscalez = player->c_scalelod / fVar4;
	tmp = player->c_lodscalez * 65536.0f;

	if (tmp > 4294967296.0f) {
		player->c_lodscalezu32 = 0xffffffff;
	} else {
		player->c_lodscalezu32 = tmp;
	}

	fVar2 = player->c_halfheight * player->c_scaley;
	fVar4 = 1.0f / sqrtf(fVar2 * fVar2 + 1.0f);
	player->c_cameratopnorm.x = 0;
	player->c_cameratopnorm.y = fVar4;
	player->c_cameratopnorm.z = fVar2 * fVar4;

	fVar5 = -player->c_halfwidth * player->c_scalex;
	fVar4 = 1.0f / sqrtf(fVar5 * fVar5 + 1.0f);
	player->c_cameraleftnorm.x = -fVar4;
	player->c_cameraleftnorm.y = 0;
	player->c_cameraleftnorm.z = -fVar5 * fVar4;
}

void cam0f0b4c3c(f32 *crosspos, struct coord *dst, f32 arg2)
{
	struct player *player = g_Vars.currentplayer;
	f32 sp20;
	f32 sp1c;
	f32 sp18 = -1.0f;
	f32 f2;

	sp1c = (player->c_halfheight - (crosspos[1] - player->c_screentop)) * player->c_scaley;
	sp20 = (crosspos[0] - player->c_screenleft - player->c_halfwidth) * player->c_scalex;

	f2 = arg2 / sqrtf(sp20 * sp20 + sp1c * sp1c + sp18 * sp18);

	dst->x = sp20 * f2;
	dst->y = sp1c * f2;
	dst->z = sp18 * f2;
}

void cam0f0b4d04(struct coord *in, f32 *out)
{
	struct player *player = g_Vars.currentplayer;
	f32 value = 1.0f / in->z;

	out[1] = in->y * value * player->c_recipscaley
		+ (player->c_screentop + player->c_halfheight);

	out[0] = (player->c_screenleft + player->c_halfwidth)
		- in->x * value * player->c_recipscalex;
}

void cam0f0b4d68(struct coord *in, f32 out[2])
{
	struct player *player = g_Vars.currentplayer;
	f32 value;

	if (in->z == 0.0f) {
		value = -100000000000000000000.0f;
	} else {
		value = 1.0f / in->z;
	}

	out[1] = in->y * value * player->c_recipscaley + (player->c_screentop + player->c_halfheight);
	out[0] = (player->c_screenleft + player->c_halfwidth) - in->x * value * player->c_recipscalex;
}

void cam0f0b4dec(struct coord *in, f32 out[2])
{
	struct player *player = g_Vars.currentplayer;
	f32 value = 1.0f / in->z;

	if (value < 0) {
		value = -value;
	}

	out[1] = in->y * value * player->c_recipscaley + (player->c_screentop + player->c_halfheight);
	out[0] = (player->c_screenleft + player->c_halfwidth) - in->x * value * player->c_recipscalex;
}

void cam0f0b4e68(struct coord *in, f32 divisor, struct coord *out)
{
	out->y = in->y * (1.0f / divisor) * g_Vars.currentplayer->c_recipscaley;
	out->x = in->x * (1.0f / divisor) * g_Vars.currentplayer->c_recipscalex;
}

void cam0f0b4eb8(struct coord *arg0, f32 arg1[2], f32 zoom, f32 aspect)
{
	f32 f12;
	f32 f14;
	struct player *player = g_Vars.currentplayer;

	f12 = cosf(zoom * 0.008726646f) * player->c_halfheight / (sinf(zoom * 0.008726646f) * arg0->f[2]);
	f14 = f12 * player->c_halfwidth / (aspect * player->c_halfheight);

	arg1[1] = f12 * arg0->f[1] + (player->c_screentop + player->c_halfheight);
	arg1[0] = player->c_screenleft + player->c_halfwidth - f14 * arg0->f[0];
}

void camSetMtxL1738(Mtx *mtx)
{
	g_Vars.currentplayer->mtxl1738 = mtx;
}

Mtx *camGetMtxL1738(void)
{
	return g_Vars.currentplayer->mtxl1738;
}

void camSetMtxL173c(Mtx *mtx)
{
	g_Vars.currentplayer->mtxl173c = mtx;
}

Mtx *camGetMtxL173c(void)
{
	return g_Vars.currentplayer->mtxl173c;
}

void camSetMtxF006c(Mtxf *mtx)
{
	g_Vars.currentplayer->mtxf006c = mtx;
}

Mtxf *camGetMtxF006c(void)
{
	return g_Vars.currentplayer->mtxf006c;
}

void camSetPerspectiveMtxL(Mtx *mtx)
{
	g_Vars.currentplayer->perspmtxl = mtx;
}

Mtx *camGetPerspectiveMtxL(void)
{
	return g_Vars.currentplayer->perspmtxl;
}

void camSetOrthogonalMtxL(Mtx *mtx)
{
	g_Vars.currentplayer->orthomtxl = mtx;
}

Mtx *camGetOrthogonalMtxL(void)
{
	return g_Vars.currentplayer->orthomtxl;
}

void camSetWorldToScreenMtxf(Mtxf *mtx)
{
	struct player *player = g_Vars.currentplayer;

	player->prevworldtoscreenmtx = player->worldtoscreenmtx;
	player->worldtoscreenmtx = mtx;
	player->c_viewfmdynticknum = g_GfxNumSwaps;
	player->unk0488 = player->unk0484;
	player->unk0484 = g_GfxMemPos;
}

Mtxf *cam0f0b5050(u8 *arg0)
{
	Mtxf *result = NULL;
	s32 i;

	if (arg0 >= g_VtxBuffers[g_GfxActiveBufferIndex] && arg0 < g_VtxBuffers[g_GfxActiveBufferIndex + 1]) {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.currentplayerindex >= playermgrGetOrderOfPlayer(i)) {
				if (g_GfxNumSwaps == g_Vars.players[i]->c_viewfmdynticknum) {
					if (arg0 >= g_Vars.players[i]->unk0484 && (u8 *)result < g_Vars.players[i]->unk0484) {
						result = g_Vars.players[i]->worldtoscreenmtx;
					}
				}
			}
		}
	} else {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.currentplayerindex >= playermgrGetOrderOfPlayer(i)) {
				if (g_GfxNumSwaps == g_Vars.players[i]->c_prevviewfmdynticknum + 1) {
					if (arg0 >= g_Vars.players[i]->unk0488 && (u8 *)result < g_Vars.players[i]->unk0488) {
						result = g_Vars.players[i]->prevworldtoscreenmtx;
					}
				}
			} else {
				if (g_GfxNumSwaps == g_Vars.players[i]->c_viewfmdynticknum + 1) {
					if (arg0 >= g_Vars.players[i]->unk0484 && (u8 *)result < g_Vars.players[i]->unk0484) {
						result = g_Vars.players[i]->worldtoscreenmtx;
					}
				}
			}
		}
	}

	return result;
}

Mtxf *cam0f0b53a4(u8 *arg0)
{
	Mtxf *result = NULL;
	s32 i;

	if (arg0 >= g_VtxBuffers[g_GfxActiveBufferIndex] && arg0 < g_VtxBuffers[g_GfxActiveBufferIndex + 1]) {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.currentplayerindex >= playermgrGetOrderOfPlayer(i)) {
				if (g_GfxNumSwaps == g_Vars.players[i]->c_viewfmdynticknum) {
					if (arg0 >= g_Vars.players[i]->unk0484 && (u8 *)result < g_Vars.players[i]->unk0484) {
						result = g_Vars.players[i]->projectionmtx;
					}
				}
			}
		}
	} else {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.currentplayerindex >= playermgrGetOrderOfPlayer(i)) {
				if (g_GfxNumSwaps == g_Vars.players[i]->c_prevviewfmdynticknum + 1) {
					if (arg0 >= g_Vars.players[i]->unk0488 && (u8 *)result < g_Vars.players[i]->unk0488) {
						result = g_Vars.players[i]->prevprojectionmtx;
					}
				}
			} else {
				if (g_GfxNumSwaps == g_Vars.players[i]->c_viewfmdynticknum + 1) {
					if (arg0 >= g_Vars.players[i]->unk0484 && (u8 *)result < g_Vars.players[i]->unk0484) {
						result = g_Vars.players[i]->projectionmtx;
					}
				}
			}
		}
	}

	return result;
}

Mtxf *camGetWorldToScreenMtxf(void)
{
	return g_Vars.currentplayer->worldtoscreenmtx;
}

void camSetMtxF1754(Mtxf *mtx)
{
	g_Vars.currentplayer->mtxf1754 = mtx;
}

Mtxf *camGetMtxF1754(void)
{
	return g_Vars.currentplayer->mtxf1754;
}

Mtxf *camGetPrevWorldToScreenMtxf(void)
{
	return g_Vars.currentplayer->prevworldtoscreenmtx;
}

void camSetMtxF1748(Mtxf *mtx)
{
	g_Vars.currentplayer->mtxf1748 = mtx;
}

Mtxf *camGetMtxF1748(void)
{
	return g_Vars.currentplayer->mtxf1748;
}

void camSetProjectionMtxF(Mtxf *mtx)
{
	struct player *player = g_Vars.currentplayer;

	player->c_prevviewfmdynticknum = player->c_viewfmdynticknum;
	player->prevprojectionmtx = player->projectionmtx;
	player->projectionmtx = mtx;
}

Mtxf *camGetProjectionMtxF(void)
{
	return g_Vars.currentplayer->projectionmtx;
}

Mtxf *camGetPrevProjectionMtxF(void)
{
	return g_Vars.currentplayer->prevprojectionmtx;
}

void camSetLookAt(LookAt *lookat)
{
	g_Vars.currentplayer->lookat = lookat;
}

LookAt *camGetLookAt(void)
{
	return g_Vars.currentplayer->lookat;
}

f32 camGetLodScaleZ(void)
{
	return g_Vars.currentplayer->c_lodscalez;
}

u32 camGetLodScaleZU32(void)
{
	return g_Vars.currentplayer->c_lodscalezu32;
}

f32 camGetScreenWidth(void)
{
	return g_Vars.currentplayer->c_screenwidth;
}

f32 camGetScreenHeight(void)
{
	return g_Vars.currentplayer->c_screenheight;
}

f32 camGetScreenLeft(void)
{
	return g_Vars.currentplayer->c_screenleft;
}

f32 camGetScreenTop(void)
{
	return g_Vars.currentplayer->c_screentop;
}

f32 camGetPerspFovY(void)
{
	return g_Vars.currentplayer->c_perspfovy;
}

f32 camGetPerspAspect(void)
{
	return g_Vars.currentplayer->c_perspaspect;
}

void cam0f0b5838(void)
{
	f32 sp2c;
	f32 sp28;
	f32 sp24;
	f32 sp20;
	struct player *player;
	Mtxf *mtx;
	f32 sp14;
	f32 sp10;

	player = g_Vars.currentplayer;
	sp24 = player->c_halfheight * player->c_scaley;
	mtx = player->projectionmtx;

	sp2c = 1.0f / sqrtf(sp24 * sp24 + 1.0f);
	sp24 *= sp2c;
	sp20 = -sp2c;

	var8009dd20.f[0] = -sp20 * mtx->m[1][0] + (sp24) * mtx->m[2][0];
	var8009dd20.f[1] = -sp20 * mtx->m[1][1] + (sp24) * mtx->m[2][1];
	var8009dd20.f[2] = -sp20 * mtx->m[1][2] + (sp24) * mtx->m[2][2];

	var8009dd2c = var8009dd20.f[0] * mtx->m[3][0] + var8009dd20.f[1] * mtx->m[3][1] + var8009dd20.f[2] * mtx->m[3][2];

	var8009dd30.f[0] = sp20 * mtx->m[1][0] + (sp24) * mtx->m[2][0];
	var8009dd30.f[1] = sp20 * mtx->m[1][1] + (sp24) * mtx->m[2][1];
	var8009dd30.f[2] = sp20 * mtx->m[1][2] + (sp24) * mtx->m[2][2];

	var8009dd3c = var8009dd30.f[0] * mtx->m[3][0] + var8009dd30.f[1] * mtx->m[3][1] + var8009dd30.f[2] * mtx->m[3][2];

	sp28 = -player->c_halfwidth * player->c_scalex;

	sp10 = 1.0f / sqrtf(sp28 * sp28 + 1.0f);
	sp28 *= sp10;
	sp14 = -sp10;

	var8009dd40.f[0] = sp14 * mtx->m[0][0] - sp28 * mtx->m[2][0];
	var8009dd40.f[1] = sp14 * mtx->m[0][1] - sp28 * mtx->m[2][1];
	var8009dd40.f[2] = sp14 * mtx->m[0][2] - sp28 * mtx->m[2][2];

	var8009dd4c = var8009dd40.f[0] * mtx->m[3][0] + var8009dd40.f[1] * mtx->m[3][1] + var8009dd40.f[2] * mtx->m[3][2];

	var8009dd50.f[0] = -sp14 * mtx->m[0][0] - sp28 * mtx->m[2][0];
	var8009dd50.f[1] = -sp14 * mtx->m[0][1] - sp28 * mtx->m[2][1];
	var8009dd50.f[2] = -sp14 * mtx->m[0][2] - sp28 * mtx->m[2][2];

	var8009dd5c = var8009dd50.f[0] * mtx->m[3][0] + var8009dd50.f[1] * mtx->m[3][1] + var8009dd50.f[2] * mtx->m[3][2];

	var8009dd60.f[0] = -mtx->m[3][0];
	var8009dd60.f[1] = -mtx->m[3][1];
	var8009dd60.f[2] = -mtx->m[3][2];

	var8009dd6c = mtx->m[2][0] * mtx->m[3][0] + mtx->m[2][1] * mtx->m[3][1] + mtx->m[2][2] * mtx->m[3][2];
}

bool cam0f0b5b9c(struct coord *arg0, f32 arg1)
{
	Mtxf *mtx = g_Vars.currentplayer->projectionmtx;

	if (var8009dd6c + arg1 < mtx->m[2][0] * arg0->f[0] + mtx->m[2][1] * arg0->f[1] + mtx->m[2][2] * arg0->f[2]) {
		return false;
	}

	if (var8009dd4c + arg1 < var8009dd40.f[0] * arg0->f[0] + var8009dd40.f[1] * arg0->f[1] + var8009dd40.f[2] * arg0->f[2]) {
		return false;
	}

	if (var8009dd5c + arg1 < var8009dd50.f[0] * arg0->f[0] + var8009dd50.f[1] * arg0->f[1] + var8009dd50.f[2] * arg0->f[2]) {
		return false;
	}

	if (var8009dd2c + arg1 < var8009dd20.f[0] * arg0->f[0] + var8009dd20.f[1] * arg0->f[1] + var8009dd20.f[2] * arg0->f[2]) {
		return false;
	}

	if (var8009dd3c + arg1 < var8009dd30.f[0] * arg0->f[0] + var8009dd30.f[1] * arg0->f[1] + var8009dd30.f[2] * arg0->f[2]) {
		return false;
	}

	return true;
}

bool camIsPosInScreenBox(struct coord *pos, f32 arg1, struct var800a4640_00 *arg2)
{
	struct coord sp74;
	f32 sp70;
	struct coord sp64;
	f32 sp60;
	struct coord sp54;
	f32 sp50;
	struct coord sp44;
	f32 sp40;
	f32 sp3c;
	f32 sp38;
	f32 sp34;
	f32 sp30;
	f32 sp2c;
	f32 sp28;
	f32 sp24;
	f32 sp20;
	f32 sp1c;
	f32 sp18;

	if (var8009dd6c + arg1 < g_Vars.currentplayer->projectionmtx->m[2][0] * pos->f[0] + g_Vars.currentplayer->projectionmtx->m[2][1] * pos->f[1] + g_Vars.currentplayer->projectionmtx->m[2][2] * pos->f[2]) {
		return false;
	}

	sp38 = (arg2->box.xmin - g_Vars.currentplayer->c_screenleft - g_Vars.currentplayer->c_halfwidth) * g_Vars.currentplayer->c_scalex;

	sp3c = 1.0f / sqrtf(sp38 * sp38 + 1.0f);
	sp38 *= sp3c;
	sp24 = -sp3c;

	sp54.f[0] = sp24 * g_Vars.currentplayer->projectionmtx->m[0][0] - sp38 * g_Vars.currentplayer->projectionmtx->m[2][0];
	sp54.f[1] = sp24 * g_Vars.currentplayer->projectionmtx->m[0][1] - sp38 * g_Vars.currentplayer->projectionmtx->m[2][1];
	sp54.f[2] = sp24 * g_Vars.currentplayer->projectionmtx->m[0][2] - sp38 * g_Vars.currentplayer->projectionmtx->m[2][2];

	sp50 = sp54.f[0] * g_Vars.currentplayer->projectionmtx->m[3][0] + sp54.f[1] * g_Vars.currentplayer->projectionmtx->m[3][1] + sp54.f[2] * g_Vars.currentplayer->projectionmtx->m[3][2];

	if (sp50 + arg1 < sp54.f[0] * pos->f[0] + sp54.f[1] * pos->f[1] + sp54.f[2] * pos->f[2]) {
		return false;
	}

	sp38 = -(arg2->box.xmax - g_Vars.currentplayer->c_screenleft - g_Vars.currentplayer->c_halfwidth) * g_Vars.currentplayer->c_scalex;
	sp30 = 1.0f / sqrtf(sp38 * sp38 + 1.0f);
	sp38 *= sp30;
	sp20 = -sp30;

	sp44.f[0] = -sp20 * g_Vars.currentplayer->projectionmtx->m[0][0] - sp38 * g_Vars.currentplayer->projectionmtx->m[2][0];
	sp44.f[1] = -sp20 * g_Vars.currentplayer->projectionmtx->m[0][1] - sp38 * g_Vars.currentplayer->projectionmtx->m[2][1];
	sp44.f[2] = -sp20 * g_Vars.currentplayer->projectionmtx->m[0][2] - sp38 * g_Vars.currentplayer->projectionmtx->m[2][2];

	sp40 = sp44.f[0] * g_Vars.currentplayer->projectionmtx->m[3][0] + sp44.f[1] * g_Vars.currentplayer->projectionmtx->m[3][1] + sp44.f[2] * g_Vars.currentplayer->projectionmtx->m[3][2];

	if (sp40 + arg1 < sp44.f[0] * pos->f[0] + sp44.f[1] * pos->f[1] + sp44.f[2] * pos->f[2]) {
		return false;
	}

	sp34 = (g_Vars.currentplayer->c_halfheight - (arg2->box.ymin - g_Vars.currentplayer->c_screentop)) * g_Vars.currentplayer->c_scaley;
	sp2c = 1.0f / sqrtf(sp34 * sp34 + 1.0f);
	sp34 *= sp2c;
	sp1c = -sp2c;

	sp74.f[0] = -sp1c * g_Vars.currentplayer->projectionmtx->m[1][0] + sp34 * g_Vars.currentplayer->projectionmtx->m[2][0];
	sp74.f[1] = -sp1c * g_Vars.currentplayer->projectionmtx->m[1][1] + sp34 * g_Vars.currentplayer->projectionmtx->m[2][1];
	sp74.f[2] = -sp1c * g_Vars.currentplayer->projectionmtx->m[1][2] + sp34 * g_Vars.currentplayer->projectionmtx->m[2][2];

	sp70 = sp74.f[0] * g_Vars.currentplayer->projectionmtx->m[3][0] + sp74.f[1] * g_Vars.currentplayer->projectionmtx->m[3][1] + sp74.f[2] * g_Vars.currentplayer->projectionmtx->m[3][2];

	if (sp70 + arg1 < sp74.f[0] * pos->f[0] + sp74.f[1] * pos->f[1] + sp74.f[2] * pos->f[2]) {
		return false;
	}

	sp34 = -(g_Vars.currentplayer->c_halfheight - (arg2->box.ymax - g_Vars.currentplayer->c_screentop)) * g_Vars.currentplayer->c_scaley;
	sp28 = 1.0f / sqrtf(sp34 * sp34 + 1.0f);
	sp34 *= sp28;
	sp18 = -sp28;

	sp64.f[0] = sp18 * g_Vars.currentplayer->projectionmtx->m[1][0] + sp34 * g_Vars.currentplayer->projectionmtx->m[2][0];
	sp64.f[1] = sp18 * g_Vars.currentplayer->projectionmtx->m[1][1] + sp34 * g_Vars.currentplayer->projectionmtx->m[2][1];
	sp64.f[2] = sp18 * g_Vars.currentplayer->projectionmtx->m[1][2] + sp34 * g_Vars.currentplayer->projectionmtx->m[2][2];

	sp60 = sp64.f[0] * g_Vars.currentplayer->projectionmtx->m[3][0] + sp64.f[1] * g_Vars.currentplayer->projectionmtx->m[3][1] + sp64.f[2] * g_Vars.currentplayer->projectionmtx->m[3][2];

	if (sp60 + arg1 < sp64.f[0] * pos->f[0] + sp64.f[1] * pos->f[1] + sp64.f[2] * pos->f[2]) {
		return false;
	}

	return true;
}

GLOBAL_ASM(
glabel camIsPosInFovAndVisibleRoom
/*  f0b6260:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0b6264:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0b6268:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0b626c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0b6270:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0b6274:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0b6278:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0b627c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0b6280:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f0b6284:	84860000 */ 	lh	$a2,0x0($a0)
/*  f0b6288:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f0b628c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0b6290:	10d20036 */ 	beq	$a2,$s2,.L0f0b636c
/*  f0b6294:	00808025 */ 	or	$s0,$a0,$zero
/*  f0b6298:	3c13800a */ 	lui	$s3,%hi(g_Rooms)
/*  f0b629c:	26734928 */ 	addiu	$s3,$s3,%lo(g_Rooms)
/*  f0b62a0:	2414008c */ 	addiu	$s4,$zero,0x8c
.L0f0b62a4:
/*  f0b62a4:	00d40019 */ 	multu	$a2,$s4
/*  f0b62a8:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0b62ac:	00007812 */ 	mflo	$t7
/*  f0b62b0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0b62b4:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f0b62b8:	33280004 */ 	andi	$t0,$t9,0x4
/*  f0b62bc:	51000028 */ 	beqzl	$t0,.L0f0b6360
/*  f0b62c0:	86060002 */ 	lh	$a2,0x2($s0)
/*  f0b62c4:	0fc56050 */ 	jal	func0f158140
/*  f0b62c8:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0b62cc:	2e230001 */ 	sltiu	$v1,$s1,0x1
/*  f0b62d0:	1060000a */ 	beqz	$v1,.L0f0b62fc
/*  f0b62d4:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f0b62d8:	84490004 */ 	lh	$t1,0x4($v0)
/*  f0b62dc:	a7a90038 */ 	sh	$t1,0x38($sp)
/*  f0b62e0:	844a0006 */ 	lh	$t2,0x6($v0)
/*  f0b62e4:	a7aa003a */ 	sh	$t2,0x3a($sp)
/*  f0b62e8:	844b0008 */ 	lh	$t3,0x8($v0)
/*  f0b62ec:	a7ab003c */ 	sh	$t3,0x3c($sp)
/*  f0b62f0:	844c000a */ 	lh	$t4,0xa($v0)
/*  f0b62f4:	10000019 */ 	b	.L0f0b635c
/*  f0b62f8:	a7ac003e */ 	sh	$t4,0x3e($sp)
.L0f0b62fc:
/*  f0b62fc:	84430004 */ 	lh	$v1,0x4($v0)
/*  f0b6300:	87ad0038 */ 	lh	$t5,0x38($sp)
/*  f0b6304:	006d082a */ 	slt	$at,$v1,$t5
/*  f0b6308:	50200003 */ 	beqzl	$at,.L0f0b6318
/*  f0b630c:	84430006 */ 	lh	$v1,0x6($v0)
/*  f0b6310:	a7a30038 */ 	sh	$v1,0x38($sp)
/*  f0b6314:	84430006 */ 	lh	$v1,0x6($v0)
.L0f0b6318:
/*  f0b6318:	87ae003a */ 	lh	$t6,0x3a($sp)
/*  f0b631c:	006e082a */ 	slt	$at,$v1,$t6
/*  f0b6320:	50200003 */ 	beqzl	$at,.L0f0b6330
/*  f0b6324:	84430008 */ 	lh	$v1,0x8($v0)
/*  f0b6328:	a7a3003a */ 	sh	$v1,0x3a($sp)
/*  f0b632c:	84430008 */ 	lh	$v1,0x8($v0)
.L0f0b6330:
/*  f0b6330:	87af003c */ 	lh	$t7,0x3c($sp)
/*  f0b6334:	01e3082a */ 	slt	$at,$t7,$v1
/*  f0b6338:	50200003 */ 	beqzl	$at,.L0f0b6348
/*  f0b633c:	8443000a */ 	lh	$v1,0xa($v0)
/*  f0b6340:	a7a3003c */ 	sh	$v1,0x3c($sp)
/*  f0b6344:	8443000a */ 	lh	$v1,0xa($v0)
.L0f0b6348:
/*  f0b6348:	87b8003e */ 	lh	$t8,0x3e($sp)
/*  f0b634c:	0303082a */ 	slt	$at,$t8,$v1
/*  f0b6350:	50200003 */ 	beqzl	$at,.L0f0b6360
/*  f0b6354:	86060002 */ 	lh	$a2,0x2($s0)
/*  f0b6358:	a7a3003e */ 	sh	$v1,0x3e($sp)
.L0f0b635c:
/*  f0b635c:	86060002 */ 	lh	$a2,0x2($s0)
.L0f0b6360:
/*  f0b6360:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f0b6364:	14d2ffcf */ 	bne	$a2,$s2,.L0f0b62a4
/*  f0b6368:	00000000 */ 	nop
.L0f0b636c:
/*  f0b636c:	16200003 */ 	bnez	$s1,.L0f0b637c
/*  f0b6370:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f0b6374:	10000004 */ 	b	.L0f0b6388
/*  f0b6378:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b637c:
/*  f0b637c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0b6380:	0fc2d74e */ 	jal	camIsPosInScreenBox
/*  f0b6384:	27a60034 */ 	addiu	$a2,$sp,0x34
.L0f0b6388:
/*  f0b6388:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b638c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0b6390:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0b6394:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0b6398:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0b639c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0b63a0:	03e00008 */ 	jr	$ra
/*  f0b63a4:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

// Mismatch: Too much compiler-managed stack
//bool camIsPosInFovAndVisibleRoom(s16 *rooms, struct coord *pos, f32 arg2)
//{
//	s8 hasdata = false;
//	s16 room;
//	s32 i;
//	struct var800a4640_00 *thisthing;
//	struct var800a4640_00 thing; // 34
//
//	for (i = 0, room = rooms[0]; room != -1; i++, room = rooms[i]) {
//		if (g_Rooms[room].flags & ROOMFLAG_VISIBLEBYPLAYER) {
//			thisthing = func0f158140(room);
//
//			if (hasdata == false) {
//				thing.box.xmin = thisthing->box.xmin;
//				thing.box.ymin = thisthing->box.ymin;
//				thing.box.xmax = thisthing->box.xmax;
//				thing.box.ymax = thisthing->box.ymax;
//			} else {
//				if (thisthing->box.xmin < thing.box.xmin) {
//					thing.box.xmin = thisthing->box.xmin;
//				}
//
//				if (thisthing->box.ymin < thing.box.ymin) {
//					thing.box.ymin = thisthing->box.ymin;
//				}
//
//				if (thisthing->box.xmax > thing.box.xmax) {
//					thing.box.xmax = thisthing->box.xmax;
//				}
//
//				if (thisthing->box.ymax > thing.box.ymax) {
//					thing.box.ymax = thisthing->box.ymax;
//				}
//			}
//
//			hasdata = true;
//		}
//	}
//
//	if (!hasdata) {
//		return false;
//	}
//
//	return camIsPosInScreenBox(pos, arg2, &thing);
//}
