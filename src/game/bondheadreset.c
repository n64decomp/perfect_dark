#include <ultra64.h>
#include "constants.h"
#include "game/bondhead.h"
#include "game/bg.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/model.h"
#include "data.h"
#include "types.h"

void func0f0125a0(s16 animnum, s32 frame, s32 endframe, s32 totalinttranslate[3])
{
	s16 inttranslate[3];
	u32 stack;

	totalinttranslate[0] = 0;
	totalinttranslate[1] = 0;
	totalinttranslate[2] = 0;

	while (frame < endframe) {
		anim_get_pos_angle_as_int(0, false, &g_SkelChr, animnum, frame, inttranslate, false);

		totalinttranslate[0] += inttranslate[0];
		totalinttranslate[1] += inttranslate[1];
		totalinttranslate[2] += inttranslate[2];

		frame++;
	}
}

void bhead_reset(void)
{
	s32 i;

	model_init(&g_Vars.currentplayer->model, &g_PlayerModeldef, g_Vars.currentplayer->bondheadsave, false);
	anim_init(g_Vars.currentplayer->model.anim);
	model_set_scale(&g_Vars.currentplayer->model, 0.1000000089407f);
	model_set_anim_play_speed(&g_Vars.currentplayer->model, (PAL ? 1.2f : 1), 0);

	g_Vars.currentplayer->headanim = HEADANIM_RESTING;
	g_Vars.currentplayer->headdamp = (PAL ? 0.9166f : 0.93f);
	g_Vars.currentplayer->headwalkingtime60 = 0;
	g_Vars.currentplayer->headamplitude = 1;
	g_Vars.currentplayer->sideamplitude = 1;
	g_Vars.currentplayer->headpos.x = 0;
	g_Vars.currentplayer->headpos.y = 0;
	g_Vars.currentplayer->headpos.z = 0;
	g_Vars.currentplayer->headlook.x = 0;
	g_Vars.currentplayer->headlook.y = 0;
	g_Vars.currentplayer->headlook.z = 0;
	g_Vars.currentplayer->headup.x = 0;
	g_Vars.currentplayer->headup.y = 0;
	g_Vars.currentplayer->headup.z = 0;
	g_Vars.currentplayer->headpossum.x = 0;
	g_Vars.currentplayer->headpossum.y = 0;
	g_Vars.currentplayer->headpossum.z = 0;
	g_Vars.currentplayer->headlooksum.x = 0;
	g_Vars.currentplayer->headlooksum.y = 0;
	g_Vars.currentplayer->headlooksum.z = (PAL ? 11.990406036377f : 14.285716056824f);
	g_Vars.currentplayer->headupsum.x = 0;
	g_Vars.currentplayer->headupsum.y = (PAL ? 11.990406036377f : 14.285716056824f);
	g_Vars.currentplayer->headupsum.z = 0;
	g_Vars.currentplayer->resetheadpos = true;
	g_Vars.currentplayer->resetheadrot = true;
	g_Vars.currentplayer->resetheadtick = true;
	g_Vars.currentplayer->headbodyoffset.x = 0;
	g_Vars.currentplayer->headbodyoffset.y = 0;
	g_Vars.currentplayer->headbodyoffset.z = 0;
	g_Vars.currentplayer->standheight = 0;
	g_Vars.currentplayer->standbodyoffset.x = 0;
	g_Vars.currentplayer->standbodyoffset.y = 0;
	g_Vars.currentplayer->standbodyoffset.z = 0;
	g_Vars.currentplayer->standfrac = 0;
	g_Vars.currentplayer->standlook[0].x = 0;
	g_Vars.currentplayer->standlook[0].y = 0;
	g_Vars.currentplayer->standlook[0].z = 1;
	g_Vars.currentplayer->standlook[1].x = 0;
	g_Vars.currentplayer->standlook[1].y = 0;
	g_Vars.currentplayer->standlook[1].z = 1;
	g_Vars.currentplayer->standup[0].x = 0;
	g_Vars.currentplayer->standup[0].y = 1;
	g_Vars.currentplayer->standup[0].z = 0;
	g_Vars.currentplayer->standup[1].x = 0;
	g_Vars.currentplayer->standup[1].y = 1;
	g_Vars.currentplayer->standup[1].z = 0;
	g_Vars.currentplayer->standcnt = 0;

	for (i = 0; i < ARRAYCOUNT(g_HeadAnims); i++) {
		s32 translate[3];
		func0f0125a0(g_HeadAnims[i].animnum, g_HeadAnims[i].loopframe, g_HeadAnims[i].endframe, translate);
		g_HeadAnims[i].translateperframe = (translate[2] * 0.1000000089407f) / (g_HeadAnims[i].endframe - g_HeadAnims[i].loopframe);
	}

	{
		struct modelrenderdata renderdata = {NULL, 1, 3};
		Mtxf sp48;

		model_set_animation(&g_Vars.currentplayer->model, ANIM_TWO_GUN_HOLD, 0, 0, 0.5f, 0);

		model_update_info(&g_Vars.currentplayer->model);
		mtx4_load_identity(&sp48);
		renderdata.unk00 = &sp48;
		renderdata.unk10 = g_Vars.currentplayer->bondheadmatrices;
		model_set_matrices_with_anim(&renderdata, &g_Vars.currentplayer->model);

		g_Vars.currentplayer->standheight = g_Vars.currentplayer->bondheadmatrices[0].m[3][1];

		g_Vars.currentplayer->standbodyoffset.x = 0;
		g_Vars.currentplayer->standbodyoffset.y = g_Vars.currentplayer->bondheadmatrices[1].m[3][1] - g_Vars.currentplayer->bondheadmatrices[0].m[3][1];
		g_Vars.currentplayer->standbodyoffset.z = g_Vars.currentplayer->bondheadmatrices[1].m[3][2] - g_Vars.currentplayer->bondheadmatrices[0].m[3][2];

		model_set_animation(&g_Vars.currentplayer->model,
				g_HeadAnims[g_Vars.currentplayer->headanim].animnum,
				0,
				g_HeadAnims[g_Vars.currentplayer->headanim].loopframe,
				0.5f, 0);

		model_set_anim_looping(&g_Vars.currentplayer->model, g_HeadAnims[g_Vars.currentplayer->headanim].loopframe, 0);
		model_set_anim_end_frame(&g_Vars.currentplayer->model, g_HeadAnims[g_Vars.currentplayer->headanim].endframe);
		model_set_anim_flip_function(&g_Vars.currentplayer->model, bhead_flip_animation);

		bhead_update_idle_roll();
	}
}
