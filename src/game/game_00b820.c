#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chr/chrai.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_00b820.h"
#include "game/game_011110.h"
#include "game/game_02cde0.h"
#include "game/game_066310.h"
#include "gvars/gvars.h"
#include "library/library_121e0.h"
#include "library/library_12dc0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f00b820
/*  f00b820:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f00b824:	3c0e8008 */ 	lui	$t6,0x8008
/*  f00b828:	95cecf06 */ 	lhu	$t6,-0x30fa($t6)
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
/*  f00b878:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b87c:	3c188006 */ 	lui	$t8,0x8006
/*  f00b880:	8f182b00 */ 	lw	$t8,0x2b00($t8)
/*  f00b884:	3c018006 */ 	lui	$at,0x8006
/*  f00b888:	3c128006 */ 	lui	$s2,%hi(var80062b14)
/*  f00b88c:	0058001b */ 	divu	$zero,$v0,$t8
/*  f00b890:	0000c810 */ 	mfhi	$t9
/*  f00b894:	ac392c80 */ 	sw	$t9,0x2c80($at)
/*  f00b898:	26522b14 */ 	addiu	$s2,$s2,%lo(var80062b14)
/*  f00b89c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f00b8a0:	ae400000 */ 	sw	$zero,0x0($s2)
/*  f00b8a4:	3c018006 */ 	lui	$at,0x8006
/*  f00b8a8:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f00b8ac:	ac202b18 */ 	sw	$zero,0x2b18($at)
/*  f00b8b0:	8cc8006c */ 	lw	$t0,0x6c($a2)
/*  f00b8b4:	17000002 */ 	bnez	$t8,.L0f00b8c0
/*  f00b8b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b8bc:	0007000d */ 	break	0x7
.L0f00b8c0:
/*  f00b8c0:	00002825 */ 	or	$a1,$zero,$zero
/*  f00b8c4:	11000003 */ 	beqz	$t0,.L0f00b8d4
/*  f00b8c8:	00001825 */ 	or	$v1,$zero,$zero
/*  f00b8cc:	10000001 */ 	beqz	$zero,.L0f00b8d4
/*  f00b8d0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f00b8d4:
/*  f00b8d4:	8cc90068 */ 	lw	$t1,0x68($a2)
/*  f00b8d8:	00002025 */ 	or	$a0,$zero,$zero
/*  f00b8dc:	00001025 */ 	or	$v0,$zero,$zero
/*  f00b8e0:	11200003 */ 	beqz	$t1,.L0f00b8f0
/*  f00b8e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b8e8:	10000001 */ 	beqz	$zero,.L0f00b8f0
/*  f00b8ec:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f00b8f0:
/*  f00b8f0:	8cca0064 */ 	lw	$t2,0x64($a2)
/*  f00b8f4:	3c15800a */ 	lui	$s5,%hi(g_MaxHeadsPerBank)
/*  f00b8f8:	26b5cd20 */ 	addiu	$s5,$s5,%lo(g_MaxHeadsPerBank)
/*  f00b8fc:	11400003 */ 	beqz	$t2,.L0f00b90c
/*  f00b900:	24180008 */ 	addiu	$t8,$zero,0x8
/*  f00b904:	10000001 */ 	beqz	$zero,.L0f00b90c
/*  f00b908:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f00b90c:
/*  f00b90c:	8ccb0070 */ 	lw	$t3,0x70($a2)
/*  f00b910:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f00b914:	3c198006 */ 	lui	$t9,0x8006
/*  f00b918:	11600003 */ 	beqz	$t3,.L0f00b928
/*  f00b91c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b920:	10000001 */ 	beqz	$zero,.L0f00b928
/*  f00b924:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f00b928:
/*  f00b928:	00446021 */ 	addu	$t4,$v0,$a0
/*  f00b92c:	01836821 */ 	addu	$t5,$t4,$v1
/*  f00b930:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f00b934:	29c10002 */ 	slti	$at,$t6,0x2
/*  f00b938:	14200005 */ 	bnez	$at,.L0f00b950
/*  f00b93c:	27221700 */ 	addiu	$v0,$t9,0x1700
/*  f00b940:	3c15800a */ 	lui	$s5,%hi(g_MaxHeadsPerBank)
/*  f00b944:	26b5cd20 */ 	addiu	$s5,$s5,%lo(g_MaxHeadsPerBank)
/*  f00b948:	1000000d */ 	beqz	$zero,.L0f00b980
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
/*  f00b98c:	3c148006 */ 	lui	$s4,%hi(var80062c14)
/*  f00b990:	3c138006 */ 	lui	$s3,0x8006
/*  f00b994:	26942c14 */ 	addiu	$s4,$s4,%lo(var80062c14)
/*  f00b998:	10000005 */ 	beqz	$zero,.L0f00b9b0
/*  f00b99c:	8e732b0c */ 	lw	$s3,0x2b0c($s3)
.L0f00b9a0:
/*  f00b9a0:	3c148006 */ 	lui	$s4,%hi(var80062b68)
/*  f00b9a4:	3c138006 */ 	lui	$s3,0x8006
/*  f00b9a8:	26942b68 */ 	addiu	$s4,$s4,%lo(var80062b68)
/*  f00b9ac:	8e732b04 */ 	lw	$s3,0x2b04($s3)
.L0f00b9b0:
/*  f00b9b0:	8eaa0000 */ 	lw	$t2,0x0($s5)
/*  f00b9b4:	3c12800a */ 	lui	$s2,%hi(g_HeadsA)
/*  f00b9b8:	2652cd28 */ 	addiu	$s2,$s2,%lo(g_HeadsA)
/*  f00b9bc:	19400022 */ 	blez	$t2,.L0f00ba48
/*  f00b9c0:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f00b9e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b9ec:	0007000d */ 	break	0x7
.L0f00b9f0:
/*  f00b9f0:	00b3082a */ 	slt	$at,$a1,$s3
/*  f00b9f4:	1020000d */ 	beqz	$at,.L0f00ba2c
/*  f00b9f8:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*  f00b9fc:	1a20000b */ 	blez	$s1,.L0f00ba2c
/*  f00ba00:	00001825 */ 	or	$v1,$zero,$zero
/*  f00ba04:	3c02800a */ 	lui	$v0,%hi(g_HeadsA)
/*  f00ba08:	2442cd28 */ 	addiu	$v0,$v0,%lo(g_HeadsA)
/*  f00ba0c:	01c02025 */ 	or	$a0,$t6,$zero
.L0f00ba10:
/*  f00ba10:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f00ba14:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00ba18:	15e40002 */ 	bne	$t7,$a0,.L0f00ba24
/*  f00ba1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00ba20:	00008025 */ 	or	$s0,$zero,$zero
.L0f00ba24:
/*  f00ba24:	1471fffa */ 	bne	$v1,$s1,.L0f00ba10
/*  f00ba28:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f00ba2c:
/*  f00ba2c:	1200ffe5 */ 	beqz	$s0,.L0f00b9c4
/*  f00ba30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00ba34:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f00ba38:	0225082a */ 	slt	$at,$s1,$a1
/*  f00ba3c:	1420ffe1 */ 	bnez	$at,.L0f00b9c4
/*  f00ba40:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f00ba44:	00008825 */ 	or	$s1,$zero,$zero
.L0f00ba48:
/*  f00ba48:	0fc41b99 */ 	jal	cheatIsActive
/*  f00ba4c:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f00ba50:	10400006 */ 	beqz	$v0,.L0f00ba6c
/*  f00ba54:	3c148006 */ 	lui	$s4,%hi(var80062c58)
/*  f00ba58:	3c148006 */ 	lui	$s4,%hi(var80062c6c)
/*  f00ba5c:	3c138006 */ 	lui	$s3,0x8006
/*  f00ba60:	26942c6c */ 	addiu	$s4,$s4,%lo(var80062c6c)
/*  f00ba64:	10000004 */ 	beqz	$zero,.L0f00ba78
/*  f00ba68:	8e732b10 */ 	lw	$s3,0x2b10($s3)
.L0f00ba6c:
/*  f00ba6c:	3c138006 */ 	lui	$s3,0x8006
/*  f00ba70:	26942c58 */ 	addiu	$s4,$s4,%lo(var80062c58)
/*  f00ba74:	8e732b08 */ 	lw	$s3,0x2b08($s3)
.L0f00ba78:
/*  f00ba78:	8ea50000 */ 	lw	$a1,0x0($s5)
/*  f00ba7c:	3c12800a */ 	lui	$s2,%hi(g_HeadsB)
/*  f00ba80:	2652cd48 */ 	addiu	$s2,$s2,%lo(g_HeadsB)
/*  f00ba84:	18a00022 */ 	blez	$a1,.L0f00bb10
/*  f00ba88:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f00bab0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00bab4:	0007000d */ 	break	0x7
.L0f00bab8:
/*  f00bab8:	00b3082a */ 	slt	$at,$a1,$s3
/*  f00babc:	1020000d */ 	beqz	$at,.L0f00baf4
/*  f00bac0:	ae490000 */ 	sw	$t1,0x0($s2)
/*  f00bac4:	1a20000b */ 	blez	$s1,.L0f00baf4
/*  f00bac8:	00001825 */ 	or	$v1,$zero,$zero
/*  f00bacc:	3c02800a */ 	lui	$v0,%hi(g_HeadsB)
/*  f00bad0:	2442cd48 */ 	addiu	$v0,$v0,%lo(g_HeadsB)
/*  f00bad4:	01202025 */ 	or	$a0,$t1,$zero
.L0f00bad8:
/*  f00bad8:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f00badc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00bae0:	15440002 */ 	bne	$t2,$a0,.L0f00baec
/*  f00bae4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00bae8:	00008025 */ 	or	$s0,$zero,$zero
.L0f00baec:
/*  f00baec:	1471fffa */ 	bne	$v1,$s1,.L0f00bad8
/*  f00baf0:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f00baf4:
/*  f00baf4:	1200ffe5 */ 	beqz	$s0,.L0f00ba8c
/*  f00baf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00bafc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f00bb00:	0225082a */ 	slt	$at,$s1,$a1
/*  f00bb04:	1420ffe1 */ 	bnez	$at,.L0f00ba8c
/*  f00bb08:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f00bb0c:	00008825 */ 	or	$s1,$zero,$zero
.L0f00bb10:
/*  f00bb10:	3c018006 */ 	lui	$at,0x8006
/*  f00bb14:	ac202c84 */ 	sw	$zero,0x2c84($at)
/*  f00bb18:	3c018006 */ 	lui	$at,0x8006
/*  f00bb1c:	18a00006 */ 	blez	$a1,.L0f00bb38
/*  f00bb20:	ac202c88 */ 	sw	$zero,0x2c88($at)
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

GLOBAL_ASM(
glabel func0f00bbc8
/*  f00bbc8:	3c0a800a */ 	lui	$t2,%hi(g_StageSetup)
/*  f00bbcc:	254ad030 */ 	addiu	$t2,$t2,%lo(g_StageSetup)
/*  f00bbd0:	27bdf8f0 */ 	addiu	$sp,$sp,-1808
/*  f00bbd4:	8d450018 */ 	lw	$a1,0x18($t2)
/*  f00bbd8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00bbdc:	3c108006 */ 	lui	$s0,%hi(g_ChrnumsB)
/*  f00bbe0:	3c078006 */ 	lui	$a3,%hi(g_NumChrsB)
/*  f00bbe4:	3c088006 */ 	lui	$t0,%hi(g_ChrsB)
/*  f00bbe8:	25087e58 */ 	addiu	$t0,$t0,%lo(g_ChrsB)
/*  f00bbec:	24e77e60 */ 	addiu	$a3,$a3,%lo(g_NumChrsB)
/*  f00bbf0:	26107e5c */ 	addiu	$s0,$s0,%lo(g_ChrnumsB)
/*  f00bbf4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f00bbf8:	ad000000 */ 	sw	$zero,0x0($t0)
/*  f00bbfc:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f00bc00:	10a00119 */ 	beqz	$a1,.L0f00c068
/*  f00bc04:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f00bc08:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f00bc0c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f00bc10:	00004825 */ 	or	$t1,$zero,$zero
/*  f00bc14:	11c0000c */ 	beqz	$t6,.L0f00bc48
/*  f00bc18:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00bc1c:	8c6f0004 */ 	lw	$t7,0x4($v1)
.L0f00bc20:
/*  f00bc20:	29e11000 */ 	slti	$at,$t7,0x1000
/*  f00bc24:	54200005 */ 	bnezl	$at,.L0f00bc3c
/*  f00bc28:	8c6e0008 */ 	lw	$t6,0x8($v1)
/*  f00bc2c:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f00bc30:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f00bc34:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f00bc38:	8c6e0008 */ 	lw	$t6,0x8($v1)
.L0f00bc3c:
/*  f00bc3c:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f00bc40:	55c0fff7 */ 	bnezl	$t6,.L0f00bc20
/*  f00bc44:	8c6f0004 */ 	lw	$t7,0x4($v1)
.L0f00bc48:
/*  f00bc48:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f00bc4c:	27b80034 */ 	addiu	$t8,$sp,0x34
/*  f00bc50:	3c198006 */ 	lui	$t9,%hi(var80061710)
/*  f00bc54:	25e20001 */ 	addiu	$v0,$t7,0x1
/*  f00bc58:	184000f9 */ 	blez	$v0,.L0f00c040
/*  f00bc5c:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f00bc60:	27391710 */ 	addiu	$t9,$t9,%lo(var80061710)
/*  f00bc64:	272f0360 */ 	addiu	$t7,$t9,0x360
.L0f00bc68:
/*  f00bc68:	8f210000 */ 	lw	$at,0x0($t9)
/*  f00bc6c:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f00bc70:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f00bc74:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f00bc78:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f00bc7c:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f00bc80:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f00bc84:	172ffff8 */ 	bne	$t9,$t7,.L0f00bc68
/*  f00bc88:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f00bc8c:	000220c0 */ 	sll	$a0,$v0,0x3
/*  f00bc90:	8f210000 */ 	lw	$at,0x0($t9)
/*  f00bc94:	00822023 */ 	subu	$a0,$a0,$v0
/*  f00bc98:	00042080 */ 	sll	$a0,$a0,0x2
/*  f00bc9c:	00822023 */ 	subu	$a0,$a0,$v0
/*  f00bca0:	00042080 */ 	sll	$a0,$a0,0x2
/*  f00bca4:	af010000 */ 	sw	$at,0x0($t8)
/*  f00bca8:	8f2f0004 */ 	lw	$t7,0x4($t9)
/*  f00bcac:	00822021 */ 	addu	$a0,$a0,$v0
/*  f00bcb0:	000420c0 */ 	sll	$a0,$a0,0x3
/*  f00bcb4:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f00bcb8:	348e000f */ 	ori	$t6,$a0,0xf
/*  f00bcbc:	af0f0004 */ 	sw	$t7,0x4($t8)
/*  f00bcc0:	afa9039c */ 	sw	$t1,0x39c($sp)
/*  f00bcc4:	afa003a0 */ 	sw	$zero,0x3a0($sp)
/*  f00bcc8:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f00bccc:	0c0048f2 */ 	jal	malloc
/*  f00bcd0:	00003025 */ 	or	$a2,$zero,$zero
/*  f00bcd4:	3c078006 */ 	lui	$a3,%hi(g_NumChrsB)
/*  f00bcd8:	24e77e60 */ 	addiu	$a3,$a3,%lo(g_NumChrsB)
/*  f00bcdc:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f00bce0:	3c088006 */ 	lui	$t0,%hi(g_ChrsB)
/*  f00bce4:	25087e58 */ 	addiu	$t0,$t0,%lo(g_ChrsB)
/*  f00bce8:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f00bcec:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f00bcf0:	3498000f */ 	ori	$t8,$a0,0xf
/*  f00bcf4:	ad020000 */ 	sw	$v0,0x0($t0)
/*  f00bcf8:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f00bcfc:	0c0048f2 */ 	jal	malloc
/*  f00bd00:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00bd04:	3c0a800a */ 	lui	$t2,%hi(g_StageSetup)
/*  f00bd08:	254ad030 */ 	addiu	$t2,$t2,%lo(g_StageSetup)
/*  f00bd0c:	8d450018 */ 	lw	$a1,0x18($t2)
/*  f00bd10:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f00bd14:	3c088006 */ 	lui	$t0,%hi(g_ChrsB)
/*  f00bd18:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f00bd1c:	25087e58 */ 	addiu	$t0,$t0,%lo(g_ChrsB)
/*  f00bd20:	8fa603a0 */ 	lw	$a2,0x3a0($sp)
/*  f00bd24:	8fa9039c */ 	lw	$t1,0x39c($sp)
/*  f00bd28:	11e00049 */ 	beqz	$t7,.L0f00be50
/*  f00bd2c:	27bf0034 */ 	addiu	$ra,$sp,0x34
/*  f00bd30:	00002025 */ 	or	$a0,$zero,$zero
/*  f00bd34:	00a01825 */ 	or	$v1,$a1,$zero
/*  f00bd38:	240d001a */ 	addiu	$t5,$zero,0x1a
/*  f00bd3c:	240cffff */ 	addiu	$t4,$zero,-1
/*  f00bd40:	240b0368 */ 	addiu	$t3,$zero,0x368
/*  f00bd44:	8c790004 */ 	lw	$t9,0x4($v1)
.L0f00bd48:
/*  f00bd48:	2b211000 */ 	slti	$at,$t9,0x1000
/*  f00bd4c:	5420003b */ 	bnezl	$at,.L0f00be3c
/*  f00bd50:	8c780008 */ 	lw	$t8,0x8($v1)
/*  f00bd54:	012b0019 */ 	multu	$t1,$t3
/*  f00bd58:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f00bd5c:	27f90360 */ 	addiu	$t9,$ra,0x360
/*  f00bd60:	00001012 */ 	mflo	$v0
/*  f00bd64:	03027021 */ 	addu	$t6,$t8,$v0
/*  f00bd68:	03e0c025 */ 	or	$t8,$ra,$zero
.L0f00bd6c:
/*  f00bd6c:	8f010000 */ 	lw	$at,0x0($t8)
/*  f00bd70:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f00bd74:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f00bd78:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f00bd7c:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*  f00bd80:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f00bd84:	8f01fffc */ 	lw	$at,-0x4($t8)
/*  f00bd88:	1719fff8 */ 	bne	$t8,$t9,.L0f00bd6c
/*  f00bd8c:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f00bd90:	8f010000 */ 	lw	$at,0x0($t8)
/*  f00bd94:	adc10000 */ 	sw	$at,0x0($t6)
/*  f00bd98:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f00bd9c:	add90004 */ 	sw	$t9,0x4($t6)
/*  f00bda0:	8d4f0018 */ 	lw	$t7,0x18($t2)
/*  f00bda4:	01e4c821 */ 	addu	$t9,$t7,$a0
/*  f00bda8:	8f230004 */ 	lw	$v1,0x4($t9)
/*  f00bdac:	28611400 */ 	slti	$at,$v1,0x1400
/*  f00bdb0:	5420000c */ 	bnezl	$at,.L0f00bde4
/*  f00bdb4:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f00bdb8:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f00bdbc:	2478fba0 */ 	addiu	$t8,$v1,-1120
/*  f00bdc0:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f00bdc4:	a5f80000 */ 	sh	$t8,0x0($t7)
/*  f00bdc8:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f00bdcc:	03222821 */ 	addu	$a1,$t9,$v0
/*  f00bdd0:	94ae0192 */ 	lhu	$t6,0x192($a1)
/*  f00bdd4:	35d80010 */ 	ori	$t8,$t6,0x10
/*  f00bdd8:	10000005 */ 	beqz	$zero,.L0f00bdf0
/*  f00bddc:	a4b80192 */ 	sh	$t8,0x192($a1)
/*  f00bde0:	8d190000 */ 	lw	$t9,0x0($t0)
.L0f00bde4:
/*  f00bde4:	246fffa0 */ 	addiu	$t7,$v1,-96
/*  f00bde8:	03227021 */ 	addu	$t6,$t9,$v0
/*  f00bdec:	a5cf0000 */ 	sh	$t7,0x0($t6)
.L0f00bdf0:
/*  f00bdf0:	8d580018 */ 	lw	$t8,0x18($t2)
/*  f00bdf4:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f00bdf8:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f00bdfc:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f00be00:	8f2f0000 */ 	lw	$t7,0x0($t9)
/*  f00be04:	01c2c021 */ 	addu	$t8,$t6,$v0
/*  f00be08:	af0f0108 */ 	sw	$t7,0x108($t8)
/*  f00be0c:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f00be10:	03227021 */ 	addu	$t6,$t9,$v0
/*  f00be14:	a5c0010c */ 	sh	$zero,0x10c($t6)
/*  f00be18:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f00be1c:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f00be20:	a70c010e */ 	sh	$t4,0x10e($t8)
/*  f00be24:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f00be28:	03227021 */ 	addu	$t6,$t9,$v0
/*  f00be2c:	a1cd0007 */ 	sb	$t5,0x7($t6)
/*  f00be30:	8d4f0018 */ 	lw	$t7,0x18($t2)
/*  f00be34:	01e41821 */ 	addu	$v1,$t7,$a0
/*  f00be38:	8c780008 */ 	lw	$t8,0x8($v1)
.L0f00be3c:
/*  f00be3c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f00be40:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f00be44:	5700ffc0 */ 	bnezl	$t8,.L0f00bd48
/*  f00be48:	8c790004 */ 	lw	$t9,0x4($v1)
/*  f00be4c:	00003025 */ 	or	$a2,$zero,$zero
.L0f00be50:
/*  f00be50:	240b0368 */ 	addiu	$t3,$zero,0x368
/*  f00be54:	012b0019 */ 	multu	$t1,$t3
/*  f00be58:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f00be5c:	240cffff */ 	addiu	$t4,$zero,-1
/*  f00be60:	240d001a */ 	addiu	$t5,$zero,0x1a
/*  f00be64:	27f80360 */ 	addiu	$t8,$ra,0x360
/*  f00be68:	00001012 */ 	mflo	$v0
/*  f00be6c:	03227021 */ 	addu	$t6,$t9,$v0
/*  f00be70:	03e0c825 */ 	or	$t9,$ra,$zero
.L0f00be74:
/*  f00be74:	8f210000 */ 	lw	$at,0x0($t9)
/*  f00be78:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f00be7c:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f00be80:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f00be84:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f00be88:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f00be8c:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f00be90:	1738fff8 */ 	bne	$t9,$t8,.L0f00be74
/*  f00be94:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f00be98:	8f210000 */ 	lw	$at,0x0($t9)
/*  f00be9c:	240f1324 */ 	addiu	$t7,$zero,0x1324
/*  f00bea0:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f00bea4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f00bea8:	8f380004 */ 	lw	$t8,0x4($t9)
/*  f00beac:	2527ffff */ 	addiu	$a3,$t1,-1
/*  f00beb0:	27a403a4 */ 	addiu	$a0,$sp,0x3a4
/*  f00beb4:	add80004 */ 	sw	$t8,0x4($t6)
/*  f00beb8:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f00bebc:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f00bec0:	a72f0000 */ 	sh	$t7,0x0($t9)
/*  f00bec4:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f00bec8:	01c2c021 */ 	addu	$t8,$t6,$v0
/*  f00becc:	af000108 */ 	sw	$zero,0x108($t8)
/*  f00bed0:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f00bed4:	01e2c821 */ 	addu	$t9,$t7,$v0
/*  f00bed8:	a720010c */ 	sh	$zero,0x10c($t9)
/*  f00bedc:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f00bee0:	01c2c021 */ 	addu	$t8,$t6,$v0
/*  f00bee4:	a70c010e */ 	sh	$t4,0x10e($t8)
/*  f00bee8:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f00beec:	01e2c821 */ 	addu	$t9,$t7,$v0
/*  f00bef0:	a32d0007 */ 	sb	$t5,0x7($t9)
/*  f00bef4:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f00bef8:	01c22821 */ 	addu	$a1,$t6,$v0
/*  f00befc:	94b80192 */ 	lhu	$t8,0x192($a1)
/*  f00bf00:	370f0010 */ 	ori	$t7,$t8,0x10
/*  f00bf04:	a4af0192 */ 	sh	$t7,0x192($a1)
.L0f00bf08:
/*  f00bf08:	18e0003e */ 	blez	$a3,.L0f00c004
/*  f00bf0c:	00002825 */ 	or	$a1,$zero,$zero
/*  f00bf10:	00001825 */ 	or	$v1,$zero,$zero
.L0f00bf14:
/*  f00bf14:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f00bf18:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f00bf1c:	03231021 */ 	addu	$v0,$t9,$v1
/*  f00bf20:	844e0368 */ 	lh	$t6,0x368($v0)
/*  f00bf24:	84580000 */ 	lh	$t8,0x0($v0)
/*  f00bf28:	24590360 */ 	addiu	$t9,$v0,0x360
/*  f00bf2c:	01d8082a */ 	slt	$at,$t6,$t8
/*  f00bf30:	10200031 */ 	beqz	$at,.L0f00bff8
/*  f00bf34:	00407025 */ 	or	$t6,$v0,$zero
/*  f00bf38:	0080c025 */ 	or	$t8,$a0,$zero
.L0f00bf3c:
/*  f00bf3c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f00bf40:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f00bf44:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f00bf48:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f00bf4c:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f00bf50:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f00bf54:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f00bf58:	15d9fff8 */ 	bne	$t6,$t9,.L0f00bf3c
/*  f00bf5c:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f00bf60:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f00bf64:	af010000 */ 	sw	$at,0x0($t8)
/*  f00bf68:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f00bf6c:	00407025 */ 	or	$t6,$v0,$zero
/*  f00bf70:	af190004 */ 	sw	$t9,0x4($t8)
/*  f00bf74:	24590360 */ 	addiu	$t9,$v0,0x360
/*  f00bf78:	0040c025 */ 	or	$t8,$v0,$zero
.L0f00bf7c:
/*  f00bf7c:	8dc10368 */ 	lw	$at,0x368($t6)
/*  f00bf80:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f00bf84:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f00bf88:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f00bf8c:	8dc10360 */ 	lw	$at,0x360($t6)
/*  f00bf90:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f00bf94:	8dc10364 */ 	lw	$at,0x364($t6)
/*  f00bf98:	15d9fff8 */ 	bne	$t6,$t9,.L0f00bf7c
/*  f00bf9c:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f00bfa0:	8dc10368 */ 	lw	$at,0x368($t6)
/*  f00bfa4:	af010000 */ 	sw	$at,0x0($t8)
/*  f00bfa8:	8dd9036c */ 	lw	$t9,0x36c($t6)
/*  f00bfac:	af190004 */ 	sw	$t9,0x4($t8)
/*  f00bfb0:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f00bfb4:	24980360 */ 	addiu	$t8,$a0,0x360
/*  f00bfb8:	01e3c821 */ 	addu	$t9,$t7,$v1
/*  f00bfbc:	00807825 */ 	or	$t7,$a0,$zero
.L0f00bfc0:
/*  f00bfc0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f00bfc4:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f00bfc8:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f00bfcc:	af21035c */ 	sw	$at,0x35c($t9)
/*  f00bfd0:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f00bfd4:	af210360 */ 	sw	$at,0x360($t9)
/*  f00bfd8:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f00bfdc:	15f8fff8 */ 	bne	$t7,$t8,.L0f00bfc0
/*  f00bfe0:	af210364 */ 	sw	$at,0x364($t9)
/*  f00bfe4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f00bfe8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f00bfec:	af210368 */ 	sw	$at,0x368($t9)
/*  f00bff0:	8df80004 */ 	lw	$t8,0x4($t7)
/*  f00bff4:	af38036c */ 	sw	$t8,0x36c($t9)
.L0f00bff8:
/*  f00bff8:	14c7ffc6 */ 	bne	$a2,$a3,.L0f00bf14
/*  f00bffc:	24630368 */ 	addiu	$v1,$v1,0x368
/*  f00c000:	00003025 */ 	or	$a2,$zero,$zero
.L0f00c004:
/*  f00c004:	14a0ffc0 */ 	bnez	$a1,.L0f00bf08
/*  f00c008:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00c00c:	1920000c */ 	blez	$t1,.L0f00c040
/*  f00c010:	00001825 */ 	or	$v1,$zero,$zero
/*  f00c014:	00001025 */ 	or	$v0,$zero,$zero
.L0f00c018:
/*  f00c018:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f00c01c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f00c020:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f00c024:	01c3c021 */ 	addu	$t8,$t6,$v1
/*  f00c028:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f00c02c:	03227021 */ 	addu	$t6,$t9,$v0
/*  f00c030:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f00c034:	24630368 */ 	addiu	$v1,$v1,0x368
/*  f00c038:	14c9fff7 */ 	bne	$a2,$t1,.L0f00c018
/*  f00c03c:	a5cf0000 */ 	sh	$t7,0x0($t6)
.L0f00c040:
/*  f00c040:	24040210 */ 	addiu	$a0,$zero,0x210
/*  f00c044:	0c0048f2 */ 	jal	malloc
/*  f00c048:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c04c:	3c018006 */ 	lui	$at,0x8006
/*  f00c050:	ac227e64 */ 	sw	$v0,0x7e64($at)
/*  f00c054:	24040220 */ 	addiu	$a0,$zero,0x220
/*  f00c058:	0c0048f2 */ 	jal	malloc
/*  f00c05c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c060:	3c018006 */ 	lui	$at,0x8006
/*  f00c064:	ac227e68 */ 	sw	$v0,0x7e68($at)
.L0f00c068:
/*  f00c068:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f00c06c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00c070:	27bd0710 */ 	addiu	$sp,$sp,0x710
/*  f00c074:	03e00008 */ 	jr	$ra
/*  f00c078:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00c07c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f00c080:	3c0e800a */ 	lui	$t6,0x800a
/*  f00c084:	8dced048 */ 	lw	$t6,-0x2fb8($t6)
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
/*  f00c0d4:	3c0f800a */ 	lui	$t7,0x800a
/*  f00c0d8:	16230004 */ 	bne	$s1,$v1,.L0f00c0ec
/*  f00c0dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00c0e0:	8defd048 */ 	lw	$t7,-0x2fb8($t7)
/*  f00c0e4:	10000042 */ 	beqz	$zero,.L0f00c1f0
/*  f00c0e8:	01f71021 */ 	addu	$v0,$t7,$s7
.L0f00c0ec:
/*  f00c0ec:	5072000c */ 	beql	$v1,$s2,.L0f00c120
/*  f00c0f0:	92180002 */ 	lbu	$t8,0x2($s0)
/*  f00c0f4:	10730013 */ 	beq	$v1,$s3,.L0f00c144
/*  f00c0f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00c0fc:	1074001c */ 	beq	$v1,$s4,.L0f00c170
/*  f00c100:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00c104:	50750026 */ 	beql	$v1,$s5,.L0f00c1a0
/*  f00c108:	920a0002 */ 	lbu	$t2,0x2($s0)
/*  f00c10c:	5076002f */ 	beql	$v1,$s6,.L0f00c1cc
/*  f00c110:	920d0002 */ 	lbu	$t5,0x2($s0)
/*  f00c114:	10000032 */ 	beqz	$zero,.L0f00c1e0
/*  f00c118:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c11c:	92180002 */ 	lbu	$t8,0x2($s0)
.L0f00c120:
/*  f00c120:	92080003 */ 	lbu	$t0,0x3($s0)
/*  f00c124:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f00c128:	03281025 */ 	or	$v0,$t9,$t0
/*  f00c12c:	0fc2486d */ 	jal	func0f0921b4
/*  f00c130:	3044ffff */ 	andi	$a0,$v0,0xffff
/*  f00c134:	5040002a */ 	beqzl	$v0,.L0f00c1e0
/*  f00c138:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c13c:	10000028 */ 	beqz	$zero,.L0f00c1e0
/*  f00c140:	02002025 */ 	or	$a0,$s0,$zero
.L0f00c144:
/*  f00c144:	0fc0b38c */ 	jal	func0f02ce30
/*  f00c148:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f00c14c:	82040003 */ 	lb	$a0,0x3($s0)
/*  f00c150:	04820023 */ 	bltzl	$a0,.L0f00c1e0
/*  f00c154:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c158:	0fc0b38c */ 	jal	func0f02ce30
/*  f00c15c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00c160:	5040001f */ 	beqzl	$v0,.L0f00c1e0
/*  f00c164:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c168:	1000001d */ 	beqz	$zero,.L0f00c1e0
/*  f00c16c:	02002025 */ 	or	$a0,$s0,$zero
.L0f00c170:
/*  f00c170:	0fc0b38c */ 	jal	func0f02ce30
/*  f00c174:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f00c178:	82040003 */ 	lb	$a0,0x3($s0)
/*  f00c17c:	04820018 */ 	bltzl	$a0,.L0f00c1e0
/*  f00c180:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c184:	0fc0b38c */ 	jal	func0f02ce30
/*  f00c188:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00c18c:	50400014 */ 	beqzl	$v0,.L0f00c1e0
/*  f00c190:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c194:	10000012 */ 	beqz	$zero,.L0f00c1e0
/*  f00c198:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c19c:	920a0002 */ 	lbu	$t2,0x2($s0)
.L0f00c1a0:
/*  f00c1a0:	920c0003 */ 	lbu	$t4,0x3($s0)
/*  f00c1a4:	000a5a00 */ 	sll	$t3,$t2,0x8
/*  f00c1a8:	0fc2486d */ 	jal	func0f0921b4
/*  f00c1ac:	016c2025 */ 	or	$a0,$t3,$t4
/*  f00c1b0:	0fc04558 */ 	jal	func0f011560
/*  f00c1b4:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f00c1b8:	50400009 */ 	beqzl	$v0,.L0f00c1e0
/*  f00c1bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c1c0:	10000007 */ 	beqz	$zero,.L0f00c1e0
/*  f00c1c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c1c8:	920d0002 */ 	lbu	$t5,0x2($s0)
.L0f00c1cc:
/*  f00c1cc:	920f0003 */ 	lbu	$t7,0x3($s0)
/*  f00c1d0:	000d7200 */ 	sll	$t6,$t5,0x8
/*  f00c1d4:	0fc2486d */ 	jal	func0f0921b4
/*  f00c1d8:	01cf2025 */ 	or	$a0,$t6,$t7
/*  f00c1dc:	02002025 */ 	or	$a0,$s0,$zero
.L0f00c1e0:
/*  f00c1e0:	0fc136d0 */ 	jal	chraiGetCommandLength
/*  f00c1e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f00c1e8:	1000ffb9 */ 	beqz	$zero,.L0f00c0d0
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
/*  f00c230:	03e00008 */ 	jr	$ra
/*  f00c234:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00c238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00c23c:	00000000 */ 	sll	$zero,$zero,0x0
);
