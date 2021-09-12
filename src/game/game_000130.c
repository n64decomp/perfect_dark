#include <ultra64.h>
#include "constants.h"
#include "game/game_000130.h"
#include "game/floor.h"
#include "bss.h"
#include "lib/lib_233c0.h"
#include "data.h"
#include "types.h"

const u32 var7f1a78c0[] = {0x40c907a9};
const u32 var7f1a78c4[] = {0x38c907a9};

void func0f000130(void)
{
	g_NumBondBodies = 0;

	while (g_BondBodies[g_NumBondBodies] >= 0) {
		g_NumBondBodies++;
	}

	g_NumMaleGuardTeamHeads = 0;

	while (g_MaleGuardTeamHeads[g_NumMaleGuardTeamHeads] >= 0) {
		g_NumMaleGuardTeamHeads++;
	}

	g_NumFemaleGuardTeamHeads = 0;

	while (g_FemaleGuardTeamHeads[g_NumFemaleGuardTeamHeads] >= 0) {
		g_NumFemaleGuardTeamHeads++;
	}

	g_NumMaleGuardHeads = 0;

	while (g_MaleGuardHeads[g_NumMaleGuardHeads] >= 0) {
		g_NumMaleGuardHeads++;
	}

	g_NumFemaleGuardHeads = 0;

	while (g_FemaleGuardHeads[g_NumFemaleGuardHeads] >= 0) {
		g_NumFemaleGuardHeads++;
	}
}

u16 func0f0002a0(s16 animnum, s32 frame, s32 endframe)
{
	s16 sp48[4];
	u16 count = 0;

	while (frame < endframe) {
		count += func0002485c(0, 0, &g_ModelTypeChr, animnum, frame, sp48, 0);
		frame++;
	}

	return count;
}

s32 func0f000358(s16 animnum, s32 frame, s32 endframe)
{
	s32 count = 0;
	s16 sp44[4];

	while (frame < endframe) {
		func0002485c(0, 0, &g_ModelTypeChr, animnum, frame, sp44, 0);
		count += sp44[2];
		frame++;
	}

	return count;
}

GLOBAL_ASM(
glabel func0f00040c
/*  f00040c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f000410:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f000414:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f000418:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f00041c:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f000420:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f000424:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f000428:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f00042c:	848e0000 */ 	lh	$t6,0x0($a0)
/*  f000430:	00008825 */ 	or	$s1,$zero,$zero
/*  f000434:	00808025 */ 	or	$s0,$a0,$zero
/*  f000438:	11c00032 */ 	beqz	$t6,.L0f000504
/*  f00043c:	3c017f1a */ 	lui	$at,%hi(var7f1a78c0)
/*  f000440:	c43878c0 */ 	lwc1	$f24,%lo(var7f1a78c0)($at)
/*  f000444:	3c017f1a */ 	lui	$at,%hi(var7f1a78c4)
/*  f000448:	4480a000 */ 	mtc1	$zero,$f20
/*  f00044c:	c43678c4 */ 	lwc1	$f22,%lo(var7f1a78c4)($at)
/*  f000450:	34128000 */ 	dli	$s2,0x8000
.L0f000454:
/*  f000454:	0fc25e42 */ 	jal	floor
/*  f000458:	c60c0004 */ 	lwc1	$f12,0x4($s0)
/*  f00045c:	86040000 */ 	lh	$a0,0x0($s0)
/*  f000460:	00002825 */ 	or	$a1,$zero,$zero
/*  f000464:	0fc000a8 */ 	jal	func0f0002a0
/*  f000468:	00403025 */ 	or	$a2,$v0,$zero
/*  f00046c:	c6000004 */ 	lwc1	$f0,0x4($s0)
/*  f000470:	3043ffff */ 	andi	$v1,$v0,0xffff
/*  f000474:	0072082a */ 	slt	$at,$v1,$s2
/*  f000478:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f00047c:	00000000 */ 	nop
/*  f000480:	4502001b */ 	bc1fl	.L0f0004f0
/*  f000484:	e6140008 */ 	swc1	$f20,0x8($s0)
/*  f000488:	5020000d */ 	beqzl	$at,.L0f0004c0
/*  f00048c:	44839000 */ 	mtc1	$v1,$f18
/*  f000490:	44832000 */ 	mtc1	$v1,$f4
/*  f000494:	3c014f80 */ 	lui	$at,0x4f80
/*  f000498:	04610004 */ 	bgez	$v1,.L0f0004ac
/*  f00049c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0004a0:	44814000 */ 	mtc1	$at,$f8
/*  f0004a4:	00000000 */ 	nop
/*  f0004a8:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0004ac:
/*  f0004ac:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0004b0:	46005403 */ 	div.s	$f16,$f10,$f0
/*  f0004b4:	1000000e */ 	b	.L0f0004f0
/*  f0004b8:	e6100008 */ 	swc1	$f16,0x8($s0)
/*  f0004bc:	44839000 */ 	mtc1	$v1,$f18
.L0f0004c0:
/*  f0004c0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0004c4:	04610004 */ 	bgez	$v1,.L0f0004d8
/*  f0004c8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0004cc:	44814000 */ 	mtc1	$at,$f8
/*  f0004d0:	00000000 */ 	nop
/*  f0004d4:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f0004d8:
/*  f0004d8:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f0004dc:	46183281 */ 	sub.s	$f10,$f6,$f24
/*  f0004e0:	46005403 */ 	div.s	$f16,$f10,$f0
/*  f0004e4:	10000002 */ 	b	.L0f0004f0
/*  f0004e8:	e6100008 */ 	swc1	$f16,0x8($s0)
/*  f0004ec:	e6140008 */ 	swc1	$f20,0x8($s0)
.L0f0004f0:
/*  f0004f0:	860f0048 */ 	lh	$t7,0x48($s0)
/*  f0004f4:	26100048 */ 	addiu	$s0,$s0,0x48
/*  f0004f8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0004fc:	15e0ffd5 */ 	bnez	$t7,.L0f000454
/*  f000500:	00000000 */ 	nop
.L0f000504:
/*  f000504:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f000508:	02201025 */ 	or	$v0,$s1,$zero
/*  f00050c:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f000510:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f000514:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f000518:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f00051c:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f000520:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f000524:	03e00008 */ 	jr	$ra
/*  f000528:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f00052c
/*  f00052c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f000530:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f000534:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f000538:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00053c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f000540:	00808025 */ 	or	$s0,$a0,$zero
/*  f000544:	00008825 */ 	or	$s1,$zero,$zero
/*  f000548:	24120080 */ 	addiu	$s2,$zero,0x80
.L0f00054c:
/*  f00054c:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f000550:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*  f000554:	05c30006 */ 	bgezl	$t6,.L0f000570
/*  f000558:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f00055c:	0fc00103 */ 	jal	func0f00040c
/*  f000560:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f000564:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f000568:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f00056c:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f000570:
/*  f000570:	1632fff6 */ 	bne	$s1,$s2,.L0f00054c
/*  f000574:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f000578:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f00057c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f000580:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f000584:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f000588:	03e00008 */ 	jr	$ra
/*  f00058c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

s32 func0f000590(struct animtablerow *rows)
{
	s32 i;

	for (i = 0; rows[i].animnum > 0; i++);

	return i;
}

f32 func0f0005c0(s16 animnum)
{
	f32 tmp = func0f000358(animnum, 0, animGetNumFrames(animnum) - 1) / (f32) animGetNumFrames(animnum);

	var8005f014[animnum] = tmp;

	return tmp * 0.1000000089407f;
}

void func0f000648(void)
{
	s32 race;
	s32 i;

	for (race = 0; race < 5; race++) {
		for (i = 0; g_AnimTablesByRace[race][i].hitpart != -1; i++) {
			if (g_AnimTablesByRace[race][i].deathanims) {
				g_AnimTablesByRace[race][i].deathanimcount = func0f000590(g_AnimTablesByRace[race][i].deathanims);
			} else {
				g_AnimTablesByRace[race][i].deathanimcount = 0;
			}

			if (g_AnimTablesByRace[race][i].injuryanims) {
				g_AnimTablesByRace[race][i].injuryanimcount = func0f000590(g_AnimTablesByRace[race][i].injuryanims);
			} else {
				g_AnimTablesByRace[race][i].injuryanimcount = 0;
			}
		}

		for (i = 0; var80067fdc[race][i].animnum >= 0; i++) {
			var80067fdc[race][i].value = func0f0005c0(var80067fdc[race][i].animnum);
		}
	}

	func0f000590(g_AnimTableHumanSlumped);

	for (race = 0; race < 2; race++) {
		func0f00052c(g_StandHeavyAttackAnims[race]);
		func0f00052c(g_StandLightAttackAnims[race]);
		func0f00052c(g_StandDualAttackAnims[race]);
		func0f00052c(g_KneelHeavyAttackAnims[race]);
		func0f00052c(g_KneelLightAttackAnims[race]);
		func0f00052c(g_KneelDualAttackAnims[race]);
	}

	func0f00040c(g_RollAttackAnims);
	func0f00040c(&g_AttackAnimHeavyWalk);
}
