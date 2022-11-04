#include <ultra64.h>
#include "constants.h"
#include "game/body.h"
#include "game/game_00b820.h"
#include "game/playerreset.h"
#include "game/setuputils.h"
#include "bss.h"
#include "lib/memp.h"
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

#if MATCHING
GLOBAL_ASM(
glabel bodiesReset
/*  f00b820:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f00b824:	3c0e8008 */ 	lui	$t6,%hi(g_HeadsAndBodies+0x2)
/*  f00b828:	95cecf06 */ 	lhu	$t6,%lo(g_HeadsAndBodies+0x2)($t6)
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
/*  f00b854:	3c028008 */ 	lui	$v0,%hi(g_HeadsAndBodies)
/*  f00b858:	2442cf04 */ 	addiu	$v0,$v0,%lo(g_HeadsAndBodies)
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
#else
// Mismatches:
// - Address of var80062b14 Should be loaded to a callee-save register
// - PLAYERCOUNT() calculation is more spread out
//   (does other register preparation during calculation)
// - Loop at 950 is calculated differently
void bodiesReset(s32 stagenum)
{
	s32 *headsavailablelist;
	s32 headsavailablelen;
	bool done;
	s32 i;
	s32 j;

	for (i = 0; g_HeadsAndBodies[i].filenum; i++) {
		g_HeadsAndBodies[i].filedata = NULL;
	}

	var80062c80 = random() % g_NumBondBodies;
	var80062b14 = 0;
	var80062b18 = 0;

	if (PLAYERCOUNT() >= 2) {
		g_NumActiveHeadsPerGender = 4;
	} else {
		// 950
		g_NumActiveHeadsPerGender = 8;

		for (i = 0; i < ARRAYCOUNT(g_StageHeadLimits); i++) {
			if (g_StageHeadLimits[i].stagenum == stagenum) {
				g_NumActiveHeadsPerGender = g_StageHeadLimits[i].maxheads;
			}
		}
	}

	// Male heads
	headsavailablelist = g_MaleGuardHeads;
	headsavailablelen = g_NumMaleGuardHeads;

	for (i = 0; i < g_NumActiveHeadsPerGender; i++) {
		do {
			done = true;
			g_ActiveMaleHeads[i] = headsavailablelist[random() % headsavailablelen];

			if (headsavailablelen > g_NumActiveHeadsPerGender) {
				for (j = 0; j < i; j++) {
					if (g_ActiveMaleHeads[i] == g_ActiveMaleHeads[j]) {
						done = false;
					}
				}
			}
		} while (!done);
	}

	// Female heads
	headsavailablelist = g_FemaleGuardHeads;
	headsavailablelen = g_NumFemaleGuardHeads;

	for (i = 0; i < g_NumActiveHeadsPerGender; i++) {
		do {
			done = true;
			g_ActiveFemaleHeads[i] = headsavailablelist[random() % headsavailablelen];

			if (headsavailablelen > g_NumActiveHeadsPerGender) {
				for (j = 0; j < i; j++) {
					if (g_ActiveFemaleHeads[i] == g_ActiveFemaleHeads[j]) {
						done = false;
					}
				}
			}
		} while (!done);
	}

	g_ActiveMaleHeadsIndex = 0;
	g_ActiveFemaleHeadsIndex = 0;

	for (i = 0; i < g_NumActiveHeadsPerGender; i++);
	for (i = 0; i < g_NumActiveHeadsPerGender; i++);
}
#endif
