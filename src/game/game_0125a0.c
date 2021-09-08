#include <ultra64.h>
#include "constants.h"
#include "game/game_0125a0.h"
#include "game/game_013ee0.h"
#include "game/bondhead.h"
#include "game/bg.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/lib_159b0.h"
#include "lib/lib_233c0.h"
#include "lib/model.h"
#include "data.h"
#include "types.h"

void func0f0125a0(s16 animnum, s32 loopframe, s32 endframe, s32 *arg3)
{
	s16 sp48[3];
	u32 stack;

	arg3[0] = 0;
	arg3[1] = 0;
	arg3[2] = 0;

	while (loopframe < endframe) {
		func0002485c(0, 0, &g_ModelTypeChr, animnum, loopframe, sp48, 0);

		arg3[0] += sp48[0];
		arg3[1] += sp48[1];
		arg3[2] += sp48[2];

		loopframe++;
	}
}

void currentPlayerInitAnimation(void)
{
	s32 i;

	modelInit(&g_Vars.currentplayer->model, &g_PlayerModelFileData, g_Vars.currentplayer->bondheadsave, false);
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
		s32 spc8[3];
		func0f0125a0(var80075c00[i].animnum, var80075c00[i].loopframe, var80075c00[i].endframe, spc8);
		var80075c00[i].unk0c = (spc8[2] * 0.1000000089407f) / (var80075c00[i].endframe - var80075c00[i].loopframe);
	}

	{
		struct objticksp476 sp88 = {NULL, 1, 3};
		Mtxf sp48;

		modelSetAnimation(&g_Vars.currentplayer->model, 1, 0, 0, 0.5f, 0);

		func0001b3bc(&g_Vars.currentplayer->model);
		func000159b0(&sp48);
		sp88.matrix = &sp48;
		sp88.unk10 = g_Vars.currentplayer->bondheadmatrices;
		func0001cebc(&sp88, &g_Vars.currentplayer->model);

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
