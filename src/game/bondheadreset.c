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
		animGetPosAngleAsInt(0, false, &g_SkelChr, animnum, frame, inttranslate, false);

		totalinttranslate[0] += inttranslate[0];
		totalinttranslate[1] += inttranslate[1];
		totalinttranslate[2] += inttranslate[2];

		frame++;
	}
}

void bheadReset(void)
{
	s32 i;

	modelInit(&g_Vars.currentplayer->model, &g_PlayerModeldef, g_Vars.currentplayer->bondheadsave, false);
	animInit(g_Vars.currentplayer->model.anim);
	modelSetScale(&g_Vars.currentplayer->model, 0.1000000089407f);
	modelSetAnimPlaySpeed(&g_Vars.currentplayer->model, (PAL ? 1.2f : 1), 0);

	g_Vars.currentplayer->headanim = 0;
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

	for (i = 0; i < 2; i++) {
		s32 translate[3];
		func0f0125a0(var80075c00[i].animnum, var80075c00[i].loopframe, var80075c00[i].endframe, translate);
		var80075c00[i].unk0c = (translate[2] * 0.1000000089407f) / (var80075c00[i].endframe - var80075c00[i].loopframe);
	}

	{
		struct modelrenderdata renderdata = {NULL, 1, 3};
		Mtxf sp48;

		modelSetAnimation(&g_Vars.currentplayer->model, ANIM_TWO_GUN_HOLD, 0, 0, 0.5f, 0);

		modelUpdateInfo(&g_Vars.currentplayer->model);
		mtx4LoadIdentity(&sp48);
		renderdata.unk00 = &sp48;
		renderdata.unk10 = g_Vars.currentplayer->bondheadmatrices;
		modelSetMatricesWithAnim(&renderdata, &g_Vars.currentplayer->model);

		g_Vars.currentplayer->standheight = g_Vars.currentplayer->bondheadmatrices[0].m[3][1];

		g_Vars.currentplayer->standbodyoffset.x = 0;
		g_Vars.currentplayer->standbodyoffset.y = g_Vars.currentplayer->bondheadmatrices[1].m[3][1] - g_Vars.currentplayer->bondheadmatrices[0].m[3][1];
		g_Vars.currentplayer->standbodyoffset.z = g_Vars.currentplayer->bondheadmatrices[1].m[3][2] - g_Vars.currentplayer->bondheadmatrices[0].m[3][2];

		modelSetAnimation(&g_Vars.currentplayer->model,
				var80075c00[g_Vars.currentplayer->headanim].animnum,
				0,
				var80075c00[g_Vars.currentplayer->headanim].loopframe,
				0.5f, 0);

		modelSetAnimLooping(&g_Vars.currentplayer->model,
				var80075c00[g_Vars.currentplayer->headanim].loopframe, 0);

		modelSetAnimEndFrame(&g_Vars.currentplayer->model,
				var80075c00[g_Vars.currentplayer->headanim].endframe);

		modelSetAnimFlipFunction(&g_Vars.currentplayer->model, bheadFlipAnimation);

		bheadUpdateIdleRoll();
	}
}
