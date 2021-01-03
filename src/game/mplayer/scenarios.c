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
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1b8440[] = "CaptureTheBriefcaseAddBankPad -> Adding New Pad %d  - Pad Id = %d-> Saving Pad\n";
const char var7f1b8490[] = "%d:%02d";
const char var7f1b8498[] = "%d:%02d";
const char var7f1b84a0[] = "%02d";
const char var7f1b84a8[] = "HackThatMacAddBankPad -> Adding New Pad %d  - Pad Id = %d-> Saving Pad\n";
const char var7f1b84f0[] = "HackThatMacReset -> Working\n";
const char var7f1b8510[] = "HackThatMacInitProps -> Start : %d Bank Pads\n";
const char var7f1b8540[] = "HackThatMacInitProps -> Adding prop %d (%x)\n";
const char var7f1b8570[] = "HackThatMacInitProps -> Mid : %d Bank Pads\n";
const char var7f1b859c[] = "HackThatMacInitProps -> Generating %d random box pads from %d in the bank\n";
const char var7f1b85e8[] = "HackThatMacInitProps -> %d/%d Random box pads generated - Listing\n";
const char var7f1b862c[] = "Pad %d -> Pad Id = %d\n";
const char var7f1b8644[] = "HackThatMacInitProps -> Building and adding custom prop %d - Pad=%d, Ptr=%08x\n";
const char var7f1b8694[] = "HackThatMacInitProps -> End\n";
const char var7f1b86b4[] = "HTM : Player %d - Term Pos = (%d,%d,%d)";
const char var7f1b86dc[] = "HTM : Player %d - Play Pos = (%d,%d,%d)";
const char var7f1b8704[] = "HTM : Player %d - T/P  Rel = (%d,%d,%d)";
const char var7f1b872c[] = "HTM : Player %d - Range XZ = %d";
const char var7f1b874c[] = "HTM : Player %d - Range Y  = %d";
const char var7f1b876c[] = "HTM : Player %d - Angle XZ = %d";
const char var7f1b878c[] = "HTM : Player %d - Dwnld Plr=%d, Dwnld Prop=%d\n";
const char var7f1b87bc[] = "HTM : Player %d - Download Time = %d";
const char var7f1b87e4[] = "PopACapReset -> num_mplayers=%d : Working\n";
const char var7f1b8810[] = "PopACapReset -> Generated %d victims for this game : Listing\n";
const char var7f1b8850[] = "PopACapReset -> Victim %d is player %d\n";
const char var7f1b8878[] = "PopACapReset -> Done\n";
const char var7f1b8890[] = "PopACapTick : Current Victim = %d (Player %d)\n";
const char var7f1b88c0[] = "%d:%02d";

void func0f17fcb0(s32 silent)
{
	g_Menus[g_MpPlayerNum].playernum = g_MpPlayerNum;

	if (IS4MB()) {
		menuPushRootDialog(&g_4MbAdvancedSetupMenuDialog, MENUROOT_4MBMAINMENU);
		func0f0f8300();
	} else {
		if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE) {
			menuPushRootDialog(&menudialog_mpchallengedetails2, MENUROOT_MPSETUP);
		} else {
			menuPushRootDialog(&menudialog_mpgamesetup3, MENUROOT_MPSETUP);
		}

		func0f0f8300();
	}

	if (!silent) {
		// Explosion sound
		audioStart(var80095200, 0x809a, NULL, -1, -1, -1, -1, -1);
	}
}

s32 menuhandlerMpDisplayTeam(u32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
			return false;
		}

		return true;
	}

	return menuhandlerMpCheckboxOption(operation, item, data);
}

s32 menuhandlerMpOneHitKills(u32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED || operation == MENUOP_CHECKHIDDEN) {
		if (mpIsFeatureUnlocked(MPFEATURE_ONEHITKILLS)) {
			return false;
		}

		return true;
	}

	return menuhandlerMpCheckboxOption(operation, item, data);
}

GLOBAL_ASM(
glabel menuhandlerMpSlowMotion
.late_rodata
glabel var7f1b88dc
.word menuhandlerMpSlowMotion+0x6c # f17febc
glabel var7f1b88e0
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b88e4
.word menuhandlerMpSlowMotion+0x78 # f17fec8
glabel var7f1b88e8
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b88ec
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b88f0
.word menuhandlerMpSlowMotion+0x94 # f17fee4
glabel var7f1b88f4
.word menuhandlerMpSlowMotion+0xe4 # f17ff34
glabel var7f1b88f8
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b88fc
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b8900
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b8904
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b8908
.word menuhandlerMpSlowMotion+0x4c # f17fe9c
glabel var7f1b890c
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b8910
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b8914
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b8918
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b891c
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b8920
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b8924
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b8928
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b892c
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b8930
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b8934
.word menuhandlerMpSlowMotion+0x11c # f17ff6c
glabel var7f1b8938
.word menuhandlerMpSlowMotion+0x4c # f17fe9c
.text
/*  f17fe50:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f17fe54:	3c0e8008 */ 	lui	$t6,%hi(mpslowmotionoptions)
/*  f17fe58:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17fe5c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f17fe60:	25ce67c0 */ 	addiu	$t6,$t6,%lo(mpslowmotionoptions)
/*  f17fe64:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f17fe68:	27a20020 */ 	addiu	$v0,$sp,0x20
/*  f17fe6c:	2488ffff */ 	addiu	$t0,$a0,-1
/*  f17fe70:	ac410000 */ 	sw	$at,0x0($v0)
/*  f17fe74:	95c10004 */ 	lhu	$at,0x4($t6)
/*  f17fe78:	a4410004 */ 	sh	$at,0x4($v0)
/*  f17fe7c:	2d010018 */ 	sltiu	$at,$t0,0x18
/*  f17fe80:	1020003a */ 	beqz	$at,.L0f17ff6c
/*  f17fe84:	00084080 */ 	sll	$t0,$t0,0x2
/*  f17fe88:	3c017f1c */ 	lui	$at,%hi(var7f1b88dc)
/*  f17fe8c:	00280821 */ 	addu	$at,$at,$t0
/*  f17fe90:	8c2888dc */ 	lw	$t0,%lo(var7f1b88dc)($at)
/*  f17fe94:	01000008 */ 	jr	$t0
/*  f17fe98:	00000000 */ 	nop
/*  f17fe9c:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f17fea0:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f17fea4:	10400003 */ 	beqz	$v0,.L0f17feb4
/*  f17fea8:	00000000 */ 	nop
/*  f17feac:	10000030 */ 	b	.L0f17ff70
/*  f17feb0:	00001025 */ 	or	$v0,$zero,$zero
.L0f17feb4:
/*  f17feb4:	1000002e */ 	b	.L0f17ff70
/*  f17feb8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f17febc:	24090003 */ 	addiu	$t1,$zero,0x3
/*  f17fec0:	1000002a */ 	b	.L0f17ff6c
/*  f17fec4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f17fec8:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f17fecc:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f17fed0:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f17fed4:	0fc5b9f1 */ 	jal	langGet
/*  f17fed8:	95840000 */ 	lhu	$a0,0x0($t4)
/*  f17fedc:	10000025 */ 	b	.L0f17ff74
/*  f17fee0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17fee4:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f17fee8:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f17feec:	8c4d000c */ 	lw	$t5,0xc($v0)
/*  f17fef0:	2401ff3f */ 	addiu	$at,$zero,-193
/*  f17fef4:	01a1c024 */ 	and	$t8,$t5,$at
/*  f17fef8:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f17fefc:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f17ff00:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17ff04:	370e0040 */ 	ori	$t6,$t8,0x40
/*  f17ff08:	54610004 */ 	bnel	$v1,$at,.L0f17ff1c
/*  f17ff0c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f17ff10:	10000016 */ 	b	.L0f17ff6c
/*  f17ff14:	ac4e000c */ 	sw	$t6,0xc($v0)
/*  f17ff18:	24010002 */ 	addiu	$at,$zero,0x2
.L0f17ff1c:
/*  f17ff1c:	54610014 */ 	bnel	$v1,$at,.L0f17ff70
/*  f17ff20:	00001025 */ 	or	$v0,$zero,$zero
/*  f17ff24:	8c59000c */ 	lw	$t9,0xc($v0)
/*  f17ff28:	37280080 */ 	ori	$t0,$t9,0x80
/*  f17ff2c:	1000000f */ 	b	.L0f17ff6c
/*  f17ff30:	ac48000c */ 	sw	$t0,0xc($v0)
/*  f17ff34:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f17ff38:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f17ff3c:	8c43000c */ 	lw	$v1,0xc($v0)
/*  f17ff40:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f17ff44:	30690080 */ 	andi	$t1,$v1,0x80
/*  f17ff48:	11200003 */ 	beqz	$t1,.L0f17ff58
/*  f17ff4c:	306b0040 */ 	andi	$t3,$v1,0x40
/*  f17ff50:	10000006 */ 	b	.L0f17ff6c
/*  f17ff54:	acca0000 */ 	sw	$t2,0x0($a2)
.L0f17ff58:
/*  f17ff58:	11600003 */ 	beqz	$t3,.L0f17ff68
/*  f17ff5c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f17ff60:	10000002 */ 	b	.L0f17ff6c
/*  f17ff64:	accc0000 */ 	sw	$t4,0x0($a2)
.L0f17ff68:
/*  f17ff68:	acc00000 */ 	sw	$zero,0x0($a2)
.L0f17ff6c:
/*  f17ff6c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17ff70:
/*  f17ff70:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17ff74:
/*  f17ff74:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f17ff78:	03e00008 */ 	jr	$ra
/*  f17ff7c:	00000000 */ 	nop
);

void scenarioHtbInit(void)
{
	g_ScenarioData.htb.token = NULL;
}

void mpHtbAddPad(s16 padnum)
{
	struct scenariodata_htb *data = &g_ScenarioData.htb;

	if (data->nextindex < ARRAYCOUNT(data->padnums)) {
		data->padnums[data->nextindex] = padnum;
		data->nextindex++;
	}
}

s32 scenarioHtbCallback08(void)
{
	return 1;
}

GLOBAL_ASM(
glabel func0f17ffe4
/*  f17ffe4:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x33c)
/*  f17ffe8:	8c42a2fc */ 	lw	$v0,%lo(g_Vars+0x33c)($v0)
/*  f17ffec:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f17fff0:	00047400 */ 	sll	$t6,$a0,0x10
/*  f17fff4:	1040001e */ 	beqz	$v0,.L0f180070
/*  f17fff8:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f17fffc:	240900c1 */ 	addiu	$t1,$zero,0xc1
/*  f180000:	24080014 */ 	addiu	$t0,$zero,0x14
/*  f180004:	24070007 */ 	addiu	$a3,$zero,0x7
/*  f180008:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18000c:	90580000 */ 	lbu	$t8,0x0($v0)
.L0f180010:
/*  f180010:	54d80015 */ 	bnel	$a2,$t8,.L0f180068
/*  f180014:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f180018:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f18001c:	84790006 */ 	lh	$t9,0x6($v1)
/*  f180020:	54990011 */ 	bnel	$a0,$t9,.L0f180068
/*  f180024:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f180028:	90650003 */ 	lbu	$a1,0x3($v1)
/*  f18002c:	50e50004 */ 	beql	$a3,$a1,.L0f180040
/*  f180030:	846a0004 */ 	lh	$t2,0x4($v1)
/*  f180034:	5505000c */ 	bnel	$t0,$a1,.L0f180068
/*  f180038:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f18003c:	846a0004 */ 	lh	$t2,0x4($v1)
.L0f180040:
/*  f180040:	552a0009 */ 	bnel	$t1,$t2,.L0f180068
/*  f180044:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f180048:	8c6b0040 */ 	lw	$t3,0x40($v1)
/*  f18004c:	906d0002 */ 	lbu	$t5,0x2($v1)
/*  f180050:	356c0004 */ 	ori	$t4,$t3,0x4
/*  f180054:	31aefffb */ 	andi	$t6,$t5,0xfffb
/*  f180058:	ac6c0040 */ 	sw	$t4,0x40($v1)
/*  f18005c:	03e00008 */ 	jr	$ra
/*  f180060:	a06e0002 */ 	sb	$t6,0x2($v1)
/*  f180064:	8c420020 */ 	lw	$v0,0x20($v0)
.L0f180068:
/*  f180068:	5440ffe9 */ 	bnezl	$v0,.L0f180010
/*  f18006c:	90580000 */ 	lbu	$t8,0x0($v0)
.L0f180070:
/*  f180070:	03e00008 */ 	jr	$ra
/*  f180074:	00000000 */ 	nop
);

void func0f180078(void)
{
	s32 i;

	g_ScenarioData.htb.nextindex = 0;

	for (i = 0; i < ARRAYCOUNT(g_ScenarioData.htb.padnums); i++) {
		g_ScenarioData.htb.padnums[i] = -1;
	}
}

GLOBAL_ASM(
glabel func0f1800a8
/*  f1800a8:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f1800ac:	3c0f8008 */ 	lui	$t7,%hi(var800869f0)
/*  f1800b0:	25ef69f0 */ 	addiu	$t7,$t7,%lo(var800869f0)
/*  f1800b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1800b8:	25e80060 */ 	addiu	$t0,$t7,0x60
/*  f1800bc:	27ae0080 */ 	addiu	$t6,$sp,0x80
.L0f1800c0:
/*  f1800c0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1800c4:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f1800c8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1800cc:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f1800d0:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f1800d4:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f1800d8:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f1800dc:	15e8fff8 */ 	bne	$t7,$t0,.L0f1800c0
/*  f1800e0:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f1800e4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1800e8:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1800ec:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x33c)
/*  f1800f0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1800f4:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1800f8:	8c42a2fc */ 	lw	$v0,%lo(g_Vars+0x33c)($v0)
/*  f1800fc:	00002025 */ 	or	$a0,$zero,$zero
/*  f180100:	27a70024 */ 	addiu	$a3,$sp,0x24
/*  f180104:	10400013 */ 	beqz	$v0,.L0f180154
/*  f180108:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f18010c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f180110:	90490000 */ 	lbu	$t1,0x0($v0)
.L0f180114:
/*  f180114:	54a9000a */ 	bnel	$a1,$t1,.L0f180140
/*  f180118:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f18011c:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f180120:	00045880 */ 	sll	$t3,$a0,0x2
/*  f180124:	00eb6021 */ 	addu	$t4,$a3,$t3
/*  f180128:	906a0003 */ 	lbu	$t2,0x3($v1)
/*  f18012c:	54ca0004 */ 	bnel	$a2,$t2,.L0f180140
/*  f180130:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f180134:	ad830000 */ 	sw	$v1,0x0($t4)
/*  f180138:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18013c:	8c420020 */ 	lw	$v0,0x20($v0)
.L0f180140:
/*  f180140:	28810014 */ 	slti	$at,$a0,0x14
/*  f180144:	10400003 */ 	beqz	$v0,.L0f180154
/*  f180148:	00000000 */ 	nop
/*  f18014c:	5420fff1 */ 	bnezl	$at,.L0f180114
/*  f180150:	90490000 */ 	lbu	$t1,0x0($v0)
.L0f180154:
/*  f180154:	1880001c */ 	blez	$a0,.L0f1801c8
/*  f180158:	00000000 */ 	nop
/*  f18015c:	0c004b70 */ 	jal	random
/*  f180160:	afa40074 */ 	sw	$a0,0x74($sp)
/*  f180164:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f180168:	27a70024 */ 	addiu	$a3,$sp,0x24
/*  f18016c:	3c058008 */ 	lui	$a1,%hi(var800869ec)
/*  f180170:	0044001b */ 	divu	$zero,$v0,$a0
/*  f180174:	24a569ec */ 	addiu	$a1,$a1,%lo(var800869ec)
/*  f180178:	3c06800b */ 	lui	$a2,%hi(g_ScenarioData)
/*  f18017c:	24c6c110 */ 	addiu	$a2,$a2,%lo(g_ScenarioData)
/*  f180180:	14800002 */ 	bnez	$a0,.L0f18018c
/*  f180184:	00000000 */ 	nop
/*  f180188:	0007000d */ 	break	0x7
.L0f18018c:
/*  f18018c:	00002010 */ 	mfhi	$a0
/*  f180190:	00046880 */ 	sll	$t5,$a0,0x2
/*  f180194:	00edc821 */ 	addu	$t9,$a3,$t5
/*  f180198:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f18019c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1801a0:	87080006 */ 	lh	$t0,0x6($t8)
/*  f1801a4:	acc80014 */ 	sw	$t0,0x14($a2)
/*  f1801a8:	8f0f0040 */ 	lw	$t7,0x40($t8)
/*  f1801ac:	35ee0004 */ 	ori	$t6,$t7,0x4
/*  f1801b0:	af0e0040 */ 	sw	$t6,0x40($t8)
/*  f1801b4:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f1801b8:	90690002 */ 	lbu	$t1,0x2($v1)
/*  f1801bc:	352a0004 */ 	ori	$t2,$t1,0x4
/*  f1801c0:	10000017 */ 	b	.L0f180220
/*  f1801c4:	a06a0002 */ 	sb	$t2,0x2($v1)
.L0f1801c8:
/*  f1801c8:	3c06800b */ 	lui	$a2,%hi(g_ScenarioData)
/*  f1801cc:	24c6c110 */ 	addiu	$a2,$a2,%lo(g_ScenarioData)
/*  f1801d0:	84cb0018 */ 	lh	$t3,0x18($a2)
/*  f1801d4:	59600012 */ 	blezl	$t3,.L0f180220
/*  f1801d8:	acc00014 */ 	sw	$zero,0x14($a2)
/*  f1801dc:	0c004b70 */ 	jal	random
/*  f1801e0:	00000000 */ 	nop
/*  f1801e4:	3c06800b */ 	lui	$a2,%hi(g_ScenarioData)
/*  f1801e8:	24c6c110 */ 	addiu	$a2,$a2,%lo(g_ScenarioData)
/*  f1801ec:	84cc0018 */ 	lh	$t4,0x18($a2)
/*  f1801f0:	004c001b */ 	divu	$zero,$v0,$t4
/*  f1801f4:	00006810 */ 	mfhi	$t5
/*  f1801f8:	000dc840 */ 	sll	$t9,$t5,0x1
/*  f1801fc:	00d9c021 */ 	addu	$t8,$a2,$t9
/*  f180200:	8708001a */ 	lh	$t0,0x1a($t8)
/*  f180204:	15800002 */ 	bnez	$t4,.L0f180210
/*  f180208:	00000000 */ 	nop
/*  f18020c:	0007000d */ 	break	0x7
.L0f180210:
/*  f180210:	acc80014 */ 	sw	$t0,0x14($a2)
/*  f180214:	10000002 */ 	b	.L0f180220
/*  f180218:	00000000 */ 	nop
/*  f18021c:	acc00014 */ 	sw	$zero,0x14($a2)
.L0f180220:
/*  f180220:	3c04800b */ 	lui	$a0,%hi(var800ac258)
/*  f180224:	2484c258 */ 	addiu	$a0,$a0,%lo(var800ac258)
/*  f180228:	27af0080 */ 	addiu	$t7,$sp,0x80
/*  f18022c:	25e90060 */ 	addiu	$t1,$t7,0x60
/*  f180230:	00805025 */ 	or	$t2,$a0,$zero
.L0f180234:
/*  f180234:	8de10000 */ 	lw	$at,0x0($t7)
/*  f180238:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f18023c:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f180240:	ad41fff4 */ 	sw	$at,-0xc($t2)
/*  f180244:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f180248:	ad41fff8 */ 	sw	$at,-0x8($t2)
/*  f18024c:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f180250:	15e9fff8 */ 	bne	$t7,$t1,.L0f180234
/*  f180254:	ad41fffc */ 	sw	$at,-0x4($t2)
/*  f180258:	8de10000 */ 	lw	$at,0x0($t7)
/*  f18025c:	240503e7 */ 	addiu	$a1,$zero,0x3e7
/*  f180260:	ad410000 */ 	sw	$at,0x0($t2)
/*  f180264:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f180268:	ad490004 */ 	sw	$t1,0x4($t2)
/*  f18026c:	8ccb0014 */ 	lw	$t3,0x14($a2)
/*  f180270:	0fc0359c */ 	jal	weaponAssignToHome
/*  f180274:	a48b0006 */ 	sh	$t3,0x6($a0)
/*  f180278:	3c04800b */ 	lui	$a0,%hi(var800ac258)
/*  f18027c:	2484c258 */ 	addiu	$a0,$a0,%lo(var800ac258)
/*  f180280:	908c0002 */ 	lbu	$t4,0x2($a0)
/*  f180284:	8c990014 */ 	lw	$t9,0x14($a0)
/*  f180288:	3c06800b */ 	lui	$a2,%hi(g_ScenarioData)
/*  f18028c:	24c6c110 */ 	addiu	$a2,$a2,%lo(g_ScenarioData)
/*  f180290:	318dfffb */ 	andi	$t5,$t4,0xfffb
/*  f180294:	a08d0002 */ 	sb	$t5,0x2($a0)
/*  f180298:	13200004 */ 	beqz	$t9,.L0f1802ac
/*  f18029c:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f1802a0:	9328003f */ 	lbu	$t0,0x3f($t9)
/*  f1802a4:	350e0020 */ 	ori	$t6,$t0,0x20
/*  f1802a8:	a32e003f */ 	sb	$t6,0x3f($t9)
.L0f1802ac:
/*  f1802ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1802b0:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f1802b4:	03e00008 */ 	jr	$ra
/*  f1802b8:	00000000 */ 	nop
);

void scenarioHtbReset(void)
{
	var800869ec = 0;
	func0f1800a8();
}

void scenarioHtbCallback10(void)
{
	s32 i;
	u32 prevplayernum = g_Vars.currentplayernum;
	struct prop *prop;

	if (var800869ec && var800869ec->prop) {
		if (g_ScenarioData.htb.token == NULL || g_ScenarioData.htb.token->type != PROPTYPE_WEAPON) {
			var800869ec = NULL;
		} else {
			var800869ec->prop->timetoregen = 1200;
		}
	}

	g_ScenarioData.htb.token = NULL;

	// Check if briefcase is on the ground
	prop = g_Vars.unk00033c;

	while (prop) {
		if (prop->type == PROPTYPE_WEAPON) {
			struct weaponobj *weapon = prop->weapon;

			if (weapon->weaponnum == WEAPON_BRIEFCASE2) {
				g_ScenarioData.htb.token = prop;
			}
		}

		prop = prop->next;
	}

	// Check if a player is holding it
	if (g_ScenarioData.htb.token == NULL) {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);

			if (invHasBriefcase()) {
				g_ScenarioData.htb.token = g_Vars.currentplayer->prop;
				break;
			}
		}
	}

	setCurrentPlayerNum(prevplayernum);

	// Check if a simulant is holding it
	if (g_ScenarioData.htb.token == NULL) {
		for (i = PLAYERCOUNT(); i < g_MpNumPlayers; i++) {
			if (g_MpPlayerChrs[i]->prop && g_MpPlayerChrs[i]->aibot->unk09c_00) {
				g_ScenarioData.htb.token = g_MpPlayerChrs[i]->prop;
				break;
			}
		}
	}

	if (g_ScenarioData.htb.token == NULL) {
		func0f1800a8();
	}

	if (g_ScenarioData.htb.token == NULL) {
		g_ScenarioData.htb.pos.x = 0;
		g_ScenarioData.htb.pos.y = 0;
		g_ScenarioData.htb.pos.z = 0;
	} else {
		struct coord *pos = &g_ScenarioData.htb.pos;
		pos->x = g_ScenarioData.htb.token->pos.x;
		pos->y = g_ScenarioData.htb.token->pos.y;
		pos->z = g_ScenarioData.htb.token->pos.z;
	}
}

void scenarioHtbCallback14(struct chrdata *chr)
{
	if (chr) {
		if (chr->aibot->unk09c_00) {
			chr->aibot->unk0a0 += g_Vars.lvupdate240;

			if (chr->aibot->unk0a0 >= SECSTOTIME240(30)) {
				// Point scored sound
				audioStart(var80095200, 0x5b8, NULL, -1, -1, -1, -1, -1);
				var800ac500[mpPlayerGetIndex(chr)]->unk3e++;
				chr->aibot->unk0a0 = 0;
			}
		} else {
			chr->aibot->unk0a0 = 0;
		}
	} else {
		if (invHasBriefcase()) {
			g_Vars.currentplayerstats->tokenheldtime += g_Vars.lvupdate240;

			if (g_Vars.currentplayerstats->tokenheldtime >= SECSTOTIME240(30)) {
				// Point scored sound
				audioStart(var80095200, 0x5b8, NULL, -1, -1, -1, -1, -1);
				var800ac500[g_Vars.currentplayernum]->unk3e++;
				func0f0ddfa4(langGet(L_MPWEAPONS(24)), 9, 1); // "1 Point!"
				g_Vars.currentplayerstats->tokenheldtime = 0;
			}
		} else {
			g_Vars.currentplayerstats->tokenheldtime = 0;
		}
	}
}

GLOBAL_ASM(
glabel scenarioHtbCallback18
/*  f18079c:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f1807a0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1807a4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1807a8:	0fc44a11 */ 	jal	invHasBriefcase
/*  f1807ac:	00808025 */ 	or	$s0,$a0,$zero
/*  f1807b0:	50400067 */ 	beqzl	$v0,.L0f180950
/*  f1807b4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1807b8:	0c002f40 */ 	jal	viGetViewLeft
/*  f1807bc:	00000000 */ 	nop
/*  f1807c0:	0c002f22 */ 	jal	viGetViewWidth
/*  f1807c4:	a7a2004a */ 	sh	$v0,0x4a($sp)
/*  f1807c8:	87af004a */ 	lh	$t7,0x4a($sp)
/*  f1807cc:	04410003 */ 	bgez	$v0,.L0f1807dc
/*  f1807d0:	00027043 */ 	sra	$t6,$v0,0x1
/*  f1807d4:	24410001 */ 	addiu	$at,$v0,0x1
/*  f1807d8:	00017043 */ 	sra	$t6,$at,0x1
.L0f1807dc:
/*  f1807dc:	01cf2821 */ 	addu	$a1,$t6,$t7
/*  f1807e0:	0c002f44 */ 	jal	viGetViewTop
/*  f1807e4:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f1807e8:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x288)
/*  f1807ec:	8f39a248 */ 	lw	$t9,%lo(g_Vars+0x288)($t9)
/*  f1807f0:	2458000a */ 	addiu	$t8,$v0,0xa
/*  f1807f4:	afb8008c */ 	sw	$t8,0x8c($sp)
/*  f1807f8:	8f2a0060 */ 	lw	$t2,0x60($t9)
/*  f1807fc:	24091c20 */ 	addiu	$t1,$zero,0x1c20
/*  f180800:	3c057f1c */ 	lui	$a1,%hi(var7f1b8490)
/*  f180804:	012a1823 */ 	subu	$v1,$t1,$t2
/*  f180808:	0069001a */ 	div	$zero,$v1,$t1
/*  f18080c:	00004012 */ 	mflo	$t0
/*  f180810:	01003025 */ 	or	$a2,$t0,$zero
/*  f180814:	15200002 */ 	bnez	$t1,.L0f180820
/*  f180818:	00000000 */ 	nop
/*  f18081c:	0007000d */ 	break	0x7
.L0f180820:
/*  f180820:	2401ffff */ 	addiu	$at,$zero,-1
/*  f180824:	15210004 */ 	bne	$t1,$at,.L0f180838
/*  f180828:	3c018000 */ 	lui	$at,0x8000
/*  f18082c:	14610002 */ 	bne	$v1,$at,.L0f180838
/*  f180830:	00000000 */ 	nop
/*  f180834:	0006000d */ 	break	0x6
.L0f180838:
/*  f180838:	01090019 */ 	multu	$t0,$t1
/*  f18083c:	240100f0 */ 	addiu	$at,$zero,0xf0
/*  f180840:	24a58490 */ 	addiu	$a1,$a1,%lo(var7f1b8490)
/*  f180844:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f180848:	00005812 */ 	mflo	$t3
/*  f18084c:	006b1823 */ 	subu	$v1,$v1,$t3
/*  f180850:	246700ef */ 	addiu	$a3,$v1,0xef
/*  f180854:	00e1001a */ 	div	$zero,$a3,$at
/*  f180858:	00003812 */ 	mflo	$a3
/*  f18085c:	0c004dad */ 	jal	sprintf
/*  f180860:	00000000 */ 	nop
/*  f180864:	0fc54d8a */ 	jal	func0f153628
/*  f180868:	02002025 */ 	or	$a0,$s0,$zero
/*  f18086c:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicXs2)
/*  f180870:	8dadfb04 */ 	lw	$t5,%lo(g_FontHandelGothicXs2)($t5)
/*  f180874:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicXs1)
/*  f180878:	00408025 */ 	or	$s0,$v0,$zero
/*  f18087c:	8ce7fb08 */ 	lw	$a3,%lo(g_FontHandelGothicXs1)($a3)
/*  f180880:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f180884:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f180888:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*  f18088c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f180890:	0fc55cbe */ 	jal	textMeasure
/*  f180894:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f180898:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f18089c:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f1808a0:	8fa20094 */ 	lw	$v0,0x94($sp)
/*  f1808a4:	8fa6008c */ 	lw	$a2,0x8c($sp)
/*  f1808a8:	04e10003 */ 	bgez	$a3,.L0f1808b8
/*  f1808ac:	00077043 */ 	sra	$t6,$a3,0x1
/*  f1808b0:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f1808b4:	00017043 */ 	sra	$t6,$at,0x1
.L0f1808b8:
/*  f1808b8:	00ae2823 */ 	subu	$a1,$a1,$t6
/*  f1808bc:	00e53821 */ 	addu	$a3,$a3,$a1
/*  f1808c0:	00461021 */ 	addu	$v0,$v0,$a2
/*  f1808c4:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f1808c8:	afa20094 */ 	sw	$v0,0x94($sp)
/*  f1808cc:	afa70098 */ 	sw	$a3,0x98($sp)
/*  f1808d0:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f1808d4:	0fc54e64 */ 	jal	func0f153990
/*  f1808d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1808dc:	0c002f02 */ 	jal	viGetX
/*  f1808e0:	00408025 */ 	or	$s0,$v0,$zero
/*  f1808e4:	0c002f06 */ 	jal	viGetY
/*  f1808e8:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f1808ec:	3c0f8008 */ 	lui	$t7,%hi(g_FontNumeric1)
/*  f1808f0:	3c188008 */ 	lui	$t8,%hi(g_FontNumeric2)
/*  f1808f4:	8f18fafc */ 	lw	$t8,%lo(g_FontNumeric2)($t8)
/*  f1808f8:	8deffb00 */ 	lw	$t7,%lo(g_FontNumeric1)($t7)
/*  f1808fc:	87ab0048 */ 	lh	$t3,0x48($sp)
/*  f180900:	3c1900ff */ 	lui	$t9,0xff
/*  f180904:	373900a0 */ 	ori	$t9,$t9,0xa0
/*  f180908:	240a00a0 */ 	addiu	$t2,$zero,0xa0
/*  f18090c:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f180910:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f180914:	02002025 */ 	or	$a0,$s0,$zero
/*  f180918:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f18091c:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f180920:	27a7004c */ 	addiu	$a3,$sp,0x4c
/*  f180924:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f180928:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f18092c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f180930:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f180934:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f180938:	0fc55b92 */ 	jal	textRender
/*  f18093c:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f180940:	0fc54de0 */ 	jal	func0f153780
/*  f180944:	00402025 */ 	or	$a0,$v0,$zero
/*  f180948:	00408025 */ 	or	$s0,$v0,$zero
/*  f18094c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f180950:
/*  f180950:	02001025 */ 	or	$v0,$s0,$zero
/*  f180954:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f180958:	03e00008 */ 	jr	$ra
/*  f18095c:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

void scenarioHtbKill(struct mpchr *mpchr, s32 mpchrnum, s32 *score, s32 *arg3)
{
	struct mpchr *loopmpchr;
	s32 i;

	*score = 0;
	*score = mpchr->unk3e;

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == mpchrnum) {
				*score -= mpchr->killcounts[i];
			} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				if (i < 4) {
					loopmpchr = &g_MpPlayers[i].base;
				} else {
					loopmpchr = &g_MpSimulants[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			} else {
				*score += mpchr->killcounts[i];
			}
		}
	}

	*arg3 = mpchr->numdeaths;
}

Gfx *scenarioHtbRadar(Gfx *gdl)
{
	if ((g_MpSetup.options & MPOPTION_HTB_SHOWONRADAR) &&
			g_ScenarioData.htb.token != NULL &&
			g_ScenarioData.htb.token->type != PROPTYPE_PLAYER &&
			g_ScenarioData.htb.token->type != PROPTYPE_CHR) {
		struct coord dist;
		dist.x = g_ScenarioData.htb.pos.x - g_Vars.currentplayer->prop->pos.x;
		dist.y = g_ScenarioData.htb.pos.y - g_Vars.currentplayer->prop->pos.y;
		dist.z = g_ScenarioData.htb.pos.z - g_Vars.currentplayer->prop->pos.z;
		gdl = radarDrawDot(gdl, g_ScenarioData.htb.token, &dist, 0xff0000, 0, 1);
	}

	return gdl;
}

bool scenarioHtbRadar2(Gfx **gdl, struct prop *prop)
{
	if ((g_MpSetup.options & MPOPTION_HTB_SHOWONRADAR) &&
			g_ScenarioData.htb.token &&
			prop == g_ScenarioData.htb.token) {
		if (prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR) {
			struct coord dist;
			dist.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
			dist.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
			dist.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;

			if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				u32 colour = g_TeamColours[radarGetTeamIndex(prop->chr->team)];
				*gdl = radarDrawDot(*gdl, g_ScenarioData.htb.token, &dist, colour, 0, 1);
			} else {
				*gdl = radarDrawDot(*gdl, g_ScenarioData.htb.token, &dist, 0xff0000, 0, 1);
			}

			return true;
		}
	}

	return false;
}

bool scenarioHtbHighlight(struct prop *prop, u32 *colour)
{
	if ((g_MpSetup.options & MPOPTION_HTB_HIGHLIGHTBRIEFCASE) && prop == g_ScenarioData.htb.token) {
		colour[0] = 0;
		colour[1] = 0xff;
		colour[2] = 0;
		colour[3] = 0x40;

		return true;
	}

	return false;
}

void scenarioCtcInit(void)
{
	s32 i, j, k;
	g_MpSetup.options |= MPOPTION_TEAMSENABLED;

	for (i = 0; i < 4; i++) {
		s32 j;
		g_ScenarioData.ctc.spawnpadsperteam[i].teamindex = i;
		g_ScenarioData.ctc.spawnpadsperteam[i].numspawnpads = 0;

		for (j = 0; j < 6; j++) {
			g_ScenarioData.ctc.spawnpadsperteam[i].spawnpads[j] = -1;
		}
	}

	for (i = 0; i != 4; i++) {
		g_ScenarioData.ctc.unk00[i] = 0;
		g_ScenarioData.ctc.teamindexes[i] = -1;
	}

	for (k = 0; k < MAX_MPCHRS; k++) {
		if (g_MpSetup.chrslots & (1 << k)) {
			struct mpchr *basedata;

			if (k < 4) {
				basedata = &g_MpPlayers[k].base;
			} else {
				basedata = &g_MpSimulants[k - 4].base;
			}

			while (basedata->team >= scenarioGetMaxTeams()) {
				basedata->team -= scenarioGetMaxTeams();
			}
		}
	}
}

s32 scenarioCtcCallback08(void)
{
	return 4;
}

void scenarioCtcCallback10(void)
{
	// empty
}

void scenarioCtcCallback14()
{
	// empty
}

GLOBAL_ASM(
glabel scenarioCtcReset
/*  f180e34:	27bdff28 */ 	addiu	$sp,$sp,-216
/*  f180e38:	3c0f8008 */ 	lui	$t7,%hi(var80086b60)
/*  f180e3c:	25ef6b60 */ 	addiu	$t7,$t7,%lo(var80086b60)
/*  f180e40:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f180e44:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f180e48:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f180e4c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f180e50:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f180e54:	25e90060 */ 	addiu	$t1,$t7,0x60
/*  f180e58:	27ae0050 */ 	addiu	$t6,$sp,0x50
.L0f180e5c:
/*  f180e5c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f180e60:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f180e64:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f180e68:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f180e6c:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f180e70:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f180e74:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f180e78:	15e9fff8 */ 	bne	$t7,$t1,.L0f180e5c
/*  f180e7c:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f180e80:	8de10000 */ 	lw	$at,0x0($t7)
/*  f180e84:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f180e88:	00009025 */ 	or	$s2,$zero,$zero
/*  f180e8c:	24030006 */ 	addiu	$v1,$zero,0x6
/*  f180e90:	adc10000 */ 	sw	$at,0x0($t6)
/*  f180e94:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f180e98:	00001025 */ 	or	$v0,$zero,$zero
.L0f180e9c:
/*  f180e9c:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f180ea0:
/*  f180ea0:	5443ffff */ 	bnel	$v0,$v1,.L0f180ea0
/*  f180ea4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f180ea8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f180eac:	2a410004 */ 	slti	$at,$s2,0x4
/*  f180eb0:	5420fffa */ 	bnezl	$at,.L0f180e9c
/*  f180eb4:	00001025 */ 	or	$v0,$zero,$zero
/*  f180eb8:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f180ebc:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData+0x8)
/*  f180ec0:	2463c118 */ 	addiu	$v1,$v1,%lo(g_ScenarioData+0x8)
/*  f180ec4:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f180ec8:	27a200b8 */ 	addiu	$v0,$sp,0xb8
.L0f180ecc:
/*  f180ecc:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f180ed0:	0203082b */ 	sltu	$at,$s0,$v1
/*  f180ed4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f180ed8:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f180edc:	1420fffb */ 	bnez	$at,.L0f180ecc
/*  f180ee0:	a600fffe */ 	sh	$zero,-0x2($s0)
/*  f180ee4:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f180ee8:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f180eec:	00009025 */ 	or	$s2,$zero,$zero
/*  f180ef0:	27b100b8 */ 	addiu	$s1,$sp,0xb8
.L0f180ef4:
/*  f180ef4:	0c004b70 */ 	jal	random
/*  f180ef8:	00000000 */ 	nop
/*  f180efc:	304a0003 */ 	andi	$t2,$v0,0x3
/*  f180f00:	a60a0008 */ 	sh	$t2,0x8($s0)
/*  f180f04:	860b0008 */ 	lh	$t3,0x8($s0)
/*  f180f08:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f180f0c:	022c1821 */ 	addu	$v1,$s1,$t4
/*  f180f10:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f180f14:	15a0fff7 */ 	bnez	$t5,.L0f180ef4
/*  f180f18:	00000000 */ 	nop
/*  f180f1c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f180f20:	24010004 */ 	addiu	$at,$zero,0x4
/*  f180f24:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f180f28:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f180f2c:	1641fff1 */ 	bne	$s2,$at,.L0f180ef4
/*  f180f30:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f180f34:	3c13800b */ 	lui	$s3,%hi(g_ScenarioData)
/*  f180f38:	3c12800b */ 	lui	$s2,%hi(g_MpSetup)
/*  f180f3c:	2652cb88 */ 	addiu	$s2,$s2,%lo(g_MpSetup)
/*  f180f40:	2673c110 */ 	addiu	$s3,$s3,%lo(g_ScenarioData)
/*  f180f44:	00008825 */ 	or	$s1,$zero,$zero
/*  f180f48:	96580016 */ 	lhu	$t8,0x16($s2)
.L0f180f4c:
/*  f180f4c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f180f50:	02297804 */ 	sllv	$t7,$t1,$s1
/*  f180f54:	030f7024 */ 	and	$t6,$t8,$t7
/*  f180f58:	11c00034 */ 	beqz	$t6,.L0f18102c
/*  f180f5c:	2a210004 */ 	slti	$at,$s1,0x4
/*  f180f60:	10200008 */ 	beqz	$at,.L0f180f84
/*  f180f64:	00116080 */ 	sll	$t4,$s1,0x2
/*  f180f68:	00115080 */ 	sll	$t2,$s1,0x2
/*  f180f6c:	01515021 */ 	addu	$t2,$t2,$s1
/*  f180f70:	3c0b800b */ 	lui	$t3,%hi(g_MpPlayers)
/*  f180f74:	256bc7b8 */ 	addiu	$t3,$t3,%lo(g_MpPlayers)
/*  f180f78:	000a5140 */ 	sll	$t2,$t2,0x5
/*  f180f7c:	10000009 */ 	b	.L0f180fa4
/*  f180f80:	014b8021 */ 	addu	$s0,$t2,$t3
.L0f180f84:
/*  f180f84:	01916021 */ 	addu	$t4,$t4,$s1
/*  f180f88:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f180f8c:	01916023 */ 	subu	$t4,$t4,$s1
/*  f180f90:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f180f94:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f180f98:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f180f9c:	258dfed0 */ 	addiu	$t5,$t4,-304
/*  f180fa0:	01b98021 */ 	addu	$s0,$t5,$t9
.L0f180fa4:
/*  f180fa4:	0fc61902 */ 	jal	scenarioGetMaxTeams
/*  f180fa8:	00000000 */ 	nop
/*  f180fac:	92090011 */ 	lbu	$t1,0x11($s0)
/*  f180fb0:	0122082a */ 	slt	$at,$t1,$v0
/*  f180fb4:	1420000b */ 	bnez	$at,.L0f180fe4
/*  f180fb8:	00000000 */ 	nop
.L0f180fbc:
/*  f180fbc:	0fc61902 */ 	jal	scenarioGetMaxTeams
/*  f180fc0:	00000000 */ 	nop
/*  f180fc4:	92180011 */ 	lbu	$t8,0x11($s0)
/*  f180fc8:	03027823 */ 	subu	$t7,$t8,$v0
/*  f180fcc:	0fc61902 */ 	jal	scenarioGetMaxTeams
/*  f180fd0:	a20f0011 */ 	sb	$t7,0x11($s0)
/*  f180fd4:	920e0011 */ 	lbu	$t6,0x11($s0)
/*  f180fd8:	01c2082a */ 	slt	$at,$t6,$v0
/*  f180fdc:	1020fff7 */ 	beqz	$at,.L0f180fbc
/*  f180fe0:	00000000 */ 	nop
.L0f180fe4:
/*  f180fe4:	0fc6343a */ 	jal	func0f18d0e8
/*  f180fe8:	02202025 */ 	or	$a0,$s1,$zero
/*  f180fec:	04400009 */ 	bltz	$v0,.L0f181014
/*  f180ff0:	00402025 */ 	or	$a0,$v0,$zero
/*  f180ff4:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f180ff8:	00000000 */ 	nop
/*  f180ffc:	50400006 */ 	beqzl	$v0,.L0f181018
/*  f181000:	920d0011 */ 	lbu	$t5,0x11($s0)
/*  f181004:	920a0011 */ 	lbu	$t2,0x11($s0)
/*  f181008:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f18100c:	014b6004 */ 	sllv	$t4,$t3,$t2
/*  f181010:	a04c0125 */ 	sb	$t4,0x125($v0)
.L0f181014:
/*  f181014:	920d0011 */ 	lbu	$t5,0x11($s0)
.L0f181018:
/*  f181018:	000dc840 */ 	sll	$t9,$t5,0x1
/*  f18101c:	02791021 */ 	addu	$v0,$s3,$t9
/*  f181020:	84490000 */ 	lh	$t1,0x0($v0)
/*  f181024:	25380001 */ 	addiu	$t8,$t1,0x1
/*  f181028:	a4580000 */ 	sh	$t8,0x0($v0)
.L0f18102c:
/*  f18102c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f181030:	2a21000c */ 	slti	$at,$s1,0xc
/*  f181034:	5420ffc5 */ 	bnezl	$at,.L0f180f4c
/*  f181038:	96580016 */ 	lhu	$t8,0x16($s2)
/*  f18103c:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f181040:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData+0x8)
/*  f181044:	2442c118 */ 	addiu	$v0,$v0,%lo(g_ScenarioData+0x8)
/*  f181048:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f18104c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f181050:	860f0000 */ 	lh	$t7,0x0($s0)
.L0f181054:
/*  f181054:	55e00003 */ 	bnezl	$t7,.L0f181064
/*  f181058:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f18105c:	a6080008 */ 	sh	$t0,0x8($s0)
/*  f181060:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f181064:
/*  f181064:	0202082b */ 	sltu	$at,$s0,$v0
/*  f181068:	5420fffa */ 	bnezl	$at,.L0f181054
/*  f18106c:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f181070:	00009025 */ 	or	$s2,$zero,$zero
/*  f181074:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f181078:
/*  f181078:	2a410004 */ 	slti	$at,$s2,0x4
/*  f18107c:	5420fffe */ 	bnezl	$at,.L0f181078
/*  f181080:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f181084:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f181088:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData+0x10)
/*  f18108c:	2463c120 */ 	addiu	$v1,$v1,%lo(g_ScenarioData+0x10)
/*  f181090:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
.L0f181094:
/*  f181094:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f181098:	0043082b */ 	sltu	$at,$v0,$v1
/*  f18109c:	1420fffd */ 	bnez	$at,.L0f181094
/*  f1810a0:	ac400054 */ 	sw	$zero,0x54($v0)
/*  f1810a4:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f1810a8:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData+0x8)
/*  f1810ac:	2442c118 */ 	addiu	$v0,$v0,%lo(g_ScenarioData+0x8)
/*  f1810b0:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
.L0f1810b4:
/*  f1810b4:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f1810b8:	0202082b */ 	sltu	$at,$s0,$v0
/*  f1810bc:	1420fffd */ 	bnez	$at,.L0f1810b4
/*  f1810c0:	a608000e */ 	sh	$t0,0xe($s0)
/*  f1810c4:	866e0000 */ 	lh	$t6,0x0($s3)
/*  f1810c8:	3c04800b */ 	lui	$a0,%hi(var800ac2c0)
/*  f1810cc:	2484c2c0 */ 	addiu	$a0,$a0,%lo(var800ac2c0)
/*  f1810d0:	11c00026 */ 	beqz	$t6,.L0f18116c
/*  f1810d4:	27ab0050 */ 	addiu	$t3,$sp,0x50
/*  f1810d8:	00806825 */ 	or	$t5,$a0,$zero
/*  f1810dc:	256c0060 */ 	addiu	$t4,$t3,0x60
.L0f1810e0:
/*  f1810e0:	8d610000 */ 	lw	$at,0x0($t3)
/*  f1810e4:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f1810e8:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f1810ec:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f1810f0:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f1810f4:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f1810f8:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f1810fc:	156cfff8 */ 	bne	$t3,$t4,.L0f1810e0
/*  f181100:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f181104:	8d610000 */ 	lw	$at,0x0($t3)
/*  f181108:	240503e8 */ 	addiu	$a1,$zero,0x3e8
/*  f18110c:	ada10000 */ 	sw	$at,0x0($t5)
/*  f181110:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*  f181114:	adac0004 */ 	sw	$t4,0x4($t5)
/*  f181118:	86790008 */ 	lh	$t9,0x8($s3)
/*  f18111c:	00194900 */ 	sll	$t1,$t9,0x4
/*  f181120:	0269c021 */ 	addu	$t8,$s3,$t1
/*  f181124:	870f0018 */ 	lh	$t7,0x18($t8)
/*  f181128:	0fc0359c */ 	jal	weaponAssignToHome
/*  f18112c:	a48f0006 */ 	sh	$t7,0x6($a0)
/*  f181130:	3c0e800b */ 	lui	$t6,%hi(var800ac2d4)
/*  f181134:	8dcec2d4 */ 	lw	$t6,%lo(var800ac2d4)($t6)
/*  f181138:	3c0a800b */ 	lui	$t2,%hi(var800ac2c0+0x2)
/*  f18113c:	914ac2c2 */ 	lbu	$t2,%lo(var800ac2c0+0x2)($t2)
/*  f181140:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x58)
/*  f181144:	ac2ec168 */ 	sw	$t6,%lo(g_ScenarioData+0x58)($at)
/*  f181148:	3c01800b */ 	lui	$at,%hi(var800ac2c0+0x2)
/*  f18114c:	314cfffb */ 	andi	$t4,$t2,0xfffb
/*  f181150:	a02cc2c2 */ 	sb	$t4,%lo(var800ac2c0+0x2)($at)
/*  f181154:	3c01800b */ 	lui	$at,%hi(var800ac320+0x2)
/*  f181158:	a420c322 */ 	sh	$zero,%lo(var800ac320+0x2)($at)
/*  f18115c:	8e6b0058 */ 	lw	$t3,0x58($s3)
/*  f181160:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f181164:	856d0028 */ 	lh	$t5,0x28($t3)
/*  f181168:	a66d0010 */ 	sh	$t5,0x10($s3)
.L0f18116c:
/*  f18116c:	86790002 */ 	lh	$t9,0x2($s3)
/*  f181170:	3c04800b */ 	lui	$a0,%hi(var800ac328)
/*  f181174:	2410fffb */ 	addiu	$s0,$zero,-5
/*  f181178:	13200028 */ 	beqz	$t9,.L0f18121c
/*  f18117c:	2484c328 */ 	addiu	$a0,$a0,%lo(var800ac328)
/*  f181180:	27a90050 */ 	addiu	$t1,$sp,0x50
/*  f181184:	252f0060 */ 	addiu	$t7,$t1,0x60
/*  f181188:	00807025 */ 	or	$t6,$a0,$zero
.L0f18118c:
/*  f18118c:	8d210000 */ 	lw	$at,0x0($t1)
/*  f181190:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f181194:	25ce000c */ 	addiu	$t6,$t6,0x000c
/*  f181198:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f18119c:	8d21fff8 */ 	lw	$at,-0x8($t1)
/*  f1811a0:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f1811a4:	8d21fffc */ 	lw	$at,-0x4($t1)
/*  f1811a8:	152ffff8 */ 	bne	$t1,$t7,.L0f18118c
/*  f1811ac:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f1811b0:	8d210000 */ 	lw	$at,0x0($t1)
/*  f1811b4:	240503e9 */ 	addiu	$a1,$zero,0x3e9
/*  f1811b8:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1811bc:	8d2f0004 */ 	lw	$t7,0x4($t1)
/*  f1811c0:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f1811c4:	866a000a */ 	lh	$t2,0xa($s3)
/*  f1811c8:	000a6100 */ 	sll	$t4,$t2,0x4
/*  f1811cc:	026c5821 */ 	addu	$t3,$s3,$t4
/*  f1811d0:	856d0018 */ 	lh	$t5,0x18($t3)
/*  f1811d4:	0fc0359c */ 	jal	weaponAssignToHome
/*  f1811d8:	a48d0006 */ 	sh	$t5,0x6($a0)
/*  f1811dc:	3c19800b */ 	lui	$t9,%hi(var800ac33c)
/*  f1811e0:	8f39c33c */ 	lw	$t9,%lo(var800ac33c)($t9)
/*  f1811e4:	3c18800b */ 	lui	$t8,%hi(var800ac328+0x2)
/*  f1811e8:	9318c32a */ 	lbu	$t8,%lo(var800ac328+0x2)($t8)
/*  f1811ec:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x5c)
/*  f1811f0:	ac39c16c */ 	sw	$t9,%lo(g_ScenarioData+0x5c)($at)
/*  f1811f4:	3c01800b */ 	lui	$at,%hi(var800ac328+0x2)
/*  f1811f8:	03107824 */ 	and	$t7,$t8,$s0
/*  f1811fc:	a02fc32a */ 	sb	$t7,%lo(var800ac328+0x2)($at)
/*  f181200:	3c01800b */ 	lui	$at,%hi(var800ac388+0x2)
/*  f181204:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f181208:	a429c38a */ 	sh	$t1,%lo(var800ac388+0x2)($at)
/*  f18120c:	8e6e005c */ 	lw	$t6,0x5c($s3)
/*  f181210:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f181214:	85ca0028 */ 	lh	$t2,0x28($t6)
/*  f181218:	a66a0012 */ 	sh	$t2,0x12($s3)
.L0f18121c:
/*  f18121c:	866c0004 */ 	lh	$t4,0x4($s3)
/*  f181220:	3c04800b */ 	lui	$a0,%hi(var800ac390)
/*  f181224:	2484c390 */ 	addiu	$a0,$a0,%lo(var800ac390)
/*  f181228:	11800027 */ 	beqz	$t4,.L0f1812c8
/*  f18122c:	27ab0050 */ 	addiu	$t3,$sp,0x50
/*  f181230:	0080c025 */ 	or	$t8,$a0,$zero
/*  f181234:	25790060 */ 	addiu	$t9,$t3,0x60
.L0f181238:
/*  f181238:	8d610000 */ 	lw	$at,0x0($t3)
/*  f18123c:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f181240:	2718000c */ 	addiu	$t8,$t8,0x000c
/*  f181244:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f181248:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f18124c:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f181250:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f181254:	1579fff8 */ 	bne	$t3,$t9,.L0f181238
/*  f181258:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f18125c:	8d610000 */ 	lw	$at,0x0($t3)
/*  f181260:	240503ea */ 	addiu	$a1,$zero,0x3ea
/*  f181264:	af010000 */ 	sw	$at,0x0($t8)
/*  f181268:	8d790004 */ 	lw	$t9,0x4($t3)
/*  f18126c:	af190004 */ 	sw	$t9,0x4($t8)
/*  f181270:	866f000c */ 	lh	$t7,0xc($s3)
/*  f181274:	000f4900 */ 	sll	$t1,$t7,0x4
/*  f181278:	02697021 */ 	addu	$t6,$s3,$t1
/*  f18127c:	85ca0018 */ 	lh	$t2,0x18($t6)
/*  f181280:	0fc0359c */ 	jal	weaponAssignToHome
/*  f181284:	a48a0006 */ 	sh	$t2,0x6($a0)
/*  f181288:	3c0c800b */ 	lui	$t4,%hi(var800ac3a4)
/*  f18128c:	8d8cc3a4 */ 	lw	$t4,%lo(var800ac3a4)($t4)
/*  f181290:	3c0d800b */ 	lui	$t5,%hi(var800ac390+0x2)
/*  f181294:	91adc392 */ 	lbu	$t5,%lo(var800ac390+0x2)($t5)
/*  f181298:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x60)
/*  f18129c:	ac2cc170 */ 	sw	$t4,%lo(g_ScenarioData+0x60)($at)
/*  f1812a0:	3c01800b */ 	lui	$at,%hi(var800ac390+0x2)
/*  f1812a4:	01b0c824 */ 	and	$t9,$t5,$s0
/*  f1812a8:	a039c392 */ 	sb	$t9,%lo(var800ac390+0x2)($at)
/*  f1812ac:	3c01800b */ 	lui	$at,%hi(var800ac3f0+0x2)
/*  f1812b0:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f1812b4:	a42bc3f2 */ 	sh	$t3,%lo(var800ac3f0+0x2)($at)
/*  f1812b8:	8e780060 */ 	lw	$t8,0x60($s3)
/*  f1812bc:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f1812c0:	870f0028 */ 	lh	$t7,0x28($t8)
/*  f1812c4:	a66f0014 */ 	sh	$t7,0x14($s3)
.L0f1812c8:
/*  f1812c8:	86690006 */ 	lh	$t1,0x6($s3)
/*  f1812cc:	3c04800b */ 	lui	$a0,%hi(var800ac3f8)
/*  f1812d0:	2484c3f8 */ 	addiu	$a0,$a0,%lo(var800ac3f8)
/*  f1812d4:	11200027 */ 	beqz	$t1,.L0f181374
/*  f1812d8:	27ae0050 */ 	addiu	$t6,$sp,0x50
/*  f1812dc:	00806825 */ 	or	$t5,$a0,$zero
/*  f1812e0:	25cc0060 */ 	addiu	$t4,$t6,0x60
.L0f1812e4:
/*  f1812e4:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1812e8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1812ec:	25ad000c */ 	addiu	$t5,$t5,0x000c
/*  f1812f0:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f1812f4:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f1812f8:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f1812fc:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f181300:	15ccfff8 */ 	bne	$t6,$t4,.L0f1812e4
/*  f181304:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f181308:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f18130c:	240503eb */ 	addiu	$a1,$zero,0x3eb
/*  f181310:	ada10000 */ 	sw	$at,0x0($t5)
/*  f181314:	8dcc0004 */ 	lw	$t4,0x4($t6)
/*  f181318:	adac0004 */ 	sw	$t4,0x4($t5)
/*  f18131c:	8679000e */ 	lh	$t9,0xe($s3)
/*  f181320:	00195900 */ 	sll	$t3,$t9,0x4
/*  f181324:	026bc021 */ 	addu	$t8,$s3,$t3
/*  f181328:	870f0018 */ 	lh	$t7,0x18($t8)
/*  f18132c:	0fc0359c */ 	jal	weaponAssignToHome
/*  f181330:	a48f0006 */ 	sh	$t7,0x6($a0)
/*  f181334:	3c09800b */ 	lui	$t1,%hi(var800ac40c)
/*  f181338:	8d29c40c */ 	lw	$t1,%lo(var800ac40c)($t1)
/*  f18133c:	3c0a800b */ 	lui	$t2,%hi(var800ac3f8+0x2)
/*  f181340:	914ac3fa */ 	lbu	$t2,%lo(var800ac3f8+0x2)($t2)
/*  f181344:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x64)
/*  f181348:	ac29c174 */ 	sw	$t1,%lo(g_ScenarioData+0x64)($at)
/*  f18134c:	3c01800b */ 	lui	$at,%hi(var800ac3f8+0x2)
/*  f181350:	01506024 */ 	and	$t4,$t2,$s0
/*  f181354:	a02cc3fa */ 	sb	$t4,%lo(var800ac3f8+0x2)($at)
/*  f181358:	3c01800b */ 	lui	$at,%hi(var800ac458+0x2)
/*  f18135c:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f181360:	a42ec45a */ 	sh	$t6,%lo(var800ac458+0x2)($at)
/*  f181364:	8e6d0064 */ 	lw	$t5,0x64($s3)
/*  f181368:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f18136c:	85b90028 */ 	lh	$t9,0x28($t5)
/*  f181370:	a6790016 */ 	sh	$t9,0x16($s3)
.L0f181374:
/*  f181374:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f181378:	3c11800b */ 	lui	$s1,%hi(g_ScenarioData+0x8)
/*  f18137c:	2631c118 */ 	addiu	$s1,$s1,%lo(g_ScenarioData+0x8)
/*  f181380:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f181384:	860b0000 */ 	lh	$t3,0x0($s0)
.L0f181388:
/*  f181388:	5160000a */ 	beqzl	$t3,.L0f1813b4
/*  f18138c:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f181390:	86040010 */ 	lh	$a0,0x10($s0)
/*  f181394:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f181398:	00003025 */ 	or	$a2,$zero,$zero
/*  f18139c:	11040004 */ 	beq	$t0,$a0,.L0f1813b0
/*  f1813a0:	00003825 */ 	or	$a3,$zero,$zero
/*  f1813a4:	0fc00b0a */ 	jal	roomSetLighting
/*  f1813a8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1813ac:	2408ffff */ 	addiu	$t0,$zero,-1
.L0f1813b0:
/*  f1813b0:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f1813b4:
/*  f1813b4:	5611fff4 */ 	bnel	$s0,$s1,.L0f181388
/*  f1813b8:	860b0000 */ 	lh	$t3,0x0($s0)
/*  f1813bc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1813c0:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f1813c4:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f1813c8:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f1813cc:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f1813d0:	03e00008 */ 	jr	$ra
/*  f1813d4:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
);

void scenarioCtcKill(struct mpchr *mpchr, s32 mpchrnum, s32 *score, s32 *arg3)
{
	struct mpchr *loopmpchr;
	s32 i;

	*score = 0;
	*score = mpchr->unk3e * 3;

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == mpchrnum) {
				*score -= mpchr->killcounts[i];
			} else {
				if (i < 4) {
					loopmpchr = &g_MpPlayers[i].base;
				} else {
					loopmpchr = &g_MpSimulants[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			}
		}
	}

	*arg3 = mpchr->numdeaths;
}

Gfx *scenarioCtcRadar(Gfx *gdl)
{
	if (g_MpSetup.options & MPOPTION_CTC_SHOWONRADAR) {
		s32 i;

		for (i = 0; i < scenarioGetMaxTeams(); i++) {
			if (g_ScenarioData.ctc.tokens[i] &&
					g_ScenarioData.ctc.tokens[i]->type != PROPTYPE_CHR &&
					g_ScenarioData.ctc.tokens[i]->type != PROPTYPE_PLAYER) {
				struct coord dist;
				dist.x = g_ScenarioData.ctc.tokens[i]->pos.x - g_Vars.currentplayer->prop->pos.x;
				dist.y = g_ScenarioData.ctc.tokens[i]->pos.y - g_Vars.currentplayer->prop->pos.y;
				dist.z = g_ScenarioData.ctc.tokens[i]->pos.z - g_Vars.currentplayer->prop->pos.z;
				gdl = radarDrawDot(gdl, g_ScenarioData.ctc.tokens[i], &dist, g_TeamColours[i], 0, 1);
			}
		}
	}

	return gdl;
}

bool scenarioCtcRadar2(Gfx **gdl, struct prop *prop)
{
	s32 i;

	if (g_MpSetup.options & MPOPTION_CTC_SHOWONRADAR) {
		for (i = 0; i < scenarioGetMaxTeams(); i++) {
			if (prop == g_ScenarioData.ctc.tokens[i] &&
					(g_ScenarioData.ctc.tokens[i]->type == PROPTYPE_CHR || g_ScenarioData.ctc.tokens[i]->type == PROPTYPE_PLAYER)) {
				struct coord dist;
				s32 colour = g_TeamColours[radarGetTeamIndex(prop->chr->team)];
				dist.x = g_ScenarioData.ctc.tokens[i]->pos.x - g_Vars.currentplayer->prop->pos.x;
				dist.y = g_ScenarioData.ctc.tokens[i]->pos.y - g_Vars.currentplayer->prop->pos.y;
				dist.z = g_ScenarioData.ctc.tokens[i]->pos.z - g_Vars.currentplayer->prop->pos.z;
				*gdl = radarDrawDot(*gdl, g_ScenarioData.ctc.tokens[i], &dist,
						g_TeamColours[i], colour, 1);
				return true;
			}
		}
	}

	return false;
}

GLOBAL_ASM(
glabel scenarioCtcHighlight
/*  f181764:	90860000 */ 	lbu	$a2,0x0($a0)
/*  f181768:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f18176c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f181770:	10c10006 */ 	beq	$a2,$at,.L0f18178c
/*  f181774:	00601025 */ 	or	$v0,$v1,$zero
/*  f181778:	24010004 */ 	addiu	$at,$zero,0x4
/*  f18177c:	10c10003 */ 	beq	$a2,$at,.L0f18178c
/*  f181780:	24010002 */ 	addiu	$at,$zero,0x2
/*  f181784:	54c1001c */ 	bnel	$a2,$at,.L0f1817f8
/*  f181788:	00001025 */ 	or	$v0,$zero,$zero
.L0f18178c:
/*  f18178c:	904e0003 */ 	lbu	$t6,0x3($v0)
/*  f181790:	24010008 */ 	addiu	$at,$zero,0x8
/*  f181794:	55c10018 */ 	bnel	$t6,$at,.L0f1817f8
/*  f181798:	00001025 */ 	or	$v0,$zero,$zero
/*  f18179c:	906f005c */ 	lbu	$t7,0x5c($v1)
/*  f1817a0:	24010057 */ 	addiu	$at,$zero,0x57
/*  f1817a4:	55e10014 */ 	bnel	$t7,$at,.L0f1817f8
/*  f1817a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1817ac:	84780062 */ 	lh	$t8,0x62($v1)
/*  f1817b0:	3c038008 */ 	lui	$v1,%hi(g_TeamColours)
/*  f1817b4:	240e004b */ 	addiu	$t6,$zero,0x4b
/*  f1817b8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1817bc:	00791821 */ 	addu	$v1,$v1,$t9
/*  f1817c0:	8c637cc4 */ 	lw	$v1,%lo(g_TeamColours)($v1)
/*  f1817c4:	acae000c */ 	sw	$t6,0xc($a1)
/*  f1817c8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1817cc:	00034602 */ 	srl	$t0,$v1,0x18
/*  f1817d0:	00035402 */ 	srl	$t2,$v1,0x10
/*  f1817d4:	00036202 */ 	srl	$t4,$v1,0x8
/*  f1817d8:	310900ff */ 	andi	$t1,$t0,0xff
/*  f1817dc:	314b00ff */ 	andi	$t3,$t2,0xff
/*  f1817e0:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f1817e4:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f1817e8:	acab0004 */ 	sw	$t3,0x4($a1)
/*  f1817ec:	03e00008 */ 	jr	$ra
/*  f1817f0:	acad0008 */ 	sw	$t5,0x8($a1)
/*  f1817f4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1817f8:
/*  f1817f8:	03e00008 */ 	jr	$ra
/*  f1817fc:	00000000 */ 	nop
);

//bool scenarioCtcHighlight(struct prop *prop, u32 *colour)
//{
//	if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR) {
//		if (prop->obj->type == OBJTYPE_WEAPON && prop->weapon->weaponnum == WEAPON_BRIEFCASE2) {
//			u32 teamcolour = g_TeamColours[prop->weapon->team];
//
//			colour[0] = teamcolour >> 24 & 0xff;
//			colour[1] = teamcolour >> 16 & 0xff;
//			colour[2] = teamcolour >> 8 & 0xff;
//			colour[3] = 75;
//
//			return true;
//		}
//	}
//
//	return false;
//}

GLOBAL_ASM(
glabel func0f181800
/*  f181800:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f181804:	24010009 */ 	addiu	$at,$zero,0x9
/*  f181808:	00001825 */ 	or	$v1,$zero,$zero
/*  f18180c:	14410008 */ 	bne	$v0,$at,.L0f181830
/*  f181810:	3c09800b */ 	lui	$t1,%hi(g_ScenarioData)
/*  f181814:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f181818:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*  f18181c:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x18)
/*  f181820:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f181824:	00380821 */ 	addu	$at,$at,$t8
/*  f181828:	a42ec128 */ 	sh	$t6,%lo(g_ScenarioData+0x18)($at)
/*  f18182c:	8c820000 */ 	lw	$v0,0x0($a0)
.L0f181830:
/*  f181830:	2401000a */ 	addiu	$at,$zero,0xa
/*  f181834:	14410017 */ 	bne	$v0,$at,.L0f181894
/*  f181838:	2529c110 */ 	addiu	$t1,$t1,%lo(g_ScenarioData)
/*  f18183c:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f181840:	2406000c */ 	addiu	$a2,$zero,0xc
/*  f181844:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f181848:	00194100 */ 	sll	$t0,$t9,0x4
/*  f18184c:	01092821 */ 	addu	$a1,$t0,$t1
.L0f181850:
/*  f181850:	84aa001c */ 	lh	$t2,0x1c($a1)
/*  f181854:	544a000d */ 	bnel	$v0,$t2,.L0f18188c
/*  f181858:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f18185c:	8c8b0008 */ 	lw	$t3,0x8($a0)
/*  f181860:	3c0f800b */ 	lui	$t7,%hi(g_ScenarioData)
/*  f181864:	25efc110 */ 	addiu	$t7,$t7,%lo(g_ScenarioData)
/*  f181868:	a4ab001c */ 	sh	$t3,0x1c($a1)
/*  f18186c:	8c8c0004 */ 	lw	$t4,0x4($a0)
/*  f181870:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f181874:	01af1021 */ 	addu	$v0,$t5,$t7
/*  f181878:	844e001a */ 	lh	$t6,0x1a($v0)
/*  f18187c:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f181880:	03e00008 */ 	jr	$ra
/*  f181884:	a458001a */ 	sh	$t8,0x1a($v0)
/*  f181888:	24630002 */ 	addiu	$v1,$v1,0x2
.L0f18188c:
/*  f18188c:	1466fff0 */ 	bne	$v1,$a2,.L0f181850
/*  f181890:	24a50002 */ 	addiu	$a1,$a1,0x2
.L0f181894:
/*  f181894:	03e00008 */ 	jr	$ra
/*  f181898:	00000000 */ 	nop
);

bool scenarioCtcCallback2c(f32 arg0, struct coord *pos, s16 *rooms, struct prop *prop, f32 *arg4)
{
	struct chrdata *chr = prop->chr;
	s32 index = radarGetTeamIndex(chr->team);

	if (g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[index]].numspawnpads > 0) {
		*arg4 = func0f0b69d0(arg0, pos, rooms, prop,
				g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[index]].spawnpads,
				g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[index]].numspawnpads);
		return true;
	}

	return false;
}

s32 scenarioCtcGetMaxTeams(void)
{
	return 4;
}

bool scenarioCtcIsRoomHighlighted(s16 room)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_ScenarioData.ctc.baserooms[i] == room && g_ScenarioData.ctc.teamindexes[i] != -1) {
			return true;
		}
	}

	return false;
}

GLOBAL_ASM(
glabel scenarioCtcCallback38
/*  f1819a4:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f1819a8:	00047400 */ 	sll	$t6,$a0,0x10
/*  f1819ac:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f1819b0:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f1819b4:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f1819b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1819bc:	24080004 */ 	addiu	$t0,$zero,0x4
.L0f1819c0:
/*  f1819c0:	84780010 */ 	lh	$t8,0x10($v1)
/*  f1819c4:	1498002f */ 	bne	$a0,$t8,.L0f181a84
/*  f1819c8:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f1819cc:	3c038008 */ 	lui	$v1,%hi(g_TeamColours)
/*  f1819d0:	00791821 */ 	addu	$v1,$v1,$t9
/*  f1819d4:	8c637cc4 */ 	lw	$v1,%lo(g_TeamColours)($v1)
/*  f1819d8:	8ca90000 */ 	lw	$t1,0x0($a1)
/*  f1819dc:	3c013b00 */ 	lui	$at,0x3b00
/*  f1819e0:	00036602 */ 	srl	$t4,$v1,0x18
/*  f1819e4:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f1819e8:	25ae00ff */ 	addiu	$t6,$t5,0xff
/*  f1819ec:	448e5000 */ 	mtc1	$t6,$f10
/*  f1819f0:	44817000 */ 	mtc1	$at,$f14
/*  f1819f4:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f1819f8:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f1819fc:	44892000 */ 	mtc1	$t1,$f4
/*  f181a00:	00037c02 */ 	srl	$t7,$v1,0x10
/*  f181a04:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f181a08:	448a3000 */ 	mtc1	$t2,$f6
/*  f181a0c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f181a10:	460e8482 */ 	mul.s	$f18,$f16,$f14
/*  f181a14:	271900ff */ 	addiu	$t9,$t8,0xff
/*  f181a18:	44992000 */ 	mtc1	$t9,$f4
/*  f181a1c:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f181a20:	00034a02 */ 	srl	$t1,$v1,0x8
/*  f181a24:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f181a28:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f181a2c:	448b4000 */ 	mtc1	$t3,$f8
/*  f181a30:	46120002 */ 	mul.s	$f0,$f0,$f18
/*  f181a34:	254b00ff */ 	addiu	$t3,$t2,0xff
/*  f181a38:	448b5000 */ 	mtc1	$t3,$f10
/*  f181a3c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f181a40:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f181a44:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f181a48:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f181a4c:	46081082 */ 	mul.s	$f2,$f2,$f8
/*  f181a50:	00000000 */ 	nop
/*  f181a54:	460e8482 */ 	mul.s	$f18,$f16,$f14
/*  f181a58:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f181a5c:	46126302 */ 	mul.s	$f12,$f12,$f18
/*  f181a60:	440d2000 */ 	mfc1	$t5,$f4
/*  f181a64:	4600118d */ 	trunc.w.s	$f6,$f2
/*  f181a68:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f181a6c:	4600620d */ 	trunc.w.s	$f8,$f12
/*  f181a70:	440f3000 */ 	mfc1	$t7,$f6
/*  f181a74:	44194000 */ 	mfc1	$t9,$f8
/*  f181a78:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f181a7c:	03e00008 */ 	jr	$ra
/*  f181a80:	acf90000 */ 	sw	$t9,0x0($a3)
.L0f181a84:
/*  f181a84:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f181a88:	1448ffcd */ 	bne	$v0,$t0,.L0f1819c0
/*  f181a8c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f181a90:	03e00008 */ 	jr	$ra
/*  f181a94:	00000000 */ 	nop
);

s32 menuhandlerMpHillTime(u32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_Vars.mphilltime;
		break;
	case MENUOP_SET:
		g_Vars.mphilltime = (u8)data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, langGet(L_MPWEAPONS(23)), data->slider.value + 10); // "%ds/Point"
		break;
	}

	return 0;
}

void scenarioKohCallback40(s32 *arg0)
{
	g_Vars.mphilltime = savefileGetInteger(arg0, 8);
}

void scenarioKohCallback44(s32 *arg0)
{
	savefileGetSomething(arg0, g_Vars.mphilltime, 8);
}

void scenarioKohInit(void)
{
	s32 i;

	g_MpSetup.options |= MPOPTION_TEAMSENABLED;
	g_ScenarioData.koh.hillindex = -1;
	g_ScenarioData.koh.hillcount = 0;
	g_ScenarioData.koh.unk00 = 0;
	g_ScenarioData.koh.occupiedteam = -1;
	g_ScenarioData.koh.unk06 = 0;
	g_ScenarioData.koh.hillroom = -1;
	g_ScenarioData.koh.unk10 = -1;
	g_ScenarioData.koh.hillpos.x = 0;
	g_ScenarioData.koh.hillpos.y = 0;
	g_ScenarioData.koh.hillpos.z = 0;
	g_ScenarioData.koh.unk30 = 0.25;
	g_ScenarioData.koh.unk34 = 1;
	g_ScenarioData.koh.unk38 = 0.25;

	for (i = 0; i < 9; i++) {
		g_ScenarioData.koh.hillpads[i] = -1;
	}
}

void scenarioKohReset(void)
{
	s16 pad_id = 0;
	struct pad pad;

	if (g_ScenarioData.koh.hillcount > 1) {
		g_ScenarioData.koh.hillindex = random() % g_ScenarioData.koh.hillcount;
		pad_id = g_ScenarioData.koh.hillpads[g_ScenarioData.koh.hillindex];
	} else {
		// @bug: If a stage setup file only has one hill, pad_id is not assigned
		// so it will always use the room that contains pad zero.
		g_ScenarioData.koh.hillindex = 0;
	}

	padUnpack(pad_id, PADFIELD_POS | PADFIELD_ROOM, &pad);
	g_ScenarioData.koh.hillroom = pad.room;
	g_ScenarioData.koh.unk10 = -1;
	g_ScenarioData.koh.hillpos.x = pad.pos.x;
	g_ScenarioData.koh.hillpos.y = pad.pos.y;
	g_ScenarioData.koh.hillpos.z = pad.pos.z;
	g_ScenarioData.koh.hillpos.y = func0002a36c(&g_ScenarioData.koh.hillpos, &g_ScenarioData.koh.hillroom, 0, 0);
	g_ScenarioData.koh.unk08 = 0;
	roomSetLighting(g_ScenarioData.koh.hillroom, LIGHTOP_5, 0, 0, 0);
}

GLOBAL_ASM(
glabel scenarioKohCallback10
.late_rodata
glabel var7f1b893c
.word 0x3f733333
glabel var7f1b8940
.word 0x3d4ccccd
glabel var7f1b8944
.word 0x3f733333
glabel var7f1b8948
.word 0x3f733333
glabel var7f1b894c
.word 0x3d4ccccd
glabel var7f1b8950
.word 0x3d4ccccd
.text
/*  f181cf0:	27bdfe78 */ 	addiu	$sp,$sp,-392
/*  f181cf4:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f181cf8:	3c13800b */ 	lui	$s3,%hi(g_ScenarioData)
/*  f181cfc:	2673c110 */ 	addiu	$s3,$s3,%lo(g_ScenarioData)
/*  f181d00:	866e000a */ 	lh	$t6,0xa($s3)
/*  f181d04:	2401ffff */ 	addiu	$at,$zero,-1
/*  f181d08:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f181d0c:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f181d10:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f181d14:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f181d18:	11c1024d */ 	beq	$t6,$at,.L0f182650
/*  f181d1c:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f181d20:	866f0008 */ 	lh	$t7,0x8($s3)
/*  f181d24:	00003825 */ 	or	$a3,$zero,$zero
/*  f181d28:	3c013f80 */ 	lui	$at,0x3f80
/*  f181d2c:	11e00058 */ 	beqz	$t7,.L0f181e90
/*  f181d30:	00000000 */ 	nop
/*  f181d34:	44811000 */ 	mtc1	$at,$f2
/*  f181d38:	3c017f1c */ 	lui	$at,%hi(var7f1b893c)
/*  f181d3c:	c42c893c */ 	lwc1	$f12,%lo(var7f1b893c)($at)
/*  f181d40:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f181d44:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f181d48:	a6780004 */ 	sh	$t8,0x4($s3)
/*  f181d4c:	4600603e */ 	c.le.s	$f12,$f0
/*  f181d50:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f181d54:	e7a20164 */ 	swc1	$f2,0x164($sp)
/*  f181d58:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f181d5c:	45000047 */ 	bc1f	.L0f181e7c
/*  f181d60:	e7a2015c */ 	swc1	$f2,0x15c($sp)
/*  f181d64:	c6640034 */ 	lwc1	$f4,0x34($s3)
/*  f181d68:	4604603e */ 	c.le.s	$f12,$f4
/*  f181d6c:	00000000 */ 	nop
/*  f181d70:	45000042 */ 	bc1f	.L0f181e7c
/*  f181d74:	00000000 */ 	nop
/*  f181d78:	c6660038 */ 	lwc1	$f6,0x38($s3)
/*  f181d7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f181d80:	00003025 */ 	or	$a2,$zero,$zero
/*  f181d84:	4606603e */ 	c.le.s	$f12,$f6
/*  f181d88:	00003825 */ 	or	$a3,$zero,$zero
/*  f181d8c:	4500003b */ 	bc1f	.L0f181e7c
/*  f181d90:	00000000 */ 	nop
/*  f181d94:	8664000e */ 	lh	$a0,0xe($s3)
/*  f181d98:	0fc00b0a */ 	jal	roomSetLighting
/*  f181d9c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f181da0:	8679000c */ 	lh	$t9,0xc($s3)
/*  f181da4:	00002025 */ 	or	$a0,$zero,$zero
/*  f181da8:	2b210002 */ 	slti	$at,$t9,0x2
/*  f181dac:	54200013 */ 	bnezl	$at,.L0f181dfc
/*  f181db0:	a660000a */ 	sh	$zero,0xa($s3)
/*  f181db4:	8670000a */ 	lh	$s0,0xa($s3)
.L0f181db8:
/*  f181db8:	0c004b70 */ 	jal	random
/*  f181dbc:	00000000 */ 	nop
/*  f181dc0:	8668000c */ 	lh	$t0,0xc($s3)
/*  f181dc4:	0048001b */ 	divu	$zero,$v0,$t0
/*  f181dc8:	00004810 */ 	mfhi	$t1
/*  f181dcc:	a669000a */ 	sh	$t1,0xa($s3)
/*  f181dd0:	8663000a */ 	lh	$v1,0xa($s3)
/*  f181dd4:	15000002 */ 	bnez	$t0,.L0f181de0
/*  f181dd8:	00000000 */ 	nop
/*  f181ddc:	0007000d */ 	break	0x7
.L0f181de0:
/*  f181de0:	1203fff5 */ 	beq	$s0,$v1,.L0f181db8
/*  f181de4:	00000000 */ 	nop
/*  f181de8:	00035040 */ 	sll	$t2,$v1,0x1
/*  f181dec:	026a5821 */ 	addu	$t3,$s3,$t2
/*  f181df0:	10000002 */ 	b	.L0f181dfc
/*  f181df4:	85640012 */ 	lh	$a0,0x12($t3)
/*  f181df8:	a660000a */ 	sh	$zero,0xa($s3)
.L0f181dfc:
/*  f181dfc:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f181e00:	0fc456ac */ 	jal	padUnpack
/*  f181e04:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f181e08:	8fac00f0 */ 	lw	$t4,0xf0($sp)
/*  f181e0c:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
/*  f181e10:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f181e14:	c7b200b0 */ 	lwc1	$f18,0xb0($sp)
/*  f181e18:	240dffff */ 	addiu	$t5,$zero,-1
/*  f181e1c:	3c04800b */ 	lui	$a0,%hi(g_ScenarioData+0x24)
/*  f181e20:	3c05800b */ 	lui	$a1,%hi(g_ScenarioData+0xe)
/*  f181e24:	a66d0010 */ 	sh	$t5,0x10($s3)
/*  f181e28:	24a5c11e */ 	addiu	$a1,$a1,%lo(g_ScenarioData+0xe)
/*  f181e2c:	2484c134 */ 	addiu	$a0,$a0,%lo(g_ScenarioData+0x24)
/*  f181e30:	00003025 */ 	or	$a2,$zero,$zero
/*  f181e34:	00003825 */ 	or	$a3,$zero,$zero
/*  f181e38:	a66c000e */ 	sh	$t4,0xe($s3)
/*  f181e3c:	e6680024 */ 	swc1	$f8,0x24($s3)
/*  f181e40:	e66a0028 */ 	swc1	$f10,0x28($s3)
/*  f181e44:	0c00a8db */ 	jal	func0002a36c
/*  f181e48:	e672002c */ 	swc1	$f18,0x2c($s3)
/*  f181e4c:	e6600028 */ 	swc1	$f0,0x28($s3)
/*  f181e50:	8664000e */ 	lh	$a0,0xe($s3)
/*  f181e54:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f181e58:	00003025 */ 	or	$a2,$zero,$zero
/*  f181e5c:	00003825 */ 	or	$a3,$zero,$zero
/*  f181e60:	0fc00b0a */ 	jal	roomSetLighting
/*  f181e64:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f181e68:	240effff */ 	addiu	$t6,$zero,-1
/*  f181e6c:	a66e0004 */ 	sh	$t6,0x4($s3)
/*  f181e70:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f181e74:	a6600008 */ 	sh	$zero,0x8($s3)
/*  f181e78:	c6600030 */ 	lwc1	$f0,0x30($s3)
.L0f181e7c:
/*  f181e7c:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f181e80:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f181e84:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f181e88:	10000196 */ 	b	.L0f1824e4
/*  f181e8c:	c6700038 */ 	lwc1	$f16,0x38($s3)
.L0f181e90:
/*  f181e90:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f181e94:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f181e98:	8e83033c */ 	lw	$v1,0x33c($s4)
/*  f181e9c:	00003025 */ 	or	$a2,$zero,$zero
/*  f181ea0:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f181ea4:	1060001e */ 	beqz	$v1,.L0f181f20
/*  f181ea8:	24100006 */ 	addiu	$s0,$zero,0x6
/*  f181eac:	90620000 */ 	lbu	$v0,0x0($v1)
.L0f181eb0:
/*  f181eb0:	52020004 */ 	beql	$s0,$v0,.L0f181ec4
/*  f181eb4:	846f0028 */ 	lh	$t7,0x28($v1)
/*  f181eb8:	56420017 */ 	bnel	$s2,$v0,.L0f181f18
/*  f181ebc:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f181ec0:	846f0028 */ 	lh	$t7,0x28($v1)
.L0f181ec4:
/*  f181ec4:	8678000e */ 	lh	$t8,0xe($s3)
/*  f181ec8:	00008825 */ 	or	$s1,$zero,$zero
/*  f181ecc:	15f80002 */ 	bne	$t7,$t8,.L0f181ed8
/*  f181ed0:	00000000 */ 	nop
/*  f181ed4:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f181ed8:
/*  f181ed8:	5220000f */ 	beqzl	$s1,.L0f181f18
/*  f181edc:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f181ee0:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f181ee4:	afa70170 */ 	sw	$a3,0x170($sp)
/*  f181ee8:	afa60174 */ 	sw	$a2,0x174($sp)
/*  f181eec:	0fc0e6a5 */ 	jal	chrIsDead
/*  f181ef0:	afa30074 */ 	sw	$v1,0x74($sp)
/*  f181ef4:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f181ef8:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f181efc:	14400005 */ 	bnez	$v0,.L0f181f14
/*  f181f00:	8fa70170 */ 	lw	$a3,0x170($sp)
/*  f181f04:	0006c880 */ 	sll	$t9,$a2,0x2
/*  f181f08:	03b94021 */ 	addu	$t0,$sp,$t9
/*  f181f0c:	ad030078 */ 	sw	$v1,0x78($t0)
/*  f181f10:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f181f14:
/*  f181f14:	8c630020 */ 	lw	$v1,0x20($v1)
.L0f181f18:
/*  f181f18:	5460ffe5 */ 	bnezl	$v1,.L0f181eb0
/*  f181f1c:	90620000 */ 	lbu	$v0,0x0($v1)
.L0f181f20:
/*  f181f20:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f181f24:	27a3011c */ 	addiu	$v1,$sp,0x11c
.L0f181f28:
/*  f181f28:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f181f2c:	0043082b */ 	sltu	$at,$v0,$v1
/*  f181f30:	1420fffd */ 	bnez	$at,.L0f181f28
/*  f181f34:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f181f38:	00008025 */ 	or	$s0,$zero,$zero
/*  f181f3c:	18c00017 */ 	blez	$a2,.L0f181f9c
/*  f181f40:	00009025 */ 	or	$s2,$zero,$zero
/*  f181f44:	27a30078 */ 	addiu	$v1,$sp,0x78
/*  f181f48:	27b100fc */ 	addiu	$s1,$sp,0xfc
.L0f181f4c:
/*  f181f4c:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f181f50:	8d250004 */ 	lw	$a1,0x4($t1)
/*  f181f54:	90a40125 */ 	lbu	$a0,0x125($a1)
/*  f181f58:	afa70170 */ 	sw	$a3,0x170($sp)
/*  f181f5c:	afa60174 */ 	sw	$a2,0x174($sp)
/*  f181f60:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f181f64:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f181f68:	00025080 */ 	sll	$t2,$v0,0x2
/*  f181f6c:	022a2021 */ 	addu	$a0,$s1,$t2
/*  f181f70:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f181f74:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f181f78:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f181f7c:	15600004 */ 	bnez	$t3,.L0f181f90
/*  f181f80:	8fa70170 */ 	lw	$a3,0x170($sp)
/*  f181f84:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f181f88:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f181f8c:	ac8c0000 */ 	sw	$t4,0x0($a0)
.L0f181f90:
/*  f181f90:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f181f94:	1606ffed */ 	bne	$s0,$a2,.L0f181f4c
/*  f181f98:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f181f9c:
/*  f181f9c:	16400005 */ 	bnez	$s2,.L0f181fb4
/*  f181fa0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f181fa4:	240dffff */ 	addiu	$t5,$zero,-1
/*  f181fa8:	a66d0004 */ 	sh	$t5,0x4($s3)
/*  f181fac:	10000120 */ 	b	.L0f182430
/*  f181fb0:	a6600006 */ 	sh	$zero,0x6($s3)
.L0f181fb4:
/*  f181fb4:	1641000b */ 	bne	$s2,$at,.L0f181fe4
/*  f181fb8:	00008025 */ 	or	$s0,$zero,$zero
/*  f181fbc:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f181fc0:	24030008 */ 	addiu	$v1,$zero,0x8
.L0f181fc4:
/*  f181fc4:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f181fc8:	55c0003d */ 	bnezl	$t6,.L0f1820c0
/*  f181fcc:	866a0004 */ 	lh	$t2,0x4($s3)
/*  f181fd0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f181fd4:	1603fffb */ 	bne	$s0,$v1,.L0f181fc4
/*  f181fd8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f181fdc:	10000038 */ 	b	.L0f1820c0
/*  f181fe0:	866a0004 */ 	lh	$t2,0x4($s3)
.L0f181fe4:
/*  f181fe4:	00008825 */ 	or	$s1,$zero,$zero
/*  f181fe8:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f181fec:	27a4011c */ 	addiu	$a0,$sp,0x11c
/*  f181ff0:	8c430000 */ 	lw	$v1,0x0($v0)
.L0f181ff4:
/*  f181ff4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f181ff8:	0223082a */ 	slt	$at,$s1,$v1
/*  f181ffc:	50200003 */ 	beqzl	$at,.L0f18200c
/*  f182000:	0044082b */ 	sltu	$at,$v0,$a0
/*  f182004:	00608825 */ 	or	$s1,$v1,$zero
/*  f182008:	0044082b */ 	sltu	$at,$v0,$a0
.L0f18200c:
/*  f18200c:	5420fff9 */ 	bnezl	$at,.L0f181ff4
/*  f182010:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f182014:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182018:	27a3011c */ 	addiu	$v1,$sp,0x11c
/*  f18201c:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f182020:
/*  f182020:	522f0003 */ 	beql	$s1,$t7,.L0f182030
/*  f182024:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f182028:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f18202c:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f182030:
/*  f182030:	0043082b */ 	sltu	$at,$v0,$v1
/*  f182034:	5420fffa */ 	bnezl	$at,.L0f182020
/*  f182038:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f18203c:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182040:	27a3011c */ 	addiu	$v1,$sp,0x11c
/*  f182044:	8c580000 */ 	lw	$t8,0x0($v0)
.L0f182048:
/*  f182048:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18204c:	0043082b */ 	sltu	$at,$v0,$v1
/*  f182050:	13000002 */ 	beqz	$t8,.L0f18205c
/*  f182054:	00000000 */ 	nop
/*  f182058:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f18205c:
/*  f18205c:	5420fffa */ 	bnezl	$at,.L0f182048
/*  f182060:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f182064:	28e10002 */ 	slti	$at,$a3,0x2
/*  f182068:	14200003 */ 	bnez	$at,.L0f182078
/*  f18206c:	00008025 */ 	or	$s0,$zero,$zero
/*  f182070:	10000002 */ 	b	.L0f18207c
/*  f182074:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f182078:
/*  f182078:	00003825 */ 	or	$a3,$zero,$zero
.L0f18207c:
/*  f18207c:	27a200fc */ 	addiu	$v0,$sp,0xfc
.L0f182080:
/*  f182080:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f182084:	53200005 */ 	beqzl	$t9,.L0f18209c
/*  f182088:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18208c:	86680004 */ 	lh	$t0,0x4($s3)
/*  f182090:	52080006 */ 	beql	$s0,$t0,.L0f1820ac
/*  f182094:	24030008 */ 	addiu	$v1,$zero,0x8
/*  f182098:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f18209c:
/*  f18209c:	2a010008 */ 	slti	$at,$s0,0x8
/*  f1820a0:	1420fff7 */ 	bnez	$at,.L0f182080
/*  f1820a4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1820a8:	24030008 */ 	addiu	$v1,$zero,0x8
.L0f1820ac:
/*  f1820ac:	16030003 */ 	bne	$s0,$v1,.L0f1820bc
/*  f1820b0:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f1820b4:	a6690004 */ 	sh	$t1,0x4($s3)
/*  f1820b8:	2410ffff */ 	addiu	$s0,$zero,-1
.L0f1820bc:
/*  f1820bc:	866a0004 */ 	lh	$t2,0x4($s3)
.L0f1820c0:
/*  f1820c0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f1820c4:	240505b9 */ 	addiu	$a1,$zero,0x5b9
/*  f1820c8:	120a0070 */ 	beq	$s0,$t2,.L0f18228c
/*  f1820cc:	00003025 */ 	or	$a2,$zero,$zero
/*  f1820d0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1820d4:	44812000 */ 	mtc1	$at,$f4
/*  f1820d8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f1820dc:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1820e0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f1820e4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1820e8:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1820ec:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f1820f0:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f1820f4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f1820f8:	00008825 */ 	or	$s1,$zero,$zero
/*  f1820fc:	0c004241 */ 	jal	audioStart
/*  f182100:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f182104:	a6700004 */ 	sh	$s0,0x4($s3)
/*  f182108:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f18210c:	0fc5b9f1 */ 	jal	langGet
/*  f182110:	24045416 */ 	addiu	$a0,$zero,0x5416
/*  f182114:	00107080 */ 	sll	$t6,$s0,0x2
/*  f182118:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f18211c:	3c0f800b */ 	lui	$t7,%hi(g_MpSetup+0x28)
/*  f182120:	25efcbb0 */ 	addiu	$t7,$t7,%lo(g_MpSetup+0x28)
/*  f182124:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f182128:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f18212c:	27a4011c */ 	addiu	$a0,$sp,0x11c
/*  f182130:	0c004dad */ 	jal	sprintf
/*  f182134:	00402825 */ 	or	$a1,$v0,$zero
/*  f182138:	8e98006c */ 	lw	$t8,0x6c($s4)
/*  f18213c:	27b0011c */ 	addiu	$s0,$sp,0x11c
/*  f182140:	8e92028c */ 	lw	$s2,0x28c($s4)
/*  f182144:	13000003 */ 	beqz	$t8,.L0f182154
/*  f182148:	00002825 */ 	or	$a1,$zero,$zero
/*  f18214c:	10000001 */ 	b	.L0f182154
/*  f182150:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f182154:
/*  f182154:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f182158:	00002025 */ 	or	$a0,$zero,$zero
/*  f18215c:	00001825 */ 	or	$v1,$zero,$zero
/*  f182160:	13200003 */ 	beqz	$t9,.L0f182170
/*  f182164:	00001025 */ 	or	$v0,$zero,$zero
/*  f182168:	10000001 */ 	b	.L0f182170
/*  f18216c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f182170:
/*  f182170:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f182174:	11000003 */ 	beqz	$t0,.L0f182184
/*  f182178:	00000000 */ 	nop
/*  f18217c:	10000001 */ 	b	.L0f182184
/*  f182180:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f182184:
/*  f182184:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f182188:	11200003 */ 	beqz	$t1,.L0f182198
/*  f18218c:	00000000 */ 	nop
/*  f182190:	10000001 */ 	b	.L0f182198
/*  f182194:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f182198:
/*  f182198:	00435021 */ 	addu	$t2,$v0,$v1
/*  f18219c:	01445821 */ 	addu	$t3,$t2,$a0
/*  f1821a0:	01656021 */ 	addu	$t4,$t3,$a1
/*  f1821a4:	19800035 */ 	blez	$t4,.L0f18227c
/*  f1821a8:	00000000 */ 	nop
.L0f1821ac:
/*  f1821ac:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1821b0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1821b4:	8e8d0284 */ 	lw	$t5,0x284($s4)
/*  f1821b8:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f1821bc:	8dc50004 */ 	lw	$a1,0x4($t6)
/*  f1821c0:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f1821c4:	90a40125 */ 	lbu	$a0,0x125($a1)
/*  f1821c8:	866f0004 */ 	lh	$t7,0x4($s3)
/*  f1821cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1821d0:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1821d4:	144f0009 */ 	bne	$v0,$t7,.L0f1821fc
/*  f1821d8:	00000000 */ 	nop
/*  f1821dc:	0fc5b9f1 */ 	jal	langGet
/*  f1821e0:	24045415 */ 	addiu	$a0,$zero,0x5415
/*  f1821e4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1821e8:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1821ec:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f1821f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1821f4:	10000004 */ 	b	.L0f182208
/*  f1821f8:	8e98006c */ 	lw	$t8,0x6c($s4)
.L0f1821fc:
/*  f1821fc:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f182200:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f182204:	8e98006c */ 	lw	$t8,0x6c($s4)
.L0f182208:
/*  f182208:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18220c:	00002825 */ 	or	$a1,$zero,$zero
/*  f182210:	13000003 */ 	beqz	$t8,.L0f182220
/*  f182214:	00002025 */ 	or	$a0,$zero,$zero
/*  f182218:	10000001 */ 	b	.L0f182220
/*  f18221c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f182220:
/*  f182220:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f182224:	00001825 */ 	or	$v1,$zero,$zero
/*  f182228:	00001025 */ 	or	$v0,$zero,$zero
/*  f18222c:	13200003 */ 	beqz	$t9,.L0f18223c
/*  f182230:	00000000 */ 	nop
/*  f182234:	10000001 */ 	b	.L0f18223c
/*  f182238:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f18223c:
/*  f18223c:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f182240:	11000003 */ 	beqz	$t0,.L0f182250
/*  f182244:	00000000 */ 	nop
/*  f182248:	10000001 */ 	b	.L0f182250
/*  f18224c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f182250:
/*  f182250:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f182254:	11200003 */ 	beqz	$t1,.L0f182264
/*  f182258:	00000000 */ 	nop
/*  f18225c:	10000001 */ 	b	.L0f182264
/*  f182260:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f182264:
/*  f182264:	00435021 */ 	addu	$t2,$v0,$v1
/*  f182268:	01445821 */ 	addu	$t3,$t2,$a0
/*  f18226c:	01656021 */ 	addu	$t4,$t3,$a1
/*  f182270:	022c082a */ 	slt	$at,$s1,$t4
/*  f182274:	1420ffcd */ 	bnez	$at,.L0f1821ac
/*  f182278:	00000000 */ 	nop
.L0f18227c:
/*  f18227c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f182280:	02402025 */ 	or	$a0,$s2,$zero
/*  f182284:	1000006b */ 	b	.L0f182434
/*  f182288:	86630004 */ 	lh	$v1,0x4($s3)
.L0f18228c:
/*  f18228c:	54e00069 */ 	bnezl	$a3,.L0f182434
/*  f182290:	86630004 */ 	lh	$v1,0x4($s3)
/*  f182294:	866d0006 */ 	lh	$t5,0x6($s3)
/*  f182298:	8e8e0034 */ 	lw	$t6,0x34($s4)
/*  f18229c:	8e990484 */ 	lw	$t9,0x484($s4)
/*  f1822a0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f1822a4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f1822a8:	a66f0006 */ 	sh	$t7,0x6($s3)
/*  f1822ac:	00194100 */ 	sll	$t0,$t9,0x4
/*  f1822b0:	86780006 */ 	lh	$t8,0x6($s3)
/*  f1822b4:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1822b8:	00084100 */ 	sll	$t0,$t0,0x4
/*  f1822bc:	25090960 */ 	addiu	$t1,$t0,0x960
/*  f1822c0:	0309082a */ 	slt	$at,$t8,$t1
/*  f1822c4:	1420005a */ 	bnez	$at,.L0f182430
/*  f1822c8:	240505b8 */ 	addiu	$a1,$zero,0x5b8
/*  f1822cc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1822d0:	44813000 */ 	mtc1	$at,$f6
/*  f1822d4:	240affff */ 	addiu	$t2,$zero,-1
/*  f1822d8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f1822dc:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1822e0:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f1822e4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1822e8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1822ec:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f1822f0:	00003025 */ 	or	$a2,$zero,$zero
/*  f1822f4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f1822f8:	00009025 */ 	or	$s2,$zero,$zero
/*  f1822fc:	0c004241 */ 	jal	audioStart
/*  f182300:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f182304:	3c03800b */ 	lui	$v1,%hi(g_MpNumPlayers)
/*  f182308:	8c63c530 */ 	lw	$v1,%lo(g_MpNumPlayers)($v1)
/*  f18230c:	3c10800b */ 	lui	$s0,%hi(g_MpPlayerChrs)
/*  f182310:	2610c4d0 */ 	addiu	$s0,$s0,%lo(g_MpPlayerChrs)
/*  f182314:	1860001e */ 	blez	$v1,.L0f182390
/*  f182318:	00002825 */ 	or	$a1,$zero,$zero
/*  f18231c:	3c11800b */ 	lui	$s1,%hi(var800ac500)
/*  f182320:	2631c500 */ 	addiu	$s1,$s1,%lo(var800ac500)
.L0f182324:
/*  f182324:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f182328:	91a40125 */ 	lbu	$a0,0x125($t5)
/*  f18232c:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f182330:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f182334:	866e0004 */ 	lh	$t6,0x4($s3)
/*  f182338:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f18233c:	144e000c */ 	bne	$v0,$t6,.L0f182370
/*  f182340:	00000000 */ 	nop
/*  f182344:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f182348:	8668000e */ 	lh	$t0,0xe($s3)
/*  f18234c:	0225c021 */ 	addu	$t8,$s1,$a1
/*  f182350:	8de3001c */ 	lw	$v1,0x1c($t7)
/*  f182354:	84790028 */ 	lh	$t9,0x28($v1)
/*  f182358:	17280005 */ 	bne	$t9,$t0,.L0f182370
/*  f18235c:	00000000 */ 	nop
/*  f182360:	8f020000 */ 	lw	$v0,0x0($t8)
/*  f182364:	8449003e */ 	lh	$t1,0x3e($v0)
/*  f182368:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f18236c:	a44a003e */ 	sh	$t2,0x3e($v0)
.L0f182370:
/*  f182370:	3c03800b */ 	lui	$v1,%hi(g_MpNumPlayers)
/*  f182374:	8c63c530 */ 	lw	$v1,%lo(g_MpNumPlayers)($v1)
/*  f182378:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f18237c:	24a50004 */ 	addiu	$a1,$a1,0x0004
/*  f182380:	0243082a */ 	slt	$at,$s2,$v1
/*  f182384:	1420ffe7 */ 	bnez	$at,.L0f182324
/*  f182388:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f18238c:	00009025 */ 	or	$s2,$zero,$zero
.L0f182390:
/*  f182390:	1860001b */ 	blez	$v1,.L0f182400
/*  f182394:	8e91028c */ 	lw	$s1,0x28c($s4)
/*  f182398:	3c10800b */ 	lui	$s0,%hi(g_MpPlayerChrs)
/*  f18239c:	2610c4d0 */ 	addiu	$s0,$s0,%lo(g_MpPlayerChrs)
/*  f1823a0:	8e020000 */ 	lw	$v0,0x0($s0)
.L0f1823a4:
/*  f1823a4:	8c4b02d4 */ 	lw	$t3,0x2d4($v0)
/*  f1823a8:	1560000e */ 	bnez	$t3,.L0f1823e4
/*  f1823ac:	00000000 */ 	nop
/*  f1823b0:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f1823b4:	90440125 */ 	lbu	$a0,0x125($v0)
/*  f1823b8:	866c0004 */ 	lh	$t4,0x4($s3)
/*  f1823bc:	144c0009 */ 	bne	$v0,$t4,.L0f1823e4
/*  f1823c0:	00000000 */ 	nop
/*  f1823c4:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1823c8:	02402025 */ 	or	$a0,$s2,$zero
/*  f1823cc:	0fc5b9f1 */ 	jal	langGet
/*  f1823d0:	24045414 */ 	addiu	$a0,$zero,0x5414
/*  f1823d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1823d8:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1823dc:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f1823e0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1823e4:
/*  f1823e4:	3c0d800b */ 	lui	$t5,%hi(g_MpNumPlayers)
/*  f1823e8:	8dadc530 */ 	lw	$t5,%lo(g_MpNumPlayers)($t5)
/*  f1823ec:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1823f0:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f1823f4:	024d082a */ 	slt	$at,$s2,$t5
/*  f1823f8:	5420ffea */ 	bnezl	$at,.L0f1823a4
/*  f1823fc:	8e020000 */ 	lw	$v0,0x0($s0)
.L0f182400:
/*  f182400:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f182404:	02202025 */ 	or	$a0,$s1,$zero
/*  f182408:	240effff */ 	addiu	$t6,$zero,-1
/*  f18240c:	a66e0004 */ 	sh	$t6,0x4($s3)
/*  f182410:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f182414:	3c0f800b */ 	lui	$t7,%hi(g_MpSetup+0xc)
/*  f182418:	8defcb94 */ 	lw	$t7,%lo(g_MpSetup+0xc)($t7)
/*  f18241c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f182420:	31f98000 */ 	andi	$t9,$t7,0x8000
/*  f182424:	53200003 */ 	beqzl	$t9,.L0f182434
/*  f182428:	86630004 */ 	lh	$v1,0x4($s3)
/*  f18242c:	a6680008 */ 	sh	$t0,0x8($s3)
.L0f182430:
/*  f182430:	86630004 */ 	lh	$v1,0x4($s3)
.L0f182434:
/*  f182434:	2401ffff */ 	addiu	$at,$zero,-1
/*  f182438:	3c028008 */ 	lui	$v0,%hi(g_TeamColours)
/*  f18243c:	1461000c */ 	bne	$v1,$at,.L0f182470
/*  f182440:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f182444:	3c013f80 */ 	lui	$at,0x3f80
/*  f182448:	44811000 */ 	mtc1	$at,$f2
/*  f18244c:	3c013e80 */ 	lui	$at,0x3e80
/*  f182450:	44817000 */ 	mtc1	$at,$f14
/*  f182454:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f182458:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f18245c:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f182460:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f182464:	e7ae0164 */ 	swc1	$f14,0x164($sp)
/*  f182468:	1000001e */ 	b	.L0f1824e4
/*  f18246c:	e7ae015c */ 	swc1	$f14,0x15c($sp)
.L0f182470:
/*  f182470:	00581021 */ 	addu	$v0,$v0,$t8
/*  f182474:	8c427cc4 */ 	lw	$v0,%lo(g_TeamColours)($v0)
/*  f182478:	3c013b00 */ 	lui	$at,0x3b00
/*  f18247c:	44811000 */ 	mtc1	$at,$f2
/*  f182480:	00024e02 */ 	srl	$t1,$v0,0x18
/*  f182484:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f182488:	254b00ff */ 	addiu	$t3,$t2,0xff
/*  f18248c:	448b4000 */ 	mtc1	$t3,$f8
/*  f182490:	00026402 */ 	srl	$t4,$v0,0x10
/*  f182494:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f182498:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f18249c:	25ae00ff */ 	addiu	$t6,$t5,0xff
/*  f1824a0:	448e2000 */ 	mtc1	$t6,$f4
/*  f1824a4:	00027a02 */ 	srl	$t7,$v0,0x8
/*  f1824a8:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f1824ac:	272800ff */ 	addiu	$t0,$t9,0xff
/*  f1824b0:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f1824b4:	44885000 */ 	mtc1	$t0,$f10
/*  f1824b8:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f1824bc:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f1824c0:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f1824c4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1824c8:	e7b20164 */ 	swc1	$f18,0x164($sp)
/*  f1824cc:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f1824d0:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f1824d4:	00000000 */ 	nop
/*  f1824d8:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f1824dc:	e7a80160 */ 	swc1	$f8,0x160($sp)
/*  f1824e0:	e7a4015c */ 	swc1	$f4,0x15c($sp)
.L0f1824e4:
/*  f1824e4:	c7a60164 */ 	lwc1	$f6,0x164($sp)
/*  f1824e8:	46003032 */ 	c.eq.s	$f6,$f0
/*  f1824ec:	00000000 */ 	nop
/*  f1824f0:	4503001c */ 	bc1tl	.L0f182564
/*  f1824f4:	c7a80160 */ 	lwc1	$f8,0x160($sp)
/*  f1824f8:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f1824fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f182500:	3c017f1c */ 	lui	$at,%hi(var7f1b8940)
/*  f182504:	58600017 */ 	blezl	$v1,.L0f182564
/*  f182508:	c7a80160 */ 	lwc1	$f8,0x160($sp)
/*  f18250c:	c4288940 */ 	lwc1	$f8,%lo(var7f1b8940)($at)
/*  f182510:	3c017f1c */ 	lui	$at,%hi(var7f1b8944)
/*  f182514:	c4208944 */ 	lwc1	$f0,%lo(var7f1b8944)($at)
/*  f182518:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f18251c:	00000000 */ 	nop
/*  f182520:	c66e0030 */ 	lwc1	$f14,0x30($s3)
/*  f182524:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182528:	0043082a */ 	slt	$at,$v0,$v1
/*  f18252c:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f182530:	5020000a */ 	beqzl	$at,.L0f18255c
/*  f182534:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f182538:	46121380 */ 	add.s	$f14,$f2,$f18
.L0f18253c:
/*  f18253c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182540:	0043082a */ 	slt	$at,$v0,$v1
/*  f182544:	e66e0030 */ 	swc1	$f14,0x30($s3)
/*  f182548:	c66e0030 */ 	lwc1	$f14,0x30($s3)
/*  f18254c:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f182550:	5420fffa */ 	bnezl	$at,.L0f18253c
/*  f182554:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f182558:	46121380 */ 	add.s	$f14,$f2,$f18
.L0f18255c:
/*  f18255c:	e66e0030 */ 	swc1	$f14,0x30($s3)
/*  f182560:	c7a80160 */ 	lwc1	$f8,0x160($sp)
.L0f182564:
/*  f182564:	3c017f1c */ 	lui	$at,%hi(var7f1b8948)
/*  f182568:	c4208948 */ 	lwc1	$f0,%lo(var7f1b8948)($at)
/*  f18256c:	460c4032 */ 	c.eq.s	$f8,$f12
/*  f182570:	00000000 */ 	nop
/*  f182574:	4503001a */ 	bc1tl	.L0f1825e0
/*  f182578:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f18257c:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f182580:	00001025 */ 	or	$v0,$zero,$zero
/*  f182584:	3c017f1c */ 	lui	$at,%hi(var7f1b894c)
/*  f182588:	58600015 */ 	blezl	$v1,.L0f1825e0
/*  f18258c:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f182590:	c426894c */ 	lwc1	$f6,%lo(var7f1b894c)($at)
/*  f182594:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f182598:	00000000 */ 	nop
/*  f18259c:	c66e0034 */ 	lwc1	$f14,0x34($s3)
/*  f1825a0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1825a4:	0043082a */ 	slt	$at,$v0,$v1
/*  f1825a8:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f1825ac:	5020000a */ 	beqzl	$at,.L0f1825d8
/*  f1825b0:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f1825b4:	46121380 */ 	add.s	$f14,$f2,$f18
.L0f1825b8:
/*  f1825b8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1825bc:	0043082a */ 	slt	$at,$v0,$v1
/*  f1825c0:	e66e0034 */ 	swc1	$f14,0x34($s3)
/*  f1825c4:	c66e0034 */ 	lwc1	$f14,0x34($s3)
/*  f1825c8:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f1825cc:	5420fffa */ 	bnezl	$at,.L0f1825b8
/*  f1825d0:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f1825d4:	46121380 */ 	add.s	$f14,$f2,$f18
.L0f1825d8:
/*  f1825d8:	e66e0034 */ 	swc1	$f14,0x34($s3)
/*  f1825dc:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
.L0f1825e0:
/*  f1825e0:	46103032 */ 	c.eq.s	$f6,$f16
/*  f1825e4:	00000000 */ 	nop
/*  f1825e8:	4503001a */ 	bc1tl	.L0f182654
/*  f1825ec:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1825f0:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f1825f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1825f8:	3c017f1c */ 	lui	$at,%hi(var7f1b8950)
/*  f1825fc:	58600015 */ 	blezl	$v1,.L0f182654
/*  f182600:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f182604:	c4288950 */ 	lwc1	$f8,%lo(var7f1b8950)($at)
/*  f182608:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f18260c:	00000000 */ 	nop
/*  f182610:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f182614:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182618:	0043082a */ 	slt	$at,$v0,$v1
/*  f18261c:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f182620:	5020000a */ 	beqzl	$at,.L0f18264c
/*  f182624:	46121400 */ 	add.s	$f16,$f2,$f18
/*  f182628:	46121400 */ 	add.s	$f16,$f2,$f18
.L0f18262c:
/*  f18262c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182630:	0043082a */ 	slt	$at,$v0,$v1
/*  f182634:	e6700038 */ 	swc1	$f16,0x38($s3)
/*  f182638:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f18263c:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f182640:	5420fffa */ 	bnezl	$at,.L0f18262c
/*  f182644:	46121400 */ 	add.s	$f16,$f2,$f18
/*  f182648:	46121400 */ 	add.s	$f16,$f2,$f18
.L0f18264c:
/*  f18264c:	e6700038 */ 	swc1	$f16,0x38($s3)
.L0f182650:
/*  f182650:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f182654:
/*  f182654:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f182658:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f18265c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f182660:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f182664:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f182668:	03e00008 */ 	jr	$ra
/*  f18266c:	27bd0188 */ 	addiu	$sp,$sp,0x188
);

GLOBAL_ASM(
glabel scenarioKohCallback18
/*  f182670:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f182674:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f182678:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f18267c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f182680:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f182684:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f182688:	00808025 */ 	or	$s0,$a0,$zero
/*  f18268c:	8de20004 */ 	lw	$v0,0x4($t7)
/*  f182690:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f182694:	90440125 */ 	lbu	$a0,0x125($v0)
/*  f182698:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f18269c:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f1826a0:	84780004 */ 	lh	$t8,0x4($v1)
/*  f1826a4:	54580094 */ 	bnel	$v0,$t8,.L0f1828f8
/*  f1826a8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1826ac:	84790008 */ 	lh	$t9,0x8($v1)
/*  f1826b0:	57200091 */ 	bnezl	$t9,.L0f1828f8
/*  f1826b4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1826b8:	0c002f40 */ 	jal	viGetViewLeft
/*  f1826bc:	00000000 */ 	nop
/*  f1826c0:	0c002f22 */ 	jal	viGetViewWidth
/*  f1826c4:	a7a2004e */ 	sh	$v0,0x4e($sp)
/*  f1826c8:	87aa004e */ 	lh	$t2,0x4e($sp)
/*  f1826cc:	04410003 */ 	bgez	$v0,.L0f1826dc
/*  f1826d0:	00024843 */ 	sra	$t1,$v0,0x1
/*  f1826d4:	24410001 */ 	addiu	$at,$v0,0x1
/*  f1826d8:	00014843 */ 	sra	$t1,$at,0x1
.L0f1826dc:
/*  f1826dc:	012a2821 */ 	addu	$a1,$t1,$t2
/*  f1826e0:	0c002f44 */ 	jal	viGetViewTop
/*  f1826e4:	afa50098 */ 	sw	$a1,0x98($sp)
/*  f1826e8:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x484)
/*  f1826ec:	8c84a444 */ 	lw	$a0,%lo(g_Vars+0x484)($a0)
/*  f1826f0:	240800f0 */ 	addiu	$t0,$zero,0xf0
/*  f1826f4:	3c0d800b */ 	lui	$t5,%hi(g_ScenarioData+0x6)
/*  f1826f8:	00880019 */ 	multu	$a0,$t0
/*  f1826fc:	85adc116 */ 	lh	$t5,%lo(g_ScenarioData+0x6)($t5)
/*  f182700:	24073840 */ 	addiu	$a3,$zero,0x3840
/*  f182704:	00047900 */ 	sll	$t7,$a0,0x4
/*  f182708:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f18270c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f182710:	25f80258 */ 	addiu	$t8,$t7,0x258
/*  f182714:	244b000a */ 	addiu	$t3,$v0,0xa
/*  f182718:	afab0094 */ 	sw	$t3,0x94($sp)
/*  f18271c:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f182720:	00006012 */ 	mflo	$t4
/*  f182724:	018d1823 */ 	subu	$v1,$t4,$t5
/*  f182728:	24630960 */ 	addiu	$v1,$v1,0x960
/*  f18272c:	0067001a */ 	div	$zero,$v1,$a3
/*  f182730:	00002812 */ 	mflo	$a1
/*  f182734:	00a03025 */ 	or	$a2,$a1,$zero
/*  f182738:	14e00002 */ 	bnez	$a3,.L0f182744
/*  f18273c:	00000000 */ 	nop
/*  f182740:	0007000d */ 	break	0x7
.L0f182744:
/*  f182744:	2401ffff */ 	addiu	$at,$zero,-1
/*  f182748:	14e10004 */ 	bne	$a3,$at,.L0f18275c
/*  f18274c:	3c018000 */ 	lui	$at,0x8000
/*  f182750:	14610002 */ 	bne	$v1,$at,.L0f18275c
/*  f182754:	00000000 */ 	nop
/*  f182758:	0006000d */ 	break	0x6
.L0f18275c:
/*  f18275c:	00a70019 */ 	multu	$a1,$a3
/*  f182760:	24010e10 */ 	addiu	$at,$zero,0xe10
/*  f182764:	3c057f1c */ 	lui	$a1,%hi(var7f1b84a0)
/*  f182768:	00007012 */ 	mflo	$t6
/*  f18276c:	006e1823 */ 	subu	$v1,$v1,$t6
/*  f182770:	00000000 */ 	nop
/*  f182774:	0301001a */ 	div	$zero,$t8,$at
/*  f182778:	0000c812 */ 	mflo	$t9
/*  f18277c:	53200015 */ 	beqzl	$t9,.L0f1827d4
/*  f182780:	246a00ef */ 	addiu	$t2,$v1,0xef
/*  f182784:	246900ef */ 	addiu	$t1,$v1,0xef
/*  f182788:	0128001a */ 	div	$zero,$t1,$t0
/*  f18278c:	00003812 */ 	mflo	$a3
/*  f182790:	3c057f1c */ 	lui	$a1,%hi(var7f1b8498)
/*  f182794:	24a58498 */ 	addiu	$a1,$a1,%lo(var7f1b8498)
/*  f182798:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f18279c:	15000002 */ 	bnez	$t0,.L0f1827a8
/*  f1827a0:	00000000 */ 	nop
/*  f1827a4:	0007000d */ 	break	0x7
.L0f1827a8:
/*  f1827a8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1827ac:	15010004 */ 	bne	$t0,$at,.L0f1827c0
/*  f1827b0:	3c018000 */ 	lui	$at,0x8000
/*  f1827b4:	15210002 */ 	bne	$t1,$at,.L0f1827c0
/*  f1827b8:	00000000 */ 	nop
/*  f1827bc:	0006000d */ 	break	0x6
.L0f1827c0:
/*  f1827c0:	0c004dad */ 	jal	sprintf
/*  f1827c4:	00000000 */ 	nop
/*  f1827c8:	10000010 */ 	b	.L0f18280c
/*  f1827cc:	00000000 */ 	nop
/*  f1827d0:	246a00ef */ 	addiu	$t2,$v1,0xef
.L0f1827d4:
/*  f1827d4:	0148001a */ 	div	$zero,$t2,$t0
/*  f1827d8:	00003012 */ 	mflo	$a2
/*  f1827dc:	24a584a0 */ 	addiu	$a1,$a1,%lo(var7f1b84a0)
/*  f1827e0:	15000002 */ 	bnez	$t0,.L0f1827ec
/*  f1827e4:	00000000 */ 	nop
/*  f1827e8:	0007000d */ 	break	0x7
.L0f1827ec:
/*  f1827ec:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1827f0:	15010004 */ 	bne	$t0,$at,.L0f182804
/*  f1827f4:	3c018000 */ 	lui	$at,0x8000
/*  f1827f8:	15410002 */ 	bne	$t2,$at,.L0f182804
/*  f1827fc:	00000000 */ 	nop
/*  f182800:	0006000d */ 	break	0x6
.L0f182804:
/*  f182804:	0c004dad */ 	jal	sprintf
/*  f182808:	00000000 */ 	nop
.L0f18280c:
/*  f18280c:	0fc54d8a */ 	jal	func0f153628
/*  f182810:	02002025 */ 	or	$a0,$s0,$zero
/*  f182814:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicXs2)
/*  f182818:	8d6bfb04 */ 	lw	$t3,%lo(g_FontHandelGothicXs2)($t3)
/*  f18281c:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicXs1)
/*  f182820:	00408025 */ 	or	$s0,$v0,$zero
/*  f182824:	8ce7fb08 */ 	lw	$a3,%lo(g_FontHandelGothicXs1)($a3)
/*  f182828:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f18282c:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f182830:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f182834:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f182838:	0fc55cbe */ 	jal	textMeasure
/*  f18283c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f182840:	8fa700a0 */ 	lw	$a3,0xa0($sp)
/*  f182844:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f182848:	8fa2009c */ 	lw	$v0,0x9c($sp)
/*  f18284c:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f182850:	04e10003 */ 	bgez	$a3,.L0f182860
/*  f182854:	00076043 */ 	sra	$t4,$a3,0x1
/*  f182858:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f18285c:	00016043 */ 	sra	$t4,$at,0x1
.L0f182860:
/*  f182860:	00ac2823 */ 	subu	$a1,$a1,$t4
/*  f182864:	00e53821 */ 	addu	$a3,$a3,$a1
/*  f182868:	00461021 */ 	addu	$v0,$v0,$a2
/*  f18286c:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f182870:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f182874:	afa700a0 */ 	sw	$a3,0xa0($sp)
/*  f182878:	afa50098 */ 	sw	$a1,0x98($sp)
/*  f18287c:	0fc54e64 */ 	jal	func0f153990
/*  f182880:	02002025 */ 	or	$a0,$s0,$zero
/*  f182884:	0c002f02 */ 	jal	viGetX
/*  f182888:	00408025 */ 	or	$s0,$v0,$zero
/*  f18288c:	0c002f06 */ 	jal	viGetY
/*  f182890:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f182894:	3c0d8008 */ 	lui	$t5,%hi(g_FontNumeric1)
/*  f182898:	3c0e8008 */ 	lui	$t6,%hi(g_FontNumeric2)
/*  f18289c:	8dcefafc */ 	lw	$t6,%lo(g_FontNumeric2)($t6)
/*  f1828a0:	8dadfb00 */ 	lw	$t5,%lo(g_FontNumeric1)($t5)
/*  f1828a4:	87b9004c */ 	lh	$t9,0x4c($sp)
/*  f1828a8:	3c0f00ff */ 	lui	$t7,0xff
/*  f1828ac:	35ef00a0 */ 	ori	$t7,$t7,0xa0
/*  f1828b0:	241800a0 */ 	addiu	$t8,$zero,0xa0
/*  f1828b4:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1828b8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f1828bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1828c0:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f1828c4:	27a60094 */ 	addiu	$a2,$sp,0x94
/*  f1828c8:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f1828cc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1828d0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1828d4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1828d8:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1828dc:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1828e0:	0fc55b92 */ 	jal	textRender
/*  f1828e4:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f1828e8:	0fc54de0 */ 	jal	func0f153780
/*  f1828ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f1828f0:	00408025 */ 	or	$s0,$v0,$zero
/*  f1828f4:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1828f8:
/*  f1828f8:	02001025 */ 	or	$v0,$s0,$zero
/*  f1828fc:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f182900:	03e00008 */ 	jr	$ra
/*  f182904:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

void scenarioKohKill(struct mpchr *mpchr, s32 mpchrnum, s32 *score, s32 *arg3)
{
	struct mpchr *loopmpchr;
	s32 i;

	*score = 0;
	*score = mpchr->unk3e;

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == mpchrnum) {
				*score -= mpchr->killcounts[i];
			} else {
				if (i < 4) {
					loopmpchr = &g_MpPlayers[i].base;
				} else {
					loopmpchr = &g_MpSimulants[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			}
		}
	}

	*arg3 = mpchr->numdeaths;
}

Gfx *scenarioKohRadar(Gfx *gdl)
{
	if (g_MpSetup.options & MPOPTION_KOH_HILLONRADAR && g_ScenarioData.koh.unk08 == 0) {
		struct coord dist;
		u32 colour;
		dist.x = g_ScenarioData.koh.hillpos.x - g_Vars.currentplayer->prop->pos.x;
		dist.y = g_ScenarioData.koh.hillpos.y - g_Vars.currentplayer->prop->pos.y;
		dist.z = g_ScenarioData.koh.hillpos.z - g_Vars.currentplayer->prop->pos.z;

		if (g_ScenarioData.koh.occupiedteam == -1) {
			colour = 0xff0000;
		} else {
			colour = g_TeamColours[g_ScenarioData.koh.occupiedteam];
		}

		gdl = radarDrawDot(gdl, NULL, &dist, colour, 0, 1);
	}

	return gdl;
}

GLOBAL_ASM(
glabel func0f182aac
/*  f182aac:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f182ab0:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f182ab4:	8462000c */ 	lh	$v0,0xc($v1)
/*  f182ab8:	28410009 */ 	slti	$at,$v0,0x9
/*  f182abc:	10200008 */ 	beqz	$at,.L0f182ae0
/*  f182ac0:	00000000 */ 	nop
/*  f182ac4:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f182ac8:	00027840 */ 	sll	$t7,$v0,0x1
/*  f182acc:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f182ad0:	a70e0012 */ 	sh	$t6,0x12($t8)
/*  f182ad4:	8479000c */ 	lh	$t9,0xc($v1)
/*  f182ad8:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f182adc:	a468000c */ 	sh	$t0,0xc($v1)
.L0f182ae0:
/*  f182ae0:	03e00008 */ 	jr	$ra
/*  f182ae4:	00000000 */ 	nop
);

bool scenarioKohIsRoomHighlighted(s16 room)
{
	return room == g_ScenarioData.koh.hillroom;
}

GLOBAL_ASM(
glabel scenarioKohCallback38
/*  f182b08:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f182b0c:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f182b10:	8458000e */ 	lh	$t8,0xe($v0)
/*  f182b14:	00047400 */ 	sll	$t6,$a0,0x10
/*  f182b18:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f182b1c:	15f8001a */ 	bne	$t7,$t8,.L0f182b88
/*  f182b20:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f182b24:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f182b28:	8cc80000 */ 	lw	$t0,0x0($a2)
/*  f182b2c:	8ce90000 */ 	lw	$t1,0x0($a3)
/*  f182b30:	44992000 */ 	mtc1	$t9,$f4
/*  f182b34:	44883000 */ 	mtc1	$t0,$f6
/*  f182b38:	c44a0030 */ 	lwc1	$f10,0x30($v0)
/*  f182b3c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f182b40:	44894000 */ 	mtc1	$t1,$f8
/*  f182b44:	c4500034 */ 	lwc1	$f16,0x34($v0)
/*  f182b48:	c4520038 */ 	lwc1	$f18,0x38($v0)
/*  f182b4c:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f182b50:	460a0002 */ 	mul.s	$f0,$f0,$f10
/*  f182b54:	00000000 */ 	nop
/*  f182b58:	46101082 */ 	mul.s	$f2,$f2,$f16
/*  f182b5c:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f182b60:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f182b64:	46126302 */ 	mul.s	$f12,$f12,$f18
/*  f182b68:	440b2000 */ 	mfc1	$t3,$f4
/*  f182b6c:	4600118d */ 	trunc.w.s	$f6,$f2
/*  f182b70:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f182b74:	4600620d */ 	trunc.w.s	$f8,$f12
/*  f182b78:	440d3000 */ 	mfc1	$t5,$f6
/*  f182b7c:	440f4000 */ 	mfc1	$t7,$f8
/*  f182b80:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f182b84:	acef0000 */ 	sw	$t7,0x0($a3)
.L0f182b88:
/*  f182b88:	03e00008 */ 	jr	$ra
/*  f182b8c:	00000000 */ 	nop
);

void scenarioHtmInit(void)
{
	g_ScenarioData.htm.uplink = NULL;
}

s32 scenarioHtmCallback08(void)
{
	return 2;
}

//GLOBAL_ASM(
//glabel mpHtmAddPad
///*  f182ba4:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
///*  f182ba8:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
///*  f182bac:	84580000 */ 	lh	$t8,0x0($v0)
///*  f182bb0:	00047400 */ 	sll	$t6,$a0,0x10
///*  f182bb4:	000e7c03 */ 	sra	$t7,$t6,0x10
///*  f182bb8:	2b01003c */ 	slti	$at,$t8,0x3c
///*  f182bbc:	1020000b */ 	beqz	$at,.L0f182bec
///*  f182bc0:	afa40000 */ 	sw	$a0,0x0($sp)
///*  f182bc4:	3c19800b */ 	lui	$t9,%hi(g_ScenarioData)
///*  f182bc8:	8739c110 */ 	lh	$t9,%lo(g_ScenarioData)($t9)
///*  f182bcc:	3c0a800b */ 	lui	$t2,%hi(g_ScenarioData)
///*  f182bd0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
///*  f182bd4:	00194040 */ 	sll	$t0,$t9,0x1
///*  f182bd8:	00484821 */ 	addu	$t1,$v0,$t0
///*  f182bdc:	a52f0004 */ 	sh	$t7,0x4($t1)
///*  f182be0:	854ac110 */ 	lh	$t2,%lo(g_ScenarioData)($t2)
///*  f182be4:	254b0001 */ 	addiu	$t3,$t2,0x1
///*  f182be8:	a42bc110 */ 	sh	$t3,%lo(g_ScenarioData)($at)
//.L0f182bec:
///*  f182bec:	03e00008 */ 	jr	$ra
///*  f182bf0:	00000000 */ 	nop
//);

void mpHtmAddPad(s16 padnum)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;

	if (data->nextindex < 60) {
		data->padnums[data->nextindex] = padnum;
		data->nextindex++;
	}
}

void func0f182bf4(void)
{
	s32 i;

	g_ScenarioData.htm.nextindex = 0;
	g_ScenarioData.htm.unk002 = 0;
	g_ScenarioData.htm.unk138 = 0;
	g_ScenarioData.htm.unk0d0 = -1;
	g_ScenarioData.htm.unk0d2 = -1;
	g_ScenarioData.htm.unk0d4 = -1;
	g_ScenarioData.htm.unk140 = 0;

	for (i = 0; i < ARRAYCOUNT(g_ScenarioData.htm.unk0d8); i++) {
		g_ScenarioData.htm.unk0d8[i] = 0;
		g_ScenarioData.htm.unk108[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_ScenarioData.htm.padnums); i++) {
		g_ScenarioData.htm.padnums[i] = -1;
	}

	for (i = 0; i < 1; i++) {
		g_ScenarioData.htm.unk07c[i].unk00 = 0;
		g_ScenarioData.htm.unk07c[i].prop = NULL;
		g_ScenarioData.htm.unk07c[i].unk08 = -1;
		g_ScenarioData.htm.unk07c[i].unk0a = 0xff;
		g_ScenarioData.htm.unk07c[i].unk0b = 0xff;
	}
}

GLOBAL_ASM(
glabel func0f182c98
/*  f182c98:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f182c9c:	3c0f8008 */ 	lui	$t7,%hi(var80086e14)
/*  f182ca0:	25ef6e14 */ 	addiu	$t7,$t7,%lo(var80086e14)
/*  f182ca4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f182ca8:	25e80060 */ 	addiu	$t0,$t7,0x60
/*  f182cac:	27ae0080 */ 	addiu	$t6,$sp,0x80
.L0f182cb0:
/*  f182cb0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f182cb4:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f182cb8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f182cbc:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f182cc0:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f182cc4:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f182cc8:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f182ccc:	15e8fff8 */ 	bne	$t7,$t0,.L0f182cb0
/*  f182cd0:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f182cd4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f182cd8:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f182cdc:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x33c)
/*  f182ce0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f182ce4:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f182ce8:	8c42a2fc */ 	lw	$v0,%lo(g_Vars+0x33c)($v0)
/*  f182cec:	00002025 */ 	or	$a0,$zero,$zero
/*  f182cf0:	27a70020 */ 	addiu	$a3,$sp,0x20
/*  f182cf4:	10400013 */ 	beqz	$v0,.L0f182d44
/*  f182cf8:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f182cfc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f182d00:	90490000 */ 	lbu	$t1,0x0($v0)
.L0f182d04:
/*  f182d04:	54a9000a */ 	bnel	$a1,$t1,.L0f182d30
/*  f182d08:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f182d0c:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f182d10:	00045880 */ 	sll	$t3,$a0,0x2
/*  f182d14:	00eb6021 */ 	addu	$t4,$a3,$t3
/*  f182d18:	906a0003 */ 	lbu	$t2,0x3($v1)
/*  f182d1c:	54ca0004 */ 	bnel	$a2,$t2,.L0f182d30
/*  f182d20:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f182d24:	ad830000 */ 	sw	$v1,0x0($t4)
/*  f182d28:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f182d2c:	8c420020 */ 	lw	$v0,0x20($v0)
.L0f182d30:
/*  f182d30:	28810014 */ 	slti	$at,$a0,0x14
/*  f182d34:	10400003 */ 	beqz	$v0,.L0f182d44
/*  f182d38:	00000000 */ 	nop
/*  f182d3c:	5420fff1 */ 	bnezl	$at,.L0f182d04
/*  f182d40:	90490000 */ 	lbu	$t1,0x0($v0)
.L0f182d44:
/*  f182d44:	1880001a */ 	blez	$a0,.L0f182db0
/*  f182d48:	00000000 */ 	nop
/*  f182d4c:	0c004b70 */ 	jal	random
/*  f182d50:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f182d54:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f182d58:	27a70020 */ 	addiu	$a3,$sp,0x20
/*  f182d5c:	3c058008 */ 	lui	$a1,%hi(var800869ec)
/*  f182d60:	0044001b */ 	divu	$zero,$v0,$a0
/*  f182d64:	24a569ec */ 	addiu	$a1,$a1,%lo(var800869ec)
/*  f182d68:	14800002 */ 	bnez	$a0,.L0f182d74
/*  f182d6c:	00000000 */ 	nop
/*  f182d70:	0007000d */ 	break	0x7
.L0f182d74:
/*  f182d74:	00002010 */ 	mfhi	$a0
/*  f182d78:	00046880 */ 	sll	$t5,$a0,0x2
/*  f182d7c:	00edc821 */ 	addu	$t9,$a3,$t5
/*  f182d80:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f182d84:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f182d88:	8f080040 */ 	lw	$t0,0x40($t8)
/*  f182d8c:	350f0004 */ 	ori	$t7,$t0,0x4
/*  f182d90:	af0f0040 */ 	sw	$t7,0x40($t8)
/*  f182d94:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f182d98:	906e0002 */ 	lbu	$t6,0x2($v1)
/*  f182d9c:	35c90004 */ 	ori	$t1,$t6,0x4
/*  f182da0:	a0690002 */ 	sb	$t1,0x2($v1)
/*  f182da4:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f182da8:	10000015 */ 	b	.L0f182e00
/*  f182dac:	85460006 */ 	lh	$a2,0x6($t2)
.L0f182db0:
/*  f182db0:	3c0b800b */ 	lui	$t3,%hi(g_ScenarioData)
/*  f182db4:	856bc110 */ 	lh	$t3,%lo(g_ScenarioData)($t3)
/*  f182db8:	59600011 */ 	blezl	$t3,.L0f182e00
/*  f182dbc:	00003025 */ 	or	$a2,$zero,$zero
/*  f182dc0:	0c004b70 */ 	jal	random
/*  f182dc4:	00000000 */ 	nop
/*  f182dc8:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f182dcc:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f182dd0:	846c0000 */ 	lh	$t4,0x0($v1)
/*  f182dd4:	004c001b */ 	divu	$zero,$v0,$t4
/*  f182dd8:	00006810 */ 	mfhi	$t5
/*  f182ddc:	000dc840 */ 	sll	$t9,$t5,0x1
/*  f182de0:	0079c021 */ 	addu	$t8,$v1,$t9
/*  f182de4:	15800002 */ 	bnez	$t4,.L0f182df0
/*  f182de8:	00000000 */ 	nop
/*  f182dec:	0007000d */ 	break	0x7
.L0f182df0:
/*  f182df0:	87060004 */ 	lh	$a2,0x4($t8)
/*  f182df4:	10000002 */ 	b	.L0f182e00
/*  f182df8:	00000000 */ 	nop
/*  f182dfc:	00003025 */ 	or	$a2,$zero,$zero
.L0f182e00:
/*  f182e00:	3c04800b */ 	lui	$a0,%hi(var800ac460)
/*  f182e04:	2484c460 */ 	addiu	$a0,$a0,%lo(var800ac460)
/*  f182e08:	27a80080 */ 	addiu	$t0,$sp,0x80
/*  f182e0c:	250e0060 */ 	addiu	$t6,$t0,0x60
/*  f182e10:	00804825 */ 	or	$t1,$a0,$zero
.L0f182e14:
/*  f182e14:	8d010000 */ 	lw	$at,0x0($t0)
/*  f182e18:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f182e1c:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f182e20:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*  f182e24:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*  f182e28:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*  f182e2c:	8d01fffc */ 	lw	$at,-0x4($t0)
/*  f182e30:	150efff8 */ 	bne	$t0,$t6,.L0f182e14
/*  f182e34:	ad21fffc */ 	sw	$at,-0x4($t1)
/*  f182e38:	8d010000 */ 	lw	$at,0x0($t0)
/*  f182e3c:	240503e7 */ 	addiu	$a1,$zero,0x3e7
/*  f182e40:	ad210000 */ 	sw	$at,0x0($t1)
/*  f182e44:	8d0e0004 */ 	lw	$t6,0x4($t0)
/*  f182e48:	ad2e0004 */ 	sw	$t6,0x4($t1)
/*  f182e4c:	0fc0359c */ 	jal	weaponAssignToHome
/*  f182e50:	a4860006 */ 	sh	$a2,0x6($a0)
/*  f182e54:	3c04800b */ 	lui	$a0,%hi(var800ac460)
/*  f182e58:	2484c460 */ 	addiu	$a0,$a0,%lo(var800ac460)
/*  f182e5c:	908a0002 */ 	lbu	$t2,0x2($a0)
/*  f182e60:	8c8c0014 */ 	lw	$t4,0x14($a0)
/*  f182e64:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f182e68:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f182e6c:	314bfffb */ 	andi	$t3,$t2,0xfffb
/*  f182e70:	a08b0002 */ 	sb	$t3,0x2($a0)
/*  f182e74:	11800004 */ 	beqz	$t4,.L0f182e88
/*  f182e78:	ac6c013c */ 	sw	$t4,0x13c($v1)
/*  f182e7c:	9199003f */ 	lbu	$t9,0x3f($t4)
/*  f182e80:	37380020 */ 	ori	$t8,$t9,0x20
/*  f182e84:	a198003f */ 	sb	$t8,0x3f($t4)
.L0f182e88:
/*  f182e88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f182e8c:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f182e90:	03e00008 */ 	jr	$ra
/*  f182e94:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel scenarioHtmReset
.late_rodata
glabel var7f1b8954
.word 0x3e4ccccd
.text
/*  f182e98:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f182e9c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f182ea0:	3c11800a */ 	lui	$s1,%hi(g_Vars+0x33c)
/*  f182ea4:	8e31a2fc */ 	lw	$s1,%lo(g_Vars+0x33c)($s1)
/*  f182ea8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f182eac:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f182eb0:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f182eb4:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f182eb8:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f182ebc:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f182ec0:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f182ec4:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f182ec8:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f182ecc:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f182ed0:	0200b025 */ 	or	$s6,$s0,$zero
/*  f182ed4:	12200017 */ 	beqz	$s1,.L0f182f34
/*  f182ed8:	00009025 */ 	or	$s2,$zero,$zero
/*  f182edc:	241500c1 */ 	addiu	$s5,$zero,0xc1
/*  f182ee0:	24140014 */ 	addiu	$s4,$zero,0x14
/*  f182ee4:	24130007 */ 	addiu	$s3,$zero,0x7
/*  f182ee8:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f182eec:	922e0000 */ 	lbu	$t6,0x0($s1)
.L0f182ef0:
/*  f182ef0:	564e000d */ 	bnel	$s2,$t6,.L0f182f28
/*  f182ef4:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f182ef8:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f182efc:	90430003 */ 	lbu	$v1,0x3($v0)
/*  f182f00:	52630004 */ 	beql	$s3,$v1,.L0f182f14
/*  f182f04:	844f0004 */ 	lh	$t7,0x4($v0)
/*  f182f08:	56830007 */ 	bnel	$s4,$v1,.L0f182f28
/*  f182f0c:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f182f10:	844f0004 */ 	lh	$t7,0x4($v0)
.L0f182f14:
/*  f182f14:	56af0004 */ 	bnel	$s5,$t7,.L0f182f28
/*  f182f18:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f182f1c:	0fc60ae9 */ 	jal	mpHtmAddPad
/*  f182f20:	84440006 */ 	lh	$a0,0x6($v0)
/*  f182f24:	8e310020 */ 	lw	$s1,0x20($s1)
.L0f182f28:
/*  f182f28:	5620fff1 */ 	bnezl	$s1,.L0f182ef0
/*  f182f2c:	922e0000 */ 	lbu	$t6,0x0($s1)
/*  f182f30:	00009025 */ 	or	$s2,$zero,$zero
.L0f182f34:
/*  f182f34:	0fc60ae7 */ 	jal	scenarioHtmCallback08
/*  f182f38:	00000000 */ 	nop
/*  f182f3c:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x2)
/*  f182f40:	0fc60ae7 */ 	jal	scenarioHtmCallback08
/*  f182f44:	a420c112 */ 	sh	$zero,%lo(g_ScenarioData+0x2)($at)
/*  f182f48:	3c18800b */ 	lui	$t8,%hi(g_ScenarioData+0x2)
/*  f182f4c:	8718c112 */ 	lh	$t8,%lo(g_ScenarioData+0x2)($t8)
/*  f182f50:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f182f54:	2411000c */ 	addiu	$s1,$zero,0xc
/*  f182f58:	0302082a */ 	slt	$at,$t8,$v0
/*  f182f5c:	10200020 */ 	beqz	$at,.L0f182fe0
/*  f182f60:	00000000 */ 	nop
.L0f182f64:
/*  f182f64:	0c004b70 */ 	jal	random
/*  f182f68:	00000000 */ 	nop
/*  f182f6c:	3c19800b */ 	lui	$t9,%hi(g_ScenarioData)
/*  f182f70:	8739c110 */ 	lh	$t9,%lo(g_ScenarioData)($t9)
/*  f182f74:	0059001b */ 	divu	$zero,$v0,$t9
/*  f182f78:	00001810 */ 	mfhi	$v1
/*  f182f7c:	00034040 */ 	sll	$t0,$v1,0x1
/*  f182f80:	02082821 */ 	addu	$a1,$s0,$t0
/*  f182f84:	84a40004 */ 	lh	$a0,0x4($a1)
/*  f182f88:	17200002 */ 	bnez	$t9,.L0f182f94
/*  f182f8c:	00000000 */ 	nop
/*  f182f90:	0007000d */ 	break	0x7
.L0f182f94:
/*  f182f94:	1880fff3 */ 	blez	$a0,.L0f182f64
/*  f182f98:	00000000 */ 	nop
/*  f182f9c:	3c09800b */ 	lui	$t1,%hi(g_ScenarioData+0x2)
/*  f182fa0:	8529c112 */ 	lh	$t1,%lo(g_ScenarioData+0x2)($t1)
/*  f182fa4:	3c0c800b */ 	lui	$t4,%hi(g_ScenarioData+0x2)
/*  f182fa8:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x2)
/*  f182fac:	01310019 */ 	multu	$t1,$s1
/*  f182fb0:	00005012 */ 	mflo	$t2
/*  f182fb4:	020a5821 */ 	addu	$t3,$s0,$t2
/*  f182fb8:	a5640084 */ 	sh	$a0,0x84($t3)
/*  f182fbc:	858cc112 */ 	lh	$t4,%lo(g_ScenarioData+0x2)($t4)
/*  f182fc0:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f182fc4:	a42dc112 */ 	sh	$t5,%lo(g_ScenarioData+0x2)($at)
/*  f182fc8:	0fc60ae7 */ 	jal	scenarioHtmCallback08
/*  f182fcc:	a4b30004 */ 	sh	$s3,0x4($a1)
/*  f182fd0:	86ce0002 */ 	lh	$t6,0x2($s6)
/*  f182fd4:	01c2082a */ 	slt	$at,$t6,$v0
/*  f182fd8:	1420ffe2 */ 	bnez	$at,.L0f182f64
/*  f182fdc:	00000000 */ 	nop
.L0f182fe0:
/*  f182fe0:	0fc60ae7 */ 	jal	scenarioHtmCallback08
/*  f182fe4:	00000000 */ 	nop
/*  f182fe8:	3c0f800b */ 	lui	$t7,%hi(g_ScenarioData+0x2)
/*  f182fec:	85efc112 */ 	lh	$t7,%lo(g_ScenarioData+0x2)($t7)
/*  f182ff0:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f182ff4:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f182ff8:	19e00006 */ 	blez	$t7,.L0f183014
/*  f182ffc:	3c14800b */ 	lui	$s4,%hi(g_ScenarioData+0xc)
/*  f183000:	86c20002 */ 	lh	$v0,0x2($s6)
/*  f183004:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f183008:
/*  f183008:	0242082a */ 	slt	$at,$s2,$v0
/*  f18300c:	5420fffe */ 	bnezl	$at,.L0f183008
/*  f183010:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f183014:
/*  f183014:	3c017f1c */ 	lui	$at,%hi(var7f1b8954)
/*  f183018:	3c130001 */ 	lui	$s3,0x1
/*  f18301c:	3c120020 */ 	lui	$s2,0x20
/*  f183020:	3c110042 */ 	lui	$s1,0x42
/*  f183024:	36310001 */ 	ori	$s1,$s1,0x1
/*  f183028:	36524000 */ 	ori	$s2,$s2,0x4000
/*  f18302c:	36732000 */ 	ori	$s3,$s3,0x2000
/*  f183030:	c4348954 */ 	lwc1	$f20,%lo(var7f1b8954)($at)
/*  f183034:	2694c11c */ 	addiu	$s4,$s4,%lo(g_ScenarioData+0xc)
/*  f183038:	4406a000 */ 	mfc1	$a2,$f20
.L0f18303c:
/*  f18303c:	24040156 */ 	addiu	$a0,$zero,0x156
/*  f183040:	86050084 */ 	lh	$a1,0x84($s0)
/*  f183044:	02203825 */ 	or	$a3,$s1,$zero
/*  f183048:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f18304c:	0fc61942 */ 	jal	func0f186508
/*  f183050:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f183054:	ae020080 */ 	sw	$v0,0x80($s0)
/*  f183058:	0fc5fff9 */ 	jal	func0f17ffe4
/*  f18305c:	86040084 */ 	lh	$a0,0x84($s0)
/*  f183060:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f183064:	5614fff5 */ 	bnel	$s0,$s4,.L0f18303c
/*  f183068:	4406a000 */ 	mfc1	$a2,$f20
/*  f18306c:	3c018008 */ 	lui	$at,%hi(var800869ec)
/*  f183070:	0fc60b26 */ 	jal	func0f182c98
/*  f183074:	ac2069ec */ 	sw	$zero,%lo(var800869ec)($at)
/*  f183078:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f18307c:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f183080:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f183084:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f183088:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f18308c:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f183090:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f183094:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f183098:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f18309c:	03e00008 */ 	jr	$ra
/*  f1830a0:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

void scenarioHtmCallback10(void)
{
	u8 stack[8];
	s32 i;
	u32 prevplayernum = g_Vars.currentplayernum;
	struct prop *prop;

	if (var800869ec && var800869ec->prop) {
		if (g_ScenarioData.htm.uplink == NULL || g_ScenarioData.htm.uplink->type != PROPTYPE_WEAPON) {
			var800869ec = 0;
		} else {
			var800869ec->prop->timetoregen = 1200;
		}
	}

	g_ScenarioData.htm.uplink = NULL;

	// Check if uplink is on the ground
	prop = g_Vars.unk00033c;

	while (prop) {
		if (prop->type == PROPTYPE_WEAPON) {
			struct weaponobj *weapon = prop->weapon;

			if (weapon->weaponnum == WEAPON_DATAUPLINK) {
				g_ScenarioData.htm.uplink = prop;
			}
		}

		prop = prop->next;
	}

	// Check if a player is holding it
	if (g_ScenarioData.htm.uplink == NULL) {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);

			if (invHasDataUplink()) {
				g_ScenarioData.htm.uplink = g_Vars.currentplayer->prop;
				break;
			}
		}
	}

	setCurrentPlayerNum(prevplayernum);

	// Check if a simulant is holding it
	if (g_ScenarioData.htm.uplink == NULL) {
		for (i = PLAYERCOUNT(); i < g_MpNumPlayers; i++) {
			if (g_MpPlayerChrs[i]->aibot->unk04c_05) {
				g_ScenarioData.htm.uplink = g_MpPlayerChrs[i]->prop;
				break;
			}
		}
	}

	if (g_ScenarioData.htm.uplink == NULL) {
		func0f182c98();
	}
}

GLOBAL_ASM(
glabel scenarioHtmCallback14
.late_rodata
glabel var7f1b8958
.word 0x40c907a9
glabel var7f1b895c
.word 0x42652ee0
glabel var7f1b8960
.word 0x42652ee0
.text
/*  f183380:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f183384:	afb4005c */ 	sw	$s4,0x5c($sp)
/*  f183388:	0080a025 */ 	or	$s4,$a0,$zero
/*  f18338c:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f183390:	afb50060 */ 	sw	$s5,0x60($sp)
/*  f183394:	afb30058 */ 	sw	$s3,0x58($sp)
/*  f183398:	afb20054 */ 	sw	$s2,0x54($sp)
/*  f18339c:	afb10050 */ 	sw	$s1,0x50($sp)
/*  f1833a0:	afb0004c */ 	sw	$s0,0x4c($sp)
/*  f1833a4:	10800008 */ 	beqz	$a0,.L0f1833c8
/*  f1833a8:	f7b40040 */ 	sdc1	$f20,0x40($sp)
/*  f1833ac:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f1833b0:	8dd3004c */ 	lw	$s3,0x4c($t6)
/*  f1833b4:	00137940 */ 	sll	$t7,$s3,0x5
/*  f1833b8:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1833bc:	000f9fc2 */ 	srl	$s3,$t7,0x1f
/*  f1833c0:	1000000d */ 	b	.L0f1833f8
/*  f1833c4:	00409025 */ 	or	$s2,$v0,$zero
.L0f1833c8:
/*  f1833c8:	0fc44a21 */ 	jal	invHasDataUplink
/*  f1833cc:	00000000 */ 	nop
/*  f1833d0:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f1833d4:	10800005 */ 	beqz	$a0,.L0f1833ec
/*  f1833d8:	00000000 */ 	nop
/*  f1833dc:	0fc2866a */ 	jal	handGetWeaponNum
/*  f1833e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1833e4:	38440036 */ 	xori	$a0,$v0,0x36
/*  f1833e8:	2c840001 */ 	sltiu	$a0,$a0,0x1
.L0f1833ec:
/*  f1833ec:	3c12800a */ 	lui	$s2,%hi(g_Vars+0x28c)
/*  f1833f0:	00809825 */ 	or	$s3,$a0,$zero
/*  f1833f4:	8e52a24c */ 	lw	$s2,%lo(g_Vars+0x28c)($s2)
.L0f1833f8:
/*  f1833f8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1833fc:	3c11800b */ 	lui	$s1,%hi(g_ScenarioData)
/*  f183400:	3c15800b */ 	lui	$s5,%hi(g_ScenarioData)
/*  f183404:	4481a000 */ 	mtc1	$at,$f20
/*  f183408:	26b5c110 */ 	addiu	$s5,$s5,%lo(g_ScenarioData)
/*  f18340c:	2631c110 */ 	addiu	$s1,$s1,%lo(g_ScenarioData)
/*  f183410:	00008025 */ 	or	$s0,$zero,$zero
.L0f183414:
/*  f183414:	8e240080 */ 	lw	$a0,0x80($s1)
/*  f183418:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f18341c:	50800061 */ 	beqzl	$a0,.L0f1835a4
/*  f183420:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183424:	12800005 */ 	beqz	$s4,.L0f18343c
/*  f183428:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f18342c:	1260000b */ 	beqz	$s3,.L0f18345c
/*  f183430:	00000000 */ 	nop
/*  f183434:	10000009 */ 	b	.L0f18345c
/*  f183438:	02402825 */ 	or	$a1,$s2,$zero
.L0f18343c:
/*  f18343c:	8c620040 */ 	lw	$v0,0x40($v1)
/*  f183440:	3c01f000 */ 	lui	$at,0xf000
/*  f183444:	30594000 */ 	andi	$t9,$v0,0x4000
/*  f183448:	13200004 */ 	beqz	$t9,.L0f18345c
/*  f18344c:	00000000 */ 	nop
/*  f183450:	00412824 */ 	and	$a1,$v0,$at
/*  f183454:	00054702 */ 	srl	$t0,$a1,0x1c
/*  f183458:	01002825 */ 	or	$a1,$t0,$zero
.L0f18345c:
/*  f18345c:	56450051 */ 	bnel	$s2,$a1,.L0f1835a4
/*  f183460:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183464:	8c690040 */ 	lw	$t1,0x40($v1)
/*  f183468:	2401bfff */ 	addiu	$at,$zero,-16385
/*  f18346c:	3c0d800b */ 	lui	$t5,%hi(g_ScenarioData+0xd4)
/*  f183470:	01215024 */ 	and	$t2,$t1,$at
/*  f183474:	3c010fff */ 	lui	$at,0xfff
/*  f183478:	3421ffff */ 	ori	$at,$at,0xffff
/*  f18347c:	ac6a0040 */ 	sw	$t2,0x40($v1)
/*  f183480:	01416024 */ 	and	$t4,$t2,$at
/*  f183484:	1260002e */ 	beqz	$s3,.L0f183540
/*  f183488:	ac6c0040 */ 	sw	$t4,0x40($v1)
/*  f18348c:	8dadc1e4 */ 	lw	$t5,%lo(g_ScenarioData+0xd4)($t5)
/*  f183490:	2401ffff */ 	addiu	$at,$zero,-1
/*  f183494:	00127080 */ 	sll	$t6,$s2,0x2
/*  f183498:	15a10041 */ 	bne	$t5,$at,.L0f1835a0
/*  f18349c:	02ae7821 */ 	addu	$t7,$s5,$t6
/*  f1834a0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd4)
/*  f1834a4:	ac30c1e4 */ 	sw	$s0,%lo(g_ScenarioData+0xd4)($at)
/*  f1834a8:	a432c1e0 */ 	sh	$s2,-0x3e20($at)
/*  f1834ac:	a432c1e2 */ 	sh	$s2,-0x3e1e($at)
/*  f1834b0:	1680003b */ 	bnez	$s4,.L0f1835a0
/*  f1834b4:	ade00108 */ 	sw	$zero,0x108($t7)
/*  f1834b8:	0fc5b9f1 */ 	jal	langGet
/*  f1834bc:	24045412 */ 	addiu	$a0,$zero,0x5412
/*  f1834c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1834c4:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1834c8:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f1834cc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1834d0:	3c18800b */ 	lui	$t8,%hi(g_ScenarioData+0xd4)
/*  f1834d4:	8f18c1e4 */ 	lw	$t8,%lo(g_ScenarioData+0xd4)($t8)
/*  f1834d8:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f1834dc:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f1834e0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1834e4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1834e8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1834ec:	02b94021 */ 	addu	$t0,$s5,$t9
/*  f1834f0:	8d050080 */ 	lw	$a1,0x80($t0)
/*  f1834f4:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f1834f8:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1834fc:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f183500:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f183504:	e7b40038 */ 	swc1	$f20,0x38($sp)
/*  f183508:	e7b40034 */ 	swc1	$f20,0x34($sp)
/*  f18350c:	e7b40030 */ 	swc1	$f20,0x30($sp)
/*  f183510:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f183514:	e7b40024 */ 	swc1	$f20,0x24($sp)
/*  f183518:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f18351c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f183520:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f183524:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f183528:	00002025 */ 	or	$a0,$zero,$zero
/*  f18352c:	240601bf */ 	addiu	$a2,$zero,0x1bf
/*  f183530:	0fc24e7e */ 	jal	func0f0939f8
/*  f183534:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f183538:	1000001a */ 	b	.L0f1835a4
/*  f18353c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f183540:
/*  f183540:	56800018 */ 	bnezl	$s4,.L0f1835a4
/*  f183544:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183548:	0fc5b9f1 */ 	jal	langGet
/*  f18354c:	24045413 */ 	addiu	$a0,$zero,0x5413
/*  f183550:	00402025 */ 	or	$a0,$v0,$zero
/*  f183554:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f183558:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f18355c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f183560:	3c013f80 */ 	lui	$at,0x3f80
/*  f183564:	44812000 */ 	mtc1	$at,$f4
/*  f183568:	240d01cc */ 	addiu	$t5,$zero,0x1cc
/*  f18356c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f183570:	240fffff */ 	addiu	$t7,$zero,-1
/*  f183574:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f183578:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f18357c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f183580:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f183584:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f183588:	00002025 */ 	or	$a0,$zero,$zero
/*  f18358c:	00002825 */ 	or	$a1,$zero,$zero
/*  f183590:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f183594:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f183598:	0c0041c6 */ 	jal	func00010718
/*  f18359c:	e7a40014 */ 	swc1	$f4,0x14($sp)
.L0f1835a0:
/*  f1835a0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1835a4:
/*  f1835a4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1835a8:	1601ff9a */ 	bne	$s0,$at,.L0f183414
/*  f1835ac:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f1835b0:	3c19800b */ 	lui	$t9,%hi(g_ScenarioData+0xd0)
/*  f1835b4:	8739c1e0 */ 	lh	$t9,%lo(g_ScenarioData+0xd0)($t9)
/*  f1835b8:	3c08800b */ 	lui	$t0,%hi(g_ScenarioData+0xd4)
/*  f1835bc:	565900f1 */ 	bnel	$s2,$t9,.L0f183984
/*  f1835c0:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f1835c4:	8d08c1e4 */ 	lw	$t0,%lo(g_ScenarioData+0xd4)($t0)
/*  f1835c8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1835cc:	00125880 */ 	sll	$t3,$s2,0x2
/*  f1835d0:	110100eb */ 	beq	$t0,$at,.L0f183980
/*  f1835d4:	00084880 */ 	sll	$t1,$t0,0x2
/*  f1835d8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1835dc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1835e0:	02a95021 */ 	addu	$t2,$s5,$t1
/*  f1835e4:	8d510080 */ 	lw	$s1,0x80($t2)
/*  f1835e8:	02ab9821 */ 	addu	$s3,$s5,$t3
/*  f1835ec:	266c0108 */ 	addiu	$t4,$s3,0x108
/*  f1835f0:	afac006c */ 	sw	$t4,0x6c($sp)
/*  f1835f4:	12800011 */ 	beqz	$s4,.L0f18363c
/*  f1835f8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1835fc:	8e90001c */ 	lw	$s0,0x1c($s4)
/*  f183600:	02802025 */ 	or	$a0,$s4,$zero
/*  f183604:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f183608:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f18360c:	3c017f1c */ 	lui	$at,%hi(var7f1b8958)
/*  f183610:	c4268958 */ 	lwc1	$f6,%lo(var7f1b8958)($at)
/*  f183614:	3c017f1c */ 	lui	$at,%hi(var7f1b895c)
/*  f183618:	c42a895c */ 	lwc1	$f10,%lo(var7f1b895c)($at)
/*  f18361c:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f183620:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f183624:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f183628:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f18362c:	8da30020 */ 	lw	$v1,0x20($t5)
/*  f183630:	386e0001 */ 	xori	$t6,$v1,0x1
/*  f183634:	1000000b */ 	b	.L0f183664
/*  f183638:	2dc30001 */ 	sltiu	$v1,$t6,0x1
.L0f18363c:
/*  f18363c:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f183640:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f183644:	00002025 */ 	or	$a0,$zero,$zero
/*  f183648:	8c5000bc */ 	lw	$s0,0xbc($v0)
/*  f18364c:	c4460144 */ 	lwc1	$f6,0x144($v0)
/*  f183650:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f183654:	0fc2866a */ 	jal	handGetWeaponNum
/*  f183658:	e7a60098 */ 	swc1	$f6,0x98($sp)
/*  f18365c:	38430036 */ 	xori	$v1,$v0,0x36
/*  f183660:	2c630001 */ 	sltiu	$v1,$v1,0x1
.L0f183664:
/*  f183664:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*  f183668:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f18366c:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*  f183670:	c6060004 */ 	lwc1	$f6,0x4($s0)
/*  f183674:	460a4501 */ 	sub.s	$f20,$f8,$f10
/*  f183678:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f18367c:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f183680:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f183684:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f183688:	afa30078 */ 	sw	$v1,0x78($sp)
/*  f18368c:	460a4381 */ 	sub.s	$f14,$f8,$f10
/*  f183690:	e7a20080 */ 	swc1	$f2,0x80($sp)
/*  f183694:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f183698:	e7ae0084 */ 	swc1	$f14,0x84($sp)
/*  f18369c:	0c012974 */ 	jal	sqrtf
/*  f1836a0:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f1836a4:	c7a20080 */ 	lwc1	$f2,0x80($sp)
/*  f1836a8:	44804000 */ 	mtc1	$zero,$f8
/*  f1836ac:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f1836b0:	c7ae0084 */ 	lwc1	$f14,0x84($sp)
/*  f1836b4:	4602403c */ 	c.lt.s	$f8,$f2
/*  f1836b8:	46000486 */ 	mov.s	$f18,$f0
/*  f1836bc:	4600a306 */ 	mov.s	$f12,$f20
/*  f1836c0:	45020004 */ 	bc1fl	.L0f1836d4
/*  f1836c4:	46001407 */ 	neg.s	$f16,$f2
/*  f1836c8:	10000002 */ 	b	.L0f1836d4
/*  f1836cc:	46001406 */ 	mov.s	$f16,$f2
/*  f1836d0:	46001407 */ 	neg.s	$f16,$f2
.L0f1836d4:
/*  f1836d4:	afa30078 */ 	sw	$v1,0x78($sp)
/*  f1836d8:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*  f1836dc:	0fc259d4 */ 	jal	func0f096750
/*  f1836e0:	e7b20090 */ 	swc1	$f18,0x90($sp)
/*  f1836e4:	3c014334 */ 	lui	$at,0x4334
/*  f1836e8:	44816000 */ 	mtc1	$at,$f12
/*  f1836ec:	3c017f1c */ 	lui	$at,%hi(var7f1b8960)
/*  f1836f0:	c42a8960 */ 	lwc1	$f10,%lo(var7f1b8960)($at)
/*  f1836f4:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f1836f8:	44804000 */ 	mtc1	$zero,$f8
/*  f1836fc:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f183700:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f183704:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*  f183708:	c7b20090 */ 	lwc1	$f18,0x90($sp)
/*  f18370c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f183710:	46062080 */ 	add.s	$f2,$f4,$f6
/*  f183714:	460c103c */ 	c.lt.s	$f2,$f12
/*  f183718:	00000000 */ 	nop
/*  f18371c:	45020009 */ 	bc1fl	.L0f183744
/*  f183720:	4602603c */ 	c.lt.s	$f12,$f2
/*  f183724:	44810000 */ 	mtc1	$at,$f0
/*  f183728:	00000000 */ 	nop
/*  f18372c:	46001080 */ 	add.s	$f2,$f2,$f0
.L0f183730:
/*  f183730:	460c103c */ 	c.lt.s	$f2,$f12
/*  f183734:	00000000 */ 	nop
/*  f183738:	4503fffd */ 	bc1tl	.L0f183730
/*  f18373c:	46001080 */ 	add.s	$f2,$f2,$f0
/*  f183740:	4602603c */ 	c.lt.s	$f12,$f2
.L0f183744:
/*  f183744:	3c0143b4 */ 	lui	$at,0x43b4
/*  f183748:	44810000 */ 	mtc1	$at,$f0
/*  f18374c:	3c01437a */ 	lui	$at,0x437a
/*  f183750:	45020007 */ 	bc1fl	.L0f183770
/*  f183754:	4602403c */ 	c.lt.s	$f8,$f2
/*  f183758:	46001081 */ 	sub.s	$f2,$f2,$f0
.L0f18375c:
/*  f18375c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f183760:	00000000 */ 	nop
/*  f183764:	4503fffd */ 	bc1tl	.L0f18375c
/*  f183768:	46001081 */ 	sub.s	$f2,$f2,$f0
/*  f18376c:	4602403c */ 	c.lt.s	$f8,$f2
.L0f183770:
/*  f183770:	44810000 */ 	mtc1	$at,$f0
/*  f183774:	3c014348 */ 	lui	$at,0x4348
/*  f183778:	45030003 */ 	bc1tl	.L0f183788
/*  f18377c:	4612003c */ 	c.lt.s	$f0,$f18
/*  f183780:	46001087 */ 	neg.s	$f2,$f2
/*  f183784:	4612003c */ 	c.lt.s	$f0,$f18
.L0f183788:
/*  f183788:	00000000 */ 	nop
/*  f18378c:	45030010 */ 	bc1tl	.L0f1837d0
/*  f183790:	4600903c */ 	c.lt.s	$f18,$f0
/*  f183794:	44815000 */ 	mtc1	$at,$f10
/*  f183798:	3c014234 */ 	lui	$at,0x4234
/*  f18379c:	4610503c */ 	c.lt.s	$f10,$f16
/*  f1837a0:	00000000 */ 	nop
/*  f1837a4:	4503000a */ 	bc1tl	.L0f1837d0
/*  f1837a8:	4600903c */ 	c.lt.s	$f18,$f0
/*  f1837ac:	44812000 */ 	mtc1	$at,$f4
/*  f1837b0:	00000000 */ 	nop
/*  f1837b4:	4602203c */ 	c.lt.s	$f4,$f2
/*  f1837b8:	00000000 */ 	nop
/*  f1837bc:	45030004 */ 	bc1tl	.L0f1837d0
/*  f1837c0:	4600903c */ 	c.lt.s	$f18,$f0
/*  f1837c4:	1460003a */ 	bnez	$v1,.L0f1838b0
/*  f1837c8:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*  f1837cc:	4600903c */ 	c.lt.s	$f18,$f0
.L0f1837d0:
/*  f1837d0:	3c014348 */ 	lui	$at,0x4348
/*  f1837d4:	240fffff */ 	addiu	$t7,$zero,-1
/*  f1837d8:	45000009 */ 	bc1f	.L0f183800
/*  f1837dc:	00000000 */ 	nop
/*  f1837e0:	44813000 */ 	mtc1	$at,$f6
/*  f1837e4:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd2)
/*  f1837e8:	4606803c */ 	c.lt.s	$f16,$f6
/*  f1837ec:	00000000 */ 	nop
/*  f1837f0:	45000003 */ 	bc1f	.L0f183800
/*  f1837f4:	00000000 */ 	nop
/*  f1837f8:	10000003 */ 	b	.L0f183808
/*  f1837fc:	a432c1e2 */ 	sh	$s2,%lo(g_ScenarioData+0xd2)($at)
.L0f183800:
/*  f183800:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd2)
/*  f183804:	a42fc1e2 */ 	sh	$t7,%lo(g_ScenarioData+0xd2)($at)
.L0f183808:
/*  f183808:	16800021 */ 	bnez	$s4,.L0f183890
/*  f18380c:	00000000 */ 	nop
/*  f183810:	0fc5b9f1 */ 	jal	langGet
/*  f183814:	24045411 */ 	addiu	$a0,$zero,0x5411
/*  f183818:	00402025 */ 	or	$a0,$v0,$zero
/*  f18381c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f183820:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f183824:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f183828:	3c18800b */ 	lui	$t8,%hi(g_ScenarioData+0xd4)
/*  f18382c:	8f18c1e4 */ 	lw	$t8,%lo(g_ScenarioData+0xd4)($t8)
/*  f183830:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f183834:	3406ffff */ 	dli	$a2,0xffff
/*  f183838:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f18383c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f183840:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f183844:	02b94021 */ 	addu	$t0,$s5,$t9
/*  f183848:	0fc249af */ 	jal	func0f0926bc
/*  f18384c:	8d040080 */ 	lw	$a0,0x80($t0)
/*  f183850:	3c013f80 */ 	lui	$at,0x3f80
/*  f183854:	44814000 */ 	mtc1	$at,$f8
/*  f183858:	240901cc */ 	addiu	$t1,$zero,0x1cc
/*  f18385c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f183860:	240bffff */ 	addiu	$t3,$zero,-1
/*  f183864:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f183868:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f18386c:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f183870:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f183874:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f183878:	00002025 */ 	or	$a0,$zero,$zero
/*  f18387c:	00002825 */ 	or	$a1,$zero,$zero
/*  f183880:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f183884:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f183888:	0c0041c6 */ 	jal	func00010718
/*  f18388c:	e7a80014 */ 	swc1	$f8,0x14($sp)
.L0f183890:
/*  f183890:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd4)
/*  f183894:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f183898:	240dffff */ 	addiu	$t5,$zero,-1
/*  f18389c:	240effff */ 	addiu	$t6,$zero,-1
/*  f1838a0:	ac2dc1e4 */ 	sw	$t5,%lo(g_ScenarioData+0xd4)($at)
/*  f1838a4:	a42ec1e0 */ 	sh	$t6,-0x3e20($at)
/*  f1838a8:	10000035 */ 	b	.L0f183980
/*  f1838ac:	ade00000 */ 	sw	$zero,0x0($t7)
.L0f1838b0:
/*  f1838b0:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x34)
/*  f1838b4:	8f399ff4 */ 	lw	$t9,%lo(g_Vars+0x34)($t9)
/*  f1838b8:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f1838bc:	03194021 */ 	addu	$t0,$t8,$t9
/*  f1838c0:	290112c1 */ 	slti	$at,$t0,0x12c1
/*  f1838c4:	1420002e */ 	bnez	$at,.L0f183980
/*  f1838c8:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f1838cc:	8e6a00d8 */ 	lw	$t2,0xd8($s3)
/*  f1838d0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd2)
/*  f1838d4:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f1838d8:	ae6b00d8 */ 	sw	$t3,0xd8($s3)
/*  f1838dc:	16800022 */ 	bnez	$s4,.L0f183968
/*  f1838e0:	a432c1e2 */ 	sh	$s2,%lo(g_ScenarioData+0xd2)($at)
/*  f1838e4:	0fc5b9f1 */ 	jal	langGet
/*  f1838e8:	24045410 */ 	addiu	$a0,$zero,0x5410
/*  f1838ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f1838f0:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1838f4:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f1838f8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1838fc:	3c0c800b */ 	lui	$t4,%hi(g_ScenarioData+0xd4)
/*  f183900:	8d8cc1e4 */ 	lw	$t4,%lo(g_ScenarioData+0xd4)($t4)
/*  f183904:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f183908:	3406ffff */ 	dli	$a2,0xffff
/*  f18390c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f183910:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f183914:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f183918:	02ad7021 */ 	addu	$t6,$s5,$t5
/*  f18391c:	0fc249af */ 	jal	func0f0926bc
/*  f183920:	8dc40080 */ 	lw	$a0,0x80($t6)
/*  f183924:	3c013f80 */ 	lui	$at,0x3f80
/*  f183928:	44815000 */ 	mtc1	$at,$f10
/*  f18392c:	240f01c1 */ 	addiu	$t7,$zero,0x1c1
/*  f183930:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f183934:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f183938:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f18393c:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f183940:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f183944:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f183948:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f18394c:	00002025 */ 	or	$a0,$zero,$zero
/*  f183950:	00002825 */ 	or	$a1,$zero,$zero
/*  f183954:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f183958:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f18395c:	0c0041c6 */ 	jal	func00010718
/*  f183960:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f183964:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f183968:
/*  f183968:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd4)
/*  f18396c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f183970:	240affff */ 	addiu	$t2,$zero,-1
/*  f183974:	ac29c1e4 */ 	sw	$t1,%lo(g_ScenarioData+0xd4)($at)
/*  f183978:	a42ac1e0 */ 	sh	$t2,-0x3e20($at)
/*  f18397c:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f183980:
/*  f183980:	8fbf0064 */ 	lw	$ra,0x64($sp)
.L0f183984:
/*  f183984:	d7b40040 */ 	ldc1	$f20,0x40($sp)
/*  f183988:	8fb0004c */ 	lw	$s0,0x4c($sp)
/*  f18398c:	8fb10050 */ 	lw	$s1,0x50($sp)
/*  f183990:	8fb20054 */ 	lw	$s2,0x54($sp)
/*  f183994:	8fb30058 */ 	lw	$s3,0x58($sp)
/*  f183998:	8fb4005c */ 	lw	$s4,0x5c($sp)
/*  f18399c:	8fb50060 */ 	lw	$s5,0x60($sp)
/*  f1839a0:	03e00008 */ 	jr	$ra
/*  f1839a4:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);

GLOBAL_ASM(
glabel scenarioHtmCallback18
/*  f1839a8:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x28c)
/*  f1839ac:	8c42a24c */ 	lw	$v0,%lo(g_Vars+0x28c)($v0)
/*  f1839b0:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f1839b4:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f1839b8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f1839bc:	8c7900d4 */ 	lw	$t9,0xd4($v1)
/*  f1839c0:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f1839c4:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f1839c8:	8df80108 */ 	lw	$t8,0x108($t7)
/*  f1839cc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1839d0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1839d4:	00808025 */ 	or	$s0,$a0,$zero
/*  f1839d8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1839dc:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1839e0:	1321006e */ 	beq	$t9,$at,.L0f183b9c
/*  f1839e4:	afb80060 */ 	sw	$t8,0x60($sp)
/*  f1839e8:	3c09800b */ 	lui	$t1,%hi(g_ScenarioData+0xd0)
/*  f1839ec:	8529c1e0 */ 	lh	$t1,%lo(g_ScenarioData+0xd0)($t1)
/*  f1839f0:	5449006b */ 	bnel	$v0,$t1,.L0f183ba0
/*  f1839f4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1839f8:	0c002f40 */ 	jal	viGetViewLeft
/*  f1839fc:	00000000 */ 	nop
/*  f183a00:	0c002f40 */ 	jal	viGetViewLeft
/*  f183a04:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f183a08:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f183a0c:	00115403 */ 	sra	$t2,$s1,0x10
/*  f183a10:	0c002f22 */ 	jal	viGetViewWidth
/*  f183a14:	01408825 */ 	or	$s1,$t2,$zero
/*  f183a18:	00515821 */ 	addu	$t3,$v0,$s1
/*  f183a1c:	0c002f44 */ 	jal	viGetViewTop
/*  f183a20:	afab0058 */ 	sw	$t3,0x58($sp)
/*  f183a24:	0c002f22 */ 	jal	viGetViewWidth
/*  f183a28:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f183a2c:	8fac005c */ 	lw	$t4,0x5c($sp)
/*  f183a30:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f183a34:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f183a38:	02002025 */ 	or	$a0,$s0,$zero
/*  f183a3c:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f183a40:	04610003 */ 	bgez	$v1,.L0f183a50
/*  f183a44:	00037043 */ 	sra	$t6,$v1,0x1
/*  f183a48:	24610001 */ 	addiu	$at,$v1,0x1
/*  f183a4c:	00017043 */ 	sra	$t6,$at,0x1
.L0f183a50:
/*  f183a50:	24010003 */ 	addiu	$at,$zero,0x3
/*  f183a54:	0041001a */ 	div	$zero,$v0,$at
/*  f183a58:	44982000 */ 	mtc1	$t8,$f4
/*  f183a5c:	00002812 */ 	mflo	$a1
/*  f183a60:	44858000 */ 	mtc1	$a1,$f16
/*  f183a64:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f183a68:	01c01825 */ 	or	$v1,$t6,$zero
/*  f183a6c:	04a10003 */ 	bgez	$a1,.L0f183a7c
/*  f183a70:	00053043 */ 	sra	$a2,$a1,0x1
/*  f183a74:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f183a78:	00013043 */ 	sra	$a2,$at,0x1
.L0f183a7c:
/*  f183a7c:	3c014596 */ 	lui	$at,0x4596
/*  f183a80:	44814000 */ 	mtc1	$at,$f8
/*  f183a84:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f183a88:	00663823 */ 	subu	$a3,$v1,$a2
/*  f183a8c:	00c37821 */ 	addu	$t7,$a2,$v1
/*  f183a90:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f183a94:	afaf0044 */ 	sw	$t7,0x44($sp)
/*  f183a98:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f183a9c:	460a9102 */ 	mul.s	$f4,$f18,$f10
/*  f183aa0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f183aa4:	44093000 */ 	mfc1	$t1,$f6
/*  f183aa8:	0fc54d8a */ 	jal	func0f153628
/*  f183aac:	01278821 */ 	addu	$s1,$t1,$a3
/*  f183ab0:	3c056000 */ 	lui	$a1,0x6000
/*  f183ab4:	34a50060 */ 	ori	$a1,$a1,0x60
/*  f183ab8:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f183abc:	00402025 */ 	or	$a0,$v0,$zero
/*  f183ac0:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f183ac4:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f183ac8:	3c08f600 */ 	lui	$t0,0xf600
/*  f183acc:	24660010 */ 	addiu	$a2,$v1,0x10
/*  f183ad0:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f183ad4:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f183ad8:	30ca03ff */ 	andi	$t2,$a2,0x3ff
/*  f183adc:	000a3080 */ 	sll	$a2,$t2,0x2
/*  f183ae0:	01c87825 */ 	or	$t7,$t6,$t0
/*  f183ae4:	01e6c025 */ 	or	$t8,$t7,$a2
/*  f183ae8:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f183aec:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f183af0:	24670008 */ 	addiu	$a3,$v1,0x8
/*  f183af4:	30f903ff */ 	andi	$t9,$a3,0x3ff
/*  f183af8:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f183afc:	000b6380 */ 	sll	$t4,$t3,0xe
/*  f183b00:	00194880 */ 	sll	$t1,$t9,0x2
/*  f183b04:	01896825 */ 	or	$t5,$t4,$t1
/*  f183b08:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f183b0c:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f183b10:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f183b14:	0fc54e0e */ 	jal	func0f153838
/*  f183b18:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f183b1c:	3c05c000 */ 	lui	$a1,0xc000
/*  f183b20:	34a500d0 */ 	ori	$a1,$a1,0xd0
/*  f183b24:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f183b28:	00402025 */ 	or	$a0,$v0,$zero
/*  f183b2c:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f183b30:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f183b34:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f183b38:	24830001 */ 	addiu	$v1,$a0,0x1
/*  f183b3c:	0071082a */ 	slt	$at,$v1,$s1
/*  f183b40:	3c08f600 */ 	lui	$t0,0xf600
/*  f183b44:	10200010 */ 	beqz	$at,.L0f183b88
/*  f183b48:	00408025 */ 	or	$s0,$v0,$zero
.L0f183b4c:
/*  f183b4c:	306f03ff */ 	andi	$t7,$v1,0x3ff
/*  f183b50:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f183b54:	308a03ff */ 	andi	$t2,$a0,0x3ff
/*  f183b58:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f183b5c:	0308c825 */ 	or	$t9,$t8,$t0
/*  f183b60:	02001025 */ 	or	$v0,$s0,$zero
/*  f183b64:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f183b68:	03264825 */ 	or	$t1,$t9,$a2
/*  f183b6c:	01676025 */ 	or	$t4,$t3,$a3
/*  f183b70:	0071082a */ 	slt	$at,$v1,$s1
/*  f183b74:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f183b78:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f183b7c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f183b80:	1420fff2 */ 	bnez	$at,.L0f183b4c
/*  f183b84:	24840002 */ 	addiu	$a0,$a0,0x2
.L0f183b88:
/*  f183b88:	0fc54e0e */ 	jal	func0f153838
/*  f183b8c:	02002025 */ 	or	$a0,$s0,$zero
/*  f183b90:	0fc54de0 */ 	jal	func0f153780
/*  f183b94:	00402025 */ 	or	$a0,$v0,$zero
/*  f183b98:	00408025 */ 	or	$s0,$v0,$zero
.L0f183b9c:
/*  f183b9c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f183ba0:
/*  f183ba0:	02001025 */ 	or	$v0,$s0,$zero
/*  f183ba4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f183ba8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f183bac:	03e00008 */ 	jr	$ra
/*  f183bb0:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

void scenarioHtmKill(struct mpchr *mpchr, s32 mpchrnum, s32 *score, s32 *arg3)
{
	struct mpchr *loopmpchr;
	s32 i;
	s32 index;

	*score = 0;
	index = func0f18d0e8(mpchrnum);

	if (index >= 0) {
		*score += g_ScenarioData.htm.unk0d8[index] * 2;
	}

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == mpchrnum) {
				*score -= mpchr->killcounts[i];
			} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				if (i < 4) {
					loopmpchr = &g_MpPlayers[i].base;
				} else {
					loopmpchr = &g_MpSimulants[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			} else {
				*score += mpchr->killcounts[i];
			}
		}
	}

	*arg3 = mpchr->numdeaths;
}

GLOBAL_ASM(
glabel scenarioHtmRadar
/*  f183d10:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f183d14:	afb70048 */ 	sw	$s7,0x48($sp)
/*  f183d18:	3c17800b */ 	lui	$s7,%hi(g_MpSetup)
/*  f183d1c:	26f7cb88 */ 	addiu	$s7,$s7,%lo(g_MpSetup)
/*  f183d20:	8eee000c */ 	lw	$t6,0xc($s7)
/*  f183d24:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f183d28:	00808825 */ 	or	$s1,$a0,$zero
/*  f183d2c:	000e7b40 */ 	sll	$t7,$t6,0xd
/*  f183d30:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f183d34:	afb60044 */ 	sw	$s6,0x44($sp)
/*  f183d38:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f183d3c:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f183d40:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f183d44:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f183d48:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f183d4c:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f183d50:	05e10123 */ 	bgez	$t7,.L0f1841e0
/*  f183d54:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f183d58:	3c18800b */ 	lui	$t8,%hi(g_ScenarioData+0x13c)
/*  f183d5c:	8f18c24c */ 	lw	$t8,%lo(g_ScenarioData+0x13c)($t8)
/*  f183d60:	53000021 */ 	beqzl	$t8,.L0f183de8
/*  f183d64:	3c01437f */ 	lui	$at,0x437f
/*  f183d68:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f183d6c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f183d70:	1041001c */ 	beq	$v0,$at,.L0f183de4
/*  f183d74:	24010003 */ 	addiu	$at,$zero,0x3
/*  f183d78:	1041001a */ 	beq	$v0,$at,.L0f183de4
/*  f183d7c:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f183d80:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f183d84:	8ec20284 */ 	lw	$v0,0x284($s6)
/*  f183d88:	c7040008 */ 	lwc1	$f4,0x8($t8)
/*  f183d8c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f183d90:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f183d94:	03002825 */ 	or	$a1,$t8,$zero
/*  f183d98:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f183d9c:	c7260008 */ 	lwc1	$f6,0x8($t9)
/*  f183da0:	3c0700ff */ 	lui	$a3,0xff
/*  f183da4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f183da8:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f183dac:	8c4c00bc */ 	lw	$t4,0xbc($v0)
/*  f183db0:	c70a000c */ 	lwc1	$f10,0xc($t8)
/*  f183db4:	c590000c */ 	lwc1	$f16,0xc($t4)
/*  f183db8:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f183dbc:	e7b2009c */ 	swc1	$f18,0x9c($sp)
/*  f183dc0:	8c4d00bc */ 	lw	$t5,0xbc($v0)
/*  f183dc4:	c7040010 */ 	lwc1	$f4,0x10($t8)
/*  f183dc8:	c5a60010 */ 	lwc1	$f6,0x10($t5)
/*  f183dcc:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f183dd0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f183dd4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f183dd8:	0fc63a7b */ 	jal	radarDrawDot
/*  f183ddc:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*  f183de0:	00408825 */ 	or	$s1,$v0,$zero
.L0f183de4:
/*  f183de4:	3c01437f */ 	lui	$at,0x437f
.L0f183de8:
/*  f183de8:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f183dec:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f183df0:	3c158008 */ 	lui	$s5,%hi(g_TeamColours)
/*  f183df4:	3c14800b */ 	lui	$s4,%hi(g_ScenarioData+0xc)
/*  f183df8:	4481b000 */ 	mtc1	$at,$f22
/*  f183dfc:	4480a000 */ 	mtc1	$zero,$f20
/*  f183e00:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f183e04:	2694c11c */ 	addiu	$s4,$s4,%lo(g_ScenarioData+0xc)
/*  f183e08:	26b57cc4 */ 	addiu	$s5,$s5,%lo(g_TeamColours)
/*  f183e0c:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f183e10:	27b30088 */ 	addiu	$s3,$sp,0x88
/*  f183e14:	241200ff */ 	addiu	$s2,$zero,0xff
/*  f183e18:	8e030080 */ 	lw	$v1,0x80($s0)
.L0f183e1c:
/*  f183e1c:	506000ee */ 	beqzl	$v1,.L0f1841d8
/*  f183e20:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f183e24:	8ec20284 */ 	lw	$v0,0x284($s6)
/*  f183e28:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f183e2c:	8e190080 */ 	lw	$t9,0x80($s0)
/*  f183e30:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f183e34:	8e0d0080 */ 	lw	$t5,0x80($s0)
/*  f183e38:	92040086 */ 	lbu	$a0,0x86($s0)
/*  f183e3c:	c5f00008 */ 	lwc1	$f16,0x8($t7)
/*  f183e40:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f183e44:	e7b20088 */ 	swc1	$f18,0x88($sp)
/*  f183e48:	8c4c00bc */ 	lw	$t4,0xbc($v0)
/*  f183e4c:	c724000c */ 	lwc1	$f4,0xc($t9)
/*  f183e50:	c586000c */ 	lwc1	$f6,0xc($t4)
/*  f183e54:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f183e58:	e7a8008c */ 	swc1	$f8,0x8c($sp)
/*  f183e5c:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f183e60:	c5aa0010 */ 	lwc1	$f10,0x10($t5)
/*  f183e64:	c7100010 */ 	lwc1	$f16,0x10($t8)
/*  f183e68:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f183e6c:	16440006 */ 	bne	$s2,$a0,.L0f183e88
/*  f183e70:	e7b20090 */ 	swc1	$f18,0x90($sp)
/*  f183e74:	4600a006 */ 	mov.s	$f0,$f20
/*  f183e78:	4600b086 */ 	mov.s	$f2,$f22
/*  f183e7c:	4600a306 */ 	mov.s	$f12,$f20
/*  f183e80:	10000033 */ 	b	.L0f183f50
/*  f183e84:	4600a386 */ 	mov.s	$f14,$f20
.L0f183e88:
/*  f183e88:	8eee000c */ 	lw	$t6,0xc($s7)
/*  f183e8c:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f183e90:	51e0002c */ 	beqzl	$t7,.L0f183f44
/*  f183e94:	4600a006 */ 	mov.s	$f0,$f20
/*  f183e98:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f183e9c:	00000000 */ 	nop
/*  f183ea0:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f183ea4:	02b96021 */ 	addu	$t4,$s5,$t9
/*  f183ea8:	8d830000 */ 	lw	$v1,0x0($t4)
/*  f183eac:	3c014f80 */ 	lui	$at,0x4f80
/*  f183eb0:	00036e02 */ 	srl	$t5,$v1,0x18
/*  f183eb4:	31b800ff */ 	andi	$t8,$t5,0xff
/*  f183eb8:	44982000 */ 	mtc1	$t8,$f4
/*  f183ebc:	00037402 */ 	srl	$t6,$v1,0x10
/*  f183ec0:	07010004 */ 	bgez	$t8,.L0f183ed4
/*  f183ec4:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f183ec8:	44813000 */ 	mtc1	$at,$f6
/*  f183ecc:	00000000 */ 	nop
/*  f183ed0:	46060000 */ 	add.s	$f0,$f0,$f6
.L0f183ed4:
/*  f183ed4:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f183ed8:	448f4000 */ 	mtc1	$t7,$f8
/*  f183edc:	0003ca02 */ 	srl	$t9,$v1,0x8
/*  f183ee0:	05e10005 */ 	bgez	$t7,.L0f183ef8
/*  f183ee4:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f183ee8:	3c014f80 */ 	lui	$at,0x4f80
/*  f183eec:	44815000 */ 	mtc1	$at,$f10
/*  f183ef0:	00000000 */ 	nop
/*  f183ef4:	460a1080 */ 	add.s	$f2,$f2,$f10
.L0f183ef8:
/*  f183ef8:	332c00ff */ 	andi	$t4,$t9,0xff
/*  f183efc:	448c8000 */ 	mtc1	$t4,$f16
/*  f183f00:	306d00ff */ 	andi	$t5,$v1,0xff
/*  f183f04:	05810005 */ 	bgez	$t4,.L0f183f1c
/*  f183f08:	46808320 */ 	cvt.s.w	$f12,$f16
/*  f183f0c:	3c014f80 */ 	lui	$at,0x4f80
/*  f183f10:	44819000 */ 	mtc1	$at,$f18
/*  f183f14:	00000000 */ 	nop
/*  f183f18:	46126300 */ 	add.s	$f12,$f12,$f18
.L0f183f1c:
/*  f183f1c:	448d2000 */ 	mtc1	$t5,$f4
/*  f183f20:	3c014f80 */ 	lui	$at,0x4f80
/*  f183f24:	05a1000a */ 	bgez	$t5,.L0f183f50
/*  f183f28:	468023a0 */ 	cvt.s.w	$f14,$f4
/*  f183f2c:	44813000 */ 	mtc1	$at,$f6
/*  f183f30:	00000000 */ 	nop
/*  f183f34:	46067380 */ 	add.s	$f14,$f14,$f6
/*  f183f38:	10000006 */ 	b	.L0f183f54
/*  f183f3c:	4458f800 */ 	cfc1	$t8,$31
/*  f183f40:	4600a006 */ 	mov.s	$f0,$f20
.L0f183f44:
/*  f183f44:	4600b086 */ 	mov.s	$f2,$f22
/*  f183f48:	4600a306 */ 	mov.s	$f12,$f20
/*  f183f4c:	4600a386 */ 	mov.s	$f14,$f20
.L0f183f50:
/*  f183f50:	4458f800 */ 	cfc1	$t8,$31
.L0f183f54:
/*  f183f54:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f183f58:	44c2f800 */ 	ctc1	$v0,$31
/*  f183f5c:	3c014f00 */ 	lui	$at,0x4f00
/*  f183f60:	02603025 */ 	or	$a2,$s3,$zero
/*  f183f64:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f183f68:	4442f800 */ 	cfc1	$v0,$31
/*  f183f6c:	00000000 */ 	nop
/*  f183f70:	30420078 */ 	andi	$v0,$v0,0x78
/*  f183f74:	50400013 */ 	beqzl	$v0,.L0f183fc4
/*  f183f78:	44024000 */ 	mfc1	$v0,$f8
/*  f183f7c:	44814000 */ 	mtc1	$at,$f8
/*  f183f80:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f183f84:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f183f88:	44c2f800 */ 	ctc1	$v0,$31
/*  f183f8c:	00000000 */ 	nop
/*  f183f90:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f183f94:	4442f800 */ 	cfc1	$v0,$31
/*  f183f98:	00000000 */ 	nop
/*  f183f9c:	30420078 */ 	andi	$v0,$v0,0x78
/*  f183fa0:	14400005 */ 	bnez	$v0,.L0f183fb8
/*  f183fa4:	00000000 */ 	nop
/*  f183fa8:	44024000 */ 	mfc1	$v0,$f8
/*  f183fac:	3c018000 */ 	lui	$at,0x8000
/*  f183fb0:	10000007 */ 	b	.L0f183fd0
/*  f183fb4:	00411025 */ 	or	$v0,$v0,$at
.L0f183fb8:
/*  f183fb8:	10000005 */ 	b	.L0f183fd0
/*  f183fbc:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f183fc0:	44024000 */ 	mfc1	$v0,$f8
.L0f183fc4:
/*  f183fc4:	00000000 */ 	nop
/*  f183fc8:	0440fffb */ 	bltz	$v0,.L0f183fb8
/*  f183fcc:	00000000 */ 	nop
.L0f183fd0:
/*  f183fd0:	44d8f800 */ 	ctc1	$t8,$31
/*  f183fd4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f183fd8:	00404025 */ 	or	$t0,$v0,$zero
/*  f183fdc:	3c014f00 */ 	lui	$at,0x4f00
/*  f183fe0:	444ef800 */ 	cfc1	$t6,$31
/*  f183fe4:	44c3f800 */ 	ctc1	$v1,$31
/*  f183fe8:	00000000 */ 	nop
/*  f183fec:	460012a4 */ 	cvt.w.s	$f10,$f2
/*  f183ff0:	4443f800 */ 	cfc1	$v1,$31
/*  f183ff4:	00000000 */ 	nop
/*  f183ff8:	30630078 */ 	andi	$v1,$v1,0x78
/*  f183ffc:	50600013 */ 	beqzl	$v1,.L0f18404c
/*  f184000:	44035000 */ 	mfc1	$v1,$f10
/*  f184004:	44815000 */ 	mtc1	$at,$f10
/*  f184008:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f18400c:	460a1281 */ 	sub.s	$f10,$f2,$f10
/*  f184010:	44c3f800 */ 	ctc1	$v1,$31
/*  f184014:	00000000 */ 	nop
/*  f184018:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f18401c:	4443f800 */ 	cfc1	$v1,$31
/*  f184020:	00000000 */ 	nop
/*  f184024:	30630078 */ 	andi	$v1,$v1,0x78
/*  f184028:	14600005 */ 	bnez	$v1,.L0f184040
/*  f18402c:	00000000 */ 	nop
/*  f184030:	44035000 */ 	mfc1	$v1,$f10
/*  f184034:	3c018000 */ 	lui	$at,0x8000
/*  f184038:	10000007 */ 	b	.L0f184058
/*  f18403c:	00611825 */ 	or	$v1,$v1,$at
.L0f184040:
/*  f184040:	10000005 */ 	b	.L0f184058
/*  f184044:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f184048:	44035000 */ 	mfc1	$v1,$f10
.L0f18404c:
/*  f18404c:	00000000 */ 	nop
/*  f184050:	0460fffb */ 	bltz	$v1,.L0f184040
/*  f184054:	00000000 */ 	nop
.L0f184058:
/*  f184058:	44cef800 */ 	ctc1	$t6,$31
/*  f18405c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f184060:	00604825 */ 	or	$t1,$v1,$zero
/*  f184064:	3c014f00 */ 	lui	$at,0x4f00
/*  f184068:	444ff800 */ 	cfc1	$t7,$31
/*  f18406c:	44c4f800 */ 	ctc1	$a0,$31
/*  f184070:	00000000 */ 	nop
/*  f184074:	46006424 */ 	cvt.w.s	$f16,$f12
/*  f184078:	4444f800 */ 	cfc1	$a0,$31
/*  f18407c:	00000000 */ 	nop
/*  f184080:	30840078 */ 	andi	$a0,$a0,0x78
/*  f184084:	50800013 */ 	beqzl	$a0,.L0f1840d4
/*  f184088:	44048000 */ 	mfc1	$a0,$f16
/*  f18408c:	44818000 */ 	mtc1	$at,$f16
/*  f184090:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f184094:	46106401 */ 	sub.s	$f16,$f12,$f16
/*  f184098:	44c4f800 */ 	ctc1	$a0,$31
/*  f18409c:	00000000 */ 	nop
/*  f1840a0:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f1840a4:	4444f800 */ 	cfc1	$a0,$31
/*  f1840a8:	00000000 */ 	nop
/*  f1840ac:	30840078 */ 	andi	$a0,$a0,0x78
/*  f1840b0:	14800005 */ 	bnez	$a0,.L0f1840c8
/*  f1840b4:	00000000 */ 	nop
/*  f1840b8:	44048000 */ 	mfc1	$a0,$f16
/*  f1840bc:	3c018000 */ 	lui	$at,0x8000
/*  f1840c0:	10000007 */ 	b	.L0f1840e0
/*  f1840c4:	00812025 */ 	or	$a0,$a0,$at
.L0f1840c8:
/*  f1840c8:	10000005 */ 	b	.L0f1840e0
/*  f1840cc:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f1840d0:	44048000 */ 	mfc1	$a0,$f16
.L0f1840d4:
/*  f1840d4:	00000000 */ 	nop
/*  f1840d8:	0480fffb */ 	bltz	$a0,.L0f1840c8
/*  f1840dc:	00000000 */ 	nop
.L0f1840e0:
/*  f1840e0:	44cff800 */ 	ctc1	$t7,$31
/*  f1840e4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1840e8:	00805025 */ 	or	$t2,$a0,$zero
/*  f1840ec:	3c014f00 */ 	lui	$at,0x4f00
/*  f1840f0:	4459f800 */ 	cfc1	$t9,$31
/*  f1840f4:	44c5f800 */ 	ctc1	$a1,$31
/*  f1840f8:	00000000 */ 	nop
/*  f1840fc:	460074a4 */ 	cvt.w.s	$f18,$f14
/*  f184100:	4445f800 */ 	cfc1	$a1,$31
/*  f184104:	00000000 */ 	nop
/*  f184108:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f18410c:	50a00013 */ 	beqzl	$a1,.L0f18415c
/*  f184110:	44059000 */ 	mfc1	$a1,$f18
/*  f184114:	44819000 */ 	mtc1	$at,$f18
/*  f184118:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f18411c:	46127481 */ 	sub.s	$f18,$f14,$f18
/*  f184120:	44c5f800 */ 	ctc1	$a1,$31
/*  f184124:	00000000 */ 	nop
/*  f184128:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f18412c:	4445f800 */ 	cfc1	$a1,$31
/*  f184130:	00000000 */ 	nop
/*  f184134:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f184138:	14a00005 */ 	bnez	$a1,.L0f184150
/*  f18413c:	00000000 */ 	nop
/*  f184140:	44059000 */ 	mfc1	$a1,$f18
/*  f184144:	3c018000 */ 	lui	$at,0x8000
/*  f184148:	10000007 */ 	b	.L0f184168
/*  f18414c:	00a12825 */ 	or	$a1,$a1,$at
.L0f184150:
/*  f184150:	10000005 */ 	b	.L0f184168
/*  f184154:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f184158:	44059000 */ 	mfc1	$a1,$f18
.L0f18415c:
/*  f18415c:	00000000 */ 	nop
/*  f184160:	04a0fffb */ 	bltz	$a1,.L0f184150
/*  f184164:	00000000 */ 	nop
.L0f184168:
/*  f184168:	44d9f800 */ 	ctc1	$t9,$31
/*  f18416c:	2c410100 */ 	sltiu	$at,$v0,0x100
/*  f184170:	14200002 */ 	bnez	$at,.L0f18417c
/*  f184174:	00a05825 */ 	or	$t3,$a1,$zero
/*  f184178:	240800ff */ 	addiu	$t0,$zero,0xff
.L0f18417c:
/*  f18417c:	2c610100 */ 	sltiu	$at,$v1,0x100
/*  f184180:	14200002 */ 	bnez	$at,.L0f18418c
/*  f184184:	00086600 */ 	sll	$t4,$t0,0x18
/*  f184188:	240900ff */ 	addiu	$t1,$zero,0xff
.L0f18418c:
/*  f18418c:	2c810100 */ 	sltiu	$at,$a0,0x100
/*  f184190:	14200002 */ 	bnez	$at,.L0f18419c
/*  f184194:	02202025 */ 	or	$a0,$s1,$zero
/*  f184198:	240a00ff */ 	addiu	$t2,$zero,0xff
.L0f18419c:
/*  f18419c:	2ca10100 */ 	sltiu	$at,$a1,0x100
/*  f1841a0:	14200002 */ 	bnez	$at,.L0f1841ac
/*  f1841a4:	00096c00 */ 	sll	$t5,$t1,0x10
/*  f1841a8:	240b00ff */ 	addiu	$t3,$zero,0xff
.L0f1841ac:
/*  f1841ac:	018dc025 */ 	or	$t8,$t4,$t5
/*  f1841b0:	000a7200 */ 	sll	$t6,$t2,0x8
/*  f1841b4:	030e7825 */ 	or	$t7,$t8,$t6
/*  f1841b8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f1841bc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1841c0:	01eb3825 */ 	or	$a3,$t7,$t3
/*  f1841c4:	8e050080 */ 	lw	$a1,0x80($s0)
/*  f1841c8:	0fc63a7b */ 	jal	radarDrawDot
/*  f1841cc:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1841d0:	00408825 */ 	or	$s1,$v0,$zero
/*  f1841d4:	2610000c */ 	addiu	$s0,$s0,0xc
.L0f1841d8:
/*  f1841d8:	5614ff10 */ 	bnel	$s0,$s4,.L0f183e1c
/*  f1841dc:	8e030080 */ 	lw	$v1,0x80($s0)
.L0f1841e0:
/*  f1841e0:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f1841e4:	02201025 */ 	or	$v0,$s1,$zero
/*  f1841e8:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f1841ec:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f1841f0:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f1841f4:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f1841f8:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f1841fc:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f184200:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f184204:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f184208:	8fb60044 */ 	lw	$s6,0x44($sp)
/*  f18420c:	8fb70048 */ 	lw	$s7,0x48($sp)
/*  f184210:	03e00008 */ 	jr	$ra
/*  f184214:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

bool scenarioHtmRadar2(Gfx **gdl, struct prop *prop)
{
	if ((g_MpSetup.options & MPOPTION_HTM_SHOWONRADAR) && g_ScenarioData.htm.uplink) {
		if (prop == g_ScenarioData.htm.uplink &&
				(prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR)) {
			struct coord dist;
			dist.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
			dist.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
			dist.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;

			if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				u32 colour = g_TeamColours[radarGetTeamIndex(prop->chr->team)];
				*gdl = radarDrawDot(*gdl, g_ScenarioData.htm.uplink, &dist, colour, 0, 1);
			} else {
				*gdl = radarDrawDot(*gdl, g_ScenarioData.htm.uplink, &dist, 0xff0000, 0, 1);
			}

			return true;
		}
	}

	return false;
}

bool scenarioHtmHighlight(struct prop *prop, u32 *colour)
{
	if (g_MpSetup.options & MPOPTION_HTM_HIGHLIGHTTERMINAL) {
		bool highlight = false;

		if (prop == g_ScenarioData.htm.uplink) {
			highlight = true;
		} else {
			s32 i;

			for (i = 0; i < 1; i++) {
				if (g_ScenarioData.htm.unk07c[i].prop == prop) {
					highlight = true;
					break;
				}
			}
		}

		if (highlight) {
			colour[0] = 0;
			colour[1] = 0xff;
			colour[2] = 0;
			colour[3] = 0x40;

			return true;
		}
	}

	return false;
}

GLOBAL_ASM(
glabel scenarioPacChooseVictims
/*  f1843d4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f1843d8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1843dc:	3c14800b */ 	lui	$s4,%hi(g_ScenarioData)
/*  f1843e0:	2694c110 */ 	addiu	$s4,$s4,%lo(g_ScenarioData)
/*  f1843e4:	240effff */ 	addiu	$t6,$zero,-1
/*  f1843e8:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f1843ec:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData+0x18)
/*  f1843f0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1843f4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1843f8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1843fc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f184400:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f184404:	ae8e0004 */ 	sw	$t6,0x4($s4)
/*  f184408:	a6800002 */ 	sh	$zero,0x2($s4)
/*  f18440c:	2463c128 */ 	addiu	$v1,$v1,%lo(g_ScenarioData+0x18)
/*  f184410:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
.L0f184414:
/*  f184414:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f184418:	a440001e */ 	sh	$zero,0x1e($v0)
/*  f18441c:	1443fffd */ 	bne	$v0,$v1,.L0f184414
/*  f184420:	a4400036 */ 	sh	$zero,0x36($v0)
/*  f184424:	3c13800b */ 	lui	$s3,%hi(g_MpNumPlayers)
/*  f184428:	2673c530 */ 	addiu	$s3,$s3,%lo(g_MpNumPlayers)
/*  f18442c:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f184430:	00008825 */ 	or	$s1,$zero,$zero
/*  f184434:	1880001f */ 	blez	$a0,.L0f1844b4
/*  f184438:	00008025 */ 	or	$s0,$zero,$zero
.L0f18443c:
/*  f18443c:	0c004b70 */ 	jal	random
/*  f184440:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f184444:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f184448:	0011c040 */ 	sll	$t8,$s1,0x1
/*  f18444c:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f184450:	0044001b */ 	divu	$zero,$v0,$a0
/*  f184454:	00001810 */ 	mfhi	$v1
/*  f184458:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f18445c:	14800002 */ 	bnez	$a0,.L0f184468
/*  f184460:	00000000 */ 	nop
/*  f184464:	0007000d */ 	break	0x7
.L0f184468:
/*  f184468:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f18446c:	1a200009 */ 	blez	$s1,.L0f184494
/*  f184470:	00000000 */ 	nop
.L0f184474:
/*  f184474:	844f0008 */ 	lh	$t7,0x8($v0)
/*  f184478:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18447c:	146f0003 */ 	bne	$v1,$t7,.L0f18448c
/*  f184480:	00000000 */ 	nop
/*  f184484:	10000003 */ 	b	.L0f184494
/*  f184488:	00009025 */ 	or	$s2,$zero,$zero
.L0f18448c:
/*  f18448c:	1611fff9 */ 	bne	$s0,$s1,.L0f184474
/*  f184490:	24420002 */ 	addiu	$v0,$v0,0x2
.L0f184494:
/*  f184494:	52400005 */ 	beqzl	$s2,.L0f1844ac
/*  f184498:	0224082a */ 	slt	$at,$s1,$a0
/*  f18449c:	a7230008 */ 	sh	$v1,0x8($t9)
/*  f1844a0:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f1844a4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1844a8:	0224082a */ 	slt	$at,$s1,$a0
.L0f1844ac:
/*  f1844ac:	5420ffe3 */ 	bnezl	$at,.L0f18443c
/*  f1844b0:	00008025 */ 	or	$s0,$zero,$zero
.L0f1844b4:
/*  f1844b4:	18800005 */ 	blez	$a0,.L0f1844cc
/*  f1844b8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1844bc:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1844c0:
/*  f1844c0:	0204082a */ 	slt	$at,$s0,$a0
/*  f1844c4:	5420fffe */ 	bnezl	$at,.L0f1844c0
/*  f1844c8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1844cc:
/*  f1844cc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1844d0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1844d4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1844d8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1844dc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1844e0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1844e4:	03e00008 */ 	jr	$ra
/*  f1844e8:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

//void scenarioPacChooseVictims(void)
//{
//	s32 i;
//	s32 j;
//
//	g_ScenarioData.pac.unk04 = -1;
//	g_ScenarioData.pac.unk02 = 0;
//
//	for (i = 0; i != MAX_MPCHRS; i++) {
//		g_ScenarioData.pac.unk20[i] = 0;
//		g_ScenarioData.pac.unk34[i] = 0;
//	}
//
//	i = 0;
//
//	while (i < g_MpNumPlayers) {
//		bool isnew = true;
//		s32 victimplayernum = random() % g_MpNumPlayers;
//
//		for (j = 0; j < i; j++) {
//			if (g_ScenarioData.pac.victims[j] == victimplayernum) {
//				isnew = false;
//				break;
//			}
//		}
//
//		if (isnew) {
//			g_ScenarioData.pac.victims[i] = victimplayernum;
//			i++;
//		}
//	}
//
//	for (i = 0; i < g_MpNumPlayers; i++) {
//		// This loop probably printed debug messages
//	}
//}

void scenarioPacInit(void)
{
	scenarioPacChooseVictims();
}

void scenarioPacReset(void)
{
	scenarioPacChooseVictims();
}

GLOBAL_ASM(
glabel scenarioPacHighlight
/*  f18452c:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup+0xc)
/*  f184530:	8dcecb94 */ 	lw	$t6,%lo(g_MpSetup+0xc)($t6)
/*  f184534:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f184538:	05e3001e */ 	bgezl	$t7,.L0f1845b4
/*  f18453c:	00001025 */ 	or	$v0,$zero,$zero
/*  f184540:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f184544:	24010006 */ 	addiu	$at,$zero,0x6
/*  f184548:	3c18800b */ 	lui	$t8,%hi(g_ScenarioData+0x4)
/*  f18454c:	10410003 */ 	beq	$v0,$at,.L0f18455c
/*  f184550:	24010003 */ 	addiu	$at,$zero,0x3
/*  f184554:	54410017 */ 	bnel	$v0,$at,.L0f1845b4
/*  f184558:	00001025 */ 	or	$v0,$zero,$zero
.L0f18455c:
/*  f18455c:	8f18c114 */ 	lw	$t8,%lo(g_ScenarioData+0x4)($t8)
/*  f184560:	2401ffff */ 	addiu	$at,$zero,-1
/*  f184564:	3c09800b */ 	lui	$t1,%hi(g_ScenarioData+0x8)
/*  f184568:	13010011 */ 	beq	$t8,$at,.L0f1845b0
/*  f18456c:	00184040 */ 	sll	$t0,$t8,0x1
/*  f184570:	01284821 */ 	addu	$t1,$t1,$t0
/*  f184574:	8529c118 */ 	lh	$t1,%lo(g_ScenarioData+0x8)($t1)
/*  f184578:	3c0b800b */ 	lui	$t3,%hi(g_MpPlayerChrs)
/*  f18457c:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f184580:	00095080 */ 	sll	$t2,$t1,0x2
/*  f184584:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f184588:	8d6bc4d0 */ 	lw	$t3,%lo(g_MpPlayerChrs)($t3)
/*  f18458c:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f184590:	240d0040 */ 	addiu	$t5,$zero,0x40
/*  f184594:	172b0006 */ 	bne	$t9,$t3,.L0f1845b0
/*  f184598:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f18459c:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f1845a0:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f1845a4:	aca00008 */ 	sw	$zero,0x8($a1)
/*  f1845a8:	03e00008 */ 	jr	$ra
/*  f1845ac:	acad000c */ 	sw	$t5,0xc($a1)
.L0f1845b0:
/*  f1845b0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1845b4:
/*  f1845b4:	03e00008 */ 	jr	$ra
/*  f1845b8:	00000000 */ 	nop
);

//bool scenarioPacHighlight(struct prop *prop, u32 *colour)
//{
//	if ((g_MpSetup.options & MPOPTION_PAC_HIGHLIGHTTARGET) &&
//			(prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR) &&
//			g_ScenarioData.pac.victimindex != -1 &&
//			prop->chr == g_MpPlayerChrs[g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex]]) {
//		colour[0] = 0;
//		colour[1] = 0xff;
//		colour[2] = 0;
//		colour[3] = 0x40;
//
//		return true;
//	}
//
//	return false;
//}

GLOBAL_ASM(
glabel func0f1845bc
/*  f1845bc:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f1845c0:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f1845c4:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*  f1845c8:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f1845cc:	3c18800b */ 	lui	$t8,%hi(g_MpNumPlayers)
/*  f1845d0:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f1845d4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f1845d8:	8f18c530 */ 	lw	$t8,%lo(g_MpNumPlayers)($t8)
/*  f1845dc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1845e0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1845e4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1845e8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1845ec:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1845f0:	170f0003 */ 	bne	$t8,$t7,.L0f184600
/*  f1845f4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1845f8:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x4)
/*  f1845fc:	ac20c114 */ 	sw	$zero,%lo(g_ScenarioData+0x4)($at)
.L0f184600:
/*  f184600:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x2)
/*  f184604:	a420c112 */ 	sh	$zero,%lo(g_ScenarioData+0x2)($at)
/*  f184608:	3c08800b */ 	lui	$t0,%hi(g_ScenarioData+0x4)
/*  f18460c:	8d08c114 */ 	lw	$t0,%lo(g_ScenarioData+0x4)($t0)
/*  f184610:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f184614:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f184618:	8e6b006c */ 	lw	$t3,0x6c($s3)
/*  f18461c:	00084840 */ 	sll	$t1,$t0,0x1
/*  f184620:	00495021 */ 	addu	$t2,$v0,$t1
/*  f184624:	85540008 */ 	lh	$s4,0x8($t2)
/*  f184628:	11600003 */ 	beqz	$t3,.L0f184638
/*  f18462c:	00008825 */ 	or	$s1,$zero,$zero
/*  f184630:	10000002 */ 	b	.L0f18463c
/*  f184634:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f184638:
/*  f184638:	00002825 */ 	or	$a1,$zero,$zero
.L0f18463c:
/*  f18463c:	8e6c0068 */ 	lw	$t4,0x68($s3)
/*  f184640:	00002025 */ 	or	$a0,$zero,$zero
/*  f184644:	00001825 */ 	or	$v1,$zero,$zero
/*  f184648:	11800003 */ 	beqz	$t4,.L0f184658
/*  f18464c:	00001025 */ 	or	$v0,$zero,$zero
/*  f184650:	10000001 */ 	b	.L0f184658
/*  f184654:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f184658:
/*  f184658:	8e6d0064 */ 	lw	$t5,0x64($s3)
/*  f18465c:	27b20048 */ 	addiu	$s2,$sp,0x48
/*  f184660:	11a00003 */ 	beqz	$t5,.L0f184670
/*  f184664:	00000000 */ 	nop
/*  f184668:	10000001 */ 	b	.L0f184670
/*  f18466c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f184670:
/*  f184670:	8e6e0070 */ 	lw	$t6,0x70($s3)
/*  f184674:	11c00003 */ 	beqz	$t6,.L0f184684
/*  f184678:	00000000 */ 	nop
/*  f18467c:	10000001 */ 	b	.L0f184684
/*  f184680:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f184684:
/*  f184684:	00437821 */ 	addu	$t7,$v0,$v1
/*  f184688:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f18468c:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f184690:	5b200042 */ 	blezl	$t9,.L0f18479c
/*  f184694:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f184698:
/*  f184698:	16910008 */ 	bne	$s4,$s1,.L0f1846bc
/*  f18469c:	02802025 */ 	or	$a0,$s4,$zero
/*  f1846a0:	0fc5b9f1 */ 	jal	langGet
/*  f1846a4:	2404540d */ 	addiu	$a0,$zero,0x540d
/*  f1846a8:	02402025 */ 	or	$a0,$s2,$zero
/*  f1846ac:	0c004dad */ 	jal	sprintf
/*  f1846b0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1846b4:	10000018 */ 	b	.L0f184718
/*  f1846b8:	02202025 */ 	or	$a0,$s1,$zero
.L0f1846bc:
/*  f1846bc:	3c09800b */ 	lui	$t1,%hi(var800ac500)
/*  f1846c0:	2529c500 */ 	addiu	$t1,$t1,%lo(var800ac500)
/*  f1846c4:	00144080 */ 	sll	$t0,$s4,0x2
/*  f1846c8:	01098021 */ 	addu	$s0,$t0,$t1
/*  f1846cc:	0fc619e0 */ 	jal	func0f186780
/*  f1846d0:	02202825 */ 	or	$a1,$s1,$zero
/*  f1846d4:	10400009 */ 	beqz	$v0,.L0f1846fc
/*  f1846d8:	00000000 */ 	nop
/*  f1846dc:	0fc5b9f1 */ 	jal	langGet
/*  f1846e0:	2404540e */ 	addiu	$a0,$zero,0x540e
/*  f1846e4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1846e8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1846ec:	0c004dad */ 	jal	sprintf
/*  f1846f0:	8e060000 */ 	lw	$a2,0x0($s0)
/*  f1846f4:	10000008 */ 	b	.L0f184718
/*  f1846f8:	02202025 */ 	or	$a0,$s1,$zero
.L0f1846fc:
/*  f1846fc:	0fc5b9f1 */ 	jal	langGet
/*  f184700:	2404540f */ 	addiu	$a0,$zero,0x540f
/*  f184704:	02402025 */ 	or	$a0,$s2,$zero
/*  f184708:	00402825 */ 	or	$a1,$v0,$zero
/*  f18470c:	0c004dad */ 	jal	sprintf
/*  f184710:	8e060000 */ 	lw	$a2,0x0($s0)
/*  f184714:	02202025 */ 	or	$a0,$s1,$zero
.L0f184718:
/*  f184718:	0fc619ae */ 	jal	func0f1866b8
/*  f18471c:	02402825 */ 	or	$a1,$s2,$zero
/*  f184720:	8e6a006c */ 	lw	$t2,0x6c($s3)
/*  f184724:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f184728:	00002825 */ 	or	$a1,$zero,$zero
/*  f18472c:	11400003 */ 	beqz	$t2,.L0f18473c
/*  f184730:	00002025 */ 	or	$a0,$zero,$zero
/*  f184734:	10000001 */ 	b	.L0f18473c
/*  f184738:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f18473c:
/*  f18473c:	8e6b0068 */ 	lw	$t3,0x68($s3)
/*  f184740:	00001825 */ 	or	$v1,$zero,$zero
/*  f184744:	00001025 */ 	or	$v0,$zero,$zero
/*  f184748:	11600003 */ 	beqz	$t3,.L0f184758
/*  f18474c:	00000000 */ 	nop
/*  f184750:	10000001 */ 	b	.L0f184758
/*  f184754:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f184758:
/*  f184758:	8e6c0064 */ 	lw	$t4,0x64($s3)
/*  f18475c:	11800003 */ 	beqz	$t4,.L0f18476c
/*  f184760:	00000000 */ 	nop
/*  f184764:	10000001 */ 	b	.L0f18476c
/*  f184768:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f18476c:
/*  f18476c:	8e6d0070 */ 	lw	$t5,0x70($s3)
/*  f184770:	11a00003 */ 	beqz	$t5,.L0f184780
/*  f184774:	00000000 */ 	nop
/*  f184778:	10000001 */ 	b	.L0f184780
/*  f18477c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f184780:
/*  f184780:	00437021 */ 	addu	$t6,$v0,$v1
/*  f184784:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f184788:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f18478c:	0238082a */ 	slt	$at,$s1,$t8
/*  f184790:	1420ffc1 */ 	bnez	$at,.L0f184698
/*  f184794:	00000000 */ 	nop
/*  f184798:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f18479c:
/*  f18479c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1847a0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1847a4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1847a8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1847ac:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1847b0:	03e00008 */ 	jr	$ra
/*  f1847b4:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0f1847b8
/*  f1847b8:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f1847bc:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f1847c0:	8c6e0004 */ 	lw	$t6,0x4($v1)
/*  f1847c4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1847c8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1847cc:	00808025 */ 	or	$s0,$a0,$zero
/*  f1847d0:	05c00036 */ 	bltz	$t6,.L0f1848ac
/*  f1847d4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1847d8:	3c0f800b */ 	lui	$t7,%hi(g_ScenarioData+0x4)
/*  f1847dc:	8defc114 */ 	lw	$t7,%lo(g_ScenarioData+0x4)($t7)
/*  f1847e0:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f1847e4:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f1847e8:	87280008 */ 	lh	$t0,0x8($t9)
/*  f1847ec:	54a80030 */ 	bnel	$a1,$t0,.L0f1848b0
/*  f1847f0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1847f4:	1085002c */ 	beq	$a0,$a1,.L0f1848a8
/*  f1847f8:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x2)
/*  f1847fc:	04800026 */ 	bltz	$a0,.L0f184898
/*  f184800:	00000000 */ 	nop
/*  f184804:	0fc619e0 */ 	jal	func0f186780
/*  f184808:	00000000 */ 	nop
/*  f18480c:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f184810:	1040000d */ 	beqz	$v0,.L0f184848
/*  f184814:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f184818:	0fc5b9f1 */ 	jal	langGet
/*  f18481c:	24045408 */ 	addiu	$a0,$zero,0x5408
/*  f184820:	02002025 */ 	or	$a0,$s0,$zero
/*  f184824:	0fc619ae */ 	jal	func0f1866b8
/*  f184828:	00402825 */ 	or	$a1,$v0,$zero
/*  f18482c:	0fc5b9f1 */ 	jal	langGet
/*  f184830:	24045409 */ 	addiu	$a0,$zero,0x5409
/*  f184834:	02002025 */ 	or	$a0,$s0,$zero
/*  f184838:	0fc619ae */ 	jal	func0f1866b8
/*  f18483c:	00402825 */ 	or	$a1,$v0,$zero
/*  f184840:	10000015 */ 	b	.L0f184898
/*  f184844:	00000000 */ 	nop
.L0f184848:
/*  f184848:	00104840 */ 	sll	$t1,$s0,0x1
/*  f18484c:	00691021 */ 	addu	$v0,$v1,$t1
/*  f184850:	844a0020 */ 	lh	$t2,0x20($v0)
/*  f184854:	2404540a */ 	addiu	$a0,$zero,0x540a
/*  f184858:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f18485c:	0fc5b9f1 */ 	jal	langGet
/*  f184860:	a44b0020 */ 	sh	$t3,0x20($v0)
/*  f184864:	02002025 */ 	or	$a0,$s0,$zero
/*  f184868:	0fc619ae */ 	jal	func0f1866b8
/*  f18486c:	00402825 */ 	or	$a1,$v0,$zero
/*  f184870:	0fc5b9f1 */ 	jal	langGet
/*  f184874:	2404540b */ 	addiu	$a0,$zero,0x540b
/*  f184878:	02002025 */ 	or	$a0,$s0,$zero
/*  f18487c:	0fc619ae */ 	jal	func0f1866b8
/*  f184880:	00402825 */ 	or	$a1,$v0,$zero
/*  f184884:	0fc5b9f1 */ 	jal	langGet
/*  f184888:	2404540c */ 	addiu	$a0,$zero,0x540c
/*  f18488c:	02002025 */ 	or	$a0,$s0,$zero
/*  f184890:	0fc619ae */ 	jal	func0f1866b8
/*  f184894:	00402825 */ 	or	$a1,$v0,$zero
.L0f184898:
/*  f184898:	0fc6116f */ 	jal	func0f1845bc
/*  f18489c:	00000000 */ 	nop
/*  f1848a0:	10000003 */ 	b	.L0f1848b0
/*  f1848a4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f1848a8:
/*  f1848a8:	a420c112 */ 	sh	$zero,%lo(g_ScenarioData+0x2)($at)
.L0f1848ac:
/*  f1848ac:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f1848b0:
/*  f1848b0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1848b4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1848b8:	03e00008 */ 	jr	$ra
/*  f1848bc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel scenarioPacCallback10
/*  f1848c0:	3c09800b */ 	lui	$t1,%hi(g_ScenarioData)
/*  f1848c4:	2529c110 */ 	addiu	$t1,$t1,%lo(g_ScenarioData)
/*  f1848c8:	8d2e0004 */ 	lw	$t6,0x4($t1)
/*  f1848cc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1848d0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1848d4:	15c10005 */ 	bne	$t6,$at,.L0f1848ec
/*  f1848d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1848dc:	0fc6116f */ 	jal	func0f1845bc
/*  f1848e0:	00000000 */ 	nop
/*  f1848e4:	3c09800b */ 	lui	$t1,%hi(g_ScenarioData)
/*  f1848e8:	2529c110 */ 	addiu	$t1,$t1,%lo(g_ScenarioData)
.L0f1848ec:
/*  f1848ec:	3c0f800b */ 	lui	$t7,%hi(g_ScenarioData+0x4)
/*  f1848f0:	8defc114 */ 	lw	$t7,%lo(g_ScenarioData+0x4)($t7)
/*  f1848f4:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f1848f8:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f1848fc:	05e00042 */ 	bltz	$t7,.L0f184a08
/*  f184900:	3c0c800b */ 	lui	$t4,%hi(g_ScenarioData+0x4)
/*  f184904:	8cf8006c */ 	lw	$t8,0x6c($a3)
/*  f184908:	00004025 */ 	or	$t0,$zero,$zero
/*  f18490c:	00002825 */ 	or	$a1,$zero,$zero
/*  f184910:	13000003 */ 	beqz	$t8,.L0f184920
/*  f184914:	00003025 */ 	or	$a2,$zero,$zero
/*  f184918:	10000001 */ 	b	.L0f184920
/*  f18491c:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f184920:
/*  f184920:	8cf90068 */ 	lw	$t9,0x68($a3)
/*  f184924:	00001025 */ 	or	$v0,$zero,$zero
/*  f184928:	13200003 */ 	beqz	$t9,.L0f184938
/*  f18492c:	00000000 */ 	nop
/*  f184930:	10000001 */ 	b	.L0f184938
/*  f184934:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f184938:
/*  f184938:	8cea0064 */ 	lw	$t2,0x64($a3)
/*  f18493c:	11400003 */ 	beqz	$t2,.L0f18494c
/*  f184940:	00000000 */ 	nop
/*  f184944:	10000001 */ 	b	.L0f18494c
/*  f184948:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f18494c:
/*  f18494c:	8ceb0070 */ 	lw	$t3,0x70($a3)
/*  f184950:	11600003 */ 	beqz	$t3,.L0f184960
/*  f184954:	00000000 */ 	nop
/*  f184958:	10000001 */ 	b	.L0f184960
/*  f18495c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f184960:
/*  f184960:	8d8cc114 */ 	lw	$t4,%lo(g_ScenarioData+0x4)($t4)
/*  f184964:	00467021 */ 	addu	$t6,$v0,$a2
/*  f184968:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f18496c:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f184970:	012d1821 */ 	addu	$v1,$t1,$t5
/*  f184974:	84640008 */ 	lh	$a0,0x8($v1)
/*  f184978:	01e8c021 */ 	addu	$t8,$t7,$t0
/*  f18497c:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData+0x2)
/*  f184980:	0098082a */ 	slt	$at,$a0,$t8
/*  f184984:	10200006 */ 	beqz	$at,.L0f1849a0
/*  f184988:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f18498c:	00f95021 */ 	addu	$t2,$a3,$t9
/*  f184990:	8d4b0064 */ 	lw	$t3,0x64($t2)
/*  f184994:	8d6c00d8 */ 	lw	$t4,0xd8($t3)
/*  f184998:	5580001c */ 	bnezl	$t4,.L0f184a0c
/*  f18499c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1849a0:
/*  f1849a0:	9442c112 */ 	lhu	$v0,%lo(g_ScenarioData+0x2)($v0)
/*  f1849a4:	8ced0034 */ 	lw	$t5,0x34($a3)
/*  f1849a8:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x2)
/*  f1849ac:	004d1021 */ 	addu	$v0,$v0,$t5
/*  f1849b0:	304effff */ 	andi	$t6,$v0,0xffff
/*  f1849b4:	a42ec112 */ 	sh	$t6,%lo(g_ScenarioData+0x2)($at)
/*  f1849b8:	2dc13841 */ 	sltiu	$at,$t6,0x3841
/*  f1849bc:	14200012 */ 	bnez	$at,.L0f184a08
/*  f1849c0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x2)
/*  f1849c4:	a420c112 */ 	sh	$zero,%lo(g_ScenarioData+0x2)($at)
/*  f1849c8:	846f0008 */ 	lh	$t7,0x8($v1)
/*  f1849cc:	24045407 */ 	addiu	$a0,$zero,0x5407
/*  f1849d0:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f1849d4:	01381021 */ 	addu	$v0,$t1,$t8
/*  f1849d8:	84590038 */ 	lh	$t9,0x38($v0)
/*  f1849dc:	272a0001 */ 	addiu	$t2,$t9,0x1
/*  f1849e0:	0fc5b9f1 */ 	jal	langGet
/*  f1849e4:	a44a0038 */ 	sh	$t2,0x38($v0)
/*  f1849e8:	3c0b800b */ 	lui	$t3,%hi(g_ScenarioData+0x4)
/*  f1849ec:	8d6bc114 */ 	lw	$t3,%lo(g_ScenarioData+0x4)($t3)
/*  f1849f0:	3c04800b */ 	lui	$a0,%hi(g_ScenarioData+0x8)
/*  f1849f4:	00402825 */ 	or	$a1,$v0,$zero
/*  f1849f8:	000b6040 */ 	sll	$t4,$t3,0x1
/*  f1849fc:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f184a00:	0fc619ae */ 	jal	func0f1866b8
/*  f184a04:	8484c118 */ 	lh	$a0,%lo(g_ScenarioData+0x8)($a0)
.L0f184a08:
/*  f184a08:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f184a0c:
/*  f184a0c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f184a10:	03e00008 */ 	jr	$ra
/*  f184a14:	00000000 */ 	nop
);

//void scenarioPacCallback10(void)
//{
//	if (g_ScenarioData.pac.victimindex == -1) {
//		func0f1845bc();
//	}
//
//	if (g_ScenarioData.pac.victimindex >= 0) {
//		if (PLAYERCOUNT() <= g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex] ||
//				g_Vars.players[g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex]]->isdead == false) {
//			g_ScenarioData.pac.age240 += g_Vars.lvupdate240;
//
//			if (g_ScenarioData.pac.age240 > SECSTOTIME240(60)) {
//				g_ScenarioData.pac.age240 = 0;
//				g_ScenarioData.pac.wincounts[g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex]]++;
//				func0f1866b8(g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex], langGet(L_MPWEAPONS(7))); // "Have a point for living!"
//			}
//		}
//	}
//}

GLOBAL_ASM(
glabel scenarioPacCallback18
/*  f184a18:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f184a1c:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f184a20:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f184a24:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f184a28:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f184a2c:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f184a30:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f184a34:	87290008 */ 	lh	$t1,0x8($t9)
/*  f184a38:	8c6e028c */ 	lw	$t6,0x28c($v1)
/*  f184a3c:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f184a40:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f184a44:	00808025 */ 	or	$s0,$a0,$zero
/*  f184a48:	15c9006e */ 	bne	$t6,$t1,.L0f184c04
/*  f184a4c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f184a50:	8c6a0284 */ 	lw	$t2,0x284($v1)
/*  f184a54:	3c0c800b */ 	lui	$t4,%hi(g_ScenarioData+0x2)
/*  f184a58:	8d4b00d8 */ 	lw	$t3,0xd8($t2)
/*  f184a5c:	5560006a */ 	bnezl	$t3,.L0f184c08
/*  f184a60:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f184a64:	958cc112 */ 	lhu	$t4,%lo(g_ScenarioData+0x2)($t4)
/*  f184a68:	240d3840 */ 	addiu	$t5,$zero,0x3840
/*  f184a6c:	01ac1823 */ 	subu	$v1,$t5,$t4
/*  f184a70:	0c002f40 */ 	jal	viGetViewLeft
/*  f184a74:	afa300a0 */ 	sw	$v1,0xa0($sp)
/*  f184a78:	0c002f22 */ 	jal	viGetViewWidth
/*  f184a7c:	a7a20046 */ 	sh	$v0,0x46($sp)
/*  f184a80:	87b80046 */ 	lh	$t8,0x46($sp)
/*  f184a84:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f184a88:	04410003 */ 	bgez	$v0,.L0f184a98
/*  f184a8c:	00027843 */ 	sra	$t7,$v0,0x1
/*  f184a90:	24410001 */ 	addiu	$at,$v0,0x1
/*  f184a94:	00017843 */ 	sra	$t7,$at,0x1
.L0f184a98:
/*  f184a98:	01f82821 */ 	addu	$a1,$t7,$t8
/*  f184a9c:	0c002f44 */ 	jal	viGetViewTop
/*  f184aa0:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f184aa4:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f184aa8:	2446000a */ 	addiu	$a2,$v0,0xa
/*  f184aac:	afa60088 */ 	sw	$a2,0x88($sp)
/*  f184ab0:	04610002 */ 	bgez	$v1,.L0f184abc
/*  f184ab4:	24083840 */ 	addiu	$t0,$zero,0x3840
/*  f184ab8:	00001825 */ 	or	$v1,$zero,$zero
.L0f184abc:
/*  f184abc:	0068001a */ 	div	$zero,$v1,$t0
/*  f184ac0:	00001012 */ 	mflo	$v0
/*  f184ac4:	3c057f1c */ 	lui	$a1,%hi(var7f1b88c0)
/*  f184ac8:	15000002 */ 	bnez	$t0,.L0f184ad4
/*  f184acc:	00000000 */ 	nop
/*  f184ad0:	0007000d */ 	break	0x7
.L0f184ad4:
/*  f184ad4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f184ad8:	15010004 */ 	bne	$t0,$at,.L0f184aec
/*  f184adc:	3c018000 */ 	lui	$at,0x8000
/*  f184ae0:	14610002 */ 	bne	$v1,$at,.L0f184aec
/*  f184ae4:	00000000 */ 	nop
/*  f184ae8:	0006000d */ 	break	0x6
.L0f184aec:
/*  f184aec:	00480019 */ 	multu	$v0,$t0
/*  f184af0:	240100f0 */ 	addiu	$at,$zero,0xf0
/*  f184af4:	00403025 */ 	or	$a2,$v0,$zero
/*  f184af8:	24a588c0 */ 	addiu	$a1,$a1,%lo(var7f1b88c0)
/*  f184afc:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f184b00:	0000c812 */ 	mflo	$t9
/*  f184b04:	00791823 */ 	subu	$v1,$v1,$t9
/*  f184b08:	246700ef */ 	addiu	$a3,$v1,0xef
/*  f184b0c:	00e1001a */ 	div	$zero,$a3,$at
/*  f184b10:	00003812 */ 	mflo	$a3
/*  f184b14:	0c004dad */ 	jal	sprintf
/*  f184b18:	00000000 */ 	nop
/*  f184b1c:	0fc54d8a */ 	jal	func0f153628
/*  f184b20:	02002025 */ 	or	$a0,$s0,$zero
/*  f184b24:	3c098008 */ 	lui	$t1,%hi(g_FontHandelGothicXs2)
/*  f184b28:	8d29fb04 */ 	lw	$t1,%lo(g_FontHandelGothicXs2)($t1)
/*  f184b2c:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicXs1)
/*  f184b30:	00408025 */ 	or	$s0,$v0,$zero
/*  f184b34:	8ce7fb08 */ 	lw	$a3,%lo(g_FontHandelGothicXs1)($a3)
/*  f184b38:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f184b3c:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f184b40:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f184b44:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f184b48:	0fc55cbe */ 	jal	textMeasure
/*  f184b4c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f184b50:	8fa70094 */ 	lw	$a3,0x94($sp)
/*  f184b54:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f184b58:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f184b5c:	8fa60088 */ 	lw	$a2,0x88($sp)
/*  f184b60:	04e10003 */ 	bgez	$a3,.L0f184b70
/*  f184b64:	00075043 */ 	sra	$t2,$a3,0x1
/*  f184b68:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f184b6c:	00015043 */ 	sra	$t2,$at,0x1
.L0f184b70:
/*  f184b70:	00aa2823 */ 	subu	$a1,$a1,$t2
/*  f184b74:	00e53821 */ 	addu	$a3,$a3,$a1
/*  f184b78:	00461021 */ 	addu	$v0,$v0,$a2
/*  f184b7c:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f184b80:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f184b84:	afa70094 */ 	sw	$a3,0x94($sp)
/*  f184b88:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f184b8c:	0fc54e64 */ 	jal	func0f153990
/*  f184b90:	02002025 */ 	or	$a0,$s0,$zero
/*  f184b94:	0c002f02 */ 	jal	viGetX
/*  f184b98:	00408025 */ 	or	$s0,$v0,$zero
/*  f184b9c:	0c002f06 */ 	jal	viGetY
/*  f184ba0:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f184ba4:	3c0b8008 */ 	lui	$t3,%hi(g_FontNumeric1)
/*  f184ba8:	3c0d8008 */ 	lui	$t5,%hi(g_FontNumeric2)
/*  f184bac:	8dadfafc */ 	lw	$t5,%lo(g_FontNumeric2)($t5)
/*  f184bb0:	8d6bfb00 */ 	lw	$t3,%lo(g_FontNumeric1)($t3)
/*  f184bb4:	87b80044 */ 	lh	$t8,0x44($sp)
/*  f184bb8:	3c0c00ff */ 	lui	$t4,0xff
/*  f184bbc:	358c00a0 */ 	ori	$t4,$t4,0xa0
/*  f184bc0:	240f00a0 */ 	addiu	$t7,$zero,0xa0
/*  f184bc4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f184bc8:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f184bcc:	02002025 */ 	or	$a0,$s0,$zero
/*  f184bd0:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f184bd4:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f184bd8:	27a70048 */ 	addiu	$a3,$sp,0x48
/*  f184bdc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f184be0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f184be4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f184be8:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f184bec:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f184bf0:	0fc55b92 */ 	jal	textRender
/*  f184bf4:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f184bf8:	0fc54de0 */ 	jal	func0f153780
/*  f184bfc:	00402025 */ 	or	$a0,$v0,$zero
/*  f184c00:	00408025 */ 	or	$s0,$v0,$zero
.L0f184c04:
/*  f184c04:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f184c08:
/*  f184c08:	02001025 */ 	or	$v0,$s0,$zero
/*  f184c0c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f184c10:	03e00008 */ 	jr	$ra
/*  f184c14:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

void scenarioPacKill(struct mpchr *mpchr, s32 mpchrnum, s32 *score, s32 *arg3)
{
	struct mpchr *loopmpchr;
	s32 i;
	s32 index;

	*score = 0;
	index = func0f18d0e8(mpchrnum);

	if (index >= 0) {
		*score += g_ScenarioData.pac.unk20[index] * 2;
		*score += g_ScenarioData.pac.wincounts[index];
	}

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == mpchrnum) {
				*score -= mpchr->killcounts[i];
			} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				if (i < 4) {
					loopmpchr = &g_MpPlayers[i].base;
				} else {
					loopmpchr = &g_MpSimulants[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			} else {
				*score += mpchr->killcounts[i];
			}
		}
	}

	*arg3 = mpchr->numdeaths;
}

Gfx *scenarioPacRadar(Gfx *gdl)
{
	return gdl;
}

GLOBAL_ASM(
glabel scenarioPacRadar2
/*  f184d8c:	3c03800b */ 	lui	$v1,%hi(g_MpSetup+0xc)
/*  f184d90:	8c63cb94 */ 	lw	$v1,%lo(g_MpSetup+0xc)($v1)
/*  f184d94:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f184d98:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f184d9c:	000372c0 */ 	sll	$t6,$v1,0xb
/*  f184da0:	05c10042 */ 	bgez	$t6,.L0f184eac
/*  f184da4:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f184da8:	3c0f800b */ 	lui	$t7,%hi(g_ScenarioData+0x4)
/*  f184dac:	8defc114 */ 	lw	$t7,%lo(g_ScenarioData+0x4)($t7)
/*  f184db0:	3c19800b */ 	lui	$t9,%hi(g_ScenarioData+0x8)
/*  f184db4:	05e0003d */ 	bltz	$t7,.L0f184eac
/*  f184db8:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f184dbc:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f184dc0:	8739c118 */ 	lh	$t9,%lo(g_ScenarioData+0x8)($t9)
/*  f184dc4:	3c09800b */ 	lui	$t1,%hi(g_MpPlayerChrs)
/*  f184dc8:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f184dcc:	00194080 */ 	sll	$t0,$t9,0x2
/*  f184dd0:	01284821 */ 	addu	$t1,$t1,$t0
/*  f184dd4:	8d29c4d0 */ 	lw	$t1,%lo(g_MpPlayerChrs)($t1)
/*  f184dd8:	8d2a001c */ 	lw	$t2,0x1c($t1)
/*  f184ddc:	15450033 */ 	bne	$t2,$a1,.L0f184eac
/*  f184de0:	afaa0034 */ 	sw	$t2,0x34($sp)
/*  f184de4:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f184de8:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f184dec:	306e0002 */ 	andi	$t6,$v1,0x2
/*  f184df0:	8c4b00bc */ 	lw	$t3,0xbc($v0)
/*  f184df4:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f184df8:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f184dfc:	c5660008 */ 	lwc1	$f6,0x8($t3)
/*  f184e00:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f184e04:	3c0700ff */ 	lui	$a3,0xff
/*  f184e08:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f184e0c:	e7a80038 */ 	swc1	$f8,0x38($sp)
/*  f184e10:	8c4c00bc */ 	lw	$t4,0xbc($v0)
/*  f184e14:	c4aa000c */ 	lwc1	$f10,0xc($a1)
/*  f184e18:	c590000c */ 	lwc1	$f16,0xc($t4)
/*  f184e1c:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f184e20:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f184e24:	8c4d00bc */ 	lw	$t5,0xbc($v0)
/*  f184e28:	c4a40010 */ 	lwc1	$f4,0x10($a1)
/*  f184e2c:	c5a60010 */ 	lwc1	$f6,0x10($t5)
/*  f184e30:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f184e34:	11c00014 */ 	beqz	$t6,.L0f184e88
/*  f184e38:	e7a80040 */ 	swc1	$f8,0x40($sp)
/*  f184e3c:	8caf0004 */ 	lw	$t7,0x4($a1)
/*  f184e40:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f184e44:	91e40125 */ 	lbu	$a0,0x125($t7)
/*  f184e48:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f184e4c:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f184e50:	3c078008 */ 	lui	$a3,%hi(g_TeamColours)
/*  f184e54:	00f83821 */ 	addu	$a3,$a3,$t8
/*  f184e58:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f184e5c:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f184e60:	8ce77cc4 */ 	lw	$a3,%lo(g_TeamColours)($a3)
/*  f184e64:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f184e68:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f184e6c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f184e70:	0fc63a7b */ 	jal	radarDrawDot
/*  f184e74:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f184e78:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f184e7c:	ad220000 */ 	sw	$v0,0x0($t1)
/*  f184e80:	1000000b */ 	b	.L0f184eb0
/*  f184e84:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f184e88:
/*  f184e88:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f184e8c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f184e90:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f184e94:	0fc63a7b */ 	jal	radarDrawDot
/*  f184e98:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f184e9c:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f184ea0:	ad820000 */ 	sw	$v0,0x0($t4)
/*  f184ea4:	10000002 */ 	b	.L0f184eb0
/*  f184ea8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f184eac:
/*  f184eac:	00001025 */ 	or	$v0,$zero,$zero
.L0f184eb0:
/*  f184eb0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f184eb4:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f184eb8:	03e00008 */ 	jr	$ra
/*  f184ebc:	00000000 */ 	nop
);

// Mismatch because the game jumps to pac properties directly
// while decomp loads the base pac address then uses offsets.
//bool scenarioPacRadar2(Gfx **gdl, struct prop *prop)
//{
//	if ((g_MpSetup.options & MPOPTION_PAC_SHOWONRADAR) && g_ScenarioData.pac.victimindex >= 0) {
//		s32 index = g_ScenarioData.pac.victimindex;
//		struct prop *thing = g_MpPlayerChrs[g_ScenarioData.pac.victims[index]]->prop;
//
//		if (thing == prop) {
//			struct coord dist;
//			dist.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
//			dist.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
//			dist.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;
//
//			if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
//				u32 colour = g_TeamColours[radarGetTeamIndex(prop->chr->team)];
//				*gdl = radarDrawDot(*gdl, thing, &dist, colour, 0, 1);
//			} else {
//				*gdl = radarDrawDot(*gdl, thing, &dist, 0xff0000, 0, 1);
//			}
//
//			return true;
//		}
//	}
//
//	return false;
//}

/**
 * While the options dialog is open, check if another player has changed the
 * scenario to a different one. If so, replace this dialog with the new one.
 */
s32 mpOptionsMenuDialog(u32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curframe->dialog != g_MpScenarios[g_MpSetup.scenario].optionsdialog) {
			s32 i;
			s32 end = ARRAYCOUNT(g_MpScenarios);

			for (i = 0; i < end; i++) {
				if (g_Menus[g_MpPlayerNum].curframe->dialog == g_MpScenarios[i].optionsdialog) {
					break;
				}
			}

			if (i < end) {
				menuPopDialog();
				menuPushDialog(g_MpScenarios[g_MpSetup.scenario].optionsdialog);
			}
		}
	}

	return 0;
}

char *mpMenuTextScenarioShortName(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s\n", langGet(g_MpScenarioOverviews[g_MpSetup.scenario].shortname));
	return g_StringPointer;
}

char *mpMenuTextScenarioName(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s\n", langGet(g_MpScenarioOverviews[g_MpSetup.scenario].name));
	return g_StringPointer;
}

const char var7f1b88d0[] = "%s:\n";
const char var7f1b88d8[] = "%s\n";

GLOBAL_ASM(
glabel menuhandler00185068
.late_rodata
glabel var7f1b8964
.word menuhandler00185068+0xa8 # f185110
glabel var7f1b8968
.word menuhandler00185068+0x224 # f18528c
glabel var7f1b896c
.word menuhandler00185068+0xf4 # f18515c
glabel var7f1b8970
.word menuhandler00185068+0x260 # f1852c8
glabel var7f1b8974
.word menuhandler00185068+0x27c # f1852e4
glabel var7f1b8978
.word menuhandler00185068+0x15c # f1851c4
glabel var7f1b897c
.word menuhandler00185068+0x1c4 # f18522c
.text
/*  f185068:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f18506c:	3c0e8008 */ 	lui	$t6,%hi(var8008716c)
/*  f185070:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f185074:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f185078:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f18507c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f185080:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f185084:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f185088:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18508c:	25ce716c */ 	addiu	$t6,$t6,%lo(var8008716c)
/*  f185090:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f185094:	27b30040 */ 	addiu	$s3,$sp,0x40
/*  f185098:	00c0a825 */ 	or	$s5,$a2,$zero
/*  f18509c:	ae610000 */ 	sw	$at,0x0($s3)
/*  f1850a0:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f1850a4:	00009025 */ 	or	$s2,$zero,$zero
/*  f1850a8:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f1850ac:	ae790004 */ 	sw	$t9,0x4($s3)
/*  f1850b0:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f1850b4:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x4b0)
/*  f1850b8:	2489ffff */ 	addiu	$t1,$a0,-1
/*  f1850bc:	ae610008 */ 	sw	$at,0x8($s3)
/*  f1850c0:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f1850c4:	ae79000c */ 	sw	$t9,0xc($s3)
/*  f1850c8:	90a80001 */ 	lbu	$t0,0x1($a1)
/*  f1850cc:	51000009 */ 	beqzl	$t0,.L0f1850f4
/*  f1850d0:	2d210007 */ 	sltiu	$at,$t1,0x7
/*  f1850d4:	8c42a470 */ 	lw	$v0,%lo(g_Vars+0x4b0)($v0)
/*  f1850d8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1850dc:	50400004 */ 	beqzl	$v0,.L0f1850f0
/*  f1850e0:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1850e4:	54410003 */ 	bnel	$v0,$at,.L0f1850f4
/*  f1850e8:	2d210007 */ 	sltiu	$at,$t1,0x7
/*  f1850ec:	0000a025 */ 	or	$s4,$zero,$zero
.L0f1850f0:
/*  f1850f0:	2d210007 */ 	sltiu	$at,$t1,0x7
.L0f1850f4:
/*  f1850f4:	10200098 */ 	beqz	$at,.L0f185358
/*  f1850f8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1850fc:	3c017f1c */ 	lui	$at,%hi(var7f1b8964)
/*  f185100:	00290821 */ 	addu	$at,$at,$t1
/*  f185104:	8c298964 */ 	lw	$t1,%lo(var7f1b8964)($at)
/*  f185108:	01200008 */ 	jr	$t1
/*  f18510c:	00000000 */ 	nop
/*  f185110:	3c108008 */ 	lui	$s0,%hi(g_MpScenarioOverviews)
/*  f185114:	3c118008 */ 	lui	$s1,%hi(var8008716c)
/*  f185118:	2631716c */ 	addiu	$s1,$s1,%lo(var8008716c)
/*  f18511c:	26107148 */ 	addiu	$s0,$s0,%lo(g_MpScenarioOverviews)
.L0f185120:
/*  f185120:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f185124:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f185128:	50400008 */ 	beqzl	$v0,.L0f18514c
/*  f18512c:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f185130:	56800005 */ 	bnezl	$s4,.L0f185148
/*  f185134:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f185138:	920a0005 */ 	lbu	$t2,0x5($s0)
/*  f18513c:	55400003 */ 	bnezl	$t2,.L0f18514c
/*  f185140:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f185144:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f185148:
/*  f185148:	26100006 */ 	addiu	$s0,$s0,0x6
.L0f18514c:
/*  f18514c:	1611fff4 */ 	bne	$s0,$s1,.L0f185120
/*  f185150:	00000000 */ 	nop
/*  f185154:	10000080 */ 	b	.L0f185358
/*  f185158:	aeb20000 */ 	sw	$s2,0x0($s5)
/*  f18515c:	3c108008 */ 	lui	$s0,%hi(g_MpScenarioOverviews)
/*  f185160:	3c118008 */ 	lui	$s1,%hi(var8008716c)
/*  f185164:	2631716c */ 	addiu	$s1,$s1,%lo(var8008716c)
/*  f185168:	26107148 */ 	addiu	$s0,$s0,%lo(g_MpScenarioOverviews)
.L0f18516c:
/*  f18516c:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f185170:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f185174:	5040000f */ 	beqzl	$v0,.L0f1851b4
/*  f185178:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f18517c:	56800005 */ 	bnezl	$s4,.L0f185194
/*  f185180:	8eac0000 */ 	lw	$t4,0x0($s5)
/*  f185184:	920b0005 */ 	lbu	$t3,0x5($s0)
/*  f185188:	5560000a */ 	bnezl	$t3,.L0f1851b4
/*  f18518c:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f185190:	8eac0000 */ 	lw	$t4,0x0($s5)
.L0f185194:
/*  f185194:	564c0006 */ 	bnel	$s2,$t4,.L0f1851b0
/*  f185198:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f18519c:	0fc5b9f1 */ 	jal	langGet
/*  f1851a0:	96040000 */ 	lhu	$a0,0x0($s0)
/*  f1851a4:	1000006e */ 	b	.L0f185360
/*  f1851a8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1851ac:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f1851b0:
/*  f1851b0:	26100006 */ 	addiu	$s0,$s0,0x6
.L0f1851b4:
/*  f1851b4:	1611ffed */ 	bne	$s0,$s1,.L0f18516c
/*  f1851b8:	00000000 */ 	nop
/*  f1851bc:	10000067 */ 	b	.L0f18535c
/*  f1851c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1851c4:	3c108008 */ 	lui	$s0,%hi(g_MpScenarioOverviews)
/*  f1851c8:	26107148 */ 	addiu	$s0,$s0,%lo(g_MpScenarioOverviews)
/*  f1851cc:	00008825 */ 	or	$s1,$zero,$zero
/*  f1851d0:	24130006 */ 	addiu	$s3,$zero,0x6
.L0f1851d4:
/*  f1851d4:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f1851d8:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f1851dc:	5040000d */ 	beqzl	$v0,.L0f185214
/*  f1851e0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1851e4:	56800005 */ 	bnezl	$s4,.L0f1851fc
/*  f1851e8:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f1851ec:	920d0005 */ 	lbu	$t5,0x5($s0)
/*  f1851f0:	55a00008 */ 	bnezl	$t5,.L0f185214
/*  f1851f4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1851f8:	8eb80000 */ 	lw	$t8,0x0($s5)
.L0f1851fc:
/*  f1851fc:	16580003 */ 	bne	$s2,$t8,.L0f18520c
/*  f185200:	3c01800b */ 	lui	$at,%hi(g_MpSetup+0x10)
/*  f185204:	10000005 */ 	b	.L0f18521c
/*  f185208:	a031cb98 */ 	sb	$s1,%lo(g_MpSetup+0x10)($at)
.L0f18520c:
/*  f18520c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f185210:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f185214:
/*  f185214:	1633ffef */ 	bne	$s1,$s3,.L0f1851d4
/*  f185218:	26100006 */ 	addiu	$s0,$s0,0x6
.L0f18521c:
/*  f18521c:	0fc61521 */ 	jal	scenarioInit
/*  f185220:	00000000 */ 	nop
/*  f185224:	1000004d */ 	b	.L0f18535c
/*  f185228:	00001025 */ 	or	$v0,$zero,$zero
/*  f18522c:	3c108008 */ 	lui	$s0,%hi(g_MpScenarioOverviews)
/*  f185230:	26107148 */ 	addiu	$s0,$s0,%lo(g_MpScenarioOverviews)
/*  f185234:	00008825 */ 	or	$s1,$zero,$zero
/*  f185238:	24130006 */ 	addiu	$s3,$zero,0x6
.L0f18523c:
/*  f18523c:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f185240:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f185244:	5040000d */ 	beqzl	$v0,.L0f18527c
/*  f185248:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18524c:	16800004 */ 	bnez	$s4,.L0f185260
/*  f185250:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup+0x10)
/*  f185254:	920f0005 */ 	lbu	$t7,0x5($s0)
/*  f185258:	55e00008 */ 	bnezl	$t7,.L0f18527c
/*  f18525c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f185260:
/*  f185260:	91cecb98 */ 	lbu	$t6,%lo(g_MpSetup+0x10)($t6)
/*  f185264:	562e0004 */ 	bnel	$s1,$t6,.L0f185278
/*  f185268:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f18526c:	1000003a */ 	b	.L0f185358
/*  f185270:	aeb20000 */ 	sw	$s2,0x0($s5)
/*  f185274:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f185278:
/*  f185278:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18527c:
/*  f18527c:	1633ffef */ 	bne	$s1,$s3,.L0f18523c
/*  f185280:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f185284:	10000035 */ 	b	.L0f18535c
/*  f185288:	00001025 */ 	or	$v0,$zero,$zero
/*  f18528c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f185290:	12800009 */ 	beqz	$s4,.L0f1852b8
/*  f185294:	aeb90000 */ 	sw	$t9,0x0($s5)
/*  f185298:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f18529c:	2404001f */ 	addiu	$a0,$zero,0x1f
/*  f1852a0:	5440002e */ 	bnezl	$v0,.L0f18535c
/*  f1852a4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1852a8:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f1852ac:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f1852b0:	5440002a */ 	bnezl	$v0,.L0f18535c
/*  f1852b4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1852b8:
/*  f1852b8:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f1852bc:	2509ffff */ 	addiu	$t1,$t0,-1
/*  f1852c0:	10000025 */ 	b	.L0f185358
/*  f1852c4:	aea90000 */ 	sw	$t1,0x0($s5)
/*  f1852c8:	8eaa0000 */ 	lw	$t2,0x0($s5)
/*  f1852cc:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f1852d0:	026b6021 */ 	addu	$t4,$s3,$t3
/*  f1852d4:	0fc5b9f1 */ 	jal	langGet
/*  f1852d8:	95840004 */ 	lhu	$a0,0x4($t4)
/*  f1852dc:	10000020 */ 	b	.L0f185360
/*  f1852e0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1852e4:	8ead0000 */ 	lw	$t5,0x0($s5)
/*  f1852e8:	3c108008 */ 	lui	$s0,%hi(g_MpScenarioOverviews)
/*  f1852ec:	26107148 */ 	addiu	$s0,$s0,%lo(g_MpScenarioOverviews)
/*  f1852f0:	000dc0c0 */ 	sll	$t8,$t5,0x3
/*  f1852f4:	02787821 */ 	addu	$t7,$s3,$t8
/*  f1852f8:	8dee0000 */ 	lw	$t6,0x0($t7)
/*  f1852fc:	00008825 */ 	or	$s1,$zero,$zero
/*  f185300:	59c00015 */ 	blezl	$t6,.L0f185358
/*  f185304:	aeb20008 */ 	sw	$s2,0x8($s5)
.L0f185308:
/*  f185308:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f18530c:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f185310:	50400008 */ 	beqzl	$v0,.L0f185334
/*  f185314:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f185318:	56800005 */ 	bnezl	$s4,.L0f185330
/*  f18531c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f185320:	92190005 */ 	lbu	$t9,0x5($s0)
/*  f185324:	57200003 */ 	bnezl	$t9,.L0f185334
/*  f185328:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f18532c:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f185330:
/*  f185330:	8ea80000 */ 	lw	$t0,0x0($s5)
.L0f185334:
/*  f185334:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f185338:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f18533c:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f185340:	02695021 */ 	addu	$t2,$s3,$t1
/*  f185344:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f185348:	022b082a */ 	slt	$at,$s1,$t3
/*  f18534c:	1420ffee */ 	bnez	$at,.L0f185308
/*  f185350:	00000000 */ 	nop
/*  f185354:	aeb20008 */ 	sw	$s2,0x8($s5)
.L0f185358:
/*  f185358:	00001025 */ 	or	$v0,$zero,$zero
.L0f18535c:
/*  f18535c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f185360:
/*  f185360:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f185364:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f185368:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18536c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f185370:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f185374:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f185378:	03e00008 */ 	jr	$ra
/*  f18537c:	27bd0050 */ 	addiu	$sp,$sp,0x50
);
