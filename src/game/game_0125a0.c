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

GLOBAL_ASM(
glabel func0f0125a0
/*  f0125a0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0125a4:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f0125a8:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f0125ac:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0125b0:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0125b4:	00049c00 */ 	sll	$s3,$a0,0x10
/*  f0125b8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0125bc:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f0125c0:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f0125c4:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0125c8:	00137403 */ 	sra	$t6,$s3,0x10
/*  f0125cc:	00a6082a */ 	slt	$at,$a1,$a2
/*  f0125d0:	01c09825 */ 	or	$s3,$t6,$zero
/*  f0125d4:	00e08025 */ 	or	$s0,$a3,$zero
/*  f0125d8:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0125dc:	00c09025 */ 	or	$s2,$a2,$zero
/*  f0125e0:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f0125e4:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f0125e8:	1020001d */ 	beqz	$at,.L0f012660
/*  f0125ec:	ace00008 */ 	sw	$zero,0x8($a3)
/*  f0125f0:	3c148008 */ 	lui	$s4,%hi(g_ModelTypeChr)
/*  f0125f4:	2694ce40 */ 	addiu	$s4,$s4,%lo(g_ModelTypeChr)
/*  f0125f8:	27b50048 */ 	addiu	$s5,$sp,0x48
.L0f0125fc:
/*  f0125fc:	00133c00 */ 	sll	$a3,$s3,0x10
/*  f012600:	00077c03 */ 	sra	$t7,$a3,0x10
/*  f012604:	01e03825 */ 	or	$a3,$t7,$zero
/*  f012608:	00002025 */ 	or	$a0,$zero,$zero
/*  f01260c:	00002825 */ 	or	$a1,$zero,$zero
/*  f012610:	02803025 */ 	or	$a2,$s4,$zero
/*  f012614:	afb10010 */ 	sw	$s1,0x10($sp)
/*  f012618:	afb50014 */ 	sw	$s5,0x14($sp)
/*  f01261c:	0c009217 */ 	jal	func0002485c
/*  f012620:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f012624:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f012628:	87b90048 */ 	lh	$t9,0x48($sp)
/*  f01262c:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f012630:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f012634:	03194021 */ 	addu	$t0,$t8,$t9
/*  f012638:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f01263c:	87aa004a */ 	lh	$t2,0x4a($sp)
/*  f012640:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f012644:	0232082a */ 	slt	$at,$s1,$s2
/*  f012648:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f01264c:	ae0b0004 */ 	sw	$t3,0x4($s0)
/*  f012650:	87ad004c */ 	lh	$t5,0x4c($sp)
/*  f012654:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f012658:	1420ffe8 */ 	bnez	$at,.L0f0125fc
/*  f01265c:	ae0e0008 */ 	sw	$t6,0x8($s0)
.L0f012660:
/*  f012660:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f012664:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f012668:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f01266c:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f012670:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f012674:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f012678:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f01267c:	03e00008 */ 	jr	$ra
/*  f012680:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

void currentPlayerInitAnimation(void)
{
	s32 i;

	func00022fa4(&g_Vars.currentplayer->model, &var8007c0c0, &g_Vars.currentplayer->unk0494, 0);
	animInitialise(g_Vars.currentplayer->model.anim);
	modelSetUnk14(&g_Vars.currentplayer->model, 0.1000000089407f);
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
	g_Vars.currentplayer->unk03a8 = true;
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
		sp88.unk10 = &g_Vars.currentplayer->unk0510;
		func0001cebc(&sp88, &g_Vars.currentplayer->model);

		g_Vars.currentplayer->standheight = g_Vars.currentplayer->unk0510.m[3][1];

		g_Vars.currentplayer->standbodyoffset.x = 0;
		g_Vars.currentplayer->standbodyoffset.y = g_Vars.currentplayer->unk0550.m[3][1] - g_Vars.currentplayer->unk0510.m[3][1];
		g_Vars.currentplayer->standbodyoffset.z = g_Vars.currentplayer->unk0550.m[3][2] - g_Vars.currentplayer->unk0510.m[3][2];

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
