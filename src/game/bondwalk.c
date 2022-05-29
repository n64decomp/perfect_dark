#include <ultra64.h>
#include "constants.h"
#include "game/bondmove.h"
#include "game/bondwalk.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/debug.h"
#include "game/game_006900.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/objectives.h"
#include "game/bondgun.h"
#include "game/player.h"
#include "game/inv.h"
#include "game/bondhead.h"
#include "game/playermgr.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "data.h"
#include "types.h"

void bwalkInit(void)
{
	u32 prevmode = g_Vars.currentplayer->bondmovemode;
	s32 i;

	g_Vars.currentplayer->bondmovemode = MOVEMODE_WALK;
	g_Vars.currentplayer->bondonground = 0;
	g_Vars.currentplayer->tank = NULL;
	g_Vars.currentplayer->unk1af0 = NULL;
	g_Vars.currentplayer->bondonturret = false;

	g_Vars.currentplayer->swaypos = 0;
	g_Vars.currentplayer->swayoffset = 0;
	g_Vars.currentplayer->swaytarget = 0;
	g_Vars.currentplayer->swayoffset0 = 0;
	g_Vars.currentplayer->swayoffset2 = 0;

	g_Vars.currentplayer->bdeltapos.x = 0;
	g_Vars.currentplayer->bdeltapos.y = -0.0001f;
	g_Vars.currentplayer->bdeltapos.z = 0;

	g_Vars.currentplayer->isfalling = false;
	g_Vars.currentplayer->fallstart = 0;

	g_Vars.currentplayer->gunextraaimx = 0;
	g_Vars.currentplayer->gunextraaimy = 0;

	g_Vars.currentplayer->bondforcespeed.x = 0;
	g_Vars.currentplayer->bondforcespeed.y = 0;
	g_Vars.currentplayer->bondforcespeed.z = 0;

	if (prevmode != MOVEMODE_WALK && prevmode != MOVEMODE_CUTSCENE) {
		g_Vars.currentplayer->sumcrouch = 0;
		g_Vars.currentplayer->crouchheight = 0;
		g_Vars.currentplayer->crouchtime240 = 0;
		g_Vars.currentplayer->crouchfall = 0;
		g_Vars.currentplayer->crouchpos = CROUCHPOS_STAND;
		g_Vars.currentplayer->autocrouchpos = CROUCHPOS_STAND;
		g_Vars.currentplayer->crouchspeed = 0;
		g_Vars.currentplayer->crouchoffset = 0;

#if VERSION < VERSION_NTSC_1_0
		bwalkUpdateCrouchOffsetReal();
#endif

		g_Vars.currentplayer->guncloseroffset = 0;
	}

#if VERSION >= VERSION_NTSC_1_0
	bwalkUpdateCrouchOffsetReal();
#endif

	if (prevmode != MOVEMODE_GRAB && prevmode != MOVEMODE_WALK) {
		for (i = 0; i != 3; i++) {
			g_Vars.currentplayer->bondshotspeed.f[i] = 0;
		}

		g_Vars.currentplayer->speedsideways = 0;
		g_Vars.currentplayer->speedstrafe = 0;
		g_Vars.currentplayer->speedgo = 0;
		g_Vars.currentplayer->speedboost = 1;
		g_Vars.currentplayer->speedmaxtime60 = 0;
		g_Vars.currentplayer->speedforwards = 0;
		g_Vars.currentplayer->speedtheta = 0;
		g_Vars.currentplayer->speedthetacontrol = 0;
	}

	if (g_Vars.currentplayer->walkinitmove) {
		struct coord delta;
		mtx00016b58(&g_Vars.currentplayer->walkinitmtx,
				0, 0, 0,
				-g_Vars.currentplayer->bond2.unk1c.x, -g_Vars.currentplayer->bond2.unk1c.y, -g_Vars.currentplayer->bond2.unk1c.z,
				g_Vars.currentplayer->bond2.unk28.x, g_Vars.currentplayer->bond2.unk28.y, g_Vars.currentplayer->bond2.unk28.z);
		g_Vars.currentplayer->walkinitt = 0;
		g_Vars.currentplayer->walkinitt2 = 0;
		g_Vars.currentplayer->walkinitstart.x = g_Vars.currentplayer->prop->pos.x;
		g_Vars.currentplayer->walkinitstart.y = g_Vars.currentplayer->prop->pos.y;
		g_Vars.currentplayer->walkinitstart.z = g_Vars.currentplayer->prop->pos.z;

		delta.x = g_Vars.currentplayer->walkinitpos.x - g_Vars.currentplayer->prop->pos.x;
		delta.y = 0;
		delta.z = g_Vars.currentplayer->walkinitpos.z - g_Vars.currentplayer->prop->pos.z;

		propSetPerimEnabled(g_Vars.currentplayer->hoverbike, false);
		bwalkCalculateNewPositionWithPush(&delta, 0, true, 0, CDTYPE_ALL);
		propSetPerimEnabled(g_Vars.currentplayer->hoverbike, true);
	} else if (prevmode != MOVEMODE_GRAB && prevmode != MOVEMODE_WALK) {
		g_Vars.currentplayer->moveinitspeed.x = 0;
		g_Vars.currentplayer->moveinitspeed.y = 0;
		g_Vars.currentplayer->moveinitspeed.z = 0;
	}
}

void bwalkSetSwayTarget(s32 value)
{
	g_Vars.currentplayer->swaytarget = value * 75.0f;
}

void bwalkAdjustCrouchPos(s32 value)
{
	g_Vars.currentplayer->crouchpos += value;

	if (g_Vars.currentplayer->crouchpos < CROUCHPOS_SQUAT) {
		g_Vars.currentplayer->crouchpos = CROUCHPOS_SQUAT;
	} else if (g_Vars.currentplayer->crouchpos > CROUCHPOS_STAND) {
		g_Vars.currentplayer->crouchpos = CROUCHPOS_STAND;
	}
}

void bwalk0f0c3b38(struct coord *reltarget, struct defaultobj *obj)
{
	struct coord posunk;
	struct coord vector;
	struct coord tween;
	struct coord globalthinga;
	struct coord globalthingb;
	struct coord abstarget;

	abstarget.x = reltarget->x + g_Vars.currentplayer->prop->pos.x;
	abstarget.y = g_Vars.currentplayer->prop->pos.y;
	abstarget.z = reltarget->z + g_Vars.currentplayer->prop->pos.z;

#if VERSION >= VERSION_NTSC_1_0
	cd00024e4c(&globalthinga, &globalthingb, 223, "bondwalk.c");
#else
	cd00024e4c(&globalthinga, &globalthingb, 221, "bondwalk.c");
#endif

	vector.x = globalthingb.z - globalthinga.z;
	vector.y = 0;
	vector.z = globalthinga.x - globalthingb.x;

	if (vector.f[0] != 0 || vector.f[2] != 0) {
		guNormalize(&vector.x, &vector.y, &vector.z);
	} else {
		vector.z = 1;
	}

	func0f02e3dc(&globalthinga, &globalthingb, &abstarget, &vector, &posunk);

	tween.x = (abstarget.x - g_Vars.currentplayer->prop->pos.x) / g_Vars.lvupdate240freal;
	tween.y = 0;
	tween.z = (abstarget.z - g_Vars.currentplayer->prop->pos.z) / g_Vars.lvupdate240freal;

	func0f082e84(obj, &posunk, &vector, &tween, false);
}

/**
 * Attempt to move the current player up vertically by the given amount.
 *
 * Collision checks are done for the new location, and if successful the
 * player's positional values are updated.
 *
 * The function is called with amount = 0 when attempting to stand up from a
 * crouch, after increasing the player's bbox to the standing size.
 */
s32 bwalkTryMoveUpwards(f32 amount)
{
	bool result;
	struct coord newpos;
	s16 rooms[8];
	u32 stack;
	u32 types;
	f32 ymax;
	f32 ymin;
	f32 width;

	if (g_Vars.currentplayer->floorflags & TILEFLAG_0100) {
		g_Vars.enableslopes = false;
	} else {
		g_Vars.enableslopes = true;
	}

	newpos.x = g_Vars.currentplayer->prop->pos.x;
	newpos.y = g_Vars.currentplayer->prop->pos.y + amount;
	newpos.z = g_Vars.currentplayer->prop->pos.z;

	types = g_Vars.bondcollisions ? CDTYPE_ALL : CDTYPE_BG;

	playerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);
	func0f065e74(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, &newpos, rooms);
	bmove0f0cb79c(g_Vars.currentplayer, &newpos, rooms);
	propSetPerimEnabled(g_Vars.currentplayer->prop, false);

	ymin -= 0.1f;

	result = cdTestVolume(&newpos, width, rooms, types, 1,
			ymax - g_Vars.currentplayer->prop->pos.y,
			ymin - g_Vars.currentplayer->prop->pos.y);

	propSetPerimEnabled(g_Vars.currentplayer->prop, true);

	if (result == CDRESULT_NOCOLLISION) {
		g_Vars.currentplayer->prop->pos.y = newpos.y;
		propDeregisterRooms(g_Vars.currentplayer->prop);
		roomsCopy(rooms, g_Vars.currentplayer->prop->rooms);
	}

	g_Vars.enableslopes = true;

	return result;
}

#if VERSION >= VERSION_NTSC_1_0
bool bwalkCalculateNewPosition(struct coord *vel, f32 rotateamount, bool apply, f32 extrawidth, s32 checktypes)
{
	s32 result = CDRESULT_NOCOLLISION;
	f32 halfwidth;
	struct coord dstpos;
	s16 dstrooms[8];
	bool copyrooms = false;
	s16 sp64[22];
	s32 types;
	f32 ymax;
	f32 ymin;
	f32 width;
	f32 xdiff;
	f32 zdiff;
	u32 stack;

	if (g_Vars.currentplayer->floorflags & TILEFLAG_0100) {
		g_Vars.enableslopes = false;
	} else {
		g_Vars.enableslopes = true;
	}

	dstpos.x = g_Vars.currentplayer->prop->pos.x;
	dstpos.y = g_Vars.currentplayer->prop->pos.y;
	dstpos.z = g_Vars.currentplayer->prop->pos.z;

	if (vel->x || vel->y || vel->z) {
		if (g_Vars.currentplayer->tank) {
			propSetPerimEnabled(g_Vars.currentplayer->tank, false);
		}

		propSetPerimEnabled(g_Vars.currentplayer->prop, false);

		dstpos.x += vel->x;
		dstpos.y += vel->y;
		dstpos.z += vel->z;

		types = g_Vars.bondcollisions ? checktypes : CDTYPE_BG;

		playerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);
		width += extrawidth;

		func0f065dfc(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms,
				&dstpos, dstrooms, sp64, 20);
		bmove0f0cb79c(g_Vars.currentplayer, &dstpos, dstrooms);

		copyrooms = true;

		// Check if the player is moving at least half their width along the
		// X or Z axis in a single frame. If less, only do a collision check for
		// the dst position. If more, do a halfway check too?
		xdiff = dstpos.x - g_Vars.currentplayer->prop->pos.x;
		zdiff = dstpos.z - g_Vars.currentplayer->prop->pos.z;
		halfwidth = width * 0.5f;

		if (xdiff > halfwidth || zdiff > halfwidth || xdiff < -halfwidth || zdiff < -halfwidth) {
			result = cdTestAToB3(&g_Vars.currentplayer->prop->pos,
					g_Vars.currentplayer->prop->rooms,
					&dstpos, dstrooms, width, types, 1,
					ymax - g_Vars.currentplayer->prop->pos.y,
					ymin - g_Vars.currentplayer->prop->pos.y);

			if (result == CDRESULT_NOCOLLISION) {
				result = cdTestAToB1(&g_Vars.currentplayer->prop->pos,
						&dstpos, width, dstrooms, types, 1,
						ymax - g_Vars.currentplayer->prop->pos.y,
						ymin - g_Vars.currentplayer->prop->pos.y);
			}
		} else {
			result = cdTestAToB1(&g_Vars.currentplayer->prop->pos,
					&dstpos, width, sp64, types, 1,
					ymax - g_Vars.currentplayer->prop->pos.y,
					ymin - g_Vars.currentplayer->prop->pos.y);
		}

		propSetPerimEnabled(g_Vars.currentplayer->prop, true);

		if (g_Vars.currentplayer->tank) {
			propSetPerimEnabled(g_Vars.currentplayer->tank, true);
		}
	}

	if (result == CDRESULT_NOCOLLISION && apply) {
		f32 angle = g_Vars.currentplayer->vv_theta + (rotateamount * 360) / M_BADTAU;

		while (angle < 0) {
			angle += 360;
		}

		while (angle >= 360) {
			angle -= 360;
		}

		g_Vars.currentplayer->vv_theta = angle;

		g_Vars.currentplayer->prop->pos.x = dstpos.x;
		g_Vars.currentplayer->prop->pos.y = dstpos.y;
		g_Vars.currentplayer->prop->pos.z = dstpos.z;

		if (copyrooms) {
			propDeregisterRooms(g_Vars.currentplayer->prop);
			roomsCopy(dstrooms, g_Vars.currentplayer->prop->rooms);
		}
	}

	g_Vars.enableslopes = true;

	return result;
}
#else
GLOBAL_ASM(
glabel bwalkCalculateNewPosition
.late_rodata
glabel var7f1a7ad8nb
.word 0x40c907a9
.text
/*  f0c19d0:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f0c19d4:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0c19d8:	3c10800a */ 	lui	$s0,0x800a
/*  f0c19dc:	2610e6c0 */ 	addiu	$s0,$s0,-6464
/*  f0c19e0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c19e4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0c19e8:	afa400b8 */ 	sw	$a0,0xb8($sp)
/*  f0c19ec:	afa500bc */ 	sw	$a1,0xbc($sp)
/*  f0c19f0:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f0c19f4:	afa700c4 */ 	sw	$a3,0xc4($sp)
/*  f0c19f8:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f0c19fc:	944e161c */ 	lhu	$t6,0x161c($v0)
/*  f0c1a00:	00803825 */ 	or	$a3,$a0,$zero
/*  f0c1a04:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c1a08:	31cf0100 */ 	andi	$t7,$t6,0x100
/*  f0c1a0c:	11e00003 */ 	beqz	$t7,.NB0f0c1a1c
/*  f0c1a10:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0c1a14:	10000002 */ 	beqz	$zero,.NB0f0c1a20
/*  f0c1a18:	ae00032c */ 	sw	$zero,0x32c($s0)
.NB0f0c1a1c:
/*  f0c1a1c:	ae18032c */ 	sw	$t8,0x32c($s0)
.NB0f0c1a20:
/*  f0c1a20:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f0c1a24:	44808000 */ 	mtc1	$zero,$f16
/*  f0c1a28:	c7240008 */ 	lwc1	$f4,0x8($t9)
/*  f0c1a2c:	e7a400a4 */ 	swc1	$f4,0xa4($sp)
/*  f0c1a30:	8c4800bc */ 	lw	$t0,0xbc($v0)
/*  f0c1a34:	c506000c */ 	lwc1	$f6,0xc($t0)
/*  f0c1a38:	e7a600a8 */ 	swc1	$f6,0xa8($sp)
/*  f0c1a3c:	8c4900bc */ 	lw	$t1,0xbc($v0)
/*  f0c1a40:	c5280010 */ 	lwc1	$f8,0x10($t1)
/*  f0c1a44:	e7a800ac */ 	swc1	$f8,0xac($sp)
/*  f0c1a48:	c4ea0000 */ 	lwc1	$f10,0x0($a3)
/*  f0c1a4c:	460a8032 */ 	c.eq.s	$f16,$f10
/*  f0c1a50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1a54:	4502000c */ 	bc1fl	.NB0f0c1a88
/*  f0c1a58:	8c441aec */ 	lw	$a0,0x1aec($v0)
/*  f0c1a5c:	c4f20004 */ 	lwc1	$f18,0x4($a3)
/*  f0c1a60:	46128032 */ 	c.eq.s	$f16,$f18
/*  f0c1a64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1a68:	45020007 */ 	bc1fl	.NB0f0c1a88
/*  f0c1a6c:	8c441aec */ 	lw	$a0,0x1aec($v0)
/*  f0c1a70:	c4e40008 */ 	lwc1	$f4,0x8($a3)
/*  f0c1a74:	46048032 */ 	c.eq.s	$f16,$f4
/*  f0c1a78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1a7c:	450300b4 */ 	bc1tl	.NB0f0c1d50
/*  f0c1a80:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c1a84:	8c441aec */ 	lw	$a0,0x1aec($v0)
.NB0f0c1a88:
/*  f0c1a88:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c1a8c:	50800006 */ 	beqzl	$a0,.NB0f0c1aa8
/*  f0c1a90:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f0c1a94:	0fc18cfb */ 	jal	propSetPerimEnabled
/*  f0c1a98:	afa700b8 */ 	sw	$a3,0xb8($sp)
/*  f0c1a9c:	8fa700b8 */ 	lw	$a3,0xb8($sp)
/*  f0c1aa0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c1aa4:	8c4400bc */ 	lw	$a0,0xbc($v0)
.NB0f0c1aa8:
/*  f0c1aa8:	afa700b8 */ 	sw	$a3,0xb8($sp)
/*  f0c1aac:	0fc18cfb */ 	jal	propSetPerimEnabled
/*  f0c1ab0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c1ab4:	8fa700b8 */ 	lw	$a3,0xb8($sp)
/*  f0c1ab8:	c7a600a4 */ 	lwc1	$f6,0xa4($sp)
/*  f0c1abc:	c7b200a8 */ 	lwc1	$f18,0xa8($sp)
/*  f0c1ac0:	c4e80000 */ 	lwc1	$f8,0x0($a3)
/*  f0c1ac4:	8e0a0328 */ 	lw	$t2,0x328($s0)
/*  f0c1ac8:	240c0020 */ 	addiu	$t4,$zero,0x20
/*  f0c1acc:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0c1ad0:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f0c1ad4:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*  f0c1ad8:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0c1adc:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f0c1ae0:	c4e40004 */ 	lwc1	$f4,0x4($a3)
/*  f0c1ae4:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f0c1ae8:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0c1aec:	e7a600a8 */ 	swc1	$f6,0xa8($sp)
/*  f0c1af0:	c4ea0008 */ 	lwc1	$f10,0x8($a3)
/*  f0c1af4:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f0c1af8:	11400003 */ 	beqz	$t2,.NB0f0c1b08
/*  f0c1afc:	e7b200ac */ 	swc1	$f18,0xac($sp)
/*  f0c1b00:	10000002 */ 	beqz	$zero,.NB0f0c1b0c
/*  f0c1b04:	afab0060 */ 	sw	$t3,0x60($sp)
.NB0f0c1b08:
/*  f0c1b08:	afac0060 */ 	sw	$t4,0x60($sp)
.NB0f0c1b0c:
/*  f0c1b0c:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c1b10:	27a70058 */ 	addiu	$a3,$sp,0x58
/*  f0c1b14:	0fc2ff20 */ 	jal	playerGetBbox
/*  f0c1b18:	8da400bc */ 	lw	$a0,0xbc($t5)
/*  f0c1b1c:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f0c1b20:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0c1b24:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c1b28:	27af0064 */ 	addiu	$t7,$sp,0x64
/*  f0c1b2c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0c1b30:	24180014 */ 	addiu	$t8,$zero,0x14
/*  f0c1b34:	27a600a4 */ 	addiu	$a2,$sp,0xa4
/*  f0c1b38:	27a70094 */ 	addiu	$a3,$sp,0x94
/*  f0c1b3c:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f0c1b40:	8dc200bc */ 	lw	$v0,0xbc($t6)
/*  f0c1b44:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0c1b48:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0c1b4c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c1b50:	0fc19419 */ 	jal	func0f065dfc
/*  f0c1b54:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0c1b58:	87b90094 */ 	lh	$t9,0x94($sp)
/*  f0c1b5c:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0c1b60:	240affff */ 	addiu	$t2,$zero,-1
/*  f0c1b64:	10b9000e */ 	beq	$a1,$t9,.NB0f0c1ba0
/*  f0c1b68:	27a60094 */ 	addiu	$a2,$sp,0x94
/*  f0c1b6c:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0c1b70:	27a20094 */ 	addiu	$v0,$sp,0x94
/*  f0c1b74:	84430000 */ 	lh	$v1,0x0($v0)
/*  f0c1b78:	850419b0 */ 	lh	$a0,0x19b0($t0)
.NB0f0c1b7c:
/*  f0c1b7c:	54830005 */ 	bnel	$a0,$v1,.NB0f0c1b94
/*  f0c1b80:	84430002 */ 	lh	$v1,0x2($v0)
/*  f0c1b84:	a7a40094 */ 	sh	$a0,0x94($sp)
/*  f0c1b88:	10000005 */ 	beqz	$zero,.NB0f0c1ba0
/*  f0c1b8c:	a7aa0096 */ 	sh	$t2,0x96($sp)
/*  f0c1b90:	84430002 */ 	lh	$v1,0x2($v0)
.NB0f0c1b94:
/*  f0c1b94:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0c1b98:	14a3fff8 */ 	bne	$a1,$v1,.NB0f0c1b7c
/*  f0c1b9c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c1ba0:
/*  f0c1ba0:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0c1ba4:	0fc323f3 */ 	jal	bmove0f0cb79c
/*  f0c1ba8:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0c1bac:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c1bb0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0c1bb4:	afab0090 */ 	sw	$t3,0x90($sp)
/*  f0c1bb8:	8d8200bc */ 	lw	$v0,0xbc($t4)
/*  f0c1bbc:	c7aa00a4 */ 	lwc1	$f10,0xa4($sp)
/*  f0c1bc0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c1bc4:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f0c1bc8:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f0c1bcc:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f0c1bd0:	46125081 */ 	sub.s	$f2,$f10,$f18
/*  f0c1bd4:	44815000 */ 	mtc1	$at,$f10
/*  f0c1bd8:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0c1bdc:	c7b20054 */ 	lwc1	$f18,0x54($sp)
/*  f0c1be0:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f0c1be4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0c1be8:	46062301 */ 	sub.s	$f12,$f4,$f6
/*  f0c1bec:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c1bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1bf4:	45030010 */ 	bc1tl	.NB0f0c1c38
/*  f0c1bf8:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0c1bfc:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0c1c00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1c04:	4503000c */ 	bc1tl	.NB0f0c1c38
/*  f0c1c08:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0c1c0c:	46000387 */ 	neg.s	$f14,$f0
/*  f0c1c10:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0c1c14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1c18:	45030007 */ 	bc1tl	.NB0f0c1c38
/*  f0c1c1c:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0c1c20:	460e603c */ 	c.lt.s	$f12,$f14
/*  f0c1c24:	8fa80060 */ 	lw	$t0,0x60($sp)
/*  f0c1c28:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0c1c2c:	45020029 */ 	bc1fl	.NB0f0c1cd4
/*  f0c1c30:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0c1c34:	8fad0060 */ 	lw	$t5,0x60($sp)
.NB0f0c1c38:
/*  f0c1c38:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0c1c3c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0c1c40:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0c1c44:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0c1c48:	c7a4005c */ 	lwc1	$f4,0x5c($sp)
/*  f0c1c4c:	c7a80058 */ 	lwc1	$f8,0x58($sp)
/*  f0c1c50:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c1c54:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0c1c58:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0c1c5c:	27a600a4 */ 	addiu	$a2,$sp,0xa4
/*  f0c1c60:	46004281 */ 	sub.s	$f10,$f8,$f0
/*  f0c1c64:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0c1c68:	27a70094 */ 	addiu	$a3,$sp,0x94
/*  f0c1c6c:	0c00bb59 */ 	jal	cdTestAToB3
/*  f0c1c70:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*  f0c1c74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c1c78:	14410024 */ 	bne	$v0,$at,.NB0f0c1d0c
/*  f0c1c7c:	00401825 */ 	or	$v1,$v0,$zero
/*  f0c1c80:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c1c84:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0c1c88:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c1c8c:	8de200bc */ 	lw	$v0,0xbc($t7)
/*  f0c1c90:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0c1c94:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0c1c98:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0c1c9c:	c7b2005c */ 	lwc1	$f18,0x5c($sp)
/*  f0c1ca0:	c7a60058 */ 	lwc1	$f6,0x58($sp)
/*  f0c1ca4:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0c1ca8:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f0c1cac:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c1cb0:	27a70094 */ 	addiu	$a3,$sp,0x94
/*  f0c1cb4:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0c1cb8:	e7a40018 */ 	swc1	$f4,0x18($sp)
/*  f0c1cbc:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c1cc0:	0c00af7e */ 	jal	cdTestAToB1
/*  f0c1cc4:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*  f0c1cc8:	10000010 */ 	beqz	$zero,.NB0f0c1d0c
/*  f0c1ccc:	00401825 */ 	or	$v1,$v0,$zero
/*  f0c1cd0:	afa80010 */ 	sw	$t0,0x10($sp)
.NB0f0c1cd4:
/*  f0c1cd4:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0c1cd8:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0c1cdc:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f0c1ce0:	c7a40058 */ 	lwc1	$f4,0x58($sp)
/*  f0c1ce4:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c1ce8:	46005481 */ 	sub.s	$f18,$f10,$f0
/*  f0c1cec:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0c1cf0:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c1cf4:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0c1cf8:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f0c1cfc:	27a70064 */ 	addiu	$a3,$sp,0x64
/*  f0c1d00:	0c00af7e */ 	jal	cdTestAToB1
/*  f0c1d04:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0c1d08:	00401825 */ 	or	$v1,$v0,$zero
.NB0f0c1d0c:
/*  f0c1d0c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c1d10:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c1d14:	8d4400bc */ 	lw	$a0,0xbc($t2)
/*  f0c1d18:	0fc18cfb */ 	jal	propSetPerimEnabled
/*  f0c1d1c:	afa300b4 */ 	sw	$v1,0xb4($sp)
/*  f0c1d20:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c1d24:	44808000 */ 	mtc1	$zero,$f16
/*  f0c1d28:	8fa300b4 */ 	lw	$v1,0xb4($sp)
/*  f0c1d2c:	8d641aec */ 	lw	$a0,0x1aec($t3)
/*  f0c1d30:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c1d34:	50800006 */ 	beqzl	$a0,.NB0f0c1d50
/*  f0c1d38:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c1d3c:	0fc18cfb */ 	jal	propSetPerimEnabled
/*  f0c1d40:	afa300b4 */ 	sw	$v1,0xb4($sp)
/*  f0c1d44:	44808000 */ 	mtc1	$zero,$f16
/*  f0c1d48:	8fa300b4 */ 	lw	$v1,0xb4($sp)
/*  f0c1d4c:	24010001 */ 	addiu	$at,$zero,0x1
.NB0f0c1d50:
/*  f0c1d50:	14610038 */ 	bne	$v1,$at,.NB0f0c1e34
/*  f0c1d54:	8fac00c0 */ 	lw	$t4,0xc0($sp)
/*  f0c1d58:	11800036 */ 	beqz	$t4,.NB0f0c1e34
/*  f0c1d5c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0c1d60:	44811000 */ 	mtc1	$at,$f2
/*  f0c1d64:	c7a800bc */ 	lwc1	$f8,0xbc($sp)
/*  f0c1d68:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c1d6c:	c4327ad8 */ 	lwc1	$f18,0x7ad8($at)
/*  f0c1d70:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0c1d74:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c1d78:	c4460144 */ 	lwc1	$f6,0x144($v0)
/*  f0c1d7c:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f0c1d80:	46043000 */ 	add.s	$f0,$f6,$f4
/*  f0c1d84:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0c1d88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1d8c:	45020007 */ 	bc1fl	.NB0f0c1dac
/*  f0c1d90:	4600103e */ 	c.le.s	$f2,$f0
/*  f0c1d94:	46020000 */ 	add.s	$f0,$f0,$f2
.NB0f0c1d98:
/*  f0c1d98:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0c1d9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1da0:	4503fffd */ 	bc1tl	.NB0f0c1d98
/*  f0c1da4:	46020000 */ 	add.s	$f0,$f0,$f2
/*  f0c1da8:	4600103e */ 	c.le.s	$f2,$f0
.NB0f0c1dac:
/*  f0c1dac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1db0:	45020007 */ 	bc1fl	.NB0f0c1dd0
/*  f0c1db4:	e4400144 */ 	swc1	$f0,0x144($v0)
/*  f0c1db8:	46020001 */ 	sub.s	$f0,$f0,$f2
.NB0f0c1dbc:
/*  f0c1dbc:	4600103e */ 	c.le.s	$f2,$f0
/*  f0c1dc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1dc4:	4503fffd */ 	bc1tl	.NB0f0c1dbc
/*  f0c1dc8:	46020001 */ 	sub.s	$f0,$f0,$f2
/*  f0c1dcc:	e4400144 */ 	swc1	$f0,0x144($v0)
.NB0f0c1dd0:
/*  f0c1dd0:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c1dd4:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f0c1dd8:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f0c1ddc:	e5c80008 */ 	swc1	$f8,0x8($t6)
/*  f0c1de0:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c1de4:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f0c1de8:	8df800bc */ 	lw	$t8,0xbc($t7)
/*  f0c1dec:	e70a000c */ 	swc1	$f10,0xc($t8)
/*  f0c1df0:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c1df4:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0c1df8:	8f2800bc */ 	lw	$t0,0xbc($t9)
/*  f0c1dfc:	e5120010 */ 	swc1	$f18,0x10($t0)
/*  f0c1e00:	8fa90090 */ 	lw	$t1,0x90($sp)
/*  f0c1e04:	5120000c */ 	beqzl	$t1,.NB0f0c1e38
/*  f0c1e08:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0c1e0c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c1e10:	8d4400bc */ 	lw	$a0,0xbc($t2)
/*  f0c1e14:	0fc193ab */ 	jal	propDeregisterRooms
/*  f0c1e18:	afa300b4 */ 	sw	$v1,0xb4($sp)
/*  f0c1e1c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c1e20:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f0c1e24:	8d6500bc */ 	lw	$a1,0xbc($t3)
/*  f0c1e28:	0fc19283 */ 	jal	roomsCopy
/*  f0c1e2c:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0c1e30:	8fa300b4 */ 	lw	$v1,0xb4($sp)
.NB0f0c1e34:
/*  f0c1e34:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f0c1e38:
/*  f0c1e38:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0c1e3c:	ae0c032c */ 	sw	$t4,0x32c($s0)
/*  f0c1e40:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0c1e44:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f0c1e48:	03e00008 */ 	jr	$ra
/*  f0c1e4c:	00601025 */ 	or	$v0,$v1,$zero
);
#endif

bool bwalkCalculateNewPositionWithPush(struct coord *delta, f32 rotateamount, bool apply, f32 extrawidth, s32 types)
{
	s32 result = bwalkCalculateNewPosition(delta, rotateamount, apply, extrawidth, types);

	if (result != CDRESULT_NOCOLLISION) {
		struct prop *obstacle = cdGetObstacle();

		if (obstacle && g_Vars.lvupdate240 > 0) {
			if (obstacle->type == PROPTYPE_DOOR) {
				struct doorobj *door = obstacle->door;
				struct coord sp90;
				struct coord sp84;
				struct coord sp78;

				if (door->doorflags & DOORFLAG_DAMAGEONCONTACT) {
					if (!g_Vars.currentplayer->isdead) {
#if VERSION >= VERSION_NTSC_1_0
						cd00024e4c(&sp84, &sp78, 465, "bondwalk.c");
#else
						cd00024e4c(&sp84, &sp78, 460, "bondwalk.c");
#endif

						sp90.x = sp78.f[2] - sp84.f[2];
						sp90.y = 0;
						sp90.z = sp84.f[0] - sp78.f[0];

						if (sp90.f[0] || sp90.f[2]) {
							guNormalize(&sp90.x, &sp90.y, &sp90.z);
						} else {
							sp90.z = 1;
						}

						chrDamageByLaser(g_Vars.currentplayer->prop->chr, 0.4f, &sp90, 0, g_Vars.currentplayer->prop);

						// Laser zap sound
						sndStart(var80095200, SFX_PICKUP_LASER, 0, -1, -1, -1, -1, -1);
					}
				}
			} else if (obstacle->type == PROPTYPE_CHR) {
				struct chrdata *chr = obstacle->chr;
				struct coord newpos;
				s16 newrooms[8];
				f32 movingdist;
				f32 xdist;
				f32 zdist;
				f32 disttochr;
				bool canpush = false;

				if (g_Vars.normmplayerisrunning) {
					if (chrCompareTeams(g_Vars.currentplayer->prop->chr, chr, COMPARE_FRIENDS)) {
						// AI bot on same team
						canpush = true;
					}
				} else if (chr->chrflags & CHRCFLAG_PUSHABLE) {
					if (g_Vars.antiplayernum < 0
							|| g_Vars.currentplayer != g_Vars.anti
							|| (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE) == 0) {
						canpush = true;
					}
				}

				if (canpush) {
					movingdist = sqrtf(delta->f[0] * delta->f[0] + delta->f[2] * delta->f[2]) / LVUPDATE240FREAL();

					xdist = obstacle->pos.x - g_Vars.currentplayer->prop->pos.x;
					zdist = obstacle->pos.z - g_Vars.currentplayer->prop->pos.z;

					if (xdist || zdist) {
						disttochr = sqrtf(xdist * xdist + zdist * zdist);

						if (disttochr > 0) {
							disttochr = movingdist / disttochr;

							xdist *= disttochr;
							zdist *= disttochr;

							chr->pushspeed[0] = 0.5f * xdist;
							chr->pushspeed[1] = 0.5f * zdist;

							newpos.x = obstacle->pos.x + chr->pushspeed[0] * LVUPDATE240FREAL();
							newpos.y = obstacle->pos.y;
							newpos.z = obstacle->pos.z + chr->pushspeed[1] * LVUPDATE240FREAL();

							chrCalculatePushPos(chr, &newpos, newrooms, false);

							obstacle->pos.x = newpos.x;
							obstacle->pos.y = newpos.y;
							obstacle->pos.z = newpos.z;

							propDeregisterRooms(obstacle);
							roomsCopy(newrooms, obstacle->rooms);
							chr0f0220ac(chr);
							modelSetRootPosition(chr->model, &newpos);

							result = bwalkCalculateNewPosition(delta, rotateamount, apply, extrawidth, types);
						}
					}
				}
			} else if (obstacle->type == PROPTYPE_PLAYER) {
				// empty
			} else if (obstacle->type == PROPTYPE_OBJ) {
				struct defaultobj *obj = obstacle->obj;
				bool dothething;

				if ((obj->hidden & OBJHFLAG_MOUNTED) == 0 && (obj->hidden & OBJHFLAG_GRABBED) == 0) {
					if (g_Vars.currentplayer->unk1af0 == 0 && obj->type == OBJTYPE_TANK) {
						g_Vars.currentplayer->tank = obstacle;
					} else if (obj->flags3 & OBJFLAG3_PUSHABLE) {
						g_Vars.currentplayer->speedmaxtime60 = 0;
						dothething = true;

						if ((obj->hidden & OBJHFLAG_AIRBORNE) &&
								(obj->projectile->flags & PROJECTILEFLAG_00001000)) {
							dothething = false;
						}

						if (dothething) {
							bwalk0f0c3b38(delta, obj);

							if (obj->hidden & OBJHFLAG_AIRBORNE && (obj->projectile->flags & PROJECTILEFLAG_00000800)) {
								bool somevalue;
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
									result = bwalkCalculateNewPosition(delta, rotateamount, apply, extrawidth, types);
								}
							}
						}
					}
				}
			}
		}
	}

	return result;
}

s32 bwalk0f0c4764(struct coord *delta, struct coord *arg1, struct coord *arg2, s32 types)
{
	s32 result = bwalkCalculateNewPositionWithPush(delta, 0, true, 0, types);

	if (result == CDRESULT_COLLISION) {
#if VERSION >= VERSION_NTSC_1_0
		cd00024e4c(arg1, arg2, 607, "bondwalk.c");
#else
		cd00024e4c(arg1, arg2, 602, "bondwalk.c");
#endif
	}

	return result;
}

s32 bwalk0f0c47d0(struct coord *a, struct coord *b, struct coord *c,
		struct coord *d, struct coord *e, s32 types)
{
	struct coord quarter;
	bool result;

	if (cd00024ea4()) {
		f32 mult = cd00024e98();
		quarter.x = a->x * mult * 0.25f;
		quarter.y = a->y * mult * 0.25f;
		quarter.z = a->z * mult * 0.25f;
		result = bwalkCalculateNewPositionWithPush(&quarter, 0, true, 0, types);

		if (result == CDRESULT_NOCOLLISION) {
			return CDRESULT_NOCOLLISION;
		}

		if (result == CDRESULT_COLLISION) {
#if VERSION >= VERSION_NTSC_1_0
			cd00024e4c(d, e, 635, "bondwalk.c");
#else
			cd00024e4c(d, e, 630, "bondwalk.c");
#endif

			if (b->x != d->x
					|| b->y != d->y
					|| b->z != d->z
					|| c->x != e->x
					|| c->y != e->y
					|| c->z != e->z) {
				return CDRESULT_COLLISION;
			}
		}
	}

	return CDRESULT_ERROR;
}

s32 bwalk0f0c494c(struct coord *a, struct coord *b, struct coord *c, s32 types)
{
	if (b->f[0] != c->f[0] || b->f[2] != c->f[2]) {
		f32 tmp;
		struct coord sp38;
		struct coord sp2c;

		sp38.x = c->x - b->x;
		sp38.y = 0;
		sp38.z = c->z - b->z;

		tmp = sqrtf(sp38.f[0] * sp38.f[0] + sp38.f[2] * sp38.f[2]);

		sp38.x *= 1.0f / tmp;
		sp38.z *= 1.0f / tmp;

		tmp = a->f[0] * sp38.f[0] + a->f[2] * sp38.f[2];

		sp2c.x = sp38.x * tmp;
		sp2c.y = 0;
		sp2c.z = sp38.z * tmp;

		return bwalkCalculateNewPositionWithPush(&sp2c, 0, true, 0, types);
	}

	return -1;
}

s32 bwalk0f0c4a5c(struct coord *arg0, struct coord *arg1, struct coord *arg2, s32 types)
{
	struct coord sp34;
	struct coord sp28;
	f32 ymax;
	f32 ymin;
	f32 tmp;
	f32 width;

	playerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);

	sp34.x = arg1->x - (g_Vars.currentplayer->prop->pos.x + arg0->f[0]);
	sp34.z = arg1->z - (g_Vars.currentplayer->prop->pos.z + arg0->f[2]);

	if (sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2] <= width * width) {
		if (arg1->f[0] != g_Vars.currentplayer->prop->pos.f[0] || arg1->f[2] != g_Vars.currentplayer->prop->pos.f[2]) {
			sp34.x = -(arg1->z - g_Vars.currentplayer->prop->pos.z);
			sp34.y = 0;
			sp34.z = arg1->x - g_Vars.currentplayer->prop->pos.x;

			tmp = sqrtf(sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2]);

			sp34.x = sp34.f[0] * (1.0f / tmp);
			sp34.z = sp34.f[2] * (1.0f / tmp);

			tmp = arg0->f[0] * sp34.f[0] + arg0->f[2] * sp34.f[2];

			sp34.x = sp34.x * tmp;
			sp34.z = sp34.z * tmp;

			sp28.x = sp34.x;
			sp28.y = 0;
			sp28.z = sp34.z;

			if (bwalkCalculateNewPositionWithPush(&sp28, 0, true, 0, types) == CDRESULT_NOCOLLISION) {
				return true;
			}
		}
	} else {
		sp34.x = arg2->x - (g_Vars.currentplayer->prop->pos.x + arg0->f[0]);
		sp34.z = arg2->z - (g_Vars.currentplayer->prop->pos.z + arg0->f[2]);

		if (sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2] <= width * width) {
			if (arg2->f[0] != g_Vars.currentplayer->prop->pos.f[0] || arg2->f[2] != g_Vars.currentplayer->prop->pos.f[2]) {
				sp34.x = -(arg2->z - g_Vars.currentplayer->prop->pos.z);
				sp34.y = 0;
				sp34.z = arg2->x - g_Vars.currentplayer->prop->pos.x;

				tmp = sqrtf(sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2]);

				sp34.x = sp34.f[0] * (1.0f / tmp);
				sp34.z = sp34.f[2] * (1.0f / tmp);

				tmp = arg0->f[0] * sp34.f[0] + arg0->f[2] * sp34.f[2];

				sp34.x = sp34.x * tmp;
				sp34.z = sp34.z * tmp;

				sp28.x = sp34.x;
				sp28.y = 0;
				sp28.z = sp34.z;

				if (bwalkCalculateNewPositionWithPush(&sp28, 0, true, 0, types) == CDRESULT_NOCOLLISION) {
					return true;
				}
			}
		}
	}

	return false;
}

void bwalk0f0c4d98(void)
{
	// empty
}

void bwalkUpdateSpeedSideways(f32 targetspeed, f32 accelspeed, s32 mult)
{
	if (g_Vars.normmplayerisrunning) {
		targetspeed = (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.unk1c + 25.0f) / 100 * targetspeed;
	}

	if (g_Vars.currentplayer->speedstrafe > targetspeed) {
		g_Vars.currentplayer->speedstrafe -= PALUPF(accelspeed * mult);

		if (g_Vars.currentplayer->speedstrafe < targetspeed) {
			g_Vars.currentplayer->speedstrafe = targetspeed;
		}
	} else if (g_Vars.currentplayer->speedstrafe < targetspeed) {
		g_Vars.currentplayer->speedstrafe += PALUPF(accelspeed * mult);

		if (g_Vars.currentplayer->speedstrafe > targetspeed) {
			g_Vars.currentplayer->speedstrafe = targetspeed;
		}
	}

	g_Vars.currentplayer->speedsideways = g_Vars.currentplayer->speedstrafe;
}

void bwalkUpdateSpeedForwards(f32 targetspeed, f32 accelspeed)
{
	if (g_Vars.normmplayerisrunning) {
		targetspeed = (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.unk1c + 25.0f) / 100 * targetspeed;
	}

	if (g_Vars.currentplayer->speedgo < targetspeed) {
		g_Vars.currentplayer->speedgo += accelspeed * g_Vars.lvupdate240freal;

		if (g_Vars.currentplayer->speedgo > targetspeed) {
			g_Vars.currentplayer->speedgo = targetspeed;
		}
	} else if (g_Vars.currentplayer->speedgo > targetspeed) {
		g_Vars.currentplayer->speedgo -= accelspeed * g_Vars.lvupdate240freal;

		if (g_Vars.currentplayer->speedgo < targetspeed) {
			g_Vars.currentplayer->speedgo = targetspeed;
		}
	}

	g_Vars.currentplayer->speedforwards = g_Vars.currentplayer->speedgo;
}

#if VERSION >= VERSION_NTSC_1_0
void bwalkUpdateVertical(void)
{
	s32 i;
	struct defaultobj *obj;
	f32 width;
	f32 ymax;
	f32 ymin;
	f32 ground;
	bool onladder;
	bool onladder2 = false;
	s16 rooms[8];
	struct coord testpos;
	struct coord newpos;
	s16 newrooms[8];
	s32 newinlift;
	struct prop *lift = NULL;
	f32 sumground;
	f32 moveamount;
	f32 clearance;
	f32 limit;
	f32 amount;
	f32 newmanground;
	f32 fallspeed;
	f32 multiplier;
	f32 newfallspeed;
	struct prop *prop;

	playerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);

	// Maybe reset counter-op's width - not sure why
	// Maybe it gets set to 0 when they die?
	if (g_Vars.antiplayernum >= 0
			&& g_Vars.currentplayer == g_Vars.anti
			&& g_Vars.currentplayer->bond2.width != 30
			&& cdTestVolume(&g_Vars.currentplayer->prop->pos, 30, g_Vars.currentplayer->prop->rooms, CDTYPE_ALL, 1, ymax - g_Vars.currentplayer->prop->pos.y, ymin - g_Vars.currentplayer->prop->pos.y)) {
		g_Vars.currentplayer->prop->chr->chrwidth = 30;
		g_Vars.currentplayer->bond2.width = 30;
		width = 30;
	}

	// Determine if player is on a ladder
	// If this comes up false, a second check is done... maybe checking if the
	// player is touching a ladder from a room which shares the same coordinate
	// space?
	onladder = cd00029ffc(&g_Vars.currentplayer->prop->pos,
			width * 1.2f, ymax - g_Vars.currentplayer->prop->pos.y,
			g_Vars.currentplayer->vv_manground - g_Vars.currentplayer->prop->pos.y + 1,
			g_Vars.currentplayer->prop->rooms, 0x8040, &g_Vars.currentplayer->laddernormal);

	if (!onladder) {
		testpos.x = g_Vars.currentplayer->prop->pos.x;
		testpos.y = g_Vars.currentplayer->prop->pos.y - 10;
		testpos.z = g_Vars.currentplayer->prop->pos.z;
		roomsCopy(g_Vars.currentplayer->prop->rooms, rooms);
		bmove0f0cb79c(g_Vars.currentplayer, &testpos, rooms);
		onladder2 = cd00029ffc(&g_Vars.currentplayer->prop->pos,
				width * 1.1f, ymax - g_Vars.currentplayer->prop->pos.y,
				g_Vars.currentplayer->vv_manground - g_Vars.currentplayer->prop->pos.y - 10,
				rooms, 0x8040, &g_Vars.currentplayer->laddernormal);
	}

	testpos.x = g_Vars.currentplayer->prop->pos.x;
	testpos.y = g_Vars.currentplayer->prop->pos.y;
	testpos.z = g_Vars.currentplayer->prop->pos.z;

	if (g_Vars.currentplayer->inlift) {
		testpos.y -= g_Vars.currentplayer->crouchheight + g_Vars.currentplayer->crouchoffsetrealsmall;
	}

	roomsCopy(g_Vars.currentplayer->prop->rooms, rooms);
	bmove0f0cb79c(g_Vars.currentplayer, &testpos, rooms);
	ground = cdFindGroundY(&testpos, g_Vars.currentplayer->bond2.width, rooms,
			&g_Vars.currentplayer->floorcol, &g_Vars.currentplayer->floortype,
			&g_Vars.currentplayer->floorflags, &g_Vars.currentplayer->floorroom,
			&newinlift, &lift);
	ground += g_Vars.currentplayer->bondonground;

	if (ground < -30000) {
		ground = -30000;
	}

#if PIRACYCHECKS
	if (g_Vars.currentplayer->inlift && newinlift == false) {
		// Exiting a lift
		piracyRestore();
	}
#endif

	if (g_Vars.currentplayer->inlift && newinlift && g_Vars.currentplayer->onladder == false) {
		// Remaining in a lift
		moveamount = ground - g_Vars.currentplayer->vv_ground;

		if (moveamount != 0) {
			// The lift is moving
			if (g_Vars.currentplayer->isfalling == false && lift == g_Vars.currentplayer->lift) {
				clearance = g_Vars.currentplayer->liftground - g_Vars.currentplayer->vv_manground;

				if (clearance < 1.0f && clearance > -1.0f) {
					// It's actually moving, and not a floating point precision issue
					g_Vars.currentplayer->vv_ground += moveamount;

					if (moveamount > 0
							|| lift == NULL
							|| lift->obj == NULL
							|| (lift->obj->flags & OBJFLAG_CHOPPER_INACTIVE) == 0
							|| bwalkTryMoveUpwards(moveamount) == CDRESULT_NOCOLLISION) {
						// Going up
						g_Vars.currentplayer->vv_manground += moveamount;
						g_Vars.currentplayer->sumground = g_Vars.currentplayer->vv_manground / (PAL ? 0.054400026798248f : 0.045499980449677f);
					}
				}
			}

			if (g_Vars.currentplayer->walkinitmove) {
				g_Vars.currentplayer->walkinitstart.y += moveamount;
			}
		}
	} else {
		lift = NULL;
	}

	g_Vars.currentplayer->inlift = newinlift;

	if (newinlift) {
		g_Vars.currentplayer->liftground = ground;
	}

	g_Vars.currentplayer->lift = lift;

	// Ladders
	if (g_Vars.currentplayer->onladder) {
		if (g_Vars.currentplayer->ladderupdown >= 0 ||
				(ground <= g_Vars.currentplayer->vv_manground &&
				 ground <= g_Vars.currentplayer->vv_manground + g_Vars.currentplayer->ladderupdown)) {
			// Still on ladder
			if (bwalkTryMoveUpwards(g_Vars.currentplayer->ladderupdown) == CDRESULT_NOCOLLISION) {
				g_Vars.currentplayer->vv_manground += g_Vars.currentplayer->ladderupdown;
			}
		} else {
			if (bwalkTryMoveUpwards(ground - g_Vars.currentplayer->vv_manground) == CDRESULT_NOCOLLISION) {
				g_Vars.currentplayer->vv_manground = ground;
				onladder = false;
			}
		}
	}

	g_Vars.currentplayer->onladder = onladder;

	if (g_Vars.currentplayer->onladder) {
		g_Vars.currentplayer->vv_ground = g_Vars.currentplayer->vv_manground;
	} else if (onladder2 == false) {
		g_Vars.currentplayer->vv_ground = ground;
	}

	// Standing on flat ground, or going up stairs, ledges or ramps
	// In other words, not falling
	if (g_Vars.currentplayer->bdeltapos.y >= 0.0f
			|| g_Vars.currentplayer->vv_ground > g_Vars.currentplayer->vv_manground) {
		g_Vars.currentplayer->sumground = g_Vars.currentplayer->vv_manground / (PAL ? 0.054400026798248f : 0.045499980449677f);

		for (i = 0; i < g_Vars.lvupdate240; i++) {
			g_Vars.currentplayer->sumground =
				g_Vars.currentplayer->sumground * (PAL ? 0.94559997320175f : 0.9545f) + g_Vars.currentplayer->vv_ground;
		}

		if (g_Vars.currentplayer->vv_manground < g_Vars.currentplayer->vv_ground) {
			// Feet are lower than the ground
			sumground = g_Vars.currentplayer->sumground * (PAL ? 0.054400026798248f : 0.045499980449677f);
			limit = g_Vars.currentplayer->vv_ground - 50;

			if (sumground < limit) {
				sumground = limit;
			}

			if (bwalkTryMoveUpwards(sumground - g_Vars.currentplayer->vv_manground) == CDRESULT_NOCOLLISION) {
				g_Vars.currentplayer->vv_manground = sumground;
			} else {
				// Not enough room above. If on a hoverbike, blow it up
				prop = cdGetObstacle();

				if (prop
						&& g_Vars.currentplayer->prop->pos.y < prop->pos.y
						&& prop->type == PROPTYPE_OBJ) {
					obj = prop->obj;

					if (obj->modelnum == MODEL_HOVBIKE) {
						amount = (obj->maxdamage - obj->damage + 1) / 250.0f;
						obj->flags &= ~OBJFLAG_INVINCIBLE;
						objDamage(obj, amount, &obj->prop->pos, WEAPON_REMOTEMINE, -1);
					}
				}
			}
		}

		// Kill player if standing on tile with TILEFLAG_DIE
		if ((g_Vars.currentplayer->floorflags & TILEFLAG_DIE)
				&& g_Vars.currentplayer->vv_manground - 20.0f < g_Vars.currentplayer->vv_ground
				&& g_Vars.currentplayer->onladder == false
				&& onladder2 == false) {
			playerDie(true);
		}
	}

	if (g_Vars.currentplayer->vv_manground > g_Vars.currentplayer->vv_ground) {
		// Not standing on ground - probably falling, or on an object of some sort
		fallspeed = g_Vars.currentplayer->bdeltapos.y;
		newmanground = g_Vars.currentplayer->vv_manground;

		if (debugIsTurboModeEnabled()
				&& g_Vars.currentplayer->bondforcespeed.x == 0
				&& g_Vars.currentplayer->bondforcespeed.z == 0) {
			multiplier = 0.277777777f * 5;
		} else {
			multiplier = 0.277777777f;
		}

		newfallspeed = fallspeed - g_Vars.lvupdate240freal * multiplier;
		newmanground += g_Vars.lvupdate240freal * (fallspeed + newfallspeed) * 0.5f;
		fallspeed = newfallspeed;

		if (newmanground < g_Vars.currentplayer->vv_ground) {
			newfallspeed = g_Vars.currentplayer->vv_manground - g_Vars.currentplayer->vv_ground;
			newmanground = g_Vars.currentplayer->vv_ground;

			fallspeed = sqrtf(g_Vars.currentplayer->bdeltapos.y *
					g_Vars.currentplayer->bdeltapos.y +
					(((newfallspeed + newfallspeed) * 0.277777777f) / 60.0f) * 60.0f);
			fallspeed = -fallspeed;
		}

		if (bwalkTryMoveUpwards(newmanground - g_Vars.currentplayer->vv_manground) == CDRESULT_NOCOLLISION) {
			// Falling
			g_Vars.currentplayer->vv_manground = newmanground;
			g_Vars.currentplayer->bdeltapos.y = fallspeed;

			if (g_Vars.currentplayer->isfalling == false) {
				// Just started falling
				g_Vars.currentplayer->isfalling = true;
				g_Vars.currentplayer->fallstart = g_Vars.lvframe60;
			} else {
				if (g_Vars.lvframe60 - g_Vars.currentplayer->fallstart > TICKS(240)) {
					// Have been falling for 4 seconds
					playerDie(true);
				}
			}
		} else {
			// Not falling
			if (g_Vars.normmplayerisrunning == false
					&& g_Vars.currentplayer->vv_ground < g_Vars.currentplayer->vv_manground - 30) {
				// Not falling - but still at least 30 units off the ground.
				// Must be something in the way...
				prop = cdGetObstacle();

				if (prop) {
					if (prop->type == PROPTYPE_CHR) {
						// Landed on top of a chr
						if (prop->chr->inlift) {
							chrYeetFromPos(prop->chr, &g_Vars.currentplayer->prop->pos, 0);
						}
					} else if (prop->type == PROPTYPE_PLAYER) {
						// Landed on top of a player
						u32 prevplayernum = g_Vars.currentplayernum;
						setCurrentPlayerNum(playermgrGetPlayerNumByProp(prop));

						if (g_Vars.currentplayer->inlift) {
							playerDieByShooter(prevplayernum, true);
						}

						setCurrentPlayerNum(prevplayernum);
					}
				}
			}

			g_Vars.currentplayer->bdeltapos.y = 0.0f;

			if (g_Vars.currentplayer->isfalling) {
				g_Vars.currentplayer->isfalling = false;
			}

			if (g_Vars.currentplayer->vv_manground <= -30000) {
				playerDie(true);
			}
		}
	} else {
		// Not falling
		if (g_Vars.currentplayer->isfalling) {
			g_Vars.currentplayer->isfalling = false;
		}

		if (g_Vars.currentplayer->vv_manground <= -30000) {
			playerDie(true);
		}
	}

	if (g_Vars.currentplayer->bdeltapos.y < 0 &&
			g_Vars.currentplayer->vv_manground <= g_Vars.currentplayer->vv_ground) {
		// Landing after a fall
		if (g_Vars.currentplayer->isfalling) {
			g_Vars.currentplayer->isfalling = false;
		}

		// I suspect these crouch fields are related to the recovery during
		// landing. Eg. The faster the fall speed, the longer Jo will take to
		// stand back to full height again.
		if (g_Vars.currentplayer->bdeltapos.y < -13.333333f) {
			g_Vars.currentplayer->crouchtime240 = TICKS(60);
			g_Vars.currentplayer->crouchfall = -90;
		} else if (g_Vars.currentplayer->bdeltapos.y < -5.0f) {
			g_Vars.currentplayer->crouchtime240 = TICKS(60);
			g_Vars.currentplayer->crouchfall =
				(-5.0f - g_Vars.currentplayer->bdeltapos.y) * -90.0f / 8.333333f;
		}

		if (g_Vars.currentplayer->bdeltapos.y < -6.0f) {
			// Play footstep sounds
			s32 sound;
			struct chrdata *chr = g_Vars.currentplayer->prop->chr;
			chr->floortype = g_Vars.currentplayer->floortype;
			chr->footstep = 1;

			sound = footstepChooseSound(chr, true);

			if (sound != -1) {
				if (sound != -1) {
					func0f0939f8(NULL, g_Vars.currentplayer->prop, sound,
							-1, -1, 0x8400, 0, 0, 0, -1, 0, -1, -1, -1, -1);
				}

				chr->footstep = 2;
				sound = footstepChooseSound(chr, true);

				if (sound != -1) {
					func0f0939f8(NULL, g_Vars.currentplayer->prop, sound,
							-1, -1, 0x8400, 0, 0, 0, -1, 0, -1, -1, -1, -1);
				}
			}

			if (g_Vars.mplayerisrunning == false
					&& (chr->headnum == HEAD_DARK_COMBAT || chr->headnum == HEAD_DARK_FROCK)
					&& g_Vars.lvframe60 - g_Vars.currentplayer->fallstart > TICKS(40)) {
				// Play Jo landing grunt
				s32 sounds[] = {
					SFX_JO_LANDING_046F,
					SFX_JO_LANDING_05B6,
					SFX_JO_LANDING_05B7
				};

				func0f0939f8(NULL, g_Vars.currentplayer->prop, sounds[random() % 3],
						-1, -1, 0x8400, 0, 0, 0, -1, 0, -1, -1, -1, -1);
			}
		}

		g_Vars.currentplayer->bdeltapos.y = 0;
	}

	// Decrease crouchtime240 for this tick.
	// If reached 0 and crouchfall is negative, start increasing
	// crouchfall over the next several ticks until it reaches 0.
	for (i = 0; i < g_Vars.lvupdate240; i++) {
		if (g_Vars.currentplayer->crouchtime240 > 0) {
			g_Vars.currentplayer->sumcrouch =
				g_Vars.currentplayer->sumcrouch * (PAL ? 0.93540000915527f : 0.9456f) + g_Vars.currentplayer->crouchfall;
			g_Vars.currentplayer->crouchtime240--;
		} else {
			if (g_Vars.currentplayer->crouchfall < 0) {
				g_Vars.currentplayer->crouchfall -= (PAL ? -1.3636363744736f : -1.125f);

				if (g_Vars.currentplayer->crouchfall >= 0) {
					g_Vars.currentplayer->crouchfall = 0;
				}
			}

			g_Vars.currentplayer->sumcrouch =
				g_Vars.currentplayer->sumcrouch * (PAL ? 0.93540000915527f : 0.9456f) + g_Vars.currentplayer->crouchfall;
		}
	}

	{
		f32 eyeheight;
		g_Vars.currentplayer->crouchheight = g_Vars.currentplayer->sumcrouch * (PAL ? 0.064599990844727f : 0.054400026798248f);
		g_Vars.currentplayer->vv_height =
			(g_Vars.currentplayer->headpos.y / g_Vars.currentplayer->standheight)
			* g_Vars.currentplayer->vv_eyeheight;

		eyeheight = g_Vars.currentplayer->vv_height +
			g_Vars.currentplayer->crouchoffsetrealsmall +
			g_Vars.currentplayer->crouchheight *
			g_Vars.currentplayer->vv_eyeheight * 0.0062893079593778f;

		if (eyeheight < 30) {
			eyeheight = 30;
		}

		newpos.x = g_Vars.currentplayer->prop->pos.x;
		newpos.y = g_Vars.currentplayer->vv_manground + eyeheight;
		newpos.z = g_Vars.currentplayer->prop->pos.z;
	}

	if (newpos.y < g_Vars.currentplayer->vv_ground + 10) {
		newpos.y = g_Vars.currentplayer->vv_ground + 10;
	}

	if (newpos.x != g_Vars.currentplayer->prop->pos.x
			|| newpos.y != g_Vars.currentplayer->prop->pos.y
			|| newpos.z != g_Vars.currentplayer->prop->pos.z) {
		func0f065e74(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, &newpos, newrooms);

		g_Vars.currentplayer->prop->pos.x = newpos.x;
		g_Vars.currentplayer->prop->pos.y = newpos.y;
		g_Vars.currentplayer->prop->pos.z = newpos.z;

		propDeregisterRooms(g_Vars.currentplayer->prop);
		roomsCopy(newrooms, g_Vars.currentplayer->prop->rooms);
	}
}
#else
s32 sounds[] = {
	SFX_JO_LANDING_046F,
	SFX_JO_LANDING_05B6,
	SFX_JO_LANDING_05B7
};

GLOBAL_ASM(
glabel bwalkUpdateVertical
.late_rodata
glabel var7f1a7adcnb
.word 0x3f99999a
glabel var7f1a7ae0nb
.word 0x3f8ccccd
glabel var7f1a7ae4nb
.word 0xc6ea6000
glabel var7f1a7ae8nb
.word 0xc6ea6000
glabel var7f1a7aecnb
.word 0x3d3a5e30
glabel var7f1a7af0nb
.word 0x3d3a5e30
glabel var7f1a7af4nb
.word 0x3f745a1d
glabel var7f1a7af8nb
.word 0x3d3a5e30
glabel var7f1a7afcnb
.word 0x3fb1c71d
glabel var7f1a7b00nb
.word 0x3e8e38e4
glabel var7f1a7b04nb
.word 0x3e8e38e4
glabel var7f1a7b08nb
.word 0xc6ea6000
glabel var7f1a7b0cnb
.word 0xc6ea6000
glabel var7f1a7b10nb
.word 0xc1555555
glabel var7f1a7b14nb
.word 0x41055555
glabel var7f1a7b18nb
.word 0x3f7212d7
glabel var7f1a7b1cnb
.word 0x3d5ed290
glabel var7f1a7b20nb
.word 0x3bce168a
.text
/*  f0c2bd8:	27bdff10 */ 	addiu	$sp,$sp,-240
/*  f0c2bdc:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f0c2be0:	3c10800a */ 	lui	$s0,0x800a
/*  f0c2be4:	2610e6c0 */ 	addiu	$s0,$s0,-6464
/*  f0c2be8:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c2bec:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0c2bf0:	afa000d0 */ 	sw	$zero,0xd0($sp)
/*  f0c2bf4:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f0c2bf8:	27a500e4 */ 	addiu	$a1,$sp,0xe4
/*  f0c2bfc:	27a600e0 */ 	addiu	$a2,$sp,0xe0
/*  f0c2c00:	27a700dc */ 	addiu	$a3,$sp,0xdc
/*  f0c2c04:	0fc2ff20 */ 	jal	playerGetBbox
/*  f0c2c08:	8dc400bc */ 	lw	$a0,0xbc($t6)
/*  f0c2c0c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c2c10:	c4267adc */ 	lwc1	$f6,0x7adc($at)
/*  f0c2c14:	c7a400e4 */ 	lwc1	$f4,0xe4($sp)
/*  f0c2c18:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2c1c:	c7aa00e0 */ 	lwc1	$f10,0xe0($sp)
/*  f0c2c20:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0c2c24:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f0c2c28:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c2c2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c2c30:	c460000c */ 	lwc1	$f0,0xc($v1)
/*  f0c2c34:	34188040 */ 	dli	$t8,0x8040
/*  f0c2c38:	245902a0 */ 	addiu	$t9,$v0,0x2a0
/*  f0c2c3c:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0c2c40:	44054000 */ 	mfc1	$a1,$f8
/*  f0c2c44:	44815000 */ 	mtc1	$at,$f10
/*  f0c2c48:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0c2c4c:	44062000 */ 	mfc1	$a2,$f4
/*  f0c2c50:	246f0028 */ 	addiu	$t7,$v1,0x28
/*  f0c2c54:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0c2c58:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0c2c5c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0c2c60:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0c2c64:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0c2c68:	44072000 */ 	mfc1	$a3,$f4
/*  f0c2c6c:	0c00ad11 */ 	jal	cd00029ffc
/*  f0c2c70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2c74:	14400031 */ 	bnez	$v0,.NB0f0c2d3c
/*  f0c2c78:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f0c2c7c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2c80:	3c014120 */ 	lui	$at,0x4120
/*  f0c2c84:	44815000 */ 	mtc1	$at,$f10
/*  f0c2c88:	8c4900bc */ 	lw	$t1,0xbc($v0)
/*  f0c2c8c:	27a500c0 */ 	addiu	$a1,$sp,0xc0
/*  f0c2c90:	c5260008 */ 	lwc1	$f6,0x8($t1)
/*  f0c2c94:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*  f0c2c98:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f0c2c9c:	c548000c */ 	lwc1	$f8,0xc($t2)
/*  f0c2ca0:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0c2ca4:	e7a400b8 */ 	swc1	$f4,0xb8($sp)
/*  f0c2ca8:	8c4b00bc */ 	lw	$t3,0xbc($v0)
/*  f0c2cac:	c5660010 */ 	lwc1	$f6,0x10($t3)
/*  f0c2cb0:	e7a600bc */ 	swc1	$f6,0xbc($sp)
/*  f0c2cb4:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f0c2cb8:	0fc19283 */ 	jal	roomsCopy
/*  f0c2cbc:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f0c2cc0:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0c2cc4:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0c2cc8:	0fc323f3 */ 	jal	bmove0f0cb79c
/*  f0c2ccc:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f0c2cd0:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c2cd4:	c42a7ae0 */ 	lwc1	$f10,0x7ae0($at)
/*  f0c2cd8:	c7a800e4 */ 	lwc1	$f8,0xe4($sp)
/*  f0c2cdc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2ce0:	c7a600e0 */ 	lwc1	$f6,0xe0($sp)
/*  f0c2ce4:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0c2ce8:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f0c2cec:	c44a0074 */ 	lwc1	$f10,0x74($v0)
/*  f0c2cf0:	3c014120 */ 	lui	$at,0x4120
/*  f0c2cf4:	c460000c */ 	lwc1	$f0,0xc($v1)
/*  f0c2cf8:	27ac00c0 */ 	addiu	$t4,$sp,0xc0
/*  f0c2cfc:	340d8040 */ 	dli	$t5,0x8040
/*  f0c2d00:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0c2d04:	44052000 */ 	mfc1	$a1,$f4
/*  f0c2d08:	44813000 */ 	mtc1	$at,$f6
/*  f0c2d0c:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0c2d10:	44064000 */ 	mfc1	$a2,$f8
/*  f0c2d14:	244e02a0 */ 	addiu	$t6,$v0,0x2a0
/*  f0c2d18:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0c2d1c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0c2d20:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0c2d24:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0c2d28:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0c2d2c:	44074000 */ 	mfc1	$a3,$f8
/*  f0c2d30:	0c00ad11 */ 	jal	cd00029ffc
/*  f0c2d34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2d38:	afa200d0 */ 	sw	$v0,0xd0($sp)
.NB0f0c2d3c:
/*  f0c2d3c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2d40:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f0c2d44:	c5ea0008 */ 	lwc1	$f10,0x8($t7)
/*  f0c2d48:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
/*  f0c2d4c:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f0c2d50:	c704000c */ 	lwc1	$f4,0xc($t8)
/*  f0c2d54:	e7a400b8 */ 	swc1	$f4,0xb8($sp)
/*  f0c2d58:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f0c2d5c:	c7260010 */ 	lwc1	$f6,0x10($t9)
/*  f0c2d60:	e7a600bc */ 	swc1	$f6,0xbc($sp)
/*  f0c2d64:	8c4902b0 */ 	lw	$t1,0x2b0($v0)
/*  f0c2d68:	5120000b */ 	beqzl	$t1,.NB0f0c2d98
/*  f0c2d6c:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f0c2d70:	8c4a19b8 */ 	lw	$t2,0x19b8($v0)
/*  f0c2d74:	c448008c */ 	lwc1	$f8,0x8c($v0)
/*  f0c2d78:	448a5000 */ 	mtc1	$t2,$f10
/*  f0c2d7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2d80:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0c2d84:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0c2d88:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c2d8c:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0c2d90:	e7a800b8 */ 	swc1	$f8,0xb8($sp)
/*  f0c2d94:	8c4400bc */ 	lw	$a0,0xbc($v0)
.NB0f0c2d98:
/*  f0c2d98:	27a500c0 */ 	addiu	$a1,$sp,0xc0
/*  f0c2d9c:	0fc19283 */ 	jal	roomsCopy
/*  f0c2da0:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f0c2da4:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0c2da8:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0c2dac:	0fc323f3 */ 	jal	bmove0f0cb79c
/*  f0c2db0:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f0c2db4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2db8:	27ae0094 */ 	addiu	$t6,$sp,0x94
/*  f0c2dbc:	27af0090 */ 	addiu	$t7,$sp,0x90
/*  f0c2dc0:	8c450378 */ 	lw	$a1,0x378($v0)
/*  f0c2dc4:	244b161e */ 	addiu	$t3,$v0,0x161e
/*  f0c2dc8:	244c161c */ 	addiu	$t4,$v0,0x161c
/*  f0c2dcc:	244d19b0 */ 	addiu	$t5,$v0,0x19b0
/*  f0c2dd0:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0c2dd4:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0c2dd8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0c2ddc:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0c2de0:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0c2de4:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f0c2de8:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f0c2dec:	0c00ad7e */ 	jal	cdFindGroundY
/*  f0c2df0:	2447161a */ 	addiu	$a3,$v0,0x161a
/*  f0c2df4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2df8:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c2dfc:	c42a7ae4 */ 	lwc1	$f10,0x7ae4($at)
/*  f0c2e00:	c4441ae8 */ 	lwc1	$f4,0x1ae8($v0)
/*  f0c2e04:	46040380 */ 	add.s	$f14,$f0,$f4
/*  f0c2e08:	460a703c */ 	c.lt.s	$f14,$f10
/*  f0c2e0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2e10:	45000002 */ 	bc1f	.NB0f0c2e1c
/*  f0c2e14:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c2e18:	c42e7ae8 */ 	lwc1	$f14,0x7ae8($at)
.NB0f0c2e1c:
/*  f0c2e1c:	8c5802b0 */ 	lw	$t8,0x2b0($v0)
/*  f0c2e20:	8fb90094 */ 	lw	$t9,0x94($sp)
/*  f0c2e24:	53000049 */ 	beqzl	$t8,.NB0f0c2f4c
/*  f0c2e28:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f0c2e2c:	53200047 */ 	beqzl	$t9,.NB0f0c2f4c
/*  f0c2e30:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f0c2e34:	8c4902ac */ 	lw	$t1,0x2ac($v0)
/*  f0c2e38:	55200044 */ 	bnezl	$t1,.NB0f0c2f4c
/*  f0c2e3c:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f0c2e40:	8c4a0030 */ 	lw	$t2,0x30($v0)
/*  f0c2e44:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c2e48:	8fab0090 */ 	lw	$t3,0x90($sp)
/*  f0c2e4c:	15400035 */ 	bnez	$t2,.NB0f0c2f24
/*  f0c2e50:	46007301 */ 	sub.s	$f12,$f14,$f0
/*  f0c2e54:	8c4c0298 */ 	lw	$t4,0x298($v0)
/*  f0c2e58:	556c0033 */ 	bnel	$t3,$t4,.NB0f0c2f28
/*  f0c2e5c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2e60:	c4460294 */ 	lwc1	$f6,0x294($v0)
/*  f0c2e64:	c4480074 */ 	lwc1	$f8,0x74($v0)
/*  f0c2e68:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c2e6c:	44812000 */ 	mtc1	$at,$f4
/*  f0c2e70:	46083081 */ 	sub.s	$f2,$f6,$f8
/*  f0c2e74:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c2e78:	4604103c */ 	c.lt.s	$f2,$f4
/*  f0c2e7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2e80:	45020029 */ 	bc1fl	.NB0f0c2f28
/*  f0c2e84:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2e88:	44815000 */ 	mtc1	$at,$f10
/*  f0c2e8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2e90:	4602503c */ 	c.lt.s	$f10,$f2
/*  f0c2e94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2e98:	45020023 */ 	bc1fl	.NB0f0c2f28
/*  f0c2e9c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2ea0:	44804000 */ 	mtc1	$zero,$f8
/*  f0c2ea4:	460c0180 */ 	add.s	$f6,$f0,$f12
/*  f0c2ea8:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0c2eac:	e4460078 */ 	swc1	$f6,0x78($v0)
/*  f0c2eb0:	8fad0090 */ 	lw	$t5,0x90($sp)
/*  f0c2eb4:	45030012 */ 	bc1tl	.NB0f0c2f00
/*  f0c2eb8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2ebc:	51a00010 */ 	beqzl	$t5,.NB0f0c2f00
/*  f0c2ec0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2ec4:	8da20004 */ 	lw	$v0,0x4($t5)
/*  f0c2ec8:	5040000d */ 	beqzl	$v0,.NB0f0c2f00
/*  f0c2ecc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2ed0:	8c4e0008 */ 	lw	$t6,0x8($v0)
/*  f0c2ed4:	000e7800 */ 	sll	$t7,$t6,0x0
/*  f0c2ed8:	05e30009 */ 	bgezl	$t7,.NB0f0c2f00
/*  f0c2edc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2ee0:	e7ac0088 */ 	swc1	$f12,0x88($sp)
/*  f0c2ee4:	0fc30612 */ 	jal	bwalkTryMoveUpwards
/*  f0c2ee8:	e7ae00d8 */ 	swc1	$f14,0xd8($sp)
/*  f0c2eec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c2ef0:	c7ac0088 */ 	lwc1	$f12,0x88($sp)
/*  f0c2ef4:	1441000b */ 	bne	$v0,$at,.NB0f0c2f24
/*  f0c2ef8:	c7ae00d8 */ 	lwc1	$f14,0xd8($sp)
/*  f0c2efc:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c2f00:
/*  f0c2f00:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c2f04:	c4440074 */ 	lwc1	$f4,0x74($v0)
/*  f0c2f08:	460c2280 */ 	add.s	$f10,$f4,$f12
/*  f0c2f0c:	e44a0074 */ 	swc1	$f10,0x74($v0)
/*  f0c2f10:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2f14:	c4287aec */ 	lwc1	$f8,0x7aec($at)
/*  f0c2f18:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c2f1c:	46083103 */ 	div.s	$f4,$f6,$f8
/*  f0c2f20:	e4440070 */ 	swc1	$f4,0x70($v0)
.NB0f0c2f24:
/*  f0c2f24:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c2f28:
/*  f0c2f28:	8c581af8 */ 	lw	$t8,0x1af8($v0)
/*  f0c2f2c:	53000008 */ 	beqzl	$t8,.NB0f0c2f50
/*  f0c2f30:	8fb90094 */ 	lw	$t9,0x94($sp)
/*  f0c2f34:	c44a1b54 */ 	lwc1	$f10,0x1b54($v0)
/*  f0c2f38:	460c5180 */ 	add.s	$f6,$f10,$f12
/*  f0c2f3c:	e4461b54 */ 	swc1	$f6,0x1b54($v0)
/*  f0c2f40:	10000002 */ 	beqz	$zero,.NB0f0c2f4c
/*  f0c2f44:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2f48:	afa00090 */ 	sw	$zero,0x90($sp)
.NB0f0c2f4c:
/*  f0c2f4c:	8fb90094 */ 	lw	$t9,0x94($sp)
.NB0f0c2f50:
/*  f0c2f50:	ac5902b0 */ 	sw	$t9,0x2b0($v0)
/*  f0c2f54:	8fa90094 */ 	lw	$t1,0x94($sp)
/*  f0c2f58:	51200004 */ 	beqzl	$t1,.NB0f0c2f6c
/*  f0c2f5c:	8fab0090 */ 	lw	$t3,0x90($sp)
/*  f0c2f60:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c2f64:	e54e0294 */ 	swc1	$f14,0x294($t2)
/*  f0c2f68:	8fab0090 */ 	lw	$t3,0x90($sp)
.NB0f0c2f6c:
/*  f0c2f6c:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c2f70:	ad8b0298 */ 	sw	$t3,0x298($t4)
/*  f0c2f74:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2f78:	8c4d02ac */ 	lw	$t5,0x2ac($v0)
/*  f0c2f7c:	51a00027 */ 	beqzl	$t5,.NB0f0c301c
/*  f0c2f80:	8faf00d4 */ 	lw	$t7,0xd4($sp)
/*  f0c2f84:	c44c029c */ 	lwc1	$f12,0x29c($v0)
/*  f0c2f88:	44804000 */ 	mtc1	$zero,$f8
/*  f0c2f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2f90:	460c403e */ 	c.le.s	$f8,$f12
/*  f0c2f94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2f98:	4501000b */ 	bc1t	.NB0f0c2fc8
/*  f0c2f9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2fa0:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c2fa4:	4602703e */ 	c.le.s	$f14,$f2
/*  f0c2fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2fac:	45020012 */ 	bc1fl	.NB0f0c2ff8
/*  f0c2fb0:	46027301 */ 	sub.s	$f12,$f14,$f2
/*  f0c2fb4:	460c1100 */ 	add.s	$f4,$f2,$f12
/*  f0c2fb8:	4604703e */ 	c.le.s	$f14,$f4
/*  f0c2fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2fc0:	4502000d */ 	bc1fl	.NB0f0c2ff8
/*  f0c2fc4:	46027301 */ 	sub.s	$f12,$f14,$f2
.NB0f0c2fc8:
/*  f0c2fc8:	0fc30612 */ 	jal	bwalkTryMoveUpwards
/*  f0c2fcc:	e7ae00d8 */ 	swc1	$f14,0xd8($sp)
/*  f0c2fd0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c2fd4:	14410010 */ 	bne	$v0,$at,.NB0f0c3018
/*  f0c2fd8:	c7ae00d8 */ 	lwc1	$f14,0xd8($sp)
/*  f0c2fdc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2fe0:	c44a0074 */ 	lwc1	$f10,0x74($v0)
/*  f0c2fe4:	c446029c */ 	lwc1	$f6,0x29c($v0)
/*  f0c2fe8:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0c2fec:	1000000a */ 	beqz	$zero,.NB0f0c3018
/*  f0c2ff0:	e4480074 */ 	swc1	$f8,0x74($v0)
/*  f0c2ff4:	46027301 */ 	sub.s	$f12,$f14,$f2
.NB0f0c2ff8:
/*  f0c2ff8:	0fc30612 */ 	jal	bwalkTryMoveUpwards
/*  f0c2ffc:	e7ae00d8 */ 	swc1	$f14,0xd8($sp)
/*  f0c3000:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c3004:	14410004 */ 	bne	$v0,$at,.NB0f0c3018
/*  f0c3008:	c7ae00d8 */ 	lwc1	$f14,0xd8($sp)
/*  f0c300c:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c3010:	e5ce0074 */ 	swc1	$f14,0x74($t6)
/*  f0c3014:	afa000d4 */ 	sw	$zero,0xd4($sp)
.NB0f0c3018:
/*  f0c3018:	8faf00d4 */ 	lw	$t7,0xd4($sp)
.NB0f0c301c:
/*  f0c301c:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c3020:	44803000 */ 	mtc1	$zero,$f6
/*  f0c3024:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3028:	af0f02ac */ 	sw	$t7,0x2ac($t8)
/*  f0c302c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3030:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f0c3034:	8c5902ac */ 	lw	$t9,0x2ac($v0)
/*  f0c3038:	13200005 */ 	beqz	$t9,.NB0f0c3050
/*  f0c303c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3040:	c4440074 */ 	lwc1	$f4,0x74($v0)
/*  f0c3044:	e4440078 */ 	swc1	$f4,0x78($v0)
/*  f0c3048:	10000005 */ 	beqz	$zero,.NB0f0c3060
/*  f0c304c:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c3050:
/*  f0c3050:	55200004 */ 	bnezl	$t1,.NB0f0c3064
/*  f0c3054:	c44a0080 */ 	lwc1	$f10,0x80($v0)
/*  f0c3058:	e44e0078 */ 	swc1	$f14,0x78($v0)
/*  f0c305c:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c3060:
/*  f0c3060:	c44a0080 */ 	lwc1	$f10,0x80($v0)
.NB0f0c3064:
/*  f0c3064:	460a303e */ 	c.le.s	$f6,$f10
/*  f0c3068:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c306c:	45030008 */ 	bc1tl	.NB0f0c3090
/*  f0c3070:	c4480074 */ 	lwc1	$f8,0x74($v0)
/*  f0c3074:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c3078:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c307c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c3080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3084:	4502004c */ 	bc1fl	.NB0f0c31b8
/*  f0c3088:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c308c:	c4480074 */ 	lwc1	$f8,0x74($v0)
.NB0f0c3090:
/*  f0c3090:	c4247af0 */ 	lwc1	$f4,0x7af0($at)
/*  f0c3094:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3098:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c309c:	46044283 */ 	div.s	$f10,$f8,$f4
/*  f0c30a0:	e44a0070 */ 	swc1	$f10,0x70($v0)
/*  f0c30a4:	8e0a0034 */ 	lw	$t2,0x34($s0)
/*  f0c30a8:	5940000e */ 	blezl	$t2,.NB0f0c30e4
/*  f0c30ac:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c30b0:	c4207af4 */ 	lwc1	$f0,0x7af4($at)
/*  f0c30b4:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c30b8:
/*  f0c30b8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0c30bc:	c4460070 */ 	lwc1	$f6,0x70($v0)
/*  f0c30c0:	c4440078 */ 	lwc1	$f4,0x78($v0)
/*  f0c30c4:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0c30c8:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0c30cc:	e44a0070 */ 	swc1	$f10,0x70($v0)
/*  f0c30d0:	8e0b0034 */ 	lw	$t3,0x34($s0)
/*  f0c30d4:	006b082a */ 	slt	$at,$v1,$t3
/*  f0c30d8:	5420fff7 */ 	bnezl	$at,.NB0f0c30b8
/*  f0c30dc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c30e0:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c30e4:
/*  f0c30e4:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c30e8:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c30ec:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c30f0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c30f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c30f8:	45020015 */ 	bc1fl	.NB0f0c3150
/*  f0c30fc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3100:	c4460070 */ 	lwc1	$f6,0x70($v0)
/*  f0c3104:	c4287af8 */ 	lwc1	$f8,0x7af8($at)
/*  f0c3108:	3c014248 */ 	lui	$at,0x4248
/*  f0c310c:	44812000 */ 	mtc1	$at,$f4
/*  f0c3110:	46083382 */ 	mul.s	$f14,$f6,$f8
/*  f0c3114:	46040301 */ 	sub.s	$f12,$f0,$f4
/*  f0c3118:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0c311c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3120:	45020003 */ 	bc1fl	.NB0f0c3130
/*  f0c3124:	46027301 */ 	sub.s	$f12,$f14,$f2
/*  f0c3128:	46006386 */ 	mov.s	$f14,$f12
/*  f0c312c:	46027301 */ 	sub.s	$f12,$f14,$f2
.NB0f0c3130:
/*  f0c3130:	0fc30612 */ 	jal	bwalkTryMoveUpwards
/*  f0c3134:	e7ae008c */ 	swc1	$f14,0x8c($sp)
/*  f0c3138:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c313c:	14410003 */ 	bne	$v0,$at,.NB0f0c314c
/*  f0c3140:	c7ae008c */ 	lwc1	$f14,0x8c($sp)
/*  f0c3144:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c3148:	e58e0074 */ 	swc1	$f14,0x74($t4)
.NB0f0c314c:
/*  f0c314c:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c3150:
/*  f0c3150:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0c3154:	944d161c */ 	lhu	$t5,0x161c($v0)
/*  f0c3158:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c315c:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c3160:	31ae4000 */ 	andi	$t6,$t5,0x4000
/*  f0c3164:	51c00014 */ 	beqzl	$t6,.NB0f0c31b8
/*  f0c3168:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c316c:	44815000 */ 	mtc1	$at,$f10
/*  f0c3170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3174:	460a1181 */ 	sub.s	$f6,$f2,$f10
/*  f0c3178:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0c317c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3180:	4502000d */ 	bc1fl	.NB0f0c31b8
/*  f0c3184:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c3188:	8c4f02ac */ 	lw	$t7,0x2ac($v0)
/*  f0c318c:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*  f0c3190:	55e00009 */ 	bnezl	$t7,.NB0f0c31b8
/*  f0c3194:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c3198:	57000007 */ 	bnezl	$t8,.NB0f0c31b8
/*  f0c319c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c31a0:	0fc2fbde */ 	jal	playerDie
/*  f0c31a4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c31a8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c31ac:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c31b0:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c31b4:	4602003c */ 	c.lt.s	$f0,$f2
.NB0f0c31b8:
/*  f0c31b8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c31bc:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c31c0:	4502007f */ 	bc1fl	.NB0f0c33c0
/*  f0c31c4:	8c4a0030 */ 	lw	$t2,0x30($v0)
/*  f0c31c8:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c31cc:	e7a20084 */ 	swc1	$f2,0x84($sp)
/*  f0c31d0:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f0c31d4:	0fc46661 */ 	jal	debugIsTurboModeEnabled
/*  f0c31d8:	e7ae0080 */ 	swc1	$f14,0x80($sp)
/*  f0c31dc:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c31e0:	c7ae0080 */ 	lwc1	$f14,0x80($sp)
/*  f0c31e4:	10400011 */ 	beqz	$v0,.NB0f0c322c
/*  f0c31e8:	c7b00084 */ 	lwc1	$f16,0x84($sp)
/*  f0c31ec:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c31f0:	44804000 */ 	mtc1	$zero,$f8
/*  f0c31f4:	c4441b6c */ 	lwc1	$f4,0x1b6c($v0)
/*  f0c31f8:	46044032 */ 	c.eq.s	$f8,$f4
/*  f0c31fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3200:	4500000a */ 	bc1f	.NB0f0c322c
/*  f0c3204:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3208:	44805000 */ 	mtc1	$zero,$f10
/*  f0c320c:	c4461b74 */ 	lwc1	$f6,0x1b74($v0)
/*  f0c3210:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3214:	46065032 */ 	c.eq.s	$f10,$f6
/*  f0c3218:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c321c:	45000003 */ 	bc1f	.NB0f0c322c
/*  f0c3220:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3224:	10000004 */ 	beqz	$zero,.NB0f0c3238
/*  f0c3228:	c4327afc */ 	lwc1	$f18,0x7afc($at)
.NB0f0c322c:
/*  f0c322c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3230:	c4327b00 */ 	lwc1	$f18,0x7b00($at)
/*  f0c3234:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c3238:
/*  f0c3238:	c60c004c */ 	lwc1	$f12,0x4c($s0)
/*  f0c323c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c3240:	44813000 */ 	mtc1	$at,$f6
/*  f0c3244:	46126202 */ 	mul.s	$f8,$f12,$f18
/*  f0c3248:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c324c:	46087081 */ 	sub.s	$f2,$f14,$f8
/*  f0c3250:	46027100 */ 	add.s	$f4,$f14,$f2
/*  f0c3254:	46001386 */ 	mov.s	$f14,$f2
/*  f0c3258:	46046282 */ 	mul.s	$f10,$f12,$f4
/*  f0c325c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3260:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0c3264:	46088400 */ 	add.s	$f16,$f16,$f8
/*  f0c3268:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0c326c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3270:	45000016 */ 	bc1f	.NB0f0c32cc
/*  f0c3274:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3278:	c4440074 */ 	lwc1	$f4,0x74($v0)
/*  f0c327c:	3c014270 */ 	lui	$at,0x4270
/*  f0c3280:	44819000 */ 	mtc1	$at,$f18
/*  f0c3284:	46002081 */ 	sub.s	$f2,$f4,$f0
/*  f0c3288:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c328c:	c4267b04 */ 	lwc1	$f6,0x7b04($at)
/*  f0c3290:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c3294:	46021280 */ 	add.s	$f10,$f2,$f2
/*  f0c3298:	e7a00084 */ 	swc1	$f0,0x84($sp)
/*  f0c329c:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c32a0:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0c32a4:	46124103 */ 	div.s	$f4,$f8,$f18
/*  f0c32a8:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f0c32ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c32b0:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f0c32b4:	0c012e84 */ 	jal	sqrtf
/*  f0c32b8:	460a3300 */ 	add.s	$f12,$f6,$f10
/*  f0c32bc:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c32c0:	c7b00084 */ 	lwc1	$f16,0x84($sp)
/*  f0c32c4:	46000387 */ 	neg.s	$f14,$f0
/*  f0c32c8:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c32cc:
/*  f0c32cc:	c4480074 */ 	lwc1	$f8,0x74($v0)
/*  f0c32d0:	e7b00084 */ 	swc1	$f16,0x84($sp)
/*  f0c32d4:	e7ae0080 */ 	swc1	$f14,0x80($sp)
/*  f0c32d8:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c32dc:	0fc30612 */ 	jal	bwalkTryMoveUpwards
/*  f0c32e0:	46088301 */ 	sub.s	$f12,$f16,$f8
/*  f0c32e4:	44809000 */ 	mtc1	$zero,$f18
/*  f0c32e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c32ec:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c32f0:	c7ae0080 */ 	lwc1	$f14,0x80($sp)
/*  f0c32f4:	1441001c */ 	bne	$v0,$at,.NB0f0c3368
/*  f0c32f8:	c7b00084 */ 	lwc1	$f16,0x84($sp)
/*  f0c32fc:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c3300:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0c3304:	e7300074 */ 	swc1	$f16,0x74($t9)
/*  f0c3308:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c330c:	e52e0080 */ 	swc1	$f14,0x80($t1)
/*  f0c3310:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3314:	8c4a0030 */ 	lw	$t2,0x30($v0)
/*  f0c3318:	55400008 */ 	bnezl	$t2,.NB0f0c333c
/*  f0c331c:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*  f0c3320:	ac4b0030 */ 	sw	$t3,0x30($v0)
/*  f0c3324:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c3328:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f0c332c:	adac0034 */ 	sw	$t4,0x34($t5)
/*  f0c3330:	10000032 */ 	beqz	$zero,.NB0f0c33fc
/*  f0c3334:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3338:	8e0e0008 */ 	lw	$t6,0x8($s0)
.NB0f0c333c:
/*  f0c333c:	8c4f0034 */ 	lw	$t7,0x34($v0)
/*  f0c3340:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c3344:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f0c3348:	2b0100f1 */ 	slti	$at,$t8,0xf1
/*  f0c334c:	5420002c */ 	bnezl	$at,.NB0f0c3400
/*  f0c3350:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c3354:	0fc2fbde */ 	jal	playerDie
/*  f0c3358:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c335c:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c3360:	10000026 */ 	beqz	$zero,.NB0f0c33fc
/*  f0c3364:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c3368:
/*  f0c3368:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c336c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3370:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c3374:	e7320080 */ 	swc1	$f18,0x80($t9)
/*  f0c3378:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c337c:	8c490030 */ 	lw	$t1,0x30($v0)
/*  f0c3380:	11200003 */ 	beqz	$t1,.NB0f0c3390
/*  f0c3384:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3388:	ac400030 */ 	sw	$zero,0x30($v0)
/*  f0c338c:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c3390:
/*  f0c3390:	c4247b08 */ 	lwc1	$f4,0x7b08($at)
/*  f0c3394:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c3398:	4604303e */ 	c.le.s	$f6,$f4
/*  f0c339c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c33a0:	45020017 */ 	bc1fl	.NB0f0c3400
/*  f0c33a4:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c33a8:	0fc2fbde */ 	jal	playerDie
/*  f0c33ac:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c33b0:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c33b4:	10000011 */ 	beqz	$zero,.NB0f0c33fc
/*  f0c33b8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c33bc:	8c4a0030 */ 	lw	$t2,0x30($v0)
.NB0f0c33c0:
/*  f0c33c0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c33c4:	11400004 */ 	beqz	$t2,.NB0f0c33d8
/*  f0c33c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c33cc:	ac400030 */ 	sw	$zero,0x30($v0)
/*  f0c33d0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c33d4:	c4420074 */ 	lwc1	$f2,0x74($v0)
.NB0f0c33d8:
/*  f0c33d8:	c42a7b0c */ 	lwc1	$f10,0x7b0c($at)
/*  f0c33dc:	460a103e */ 	c.le.s	$f2,$f10
/*  f0c33e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c33e4:	45020006 */ 	bc1fl	.NB0f0c3400
/*  f0c33e8:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c33ec:	0fc2fbde */ 	jal	playerDie
/*  f0c33f0:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c33f4:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c33f8:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c33fc:
/*  f0c33fc:	c44e0080 */ 	lwc1	$f14,0x80($v0)
.NB0f0c3400:
/*  f0c3400:	44804000 */ 	mtc1	$zero,$f8
/*  f0c3404:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3408:	4608703c */ 	c.lt.s	$f14,$f8
/*  f0c340c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3410:	450200c5 */ 	bc1fl	.NB0f0c3728
/*  f0c3414:	8e090034 */ 	lw	$t1,0x34($s0)
/*  f0c3418:	c4440078 */ 	lwc1	$f4,0x78($v0)
/*  f0c341c:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c3420:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3424:	4604303e */ 	c.le.s	$f6,$f4
/*  f0c3428:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c342c:	450200be */ 	bc1fl	.NB0f0c3728
/*  f0c3430:	8e090034 */ 	lw	$t1,0x34($s0)
/*  f0c3434:	8c4b0030 */ 	lw	$t3,0x30($v0)
/*  f0c3438:	240c003c */ 	addiu	$t4,$zero,0x3c
/*  f0c343c:	11600004 */ 	beqz	$t3,.NB0f0c3450
/*  f0c3440:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3444:	ac400030 */ 	sw	$zero,0x30($v0)
/*  f0c3448:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c344c:	c44e0080 */ 	lwc1	$f14,0x80($v0)
.NB0f0c3450:
/*  f0c3450:	c42a7b10 */ 	lwc1	$f10,0x7b10($at)
/*  f0c3454:	3c01c0a0 */ 	lui	$at,0xc0a0
/*  f0c3458:	460a703c */ 	c.lt.s	$f14,$f10
/*  f0c345c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3460:	4502000a */ 	bc1fl	.NB0f0c348c
/*  f0c3464:	44810000 */ 	mtc1	$at,$f0
/*  f0c3468:	ac4c0090 */ 	sw	$t4,0x90($v0)
/*  f0c346c:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c3470:	44814000 */ 	mtc1	$at,$f8
/*  f0c3474:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c3478:	e5a80094 */ 	swc1	$f8,0x94($t5)
/*  f0c347c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3480:	10000014 */ 	beqz	$zero,.NB0f0c34d4
/*  f0c3484:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c3488:	44810000 */ 	mtc1	$at,$f0
.NB0f0c348c:
/*  f0c348c:	240e003c */ 	addiu	$t6,$zero,0x3c
/*  f0c3490:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0c3494:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3498:	4502000f */ 	bc1fl	.NB0f0c34d8
/*  f0c349c:	3c01c0c0 */ 	lui	$at,0xc0c0
/*  f0c34a0:	ac4e0090 */ 	sw	$t6,0x90($v0)
/*  f0c34a4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c34a8:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c34ac:	44815000 */ 	mtc1	$at,$f10
/*  f0c34b0:	c4440080 */ 	lwc1	$f4,0x80($v0)
/*  f0c34b4:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c34b8:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0c34bc:	c4247b14 */ 	lwc1	$f4,0x7b14($at)
/*  f0c34c0:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0c34c4:	46044183 */ 	div.s	$f6,$f8,$f4
/*  f0c34c8:	e4460094 */ 	swc1	$f6,0x94($v0)
/*  f0c34cc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c34d0:	c44e0080 */ 	lwc1	$f14,0x80($v0)
.NB0f0c34d4:
/*  f0c34d4:	3c01c0c0 */ 	lui	$at,0xc0c0
.NB0f0c34d8:
/*  f0c34d8:	44815000 */ 	mtc1	$at,$f10
/*  f0c34dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c34e0:	460a703c */ 	c.lt.s	$f14,$f10
/*  f0c34e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c34e8:	4502008c */ 	bc1fl	.NB0f0c371c
/*  f0c34ec:	44804000 */ 	mtc1	$zero,$f8
/*  f0c34f0:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f0c34f4:	9058161e */ 	lbu	$t8,0x161e($v0)
/*  f0c34f8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c34fc:	8de40004 */ 	lw	$a0,0x4($t7)
/*  f0c3500:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c3504:	a0980191 */ 	sb	$t8,0x191($a0)
/*  f0c3508:	a0990190 */ 	sb	$t9,0x190($a0)
/*  f0c350c:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c3510:	0fc01771 */ 	jal	footstepChooseSound
/*  f0c3514:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f0c3518:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0c351c:	10410043 */ 	beq	$v0,$at,.NB0f0c362c
/*  f0c3520:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c3524:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0c3528:	1041001a */ 	beq	$v0,$at,.NB0f0c3594
/*  f0c352c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c3530:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c3534:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c3538:	44810000 */ 	mtc1	$at,$f0
/*  f0c353c:	8d2500bc */ 	lw	$a1,0xbc($t1)
/*  f0c3540:	00023400 */ 	sll	$a2,$v0,0x10
/*  f0c3544:	00065403 */ 	sra	$t2,$a2,0x10
/*  f0c3548:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0c354c:	340c8400 */ 	dli	$t4,0x8400
/*  f0c3550:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0c3554:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f0c3558:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0c355c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0c3560:	01403025 */ 	or	$a2,$t2,$zero
/*  f0c3564:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c3568:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0c356c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0c3570:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0c3574:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0c3578:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0c357c:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0c3580:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0c3584:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0c3588:	0fc24762 */ 	jal	func0f0939f8
/*  f0c358c:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0c3590:	8fa300ec */ 	lw	$v1,0xec($sp)
.NB0f0c3594:
/*  f0c3594:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0c3598:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0c359c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c35a0:	a08e0190 */ 	sb	$t6,0x190($a0)
/*  f0c35a4:	0fc01771 */ 	jal	footstepChooseSound
/*  f0c35a8:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c35ac:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0c35b0:	1041001e */ 	beq	$v0,$at,.NB0f0c362c
/*  f0c35b4:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c35b8:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c35bc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c35c0:	44814000 */ 	mtc1	$at,$f8
/*  f0c35c4:	8de500bc */ 	lw	$a1,0xbc($t7)
/*  f0c35c8:	44812000 */ 	mtc1	$at,$f4
/*  f0c35cc:	44813000 */ 	mtc1	$at,$f6
/*  f0c35d0:	44815000 */ 	mtc1	$at,$f10
/*  f0c35d4:	00023400 */ 	sll	$a2,$v0,0x10
/*  f0c35d8:	0006c403 */ 	sra	$t8,$a2,0x10
/*  f0c35dc:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0c35e0:	34098400 */ 	dli	$t1,0x8400
/*  f0c35e4:	240affff */ 	addiu	$t2,$zero,-1
/*  f0c35e8:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f0c35ec:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0c35f0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0c35f4:	03003025 */ 	or	$a2,$t8,$zero
/*  f0c35f8:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c35fc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0c3600:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0c3604:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0c3608:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0c360c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c3610:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0c3614:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f0c3618:	e7a40030 */ 	swc1	$f4,0x30($sp)
/*  f0c361c:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f0c3620:	0fc24762 */ 	jal	func0f0939f8
/*  f0c3624:	e7aa0038 */ 	swc1	$f10,0x38($sp)
/*  f0c3628:	8fa300ec */ 	lw	$v1,0xec($sp)
.NB0f0c362c:
/*  f0c362c:	8e0b0314 */ 	lw	$t3,0x314($s0)
/*  f0c3630:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f0c3634:	55600039 */ 	bnezl	$t3,.NB0f0c371c
/*  f0c3638:	44804000 */ 	mtc1	$zero,$f8
/*  f0c363c:	81820006 */ 	lb	$v0,0x6($t4)
/*  f0c3640:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c3644:	10410003 */ 	beq	$v0,$at,.NB0f0c3654
/*  f0c3648:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0c364c:	54410033 */ 	bnel	$v0,$at,.NB0f0c371c
/*  f0c3650:	44804000 */ 	mtc1	$zero,$f8
.NB0f0c3654:
/*  f0c3654:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c3658:	8e0d0008 */ 	lw	$t5,0x8($s0)
/*  f0c365c:	3c098007 */ 	lui	$t1,0x8007
/*  f0c3660:	8dcf0034 */ 	lw	$t7,0x34($t6)
/*  f0c3664:	25293510 */ 	addiu	$t1,$t1,0x3510
/*  f0c3668:	01afc023 */ 	subu	$t8,$t5,$t7
/*  f0c366c:	2b010029 */ 	slti	$at,$t8,0x29
/*  f0c3670:	5420002a */ 	bnezl	$at,.NB0f0c371c
/*  f0c3674:	44804000 */ 	mtc1	$zero,$f8
/*  f0c3678:	8d210000 */ 	lw	$at,0x0($t1)
/*  f0c367c:	27b90064 */ 	addiu	$t9,$sp,0x64
/*  f0c3680:	8d2b0004 */ 	lw	$t3,0x4($t1)
/*  f0c3684:	af210000 */ 	sw	$at,0x0($t9)
/*  f0c3688:	8d210008 */ 	lw	$at,0x8($t1)
/*  f0c368c:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  f0c3690:	af210008 */ 	sw	$at,0x8($t9)
/*  f0c3694:	0c004d84 */ 	jal	random
/*  f0c3698:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c369c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c36a0:	0041001b */ 	divu	$zero,$v0,$at
/*  f0c36a4:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c36a8:	00007010 */ 	mfhi	$t6
/*  f0c36ac:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f0c36b0:	03ad3021 */ 	addu	$a2,$sp,$t5
/*  f0c36b4:	84c60066 */ 	lh	$a2,0x66($a2)
/*  f0c36b8:	8d8500bc */ 	lw	$a1,0xbc($t4)
/*  f0c36bc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c36c0:	44814000 */ 	mtc1	$at,$f8
/*  f0c36c4:	44812000 */ 	mtc1	$at,$f4
/*  f0c36c8:	44813000 */ 	mtc1	$at,$f6
/*  f0c36cc:	44815000 */ 	mtc1	$at,$f10
/*  f0c36d0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0c36d4:	34188400 */ 	dli	$t8,0x8400
/*  f0c36d8:	240affff */ 	addiu	$t2,$zero,-1
/*  f0c36dc:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f0c36e0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0c36e4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0c36e8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0c36ec:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0c36f0:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0c36f4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0c36f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c36fc:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0c3700:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f0c3704:	e7a40030 */ 	swc1	$f4,0x30($sp)
/*  f0c3708:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f0c370c:	0fc24762 */ 	jal	func0f0939f8
/*  f0c3710:	e7aa0038 */ 	swc1	$f10,0x38($sp)
/*  f0c3714:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c3718:	44804000 */ 	mtc1	$zero,$f8
.NB0f0c371c:
/*  f0c371c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c3720:	e7280080 */ 	swc1	$f8,0x80($t9)
/*  f0c3724:	8e090034 */ 	lw	$t1,0x34($s0)
.NB0f0c3728:
/*  f0c3728:	3c01bf90 */ 	lui	$at,0xbf90
/*  f0c372c:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f0c3730:	1920002c */ 	blez	$t1,.NB0f0c37e4
/*  f0c3734:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f0c3738:	44816000 */ 	mtc1	$at,$f12
/*  f0c373c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3740:	44809000 */ 	mtc1	$zero,$f18
/*  f0c3744:	c4227b18 */ 	lwc1	$f2,0x7b18($at)
/*  f0c3748:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c374c:
/*  f0c374c:	8c4b0090 */ 	lw	$t3,0x90($v0)
/*  f0c3750:	5960000c */ 	blezl	$t3,.NB0f0c3784
/*  f0c3754:	c4400094 */ 	lwc1	$f0,0x94($v0)
/*  f0c3758:	c4440088 */ 	lwc1	$f4,0x88($v0)
/*  f0c375c:	c44a0094 */ 	lwc1	$f10,0x94($v0)
/*  f0c3760:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0c3764:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0c3768:	e4480088 */ 	swc1	$f8,0x88($v0)
/*  f0c376c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3770:	8c4c0090 */ 	lw	$t4,0x90($v0)
/*  f0c3774:	258effff */ 	addiu	$t6,$t4,-1
/*  f0c3778:	10000015 */ 	beqz	$zero,.NB0f0c37d0
/*  f0c377c:	ac4e0090 */ 	sw	$t6,0x90($v0)
/*  f0c3780:	c4400094 */ 	lwc1	$f0,0x94($v0)
.NB0f0c3784:
/*  f0c3784:	4612003c */ 	c.lt.s	$f0,$f18
/*  f0c3788:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c378c:	4502000d */ 	bc1fl	.NB0f0c37c4
/*  f0c3790:	c4460088 */ 	lwc1	$f6,0x88($v0)
/*  f0c3794:	460c0101 */ 	sub.s	$f4,$f0,$f12
/*  f0c3798:	e4440094 */ 	swc1	$f4,0x94($v0)
/*  f0c379c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c37a0:	c4400094 */ 	lwc1	$f0,0x94($v0)
/*  f0c37a4:	4600903e */ 	c.le.s	$f18,$f0
/*  f0c37a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c37ac:	45020005 */ 	bc1fl	.NB0f0c37c4
/*  f0c37b0:	c4460088 */ 	lwc1	$f6,0x88($v0)
/*  f0c37b4:	e4520094 */ 	swc1	$f18,0x94($v0)
/*  f0c37b8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c37bc:	c4400094 */ 	lwc1	$f0,0x94($v0)
/*  f0c37c0:	c4460088 */ 	lwc1	$f6,0x88($v0)
.NB0f0c37c4:
/*  f0c37c4:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f0c37c8:	46005200 */ 	add.s	$f8,$f10,$f0
/*  f0c37cc:	e4480088 */ 	swc1	$f8,0x88($v0)
.NB0f0c37d0:
/*  f0c37d0:	8e0d0034 */ 	lw	$t5,0x34($s0)
/*  f0c37d4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0c37d8:	006d082a */ 	slt	$at,$v1,$t5
/*  f0c37dc:	5420ffdb */ 	bnezl	$at,.NB0f0c374c
/*  f0c37e0:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c37e4:
/*  f0c37e4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c37e8:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0c37ec:	44811000 */ 	mtc1	$at,$f2
/*  f0c37f0:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c37f4:	c4267b1c */ 	lwc1	$f6,0x7b1c($at)
/*  f0c37f8:	c4440088 */ 	lwc1	$f4,0x88($v0)
/*  f0c37fc:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3800:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f0c3804:	e44a008c */ 	swc1	$f10,0x8c($v0)
/*  f0c3808:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c380c:	c44803c4 */ 	lwc1	$f8,0x3c4($v0)
/*  f0c3810:	c4440414 */ 	lwc1	$f4,0x414($v0)
/*  f0c3814:	c44a19c4 */ 	lwc1	$f10,0x19c4($v0)
/*  f0c3818:	46044183 */ 	div.s	$f6,$f8,$f4
/*  f0c381c:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0c3820:	e44819bc */ 	swc1	$f8,0x19bc($v0)
/*  f0c3824:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3828:	8c4f19b8 */ 	lw	$t7,0x19b8($v0)
/*  f0c382c:	c44419bc */ 	lwc1	$f4,0x19bc($v0)
/*  f0c3830:	448f3000 */ 	mtc1	$t7,$f6
/*  f0c3834:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3838:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0c383c:	c446008c */ 	lwc1	$f6,0x8c($v0)
/*  f0c3840:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0c3844:	c44419c4 */ 	lwc1	$f4,0x19c4($v0)
/*  f0c3848:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0c384c:	c4267b20 */ 	lwc1	$f6,0x7b20($at)
/*  f0c3850:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f0c3854:	46044000 */ 	add.s	$f0,$f8,$f4
/*  f0c3858:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c385c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3860:	45020003 */ 	bc1fl	.NB0f0c3870
/*  f0c3864:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f0c3868:	46001006 */ 	mov.s	$f0,$f2
/*  f0c386c:	8c5800bc */ 	lw	$t8,0xbc($v0)
.NB0f0c3870:
/*  f0c3870:	c70a0008 */ 	lwc1	$f10,0x8($t8)
/*  f0c3874:	e7aa00a8 */ 	swc1	$f10,0xa8($sp)
/*  f0c3878:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c387c:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f0c3880:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0c3884:	e7a800ac */ 	swc1	$f8,0xac($sp)
/*  f0c3888:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f0c388c:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f0c3890:	c5440010 */ 	lwc1	$f4,0x10($t2)
/*  f0c3894:	e7a400b0 */ 	swc1	$f4,0xb0($sp)
/*  f0c3898:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f0c389c:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f0c38a0:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0c38a4:	46065032 */ 	c.eq.s	$f10,$f6
/*  f0c38a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c38ac:	4500000c */ 	bc1f	.NB0f0c38e0
/*  f0c38b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c38b4:	c464000c */ 	lwc1	$f4,0xc($v1)
/*  f0c38b8:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f0c38bc:	46044032 */ 	c.eq.s	$f8,$f4
/*  f0c38c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c38c4:	45000006 */ 	bc1f	.NB0f0c38e0
/*  f0c38c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c38cc:	c4660010 */ 	lwc1	$f6,0x10($v1)
/*  f0c38d0:	46065032 */ 	c.eq.s	$f10,$f6
/*  f0c38d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c38d8:	45030018 */ 	bc1tl	.NB0f0c393c
/*  f0c38dc:	8fbf004c */ 	lw	$ra,0x4c($sp)
.NB0f0c38e0:
/*  f0c38e0:	0fc19437 */ 	jal	func0f065e74
/*  f0c38e4:	24650028 */ 	addiu	$a1,$v1,0x28
/*  f0c38e8:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c38ec:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
/*  f0c38f0:	8f2900bc */ 	lw	$t1,0xbc($t9)
/*  f0c38f4:	e5280008 */ 	swc1	$f8,0x8($t1)
/*  f0c38f8:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c38fc:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f0c3900:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f0c3904:	e584000c */ 	swc1	$f4,0xc($t4)
/*  f0c3908:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c390c:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f0c3910:	8dcd00bc */ 	lw	$t5,0xbc($t6)
/*  f0c3914:	e5aa0010 */ 	swc1	$f10,0x10($t5)
/*  f0c3918:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c391c:	0fc193ab */ 	jal	propDeregisterRooms
/*  f0c3920:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f0c3924:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c3928:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f0c392c:	8f0500bc */ 	lw	$a1,0xbc($t8)
/*  f0c3930:	0fc19283 */ 	jal	roomsCopy
/*  f0c3934:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0c3938:	8fbf004c */ 	lw	$ra,0x4c($sp)
.NB0f0c393c:
/*  f0c393c:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0c3940:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
/*  f0c3944:	03e00008 */ 	jr	$ra
/*  f0c3948:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

void bwalkApplyCrouchSpeed(void)
{
	if (bmoveGetCrouchPos() == CROUCHPOS_DUCK) {
		g_Vars.currentplayer->speedforwards *= 0.5f;
		g_Vars.currentplayer->speedsideways *= 0.5f;
	} else if (bmoveGetCrouchPos() == CROUCHPOS_SQUAT) {
		g_Vars.currentplayer->speedforwards *= 0.35f;
		g_Vars.currentplayer->speedsideways *= 0.35f;
	}
}

void bwalkUpdateCrouchOffsetReal(void)
{
	if (g_Vars.currentplayer->vv_eyeheight + -90.0f * g_Vars.currentplayer->vv_eyeheight * (1.0f / 159.0f) < 69.0f) {
		g_Vars.currentplayer->crouchoffsetreal = g_Vars.currentplayer->crouchoffset * ((69.0f - g_Vars.currentplayer->vv_eyeheight) / -90.0f);
	} else {
		g_Vars.currentplayer->crouchoffsetreal = g_Vars.currentplayer->crouchoffset * g_Vars.currentplayer->vv_eyeheight * (1.0f / 159.0f);
	}

	if (cheatIsActive(CHEAT_SMALLJO)) {
		g_Vars.currentplayer->crouchoffsetsmall = 69.0f - g_Vars.currentplayer->vv_eyeheight;
		g_Vars.currentplayer->crouchoffsetrealsmall = 69.0f - g_Vars.currentplayer->vv_eyeheight;
	} else {
		g_Vars.currentplayer->crouchoffsetsmall = g_Vars.currentplayer->crouchoffset;
		g_Vars.currentplayer->crouchoffsetrealsmall = g_Vars.currentplayer->crouchoffsetreal;
	}
}

void bwalkUpdateCrouchOffset(void)
{
	f32 targetoffset = 0;

	if (bmoveGetCrouchPos() == CROUCHPOS_SQUAT) {
		targetoffset = -90;
	} else if (bmoveGetCrouchPos() == CROUCHPOS_DUCK) {
		targetoffset = -45;
	} else if (bmoveGetCrouchPos() == CROUCHPOS_STAND) {
		// empty
	}

	if (targetoffset != g_Vars.currentplayer->crouchoffset) {
		f32 prevcrouchoffset = g_Vars.currentplayer->crouchoffset;
		f32 prevcrouchoffsetreal = g_Vars.currentplayer->crouchoffsetreal;
		f32 prevcrouchoffsetsmall = g_Vars.currentplayer->crouchoffsetsmall;
		f32 prevcrouchoffsetrealsmall = g_Vars.currentplayer->crouchoffsetrealsmall;

		// f32 *frac, f32 maxfrac, f32 *fracspeed, f32 accel, f32 decel, f32 maxspeed
		applySpeed(&g_Vars.currentplayer->crouchoffset, targetoffset,
				&g_Vars.currentplayer->crouchspeed, PALUPF(0.5f), PALUPF(0.5f), PALUPF(5.0f));

		bwalkUpdateCrouchOffsetReal();

		if (bwalkTryMoveUpwards(0) == CDRESULT_COLLISION) {
			// Crouch adjustment is blocked by ceiling
			g_Vars.currentplayer->crouchoffset = prevcrouchoffset;
			g_Vars.currentplayer->crouchoffsetreal = prevcrouchoffsetreal;
			g_Vars.currentplayer->crouchoffsetsmall = prevcrouchoffsetsmall;
			g_Vars.currentplayer->crouchoffsetrealsmall = prevcrouchoffsetrealsmall;
			g_Vars.currentplayer->crouchspeed = 0;
			bwalkAdjustCrouchPos(-1);
		}
	}

	if (targetoffset == g_Vars.currentplayer->crouchoffset) {
		g_Vars.currentplayer->crouchspeed = 0;
	}

	g_Vars.currentplayer->guncloseroffset = g_Vars.currentplayer->crouchoffset / -90;
}

void bwalkUpdateTheta(void)
{
	f32 mult;
	f32 rotateamount;
	struct coord delta = {0, 0, 0};

	// Turn speed is calculated from the chr's height
	mult = 159.0f / g_Vars.currentplayer->vv_eyeheight;
	rotateamount = g_Vars.currentplayer->speedtheta * mult
		* g_Vars.lvupdate240freal * 0.0174505133f * 3.5f;

	bwalkCalculateNewPositionWithPush(&delta, rotateamount, true, 0, CDTYPE_ALL);
}

void bwalk0f0c63bc(struct coord *arg0, u32 arg1, s32 types)
{
	struct coord sp100;
	struct coord sp88;

	g_Vars.currentplayer->bondonturret = false;
	g_Vars.currentplayer->autocrouchpos = CROUCHPOS_STAND;

	bwalk0f0c4d98();

	if (bwalk0f0c4764(arg0, &sp100, &sp88, types) == CDRESULT_COLLISION) {
		struct coord sp76;
		struct coord sp64;

		s32 result = bwalk0f0c47d0(arg0, &sp100, &sp88, &sp76, &sp64, types);

		if (result >= CDRESULT_NOCOLLISION || result <= CDRESULT_ERROR) {
			if (result >= CDRESULT_NOCOLLISION) {
				bwalk0f0c4d98();
			}

			if (arg1
					&& bwalk0f0c494c(arg0, &sp100, &sp88, types) <= CDRESULT_COLLISION
					&& bwalk0f0c4a5c(arg0, &sp100, &sp88, types) <= CDRESULT_COLLISION) {
				// empty
			}
		} else if (result == CDRESULT_COLLISION) {
			struct coord sp48;
			struct coord sp36;

			if (bwalk0f0c47d0(arg0, &sp76, &sp64, &sp48, &sp36, types) >= CDRESULT_NOCOLLISION) {
				bwalk0f0c4d98();
			}

			if (arg1
					&& bwalk0f0c494c(arg0, &sp76, &sp64, types) <= CDRESULT_COLLISION
					&& bwalk0f0c494c(arg0, &sp100, &sp88, types) <= CDRESULT_COLLISION
					&& bwalk0f0c4a5c(arg0, &sp76, &sp64, types) <= CDRESULT_COLLISION) {
				bwalk0f0c4a5c(arg0, &sp100, &sp88, types);
			}
		}
	}

	bwalk0f0c4d98();
}

void bwalkUpdatePrevPos(void)
{
	g_Vars.currentplayer->bondprevpos.x = g_Vars.currentplayer->prop->pos.x;
	g_Vars.currentplayer->bondprevpos.y = g_Vars.currentplayer->prop->pos.y;
	g_Vars.currentplayer->bondprevpos.z = g_Vars.currentplayer->prop->pos.z;

	roomsCopy(g_Vars.currentplayer->prop->rooms, g_Vars.currentplayer->bondprevrooms);
}

void bwalkHandleActivate(void)
{
	if (g_Vars.currentplayer->walkinitmove) {
		g_Vars.currentplayer->bondactivateorreload = 0;
	}
}

void bwalkApplyMoveData(struct movedata *data)
{
	if (g_Vars.currentplayer->walkinitmove == false) {
		// Sideways
		if (data->digitalstepleft) {
			bwalkUpdateSpeedSideways(-1, 0.2f, data->digitalstepleft);
		} else if (data->digitalstepright) {
			bwalkUpdateSpeedSideways(1, 0.2f, data->digitalstepright);
		} else if (data->unk14 == false) {
			bwalkUpdateSpeedSideways(0, 0.2f, g_Vars.lvupdate240_60);
		}

		if (data->unk14) {
			bwalkUpdateSpeedSideways(data->analogstrafe * 0.014285714365542f, 0.2f, g_Vars.lvupdate240_60);
		}

		// Forward/back
		if (data->digitalstepforward) {
			bwalkUpdateSpeedForwards(1, 1);
			g_Vars.currentplayer->speedmaxtime60 += g_Vars.lvupdate240_60;
		} else if (data->digitalstepback) {
			bwalkUpdateSpeedForwards(-1, 1);
		} else if (data->canlookahead == false) {
			bwalkUpdateSpeedForwards(0, 1);
		}

		if (data->canlookahead) {
			bwalkUpdateSpeedForwards(data->analogwalk * 0.014285714365542f, 1);

			if (data->analogwalk > 60) {
				g_Vars.currentplayer->speedmaxtime60 += g_Vars.lvupdate240_60;
			} else {
				g_Vars.currentplayer->speedmaxtime60 = 0;
			}
		}

		// Force speeds to range -1 to 1
		if (g_Vars.currentplayer->speedforwards > 1) {
			g_Vars.currentplayer->speedforwards = 1;
		}

		if (g_Vars.currentplayer->speedforwards < -1) {
			g_Vars.currentplayer->speedforwards = -1;
		}

		if (g_Vars.currentplayer->speedsideways > 1) {
			g_Vars.currentplayer->speedsideways = 1;
		}

		if (g_Vars.currentplayer->speedsideways < -1) {
			g_Vars.currentplayer->speedsideways = -1;
		}

		g_Vars.currentplayer->speedforwards *= 1.08f;
		g_Vars.currentplayer->speedforwards *= g_Vars.currentplayer->speedboost;

		if ((data->canlookahead == false && data->digitalstepforward == false) ||
				bmoveGetCrouchPos() != CROUCHPOS_STAND) {
			g_Vars.currentplayer->speedmaxtime60 = 0;
		}

		if (data->rleanleft) {
			bwalkSetSwayTarget(-1);
		} else if (data->rleanright) {
			bwalkSetSwayTarget(1);
		} else {
			bwalkSetSwayTarget(0);
		}

		while (data->crouchdown-- > 0) {
			bwalkAdjustCrouchPos(-1);
		}

		while (data->crouchup-- > 0) {
			bwalkAdjustCrouchPos(1);
		}

		g_Vars.currentplayer->eyesshut = data->eyesshut;
	}
}

void bwalkUpdateSpeedTheta(void)
{
	if (bmoveGetCrouchPos() == CROUCHPOS_SQUAT) {
		g_Vars.currentplayer->speedtheta *= 0.5f;
	} else if (bmoveGetCrouchPos() == CROUCHPOS_DUCK) {
		g_Vars.currentplayer->speedtheta *= 0.75f;
	}
}

void bwalk0f0c69b8(void)
{
	s32 i;
	f32 spe0;
	f32 spdc;
	f32 spd8;
	struct coord spcc = {0, 0, 0};
	f32 spc8;
	f32 spc4;
	f32 spc0;
	f32 tmp1;
	f32 tmp2;
	f32 spb4;
	f32 spb0;
	f32 dist;
	f32 spa8;
	f32 mult;
	f32 f0;
	f32 lvupdate240f;
	s32 lvupdate240;
	s32 cdresult;
	struct escalatorobj *esc;
	f32 sp8c;
	f32 sp88;
	f32 speedforwards;
	f32 speedsideways;
	f32 speedtheta;
	f32 maxspeed;
	f32 sp74;
	f32 width;
	f32 ymax;
	f32 ymin;
	f32 xdiff;
	f32 zdiff;
	f32 xdelta;
	f32 zdelta;
	f32 sp54;
	f32 sp50;
	f32 sp4c;
	f32 sp48;
	f32 sp44;
	f32 sp40;
	f32 sp3c;
	f32 breathing;

	spc0 = g_Vars.currentplayer->vv_eyeheight - 159;

	if (invHasBriefcase() && ((g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE || g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE))) {
		spc0 = -63.600006f;
	}

	spc0 = spc0 / 353.33331298828f + 1.0f;

	if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_FASTMOVEMENT)) {
		spc0 *= 1.25f;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (cheatIsActive(CHEAT_SMALLJO)) {
		spc0 *= 0.4f;
	}
#endif

	if (g_Vars.currentplayer->walkinitmove) {
		g_Vars.currentplayer->walkinitt += g_Vars.lvupdate240freal * (1.0f / 60.0f);

		if (g_Vars.currentplayer->walkinitt >= 1.0f) {
			g_Vars.currentplayer->walkinitt = 1.0f;
			g_Vars.currentplayer->walkinitmove = false;
		}

		g_Vars.currentplayer->walkinitt2 = 1.0f - (cosf(g_Vars.currentplayer->walkinitt * M_BADPI) + 1.0f) * 0.5f;

		bmoveUpdateHead(0.0f, 0.0f, 0.0f, &g_Vars.currentplayer->walkinitmtx, 1.0f - g_Vars.currentplayer->walkinitt2);

		g_Vars.currentplayer->gunspeed = 0.0f;

		bmoveUpdateMoveInitSpeed(&spcc);
		bwalkCalculateNewPositionWithPush(&spcc, 0.0f, true, 0.0f, CDTYPE_ALL);
	} else {
		bwalkApplyCrouchSpeed();
		bwalkUpdateCrouchOffset();

		bmove0f0cba88(&spc8, &spc4,
				&g_Vars.currentplayer->bondshotspeed,
				g_Vars.currentplayer->vv_sintheta, g_Vars.currentplayer->vv_costheta);

		tmp1 = -g_Vars.currentplayer->swaytarget * g_Vars.currentplayer->bond2.unk00.f[2];
		tmp2 = g_Vars.currentplayer->swaytarget * g_Vars.currentplayer->bond2.unk00.f[0];
		tmp1 *= spc0;
		tmp2 *= spc0;
		spa8 = 0.0f;

		if (g_Vars.currentplayer->crouchoffset < -45.0f) {
			tmp1 *= 0.35f;
			tmp2 *= 0.35f;
		} else if (g_Vars.currentplayer->crouchoffset < 0.0f) {
			tmp1 *= 0.5f;
			tmp2 *= 0.5f;
		}

		spb4 = tmp1 - g_Vars.currentplayer->swayoffset0;
		spb0 = tmp2 - g_Vars.currentplayer->swayoffset2;

		dist = sqrtf(spb4 * spb4 + spb0 * spb0);

		if (g_Vars.lvupdate240freal > PALUPF(4)) {
			lvupdate240f = PALUPF(4);
			lvupdate240 = 4;
		} else {
			lvupdate240f = g_Vars.lvupdate240freal;
			lvupdate240 = g_Vars.lvupdate240_60;
		}

		for (i = 0; i < lvupdate240; i++) {
			spa8 += (dist - spa8) * PALUPF(0.1f);
		}

		spa8 += 3.75f * lvupdate240f;

		if (g_Vars.currentplayer->crouchoffset < -45.0f) {
			spa8 *= 0.35f;
		} else if (g_Vars.currentplayer->crouchoffset < 0.0f) {
			spa8 *= 0.5f;
		}

		if (spa8 < dist) {
			spa8 /= dist;
			spb4 *= spa8;
			spb0 *= spa8;
		}

		speedsideways = (g_Vars.currentplayer->speedsideways + spc4) * 0.8f;
		speedforwards = g_Vars.currentplayer->speedforwards + spc8;
		speedtheta = g_Vars.currentplayer->speedtheta * 0.8f;

		if (speedsideways < 0.0f) {
			speedsideways = -speedsideways;
		}

		if (speedforwards < 0.0f) {
			speedforwards = -speedforwards;
		}

		if (speedtheta < 0.0f) {
			speedtheta = -speedtheta;
		}

		maxspeed = speedforwards;

		if (speedsideways > maxspeed) {
			maxspeed = speedsideways;
		}

		if (speedtheta > maxspeed) {
			maxspeed = speedtheta;
		}

		if (dist >= 0.1f && maxspeed < 0.8f) {
			maxspeed = 0.8f;
		}

		if (maxspeed >= 0.75f) {
			g_Vars.currentplayer->bondbreathing += (maxspeed - 0.75f) * g_Vars.lvupdate240freal / 900;
		} else {
			g_Vars.currentplayer->bondbreathing -= (0.75f - maxspeed) * g_Vars.lvupdate240freal / 2700;
		}

		if (g_Vars.currentplayer->bondbreathing < 0.0f) {
			g_Vars.currentplayer->bondbreathing = 0.0f;
		} else if (g_Vars.currentplayer->bondbreathing > 1.0f) {
			g_Vars.currentplayer->bondbreathing = 1.0f;
		}

		mult = var80075c00[1].unk0c * 0.5f * g_Vars.lvupdate240freal;
		spe0 = (g_Vars.currentplayer->speedsideways * spc0 + spc4) * mult;

#if VERSION >= VERSION_NTSC_1_0
		if (cheatIsActive(CHEAT_SMALLJO)) {
			spe0 /= 0.4f;
		}
#endif

		bmove0f0cc654(maxspeed, g_Vars.currentplayer->speedforwards * spc0 + spc8, spe0);

		g_Vars.currentplayer->gunspeed = maxspeed;

		spdc = g_Vars.currentplayer->headpos.x;
		spd8 = g_Vars.currentplayer->headpos.z;

#if VERSION >= VERSION_NTSC_1_0
		if (cheatIsActive(CHEAT_SMALLJO)) {
			spdc *= 0.4f;
		}
#endif

		spcc.f[0] += (spd8 * g_Vars.currentplayer->bond2.unk00.f[0] - spdc * g_Vars.currentplayer->bond2.unk00.f[2]) * g_Vars.lvupdate240freal;
		spcc.f[2] += (spd8 * g_Vars.currentplayer->bond2.unk00.f[2] + spdc * g_Vars.currentplayer->bond2.unk00.f[0]) * g_Vars.lvupdate240freal;
		spcc.f[0] += spb4;
		spcc.f[2] += spb0;

		bmoveUpdateMoveInitSpeed(&spcc);

		if (debugIsTurboModeEnabled()) {
			spcc.f[0] += (g_Vars.currentplayer->bond2.unk00.f[0] * g_Vars.currentplayer->speedforwards - g_Vars.currentplayer->bond2.unk00.f[2] * g_Vars.currentplayer->speedsideways) * g_Vars.lvupdate240freal * 10.0f;
			spcc.f[2] += (g_Vars.currentplayer->bond2.unk00.f[2] * g_Vars.currentplayer->speedforwards + g_Vars.currentplayer->bond2.unk00.f[0] * g_Vars.currentplayer->speedsideways) * g_Vars.lvupdate240freal * 10.0f;
		}

		if (g_Vars.currentplayer->bondforcespeed.f[0] != 0.0f || g_Vars.currentplayer->bondforcespeed.f[2] != 0.0f) {
			spcc.f[0] += g_Vars.currentplayer->bondforcespeed.f[0] * g_Vars.lvupdate240freal;
			spcc.f[2] += g_Vars.currentplayer->bondforcespeed.f[2] * g_Vars.lvupdate240freal;
		}

		if (g_Vars.currentplayer->onladder) {
			guNormalize(&g_Vars.currentplayer->laddernormal.x, &g_Vars.currentplayer->laddernormal.y, &g_Vars.currentplayer->laddernormal.z);

			sp74 = -(spcc.f[0] * g_Vars.currentplayer->laddernormal.f[0] + spcc.f[2] * g_Vars.currentplayer->laddernormal.f[2]);

			if (-4.0f * g_Vars.lvupdate240freal < sp74) {
				if (sp74 < 0.0f) {
					spcc.f[0] += sp74 * g_Vars.currentplayer->laddernormal.f[0];
					spcc.f[2] += sp74 * g_Vars.currentplayer->laddernormal.f[2];
					g_Vars.currentplayer->ladderupdown = sp74 * 0.3f;
				} else {
					playerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);

					cdresult = cd0002a13c(&g_Vars.currentplayer->prop->pos,
							width * 1.1f, ymax - g_Vars.currentplayer->prop->pos.y,
							(g_Vars.currentplayer->vv_manground - g_Vars.currentplayer->prop->pos.y) + 1.0f,
							g_Vars.currentplayer->prop->rooms, 0x8040);

					if (cdresult == CDRESULT_COLLISION) {
						g_Vars.currentplayer->ladderupdown = 0.0f;
					} else {
						spcc.f[0] += sp74 * g_Vars.currentplayer->laddernormal.f[0];
						spcc.f[2] += sp74 * g_Vars.currentplayer->laddernormal.f[2];
						g_Vars.currentplayer->ladderupdown = sp74 * 0.3f;
					}
				}

				spcc.x *= 0.3f;
				spcc.z *= 0.3f;
			} else {
				g_Vars.currentplayer->ladderupdown = 0.0f;
			}
		}

		if (g_Vars.currentplayer->lift) {
			esc = (struct escalatorobj *) g_Vars.currentplayer->lift->obj;

			if (esc->base.type == OBJTYPE_ESCASTEP) {
				spcc.x += esc->base.prop->pos.x - esc->prevpos.x;
				spcc.z += esc->base.prop->pos.z - esc->prevpos.z;
			}
		}

		sp8c = g_Vars.currentplayer->prop->pos.x;
		sp88 = g_Vars.currentplayer->prop->pos.z;

		bwalk0f0c63bc(&spcc, g_Vars.currentplayer->swaytarget == 0.0f, CDTYPE_ALL);

		xdelta = g_Vars.currentplayer->prop->pos.x - g_Vars.currentplayer->bondprevpos.x;
		zdelta = g_Vars.currentplayer->prop->pos.z - g_Vars.currentplayer->bondprevpos.z;

		sp54 = -xdelta * g_Vars.currentplayer->bond2.unk00.f[2] + zdelta * g_Vars.currentplayer->bond2.unk00.f[0];
		sp50 = xdelta * g_Vars.currentplayer->bond2.unk00.f[0] + zdelta * g_Vars.currentplayer->bond2.unk00.f[2];

		sp4c = -spcc.f[0] * g_Vars.currentplayer->bond2.unk00.f[2] + spcc.f[2] * g_Vars.currentplayer->bond2.unk00.f[0];
		sp48 = spcc.f[0] * g_Vars.currentplayer->bond2.unk00.f[0] + spcc.f[2] * g_Vars.currentplayer->bond2.unk00.f[2];

		if (xdelta >= 0.0f) {
			if (g_Vars.currentplayer->bondshotspeed.f[0] > 0.0f) {
				if (spcc.f[0] >= 0.0f && xdelta < spcc.f[0]) {
					g_Vars.currentplayer->bondshotspeed.f[0] *= xdelta / spcc.f[0];
				}
			} else {
				if (spcc.f[0] < 0.0f) {
					g_Vars.currentplayer->bondshotspeed.f[0] = 0.0f;
				}
			}
		} else {
			if (g_Vars.currentplayer->bondshotspeed.f[0] < 0.0f) {
				if (spcc.f[0] <= 0.0f && spcc.f[0] < xdelta) {
					g_Vars.currentplayer->bondshotspeed.f[0] *= xdelta / spcc.f[0];
				}
			} else {
				if (spcc.f[0] > 0.0f) {
					g_Vars.currentplayer->bondshotspeed.f[0] = 0.0f;
				}
			}
		}

		if (zdelta >= 0.0f) {
			if (g_Vars.currentplayer->bondshotspeed.f[2] > 0.0f) {
				if (spcc.f[2] >= 0.0f && zdelta < spcc.f[2]) {
					g_Vars.currentplayer->bondshotspeed.f[2] *= zdelta / spcc.f[2];
				}
			} else {
				if (spcc.f[2] < 0.0f) {
					g_Vars.currentplayer->bondshotspeed.f[2] = 0.0f;
				}
			}
		} else {
			if (g_Vars.currentplayer->bondshotspeed.f[2] < 0.0f) {
				if (spcc.f[2] <= 0.0f && spcc.f[2] < zdelta) {
					g_Vars.currentplayer->bondshotspeed.f[2] *= zdelta / spcc.f[2];
				}
			} else {
				if (spcc.f[2] > 0.0f) {
					g_Vars.currentplayer->bondshotspeed.f[2] = 0.0f;
				}
			}
		}

		if (sp4c != 0.0f && g_Vars.currentplayer->speedstrafe * sp4c > 0.0f) {
			sp54 /= sp4c;

			if (sp54 <= 0.0f) {
				g_Vars.currentplayer->speedstrafe = 0.0f;
			} else if (sp54 < 1.0f) {
				g_Vars.currentplayer->speedstrafe *= sp54;
			}
		}

		if (sp48 != 0.0f) {
			if (g_Vars.currentplayer->speedgo * sp48 > 0.0f) {
				sp50 /= sp48;

				if (sp50 <= 0.0f) {
					g_Vars.currentplayer->speedgo = 0.0f;
				} else if (sp50 < 1.0f) {
					g_Vars.currentplayer->speedgo *= sp50;
				}
			}
		}

		xdiff = g_Vars.currentplayer->prop->pos.x - sp8c;
		zdiff = g_Vars.currentplayer->prop->pos.z - sp88;
		f0 = spcc.f[0] * spcc.f[0] + spcc.f[2] * spcc.f[2];

		if (f0 != 0.0f) {
			f0 = (xdiff * xdiff + zdiff * zdiff) / f0;
		}

		f0 = sqrtf(f0);
		g_Vars.currentplayer->swayoffset0 += f0 * spb4;
		g_Vars.currentplayer->swayoffset2 += f0 * spb0;
	}

	sp44 = g_Vars.currentplayer->speedtheta;
	sp40 = g_Vars.currentplayer->speedverta / 0.7f + g_Vars.currentplayer->crouchspeed / PALUPF(5.0f);
	sp3c = g_Vars.currentplayer->gunspeed;

	breathing = bheadGetBreathingValue();

	if (sp40 > 1.0f) {
		sp40 = 1.0f;
	} else if (sp40 < -1.0f) {
		sp40 = -1.0f;
	}

	if (g_Vars.currentplayer->headanim == 1) {
		breathing *= 1.2f;
	}

	bgun0f09d8dc(breathing, sp3c, sp40, sp44, 0.0f);
	bgunSetAdjustPos(g_Vars.currentplayer->vv_verta360 * 0.017450513318181f);
}

void bwalkTick(void)
{
	bwalkUpdatePrevPos();
	bwalkUpdateTheta();
	bmoveUpdateVerta();
	bwalk0f0c69b8();
	bwalkUpdateVertical();

#if VERSION >= VERSION_NTSC_1_0
	{
		s32 i;

		for (i = 0; g_Vars.currentplayer->prop->rooms[i] != -1; i++) {
			if (g_Vars.currentplayer->floorroom == g_Vars.currentplayer->prop->rooms[i]) {
				propDeregisterRooms(g_Vars.currentplayer->prop);
				g_Vars.currentplayer->prop->rooms[0] = g_Vars.currentplayer->floorroom;
				g_Vars.currentplayer->prop->rooms[1] = -1;
				break;
			}
		}
	}
#endif

	bmove0f0cb8c4(g_Vars.currentplayer);
	objectiveCheckRoomEntered(g_Vars.currentplayer->prop->rooms[0]);

	if (g_Vars.currentplayer->walkinitmove) {
		struct coord coord;
		coord.x = (g_Vars.currentplayer->walkinitstart.x - g_Vars.currentplayer->walkinitpos.x)
			* (1.0f - g_Vars.currentplayer->walkinitt2) + g_Vars.currentplayer->prop->pos.x;

		coord.y = (g_Vars.currentplayer->walkinitstart.y - g_Vars.currentplayer->prop->pos.y)
			* (1.0f - g_Vars.currentplayer->walkinitt2) + g_Vars.currentplayer->prop->pos.y;

		coord.z = (g_Vars.currentplayer->walkinitstart.z - g_Vars.currentplayer->walkinitpos.z)
			* (1.0f - g_Vars.currentplayer->walkinitt2) + g_Vars.currentplayer->prop->pos.z;

		bmove0f0cc19c(&coord);
	} else {
		bmove0f0cc19c(&g_Vars.currentplayer->prop->pos);
	}

	playerUpdatePerimInfo();
	doorsCheckAutomatic();
}
