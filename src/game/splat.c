#include <ultra64.h>
#include "constants.h"
#include "game/smoke/smoke.h"
#include "game/bg.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

u32 var8007f8a0 = 0x3e19999a;
u32 var8007f8a4 = 0x40400000;
f32 var8007f8a8 = 12;
u32 var8007f8ac = 0x00000008;
u32 var8007f8b0 = 0x43340000;
u32 var8007f8b4 = 0x40a00000;
u32 var8007f8b8 = 0x42480000;

void splatTick(struct prop *prop)
{
	struct chrdata *chr = prop->chr;
	struct chrdata *attacker = chr->lastattacker;
	s32 race;

	if (chr->unk32c_19 || (chr->chrflags & CHRCFLAG_HIDDEN) || chr->bulletstaken == 0) {
		return;
	}

	race = CHRRACE(chr);

	if (race != RACE_DRCAROLL && race != RACE_ROBOT) {
		u8 isskedar = false;

		if (race == RACE_SKEDAR || chr->bodynum == BODY_MRBLONDE) {
			isskedar = true;
		}

		osSyncPrintf("Splat Tick - P=%x, B=%d, T=%d, S=%d, W=%d, D=%d, H=%d\n");

		if (chr->actiontype == ACT_DEAD || chr->actiontype == ACT_DIE) {
			u32 stack;
			f32 thudframe = -1.0f;

			if (chr->actiontype == ACT_DIE) {
				if (chr->act_die.thudframe2 != -1) {
					thudframe = chr->act_die.thudframe2;
				} else if (chr->act_die.thudframe1 != -1) {
					thudframe = chr->act_die.thudframe1;
				}
			}

			if (thudframe != -1.0f && modelGetCurAnimFrame(chr->model) < thudframe) {
				osSyncPrintf("SPLAT : Not Dead Enough %s%s%f", "", "", modelGetCurAnimFrame(chr->model));
			} else if (chr->tickssincesplat > PALDOWN(30) && chr->deaddropsplatsadded < 6) {
				chr->deaddropsplatsadded += func0f148f18(1, 1.1f, prop, NULL, 0, 0, isskedar, 1, PALDOWN(150), attacker, random() & 8);
			}
		} else {
			u32 value = chr->bulletstaken * chr->tickssincesplat;

			if (value > PALDOWN(240)) {
				f32 dist = coordsGetDistance(&chr->lastdroppos, &prop->pos);
				s32 addmore = false;

				if (dist > 40) {
					addmore = true;
					chr->splatsdroppedhe = 0;
				} else if (chr->splatsdroppedhe < 8) {
					addmore = true;
					chr->splatsdroppedhe++;
				}

				if (addmore) {
					chr->woundedsplatsadded += func0f148f18(1, 0.3f, prop, NULL, 0, 0, isskedar, 2, PALDOWN(80), attacker, 0);
				}
			}

			if (chr->woundedsplatsadded >= 40) {
				func0f141704(prop);
				chr->woundedsplatsadded--;
			}

			chr->deaddropsplatsadded = 0;
		}
	}

	chr->tickssincesplat += g_Vars.lvupdate240_60;
}

void func0f148e54(struct prop *prop, struct splat *arg1, struct coord *arg2, struct coord *arg3, s32 arg4, s32 arg5, struct chrdata *arg6)
{
	struct chrdata *chr = prop->chr;

	if (chr->bulletstaken < 7) {
		chr->bulletstaken++;
	}

	if (arg5 == 0) {
		u32 rand = random() % 3;

		if (rand) {
			chr->stdsplatsadded += func0f148f18(rand, 0.8f, prop, arg1, arg2, arg3, arg4, arg5, PALDOWN(50), arg6, 0);
		}
	}
}

s32 func0f148f18(s32 qty, f32 arg1, struct prop *prop, struct splat *arg3, struct coord *arg4, struct coord *arg5, s32 arg6, s32 arg7, s32 arg8, struct chrdata *arg9, s32 arg10)
{
	s32 i;
	s32 j;
	struct splat stacksplat;
	struct splat *splat = arg7 == 0 ? arg3 : &stacksplat;
	f32 spfc[3];
	f32 spf0[3];
	f32 spe4[3];
	Mtxf spa4;
	s32 numdropped = 0;
	f32 dist;

	if (arg7 == 0) {
		dist = coordsGetDistance(&splat->unk01c, arg5);

		for (i = 0; i < 3; i++) {
			spfc[i] = ((f32 *)&splat->unk028)[i];
			spf0[i] = ((f32 *)&splat->unk00c)[i];
			((f32 *)&splat->unk01c)[i] = ((f32 *)arg5)[i];
			((f32 *)&splat->unk000)[i] = ((f32 *)arg4)[i];
		}
	} else {
		f32 extraheight;

		if (prop->type == PROPTYPE_CHR) {
			extraheight = 50;
		} else {
			extraheight = 0;
		}

		dist = 0.7f;

		splat->unk028.x = 0;  spfc[0] = 0;
		splat->unk028.y = -1; spfc[1] = -1;
		splat->unk028.z = 0;  spfc[2] = 0;

		splat->unk00c.x = 0;  spf0[0] = 0;
		splat->unk00c.y = -1; spf0[1] = -1;
		splat->unk00c.z = 0;  spf0[2] = 0;

		splat->unk01c.x = prop->pos.x;
		splat->unk01c.y = prop->pos.y + extraheight;
		splat->unk01c.z = prop->pos.z;

		splat->unk000.x = prop->pos.x;
		splat->unk000.y = prop->pos.y + extraheight;
		splat->unk000.z = prop->pos.z;
	}

	for (i = 0; i < qty; i++) {
		for (j = 0; j < 3; j++) {
			f32 rand = random() * (1.0f / U32_MAX);
			spe4[j] = (rand * var8007f8a8 + rand * var8007f8a8 - var8007f8a8) * 0.017453292384744f;
		}

		func0001648c((struct coord *)spe4, &spa4);
		func00015b14(&spa4, (struct coord *)spfc, &splat->unk028);
		func00015b14(&spa4, (struct coord *)spf0, &splat->unk00c);
		func0f177164(&splat->unk028, &splat->unk028, 403, "splat.c");
		func0f177164(&splat->unk00c, &splat->unk00c, 404, "splat.c");

		if (func0f149274(arg1, prop, splat, dist, arg6, arg7, arg8, arg9, arg10)) {
			numdropped++;
		}
	}

	if (numdropped) {
		struct chrdata *chr = prop->chr;

		chr->tickssincesplat = 0;
		chr->lastdroppos.x = prop->pos.x;
		chr->lastdroppos.y = prop->pos.y;
		chr->lastdroppos.z = prop->pos.z;
	}

	return numdropped;
}

const char var7f1b5fe0[] = "Splat : Out of range\n";
const char var7f1b5ff8[] = "Splat_ResetChr : Reset One Char : chrdata = %x\n";

GLOBAL_ASM(
glabel func0f149274
.late_rodata
glabel var7f1b6030
.word 0x497423f0
.text
/*  f149274:	27bdfa18 */ 	addiu	$sp,$sp,-1512
/*  f149278:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f14927c:	e7ac05e8 */ 	swc1	$f12,0x5e8($sp)
/*  f149280:	afa505ec */ 	sw	$a1,0x5ec($sp)
/*  f149284:	afa705f4 */ 	sw	$a3,0x5f4($sp)
/*  f149288:	afa00500 */ 	sw	$zero,0x500($sp)
/*  f14928c:	afa004ec */ 	sw	$zero,0x4ec($sp)
/*  f149290:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f149294:	27a400ac */ 	addiu	$a0,$sp,0xac
/*  f149298:	00c01825 */ 	or	$v1,$a2,$zero
.L0f14929c:
/*  f14929c:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f1492a0:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1492a4:	0044082b */ 	sltu	$at,$v0,$a0
/*  f1492a8:	e444fffc */ 	swc1	$f4,-0x4($v0)
/*  f1492ac:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f1492b0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1492b4:	e4460008 */ 	swc1	$f6,0x8($v0)
/*  f1492b8:	c4680018 */ 	lwc1	$f8,0x18($v1)
/*  f1492bc:	e4480018 */ 	swc1	$f8,0x18($v0)
/*  f1492c0:	c46a0024 */ 	lwc1	$f10,0x24($v1)
/*  f1492c4:	1420fff5 */ 	bnez	$at,.L0f14929c
/*  f1492c8:	e44a0024 */ 	swc1	$f10,0x24($v0)
/*  f1492cc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1492d0:	3c018008 */ 	lui	$at,%hi(var8007f8b0)
/*  f1492d4:	afae00d8 */ 	sw	$t6,0xd8($sp)
/*  f1492d8:	c420f8b0 */ 	lwc1	$f0,%lo(var8007f8b0)($at)
/*  f1492dc:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f1492e0:	27a30514 */ 	addiu	$v1,$sp,0x514
/*  f1492e4:	27a40520 */ 	addiu	$a0,$sp,0x520
/*  f1492e8:	c44e0028 */ 	lwc1	$f14,0x28($v0)
/*  f1492ec:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1492f0:	0064082b */ 	sltu	$at,$v1,$a0
/*  f1492f4:	46007482 */ 	mul.s	$f18,$f14,$f0
/*  f1492f8:	5020000b */ 	beqzl	$at,.L0f149328
/*  f1492fc:	c450001c */ 	lwc1	$f16,0x1c($v0)
.L0f149300:
/*  f149300:	c450001c */ 	lwc1	$f16,0x1c($v0)
/*  f149304:	c44e002c */ 	lwc1	$f14,0x2c($v0)
/*  f149308:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14930c:	46109400 */ 	add.s	$f16,$f18,$f16
/*  f149310:	46007482 */ 	mul.s	$f18,$f14,$f0
/*  f149314:	0064082b */ 	sltu	$at,$v1,$a0
/*  f149318:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f14931c:	1420fff8 */ 	bnez	$at,.L0f149300
/*  f149320:	e470fff8 */ 	swc1	$f16,-0x8($v1)
/*  f149324:	c450001c */ 	lwc1	$f16,0x1c($v0)
.L0f149328:
/*  f149328:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f14932c:	46109400 */ 	add.s	$f16,$f18,$f16
/*  f149330:	e470fffc */ 	swc1	$f16,-0x4($v1)
/*  f149334:	8faf05ec */ 	lw	$t7,0x5ec($sp)
/*  f149338:	27a500bc */ 	addiu	$a1,$sp,0xbc
/*  f14933c:	27a70530 */ 	addiu	$a3,$sp,0x530
/*  f149340:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f149344:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f149348:	25e40008 */ 	addiu	$a0,$t7,0x8
/*  f14934c:	0c006052 */ 	jal	func00018148
/*  f149350:	25e60028 */ 	addiu	$a2,$t7,0x28
/*  f149354:	27b80540 */ 	addiu	$t8,$sp,0x540
/*  f149358:	2419001f */ 	addiu	$t9,$zero,0x1f
/*  f14935c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f149360:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f149364:	27a400bc */ 	addiu	$a0,$sp,0xbc
/*  f149368:	27a50514 */ 	addiu	$a1,$sp,0x514
/*  f14936c:	27a60530 */ 	addiu	$a2,$sp,0x530
/*  f149370:	0c006052 */ 	jal	func00018148
/*  f149374:	27a70520 */ 	addiu	$a3,$sp,0x520
/*  f149378:	87a80540 */ 	lh	$t0,0x540($sp)
/*  f14937c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f149380:	27a30540 */ 	addiu	$v1,$sp,0x540
/*  f149384:	51010086 */ 	beql	$t0,$at,.L0f1495a0
/*  f149388:	8fb904ec */ 	lw	$t9,0x4ec($sp)
/*  f14938c:	84660000 */ 	lh	$a2,0x0($v1)
/*  f149390:	27a400bc */ 	addiu	$a0,$sp,0xbc
.L0f149394:
/*  f149394:	27a50514 */ 	addiu	$a1,$sp,0x514
/*  f149398:	27a705b0 */ 	addiu	$a3,$sp,0x5b0
/*  f14939c:	0fc58548 */ 	jal	func0f161520
/*  f1493a0:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f1493a4:	10400078 */ 	beqz	$v0,.L0f149588
/*  f1493a8:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f1493ac:	c7a00514 */ 	lwc1	$f0,0x514($sp)
/*  f1493b0:	c7b000bc */ 	lwc1	$f16,0xbc($sp)
/*  f1493b4:	c7aa05b0 */ 	lwc1	$f10,0x5b0($sp)
/*  f1493b8:	4600803e */ 	c.le.s	$f16,$f0
/*  f1493bc:	00000000 */ 	nop
/*  f1493c0:	4502000a */ 	bc1fl	.L0f1493ec
/*  f1493c4:	4610003e */ 	c.le.s	$f0,$f16
/*  f1493c8:	4600503e */ 	c.le.s	$f10,$f0
/*  f1493cc:	00000000 */ 	nop
/*  f1493d0:	45020006 */ 	bc1fl	.L0f1493ec
/*  f1493d4:	4610003e */ 	c.le.s	$f0,$f16
/*  f1493d8:	460a803e */ 	c.le.s	$f16,$f10
/*  f1493dc:	00000000 */ 	nop
/*  f1493e0:	4503000e */ 	bc1tl	.L0f14941c
/*  f1493e4:	c7a20518 */ 	lwc1	$f2,0x518($sp)
/*  f1493e8:	4610003e */ 	c.le.s	$f0,$f16
.L0f1493ec:
/*  f1493ec:	c7b205b0 */ 	lwc1	$f18,0x5b0($sp)
/*  f1493f0:	45020066 */ 	bc1fl	.L0f14958c
/*  f1493f4:	84660002 */ 	lh	$a2,0x2($v1)
/*  f1493f8:	4612003e */ 	c.le.s	$f0,$f18
/*  f1493fc:	00000000 */ 	nop
/*  f149400:	45020062 */ 	bc1fl	.L0f14958c
/*  f149404:	84660002 */ 	lh	$a2,0x2($v1)
/*  f149408:	4610903e */ 	c.le.s	$f18,$f16
/*  f14940c:	00000000 */ 	nop
/*  f149410:	4502005e */ 	bc1fl	.L0f14958c
/*  f149414:	84660002 */ 	lh	$a2,0x2($v1)
/*  f149418:	c7a20518 */ 	lwc1	$f2,0x518($sp)
.L0f14941c:
/*  f14941c:	c7ae00c0 */ 	lwc1	$f14,0xc0($sp)
/*  f149420:	c7a405b4 */ 	lwc1	$f4,0x5b4($sp)
/*  f149424:	4602703e */ 	c.le.s	$f14,$f2
/*  f149428:	00000000 */ 	nop
/*  f14942c:	4502000a */ 	bc1fl	.L0f149458
/*  f149430:	460e103e */ 	c.le.s	$f2,$f14
/*  f149434:	4602203e */ 	c.le.s	$f4,$f2
/*  f149438:	00000000 */ 	nop
/*  f14943c:	45020006 */ 	bc1fl	.L0f149458
/*  f149440:	460e103e */ 	c.le.s	$f2,$f14
/*  f149444:	4604703e */ 	c.le.s	$f14,$f4
/*  f149448:	00000000 */ 	nop
/*  f14944c:	4503000e */ 	bc1tl	.L0f149488
/*  f149450:	c7a000c4 */ 	lwc1	$f0,0xc4($sp)
/*  f149454:	460e103e */ 	c.le.s	$f2,$f14
.L0f149458:
/*  f149458:	c7a605b4 */ 	lwc1	$f6,0x5b4($sp)
/*  f14945c:	4502004b */ 	bc1fl	.L0f14958c
/*  f149460:	84660002 */ 	lh	$a2,0x2($v1)
/*  f149464:	4606103e */ 	c.le.s	$f2,$f6
/*  f149468:	00000000 */ 	nop
/*  f14946c:	45020047 */ 	bc1fl	.L0f14958c
/*  f149470:	84660002 */ 	lh	$a2,0x2($v1)
/*  f149474:	460e303e */ 	c.le.s	$f6,$f14
/*  f149478:	00000000 */ 	nop
/*  f14947c:	45020043 */ 	bc1fl	.L0f14958c
/*  f149480:	84660002 */ 	lh	$a2,0x2($v1)
/*  f149484:	c7a000c4 */ 	lwc1	$f0,0xc4($sp)
.L0f149488:
/*  f149488:	c7ac051c */ 	lwc1	$f12,0x51c($sp)
/*  f14948c:	c7a805b8 */ 	lwc1	$f8,0x5b8($sp)
/*  f149490:	460c003e */ 	c.le.s	$f0,$f12
/*  f149494:	00000000 */ 	nop
/*  f149498:	4502000a */ 	bc1fl	.L0f1494c4
/*  f14949c:	4600603e */ 	c.le.s	$f12,$f0
/*  f1494a0:	460c403e */ 	c.le.s	$f8,$f12
/*  f1494a4:	00000000 */ 	nop
/*  f1494a8:	45020006 */ 	bc1fl	.L0f1494c4
/*  f1494ac:	4600603e */ 	c.le.s	$f12,$f0
/*  f1494b0:	4608003e */ 	c.le.s	$f0,$f8
/*  f1494b4:	00000000 */ 	nop
/*  f1494b8:	4503000e */ 	bc1tl	.L0f1494f4
/*  f1494bc:	c7b205b0 */ 	lwc1	$f18,0x5b0($sp)
/*  f1494c0:	4600603e */ 	c.le.s	$f12,$f0
.L0f1494c4:
/*  f1494c4:	c7aa05b8 */ 	lwc1	$f10,0x5b8($sp)
/*  f1494c8:	45020030 */ 	bc1fl	.L0f14958c
/*  f1494cc:	84660002 */ 	lh	$a2,0x2($v1)
/*  f1494d0:	460a603e */ 	c.le.s	$f12,$f10
/*  f1494d4:	00000000 */ 	nop
/*  f1494d8:	4502002c */ 	bc1fl	.L0f14958c
/*  f1494dc:	84660002 */ 	lh	$a2,0x2($v1)
/*  f1494e0:	4600503e */ 	c.le.s	$f10,$f0
/*  f1494e4:	00000000 */ 	nop
/*  f1494e8:	45020028 */ 	bc1fl	.L0f14958c
/*  f1494ec:	84660002 */ 	lh	$a2,0x2($v1)
/*  f1494f0:	c7b205b0 */ 	lwc1	$f18,0x5b0($sp)
.L0f1494f4:
/*  f1494f4:	c7a405b4 */ 	lwc1	$f4,0x5b4($sp)
/*  f1494f8:	c7a605b8 */ 	lwc1	$f6,0x5b8($sp)
/*  f1494fc:	46128032 */ 	c.eq.s	$f16,$f18
/*  f149500:	00000000 */ 	nop
/*  f149504:	4502000a */ 	bc1fl	.L0f149530
/*  f149508:	846a0000 */ 	lh	$t2,0x0($v1)
/*  f14950c:	46047032 */ 	c.eq.s	$f14,$f4
/*  f149510:	00000000 */ 	nop
/*  f149514:	45020006 */ 	bc1fl	.L0f149530
/*  f149518:	846a0000 */ 	lh	$t2,0x0($v1)
/*  f14951c:	46060032 */ 	c.eq.s	$f0,$f6
/*  f149520:	00000000 */ 	nop
/*  f149524:	45030019 */ 	bc1tl	.L0f14958c
/*  f149528:	84660002 */ 	lh	$a2,0x2($v1)
/*  f14952c:	846a0000 */ 	lh	$t2,0x0($v1)
.L0f149530:
/*  f149530:	27ac05b0 */ 	addiu	$t4,$sp,0x5b0
/*  f149534:	258f0030 */ 	addiu	$t7,$t4,0x30
/*  f149538:	27ab0580 */ 	addiu	$t3,$sp,0x580
/*  f14953c:	afaa0500 */ 	sw	$t2,0x500($sp)
.L0f149540:
/*  f149540:	8d810000 */ 	lw	$at,0x0($t4)
/*  f149544:	258c000c */ 	addiu	$t4,$t4,0xc
/*  f149548:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f14954c:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*  f149550:	8d81fff8 */ 	lw	$at,-0x8($t4)
/*  f149554:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*  f149558:	8d81fffc */ 	lw	$at,-0x4($t4)
/*  f14955c:	158ffff8 */ 	bne	$t4,$t7,.L0f149540
/*  f149560:	ad61fffc */ 	sw	$at,-0x4($t3)
/*  f149564:	c7a005b0 */ 	lwc1	$f0,0x5b0($sp)
/*  f149568:	c7a205b4 */ 	lwc1	$f2,0x5b4($sp)
/*  f14956c:	c7ac05b8 */ 	lwc1	$f12,0x5b8($sp)
/*  f149570:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f149574:	afb804ec */ 	sw	$t8,0x4ec($sp)
/*  f149578:	e7a00514 */ 	swc1	$f0,0x514($sp)
/*  f14957c:	e7a20518 */ 	swc1	$f2,0x518($sp)
/*  f149580:	10000006 */ 	b	.L0f14959c
/*  f149584:	e7ac051c */ 	swc1	$f12,0x51c($sp)
.L0f149588:
/*  f149588:	84660002 */ 	lh	$a2,0x2($v1)
.L0f14958c:
/*  f14958c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f149590:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f149594:	54c1ff7f */ 	bnel	$a2,$at,.L0f149394
/*  f149598:	27a400bc */ 	addiu	$a0,$sp,0xbc
.L0f14959c:
/*  f14959c:	8fb904ec */ 	lw	$t9,0x4ec($sp)
.L0f1495a0:
/*  f1495a0:	27a400bc */ 	addiu	$a0,$sp,0xbc
/*  f1495a4:	3c017f1b */ 	lui	$at,%hi(var7f1b6030)
/*  f1495a8:	13200019 */ 	beqz	$t9,.L0f149610
/*  f1495ac:	00000000 */ 	nop
/*  f1495b0:	0fc5dd18 */ 	jal	coordsGetDistance
/*  f1495b4:	27a50580 */ 	addiu	$a1,$sp,0x580
/*  f1495b8:	3c018008 */ 	lui	$at,%hi(var8007f8b0)
/*  f1495bc:	c428f8b0 */ 	lwc1	$f8,%lo(var8007f8b0)($at)
/*  f1495c0:	46000306 */ 	mov.s	$f12,$f0
/*  f1495c4:	27a805b0 */ 	addiu	$t0,$sp,0x5b0
/*  f1495c8:	4608003c */ 	c.lt.s	$f0,$f8
/*  f1495cc:	27a905bc */ 	addiu	$t1,$sp,0x5bc
/*  f1495d0:	4500000d */ 	bc1f	.L0f149608
/*  f1495d4:	00000000 */ 	nop
/*  f1495d8:	87ae05dc */ 	lh	$t6,0x5dc($sp)
/*  f1495dc:	8faa0500 */ 	lw	$t2,0x500($sp)
/*  f1495e0:	afa8050c */ 	sw	$t0,0x50c($sp)
/*  f1495e4:	39cd0002 */ 	xori	$t5,$t6,0x2
/*  f1495e8:	2dad0001 */ 	sltiu	$t5,$t5,0x1
/*  f1495ec:	afa80508 */ 	sw	$t0,0x508($sp)
/*  f1495f0:	afa90504 */ 	sw	$t1,0x504($sp)
/*  f1495f4:	afa005e0 */ 	sw	$zero,0x5e0($sp)
/*  f1495f8:	afa004fc */ 	sw	$zero,0x4fc($sp)
/*  f1495fc:	afad04f0 */ 	sw	$t5,0x4f0($sp)
/*  f149600:	10000004 */ 	b	.L0f149614
/*  f149604:	afaa04f8 */ 	sw	$t2,0x4f8($sp)
.L0f149608:
/*  f149608:	10000002 */ 	b	.L0f149614
/*  f14960c:	afa004ec */ 	sw	$zero,0x4ec($sp)
.L0f149610:
/*  f149610:	c42c6030 */ 	lwc1	$f12,%lo(var7f1b6030)($at)
.L0f149614:
/*  f149614:	8faf05fc */ 	lw	$t7,0x5fc($sp)
/*  f149618:	3c018008 */ 	lui	$at,%hi(var8007f8b0)
/*  f14961c:	c7aa05f4 */ 	lwc1	$f10,0x5f4($sp)
/*  f149620:	55e0005c */ 	bnezl	$t7,.L0f149794
/*  f149624:	8fae04ec */ 	lw	$t6,0x4ec($sp)
/*  f149628:	c420f8b0 */ 	lwc1	$f0,%lo(var8007f8b0)($at)
/*  f14962c:	4600603c */ 	c.lt.s	$f12,$f0
/*  f149630:	00000000 */ 	nop
/*  f149634:	45020004 */ 	bc1fl	.L0f149648
/*  f149638:	46000086 */ 	mov.s	$f2,$f0
/*  f14963c:	10000002 */ 	b	.L0f149648
/*  f149640:	46006086 */ 	mov.s	$f2,$f12
/*  f149644:	46000086 */ 	mov.s	$f2,$f0
.L0f149648:
/*  f149648:	460a1080 */ 	add.s	$f2,$f2,$f10
/*  f14964c:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f149650:	27a304b0 */ 	addiu	$v1,$sp,0x4b0
/*  f149654:	e7a200d4 */ 	swc1	$f2,0xd4($sp)
.L0f149658:
/*  f149658:	24420068 */ 	addiu	$v0,$v0,0x68
/*  f14965c:	ac40ffd8 */ 	sw	$zero,-0x28($v0)
/*  f149660:	ac40ffdc */ 	sw	$zero,-0x24($v0)
/*  f149664:	1443fffc */ 	bne	$v0,$v1,.L0f149658
/*  f149668:	ac40ffe0 */ 	sw	$zero,-0x20($v0)
/*  f14966c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f149670:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f149674:	8c43034c */ 	lw	$v1,0x34c($v0)
/*  f149678:	8c450348 */ 	lw	$a1,0x348($v0)
/*  f14967c:	2463fffc */ 	addiu	$v1,$v1,-4
/*  f149680:	0065082b */ 	sltu	$at,$v1,$a1
/*  f149684:	14200016 */ 	bnez	$at,.L0f1496e0
/*  f149688:	00000000 */ 	nop
/*  f14968c:	8c640000 */ 	lw	$a0,0x0($v1)
.L0f149690:
/*  f149690:	50800010 */ 	beqzl	$a0,.L0f1496d4
/*  f149694:	2463fffc */ 	addiu	$v1,$v1,-4
/*  f149698:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f14969c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1496a0:	10410005 */ 	beq	$v0,$at,.L0f1496b8
/*  f1496a4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1496a8:	10410003 */ 	beq	$v0,$at,.L0f1496b8
/*  f1496ac:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1496b0:	54410008 */ 	bnel	$v0,$at,.L0f1496d4
/*  f1496b4:	2463fffc */ 	addiu	$v1,$v1,-4
.L0f1496b8:
/*  f1496b8:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f1496bc:	0fc21780 */ 	jal	func0f085e00
/*  f1496c0:	afa305e4 */ 	sw	$v1,0x5e4($sp)
/*  f1496c4:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x348)
/*  f1496c8:	8fa305e4 */ 	lw	$v1,0x5e4($sp)
/*  f1496cc:	8ca5a308 */ 	lw	$a1,%lo(g_Vars+0x348)($a1)
/*  f1496d0:	2463fffc */ 	addiu	$v1,$v1,-4
.L0f1496d4:
/*  f1496d4:	0065082b */ 	sltu	$at,$v1,$a1
/*  f1496d8:	5020ffed */ 	beqzl	$at,.L0f149690
/*  f1496dc:	8c640000 */ 	lw	$a0,0x0($v1)
.L0f1496e0:
/*  f1496e0:	3c06800b */ 	lui	$a2,%hi(g_Textures)
/*  f1496e4:	3c058008 */ 	lui	$a1,%hi(somethings)
/*  f1496e8:	24a54458 */ 	addiu	$a1,$a1,%lo(somethings)
/*  f1496ec:	24c6abc0 */ 	addiu	$a2,$a2,%lo(g_Textures)
/*  f1496f0:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f1496f4:	27a704b0 */ 	addiu	$a3,$sp,0x4b0
/*  f1496f8:	8c4c0040 */ 	lw	$t4,0x40($v0)
.L0f1496fc:
/*  f1496fc:	2444003c */ 	addiu	$a0,$v0,0x3c
/*  f149700:	24420068 */ 	addiu	$v0,$v0,0x68
/*  f149704:	11800020 */ 	beqz	$t4,.L0f149788
/*  f149708:	00000000 */ 	nop
/*  f14970c:	8483003a */ 	lh	$v1,0x3a($a0)
/*  f149710:	0460000d */ 	bltz	$v1,.L0f149748
/*  f149714:	28610daf */ 	slti	$at,$v1,0xdaf
/*  f149718:	5020000c */ 	beqzl	$at,.L0f14974c
/*  f14971c:	248c0010 */ 	addiu	$t4,$a0,0x10
/*  f149720:	8ccb0000 */ 	lw	$t3,0x0($a2)
/*  f149724:	0003c0c0 */ 	sll	$t8,$v1,0x3
/*  f149728:	0178c821 */ 	addu	$t9,$t3,$t8
/*  f14972c:	93280000 */ 	lbu	$t0,0x0($t9)
/*  f149730:	3109000f */ 	andi	$t1,$t0,0xf
/*  f149734:	00095080 */ 	sll	$t2,$t1,0x2
/*  f149738:	00aa7021 */ 	addu	$t6,$a1,$t2
/*  f14973c:	8dcd0000 */ 	lw	$t5,0x0($t6)
/*  f149740:	85af000a */ 	lh	$t7,0xa($t5)
/*  f149744:	11e00010 */ 	beqz	$t7,.L0f149788
.L0f149748:
/*  f149748:	248c0010 */ 	addiu	$t4,$a0,0x10
.L0f14974c:
/*  f14974c:	248b0050 */ 	addiu	$t3,$a0,0x50
/*  f149750:	2498001c */ 	addiu	$t8,$a0,0x1c
/*  f149754:	afac050c */ 	sw	$t4,0x50c($sp)
/*  f149758:	afab0508 */ 	sw	$t3,0x508($sp)
/*  f14975c:	afb80504 */ 	sw	$t8,0x504($sp)
/*  f149760:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f149764:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f149768:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14976c:	afb905e0 */ 	sw	$t9,0x5e0($sp)
/*  f149770:	80880043 */ 	lb	$t0,0x43($a0)
/*  f149774:	afa904f8 */ 	sw	$t1,0x4f8($sp)
/*  f149778:	afa004f0 */ 	sw	$zero,0x4f0($sp)
/*  f14977c:	afaa04ec */ 	sw	$t2,0x4ec($sp)
/*  f149780:	10000003 */ 	b	.L0f149790
/*  f149784:	afa804fc */ 	sw	$t0,0x4fc($sp)
.L0f149788:
/*  f149788:	5447ffdc */ 	bnel	$v0,$a3,.L0f1496fc
/*  f14978c:	8c4c0040 */ 	lw	$t4,0x40($v0)
.L0f149790:
/*  f149790:	8fae04ec */ 	lw	$t6,0x4ec($sp)
.L0f149794:
/*  f149794:	27a3003c */ 	addiu	$v1,$sp,0x3c
/*  f149798:	8fa4050c */ 	lw	$a0,0x50c($sp)
/*  f14979c:	11c0002d */ 	beqz	$t6,.L0f149854
/*  f1497a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1497a4:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f1497a8:	8fa50508 */ 	lw	$a1,0x508($sp)
/*  f1497ac:	8fa60504 */ 	lw	$a2,0x504($sp)
/*  f1497b0:	27a70048 */ 	addiu	$a3,$sp,0x48
.L0f1497b4:
/*  f1497b4:	c4920000 */ 	lwc1	$f18,0x0($a0)
/*  f1497b8:	c446001c */ 	lwc1	$f6,0x1c($v0)
/*  f1497bc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1497c0:	e472fffc */ 	swc1	$f18,-0x4($v1)
/*  f1497c4:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f1497c8:	e4660020 */ 	swc1	$f6,0x20($v1)
/*  f1497cc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1497d0:	e4640008 */ 	swc1	$f4,0x8($v1)
/*  f1497d4:	c4c80000 */ 	lwc1	$f8,0x0($a2)
/*  f1497d8:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f1497dc:	24a50004 */ 	addiu	$a1,$a1,4
/*  f1497e0:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f1497e4:	1467fff3 */ 	bne	$v1,$a3,.L0f1497b4
/*  f1497e8:	e4680014 */ 	swc1	$f8,0x14($v1)
/*  f1497ec:	8fad05ec */ 	lw	$t5,0x5ec($sp)
/*  f1497f0:	8faf05e0 */ 	lw	$t7,0x5e0($sp)
/*  f1497f4:	8fac0604 */ 	lw	$t4,0x604($sp)
/*  f1497f8:	8fab04fc */ 	lw	$t3,0x4fc($sp)
/*  f1497fc:	8fb804f8 */ 	lw	$t8,0x4f8($sp)
/*  f149800:	8fb905f8 */ 	lw	$t9,0x5f8($sp)
/*  f149804:	8fa80600 */ 	lw	$t0,0x600($sp)
/*  f149808:	c7aa05e8 */ 	lwc1	$f10,0x5e8($sp)
/*  f14980c:	8fa905fc */ 	lw	$t1,0x5fc($sp)
/*  f149810:	8faa0608 */ 	lw	$t2,0x608($sp)
/*  f149814:	8fae04f0 */ 	lw	$t6,0x4f0($sp)
/*  f149818:	27a4003c */ 	addiu	$a0,$sp,0x3c
/*  f14981c:	afad0074 */ 	sw	$t5,0x74($sp)
/*  f149820:	afaf0070 */ 	sw	$t7,0x70($sp)
/*  f149824:	afac0078 */ 	sw	$t4,0x78($sp)
/*  f149828:	afab007c */ 	sw	$t3,0x7c($sp)
/*  f14982c:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f149830:	afb90084 */ 	sw	$t9,0x84($sp)
/*  f149834:	afa80090 */ 	sw	$t0,0x90($sp)
/*  f149838:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f14983c:	afa9006c */ 	sw	$t1,0x6c($sp)
/*  f149840:	afaa0094 */ 	sw	$t2,0x94($sp)
/*  f149844:	0fc5261b */ 	jal	func0f14986c
/*  f149848:	afae0088 */ 	sw	$t6,0x88($sp)
/*  f14984c:	10000001 */ 	b	.L0f149854
/*  f149850:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f149854:
/*  f149854:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f149858:	27bd05e8 */ 	addiu	$sp,$sp,0x5e8
/*  f14985c:	03e00008 */ 	jr	$ra
/*  f149860:	00000000 */ 	nop
);

void func0f149864(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0f14986c
.late_rodata
glabel var7f1b6034
.word func0f14986c+0x11c # f149988
glabel var7f1b6038
.word func0f14986c+0x11c # f149988
glabel var7f1b603c
.word func0f14986c+0x11c # f149988
glabel var7f1b6040
.word func0f14986c+0x12c # f149998
glabel var7f1b6044
.word func0f14986c+0x12c # f149998
glabel var7f1b6048
.word func0f14986c+0x13c # f1499a8
.text
/*  f14986c:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f149870:	240e00c0 */ 	addiu	$t6,$zero,0xc0
/*  f149874:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f149878:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f14987c:	a3ae0092 */ 	sb	$t6,0x92($sp)
/*  f149880:	8c820048 */ 	lw	$v0,0x48($a0)
/*  f149884:	00808025 */ 	or	$s0,$a0,$zero
/*  f149888:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f14988c:	afaf0088 */ 	sw	$t7,0x88($sp)
/*  f149890:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f149894:	8c98004c */ 	lw	$t8,0x4c($a0)
/*  f149898:	0c004b70 */ 	jal	random
/*  f14989c:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f1498a0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1498a4:	0041001b */ 	divu	$zero,$v0,$at
/*  f1498a8:	0000c810 */ 	mfhi	$t9
/*  f1498ac:	27280009 */ 	addiu	$t0,$t9,0x9
/*  f1498b0:	afa8008c */ 	sw	$t0,0x8c($sp)
/*  f1498b4:	8e030034 */ 	lw	$v1,0x34($s0)
/*  f1498b8:	50600013 */ 	beqzl	$v1,.L0f149908
/*  f1498bc:	8e020030 */ 	lw	$v0,0x30($s0)
/*  f1498c0:	90690000 */ 	lbu	$t1,0x0($v1)
/*  f1498c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1498c8:	5521000f */ 	bnel	$t1,$at,.L0f149908
/*  f1498cc:	8e020030 */ 	lw	$v0,0x30($s0)
/*  f1498d0:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f1498d4:	5040000c */ 	beqzl	$v0,.L0f149908
/*  f1498d8:	8e020030 */ 	lw	$v0,0x30($s0)
/*  f1498dc:	90430003 */ 	lbu	$v1,0x3($v0)
/*  f1498e0:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f1498e4:	240a0040 */ 	addiu	$t2,$zero,0x40
/*  f1498e8:	10610004 */ 	beq	$v1,$at,.L0f1498fc
/*  f1498ec:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f1498f0:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f1498f4:	54610004 */ 	bnel	$v1,$at,.L0f149908
/*  f1498f8:	8e020030 */ 	lw	$v0,0x30($s0)
.L0f1498fc:
/*  f1498fc:	a3aa0092 */ 	sb	$t2,0x92($sp)
/*  f149900:	afab0080 */ 	sw	$t3,0x80($sp)
/*  f149904:	8e020030 */ 	lw	$v0,0x30($s0)
.L0f149908:
/*  f149908:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14990c:	10410005 */ 	beq	$v0,$at,.L0f149924
/*  f149910:	24010002 */ 	addiu	$at,$zero,0x2
/*  f149914:	1041000b */ 	beq	$v0,$at,.L0f149944
/*  f149918:	00000000 */ 	nop
/*  f14991c:	1000000d */ 	b	.L0f149954
/*  f149920:	00000000 */ 	nop
.L0f149924:
/*  f149924:	0c004b70 */ 	jal	random
/*  f149928:	00000000 */ 	nop
/*  f14992c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f149930:	0041001b */ 	divu	$zero,$v0,$at
/*  f149934:	00006010 */ 	mfhi	$t4
/*  f149938:	258d0009 */ 	addiu	$t5,$t4,0x9
/*  f14993c:	10000005 */ 	b	.L0f149954
/*  f149940:	afad008c */ 	sw	$t5,0x8c($sp)
.L0f149944:
/*  f149944:	0c004b70 */ 	jal	random
/*  f149948:	00000000 */ 	nop
/*  f14994c:	240e000c */ 	addiu	$t6,$zero,0xc
/*  f149950:	afae008c */ 	sw	$t6,0x8c($sp)
.L0f149954:
/*  f149954:	0c004b70 */ 	jal	random
/*  f149958:	00000000 */ 	nop
/*  f14995c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f149960:	0041001b */ 	divu	$zero,$v0,$at
/*  f149964:	00007810 */ 	mfhi	$t7
/*  f149968:	2de10006 */ 	sltiu	$at,$t7,0x6
/*  f14996c:	10200012 */ 	beqz	$at,.L0f1499b8
/*  f149970:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f149974:	3c017f1b */ 	lui	$at,%hi(var7f1b6034)
/*  f149978:	002f0821 */ 	addu	$at,$at,$t7
/*  f14997c:	8c2f6034 */ 	lw	$t7,%lo(var7f1b6034)($at)
/*  f149980:	01e00008 */ 	jr	$t7
/*  f149984:	00000000 */ 	nop
/*  f149988:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f14998c:	44812000 */ 	mtc1	$at,$f4
/*  f149990:	10000009 */ 	b	.L0f1499b8
/*  f149994:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f149998:	3c0140a0 */ 	lui	$at,0x40a0
/*  f14999c:	44813000 */ 	mtc1	$at,$f6
/*  f1499a0:	10000005 */ 	b	.L0f1499b8
/*  f1499a4:	e7a6009c */ 	swc1	$f6,0x9c($sp)
/*  f1499a8:	3c014040 */ 	lui	$at,0x4040
/*  f1499ac:	44814000 */ 	mtc1	$at,$f8
/*  f1499b0:	00000000 */ 	nop
/*  f1499b4:	e7a8009c */ 	swc1	$f8,0x9c($sp)
.L0f1499b8:
/*  f1499b8:	2605000c */ 	addiu	$a1,$s0,0xc
/*  f1499bc:	afa5006c */ 	sw	$a1,0x6c($sp)
/*  f1499c0:	0fc5dd18 */ 	jal	coordsGetDistance
/*  f1499c4:	26040024 */ 	addiu	$a0,$s0,0x24
/*  f1499c8:	3c018008 */ 	lui	$at,%hi(var8007f8a0)
/*  f1499cc:	c42af8a0 */ 	lwc1	$f10,%lo(var8007f8a0)($at)
/*  f1499d0:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f1499d4:	3c018008 */ 	lui	$at,%hi(var8007f8b8)
/*  f1499d8:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f1499dc:	c422f8b8 */ 	lwc1	$f2,%lo(var8007f8b8)($at)
/*  f1499e0:	3c018008 */ 	lui	$at,%hi(var8007f8b4)
/*  f1499e4:	46062302 */ 	mul.s	$f12,$f4,$f6
/*  f1499e8:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1499ec:	00000000 */ 	nop
/*  f1499f0:	45000002 */ 	bc1f	.L0f1499fc
/*  f1499f4:	00000000 */ 	nop
/*  f1499f8:	46001306 */ 	mov.s	$f12,$f2
.L0f1499fc:
/*  f1499fc:	c420f8b4 */ 	lwc1	$f0,%lo(var8007f8b4)($at)
/*  f149a00:	3c013f80 */ 	lui	$at,0x3f80
/*  f149a04:	44811000 */ 	mtc1	$at,$f2
/*  f149a08:	4600603c */ 	c.lt.s	$f12,$f0
/*  f149a0c:	3c013f00 */ 	lui	$at,0x3f00
/*  f149a10:	44814000 */ 	mtc1	$at,$f8
/*  f149a14:	45000002 */ 	bc1f	.L0f149a20
/*  f149a18:	00000000 */ 	nop
/*  f149a1c:	46000306 */ 	mov.s	$f12,$f0
.L0f149a20:
/*  f149a20:	460c4002 */ 	mul.s	$f0,$f8,$f12
/*  f149a24:	4602003c */ 	c.lt.s	$f0,$f2
/*  f149a28:	46000406 */ 	mov.s	$f16,$f0
/*  f149a2c:	46000486 */ 	mov.s	$f18,$f0
/*  f149a30:	45020003 */ 	bc1fl	.L0f149a40
/*  f149a34:	4602003c */ 	c.lt.s	$f0,$f2
/*  f149a38:	46001406 */ 	mov.s	$f16,$f2
/*  f149a3c:	4602003c */ 	c.lt.s	$f0,$f2
.L0f149a40:
/*  f149a40:	00000000 */ 	nop
/*  f149a44:	45020003 */ 	bc1fl	.L0f149a54
/*  f149a48:	e7ac00a0 */ 	swc1	$f12,0xa0($sp)
/*  f149a4c:	46001486 */ 	mov.s	$f18,$f2
/*  f149a50:	e7ac00a0 */ 	swc1	$f12,0xa0($sp)
.L0f149a54:
/*  f149a54:	e7b000ac */ 	swc1	$f16,0xac($sp)
/*  f149a58:	0c004b70 */ 	jal	random
/*  f149a5c:	e7b200a8 */ 	swc1	$f18,0xa8($sp)
/*  f149a60:	44825000 */ 	mtc1	$v0,$f10
/*  f149a64:	c7ac00a0 */ 	lwc1	$f12,0xa0($sp)
/*  f149a68:	c7b000ac */ 	lwc1	$f16,0xac($sp)
/*  f149a6c:	04410005 */ 	bgez	$v0,.L0f149a84
/*  f149a70:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f149a74:	3c014f80 */ 	lui	$at,0x4f80
/*  f149a78:	44813000 */ 	mtc1	$at,$f6
/*  f149a7c:	00000000 */ 	nop
/*  f149a80:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f149a84:
/*  f149a84:	3c012f80 */ 	lui	$at,0x2f80
/*  f149a88:	44814000 */ 	mtc1	$at,$f8
/*  f149a8c:	00000000 */ 	nop
/*  f149a90:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f149a94:	00000000 */ 	nop
/*  f149a98:	46105002 */ 	mul.s	$f0,$f10,$f16
/*  f149a9c:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f149aa0:	46103101 */ 	sub.s	$f4,$f6,$f16
/*  f149aa4:	460c2380 */ 	add.s	$f14,$f4,$f12
/*  f149aa8:	0c004b70 */ 	jal	random
/*  f149aac:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f149ab0:	44824000 */ 	mtc1	$v0,$f8
/*  f149ab4:	c7ac00a0 */ 	lwc1	$f12,0xa0($sp)
/*  f149ab8:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f149abc:	c7b200a8 */ 	lwc1	$f18,0xa8($sp)
/*  f149ac0:	04410005 */ 	bgez	$v0,.L0f149ad8
/*  f149ac4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f149ac8:	3c014f80 */ 	lui	$at,0x4f80
/*  f149acc:	44813000 */ 	mtc1	$at,$f6
/*  f149ad0:	00000000 */ 	nop
/*  f149ad4:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f149ad8:
/*  f149ad8:	3c012f80 */ 	lui	$at,0x2f80
/*  f149adc:	44812000 */ 	mtc1	$at,$f4
/*  f149ae0:	3c018008 */ 	lui	$at,%hi(var8007f8b8)
/*  f149ae4:	c422f8b8 */ 	lwc1	$f2,%lo(var8007f8b8)($at)
/*  f149ae8:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f149aec:	460e103c */ 	c.lt.s	$f2,$f14
/*  f149af0:	46124002 */ 	mul.s	$f0,$f8,$f18
/*  f149af4:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f149af8:	46123281 */ 	sub.s	$f10,$f6,$f18
/*  f149afc:	460c5400 */ 	add.s	$f16,$f10,$f12
/*  f149b00:	45000002 */ 	bc1f	.L0f149b0c
/*  f149b04:	e7b00098 */ 	swc1	$f16,0x98($sp)
/*  f149b08:	46001386 */ 	mov.s	$f14,$f2
.L0f149b0c:
/*  f149b0c:	4610103c */ 	c.lt.s	$f2,$f16
/*  f149b10:	00000000 */ 	nop
/*  f149b14:	45020003 */ 	bc1fl	.L0f149b24
/*  f149b18:	c6000050 */ 	lwc1	$f0,0x50($s0)
/*  f149b1c:	e7a20098 */ 	swc1	$f2,0x98($sp)
/*  f149b20:	c6000050 */ 	lwc1	$f0,0x50($s0)
.L0f149b24:
/*  f149b24:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f149b28:	46007382 */ 	mul.s	$f14,$f14,$f0
/*  f149b2c:	00000000 */ 	nop
/*  f149b30:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f149b34:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f149b38:	8e040038 */ 	lw	$a0,0x38($s0)
/*  f149b3c:	0fc4f972 */ 	jal	func0f13e5c8
/*  f149b40:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f149b44:	8e02003c */ 	lw	$v0,0x3c($s0)
/*  f149b48:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f149b4c:	00003025 */ 	or	$a2,$zero,$zero
/*  f149b50:	10400004 */ 	beqz	$v0,.L0f149b64
/*  f149b54:	00000000 */ 	nop
/*  f149b58:	8c46001c */ 	lw	$a2,0x1c($v0)
/*  f149b5c:	10000001 */ 	b	.L0f149b64
/*  f149b60:	24c60008 */ 	addiu	$a2,$a2,0x8
.L0f149b64:
/*  f149b64:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f149b68:	0c004b70 */ 	jal	random
/*  f149b6c:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f149b70:	24010168 */ 	addiu	$at,$zero,0x168
/*  f149b74:	0041001b */ 	divu	$zero,$v0,$at
/*  f149b78:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f149b7c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f149b80:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f149b84:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f149b88:	8e190044 */ 	lw	$t9,0x44($s0)
/*  f149b8c:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f149b90:	93ac0092 */ 	lbu	$t4,0x92($sp)
/*  f149b94:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f149b98:	8e080034 */ 	lw	$t0,0x34($s0)
/*  f149b9c:	00007010 */ 	mfhi	$t6
/*  f149ba0:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f149ba4:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f149ba8:	8e090038 */ 	lw	$t1,0x38($s0)
/*  f149bac:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f149bb0:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f149bb4:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f149bb8:	8e0a0040 */ 	lw	$t2,0x40($s0)
/*  f149bbc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f149bc0:	02002025 */ 	or	$a0,$s0,$zero
/*  f149bc4:	afaa0024 */ 	sw	$t2,0x24($sp)
/*  f149bc8:	8e0b003c */ 	lw	$t3,0x3c($s0)
/*  f149bcc:	afae0040 */ 	sw	$t6,0x40($sp)
/*  f149bd0:	afad003c */ 	sw	$t5,0x3c($sp)
/*  f149bd4:	e7ae0030 */ 	swc1	$f14,0x30($sp)
/*  f149bd8:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f149bdc:	afac0038 */ 	sw	$t4,0x38($sp)
/*  f149be0:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f149be4:	960f0056 */ 	lhu	$t7,0x56($s0)
/*  f149be8:	26050018 */ 	addiu	$a1,$s0,0x18
/*  f149bec:	00003825 */ 	or	$a3,$zero,$zero
/*  f149bf0:	afaf0044 */ 	sw	$t7,0x44($sp)
/*  f149bf4:	8e180058 */ 	lw	$t8,0x58($s0)
/*  f149bf8:	afb9004c */ 	sw	$t9,0x4c($sp)
/*  f149bfc:	0fc4fd41 */ 	jal	func0f13f504
/*  f149c00:	afb80048 */ 	sw	$t8,0x48($sp)
/*  f149c04:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f149c08:	8fa80084 */ 	lw	$t0,0x84($sp)
/*  f149c0c:	240affff */ 	addiu	$t2,$zero,-1
/*  f149c10:	14400003 */ 	bnez	$v0,.L0f149c20
/*  f149c14:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f149c18:	5100000e */ 	beqzl	$t0,.L0f149c54
/*  f149c1c:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f149c20:
/*  f149c20:	8e090044 */ 	lw	$t1,0x44($s0)
/*  f149c24:	a7aa007a */ 	sh	$t2,0x7a($sp)
/*  f149c28:	10400003 */ 	beqz	$v0,.L0f149c38
/*  f149c2c:	a7a90078 */ 	sh	$t1,0x78($sp)
/*  f149c30:	10000002 */ 	b	.L0f149c3c
/*  f149c34:	2402000d */ 	addiu	$v0,$zero,0xd
.L0f149c38:
/*  f149c38:	2402000e */ 	addiu	$v0,$zero,0xe
.L0f149c3c:
/*  f149c3c:	00023400 */ 	sll	$a2,$v0,0x10
/*  f149c40:	00065c03 */ 	sra	$t3,$a2,0x10
/*  f149c44:	01603025 */ 	or	$a2,$t3,$zero
/*  f149c48:	0fc4ba08 */ 	jal	smokeCreateSimple
/*  f149c4c:	8fa4006c */ 	lw	$a0,0x6c($sp)
/*  f149c50:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f149c54:
/*  f149c54:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f149c58:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
/*  f149c5c:	03e00008 */ 	jr	$ra
/*  f149c60:	00000000 */ 	nop
);

void chrInitSplats(struct chrdata *chr)
{
	chr->bulletstaken = 0;
	chr->tickssincesplat = 0;
	chr->stdsplatsadded = 0;
	chr->woundedsplatsadded = 0;
	chr->deaddropsplatsadded = 0;
	chr->splatsdroppedhe = 0;
	chr->lastdroppos.x = 0;
	chr->lastdroppos.y = 0;
	chr->lastdroppos.z = 0;
}
