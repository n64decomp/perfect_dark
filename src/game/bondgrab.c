#include <ultra64.h>
#include "constants.h"
#include "game/bondgrab.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_0601b0.h"
#include "game/propobj.h"
#include "game/game_095320.h"
#include "game/game_097ba0.h"
#include "game/game_0b63b0.h"
#include "game/bondmove.h"
#include "game/game_113220.h"
#include "game/game_11ecf0.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1ad940[] = "bondgrab.c";
const char var7f1ad94c[] = "bondgrab.c";
const char var7f1ad958[] = "bondgrab.c";

void currentPlayerGrabInit(void)
{
	u32 prevmode = g_Vars.currentplayer->bondmovemode;
	f32 matrix[16];
	struct prop *prop = g_Vars.currentplayer->grabbedprop;

	g_Vars.currentplayer->bondmovemode = MOVEMODE_GRAB;

	g_Vars.currentplayer->unk1b60 = 0;
	g_Vars.currentplayer->grabbedprevpos.x = prop->pos.x;
	g_Vars.currentplayer->grabbedprevpos.y = prop->pos.y;
	g_Vars.currentplayer->grabbedprevpos.z = prop->pos.z;
	g_Vars.currentplayer->grabbedrotoffset = 0;
	g_Vars.currentplayer->unk1c58 = 0;
	g_Vars.currentplayer->grabbedposoffset.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
	g_Vars.currentplayer->grabbedposoffset.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
	g_Vars.currentplayer->grabbedposoffset.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;
	g_Vars.currentplayer->grabbeddoextra = 0;
	g_Vars.currentplayer->grabbedrotextra = 0;
	g_Vars.currentplayer->grabbedposextra.x = 0;
	g_Vars.currentplayer->grabbedposextra.y = 0;
	g_Vars.currentplayer->grabbedposextra.z = 0;
	g_Vars.currentplayer->grabbedrotextrasum = 0;
	g_Vars.currentplayer->grabbedposextrasum.x = 0;
	g_Vars.currentplayer->grabbedposextrasum.y = 0;
	g_Vars.currentplayer->grabbedposextrasum.z = 0;
	g_Vars.currentplayer->guncloseroffset = 0;
	g_Vars.currentplayer->gunextraaimx = 0;
	g_Vars.currentplayer->gunextraaimy = 0;

	func00016374((g_Vars.currentplayer->vv_theta * M_TAU) / 360.0f, matrix);
	func00015b10(matrix, &g_Vars.currentplayer->grabbedposoffset);

	g_Vars.currentplayer->bondprevtheta = g_Vars.currentplayer->vv_theta;

	if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_DOOR || prop->type == PROPTYPE_WEAPON) {
		struct defaultobj *obj = prop->obj;
		struct hov *hov = NULL;
		bool setthething;

		if (obj->hidden & OBJHFLAG_00000080) {
			struct obj48 *obj48 = obj->unk48;
			g_Vars.currentplayer->bondshotspeed[0] += obj48->unk04.x * 0.2f;
			g_Vars.currentplayer->bondshotspeed[2] += obj48->unk04.z * 0.2f;
			func0f06ac40(obj);
		}

		if (obj->type == OBJTYPE_HOVERPROP) {
			struct hoverpropobj *hoverprop = (struct hoverpropobj *)prop->obj;
			hov = &hoverprop->hov;
		} else if (obj->type == OBJTYPE_HOVERBIKE) {
			struct hoverbikeobj *hoverprop = (struct hoverbikeobj *)prop->obj;
			hov = &hoverprop->hov;
		}

		if (hov) {
			g_Vars.currentplayer->grabbedrotoffset =
				hov->unk10 - (M_TAU - (g_Vars.currentplayer->vv_theta * M_TAU) / 360.0f);

			if (g_Vars.currentplayer->grabbedrotoffset >= M_TAU) {
				g_Vars.currentplayer->grabbedrotoffset -= M_TAU;
			} else if (g_Vars.currentplayer->grabbedrotoffset < 0) {
				g_Vars.currentplayer->grabbedrotoffset += M_TAU;
			}
		}

		obj->hidden |= OBJHFLAG_GRABBED;

		if (obj->flags3 & OBJFLAG3_02000000) {
			setthething = func000276c8(obj->geo,
					g_Vars.currentplayer->prop->pos.x,
					g_Vars.currentplayer->prop->pos.z, 45, 0, 0);
		} else {
			setthething = func000274e0(obj->geo,
					g_Vars.currentplayer->prop->pos.x,
					g_Vars.currentplayer->prop->pos.z, 45, 0, 0);
		}

		if (setthething) {
			g_Vars.currentplayer->unk1c58 = 15;
		}
	}

	if (prevmode != MOVEMODE_GRAB && prevmode != MOVEMODE_WALK) {
		s32 i;

		for (i = 0; i != 3; i++) {
			g_Vars.currentplayer->bondshotspeed[i] = 0;
		}

		g_Vars.currentplayer->speedsideways = 0;
		g_Vars.currentplayer->speedstrafe = 0;
		g_Vars.currentplayer->speedgo = 0;
		g_Vars.currentplayer->speedboost = 1;
		g_Vars.currentplayer->speedmaxtime60 = 0;
		g_Vars.currentplayer->speedforwards = 0;
		g_Vars.currentplayer->speedtheta = 0;
		g_Vars.currentplayer->speedthetacontrol = 0;
		g_Vars.currentplayer->moveinitspeed.x = 0;
		g_Vars.currentplayer->moveinitspeed.y = 0;
		g_Vars.currentplayer->moveinitspeed.z = 0;
	}

	g_Vars.currentplayer->grabstarttime = g_Vars.lvframe60;
}

void currentPlayerUpdateGrabbedPropForRelease(void)
{
	struct coord moveamount;
	struct defaultobj *obj;
	f32 rotateamount;

	if (g_Vars.currentplayer->grabbedprop) {
		struct defaultobj *obj = g_Vars.currentplayer->grabbedprop->obj;
		obj->hidden &= ~OBJHFLAG_GRABBED;

		if (g_Vars.lvupdate240 > 0) {
			moveamount.x = (g_Vars.currentplayer->grabbedprop->pos.x - g_Vars.currentplayer->grabbedprevpos.x) / g_Vars.lvupdate240freal;
			moveamount.y = 0;
			moveamount.z = (g_Vars.currentplayer->grabbedprop->pos.z - g_Vars.currentplayer->grabbedprevpos.z) / g_Vars.lvupdate240freal;

			rotateamount = -(g_Vars.currentplayer->vv_theta - g_Vars.currentplayer->bondprevtheta)
				* M_TAU / 360;

			if (rotateamount < -M_PI) {
				rotateamount += M_TAU;
			} else if (rotateamount >= M_PI) {
				rotateamount -= M_TAU;
			}

			rotateamount /= g_Vars.lvupdate240freal;

			func0f082a1c(g_Vars.currentplayer->grabbedprop->obj, &moveamount,
					rotateamount, 0, 0);
		}

		g_Vars.currentplayer->grabbedprop = NULL;
	}
}

GLOBAL_ASM(
glabel func0f0ccbf0
.late_rodata
glabel var7f1ad990
.word 0x3dcccccd
.text
/*  f0ccbf0:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0ccbf4:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0ccbf8:	8c6e0034 */ 	lw	$t6,0x34($v1)
/*  f0ccbfc:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f0ccc00:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0ccc04:	afa400e0 */ 	sw	$a0,0xe0($sp)
/*  f0ccc08:	afa500e4 */ 	sw	$a1,0xe4($sp)
/*  f0ccc0c:	19c0010f */ 	blez	$t6,.L0f0cd04c
/*  f0ccc10:	afa600e8 */ 	sw	$a2,0xe8($sp)
/*  f0ccc14:	3c0f800a */ 	lui	$t7,%hi(var8009de70)
/*  f0ccc18:	8defde70 */ 	lw	$t7,%lo(var8009de70)($t7)
/*  f0ccc1c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0ccc20:	27ae0074 */ 	addiu	$t6,$sp,0x74
/*  f0ccc24:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f0ccc28:	3c0f8007 */ 	lui	$t7,%hi(var80070e84)
/*  f0ccc2c:	25ef0e84 */ 	addiu	$t7,$t7,%lo(var80070e84)
/*  f0ccc30:	1701004f */ 	bne	$t8,$at,.L0f0ccd70
/*  f0ccc34:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f0ccc38:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ccc3c:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f0ccc40:	3c077f1b */ 	lui	$a3,%hi(var7f1ad940)
/*  f0ccc44:	8c4800bc */ 	lw	$t0,0xbc($v0)
/*  f0ccc48:	24e7d940 */ 	addiu	$a3,$a3,%lo(var7f1ad940)
/*  f0ccc4c:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0ccc50:	c5060008 */ 	lwc1	$f6,0x8($t0)
/*  f0ccc54:	240600c9 */ 	addiu	$a2,$zero,0xc9
/*  f0ccc58:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0ccc5c:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f0ccc60:	8c4900bc */ 	lw	$t1,0xbc($v0)
/*  f0ccc64:	c52a000c */ 	lwc1	$f10,0xc($t1)
/*  f0ccc68:	e7aa009c */ 	swc1	$f10,0x9c($sp)
/*  f0ccc6c:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f0ccc70:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f0ccc74:	27a400b0 */ 	addiu	$a0,$sp,0xb0
/*  f0ccc78:	c5460010 */ 	lwc1	$f6,0x10($t2)
/*  f0ccc7c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0ccc80:	0c009393 */ 	jal	func00024e4c
/*  f0ccc84:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*  f0ccc88:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f0ccc8c:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f0ccc90:	44809000 */ 	mtc1	$zero,$f18
/*  f0ccc94:	c7a600b0 */ 	lwc1	$f6,0xb0($sp)
/*  f0ccc98:	46045001 */ 	sub.s	$f0,$f10,$f4
/*  f0ccc9c:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f0ccca0:	27a400c8 */ 	addiu	$a0,$sp,0xc8
/*  f0ccca4:	27a500cc */ 	addiu	$a1,$sp,0xcc
/*  f0ccca8:	46009032 */ 	c.eq.s	$f18,$f0
/*  f0cccac:	e7a000c8 */ 	swc1	$f0,0xc8($sp)
/*  f0cccb0:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0cccb4:	e7b200cc */ 	swc1	$f18,0xcc($sp)
/*  f0cccb8:	45000005 */ 	bc1f	.L0f0cccd0
/*  f0cccbc:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
/*  f0cccc0:	460a9032 */ 	c.eq.s	$f18,$f10
/*  f0cccc4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cccc8:	45030006 */ 	bc1tl	.L0f0ccce4
/*  f0ccccc:	44812000 */ 	mtc1	$at,$f4
.L0f0cccd0:
/*  f0cccd0:	0c0011e4 */ 	jal	scaleTo1
/*  f0cccd4:	27a600d0 */ 	addiu	$a2,$sp,0xd0
/*  f0cccd8:	10000005 */ 	beqz	$zero,.L0f0cccf0
/*  f0cccdc:	27ab00d4 */ 	addiu	$t3,$sp,0xd4
/*  f0ccce0:	44812000 */ 	mtc1	$at,$f4
.L0f0ccce4:
/*  f0ccce4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccce8:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*  f0cccec:	27ab00d4 */ 	addiu	$t3,$sp,0xd4
.L0f0cccf0:
/*  f0cccf0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0cccf4:	27a400b0 */ 	addiu	$a0,$sp,0xb0
/*  f0cccf8:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0cccfc:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f0ccd00:	0fc0b8f7 */ 	jal	func0f02e3dc
/*  f0ccd04:	27a700c8 */ 	addiu	$a3,$sp,0xc8
/*  f0ccd08:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0ccd0c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0ccd10:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ccd14:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f0ccd18:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0ccd1c:	8c4c00bc */ 	lw	$t4,0xbc($v0)
/*  f0ccd20:	44809000 */ 	mtc1	$zero,$f18
/*  f0ccd24:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f0ccd28:	c5880008 */ 	lwc1	$f8,0x8($t4)
/*  f0ccd2c:	e7b200c0 */ 	swc1	$f18,0xc0($sp)
/*  f0ccd30:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*  f0ccd34:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0ccd38:	c7a600a0 */ 	lwc1	$f6,0xa0($sp)
/*  f0ccd3c:	27a600c8 */ 	addiu	$a2,$sp,0xc8
/*  f0ccd40:	27a700bc */ 	addiu	$a3,$sp,0xbc
/*  f0ccd44:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f0ccd48:	e7a400bc */ 	swc1	$f4,0xbc($sp)
/*  f0ccd4c:	8c4d00bc */ 	lw	$t5,0xbc($v0)
/*  f0ccd50:	c5a80010 */ 	lwc1	$f8,0x10($t5)
/*  f0ccd54:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0ccd58:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0ccd5c:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f0ccd60:	0fc20ba1 */ 	jal	func0f082e84
/*  f0ccd64:	e7a400c4 */ 	swc1	$f4,0xc4($sp)
/*  f0ccd68:	100000b9 */ 	beqz	$zero,.L0f0cd050
/*  f0ccd6c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0ccd70:
/*  f0ccd70:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0ccd74:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f0ccd78:	3c077f1b */ 	lui	$a3,%hi(var7f1ad94c)
/*  f0ccd7c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0ccd80:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0ccd84:	24e7d94c */ 	addiu	$a3,$a3,%lo(var7f1ad94c)
/*  f0ccd88:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0ccd8c:	240600e4 */ 	addiu	$a2,$zero,0xe4
/*  f0ccd90:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f0ccd94:	0c009393 */ 	jal	func00024e4c
/*  f0ccd98:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0ccd9c:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f0ccda0:	0c0094d9 */ 	jal	func00025364
/*  f0ccda4:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0ccda8:	1040000e */ 	beqz	$v0,.L0f0ccde4
/*  f0ccdac:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0ccdb0:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f0ccdb4:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f0ccdb8:	c7a40048 */ 	lwc1	$f4,0x48($sp)
/*  f0ccdbc:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0ccdc0:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*  f0ccdc4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0ccdc8:	e7aa0044 */ 	swc1	$f10,0x44($sp)
/*  f0ccdcc:	c7aa004c */ 	lwc1	$f10,0x4c($sp)
/*  f0ccdd0:	c7a40058 */ 	lwc1	$f4,0x58($sp)
/*  f0ccdd4:	e7a80048 */ 	swc1	$f8,0x48($sp)
/*  f0ccdd8:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0ccddc:	10000019 */ 	beqz	$zero,.L0f0cce44
/*  f0ccde0:	e7a6004c */ 	swc1	$f6,0x4c($sp)
.L0f0ccde4:
/*  f0ccde4:	3c02800a */ 	lui	$v0,%hi(var8009de70)
/*  f0ccde8:	8c42de70 */ 	lw	$v0,%lo(var8009de70)($v0)
/*  f0ccdec:	8fb900e8 */ 	lw	$t9,0xe8($sp)
/*  f0ccdf0:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0ccdf4:	e7a80050 */ 	swc1	$f8,0x50($sp)
/*  f0ccdf8:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f0ccdfc:	e7aa0054 */ 	swc1	$f10,0x54($sp)
/*  f0cce00:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0cce04:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f0cce08:	8f2a0014 */ 	lw	$t2,0x14($t9)
/*  f0cce0c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0cce10:	c5460008 */ 	lwc1	$f6,0x8($t2)
/*  f0cce14:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0cce18:	e7aa0044 */ 	swc1	$f10,0x44($sp)
/*  f0cce1c:	8f2b0014 */ 	lw	$t3,0x14($t9)
/*  f0cce20:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f0cce24:	c564000c */ 	lwc1	$f4,0xc($t3)
/*  f0cce28:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0cce2c:	e7a80048 */ 	swc1	$f8,0x48($sp)
/*  f0cce30:	8f2c0014 */ 	lw	$t4,0x14($t9)
/*  f0cce34:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0cce38:	c58a0010 */ 	lwc1	$f10,0x10($t4)
/*  f0cce3c:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0cce40:	e7a6004c */ 	swc1	$f6,0x4c($sp)
.L0f0cce44:
/*  f0cce44:	27ad008c */ 	addiu	$t5,$sp,0x8c
/*  f0cce48:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0cce4c:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f0cce50:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0cce54:	0fc0b8f7 */ 	jal	func0f02e3dc
/*  f0cce58:	27a70044 */ 	addiu	$a3,$sp,0x44
/*  f0cce5c:	8fa200e0 */ 	lw	$v0,0xe0($sp)
/*  f0cce60:	44809000 */ 	mtc1	$zero,$f18
/*  f0cce64:	27a40080 */ 	addiu	$a0,$sp,0x80
/*  f0cce68:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f0cce6c:	e7b20084 */ 	swc1	$f18,0x84($sp)
/*  f0cce70:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f0cce74:	e7a80080 */ 	swc1	$f8,0x80($sp)
/*  f0cce78:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0cce7c:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0cce80:	46049032 */ 	c.eq.s	$f18,$f4
/*  f0cce84:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f0cce88:	c7a60088 */ 	lwc1	$f6,0x88($sp)
/*  f0cce8c:	45000005 */ 	bc1f	.L0f0ccea4
/*  f0cce90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cce94:	46069032 */ 	c.eq.s	$f18,$f6
/*  f0cce98:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cce9c:	45030007 */ 	bc1tl	.L0f0ccebc
/*  f0ccea0:	44814000 */ 	mtc1	$at,$f8
.L0f0ccea4:
/*  f0ccea4:	0c0011e4 */ 	jal	scaleTo1
/*  f0ccea8:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f0cceac:	44809000 */ 	mtc1	$zero,$f18
/*  f0cceb0:	10000004 */ 	beqz	$zero,.L0f0ccec4
/*  f0cceb4:	8fa200e0 */ 	lw	$v0,0xe0($sp)
/*  f0cceb8:	44814000 */ 	mtc1	$at,$f8
.L0f0ccebc:
/*  f0ccebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccec0:	e7a80088 */ 	swc1	$f8,0x88($sp)
.L0f0ccec4:
/*  f0ccec4:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f0ccec8:	3c01800a */ 	lui	$at,0x800a
/*  f0ccecc:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0cced0:	46009032 */ 	c.eq.s	$f18,$f0
/*  f0cced4:	27a60080 */ 	addiu	$a2,$sp,0x80
/*  f0cced8:	27a70074 */ 	addiu	$a3,$sp,0x74
/*  f0ccedc:	45030007 */ 	bc1tl	.L0f0ccefc
/*  f0ccee0:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f0ccee4:	c424a00c */ 	lwc1	$f4,-0x5ff4($at)
/*  f0ccee8:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f0cceec:	46040183 */ 	div.s	$f6,$f0,$f4
/*  f0ccef0:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0ccef4:	e7a80074 */ 	swc1	$f8,0x74($sp)
/*  f0ccef8:	c4400008 */ 	lwc1	$f0,0x8($v0)
.L0f0ccefc:
/*  f0ccefc:	3c01800a */ 	lui	$at,0x800a
/*  f0ccf00:	46009032 */ 	c.eq.s	$f18,$f0
/*  f0ccf04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccf08:	45030007 */ 	bc1tl	.L0f0ccf28
/*  f0ccf0c:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f0ccf10:	c42aa00c */ 	lwc1	$f10,-0x5ff4($at)
/*  f0ccf14:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f0ccf18:	460a0183 */ 	div.s	$f6,$f0,$f10
/*  f0ccf1c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0ccf20:	e7a8007c */ 	swc1	$f8,0x7c($sp)
/*  f0ccf24:	8fa400e8 */ 	lw	$a0,0xe8($sp)
.L0f0ccf28:
/*  f0ccf28:	0fc20ba1 */ 	jal	func0f082e84
/*  f0ccf2c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0ccf30:	44809000 */ 	mtc1	$zero,$f18
/*  f0ccf34:	c7aa00e4 */ 	lwc1	$f10,0xe4($sp)
/*  f0ccf38:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x284)
/*  f0ccf3c:	46125032 */ 	c.eq.s	$f10,$f18
/*  f0ccf40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccf44:	45030042 */ 	bc1tl	.L0f0cd050
/*  f0ccf48:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0ccf4c:	8d08a244 */ 	lw	$t0,%lo(g_Vars+0x284)($t0)
/*  f0ccf50:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f0ccf54:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f0ccf58:	8d0200bc */ 	lw	$v0,0xbc($t0)
/*  f0ccf5c:	3c0e8007 */ 	lui	$t6,%hi(var80070e90)
/*  f0ccf60:	25ce0e90 */ 	addiu	$t6,$t6,%lo(var80070e90)
/*  f0ccf64:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0ccf68:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f0ccf6c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0ccf70:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f0ccf74:	27b8002c */ 	addiu	$t8,$sp,0x2c
/*  f0ccf78:	af010000 */ 	sw	$at,0x0($t8)
/*  f0ccf7c:	460a4381 */ 	sub.s	$f14,$f8,$f10
/*  f0ccf80:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f0ccf84:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0ccf88:	8dc90004 */ 	lw	$t1,0x4($t6)
/*  f0ccf8c:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f0ccf90:	af010008 */ 	sw	$at,0x8($t8)
/*  f0ccf94:	af090004 */ 	sw	$t1,0x4($t8)
/*  f0ccf98:	e7ae003c */ 	swc1	$f14,0x3c($sp)
/*  f0ccf9c:	e7a20040 */ 	swc1	$f2,0x40($sp)
/*  f0ccfa0:	0c012974 */ 	jal	sqrtf
/*  f0ccfa4:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f0ccfa8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ccfac:	44814000 */ 	mtc1	$at,$f8
/*  f0ccfb0:	3c01800a */ 	lui	$at,0x800a
/*  f0ccfb4:	c424a00c */ 	lwc1	$f4,-0x5ff4($at)
/*  f0ccfb8:	46004303 */ 	div.s	$f12,$f8,$f0
/*  f0ccfbc:	c7aa00e4 */ 	lwc1	$f10,0xe4($sp)
/*  f0ccfc0:	c7a20040 */ 	lwc1	$f2,0x40($sp)
/*  f0ccfc4:	c7ae003c */ 	lwc1	$f14,0x3c($sp)
/*  f0ccfc8:	3c014220 */ 	lui	$at,0x4220
/*  f0ccfcc:	44809000 */ 	mtc1	$zero,$f18
/*  f0ccfd0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ccfd4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ccfd8:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f0ccfdc:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*  f0ccfe0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0ccfe4:	46045183 */ 	div.s	$f6,$f10,$f4
/*  f0ccfe8:	44812000 */ 	mtc1	$at,$f4
/*  f0ccfec:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0ccff0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccff4:	460c7382 */ 	mul.s	$f14,$f14,$f12
/*  f0ccff8:	46007207 */ 	neg.s	$f8,$f14
/*  f0ccffc:	e7a600e4 */ 	swc1	$f6,0xe4($sp)
/*  f0cd000:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0cd004:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd008:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f0cd00c:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f0cd010:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0cd014:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f0cd018:	44814000 */ 	mtc1	$at,$f8
/*  f0cd01c:	3c017f1b */ 	lui	$at,%hi(var7f1ad990)
/*  f0cd020:	e7a4002c */ 	swc1	$f4,0x2c($sp)
/*  f0cd024:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0cd028:	c7aa0034 */ 	lwc1	$f10,0x34($sp)
/*  f0cd02c:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f0cd030:	c42ad990 */ 	lwc1	$f10,%lo(var7f1ad990)($at)
/*  f0cd034:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f0cd038:	e7a80034 */ 	swc1	$f8,0x34($sp)
/*  f0cd03c:	46049400 */ 	add.s	$f16,$f18,$f4
/*  f0cd040:	44068000 */ 	mfc1	$a2,$f16
/*  f0cd044:	0fc20a87 */ 	jal	func0f082a1c
/*  f0cd048:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cd04c:
/*  f0cd04c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0cd050:
/*  f0cd050:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
/*  f0cd054:	03e00008 */ 	jr	$ra
/*  f0cd058:	00000000 */ 	sll	$zero,$zero,0x0
);

bool func0f0cd05c(f32 y)
{
	bool result;
	struct coord newpos;
	s16 rooms[8];
	f32 ymax;
	f32 ymin;
	f32 width;

	newpos.x = g_Vars.currentplayer->prop->pos.x;
	newpos.y = g_Vars.currentplayer->prop->pos.y + y;
	newpos.z = g_Vars.currentplayer->prop->pos.z;

	propPlayerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);
	func0f065e74(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, &newpos, rooms);
	func0f0cb79c(g_Vars.currentplayer, &newpos, rooms);
	func0f064178(g_Vars.currentplayer->prop, false);

	ymin -= 0.1f;

	result = func0002a684(&newpos, width, rooms, 63, 1,
			ymax - g_Vars.currentplayer->prop->pos.y,
			ymin - g_Vars.currentplayer->prop->pos.y);

	func0f064178(g_Vars.currentplayer->prop, true);

	if (result == 1) {
		g_Vars.currentplayer->prop->pos.y = newpos.y;
		func0f065c44(g_Vars.currentplayer->prop);
		roomsCopy(rooms, g_Vars.currentplayer->prop->rooms);
	}

	return result;
}

GLOBAL_ASM(
glabel func0f0cd1a4
.late_rodata
glabel var7f1ad998
.word 0x3c8ef461
glabel var7f1ad99c
.word 0x3f7cbfb1
glabel var7f1ad9a0
.word 0x3c5013c0
glabel var7f1ad9a4
.word 0x40490fdb
glabel var7f1ad9a8
.word 0x40c907a9
glabel var7f1ad9ac
.word 0xc0490fdb
glabel var7f1ad9b0
.word 0x40c907a9
glabel var7f1ad9b4
.word 0x40c907a9
glabel var7f1ad9b8
.word 0x40c907a9
glabel var7f1ad9bc
.word 0x40c907a9
glabel var7f1ad9c0
.word 0x40c907a9
glabel var7f1ad9c4
.word 0x40c907a9
.text
/*  f0cd1a4:	27bdff10 */ 	addiu	$sp,$sp,-240
/*  f0cd1a8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0cd1ac:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0cd1b0:	3c018007 */ 	lui	$at,0x8007
/*  f0cd1b4:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0cd1b8:	ac200e80 */ 	sw	$zero,0xe80($at)
/*  f0cd1bc:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0cd1c0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0cd1c4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0cd1c8:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f0cd1cc:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0cd1d0:	afa400f0 */ 	sw	$a0,0xf0($sp)
/*  f0cd1d4:	afa500f4 */ 	sw	$a1,0xf4($sp)
/*  f0cd1d8:	afa600f8 */ 	sw	$a2,0xf8($sp)
/*  f0cd1dc:	afae00ec */ 	sw	$t6,0xec($sp)
/*  f0cd1e0:	afa000c8 */ 	sw	$zero,0xc8($sp)
/*  f0cd1e4:	27a600c4 */ 	addiu	$a2,$sp,0xc4
/*  f0cd1e8:	27a500bc */ 	addiu	$a1,$sp,0xbc
/*  f0cd1ec:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f0cd1f0:	0fc3082e */ 	jal	propPlayerGetBbox
/*  f0cd1f4:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f0cd1f8:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cd1fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cd200:	0fc1905e */ 	jal	func0f064178
/*  f0cd204:	8f0400bc */ 	lw	$a0,0xbc($t8)
/*  f0cd208:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cd20c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cd210:	0fc1905e */ 	jal	func0f064178
/*  f0cd214:	8f241b5c */ 	lw	$a0,0x1b5c($t9)
/*  f0cd218:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cd21c:	8fa300f0 */ 	lw	$v1,0xf0($sp)
/*  f0cd220:	4480a000 */ 	mtc1	$zero,$f20
/*  f0cd224:	8d0900bc */ 	lw	$t1,0xbc($t0)
/*  f0cd228:	c5240008 */ 	lwc1	$f4,0x8($t1)
/*  f0cd22c:	e7a400dc */ 	swc1	$f4,0xdc($sp)
/*  f0cd230:	8d0a00bc */ 	lw	$t2,0xbc($t0)
/*  f0cd234:	c546000c */ 	lwc1	$f6,0xc($t2)
/*  f0cd238:	e7a600e0 */ 	swc1	$f6,0xe0($sp)
/*  f0cd23c:	8d0b00bc */ 	lw	$t3,0xbc($t0)
/*  f0cd240:	c7a600dc */ 	lwc1	$f6,0xdc($sp)
/*  f0cd244:	c5680010 */ 	lwc1	$f8,0x10($t3)
/*  f0cd248:	e7a800e4 */ 	swc1	$f8,0xe4($sp)
/*  f0cd24c:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f0cd250:	4600a032 */ 	c.eq.s	$f20,$f0
/*  f0cd254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd258:	4502000c */ 	bc1fl	.L0f0cd28c
/*  f0cd25c:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0cd260:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f0cd264:	460aa032 */ 	c.eq.s	$f20,$f10
/*  f0cd268:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd26c:	45020007 */ 	bc1fl	.L0f0cd28c
/*  f0cd270:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0cd274:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0cd278:	4604a032 */ 	c.eq.s	$f20,$f4
/*  f0cd27c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd280:	45030047 */ 	bc1tl	.L0f0cd3a0
/*  f0cd284:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0cd288:	46003200 */ 	add.s	$f8,$f6,$f0
.L0f0cd28c:
/*  f0cd28c:	c7aa00e0 */ 	lwc1	$f10,0xe0($sp)
/*  f0cd290:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f0cd294:	27a700cc */ 	addiu	$a3,$sp,0xcc
/*  f0cd298:	e7a800dc */ 	swc1	$f8,0xdc($sp)
/*  f0cd29c:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f0cd2a0:	c7a800e4 */ 	lwc1	$f8,0xe4($sp)
/*  f0cd2a4:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0cd2a8:	e7a600e0 */ 	swc1	$f6,0xe0($sp)
/*  f0cd2ac:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f0cd2b0:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0cd2b4:	e7a400e4 */ 	swc1	$f4,0xe4($sp)
/*  f0cd2b8:	8d0200bc */ 	lw	$v0,0xbc($t0)
/*  f0cd2bc:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0cd2c0:	0fc1979d */ 	jal	func0f065e74
/*  f0cd2c4:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0cd2c8:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0cd2cc:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f0cd2d0:	0fc32de7 */ 	jal	func0f0cb79c
/*  f0cd2d4:	27a600cc */ 	addiu	$a2,$sp,0xcc
/*  f0cd2d8:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0cd2dc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0cd2e0:	afac00c8 */ 	sw	$t4,0xc8($sp)
/*  f0cd2e4:	8da200bc */ 	lw	$v0,0xbc($t5)
/*  f0cd2e8:	240e003f */ 	addiu	$t6,$zero,0x3f
/*  f0cd2ec:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0cd2f0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0cd2f4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0cd2f8:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0cd2fc:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0cd300:	c7aa00c0 */ 	lwc1	$f10,0xc0($sp)
/*  f0cd304:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f0cd308:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0cd30c:	27a700cc */ 	addiu	$a3,$sp,0xcc
/*  f0cd310:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0cd314:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0cd318:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*  f0cd31c:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0cd320:	0c00b62e */ 	jal	func0002d8b8
/*  f0cd324:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f0cd328:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd32c:	14410014 */ 	bne	$v0,$at,.L0f0cd380
/*  f0cd330:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f0cd334:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cd338:	2419003f */ 	addiu	$t9,$zero,0x3f
/*  f0cd33c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0cd340:	8f0200bc */ 	lw	$v0,0xbc($t8)
/*  f0cd344:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0cd348:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0cd34c:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0cd350:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0cd354:	c7aa00c0 */ 	lwc1	$f10,0xc0($sp)
/*  f0cd358:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f0cd35c:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0cd360:	8fa600bc */ 	lw	$a2,0xbc($sp)
/*  f0cd364:	27a700cc */ 	addiu	$a3,$sp,0xcc
/*  f0cd368:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0cd36c:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*  f0cd370:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0cd374:	0c00a9bf */ 	jal	func0002a6fc
/*  f0cd378:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f0cd37c:	afa200ec */ 	sw	$v0,0xec($sp)
.L0f0cd380:
/*  f0cd380:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd384:	50410006 */ 	beql	$v0,$at,.L0f0cd3a0
/*  f0cd388:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0cd38c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0cd390:	3c01800a */ 	lui	$at,%hi(var8009de70)
/*  f0cd394:	8d4b00bc */ 	lw	$t3,0xbc($t2)
/*  f0cd398:	ac2bde70 */ 	sw	$t3,%lo(var8009de70)($at)
/*  f0cd39c:	8e0c0284 */ 	lw	$t4,0x284($s0)
.L0f0cd3a0:
/*  f0cd3a0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cd3a4:	0fc1905e */ 	jal	func0f064178
/*  f0cd3a8:	8d841b5c */ 	lw	$a0,0x1b5c($t4)
/*  f0cd3ac:	8fad00ec */ 	lw	$t5,0xec($sp)
/*  f0cd3b0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd3b4:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f0cd3b8:	55a1010c */ 	bnel	$t5,$at,.L0f0cd7ec
/*  f0cd3bc:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0cd3c0:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cd3c4:	46003387 */ 	neg.s	$f14,$f6
/*  f0cd3c8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cd3cc:	e7ae004c */ 	swc1	$f14,0x4c($sp)
/*  f0cd3d0:	8d0f1a1c */ 	lw	$t7,0x1a1c($t0)
/*  f0cd3d4:	8d0e1b5c */ 	lw	$t6,0x1b5c($t0)
/*  f0cd3d8:	3c014120 */ 	lui	$at,0x4120
/*  f0cd3dc:	11e0005d */ 	beqz	$t7,.L0f0cd554
/*  f0cd3e0:	8dc50004 */ 	lw	$a1,0x4($t6)
/*  f0cd3e4:	44811000 */ 	mtc1	$at,$f2
/*  f0cd3e8:	c50a0148 */ 	lwc1	$f10,0x148($t0)
/*  f0cd3ec:	3c017f1b */ 	lui	$at,%hi(var7f1ad998)
/*  f0cd3f0:	c426d998 */ 	lwc1	$f6,%lo(var7f1ad998)($at)
/*  f0cd3f4:	46005107 */ 	neg.s	$f4,$f10
/*  f0cd3f8:	3c014060 */ 	lui	$at,0x4060
/*  f0cd3fc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0cd400:	44815000 */ 	mtc1	$at,$f10
/*  f0cd404:	3c0140c0 */ 	lui	$at,0x40c0
/*  f0cd408:	44812000 */ 	mtc1	$at,$f4
/*  f0cd40c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0cd410:	44813000 */ 	mtc1	$at,$f6
/*  f0cd414:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0cd418:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f0cd41c:	44815000 */ 	mtc1	$at,$f10
/*  f0cd420:	8e030034 */ 	lw	$v1,0x34($s0)
/*  f0cd424:	3c017f1b */ 	lui	$at,%hi(var7f1ad99c)
/*  f0cd428:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cd42c:	46040402 */ 	mul.s	$f16,$f0,$f4
/*  f0cd430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd434:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0cd438:	c5060168 */ 	lwc1	$f6,0x168($t0)
/*  f0cd43c:	e7b4008c */ 	swc1	$f20,0x8c($sp)
/*  f0cd440:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0cd444:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd448:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0cd44c:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0cd450:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f0cd454:	c5060170 */ 	lwc1	$f6,0x170($t0)
/*  f0cd458:	46003107 */ 	neg.s	$f4,$f6
/*  f0cd45c:	c5061c58 */ 	lwc1	$f6,0x1c58($t0)
/*  f0cd460:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f0cd464:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0cd468:	e7a40090 */ 	swc1	$f4,0x90($sp)
/*  f0cd46c:	c5081a3c */ 	lwc1	$f8,0x1a3c($t0)
/*  f0cd470:	c5161a38 */ 	lwc1	$f22,0x1a38($t0)
/*  f0cd474:	e7a800ac */ 	swc1	$f8,0xac($sp)
/*  f0cd478:	c5061a40 */ 	lwc1	$f6,0x1a40($t0)
/*  f0cd47c:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0cd480:	e7a600b0 */ 	swc1	$f6,0xb0($sp)
/*  f0cd484:	c5081a44 */ 	lwc1	$f8,0x1a44($t0)
/*  f0cd488:	18600024 */ 	blez	$v1,.L0f0cd51c
/*  f0cd48c:	e7a800b4 */ 	swc1	$f8,0xb4($sp)
/*  f0cd490:	46002306 */ 	mov.s	$f12,$f4
/*  f0cd494:	46005086 */ 	mov.s	$f2,$f10
/*  f0cd498:	c420d99c */ 	lwc1	$f0,%lo(var7f1ad99c)($at)
/*  f0cd49c:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f0cd4a0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0cd4a4:	0043082a */ 	slt	$at,$v0,$v1
/*  f0cd4a8:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0cd4ac:	10200011 */ 	beqz	$at,.L0f0cd4f4
/*  f0cd4b0:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
.L0f0cd4b4:
/*  f0cd4b4:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0cd4b8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0cd4bc:	0043082a */ 	slt	$at,$v0,$v1
/*  f0cd4c0:	46160102 */ 	mul.s	$f4,$f0,$f22
/*  f0cd4c4:	4608a280 */ 	add.s	$f10,$f20,$f8
/*  f0cd4c8:	46120202 */ 	mul.s	$f8,$f0,$f18
/*  f0cd4cc:	46066180 */ 	add.s	$f6,$f12,$f6
/*  f0cd4d0:	e7aa00b0 */ 	swc1	$f10,0xb0($sp)
/*  f0cd4d4:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f0cd4d8:	46102580 */ 	add.s	$f22,$f4,$f16
/*  f0cd4dc:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*  f0cd4e0:	46081480 */ 	add.s	$f18,$f2,$f8
/*  f0cd4e4:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0cd4e8:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f0cd4ec:	1420fff1 */ 	bnez	$at,.L0f0cd4b4
/*  f0cd4f0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cd4f4:
/*  f0cd4f4:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0cd4f8:	4608a280 */ 	add.s	$f10,$f20,$f8
/*  f0cd4fc:	46160102 */ 	mul.s	$f4,$f0,$f22
/*  f0cd500:	e7aa00b0 */ 	swc1	$f10,0xb0($sp)
/*  f0cd504:	46120202 */ 	mul.s	$f8,$f0,$f18
/*  f0cd508:	46066180 */ 	add.s	$f6,$f12,$f6
/*  f0cd50c:	46102580 */ 	add.s	$f22,$f4,$f16
/*  f0cd510:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*  f0cd514:	46081480 */ 	add.s	$f18,$f2,$f8
/*  f0cd518:	e7b200ac */ 	swc1	$f18,0xac($sp)
.L0f0cd51c:
/*  f0cd51c:	3c017f1b */ 	lui	$at,%hi(var7f1ad9a0)
/*  f0cd520:	c420d9a0 */ 	lwc1	$f0,%lo(var7f1ad9a0)($at)
/*  f0cd524:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0cd528:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f0cd52c:	4600b182 */ 	mul.s	$f6,$f22,$f0
/*  f0cd530:	e7a600a8 */ 	swc1	$f6,0xa8($sp)
/*  f0cd534:	46009202 */ 	mul.s	$f8,$f18,$f0
/*  f0cd538:	c7a600b4 */ 	lwc1	$f6,0xb4($sp)
/*  f0cd53c:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0cd540:	e7a8009c */ 	swc1	$f8,0x9c($sp)
/*  f0cd544:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0cd548:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f0cd54c:	1000000a */ 	beqz	$zero,.L0f0cd578
/*  f0cd550:	e7a800a4 */ 	swc1	$f8,0xa4($sp)
.L0f0cd554:
/*  f0cd554:	c5041a20 */ 	lwc1	$f4,0x1a20($t0)
/*  f0cd558:	c7b600b8 */ 	lwc1	$f22,0xb8($sp)
/*  f0cd55c:	e7a400a8 */ 	swc1	$f4,0xa8($sp)
/*  f0cd560:	c50a1a2c */ 	lwc1	$f10,0x1a2c($t0)
/*  f0cd564:	e7aa009c */ 	swc1	$f10,0x9c($sp)
/*  f0cd568:	c5061a30 */ 	lwc1	$f6,0x1a30($t0)
/*  f0cd56c:	e7a600a0 */ 	swc1	$f6,0xa0($sp)
/*  f0cd570:	c5081a34 */ 	lwc1	$f8,0x1a34($t0)
/*  f0cd574:	e7a800a4 */ 	swc1	$f8,0xa4($sp)
.L0f0cd578:
/*  f0cd578:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f0cd57c:	24010035 */ 	addiu	$at,$zero,0x35
/*  f0cd580:	c7040000 */ 	lwc1	$f4,0x0($t8)
/*  f0cd584:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f0cd588:	c70a0004 */ 	lwc1	$f10,0x4($t8)
/*  f0cd58c:	e7aa0080 */ 	swc1	$f10,0x80($sp)
/*  f0cd590:	c7060008 */ 	lwc1	$f6,0x8($t8)
/*  f0cd594:	e7a60084 */ 	swc1	$f6,0x84($sp)
/*  f0cd598:	90a20003 */ 	lbu	$v0,0x3($a1)
/*  f0cd59c:	54410006 */ 	bnel	$v0,$at,.L0f0cd5b8
/*  f0cd5a0:	24010033 */ 	addiu	$at,$zero,0x33
/*  f0cd5a4:	8d191b5c */ 	lw	$t9,0x1b5c($t0)
/*  f0cd5a8:	8f220004 */ 	lw	$v0,0x4($t9)
/*  f0cd5ac:	10000007 */ 	beqz	$zero,.L0f0cd5cc
/*  f0cd5b0:	2444005c */ 	addiu	$a0,$v0,0x5c
/*  f0cd5b4:	24010033 */ 	addiu	$at,$zero,0x33
.L0f0cd5b8:
/*  f0cd5b8:	14410004 */ 	bne	$v0,$at,.L0f0cd5cc
/*  f0cd5bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd5c0:	8d091b5c */ 	lw	$t1,0x1b5c($t0)
/*  f0cd5c4:	8d220004 */ 	lw	$v0,0x4($t1)
/*  f0cd5c8:	2444005c */ 	addiu	$a0,$v0,0x5c
.L0f0cd5cc:
/*  f0cd5cc:	10800026 */ 	beqz	$a0,.L0f0cd668
/*  f0cd5d0:	3c017f1b */ 	lui	$at,%hi(var7f1ad9a4)
/*  f0cd5d4:	c420d9a4 */ 	lwc1	$f0,%lo(var7f1ad9a4)($at)
/*  f0cd5d8:	3c017f1b */ 	lui	$at,%hi(var7f1ad9a8)
/*  f0cd5dc:	c422d9a8 */ 	lwc1	$f2,%lo(var7f1ad9a8)($at)
/*  f0cd5e0:	c5080144 */ 	lwc1	$f8,0x144($t0)
/*  f0cd5e4:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cd5e8:	44818000 */ 	mtc1	$at,$f16
/*  f0cd5ec:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f0cd5f0:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*  f0cd5f4:	3c017f1b */ 	lui	$at,%hi(var7f1ad9ac)
/*  f0cd5f8:	46102283 */ 	div.s	$f10,$f4,$f16
/*  f0cd5fc:	460a1181 */ 	sub.s	$f6,$f2,$f10
/*  f0cd600:	c50a1a0c */ 	lwc1	$f10,0x1a0c($t0)
/*  f0cd604:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0cd608:	c4880010 */ 	lwc1	$f8,0x10($a0)
/*  f0cd60c:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0cd610:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f0cd614:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0cd618:	460a2380 */ 	add.s	$f14,$f4,$f10
/*  f0cd61c:	460e003e */ 	c.le.s	$f0,$f14
/*  f0cd620:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd624:	45000006 */ 	bc1f	.L0f0cd640
/*  f0cd628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd62c:	46027381 */ 	sub.s	$f14,$f14,$f2
.L0f0cd630:
/*  f0cd630:	460e003e */ 	c.le.s	$f0,$f14
/*  f0cd634:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd638:	4503fffd */ 	bc1tl	.L0f0cd630
/*  f0cd63c:	46027381 */ 	sub.s	$f14,$f14,$f2
.L0f0cd640:
/*  f0cd640:	c420d9ac */ 	lwc1	$f0,%lo(var7f1ad9ac)($at)
/*  f0cd644:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cd648:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd64c:	45020007 */ 	bc1fl	.L0f0cd66c
/*  f0cd650:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f0cd654:	46027380 */ 	add.s	$f14,$f14,$f2
.L0f0cd658:
/*  f0cd658:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cd65c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd660:	4503fffd */ 	bc1tl	.L0f0cd658
/*  f0cd664:	46027380 */ 	add.s	$f14,$f14,$f2
.L0f0cd668:
/*  f0cd668:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
.L0f0cd66c:
/*  f0cd66c:	3c017f1b */ 	lui	$at,%hi(var7f1ad9b0)
/*  f0cd670:	c422d9b0 */ 	lwc1	$f2,%lo(var7f1ad9b0)($at)
/*  f0cd674:	46143032 */ 	c.eq.s	$f6,$f20
/*  f0cd678:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cd67c:	44818000 */ 	mtc1	$at,$f16
/*  f0cd680:	45020005 */ 	bc1fl	.L0f0cd698
/*  f0cd684:	c5080144 */ 	lwc1	$f8,0x144($t0)
/*  f0cd688:	8d0a1a1c */ 	lw	$t2,0x1a1c($t0)
/*  f0cd68c:	51400034 */ 	beqzl	$t2,.L0f0cd760
/*  f0cd690:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0cd694:	c5080144 */ 	lwc1	$f8,0x144($t0)
.L0f0cd698:
/*  f0cd698:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f0cd69c:	c7a800f4 */ 	lwc1	$f8,0xf4($sp)
/*  f0cd6a0:	46102283 */ 	div.s	$f10,$f4,$f16
/*  f0cd6a4:	460a1181 */ 	sub.s	$f6,$f2,$f10
/*  f0cd6a8:	46083301 */ 	sub.s	$f12,$f6,$f8
/*  f0cd6ac:	460c103e */ 	c.le.s	$f2,$f12
/*  f0cd6b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd6b4:	45020004 */ 	bc1fl	.L0f0cd6c8
/*  f0cd6b8:	4614603c */ 	c.lt.s	$f12,$f20
/*  f0cd6bc:	10000006 */ 	beqz	$zero,.L0f0cd6d8
/*  f0cd6c0:	46026301 */ 	sub.s	$f12,$f12,$f2
/*  f0cd6c4:	4614603c */ 	c.lt.s	$f12,$f20
.L0f0cd6c8:
/*  f0cd6c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd6cc:	45020003 */ 	bc1fl	.L0f0cd6dc
/*  f0cd6d0:	e7ac0074 */ 	swc1	$f12,0x74($sp)
/*  f0cd6d4:	46026300 */ 	add.s	$f12,$f12,$f2
.L0f0cd6d8:
/*  f0cd6d8:	e7ac0074 */ 	swc1	$f12,0x74($sp)
.L0f0cd6dc:
/*  f0cd6dc:	0c0068f4 */ 	jal	cosf
/*  f0cd6e0:	e7ae0078 */ 	swc1	$f14,0x78($sp)
/*  f0cd6e4:	c7ac0074 */ 	lwc1	$f12,0x74($sp)
/*  f0cd6e8:	0c0068f7 */ 	jal	sinf
/*  f0cd6ec:	e7a00070 */ 	swc1	$f0,0x70($sp)
/*  f0cd6f0:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cd6f4:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f0cd6f8:	c7a600a4 */ 	lwc1	$f6,0xa4($sp)
/*  f0cd6fc:	c50a1a10 */ 	lwc1	$f10,0x1a10($t0)
/*  f0cd700:	c5081a18 */ 	lwc1	$f8,0x1a18($t0)
/*  f0cd704:	8d0b1b5c */ 	lw	$t3,0x1b5c($t0)
/*  f0cd708:	460a2300 */ 	add.s	$f12,$f4,$f10
/*  f0cd70c:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f0cd710:	c7a400dc */ 	lwc1	$f4,0xdc($sp)
/*  f0cd714:	46083480 */ 	add.s	$f18,$f6,$f8
/*  f0cd718:	460a6182 */ 	mul.s	$f6,$f12,$f10
/*  f0cd71c:	c7ae0078 */ 	lwc1	$f14,0x78($sp)
/*  f0cd720:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0cd724:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0cd728:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0cd72c:	c5680008 */ 	lwc1	$f8,0x8($t3)
/*  f0cd730:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0cd734:	460a9202 */ 	mul.s	$f8,$f18,$f10
/*  f0cd738:	c7a600e4 */ 	lwc1	$f6,0xe4($sp)
/*  f0cd73c:	46006282 */ 	mul.s	$f10,$f12,$f0
/*  f0cd740:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f0cd744:	8d0c1b5c */ 	lw	$t4,0x1b5c($t0)
/*  f0cd748:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0cd74c:	c5880010 */ 	lwc1	$f8,0x10($t4)
/*  f0cd750:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0cd754:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0cd758:	e7a40084 */ 	swc1	$f4,0x84($sp)
/*  f0cd75c:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f0cd760:
/*  f0cd760:	3c018007 */ 	lui	$at,0x8007
/*  f0cd764:	ac2d0e80 */ 	sw	$t5,0xe80($at)
/*  f0cd768:	8d0e1b5c */ 	lw	$t6,0x1b5c($t0)
/*  f0cd76c:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*  f0cd770:	3c02800a */ 	lui	$v0,%hi(var8009de78)
/*  f0cd774:	c5ca0008 */ 	lwc1	$f10,0x8($t6)
/*  f0cd778:	2442de78 */ 	addiu	$v0,$v0,%lo(var8009de78)
/*  f0cd77c:	44067000 */ 	mfc1	$a2,$f14
/*  f0cd780:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0cd784:	c7aa0080 */ 	lwc1	$f10,0x80($sp)
/*  f0cd788:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f0cd78c:	8fa700f8 */ 	lw	$a3,0xf8($sp)
/*  f0cd790:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f0cd794:	8d0f1b5c */ 	lw	$t7,0x1b5c($t0)
/*  f0cd798:	c5e4000c */ 	lwc1	$f4,0xc($t7)
/*  f0cd79c:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0cd7a0:	c7a40084 */ 	lwc1	$f4,0x84($sp)
/*  f0cd7a4:	e4460004 */ 	swc1	$f6,0x4($v0)
/*  f0cd7a8:	8d181b5c */ 	lw	$t8,0x1b5c($t0)
/*  f0cd7ac:	c7080010 */ 	lwc1	$f8,0x10($t8)
/*  f0cd7b0:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0cd7b4:	e44a0008 */ 	swc1	$f10,0x8($v0)
/*  f0cd7b8:	8d191b5c */ 	lw	$t9,0x1b5c($t0)
/*  f0cd7bc:	0fc1c851 */ 	jal	func0f072144
/*  f0cd7c0:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f0cd7c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd7c8:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f0cd7cc:	10410006 */ 	beq	$v0,$at,.L0f0cd7e8
/*  f0cd7d0:	e7b600b8 */ 	swc1	$f22,0xb8($sp)
/*  f0cd7d4:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0cd7d8:	3c01800a */ 	lui	$at,%hi(var8009de70)
/*  f0cd7dc:	8d2a1b5c */ 	lw	$t2,0x1b5c($t1)
/*  f0cd7e0:	e7b600b8 */ 	swc1	$f22,0xb8($sp)
/*  f0cd7e4:	ac2ade70 */ 	sw	$t2,%lo(var8009de70)($at)
.L0f0cd7e8:
/*  f0cd7e8:	8e0b0284 */ 	lw	$t3,0x284($s0)
.L0f0cd7ec:
/*  f0cd7ec:	c7b600b8 */ 	lwc1	$f22,0xb8($sp)
/*  f0cd7f0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cd7f4:	0fc1905e */ 	jal	func0f064178
/*  f0cd7f8:	8d6400bc */ 	lw	$a0,0xbc($t3)
/*  f0cd7fc:	3c017f1b */ 	lui	$at,%hi(var7f1ad9c4)
/*  f0cd800:	c422d9c4 */ 	lwc1	$f2,%lo(var7f1ad9c4)($at)
/*  f0cd804:	8fac00ec */ 	lw	$t4,0xec($sp)
/*  f0cd808:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cd80c:	44818000 */ 	mtc1	$at,$f16
/*  f0cd810:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd814:	55810050 */ 	bnel	$t4,$at,.L0f0cd958
/*  f0cd818:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0cd81c:	8fad00f8 */ 	lw	$t5,0xf8($sp)
/*  f0cd820:	3c01800a */ 	lui	$at,%hi(var8009de70)
/*  f0cd824:	ac20de70 */ 	sw	$zero,%lo(var8009de70)($at)
/*  f0cd828:	11a0004a */ 	beqz	$t5,.L0f0cd954
/*  f0cd82c:	c7a800f4 */ 	lwc1	$f8,0xf4($sp)
/*  f0cd830:	46104102 */ 	mul.s	$f4,$f8,$f16
/*  f0cd834:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cd838:	c5060144 */ 	lwc1	$f6,0x144($t0)
/*  f0cd83c:	46022283 */ 	div.s	$f10,$f4,$f2
/*  f0cd840:	460a3000 */ 	add.s	$f0,$f6,$f10
/*  f0cd844:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0cd848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd84c:	45020007 */ 	bc1fl	.L0f0cd86c
/*  f0cd850:	4600803e */ 	c.le.s	$f16,$f0
/*  f0cd854:	46100000 */ 	add.s	$f0,$f0,$f16
.L0f0cd858:
/*  f0cd858:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0cd85c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd860:	4503fffd */ 	bc1tl	.L0f0cd858
/*  f0cd864:	46100000 */ 	add.s	$f0,$f0,$f16
/*  f0cd868:	4600803e */ 	c.le.s	$f16,$f0
.L0f0cd86c:
/*  f0cd86c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd870:	45020007 */ 	bc1fl	.L0f0cd890
/*  f0cd874:	e5000144 */ 	swc1	$f0,0x144($t0)
/*  f0cd878:	46100001 */ 	sub.s	$f0,$f0,$f16
.L0f0cd87c:
/*  f0cd87c:	4600803e */ 	c.le.s	$f16,$f0
/*  f0cd880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd884:	4503fffd */ 	bc1tl	.L0f0cd87c
/*  f0cd888:	46100001 */ 	sub.s	$f0,$f0,$f16
/*  f0cd88c:	e5000144 */ 	swc1	$f0,0x144($t0)
.L0f0cd890:
/*  f0cd890:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0cd894:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f0cd898:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f0cd89c:	e5e80008 */ 	swc1	$f8,0x8($t7)
/*  f0cd8a0:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cd8a4:	c7a400e0 */ 	lwc1	$f4,0xe0($sp)
/*  f0cd8a8:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f0cd8ac:	e724000c */ 	swc1	$f4,0xc($t9)
/*  f0cd8b0:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0cd8b4:	c7a600e4 */ 	lwc1	$f6,0xe4($sp)
/*  f0cd8b8:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0cd8bc:	e5460010 */ 	swc1	$f6,0x10($t2)
/*  f0cd8c0:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*  f0cd8c4:	5160000a */ 	beqzl	$t3,.L0f0cd8f0
/*  f0cd8c8:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cd8cc:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0cd8d0:	0fc19711 */ 	jal	func0f065c44
/*  f0cd8d4:	8d8400bc */ 	lw	$a0,0xbc($t4)
/*  f0cd8d8:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0cd8dc:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0cd8e0:	8da500bc */ 	lw	$a1,0xbc($t5)
/*  f0cd8e4:	0fc195e9 */ 	jal	roomsCopy
/*  f0cd8e8:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0cd8ec:	8e080284 */ 	lw	$t0,0x284($s0)
.L0f0cd8f0:
/*  f0cd8f0:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f0cd8f4:	8d0e1a1c */ 	lw	$t6,0x1a1c($t0)
/*  f0cd8f8:	51c00017 */ 	beqzl	$t6,.L0f0cd958
/*  f0cd8fc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0cd900:	e50a1a20 */ 	swc1	$f10,0x1a20($t0)
/*  f0cd904:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0cd908:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f0cd90c:	e5e81a2c */ 	swc1	$f8,0x1a2c($t7)
/*  f0cd910:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cd914:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f0cd918:	e7041a30 */ 	swc1	$f4,0x1a30($t8)
/*  f0cd91c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cd920:	c7a600a4 */ 	lwc1	$f6,0xa4($sp)
/*  f0cd924:	e7261a34 */ 	swc1	$f6,0x1a34($t9)
/*  f0cd928:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0cd92c:	e5361a38 */ 	swc1	$f22,0x1a38($t1)
/*  f0cd930:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0cd934:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f0cd938:	e54a1a3c */ 	swc1	$f10,0x1a3c($t2)
/*  f0cd93c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0cd940:	c7a800b0 */ 	lwc1	$f8,0xb0($sp)
/*  f0cd944:	e5681a40 */ 	swc1	$f8,0x1a40($t3)
/*  f0cd948:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0cd94c:	c7a400b4 */ 	lwc1	$f4,0xb4($sp)
/*  f0cd950:	e5841a44 */ 	swc1	$f4,0x1a44($t4)
.L0f0cd954:
/*  f0cd954:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0cd958:
/*  f0cd958:	8fa200ec */ 	lw	$v0,0xec($sp)
/*  f0cd95c:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0cd960:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f0cd964:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0cd968:	03e00008 */ 	jr	$ra
/*  f0cd96c:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
);

GLOBAL_ASM(
glabel func0f0cd970
/*  f0cd970:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0cd974:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cd978:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0cd97c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0cd980:	0fc33469 */ 	jal	func0f0cd1a4
/*  f0cd984:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0cd988:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd98c:	10410058 */ 	beq	$v0,$at,.L0f0cdaf0
/*  f0cd990:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f0cd994:	0c0093ac */ 	jal	func00024eb0
/*  f0cd998:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd99c:	10400054 */ 	beqz	$v0,.L0f0cdaf0
/*  f0cd9a0:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0cd9a4:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0cd9a8:	8c8e0034 */ 	lw	$t6,0x34($a0)
/*  f0cd9ac:	59c00051 */ 	blezl	$t6,.L0f0cdaf4
/*  f0cd9b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cd9b4:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0cd9b8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0cd9bc:	1061004c */ 	beq	$v1,$at,.L0f0cdaf0
/*  f0cd9c0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0cd9c4:	1061004a */ 	beq	$v1,$at,.L0f0cdaf0
/*  f0cd9c8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd9cc:	54610049 */ 	bnel	$v1,$at,.L0f0cdaf4
/*  f0cd9d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cd9d4:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0cd9d8:	8cc30040 */ 	lw	$v1,0x40($a2)
/*  f0cd9dc:	00037940 */ 	sll	$t7,$v1,0x5
/*  f0cd9e0:	05e00043 */ 	bltz	$t7,.L0f0cdaf0
/*  f0cd9e4:	0003c100 */ 	sll	$t8,$v1,0x4
/*  f0cd9e8:	07020042 */ 	bltzl	$t8,.L0f0cdaf4
/*  f0cd9ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cd9f0:	8cd90010 */ 	lw	$t9,0x10($a2)
/*  f0cd9f4:	33280001 */ 	andi	$t0,$t9,0x1
/*  f0cd9f8:	5100003e */ 	beqzl	$t0,.L0f0cdaf4
/*  f0cd9fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cda00:	8c890284 */ 	lw	$t1,0x284($a0)
/*  f0cda04:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0cda08:	ad200178 */ 	sw	$zero,0x178($t1)
/*  f0cda0c:	8cca0040 */ 	lw	$t2,0x40($a2)
/*  f0cda10:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0cda14:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0cda18:	314b0080 */ 	andi	$t3,$t2,0x80
/*  f0cda1c:	11600007 */ 	beqz	$t3,.L0f0cda3c
/*  f0cda20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cda24:	8ccc0048 */ 	lw	$t4,0x48($a2)
/*  f0cda28:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f0cda2c:	31ae1000 */ 	andi	$t6,$t5,0x1000
/*  f0cda30:	11c00002 */ 	beqz	$t6,.L0f0cda3c
/*  f0cda34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cda38:	00001025 */ 	or	$v0,$zero,$zero
.L0f0cda3c:
/*  f0cda3c:	5040002d */ 	beqzl	$v0,.L0f0cdaf4
/*  f0cda40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cda44:	0fc332fc */ 	jal	func0f0ccbf0
/*  f0cda48:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f0cda4c:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f0cda50:	8ccf0040 */ 	lw	$t7,0x40($a2)
/*  f0cda54:	31f80080 */ 	andi	$t8,$t7,0x80
/*  f0cda58:	53000026 */ 	beqzl	$t8,.L0f0cdaf4
/*  f0cda5c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cda60:	8cd90048 */ 	lw	$t9,0x48($a2)
/*  f0cda64:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0cda68:	27a50020 */ 	addiu	$a1,$sp,0x20
/*  f0cda6c:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f0cda70:	31090800 */ 	andi	$t1,$t0,0x800
/*  f0cda74:	5120001f */ 	beqzl	$t1,.L0f0cdaf4
/*  f0cda78:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cda7c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0cda80:	0fc1cf1b */ 	jal	func0f073c6c
/*  f0cda84:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f0cda88:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f0cda8c:	8cca0040 */ 	lw	$t2,0x40($a2)
/*  f0cda90:	314b0080 */ 	andi	$t3,$t2,0x80
/*  f0cda94:	11600010 */ 	beqz	$t3,.L0f0cdad8
/*  f0cda98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cda9c:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0cdaa0:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0cdaa4:	358d1000 */ 	ori	$t5,$t4,0x1000
/*  f0cdaa8:	10400006 */ 	beqz	$v0,.L0f0cdac4
/*  f0cdaac:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0cdab0:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0cdab4:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0cdab8:	35cf2000 */ 	ori	$t7,$t6,0x2000
/*  f0cdabc:	10000006 */ 	beqz	$zero,.L0f0cdad8
/*  f0cdac0:	ac6f0000 */ 	sw	$t7,0x0($v1)
.L0f0cdac4:
/*  f0cdac4:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0cdac8:	2401dfff */ 	addiu	$at,$zero,-8193
/*  f0cdacc:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0cdad0:	0301c824 */ 	and	$t9,$t8,$at
/*  f0cdad4:	ac790000 */ 	sw	$t9,0x0($v1)
.L0f0cdad8:
/*  f0cdad8:	10400005 */ 	beqz	$v0,.L0f0cdaf0
/*  f0cdadc:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0cdae0:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0cdae4:	0fc33469 */ 	jal	func0f0cd1a4
/*  f0cdae8:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0cdaec:	afa20034 */ 	sw	$v0,0x34($sp)
.L0f0cdaf0:
/*  f0cdaf0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0cdaf4:
/*  f0cdaf4:	8fa20034 */ 	lw	$v0,0x34($sp)
/*  f0cdaf8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0cdafc:	03e00008 */ 	jr	$ra
/*  f0cdb00:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cdb04
/*  f0cdb04:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0cdb08:	3c0e8007 */ 	lui	$t6,%hi(var80070e9c)
/*  f0cdb0c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cdb10:	25ce0e9c */ 	addiu	$t6,$t6,%lo(var80070e9c)
/*  f0cdb14:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0cdb18:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f0cdb1c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x284)
/*  f0cdb20:	ac810000 */ 	sw	$at,0x0($a0)
/*  f0cdb24:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f0cdb28:	00a03025 */ 	or	$a2,$a1,$zero
/*  f0cdb2c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0cdb30:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f0cdb34:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0cdb38:	44056000 */ 	mfc1	$a1,$f12
/*  f0cdb3c:	ac810008 */ 	sw	$at,0x8($a0)
/*  f0cdb40:	8d29a244 */ 	lw	$t1,%lo(g_Vars+0x284)($t1)
/*  f0cdb44:	0fc3365c */ 	jal	func0f0cd970
/*  f0cdb48:	ad281a1c */ 	sw	$t0,0x1a1c($t1)
/*  f0cdb4c:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x284)
/*  f0cdb50:	8d4aa244 */ 	lw	$t2,%lo(g_Vars+0x284)($t2)
/*  f0cdb54:	ad401a1c */ 	sw	$zero,0x1a1c($t2)
/*  f0cdb58:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cdb5c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0cdb60:	03e00008 */ 	jr	$ra
/*  f0cdb64:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cdb68
.late_rodata
glabel var7f1ad9c8
.word 0x3f8147ae
.text
/*  f0cdb68:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f0cdb6c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cdb70:	44817000 */ 	mtc1	$at,$f14
/*  f0cdb74:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0cdb78:	3c077f1b */ 	lui	$a3,%hi(var7f1ad958)
/*  f0cdb7c:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f0cdb80:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f0cdb84:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f0cdb88:	e7ac00b0 */ 	swc1	$f12,0xb0($sp)
/*  f0cdb8c:	24e7d958 */ 	addiu	$a3,$a3,%lo(var7f1ad958)
/*  f0cdb90:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0cdb94:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f0cdb98:	240602a6 */ 	addiu	$a2,$zero,0x2a6
/*  f0cdb9c:	0c009393 */ 	jal	func00024e4c
/*  f0cdba0:	e7ae0060 */ 	swc1	$f14,0x60($sp)
/*  f0cdba4:	c7ac00a4 */ 	lwc1	$f12,0xa4($sp)
/*  f0cdba8:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f0cdbac:	4480c000 */ 	mtc1	$zero,$f24
/*  f0cdbb0:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0cdbb4:	460c2401 */ 	sub.s	$f16,$f4,$f12
/*  f0cdbb8:	c7a600a0 */ 	lwc1	$f6,0xa0($sp)
/*  f0cdbbc:	c7ae0060 */ 	lwc1	$f14,0x60($sp)
/*  f0cdbc0:	46188032 */ 	c.eq.s	$f16,$f24
/*  f0cdbc4:	46123001 */ 	sub.s	$f0,$f6,$f18
/*  f0cdbc8:	45000008 */ 	bc1f	.L0f0cdbec
/*  f0cdbcc:	46000086 */ 	mov.s	$f2,$f0
/*  f0cdbd0:	46180032 */ 	c.eq.s	$f0,$f24
/*  f0cdbd4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cdbd8:	45000004 */ 	bc1f	.L0f0cdbec
/*  f0cdbdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdbe0:	44811000 */ 	mtc1	$at,$f2
/*  f0cdbe4:	10000012 */ 	beqz	$zero,.L0f0cdc30
/*  f0cdbe8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cdbec:
/*  f0cdbec:	46108202 */ 	mul.s	$f8,$f16,$f16
/*  f0cdbf0:	e7a20078 */ 	swc1	$f2,0x78($sp)
/*  f0cdbf4:	e7ae0060 */ 	swc1	$f14,0x60($sp)
/*  f0cdbf8:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f0cdbfc:	e7b0007c */ 	swc1	$f16,0x7c($sp)
/*  f0cdc00:	0c012974 */ 	jal	sqrtf
/*  f0cdc04:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f0cdc08:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cdc0c:	44812000 */ 	mtc1	$at,$f4
/*  f0cdc10:	c7b0007c */ 	lwc1	$f16,0x7c($sp)
/*  f0cdc14:	c7a20078 */ 	lwc1	$f2,0x78($sp)
/*  f0cdc18:	46002303 */ 	div.s	$f12,$f4,$f0
/*  f0cdc1c:	c7ae0060 */ 	lwc1	$f14,0x60($sp)
/*  f0cdc20:	460c8402 */ 	mul.s	$f16,$f16,$f12
/*  f0cdc24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdc28:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0cdc2c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cdc30:
/*  f0cdc30:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0cdc34:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0cdc38:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f0cdc3c:	46008007 */ 	neg.s	$f0,$f16
/*  f0cdc40:	8dc200bc */ 	lw	$v0,0xbc($t6)
/*  f0cdc44:	46001506 */ 	mov.s	$f20,$f2
/*  f0cdc48:	46000586 */ 	mov.s	$f22,$f0
/*  f0cdc4c:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0cdc50:	3c0f8006 */ 	lui	$t7,%hi(var8005f034)
/*  f0cdc54:	27a4008c */ 	addiu	$a0,$sp,0x8c
/*  f0cdc58:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0cdc5c:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0cdc60:	27a50080 */ 	addiu	$a1,$sp,0x80
/*  f0cdc64:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0cdc68:	c7aa00a4 */ 	lwc1	$f10,0xa4($sp)
/*  f0cdc6c:	460a3181 */ 	sub.s	$f6,$f6,$f10
/*  f0cdc70:	46061182 */ 	mul.s	$f6,$f2,$f6
/*  f0cdc74:	46062100 */ 	add.s	$f4,$f4,$f6
/*  f0cdc78:	4618203c */ 	c.lt.s	$f4,$f24
/*  f0cdc7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdc80:	45000003 */ 	bc1f	.L0f0cdc90
/*  f0cdc84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdc88:	46001507 */ 	neg.s	$f20,$f2
/*  f0cdc8c:	46000587 */ 	neg.s	$f22,$f0
.L0f0cdc90:
/*  f0cdc90:	8deff034 */ 	lw	$t7,%lo(var8005f034)($t7)
/*  f0cdc94:	c7ac00a4 */ 	lwc1	$f12,0xa4($sp)
/*  f0cdc98:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0cdc9c:	11e00020 */ 	beqz	$t7,.L0f0cdd20
/*  f0cdca0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdca4:	3c04800a */ 	lui	$a0,%hi(var8009a918+0x1)
/*  f0cdca8:	9084a919 */ 	lbu	$a0,%lo(var8009a918+0x1)($a0)
/*  f0cdcac:	3c18800a */ 	lui	$t8,%hi(var8009a918)
/*  f0cdcb0:	2702a918 */ 	addiu	$v0,$t8,%lo(var8009a918)
/*  f0cdcb4:	18800061 */ 	blez	$a0,.L0f0cde3c
/*  f0cdcb8:	0004c8c0 */ 	sll	$t9,$a0,0x3
/*  f0cdcbc:	03221821 */ 	addu	$v1,$t9,$v0
/*  f0cdcc0:	c4460010 */ 	lwc1	$f6,0x10($v0)
.L0f0cdcc4:
/*  f0cdcc4:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0cdcc8:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f0cdccc:	46123101 */ 	sub.s	$f4,$f6,$f18
/*  f0cdcd0:	0043082b */ 	sltu	$at,$v0,$v1
/*  f0cdcd4:	460c4181 */ 	sub.s	$f6,$f8,$f12
/*  f0cdcd8:	46162282 */ 	mul.s	$f10,$f4,$f22
/*  f0cdcdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdce0:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0cdce4:	46045000 */ 	add.s	$f0,$f10,$f4
/*  f0cdce8:	4618003c */ 	c.lt.s	$f0,$f24
/*  f0cdcec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdcf0:	45000007 */ 	bc1f	.L0f0cdd10
/*  f0cdcf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdcf8:	46000007 */ 	neg.s	$f0,$f0
/*  f0cdcfc:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cdd00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdd04:	45000002 */ 	bc1f	.L0f0cdd10
/*  f0cdd08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdd0c:	46000386 */ 	mov.s	$f14,$f0
.L0f0cdd10:
/*  f0cdd10:	5420ffec */ 	bnezl	$at,.L0f0cdcc4
/*  f0cdd14:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0cdd18:	10000049 */ 	beqz	$zero,.L0f0cde40
/*  f0cdd1c:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
.L0f0cdd20:
/*  f0cdd20:	0c0094d9 */ 	jal	func00025364
/*  f0cdd24:	e7ae0060 */ 	swc1	$f14,0x60($sp)
/*  f0cdd28:	1040001c */ 	beqz	$v0,.L0f0cdd9c
/*  f0cdd2c:	c7ae0060 */ 	lwc1	$f14,0x60($sp)
/*  f0cdd30:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0cdd34:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f0cdd38:	c7ac00a4 */ 	lwc1	$f12,0xa4($sp)
/*  f0cdd3c:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f0cdd40:	46124181 */ 	sub.s	$f6,$f8,$f18
/*  f0cdd44:	460c2201 */ 	sub.s	$f8,$f4,$f12
/*  f0cdd48:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0cdd4c:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f0cdd50:	46144182 */ 	mul.s	$f6,$f8,$f20
/*  f0cdd54:	46122201 */ 	sub.s	$f8,$f4,$f18
/*  f0cdd58:	46065000 */ 	add.s	$f0,$f10,$f6
/*  f0cdd5c:	c7a60080 */ 	lwc1	$f6,0x80($sp)
/*  f0cdd60:	46164282 */ 	mul.s	$f10,$f8,$f22
/*  f0cdd64:	460c3101 */ 	sub.s	$f4,$f6,$f12
/*  f0cdd68:	46142202 */ 	mul.s	$f8,$f4,$f20
/*  f0cdd6c:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f0cdd70:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0cdd74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdd78:	45020003 */ 	bc1fl	.L0f0cdd88
/*  f0cdd7c:	4618003c */ 	c.lt.s	$f0,$f24
/*  f0cdd80:	46008006 */ 	mov.s	$f0,$f16
/*  f0cdd84:	4618003c */ 	c.lt.s	$f0,$f24
.L0f0cdd88:
/*  f0cdd88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdd8c:	4502002c */ 	bc1fl	.L0f0cde40
/*  f0cdd90:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cdd94:	10000029 */ 	beqz	$zero,.L0f0cde3c
/*  f0cdd98:	46000387 */ 	neg.s	$f14,$f0
.L0f0cdd9c:
/*  f0cdd9c:	3c088007 */ 	lui	$t0,%hi(var80070e80)
/*  f0cdda0:	8d080e80 */ 	lw	$t0,%lo(var80070e80)($t0)
/*  f0cdda4:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x284)
/*  f0cdda8:	51000025 */ 	beqzl	$t0,.L0f0cde40
/*  f0cddac:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cddb0:	8d29a244 */ 	lw	$t1,%lo(g_Vars+0x284)($t1)
/*  f0cddb4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cddb8:	8d241b5c */ 	lw	$a0,0x1b5c($t1)
/*  f0cddbc:	908a0000 */ 	lbu	$t2,0x0($a0)
/*  f0cddc0:	5541001f */ 	bnel	$t2,$at,.L0f0cde40
/*  f0cddc4:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cddc8:	8c8b0004 */ 	lw	$t3,0x4($a0)
/*  f0cddcc:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0cddd0:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f0cddd4:	8d6c0010 */ 	lw	$t4,0x10($t3)
/*  f0cddd8:	27a70044 */ 	addiu	$a3,$sp,0x44
/*  f0cdddc:	000c6980 */ 	sll	$t5,$t4,0x6
/*  f0cdde0:	05a30017 */ 	bgezl	$t5,.L0f0cde40
/*  f0cdde4:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cdde8:	0fc21d5b */ 	jal	propObjGetBbox
/*  f0cddec:	e7ae0060 */ 	swc1	$f14,0x60($sp)
/*  f0cddf0:	3c02800a */ 	lui	$v0,%hi(var8009de78)
/*  f0cddf4:	2442de78 */ 	addiu	$v0,$v0,%lo(var8009de78)
/*  f0cddf8:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0cddfc:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0cde00:	c7ac00a4 */ 	lwc1	$f12,0xa4($sp)
/*  f0cde04:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f0cde08:	46123101 */ 	sub.s	$f4,$f6,$f18
/*  f0cde0c:	c7ae0060 */ 	lwc1	$f14,0x60($sp)
/*  f0cde10:	460c4181 */ 	sub.s	$f6,$f8,$f12
/*  f0cde14:	46162282 */ 	mul.s	$f10,$f4,$f22
/*  f0cde18:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*  f0cde1c:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0cde20:	46045000 */ 	add.s	$f0,$f10,$f4
/*  f0cde24:	46080001 */ 	sub.s	$f0,$f0,$f8
/*  f0cde28:	4618003c */ 	c.lt.s	$f0,$f24
/*  f0cde2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cde30:	45020003 */ 	bc1fl	.L0f0cde40
/*  f0cde34:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cde38:	46000387 */ 	neg.s	$f14,$f0
.L0f0cde3c:
/*  f0cde3c:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
.L0f0cde40:
/*  f0cde40:	0c0068f7 */ 	jal	sinf
/*  f0cde44:	e7ae0060 */ 	swc1	$f14,0x60($sp)
/*  f0cde48:	3c0143c8 */ 	lui	$at,0x43c8
/*  f0cde4c:	44813000 */ 	mtc1	$at,$f6
/*  f0cde50:	c7ae0060 */ 	lwc1	$f14,0x60($sp)
/*  f0cde54:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cde58:	46060302 */ 	mul.s	$f12,$f0,$f6
/*  f0cde5c:	4618603c */ 	c.lt.s	$f12,$f24
/*  f0cde60:	46006086 */ 	mov.s	$f2,$f12
/*  f0cde64:	45020003 */ 	bc1fl	.L0f0cde74
/*  f0cde68:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0cde6c:	46006087 */ 	neg.s	$f2,$f12
/*  f0cde70:	460e103c */ 	c.lt.s	$f2,$f14
.L0f0cde74:
/*  f0cde74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cde78:	45020003 */ 	bc1fl	.L0f0cde88
/*  f0cde7c:	460ec03e */ 	c.le.s	$f24,$f14
/*  f0cde80:	46001386 */ 	mov.s	$f14,$f2
/*  f0cde84:	460ec03e */ 	c.le.s	$f24,$f14
.L0f0cde88:
/*  f0cde88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cde8c:	45000012 */ 	bc1f	.L0f0cded8
/*  f0cde90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cde94:	46147282 */ 	mul.s	$f10,$f14,$f20
/*  f0cde98:	3c017f1b */ 	lui	$at,%hi(var7f1ad9c8)
/*  f0cde9c:	c420d9c8 */ 	lwc1	$f0,%lo(var7f1ad9c8)($at)
/*  f0cdea0:	e7b80058 */ 	swc1	$f24,0x58($sp)
/*  f0cdea4:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f0cdea8:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0cdeac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdeb0:	46167202 */ 	mul.s	$f8,$f14,$f22
/*  f0cdeb4:	e7a40054 */ 	swc1	$f4,0x54($sp)
/*  f0cdeb8:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0cdebc:	0fc3382f */ 	jal	func0f0ce0bc
/*  f0cdec0:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*  f0cdec4:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cdec8:	0fc336c1 */ 	jal	func0f0cdb04
/*  f0cdecc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cded0:	10000002 */ 	beqz	$zero,.L0f0cdedc
/*  f0cded4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0cded8:
/*  f0cded8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0cdedc:
/*  f0cdedc:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f0cdee0:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f0cdee4:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f0cdee8:	03e00008 */ 	jr	$ra
/*  f0cdeec:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

GLOBAL_ASM(
glabel func0f0cdef0
.late_rodata
glabel var7f1ad9cc
.word 0x3c8ef461
.text
/*  f0cdef0:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0cdef4:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0cdef8:	8c4e0034 */ 	lw	$t6,0x34($v0)
/*  f0cdefc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0cdf00:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cdf04:	59c00014 */ 	blezl	$t6,.L0f0cdf58
/*  f0cdf08:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cdf0c:	8c4f0284 */ 	lw	$t7,0x284($v0)
/*  f0cdf10:	c446004c */ 	lwc1	$f6,0x4c($v0)
/*  f0cdf14:	3c017f1b */ 	lui	$at,%hi(var7f1ad9cc)
/*  f0cdf18:	c5e40148 */ 	lwc1	$f4,0x148($t7)
/*  f0cdf1c:	c42ad9cc */ 	lwc1	$f10,%lo(var7f1ad9cc)($at)
/*  f0cdf20:	3c014060 */ 	lui	$at,0x4060
/*  f0cdf24:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0cdf28:	44819000 */ 	mtc1	$at,$f18
/*  f0cdf2c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cdf30:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0cdf34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdf38:	46128302 */ 	mul.s	$f12,$f16,$f18
/*  f0cdf3c:	0fc336c1 */ 	jal	func0f0cdb04
/*  f0cdf40:	e7ac001c */ 	swc1	$f12,0x1c($sp)
/*  f0cdf44:	14400003 */ 	bnez	$v0,.L0f0cdf54
/*  f0cdf48:	c7ac001c */ 	lwc1	$f12,0x1c($sp)
/*  f0cdf4c:	0fc336da */ 	jal	func0f0cdb68
/*  f0cdf50:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cdf54:
/*  f0cdf54:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0cdf58:
/*  f0cdf58:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0cdf5c:	03e00008 */ 	jr	$ra
/*  f0cdf60:	00000000 */ 	sll	$zero,$zero,0x0
);

bool func0f0cdf64(struct coord *delta, struct coord *arg1, struct coord *arg2)
{
	bool result = func0f0cd970(delta, 0, true);

	if (!result) {
		func00024e4c(arg1, arg2, 0x32f, "bondgrab.c");
	}

	return result;
}

GLOBAL_ASM(
glabel func0f0cdfbc
/*  f0cdfbc:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0cdfc0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cdfc4:	c4c20000 */ 	lwc1	$f2,0x0($a2)
/*  f0cdfc8:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*  f0cdfcc:	00803825 */ 	or	$a3,$a0,$zero
/*  f0cdfd0:	46020032 */ 	c.eq.s	$f0,$f2
/*  f0cdfd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdfd8:	45020009 */ 	bc1fl	.L0f0ce000
/*  f0cdfdc:	46001201 */ 	sub.s	$f8,$f2,$f0
/*  f0cdfe0:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f0cdfe4:	c4c60008 */ 	lwc1	$f6,0x8($a2)
/*  f0cdfe8:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0cdfec:	46062032 */ 	c.eq.s	$f4,$f6
/*  f0cdff0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdff4:	4501002d */ 	bc1t	.L0f0ce0ac
/*  f0cdff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdffc:	46001201 */ 	sub.s	$f8,$f2,$f0
.L0f0ce000:
/*  f0ce000:	e7a80030 */ 	swc1	$f8,0x30($sp)
/*  f0ce004:	c4b00008 */ 	lwc1	$f16,0x8($a1)
/*  f0ce008:	c4ca0008 */ 	lwc1	$f10,0x8($a2)
/*  f0ce00c:	c7a80030 */ 	lwc1	$f8,0x30($sp)
/*  f0ce010:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f0ce014:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0ce018:	e7b20038 */ 	swc1	$f18,0x38($sp)
/*  f0ce01c:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*  f0ce020:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f0ce024:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce028:	46084282 */ 	mul.s	$f10,$f8,$f8
/*  f0ce02c:	0c012974 */ 	jal	sqrtf
/*  f0ce030:	460a3300 */ 	add.s	$f12,$f6,$f10
/*  f0ce034:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ce038:	44818000 */ 	mtc1	$at,$f16
/*  f0ce03c:	c7b20030 */ 	lwc1	$f18,0x30($sp)
/*  f0ce040:	c7a80038 */ 	lwc1	$f8,0x38($sp)
/*  f0ce044:	46008083 */ 	div.s	$f2,$f16,$f0
/*  f0ce048:	8fa70040 */ 	lw	$a3,0x40($sp)
/*  f0ce04c:	44807000 */ 	mtc1	$zero,$f14
/*  f0ce050:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f0ce054:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0ce058:	44057000 */ 	mfc1	$a1,$f14
/*  f0ce05c:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f0ce060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce064:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0ce068:	e7a40030 */ 	swc1	$f4,0x30($sp)
/*  f0ce06c:	e7a60038 */ 	swc1	$f6,0x38($sp)
/*  f0ce070:	c4ea0008 */ 	lwc1	$f10,0x8($a3)
/*  f0ce074:	c4f20000 */ 	lwc1	$f18,0x0($a3)
/*  f0ce078:	e7ae0028 */ 	swc1	$f14,0x28($sp)
/*  f0ce07c:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0ce080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce084:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f0ce088:	46088300 */ 	add.s	$f12,$f16,$f8
/*  f0ce08c:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f0ce090:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce094:	460c3482 */ 	mul.s	$f18,$f6,$f12
/*  f0ce098:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f0ce09c:	0fc3365c */ 	jal	func0f0cd970
/*  f0ce0a0:	e7b2002c */ 	swc1	$f18,0x2c($sp)
/*  f0ce0a4:	10000002 */ 	beqz	$zero,.L0f0ce0b0
/*  f0ce0a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ce0ac:
/*  f0ce0ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ce0b0:
/*  f0ce0b0:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0ce0b4:	03e00008 */ 	jr	$ra
/*  f0ce0b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ce0bc
/*  f0ce0bc:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0ce0c0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ce0c4:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0ce0c8:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*  f0ce0cc:	0fc337d9 */ 	jal	func0f0cdf64
/*  f0ce0d0:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f0ce0d4:	14400006 */ 	bnez	$v0,.L0f0ce0f0
/*  f0ce0d8:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0ce0dc:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*  f0ce0e0:	0fc337ef */ 	jal	func0f0cdfbc
/*  f0ce0e4:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f0ce0e8:	5c400002 */ 	bgtzl	$v0,.L0f0ce0f4
/*  f0ce0ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ce0f0:
/*  f0ce0f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ce0f4:
/*  f0ce0f4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0ce0f8:	03e00008 */ 	jr	$ra
/*  f0ce0fc:	00000000 */ 	sll	$zero,$zero,0x0
);

void currentPlayerUpdatePrevPosGrab(void)
{
	g_Vars.currentplayer->bondprevpos.x = g_Vars.currentplayer->prop->pos.x;
	g_Vars.currentplayer->bondprevpos.y = g_Vars.currentplayer->prop->pos.y;
	g_Vars.currentplayer->bondprevpos.z = g_Vars.currentplayer->prop->pos.z;

	g_Vars.currentplayer->bondprevtheta = g_Vars.currentplayer->vv_theta;

	g_Vars.currentplayer->grabbedprevpos.x = g_Vars.currentplayer->grabbedprop->pos.x;
	g_Vars.currentplayer->grabbedprevpos.y = g_Vars.currentplayer->grabbedprop->pos.y;
	g_Vars.currentplayer->grabbedprevpos.z = g_Vars.currentplayer->grabbedprop->pos.z;
}

void func0f0ce178(void)
{
	func0f069c70(g_Vars.currentplayer->grabbedprop->obj, 0, 1);
}

void func0f0ce1ac(void)
{
	f32 stack;
	s32 i;
	f32 tmp;
	bool inlift;
	struct prop *lift = NULL;
	f32 dist;
	f32 f14;
	f32 fVar3;
	f32 f0;

	f14 = func0002a1b0(&g_Vars.currentplayer->prop->pos,
			g_Vars.currentplayer->bond2.width,
			g_Vars.currentplayer->prop->rooms,
			&g_Vars.currentplayer->floorcol,
			&g_Vars.currentplayer->floortype,
			&g_Vars.currentplayer->floorflags,
			&g_Vars.currentplayer->floorroom, &inlift, &lift);

	if (f14 < -30000) {
		f14 = -30000;
	}

	if (g_Vars.currentplayer->inlift && inlift) {
		if (g_Vars.currentplayer->lift == lift) {
			dist = g_Vars.currentplayer->liftground - g_Vars.currentplayer->vv_manground;

			if (dist < 1.0f && dist > -1.0f) {
				f0 = f14 - g_Vars.currentplayer->vv_ground;
				g_Vars.currentplayer->vv_ground += f0;
				g_Vars.currentplayer->vv_manground += f0;
				g_Vars.currentplayer->sumground = g_Vars.currentplayer->vv_manground / 0.045499980449677f;
			}
		}
	} else {
		lift = NULL;
	}

	g_Vars.currentplayer->inlift = inlift;

	if (inlift) {
		g_Vars.currentplayer->liftground = f14;
	}

	g_Vars.currentplayer->lift = lift;
	g_Vars.currentplayer->vv_ground = f14;
	g_Vars.currentplayer->vv_height =
		(g_Vars.currentplayer->headpos.y / g_Vars.currentplayer->standheight) *
		g_Vars.currentplayer->vv_eyeheight;
	fVar3 = g_Vars.currentplayer->vv_manground / 0.045499980449677f;

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		fVar3 = 0.9545f * fVar3 + g_Vars.currentplayer->vv_ground;
	}

	f0 = g_Vars.currentplayer->vv_height;

	if (f0 < 30) {
		f0 = 30;
	}

	tmp = fVar3 * 0.045499980449677f + f0 - g_Vars.currentplayer->prop->pos.y;

	if (g_Vars.currentplayer->prop->pos.y + tmp < g_Vars.currentplayer->vv_ground + 10.0f) {
		tmp = g_Vars.currentplayer->vv_ground + 10.0f - g_Vars.currentplayer->prop->pos.y;
	}

	if (func0f0cd05c(tmp)) {
		g_Vars.currentplayer->sumground = fVar3;
		g_Vars.currentplayer->vv_manground = fVar3 * 0.045499980449677f;
	}

	if ((g_Vars.currentplayer->floorflags & FLOORFLAG_4000) &&
			g_Vars.currentplayer->vv_manground - 20.0f < g_Vars.currentplayer->vv_ground) {
		currentPlayerDie(true);
	}
}

void func0f0ce450(void)
{
	if (func0f086d60(g_Vars.currentplayer->grabbedprop)) {
		g_Vars.currentplayer->unk00d0 = 0;
	} else {
		g_Vars.currentplayer->unk00d0 = 0;
		currentPlayerSetMoveMode(MOVEMODE_WALK);
	}
}

GLOBAL_ASM(
glabel func0f0ce4a0
/*  f0ce4a0:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0ce4a4:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0ce4a8:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce4ac:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0ce4b0:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0ce4b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce4b8:	45020013 */ 	bc1fl	.L0f0ce508
/*  f0ce4bc:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0ce4c0:	44862000 */ 	mtc1	$a2,$f4
/*  f0ce4c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce4c8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ce4cc:	46067202 */ 	mul.s	$f8,$f14,$f6
/*  f0ce4d0:	46080281 */ 	sub.s	$f10,$f0,$f8
/*  f0ce4d4:	e44a016c */ 	swc1	$f10,0x16c($v0)
/*  f0ce4d8:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce4dc:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0ce4e0:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0ce4e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce4e8:	4500001a */ 	bc1f	.L0f0ce554
/*  f0ce4ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce4f0:	e44c016c */ 	swc1	$f12,0x16c($v0)
/*  f0ce4f4:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0ce4f8:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0ce4fc:	10000015 */ 	beqz	$zero,.L0f0ce554
/*  f0ce500:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0ce504:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0ce508:
/*  f0ce508:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce50c:	45000011 */ 	bc1f	.L0f0ce554
/*  f0ce510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce514:	44868000 */ 	mtc1	$a2,$f16
/*  f0ce518:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce51c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ce520:	46127102 */ 	mul.s	$f4,$f14,$f18
/*  f0ce524:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f0ce528:	e446016c */ 	swc1	$f6,0x16c($v0)
/*  f0ce52c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce530:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0ce534:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0ce538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce53c:	45000005 */ 	bc1f	.L0f0ce554
/*  f0ce540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce544:	e44c016c */ 	swc1	$f12,0x16c($v0)
/*  f0ce548:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0ce54c:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0ce550:	c440016c */ 	lwc1	$f0,0x16c($v0)
.L0f0ce554:
/*  f0ce554:	03e00008 */ 	jr	$ra
/*  f0ce558:	e4400168 */ 	swc1	$f0,0x168($v0)
);

void currentPlayerUpdateSpeedForwardsGrab(f32 target, f32 speed)
{
	if (g_Vars.currentplayer->speedgo < target) {
		g_Vars.currentplayer->speedgo += speed * g_Vars.lvupdate240freal;

		if (g_Vars.currentplayer->speedgo > target) {
			g_Vars.currentplayer->speedgo = target;
		}
	} else if (g_Vars.currentplayer->speedgo > target) {
		g_Vars.currentplayer->speedgo -= speed * g_Vars.lvupdate240freal;

		if (g_Vars.currentplayer->speedgo < target) {
			g_Vars.currentplayer->speedgo = target;
		}
	}

	g_Vars.currentplayer->speedforwards = g_Vars.currentplayer->speedgo;
}

GLOBAL_ASM(
glabel func0f0ce608
.late_rodata
glabel var7f1ad9e4
.word 0x3d888889
glabel var7f1ad9e8
.word 0x3d888889
glabel var7f1ad9ec
.word 0x3d888889
glabel var7f1ad9f0
.word 0x3c6a0ea1
glabel var7f1ad9f4
.word 0x3d888889
glabel var7f1ad9f8
.word 0x3d888889
glabel var7f1ad9fc
.word 0x3d888889
glabel var7f1ada00
.word 0x3d888889
glabel var7f1ada04
.word 0x3c6a0ea1
glabel var7f1ada08
.word 0x3d888889
glabel var7f1ada0c
.word 0x3f8a3d71
.text
/*  f0ce608:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0ce60c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0ce610:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ce614:	8c860028 */ 	lw	$a2,0x28($a0)
/*  f0ce618:	00808025 */ 	or	$s0,$a0,$zero
/*  f0ce61c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0ce620:	50c00008 */ 	beqzl	$a2,.L0f0ce644
/*  f0ce624:	8e06002c */ 	lw	$a2,0x2c($s0)
/*  f0ce628:	44816000 */ 	mtc1	$at,$f12
/*  f0ce62c:	3c017f1b */ 	lui	$at,%hi(var7f1ad9e4)
/*  f0ce630:	0fc33928 */ 	jal	func0f0ce4a0
/*  f0ce634:	c42ed9e4 */ 	lwc1	$f14,%lo(var7f1ad9e4)($at)
/*  f0ce638:	10000015 */ 	beqz	$zero,.L0f0ce690
/*  f0ce63c:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f0ce640:	8e06002c */ 	lw	$a2,0x2c($s0)
.L0f0ce644:
/*  f0ce644:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ce648:	50c00008 */ 	beqzl	$a2,.L0f0ce66c
/*  f0ce64c:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f0ce650:	44816000 */ 	mtc1	$at,$f12
/*  f0ce654:	3c017f1b */ 	lui	$at,%hi(var7f1ad9e8)
/*  f0ce658:	0fc33928 */ 	jal	func0f0ce4a0
/*  f0ce65c:	c42ed9e8 */ 	lwc1	$f14,%lo(var7f1ad9e8)($at)
/*  f0ce660:	1000000b */ 	beqz	$zero,.L0f0ce690
/*  f0ce664:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f0ce668:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f0ce66c:
/*  f0ce66c:	3c017f1b */ 	lui	$at,%hi(var7f1ad9ec)
/*  f0ce670:	3c06800a */ 	lui	$a2,%hi(g_Vars+0x38)
/*  f0ce674:	14400006 */ 	bnez	$v0,.L0f0ce690
/*  f0ce678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce67c:	44806000 */ 	mtc1	$zero,$f12
/*  f0ce680:	c42ed9ec */ 	lwc1	$f14,%lo(var7f1ad9ec)($at)
/*  f0ce684:	0fc33928 */ 	jal	func0f0ce4a0
/*  f0ce688:	8cc69ff8 */ 	lw	$a2,%lo(g_Vars+0x38)($a2)
/*  f0ce68c:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f0ce690:
/*  f0ce690:	5040000e */ 	beqzl	$v0,.L0f0ce6cc
/*  f0ce694:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f0ce698:	8e0e00a4 */ 	lw	$t6,0xa4($s0)
/*  f0ce69c:	3c017f1b */ 	lui	$at,%hi(var7f1ad9f0)
/*  f0ce6a0:	c428d9f0 */ 	lwc1	$f8,%lo(var7f1ad9f0)($at)
/*  f0ce6a4:	448e2000 */ 	mtc1	$t6,$f4
/*  f0ce6a8:	3c017f1b */ 	lui	$at,%hi(var7f1ad9f4)
/*  f0ce6ac:	3c06800a */ 	lui	$a2,%hi(g_Vars+0x38)
/*  f0ce6b0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ce6b4:	8cc69ff8 */ 	lw	$a2,%lo(g_Vars+0x38)($a2)
/*  f0ce6b8:	c42ed9f4 */ 	lwc1	$f14,%lo(var7f1ad9f4)($at)
/*  f0ce6bc:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f0ce6c0:	0fc33928 */ 	jal	func0f0ce4a0
/*  f0ce6c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce6c8:	8e0f0020 */ 	lw	$t7,0x20($s0)
.L0f0ce6cc:
/*  f0ce6cc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ce6d0:	51e0000f */ 	beqzl	$t7,.L0f0ce710
/*  f0ce6d4:	8e090024 */ 	lw	$t1,0x24($s0)
/*  f0ce6d8:	44816000 */ 	mtc1	$at,$f12
/*  f0ce6dc:	3c017f1b */ 	lui	$at,%hi(var7f1ad9f8)
/*  f0ce6e0:	0fc33957 */ 	jal	currentPlayerUpdateSpeedForwardsGrab
/*  f0ce6e4:	c42ed9f8 */ 	lwc1	$f14,%lo(var7f1ad9f8)($at)
/*  f0ce6e8:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0ce6ec:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0ce6f0:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce6f4:	8c990038 */ 	lw	$t9,0x38($a0)
/*  f0ce6f8:	8c580178 */ 	lw	$t8,0x178($v0)
/*  f0ce6fc:	03194021 */ 	addu	$t0,$t8,$t9
/*  f0ce700:	ac480178 */ 	sw	$t0,0x178($v0)
/*  f0ce704:	10000012 */ 	beqz	$zero,.L0f0ce750
/*  f0ce708:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0ce70c:	8e090024 */ 	lw	$t1,0x24($s0)
.L0f0ce710:
/*  f0ce710:	11200007 */ 	beqz	$t1,.L0f0ce730
/*  f0ce714:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0ce718:	44816000 */ 	mtc1	$at,$f12
/*  f0ce71c:	3c017f1b */ 	lui	$at,%hi(var7f1ad9fc)
/*  f0ce720:	0fc33957 */ 	jal	currentPlayerUpdateSpeedForwardsGrab
/*  f0ce724:	c42ed9fc */ 	lwc1	$f14,%lo(var7f1ad9fc)($at)
/*  f0ce728:	10000009 */ 	beqz	$zero,.L0f0ce750
/*  f0ce72c:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0ce730:
/*  f0ce730:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0ce734:	3c017f1b */ 	lui	$at,%hi(var7f1ada00)
/*  f0ce738:	14600005 */ 	bnez	$v1,.L0f0ce750
/*  f0ce73c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce740:	44806000 */ 	mtc1	$zero,$f12
/*  f0ce744:	0fc33957 */ 	jal	currentPlayerUpdateSpeedForwardsGrab
/*  f0ce748:	c42eda00 */ 	lwc1	$f14,%lo(var7f1ada00)($at)
/*  f0ce74c:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0ce750:
/*  f0ce750:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0ce754:	1060001e */ 	beqz	$v1,.L0f0ce7d0
/*  f0ce758:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0ce75c:	8e0a00a8 */ 	lw	$t2,0xa8($s0)
/*  f0ce760:	3c017f1b */ 	lui	$at,%hi(var7f1ada04)
/*  f0ce764:	c432da04 */ 	lwc1	$f18,%lo(var7f1ada04)($at)
/*  f0ce768:	448a5000 */ 	mtc1	$t2,$f10
/*  f0ce76c:	3c017f1b */ 	lui	$at,%hi(var7f1ada08)
/*  f0ce770:	c42eda08 */ 	lwc1	$f14,%lo(var7f1ada08)($at)
/*  f0ce774:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0ce778:	46128302 */ 	mul.s	$f12,$f16,$f18
/*  f0ce77c:	0fc33957 */ 	jal	currentPlayerUpdateSpeedForwardsGrab
/*  f0ce780:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce784:	8e0b00a8 */ 	lw	$t3,0xa8($s0)
/*  f0ce788:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0ce78c:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f0ce790:	2961003d */ 	slti	$at,$t3,0x3d
/*  f0ce794:	1420000a */ 	bnez	$at,.L0f0ce7c0
/*  f0ce798:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce79c:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0ce7a0:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x38)
/*  f0ce7a4:	8dad9ff8 */ 	lw	$t5,%lo(g_Vars+0x38)($t5)
/*  f0ce7a8:	8c4c0178 */ 	lw	$t4,0x178($v0)
/*  f0ce7ac:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0ce7b0:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0ce7b4:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0ce7b8:	10000005 */ 	beqz	$zero,.L0f0ce7d0
/*  f0ce7bc:	ac4e0178 */ 	sw	$t6,0x178($v0)
.L0f0ce7c0:
/*  f0ce7c0:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f0ce7c4:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0ce7c8:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0ce7cc:	ade00178 */ 	sw	$zero,0x178($t7)
.L0f0ce7d0:
/*  f0ce7d0:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce7d4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ce7d8:	44816000 */ 	mtc1	$at,$f12
/*  f0ce7dc:	c4400170 */ 	lwc1	$f0,0x170($v0)
/*  f0ce7e0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0ce7e4:	44811000 */ 	mtc1	$at,$f2
/*  f0ce7e8:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0ce7ec:	3c017f1b */ 	lui	$at,%hi(var7f1ada0c)
/*  f0ce7f0:	45020005 */ 	bc1fl	.L0f0ce808
/*  f0ce7f4:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0ce7f8:	e44c0170 */ 	swc1	$f12,0x170($v0)
/*  f0ce7fc:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce800:	c4400170 */ 	lwc1	$f0,0x170($v0)
/*  f0ce804:	4602003c */ 	c.lt.s	$f0,$f2
.L0f0ce808:
/*  f0ce808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce80c:	45020004 */ 	bc1fl	.L0f0ce820
/*  f0ce810:	c4400168 */ 	lwc1	$f0,0x168($v0)
/*  f0ce814:	e4420170 */ 	swc1	$f2,0x170($v0)
/*  f0ce818:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce81c:	c4400168 */ 	lwc1	$f0,0x168($v0)
.L0f0ce820:
/*  f0ce820:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0ce824:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce828:	45020005 */ 	bc1fl	.L0f0ce840
/*  f0ce82c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0ce830:	e44c0168 */ 	swc1	$f12,0x168($v0)
/*  f0ce834:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce838:	c4400168 */ 	lwc1	$f0,0x168($v0)
/*  f0ce83c:	4602003c */ 	c.lt.s	$f0,$f2
.L0f0ce840:
/*  f0ce840:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce844:	45020004 */ 	bc1fl	.L0f0ce858
/*  f0ce848:	c4440170 */ 	lwc1	$f4,0x170($v0)
/*  f0ce84c:	e4420168 */ 	swc1	$f2,0x168($v0)
/*  f0ce850:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce854:	c4440170 */ 	lwc1	$f4,0x170($v0)
.L0f0ce858:
/*  f0ce858:	c426da0c */ 	lwc1	$f6,%lo(var7f1ada0c)($at)
/*  f0ce85c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0ce860:	e4480170 */ 	swc1	$f8,0x170($v0)
/*  f0ce864:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce868:	c44a0170 */ 	lwc1	$f10,0x170($v0)
/*  f0ce86c:	c4500174 */ 	lwc1	$f16,0x174($v0)
/*  f0ce870:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0ce874:	e4520170 */ 	swc1	$f18,0x170($v0)
/*  f0ce878:	8e180010 */ 	lw	$t8,0x10($s0)
/*  f0ce87c:	57000007 */ 	bnezl	$t8,.L0f0ce89c
/*  f0ce880:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0ce884:	8e190020 */ 	lw	$t9,0x20($s0)
/*  f0ce888:	57200004 */ 	bnezl	$t9,.L0f0ce89c
/*  f0ce88c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0ce890:	8c880284 */ 	lw	$t0,0x284($a0)
/*  f0ce894:	ad000178 */ 	sw	$zero,0x178($t0)
/*  f0ce898:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0ce89c:
/*  f0ce89c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0ce8a0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0ce8a4:	03e00008 */ 	jr	$ra
/*  f0ce8a8:	00000000 */ 	sll	$zero,$zero,0x0
);

void currentPlayerUpdateSpeedThetaGrab(void)
{
	f32 mult = 0.98470002412796f;
	f32 speedtheta = g_Vars.currentplayer->speedtheta * 0.75f;
	s32 i;

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		g_Vars.currentplayer->unk1b60 = g_Vars.currentplayer->unk1b60 * mult + speedtheta;
	}

	g_Vars.currentplayer->speedtheta = g_Vars.currentplayer->unk1b60 * 0.01529997587204f;
}

GLOBAL_ASM(
glabel func0f0ce924
.late_rodata
glabel var7f1ada18
.word 0x3f4ccccd
glabel var7f1ada1c
.word 0x4528c000
glabel var7f1ada20
.word 0x3ecccccd
glabel var7f1ada24
.word 0x3f333333
glabel var7f1ada28
.word 0x3f99999a
glabel var7f1ada2c
.word 0x3c8ef461
.text
/*  f0ce924:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0ce928:	3c0f8007 */ 	lui	$t7,%hi(var80070ea8)
/*  f0ce92c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0ce930:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0ce934:	25ef0ea8 */ 	addiu	$t7,$t7,%lo(var80070ea8)
/*  f0ce938:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0ce93c:	27ae0074 */ 	addiu	$t6,$sp,0x74
/*  f0ce940:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f0ce944:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0ce948:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0ce94c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ce950:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ce954:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f0ce958:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0ce95c:	8d0a0034 */ 	lw	$t2,0x34($t0)
/*  f0ce960:	59400154 */ 	blezl	$t2,.L0f0ceeb4
/*  f0ce964:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0ce968:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ce96c:	27a40070 */ 	addiu	$a0,$sp,0x70
/*  f0ce970:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0ce974:	c444014c */ 	lwc1	$f4,0x14c($v0)
/*  f0ce978:	8c470150 */ 	lw	$a3,0x150($v0)
/*  f0ce97c:	2446017c */ 	addiu	$a2,$v0,0x17c
/*  f0ce980:	0fc32ea2 */ 	jal	func0f0cba88
/*  f0ce984:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0ce988:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ce98c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ce990:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ce994:	c7a80070 */ 	lwc1	$f8,0x70($sp)
/*  f0ce998:	3c017f1b */ 	lui	$at,%hi(var7f1ada18)
/*  f0ce99c:	c4460170 */ 	lwc1	$f6,0x170($v0)
/*  f0ce9a0:	c42cda18 */ 	lwc1	$f12,%lo(var7f1ada18)($at)
/*  f0ce9a4:	3c018007 */ 	lui	$at,0x8007
/*  f0ce9a8:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0ce9ac:	4480a000 */ 	mtc1	$zero,$f20
/*  f0ce9b0:	e44a0170 */ 	swc1	$f10,0x170($v0)
/*  f0ce9b4:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ce9b8:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f0ce9bc:	c4440168 */ 	lwc1	$f4,0x168($v0)
/*  f0ce9c0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0ce9c4:	e4480168 */ 	swc1	$f8,0x168($v0)
/*  f0ce9c8:	c42a5c24 */ 	lwc1	$f10,0x5c24($at)
/*  f0ce9cc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0ce9d0:	44812000 */ 	mtc1	$at,$f4
/*  f0ce9d4:	c50e004c */ 	lwc1	$f14,0x4c($t0)
/*  f0ce9d8:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ce9dc:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0ce9e0:	3c013f40 */ 	lui	$at,0x3f40
/*  f0ce9e4:	c4400168 */ 	lwc1	$f0,0x168($v0)
/*  f0ce9e8:	460e3082 */ 	mul.s	$f2,$f6,$f14
/*  f0ce9ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce9f0:	46020202 */ 	mul.s	$f8,$f0,$f2
/*  f0ce9f4:	e7a80088 */ 	swc1	$f8,0x88($sp)
/*  f0ce9f8:	460c0402 */ 	mul.s	$f16,$f0,$f12
/*  f0ce9fc:	c44a0148 */ 	lwc1	$f10,0x148($v0)
/*  f0cea00:	c4520170 */ 	lwc1	$f18,0x170($v0)
/*  f0cea04:	44810000 */ 	mtc1	$at,$f0
/*  f0cea08:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f0cea0c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0cea10:	e7a40060 */ 	swc1	$f4,0x60($sp)
/*  f0cea14:	45000002 */ 	bc1f	.L0f0cea20
/*  f0cea18:	c7a60060 */ 	lwc1	$f6,0x60($sp)
/*  f0cea1c:	46008407 */ 	neg.s	$f16,$f16
.L0f0cea20:
/*  f0cea20:	4614903c */ 	c.lt.s	$f18,$f20
/*  f0cea24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cea28:	45020003 */ 	bc1fl	.L0f0cea38
/*  f0cea2c:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0cea30:	46009487 */ 	neg.s	$f18,$f18
/*  f0cea34:	4614303c */ 	c.lt.s	$f6,$f20
.L0f0cea38:
/*  f0cea38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cea3c:	45020004 */ 	bc1fl	.L0f0cea50
/*  f0cea40:	4610903c */ 	c.lt.s	$f18,$f16
/*  f0cea44:	46003207 */ 	neg.s	$f8,$f6
/*  f0cea48:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*  f0cea4c:	4610903c */ 	c.lt.s	$f18,$f16
.L0f0cea50:
/*  f0cea50:	46009306 */ 	mov.s	$f12,$f18
/*  f0cea54:	c7aa0060 */ 	lwc1	$f10,0x60($sp)
/*  f0cea58:	45020003 */ 	bc1fl	.L0f0cea68
/*  f0cea5c:	460a603c */ 	c.lt.s	$f12,$f10
/*  f0cea60:	46008306 */ 	mov.s	$f12,$f16
/*  f0cea64:	460a603c */ 	c.lt.s	$f12,$f10
.L0f0cea68:
/*  f0cea68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cea6c:	45020003 */ 	bc1fl	.L0f0cea7c
/*  f0cea70:	460c003e */ 	c.le.s	$f0,$f12
/*  f0cea74:	46005306 */ 	mov.s	$f12,$f10
/*  f0cea78:	460c003e */ 	c.le.s	$f0,$f12
.L0f0cea7c:
/*  f0cea7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cea80:	4502000b */ 	bc1fl	.L0f0ceab0
/*  f0cea84:	460c0201 */ 	sub.s	$f8,$f0,$f12
/*  f0cea88:	46006101 */ 	sub.s	$f4,$f12,$f0
/*  f0cea8c:	3c014461 */ 	lui	$at,0x4461
/*  f0cea90:	44814000 */ 	mtc1	$at,$f8
/*  f0cea94:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f0cea98:	c4440198 */ 	lwc1	$f4,0x198($v0)
/*  f0cea9c:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0ceaa0:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0ceaa4:	10000009 */ 	beqz	$zero,.L0f0ceacc
/*  f0ceaa8:	e4460198 */ 	swc1	$f6,0x198($v0)
/*  f0ceaac:	460c0201 */ 	sub.s	$f8,$f0,$f12
.L0f0ceab0:
/*  f0ceab0:	3c017f1b */ 	lui	$at,%hi(var7f1ada1c)
/*  f0ceab4:	c42ada1c */ 	lwc1	$f10,%lo(var7f1ada1c)($at)
/*  f0ceab8:	460e4102 */ 	mul.s	$f4,$f8,$f14
/*  f0ceabc:	c4480198 */ 	lwc1	$f8,0x198($v0)
/*  f0ceac0:	460a2183 */ 	div.s	$f6,$f4,$f10
/*  f0ceac4:	46064101 */ 	sub.s	$f4,$f8,$f6
/*  f0ceac8:	e4440198 */ 	swc1	$f4,0x198($v0)
.L0f0ceacc:
/*  f0ceacc:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0cead0:	c4400198 */ 	lwc1	$f0,0x198($v0)
/*  f0cead4:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0cead8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceadc:	45020005 */ 	bc1fl	.L0f0ceaf4
/*  f0ceae0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ceae4:	e4540198 */ 	swc1	$f20,0x198($v0)
/*  f0ceae8:	1000000c */ 	beqz	$zero,.L0f0ceb1c
/*  f0ceaec:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ceaf0:	3c013f80 */ 	lui	$at,0x3f80
.L0f0ceaf4:
/*  f0ceaf4:	44815000 */ 	mtc1	$at,$f10
/*  f0ceaf8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ceafc:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0ceb00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceb04:	45020006 */ 	bc1fl	.L0f0ceb20
/*  f0ceb08:	c44e0170 */ 	lwc1	$f14,0x170($v0)
/*  f0ceb0c:	44814000 */ 	mtc1	$at,$f8
/*  f0ceb10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceb14:	e4480198 */ 	swc1	$f8,0x198($v0)
/*  f0ceb18:	8d020284 */ 	lw	$v0,0x284($t0)
.L0f0ceb1c:
/*  f0ceb1c:	c44e0170 */ 	lwc1	$f14,0x170($v0)
.L0f0ceb20:
/*  f0ceb20:	e7ac005c */ 	swc1	$f12,0x5c($sp)
/*  f0ceb24:	0fc33195 */ 	jal	func0f0cc654
/*  f0ceb28:	8fa60088 */ 	lw	$a2,0x88($sp)
/*  f0ceb2c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ceb30:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ceb34:	c7ac005c */ 	lwc1	$f12,0x5c($sp)
/*  f0ceb38:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0ceb3c:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0ceb40:	e56c00cc */ 	swc1	$f12,0xcc($t3)
/*  f0ceb44:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ceb48:	c44003c0 */ 	lwc1	$f0,0x3c0($v0)
/*  f0ceb4c:	c44203c8 */ 	lwc1	$f2,0x3c8($v0)
/*  f0ceb50:	e7a00084 */ 	swc1	$f0,0x84($sp)
/*  f0ceb54:	0fc41b99 */ 	jal	cheatIsActive
/*  f0ceb58:	e7a20080 */ 	swc1	$f2,0x80($sp)
/*  f0ceb5c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ceb60:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ceb64:	c7a00084 */ 	lwc1	$f0,0x84($sp)
/*  f0ceb68:	10400007 */ 	beqz	$v0,.L0f0ceb88
/*  f0ceb6c:	c7a20080 */ 	lwc1	$f2,0x80($sp)
/*  f0ceb70:	3c017f1b */ 	lui	$at,%hi(var7f1ada20)
/*  f0ceb74:	c42cda20 */ 	lwc1	$f12,%lo(var7f1ada20)($at)
/*  f0ceb78:	460c0002 */ 	mul.s	$f0,$f0,$f12
/*  f0ceb7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceb80:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0ceb84:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ceb88:
/*  f0ceb88:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ceb8c:	c50e004c */ 	lwc1	$f14,0x4c($t0)
/*  f0ceb90:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0ceb94:	c446036c */ 	lwc1	$f6,0x36c($v0)
/*  f0ceb98:	c44a0374 */ 	lwc1	$f10,0x374($v0)
/*  f0ceb9c:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f0ceba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceba4:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0ceba8:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f0cebac:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0cebb0:	460e3282 */ 	mul.s	$f10,$f6,$f14
/*  f0cebb4:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0cebb8:	e7a80074 */ 	swc1	$f8,0x74($sp)
/*  f0cebbc:	c4460374 */ 	lwc1	$f6,0x374($v0)
/*  f0cebc0:	c44a036c */ 	lwc1	$f10,0x36c($v0)
/*  f0cebc4:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f0cebc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cebcc:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0cebd0:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0cebd4:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f0cebd8:	460e3282 */ 	mul.s	$f10,$f6,$f14
/*  f0cebdc:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0cebe0:	0fc32ed2 */ 	jal	currentPlayerUpdateMoveInitSpeed
/*  f0cebe4:	e7a8007c */ 	swc1	$f8,0x7c($sp)
/*  f0cebe8:	0fc47b82 */ 	jal	func0f11ee08
/*  f0cebec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cebf0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0cebf4:	1040001f */ 	beqz	$v0,.L0f0cec74
/*  f0cebf8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0cebfc:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0cec00:	c50e004c */ 	lwc1	$f14,0x4c($t0)
/*  f0cec04:	3c014120 */ 	lui	$at,0x4120
/*  f0cec08:	c446036c */ 	lwc1	$f6,0x36c($v0)
/*  f0cec0c:	c4440170 */ 	lwc1	$f4,0x170($v0)
/*  f0cec10:	c4480374 */ 	lwc1	$f8,0x374($v0)
/*  f0cec14:	44810000 */ 	mtc1	$at,$f0
/*  f0cec18:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0cec1c:	c4460168 */ 	lwc1	$f6,0x168($v0)
/*  f0cec20:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f0cec24:	46045201 */ 	sub.s	$f8,$f10,$f4
/*  f0cec28:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0cec2c:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*  f0cec30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cec34:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f0cec38:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0cec3c:	e7a80074 */ 	swc1	$f8,0x74($sp)
/*  f0cec40:	c4440170 */ 	lwc1	$f4,0x170($v0)
/*  f0cec44:	c4460374 */ 	lwc1	$f6,0x374($v0)
/*  f0cec48:	c448036c */ 	lwc1	$f8,0x36c($v0)
/*  f0cec4c:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0cec50:	c4460168 */ 	lwc1	$f6,0x168($v0)
/*  f0cec54:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f0cec58:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f0cec5c:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f0cec60:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*  f0cec64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cec68:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f0cec6c:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0cec70:	e7a8007c */ 	swc1	$f8,0x7c($sp)
.L0f0cec74:
/*  f0cec74:	0fc3382f */ 	jal	func0f0ce0bc
/*  f0cec78:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0cec7c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0cec80:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0cec84:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0cec88:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f0cec8c:	c4480318 */ 	lwc1	$f8,0x318($v0)
/*  f0cec90:	c4440310 */ 	lwc1	$f4,0x310($v0)
/*  f0cec94:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f0cec98:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f0cec9c:	c440036c */ 	lwc1	$f0,0x36c($v0)
/*  f0ceca0:	46085381 */ 	sub.s	$f14,$f10,$f8
/*  f0ceca4:	c4420374 */ 	lwc1	$f2,0x374($v0)
/*  f0ceca8:	46043301 */ 	sub.s	$f12,$f6,$f4
/*  f0cecac:	460e0182 */ 	mul.s	$f6,$f0,$f14
/*  f0cecb0:	46006107 */ 	neg.s	$f4,$f12
/*  f0cecb4:	46022282 */ 	mul.s	$f10,$f4,$f2
/*  f0cecb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cecbc:	460e1202 */ 	mul.s	$f8,$f2,$f14
/*  f0cecc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cecc4:	46006102 */ 	mul.s	$f4,$f12,$f0
/*  f0cecc8:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f0ceccc:	c7aa007c */ 	lwc1	$f10,0x7c($sp)
/*  f0cecd0:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0cecd4:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0cecd8:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0cecdc:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*  f0cece0:	46002187 */ 	neg.s	$f6,$f4
/*  f0cece4:	46023182 */ 	mul.s	$f6,$f6,$f2
/*  f0cece8:	46064480 */ 	add.s	$f18,$f8,$f6
/*  f0cecec:	460a1202 */ 	mul.s	$f8,$f2,$f10
/*  f0cecf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cecf4:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0cecf8:	46149032 */ 	c.eq.s	$f18,$f20
/*  f0cecfc:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f0ced00:	45010019 */ 	bc1t	.L0f0ced68
/*  f0ced04:	e7aa0044 */ 	swc1	$f10,0x44($sp)
/*  f0ced08:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0ced0c:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0ced10:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0ced14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ced18:	45020014 */ 	bc1fl	.L0f0ced6c
/*  f0ced1c:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f0ced20:	46128403 */ 	div.s	$f16,$f16,$f18
/*  f0ced24:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ced28:	4614803e */ 	c.le.s	$f16,$f20
/*  f0ced2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ced30:	45020005 */ 	bc1fl	.L0f0ced48
/*  f0ced34:	44814000 */ 	mtc1	$at,$f8
/*  f0ced38:	e454016c */ 	swc1	$f20,0x16c($v0)
/*  f0ced3c:	1000000a */ 	beqz	$zero,.L0f0ced68
/*  f0ced40:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ced44:	44814000 */ 	mtc1	$at,$f8
.L0f0ced48:
/*  f0ced48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ced4c:	4608803c */ 	c.lt.s	$f16,$f8
/*  f0ced50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ced54:	45020005 */ 	bc1fl	.L0f0ced6c
/*  f0ced58:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f0ced5c:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f0ced60:	e446016c */ 	swc1	$f6,0x16c($v0)
/*  f0ced64:	8d020284 */ 	lw	$v0,0x284($t0)
.L0f0ced68:
/*  f0ced68:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
.L0f0ced6c:
/*  f0ced6c:	46145032 */ 	c.eq.s	$f10,$f20
/*  f0ced70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ced74:	4503001c */ 	bc1tl	.L0f0cede8
/*  f0ced78:	c4460148 */ 	lwc1	$f6,0x148($v0)
/*  f0ced7c:	c44019a4 */ 	lwc1	$f0,0x19a4($v0)
/*  f0ced80:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*  f0ced84:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f0ced88:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0ced8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ced90:	45020015 */ 	bc1fl	.L0f0cede8
/*  f0ced94:	c4460148 */ 	lwc1	$f6,0x148($v0)
/*  f0ced98:	460a4183 */ 	div.s	$f6,$f8,$f10
/*  f0ced9c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ceda0:	4614303e */ 	c.le.s	$f6,$f20
/*  f0ceda4:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*  f0ceda8:	c7a4004c */ 	lwc1	$f4,0x4c($sp)
/*  f0cedac:	45020005 */ 	bc1fl	.L0f0cedc4
/*  f0cedb0:	44814000 */ 	mtc1	$at,$f8
/*  f0cedb4:	e45419a4 */ 	swc1	$f20,0x19a4($v0)
/*  f0cedb8:	1000000a */ 	beqz	$zero,.L0f0cede4
/*  f0cedbc:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0cedc0:	44814000 */ 	mtc1	$at,$f8
.L0f0cedc4:
/*  f0cedc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cedc8:	4608203c */ 	c.lt.s	$f4,$f8
/*  f0cedcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cedd0:	45020005 */ 	bc1fl	.L0f0cede8
/*  f0cedd4:	c4460148 */ 	lwc1	$f6,0x148($v0)
/*  f0cedd8:	46040282 */ 	mul.s	$f10,$f0,$f4
/*  f0ceddc:	e44a19a4 */ 	swc1	$f10,0x19a4($v0)
/*  f0cede0:	8d020284 */ 	lw	$v0,0x284($t0)
.L0f0cede4:
/*  f0cede4:	c4460148 */ 	lwc1	$f6,0x148($v0)
.L0f0cede8:
/*  f0cede8:	3c017f1b */ 	lui	$at,%hi(var7f1ada24)
/*  f0cedec:	c424da24 */ 	lwc1	$f4,%lo(var7f1ada24)($at)
/*  f0cedf0:	e7a60040 */ 	swc1	$f6,0x40($sp)
/*  f0cedf4:	c448015c */ 	lwc1	$f8,0x15c($v0)
/*  f0cedf8:	c44a00cc */ 	lwc1	$f10,0xcc($v0)
/*  f0cedfc:	46044083 */ 	div.s	$f2,$f8,$f4
/*  f0cee00:	e7aa0038 */ 	swc1	$f10,0x38($sp)
/*  f0cee04:	0fc4505b */ 	jal	func0f11416c
/*  f0cee08:	e7a2003c */ 	swc1	$f2,0x3c($sp)
/*  f0cee0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cee10:	44817000 */ 	mtc1	$at,$f14
/*  f0cee14:	c7a2003c */ 	lwc1	$f2,0x3c($sp)
/*  f0cee18:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0cee1c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0cee20:	4602703c */ 	c.lt.s	$f14,$f2
/*  f0cee24:	46000306 */ 	mov.s	$f12,$f0
/*  f0cee28:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cee2c:	8fa70040 */ 	lw	$a3,0x40($sp)
/*  f0cee30:	45020004 */ 	bc1fl	.L0f0cee44
/*  f0cee34:	44817000 */ 	mtc1	$at,$f14
/*  f0cee38:	10000008 */ 	beqz	$zero,.L0f0cee5c
/*  f0cee3c:	46007086 */ 	mov.s	$f2,$f14
/*  f0cee40:	44817000 */ 	mtc1	$at,$f14
.L0f0cee44:
/*  f0cee44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cee48:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0cee4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cee50:	45020003 */ 	bc1fl	.L0f0cee60
/*  f0cee54:	8d0c0284 */ 	lw	$t4,0x284($t0)
/*  f0cee58:	46007086 */ 	mov.s	$f2,$f14
.L0f0cee5c:
/*  f0cee5c:	8d0c0284 */ 	lw	$t4,0x284($t0)
.L0f0cee60:
/*  f0cee60:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cee64:	44061000 */ 	mfc1	$a2,$f2
/*  f0cee68:	8d8d03ac */ 	lw	$t5,0x3ac($t4)
/*  f0cee6c:	c7ae0038 */ 	lwc1	$f14,0x38($sp)
/*  f0cee70:	15a10004 */ 	bne	$t5,$at,.L0f0cee84
/*  f0cee74:	3c017f1b */ 	lui	$at,%hi(var7f1ada28)
/*  f0cee78:	c426da28 */ 	lwc1	$f6,%lo(var7f1ada28)($at)
/*  f0cee7c:	46060302 */ 	mul.s	$f12,$f0,$f6
/*  f0cee80:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cee84:
/*  f0cee84:	0fc27637 */ 	jal	func0f09d8dc
/*  f0cee88:	e7b40010 */ 	swc1	$f20,0x10($sp)
/*  f0cee8c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0cee90:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0cee94:	8d190284 */ 	lw	$t9,0x284($t0)
/*  f0cee98:	3c017f1b */ 	lui	$at,%hi(var7f1ada2c)
/*  f0cee9c:	c424da2c */ 	lwc1	$f4,%lo(var7f1ada2c)($at)
/*  f0ceea0:	c7280158 */ 	lwc1	$f8,0x158($t9)
/*  f0ceea4:	46044302 */ 	mul.s	$f12,$f8,$f4
/*  f0ceea8:	0fc288a4 */ 	jal	func0f0a2290
/*  f0ceeac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceeb0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0ceeb4:
/*  f0ceeb4:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0ceeb8:	27bd0090 */ 	addiu	$sp,$sp,0x90
/*  f0ceebc:	03e00008 */ 	jr	$ra
/*  f0ceec0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ceec4
.late_rodata
glabel var7f1ada30
.word 0xc6ea6000
.text
/*  f0ceec4:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0ceec8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0ceecc:	0fc33840 */ 	jal	currentPlayerUpdatePrevPosGrab
/*  f0ceed0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0ceed4:	0fc337bc */ 	jal	func0f0cdef0
/*  f0ceed8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceedc:	0fc32fd4 */ 	jal	func0f0cbf50
/*  f0ceee0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceee4:	0fc33a49 */ 	jal	func0f0ce924
/*  f0ceee8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceeec:	0fc3385e */ 	jal	func0f0ce178
/*  f0ceef0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceef4:	0fc3386b */ 	jal	func0f0ce1ac
/*  f0ceef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceefc:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0cef00:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f0cef04:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0cef08:	8e0600bc */ 	lw	$a2,0xbc($s0)
/*  f0cef0c:	84ce0028 */ 	lh	$t6,0x28($a2)
/*  f0cef10:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0cef14:	50ae0018 */ 	beql	$a1,$t6,.L0f0cef78
/*  f0cef18:	8e091b5c */ 	lw	$t1,0x1b5c($s0)
/*  f0cef1c:	860419b0 */ 	lh	$a0,0x19b0($s0)
/*  f0cef20:	84c30028 */ 	lh	$v1,0x28($a2)
.L0f0cef24:
/*  f0cef24:	54830010 */ 	bnel	$a0,$v1,.L0f0cef68
/*  f0cef28:	8443002a */ 	lh	$v1,0x2a($v0)
/*  f0cef2c:	0fc19711 */ 	jal	func0f065c44
/*  f0cef30:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0cef34:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0cef38:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0cef3c:	8c500284 */ 	lw	$s0,0x284($v0)
/*  f0cef40:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0cef44:	860f19b0 */ 	lh	$t7,0x19b0($s0)
/*  f0cef48:	8e1800bc */ 	lw	$t8,0xbc($s0)
/*  f0cef4c:	a70f0028 */ 	sh	$t7,0x28($t8)
/*  f0cef50:	8c590284 */ 	lw	$t9,0x284($v0)
/*  f0cef54:	8f2800bc */ 	lw	$t0,0xbc($t9)
/*  f0cef58:	a505002a */ 	sh	$a1,0x2a($t0)
/*  f0cef5c:	10000005 */ 	beqz	$zero,.L0f0cef74
/*  f0cef60:	8c500284 */ 	lw	$s0,0x284($v0)
/*  f0cef64:	8443002a */ 	lh	$v1,0x2a($v0)
.L0f0cef68:
/*  f0cef68:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0cef6c:	14a3ffed */ 	bne	$a1,$v1,.L0f0cef24
/*  f0cef70:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cef74:
/*  f0cef74:	8e091b5c */ 	lw	$t1,0x1b5c($s0)
.L0f0cef78:
/*  f0cef78:	24010035 */ 	addiu	$at,$zero,0x35
/*  f0cef7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cef80:	8d220004 */ 	lw	$v0,0x4($t1)
/*  f0cef84:	90430003 */ 	lbu	$v1,0x3($v0)
/*  f0cef88:	00402025 */ 	or	$a0,$v0,$zero
/*  f0cef8c:	54610004 */ 	bnel	$v1,$at,.L0f0cefa0
/*  f0cef90:	24010033 */ 	addiu	$at,$zero,0x33
/*  f0cef94:	10000005 */ 	beqz	$zero,.L0f0cefac
/*  f0cef98:	2445005c */ 	addiu	$a1,$v0,0x5c
/*  f0cef9c:	24010033 */ 	addiu	$at,$zero,0x33
.L0f0cefa0:
/*  f0cefa0:	14610002 */ 	bne	$v1,$at,.L0f0cefac
/*  f0cefa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cefa8:	2445005c */ 	addiu	$a1,$v0,0x5c
.L0f0cefac:
/*  f0cefac:	10a00005 */ 	beqz	$a1,.L0f0cefc4
/*  f0cefb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cefb4:	0fc1c52e */ 	jal	func0f0714b8
/*  f0cefb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cefbc:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0cefc0:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
.L0f0cefc4:
/*  f0cefc4:	0fc32e31 */ 	jal	func0f0cb8c4
/*  f0cefc8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cefcc:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x284)
/*  f0cefd0:	8d4aa244 */ 	lw	$t2,%lo(g_Vars+0x284)($t2)
/*  f0cefd4:	8d4b00bc */ 	lw	$t3,0xbc($t2)
/*  f0cefd8:	0fc257d8 */ 	jal	objectiveCheckRoomEntered
/*  f0cefdc:	85640028 */ 	lh	$a0,0x28($t3)
/*  f0cefe0:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x284)
/*  f0cefe4:	8d8ca244 */ 	lw	$t4,%lo(g_Vars+0x284)($t4)
/*  f0cefe8:	8d8400bc */ 	lw	$a0,0xbc($t4)
/*  f0cefec:	0fc33067 */ 	jal	func0f0cc19c
/*  f0ceff0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0ceff4:	0fc307fd */ 	jal	func0f0c1ff4
/*  f0ceff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceffc:	0fc23064 */ 	jal	func0f08c190
/*  f0cf000:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf004:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x284)
/*  f0cf008:	8dada244 */ 	lw	$t5,%lo(g_Vars+0x284)($t5)
/*  f0cf00c:	8da21b5c */ 	lw	$v0,0x1b5c($t5)
/*  f0cf010:	50400048 */ 	beqzl	$v0,.L0f0cf134
/*  f0cf014:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0cf018:	0fc1c4d8 */ 	jal	func0f071360
/*  f0cf01c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0cf020:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0cf024:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f0cf028:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cf02c:	8e021b5c */ 	lw	$v0,0x1b5c($s0)
/*  f0cf030:	c6080074 */ 	lwc1	$f8,0x74($s0)
/*  f0cf034:	c444000c */ 	lwc1	$f4,0xc($v0)
/*  f0cf038:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f0cf03c:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0cf040:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0cf044:	e7aa0030 */ 	swc1	$f10,0x30($sp)
/*  f0cf048:	0fc1905e */ 	jal	func0f064178
/*  f0cf04c:	8e0400bc */ 	lw	$a0,0xbc($s0)
/*  f0cf050:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f0cf054:	0fc1905e */ 	jal	func0f064178
/*  f0cf058:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cf05c:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0cf060:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f0cf064:	3c017f1b */ 	lui	$at,%hi(var7f1ada30)
/*  f0cf068:	c430da30 */ 	lwc1	$f16,%lo(var7f1ada30)($at)
/*  f0cf06c:	c6000078 */ 	lwc1	$f0,0x78($s0)
/*  f0cf070:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f0cf074:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0cf078:	4610003e */ 	c.le.s	$f0,$f16
/*  f0cf07c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf080:	45010021 */ 	bc1t	.L0f0cf108
/*  f0cf084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf088:	44819000 */ 	mtc1	$at,$f18
/*  f0cf08c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0cf090:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0cf094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf098:	4501001b */ 	bc1t	.L0f0cf108
/*  f0cf09c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf0a0:	44812000 */ 	mtc1	$at,$f4
/*  f0cf0a4:	3c014248 */ 	lui	$at,0x4248
/*  f0cf0a8:	4602203c */ 	c.lt.s	$f4,$f2
/*  f0cf0ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf0b0:	45010015 */ 	bc1t	.L0f0cf108
/*  f0cf0b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf0b8:	c6060074 */ 	lwc1	$f6,0x74($s0)
/*  f0cf0bc:	44814000 */ 	mtc1	$at,$f8
/*  f0cf0c0:	240e003f */ 	addiu	$t6,$zero,0x3f
/*  f0cf0c4:	240f000c */ 	addiu	$t7,$zero,0xc
/*  f0cf0c8:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0cf0cc:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0cf0d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf0d4:	4501000c */ 	bc1t	.L0f0cf108
/*  f0cf0d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf0dc:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0cf0e0:	8e021b5c */ 	lw	$v0,0x1b5c($s0)
/*  f0cf0e4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0cf0e8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0cf0ec:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0cf0f0:	24650028 */ 	addiu	$a1,$v1,0x28
/*  f0cf0f4:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f0cf0f8:	0c00b70f */ 	jal	hasLineOfSight
/*  f0cf0fc:	24470028 */ 	addiu	$a3,$v0,0x28
/*  f0cf100:	14400003 */ 	bnez	$v0,.L0f0cf110
/*  f0cf104:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cf108:
/*  f0cf108:	0fc31f4c */ 	jal	currentPlayerSetMoveMode
/*  f0cf10c:	00002025 */ 	or	$a0,$zero,$zero
.L0f0cf110:
/*  f0cf110:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f0cf114:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f0cf118:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cf11c:	0fc1905e */ 	jal	func0f064178
/*  f0cf120:	8f0400bc */ 	lw	$a0,0xbc($t8)
/*  f0cf124:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f0cf128:	0fc1905e */ 	jal	func0f064178
/*  f0cf12c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cf130:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0cf134:
/*  f0cf134:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0cf138:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0cf13c:	03e00008 */ 	jr	$ra
/*  f0cf140:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf144:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf14c:	00000000 */ 	sll	$zero,$zero,0x0
);
