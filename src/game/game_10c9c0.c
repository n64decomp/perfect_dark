#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_0f09f0.h"
#include "game/game_10c9c0.h"
#include "game/game_19aa80.h"
#include "game/mplayer.h"
#include "gvars/gvars.h"
#include "types.h"

s32 menuhandler4MbDropOut(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();

		if (func0f18c87c() == 1) {
			func0f0f820c(&g_4MbMainMenu, 11);
		}
	}

	return 0;
}

s32 menuhandler0010ca1c(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		if (g_Vars.stagenum == 0x5d) {
			func0f0f820c(&g_4MbMainMenu, 11);
		} else {
			func0f0f820c(&g_SoloPauseMenuDialog, 2);
		}
	}

	return 0;
}

s32 menuhandler4MbAdvancedSetup(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f0f820c(&g_4MbAdvancedSetupMenuDialog, 11);
	}

	return 0;
}

s32 menuhandler0010cabc(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		mpSetCurrentChallenge(g_MenuStack[g_MpPlayerNum].slotindex);
		func0f0f820c(&menudialog_mpquickgo2, 11);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f10cb2c
/*  f10cb2c:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10cb30:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10cb34:	3c028006 */ 	lui	$v0,%hi(var80062940)
/*  f10cb38:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f10cb3c:	24422940 */ 	addiu	$v0,$v0,%lo(var80062940)
/*  f10cb40:	ac201448 */ 	sw	$zero,%lo(g_MpPlayerNum)($at)
/*  f10cb44:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f10cb48:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10cb4c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f10cb50:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f10cb54:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f10cb58:	11e0000e */ 	beqz	$t7,.L0f10cb94
/*  f10cb5c:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f10cb60:	3c188008 */ 	lui	$t8,%hi(var80087260)
/*  f10cb64:	8f187260 */ 	lw	$t8,%lo(var80087260)($t8)
/*  f10cb68:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f10cb6c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f10cb70:	1700001d */ 	bnez	$t8,.L0f10cbe8
/*  f10cb74:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f10cb78:	3c048007 */ 	lui	$a0,%hi(g_4MbMainMenu)
/*  f10cb7c:	ac590490 */ 	sw	$t9,0x490($v0)
/*  f10cb80:	24845294 */ 	addiu	$a0,$a0,%lo(g_4MbMainMenu)
/*  f10cb84:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10cb88:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f10cb8c:	10000017 */ 	beqz	$zero,.L0f10cbec
/*  f10cb90:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f10cb94:
/*  f10cb94:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f10cb98:	a0480000 */ 	sb	$t0,0x0($v0)
/*  f10cb9c:	00008025 */ 	or	$s0,$zero,$zero
/*  f10cba0:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f10cba4:	02002025 */ 	or	$a0,$s0,$zero
.L0f10cba8:
/*  f10cba8:	0fc62003 */ 	jal	func0f18800c
/*  f10cbac:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f10cbb0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10cbb4:	5611fffc */ 	bnel	$s0,$s1,.L0f10cba8
/*  f10cbb8:	02002025 */ 	or	$a0,$s0,$zero
/*  f10cbbc:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f10cbc0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f10cbc4:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f10cbc8:	ac400294 */ 	sw	$zero,0x294($v0)
/*  f10cbcc:	ac430298 */ 	sw	$v1,0x298($v0)
/*  f10cbd0:	0fc66bf7 */ 	jal	func0f19afdc
/*  f10cbd4:	ac43029c */ 	sw	$v1,0x29c($v0)
/*  f10cbd8:	3c048007 */ 	lui	$a0,%hi(menudialog_fileselect2)
/*  f10cbdc:	24844f34 */ 	addiu	$a0,$a0,%lo(menudialog_fileselect2)
/*  f10cbe0:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10cbe4:	2405000a */ 	addiu	$a1,$zero,0xa
.L0f10cbe8:
/*  f10cbe8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f10cbec:
/*  f10cbec:	8fa90020 */ 	lw	$t1,0x20($sp)
/*  f10cbf0:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f10cbf4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f10cbf8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f10cbfc:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f10cc00:	03e00008 */ 	jr	$ra
/*  f10cc04:	ac291448 */ 	sw	$t1,%lo(g_MpPlayerNum)($at)
);

bool menudialog4MbMainMenu(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	if (operation == MENUOP_100) {
		g_Vars.unk000494 = 0;
		g_Vars.unk000495 = 0;
		g_Vars.unk000496 = 0;
		g_Vars.unk000497 = 0;
	}

	if (g_MenuStack[g_MpPlayerNum].unk4f8 &&
			g_MenuStack[g_MpPlayerNum].unk4f8->dialog == &g_4MbMainMenu &&
			operation == MENUOP_102) {
		g_Vars.unk000490 = 2;
		g_Vars.mpquickteam = MPQUICKTEAM_5;
		g_Vars.unk00049c = 0;
		mpResetVar800884b4();
		func0f19c220();
	}

	return false;
}
