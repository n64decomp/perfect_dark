#include <ultra64.h>
#include "constants.h"
#include "game/bondgrab.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/debug.h"
#include "game/prop.h"
#include "game/objectives.h"
#include "game/bondgun.h"
#include "game/player.h"
#include "game/bondhead.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "data.h"
#include "types.h"

struct prop *var8009de70;
u32 var8009de74;
struct coord var8009de78;
u32 var8009de84;
u32 var8009de88;
u32 var8009de8c;

bool var80070e80 = false;

void bgrabInit(void)
{
	s32 prevmode = g_Vars.currentplayer->bondmovemode;
	Mtxf matrix;
	struct prop *prop = g_Vars.currentplayer->grabbedprop;

	g_Vars.currentplayer->bondmovemode = MOVEMODE_GRAB;

	g_Vars.currentplayer->bondgrabthetaspeedsum = 0;
	g_Vars.currentplayer->grabbedprevpos.x = prop->pos.x;
	g_Vars.currentplayer->grabbedprevpos.y = prop->pos.y;
	g_Vars.currentplayer->grabbedprevpos.z = prop->pos.z;
	g_Vars.currentplayer->grabbedrotoffset = 0;
	g_Vars.currentplayer->grabbedforcez = 0;
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

	mtx4LoadYRotation((g_Vars.currentplayer->vv_theta * M_BADTAU) / 360.0f, &matrix);
	mtx4RotateVecInPlace(&matrix, &g_Vars.currentplayer->grabbedposoffset);

	g_Vars.currentplayer->bondprevtheta = g_Vars.currentplayer->vv_theta;

	if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_DOOR || prop->type == PROPTYPE_WEAPON) {
		struct defaultobj *obj = prop->obj;
		struct hov *hov = NULL;
		bool withforce;

		if (obj->hidden & OBJHFLAG_AIRBORNE) {
			struct projectile *projectile = obj->projectile;
			g_Vars.currentplayer->bondshotspeed.x += projectile->speed.x * 0.2f;
			g_Vars.currentplayer->bondshotspeed.z += projectile->speed.z * 0.2f;
			objEndFlight(obj);
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
				hov->unk10 - (M_BADTAU - (g_Vars.currentplayer->vv_theta * M_BADTAU) / 360.0f);

			if (g_Vars.currentplayer->grabbedrotoffset >= M_BADTAU) {
				g_Vars.currentplayer->grabbedrotoffset -= M_BADTAU;
			} else if (g_Vars.currentplayer->grabbedrotoffset < 0) {
				g_Vars.currentplayer->grabbedrotoffset += M_BADTAU;
			}
		}

		obj->hidden |= OBJHFLAG_GRABBED;

		if (obj->flags3 & OBJFLAG3_GEOTYPE3) {
			withforce = cd000276c8(obj->geo3,
					g_Vars.currentplayer->prop->pos.x,
					g_Vars.currentplayer->prop->pos.z,
					VERSION >= VERSION_NTSC_1_0 ? 45 : 40, 0, 0);
		} else {
			withforce = cd000274e0(obj->geo2,
					g_Vars.currentplayer->prop->pos.x,
					g_Vars.currentplayer->prop->pos.z,
					VERSION >= VERSION_NTSC_1_0 ? 45 : 40, 0, 0);
		}

		if (withforce) {
			g_Vars.currentplayer->grabbedforcez = VERSION >= VERSION_NTSC_1_0 ? 15 : 10;
		}
	}

	if (prevmode != MOVEMODE_GRAB && prevmode != MOVEMODE_WALK) {
		s32 i;

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
		g_Vars.currentplayer->moveinitspeed.x = 0;
		g_Vars.currentplayer->moveinitspeed.y = 0;
		g_Vars.currentplayer->moveinitspeed.z = 0;
	}

	g_Vars.currentplayer->grabstarttime = g_Vars.lvframe60;
}

void bgrabExit(void)
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
				* M_BADTAU / 360;

			if (rotateamount < -M_PI) {
				rotateamount += M_BADTAU;
			} else if (rotateamount >= M_PI) {
				rotateamount -= M_BADTAU;
			}

			rotateamount /= g_Vars.lvupdate240freal;

			objApplyMomentum(g_Vars.currentplayer->grabbedprop->obj, &moveamount,
					rotateamount, 0, 0);
		}

		g_Vars.currentplayer->grabbedprop = NULL;
	}
}

void bgrab0f0ccbf0(struct coord *delta, f32 angle, struct defaultobj *obj)
{
	struct coord spd4;
	struct coord spc8;
	struct coord spbc;
	struct coord spb0;
	struct coord spa4;
	struct coord sp98;

	if (g_Vars.lvupdate240 > 0) {
		if (var8009de70->type == PROPTYPE_PLAYER) {
			sp98.x = delta->x + g_Vars.currentplayer->prop->pos.x;
			sp98.y = g_Vars.currentplayer->prop->pos.y;
			sp98.z = delta->z + g_Vars.currentplayer->prop->pos.z;

#if VERSION >= VERSION_NTSC_1_0
			cd00024e4c(&spb0, &spa4, 201, "bondgrab.c");
#else
			cd00024e4c(&spb0, &spa4, 200, "bondgrab.c");
#endif

			spc8.x = spa4.z - spb0.z;
			spc8.y = 0.0f;
			spc8.z = spb0.x - spa4.x;

			if (spc8.f[0] != 0.0f || spc8.f[2] != 0.0f) {
				guNormalize(&spc8.x, &spc8.y, &spc8.z);
			} else {
				spc8.z = 1.0f;
			}

			func0f02e3dc(&spb0, &spa4, &sp98, &spc8, &spd4);

			spbc.x = (sp98.x - g_Vars.currentplayer->prop->pos.x) / g_Vars.lvupdate240freal;
			spbc.y = 0.0f;
			spbc.z = (sp98.z - g_Vars.currentplayer->prop->pos.z) / g_Vars.lvupdate240freal;

			func0f082e84(obj, &spd4, &spc8, &spbc, false);
		} else {
			struct coord sp8c;
			struct coord sp80;
			struct coord sp74 = {0, 0, 0};
			struct coord sp68;
			struct coord sp5c;
			struct coord sp50;
			struct coord sp44;

#if VERSION >= VERSION_NTSC_1_0
			cd00024e4c(&sp68, &sp5c, 228, "bondgrab.c");
#else
			cd00024e4c(&sp68, &sp5c, 227, "bondgrab.c");
#endif

			if (cd00025364(&sp50, &sp44)) {
				sp44.x -= sp50.x;
				sp44.y -= sp50.y;
				sp44.z -= sp50.z;
			} else {
				sp50.x = var8009de70->pos.x;
				sp50.y = var8009de70->pos.y;
				sp50.z = var8009de70->pos.z;

				sp44.x = obj->prop->pos.x - var8009de70->pos.x;
				sp44.y = obj->prop->pos.y - var8009de70->pos.y;
				sp44.z = obj->prop->pos.z - var8009de70->pos.z;
			}

			func0f02e3dc(&sp68, &sp5c, &sp50, &sp44, &sp8c);

			sp80.x = delta->x;
			sp80.y = 0.0f;
			sp80.z = delta->z;

			if (sp80.f[0] != 0.0f || sp80.f[2] != 0.0f) {
				guNormalize(&sp80.x, &sp80.y, &sp80.z);
			} else {
				sp80.z = 1.0f;
			}

			if (delta->x != 0.0f) {
				sp74.x += delta->x / g_Vars.lvupdate240freal;
			}

			if (delta->z != 0.0f) {
				sp74.z += delta->z / g_Vars.lvupdate240freal;
			}

			func0f082e84(obj, &sp8c, &sp80, &sp74, false);

			if (angle != 0.0f) {
				f32 sp40 = sp8c.x - g_Vars.currentplayer->prop->pos.x;
				f32 sp3c = sp8c.z - g_Vars.currentplayer->prop->pos.z;
				f32 rotation = 0.0f;
				struct coord sp2c = {0, 0, 0};
				f32 mult = 1.0f / sqrtf(sp40 * sp40 + sp3c * sp3c);

				sp40 *= mult;
				sp3c *= mult;
				angle = angle / g_Vars.lvupdate240freal;

				sp2c.x += -sp3c * angle * 40.0f;
				sp2c.z += sp40 * angle * 40.0f;

				rotation += angle * 0.1f;

				objApplyMomentum(obj, &sp2c, rotation, true, true);
			}
		}
	}
}

bool bgrabTryMoveUpwards(f32 y)
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

	playerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);
	func0f065e74(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, &newpos, rooms);
	bmove0f0cb79c(g_Vars.currentplayer, &newpos, rooms);
	propSetPerimEnabled(g_Vars.currentplayer->prop, false);

	ymin -= 0.1f;

	result = cdTestVolume(&newpos, width, rooms, CDTYPE_ALL, 1,
			ymax - g_Vars.currentplayer->prop->pos.y,
			ymin - g_Vars.currentplayer->prop->pos.y);

	propSetPerimEnabled(g_Vars.currentplayer->prop, true);

	if (result == CDRESULT_NOCOLLISION) {
		g_Vars.currentplayer->prop->pos.y = newpos.y;
		propDeregisterRooms(g_Vars.currentplayer->prop);
		roomsCopy(rooms, g_Vars.currentplayer->prop->rooms);
	}

	return result;
}

#if PAL
GLOBAL_ASM(
glabel bgrabCalculateNewPosition
.late_rodata
glabel var7f1ad998
.word 0x3c8ef461
glabel var7f1ad99c
.word 0x3f7c154d
glabel var7f1ad9a0
.word 0x3c7aacc0
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
/*  f0cd1b0:	3c018007 */ 	lui	$at,%hi(var80070e80)
/*  f0cd1b4:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0cd1b8:	ac200e80 */ 	sw	$zero,%lo(var80070e80)($at)
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
/*  f0cd1f0:	0fc3082e */ 	jal	playerGetBbox
/*  f0cd1f4:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f0cd1f8:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cd1fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cd200:	0fc1905e */ 	jal	propSetPerimEnabled
/*  f0cd204:	8f0400bc */ 	lw	$a0,0xbc($t8)
/*  f0cd208:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cd20c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cd210:	0fc1905e */ 	jal	propSetPerimEnabled
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
/*  f0cd254:	00000000 */ 	nop
/*  f0cd258:	4502000c */ 	bc1fl	.L0f0cd28c
/*  f0cd25c:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0cd260:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f0cd264:	460aa032 */ 	c.eq.s	$f20,$f10
/*  f0cd268:	00000000 */ 	nop
/*  f0cd26c:	45020007 */ 	bc1fl	.L0f0cd28c
/*  f0cd270:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0cd274:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0cd278:	4604a032 */ 	c.eq.s	$f20,$f4
/*  f0cd27c:	00000000 */ 	nop
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
/*  f0cd2d0:	0fc32de7 */ 	jal	bmove0f0cb79c
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
/*  f0cd320:	0c00b62e */ 	jal	cd0002d8b8
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
/*  f0cd374:	0c00a9bf */ 	jal	cd0002a6fc
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
/*  f0cd3a4:	0fc1905e */ 	jal	propSetPerimEnabled
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
/*  f0cd430:	00000000 */ 	nop
/*  f0cd434:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0cd438:	c5060168 */ 	lwc1	$f6,0x168($t0)
/*  f0cd43c:	e7b4008c */ 	swc1	$f20,0x8c($sp)
/*  f0cd440:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0cd444:	00000000 */ 	nop
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
/*  f0cd4f0:	00000000 */ 	nop
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
/*  f0cd54c:	1000000a */ 	b	.L0f0cd578
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
/*  f0cd5ac:	10000007 */ 	b	.L0f0cd5cc
/*  f0cd5b0:	2444005c */ 	addiu	$a0,$v0,0x5c
/*  f0cd5b4:	24010033 */ 	addiu	$at,$zero,0x33
.L0f0cd5b8:
/*  f0cd5b8:	14410004 */ 	bne	$v0,$at,.L0f0cd5cc
/*  f0cd5bc:	00000000 */ 	nop
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
/*  f0cd620:	00000000 */ 	nop
/*  f0cd624:	45000006 */ 	bc1f	.L0f0cd640
/*  f0cd628:	00000000 */ 	nop
/*  f0cd62c:	46027381 */ 	sub.s	$f14,$f14,$f2
.L0f0cd630:
/*  f0cd630:	460e003e */ 	c.le.s	$f0,$f14
/*  f0cd634:	00000000 */ 	nop
/*  f0cd638:	4503fffd */ 	bc1tl	.L0f0cd630
/*  f0cd63c:	46027381 */ 	sub.s	$f14,$f14,$f2
.L0f0cd640:
/*  f0cd640:	c420d9ac */ 	lwc1	$f0,%lo(var7f1ad9ac)($at)
/*  f0cd644:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cd648:	00000000 */ 	nop
/*  f0cd64c:	45020007 */ 	bc1fl	.L0f0cd66c
/*  f0cd650:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f0cd654:	46027380 */ 	add.s	$f14,$f14,$f2
.L0f0cd658:
/*  f0cd658:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cd65c:	00000000 */ 	nop
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
/*  f0cd6b0:	00000000 */ 	nop
/*  f0cd6b4:	45020004 */ 	bc1fl	.L0f0cd6c8
/*  f0cd6b8:	4614603c */ 	c.lt.s	$f12,$f20
/*  f0cd6bc:	10000006 */ 	b	.L0f0cd6d8
/*  f0cd6c0:	46026301 */ 	sub.s	$f12,$f12,$f2
/*  f0cd6c4:	4614603c */ 	c.lt.s	$f12,$f20
.L0f0cd6c8:
/*  f0cd6c8:	00000000 */ 	nop
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
/*  f0cd760:	3c018007 */ 	lui	$at,%hi(var80070e80)
/*  f0cd764:	ac2d0e80 */ 	sw	$t5,%lo(var80070e80)($at)
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
/*  f0cd7f4:	0fc1905e */ 	jal	propSetPerimEnabled
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
/*  f0cd848:	00000000 */ 	nop
/*  f0cd84c:	45020007 */ 	bc1fl	.L0f0cd86c
/*  f0cd850:	4600803e */ 	c.le.s	$f16,$f0
/*  f0cd854:	46100000 */ 	add.s	$f0,$f0,$f16
.L0f0cd858:
/*  f0cd858:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0cd85c:	00000000 */ 	nop
/*  f0cd860:	4503fffd */ 	bc1tl	.L0f0cd858
/*  f0cd864:	46100000 */ 	add.s	$f0,$f0,$f16
/*  f0cd868:	4600803e */ 	c.le.s	$f16,$f0
.L0f0cd86c:
/*  f0cd86c:	00000000 */ 	nop
/*  f0cd870:	45020007 */ 	bc1fl	.L0f0cd890
/*  f0cd874:	e5000144 */ 	swc1	$f0,0x144($t0)
/*  f0cd878:	46100001 */ 	sub.s	$f0,$f0,$f16
.L0f0cd87c:
/*  f0cd87c:	4600803e */ 	c.le.s	$f16,$f0
/*  f0cd880:	00000000 */ 	nop
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
/*  f0cd8d0:	0fc19711 */ 	jal	propDeregisterRooms
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
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel bgrabCalculateNewPosition
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
/*  f0cd1b0:	3c018007 */ 	lui	$at,%hi(var80070e80)
/*  f0cd1b4:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0cd1b8:	ac200e80 */ 	sw	$zero,%lo(var80070e80)($at)
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
/*  f0cd1f0:	0fc3082e */ 	jal	playerGetBbox
/*  f0cd1f4:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f0cd1f8:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cd1fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cd200:	0fc1905e */ 	jal	propSetPerimEnabled
/*  f0cd204:	8f0400bc */ 	lw	$a0,0xbc($t8)
/*  f0cd208:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cd20c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cd210:	0fc1905e */ 	jal	propSetPerimEnabled
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
/*  f0cd254:	00000000 */ 	nop
/*  f0cd258:	4502000c */ 	bc1fl	.L0f0cd28c
/*  f0cd25c:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0cd260:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f0cd264:	460aa032 */ 	c.eq.s	$f20,$f10
/*  f0cd268:	00000000 */ 	nop
/*  f0cd26c:	45020007 */ 	bc1fl	.L0f0cd28c
/*  f0cd270:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0cd274:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0cd278:	4604a032 */ 	c.eq.s	$f20,$f4
/*  f0cd27c:	00000000 */ 	nop
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
/*  f0cd2d0:	0fc32de7 */ 	jal	bmove0f0cb79c
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
/*  f0cd320:	0c00b62e */ 	jal	cd0002d8b8
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
/*  f0cd374:	0c00a9bf */ 	jal	cd0002a6fc
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
/*  f0cd3a4:	0fc1905e */ 	jal	propSetPerimEnabled
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
/*  f0cd430:	00000000 */ 	nop
/*  f0cd434:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0cd438:	c5060168 */ 	lwc1	$f6,0x168($t0)
/*  f0cd43c:	e7b4008c */ 	swc1	$f20,0x8c($sp)
/*  f0cd440:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0cd444:	00000000 */ 	nop
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
/*  f0cd4f0:	00000000 */ 	nop
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
/*  f0cd54c:	1000000a */ 	b	.L0f0cd578
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
/*  f0cd5ac:	10000007 */ 	b	.L0f0cd5cc
/*  f0cd5b0:	2444005c */ 	addiu	$a0,$v0,0x5c
/*  f0cd5b4:	24010033 */ 	addiu	$at,$zero,0x33
.L0f0cd5b8:
/*  f0cd5b8:	14410004 */ 	bne	$v0,$at,.L0f0cd5cc
/*  f0cd5bc:	00000000 */ 	nop
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
/*  f0cd620:	00000000 */ 	nop
/*  f0cd624:	45000006 */ 	bc1f	.L0f0cd640
/*  f0cd628:	00000000 */ 	nop
/*  f0cd62c:	46027381 */ 	sub.s	$f14,$f14,$f2
.L0f0cd630:
/*  f0cd630:	460e003e */ 	c.le.s	$f0,$f14
/*  f0cd634:	00000000 */ 	nop
/*  f0cd638:	4503fffd */ 	bc1tl	.L0f0cd630
/*  f0cd63c:	46027381 */ 	sub.s	$f14,$f14,$f2
.L0f0cd640:
/*  f0cd640:	c420d9ac */ 	lwc1	$f0,%lo(var7f1ad9ac)($at)
/*  f0cd644:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cd648:	00000000 */ 	nop
/*  f0cd64c:	45020007 */ 	bc1fl	.L0f0cd66c
/*  f0cd650:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f0cd654:	46027380 */ 	add.s	$f14,$f14,$f2
.L0f0cd658:
/*  f0cd658:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cd65c:	00000000 */ 	nop
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
/*  f0cd6b0:	00000000 */ 	nop
/*  f0cd6b4:	45020004 */ 	bc1fl	.L0f0cd6c8
/*  f0cd6b8:	4614603c */ 	c.lt.s	$f12,$f20
/*  f0cd6bc:	10000006 */ 	b	.L0f0cd6d8
/*  f0cd6c0:	46026301 */ 	sub.s	$f12,$f12,$f2
/*  f0cd6c4:	4614603c */ 	c.lt.s	$f12,$f20
.L0f0cd6c8:
/*  f0cd6c8:	00000000 */ 	nop
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
/*  f0cd760:	3c018007 */ 	lui	$at,%hi(var80070e80)
/*  f0cd764:	ac2d0e80 */ 	sw	$t5,%lo(var80070e80)($at)
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
/*  f0cd7f4:	0fc1905e */ 	jal	propSetPerimEnabled
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
/*  f0cd848:	00000000 */ 	nop
/*  f0cd84c:	45020007 */ 	bc1fl	.L0f0cd86c
/*  f0cd850:	4600803e */ 	c.le.s	$f16,$f0
/*  f0cd854:	46100000 */ 	add.s	$f0,$f0,$f16
.L0f0cd858:
/*  f0cd858:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0cd85c:	00000000 */ 	nop
/*  f0cd860:	4503fffd */ 	bc1tl	.L0f0cd858
/*  f0cd864:	46100000 */ 	add.s	$f0,$f0,$f16
/*  f0cd868:	4600803e */ 	c.le.s	$f16,$f0
.L0f0cd86c:
/*  f0cd86c:	00000000 */ 	nop
/*  f0cd870:	45020007 */ 	bc1fl	.L0f0cd890
/*  f0cd874:	e5000144 */ 	swc1	$f0,0x144($t0)
/*  f0cd878:	46100001 */ 	sub.s	$f0,$f0,$f16
.L0f0cd87c:
/*  f0cd87c:	4600803e */ 	c.le.s	$f16,$f0
/*  f0cd880:	00000000 */ 	nop
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
/*  f0cd8d0:	0fc19711 */ 	jal	propDeregisterRooms
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
#else
GLOBAL_ASM(
glabel bgrabCalculateNewPosition
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
/*  f0ca9d4:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f0ca9d8:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0ca9dc:	3c10800a */ 	lui	$s0,0x800a
/*  f0ca9e0:	3c018007 */ 	lui	$at,0x8007
/*  f0ca9e4:	2610e6c0 */ 	addiu	$s0,$s0,-6464
/*  f0ca9e8:	ac203540 */ 	sw	$zero,0x3540($at)
/*  f0ca9ec:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0ca9f0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0ca9f4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0ca9f8:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0ca9fc:	afa400e8 */ 	sw	$a0,0xe8($sp)
/*  f0caa00:	afa500ec */ 	sw	$a1,0xec($sp)
/*  f0caa04:	afa600f0 */ 	sw	$a2,0xf0($sp)
/*  f0caa08:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f0caa0c:	afa000c0 */ 	sw	$zero,0xc0($sp)
/*  f0caa10:	27a600bc */ 	addiu	$a2,$sp,0xbc
/*  f0caa14:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0caa18:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f0caa1c:	0fc2ff20 */ 	jal	playerGetBbox
/*  f0caa20:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f0caa24:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0caa28:	00002825 */ 	or	$a1,$zero,$zero
/*  f0caa2c:	0fc18cfb */ 	jal	propSetPerimEnabled
/*  f0caa30:	8f0400bc */ 	lw	$a0,0xbc($t8)
/*  f0caa34:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0caa38:	00002825 */ 	or	$a1,$zero,$zero
/*  f0caa3c:	0fc18cfb */ 	jal	propSetPerimEnabled
/*  f0caa40:	8f241b5c */ 	lw	$a0,0x1b5c($t9)
/*  f0caa44:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0caa48:	8fa300e8 */ 	lw	$v1,0xe8($sp)
/*  f0caa4c:	4480a000 */ 	mtc1	$zero,$f20
/*  f0caa50:	8d0900bc */ 	lw	$t1,0xbc($t0)
/*  f0caa54:	c5240008 */ 	lwc1	$f4,0x8($t1)
/*  f0caa58:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f0caa5c:	8d0a00bc */ 	lw	$t2,0xbc($t0)
/*  f0caa60:	c546000c */ 	lwc1	$f6,0xc($t2)
/*  f0caa64:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
/*  f0caa68:	8d0b00bc */ 	lw	$t3,0xbc($t0)
/*  f0caa6c:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0caa70:	c5680010 */ 	lwc1	$f8,0x10($t3)
/*  f0caa74:	e7a800dc */ 	swc1	$f8,0xdc($sp)
/*  f0caa78:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f0caa7c:	4600a032 */ 	c.eq.s	$f20,$f0
/*  f0caa80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caa84:	4502000c */ 	bc1fl	.NB0f0caab8
/*  f0caa88:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0caa8c:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f0caa90:	460aa032 */ 	c.eq.s	$f20,$f10
/*  f0caa94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caa98:	45020007 */ 	bc1fl	.NB0f0caab8
/*  f0caa9c:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0caaa0:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0caaa4:	4604a032 */ 	c.eq.s	$f20,$f4
/*  f0caaa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caaac:	45030058 */ 	bc1tl	.NB0f0cac10
/*  f0caab0:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0caab4:	46003200 */ 	add.s	$f8,$f6,$f0
.NB0f0caab8:
/*  f0caab8:	c7aa00d8 */ 	lwc1	$f10,0xd8($sp)
/*  f0caabc:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f0caac0:	27a700c4 */ 	addiu	$a3,$sp,0xc4
/*  f0caac4:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*  f0caac8:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f0caacc:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f0caad0:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0caad4:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
/*  f0caad8:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f0caadc:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0caae0:	e7a400dc */ 	swc1	$f4,0xdc($sp)
/*  f0caae4:	8d0200bc */ 	lw	$v0,0xbc($t0)
/*  f0caae8:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0caaec:	0fc19437 */ 	jal	func0f065e74
/*  f0caaf0:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0caaf4:	87ac00c4 */ 	lh	$t4,0xc4($sp)
/*  f0caaf8:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0caafc:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0cab00:	10ac000e */ 	beq	$a1,$t4,.NB0f0cab3c
/*  f0cab04:	27a600c4 */ 	addiu	$a2,$sp,0xc4
/*  f0cab08:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0cab0c:	27a200c4 */ 	addiu	$v0,$sp,0xc4
/*  f0cab10:	84430000 */ 	lh	$v1,0x0($v0)
/*  f0cab14:	85a419b0 */ 	lh	$a0,0x19b0($t5)
.NB0f0cab18:
/*  f0cab18:	54830005 */ 	bnel	$a0,$v1,.NB0f0cab30
/*  f0cab1c:	84430002 */ 	lh	$v1,0x2($v0)
/*  f0cab20:	a7a400c4 */ 	sh	$a0,0xc4($sp)
/*  f0cab24:	10000005 */ 	beqz	$zero,.NB0f0cab3c
/*  f0cab28:	a7af00c6 */ 	sh	$t7,0xc6($sp)
/*  f0cab2c:	84430002 */ 	lh	$v1,0x2($v0)
.NB0f0cab30:
/*  f0cab30:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0cab34:	14a3fff8 */ 	bne	$a1,$v1,.NB0f0cab18
/*  f0cab38:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0cab3c:
/*  f0cab3c:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0cab40:	0fc323f3 */ 	jal	bmove0f0cb79c
/*  f0cab44:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*  f0cab48:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cab4c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0cab50:	afb800c0 */ 	sw	$t8,0xc0($sp)
/*  f0cab54:	8f2200bc */ 	lw	$v0,0xbc($t9)
/*  f0cab58:	2409003f */ 	addiu	$t1,$zero,0x3f
/*  f0cab5c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0cab60:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0cab64:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0cab68:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0cab6c:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f0cab70:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0cab74:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f0cab78:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0cab7c:	27a700c4 */ 	addiu	$a3,$sp,0xc4
/*  f0cab80:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0cab84:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0cab88:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*  f0cab8c:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0cab90:	0c00bb30 */ 	jal	cd0002d8b8
/*  f0cab94:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f0cab98:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cab9c:	14410014 */ 	bne	$v0,$at,.NB0f0cabf0
/*  f0caba0:	afa200e4 */ 	sw	$v0,0xe4($sp)
/*  f0caba4:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0caba8:	240c003f */ 	addiu	$t4,$zero,0x3f
/*  f0cabac:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0cabb0:	8d6200bc */ 	lw	$v0,0xbc($t3)
/*  f0cabb4:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0cabb8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0cabbc:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0cabc0:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f0cabc4:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0cabc8:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*  f0cabcc:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0cabd0:	8fa600b4 */ 	lw	$a2,0xb4($sp)
/*  f0cabd4:	27a700c4 */ 	addiu	$a3,$sp,0xc4
/*  f0cabd8:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0cabdc:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*  f0cabe0:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0cabe4:	0c00aec1 */ 	jal	cd0002a6fc
/*  f0cabe8:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f0cabec:	afa200e4 */ 	sw	$v0,0xe4($sp)
.NB0f0cabf0:
/*  f0cabf0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cabf4:	50410006 */ 	beql	$v0,$at,.NB0f0cac10
/*  f0cabf8:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cabfc:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0cac00:	3c01800a */ 	lui	$at,0x800a
/*  f0cac04:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f0cac08:	ac2f2650 */ 	sw	$t7,0x2650($at)
/*  f0cac0c:	8e180284 */ 	lw	$t8,0x284($s0)
.NB0f0cac10:
/*  f0cac10:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cac14:	0fc18cfb */ 	jal	propSetPerimEnabled
/*  f0cac18:	8f041b5c */ 	lw	$a0,0x1b5c($t8)
/*  f0cac1c:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f0cac20:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cac24:	c7a600ec */ 	lwc1	$f6,0xec($sp)
/*  f0cac28:	5721010e */ 	bnel	$t9,$at,.NB0f0cb064
/*  f0cac2c:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0cac30:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cac34:	46003387 */ 	neg.s	$f14,$f6
/*  f0cac38:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cac3c:	e7ae0040 */ 	swc1	$f14,0x40($sp)
/*  f0cac40:	8d0a1a1c */ 	lw	$t2,0x1a1c($t0)
/*  f0cac44:	8d091b5c */ 	lw	$t1,0x1b5c($t0)
/*  f0cac48:	3c014120 */ 	lui	$at,0x4120
/*  f0cac4c:	11400062 */ 	beqz	$t2,.NB0f0cadd8
/*  f0cac50:	8d250004 */ 	lw	$a1,0x4($t1)
/*  f0cac54:	44811000 */ 	mtc1	$at,$f2
/*  f0cac58:	c50a0148 */ 	lwc1	$f10,0x148($t0)
/*  f0cac5c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0cac60:	c4267cd8 */ 	lwc1	$f6,0x7cd8($at)
/*  f0cac64:	46005107 */ 	neg.s	$f4,$f10
/*  f0cac68:	3c014060 */ 	lui	$at,0x4060
/*  f0cac6c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0cac70:	44815000 */ 	mtc1	$at,$f10
/*  f0cac74:	3c0140c0 */ 	lui	$at,0x40c0
/*  f0cac78:	44812000 */ 	mtc1	$at,$f4
/*  f0cac7c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0cac80:	44813000 */ 	mtc1	$at,$f6
/*  f0cac84:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0cac88:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f0cac8c:	44815000 */ 	mtc1	$at,$f10
/*  f0cac90:	8e030034 */ 	lw	$v1,0x34($s0)
/*  f0cac94:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0cac98:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cac9c:	46040402 */ 	mul.s	$f16,$f0,$f4
/*  f0caca0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caca4:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0caca8:	c5060168 */ 	lwc1	$f6,0x168($t0)
/*  f0cacac:	e7b40084 */ 	swc1	$f20,0x84($sp)
/*  f0cacb0:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0cacb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cacb8:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0cacbc:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0cacc0:	e7aa0080 */ 	swc1	$f10,0x80($sp)
/*  f0cacc4:	c5060170 */ 	lwc1	$f6,0x170($t0)
/*  f0cacc8:	46003107 */ 	neg.s	$f4,$f6
/*  f0caccc:	c5061c58 */ 	lwc1	$f6,0x1c58($t0)
/*  f0cacd0:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f0cacd4:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0cacd8:	e7a40088 */ 	swc1	$f4,0x88($sp)
/*  f0cacdc:	c5081a38 */ 	lwc1	$f8,0x1a38($t0)
/*  f0cace0:	e7a800b0 */ 	swc1	$f8,0xb0($sp)
/*  f0cace4:	c5061a3c */ 	lwc1	$f6,0x1a3c($t0)
/*  f0cace8:	e7a600a4 */ 	swc1	$f6,0xa4($sp)
/*  f0cacec:	c5081a40 */ 	lwc1	$f8,0x1a40($t0)
/*  f0cacf0:	c7b200a4 */ 	lwc1	$f18,0xa4($sp)
/*  f0cacf4:	e7a800a8 */ 	swc1	$f8,0xa8($sp)
/*  f0cacf8:	c5061a44 */ 	lwc1	$f6,0x1a44($t0)
/*  f0cacfc:	18600027 */ 	blez	$v1,.NB0f0cad9c
/*  f0cad00:	e7a600ac */ 	swc1	$f6,0xac($sp)
/*  f0cad04:	46002306 */ 	mov.s	$f12,$f4
/*  f0cad08:	46005086 */ 	mov.s	$f2,$f10
/*  f0cad0c:	c4207cdc */ 	lwc1	$f0,0x7cdc($at)
/*  f0cad10:	c7a800b0 */ 	lwc1	$f8,0xb0($sp)
/*  f0cad14:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0cad18:	0043082a */ 	slt	$at,$v0,$v1
/*  f0cad1c:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0cad20:	10200012 */ 	beqz	$at,.NB0f0cad6c
/*  f0cad24:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
.NB0f0cad28:
/*  f0cad28:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f0cad2c:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f0cad30:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f0cad34:	46120282 */ 	mul.s	$f10,$f0,$f18
/*  f0cad38:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0cad3c:	e7a400b0 */ 	swc1	$f4,0xb0($sp)
/*  f0cad40:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f0cad44:	c7a800b0 */ 	lwc1	$f8,0xb0($sp)
/*  f0cad48:	4606a180 */ 	add.s	$f6,$f20,$f6
/*  f0cad4c:	0043082a */ 	slt	$at,$v0,$v1
/*  f0cad50:	460a1480 */ 	add.s	$f18,$f2,$f10
/*  f0cad54:	e7a600a8 */ 	swc1	$f6,0xa8($sp)
/*  f0cad58:	46046100 */ 	add.s	$f4,$f12,$f4
/*  f0cad5c:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0cad60:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
/*  f0cad64:	1420fff0 */ 	bnez	$at,.NB0f0cad28
/*  f0cad68:	e7a400ac */ 	swc1	$f4,0xac($sp)
.NB0f0cad6c:
/*  f0cad6c:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f0cad70:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f0cad74:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f0cad78:	46120282 */ 	mul.s	$f10,$f0,$f18
/*  f0cad7c:	e7a400b0 */ 	swc1	$f4,0xb0($sp)
/*  f0cad80:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f0cad84:	4606a180 */ 	add.s	$f6,$f20,$f6
/*  f0cad88:	460a1480 */ 	add.s	$f18,$f2,$f10
/*  f0cad8c:	e7a600a8 */ 	swc1	$f6,0xa8($sp)
/*  f0cad90:	46046100 */ 	add.s	$f4,$f12,$f4
/*  f0cad94:	e7a400ac */ 	swc1	$f4,0xac($sp)
/*  f0cad98:	e7b200a4 */ 	swc1	$f18,0xa4($sp)
.NB0f0cad9c:
/*  f0cad9c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0cada0:	c4207ce0 */ 	lwc1	$f0,0x7ce0($at)
/*  f0cada4:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f0cada8:	c7b200a4 */ 	lwc1	$f18,0xa4($sp)
/*  f0cadac:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f0cadb0:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0cadb4:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f0cadb8:	46009202 */ 	mul.s	$f8,$f18,$f0
/*  f0cadbc:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f0cadc0:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f0cadc4:	e7a80094 */ 	swc1	$f8,0x94($sp)
/*  f0cadc8:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f0cadcc:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f0cadd0:	10000009 */ 	beqz	$zero,.NB0f0cadf8
/*  f0cadd4:	e7a8009c */ 	swc1	$f8,0x9c($sp)
.NB0f0cadd8:
/*  f0cadd8:	c5061a20 */ 	lwc1	$f6,0x1a20($t0)
/*  f0caddc:	e7a600a0 */ 	swc1	$f6,0xa0($sp)
/*  f0cade0:	c5041a2c */ 	lwc1	$f4,0x1a2c($t0)
/*  f0cade4:	e7a40094 */ 	swc1	$f4,0x94($sp)
/*  f0cade8:	c50a1a30 */ 	lwc1	$f10,0x1a30($t0)
/*  f0cadec:	e7aa0098 */ 	swc1	$f10,0x98($sp)
/*  f0cadf0:	c5081a34 */ 	lwc1	$f8,0x1a34($t0)
/*  f0cadf4:	e7a8009c */ 	swc1	$f8,0x9c($sp)
.NB0f0cadf8:
/*  f0cadf8:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f0cadfc:	24010035 */ 	addiu	$at,$zero,0x35
/*  f0cae00:	c5660000 */ 	lwc1	$f6,0x0($t3)
/*  f0cae04:	e7a60070 */ 	swc1	$f6,0x70($sp)
/*  f0cae08:	c5640004 */ 	lwc1	$f4,0x4($t3)
/*  f0cae0c:	e7a40074 */ 	swc1	$f4,0x74($sp)
/*  f0cae10:	c56a0008 */ 	lwc1	$f10,0x8($t3)
/*  f0cae14:	e7aa0078 */ 	swc1	$f10,0x78($sp)
/*  f0cae18:	90a20003 */ 	lbu	$v0,0x3($a1)
/*  f0cae1c:	54410006 */ 	bnel	$v0,$at,.NB0f0cae38
/*  f0cae20:	24010033 */ 	addiu	$at,$zero,0x33
/*  f0cae24:	8d0c1b5c */ 	lw	$t4,0x1b5c($t0)
/*  f0cae28:	8d820004 */ 	lw	$v0,0x4($t4)
/*  f0cae2c:	10000007 */ 	beqz	$zero,.NB0f0cae4c
/*  f0cae30:	2444005c */ 	addiu	$a0,$v0,0x5c
/*  f0cae34:	24010033 */ 	addiu	$at,$zero,0x33
.NB0f0cae38:
/*  f0cae38:	14410004 */ 	bne	$v0,$at,.NB0f0cae4c
/*  f0cae3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cae40:	8d0d1b5c */ 	lw	$t5,0x1b5c($t0)
/*  f0cae44:	8da20004 */ 	lw	$v0,0x4($t5)
/*  f0cae48:	2444005c */ 	addiu	$a0,$v0,0x5c
.NB0f0cae4c:
/*  f0cae4c:	10800026 */ 	beqz	$a0,.NB0f0caee8
/*  f0cae50:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0cae54:	c4207ce4 */ 	lwc1	$f0,0x7ce4($at)
/*  f0cae58:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0cae5c:	c4227ce8 */ 	lwc1	$f2,0x7ce8($at)
/*  f0cae60:	c5080144 */ 	lwc1	$f8,0x144($t0)
/*  f0cae64:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cae68:	44818000 */ 	mtc1	$at,$f16
/*  f0cae6c:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0cae70:	c7a80040 */ 	lwc1	$f8,0x40($sp)
/*  f0cae74:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0cae78:	46103103 */ 	div.s	$f4,$f6,$f16
/*  f0cae7c:	46041281 */ 	sub.s	$f10,$f2,$f4
/*  f0cae80:	c5041a0c */ 	lwc1	$f4,0x1a0c($t0)
/*  f0cae84:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0cae88:	c4880010 */ 	lwc1	$f8,0x10($a0)
/*  f0cae8c:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f0cae90:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f0cae94:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f0cae98:	46043380 */ 	add.s	$f14,$f6,$f4
/*  f0cae9c:	460e003e */ 	c.le.s	$f0,$f14
/*  f0caea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caea4:	45000006 */ 	bc1f	.NB0f0caec0
/*  f0caea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caeac:	46027381 */ 	sub.s	$f14,$f14,$f2
.NB0f0caeb0:
/*  f0caeb0:	460e003e */ 	c.le.s	$f0,$f14
/*  f0caeb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caeb8:	4503fffd */ 	bc1tl	.NB0f0caeb0
/*  f0caebc:	46027381 */ 	sub.s	$f14,$f14,$f2
.NB0f0caec0:
/*  f0caec0:	c4207cec */ 	lwc1	$f0,0x7cec($at)
/*  f0caec4:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0caec8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caecc:	45020007 */ 	bc1fl	.NB0f0caeec
/*  f0caed0:	c7aa00ec */ 	lwc1	$f10,0xec($sp)
/*  f0caed4:	46027380 */ 	add.s	$f14,$f14,$f2
.NB0f0caed8:
/*  f0caed8:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0caedc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caee0:	4503fffd */ 	bc1tl	.NB0f0caed8
/*  f0caee4:	46027380 */ 	add.s	$f14,$f14,$f2
.NB0f0caee8:
/*  f0caee8:	c7aa00ec */ 	lwc1	$f10,0xec($sp)
.NB0f0caeec:
/*  f0caeec:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0caef0:	c4227cf0 */ 	lwc1	$f2,0x7cf0($at)
/*  f0caef4:	46145032 */ 	c.eq.s	$f10,$f20
/*  f0caef8:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0caefc:	44818000 */ 	mtc1	$at,$f16
/*  f0caf00:	45020005 */ 	bc1fl	.NB0f0caf18
/*  f0caf04:	c5080144 */ 	lwc1	$f8,0x144($t0)
/*  f0caf08:	8d0e1a1c */ 	lw	$t6,0x1a1c($t0)
/*  f0caf0c:	51c00034 */ 	beqzl	$t6,.NB0f0cafe0
/*  f0caf10:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0caf14:	c5080144 */ 	lwc1	$f8,0x144($t0)
.NB0f0caf18:
/*  f0caf18:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0caf1c:	c7a800ec */ 	lwc1	$f8,0xec($sp)
/*  f0caf20:	46103103 */ 	div.s	$f4,$f6,$f16
/*  f0caf24:	46041281 */ 	sub.s	$f10,$f2,$f4
/*  f0caf28:	46085301 */ 	sub.s	$f12,$f10,$f8
/*  f0caf2c:	460c103e */ 	c.le.s	$f2,$f12
/*  f0caf30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caf34:	45020004 */ 	bc1fl	.NB0f0caf48
/*  f0caf38:	4614603c */ 	c.lt.s	$f12,$f20
/*  f0caf3c:	10000006 */ 	beqz	$zero,.NB0f0caf58
/*  f0caf40:	46026301 */ 	sub.s	$f12,$f12,$f2
/*  f0caf44:	4614603c */ 	c.lt.s	$f12,$f20
.NB0f0caf48:
/*  f0caf48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caf4c:	45020003 */ 	bc1fl	.NB0f0caf5c
/*  f0caf50:	e7ac0068 */ 	swc1	$f12,0x68($sp)
/*  f0caf54:	46026300 */ 	add.s	$f12,$f12,$f2
.NB0f0caf58:
/*  f0caf58:	e7ac0068 */ 	swc1	$f12,0x68($sp)
.NB0f0caf5c:
/*  f0caf5c:	0c006d52 */ 	jal	cosf
/*  f0caf60:	e7ae006c */ 	swc1	$f14,0x6c($sp)
/*  f0caf64:	c7ac0068 */ 	lwc1	$f12,0x68($sp)
/*  f0caf68:	0c006d55 */ 	jal	sinf
/*  f0caf6c:	e7a00064 */ 	swc1	$f0,0x64($sp)
/*  f0caf70:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0caf74:	c7a60094 */ 	lwc1	$f6,0x94($sp)
/*  f0caf78:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f0caf7c:	c5041a10 */ 	lwc1	$f4,0x1a10($t0)
/*  f0caf80:	c5081a18 */ 	lwc1	$f8,0x1a18($t0)
/*  f0caf84:	8d0f1b5c */ 	lw	$t7,0x1b5c($t0)
/*  f0caf88:	46043300 */ 	add.s	$f12,$f6,$f4
/*  f0caf8c:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*  f0caf90:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0caf94:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f0caf98:	46046282 */ 	mul.s	$f10,$f12,$f4
/*  f0caf9c:	c7ae006c */ 	lwc1	$f14,0x6c($sp)
/*  f0cafa0:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0cafa4:	46009182 */ 	mul.s	$f6,$f18,$f0
/*  f0cafa8:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f0cafac:	c5e80008 */ 	lwc1	$f8,0x8($t7)
/*  f0cafb0:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f0cafb4:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f0cafb8:	c7aa00dc */ 	lwc1	$f10,0xdc($sp)
/*  f0cafbc:	46006102 */ 	mul.s	$f4,$f12,$f0
/*  f0cafc0:	e7a60070 */ 	swc1	$f6,0x70($sp)
/*  f0cafc4:	8d181b5c */ 	lw	$t8,0x1b5c($t0)
/*  f0cafc8:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0cafcc:	c7080010 */ 	lwc1	$f8,0x10($t8)
/*  f0cafd0:	46043281 */ 	sub.s	$f10,$f6,$f4
/*  f0cafd4:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f0cafd8:	e7a60078 */ 	swc1	$f6,0x78($sp)
/*  f0cafdc:	24190001 */ 	addiu	$t9,$zero,0x1
.NB0f0cafe0:
/*  f0cafe0:	3c018007 */ 	lui	$at,0x8007
/*  f0cafe4:	ac393540 */ 	sw	$t9,0x3540($at)
/*  f0cafe8:	8d091b5c */ 	lw	$t1,0x1b5c($t0)
/*  f0cafec:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f0caff0:	3c02800a */ 	lui	$v0,0x800a
/*  f0caff4:	c5240008 */ 	lwc1	$f4,0x8($t1)
/*  f0caff8:	24422658 */ 	addiu	$v0,$v0,0x2658
/*  f0caffc:	44067000 */ 	mfc1	$a2,$f14
/*  f0cb000:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0cb004:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0cb008:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0cb00c:	8fa700f0 */ 	lw	$a3,0xf0($sp)
/*  f0cb010:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f0cb014:	8d0a1b5c */ 	lw	$t2,0x1b5c($t0)
/*  f0cb018:	c546000c */ 	lwc1	$f6,0xc($t2)
/*  f0cb01c:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f0cb020:	c7a60078 */ 	lwc1	$f6,0x78($sp)
/*  f0cb024:	e44a0004 */ 	swc1	$f10,0x4($v0)
/*  f0cb028:	8d0b1b5c */ 	lw	$t3,0x1b5c($t0)
/*  f0cb02c:	c5680010 */ 	lwc1	$f8,0x10($t3)
/*  f0cb030:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0cb034:	e4440008 */ 	swc1	$f4,0x8($v0)
/*  f0cb038:	8d0c1b5c */ 	lw	$t4,0x1b5c($t0)
/*  f0cb03c:	0fc1c3b6 */ 	jal	func0f072144
/*  f0cb040:	8d840004 */ 	lw	$a0,0x4($t4)
/*  f0cb044:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cb048:	10410005 */ 	beq	$v0,$at,.NB0f0cb060
/*  f0cb04c:	afa200e4 */ 	sw	$v0,0xe4($sp)
/*  f0cb050:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0cb054:	3c01800a */ 	lui	$at,0x800a
/*  f0cb058:	8dae1b5c */ 	lw	$t6,0x1b5c($t5)
/*  f0cb05c:	ac2e2650 */ 	sw	$t6,0x2650($at)
.NB0f0cb060:
/*  f0cb060:	8e0f0284 */ 	lw	$t7,0x284($s0)
.NB0f0cb064:
/*  f0cb064:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cb068:	0fc18cfb */ 	jal	propSetPerimEnabled
/*  f0cb06c:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f0cb070:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0cb074:	c4227d04 */ 	lwc1	$f2,0x7d04($at)
/*  f0cb078:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0cb07c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cb080:	44818000 */ 	mtc1	$at,$f16
/*  f0cb084:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cb088:	57010051 */ 	bnel	$t8,$at,.NB0f0cb1d0
/*  f0cb08c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0cb090:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f0cb094:	3c01800a */ 	lui	$at,0x800a
/*  f0cb098:	ac202650 */ 	sw	$zero,0x2650($at)
/*  f0cb09c:	1320004b */ 	beqz	$t9,.NB0f0cb1cc
/*  f0cb0a0:	c7a800ec */ 	lwc1	$f8,0xec($sp)
/*  f0cb0a4:	46104182 */ 	mul.s	$f6,$f8,$f16
/*  f0cb0a8:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cb0ac:	c50a0144 */ 	lwc1	$f10,0x144($t0)
/*  f0cb0b0:	46023103 */ 	div.s	$f4,$f6,$f2
/*  f0cb0b4:	46045000 */ 	add.s	$f0,$f10,$f4
/*  f0cb0b8:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0cb0bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb0c0:	45020007 */ 	bc1fl	.NB0f0cb0e0
/*  f0cb0c4:	4600803e */ 	c.le.s	$f16,$f0
/*  f0cb0c8:	46100000 */ 	add.s	$f0,$f0,$f16
.NB0f0cb0cc:
/*  f0cb0cc:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0cb0d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb0d4:	4503fffd */ 	bc1tl	.NB0f0cb0cc
/*  f0cb0d8:	46100000 */ 	add.s	$f0,$f0,$f16
/*  f0cb0dc:	4600803e */ 	c.le.s	$f16,$f0
.NB0f0cb0e0:
/*  f0cb0e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb0e4:	45020007 */ 	bc1fl	.NB0f0cb104
/*  f0cb0e8:	e5000144 */ 	swc1	$f0,0x144($t0)
/*  f0cb0ec:	46100001 */ 	sub.s	$f0,$f0,$f16
.NB0f0cb0f0:
/*  f0cb0f0:	4600803e */ 	c.le.s	$f16,$f0
/*  f0cb0f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb0f8:	4503fffd */ 	bc1tl	.NB0f0cb0f0
/*  f0cb0fc:	46100001 */ 	sub.s	$f0,$f0,$f16
/*  f0cb100:	e5000144 */ 	swc1	$f0,0x144($t0)
.NB0f0cb104:
/*  f0cb104:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0cb108:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0cb10c:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0cb110:	e5480008 */ 	swc1	$f8,0x8($t2)
/*  f0cb114:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0cb118:	c7a600d8 */ 	lwc1	$f6,0xd8($sp)
/*  f0cb11c:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f0cb120:	e586000c */ 	swc1	$f6,0xc($t4)
/*  f0cb124:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0cb128:	c7aa00dc */ 	lwc1	$f10,0xdc($sp)
/*  f0cb12c:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f0cb130:	e5ca0010 */ 	swc1	$f10,0x10($t6)
/*  f0cb134:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f0cb138:	51e0000a */ 	beqzl	$t7,.NB0f0cb164
/*  f0cb13c:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cb140:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cb144:	0fc193ab */ 	jal	propDeregisterRooms
/*  f0cb148:	8f0400bc */ 	lw	$a0,0xbc($t8)
/*  f0cb14c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cb150:	27a400c4 */ 	addiu	$a0,$sp,0xc4
/*  f0cb154:	8f2500bc */ 	lw	$a1,0xbc($t9)
/*  f0cb158:	0fc19283 */ 	jal	roomsCopy
/*  f0cb15c:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0cb160:	8e080284 */ 	lw	$t0,0x284($s0)
.NB0f0cb164:
/*  f0cb164:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f0cb168:	8d091a1c */ 	lw	$t1,0x1a1c($t0)
/*  f0cb16c:	51200018 */ 	beqzl	$t1,.NB0f0cb1d0
/*  f0cb170:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0cb174:	e5041a20 */ 	swc1	$f4,0x1a20($t0)
/*  f0cb178:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0cb17c:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f0cb180:	e5481a2c */ 	swc1	$f8,0x1a2c($t2)
/*  f0cb184:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0cb188:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f0cb18c:	e5661a30 */ 	swc1	$f6,0x1a30($t3)
/*  f0cb190:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0cb194:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f0cb198:	e58a1a34 */ 	swc1	$f10,0x1a34($t4)
/*  f0cb19c:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0cb1a0:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f0cb1a4:	e5a41a38 */ 	swc1	$f4,0x1a38($t5)
/*  f0cb1a8:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0cb1ac:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f0cb1b0:	e5c81a3c */ 	swc1	$f8,0x1a3c($t6)
/*  f0cb1b4:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0cb1b8:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f0cb1bc:	e5e61a40 */ 	swc1	$f6,0x1a40($t7)
/*  f0cb1c0:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cb1c4:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f0cb1c8:	e70a1a44 */ 	swc1	$f10,0x1a44($t8)
.NB0f0cb1cc:
/*  f0cb1cc:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f0cb1d0:
/*  f0cb1d0:	8fa200e4 */ 	lw	$v0,0xe4($sp)
/*  f0cb1d4:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0cb1d8:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0cb1dc:	03e00008 */ 	jr	$ra
/*  f0cb1e0:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
);
#endif

bool bgrabCalculateNewPositiontWithPush(struct coord *delta, f32 angle, bool arg2)
{
	s32 result = bgrabCalculateNewPosition(delta, angle, arg2);

	if (result != CDRESULT_NOCOLLISION) {
		struct prop *obstacle = cdGetObstacle();

		if (obstacle && g_Vars.lvupdate240 > 0) {
			if (obstacle->type == PROPTYPE_CHR) {
				// empty
			} else if (obstacle->type == PROPTYPE_PLAYER) {
				// empty
			} else if (obstacle->type == PROPTYPE_OBJ) {
				struct defaultobj *obj = obstacle->obj;

				if ((obj->hidden & OBJHFLAG_MOUNTED) == 0
						&& (obj->hidden & OBJHFLAG_GRABBED) == 0
						&& (obj->flags3 & OBJFLAG3_PUSHABLE)) {
					bool canpush = true;

					g_Vars.currentplayer->speedmaxtime60 = 0;

					if ((obj->hidden & OBJHFLAG_AIRBORNE)
							&& (obj->projectile->flags & PROJECTILEFLAG_00001000)) {
						canpush = false;
					}

					if (canpush) {
						bgrab0f0ccbf0(delta, angle, obj);

						if ((obj->hidden & OBJHFLAG_AIRBORNE)
								&& (obj->projectile->flags & PROJECTILEFLAG_00000800)) {
							s32 someint;
							bool somebool = false;
							someint = func0f073c6c(obj, &somebool);

							if ((obj->hidden & OBJHFLAG_AIRBORNE)) {
								obj->projectile->flags |= PROJECTILEFLAG_00001000;

								if (someint) {
									obj->projectile->flags |= PROJECTILEFLAG_00002000;
								} else {
									obj->projectile->flags &= ~PROJECTILEFLAG_00002000;
								}
							}

							if (someint) {
								result = bgrabCalculateNewPosition(delta, angle, arg2);
							}
						}
					}
				}
			}
		}
	}

	return result;
}

bool bgrab0f0cdb04(f32 angle, bool arg2)
{
	struct coord coord = {0, 0, 0};
	bool result;

	g_Vars.currentplayer->grabbeddoextra = true;
	result = bgrabCalculateNewPositiontWithPush(&coord, angle, arg2);
	g_Vars.currentplayer->grabbeddoextra = false;

	return result;
}

bool bgrab0f0cdb68(f32 angle)
{
	struct coord spa4;
	struct coord sp98;
	struct coord sp8c;
	struct coord sp80;
	f32 sp7c;
	f32 sp78;
	f32 f2;
	f32 f20;
	f32 f22;
	s32 i;
	f32 f0;
	f32 sp60 = -1.0f;
	struct coord sp54;
	f32 f12;
	f32 width;
	f32 ymax;
	f32 ymin;

#if VERSION >= VERSION_NTSC_1_0
	cd00024e4c(&spa4, &sp98, 678, "bondgrab.c");
#else
	cd00024e4c(&spa4, &sp98, 674, "bondgrab.c");
#endif

	sp7c = sp98.f[0] - spa4.f[0];
	sp78 = sp98.f[2] - spa4.f[2];

	if (sp7c == 0.0f && sp78 == 0.0f) {
		sp78 = 1.0f;
	} else {
		f12 = 1.0f / sqrtf(sp7c * sp7c + sp78 * sp78);
		sp7c = sp7c * f12;
		sp78 = sp78 * f12;
	}

	f20 = sp78;
	f22 = -sp7c;

	if ((f20 * (g_Vars.currentplayer->prop->pos.x - spa4.f[0]) + f22 * (g_Vars.currentplayer->prop->pos.z - spa4.f[2])) < 0.0f) {
		f20 = -f20;
		f22 = -f22;
	}

	if (var8005f034) {
		for (i = 0; i < var8009a918.header.numvertices; i++) {
			f0 = (var8009a918.vertices[i][0] - spa4.f[0]) * f20 + (var8009a918.vertices[i][1] - spa4.f[2]) * f22;

			if (f0 < 0.0f) {
				f0 = -f0;

				if (f0 > sp60) {
					sp60 = f0;
				}
			}
		}
	} else {
		if (cd00025364(&sp8c, &sp80)) {
			f32 f0 = (sp8c.f[0] - spa4.f[0]) * f20 + f22 * (sp8c.f[2] - spa4.f[2]);
			f32 f16 = (sp80.f[0] - spa4.f[0]) * f20 + f22 * (sp80.f[2] - spa4.f[2]);

			if (f16 < f0) {
				f0 = f16;
			}

			if (f0 < 0.0f) {
				sp60 = -f0;
			}
		} else if (var80070e80 != 0) {
			if (g_Vars.currentplayer->grabbedprop->type == PROPTYPE_OBJ) {
				if (g_Vars.currentplayer->grabbedprop->obj->flags3 & OBJFLAG3_GEOTYPE3) {
					propObjGetBbox(g_Vars.currentplayer->grabbedprop, &width, &ymax, &ymin);

					f0 = (var8009de78.f[0] - spa4.f[0]) * f20 + (var8009de78.f[2] - spa4.f[2]) * f22;
					f0 -= width;

					if (f0 < 0.0f) {
						sp60 = -f0;
					}
				}
			}
		}
	}

	f2 = sinf(angle) * 400.0f;

	if (f2 < 0.0f) {
		f2 = -f2;
	}

	if (f2 < sp60) {
		sp60 = f2;
	}

	if (sp60 >= 0.0f) {
		sp54.x = sp60 * f20 * 1.01f;
		sp54.y = 0.0f;
		sp54.z = sp60 * f22 * 1.01f;

		bgrab0f0ce0bc(&sp54);

		return bgrab0f0cdb04(angle, true);
	}

	return false;
}

void bgrab0f0cdef0(void)
{
	if (g_Vars.lvupdate240 > 0) {
		f32 angle = g_Vars.currentplayer->speedtheta * g_Vars.lvupdate240freal * 0.017450513318181f * 3.5f;

		if (bgrab0f0cdb04(angle, true) == 0) {
			bgrab0f0cdb68(angle);
		}
	}
}

bool bgrab0f0cdf64(struct coord *delta, struct coord *arg1, struct coord *arg2)
{
	bool result = bgrabCalculateNewPositiontWithPush(delta, 0, true);

	if (!result) {
#if VERSION >= VERSION_NTSC_1_0
		cd00024e4c(arg1, arg2, 815, "bondgrab.c");
#else
		cd00024e4c(arg1, arg2, 811, "bondgrab.c");
#endif
	}

	return result;
}

s32 bgrab0f0cdfbc(struct coord *delta, struct coord *arg1, struct coord *arg2)
{
	if (arg1->f[0] != arg2->f[0] || arg1->f[2] != arg2->f[2]) {
		f32 tmp;
		struct coord sp30;
		struct coord sp24;

		sp30.x = arg2->x - arg1->x;
		sp30.z = arg2->z - arg1->z;

		tmp = 1.0f / sqrtf(sp30.f[0] * sp30.f[0] + sp30.f[2] * sp30.f[2]);

		sp30.x *= tmp;
		sp30.z *= tmp;

		tmp = delta->f[0] * sp30.f[0] + delta->f[2] * sp30.f[2];

		sp24.x = sp30.x * tmp;
		sp24.y = 0;
		sp24.z = sp30.z * tmp;

		return bgrabCalculateNewPositiontWithPush(&sp24, 0, true);
	}

	return -1;
}

void bgrab0f0ce0bc(struct coord *arg0)
{
	struct coord a;
	struct coord b;
	s32 value = bgrab0f0cdf64(arg0, &a, &b);

	if (value == 0) {
		value = bgrab0f0cdfbc(arg0, &a, &b);

		if (value <= 0) {
			value = 1;
		}
	}

	if (value) {
		// empty
	}
}

void bgrabUpdatePrevPos(void)
{
	g_Vars.currentplayer->bondprevpos.x = g_Vars.currentplayer->prop->pos.x;
	g_Vars.currentplayer->bondprevpos.y = g_Vars.currentplayer->prop->pos.y;
	g_Vars.currentplayer->bondprevpos.z = g_Vars.currentplayer->prop->pos.z;

	g_Vars.currentplayer->bondprevtheta = g_Vars.currentplayer->vv_theta;

	g_Vars.currentplayer->grabbedprevpos.x = g_Vars.currentplayer->grabbedprop->pos.x;
	g_Vars.currentplayer->grabbedprevpos.y = g_Vars.currentplayer->grabbedprop->pos.y;
	g_Vars.currentplayer->grabbedprevpos.z = g_Vars.currentplayer->grabbedprop->pos.z;
}

void bgrab0f0ce178(void)
{
	func0f069c70(g_Vars.currentplayer->grabbedprop->obj, 0, 1);
}

void bgrabUpdateVertical(void)
{
	f32 stack;
	s32 i;
	f32 tmp;
	s32 inlift;
	struct prop *lift = NULL;
	f32 dist;
	f32 f14;
	f32 fVar3;
	f32 f0;

	f14 = cdFindGroundY(&g_Vars.currentplayer->prop->pos,
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
				g_Vars.currentplayer->sumground = g_Vars.currentplayer->vv_manground / (PAL ? 0.054400026798248f : 0.045499980449677f);
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
	fVar3 = g_Vars.currentplayer->vv_manground / (PAL ? 0.054400026798248f : 0.045499980449677f);

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		fVar3 = (PAL ? 0.94559997320175f : 0.9545f) * fVar3 + g_Vars.currentplayer->vv_ground;
	}

	f0 = g_Vars.currentplayer->vv_height;

	if (f0 < 30) {
		f0 = 30;
	}

	tmp = fVar3 * (PAL ? 0.054400026798248f : 0.045499980449677f) + f0 - g_Vars.currentplayer->prop->pos.y;

#if VERSION >= VERSION_NTSC_1_0
	if (g_Vars.currentplayer->prop->pos.y + tmp < g_Vars.currentplayer->vv_ground + 10.0f) {
		tmp = g_Vars.currentplayer->vv_ground + 10.0f - g_Vars.currentplayer->prop->pos.y;
	}
#endif

	if (bgrabTryMoveUpwards(tmp)) {
		g_Vars.currentplayer->sumground = fVar3;
		g_Vars.currentplayer->vv_manground = fVar3 * (PAL ? 0.054400026798248f : 0.045499980449677f);
	}

	if ((g_Vars.currentplayer->floorflags & TILEFLAG_DIE) &&
			g_Vars.currentplayer->vv_manground - 20.0f < g_Vars.currentplayer->vv_ground) {
		playerDie(true);
	}
}

void bgrabHandleActivate(void)
{
	if (currentPlayerTryMountHoverbike(g_Vars.currentplayer->grabbedprop)) {
		g_Vars.currentplayer->bondactivateorreload = 0;
	} else {
		g_Vars.currentplayer->bondactivateorreload = 0;
		bmoveSetMode(MOVEMODE_WALK);
	}
}

void bgrabUpdateSpeedSideways(f32 targetspeed, f32 accelspeed, s32 mult)
{
	if (targetspeed < g_Vars.currentplayer->speedstrafe) {
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

void bgrabUpdateSpeedForwards(f32 target, f32 speed)
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

void bgrabApplyMoveData(struct movedata *data)
{
	// Sideways
	if (data->digitalstepleft) {
		bgrabUpdateSpeedSideways(-1, 0.2f / 3.0f, data->digitalstepleft);
	} else if (data->digitalstepright) {
		bgrabUpdateSpeedSideways(1, 0.2f / 3.0f, data->digitalstepright);
	} else if (data->unk14 == 0) {
		bgrabUpdateSpeedSideways(0, 0.2f / 3.0f, g_Vars.lvupdate240_60);
	}

	if (data->unk14) {
		bgrabUpdateSpeedSideways(data->analogstrafe * 0.014285714365542f, 0.2f / 3.0f, g_Vars.lvupdate240_60);
	}

	// Forward/back
	if (data->digitalstepforward) {
		bgrabUpdateSpeedForwards(1, 0.2f / 3.0f);
		g_Vars.currentplayer->speedmaxtime60 += g_Vars.lvupdate240_60;
	} else if (data->digitalstepback) {
		bgrabUpdateSpeedForwards(-1, 0.2f / 3.0f);
	} else if (data->canlookahead == false) {
		bgrabUpdateSpeedForwards(0, 0.2f / 3.0f);
	}

	if (data->canlookahead) {
		bgrabUpdateSpeedForwards(data->analogwalk * 0.014285714365542f, 0.2f / 3.0f);

		if (data->analogwalk > 60) {
			g_Vars.currentplayer->speedmaxtime60 += g_Vars.lvupdate240_60;
		} else {
			g_Vars.currentplayer->speedmaxtime60 = 0;
		}
	}

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

	if (data->canlookahead == false && data->digitalstepforward == false) {
		g_Vars.currentplayer->speedmaxtime60 = 0;
	}
}

void bgrabUpdateSpeedTheta(void)
{
	f32 mult = (PAL ? 0.97519999742508f : 0.98470002412796f);
	f32 speedtheta = g_Vars.currentplayer->speedtheta * 0.75f;
	s32 i;

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		g_Vars.currentplayer->bondgrabthetaspeedsum = g_Vars.currentplayer->bondgrabthetaspeedsum * mult + speedtheta;
	}

	g_Vars.currentplayer->speedtheta = g_Vars.currentplayer->bondgrabthetaspeedsum * (PAL ? 0.024800002574921f : 0.01529997587204f);
}

void bgrab0f0ce924(void)
{
	f32 mult;
	f32 sp88;
	f32 sp84;
	f32 sp80;
	struct coord sp74 = {0, 0, 0};
	f32 sp70;
	f32 sp6c;
	f32 speedforwards;
	f32 speedsideways;
	f32 speedtheta;
	f32 maxspeed;
	f32 xdelta;
	f32 zdelta;
	f32 sp50;
	f32 sp4c;
	f32 sp48;
	f32 sp44;
	f32 sp40;
	f32 sp3c;
	f32 sp38;
	f32 breathing;

	if (g_Vars.lvupdate240 > 0) {
		bmove0f0cba88(&sp70, &sp6c, &g_Vars.currentplayer->bondshotspeed, g_Vars.currentplayer->vv_sintheta, g_Vars.currentplayer->vv_costheta);

		g_Vars.currentplayer->speedforwards += sp70;
		g_Vars.currentplayer->speedsideways += sp6c;

		mult = var80075c00[1].unk0c * 0.5f * g_Vars.lvupdate240freal;
		sp88 = mult * g_Vars.currentplayer->speedsideways;

		speedsideways = g_Vars.currentplayer->speedsideways * 0.8f;
		speedforwards = g_Vars.currentplayer->speedforwards;
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

		if (maxspeed >= 0.75f) {
			g_Vars.currentplayer->bondbreathing += (maxspeed - 0.75f) * g_Vars.lvupdate240freal / 900.0f;
		} else {
			g_Vars.currentplayer->bondbreathing -= (0.75f - maxspeed) * g_Vars.lvupdate240freal / 2700.0f;
		}

		if (g_Vars.currentplayer->bondbreathing < 0.0f) {
			g_Vars.currentplayer->bondbreathing = 0.0f;
		} else if (g_Vars.currentplayer->bondbreathing > 1.0f) {
			g_Vars.currentplayer->bondbreathing = 1.0f;
		}

		bmove0f0cc654(maxspeed, g_Vars.currentplayer->speedforwards, sp88);

		g_Vars.currentplayer->gunspeed = maxspeed;

		sp84 = g_Vars.currentplayer->headpos.x;
		sp80 = g_Vars.currentplayer->headpos.z;

#if VERSION >= VERSION_NTSC_1_0
		if (cheatIsActive(CHEAT_SMALLJO)) {
			sp84 *= 0.4f;
			sp80 *= 0.4f;
		}
#endif

		sp74.x += (sp80 * g_Vars.currentplayer->bond2.unk00.f[0] - sp84 * g_Vars.currentplayer->bond2.unk00.f[2]) * g_Vars.lvupdate240freal;
		sp74.z += (sp80 * g_Vars.currentplayer->bond2.unk00.f[2] + sp84 * g_Vars.currentplayer->bond2.unk00.f[0]) * g_Vars.lvupdate240freal;

		bmoveUpdateMoveInitSpeed(&sp74);

		if (debugIsTurboModeEnabled()) {
			sp74.x += (g_Vars.currentplayer->bond2.unk00.f[0] * g_Vars.currentplayer->speedforwards - (g_Vars.currentplayer->bond2.unk00.f[2] * g_Vars.currentplayer->speedsideways)) * g_Vars.lvupdate240freal * 10.0f;
			sp74.z += (g_Vars.currentplayer->bond2.unk00.f[2] * g_Vars.currentplayer->speedforwards + (g_Vars.currentplayer->bond2.unk00.f[0] * g_Vars.currentplayer->speedsideways)) * g_Vars.lvupdate240freal * 10.0f;
		}

		bgrab0f0ce0bc(&sp74);

		xdelta = g_Vars.currentplayer->prop->pos.f[0] - g_Vars.currentplayer->bondprevpos.f[0];
		zdelta = g_Vars.currentplayer->prop->pos.f[2] - g_Vars.currentplayer->bondprevpos.f[2];

		sp50 = -xdelta * g_Vars.currentplayer->bond2.unk00.f[2] + zdelta * g_Vars.currentplayer->bond2.unk00.f[0];
		sp4c = xdelta * g_Vars.currentplayer->bond2.unk00.f[0] + zdelta * g_Vars.currentplayer->bond2.unk00.f[2];
		sp48 = -sp74.f[0] * g_Vars.currentplayer->bond2.unk00.f[2] + sp74.f[2] * g_Vars.currentplayer->bond2.unk00.f[0];
		sp44 = sp74.f[0] * g_Vars.currentplayer->bond2.unk00.f[0] + sp74.f[2] * g_Vars.currentplayer->bond2.unk00.f[2];

		if (sp48 != 0.0f) {
			if (g_Vars.currentplayer->speedstrafe * sp48 > 0.0f) {
				sp50 /= sp48;

				if (sp50 <= 0.0f) {
					g_Vars.currentplayer->speedstrafe = 0.0f;
				} else if (sp50 < 1.0f) {
					g_Vars.currentplayer->speedstrafe *= sp50;
				}
			}
		}

		if (sp44 != 0.0f) {
			if (g_Vars.currentplayer->speedgo * sp44 > 0.0f) {
				sp4c /= sp44;

				if (sp4c <= 0.0f) {
					g_Vars.currentplayer->speedgo = 0.0f;
				} else if (sp4c < 1.0f) {
					g_Vars.currentplayer->speedgo *= sp4c;
				}
			}
		}

		sp40 = g_Vars.currentplayer->speedtheta;
		sp3c = g_Vars.currentplayer->speedverta / 0.7f;
		sp38 = g_Vars.currentplayer->gunspeed;

		breathing = bheadGetBreathingValue();

		if (sp3c > 1.0f) {
			sp3c = 1.0f;
		} else if (sp3c < -1.0f) {
			sp3c = -1.0f;
		}

		if (g_Vars.currentplayer->headanim == 1) {
			breathing *= 1.2f;
		}

		bgun0f09d8dc(breathing, sp38, sp3c, sp40, 0.0f);
		bgunSetAdjustPos(g_Vars.currentplayer->vv_verta360 * 0.017450513f);
	}
}

void bgrabTick(void)
{
	bgrabUpdatePrevPos();
	bgrab0f0cdef0();
	bmoveUpdateVerta();
	bgrab0f0ce924();
	bgrab0f0ce178();
	bgrabUpdateVertical();

#if VERSION >= VERSION_NTSC_1_0
	{
		s32 i;

		for (i = 0; g_Vars.currentplayer->prop->rooms[i] != -1; i++) {
			if (g_Vars.currentplayer->prop->rooms[i] == g_Vars.currentplayer->floorroom) {
				propDeregisterRooms(g_Vars.currentplayer->prop);
				g_Vars.currentplayer->prop->rooms[0] = g_Vars.currentplayer->floorroom;
				g_Vars.currentplayer->prop->rooms[1] = -1;
				break;
			}
		}
	}
#endif

	{
		struct defaultobj *obj = g_Vars.currentplayer->grabbedprop->obj;
		struct hov *hov = NULL;

		if (obj->type == OBJTYPE_HOVERPROP) {
			struct hoverpropobj *hoverprop = (struct hoverpropobj *)g_Vars.currentplayer->grabbedprop->obj;
			hov = &hoverprop->hov;
		} else if (obj->type == OBJTYPE_HOVERBIKE) {
			struct hoverbikeobj *hoverbike = (struct hoverbikeobj *)g_Vars.currentplayer->grabbedprop->obj;
			hov = &hoverbike->hov;
		}

		if (hov) {
			func0f0714b8(obj, hov);
		}

		bmove0f0cb8c4(g_Vars.currentplayer);
		objectiveCheckRoomEntered(g_Vars.currentplayer->prop->rooms[0]);
		bmove0f0cc19c(&g_Vars.currentplayer->prop->pos);
		playerUpdatePerimInfo();
		doorsCheckAutomatic();

		if (g_Vars.currentplayer->grabbedprop) {
			// Determine if the grabbed prop should be force released
			f32 ydiff = g_Vars.currentplayer->grabbedprop->pos.y
				- objGetHov04(g_Vars.currentplayer->grabbedprop->obj)
				- g_Vars.currentplayer->vv_manground;

			struct prop *grabbedprop = g_Vars.currentplayer->grabbedprop;

			propSetPerimEnabled(g_Vars.currentplayer->prop, false);
			propSetPerimEnabled(grabbedprop, false);

			if (g_Vars.currentplayer->vv_ground <= -30000
					|| ydiff < -100 || ydiff > 100
					|| g_Vars.currentplayer->vv_ground < g_Vars.currentplayer->vv_manground - 50
					|| !cdHasLineOfSight(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms,
						&g_Vars.currentplayer->grabbedprop->pos, g_Vars.currentplayer->grabbedprop->rooms, CDTYPE_ALL, 12)) {
				bmoveSetMode(MOVEMODE_WALK);
			}

			propSetPerimEnabled(g_Vars.currentplayer->prop, true);
			propSetPerimEnabled(grabbedprop, true);
		}
	}
}
