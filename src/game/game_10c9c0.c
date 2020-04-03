#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
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

		if (mpGetNumChrs() == 1) {
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

void func0f10cb2c(void)
{
	s32 i;
	u32 prevplayernum = g_MpPlayerNum;
	g_MpPlayerNum = 0;

	if (var80062940) {
		if (var80087260 == 0) {
			g_Vars.unk000490 = 2;
			menuPushRootDialog(&g_4MbMainMenu, MENUROOT_4MBMAINMENU);
		}
	} else {
		var80062940 = 1;

		for (i = 0; i != 6; i++) {
			func0f18800c(i, true);
		}

		g_Vars.bondplayernum = 0;
		g_Vars.coopplayernum = -1;
		g_Vars.antiplayernum = -1;

		func0f19afdc();

		menuPushRootDialog(&menudialog_fileselect2, MENUROOT_10);
	}

	g_MpPlayerNum = prevplayernum;
}

bool menudialog4MbMainMenu(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	if (operation == MENUOP_100) {
		g_Vars.unk000494 = 0;
		g_Vars.unk000495 = 0;
		g_Vars.unk000496 = 0;
		g_Vars.unk000497 = 0;
	}

	if (g_MenuStack[g_MpPlayerNum].curframe &&
			g_MenuStack[g_MpPlayerNum].curframe->dialog == &g_4MbMainMenu &&
			operation == MENUOP_102) {
		g_Vars.unk000490 = 2;
		g_Vars.mpquickteam = MPQUICKTEAM_5;
		g_Vars.unk00049c = 0;
		mpResetVar800884b4();
		func0f19c220();
	}

	return false;
}
