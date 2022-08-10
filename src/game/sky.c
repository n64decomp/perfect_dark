#include <ultra64.h>
#include "constants.h"
#include "game/quaternion.h"
#include "game/game_0b2150.h"
#include "game/camera.h"
#include "game/sky.h"
#include "game/game_152fa0.h"
#include "game/env.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/mtx.h"
#include "lib/sched.h"
#include "data.h"
#include "types.h"

#define SKYABS(val) (val >= 0.0f ? (val) : -(val))

u32 g_SkyStageNum;
bool g_SkyLightningActive;
Mtxf var800a33a8;
struct coord g_SunPositions[3]; // relative to centre screen, with a huge scale
u32 var800a340c;
f32 g_SunScreenXPositions[4];
f32 g_SunScreenYPositions[4];

f32 g_SkyCloudOffset = 0;
f32 g_SkyWindSpeed = 1;
f32 g_SunAlphaFracs[3] = {0};
s32 g_SunFlareTimers240[3] = {0};
u32 var8007dba0 = 0x00000010;
u32 var8007dba4 = 0x00000020;
u32 var8007dba8 = 0x0000000c;
u32 var8007dbac = 0x00000020;
u32 var8007dbb0 = 0x00000018;
u32 var8007dbb4 = 0x00000040;
u32 var8007dbb8 = 0x0000003c;
u32 var8007dbbc = 0x00000050;
u32 var8007dbc0 = 0x000000e1;
u32 var8007dbc4 = 0x00000113;
u32 var8007dbc8 = 0x000001d6;
u32 var8007dbcc = 0x0000023a;
u32 var8007dbd0 = 0xff99ffff;
u32 var8007dbd4 = 0x9999ffff;
u32 var8007dbd8 = 0x99ffffff;
u32 var8007dbdc = 0x99ff99ff;
u32 var8007dbe0 = 0xffff99ff;
u32 var8007dbe4 = 0xff9999ff;
struct coord g_TeleportToPos = {0, 0, 0};
struct coord g_TeleportToUp = {0, 0, 1};
struct coord g_TeleportToLook = {0, 1, 0};

void sky0f11f000(f32 left, f32 top, struct coord *arg2)
{
	Mtxf *mtx = camGetProjectionMtxF();
	f32 pos[2];

	pos[0] = left + camGetScreenLeft();
	pos[1] = top + camGetScreenTop() + envGetCurrent()->unk40;

	cam0f0b4c3c(pos, arg2, 100);
	mtx4RotateVecInPlace(mtx, arg2);
}

bool sky0f11f07c(struct coord *arg0, struct coord *arg1, f32 *arg2)
{
	struct coord *campos = &g_Vars.currentplayer->cam_pos;
	f32 f12 = 2.0f * arg0->y / sqrtf(arg0->f[0] * arg0->f[0] + arg0->f[2] * arg0->f[2] + 0.0001f);
	f32 sp2c;
	f32 f12_2;
	f32 sp24;
	u32 stack[2];

	if (f12 > 1.0f) {
		f12 = 1.0f;
	}

	*arg2 = 1.0f - f12;

	if (arg0->y == 0.0f) {
		sp24 = 0.01f;
	} else {
		sp24 = arg0->y;
	}

	if (sp24 > 0.0f) {
		sp2c = (envGetCurrent()->clouds_scale - campos->y) / sp24;
		f12_2 = sqrtf(arg0->f[0] * arg0->f[0] + arg0->f[2] * arg0->f[2]) * sp2c;

		if (f12_2 > 300000) {
			sp2c *= 300000 / f12_2;
		}

		arg1->x = campos->x + sp2c * arg0->f[0];
		arg1->y = campos->y + sp2c * sp24;
		arg1->z = campos->z + sp2c * arg0->f[2];

		return true;
	}

	return false;
}

bool sky0f11f1fc(struct coord *arg0, struct coord *arg1, f32 *arg2)
{
	struct coord *campos = &g_Vars.currentplayer->cam_pos;
	f32 f12 = -2.0f * arg0->y / sqrtf(arg0->f[0] * arg0->f[0] + arg0->f[2] * arg0->f[2] + 0.0001f);
	f32 sp2c;
	f32 f12_2;
	f32 sp24;
	u32 stack[2];

	if (f12 > 1.0f) {
		f12 = 1.0f;
	}

	*arg2 = 1.0f - f12;

	if (arg0->y == 0.0f) {
		sp24 = -0.01f;
	} else {
		sp24 = arg0->y;
	}

	if (sp24 < 0.0f) {
		sp2c = (envGetCurrent()->water_scale - campos->y) / sp24;
		f12_2 = sqrtf(arg0->f[0] * arg0->f[0] + arg0->f[2] * arg0->f[2]) * sp2c;

		if (f12_2 > 300000) {
			sp2c *= 300000 / f12_2;
		}

		arg1->x = campos->x + sp2c * arg0->f[0];
		arg1->y = campos->y + sp2c * sp24;
		arg1->z = campos->z + sp2c * arg0->f[2];

		return true;
	}

	return false;
}

/**
 * Scale base based on the height percentage between base and ref...
 * except the new y is zero.
 */
void sky0f11f384(struct coord *base, struct coord *ref, struct coord *out)
{
	f32 mult = base->y / (base->y - ref->y);

	out->x = (ref->x - base->x) * mult + base->x;
	out->y = 0;
	out->z = (ref->z - base->z) * mult + base->z;
}

f32 skyClamp(f32 value, f32 min, f32 max)
{
	if (value < min) {
		return min;
	}

	if (value > max) {
		return max;
	}

	return value;
}

f32 skyRound(f32 value)
{
	return (s32)(value + 0.5f);
}

void skyChooseCloudVtxColour(struct skything18 *arg0, f32 arg1)
{
	struct environment *env = envGetCurrent();
	f32 scale = 1.0f - arg1;
	f32 r = env->sky_r;
	f32 g = env->sky_g;
	f32 b = env->sky_b;

	arg0->r = r + env->clouds_r * (1.0f - r * (1.0f / 255.0f)) * scale;
	arg0->g = g + env->clouds_g * (1.0f - g * (1.0f / 255.0f)) * scale;
	arg0->b = b + env->clouds_b * (1.0f - b * (1.0f / 255.0f)) * scale;

	if (g_SkyLightningActive) {
		arg0->r = arg0->g = arg0->b = 0xff;
	}

	arg0->a = 0xff;
}

void sky0f11f6ec(struct skything18 *arg0, f32 arg1)
{
	struct environment *env = envGetCurrent();
	f32 scale = 1.0f - arg1;
	f32 r = env->sky_r;
	f32 g = env->sky_g;
	f32 b = env->sky_b;

	arg0->r = r + env->water_r * (1.0f - r * (1.0f / 255.0f)) * scale;
	arg0->g = g + env->water_g * (1.0f - g * (1.0f / 255.0f)) * scale;
	arg0->b = b + env->water_b * (1.0f - b * (1.0f / 255.0f)) * scale;
	arg0->a = 0xff;
}

Gfx *skyRender(Gfx *gdl)
{
	struct coord sp6a4;
	struct coord sp698;
	struct coord sp68c;
	struct coord sp680;
	struct coord sp674;
	struct coord sp668;
	struct coord sp65c;
	struct coord sp650;
	struct coord sp644;
	struct coord sp638;
	struct coord sp62c;
	struct coord sp620;
	struct coord sp614;
	struct coord sp608;
	struct coord sp5fc;
	struct coord sp5f0;
	struct coord sp5e4;
	struct coord sp5d8;
	struct coord sp5cc;
	struct coord sp5c0;
	struct coord sp5b4;
	struct coord sp5a8;
	struct coord sp59c;
	struct coord sp590;
	f32 sp58c;
	f32 sp588;
	f32 sp584;
	f32 sp580;
	f32 sp57c;
	f32 sp578;
	f32 sp574;
	f32 sp570;
	f32 sp56c;
	f32 sp568;
	f32 sp564;
	f32 sp560;
	f32 sp55c;
	f32 sp558;
	f32 sp554;
	f32 sp550;
	f32 sp54c;
	f32 sp548;
	s32 s1;
	s32 j;
	s32 k;
	s32 sp538;
	s32 sp534;
	s32 sp530;
	s32 sp52c;
	struct skything18 sp4b4[5];
	struct skything18 sp43c[5];
	f32 tmp;
	f32 scale;
	bool sp430;
	struct environment *env;

	sp430 = false;
	env = envGetCurrent();

	if (!env->clouds_enabled || g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
		if (PLAYERCOUNT() == 1) {
			gDPSetCycleType(gdl++, G_CYC_FILL);

			if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
				gdl = viSetFillColour(gdl, 0, 0, 0);
			} else {
				gdl = viSetFillColour(gdl, env->sky_r, env->sky_g, env->sky_b);
			}

			gDPFillRectangle(gdl++, viGetViewLeft(), viGetViewTop(),
					viGetViewLeft() + viGetViewWidth() - 1,
					viGetViewTop() + viGetViewHeight() - 1);

			gDPPipeSync(gdl++);
			return gdl;
		}

		gDPPipeSync(gdl++);
		gDPSetCycleType(gdl++, G_CYC_FILL);

		if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
			gdl = viSetFillColour(gdl, 0, 0, 0);
		} else {
			gdl = viSetFillColour(gdl, env->sky_r, env->sky_g, env->sky_b);
		}

		gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);

		gDPFillRectangle(gdl++,
				g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop,
				g_Vars.currentplayer->viewleft + g_Vars.currentplayer->viewwidth - 1,
				g_Vars.currentplayer->viewtop + g_Vars.currentplayer->viewheight - 1);

		gDPPipeSync(gdl++);
		return gdl;
	}

	gdl = viSetFillColour(gdl, env->sky_r, env->sky_g, env->sky_b);

	if (&sp6a4);

	sky0f11f000(0.0f, 0.0f, &sp6a4);
	sky0f11f000(camGetScreenWidth() - 0.1f, 0.0f, &sp698);
	sky0f11f000(0.0f, camGetScreenHeight() - 0.1f, &sp68c);
	sky0f11f000(camGetScreenWidth() - 0.1f, camGetScreenHeight() - 0.1f, &sp680);

	sp538 = sky0f11f07c(&sp6a4, &sp644, &sp58c);
	sp534 = sky0f11f07c(&sp698, &sp638, &sp588);
	sp530 = sky0f11f07c(&sp68c, &sp62c, &sp584);
	sp52c = sky0f11f07c(&sp680, &sp620, &sp580);

	sky0f11f1fc(&sp6a4, &sp5e4, &sp56c);
	sky0f11f1fc(&sp698, &sp5d8, &sp568);
	sky0f11f1fc(&sp68c, &sp5cc, &sp564);
	sky0f11f1fc(&sp680, &sp5c0, &sp560);

	if (sp538 != sp530) {
		sp54c = camGetScreenTop() + camGetScreenHeight() * (sp6a4.f[1] / (sp6a4.f[1] - sp68c.f[1]));

		sky0f11f000(0.0f, sp54c, &sp65c);
		sky0f11f384(&sp6a4, &sp68c, &sp65c);
		sky0f11f07c(&sp65c, &sp5fc, &sp574);
		sky0f11f1fc(&sp65c, &sp59c, &sp554);
	} else {
		sp54c = 0.0f;
	}

	if (sp534 != sp52c) {
		sp548 = camGetScreenTop() + camGetScreenHeight() * (sp698.f[1] / (sp698.f[1] - sp680.f[1]));

		sky0f11f000(camGetScreenWidth() - 0.1f, sp548, &sp650);
		sky0f11f384(&sp698, &sp680, &sp650);
		sky0f11f07c(&sp650, &sp5f0, &sp570);
		sky0f11f1fc(&sp650, &sp590, &sp550);
	} else {
		sp548 = 0.0f;
	}

	if (sp538 != sp534) {
		sky0f11f000(camGetScreenLeft() + camGetScreenWidth() * (sp6a4.f[1] / (sp6a4.f[1] - sp698.f[1])), 0.0f, &sp674);
		sky0f11f384(&sp6a4, &sp698, &sp674);
		sky0f11f07c(&sp674, &sp614, &sp57c);
		sky0f11f1fc(&sp674, &sp5b4, &sp55c);
	}

	if (sp530 != sp52c) {
		tmp = camGetScreenLeft() + camGetScreenWidth() * (sp68c.f[1] / (sp68c.f[1] - sp680.f[1]));

		sky0f11f000(tmp, camGetScreenHeight() - 0.1f, &sp668);
		sky0f11f384(&sp68c, &sp680, &sp668);
		sky0f11f07c(&sp668, &sp608, &sp578);
		sky0f11f1fc(&sp668, &sp5a8, &sp558);
	}

	switch ((sp538 << 3) | (sp534 << 2) | (sp530 << 1) | sp52c) {
	case 15:
		s1 = 0;
		scale = 0.033333335f;
		break;
	case 0:
		s1 = 4;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5e4.f[0] * scale;
		sp43c[0].unk04 = sp5e4.f[1] * scale;
		sp43c[0].unk08 = sp5e4.f[2] * scale;
		sp43c[1].unk00 = sp5d8.f[0] * scale;
		sp43c[1].unk04 = sp5d8.f[1] * scale;
		sp43c[1].unk08 = sp5d8.f[2] * scale;
		sp43c[2].unk00 = sp5cc.f[0] * scale;
		sp43c[2].unk04 = sp5cc.f[1] * scale;
		sp43c[2].unk08 = sp5cc.f[2] * scale;
		sp43c[3].unk00 = sp5c0.f[0] * scale;
		sp43c[3].unk04 = sp5c0.f[1] * scale;
		sp43c[3].unk08 = sp5c0.f[2] * scale;
		sp43c[0].unk0c = sp5e4.f[0];
		sp43c[0].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp5d8.f[0];
		sp43c[1].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp5cc.f[0];
		sp43c[2].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
		sp43c[3].unk0c = sp5c0.f[0];
		sp43c[3].unk10 = sp5c0.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp56c);
		sky0f11f6ec(&sp43c[1], sp568);
		sky0f11f6ec(&sp43c[2], sp564);
		sky0f11f6ec(&sp43c[3], sp560);
		break;
	case 3:
		s1 = 4;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5e4.f[0] * scale;
		sp43c[0].unk04 = sp5e4.f[1] * scale;
		sp43c[0].unk08 = sp5e4.f[2] * scale;
		sp43c[1].unk00 = sp5d8.f[0] * scale;
		sp43c[1].unk04 = sp5d8.f[1] * scale;
		sp43c[1].unk08 = sp5d8.f[2] * scale;
		sp43c[2].unk00 = sp59c.f[0] * scale;
		sp43c[2].unk04 = sp59c.f[1] * scale;
		sp43c[2].unk08 = sp59c.f[2] * scale;
		sp43c[3].unk00 = sp590.f[0] * scale;
		sp43c[3].unk04 = sp590.f[1] * scale;
		sp43c[3].unk08 = sp590.f[2] * scale;
		sp43c[0].unk0c = sp5e4.f[0];
		sp43c[0].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp5d8.f[0];
		sp43c[1].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp59c.f[0];
		sp43c[2].unk10 = sp59c.f[2] + g_SkyCloudOffset;
		sp43c[3].unk0c = sp590.f[0];
		sp43c[3].unk10 = sp590.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp56c);
		sky0f11f6ec(&sp43c[1], sp568);
		sky0f11f6ec(&sp43c[2], sp554);
		sky0f11f6ec(&sp43c[3], sp550);
		break;
	case 12:
		s1 = 4;
		sp430 = true;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5c0.f[0] * scale;
		sp43c[0].unk04 = sp5c0.f[1] * scale;
		sp43c[0].unk08 = sp5c0.f[2] * scale;
		sp43c[1].unk00 = sp5cc.f[0] * scale;
		sp43c[1].unk04 = sp5cc.f[1] * scale;
		sp43c[1].unk08 = sp5cc.f[2] * scale;
		sp43c[2].unk00 = sp590.f[0] * scale;
		sp43c[2].unk04 = sp590.f[1] * scale;
		sp43c[2].unk08 = sp590.f[2] * scale;
		sp43c[3].unk00 = sp59c.f[0] * scale;
		sp43c[3].unk04 = sp59c.f[1] * scale;
		sp43c[3].unk08 = sp59c.f[2] * scale;
		sp43c[0].unk0c = sp5c0.f[0];
		sp43c[0].unk10 = sp5c0.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp5cc.f[0];
		sp43c[1].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp590.f[0];
		sp43c[2].unk10 = sp590.f[2] + g_SkyCloudOffset;
		sp43c[3].unk0c = sp59c.f[0];
		sp43c[3].unk10 = sp59c.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp560);
		sky0f11f6ec(&sp43c[1], sp564);
		sky0f11f6ec(&sp43c[2], sp550);
		sky0f11f6ec(&sp43c[3], sp554);
		break;
	case 10:
		s1 = 4;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5d8.f[0] * scale;
		sp43c[0].unk04 = sp5d8.f[1] * scale;
		sp43c[0].unk08 = sp5d8.f[2] * scale;
		sp43c[1].unk00 = sp5c0.f[0] * scale;
		sp43c[1].unk04 = sp5c0.f[1] * scale;
		sp43c[1].unk08 = sp5c0.f[2] * scale;
		sp43c[2].unk00 = sp5b4.f[0] * scale;
		sp43c[2].unk04 = sp5b4.f[1] * scale;
		sp43c[2].unk08 = sp5b4.f[2] * scale;
		sp43c[3].unk00 = sp5a8.f[0] * scale;
		sp43c[3].unk04 = sp5a8.f[1] * scale;
		sp43c[3].unk08 = sp5a8.f[2] * scale;
		sp43c[0].unk0c = sp5d8.f[0];
		sp43c[0].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp5c0.f[0];
		sp43c[1].unk10 = sp5c0.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp5b4.f[0];
		sp43c[2].unk10 = sp5b4.f[2] + g_SkyCloudOffset;
		sp43c[3].unk0c = sp5a8.f[0];
		sp43c[3].unk10 = sp5a8.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp568);
		sky0f11f6ec(&sp43c[1], sp560);
		sky0f11f6ec(&sp43c[2], sp55c);
		sky0f11f6ec(&sp43c[3], sp558);
		break;
	case 5:
		s1 = 4;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5cc.f[0] * scale;
		sp43c[0].unk04 = sp5cc.f[1] * scale;
		sp43c[0].unk08 = sp5cc.f[2] * scale;
		sp43c[1].unk00 = sp5e4.f[0] * scale;
		sp43c[1].unk04 = sp5e4.f[1] * scale;
		sp43c[1].unk08 = sp5e4.f[2] * scale;
		sp43c[2].unk00 = sp5a8.f[0] * scale;
		sp43c[2].unk04 = sp5a8.f[1] * scale;
		sp43c[2].unk08 = sp5a8.f[2] * scale;
		sp43c[3].unk00 = sp5b4.f[0] * scale;
		sp43c[3].unk04 = sp5b4.f[1] * scale;
		sp43c[3].unk08 = sp5b4.f[2] * scale;
		sp43c[0].unk0c = sp5cc.f[0];
		sp43c[0].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp5e4.f[0];
		sp43c[1].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp5a8.f[0];
		sp43c[2].unk10 = sp5a8.f[2] + g_SkyCloudOffset;
		sp43c[3].unk0c = sp5b4.f[0];
		sp43c[3].unk10 = sp5b4.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp564);
		sky0f11f6ec(&sp43c[1], sp56c);
		sky0f11f6ec(&sp43c[2], sp558);
		sky0f11f6ec(&sp43c[3], sp55c);
		break;
	case 14:
		s1 = 3;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5c0.f[0] * scale;
		sp43c[0].unk04 = sp5c0.f[1] * scale;
		sp43c[0].unk08 = sp5c0.f[2] * scale;
		sp43c[1].unk00 = sp5a8.f[0] * scale;
		sp43c[1].unk04 = sp5a8.f[1] * scale;
		sp43c[1].unk08 = sp5a8.f[2] * scale;
		sp43c[2].unk00 = sp590.f[0] * scale;
		sp43c[2].unk04 = sp590.f[1] * scale;
		sp43c[2].unk08 = sp590.f[2] * scale;
		sp43c[0].unk0c = sp5c0.f[0];
		sp43c[0].unk10 = sp5c0.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp5a8.f[0];
		sp43c[1].unk10 = sp5a8.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp590.f[0];
		sp43c[2].unk10 = sp590.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp560);
		sky0f11f6ec(&sp43c[1], sp558);
		sky0f11f6ec(&sp43c[2], sp550);
		break;
	case 13:
		s1 = 3;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5cc.f[0] * scale;
		sp43c[0].unk04 = sp5cc.f[1] * scale;
		sp43c[0].unk08 = sp5cc.f[2] * scale;
		sp43c[1].unk00 = sp59c.f[0] * scale;
		sp43c[1].unk04 = sp59c.f[1] * scale;
		sp43c[1].unk08 = sp59c.f[2] * scale;
		sp43c[2].unk00 = sp5a8.f[0] * scale;
		sp43c[2].unk04 = sp5a8.f[1] * scale;
		sp43c[2].unk08 = sp5a8.f[2] * scale;
		sp43c[0].unk0c = sp5cc.f[0];
		sp43c[0].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp59c.f[0];
		sp43c[1].unk10 = sp59c.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp5a8.f[0];
		sp43c[2].unk10 = sp5a8.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp564);
		sky0f11f6ec(&sp43c[1], sp554);
		sky0f11f6ec(&sp43c[2], sp558);
		break;
	case 11:
		s1 = 3;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5d8.f[0] * scale;
		sp43c[0].unk04 = sp5d8.f[1] * scale;
		sp43c[0].unk08 = sp5d8.f[2] * scale;
		sp43c[1].unk00 = sp590.f[0] * scale;
		sp43c[1].unk04 = sp590.f[1] * scale;
		sp43c[1].unk08 = sp590.f[2] * scale;
		sp43c[2].unk00 = sp5b4.f[0] * scale;
		sp43c[2].unk04 = sp5b4.f[1] * scale;
		sp43c[2].unk08 = sp5b4.f[2] * scale;
		sp43c[0].unk0c = sp5d8.f[0];
		sp43c[0].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp590.f[0];
		sp43c[1].unk10 = sp590.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp5b4.f[0];
		sp43c[2].unk10 = sp5b4.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp568);
		sky0f11f6ec(&sp43c[1], sp550);
		sky0f11f6ec(&sp43c[2], sp55c);
		break;
	case 7:
		s1 = 3;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5e4.f[0] * scale;
		sp43c[0].unk04 = sp5e4.f[1] * scale;
		sp43c[0].unk08 = sp5e4.f[2] * scale;
		sp43c[1].unk00 = sp5b4.f[0] * scale;
		sp43c[1].unk04 = sp5b4.f[1] * scale;
		sp43c[1].unk08 = sp5b4.f[2] * scale;
		sp43c[2].unk00 = sp59c.f[0] * scale;
		sp43c[2].unk04 = sp59c.f[1] * scale;
		sp43c[2].unk08 = sp59c.f[2] * scale;
		sp43c[0].unk0c = sp5e4.f[0];
		sp43c[0].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp5b4.f[0];
		sp43c[1].unk10 = sp5b4.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp59c.f[0];
		sp43c[2].unk10 = sp59c.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp56c);
		sky0f11f6ec(&sp43c[1], sp55c);
		sky0f11f6ec(&sp43c[2], sp554);
		break;
	case 1:
		s1 = 5;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5cc.f[0] * scale;
		sp43c[0].unk04 = sp5cc.f[1] * scale;
		sp43c[0].unk08 = sp5cc.f[2] * scale;
		sp43c[1].unk00 = sp5e4.f[0] * scale;
		sp43c[1].unk04 = sp5e4.f[1] * scale;
		sp43c[1].unk08 = sp5e4.f[2] * scale;
		sp43c[2].unk00 = sp5d8.f[0] * scale;
		sp43c[2].unk04 = sp5d8.f[1] * scale;
		sp43c[2].unk08 = sp5d8.f[2] * scale;
		sp43c[3].unk00 = sp590.f[0] * scale;
		sp43c[3].unk04 = sp590.f[1] * scale;
		sp43c[3].unk08 = sp590.f[2] * scale;
		sp43c[4].unk00 = sp5a8.f[0] * scale;
		sp43c[4].unk04 = sp5a8.f[1] * scale;
		sp43c[4].unk08 = sp5a8.f[2] * scale;
		sp43c[0].unk0c = sp5cc.f[0];
		sp43c[0].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp5e4.f[0];
		sp43c[1].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp5d8.f[0];
		sp43c[2].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
		sp43c[3].unk0c = sp590.f[0];
		sp43c[3].unk10 = sp590.f[2] + g_SkyCloudOffset;
		sp43c[4].unk0c = sp5a8.f[0];
		sp43c[4].unk10 = sp5a8.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp564);
		sky0f11f6ec(&sp43c[1], sp56c);
		sky0f11f6ec(&sp43c[2], sp568);
		sky0f11f6ec(&sp43c[3], sp550);
		sky0f11f6ec(&sp43c[4], sp558);
		break;
	case 2:
		s1 = 5;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5e4.f[0] * scale;
		sp43c[0].unk04 = sp5e4.f[1] * scale;
		sp43c[0].unk08 = sp5e4.f[2] * scale;
		sp43c[1].unk00 = sp5d8.f[0] * scale;
		sp43c[1].unk04 = sp5d8.f[1] * scale;
		sp43c[1].unk08 = sp5d8.f[2] * scale;
		sp43c[2].unk00 = sp5c0.f[0] * scale;
		sp43c[2].unk04 = sp5c0.f[1] * scale;
		sp43c[2].unk08 = sp5c0.f[2] * scale;
		sp43c[3].unk00 = sp5a8.f[0] * scale;
		sp43c[3].unk04 = sp5a8.f[1] * scale;
		sp43c[3].unk08 = sp5a8.f[2] * scale;
		sp43c[4].unk00 = sp59c.f[0] * scale;
		sp43c[4].unk04 = sp59c.f[1] * scale;
		sp43c[4].unk08 = sp59c.f[2] * scale;
		sp43c[0].unk0c = sp5e4.f[0];
		sp43c[0].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp5d8.f[0];
		sp43c[1].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp5c0.f[0];
		sp43c[2].unk10 = sp5c0.f[2] + g_SkyCloudOffset;
		sp43c[3].unk0c = sp5a8.f[0];
		sp43c[3].unk10 = sp5a8.f[2] + g_SkyCloudOffset;
		sp43c[4].unk0c = sp59c.f[0];
		sp43c[4].unk10 = sp59c.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp56c);
		sky0f11f6ec(&sp43c[1], sp568);
		sky0f11f6ec(&sp43c[2], sp560);
		sky0f11f6ec(&sp43c[3], sp558);
		sky0f11f6ec(&sp43c[4], sp554);
		break;
	case 4:
		s1 = 5;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5c0.f[0] * scale;
		sp43c[0].unk04 = sp5c0.f[1] * scale;
		sp43c[0].unk08 = sp5c0.f[2] * scale;
		sp43c[1].unk00 = sp5cc.f[0] * scale;
		sp43c[1].unk04 = sp5cc.f[1] * scale;
		sp43c[1].unk08 = sp5cc.f[2] * scale;
		sp43c[2].unk00 = sp5e4.f[0] * scale;
		sp43c[2].unk04 = sp5e4.f[1] * scale;
		sp43c[2].unk08 = sp5e4.f[2] * scale;
		sp43c[3].unk00 = sp5b4.f[0] * scale;
		sp43c[3].unk04 = sp5b4.f[1] * scale;
		sp43c[3].unk08 = sp5b4.f[2] * scale;
		sp43c[4].unk00 = sp590.f[0] * scale;
		sp43c[4].unk04 = sp590.f[1] * scale;
		sp43c[4].unk08 = sp590.f[2] * scale;
		sp43c[0].unk0c = sp5c0.f[0];
		sp43c[0].unk10 = sp5c0.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp5cc.f[0];
		sp43c[1].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp5e4.f[0];
		sp43c[2].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
		sp43c[3].unk0c = sp5b4.f[0];
		sp43c[3].unk10 = sp5b4.f[2] + g_SkyCloudOffset;
		sp43c[4].unk0c = sp590.f[0];
		sp43c[4].unk10 = sp590.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp560);
		sky0f11f6ec(&sp43c[1], sp564);
		sky0f11f6ec(&sp43c[2], sp56c);
		sky0f11f6ec(&sp43c[3], sp55c);
		sky0f11f6ec(&sp43c[4], sp550);
		break;
	case 8:
		s1 = 5;
		scale = 0.033333335f;
		sp43c[0].unk00 = sp5d8.f[0] * scale;
		sp43c[0].unk04 = sp5d8.f[1] * scale;
		sp43c[0].unk08 = sp5d8.f[2] * scale;
		sp43c[1].unk00 = sp5c0.f[0] * scale;
		sp43c[1].unk04 = sp5c0.f[1] * scale;
		sp43c[1].unk08 = sp5c0.f[2] * scale;
		sp43c[2].unk00 = sp5cc.f[0] * scale;
		sp43c[2].unk04 = sp5cc.f[1] * scale;
		sp43c[2].unk08 = sp5cc.f[2] * scale;
		sp43c[3].unk00 = sp59c.f[0] * scale;
		sp43c[3].unk04 = sp59c.f[1] * scale;
		sp43c[3].unk08 = sp59c.f[2] * scale;
		sp43c[4].unk00 = sp5b4.f[0] * scale;
		sp43c[4].unk04 = sp5b4.f[1] * scale;
		sp43c[4].unk08 = sp5b4.f[2] * scale;
		sp43c[0].unk0c = sp5d8.f[0];
		sp43c[0].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
		sp43c[1].unk0c = sp5c0.f[0];
		sp43c[1].unk10 = sp5c0.f[2] + g_SkyCloudOffset;
		sp43c[2].unk0c = sp5cc.f[0];
		sp43c[2].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
		sp43c[3].unk0c = sp59c.f[0];
		sp43c[3].unk10 = sp59c.f[2] + g_SkyCloudOffset;
		sp43c[4].unk0c = sp5b4.f[0];
		sp43c[4].unk10 = sp5b4.f[2] + g_SkyCloudOffset;

		sky0f11f6ec(&sp43c[0], sp568);
		sky0f11f6ec(&sp43c[1], sp560);
		sky0f11f6ec(&sp43c[2], sp564);
		sky0f11f6ec(&sp43c[3], sp554);
		sky0f11f6ec(&sp43c[4], sp55c);
		break;
	default:
		return gdl;
	}

	if (s1 > 0) {
		Mtxf sp3cc;
		Mtxf sp38c;
		struct skything38 sp274[5];
		s32 i;

		mtx4MultMtx4(camGetMtxF1754(), camGetWorldToScreenMtxf(), &sp3cc);
		guScaleF(var800a33a8.m, 1.0f / scale, 1.0f / scale, 1.0f / scale);
		mtx4MultMtx4(&sp3cc, &var800a33a8, &sp38c);

		for (i = 0; i < s1; i++) {
			sky0f1228d0(&sp43c[i], &sp38c, 130, 65535.0f, 65535.0f, &sp274[i]);

			sp274[i].unk28 = skyClamp(sp274[i].unk28, camGetScreenLeft() * 4.0f, (camGetScreenLeft() + camGetScreenWidth()) * 4.0f - 1.0f);
			sp274[i].unk2c = skyClamp(sp274[i].unk2c, camGetScreenTop() * 4.0f, (camGetScreenTop() + camGetScreenHeight()) * 4.0f - 1.0f);

			if (sp274[i].unk2c > camGetScreenTop() * 4.0f + 4.0f
					&& sp274[i].unk2c < (camGetScreenTop() + camGetScreenHeight()) * 4.0f - 4.0f) {
				sp274[i].unk2c -= 4.0f;
			}
		}

		if (!env->water_enabled) {
			f32 f14 = 1279.0f;
			f32 f16 = 959.0f;
			f32 f2 = 0.0f;
			f32 f12 = 0.0f;

			for (j = 0; j < s1; j++) {
				if (sp274[j].unk28 < f14) {
					f14 = sp274[j].unk28;
				}

				if (sp274[j].unk28 > f2) {
					f2 = sp274[j].unk28;
				}

				if (sp274[j].unk2c < f16) {
					f16 = sp274[j].unk2c;
				}

				if (sp274[j].unk2c > f12) {
					f12 = sp274[j].unk2c;
				}
			}

			gDPPipeSync(gdl++);
			gDPSetCycleType(gdl++, G_CYC_FILL);
			gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
			gDPSetTexturePersp(gdl++, G_TP_NONE);
			gDPFillRectangle(gdl++, (s32)(f14 * 0.25f), (s32)(f16 * 0.25f), (s32)(f2 * 0.25f), (s32)(f12 * 0.25f));
			gDPPipeSync(gdl++);
			gDPSetTexturePersp(gdl++, G_TP_PERSP);
		} else {
			gDPPipeSync(gdl++);

			texSelect(&gdl, &g_TexWaterConfigs[env->water_type], 1, 0, 2, 1, NULL);

			gDPSetRenderMode(gdl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

			if (s1 == 4) {
				gdl = sky0f122d4c(gdl, &sp274[0], &sp274[1], &sp274[3], 130.0f, true);

				if (sp430) {
					sp274[0].unk2c++;
					sp274[1].unk2c++;
					sp274[2].unk2c++;
					sp274[3].unk2c++;
				}

				gdl = sky0f122d4c(gdl, &sp274[3], &sp274[2], &sp274[0], 130.0f, true);
			} else if (s1 == 5) {
				gdl = sky0f122d4c(gdl, &sp274[0], &sp274[1], &sp274[2], 130.0f, true);
				gdl = sky0f122d4c(gdl, &sp274[0], &sp274[2], &sp274[3], 130.0f, true);
				gdl = sky0f122d4c(gdl, &sp274[0], &sp274[3], &sp274[4], 130.0f, true);
			} else if (s1 == 3) {
				gdl = sky0f122d4c(gdl, &sp274[0], &sp274[1], &sp274[2], 130.0f, true);
			}
		}
	}

	switch ((sp538 << 3) | (sp534 << 2) | (sp530 << 1) | sp52c) {
	case 0:
		return gdl;
	case 15:
		s1 = 4;
		sp4b4[0].unk00 = sp644.f[0] * scale;
		sp4b4[0].unk04 = sp644.f[1] * scale;
		sp4b4[0].unk08 = sp644.f[2] * scale;
		sp4b4[1].unk00 = sp638.f[0] * scale;
		sp4b4[1].unk04 = sp638.f[1] * scale;
		sp4b4[1].unk08 = sp638.f[2] * scale;
		sp4b4[2].unk00 = sp62c.f[0] * scale;
		sp4b4[2].unk04 = sp62c.f[1] * scale;
		sp4b4[2].unk08 = sp62c.f[2] * scale;
		sp4b4[3].unk00 = sp620.f[0] * scale;
		sp4b4[3].unk04 = sp620.f[1] * scale;
		sp4b4[3].unk08 = sp620.f[2] * scale;
		sp4b4[0].unk0c = sp644.f[0] * 0.1f;
		sp4b4[0].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp638.f[0] * 0.1f;
		sp4b4[1].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp62c.f[0] * 0.1f;
		sp4b4[2].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[3].unk0c = sp620.f[0] * 0.1f;
		sp4b4[3].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp58c);
		skyChooseCloudVtxColour(&sp4b4[1], sp588);
		skyChooseCloudVtxColour(&sp4b4[2], sp584);
		skyChooseCloudVtxColour(&sp4b4[3], sp580);
		break;
	case 12:
		s1 = 4;
		sp4b4[0].unk00 = sp644.f[0] * scale;
		sp4b4[0].unk04 = sp644.f[1] * scale;
		sp4b4[0].unk08 = sp644.f[2] * scale;
		sp4b4[1].unk00 = sp638.f[0] * scale;
		sp4b4[1].unk04 = sp638.f[1] * scale;
		sp4b4[1].unk08 = sp638.f[2] * scale;
		sp4b4[2].unk00 = sp5fc.f[0] * scale;
		sp4b4[2].unk04 = sp5fc.f[1] * scale;
		sp4b4[2].unk08 = sp5fc.f[2] * scale;
		sp4b4[3].unk00 = sp5f0.f[0] * scale;
		sp4b4[3].unk04 = sp5f0.f[1] * scale;
		sp4b4[3].unk08 = sp5f0.f[2] * scale;
		sp4b4[0].unk0c = sp644.f[0] * 0.1f;
		sp4b4[0].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp638.f[0] * 0.1f;
		sp4b4[1].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp5fc.f[0] * 0.1f;
		sp4b4[2].unk10 = sp5fc.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[3].unk0c = sp5f0.f[0] * 0.1f;
		sp4b4[3].unk10 = sp5f0.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp58c);
		skyChooseCloudVtxColour(&sp4b4[1], sp588);
		skyChooseCloudVtxColour(&sp4b4[2], sp574);
		skyChooseCloudVtxColour(&sp4b4[3], sp570);
		break;
	case 3:
		s1 = 4;
		sp4b4[0].unk00 = sp620.f[0] * scale;
		sp4b4[0].unk04 = sp620.f[1] * scale;
		sp4b4[0].unk08 = sp620.f[2] * scale;
		sp4b4[1].unk00 = sp62c.f[0] * scale;
		sp4b4[1].unk04 = sp62c.f[1] * scale;
		sp4b4[1].unk08 = sp62c.f[2] * scale;
		sp4b4[2].unk00 = sp5f0.f[0] * scale;
		sp4b4[2].unk04 = sp5f0.f[1] * scale;
		sp4b4[2].unk08 = sp5f0.f[2] * scale;
		sp4b4[3].unk00 = sp5fc.f[0] * scale;
		sp4b4[3].unk04 = sp5fc.f[1] * scale;
		sp4b4[3].unk08 = sp5fc.f[2] * scale;
		sp4b4[0].unk0c = sp620.f[0] * 0.1f;
		sp4b4[0].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp62c.f[0] * 0.1f;
		sp4b4[1].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp5f0.f[0] * 0.1f;
		sp4b4[2].unk10 = sp5f0.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[3].unk0c = sp5fc.f[0] * 0.1f;
		sp4b4[3].unk10 = sp5fc.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp580);
		skyChooseCloudVtxColour(&sp4b4[1], sp584);
		skyChooseCloudVtxColour(&sp4b4[2], sp570);
		skyChooseCloudVtxColour(&sp4b4[3], sp574);
		break;
	case 5:
		s1 = 4;
		sp4b4[0].unk00 = sp638.f[0] * scale;
		sp4b4[0].unk04 = sp638.f[1] * scale;
		sp4b4[0].unk08 = sp638.f[2] * scale;
		sp4b4[1].unk00 = sp620.f[0] * scale;
		sp4b4[1].unk04 = sp620.f[1] * scale;
		sp4b4[1].unk08 = sp620.f[2] * scale;
		sp4b4[2].unk00 = sp614.f[0] * scale;
		sp4b4[2].unk04 = sp614.f[1] * scale;
		sp4b4[2].unk08 = sp614.f[2] * scale;
		sp4b4[3].unk00 = sp608.f[0] * scale;
		sp4b4[3].unk04 = sp608.f[1] * scale;
		sp4b4[3].unk08 = sp608.f[2] * scale;
		sp4b4[0].unk0c = sp638.f[0] * 0.1f;
		sp4b4[0].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp620.f[0] * 0.1f;
		sp4b4[1].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp614.f[0] * 0.1f;
		sp4b4[2].unk10 = sp614.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[3].unk0c = sp608.f[0] * 0.1f;
		sp4b4[3].unk10 = sp608.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp588);
		skyChooseCloudVtxColour(&sp4b4[1], sp580);
		skyChooseCloudVtxColour(&sp4b4[2], sp57c);
		skyChooseCloudVtxColour(&sp4b4[3], sp578);
		break;
	case 10:
		s1 = 4;
		sp4b4[0].unk00 = sp62c.f[0] * scale;
		sp4b4[0].unk04 = sp62c.f[1] * scale;
		sp4b4[0].unk08 = sp62c.f[2] * scale;
		sp4b4[1].unk00 = sp644.f[0] * scale;
		sp4b4[1].unk04 = sp644.f[1] * scale;
		sp4b4[1].unk08 = sp644.f[2] * scale;
		sp4b4[2].unk00 = sp608.f[0] * scale;
		sp4b4[2].unk04 = sp608.f[1] * scale;
		sp4b4[2].unk08 = sp608.f[2] * scale;
		sp4b4[3].unk00 = sp614.f[0] * scale;
		sp4b4[3].unk04 = sp614.f[1] * scale;
		sp4b4[3].unk08 = sp614.f[2] * scale;
		sp4b4[0].unk0c = sp62c.f[0] * 0.1f;
		sp4b4[0].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp644.f[0] * 0.1f;
		sp4b4[1].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp608.f[0] * 0.1f;
		sp4b4[2].unk10 = sp608.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[3].unk0c = sp614.f[0] * 0.1f;
		sp4b4[3].unk10 = sp614.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp584);
		skyChooseCloudVtxColour(&sp4b4[1], sp58c);
		skyChooseCloudVtxColour(&sp4b4[2], sp578);
		skyChooseCloudVtxColour(&sp4b4[3], sp57c);
		break;
	case 1:
		s1 = 3;
		sp4b4[0].unk00 = sp620.f[0] * scale;
		sp4b4[0].unk04 = sp620.f[1] * scale;
		sp4b4[0].unk08 = sp620.f[2] * scale;
		sp4b4[1].unk00 = sp608.f[0] * scale;
		sp4b4[1].unk04 = sp608.f[1] * scale;
		sp4b4[1].unk08 = sp608.f[2] * scale;
		sp4b4[2].unk00 = sp5f0.f[0] * scale;
		sp4b4[2].unk04 = sp5f0.f[1] * scale;
		sp4b4[2].unk08 = sp5f0.f[2] * scale;
		sp4b4[0].unk0c = sp620.f[0] * 0.1f;
		sp4b4[0].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp608.f[0] * 0.1f;
		sp4b4[1].unk10 = sp608.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp5f0.f[0] * 0.1f;
		sp4b4[2].unk10 = sp5f0.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp580);
		skyChooseCloudVtxColour(&sp4b4[1], sp578);
		skyChooseCloudVtxColour(&sp4b4[2], sp570);
		break;
	case 2:
		s1 = 3;
		sp4b4[0].unk00 = sp62c.f[0] * scale;
		sp4b4[0].unk04 = sp62c.f[1] * scale;
		sp4b4[0].unk08 = sp62c.f[2] * scale;
		sp4b4[1].unk00 = sp5fc.f[0] * scale;
		sp4b4[1].unk04 = sp5fc.f[1] * scale;
		sp4b4[1].unk08 = sp5fc.f[2] * scale;
		sp4b4[2].unk00 = sp608.f[0] * scale;
		sp4b4[2].unk04 = sp608.f[1] * scale;
		sp4b4[2].unk08 = sp608.f[2] * scale;
		sp4b4[0].unk0c = sp62c.f[0] * 0.1f;
		sp4b4[0].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp5fc.f[0] * 0.1f;
		sp4b4[1].unk10 = sp5fc.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp608.f[0] * 0.1f;
		sp4b4[2].unk10 = sp608.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp584);
		skyChooseCloudVtxColour(&sp4b4[1], sp574);
		skyChooseCloudVtxColour(&sp4b4[2], sp578);
		break;
	case 4:
		s1 = 3;
		sp4b4[0].unk00 = sp638.f[0] * scale;
		sp4b4[0].unk04 = sp638.f[1] * scale;
		sp4b4[0].unk08 = sp638.f[2] * scale;
		sp4b4[1].unk00 = sp5f0.f[0] * scale;
		sp4b4[1].unk04 = sp5f0.f[1] * scale;
		sp4b4[1].unk08 = sp5f0.f[2] * scale;
		sp4b4[2].unk00 = sp614.f[0] * scale;
		sp4b4[2].unk04 = sp614.f[1] * scale;
		sp4b4[2].unk08 = sp614.f[2] * scale;
		sp4b4[0].unk0c = sp638.f[0] * 0.1f;
		sp4b4[0].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp5f0.f[0] * 0.1f;
		sp4b4[1].unk10 = sp5f0.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp614.f[0] * 0.1f;
		sp4b4[2].unk10 = sp614.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp588);
		skyChooseCloudVtxColour(&sp4b4[1], sp570);
		skyChooseCloudVtxColour(&sp4b4[2], sp57c);
		break;
	case 8:
		s1 = 3;
		sp4b4[0].unk00 = sp644.f[0] * scale;
		sp4b4[0].unk04 = sp644.f[1] * scale;
		sp4b4[0].unk08 = sp644.f[2] * scale;
		sp4b4[1].unk00 = sp614.f[0] * scale;
		sp4b4[1].unk04 = sp614.f[1] * scale;
		sp4b4[1].unk08 = sp614.f[2] * scale;
		sp4b4[2].unk00 = sp5fc.f[0] * scale;
		sp4b4[2].unk04 = sp5fc.f[1] * scale;
		sp4b4[2].unk08 = sp5fc.f[2] * scale;
		sp4b4[0].unk0c = sp644.f[0] * 0.1f;
		sp4b4[0].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp614.f[0] * 0.1f;
		sp4b4[1].unk10 = sp614.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp5fc.f[0] * 0.1f;
		sp4b4[2].unk10 = sp5fc.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp58c);
		skyChooseCloudVtxColour(&sp4b4[1], sp57c);
		skyChooseCloudVtxColour(&sp4b4[2], sp574);
		break;
	case 14:
		s1 = 5;
		sp4b4[0].unk00 = sp62c.f[0] * scale;
		sp4b4[0].unk04 = sp62c.f[1] * scale;
		sp4b4[0].unk08 = sp62c.f[2] * scale;
		sp4b4[1].unk00 = sp644.f[0] * scale;
		sp4b4[1].unk04 = sp644.f[1] * scale;
		sp4b4[1].unk08 = sp644.f[2] * scale;
		sp4b4[2].unk00 = sp638.f[0] * scale;
		sp4b4[2].unk04 = sp638.f[1] * scale;
		sp4b4[2].unk08 = sp638.f[2] * scale;
		sp4b4[3].unk00 = sp5f0.f[0] * scale;
		sp4b4[3].unk04 = sp5f0.f[1] * scale;
		sp4b4[3].unk08 = sp5f0.f[2] * scale;
		sp4b4[4].unk00 = sp608.f[0] * scale;
		sp4b4[4].unk04 = sp608.f[1] * scale;
		sp4b4[4].unk08 = sp608.f[2] * scale;
		sp4b4[0].unk0c = sp62c.f[0] * 0.1f;
		sp4b4[0].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp644.f[0] * 0.1f;
		sp4b4[1].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp638.f[0] * 0.1f;
		sp4b4[2].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[3].unk0c = sp5f0.f[0] * 0.1f;
		sp4b4[3].unk10 = sp5f0.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[4].unk0c = sp608.f[0] * 0.1f;
		sp4b4[4].unk10 = sp608.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp584);
		skyChooseCloudVtxColour(&sp4b4[1], sp58c);
		skyChooseCloudVtxColour(&sp4b4[2], sp588);
		skyChooseCloudVtxColour(&sp4b4[3], sp570);
		skyChooseCloudVtxColour(&sp4b4[4], sp578);
		break;
	case 13:
		s1 = 5;
		sp4b4[0].unk00 = sp644.f[0] * scale;
		sp4b4[0].unk04 = sp644.f[1] * scale;
		sp4b4[0].unk08 = sp644.f[2] * scale;
		sp4b4[1].unk00 = sp638.f[0] * scale;
		sp4b4[1].unk04 = sp638.f[1] * scale;
		sp4b4[1].unk08 = sp638.f[2] * scale;
		sp4b4[2].unk00 = sp620.f[0] * scale;
		sp4b4[2].unk04 = sp620.f[1] * scale;
		sp4b4[2].unk08 = sp620.f[2] * scale;
		sp4b4[3].unk00 = sp608.f[0] * scale;
		sp4b4[3].unk04 = sp608.f[1] * scale;
		sp4b4[3].unk08 = sp608.f[2] * scale;
		sp4b4[4].unk00 = sp5fc.f[0] * scale;
		sp4b4[4].unk04 = sp5fc.f[1] * scale;
		sp4b4[4].unk08 = sp5fc.f[2] * scale;
		sp4b4[0].unk0c = sp644.f[0] * 0.1f;
		sp4b4[0].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp638.f[0] * 0.1f;
		sp4b4[1].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp620.f[0] * 0.1f;
		sp4b4[2].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[3].unk0c = sp608.f[0] * 0.1f;
		sp4b4[3].unk10 = sp608.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[4].unk0c = sp5fc.f[0] * 0.1f;
		sp4b4[4].unk10 = sp5fc.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp58c);
		skyChooseCloudVtxColour(&sp4b4[1], sp588);
		skyChooseCloudVtxColour(&sp4b4[2], sp580);
		skyChooseCloudVtxColour(&sp4b4[3], sp578);
		skyChooseCloudVtxColour(&sp4b4[4], sp574);
		break;
	case 11:
		s1 = 5;
		sp4b4[0].unk00 = sp620.f[0] * scale;
		sp4b4[0].unk04 = sp620.f[1] * scale;
		sp4b4[0].unk08 = sp620.f[2] * scale;
		sp4b4[1].unk00 = sp62c.f[0] * scale;
		sp4b4[1].unk04 = sp62c.f[1] * scale;
		sp4b4[1].unk08 = sp62c.f[2] * scale;
		sp4b4[2].unk00 = sp644.f[0] * scale;
		sp4b4[2].unk04 = sp644.f[1] * scale;
		sp4b4[2].unk08 = sp644.f[2] * scale;
		sp4b4[3].unk00 = sp614.f[0] * scale;
		sp4b4[3].unk04 = sp614.f[1] * scale;
		sp4b4[3].unk08 = sp614.f[2] * scale;
		sp4b4[4].unk00 = sp5f0.f[0] * scale;
		sp4b4[4].unk04 = sp5f0.f[1] * scale;
		sp4b4[4].unk08 = sp5f0.f[2] * scale;
		sp4b4[0].unk0c = sp620.f[0] * 0.1f;
		sp4b4[0].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp62c.f[0] * 0.1f;
		sp4b4[1].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp644.f[0] * 0.1f;
		sp4b4[2].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[3].unk0c = sp614.f[0] * 0.1f;
		sp4b4[3].unk10 = sp614.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[4].unk0c = sp5f0.f[0] * 0.1f;
		sp4b4[4].unk10 = sp5f0.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp580);
		skyChooseCloudVtxColour(&sp4b4[1], sp584);
		skyChooseCloudVtxColour(&sp4b4[2], sp58c);
		skyChooseCloudVtxColour(&sp4b4[3], sp57c);
		skyChooseCloudVtxColour(&sp4b4[4], sp570);
		break;
	case 7:
		s1 = 5;
		sp4b4[0].unk00 = sp638.f[0] * scale;
		sp4b4[0].unk04 = sp638.f[1] * scale;
		sp4b4[0].unk08 = sp638.f[2] * scale;
		sp4b4[1].unk00 = sp620.f[0] * scale;
		sp4b4[1].unk04 = sp620.f[1] * scale;
		sp4b4[1].unk08 = sp620.f[2] * scale;
		sp4b4[2].unk00 = sp62c.f[0] * scale;
		sp4b4[2].unk04 = sp62c.f[1] * scale;
		sp4b4[2].unk08 = sp62c.f[2] * scale;
		sp4b4[3].unk00 = sp5fc.f[0] * scale;
		sp4b4[3].unk04 = sp5fc.f[1] * scale;
		sp4b4[3].unk08 = sp5fc.f[2] * scale;
		sp4b4[4].unk00 = sp614.f[0] * scale;
		sp4b4[4].unk04 = sp614.f[1] * scale;
		sp4b4[4].unk08 = sp614.f[2] * scale;
		sp4b4[0].unk0c = sp638.f[0] * 0.1f;
		sp4b4[0].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[1].unk0c = sp620.f[0] * 0.1f;
		sp4b4[1].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[2].unk0c = sp62c.f[0] * 0.1f;
		sp4b4[2].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[3].unk0c = sp5fc.f[0] * 0.1f;
		sp4b4[3].unk10 = sp5fc.f[2] * 0.1f + g_SkyCloudOffset;
		sp4b4[4].unk0c = sp614.f[0] * 0.1f;
		sp4b4[4].unk10 = sp614.f[2] * 0.1f + g_SkyCloudOffset;

		skyChooseCloudVtxColour(&sp4b4[0], sp588);
		skyChooseCloudVtxColour(&sp4b4[1], sp580);
		skyChooseCloudVtxColour(&sp4b4[2], sp584);
		skyChooseCloudVtxColour(&sp4b4[3], sp574);
		skyChooseCloudVtxColour(&sp4b4[4], sp57c);
		break;
	default:
		return gdl;
	}

	gDPPipeSync(gdl++);

	texSelect(&gdl, &g_TexWaterConfigs[env->unk18], 1, 0, 2, 1, NULL);

	if (1);

	gDPSetEnvColor(gdl++, env->sky_r, env->sky_g, env->sky_b, 0xff);
	gDPSetCombineLERP(gdl++,
			SHADE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, SHADE,
			SHADE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, SHADE);

	{
		s32 stack;
		Mtxf sp1ec;
		Mtxf sp1ac;
		struct skything38 sp94[5];
		s32 i;

		mtx4MultMtx4(camGetMtxF1754(), camGetWorldToScreenMtxf(), &sp1ec);
		guScaleF(var800a33a8.m, 1.0f / scale, 1.0f / scale, 1.0f / scale);
		mtx4MultMtx4(&sp1ec, &var800a33a8, &sp1ac);

		for (i = 0; i < s1; i++) {
			sky0f1228d0(&sp4b4[i], &sp1ac, 130, 65535.0f, 65535.0f, &sp94[i]);

			sp94[i].unk28 = skyClamp(sp94[i].unk28, camGetScreenLeft() * 4.0f, (camGetScreenLeft() + camGetScreenWidth()) * 4.0f - 1.0f);
			sp94[i].unk2c = skyClamp(sp94[i].unk2c, camGetScreenTop() * 4.0f, (camGetScreenTop() + camGetScreenHeight()) * 4.0f - 1.0f);
		}

		if (s1 == 4) {
			if (((sp538 << 3) | (sp534 << 2) | (sp530 << 1) | sp52c) == 12) {
				if (sp548 < sp54c) {
					if (sp94[3].unk2c >= sp94[1].unk2c + 4.0f) {
						sp94[0].unk28 = camGetScreenLeft() * 4.0f;
						sp94[0].unk2c = camGetScreenTop() * 4.0f;
						sp94[1].unk28 = (camGetScreenLeft() + camGetScreenWidth()) * 4.0f - 1.0f;
						sp94[1].unk2c = camGetScreenTop() * 4.0f;
						sp94[2].unk28 = camGetScreenLeft() * 4.0f;
						sp94[3].unk28 = (camGetScreenLeft() + camGetScreenWidth()) * 4.0f - 1.0f;

						gdl = sky0f123fd4(gdl, &sp94[0], &sp94[1], &sp94[2], &sp94[3], 130.0f);
					} else {
						gdl = sky0f122d4c(gdl, &sp94[0], &sp94[1], &sp94[2], 130.0f, true);
					}
				} else if (sp94[2].unk2c >= sp94[0].unk2c + 4.0f) {
					sp94[0].unk28 = camGetScreenLeft() * 4.0f;
					sp94[0].unk2c = camGetScreenTop() * 4.0f;
					sp94[1].unk28 = (camGetScreenLeft() + camGetScreenWidth()) * 4.0f - 1.0f;
					sp94[1].unk2c = camGetScreenTop() * 4.0f;
					sp94[2].unk28 = camGetScreenLeft() * 4.0f;
					sp94[3].unk28 = (camGetScreenLeft() + camGetScreenWidth()) * 4.0f - 1.0f;

					gdl = sky0f123fd4(gdl, &sp94[1], &sp94[0], &sp94[3], &sp94[2], 130.0f);
				} else {
					gdl = sky0f122d4c(gdl, &sp94[1], &sp94[0], &sp94[3], 130.0f, true);
				}
			} else {
				gdl = sky0f122d4c(gdl, &sp94[0], &sp94[1], &sp94[3], 130.0f, true);
				gdl = sky0f122d4c(gdl, &sp94[3], &sp94[2], &sp94[0], 130.0f, true);
			}
		} else if (s1 == 5) {
			gdl = sky0f122d4c(gdl, &sp94[0], &sp94[1], &sp94[2], 130.0f, true);
			gdl = sky0f122d4c(gdl, &sp94[0], &sp94[2], &sp94[3], 130.0f, true);
			gdl = sky0f122d4c(gdl, &sp94[0], &sp94[3], &sp94[4], 130.0f, true);
		} else if (s1 == 3) {
			gdl = sky0f122d4c(gdl, &sp94[0], &sp94[1], &sp94[2], 130.0f, true);
		}
	}

	return gdl;
}

void sky0f1228d0(struct skything18 *arg0, Mtxf *arg1, u16 arg2, f32 arg3, f32 arg4, struct skything38 *arg5)
{
	f32 sp68[4];
	f32 sp64;
	f32 sp60;
	f32 f22;
	f32 f0;
	f32 sp48[4];
	f32 sp38[4];
	f32 sp34;
	f32 sp30;
	f32 mult;

	mult = arg2 / 65536.0f;

	sp68[0] = (arg0->unk00 * arg1->m[0][0] + arg0->unk04 * arg1->m[1][0] + arg0->unk08 * arg1->m[2][0]) + arg1->m[3][0];
	sp68[1] = (arg0->unk00 * arg1->m[0][1] + arg0->unk04 * arg1->m[1][1] + arg0->unk08 * arg1->m[2][1]) + arg1->m[3][1];
	sp68[2] = (arg0->unk00 * arg1->m[0][2] + arg0->unk04 * arg1->m[1][2] + arg0->unk08 * arg1->m[2][2]) + arg1->m[3][2];
	sp68[3] = (arg0->unk00 * arg1->m[0][3] + arg0->unk04 * arg1->m[1][3] + arg0->unk08 * arg1->m[2][3]) + arg1->m[3][3];

	sp60 = arg0->unk0c * (arg3 * (1.0f / 65536.0f));
	sp64 = arg0->unk10 * (arg4 * (1.0f / 65536.0f));

	if (sp68[3] == 0.0f) {
		f22 = 32767.0f;
	} else {
		f22 = 1.0f / (sp68[3] * mult);
	}

	f0 = f22;

	if (f0 < 0.0f) {
		f0 = 32767.0f;
	}

	sp48[0] = sp68[0] * f0 * mult;
	sp48[1] = sp68[1] * f0 * mult;
	sp48[2] = sp68[2] * f0 * mult;
	sp48[3] = sp68[3] * f0 * mult;

	sp34 = camGetScreenWidth();
	sp30 = camGetScreenWidth();
	sp38[0] = sp48[0] * (sp34 + sp34) + (sp30 + sp30 + camGetScreenLeft() * 4);

	sp34 = camGetScreenHeight();
	sp30 = camGetScreenHeight();
	sp38[1] = -sp48[1] * (sp34 + sp34) + (sp30 + sp30 + camGetScreenTop() * 4);

	sp34 = 511.0f;
	sp30 = 511.0f;
	sp38[2] = sp48[2] * sp34 + sp30;

	sp34 = 0;
	sp30 = 0;
	sp38[3] = sp48[3] * sp34 + sp30;

	sp38[0] = skyClamp(sp38[0], -4090.0f, 4090.0f);
	sp38[1] = skyClamp(sp38[1], -4090.0f, 4090.0f);
	sp38[2] = skyClamp(sp38[2], 0.0f, 32767.0f);
	sp38[3] = skyClamp(sp38[3], 0.0f, 32767.0f);

	arg5->unk00 = sp68[0];
	arg5->unk04 = sp68[1];
	arg5->unk08 = sp68[2];
	arg5->unk0c = sp68[3];
	arg5->unk20 = sp60;
	arg5->unk24 = sp64;
	arg5->unk28 = sp38[0];
	arg5->unk2c = sp38[1] - envGetCurrent()->unk40 * 4.0f;
	arg5->unk30 = sp38[2];
	arg5->unk34 = f22;

	arg5->r = arg0->r;
	arg5->g = arg0->g;
	arg5->b = arg0->b;
	arg5->a = arg0->a;
}

bool sky0f122ce8(struct skything38 *arg0, struct skything38 *arg1)
{
	f32 f0 = arg0->unk28 - arg1->unk28;
	f32 f2 = arg0->unk2c - arg1->unk2c;

	return sqrtf(f0 * f0 + f2 * f2) < 1.0f ? true : false;
}

Gfx *sky0f122d4c(Gfx *gdl, struct skything38 *arg1, struct skything38 *arg2, struct skything38 *arg3, f32 arg4, bool textured)
{
	struct skything38 *sp484;
	struct skything38 *sp480;
	struct skything38 *sp47c;
	s32 i;
	f32 sp474;
	f32 sp470;
	f32 sp46c;
	f32 sp468;
	f32 sp464;
	f32 sp460;

	f32 sp45c[1];
	f32 sp458[1];
	f32 sp454[1];
	f32 sp450[1];
	f32 sp44c[1];
	f32 sp448[1];

	f32 sp444;
	f32 sp440;

	f32 sp43c[1];
	f32 sp438[1];
	f32 sp434[1];
	f32 sp430[1];
	f32 sp42c[1];
	f32 sp428[1];
	f32 sp424[1];
	f32 sp420[1];

	f32 sp41c;
	f32 sp418;
	f32 sp414;
	f32 sp410;
	f32 sp40c;
	f32 sp408;
	f32 sp404;
	f32 sp400;

	f32 sp3fc[1];
	f32 sp3f8[1];
	f32 sp3f4[1];
	f32 sp3f0[1];
	f32 sp3ec[1];
	f32 sp3e8[1];
	f32 sp3e4[1];
	f32 sp3e0[1];

	f32 sp3dc[1];
	f32 sp3d8[1];
	f32 sp3d4[1];
	f32 sp3d0[1];
	f32 sp3cc[1];
	f32 sp3c8[1];
	f32 sp3c4[1];
	f32 sp3c0[1];

	f32 sp3bc[1];
	f32 sp3b8[1];
	f32 sp3b4[1];
	f32 sp3b0[1];
	f32 sp3ac[1];
	f32 sp3a8[1];
	f32 sp3a4[1];
	f32 sp3a0[1];
	f32 sp39c[1];
	f32 sp398[1];
	f32 sp394[1];
	f32 sp390[1];
	f32 sp38c[1];
	f32 sp388[1];
	f32 sp384[1];
	f32 sp380[1];
	f32 sp37c;
	f32 sp378;
	f32 sp374[1];
	f32 sp370[1];
	f32 sp36c[1];
	f32 sp368;
	f32 sp364[1];
	f32 sp360[1];
	f32 sp35c[1];
	f32 sp358[1];
	f32 sp354[1];
	f32 sp350[1];
	f32 sp34c[1];
	f32 sp348[1];
	f32 sp344[1];
	f32 sp340[1];
	f32 sp33c[1];
	f32 sp338[1];
	f32 sp334[1];
	f32 sp330[1];
	f32 sp310[8];
	f32 sp2f0[8];
	f32 sp2d0[8];
	f32 sp2b0[8];
	f32 sp290[8];
	f32 sp270[8];
	f32 sp250[8];
	f32 sp230[8];
	f32 sp210[8];
	f32 f2;
	f32 sp208[1];
	f32 sp204[1];
	f32 sp200[1];
	u32 stack[4];
	f32 sp1d0[8];
	f32 sp1b0[8];
	u32 stack2;
	f32 sp1a8[1];
	f32 sp1a4[1];
	f32 sp1a0[1];
	struct skything38 *swap1;
	struct skything38 *swap2;
	struct skything38 *swap3;
	f32 sp190[1];
	u32 stack3;

	if (sky0f122ce8(arg1, arg2) || sky0f122ce8(arg2, arg3) || sky0f122ce8(arg3, arg1)) {
		return gdl;
	}

	sp378 = arg4 / 65536.0f;

	sp474 = arg2->unk28 - arg1->unk28;
	sp470 = arg2->unk2c - arg1->unk2c;
	sp46c = arg3->unk28 - arg1->unk28;
	sp468 = arg3->unk2c - arg1->unk2c;

	sp444 = ((sp46c * sp470) - (sp474 * sp468)) * (1.0f / 65536.0f);

	if (sp444 == 0.0f) {
		return gdl;
	}

	sp440 = 1.0f / sp444;

	sp484 = arg1;
	sp480 = arg2;
	sp47c = arg3;

	if (sp480->unk2c < sp484->unk2c) {
		swap1 = sp480;
		sp480 = sp484;
		sp484 = swap1;

		sp444 *= -1.0f;
		sp440 *= -1.0f;
	}

	if (sp47c->unk2c < sp480->unk2c) {
		swap2 = sp480;
		sp480 = sp47c;
		sp47c = swap2;

		sp444 *= -1.0f;
		sp440 *= -1.0f;
	}

	if (sp480->unk2c < sp484->unk2c) {
		swap3 = sp480;
		sp480 = sp484;
		sp484 = swap3;

		sp444 *= -1.0f;
		sp440 *= -1.0f;
	}

	sp420[0] = sp480->unk28 * 0.25f;
	sp424[0] = 0.0f;
	sp428[0] = sp484->unk28 * 0.25f;
	sp42c[0] = 0.0f;
	sp430[0] = sp484->unk28 * 0.25f;
	sp434[0] = 0.0f;
	sp43c[0] = 0.0f;
	sp438[0] = 0.0f;

	sp448[0] = sp47c->unk28;
	sp44c[0] = sp47c->unk2c;
	sp450[0] = sp480->unk28;
	sp454[0] = sp480->unk2c;
	sp458[0] = sp484->unk28;
	sp45c[0] = sp484->unk2c;

	sp474 = sp450[0] - sp458[0];
	sp470 = sp454[0] - sp45c[0];
	sp46c = sp448[0] - sp458[0];
	sp468 = sp44c[0] - sp45c[0];
	sp464 = sp448[0] - sp450[0];
	sp460 = sp44c[0] - sp454[0];

	sp3fc[0] = 0.0f;
	sp3f8[0] = 0.0f;
	sp3dc[0] = 0.0f;
	sp3d8[0] = 0.0f;
	sp3a0[0] = 0.0f;
	sp3a8[0] = 0.0f;
	sp3b0[0] = 0.0f;
	sp3bc[0] = 0.0f;
	sp3b8[0] = 0.0f;
	sp380[0] = 0.0f;
	sp388[0] = 0.0f;
	sp390[0] = 0.0f;
	sp39c[0] = 0.0f;
	sp398[0] = 0.0f;

	sp3e0[0] = sp464 / 4.0f;
	sp3e4[0] = sp460 / 4.0f;
	sp3e8[0] = sp474 / 4.0f;
	sp3ec[0] = sp470 / 4.0f;
	sp3f0[0] = sp46c / 4.0f;
	sp3f4[0] = sp468 / 4.0f;

	sp3c0[0] = sp464 * 4.0f;
	sp3c4[0] = sp460 * 4.0f;
	sp3c8[0] = sp474 * 4.0f;
	sp3cc[0] = sp470 * 4.0f;
	sp3d0[0] = sp46c * 4.0f;
	sp3d4[0] = sp468 * 4.0f;

	sp3a4[0] = 4.0f / sp460;
	sp3ac[0] = 4.0f / sp470;
	sp3b4[0] = 4.0f / sp468;

	sp384[0] = sp464 / sp460;
	sp38c[0] = sp474 / sp470;
	sp394[0] = sp46c / sp468;

	sp384[0] = skyClamp(sp384[0], -1878.0f, 1877.0f);
	sp38c[0] = skyClamp(sp38c[0], -1878.0f, 1877.0f);
	sp394[0] = skyClamp(sp394[0], -1878.0f, 1877.0f);

	f2 = (sp484->unk2c * 0.25f);
	sp37c = f2 - (s32) f2;
	sp408 = sp428[0] - skyRound(sp38c[0] * 8192.0f) * (1.0f / 8192.0f) * sp37c;
	sp410 = sp430[0] - skyRound(sp394[0] * 8192.0f) * (1.0f / 8192.0f) * sp37c;

	gImmp1(gdl++, G_RDPHALF_1, (textured ? (G_TRI_SHADE_TXTR << 24) : (G_TRI_FILL << 24))
			| (sp444 < 0.0f ? 0x00800000 : 0)
			| (u32) sp47c->unk2c);
	gImmp1(gdl++, G_RDPHALF_CONT, (s32) sp480->unk2c << 16 | (s32) sp484->unk2c);

	gImmp1(gdl++, G_RDPHALF_1, func0f152fa0(sp480->unk28 * 0.25f));
	gImmp1(gdl++, G_RDPHALF_CONT, func0f152fa0(sp384[0]));

	gImmp1(gdl++, G_RDPHALF_1, func0f152fa0(sp410));
	gImmp1(gdl++, G_RDPHALF_CONT, func0f152fa0(sp394[0]));

	gImmp1(gdl++, G_RDPHALF_1, func0f152fa0(sp408));
	gImmp1(gdl++, G_RDPHALF_CONT, func0f152fa0(sp38c[0]));

	if (!textured) {
		return gdl;
	}

	sp36c[0] = sp484->unk0c * sp378;
	sp370[0] = sp480->unk0c * sp378;
	sp374[0] = sp47c->unk0c * sp378;

	sp368 = sp36c[0];

	if (sp370[0] < sp368) {
		sp368 = sp370[0];
	}

	if (sp374[0] < sp368) {
		sp368 = sp374[0];
	}

	sp368 *= 0.5f;

	sp35c[0] = sp484->unk34 * sp368;
	sp360[0] = sp480->unk34 * sp368;
	sp364[0] = sp47c->unk34 * sp368;

	sp338[0] = sp35c[0] * sp484->unk20;
	sp33c[0] = sp35c[0] * sp484->unk24;
	sp340[0] = sp35c[0] * 32767.0f;
	sp344[0] = sp360[0] * sp480->unk20;
	sp348[0] = sp360[0] * sp480->unk24;
	sp34c[0] = sp360[0] * 32767.0f;
	sp350[0] = sp364[0] * sp47c->unk20;
	sp354[0] = sp364[0] * sp47c->unk24;
	sp358[0] = sp364[0] * 32767.0f;

	sp330[0] = SKYABS(sp338[0]);
	sp334[0] = SKYABS(sp33c[0]);

	if (sp330[0] < SKYABS(sp344[0])) {
		sp330[0] = SKYABS(sp344[0]);
	}

	if (sp334[0] < SKYABS(sp348[0])) {
		sp334[0] = SKYABS(sp348[0]);
	}

	if (sp330[0] < SKYABS(sp350[0])) {
		sp330[0] = SKYABS(sp350[0]);
	}

	if (sp334[0] < SKYABS(sp354[0])) {
		sp334[0] = SKYABS(sp354[0]);
	}

	sp310[0] = sp484->r + 0.5f;
	sp310[1] = sp484->g + 0.5f;
	sp310[2] = sp484->b + 0.5f;
	sp310[3] = sp484->a + 0.5f;

	sp2f0[0] = sp480->r + 0.5f;
	sp2f0[1] = sp480->g + 0.5f;
	sp2f0[2] = sp480->b + 0.5f;
	sp2f0[3] = sp480->a + 0.5f;

	sp2d0[0] = sp47c->r + 0.5f;
	sp2d0[1] = sp47c->g + 0.5f;
	sp2d0[2] = sp47c->b + 0.5f;
	sp2d0[3] = sp47c->a + 0.5f;

	sp310[4] = sp338[0]; sp310[5] = sp33c[0]; sp310[6] = sp340[0];
	sp2f0[4] = sp344[0]; sp2f0[5] = sp348[0]; sp2f0[6] = sp34c[0];
	sp2d0[4] = sp350[0]; sp2d0[5] = sp354[0]; sp2d0[6] = sp358[0];

	sp310[7] = sp484->unk30;
	sp2f0[7] = sp480->unk30;
	sp2d0[7] = sp47c->unk30;

	for (i = 0; i < 8; i++) {
		sp2b0[i] = sp2f0[i] - sp310[i];
		sp290[i] = sp2d0[i] - sp310[i];
	}

	for (i = 0; i < 8; i++) {
		sp250[i] = (sp290[i] * sp3cc[0] - sp2b0[i] * sp3d4[0]) * (1.0f / 65536.0f);
		sp270[i] = (sp2b0[i] * sp3d0[0] - sp290[i] * sp3c8[0]) * (1.0f / 65536.0f);
		sp290[i] = sp250[i] * sp440;
		sp2b0[i] = sp270[i] * sp440;
		sp230[i] = sp2b0[i] + sp290[i] * sp394[0];
		sp210[i] = sp310[i] - sp230[i] * sp37c;
	}

	{
		u32 sp168;
		u32 sp164;
		u32 sp160;
		u32 sp15c;
		u32 sp158;
		u32 sp154;
		u32 sp150;
		u32 sp14c;
		u32 sp148;
		u32 sp144;
		u32 sp140;
		u32 sp13c;
		u32 sp138;
		u32 sp134;
		u32 sp130;
		u32 sp12c;

		sp168 = func0f152fa0(sp210[0]);
		sp164 = func0f152fa0(sp210[1]);
		sp160 = func0f152fa0(sp210[2]);
		sp15c = func0f152fa0(sp210[3]);

		sp158 = func0f152fa0(sp290[0]);
		sp154 = func0f152fa0(sp290[1]);
		sp150 = func0f152fa0(sp290[2]);
		sp14c = func0f152fa0(sp290[3]);

		sp138 = func0f152fa0(sp2b0[0]);
		sp134 = func0f152fa0(sp2b0[1]);
		sp130 = func0f152fa0(sp2b0[2]);
		sp12c = func0f152fa0(sp2b0[3]);

		sp148 = func0f152fa0(sp230[0]);
		sp144 = func0f152fa0(sp230[1]);
		sp140 = func0f152fa0(sp230[2]);
		sp13c = func0f152fa0(sp230[3]);

		gImmp1(gdl++, G_RDPHALF_1, (sp168 & 0xffff0000) | (sp164 & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (sp160 & 0xffff0000) | (sp15c & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (sp158 & 0xffff0000) | (sp154 & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (sp150 & 0xffff0000) | (sp14c & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (sp168 & 0x0000ffff) << 16 | (sp164 & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (sp160 & 0x0000ffff) << 16 | (sp15c & 0x0000ffff));

		gImmp1(gdl++, G_RDPHALF_1, (sp158 & 0x0000ffff) << 16 | (sp154 & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (sp150 & 0x0000ffff) << 16 | (sp14c & 0x0000ffff));

		gImmp1(gdl++, G_RDPHALF_1, (sp148 & 0xffff0000) | (sp144 & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (sp140 & 0xffff0000) | (sp13c & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (sp138 & 0xffff0000) | (sp134 & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (sp130 & 0xffff0000) | (sp12c & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (sp148 & 0x0000ffff) << 16 | (sp144 & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (sp140 & 0x0000ffff) << 16 | (sp13c & 0x0000ffff));

		gImmp1(gdl++, G_RDPHALF_1, (sp138 & 0x0000ffff) << 16 | (sp134 & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (sp130 & 0x0000ffff) << 16 | (sp12c & 0x0000ffff));
	}

	sp200[0] = sp330[0] * (1.0f / 32.0f);
	sp204[0] = sp334[0] * (1.0f / 32.0f);
	sp208[0] = sp368 * (1.0f / 32.0f);

	for (i = 0; i < 8; i++) {
		sp1d0[i] = SKYABS(sp290[i]) * (1.0f / 32.0f);
		sp1b0[i] = SKYABS(sp2b0[i]) * (1.0f / 32.0f);
	}

	sp1a0[0] = sp200[0] + (2.0f * sp1d0[4]) + sp1b0[4];
	sp1a4[0] = sp204[0] + (2.0f * sp1d0[5]) + sp1b0[5];
	sp1a8[0] = sp208[0] + (2.0f * sp1d0[6]) + sp1b0[6];

	if (sp1a0[0] < sp1a4[0]) {
		sp1a0[0] = sp1a4[0];
	}

	if (sp1a0[0] < sp1a8[0]) {
		sp1a0[0] = sp1a8[0];
	}

	sp1a0[0] *= 1.0f / 1024.0f;

	if (sp1a0[0] > 1.0f) {
		sp190[0] = 1.0f / sp1a0[0];
	} else {
		sp190[0] = 1.0f;
	}

	{
		u32 spe8;
		u32 spe4;
		u32 spe0;
		u32 spdc;
		u32 spd8;
		u32 spd4;
		u32 spd0;
		u32 spcc;
		u32 spc8;
		u32 spc4;
		u32 spc0;
		u32 spbc;
		u32 spb8;
		u32 spb4;
		u32 spb0;
		u32 spac;

		spe8 = func0f152fa0(sp210[4] * sp190[0]);
		spe4 = func0f152fa0(sp210[5] * sp190[0]);
		spe0 = func0f152fa0(sp210[6] * sp190[0]);
		spdc = 0;

		spd8 = func0f152fa0(sp290[4] * sp190[0]);
		spd4 = func0f152fa0(sp290[5] * sp190[0]);
		spd0 = func0f152fa0(sp290[6] * sp190[0]);
		spcc = 0;

		spb8 = func0f152fa0(sp2b0[4] * sp190[0]);
		spb4 = func0f152fa0(sp2b0[5] * sp190[0]);
		spb0 = func0f152fa0(sp2b0[6] * sp190[0]);
		spac = 0;

		spc8 = func0f152fa0(sp230[4] * sp190[0]);
		spc4 = func0f152fa0(sp230[5] * sp190[0]);
		spc0 = func0f152fa0(sp230[6] * sp190[0]);
		spbc = 0;

		gImmp1(gdl++, G_RDPHALF_1, (spe8 & 0xffff0000) | (spe4 & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (spe0 & 0xffff0000) | (spdc & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (spd8 & 0xffff0000) | (spd4 & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (spd0 & 0xffff0000) | (spcc & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (spe8 & 0x0000ffff) << 16 | (spe4 & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (spe0 & 0x0000ffff) << 16 | (spdc & 0x0000ffff));

		gImmp1(gdl++, G_RDPHALF_1, (spd8 & 0x0000ffff) << 16 | (spd4 & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (spd0 & 0x0000ffff) << 16 | (spcc & 0x0000ffff));

		gImmp1(gdl++, G_RDPHALF_1, (spc8 & 0xffff0000) | (spc4 & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (spc0 & 0xffff0000) | (spbc & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (spb8 & 0xffff0000) | (spb4 & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (spb0 & 0xffff0000) | (spac & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (spc8 & 0x0000ffff) << 16 | (spc4 & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (spc0 & 0x0000ffff) << 16 | (spbc & 0x0000ffff));

		gImmp1(gdl++, G_RDPHALF_1, (spb8 & 0x0000ffff) << 16 | (spb4 & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_2, (spb0 & 0x0000ffff) << 16 | (spac & 0x0000ffff));
	}

	return gdl;
}

Gfx *sky0f123fd4(Gfx *gdl, struct skything38 *arg1, struct skything38 *arg2, struct skything38 *arg3, struct skything38 *arg4, f32 arg5)
{
	struct skything38 *sp4cc;
	struct skything38 *sp4c8;
	struct skything38 *sp4c4;
	s32 i;
	u32 stack;
	f32 sp4b8;
	f32 sp4b4;
	f32 sp4b0;
	f32 sp4ac;
	f32 sp4a8;
	f32 sp4a4;
	f32 sp4a0[1];
	f32 sp49c[1];
	f32 sp498[1];
	f32 sp494[1];
	f32 sp490[1];
	f32 sp48c[1];
	f32 sp488;
	f32 sp484;
	f32 sp480[1];
	f32 sp47c[1];
	f32 sp478[1];
	f32 sp474[1];
	f32 sp470[1];
	f32 sp46c[1];
	f32 sp468[1];
	f32 sp464[1];
	struct skything38 *swap1;
	struct skything38 *swap2;
	struct skything38 *swap3;
	f32 sp454[1];
	u32 stack07;
	f32 sp44c[1];
	u32 stack08;
	u32 stack09;
	f32 sp440[1];
	f32 sp43c[1];
	f32 sp438[1];
	f32 sp434[1];
	f32 sp430[1];
	f32 sp42c[1];
	f32 sp428[1];
	f32 sp424[1];
	f32 sp420[1];
	f32 sp41c[1];
	f32 sp418[1];
	f32 sp414[1];
	f32 sp410[1];
	f32 sp40c[1];
	f32 sp408[1];
	f32 sp404[1];
	f32 sp400[1];
	f32 sp3fc[1];
	f32 sp3f8[1];
	f32 sp3f4[1];
	f32 sp3f0[1];
	f32 sp3ec[1];
	f32 sp3e8[1];
	f32 sp3e4[1];
	f32 sp3e0[1];
	f32 sp3dc[1];
	f32 sp3d8[1];
	f32 sp3d4[1];
	f32 sp3d0[1];
	f32 sp3cc[1];
	f32 sp3c8[1];
	f32 sp3c4[1];
	f32 sp3c0;
	f32 sp3bc[1];
	f32 sp3b8[1];
	f32 sp3b4[1];
	f32 sp3b0[1];
	f32 sp3ac;
	f32 sp3a8[1];
	f32 sp3a4[1];
	f32 sp3a0[1];
	f32 sp39c[1];
	f32 sp398[1];
	f32 sp394[1];
	f32 sp390[1];
	f32 sp38c[1];
	f32 sp388[1];
	f32 sp384[1];
	f32 sp380[1];
	f32 sp37c[1];
	f32 sp378[1];
	f32 sp374[1];
	f32 sp370[1];
	f32 sp36c[1];
	f32 sp368[1];
	f32 sp364[1];
	f32 sp354[4];
	f32 sp334[8];
	f32 sp314[8];
	f32 sp2f4[8];
	f32 sp2d4[8];
	f32 sp2b4[8];
	f32 sp294[8];
	f32 sp274[8];
	f32 sp254[8];
	u32 stack10;
	u32 stack11;
	u32 stack12;
	u32 stack13;
	u32 stack00;
	f32 sp23c[1];
	f32 sp238[1];
	f32 sp234[1];
	f32 sp214[8];
	f32 sp1f4[8];
	u32 stack03;
	u32 stack04;
	u32 stack05;
	u32 stack06;
	u32 stack15;
	f32 sp1dc[1];
	f32 sp1d8[1];
	f32 sp1d4[1];
	u32 stack01;
	u32 stack02;
	u32 stack14;
	f32 sp1c4[1];
	u32 stack16;

	if (sky0f122ce8(arg1, arg2)
			|| sky0f122ce8(arg2, arg3)
			|| sky0f122ce8(arg3, arg1)
			|| sky0f122ce8(arg4, arg1)
			|| sky0f122ce8(arg4, arg2)
			|| sky0f122ce8(arg4, arg3)) {
		return gdl;
	}

	sp3c0 = arg5 * (1.0f / 65536.0f);

	sp4b8 = arg2->unk28 - arg1->unk28;
	sp4b4 = arg2->unk2c - arg1->unk2c;
	sp4b0 = arg3->unk28 - arg1->unk28;
	sp4ac = arg3->unk2c - arg1->unk2c;

	sp488 = ((sp4b0 * sp4b4) - (sp4b8 * sp4ac)) * (1.0f / 65536.0f);

	sp484 = 1.0f / sp488;

	sp4cc = arg1;
	sp4c8 = arg2;
	sp4c4 = arg3;

	if (sp4c8->unk2c < sp4cc->unk2c) {
		swap1 = sp4c8;
		sp4c8 = sp4cc;
		sp4cc = swap1;

		sp488 *= -1.0f;
		sp484 *= -1.0f;
	}

	if (sp4c4->unk2c < sp4c8->unk2c) {
		swap2 = sp4c8;
		sp4c8 = sp4c4;
		sp4c4 = swap2;

		sp488 *= -1.0f;
		sp484 *= -1.0f;
	}

	if (sp4c8->unk2c < sp4cc->unk2c) {
		swap3 = sp4c8;
		sp4c8 = sp4cc;
		sp4cc = swap3;

		sp488 *= -1.0f;
		sp484 *= -1.0f;
	}

	sp464[0] = sp4c8->unk28 * 0.25f;
	sp468[0] = 0.0f;
	sp46c[0] = sp4cc->unk28 * 0.25f;
	sp470[0] = 0.0f;
	sp474[0] = sp4cc->unk28 * 0.25f;
	sp478[0] = 0.0f;
	sp480[0] = 0.0f;
	sp47c[0] = 0.0f;

	sp48c[0] = sp4c4->unk28;
	sp490[0] = sp4c4->unk2c;
	sp494[0] = sp4c8->unk28;
	sp498[0] = sp4c8->unk2c;
	sp49c[0] = sp4cc->unk28;
	sp4a0[0] = sp4cc->unk2c;

	sp4b8 = sp494[0] - sp49c[0];
	sp4b4 = sp498[0] - sp4a0[0];
	sp4b0 = sp48c[0] - sp49c[0];
	sp4ac = sp490[0] - sp4a0[0];
	sp4a8 = sp48c[0] - sp494[0];
	sp4a4 = sp490[0] - sp498[0];

	sp440[0] = 0.0f;
	sp43c[0] = 0.0f;
	sp420[0] = 0.0f;
	sp41c[0] = 0.0f;
	sp3e4[0] = 0.0f;
	sp3ec[0] = 0.0f;
	sp3f4[0] = 0.0f;
	sp400[0] = 0.0f;
	sp3fc[0] = 0.0f;
	sp3c4[0] = 0.0f;
	sp3cc[0] = 0.0f;
	sp3d4[0] = 0.0f;
	sp3e0[0] = 0.0f;
	sp3dc[0] = 0.0f;

	sp424[0] = sp4a8 / 4.0f;
	sp428[0] = sp4a4 / 4.0f;
	sp42c[0] = sp4b8 / 4.0f;
	sp430[0] = sp4b4 / 4.0f;
	sp434[0] = sp4b0 / 4.0f;
	sp438[0] = sp4ac / 4.0f;

	sp404[0] = sp4a8 * 4.0f;
	sp408[0] = sp4a4 * 4.0f;
	sp40c[0] = sp4b8 * 4.0f;
	sp410[0] = sp4b4 * 4.0f;
	sp414[0] = sp4b0 * 4.0f;
	sp418[0] = sp4ac * 4.0f;

	sp3e8[0] = 4.0f / sp4a4;
	sp3f0[0] = 4.0f / sp4b4;
	sp3f8[0] = 4.0f / sp4ac;

	sp3c8[0] = sp4a8 / sp4a4;
	sp3d0[0] = sp4b8 / sp4b4;
	sp3d8[0] = sp4b0 / sp4ac;

	sp3c8[0] = skyClamp(sp3c8[0], -1878.0f, 1877.0f);
	sp3d0[0] = skyClamp(sp3d0[0], -1878.0f, 1877.0f);
	sp3d8[0] = skyClamp(sp3d8[0], -1878.0f, 1877.0f);

	sp44c[0] = sp46c[0];
	sp454[0] = sp474[0];

	if (arg1->unk28 < arg2->unk28) {
		f32 sp1bc;

		if (arg3->unk2c - arg4->unk2c < 1.0f) {
			sp1bc = -1878.0f;
		} else {
			sp1bc = -(camGetScreenWidth() - 0.25f) / ((arg3->unk2c - arg4->unk2c) / 4.0f);
		}

		gImmp1(gdl++, G_RDPHALF_1, (G_TRI_SHADE_TXTR << 24) | 0x00800000 | (u32) arg3->unk2c);
		gImmp1(gdl++, G_RDPHALF_CONT, (s32) arg4->unk2c << 16 | (s32) arg1->unk2c);

		gImmp1(gdl++, G_RDPHALF_1, func0f152fa0(camGetScreenLeft() + camGetScreenWidth() - 0.25f));
		gImmp1(gdl++, G_RDPHALF_CONT, func0f152fa0(sp1bc));

		gImmp1(gdl++, G_RDPHALF_1, func0f152fa0(camGetScreenLeft()));
		gImmp1(gdl++, G_RDPHALF_CONT, func0f152fa0(0.0f));

		gImmp1(gdl++, G_RDPHALF_1, func0f152fa0(camGetScreenLeft() + camGetScreenWidth() - 0.25f));
		gImmp1(gdl++, G_RDPHALF_CONT, func0f152fa0(0.0f));
	} else {
		f32 sp198;

		if (arg3->unk2c - arg4->unk2c < 1.0f) {
			sp198 = 1877.0f;
		} else {
			sp198 = (camGetScreenWidth() - 0.25f) / ((arg3->unk2c - arg4->unk2c) / 4.0f);
		}

		gImmp1(gdl++, G_RDPHALF_1, 0xce000000 | (u32) arg3->unk2c);
		gImmp1(gdl++, G_RDPHALF_CONT, (s32) arg4->unk2c << 16 | (s32) arg1->unk2c);

		gImmp1(gdl++, G_RDPHALF_1, func0f152fa0(camGetScreenLeft()));
		gImmp1(gdl++, G_RDPHALF_CONT, func0f152fa0(sp198));

		gImmp1(gdl++, G_RDPHALF_1, func0f152fa0(camGetScreenLeft() + camGetScreenWidth() - 0.25f));
		gImmp1(gdl++, G_RDPHALF_CONT, func0f152fa0(0.0f));

		gImmp1(gdl++, G_RDPHALF_1, func0f152fa0(camGetScreenLeft()));
		gImmp1(gdl++, G_RDPHALF_CONT, func0f152fa0(0.0f));
	}

	sp3b0[0] = sp4cc->unk0c * sp3c0;
	sp3b4[0] = sp4c8->unk0c * sp3c0;
	sp3b8[0] = sp4c4->unk0c * sp3c0;
	sp3bc[0] = arg4->unk0c * sp3c0;

	sp3ac = sp3b0[0];

	if (sp3b4[0] < sp3ac) {
		sp3ac = sp3b4[0];
	}

	if (sp3b8[0] < sp3ac) {
		sp3ac = sp3b8[0];
	}

	if (sp3bc[0] < sp3ac) {
		sp3ac = sp3bc[0];
	}

	sp3ac *= 0.5f;

	sp39c[0] = sp4cc->unk34 * sp3ac;
	sp3a0[0] = sp4c8->unk34 * sp3ac;
	sp3a4[0] = sp4c4->unk34 * sp3ac;
	sp3a8[0] = arg4->unk34 * sp3ac;

	sp36c[0] = sp39c[0] * sp4cc->unk20;
	sp370[0] = sp39c[0] * sp4cc->unk24;
	sp374[0] = sp39c[0] * 32767.0f;
	sp378[0] = sp3a0[0] * sp4c8->unk20;
	sp37c[0] = sp3a0[0] * sp4c8->unk24;
	sp380[0] = sp3a0[0] * 32767.0f;
	sp384[0] = sp3a4[0] * sp4c4->unk20;
	sp388[0] = sp3a4[0] * sp4c4->unk24;
	sp38c[0] = sp3a4[0] * 32767.0f;
	sp390[0] = sp3a8[0] * arg4->unk20;
	sp394[0] = sp3a8[0] * arg4->unk24;
	sp398[0] = sp3a8[0] * 32767.0f;

	sp364[0] = SKYABS(sp36c[0]);
	sp368[0] = SKYABS(sp370[0]);

	if (sp364[0] < SKYABS(sp378[0])) {
		sp364[0] = SKYABS(sp378[0]);
	}

	if (sp368[0] < SKYABS(sp37c[0])) {
		sp368[0] = SKYABS(sp37c[0]);
	}

	if (sp364[0] < SKYABS(sp384[0])) {
		sp364[0] = SKYABS(sp384[0]);
	}

	if (sp368[0] < SKYABS(sp388[0])) {
		sp368[0] = SKYABS(sp388[0]);
	}

	if (sp364[0] < SKYABS(sp390[0])) {
		sp364[0] = SKYABS(sp390[0]);
	}

	if (sp368[0] < SKYABS(sp394[0])) {
		sp368[0] = SKYABS(sp394[0]);
	}

	sp354[0] = sp36c[0]; sp354[1] = sp370[0]; sp354[2] = sp374[0];
	sp334[0] = sp378[0]; sp334[1] = sp37c[0]; sp334[2] = sp380[0];
	sp314[0] = sp384[0]; sp314[1] = sp388[0]; sp314[2] = sp38c[0];

	sp354[3] = sp4cc->unk30;
	sp334[3] = sp4c8->unk30;
	sp314[3] = sp4c4->unk30;

	for (i = 0; i < 4; i++) {
		sp2f4[i] = sp334[i] - sp354[i];
		sp2d4[i] = sp314[i] - sp354[i];
	}

	for (i = 0; i < 4; i++) {
		sp294[i] = ((sp2d4[i] * sp410[0]) - (sp2f4[i] * sp418[0])) * (1.0f / 65536.0f);
		sp2b4[i] = ((sp2f4[i] * sp414[0]) - (sp2d4[i] * sp40c[0])) * (1.0f / 65536.0f);
		sp2d4[i] = sp294[i] * sp484;
		sp2f4[i] = sp2b4[i] * sp484;
		sp274[i] = sp2b4[i] * sp484;
		sp254[i] = sp354[i];
	}

	{
		f32 mult = arg4->unk2c / arg3->unk2c;

		f32 sp170 = arg4->r + ((arg1->r - arg3->r) * mult);
		f32 sp16c = arg4->g + ((arg1->g - arg3->g) * mult);
		f32 sp168 = arg4->b + ((arg1->b - arg3->b) * mult);
		f32 sp164 = arg4->a + ((arg1->a - arg3->a) * mult);

		u32 sp160 = arg1->r * 65536.0f;
		u32 sp15c = arg1->g * 65536.0f;
		u32 sp158 = arg1->b * 65536.0f;
		u32 sp154 = arg1->a * 65536.0f;

		u32 sp150 = func0f152fa0((sp170 - arg1->r) / ((arg2->unk28 - arg1->unk28) * 0.25f));
		u32 sp14c = func0f152fa0((sp16c - arg1->g) / ((arg2->unk28 - arg1->unk28) * 0.25f));
		u32 sp148 = func0f152fa0((sp168 - arg1->b) / ((arg2->unk28 - arg1->unk28) * 0.25f));
		u32 sp144 = func0f152fa0((sp164 - arg1->a) / ((arg2->unk28 - arg1->unk28) * 0.25f));

		u32 sp140;
		u32 sp13c;
		u32 sp138;
		u32 sp134;
		u32 sp130;
		u32 sp12c;
		u32 sp128;
		u32 sp124;

		sp140 = sp130 = func0f152fa0((arg3->r - arg1->r) / ((arg3->unk2c - arg1->unk2c) * 0.25f));
		sp13c = sp12c = func0f152fa0((arg3->g - arg1->g) / ((arg3->unk2c - arg1->unk2c) * 0.25f));
		sp138 = sp128 = func0f152fa0((arg3->b - arg1->b) / ((arg3->unk2c - arg1->unk2c) * 0.25f));
		sp124 = sp134 = func0f152fa0((arg3->a - arg1->a) / ((arg3->unk2c - arg1->unk2c) * 0.25f));

		gImmp1(gdl++, G_RDPHALF_1, (sp160 & 0xffff0000) | (sp15c & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (sp158 & 0xffff0000) | (sp154 & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (sp150 & 0xffff0000) | (sp14c & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (sp148 & 0xffff0000) | (sp144 & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (sp160 & 0x0000ffff) << 16 | (sp15c & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (sp158 & 0x0000ffff) << 16 | (sp154 & 0x0000ffff));

		gImmp1(gdl++, G_RDPHALF_1, (sp150 & 0x0000ffff) << 16 | (sp14c & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (sp148 & 0x0000ffff) << 16 | (sp144 & 0x0000ffff));

		gImmp1(gdl++, G_RDPHALF_1, (sp140 & 0xffff0000) | (sp13c & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (sp138 & 0xffff0000) | (sp134 & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (sp130 & 0xffff0000) | (sp12c & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (sp128 & 0xffff0000) | (sp124 & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (sp140 & 0x0000ffff) << 16 | (sp13c & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (sp138 & 0x0000ffff) << 16 | (sp134 & 0x0000ffff));

		gImmp1(gdl++, G_RDPHALF_1, (sp130 & 0x0000ffff) << 16 | (sp12c & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (sp128 & 0x0000ffff) << 16 | (sp124 & 0x0000ffff));
	}

	sp234[0] = sp364[0] * (1.0f / 32.0f);
	sp238[0] = sp368[0] * (1.0f / 32.0f);
	sp23c[0] = sp3ac * (1.0f / 32.0f);

	for (i = 0; i < 4; i++) {
		sp214[i] = SKYABS(sp2d4[i]) * (1.0f / 32.0f);
		sp1f4[i] = SKYABS(sp2f4[i]) * (1.0f / 32.0f);
	}

	sp1d4[0] = sp234[0] + (2.0f * sp214[0]) + sp1f4[0];
	sp1d8[0] = sp238[0] + (2.0f * sp214[1]) + sp1f4[1];
	sp1dc[0] = sp23c[0] + (2.0f * sp214[2]) + sp1f4[2];

	if (sp1d4[0] < sp1d8[0]) {
		sp1d4[0] = sp1d8[0];
	}

	if (sp1d4[0] < sp1dc[0]) {
		sp1d4[0] = sp1dc[0];
	}

	sp1d4[0] *= (1.0f / 1024.0f);

	if (sp1d4[0] > 1.0f) {
		sp1c4[0] = 1.0f / sp1d4[0];
	} else {
		sp1c4[0] = 1.0f;
	}

	{
		u32 spe0;
		u32 spdc;
		u32 spd8;
		u32 spd4;
		u32 spd0;
		u32 spcc;
		u32 spc8;
		u32 spc4;
		u32 spc0;
		u32 spbc;
		u32 spb8;
		u32 spb4;
		u32 spb0;
		u32 spac;
		u32 spa8;
		u32 spa4;

		spe0 = func0f152fa0(sp254[0] * sp1c4[0]);
		spdc = func0f152fa0(sp254[1] * sp1c4[0]);
		spd8 = func0f152fa0(sp254[2] * sp1c4[0]);
		spd4 = func0f152fa0(sp254[3] * sp1c4[0]);

		spd0 = func0f152fa0(sp2d4[0] * sp1c4[0]);
		spcc = func0f152fa0(sp2d4[1] * sp1c4[0]);
		spc8 = func0f152fa0(sp2d4[2] * sp1c4[0]);
		spc4 = func0f152fa0(sp2d4[3] * sp1c4[0]);

		spb0 = func0f152fa0(sp2f4[0] * sp1c4[0]);
		spac = func0f152fa0(sp2f4[1] * sp1c4[0]);
		spa8 = func0f152fa0(sp2f4[2] * sp1c4[0]);
		spa4 = func0f152fa0(sp2f4[3] * sp1c4[0]);

		spc0 = func0f152fa0(sp274[0] * sp1c4[0]);
		spbc = func0f152fa0(sp274[1] * sp1c4[0]);
		spb8 = func0f152fa0(sp274[2] * sp1c4[0]);
		spb4 = func0f152fa0(sp274[3] * sp1c4[0]);

		gImmp1(gdl++, G_RDPHALF_1, (spe0 & 0xffff0000) | (spdc & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (spd8 & 0xffff0000) | (spd4 & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (spd0 & 0xffff0000) | (spcc & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (spc8 & 0xffff0000) | (spc4 & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (spe0 & 0x0000ffff) << 16 | (spdc & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (spd8 & 0x0000ffff) << 16 | (spd4 & 0x0000ffff));

		gImmp1(gdl++, G_RDPHALF_1, (spd0 & 0x0000ffff) << 16 | (spcc & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (spc8 & 0x0000ffff) << 16 | (spc4 & 0x0000ffff));

		gImmp1(gdl++, G_RDPHALF_1, (spc0 & 0xffff0000) | (spbc & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (spb8 & 0xffff0000) | (spb4 & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (spb0 & 0xffff0000) | (spac & 0xffff0000) >> 16);
		gImmp1(gdl++, G_RDPHALF_CONT, (spa8 & 0xffff0000) | (spa4 & 0xffff0000) >> 16);

		gImmp1(gdl++, G_RDPHALF_1, (spc0 & 0x0000ffff) << 16 | (spbc & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_CONT, (spb8 & 0x0000ffff) << 16 | (spb4 & 0x0000ffff));

		gImmp1(gdl++, G_RDPHALF_1, (spb0 & 0x0000ffff) << 16 | (spac & 0x0000ffff));
		gImmp1(gdl++, G_RDPHALF_2, (spa8 & 0x0000ffff) << 16 | (spa4 & 0x0000ffff));
	}

	return gdl;
}

void skyCreateArtifact(struct artifact *artifact, s32 x, s32 y)
{
	s32 viewleft = viGetViewLeft();
	s32 viewtop = viGetViewTop();
	s32 viewwidth = viGetViewWidth();
	s32 viewheight = viGetViewHeight();

	if (x >= viewleft && x < viewleft + viewwidth && y >= viewtop && y < viewtop + viewheight) {
		artifact->unk08 = &var800844f0[(s32)camGetScreenWidth() * y + x];
		artifact->unk0c.u16_2 = x;
		artifact->unk0c.u16_1 = y;
		artifact->type = ARTIFACTTYPE_CIRCLE;
	}
}

f32 sky0f125a1c(struct artifact *artifacts)
{
	f32 sum = 0;
	s32 i;

	for (i = 0; i < 8; i++) {
		if (artifacts[i].type == ARTIFACTTYPE_CIRCLE && artifacts[i].unk02 == 0xfffc) {
			sum += 0.125f;
		}
	}

	return sum;
}

Gfx *skyRenderSuns(Gfx *gdl, bool xray)
{
	Mtxf *sp16c;
	Mtxf *sp168;
	s16 viewleft;
	s16 viewtop;
	s16 viewwidth;
	s16 viewheight;
	f32 viewleftf;
	f32 viewtopf;
	f32 viewwidthf;
	f32 viewheightf;
	struct artifact *artifacts;
	u8 colour[3];
	struct environment *env;
	struct sun *sun;
	s32 i;
	f32 sp134[2];
	f32 sp12c[2];
	s32 xscale;
	f32 sp124;
	bool onscreen;
	f32 radius;

	sp16c = camGetWorldToScreenMtxf();
	sp168 = camGetMtxF1754();
	env = envGetCurrent();

	xscale = 1;

	if (env->numsuns <= 0 || !var800844f0 || g_Vars.mplayerisrunning) {
		return gdl;
	}

#if !PAL
	if (g_ViRes == 1) {
		xscale = 2;
	}
#endif

	viewleft = viGetViewLeft();
	viewtop = viGetViewTop();
	viewwidth = viGetViewWidth();
	viewheight = viGetViewHeight();

	viewleftf = viewleft;
	viewtopf = viewtop;
	viewwidthf = viewwidth;
	viewheightf = viewheight;

	sun = env->suns;

	for (i = 0; i < env->numsuns; i++) {
		g_SunPositions[i].f[0] = sun->pos[0];
		g_SunPositions[i].f[1] = sun->pos[1];
		g_SunPositions[i].f[2] = sun->pos[2];

		colour[0] = sun->red;
		colour[1] = sun->green;
		colour[2] = sun->blue;

		if (!xray) {
			mtx4TransformVecInPlace(sp16c, &g_SunPositions[i]);
			mtx4TransformVecInPlace(sp168, &g_SunPositions[i]);

			if (g_SunPositions[i].f[2] > 1.0f) {
				g_SunScreenXPositions[i] = (g_SunPositions[i].f[0] / g_SunPositions[i].f[2] + 1.0f) * 0.5f * viewwidthf + viewleftf;
				g_SunScreenYPositions[i] = (-g_SunPositions[i].f[1] / g_SunPositions[i].f[2] + 1.0f) * 0.5f * viewheightf + viewtopf;
				radius = 60.0f / viGetFovY() * sun->texture_size;
				onscreen = false;

				if (g_SunScreenXPositions[i] >= viewleftf - radius
						&& g_SunScreenXPositions[i] < viewleftf + viewwidth + radius
						&& g_SunScreenYPositions[i] >= viewtopf - radius
						&& g_SunScreenYPositions[i] < viewtopf + viewheightf + radius) {
					// Sun is at least partially on screen
					if (g_SunScreenXPositions[i] >= viewleftf
							&& g_SunScreenXPositions[i] < viewleftf + viewwidthf
							&& g_SunScreenYPositions[i] >= viewtopf
							&& g_SunScreenYPositions[i] < viewtopf + viewheightf) {
						// Sun's centre point is on-screen
						f32 distfromedge;
						f32 mindistfromedge;
						artifacts = schedGetWriteArtifacts();
						onscreen = true;
						mindistfromedge = 1000;

						if ((s32)g_SunScreenXPositions[i] < viewleft + 15) {
							distfromedge = g_SunScreenXPositions[i];

							if (distfromedge < mindistfromedge) {
								mindistfromedge = distfromedge;
							}
						}

						if (1);

						if ((s32)g_SunScreenYPositions[i] < viewtop + 15) {
							distfromedge = g_SunScreenYPositions[i];

							if (distfromedge < mindistfromedge) {
								mindistfromedge = distfromedge;
							}
						}

						if ((s32)g_SunScreenXPositions[i] > viewleft + viewwidth - 16) {
							distfromedge = viewleft + viewwidth - 1 - g_SunScreenXPositions[i];

							if (distfromedge < mindistfromedge) {
								mindistfromedge = distfromedge;
							}
						}

						if ((s32)g_SunScreenYPositions[i] > viewtop + viewheight - 16) {
							distfromedge = viewtop + viewheight - 1 - g_SunScreenYPositions[i];

							if (distfromedge < mindistfromedge) {
								mindistfromedge = distfromedge;
							}
						}

						mindistfromedge -= 1.0f;

						if (mindistfromedge < 0.0f) {
							mindistfromedge = 0.0f;
						}

						g_SunAlphaFracs[i] = mindistfromedge * (1.0f / 15.0f);

						if (g_SunAlphaFracs[i] > 1.0f) {
							g_SunAlphaFracs[i] = 1.0f;
						}

						skyCreateArtifact(&artifacts[i * 8 + 0], (s32)g_SunScreenXPositions[i] - 7, (s32)g_SunScreenYPositions[i] + 1);
						skyCreateArtifact(&artifacts[i * 8 + 1], (s32)g_SunScreenXPositions[i] - 5, (s32)g_SunScreenYPositions[i] - 3);
						skyCreateArtifact(&artifacts[i * 8 + 2], (s32)g_SunScreenXPositions[i] - 3, (s32)g_SunScreenYPositions[i] + 5);
						skyCreateArtifact(&artifacts[i * 8 + 3], (s32)g_SunScreenXPositions[i] - 1, (s32)g_SunScreenYPositions[i] - 7);
						skyCreateArtifact(&artifacts[i * 8 + 4], (s32)g_SunScreenXPositions[i] + 1, (s32)g_SunScreenYPositions[i] + 7);
						skyCreateArtifact(&artifacts[i * 8 + 5], (s32)g_SunScreenXPositions[i] + 3, (s32)g_SunScreenYPositions[i] - 5);
						skyCreateArtifact(&artifacts[i * 8 + 6], (s32)g_SunScreenXPositions[i] + 5, (s32)g_SunScreenYPositions[i] + 3);
						skyCreateArtifact(&artifacts[i * 8 + 7], (s32)g_SunScreenXPositions[i] + 7, (s32)g_SunScreenYPositions[i] - 1);
					}

					if (1);

					g_SunFlareTimers240[i] += g_Vars.lvupdate240;

					texSelect(&gdl, &g_TexLightGlareConfigs[5], 4, 0, 2, 1, NULL);

					gDPSetCycleType(gdl++, G_CYC_1CYCLE);
					gDPSetColorDither(gdl++, G_CD_DISABLE);
					gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
					gDPSetTexturePersp(gdl++, G_TP_NONE);
					gDPSetAlphaCompare(gdl++, G_AC_NONE);
					gDPSetTextureLOD(gdl++, G_TL_TILE);
					gDPSetTextureConvert(gdl++, G_TC_FILT);
					gDPSetTextureLUT(gdl++, G_TT_NONE);
					gDPSetTextureFilter(gdl++, G_TF_BILERP);
					gDPSetCombineLERP(gdl++,
							ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0,
							ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0);
					gDPSetEnvColor(gdl++, colour[0], colour[1], colour[2], (s32)(g_SunAlphaFracs[i] * 255.0f));

					sp134[0] = g_SunScreenXPositions[i];
					sp134[1] = g_SunScreenYPositions[i];
					sp12c[0] = radius * 0.50f * xscale;
					sp12c[1] = radius * 0.50f;

					func0f0b2150(&gdl, sp134, sp12c, g_TexLightGlareConfigs[5].width, g_TexLightGlareConfigs[5].height, 0, 1, 1, 1, 0, 1);

					gDPPipeSync(gdl++);
					gDPSetColorDither(gdl++, G_CD_BAYER);
					gDPSetTexturePersp(gdl++, G_TP_PERSP);
					gDPSetTextureLOD(gdl++, G_TL_LOD);

					sp124 = sky0f125a1c(&schedGetFrontArtifacts()[i * 8]);
				}

				if (onscreen && sp124 > 0.0f) {
					g_SunFlareTimers240[i] += g_Vars.lvupdate240;
				} else {
					g_SunFlareTimers240[i] = 0;
				}
			}
		}

		sun++;
	}

	return gdl;
}

#if VERSION == VERSION_PAL_FINAL
GLOBAL_ASM(
glabel sky0f126384
.late_rodata
glabel var7f1b510c
.word 0x3c23d70a
glabel var7f1b5110
.word 0x3bda740e
glabel var7f1b5114
.word 0x3d23d70a
glabel var7f1b5118
.word 0x3c4ccccd
glabel var7f1b511c
.word 0x3dcccccd
.text
/*  f126e68:	27bdfe68 */ 	addiu	$sp,$sp,-408
/*  f126e6c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f126e70:	afbf008c */ 	sw	$ra,0x8c($sp)
/*  f126e74:	afbe0088 */ 	sw	$s8,0x88($sp)
/*  f126e78:	afb70084 */ 	sw	$s7,0x84($sp)
/*  f126e7c:	afb60080 */ 	sw	$s6,0x80($sp)
/*  f126e80:	afb5007c */ 	sw	$s5,0x7c($sp)
/*  f126e84:	afb40078 */ 	sw	$s4,0x78($sp)
/*  f126e88:	afb30074 */ 	sw	$s3,0x74($sp)
/*  f126e8c:	afb20070 */ 	sw	$s2,0x70($sp)
/*  f126e90:	afb1006c */ 	sw	$s1,0x6c($sp)
/*  f126e94:	afb00068 */ 	sw	$s0,0x68($sp)
/*  f126e98:	f7be0060 */ 	sdc1	$f30,0x60($sp)
/*  f126e9c:	f7bc0058 */ 	sdc1	$f28,0x58($sp)
/*  f126ea0:	f7ba0050 */ 	sdc1	$f26,0x50($sp)
/*  f126ea4:	f7b80048 */ 	sdc1	$f24,0x48($sp)
/*  f126ea8:	f7b60040 */ 	sdc1	$f22,0x40($sp)
/*  f126eac:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f126eb0:	afa40198 */ 	sw	$a0,0x198($sp)
/*  f126eb4:	25efe070 */ 	addiu	$t7,$t7,-8080
/*  f126eb8:	8de10000 */ 	lw	$at,0x0($t7)
/*  f126ebc:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f126ec0:	27ae0164 */ 	addiu	$t6,$sp,0x164
/*  f126ec4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f126ec8:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f126ecc:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f126ed0:	8de10008 */ 	lw	$at,0x8($t7)
/*  f126ed4:	3c0a8008 */ 	lui	$t2,0x8008
/*  f126ed8:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f126edc:	adc10008 */ 	sw	$at,0x8($t6)
/*  f126ee0:	8de10010 */ 	lw	$at,0x10($t7)
/*  f126ee4:	8de80014 */ 	lw	$t0,0x14($t7)
/*  f126ee8:	254ae088 */ 	addiu	$t2,$t2,-8056
/*  f126eec:	adc10010 */ 	sw	$at,0x10($t6)
/*  f126ef0:	adc80014 */ 	sw	$t0,0x14($t6)
/*  f126ef4:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f126ef8:	8d410000 */ 	lw	$at,0x0($t2)
/*  f126efc:	27a9014c */ 	addiu	$t1,$sp,0x14c
/*  f126f00:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f126f04:	ad210000 */ 	sw	$at,0x0($t1)
/*  f126f08:	8d410008 */ 	lw	$at,0x8($t2)
/*  f126f0c:	8d4d000c */ 	lw	$t5,0xc($t2)
/*  f126f10:	3c188008 */ 	lui	$t8,0x8008
/*  f126f14:	ad210008 */ 	sw	$at,0x8($t1)
/*  f126f18:	ad2d000c */ 	sw	$t5,0xc($t1)
/*  f126f1c:	8d4d0014 */ 	lw	$t5,0x14($t2)
/*  f126f20:	8d410010 */ 	lw	$at,0x10($t2)
/*  f126f24:	2718e0a0 */ 	addiu	$t8,$t8,-8032
/*  f126f28:	ad2d0014 */ 	sw	$t5,0x14($t1)
/*  f126f2c:	ad210010 */ 	sw	$at,0x10($t1)
/*  f126f30:	8f080004 */ 	lw	$t0,0x4($t8)
/*  f126f34:	8f010000 */ 	lw	$at,0x0($t8)
/*  f126f38:	27b90134 */ 	addiu	$t9,$sp,0x134
/*  f126f3c:	af280004 */ 	sw	$t0,0x4($t9)
/*  f126f40:	af210000 */ 	sw	$at,0x0($t9)
/*  f126f44:	8f010008 */ 	lw	$at,0x8($t8)
/*  f126f48:	8f08000c */ 	lw	$t0,0xc($t8)
/*  f126f4c:	4487b000 */ 	mtc1	$a3,$f22
/*  f126f50:	af210008 */ 	sw	$at,0x8($t9)
/*  f126f54:	af28000c */ 	sw	$t0,0xc($t9)
/*  f126f58:	8f080014 */ 	lw	$t0,0x14($t8)
/*  f126f5c:	8f010010 */ 	lw	$at,0x10($t8)
/*  f126f60:	4485d000 */ 	mtc1	$a1,$f26
/*  f126f64:	4486e000 */ 	mtc1	$a2,$f28
/*  f126f68:	af280014 */ 	sw	$t0,0x14($t9)
/*  f126f6c:	0c002e73 */ 	jal	viGetViewWidth
/*  f126f70:	af210010 */ 	sw	$at,0x10($t9)
/*  f126f74:	44822000 */ 	mtc1	$v0,$f4
/*  f126f78:	3c017f1b */ 	lui	$at,0x7f1b
/*  f126f7c:	c43463fc */ 	lwc1	$f20,0x63fc($at)
/*  f126f80:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f126f84:	3c013f00 */ 	lui	$at,0x3f00
/*  f126f88:	4481f000 */ 	mtc1	$at,$f30
/*  f126f8c:	00000000 */ 	nop
/*  f126f90:	461e3202 */ 	mul.s	$f8,$f6,$f30
/*  f126f94:	4608d281 */ 	sub.s	$f10,$f26,$f8
/*  f126f98:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f126f9c:	0c002e77 */ 	jal	viGetViewHeight
/*  f126fa0:	e7a40130 */ 	swc1	$f4,0x130($sp)
/*  f126fa4:	44823000 */ 	mtc1	$v0,$f6
/*  f126fa8:	3c16800b */ 	lui	$s6,0x800b
/*  f126fac:	26d6bb40 */ 	addiu	$s6,$s6,-17600
/*  f126fb0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f126fb4:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f126fb8:	27b50198 */ 	addiu	$s5,$sp,0x198
/*  f126fbc:	240c0002 */ 	li	$t4,0x2
/*  f126fc0:	240b0001 */ 	li	$t3,0x1
/*  f126fc4:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f126fc8:	461e4282 */ 	mul.s	$f10,$f8,$f30
/*  f126fcc:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f126fd0:	02a02025 */ 	move	$a0,$s5
/*  f126fd4:	24060004 */ 	li	$a2,0x4
/*  f126fd8:	00003825 */ 	move	$a3,$zero
/*  f126fdc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f126fe0:	24a50048 */ 	addiu	$a1,$a1,0x48
/*  f126fe4:	460ae101 */ 	sub.s	$f4,$f28,$f10
/*  f126fe8:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f126fec:	0fc2cfb8 */ 	jal	texSelect
/*  f126ff0:	e7a6012c */ 	swc1	$f6,0x12c($sp)
/*  f126ff4:	8fa90198 */ 	lw	$t1,0x198($sp)
/*  f126ff8:	3c10ba00 */ 	lui	$s0,0xba00
/*  f126ffc:	36101402 */ 	ori	$s0,$s0,0x1402
/*  f127000:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f127004:	afaa0198 */ 	sw	$t2,0x198($sp)
/*  f127008:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f12700c:	ad300000 */ 	sw	$s0,0x0($t1)
/*  f127010:	8fad0198 */ 	lw	$t5,0x198($sp)
/*  f127014:	3c0eba00 */ 	lui	$t6,0xba00
/*  f127018:	35ce0602 */ 	ori	$t6,$t6,0x602
/*  f12701c:	25af0008 */ 	addiu	$t7,$t5,0x8
/*  f127020:	afaf0198 */ 	sw	$t7,0x198($sp)
/*  f127024:	24190040 */ 	li	$t9,0x40
/*  f127028:	adb90004 */ 	sw	$t9,0x4($t5)
/*  f12702c:	adae0000 */ 	sw	$t6,0x0($t5)
/*  f127030:	8fb80198 */ 	lw	$t8,0x198($sp)
/*  f127034:	3c0cba00 */ 	lui	$t4,0xba00
/*  f127038:	358c0402 */ 	ori	$t4,$t4,0x402
/*  f12703c:	27080008 */ 	addiu	$t0,$t8,0x8
/*  f127040:	afa80198 */ 	sw	$t0,0x198($sp)
/*  f127044:	af000004 */ 	sw	$zero,0x4($t8)
/*  f127048:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f12704c:	8fab0198 */ 	lw	$t3,0x198($sp)
/*  f127050:	3c11b900 */ 	lui	$s1,0xb900
/*  f127054:	3c120050 */ 	lui	$s2,0x50
/*  f127058:	25690008 */ 	addiu	$t1,$t3,0x8
/*  f12705c:	afa90198 */ 	sw	$t1,0x198($sp)
/*  f127060:	365241c8 */ 	ori	$s2,$s2,0x41c8
/*  f127064:	3631031d */ 	ori	$s1,$s1,0x31d
/*  f127068:	ad710000 */ 	sw	$s1,0x0($t3)
/*  f12706c:	ad720004 */ 	sw	$s2,0x4($t3)
/*  f127070:	8faa0198 */ 	lw	$t2,0x198($sp)
/*  f127074:	3c0fba00 */ 	lui	$t7,0xba00
/*  f127078:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f12707c:	254d0008 */ 	addiu	$t5,$t2,0x8
/*  f127080:	afad0198 */ 	sw	$t5,0x198($sp)
/*  f127084:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f127088:	ad4f0000 */ 	sw	$t7,0x0($t2)
/*  f12708c:	8fae0198 */ 	lw	$t6,0x198($sp)
/*  f127090:	3c13b900 */ 	lui	$s3,0xb900
/*  f127094:	36730002 */ 	ori	$s3,$s3,0x2
/*  f127098:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f12709c:	afb90198 */ 	sw	$t9,0x198($sp)
/*  f1270a0:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f1270a4:	add30000 */ 	sw	$s3,0x0($t6)
/*  f1270a8:	8fb80198 */ 	lw	$t8,0x198($sp)
/*  f1270ac:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1270b0:	358c1001 */ 	ori	$t4,$t4,0x1001
/*  f1270b4:	27080008 */ 	addiu	$t0,$t8,0x8
/*  f1270b8:	afa80198 */ 	sw	$t0,0x198($sp)
/*  f1270bc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f1270c0:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f1270c4:	8fab0198 */ 	lw	$t3,0x198($sp)
/*  f1270c8:	3c14ba00 */ 	lui	$s4,0xba00
/*  f1270cc:	36940903 */ 	ori	$s4,$s4,0x903
/*  f1270d0:	25690008 */ 	addiu	$t1,$t3,0x8
/*  f1270d4:	afa90198 */ 	sw	$t1,0x198($sp)
/*  f1270d8:	240a0c00 */ 	li	$t2,0xc00
/*  f1270dc:	ad6a0004 */ 	sw	$t2,0x4($t3)
/*  f1270e0:	ad740000 */ 	sw	$s4,0x0($t3)
/*  f1270e4:	8fad0198 */ 	lw	$t5,0x198($sp)
/*  f1270e8:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1270ec:	35ce0e02 */ 	ori	$t6,$t6,0xe02
/*  f1270f0:	25af0008 */ 	addiu	$t7,$t5,0x8
/*  f1270f4:	afaf0198 */ 	sw	$t7,0x198($sp)
/*  f1270f8:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f1270fc:	adae0000 */ 	sw	$t6,0x0($t5)
/*  f127100:	8fb90198 */ 	lw	$t9,0x198($sp)
/*  f127104:	3c08ba00 */ 	lui	$t0,0xba00
/*  f127108:	35080c02 */ 	ori	$t0,$t0,0xc02
/*  f12710c:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f127110:	afb80198 */ 	sw	$t8,0x198($sp)
/*  f127114:	240c2000 */ 	li	$t4,0x2000
/*  f127118:	af2c0004 */ 	sw	$t4,0x4($t9)
/*  f12711c:	af280000 */ 	sw	$t0,0x0($t9)
/*  f127120:	8fab0198 */ 	lw	$t3,0x198($sp)
/*  f127124:	3c0dff36 */ 	lui	$t5,0xff36
/*  f127128:	3c0afcff */ 	lui	$t2,0xfcff
/*  f12712c:	25690008 */ 	addiu	$t1,$t3,0x8
/*  f127130:	afa90198 */ 	sw	$t1,0x198($sp)
/*  f127134:	354a9bff */ 	ori	$t2,$t2,0x9bff
/*  f127138:	35adff7f */ 	ori	$t5,$t5,0xff7f
/*  f12713c:	ad6d0004 */ 	sw	$t5,0x4($t3)
/*  f127140:	0c002eee */ 	jal	viGetFovY
/*  f127144:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f127148:	8faf0198 */ 	lw	$t7,0x198($sp)
/*  f12714c:	3c17fb00 */ 	lui	$s7,0xfb00
/*  f127150:	3c013f00 */ 	lui	$at,0x3f00
/*  f127154:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f127158:	afae0198 */ 	sw	$t6,0x198($sp)
/*  f12715c:	adf70000 */ 	sw	$s7,0x0($t7)
/*  f127160:	c7a801b0 */ 	lwc1	$f8,0x1b0($sp)
/*  f127164:	4481a000 */ 	mtc1	$at,$f20
/*  f127168:	3c01437f */ 	lui	$at,0x437f
/*  f12716c:	46164282 */ 	mul.s	$f10,$f8,$f22
/*  f127170:	44812000 */ 	mtc1	$at,$f4
/*  f127174:	2401ff00 */ 	li	$at,-256
/*  f127178:	240a0001 */ 	li	$t2,0x1
/*  f12717c:	27be0184 */ 	addiu	$s8,$sp,0x184
/*  f127180:	240e0001 */ 	li	$t6,0x1
/*  f127184:	24190001 */ 	li	$t9,0x1
/*  f127188:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f12718c:	03c02825 */ 	move	$a1,$s8
/*  f127190:	02a02025 */ 	move	$a0,$s5
/*  f127194:	4616a102 */ 	mul.s	$f4,$f20,$f22
/*  f127198:	27a6017c */ 	addiu	$a2,$sp,0x17c
/*  f12719c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f1271a0:	4604a180 */ 	add.s	$f6,$f20,$f4
/*  f1271a4:	44184000 */ 	mfc1	$t8,$f8
/*  f1271a8:	00000000 */ 	nop
/*  f1271ac:	330800ff */ 	andi	$t0,$t8,0xff
/*  f1271b0:	01016025 */ 	or	$t4,$t0,$at
/*  f1271b4:	adec0004 */ 	sw	$t4,0x4($t7)
/*  f1271b8:	c7aa01a8 */ 	lwc1	$f10,0x1a8($sp)
/*  f1271bc:	3c014270 */ 	lui	$at,0x4270
/*  f1271c0:	44812000 */ 	mtc1	$at,$f4
/*  f1271c4:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f1271c8:	8ec20000 */ 	lw	$v0,0x0($s6)
/*  f1271cc:	e7ba0184 */ 	swc1	$f26,0x184($sp)
/*  f1271d0:	e7bc0188 */ 	swc1	$f28,0x188($sp)
/*  f1271d4:	240f0001 */ 	li	$t7,0x1
/*  f1271d8:	24180001 */ 	li	$t8,0x1
/*  f1271dc:	46002283 */ 	div.s	$f10,$f4,$f0
/*  f1271e0:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f1271e4:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f1271e8:	448a3000 */ 	mtc1	$t2,$f6
/*  f1271ec:	44092000 */ 	mfc1	$t1,$f4
/*  f1271f0:	46803620 */ 	cvt.s.w	$f24,$f6
/*  f1271f4:	44895000 */ 	mtc1	$t1,$f10
/*  f1271f8:	00000000 */ 	nop
/*  f1271fc:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f127200:	46144082 */ 	mul.s	$f2,$f8,$f20
/*  f127204:	00000000 */ 	nop
/*  f127208:	46181102 */ 	mul.s	$f4,$f2,$f24
/*  f12720c:	e7a20180 */ 	swc1	$f2,0x180($sp)
/*  f127210:	e7a4017c */ 	swc1	$f4,0x17c($sp)
/*  f127214:	904d004d */ 	lbu	$t5,0x4d($v0)
/*  f127218:	9047004c */ 	lbu	$a3,0x4c($v0)
/*  f12721c:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f127220:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f127224:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f127228:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f12722c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f127230:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f127234:	0fc2c99c */ 	jal	func0f0b2150
/*  f127238:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f12723c:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f127240:	24080002 */ 	li	$t0,0x2
/*  f127244:	240c0001 */ 	li	$t4,0x1
/*  f127248:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f12724c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f127250:	02a02025 */ 	move	$a0,$s5
/*  f127254:	24060004 */ 	li	$a2,0x4
/*  f127258:	00003825 */ 	move	$a3,$zero
/*  f12725c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f127260:	0fc2cfb8 */ 	jal	texSelect
/*  f127264:	24a5000c */ 	addiu	$a1,$a1,0xc
/*  f127268:	8fab0198 */ 	lw	$t3,0x198($sp)
/*  f12726c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f127270:	35ef0602 */ 	ori	$t7,$t7,0x602
/*  f127274:	25690008 */ 	addiu	$t1,$t3,0x8
/*  f127278:	afa90198 */ 	sw	$t1,0x198($sp)
/*  f12727c:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f127280:	ad700000 */ 	sw	$s0,0x0($t3)
/*  f127284:	8faa0198 */ 	lw	$t2,0x198($sp)
/*  f127288:	240e0040 */ 	li	$t6,0x40
/*  f12728c:	3c08ba00 */ 	lui	$t0,0xba00
/*  f127290:	254d0008 */ 	addiu	$t5,$t2,0x8
/*  f127294:	afad0198 */ 	sw	$t5,0x198($sp)
/*  f127298:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*  f12729c:	ad4f0000 */ 	sw	$t7,0x0($t2)
/*  f1272a0:	8fb90198 */ 	lw	$t9,0x198($sp)
/*  f1272a4:	35080402 */ 	ori	$t0,$t0,0x402
/*  f1272a8:	3c0dba00 */ 	lui	$t5,0xba00
/*  f1272ac:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f1272b0:	afb80198 */ 	sw	$t8,0x198($sp)
/*  f1272b4:	af200004 */ 	sw	$zero,0x4($t9)
/*  f1272b8:	af280000 */ 	sw	$t0,0x0($t9)
/*  f1272bc:	8fac0198 */ 	lw	$t4,0x198($sp)
/*  f1272c0:	35ad1301 */ 	ori	$t5,$t5,0x1301
/*  f1272c4:	3c08ba00 */ 	lui	$t0,0xba00
/*  f1272c8:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f1272cc:	afab0198 */ 	sw	$t3,0x198($sp)
/*  f1272d0:	ad920004 */ 	sw	$s2,0x4($t4)
/*  f1272d4:	ad910000 */ 	sw	$s1,0x0($t4)
/*  f1272d8:	8fa90198 */ 	lw	$t1,0x198($sp)
/*  f1272dc:	35081001 */ 	ori	$t0,$t0,0x1001
/*  f1272e0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1272e4:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f1272e8:	afaa0198 */ 	sw	$t2,0x198($sp)
/*  f1272ec:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f1272f0:	ad2d0000 */ 	sw	$t5,0x0($t1)
/*  f1272f4:	8faf0198 */ 	lw	$t7,0x198($sp)
/*  f1272f8:	24090c00 */ 	li	$t1,0xc00
/*  f1272fc:	4480b000 */ 	mtc1	$zero,$f22
/*  f127300:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f127304:	afae0198 */ 	sw	$t6,0x198($sp)
/*  f127308:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f12730c:	adf30000 */ 	sw	$s3,0x0($t7)
/*  f127310:	8fb90198 */ 	lw	$t9,0x198($sp)
/*  f127314:	3c0fba00 */ 	lui	$t7,0xba00
/*  f127318:	35ef0e02 */ 	ori	$t7,$t7,0xe02
/*  f12731c:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f127320:	afb80198 */ 	sw	$t8,0x198($sp)
/*  f127324:	af200004 */ 	sw	$zero,0x4($t9)
/*  f127328:	af280000 */ 	sw	$t0,0x0($t9)
/*  f12732c:	8fac0198 */ 	lw	$t4,0x198($sp)
/*  f127330:	3c18ba00 */ 	lui	$t8,0xba00
/*  f127334:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f127338:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f12733c:	afab0198 */ 	sw	$t3,0x198($sp)
/*  f127340:	ad890004 */ 	sw	$t1,0x4($t4)
/*  f127344:	ad940000 */ 	sw	$s4,0x0($t4)
/*  f127348:	8faa0198 */ 	lw	$t2,0x198($sp)
/*  f12734c:	24082000 */ 	li	$t0,0x2000
/*  f127350:	3c09fcff */ 	lui	$t1,0xfcff
/*  f127354:	254d0008 */ 	addiu	$t5,$t2,0x8
/*  f127358:	afad0198 */ 	sw	$t5,0x198($sp)
/*  f12735c:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f127360:	ad4f0000 */ 	sw	$t7,0x0($t2)
/*  f127364:	8fae0198 */ 	lw	$t6,0x198($sp)
/*  f127368:	3c0aff36 */ 	lui	$t2,0xff36
/*  f12736c:	354aff7f */ 	ori	$t2,$t2,0xff7f
/*  f127370:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f127374:	afb90198 */ 	sw	$t9,0x198($sp)
/*  f127378:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f12737c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f127380:	8fac0198 */ 	lw	$t4,0x198($sp)
/*  f127384:	35299bff */ 	ori	$t1,$t1,0x9bff
/*  f127388:	27b4014c */ 	addiu	$s4,$sp,0x14c
/*  f12738c:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f127390:	afab0198 */ 	sw	$t3,0x198($sp)
/*  f127394:	ad8a0004 */ 	sw	$t2,0x4($t4)
/*  f127398:	ad890000 */ 	sw	$t1,0x0($t4)
/*  f12739c:	c43e6400 */ 	lwc1	$f30,0x6400($at)
/*  f1273a0:	3c014316 */ 	lui	$at,0x4316
/*  f1273a4:	e7bc01a0 */ 	swc1	$f28,0x1a0($sp)
/*  f1273a8:	4481e000 */ 	mtc1	$at,$f28
/*  f1273ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f1273b0:	e7ba019c */ 	swc1	$f26,0x19c($sp)
/*  f1273b4:	4481d000 */ 	mtc1	$at,$f26
/*  f1273b8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1273bc:	e7b80094 */ 	swc1	$f24,0x94($sp)
/*  f1273c0:	c4386404 */ 	lwc1	$f24,0x6404($at)
/*  f1273c4:	8fb301ac */ 	lw	$s3,0x1ac($sp)
/*  f1273c8:	27b1014c */ 	addiu	$s1,$sp,0x14c
/*  f1273cc:	27b20164 */ 	addiu	$s2,$sp,0x164
/*  f1273d0:	27b00134 */ 	addiu	$s0,$sp,0x134
.PF0f1273d4:
/*  f1273d4:	2a61004b */ 	slti	$at,$s3,0x4b
/*  f1273d8:	1020000c */ 	beqz	$at,.PF0f12740c
/*  f1273dc:	266dffb5 */ 	addiu	$t5,$s3,-75
/*  f1273e0:	2a610019 */ 	slti	$at,$s3,0x19
/*  f1273e4:	10200007 */ 	beqz	$at,.PF0f127404
/*  f1273e8:	00000000 */ 	nop
/*  f1273ec:	44935000 */ 	mtc1	$s3,$f10
/*  f1273f0:	00000000 */ 	nop
/*  f1273f4:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f1273f8:	46184082 */ 	mul.s	$f2,$f8,$f24
/*  f1273fc:	10000011 */ 	b	.PF0f127444
/*  f127400:	8e2f0000 */ 	lw	$t7,0x0($s1)
.PF0f127404:
/*  f127404:	1000000e */ 	b	.PF0f127440
/*  f127408:	4600d086 */ 	mov.s	$f2,$f26
.PF0f12740c:
/*  f12740c:	448d3000 */ 	mtc1	$t5,$f6
/*  f127410:	00000000 */ 	nop
/*  f127414:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f127418:	4604e281 */ 	sub.s	$f10,$f28,$f4
/*  f12741c:	461e5202 */ 	mul.s	$f8,$f10,$f30
/*  f127420:	00000000 */ 	nop
/*  f127424:	46144082 */ 	mul.s	$f2,$f8,$f20
/*  f127428:	4616103c */ 	c.lt.s	$f2,$f22
/*  f12742c:	00000000 */ 	nop
/*  f127430:	45000002 */ 	bc1f	.PF0f12743c
/*  f127434:	00000000 */ 	nop
/*  f127438:	4600b086 */ 	mov.s	$f2,$f22
.PF0f12743c:
/*  f12743c:	46141080 */ 	add.s	$f2,$f2,$f20
.PF0f127440:
/*  f127440:	8e2f0000 */ 	lw	$t7,0x0($s1)
.PF0f127444:
/*  f127444:	c7aa0130 */ 	lwc1	$f10,0x130($sp)
/*  f127448:	8fa30198 */ 	lw	$v1,0x198($sp)
/*  f12744c:	448f3000 */ 	mtc1	$t7,$f6
/*  f127450:	c7a4019c */ 	lwc1	$f4,0x19c($sp)
/*  f127454:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f127458:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f12745c:	24780008 */ 	addiu	$t8,$v1,0x8
/*  f127460:	c7a601a0 */ 	lwc1	$f6,0x1a0($sp)
/*  f127464:	afb80198 */ 	sw	$t8,0x198($sp)
/*  f127468:	3c014f80 */ 	lui	$at,0x4f80
/*  f12746c:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f127470:	c7aa012c */ 	lwc1	$f10,0x12c($sp)
/*  f127474:	ac770000 */ 	sw	$s7,0x0($v1)
/*  f127478:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f12747c:	304800ff */ 	andi	$t0,$v0,0xff
/*  f127480:	46082301 */ 	sub.s	$f12,$f4,$f8
/*  f127484:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f127488:	448e4000 */ 	mtc1	$t6,$f8
/*  f12748c:	44885000 */ 	mtc1	$t0,$f10
/*  f127490:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f127494:	c7a801b0 */ 	lwc1	$f8,0x1b0($sp)
/*  f127498:	46043381 */ 	sub.s	$f14,$f6,$f4
/*  f12749c:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f1274a0:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f1274a4:	05010004 */ 	bgez	$t0,.PF0f1274b8
/*  f1274a8:	00000000 */ 	nop
/*  f1274ac:	44812000 */ 	mtc1	$at,$f4
/*  f1274b0:	00000000 */ 	nop
/*  f1274b4:	46043180 */ 	add.s	$f6,$f6,$f4
.PF0f1274b8:
/*  f1274b8:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f1274bc:	02a02025 */ 	move	$a0,$s5
/*  f1274c0:	00027e02 */ 	srl	$t7,$v0,0x18
/*  f1274c4:	000f7600 */ 	sll	$t6,$t7,0x18
/*  f1274c8:	00024402 */ 	srl	$t0,$v0,0x10
/*  f1274cc:	310c00ff */ 	andi	$t4,$t0,0xff
/*  f1274d0:	00027a02 */ 	srl	$t7,$v0,0x8
/*  f1274d4:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f1274d8:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f1274dc:	03c02825 */ 	move	$a1,$s8
/*  f1274e0:	27a6017c */ 	addiu	$a2,$sp,0x17c
/*  f1274e4:	440b4000 */ 	mfc1	$t3,$f8
/*  f1274e8:	00000000 */ 	nop
/*  f1274ec:	316900ff */ 	andi	$t1,$t3,0xff
/*  f1274f0:	012ec825 */ 	or	$t9,$t1,$t6
/*  f1274f4:	31e900ff */ 	andi	$t1,$t7,0xff
/*  f1274f8:	000c5c00 */ 	sll	$t3,$t4,0x10
/*  f1274fc:	032b5025 */ 	or	$t2,$t9,$t3
/*  f127500:	00097200 */ 	sll	$t6,$t1,0x8
/*  f127504:	014ec025 */ 	or	$t8,$t2,$t6
/*  f127508:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f12750c:	c7a60094 */ 	lwc1	$f6,0x94($sp)
/*  f127510:	8ec20000 */ 	lw	$v0,0x0($s6)
/*  f127514:	e7ac0184 */ 	swc1	$f12,0x184($sp)
/*  f127518:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f12751c:	e7ae0188 */ 	swc1	$f14,0x188($sp)
/*  f127520:	e7b20180 */ 	swc1	$f18,0x180($sp)
/*  f127524:	240c0001 */ 	li	$t4,0x1
/*  f127528:	e7aa017c */ 	swc1	$f10,0x17c($sp)
/*  f12752c:	90480011 */ 	lbu	$t0,0x11($v0)
/*  f127530:	90470010 */ 	lbu	$a3,0x10($v0)
/*  f127534:	afac0028 */ 	sw	$t4,0x28($sp)
/*  f127538:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f12753c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f127540:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f127544:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f127548:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f12754c:	0fc2c99c */ 	jal	func0f0b2150
/*  f127550:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f127554:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f127558:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f12755c:	1614ff9d */ 	bne	$s0,$s4,.PF0f1273d4
/*  f127560:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f127564:	0c002e73 */ 	jal	viGetViewWidth
/*  f127568:	00000000 */ 	nop
/*  f12756c:	44822000 */ 	mtc1	$v0,$f4
/*  f127570:	3c013f00 */ 	lui	$at,0x3f00
/*  f127574:	4481c000 */ 	mtc1	$at,$f24
/*  f127578:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f12757c:	c7aa019c */ 	lwc1	$f10,0x19c($sp)
/*  f127580:	46184182 */ 	mul.s	$f6,$f8,$f24
/*  f127584:	0c002e77 */ 	jal	viGetViewHeight
/*  f127588:	460a3501 */ 	sub.s	$f20,$f6,$f10
/*  f12758c:	44822000 */ 	mtc1	$v0,$f4
/*  f127590:	c7aa01a0 */ 	lwc1	$f10,0x1a0($sp)
/*  f127594:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f127598:	46184182 */ 	mul.s	$f6,$f8,$f24
/*  f12759c:	460a3001 */ 	sub.s	$f0,$f6,$f10
/*  f1275a0:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f1275a4:	00000000 */ 	nop
/*  f1275a8:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f1275ac:	0c0127b4 */ 	jal	sqrtf
/*  f1275b0:	46082300 */ 	add.s	$f12,$f4,$f8
/*  f1275b4:	3c014220 */ 	lui	$at,0x4220
/*  f1275b8:	44813000 */ 	mtc1	$at,$f6
/*  f1275bc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1275c0:	c4246408 */ 	lwc1	$f4,0x6408($at)
/*  f1275c4:	46003281 */ 	sub.s	$f10,$f6,$f0
/*  f1275c8:	3c19800a */ 	lui	$t9,0x800a
/*  f1275cc:	c7a601b0 */ 	lwc1	$f6,0x1b0($sp)
/*  f1275d0:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f1275d4:	4616603c */ 	c.lt.s	$f12,$f22
/*  f1275d8:	00000000 */ 	nop
/*  f1275dc:	45000002 */ 	bc1f	.PF0f1275e8
/*  f1275e0:	00000000 */ 	nop
/*  f1275e4:	4600b306 */ 	mov.s	$f12,$f22
.PF0f1275e8:
/*  f1275e8:	8f39a544 */ 	lw	$t9,-0x5abc($t9)
/*  f1275ec:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1275f0:	c428640c */ 	lwc1	$f8,0x640c($at)
/*  f1275f4:	0333082a */ 	slt	$at,$t9,$s3
/*  f1275f8:	14200002 */ 	bnez	$at,.PF0f127604
/*  f1275fc:	46086300 */ 	add.s	$f12,$f12,$f8
/*  f127600:	4600b306 */ 	mov.s	$f12,$f22
.PF0f127604:
/*  f127604:	460cb03c */ 	c.lt.s	$f22,$f12
/*  f127608:	00000000 */ 	nop
/*  f12760c:	4502000d */ 	bc1fl	.PF0f127644
/*  f127610:	8fad0198 */ 	lw	$t5,0x198($sp)
/*  f127614:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f127618:	3c01437f */ 	lui	$at,0x437f
/*  f12761c:	44812000 */ 	mtc1	$at,$f4
/*  f127620:	00000000 */ 	nop
/*  f127624:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f127628:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f12762c:	44043000 */ 	mfc1	$a0,$f6
/*  f127630:	00000000 */ 	nop
/*  f127634:	00802825 */ 	move	$a1,$a0
/*  f127638:	0fc49f81 */ 	jal	sky0f127334
/*  f12763c:	00803025 */ 	move	$a2,$a0
/*  f127640:	8fad0198 */ 	lw	$t5,0x198($sp)
.PF0f127644:
/*  f127644:	3c09ba00 */ 	lui	$t1,0xba00
/*  f127648:	35290602 */ 	ori	$t1,$t1,0x602
/*  f12764c:	25af0008 */ 	addiu	$t7,$t5,0x8
/*  f127650:	afaf0198 */ 	sw	$t7,0x198($sp)
/*  f127654:	240a0040 */ 	li	$t2,0x40
/*  f127658:	adaa0004 */ 	sw	$t2,0x4($t5)
/*  f12765c:	ada90000 */ 	sw	$t1,0x0($t5)
/*  f127660:	8fae0198 */ 	lw	$t6,0x198($sp)
/*  f127664:	3c08ba00 */ 	lui	$t0,0xba00
/*  f127668:	35080402 */ 	ori	$t0,$t0,0x402
/*  f12766c:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f127670:	afb80198 */ 	sw	$t8,0x198($sp)
/*  f127674:	240c00c0 */ 	li	$t4,0xc0
/*  f127678:	adcc0004 */ 	sw	$t4,0x4($t6)
/*  f12767c:	adc80000 */ 	sw	$t0,0x0($t6)
/*  f127680:	8fb90198 */ 	lw	$t9,0x198($sp)
/*  f127684:	3c0dba00 */ 	lui	$t5,0xba00
/*  f127688:	35ad1301 */ 	ori	$t5,$t5,0x1301
/*  f12768c:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f127690:	afab0198 */ 	sw	$t3,0x198($sp)
/*  f127694:	3c0f0008 */ 	lui	$t7,0x8
/*  f127698:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f12769c:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f1276a0:	8fa90198 */ 	lw	$t1,0x198($sp)
/*  f1276a4:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1276a8:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f1276ac:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f1276b0:	afaa0198 */ 	sw	$t2,0x198($sp)
/*  f1276b4:	3c180001 */ 	lui	$t8,0x1
/*  f1276b8:	ad380004 */ 	sw	$t8,0x4($t1)
/*  f1276bc:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*  f1276c0:	8fbf008c */ 	lw	$ra,0x8c($sp)
/*  f1276c4:	8fbe0088 */ 	lw	$s8,0x88($sp)
/*  f1276c8:	8fb70084 */ 	lw	$s7,0x84($sp)
/*  f1276cc:	8fb60080 */ 	lw	$s6,0x80($sp)
/*  f1276d0:	8fb5007c */ 	lw	$s5,0x7c($sp)
/*  f1276d4:	8fb40078 */ 	lw	$s4,0x78($sp)
/*  f1276d8:	8fb30074 */ 	lw	$s3,0x74($sp)
/*  f1276dc:	8fb20070 */ 	lw	$s2,0x70($sp)
/*  f1276e0:	8fb1006c */ 	lw	$s1,0x6c($sp)
/*  f1276e4:	8fb00068 */ 	lw	$s0,0x68($sp)
/*  f1276e8:	d7be0060 */ 	ldc1	$f30,0x60($sp)
/*  f1276ec:	d7bc0058 */ 	ldc1	$f28,0x58($sp)
/*  f1276f0:	d7ba0050 */ 	ldc1	$f26,0x50($sp)
/*  f1276f4:	d7b80048 */ 	ldc1	$f24,0x48($sp)
/*  f1276f8:	d7b60040 */ 	ldc1	$f22,0x40($sp)
/*  f1276fc:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f127700:	8fa20198 */ 	lw	$v0,0x198($sp)
/*  f127704:	03e00008 */ 	jr	$ra
/*  f127708:	27bd0198 */ 	addiu	$sp,$sp,0x198
);
#elif VERSION == VERSION_PAL_BETA
GLOBAL_ASM(
glabel sky0f126384
.late_rodata
glabel var7f1b510c
.word 0x3c23d70a
glabel var7f1b5110
.word 0x3bda740e
glabel var7f1b5114
.word 0x3d23d70a
glabel var7f1b5118
.word 0x3c4ccccd
glabel var7f1b511c
.word 0x3dcccccd
.text
/*  f127878:	27bdfe68 */ 	addiu	$sp,$sp,-408
/*  f12787c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f127880:	afbf008c */ 	sw	$ra,0x8c($sp)
/*  f127884:	afbe0088 */ 	sw	$s8,0x88($sp)
/*  f127888:	afb70084 */ 	sw	$s7,0x84($sp)
/*  f12788c:	afb60080 */ 	sw	$s6,0x80($sp)
/*  f127890:	afb5007c */ 	sw	$s5,0x7c($sp)
/*  f127894:	afb40078 */ 	sw	$s4,0x78($sp)
/*  f127898:	afb30074 */ 	sw	$s3,0x74($sp)
/*  f12789c:	afb20070 */ 	sw	$s2,0x70($sp)
/*  f1278a0:	afb1006c */ 	sw	$s1,0x6c($sp)
/*  f1278a4:	afb00068 */ 	sw	$s0,0x68($sp)
/*  f1278a8:	f7be0060 */ 	sdc1	$f30,0x60($sp)
/*  f1278ac:	f7bc0058 */ 	sdc1	$f28,0x58($sp)
/*  f1278b0:	f7ba0050 */ 	sdc1	$f26,0x50($sp)
/*  f1278b4:	f7b80048 */ 	sdc1	$f24,0x48($sp)
/*  f1278b8:	f7b60040 */ 	sdc1	$f22,0x40($sp)
/*  f1278bc:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f1278c0:	afa40198 */ 	sw	$a0,0x198($sp)
/*  f1278c4:	25ef0070 */ 	addiu	$t7,$t7,0x70
/*  f1278c8:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1278cc:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1278d0:	27ae0164 */ 	addiu	$t6,$sp,0x164
/*  f1278d4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1278d8:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1278dc:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f1278e0:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1278e4:	3c0a8008 */ 	lui	$t2,0x8008
/*  f1278e8:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f1278ec:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1278f0:	8de10010 */ 	lw	$at,0x10($t7)
/*  f1278f4:	8de80014 */ 	lw	$t0,0x14($t7)
/*  f1278f8:	254a0088 */ 	addiu	$t2,$t2,0x88
/*  f1278fc:	adc10010 */ 	sw	$at,0x10($t6)
/*  f127900:	adc80014 */ 	sw	$t0,0x14($t6)
/*  f127904:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f127908:	8d410000 */ 	lw	$at,0x0($t2)
/*  f12790c:	27a9014c */ 	addiu	$t1,$sp,0x14c
/*  f127910:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f127914:	ad210000 */ 	sw	$at,0x0($t1)
/*  f127918:	8d410008 */ 	lw	$at,0x8($t2)
/*  f12791c:	8d4d000c */ 	lw	$t5,0xc($t2)
/*  f127920:	3c188008 */ 	lui	$t8,0x8008
/*  f127924:	ad210008 */ 	sw	$at,0x8($t1)
/*  f127928:	ad2d000c */ 	sw	$t5,0xc($t1)
/*  f12792c:	8d4d0014 */ 	lw	$t5,0x14($t2)
/*  f127930:	8d410010 */ 	lw	$at,0x10($t2)
/*  f127934:	271800a0 */ 	addiu	$t8,$t8,0xa0
/*  f127938:	ad2d0014 */ 	sw	$t5,0x14($t1)
/*  f12793c:	ad210010 */ 	sw	$at,0x10($t1)
/*  f127940:	8f080004 */ 	lw	$t0,0x4($t8)
/*  f127944:	8f010000 */ 	lw	$at,0x0($t8)
/*  f127948:	27b90134 */ 	addiu	$t9,$sp,0x134
/*  f12794c:	af280004 */ 	sw	$t0,0x4($t9)
/*  f127950:	af210000 */ 	sw	$at,0x0($t9)
/*  f127954:	8f010008 */ 	lw	$at,0x8($t8)
/*  f127958:	8f08000c */ 	lw	$t0,0xc($t8)
/*  f12795c:	4487b000 */ 	mtc1	$a3,$f22
/*  f127960:	af210008 */ 	sw	$at,0x8($t9)
/*  f127964:	af28000c */ 	sw	$t0,0xc($t9)
/*  f127968:	8f080014 */ 	lw	$t0,0x14($t8)
/*  f12796c:	8f010010 */ 	lw	$at,0x10($t8)
/*  f127970:	4485d000 */ 	mtc1	$a1,$f26
/*  f127974:	4486e000 */ 	mtc1	$a2,$f28
/*  f127978:	af280014 */ 	sw	$t0,0x14($t9)
/*  f12797c:	0c002e6d */ 	jal	viGetViewWidth
/*  f127980:	af210010 */ 	sw	$at,0x10($t9)
/*  f127984:	44822000 */ 	mtc1	$v0,$f4
/*  f127988:	3c017f1b */ 	lui	$at,0x7f1b
/*  f12798c:	c43470fc */ 	lwc1	$f20,0x70fc($at)
/*  f127990:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f127994:	3c013f00 */ 	lui	$at,0x3f00
/*  f127998:	4481f000 */ 	mtc1	$at,$f30
/*  f12799c:	00000000 */ 	nop
/*  f1279a0:	461e3202 */ 	mul.s	$f8,$f6,$f30
/*  f1279a4:	4608d281 */ 	sub.s	$f10,$f26,$f8
/*  f1279a8:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f1279ac:	0c002e71 */ 	jal	viGetViewHeight
/*  f1279b0:	e7a40130 */ 	swc1	$f4,0x130($sp)
/*  f1279b4:	44823000 */ 	mtc1	$v0,$f6
/*  f1279b8:	3c16800b */ 	lui	$s6,0x800b
/*  f1279bc:	26d6fbc0 */ 	addiu	$s6,$s6,-1088
/*  f1279c0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1279c4:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f1279c8:	27b50198 */ 	addiu	$s5,$sp,0x198
/*  f1279cc:	240c0002 */ 	li	$t4,0x2
/*  f1279d0:	240b0001 */ 	li	$t3,0x1
/*  f1279d4:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f1279d8:	461e4282 */ 	mul.s	$f10,$f8,$f30
/*  f1279dc:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1279e0:	02a02025 */ 	move	$a0,$s5
/*  f1279e4:	24060004 */ 	li	$a2,0x4
/*  f1279e8:	00003825 */ 	move	$a3,$zero
/*  f1279ec:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1279f0:	24a50048 */ 	addiu	$a1,$a1,0x48
/*  f1279f4:	460ae101 */ 	sub.s	$f4,$f28,$f10
/*  f1279f8:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f1279fc:	0fc2cf74 */ 	jal	texSelect
/*  f127a00:	e7a6012c */ 	swc1	$f6,0x12c($sp)
/*  f127a04:	8fa90198 */ 	lw	$t1,0x198($sp)
/*  f127a08:	3c10ba00 */ 	lui	$s0,0xba00
/*  f127a0c:	36101402 */ 	ori	$s0,$s0,0x1402
/*  f127a10:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f127a14:	afaa0198 */ 	sw	$t2,0x198($sp)
/*  f127a18:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f127a1c:	ad300000 */ 	sw	$s0,0x0($t1)
/*  f127a20:	8fad0198 */ 	lw	$t5,0x198($sp)
/*  f127a24:	3c0eba00 */ 	lui	$t6,0xba00
/*  f127a28:	35ce0602 */ 	ori	$t6,$t6,0x602
/*  f127a2c:	25af0008 */ 	addiu	$t7,$t5,0x8
/*  f127a30:	afaf0198 */ 	sw	$t7,0x198($sp)
/*  f127a34:	24190040 */ 	li	$t9,0x40
/*  f127a38:	adb90004 */ 	sw	$t9,0x4($t5)
/*  f127a3c:	adae0000 */ 	sw	$t6,0x0($t5)
/*  f127a40:	8fb80198 */ 	lw	$t8,0x198($sp)
/*  f127a44:	3c0cba00 */ 	lui	$t4,0xba00
/*  f127a48:	358c0402 */ 	ori	$t4,$t4,0x402
/*  f127a4c:	27080008 */ 	addiu	$t0,$t8,0x8
/*  f127a50:	afa80198 */ 	sw	$t0,0x198($sp)
/*  f127a54:	af000004 */ 	sw	$zero,0x4($t8)
/*  f127a58:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f127a5c:	8fab0198 */ 	lw	$t3,0x198($sp)
/*  f127a60:	3c11b900 */ 	lui	$s1,0xb900
/*  f127a64:	3c120050 */ 	lui	$s2,0x50
/*  f127a68:	25690008 */ 	addiu	$t1,$t3,0x8
/*  f127a6c:	afa90198 */ 	sw	$t1,0x198($sp)
/*  f127a70:	365241c8 */ 	ori	$s2,$s2,0x41c8
/*  f127a74:	3631031d */ 	ori	$s1,$s1,0x31d
/*  f127a78:	ad710000 */ 	sw	$s1,0x0($t3)
/*  f127a7c:	ad720004 */ 	sw	$s2,0x4($t3)
/*  f127a80:	8faa0198 */ 	lw	$t2,0x198($sp)
/*  f127a84:	3c0fba00 */ 	lui	$t7,0xba00
/*  f127a88:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f127a8c:	254d0008 */ 	addiu	$t5,$t2,0x8
/*  f127a90:	afad0198 */ 	sw	$t5,0x198($sp)
/*  f127a94:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f127a98:	ad4f0000 */ 	sw	$t7,0x0($t2)
/*  f127a9c:	8fae0198 */ 	lw	$t6,0x198($sp)
/*  f127aa0:	3c13b900 */ 	lui	$s3,0xb900
/*  f127aa4:	36730002 */ 	ori	$s3,$s3,0x2
/*  f127aa8:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f127aac:	afb90198 */ 	sw	$t9,0x198($sp)
/*  f127ab0:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f127ab4:	add30000 */ 	sw	$s3,0x0($t6)
/*  f127ab8:	8fb80198 */ 	lw	$t8,0x198($sp)
/*  f127abc:	3c0cba00 */ 	lui	$t4,0xba00
/*  f127ac0:	358c1001 */ 	ori	$t4,$t4,0x1001
/*  f127ac4:	27080008 */ 	addiu	$t0,$t8,0x8
/*  f127ac8:	afa80198 */ 	sw	$t0,0x198($sp)
/*  f127acc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f127ad0:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f127ad4:	8fab0198 */ 	lw	$t3,0x198($sp)
/*  f127ad8:	3c14ba00 */ 	lui	$s4,0xba00
/*  f127adc:	36940903 */ 	ori	$s4,$s4,0x903
/*  f127ae0:	25690008 */ 	addiu	$t1,$t3,0x8
/*  f127ae4:	afa90198 */ 	sw	$t1,0x198($sp)
/*  f127ae8:	240a0c00 */ 	li	$t2,0xc00
/*  f127aec:	ad6a0004 */ 	sw	$t2,0x4($t3)
/*  f127af0:	ad740000 */ 	sw	$s4,0x0($t3)
/*  f127af4:	8fad0198 */ 	lw	$t5,0x198($sp)
/*  f127af8:	3c0eba00 */ 	lui	$t6,0xba00
/*  f127afc:	35ce0e02 */ 	ori	$t6,$t6,0xe02
/*  f127b00:	25af0008 */ 	addiu	$t7,$t5,0x8
/*  f127b04:	afaf0198 */ 	sw	$t7,0x198($sp)
/*  f127b08:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f127b0c:	adae0000 */ 	sw	$t6,0x0($t5)
/*  f127b10:	8fb90198 */ 	lw	$t9,0x198($sp)
/*  f127b14:	3c08ba00 */ 	lui	$t0,0xba00
/*  f127b18:	35080c02 */ 	ori	$t0,$t0,0xc02
/*  f127b1c:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f127b20:	afb80198 */ 	sw	$t8,0x198($sp)
/*  f127b24:	240c2000 */ 	li	$t4,0x2000
/*  f127b28:	af2c0004 */ 	sw	$t4,0x4($t9)
/*  f127b2c:	af280000 */ 	sw	$t0,0x0($t9)
/*  f127b30:	8fab0198 */ 	lw	$t3,0x198($sp)
/*  f127b34:	3c0dff36 */ 	lui	$t5,0xff36
/*  f127b38:	3c0afcff */ 	lui	$t2,0xfcff
/*  f127b3c:	25690008 */ 	addiu	$t1,$t3,0x8
/*  f127b40:	afa90198 */ 	sw	$t1,0x198($sp)
/*  f127b44:	354a9bff */ 	ori	$t2,$t2,0x9bff
/*  f127b48:	35adff7f */ 	ori	$t5,$t5,0xff7f
/*  f127b4c:	ad6d0004 */ 	sw	$t5,0x4($t3)
/*  f127b50:	0c002ee8 */ 	jal	viGetFovY
/*  f127b54:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f127b58:	8faf0198 */ 	lw	$t7,0x198($sp)
/*  f127b5c:	3c17fb00 */ 	lui	$s7,0xfb00
/*  f127b60:	3c013f00 */ 	lui	$at,0x3f00
/*  f127b64:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f127b68:	afae0198 */ 	sw	$t6,0x198($sp)
/*  f127b6c:	adf70000 */ 	sw	$s7,0x0($t7)
/*  f127b70:	c7a801b0 */ 	lwc1	$f8,0x1b0($sp)
/*  f127b74:	4481a000 */ 	mtc1	$at,$f20
/*  f127b78:	3c01437f */ 	lui	$at,0x437f
/*  f127b7c:	46164282 */ 	mul.s	$f10,$f8,$f22
/*  f127b80:	44812000 */ 	mtc1	$at,$f4
/*  f127b84:	2401ff00 */ 	li	$at,-256
/*  f127b88:	240a0001 */ 	li	$t2,0x1
/*  f127b8c:	27be0184 */ 	addiu	$s8,$sp,0x184
/*  f127b90:	240e0001 */ 	li	$t6,0x1
/*  f127b94:	24190001 */ 	li	$t9,0x1
/*  f127b98:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f127b9c:	03c02825 */ 	move	$a1,$s8
/*  f127ba0:	02a02025 */ 	move	$a0,$s5
/*  f127ba4:	4616a102 */ 	mul.s	$f4,$f20,$f22
/*  f127ba8:	27a6017c */ 	addiu	$a2,$sp,0x17c
/*  f127bac:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f127bb0:	4604a180 */ 	add.s	$f6,$f20,$f4
/*  f127bb4:	44184000 */ 	mfc1	$t8,$f8
/*  f127bb8:	00000000 */ 	nop
/*  f127bbc:	330800ff */ 	andi	$t0,$t8,0xff
/*  f127bc0:	01016025 */ 	or	$t4,$t0,$at
/*  f127bc4:	adec0004 */ 	sw	$t4,0x4($t7)
/*  f127bc8:	c7aa01a8 */ 	lwc1	$f10,0x1a8($sp)
/*  f127bcc:	3c014270 */ 	lui	$at,0x4270
/*  f127bd0:	44812000 */ 	mtc1	$at,$f4
/*  f127bd4:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f127bd8:	8ec20000 */ 	lw	$v0,0x0($s6)
/*  f127bdc:	e7ba0184 */ 	swc1	$f26,0x184($sp)
/*  f127be0:	e7bc0188 */ 	swc1	$f28,0x188($sp)
/*  f127be4:	240f0001 */ 	li	$t7,0x1
/*  f127be8:	24180001 */ 	li	$t8,0x1
/*  f127bec:	46002283 */ 	div.s	$f10,$f4,$f0
/*  f127bf0:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f127bf4:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f127bf8:	448a3000 */ 	mtc1	$t2,$f6
/*  f127bfc:	44092000 */ 	mfc1	$t1,$f4
/*  f127c00:	46803620 */ 	cvt.s.w	$f24,$f6
/*  f127c04:	44895000 */ 	mtc1	$t1,$f10
/*  f127c08:	00000000 */ 	nop
/*  f127c0c:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f127c10:	46144082 */ 	mul.s	$f2,$f8,$f20
/*  f127c14:	00000000 */ 	nop
/*  f127c18:	46181102 */ 	mul.s	$f4,$f2,$f24
/*  f127c1c:	e7a20180 */ 	swc1	$f2,0x180($sp)
/*  f127c20:	e7a4017c */ 	swc1	$f4,0x17c($sp)
/*  f127c24:	904d004d */ 	lbu	$t5,0x4d($v0)
/*  f127c28:	9047004c */ 	lbu	$a3,0x4c($v0)
/*  f127c2c:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f127c30:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f127c34:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f127c38:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f127c3c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f127c40:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f127c44:	0fc2c958 */ 	jal	func0f0b2150
/*  f127c48:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f127c4c:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f127c50:	24080002 */ 	li	$t0,0x2
/*  f127c54:	240c0001 */ 	li	$t4,0x1
/*  f127c58:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f127c5c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f127c60:	02a02025 */ 	move	$a0,$s5
/*  f127c64:	24060004 */ 	li	$a2,0x4
/*  f127c68:	00003825 */ 	move	$a3,$zero
/*  f127c6c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f127c70:	0fc2cf74 */ 	jal	texSelect
/*  f127c74:	24a5000c */ 	addiu	$a1,$a1,0xc
/*  f127c78:	8fab0198 */ 	lw	$t3,0x198($sp)
/*  f127c7c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f127c80:	35ef0602 */ 	ori	$t7,$t7,0x602
/*  f127c84:	25690008 */ 	addiu	$t1,$t3,0x8
/*  f127c88:	afa90198 */ 	sw	$t1,0x198($sp)
/*  f127c8c:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f127c90:	ad700000 */ 	sw	$s0,0x0($t3)
/*  f127c94:	8faa0198 */ 	lw	$t2,0x198($sp)
/*  f127c98:	240e0040 */ 	li	$t6,0x40
/*  f127c9c:	3c08ba00 */ 	lui	$t0,0xba00
/*  f127ca0:	254d0008 */ 	addiu	$t5,$t2,0x8
/*  f127ca4:	afad0198 */ 	sw	$t5,0x198($sp)
/*  f127ca8:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*  f127cac:	ad4f0000 */ 	sw	$t7,0x0($t2)
/*  f127cb0:	8fb90198 */ 	lw	$t9,0x198($sp)
/*  f127cb4:	35080402 */ 	ori	$t0,$t0,0x402
/*  f127cb8:	3c0dba00 */ 	lui	$t5,0xba00
/*  f127cbc:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f127cc0:	afb80198 */ 	sw	$t8,0x198($sp)
/*  f127cc4:	af200004 */ 	sw	$zero,0x4($t9)
/*  f127cc8:	af280000 */ 	sw	$t0,0x0($t9)
/*  f127ccc:	8fac0198 */ 	lw	$t4,0x198($sp)
/*  f127cd0:	35ad1301 */ 	ori	$t5,$t5,0x1301
/*  f127cd4:	3c08ba00 */ 	lui	$t0,0xba00
/*  f127cd8:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f127cdc:	afab0198 */ 	sw	$t3,0x198($sp)
/*  f127ce0:	ad920004 */ 	sw	$s2,0x4($t4)
/*  f127ce4:	ad910000 */ 	sw	$s1,0x0($t4)
/*  f127ce8:	8fa90198 */ 	lw	$t1,0x198($sp)
/*  f127cec:	35081001 */ 	ori	$t0,$t0,0x1001
/*  f127cf0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f127cf4:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f127cf8:	afaa0198 */ 	sw	$t2,0x198($sp)
/*  f127cfc:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f127d00:	ad2d0000 */ 	sw	$t5,0x0($t1)
/*  f127d04:	8faf0198 */ 	lw	$t7,0x198($sp)
/*  f127d08:	24090c00 */ 	li	$t1,0xc00
/*  f127d0c:	4480b000 */ 	mtc1	$zero,$f22
/*  f127d10:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f127d14:	afae0198 */ 	sw	$t6,0x198($sp)
/*  f127d18:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f127d1c:	adf30000 */ 	sw	$s3,0x0($t7)
/*  f127d20:	8fb90198 */ 	lw	$t9,0x198($sp)
/*  f127d24:	3c0fba00 */ 	lui	$t7,0xba00
/*  f127d28:	35ef0e02 */ 	ori	$t7,$t7,0xe02
/*  f127d2c:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f127d30:	afb80198 */ 	sw	$t8,0x198($sp)
/*  f127d34:	af200004 */ 	sw	$zero,0x4($t9)
/*  f127d38:	af280000 */ 	sw	$t0,0x0($t9)
/*  f127d3c:	8fac0198 */ 	lw	$t4,0x198($sp)
/*  f127d40:	3c18ba00 */ 	lui	$t8,0xba00
/*  f127d44:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f127d48:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f127d4c:	afab0198 */ 	sw	$t3,0x198($sp)
/*  f127d50:	ad890004 */ 	sw	$t1,0x4($t4)
/*  f127d54:	ad940000 */ 	sw	$s4,0x0($t4)
/*  f127d58:	8faa0198 */ 	lw	$t2,0x198($sp)
/*  f127d5c:	24082000 */ 	li	$t0,0x2000
/*  f127d60:	3c09fcff */ 	lui	$t1,0xfcff
/*  f127d64:	254d0008 */ 	addiu	$t5,$t2,0x8
/*  f127d68:	afad0198 */ 	sw	$t5,0x198($sp)
/*  f127d6c:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f127d70:	ad4f0000 */ 	sw	$t7,0x0($t2)
/*  f127d74:	8fae0198 */ 	lw	$t6,0x198($sp)
/*  f127d78:	3c0aff36 */ 	lui	$t2,0xff36
/*  f127d7c:	354aff7f */ 	ori	$t2,$t2,0xff7f
/*  f127d80:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f127d84:	afb90198 */ 	sw	$t9,0x198($sp)
/*  f127d88:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f127d8c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f127d90:	8fac0198 */ 	lw	$t4,0x198($sp)
/*  f127d94:	35299bff */ 	ori	$t1,$t1,0x9bff
/*  f127d98:	27b4014c */ 	addiu	$s4,$sp,0x14c
/*  f127d9c:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f127da0:	afab0198 */ 	sw	$t3,0x198($sp)
/*  f127da4:	ad8a0004 */ 	sw	$t2,0x4($t4)
/*  f127da8:	ad890000 */ 	sw	$t1,0x0($t4)
/*  f127dac:	c43e7100 */ 	lwc1	$f30,0x7100($at)
/*  f127db0:	3c014316 */ 	lui	$at,0x4316
/*  f127db4:	e7bc01a0 */ 	swc1	$f28,0x1a0($sp)
/*  f127db8:	4481e000 */ 	mtc1	$at,$f28
/*  f127dbc:	3c013f80 */ 	lui	$at,0x3f80
/*  f127dc0:	e7ba019c */ 	swc1	$f26,0x19c($sp)
/*  f127dc4:	4481d000 */ 	mtc1	$at,$f26
/*  f127dc8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f127dcc:	e7b80094 */ 	swc1	$f24,0x94($sp)
/*  f127dd0:	c4387104 */ 	lwc1	$f24,0x7104($at)
/*  f127dd4:	8fb301ac */ 	lw	$s3,0x1ac($sp)
/*  f127dd8:	27b1014c */ 	addiu	$s1,$sp,0x14c
/*  f127ddc:	27b20164 */ 	addiu	$s2,$sp,0x164
/*  f127de0:	27b00134 */ 	addiu	$s0,$sp,0x134
.PB0f127de4:
/*  f127de4:	2a61004b */ 	slti	$at,$s3,0x4b
/*  f127de8:	1020000c */ 	beqz	$at,.PB0f127e1c
/*  f127dec:	266dffb5 */ 	addiu	$t5,$s3,-75
/*  f127df0:	2a610019 */ 	slti	$at,$s3,0x19
/*  f127df4:	10200007 */ 	beqz	$at,.PB0f127e14
/*  f127df8:	00000000 */ 	nop
/*  f127dfc:	44935000 */ 	mtc1	$s3,$f10
/*  f127e00:	00000000 */ 	nop
/*  f127e04:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f127e08:	46184082 */ 	mul.s	$f2,$f8,$f24
/*  f127e0c:	10000011 */ 	b	.PB0f127e54
/*  f127e10:	8e2f0000 */ 	lw	$t7,0x0($s1)
.PB0f127e14:
/*  f127e14:	1000000e */ 	b	.PB0f127e50
/*  f127e18:	4600d086 */ 	mov.s	$f2,$f26
.PB0f127e1c:
/*  f127e1c:	448d3000 */ 	mtc1	$t5,$f6
/*  f127e20:	00000000 */ 	nop
/*  f127e24:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f127e28:	4604e281 */ 	sub.s	$f10,$f28,$f4
/*  f127e2c:	461e5202 */ 	mul.s	$f8,$f10,$f30
/*  f127e30:	00000000 */ 	nop
/*  f127e34:	46144082 */ 	mul.s	$f2,$f8,$f20
/*  f127e38:	4616103c */ 	c.lt.s	$f2,$f22
/*  f127e3c:	00000000 */ 	nop
/*  f127e40:	45000002 */ 	bc1f	.PB0f127e4c
/*  f127e44:	00000000 */ 	nop
/*  f127e48:	4600b086 */ 	mov.s	$f2,$f22
.PB0f127e4c:
/*  f127e4c:	46141080 */ 	add.s	$f2,$f2,$f20
.PB0f127e50:
/*  f127e50:	8e2f0000 */ 	lw	$t7,0x0($s1)
.PB0f127e54:
/*  f127e54:	c7aa0130 */ 	lwc1	$f10,0x130($sp)
/*  f127e58:	8fa30198 */ 	lw	$v1,0x198($sp)
/*  f127e5c:	448f3000 */ 	mtc1	$t7,$f6
/*  f127e60:	c7a4019c */ 	lwc1	$f4,0x19c($sp)
/*  f127e64:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f127e68:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f127e6c:	24780008 */ 	addiu	$t8,$v1,0x8
/*  f127e70:	c7a601a0 */ 	lwc1	$f6,0x1a0($sp)
/*  f127e74:	afb80198 */ 	sw	$t8,0x198($sp)
/*  f127e78:	3c014f80 */ 	lui	$at,0x4f80
/*  f127e7c:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f127e80:	c7aa012c */ 	lwc1	$f10,0x12c($sp)
/*  f127e84:	ac770000 */ 	sw	$s7,0x0($v1)
/*  f127e88:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f127e8c:	304800ff */ 	andi	$t0,$v0,0xff
/*  f127e90:	46082301 */ 	sub.s	$f12,$f4,$f8
/*  f127e94:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f127e98:	448e4000 */ 	mtc1	$t6,$f8
/*  f127e9c:	44885000 */ 	mtc1	$t0,$f10
/*  f127ea0:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f127ea4:	c7a801b0 */ 	lwc1	$f8,0x1b0($sp)
/*  f127ea8:	46043381 */ 	sub.s	$f14,$f6,$f4
/*  f127eac:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f127eb0:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f127eb4:	05010004 */ 	bgez	$t0,.PB0f127ec8
/*  f127eb8:	00000000 */ 	nop
/*  f127ebc:	44812000 */ 	mtc1	$at,$f4
/*  f127ec0:	00000000 */ 	nop
/*  f127ec4:	46043180 */ 	add.s	$f6,$f6,$f4
.PB0f127ec8:
/*  f127ec8:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f127ecc:	02a02025 */ 	move	$a0,$s5
/*  f127ed0:	00027e02 */ 	srl	$t7,$v0,0x18
/*  f127ed4:	000f7600 */ 	sll	$t6,$t7,0x18
/*  f127ed8:	00024402 */ 	srl	$t0,$v0,0x10
/*  f127edc:	310c00ff */ 	andi	$t4,$t0,0xff
/*  f127ee0:	00027a02 */ 	srl	$t7,$v0,0x8
/*  f127ee4:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f127ee8:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f127eec:	03c02825 */ 	move	$a1,$s8
/*  f127ef0:	27a6017c */ 	addiu	$a2,$sp,0x17c
/*  f127ef4:	440b4000 */ 	mfc1	$t3,$f8
/*  f127ef8:	00000000 */ 	nop
/*  f127efc:	316900ff */ 	andi	$t1,$t3,0xff
/*  f127f00:	012ec825 */ 	or	$t9,$t1,$t6
/*  f127f04:	31e900ff */ 	andi	$t1,$t7,0xff
/*  f127f08:	000c5c00 */ 	sll	$t3,$t4,0x10
/*  f127f0c:	032b5025 */ 	or	$t2,$t9,$t3
/*  f127f10:	00097200 */ 	sll	$t6,$t1,0x8
/*  f127f14:	014ec025 */ 	or	$t8,$t2,$t6
/*  f127f18:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f127f1c:	c7a60094 */ 	lwc1	$f6,0x94($sp)
/*  f127f20:	8ec20000 */ 	lw	$v0,0x0($s6)
/*  f127f24:	e7ac0184 */ 	swc1	$f12,0x184($sp)
/*  f127f28:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f127f2c:	e7ae0188 */ 	swc1	$f14,0x188($sp)
/*  f127f30:	e7b20180 */ 	swc1	$f18,0x180($sp)
/*  f127f34:	240c0001 */ 	li	$t4,0x1
/*  f127f38:	e7aa017c */ 	swc1	$f10,0x17c($sp)
/*  f127f3c:	90480011 */ 	lbu	$t0,0x11($v0)
/*  f127f40:	90470010 */ 	lbu	$a3,0x10($v0)
/*  f127f44:	afac0028 */ 	sw	$t4,0x28($sp)
/*  f127f48:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f127f4c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f127f50:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f127f54:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f127f58:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f127f5c:	0fc2c958 */ 	jal	func0f0b2150
/*  f127f60:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f127f64:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f127f68:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f127f6c:	1614ff9d */ 	bne	$s0,$s4,.PB0f127de4
/*  f127f70:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f127f74:	0c002e6d */ 	jal	viGetViewWidth
/*  f127f78:	00000000 */ 	nop
/*  f127f7c:	44822000 */ 	mtc1	$v0,$f4
/*  f127f80:	3c013f00 */ 	lui	$at,0x3f00
/*  f127f84:	4481c000 */ 	mtc1	$at,$f24
/*  f127f88:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f127f8c:	c7aa019c */ 	lwc1	$f10,0x19c($sp)
/*  f127f90:	46184182 */ 	mul.s	$f6,$f8,$f24
/*  f127f94:	0c002e71 */ 	jal	viGetViewHeight
/*  f127f98:	460a3501 */ 	sub.s	$f20,$f6,$f10
/*  f127f9c:	44822000 */ 	mtc1	$v0,$f4
/*  f127fa0:	c7aa01a0 */ 	lwc1	$f10,0x1a0($sp)
/*  f127fa4:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f127fa8:	46184182 */ 	mul.s	$f6,$f8,$f24
/*  f127fac:	460a3001 */ 	sub.s	$f0,$f6,$f10
/*  f127fb0:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f127fb4:	00000000 */ 	nop
/*  f127fb8:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f127fbc:	0c012ae4 */ 	jal	sqrtf
/*  f127fc0:	46082300 */ 	add.s	$f12,$f4,$f8
/*  f127fc4:	3c014220 */ 	lui	$at,0x4220
/*  f127fc8:	44813000 */ 	mtc1	$at,$f6
/*  f127fcc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f127fd0:	c4247108 */ 	lwc1	$f4,0x7108($at)
/*  f127fd4:	46003281 */ 	sub.s	$f10,$f6,$f0
/*  f127fd8:	3c19800a */ 	lui	$t9,0x800a
/*  f127fdc:	c7a601b0 */ 	lwc1	$f6,0x1b0($sp)
/*  f127fe0:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f127fe4:	4616603c */ 	c.lt.s	$f12,$f22
/*  f127fe8:	00000000 */ 	nop
/*  f127fec:	45000002 */ 	bc1f	.PB0f127ff8
/*  f127ff0:	00000000 */ 	nop
/*  f127ff4:	4600b306 */ 	mov.s	$f12,$f22
.PB0f127ff8:
/*  f127ff8:	8f39e504 */ 	lw	$t9,-0x1afc($t9)
/*  f127ffc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f128000:	c428710c */ 	lwc1	$f8,0x710c($at)
/*  f128004:	0333082a */ 	slt	$at,$t9,$s3
/*  f128008:	14200002 */ 	bnez	$at,.PB0f128014
/*  f12800c:	46086300 */ 	add.s	$f12,$f12,$f8
/*  f128010:	4600b306 */ 	mov.s	$f12,$f22
.PB0f128014:
/*  f128014:	460cb03c */ 	c.lt.s	$f22,$f12
/*  f128018:	00000000 */ 	nop
/*  f12801c:	4502000d */ 	bc1fl	.PB0f128054
/*  f128020:	8fad0198 */ 	lw	$t5,0x198($sp)
/*  f128024:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f128028:	3c01437f */ 	lui	$at,0x437f
/*  f12802c:	44812000 */ 	mtc1	$at,$f4
/*  f128030:	00000000 */ 	nop
/*  f128034:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f128038:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f12803c:	44043000 */ 	mfc1	$a0,$f6
/*  f128040:	00000000 */ 	nop
/*  f128044:	00802825 */ 	move	$a1,$a0
/*  f128048:	0fc4a205 */ 	jal	sky0f127334
/*  f12804c:	00803025 */ 	move	$a2,$a0
/*  f128050:	8fad0198 */ 	lw	$t5,0x198($sp)
.PB0f128054:
/*  f128054:	3c09ba00 */ 	lui	$t1,0xba00
/*  f128058:	35290602 */ 	ori	$t1,$t1,0x602
/*  f12805c:	25af0008 */ 	addiu	$t7,$t5,0x8
/*  f128060:	afaf0198 */ 	sw	$t7,0x198($sp)
/*  f128064:	240a0040 */ 	li	$t2,0x40
/*  f128068:	adaa0004 */ 	sw	$t2,0x4($t5)
/*  f12806c:	ada90000 */ 	sw	$t1,0x0($t5)
/*  f128070:	8fae0198 */ 	lw	$t6,0x198($sp)
/*  f128074:	3c08ba00 */ 	lui	$t0,0xba00
/*  f128078:	35080402 */ 	ori	$t0,$t0,0x402
/*  f12807c:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f128080:	afb80198 */ 	sw	$t8,0x198($sp)
/*  f128084:	240c00c0 */ 	li	$t4,0xc0
/*  f128088:	adcc0004 */ 	sw	$t4,0x4($t6)
/*  f12808c:	adc80000 */ 	sw	$t0,0x0($t6)
/*  f128090:	8fb90198 */ 	lw	$t9,0x198($sp)
/*  f128094:	3c0dba00 */ 	lui	$t5,0xba00
/*  f128098:	35ad1301 */ 	ori	$t5,$t5,0x1301
/*  f12809c:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f1280a0:	afab0198 */ 	sw	$t3,0x198($sp)
/*  f1280a4:	3c0f0008 */ 	lui	$t7,0x8
/*  f1280a8:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f1280ac:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f1280b0:	8fa90198 */ 	lw	$t1,0x198($sp)
/*  f1280b4:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1280b8:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f1280bc:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f1280c0:	afaa0198 */ 	sw	$t2,0x198($sp)
/*  f1280c4:	3c180001 */ 	lui	$t8,0x1
/*  f1280c8:	ad380004 */ 	sw	$t8,0x4($t1)
/*  f1280cc:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*  f1280d0:	8fbf008c */ 	lw	$ra,0x8c($sp)
/*  f1280d4:	8fbe0088 */ 	lw	$s8,0x88($sp)
/*  f1280d8:	8fb70084 */ 	lw	$s7,0x84($sp)
/*  f1280dc:	8fb60080 */ 	lw	$s6,0x80($sp)
/*  f1280e0:	8fb5007c */ 	lw	$s5,0x7c($sp)
/*  f1280e4:	8fb40078 */ 	lw	$s4,0x78($sp)
/*  f1280e8:	8fb30074 */ 	lw	$s3,0x74($sp)
/*  f1280ec:	8fb20070 */ 	lw	$s2,0x70($sp)
/*  f1280f0:	8fb1006c */ 	lw	$s1,0x6c($sp)
/*  f1280f4:	8fb00068 */ 	lw	$s0,0x68($sp)
/*  f1280f8:	d7be0060 */ 	ldc1	$f30,0x60($sp)
/*  f1280fc:	d7bc0058 */ 	ldc1	$f28,0x58($sp)
/*  f128100:	d7ba0050 */ 	ldc1	$f26,0x50($sp)
/*  f128104:	d7b80048 */ 	ldc1	$f24,0x48($sp)
/*  f128108:	d7b60040 */ 	ldc1	$f22,0x40($sp)
/*  f12810c:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f128110:	8fa20198 */ 	lw	$v0,0x198($sp)
/*  f128114:	03e00008 */ 	jr	$ra
/*  f128118:	27bd0198 */ 	addiu	$sp,$sp,0x198
);
#else
GLOBAL_ASM(
glabel sky0f126384
.late_rodata
glabel var7f1b510c
.word 0x3c23d70a
glabel var7f1b5110
.word 0x3bb60b61
glabel var7f1b5114
.word 0x3d088889
glabel var7f1b5118
.word 0x3c4ccccd
glabel var7f1b511c
.word 0x3dcccccd
.text
/*  f126384:	27bdfe70 */ 	addiu	$sp,$sp,-400
/*  f126388:	3c0f8008 */ 	lui	$t7,%hi(var8007dba0)
/*  f12638c:	afbf0084 */ 	sw	$ra,0x84($sp)
/*  f126390:	afb70080 */ 	sw	$s7,0x80($sp)
/*  f126394:	afb6007c */ 	sw	$s6,0x7c($sp)
/*  f126398:	afb50078 */ 	sw	$s5,0x78($sp)
/*  f12639c:	afb40074 */ 	sw	$s4,0x74($sp)
/*  f1263a0:	afb30070 */ 	sw	$s3,0x70($sp)
/*  f1263a4:	afb2006c */ 	sw	$s2,0x6c($sp)
/*  f1263a8:	afb10068 */ 	sw	$s1,0x68($sp)
/*  f1263ac:	afb00064 */ 	sw	$s0,0x64($sp)
/*  f1263b0:	f7be0058 */ 	sdc1	$f30,0x58($sp)
/*  f1263b4:	f7bc0050 */ 	sdc1	$f28,0x50($sp)
/*  f1263b8:	f7ba0048 */ 	sdc1	$f26,0x48($sp)
/*  f1263bc:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*  f1263c0:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f1263c4:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f1263c8:	afa40190 */ 	sw	$a0,0x190($sp)
/*  f1263cc:	25efdba0 */ 	addiu	$t7,$t7,%lo(var8007dba0)
/*  f1263d0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1263d4:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1263d8:	27ae015c */ 	addiu	$t6,$sp,0x15c
/*  f1263dc:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1263e0:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1263e4:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f1263e8:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1263ec:	3c0a8008 */ 	lui	$t2,%hi(var8007dbb8)
/*  f1263f0:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f1263f4:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1263f8:	8de10010 */ 	lw	$at,0x10($t7)
/*  f1263fc:	8de80014 */ 	lw	$t0,0x14($t7)
/*  f126400:	254adbb8 */ 	addiu	$t2,$t2,%lo(var8007dbb8)
/*  f126404:	adc10010 */ 	sw	$at,0x10($t6)
/*  f126408:	adc80014 */ 	sw	$t0,0x14($t6)
/*  f12640c:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f126410:	8d410000 */ 	lw	$at,0x0($t2)
/*  f126414:	27a90144 */ 	addiu	$t1,$sp,0x144
/*  f126418:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f12641c:	ad210000 */ 	sw	$at,0x0($t1)
/*  f126420:	8d410008 */ 	lw	$at,0x8($t2)
/*  f126424:	8d4d000c */ 	lw	$t5,0xc($t2)
/*  f126428:	3c188008 */ 	lui	$t8,%hi(var8007dbd0)
/*  f12642c:	ad210008 */ 	sw	$at,0x8($t1)
/*  f126430:	ad2d000c */ 	sw	$t5,0xc($t1)
/*  f126434:	8d4d0014 */ 	lw	$t5,0x14($t2)
/*  f126438:	8d410010 */ 	lw	$at,0x10($t2)
/*  f12643c:	2718dbd0 */ 	addiu	$t8,$t8,%lo(var8007dbd0)
/*  f126440:	ad2d0014 */ 	sw	$t5,0x14($t1)
/*  f126444:	ad210010 */ 	sw	$at,0x10($t1)
/*  f126448:	8f080004 */ 	lw	$t0,0x4($t8)
/*  f12644c:	8f010000 */ 	lw	$at,0x0($t8)
/*  f126450:	27b9012c */ 	addiu	$t9,$sp,0x12c
/*  f126454:	af280004 */ 	sw	$t0,0x4($t9)
/*  f126458:	af210000 */ 	sw	$at,0x0($t9)
/*  f12645c:	8f010008 */ 	lw	$at,0x8($t8)
/*  f126460:	8f08000c */ 	lw	$t0,0xc($t8)
/*  f126464:	3c0c8007 */ 	lui	$t4,%hi(g_ViRes)
/*  f126468:	af210008 */ 	sw	$at,0x8($t9)
/*  f12646c:	af28000c */ 	sw	$t0,0xc($t9)
/*  f126470:	8f080014 */ 	lw	$t0,0x14($t8)
/*  f126474:	8f010010 */ 	lw	$at,0x10($t8)
/*  f126478:	4487b000 */ 	mtc1	$a3,$f22
/*  f12647c:	af280014 */ 	sw	$t0,0x14($t9)
/*  f126480:	af210010 */ 	sw	$at,0x10($t9)
/*  f126484:	8d8c06c8 */ 	lw	$t4,%lo(g_ViRes)($t4)
/*  f126488:	4485d000 */ 	mtc1	$a1,$f26
/*  f12648c:	4486e000 */ 	mtc1	$a2,$f28
/*  f126490:	24010001 */ 	addiu	$at,$zero,0x1
/*  f126494:	15810002 */ 	bne	$t4,$at,.L0f1264a0
/*  f126498:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f12649c:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f1264a0:
/*  f1264a0:	0c002f22 */ 	jal	viGetViewWidth
/*  f1264a4:	00000000 */ 	nop
/*  f1264a8:	44822000 */ 	mtc1	$v0,$f4
/*  f1264ac:	3c017f1b */ 	lui	$at,%hi(var7f1b510c)
/*  f1264b0:	c434510c */ 	lwc1	$f20,%lo(var7f1b510c)($at)
/*  f1264b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1264b8:	3c013f00 */ 	lui	$at,0x3f00
/*  f1264bc:	4481f000 */ 	mtc1	$at,$f30
/*  f1264c0:	00000000 */ 	nop
/*  f1264c4:	461e3202 */ 	mul.s	$f8,$f6,$f30
/*  f1264c8:	4608d281 */ 	sub.s	$f10,$f26,$f8
/*  f1264cc:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f1264d0:	0c002f26 */ 	jal	viGetViewHeight
/*  f1264d4:	e7a40128 */ 	swc1	$f4,0x128($sp)
/*  f1264d8:	44823000 */ 	mtc1	$v0,$f6
/*  f1264dc:	3c16800b */ 	lui	$s6,%hi(g_TexLightGlareConfigs)
/*  f1264e0:	26d6b5a0 */ 	addiu	$s6,$s6,%lo(g_TexLightGlareConfigs)
/*  f1264e4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1264e8:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f1264ec:	27b50190 */ 	addiu	$s5,$sp,0x190
/*  f1264f0:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f1264f4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1264f8:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f1264fc:	461e4282 */ 	mul.s	$f10,$f8,$f30
/*  f126500:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f126504:	02a02025 */ 	or	$a0,$s5,$zero
/*  f126508:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f12650c:	00003825 */ 	or	$a3,$zero,$zero
/*  f126510:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f126514:	24a50048 */ 	addiu	$a1,$a1,0x48
/*  f126518:	460ae101 */ 	sub.s	$f4,$f28,$f10
/*  f12651c:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f126520:	0fc2ce70 */ 	jal	texSelect
/*  f126524:	e7a60124 */ 	swc1	$f6,0x124($sp)
/*  f126528:	8faa0190 */ 	lw	$t2,0x190($sp)
/*  f12652c:	3c11ba00 */ 	lui	$s1,0xba00
/*  f126530:	36311402 */ 	ori	$s1,$s1,0x1402
/*  f126534:	254d0008 */ 	addiu	$t5,$t2,0x8
/*  f126538:	afad0190 */ 	sw	$t5,0x190($sp)
/*  f12653c:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f126540:	ad510000 */ 	sw	$s1,0x0($t2)
/*  f126544:	8faf0190 */ 	lw	$t7,0x190($sp)
/*  f126548:	3c19ba00 */ 	lui	$t9,0xba00
/*  f12654c:	37390602 */ 	ori	$t9,$t9,0x602
/*  f126550:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f126554:	afae0190 */ 	sw	$t6,0x190($sp)
/*  f126558:	24180040 */ 	addiu	$t8,$zero,0x40
/*  f12655c:	adf80004 */ 	sw	$t8,0x4($t7)
/*  f126560:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f126564:	8fa80190 */ 	lw	$t0,0x190($sp)
/*  f126568:	3c0bba00 */ 	lui	$t3,0xba00
/*  f12656c:	356b0402 */ 	ori	$t3,$t3,0x402
/*  f126570:	250c0008 */ 	addiu	$t4,$t0,0x8
/*  f126574:	afac0190 */ 	sw	$t4,0x190($sp)
/*  f126578:	ad000004 */ 	sw	$zero,0x4($t0)
/*  f12657c:	ad0b0000 */ 	sw	$t3,0x0($t0)
/*  f126580:	8fa90190 */ 	lw	$t1,0x190($sp)
/*  f126584:	3c12b900 */ 	lui	$s2,0xb900
/*  f126588:	3c130050 */ 	lui	$s3,0x50
/*  f12658c:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f126590:	afaa0190 */ 	sw	$t2,0x190($sp)
/*  f126594:	367341c8 */ 	ori	$s3,$s3,0x41c8
/*  f126598:	3652031d */ 	ori	$s2,$s2,0x31d
/*  f12659c:	ad320000 */ 	sw	$s2,0x0($t1)
/*  f1265a0:	ad330004 */ 	sw	$s3,0x4($t1)
/*  f1265a4:	8fad0190 */ 	lw	$t5,0x190($sp)
/*  f1265a8:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1265ac:	35ce1301 */ 	ori	$t6,$t6,0x1301
/*  f1265b0:	25af0008 */ 	addiu	$t7,$t5,0x8
/*  f1265b4:	afaf0190 */ 	sw	$t7,0x190($sp)
/*  f1265b8:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f1265bc:	adae0000 */ 	sw	$t6,0x0($t5)
/*  f1265c0:	8fb90190 */ 	lw	$t9,0x190($sp)
/*  f1265c4:	3c14b900 */ 	lui	$s4,0xb900
/*  f1265c8:	36940002 */ 	ori	$s4,$s4,0x2
/*  f1265cc:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f1265d0:	afb80190 */ 	sw	$t8,0x190($sp)
/*  f1265d4:	af200004 */ 	sw	$zero,0x4($t9)
/*  f1265d8:	af340000 */ 	sw	$s4,0x0($t9)
/*  f1265dc:	8fa80190 */ 	lw	$t0,0x190($sp)
/*  f1265e0:	3c0bba00 */ 	lui	$t3,0xba00
/*  f1265e4:	356b1001 */ 	ori	$t3,$t3,0x1001
/*  f1265e8:	250c0008 */ 	addiu	$t4,$t0,0x8
/*  f1265ec:	afac0190 */ 	sw	$t4,0x190($sp)
/*  f1265f0:	ad000004 */ 	sw	$zero,0x4($t0)
/*  f1265f4:	ad0b0000 */ 	sw	$t3,0x0($t0)
/*  f1265f8:	8fa90190 */ 	lw	$t1,0x190($sp)
/*  f1265fc:	3c0dba00 */ 	lui	$t5,0xba00
/*  f126600:	35ad0903 */ 	ori	$t5,$t5,0x903
/*  f126604:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f126608:	afaa0190 */ 	sw	$t2,0x190($sp)
/*  f12660c:	240f0c00 */ 	addiu	$t7,$zero,0xc00
/*  f126610:	ad2f0004 */ 	sw	$t7,0x4($t1)
/*  f126614:	ad2d0000 */ 	sw	$t5,0x0($t1)
/*  f126618:	8fae0190 */ 	lw	$t6,0x190($sp)
/*  f12661c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f126620:	37180e02 */ 	ori	$t8,$t8,0xe02
/*  f126624:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f126628:	afb90190 */ 	sw	$t9,0x190($sp)
/*  f12662c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f126630:	add80000 */ 	sw	$t8,0x0($t6)
/*  f126634:	8fa80190 */ 	lw	$t0,0x190($sp)
/*  f126638:	3c0bba00 */ 	lui	$t3,0xba00
/*  f12663c:	356b0c02 */ 	ori	$t3,$t3,0xc02
/*  f126640:	250c0008 */ 	addiu	$t4,$t0,0x8
/*  f126644:	afac0190 */ 	sw	$t4,0x190($sp)
/*  f126648:	24092000 */ 	addiu	$t1,$zero,0x2000
/*  f12664c:	ad090004 */ 	sw	$t1,0x4($t0)
/*  f126650:	ad0b0000 */ 	sw	$t3,0x0($t0)
/*  f126654:	8faa0190 */ 	lw	$t2,0x190($sp)
/*  f126658:	3c0eff36 */ 	lui	$t6,0xff36
/*  f12665c:	3c0ffcff */ 	lui	$t7,0xfcff
/*  f126660:	254d0008 */ 	addiu	$t5,$t2,0x8
/*  f126664:	afad0190 */ 	sw	$t5,0x190($sp)
/*  f126668:	35ef9bff */ 	ori	$t7,$t7,0x9bff
/*  f12666c:	35ceff7f */ 	ori	$t6,$t6,0xff7f
/*  f126670:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*  f126674:	0c002f9d */ 	jal	viGetFovY
/*  f126678:	ad4f0000 */ 	sw	$t7,0x0($t2)
/*  f12667c:	8fb90190 */ 	lw	$t9,0x190($sp)
/*  f126680:	3c17fb00 */ 	lui	$s7,0xfb00
/*  f126684:	3c013f00 */ 	lui	$at,0x3f00
/*  f126688:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f12668c:	afb80190 */ 	sw	$t8,0x190($sp)
/*  f126690:	af370000 */ 	sw	$s7,0x0($t9)
/*  f126694:	c7a801a8 */ 	lwc1	$f8,0x1a8($sp)
/*  f126698:	4481a000 */ 	mtc1	$at,$f20
/*  f12669c:	3c01437f */ 	lui	$at,0x437f
/*  f1266a0:	46164282 */ 	mul.s	$f10,$f8,$f22
/*  f1266a4:	44812000 */ 	mtc1	$at,$f4
/*  f1266a8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1266ac:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1266b0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1266b4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1266b8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1266bc:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f1266c0:	27a5017c */ 	addiu	$a1,$sp,0x17c
/*  f1266c4:	27a60174 */ 	addiu	$a2,$sp,0x174
/*  f1266c8:	4616a102 */ 	mul.s	$f4,$f20,$f22
/*  f1266cc:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f1266d0:	4604a180 */ 	add.s	$f6,$f20,$f4
/*  f1266d4:	440c4000 */ 	mfc1	$t4,$f8
/*  f1266d8:	00000000 */ 	nop
/*  f1266dc:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f1266e0:	01614825 */ 	or	$t1,$t3,$at
/*  f1266e4:	af290004 */ 	sw	$t1,0x4($t9)
/*  f1266e8:	c7aa01a0 */ 	lwc1	$f10,0x1a0($sp)
/*  f1266ec:	3c014270 */ 	lui	$at,0x4270
/*  f1266f0:	44812000 */ 	mtc1	$at,$f4
/*  f1266f4:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f1266f8:	8ec20000 */ 	lw	$v0,0x0($s6)
/*  f1266fc:	e7ba017c */ 	swc1	$f26,0x17c($sp)
/*  f126700:	e7bc0180 */ 	swc1	$f28,0x180($sp)
/*  f126704:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f126708:	46002283 */ 	div.s	$f10,$f4,$f0
/*  f12670c:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f126710:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f126714:	44903000 */ 	mtc1	$s0,$f6
/*  f126718:	440d2000 */ 	mfc1	$t5,$f4
/*  f12671c:	46803620 */ 	cvt.s.w	$f24,$f6
/*  f126720:	448d5000 */ 	mtc1	$t5,$f10
/*  f126724:	00000000 */ 	nop
/*  f126728:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f12672c:	46144082 */ 	mul.s	$f2,$f8,$f20
/*  f126730:	00000000 */ 	nop
/*  f126734:	46181102 */ 	mul.s	$f4,$f2,$f24
/*  f126738:	e7a20178 */ 	swc1	$f2,0x178($sp)
/*  f12673c:	e7a40174 */ 	swc1	$f4,0x174($sp)
/*  f126740:	904f004d */ 	lbu	$t7,0x4d($v0)
/*  f126744:	9047004c */ 	lbu	$a3,0x4c($v0)
/*  f126748:	afa80028 */ 	sw	$t0,0x28($sp)
/*  f12674c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f126750:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f126754:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f126758:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f12675c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f126760:	0fc2c854 */ 	jal	func0f0b2150
/*  f126764:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f126768:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f12676c:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f126770:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f126774:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f126778:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f12677c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f126780:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f126784:	00003825 */ 	or	$a3,$zero,$zero
/*  f126788:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f12678c:	0fc2ce70 */ 	jal	texSelect
/*  f126790:	24a5000c */ 	addiu	$a1,$a1,0xc
/*  f126794:	8fa90190 */ 	lw	$t1,0x190($sp)
/*  f126798:	3c0eba00 */ 	lui	$t6,0xba00
/*  f12679c:	35ce0602 */ 	ori	$t6,$t6,0x602
/*  f1267a0:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f1267a4:	afaa0190 */ 	sw	$t2,0x190($sp)
/*  f1267a8:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f1267ac:	ad310000 */ 	sw	$s1,0x0($t1)
/*  f1267b0:	8fad0190 */ 	lw	$t5,0x190($sp)
/*  f1267b4:	24190040 */ 	addiu	$t9,$zero,0x40
/*  f1267b8:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1267bc:	25af0008 */ 	addiu	$t7,$t5,0x8
/*  f1267c0:	afaf0190 */ 	sw	$t7,0x190($sp)
/*  f1267c4:	adb90004 */ 	sw	$t9,0x4($t5)
/*  f1267c8:	adae0000 */ 	sw	$t6,0x0($t5)
/*  f1267cc:	8fb80190 */ 	lw	$t8,0x190($sp)
/*  f1267d0:	358c0402 */ 	ori	$t4,$t4,0x402
/*  f1267d4:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1267d8:	27080008 */ 	addiu	$t0,$t8,0x8
/*  f1267dc:	afa80190 */ 	sw	$t0,0x190($sp)
/*  f1267e0:	af000004 */ 	sw	$zero,0x4($t8)
/*  f1267e4:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f1267e8:	8fab0190 */ 	lw	$t3,0x190($sp)
/*  f1267ec:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f1267f0:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1267f4:	25690008 */ 	addiu	$t1,$t3,0x8
/*  f1267f8:	afa90190 */ 	sw	$t1,0x190($sp)
/*  f1267fc:	ad730004 */ 	sw	$s3,0x4($t3)
/*  f126800:	ad720000 */ 	sw	$s2,0x0($t3)
/*  f126804:	8faa0190 */ 	lw	$t2,0x190($sp)
/*  f126808:	358c1001 */ 	ori	$t4,$t4,0x1001
/*  f12680c:	3c017f1b */ 	lui	$at,%hi(var7f1b5110)
/*  f126810:	254d0008 */ 	addiu	$t5,$t2,0x8
/*  f126814:	afad0190 */ 	sw	$t5,0x190($sp)
/*  f126818:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f12681c:	ad4f0000 */ 	sw	$t7,0x0($t2)
/*  f126820:	8fae0190 */ 	lw	$t6,0x190($sp)
/*  f126824:	3c0aba00 */ 	lui	$t2,0xba00
/*  f126828:	354a0903 */ 	ori	$t2,$t2,0x903
/*  f12682c:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f126830:	afb90190 */ 	sw	$t9,0x190($sp)
/*  f126834:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f126838:	add40000 */ 	sw	$s4,0x0($t6)
/*  f12683c:	8fb80190 */ 	lw	$t8,0x190($sp)
/*  f126840:	240d0c00 */ 	addiu	$t5,$zero,0xc00
/*  f126844:	3c19ba00 */ 	lui	$t9,0xba00
/*  f126848:	27080008 */ 	addiu	$t0,$t8,0x8
/*  f12684c:	afa80190 */ 	sw	$t0,0x190($sp)
/*  f126850:	af000004 */ 	sw	$zero,0x4($t8)
/*  f126854:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f126858:	8fab0190 */ 	lw	$t3,0x190($sp)
/*  f12685c:	37390e02 */ 	ori	$t9,$t9,0xe02
/*  f126860:	3c0cba00 */ 	lui	$t4,0xba00
/*  f126864:	25690008 */ 	addiu	$t1,$t3,0x8
/*  f126868:	afa90190 */ 	sw	$t1,0x190($sp)
/*  f12686c:	ad6d0004 */ 	sw	$t5,0x4($t3)
/*  f126870:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f126874:	8faf0190 */ 	lw	$t7,0x190($sp)
/*  f126878:	240b2000 */ 	addiu	$t3,$zero,0x2000
/*  f12687c:	358c0c02 */ 	ori	$t4,$t4,0xc02
/*  f126880:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f126884:	afae0190 */ 	sw	$t6,0x190($sp)
/*  f126888:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f12688c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f126890:	8fb80190 */ 	lw	$t8,0x190($sp)
/*  f126894:	3c0fff36 */ 	lui	$t7,0xff36
/*  f126898:	3c0dfcff */ 	lui	$t5,0xfcff
/*  f12689c:	27080008 */ 	addiu	$t0,$t8,0x8
/*  f1268a0:	afa80190 */ 	sw	$t0,0x190($sp)
/*  f1268a4:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f1268a8:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f1268ac:	8fa90190 */ 	lw	$t1,0x190($sp)
/*  f1268b0:	35ad9bff */ 	ori	$t5,$t5,0x9bff
/*  f1268b4:	35efff7f */ 	ori	$t7,$t7,0xff7f
/*  f1268b8:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f1268bc:	afaa0190 */ 	sw	$t2,0x190($sp)
/*  f1268c0:	ad2f0004 */ 	sw	$t7,0x4($t1)
/*  f1268c4:	ad2d0000 */ 	sw	$t5,0x0($t1)
/*  f1268c8:	c43e5110 */ 	lwc1	$f30,%lo(var7f1b5110)($at)
/*  f1268cc:	3c014334 */ 	lui	$at,0x4334
/*  f1268d0:	e7bc0198 */ 	swc1	$f28,0x198($sp)
/*  f1268d4:	4481e000 */ 	mtc1	$at,$f28
/*  f1268d8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1268dc:	e7ba0194 */ 	swc1	$f26,0x194($sp)
/*  f1268e0:	4481d000 */ 	mtc1	$at,$f26
/*  f1268e4:	3c017f1b */ 	lui	$at,%hi(var7f1b5114)
/*  f1268e8:	e7b8009c */ 	swc1	$f24,0x9c($sp)
/*  f1268ec:	4480b000 */ 	mtc1	$zero,$f22
/*  f1268f0:	c4385114 */ 	lwc1	$f24,%lo(var7f1b5114)($at)
/*  f1268f4:	8fb301a4 */ 	lw	$s3,0x1a4($sp)
/*  f1268f8:	27b40144 */ 	addiu	$s4,$sp,0x144
/*  f1268fc:	27b2015c */ 	addiu	$s2,$sp,0x15c
/*  f126900:	27b10144 */ 	addiu	$s1,$sp,0x144
/*  f126904:	27b0012c */ 	addiu	$s0,$sp,0x12c
.L0f126908:
/*  f126908:	2a61005a */ 	slti	$at,$s3,0x5a
/*  f12690c:	1020000c */ 	beqz	$at,.L0f126940
/*  f126910:	266effa6 */ 	addiu	$t6,$s3,-90
/*  f126914:	2a61001e */ 	slti	$at,$s3,0x1e
/*  f126918:	10200007 */ 	beqz	$at,.L0f126938
/*  f12691c:	00000000 */ 	nop
/*  f126920:	44935000 */ 	mtc1	$s3,$f10
/*  f126924:	00000000 */ 	nop
/*  f126928:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f12692c:	46184082 */ 	mul.s	$f2,$f8,$f24
/*  f126930:	10000011 */ 	b	.L0f126978
/*  f126934:	8e390000 */ 	lw	$t9,0x0($s1)
.L0f126938:
/*  f126938:	1000000e */ 	b	.L0f126974
/*  f12693c:	4600d086 */ 	mov.s	$f2,$f26
.L0f126940:
/*  f126940:	448e3000 */ 	mtc1	$t6,$f6
/*  f126944:	00000000 */ 	nop
/*  f126948:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f12694c:	4604e281 */ 	sub.s	$f10,$f28,$f4
/*  f126950:	461e5202 */ 	mul.s	$f8,$f10,$f30
/*  f126954:	00000000 */ 	nop
/*  f126958:	46144082 */ 	mul.s	$f2,$f8,$f20
/*  f12695c:	4616103c */ 	c.lt.s	$f2,$f22
/*  f126960:	00000000 */ 	nop
/*  f126964:	45000002 */ 	bc1f	.L0f126970
/*  f126968:	00000000 */ 	nop
/*  f12696c:	4600b086 */ 	mov.s	$f2,$f22
.L0f126970:
/*  f126970:	46141080 */ 	add.s	$f2,$f2,$f20
.L0f126974:
/*  f126974:	8e390000 */ 	lw	$t9,0x0($s1)
.L0f126978:
/*  f126978:	c7aa0128 */ 	lwc1	$f10,0x128($sp)
/*  f12697c:	8fa30190 */ 	lw	$v1,0x190($sp)
/*  f126980:	44993000 */ 	mtc1	$t9,$f6
/*  f126984:	c7a40194 */ 	lwc1	$f4,0x194($sp)
/*  f126988:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f12698c:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f126990:	246c0008 */ 	addiu	$t4,$v1,0x8
/*  f126994:	c7a60198 */ 	lwc1	$f6,0x198($sp)
/*  f126998:	afac0190 */ 	sw	$t4,0x190($sp)
/*  f12699c:	3c014f80 */ 	lui	$at,0x4f80
/*  f1269a0:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f1269a4:	c7aa0124 */ 	lwc1	$f10,0x124($sp)
/*  f1269a8:	ac770000 */ 	sw	$s7,0x0($v1)
/*  f1269ac:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f1269b0:	304b00ff */ 	andi	$t3,$v0,0xff
/*  f1269b4:	46082301 */ 	sub.s	$f12,$f4,$f8
/*  f1269b8:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f1269bc:	44984000 */ 	mtc1	$t8,$f8
/*  f1269c0:	448b5000 */ 	mtc1	$t3,$f10
/*  f1269c4:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f1269c8:	c7a801a8 */ 	lwc1	$f8,0x1a8($sp)
/*  f1269cc:	46043381 */ 	sub.s	$f14,$f6,$f4
/*  f1269d0:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f1269d4:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f1269d8:	05610004 */ 	bgez	$t3,.L0f1269ec
/*  f1269dc:	00000000 */ 	nop
/*  f1269e0:	44812000 */ 	mtc1	$at,$f4
/*  f1269e4:	00000000 */ 	nop
/*  f1269e8:	46043180 */ 	add.s	$f6,$f6,$f4
.L0f1269ec:
/*  f1269ec:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f1269f0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1269f4:	0002ce02 */ 	srl	$t9,$v0,0x18
/*  f1269f8:	0019c600 */ 	sll	$t8,$t9,0x18
/*  f1269fc:	00025c02 */ 	srl	$t3,$v0,0x10
/*  f126a00:	316900ff */ 	andi	$t1,$t3,0xff
/*  f126a04:	0002ca02 */ 	srl	$t9,$v0,0x8
/*  f126a08:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f126a0c:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f126a10:	27a5017c */ 	addiu	$a1,$sp,0x17c
/*  f126a14:	27a60174 */ 	addiu	$a2,$sp,0x174
/*  f126a18:	440a4000 */ 	mfc1	$t2,$f8
/*  f126a1c:	00000000 */ 	nop
/*  f126a20:	314d00ff */ 	andi	$t5,$t2,0xff
/*  f126a24:	01b84025 */ 	or	$t0,$t5,$t8
/*  f126a28:	332d00ff */ 	andi	$t5,$t9,0xff
/*  f126a2c:	00095400 */ 	sll	$t2,$t1,0x10
/*  f126a30:	010a7825 */ 	or	$t7,$t0,$t2
/*  f126a34:	000dc200 */ 	sll	$t8,$t5,0x8
/*  f126a38:	01f86025 */ 	or	$t4,$t7,$t8
/*  f126a3c:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f126a40:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f126a44:	8ec20000 */ 	lw	$v0,0x0($s6)
/*  f126a48:	e7ac017c */ 	swc1	$f12,0x17c($sp)
/*  f126a4c:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f126a50:	e7ae0180 */ 	swc1	$f14,0x180($sp)
/*  f126a54:	e7b20178 */ 	swc1	$f18,0x178($sp)
/*  f126a58:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f126a5c:	e7aa0174 */ 	swc1	$f10,0x174($sp)
/*  f126a60:	904b0011 */ 	lbu	$t3,0x11($v0)
/*  f126a64:	90470010 */ 	lbu	$a3,0x10($v0)
/*  f126a68:	afa90028 */ 	sw	$t1,0x28($sp)
/*  f126a6c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f126a70:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f126a74:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f126a78:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f126a7c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f126a80:	0fc2c854 */ 	jal	func0f0b2150
/*  f126a84:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f126a88:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f126a8c:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f126a90:	1614ff9d */ 	bne	$s0,$s4,.L0f126908
/*  f126a94:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f126a98:	0c002f22 */ 	jal	viGetViewWidth
/*  f126a9c:	00000000 */ 	nop
/*  f126aa0:	44822000 */ 	mtc1	$v0,$f4
/*  f126aa4:	3c013f00 */ 	lui	$at,0x3f00
/*  f126aa8:	4481c000 */ 	mtc1	$at,$f24
/*  f126aac:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f126ab0:	c7aa0194 */ 	lwc1	$f10,0x194($sp)
/*  f126ab4:	46184182 */ 	mul.s	$f6,$f8,$f24
/*  f126ab8:	0c002f26 */ 	jal	viGetViewHeight
/*  f126abc:	460a3501 */ 	sub.s	$f20,$f6,$f10
/*  f126ac0:	44822000 */ 	mtc1	$v0,$f4
/*  f126ac4:	c7aa0198 */ 	lwc1	$f10,0x198($sp)
/*  f126ac8:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f126acc:	46184182 */ 	mul.s	$f6,$f8,$f24
/*  f126ad0:	460a3001 */ 	sub.s	$f0,$f6,$f10
/*  f126ad4:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f126ad8:	00000000 */ 	nop
/*  f126adc:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f126ae0:	0c012974 */ 	jal	sqrtf
/*  f126ae4:	46082300 */ 	add.s	$f12,$f4,$f8
/*  f126ae8:	3c014220 */ 	lui	$at,0x4220
/*  f126aec:	44813000 */ 	mtc1	$at,$f6
/*  f126af0:	3c017f1b */ 	lui	$at,%hi(var7f1b5118)
/*  f126af4:	c4245118 */ 	lwc1	$f4,%lo(var7f1b5118)($at)
/*  f126af8:	46003281 */ 	sub.s	$f10,$f6,$f0
/*  f126afc:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x34)
/*  f126b00:	c7a601a8 */ 	lwc1	$f6,0x1a8($sp)
/*  f126b04:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f126b08:	4616603c */ 	c.lt.s	$f12,$f22
/*  f126b0c:	00000000 */ 	nop
/*  f126b10:	45000002 */ 	bc1f	.L0f126b1c
/*  f126b14:	00000000 */ 	nop
/*  f126b18:	4600b306 */ 	mov.s	$f12,$f22
.L0f126b1c:
/*  f126b1c:	8d089ff4 */ 	lw	$t0,%lo(g_Vars+0x34)($t0)
/*  f126b20:	3c017f1b */ 	lui	$at,%hi(var7f1b511c)
/*  f126b24:	c428511c */ 	lwc1	$f8,%lo(var7f1b511c)($at)
/*  f126b28:	0113082a */ 	slt	$at,$t0,$s3
/*  f126b2c:	14200002 */ 	bnez	$at,.L0f126b38
/*  f126b30:	46086300 */ 	add.s	$f12,$f12,$f8
/*  f126b34:	4600b306 */ 	mov.s	$f12,$f22
.L0f126b38:
/*  f126b38:	460cb03c */ 	c.lt.s	$f22,$f12
/*  f126b3c:	00000000 */ 	nop
/*  f126b40:	4502000d */ 	bc1fl	.L0f126b78
/*  f126b44:	8fae0190 */ 	lw	$t6,0x190($sp)
/*  f126b48:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f126b4c:	3c01437f */ 	lui	$at,0x437f
/*  f126b50:	44812000 */ 	mtc1	$at,$f4
/*  f126b54:	00000000 */ 	nop
/*  f126b58:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f126b5c:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f126b60:	44043000 */ 	mfc1	$a0,$f6
/*  f126b64:	00000000 */ 	nop
/*  f126b68:	00802825 */ 	or	$a1,$a0,$zero
/*  f126b6c:	0fc49ccd */ 	jal	sky0f127334
/*  f126b70:	00803025 */ 	or	$a2,$a0,$zero
/*  f126b74:	8fae0190 */ 	lw	$t6,0x190($sp)
.L0f126b78:
/*  f126b78:	3c0dba00 */ 	lui	$t5,0xba00
/*  f126b7c:	35ad0602 */ 	ori	$t5,$t5,0x602
/*  f126b80:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f126b84:	afb90190 */ 	sw	$t9,0x190($sp)
/*  f126b88:	240f0040 */ 	addiu	$t7,$zero,0x40
/*  f126b8c:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f126b90:	adcd0000 */ 	sw	$t5,0x0($t6)
/*  f126b94:	8fb80190 */ 	lw	$t8,0x190($sp)
/*  f126b98:	3c0bba00 */ 	lui	$t3,0xba00
/*  f126b9c:	356b0402 */ 	ori	$t3,$t3,0x402
/*  f126ba0:	270c0008 */ 	addiu	$t4,$t8,0x8
/*  f126ba4:	afac0190 */ 	sw	$t4,0x190($sp)
/*  f126ba8:	240900c0 */ 	addiu	$t1,$zero,0xc0
/*  f126bac:	af090004 */ 	sw	$t1,0x4($t8)
/*  f126bb0:	af0b0000 */ 	sw	$t3,0x0($t8)
/*  f126bb4:	8fa80190 */ 	lw	$t0,0x190($sp)
/*  f126bb8:	3c0eba00 */ 	lui	$t6,0xba00
/*  f126bbc:	35ce1301 */ 	ori	$t6,$t6,0x1301
/*  f126bc0:	250a0008 */ 	addiu	$t2,$t0,0x8
/*  f126bc4:	afaa0190 */ 	sw	$t2,0x190($sp)
/*  f126bc8:	3c190008 */ 	lui	$t9,0x8
/*  f126bcc:	ad190004 */ 	sw	$t9,0x4($t0)
/*  f126bd0:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*  f126bd4:	8fad0190 */ 	lw	$t5,0x190($sp)
/*  f126bd8:	3c18ba00 */ 	lui	$t8,0xba00
/*  f126bdc:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f126be0:	25af0008 */ 	addiu	$t7,$t5,0x8
/*  f126be4:	afaf0190 */ 	sw	$t7,0x190($sp)
/*  f126be8:	3c0c0001 */ 	lui	$t4,0x1
/*  f126bec:	adac0004 */ 	sw	$t4,0x4($t5)
/*  f126bf0:	adb80000 */ 	sw	$t8,0x0($t5)
/*  f126bf4:	8fbf0084 */ 	lw	$ra,0x84($sp)
/*  f126bf8:	8fb70080 */ 	lw	$s7,0x80($sp)
/*  f126bfc:	8fb6007c */ 	lw	$s6,0x7c($sp)
/*  f126c00:	8fb50078 */ 	lw	$s5,0x78($sp)
/*  f126c04:	8fb40074 */ 	lw	$s4,0x74($sp)
/*  f126c08:	8fb30070 */ 	lw	$s3,0x70($sp)
/*  f126c0c:	8fb2006c */ 	lw	$s2,0x6c($sp)
/*  f126c10:	8fb10068 */ 	lw	$s1,0x68($sp)
/*  f126c14:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f126c18:	d7be0058 */ 	ldc1	$f30,0x58($sp)
/*  f126c1c:	d7bc0050 */ 	ldc1	$f28,0x50($sp)
/*  f126c20:	d7ba0048 */ 	ldc1	$f26,0x48($sp)
/*  f126c24:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*  f126c28:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f126c2c:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f126c30:	8fa20190 */ 	lw	$v0,0x190($sp)
/*  f126c34:	03e00008 */ 	jr	$ra
/*  f126c38:	27bd0190 */ 	addiu	$sp,$sp,0x190
);
#endif

/**
 * Render a sun and its artifacts.
 */
//Gfx *sky0f126384(Gfx *gdl, f32 x, f32 y, f32 arg3, f32 size, s32 arg5, f32 arg6)
//{
//	f32 fa;
//	f32 fb;
//	f32 fc;
//	f32 sp17c[2];
//	f32 sp174[2];
//	s32 sp15c[] = { 16, 32, 12, 32, 24, 64 }; // diameters?
//	s32 sp144[] = { 60, 80, 225, 275, 470, 570 }; // distances from the sun?
//
//	u32 colours[] = { // 12c
//		0xff99ffff, // pinkish/purple
//		0x9999ffff, // blue
//		0x99ffffff, // very light blue
//		0x99ff99ff, // green
//		0xffff99ff, // yellow
//		0xff9999ff, // red
//	};
//
//	f32 sp128;
//	f32 sp124;
//	s32 scale;
//	s32 i;
//	f32 f2;
//	f32 f12;
//	f32 f20;
//	f32 f0;
//
//	scale = 1;
//
//	if (g_ViRes == VIRES_HI) {
//		scale = 2;
//	}
//
//	sp128 = (x - viGetViewWidth() * 0.5f) * 0.01f;
//	sp124 = (y - viGetViewHeight() * 0.5f) * 0.01f;
//
//	// Render the sun
//	texSelect(&gdl, &g_TexLightGlareConfigs[6], 4, 0, 2, 1, NULL);
//
//	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//	gDPSetColorDither(gdl++, G_CD_BAYER);
//	gDPSetAlphaDither(gdl++, G_AD_PATTERN);
//	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
//	gDPSetTexturePersp(gdl++, G_TP_NONE);
//	gDPSetAlphaCompare(gdl++, G_AC_NONE);
//	gDPSetTextureLOD(gdl++, G_TL_TILE);
//	gDPSetTextureConvert(gdl++, G_TC_FILT);
//	gDPSetTextureLUT(gdl++, G_TT_NONE);
//	gDPSetTextureFilter(gdl++, G_TF_BILERP);
//	gDPSetCombineLERP(gdl++,
//			0, 0, 0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0,
//			0, 0, 0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0);
//
//	fa = (size * (0.5f + 0.5f * arg3) * (60.0f / viGetFovY()));
//
//	gDPSetEnvColor(gdl++, 0xff, 0xff, 0xff, (s32)(arg6 * arg3 * 255.0f));
//
//	sp17c[0] = x;
//	sp17c[1] = y;
//	sp174[1] = fa;
//	sp174[0] = fa * scale;
//
//	func0f0b2150(&gdl, sp17c, sp174, g_TexLightGlareConfigs[6].width, g_TexLightGlareConfigs[6].height, 0, 1, 1, 1, 0, 1);
//
//	// Render the artifacts
//	texSelect(&gdl, &g_TexLightGlareConfigs[1], 4, 0, 2, 1, NULL);
//
//	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//	gDPSetColorDither(gdl++, G_CD_BAYER);
//	gDPSetAlphaDither(gdl++, G_AD_PATTERN);
//	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
//	gDPSetTexturePersp(gdl++, G_TP_NONE);
//	gDPSetAlphaCompare(gdl++, G_AC_NONE);
//	gDPSetTextureLOD(gdl++, G_TL_TILE);
//	gDPSetTextureConvert(gdl++, G_TC_FILT);
//	gDPSetTextureLUT(gdl++, G_TT_NONE);
//	gDPSetTextureFilter(gdl++, G_TF_BILERP);
//	gDPSetCombineLERP(gdl++,
//			0, 0, 0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0,
//			0, 0, 0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0);
//
//	for (i = 0; i < 6; i++) {
//		// 90c
//		if (arg5 < 90) {
//			if (arg5 < 30) {
//				f2 = arg5 * 0.033333335071802f;
//			} else {
//				f2 = 1.0f;
//			}
//		} else {
//			f2 = (180.0f - (arg5 - 90)) * 0.0055555556900799f * 0.5f;
//
//			if (f2 < 0.0f) {
//				f2 = 0.0f;
//			}
//
//			f2 += 0.5f;
//		}
//
//		// 974
//		fb = x - sp144[i] * sp128;
//		fc = y - sp144[i] * sp124;
//		fa = sp15c[i] * 0.5f;
//
//		gDPSetEnvColor(gdl++, colours[i] >> 24, (colours[i] >> 16) & 0xff, (colours[i] >> 8) & 0xff, (s32)((colours[i] & 0xff) * (arg6 * f2)));
//
//		sp17c[0] = fb;
//		sp17c[1] = fc;
//
//		sp174[1] = fa;
//		sp174[0] = fa * scale;
//
//		func0f0b2150(&gdl, sp17c, sp174, g_TexLightGlareConfigs[1].width, g_TexLightGlareConfigs[1].height, 0, 0, 0, 0, 0, 1);
//	}
//
//	f20 = viGetViewWidth() * .5f - x;
//	f0 = viGetViewHeight() * .5f - y;
//
//	f12 = (40.0f - sqrtf(f20 * f20 + f0 * f0)) * 0.0125f;
//
//	if (f12 < 0.0f) {
//		f12 = 0.0f;
//	}
//
//	f12 += 0.1f;
//
//	if (arg5 <= g_Vars.lvupdate240) {
//		f12 = 0.0f;
//	}
//
//	if (f12 > 0.0f) {
//		sky0f127334(arg6 * f12 * 255.0f, arg6 * f12 * 255.0f, arg6 * f12 * 255.0f);
//	}
//
//	gDPSetColorDither(gdl++, G_CD_BAYER);
//	gDPSetAlphaDither(gdl++, G_AD_PATTERN | G_CD_DISABLE);
//	gDPSetTexturePersp(gdl++, G_TP_PERSP);
//	gDPSetTextureLOD(gdl++, G_TL_LOD);
//
//	return gdl;
//}

/**
 * Render a sun and its artifacts if on screen.
 */
Gfx *sky0f126c3c(Gfx *gdl, f32 x, f32 y, f32 z, f32 arg4, f32 arg5)
{
	struct coord sp64;

	sp64.x = x;
	sp64.y = y;
	sp64.z = z;

	mtx4TransformVecInPlace(camGetWorldToScreenMtxf(), &sp64);
	mtx4TransformVecInPlace(camGetMtxF1754(), &sp64);

	if (sp64.z > 1.0f) {
		f32 xpos;
		f32 ypos;
		s16 viewlefti = viGetViewLeft();
		s16 viewtopi = viGetViewTop();
		s16 viewwidthi = viGetViewWidth();
		s16 viewheighti = viGetViewHeight();
		f32 viewleft = viewlefti;
		f32 viewwidth = viewwidthi;
		f32 viewtop = viewtopi;
		f32 viewheight = viewheighti;

		xpos = viewleft + (sp64.f[0] / sp64.f[2] + 1.0f) * 0.5f * viewwidth;
		ypos = viewtop + (-sp64.f[1] / sp64.f[2] + 1.0f) * 0.5f * viewheight;

		if (xpos >= viewleft && xpos < viewleft + viewwidth
				&& ypos >= viewtop && ypos < viewtop + viewheight) {
			gdl = sky0f126384(gdl, xpos, ypos, arg5, arg4, TICKS(90), 1.0f);
		}
	}

	return gdl;
}

/**
 * Render lens flares during teleport.
 */
Gfx *sky0f126de8(Gfx *gdl)
{
	f32 sp154 = var80061630 * M_BADTAU;
	s32 i;
	f32 f20 = 0.0f;
	f32 f20_2;
	f32 f22;
	f32 f22_3;
	struct pad pad;
	struct coord spe0;
	f32 spd0[4];
	Mtxf mtx;
	f32 f24;
	f32 f30;

	if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_PREENTER) {
		f20 = g_Vars.currentplayer->teleporttime / 24.0f * 0.33f;
	} else if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_ENTERING) {
		f20 = g_Vars.currentplayer->teleporttime / 48.0f * 0.66f + 0.33f;
	}

	f30 = f20 * 6.0f;
	f22 = f20 * 1.3f;

	if (f22 > 1.0f) {
		f22 = 1.0f;
	}

	if (f30 > 1.0f) {
		f30 = 1.0f;
	}

	f20 *= 1.7f;

	if (f20 > 1.0f) {
		f20 = 1.0f;
	}

	padUnpack(g_Vars.currentplayer->teleportpad, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP, &pad);

	g_TeleportToPos.x = pad.pos.x;
	g_TeleportToPos.y = pad.pos.y;
	g_TeleportToPos.z = pad.pos.z;
	g_TeleportToLook.x = pad.look.x;
	g_TeleportToLook.y = pad.look.y;
	g_TeleportToLook.z = pad.look.z;
	g_TeleportToUp.x = pad.up.x;
	g_TeleportToUp.y = pad.up.y;
	g_TeleportToUp.z = pad.up.z;

	f22 = -cosf(f22 * M_PI) * 0.5f + .5f;
	f24 = 100 * f22;

	for (i = 0; i < 5; i++) {
		spe0.x = g_TeleportToLook.f[0] * f24;
		spe0.y = g_TeleportToLook.f[1] * f24;
		spe0.z = g_TeleportToLook.f[2] * f24;

		f22_3 = sp154 + i * 1.2564370632172f;
		f20_2 = sinf(f22_3);

		spd0[0] = cosf(f22_3);
		spd0[1] = g_TeleportToUp.f[0] * f20_2;
		spd0[2] = g_TeleportToUp.f[1] * f20_2;
		spd0[3] = g_TeleportToUp.f[2] * f20_2;

		quaternionToMtx(spd0, &mtx);
		mtx4RotateVecInPlace(&mtx, &spe0);

		spe0.x += g_TeleportToPos.x;
		spe0.y += g_TeleportToPos.y;
		spe0.z += g_TeleportToPos.z;

		gdl = sky0f126c3c(gdl, spe0.x, spe0.y, spe0.z, f20 * 200, f30);
	}

	return gdl;
}

/**
 * Render teleport artifacts, and all suns and their artifacts.
 */
Gfx *skyRenderArtifacts(Gfx *gdl)
{
	struct environment *env = envGetCurrent();
	struct sun *sun;
	s32 i;

	if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_PREENTER
			|| g_Vars.currentplayer->teleportstate == TELEPORTSTATE_ENTERING) {
		gdl = sky0f126de8(gdl);
	}

	if (env->numsuns <= 0 || !var800844f0 || g_Vars.mplayerisrunning) {
		return gdl;
	}

	sun = env->suns;

	for (i = 0; i < env->numsuns; i++) {
		if (sun->lens_flare && g_SunPositions[i].z > 1) {
			struct artifact *artifact = schedGetFrontArtifacts() + i * 8;
			f32 value = sky0f125a1c(artifact);

			if (value > 0.0f) {
				gdl = sky0f126384(gdl, g_SunScreenXPositions[i], g_SunScreenYPositions[i], value, sun->orb_size, g_SunFlareTimers240[i], g_SunAlphaFracs[i]);
			}
		}

		sun++;
	}

	return gdl;
}

void sky0f127334(s32 arg0, s32 arg1, s32 arg2)
{
	g_Vars.currentplayer->unk1c28 = sqrtf(g_Vars.currentplayer->unk1c28 * g_Vars.currentplayer->unk1c28 + arg0 * arg0);
	g_Vars.currentplayer->unk1c2c = sqrtf(g_Vars.currentplayer->unk1c2c * g_Vars.currentplayer->unk1c2c + arg1 * arg1);
	g_Vars.currentplayer->unk1c30 = sqrtf(g_Vars.currentplayer->unk1c30 * g_Vars.currentplayer->unk1c30 + arg2 * arg2);

	if (g_Vars.currentplayer->unk1c28 > 0xcc) {
		g_Vars.currentplayer->unk1c28 = 0xcc;
	}

	if (g_Vars.currentplayer->unk1c2c > 0xcc) {
		g_Vars.currentplayer->unk1c2c = 0xcc;
	}

	if (g_Vars.currentplayer->unk1c30 > 0xcc) {
		g_Vars.currentplayer->unk1c30 = 0xcc;
	}
}

s32 sky0f127490(s32 arg0, s32 arg1)
{
	if (arg1 >= arg0) {
		if (arg1 - arg0 > 8) {
			return arg0 + 8;
		}

		return arg1;
	}

	if (arg0 - arg1 > 8) {
		return arg0 - 8;
	}

	return arg1;
}

Gfx *sky0f1274d8(Gfx *gdl)
{
	s32 value;
	u32 stack;

	g_Vars.currentplayer->unk1c28 = sky0f127490(g_Vars.currentplayer->unk1c34, g_Vars.currentplayer->unk1c28);
	g_Vars.currentplayer->unk1c2c = sky0f127490(g_Vars.currentplayer->unk1c38, g_Vars.currentplayer->unk1c2c);
	g_Vars.currentplayer->unk1c30 = sky0f127490(g_Vars.currentplayer->unk1c3c, g_Vars.currentplayer->unk1c30);

	value = (g_Vars.currentplayer->unk1c28 > g_Vars.currentplayer->unk1c2c && g_Vars.currentplayer->unk1c28 > g_Vars.currentplayer->unk1c30)
		? g_Vars.currentplayer->unk1c28
		: g_Vars.currentplayer->unk1c2c > g_Vars.currentplayer->unk1c30
		? g_Vars.currentplayer->unk1c2c
		: g_Vars.currentplayer->unk1c30;

	if (!g_InCutscene && EYESPYINACTIVE() && value > 0) {
		f32 r = g_Vars.currentplayer->unk1c28 * (255.0f / value);
		f32 g = g_Vars.currentplayer->unk1c2c * (255.0f / value);
		f32 b = g_Vars.currentplayer->unk1c30 * (255.0f / value);

		f32 a = (g_Vars.currentplayer->unk1c28
			+ g_Vars.currentplayer->unk1c2c
			+ g_Vars.currentplayer->unk1c30) * (1.0f / 3.0f);

		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetColorDither(gdl++, G_CD_DISABLE);
		gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
		gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

		if (USINGDEVICE(DEVICE_NIGHTVISION)) {
			r *= 0.5f;
			g *= 0.75f;
			b *= 0.5f;
		} else if (USINGDEVICE(DEVICE_IRSCANNER)) {
			r *= 0.75f;
			g *= 0.5f;
			b *= 0.5f;
		}

		gDPSetPrimColor(gdl++, 0, 0, (s32)r, (s32)g, (s32)b, (s32)a);

		gDPFillRectangle(gdl++,
				viGetViewLeft(),
				viGetViewTop(),
				viGetViewLeft() + viGetViewWidth(),
				viGetViewTop() + viGetViewHeight());

		gDPPipeSync(gdl++);
	}

	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);

	g_Vars.currentplayer->unk1c34 = g_Vars.currentplayer->unk1c28;
	g_Vars.currentplayer->unk1c38 = g_Vars.currentplayer->unk1c2c;
	g_Vars.currentplayer->unk1c3c = g_Vars.currentplayer->unk1c30;
	g_Vars.currentplayer->unk1c28 = 0;
	g_Vars.currentplayer->unk1c2c = 0;
	g_Vars.currentplayer->unk1c30 = 0;

	return gdl;
}
