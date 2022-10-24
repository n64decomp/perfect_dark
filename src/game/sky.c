#include <ultra64.h>
#include "constants.h"
#include "game/quaternion.h"
#include "game/game_0b2150.h"
#include "game/camera.h"
#include "game/sky.h"
#include "game/game_152fa0.h"
#include "game/env.h"
#include "game/pad.h"
#include "game/tex.h"
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

/**
 * Render a sun and its artifacts.
 */
Gfx *sky0f126384(Gfx *gdl, f32 x, f32 y, f32 arg3, f32 size, s32 arg5, f32 arg6)
{
	s32 i;
	f32 f2;
	f32 f12;
	f32 sp17c[2];
	f32 sp174[2];
	s32 sp15c[] = { 16, 32, 12, 32, 24, 64 }; // diameters?
	s32 sp144[] = { 60, 80, 225, 275, 470, 570 }; // distances from the sun?

	u32 colours[] = {
		0xff99ffff, // pinkish/purple
		0x9999ffff, // blue
		0x99ffffff, // very light blue
		0x99ff99ff, // green
		0xffff99ff, // yellow
		0xff9999ff, // red
	};

	f32 sp128;
	f32 sp124;
	s32 scale;
	f32 fovy;

	scale = 1;

#if !PAL
	if (g_ViRes == VIRES_HI) {
		scale = 2;
	}
#endif

	sp128 = (x - viGetViewWidth() / 2.0f) * 0.01f;
	sp124 = (y - viGetViewHeight() / 2.0f) * 0.01f;

	// Render the sun
	texSelect(&gdl, &g_TexLightGlareConfigs[6], 4, 0, 2, 1, NULL);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetAlphaDither(gdl++, G_AD_PATTERN);
	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetTextureLUT(gdl++, G_TT_NONE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0,
			0, 0, 0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0);

	fovy = viGetFovY();

	gDPSetEnvColor(gdl++, 0xff, 0xff, 0xff, (s32) (arg6 * arg3 * 255.0f));
	f2 = ((s32) ((60.0f / fovy) * (size * (0.5f + (0.5f * arg3)))));

	sp17c[0] = x;
	sp17c[1] = y;
	sp174[1] = f2 * 0.5f;
	sp174[0] = f2 * 0.5f * scale;

	func0f0b2150(&gdl, sp17c, sp174, g_TexLightGlareConfigs[6].width, g_TexLightGlareConfigs[6].height, 0, 1, 1, 1, 0, 1);

	// Render the artifacts
	texSelect(&gdl, &g_TexLightGlareConfigs[1], 4, 0, 2, 1, NULL);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetAlphaDither(gdl++, G_AD_PATTERN);
	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetTextureLUT(gdl++, G_TT_NONE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0,
			0, 0, 0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0);

	for (i = 0; i < 6; i++) {
		f32 f12;
		f32 f14;
		f32 tmp;

		if (arg5 < TICKS(90)) {
			if (arg5 < TICKS(30)) {
				f2 = arg5 * (1.0f / TICKS(30.0f));
			} else {
				f2 = 1.0f;
			}
		} else {
			f2 = (TICKS(180.0f) - (arg5 - TICKS(90))) * (1.0f / TICKS(180.0f)) * 0.5f;

			if (f2 < 0.0f) {
				f2 =  0.0f;
			}

			f2 += 0.5f;
		}

		f12 = x - sp144[i] * sp128;
		f14 = y - sp144[i] * sp124;

		tmp = sp15c[i];

		gDPSetEnvColor(gdl++,
				(colours[i] >> 24) & 0xff,
				(colours[i] >> 16) & 0xff,
				(colours[i] >> 8) & 0xff,
				(s32) ((colours[i] & 0xff) * (arg6 * f2)));

		sp17c[0] = f12;
		sp17c[1] = f14;

		sp174[1] = tmp * 0.5f;
		sp174[0] = tmp * 0.5f * scale;

		func0f0b2150(&gdl, sp17c, sp174, g_TexLightGlareConfigs[1].width, g_TexLightGlareConfigs[1].height, 0, 0, 0, 0, 0, 1);
	}

	sp128 = viGetViewWidth() / 2.0f - x;
	sp124 = viGetViewHeight() / 2.0f - y;

	f12 = (40.0f - sqrtf(sp128 * sp128 + sp124 * sp124)) * 0.0125f;

	if (f12 < 0.0f) {
		f12 = 0.0f;
	}

	f12 += 0.1f;

	if (arg5 <= g_Vars.lvupdate240) {
		f12 = 0.0f;
	}

	if (f12 > 0.0f) {
		sky0f127334(arg6 * f12 * 255.0f, arg6 * f12 * 255.0f, arg6 * f12 * 255.0f);
	}

	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetAlphaDither(gdl++, G_AD_PATTERN | G_CD_DISABLE);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);
	gDPSetTextureLOD(gdl++, G_TL_LOD);

	return gdl;
}

struct coord g_TeleportToPos = {0, 0, 0};
struct coord g_TeleportToUp = {0, 0, 1};
struct coord g_TeleportToLook = {0, 1, 0};

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
	f32 sp154 = g_20SecIntervalFrac * M_BADTAU;
	s32 i;
	f32 f20 = 0.0f;
	f32 f20_2;
	f32 f22;
	f32 f22_3;
	struct pad *pad;
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

	pad = &g_Pads[g_Vars.currentplayer->teleportpad];

	g_TeleportToPos.x = pad->pos.x;
	g_TeleportToPos.y = pad->pos.y;
	g_TeleportToPos.z = pad->pos.z;
	g_TeleportToLook.x = pad->look.x;
	g_TeleportToLook.y = pad->look.y;
	g_TeleportToLook.z = pad->look.z;
	g_TeleportToUp.x = pad->up.x;
	g_TeleportToUp.y = pad->up.y;
	g_TeleportToUp.z = pad->up.z;

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
