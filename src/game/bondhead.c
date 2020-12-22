#include <ultra64.h>
#include "constants.h"
#include "game/bondmove.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_096b20.h"
#include "game/bondhead.h"
#include "gvars/gvars.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_1a500.h"
#include "lib/lib_233c0.h"
#include "types.h"

struct var80075c00 var80075c00[] = {
	{ ANIM_2B, 9.5, 27, 0, 0,   1.5 },
	{ ANIM_29, 7.5, 17, 0, 1.5, 100 },
};

struct coord var80075c30 = {0, 0, 0};

void currentPlayerFlipAnimation(void)
{
	g_Vars.currentplayer->model.anim->flip = !g_Vars.currentplayer->model.anim->flip;
}

void currentPlayerUpdateIdleHeadRoll(void)
{
	f32 mult = 1.0f / U32_MAX;

	g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt].x = ((f32)random() * mult - 0.5f) * 0.02f;
	g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt].z = 1;
	g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt].x = ((f32)random() * mult - 0.5f) * 0.02f;
	g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt].y = 1;

	if (g_Vars.currentplayer->standcnt) {
		g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt].y = (f32)random() * mult * 0.01f;
		g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt].z = (f32)random() * mult * -0.01f;
	} else {
		g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt].y = (f32)random() * mult * -0.01f;
		g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt].z = (f32)random() * mult * 0.01f;
	}

	g_Vars.currentplayer->standcnt = 1 - g_Vars.currentplayer->standcnt;
}

void currentPlayerUpdateHeadPos(struct coord *vel)
{
	s32 i;

	if (g_Vars.currentplayer->resetheadpos) {
		g_Vars.currentplayer->headpossum.x = 0;
		g_Vars.currentplayer->headpossum.y = vel->y / 0.018000006f;
		g_Vars.currentplayer->headpossum.z = 0;

		g_Vars.currentplayer->resetheadpos = false;
	}

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		g_Vars.currentplayer->headpossum.x = vel->x + 0.982f * g_Vars.currentplayer->headpossum.x;
		g_Vars.currentplayer->headpossum.y = vel->y + 0.982f * g_Vars.currentplayer->headpossum.y;
		g_Vars.currentplayer->headpossum.z = vel->z + 0.982f * g_Vars.currentplayer->headpossum.z;
	}

	g_Vars.currentplayer->headpos.x = g_Vars.currentplayer->headpossum.x * 0.018000006f;
	g_Vars.currentplayer->headpos.y = g_Vars.currentplayer->headpossum.y * 0.018000006f;
	g_Vars.currentplayer->headpos.z = g_Vars.currentplayer->headpossum.z * 0.018000006f;
}

void currentPlayerUpdateHeadRot(struct coord *lookvel, struct coord *upvel)
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

void currentPlayerSetHeadDamp(f32 headdamp)
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

void currentPlayerUpdateHead(f32 arg0, f32 arg1)
{
	struct coord headpos = var80075c30;
	struct coord lookvel = {0, 0, 1};
	struct coord upvel = {0, 1, 0};
	f32 animspeed = 0;

	if (func00023794(g_Vars.currentplayer->model.anim->animnum)) {
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
			struct objticksp476 sp80 = {NULL, 1, 3};
			Mtxf sp40;
			struct coord modelpos = {0, 0, 0};
			bool somebool = func0001e2a8();

			g_Vars.currentplayer->unk03a8 = false;

			func0001e29c(false);
			func0001ee18(&g_Vars.currentplayer->model, g_Vars.lvupdate240, true);
			func0001e29c(somebool);
			func0001b3bc(&g_Vars.currentplayer->model);
			func000159b0(&sp40);

			sp80.matrix = &sp40;
			sp80.model0c = &g_Vars.currentplayer->unk0510;
			func0001cebc(&sp80, &g_Vars.currentplayer->model);

			g_Vars.currentplayer->headbodyoffset.x = g_Vars.currentplayer->standbodyoffset.x;
			g_Vars.currentplayer->headbodyoffset.y = g_Vars.currentplayer->standbodyoffset.y;
			g_Vars.currentplayer->headbodyoffset.z = g_Vars.currentplayer->standbodyoffset.z;

			modelGetRootPosition(&g_Vars.currentplayer->model, &modelpos);

			modelpos.x -= g_Vars.currentplayer->unk0510.unk30;
			modelpos.z -= g_Vars.currentplayer->unk0510.unk38;

			modelSetRootPosition(&g_Vars.currentplayer->model, &modelpos);
		}
	}

	if (animspeed > 0) {
		g_Vars.currentplayer->unk0510.unk30 += arg1;
		g_Vars.currentplayer->unk0510.unk38 *= arg0;

		if (g_Vars.lvupdate240 > 0) {
			g_Vars.currentplayer->unk0510.unk30 /= g_Vars.lvupdate240freal;
			g_Vars.currentplayer->unk0510.unk38 /= g_Vars.lvupdate240freal;
		}

		headpos.x = g_Vars.currentplayer->unk0510.unk30 * g_Vars.currentplayer->headamplitude;
		headpos.y = (g_Vars.currentplayer->unk0510.unk34 - g_Vars.currentplayer->standheight) *
			g_Vars.currentplayer->headamplitude + g_Vars.currentplayer->standheight;
		headpos.z = g_Vars.currentplayer->unk0510.unk38 * g_Vars.currentplayer->headamplitude;

		if (g_Vars.currentplayer->headanim >= 0) {
			lookvel.x = g_Vars.currentplayer->unk0510.unk20 * g_Vars.currentplayer->sideamplitude;
			lookvel.y = g_Vars.currentplayer->unk0510.unk24 * g_Vars.currentplayer->headamplitude;
			lookvel.z = (g_Vars.currentplayer->unk0510.unk28 - 1.0f) * g_Vars.currentplayer->headamplitude + 1.0f;

			upvel.x = g_Vars.currentplayer->unk0510.unk10 * g_Vars.currentplayer->headamplitude;
			upvel.y = (g_Vars.currentplayer->unk0510.unk14 - 1.0f) * g_Vars.currentplayer->headamplitude + 1.0f;
			upvel.z = g_Vars.currentplayer->unk0510.unk18 * g_Vars.currentplayer->headamplitude;

			g_Vars.currentplayer->headwalkingtime60 += g_Vars.lvupdate240_60;

			if (g_Vars.currentplayer->headwalkingtime60 > 60) {
				currentPlayerSetHeadDamp(0.982f);
			} else {
				currentPlayerSetHeadDamp(0.99748998880386f);
			}
		} else {
			lookvel.x = g_Vars.currentplayer->unk0510.unk20;
			lookvel.y = g_Vars.currentplayer->unk0510.unk24;
			lookvel.z = g_Vars.currentplayer->unk0510.unk28;

			upvel.x = g_Vars.currentplayer->unk0510.unk10;
			upvel.y = g_Vars.currentplayer->unk0510.unk14;
			upvel.z = g_Vars.currentplayer->unk0510.unk18;

			currentPlayerSetHeadDamp(0.96f);
		}
	} else {
		g_Vars.currentplayer->headbodyoffset.x = g_Vars.currentplayer->standbodyoffset.x;
		g_Vars.currentplayer->headbodyoffset.y = g_Vars.currentplayer->standbodyoffset.y;
		g_Vars.currentplayer->headbodyoffset.z = g_Vars.currentplayer->standbodyoffset.z;

		headpos.x = 0;
		headpos.y = g_Vars.currentplayer->standheight;
		headpos.z = 0;

		g_Vars.currentplayer->headwalkingtime60 = 0;
		currentPlayerSetHeadDamp(0.99748998880386f);

		if (currentPlayerGetCrouchPos() != CROUCH_SQUAT) {
			g_Vars.currentplayer->standfrac +=
				(0.0083333337679505f + 0.025000002235174f * g_Vars.currentplayer->bondbreathing)
				* g_Vars.lvupdate240freal;

			if (g_Vars.currentplayer->standfrac >= 1) {
				currentPlayerUpdateIdleHeadRoll();
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

	currentPlayerUpdateHeadPos(&headpos);
	currentPlayerUpdateHeadRot(&lookvel, &upvel);
}

void currentPlayerAdjustHeadAnimation(f32 speed)
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

				modelSetAnimFlipFunction(&g_Vars.currentplayer->model, currentPlayerFlipAnimation);
				g_Vars.currentplayer->headanim = i;
			}

			speed = speed / var80075c00[i].unk0c;

			modelSetAnimSpeed(&g_Vars.currentplayer->model, speed * 0.5f, 0);
			break;
		}
	}

	chr->oldframe = g_Vars.currentplayer->model.anim->frame;
}

void currentPlayerStartDeathAnimation(s16 animnum, u32 flip, f32 fstarttime, f32 speed)
{
	modelSetAnimation(&g_Vars.currentplayer->model, animnum, flip, fstarttime, speed * 0.5f, 12);
	g_Vars.currentplayer->headanim = -1;
}

void currentPlayerSetAnimSpeed(f32 speed)
{
	modelSetAnimSpeed(&g_Vars.currentplayer->model, speed * 0.5f, 0);
}

f32 func0f11416c(void)
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
