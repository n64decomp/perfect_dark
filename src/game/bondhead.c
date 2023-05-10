#include <ultra64.h>
#include "constants.h"
#include "game/bondmove.h"
#include "game/game_096b20.h"
#include "game/bondhead.h"
#include "bss.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/model.h"
#include "data.h"
#include "types.h"

struct var80075c00 var80075c00[] = {
	{ ANIM_002B, 9.5, 27, 0, 0,   1.5 },
	{ ANIM_0029, 7.5, 17, 0, 1.5, 100 },
};

struct coord var80075c30 = {0, 0, 0};

void bheadFlipAnimation(void)
{
	g_Vars.currentplayer->model.anim->flip = !g_Vars.currentplayer->model.anim->flip;
}

void bheadUpdateIdleRoll(void)
{
	g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt].x = (RANDOMFRAC() - 0.5f) * 0.02f;
	g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt].z = 1;
	g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt].x = (RANDOMFRAC() - 0.5f) * 0.02f;
	g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt].y = 1;

	if (g_Vars.currentplayer->standcnt) {
		g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt].y = RANDOMFRAC() * 0.01f;
		g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt].z = RANDOMFRAC() * -0.01f;
	} else {
		g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt].y = RANDOMFRAC() * -0.01f;
		g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt].z = RANDOMFRAC() * 0.01f;
	}

	g_Vars.currentplayer->standcnt = 1 - g_Vars.currentplayer->standcnt;
}

static void bheadUpdatePos(struct coord *vel)
{
	s32 i;

	if (g_Vars.currentplayer->resetheadpos) {
		g_Vars.currentplayer->headpossum.x = 0;
		g_Vars.currentplayer->headpossum.y = vel->y / (PAL ? 0.021499991416931f : 0.018000006f);
		g_Vars.currentplayer->headpossum.z = 0;

		g_Vars.currentplayer->resetheadpos = false;
	}

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		g_Vars.currentplayer->headpossum.x = vel->x + (PAL ? 0.9785f : 0.982f) * g_Vars.currentplayer->headpossum.x;
		g_Vars.currentplayer->headpossum.y = vel->y + (PAL ? 0.9785f : 0.982f) * g_Vars.currentplayer->headpossum.y;
		g_Vars.currentplayer->headpossum.z = vel->z + (PAL ? 0.9785f : 0.982f) * g_Vars.currentplayer->headpossum.z;
	}

	g_Vars.currentplayer->headpos.x = g_Vars.currentplayer->headpossum.x * (PAL ? 0.021499991416931f : 0.018000006f);
	g_Vars.currentplayer->headpos.y = g_Vars.currentplayer->headpossum.y * (PAL ? 0.021499991416931f : 0.018000006f);
	g_Vars.currentplayer->headpos.z = g_Vars.currentplayer->headpossum.z * (PAL ? 0.021499991416931f : 0.018000006f);
}

static void bheadUpdateRot(struct coord *lookvel, struct coord *upvel)
{
	s32 i;

	if (g_Vars.currentplayer->resetheadrot) {
		g_Vars.currentplayer->headlooksum.x = lookvel->x / (1.0f - g_Vars.currentplayer->headdamp);
		g_Vars.currentplayer->headlooksum.y = lookvel->y / (1.0f - g_Vars.currentplayer->headdamp);
		g_Vars.currentplayer->headlooksum.z = lookvel->z / (1.0f - g_Vars.currentplayer->headdamp);
		g_Vars.currentplayer->headupsum.x = upvel->x / (1.0f - g_Vars.currentplayer->headdamp);
		g_Vars.currentplayer->headupsum.y = upvel->y / (1.0f - g_Vars.currentplayer->headdamp);
		g_Vars.currentplayer->headupsum.z = upvel->z / (1.0f - g_Vars.currentplayer->headdamp);

		g_Vars.currentplayer->resetheadrot = false;
	}

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		g_Vars.currentplayer->headlooksum.x = lookvel->x + g_Vars.currentplayer->headdamp * g_Vars.currentplayer->headlooksum.x;
		g_Vars.currentplayer->headlooksum.y = lookvel->y + g_Vars.currentplayer->headdamp * g_Vars.currentplayer->headlooksum.y;
		g_Vars.currentplayer->headlooksum.z = lookvel->z + g_Vars.currentplayer->headdamp * g_Vars.currentplayer->headlooksum.z;
		g_Vars.currentplayer->headupsum.x = upvel->x + g_Vars.currentplayer->headdamp * g_Vars.currentplayer->headupsum.x;
		g_Vars.currentplayer->headupsum.y = upvel->y + g_Vars.currentplayer->headdamp * g_Vars.currentplayer->headupsum.y;
		g_Vars.currentplayer->headupsum.z = upvel->z + g_Vars.currentplayer->headdamp * g_Vars.currentplayer->headupsum.z;
	}

	g_Vars.currentplayer->headlook.x = g_Vars.currentplayer->headlooksum.x * (1.0f - g_Vars.currentplayer->headdamp);
	g_Vars.currentplayer->headlook.y = g_Vars.currentplayer->headlooksum.y * (1.0f - g_Vars.currentplayer->headdamp);
	g_Vars.currentplayer->headlook.z = g_Vars.currentplayer->headlooksum.z * (1.0f - g_Vars.currentplayer->headdamp);
	g_Vars.currentplayer->headup.x = g_Vars.currentplayer->headupsum.x * (1.0f - g_Vars.currentplayer->headdamp);
	g_Vars.currentplayer->headup.y = g_Vars.currentplayer->headupsum.y * (1.0f - g_Vars.currentplayer->headdamp);
	g_Vars.currentplayer->headup.z = g_Vars.currentplayer->headupsum.z * (1.0f - g_Vars.currentplayer->headdamp);
}

static void bheadSetDamp(f32 headdamp)
{
	if (headdamp != g_Vars.currentplayer->headdamp) {
		f32 divisor = 1.0f - headdamp;
		g_Vars.currentplayer->headlooksum.x = (g_Vars.currentplayer->headlooksum.x * (1.0f - g_Vars.currentplayer->headdamp)) / divisor;
		g_Vars.currentplayer->headlooksum.y = (g_Vars.currentplayer->headlooksum.y * (1.0f - g_Vars.currentplayer->headdamp)) / divisor;
		g_Vars.currentplayer->headlooksum.z = (g_Vars.currentplayer->headlooksum.z * (1.0f - g_Vars.currentplayer->headdamp)) / divisor;
		g_Vars.currentplayer->headupsum.x = (g_Vars.currentplayer->headupsum.x * (1.0f - g_Vars.currentplayer->headdamp)) / divisor;
		g_Vars.currentplayer->headupsum.y = (g_Vars.currentplayer->headupsum.y * (1.0f - g_Vars.currentplayer->headdamp)) / divisor;
		g_Vars.currentplayer->headupsum.z = (g_Vars.currentplayer->headupsum.z * (1.0f - g_Vars.currentplayer->headdamp)) / divisor;
		g_Vars.currentplayer->headdamp = headdamp;
	}
}

void bheadUpdate(f32 arg0, f32 arg1)
{
	struct coord headpos = var80075c30;
	struct coord lookvel = {0, 0, 1};
	struct coord upvel = {0, 1, 0};
	f32 animspeed = 0;

	if (animHasFrames(g_Vars.currentplayer->model.anim->animnum)) {
		animspeed = modelGetAbsAnimSpeed(&g_Vars.currentplayer->model);

		if (g_Vars.currentplayer->headanim == 0) {
			if (animspeed > 0.69999998807907f) {
				g_Vars.currentplayer->headamplitude = 1;
			} else if (animspeed > 0.1f) {
				g_Vars.currentplayer->headamplitude = 0.4f + (animspeed - 0.1f) * 0.60000002384186f / 0.59999996423721f;
			} else {
				g_Vars.currentplayer->headamplitude = 0.4f;
			}

			g_Vars.currentplayer->sideamplitude = g_Vars.currentplayer->headamplitude;
		} else {
			if (g_Vars.currentplayer->headanim == 1) {
				g_Vars.currentplayer->headamplitude = 0.89999997615814f;
				g_Vars.currentplayer->sideamplitude = 0.5f;
			} else {
				g_Vars.currentplayer->headamplitude = 1;
				g_Vars.currentplayer->sideamplitude = g_Vars.currentplayer->headamplitude;
			}
		}

		{
			struct modelrenderdata sp80 = {NULL, 1, 3};
			Mtxf sp40;
			struct coord modelpos = {0, 0, 0};
			bool somebool = var8005efdc;

			g_Vars.currentplayer->resetheadtick = false;

			var8005efdc = false;
			model0001ee18(&g_Vars.currentplayer->model, g_Vars.lvupdate240, true);
			var8005efdc = somebool;
			model0001b3bc(&g_Vars.currentplayer->model);
			mtx4LoadIdentity(&sp40);

			sp80.unk00 = &sp40;
			sp80.unk10 = g_Vars.currentplayer->bondheadmatrices;
			model0001cebc(&sp80, &g_Vars.currentplayer->model);

			g_Vars.currentplayer->headbodyoffset = g_Vars.currentplayer->standbodyoffset;

			modelGetRootPosition(&g_Vars.currentplayer->model, &modelpos);

			modelpos.x -= g_Vars.currentplayer->bondheadmatrices[0].m[3][0];
			modelpos.z -= g_Vars.currentplayer->bondheadmatrices[0].m[3][2];

			modelSetRootPosition(&g_Vars.currentplayer->model, &modelpos);
		}
	}

	if (animspeed > 0) {
		g_Vars.currentplayer->bondheadmatrices[0].m[3][0] += arg1;
		g_Vars.currentplayer->bondheadmatrices[0].m[3][2] *= arg0;

		if (g_Vars.lvupdate240 > 0) {
			g_Vars.currentplayer->bondheadmatrices[0].m[3][0] /= g_Vars.lvupdate60freal;
			g_Vars.currentplayer->bondheadmatrices[0].m[3][2] /= g_Vars.lvupdate60freal;
		}

		headpos.x = g_Vars.currentplayer->bondheadmatrices[0].m[3][0] * g_Vars.currentplayer->headamplitude;
		headpos.y = (g_Vars.currentplayer->bondheadmatrices[0].m[3][1] - g_Vars.currentplayer->standheight) *
			g_Vars.currentplayer->headamplitude + g_Vars.currentplayer->standheight;
		headpos.z = g_Vars.currentplayer->bondheadmatrices[0].m[3][2] * g_Vars.currentplayer->headamplitude;

		if (g_Vars.currentplayer->headanim >= 0) {
			lookvel.x = g_Vars.currentplayer->bondheadmatrices[0].m[2][0] * g_Vars.currentplayer->sideamplitude;
			lookvel.y = g_Vars.currentplayer->bondheadmatrices[0].m[2][1] * g_Vars.currentplayer->headamplitude;
			lookvel.z = (g_Vars.currentplayer->bondheadmatrices[0].m[2][2] - 1.0f) * g_Vars.currentplayer->headamplitude + 1.0f;

			upvel.x = g_Vars.currentplayer->bondheadmatrices[0].m[1][0] * g_Vars.currentplayer->headamplitude;
			upvel.y = (g_Vars.currentplayer->bondheadmatrices[0].m[1][1] - 1.0f) * g_Vars.currentplayer->headamplitude + 1.0f;
			upvel.z = g_Vars.currentplayer->bondheadmatrices[0].m[1][2] * g_Vars.currentplayer->headamplitude;

			g_Vars.currentplayer->headwalkingtime60 += g_Vars.lvupdate60;

			if (g_Vars.currentplayer->headwalkingtime60 > TICKS(60)) {
				bheadSetDamp(PAL ? 0.9785f : 0.982f);
			} else {
				bheadSetDamp(PAL ? 0.99699f : 0.99748998880386f);
			}
		} else {
			lookvel.x = g_Vars.currentplayer->bondheadmatrices[0].m[2][0];
			lookvel.y = g_Vars.currentplayer->bondheadmatrices[0].m[2][1];
			lookvel.z = g_Vars.currentplayer->bondheadmatrices[0].m[2][2];

			upvel.x = g_Vars.currentplayer->bondheadmatrices[0].m[1][0];
			upvel.y = g_Vars.currentplayer->bondheadmatrices[0].m[1][1];
			upvel.z = g_Vars.currentplayer->bondheadmatrices[0].m[1][2];

			bheadSetDamp(PAL ? 0.952f : 0.96f);
		}
	} else {
		g_Vars.currentplayer->headbodyoffset = g_Vars.currentplayer->standbodyoffset;

		headpos.x = 0;
		headpos.y = g_Vars.currentplayer->standheight;
		headpos.z = 0;

		g_Vars.currentplayer->headwalkingtime60 = 0;
		bheadSetDamp(PAL ? 0.99699f : 0.99748998880386f);

		if (bmoveGetCrouchPos() != CROUCHPOS_SQUAT) {
			g_Vars.currentplayer->standfrac +=
				(0.0083333337679505f + 0.025000002235174f * g_Vars.currentplayer->bondbreathing)
				* g_Vars.lvupdate60freal;

			if (g_Vars.currentplayer->standfrac >= 1) {
				bheadUpdateIdleRoll();
				g_Vars.currentplayer->standfrac -= 1;
			}

			func0f096b20(
					&g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt],
					&g_Vars.currentplayer->standlook[1 - g_Vars.currentplayer->standcnt],
					g_Vars.currentplayer->standfrac, &lookvel);

			lookvel.x *= 1 + 5 * g_Vars.currentplayer->bondbreathing;
			lookvel.y *= 1 + 5 * g_Vars.currentplayer->bondbreathing;

			func0f096b20(
					&g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt],
					&g_Vars.currentplayer->standup[1 - g_Vars.currentplayer->standcnt],
					g_Vars.currentplayer->standfrac, &upvel);

			upvel.x *= 1 + 5 * g_Vars.currentplayer->bondbreathing;
			upvel.z *= 1 + 5 * g_Vars.currentplayer->bondbreathing;
		}
	}

	bheadUpdatePos(&headpos);
	bheadUpdateRot(&lookvel, &upvel);
}

void bheadAdjustAnimation(f32 speed)
{
	struct chrdata *chr = g_Vars.currentplayer->prop->chr;
	s32 i;

	speed *= var80075c00[1].unk0c;

	for (i = 0; i < 2; i++) {
		if (var80075c00[i].unk14 * var80075c00[i].unk0c >= speed) {
			s32 headanim = g_Vars.currentplayer->headanim;

			if (i != headanim) {
				f32 startframe = 0.0f;

				if (headanim >= 0) {
					startframe = (g_Vars.currentplayer->model.anim->frame - var80075c00[headanim].loopframe)
						/ (var80075c00[headanim].endframe - var80075c00[headanim].loopframe);
					startframe = var80075c00[i].loopframe + (var80075c00[i].endframe - var80075c00[i].loopframe) * startframe;
				}

				modelSetAnimation(&g_Vars.currentplayer->model, var80075c00[i].animnum,
						g_Vars.currentplayer->model.anim->flip, startframe, 0.5f, 12);
				modelSetAnimLooping(&g_Vars.currentplayer->model, var80075c00[i].loopframe, false);
				modelSetAnimEndFrame(&g_Vars.currentplayer->model, var80075c00[i].endframe);

				modelSetAnimFlipFunction(&g_Vars.currentplayer->model, bheadFlipAnimation);
				g_Vars.currentplayer->headanim = i;
			}

			speed = speed / var80075c00[i].unk0c;

			modelSetAnimSpeed(&g_Vars.currentplayer->model, speed * 0.5f, 0);
			break;
		}
	}

	chr->oldframe = g_Vars.currentplayer->model.anim->frame;
}

void bheadStartDeathAnimation(s16 animnum, u32 flip, f32 fstarttime, f32 speed)
{
	modelSetAnimation(&g_Vars.currentplayer->model, animnum, flip, fstarttime, speed * 0.5f, 12);
	g_Vars.currentplayer->headanim = -1;
}

void bheadSetSpeed(f32 speed)
{
	modelSetAnimSpeed(&g_Vars.currentplayer->model, speed * 0.5f, 0);
}

f32 bheadGetBreathingValue(void)
{
	if (g_Vars.currentplayer->headanim >= 0) {
		f32 a = g_Vars.currentplayer->bondbreathing * 0.012500001f + 0.004166667f;
		f32 b = modelGetAbsAnimSpeed(&g_Vars.currentplayer->model);

		if (b > 0) {
			f32 c = b / (var80075c00[g_Vars.currentplayer->headanim].endframe - var80075c00[g_Vars.currentplayer->headanim].loopframe);

			if (c < a) {
				c = a;
			}

			return c;
		}

		return a;
	}

	return 0;
}
