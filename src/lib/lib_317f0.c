#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/lib_2fc60.h"
#include "lib/lib_317f0.h"
#include "lib/lib_39c80.h"
#include "lib/lib_3a100.h"
#include "lib/lib_3d280.h"
#include "lib/lib_3e3e0.h"
#include "data.h"
#include "types.h"

u32 var8009c330;
s16 *var8009c334;

u32 var8005f120 = 0;
u32 var8005f124 = 0;
void *var8005f128 = NULL;
N_ALSndPlayer *g_SndPlayer = &var8009c2d0;
u32 var8005f130 = 0;
u32 var8005f134 = 0;
u32 var8005f138 = 0;
u32 var8005f13c = 0;
void *var8005f140 = NULL; // function callback

void func00033090(struct audiohandle *handle)
{
	if (handle->unk44 & 4) {
		n_alSynStopVoice(&handle->voice);
		n_alSynFreeVoice(&handle->voice);
	}

	func0003364c(handle);
	func00033180(&g_SndPlayer->evtq, handle, 0xffff);
}

GLOBAL_ASM(
glabel func00033100
/*    33100:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33104:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33108:	afa40030 */ 	sw	$a0,0x30($sp)
/*    3310c:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    33110:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    33114:	8df80004 */ 	lw	$t8,0x4($t7)
/*    33118:	0c00e7f8 */ 	jal	alCents2Ratio
/*    3311c:	83040005 */ 	lb	$a0,0x5($t8)
/*    33120:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    33124:	c724002c */ 	lwc1	$f4,0x2c($t9)
/*    33128:	46040182 */ 	mul.s	$f6,$f0,$f4
/*    3312c:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*    33130:	24080010 */ 	addiu	$t0,$zero,0x10
/*    33134:	a7a80020 */ 	sh	$t0,0x20($sp)
/*    33138:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3313c:	afa90024 */ 	sw	$t1,0x24($sp)
/*    33140:	27aa001c */ 	addiu	$t2,$sp,0x1c
/*    33144:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    33148:	afab0028 */ 	sw	$t3,0x28($sp)
/*    3314c:	3c048006 */ 	lui	$a0,%hi(g_SndPlayer)
/*    33150:	8c84f12c */ 	lw	$a0,%lo(g_SndPlayer)($a0)
/*    33154:	27a50020 */ 	addiu	$a1,$sp,0x20
/*    33158:	34068235 */ 	dli	$a2,0x8235
/*    3315c:	00003825 */ 	or	$a3,$zero,$zero
/*    33160:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    33164:	24840014 */ 	addiu	$a0,$a0,20
/*    33168:	10000001 */ 	b	.L00033170
/*    3316c:	00000000 */ 	nop
.L00033170:
/*    33170:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33174:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    33178:	03e00008 */ 	jr	$ra
/*    3317c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033180
/*    33180:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33184:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33188:	afa40030 */ 	sw	$a0,0x30($sp)
/*    3318c:	afa50034 */ 	sw	$a1,0x34($sp)
/*    33190:	afa60038 */ 	sw	$a2,0x38($sp)
/*    33194:	0c012194 */ 	jal	osSetIntMask
/*    33198:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3319c:	afa20018 */ 	sw	$v0,0x18($sp)
/*    331a0:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    331a4:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    331a8:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    331ac:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    331b0:	13000028 */ 	beqz	$t8,.L00033254
/*    331b4:	00000000 */ 	nop
.L000331b8:
/*    331b8:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    331bc:	8f280000 */ 	lw	$t0,0x0($t9)
/*    331c0:	afa80028 */ 	sw	$t0,0x28($sp)
/*    331c4:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    331c8:	afa90024 */ 	sw	$t1,0x24($sp)
/*    331cc:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    331d0:	afaa0020 */ 	sw	$t2,0x20($sp)
/*    331d4:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    331d8:	256c000c */ 	addiu	$t4,$t3,0xc
/*    331dc:	afac001c */ 	sw	$t4,0x1c($sp)
/*    331e0:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    331e4:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    331e8:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    331ec:	15cf0014 */ 	bne	$t6,$t7,.L00033240
/*    331f0:	00000000 */ 	nop
/*    331f4:	95b80000 */ 	lhu	$t8,0x0($t5)
/*    331f8:	97b9003a */ 	lhu	$t9,0x3a($sp)
/*    331fc:	03194024 */ 	and	$t0,$t8,$t9
/*    33200:	1100000f */ 	beqz	$t0,.L00033240
/*    33204:	00000000 */ 	nop
/*    33208:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3320c:	11200007 */ 	beqz	$t1,.L0003322c
/*    33210:	00000000 */ 	nop
/*    33214:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    33218:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3321c:	8d4b0008 */ 	lw	$t3,0x8($t2)
/*    33220:	8d8e0008 */ 	lw	$t6,0x8($t4)
/*    33224:	016e7821 */ 	addu	$t7,$t3,$t6
/*    33228:	ad4f0008 */ 	sw	$t7,0x8($t2)
.L0003322c:
/*    3322c:	0c00c5e9 */ 	jal	alUnlink
/*    33230:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33234:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33238:	0c00c5dc */ 	jal	alLink
/*    3323c:	8fa50030 */ 	lw	$a1,0x30($sp)
.L00033240:
/*    33240:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    33244:	afad002c */ 	sw	$t5,0x2c($sp)
/*    33248:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3324c:	1700ffda */ 	bnez	$t8,.L000331b8
/*    33250:	00000000 */ 	nop
.L00033254:
/*    33254:	0c012194 */ 	jal	osSetIntMask
/*    33258:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    3325c:	10000001 */ 	b	.L00033264
/*    33260:	00000000 */ 	nop
.L00033264:
/*    33264:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33268:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    3326c:	03e00008 */ 	jr	$ra
/*    33270:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033274
/*    33274:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33278:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3327c:	afa40030 */ 	sw	$a0,0x30($sp)
/*    33280:	afa50034 */ 	sw	$a1,0x34($sp)
/*    33284:	0c012194 */ 	jal	osSetIntMask
/*    33288:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3328c:	afa2002c */ 	sw	$v0,0x2c($sp)
/*    33290:	3c0e8006 */ 	lui	$t6,%hi(var8005f120)
/*    33294:	8dcef120 */ 	lw	$t6,%lo(var8005f120)($t6)
/*    33298:	afae0020 */ 	sw	$t6,0x20($sp)
/*    3329c:	3c0f8006 */ 	lui	$t7,%hi(var8005f128)
/*    332a0:	8deff128 */ 	lw	$t7,%lo(var8005f128)($t7)
/*    332a4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    332a8:	3c188006 */ 	lui	$t8,%hi(var8005f124)
/*    332ac:	8f18f124 */ 	lw	$t8,%lo(var8005f124)($t8)
/*    332b0:	afb80018 */ 	sw	$t8,0x18($sp)
/*    332b4:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    332b8:	a7a0002a */ 	sh	$zero,0x2a($sp)
/*    332bc:	13200008 */ 	beqz	$t9,.L000332e0
/*    332c0:	00000000 */ 	nop
.L000332c4:
/*    332c4:	97a8002a */ 	lhu	$t0,0x2a($sp)
/*    332c8:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    332cc:	25090001 */ 	addiu	$t1,$t0,0x1
/*    332d0:	a7a9002a */ 	sh	$t1,0x2a($sp)
/*    332d4:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    332d8:	1560fffa */ 	bnez	$t3,.L000332c4
/*    332dc:	afab0020 */ 	sw	$t3,0x20($sp)
.L000332e0:
/*    332e0:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    332e4:	a7a00028 */ 	sh	$zero,0x28($sp)
/*    332e8:	11800008 */ 	beqz	$t4,.L0003330c
/*    332ec:	00000000 */ 	nop
.L000332f0:
/*    332f0:	97ad0028 */ 	lhu	$t5,0x28($sp)
/*    332f4:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    332f8:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    332fc:	a7ae0028 */ 	sh	$t6,0x28($sp)
/*    33300:	8df80000 */ 	lw	$t8,0x0($t7)
/*    33304:	1700fffa */ 	bnez	$t8,.L000332f0
/*    33308:	afb8001c */ 	sw	$t8,0x1c($sp)
.L0003330c:
/*    3330c:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33310:	a7a00026 */ 	sh	$zero,0x26($sp)
/*    33314:	13200008 */ 	beqz	$t9,.L00033338
/*    33318:	00000000 */ 	nop
.L0003331c:
/*    3331c:	97a80026 */ 	lhu	$t0,0x26($sp)
/*    33320:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    33324:	25090001 */ 	addiu	$t1,$t0,0x1
/*    33328:	a7a90026 */ 	sh	$t1,0x26($sp)
/*    3332c:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*    33330:	1560fffa */ 	bnez	$t3,.L0003331c
/*    33334:	afab0018 */ 	sw	$t3,0x18($sp)
.L00033338:
/*    33338:	97ac0028 */ 	lhu	$t4,0x28($sp)
/*    3333c:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    33340:	a5ac0000 */ 	sh	$t4,0x0($t5)
/*    33344:	97ae002a */ 	lhu	$t6,0x2a($sp)
/*    33348:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    3334c:	a5ee0000 */ 	sh	$t6,0x0($t7)
/*    33350:	0c012194 */ 	jal	osSetIntMask
/*    33354:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33358:	10000003 */ 	b	.L00033368
/*    3335c:	97a20026 */ 	lhu	$v0,0x26($sp)
/*    33360:	10000001 */ 	b	.L00033368
/*    33364:	00000000 */ 	nop
.L00033368:
/*    33368:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3336c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    33370:	03e00008 */ 	jr	$ra
/*    33374:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033378
/*    33378:	3c018006 */ 	lui	$at,%hi(var8005f13c)
/*    3337c:	ac24f13c */ 	sw	$a0,%lo(var8005f13c)($at)
/*    33380:	03e00008 */ 	jr	$ra
/*    33384:	00000000 */ 	nop
/*    33388:	03e00008 */ 	jr	$ra
/*    3338c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00033390
/*    33390:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    33394:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33398:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3339c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    333a0:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    333a4:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*    333a8:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    333ac:	3c188006 */ 	lui	$t8,%hi(var8005f134)
/*    333b0:	8f18f134 */ 	lw	$t8,%lo(var8005f134)($t8)
/*    333b4:	3c088006 */ 	lui	$t0,%hi(var8005f138)
/*    333b8:	8d08f138 */ 	lw	$t0,%lo(var8005f138)($t0)
/*    333bc:	3c018006 */ 	lui	$at,%hi(var8005f134)
/*    333c0:	27190001 */ 	addiu	$t9,$t8,0x1
/*    333c4:	ac39f134 */ 	sw	$t9,%lo(var8005f134)($at)
/*    333c8:	0119082a */ 	slt	$at,$t0,$t9
/*    333cc:	1020000a */ 	beqz	$at,.L000333f8
/*    333d0:	00000000 */ 	nop
/*    333d4:	3c098006 */ 	lui	$t1,%hi(var8005f134)
/*    333d8:	8d29f134 */ 	lw	$t1,%lo(var8005f134)($t1)
/*    333dc:	3c018006 */ 	lui	$at,%hi(var8005f138)
/*    333e0:	ac29f138 */ 	sw	$t1,%lo(var8005f138)($at)
/*    333e4:	3c0a8006 */ 	lui	$t2,%hi(var8005f134)
/*    333e8:	8d4af134 */ 	lw	$t2,%lo(var8005f134)($t2)
/*    333ec:	29410011 */ 	slti	$at,$t2,0x11
/*    333f0:	14200001 */ 	bnez	$at,.L000333f8
/*    333f4:	00000000 */ 	nop
.L000333f8:
/*    333f8:	0c012194 */ 	jal	osSetIntMask
/*    333fc:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33400:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    33404:	3c0b8006 */ 	lui	$t3,%hi(var8005f128)
/*    33408:	8d6bf128 */ 	lw	$t3,%lo(var8005f128)($t3)
/*    3340c:	afab0024 */ 	sw	$t3,0x24($sp)
/*    33410:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    33414:	1180007d */ 	beqz	$t4,.L0003360c
/*    33418:	00000000 */ 	nop
/*    3341c:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    33420:	3c018006 */ 	lui	$at,%hi(var8005f128)
/*    33424:	8dae0000 */ 	lw	$t6,0x0($t5)
/*    33428:	ac2ef128 */ 	sw	$t6,%lo(var8005f128)($at)
/*    3342c:	0c00c5e9 */ 	jal	alUnlink
/*    33430:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    33434:	3c0f8006 */ 	lui	$t7,%hi(var8005f120)
/*    33438:	8deff120 */ 	lw	$t7,%lo(var8005f120)($t7)
/*    3343c:	11e0000f */ 	beqz	$t7,.L0003347c
/*    33440:	00000000 */ 	nop
/*    33444:	3c188006 */ 	lui	$t8,%hi(var8005f120)
/*    33448:	8f18f120 */ 	lw	$t8,%lo(var8005f120)($t8)
/*    3344c:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    33450:	af380000 */ 	sw	$t8,0x0($t9)
/*    33454:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    33458:	ad000004 */ 	sw	$zero,0x4($t0)
/*    3345c:	3c0a8006 */ 	lui	$t2,%hi(var8005f120)
/*    33460:	8d4af120 */ 	lw	$t2,%lo(var8005f120)($t2)
/*    33464:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    33468:	ad490004 */ 	sw	$t1,0x4($t2)
/*    3346c:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    33470:	3c018006 */ 	lui	$at,%hi(var8005f120)
/*    33474:	1000000c */ 	b	.L000334a8
/*    33478:	ac2bf120 */ 	sw	$t3,%lo(var8005f120)($at)
.L0003347c:
/*    3347c:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    33480:	ad800004 */ 	sw	$zero,0x4($t4)
/*    33484:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    33488:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    3348c:	adae0000 */ 	sw	$t6,0x0($t5)
/*    33490:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    33494:	3c018006 */ 	lui	$at,%hi(var8005f120)
/*    33498:	ac2ff120 */ 	sw	$t7,%lo(var8005f120)($at)
/*    3349c:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    334a0:	3c018006 */ 	lui	$at,%hi(var8005f124)
/*    334a4:	ac38f124 */ 	sw	$t8,%lo(var8005f124)($at)
.L000334a8:
/*    334a8:	0c012194 */ 	jal	osSetIntMask
/*    334ac:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    334b0:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    334b4:	8f280000 */ 	lw	$t0,0x0($t9)
/*    334b8:	8d090004 */ 	lw	$t1,0x4($t0)
/*    334bc:	252a0001 */ 	addiu	$t2,$t1,0x1
/*    334c0:	2d4a0001 */ 	sltiu	$t2,$t2,0x1
/*    334c4:	afaa0018 */ 	sw	$t2,0x18($sp)
/*    334c8:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    334cc:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    334d0:	ad8b0008 */ 	sw	$t3,0x8($t4)
/*    334d4:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    334d8:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    334dc:	25cd0040 */ 	addiu	$t5,$t6,0x40
/*    334e0:	a1ed0040 */ 	sb	$t5,0x40($t7)
/*    334e4:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    334e8:	24180005 */ 	addiu	$t8,$zero,0x5
/*    334ec:	a3380045 */ 	sb	$t8,0x45($t9)
/*    334f0:	3c013f80 */ 	lui	$at,0x3f80
/*    334f4:	44812000 */ 	mtc1	$at,$f4
/*    334f8:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    334fc:	e504002c */ 	swc1	$f4,0x2c($t0)
/*    33500:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    33504:	24090002 */ 	addiu	$t1,$zero,0x2
/*    33508:	ad490034 */ 	sw	$t1,0x34($t2)
/*    3350c:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    33510:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    33514:	916c0003 */ 	lbu	$t4,0x3($t3)
/*    33518:	318e00f0 */ 	andi	$t6,$t4,0xf0
/*    3351c:	a1ae0044 */ 	sb	$t6,0x44($t5)
/*    33520:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    33524:	ade00030 */ 	sw	$zero,0x30($t7)
/*    33528:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3352c:	93190044 */ 	lbu	$t9,0x44($t8)
/*    33530:	33280020 */ 	andi	$t0,$t9,0x20
/*    33534:	1100000e */ 	beqz	$t0,.L00033570
/*    33538:	00000000 */ 	nop
/*    3353c:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    33540:	91240004 */ 	lbu	$a0,0x4($t1)
/*    33544:	00800821 */ 	addu	$at,$a0,$zero
/*    33548:	00012080 */ 	sll	$a0,$at,0x2
/*    3354c:	00812023 */ 	subu	$a0,$a0,$at
/*    33550:	000420c0 */ 	sll	$a0,$a0,0x3
/*    33554:	00812021 */ 	addu	$a0,$a0,$at
/*    33558:	00042080 */ 	sll	$a0,$a0,0x2
/*    3355c:	0c00e7f8 */ 	jal	alCents2Ratio
/*    33560:	2484e890 */ 	addiu	$a0,$a0,-6000
/*    33564:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    33568:	1000000e */ 	b	.L000335a4
/*    3356c:	e5400028 */ 	swc1	$f0,0x28($t2)
.L00033570:
/*    33570:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    33574:	916c0004 */ 	lbu	$t4,0x4($t3)
/*    33578:	816d0005 */ 	lb	$t5,0x5($t3)
/*    3357c:	000c7080 */ 	sll	$t6,$t4,0x2
/*    33580:	01cc7023 */ 	subu	$t6,$t6,$t4
/*    33584:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    33588:	01cc7021 */ 	addu	$t6,$t6,$t4
/*    3358c:	000e7080 */ 	sll	$t6,$t6,0x2
/*    33590:	01cd2021 */ 	addu	$a0,$t6,$t5
/*    33594:	0c00e7f8 */ 	jal	alCents2Ratio
/*    33598:	2484e890 */ 	addiu	$a0,$a0,-6000
/*    3359c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    335a0:	e5e00028 */ 	swc1	$f0,0x28($t7)
.L000335a4:
/*    335a4:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    335a8:	13000005 */ 	beqz	$t8,.L000335c0
/*    335ac:	00000000 */ 	nop
/*    335b0:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    335b4:	93280044 */ 	lbu	$t0,0x44($t9)
/*    335b8:	35090002 */ 	ori	$t1,$t0,0x2
/*    335bc:	a3290044 */ 	sb	$t1,0x44($t9)
.L000335c0:
/*    335c0:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    335c4:	a1400042 */ 	sb	$zero,0x42($t2)
/*    335c8:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    335cc:	240c0040 */ 	addiu	$t4,$zero,0x40
/*    335d0:	a16c0041 */ 	sb	$t4,0x41($t3)
/*    335d4:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    335d8:	240e7fff */ 	addiu	$t6,$zero,0x7fff
/*    335dc:	a5ae0038 */ 	sh	$t6,0x38($t5)
/*    335e0:	3c0f8006 */ 	lui	$t7,%hi(var8005f13c)
/*    335e4:	8deff13c */ 	lw	$t7,%lo(var8005f13c)($t7)
/*    335e8:	11e00006 */ 	beqz	$t7,.L00033604
/*    335ec:	00000000 */ 	nop
/*    335f0:	3c198006 */ 	lui	$t9,%hi(var8005f13c)
/*    335f4:	8f39f13c */ 	lw	$t9,%lo(var8005f13c)($t9)
/*    335f8:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    335fc:	0320f809 */ 	jalr	$t9
/*    33600:	8f040008 */ 	lw	$a0,0x8($t8)
.L00033604:
/*    33604:	10000003 */ 	b	.L00033614
/*    33608:	00000000 */ 	nop
.L0003360c:
/*    3360c:	0c012194 */ 	jal	osSetIntMask
/*    33610:	8fa4001c */ 	lw	$a0,0x1c($sp)
.L00033614:
/*    33614:	10000003 */ 	b	.L00033624
/*    33618:	8fa20024 */ 	lw	$v0,0x24($sp)
/*    3361c:	10000001 */ 	b	.L00033624
/*    33620:	00000000 */ 	nop
.L00033624:
/*    33624:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33628:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3362c:	03e00008 */ 	jr	$ra
/*    33630:	00000000 */ 	nop
);

void func00033634(void *fn)
{
	var8005f140 = fn;
}

GLOBAL_ASM(
glabel func0003364c
/*    3364c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33650:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33654:	afa40018 */ 	sw	$a0,0x18($sp)
/*    33658:	3c0e8006 */ 	lui	$t6,%hi(var8005f134)
/*    3365c:	8dcef134 */ 	lw	$t6,%lo(var8005f134)($t6)
/*    33660:	3c018006 */ 	lui	$at,%hi(var8005f134)
/*    33664:	25cfffff */ 	addiu	$t7,$t6,-1
/*    33668:	ac2ff134 */ 	sw	$t7,%lo(var8005f134)($at)
/*    3366c:	3c188006 */ 	lui	$t8,%hi(var8005f120)
/*    33670:	8f18f120 */ 	lw	$t8,%lo(var8005f120)($t8)
/*    33674:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33678:	17190005 */ 	bne	$t8,$t9,.L00033690
/*    3367c:	00000000 */ 	nop
/*    33680:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    33684:	3c018006 */ 	lui	$at,%hi(var8005f120)
/*    33688:	8d090000 */ 	lw	$t1,0x0($t0)
/*    3368c:	ac29f120 */ 	sw	$t1,%lo(var8005f120)($at)
.L00033690:
/*    33690:	3c0a8006 */ 	lui	$t2,%hi(var8005f124)
/*    33694:	8d4af124 */ 	lw	$t2,%lo(var8005f124)($t2)
/*    33698:	8fab0018 */ 	lw	$t3,0x18($sp)
/*    3369c:	154b0005 */ 	bne	$t2,$t3,.L000336b4
/*    336a0:	00000000 */ 	nop
/*    336a4:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    336a8:	3c018006 */ 	lui	$at,%hi(var8005f124)
/*    336ac:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    336b0:	ac2df124 */ 	sw	$t5,%lo(var8005f124)($at)
.L000336b4:
/*    336b4:	0c00c5e9 */ 	jal	alUnlink
/*    336b8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    336bc:	3c0e8006 */ 	lui	$t6,%hi(var8005f128)
/*    336c0:	8dcef128 */ 	lw	$t6,%lo(var8005f128)($t6)
/*    336c4:	11c0000f */ 	beqz	$t6,.L00033704
/*    336c8:	00000000 */ 	nop
/*    336cc:	3c0f8006 */ 	lui	$t7,%hi(var8005f128)
/*    336d0:	8deff128 */ 	lw	$t7,%lo(var8005f128)($t7)
/*    336d4:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    336d8:	af0f0000 */ 	sw	$t7,0x0($t8)
/*    336dc:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    336e0:	af200004 */ 	sw	$zero,0x4($t9)
/*    336e4:	3c098006 */ 	lui	$t1,%hi(var8005f128)
/*    336e8:	8d29f128 */ 	lw	$t1,%lo(var8005f128)($t1)
/*    336ec:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    336f0:	ad280004 */ 	sw	$t0,0x4($t1)
/*    336f4:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    336f8:	3c018006 */ 	lui	$at,%hi(var8005f128)
/*    336fc:	10000009 */ 	b	.L00033724
/*    33700:	ac2af128 */ 	sw	$t2,%lo(var8005f128)($at)
.L00033704:
/*    33704:	8fab0018 */ 	lw	$t3,0x18($sp)
/*    33708:	ad600004 */ 	sw	$zero,0x4($t3)
/*    3370c:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    33710:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    33714:	ad8d0000 */ 	sw	$t5,0x0($t4)
/*    33718:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    3371c:	3c018006 */ 	lui	$at,%hi(var8005f128)
/*    33720:	ac2ef128 */ 	sw	$t6,%lo(var8005f128)($at)
.L00033724:
/*    33724:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33728:	91f80044 */ 	lbu	$t8,0x44($t7)
/*    3372c:	33190004 */ 	andi	$t9,$t8,0x4
/*    33730:	13200006 */ 	beqz	$t9,.L0003374c
/*    33734:	00000000 */ 	nop
/*    33738:	3c088006 */ 	lui	$t0,%hi(var8005f130)
/*    3373c:	8508f130 */ 	lh	$t0,%lo(var8005f130)($t0)
/*    33740:	3c018006 */ 	lui	$at,%hi(var8005f130)
/*    33744:	2509ffff */ 	addiu	$t1,$t0,-1
/*    33748:	a429f130 */ 	sh	$t1,%lo(var8005f130)($at)
.L0003374c:
/*    3374c:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    33750:	a1400045 */ 	sb	$zero,0x45($t2)
/*    33754:	8fab0018 */ 	lw	$t3,0x18($sp)
/*    33758:	8d6d0030 */ 	lw	$t5,0x30($t3)
/*    3375c:	11a0000b */ 	beqz	$t5,.L0003378c
/*    33760:	00000000 */ 	nop
/*    33764:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    33768:	8d8e0030 */ 	lw	$t6,0x30($t4)
/*    3376c:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    33770:	15ec0004 */ 	bne	$t7,$t4,.L00033784
/*    33774:	00000000 */ 	nop
/*    33778:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    3377c:	8f190030 */ 	lw	$t9,0x30($t8)
/*    33780:	af200000 */ 	sw	$zero,0x0($t9)
.L00033784:
/*    33784:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    33788:	ad000030 */ 	sw	$zero,0x30($t0)
.L0003378c:
/*    3378c:	3c098006 */ 	lui	$t1,%hi(var8005f140)
/*    33790:	8d29f140 */ 	lw	$t1,%lo(var8005f140)($t1)
/*    33794:	11200006 */ 	beqz	$t1,.L000337b0
/*    33798:	00000000 */ 	nop
/*    3379c:	3c198006 */ 	lui	$t9,%hi(var8005f140)
/*    337a0:	8f39f140 */ 	lw	$t9,%lo(var8005f140)($t9)
/*    337a4:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    337a8:	0320f809 */ 	jalr	$t9
/*    337ac:	8d440008 */ 	lw	$a0,0x8($t2)
.L000337b0:
/*    337b0:	10000001 */ 	b	.L000337b8
/*    337b4:	00000000 */ 	nop
.L000337b8:
/*    337b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    337bc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    337c0:	03e00008 */ 	jr	$ra
/*    337c4:	00000000 */ 	nop
/*    337c8:	30a500ff */ 	andi	$a1,$a1,0xff
/*    337cc:	10800004 */ 	beqz	$a0,.L000337e0
/*    337d0:	00000000 */ 	nop
/*    337d4:	00057400 */ 	sll	$t6,$a1,0x10
/*    337d8:	000e7c03 */ 	sra	$t7,$t6,0x10
/*    337dc:	a08f0040 */ 	sb	$t7,0x40($a0)
.L000337e0:
/*    337e0:	03e00008 */ 	jr	$ra
/*    337e4:	00000000 */ 	nop
/*    337e8:	03e00008 */ 	jr	$ra
/*    337ec:	00000000 */ 	nop
);

bool audioIsPlaying(struct audiohandle *handle)
{
	if (handle) {
		return handle->playing;
	} else {
		return false;
	}
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00033820
/*    33820:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*    33824:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33828:	afa40060 */ 	sw	$a0,0x60($sp)
/*    3382c:	afa50064 */ 	sw	$a1,0x64($sp)
/*    33830:	afa60068 */ 	sw	$a2,0x68($sp)
/*    33834:	afa7006c */ 	sw	$a3,0x6c($sp)
/*    33838:	afa00058 */ 	sw	$zero,0x58($sp)
/*    3383c:	a7a0004e */ 	sh	$zero,0x4e($sp)
/*    33840:	afa00040 */ 	sw	$zero,0x40($sp)
/*    33844:	0c0040d8 */ 	jal	sndIsDisabled
/*    33848:	00000000 */ 	nop
/*    3384c:	10400003 */ 	beqz	$v0,.L0003385c
/*    33850:	00000000 */ 	nop
/*    33854:	100000af */ 	b	.L00033b14
/*    33858:	00001025 */ 	or	$v0,$zero,$zero
.L0003385c:
/*    3385c:	87ae0066 */ 	lh	$t6,0x66($sp)
/*    33860:	11c000a2 */ 	beqz	$t6,.L00033aec
/*    33864:	00000000 */ 	nop
.L00033868:
/*    33868:	0c003d27 */ 	jal	snd0000f49c
/*    3386c:	87a40066 */ 	lh	$a0,0x66($sp)
/*    33870:	afa20050 */ 	sw	$v0,0x50($sp)
/*    33874:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    33878:	0c00cce4 */ 	jal	func00033390
/*    3387c:	8fa50050 */ 	lw	$a1,0x50($sp)
/*    33880:	afa2005c */ 	sw	$v0,0x5c($sp)
/*    33884:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    33888:	11e00064 */ 	beqz	$t7,.L00033a1c
/*    3388c:	00000000 */ 	nop
/*    33890:	3c198006 */ 	lui	$t9,%hi(g_SndPlayer)
/*    33894:	8f39f12c */ 	lw	$t9,%lo(g_SndPlayer)($t9)
/*    33898:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    3389c:	af38003c */ 	sw	$t8,0x3c($t9)
/*    338a0:	24080001 */ 	addiu	$t0,$zero,0x1
/*    338a4:	a7a8002c */ 	sh	$t0,0x2c($sp)
/*    338a8:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    338ac:	afa90030 */ 	sw	$t1,0x30($sp)
/*    338b0:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    338b4:	93aa006f */ 	lbu	$t2,0x6f($sp)
/*    338b8:	916c0041 */ 	lbu	$t4,0x41($t3)
/*    338bc:	014c6821 */ 	addu	$t5,$t2,$t4
/*    338c0:	25aeffc0 */ 	addiu	$t6,$t5,-64
/*    338c4:	afae003c */ 	sw	$t6,0x3c($sp)
/*    338c8:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    338cc:	29e10080 */ 	slti	$at,$t7,0x80
/*    338d0:	14200004 */ 	bnez	$at,.L000338e4
/*    338d4:	00000000 */ 	nop
/*    338d8:	2418007f */ 	addiu	$t8,$zero,0x7f
/*    338dc:	10000005 */ 	b	.L000338f4
/*    338e0:	afb8003c */ 	sw	$t8,0x3c($sp)
.L000338e4:
/*    338e4:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    338e8:	07210002 */ 	bgez	$t9,.L000338f4
/*    338ec:	00000000 */ 	nop
/*    338f0:	afa0003c */ 	sw	$zero,0x3c($sp)
.L000338f4:
/*    338f4:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    338f8:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    338fc:	a1280041 */ 	sb	$t0,0x41($t1)
/*    33900:	8faa005c */ 	lw	$t2,0x5c($sp)
/*    33904:	97ab006a */ 	lhu	$t3,0x6a($sp)
/*    33908:	854c0038 */ 	lh	$t4,0x38($t2)
/*    3390c:	016c0019 */ 	multu	$t3,$t4
/*    33910:	00006812 */ 	mflo	$t5
/*    33914:	000d73c2 */ 	srl	$t6,$t5,0xf
/*    33918:	a54e0038 */ 	sh	$t6,0x38($t2)
/*    3391c:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    33920:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*    33924:	c5e4002c */ 	lwc1	$f4,0x2c($t7)
/*    33928:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    3392c:	e5e8002c */ 	swc1	$f8,0x2c($t7)
/*    33930:	93b80077 */ 	lbu	$t8,0x77($sp)
/*    33934:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    33938:	a3380042 */ 	sb	$t8,0x42($t9)
/*    3393c:	93a8007b */ 	lbu	$t0,0x7b($sp)
/*    33940:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    33944:	a1280043 */ 	sb	$t0,0x43($t1)
/*    33948:	87ab0066 */ 	lh	$t3,0x66($sp)
/*    3394c:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    33950:	a58b0046 */ 	sh	$t3,0x46($t4)
/*    33954:	8fad005c */ 	lw	$t5,0x5c($sp)
/*    33958:	ada00048 */ 	sw	$zero,0x48($t5)
/*    3395c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    33960:	8dca0004 */ 	lw	$t2,0x4($t6)
/*    33964:	914f0001 */ 	lbu	$t7,0x1($t2)
/*    33968:	000fc180 */ 	sll	$t8,$t7,0x6
/*    3396c:	030fc021 */ 	addu	$t8,$t8,$t7
/*    33970:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    33974:	030fc021 */ 	addu	$t8,$t8,$t7
/*    33978:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3397c:	030fc023 */ 	subu	$t8,$t8,$t7
/*    33980:	0018c080 */ 	sll	$t8,$t8,0x2
/*    33984:	030fc021 */ 	addu	$t8,$t8,$t7
/*    33988:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3398c:	030fc021 */ 	addu	$t8,$t8,$t7
/*    33990:	afb80044 */ 	sw	$t8,0x44($sp)
/*    33994:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    33998:	93280044 */ 	lbu	$t0,0x44($t9)
/*    3399c:	31090010 */ 	andi	$t1,$t0,0x10
/*    339a0:	11200014 */ 	beqz	$t1,.L000339f4
/*    339a4:	00000000 */ 	nop
/*    339a8:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    339ac:	2401ffef */ 	addiu	$at,$zero,-17
/*    339b0:	916c0044 */ 	lbu	$t4,0x44($t3)
/*    339b4:	01816824 */ 	and	$t5,$t4,$at
/*    339b8:	a16d0044 */ 	sb	$t5,0x44($t3)
/*    339bc:	3c048006 */ 	lui	$a0,%hi(g_SndPlayer)
/*    339c0:	8c84f12c */ 	lw	$a0,%lo(g_SndPlayer)($a0)
/*    339c4:	8fa60040 */ 	lw	$a2,0x40($sp)
/*    339c8:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*    339cc:	00003825 */ 	or	$a3,$zero,$zero
/*    339d0:	24840014 */ 	addiu	$a0,$a0,20
/*    339d4:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    339d8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*    339dc:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    339e0:	25ca0001 */ 	addiu	$t2,$t6,0x1
/*    339e4:	afaa0048 */ 	sw	$t2,0x48($sp)
/*    339e8:	87af0066 */ 	lh	$t7,0x66($sp)
/*    339ec:	10000009 */ 	b	.L00033a14
/*    339f0:	a7af004e */ 	sh	$t7,0x4e($sp)
.L000339f4:
/*    339f4:	3c048006 */ 	lui	$a0,%hi(g_SndPlayer)
/*    339f8:	8c84f12c */ 	lw	$a0,%lo(g_SndPlayer)($a0)
/*    339fc:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    33a00:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*    33a04:	00003825 */ 	or	$a3,$zero,$zero
/*    33a08:	24840014 */ 	addiu	$a0,$a0,20
/*    33a0c:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    33a10:	24c60001 */ 	addiu	$a2,$a2,0x1
.L00033a14:
/*    33a14:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    33a18:	afb80058 */ 	sw	$t8,0x58($sp)
.L00033a1c:
/*    33a1c:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    33a20:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    33a24:	03284821 */ 	addu	$t1,$t9,$t0
/*    33a28:	afa90040 */ 	sw	$t1,0x40($sp)
/*    33a2c:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    33a30:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    33a34:	afad0054 */ 	sw	$t5,0x54($sp)
/*    33a38:	8fab0054 */ 	lw	$t3,0x54($sp)
/*    33a3c:	916a0002 */ 	lbu	$t2,0x2($t3)
/*    33a40:	916e0000 */ 	lbu	$t6,0x0($t3)
/*    33a44:	314f00c0 */ 	andi	$t7,$t2,0xc0
/*    33a48:	000fc080 */ 	sll	$t8,$t7,0x2
/*    33a4c:	01d8c821 */ 	addu	$t9,$t6,$t8
/*    33a50:	a7b90066 */ 	sh	$t9,0x66($sp)
/*    33a54:	87a80066 */ 	lh	$t0,0x66($sp)
/*    33a58:	11000004 */ 	beqz	$t0,.L00033a6c
/*    33a5c:	00000000 */ 	nop
/*    33a60:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    33a64:	1520ff80 */ 	bnez	$t1,.L00033868
/*    33a68:	00000000 */ 	nop
.L00033a6c:
/*    33a6c:	8fac0058 */ 	lw	$t4,0x58($sp)
/*    33a70:	1180001e */ 	beqz	$t4,.L00033aec
/*    33a74:	00000000 */ 	nop
/*    33a78:	8fad0058 */ 	lw	$t5,0x58($sp)
/*    33a7c:	91ab0044 */ 	lbu	$t3,0x44($t5)
/*    33a80:	356a0001 */ 	ori	$t2,$t3,0x1
/*    33a84:	a1aa0044 */ 	sb	$t2,0x44($t5)
/*    33a88:	8faf007c */ 	lw	$t7,0x7c($sp)
/*    33a8c:	8fae0058 */ 	lw	$t6,0x58($sp)
/*    33a90:	adcf0030 */ 	sw	$t7,0x30($t6)
/*    33a94:	87b8004e */ 	lh	$t8,0x4e($sp)
/*    33a98:	13000014 */ 	beqz	$t8,.L00033aec
/*    33a9c:	00000000 */ 	nop
/*    33aa0:	8fb90058 */ 	lw	$t9,0x58($sp)
/*    33aa4:	93280044 */ 	lbu	$t0,0x44($t9)
/*    33aa8:	35090010 */ 	ori	$t1,$t0,0x10
/*    33aac:	a3290044 */ 	sb	$t1,0x44($t9)
/*    33ab0:	240c0200 */ 	addiu	$t4,$zero,0x200
/*    33ab4:	a7ac001c */ 	sh	$t4,0x1c($sp)
/*    33ab8:	8fab0058 */ 	lw	$t3,0x58($sp)
/*    33abc:	afab0020 */ 	sw	$t3,0x20($sp)
/*    33ac0:	87aa004e */ 	lh	$t2,0x4e($sp)
/*    33ac4:	afaa0024 */ 	sw	$t2,0x24($sp)
/*    33ac8:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    33acc:	afad0028 */ 	sw	$t5,0x28($sp)
/*    33ad0:	3c048006 */ 	lui	$a0,%hi(g_SndPlayer)
/*    33ad4:	8c84f12c */ 	lw	$a0,%lo(g_SndPlayer)($a0)
/*    33ad8:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    33adc:	8fa60048 */ 	lw	$a2,0x48($sp)
/*    33ae0:	00003825 */ 	or	$a3,$zero,$zero
/*    33ae4:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    33ae8:	24840014 */ 	addiu	$a0,$a0,20
.L00033aec:
/*    33aec:	8faf007c */ 	lw	$t7,0x7c($sp)
/*    33af0:	11e00004 */ 	beqz	$t7,.L00033b04
/*    33af4:	00000000 */ 	nop
/*    33af8:	8fae0058 */ 	lw	$t6,0x58($sp)
/*    33afc:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*    33b00:	af0e0000 */ 	sw	$t6,0x0($t8)
.L00033b04:
/*    33b04:	10000003 */ 	b	.L00033b14
/*    33b08:	8fa20058 */ 	lw	$v0,0x58($sp)
/*    33b0c:	10000001 */ 	b	.L00033b14
/*    33b10:	00000000 */ 	nop
.L00033b14:
/*    33b14:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33b18:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*    33b1c:	03e00008 */ 	jr	$ra
/*    33b20:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func00033820
/*    34db0:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*    34db4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    34db8:	afa40060 */ 	sw	$a0,0x60($sp)
/*    34dbc:	afa50064 */ 	sw	$a1,0x64($sp)
/*    34dc0:	afa60068 */ 	sw	$a2,0x68($sp)
/*    34dc4:	afa7006c */ 	sw	$a3,0x6c($sp)
/*    34dc8:	afa00058 */ 	sw	$zero,0x58($sp)
/*    34dcc:	a7a0004e */ 	sh	$zero,0x4e($sp)
/*    34dd0:	afa00040 */ 	sw	$zero,0x40($sp)
/*    34dd4:	0c0041df */ 	jal	sndIsDisabled
/*    34dd8:	00000000 */ 	sll	$zero,$zero,0x0
/*    34ddc:	10400003 */ 	beqz	$v0,.NB00034dec
/*    34de0:	00000000 */ 	sll	$zero,$zero,0x0
/*    34de4:	100000aa */ 	beqz	$zero,.NB00035090
/*    34de8:	00001025 */ 	or	$v0,$zero,$zero
.NB00034dec:
/*    34dec:	87ae0066 */ 	lh	$t6,0x66($sp)
/*    34df0:	11c0009d */ 	beqz	$t6,.NB00035068
/*    34df4:	00000000 */ 	sll	$zero,$zero,0x0
.NB00034df8:
/*    34df8:	0c003e46 */ 	jal	snd0000f49c
/*    34dfc:	87a40066 */ 	lh	$a0,0x66($sp)
/*    34e00:	afa20050 */ 	sw	$v0,0x50($sp)
/*    34e04:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    34e08:	0c00d248 */ 	jal	func00033390
/*    34e0c:	8fa50050 */ 	lw	$a1,0x50($sp)
/*    34e10:	afa2005c */ 	sw	$v0,0x5c($sp)
/*    34e14:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    34e18:	11e0005f */ 	beqz	$t7,.NB00034f98
/*    34e1c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34e20:	3c198006 */ 	lui	$t9,0x8006
/*    34e24:	8f39163c */ 	lw	$t9,0x163c($t9)
/*    34e28:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    34e2c:	af38003c */ 	sw	$t8,0x3c($t9)
/*    34e30:	24080001 */ 	addiu	$t0,$zero,0x1
/*    34e34:	a7a8002c */ 	sh	$t0,0x2c($sp)
/*    34e38:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    34e3c:	afa90030 */ 	sw	$t1,0x30($sp)
/*    34e40:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    34e44:	93aa006f */ 	lbu	$t2,0x6f($sp)
/*    34e48:	916c0041 */ 	lbu	$t4,0x41($t3)
/*    34e4c:	014c6821 */ 	addu	$t5,$t2,$t4
/*    34e50:	25aeffc0 */ 	addiu	$t6,$t5,-64
/*    34e54:	afae003c */ 	sw	$t6,0x3c($sp)
/*    34e58:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    34e5c:	29e10080 */ 	slti	$at,$t7,0x80
/*    34e60:	14200004 */ 	bnez	$at,.NB00034e74
/*    34e64:	00000000 */ 	sll	$zero,$zero,0x0
/*    34e68:	2418007f */ 	addiu	$t8,$zero,0x7f
/*    34e6c:	10000005 */ 	beqz	$zero,.NB00034e84
/*    34e70:	afb8003c */ 	sw	$t8,0x3c($sp)
.NB00034e74:
/*    34e74:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    34e78:	07210002 */ 	bgez	$t9,.NB00034e84
/*    34e7c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34e80:	afa0003c */ 	sw	$zero,0x3c($sp)
.NB00034e84:
/*    34e84:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    34e88:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    34e8c:	a1280041 */ 	sb	$t0,0x41($t1)
/*    34e90:	8faa005c */ 	lw	$t2,0x5c($sp)
/*    34e94:	97ab006a */ 	lhu	$t3,0x6a($sp)
/*    34e98:	854c0038 */ 	lh	$t4,0x38($t2)
/*    34e9c:	016c0019 */ 	multu	$t3,$t4
/*    34ea0:	00006812 */ 	mflo	$t5
/*    34ea4:	000d73c2 */ 	srl	$t6,$t5,0xf
/*    34ea8:	a54e0038 */ 	sh	$t6,0x38($t2)
/*    34eac:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    34eb0:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*    34eb4:	c5e4002c */ 	lwc1	$f4,0x2c($t7)
/*    34eb8:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    34ebc:	e5e8002c */ 	swc1	$f8,0x2c($t7)
/*    34ec0:	93b80077 */ 	lbu	$t8,0x77($sp)
/*    34ec4:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    34ec8:	a3380042 */ 	sb	$t8,0x42($t9)
/*    34ecc:	93a8007b */ 	lbu	$t0,0x7b($sp)
/*    34ed0:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    34ed4:	a1280043 */ 	sb	$t0,0x43($t1)
/*    34ed8:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    34edc:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*    34ee0:	918d0001 */ 	lbu	$t5,0x1($t4)
/*    34ee4:	000d7180 */ 	sll	$t6,$t5,0x6
/*    34ee8:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    34eec:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    34ef0:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    34ef4:	000e7080 */ 	sll	$t6,$t6,0x2
/*    34ef8:	01cd7023 */ 	subu	$t6,$t6,$t5
/*    34efc:	000e7080 */ 	sll	$t6,$t6,0x2
/*    34f00:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    34f04:	000e7080 */ 	sll	$t6,$t6,0x2
/*    34f08:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    34f0c:	afae0044 */ 	sw	$t6,0x44($sp)
/*    34f10:	8faa005c */ 	lw	$t2,0x5c($sp)
/*    34f14:	914f0044 */ 	lbu	$t7,0x44($t2)
/*    34f18:	31f80010 */ 	andi	$t8,$t7,0x10
/*    34f1c:	13000014 */ 	beqz	$t8,.NB00034f70
/*    34f20:	00000000 */ 	sll	$zero,$zero,0x0
/*    34f24:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    34f28:	2401ffef */ 	addiu	$at,$zero,-17
/*    34f2c:	93280044 */ 	lbu	$t0,0x44($t9)
/*    34f30:	01014824 */ 	and	$t1,$t0,$at
/*    34f34:	a3290044 */ 	sb	$t1,0x44($t9)
/*    34f38:	3c048006 */ 	lui	$a0,0x8006
/*    34f3c:	8c84163c */ 	lw	$a0,0x163c($a0)
/*    34f40:	8fa60040 */ 	lw	$a2,0x40($sp)
/*    34f44:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*    34f48:	00003825 */ 	or	$a3,$zero,$zero
/*    34f4c:	24840014 */ 	addiu	$a0,$a0,0x14
/*    34f50:	0c00f678 */ 	jal	n_alEvtqPostEvent
/*    34f54:	24c60001 */ 	addiu	$a2,$a2,0x1
/*    34f58:	8fab0044 */ 	lw	$t3,0x44($sp)
/*    34f5c:	256c0001 */ 	addiu	$t4,$t3,0x1
/*    34f60:	afac0048 */ 	sw	$t4,0x48($sp)
/*    34f64:	87ad0066 */ 	lh	$t5,0x66($sp)
/*    34f68:	10000009 */ 	beqz	$zero,.NB00034f90
/*    34f6c:	a7ad004e */ 	sh	$t5,0x4e($sp)
.NB00034f70:
/*    34f70:	3c048006 */ 	lui	$a0,0x8006
/*    34f74:	8c84163c */ 	lw	$a0,0x163c($a0)
/*    34f78:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    34f7c:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*    34f80:	00003825 */ 	or	$a3,$zero,$zero
/*    34f84:	24840014 */ 	addiu	$a0,$a0,0x14
/*    34f88:	0c00f678 */ 	jal	n_alEvtqPostEvent
/*    34f8c:	24c60001 */ 	addiu	$a2,$a2,0x1
.NB00034f90:
/*    34f90:	8fae005c */ 	lw	$t6,0x5c($sp)
/*    34f94:	afae0058 */ 	sw	$t6,0x58($sp)
.NB00034f98:
/*    34f98:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    34f9c:	8faf0044 */ 	lw	$t7,0x44($sp)
/*    34fa0:	014fc021 */ 	addu	$t8,$t2,$t7
/*    34fa4:	afb80040 */ 	sw	$t8,0x40($sp)
/*    34fa8:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    34fac:	8d090004 */ 	lw	$t1,0x4($t0)
/*    34fb0:	afa90054 */ 	sw	$t1,0x54($sp)
/*    34fb4:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    34fb8:	932c0002 */ 	lbu	$t4,0x2($t9)
/*    34fbc:	932b0000 */ 	lbu	$t3,0x0($t9)
/*    34fc0:	318d00c0 */ 	andi	$t5,$t4,0xc0
/*    34fc4:	000d7080 */ 	sll	$t6,$t5,0x2
/*    34fc8:	016e5021 */ 	addu	$t2,$t3,$t6
/*    34fcc:	a7aa0066 */ 	sh	$t2,0x66($sp)
/*    34fd0:	87af0066 */ 	lh	$t7,0x66($sp)
/*    34fd4:	11e00004 */ 	beqz	$t7,.NB00034fe8
/*    34fd8:	00000000 */ 	sll	$zero,$zero,0x0
/*    34fdc:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    34fe0:	1700ff85 */ 	bnez	$t8,.NB00034df8
/*    34fe4:	00000000 */ 	sll	$zero,$zero,0x0
.NB00034fe8:
/*    34fe8:	8fa80058 */ 	lw	$t0,0x58($sp)
/*    34fec:	1100001e */ 	beqz	$t0,.NB00035068
/*    34ff0:	00000000 */ 	sll	$zero,$zero,0x0
/*    34ff4:	8fa90058 */ 	lw	$t1,0x58($sp)
/*    34ff8:	91390044 */ 	lbu	$t9,0x44($t1)
/*    34ffc:	372c0001 */ 	ori	$t4,$t9,0x1
/*    35000:	a12c0044 */ 	sb	$t4,0x44($t1)
/*    35004:	8fad007c */ 	lw	$t5,0x7c($sp)
/*    35008:	8fab0058 */ 	lw	$t3,0x58($sp)
/*    3500c:	ad6d0030 */ 	sw	$t5,0x30($t3)
/*    35010:	87ae004e */ 	lh	$t6,0x4e($sp)
/*    35014:	11c00014 */ 	beqz	$t6,.NB00035068
/*    35018:	00000000 */ 	sll	$zero,$zero,0x0
/*    3501c:	8faa0058 */ 	lw	$t2,0x58($sp)
/*    35020:	914f0044 */ 	lbu	$t7,0x44($t2)
/*    35024:	35f80010 */ 	ori	$t8,$t7,0x10
/*    35028:	a1580044 */ 	sb	$t8,0x44($t2)
/*    3502c:	24080200 */ 	addiu	$t0,$zero,0x200
/*    35030:	a7a8001c */ 	sh	$t0,0x1c($sp)
/*    35034:	8fb90058 */ 	lw	$t9,0x58($sp)
/*    35038:	afb90020 */ 	sw	$t9,0x20($sp)
/*    3503c:	87ac004e */ 	lh	$t4,0x4e($sp)
/*    35040:	afac0024 */ 	sw	$t4,0x24($sp)
/*    35044:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    35048:	afa90028 */ 	sw	$t1,0x28($sp)
/*    3504c:	3c048006 */ 	lui	$a0,0x8006
/*    35050:	8c84163c */ 	lw	$a0,0x163c($a0)
/*    35054:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    35058:	8fa60048 */ 	lw	$a2,0x48($sp)
/*    3505c:	00003825 */ 	or	$a3,$zero,$zero
/*    35060:	0c00f678 */ 	jal	n_alEvtqPostEvent
/*    35064:	24840014 */ 	addiu	$a0,$a0,0x14
.NB00035068:
/*    35068:	8fad007c */ 	lw	$t5,0x7c($sp)
/*    3506c:	11a00004 */ 	beqz	$t5,.NB00035080
/*    35070:	00000000 */ 	sll	$zero,$zero,0x0
/*    35074:	8fab0058 */ 	lw	$t3,0x58($sp)
/*    35078:	8fae007c */ 	lw	$t6,0x7c($sp)
/*    3507c:	adcb0000 */ 	sw	$t3,0x0($t6)
.NB00035080:
/*    35080:	10000003 */ 	beqz	$zero,.NB00035090
/*    35084:	8fa20058 */ 	lw	$v0,0x58($sp)
/*    35088:	10000001 */ 	beqz	$zero,.NB00035090
/*    3508c:	00000000 */ 	sll	$zero,$zero,0x0
.NB00035090:
/*    35090:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    35094:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*    35098:	03e00008 */ 	jr	$ra
/*    3509c:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

void audioStop(struct audiohandle *handle)
{
	N_ALEvent evt;

#if VERSION >= VERSION_NTSC_FINAL
	if (handle && (handle->unk44 & 2)) {
		func00033bc0(handle);
	} else {
		evt.type = AL_400_EVT;
		evt.msg.evt400.handle = handle;

		if (handle != NULL) {
			evt.msg.evt400.handle->unk44 &= ~0x10;

			n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, 0, 0);
		}
	}
#elif VERSION >= VERSION_NTSC_1_0
	// NTSC 1.0 lacks the null handle check
	if (handle->unk44 & 2) {
		func00033bc0(handle);
	} else {
		evt.type = AL_400_EVT;
		evt.msg.evt400.handle = handle;

		if (handle != NULL) {
			evt.msg.evt400.handle->unk44 &= ~0x10;

			n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, 0, 0);
		}
	}
#else
	evt.type = AL_400_EVT;
	evt.msg.evt400.handle = handle;

	if (handle != NULL) {
		evt.msg.evt400.handle->unk44 &= ~0x10;

		n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, 0, 0);
	}
#endif
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00033bc0
/*    33bc0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    33bc4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33bc8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    33bcc:	240e0080 */ 	addiu	$t6,$zero,0x80
/*    33bd0:	a7ae0018 */ 	sh	$t6,0x18($sp)
/*    33bd4:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    33bd8:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    33bdc:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    33be0:	1300000d */ 	beqz	$t8,.L00033c18
/*    33be4:	00000000 */ 	nop
/*    33be8:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    33bec:	2401ffef */ 	addiu	$at,$zero,-17
/*    33bf0:	93280044 */ 	lbu	$t0,0x44($t9)
/*    33bf4:	01014824 */ 	and	$t1,$t0,$at
/*    33bf8:	a3290044 */ 	sb	$t1,0x44($t9)
/*    33bfc:	3c048006 */ 	lui	$a0,%hi(g_SndPlayer)
/*    33c00:	8c84f12c */ 	lw	$a0,%lo(g_SndPlayer)($a0)
/*    33c04:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    33c08:	00003025 */ 	or	$a2,$zero,$zero
/*    33c0c:	00003825 */ 	or	$a3,$zero,$zero
/*    33c10:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    33c14:	24840014 */ 	addiu	$a0,$a0,20
.L00033c18:
/*    33c18:	10000001 */ 	b	.L00033c20
/*    33c1c:	00000000 */ 	nop
.L00033c20:
/*    33c20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33c24:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    33c28:	03e00008 */ 	jr	$ra
/*    33c2c:	00000000 */ 	nop
);
#endif

GLOBAL_ASM(
glabel func00033c30
/*    33c30:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33c34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33c38:	afa40030 */ 	sw	$a0,0x30($sp)
/*    33c3c:	0c012194 */ 	jal	osSetIntMask
/*    33c40:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33c44:	afa2002c */ 	sw	$v0,0x2c($sp)
/*    33c48:	3c0e8006 */ 	lui	$t6,%hi(var8005f120)
/*    33c4c:	8dcef120 */ 	lw	$t6,%lo(var8005f120)($t6)
/*    33c50:	afae0018 */ 	sw	$t6,0x18($sp)
/*    33c54:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33c58:	11e0001d */ 	beqz	$t7,.L00033cd0
/*    33c5c:	00000000 */ 	nop
.L00033c60:
/*    33c60:	24180400 */ 	addiu	$t8,$zero,0x400
/*    33c64:	a7b8001c */ 	sh	$t8,0x1c($sp)
/*    33c68:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33c6c:	afb90020 */ 	sw	$t9,0x20($sp)
/*    33c70:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    33c74:	93aa0033 */ 	lbu	$t2,0x33($sp)
/*    33c78:	91090044 */ 	lbu	$t1,0x44($t0)
/*    33c7c:	012a5824 */ 	and	$t3,$t1,$t2
/*    33c80:	156a000d */ 	bne	$t3,$t2,.L00033cb8
/*    33c84:	00000000 */ 	nop
/*    33c88:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    33c8c:	2401ffef */ 	addiu	$at,$zero,-17
/*    33c90:	918d0044 */ 	lbu	$t5,0x44($t4)
/*    33c94:	01a17024 */ 	and	$t6,$t5,$at
/*    33c98:	a18e0044 */ 	sb	$t6,0x44($t4)
/*    33c9c:	3c048006 */ 	lui	$a0,%hi(g_SndPlayer)
/*    33ca0:	8c84f12c */ 	lw	$a0,%lo(g_SndPlayer)($a0)
/*    33ca4:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    33ca8:	00003025 */ 	or	$a2,$zero,$zero
/*    33cac:	00003825 */ 	or	$a3,$zero,$zero
/*    33cb0:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    33cb4:	24840014 */ 	addiu	$a0,$a0,20
.L00033cb8:
/*    33cb8:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33cbc:	8df80000 */ 	lw	$t8,0x0($t7)
/*    33cc0:	afb80018 */ 	sw	$t8,0x18($sp)
/*    33cc4:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33cc8:	1720ffe5 */ 	bnez	$t9,.L00033c60
/*    33ccc:	00000000 */ 	nop
.L00033cd0:
/*    33cd0:	0c012194 */ 	jal	osSetIntMask
/*    33cd4:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33cd8:	10000001 */ 	b	.L00033ce0
/*    33cdc:	00000000 */ 	nop
.L00033ce0:
/*    33ce0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33ce4:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    33ce8:	03e00008 */ 	jr	$ra
/*    33cec:	00000000 */ 	nop
);

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00033cf0
/*    33cf0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33cf4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33cf8:	afa40030 */ 	sw	$a0,0x30($sp)
/*    33cfc:	0c012194 */ 	jal	osSetIntMask
/*    33d00:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33d04:	afa2002c */ 	sw	$v0,0x2c($sp)
/*    33d08:	3c0e8006 */ 	lui	$t6,%hi(var8005f120)
/*    33d0c:	8dcef120 */ 	lw	$t6,%lo(var8005f120)($t6)
/*    33d10:	afae0018 */ 	sw	$t6,0x18($sp)
/*    33d14:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33d18:	11e0001d */ 	beqz	$t7,.L00033d90
/*    33d1c:	00000000 */ 	nop
.L00033d20:
/*    33d20:	24180080 */ 	addiu	$t8,$zero,0x80
/*    33d24:	a7b8001c */ 	sh	$t8,0x1c($sp)
/*    33d28:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33d2c:	afb90020 */ 	sw	$t9,0x20($sp)
/*    33d30:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    33d34:	93aa0033 */ 	lbu	$t2,0x33($sp)
/*    33d38:	91090044 */ 	lbu	$t1,0x44($t0)
/*    33d3c:	012a5824 */ 	and	$t3,$t1,$t2
/*    33d40:	156a000d */ 	bne	$t3,$t2,.L00033d78
/*    33d44:	00000000 */ 	nop
/*    33d48:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    33d4c:	2401ffef */ 	addiu	$at,$zero,-17
/*    33d50:	918d0044 */ 	lbu	$t5,0x44($t4)
/*    33d54:	01a17024 */ 	and	$t6,$t5,$at
/*    33d58:	a18e0044 */ 	sb	$t6,0x44($t4)
/*    33d5c:	3c048006 */ 	lui	$a0,%hi(g_SndPlayer)
/*    33d60:	8c84f12c */ 	lw	$a0,%lo(g_SndPlayer)($a0)
/*    33d64:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    33d68:	00003025 */ 	or	$a2,$zero,$zero
/*    33d6c:	00003825 */ 	or	$a3,$zero,$zero
/*    33d70:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    33d74:	24840014 */ 	addiu	$a0,$a0,20
.L00033d78:
/*    33d78:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33d7c:	8df80000 */ 	lw	$t8,0x0($t7)
/*    33d80:	afb80018 */ 	sw	$t8,0x18($sp)
/*    33d84:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33d88:	1720ffe5 */ 	bnez	$t9,.L00033d20
/*    33d8c:	00000000 */ 	nop
.L00033d90:
/*    33d90:	0c012194 */ 	jal	osSetIntMask
/*    33d94:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33d98:	10000001 */ 	b	.L00033da0
/*    33d9c:	00000000 */ 	nop
.L00033da0:
/*    33da0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33da4:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    33da8:	03e00008 */ 	jr	$ra
/*    33dac:	00000000 */ 	nop
);
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00033db0
/*    33db0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33db4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33db8:	0c00cf3c */ 	jal	func00033cf0
/*    33dbc:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33dc0:	10000001 */ 	b	.L00033dc8
/*    33dc4:	00000000 */ 	nop
.L00033dc8:
/*    33dc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33dcc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    33dd0:	03e00008 */ 	jr	$ra
/*    33dd4:	00000000 */ 	nop
);
#endif

GLOBAL_ASM(
glabel func00033dd8
/*    33dd8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33ddc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33de0:	0c00cf0c */ 	jal	func00033c30
/*    33de4:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33de8:	10000001 */ 	b	.L00033df0
/*    33dec:	00000000 */ 	nop
.L00033df0:
/*    33df0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33df4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    33df8:	03e00008 */ 	jr	$ra
/*    33dfc:	00000000 */ 	nop
/*    33e00:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33e04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33e08:	0c00cf0c */ 	jal	func00033c30
/*    33e0c:	24040011 */ 	addiu	$a0,$zero,0x11
/*    33e10:	10000001 */ 	b	.L00033e18
/*    33e14:	00000000 */ 	nop
.L00033e18:
/*    33e18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33e1c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    33e20:	03e00008 */ 	jr	$ra
/*    33e24:	00000000 */ 	nop
/*    33e28:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33e2c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33e30:	0c00cf0c */ 	jal	func00033c30
/*    33e34:	24040003 */ 	addiu	$a0,$zero,0x3
/*    33e38:	10000001 */ 	b	.L00033e40
/*    33e3c:	00000000 */ 	nop
.L00033e40:
/*    33e40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33e44:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    33e48:	03e00008 */ 	jr	$ra
/*    33e4c:	00000000 */ 	nop
);

void audioPostEvent(struct audiohandle *handle, s16 type, s32 data)
{
	N_ALEvent evt;

	evt.type = type;
	evt.msg.generic.handle = handle;
	evt.msg.generic.data = data;

	if (handle) {
		n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, 0, 0);
	} else {
		// empty
	}
}

GLOBAL_ASM(
glabel func00033ec4
/*    33ec4:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    33ec8:	308400ff */ 	andi	$a0,$a0,0xff
/*    33ecc:	3c0e800a */ 	lui	$t6,%hi(var8009c334)
/*    33ed0:	8dcec334 */ 	lw	$t6,%lo(var8009c334)($t6)
/*    33ed4:	11c00005 */ 	beqz	$t6,.L00033eec
/*    33ed8:	00000000 */ 	nop
/*    33edc:	00047840 */ 	sll	$t7,$a0,0x1
/*    33ee0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    33ee4:	10000002 */ 	b	.L00033ef0
/*    33ee8:	87050000 */ 	lh	$a1,0x0($t8)
.L00033eec:
/*    33eec:	00002825 */ 	or	$a1,$zero,$zero
.L00033ef0:
/*    33ef0:	10000003 */ 	b	.L00033f00
/*    33ef4:	30a2ffff */ 	andi	$v0,$a1,0xffff
/*    33ef8:	10000001 */ 	b	.L00033f00
/*    33efc:	00000000 */ 	nop
.L00033f00:
/*    33f00:	03e00008 */ 	jr	$ra
/*    33f04:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00033f08
/*    33f08:	3c028006 */ 	lui	$v0,%hi(var8005f120)
/*    33f0c:	03e00008 */ 	jr	$ra
/*    33f10:	8c42f120 */ 	lw	$v0,%lo(var8005f120)($v0)
/*    33f14:	03e00008 */ 	jr	$ra
/*    33f18:	00000000 */ 	nop
/*    33f1c:	03e00008 */ 	jr	$ra
/*    33f20:	00000000 */ 	nop
);
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00033f24
/*    33f24:	3c0e8006 */ 	lui	$t6,%hi(g_SndPlayer)
/*    33f28:	8dcef12c */ 	lw	$t6,%lo(g_SndPlayer)($t6)
/*    33f2c:	03e00008 */ 	jr	$ra
/*    33f30:	8dc20050 */ 	lw	$v0,0x50($t6)
/*    33f34:	03e00008 */ 	jr	$ra
/*    33f38:	00000000 */ 	nop
/*    33f3c:	03e00008 */ 	jr	$ra
/*    33f40:	00000000 */ 	nop
);
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00033f44
/*    33f44:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    33f48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33f4c:	afa40038 */ 	sw	$a0,0x38($sp)
/*    33f50:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    33f54:	3c0e800a */ 	lui	$t6,%hi(var8009c334)
/*    33f58:	8dcec334 */ 	lw	$t6,%lo(var8009c334)($t6)
/*    33f5c:	11c0002e */ 	beqz	$t6,.L00034018
/*    33f60:	00000000 */ 	nop
/*    33f64:	0c012194 */ 	jal	osSetIntMask
/*    33f68:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33f6c:	afa20034 */ 	sw	$v0,0x34($sp)
/*    33f70:	3c0f8006 */ 	lui	$t7,%hi(var8005f120)
/*    33f74:	8deff120 */ 	lw	$t7,%lo(var8005f120)($t7)
/*    33f78:	afaf0030 */ 	sw	$t7,0x30($sp)
/*    33f7c:	93a8003b */ 	lbu	$t0,0x3b($sp)
/*    33f80:	3c19800a */ 	lui	$t9,%hi(var8009c334)
/*    33f84:	8f39c334 */ 	lw	$t9,%lo(var8009c334)($t9)
/*    33f88:	97b8003e */ 	lhu	$t8,0x3e($sp)
/*    33f8c:	00084840 */ 	sll	$t1,$t0,0x1
/*    33f90:	03295021 */ 	addu	$t2,$t9,$t1
/*    33f94:	a5580000 */ 	sh	$t8,0x0($t2)
/*    33f98:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    33f9c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*    33fa0:	1160001b */ 	beqz	$t3,.L00034010
/*    33fa4:	00000000 */ 	nop
.L00033fa8:
/*    33fa8:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    33fac:	93b9003b */ 	lbu	$t9,0x3b($sp)
/*    33fb0:	8d8d0008 */ 	lw	$t5,0x8($t4)
/*    33fb4:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    33fb8:	91cf0002 */ 	lbu	$t7,0x2($t6)
/*    33fbc:	31e8001f */ 	andi	$t0,$t7,0x1f
/*    33fc0:	1519000c */ 	bne	$t0,$t9,.L00033ff4
/*    33fc4:	00000000 */ 	nop
/*    33fc8:	24090800 */ 	addiu	$t1,$zero,0x800
/*    33fcc:	a7a9001c */ 	sh	$t1,0x1c($sp)
/*    33fd0:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    33fd4:	afb80020 */ 	sw	$t8,0x20($sp)
/*    33fd8:	3c048006 */ 	lui	$a0,%hi(g_SndPlayer)
/*    33fdc:	8c84f12c */ 	lw	$a0,%lo(g_SndPlayer)($a0)
/*    33fe0:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    33fe4:	00003025 */ 	or	$a2,$zero,$zero
/*    33fe8:	00003825 */ 	or	$a3,$zero,$zero
/*    33fec:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    33ff0:	24840014 */ 	addiu	$a0,$a0,20
.L00033ff4:
/*    33ff4:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    33ff8:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    33ffc:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    34000:	afab002c */ 	sw	$t3,0x2c($sp)
/*    34004:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    34008:	15a0ffe7 */ 	bnez	$t5,.L00033fa8
/*    3400c:	afad0030 */ 	sw	$t5,0x30($sp)
.L00034010:
/*    34010:	0c012194 */ 	jal	osSetIntMask
/*    34014:	8fa40034 */ 	lw	$a0,0x34($sp)
.L00034018:
/*    34018:	10000001 */ 	b	.L00034020
/*    3401c:	00000000 */ 	nop
.L00034020:
/*    34020:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    34024:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    34028:	03e00008 */ 	jr	$ra
/*    3402c:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func00033f44
/*    35300:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    35304:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    35308:	afa40038 */ 	sw	$a0,0x38($sp)
/*    3530c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    35310:	3c0e800a */ 	lui	$t6,0x800a
/*    35314:	8dce0a34 */ 	lw	$t6,0xa34($t6)
/*    35318:	11c0002e */ 	beqz	$t6,.NB000353d4
/*    3531c:	00000000 */ 	sll	$zero,$zero,0x0
/*    35320:	0c012688 */ 	jal	osSetIntMask
/*    35324:	24040001 */ 	addiu	$a0,$zero,0x1
/*    35328:	afa20034 */ 	sw	$v0,0x34($sp)
/*    3532c:	3c0f8006 */ 	lui	$t7,0x8006
/*    35330:	8def1630 */ 	lw	$t7,0x1630($t7)
/*    35334:	afaf0030 */ 	sw	$t7,0x30($sp)
/*    35338:	93a8003b */ 	lbu	$t0,0x3b($sp)
/*    3533c:	3c19800a */ 	lui	$t9,0x800a
/*    35340:	8f390a34 */ 	lw	$t9,0xa34($t9)
/*    35344:	97b8003e */ 	lhu	$t8,0x3e($sp)
/*    35348:	00084840 */ 	sll	$t1,$t0,0x1
/*    3534c:	03295021 */ 	addu	$t2,$t9,$t1
/*    35350:	a5580000 */ 	sh	$t8,0x0($t2)
/*    35354:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    35358:	afa0002c */ 	sw	$zero,0x2c($sp)
/*    3535c:	1160001b */ 	beqz	$t3,.NB000353cc
/*    35360:	00000000 */ 	sll	$zero,$zero,0x0
.NB00035364:
/*    35364:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    35368:	93b9003b */ 	lbu	$t9,0x3b($sp)
/*    3536c:	8d8d0008 */ 	lw	$t5,0x8($t4)
/*    35370:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    35374:	91cf0002 */ 	lbu	$t7,0x2($t6)
/*    35378:	31e8001f */ 	andi	$t0,$t7,0x1f
/*    3537c:	1519000c */ 	bne	$t0,$t9,.NB000353b0
/*    35380:	00000000 */ 	sll	$zero,$zero,0x0
/*    35384:	24090800 */ 	addiu	$t1,$zero,0x800
/*    35388:	a7a9001c */ 	sh	$t1,0x1c($sp)
/*    3538c:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    35390:	afb80020 */ 	sw	$t8,0x20($sp)
/*    35394:	3c048006 */ 	lui	$a0,0x8006
/*    35398:	8c84163c */ 	lw	$a0,0x163c($a0)
/*    3539c:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    353a0:	00003025 */ 	or	$a2,$zero,$zero
/*    353a4:	00003825 */ 	or	$a3,$zero,$zero
/*    353a8:	0c00f678 */ 	jal	n_alEvtqPostEvent
/*    353ac:	24840014 */ 	addiu	$a0,$a0,0x14
.NB000353b0:
/*    353b0:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    353b4:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    353b8:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    353bc:	afab002c */ 	sw	$t3,0x2c($sp)
/*    353c0:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    353c4:	15a0ffe7 */ 	bnez	$t5,.NB00035364
/*    353c8:	afad0030 */ 	sw	$t5,0x30($sp)
.NB000353cc:
/*    353cc:	0c012688 */ 	jal	osSetIntMask
/*    353d0:	8fa40034 */ 	lw	$a0,0x34($sp)
.NB000353d4:
/*    353d4:	10000001 */ 	beqz	$zero,.NB000353dc
/*    353d8:	00000000 */ 	sll	$zero,$zero,0x0
.NB000353dc:
/*    353dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    353e0:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    353e4:	03e00008 */ 	jr	$ra
/*    353e8:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif
