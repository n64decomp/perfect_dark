#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02a0e0.h"
#include "game/data/data_02da90.h"
#include "game/dlights.h"
#include "game/game_005fd0.h"
#include "game/game_00c490.h"
#include "game/game_0601b0.h"
#include "game/game_092610.h"
#include "game/game_096750.h"
#include "game/game_097ba0.h"
#include "game/game_0b63b0.h"
#include "game/game_0d4690.h"
#include "game/game_0dcdb0.h"
#include "game/game_0f09f0.h"
#include "game/inventory/inventory.h"
#include "game/game_127910.h"
#include "game/game_1531a0.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/radar.h"
#include "game/game_197600.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0e9d0.h"
#include "lib/memory.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_4a360.h"
#include "types.h"

s32 menuhandlerMpOpenOptions(u32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPushDialog(g_MpScenarios[g_MpSetup.scenario].optionsdialog);
	}

	return 0;
}

void scenarioCallback40(s32 *arg0)
{
	if (g_MpScenarios[g_MpSetup.scenario].unk40) {
		g_MpScenarios[g_MpSetup.scenario].unk40(arg0);
	} else {
		savefileGetInteger(arg0, 8);
	}
}

void scenarioCallback44(s32 *arg0)
{
	if (g_MpScenarios[g_MpSetup.scenario].unk44) {
		g_MpScenarios[g_MpSetup.scenario].unk44(arg0);
	} else {
		savefileGetSomething(arg0, 0, 8);
	}
}

void scenarioInit(void)
{
	if (g_MpScenarios[g_MpSetup.scenario].initfunc) {
		g_MpScenarios[g_MpSetup.scenario].initfunc();
	}
}

s32 scenarioCallback08(void)
{
	s32 result = 0;

	if (g_MpScenarios[g_MpSetup.scenario].unk08) {
		result = g_MpScenarios[g_MpSetup.scenario].unk08();
	}

	return result;
}

void scenarioReset(void)
{
	if (g_MpScenarios[g_MpSetup.scenario].resetfunc) {
		g_MpScenarios[g_MpSetup.scenario].resetfunc();
	}
}

GLOBAL_ASM(
glabel func0f185568
/*  f185568:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f18556c:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f185570:	3c14800b */ 	lui	$s4,%hi(g_MpSetup+0x28)
/*  f185574:	2694cbb0 */ 	addiu	$s4,$s4,%lo(g_MpSetup+0x28)
/*  f185578:	928f0060 */ 	lbu	$t7,0x60($s4)
/*  f18557c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x28c)
/*  f185580:	8dcea24c */ 	lw	$t6,%lo(g_Vars+0x28c)($t6)
/*  f185584:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f185588:	24130005 */ 	addiu	$s3,$zero,0x5
/*  f18558c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f185590:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f185594:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f185598:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18559c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1855a0:	166f000a */ 	bne	$s3,$t7,.L0f1855cc
/*  f1855a4:	afae00b8 */ 	sw	$t6,0xb8($sp)
/*  f1855a8:	0fc66dfd */ 	jal	mpGetCurrentChallengeIndex
/*  f1855ac:	00000000 */ 	nop
/*  f1855b0:	0fc66dbe */ 	jal	mpGetChallengeNameBySlot
/*  f1855b4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1855b8:	3c057f1c */ 	lui	$a1,%hi(var7f1b88d0)
/*  f1855bc:	24a588d0 */ 	addiu	$a1,$a1,%lo(var7f1b88d0)
/*  f1855c0:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f1855c4:	0c004dad */ 	jal	sprintf
/*  f1855c8:	00403025 */ 	or	$a2,$v0,$zero
.L0f1855cc:
/*  f1855cc:	3c18800b */ 	lui	$t8,%hi(g_MpSetup+0x10)
/*  f1855d0:	9318cb98 */ 	lbu	$t8,%lo(g_MpSetup+0x10)($t8)
/*  f1855d4:	3c048008 */ 	lui	$a0,%hi(g_MpScenarioOverviews)
/*  f1855d8:	27b5007c */ 	addiu	$s5,$sp,0x7c
/*  f1855dc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1855e0:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1855e4:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f1855e8:	00992021 */ 	addu	$a0,$a0,$t9
/*  f1855ec:	0fc5b9f1 */ 	jal	langGet
/*  f1855f0:	94847148 */ 	lhu	$a0,%lo(g_MpScenarioOverviews)($a0)
/*  f1855f4:	27b20040 */ 	addiu	$s2,$sp,0x40
/*  f1855f8:	3c057f1c */ 	lui	$a1,%hi(var7f1b88d8)
/*  f1855fc:	24a588d8 */ 	addiu	$a1,$a1,%lo(var7f1b88d8)
/*  f185600:	02402025 */ 	or	$a0,$s2,$zero
/*  f185604:	0c004dad */ 	jal	sprintf
/*  f185608:	00403025 */ 	or	$a2,$v0,$zero
/*  f18560c:	3c03800b */ 	lui	$v1,%hi(g_MpNumPlayers)
/*  f185610:	8c63c530 */ 	lw	$v1,%lo(g_MpNumPlayers)($v1)
/*  f185614:	3c10800b */ 	lui	$s0,%hi(g_MpPlayerChrs)
/*  f185618:	2610c4d0 */ 	addiu	$s0,$s0,%lo(g_MpPlayerChrs)
/*  f18561c:	18600018 */ 	blez	$v1,.L0f185680
/*  f185620:	00008825 */ 	or	$s1,$zero,$zero
.L0f185624:
/*  f185624:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f185628:	8d0902d4 */ 	lw	$t1,0x2d4($t0)
/*  f18562c:	55200011 */ 	bnezl	$t1,.L0f185674
/*  f185630:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f185634:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f185638:	02202025 */ 	or	$a0,$s1,$zero
/*  f18563c:	928a0060 */ 	lbu	$t2,0x60($s4)
/*  f185640:	02a02025 */ 	or	$a0,$s5,$zero
/*  f185644:	00002825 */ 	or	$a1,$zero,$zero
/*  f185648:	566a0004 */ 	bnel	$s3,$t2,.L0f18565c
/*  f18564c:	02402025 */ 	or	$a0,$s2,$zero
/*  f185650:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f185654:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f185658:	02402025 */ 	or	$a0,$s2,$zero
.L0f18565c:
/*  f18565c:	00002825 */ 	or	$a1,$zero,$zero
/*  f185660:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f185664:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f185668:	3c03800b */ 	lui	$v1,%hi(g_MpNumPlayers)
/*  f18566c:	8c63c530 */ 	lw	$v1,%lo(g_MpNumPlayers)($v1)
/*  f185670:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f185674:
/*  f185674:	0223082a */ 	slt	$at,$s1,$v1
/*  f185678:	1420ffea */ 	bnez	$at,.L0f185624
/*  f18567c:	26100004 */ 	addiu	$s0,$s0,0x4
.L0f185680:
/*  f185680:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f185684:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*  f185688:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f18568c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f185690:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f185694:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f185698:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18569c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f1856a0:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f1856a4:	03e00008 */ 	jr	$ra
/*  f1856a8:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);

void scenarioCallback10(void)
{
	if (g_Vars.normmplayerisrunning) {
		if (g_Vars.lvframenum == 5) {
			func0f185568();
		}

		if (g_MpScenarios[g_MpSetup.scenario].unk10) {
			g_MpScenarios[g_MpSetup.scenario].unk10();
		}
	}
}

void scenarioCallback14(struct chrdata *chr)
{
	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].unk14) {
		g_MpScenarios[g_MpSetup.scenario].unk14(chr);
	}
}

GLOBAL_ASM(
glabel func0f185774
/*  f185774:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f185778:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f18577c:	8d2e0318 */ 	lw	$t6,0x318($t1)
/*  f185780:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f185784:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f185788:	11c0011d */ 	beqz	$t6,.L0f185c00
/*  f18578c:	00802825 */ 	or	$a1,$a0,$zero
/*  f185790:	3c0a800b */ 	lui	$t2,%hi(g_MpSetup)
/*  f185794:	254acb88 */ 	addiu	$t2,$t2,%lo(g_MpSetup)
/*  f185798:	914f0010 */ 	lbu	$t7,0x10($t2)
/*  f18579c:	240b0048 */ 	addiu	$t3,$zero,0x48
/*  f1857a0:	3c088008 */ 	lui	$t0,%hi(g_MpScenarios)
/*  f1857a4:	01eb0019 */ 	multu	$t7,$t3
/*  f1857a8:	25086f98 */ 	addiu	$t0,$t0,%lo(g_MpScenarios)
/*  f1857ac:	0000c012 */ 	mflo	$t8
/*  f1857b0:	0118c821 */ 	addu	$t9,$t0,$t8
/*  f1857b4:	8f2c0018 */ 	lw	$t4,0x18($t9)
/*  f1857b8:	51800041 */ 	beqzl	$t4,.L0f1858c0
/*  f1857bc:	8d2d006c */ 	lw	$t5,0x6c($t1)
/*  f1857c0:	914d001e */ 	lbu	$t5,0x1e($t2)
/*  f1857c4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1857c8:	3c0e8008 */ 	lui	$t6,%hi(g_NumReasonsToEndMpMatch)
/*  f1857cc:	51a1003c */ 	beql	$t5,$at,.L0f1858c0
/*  f1857d0:	8d2d006c */ 	lw	$t5,0x6c($t1)
/*  f1857d4:	8dce4038 */ 	lw	$t6,%lo(g_NumReasonsToEndMpMatch)($t6)
/*  f1857d8:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1857dc:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f1857e0:	15c00036 */ 	bnez	$t6,.L0f1858bc
/*  f1857e4:	24830008 */ 	addiu	$v1,$a0,0x8
/*  f1857e8:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1857ec:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f1857f0:	3c18ba00 */ 	lui	$t8,0xba00
/*  f1857f4:	37180602 */ 	ori	$t8,$t8,0x602
/*  f1857f8:	241900c0 */ 	addiu	$t9,$zero,0xc0
/*  f1857fc:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f185800:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f185804:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f185808:	3c0cb600 */ 	lui	$t4,0xb600
/*  f18580c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f185810:	ac8d0004 */ 	sw	$t5,0x4($a0)
/*  f185814:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f185818:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f18581c:	3c0ee700 */ 	lui	$t6,0xe700
/*  f185820:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f185824:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f185828:	3c0fba00 */ 	lui	$t7,0xba00
/*  f18582c:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f185830:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f185834:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f185838:	24e20008 */ 	addiu	$v0,$a3,0x8
/*  f18583c:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f185840:	3c18ba00 */ 	lui	$t8,0xba00
/*  f185844:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f185848:	24430008 */ 	addiu	$v1,$v0,0x8
/*  f18584c:	3c190030 */ 	lui	$t9,0x30
/*  f185850:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f185854:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f185858:	3c0cb900 */ 	lui	$t4,0xb900
/*  f18585c:	3c0d0f0a */ 	lui	$t5,0xf0a
/*  f185860:	35ad4000 */ 	ori	$t5,$t5,0x4000
/*  f185864:	358c031d */ 	ori	$t4,$t4,0x31d
/*  f185868:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f18586c:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f185870:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f185874:	3c0eba00 */ 	lui	$t6,0xba00
/*  f185878:	35ce1701 */ 	ori	$t6,$t6,0x1701
/*  f18587c:	3c0f0080 */ 	lui	$t7,0x80
/*  f185880:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f185884:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f185888:	91580010 */ 	lbu	$t8,0x10($t2)
/*  f18588c:	24c40008 */ 	addiu	$a0,$a2,0x8
/*  f185890:	030b0019 */ 	multu	$t8,$t3
/*  f185894:	0000c812 */ 	mflo	$t9
/*  f185898:	01196021 */ 	addu	$t4,$t0,$t9
/*  f18589c:	8d990018 */ 	lw	$t9,0x18($t4)
/*  f1858a0:	0320f809 */ 	jalr	$t9
/*  f1858a4:	00000000 */ 	nop
/*  f1858a8:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f1858ac:	3c0a800b */ 	lui	$t2,%hi(g_MpSetup)
/*  f1858b0:	254acb88 */ 	addiu	$t2,$t2,%lo(g_MpSetup)
/*  f1858b4:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f1858b8:	00402825 */ 	or	$a1,$v0,$zero
.L0f1858bc:
/*  f1858bc:	8d2d006c */ 	lw	$t5,0x6c($t1)
.L0f1858c0:
/*  f1858c0:	00004025 */ 	or	$t0,$zero,$zero
/*  f1858c4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1858c8:	11a00003 */ 	beqz	$t5,.L0f1858d8
/*  f1858cc:	00003825 */ 	or	$a3,$zero,$zero
/*  f1858d0:	10000001 */ 	b	.L0f1858d8
/*  f1858d4:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f1858d8:
/*  f1858d8:	8d2e0068 */ 	lw	$t6,0x68($t1)
/*  f1858dc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1858e0:	11c00003 */ 	beqz	$t6,.L0f1858f0
/*  f1858e4:	00000000 */ 	nop
/*  f1858e8:	10000001 */ 	b	.L0f1858f0
/*  f1858ec:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1858f0:
/*  f1858f0:	8d2f0064 */ 	lw	$t7,0x64($t1)
/*  f1858f4:	11e00003 */ 	beqz	$t7,.L0f185904
/*  f1858f8:	00000000 */ 	nop
/*  f1858fc:	10000001 */ 	b	.L0f185904
/*  f185900:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f185904:
/*  f185904:	8d380070 */ 	lw	$t8,0x70($t1)
/*  f185908:	13000003 */ 	beqz	$t8,.L0f185918
/*  f18590c:	00000000 */ 	nop
/*  f185910:	10000001 */ 	b	.L0f185918
/*  f185914:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f185918:
/*  f185918:	8d44000c */ 	lw	$a0,0xc($t2)
/*  f18591c:	00476021 */ 	addu	$t4,$v0,$a3
/*  f185920:	0186c821 */ 	addu	$t9,$t4,$a2
/*  f185924:	03281821 */ 	addu	$v1,$t9,$t0
/*  f185928:	308d0002 */ 	andi	$t5,$a0,0x2
/*  f18592c:	11a000b4 */ 	beqz	$t5,.L0f185c00
/*  f185930:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f185934:	308e0200 */ 	andi	$t6,$a0,0x200
/*  f185938:	11c000b1 */ 	beqz	$t6,.L0f185c00
/*  f18593c:	28610002 */ 	slti	$at,$v1,0x2
/*  f185940:	142000af */ 	bnez	$at,.L0f185c00
/*  f185944:	00a01025 */ 	or	$v0,$a1,$zero
/*  f185948:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f18594c:	8d2c028c */ 	lw	$t4,0x28c($t1)
/*  f185950:	3c19ba00 */ 	lui	$t9,0xba00
/*  f185954:	8df800bc */ 	lw	$t8,0xbc($t7)
/*  f185958:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f18595c:	24a30008 */ 	addiu	$v1,$a1,0x8
/*  f185960:	8f080004 */ 	lw	$t0,0x4($t8)
/*  f185964:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f185968:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f18596c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f185970:	3c0dba00 */ 	lui	$t5,0xba00
/*  f185974:	35ad0602 */ 	ori	$t5,$t5,0x602
/*  f185978:	240e00c0 */ 	addiu	$t6,$zero,0xc0
/*  f18597c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f185980:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f185984:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f185988:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f18598c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f185990:	3c0fb600 */ 	lui	$t7,0xb600
/*  f185994:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f185998:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f18599c:	3c0ce700 */ 	lui	$t4,0xe700
/*  f1859a0:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f1859a4:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1859a8:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f1859ac:	3c19ba00 */ 	lui	$t9,0xba00
/*  f1859b0:	37391301 */ 	ori	$t9,$t9,0x1301
/*  f1859b4:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f1859b8:	24e20008 */ 	addiu	$v0,$a3,0x8
/*  f1859bc:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f1859c0:	3c0dba00 */ 	lui	$t5,0xba00
/*  f1859c4:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*  f1859c8:	24430008 */ 	addiu	$v1,$v0,0x8
/*  f1859cc:	3c0e0030 */ 	lui	$t6,0x30
/*  f1859d0:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f1859d4:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f1859d8:	3c180f0a */ 	lui	$t8,0xf0a
/*  f1859dc:	3c0fb900 */ 	lui	$t7,0xb900
/*  f1859e0:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f1859e4:	37184000 */ 	ori	$t8,$t8,0x4000
/*  f1859e8:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1859ec:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f1859f0:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f1859f4:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1859f8:	358c1701 */ 	ori	$t4,$t4,0x1701
/*  f1859fc:	3c190080 */ 	lui	$t9,0x80
/*  f185a00:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f185a04:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f185a08:	24c50008 */ 	addiu	$a1,$a2,0x8
/*  f185a0c:	91040125 */ 	lbu	$a0,0x125($t0)
/*  f185a10:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f185a14:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f185a18:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f185a1c:	00026880 */ 	sll	$t5,$v0,0x2
/*  f185a20:	3c048008 */ 	lui	$a0,%hi(var80087ce4)
/*  f185a24:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f185a28:	8c847ce4 */ 	lw	$a0,%lo(var80087ce4)($a0)
/*  f185a2c:	3c0ef700 */ 	lui	$t6,0xf700
/*  f185a30:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f185a34:	24650008 */ 	addiu	$a1,$v1,0x8
/*  f185a38:	ac640004 */ 	sw	$a0,0x4($v1)
/*  f185a3c:	0c002f40 */ 	jal	viGetViewLeft
/*  f185a40:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f185a44:	0c002f22 */ 	jal	viGetViewWidth
/*  f185a48:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f185a4c:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f185a50:	00463821 */ 	addu	$a3,$v0,$a2
/*  f185a54:	0c002f44 */ 	jal	viGetViewTop
/*  f185a58:	afa70028 */ 	sw	$a3,0x28($sp)
/*  f185a5c:	0c002f26 */ 	jal	viGetViewHeight
/*  f185a60:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f185a64:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f185a68:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f185a6c:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f185a70:	29e10003 */ 	slti	$at,$t7,0x3
/*  f185a74:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f185a78:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f185a7c:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f185a80:	14200027 */ 	bnez	$at,.L0f185b20
/*  f185a84:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f185a88:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f185a8c:	310303ff */ 	andi	$v1,$t0,0x3ff
/*  f185a90:	00037880 */ 	sll	$t7,$v1,0x2
/*  f185a94:	2b010002 */ 	slti	$at,$t8,0x2
/*  f185a98:	10200013 */ 	beqz	$at,.L0f185ae8
/*  f185a9c:	01e01825 */ 	or	$v1,$t7,$zero
/*  f185aa0:	00482021 */ 	addu	$a0,$v0,$t0
/*  f185aa4:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f185aa8:	24edffff */ 	addiu	$t5,$a3,-1
/*  f185aac:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f185ab0:	308c03ff */ 	andi	$t4,$a0,0x3ff
/*  f185ab4:	000c2080 */ 	sll	$a0,$t4,0x2
/*  f185ab8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f185abc:	3c01f600 */ 	lui	$at,0xf600
/*  f185ac0:	30d903ff */ 	andi	$t9,$a2,0x3ff
/*  f185ac4:	00196b80 */ 	sll	$t5,$t9,0xe
/*  f185ac8:	01e1c025 */ 	or	$t8,$t7,$at
/*  f185acc:	00a01825 */ 	or	$v1,$a1,$zero
/*  f185ad0:	03046025 */ 	or	$t4,$t8,$a0
/*  f185ad4:	01a47025 */ 	or	$t6,$t5,$a0
/*  f185ad8:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f185adc:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f185ae0:	10000047 */ 	b	.L0f185c00
/*  f185ae4:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f185ae8:
/*  f185ae8:	24f8ffff */ 	addiu	$t8,$a3,-1
/*  f185aec:	330c03ff */ 	andi	$t4,$t8,0x3ff
/*  f185af0:	000ccb80 */ 	sll	$t9,$t4,0xe
/*  f185af4:	3c01f600 */ 	lui	$at,0xf600
/*  f185af8:	03216825 */ 	or	$t5,$t9,$at
/*  f185afc:	01af7025 */ 	or	$t6,$t5,$t7
/*  f185b00:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f185b04:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f185b08:	00a01025 */ 	or	$v0,$a1,$zero
/*  f185b0c:	03036025 */ 	or	$t4,$t8,$v1
/*  f185b10:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f185b14:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f185b18:	10000039 */ 	b	.L0f185c00
/*  f185b1c:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f185b20:
/*  f185b20:	913904e0 */ 	lbu	$t9,0x4e0($t1)
/*  f185b24:	00a01825 */ 	or	$v1,$a1,$zero
/*  f185b28:	00482021 */ 	addu	$a0,$v0,$t0
/*  f185b2c:	13200011 */ 	beqz	$t9,.L0f185b74
/*  f185b30:	8fac001c */ 	lw	$t4,0x1c($sp)
/*  f185b34:	2484fffe */ 	addiu	$a0,$a0,-2
/*  f185b38:	24efffff */ 	addiu	$t7,$a3,-1
/*  f185b3c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f185b40:	308d03ff */ 	andi	$t5,$a0,0x3ff
/*  f185b44:	000d2080 */ 	sll	$a0,$t5,0x2
/*  f185b48:	00186380 */ 	sll	$t4,$t8,0xe
/*  f185b4c:	3c01f600 */ 	lui	$at,0xf600
/*  f185b50:	30ce03ff */ 	andi	$t6,$a2,0x3ff
/*  f185b54:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f185b58:	0181c825 */ 	or	$t9,$t4,$at
/*  f185b5c:	03246825 */ 	or	$t5,$t9,$a0
/*  f185b60:	01e4c025 */ 	or	$t8,$t7,$a0
/*  f185b64:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f185b68:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f185b6c:	10000024 */ 	b	.L0f185c00
/*  f185b70:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f185b74:
/*  f185b74:	15800013 */ 	bnez	$t4,.L0f185bc4
/*  f185b78:	310303ff */ 	andi	$v1,$t0,0x3ff
/*  f185b7c:	00482021 */ 	addu	$a0,$v0,$t0
/*  f185b80:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f185b84:	24eeffff */ 	addiu	$t6,$a3,-1
/*  f185b88:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f185b8c:	309903ff */ 	andi	$t9,$a0,0x3ff
/*  f185b90:	00192080 */ 	sll	$a0,$t9,0x2
/*  f185b94:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f185b98:	3c01f600 */ 	lui	$at,0xf600
/*  f185b9c:	30cd03ff */ 	andi	$t5,$a2,0x3ff
/*  f185ba0:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f185ba4:	03016025 */ 	or	$t4,$t8,$at
/*  f185ba8:	00a01825 */ 	or	$v1,$a1,$zero
/*  f185bac:	0184c825 */ 	or	$t9,$t4,$a0
/*  f185bb0:	01c47825 */ 	or	$t7,$t6,$a0
/*  f185bb4:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f185bb8:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f185bbc:	10000010 */ 	b	.L0f185c00
/*  f185bc0:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f185bc4:
/*  f185bc4:	24ecffff */ 	addiu	$t4,$a3,-1
/*  f185bc8:	319903ff */ 	andi	$t9,$t4,0x3ff
/*  f185bcc:	00196b80 */ 	sll	$t5,$t9,0xe
/*  f185bd0:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f185bd4:	3c01f600 */ 	lui	$at,0xf600
/*  f185bd8:	01a17025 */ 	or	$t6,$t5,$at
/*  f185bdc:	01d87825 */ 	or	$t7,$t6,$t8
/*  f185be0:	03001825 */ 	or	$v1,$t8,$zero
/*  f185be4:	30d803ff */ 	andi	$t8,$a2,0x3ff
/*  f185be8:	00a01025 */ 	or	$v0,$a1,$zero
/*  f185bec:	00186380 */ 	sll	$t4,$t8,0xe
/*  f185bf0:	0183c825 */ 	or	$t9,$t4,$v1
/*  f185bf4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f185bf8:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f185bfc:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f185c00:
/*  f185c00:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f185c04:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f185c08:	00a01025 */ 	or	$v0,$a1,$zero
/*  f185c0c:	03e00008 */ 	jr	$ra
/*  f185c10:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f185c14
/*  f185c14:	3c0b800b */ 	lui	$t3,%hi(g_MpSetup)
/*  f185c18:	256bcb88 */ 	addiu	$t3,$t3,%lo(g_MpSetup)
/*  f185c1c:	916e0010 */ 	lbu	$t6,0x10($t3)
/*  f185c20:	3c028008 */ 	lui	$v0,%hi(g_MpScenarios+0x1c)
/*  f185c24:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f185c28:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f185c2c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f185c30:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f185c34:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f185c38:	8c426fb4 */ 	lw	$v0,%lo(g_MpScenarios+0x1c)($v0)
/*  f185c3c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f185c40:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f185c44:	00808025 */ 	or	$s0,$a0,$zero
/*  f185c48:	00a08825 */ 	or	$s1,$a1,$zero
/*  f185c4c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f185c50:	10400005 */ 	beqz	$v0,.L0f185c68
/*  f185c54:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f185c58:	0040f809 */ 	jalr	$v0
/*  f185c5c:	00000000 */ 	nop
/*  f185c60:	1000003b */ 	b	.L0f185d50
/*  f185c64:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f185c68:
/*  f185c68:	3c09800b */ 	lui	$t1,%hi(g_MpSimulants)
/*  f185c6c:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f185c70:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f185c74:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f185c78:	2529c538 */ 	addiu	$t1,$t1,%lo(g_MpSimulants)
/*  f185c7c:	00001025 */ 	or	$v0,$zero,$zero
/*  f185c80:	02001825 */ 	or	$v1,$s0,$zero
/*  f185c84:	240a004c */ 	addiu	$t2,$zero,0x4c
/*  f185c88:	240800a0 */ 	addiu	$t0,$zero,0xa0
/*  f185c8c:	2405000c */ 	addiu	$a1,$zero,0xc
.L0f185c90:
/*  f185c90:	54510007 */ 	bnel	$v0,$s1,.L0f185cb0
/*  f185c94:	8d6d000c */ 	lw	$t5,0xc($t3)
/*  f185c98:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f185c9c:	84790024 */ 	lh	$t9,0x24($v1)
/*  f185ca0:	03196023 */ 	subu	$t4,$t8,$t9
/*  f185ca4:	10000023 */ 	b	.L0f185d34
/*  f185ca8:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f185cac:	8d6d000c */ 	lw	$t5,0xc($t3)
.L0f185cb0:
/*  f185cb0:	28410004 */ 	slti	$at,$v0,0x4
/*  f185cb4:	31ae0002 */ 	andi	$t6,$t5,0x2
/*  f185cb8:	51c0001b */ 	beqzl	$t6,.L0f185d28
/*  f185cbc:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f185cc0:	10200006 */ 	beqz	$at,.L0f185cdc
/*  f185cc4:	00000000 */ 	nop
/*  f185cc8:	00480019 */ 	multu	$v0,$t0
/*  f185ccc:	00007812 */ 	mflo	$t7
/*  f185cd0:	00ef2021 */ 	addu	$a0,$a3,$t7
/*  f185cd4:	10000006 */ 	b	.L0f185cf0
/*  f185cd8:	92190011 */ 	lbu	$t9,0x11($s0)
.L0f185cdc:
/*  f185cdc:	004a0019 */ 	multu	$v0,$t2
/*  f185ce0:	0000c012 */ 	mflo	$t8
/*  f185ce4:	01382021 */ 	addu	$a0,$t1,$t8
/*  f185ce8:	2484fed0 */ 	addiu	$a0,$a0,-304
/*  f185cec:	92190011 */ 	lbu	$t9,0x11($s0)
.L0f185cf0:
/*  f185cf0:	908c0011 */ 	lbu	$t4,0x11($a0)
/*  f185cf4:	572c0007 */ 	bnel	$t9,$t4,.L0f185d14
/*  f185cf8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f185cfc:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f185d00:	846e0024 */ 	lh	$t6,0x24($v1)
/*  f185d04:	01ae7823 */ 	subu	$t7,$t5,$t6
/*  f185d08:	1000000a */ 	b	.L0f185d34
/*  f185d0c:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f185d10:	8cd80000 */ 	lw	$t8,0x0($a2)
.L0f185d14:
/*  f185d14:	84790024 */ 	lh	$t9,0x24($v1)
/*  f185d18:	03196021 */ 	addu	$t4,$t8,$t9
/*  f185d1c:	10000005 */ 	b	.L0f185d34
/*  f185d20:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f185d24:	8ccd0000 */ 	lw	$t5,0x0($a2)
.L0f185d28:
/*  f185d28:	846e0024 */ 	lh	$t6,0x24($v1)
/*  f185d2c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f185d30:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f185d34:
/*  f185d34:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f185d38:	1445ffd5 */ 	bne	$v0,$a1,.L0f185c90
/*  f185d3c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f185d40:	8618003c */ 	lh	$t8,0x3c($s0)
/*  f185d44:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*  f185d48:	af380000 */ 	sw	$t8,0x0($t9)
/*  f185d4c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f185d50:
/*  f185d50:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f185d54:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f185d58:	03e00008 */ 	jr	$ra
/*  f185d5c:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

Gfx *scenarioRadar(Gfx *gdl)
{
	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].radarfunc) {
		return g_MpScenarios[g_MpSetup.scenario].radarfunc(gdl);
	}

	return gdl;
}

bool scenarioRadar2(Gfx **gdl, struct prop *prop)
{
	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].radar2func) {
		return g_MpScenarios[g_MpSetup.scenario].radar2func(gdl, prop);
	}

	return false;
}

GLOBAL_ASM(
glabel func0f185e20
.late_rodata
glabel var7f1b8980
.word func0f185e20+0xf4 # f185f14
glabel var7f1b8984
.word func0f185e20+0xf4 # f185f14
glabel var7f1b8988
.word func0f185e20+0x348 # f186168
glabel var7f1b898c
.word func0f185e20+0x348 # f186168
glabel var7f1b8990
.word func0f185e20+0x348 # f186168
glabel var7f1b8994
.word func0f185e20+0x348 # f186168
glabel var7f1b8998
.word func0f185e20+0x348 # f186168
glabel var7f1b899c
.word func0f185e20+0xf4 # f185f14
glabel var7f1b89a0
.word func0f185e20+0x348 # f186168
glabel var7f1b89a4
.word func0f185e20+0x348 # f186168
glabel var7f1b89a8
.word func0f185e20+0x348 # f186168
glabel var7f1b89ac
.word func0f185e20+0x348 # f186168
glabel var7f1b89b0
.word func0f185e20+0x348 # f186168
glabel var7f1b89b4
.word func0f185e20+0xf4 # f185f14
glabel var7f1b89b8
.word func0f185e20+0xf4 # f185f14
.text
/*  f185e20:	3c07800b */ 	lui	$a3,%hi(g_MpSetup)
/*  f185e24:	24e7cb88 */ 	addiu	$a3,$a3,%lo(g_MpSetup)
/*  f185e28:	90ee0010 */ 	lbu	$t6,0x10($a3)
/*  f185e2c:	3c028008 */ 	lui	$v0,%hi(g_MpScenarios+0x28)
/*  f185e30:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f185e34:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f185e38:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f185e3c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f185e40:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f185e44:	8c426fc0 */ 	lw	$v0,%lo(g_MpScenarios+0x28)($v0)
/*  f185e48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f185e4c:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f185e50:	5040000a */ 	beqzl	$v0,.L0f185e7c
/*  f185e54:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f185e58:	0040f809 */ 	jalr	$v0
/*  f185e5c:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f185e60:	3c07800b */ 	lui	$a3,%hi(g_MpSetup)
/*  f185e64:	24e7cb88 */ 	addiu	$a3,$a3,%lo(g_MpSetup)
/*  f185e68:	10400003 */ 	beqz	$v0,.L0f185e78
/*  f185e6c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f185e70:	100000be */ 	b	.L0f18616c
/*  f185e74:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f185e78:
/*  f185e78:	8fb80030 */ 	lw	$t8,0x30($sp)
.L0f185e7c:
/*  f185e7c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f185e80:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f185e84:	10410005 */ 	beq	$v0,$at,.L0f185e9c
/*  f185e88:	24010002 */ 	addiu	$at,$zero,0x2
/*  f185e8c:	10410003 */ 	beq	$v0,$at,.L0f185e9c
/*  f185e90:	24010004 */ 	addiu	$at,$zero,0x4
/*  f185e94:	54410032 */ 	bnel	$v0,$at,.L0f185f60
/*  f185e98:	24010003 */ 	addiu	$at,$zero,0x3
.L0f185e9c:
/*  f185e9c:	90e90010 */ 	lbu	$t1,0x10($a3)
/*  f185ea0:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f185ea4:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x288)
/*  f185ea8:	15200005 */ 	bnez	$t1,.L0f185ec0
/*  f185eac:	8f220004 */ 	lw	$v0,0x4($t9)
/*  f185eb0:	8cea000c */ 	lw	$t2,0xc($a3)
/*  f185eb4:	314b0020 */ 	andi	$t3,$t2,0x20
/*  f185eb8:	556000ac */ 	bnezl	$t3,.L0f18616c
/*  f185ebc:	00001025 */ 	or	$v0,$zero,$zero
.L0f185ec0:
/*  f185ec0:	8d8ca248 */ 	lw	$t4,%lo(g_Vars+0x288)($t4)
/*  f185ec4:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers+0x14)
/*  f185ec8:	8d8d0070 */ 	lw	$t5,0x70($t4)
/*  f185ecc:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f185ed0:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f185ed4:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f185ed8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f185edc:	8defc7cc */ 	lw	$t7,%lo(g_MpPlayers+0x14)($t7)
/*  f185ee0:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f185ee4:	530000a1 */ 	beqzl	$t8,.L0f18616c
/*  f185ee8:	00001025 */ 	or	$v0,$zero,$zero
/*  f185eec:	90590003 */ 	lbu	$t9,0x3($v0)
/*  f185ef0:	2729fff9 */ 	addiu	$t1,$t9,-7
/*  f185ef4:	2d21000f */ 	sltiu	$at,$t1,0xf
/*  f185ef8:	1020009b */ 	beqz	$at,.L0f186168
/*  f185efc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f185f00:	3c017f1c */ 	lui	$at,%hi(var7f1b8980)
/*  f185f04:	00290821 */ 	addu	$at,$at,$t1
/*  f185f08:	8c298980 */ 	lw	$t1,%lo(var7f1b8980)($at)
/*  f185f0c:	01200008 */ 	jr	$t1
/*  f185f10:	00000000 */ 	nop
/*  f185f14:	240a00cd */ 	addiu	$t2,$zero,0xcd
/*  f185f18:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f185f1c:	3c0141a0 */ 	lui	$at,0x41a0
/*  f185f20:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f185f24:	acaa0004 */ 	sw	$t2,0x4($a1)
/*  f185f28:	acab0008 */ 	sw	$t3,0x8($a1)
/*  f185f2c:	44816000 */ 	mtc1	$at,$f12
/*  f185f30:	0fc01ac2 */ 	jal	func0f006b08
/*  f185f34:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f185f38:	3c01437f */ 	lui	$at,0x437f
/*  f185f3c:	44812000 */ 	mtc1	$at,$f4
/*  f185f40:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f185f44:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f185f48:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f185f4c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f185f50:	440d4000 */ 	mfc1	$t5,$f8
/*  f185f54:	10000085 */ 	b	.L0f18616c
/*  f185f58:	acad000c */ 	sw	$t5,0xc($a1)
/*  f185f5c:	24010003 */ 	addiu	$at,$zero,0x3
.L0f185f60:
/*  f185f60:	10410004 */ 	beq	$v0,$at,.L0f185f74
/*  f185f64:	00003025 */ 	or	$a2,$zero,$zero
/*  f185f68:	24010006 */ 	addiu	$at,$zero,0x6
/*  f185f6c:	5441007f */ 	bnel	$v0,$at,.L0f18616c
/*  f185f70:	00001025 */ 	or	$v0,$zero,$zero
.L0f185f74:
/*  f185f74:	8cee000c */ 	lw	$t6,0xc($a3)
/*  f185f78:	00001825 */ 	or	$v1,$zero,$zero
/*  f185f7c:	00004025 */ 	or	$t0,$zero,$zero
/*  f185f80:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f185f84:	11e00017 */ 	beqz	$t7,.L0f185fe4
/*  f185f88:	00002025 */ 	or	$a0,$zero,$zero
/*  f185f8c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f185f90:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f185f94:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f185f98:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f185f9c:	0fc3f594 */ 	jal	currentPlayerGetCommandingAibot
/*  f185fa0:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f185fa4:	3c07800b */ 	lui	$a3,%hi(g_MpSetup)
/*  f185fa8:	24e7cb88 */ 	addiu	$a3,$a3,%lo(g_MpSetup)
/*  f185fac:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f185fb0:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f185fb4:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f185fb8:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f185fbc:	10400009 */ 	beqz	$v0,.L0f185fe4
/*  f185fc0:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f185fc4:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f185fc8:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f185fcc:	54590005 */ 	bnel	$v0,$t9,.L0f185fe4
/*  f185fd0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f185fd4:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f185fd8:	10000002 */ 	b	.L0f185fe4
/*  f185fdc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f185fe0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f185fe4:
/*  f185fe4:	14c00025 */ 	bnez	$a2,.L0f18607c
/*  f185fe8:	00000000 */ 	nop
/*  f185fec:	14600023 */ 	bnez	$v1,.L0f18607c
/*  f185ff0:	00000000 */ 	nop
/*  f185ff4:	90e90010 */ 	lbu	$t1,0x10($a3)
/*  f185ff8:	8ce2000c */ 	lw	$v0,0xc($a3)
/*  f185ffc:	15200002 */ 	bnez	$t1,.L0f186008
/*  f186000:	304a0010 */ 	andi	$t2,$v0,0x10
/*  f186004:	1540001d */ 	bnez	$t2,.L0f18607c
.L0f186008:
/*  f186008:	304b0002 */ 	andi	$t3,$v0,0x2
/*  f18600c:	1160000e */ 	beqz	$t3,.L0f186048
/*  f186010:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x288)
/*  f186014:	8d8ca248 */ 	lw	$t4,%lo(g_Vars+0x288)($t4)
/*  f186018:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers+0x14)
/*  f18601c:	8d8d0070 */ 	lw	$t5,0x70($t4)
/*  f186020:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f186024:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f186028:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18602c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f186030:	8defc7cc */ 	lw	$t7,%lo(g_MpPlayers+0x14)($t7)
/*  f186034:	31f80008 */ 	andi	$t8,$t7,0x8
/*  f186038:	13000003 */ 	beqz	$t8,.L0f186048
/*  f18603c:	00000000 */ 	nop
/*  f186040:	1000000e */ 	b	.L0f18607c
/*  f186044:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186048:
/*  f186048:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x288)
/*  f18604c:	8f39a248 */ 	lw	$t9,%lo(g_Vars+0x288)($t9)
/*  f186050:	3c0b800b */ 	lui	$t3,%hi(g_MpPlayers+0x14)
/*  f186054:	8f290070 */ 	lw	$t1,0x70($t9)
/*  f186058:	00095080 */ 	sll	$t2,$t1,0x2
/*  f18605c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f186060:	000a5140 */ 	sll	$t2,$t2,0x5
/*  f186064:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f186068:	8d6bc7cc */ 	lw	$t3,%lo(g_MpPlayers+0x14)($t3)
/*  f18606c:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f186070:	11800002 */ 	beqz	$t4,.L0f18607c
/*  f186074:	00000000 */ 	nop
/*  f186078:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f18607c:
/*  f18607c:	10800027 */ 	beqz	$a0,.L0f18611c
/*  f186080:	8fad0030 */ 	lw	$t5,0x30($sp)
/*  f186084:	8dae0004 */ 	lw	$t6,0x4($t5)
/*  f186088:	91c40125 */ 	lbu	$a0,0x125($t6)
/*  f18608c:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f186090:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f186094:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f186098:	00027880 */ 	sll	$t7,$v0,0x2
/*  f18609c:	3c038008 */ 	lui	$v1,%hi(g_TeamColours)
/*  f1860a0:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f1860a4:	8c637cc4 */ 	lw	$v1,%lo(g_TeamColours)($v1)
/*  f1860a8:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f1860ac:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f1860b0:	0003c602 */ 	srl	$t8,$v1,0x18
/*  f1860b4:	00034c02 */ 	srl	$t1,$v1,0x10
/*  f1860b8:	00035a02 */ 	srl	$t3,$v1,0x8
/*  f1860bc:	331900ff */ 	andi	$t9,$t8,0xff
/*  f1860c0:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f1860c4:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f1860c8:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f1860cc:	acaa0004 */ 	sw	$t2,0x4($a1)
/*  f1860d0:	10c0000e */ 	beqz	$a2,.L0f18610c
/*  f1860d4:	acac0008 */ 	sw	$t4,0x8($a1)
/*  f1860d8:	3c0141a0 */ 	lui	$at,0x41a0
/*  f1860dc:	44816000 */ 	mtc1	$at,$f12
/*  f1860e0:	0fc01ac2 */ 	jal	func0f006b08
/*  f1860e4:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f1860e8:	3c014300 */ 	lui	$at,0x4300
/*  f1860ec:	44815000 */ 	mtc1	$at,$f10
/*  f1860f0:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f1860f4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1860f8:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f1860fc:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f186100:	440e9000 */ 	mfc1	$t6,$f18
/*  f186104:	10000019 */ 	b	.L0f18616c
/*  f186108:	acae000c */ 	sw	$t6,0xc($a1)
.L0f18610c:
/*  f18610c:	240f004b */ 	addiu	$t7,$zero,0x4b
/*  f186110:	acaf000c */ 	sw	$t7,0xc($a1)
/*  f186114:	10000015 */ 	b	.L0f18616c
/*  f186118:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18611c:
/*  f18611c:	11000012 */ 	beqz	$t0,.L0f186168
/*  f186120:	241800cd */ 	addiu	$t8,$zero,0xcd
/*  f186124:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f186128:	3c0141a0 */ 	lui	$at,0x41a0
/*  f18612c:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f186130:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f186134:	acb90008 */ 	sw	$t9,0x8($a1)
/*  f186138:	44816000 */ 	mtc1	$at,$f12
/*  f18613c:	0fc01ac2 */ 	jal	func0f006b08
/*  f186140:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f186144:	3c01434d */ 	lui	$at,0x434d
/*  f186148:	44812000 */ 	mtc1	$at,$f4
/*  f18614c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f186150:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f186154:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f186158:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f18615c:	440a4000 */ 	mfc1	$t2,$f8
/*  f186160:	10000002 */ 	b	.L0f18616c
/*  f186164:	acaa000c */ 	sw	$t2,0xc($a1)
.L0f186168:
/*  f186168:	00001025 */ 	or	$v0,$zero,$zero
.L0f18616c:
/*  f18616c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f186170:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f186174:	03e00008 */ 	jr	$ra
/*  f186178:	00000000 */ 	nop
);

f32 scenarioCallback2c(f32 arg0, struct coord *pos, s16 *rooms, struct prop *prop)
{
	f32 result;

	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].unk2c &&
			g_MpScenarios[g_MpSetup.scenario].unk2c(arg0, pos, rooms, prop, &result)) {
		return result;
	}

	return func0f0b72a8(arg0, pos, rooms, prop);
}

void mpPrepareScenario(void)
{
	s32 i;
	s32 j;
	s32 *cmd = g_StageSetup.intro;

	switch (g_MpSetup.scenario) {
	case MPSCENARIO_KINGOFTHEHILL:
		g_ScenarioData.koh.hillcount = 0;
		break;
	case MPSCENARIO_CAPTURETHECASE:
		for (i = 0; i < ARRAYCOUNT(g_ScenarioData.ctc.spawnpadsperteam); i++) {
			g_ScenarioData.ctc.spawnpadsperteam[i].teamindex = -1;
			g_ScenarioData.ctc.spawnpadsperteam[i].numspawnpads = 0;

			for (j = 0; j < ARRAYCOUNT(g_ScenarioData.ctc.spawnpadsperteam[i].spawnpads); j++) {
				g_ScenarioData.ctc.spawnpadsperteam[i].spawnpads[j] = -1;
			}
		}

		for (i = 0; i < ARRAYCOUNT(g_ScenarioData.ctc.unk00); i++) {
			g_ScenarioData.ctc.unk00[i] = 0;
			g_ScenarioData.ctc.teamindexes[i] = -1;
		}
		break;
	case MPSCENARIO_HACKERCENTRAL:
		func0f182bf4();
		break;
	case MPSCENARIO_HOLDTHEBRIEFCASE:
		func0f180078();
		break;
	case MPSCENARIO_POPACAP:
		break;
	}

	if (cmd) {
		while (cmd[0] != INTROCMD_END) {
			switch (cmd[0]) {
			case INTROCMD_SPAWN:
				cmd += 3;
				break;
			case INTROCMD_CASE:
			case INTROCMD_CASERESPAWN:
				if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE) {
					mpCtcAddPad(cmd);
				} else if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
					mpHtmAddPad(cmd[2]);
				} else if (g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE) {
					mpHtbAddPad(cmd[2]);
				}
				cmd += 3;
				break;
			case INTROCMD_HILL:
				if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
					mpKohAddHill(cmd);
				}
				cmd += 2;
				break;
			case INTROCMD_WEAPON:
				cmd += 4;
				break;
			case INTROCMD_AMMO:
				cmd += 4;
				break;
			case INTROCMD_3:
				cmd += 8;
				break;
			case INTROCMD_4:
				cmd += 2;
				break;
			case INTROCMD_OUTFIT:
				cmd += 2;
				break;
			case INTROCMD_6:
				cmd += 10;
				break;
			case INTROCMD_WATCHTIME:
				cmd += 3;
				break;
			case INTROCMD_CREDITOFFSET:
				cmd += 2;
				break;
			default:
				cmd++;
				break;
			}
		}
	}
}

s32 scenarioGetMaxTeams(void)
{
	if (g_MpScenarios[g_MpSetup.scenario].maxteamsfunc) {
		return g_MpScenarios[g_MpSetup.scenario].maxteamsfunc();
	}

	return MAX_TEAMS;
}

bool scenarioIsRoomHighlighted(s16 room)
{
	if (g_MpScenarios[g_MpSetup.scenario].isroomhighlightedfunc) {
		return g_MpScenarios[g_MpSetup.scenario].isroomhighlightedfunc(room);
	}

	return false;
}

void scenarioCallback38(s16 arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
	if (g_MpScenarios[g_MpSetup.scenario].unk38) {
		g_MpScenarios[g_MpSetup.scenario].unk38(arg0, arg1, arg2, arg3);
	}
}

GLOBAL_ASM(
glabel func0f186508
/*  f186508:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f18650c:	3c0f8008 */ 	lui	$t7,%hi(var800871fc)
/*  f186510:	25ef71fc */ 	addiu	$t7,$t7,%lo(var800871fc)
/*  f186514:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f186518:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f18651c:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f186520:	afa60080 */ 	sw	$a2,0x80($sp)
/*  f186524:	afa70084 */ 	sw	$a3,0x84($sp)
/*  f186528:	25e80054 */ 	addiu	$t0,$t7,0x54
/*  f18652c:	27ae001c */ 	addiu	$t6,$sp,0x1c
.L0f186530:
/*  f186530:	8de10000 */ 	lw	$at,0x0($t7)
/*  f186534:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f186538:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f18653c:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f186540:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f186544:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f186548:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f18654c:	15e8fff8 */ 	bne	$t7,$t0,.L0f186530
/*  f186550:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f186554:	8de10000 */ 	lw	$at,0x0($t7)
/*  f186558:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f18655c:	24040060 */ 	addiu	$a0,$zero,0x60
/*  f186560:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f186564:	adc10000 */ 	sw	$at,0x0($t6)
/*  f186568:	0c0048f2 */ 	jal	malloc
/*  f18656c:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f186570:	27a9001c */ 	addiu	$t1,$sp,0x1c
/*  f186574:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f186578:	252c0054 */ 	addiu	$t4,$t1,0x54
/*  f18657c:	00406825 */ 	or	$t5,$v0,$zero
.L0f186580:
/*  f186580:	8d210000 */ 	lw	$at,0x0($t1)
/*  f186584:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f186588:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f18658c:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f186590:	8d21fff8 */ 	lw	$at,-0x8($t1)
/*  f186594:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f186598:	8d21fffc */ 	lw	$at,-0x4($t1)
/*  f18659c:	152cfff8 */ 	bne	$t1,$t4,.L0f186580
/*  f1865a0:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f1865a4:	8d210000 */ 	lw	$at,0x0($t1)
/*  f1865a8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f1865ac:	00402025 */ 	or	$a0,$v0,$zero
/*  f1865b0:	ada10000 */ 	sw	$at,0x0($t5)
/*  f1865b4:	8d2c0004 */ 	lw	$t4,0x4($t1)
/*  f1865b8:	3c014380 */ 	lui	$at,0x4380
/*  f1865bc:	44813000 */ 	mtc1	$at,$f6
/*  f1865c0:	adac0004 */ 	sw	$t4,0x4($t5)
/*  f1865c4:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f1865c8:	3c014f00 */ 	lui	$at,0x4f00
/*  f1865cc:	2405007b */ 	addiu	$a1,$zero,0x7b
/*  f1865d0:	a4590004 */ 	sh	$t9,0x4($v0)
/*  f1865d4:	87b8007e */ 	lh	$t8,0x7e($sp)
/*  f1865d8:	a4580006 */ 	sh	$t8,0x6($v0)
/*  f1865dc:	8fa80084 */ 	lw	$t0,0x84($sp)
/*  f1865e0:	ac480008 */ 	sw	$t0,0x8($v0)
/*  f1865e4:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f1865e8:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f1865ec:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f1865f0:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f1865f4:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f1865f8:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f1865fc:	444bf800 */ 	cfc1	$t3,$31
/*  f186600:	44caf800 */ 	ctc1	$t2,$31
/*  f186604:	00000000 */ 	nop
/*  f186608:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f18660c:	444af800 */ 	cfc1	$t2,$31
/*  f186610:	00000000 */ 	nop
/*  f186614:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f186618:	51400013 */ 	beqzl	$t2,.L0f186668
/*  f18661c:	440a5000 */ 	mfc1	$t2,$f10
/*  f186620:	44815000 */ 	mtc1	$at,$f10
/*  f186624:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f186628:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f18662c:	44caf800 */ 	ctc1	$t2,$31
/*  f186630:	00000000 */ 	nop
/*  f186634:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f186638:	444af800 */ 	cfc1	$t2,$31
/*  f18663c:	00000000 */ 	nop
/*  f186640:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f186644:	15400005 */ 	bnez	$t2,.L0f18665c
/*  f186648:	00000000 */ 	nop
/*  f18664c:	440a5000 */ 	mfc1	$t2,$f10
/*  f186650:	3c018000 */ 	lui	$at,0x8000
/*  f186654:	10000007 */ 	b	.L0f186674
/*  f186658:	01415025 */ 	or	$t2,$t2,$at
.L0f18665c:
/*  f18665c:	10000005 */ 	b	.L0f186674
/*  f186660:	240affff */ 	addiu	$t2,$zero,-1
/*  f186664:	440a5000 */ 	mfc1	$t2,$f10
.L0f186668:
/*  f186668:	00000000 */ 	nop
/*  f18666c:	0540fffb */ 	bltz	$t2,.L0f18665c
/*  f186670:	00000000 */ 	nop
.L0f186674:
/*  f186674:	904c0002 */ 	lbu	$t4,0x2($v0)
/*  f186678:	44cbf800 */ 	ctc1	$t3,$31
/*  f18667c:	a44a0000 */ 	sh	$t2,0x0($v0)
/*  f186680:	3189fffb */ 	andi	$t1,$t4,0xfffb
/*  f186684:	0fc033b9 */ 	jal	setupGenericObject
/*  f186688:	a0490002 */ 	sb	$t1,0x2($v0)
/*  f18668c:	8fad0018 */ 	lw	$t5,0x18($sp)
/*  f186690:	0fc1812f */ 	jal	func0f0604bc
/*  f186694:	8da40014 */ 	lw	$a0,0x14($t5)
/*  f186698:	8fb90018 */ 	lw	$t9,0x18($sp)
/*  f18669c:	0fc180bc */ 	jal	propShow
/*  f1866a0:	8f240014 */ 	lw	$a0,0x14($t9)
/*  f1866a4:	8fb80018 */ 	lw	$t8,0x18($sp)
/*  f1866a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1866ac:	8f020014 */ 	lw	$v0,0x14($t8)
/*  f1866b0:	03e00008 */ 	jr	$ra
/*  f1866b4:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f1866b8
/*  f1866b8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1866bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1866c0:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f1866c4:	0480002a */ 	bltz	$a0,.L0f186770
/*  f1866c8:	00803825 */ 	or	$a3,$a0,$zero
/*  f1866cc:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f1866d0:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f1866d4:	8cae006c */ 	lw	$t6,0x6c($a1)
/*  f1866d8:	00003025 */ 	or	$a2,$zero,$zero
/*  f1866dc:	00001825 */ 	or	$v1,$zero,$zero
/*  f1866e0:	11c00003 */ 	beqz	$t6,.L0f1866f0
/*  f1866e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1866e8:	10000001 */ 	b	.L0f1866f0
/*  f1866ec:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1866f0:
/*  f1866f0:	8caf0068 */ 	lw	$t7,0x68($a1)
/*  f1866f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1866f8:	11e00003 */ 	beqz	$t7,.L0f186708
/*  f1866fc:	00000000 */ 	nop
/*  f186700:	10000001 */ 	b	.L0f186708
/*  f186704:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186708:
/*  f186708:	8cb80064 */ 	lw	$t8,0x64($a1)
/*  f18670c:	13000003 */ 	beqz	$t8,.L0f18671c
/*  f186710:	00000000 */ 	nop
/*  f186714:	10000001 */ 	b	.L0f18671c
/*  f186718:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f18671c:
/*  f18671c:	8cb90070 */ 	lw	$t9,0x70($a1)
/*  f186720:	13200003 */ 	beqz	$t9,.L0f186730
/*  f186724:	00000000 */ 	nop
/*  f186728:	10000001 */ 	b	.L0f186730
/*  f18672c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186730:
/*  f186730:	00444021 */ 	addu	$t0,$v0,$a0
/*  f186734:	01034821 */ 	addu	$t1,$t0,$v1
/*  f186738:	01265021 */ 	addu	$t2,$t1,$a2
/*  f18673c:	00ea082a */ 	slt	$at,$a3,$t2
/*  f186740:	5020000c */ 	beqzl	$at,.L0f186774
/*  f186744:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f186748:	8cab028c */ 	lw	$t3,0x28c($a1)
/*  f18674c:	00e02025 */ 	or	$a0,$a3,$zero
/*  f186750:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186754:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f186758:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f18675c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186760:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f186764:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186768:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f18676c:	8fa4001c */ 	lw	$a0,0x1c($sp)
.L0f186770:
/*  f186770:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f186774:
/*  f186774:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f186778:	03e00008 */ 	jr	$ra
/*  f18677c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f186780
/*  f186780:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup+0xc)
/*  f186784:	8dcecb94 */ 	lw	$t6,%lo(g_MpSetup+0xc)($t6)
/*  f186788:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18678c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f186790:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f186794:	51e0003c */ 	beqzl	$t7,.L0f186888
/*  f186798:	00001025 */ 	or	$v0,$zero,$zero
/*  f18679c:	0482003a */ 	bltzl	$a0,.L0f186888
/*  f1867a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1867a4:	04a20038 */ 	bltzl	$a1,.L0f186888
/*  f1867a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1867ac:	0fc6341d */ 	jal	func0f18d074
/*  f1867b0:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f1867b4:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f1867b8:	0fc6341d */ 	jal	func0f18d074
/*  f1867bc:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f1867c0:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f1867c4:	04620030 */ 	bltzl	$v1,.L0f186888
/*  f1867c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1867cc:	0440002d */ 	bltz	$v0,.L0f186884
/*  f1867d0:	28610004 */ 	slti	$at,$v1,0x4
/*  f1867d4:	10200008 */ 	beqz	$at,.L0f1867f8
/*  f1867d8:	00034080 */ 	sll	$t0,$v1,0x2
/*  f1867dc:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f1867e0:	0303c021 */ 	addu	$t8,$t8,$v1
/*  f1867e4:	3c19800b */ 	lui	$t9,%hi(g_MpPlayers)
/*  f1867e8:	2739c7b8 */ 	addiu	$t9,$t9,%lo(g_MpPlayers)
/*  f1867ec:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f1867f0:	10000009 */ 	b	.L0f186818
/*  f1867f4:	03192021 */ 	addu	$a0,$t8,$t9
.L0f1867f8:
/*  f1867f8:	01034021 */ 	addu	$t0,$t0,$v1
/*  f1867fc:	00084080 */ 	sll	$t0,$t0,0x2
/*  f186800:	01034023 */ 	subu	$t0,$t0,$v1
/*  f186804:	00084080 */ 	sll	$t0,$t0,0x2
/*  f186808:	3c0a800b */ 	lui	$t2,%hi(g_MpSimulants)
/*  f18680c:	254ac538 */ 	addiu	$t2,$t2,%lo(g_MpSimulants)
/*  f186810:	2509fed0 */ 	addiu	$t1,$t0,-304
/*  f186814:	012a2021 */ 	addu	$a0,$t1,$t2
.L0f186818:
/*  f186818:	28410004 */ 	slti	$at,$v0,0x4
/*  f18681c:	10200008 */ 	beqz	$at,.L0f186840
/*  f186820:	00026880 */ 	sll	$t5,$v0,0x2
/*  f186824:	00025880 */ 	sll	$t3,$v0,0x2
/*  f186828:	01625821 */ 	addu	$t3,$t3,$v0
/*  f18682c:	3c0c800b */ 	lui	$t4,%hi(g_MpPlayers)
/*  f186830:	258cc7b8 */ 	addiu	$t4,$t4,%lo(g_MpPlayers)
/*  f186834:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f186838:	10000009 */ 	b	.L0f186860
/*  f18683c:	016c1821 */ 	addu	$v1,$t3,$t4
.L0f186840:
/*  f186840:	01a26821 */ 	addu	$t5,$t5,$v0
/*  f186844:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f186848:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18684c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f186850:	3c0f800b */ 	lui	$t7,%hi(g_MpSimulants)
/*  f186854:	25efc538 */ 	addiu	$t7,$t7,%lo(g_MpSimulants)
/*  f186858:	25aefed0 */ 	addiu	$t6,$t5,-304
/*  f18685c:	01cf1821 */ 	addu	$v1,$t6,$t7
.L0f186860:
/*  f186860:	90780011 */ 	lbu	$t8,0x11($v1)
/*  f186864:	90990011 */ 	lbu	$t9,0x11($a0)
/*  f186868:	00001825 */ 	or	$v1,$zero,$zero
/*  f18686c:	17190003 */ 	bne	$t8,$t9,.L0f18687c
/*  f186870:	00000000 */ 	nop
/*  f186874:	10000004 */ 	b	.L0f186888
/*  f186878:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18687c:
/*  f18687c:	10000002 */ 	b	.L0f186888
/*  f186880:	00601025 */ 	or	$v0,$v1,$zero
.L0f186884:
/*  f186884:	00001025 */ 	or	$v0,$zero,$zero
.L0f186888:
/*  f186888:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18688c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f186890:	03e00008 */ 	jr	$ra
/*  f186894:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel chrGiveBriefcase
/*  f186898:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f18689c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1868a0:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f1868a4:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f1868a8:	afa40128 */ 	sw	$a0,0x128($sp)
/*  f1868ac:	afa5012c */ 	sw	$a1,0x12c($sp)
/*  f1868b0:	3c03800b */ 	lui	$v1,%hi(g_MpSetup+0x10)
/*  f1868b4:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f1868b8:	9063cb98 */ 	lbu	$v1,%lo(g_MpSetup+0x10)($v1)
/*  f1868bc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1868c0:	afa20124 */ 	sw	$v0,0x124($sp)
/*  f1868c4:	146100a5 */ 	bne	$v1,$at,.L0f186b5c
/*  f1868c8:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f1868cc:	8c98001c */ 	lw	$t8,0x1c($a0)
/*  f1868d0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x4)
/*  f1868d4:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f1868d8:	ac38c114 */ 	sw	$t8,%lo(g_ScenarioData+0x4)($at)
/*  f1868dc:	8c9902d4 */ 	lw	$t9,0x2d4($a0)
/*  f1868e0:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f1868e4:	53200017 */ 	beqzl	$t9,.L0f186944
/*  f1868e8:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f1868ec:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1868f0:	00000000 */ 	nop
/*  f1868f4:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1868f8:	3c0b800b */ 	lui	$t3,%hi(var800ac500)
/*  f1868fc:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f186900:	8d6bc500 */ 	lw	$t3,%lo(var800ac500)($t3)
/*  f186904:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f186908:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f18690c:	afab0050 */ 	sw	$t3,0x50($sp)
/*  f186910:	0fc21f03 */ 	jal	propPlayPickupSound
/*  f186914:	9185005c */ 	lbu	$a1,0x5c($t4)
/*  f186918:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f18691c:	24050057 */ 	addiu	$a1,$zero,0x57
/*  f186920:	8c8302d4 */ 	lw	$v1,0x2d4($a0)
/*  f186924:	906e009c */ 	lbu	$t6,0x9c($v1)
/*  f186928:	35d80080 */ 	ori	$t8,$t6,0x80
/*  f18692c:	0fc65fa3 */ 	jal	func0f197e8c
/*  f186930:	a078009c */ 	sb	$t8,0x9c($v1)
/*  f186934:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f186938:	10000020 */ 	b	.L0f1869bc
/*  f18693c:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f186940:	8e39028c */ 	lw	$t9,0x28c($s1)
.L0f186944:
/*  f186944:	3c0c800b */ 	lui	$t4,%hi(g_MpPlayers)
/*  f186948:	258cc7b8 */ 	addiu	$t4,$t4,%lo(g_MpPlayers)
/*  f18694c:	001979c0 */ 	sll	$t7,$t9,0x7
/*  f186950:	022f5021 */ 	addu	$t2,$s1,$t7
/*  f186954:	8d4200e4 */ 	lw	$v0,0xe4($t2)
/*  f186958:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f18695c:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f186960:	28410004 */ 	slti	$at,$v0,0x4
/*  f186964:	10200007 */ 	beqz	$at,.L0f186984
/*  f186968:	00027080 */ 	sll	$t6,$v0,0x2
/*  f18696c:	00025880 */ 	sll	$t3,$v0,0x2
/*  f186970:	01625821 */ 	addu	$t3,$t3,$v0
/*  f186974:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f186978:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f18697c:	10000008 */ 	b	.L0f1869a0
/*  f186980:	afad0050 */ 	sw	$t5,0x50($sp)
.L0f186984:
/*  f186984:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f186988:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18698c:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f186990:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f186994:	25d8fed0 */ 	addiu	$t8,$t6,-304
/*  f186998:	03197821 */ 	addu	$t7,$t8,$t9
/*  f18699c:	afaf0050 */ 	sw	$t7,0x50($sp)
.L0f1869a0:
/*  f1869a0:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f1869a4:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f1869a8:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f1869ac:	0fc221f2 */ 	jal	currentPlayerQueuePickupWeaponHudmsg
/*  f1869b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1869b4:	0fc21f44 */ 	jal	func0f087d10
/*  f1869b8:	24040057 */ 	addiu	$a0,$zero,0x57
.L0f1869bc:
/*  f1869bc:	0fc5b9f1 */ 	jal	langGet
/*  f1869c0:	24045400 */ 	addiu	$a0,$zero,0x5400
/*  f1869c4:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f1869c8:	0fc28874 */ 	jal	weaponGetShortName
/*  f1869cc:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f1869d0:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1869d4:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f1869d8:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f1869dc:	0c004dad */ 	jal	sprintf
/*  f1869e0:	00403825 */ 	or	$a3,$v0,$zero
/*  f1869e4:	8e29006c */ 	lw	$t1,0x6c($s1)
/*  f1869e8:	8e2a028c */ 	lw	$t2,0x28c($s1)
/*  f1869ec:	00008025 */ 	or	$s0,$zero,$zero
/*  f1869f0:	11200003 */ 	beqz	$t1,.L0f186a00
/*  f1869f4:	afaa0118 */ 	sw	$t2,0x118($sp)
/*  f1869f8:	10000002 */ 	b	.L0f186a04
/*  f1869fc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186a00:
/*  f186a00:	00002025 */ 	or	$a0,$zero,$zero
.L0f186a04:
/*  f186a04:	8e280068 */ 	lw	$t0,0x68($s1)
/*  f186a08:	00001825 */ 	or	$v1,$zero,$zero
/*  f186a0c:	00002825 */ 	or	$a1,$zero,$zero
/*  f186a10:	11000003 */ 	beqz	$t0,.L0f186a20
/*  f186a14:	00001025 */ 	or	$v0,$zero,$zero
/*  f186a18:	10000001 */ 	b	.L0f186a20
/*  f186a1c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186a20:
/*  f186a20:	8e270064 */ 	lw	$a3,0x64($s1)
/*  f186a24:	10e00003 */ 	beqz	$a3,.L0f186a34
/*  f186a28:	00000000 */ 	nop
/*  f186a2c:	10000001 */ 	b	.L0f186a34
/*  f186a30:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f186a34:
/*  f186a34:	8e260070 */ 	lw	$a2,0x70($s1)
/*  f186a38:	10c00003 */ 	beqz	$a2,.L0f186a48
/*  f186a3c:	00000000 */ 	nop
/*  f186a40:	10000001 */ 	b	.L0f186a48
/*  f186a44:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186a48:
/*  f186a48:	00455821 */ 	addu	$t3,$v0,$a1
/*  f186a4c:	01636021 */ 	addu	$t4,$t3,$v1
/*  f186a50:	01846821 */ 	addu	$t5,$t4,$a0
/*  f186a54:	19a0002d */ 	blez	$t5,.L0f186b0c
/*  f186a58:	00000000 */ 	nop
/*  f186a5c:	8fae0128 */ 	lw	$t6,0x128($sp)
.L0f186a60:
/*  f186a60:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f186a64:	8dd802d4 */ 	lw	$t8,0x2d4($t6)
/*  f186a68:	17000003 */ 	bnez	$t8,.L0f186a78
/*  f186a6c:	00000000 */ 	nop
/*  f186a70:	1219000f */ 	beq	$s0,$t9,.L0f186ab0
/*  f186a74:	00000000 */ 	nop
.L0f186a78:
/*  f186a78:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186a7c:	02002025 */ 	or	$a0,$s0,$zero
/*  f186a80:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f186a84:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186a88:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f186a8c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186a90:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x6c)
/*  f186a94:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x68)
/*  f186a98:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x64)
/*  f186a9c:	3c06800a */ 	lui	$a2,%hi(g_Vars+0x70)
/*  f186aa0:	8cc6a030 */ 	lw	$a2,%lo(g_Vars+0x70)($a2)
/*  f186aa4:	8ce7a024 */ 	lw	$a3,%lo(g_Vars+0x64)($a3)
/*  f186aa8:	8d08a028 */ 	lw	$t0,%lo(g_Vars+0x68)($t0)
/*  f186aac:	8d29a02c */ 	lw	$t1,%lo(g_Vars+0x6c)($t1)
.L0f186ab0:
/*  f186ab0:	11200003 */ 	beqz	$t1,.L0f186ac0
/*  f186ab4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f186ab8:	10000002 */ 	b	.L0f186ac4
/*  f186abc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186ac0:
/*  f186ac0:	00002025 */ 	or	$a0,$zero,$zero
.L0f186ac4:
/*  f186ac4:	11000003 */ 	beqz	$t0,.L0f186ad4
/*  f186ac8:	00001825 */ 	or	$v1,$zero,$zero
/*  f186acc:	10000001 */ 	b	.L0f186ad4
/*  f186ad0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186ad4:
/*  f186ad4:	10e00003 */ 	beqz	$a3,.L0f186ae4
/*  f186ad8:	00002825 */ 	or	$a1,$zero,$zero
/*  f186adc:	10000001 */ 	b	.L0f186ae4
/*  f186ae0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f186ae4:
/*  f186ae4:	10c00003 */ 	beqz	$a2,.L0f186af4
/*  f186ae8:	00001025 */ 	or	$v0,$zero,$zero
/*  f186aec:	10000001 */ 	b	.L0f186af4
/*  f186af0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186af4:
/*  f186af4:	00457821 */ 	addu	$t7,$v0,$a1
/*  f186af8:	01e35021 */ 	addu	$t2,$t7,$v1
/*  f186afc:	01445821 */ 	addu	$t3,$t2,$a0
/*  f186b00:	020b082a */ 	slt	$at,$s0,$t3
/*  f186b04:	5420ffd6 */ 	bnezl	$at,.L0f186a60
/*  f186b08:	8fae0128 */ 	lw	$t6,0x128($sp)
.L0f186b0c:
/*  f186b0c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186b10:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f186b14:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f186b18:	8fa30124 */ 	lw	$v1,0x124($sp)
/*  f186b1c:	8fa40124 */ 	lw	$a0,0x124($sp)
/*  f186b20:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
/*  f186b24:	51a00007 */ 	beqzl	$t5,.L0f186b44
/*  f186b28:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f186b2c:	8c6e0040 */ 	lw	$t6,0x40($v1)
/*  f186b30:	00001025 */ 	or	$v0,$zero,$zero
/*  f186b34:	35d80004 */ 	ori	$t8,$t6,0x4
/*  f186b38:	100001ce */ 	b	.L0f187274
/*  f186b3c:	ac780040 */ 	sw	$t8,0x40($v1)
/*  f186b40:	90860002 */ 	lbu	$a2,0x2($a0)
.L0f186b44:
/*  f186b44:	00002825 */ 	or	$a1,$zero,$zero
/*  f186b48:	30cf0004 */ 	andi	$t7,$a2,0x4
/*  f186b4c:	0fc1ab4b */ 	jal	func0f06ad2c
/*  f186b50:	01e03025 */ 	or	$a2,$t7,$zero
/*  f186b54:	100001c7 */ 	b	.L0f187274
/*  f186b58:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186b5c:
/*  f186b5c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f186b60:	146101be */ 	bne	$v1,$at,.L0f18725c
/*  f186b64:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f186b68:	8faa0128 */ 	lw	$t2,0x128($sp)
/*  f186b6c:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f186b70:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f186b74:	8d4302d4 */ 	lw	$v1,0x2d4($t2)
/*  f186b78:	5060000e */ 	beqzl	$v1,.L0f186bb4
/*  f186b7c:	8e2e028c */ 	lw	$t6,0x28c($s1)
/*  f186b80:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f186b84:	01402025 */ 	or	$a0,$t2,$zero
/*  f186b88:	00025880 */ 	sll	$t3,$v0,0x2
/*  f186b8c:	3c0c800b */ 	lui	$t4,%hi(var800ac500)
/*  f186b90:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f186b94:	8d8cc500 */ 	lw	$t4,%lo(var800ac500)($t4)
/*  f186b98:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f186b9c:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f186ba0:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f186ba4:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f186ba8:	10000019 */ 	b	.L0f186c10
/*  f186bac:	8da302d4 */ 	lw	$v1,0x2d4($t5)
/*  f186bb0:	8e2e028c */ 	lw	$t6,0x28c($s1)
.L0f186bb4:
/*  f186bb4:	3c0a800b */ 	lui	$t2,%hi(g_MpPlayers)
/*  f186bb8:	254ac7b8 */ 	addiu	$t2,$t2,%lo(g_MpPlayers)
/*  f186bbc:	000ec1c0 */ 	sll	$t8,$t6,0x7
/*  f186bc0:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f186bc4:	8f2200e4 */ 	lw	$v0,0xe4($t9)
/*  f186bc8:	3c0e800b */ 	lui	$t6,%hi(g_MpSimulants)
/*  f186bcc:	25cec538 */ 	addiu	$t6,$t6,%lo(g_MpSimulants)
/*  f186bd0:	28410004 */ 	slti	$at,$v0,0x4
/*  f186bd4:	10200007 */ 	beqz	$at,.L0f186bf4
/*  f186bd8:	00026080 */ 	sll	$t4,$v0,0x2
/*  f186bdc:	00027880 */ 	sll	$t7,$v0,0x2
/*  f186be0:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f186be4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f186be8:	01ea5821 */ 	addu	$t3,$t7,$t2
/*  f186bec:	10000008 */ 	b	.L0f186c10
/*  f186bf0:	afab0050 */ 	sw	$t3,0x50($sp)
.L0f186bf4:
/*  f186bf4:	01826021 */ 	addu	$t4,$t4,$v0
/*  f186bf8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f186bfc:	01826023 */ 	subu	$t4,$t4,$v0
/*  f186c00:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f186c04:	258dfed0 */ 	addiu	$t5,$t4,-304
/*  f186c08:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f186c0c:	afb80050 */ 	sw	$t8,0x50($sp)
.L0f186c10:
/*  f186c10:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f186c14:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f186c18:	932f0011 */ 	lbu	$t7,0x11($t9)
/*  f186c1c:	854b0062 */ 	lh	$t3,0x62($t2)
/*  f186c20:	15eb00c8 */ 	bne	$t7,$t3,.L0f186f44
/*  f186c24:	00000000 */ 	nop
/*  f186c28:	10600005 */ 	beqz	$v1,.L0f186c40
/*  f186c2c:	00000000 */ 	nop
/*  f186c30:	8c6c009c */ 	lw	$t4,0x9c($v1)
/*  f186c34:	000c7040 */ 	sll	$t6,$t4,0x1
/*  f186c38:	05c20008 */ 	bltzl	$t6,.L0f186c5c
/*  f186c3c:	8fb80050 */ 	lw	$t8,0x50($sp)
.L0f186c40:
/*  f186c40:	546000b9 */ 	bnezl	$v1,.L0f186f28
/*  f186c44:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f186c48:	0fc44a11 */ 	jal	invHasBriefcase
/*  f186c4c:	00000000 */ 	nop
/*  f186c50:	504000b5 */ 	beqzl	$v0,.L0f186f28
/*  f186c54:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f186c58:	8fb80050 */ 	lw	$t8,0x50($sp)
.L0f186c5c:
/*  f186c5c:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f186c60:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f186c64:	8719003e */ 	lh	$t9,0x3e($t8)
/*  f186c68:	00008025 */ 	or	$s0,$zero,$zero
/*  f186c6c:	272a0001 */ 	addiu	$t2,$t9,0x1
/*  f186c70:	a70a003e */ 	sh	$t2,0x3e($t8)
/*  f186c74:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f186c78:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f186c7c:	8de3001c */ 	lw	$v1,0x1c($t7)
.L0f186c80:
/*  f186c80:	8c4b0058 */ 	lw	$t3,0x58($v0)
/*  f186c84:	506b0006 */ 	beql	$v1,$t3,.L0f186ca0
/*  f186c88:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
/*  f186c8c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f186c90:	2a010004 */ 	slti	$at,$s0,0x4
/*  f186c94:	1420fffa */ 	bnez	$at,.L0f186c80
/*  f186c98:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f186c9c:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
.L0f186ca0:
/*  f186ca0:	11a00009 */ 	beqz	$t5,.L0f186cc8
/*  f186ca4:	01802025 */ 	or	$a0,$t4,$zero
/*  f186ca8:	0fc66661 */ 	jal	func0f199984
/*  f186cac:	24050057 */ 	addiu	$a1,$zero,0x57
/*  f186cb0:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f186cb4:	8dc302d4 */ 	lw	$v1,0x2d4($t6)
/*  f186cb8:	9079009c */ 	lbu	$t9,0x9c($v1)
/*  f186cbc:	332affbf */ 	andi	$t2,$t9,0xffbf
/*  f186cc0:	10000014 */ 	b	.L0f186d14
/*  f186cc4:	a06a009c */ 	sb	$t2,0x9c($v1)
.L0f186cc8:
/*  f186cc8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f186ccc:	44812000 */ 	mtc1	$at,$f4
/*  f186cd0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f186cd4:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f186cd8:	240fffff */ 	addiu	$t7,$zero,-1
/*  f186cdc:	240bffff */ 	addiu	$t3,$zero,-1
/*  f186ce0:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f186ce4:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f186ce8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f186cec:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f186cf0:	240505b8 */ 	addiu	$a1,$zero,0x5b8
/*  f186cf4:	00003025 */ 	or	$a2,$zero,$zero
/*  f186cf8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f186cfc:	0c004241 */ 	jal	audioStart
/*  f186d00:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f186d04:	0fc24494 */ 	jal	func0f091250
/*  f186d08:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d0c:	0fc447a9 */ 	jal	invRemoveItemByNum
/*  f186d10:	24040057 */ 	addiu	$a0,$zero,0x57
.L0f186d14:
/*  f186d14:	0fc5b9f1 */ 	jal	langGet
/*  f186d18:	24045404 */ 	addiu	$a0,$zero,0x5404
/*  f186d1c:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d20:	0fc28874 */ 	jal	weaponGetShortName
/*  f186d24:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186d28:	00106880 */ 	sll	$t5,$s0,0x2
/*  f186d2c:	01b06823 */ 	subu	$t5,$t5,$s0
/*  f186d30:	3c0c800b */ 	lui	$t4,%hi(g_MpSetup+0x28)
/*  f186d34:	258ccbb0 */ 	addiu	$t4,$t4,%lo(g_MpSetup+0x28)
/*  f186d38:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f186d3c:	01ac3021 */ 	addu	$a2,$t5,$t4
/*  f186d40:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f186d44:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186d48:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f186d4c:	0c004dad */ 	jal	sprintf
/*  f186d50:	00403825 */ 	or	$a3,$v0,$zero
/*  f186d54:	0fc5b9f1 */ 	jal	langGet
/*  f186d58:	24045405 */ 	addiu	$a0,$zero,0x5405
/*  f186d5c:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d60:	0fc28874 */ 	jal	weaponGetShortName
/*  f186d64:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186d68:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186d6c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f186d70:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f186d74:	0c004dad */ 	jal	sprintf
/*  f186d78:	00403825 */ 	or	$a3,$v0,$zero
/*  f186d7c:	0fc5b9f1 */ 	jal	langGet
/*  f186d80:	24045406 */ 	addiu	$a0,$zero,0x5406
/*  f186d84:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d88:	0fc28874 */ 	jal	weaponGetShortName
/*  f186d8c:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186d90:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186d94:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f186d98:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f186d9c:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f186da0:	0c004dad */ 	jal	sprintf
/*  f186da4:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f186da8:	8e39006c */ 	lw	$t9,0x6c($s1)
/*  f186dac:	8e2e028c */ 	lw	$t6,0x28c($s1)
/*  f186db0:	afb00114 */ 	sw	$s0,0x114($sp)
/*  f186db4:	00008025 */ 	or	$s0,$zero,$zero
/*  f186db8:	13200003 */ 	beqz	$t9,.L0f186dc8
/*  f186dbc:	afae0118 */ 	sw	$t6,0x118($sp)
/*  f186dc0:	10000002 */ 	b	.L0f186dcc
/*  f186dc4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186dc8:
/*  f186dc8:	00002025 */ 	or	$a0,$zero,$zero
.L0f186dcc:
/*  f186dcc:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f186dd0:	00001825 */ 	or	$v1,$zero,$zero
/*  f186dd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f186dd8:	11400003 */ 	beqz	$t2,.L0f186de8
/*  f186ddc:	00001025 */ 	or	$v0,$zero,$zero
/*  f186de0:	10000001 */ 	b	.L0f186de8
/*  f186de4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186de8:
/*  f186de8:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f186dec:	13000003 */ 	beqz	$t8,.L0f186dfc
/*  f186df0:	00000000 */ 	nop
/*  f186df4:	10000001 */ 	b	.L0f186dfc
/*  f186df8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f186dfc:
/*  f186dfc:	8e2f0070 */ 	lw	$t7,0x70($s1)
/*  f186e00:	11e00003 */ 	beqz	$t7,.L0f186e10
/*  f186e04:	00000000 */ 	nop
/*  f186e08:	10000001 */ 	b	.L0f186e10
/*  f186e0c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186e10:
/*  f186e10:	00455821 */ 	addu	$t3,$v0,$a1
/*  f186e14:	01636821 */ 	addu	$t5,$t3,$v1
/*  f186e18:	01a46021 */ 	addu	$t4,$t5,$a0
/*  f186e1c:	1980003f */ 	blez	$t4,.L0f186f1c
/*  f186e20:	00000000 */ 	nop
.L0f186e24:
/*  f186e24:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186e28:	02002025 */ 	or	$a0,$s0,$zero
/*  f186e2c:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f186e30:	00107880 */ 	sll	$t7,$s0,0x2
/*  f186e34:	3c0b800b */ 	lui	$t3,%hi(var800ac500)
/*  f186e38:	8dd902d4 */ 	lw	$t9,0x2d4($t6)
/*  f186e3c:	8faa0118 */ 	lw	$t2,0x118($sp)
/*  f186e40:	016f5821 */ 	addu	$t3,$t3,$t7
/*  f186e44:	17200008 */ 	bnez	$t9,.L0f186e68
/*  f186e48:	00000000 */ 	nop
/*  f186e4c:	160a0006 */ 	bne	$s0,$t2,.L0f186e68
/*  f186e50:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f186e54:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186e58:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f186e5c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186e60:	10000011 */ 	b	.L0f186ea8
/*  f186e64:	8e2c006c */ 	lw	$t4,0x6c($s1)
.L0f186e68:
/*  f186e68:	8d6bc500 */ 	lw	$t3,%lo(var800ac500)($t3)
/*  f186e6c:	8fb80114 */ 	lw	$t8,0x114($sp)
/*  f186e70:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186e74:	916d0011 */ 	lbu	$t5,0x11($t3)
/*  f186e78:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f186e7c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186e80:	170d0006 */ 	bne	$t8,$t5,.L0f186e9c
/*  f186e84:	00000000 */ 	nop
/*  f186e88:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f186e8c:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f186e90:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186e94:	10000004 */ 	b	.L0f186ea8
/*  f186e98:	8e2c006c */ 	lw	$t4,0x6c($s1)
.L0f186e9c:
/*  f186e9c:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f186ea0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186ea4:	8e2c006c */ 	lw	$t4,0x6c($s1)
.L0f186ea8:
/*  f186ea8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f186eac:	00002025 */ 	or	$a0,$zero,$zero
/*  f186eb0:	11800003 */ 	beqz	$t4,.L0f186ec0
/*  f186eb4:	00001825 */ 	or	$v1,$zero,$zero
/*  f186eb8:	10000001 */ 	b	.L0f186ec0
/*  f186ebc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186ec0:
/*  f186ec0:	8e2e0068 */ 	lw	$t6,0x68($s1)
/*  f186ec4:	00002825 */ 	or	$a1,$zero,$zero
/*  f186ec8:	00001025 */ 	or	$v0,$zero,$zero
/*  f186ecc:	11c00003 */ 	beqz	$t6,.L0f186edc
/*  f186ed0:	00000000 */ 	nop
/*  f186ed4:	10000001 */ 	b	.L0f186edc
/*  f186ed8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186edc:
/*  f186edc:	8e390064 */ 	lw	$t9,0x64($s1)
/*  f186ee0:	13200003 */ 	beqz	$t9,.L0f186ef0
/*  f186ee4:	00000000 */ 	nop
/*  f186ee8:	10000001 */ 	b	.L0f186ef0
/*  f186eec:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f186ef0:
/*  f186ef0:	8e2a0070 */ 	lw	$t2,0x70($s1)
/*  f186ef4:	11400003 */ 	beqz	$t2,.L0f186f04
/*  f186ef8:	00000000 */ 	nop
/*  f186efc:	10000001 */ 	b	.L0f186f04
/*  f186f00:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186f04:
/*  f186f04:	00457821 */ 	addu	$t7,$v0,$a1
/*  f186f08:	01e35821 */ 	addu	$t3,$t7,$v1
/*  f186f0c:	0164c021 */ 	addu	$t8,$t3,$a0
/*  f186f10:	0218082a */ 	slt	$at,$s0,$t8
/*  f186f14:	1420ffc3 */ 	bnez	$at,.L0f186e24
/*  f186f18:	00000000 */ 	nop
.L0f186f1c:
/*  f186f1c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186f20:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f186f24:	8fad0128 */ 	lw	$t5,0x128($sp)
.L0f186f28:
/*  f186f28:	8dac02d4 */ 	lw	$t4,0x2d4($t5)
/*  f186f2c:	11800003 */ 	beqz	$t4,.L0f186f3c
/*  f186f30:	00000000 */ 	nop
/*  f186f34:	100000cf */ 	b	.L0f187274
/*  f186f38:	00001025 */ 	or	$v0,$zero,$zero
.L0f186f3c:
/*  f186f3c:	100000cd */ 	b	.L0f187274
/*  f186f40:	00001025 */ 	or	$v0,$zero,$zero
.L0f186f44:
/*  f186f44:	10600005 */ 	beqz	$v1,.L0f186f5c
/*  f186f48:	00000000 */ 	nop
/*  f186f4c:	8c6e009c */ 	lw	$t6,0x9c($v1)
/*  f186f50:	000e5040 */ 	sll	$t2,$t6,0x1
/*  f186f54:	05410008 */ 	bgez	$t2,.L0f186f78
/*  f186f58:	00000000 */ 	nop
.L0f186f5c:
/*  f186f5c:	546000b8 */ 	bnezl	$v1,.L0f187240
/*  f186f60:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f186f64:	0fc44a11 */ 	jal	invHasBriefcase
/*  f186f68:	00000000 */ 	nop
/*  f186f6c:	144000b3 */ 	bnez	$v0,.L0f18723c
/*  f186f70:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f186f74:	8de302d4 */ 	lw	$v1,0x2d4($t7)
.L0f186f78:
/*  f186f78:	50600009 */ 	beqzl	$v1,.L0f186fa0
/*  f186f7c:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f186f80:	9078009c */ 	lbu	$t8,0x9c($v1)
/*  f186f84:	370d0040 */ 	ori	$t5,$t8,0x40
/*  f186f88:	a06d009c */ 	sb	$t5,0x9c($v1)
/*  f186f8c:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f186f90:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f186f94:	0fc21f03 */ 	jal	propPlayPickupSound
/*  f186f98:	9185005c */ 	lbu	$a1,0x5c($t4)
/*  f186f9c:	8faa0120 */ 	lw	$t2,0x120($sp)
.L0f186fa0:
/*  f186fa0:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f186fa4:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x58)
/*  f186fa8:	854f0062 */ 	lh	$t7,0x62($t2)
/*  f186fac:	8dd9001c */ 	lw	$t9,0x1c($t6)
/*  f186fb0:	24045401 */ 	addiu	$a0,$zero,0x5401
/*  f186fb4:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f186fb8:	002b0821 */ 	addu	$at,$at,$t3
/*  f186fbc:	0fc5b9f1 */ 	jal	langGet
/*  f186fc0:	ac39c168 */ 	sw	$t9,%lo(g_ScenarioData+0x58)($at)
/*  f186fc4:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186fc8:	0fc28874 */ 	jal	weaponGetShortName
/*  f186fcc:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186fd0:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f186fd4:	3c10800b */ 	lui	$s0,%hi(g_MpSetup+0x28)
/*  f186fd8:	2610cbb0 */ 	addiu	$s0,$s0,%lo(g_MpSetup+0x28)
/*  f186fdc:	870d0062 */ 	lh	$t5,0x62($t8)
/*  f186fe0:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f186fe4:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186fe8:	000d6080 */ 	sll	$t4,$t5,0x2
/*  f186fec:	018d6023 */ 	subu	$t4,$t4,$t5
/*  f186ff0:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f186ff4:	020c3821 */ 	addu	$a3,$s0,$t4
/*  f186ff8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f186ffc:	0c004dad */ 	jal	sprintf
/*  f187000:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187004:	0fc5b9f1 */ 	jal	langGet
/*  f187008:	24045402 */ 	addiu	$a0,$zero,0x5402
/*  f18700c:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f187010:	0fc28874 */ 	jal	weaponGetShortName
/*  f187014:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f187018:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f18701c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187020:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187024:	0c004dad */ 	jal	sprintf
/*  f187028:	00403825 */ 	or	$a3,$v0,$zero
/*  f18702c:	0fc5b9f1 */ 	jal	langGet
/*  f187030:	24045403 */ 	addiu	$a0,$zero,0x5403
/*  f187034:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f187038:	0fc28874 */ 	jal	weaponGetShortName
/*  f18703c:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f187040:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f187044:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f187048:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f18704c:	85ca0062 */ 	lh	$t2,0x62($t6)
/*  f187050:	00403825 */ 	or	$a3,$v0,$zero
/*  f187054:	000a7880 */ 	sll	$t7,$t2,0x2
/*  f187058:	01ea7823 */ 	subu	$t7,$t7,$t2
/*  f18705c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f187060:	0c004dad */ 	jal	sprintf
/*  f187064:	020f3021 */ 	addu	$a2,$s0,$t7
/*  f187068:	8e2b006c */ 	lw	$t3,0x6c($s1)
/*  f18706c:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f187070:	00008025 */ 	or	$s0,$zero,$zero
/*  f187074:	11600003 */ 	beqz	$t3,.L0f187084
/*  f187078:	afb90118 */ 	sw	$t9,0x118($sp)
/*  f18707c:	10000002 */ 	b	.L0f187088
/*  f187080:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f187084:
/*  f187084:	00002025 */ 	or	$a0,$zero,$zero
.L0f187088:
/*  f187088:	8e380068 */ 	lw	$t8,0x68($s1)
/*  f18708c:	00001825 */ 	or	$v1,$zero,$zero
/*  f187090:	00002825 */ 	or	$a1,$zero,$zero
/*  f187094:	13000003 */ 	beqz	$t8,.L0f1870a4
/*  f187098:	00001025 */ 	or	$v0,$zero,$zero
/*  f18709c:	10000001 */ 	b	.L0f1870a4
/*  f1870a0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1870a4:
/*  f1870a4:	8e2d0064 */ 	lw	$t5,0x64($s1)
/*  f1870a8:	11a00003 */ 	beqz	$t5,.L0f1870b8
/*  f1870ac:	00000000 */ 	nop
/*  f1870b0:	10000001 */ 	b	.L0f1870b8
/*  f1870b4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1870b8:
/*  f1870b8:	8e2c0070 */ 	lw	$t4,0x70($s1)
/*  f1870bc:	11800003 */ 	beqz	$t4,.L0f1870cc
/*  f1870c0:	00000000 */ 	nop
/*  f1870c4:	10000001 */ 	b	.L0f1870cc
/*  f1870c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1870cc:
/*  f1870cc:	00457021 */ 	addu	$t6,$v0,$a1
/*  f1870d0:	01c35021 */ 	addu	$t2,$t6,$v1
/*  f1870d4:	01447821 */ 	addu	$t7,$t2,$a0
/*  f1870d8:	19e0003f */ 	blez	$t7,.L0f1871d8
/*  f1870dc:	00000000 */ 	nop
.L0f1870e0:
/*  f1870e0:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1870e4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1870e8:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f1870ec:	00107080 */ 	sll	$t6,$s0,0x2
/*  f1870f0:	3c0a800b */ 	lui	$t2,%hi(var800ac500)
/*  f1870f4:	8f2b02d4 */ 	lw	$t3,0x2d4($t9)
/*  f1870f8:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f1870fc:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f187100:	15600008 */ 	bnez	$t3,.L0f187124
/*  f187104:	8fad0120 */ 	lw	$t5,0x120($sp)
/*  f187108:	16180006 */ 	bne	$s0,$t8,.L0f187124
/*  f18710c:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f187110:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f187114:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f187118:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18711c:	10000011 */ 	b	.L0f187164
/*  f187120:	8e39006c */ 	lw	$t9,0x6c($s1)
.L0f187124:
/*  f187124:	8d4ac500 */ 	lw	$t2,%lo(var800ac500)($t2)
/*  f187128:	85ac0062 */ 	lh	$t4,0x62($t5)
/*  f18712c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f187130:	914f0011 */ 	lbu	$t7,0x11($t2)
/*  f187134:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f187138:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f18713c:	158f0006 */ 	bne	$t4,$t7,.L0f187158
/*  f187140:	00000000 */ 	nop
/*  f187144:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187148:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f18714c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f187150:	10000004 */ 	b	.L0f187164
/*  f187154:	8e39006c */ 	lw	$t9,0x6c($s1)
.L0f187158:
/*  f187158:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f18715c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f187160:	8e39006c */ 	lw	$t9,0x6c($s1)
.L0f187164:
/*  f187164:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f187168:	00002025 */ 	or	$a0,$zero,$zero
/*  f18716c:	13200003 */ 	beqz	$t9,.L0f18717c
/*  f187170:	00001825 */ 	or	$v1,$zero,$zero
/*  f187174:	10000001 */ 	b	.L0f18717c
/*  f187178:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f18717c:
/*  f18717c:	8e2b0068 */ 	lw	$t3,0x68($s1)
/*  f187180:	00002825 */ 	or	$a1,$zero,$zero
/*  f187184:	00001025 */ 	or	$v0,$zero,$zero
/*  f187188:	11600003 */ 	beqz	$t3,.L0f187198
/*  f18718c:	00000000 */ 	nop
/*  f187190:	10000001 */ 	b	.L0f187198
/*  f187194:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f187198:
/*  f187198:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f18719c:	13000003 */ 	beqz	$t8,.L0f1871ac
/*  f1871a0:	00000000 */ 	nop
/*  f1871a4:	10000001 */ 	b	.L0f1871ac
/*  f1871a8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1871ac:
/*  f1871ac:	8e2d0070 */ 	lw	$t5,0x70($s1)
/*  f1871b0:	11a00003 */ 	beqz	$t5,.L0f1871c0
/*  f1871b4:	00000000 */ 	nop
/*  f1871b8:	10000001 */ 	b	.L0f1871c0
/*  f1871bc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1871c0:
/*  f1871c0:	00457021 */ 	addu	$t6,$v0,$a1
/*  f1871c4:	01c35021 */ 	addu	$t2,$t6,$v1
/*  f1871c8:	01446021 */ 	addu	$t4,$t2,$a0
/*  f1871cc:	020c082a */ 	slt	$at,$s0,$t4
/*  f1871d0:	1420ffc3 */ 	bnez	$at,.L0f1870e0
/*  f1871d4:	00000000 */ 	nop
.L0f1871d8:
/*  f1871d8:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1871dc:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f1871e0:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f1871e4:	8df902d4 */ 	lw	$t9,0x2d4($t7)
/*  f1871e8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1871ec:	13200009 */ 	beqz	$t9,.L0f187214
/*  f1871f0:	00000000 */ 	nop
/*  f1871f4:	0fc65fa3 */ 	jal	func0f197e8c
/*  f1871f8:	24050057 */ 	addiu	$a1,$zero,0x57
/*  f1871fc:	8fab0124 */ 	lw	$t3,0x124($sp)
/*  f187200:	00001025 */ 	or	$v0,$zero,$zero
/*  f187204:	8d780040 */ 	lw	$t8,0x40($t3)
/*  f187208:	370d0004 */ 	ori	$t5,$t8,0x4
/*  f18720c:	10000019 */ 	b	.L0f187274
/*  f187210:	ad6d0040 */ 	sw	$t5,0x40($t3)
.L0f187214:
/*  f187214:	0fc4483c */ 	jal	invGiveWeaponsByProp
/*  f187218:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f18721c:	8fa40124 */ 	lw	$a0,0x124($sp)
/*  f187220:	00002825 */ 	or	$a1,$zero,$zero
/*  f187224:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f187228:	30ca0004 */ 	andi	$t2,$a2,0x4
/*  f18722c:	0fc1ab4b */ 	jal	func0f06ad2c
/*  f187230:	01403025 */ 	or	$a2,$t2,$zero
/*  f187234:	1000000f */ 	b	.L0f187274
/*  f187238:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18723c:
/*  f18723c:	8fac0128 */ 	lw	$t4,0x128($sp)
.L0f187240:
/*  f187240:	8d9902d4 */ 	lw	$t9,0x2d4($t4)
/*  f187244:	13200003 */ 	beqz	$t9,.L0f187254
/*  f187248:	00000000 */ 	nop
/*  f18724c:	10000009 */ 	b	.L0f187274
/*  f187250:	00001025 */ 	or	$v0,$zero,$zero
.L0f187254:
/*  f187254:	10000007 */ 	b	.L0f187274
/*  f187258:	00001025 */ 	or	$v0,$zero,$zero
.L0f18725c:
/*  f18725c:	8df802d4 */ 	lw	$t8,0x2d4($t7)
/*  f187260:	00001025 */ 	or	$v0,$zero,$zero
/*  f187264:	13000003 */ 	beqz	$t8,.L0f187274
/*  f187268:	00000000 */ 	nop
/*  f18726c:	10000001 */ 	b	.L0f187274
/*  f187270:	00001025 */ 	or	$v0,$zero,$zero
.L0f187274:
/*  f187274:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f187278:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f18727c:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f187280:	03e00008 */ 	jr	$ra
/*  f187284:	27bd0128 */ 	addiu	$sp,$sp,0x128
);

GLOBAL_ASM(
glabel func0f187288
/*  f187288:	27bdfef0 */ 	addiu	$sp,$sp,-272
/*  f18728c:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup+0x10)
/*  f187290:	91cecb98 */ 	lbu	$t6,%lo(g_MpSetup+0x10)($t6)
/*  f187294:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f187298:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f18729c:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f1872a0:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f1872a4:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f1872a8:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f1872ac:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f1872b0:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f1872b4:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f1872b8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1872bc:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f1872c0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f1872c4:	00a0b825 */ 	or	$s7,$a1,$zero
/*  f1872c8:	0080f025 */ 	or	$s8,$a0,$zero
/*  f1872cc:	15c10043 */ 	bne	$t6,$at,.L0f1873dc
/*  f1872d0:	8cb60004 */ 	lw	$s6,0x4($a1)
/*  f1872d4:	3c11800b */ 	lui	$s1,%hi(g_ScenarioData)
/*  f1872d8:	4480a000 */ 	mtc1	$zero,$f20
/*  f1872dc:	2631c110 */ 	addiu	$s1,$s1,%lo(g_ScenarioData)
/*  f1872e0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1872e4:	27b50070 */ 	addiu	$s5,$sp,0x70
/*  f1872e8:	27b400b0 */ 	addiu	$s4,$sp,0xb0
.L0f1872ec:
/*  f1872ec:	8fcf001c */ 	lw	$t7,0x1c($s8)
/*  f1872f0:	8e380058 */ 	lw	$t8,0x58($s1)
/*  f1872f4:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1872f8:	0010c840 */ 	sll	$t9,$s0,0x1
/*  f1872fc:	15f80033 */ 	bne	$t7,$t8,.L0f1873cc
/*  f187300:	3c08800b */ 	lui	$t0,%hi(g_ScenarioData)
/*  f187304:	2508c110 */ 	addiu	$t0,$t0,%lo(g_ScenarioData)
/*  f187308:	0fc1ab10 */ 	jal	objEndFlight
/*  f18730c:	03289821 */ 	addu	$s3,$t9,$t0
/*  f187310:	ae370058 */ 	sw	$s7,0x58($s1)
/*  f187314:	a6d00062 */ 	sh	$s0,0x62($s6)
/*  f187318:	86690008 */ 	lh	$t1,0x8($s3)
/*  f18731c:	3c04800b */ 	lui	$a0,%hi(g_ScenarioData+0x18)
/*  f187320:	8ef20004 */ 	lw	$s2,0x4($s7)
/*  f187324:	00095100 */ 	sll	$t2,$t1,0x4
/*  f187328:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f18732c:	8484c128 */ 	lh	$a0,%lo(g_ScenarioData+0x18)($a0)
/*  f187330:	2405004e */ 	addiu	$a1,$zero,0x4e
/*  f187334:	0fc456ac */ 	jal	padUnpack
/*  f187338:	02803025 */ 	or	$a2,$s4,$zero
/*  f18733c:	c7a400bc */ 	lwc1	$f4,0xbc($sp)
/*  f187340:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f187344:	c7b000c4 */ 	lwc1	$f16,0xc4($sp)
/*  f187348:	46002187 */ 	neg.s	$f6,$f4
/*  f18734c:	46004287 */ 	neg.s	$f10,$f8
/*  f187350:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f187354:	c7a600cc */ 	lwc1	$f6,0xcc($sp)
/*  f187358:	c7a800d0 */ 	lwc1	$f8,0xd0($sp)
/*  f18735c:	c7a400c8 */ 	lwc1	$f4,0xc8($sp)
/*  f187360:	46008487 */ 	neg.s	$f18,$f16
/*  f187364:	4405a000 */ 	mfc1	$a1,$f20
/*  f187368:	4406a000 */ 	mfc1	$a2,$f20
/*  f18736c:	4407a000 */ 	mfc1	$a3,$f20
/*  f187370:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f187374:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f187378:	02a02025 */ 	or	$a0,$s5,$zero
/*  f18737c:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f187380:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f187384:	0c005b56 */ 	jal	func00016d58
/*  f187388:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f18738c:	8e420018 */ 	lw	$v0,0x18($s2)
/*  f187390:	02a02825 */ 	or	$a1,$s5,$zero
/*  f187394:	50400004 */ 	beqzl	$v0,.L0f1873a8
/*  f187398:	8fab00f8 */ 	lw	$t3,0xf8($sp)
/*  f18739c:	0c0057c1 */ 	jal	func00015f04
/*  f1873a0:	c44c0014 */ 	lwc1	$f12,0x14($v0)
/*  f1873a4:	8fab00f8 */ 	lw	$t3,0xf8($sp)
.L0f1873a8:
/*  f1873a8:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1873ac:	a7ac006e */ 	sh	$t4,0x6e($sp)
/*  f1873b0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1873b4:	02802825 */ 	or	$a1,$s4,$zero
/*  f1873b8:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1873bc:	27a7006c */ 	addiu	$a3,$sp,0x6c
/*  f1873c0:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f1873c4:	0fc1a9cc */ 	jal	func0f06a730
/*  f1873c8:	a7ab006c */ 	sh	$t3,0x6c($sp)
.L0f1873cc:
/*  f1873cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1873d0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1873d4:	1601ffc5 */ 	bne	$s0,$at,.L0f1872ec
/*  f1873d8:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f1873dc:
/*  f1873dc:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f1873e0:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f1873e4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1873e8:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1873ec:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1873f0:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1873f4:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f1873f8:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f1873fc:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f187400:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f187404:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f187408:	03e00008 */ 	jr	$ra
/*  f18740c:	27bd0110 */ 	addiu	$sp,$sp,0x110
);

bool chrGiveUplink(struct chrdata *chr, struct prop *prop)
{
	s32 i;
	struct mpchr *mpchr;
	char message[60];
	s32 mpindex;
	u32 playernum;
	struct defaultobj *obj;

	if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
		obj = prop->obj;
		g_ScenarioData.htm.uplink = chr->prop;

		if (chr->aibot) {
			mpchr = var800ac500[mpPlayerGetIndex(chr)];
		} else {
			mpindex = g_Vars.playerstats[g_Vars.currentplayernum].mpindex;

			if (mpindex < 4) {
				mpchr = &g_MpPlayers[mpindex].base;
			} else {
				mpchr = &g_MpSimulants[mpindex - 4].base;
			}
		}

		// "%shas the\n%s"
		sprintf(message, langGet(L_MPWEAPONS(0)), mpchr->name, weaponGetShortName(WEAPON_DATAUPLINK));
		playernum = g_Vars.currentplayernum;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (chr->aibot || i != playernum) {
				setCurrentPlayerNum(i);
				func0f0ddfa4(message, 9, 1);
			}
		}

		setCurrentPlayerNum(playernum);

		if (chr->aibot) {
			propPlayPickupSound(prop, WEAPON_DATAUPLINK);
			func0f197e8c(chr, WEAPON_DATAUPLINK);
			chr->aibot->unk04c_05 = true;
			obj->hidden |= 4;
			return false;
		} else {
			invGiveSingleWeapon(WEAPON_DATAUPLINK);
			currentPlayerQueuePickupWeaponHudmsg(WEAPON_DATAUPLINK, false);
			func0f087d10(WEAPON_DATAUPLINK);
			func0f06ad2c(obj, 0, obj->hidden2 & OBJH2FLAG_04);
			return true;
		}
	} else if (chr->aibot) {
		return false;
	}

	return false;
}

void scenarioHtmActivateUplink(struct chrdata *chr, struct prop *terminal)
{
	if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
		struct defaultobj *obj = terminal->obj;

		if (obj->flags3 & OBJFLAG3_00002000) {
			u32 mpindex = mpPlayerGetIndex(chr);

			if ((obj->hidden & OBJHFLAG_ACTIVATED_BY_BOND) == 0) {
				obj->hidden &= 0x0fffffff;
				obj->hidden |= (mpindex << 28) & 0xf0000000;
				obj->hidden |= OBJHFLAG_ACTIVATED_BY_BOND;
			}
		}
	}
}
