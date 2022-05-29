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

void bwalkUpdateVertical(void)
{
	s32 i;
	f32 newfallspeed;
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
#if VERSION >= VERSION_NTSC_1_0
	f32 limit;
	f32 amount;
	struct prop *prop;
#endif
	f32 newmanground;
	f32 fallspeed;
	f32 eyeheight;
	f32 multiplier;
#if VERSION >= VERSION_NTSC_1_0
	struct defaultobj *obj;
#endif

	playerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);

#if VERSION >= VERSION_NTSC_1_0
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
#endif

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

#if VERSION >= VERSION_NTSC_1_0
		if (moveamount != 0)
#endif
		{
			// The lift is moving
			if (g_Vars.currentplayer->isfalling == false && lift == g_Vars.currentplayer->lift) {
				if (g_Vars.currentplayer->liftground - g_Vars.currentplayer->vv_manground < 1.0f
						&& g_Vars.currentplayer->liftground - g_Vars.currentplayer->vv_manground > -1.0f) {
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

			if (sumground < g_Vars.currentplayer->vv_ground - 50) {
				sumground = g_Vars.currentplayer->vv_ground - 50;
			}

			if (bwalkTryMoveUpwards(sumground - g_Vars.currentplayer->vv_manground) == CDRESULT_NOCOLLISION) {
				g_Vars.currentplayer->vv_manground = sumground;
			}
#if VERSION >= VERSION_NTSC_1_0
			else {
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
#endif
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
#if VERSION >= VERSION_NTSC_1_0
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
#endif

			g_Vars.currentplayer->bdeltapos.y = VERSION >= VERSION_NTSC_1_0 ? 0.0f : 0;

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
							-1, -1, 0x8400, 0, 0, 0, -1, NULL, -1, -1, -1, -1);
				}

				chr->footstep = 2;
				sound = footstepChooseSound(chr, true);

				if (sound != -1) {
					func0f0939f8(NULL, g_Vars.currentplayer->prop, sound,
							-1, -1, 0x8400, 0, 0, 0, -1, NULL, -1, -1, -1, -1);
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
						-1, -1, 0x8400, 0, 0, 0, -1, NULL, -1, -1, -1, -1);
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

#if VERSION >= VERSION_NTSC_1_0
	if (newpos.y < g_Vars.currentplayer->vv_ground + 10) {
		newpos.y = g_Vars.currentplayer->vv_ground + 10;
	}
#endif

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
