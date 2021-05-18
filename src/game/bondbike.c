#include <ultra64.h>
#include "constants.h"
#include "game/bondbike.h"
#include "game/bondmove.h"
#include "game/chr/chraction.h"
#include "game/prop.h"
#include "game/game_091e10.h"
#include "game/game_092610.h"
#include "game/game_095320.h"
#include "game/game_096ca0.h"
#include "game/game_097ba0.h"
#include "game/game_0b3350.h"
#include "game/game_0b69d0.h"
#include "game/bondhead.h"
#include "game/lv.h"
#include "game/objectives.h"
#include "game/options.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_24e40.h"
#include "data.h"
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
	func0f0939f8(NULL, g_Vars.currentplayer->hoverbike, SFX_BIKE_PULSE, -1,
			-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);

	obj->flags |= OBJFLAG_40000000;
}

void bbikeUpdateVehicleOffset(void)
{
	struct defaultobj *hoverbike = g_Vars.currentplayer->hoverbike->obj;

	g_Vars.currentplayer->bondvehicleoffset.x = 0.0f / hoverbike->model->scale;
	g_Vars.currentplayer->bondvehicleoffset.y = 80.0f / hoverbike->model->scale;
	g_Vars.currentplayer->bondvehicleoffset.z = -50.0f / hoverbike->model->scale;
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
			&& g_Vars.lvframe60 - g_Vars.currentplayer->activatetimelast < PALDOWN(25)) {
		struct hoverbikeobj *bike = (struct hoverbikeobj *)g_Vars.currentplayer->hoverbike->obj;
		struct modelrodata_bbox *bbox = objFindBboxRodata(&bike->base);

		f32 sidedist = bbox->xmax * bike->base.model->scale;
		f32 frontdist = bbox->zmax * bike->base.model->scale;
		f32 diagdist = sqrtf(sidedist * sidedist + frontdist * frontdist);

		g_Vars.currentplayer->walkinitmove = false;

		bbikeTryDismountAngle(1.5705462694168f, sidedist);  // 90  - left
		bbikeTryDismountAngle(4.7116389274597f, sidedist);  // 270 - right
		bbikeTryDismountAngle(0.7852731347084f, diagdist);  // 45  - front left
		bbikeTryDismountAngle(5.4969120025635f, diagdist);  // 315 - front right
		bbikeTryDismountAngle(2.3558194637299f, diagdist);  // 135 - back left
		bbikeTryDismountAngle(3.9263656139374f, diagdist);  // 225 - back right
		bbikeTryDismountAngle(0, frontdist);                // 0   - front
		bbikeTryDismountAngle(3.1410925388336f, frontdist); // 180 - back

		if (g_Vars.currentplayer->walkinitmove) {
			bmoveSetMode(MOVEMODE_WALK);
		}

		g_Vars.currentplayer->bondactivateorreload = 0;
	}
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel bbikeApplyMoveData
.late_rodata
glabel var7f1adb54
.word 0x3dcccccd
glabel var7f1adb58
.word 0xbdcccccd
glabel var7f1adb5c
.word 0xbdf5c290
glabel var7f1adb60
.word 0x3df5c290
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
/*  f0d2740:	0fc5b364 */ 	jal	lvIsPaused
/*  f0d2744:	00000000 */ 	nop
/*  f0d2748:	1440000d */ 	bnez	$v0,.L0f0d2780
/*  f0d274c:	8fa70060 */ 	lw	$a3,0x60($sp)
/*  f0d2750:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d2754:	83a5005b */ 	lb	$a1,0x5b($sp)
/*  f0d2758:	0c005326 */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0d275c:	24060202 */ 	addiu	$a2,$zero,0x202
/*  f0d2760:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0d2764:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d2768:	24060101 */ 	addiu	$a2,$zero,0x101
/*  f0d276c:	ad820028 */ 	sw	$v0,0x28($t4)
/*  f0d2770:	0c005326 */ 	jal	joyCountButtonsOnSpecificSamples
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
#else
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
/*  f0d2740:	0fc5b364 */ 	jal	lvIsPaused
/*  f0d2744:	00000000 */ 	nop
/*  f0d2748:	1440000d */ 	bnez	$v0,.L0f0d2780
/*  f0d274c:	8fa70060 */ 	lw	$a3,0x60($sp)
/*  f0d2750:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d2754:	83a5005b */ 	lb	$a1,0x5b($sp)
/*  f0d2758:	0c005326 */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0d275c:	24060202 */ 	addiu	$a2,$zero,0x202
/*  f0d2760:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0d2764:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d2768:	24060101 */ 	addiu	$a2,$zero,0x101
/*  f0d276c:	ad820028 */ 	sw	$v0,0x28($t4)
/*  f0d2770:	0c005326 */ 	jal	joyCountButtonsOnSpecificSamples
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
#endif

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
//			&& !lvIsPaused()) {
//		data->digitalstepleft = joyCountButtonsOnSpecificSamples(0, contnum, L_JPAD | L_CBUTTONS);
//		data->digitalstepright = joyCountButtonsOnSpecificSamples(0, contnum, R_JPAD | R_CBUTTONS);
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

s32 bbikeCalculateNewPosition(struct coord *vel, f32 angledelta)
{
	s32 result = CDRESULT_NOCOLLISION;
	struct coord dstpos;
	s16 dstrooms[8];
	struct hov hov;
	bool hasvel = false;
	struct hoverbikeobj *bike = (struct hoverbikeobj *) g_Vars.currentplayer->hoverbike->obj;
	s16 spa8[20];
	f32 xdiff;
	f32 zdiff;
	f32 ymax;
	f32 ymin;
	f32 width;
	f32 halfwidth;

	dstpos.x = g_Vars.currentplayer->hoverbike->pos.x;
	dstpos.y = g_Vars.currentplayer->hoverbike->pos.y;
	dstpos.z = g_Vars.currentplayer->hoverbike->pos.z;

	if (vel->x || vel->y || vel->z) {
		propSetCollisionsEnabled(g_Vars.currentplayer->prop, false);
		propSetCollisionsEnabled(g_Vars.currentplayer->hoverbike, false);

		dstpos.x += vel->x;
		dstpos.z += vel->z;

		propObjGetBbox(g_Vars.currentplayer->hoverbike, &width, &ymax, &ymin);
		func0f065dfc(&g_Vars.currentplayer->hoverbike->pos,
				g_Vars.currentplayer->hoverbike->rooms,
				&dstpos, dstrooms, spa8, 20);

		func0f09233c(&bike->base, &dstpos, bike->base.realrot, dstrooms);

		hasvel = true;

		hov = bike->hov;

		func0f0713e4(&bike->base, &hov, &dstpos, dstrooms, bike->base.realrot);

		dstpos.y += hov.unk34 - bike->hov.unk34;

		halfwidth = width * 0.5f;
		xdiff = dstpos.x - g_Vars.currentplayer->hoverbike->pos.x;
		zdiff = dstpos.z - g_Vars.currentplayer->hoverbike->pos.z;

		if (xdiff > halfwidth || zdiff > halfwidth || xdiff < -halfwidth || zdiff < -halfwidth) {
			result = cdTestAToB3(&g_Vars.currentplayer->hoverbike->pos,
					g_Vars.currentplayer->hoverbike->rooms,
					&dstpos, dstrooms, width, CDTYPE_ALL, 1,
					ymax - g_Vars.currentplayer->hoverbike->pos.y,
					ymin - g_Vars.currentplayer->hoverbike->pos.y);

			if (result == CDRESULT_NOCOLLISION) {
				result = cdTestAToB1(&g_Vars.currentplayer->hoverbike->pos,
						&dstpos, width, dstrooms, CDTYPE_ALL, 1,
						ymax - g_Vars.currentplayer->hoverbike->pos.y,
						ymin - g_Vars.currentplayer->hoverbike->pos.y);
			}
		} else {
			result = cdTestAToB1(&g_Vars.currentplayer->hoverbike->pos,
					&dstpos, width, spa8, CDTYPE_ALL, 1,
					ymax - g_Vars.currentplayer->hoverbike->pos.y,
					ymin - g_Vars.currentplayer->hoverbike->pos.y);
		}

		propSetCollisionsEnabled(g_Vars.currentplayer->prop, true);
		propSetCollisionsEnabled(g_Vars.currentplayer->hoverbike, true);
	}

	if (angledelta) {
		u32 stack[2];
		f32 newangle = hoverpropGetTurnAngle(&bike->base) - angledelta;
		Mtxf sp44;

		if (newangle >= M_BADTAU) {
			newangle -= M_BADTAU;
		} else if (newangle < 0.0f) {
			newangle += M_BADTAU;
		}

		hoverpropSetTurnAngle(&bike->base, newangle);

		func00016374(newangle, &sp44);
		func00015f04(bike->base.model->scale, &sp44);
		func00015da0(&sp44, bike->base.realrot);
	}

	if (result == CDRESULT_NOCOLLISION && hasvel) {
		g_Vars.currentplayer->hoverbike->pos.x = dstpos.x;
		g_Vars.currentplayer->hoverbike->pos.z = dstpos.z;

		func0f065c44(g_Vars.currentplayer->hoverbike);
		roomsCopy(dstrooms, g_Vars.currentplayer->hoverbike->rooms);

		bike->hov = hov;
	}

	return result;
}

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

#if VERSION < VERSION_NTSC_1_0
	{
		s32 i;

		for (i = 0; newrooms[i] != -1; i++) {
			if (g_Vars.currentplayer->floorroom == newrooms[i]) {
				newrooms[0] = g_Vars.currentplayer->floorroom;
				newrooms[1] = -1;
				break;
			}
		}
	}
#endif

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

	if (g_Vars.currentplayer->floorflags & TILEFLAG_DIE) {
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

void bbikeTick(void)
{
	struct defaultobj *obj = g_Vars.currentplayer->hoverbike->obj;
	struct hoverbikeobj *bike = (struct hoverbikeobj *) g_Vars.currentplayer->hoverbike->obj;
	struct coord sp20c;
	struct prop *prop;
	s32 i;
	f32 sp200;
	u32 stack;
	f32 sp1f8;
	f32 sp1f4;
	struct coord sp1e8;
	Mtxf sp1a8;
	u32 stack2;
	Mtxf sp164;
	Mtxf sp124;
	Mtxf spe4;
	u32 stack3;
	struct coord spd4;
	u32 stack4;
	struct coord spc4;
	f32 spb4[4];
	u32 stack5;
	struct coord spa4;
	u32 stack6;
	struct coord sp94;
	f32 sp84[4];
	struct coord pos;
	f32 breathing;
	f32 sp70;
	f32 sqdist;

	static f32 var80070f04 = 0;

	if (g_Vars.lvupdate240 > 0) {
		g_Vars.currentplayer->bondprevpos.x = g_Vars.currentplayer->prop->pos.x;
		g_Vars.currentplayer->bondprevpos.y = g_Vars.currentplayer->prop->pos.y;
		g_Vars.currentplayer->bondprevpos.z = g_Vars.currentplayer->prop->pos.z;

		g_Vars.currentplayer->bondbreathing -= (0.75f * g_Vars.lvupdate240freal) / 2700.0f;

		if (g_Vars.currentplayer->bondbreathing < 0.0f) {
			g_Vars.currentplayer->bondbreathing = 0.0f;
		}

		if (g_Vars.currentplayer->bondvehiclemode == VEHICLEMODE_OFF) {
			func0f072adc(bike,
					g_Vars.currentplayer->speedforwards,
					g_Vars.currentplayer->speedsideways,
					g_Vars.currentplayer->speedtheta);
		} else {
			if (g_Vars.currentplayer->bondvehiclemode == VEHICLEMODE_ENGINESTART) {
				g_Vars.currentplayer->bondvehiclemode = VEHICLEMODE_RUNNING;
			}

			func0f072adc(bike,
					g_Vars.currentplayer->speedforwards,
					g_Vars.currentplayer->speedsideways,
					g_Vars.currentplayer->speedtheta);
		}

		if (g_Vars.currentplayer->bondvehiclemode == VEHICLEMODE_RUNNING) {
			sqdist = g_Vars.currentplayer->speedforwards * g_Vars.currentplayer->speedforwards
				+ g_Vars.currentplayer->speedsideways * g_Vars.currentplayer->speedsideways;

			if (sqdist > 1.0f) {
				sqdist = 1.0f;
			}

			for (i = 0; i < g_Vars.lvupdate240; i++) {
				var80070f04 += (sqdist - var80070f04) * (PAL ? 0.003f : 0.0025f);
			}

			sp200 = 1.0f - (var80070f04 + var80070f04);

			if (var80070f04 + var80070f04 > 1.0f) {
				sp200 = 0.0f;
			}

			sp200 *= 300.0f;

			func0f093630(g_Vars.currentplayer->hoverbike, var80070f04, -1);
			func0f093790(g_Vars.currentplayer->hoverbike, var80070f04 * 300.0f);
			func0f093790(g_Vars.currentplayer->prop, sp200);
		}

		if (1);

		bbike0f0d363c(bike->w * g_Vars.lvupdate240freal);

		sp20c.x = bike->speed[0] * g_Vars.lvupdate240freal;
		sp20c.y = 0.0f;
		sp20c.z = bike->speed[1] * g_Vars.lvupdate240freal;

		bike->prevpos[0] = bike->base.prop->pos.x;
		bike->prevpos[1] = bike->base.prop->pos.z;

		bbike0f0d3c60(&sp20c);

		sp1f8 = (bike->base.prop->pos.x - bike->prevpos[0]) / g_Vars.lvupdate240freal;
		sp1f4 = (bike->base.prop->pos.z - bike->prevpos[1]) / g_Vars.lvupdate240freal;

		if (sp1f8 != 0.0f || sp1f4 != 0.0f) {
			f32 tmp = sp1f8 * sp1f8 + sp1f4 * sp1f4;

			if (tmp > 0.0f) {
				tmp = sqrtf((bike->speed[0] * bike->speed[0] + bike->speed[1] * bike->speed[1]) / tmp);

				if (tmp < 1.0f) {
					sp1f8 *= tmp;
					sp1f4 *= tmp;
				}
			}
		}

		bike->speed[0] = sp1f8;
		bike->speed[1] = sp1f4;

		func0f0714b8(obj, &bike->hov);
		func0f069c70(obj, true, true);
		func00015d54(obj->realrot, &sp1a8);
		func00015dd4(&obj->prop->pos, &sp1a8);
		func00015b68(&sp1a8, &g_Vars.currentplayer->bondvehicleoffset, &sp1e8);

		bbikeUpdateVertical(&sp1e8);

		prop = g_Vars.currentplayer->prop;

#if VERSION >= VERSION_NTSC_1_0
		for (i = 0; prop->rooms[i] != -1; i++) {
			if (prop->rooms[i] == g_Vars.currentplayer->floorroom) {
				func0f065c44(prop);
				g_Vars.currentplayer->prop->rooms[0] = g_Vars.currentplayer->floorroom;
				g_Vars.currentplayer->prop->rooms[1] = -1;
				break;
			}
		}
#endif
	}

	bheadAdjustAnimation(0);
	bheadUpdate(0, 0);
	func000162e8((360.0f - g_Vars.currentplayer->vv_verta360) * 0.017450513318181f, &sp164);

	func00016d58(&sp124, 0.0f, 0.0f, 0.0f,
			-g_Vars.currentplayer->headlook.x, -g_Vars.currentplayer->headlook.y, -g_Vars.currentplayer->headlook.z,
			g_Vars.currentplayer->headup.x, g_Vars.currentplayer->headup.y, g_Vars.currentplayer->headup.z);

	func000159fc(&sp124, &sp164);
	func00015d54(obj->realrot, &sp124);
	func00015f04(1.0f / obj->model->scale, &sp124);
	func00016374(hoverpropGetTurnAngle(obj), &spe4);
	func0f097044(&spe4, &spd4);
	func0f097044(&sp124, &spc4);
	func0f0976c0(&spc4, &spd4);
	func0f0972b8(&spd4, &spc4, 0.8f, spb4);
	func0f096ed4(spb4, &sp124);
	func000159fc(&sp124, &sp164);

	if (g_Vars.currentplayer->bondvehiclemode == VEHICLEMODE_OFF) {
		g_Vars.currentplayer->bondentert += g_Vars.lvupdate240freal / 60.0f;

		if (g_Vars.currentplayer->bondentert >= 1.0f) {
			g_Vars.currentplayer->bondentert = 1.0f;
		}

		g_Vars.currentplayer->bondentert2 = (cosf(g_Vars.currentplayer->bondentert * M_BADTAU * 0.5f) + 1.0f) * 0.5f;

		if (g_Vars.currentplayer->bondentert >= 1.0f) {
			g_Vars.currentplayer->bondvehiclemode = VEHICLEMODE_ENGINESTART;

			func0f0926bc(g_Vars.currentplayer->hoverbike, 1, 0xffff);

			func0f0939f8(NULL, g_Vars.currentplayer->prop, SFX_BIKE_TAKEOFF, -1,
					-1, 0, 0, 0, NULL, -1, NULL, -1, -1, -1, -1);

			func0f0939f8(NULL, g_Vars.currentplayer->prop, SFX_BIKE_PULSE, -1,
					-1, 0, 0, 0, NULL, -1, NULL, -1, -1, -1, -1);

			func0f0939f8(NULL, g_Vars.currentplayer->hoverbike, SFX_BIKE_ENGINE, -1,
					-1, 0, 0, 0, NULL, -1, NULL, -1, -1, -1, -1);
		}

		func0f097044(&g_Vars.currentplayer->bondentermtx, &spa4);
		func0f097044(&sp164, &sp94);
		func0f0976c0(&sp94, &spa4);
		func0f0972b8(&spa4, &sp94, 1.0f - g_Vars.currentplayer->bondentert2, sp84);
		func0f096ed4(sp84, &sp164);
	}

	g_Vars.currentplayer->bond2.unk1c.x = sp164.m[2][0];
	g_Vars.currentplayer->bond2.unk1c.y = sp164.m[2][1];
	g_Vars.currentplayer->bond2.unk1c.z = sp164.m[2][2];
	g_Vars.currentplayer->bond2.unk28.x = sp164.m[1][0];
	g_Vars.currentplayer->bond2.unk28.y = sp164.m[1][1];
	g_Vars.currentplayer->bond2.unk28.z = sp164.m[1][2];

	if (g_Vars.currentplayer->bondvehiclemode == VEHICLEMODE_OFF) {
		pos.x = (g_Vars.currentplayer->bondenterpos.x - g_Vars.currentplayer->bondenteraim.x) * g_Vars.currentplayer->bondentert2 + g_Vars.currentplayer->prop->pos.x;
		pos.y = (g_Vars.currentplayer->bondenterpos.y - g_Vars.currentplayer->prop->pos.y) * g_Vars.currentplayer->bondentert2 + g_Vars.currentplayer->prop->pos.y;
		pos.z = (g_Vars.currentplayer->bondenterpos.z - g_Vars.currentplayer->bondenteraim.z) * g_Vars.currentplayer->bondentert2 + g_Vars.currentplayer->prop->pos.z;

		bmove0f0cc19c(&pos);
	} else {
		bmove0f0cc19c(&g_Vars.currentplayer->prop->pos);
	}

	sp70 = g_Vars.currentplayer->speedverta / 0.7f;
	breathing = bheadGetBreathingValue();

	if (sp70 > 1.0f) {
		sp70 = 1.0f;
	} else if (sp70 < -1.0f) {
		sp70 = -1.0f;
	}

	func0f09d8dc(breathing, 0, sp70, 0.0f, g_Vars.currentplayer->speedsideways);
	handSetAdjustPos(g_Vars.currentplayer->vv_verta360 * 0.017450513318181f);
	currentPlayerUpdatePerimInfo();
	bmove0f0cb8c4(g_Vars.currentplayer);
	objectiveCheckRoomEntered(g_Vars.currentplayer->prop->rooms[0]);
	doorsCheckAutomatic();
}
