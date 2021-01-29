#include <ultra64.h>
#include "constants.h"
#include "game/bondbike.h"
#include "game/bondmove.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_0601b0.h"
#include "game/game_091e10.h"
#include "game/game_092610.h"
#include "game/game_095320.h"
#include "game/game_096ca0.h"
#include "game/game_097ba0.h"
#include "game/game_0b3350.h"
#include "game/game_0b69d0.h"
#include "game/bondhead.h"
#include "game/core.h"
#include "game/pdoptions.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
#include "lib/lib_13900.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_4a360.h"
#include "types.h"

void bbikeInit(void)
{
	struct hoverbikeobj *hoverbike = (struct hoverbikeobj *)g_Vars.currentplayer->hoverbike->obj;
	Mtxf matrix;

	g_Vars.currentplayer->bondmovemode = MOVEMODE_BIKE;
	g_Vars.currentplayer->bondvehiclemode = 0;
	g_Vars.currentplayer->guncloseroffset = 0;
	g_Vars.currentplayer->gunextraaimx = 0;
	g_Vars.currentplayer->gunextraaimy = 0;

	bbikeUpdateVehicleOffset();

	g_Vars.currentplayer->bondentert = 0;
	g_Vars.currentplayer->bondentert2 = 1;
	g_Vars.currentplayer->bondenterpos.x = g_Vars.currentplayer->prop->pos.x;
	g_Vars.currentplayer->bondenterpos.y = g_Vars.currentplayer->prop->pos.y;
	g_Vars.currentplayer->bondenterpos.z = g_Vars.currentplayer->prop->pos.z;

	func00015d54(hoverbike->base.realrot, &matrix);
	func00015dd4(&hoverbike->base.prop->pos, &matrix);
	func00015b68(&matrix, &g_Vars.currentplayer->bondvehicleoffset, &g_Vars.currentplayer->bondenteraim);
	func00016b58(&g_Vars.currentplayer->bondentermtx,
			0, 0, 0,
			-g_Vars.currentplayer->bond2.unk1c.x, -g_Vars.currentplayer->bond2.unk1c.y, -g_Vars.currentplayer->bond2.unk1c.z,
			g_Vars.currentplayer->bond2.unk28.x, g_Vars.currentplayer->bond2.unk28.y, g_Vars.currentplayer->bond2.unk28.z);

	g_Vars.currentplayer->speedtheta = 0;
	g_Vars.currentplayer->speedthetacontrol = 0;
	g_Vars.currentplayer->speedforwards = 0;
	g_Vars.currentplayer->speedsideways = 0;

	if (hoverbike->base.hidden & OBJHFLAG_AIRBORNE) {
		struct projectile *projectile = hoverbike->base.projectile;
		hoverbike->speed[0] = projectile->unk004.x;
		hoverbike->speed[1] = projectile->unk004.z;
		hoverbike->w = projectile->unk0dc;
	}

	func0f06ac90(g_Vars.currentplayer->hoverbike);

	hoverbike->base.hidden |= OBJHFLAG_04000000;
}

void bbikeExit(void)
{
	struct defaultobj *obj = g_Vars.currentplayer->hoverbike->obj;
	struct hoverbikeobj *bikeobj = (struct hoverbikeobj *)g_Vars.currentplayer->hoverbike->obj;
	struct coord coord;
	f32 w;

	obj->hidden &= ~OBJHFLAG_04000000;

	coord.x = bikeobj->speed[0];
	coord.y = 0;
	coord.z = bikeobj->speed[1];
	w = bikeobj->w;

	func0f082a1c(obj, &coord, w, 0, 0);
	func0f0926bc(g_Vars.currentplayer->hoverbike, 1, 0xffff);
	func0f0926bc(g_Vars.currentplayer->prop, 1, 0xffff);
	func0f0939f8(NULL, g_Vars.currentplayer->hoverbike, 0x80af, -1,
			-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);

	obj->flags |= OBJFLAG_40000000;
}

void bbikeUpdateVehicleOffset(void)
{
	struct defaultobj *hoverbike = g_Vars.currentplayer->hoverbike->obj;

	g_Vars.currentplayer->bondvehicleoffset.x = 0.0f / hoverbike->model->unk14;
	g_Vars.currentplayer->bondvehicleoffset.y = 80.0f / hoverbike->model->unk14;
	g_Vars.currentplayer->bondvehicleoffset.z = -50.0f / hoverbike->model->unk14;
}

void bbikeTryDismountAngle(f32 relativeangle, f32 distance)
{
	u32 stack;
	struct hoverbikeobj *bike;
	f32 angle;
	struct coord pos;
	s16 rooms[8];
	s32 result;
	f32 ymax;
	f32 ymin;
	f32 width;

	if (g_Vars.currentplayer->walkinitmove == 0) {
		bike = (struct hoverbikeobj *)g_Vars.currentplayer->hoverbike->obj;
		angle = hoverpropGetTurnAngle(&bike->base);

		propPlayerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);

		distance += width + 10;

		angle += relativeangle;

		if (angle >= M_BADTAU) {
			angle -= M_BADTAU;
		}

		pos.x = g_Vars.currentplayer->hoverbike->pos.x + sinf(angle) * distance;
		pos.y = g_Vars.currentplayer->hoverbike->pos.y;
		pos.z = g_Vars.currentplayer->hoverbike->pos.z + cosf(angle) * distance;

		propSetCollisionsEnabled(g_Vars.currentplayer->hoverbike, false);
		propSetCollisionsEnabled(g_Vars.currentplayer->prop, false);

		func0f065e74(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, &pos, rooms);
		bmove0f0cb79c(g_Vars.currentplayer, &pos, rooms);

		result = cdTestAToB2(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms,
				&pos, rooms, CDTYPE_ALL, true,
				ymax - g_Vars.currentplayer->prop->pos.y,
				ymin - g_Vars.currentplayer->prop->pos.y);

		propSetCollisionsEnabled(g_Vars.currentplayer->hoverbike, true);

		if (result == CDRESULT_NOCOLLISION) {
			result = cdTestVolume(&pos, width, rooms, CDTYPE_ALL, true,
					ymax - g_Vars.currentplayer->prop->pos.y,
					ymin - g_Vars.currentplayer->prop->pos.y);
		}

		if (result == CDRESULT_NOCOLLISION) {
			g_Vars.currentplayer->walkinitmove = true;

			g_Vars.currentplayer->walkinitpos.x = pos.x;
			g_Vars.currentplayer->walkinitpos.y = pos.y;
			g_Vars.currentplayer->walkinitpos.z = pos.z;

			g_Vars.currentplayer->moveinitspeed.x = bike->speed[0];
			g_Vars.currentplayer->moveinitspeed.y = 0;
			g_Vars.currentplayer->moveinitspeed.z = bike->speed[1];
		}

		propSetCollisionsEnabled(g_Vars.currentplayer->prop, true);
	}
}

void bbikeHandleActivate(void)
{
	if (g_Vars.currentplayer->bondvehiclemode == VEHICLEMODE_RUNNING
			&& g_Vars.lvframe60 - g_Vars.currentplayer->activatetimelast < 25) {
		struct hoverbikeobj *bike = (struct hoverbikeobj *)g_Vars.currentplayer->hoverbike->obj;
		struct model08thing *thing = func0f068af4(&bike->base);

		f32 fVar5 = thing->unk04[1] * bike->base.model->unk14;
		f32 fVar3 = thing->unk18 * bike->base.model->unk14;
		f32 uVar4 = sqrtf(fVar5 * fVar5 + fVar3 * fVar3);

		g_Vars.currentplayer->walkinitmove = false;

		bbikeTryDismountAngle(1.5705462694168f, fVar5);
		bbikeTryDismountAngle(4.7116389274597f, fVar5);
		bbikeTryDismountAngle(0.7852731347084f, uVar4);
		bbikeTryDismountAngle(5.4969120025635f, uVar4);
		bbikeTryDismountAngle(2.3558194637299f, uVar4);
		bbikeTryDismountAngle(3.9263656139374f, uVar4);
		bbikeTryDismountAngle(0, fVar3);
		bbikeTryDismountAngle(3.1410925388336f, fVar3);

		if (g_Vars.currentplayer->walkinitmove) {
			bmoveSetMode(MOVEMODE_WALK);
		}

		g_Vars.currentplayer->bondactivateorreload = 0;
	}
}

GLOBAL_ASM(
glabel bbikeApplyMoveData
.late_rodata
glabel var7f1adb54
.word 0x3dcccccd
glabel var7f1adb58
.word 0xbdcccccd
glabel var7f1adb5c
.word 0xbdcccccd
glabel var7f1adb60
.word 0x3dcccccd
glabel var7f1adb64
.word 0x40490fdb
glabel var7f1adb68
.word 0x3f4ccccd
glabel var7f1adb6c
.word 0x40c907a9
glabel var7f1adb70
.word 0x40c907a9
glabel var7f1adb74
.word 0x3f4ccccd
.text
/*  f0d26ac:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0d26b0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0d26b4:	8c4e0284 */ 	lw	$t6,0x284($v0)
/*  f0d26b8:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0d26bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0d26c0:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0d26c4:	8dcf1a6c */ 	lw	$t7,0x1a6c($t6)
/*  f0d26c8:	8c590288 */ 	lw	$t9,0x288($v0)
/*  f0d26cc:	8df80004 */ 	lw	$t8,0x4($t7)
/*  f0d26d0:	afb8005c */ 	sw	$t8,0x5c($sp)
/*  f0d26d4:	0fc549d2 */ 	jal	optionsGetContpadNum1
/*  f0d26d8:	8f240070 */ 	lw	$a0,0x70($t9)
/*  f0d26dc:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x288)
/*  f0d26e0:	8d08a248 */ 	lw	$t0,%lo(g_Vars+0x288)($t0)
/*  f0d26e4:	a3a2005b */ 	sb	$v0,0x5b($sp)
/*  f0d26e8:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f0d26ec:	8d040070 */ 	lw	$a0,0x70($t0)
/*  f0d26f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0d26f4:	10410012 */ 	beq	$v0,$at,.L0f0d2740
/*  f0d26f8:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x288)
/*  f0d26fc:	8d29a248 */ 	lw	$t1,%lo(g_Vars+0x288)($t1)
/*  f0d2700:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f0d2704:	8d240070 */ 	lw	$a0,0x70($t1)
/*  f0d2708:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0d270c:	1041000c */ 	beq	$v0,$at,.L0f0d2740
/*  f0d2710:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x288)
/*  f0d2714:	8d4aa248 */ 	lw	$t2,%lo(g_Vars+0x288)($t2)
/*  f0d2718:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f0d271c:	8d440070 */ 	lw	$a0,0x70($t2)
/*  f0d2720:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0d2724:	10410006 */ 	beq	$v0,$at,.L0f0d2740
/*  f0d2728:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x288)
/*  f0d272c:	8d6ba248 */ 	lw	$t3,%lo(g_Vars+0x288)($t3)
/*  f0d2730:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f0d2734:	8d640070 */ 	lw	$a0,0x70($t3)
/*  f0d2738:	14400011 */ 	bnez	$v0,.L0f0d2780
/*  f0d273c:	8fa70060 */ 	lw	$a3,0x60($sp)
.L0f0d2740:
/*  f0d2740:	0fc5b364 */ 	jal	coreIsPaused
/*  f0d2744:	00000000 */ 	nop
/*  f0d2748:	1440000d */ 	bnez	$v0,.L0f0d2780
/*  f0d274c:	8fa70060 */ 	lw	$a3,0x60($sp)
/*  f0d2750:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d2754:	83a5005b */ 	lb	$a1,0x5b($sp)
/*  f0d2758:	0c005326 */ 	jal	contCountButtonsOnSpecificSamples
/*  f0d275c:	24060202 */ 	addiu	$a2,$zero,0x202
/*  f0d2760:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0d2764:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d2768:	24060101 */ 	addiu	$a2,$zero,0x101
/*  f0d276c:	ad820028 */ 	sw	$v0,0x28($t4)
/*  f0d2770:	0c005326 */ 	jal	contCountButtonsOnSpecificSamples
/*  f0d2774:	83a5005b */ 	lb	$a1,0x5b($sp)
/*  f0d2778:	8fa70060 */ 	lw	$a3,0x60($sp)
/*  f0d277c:	ace2002c */ 	sw	$v0,0x2c($a3)
.L0f0d2780:
/*  f0d2780:	8ced0020 */ 	lw	$t5,0x20($a3)
/*  f0d2784:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0d2788:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0d278c:	11a00015 */ 	beqz	$t5,.L0f0d27e4
/*  f0d2790:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d2794:	44819000 */ 	mtc1	$at,$f18
/*  f0d2798:	3c017f1b */ 	lui	$at,%hi(var7f1adb54)
/*  f0d279c:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0d27a0:	c424db54 */ 	lwc1	$f4,%lo(var7f1adb54)($at)
/*  f0d27a4:	c486004c */ 	lwc1	$f6,0x4c($a0)
/*  f0d27a8:	c4400170 */ 	lwc1	$f0,0x170($v0)
/*  f0d27ac:	46062302 */ 	mul.s	$f12,$f4,$f6
/*  f0d27b0:	46009081 */ 	sub.s	$f2,$f18,$f0
/*  f0d27b4:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0d27b8:	00000000 */ 	nop
/*  f0d27bc:	45020003 */ 	bc1fl	.L0f0d27cc
/*  f0d27c0:	46020200 */ 	add.s	$f8,$f0,$f2
/*  f0d27c4:	46006086 */ 	mov.s	$f2,$f12
/*  f0d27c8:	46020200 */ 	add.s	$f8,$f0,$f2
.L0f0d27cc:
/*  f0d27cc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d27d0:	44817000 */ 	mtc1	$at,$f14
/*  f0d27d4:	44808000 */ 	mtc1	$zero,$f16
/*  f0d27d8:	e4480170 */ 	swc1	$f8,0x170($v0)
/*  f0d27dc:	10000055 */ 	b	.L0f0d2934
/*  f0d27e0:	8c820284 */ 	lw	$v0,0x284($a0)
.L0f0d27e4:
/*  f0d27e4:	8cee0024 */ 	lw	$t6,0x24($a3)
/*  f0d27e8:	11c0001a */ 	beqz	$t6,.L0f0d2854
/*  f0d27ec:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d27f0:	44817000 */ 	mtc1	$at,$f14
/*  f0d27f4:	3c017f1b */ 	lui	$at,%hi(var7f1adb58)
/*  f0d27f8:	c42adb58 */ 	lwc1	$f10,%lo(var7f1adb58)($at)
/*  f0d27fc:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0d2800:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4c)
/*  f0d2804:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0d2808:	c424a00c */ 	lwc1	$f4,%lo(g_Vars+0x4c)($at)
/*  f0d280c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d2810:	c4400170 */ 	lwc1	$f0,0x170($v0)
/*  f0d2814:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f0d2818:	44819000 */ 	mtc1	$at,$f18
/*  f0d281c:	46007081 */ 	sub.s	$f2,$f14,$f0
/*  f0d2820:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0d2824:	00000000 */ 	nop
/*  f0d2828:	45020003 */ 	bc1fl	.L0f0d2838
/*  f0d282c:	46020180 */ 	add.s	$f6,$f0,$f2
/*  f0d2830:	46006086 */ 	mov.s	$f2,$f12
/*  f0d2834:	46020180 */ 	add.s	$f6,$f0,$f2
.L0f0d2838:
/*  f0d2838:	44808000 */ 	mtc1	$zero,$f16
/*  f0d283c:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0d2840:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0d2844:	e4460170 */ 	swc1	$f6,0x170($v0)
/*  f0d2848:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0d284c:	10000039 */ 	b	.L0f0d2934
/*  f0d2850:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
.L0f0d2854:
/*  f0d2854:	8cef0010 */ 	lw	$t7,0x10($a3)
/*  f0d2858:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x284)
/*  f0d285c:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0d2860:	11e0002b */ 	beqz	$t7,.L0f0d2910
/*  f0d2864:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d2868:	8cf800a8 */ 	lw	$t8,0xa8($a3)
/*  f0d286c:	3c01428c */ 	lui	$at,0x428c
/*  f0d2870:	44812000 */ 	mtc1	$at,$f4
/*  f0d2874:	44984000 */ 	mtc1	$t8,$f8
/*  f0d2878:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x284)
/*  f0d287c:	8f39a244 */ 	lw	$t9,%lo(g_Vars+0x284)($t9)
/*  f0d2880:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d2884:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0d2888:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d288c:	44814000 */ 	mtc1	$at,$f8
/*  f0d2890:	44808000 */ 	mtc1	$zero,$f16
/*  f0d2894:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d2898:	46045183 */ 	div.s	$f6,$f10,$f4
/*  f0d289c:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0d28a0:	e7260170 */ 	swc1	$f6,0x170($t9)
/*  f0d28a4:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0d28a8:	c4400170 */ 	lwc1	$f0,0x170($v0)
/*  f0d28ac:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0d28b0:	00000000 */ 	nop
/*  f0d28b4:	4502000a */ 	bc1fl	.L0f0d28e0
/*  f0d28b8:	44817000 */ 	mtc1	$at,$f14
/*  f0d28bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d28c0:	44815000 */ 	mtc1	$at,$f10
/*  f0d28c4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d28c8:	44817000 */ 	mtc1	$at,$f14
/*  f0d28cc:	e44a0170 */ 	swc1	$f10,0x170($v0)
/*  f0d28d0:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0d28d4:	1000000a */ 	b	.L0f0d2900
/*  f0d28d8:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0d28dc:	44817000 */ 	mtc1	$at,$f14
.L0f0d28e0:
/*  f0d28e0:	00000000 */ 	nop
/*  f0d28e4:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0d28e8:	00000000 */ 	nop
/*  f0d28ec:	45020005 */ 	bc1fl	.L0f0d2904
/*  f0d28f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d28f4:	e44e0170 */ 	swc1	$f14,0x170($v0)
/*  f0d28f8:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0d28fc:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
.L0f0d2900:
/*  f0d2900:	3c013f80 */ 	lui	$at,0x3f80
.L0f0d2904:
/*  f0d2904:	44819000 */ 	mtc1	$at,$f18
/*  f0d2908:	1000000a */ 	b	.L0f0d2934
/*  f0d290c:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
.L0f0d2910:
/*  f0d2910:	44808000 */ 	mtc1	$zero,$f16
/*  f0d2914:	8d08a244 */ 	lw	$t0,%lo(g_Vars+0x284)($t0)
/*  f0d2918:	44819000 */ 	mtc1	$at,$f18
/*  f0d291c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d2920:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0d2924:	e5100170 */ 	swc1	$f16,0x170($t0)
/*  f0d2928:	44817000 */ 	mtc1	$at,$f14
/*  f0d292c:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0d2930:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
.L0f0d2934:
/*  f0d2934:	8ce30028 */ 	lw	$v1,0x28($a3)
/*  f0d2938:	50600011 */ 	beqzl	$v1,.L0f0d2980
/*  f0d293c:	8ce3002c */ 	lw	$v1,0x2c($a3)
/*  f0d2940:	44832000 */ 	mtc1	$v1,$f4
/*  f0d2944:	3c017f1b */ 	lui	$at,%hi(var7f1adb5c)
/*  f0d2948:	c428db5c */ 	lwc1	$f8,%lo(var7f1adb5c)($at)
/*  f0d294c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d2950:	c4400168 */ 	lwc1	$f0,0x168($v0)
/*  f0d2954:	46007081 */ 	sub.s	$f2,$f14,$f0
/*  f0d2958:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f0d295c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0d2960:	00000000 */ 	nop
/*  f0d2964:	45020003 */ 	bc1fl	.L0f0d2974
/*  f0d2968:	46020280 */ 	add.s	$f10,$f0,$f2
/*  f0d296c:	46006086 */ 	mov.s	$f2,$f12
/*  f0d2970:	46020280 */ 	add.s	$f10,$f0,$f2
.L0f0d2974:
/*  f0d2974:	1000002e */ 	b	.L0f0d2a30
/*  f0d2978:	e44a0168 */ 	swc1	$f10,0x168($v0)
/*  f0d297c:	8ce3002c */ 	lw	$v1,0x2c($a3)
.L0f0d2980:
/*  f0d2980:	50600011 */ 	beqzl	$v1,.L0f0d29c8
/*  f0d2984:	8ce90014 */ 	lw	$t1,0x14($a3)
/*  f0d2988:	44832000 */ 	mtc1	$v1,$f4
/*  f0d298c:	3c017f1b */ 	lui	$at,%hi(var7f1adb60)
/*  f0d2990:	c428db60 */ 	lwc1	$f8,%lo(var7f1adb60)($at)
/*  f0d2994:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d2998:	c4400168 */ 	lwc1	$f0,0x168($v0)
/*  f0d299c:	46009081 */ 	sub.s	$f2,$f18,$f0
/*  f0d29a0:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f0d29a4:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0d29a8:	00000000 */ 	nop
/*  f0d29ac:	45020003 */ 	bc1fl	.L0f0d29bc
/*  f0d29b0:	46020280 */ 	add.s	$f10,$f0,$f2
/*  f0d29b4:	46006086 */ 	mov.s	$f2,$f12
/*  f0d29b8:	46020280 */ 	add.s	$f10,$f0,$f2
.L0f0d29bc:
/*  f0d29bc:	1000001c */ 	b	.L0f0d2a30
/*  f0d29c0:	e44a0168 */ 	swc1	$f10,0x168($v0)
/*  f0d29c4:	8ce90014 */ 	lw	$t1,0x14($a3)
.L0f0d29c8:
/*  f0d29c8:	51200019 */ 	beqzl	$t1,.L0f0d2a30
/*  f0d29cc:	e4500168 */ 	swc1	$f16,0x168($v0)
/*  f0d29d0:	8cea00a4 */ 	lw	$t2,0xa4($a3)
/*  f0d29d4:	3c01428c */ 	lui	$at,0x428c
/*  f0d29d8:	44814000 */ 	mtc1	$at,$f8
/*  f0d29dc:	448a2000 */ 	mtc1	$t2,$f4
/*  f0d29e0:	00000000 */ 	nop
/*  f0d29e4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d29e8:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0d29ec:	e44a0168 */ 	swc1	$f10,0x168($v0)
/*  f0d29f0:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0d29f4:	c4400168 */ 	lwc1	$f0,0x168($v0)
/*  f0d29f8:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0d29fc:	00000000 */ 	nop
/*  f0d2a00:	45020005 */ 	bc1fl	.L0f0d2a18
/*  f0d2a04:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0d2a08:	e4520168 */ 	swc1	$f18,0x168($v0)
/*  f0d2a0c:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0d2a10:	c4400168 */ 	lwc1	$f0,0x168($v0)
/*  f0d2a14:	460e003c */ 	c.lt.s	$f0,$f14
.L0f0d2a18:
/*  f0d2a18:	00000000 */ 	nop
/*  f0d2a1c:	45020005 */ 	bc1fl	.L0f0d2a34
/*  f0d2a20:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f0d2a24:	10000002 */ 	b	.L0f0d2a30
/*  f0d2a28:	e44e0168 */ 	swc1	$f14,0x168($v0)
/*  f0d2a2c:	e4500168 */ 	swc1	$f16,0x168($v0)
.L0f0d2a30:
/*  f0d2a30:	8fa2005c */ 	lw	$v0,0x5c($sp)
.L0f0d2a34:
/*  f0d2a34:	3c017f1b */ 	lui	$at,%hi(var7f1adb64)
/*  f0d2a38:	c424db64 */ 	lwc1	$f4,%lo(var7f1adb64)($at)
/*  f0d2a3c:	c4400070 */ 	lwc1	$f0,0x70($v0)
/*  f0d2a40:	c44c00b8 */ 	lwc1	$f12,0xb8($v0)
/*  f0d2a44:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0d2a48:	46006307 */ 	neg.s	$f12,$f12
/*  f0d2a4c:	45000008 */ 	bc1f	.L0f0d2a70
/*  f0d2a50:	3c017f1b */ 	lui	$at,%hi(var7f1adb68)
/*  f0d2a54:	c428db68 */ 	lwc1	$f8,%lo(var7f1adb68)($at)
/*  f0d2a58:	46000187 */ 	neg.s	$f6,$f0
/*  f0d2a5c:	3c017f1b */ 	lui	$at,%hi(var7f1adb6c)
/*  f0d2a60:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0d2a64:	c422db6c */ 	lwc1	$f2,%lo(var7f1adb6c)($at)
/*  f0d2a68:	10000008 */ 	b	.L0f0d2a8c
/*  f0d2a6c:	460a6300 */ 	add.s	$f12,$f12,$f10
.L0f0d2a70:
/*  f0d2a70:	3c017f1b */ 	lui	$at,%hi(var7f1adb70)
/*  f0d2a74:	c422db70 */ 	lwc1	$f2,%lo(var7f1adb70)($at)
/*  f0d2a78:	3c017f1b */ 	lui	$at,%hi(var7f1adb74)
/*  f0d2a7c:	c426db74 */ 	lwc1	$f6,%lo(var7f1adb74)($at)
/*  f0d2a80:	46001101 */ 	sub.s	$f4,$f2,$f0
/*  f0d2a84:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d2a88:	46086300 */ 	add.s	$f12,$f12,$f8
.L0f0d2a8c:
/*  f0d2a8c:	4610603c */ 	c.lt.s	$f12,$f16
/*  f0d2a90:	00000000 */ 	nop
/*  f0d2a94:	45020004 */ 	bc1fl	.L0f0d2aa8
/*  f0d2a98:	460c103e */ 	c.le.s	$f2,$f12
/*  f0d2a9c:	10000006 */ 	b	.L0f0d2ab8
/*  f0d2aa0:	46026300 */ 	add.s	$f12,$f12,$f2
/*  f0d2aa4:	460c103e */ 	c.le.s	$f2,$f12
.L0f0d2aa8:
/*  f0d2aa8:	00000000 */ 	nop
/*  f0d2aac:	45020003 */ 	bc1fl	.L0f0d2abc
/*  f0d2ab0:	e7b00030 */ 	swc1	$f16,0x30($sp)
/*  f0d2ab4:	46026301 */ 	sub.s	$f12,$f12,$f2
.L0f0d2ab8:
/*  f0d2ab8:	e7b00030 */ 	swc1	$f16,0x30($sp)
.L0f0d2abc:
/*  f0d2abc:	0c0068f7 */ 	jal	sinf
/*  f0d2ac0:	e7ac003c */ 	swc1	$f12,0x3c($sp)
/*  f0d2ac4:	46000287 */ 	neg.s	$f10,$f0
/*  f0d2ac8:	c7ac003c */ 	lwc1	$f12,0x3c($sp)
/*  f0d2acc:	0c0068f4 */ 	jal	cosf
/*  f0d2ad0:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f0d2ad4:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0d2ad8:	27a40030 */ 	addiu	$a0,$sp,0x30
/*  f0d2adc:	0fc2d341 */ 	jal	func0f0b4d04
/*  f0d2ae0:	27a50028 */ 	addiu	$a1,$sp,0x28
/*  f0d2ae4:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f0d2ae8:	00000000 */ 	nop
/*  f0d2aec:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f0d2af0:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0d2af4:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*  f0d2af8:	c7a60024 */ 	lwc1	$f6,0x24($sp)
/*  f0d2afc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d2b00:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x284)
/*  f0d2b04:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f0d2b08:	44812000 */ 	mtc1	$at,$f4
/*  f0d2b0c:	3c013f40 */ 	lui	$at,0x3f40
/*  f0d2b10:	8d6ba244 */ 	lw	$t3,%lo(g_Vars+0x284)($t3)
/*  f0d2b14:	46021200 */ 	add.s	$f8,$f2,$f2
/*  f0d2b18:	46004283 */ 	div.s	$f10,$f8,$f0
/*  f0d2b1c:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0d2b20:	44815000 */ 	mtc1	$at,$f10
/*  f0d2b24:	46003207 */ 	neg.s	$f8,$f6
/*  f0d2b28:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0d2b2c:	e56401b8 */ 	swc1	$f4,0x1b8($t3)
/*  f0d2b30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0d2b34:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f0d2b38:	03e00008 */ 	jr	$ra
/*  f0d2b3c:	00000000 */ 	nop
);

// Mismatch due to stack placement.
// Need to declare another stack variable before sp3c to push sp3c onwards down,
// but this makes the stack allocation too big.
//void bbikeApplyMoveData(struct movedata *data)
//{
//	struct hoverbikeobj *bike = (struct hoverbikeobj *)g_Vars.currentplayer->hoverbike->obj;
//	s8 contnum = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
//
//	if ((optionsGetControlMode(g_Vars.currentplayerstats->mpindex) == CONTROLMODE_12
//				|| optionsGetControlMode(g_Vars.currentplayerstats->mpindex) == CONTROLMODE_14
//				|| optionsGetControlMode(g_Vars.currentplayerstats->mpindex) == CONTROLMODE_13
//				|| optionsGetControlMode(g_Vars.currentplayerstats->mpindex) == CONTROLMODE_11)
//			&& !coreIsPaused()) {
//		data->digitalstepleft = contCountButtonsOnSpecificSamples(0, contnum, L_JPAD | L_CBUTTONS);
//		data->digitalstepright = contCountButtonsOnSpecificSamples(0, contnum, R_JPAD | R_CBUTTONS);
//	}
//
//	// Forward/back
//	if (data->digitalstepforward) {
//		f32 value = 1.0f - g_Vars.currentplayer->speedforwards;
//
//		if (value > 0.1f * g_Vars.lvupdate240freal) {
//			value = 0.1f * g_Vars.lvupdate240freal;
//		}
//
//		g_Vars.currentplayer->speedforwards += value;
//	} else if (data->digitalstepback) {
//		f32 value = -1.0f - g_Vars.currentplayer->speedforwards;
//
//		if (value < -0.1f * g_Vars.lvupdate240freal) {
//			value = -0.1f * g_Vars.lvupdate240freal;
//		}
//
//		g_Vars.currentplayer->speedforwards += value;
//	} else if (data->canlookahead) {
//		g_Vars.currentplayer->speedforwards = data->analogwalk / 70.0f;
//
//		if (g_Vars.currentplayer->speedforwards > 1.0f) {
//			g_Vars.currentplayer->speedforwards = 1;
//		} else if (g_Vars.currentplayer->speedforwards < -1.0f) {
//			g_Vars.currentplayer->speedforwards = -1;
//		}
//	} else {
//		g_Vars.currentplayer->speedforwards = 0;
//	}
//
//	// Sideways
//	if (data->digitalstepleft) {
//		f32 value = -1.0f - g_Vars.currentplayer->speedsideways;
//
//		if (value < data->digitalstepleft * -0.1f) {
//			value = data->digitalstepleft * -0.1f;
//		}
//
//		g_Vars.currentplayer->speedsideways += value;
//	} else if (data->digitalstepright) {
//		f32 value = 1.0f - g_Vars.currentplayer->speedsideways;
//
//		if (value > data->digitalstepright * 0.1f) {
//			value = data->digitalstepright * 0.1f;
//		}
//
//		g_Vars.currentplayer->speedsideways += value;
//	} else if (data->unk14) {
//		g_Vars.currentplayer->speedsideways = data->analogstrafe / 70.0f;
//
//		if (g_Vars.currentplayer->speedsideways > 1.0f) {
//			g_Vars.currentplayer->speedsideways = 1.0f;
//		}
//
//		if (g_Vars.currentplayer->speedsideways < -1.0f) {
//			g_Vars.currentplayer->speedsideways = -1.0f;
//		}
//	} else {
//		g_Vars.currentplayer->speedsideways = 0;
//	}
//
//	{
//		f32 stack;
//		f32 sp3c;
//		struct coord sp30;
//		f32 sp28[2];
//
//		sp3c = -bike->exreal;
//
//		if (bike->hov.unk14 < M_PI) {
//			sp3c += -bike->hov.unk14 * 0.8f;
//		} else {
//			sp3c += (M_BADTAU - bike->hov.unk14) * 0.8f;
//		}
//
//		if (sp3c < 0) {
//			sp3c += M_BADTAU;
//		} else if (sp3c >= M_BADTAU) {
//			sp3c -= M_BADTAU;
//		}
//
//		sp30.x = 0;
//		sp30.y = -sinf(sp3c);
//		sp30.z = cosf(sp3c);
//
//		func0f0b4d04(&sp30, sp28);
//
//		g_Vars.currentplayer->gunextraaimy = -((sp28[1] - currentPlayerGetScreenTop()) * 2.0f / currentPlayerGetScreenHeight() - 1.0f) * 0.75f;
//	}
//}

void bbike0f0d2b40(struct defaultobj *bike, struct coord *arg1, f32 arg2, struct defaultobj *obstacle)
{
	struct coord sp9c;
	struct coord sp90;
	struct coord sp84 = {0, 0, 0};
	struct coord sp78;
	struct coord sp6c;
	struct coord sp60;
	struct coord sp54;

	func00024e4c(&sp78, &sp6c, 333, "bondbike.c");

	sp60.x = bike->prop->pos.x;
	sp60.y = bike->prop->pos.y;
	sp60.z = bike->prop->pos.z;

	sp54.x = obstacle->prop->pos.x - bike->prop->pos.x;
	sp54.y = obstacle->prop->pos.y - bike->prop->pos.y;
	sp54.z = obstacle->prop->pos.z - bike->prop->pos.z;

	func0f02e3dc(&sp78, &sp6c, &sp60, &sp54, &sp9c);

	sp90.x = arg1->f[0];
	sp90.y = 0;
	sp90.z = arg1->f[2];

	if (sp90.f[0] || sp90.f[2]) {
		guNormalize(&sp90.x, &sp90.y, &sp90.z);
	} else {
		sp90.z = 1;
	}

	if (arg1->x) {
		sp84.x += arg1->x / g_Vars.lvupdate240freal;
	}

	if (arg1->z) {
		sp84.z += arg1->z / g_Vars.lvupdate240freal;
	}

	func0f082e84(obstacle, &sp9c, &sp90, &sp84, false);

	if (arg2) {
		f32 xdiff = sp9c.x - bike->prop->pos.x;
		f32 zdiff = sp9c.z - bike->prop->pos.z;
		f32 somefloat = 0;
		struct coord sp3c = {0, 0, 0};

		f32 tmp = 1 / sqrtf(xdiff * xdiff + zdiff * zdiff);

		xdiff *= tmp;
		zdiff *= tmp;

		arg2 = arg2 / g_Vars.lvupdate240freal;

		sp3c.x += -zdiff * arg2 * 40;
		sp3c.z += xdiff * arg2 * 40;
		somefloat += arg2 * 0.1f;

		func0f082a1c(obstacle, &sp3c, somefloat, true, true);
	}
}

GLOBAL_ASM(
glabel bbikeCalculateNewPosition
.late_rodata
glabel var7f1adb7c
.word 0x40c907a9
.text
/*  f0d2e18:	27bdfec8 */ 	addiu	$sp,$sp,-312
/*  f0d2e1c:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f0d2e20:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f0d2e24:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f0d2e28:	8e230284 */ 	lw	$v1,0x284($s1)
/*  f0d2e2c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0d2e30:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0d2e34:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f0d2e38:	afa5013c */ 	sw	$a1,0x13c($sp)
/*  f0d2e3c:	afae0134 */ 	sw	$t6,0x134($sp)
/*  f0d2e40:	afa000d4 */ 	sw	$zero,0xd4($sp)
/*  f0d2e44:	8c621a6c */ 	lw	$v0,0x1a6c($v1)
/*  f0d2e48:	44800000 */ 	mtc1	$zero,$f0
/*  f0d2e4c:	00803025 */ 	or	$a2,$a0,$zero
/*  f0d2e50:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0d2e54:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f0d2e58:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d2e5c:	e7a40128 */ 	swc1	$f4,0x128($sp)
/*  f0d2e60:	8c6f1a6c */ 	lw	$t7,0x1a6c($v1)
/*  f0d2e64:	c5e6000c */ 	lwc1	$f6,0xc($t7)
/*  f0d2e68:	e7a6012c */ 	swc1	$f6,0x12c($sp)
/*  f0d2e6c:	8c781a6c */ 	lw	$t8,0x1a6c($v1)
/*  f0d2e70:	c7080010 */ 	lwc1	$f8,0x10($t8)
/*  f0d2e74:	e7a80130 */ 	swc1	$f8,0x130($sp)
/*  f0d2e78:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f0d2e7c:	460a0032 */ 	c.eq.s	$f0,$f10
/*  f0d2e80:	00000000 */ 	nop
/*  f0d2e84:	4502000c */ 	bc1fl	.L0f0d2eb8
/*  f0d2e88:	8c6400bc */ 	lw	$a0,0xbc($v1)
/*  f0d2e8c:	c4900004 */ 	lwc1	$f16,0x4($a0)
/*  f0d2e90:	46100032 */ 	c.eq.s	$f0,$f16
/*  f0d2e94:	00000000 */ 	nop
/*  f0d2e98:	45020007 */ 	bc1fl	.L0f0d2eb8
/*  f0d2e9c:	8c6400bc */ 	lw	$a0,0xbc($v1)
/*  f0d2ea0:	c4920008 */ 	lwc1	$f18,0x8($a0)
/*  f0d2ea4:	46120032 */ 	c.eq.s	$f0,$f18
/*  f0d2ea8:	00000000 */ 	nop
/*  f0d2eac:	450300a6 */ 	bc1tl	.L0f0d3148
/*  f0d2eb0:	c7a4013c */ 	lwc1	$f4,0x13c($sp)
/*  f0d2eb4:	8c6400bc */ 	lw	$a0,0xbc($v1)
.L0f0d2eb8:
/*  f0d2eb8:	0fc1905e */ 	jal	propSetCollisionsEnabled
/*  f0d2ebc:	afa60138 */ 	sw	$a2,0x138($sp)
/*  f0d2ec0:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0d2ec4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d2ec8:	0fc1905e */ 	jal	propSetCollisionsEnabled
/*  f0d2ecc:	8f241a6c */ 	lw	$a0,0x1a6c($t9)
/*  f0d2ed0:	8fa20138 */ 	lw	$v0,0x138($sp)
/*  f0d2ed4:	c7a40128 */ 	lwc1	$f4,0x128($sp)
/*  f0d2ed8:	c7aa0130 */ 	lwc1	$f10,0x130($sp)
/*  f0d2edc:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f0d2ee0:	8e280284 */ 	lw	$t0,0x284($s1)
/*  f0d2ee4:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0d2ee8:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0d2eec:	27a6009c */ 	addiu	$a2,$sp,0x9c
/*  f0d2ef0:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f0d2ef4:	e7a80128 */ 	swc1	$f8,0x128($sp)
/*  f0d2ef8:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f0d2efc:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f0d2f00:	e7b20130 */ 	swc1	$f18,0x130($sp)
/*  f0d2f04:	0fc21d5b */ 	jal	propObjGetBbox
/*  f0d2f08:	8d041a6c */ 	lw	$a0,0x1a6c($t0)
/*  f0d2f0c:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f0d2f10:	27aa00a8 */ 	addiu	$t2,$sp,0xa8
/*  f0d2f14:	240b0014 */ 	addiu	$t3,$zero,0x14
/*  f0d2f18:	8d221a6c */ 	lw	$v0,0x1a6c($t1)
/*  f0d2f1c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0d2f20:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0d2f24:	27a60128 */ 	addiu	$a2,$sp,0x128
/*  f0d2f28:	27a70118 */ 	addiu	$a3,$sp,0x118
/*  f0d2f2c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0d2f30:	0fc1977f */ 	jal	func0f065dfc
/*  f0d2f34:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0d2f38:	2606001c */ 	addiu	$a2,$s0,0x1c
/*  f0d2f3c:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0d2f40:	02002025 */ 	or	$a0,$s0,$zero
/*  f0d2f44:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0d2f48:	0fc248cf */ 	jal	func0f09233c
/*  f0d2f4c:	27a70118 */ 	addiu	$a3,$sp,0x118
/*  f0d2f50:	27a500d8 */ 	addiu	$a1,$sp,0xd8
/*  f0d2f54:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0d2f58:	afac00d4 */ 	sw	$t4,0xd4($sp)
/*  f0d2f5c:	00a0c825 */ 	or	$t9,$a1,$zero
/*  f0d2f60:	0200c025 */ 	or	$t8,$s0,$zero
/*  f0d2f64:	260f003c */ 	addiu	$t7,$s0,0x3c
.L0f0d2f68:
/*  f0d2f68:	8f01005c */ 	lw	$at,0x5c($t8)
/*  f0d2f6c:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f0d2f70:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f0d2f74:	af21fff4 */ 	sw	$at,-0xc($t9)
/*  f0d2f78:	8f010054 */ 	lw	$at,0x54($t8)
/*  f0d2f7c:	af21fff8 */ 	sw	$at,-0x8($t9)
/*  f0d2f80:	8f010058 */ 	lw	$at,0x58($t8)
/*  f0d2f84:	170ffff8 */ 	bne	$t8,$t7,.L0f0d2f68
/*  f0d2f88:	af21fffc */ 	sw	$at,-0x4($t9)
/*  f0d2f8c:	8f01005c */ 	lw	$at,0x5c($t8)
/*  f0d2f90:	02002025 */ 	or	$a0,$s0,$zero
/*  f0d2f94:	27a60128 */ 	addiu	$a2,$sp,0x128
/*  f0d2f98:	af210000 */ 	sw	$at,0x0($t9)
/*  f0d2f9c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f0d2fa0:	27a70118 */ 	addiu	$a3,$sp,0x118
/*  f0d2fa4:	0fc1c4f9 */ 	jal	func0f0713e4
/*  f0d2fa8:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0d2fac:	c7a4010c */ 	lwc1	$f4,0x10c($sp)
/*  f0d2fb0:	c6060090 */ 	lwc1	$f6,0x90($s0)
/*  f0d2fb4:	c7aa012c */ 	lwc1	$f10,0x12c($sp)
/*  f0d2fb8:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f0d2fbc:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0d2fc0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d2fc4:	c7b20128 */ 	lwc1	$f18,0x128($sp)
/*  f0d2fc8:	c7a60130 */ 	lwc1	$f6,0x130($sp)
/*  f0d2fcc:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f0d2fd0:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f0d2fd4:	240a003f */ 	addiu	$t2,$zero,0x3f
/*  f0d2fd8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0d2fdc:	e7b0012c */ 	swc1	$f16,0x12c($sp)
/*  f0d2fe0:	44818000 */ 	mtc1	$at,$f16
/*  f0d2fe4:	8d221a6c */ 	lw	$v0,0x1a6c($t1)
/*  f0d2fe8:	46104002 */ 	mul.s	$f0,$f8,$f16
/*  f0d2fec:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0d2ff0:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f0d2ff4:	46049081 */ 	sub.s	$f2,$f18,$f4
/*  f0d2ff8:	c7b20094 */ 	lwc1	$f18,0x94($sp)
/*  f0d2ffc:	460a3301 */ 	sub.s	$f12,$f6,$f10
/*  f0d3000:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0d3004:	00000000 */ 	nop
/*  f0d3008:	45030010 */ 	bc1tl	.L0f0d304c
/*  f0d300c:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0d3010:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0d3014:	00000000 */ 	nop
/*  f0d3018:	4503000c */ 	bc1tl	.L0f0d304c
/*  f0d301c:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0d3020:	46000387 */ 	neg.s	$f14,$f0
/*  f0d3024:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0d3028:	00000000 */ 	nop
/*  f0d302c:	45030007 */ 	bc1tl	.L0f0d304c
/*  f0d3030:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0d3034:	460e603c */ 	c.lt.s	$f12,$f14
/*  f0d3038:	240f003f */ 	addiu	$t7,$zero,0x3f
/*  f0d303c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d3040:	45020028 */ 	bc1fl	.L0f0d30e4
/*  f0d3044:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d3048:	e7b20010 */ 	swc1	$f18,0x10($sp)
.L0f0d304c:
/*  f0d304c:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0d3050:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0d3054:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0d3058:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f0d305c:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f0d3060:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0d3064:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0d3068:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0d306c:	27a60128 */ 	addiu	$a2,$sp,0x128
/*  f0d3070:	46005201 */ 	sub.s	$f8,$f10,$f0
/*  f0d3074:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0d3078:	27a70118 */ 	addiu	$a3,$sp,0x118
/*  f0d307c:	0c00b657 */ 	jal	cdTestAToB3
/*  f0d3080:	e7a80020 */ 	swc1	$f8,0x20($sp)
/*  f0d3084:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0d3088:	14410024 */ 	bne	$v0,$at,.L0f0d311c
/*  f0d308c:	afa20134 */ 	sw	$v0,0x134($sp)
/*  f0d3090:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f0d3094:	240e003f */ 	addiu	$t6,$zero,0x3f
/*  f0d3098:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0d309c:	8d821a6c */ 	lw	$v0,0x1a6c($t4)
/*  f0d30a0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0d30a4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0d30a8:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0d30ac:	c7b0009c */ 	lwc1	$f16,0x9c($sp)
/*  f0d30b0:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f0d30b4:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0d30b8:	46008481 */ 	sub.s	$f18,$f16,$f0
/*  f0d30bc:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f0d30c0:	27a70118 */ 	addiu	$a3,$sp,0x118
/*  f0d30c4:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0d30c8:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f0d30cc:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0d30d0:	0c00aa7c */ 	jal	cdTestAToB1
/*  f0d30d4:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0d30d8:	10000010 */ 	b	.L0f0d311c
/*  f0d30dc:	afa20134 */ 	sw	$v0,0x134($sp)
/*  f0d30e0:	afaf0010 */ 	sw	$t7,0x10($sp)
.L0f0d30e4:
/*  f0d30e4:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0d30e8:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0d30ec:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f0d30f0:	c7b00098 */ 	lwc1	$f16,0x98($sp)
/*  f0d30f4:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0d30f8:	46005201 */ 	sub.s	$f8,$f10,$f0
/*  f0d30fc:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0d3100:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f0d3104:	46008481 */ 	sub.s	$f18,$f16,$f0
/*  f0d3108:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*  f0d310c:	27a700a8 */ 	addiu	$a3,$sp,0xa8
/*  f0d3110:	0c00aa7c */ 	jal	cdTestAToB1
/*  f0d3114:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f0d3118:	afa20134 */ 	sw	$v0,0x134($sp)
.L0f0d311c:
/*  f0d311c:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0d3120:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0d3124:	0fc1905e */ 	jal	propSetCollisionsEnabled
/*  f0d3128:	8f2400bc */ 	lw	$a0,0xbc($t9)
/*  f0d312c:	8e280284 */ 	lw	$t0,0x284($s1)
/*  f0d3130:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0d3134:	0fc1905e */ 	jal	propSetCollisionsEnabled
/*  f0d3138:	8d041a6c */ 	lw	$a0,0x1a6c($t0)
/*  f0d313c:	44800000 */ 	mtc1	$zero,$f0
/*  f0d3140:	00000000 */ 	nop
/*  f0d3144:	c7a4013c */ 	lwc1	$f4,0x13c($sp)
.L0f0d3148:
/*  f0d3148:	02002025 */ 	or	$a0,$s0,$zero
/*  f0d314c:	2609001c */ 	addiu	$t1,$s0,0x1c
/*  f0d3150:	46002032 */ 	c.eq.s	$f4,$f0
/*  f0d3154:	00000000 */ 	nop
/*  f0d3158:	45030023 */ 	bc1tl	.L0f0d31e8
/*  f0d315c:	8fab0134 */ 	lw	$t3,0x134($sp)
/*  f0d3160:	0fc1c836 */ 	jal	hoverpropGetTurnAngle
/*  f0d3164:	afa90040 */ 	sw	$t1,0x40($sp)
/*  f0d3168:	c7a6013c */ 	lwc1	$f6,0x13c($sp)
/*  f0d316c:	3c017f1b */ 	lui	$at,%hi(var7f1adb7c)
/*  f0d3170:	c42edb7c */ 	lwc1	$f14,%lo(var7f1adb7c)($at)
/*  f0d3174:	46060081 */ 	sub.s	$f2,$f0,$f6
/*  f0d3178:	02002025 */ 	or	$a0,$s0,$zero
/*  f0d317c:	4602703e */ 	c.le.s	$f14,$f2
/*  f0d3180:	46001306 */ 	mov.s	$f12,$f2
/*  f0d3184:	45020004 */ 	bc1fl	.L0f0d3198
/*  f0d3188:	44805000 */ 	mtc1	$zero,$f10
/*  f0d318c:	10000008 */ 	b	.L0f0d31b0
/*  f0d3190:	460e1301 */ 	sub.s	$f12,$f2,$f14
/*  f0d3194:	44805000 */ 	mtc1	$zero,$f10
.L0f0d3198:
/*  f0d3198:	00000000 */ 	nop
/*  f0d319c:	460a103c */ 	c.lt.s	$f2,$f10
/*  f0d31a0:	00000000 */ 	nop
/*  f0d31a4:	45020003 */ 	bc1fl	.L0f0d31b4
/*  f0d31a8:	44056000 */ 	mfc1	$a1,$f12
/*  f0d31ac:	460e1300 */ 	add.s	$f12,$f2,$f14
.L0f0d31b0:
/*  f0d31b0:	44056000 */ 	mfc1	$a1,$f12
.L0f0d31b4:
/*  f0d31b4:	0fc1c844 */ 	jal	hoverpropSetTurnAngle
/*  f0d31b8:	e7ac0084 */ 	swc1	$f12,0x84($sp)
/*  f0d31bc:	c7ac0084 */ 	lwc1	$f12,0x84($sp)
/*  f0d31c0:	0c0058dd */ 	jal	func00016374
/*  f0d31c4:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0d31c8:	8e0a0018 */ 	lw	$t2,0x18($s0)
/*  f0d31cc:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0d31d0:	0c0057c1 */ 	jal	func00015f04
/*  f0d31d4:	c54c0014 */ 	lwc1	$f12,0x14($t2)
/*  f0d31d8:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f0d31dc:	0c005768 */ 	jal	func00015da0
/*  f0d31e0:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0d31e4:	8fab0134 */ 	lw	$t3,0x134($sp)
.L0f0d31e8:
/*  f0d31e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0d31ec:	8fac00d4 */ 	lw	$t4,0xd4($sp)
/*  f0d31f0:	55610024 */ 	bnel	$t3,$at,.L0f0d3284
/*  f0d31f4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0d31f8:	51800022 */ 	beqzl	$t4,.L0f0d3284
/*  f0d31fc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0d3200:	8e2e0284 */ 	lw	$t6,0x284($s1)
/*  f0d3204:	c7a80128 */ 	lwc1	$f8,0x128($sp)
/*  f0d3208:	2608005c */ 	addiu	$t0,$s0,0x5c
/*  f0d320c:	8dcd1a6c */ 	lw	$t5,0x1a6c($t6)
/*  f0d3210:	e5a80008 */ 	swc1	$f8,0x8($t5)
/*  f0d3214:	8e2f0284 */ 	lw	$t7,0x284($s1)
/*  f0d3218:	c7b00130 */ 	lwc1	$f16,0x130($sp)
/*  f0d321c:	8df81a6c */ 	lw	$t8,0x1a6c($t7)
/*  f0d3220:	e7100010 */ 	swc1	$f16,0x10($t8)
/*  f0d3224:	8e390284 */ 	lw	$t9,0x284($s1)
/*  f0d3228:	8f241a6c */ 	lw	$a0,0x1a6c($t9)
/*  f0d322c:	0fc19711 */ 	jal	func0f065c44
/*  f0d3230:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f0d3234:	8e290284 */ 	lw	$t1,0x284($s1)
/*  f0d3238:	27a40118 */ 	addiu	$a0,$sp,0x118
/*  f0d323c:	8d251a6c */ 	lw	$a1,0x1a6c($t1)
/*  f0d3240:	0fc195e9 */ 	jal	roomsCopy
/*  f0d3244:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0d3248:	27ab00d8 */ 	addiu	$t3,$sp,0xd8
/*  f0d324c:	256d003c */ 	addiu	$t5,$t3,0x3c
/*  f0d3250:	8faa0040 */ 	lw	$t2,0x40($sp)
.L0f0d3254:
/*  f0d3254:	8d610000 */ 	lw	$at,0x0($t3)
/*  f0d3258:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f0d325c:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f0d3260:	ad41fff4 */ 	sw	$at,-0xc($t2)
/*  f0d3264:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f0d3268:	ad41fff8 */ 	sw	$at,-0x8($t2)
/*  f0d326c:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f0d3270:	156dfff8 */ 	bne	$t3,$t5,.L0f0d3254
/*  f0d3274:	ad41fffc */ 	sw	$at,-0x4($t2)
/*  f0d3278:	8d610000 */ 	lw	$at,0x0($t3)
/*  f0d327c:	ad410000 */ 	sw	$at,0x0($t2)
/*  f0d3280:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0d3284:
/*  f0d3284:	8fa20134 */ 	lw	$v0,0x134($sp)
/*  f0d3288:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f0d328c:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f0d3290:	03e00008 */ 	jr	$ra
/*  f0d3294:	27bd0138 */ 	addiu	$sp,$sp,0x138
);

s32 bbikeCalculateNewPositionWithPush(struct coord *arg0, f32 arg1)
{
	s32 result = bbikeCalculateNewPosition(arg0, arg1);

	if (result != CDRESULT_NOCOLLISION) {
		struct prop *obstacle = cdGetObstacle();

		if (obstacle && g_Vars.lvupdate240 > 0) {
			if (obstacle->type == PROPTYPE_CHR) {
				// empty
			} else if (obstacle->type == PROPTYPE_PLAYER) {
				// empty
			} else if (obstacle->type == PROPTYPE_OBJ) {
				struct defaultobj *obj = obstacle->obj;

				if ((obj->hidden & OBJHFLAG_04000000) == 0
						&& (obj->hidden & OBJHFLAG_GRABBED) == 0
						&& (obj->flags3 & OBJFLAG3_PUSHABLE)) {
					bool pass = true;
					struct defaultobj *bike = g_Vars.currentplayer->hoverbike->obj;

					if ((obj->hidden & OBJHFLAG_AIRBORNE)
							&& (obj->projectile->flags & PROJECTILEFLAG_00001000)) {
						pass = false;
					}

					if (pass) {
						bbike0f0d2b40(bike, arg0, arg1, obj);

						if ((obj->hidden & OBJHFLAG_AIRBORNE)
								&& (obj->projectile->flags & PROJECTILEFLAG_00000800)) {
							s32 somevalue;
							bool somebool = false;
							somevalue = func0f073c6c(obj, &somebool);

							if (obj->hidden & OBJHFLAG_AIRBORNE) {
								obj->projectile->flags |= PROJECTILEFLAG_00001000;

								if (somevalue) {
									obj->projectile->flags |= PROJECTILEFLAG_00002000;
								} else {
									obj->projectile->flags &= ~PROJECTILEFLAG_00002000;
								}
							}

							if (somevalue) {
								result = bbikeCalculateNewPosition(arg0, arg1);
							}
						}
					}
				}
			}
		}
	}

	return result;
}

void bbikeUpdateVertical(struct coord *arg0)
{
	struct defaultobj *bike = g_Vars.currentplayer->hoverbike->obj;
	f32 angle;
	s16 newrooms[8];
	bool newinlift;
	struct prop *lift = NULL;
	f32 ground;

	angle = hoverpropGetTurnAngle(bike);

	func0f065e74(&bike->prop->pos, bike->prop->rooms, arg0, newrooms);
	bmove0f0cb79c(g_Vars.currentplayer, arg0, newrooms);
	func0f065c44(g_Vars.currentplayer->prop);
	roomsCopy(newrooms, g_Vars.currentplayer->prop->rooms);

	g_Vars.currentplayer->vv_theta = (M_BADTAU - angle) * 360.0f / M_BADTAU;

	g_Vars.currentplayer->prop->pos.x = arg0->x;
	g_Vars.currentplayer->prop->pos.y = arg0->y;
	g_Vars.currentplayer->prop->pos.z = arg0->z;

	ground = cdFindGroundY(&g_Vars.currentplayer->prop->pos,
			g_Vars.currentplayer->bond2.width,
			g_Vars.currentplayer->prop->rooms,
			&g_Vars.currentplayer->floorcol,
			&g_Vars.currentplayer->floortype,
			&g_Vars.currentplayer->floorflags,
			&g_Vars.currentplayer->floorroom,
			&newinlift, &lift);

	if (ground < -30000) {
		ground = -30000;
	}

	if (g_Vars.currentplayer->inlift && newinlift) {
		f32 diff = ground - g_Vars.currentplayer->vv_ground;

		// If getting on the bike
		if (g_Vars.currentplayer->bondvehiclemode == VEHICLEMODE_OFF) {
			g_Vars.currentplayer->bondenterpos.y += diff;
		}
	} else {
		lift = NULL;
	}

	g_Vars.currentplayer->inlift = newinlift;

	if (newinlift) {
		g_Vars.currentplayer->liftground = ground;
	}

	g_Vars.currentplayer->lift = lift;
	g_Vars.currentplayer->vv_ground = ground;
	g_Vars.currentplayer->vv_height = g_Vars.currentplayer->headpos.y / g_Vars.currentplayer->standheight * g_Vars.currentplayer->vv_eyeheight;
	g_Vars.currentplayer->vv_manground = g_Vars.currentplayer->prop->pos.y - g_Vars.currentplayer->vv_height;

	if (g_Vars.currentplayer->floorflags & FLOORFLAG_DIE) {
		currentPlayerDie(true);
	}

	bmoveUpdateVerta();
}

s32 bbike0f0d363c(f32 arg0)
{
	struct coord coord = {0, 0, 0};

	return bbikeCalculateNewPositionWithPush(&coord, arg0);
}

s32 bbike0f0d3680(struct coord *arg0, struct coord *arg1, struct coord *arg2)
{
	s32 result = bbikeCalculateNewPositionWithPush(arg0, 0);

	if (!result) {
		func00024e4c(arg1, arg2, 659, "bondbike.c");
	}

	return result;
}

s32 bbike0f0d36d4(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4)
{
	if (func00024ea4()) {
		struct coord sp24;
		f32 somefloat = func00024e98();
		s32 someint;

		sp24.x = arg0->x * somefloat * 0.25f;
		sp24.y = arg0->y * somefloat * 0.25f;
		sp24.z = arg0->z * somefloat * 0.25f;

		someint = bbikeCalculateNewPositionWithPush(&sp24, 0);

		if (someint == 1) {
			return 1;
		}

		if (someint == 0) {
			func00024e4c(arg3, arg4, 685, "bondbike.c");

			if (arg3->f[0] != arg1->f[0]
					|| arg3->f[1] != arg1->f[1]
					|| arg3->f[2] != arg1->f[2]
					|| arg4->f[0] != arg2->f[0]
					|| arg4->f[1] != arg2->f[1]
					|| arg4->f[2] != arg2->f[2]) {
				return 0;
			}
		}
	}

	return -1;
}

s32 bbike0f0d3840(struct coord *arg0, struct coord *arg1, struct coord *arg2)
{
	s32 result;

	if (arg1->f[0] != arg2->f[0] || arg1->f[2] != arg2->f[2]) {
		struct coord sp30;
		struct coord sp24;
		f32 tmp;

		sp30.x = arg2->x - arg1->x;
		sp30.z = arg2->z - arg1->z;

		tmp = sqrtf(sp30.f[0] * sp30.f[0] + sp30.f[2] * sp30.f[2]);

		sp30.x *= 1.0f / tmp;
		sp30.z *= 1.0f / tmp;

		tmp = arg0->f[0] * sp30.f[0] + arg0->f[2] * sp30.f[2];

		sp24.x = sp30.x * tmp;
		sp24.y = 0;
		sp24.z = sp30.z * tmp;

		result = bbikeCalculateNewPositionWithPush(&sp24, 0);
	} else {
		result = -1;
	}

	return result;
}

s32 bbike0f0d3940(struct coord *arg0, struct coord *arg1, struct coord *arg2)
{
	struct coord sp34;
	struct coord sp28;
	f32 ymax;
	f32 ymin;
	f32 tmp;
	f32 width;

	propObjGetBbox(g_Vars.currentplayer->hoverbike, &width, &ymax, &ymin);

	sp34.x = arg1->x - (g_Vars.currentplayer->hoverbike->pos.x + arg0->f[0]);
	sp34.z = arg1->z - (g_Vars.currentplayer->hoverbike->pos.z + arg0->f[2]);

	if (sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2] <= width * width) {
		if (arg1->f[0] != g_Vars.currentplayer->hoverbike->pos.f[0] || arg1->f[2] != g_Vars.currentplayer->hoverbike->pos.f[2]) {
			sp34.x = -(arg1->z - g_Vars.currentplayer->hoverbike->pos.z);
			sp34.y = 0;
			sp34.z = arg1->x - g_Vars.currentplayer->hoverbike->pos.x;

			tmp = sqrtf(sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2]);

			sp34.x = sp34.f[0] * (1.0f / tmp);
			sp34.z = sp34.f[2] * (1.0f / tmp);

			tmp = arg0->f[0] * sp34.f[0] + arg0->f[2] * sp34.f[2];

			sp34.x = sp34.x * tmp;
			sp34.z = sp34.z * tmp;

			sp28.x = sp34.x;
			sp28.y = 0;
			sp28.z = sp34.z;

			if (bbikeCalculateNewPositionWithPush(&sp28, 0) == CDRESULT_NOCOLLISION) {
				return true;
			}
		}
	} else {
		sp34.x = arg2->x - (g_Vars.currentplayer->hoverbike->pos.x + arg0->f[0]);
		sp34.z = arg2->z - (g_Vars.currentplayer->hoverbike->pos.z + arg0->f[2]);

		if (sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2] <= width * width) {
			if (arg2->f[0] != g_Vars.currentplayer->hoverbike->pos.f[0] || arg2->f[2] != g_Vars.currentplayer->hoverbike->pos.f[2]) {
				sp34.x = -(arg2->z - g_Vars.currentplayer->hoverbike->pos.z);
				sp34.y = 0;
				sp34.z = arg2->x - g_Vars.currentplayer->hoverbike->pos.x;

				tmp = sqrtf(sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2]);

				sp34.x = sp34.f[0] * (1.0f / tmp);
				sp34.z = sp34.f[2] * (1.0f / tmp);

				tmp = arg0->f[0] * sp34.f[0] + arg0->f[2] * sp34.f[2];

				sp34.x = sp34.x * tmp;
				sp34.z = sp34.z * tmp;

				sp28.x = sp34.x;
				sp28.y = 0;
				sp28.z = sp34.z;

				if (bbikeCalculateNewPositionWithPush(&sp28, 0) == CDRESULT_NOCOLLISION) {
					return true;
				}
			}
		}
	}

	return false;
}

GLOBAL_ASM(
glabel bbike0f0d3c60
/*  f0d3c60:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f0d3c64:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0d3c68:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f0d3c6c:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0d3c70:	0fc34da0 */ 	jal	bbike0f0d3680
/*  f0d3c74:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0d3c78:	14400031 */ 	bnez	$v0,.L0f0d3d40
/*  f0d3c7c:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0d3c80:	27ae0040 */ 	addiu	$t6,$sp,0x40
/*  f0d3c84:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0d3c88:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0d3c8c:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0d3c90:	0fc34db5 */ 	jal	bbike0f0d36d4
/*  f0d3c94:	27a7004c */ 	addiu	$a3,$sp,0x4c
/*  f0d3c98:	1c400002 */ 	bgtz	$v0,.L0f0d3ca4
/*  f0d3c9c:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0d3ca0:	0441000c */ 	bgez	$v0,.L0f0d3cd4
.L0f0d3ca4:
/*  f0d3ca4:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0d3ca8:	0fc34e10 */ 	jal	bbike0f0d3840
/*  f0d3cac:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0d3cb0:	1c400023 */ 	bgtz	$v0,.L0f0d3d40
/*  f0d3cb4:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0d3cb8:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0d3cbc:	0fc34e50 */ 	jal	bbike0f0d3940
/*  f0d3cc0:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0d3cc4:	5c40001f */ 	bgtzl	$v0,.L0f0d3d44
/*  f0d3cc8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0d3ccc:	1000001d */ 	b	.L0f0d3d44
/*  f0d3cd0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0d3cd4:
/*  f0d3cd4:	1440001a */ 	bnez	$v0,.L0f0d3d40
/*  f0d3cd8:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0d3cdc:	27af0024 */ 	addiu	$t7,$sp,0x24
/*  f0d3ce0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d3ce4:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0d3ce8:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0d3cec:	0fc34db5 */ 	jal	bbike0f0d36d4
/*  f0d3cf0:	27a70030 */ 	addiu	$a3,$sp,0x30
/*  f0d3cf4:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0d3cf8:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0d3cfc:	0fc34e10 */ 	jal	bbike0f0d3840
/*  f0d3d00:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0d3d04:	1c40000e */ 	bgtz	$v0,.L0f0d3d40
/*  f0d3d08:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0d3d0c:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0d3d10:	0fc34e10 */ 	jal	bbike0f0d3840
/*  f0d3d14:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0d3d18:	1c400009 */ 	bgtz	$v0,.L0f0d3d40
/*  f0d3d1c:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0d3d20:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0d3d24:	0fc34e50 */ 	jal	bbike0f0d3940
/*  f0d3d28:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0d3d2c:	1c400004 */ 	bgtz	$v0,.L0f0d3d40
/*  f0d3d30:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0d3d34:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0d3d38:	0fc34e50 */ 	jal	bbike0f0d3940
/*  f0d3d3c:	27a60058 */ 	addiu	$a2,$sp,0x58
.L0f0d3d40:
/*  f0d3d40:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0d3d44:
/*  f0d3d44:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f0d3d48:	03e00008 */ 	jr	$ra
/*  f0d3d4c:	00000000 */ 	nop
);

// Mismatch because the below copies arg0 into s0 but goal uses sp.
//void bbike0f0d3c60(struct coord *arg0)
//{
//	struct coord sp100;
//	struct coord sp88;
//	struct coord sp76;
//	struct coord sp64;
//	s32 lVar1;
//	struct coord sp48;
//	struct coord sp36;
//
//	if (bbike0f0d3680(arg0, &sp100, &sp88) == 0) {
//		lVar1 = bbike0f0d36d4(arg0, &sp100, &sp88, &sp76, &sp64);
//
//		if (lVar1 > 0 || lVar1 < 0) {
//			if (bbike0f0d3840(arg0, &sp100, &sp88) < 1
//					&& bbike0f0d3940(arg0, &sp100, &sp88) < 1) {
//				// empty
//			}
//		} else if (lVar1 == 0) {
//			bbike0f0d36d4(arg0, &sp76, &sp64, &sp48, &sp36);
//
//			if (bbike0f0d3840(arg0, &sp76, &sp64) < 1
//					&& bbike0f0d3840(arg0, &sp100, &sp88) < 1
//					&& bbike0f0d3940(arg0, &sp76, &sp64) < 1) {
//				bbike0f0d3940(arg0, &sp100, &sp88);
//			}
//		}
//	}
//}

GLOBAL_ASM(
glabel bbikeTick
.late_rodata
glabel var7f1adb88
.word 0x4528c000
glabel var7f1adb8c
.word 0x3b23d70a
glabel var7f1adb90
.word 0x3c8ef461
glabel var7f1adb94
.word 0x40c907a9
glabel var7f1adb98
.word 0x3f333333
glabel var7f1adb9c
.word 0x3c8ef461
.text
/*  f0d3d50:	27bdfde0 */ 	addiu	$sp,$sp,-544
/*  f0d3d54:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f0d3d58:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0d3d5c:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0d3d60:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d3d64:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0d3d68:	8e0f0034 */ 	lw	$t7,0x34($s0)
/*  f0d3d6c:	8d0e1a6c */ 	lw	$t6,0x1a6c($t0)
/*  f0d3d70:	8dc40004 */ 	lw	$a0,0x4($t6)
/*  f0d3d74:	19e000f8 */ 	blez	$t7,.L0f0d4158
/*  f0d3d78:	afa4021c */ 	sw	$a0,0x21c($sp)
/*  f0d3d7c:	8d1800bc */ 	lw	$t8,0xbc($t0)
/*  f0d3d80:	3c013f40 */ 	lui	$at,0x3f40
/*  f0d3d84:	44815000 */ 	mtc1	$at,$f10
/*  f0d3d88:	c7040008 */ 	lwc1	$f4,0x8($t8)
/*  f0d3d8c:	3c017f1b */ 	lui	$at,%hi(var7f1adb88)
/*  f0d3d90:	44800000 */ 	mtc1	$zero,$f0
/*  f0d3d94:	e5040310 */ 	swc1	$f4,0x310($t0)
/*  f0d3d98:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d3d9c:	8d1900bc */ 	lw	$t9,0xbc($t0)
/*  f0d3da0:	c726000c */ 	lwc1	$f6,0xc($t9)
/*  f0d3da4:	e5060314 */ 	swc1	$f6,0x314($t0)
/*  f0d3da8:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d3dac:	8d0900bc */ 	lw	$t1,0xbc($t0)
/*  f0d3db0:	c5280010 */ 	lwc1	$f8,0x10($t1)
/*  f0d3db4:	e5080318 */ 	swc1	$f8,0x318($t0)
/*  f0d3db8:	c604004c */ 	lwc1	$f4,0x4c($s0)
/*  f0d3dbc:	c428db88 */ 	lwc1	$f8,%lo(var7f1adb88)($at)
/*  f0d3dc0:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d3dc4:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0d3dc8:	c5040198 */ 	lwc1	$f4,0x198($t0)
/*  f0d3dcc:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0d3dd0:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0d3dd4:	e5060198 */ 	swc1	$f6,0x198($t0)
/*  f0d3dd8:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d3ddc:	c5080198 */ 	lwc1	$f8,0x198($t0)
/*  f0d3de0:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0d3de4:	00000000 */ 	nop
/*  f0d3de8:	45020004 */ 	bc1fl	.L0f0d3dfc
/*  f0d3dec:	8d021a7c */ 	lw	$v0,0x1a7c($t0)
/*  f0d3df0:	e5000198 */ 	swc1	$f0,0x198($t0)
/*  f0d3df4:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d3df8:	8d021a7c */ 	lw	$v0,0x1a7c($t0)
.L0f0d3dfc:
/*  f0d3dfc:	54400009 */ 	bnezl	$v0,.L0f0d3e24
/*  f0d3e00:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0d3e04:	8d050170 */ 	lw	$a1,0x170($t0)
/*  f0d3e08:	8d060168 */ 	lw	$a2,0x168($t0)
/*  f0d3e0c:	8d070148 */ 	lw	$a3,0x148($t0)
/*  f0d3e10:	0fc1cab7 */ 	jal	func0f072adc
/*  f0d3e14:	afa40218 */ 	sw	$a0,0x218($sp)
/*  f0d3e18:	1000000c */ 	b	.L0f0d3e4c
/*  f0d3e1c:	8fa70218 */ 	lw	$a3,0x218($sp)
/*  f0d3e20:	24010001 */ 	addiu	$at,$zero,0x1
.L0f0d3e24:
/*  f0d3e24:	14410003 */ 	bne	$v0,$at,.L0f0d3e34
/*  f0d3e28:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f0d3e2c:	ad0a1a7c */ 	sw	$t2,0x1a7c($t0)
/*  f0d3e30:	8e080284 */ 	lw	$t0,0x284($s0)
.L0f0d3e34:
/*  f0d3e34:	8d050170 */ 	lw	$a1,0x170($t0)
/*  f0d3e38:	8d060168 */ 	lw	$a2,0x168($t0)
/*  f0d3e3c:	8d070148 */ 	lw	$a3,0x148($t0)
/*  f0d3e40:	0fc1cab7 */ 	jal	func0f072adc
/*  f0d3e44:	afa40218 */ 	sw	$a0,0x218($sp)
/*  f0d3e48:	8fa70218 */ 	lw	$a3,0x218($sp)
.L0f0d3e4c:
/*  f0d3e4c:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d3e50:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0d3e54:	8d0b1a7c */ 	lw	$t3,0x1a7c($t0)
/*  f0d3e58:	55610044 */ 	bnel	$t3,$at,.L0f0d3f6c
/*  f0d3e5c:	c4ea00ac */ 	lwc1	$f10,0xac($a3)
/*  f0d3e60:	c5000170 */ 	lwc1	$f0,0x170($t0)
/*  f0d3e64:	c5020168 */ 	lwc1	$f2,0x168($t0)
/*  f0d3e68:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d3e6c:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0d3e70:	44817000 */ 	mtc1	$at,$f14
/*  f0d3e74:	3c018007 */ 	lui	$at,%hi(var80070f10-0xc)
/*  f0d3e78:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f0d3e7c:	460a2300 */ 	add.s	$f12,$f4,$f10
/*  f0d3e80:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0d3e84:	00000000 */ 	nop
/*  f0d3e88:	45020003 */ 	bc1fl	.L0f0d3e98
/*  f0d3e8c:	8e030034 */ 	lw	$v1,0x34($s0)
/*  f0d3e90:	46007306 */ 	mov.s	$f12,$f14
/*  f0d3e94:	8e030034 */ 	lw	$v1,0x34($s0)
.L0f0d3e98:
/*  f0d3e98:	00001025 */ 	or	$v0,$zero,$zero
/*  f0d3e9c:	1860000c */ 	blez	$v1,.L0f0d3ed0
/*  f0d3ea0:	00000000 */ 	nop
/*  f0d3ea4:	c4220f04 */ 	lwc1	$f2,%lo(var80070f10-0xc)($at)
/*  f0d3ea8:	3c017f1b */ 	lui	$at,%hi(var7f1adb8c)
/*  f0d3eac:	c420db8c */ 	lwc1	$f0,%lo(var7f1adb8c)($at)
.L0f0d3eb0:
/*  f0d3eb0:	46026181 */ 	sub.s	$f6,$f12,$f2
/*  f0d3eb4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d3eb8:	0043082a */ 	slt	$at,$v0,$v1
/*  f0d3ebc:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0d3ec0:	1420fffb */ 	bnez	$at,.L0f0d3eb0
/*  f0d3ec4:	46081080 */ 	add.s	$f2,$f2,$f8
/*  f0d3ec8:	3c018007 */ 	lui	$at,%hi(var80070f10-0xc)
/*  f0d3ecc:	e4220f04 */ 	swc1	$f2,%lo(var80070f10-0xc)($at)
.L0f0d3ed0:
/*  f0d3ed0:	3c018007 */ 	lui	$at,%hi(var80070f10-0xc)
/*  f0d3ed4:	c4220f04 */ 	lwc1	$f2,%lo(var80070f10-0xc)($at)
/*  f0d3ed8:	3c014396 */ 	lui	$at,0x4396
/*  f0d3edc:	44812000 */ 	mtc1	$at,$f4
/*  f0d3ee0:	46021000 */ 	add.s	$f0,$f2,$f2
/*  f0d3ee4:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0d3ee8:	46007301 */ 	sub.s	$f12,$f14,$f0
/*  f0d3eec:	45000003 */ 	bc1f	.L0f0d3efc
/*  f0d3ef0:	00000000 */ 	nop
/*  f0d3ef4:	44806000 */ 	mtc1	$zero,$f12
/*  f0d3ef8:	00000000 */ 	nop
.L0f0d3efc:
/*  f0d3efc:	46046302 */ 	mul.s	$f12,$f12,$f4
/*  f0d3f00:	8d041a6c */ 	lw	$a0,0x1a6c($t0)
/*  f0d3f04:	44051000 */ 	mfc1	$a1,$f2
/*  f0d3f08:	3c018007 */ 	lui	$at,%hi(var80070f10-0xc)
/*  f0d3f0c:	e4220f04 */ 	swc1	$f2,%lo(var80070f10-0xc)($at)
/*  f0d3f10:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0d3f14:	0fc24d8c */ 	jal	func0f093630
/*  f0d3f18:	e7ac0200 */ 	swc1	$f12,0x200($sp)
/*  f0d3f1c:	3c018007 */ 	lui	$at,%hi(var80070f10-0xc)
/*  f0d3f20:	c4220f04 */ 	lwc1	$f2,%lo(var80070f10-0xc)($at)
/*  f0d3f24:	3c014396 */ 	lui	$at,0x4396
/*  f0d3f28:	44815000 */ 	mtc1	$at,$f10
/*  f0d3f2c:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0d3f30:	460a1182 */ 	mul.s	$f6,$f2,$f10
/*  f0d3f34:	8d841a6c */ 	lw	$a0,0x1a6c($t4)
/*  f0d3f38:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0d3f3c:	44054000 */ 	mfc1	$a1,$f8
/*  f0d3f40:	0fc24de4 */ 	jal	func0f093790
/*  f0d3f44:	00000000 */ 	nop
/*  f0d3f48:	c7ac0200 */ 	lwc1	$f12,0x200($sp)
/*  f0d3f4c:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0d3f50:	4600610d */ 	trunc.w.s	$f4,$f12
/*  f0d3f54:	8dc400bc */ 	lw	$a0,0xbc($t6)
/*  f0d3f58:	44052000 */ 	mfc1	$a1,$f4
/*  f0d3f5c:	0fc24de4 */ 	jal	func0f093790
/*  f0d3f60:	00000000 */ 	nop
/*  f0d3f64:	8fa70218 */ 	lw	$a3,0x218($sp)
/*  f0d3f68:	c4ea00ac */ 	lwc1	$f10,0xac($a3)
.L0f0d3f6c:
/*  f0d3f6c:	c606004c */ 	lwc1	$f6,0x4c($s0)
/*  f0d3f70:	46065302 */ 	mul.s	$f12,$f10,$f6
/*  f0d3f74:	0fc34d8f */ 	jal	bbike0f0d363c
/*  f0d3f78:	00000000 */ 	nop
/*  f0d3f7c:	8fa70218 */ 	lw	$a3,0x218($sp)
/*  f0d3f80:	c600004c */ 	lwc1	$f0,0x4c($s0)
/*  f0d3f84:	44805000 */ 	mtc1	$zero,$f10
/*  f0d3f88:	c4e8009c */ 	lwc1	$f8,0x9c($a3)
/*  f0d3f8c:	27a4020c */ 	addiu	$a0,$sp,0x20c
/*  f0d3f90:	e7aa0210 */ 	swc1	$f10,0x210($sp)
/*  f0d3f94:	46004102 */ 	mul.s	$f4,$f8,$f0
/*  f0d3f98:	e7a4020c */ 	swc1	$f4,0x20c($sp)
/*  f0d3f9c:	c4e600a0 */ 	lwc1	$f6,0xa0($a3)
/*  f0d3fa0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0d3fa4:	e7a80214 */ 	swc1	$f8,0x214($sp)
/*  f0d3fa8:	8ce20014 */ 	lw	$v0,0x14($a3)
/*  f0d3fac:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0d3fb0:	e4e400a4 */ 	swc1	$f4,0xa4($a3)
/*  f0d3fb4:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f0d3fb8:	0fc34f18 */ 	jal	bbike0f0d3c60
/*  f0d3fbc:	e4ea00a8 */ 	swc1	$f10,0xa8($a3)
/*  f0d3fc0:	8fa70218 */ 	lw	$a3,0x218($sp)
/*  f0d3fc4:	c600004c */ 	lwc1	$f0,0x4c($s0)
/*  f0d3fc8:	8ce20014 */ 	lw	$v0,0x14($a3)
/*  f0d3fcc:	c4e800a4 */ 	lwc1	$f8,0xa4($a3)
/*  f0d3fd0:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0d3fd4:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f0d3fd8:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0d3fdc:	c4e600a8 */ 	lwc1	$f6,0xa8($a3)
/*  f0d3fe0:	46002383 */ 	div.s	$f14,$f4,$f0
/*  f0d3fe4:	44802000 */ 	mtc1	$zero,$f4
/*  f0d3fe8:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0d3fec:	46004403 */ 	div.s	$f16,$f8,$f0
/*  f0d3ff0:	46047032 */ 	c.eq.s	$f14,$f4
/*  f0d3ff4:	00000000 */ 	nop
/*  f0d3ff8:	45000007 */ 	bc1f	.L0f0d4018
/*  f0d3ffc:	00000000 */ 	nop
/*  f0d4000:	44805000 */ 	mtc1	$zero,$f10
/*  f0d4004:	00000000 */ 	nop
/*  f0d4008:	460a8032 */ 	c.eq.s	$f16,$f10
/*  f0d400c:	00000000 */ 	nop
/*  f0d4010:	4503001f */ 	bc1tl	.L0f0d4090
/*  f0d4014:	e4ee009c */ 	swc1	$f14,0x9c($a3)
.L0f0d4018:
/*  f0d4018:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f0d401c:	44802000 */ 	mtc1	$zero,$f4
/*  f0d4020:	46108202 */ 	mul.s	$f8,$f16,$f16
/*  f0d4024:	46083480 */ 	add.s	$f18,$f6,$f8
/*  f0d4028:	4612203c */ 	c.lt.s	$f4,$f18
/*  f0d402c:	00000000 */ 	nop
/*  f0d4030:	45020017 */ 	bc1fl	.L0f0d4090
/*  f0d4034:	e4ee009c */ 	swc1	$f14,0x9c($a3)
/*  f0d4038:	c4e200a0 */ 	lwc1	$f2,0xa0($a3)
/*  f0d403c:	c4e0009c */ 	lwc1	$f0,0x9c($a3)
/*  f0d4040:	e7b001f4 */ 	swc1	$f16,0x1f4($sp)
/*  f0d4044:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f0d4048:	e7ae01f8 */ 	swc1	$f14,0x1f8($sp)
/*  f0d404c:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f0d4050:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0d4054:	0c012974 */ 	jal	sqrtf
/*  f0d4058:	46124303 */ 	div.s	$f12,$f8,$f18
/*  f0d405c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d4060:	44812000 */ 	mtc1	$at,$f4
/*  f0d4064:	8fa70218 */ 	lw	$a3,0x218($sp)
/*  f0d4068:	c7ae01f8 */ 	lwc1	$f14,0x1f8($sp)
/*  f0d406c:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0d4070:	c7b001f4 */ 	lwc1	$f16,0x1f4($sp)
/*  f0d4074:	45020006 */ 	bc1fl	.L0f0d4090
/*  f0d4078:	e4ee009c */ 	swc1	$f14,0x9c($a3)
/*  f0d407c:	46007382 */ 	mul.s	$f14,$f14,$f0
/*  f0d4080:	00000000 */ 	nop
/*  f0d4084:	46008402 */ 	mul.s	$f16,$f16,$f0
/*  f0d4088:	00000000 */ 	nop
/*  f0d408c:	e4ee009c */ 	swc1	$f14,0x9c($a3)
.L0f0d4090:
/*  f0d4090:	e4f000a0 */ 	swc1	$f16,0xa0($a3)
/*  f0d4094:	8fa4021c */ 	lw	$a0,0x21c($sp)
/*  f0d4098:	0fc1c52e */ 	jal	func0f0714b8
/*  f0d409c:	24e5005c */ 	addiu	$a1,$a3,0x5c
/*  f0d40a0:	8fa4021c */ 	lw	$a0,0x21c($sp)
/*  f0d40a4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0d40a8:	0fc1a71c */ 	jal	func0f069c70
/*  f0d40ac:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0d40b0:	8fa4021c */ 	lw	$a0,0x21c($sp)
/*  f0d40b4:	27a501a8 */ 	addiu	$a1,$sp,0x1a8
/*  f0d40b8:	0c005755 */ 	jal	func00015d54
/*  f0d40bc:	2484001c */ 	addiu	$a0,$a0,0x1c
/*  f0d40c0:	8fb8021c */ 	lw	$t8,0x21c($sp)
/*  f0d40c4:	27a501a8 */ 	addiu	$a1,$sp,0x1a8
/*  f0d40c8:	8f040014 */ 	lw	$a0,0x14($t8)
/*  f0d40cc:	0c005775 */ 	jal	func00015dd4
/*  f0d40d0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d40d4:	8e050284 */ 	lw	$a1,0x284($s0)
/*  f0d40d8:	27a401a8 */ 	addiu	$a0,$sp,0x1a8
/*  f0d40dc:	27a601e8 */ 	addiu	$a2,$sp,0x1e8
/*  f0d40e0:	0c0056da */ 	jal	func00015b68
/*  f0d40e4:	24a51a70 */ 	addiu	$a1,$a1,0x1a70
/*  f0d40e8:	0fc34d07 */ 	jal	bbikeUpdateVertical
/*  f0d40ec:	27a401e8 */ 	addiu	$a0,$sp,0x1e8
/*  f0d40f0:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d40f4:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0d40f8:	8d0600bc */ 	lw	$a2,0xbc($t0)
/*  f0d40fc:	84d90028 */ 	lh	$t9,0x28($a2)
/*  f0d4100:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0d4104:	50b90015 */ 	beql	$a1,$t9,.L0f0d415c
/*  f0d4108:	8fad021c */ 	lw	$t5,0x21c($sp)
/*  f0d410c:	850419b0 */ 	lh	$a0,0x19b0($t0)
/*  f0d4110:	84c30028 */ 	lh	$v1,0x28($a2)
.L0f0d4114:
/*  f0d4114:	5483000d */ 	bnel	$a0,$v1,.L0f0d414c
/*  f0d4118:	8443002a */ 	lh	$v1,0x2a($v0)
/*  f0d411c:	0fc19711 */ 	jal	func0f065c44
/*  f0d4120:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0d4124:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d4128:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0d412c:	850919b0 */ 	lh	$t1,0x19b0($t0)
/*  f0d4130:	8d0a00bc */ 	lw	$t2,0xbc($t0)
/*  f0d4134:	a5490028 */ 	sh	$t1,0x28($t2)
/*  f0d4138:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0d413c:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f0d4140:	10000005 */ 	b	.L0f0d4158
/*  f0d4144:	a585002a */ 	sh	$a1,0x2a($t4)
/*  f0d4148:	8443002a */ 	lh	$v1,0x2a($v0)
.L0f0d414c:
/*  f0d414c:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0d4150:	14a3fff0 */ 	bne	$a1,$v1,.L0f0d4114
/*  f0d4154:	00000000 */ 	nop
.L0f0d4158:
/*  f0d4158:	8fad021c */ 	lw	$t5,0x21c($sp)
.L0f0d415c:
/*  f0d415c:	44806000 */ 	mtc1	$zero,$f12
/*  f0d4160:	25ae001c */ 	addiu	$t6,$t5,0x1c
/*  f0d4164:	0fc44fc4 */ 	jal	bheadAdjustAnimation
/*  f0d4168:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0d416c:	44806000 */ 	mtc1	$zero,$f12
/*  f0d4170:	0fc44e29 */ 	jal	bheadUpdate
/*  f0d4174:	46006386 */ 	mov.s	$f14,$f12
/*  f0d4178:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0d417c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d4180:	44815000 */ 	mtc1	$at,$f10
/*  f0d4184:	c5e60158 */ 	lwc1	$f6,0x158($t7)
/*  f0d4188:	3c017f1b */ 	lui	$at,%hi(var7f1adb90)
/*  f0d418c:	c424db90 */ 	lwc1	$f4,%lo(var7f1adb90)($at)
/*  f0d4190:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0d4194:	27a50164 */ 	addiu	$a1,$sp,0x164
/*  f0d4198:	46044302 */ 	mul.s	$f12,$f8,$f4
/*  f0d419c:	0c0058ba */ 	jal	func000162e8
/*  f0d41a0:	00000000 */ 	nop
/*  f0d41a4:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d41a8:	27a40124 */ 	addiu	$a0,$sp,0x124
/*  f0d41ac:	24050000 */ 	addiu	$a1,$zero,0x0
/*  f0d41b0:	c50a03cc */ 	lwc1	$f10,0x3cc($t0)
/*  f0d41b4:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f0d41b8:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f0d41bc:	46005187 */ 	neg.s	$f6,$f10
/*  f0d41c0:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f0d41c4:	c50803d0 */ 	lwc1	$f8,0x3d0($t0)
/*  f0d41c8:	46004107 */ 	neg.s	$f4,$f8
/*  f0d41cc:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0d41d0:	c50a03d4 */ 	lwc1	$f10,0x3d4($t0)
/*  f0d41d4:	46005187 */ 	neg.s	$f6,$f10
/*  f0d41d8:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*  f0d41dc:	c50803d8 */ 	lwc1	$f8,0x3d8($t0)
/*  f0d41e0:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*  f0d41e4:	c50403dc */ 	lwc1	$f4,0x3dc($t0)
/*  f0d41e8:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0d41ec:	c50a03e0 */ 	lwc1	$f10,0x3e0($t0)
/*  f0d41f0:	0c005b56 */ 	jal	func00016d58
/*  f0d41f4:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f0d41f8:	27a40124 */ 	addiu	$a0,$sp,0x124
/*  f0d41fc:	0c00567f */ 	jal	func000159fc
/*  f0d4200:	27a50164 */ 	addiu	$a1,$sp,0x164
/*  f0d4204:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f0d4208:	0c005755 */ 	jal	func00015d54
/*  f0d420c:	27a50124 */ 	addiu	$a1,$sp,0x124
/*  f0d4210:	8fb8021c */ 	lw	$t8,0x21c($sp)
/*  f0d4214:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d4218:	44813000 */ 	mtc1	$at,$f6
/*  f0d421c:	8f190018 */ 	lw	$t9,0x18($t8)
/*  f0d4220:	27a50124 */ 	addiu	$a1,$sp,0x124
/*  f0d4224:	c7280014 */ 	lwc1	$f8,0x14($t9)
/*  f0d4228:	0c0057c1 */ 	jal	func00015f04
/*  f0d422c:	46083303 */ 	div.s	$f12,$f6,$f8
/*  f0d4230:	0fc1c836 */ 	jal	hoverpropGetTurnAngle
/*  f0d4234:	8fa4021c */ 	lw	$a0,0x21c($sp)
/*  f0d4238:	46000306 */ 	mov.s	$f12,$f0
/*  f0d423c:	0c0058dd */ 	jal	func00016374
/*  f0d4240:	27a500e4 */ 	addiu	$a1,$sp,0xe4
/*  f0d4244:	27a400e4 */ 	addiu	$a0,$sp,0xe4
/*  f0d4248:	0fc25c11 */ 	jal	func0f097044
/*  f0d424c:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*  f0d4250:	27a40124 */ 	addiu	$a0,$sp,0x124
/*  f0d4254:	0fc25c11 */ 	jal	func0f097044
/*  f0d4258:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0d425c:	27a400c4 */ 	addiu	$a0,$sp,0xc4
/*  f0d4260:	0fc25db0 */ 	jal	func0f0976c0
/*  f0d4264:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*  f0d4268:	3c063f4c */ 	lui	$a2,0x3f4c
/*  f0d426c:	34c6cccd */ 	ori	$a2,$a2,0xcccd
/*  f0d4270:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f0d4274:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0d4278:	0fc25cae */ 	jal	func0f0972b8
/*  f0d427c:	27a700b4 */ 	addiu	$a3,$sp,0xb4
/*  f0d4280:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f0d4284:	0fc25bb5 */ 	jal	func0f096ed4
/*  f0d4288:	27a50124 */ 	addiu	$a1,$sp,0x124
/*  f0d428c:	27a40124 */ 	addiu	$a0,$sp,0x124
/*  f0d4290:	0c00567f */ 	jal	func000159fc
/*  f0d4294:	27a50164 */ 	addiu	$a1,$sp,0x164
/*  f0d4298:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d429c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d42a0:	8d091a7c */ 	lw	$t1,0x1a7c($t0)
/*  f0d42a4:	5520008b */ 	bnezl	$t1,.L0f0d44d4
/*  f0d42a8:	c7aa0184 */ 	lwc1	$f10,0x184($sp)
/*  f0d42ac:	44811000 */ 	mtc1	$at,$f2
/*  f0d42b0:	3c014270 */ 	lui	$at,0x4270
/*  f0d42b4:	44815000 */ 	mtc1	$at,$f10
/*  f0d42b8:	c604004c */ 	lwc1	$f4,0x4c($s0)
/*  f0d42bc:	c5081a80 */ 	lwc1	$f8,0x1a80($t0)
/*  f0d42c0:	3c017f1b */ 	lui	$at,%hi(var7f1adb94)
/*  f0d42c4:	460a2183 */ 	div.s	$f6,$f4,$f10
/*  f0d42c8:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0d42cc:	e5041a80 */ 	swc1	$f4,0x1a80($t0)
/*  f0d42d0:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d42d4:	c5001a80 */ 	lwc1	$f0,0x1a80($t0)
/*  f0d42d8:	4600103e */ 	c.le.s	$f2,$f0
/*  f0d42dc:	00000000 */ 	nop
/*  f0d42e0:	45000004 */ 	bc1f	.L0f0d42f4
/*  f0d42e4:	00000000 */ 	nop
/*  f0d42e8:	e5021a80 */ 	swc1	$f2,0x1a80($t0)
/*  f0d42ec:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0d42f0:	c5401a80 */ 	lwc1	$f0,0x1a80($t2)
.L0f0d42f4:
/*  f0d42f4:	c42adb94 */ 	lwc1	$f10,%lo(var7f1adb94)($at)
/*  f0d42f8:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d42fc:	44813000 */ 	mtc1	$at,$f6
/*  f0d4300:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0d4304:	00000000 */ 	nop
/*  f0d4308:	46064302 */ 	mul.s	$f12,$f8,$f6
/*  f0d430c:	0c0068f4 */ 	jal	cosf
/*  f0d4310:	00000000 */ 	nop
/*  f0d4314:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d4318:	44812000 */ 	mtc1	$at,$f4
/*  f0d431c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d4320:	44814000 */ 	mtc1	$at,$f8
/*  f0d4324:	46040280 */ 	add.s	$f10,$f0,$f4
/*  f0d4328:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0d432c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d4330:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0d4334:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d4338:	44815000 */ 	mtc1	$at,$f10
/*  f0d433c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0d4340:	e5661a84 */ 	swc1	$f6,0x1a84($t3)
/*  f0d4344:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d4348:	c5041a80 */ 	lwc1	$f4,0x1a80($t0)
/*  f0d434c:	4604503e */ 	c.le.s	$f10,$f4
/*  f0d4350:	00000000 */ 	nop
/*  f0d4354:	45020047 */ 	bc1fl	.L0f0d4474
/*  f0d4358:	25041a9c */ 	addiu	$a0,$t0,0x1a9c
/*  f0d435c:	ad0c1a7c */ 	sw	$t4,0x1a7c($t0)
/*  f0d4360:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0d4364:	3406ffff */ 	dli	$a2,0xffff
/*  f0d4368:	0fc249af */ 	jal	func0f0926bc
/*  f0d436c:	8da41a6c */ 	lw	$a0,0x1a6c($t5)
/*  f0d4370:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0d4374:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d4378:	44810000 */ 	mtc1	$at,$f0
/*  f0d437c:	8dc500bc */ 	lw	$a1,0xbc($t6)
/*  f0d4380:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0d4384:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0d4388:	afb8002c */ 	sw	$t8,0x2c($sp)
/*  f0d438c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d4390:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0d4394:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0d4398:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0d439c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0d43a0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0d43a4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d43a8:	240600f5 */ 	addiu	$a2,$zero,0xf5
/*  f0d43ac:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0d43b0:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0d43b4:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0d43b8:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0d43bc:	0fc24e7e */ 	jal	func0f0939f8
/*  f0d43c0:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0d43c4:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0d43c8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d43cc:	44810000 */ 	mtc1	$at,$f0
/*  f0d43d0:	8f2500bc */ 	lw	$a1,0xbc($t9)
/*  f0d43d4:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0d43d8:	240affff */ 	addiu	$t2,$zero,-1
/*  f0d43dc:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f0d43e0:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0d43e4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0d43e8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0d43ec:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0d43f0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0d43f4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0d43f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d43fc:	240680af */ 	addiu	$a2,$zero,-32593
/*  f0d4400:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0d4404:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0d4408:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0d440c:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0d4410:	0fc24e7e */ 	jal	func0f0939f8
/*  f0d4414:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0d4418:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0d441c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d4420:	44810000 */ 	mtc1	$at,$f0
/*  f0d4424:	8d651a6c */ 	lw	$a1,0x1a6c($t3)
/*  f0d4428:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0d442c:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0d4430:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f0d4434:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0d4438:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0d443c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0d4440:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0d4444:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0d4448:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0d444c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d4450:	240601b4 */ 	addiu	$a2,$zero,0x1b4
/*  f0d4454:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0d4458:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0d445c:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0d4460:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0d4464:	0fc24e7e */ 	jal	func0f0939f8
/*  f0d4468:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0d446c:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d4470:	25041a9c */ 	addiu	$a0,$t0,0x1a9c
.L0f0d4474:
/*  f0d4474:	0fc25c11 */ 	jal	func0f097044
/*  f0d4478:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0d447c:	27a40164 */ 	addiu	$a0,$sp,0x164
/*  f0d4480:	0fc25c11 */ 	jal	func0f097044
/*  f0d4484:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0d4488:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f0d448c:	0fc25db0 */ 	jal	func0f0976c0
/*  f0d4490:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0d4494:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0d4498:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d449c:	44814000 */ 	mtc1	$at,$f8
/*  f0d44a0:	c5c61a84 */ 	lwc1	$f6,0x1a84($t6)
/*  f0d44a4:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0d44a8:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0d44ac:	46064101 */ 	sub.s	$f4,$f8,$f6
/*  f0d44b0:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f0d44b4:	44062000 */ 	mfc1	$a2,$f4
/*  f0d44b8:	0fc25cae */ 	jal	func0f0972b8
/*  f0d44bc:	00000000 */ 	nop
/*  f0d44c0:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0d44c4:	0fc25bb5 */ 	jal	func0f096ed4
/*  f0d44c8:	27a50164 */ 	addiu	$a1,$sp,0x164
/*  f0d44cc:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d44d0:	c7aa0184 */ 	lwc1	$f10,0x184($sp)
.L0f0d44d4:
/*  f0d44d4:	e50a0388 */ 	swc1	$f10,0x388($t0)
/*  f0d44d8:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0d44dc:	c7a80188 */ 	lwc1	$f8,0x188($sp)
/*  f0d44e0:	e5e8038c */ 	swc1	$f8,0x38c($t7)
/*  f0d44e4:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0d44e8:	c7a6018c */ 	lwc1	$f6,0x18c($sp)
/*  f0d44ec:	e7060390 */ 	swc1	$f6,0x390($t8)
/*  f0d44f0:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0d44f4:	c7a40174 */ 	lwc1	$f4,0x174($sp)
/*  f0d44f8:	e7240394 */ 	swc1	$f4,0x394($t9)
/*  f0d44fc:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0d4500:	c7aa0178 */ 	lwc1	$f10,0x178($sp)
/*  f0d4504:	e52a0398 */ 	swc1	$f10,0x398($t1)
/*  f0d4508:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0d450c:	c7a8017c */ 	lwc1	$f8,0x17c($sp)
/*  f0d4510:	e548039c */ 	swc1	$f8,0x39c($t2)
/*  f0d4514:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0d4518:	8d0b1a7c */ 	lw	$t3,0x1a7c($t0)
/*  f0d451c:	55600020 */ 	bnezl	$t3,.L0f0d45a0
/*  f0d4520:	8d0400bc */ 	lw	$a0,0xbc($t0)
/*  f0d4524:	c5061a90 */ 	lwc1	$f6,0x1a90($t0)
/*  f0d4528:	c5041adc */ 	lwc1	$f4,0x1adc($t0)
/*  f0d452c:	c5081a84 */ 	lwc1	$f8,0x1a84($t0)
/*  f0d4530:	8d0c00bc */ 	lw	$t4,0xbc($t0)
/*  f0d4534:	46043281 */ 	sub.s	$f10,$f6,$f4
/*  f0d4538:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f0d453c:	c5840008 */ 	lwc1	$f4,0x8($t4)
/*  f0d4540:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d4544:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f0d4548:	e7aa0078 */ 	swc1	$f10,0x78($sp)
/*  f0d454c:	8d0d00bc */ 	lw	$t5,0xbc($t0)
/*  f0d4550:	c5081a94 */ 	lwc1	$f8,0x1a94($t0)
/*  f0d4554:	c5041a84 */ 	lwc1	$f4,0x1a84($t0)
/*  f0d4558:	c5a0000c */ 	lwc1	$f0,0xc($t5)
/*  f0d455c:	46004181 */ 	sub.s	$f6,$f8,$f0
/*  f0d4560:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0d4564:	46005200 */ 	add.s	$f8,$f10,$f0
/*  f0d4568:	e7a8007c */ 	swc1	$f8,0x7c($sp)
/*  f0d456c:	c5041ae4 */ 	lwc1	$f4,0x1ae4($t0)
/*  f0d4570:	c5061a98 */ 	lwc1	$f6,0x1a98($t0)
/*  f0d4574:	c5081a84 */ 	lwc1	$f8,0x1a84($t0)
/*  f0d4578:	8d0e00bc */ 	lw	$t6,0xbc($t0)
/*  f0d457c:	46043281 */ 	sub.s	$f10,$f6,$f4
/*  f0d4580:	c5c40010 */ 	lwc1	$f4,0x10($t6)
/*  f0d4584:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d4588:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f0d458c:	0fc33067 */ 	jal	bmove0f0cc19c
/*  f0d4590:	e7aa0080 */ 	swc1	$f10,0x80($sp)
/*  f0d4594:	10000005 */ 	b	.L0f0d45ac
/*  f0d4598:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0d459c:	8d0400bc */ 	lw	$a0,0xbc($t0)
.L0f0d45a0:
/*  f0d45a0:	0fc33067 */ 	jal	bmove0f0cc19c
/*  f0d45a4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d45a8:	8e0f0284 */ 	lw	$t7,0x284($s0)
.L0f0d45ac:
/*  f0d45ac:	3c017f1b */ 	lui	$at,%hi(var7f1adb98)
/*  f0d45b0:	c426db98 */ 	lwc1	$f6,%lo(var7f1adb98)($at)
/*  f0d45b4:	c5e8015c */ 	lwc1	$f8,0x15c($t7)
/*  f0d45b8:	46064083 */ 	div.s	$f2,$f8,$f6
/*  f0d45bc:	0fc4505b */ 	jal	bheadGetBreathingValue
/*  f0d45c0:	e7a20070 */ 	swc1	$f2,0x70($sp)
/*  f0d45c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d45c8:	c7a20070 */ 	lwc1	$f2,0x70($sp)
/*  f0d45cc:	44812000 */ 	mtc1	$at,$f4
/*  f0d45d0:	46000306 */ 	mov.s	$f12,$f0
/*  f0d45d4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d45d8:	4602203c */ 	c.lt.s	$f4,$f2
/*  f0d45dc:	00000000 */ 	nop
/*  f0d45e0:	45020006 */ 	bc1fl	.L0f0d45fc
/*  f0d45e4:	44815000 */ 	mtc1	$at,$f10
/*  f0d45e8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d45ec:	44811000 */ 	mtc1	$at,$f2
/*  f0d45f0:	1000000a */ 	b	.L0f0d461c
/*  f0d45f4:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0d45f8:	44815000 */ 	mtc1	$at,$f10
.L0f0d45fc:
/*  f0d45fc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d4600:	460a103c */ 	c.lt.s	$f2,$f10
/*  f0d4604:	00000000 */ 	nop
/*  f0d4608:	45020004 */ 	bc1fl	.L0f0d461c
/*  f0d460c:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0d4610:	44811000 */ 	mtc1	$at,$f2
/*  f0d4614:	00000000 */ 	nop
/*  f0d4618:	8e180284 */ 	lw	$t8,0x284($s0)
.L0f0d461c:
/*  f0d461c:	44807000 */ 	mtc1	$zero,$f14
/*  f0d4620:	44061000 */ 	mfc1	$a2,$f2
/*  f0d4624:	c7080168 */ 	lwc1	$f8,0x168($t8)
/*  f0d4628:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f0d462c:	0fc27637 */ 	jal	func0f09d8dc
/*  f0d4630:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0d4634:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0d4638:	3c017f1b */ 	lui	$at,%hi(var7f1adb9c)
/*  f0d463c:	c424db9c */ 	lwc1	$f4,%lo(var7f1adb9c)($at)
/*  f0d4640:	c7260158 */ 	lwc1	$f6,0x158($t9)
/*  f0d4644:	46043302 */ 	mul.s	$f12,$f6,$f4
/*  f0d4648:	0fc288a4 */ 	jal	func0f0a2290
/*  f0d464c:	00000000 */ 	nop
/*  f0d4650:	0fc307fd */ 	jal	currentPlayerUpdatePerimInfo
/*  f0d4654:	00000000 */ 	nop
/*  f0d4658:	0fc32e31 */ 	jal	bmove0f0cb8c4
/*  f0d465c:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0d4660:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0d4664:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0d4668:	0fc257d8 */ 	jal	objectiveCheckRoomEntered
/*  f0d466c:	85440028 */ 	lh	$a0,0x28($t2)
/*  f0d4670:	0fc23064 */ 	jal	func0f08c190
/*  f0d4674:	00000000 */ 	nop
/*  f0d4678:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0d467c:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0d4680:	27bd0220 */ 	addiu	$sp,$sp,0x220
/*  f0d4684:	03e00008 */ 	jr	$ra
/*  f0d4688:	00000000 */ 	nop
/*  f0d468c:	00000000 */ 	nop
);
