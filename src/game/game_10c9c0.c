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
#include "game/mplayer/mplayer.h"
#include "gvars/gvars.h"
#include "types.h"

s32 menuhandler4MbDropOut(u32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();

		if (mpGetNumChrs() == 1) {
			func0f0f820c(&g_4MbMainMenu, MENUROOT_4MBMAINMENU);
		}
	}

	return 0;
}

s32 menuhandler0010ca1c(u32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_Vars.stagenum == STAGE_4MBMENU) {
			func0f0f820c(&g_4MbMainMenu, MENUROOT_4MBMAINMENU);
		} else {
			func0f0f820c(&g_SoloPauseMenuDialog, MENUROOT_MAINMENU);
		}
	}

	return 0;
}

s32 menuhandler4MbAdvancedSetup(u32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f0f820c(&g_4MbAdvancedSetupMenuDialog, MENUROOT_4MBMAINMENU);
	}

	return 0;
}

s32 menuhandler0010cabc(u32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		mpSetCurrentChallenge(g_Menus[g_MpPlayerNum].data.main4mb.slotindex);
		func0f0f820c(&menudialog_mpquickgo2, MENUROOT_4MBMAINMENU);
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

		mpDetermineUnlockedFeatures();

		menuPushRootDialog(&menudialog_fileselect2, MENUROOT_10);
	}

	g_MpPlayerNum = prevplayernum;
}

s32 menudialog4MbMainMenu(u32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.unk000494[0] = 0;
		g_Vars.unk000494[1] = 0;
		g_Vars.unk000494[2] = 0;
		g_Vars.unk000494[3] = 0;
	}

	if (g_Menus[g_MpPlayerNum].curframe &&
			g_Menus[g_MpPlayerNum].curframe->dialog == &g_4MbMainMenu &&
			operation == MENUOP_TICK) {
		g_Vars.unk000490 = 2;
		g_Vars.mpquickteam = MPQUICKTEAM_5;
		g_Vars.unk00049c = 0;
		mpClearCurrentChallenge();
		mpRemoveLock();
	}

	return false;
}
