#include <ultra64.h>
#include "constants.h"
#include "game/game_095320.h"
#include "game/game_096360.h"
#include "game/game_0b3350.h"
#include "game/training/training.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_PAL_FINAL
const u32 var7f1ab800[] = {0x40f13c65};
const u32 var7f1ab804[] = {0x3cf13c65};
const u32 var7f1ab808[] = {0x40f13c65};
const u32 var7f1ab80c[] = {0x3cf13c65};
const u32 var7f1ab810[] = {0x40f13c65};
const u32 var7f1ab814[] = {0x3cf13c65};
#else
const u32 var7f1ab800[] = {0x40c907a9};
const u32 var7f1ab804[] = {0x3cc907a9};
const u32 var7f1ab808[] = {0x40c907a9};
const u32 var7f1ab80c[] = {0x3cc907a9};
const u32 var7f1ab810[] = {0x40c907a9};
const u32 var7f1ab814[] = {0x3cc907a9};
#endif

u32 var8006ae80 = 0x00000000;

GLOBAL_ASM(
glabel func0f096360
/*  f096360:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f096364:	3c0f8007 */ 	lui	$t7,%hi(var8006ae80)
/*  f096368:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f09636c:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f096370:	25efae80 */ 	addiu	$t7,$t7,%lo(var8006ae80)
/*  f096374:	8de10000 */ 	lw	$at,0x0($t7)
/*  f096378:	27ae001c */ 	addiu	$t6,$sp,0x1c
/*  f09637c:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f096380:	adc10000 */ 	sw	$at,0x0($t6)
/*  f096384:	8de10008 */ 	lw	$at,0x8($t7)
/*  f096388:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f09638c:	0c004b70 */ 	jal	random
/*  f096390:	adc10008 */ 	sw	$at,0x8($t6)
/*  f096394:	44822000 */ 	mtc1	$v0,$f4
/*  f096398:	3c014f80 */ 	lui	$at,0x4f80
/*  f09639c:	04410004 */ 	bgez	$v0,.L0f0963b0
/*  f0963a0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0963a4:	44814000 */ 	mtc1	$at,$f8
/*  f0963a8:	00000000 */ 	nop
/*  f0963ac:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0963b0:
/*  f0963b0:	3c012f80 */ 	lui	$at,0x2f80
/*  f0963b4:	44815000 */ 	mtc1	$at,$f10
/*  f0963b8:	3c017f1b */ 	lui	$at,%hi(var7f1ab800)
/*  f0963bc:	c432b800 */ 	lwc1	$f18,%lo(var7f1ab800)($at)
/*  f0963c0:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0963c4:	3c013c00 */ 	lui	$at,0x3c00
/*  f0963c8:	44814000 */ 	mtc1	$at,$f8
/*  f0963cc:	3c017f1b */ 	lui	$at,%hi(var7f1ab804)
/*  f0963d0:	c42ab804 */ 	lwc1	$f10,%lo(var7f1ab804)($at)
/*  f0963d4:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0963d8:	00000000 */ 	nop
/*  f0963dc:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0963e0:	460a3401 */ 	sub.s	$f16,$f6,$f10
/*  f0963e4:	0c004b70 */ 	jal	random
/*  f0963e8:	e7b0001c */ 	swc1	$f16,0x1c($sp)
/*  f0963ec:	44829000 */ 	mtc1	$v0,$f18
/*  f0963f0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0963f4:	04410004 */ 	bgez	$v0,.L0f096408
/*  f0963f8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0963fc:	44814000 */ 	mtc1	$at,$f8
/*  f096400:	00000000 */ 	nop
/*  f096404:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f096408:
/*  f096408:	3c012f80 */ 	lui	$at,0x2f80
/*  f09640c:	44813000 */ 	mtc1	$at,$f6
/*  f096410:	3c017f1b */ 	lui	$at,%hi(var7f1ab808)
/*  f096414:	c430b808 */ 	lwc1	$f16,%lo(var7f1ab808)($at)
/*  f096418:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f09641c:	3c013c00 */ 	lui	$at,0x3c00
/*  f096420:	44814000 */ 	mtc1	$at,$f8
/*  f096424:	3c017f1b */ 	lui	$at,%hi(var7f1ab80c)
/*  f096428:	c426b80c */ 	lwc1	$f6,%lo(var7f1ab80c)($at)
/*  f09642c:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f096430:	00000000 */ 	nop
/*  f096434:	46089102 */ 	mul.s	$f4,$f18,$f8
/*  f096438:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f09643c:	0c004b70 */ 	jal	random
/*  f096440:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*  f096444:	44828000 */ 	mtc1	$v0,$f16
/*  f096448:	3c014f80 */ 	lui	$at,0x4f80
/*  f09644c:	04410004 */ 	bgez	$v0,.L0f096460
/*  f096450:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f096454:	44814000 */ 	mtc1	$at,$f8
/*  f096458:	00000000 */ 	nop
/*  f09645c:	46089480 */ 	add.s	$f18,$f18,$f8
.L0f096460:
/*  f096460:	3c012f80 */ 	lui	$at,0x2f80
/*  f096464:	44812000 */ 	mtc1	$at,$f4
/*  f096468:	3c017f1b */ 	lui	$at,%hi(var7f1ab810)
/*  f09646c:	c42ab810 */ 	lwc1	$f10,%lo(var7f1ab810)($at)
/*  f096470:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f096474:	3c013c00 */ 	lui	$at,0x3c00
/*  f096478:	44814000 */ 	mtc1	$at,$f8
/*  f09647c:	3c017f1b */ 	lui	$at,%hi(var7f1ab814)
/*  f096480:	c424b814 */ 	lwc1	$f4,%lo(var7f1ab814)($at)
/*  f096484:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f096488:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f09648c:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f096490:	00000000 */ 	nop
/*  f096494:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f096498:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f09649c:	0c005923 */ 	jal	func0001648c
/*  f0964a0:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f0964a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0964a8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0964ac:	03e00008 */ 	jr	$ra
/*  f0964b0:	00000000 */ 	nop
);

void func0f0964b4(f32 *arg0, f32 mf[4][4])
{
	arg0[0] = random() * (1.0f / U32_MAX) * 1.6666666269302f * 4.0f - 3.3333332538605f;
	arg0[1] = random() * (1.0f / U32_MAX) * 1.6666666269302f * 4.0f;
	arg0[2] = random() * (1.0f / U32_MAX) * 1.6666666269302f * 4.0f - 3.3333332538605f;

	func0f096360(mf);
}

void func0f0965e4(f32 *arg0, f32 *arg1, f32 arg2)
{
	f32 tmp = arg1[0] - arg2 * 0.27777779f;
	arg0[0] += arg2 * (arg1[0] + tmp) * 0.5f;
	arg1[0] = tmp;
}

void func0f096628(f32 *arg0, f32 *arg1, f32 arg2)
{
	func0f0965e4(&arg0[1], &arg1[1], arg2);

	arg0[0] += arg2 * arg1[0];
	arg0[2] += arg2 * arg1[2];
}

void func0f096698(Mtxf *arg0, Mtxf *arg1, s32 count)
{
	s32 i;

	for (i = 0; i < count; i++) {
		func00015be0(arg1, arg0);
	}
}
