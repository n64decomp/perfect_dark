#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/propobj.h"
#include "game/game_095320.h"
#include "game/game_096360.h"
#include "game/game_0b3350.h"
#include "game/game_19c990.h"
#include "gvars/gvars.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "types.h"

const u32 var7f1ab800[] = {0x40c907a9};
const u32 var7f1ab804[] = {0x3cc907a9};
const u32 var7f1ab808[] = {0x40c907a9};
const u32 var7f1ab80c[] = {0x3cc907a9};
const u32 var7f1ab810[] = {0x40c907a9};
const u32 var7f1ab814[] = {0x3cc907a9};
const u32 var7f1ab818[] = {0x3fd55555};
const u32 var7f1ab81c[] = {0x40555555};
const u32 var7f1ab820[] = {0x3fd55555};
const u32 var7f1ab824[] = {0x3fd55555};
const u32 var7f1ab828[] = {0x40555555};
const u32 var7f1ab82c[] = {0x3e8e38e4};

// Too much stack usage and unknown functions to decompile this accurately
// at the moment.
//void objectiveCheckHolograph(s32 arg0)
//{
//	struct criteria_holograph *criteria = g_HolographCriterias;
//
//	while (criteria) {
//		if (g_Vars.stagenum == STAGE_CITRAINING) {
//			criteria->status = OBJECTIVE_INCOMPLETE;
//		}
//
//		if (criteria->status == OBJECTIVE_INCOMPLETE) {
//			struct defaultobj *obj = objFindByTagId(criteria->obj);
//
//			if (obj && obj->prop && obj->prop->flags & 2 && obj->prop->z > 0 && func0f0869a8(obj)) {
//				f32 fVar11 = arg0;
//				s32 a[2];
//				s32 b[2];
//				s32 c[2];
//
//				if (fVar11 != 0.00000000) {
//					float xdiff = obj->prop->pos.x - g_Vars.currentplayer->cam_pos.x;
//					float zdiff = obj->prop->pos.z - g_Vars.currentplayer->cam_pos.z;
//					pass = xdiff * xdiff + zdiff * zdiff < fVar11 * fVar11;
//				} else {
//					pass = fVar11 > -1;
//				}
//
//				if (pass && func0f0899dc(obj->prop, a, b, c))  {
//					func0f06803c(a, b, c, &fStack56);
//
//					if (func0f0b57f8() < fStack56 && fStack56 < currentPlayerGetScreenWidth() + func0f0b57f8() &&
//							func0f0b57f8() < fStack64 && fStack64 < currentPlayerGetScreenWidth() + func0f0b57f8() &&
//							func0f0b5808() < fStack52 && fStack52 < currentPlayerGetScreenHeight() + func0f0b5808() &&
//							func0f0b5808() < fStack60 && fStack60 < currentPlayerGetScreenHeight() + func0f0b5808()) {
//						criteria->status = OBJECTIVE_COMPLETE;
//
//						if (g_Vars.stagenum == STAGE_CITRAINING) {
//							struct trainingdata *data = ciGetTrainingData();
//							data->holographedpc = true;
//						}
//					}
//				}
//			}
//		}
//
//		criteria = criteria->next;
//	}
//}

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
/*  f0963a8:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f0963d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0963dc:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0963e0:	460a3401 */ 	sub.s	$f16,$f6,$f10
/*  f0963e4:	0c004b70 */ 	jal	random
/*  f0963e8:	e7b0001c */ 	swc1	$f16,0x1c($sp)
/*  f0963ec:	44829000 */ 	mtc1	$v0,$f18
/*  f0963f0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0963f4:	04410004 */ 	bgez	$v0,.L0f096408
/*  f0963f8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0963fc:	44814000 */ 	mtc1	$at,$f8
/*  f096400:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f096430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096434:	46089102 */ 	mul.s	$f4,$f18,$f8
/*  f096438:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f09643c:	0c004b70 */ 	jal	random
/*  f096440:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*  f096444:	44828000 */ 	mtc1	$v0,$f16
/*  f096448:	3c014f80 */ 	lui	$at,0x4f80
/*  f09644c:	04410004 */ 	bgez	$v0,.L0f096460
/*  f096450:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f096454:	44814000 */ 	mtc1	$at,$f8
/*  f096458:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f096490:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096494:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f096498:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f09649c:	0c005923 */ 	jal	func0001648c
/*  f0964a0:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f0964a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0964a8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0964ac:	03e00008 */ 	jr	$ra
/*  f0964b0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0964b4
/*  f0964b4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0964b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0964bc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0964c0:	0c004b70 */ 	jal	random
/*  f0964c4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0964c8:	44822000 */ 	mtc1	$v0,$f4
/*  f0964cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0964d0:	04410004 */ 	bgez	$v0,.L0f0964e4
/*  f0964d4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0964d8:	44814000 */ 	mtc1	$at,$f8
/*  f0964dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0964e0:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0964e4:
/*  f0964e4:	3c012f80 */ 	lui	$at,0x2f80
/*  f0964e8:	44815000 */ 	mtc1	$at,$f10
/*  f0964ec:	3c017f1b */ 	lui	$at,%hi(var7f1ab818)
/*  f0964f0:	c432b818 */ 	lwc1	$f18,%lo(var7f1ab818)($at)
/*  f0964f4:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0964f8:	3c014080 */ 	lui	$at,0x4080
/*  f0964fc:	44814000 */ 	mtc1	$at,$f8
/*  f096500:	3c017f1b */ 	lui	$at,%hi(var7f1ab81c)
/*  f096504:	c42ab81c */ 	lwc1	$f10,%lo(var7f1ab81c)($at)
/*  f096508:	8fae0018 */ 	lw	$t6,0x18($sp)
/*  f09650c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f096510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096514:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f096518:	460a3401 */ 	sub.s	$f16,$f6,$f10
/*  f09651c:	0c004b70 */ 	jal	random
/*  f096520:	e5d00000 */ 	swc1	$f16,0x0($t6)
/*  f096524:	44829000 */ 	mtc1	$v0,$f18
/*  f096528:	3c014f80 */ 	lui	$at,0x4f80
/*  f09652c:	04410004 */ 	bgez	$v0,.L0f096540
/*  f096530:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f096534:	44814000 */ 	mtc1	$at,$f8
/*  f096538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09653c:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f096540:
/*  f096540:	3c012f80 */ 	lui	$at,0x2f80
/*  f096544:	44813000 */ 	mtc1	$at,$f6
/*  f096548:	3c017f1b */ 	lui	$at,%hi(var7f1ab820)
/*  f09654c:	c430b820 */ 	lwc1	$f16,%lo(var7f1ab820)($at)
/*  f096550:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f096554:	3c014080 */ 	lui	$at,0x4080
/*  f096558:	44814000 */ 	mtc1	$at,$f8
/*  f09655c:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f096560:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f096564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096568:	46089102 */ 	mul.s	$f4,$f18,$f8
/*  f09656c:	0c004b70 */ 	jal	random
/*  f096570:	e5e40004 */ 	swc1	$f4,0x4($t7)
/*  f096574:	44823000 */ 	mtc1	$v0,$f6
/*  f096578:	3c014f80 */ 	lui	$at,0x4f80
/*  f09657c:	04410004 */ 	bgez	$v0,.L0f096590
/*  f096580:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f096584:	44818000 */ 	mtc1	$at,$f16
/*  f096588:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09658c:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f096590:
/*  f096590:	3c012f80 */ 	lui	$at,0x2f80
/*  f096594:	44819000 */ 	mtc1	$at,$f18
/*  f096598:	3c017f1b */ 	lui	$at,%hi(var7f1ab824)
/*  f09659c:	c424b824 */ 	lwc1	$f4,%lo(var7f1ab824)($at)
/*  f0965a0:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f0965a4:	3c014080 */ 	lui	$at,0x4080
/*  f0965a8:	44818000 */ 	mtc1	$at,$f16
/*  f0965ac:	3c017f1b */ 	lui	$at,%hi(var7f1ab828)
/*  f0965b0:	c432b828 */ 	lwc1	$f18,%lo(var7f1ab828)($at)
/*  f0965b4:	8fb80018 */ 	lw	$t8,0x18($sp)
/*  f0965b8:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0965bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0965c0:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f0965c4:	46125201 */ 	sub.s	$f8,$f10,$f18
/*  f0965c8:	e7080008 */ 	swc1	$f8,0x8($t8)
/*  f0965cc:	0fc258d8 */ 	jal	func0f096360
/*  f0965d0:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0965d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0965d8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0965dc:	03e00008 */ 	jr	$ra
/*  f0965e0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0965e4
/*  f0965e4:	3c017f1b */ 	lui	$at,%hi(var7f1ab82c)
/*  f0965e8:	44866000 */ 	mtc1	$a2,$f12
/*  f0965ec:	c424b82c */ 	lwc1	$f4,%lo(var7f1ab82c)($at)
/*  f0965f0:	c4a20000 */ 	lwc1	$f2,0x0($a1)
/*  f0965f4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0965f8:	46046182 */ 	mul.s	$f6,$f12,$f4
/*  f0965fc:	44818000 */ 	mtc1	$at,$f16
/*  f096600:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f096604:	46061001 */ 	sub.s	$f0,$f2,$f6
/*  f096608:	46001200 */ 	add.s	$f8,$f2,$f0
/*  f09660c:	46086282 */ 	mul.s	$f10,$f12,$f8
/*  f096610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096614:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f096618:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f09661c:	e4860000 */ 	swc1	$f6,0x0($a0)
/*  f096620:	03e00008 */ 	jr	$ra
/*  f096624:	e4a00000 */ 	swc1	$f0,0x0($a1)
/*  f096628:	44866000 */ 	mtc1	$a2,$f12
/*  f09662c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f096630:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f096634:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f096638:	00803825 */ 	or	$a3,$a0,$zero
/*  f09663c:	44066000 */ 	mfc1	$a2,$f12
/*  f096640:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f096644:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f096648:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f09664c:	0fc25979 */ 	jal	func0f0965e4
/*  f096650:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f096654:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f096658:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*  f09665c:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f096660:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f096664:	c4e40000 */ 	lwc1	$f4,0x0($a3)
/*  f096668:	46066202 */ 	mul.s	$f8,$f12,$f6
/*  f09666c:	c4f00008 */ 	lwc1	$f16,0x8($a3)
/*  f096670:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f096674:	e4ea0000 */ 	swc1	$f10,0x0($a3)
/*  f096678:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f09667c:	46126182 */ 	mul.s	$f6,$f12,$f18
/*  f096680:	46068100 */ 	add.s	$f4,$f16,$f6
/*  f096684:	e4e40008 */ 	swc1	$f4,0x8($a3)
/*  f096688:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09668c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f096690:	03e00008 */ 	jr	$ra
/*  f096694:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f096698
/*  f096698:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f09669c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0966a0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0966a4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0966a8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0966ac:	00c08825 */ 	or	$s1,$a2,$zero
/*  f0966b0:	00a09025 */ 	or	$s2,$a1,$zero
/*  f0966b4:	00809825 */ 	or	$s3,$a0,$zero
/*  f0966b8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0966bc:	18c00007 */ 	blez	$a2,.L0f0966dc
/*  f0966c0:	00008025 */ 	or	$s0,$zero,$zero
/*  f0966c4:	02402025 */ 	or	$a0,$s2,$zero
.L0f0966c8:
/*  f0966c8:	0c0056f8 */ 	jal	func00015be0
/*  f0966cc:	02602825 */ 	or	$a1,$s3,$zero
/*  f0966d0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0966d4:	5611fffc */ 	bnel	$s0,$s1,.L0f0966c8
/*  f0966d8:	02402025 */ 	or	$a0,$s2,$zero
.L0f0966dc:
/*  f0966dc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0966e0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0966e4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0966e8:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0966ec:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0966f0:	03e00008 */ 	jr	$ra
/*  f0966f4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0966f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0966fc:	00000000 */ 	sll	$zero,$zero,0x0
);
