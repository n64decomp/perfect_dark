#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chr/chrai.h"
#include "game/game_00b820.h"
#include "game/game_011110.h"
#include "game/game_02cde0.h"
#include "game/game_091e10.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

struct stageheadlimit g_StageHeadLimits[3] = {
	{ STAGE_INFILTRATION, 5 },
	{ STAGE_RESCUE,       4 },
	{ STAGE_ESCAPE,       5 },
};

u32 var80061708 = 0x00000000;
u32 var8006170c = 0x00000000;

GLOBAL_ASM(
glabel stageChooseActiveHeads
/*  f00b820:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f00b824:	3c0e8008 */ 	lui	$t6,%hi(g_Bodies+0x2)
/*  f00b828:	95cecf06 */ 	lhu	$t6,%lo(g_Bodies+0x2)($t6)
/*  f00b82c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f00b830:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f00b834:	00808025 */ 	or	$s0,$a0,$zero
/*  f00b838:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f00b83c:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f00b840:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f00b844:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f00b848:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f00b84c:	11c00009 */ 	beqz	$t6,.L0f00b874
/*  f00b850:	00008825 */ 	or	$s1,$zero,$zero
/*  f00b854:	3c028008 */ 	lui	$v0,%hi(g_Bodies)
/*  f00b858:	2442cf04 */ 	addiu	$v0,$v0,%lo(g_Bodies)
/*  f00b85c:	944f0016 */ 	lhu	$t7,0x16($v0)
.L0f00b860:
/*  f00b860:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f00b864:	ac40fff8 */ 	sw	$zero,-0x8($v0)
/*  f00b868:	55e0fffd */ 	bnezl	$t7,.L0f00b860
/*  f00b86c:	944f0016 */ 	lhu	$t7,0x16($v0)
/*  f00b870:	00008825 */ 	or	$s1,$zero,$zero
.L0f00b874:
/*  f00b874:	0c004b70 */ 	jal	random
/*  f00b878:	00000000 */ 	nop
/*  f00b87c:	3c188006 */ 	lui	$t8,%hi(g_NumBondBodies)
/*  f00b880:	8f182b00 */ 	lw	$t8,%lo(g_NumBondBodies)($t8)
/*  f00b884:	3c018006 */ 	lui	$at,%hi(var80062c80)
/*  f00b888:	3c128006 */ 	lui	$s2,%hi(var80062b14)
/*  f00b88c:	0058001b */ 	divu	$zero,$v0,$t8
/*  f00b890:	0000c810 */ 	mfhi	$t9
/*  f00b894:	ac392c80 */ 	sw	$t9,%lo(var80062c80)($at)
/*  f00b898:	26522b14 */ 	addiu	$s2,$s2,%lo(var80062b14)
/*  f00b89c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f00b8a0:	ae400000 */ 	sw	$zero,0x0($s2)
/*  f00b8a4:	3c018006 */ 	lui	$at,%hi(var80062b18)
/*  f00b8a8:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f00b8ac:	ac202b18 */ 	sw	$zero,%lo(var80062b18)($at)
/*  f00b8b0:	8cc8006c */ 	lw	$t0,0x6c($a2)
/*  f00b8b4:	17000002 */ 	bnez	$t8,.L0f00b8c0
/*  f00b8b8:	00000000 */ 	nop
/*  f00b8bc:	0007000d */ 	break	0x7
.L0f00b8c0:
/*  f00b8c0:	00002825 */ 	or	$a1,$zero,$zero
/*  f00b8c4:	11000003 */ 	beqz	$t0,.L0f00b8d4
/*  f00b8c8:	00001825 */ 	or	$v1,$zero,$zero
/*  f00b8cc:	10000001 */ 	b	.L0f00b8d4
/*  f00b8d0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f00b8d4:
/*  f00b8d4:	8cc90068 */ 	lw	$t1,0x68($a2)
/*  f00b8d8:	00002025 */ 	or	$a0,$zero,$zero
/*  f00b8dc:	00001025 */ 	or	$v0,$zero,$zero
/*  f00b8e0:	11200003 */ 	beqz	$t1,.L0f00b8f0
/*  f00b8e4:	00000000 */ 	nop
/*  f00b8e8:	10000001 */ 	b	.L0f00b8f0
/*  f00b8ec:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f00b8f0:
/*  f00b8f0:	8cca0064 */ 	lw	$t2,0x64($a2)
/*  f00b8f4:	3c15800a */ 	lui	$s5,%hi(g_NumActiveHeadsPerGender)
/*  f00b8f8:	26b5cd20 */ 	addiu	$s5,$s5,%lo(g_NumActiveHeadsPerGender)
/*  f00b8fc:	11400003 */ 	beqz	$t2,.L0f00b90c
/*  f00b900:	24180008 */ 	addiu	$t8,$zero,0x8
/*  f00b904:	10000001 */ 	b	.L0f00b90c
/*  f00b908:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f00b90c:
/*  f00b90c:	8ccb0070 */ 	lw	$t3,0x70($a2)
/*  f00b910:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f00b914:	3c198006 */ 	lui	$t9,%hi(g_StageHeadLimits)
/*  f00b918:	11600003 */ 	beqz	$t3,.L0f00b928
/*  f00b91c:	00000000 */ 	nop
/*  f00b920:	10000001 */ 	b	.L0f00b928
/*  f00b924:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f00b928:
/*  f00b928:	00446021 */ 	addu	$t4,$v0,$a0
/*  f00b92c:	01836821 */ 	addu	$t5,$t4,$v1
/*  f00b930:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f00b934:	29c10002 */ 	slti	$at,$t6,0x2
/*  f00b938:	14200005 */ 	bnez	$at,.L0f00b950
/*  f00b93c:	27221700 */ 	addiu	$v0,$t9,%lo(g_StageHeadLimits)
/*  f00b940:	3c15800a */ 	lui	$s5,%hi(g_NumActiveHeadsPerGender)
/*  f00b944:	26b5cd20 */ 	addiu	$s5,$s5,%lo(g_NumActiveHeadsPerGender)
/*  f00b948:	1000000d */ 	b	.L0f00b980
/*  f00b94c:	aeaf0000 */ 	sw	$t7,0x0($s5)
.L0f00b950:
/*  f00b950:	aeb80000 */ 	sw	$t8,0x0($s5)
/*  f00b954:	24440006 */ 	addiu	$a0,$v0,0x6
/*  f00b958:	90480000 */ 	lbu	$t0,0x0($v0)
.L0f00b95c:
/*  f00b95c:	56080004 */ 	bnel	$s0,$t0,.L0f00b970
/*  f00b960:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f00b964:	90490001 */ 	lbu	$t1,0x1($v0)
/*  f00b968:	aea90000 */ 	sw	$t1,0x0($s5)
/*  f00b96c:	24420002 */ 	addiu	$v0,$v0,0x2
.L0f00b970:
/*  f00b970:	0044082b */ 	sltu	$at,$v0,$a0
/*  f00b974:	5420fff9 */ 	bnezl	$at,.L0f00b95c
/*  f00b978:	90480000 */ 	lbu	$t0,0x0($v0)
/*  f00b97c:	00008825 */ 	or	$s1,$zero,$zero
.L0f00b980:
/*  f00b980:	0fc41b99 */ 	jal	cheatIsActive
/*  f00b984:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f00b988:	10400005 */ 	beqz	$v0,.L0f00b9a0
/*  f00b98c:	3c148006 */ 	lui	$s4,%hi(g_MaleGuardTeamHeads)
/*  f00b990:	3c138006 */ 	lui	$s3,%hi(g_NumMaleGuardTeamHeads)
/*  f00b994:	26942c14 */ 	addiu	$s4,$s4,%lo(g_MaleGuardTeamHeads)
/*  f00b998:	10000005 */ 	b	.L0f00b9b0
/*  f00b99c:	8e732b0c */ 	lw	$s3,%lo(g_NumMaleGuardTeamHeads)($s3)
.L0f00b9a0:
/*  f00b9a0:	3c148006 */ 	lui	$s4,%hi(g_MaleGuardHeads)
/*  f00b9a4:	3c138006 */ 	lui	$s3,%hi(g_NumMaleGuardHeads)
/*  f00b9a8:	26942b68 */ 	addiu	$s4,$s4,%lo(g_MaleGuardHeads)
/*  f00b9ac:	8e732b04 */ 	lw	$s3,%lo(g_NumMaleGuardHeads)($s3)
.L0f00b9b0:
/*  f00b9b0:	8eaa0000 */ 	lw	$t2,0x0($s5)
/*  f00b9b4:	3c12800a */ 	lui	$s2,%hi(g_ActiveMaleHeads)
/*  f00b9b8:	2652cd28 */ 	addiu	$s2,$s2,%lo(g_ActiveMaleHeads)
/*  f00b9bc:	19400022 */ 	blez	$t2,.L0f00ba48
/*  f00b9c0:	00000000 */ 	nop
.L0f00b9c4:
/*  f00b9c4:	0c004b70 */ 	jal	random
/*  f00b9c8:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f00b9cc:	0053001b */ 	divu	$zero,$v0,$s3
/*  f00b9d0:	00005810 */ 	mfhi	$t3
/*  f00b9d4:	8ea50000 */ 	lw	$a1,0x0($s5)
/*  f00b9d8:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f00b9dc:	028c6821 */ 	addu	$t5,$s4,$t4
/*  f00b9e0:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f00b9e4:	16600002 */ 	bnez	$s3,.L0f00b9f0
/*  f00b9e8:	00000000 */ 	nop
/*  f00b9ec:	0007000d */ 	break	0x7
.L0f00b9f0:
/*  f00b9f0:	00b3082a */ 	slt	$at,$a1,$s3
/*  f00b9f4:	1020000d */ 	beqz	$at,.L0f00ba2c
/*  f00b9f8:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*  f00b9fc:	1a20000b */ 	blez	$s1,.L0f00ba2c
/*  f00ba00:	00001825 */ 	or	$v1,$zero,$zero
/*  f00ba04:	3c02800a */ 	lui	$v0,%hi(g_ActiveMaleHeads)
/*  f00ba08:	2442cd28 */ 	addiu	$v0,$v0,%lo(g_ActiveMaleHeads)
/*  f00ba0c:	01c02025 */ 	or	$a0,$t6,$zero
.L0f00ba10:
/*  f00ba10:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f00ba14:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00ba18:	15e40002 */ 	bne	$t7,$a0,.L0f00ba24
/*  f00ba1c:	00000000 */ 	nop
/*  f00ba20:	00008025 */ 	or	$s0,$zero,$zero
.L0f00ba24:
/*  f00ba24:	1471fffa */ 	bne	$v1,$s1,.L0f00ba10
/*  f00ba28:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f00ba2c:
/*  f00ba2c:	1200ffe5 */ 	beqz	$s0,.L0f00b9c4
/*  f00ba30:	00000000 */ 	nop
/*  f00ba34:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f00ba38:	0225082a */ 	slt	$at,$s1,$a1
/*  f00ba3c:	1420ffe1 */ 	bnez	$at,.L0f00b9c4
/*  f00ba40:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f00ba44:	00008825 */ 	or	$s1,$zero,$zero
.L0f00ba48:
/*  f00ba48:	0fc41b99 */ 	jal	cheatIsActive
/*  f00ba4c:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f00ba50:	10400006 */ 	beqz	$v0,.L0f00ba6c
/*  f00ba54:	3c148006 */ 	lui	$s4,%hi(g_FemaleGuardHeads)
/*  f00ba58:	3c148006 */ 	lui	$s4,%hi(g_FemaleGuardTeamHeads)
/*  f00ba5c:	3c138006 */ 	lui	$s3,%hi(g_NumFemaleGuardTeamHeads)
/*  f00ba60:	26942c6c */ 	addiu	$s4,$s4,%lo(g_FemaleGuardTeamHeads)
/*  f00ba64:	10000004 */ 	b	.L0f00ba78
/*  f00ba68:	8e732b10 */ 	lw	$s3,%lo(g_NumFemaleGuardTeamHeads)($s3)
.L0f00ba6c:
/*  f00ba6c:	3c138006 */ 	lui	$s3,%hi(g_NumFemaleGuardHeads)
/*  f00ba70:	26942c58 */ 	addiu	$s4,$s4,%lo(g_FemaleGuardHeads)
/*  f00ba74:	8e732b08 */ 	lw	$s3,%lo(g_NumFemaleGuardHeads)($s3)
.L0f00ba78:
/*  f00ba78:	8ea50000 */ 	lw	$a1,0x0($s5)
/*  f00ba7c:	3c12800a */ 	lui	$s2,%hi(g_ActiveFemaleHeads)
/*  f00ba80:	2652cd48 */ 	addiu	$s2,$s2,%lo(g_ActiveFemaleHeads)
/*  f00ba84:	18a00022 */ 	blez	$a1,.L0f00bb10
/*  f00ba88:	00000000 */ 	nop
.L0f00ba8c:
/*  f00ba8c:	0c004b70 */ 	jal	random
/*  f00ba90:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f00ba94:	0053001b */ 	divu	$zero,$v0,$s3
/*  f00ba98:	0000c010 */ 	mfhi	$t8
/*  f00ba9c:	8ea50000 */ 	lw	$a1,0x0($s5)
/*  f00baa0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f00baa4:	02994021 */ 	addu	$t0,$s4,$t9
/*  f00baa8:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f00baac:	16600002 */ 	bnez	$s3,.L0f00bab8
/*  f00bab0:	00000000 */ 	nop
/*  f00bab4:	0007000d */ 	break	0x7
.L0f00bab8:
/*  f00bab8:	00b3082a */ 	slt	$at,$a1,$s3
/*  f00babc:	1020000d */ 	beqz	$at,.L0f00baf4
/*  f00bac0:	ae490000 */ 	sw	$t1,0x0($s2)
/*  f00bac4:	1a20000b */ 	blez	$s1,.L0f00baf4
/*  f00bac8:	00001825 */ 	or	$v1,$zero,$zero
/*  f00bacc:	3c02800a */ 	lui	$v0,%hi(g_ActiveFemaleHeads)
/*  f00bad0:	2442cd48 */ 	addiu	$v0,$v0,%lo(g_ActiveFemaleHeads)
/*  f00bad4:	01202025 */ 	or	$a0,$t1,$zero
.L0f00bad8:
/*  f00bad8:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f00badc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00bae0:	15440002 */ 	bne	$t2,$a0,.L0f00baec
/*  f00bae4:	00000000 */ 	nop
/*  f00bae8:	00008025 */ 	or	$s0,$zero,$zero
.L0f00baec:
/*  f00baec:	1471fffa */ 	bne	$v1,$s1,.L0f00bad8
/*  f00baf0:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f00baf4:
/*  f00baf4:	1200ffe5 */ 	beqz	$s0,.L0f00ba8c
/*  f00baf8:	00000000 */ 	nop
/*  f00bafc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f00bb00:	0225082a */ 	slt	$at,$s1,$a1
/*  f00bb04:	1420ffe1 */ 	bnez	$at,.L0f00ba8c
/*  f00bb08:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f00bb0c:	00008825 */ 	or	$s1,$zero,$zero
.L0f00bb10:
/*  f00bb10:	3c018006 */ 	lui	$at,%hi(g_ActiveMaleHeadsIndex)
/*  f00bb14:	ac202c84 */ 	sw	$zero,%lo(g_ActiveMaleHeadsIndex)($at)
/*  f00bb18:	3c018006 */ 	lui	$at,%hi(g_ActiveFemaleHeadsIndex)
/*  f00bb1c:	18a00006 */ 	blez	$a1,.L0f00bb38
/*  f00bb20:	ac202c88 */ 	sw	$zero,%lo(g_ActiveFemaleHeadsIndex)($at)
/*  f00bb24:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f00bb28:
/*  f00bb28:	0225082a */ 	slt	$at,$s1,$a1
/*  f00bb2c:	5420fffe */ 	bnezl	$at,.L0f00bb28
/*  f00bb30:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f00bb34:	00008825 */ 	or	$s1,$zero,$zero
.L0f00bb38:
/*  f00bb38:	18a00005 */ 	blez	$a1,.L0f00bb50
/*  f00bb3c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f00bb40:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f00bb44:
/*  f00bb44:	0225082a */ 	slt	$at,$s1,$a1
/*  f00bb48:	5420fffe */ 	bnezl	$at,.L0f00bb44
/*  f00bb4c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f00bb50:
/*  f00bb50:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f00bb54:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f00bb58:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f00bb5c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f00bb60:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f00bb64:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f00bb68:	03e00008 */ 	jr	$ra
/*  f00bb6c:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

// Mismatches:
// - Address of var80062b14 Should be loaded to a callee-save register
// - PLAYERCOUNT() calculation is more spread out
//   (does other register preparation during calculation)
// - Loop at 950 is calculated differently
//void stageChooseActiveHeads(s32 stagenum)
//{
//	s32 *headsavailablelist;
//	s32 headsavailablelen;
//	bool done;
//	s32 i;
//	s32 j;
//
//	for (i = 0; g_Bodies[i].bodyfileid; i++) {
//		g_Bodies[i].unk0c = NULL;
//	}
//
//	var80062c80 = random() % g_NumBondBodies;
//	var80062b14 = 0;
//	var80062b18 = 0;
//
//	if (PLAYERCOUNT() >= 2) {
//		g_NumActiveHeadsPerGender = 4;
//	} else {
//		// 950
//		g_NumActiveHeadsPerGender = 8;
//
//		for (i = 0; i < ARRAYCOUNT(g_StageHeadLimits); i++) {
//			if (g_StageHeadLimits[i].stagenum == stagenum) {
//				g_NumActiveHeadsPerGender = g_StageHeadLimits[i].maxheads;
//			}
//		}
//	}
//
//	// Male heads
//	if (cheatIsActive(CHEAT_TEAMHEADSONLY)) {
//		headsavailablelist = g_MaleGuardTeamHeads;
//		headsavailablelen = g_NumMaleGuardTeamHeads;
//	} else {
//		headsavailablelist = g_MaleGuardHeads;
//		headsavailablelen = g_NumMaleGuardHeads;
//	}
//
//	for (i = 0; i < g_NumActiveHeadsPerGender; i++) {
//		do {
//			done = true;
//			g_ActiveMaleHeads[i] = headsavailablelist[random() % headsavailablelen];
//
//			if (headsavailablelen > g_NumActiveHeadsPerGender) {
//				for (j = 0; j < i; j++) {
//					if (g_ActiveMaleHeads[i] == g_ActiveMaleHeads[j]) {
//						done = false;
//					}
//				}
//			}
//		} while (!done);
//	}
//
//	// Female heads
//	if (cheatIsActive(CHEAT_TEAMHEADSONLY)) {
//		headsavailablelist = g_FemaleGuardTeamHeads;
//		headsavailablelen = g_NumFemaleGuardTeamHeads;
//	} else {
//		headsavailablelist = g_FemaleGuardHeads;
//		headsavailablelen = g_NumFemaleGuardHeads;
//	}
//
//	for (i = 0; i < g_NumActiveHeadsPerGender; i++) {
//		do {
//			done = true;
//			g_ActiveFemaleHeads[i] = headsavailablelist[random() % headsavailablelen];
//
//			if (headsavailablelen > g_NumActiveHeadsPerGender) {
//				for (j = 0; j < i; j++) {
//					if (g_ActiveFemaleHeads[i] == g_ActiveFemaleHeads[j]) {
//						done = false;
//					}
//				}
//			}
//		} while (!done);
//	}
//
//	g_ActiveMaleHeadsIndex = 0;
//	g_ActiveFemaleHeadsIndex = 0;
//
//	for (i = 0; i < g_NumActiveHeadsPerGender; i++);
//	for (i = 0; i < g_NumActiveHeadsPerGender; i++);
//}

void resetSomeStageThings(void)
{
	s32 i;

	for (i = 0; i != MAX_DANGEROUSPROPS; i++) {
		g_DangerousProps[i] = NULL;
	}

	g_StageFlags = 0;

	var80062ca0 = 1;
	var80062ca4 = 1;
	var80062ca8 = 1;
	var80062cac = 1;

	var80062cbc = 0;
}

void stageAllocateBgChrs(void)
{
	bool modified;
	struct chrdata tmp;
	s32 i;

	g_BgChrs = NULL;
	g_BgChrnums = 0;
	g_NumBgChrs = 0;

	if (!g_StageSetup.ailists) {
		return;
	}

	// Count the number of background AI lists
	i = 0;

	while (g_StageSetup.ailists[i].list) {
		if (g_StageSetup.ailists[i].id >= 0x1000) {
			g_NumBgChrs++;
		}

		i++;
	}

	// Add one for cutscene
	g_NumBgChrs++;

	if (g_NumBgChrs > 0) {
		s32 count = 0;
		struct chrdata blankchr = {0};

		// Allocate BG chrs
		g_BgChrs = malloc(ALIGN16(g_NumBgChrs * sizeof(struct chrdata)), MEMPOOL_STAGE);
		g_BgChrnums = malloc(ALIGN16(g_NumBgChrs * sizeof(s16)), MEMPOOL_STAGE);

		// Initialise BG chrs
		i = 0;

		while (g_StageSetup.ailists[i].list) {
			if (g_StageSetup.ailists[i].id >= 0x1000) {
				g_BgChrs[count] = blankchr;

				if (g_StageSetup.ailists[i].id >= 0x1400) {
					g_BgChrs[count].chrnum = g_StageSetup.ailists[i].id - 0x460; // 4000+
					g_BgChrs[count].hidden2 |= CHRH2FLAG_0010;
				} else {
					g_BgChrs[count].chrnum = g_StageSetup.ailists[i].id - 0x60; // 4000+
				}

				g_BgChrs[count].ailist = g_StageSetup.ailists[i].list;
				g_BgChrs[count].aioffset = 0;
				g_BgChrs[count].aireturnlist = -1;
				g_BgChrs[count].actiontype = ACT_NULL;
				count++;
			}

			i++;
		}

		// The final BG chr is for cutscene use
		g_BgChrs[count] = blankchr;
		g_BgChrs[count].chrnum = 4900;
		g_BgChrs[count].ailist = NULL;
		g_BgChrs[count].aioffset = 0;
		g_BgChrs[count].aireturnlist = -1;
		g_BgChrs[count].actiontype = ACT_NULL;
		g_BgChrs[count].hidden2 |= CHRH2FLAG_0010;
		count++;

		// Sort them
		do {
			modified = false;

			for (i = 0; i < count - 1; i++) {
				if (g_BgChrs[i + 1].chrnum < g_BgChrs[i].chrnum) {
					tmp = g_BgChrs[i];
					g_BgChrs[i] = g_BgChrs[i + 1];
					g_BgChrs[i + 1] = tmp;

					modified = true;
				}
			}
		} while (modified);

		// Populate chr numbers
		for (i = 0; i < count; i++) {
			g_BgChrnums[i] = g_BgChrs[i].chrnum;
		}
	}

	g_TeamList = malloc(0x210, MEMPOOL_STAGE);
	g_SquadronList = malloc(0x220, MEMPOOL_STAGE);
}

GLOBAL_ASM(
glabel debugLoadAllAilistModels
/*  f00c07c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f00c080:	3c0e800a */ 	lui	$t6,%hi(g_StageSetup+0x18)
/*  f00c084:	8dced048 */ 	lw	$t6,%lo(g_StageSetup+0x18)($t6)
/*  f00c088:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00c08c:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f00c090:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f00c094:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f00c098:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f00c09c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f00c0a0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f00c0a4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f00c0a8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f00c0ac:	8dd00000 */ 	lw	$s0,0x0($t6)
/*  f00c0b0:	241500c8 */ 	addiu	$s5,$zero,0xc8
/*  f00c0b4:	241600c9 */ 	addiu	$s6,$zero,0xc9
/*  f00c0b8:	12000052 */ 	beqz	$s0,.L0f00c204
/*  f00c0bc:	0000b825 */ 	or	$s7,$zero,$zero
/*  f00c0c0:	241400c7 */ 	addiu	$s4,$zero,0xc7
/*  f00c0c4:	241300c6 */ 	addiu	$s3,$zero,0xc6
/*  f00c0c8:	2412001c */ 	addiu	$s2,$zero,0x1c
/*  f00c0cc:	24110004 */ 	addiu	$s1,$zero,0x4
.L0f00c0d0:
/*  f00c0d0:	92030000 */ 	lbu	$v1,0x0($s0)
.L0f00c0d4:
/*  f00c0d4:	3c0f800a */ 	lui	$t7,%hi(g_StageSetup+0x18)
/*  f00c0d8:	16230004 */ 	bne	$s1,$v1,.L0f00c0ec
/*  f00c0dc:	00000000 */ 	nop
/*  f00c0e0:	8defd048 */ 	lw	$t7,%lo(g_StageSetup+0x18)($t7)
/*  f00c0e4:	10000042 */ 	b	.L0f00c1f0
/*  f00c0e8:	01f71021 */ 	addu	$v0,$t7,$s7
.L0f00c0ec:
/*  f00c0ec:	5072000c */ 	beql	$v1,$s2,.L0f00c120
/*  f00c0f0:	92180002 */ 	lbu	$t8,0x2($s0)
/*  f00c0f4:	10730013 */ 	beq	$v1,$s3,.L0f00c144
/*  f00c0f8:	00000000 */ 	nop
/*  f00c0fc:	1074001c */ 	beq	$v1,$s4,.L0f00c170
/*  f00c100:	00000000 */ 	nop
/*  f00c104:	50750026 */ 	beql	$v1,$s5,.L0f00c1a0
/*  f00c108:	920a0002 */ 	lbu	$t2,0x2($s0)
/*  f00c10c:	5076002f */ 	beql	$v1,$s6,.L0f00c1cc
/*  f00c110:	920d0002 */ 	lbu	$t5,0x2($s0)
/*  f00c114:	10000032 */ 	b	.L0f00c1e0
/*  f00c118:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c11c:	92180002 */ 	lbu	$t8,0x2($s0)
.L0f00c120:
/*  f00c120:	92080003 */ 	lbu	$t0,0x3($s0)
/*  f00c124:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f00c128:	03281025 */ 	or	$v0,$t9,$t0
/*  f00c12c:	0fc2486d */ 	jal	propLoad
/*  f00c130:	3044ffff */ 	andi	$a0,$v0,0xffff
/*  f00c134:	5040002a */ 	beqzl	$v0,.L0f00c1e0
/*  f00c138:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c13c:	10000028 */ 	b	.L0f00c1e0
/*  f00c140:	02002025 */ 	or	$a0,$s0,$zero
.L0f00c144:
/*  f00c144:	0fc0b38c */ 	jal	bodyLoad
/*  f00c148:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f00c14c:	82040003 */ 	lb	$a0,0x3($s0)
/*  f00c150:	04820023 */ 	bltzl	$a0,.L0f00c1e0
/*  f00c154:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c158:	0fc0b38c */ 	jal	bodyLoad
/*  f00c15c:	00000000 */ 	nop
/*  f00c160:	5040001f */ 	beqzl	$v0,.L0f00c1e0
/*  f00c164:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c168:	1000001d */ 	b	.L0f00c1e0
/*  f00c16c:	02002025 */ 	or	$a0,$s0,$zero
.L0f00c170:
/*  f00c170:	0fc0b38c */ 	jal	bodyLoad
/*  f00c174:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f00c178:	82040003 */ 	lb	$a0,0x3($s0)
/*  f00c17c:	04820018 */ 	bltzl	$a0,.L0f00c1e0
/*  f00c180:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c184:	0fc0b38c */ 	jal	bodyLoad
/*  f00c188:	00000000 */ 	nop
/*  f00c18c:	50400014 */ 	beqzl	$v0,.L0f00c1e0
/*  f00c190:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c194:	10000012 */ 	b	.L0f00c1e0
/*  f00c198:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c19c:	920a0002 */ 	lbu	$t2,0x2($s0)
.L0f00c1a0:
/*  f00c1a0:	920c0003 */ 	lbu	$t4,0x3($s0)
/*  f00c1a4:	000a5a00 */ 	sll	$t3,$t2,0x8
/*  f00c1a8:	0fc2486d */ 	jal	propLoad
/*  f00c1ac:	016c2025 */ 	or	$a0,$t3,$t4
/*  f00c1b0:	0fc04558 */ 	jal	weaponLoadProjectileModels
/*  f00c1b4:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f00c1b8:	50400009 */ 	beqzl	$v0,.L0f00c1e0
/*  f00c1bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c1c0:	10000007 */ 	b	.L0f00c1e0
/*  f00c1c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c1c8:	920d0002 */ 	lbu	$t5,0x2($s0)
.L0f00c1cc:
/*  f00c1cc:	920f0003 */ 	lbu	$t7,0x3($s0)
/*  f00c1d0:	000d7200 */ 	sll	$t6,$t5,0x8
/*  f00c1d4:	0fc2486d */ 	jal	propLoad
/*  f00c1d8:	01cf2025 */ 	or	$a0,$t6,$t7
/*  f00c1dc:	02002025 */ 	or	$a0,$s0,$zero
.L0f00c1e0:
/*  f00c1e0:	0fc136d0 */ 	jal	chraiGetCommandLength
/*  f00c1e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f00c1e8:	1000ffb9 */ 	b	.L0f00c0d0
/*  f00c1ec:	02028021 */ 	addu	$s0,$s0,$v0
.L0f00c1f0:
/*  f00c1f0:	8c500008 */ 	lw	$s0,0x8($v0)
/*  f00c1f4:	26f70008 */ 	addiu	$s7,$s7,0x8
/*  f00c1f8:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f00c1fc:	5600ffb5 */ 	bnezl	$s0,.L0f00c0d4
/*  f00c200:	92030000 */ 	lbu	$v1,0x0($s0)
.L0f00c204:
/*  f00c204:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00c208:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f00c20c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f00c210:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f00c214:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f00c218:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f00c21c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f00c220:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f00c224:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f00c228:	03e00008 */ 	jr	$ra
/*  f00c22c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

// Mismatch: regalloc near 19c
//void debugLoadAllAilistModels(void)
//{
//	u8 *cmd = g_StageSetup.ailists[0].list;
//	s32 i = 0;
//	s32 id;
//
//	if (!cmd) {
//		return;
//	}
//
//	do {
//		while (true) {
//			if (cmd[0] == AICMD_END) {
//				break;
//			}
//
//			switch (cmd[0]) {
//			case AICMD_DROPITEM: // 120
//				id = cmd[3] | (cmd[2] << 8);
//
//				if (propLoad(id & 0xffff)) {
//					// empty
//				}
//				break;
//			case AICMD_SPAWNCHRATPAD: // 144
//				if (bodyLoad(cmd[2])) {
//					// empty
//				}
//				if ((s8)cmd[3] >= 0 && bodyLoad((s8)cmd[3])) {
//					// empty
//				}
//				break;
//			case AICMD_SPAWNCHRATCHR: // 170
//				if (bodyLoad(cmd[2])) {
//					// empty
//				}
//				if ((s8)cmd[3] >= 0 && bodyLoad((s8)cmd[3])) {
//					// empty
//				}
//				break;
//			case AICMD_EQUIPWEAPON: // 19c
//				if (propLoad(cmd[3] | (cmd[2] << 8))) {
//					// empty
//				}
//				if (weaponLoadProjectileModels(cmd[4])) {
//					// empty
//				}
//				break;
//			case AICMD_EQUIPHAT: // 1c8
//				if (propLoad(cmd[3] | (cmd[2] << 8))) {
//					// empty
//				}
//				break;
//			}
//
//			cmd += chraiGetCommandLength(cmd, 0);
//		}
//
//		i++;
//		cmd = g_StageSetup.ailists[i].list;
//	} while (cmd);
//}

void func0f00c230(void)
{
	// empty
}
