#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/dlights.h"
#include "game/game_006900.h"
#include "game/game_00c490.h"
#include "game/prop.h"
#include "game/game_092610.h"
#include "game/atan2f.h"
#include "game/bondgun.h"
#include "game/game_0b69d0.h"
#include "game/game_0d4690.h"
#include "game/hudmsg.h"
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
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/snd.h"
#include "lib/memory.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_24e40.h"
#include "data.h"
#include "types.h"

struct scenariodata g_ScenarioData;
u32 var800ac254;
u32 var800ac258;
u32 var800ac25c;
u32 var800ac260;
u32 var800ac264;
u32 var800ac268;
u32 var800ac26c;
u32 var800ac270;
u32 var800ac274;
u32 var800ac278;
u32 var800ac27c;
u32 var800ac280;
u32 var800ac284;
u32 var800ac288;
u32 var800ac28c;
u32 var800ac290;
u32 var800ac294;
u32 var800ac298;
u32 var800ac29c;
u32 var800ac2a0;
u32 var800ac2a4;
u32 var800ac2a8;
u32 var800ac2ac;
u32 var800ac2b0;
u32 var800ac2b4;
u32 var800ac2b8;
u32 var800ac2bc;
u32 var800ac2c0;
u32 var800ac2c4;
u32 var800ac2c8;
u32 var800ac2cc;
u32 var800ac2d0;
u32 var800ac2d4;
u32 var800ac2d8;
u32 var800ac2dc;
u32 var800ac2e0;
u32 var800ac2e4;
u32 var800ac2e8;
u32 var800ac2ec;
u32 var800ac2f0;
u32 var800ac2f4;
u32 var800ac2f8;
u32 var800ac2fc;
u32 var800ac300;
u32 var800ac304;
u32 var800ac308;
u32 var800ac30c;
u32 var800ac310;
u32 var800ac314;
u32 var800ac318;
u32 var800ac31c;
u32 var800ac320;
u32 var800ac324;
u32 var800ac328;
u32 var800ac32c;
u32 var800ac330;
u32 var800ac334;
u32 var800ac338;
u32 var800ac33c;
u32 var800ac340;
u32 var800ac344;
u32 var800ac348;
u32 var800ac34c;
u32 var800ac350;
u32 var800ac354;
u32 var800ac358;
u32 var800ac35c;
u32 var800ac360;
u32 var800ac364;
u32 var800ac368;
u32 var800ac36c;
u32 var800ac370;
u32 var800ac374;
u32 var800ac378;
u32 var800ac37c;
u32 var800ac380;
u32 var800ac384;
u32 var800ac388;
u32 var800ac38c;
u32 var800ac390;
u32 var800ac394;
u32 var800ac398;
u32 var800ac39c;
u32 var800ac3a0;
u32 var800ac3a4;
u32 var800ac3a8;
u32 var800ac3ac;
u32 var800ac3b0;
u32 var800ac3b4;
u32 var800ac3b8;
u32 var800ac3bc;
u32 var800ac3c0;
u32 var800ac3c4;
u32 var800ac3c8;
u32 var800ac3cc;
u32 var800ac3d0;
u32 var800ac3d4;
u32 var800ac3d8;
u32 var800ac3dc;
u32 var800ac3e0;
u32 var800ac3e4;
u32 var800ac3e8;
u32 var800ac3ec;
u32 var800ac3f0;
u32 var800ac3f4;
u32 var800ac3f8;
u32 var800ac3fc;
u32 var800ac400;
u32 var800ac404;
u32 var800ac408;
u32 var800ac40c;
u32 var800ac410;
u32 var800ac414;
u32 var800ac418;
u32 var800ac41c;
u32 var800ac420;
u32 var800ac424;
u32 var800ac428;
u32 var800ac42c;
u32 var800ac430;
u32 var800ac434;
u32 var800ac438;
u32 var800ac43c;
u32 var800ac440;
u32 var800ac444;
u32 var800ac448;
u32 var800ac44c;
u32 var800ac450;
u32 var800ac454;
u32 var800ac458;
u32 var800ac45c;
u32 var800ac460;
u32 var800ac464;
u32 var800ac468;
u32 var800ac46c;
u32 var800ac470;
u32 var800ac474;
u32 var800ac478;
u32 var800ac47c;
u32 var800ac480;
u32 var800ac484;
u32 var800ac488;
u32 var800ac48c;
u32 var800ac490;
u32 var800ac494;
u32 var800ac498;
u32 var800ac49c;
u32 var800ac4a0;
u32 var800ac4a4;
u32 var800ac4a8;
u32 var800ac4ac;
u32 var800ac4b0;
u32 var800ac4b4;
u32 var800ac4b8;
u32 var800ac4bc;
u32 var800ac4c0;
u32 var800ac4c4;
u32 var800ac4c8;
u32 var800ac4cc;

struct mpscenario g_MpScenarios[6];

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

s32 menuhandlerMpDisplayTeam(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
			return false;
		}

		return true;
	}

	return menuhandlerMpCheckboxOption(operation, item, data);
}

s32 menuhandlerMpOneHitKills(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED || operation == MENUOP_CHECKHIDDEN) {
		if (mpIsFeatureUnlocked(MPFEATURE_ONEHITKILLS)) {
			return false;
		}

		return true;
	}

	return menuhandlerMpCheckboxOption(operation, item, data);
}

u16 mpslowmotionoptions[] = {
	L_MPMENU_240, // "Off"
	L_MPMENU_241, // "On"
	L_MPMENU_242, // "Smart"
};

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

#if VERSION >= VERSION_NTSC_1_0
	if (data->nextindex < ARRAYCOUNT(data->padnums))
#endif
	{
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

struct menuitem g_MpCombatOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222, MPOPTION_ONEHITKILLS,       menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223, 0x00000000,                 menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224, MPOPTION_FASTMOVEMENT,      menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225, MPOPTION_DISPLAYTEAM,       menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226, MPOPTION_NORADAR,           menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227, MPOPTION_NOAUTOAIM,         menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_228, MPOPTION_NOPLAYERHIGHLIGHT, menuhandlerMpCheckboxOption }, // "No Player Highlight"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_229, MPOPTION_NOPICKUPHIGHLIGHT, menuhandlerMpCheckboxOption }, // "No Pickup Highlight"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239, 0x00000000,                 NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
};

struct menudialog g_MpCombatOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_215, // "Combat Options"
	g_MpCombatOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

struct menuitem g_MpBriefcaseOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222,  MPOPTION_ONEHITKILLS,            menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223,  0x00000000,                      menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224,  MPOPTION_FASTMOVEMENT,           menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225,  MPOPTION_DISPLAYTEAM,            menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226,  MPOPTION_NORADAR,                menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227,  MPOPTION_NOAUTOAIM,              menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS_493, MPOPTION_KILLSSCORE,             menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                      NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_237,  MPOPTION_HTB_HIGHLIGHTBRIEFCASE, menuhandlerMpCheckboxOption }, // "Highlight Briefcase"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_238,  MPOPTION_HTB_SHOWONRADAR,        menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                      NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239,  0x00000000,                      NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,                      NULL                        },
};

struct menudialog g_MpBriefcaseOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_216, // "Briefcase Options"
	g_MpBriefcaseOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

struct defaultobj *var800869ec = NULL;

u32 var800869f0 = 0x01000008;
u32 var800869f4 = 0x00110000;
u32 var800869f8 = 0x00420001;
u32 var800869fc = 0x00204000;
u32 var80086a00 = 0x00000000;
u32 var80086a04 = 0x00000000;
u32 var80086a08 = 0x00000000;
u32 var80086a0c = 0x3f800000;
u32 var80086a10 = 0x00000000;
u32 var80086a14 = 0x00000000;
u32 var80086a18 = 0x00000000;
u32 var80086a1c = 0x3f800000;
u32 var80086a20 = 0x00000000;
u32 var80086a24 = 0x00000000;
u32 var80086a28 = 0x00000000;
u32 var80086a2c = 0x3f800000;
u32 var80086a30 = 0x00000000;
u32 var80086a34 = 0x00000000;
u32 var80086a38 = 0x00000000;
u32 var80086a3c = 0x000003e8;
u32 var80086a40 = 0xffffff00;
u32 var80086a44 = 0xffffff00;
u32 var80086a48 = 0x0fff0000;
u32 var80086a4c = 0x57000000;
u32 var80086a50 = 0x00ffffff;
u32 var80086a54 = 0x00000000;

#if VERSION >= VERSION_NTSC_1_0
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
#else
GLOBAL_ASM(
glabel func0f1800a8
/*  f17a714:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f17a718:	3c0f8009 */ 	lui	$t7,0x8009
/*  f17a71c:	25ef9170 */ 	addiu	$t7,$t7,-28304
/*  f17a720:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a724:	25e80060 */ 	addiu	$t0,$t7,0x60
/*  f17a728:	27ae0080 */ 	addiu	$t6,$sp,0x80
.NB0f17a72c:
/*  f17a72c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f17a730:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f17a734:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f17a738:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f17a73c:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f17a740:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f17a744:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f17a748:	15e8fff8 */ 	bne	$t7,$t0,.NB0f17a72c
/*  f17a74c:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f17a750:	8de10000 */ 	lw	$at,0x0($t7)
/*  f17a754:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f17a758:	3c03800a */ 	lui	$v1,0x800a
/*  f17a75c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f17a760:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f17a764:	8c63e9fc */ 	lw	$v1,-0x1604($v1)
/*  f17a768:	00002025 */ 	or	$a0,$zero,$zero
/*  f17a76c:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f17a770:	1060000f */ 	beqz	$v1,.NB0f17a7b0
/*  f17a774:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f17a778:	8c620004 */ 	lw	$v0,0x4($v1)
.NB0f17a77c:
/*  f17a77c:	00045080 */ 	sll	$t2,$a0,0x2
/*  f17a780:	00ca5821 */ 	addu	$t3,$a2,$t2
/*  f17a784:	90490003 */ 	lbu	$t1,0x3($v0)
/*  f17a788:	54a90004 */ 	bnel	$a1,$t1,.NB0f17a79c
/*  f17a78c:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f17a790:	ad620000 */ 	sw	$v0,0x0($t3)
/*  f17a794:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f17a798:	8c630020 */ 	lw	$v1,0x20($v1)
.NB0f17a79c:
/*  f17a79c:	28810014 */ 	slti	$at,$a0,0x14
/*  f17a7a0:	10600003 */ 	beqz	$v1,.NB0f17a7b0
/*  f17a7a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17a7a8:	5420fff4 */ 	bnezl	$at,.NB0f17a77c
/*  f17a7ac:	8c620004 */ 	lw	$v0,0x4($v1)
.NB0f17a7b0:
/*  f17a7b0:	1880001c */ 	blez	$a0,.NB0f17a824
/*  f17a7b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17a7b8:	0c004d84 */ 	jal	random
/*  f17a7bc:	afa40074 */ 	sw	$a0,0x74($sp)
/*  f17a7c0:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f17a7c4:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f17a7c8:	3c058009 */ 	lui	$a1,0x8009
/*  f17a7cc:	0044001b */ 	divu	$zero,$v0,$a0
/*  f17a7d0:	24a5916c */ 	addiu	$a1,$a1,-28308
/*  f17a7d4:	3c07800b */ 	lui	$a3,0x800b
/*  f17a7d8:	24e709c0 */ 	addiu	$a3,$a3,0x9c0
/*  f17a7dc:	14800002 */ 	bnez	$a0,.NB0f17a7e8
/*  f17a7e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17a7e4:	0007000d */ 	break	0x7
.NB0f17a7e8:
/*  f17a7e8:	00002010 */ 	mfhi	$a0
/*  f17a7ec:	00046080 */ 	sll	$t4,$a0,0x2
/*  f17a7f0:	00cc6821 */ 	addu	$t5,$a2,$t4
/*  f17a7f4:	8db90000 */ 	lw	$t9,0x0($t5)
/*  f17a7f8:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f17a7fc:	87380006 */ 	lh	$t8,0x6($t9)
/*  f17a800:	acf80014 */ 	sw	$t8,0x14($a3)
/*  f17a804:	8f280040 */ 	lw	$t0,0x40($t9)
/*  f17a808:	350f0004 */ 	ori	$t7,$t0,0x4
/*  f17a80c:	af2f0040 */ 	sw	$t7,0x40($t9)
/*  f17a810:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f17a814:	906e0002 */ 	lbu	$t6,0x2($v1)
/*  f17a818:	35c90004 */ 	ori	$t1,$t6,0x4
/*  f17a81c:	10000017 */ 	beqz	$zero,.NB0f17a87c
/*  f17a820:	a0690002 */ 	sb	$t1,0x2($v1)
.NB0f17a824:
/*  f17a824:	3c07800b */ 	lui	$a3,0x800b
/*  f17a828:	24e709c0 */ 	addiu	$a3,$a3,0x9c0
/*  f17a82c:	84ea0018 */ 	lh	$t2,0x18($a3)
/*  f17a830:	59400012 */ 	blezl	$t2,.NB0f17a87c
/*  f17a834:	ace00014 */ 	sw	$zero,0x14($a3)
/*  f17a838:	0c004d84 */ 	jal	random
/*  f17a83c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17a840:	3c07800b */ 	lui	$a3,0x800b
/*  f17a844:	24e709c0 */ 	addiu	$a3,$a3,0x9c0
/*  f17a848:	84eb0018 */ 	lh	$t3,0x18($a3)
/*  f17a84c:	004b001b */ 	divu	$zero,$v0,$t3
/*  f17a850:	00006010 */ 	mfhi	$t4
/*  f17a854:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f17a858:	00edc821 */ 	addu	$t9,$a3,$t5
/*  f17a85c:	8738001a */ 	lh	$t8,0x1a($t9)
/*  f17a860:	15600002 */ 	bnez	$t3,.NB0f17a86c
/*  f17a864:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17a868:	0007000d */ 	break	0x7
.NB0f17a86c:
/*  f17a86c:	acf80014 */ 	sw	$t8,0x14($a3)
/*  f17a870:	10000002 */ 	beqz	$zero,.NB0f17a87c
/*  f17a874:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17a878:	ace00014 */ 	sw	$zero,0x14($a3)
.NB0f17a87c:
/*  f17a87c:	3c04800b */ 	lui	$a0,0x800b
/*  f17a880:	24840b08 */ 	addiu	$a0,$a0,0xb08
/*  f17a884:	27a80080 */ 	addiu	$t0,$sp,0x80
/*  f17a888:	250e0060 */ 	addiu	$t6,$t0,0x60
/*  f17a88c:	00804825 */ 	or	$t1,$a0,$zero
.NB0f17a890:
/*  f17a890:	8d010000 */ 	lw	$at,0x0($t0)
/*  f17a894:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f17a898:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f17a89c:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*  f17a8a0:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*  f17a8a4:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*  f17a8a8:	8d01fffc */ 	lw	$at,-0x4($t0)
/*  f17a8ac:	150efff8 */ 	bne	$t0,$t6,.NB0f17a890
/*  f17a8b0:	ad21fffc */ 	sw	$at,-0x4($t1)
/*  f17a8b4:	8d010000 */ 	lw	$at,0x0($t0)
/*  f17a8b8:	240503e7 */ 	addiu	$a1,$zero,0x3e7
/*  f17a8bc:	ad210000 */ 	sw	$at,0x0($t1)
/*  f17a8c0:	8d0e0004 */ 	lw	$t6,0x4($t0)
/*  f17a8c4:	ad2e0004 */ 	sw	$t6,0x4($t1)
/*  f17a8c8:	8cea0014 */ 	lw	$t2,0x14($a3)
/*  f17a8cc:	0fc034c8 */ 	jal	weaponAssignToHome
/*  f17a8d0:	a48a0006 */ 	sh	$t2,0x6($a0)
/*  f17a8d4:	3c04800b */ 	lui	$a0,0x800b
/*  f17a8d8:	24840b08 */ 	addiu	$a0,$a0,0xb08
/*  f17a8dc:	908b0002 */ 	lbu	$t3,0x2($a0)
/*  f17a8e0:	8c8d0014 */ 	lw	$t5,0x14($a0)
/*  f17a8e4:	3c07800b */ 	lui	$a3,0x800b
/*  f17a8e8:	24e709c0 */ 	addiu	$a3,$a3,0x9c0
/*  f17a8ec:	316cfffb */ 	andi	$t4,$t3,0xfffb
/*  f17a8f0:	a08c0002 */ 	sb	$t4,0x2($a0)
/*  f17a8f4:	11a00004 */ 	beqz	$t5,.NB0f17a908
/*  f17a8f8:	aced0004 */ 	sw	$t5,0x4($a3)
/*  f17a8fc:	91b8003f */ 	lbu	$t8,0x3f($t5)
/*  f17a900:	370f0020 */ 	ori	$t7,$t8,0x20
/*  f17a904:	a1af003f */ 	sb	$t7,0x3f($t5)
.NB0f17a908:
/*  f17a908:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17a90c:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f17a910:	03e00008 */ 	jr	$ra
/*  f17a914:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

void scenarioHtbReset(void)
{
	var800869ec = 0;
	func0f1800a8();
}

void scenarioHtbTick(void)
{
	s32 i;
	u32 prevplayernum = g_Vars.currentplayernum;
	struct prop *prop;

	if (var800869ec && var800869ec->prop) {
		if (g_ScenarioData.htb.token == NULL || g_ScenarioData.htb.token->type != PROPTYPE_WEAPON) {
			var800869ec = NULL;
		} else {
			var800869ec->prop->timetoregen = PALDOWN(1200);
		}
	}

	g_ScenarioData.htb.token = NULL;

	// Check if briefcase is on the ground
	prop = g_Vars.activeprops;

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
#if VERSION >= VERSION_NTSC_1_0
			if (g_MpPlayerChrs[i]->prop && g_MpPlayerChrs[i]->aibot->unk09c_00)
#else
			if (g_MpPlayerChrs[i]->aibot->unk09c_00)
#endif
			{
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

			if (chr->aibot->unk0a0 >= PALDOWN(7200)) {
				sndStart(var80095200, SFX_MP_SCOREPOINT, NULL, -1, -1, -1, -1, -1);
				var800ac500[mpPlayerGetIndex(chr)]->unk3e++;
				chr->aibot->unk0a0 = 0;
			}
		} else {
			chr->aibot->unk0a0 = 0;
		}
	} else {
		if (invHasBriefcase()) {
			g_Vars.currentplayerstats->tokenheldtime += g_Vars.lvupdate240;

			if (g_Vars.currentplayerstats->tokenheldtime >= PALDOWN(7200)) {
				sndStart(var80095200, SFX_MP_SCOREPOINT, NULL, -1, -1, -1, -1, -1);
				var800ac500[g_Vars.currentplayernum]->unk3e++;
				hudmsgCreateWithFlags(langGet(L_MPWEAPONS_024), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE); // "1 Point!"
				g_Vars.currentplayerstats->tokenheldtime = 0;
			}
		} else {
			g_Vars.currentplayerstats->tokenheldtime = 0;
		}
	}
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel scenarioHtbCallback18
/*  f1817dc:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f1817e0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1817e4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1817e8:	0fc44cc9 */ 	jal	invHasBriefcase
/*  f1817ec:	00808025 */ 	move	$s0,$a0
/*  f1817f0:	50400058 */ 	beqzl	$v0,.PF0f181954
/*  f1817f4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1817f8:	0c002e91 */ 	jal	viGetViewLeft
/*  f1817fc:	00000000 */ 	nop
/*  f181800:	0c002e73 */ 	jal	viGetViewWidth
/*  f181804:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f181808:	87af0042 */ 	lh	$t7,0x42($sp)
/*  f18180c:	04410003 */ 	bgez	$v0,.PF0f18181c
/*  f181810:	00027043 */ 	sra	$t6,$v0,0x1
/*  f181814:	24410001 */ 	addiu	$at,$v0,0x1
/*  f181818:	00017043 */ 	sra	$t6,$at,0x1
.PF0f18181c:
/*  f18181c:	01cf2821 */ 	addu	$a1,$t6,$t7
/*  f181820:	0c002e95 */ 	jal	viGetViewTop
/*  f181824:	afa50088 */ 	sw	$a1,0x88($sp)
/*  f181828:	3c19800a */ 	lui	$t9,0x800a
/*  f18182c:	8f39a798 */ 	lw	$t9,-0x5868($t9)
/*  f181830:	2458000a */ 	addiu	$t8,$v0,0xa
/*  f181834:	afb80084 */ 	sw	$t8,0x84($sp)
/*  f181838:	8f280060 */ 	lw	$t0,0x60($t9)
/*  f18183c:	24091770 */ 	li	$t1,0x1770
/*  f181840:	240100c8 */ 	li	$at,0xc8
/*  f181844:	01281823 */ 	subu	$v1,$t1,$t0
/*  f181848:	246700c7 */ 	addiu	$a3,$v1,0xc7
/*  f18184c:	00e1001a */ 	div	$zero,$a3,$at
/*  f181850:	00003812 */ 	mflo	$a3
/*  f181854:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f181858:	24a59ae0 */ 	addiu	$a1,$a1,-25888
/*  f18185c:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f181860:	0c004d11 */ 	jal	sprintf
/*  f181864:	00003025 */ 	move	$a2,$zero
/*  f181868:	0fc550cf */ 	jal	func0f153628
/*  f18186c:	02002025 */ 	move	$a0,$s0
/*  f181870:	3c0b8008 */ 	lui	$t3,0x8008
/*  f181874:	8d6b0064 */ 	lw	$t3,0x64($t3)
/*  f181878:	3c078008 */ 	lui	$a3,0x8008
/*  f18187c:	00408025 */ 	move	$s0,$v0
/*  f181880:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f181884:	27a4008c */ 	addiu	$a0,$sp,0x8c
/*  f181888:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f18188c:	27a60044 */ 	addiu	$a2,$sp,0x44
/*  f181890:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f181894:	0fc5609a */ 	jal	textMeasure
/*  f181898:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f18189c:	8fa70090 */ 	lw	$a3,0x90($sp)
/*  f1818a0:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f1818a4:	8fa2008c */ 	lw	$v0,0x8c($sp)
/*  f1818a8:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f1818ac:	04e10003 */ 	bgez	$a3,.PF0f1818bc
/*  f1818b0:	00076043 */ 	sra	$t4,$a3,0x1
/*  f1818b4:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f1818b8:	00016043 */ 	sra	$t4,$at,0x1
.PF0f1818bc:
/*  f1818bc:	00ac2823 */ 	subu	$a1,$a1,$t4
/*  f1818c0:	00e53821 */ 	addu	$a3,$a3,$a1
/*  f1818c4:	00461021 */ 	addu	$v0,$v0,$a2
/*  f1818c8:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f1818cc:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f1818d0:	afa70090 */ 	sw	$a3,0x90($sp)
/*  f1818d4:	afa50088 */ 	sw	$a1,0x88($sp)
/*  f1818d8:	0fc551a9 */ 	jal	func0f153990
/*  f1818dc:	02002025 */ 	move	$a0,$s0
/*  f1818e0:	0c002e53 */ 	jal	viGetWidth
/*  f1818e4:	00408025 */ 	move	$s0,$v0
/*  f1818e8:	0c002e57 */ 	jal	viGetHeight
/*  f1818ec:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f1818f0:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1818f4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1818f8:	8dce005c */ 	lw	$t6,0x5c($t6)
/*  f1818fc:	8dad0060 */ 	lw	$t5,0x60($t5)
/*  f181900:	87b90040 */ 	lh	$t9,0x40($sp)
/*  f181904:	3c0f00ff */ 	lui	$t7,0xff
/*  f181908:	35ef00a0 */ 	ori	$t7,$t7,0xa0
/*  f18190c:	241800a0 */ 	li	$t8,0xa0
/*  f181910:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f181914:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f181918:	02002025 */ 	move	$a0,$s0
/*  f18191c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f181920:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f181924:	27a70044 */ 	addiu	$a3,$sp,0x44
/*  f181928:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f18192c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f181930:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f181934:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f181938:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f18193c:	0fc55fa0 */ 	jal	textRender
/*  f181940:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f181944:	0fc55125 */ 	jal	func0f153780
/*  f181948:	00402025 */ 	move	$a0,$v0
/*  f18194c:	00408025 */ 	move	$s0,$v0
/*  f181950:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PF0f181954:
/*  f181954:	02001025 */ 	move	$v0,$s0
/*  f181958:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f18195c:	03e00008 */ 	jr	$ra
/*  f181960:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);
#elif VERSION >= VERSION_NTSC_1_0
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
/*  f1808dc:	0c002f02 */ 	jal	viGetWidth
/*  f1808e0:	00408025 */ 	or	$s0,$v0,$zero
/*  f1808e4:	0c002f06 */ 	jal	viGetHeight
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
#else
GLOBAL_ASM(
glabel scenarioHtbCallback18
/*  f17adec:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f17adf0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f17adf4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f17adf8:	0fc43329 */ 	jal	invHasBriefcase
/*  f17adfc:	00808025 */ 	or	$s0,$a0,$zero
/*  f17ae00:	5040006b */ 	beqzl	$v0,.NB0f17afb0
/*  f17ae04:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f17ae08:	0c002fb5 */ 	jal	viGetViewLeft
/*  f17ae0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ae10:	0c002f97 */ 	jal	viGetViewWidth
/*  f17ae14:	a7a2004a */ 	sh	$v0,0x4a($sp)
/*  f17ae18:	87af004a */ 	lh	$t7,0x4a($sp)
/*  f17ae1c:	04410003 */ 	bgez	$v0,.NB0f17ae2c
/*  f17ae20:	00027043 */ 	sra	$t6,$v0,0x1
/*  f17ae24:	24410001 */ 	addiu	$at,$v0,0x1
/*  f17ae28:	00017043 */ 	sra	$t6,$at,0x1
.NB0f17ae2c:
/*  f17ae2c:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f17ae30:	0c002fb9 */ 	jal	viGetViewTop
/*  f17ae34:	afa30090 */ 	sw	$v1,0x90($sp)
/*  f17ae38:	3c19800a */ 	lui	$t9,0x800a
/*  f17ae3c:	8f39e948 */ 	lw	$t9,-0x16b8($t9)
/*  f17ae40:	2458000a */ 	addiu	$t8,$v0,0xa
/*  f17ae44:	afb8008c */ 	sw	$t8,0x8c($sp)
/*  f17ae48:	8f2a0060 */ 	lw	$t2,0x60($t9)
/*  f17ae4c:	24091c20 */ 	addiu	$t1,$zero,0x1c20
/*  f17ae50:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f17ae54:	012a1823 */ 	subu	$v1,$t1,$t2
/*  f17ae58:	0069001a */ 	div	$zero,$v1,$t1
/*  f17ae5c:	00004012 */ 	mflo	$t0
/*  f17ae60:	01003025 */ 	or	$a2,$t0,$zero
/*  f17ae64:	15200002 */ 	bnez	$t1,.NB0f17ae70
/*  f17ae68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ae6c:	0007000d */ 	break	0x7
.NB0f17ae70:
/*  f17ae70:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17ae74:	15210004 */ 	bne	$t1,$at,.NB0f17ae88
/*  f17ae78:	3c018000 */ 	lui	$at,0x8000
/*  f17ae7c:	14610002 */ 	bne	$v1,$at,.NB0f17ae88
/*  f17ae80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ae84:	0006000d */ 	break	0x6
.NB0f17ae88:
/*  f17ae88:	01090019 */ 	multu	$t0,$t1
/*  f17ae8c:	240100f0 */ 	addiu	$at,$zero,0xf0
/*  f17ae90:	24a52d80 */ 	addiu	$a1,$a1,0x2d80
/*  f17ae94:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f17ae98:	00005812 */ 	mflo	$t3
/*  f17ae9c:	006b1823 */ 	subu	$v1,$v1,$t3
/*  f17aea0:	246700ef */ 	addiu	$a3,$v1,0xef
/*  f17aea4:	00e1001a */ 	div	$zero,$a3,$at
/*  f17aea8:	00003812 */ 	mflo	$a3
/*  f17aeac:	0c004fc1 */ 	jal	sprintf
/*  f17aeb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17aeb4:	0fc5374a */ 	jal	func0f153628
/*  f17aeb8:	02002025 */ 	or	$a0,$s0,$zero
/*  f17aebc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f17aec0:	8dad2364 */ 	lw	$t5,0x2364($t5)
/*  f17aec4:	3c078008 */ 	lui	$a3,0x8008
/*  f17aec8:	00408025 */ 	or	$s0,$v0,$zero
/*  f17aecc:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f17aed0:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f17aed4:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f17aed8:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*  f17aedc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f17aee0:	0fc54655 */ 	jal	textMeasure
/*  f17aee4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f17aee8:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f17aeec:	8fa30090 */ 	lw	$v1,0x90($sp)
/*  f17aef0:	8faf0094 */ 	lw	$t7,0x94($sp)
/*  f17aef4:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f17aef8:	04410003 */ 	bgez	$v0,.NB0f17af08
/*  f17aefc:	00027043 */ 	sra	$t6,$v0,0x1
/*  f17af00:	24410001 */ 	addiu	$at,$v0,0x1
/*  f17af04:	00017043 */ 	sra	$t6,$at,0x1
.NB0f17af08:
/*  f17af08:	006e1823 */ 	subu	$v1,$v1,$t6
/*  f17af0c:	27aa0094 */ 	addiu	$t2,$sp,0x94
/*  f17af10:	00431021 */ 	addu	$v0,$v0,$v1
/*  f17af14:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f17af18:	afb90094 */ 	sw	$t9,0x94($sp)
/*  f17af1c:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f17af20:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f17af24:	afa30090 */ 	sw	$v1,0x90($sp)
/*  f17af28:	02002025 */ 	or	$a0,$s0,$zero
/*  f17af2c:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f17af30:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f17af34:	0fc537d6 */ 	jal	func0f153858
/*  f17af38:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f17af3c:	0c002f77 */ 	jal	viGetWidth
/*  f17af40:	00408025 */ 	or	$s0,$v0,$zero
/*  f17af44:	0c002f7b */ 	jal	viGetHeight
/*  f17af48:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f17af4c:	3c0b8008 */ 	lui	$t3,0x8008
/*  f17af50:	3c0c8008 */ 	lui	$t4,0x8008
/*  f17af54:	8d8c235c */ 	lw	$t4,0x235c($t4)
/*  f17af58:	8d6b2360 */ 	lw	$t3,0x2360($t3)
/*  f17af5c:	87af0048 */ 	lh	$t7,0x48($sp)
/*  f17af60:	3c0d00ff */ 	lui	$t5,0xff
/*  f17af64:	35ad00a0 */ 	ori	$t5,$t5,0xa0
/*  f17af68:	240e0088 */ 	addiu	$t6,$zero,0x88
/*  f17af6c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f17af70:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f17af74:	02002025 */ 	or	$a0,$s0,$zero
/*  f17af78:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f17af7c:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f17af80:	27a7004c */ 	addiu	$a3,$sp,0x4c
/*  f17af84:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f17af88:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f17af8c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f17af90:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f17af94:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f17af98:	0fc54529 */ 	jal	textRender
/*  f17af9c:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f17afa0:	0fc537a0 */ 	jal	func0f153780
/*  f17afa4:	00402025 */ 	or	$a0,$v0,$zero
/*  f17afa8:	00408025 */ 	or	$s0,$v0,$zero
/*  f17afac:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f17afb0:
/*  f17afb0:	02001025 */ 	or	$v0,$s0,$zero
/*  f17afb4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f17afb8:	03e00008 */ 	jr	$ra
/*  f17afbc:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);
#endif

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

void scenarioCtcTick(void)
{
	// empty
}

void scenarioCtcCallback14(struct chrdata *chr)
{
	if (chr);
}

struct menuitem g_MpCaptureOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222,  MPOPTION_ONEHITKILLS,     menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223,  0x00000000,               menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224,  MPOPTION_FASTMOVEMENT,    menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225,  MPOPTION_DISPLAYTEAM,     menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226,  MPOPTION_NORADAR,         menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227,  MPOPTION_NOAUTOAIM,       menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS_493, MPOPTION_KILLSSCORE,      menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_236,  MPOPTION_CTC_SHOWONRADAR, menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239,  0x00000000,               NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
};

struct menudialog g_MpCaptureOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_220, // "Capture Options"
	g_MpCaptureOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

u32 var80086b60 = 0x01000008;
u32 var80086b64 = 0x00110000;
u32 var80086b68 = 0x00420001;
u32 var80086b6c = 0x00204000;
u32 var80086b70 = 0x00000000;
u32 var80086b74 = 0x00000000;
u32 var80086b78 = 0x00000000;
u32 var80086b7c = 0x3f800000;
u32 var80086b80 = 0x00000000;
u32 var80086b84 = 0x00000000;
u32 var80086b88 = 0x00000000;
u32 var80086b8c = 0x3f800000;
u32 var80086b90 = 0x00000000;
u32 var80086b94 = 0x00000000;
u32 var80086b98 = 0x00000000;
u32 var80086b9c = 0x3f800000;
u32 var80086ba0 = 0x00000000;
u32 var80086ba4 = 0x00000000;
u32 var80086ba8 = 0x00000000;
u32 var80086bac = 0x000003e8;
u32 var80086bb0 = 0xffffff00;
u32 var80086bb4 = 0xffffff00;
u32 var80086bb8 = 0x0fff0000;
u32 var80086bbc = 0x57000000;
u32 var80086bc0 = 0x00ffffff;
u32 var80086bc4 = 0x00000000;

#if VERSION >= VERSION_NTSC_1_0
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
#else
GLOBAL_ASM(
glabel scenarioCtcReset
/*  f17b494:	27bdff28 */ 	addiu	$sp,$sp,-216
/*  f17b498:	3c0f8009 */ 	lui	$t7,0x8009
/*  f17b49c:	25ef92e0 */ 	addiu	$t7,$t7,-27936
/*  f17b4a0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f17b4a4:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f17b4a8:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f17b4ac:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f17b4b0:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f17b4b4:	25e90060 */ 	addiu	$t1,$t7,0x60
/*  f17b4b8:	27ae0050 */ 	addiu	$t6,$sp,0x50
.NB0f17b4bc:
/*  f17b4bc:	8de10000 */ 	lw	$at,0x0($t7)
/*  f17b4c0:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f17b4c4:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f17b4c8:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f17b4cc:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f17b4d0:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f17b4d4:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f17b4d8:	15e9fff8 */ 	bne	$t7,$t1,.NB0f17b4bc
/*  f17b4dc:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f17b4e0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f17b4e4:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f17b4e8:	00009025 */ 	or	$s2,$zero,$zero
/*  f17b4ec:	24030006 */ 	addiu	$v1,$zero,0x6
/*  f17b4f0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f17b4f4:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f17b4f8:	00001025 */ 	or	$v0,$zero,$zero
.NB0f17b4fc:
/*  f17b4fc:	24420001 */ 	addiu	$v0,$v0,0x1
.NB0f17b500:
/*  f17b500:	5443ffff */ 	bnel	$v0,$v1,.NB0f17b500
/*  f17b504:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f17b508:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17b50c:	2a410004 */ 	slti	$at,$s2,0x4
/*  f17b510:	5420fffa */ 	bnezl	$at,.NB0f17b4fc
/*  f17b514:	00001025 */ 	or	$v0,$zero,$zero
/*  f17b518:	3c10800b */ 	lui	$s0,0x800b
/*  f17b51c:	3c03800b */ 	lui	$v1,0x800b
/*  f17b520:	246309c8 */ 	addiu	$v1,$v1,0x9c8
/*  f17b524:	261009c0 */ 	addiu	$s0,$s0,0x9c0
/*  f17b528:	27a200b8 */ 	addiu	$v0,$sp,0xb8
.NB0f17b52c:
/*  f17b52c:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f17b530:	0203082b */ 	sltu	$at,$s0,$v1
/*  f17b534:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f17b538:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f17b53c:	1420fffb */ 	bnez	$at,.NB0f17b52c
/*  f17b540:	a600fffe */ 	sh	$zero,-0x2($s0)
/*  f17b544:	3c10800b */ 	lui	$s0,0x800b
/*  f17b548:	261009c0 */ 	addiu	$s0,$s0,0x9c0
/*  f17b54c:	00009025 */ 	or	$s2,$zero,$zero
/*  f17b550:	27b100b8 */ 	addiu	$s1,$sp,0xb8
.NB0f17b554:
/*  f17b554:	0c004d84 */ 	jal	random
/*  f17b558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17b55c:	304a0003 */ 	andi	$t2,$v0,0x3
/*  f17b560:	a60a0008 */ 	sh	$t2,0x8($s0)
/*  f17b564:	860b0008 */ 	lh	$t3,0x8($s0)
/*  f17b568:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f17b56c:	022c1821 */ 	addu	$v1,$s1,$t4
/*  f17b570:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f17b574:	15a0fff7 */ 	bnez	$t5,.NB0f17b554
/*  f17b578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17b57c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17b580:	24010004 */ 	addiu	$at,$zero,0x4
/*  f17b584:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f17b588:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f17b58c:	1641fff1 */ 	bne	$s2,$at,.NB0f17b554
/*  f17b590:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f17b594:	3c13800b */ 	lui	$s3,0x800b
/*  f17b598:	3c12800b */ 	lui	$s2,0x800b
/*  f17b59c:	26521438 */ 	addiu	$s2,$s2,0x1438
/*  f17b5a0:	267309c0 */ 	addiu	$s3,$s3,0x9c0
/*  f17b5a4:	00008825 */ 	or	$s1,$zero,$zero
/*  f17b5a8:	96580016 */ 	lhu	$t8,0x16($s2)
.NB0f17b5ac:
/*  f17b5ac:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f17b5b0:	02297804 */ 	sllv	$t7,$t1,$s1
/*  f17b5b4:	030f7024 */ 	and	$t6,$t8,$t7
/*  f17b5b8:	11c00036 */ 	beqz	$t6,.NB0f17b694
/*  f17b5bc:	2a210004 */ 	slti	$at,$s1,0x4
/*  f17b5c0:	10200008 */ 	beqz	$at,.NB0f17b5e4
/*  f17b5c4:	00116080 */ 	sll	$t4,$s1,0x2
/*  f17b5c8:	00115080 */ 	sll	$t2,$s1,0x2
/*  f17b5cc:	01515021 */ 	addu	$t2,$t2,$s1
/*  f17b5d0:	3c0b800b */ 	lui	$t3,0x800b
/*  f17b5d4:	256b1068 */ 	addiu	$t3,$t3,0x1068
/*  f17b5d8:	000a5140 */ 	sll	$t2,$t2,0x5
/*  f17b5dc:	10000009 */ 	beqz	$zero,.NB0f17b604
/*  f17b5e0:	014b8021 */ 	addu	$s0,$t2,$t3
.NB0f17b5e4:
/*  f17b5e4:	01916021 */ 	addu	$t4,$t4,$s1
/*  f17b5e8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f17b5ec:	01916023 */ 	subu	$t4,$t4,$s1
/*  f17b5f0:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f17b5f4:	3c19800b */ 	lui	$t9,0x800b
/*  f17b5f8:	27390de8 */ 	addiu	$t9,$t9,0xde8
/*  f17b5fc:	258dfed0 */ 	addiu	$t5,$t4,-304
/*  f17b600:	01b98021 */ 	addu	$s0,$t5,$t9
.NB0f17b604:
/*  f17b604:	0fc6021c */ 	jal	scenarioGetMaxTeams
/*  f17b608:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17b60c:	92090011 */ 	lbu	$t1,0x11($s0)
/*  f17b610:	0122082a */ 	slt	$at,$t1,$v0
/*  f17b614:	1420000b */ 	bnez	$at,.NB0f17b644
/*  f17b618:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f17b61c:
/*  f17b61c:	0fc6021c */ 	jal	scenarioGetMaxTeams
/*  f17b620:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17b624:	92180011 */ 	lbu	$t8,0x11($s0)
/*  f17b628:	03027823 */ 	subu	$t7,$t8,$v0
/*  f17b62c:	0fc6021c */ 	jal	scenarioGetMaxTeams
/*  f17b630:	a20f0011 */ 	sb	$t7,0x11($s0)
/*  f17b634:	920e0011 */ 	lbu	$t6,0x11($s0)
/*  f17b638:	01c2082a */ 	slt	$at,$t6,$v0
/*  f17b63c:	1020fff7 */ 	beqz	$at,.NB0f17b61c
/*  f17b640:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f17b644:
/*  f17b644:	0fc61cbb */ 	jal	func0f18d0e8
/*  f17b648:	02202025 */ 	or	$a0,$s1,$zero
/*  f17b64c:	0442000c */ 	bltzl	$v0,.NB0f17b680
/*  f17b650:	920d0011 */ 	lbu	$t5,0x11($s0)
/*  f17b654:	0fc61cbb */ 	jal	func0f18d0e8
/*  f17b658:	02202025 */ 	or	$a0,$s1,$zero
/*  f17b65c:	0fc61c91 */ 	jal	mpGetChrFromPlayerIndex
/*  f17b660:	00402025 */ 	or	$a0,$v0,$zero
/*  f17b664:	50400006 */ 	beqzl	$v0,.NB0f17b680
/*  f17b668:	920d0011 */ 	lbu	$t5,0x11($s0)
/*  f17b66c:	920a0011 */ 	lbu	$t2,0x11($s0)
/*  f17b670:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f17b674:	014b6004 */ 	sllv	$t4,$t3,$t2
/*  f17b678:	a04c0125 */ 	sb	$t4,0x125($v0)
/*  f17b67c:	920d0011 */ 	lbu	$t5,0x11($s0)
.NB0f17b680:
/*  f17b680:	000dc840 */ 	sll	$t9,$t5,0x1
/*  f17b684:	02791021 */ 	addu	$v0,$s3,$t9
/*  f17b688:	84490000 */ 	lh	$t1,0x0($v0)
/*  f17b68c:	25380001 */ 	addiu	$t8,$t1,0x1
/*  f17b690:	a4580000 */ 	sh	$t8,0x0($v0)
.NB0f17b694:
/*  f17b694:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17b698:	2a21000c */ 	slti	$at,$s1,0xc
/*  f17b69c:	5420ffc3 */ 	bnezl	$at,.NB0f17b5ac
/*  f17b6a0:	96580016 */ 	lhu	$t8,0x16($s2)
/*  f17b6a4:	3c10800b */ 	lui	$s0,0x800b
/*  f17b6a8:	3c02800b */ 	lui	$v0,0x800b
/*  f17b6ac:	244209c8 */ 	addiu	$v0,$v0,0x9c8
/*  f17b6b0:	261009c0 */ 	addiu	$s0,$s0,0x9c0
/*  f17b6b4:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f17b6b8:	860f0000 */ 	lh	$t7,0x0($s0)
.NB0f17b6bc:
/*  f17b6bc:	55e00003 */ 	bnezl	$t7,.NB0f17b6cc
/*  f17b6c0:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f17b6c4:	a6080008 */ 	sh	$t0,0x8($s0)
/*  f17b6c8:	26100002 */ 	addiu	$s0,$s0,0x2
.NB0f17b6cc:
/*  f17b6cc:	0202082b */ 	sltu	$at,$s0,$v0
/*  f17b6d0:	5420fffa */ 	bnezl	$at,.NB0f17b6bc
/*  f17b6d4:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f17b6d8:	00009025 */ 	or	$s2,$zero,$zero
/*  f17b6dc:	26520001 */ 	addiu	$s2,$s2,0x1
.NB0f17b6e0:
/*  f17b6e0:	2a410004 */ 	slti	$at,$s2,0x4
/*  f17b6e4:	5420fffe */ 	bnezl	$at,.NB0f17b6e0
/*  f17b6e8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17b6ec:	3c02800b */ 	lui	$v0,0x800b
/*  f17b6f0:	3c03800b */ 	lui	$v1,0x800b
/*  f17b6f4:	246309d0 */ 	addiu	$v1,$v1,0x9d0
/*  f17b6f8:	244209c0 */ 	addiu	$v0,$v0,0x9c0
.NB0f17b6fc:
/*  f17b6fc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f17b700:	0043082b */ 	sltu	$at,$v0,$v1
/*  f17b704:	1420fffd */ 	bnez	$at,.NB0f17b6fc
/*  f17b708:	ac400054 */ 	sw	$zero,0x54($v0)
/*  f17b70c:	3c10800b */ 	lui	$s0,0x800b
/*  f17b710:	3c02800b */ 	lui	$v0,0x800b
/*  f17b714:	244209c8 */ 	addiu	$v0,$v0,0x9c8
/*  f17b718:	261009c0 */ 	addiu	$s0,$s0,0x9c0
.NB0f17b71c:
/*  f17b71c:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f17b720:	0202082b */ 	sltu	$at,$s0,$v0
/*  f17b724:	1420fffd */ 	bnez	$at,.NB0f17b71c
/*  f17b728:	a608000e */ 	sh	$t0,0xe($s0)
/*  f17b72c:	866e0000 */ 	lh	$t6,0x0($s3)
/*  f17b730:	3c04800b */ 	lui	$a0,0x800b
/*  f17b734:	24840b70 */ 	addiu	$a0,$a0,0xb70
/*  f17b738:	11c00026 */ 	beqz	$t6,.NB0f17b7d4
/*  f17b73c:	27ab0050 */ 	addiu	$t3,$sp,0x50
/*  f17b740:	00806825 */ 	or	$t5,$a0,$zero
/*  f17b744:	256c0060 */ 	addiu	$t4,$t3,0x60
.NB0f17b748:
/*  f17b748:	8d610000 */ 	lw	$at,0x0($t3)
/*  f17b74c:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f17b750:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f17b754:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f17b758:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f17b75c:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f17b760:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f17b764:	156cfff8 */ 	bne	$t3,$t4,.NB0f17b748
/*  f17b768:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f17b76c:	8d610000 */ 	lw	$at,0x0($t3)
/*  f17b770:	240503e8 */ 	addiu	$a1,$zero,0x3e8
/*  f17b774:	ada10000 */ 	sw	$at,0x0($t5)
/*  f17b778:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*  f17b77c:	adac0004 */ 	sw	$t4,0x4($t5)
/*  f17b780:	86790008 */ 	lh	$t9,0x8($s3)
/*  f17b784:	00194900 */ 	sll	$t1,$t9,0x4
/*  f17b788:	0269c021 */ 	addu	$t8,$s3,$t1
/*  f17b78c:	870f0018 */ 	lh	$t7,0x18($t8)
/*  f17b790:	0fc034c8 */ 	jal	weaponAssignToHome
/*  f17b794:	a48f0006 */ 	sh	$t7,0x6($a0)
/*  f17b798:	3c0e800b */ 	lui	$t6,0x800b
/*  f17b79c:	8dce0b84 */ 	lw	$t6,0xb84($t6)
/*  f17b7a0:	3c0a800b */ 	lui	$t2,0x800b
/*  f17b7a4:	914a0b72 */ 	lbu	$t2,0xb72($t2)
/*  f17b7a8:	3c01800b */ 	lui	$at,0x800b
/*  f17b7ac:	ac2e0a18 */ 	sw	$t6,0xa18($at)
/*  f17b7b0:	3c01800b */ 	lui	$at,0x800b
/*  f17b7b4:	314cfffb */ 	andi	$t4,$t2,0xfffb
/*  f17b7b8:	a02c0b72 */ 	sb	$t4,0xb72($at)
/*  f17b7bc:	3c01800b */ 	lui	$at,0x800b
/*  f17b7c0:	a4200bd2 */ 	sh	$zero,0xbd2($at)
/*  f17b7c4:	8e6b0058 */ 	lw	$t3,0x58($s3)
/*  f17b7c8:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f17b7cc:	856d0028 */ 	lh	$t5,0x28($t3)
/*  f17b7d0:	a66d0010 */ 	sh	$t5,0x10($s3)
.NB0f17b7d4:
/*  f17b7d4:	86790002 */ 	lh	$t9,0x2($s3)
/*  f17b7d8:	3c04800b */ 	lui	$a0,0x800b
/*  f17b7dc:	2410fffb */ 	addiu	$s0,$zero,-5
/*  f17b7e0:	13200028 */ 	beqz	$t9,.NB0f17b884
/*  f17b7e4:	24840bd8 */ 	addiu	$a0,$a0,0xbd8
/*  f17b7e8:	27a90050 */ 	addiu	$t1,$sp,0x50
/*  f17b7ec:	252f0060 */ 	addiu	$t7,$t1,0x60
/*  f17b7f0:	00807025 */ 	or	$t6,$a0,$zero
.NB0f17b7f4:
/*  f17b7f4:	8d210000 */ 	lw	$at,0x0($t1)
/*  f17b7f8:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f17b7fc:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f17b800:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f17b804:	8d21fff8 */ 	lw	$at,-0x8($t1)
/*  f17b808:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f17b80c:	8d21fffc */ 	lw	$at,-0x4($t1)
/*  f17b810:	152ffff8 */ 	bne	$t1,$t7,.NB0f17b7f4
/*  f17b814:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f17b818:	8d210000 */ 	lw	$at,0x0($t1)
/*  f17b81c:	240503e9 */ 	addiu	$a1,$zero,0x3e9
/*  f17b820:	adc10000 */ 	sw	$at,0x0($t6)
/*  f17b824:	8d2f0004 */ 	lw	$t7,0x4($t1)
/*  f17b828:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f17b82c:	866a000a */ 	lh	$t2,0xa($s3)
/*  f17b830:	000a6100 */ 	sll	$t4,$t2,0x4
/*  f17b834:	026c5821 */ 	addu	$t3,$s3,$t4
/*  f17b838:	856d0018 */ 	lh	$t5,0x18($t3)
/*  f17b83c:	0fc034c8 */ 	jal	weaponAssignToHome
/*  f17b840:	a48d0006 */ 	sh	$t5,0x6($a0)
/*  f17b844:	3c19800b */ 	lui	$t9,0x800b
/*  f17b848:	8f390bec */ 	lw	$t9,0xbec($t9)
/*  f17b84c:	3c18800b */ 	lui	$t8,0x800b
/*  f17b850:	93180bda */ 	lbu	$t8,0xbda($t8)
/*  f17b854:	3c01800b */ 	lui	$at,0x800b
/*  f17b858:	ac390a1c */ 	sw	$t9,0xa1c($at)
/*  f17b85c:	3c01800b */ 	lui	$at,0x800b
/*  f17b860:	03107824 */ 	and	$t7,$t8,$s0
/*  f17b864:	a02f0bda */ 	sb	$t7,0xbda($at)
/*  f17b868:	3c01800b */ 	lui	$at,0x800b
/*  f17b86c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f17b870:	a4290c3a */ 	sh	$t1,0xc3a($at)
/*  f17b874:	8e6e005c */ 	lw	$t6,0x5c($s3)
/*  f17b878:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f17b87c:	85ca0028 */ 	lh	$t2,0x28($t6)
/*  f17b880:	a66a0012 */ 	sh	$t2,0x12($s3)
.NB0f17b884:
/*  f17b884:	866c0004 */ 	lh	$t4,0x4($s3)
/*  f17b888:	3c04800b */ 	lui	$a0,0x800b
/*  f17b88c:	24840c40 */ 	addiu	$a0,$a0,0xc40
/*  f17b890:	11800027 */ 	beqz	$t4,.NB0f17b930
/*  f17b894:	27ab0050 */ 	addiu	$t3,$sp,0x50
/*  f17b898:	0080c025 */ 	or	$t8,$a0,$zero
/*  f17b89c:	25790060 */ 	addiu	$t9,$t3,0x60
.NB0f17b8a0:
/*  f17b8a0:	8d610000 */ 	lw	$at,0x0($t3)
/*  f17b8a4:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f17b8a8:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f17b8ac:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f17b8b0:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f17b8b4:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f17b8b8:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f17b8bc:	1579fff8 */ 	bne	$t3,$t9,.NB0f17b8a0
/*  f17b8c0:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f17b8c4:	8d610000 */ 	lw	$at,0x0($t3)
/*  f17b8c8:	240503ea */ 	addiu	$a1,$zero,0x3ea
/*  f17b8cc:	af010000 */ 	sw	$at,0x0($t8)
/*  f17b8d0:	8d790004 */ 	lw	$t9,0x4($t3)
/*  f17b8d4:	af190004 */ 	sw	$t9,0x4($t8)
/*  f17b8d8:	866f000c */ 	lh	$t7,0xc($s3)
/*  f17b8dc:	000f4900 */ 	sll	$t1,$t7,0x4
/*  f17b8e0:	02697021 */ 	addu	$t6,$s3,$t1
/*  f17b8e4:	85ca0018 */ 	lh	$t2,0x18($t6)
/*  f17b8e8:	0fc034c8 */ 	jal	weaponAssignToHome
/*  f17b8ec:	a48a0006 */ 	sh	$t2,0x6($a0)
/*  f17b8f0:	3c0c800b */ 	lui	$t4,0x800b
/*  f17b8f4:	8d8c0c54 */ 	lw	$t4,0xc54($t4)
/*  f17b8f8:	3c0d800b */ 	lui	$t5,0x800b
/*  f17b8fc:	91ad0c42 */ 	lbu	$t5,0xc42($t5)
/*  f17b900:	3c01800b */ 	lui	$at,0x800b
/*  f17b904:	ac2c0a20 */ 	sw	$t4,0xa20($at)
/*  f17b908:	3c01800b */ 	lui	$at,0x800b
/*  f17b90c:	01b0c824 */ 	and	$t9,$t5,$s0
/*  f17b910:	a0390c42 */ 	sb	$t9,0xc42($at)
/*  f17b914:	3c01800b */ 	lui	$at,0x800b
/*  f17b918:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f17b91c:	a42b0ca2 */ 	sh	$t3,0xca2($at)
/*  f17b920:	8e780060 */ 	lw	$t8,0x60($s3)
/*  f17b924:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f17b928:	870f0028 */ 	lh	$t7,0x28($t8)
/*  f17b92c:	a66f0014 */ 	sh	$t7,0x14($s3)
.NB0f17b930:
/*  f17b930:	86690006 */ 	lh	$t1,0x6($s3)
/*  f17b934:	3c04800b */ 	lui	$a0,0x800b
/*  f17b938:	24840ca8 */ 	addiu	$a0,$a0,0xca8
/*  f17b93c:	11200027 */ 	beqz	$t1,.NB0f17b9dc
/*  f17b940:	27ae0050 */ 	addiu	$t6,$sp,0x50
/*  f17b944:	00806825 */ 	or	$t5,$a0,$zero
/*  f17b948:	25cc0060 */ 	addiu	$t4,$t6,0x60
.NB0f17b94c:
/*  f17b94c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f17b950:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f17b954:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f17b958:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f17b95c:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f17b960:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f17b964:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f17b968:	15ccfff8 */ 	bne	$t6,$t4,.NB0f17b94c
/*  f17b96c:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f17b970:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f17b974:	240503eb */ 	addiu	$a1,$zero,0x3eb
/*  f17b978:	ada10000 */ 	sw	$at,0x0($t5)
/*  f17b97c:	8dcc0004 */ 	lw	$t4,0x4($t6)
/*  f17b980:	adac0004 */ 	sw	$t4,0x4($t5)
/*  f17b984:	8679000e */ 	lh	$t9,0xe($s3)
/*  f17b988:	00195900 */ 	sll	$t3,$t9,0x4
/*  f17b98c:	026bc021 */ 	addu	$t8,$s3,$t3
/*  f17b990:	870f0018 */ 	lh	$t7,0x18($t8)
/*  f17b994:	0fc034c8 */ 	jal	weaponAssignToHome
/*  f17b998:	a48f0006 */ 	sh	$t7,0x6($a0)
/*  f17b99c:	3c09800b */ 	lui	$t1,0x800b
/*  f17b9a0:	8d290cbc */ 	lw	$t1,0xcbc($t1)
/*  f17b9a4:	3c0a800b */ 	lui	$t2,0x800b
/*  f17b9a8:	914a0caa */ 	lbu	$t2,0xcaa($t2)
/*  f17b9ac:	3c01800b */ 	lui	$at,0x800b
/*  f17b9b0:	ac290a24 */ 	sw	$t1,0xa24($at)
/*  f17b9b4:	3c01800b */ 	lui	$at,0x800b
/*  f17b9b8:	01506024 */ 	and	$t4,$t2,$s0
/*  f17b9bc:	a02c0caa */ 	sb	$t4,0xcaa($at)
/*  f17b9c0:	3c01800b */ 	lui	$at,0x800b
/*  f17b9c4:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f17b9c8:	a42e0d0a */ 	sh	$t6,0xd0a($at)
/*  f17b9cc:	8e6d0064 */ 	lw	$t5,0x64($s3)
/*  f17b9d0:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f17b9d4:	85b90028 */ 	lh	$t9,0x28($t5)
/*  f17b9d8:	a6790016 */ 	sh	$t9,0x16($s3)
.NB0f17b9dc:
/*  f17b9dc:	3c10800b */ 	lui	$s0,0x800b
/*  f17b9e0:	3c11800b */ 	lui	$s1,0x800b
/*  f17b9e4:	263109c8 */ 	addiu	$s1,$s1,0x9c8
/*  f17b9e8:	261009c0 */ 	addiu	$s0,$s0,0x9c0
/*  f17b9ec:	860b0000 */ 	lh	$t3,0x0($s0)
.NB0f17b9f0:
/*  f17b9f0:	5160000a */ 	beqzl	$t3,.NB0f17ba1c
/*  f17b9f4:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f17b9f8:	86040010 */ 	lh	$a0,0x10($s0)
/*  f17b9fc:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f17ba00:	00003025 */ 	or	$a2,$zero,$zero
/*  f17ba04:	11040004 */ 	beq	$t0,$a0,.NB0f17ba18
/*  f17ba08:	00003825 */ 	or	$a3,$zero,$zero
/*  f17ba0c:	0fc00b2e */ 	jal	roomSetLighting
/*  f17ba10:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f17ba14:	2408ffff */ 	addiu	$t0,$zero,-1
.NB0f17ba18:
/*  f17ba18:	26100002 */ 	addiu	$s0,$s0,0x2
.NB0f17ba1c:
/*  f17ba1c:	5611fff4 */ 	bnel	$s0,$s1,.NB0f17b9f0
/*  f17ba20:	860b0000 */ 	lh	$t3,0x0($s0)
/*  f17ba24:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17ba28:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f17ba2c:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f17ba30:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f17ba34:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f17ba38:	03e00008 */ 	jr	$ra
/*  f17ba3c:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
);
#endif

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

void mpCtcAddPad(s32 *cmd)
{
	s32 i;

	if (cmd[0] == INTROCMD_CASE) {
		g_ScenarioData.ctc.spawnpadsperteam[cmd[1]].teamindex = cmd[2];
	}

	if (cmd[0] == INTROCMD_CASERESPAWN) {
		for (i = 0; i != ARRAYCOUNT(g_ScenarioData.ctc.spawnpadsperteam[cmd[1]].spawnpads); i++) {
			if (g_ScenarioData.ctc.spawnpadsperteam[cmd[1]].spawnpads[i] == -1) {
				g_ScenarioData.ctc.spawnpadsperteam[cmd[1]].spawnpads[i] = cmd[2];
				g_ScenarioData.ctc.spawnpadsperteam[cmd[1]].numspawnpads++;
				return;
			}
		}
	}
}

bool scenarioCtcChooseSpawnLocation(f32 arg0, struct coord *pos, s16 *rooms, struct prop *prop, f32 *arg4)
{
	struct chrdata *chr = prop->chr;
	s32 index = radarGetTeamIndex(chr->team);

	if (g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[index]].numspawnpads > 0) {
		*arg4 = playerChooseSpawnLocation(arg0, pos, rooms, prop,
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

s32 menuhandlerMpHillTime(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_Vars.mphilltime;
		break;
	case MENUOP_SET:
		g_Vars.mphilltime = (u8)data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, langGet(L_MPWEAPONS_023), data->slider.value + 10); // "%ds/Point"
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
	g_ScenarioData.koh.hillrooms[0] = -1;
	g_ScenarioData.koh.hillrooms[1] = -1;
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
	g_ScenarioData.koh.hillrooms[0] = pad.room;
	g_ScenarioData.koh.hillrooms[1] = -1;
	g_ScenarioData.koh.hillpos.x = pad.pos.x;
	g_ScenarioData.koh.hillpos.y = pad.pos.y;
	g_ScenarioData.koh.hillpos.z = pad.pos.z;
	g_ScenarioData.koh.hillpos.y = func0002a36c(&g_ScenarioData.koh.hillpos, &g_ScenarioData.koh.hillrooms[0], 0, 0);
	g_ScenarioData.koh.unk08 = 0;
	roomSetLighting(g_ScenarioData.koh.hillrooms[0], LIGHTOP_5, 0, 0, 0);
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel scenarioKohTick
.late_rodata
glabel var7f1b893c
.word 0x3f733333
glabel var7f1b8940
.word 0x3d7487fd
glabel var7f1b8944
.word 0x3f70b780
glabel var7f1b8948
.word 0x3f70b780
glabel var7f1b894c
.word 0x3d7487fd
glabel var7f1b8950
.word 0x3d7487fd
.text
/*  f182cf4:	27bdfe78 */ 	addiu	$sp,$sp,-392
/*  f182cf8:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f182cfc:	3c13800b */ 	lui	$s3,0x800b
/*  f182d00:	2673c6b0 */ 	addiu	$s3,$s3,-14672
/*  f182d04:	866e000a */ 	lh	$t6,0xa($s3)
/*  f182d08:	2401ffff */ 	li	$at,-1
/*  f182d0c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f182d10:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f182d14:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f182d18:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f182d1c:	11c1024f */ 	beq	$t6,$at,.PF0f18365c
/*  f182d20:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f182d24:	866f0008 */ 	lh	$t7,0x8($s3)
/*  f182d28:	00003825 */ 	move	$a3,$zero
/*  f182d2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f182d30:	11e00058 */ 	beqz	$t7,.PF0f182e94
/*  f182d34:	00000000 */ 	nop
/*  f182d38:	44811000 */ 	mtc1	$at,$f2
/*  f182d3c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f182d40:	c42c9f8c */ 	lwc1	$f12,-0x6074($at)
/*  f182d44:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f182d48:	2418ffff */ 	li	$t8,-1
/*  f182d4c:	a6780004 */ 	sh	$t8,0x4($s3)
/*  f182d50:	4600603e */ 	c.le.s	$f12,$f0
/*  f182d54:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f182d58:	e7a20164 */ 	swc1	$f2,0x164($sp)
/*  f182d5c:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f182d60:	45000047 */ 	bc1f	.PF0f182e80
/*  f182d64:	e7a2015c */ 	swc1	$f2,0x15c($sp)
/*  f182d68:	c6640034 */ 	lwc1	$f4,0x34($s3)
/*  f182d6c:	4604603e */ 	c.le.s	$f12,$f4
/*  f182d70:	00000000 */ 	nop
/*  f182d74:	45000042 */ 	bc1f	.PF0f182e80
/*  f182d78:	00000000 */ 	nop
/*  f182d7c:	c6660038 */ 	lwc1	$f6,0x38($s3)
/*  f182d80:	00002825 */ 	move	$a1,$zero
/*  f182d84:	00003025 */ 	move	$a2,$zero
/*  f182d88:	4606603e */ 	c.le.s	$f12,$f6
/*  f182d8c:	00003825 */ 	move	$a3,$zero
/*  f182d90:	4500003b */ 	bc1f	.PF0f182e80
/*  f182d94:	00000000 */ 	nop
/*  f182d98:	8664000e */ 	lh	$a0,0xe($s3)
/*  f182d9c:	0fc00b0a */ 	jal	roomSetLighting
/*  f182da0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f182da4:	8679000c */ 	lh	$t9,0xc($s3)
/*  f182da8:	00002025 */ 	move	$a0,$zero
/*  f182dac:	2b210002 */ 	slti	$at,$t9,0x2
/*  f182db0:	54200013 */ 	bnezl	$at,.PF0f182e00
/*  f182db4:	a660000a */ 	sh	$zero,0xa($s3)
/*  f182db8:	8670000a */ 	lh	$s0,0xa($s3)
.PF0f182dbc:
/*  f182dbc:	0c004ad4 */ 	jal	random
/*  f182dc0:	00000000 */ 	nop
/*  f182dc4:	8668000c */ 	lh	$t0,0xc($s3)
/*  f182dc8:	0048001b */ 	divu	$zero,$v0,$t0
/*  f182dcc:	00004810 */ 	mfhi	$t1
/*  f182dd0:	a669000a */ 	sh	$t1,0xa($s3)
/*  f182dd4:	8663000a */ 	lh	$v1,0xa($s3)
/*  f182dd8:	15000002 */ 	bnez	$t0,.PF0f182de4
/*  f182ddc:	00000000 */ 	nop
/*  f182de0:	0007000d */ 	break	0x7
.PF0f182de4:
/*  f182de4:	1203fff5 */ 	beq	$s0,$v1,.PF0f182dbc
/*  f182de8:	00000000 */ 	nop
/*  f182dec:	00035040 */ 	sll	$t2,$v1,0x1
/*  f182df0:	026a5821 */ 	addu	$t3,$s3,$t2
/*  f182df4:	10000002 */ 	b	.PF0f182e00
/*  f182df8:	85640012 */ 	lh	$a0,0x12($t3)
/*  f182dfc:	a660000a */ 	sh	$zero,0xa($s3)
.PF0f182e00:
/*  f182e00:	24050042 */ 	li	$a1,0x42
/*  f182e04:	0fc45964 */ 	jal	padUnpack
/*  f182e08:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f182e0c:	8fac00f0 */ 	lw	$t4,0xf0($sp)
/*  f182e10:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
/*  f182e14:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f182e18:	c7b200b0 */ 	lwc1	$f18,0xb0($sp)
/*  f182e1c:	240dffff */ 	li	$t5,-1
/*  f182e20:	3c04800b */ 	lui	$a0,0x800b
/*  f182e24:	3c05800b */ 	lui	$a1,0x800b
/*  f182e28:	a66d0010 */ 	sh	$t5,0x10($s3)
/*  f182e2c:	24a5c6be */ 	addiu	$a1,$a1,-14658
/*  f182e30:	2484c6d4 */ 	addiu	$a0,$a0,-14636
/*  f182e34:	00003025 */ 	move	$a2,$zero
/*  f182e38:	00003825 */ 	move	$a3,$zero
/*  f182e3c:	a66c000e */ 	sh	$t4,0xe($s3)
/*  f182e40:	e6680024 */ 	swc1	$f8,0x24($s3)
/*  f182e44:	e66a0028 */ 	swc1	$f10,0x28($s3)
/*  f182e48:	0c00a71b */ 	jal	func0002a36c
/*  f182e4c:	e672002c */ 	swc1	$f18,0x2c($s3)
/*  f182e50:	e6600028 */ 	swc1	$f0,0x28($s3)
/*  f182e54:	8664000e */ 	lh	$a0,0xe($s3)
/*  f182e58:	24050005 */ 	li	$a1,0x5
/*  f182e5c:	00003025 */ 	move	$a2,$zero
/*  f182e60:	00003825 */ 	move	$a3,$zero
/*  f182e64:	0fc00b0a */ 	jal	roomSetLighting
/*  f182e68:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f182e6c:	240effff */ 	li	$t6,-1
/*  f182e70:	a66e0004 */ 	sh	$t6,0x4($s3)
/*  f182e74:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f182e78:	a6600008 */ 	sh	$zero,0x8($s3)
/*  f182e7c:	c6600030 */ 	lwc1	$f0,0x30($s3)
.PF0f182e80:
/*  f182e80:	3c14800a */ 	lui	$s4,0x800a
/*  f182e84:	2694a510 */ 	addiu	$s4,$s4,-23280
/*  f182e88:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f182e8c:	10000198 */ 	b	.PF0f1834f0
/*  f182e90:	c6700038 */ 	lwc1	$f16,0x38($s3)
.PF0f182e94:
/*  f182e94:	3c14800a */ 	lui	$s4,0x800a
/*  f182e98:	2694a510 */ 	addiu	$s4,$s4,-23280
/*  f182e9c:	8e83033c */ 	lw	$v1,0x33c($s4)
/*  f182ea0:	00003025 */ 	move	$a2,$zero
/*  f182ea4:	24120003 */ 	li	$s2,0x3
/*  f182ea8:	1060001e */ 	beqz	$v1,.PF0f182f24
/*  f182eac:	24100006 */ 	li	$s0,0x6
/*  f182eb0:	90620000 */ 	lbu	$v0,0x0($v1)
.PF0f182eb4:
/*  f182eb4:	52020004 */ 	beql	$s0,$v0,.PF0f182ec8
/*  f182eb8:	846f0028 */ 	lh	$t7,0x28($v1)
/*  f182ebc:	56420017 */ 	bnel	$s2,$v0,.PF0f182f1c
/*  f182ec0:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f182ec4:	846f0028 */ 	lh	$t7,0x28($v1)
.PF0f182ec8:
/*  f182ec8:	8678000e */ 	lh	$t8,0xe($s3)
/*  f182ecc:	00008825 */ 	move	$s1,$zero
/*  f182ed0:	15f80002 */ 	bne	$t7,$t8,.PF0f182edc
/*  f182ed4:	00000000 */ 	nop
/*  f182ed8:	24110001 */ 	li	$s1,0x1
.PF0f182edc:
/*  f182edc:	5220000f */ 	beqzl	$s1,.PF0f182f1c
/*  f182ee0:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f182ee4:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f182ee8:	afa70170 */ 	sw	$a3,0x170($sp)
/*  f182eec:	afa60174 */ 	sw	$a2,0x174($sp)
/*  f182ef0:	0fc0e706 */ 	jal	chrIsDead
/*  f182ef4:	afa30074 */ 	sw	$v1,0x74($sp)
/*  f182ef8:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f182efc:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f182f00:	14400005 */ 	bnez	$v0,.PF0f182f18
/*  f182f04:	8fa70170 */ 	lw	$a3,0x170($sp)
/*  f182f08:	0006c880 */ 	sll	$t9,$a2,0x2
/*  f182f0c:	03b94021 */ 	addu	$t0,$sp,$t9
/*  f182f10:	ad030078 */ 	sw	$v1,0x78($t0)
/*  f182f14:	24c60001 */ 	addiu	$a2,$a2,0x1
.PF0f182f18:
/*  f182f18:	8c630020 */ 	lw	$v1,0x20($v1)
.PF0f182f1c:
/*  f182f1c:	5460ffe5 */ 	bnezl	$v1,.PF0f182eb4
/*  f182f20:	90620000 */ 	lbu	$v0,0x0($v1)
.PF0f182f24:
/*  f182f24:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182f28:	27a3011c */ 	addiu	$v1,$sp,0x11c
.PF0f182f2c:
/*  f182f2c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f182f30:	0043082b */ 	sltu	$at,$v0,$v1
/*  f182f34:	1420fffd */ 	bnez	$at,.PF0f182f2c
/*  f182f38:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f182f3c:	00008025 */ 	move	$s0,$zero
/*  f182f40:	18c00017 */ 	blez	$a2,.PF0f182fa0
/*  f182f44:	00009025 */ 	move	$s2,$zero
/*  f182f48:	27a30078 */ 	addiu	$v1,$sp,0x78
/*  f182f4c:	27b100fc */ 	addiu	$s1,$sp,0xfc
.PF0f182f50:
/*  f182f50:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f182f54:	8d250004 */ 	lw	$a1,0x4($t1)
/*  f182f58:	90a40125 */ 	lbu	$a0,0x125($a1)
/*  f182f5c:	afa70170 */ 	sw	$a3,0x170($sp)
/*  f182f60:	afa60174 */ 	sw	$a2,0x174($sp)
/*  f182f64:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f182f68:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f182f6c:	00025080 */ 	sll	$t2,$v0,0x2
/*  f182f70:	022a2021 */ 	addu	$a0,$s1,$t2
/*  f182f74:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f182f78:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f182f7c:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f182f80:	15600004 */ 	bnez	$t3,.PF0f182f94
/*  f182f84:	8fa70170 */ 	lw	$a3,0x170($sp)
/*  f182f88:	240c0001 */ 	li	$t4,0x1
/*  f182f8c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f182f90:	ac8c0000 */ 	sw	$t4,0x0($a0)
.PF0f182f94:
/*  f182f94:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f182f98:	1606ffed */ 	bne	$s0,$a2,.PF0f182f50
/*  f182f9c:	24630004 */ 	addiu	$v1,$v1,0x4
.PF0f182fa0:
/*  f182fa0:	16400005 */ 	bnez	$s2,.PF0f182fb8
/*  f182fa4:	24010001 */ 	li	$at,0x1
/*  f182fa8:	240dffff */ 	li	$t5,-1
/*  f182fac:	a66d0004 */ 	sh	$t5,0x4($s3)
/*  f182fb0:	10000122 */ 	b	.PF0f18343c
/*  f182fb4:	a6600006 */ 	sh	$zero,0x6($s3)
.PF0f182fb8:
/*  f182fb8:	1641000b */ 	bne	$s2,$at,.PF0f182fe8
/*  f182fbc:	00008025 */ 	move	$s0,$zero
/*  f182fc0:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182fc4:	24030008 */ 	li	$v1,0x8
.PF0f182fc8:
/*  f182fc8:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f182fcc:	55c0003d */ 	bnezl	$t6,.PF0f1830c4
/*  f182fd0:	866a0004 */ 	lh	$t2,0x4($s3)
/*  f182fd4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f182fd8:	1603fffb */ 	bne	$s0,$v1,.PF0f182fc8
/*  f182fdc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f182fe0:	10000038 */ 	b	.PF0f1830c4
/*  f182fe4:	866a0004 */ 	lh	$t2,0x4($s3)
.PF0f182fe8:
/*  f182fe8:	00008825 */ 	move	$s1,$zero
/*  f182fec:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182ff0:	27a4011c */ 	addiu	$a0,$sp,0x11c
/*  f182ff4:	8c430000 */ 	lw	$v1,0x0($v0)
.PF0f182ff8:
/*  f182ff8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f182ffc:	0223082a */ 	slt	$at,$s1,$v1
/*  f183000:	50200003 */ 	beqzl	$at,.PF0f183010
/*  f183004:	0044082b */ 	sltu	$at,$v0,$a0
/*  f183008:	00608825 */ 	move	$s1,$v1
/*  f18300c:	0044082b */ 	sltu	$at,$v0,$a0
.PF0f183010:
/*  f183010:	5420fff9 */ 	bnezl	$at,.PF0f182ff8
/*  f183014:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f183018:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f18301c:	27a3011c */ 	addiu	$v1,$sp,0x11c
/*  f183020:	8c4f0000 */ 	lw	$t7,0x0($v0)
.PF0f183024:
/*  f183024:	522f0003 */ 	beql	$s1,$t7,.PF0f183034
/*  f183028:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18302c:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f183030:	24420004 */ 	addiu	$v0,$v0,0x4
.PF0f183034:
/*  f183034:	0043082b */ 	sltu	$at,$v0,$v1
/*  f183038:	5420fffa */ 	bnezl	$at,.PF0f183024
/*  f18303c:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f183040:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f183044:	27a3011c */ 	addiu	$v1,$sp,0x11c
/*  f183048:	8c580000 */ 	lw	$t8,0x0($v0)
.PF0f18304c:
/*  f18304c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f183050:	0043082b */ 	sltu	$at,$v0,$v1
/*  f183054:	13000002 */ 	beqz	$t8,.PF0f183060
/*  f183058:	00000000 */ 	nop
/*  f18305c:	24e70001 */ 	addiu	$a3,$a3,0x1
.PF0f183060:
/*  f183060:	5420fffa */ 	bnezl	$at,.PF0f18304c
/*  f183064:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f183068:	28e10002 */ 	slti	$at,$a3,0x2
/*  f18306c:	14200003 */ 	bnez	$at,.PF0f18307c
/*  f183070:	00008025 */ 	move	$s0,$zero
/*  f183074:	10000002 */ 	b	.PF0f183080
/*  f183078:	24070001 */ 	li	$a3,0x1
.PF0f18307c:
/*  f18307c:	00003825 */ 	move	$a3,$zero
.PF0f183080:
/*  f183080:	27a200fc */ 	addiu	$v0,$sp,0xfc
.PF0f183084:
/*  f183084:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f183088:	53200005 */ 	beqzl	$t9,.PF0f1830a0
/*  f18308c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183090:	86680004 */ 	lh	$t0,0x4($s3)
/*  f183094:	52080006 */ 	beql	$s0,$t0,.PF0f1830b0
/*  f183098:	24030008 */ 	li	$v1,0x8
/*  f18309c:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f1830a0:
/*  f1830a0:	2a010008 */ 	slti	$at,$s0,0x8
/*  f1830a4:	1420fff7 */ 	bnez	$at,.PF0f183084
/*  f1830a8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1830ac:	24030008 */ 	li	$v1,0x8
.PF0f1830b0:
/*  f1830b0:	16030003 */ 	bne	$s0,$v1,.PF0f1830c0
/*  f1830b4:	2409ffff */ 	li	$t1,-1
/*  f1830b8:	a6690004 */ 	sh	$t1,0x4($s3)
/*  f1830bc:	2410ffff */ 	li	$s0,-1
.PF0f1830c0:
/*  f1830c0:	866a0004 */ 	lh	$t2,0x4($s3)
.PF0f1830c4:
/*  f1830c4:	3c048009 */ 	lui	$a0,0x8009
/*  f1830c8:	240505b9 */ 	li	$a1,0x5b9
/*  f1830cc:	120a0070 */ 	beq	$s0,$t2,.PF0f183290
/*  f1830d0:	00003025 */ 	move	$a2,$zero
/*  f1830d4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1830d8:	44812000 */ 	mtc1	$at,$f4
/*  f1830dc:	240bffff */ 	li	$t3,-1
/*  f1830e0:	240cffff */ 	li	$t4,-1
/*  f1830e4:	240dffff */ 	li	$t5,-1
/*  f1830e8:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1830ec:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1830f0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f1830f4:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f1830f8:	2407ffff */ 	li	$a3,-1
/*  f1830fc:	00008825 */ 	move	$s1,$zero
/*  f183100:	0c0041a0 */ 	jal	sndStart
/*  f183104:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f183108:	a6700004 */ 	sh	$s0,0x4($s3)
/*  f18310c:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f183110:	0fc5bdaa */ 	jal	langGet
/*  f183114:	24045417 */ 	li	$a0,0x5417
/*  f183118:	00107080 */ 	sll	$t6,$s0,0x2
/*  f18311c:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f183120:	3c0f800b */ 	lui	$t7,0x800b
/*  f183124:	25efd150 */ 	addiu	$t7,$t7,-11952
/*  f183128:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18312c:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f183130:	27a4011c */ 	addiu	$a0,$sp,0x11c
/*  f183134:	0c004d11 */ 	jal	sprintf
/*  f183138:	00402825 */ 	move	$a1,$v0
/*  f18313c:	8e98006c */ 	lw	$t8,0x6c($s4)
/*  f183140:	27b0011c */ 	addiu	$s0,$sp,0x11c
/*  f183144:	8e92028c */ 	lw	$s2,0x28c($s4)
/*  f183148:	13000003 */ 	beqz	$t8,.PF0f183158
/*  f18314c:	00002825 */ 	move	$a1,$zero
/*  f183150:	10000001 */ 	b	.PF0f183158
/*  f183154:	24050001 */ 	li	$a1,0x1
.PF0f183158:
/*  f183158:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f18315c:	00002025 */ 	move	$a0,$zero
/*  f183160:	00001825 */ 	move	$v1,$zero
/*  f183164:	13200003 */ 	beqz	$t9,.PF0f183174
/*  f183168:	00001025 */ 	move	$v0,$zero
/*  f18316c:	10000001 */ 	b	.PF0f183174
/*  f183170:	24040001 */ 	li	$a0,0x1
.PF0f183174:
/*  f183174:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f183178:	11000003 */ 	beqz	$t0,.PF0f183188
/*  f18317c:	00000000 */ 	nop
/*  f183180:	10000001 */ 	b	.PF0f183188
/*  f183184:	24030001 */ 	li	$v1,0x1
.PF0f183188:
/*  f183188:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f18318c:	11200003 */ 	beqz	$t1,.PF0f18319c
/*  f183190:	00000000 */ 	nop
/*  f183194:	10000001 */ 	b	.PF0f18319c
/*  f183198:	24020001 */ 	li	$v0,0x1
.PF0f18319c:
/*  f18319c:	00435021 */ 	addu	$t2,$v0,$v1
/*  f1831a0:	01445821 */ 	addu	$t3,$t2,$a0
/*  f1831a4:	01656021 */ 	addu	$t4,$t3,$a1
/*  f1831a8:	19800035 */ 	blez	$t4,.PF0f183280
/*  f1831ac:	00000000 */ 	nop
.PF0f1831b0:
/*  f1831b0:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f1831b4:	02202025 */ 	move	$a0,$s1
/*  f1831b8:	8e8d0284 */ 	lw	$t5,0x284($s4)
/*  f1831bc:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f1831c0:	8dc50004 */ 	lw	$a1,0x4($t6)
/*  f1831c4:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f1831c8:	90a40125 */ 	lbu	$a0,0x125($a1)
/*  f1831cc:	866f0004 */ 	lh	$t7,0x4($s3)
/*  f1831d0:	02002025 */ 	move	$a0,$s0
/*  f1831d4:	24050009 */ 	li	$a1,0x9
/*  f1831d8:	144f0009 */ 	bne	$v0,$t7,.PF0f183200
/*  f1831dc:	00000000 */ 	nop
/*  f1831e0:	0fc5bdaa */ 	jal	langGet
/*  f1831e4:	24045416 */ 	li	$a0,0x5416
/*  f1831e8:	00402025 */ 	move	$a0,$v0
/*  f1831ec:	24050009 */ 	li	$a1,0x9
/*  f1831f0:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f1831f4:	24060001 */ 	li	$a2,0x1
/*  f1831f8:	10000004 */ 	b	.PF0f18320c
/*  f1831fc:	8e98006c */ 	lw	$t8,0x6c($s4)
.PF0f183200:
/*  f183200:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f183204:	24060001 */ 	li	$a2,0x1
/*  f183208:	8e98006c */ 	lw	$t8,0x6c($s4)
.PF0f18320c:
/*  f18320c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f183210:	00002825 */ 	move	$a1,$zero
/*  f183214:	13000003 */ 	beqz	$t8,.PF0f183224
/*  f183218:	00002025 */ 	move	$a0,$zero
/*  f18321c:	10000001 */ 	b	.PF0f183224
/*  f183220:	24050001 */ 	li	$a1,0x1
.PF0f183224:
/*  f183224:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f183228:	00001825 */ 	move	$v1,$zero
/*  f18322c:	00001025 */ 	move	$v0,$zero
/*  f183230:	13200003 */ 	beqz	$t9,.PF0f183240
/*  f183234:	00000000 */ 	nop
/*  f183238:	10000001 */ 	b	.PF0f183240
/*  f18323c:	24040001 */ 	li	$a0,0x1
.PF0f183240:
/*  f183240:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f183244:	11000003 */ 	beqz	$t0,.PF0f183254
/*  f183248:	00000000 */ 	nop
/*  f18324c:	10000001 */ 	b	.PF0f183254
/*  f183250:	24030001 */ 	li	$v1,0x1
.PF0f183254:
/*  f183254:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f183258:	11200003 */ 	beqz	$t1,.PF0f183268
/*  f18325c:	00000000 */ 	nop
/*  f183260:	10000001 */ 	b	.PF0f183268
/*  f183264:	24020001 */ 	li	$v0,0x1
.PF0f183268:
/*  f183268:	00435021 */ 	addu	$t2,$v0,$v1
/*  f18326c:	01445821 */ 	addu	$t3,$t2,$a0
/*  f183270:	01656021 */ 	addu	$t4,$t3,$a1
/*  f183274:	022c082a */ 	slt	$at,$s1,$t4
/*  f183278:	1420ffcd */ 	bnez	$at,.PF0f1831b0
/*  f18327c:	00000000 */ 	nop
.PF0f183280:
/*  f183280:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f183284:	02402025 */ 	move	$a0,$s2
/*  f183288:	1000006d */ 	b	.PF0f183440
/*  f18328c:	86630004 */ 	lh	$v1,0x4($s3)
.PF0f183290:
/*  f183290:	54e0006b */ 	bnezl	$a3,.PF0f183440
/*  f183294:	86630004 */ 	lh	$v1,0x4($s3)
/*  f183298:	8e990484 */ 	lw	$t9,0x484($s4)
/*  f18329c:	866d0006 */ 	lh	$t5,0x6($s3)
/*  f1832a0:	8e8e0034 */ 	lw	$t6,0x34($s4)
/*  f1832a4:	00194080 */ 	sll	$t0,$t9,0x2
/*  f1832a8:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1832ac:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f1832b0:	a66f0006 */ 	sh	$t7,0x6($s3)
/*  f1832b4:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f1832b8:	86780006 */ 	lh	$t8,0x6($s3)
/*  f1832bc:	01194021 */ 	addu	$t0,$t0,$t9
/*  f1832c0:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f1832c4:	250907d0 */ 	addiu	$t1,$t0,0x7d0
/*  f1832c8:	0309082a */ 	slt	$at,$t8,$t1
/*  f1832cc:	1420005b */ 	bnez	$at,.PF0f18343c
/*  f1832d0:	3c048009 */ 	lui	$a0,0x8009
/*  f1832d4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1832d8:	44813000 */ 	mtc1	$at,$f6
/*  f1832dc:	240affff */ 	li	$t2,-1
/*  f1832e0:	240bffff */ 	li	$t3,-1
/*  f1832e4:	240cffff */ 	li	$t4,-1
/*  f1832e8:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f1832ec:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1832f0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1832f4:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f1832f8:	240505b8 */ 	li	$a1,0x5b8
/*  f1832fc:	00003025 */ 	move	$a2,$zero
/*  f183300:	2407ffff */ 	li	$a3,-1
/*  f183304:	00009025 */ 	move	$s2,$zero
/*  f183308:	0c0041a0 */ 	jal	sndStart
/*  f18330c:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f183310:	3c03800b */ 	lui	$v1,0x800b
/*  f183314:	8c63cad0 */ 	lw	$v1,-0x3530($v1)
/*  f183318:	3c10800b */ 	lui	$s0,0x800b
/*  f18331c:	2610ca70 */ 	addiu	$s0,$s0,-13712
/*  f183320:	1860001e */ 	blez	$v1,.PF0f18339c
/*  f183324:	00002825 */ 	move	$a1,$zero
/*  f183328:	3c11800b */ 	lui	$s1,0x800b
/*  f18332c:	2631caa0 */ 	addiu	$s1,$s1,-13664
.PF0f183330:
/*  f183330:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f183334:	91a40125 */ 	lbu	$a0,0x125($t5)
/*  f183338:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f18333c:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f183340:	866e0004 */ 	lh	$t6,0x4($s3)
/*  f183344:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f183348:	144e000c */ 	bne	$v0,$t6,.PF0f18337c
/*  f18334c:	00000000 */ 	nop
/*  f183350:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f183354:	8668000e */ 	lh	$t0,0xe($s3)
/*  f183358:	0225c021 */ 	addu	$t8,$s1,$a1
/*  f18335c:	8de3001c */ 	lw	$v1,0x1c($t7)
/*  f183360:	84790028 */ 	lh	$t9,0x28($v1)
/*  f183364:	17280005 */ 	bne	$t9,$t0,.PF0f18337c
/*  f183368:	00000000 */ 	nop
/*  f18336c:	8f020000 */ 	lw	$v0,0x0($t8)
/*  f183370:	8449003e */ 	lh	$t1,0x3e($v0)
/*  f183374:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f183378:	a44a003e */ 	sh	$t2,0x3e($v0)
.PF0f18337c:
/*  f18337c:	3c03800b */ 	lui	$v1,0x800b
/*  f183380:	8c63cad0 */ 	lw	$v1,-0x3530($v1)
/*  f183384:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f183388:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f18338c:	0243082a */ 	slt	$at,$s2,$v1
/*  f183390:	1420ffe7 */ 	bnez	$at,.PF0f183330
/*  f183394:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f183398:	00009025 */ 	move	$s2,$zero
.PF0f18339c:
/*  f18339c:	1860001b */ 	blez	$v1,.PF0f18340c
/*  f1833a0:	8e91028c */ 	lw	$s1,0x28c($s4)
/*  f1833a4:	3c10800b */ 	lui	$s0,0x800b
/*  f1833a8:	2610ca70 */ 	addiu	$s0,$s0,-13712
/*  f1833ac:	8e020000 */ 	lw	$v0,0x0($s0)
.PF0f1833b0:
/*  f1833b0:	8c4b02d4 */ 	lw	$t3,0x2d4($v0)
/*  f1833b4:	1560000e */ 	bnez	$t3,.PF0f1833f0
/*  f1833b8:	00000000 */ 	nop
/*  f1833bc:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f1833c0:	90440125 */ 	lbu	$a0,0x125($v0)
/*  f1833c4:	866c0004 */ 	lh	$t4,0x4($s3)
/*  f1833c8:	144c0009 */ 	bne	$v0,$t4,.PF0f1833f0
/*  f1833cc:	00000000 */ 	nop
/*  f1833d0:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f1833d4:	02402025 */ 	move	$a0,$s2
/*  f1833d8:	0fc5bdaa */ 	jal	langGet
/*  f1833dc:	24045415 */ 	li	$a0,0x5415
/*  f1833e0:	00402025 */ 	move	$a0,$v0
/*  f1833e4:	24050009 */ 	li	$a1,0x9
/*  f1833e8:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f1833ec:	24060001 */ 	li	$a2,0x1
.PF0f1833f0:
/*  f1833f0:	3c0d800b */ 	lui	$t5,0x800b
/*  f1833f4:	8dadcad0 */ 	lw	$t5,-0x3530($t5)
/*  f1833f8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1833fc:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f183400:	024d082a */ 	slt	$at,$s2,$t5
/*  f183404:	5420ffea */ 	bnezl	$at,.PF0f1833b0
/*  f183408:	8e020000 */ 	lw	$v0,0x0($s0)
.PF0f18340c:
/*  f18340c:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f183410:	02202025 */ 	move	$a0,$s1
/*  f183414:	240effff */ 	li	$t6,-1
/*  f183418:	a66e0004 */ 	sh	$t6,0x4($s3)
/*  f18341c:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f183420:	3c0f800b */ 	lui	$t7,0x800b
/*  f183424:	8defd134 */ 	lw	$t7,-0x2ecc($t7)
/*  f183428:	24080001 */ 	li	$t0,0x1
/*  f18342c:	31f98000 */ 	andi	$t9,$t7,0x8000
/*  f183430:	53200003 */ 	beqzl	$t9,.PF0f183440
/*  f183434:	86630004 */ 	lh	$v1,0x4($s3)
/*  f183438:	a6680008 */ 	sh	$t0,0x8($s3)
.PF0f18343c:
/*  f18343c:	86630004 */ 	lh	$v1,0x4($s3)
.PF0f183440:
/*  f183440:	2401ffff */ 	li	$at,-1
/*  f183444:	3c028009 */ 	lui	$v0,0x8009
/*  f183448:	1461000c */ 	bne	$v1,$at,.PF0f18347c
/*  f18344c:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f183450:	3c013f80 */ 	lui	$at,0x3f80
/*  f183454:	44811000 */ 	mtc1	$at,$f2
/*  f183458:	3c013e80 */ 	lui	$at,0x3e80
/*  f18345c:	44817000 */ 	mtc1	$at,$f14
/*  f183460:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f183464:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f183468:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f18346c:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f183470:	e7ae0164 */ 	swc1	$f14,0x164($sp)
/*  f183474:	1000001e */ 	b	.PF0f1834f0
/*  f183478:	e7ae015c */ 	swc1	$f14,0x15c($sp)
.PF0f18347c:
/*  f18347c:	00581021 */ 	addu	$v0,$v0,$t8
/*  f183480:	8c428214 */ 	lw	$v0,-0x7dec($v0)
/*  f183484:	3c013b00 */ 	lui	$at,0x3b00
/*  f183488:	44811000 */ 	mtc1	$at,$f2
/*  f18348c:	00024e02 */ 	srl	$t1,$v0,0x18
/*  f183490:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f183494:	254b00ff */ 	addiu	$t3,$t2,0xff
/*  f183498:	448b4000 */ 	mtc1	$t3,$f8
/*  f18349c:	00026402 */ 	srl	$t4,$v0,0x10
/*  f1834a0:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f1834a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1834a8:	25ae00ff */ 	addiu	$t6,$t5,0xff
/*  f1834ac:	448e2000 */ 	mtc1	$t6,$f4
/*  f1834b0:	00027a02 */ 	srl	$t7,$v0,0x8
/*  f1834b4:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f1834b8:	272800ff */ 	addiu	$t0,$t9,0xff
/*  f1834bc:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f1834c0:	44885000 */ 	mtc1	$t0,$f10
/*  f1834c4:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f1834c8:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f1834cc:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f1834d0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1834d4:	e7b20164 */ 	swc1	$f18,0x164($sp)
/*  f1834d8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f1834dc:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f1834e0:	00000000 */ 	nop
/*  f1834e4:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f1834e8:	e7a80160 */ 	swc1	$f8,0x160($sp)
/*  f1834ec:	e7a4015c */ 	swc1	$f4,0x15c($sp)
.PF0f1834f0:
/*  f1834f0:	c7a60164 */ 	lwc1	$f6,0x164($sp)
/*  f1834f4:	46003032 */ 	c.eq.s	$f6,$f0
/*  f1834f8:	00000000 */ 	nop
/*  f1834fc:	4503001c */ 	bc1tl	.PF0f183570
/*  f183500:	c7a80160 */ 	lwc1	$f8,0x160($sp)
/*  f183504:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f183508:	00001025 */ 	move	$v0,$zero
/*  f18350c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f183510:	58600017 */ 	blezl	$v1,.PF0f183570
/*  f183514:	c7a80160 */ 	lwc1	$f8,0x160($sp)
/*  f183518:	c4289f90 */ 	lwc1	$f8,-0x6070($at)
/*  f18351c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f183520:	c4209f94 */ 	lwc1	$f0,-0x606c($at)
/*  f183524:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f183528:	00000000 */ 	nop
/*  f18352c:	c66e0030 */ 	lwc1	$f14,0x30($s3)
/*  f183530:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f183534:	0043082a */ 	slt	$at,$v0,$v1
/*  f183538:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f18353c:	5020000a */ 	beqzl	$at,.PF0f183568
/*  f183540:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f183544:	46121380 */ 	add.s	$f14,$f2,$f18
.PF0f183548:
/*  f183548:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18354c:	0043082a */ 	slt	$at,$v0,$v1
/*  f183550:	e66e0030 */ 	swc1	$f14,0x30($s3)
/*  f183554:	c66e0030 */ 	lwc1	$f14,0x30($s3)
/*  f183558:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f18355c:	5420fffa */ 	bnezl	$at,.PF0f183548
/*  f183560:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f183564:	46121380 */ 	add.s	$f14,$f2,$f18
.PF0f183568:
/*  f183568:	e66e0030 */ 	swc1	$f14,0x30($s3)
/*  f18356c:	c7a80160 */ 	lwc1	$f8,0x160($sp)
.PF0f183570:
/*  f183570:	3c017f1c */ 	lui	$at,0x7f1c
/*  f183574:	c4209f98 */ 	lwc1	$f0,-0x6068($at)
/*  f183578:	460c4032 */ 	c.eq.s	$f8,$f12
/*  f18357c:	00000000 */ 	nop
/*  f183580:	4503001a */ 	bc1tl	.PF0f1835ec
/*  f183584:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f183588:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f18358c:	00001025 */ 	move	$v0,$zero
/*  f183590:	3c017f1c */ 	lui	$at,0x7f1c
/*  f183594:	58600015 */ 	blezl	$v1,.PF0f1835ec
/*  f183598:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f18359c:	c4269f9c */ 	lwc1	$f6,-0x6064($at)
/*  f1835a0:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f1835a4:	00000000 */ 	nop
/*  f1835a8:	c66e0034 */ 	lwc1	$f14,0x34($s3)
/*  f1835ac:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1835b0:	0043082a */ 	slt	$at,$v0,$v1
/*  f1835b4:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f1835b8:	5020000a */ 	beqzl	$at,.PF0f1835e4
/*  f1835bc:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f1835c0:	46121380 */ 	add.s	$f14,$f2,$f18
.PF0f1835c4:
/*  f1835c4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1835c8:	0043082a */ 	slt	$at,$v0,$v1
/*  f1835cc:	e66e0034 */ 	swc1	$f14,0x34($s3)
/*  f1835d0:	c66e0034 */ 	lwc1	$f14,0x34($s3)
/*  f1835d4:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f1835d8:	5420fffa */ 	bnezl	$at,.PF0f1835c4
/*  f1835dc:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f1835e0:	46121380 */ 	add.s	$f14,$f2,$f18
.PF0f1835e4:
/*  f1835e4:	e66e0034 */ 	swc1	$f14,0x34($s3)
/*  f1835e8:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
.PF0f1835ec:
/*  f1835ec:	46103032 */ 	c.eq.s	$f6,$f16
/*  f1835f0:	00000000 */ 	nop
/*  f1835f4:	4503001a */ 	bc1tl	.PF0f183660
/*  f1835f8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1835fc:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f183600:	00001025 */ 	move	$v0,$zero
/*  f183604:	3c017f1c */ 	lui	$at,0x7f1c
/*  f183608:	58600015 */ 	blezl	$v1,.PF0f183660
/*  f18360c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f183610:	c4289fa0 */ 	lwc1	$f8,-0x6060($at)
/*  f183614:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f183618:	00000000 */ 	nop
/*  f18361c:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f183620:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f183624:	0043082a */ 	slt	$at,$v0,$v1
/*  f183628:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f18362c:	5020000a */ 	beqzl	$at,.PF0f183658
/*  f183630:	46121400 */ 	add.s	$f16,$f2,$f18
/*  f183634:	46121400 */ 	add.s	$f16,$f2,$f18
.PF0f183638:
/*  f183638:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18363c:	0043082a */ 	slt	$at,$v0,$v1
/*  f183640:	e6700038 */ 	swc1	$f16,0x38($s3)
/*  f183644:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f183648:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f18364c:	5420fffa */ 	bnezl	$at,.PF0f183638
/*  f183650:	46121400 */ 	add.s	$f16,$f2,$f18
/*  f183654:	46121400 */ 	add.s	$f16,$f2,$f18
.PF0f183658:
/*  f183658:	e6700038 */ 	swc1	$f16,0x38($s3)
.PF0f18365c:
/*  f18365c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PF0f183660:
/*  f183660:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f183664:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f183668:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f18366c:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f183670:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f183674:	03e00008 */ 	jr	$ra
/*  f183678:	27bd0188 */ 	addiu	$sp,$sp,0x188
);
#else
GLOBAL_ASM(
glabel scenarioKohTick
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
/*  f1820fc:	0c004241 */ 	jal	sndStart
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
/*  f1821ec:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f1821f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1821f4:	10000004 */ 	b	.L0f182208
/*  f1821f8:	8e98006c */ 	lw	$t8,0x6c($s4)
.L0f1821fc:
/*  f1821fc:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f1822fc:	0c004241 */ 	jal	sndStart
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
/*  f1823dc:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel scenarioKohCallback18
/*  f18367c:	3c0e800a */ 	lui	$t6,0x800a
/*  f183680:	8dcea794 */ 	lw	$t6,-0x586c($t6)
/*  f183684:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f183688:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f18368c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f183690:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f183694:	00808025 */ 	move	$s0,$a0
/*  f183698:	8de20004 */ 	lw	$v0,0x4($t7)
/*  f18369c:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f1836a0:	90440125 */ 	lbu	$a0,0x125($v0)
/*  f1836a4:	3c03800b */ 	lui	$v1,0x800b
/*  f1836a8:	2463c6b0 */ 	addiu	$v1,$v1,-14672
/*  f1836ac:	84780004 */ 	lh	$t8,0x4($v1)
/*  f1836b0:	54580092 */ 	bnel	$v0,$t8,.PF0f1838fc
/*  f1836b4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1836b8:	84790008 */ 	lh	$t9,0x8($v1)
/*  f1836bc:	5720008f */ 	bnezl	$t9,.PF0f1838fc
/*  f1836c0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1836c4:	0c002e91 */ 	jal	viGetViewLeft
/*  f1836c8:	00000000 */ 	nop
/*  f1836cc:	0c002e73 */ 	jal	viGetViewWidth
/*  f1836d0:	a7a2004e */ 	sh	$v0,0x4e($sp)
/*  f1836d4:	87aa004e */ 	lh	$t2,0x4e($sp)
/*  f1836d8:	04410003 */ 	bgez	$v0,.PF0f1836e8
/*  f1836dc:	00024843 */ 	sra	$t1,$v0,0x1
/*  f1836e0:	24410001 */ 	addiu	$at,$v0,0x1
/*  f1836e4:	00014843 */ 	sra	$t1,$at,0x1
.PF0f1836e8:
/*  f1836e8:	012a2821 */ 	addu	$a1,$t1,$t2
/*  f1836ec:	0c002e95 */ 	jal	viGetViewTop
/*  f1836f0:	afa50098 */ 	sw	$a1,0x98($sp)
/*  f1836f4:	3c04800a */ 	lui	$a0,0x800a
/*  f1836f8:	8c84a994 */ 	lw	$a0,-0x566c($a0)
/*  f1836fc:	240800c8 */ 	li	$t0,0xc8
/*  f183700:	3c0d800b */ 	lui	$t5,0x800b
/*  f183704:	00880019 */ 	multu	$a0,$t0
/*  f183708:	85adc6b6 */ 	lh	$t5,-0x394a($t5)
/*  f18370c:	24072ee0 */ 	li	$a3,0x2ee0
/*  f183710:	00047900 */ 	sll	$t7,$a0,0x4
/*  f183714:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f183718:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18371c:	25f80258 */ 	addiu	$t8,$t7,0x258
/*  f183720:	244b000a */ 	addiu	$t3,$v0,0xa
/*  f183724:	afab0094 */ 	sw	$t3,0x94($sp)
/*  f183728:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f18372c:	00006012 */ 	mflo	$t4
/*  f183730:	018d1823 */ 	subu	$v1,$t4,$t5
/*  f183734:	24630897 */ 	addiu	$v1,$v1,0x897
/*  f183738:	0067001a */ 	div	$zero,$v1,$a3
/*  f18373c:	00002812 */ 	mflo	$a1
/*  f183740:	00a03025 */ 	move	$a2,$a1
/*  f183744:	14e00002 */ 	bnez	$a3,.PF0f183750
/*  f183748:	00000000 */ 	nop
/*  f18374c:	0007000d */ 	break	0x7
.PF0f183750:
/*  f183750:	2401ffff */ 	li	$at,-1
/*  f183754:	14e10004 */ 	bne	$a3,$at,.PF0f183768
/*  f183758:	3c018000 */ 	lui	$at,0x8000
/*  f18375c:	14610002 */ 	bne	$v1,$at,.PF0f183768
/*  f183760:	00000000 */ 	nop
/*  f183764:	0006000d */ 	break	0x6
.PF0f183768:
/*  f183768:	00a70019 */ 	multu	$a1,$a3
/*  f18376c:	24010e10 */ 	li	$at,0xe10
/*  f183770:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f183774:	00007012 */ 	mflo	$t6
/*  f183778:	006e1823 */ 	subu	$v1,$v1,$t6
/*  f18377c:	00000000 */ 	nop
/*  f183780:	0301001a */ 	div	$zero,$t8,$at
/*  f183784:	0000c812 */ 	mflo	$t9
/*  f183788:	13200013 */ 	beqz	$t9,.PF0f1837d8
/*  f18378c:	00000000 */ 	nop
/*  f183790:	0068001a */ 	div	$zero,$v1,$t0
/*  f183794:	00003812 */ 	mflo	$a3
/*  f183798:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f18379c:	24a59ae8 */ 	addiu	$a1,$a1,-25880
/*  f1837a0:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f1837a4:	15000002 */ 	bnez	$t0,.PF0f1837b0
/*  f1837a8:	00000000 */ 	nop
/*  f1837ac:	0007000d */ 	break	0x7
.PF0f1837b0:
/*  f1837b0:	2401ffff */ 	li	$at,-1
/*  f1837b4:	15010004 */ 	bne	$t0,$at,.PF0f1837c8
/*  f1837b8:	3c018000 */ 	lui	$at,0x8000
/*  f1837bc:	14610002 */ 	bne	$v1,$at,.PF0f1837c8
/*  f1837c0:	00000000 */ 	nop
/*  f1837c4:	0006000d */ 	break	0x6
.PF0f1837c8:
/*  f1837c8:	0c004d11 */ 	jal	sprintf
/*  f1837cc:	00000000 */ 	nop
/*  f1837d0:	1000000f */ 	b	.PF0f183810
/*  f1837d4:	00000000 */ 	nop
.PF0f1837d8:
/*  f1837d8:	0068001a */ 	div	$zero,$v1,$t0
/*  f1837dc:	00003012 */ 	mflo	$a2
/*  f1837e0:	24a59af0 */ 	addiu	$a1,$a1,-25872
/*  f1837e4:	15000002 */ 	bnez	$t0,.PF0f1837f0
/*  f1837e8:	00000000 */ 	nop
/*  f1837ec:	0007000d */ 	break	0x7
.PF0f1837f0:
/*  f1837f0:	2401ffff */ 	li	$at,-1
/*  f1837f4:	15010004 */ 	bne	$t0,$at,.PF0f183808
/*  f1837f8:	3c018000 */ 	lui	$at,0x8000
/*  f1837fc:	14610002 */ 	bne	$v1,$at,.PF0f183808
/*  f183800:	00000000 */ 	nop
/*  f183804:	0006000d */ 	break	0x6
.PF0f183808:
/*  f183808:	0c004d11 */ 	jal	sprintf
/*  f18380c:	00000000 */ 	nop
.PF0f183810:
/*  f183810:	0fc550cf */ 	jal	func0f153628
/*  f183814:	02002025 */ 	move	$a0,$s0
/*  f183818:	3c098008 */ 	lui	$t1,0x8008
/*  f18381c:	8d290064 */ 	lw	$t1,0x64($t1)
/*  f183820:	3c078008 */ 	lui	$a3,0x8008
/*  f183824:	00408025 */ 	move	$s0,$v0
/*  f183828:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f18382c:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f183830:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f183834:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f183838:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18383c:	0fc5609a */ 	jal	textMeasure
/*  f183840:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f183844:	8fa700a0 */ 	lw	$a3,0xa0($sp)
/*  f183848:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f18384c:	8fa2009c */ 	lw	$v0,0x9c($sp)
/*  f183850:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f183854:	04e10003 */ 	bgez	$a3,.PF0f183864
/*  f183858:	00075043 */ 	sra	$t2,$a3,0x1
/*  f18385c:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f183860:	00015043 */ 	sra	$t2,$at,0x1
.PF0f183864:
/*  f183864:	00aa2823 */ 	subu	$a1,$a1,$t2
/*  f183868:	00e53821 */ 	addu	$a3,$a3,$a1
/*  f18386c:	00461021 */ 	addu	$v0,$v0,$a2
/*  f183870:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f183874:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f183878:	afa700a0 */ 	sw	$a3,0xa0($sp)
/*  f18387c:	afa50098 */ 	sw	$a1,0x98($sp)
/*  f183880:	0fc551a9 */ 	jal	func0f153990
/*  f183884:	02002025 */ 	move	$a0,$s0
/*  f183888:	0c002e53 */ 	jal	viGetWidth
/*  f18388c:	00408025 */ 	move	$s0,$v0
/*  f183890:	0c002e57 */ 	jal	viGetHeight
/*  f183894:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f183898:	3c0b8008 */ 	lui	$t3,0x8008
/*  f18389c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1838a0:	8d8c005c */ 	lw	$t4,0x5c($t4)
/*  f1838a4:	8d6b0060 */ 	lw	$t3,0x60($t3)
/*  f1838a8:	87af004c */ 	lh	$t7,0x4c($sp)
/*  f1838ac:	3c0d00ff */ 	lui	$t5,0xff
/*  f1838b0:	35ad00a0 */ 	ori	$t5,$t5,0xa0
/*  f1838b4:	240e00a0 */ 	li	$t6,0xa0
/*  f1838b8:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1838bc:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f1838c0:	02002025 */ 	move	$a0,$s0
/*  f1838c4:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f1838c8:	27a60094 */ 	addiu	$a2,$sp,0x94
/*  f1838cc:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f1838d0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1838d4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1838d8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1838dc:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f1838e0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f1838e4:	0fc55fa0 */ 	jal	textRender
/*  f1838e8:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f1838ec:	0fc55125 */ 	jal	func0f153780
/*  f1838f0:	00402025 */ 	move	$a0,$v0
/*  f1838f4:	00408025 */ 	move	$s0,$v0
/*  f1838f8:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PF0f1838fc:
/*  f1838fc:	02001025 */ 	move	$v0,$s0
/*  f183900:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f183904:	03e00008 */ 	jr	$ra
/*  f183908:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);
#elif VERSION >= VERSION_NTSC_1_0
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
/*  f182884:	0c002f02 */ 	jal	viGetWidth
/*  f182888:	00408025 */ 	or	$s0,$v0,$zero
/*  f18288c:	0c002f06 */ 	jal	viGetHeight
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
#else
GLOBAL_ASM(
glabel scenarioKohCallback18
/*  f17ccd8:	3c0e800a */ 	lui	$t6,0x800a
/*  f17ccdc:	8dcee944 */ 	lw	$t6,-0x16bc($t6)
/*  f17cce0:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f17cce4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f17cce8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f17ccec:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f17ccf0:	00808025 */ 	or	$s0,$a0,$zero
/*  f17ccf4:	8de20004 */ 	lw	$v0,0x4($t7)
/*  f17ccf8:	0fc622ca */ 	jal	radarGetTeamIndex
/*  f17ccfc:	90440125 */ 	lbu	$a0,0x125($v0)
/*  f17cd00:	3c03800b */ 	lui	$v1,0x800b
/*  f17cd04:	246309c0 */ 	addiu	$v1,$v1,0x9c0
/*  f17cd08:	84780004 */ 	lh	$t8,0x4($v1)
/*  f17cd0c:	54580098 */ 	bnel	$v0,$t8,.NB0f17cf70
/*  f17cd10:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f17cd14:	84790008 */ 	lh	$t9,0x8($v1)
/*  f17cd18:	57200095 */ 	bnezl	$t9,.NB0f17cf70
/*  f17cd1c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f17cd20:	0c002fb5 */ 	jal	viGetViewLeft
/*  f17cd24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17cd28:	0c002f97 */ 	jal	viGetViewWidth
/*  f17cd2c:	a7a2004e */ 	sh	$v0,0x4e($sp)
/*  f17cd30:	87aa004e */ 	lh	$t2,0x4e($sp)
/*  f17cd34:	04410003 */ 	bgez	$v0,.NB0f17cd44
/*  f17cd38:	00024843 */ 	sra	$t1,$v0,0x1
/*  f17cd3c:	24410001 */ 	addiu	$at,$v0,0x1
/*  f17cd40:	00014843 */ 	sra	$t1,$at,0x1
.NB0f17cd44:
/*  f17cd44:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f17cd48:	0c002fb9 */ 	jal	viGetViewTop
/*  f17cd4c:	afa30098 */ 	sw	$v1,0x98($sp)
/*  f17cd50:	3c04800a */ 	lui	$a0,0x800a
/*  f17cd54:	8c84eb44 */ 	lw	$a0,-0x14bc($a0)
/*  f17cd58:	240800f0 */ 	addiu	$t0,$zero,0xf0
/*  f17cd5c:	3c0d800b */ 	lui	$t5,0x800b
/*  f17cd60:	00880019 */ 	multu	$a0,$t0
/*  f17cd64:	85ad09c6 */ 	lh	$t5,0x9c6($t5)
/*  f17cd68:	24073840 */ 	addiu	$a3,$zero,0x3840
/*  f17cd6c:	00047900 */ 	sll	$t7,$a0,0x4
/*  f17cd70:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f17cd74:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17cd78:	25f80258 */ 	addiu	$t8,$t7,0x258
/*  f17cd7c:	244b000a */ 	addiu	$t3,$v0,0xa
/*  f17cd80:	afab0094 */ 	sw	$t3,0x94($sp)
/*  f17cd84:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f17cd88:	00006012 */ 	mflo	$t4
/*  f17cd8c:	018d1823 */ 	subu	$v1,$t4,$t5
/*  f17cd90:	24630960 */ 	addiu	$v1,$v1,0x960
/*  f17cd94:	0067001a */ 	div	$zero,$v1,$a3
/*  f17cd98:	00002812 */ 	mflo	$a1
/*  f17cd9c:	00a03025 */ 	or	$a2,$a1,$zero
/*  f17cda0:	14e00002 */ 	bnez	$a3,.NB0f17cdac
/*  f17cda4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17cda8:	0007000d */ 	break	0x7
.NB0f17cdac:
/*  f17cdac:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17cdb0:	14e10004 */ 	bne	$a3,$at,.NB0f17cdc4
/*  f17cdb4:	3c018000 */ 	lui	$at,0x8000
/*  f17cdb8:	14610002 */ 	bne	$v1,$at,.NB0f17cdc4
/*  f17cdbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17cdc0:	0006000d */ 	break	0x6
.NB0f17cdc4:
/*  f17cdc4:	00a70019 */ 	multu	$a1,$a3
/*  f17cdc8:	24010e10 */ 	addiu	$at,$zero,0xe10
/*  f17cdcc:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f17cdd0:	00007012 */ 	mflo	$t6
/*  f17cdd4:	006e1823 */ 	subu	$v1,$v1,$t6
/*  f17cdd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17cddc:	0301001a */ 	div	$zero,$t8,$at
/*  f17cde0:	0000c812 */ 	mflo	$t9
/*  f17cde4:	53200015 */ 	beqzl	$t9,.NB0f17ce3c
/*  f17cde8:	246a00ef */ 	addiu	$t2,$v1,0xef
/*  f17cdec:	246900ef */ 	addiu	$t1,$v1,0xef
/*  f17cdf0:	0128001a */ 	div	$zero,$t1,$t0
/*  f17cdf4:	00003812 */ 	mflo	$a3
/*  f17cdf8:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f17cdfc:	24a52d88 */ 	addiu	$a1,$a1,0x2d88
/*  f17ce00:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f17ce04:	15000002 */ 	bnez	$t0,.NB0f17ce10
/*  f17ce08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ce0c:	0007000d */ 	break	0x7
.NB0f17ce10:
/*  f17ce10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17ce14:	15010004 */ 	bne	$t0,$at,.NB0f17ce28
/*  f17ce18:	3c018000 */ 	lui	$at,0x8000
/*  f17ce1c:	15210002 */ 	bne	$t1,$at,.NB0f17ce28
/*  f17ce20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ce24:	0006000d */ 	break	0x6
.NB0f17ce28:
/*  f17ce28:	0c004fc1 */ 	jal	sprintf
/*  f17ce2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ce30:	10000010 */ 	beqz	$zero,.NB0f17ce74
/*  f17ce34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ce38:	246a00ef */ 	addiu	$t2,$v1,0xef
.NB0f17ce3c:
/*  f17ce3c:	0148001a */ 	div	$zero,$t2,$t0
/*  f17ce40:	00003012 */ 	mflo	$a2
/*  f17ce44:	24a52d90 */ 	addiu	$a1,$a1,0x2d90
/*  f17ce48:	15000002 */ 	bnez	$t0,.NB0f17ce54
/*  f17ce4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ce50:	0007000d */ 	break	0x7
.NB0f17ce54:
/*  f17ce54:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17ce58:	15010004 */ 	bne	$t0,$at,.NB0f17ce6c
/*  f17ce5c:	3c018000 */ 	lui	$at,0x8000
/*  f17ce60:	15410002 */ 	bne	$t2,$at,.NB0f17ce6c
/*  f17ce64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ce68:	0006000d */ 	break	0x6
.NB0f17ce6c:
/*  f17ce6c:	0c004fc1 */ 	jal	sprintf
/*  f17ce70:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f17ce74:
/*  f17ce74:	0fc5374a */ 	jal	func0f153628
/*  f17ce78:	02002025 */ 	or	$a0,$s0,$zero
/*  f17ce7c:	3c0b8008 */ 	lui	$t3,0x8008
/*  f17ce80:	8d6b2364 */ 	lw	$t3,0x2364($t3)
/*  f17ce84:	3c078008 */ 	lui	$a3,0x8008
/*  f17ce88:	00408025 */ 	or	$s0,$v0,$zero
/*  f17ce8c:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f17ce90:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f17ce94:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f17ce98:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f17ce9c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f17cea0:	0fc54655 */ 	jal	textMeasure
/*  f17cea4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f17cea8:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f17ceac:	8fa30098 */ 	lw	$v1,0x98($sp)
/*  f17ceb0:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f17ceb4:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f17ceb8:	04410003 */ 	bgez	$v0,.NB0f17cec8
/*  f17cebc:	00026043 */ 	sra	$t4,$v0,0x1
/*  f17cec0:	24410001 */ 	addiu	$at,$v0,0x1
/*  f17cec4:	00016043 */ 	sra	$t4,$at,0x1
.NB0f17cec8:
/*  f17cec8:	006c1823 */ 	subu	$v1,$v1,$t4
/*  f17cecc:	27b8009c */ 	addiu	$t8,$sp,0x9c
/*  f17ced0:	00431021 */ 	addu	$v0,$v0,$v1
/*  f17ced4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f17ced8:	afaf009c */ 	sw	$t7,0x9c($sp)
/*  f17cedc:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f17cee0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f17cee4:	afa30098 */ 	sw	$v1,0x98($sp)
/*  f17cee8:	02002025 */ 	or	$a0,$s0,$zero
/*  f17ceec:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f17cef0:	27a60094 */ 	addiu	$a2,$sp,0x94
/*  f17cef4:	0fc537d6 */ 	jal	func0f153858
/*  f17cef8:	27a700a0 */ 	addiu	$a3,$sp,0xa0
/*  f17cefc:	0c002f77 */ 	jal	viGetWidth
/*  f17cf00:	00408025 */ 	or	$s0,$v0,$zero
/*  f17cf04:	0c002f7b */ 	jal	viGetHeight
/*  f17cf08:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f17cf0c:	3c198008 */ 	lui	$t9,0x8008
/*  f17cf10:	3c098008 */ 	lui	$t1,0x8008
/*  f17cf14:	8d29235c */ 	lw	$t1,0x235c($t1)
/*  f17cf18:	8f392360 */ 	lw	$t9,0x2360($t9)
/*  f17cf1c:	87ac004c */ 	lh	$t4,0x4c($sp)
/*  f17cf20:	3c0a00ff */ 	lui	$t2,0xff
/*  f17cf24:	354a00a0 */ 	ori	$t2,$t2,0xa0
/*  f17cf28:	240b0088 */ 	addiu	$t3,$zero,0x88
/*  f17cf2c:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f17cf30:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f17cf34:	02002025 */ 	or	$a0,$s0,$zero
/*  f17cf38:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f17cf3c:	27a60094 */ 	addiu	$a2,$sp,0x94
/*  f17cf40:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f17cf44:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f17cf48:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f17cf4c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f17cf50:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f17cf54:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f17cf58:	0fc54529 */ 	jal	textRender
/*  f17cf5c:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f17cf60:	0fc537a0 */ 	jal	func0f153780
/*  f17cf64:	00402025 */ 	or	$a0,$v0,$zero
/*  f17cf68:	00408025 */ 	or	$s0,$v0,$zero
/*  f17cf6c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f17cf70:
/*  f17cf70:	02001025 */ 	or	$v0,$s0,$zero
/*  f17cf74:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f17cf78:	03e00008 */ 	jr	$ra
/*  f17cf7c:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);
#endif

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

void mpKohAddHill(s32 *cmd)
{
	if (g_ScenarioData.koh.hillcount < ARRAYCOUNT(g_ScenarioData.koh.hillpads)) {
		g_ScenarioData.koh.hillpads[g_ScenarioData.koh.hillcount] = cmd[1];
		g_ScenarioData.koh.hillcount++;
	}
}

bool scenarioKohIsRoomHighlighted(s16 room)
{
	return room == g_ScenarioData.koh.hillrooms[0];
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

void mpHtmAddPad(s16 padnum)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;

#if VERSION >= VERSION_NTSC_1_0
	if (data->nextindex < 60)
#endif
	{
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

struct menuitem g_MpHillOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222,  MPOPTION_ONEHITKILLS,     menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223,  0x00000000,               menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224,  MPOPTION_FASTMOVEMENT,    menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225,  MPOPTION_DISPLAYTEAM,     menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226,  MPOPTION_NORADAR,         menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227,  MPOPTION_NOAUTOAIM,       menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS_493, MPOPTION_KILLSSCORE,      menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_233,  MPOPTION_KOH_HILLONRADAR, menuhandlerMpCheckboxOption }, // "Hill on Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_234,  MPOPTION_KOH_MOBILEHILL,  menuhandlerMpCheckboxOption }, // "Mobile Hill"
	{ MENUITEMTYPE_SLIDER,     0, 0x00020000, L_MPMENU_235,  0x0000006e,               menuhandlerMpHillTime       }, // "Time"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239,  0x00000000,               NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
};

struct menudialog g_MpHillOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_219, // "Hill Options"
	g_MpHillOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

struct menuitem g_MpHackerOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222,  MPOPTION_ONEHITKILLS,           menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223,  0x00000000,                     menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224,  MPOPTION_FASTMOVEMENT,          menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225,  MPOPTION_DISPLAYTEAM,           menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226,  MPOPTION_NORADAR,               menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227,  MPOPTION_NOAUTOAIM,             menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS_493, MPOPTION_KILLSSCORE,            menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                     NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_231,  MPOPTION_HTM_HIGHLIGHTTERMINAL, menuhandlerMpCheckboxOption }, // "Highlight Terminal"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_238,  MPOPTION_HTM_SHOWONRADAR,       menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                     NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239,  0x00000000,                     NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,                     NULL                        },
};

struct menudialog g_MpHackerOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_217, // "Hacker Options"
	g_MpHackerOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

u32 var80086e14 = 0x02000008;
u32 var80086e18 = 0x00130000;
u32 var80086e1c = 0x00420001;
u32 var80086e20 = 0x00204000;
u32 var80086e24 = 0x00000000;
u32 var80086e28 = 0x00000000;
u32 var80086e2c = 0x00000000;
u32 var80086e30 = 0x3f800000;
u32 var80086e34 = 0x00000000;
u32 var80086e38 = 0x00000000;
u32 var80086e3c = 0x00000000;
u32 var80086e40 = 0x3f800000;
u32 var80086e44 = 0x00000000;
u32 var80086e48 = 0x00000000;
u32 var80086e4c = 0x00000000;
u32 var80086e50 = 0x3f800000;
u32 var80086e54 = 0x00000000;
u32 var80086e58 = 0x00000000;
u32 var80086e5c = 0x00000000;
u32 var80086e60 = 0x000003e8;
u32 var80086e64 = 0xffffff00;
u32 var80086e68 = 0xffffff00;
u32 var80086e6c = 0x0fff0000;
u32 var80086e70 = 0x36000000;
u32 var80086e74 = 0x00ffffff;
u32 var80086e78 = 0x00000000;

#if VERSION >= VERSION_NTSC_1_0
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
#else
GLOBAL_ASM(
glabel func0f182c98
/*  f17d2ec:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f17d2f0:	3c0f8009 */ 	lui	$t7,0x8009
/*  f17d2f4:	25ef9594 */ 	addiu	$t7,$t7,-27244
/*  f17d2f8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17d2fc:	25e80060 */ 	addiu	$t0,$t7,0x60
/*  f17d300:	27ae0080 */ 	addiu	$t6,$sp,0x80
.NB0f17d304:
/*  f17d304:	8de10000 */ 	lw	$at,0x0($t7)
/*  f17d308:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f17d30c:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f17d310:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f17d314:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f17d318:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f17d31c:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f17d320:	15e8fff8 */ 	bne	$t7,$t0,.NB0f17d304
/*  f17d324:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f17d328:	8de10000 */ 	lw	$at,0x0($t7)
/*  f17d32c:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f17d330:	3c03800a */ 	lui	$v1,0x800a
/*  f17d334:	adc10000 */ 	sw	$at,0x0($t6)
/*  f17d338:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f17d33c:	8c63e9fc */ 	lw	$v1,-0x1604($v1)
/*  f17d340:	00002025 */ 	or	$a0,$zero,$zero
/*  f17d344:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f17d348:	1060000f */ 	beqz	$v1,.NB0f17d388
/*  f17d34c:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f17d350:	8c620004 */ 	lw	$v0,0x4($v1)
.NB0f17d354:
/*  f17d354:	00045080 */ 	sll	$t2,$a0,0x2
/*  f17d358:	00ca5821 */ 	addu	$t3,$a2,$t2
/*  f17d35c:	90490003 */ 	lbu	$t1,0x3($v0)
/*  f17d360:	54a90004 */ 	bnel	$a1,$t1,.NB0f17d374
/*  f17d364:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f17d368:	ad620000 */ 	sw	$v0,0x0($t3)
/*  f17d36c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f17d370:	8c630020 */ 	lw	$v1,0x20($v1)
.NB0f17d374:
/*  f17d374:	28810014 */ 	slti	$at,$a0,0x14
/*  f17d378:	10600003 */ 	beqz	$v1,.NB0f17d388
/*  f17d37c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d380:	5420fff4 */ 	bnezl	$at,.NB0f17d354
/*  f17d384:	8c620004 */ 	lw	$v0,0x4($v1)
.NB0f17d388:
/*  f17d388:	1880001a */ 	blez	$a0,.NB0f17d3f4
/*  f17d38c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d390:	0c004d84 */ 	jal	random
/*  f17d394:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f17d398:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f17d39c:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f17d3a0:	3c058009 */ 	lui	$a1,0x8009
/*  f17d3a4:	0044001b */ 	divu	$zero,$v0,$a0
/*  f17d3a8:	24a5916c */ 	addiu	$a1,$a1,-28308
/*  f17d3ac:	14800002 */ 	bnez	$a0,.NB0f17d3b8
/*  f17d3b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d3b4:	0007000d */ 	break	0x7
.NB0f17d3b8:
/*  f17d3b8:	00002010 */ 	mfhi	$a0
/*  f17d3bc:	00046080 */ 	sll	$t4,$a0,0x2
/*  f17d3c0:	00cc6821 */ 	addu	$t5,$a2,$t4
/*  f17d3c4:	8db90000 */ 	lw	$t9,0x0($t5)
/*  f17d3c8:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f17d3cc:	8f380040 */ 	lw	$t8,0x40($t9)
/*  f17d3d0:	37080004 */ 	ori	$t0,$t8,0x4
/*  f17d3d4:	af280040 */ 	sw	$t0,0x40($t9)
/*  f17d3d8:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f17d3dc:	906f0002 */ 	lbu	$t7,0x2($v1)
/*  f17d3e0:	35ee0004 */ 	ori	$t6,$t7,0x4
/*  f17d3e4:	a06e0002 */ 	sb	$t6,0x2($v1)
/*  f17d3e8:	8ca90000 */ 	lw	$t1,0x0($a1)
/*  f17d3ec:	10000015 */ 	beqz	$zero,.NB0f17d444
/*  f17d3f0:	85270006 */ 	lh	$a3,0x6($t1)
.NB0f17d3f4:
/*  f17d3f4:	3c0a800b */ 	lui	$t2,0x800b
/*  f17d3f8:	854a09c0 */ 	lh	$t2,0x9c0($t2)
/*  f17d3fc:	59400011 */ 	blezl	$t2,.NB0f17d444
/*  f17d400:	00003825 */ 	or	$a3,$zero,$zero
/*  f17d404:	0c004d84 */ 	jal	random
/*  f17d408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d40c:	3c03800b */ 	lui	$v1,0x800b
/*  f17d410:	246309c0 */ 	addiu	$v1,$v1,0x9c0
/*  f17d414:	846b0000 */ 	lh	$t3,0x0($v1)
/*  f17d418:	004b001b */ 	divu	$zero,$v0,$t3
/*  f17d41c:	00006010 */ 	mfhi	$t4
/*  f17d420:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f17d424:	006dc821 */ 	addu	$t9,$v1,$t5
/*  f17d428:	15600002 */ 	bnez	$t3,.NB0f17d434
/*  f17d42c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d430:	0007000d */ 	break	0x7
.NB0f17d434:
/*  f17d434:	87270004 */ 	lh	$a3,0x4($t9)
/*  f17d438:	10000002 */ 	beqz	$zero,.NB0f17d444
/*  f17d43c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d440:	00003825 */ 	or	$a3,$zero,$zero
.NB0f17d444:
/*  f17d444:	3c04800b */ 	lui	$a0,0x800b
/*  f17d448:	24840d10 */ 	addiu	$a0,$a0,0xd10
/*  f17d44c:	27b80080 */ 	addiu	$t8,$sp,0x80
/*  f17d450:	270f0060 */ 	addiu	$t7,$t8,0x60
/*  f17d454:	00807025 */ 	or	$t6,$a0,$zero
.NB0f17d458:
/*  f17d458:	8f010000 */ 	lw	$at,0x0($t8)
/*  f17d45c:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f17d460:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f17d464:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f17d468:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*  f17d46c:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f17d470:	8f01fffc */ 	lw	$at,-0x4($t8)
/*  f17d474:	170ffff8 */ 	bne	$t8,$t7,.NB0f17d458
/*  f17d478:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f17d47c:	8f010000 */ 	lw	$at,0x0($t8)
/*  f17d480:	240503e7 */ 	addiu	$a1,$zero,0x3e7
/*  f17d484:	adc10000 */ 	sw	$at,0x0($t6)
/*  f17d488:	8f0f0004 */ 	lw	$t7,0x4($t8)
/*  f17d48c:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f17d490:	0fc034c8 */ 	jal	weaponAssignToHome
/*  f17d494:	a4870006 */ 	sh	$a3,0x6($a0)
/*  f17d498:	3c04800b */ 	lui	$a0,0x800b
/*  f17d49c:	24840d10 */ 	addiu	$a0,$a0,0xd10
/*  f17d4a0:	90890002 */ 	lbu	$t1,0x2($a0)
/*  f17d4a4:	8c8b0014 */ 	lw	$t3,0x14($a0)
/*  f17d4a8:	3c03800b */ 	lui	$v1,0x800b
/*  f17d4ac:	246309c0 */ 	addiu	$v1,$v1,0x9c0
/*  f17d4b0:	312afffb */ 	andi	$t2,$t1,0xfffb
/*  f17d4b4:	a08a0002 */ 	sb	$t2,0x2($a0)
/*  f17d4b8:	11600004 */ 	beqz	$t3,.NB0f17d4cc
/*  f17d4bc:	ac6b013c */ 	sw	$t3,0x13c($v1)
/*  f17d4c0:	916d003f */ 	lbu	$t5,0x3f($t3)
/*  f17d4c4:	35b90020 */ 	ori	$t9,$t5,0x20
/*  f17d4c8:	a179003f */ 	sb	$t9,0x3f($t3)
.NB0f17d4cc:
/*  f17d4cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17d4d0:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f17d4d4:	03e00008 */ 	jr	$ra
/*  f17d4d8:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

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

void scenarioHtmTick(void)
{
	u8 stack[8];
	s32 i;
	u32 prevplayernum = g_Vars.currentplayernum;
	struct prop *prop;

	if (var800869ec && var800869ec->prop) {
		if (g_ScenarioData.htm.uplink == NULL || g_ScenarioData.htm.uplink->type != PROPTYPE_WEAPON) {
			var800869ec = 0;
		} else {
			var800869ec->prop->timetoregen = PALDOWN(1200);
		}
	}

	g_ScenarioData.htm.uplink = NULL;

	// Check if uplink is on the ground
	prop = g_Vars.activeprops;

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

#if VERSION >= VERSION_PAL_FINAL
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
/*  f1833dc:	0fc2866a */ 	jal	bgunGetWeaponNum
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
/*  f1834a0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
/*  f1834a4:	ac30c1e4 */ 	sw	$s0,%lo(g_ScenarioData+0xd4)($at)
/*  f1834a8:	a432c1e0 */ 	sh	$s2,%lo(g_ScenarioData+0xd0)($at)
/*  f1834ac:	a432c1e2 */ 	sh	$s2,%lo(g_ScenarioData+0xd2)($at)
/*  f1834b0:	1680003b */ 	bnez	$s4,.L0f1835a0
/*  f1834b4:	ade00108 */ 	sw	$zero,0x108($t7)
/*  f1834b8:	0fc5b9f1 */ 	jal	langGet
/*  f1834bc:	24045412 */ 	addiu	$a0,$zero,0x5413
/*  f1834c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1834c4:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1834c8:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f18354c:	24045413 */ 	addiu	$a0,$zero,0x5414
/*  f183550:	00402025 */ 	or	$a0,$v0,$zero
/*  f183554:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f183558:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f183598:	0c0041c6 */ 	jal	snd00010718
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
/*  f183654:	0fc2866a */ 	jal	bgunGetWeaponNum
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
/*  f1836dc:	0fc259d4 */ 	jal	atan2f
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
/*  f183814:	24045411 */ 	addiu	$a0,$zero,0x5412
/*  f183818:	00402025 */ 	or	$a0,$v0,$zero
/*  f18381c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f183820:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f183888:	0c0041c6 */ 	jal	snd00010718
/*  f18388c:	e7a80014 */ 	swc1	$f8,0x14($sp)
.L0f183890:
/*  f183890:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
/*  f183894:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f183898:	240dffff */ 	addiu	$t5,$zero,-1
/*  f18389c:	240effff */ 	addiu	$t6,$zero,-1
/*  f1838a0:	ac2dc1e4 */ 	sw	$t5,%lo(g_ScenarioData+0xd4)($at)
/*  f1838a4:	a42ec1e0 */ 	sh	$t6,%lo(g_ScenarioData+0xd0)($at)
/*  f1838a8:	10000035 */ 	b	.L0f183980
/*  f1838ac:	ade00000 */ 	sw	$zero,0x0($t7)
.L0f1838b0:
/*  f1838b0:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x34)
/*  f1838b4:	8f399ff4 */ 	lw	$t9,%lo(g_Vars+0x34)($t9)
/*  f1838b8:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f1838bc:	03194021 */ 	addu	$t0,$t8,$t9
/*  f1838c0:	290112c1 */ 	slti	$at,$t0,0xfa1
/*  f1838c4:	1420002e */ 	bnez	$at,.L0f183980
/*  f1838c8:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f1838cc:	8e6a00d8 */ 	lw	$t2,0xd8($s3)
/*  f1838d0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd2)
/*  f1838d4:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f1838d8:	ae6b00d8 */ 	sw	$t3,0xd8($s3)
/*  f1838dc:	16800022 */ 	bnez	$s4,.L0f183968
/*  f1838e0:	a432c1e2 */ 	sh	$s2,%lo(g_ScenarioData+0xd2)($at)
/*  f1838e4:	0fc5b9f1 */ 	jal	langGet
/*  f1838e8:	24045410 */ 	addiu	$a0,$zero,0x5411
/*  f1838ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f1838f0:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1838f4:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f18395c:	0c0041c6 */ 	jal	snd00010718
/*  f183960:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f183964:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f183968:
/*  f183968:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
/*  f18396c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f183970:	240affff */ 	addiu	$t2,$zero,-1
/*  f183974:	ac29c1e4 */ 	sw	$t1,%lo(g_ScenarioData+0xd4)($at)
/*  f183978:	a42ac1e0 */ 	sh	$t2,%lo(g_ScenarioData+0xd0)($at)
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
#else
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
/*  f1833dc:	0fc2866a */ 	jal	bgunGetWeaponNum
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
/*  f1834a0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
/*  f1834a4:	ac30c1e4 */ 	sw	$s0,%lo(g_ScenarioData+0xd4)($at)
/*  f1834a8:	a432c1e0 */ 	sh	$s2,%lo(g_ScenarioData+0xd0)($at)
/*  f1834ac:	a432c1e2 */ 	sh	$s2,%lo(g_ScenarioData+0xd2)($at)
/*  f1834b0:	1680003b */ 	bnez	$s4,.L0f1835a0
/*  f1834b4:	ade00108 */ 	sw	$zero,0x108($t7)
/*  f1834b8:	0fc5b9f1 */ 	jal	langGet
/*  f1834bc:	24045412 */ 	addiu	$a0,$zero,0x5412
/*  f1834c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1834c4:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1834c8:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f183558:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f183598:	0c0041c6 */ 	jal	snd00010718
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
/*  f183654:	0fc2866a */ 	jal	bgunGetWeaponNum
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
/*  f1836dc:	0fc259d4 */ 	jal	atan2f
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
/*  f183820:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f183888:	0c0041c6 */ 	jal	snd00010718
/*  f18388c:	e7a80014 */ 	swc1	$f8,0x14($sp)
.L0f183890:
/*  f183890:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
/*  f183894:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f183898:	240dffff */ 	addiu	$t5,$zero,-1
/*  f18389c:	240effff */ 	addiu	$t6,$zero,-1
/*  f1838a0:	ac2dc1e4 */ 	sw	$t5,%lo(g_ScenarioData+0xd4)($at)
/*  f1838a4:	a42ec1e0 */ 	sh	$t6,%lo(g_ScenarioData+0xd0)($at)
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
/*  f1838f4:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f18395c:	0c0041c6 */ 	jal	snd00010718
/*  f183960:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f183964:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f183968:
/*  f183968:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
/*  f18396c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f183970:	240affff */ 	addiu	$t2,$zero,-1
/*  f183974:	ac29c1e4 */ 	sw	$t1,%lo(g_ScenarioData+0xd4)($at)
/*  f183978:	a42ac1e0 */ 	sh	$t2,%lo(g_ScenarioData+0xd0)($at)
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
#endif

#if PAL
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
/*  f183a7c:	3c014596 */ 	lui	$at,0x457a
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
#else
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
#endif

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

#if VERSION >= VERSION_PAL_FINAL
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
/*  f1846a4:	2404540d */ 	addiu	$a0,$zero,0x540e
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
/*  f1846cc:	0fc619e0 */ 	jal	mpChrsAreSameTeam
/*  f1846d0:	02202825 */ 	or	$a1,$s1,$zero
/*  f1846d4:	10400009 */ 	beqz	$v0,.L0f1846fc
/*  f1846d8:	00000000 */ 	nop
/*  f1846dc:	0fc5b9f1 */ 	jal	langGet
/*  f1846e0:	2404540e */ 	addiu	$a0,$zero,0x540f
/*  f1846e4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1846e8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1846ec:	0c004dad */ 	jal	sprintf
/*  f1846f0:	8e060000 */ 	lw	$a2,0x0($s0)
/*  f1846f4:	10000008 */ 	b	.L0f184718
/*  f1846f8:	02202025 */ 	or	$a0,$s1,$zero
.L0f1846fc:
/*  f1846fc:	0fc5b9f1 */ 	jal	langGet
/*  f184700:	2404540f */ 	addiu	$a0,$zero,0x5410
/*  f184704:	02402025 */ 	or	$a0,$s2,$zero
/*  f184708:	00402825 */ 	or	$a1,$v0,$zero
/*  f18470c:	0c004dad */ 	jal	sprintf
/*  f184710:	8e060000 */ 	lw	$a2,0x0($s0)
/*  f184714:	02202025 */ 	or	$a0,$s1,$zero
.L0f184718:
/*  f184718:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
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
#else
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
/*  f1846cc:	0fc619e0 */ 	jal	mpChrsAreSameTeam
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
/*  f184718:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
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
#endif

#if VERSION >= VERSION_PAL_FINAL
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
/*  f184804:	0fc619e0 */ 	jal	mpChrsAreSameTeam
/*  f184808:	00000000 */ 	nop
/*  f18480c:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f184810:	1040000d */ 	beqz	$v0,.L0f184848
/*  f184814:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f184818:	0fc5b9f1 */ 	jal	langGet
/*  f18481c:	24045408 */ 	addiu	$a0,$zero,0x5409
/*  f184820:	02002025 */ 	or	$a0,$s0,$zero
/*  f184824:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
/*  f184828:	00402825 */ 	or	$a1,$v0,$zero
/*  f18482c:	0fc5b9f1 */ 	jal	langGet
/*  f184830:	24045409 */ 	addiu	$a0,$zero,0x540a
/*  f184834:	02002025 */ 	or	$a0,$s0,$zero
/*  f184838:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
/*  f18483c:	00402825 */ 	or	$a1,$v0,$zero
/*  f184840:	10000015 */ 	b	.L0f184898
/*  f184844:	00000000 */ 	nop
.L0f184848:
/*  f184848:	00104840 */ 	sll	$t1,$s0,0x1
/*  f18484c:	00691021 */ 	addu	$v0,$v1,$t1
/*  f184850:	844a0020 */ 	lh	$t2,0x20($v0)
/*  f184854:	2404540a */ 	addiu	$a0,$zero,0x540b
/*  f184858:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f18485c:	0fc5b9f1 */ 	jal	langGet
/*  f184860:	a44b0020 */ 	sh	$t3,0x20($v0)
/*  f184864:	02002025 */ 	or	$a0,$s0,$zero
/*  f184868:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
/*  f18486c:	00402825 */ 	or	$a1,$v0,$zero
/*  f184870:	0fc5b9f1 */ 	jal	langGet
/*  f184874:	2404540b */ 	addiu	$a0,$zero,0x540c
/*  f184878:	02002025 */ 	or	$a0,$s0,$zero
/*  f18487c:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
/*  f184880:	00402825 */ 	or	$a1,$v0,$zero
/*  f184884:	0fc5b9f1 */ 	jal	langGet
/*  f184888:	2404540c */ 	addiu	$a0,$zero,0x540d
/*  f18488c:	02002025 */ 	or	$a0,$s0,$zero
/*  f184890:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
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
#elif VERSION >= VERSION_NTSC_1_0
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
/*  f184804:	0fc619e0 */ 	jal	mpChrsAreSameTeam
/*  f184808:	00000000 */ 	nop
/*  f18480c:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f184810:	1040000d */ 	beqz	$v0,.L0f184848
/*  f184814:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f184818:	0fc5b9f1 */ 	jal	langGet
/*  f18481c:	24045408 */ 	addiu	$a0,$zero,0x5408
/*  f184820:	02002025 */ 	or	$a0,$s0,$zero
/*  f184824:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
/*  f184828:	00402825 */ 	or	$a1,$v0,$zero
/*  f18482c:	0fc5b9f1 */ 	jal	langGet
/*  f184830:	24045409 */ 	addiu	$a0,$zero,0x5409
/*  f184834:	02002025 */ 	or	$a0,$s0,$zero
/*  f184838:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
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
/*  f184868:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
/*  f18486c:	00402825 */ 	or	$a1,$v0,$zero
/*  f184870:	0fc5b9f1 */ 	jal	langGet
/*  f184874:	2404540b */ 	addiu	$a0,$zero,0x540b
/*  f184878:	02002025 */ 	or	$a0,$s0,$zero
/*  f18487c:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
/*  f184880:	00402825 */ 	or	$a1,$v0,$zero
/*  f184884:	0fc5b9f1 */ 	jal	langGet
/*  f184888:	2404540c */ 	addiu	$a0,$zero,0x540c
/*  f18488c:	02002025 */ 	or	$a0,$s0,$zero
/*  f184890:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
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
#else
GLOBAL_ASM(
glabel func0f1847b8
/*  f17edfc:	3c03800b */ 	lui	$v1,0x800b
/*  f17ee00:	246309c0 */ 	addiu	$v1,$v1,0x9c0
/*  f17ee04:	8c6e0004 */ 	lw	$t6,0x4($v1)
/*  f17ee08:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f17ee0c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17ee10:	00808025 */ 	or	$s0,$a0,$zero
/*  f17ee14:	05c00033 */ 	bltz	$t6,.NB0f17eee4
/*  f17ee18:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f17ee1c:	3c0f800b */ 	lui	$t7,0x800b
/*  f17ee20:	8def09c4 */ 	lw	$t7,0x9c4($t7)
/*  f17ee24:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f17ee28:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f17ee2c:	87280008 */ 	lh	$t0,0x8($t9)
/*  f17ee30:	54a8002d */ 	bnel	$a1,$t0,.NB0f17eee8
/*  f17ee34:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f17ee38:	5085002b */ 	beql	$a0,$a1,.NB0f17eee8
/*  f17ee3c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f17ee40:	04800026 */ 	bltz	$a0,.NB0f17eedc
/*  f17ee44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ee48:	0fc602fa */ 	jal	mpChrsAreSameTeam
/*  f17ee4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ee50:	3c03800b */ 	lui	$v1,0x800b
/*  f17ee54:	1040000d */ 	beqz	$v0,.NB0f17ee8c
/*  f17ee58:	246309c0 */ 	addiu	$v1,$v1,0x9c0
/*  f17ee5c:	0fc5a4dd */ 	jal	langGet
/*  f17ee60:	24045408 */ 	addiu	$a0,$zero,0x5408
/*  f17ee64:	02002025 */ 	or	$a0,$s0,$zero
/*  f17ee68:	0fc602c8 */ 	jal	mpCreateScenarioHudmsg
/*  f17ee6c:	00402825 */ 	or	$a1,$v0,$zero
/*  f17ee70:	0fc5a4dd */ 	jal	langGet
/*  f17ee74:	24045409 */ 	addiu	$a0,$zero,0x5409
/*  f17ee78:	02002025 */ 	or	$a0,$s0,$zero
/*  f17ee7c:	0fc602c8 */ 	jal	mpCreateScenarioHudmsg
/*  f17ee80:	00402825 */ 	or	$a1,$v0,$zero
/*  f17ee84:	10000015 */ 	beqz	$zero,.NB0f17eedc
/*  f17ee88:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f17ee8c:
/*  f17ee8c:	00104840 */ 	sll	$t1,$s0,0x1
/*  f17ee90:	00691021 */ 	addu	$v0,$v1,$t1
/*  f17ee94:	844a0020 */ 	lh	$t2,0x20($v0)
/*  f17ee98:	2404540a */ 	addiu	$a0,$zero,0x540a
/*  f17ee9c:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f17eea0:	0fc5a4dd */ 	jal	langGet
/*  f17eea4:	a44b0020 */ 	sh	$t3,0x20($v0)
/*  f17eea8:	02002025 */ 	or	$a0,$s0,$zero
/*  f17eeac:	0fc602c8 */ 	jal	mpCreateScenarioHudmsg
/*  f17eeb0:	00402825 */ 	or	$a1,$v0,$zero
/*  f17eeb4:	0fc5a4dd */ 	jal	langGet
/*  f17eeb8:	2404540b */ 	addiu	$a0,$zero,0x540b
/*  f17eebc:	02002025 */ 	or	$a0,$s0,$zero
/*  f17eec0:	0fc602c8 */ 	jal	mpCreateScenarioHudmsg
/*  f17eec4:	00402825 */ 	or	$a1,$v0,$zero
/*  f17eec8:	0fc5a4dd */ 	jal	langGet
/*  f17eecc:	2404540c */ 	addiu	$a0,$zero,0x540c
/*  f17eed0:	02002025 */ 	or	$a0,$s0,$zero
/*  f17eed4:	0fc602c8 */ 	jal	mpCreateScenarioHudmsg
/*  f17eed8:	00402825 */ 	or	$a1,$v0,$zero
.NB0f17eedc:
/*  f17eedc:	0fc5fb00 */ 	jal	func0f1845bc
/*  f17eee0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f17eee4:
/*  f17eee4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.NB0f17eee8:
/*  f17eee8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f17eeec:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f17eef0:	03e00008 */ 	jr	$ra
/*  f17eef4:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel scenarioPacTick
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
/*  f1849b8:	2dc13841 */ 	sltiu	$at,$t6,0x2ee1
/*  f1849bc:	14200012 */ 	bnez	$at,.L0f184a08
/*  f1849c0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x2)
/*  f1849c4:	a420c112 */ 	sh	$zero,%lo(g_ScenarioData+0x2)($at)
/*  f1849c8:	846f0008 */ 	lh	$t7,0x8($v1)
/*  f1849cc:	24045407 */ 	addiu	$a0,$zero,0x5408
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
/*  f184a00:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
/*  f184a04:	8484c118 */ 	lh	$a0,%lo(g_ScenarioData+0x8)($a0)
.L0f184a08:
/*  f184a08:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f184a0c:
/*  f184a0c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f184a10:	03e00008 */ 	jr	$ra
/*  f184a14:	00000000 */ 	nop
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel scenarioPacTick
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
/*  f184a00:	0fc619ae */ 	jal	mpCreateScenarioHudmsg
/*  f184a04:	8484c118 */ 	lh	$a0,%lo(g_ScenarioData+0x8)($a0)
.L0f184a08:
/*  f184a08:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f184a0c:
/*  f184a0c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f184a10:	03e00008 */ 	jr	$ra
/*  f184a14:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel scenarioPacTick
/*  f17eef8:	3c03800b */ 	lui	$v1,0x800b
/*  f17eefc:	246309c0 */ 	addiu	$v1,$v1,0x9c0
/*  f17ef00:	8c6e0004 */ 	lw	$t6,0x4($v1)
/*  f17ef04:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17ef08:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17ef0c:	15c10005 */ 	bne	$t6,$at,.NB0f17ef24
/*  f17ef10:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17ef14:	0fc5fb00 */ 	jal	func0f1845bc
/*  f17ef18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ef1c:	3c03800b */ 	lui	$v1,0x800b
/*  f17ef20:	246309c0 */ 	addiu	$v1,$v1,0x9c0
.NB0f17ef24:
/*  f17ef24:	3c0f800b */ 	lui	$t7,0x800b
/*  f17ef28:	8def09c4 */ 	lw	$t7,0x9c4($t7)
/*  f17ef2c:	3c02800b */ 	lui	$v0,0x800b
/*  f17ef30:	3c18800a */ 	lui	$t8,0x800a
/*  f17ef34:	05e2001e */ 	bltzl	$t7,.NB0f17efb0
/*  f17ef38:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17ef3c:	944209c2 */ 	lhu	$v0,0x9c2($v0)
/*  f17ef40:	8f18e6f4 */ 	lw	$t8,-0x190c($t8)
/*  f17ef44:	3c01800b */ 	lui	$at,0x800b
/*  f17ef48:	000f4040 */ 	sll	$t0,$t7,0x1
/*  f17ef4c:	00581021 */ 	addu	$v0,$v0,$t8
/*  f17ef50:	3059ffff */ 	andi	$t9,$v0,0xffff
/*  f17ef54:	a43909c2 */ 	sh	$t9,0x9c2($at)
/*  f17ef58:	2f213841 */ 	sltiu	$at,$t9,0x3841
/*  f17ef5c:	14200013 */ 	bnez	$at,.NB0f17efac
/*  f17ef60:	00684821 */ 	addu	$t1,$v1,$t0
/*  f17ef64:	3c01800b */ 	lui	$at,0x800b
/*  f17ef68:	a42009c2 */ 	sh	$zero,0x9c2($at)
/*  f17ef6c:	852a0008 */ 	lh	$t2,0x8($t1)
/*  f17ef70:	24045407 */ 	addiu	$a0,$zero,0x5407
/*  f17ef74:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f17ef78:	006b1021 */ 	addu	$v0,$v1,$t3
/*  f17ef7c:	844c0038 */ 	lh	$t4,0x38($v0)
/*  f17ef80:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f17ef84:	0fc5a4dd */ 	jal	langGet
/*  f17ef88:	a44d0038 */ 	sh	$t5,0x38($v0)
/*  f17ef8c:	3c0e800b */ 	lui	$t6,0x800b
/*  f17ef90:	8dce09c4 */ 	lw	$t6,0x9c4($t6)
/*  f17ef94:	3c04800b */ 	lui	$a0,0x800b
/*  f17ef98:	00402825 */ 	or	$a1,$v0,$zero
/*  f17ef9c:	000ec040 */ 	sll	$t8,$t6,0x1
/*  f17efa0:	00982021 */ 	addu	$a0,$a0,$t8
/*  f17efa4:	0fc602c8 */ 	jal	mpCreateScenarioHudmsg
/*  f17efa8:	848409c8 */ 	lh	$a0,0x9c8($a0)
.NB0f17efac:
/*  f17efac:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f17efb0:
/*  f17efb0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17efb4:	03e00008 */ 	jr	$ra
/*  f17efb8:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

//void scenarioPacTick(void)
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
//				mpCreateScenarioHudmsg(g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex], langGet(L_MPWEAPONS_007)); // "Have a point for living!"
//			}
//		}
//	}
//}

#if VERSION >= VERSION_PAL_FINAL
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
/*  f184a68:	240d3840 */ 	addiu	$t5,$zero,0x2ee0
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
/*  f184ab4:	24083840 */ 	addiu	$t0,$zero,0x2ee0
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
/*  f184af0:	240100f0 */ 	addiu	$at,$zero,0xc8
/*  f184af4:	00403025 */ 	or	$a2,$v0,$zero
/*  f184af8:	24a588c0 */ 	addiu	$a1,$a1,%lo(var7f1b88c0)
/*  f184afc:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f184b00:	0000c812 */ 	mflo	$t9
/*  f184b04:	00791823 */ 	subu	$v1,$v1,$t9
/*  f184b08:	246700ef */ 	addiu	$a3,$v1,0xc7
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
/*  f184b94:	0c002f02 */ 	jal	viGetWidth
/*  f184b98:	00408025 */ 	or	$s0,$v0,$zero
/*  f184b9c:	0c002f06 */ 	jal	viGetHeight
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
#elif VERSION >= VERSION_NTSC_1_0
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
/*  f184b94:	0c002f02 */ 	jal	viGetWidth
/*  f184b98:	00408025 */ 	or	$s0,$v0,$zero
/*  f184b9c:	0c002f06 */ 	jal	viGetHeight
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
#else
GLOBAL_ASM(
glabel scenarioPacCallback18
/*  f17efbc:	3c02800b */ 	lui	$v0,0x800b
/*  f17efc0:	244209c0 */ 	addiu	$v0,$v0,0x9c0
/*  f17efc4:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f17efc8:	3c0e800a */ 	lui	$t6,0x800a
/*  f17efcc:	8dcee94c */ 	lw	$t6,-0x16b4($t6)
/*  f17efd0:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f17efd4:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f17efd8:	87290008 */ 	lh	$t1,0x8($t9)
/*  f17efdc:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f17efe0:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f17efe4:	00808025 */ 	or	$s0,$a0,$zero
/*  f17efe8:	15c9006e */ 	bne	$t6,$t1,.NB0f17f1a4
/*  f17efec:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f17eff0:	3c0a800b */ 	lui	$t2,0x800b
/*  f17eff4:	954a09c2 */ 	lhu	$t2,0x9c2($t2)
/*  f17eff8:	240b3840 */ 	addiu	$t3,$zero,0x3840
/*  f17effc:	016a1823 */ 	subu	$v1,$t3,$t2
/*  f17f000:	0c002fb5 */ 	jal	viGetViewLeft
/*  f17f004:	afa300a0 */ 	sw	$v1,0xa0($sp)
/*  f17f008:	0c002f97 */ 	jal	viGetViewWidth
/*  f17f00c:	a7a20046 */ 	sh	$v0,0x46($sp)
/*  f17f010:	87ad0046 */ 	lh	$t5,0x46($sp)
/*  f17f014:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f17f018:	04410003 */ 	bgez	$v0,.NB0f17f028
/*  f17f01c:	00026043 */ 	sra	$t4,$v0,0x1
/*  f17f020:	24410001 */ 	addiu	$at,$v0,0x1
/*  f17f024:	00016043 */ 	sra	$t4,$at,0x1
.NB0f17f028:
/*  f17f028:	018d4021 */ 	addu	$t0,$t4,$t5
/*  f17f02c:	0c002fb9 */ 	jal	viGetViewTop
/*  f17f030:	afa8008c */ 	sw	$t0,0x8c($sp)
/*  f17f034:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f17f038:	244f000a */ 	addiu	$t7,$v0,0xa
/*  f17f03c:	afaf0088 */ 	sw	$t7,0x88($sp)
/*  f17f040:	04610002 */ 	bgez	$v1,.NB0f17f04c
/*  f17f044:	24083840 */ 	addiu	$t0,$zero,0x3840
/*  f17f048:	00001825 */ 	or	$v1,$zero,$zero
.NB0f17f04c:
/*  f17f04c:	0068001a */ 	div	$zero,$v1,$t0
/*  f17f050:	00001012 */ 	mflo	$v0
/*  f17f054:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f17f058:	15000002 */ 	bnez	$t0,.NB0f17f064
/*  f17f05c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f060:	0007000d */ 	break	0x7
.NB0f17f064:
/*  f17f064:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17f068:	15010004 */ 	bne	$t0,$at,.NB0f17f07c
/*  f17f06c:	3c018000 */ 	lui	$at,0x8000
/*  f17f070:	14610002 */ 	bne	$v1,$at,.NB0f17f07c
/*  f17f074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f078:	0006000d */ 	break	0x6
.NB0f17f07c:
/*  f17f07c:	00480019 */ 	multu	$v0,$t0
/*  f17f080:	240100f0 */ 	addiu	$at,$zero,0xf0
/*  f17f084:	00403025 */ 	or	$a2,$v0,$zero
/*  f17f088:	24a531b0 */ 	addiu	$a1,$a1,0x31b0
/*  f17f08c:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f17f090:	0000c012 */ 	mflo	$t8
/*  f17f094:	00781823 */ 	subu	$v1,$v1,$t8
/*  f17f098:	246700ef */ 	addiu	$a3,$v1,0xef
/*  f17f09c:	00e1001a */ 	div	$zero,$a3,$at
/*  f17f0a0:	00003812 */ 	mflo	$a3
/*  f17f0a4:	0c004fc1 */ 	jal	sprintf
/*  f17f0a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f0ac:	0fc5374a */ 	jal	func0f153628
/*  f17f0b0:	02002025 */ 	or	$a0,$s0,$zero
/*  f17f0b4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f17f0b8:	8dce2364 */ 	lw	$t6,0x2364($t6)
/*  f17f0bc:	3c078008 */ 	lui	$a3,0x8008
/*  f17f0c0:	00408025 */ 	or	$s0,$v0,$zero
/*  f17f0c4:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f17f0c8:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f17f0cc:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f17f0d0:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f17f0d4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f17f0d8:	0fc54655 */ 	jal	textMeasure
/*  f17f0dc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f17f0e0:	8fa20094 */ 	lw	$v0,0x94($sp)
/*  f17f0e4:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f17f0e8:	8fab0090 */ 	lw	$t3,0x90($sp)
/*  f17f0ec:	8faa0088 */ 	lw	$t2,0x88($sp)
/*  f17f0f0:	04410003 */ 	bgez	$v0,.NB0f17f100
/*  f17f0f4:	00024843 */ 	sra	$t1,$v0,0x1
/*  f17f0f8:	24410001 */ 	addiu	$at,$v0,0x1
/*  f17f0fc:	00014843 */ 	sra	$t1,$at,0x1
.NB0f17f100:
/*  f17f100:	01094023 */ 	subu	$t0,$t0,$t1
/*  f17f104:	27ad0090 */ 	addiu	$t5,$sp,0x90
/*  f17f108:	00481021 */ 	addu	$v0,$v0,$t0
/*  f17f10c:	016a6021 */ 	addu	$t4,$t3,$t2
/*  f17f110:	afac0090 */ 	sw	$t4,0x90($sp)
/*  f17f114:	afa20094 */ 	sw	$v0,0x94($sp)
/*  f17f118:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f17f11c:	afa8008c */ 	sw	$t0,0x8c($sp)
/*  f17f120:	02002025 */ 	or	$a0,$s0,$zero
/*  f17f124:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f17f128:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f17f12c:	0fc537d6 */ 	jal	func0f153858
/*  f17f130:	27a70094 */ 	addiu	$a3,$sp,0x94
/*  f17f134:	0c002f77 */ 	jal	viGetWidth
/*  f17f138:	00408025 */ 	or	$s0,$v0,$zero
/*  f17f13c:	0c002f7b */ 	jal	viGetHeight
/*  f17f140:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f17f144:	3c0f8008 */ 	lui	$t7,0x8008
/*  f17f148:	3c188008 */ 	lui	$t8,0x8008
/*  f17f14c:	8f18235c */ 	lw	$t8,0x235c($t8)
/*  f17f150:	8def2360 */ 	lw	$t7,0x2360($t7)
/*  f17f154:	87a90044 */ 	lh	$t1,0x44($sp)
/*  f17f158:	3c1900ff */ 	lui	$t9,0xff
/*  f17f15c:	373900a0 */ 	ori	$t9,$t9,0xa0
/*  f17f160:	240e0088 */ 	addiu	$t6,$zero,0x88
/*  f17f164:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f17f168:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f17f16c:	02002025 */ 	or	$a0,$s0,$zero
/*  f17f170:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f17f174:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f17f178:	27a70048 */ 	addiu	$a3,$sp,0x48
/*  f17f17c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f17f180:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f17f184:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f17f188:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f17f18c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f17f190:	0fc54529 */ 	jal	textRender
/*  f17f194:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f17f198:	0fc537a0 */ 	jal	func0f153780
/*  f17f19c:	00402025 */ 	or	$a0,$v0,$zero
/*  f17f1a0:	00408025 */ 	or	$s0,$v0,$zero
.NB0f17f1a4:
/*  f17f1a4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f17f1a8:	02001025 */ 	or	$v0,$s0,$zero
/*  f17f1ac:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f17f1b0:	03e00008 */ 	jr	$ra
/*  f17f1b4:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);
#endif

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
s32 mpOptionsMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
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

struct menuitem g_MpPopacapOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222,  MPOPTION_ONEHITKILLS,         menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223,  0x00000000,                   menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224,  MPOPTION_FASTMOVEMENT,        menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225,  MPOPTION_DISPLAYTEAM,         menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226,  MPOPTION_NORADAR,             menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227,  MPOPTION_NOAUTOAIM,           menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS_493, MPOPTION_KILLSSCORE,          menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                   NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_230,  MPOPTION_PAC_HIGHLIGHTTARGET, menuhandlerMpCheckboxOption }, // "Highlight Target"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_238,  MPOPTION_PAC_SHOWONRADAR,     menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                   NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239,  0x00000000,                   NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,                   NULL                        },
};

struct menudialog g_MpPopacapOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_218, // "Pop a Cap Options"
	g_MpPopacapOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

struct mpscenario g_MpScenarios[6] = {
	{
		&g_MpCombatOptionsMenuDialog,
	}, {
		&g_MpBriefcaseOptionsMenuDialog,
		scenarioHtbInit,
		scenarioHtbCallback08,
		scenarioHtbReset,
		scenarioHtbTick,
		scenarioHtbCallback14,
		scenarioHtbCallback18,
		scenarioHtbKill,
		scenarioHtbRadar,
		scenarioHtbRadar2,
		scenarioHtbHighlight,
	}, {
		&g_MpHackerOptionsMenuDialog,
		scenarioHtmInit,
		scenarioHtmCallback08,
		scenarioHtmReset,
		scenarioHtmTick,
		scenarioHtmCallback14,
		scenarioHtmCallback18,
		scenarioHtmKill,
		scenarioHtmRadar,
		scenarioHtmRadar2,
		scenarioHtmHighlight,
	}, {
		&g_MpPopacapOptionsMenuDialog,
		scenarioPacInit,
		NULL,
		scenarioPacReset,
		scenarioPacTick,
		NULL,
		scenarioPacCallback18,
		scenarioPacKill,
		scenarioPacRadar,
		scenarioPacRadar2,
		scenarioPacHighlight,
	}, {
		&g_MpHillOptionsMenuDialog,
		scenarioKohInit,
		NULL,
		scenarioKohReset,
		scenarioKohTick,
		NULL,
		scenarioKohCallback18,
		scenarioKohKill,
		scenarioKohRadar,
		NULL,
		NULL,
		NULL,
		NULL,
		scenarioKohIsRoomHighlighted,
		scenarioKohCallback38,
		NULL,
		scenarioKohCallback40,
		scenarioKohCallback44
	}, {
		&g_MpCaptureOptionsMenuDialog,
		scenarioCtcInit,
		scenarioCtcCallback08,
		scenarioCtcReset,
		scenarioCtcTick,
		scenarioCtcCallback14,
		NULL,
		scenarioCtcKill,
		scenarioCtcRadar,
		scenarioCtcRadar2,
		scenarioCtcHighlight,
		scenarioCtcChooseSpawnLocation,
		scenarioCtcGetMaxTeams,
		scenarioCtcIsRoomHighlighted,
		scenarioCtcCallback38,
	},
};

struct mpscenariooverview g_MpScenarioOverviews[] = {
	// Full name, short name, unlock flags?
	{ L_MPMENU_246, L_MPMENU_253, 0x00, false }, // "Combat", "Combat"
	{ L_MPMENU_247, L_MPMENU_254, 0x20, false }, // "Hold the Briefcase", "Briefcase"
	{ L_MPMENU_248, L_MPMENU_255, 0x4e, false }, // "Hacker Central", "Hacker"
	{ L_MPMENU_249, L_MPMENU_256, 0x4d, false }, // "Pop a Cap", "Pop"
	{ L_MPMENU_250, L_MPMENU_257, 0x1f, true  }, // "King of the Hill", "Hill"
	{ L_MPMENU_251, L_MPMENU_258, 0x21, true  }, // "Capture the Case", "Capture"
};

u32 var8008716c = 0x00000000;
u32 var80087170 = 0x50f40000; // "Free for All!"
u32 var80087174 = 0x00000004;
u32 var80087178 = 0x50f50000; // "-Teamwork-"

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

s32 menuhandlerMpOpenOptions(s32 operation, struct menuitem *item, union handlerdata *data)
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

void mpCreateMatchStartHudmsgs(void)
{
	s32 i;
	s32 prevplayernum = g_Vars.currentplayernum;
	char challengename[60];
	char scenarioname[60];

	if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE) {
		sprintf(challengename, "%s:\n", mpGetChallengeNameBySlot(mpGetCurrentChallengeIndex()));
	}

	sprintf(scenarioname, "%s\n", langGet(g_MpScenarioOverviews[g_MpSetup.scenario].name));

	for (i = 0; i < g_MpNumPlayers; i++) {
		if (g_MpPlayerChrs[i]->aibot == NULL) {
			setCurrentPlayerNum(i);

			if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE) {
				hudmsgCreateWithFlags(challengename, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE);
			}

			hudmsgCreateWithFlags(scenarioname, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE);
		}
	}

	setCurrentPlayerNum(prevplayernum);
}

void scenarioTick(void)
{
	if (g_Vars.normmplayerisrunning) {
		if (g_Vars.lvframenum == 5) {
			mpCreateMatchStartHudmsgs();
		}

		if (g_MpScenarios[g_MpSetup.scenario].tickfunc) {
			g_MpScenarios[g_MpSetup.scenario].tickfunc();
		}
	}
}

void scenarioCallback14(struct chrdata *chr)
{
	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].unk14) {
		g_MpScenarios[g_MpSetup.scenario].unk14(chr);
	}
}

#if VERSION >= VERSION_NTSC_1_0
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
#else
GLOBAL_ASM(
glabel func0f185774
/*  f17fd14:	3c08800a */ 	lui	$t0,0x800a
/*  f17fd18:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f17fd1c:	8d0e0318 */ 	lw	$t6,0x318($t0)
/*  f17fd20:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f17fd24:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17fd28:	00808025 */ 	or	$s0,$a0,$zero
/*  f17fd2c:	11c000ce */ 	beqz	$t6,.NB0f180068
/*  f17fd30:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f17fd34:	3c0f800b */ 	lui	$t7,0x800b
/*  f17fd38:	91ef1448 */ 	lbu	$t7,0x1448($t7)
/*  f17fd3c:	3c028009 */ 	lui	$v0,0x8009
/*  f17fd40:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f17fd44:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17fd48:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f17fd4c:	00581021 */ 	addu	$v0,$v0,$t8
/*  f17fd50:	8c429730 */ 	lw	$v0,-0x68d0($v0)
/*  f17fd54:	50400007 */ 	beqzl	$v0,.NB0f17fd74
/*  f17fd58:	8d19006c */ 	lw	$t9,0x6c($t0)
/*  f17fd5c:	0040f809 */ 	jalr	$v0
/*  f17fd60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fd64:	3c08800a */ 	lui	$t0,0x800a
/*  f17fd68:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f17fd6c:	00408025 */ 	or	$s0,$v0,$zero
/*  f17fd70:	8d19006c */ 	lw	$t9,0x6c($t0)
.NB0f17fd74:
/*  f17fd74:	00003825 */ 	or	$a3,$zero,$zero
/*  f17fd78:	00002825 */ 	or	$a1,$zero,$zero
/*  f17fd7c:	13200003 */ 	beqz	$t9,.NB0f17fd8c
/*  f17fd80:	3c04800b */ 	lui	$a0,0x800b
/*  f17fd84:	10000001 */ 	beqz	$zero,.NB0f17fd8c
/*  f17fd88:	24070001 */ 	addiu	$a3,$zero,0x1
.NB0f17fd8c:
/*  f17fd8c:	8d090068 */ 	lw	$t1,0x68($t0)
/*  f17fd90:	00003025 */ 	or	$a2,$zero,$zero
/*  f17fd94:	00001025 */ 	or	$v0,$zero,$zero
/*  f17fd98:	11200003 */ 	beqz	$t1,.NB0f17fda8
/*  f17fd9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fda0:	10000001 */ 	beqz	$zero,.NB0f17fda8
/*  f17fda4:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f17fda8:
/*  f17fda8:	8d0a0064 */ 	lw	$t2,0x64($t0)
/*  f17fdac:	11400003 */ 	beqz	$t2,.NB0f17fdbc
/*  f17fdb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fdb4:	10000001 */ 	beqz	$zero,.NB0f17fdbc
/*  f17fdb8:	24060001 */ 	addiu	$a2,$zero,0x1
.NB0f17fdbc:
/*  f17fdbc:	8d0b0070 */ 	lw	$t3,0x70($t0)
/*  f17fdc0:	11600003 */ 	beqz	$t3,.NB0f17fdd0
/*  f17fdc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fdc8:	10000001 */ 	beqz	$zero,.NB0f17fdd0
/*  f17fdcc:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f17fdd0:
/*  f17fdd0:	8c841444 */ 	lw	$a0,0x1444($a0)
/*  f17fdd4:	00466021 */ 	addu	$t4,$v0,$a2
/*  f17fdd8:	01856821 */ 	addu	$t5,$t4,$a1
/*  f17fddc:	01a71821 */ 	addu	$v1,$t5,$a3
/*  f17fde0:	308e0002 */ 	andi	$t6,$a0,0x2
/*  f17fde4:	11c000a0 */ 	beqz	$t6,.NB0f180068
/*  f17fde8:	afa30020 */ 	sw	$v1,0x20($sp)
/*  f17fdec:	308f0200 */ 	andi	$t7,$a0,0x200
/*  f17fdf0:	11e0009d */ 	beqz	$t7,.NB0f180068
/*  f17fdf4:	28610002 */ 	slti	$at,$v1,0x2
/*  f17fdf8:	1420009b */ 	bnez	$at,.NB0f180068
/*  f17fdfc:	02001025 */ 	or	$v0,$s0,$zero
/*  f17fe00:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f17fe04:	8d09028c */ 	lw	$t1,0x28c($t0)
/*  f17fe08:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17fe0c:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f17fe10:	3c0aba00 */ 	lui	$t2,0xba00
/*  f17fe14:	354a0c02 */ 	ori	$t2,$t2,0xc02
/*  f17fe18:	8f270004 */ 	lw	$a3,0x4($t9)
/*  f17fe1c:	afa90024 */ 	sw	$t1,0x24($sp)
/*  f17fe20:	02001825 */ 	or	$v1,$s0,$zero
/*  f17fe24:	3c0bba00 */ 	lui	$t3,0xba00
/*  f17fe28:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f17fe2c:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f17fe30:	356b0602 */ 	ori	$t3,$t3,0x602
/*  f17fe34:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17fe38:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f17fe3c:	240c00c0 */ 	addiu	$t4,$zero,0xc0
/*  f17fe40:	02002025 */ 	or	$a0,$s0,$zero
/*  f17fe44:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f17fe48:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17fe4c:	3c0db600 */ 	lui	$t5,0xb600
/*  f17fe50:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f17fe54:	02002825 */ 	or	$a1,$s0,$zero
/*  f17fe58:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f17fe5c:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f17fe60:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17fe64:	3c0fe700 */ 	lui	$t7,0xe700
/*  f17fe68:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f17fe6c:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f17fe70:	02003025 */ 	or	$a2,$s0,$zero
/*  f17fe74:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17fe78:	3c18ba00 */ 	lui	$t8,0xba00
/*  f17fe7c:	37181301 */ 	ori	$t8,$t8,0x1301
/*  f17fe80:	02001025 */ 	or	$v0,$s0,$zero
/*  f17fe84:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f17fe88:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f17fe8c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17fe90:	3c19ba00 */ 	lui	$t9,0xba00
/*  f17fe94:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f17fe98:	3c090030 */ 	lui	$t1,0x30
/*  f17fe9c:	02001825 */ 	or	$v1,$s0,$zero
/*  f17fea0:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f17fea4:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f17fea8:	3c0b0f0a */ 	lui	$t3,0xf0a
/*  f17feac:	3c0ab900 */ 	lui	$t2,0xb900
/*  f17feb0:	354a031d */ 	ori	$t2,$t2,0x31d
/*  f17feb4:	356b4000 */ 	ori	$t3,$t3,0x4000
/*  f17feb8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17febc:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f17fec0:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f17fec4:	02002825 */ 	or	$a1,$s0,$zero
/*  f17fec8:	3c0cba00 */ 	lui	$t4,0xba00
/*  f17fecc:	358c1701 */ 	ori	$t4,$t4,0x1701
/*  f17fed0:	3c0d0080 */ 	lui	$t5,0x80
/*  f17fed4:	acad0004 */ 	sw	$t5,0x4($a1)
/*  f17fed8:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f17fedc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17fee0:	0fc622ca */ 	jal	radarGetTeamIndex
/*  f17fee4:	90e40125 */ 	lbu	$a0,0x125($a3)
/*  f17fee8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f17feec:	3c048009 */ 	lui	$a0,0x8009
/*  f17fef0:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f17fef4:	8c84a464 */ 	lw	$a0,-0x5b9c($a0)
/*  f17fef8:	02001825 */ 	or	$v1,$s0,$zero
/*  f17fefc:	3c0ff700 */ 	lui	$t7,0xf700
/*  f17ff00:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f17ff04:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17ff08:	0c002fb5 */ 	jal	viGetViewLeft
/*  f17ff0c:	ac640004 */ 	sw	$a0,0x4($v1)
/*  f17ff10:	0c002f97 */ 	jal	viGetViewWidth
/*  f17ff14:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f17ff18:	8fa70034 */ 	lw	$a3,0x34($sp)
/*  f17ff1c:	00472821 */ 	addu	$a1,$v0,$a3
/*  f17ff20:	0c002fb9 */ 	jal	viGetViewTop
/*  f17ff24:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f17ff28:	0c002f9b */ 	jal	viGetViewHeight
/*  f17ff2c:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f17ff30:	8fb80020 */ 	lw	$t8,0x20($sp)
/*  f17ff34:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f17ff38:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f17ff3c:	2b010003 */ 	slti	$at,$t8,0x3
/*  f17ff40:	14200026 */ 	bnez	$at,.NB0f17ffdc
/*  f17ff44:	8fa70034 */ 	lw	$a3,0x34($sp)
/*  f17ff48:	8fb90024 */ 	lw	$t9,0x24($sp)
/*  f17ff4c:	30c303ff */ 	andi	$v1,$a2,0x3ff
/*  f17ff50:	00035080 */ 	sll	$t2,$v1,0x2
/*  f17ff54:	2b210002 */ 	slti	$at,$t9,0x2
/*  f17ff58:	10200013 */ 	beqz	$at,.NB0f17ffa8
/*  f17ff5c:	24abffff */ 	addiu	$t3,$a1,-1
/*  f17ff60:	00462021 */ 	addu	$a0,$v0,$a2
/*  f17ff64:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f17ff68:	24abffff */ 	addiu	$t3,$a1,-1
/*  f17ff6c:	316c03ff */ 	andi	$t4,$t3,0x3ff
/*  f17ff70:	308903ff */ 	andi	$t1,$a0,0x3ff
/*  f17ff74:	00095080 */ 	sll	$t2,$t1,0x2
/*  f17ff78:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f17ff7c:	3c01f600 */ 	lui	$at,0xf600
/*  f17ff80:	30f803ff */ 	andi	$t8,$a3,0x3ff
/*  f17ff84:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f17ff88:	01a17025 */ 	or	$t6,$t5,$at
/*  f17ff8c:	02001825 */ 	or	$v1,$s0,$zero
/*  f17ff90:	01ca7825 */ 	or	$t7,$t6,$t2
/*  f17ff94:	032a4825 */ 	or	$t1,$t9,$t2
/*  f17ff98:	ac690004 */ 	sw	$t1,0x4($v1)
/*  f17ff9c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f17ffa0:	10000031 */ 	beqz	$zero,.NB0f180068
/*  f17ffa4:	26100008 */ 	addiu	$s0,$s0,0x8
.NB0f17ffa8:
/*  f17ffa8:	316c03ff */ 	andi	$t4,$t3,0x3ff
/*  f17ffac:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f17ffb0:	3c01f600 */ 	lui	$at,0xf600
/*  f17ffb4:	30f803ff */ 	andi	$t8,$a3,0x3ff
/*  f17ffb8:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f17ffbc:	01a17025 */ 	or	$t6,$t5,$at
/*  f17ffc0:	02001025 */ 	or	$v0,$s0,$zero
/*  f17ffc4:	01ca7825 */ 	or	$t7,$t6,$t2
/*  f17ffc8:	032a4825 */ 	or	$t1,$t9,$t2
/*  f17ffcc:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f17ffd0:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f17ffd4:	10000024 */ 	beqz	$zero,.NB0f180068
/*  f17ffd8:	26100008 */ 	addiu	$s0,$s0,0x8
.NB0f17ffdc:
/*  f17ffdc:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f17ffe0:	30c303ff */ 	andi	$v1,$a2,0x3ff
/*  f17ffe4:	00036080 */ 	sll	$t4,$v1,0x2
/*  f17ffe8:	15400013 */ 	bnez	$t2,.NB0f180038
/*  f17ffec:	24adffff */ 	addiu	$t5,$a1,-1
/*  f17fff0:	00462021 */ 	addu	$a0,$v0,$a2
/*  f17fff4:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f17fff8:	24adffff */ 	addiu	$t5,$a1,-1
/*  f17fffc:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f180000:	308b03ff */ 	andi	$t3,$a0,0x3ff
/*  f180004:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f180008:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f18000c:	3c01f600 */ 	lui	$at,0xf600
/*  f180010:	30e903ff */ 	andi	$t1,$a3,0x3ff
/*  f180014:	00095380 */ 	sll	$t2,$t1,0xe
/*  f180018:	01e1c025 */ 	or	$t8,$t7,$at
/*  f18001c:	02001825 */ 	or	$v1,$s0,$zero
/*  f180020:	030cc825 */ 	or	$t9,$t8,$t4
/*  f180024:	014c5825 */ 	or	$t3,$t2,$t4
/*  f180028:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f18002c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f180030:	1000000d */ 	beqz	$zero,.NB0f180068
/*  f180034:	26100008 */ 	addiu	$s0,$s0,0x8
.NB0f180038:
/*  f180038:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18003c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f180040:	02001025 */ 	or	$v0,$s0,$zero
/*  f180044:	3c01f600 */ 	lui	$at,0xf600
/*  f180048:	30e903ff */ 	andi	$t1,$a3,0x3ff
/*  f18004c:	00095380 */ 	sll	$t2,$t1,0xe
/*  f180050:	01e1c025 */ 	or	$t8,$t7,$at
/*  f180054:	030cc825 */ 	or	$t9,$t8,$t4
/*  f180058:	014c5825 */ 	or	$t3,$t2,$t4
/*  f18005c:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f180060:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f180064:	26100008 */ 	addiu	$s0,$s0,0x8
.NB0f180068:
/*  f180068:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f18006c:	02001025 */ 	or	$v0,$s0,$zero
/*  f180070:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f180074:	03e00008 */ 	jr	$ra
/*  f180078:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
#endif

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

f32 scenarioChooseSpawnLocation(f32 arg0, struct coord *pos, s16 *rooms, struct prop *prop)
{
	f32 result;

	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].spawnfunc &&
			g_MpScenarios[g_MpSetup.scenario].spawnfunc(arg0, pos, rooms, prop, &result)) {
		return result;
	}

	return playerChooseGeneralSpawnLocation(arg0, pos, rooms, prop);
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

struct menuitem g_MpScenarioMenuItems[] = {
	 { MENUITEMTYPE_LIST,        0, 0x00020040, 0x00000078, 0x0000004d, menuhandler00185068 },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpScenarioMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_243, // "Scenario"
	g_MpScenarioMenuItems,
	NULL,
	0x00000011,
	NULL,
};

struct menuitem g_MpQuickTeamScenarioMenuItems[] = {
	 { MENUITEMTYPE_LIST,        1, 0x00020040, 0x00000078, 0x0000004d, menuhandler00185068 },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpQuickTeamScenarioMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_243, // "Scenario"
	g_MpQuickTeamScenarioMenuItems,
	NULL,
	0x00000011,
	NULL,
};

u32 var800871fc = 0x01000003;
u32 var80087200 = 0x0020ffff;
u32 var80087204 = 0x00000000;
u32 var80087208 = 0x00000000;
u32 var8008720c = 0x00000000;
u32 var80087210 = 0x00000000;
u32 var80087214 = 0x00000000;
u32 var80087218 = 0x3f800000;
u32 var8008721c = 0x00000000;
u32 var80087220 = 0x00000000;
u32 var80087224 = 0x00000000;
u32 var80087228 = 0x3f800000;
u32 var8008722c = 0x00000000;
u32 var80087230 = 0x00000000;
u32 var80087234 = 0x00000000;
u32 var80087238 = 0x3f800000;
u32 var8008723c = 0x00000000;
u32 var80087240 = 0x00000000;
u32 var80087244 = 0x00000000;
u32 var80087248 = 0x000003e8;
u32 var8008724c = 0xffffff00;
u32 var80087250 = 0xffffff00;
u32 var80087254 = 0x0fff0000;
u32 var80087258 = 0x00000000;
u32 var8008725c = 0x00000000;

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
/*  f186690:	0fc1812f */ 	jal	propActivate
/*  f186694:	8da40014 */ 	lw	$a0,0x14($t5)
/*  f186698:	8fb90018 */ 	lw	$t9,0x18($sp)
/*  f18669c:	0fc180bc */ 	jal	propEnable
/*  f1866a0:	8f240014 */ 	lw	$a0,0x14($t9)
/*  f1866a4:	8fb80018 */ 	lw	$t8,0x18($sp)
/*  f1866a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1866ac:	8f020014 */ 	lw	$v0,0x14($t8)
/*  f1866b0:	03e00008 */ 	jr	$ra
/*  f1866b4:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

void mpCreateScenarioHudmsg(s32 playernum, char *message)
{
	if (playernum >= 0 && playernum < PLAYERCOUNT()) {
		s32 prevplayernum = g_Vars.currentplayernum;

		setCurrentPlayerNum(playernum);
		hudmsgCreateWithFlags(message, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
		setCurrentPlayerNum(prevplayernum);
	}
}

bool mpChrsAreSameTeam(s32 arg0, s32 arg1)
{
	struct mpchr *achr;
	struct mpchr *bchr;

	if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) && arg0 >= 0 && arg1 >= 0) {
		s32 a = func0f18d074(arg0);
		s32 b = func0f18d074(arg1);

		if (a >= 0 && b >= 0) {
			if (a < 4) {
				achr = &g_MpPlayers[a].base;
			} else {
				achr = &g_MpSimulants[a - 4].base;
			}

			if (b < 4) {
				bchr = &g_MpPlayers[b].base;
			} else {
				bchr = &g_MpSimulants[b - 4].base;
			}

			return (achr->team == bchr->team) ? true : false;
		}
	}

	return false;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel chrGiveBriefcase
/*  f18789c:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f1878a0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1878a4:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f1878a8:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f1878ac:	afa40128 */ 	sw	$a0,0x128($sp)
/*  f1878b0:	afa5012c */ 	sw	$a1,0x12c($sp)
/*  f1878b4:	3c03800b */ 	lui	$v1,0x800b
/*  f1878b8:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f1878bc:	9063d138 */ 	lbu	$v1,-0x2ec8($v1)
/*  f1878c0:	24010001 */ 	li	$at,0x1
/*  f1878c4:	afa20124 */ 	sw	$v0,0x124($sp)
/*  f1878c8:	146100a5 */ 	bne	$v1,$at,.PF0f187b60
/*  f1878cc:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f1878d0:	8c98001c */ 	lw	$t8,0x1c($a0)
/*  f1878d4:	3c01800b */ 	lui	$at,0x800b
/*  f1878d8:	3c11800a */ 	lui	$s1,0x800a
/*  f1878dc:	ac38c6b4 */ 	sw	$t8,-0x394c($at)
/*  f1878e0:	8c9902d4 */ 	lw	$t9,0x2d4($a0)
/*  f1878e4:	2631a510 */ 	addiu	$s1,$s1,-23280
/*  f1878e8:	53200017 */ 	beqzl	$t9,.PF0f187948
/*  f1878ec:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f1878f0:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f1878f4:	00000000 */ 	nop
/*  f1878f8:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1878fc:	3c0b800b */ 	lui	$t3,0x800b
/*  f187900:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f187904:	8d6bcaa0 */ 	lw	$t3,-0x3560($t3)
/*  f187908:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f18790c:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f187910:	afab0050 */ 	sw	$t3,0x50($sp)
/*  f187914:	0fc21f5f */ 	jal	propPlayPickupSound
/*  f187918:	9185005c */ 	lbu	$a1,0x5c($t4)
/*  f18791c:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f187920:	24050057 */ 	li	$a1,0x57
/*  f187924:	8c8302d4 */ 	lw	$v1,0x2d4($a0)
/*  f187928:	906e009c */ 	lbu	$t6,0x9c($v1)
/*  f18792c:	35d80080 */ 	ori	$t8,$t6,0x80
/*  f187930:	0fc663e3 */ 	jal	aibotGiveSingleWeapon
/*  f187934:	a078009c */ 	sb	$t8,0x9c($v1)
/*  f187938:	3c11800a */ 	lui	$s1,0x800a
/*  f18793c:	10000020 */ 	b	.PF0f1879c0
/*  f187940:	2631a510 */ 	addiu	$s1,$s1,-23280
/*  f187944:	8e39028c */ 	lw	$t9,0x28c($s1)
.PF0f187948:
/*  f187948:	3c0c800b */ 	lui	$t4,0x800b
/*  f18794c:	258ccd58 */ 	addiu	$t4,$t4,-12968
/*  f187950:	001979c0 */ 	sll	$t7,$t9,0x7
/*  f187954:	022f5021 */ 	addu	$t2,$s1,$t7
/*  f187958:	8d4200e4 */ 	lw	$v0,0xe4($t2)
/*  f18795c:	3c19800b */ 	lui	$t9,0x800b
/*  f187960:	2739cad8 */ 	addiu	$t9,$t9,-13608
/*  f187964:	28410004 */ 	slti	$at,$v0,0x4
/*  f187968:	10200007 */ 	beqz	$at,.PF0f187988
/*  f18796c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f187970:	00025880 */ 	sll	$t3,$v0,0x2
/*  f187974:	01625821 */ 	addu	$t3,$t3,$v0
/*  f187978:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f18797c:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f187980:	10000008 */ 	b	.PF0f1879a4
/*  f187984:	afad0050 */ 	sw	$t5,0x50($sp)
.PF0f187988:
/*  f187988:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f18798c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f187990:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f187994:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f187998:	25d8fed0 */ 	addiu	$t8,$t6,-304
/*  f18799c:	03197821 */ 	addu	$t7,$t8,$t9
/*  f1879a0:	afaf0050 */ 	sw	$t7,0x50($sp)
.PF0f1879a4:
/*  f1879a4:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f1879a8:	24040057 */ 	li	$a0,0x57
/*  f1879ac:	24040057 */ 	li	$a0,0x57
/*  f1879b0:	0fc221bd */ 	jal	currentPlayerQueuePickupWeaponHudmsg
/*  f1879b4:	00002825 */ 	move	$a1,$zero
/*  f1879b8:	0fc21fa0 */ 	jal	weaponPlayPickupSound
/*  f1879bc:	24040057 */ 	li	$a0,0x57
.PF0f1879c0:
/*  f1879c0:	0fc5bdaa */ 	jal	langGet
/*  f1879c4:	24045401 */ 	li	$a0,0x5401
/*  f1879c8:	24040057 */ 	li	$a0,0x57
/*  f1879cc:	0fc28941 */ 	jal	bgunGetShortName
/*  f1879d0:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f1879d4:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1879d8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f1879dc:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f1879e0:	0c004d11 */ 	jal	sprintf
/*  f1879e4:	00403825 */ 	move	$a3,$v0
/*  f1879e8:	8e29006c */ 	lw	$t1,0x6c($s1)
/*  f1879ec:	8e2a028c */ 	lw	$t2,0x28c($s1)
/*  f1879f0:	00008025 */ 	move	$s0,$zero
/*  f1879f4:	11200003 */ 	beqz	$t1,.PF0f187a04
/*  f1879f8:	afaa0118 */ 	sw	$t2,0x118($sp)
/*  f1879fc:	10000002 */ 	b	.PF0f187a08
/*  f187a00:	24040001 */ 	li	$a0,0x1
.PF0f187a04:
/*  f187a04:	00002025 */ 	move	$a0,$zero
.PF0f187a08:
/*  f187a08:	8e280068 */ 	lw	$t0,0x68($s1)
/*  f187a0c:	00001825 */ 	move	$v1,$zero
/*  f187a10:	00002825 */ 	move	$a1,$zero
/*  f187a14:	11000003 */ 	beqz	$t0,.PF0f187a24
/*  f187a18:	00001025 */ 	move	$v0,$zero
/*  f187a1c:	10000001 */ 	b	.PF0f187a24
/*  f187a20:	24030001 */ 	li	$v1,0x1
.PF0f187a24:
/*  f187a24:	8e270064 */ 	lw	$a3,0x64($s1)
/*  f187a28:	10e00003 */ 	beqz	$a3,.PF0f187a38
/*  f187a2c:	00000000 */ 	nop
/*  f187a30:	10000001 */ 	b	.PF0f187a38
/*  f187a34:	24050001 */ 	li	$a1,0x1
.PF0f187a38:
/*  f187a38:	8e260070 */ 	lw	$a2,0x70($s1)
/*  f187a3c:	10c00003 */ 	beqz	$a2,.PF0f187a4c
/*  f187a40:	00000000 */ 	nop
/*  f187a44:	10000001 */ 	b	.PF0f187a4c
/*  f187a48:	24020001 */ 	li	$v0,0x1
.PF0f187a4c:
/*  f187a4c:	00455821 */ 	addu	$t3,$v0,$a1
/*  f187a50:	01636021 */ 	addu	$t4,$t3,$v1
/*  f187a54:	01846821 */ 	addu	$t5,$t4,$a0
/*  f187a58:	19a0002d */ 	blez	$t5,.PF0f187b10
/*  f187a5c:	00000000 */ 	nop
/*  f187a60:	8fae0128 */ 	lw	$t6,0x128($sp)
.PF0f187a64:
/*  f187a64:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f187a68:	8dd802d4 */ 	lw	$t8,0x2d4($t6)
/*  f187a6c:	17000003 */ 	bnez	$t8,.PF0f187a7c
/*  f187a70:	00000000 */ 	nop
/*  f187a74:	1219000f */ 	beq	$s0,$t9,.PF0f187ab4
/*  f187a78:	00000000 */ 	nop
.PF0f187a7c:
/*  f187a7c:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f187a80:	02002025 */ 	move	$a0,$s0
/*  f187a84:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f187a88:	24050009 */ 	li	$a1,0x9
/*  f187a8c:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f187a90:	24060001 */ 	li	$a2,0x1
/*  f187a94:	3c09800a */ 	lui	$t1,0x800a
/*  f187a98:	3c08800a */ 	lui	$t0,0x800a
/*  f187a9c:	3c07800a */ 	lui	$a3,0x800a
/*  f187aa0:	3c06800a */ 	lui	$a2,0x800a
/*  f187aa4:	8cc6a580 */ 	lw	$a2,-0x5a80($a2)
/*  f187aa8:	8ce7a574 */ 	lw	$a3,-0x5a8c($a3)
/*  f187aac:	8d08a578 */ 	lw	$t0,-0x5a88($t0)
/*  f187ab0:	8d29a57c */ 	lw	$t1,-0x5a84($t1)
.PF0f187ab4:
/*  f187ab4:	11200003 */ 	beqz	$t1,.PF0f187ac4
/*  f187ab8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f187abc:	10000002 */ 	b	.PF0f187ac8
/*  f187ac0:	24040001 */ 	li	$a0,0x1
.PF0f187ac4:
/*  f187ac4:	00002025 */ 	move	$a0,$zero
.PF0f187ac8:
/*  f187ac8:	11000003 */ 	beqz	$t0,.PF0f187ad8
/*  f187acc:	00001825 */ 	move	$v1,$zero
/*  f187ad0:	10000001 */ 	b	.PF0f187ad8
/*  f187ad4:	24030001 */ 	li	$v1,0x1
.PF0f187ad8:
/*  f187ad8:	10e00003 */ 	beqz	$a3,.PF0f187ae8
/*  f187adc:	00002825 */ 	move	$a1,$zero
/*  f187ae0:	10000001 */ 	b	.PF0f187ae8
/*  f187ae4:	24050001 */ 	li	$a1,0x1
.PF0f187ae8:
/*  f187ae8:	10c00003 */ 	beqz	$a2,.PF0f187af8
/*  f187aec:	00001025 */ 	move	$v0,$zero
/*  f187af0:	10000001 */ 	b	.PF0f187af8
/*  f187af4:	24020001 */ 	li	$v0,0x1
.PF0f187af8:
/*  f187af8:	00457821 */ 	addu	$t7,$v0,$a1
/*  f187afc:	01e35021 */ 	addu	$t2,$t7,$v1
/*  f187b00:	01445821 */ 	addu	$t3,$t2,$a0
/*  f187b04:	020b082a */ 	slt	$at,$s0,$t3
/*  f187b08:	5420ffd6 */ 	bnezl	$at,.PF0f187a64
/*  f187b0c:	8fae0128 */ 	lw	$t6,0x128($sp)
.PF0f187b10:
/*  f187b10:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f187b14:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f187b18:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f187b1c:	8fa30124 */ 	lw	$v1,0x124($sp)
/*  f187b20:	8fa40124 */ 	lw	$a0,0x124($sp)
/*  f187b24:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
/*  f187b28:	51a00007 */ 	beqzl	$t5,.PF0f187b48
/*  f187b2c:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f187b30:	8c6e0040 */ 	lw	$t6,0x40($v1)
/*  f187b34:	00001025 */ 	move	$v0,$zero
/*  f187b38:	35d80004 */ 	ori	$t8,$t6,0x4
/*  f187b3c:	100001b6 */ 	b	.PF0f188218
/*  f187b40:	ac780040 */ 	sw	$t8,0x40($v1)
/*  f187b44:	90860002 */ 	lbu	$a2,0x2($a0)
.PF0f187b48:
/*  f187b48:	00002825 */ 	move	$a1,$zero
/*  f187b4c:	30cf0004 */ 	andi	$t7,$a2,0x4
/*  f187b50:	0fc1abed */ 	jal	objRemove2
/*  f187b54:	01e03025 */ 	move	$a2,$t7
/*  f187b58:	100001af */ 	b	.PF0f188218
/*  f187b5c:	24020001 */ 	li	$v0,0x1
.PF0f187b60:
/*  f187b60:	24010005 */ 	li	$at,0x5
/*  f187b64:	146101a6 */ 	bne	$v1,$at,.PF0f188200
/*  f187b68:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f187b6c:	8faa0128 */ 	lw	$t2,0x128($sp)
/*  f187b70:	3c11800a */ 	lui	$s1,0x800a
/*  f187b74:	2631a510 */ 	addiu	$s1,$s1,-23280
/*  f187b78:	8d4302d4 */ 	lw	$v1,0x2d4($t2)
/*  f187b7c:	5060000e */ 	beqzl	$v1,.PF0f187bb8
/*  f187b80:	8e2e028c */ 	lw	$t6,0x28c($s1)
/*  f187b84:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f187b88:	01402025 */ 	move	$a0,$t2
/*  f187b8c:	00025880 */ 	sll	$t3,$v0,0x2
/*  f187b90:	3c0c800b */ 	lui	$t4,0x800b
/*  f187b94:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f187b98:	8d8ccaa0 */ 	lw	$t4,-0x3560($t4)
/*  f187b9c:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f187ba0:	3c11800a */ 	lui	$s1,0x800a
/*  f187ba4:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f187ba8:	2631a510 */ 	addiu	$s1,$s1,-23280
/*  f187bac:	10000019 */ 	b	.PF0f187c14
/*  f187bb0:	8da302d4 */ 	lw	$v1,0x2d4($t5)
/*  f187bb4:	8e2e028c */ 	lw	$t6,0x28c($s1)
.PF0f187bb8:
/*  f187bb8:	3c0a800b */ 	lui	$t2,0x800b
/*  f187bbc:	254acd58 */ 	addiu	$t2,$t2,-12968
/*  f187bc0:	000ec1c0 */ 	sll	$t8,$t6,0x7
/*  f187bc4:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f187bc8:	8f2200e4 */ 	lw	$v0,0xe4($t9)
/*  f187bcc:	3c0e800b */ 	lui	$t6,0x800b
/*  f187bd0:	25cecad8 */ 	addiu	$t6,$t6,-13608
/*  f187bd4:	28410004 */ 	slti	$at,$v0,0x4
/*  f187bd8:	10200007 */ 	beqz	$at,.PF0f187bf8
/*  f187bdc:	00026080 */ 	sll	$t4,$v0,0x2
/*  f187be0:	00027880 */ 	sll	$t7,$v0,0x2
/*  f187be4:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f187be8:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f187bec:	01ea5821 */ 	addu	$t3,$t7,$t2
/*  f187bf0:	10000008 */ 	b	.PF0f187c14
/*  f187bf4:	afab0050 */ 	sw	$t3,0x50($sp)
.PF0f187bf8:
/*  f187bf8:	01826021 */ 	addu	$t4,$t4,$v0
/*  f187bfc:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f187c00:	01826023 */ 	subu	$t4,$t4,$v0
/*  f187c04:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f187c08:	258dfed0 */ 	addiu	$t5,$t4,-304
/*  f187c0c:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f187c10:	afb80050 */ 	sw	$t8,0x50($sp)
.PF0f187c14:
/*  f187c14:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f187c18:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f187c1c:	932f0011 */ 	lbu	$t7,0x11($t9)
/*  f187c20:	854b0062 */ 	lh	$t3,0x62($t2)
/*  f187c24:	15eb00bc */ 	bne	$t7,$t3,.PF0f187f18
/*  f187c28:	00000000 */ 	nop
/*  f187c2c:	10600005 */ 	beqz	$v1,.PF0f187c44
/*  f187c30:	00000000 */ 	nop
/*  f187c34:	8c6c009c */ 	lw	$t4,0x9c($v1)
/*  f187c38:	000c7040 */ 	sll	$t6,$t4,0x1
/*  f187c3c:	05c20008 */ 	bltzl	$t6,.PF0f187c60
/*  f187c40:	8fb80050 */ 	lw	$t8,0x50($sp)
.PF0f187c44:
/*  f187c44:	546000ad */ 	bnezl	$v1,.PF0f187efc
/*  f187c48:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f187c4c:	0fc44cc9 */ 	jal	invHasBriefcase
/*  f187c50:	00000000 */ 	nop
/*  f187c54:	504000a9 */ 	beqzl	$v0,.PF0f187efc
/*  f187c58:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f187c5c:	8fb80050 */ 	lw	$t8,0x50($sp)
.PF0f187c60:
/*  f187c60:	3c02800b */ 	lui	$v0,0x800b
/*  f187c64:	2442c6b0 */ 	addiu	$v0,$v0,-14672
/*  f187c68:	8719003e */ 	lh	$t9,0x3e($t8)
/*  f187c6c:	00008025 */ 	move	$s0,$zero
/*  f187c70:	272a0001 */ 	addiu	$t2,$t9,0x1
/*  f187c74:	a70a003e */ 	sh	$t2,0x3e($t8)
/*  f187c78:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f187c7c:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f187c80:	8de3001c */ 	lw	$v1,0x1c($t7)
.PF0f187c84:
/*  f187c84:	8c4b0058 */ 	lw	$t3,0x58($v0)
/*  f187c88:	506b0006 */ 	beql	$v1,$t3,.PF0f187ca4
/*  f187c8c:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
/*  f187c90:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f187c94:	2a010004 */ 	slti	$at,$s0,0x4
/*  f187c98:	1420fffa */ 	bnez	$at,.PF0f187c84
/*  f187c9c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f187ca0:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
.PF0f187ca4:
/*  f187ca4:	11a00009 */ 	beqz	$t5,.PF0f187ccc
/*  f187ca8:	01802025 */ 	move	$a0,$t4
/*  f187cac:	0fc66aa1 */ 	jal	func0f199984
/*  f187cb0:	24050057 */ 	li	$a1,0x57
/*  f187cb4:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f187cb8:	8dc302d4 */ 	lw	$v1,0x2d4($t6)
/*  f187cbc:	9079009c */ 	lbu	$t9,0x9c($v1)
/*  f187cc0:	332affbf */ 	andi	$t2,$t9,0xffbf
/*  f187cc4:	10000014 */ 	b	.PF0f187d18
/*  f187cc8:	a06a009c */ 	sb	$t2,0x9c($v1)
.PF0f187ccc:
/*  f187ccc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f187cd0:	44812000 */ 	mtc1	$at,$f4
/*  f187cd4:	3c048009 */ 	lui	$a0,0x8009
/*  f187cd8:	2418ffff */ 	li	$t8,-1
/*  f187cdc:	240fffff */ 	li	$t7,-1
/*  f187ce0:	240bffff */ 	li	$t3,-1
/*  f187ce4:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f187ce8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f187cec:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f187cf0:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f187cf4:	240505b8 */ 	li	$a1,0x5b8
/*  f187cf8:	00003025 */ 	move	$a2,$zero
/*  f187cfc:	2407ffff */ 	li	$a3,-1
/*  f187d00:	0c0041a0 */ 	jal	sndStart
/*  f187d04:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f187d08:	0fc24454 */ 	jal	func0f091250
/*  f187d0c:	24040057 */ 	li	$a0,0x57
/*  f187d10:	0fc44a61 */ 	jal	invRemoveItemByNum
/*  f187d14:	24040057 */ 	li	$a0,0x57
.PF0f187d18:
/*  f187d18:	0fc5bdaa */ 	jal	langGet
/*  f187d1c:	24045405 */ 	li	$a0,0x5405
/*  f187d20:	00106880 */ 	sll	$t5,$s0,0x2
/*  f187d24:	01b06823 */ 	subu	$t5,$t5,$s0
/*  f187d28:	3c0c800b */ 	lui	$t4,0x800b
/*  f187d2c:	258cd150 */ 	addiu	$t4,$t4,-11952
/*  f187d30:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f187d34:	01ac3021 */ 	addu	$a2,$t5,$t4
/*  f187d38:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f187d3c:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f187d40:	0c004d11 */ 	jal	sprintf
/*  f187d44:	00402825 */ 	move	$a1,$v0
/*  f187d48:	0fc5bdaa */ 	jal	langGet
/*  f187d4c:	24045406 */ 	li	$a0,0x5406
/*  f187d50:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187d54:	00402825 */ 	move	$a1,$v0
/*  f187d58:	0c004d11 */ 	jal	sprintf
/*  f187d5c:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187d60:	0fc5bdaa */ 	jal	langGet
/*  f187d64:	24045407 */ 	li	$a0,0x5407
/*  f187d68:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f187d6c:	00402825 */ 	move	$a1,$v0
/*  f187d70:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187d74:	0c004d11 */ 	jal	sprintf
/*  f187d78:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f187d7c:	8e39006c */ 	lw	$t9,0x6c($s1)
/*  f187d80:	8e2e028c */ 	lw	$t6,0x28c($s1)
/*  f187d84:	afb00114 */ 	sw	$s0,0x114($sp)
/*  f187d88:	00008025 */ 	move	$s0,$zero
/*  f187d8c:	13200003 */ 	beqz	$t9,.PF0f187d9c
/*  f187d90:	afae0118 */ 	sw	$t6,0x118($sp)
/*  f187d94:	10000002 */ 	b	.PF0f187da0
/*  f187d98:	24040001 */ 	li	$a0,0x1
.PF0f187d9c:
/*  f187d9c:	00002025 */ 	move	$a0,$zero
.PF0f187da0:
/*  f187da0:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f187da4:	00001825 */ 	move	$v1,$zero
/*  f187da8:	00002825 */ 	move	$a1,$zero
/*  f187dac:	11400003 */ 	beqz	$t2,.PF0f187dbc
/*  f187db0:	00001025 */ 	move	$v0,$zero
/*  f187db4:	10000001 */ 	b	.PF0f187dbc
/*  f187db8:	24030001 */ 	li	$v1,0x1
.PF0f187dbc:
/*  f187dbc:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f187dc0:	13000003 */ 	beqz	$t8,.PF0f187dd0
/*  f187dc4:	00000000 */ 	nop
/*  f187dc8:	10000001 */ 	b	.PF0f187dd0
/*  f187dcc:	24050001 */ 	li	$a1,0x1
.PF0f187dd0:
/*  f187dd0:	8e2f0070 */ 	lw	$t7,0x70($s1)
/*  f187dd4:	11e00003 */ 	beqz	$t7,.PF0f187de4
/*  f187dd8:	00000000 */ 	nop
/*  f187ddc:	10000001 */ 	b	.PF0f187de4
/*  f187de0:	24020001 */ 	li	$v0,0x1
.PF0f187de4:
/*  f187de4:	00455821 */ 	addu	$t3,$v0,$a1
/*  f187de8:	01636821 */ 	addu	$t5,$t3,$v1
/*  f187dec:	01a46021 */ 	addu	$t4,$t5,$a0
/*  f187df0:	1980003f */ 	blez	$t4,.PF0f187ef0
/*  f187df4:	00000000 */ 	nop
.PF0f187df8:
/*  f187df8:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f187dfc:	02002025 */ 	move	$a0,$s0
/*  f187e00:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f187e04:	00107880 */ 	sll	$t7,$s0,0x2
/*  f187e08:	3c0b800b */ 	lui	$t3,0x800b
/*  f187e0c:	8dd902d4 */ 	lw	$t9,0x2d4($t6)
/*  f187e10:	8faa0118 */ 	lw	$t2,0x118($sp)
/*  f187e14:	016f5821 */ 	addu	$t3,$t3,$t7
/*  f187e18:	17200008 */ 	bnez	$t9,.PF0f187e3c
/*  f187e1c:	00000000 */ 	nop
/*  f187e20:	160a0006 */ 	bne	$s0,$t2,.PF0f187e3c
/*  f187e24:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f187e28:	24050009 */ 	li	$a1,0x9
/*  f187e2c:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f187e30:	24060001 */ 	li	$a2,0x1
/*  f187e34:	10000011 */ 	b	.PF0f187e7c
/*  f187e38:	8e2c006c */ 	lw	$t4,0x6c($s1)
.PF0f187e3c:
/*  f187e3c:	8d6bcaa0 */ 	lw	$t3,-0x3560($t3)
/*  f187e40:	8fb80114 */ 	lw	$t8,0x114($sp)
/*  f187e44:	24060001 */ 	li	$a2,0x1
/*  f187e48:	916d0011 */ 	lbu	$t5,0x11($t3)
/*  f187e4c:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f187e50:	24050009 */ 	li	$a1,0x9
/*  f187e54:	170d0006 */ 	bne	$t8,$t5,.PF0f187e70
/*  f187e58:	00000000 */ 	nop
/*  f187e5c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187e60:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f187e64:	24050009 */ 	li	$a1,0x9
/*  f187e68:	10000004 */ 	b	.PF0f187e7c
/*  f187e6c:	8e2c006c */ 	lw	$t4,0x6c($s1)
.PF0f187e70:
/*  f187e70:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f187e74:	24060001 */ 	li	$a2,0x1
/*  f187e78:	8e2c006c */ 	lw	$t4,0x6c($s1)
.PF0f187e7c:
/*  f187e7c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f187e80:	00002025 */ 	move	$a0,$zero
/*  f187e84:	11800003 */ 	beqz	$t4,.PF0f187e94
/*  f187e88:	00001825 */ 	move	$v1,$zero
/*  f187e8c:	10000001 */ 	b	.PF0f187e94
/*  f187e90:	24040001 */ 	li	$a0,0x1
.PF0f187e94:
/*  f187e94:	8e2e0068 */ 	lw	$t6,0x68($s1)
/*  f187e98:	00002825 */ 	move	$a1,$zero
/*  f187e9c:	00001025 */ 	move	$v0,$zero
/*  f187ea0:	11c00003 */ 	beqz	$t6,.PF0f187eb0
/*  f187ea4:	00000000 */ 	nop
/*  f187ea8:	10000001 */ 	b	.PF0f187eb0
/*  f187eac:	24030001 */ 	li	$v1,0x1
.PF0f187eb0:
/*  f187eb0:	8e390064 */ 	lw	$t9,0x64($s1)
/*  f187eb4:	13200003 */ 	beqz	$t9,.PF0f187ec4
/*  f187eb8:	00000000 */ 	nop
/*  f187ebc:	10000001 */ 	b	.PF0f187ec4
/*  f187ec0:	24050001 */ 	li	$a1,0x1
.PF0f187ec4:
/*  f187ec4:	8e2a0070 */ 	lw	$t2,0x70($s1)
/*  f187ec8:	11400003 */ 	beqz	$t2,.PF0f187ed8
/*  f187ecc:	00000000 */ 	nop
/*  f187ed0:	10000001 */ 	b	.PF0f187ed8
/*  f187ed4:	24020001 */ 	li	$v0,0x1
.PF0f187ed8:
/*  f187ed8:	00457821 */ 	addu	$t7,$v0,$a1
/*  f187edc:	01e35821 */ 	addu	$t3,$t7,$v1
/*  f187ee0:	0164c021 */ 	addu	$t8,$t3,$a0
/*  f187ee4:	0218082a */ 	slt	$at,$s0,$t8
/*  f187ee8:	1420ffc3 */ 	bnez	$at,.PF0f187df8
/*  f187eec:	00000000 */ 	nop
.PF0f187ef0:
/*  f187ef0:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f187ef4:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f187ef8:	8fad0128 */ 	lw	$t5,0x128($sp)
.PF0f187efc:
/*  f187efc:	8dac02d4 */ 	lw	$t4,0x2d4($t5)
/*  f187f00:	11800003 */ 	beqz	$t4,.PF0f187f10
/*  f187f04:	00000000 */ 	nop
/*  f187f08:	100000c3 */ 	b	.PF0f188218
/*  f187f0c:	00001025 */ 	move	$v0,$zero
.PF0f187f10:
/*  f187f10:	100000c1 */ 	b	.PF0f188218
/*  f187f14:	00001025 */ 	move	$v0,$zero
.PF0f187f18:
/*  f187f18:	10600005 */ 	beqz	$v1,.PF0f187f30
/*  f187f1c:	00000000 */ 	nop
/*  f187f20:	8c6e009c */ 	lw	$t6,0x9c($v1)
/*  f187f24:	000e5040 */ 	sll	$t2,$t6,0x1
/*  f187f28:	05410008 */ 	bgez	$t2,.PF0f187f4c
/*  f187f2c:	00000000 */ 	nop
.PF0f187f30:
/*  f187f30:	546000ac */ 	bnezl	$v1,.PF0f1881e4
/*  f187f34:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f187f38:	0fc44cc9 */ 	jal	invHasBriefcase
/*  f187f3c:	00000000 */ 	nop
/*  f187f40:	144000a7 */ 	bnez	$v0,.PF0f1881e0
/*  f187f44:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f187f48:	8de302d4 */ 	lw	$v1,0x2d4($t7)
.PF0f187f4c:
/*  f187f4c:	50600009 */ 	beqzl	$v1,.PF0f187f74
/*  f187f50:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f187f54:	9078009c */ 	lbu	$t8,0x9c($v1)
/*  f187f58:	370d0040 */ 	ori	$t5,$t8,0x40
/*  f187f5c:	a06d009c */ 	sb	$t5,0x9c($v1)
/*  f187f60:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f187f64:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f187f68:	0fc21f5f */ 	jal	propPlayPickupSound
/*  f187f6c:	9185005c */ 	lbu	$a1,0x5c($t4)
/*  f187f70:	8faa0120 */ 	lw	$t2,0x120($sp)
.PF0f187f74:
/*  f187f74:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f187f78:	3c01800b */ 	lui	$at,0x800b
/*  f187f7c:	854f0062 */ 	lh	$t7,0x62($t2)
/*  f187f80:	8dd9001c */ 	lw	$t9,0x1c($t6)
/*  f187f84:	24045402 */ 	li	$a0,0x5402
/*  f187f88:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f187f8c:	002b0821 */ 	addu	$at,$at,$t3
/*  f187f90:	0fc5bdaa */ 	jal	langGet
/*  f187f94:	ac39c708 */ 	sw	$t9,-0x38f8($at)
/*  f187f98:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f187f9c:	3c10800b */ 	lui	$s0,0x800b
/*  f187fa0:	2610d150 */ 	addiu	$s0,$s0,-11952
/*  f187fa4:	870d0062 */ 	lh	$t5,0x62($t8)
/*  f187fa8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f187fac:	00402825 */ 	move	$a1,$v0
/*  f187fb0:	000d6080 */ 	sll	$t4,$t5,0x2
/*  f187fb4:	018d6023 */ 	subu	$t4,$t4,$t5
/*  f187fb8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f187fbc:	020c3821 */ 	addu	$a3,$s0,$t4
/*  f187fc0:	0c004d11 */ 	jal	sprintf
/*  f187fc4:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187fc8:	0fc5bdaa */ 	jal	langGet
/*  f187fcc:	24045403 */ 	li	$a0,0x5403
/*  f187fd0:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187fd4:	00402825 */ 	move	$a1,$v0
/*  f187fd8:	0c004d11 */ 	jal	sprintf
/*  f187fdc:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187fe0:	0fc5bdaa */ 	jal	langGet
/*  f187fe4:	24045404 */ 	li	$a0,0x5404
/*  f187fe8:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f187fec:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f187ff0:	00402825 */ 	move	$a1,$v0
/*  f187ff4:	85ca0062 */ 	lh	$t2,0x62($t6)
/*  f187ff8:	000a7880 */ 	sll	$t7,$t2,0x2
/*  f187ffc:	01ea7823 */ 	subu	$t7,$t7,$t2
/*  f188000:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f188004:	0c004d11 */ 	jal	sprintf
/*  f188008:	020f3021 */ 	addu	$a2,$s0,$t7
/*  f18800c:	8e2b006c */ 	lw	$t3,0x6c($s1)
/*  f188010:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f188014:	00008025 */ 	move	$s0,$zero
/*  f188018:	11600003 */ 	beqz	$t3,.PF0f188028
/*  f18801c:	afb90118 */ 	sw	$t9,0x118($sp)
/*  f188020:	10000002 */ 	b	.PF0f18802c
/*  f188024:	24040001 */ 	li	$a0,0x1
.PF0f188028:
/*  f188028:	00002025 */ 	move	$a0,$zero
.PF0f18802c:
/*  f18802c:	8e380068 */ 	lw	$t8,0x68($s1)
/*  f188030:	00001825 */ 	move	$v1,$zero
/*  f188034:	00002825 */ 	move	$a1,$zero
/*  f188038:	13000003 */ 	beqz	$t8,.PF0f188048
/*  f18803c:	00001025 */ 	move	$v0,$zero
/*  f188040:	10000001 */ 	b	.PF0f188048
/*  f188044:	24030001 */ 	li	$v1,0x1
.PF0f188048:
/*  f188048:	8e2d0064 */ 	lw	$t5,0x64($s1)
/*  f18804c:	11a00003 */ 	beqz	$t5,.PF0f18805c
/*  f188050:	00000000 */ 	nop
/*  f188054:	10000001 */ 	b	.PF0f18805c
/*  f188058:	24050001 */ 	li	$a1,0x1
.PF0f18805c:
/*  f18805c:	8e2c0070 */ 	lw	$t4,0x70($s1)
/*  f188060:	11800003 */ 	beqz	$t4,.PF0f188070
/*  f188064:	00000000 */ 	nop
/*  f188068:	10000001 */ 	b	.PF0f188070
/*  f18806c:	24020001 */ 	li	$v0,0x1
.PF0f188070:
/*  f188070:	00457021 */ 	addu	$t6,$v0,$a1
/*  f188074:	01c35021 */ 	addu	$t2,$t6,$v1
/*  f188078:	01447821 */ 	addu	$t7,$t2,$a0
/*  f18807c:	19e0003f */ 	blez	$t7,.PF0f18817c
/*  f188080:	00000000 */ 	nop
.PF0f188084:
/*  f188084:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f188088:	02002025 */ 	move	$a0,$s0
/*  f18808c:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f188090:	00107080 */ 	sll	$t6,$s0,0x2
/*  f188094:	3c0a800b */ 	lui	$t2,0x800b
/*  f188098:	8f2b02d4 */ 	lw	$t3,0x2d4($t9)
/*  f18809c:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f1880a0:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f1880a4:	15600008 */ 	bnez	$t3,.PF0f1880c8
/*  f1880a8:	8fad0120 */ 	lw	$t5,0x120($sp)
/*  f1880ac:	16180006 */ 	bne	$s0,$t8,.PF0f1880c8
/*  f1880b0:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f1880b4:	24050009 */ 	li	$a1,0x9
/*  f1880b8:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f1880bc:	24060001 */ 	li	$a2,0x1
/*  f1880c0:	10000011 */ 	b	.PF0f188108
/*  f1880c4:	8e39006c */ 	lw	$t9,0x6c($s1)
.PF0f1880c8:
/*  f1880c8:	8d4acaa0 */ 	lw	$t2,-0x3560($t2)
/*  f1880cc:	85ac0062 */ 	lh	$t4,0x62($t5)
/*  f1880d0:	24060001 */ 	li	$a2,0x1
/*  f1880d4:	914f0011 */ 	lbu	$t7,0x11($t2)
/*  f1880d8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f1880dc:	24050009 */ 	li	$a1,0x9
/*  f1880e0:	158f0006 */ 	bne	$t4,$t7,.PF0f1880fc
/*  f1880e4:	00000000 */ 	nop
/*  f1880e8:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f1880ec:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f1880f0:	24050009 */ 	li	$a1,0x9
/*  f1880f4:	10000004 */ 	b	.PF0f188108
/*  f1880f8:	8e39006c */ 	lw	$t9,0x6c($s1)
.PF0f1880fc:
/*  f1880fc:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f188100:	24060001 */ 	li	$a2,0x1
/*  f188104:	8e39006c */ 	lw	$t9,0x6c($s1)
.PF0f188108:
/*  f188108:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18810c:	00002025 */ 	move	$a0,$zero
/*  f188110:	13200003 */ 	beqz	$t9,.PF0f188120
/*  f188114:	00001825 */ 	move	$v1,$zero
/*  f188118:	10000001 */ 	b	.PF0f188120
/*  f18811c:	24040001 */ 	li	$a0,0x1
.PF0f188120:
/*  f188120:	8e2b0068 */ 	lw	$t3,0x68($s1)
/*  f188124:	00002825 */ 	move	$a1,$zero
/*  f188128:	00001025 */ 	move	$v0,$zero
/*  f18812c:	11600003 */ 	beqz	$t3,.PF0f18813c
/*  f188130:	00000000 */ 	nop
/*  f188134:	10000001 */ 	b	.PF0f18813c
/*  f188138:	24030001 */ 	li	$v1,0x1
.PF0f18813c:
/*  f18813c:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f188140:	13000003 */ 	beqz	$t8,.PF0f188150
/*  f188144:	00000000 */ 	nop
/*  f188148:	10000001 */ 	b	.PF0f188150
/*  f18814c:	24050001 */ 	li	$a1,0x1
.PF0f188150:
/*  f188150:	8e2d0070 */ 	lw	$t5,0x70($s1)
/*  f188154:	11a00003 */ 	beqz	$t5,.PF0f188164
/*  f188158:	00000000 */ 	nop
/*  f18815c:	10000001 */ 	b	.PF0f188164
/*  f188160:	24020001 */ 	li	$v0,0x1
.PF0f188164:
/*  f188164:	00457021 */ 	addu	$t6,$v0,$a1
/*  f188168:	01c35021 */ 	addu	$t2,$t6,$v1
/*  f18816c:	01446021 */ 	addu	$t4,$t2,$a0
/*  f188170:	020c082a */ 	slt	$at,$s0,$t4
/*  f188174:	1420ffc3 */ 	bnez	$at,.PF0f188084
/*  f188178:	00000000 */ 	nop
.PF0f18817c:
/*  f18817c:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f188180:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f188184:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f188188:	8df902d4 */ 	lw	$t9,0x2d4($t7)
/*  f18818c:	01e02025 */ 	move	$a0,$t7
/*  f188190:	13200009 */ 	beqz	$t9,.PF0f1881b8
/*  f188194:	00000000 */ 	nop
/*  f188198:	0fc663e3 */ 	jal	aibotGiveSingleWeapon
/*  f18819c:	24050057 */ 	li	$a1,0x57
/*  f1881a0:	8fab0124 */ 	lw	$t3,0x124($sp)
/*  f1881a4:	00001025 */ 	move	$v0,$zero
/*  f1881a8:	8d780040 */ 	lw	$t8,0x40($t3)
/*  f1881ac:	370d0004 */ 	ori	$t5,$t8,0x4
/*  f1881b0:	10000019 */ 	b	.PF0f188218
/*  f1881b4:	ad6d0040 */ 	sw	$t5,0x40($t3)
.PF0f1881b8:
/*  f1881b8:	0fc44af4 */ 	jal	invGiveWeaponsByProp
/*  f1881bc:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f1881c0:	8fa40124 */ 	lw	$a0,0x124($sp)
/*  f1881c4:	00002825 */ 	move	$a1,$zero
/*  f1881c8:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f1881cc:	30ca0004 */ 	andi	$t2,$a2,0x4
/*  f1881d0:	0fc1abed */ 	jal	objRemove2
/*  f1881d4:	01403025 */ 	move	$a2,$t2
/*  f1881d8:	1000000f */ 	b	.PF0f188218
/*  f1881dc:	24020001 */ 	li	$v0,0x1
.PF0f1881e0:
/*  f1881e0:	8fac0128 */ 	lw	$t4,0x128($sp)
.PF0f1881e4:
/*  f1881e4:	8d9902d4 */ 	lw	$t9,0x2d4($t4)
/*  f1881e8:	13200003 */ 	beqz	$t9,.PF0f1881f8
/*  f1881ec:	00000000 */ 	nop
/*  f1881f0:	10000009 */ 	b	.PF0f188218
/*  f1881f4:	00001025 */ 	move	$v0,$zero
.PF0f1881f8:
/*  f1881f8:	10000007 */ 	b	.PF0f188218
/*  f1881fc:	00001025 */ 	move	$v0,$zero
.PF0f188200:
/*  f188200:	8df802d4 */ 	lw	$t8,0x2d4($t7)
/*  f188204:	00001025 */ 	move	$v0,$zero
/*  f188208:	13000003 */ 	beqz	$t8,.PF0f188218
/*  f18820c:	00000000 */ 	nop
/*  f188210:	10000001 */ 	b	.PF0f188218
/*  f188214:	00001025 */ 	move	$v0,$zero
.PF0f188218:
/*  f188218:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f18821c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f188220:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f188224:	03e00008 */ 	jr	$ra
/*  f188228:	27bd0128 */ 	addiu	$sp,$sp,0x128
);
#elif VERSION >= VERSION_NTSC_1_0
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
/*  f18692c:	0fc65fa3 */ 	jal	aibotGiveSingleWeapon
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
/*  f1869b4:	0fc21f44 */ 	jal	weaponPlayPickupSound
/*  f1869b8:	24040057 */ 	addiu	$a0,$zero,0x57
.L0f1869bc:
/*  f1869bc:	0fc5b9f1 */ 	jal	langGet
/*  f1869c0:	24045400 */ 	addiu	$a0,$zero,0x5400
/*  f1869c4:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f1869c8:	0fc28874 */ 	jal	bgunGetShortName
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
/*  f186a88:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f186b4c:	0fc1ab4b */ 	jal	objRemove2
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
/*  f186cfc:	0c004241 */ 	jal	sndStart
/*  f186d00:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f186d04:	0fc24494 */ 	jal	func0f091250
/*  f186d08:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d0c:	0fc447a9 */ 	jal	invRemoveItemByNum
/*  f186d10:	24040057 */ 	addiu	$a0,$zero,0x57
.L0f186d14:
/*  f186d14:	0fc5b9f1 */ 	jal	langGet
/*  f186d18:	24045404 */ 	addiu	$a0,$zero,0x5404
/*  f186d1c:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d20:	0fc28874 */ 	jal	bgunGetShortName
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
/*  f186d60:	0fc28874 */ 	jal	bgunGetShortName
/*  f186d64:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186d68:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186d6c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f186d70:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f186d74:	0c004dad */ 	jal	sprintf
/*  f186d78:	00403825 */ 	or	$a3,$v0,$zero
/*  f186d7c:	0fc5b9f1 */ 	jal	langGet
/*  f186d80:	24045406 */ 	addiu	$a0,$zero,0x5406
/*  f186d84:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d88:	0fc28874 */ 	jal	bgunGetShortName
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
/*  f186e58:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f186e8c:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f186e90:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186e94:	10000004 */ 	b	.L0f186ea8
/*  f186e98:	8e2c006c */ 	lw	$t4,0x6c($s1)
.L0f186e9c:
/*  f186e9c:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f186fc8:	0fc28874 */ 	jal	bgunGetShortName
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
/*  f187010:	0fc28874 */ 	jal	bgunGetShortName
/*  f187014:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f187018:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f18701c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187020:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187024:	0c004dad */ 	jal	sprintf
/*  f187028:	00403825 */ 	or	$a3,$v0,$zero
/*  f18702c:	0fc5b9f1 */ 	jal	langGet
/*  f187030:	24045403 */ 	addiu	$a0,$zero,0x5403
/*  f187034:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f187038:	0fc28874 */ 	jal	bgunGetShortName
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
/*  f187114:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f187148:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f18714c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f187150:	10000004 */ 	b	.L0f187164
/*  f187154:	8e39006c */ 	lw	$t9,0x6c($s1)
.L0f187158:
/*  f187158:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
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
/*  f1871f4:	0fc65fa3 */ 	jal	aibotGiveSingleWeapon
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
/*  f18722c:	0fc1ab4b */ 	jal	objRemove2
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
#else
GLOBAL_ASM(
glabel chrGiveBriefcase
/*  f180d00:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f180d04:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f180d08:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f180d0c:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f180d10:	afa40128 */ 	sw	$a0,0x128($sp)
/*  f180d14:	afa5012c */ 	sw	$a1,0x12c($sp)
/*  f180d18:	3c03800b */ 	lui	$v1,0x800b
/*  f180d1c:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f180d20:	90631448 */ 	lbu	$v1,0x1448($v1)
/*  f180d24:	24010001 */ 	addiu	$at,$zero,0x1
/*  f180d28:	afa20124 */ 	sw	$v0,0x124($sp)
/*  f180d2c:	1461009f */ 	bne	$v1,$at,.NB0f180fac
/*  f180d30:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f180d34:	8c98001c */ 	lw	$t8,0x1c($a0)
/*  f180d38:	3c01800b */ 	lui	$at,0x800b
/*  f180d3c:	3c11800a */ 	lui	$s1,0x800a
/*  f180d40:	ac3809c4 */ 	sw	$t8,0x9c4($at)
/*  f180d44:	8c9902d4 */ 	lw	$t9,0x2d4($a0)
/*  f180d48:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f180d4c:	53200017 */ 	beqzl	$t9,.NB0f180dac
/*  f180d50:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f180d54:	0fc61c7f */ 	jal	mpPlayerGetIndex
/*  f180d58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180d5c:	00025080 */ 	sll	$t2,$v0,0x2
/*  f180d60:	3c0b800b */ 	lui	$t3,0x800b
/*  f180d64:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f180d68:	8d6b0db0 */ 	lw	$t3,0xdb0($t3)
/*  f180d6c:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f180d70:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f180d74:	afab0050 */ 	sw	$t3,0x50($sp)
/*  f180d78:	0fc2191a */ 	jal	propPlayPickupSound
/*  f180d7c:	9185005c */ 	lbu	$a1,0x5c($t4)
/*  f180d80:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f180d84:	24050056 */ 	addiu	$a1,$zero,0x56
/*  f180d88:	8c8302d4 */ 	lw	$v1,0x2d4($a0)
/*  f180d8c:	906e009c */ 	lbu	$t6,0x9c($v1)
/*  f180d90:	35d80080 */ 	ori	$t8,$t6,0x80
/*  f180d94:	0fc6479b */ 	jal	aibotGiveSingleWeapon
/*  f180d98:	a078009c */ 	sb	$t8,0x9c($v1)
/*  f180d9c:	3c11800a */ 	lui	$s1,0x800a
/*  f180da0:	10000020 */ 	beqz	$zero,.NB0f180e24
/*  f180da4:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f180da8:	8e39028c */ 	lw	$t9,0x28c($s1)
.NB0f180dac:
/*  f180dac:	3c0c800b */ 	lui	$t4,0x800b
/*  f180db0:	258c1068 */ 	addiu	$t4,$t4,0x1068
/*  f180db4:	001979c0 */ 	sll	$t7,$t9,0x7
/*  f180db8:	022f5021 */ 	addu	$t2,$s1,$t7
/*  f180dbc:	8d4200e4 */ 	lw	$v0,0xe4($t2)
/*  f180dc0:	3c19800b */ 	lui	$t9,0x800b
/*  f180dc4:	27390de8 */ 	addiu	$t9,$t9,0xde8
/*  f180dc8:	28410004 */ 	slti	$at,$v0,0x4
/*  f180dcc:	10200007 */ 	beqz	$at,.NB0f180dec
/*  f180dd0:	00027080 */ 	sll	$t6,$v0,0x2
/*  f180dd4:	00025880 */ 	sll	$t3,$v0,0x2
/*  f180dd8:	01625821 */ 	addu	$t3,$t3,$v0
/*  f180ddc:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f180de0:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f180de4:	10000008 */ 	beqz	$zero,.NB0f180e08
/*  f180de8:	afad0050 */ 	sw	$t5,0x50($sp)
.NB0f180dec:
/*  f180dec:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f180df0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f180df4:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f180df8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f180dfc:	25d8fed0 */ 	addiu	$t8,$t6,-304
/*  f180e00:	03197821 */ 	addu	$t7,$t8,$t9
/*  f180e04:	afaf0050 */ 	sw	$t7,0x50($sp)
.NB0f180e08:
/*  f180e08:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f180e0c:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f180e10:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f180e14:	0fc21c09 */ 	jal	currentPlayerQueuePickupWeaponHudmsg
/*  f180e18:	00002825 */ 	or	$a1,$zero,$zero
/*  f180e1c:	0fc2195b */ 	jal	weaponPlayPickupSound
/*  f180e20:	24040056 */ 	addiu	$a0,$zero,0x56
.NB0f180e24:
/*  f180e24:	0fc5a4dd */ 	jal	langGet
/*  f180e28:	24045400 */ 	addiu	$a0,$zero,0x5400
/*  f180e2c:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f180e30:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f180e34:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f180e38:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f180e3c:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f180e40:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f180e44:	0c004fc1 */ 	jal	sprintf
/*  f180e48:	00403825 */ 	or	$a3,$v0,$zero
/*  f180e4c:	8e29006c */ 	lw	$t1,0x6c($s1)
/*  f180e50:	8e2a028c */ 	lw	$t2,0x28c($s1)
/*  f180e54:	00008025 */ 	or	$s0,$zero,$zero
/*  f180e58:	11200003 */ 	beqz	$t1,.NB0f180e68
/*  f180e5c:	afaa0118 */ 	sw	$t2,0x118($sp)
/*  f180e60:	10000002 */ 	beqz	$zero,.NB0f180e6c
/*  f180e64:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f180e68:
/*  f180e68:	00002025 */ 	or	$a0,$zero,$zero
.NB0f180e6c:
/*  f180e6c:	8e280068 */ 	lw	$t0,0x68($s1)
/*  f180e70:	00001825 */ 	or	$v1,$zero,$zero
/*  f180e74:	00002825 */ 	or	$a1,$zero,$zero
/*  f180e78:	11000003 */ 	beqz	$t0,.NB0f180e88
/*  f180e7c:	00001025 */ 	or	$v0,$zero,$zero
/*  f180e80:	10000001 */ 	beqz	$zero,.NB0f180e88
/*  f180e84:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f180e88:
/*  f180e88:	8e270064 */ 	lw	$a3,0x64($s1)
/*  f180e8c:	10e00003 */ 	beqz	$a3,.NB0f180e9c
/*  f180e90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180e94:	10000001 */ 	beqz	$zero,.NB0f180e9c
/*  f180e98:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f180e9c:
/*  f180e9c:	8e260070 */ 	lw	$a2,0x70($s1)
/*  f180ea0:	10c00003 */ 	beqz	$a2,.NB0f180eb0
/*  f180ea4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180ea8:	10000001 */ 	beqz	$zero,.NB0f180eb0
/*  f180eac:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f180eb0:
/*  f180eb0:	00455821 */ 	addu	$t3,$v0,$a1
/*  f180eb4:	01636021 */ 	addu	$t4,$t3,$v1
/*  f180eb8:	01846821 */ 	addu	$t5,$t4,$a0
/*  f180ebc:	19a0002d */ 	blez	$t5,.NB0f180f74
/*  f180ec0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180ec4:	8fae0128 */ 	lw	$t6,0x128($sp)
.NB0f180ec8:
/*  f180ec8:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f180ecc:	8dd802d4 */ 	lw	$t8,0x2d4($t6)
/*  f180ed0:	17000003 */ 	bnez	$t8,.NB0f180ee0
/*  f180ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180ed8:	1219000f */ 	beq	$s0,$t9,.NB0f180f18
/*  f180edc:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f180ee0:
/*  f180ee0:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f180ee4:	02002025 */ 	or	$a0,$s0,$zero
/*  f180ee8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f180eec:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f180ef0:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f180ef4:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f180ef8:	3c09800a */ 	lui	$t1,0x800a
/*  f180efc:	3c08800a */ 	lui	$t0,0x800a
/*  f180f00:	3c07800a */ 	lui	$a3,0x800a
/*  f180f04:	3c06800a */ 	lui	$a2,0x800a
/*  f180f08:	8cc6e730 */ 	lw	$a2,-0x18d0($a2)
/*  f180f0c:	8ce7e724 */ 	lw	$a3,-0x18dc($a3)
/*  f180f10:	8d08e728 */ 	lw	$t0,-0x18d8($t0)
/*  f180f14:	8d29e72c */ 	lw	$t1,-0x18d4($t1)
.NB0f180f18:
/*  f180f18:	11200003 */ 	beqz	$t1,.NB0f180f28
/*  f180f1c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f180f20:	10000002 */ 	beqz	$zero,.NB0f180f2c
/*  f180f24:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f180f28:
/*  f180f28:	00002025 */ 	or	$a0,$zero,$zero
.NB0f180f2c:
/*  f180f2c:	11000003 */ 	beqz	$t0,.NB0f180f3c
/*  f180f30:	00001825 */ 	or	$v1,$zero,$zero
/*  f180f34:	10000001 */ 	beqz	$zero,.NB0f180f3c
/*  f180f38:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f180f3c:
/*  f180f3c:	10e00003 */ 	beqz	$a3,.NB0f180f4c
/*  f180f40:	00002825 */ 	or	$a1,$zero,$zero
/*  f180f44:	10000001 */ 	beqz	$zero,.NB0f180f4c
/*  f180f48:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f180f4c:
/*  f180f4c:	10c00003 */ 	beqz	$a2,.NB0f180f5c
/*  f180f50:	00001025 */ 	or	$v0,$zero,$zero
/*  f180f54:	10000001 */ 	beqz	$zero,.NB0f180f5c
/*  f180f58:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f180f5c:
/*  f180f5c:	00457821 */ 	addu	$t7,$v0,$a1
/*  f180f60:	01e35021 */ 	addu	$t2,$t7,$v1
/*  f180f64:	01445821 */ 	addu	$t3,$t2,$a0
/*  f180f68:	020b082a */ 	slt	$at,$s0,$t3
/*  f180f6c:	5420ffd6 */ 	bnezl	$at,.NB0f180ec8
/*  f180f70:	8fae0128 */ 	lw	$t6,0x128($sp)
.NB0f180f74:
/*  f180f74:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f180f78:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f180f7c:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f180f80:	8fae0124 */ 	lw	$t6,0x124($sp)
/*  f180f84:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
/*  f180f88:	11a00006 */ 	beqz	$t5,.NB0f180fa4
/*  f180f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180f90:	8dd80040 */ 	lw	$t8,0x40($t6)
/*  f180f94:	00001025 */ 	or	$v0,$zero,$zero
/*  f180f98:	37190004 */ 	ori	$t9,$t8,0x4
/*  f180f9c:	100001c3 */ 	beqz	$zero,.NB0f1816ac
/*  f180fa0:	add90040 */ 	sw	$t9,0x40($t6)
.NB0f180fa4:
/*  f180fa4:	100001c1 */ 	beqz	$zero,.NB0f1816ac
/*  f180fa8:	24020004 */ 	addiu	$v0,$zero,0x4
.NB0f180fac:
/*  f180fac:	24010005 */ 	addiu	$at,$zero,0x5
/*  f180fb0:	146101b8 */ 	bne	$v1,$at,.NB0f181694
/*  f180fb4:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f180fb8:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f180fbc:	3c11800a */ 	lui	$s1,0x800a
/*  f180fc0:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f180fc4:	8de302d4 */ 	lw	$v1,0x2d4($t7)
/*  f180fc8:	5060000e */ 	beqzl	$v1,.NB0f181004
/*  f180fcc:	8e2d028c */ 	lw	$t5,0x28c($s1)
/*  f180fd0:	0fc61c7f */ 	jal	mpPlayerGetIndex
/*  f180fd4:	01e02025 */ 	or	$a0,$t7,$zero
/*  f180fd8:	00025080 */ 	sll	$t2,$v0,0x2
/*  f180fdc:	3c0b800b */ 	lui	$t3,0x800b
/*  f180fe0:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f180fe4:	8d6b0db0 */ 	lw	$t3,0xdb0($t3)
/*  f180fe8:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f180fec:	3c11800a */ 	lui	$s1,0x800a
/*  f180ff0:	afab0050 */ 	sw	$t3,0x50($sp)
/*  f180ff4:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f180ff8:	10000019 */ 	beqz	$zero,.NB0f181060
/*  f180ffc:	8d8302d4 */ 	lw	$v1,0x2d4($t4)
/*  f181000:	8e2d028c */ 	lw	$t5,0x28c($s1)
.NB0f181004:
/*  f181004:	3c0f800b */ 	lui	$t7,0x800b
/*  f181008:	25ef1068 */ 	addiu	$t7,$t7,0x1068
/*  f18100c:	000dc1c0 */ 	sll	$t8,$t5,0x7
/*  f181010:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f181014:	8f2200e4 */ 	lw	$v0,0xe4($t9)
/*  f181018:	3c0d800b */ 	lui	$t5,0x800b
/*  f18101c:	25ad0de8 */ 	addiu	$t5,$t5,0xde8
/*  f181020:	28410004 */ 	slti	$at,$v0,0x4
/*  f181024:	10200007 */ 	beqz	$at,.NB0f181044
/*  f181028:	00025880 */ 	sll	$t3,$v0,0x2
/*  f18102c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f181030:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f181034:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f181038:	01cf5021 */ 	addu	$t2,$t6,$t7
/*  f18103c:	10000008 */ 	beqz	$zero,.NB0f181060
/*  f181040:	afaa0050 */ 	sw	$t2,0x50($sp)
.NB0f181044:
/*  f181044:	01625821 */ 	addu	$t3,$t3,$v0
/*  f181048:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f18104c:	01625823 */ 	subu	$t3,$t3,$v0
/*  f181050:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f181054:	256cfed0 */ 	addiu	$t4,$t3,-304
/*  f181058:	018dc021 */ 	addu	$t8,$t4,$t5
/*  f18105c:	afb80050 */ 	sw	$t8,0x50($sp)
.NB0f181060:
/*  f181060:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f181064:	8faf0120 */ 	lw	$t7,0x120($sp)
/*  f181068:	932e0011 */ 	lbu	$t6,0x11($t9)
/*  f18106c:	85ea0062 */ 	lh	$t2,0x62($t7)
/*  f181070:	15ca00c8 */ 	bne	$t6,$t2,.NB0f181394
/*  f181074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181078:	10600005 */ 	beqz	$v1,.NB0f181090
/*  f18107c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181080:	8c6b009c */ 	lw	$t3,0x9c($v1)
/*  f181084:	000b6840 */ 	sll	$t5,$t3,0x1
/*  f181088:	05a20008 */ 	bltzl	$t5,.NB0f1810ac
/*  f18108c:	8fb80050 */ 	lw	$t8,0x50($sp)
.NB0f181090:
/*  f181090:	546000b9 */ 	bnezl	$v1,.NB0f181378
/*  f181094:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f181098:	0fc43329 */ 	jal	invHasBriefcase
/*  f18109c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1810a0:	504000b5 */ 	beqzl	$v0,.NB0f181378
/*  f1810a4:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f1810a8:	8fb80050 */ 	lw	$t8,0x50($sp)
.NB0f1810ac:
/*  f1810ac:	3c02800b */ 	lui	$v0,0x800b
/*  f1810b0:	244209c0 */ 	addiu	$v0,$v0,0x9c0
/*  f1810b4:	8719003e */ 	lh	$t9,0x3e($t8)
/*  f1810b8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1810bc:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f1810c0:	a70f003e */ 	sh	$t7,0x3e($t8)
/*  f1810c4:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f1810c8:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f1810cc:	8dc3001c */ 	lw	$v1,0x1c($t6)
.NB0f1810d0:
/*  f1810d0:	8c4a0058 */ 	lw	$t2,0x58($v0)
/*  f1810d4:	506a0006 */ 	beql	$v1,$t2,.NB0f1810f0
/*  f1810d8:	8d6c02d4 */ 	lw	$t4,0x2d4($t3)
/*  f1810dc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1810e0:	2a010004 */ 	slti	$at,$s0,0x4
/*  f1810e4:	1420fffa */ 	bnez	$at,.NB0f1810d0
/*  f1810e8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1810ec:	8d6c02d4 */ 	lw	$t4,0x2d4($t3)
.NB0f1810f0:
/*  f1810f0:	11800009 */ 	beqz	$t4,.NB0f181118
/*  f1810f4:	01602025 */ 	or	$a0,$t3,$zero
/*  f1810f8:	0fc64e59 */ 	jal	func0f199984
/*  f1810fc:	24050056 */ 	addiu	$a1,$zero,0x56
/*  f181100:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f181104:	8da302d4 */ 	lw	$v1,0x2d4($t5)
/*  f181108:	9079009c */ 	lbu	$t9,0x9c($v1)
/*  f18110c:	332fffbf */ 	andi	$t7,$t9,0xffbf
/*  f181110:	10000014 */ 	beqz	$zero,.NB0f181164
/*  f181114:	a06f009c */ 	sb	$t7,0x9c($v1)
.NB0f181118:
/*  f181118:	3c01bf80 */ 	lui	$at,0xbf80
/*  f18111c:	44812000 */ 	mtc1	$at,$f4
/*  f181120:	3c04800a */ 	lui	$a0,0x800a
/*  f181124:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f181128:	240effff */ 	addiu	$t6,$zero,-1
/*  f18112c:	240affff */ 	addiu	$t2,$zero,-1
/*  f181130:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f181134:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f181138:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f18113c:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f181140:	240505b8 */ 	addiu	$a1,$zero,0x5b8
/*  f181144:	00003025 */ 	or	$a2,$zero,$zero
/*  f181148:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f18114c:	0c004338 */ 	jal	sndStart
/*  f181150:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f181154:	0fc23e12 */ 	jal	func0f091250
/*  f181158:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f18115c:	0fc430c1 */ 	jal	invRemoveItemByNum
/*  f181160:	24040056 */ 	addiu	$a0,$zero,0x56
.NB0f181164:
/*  f181164:	0fc5a4dd */ 	jal	langGet
/*  f181168:	24045404 */ 	addiu	$a0,$zero,0x5404
/*  f18116c:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f181170:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f181174:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f181178:	00106080 */ 	sll	$t4,$s0,0x2
/*  f18117c:	01906023 */ 	subu	$t4,$t4,$s0
/*  f181180:	3c0b800b */ 	lui	$t3,0x800b
/*  f181184:	256b1460 */ 	addiu	$t3,$t3,0x1460
/*  f181188:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f18118c:	018b3021 */ 	addu	$a2,$t4,$t3
/*  f181190:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f181194:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f181198:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f18119c:	0c004fc1 */ 	jal	sprintf
/*  f1811a0:	00403825 */ 	or	$a3,$v0,$zero
/*  f1811a4:	0fc5a4dd */ 	jal	langGet
/*  f1811a8:	24045405 */ 	addiu	$a0,$zero,0x5405
/*  f1811ac:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f1811b0:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f1811b4:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f1811b8:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1811bc:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f1811c0:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f1811c4:	0c004fc1 */ 	jal	sprintf
/*  f1811c8:	00403825 */ 	or	$a3,$v0,$zero
/*  f1811cc:	0fc5a4dd */ 	jal	langGet
/*  f1811d0:	24045406 */ 	addiu	$a0,$zero,0x5406
/*  f1811d4:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f1811d8:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f1811dc:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f1811e0:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1811e4:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f1811e8:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f1811ec:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f1811f0:	0c004fc1 */ 	jal	sprintf
/*  f1811f4:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f1811f8:	8e39006c */ 	lw	$t9,0x6c($s1)
/*  f1811fc:	8e2d028c */ 	lw	$t5,0x28c($s1)
/*  f181200:	afb00114 */ 	sw	$s0,0x114($sp)
/*  f181204:	00008025 */ 	or	$s0,$zero,$zero
/*  f181208:	13200003 */ 	beqz	$t9,.NB0f181218
/*  f18120c:	afad0118 */ 	sw	$t5,0x118($sp)
/*  f181210:	10000002 */ 	beqz	$zero,.NB0f18121c
/*  f181214:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f181218:
/*  f181218:	00002025 */ 	or	$a0,$zero,$zero
.NB0f18121c:
/*  f18121c:	8e2f0068 */ 	lw	$t7,0x68($s1)
/*  f181220:	00001825 */ 	or	$v1,$zero,$zero
/*  f181224:	00002825 */ 	or	$a1,$zero,$zero
/*  f181228:	11e00003 */ 	beqz	$t7,.NB0f181238
/*  f18122c:	00001025 */ 	or	$v0,$zero,$zero
/*  f181230:	10000001 */ 	beqz	$zero,.NB0f181238
/*  f181234:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f181238:
/*  f181238:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f18123c:	13000003 */ 	beqz	$t8,.NB0f18124c
/*  f181240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181244:	10000001 */ 	beqz	$zero,.NB0f18124c
/*  f181248:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f18124c:
/*  f18124c:	8e2e0070 */ 	lw	$t6,0x70($s1)
/*  f181250:	11c00003 */ 	beqz	$t6,.NB0f181260
/*  f181254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181258:	10000001 */ 	beqz	$zero,.NB0f181260
/*  f18125c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f181260:
/*  f181260:	00455021 */ 	addu	$t2,$v0,$a1
/*  f181264:	01436021 */ 	addu	$t4,$t2,$v1
/*  f181268:	01845821 */ 	addu	$t3,$t4,$a0
/*  f18126c:	1960003f */ 	blez	$t3,.NB0f18136c
/*  f181270:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f181274:
/*  f181274:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f181278:	02002025 */ 	or	$a0,$s0,$zero
/*  f18127c:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f181280:	00107080 */ 	sll	$t6,$s0,0x2
/*  f181284:	3c0a800b */ 	lui	$t2,0x800b
/*  f181288:	8db902d4 */ 	lw	$t9,0x2d4($t5)
/*  f18128c:	8faf0118 */ 	lw	$t7,0x118($sp)
/*  f181290:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f181294:	17200008 */ 	bnez	$t9,.NB0f1812b8
/*  f181298:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18129c:	160f0006 */ 	bne	$s0,$t7,.NB0f1812b8
/*  f1812a0:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f1812a4:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1812a8:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f1812ac:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1812b0:	10000011 */ 	beqz	$zero,.NB0f1812f8
/*  f1812b4:	8e2b006c */ 	lw	$t3,0x6c($s1)
.NB0f1812b8:
/*  f1812b8:	8d4a0db0 */ 	lw	$t2,0xdb0($t2)
/*  f1812bc:	8fb80114 */ 	lw	$t8,0x114($sp)
/*  f1812c0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1812c4:	914c0011 */ 	lbu	$t4,0x11($t2)
/*  f1812c8:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f1812cc:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1812d0:	170c0006 */ 	bne	$t8,$t4,.NB0f1812ec
/*  f1812d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1812d8:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f1812dc:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f1812e0:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1812e4:	10000004 */ 	beqz	$zero,.NB0f1812f8
/*  f1812e8:	8e2b006c */ 	lw	$t3,0x6c($s1)
.NB0f1812ec:
/*  f1812ec:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f1812f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1812f4:	8e2b006c */ 	lw	$t3,0x6c($s1)
.NB0f1812f8:
/*  f1812f8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1812fc:	00002025 */ 	or	$a0,$zero,$zero
/*  f181300:	11600003 */ 	beqz	$t3,.NB0f181310
/*  f181304:	00001825 */ 	or	$v1,$zero,$zero
/*  f181308:	10000001 */ 	beqz	$zero,.NB0f181310
/*  f18130c:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f181310:
/*  f181310:	8e2d0068 */ 	lw	$t5,0x68($s1)
/*  f181314:	00002825 */ 	or	$a1,$zero,$zero
/*  f181318:	00001025 */ 	or	$v0,$zero,$zero
/*  f18131c:	11a00003 */ 	beqz	$t5,.NB0f18132c
/*  f181320:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181324:	10000001 */ 	beqz	$zero,.NB0f18132c
/*  f181328:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f18132c:
/*  f18132c:	8e390064 */ 	lw	$t9,0x64($s1)
/*  f181330:	13200003 */ 	beqz	$t9,.NB0f181340
/*  f181334:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181338:	10000001 */ 	beqz	$zero,.NB0f181340
/*  f18133c:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f181340:
/*  f181340:	8e2f0070 */ 	lw	$t7,0x70($s1)
/*  f181344:	11e00003 */ 	beqz	$t7,.NB0f181354
/*  f181348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18134c:	10000001 */ 	beqz	$zero,.NB0f181354
/*  f181350:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f181354:
/*  f181354:	00457021 */ 	addu	$t6,$v0,$a1
/*  f181358:	01c35021 */ 	addu	$t2,$t6,$v1
/*  f18135c:	0144c021 */ 	addu	$t8,$t2,$a0
/*  f181360:	0218082a */ 	slt	$at,$s0,$t8
/*  f181364:	1420ffc3 */ 	bnez	$at,.NB0f181274
/*  f181368:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f18136c:
/*  f18136c:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f181370:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f181374:	8fac0128 */ 	lw	$t4,0x128($sp)
.NB0f181378:
/*  f181378:	8d8b02d4 */ 	lw	$t3,0x2d4($t4)
/*  f18137c:	11600003 */ 	beqz	$t3,.NB0f18138c
/*  f181380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181384:	100000c9 */ 	beqz	$zero,.NB0f1816ac
/*  f181388:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18138c:
/*  f18138c:	100000c7 */ 	beqz	$zero,.NB0f1816ac
/*  f181390:	00001025 */ 	or	$v0,$zero,$zero
.NB0f181394:
/*  f181394:	10600005 */ 	beqz	$v1,.NB0f1813ac
/*  f181398:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18139c:	8c6d009c */ 	lw	$t5,0x9c($v1)
/*  f1813a0:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f1813a4:	05e10008 */ 	bgez	$t7,.NB0f1813c8
/*  f1813a8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1813ac:
/*  f1813ac:	546000b2 */ 	bnezl	$v1,.NB0f181678
/*  f1813b0:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f1813b4:	0fc43329 */ 	jal	invHasBriefcase
/*  f1813b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1813bc:	144000ad */ 	bnez	$v0,.NB0f181674
/*  f1813c0:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f1813c4:	8dc302d4 */ 	lw	$v1,0x2d4($t6)
.NB0f1813c8:
/*  f1813c8:	50600009 */ 	beqzl	$v1,.NB0f1813f0
/*  f1813cc:	8faf0120 */ 	lw	$t7,0x120($sp)
/*  f1813d0:	9078009c */ 	lbu	$t8,0x9c($v1)
/*  f1813d4:	370c0040 */ 	ori	$t4,$t8,0x40
/*  f1813d8:	a06c009c */ 	sb	$t4,0x9c($v1)
/*  f1813dc:	8fab0120 */ 	lw	$t3,0x120($sp)
/*  f1813e0:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f1813e4:	0fc2191a */ 	jal	propPlayPickupSound
/*  f1813e8:	9165005c */ 	lbu	$a1,0x5c($t3)
/*  f1813ec:	8faf0120 */ 	lw	$t7,0x120($sp)
.NB0f1813f0:
/*  f1813f0:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f1813f4:	3c01800b */ 	lui	$at,0x800b
/*  f1813f8:	85ee0062 */ 	lh	$t6,0x62($t7)
/*  f1813fc:	8db9001c */ 	lw	$t9,0x1c($t5)
/*  f181400:	24045401 */ 	addiu	$a0,$zero,0x5401
/*  f181404:	000e5080 */ 	sll	$t2,$t6,0x2
/*  f181408:	002a0821 */ 	addu	$at,$at,$t2
/*  f18140c:	0fc5a4dd */ 	jal	langGet
/*  f181410:	ac390a18 */ 	sw	$t9,0xa18($at)
/*  f181414:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f181418:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f18141c:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f181420:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f181424:	3c10800b */ 	lui	$s0,0x800b
/*  f181428:	26101460 */ 	addiu	$s0,$s0,0x1460
/*  f18142c:	870c0062 */ 	lh	$t4,0x62($t8)
/*  f181430:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f181434:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f181438:	000c5880 */ 	sll	$t3,$t4,0x2
/*  f18143c:	016c5823 */ 	subu	$t3,$t3,$t4
/*  f181440:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f181444:	020b3821 */ 	addu	$a3,$s0,$t3
/*  f181448:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f18144c:	0c004fc1 */ 	jal	sprintf
/*  f181450:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f181454:	0fc5a4dd */ 	jal	langGet
/*  f181458:	24045402 */ 	addiu	$a0,$zero,0x5402
/*  f18145c:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f181460:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f181464:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f181468:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f18146c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f181470:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f181474:	0c004fc1 */ 	jal	sprintf
/*  f181478:	00403825 */ 	or	$a3,$v0,$zero
/*  f18147c:	0fc5a4dd */ 	jal	langGet
/*  f181480:	24045403 */ 	addiu	$a0,$zero,0x5403
/*  f181484:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f181488:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f18148c:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f181490:	8fad0120 */ 	lw	$t5,0x120($sp)
/*  f181494:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f181498:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f18149c:	85af0062 */ 	lh	$t7,0x62($t5)
/*  f1814a0:	00403825 */ 	or	$a3,$v0,$zero
/*  f1814a4:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f1814a8:	01cf7023 */ 	subu	$t6,$t6,$t7
/*  f1814ac:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1814b0:	0c004fc1 */ 	jal	sprintf
/*  f1814b4:	020e3021 */ 	addu	$a2,$s0,$t6
/*  f1814b8:	8e2a006c */ 	lw	$t2,0x6c($s1)
/*  f1814bc:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f1814c0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1814c4:	11400003 */ 	beqz	$t2,.NB0f1814d4
/*  f1814c8:	afb90118 */ 	sw	$t9,0x118($sp)
/*  f1814cc:	10000002 */ 	beqz	$zero,.NB0f1814d8
/*  f1814d0:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f1814d4:
/*  f1814d4:	00002025 */ 	or	$a0,$zero,$zero
.NB0f1814d8:
/*  f1814d8:	8e380068 */ 	lw	$t8,0x68($s1)
/*  f1814dc:	00001825 */ 	or	$v1,$zero,$zero
/*  f1814e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1814e4:	13000003 */ 	beqz	$t8,.NB0f1814f4
/*  f1814e8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1814ec:	10000001 */ 	beqz	$zero,.NB0f1814f4
/*  f1814f0:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f1814f4:
/*  f1814f4:	8e2c0064 */ 	lw	$t4,0x64($s1)
/*  f1814f8:	11800003 */ 	beqz	$t4,.NB0f181508
/*  f1814fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181500:	10000001 */ 	beqz	$zero,.NB0f181508
/*  f181504:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f181508:
/*  f181508:	8e2b0070 */ 	lw	$t3,0x70($s1)
/*  f18150c:	11600003 */ 	beqz	$t3,.NB0f18151c
/*  f181510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181514:	10000001 */ 	beqz	$zero,.NB0f18151c
/*  f181518:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f18151c:
/*  f18151c:	00456821 */ 	addu	$t5,$v0,$a1
/*  f181520:	01a37821 */ 	addu	$t7,$t5,$v1
/*  f181524:	01e47021 */ 	addu	$t6,$t7,$a0
/*  f181528:	19c0003f */ 	blez	$t6,.NB0f181628
/*  f18152c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f181530:
/*  f181530:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f181534:	02002025 */ 	or	$a0,$s0,$zero
/*  f181538:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f18153c:	00106880 */ 	sll	$t5,$s0,0x2
/*  f181540:	3c0f800b */ 	lui	$t7,0x800b
/*  f181544:	8f2a02d4 */ 	lw	$t2,0x2d4($t9)
/*  f181548:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f18154c:	01ed7821 */ 	addu	$t7,$t7,$t5
/*  f181550:	15400008 */ 	bnez	$t2,.NB0f181574
/*  f181554:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f181558:	16180006 */ 	bne	$s0,$t8,.NB0f181574
/*  f18155c:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f181560:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f181564:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f181568:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18156c:	10000011 */ 	beqz	$zero,.NB0f1815b4
/*  f181570:	8e39006c */ 	lw	$t9,0x6c($s1)
.NB0f181574:
/*  f181574:	8def0db0 */ 	lw	$t7,0xdb0($t7)
/*  f181578:	858b0062 */ 	lh	$t3,0x62($t4)
/*  f18157c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f181580:	91ee0011 */ 	lbu	$t6,0x11($t7)
/*  f181584:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f181588:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f18158c:	156e0006 */ 	bne	$t3,$t6,.NB0f1815a8
/*  f181590:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181594:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f181598:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f18159c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1815a0:	10000004 */ 	beqz	$zero,.NB0f1815b4
/*  f1815a4:	8e39006c */ 	lw	$t9,0x6c($s1)
.NB0f1815a8:
/*  f1815a8:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f1815ac:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1815b0:	8e39006c */ 	lw	$t9,0x6c($s1)
.NB0f1815b4:
/*  f1815b4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1815b8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1815bc:	13200003 */ 	beqz	$t9,.NB0f1815cc
/*  f1815c0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1815c4:	10000001 */ 	beqz	$zero,.NB0f1815cc
/*  f1815c8:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f1815cc:
/*  f1815cc:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f1815d0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1815d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1815d8:	11400003 */ 	beqz	$t2,.NB0f1815e8
/*  f1815dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1815e0:	10000001 */ 	beqz	$zero,.NB0f1815e8
/*  f1815e4:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f1815e8:
/*  f1815e8:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f1815ec:	13000003 */ 	beqz	$t8,.NB0f1815fc
/*  f1815f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1815f4:	10000001 */ 	beqz	$zero,.NB0f1815fc
/*  f1815f8:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f1815fc:
/*  f1815fc:	8e2c0070 */ 	lw	$t4,0x70($s1)
/*  f181600:	11800003 */ 	beqz	$t4,.NB0f181610
/*  f181604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181608:	10000001 */ 	beqz	$zero,.NB0f181610
/*  f18160c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f181610:
/*  f181610:	00456821 */ 	addu	$t5,$v0,$a1
/*  f181614:	01a37821 */ 	addu	$t7,$t5,$v1
/*  f181618:	01e45821 */ 	addu	$t3,$t7,$a0
/*  f18161c:	020b082a */ 	slt	$at,$s0,$t3
/*  f181620:	1420ffc3 */ 	bnez	$at,.NB0f181530
/*  f181624:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f181628:
/*  f181628:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f18162c:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f181630:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f181634:	8dd902d4 */ 	lw	$t9,0x2d4($t6)
/*  f181638:	01c02025 */ 	or	$a0,$t6,$zero
/*  f18163c:	13200009 */ 	beqz	$t9,.NB0f181664
/*  f181640:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181644:	0fc6479b */ 	jal	aibotGiveSingleWeapon
/*  f181648:	24050056 */ 	addiu	$a1,$zero,0x56
/*  f18164c:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f181650:	00001025 */ 	or	$v0,$zero,$zero
/*  f181654:	8d580040 */ 	lw	$t8,0x40($t2)
/*  f181658:	370c0004 */ 	ori	$t4,$t8,0x4
/*  f18165c:	10000013 */ 	beqz	$zero,.NB0f1816ac
/*  f181660:	ad4c0040 */ 	sw	$t4,0x40($t2)
.NB0f181664:
/*  f181664:	0fc43154 */ 	jal	invGiveWeaponsByProp
/*  f181668:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f18166c:	1000000f */ 	beqz	$zero,.NB0f1816ac
/*  f181670:	24020004 */ 	addiu	$v0,$zero,0x4
.NB0f181674:
/*  f181674:	8fad0128 */ 	lw	$t5,0x128($sp)
.NB0f181678:
/*  f181678:	8daf02d4 */ 	lw	$t7,0x2d4($t5)
/*  f18167c:	11e00003 */ 	beqz	$t7,.NB0f18168c
/*  f181680:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181684:	10000009 */ 	beqz	$zero,.NB0f1816ac
/*  f181688:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18168c:
/*  f18168c:	10000007 */ 	beqz	$zero,.NB0f1816ac
/*  f181690:	00001025 */ 	or	$v0,$zero,$zero
.NB0f181694:
/*  f181694:	8d7902d4 */ 	lw	$t9,0x2d4($t3)
/*  f181698:	00001025 */ 	or	$v0,$zero,$zero
/*  f18169c:	13200003 */ 	beqz	$t9,.NB0f1816ac
/*  f1816a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1816a4:	10000001 */ 	beqz	$zero,.NB0f1816ac
/*  f1816a8:	00001025 */ 	or	$v0,$zero,$zero
.NB0f1816ac:
/*  f1816ac:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1816b0:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f1816b4:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f1816b8:	03e00008 */ 	jr	$ra
/*  f1816bc:	27bd0128 */ 	addiu	$sp,$sp,0x128
);
#endif

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

s32 chrGiveUplink(struct chrdata *chr, struct prop *prop)
{
	s32 i;
	struct mpchr *mpchr;
	char message[60];
	s32 mpindex;
	u32 playernum;

	if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
#if VERSION >= VERSION_NTSC_1_0
		struct defaultobj *obj = prop->obj;
#endif

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

#if PAL
		// "%shas the\nData Uplink%s"
		sprintf(message, langGet(L_MPWEAPONS_000), mpchr->name);
#else
		// "%shas the\n%s"
		sprintf(message, langGet(L_MPWEAPONS_000), mpchr->name, bgunGetShortName(WEAPON_DATAUPLINK));
#endif
		playernum = g_Vars.currentplayernum;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (chr->aibot || i != playernum) {
				setCurrentPlayerNum(i);
				hudmsgCreateWithFlags(message, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
			}
		}

		setCurrentPlayerNum(playernum);

		if (chr->aibot) {
			propPlayPickupSound(prop, WEAPON_DATAUPLINK);
			aibotGiveSingleWeapon(chr, WEAPON_DATAUPLINK);
			chr->aibot->unk04c_05 = true;

#if VERSION >= VERSION_NTSC_1_0
			obj->hidden |= OBJHFLAG_REAPABLE;
#else
			prop->obj->hidden |= OBJHFLAG_REAPABLE;
#endif

			return 0;
		} else {
			invGiveSingleWeapon(WEAPON_DATAUPLINK);
			currentPlayerQueuePickupWeaponHudmsg(WEAPON_DATAUPLINK, false);
			weaponPlayPickupSound(WEAPON_DATAUPLINK);

#if VERSION >= VERSION_NTSC_1_0
			objRemove2(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
			return 1;
#else
			return 4;
#endif

		}
	} else if (chr->aibot) {
		return 0;
	}

	return 0;
}

void scenarioHtmActivateUplink(struct chrdata *chr, struct prop *terminal)
{
	if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
		struct defaultobj *obj = terminal->obj;

		if (obj->flags3 & OBJFLAG3_HTMTERMINAL) {
			u32 mpindex = mpPlayerGetIndex(chr);

			if ((obj->hidden & OBJHFLAG_ACTIVATED_BY_BOND) == 0) {
				obj->hidden &= 0x0fffffff;
				obj->hidden |= (mpindex << 28) & 0xf0000000;
				obj->hidden |= OBJHFLAG_ACTIVATED_BY_BOND;
			}
		}
	}
}
