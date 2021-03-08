#include <ultra64.h>
#include "constants.h"
#include "game/game_0b3350.h"
#include "game/game_0d4690.h"
#include "game/game_0f09f0.h"
#include "game/game_107fb0.h"
#include "game/game_1531a0.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "game/utils.h"
#include "gvars/gvars.h"
#include "lib/lib_09a80.h"
#include "lib/lib_126b0.h"
#include "data.h"
#include "types.h"

// bss
struct savelocation_2d8 g_FilemgrFileToCopy;
struct savelocation_2d8 var800a21e8;
struct savelocation_2d8 g_FilemgrFileToDelete;
struct savelocation_2d8 var800a21f8;
struct savefile_solo g_SoloSaveFile;
u32 var800a22bc;
struct savelocation_2d8 g_FilemgrLoadedMainFile;

// These might be able to be removed by relocating their symbols
struct menudialog g_FilemgrCopyMenuDialog;
struct menudialog g_FilemgrConfirmDeleteMenuDialog;
struct menudialog g_FilemgrDeleteMenuDialog;
struct menudialog g_FilemgrDuplicateNameMenuDialog;
struct menudialog g_FilemgrEnterNameMenuDialog;
struct menudialog g_FilemgrErrorMenuDialog;
struct menudialog g_FilemgrFileInUseMenuDialog;
struct menudialog g_FilemgrFileLostMenuDialog;
struct menudialog g_FilemgrFileSavedMenuDialog;
struct menudialog g_FilemgrFileSelectMenuDialog;
struct menudialog g_FilemgrRenameMenuDialog;
struct menudialog g_FilemgrSaveElsewhereMenuDialog;
struct menudialog g_FilemgrSaveErrorMenuDialog;
struct menudialog g_FilemgrSelectLocationMenuDialog;
struct menudialog g_PakDeleteNoteMenuDialog;
struct menudialog g_PakGameNotesMenuDialog;
struct menudialog g_PakNotOriginalMenuDialog;
struct pakdata *g_EditingPak;

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f1088d0pf
/*  f1088d0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1088d4:	24010006 */ 	li	$at,0x6
/*  f1088d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1088dc:	14810009 */ 	bne	$a0,$at,.PF0f108904
/*  f1088e0:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1088e4:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f1088e8:	3c02800a */ 	lui	$v0,0x800a
/*  f1088ec:	2442a510 */ 	addiu	$v0,$v0,-23280
/*  f1088f0:	a44e0482 */ 	sh	$t6,0x482($v0)
/*  f1088f4:	0fc5bdd7 */ 	jal	0xf16f75c
/*  f1088f8:	31c4ffff */ 	andi	$a0,$t6,0xffff
/*  f1088fc:	0fc3cf8c */ 	jal	0xf0f3e30
/*  f108900:	00000000 */ 	nop
.PF0f108904:
/*  f108904:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108908:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10890c:	00001025 */ 	move	$v0,$zero
/*  f108910:	03e00008 */ 	jr	$ra
/*  f108914:	00000000 */ 	nop
);
#endif

char *filemgrGetDeviceName(s32 index)
{
	u16 names[] = {
		L_OPTIONS(112), // "Controller Pak 1"
		L_OPTIONS(113), // "Controller Pak 2"
		L_OPTIONS(114), // "Controller Pak 3"
		L_OPTIONS(115), // "Controller Pak 4"
		L_OPTIONS(111), // "Game Pak"
		L_MPWEAPONS(229), // "Controller Pak Not Found"
	};

	if (index < ARRAYCOUNT(names)) {
		return langGet(names[index]);
	}

	return NULL;
}

s32 filemgrDeviceNameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if ((g_Menus[g_MpPlayerNum].unke3c & 0x7f) >= SAVEDEVICE_INVALID) {
			return true;
		}
	}

	return 0;
}

char *filemgrMenuTextDeviceName(struct menuitem *item)
{
	return filemgrGetDeviceName(g_Menus[g_MpPlayerNum].unke3c & 0x7f);
}

void filemgrGetFileName(char *buffer, struct savelocation000 *arg1, u32 filetype)
{
	s32 days;
	char tmpbuffer1[28];
	char namebuffer[20];
	u32 totalinseconds;
	s32 pos;
	s32 hours;
	s32 minutes;
	s32 seconds;
	s32 totalinhours;

	switch (filetype) {
	case FILETYPE_SOLO:
	case FILETYPE_MPSETUP:
		func0f0d564c(arg1->unk06, tmpbuffer1, 0);
		break;
	case FILETYPE_MPPLAYER:
		// MP Player filenames have the play duration appended to the name
		func0f18d9a4(arg1->unk06, namebuffer, &totalinseconds);
		pos = sprintf(tmpbuffer1, "%s-", namebuffer);

		if (totalinseconds >= 0x7ffffff) { // about 4.25 years
			sprintf(tmpbuffer1 + pos, "==:==");
		} else {
			seconds = totalinseconds % 60;
			totalinseconds = totalinseconds / 60;
			totalinhours = totalinseconds / 60;
			minutes = totalinseconds % 60;
			days = totalinhours / 24;
			hours = totalinhours % 24;

			if (days == 0) {
				// seconds is passed but has no placeholder
				sprintf(tmpbuffer1 + pos, "%d:%02d", hours, minutes, seconds);
			} else {
				sprintf(tmpbuffer1 + pos, "%d:%02d:%02d", days, hours, minutes);
			}
		}
		break;
	}

	sprintf(buffer, "%s\n", tmpbuffer1);
}

const char var7f1b2f28[] = "Setup: item = %x\n";

const u32 var7f1b2f3c[] = {0xa0, 0x31, 0x4e, 0x4a0};

s32 filemgrFileNameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_Menus[g_MpPlayerNum].unke38 == 0) {
			return true;
		}
	}

	return 0;
}

char *filemgrMenuTextDeleteFileName(struct menuitem *item)
{
	if (g_Menus[g_MpPlayerNum].unke38) {
		filemgrGetFileName(g_StringPointer,
				g_Menus[g_MpPlayerNum].unke38,
				g_Menus[g_MpPlayerNum].unke3d);
		return g_StringPointer;
	}

	return NULL;
}

void func0f108324(s32 arg0)
{
	s32 index = pakSearch(arg0);

	if (index >= 0) {
		g_Menus[g_MpPlayerNum].unke3c = index;
	} else {
		g_Menus[g_MpPlayerNum].unke3c = SAVEDEVICE_INVALID;
	}
}

void func0f1083b0(struct savelocation000 *arg0)
{
	func0f108324(arg0->unk04);
}

void func0f1083d0(struct savelocation000 *arg0, s32 filetype)
{
	g_Menus[g_MpPlayerNum].unke3d = filetype;
	g_Menus[g_MpPlayerNum].unke38 = arg0;
	func0f1083b0(arg0);
}

u16 g_PakFailReasons[] = {
	L_OPTIONS(322), // "The Controller Pak was not found in any controller."
	L_OPTIONS(323), // "File was not saved."
	L_OPTIONS(324), // "File would not load."
	L_OPTIONS(325), // "Could not delete the file."
	L_OPTIONS(326), // "Out of memory."
	L_OPTIONS(327), // "This player is already loaded for this game."
	L_OPTIONS(328), // "has been removed."
	L_OPTIONS(329), // "Controller Pak is damaged or incorrectly inserted."
	L_OPTIONS(330), // "Game note delete failed."
};

char *filemgrMenuTextFailReason(struct menuitem *item)
{
	return langGet(g_PakFailReasons[g_Menus[g_MpPlayerNum].errno]);
}

/**
 * Unused.
 */
char *func0f108484(struct menuitem *item)
{
	sprintf(g_StringPointer, "location: controller pak 1\n");
	return g_StringPointer;
}

s32 filemgrDeviceNameForErrorMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if ((g_Menus[g_MpPlayerNum].unke3c & 0x7f) >= SAVEDEVICE_INVALID) {
			return true;
		}

		switch (g_Menus[g_MpPlayerNum].errno) {
		case FILEERROR_OUTOFMEMORY:
		case FILEERROR_ALREADYLOADED:
		case FILEERROR_PAKDAMAGED:
		default:
			return true;
		case FILEERROR_SAVEFAILED:
		case FILEERROR_LOADFAILED:
		case FILEERROR_DELETEFAILED:
		case FILEERROR_PAKREMOVED:
		case FILEERROR_DELETENOTEFAILED:
			break;
		}
	}

	return false;
}

char *filemgrMenuTextDeviceNameForError(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s", filemgrGetDeviceName(g_Menus[g_MpPlayerNum].unke3c & 0x7f));

	if (g_Menus[g_MpPlayerNum].errno != FILEERROR_PAKREMOVED) {
		s32 i = 0;

		while (g_StringPointer[i] != '\0') {
			i++;
		}

		g_StringPointer[i - 1] = ':';
		g_StringPointer[i] = '\n';
		g_StringPointer[i + 1] = '\0';
	}

	return g_StringPointer;
}

const char var7f1b2f6c[] = "FileMan: Failure Handler\n";
const char var7f1b2f88[] = "Copy Memory Freed\n";
const char var7f1b2f9c[] = "FileMan: Success Handler\n";
const char var7f1b2fb8[] = "Copy Memory Freed\n";
const char var7f1b2fcc[] = ">> block read going write, target file is %x-%x\n";
const char var7f1b3000[] = "SaveElsewhere\n";
const char var7f1b3010[] = "DELETING: %x-%x\n";
const char var7f1b3024[] = "MyResult: %d\n";
const char var7f1b3034[] = "PakOperationSearch>> Search for pak: %x = %d\n";

void filemgrPushErrorDialog(u16 errno)
{
	g_Menus[g_MpPlayerNum].errno = errno;

	menuPushDialog(&g_FilemgrErrorMenuDialog);
}

struct menuitem g_FilemgrErrorMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextDeviceNameForError, 0x00000000, filemgrDeviceNameForErrorMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextFailReason, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(321), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrErrorMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(320), // "Error"
	g_FilemgrErrorMenuItems,
	NULL,
	0x00000080,
	NULL,
};

s32 filemgrGetDeviceNameOrStartIndex(s32 listnum, s32 operation, s32 optionindex)
{
	u16 names[] = {
		L_OPTIONS(111), // "Game Pak"
		L_OPTIONS(112), // "Controller Pak 1"
		L_OPTIONS(113), // "Controller Pak 2"
		L_OPTIONS(114), // "Controller Pak 3"
		L_OPTIONS(115), // "Controller Pak 4"
	};

	s32 i;
	s32 remaining = optionindex;

	for (i = 0; i < ARRAYCOUNT(names); i++) {
		if (g_FileLists[listnum]->devicestartindexes[i] != -1) {
			if (remaining == 0) {
				if (operation == MENUOP_GETOPTGROUPTEXT) {
					return (s32)langGet(names[i]);
				}

				return g_FileLists[listnum]->devicestartindexes[i];
			}

			remaining--;
		}
	}

	return 0;
}

char *filemgrMenuTextErrorTitle(struct menuitem *item)
{
	u16 messages[] = {
		L_OPTIONS(331), // "Error Loading Game"
		L_OPTIONS(332), // "Error Saving Game"
		L_OPTIONS(333), // "Error Loading Player"
		L_OPTIONS(334), // "Error Saving Player"
		L_OPTIONS(335), // "Error Loading PerfectHead"
		L_OPTIONS(336), // "Error Saving PerfectHead"
		L_OPTIONS(337), // "Error Reading File"
		L_OPTIONS(338), // "Error Writing File"
		L_OPTIONS(339), // "Error"
	};

	switch (g_Menus[g_MpPlayerNum].unke42) {
	case 100:
	case 102:
		return langGet(messages[0]);
	case 0:
	case 1:
	case 2:
	case 4:
		return langGet(messages[1]);
	case 101:
		return langGet(messages[2]);
	case 3:
		return langGet(messages[3]);
	case 104:
	case 105:
	case 106:
		return langGet(messages[6]);
	case 6:
	case 7:
	case 8:
		return langGet(messages[7]);
	}

	return langGet(messages[8]);
}

char *filemgrMenuTextFileType(struct menuitem *item)
{
	u16 names[] = {
		L_OPTIONS(103), // "Single Player Agent File"
		L_OPTIONS(104), // "Combat Simulator Settings File"
		L_OPTIONS(105), // "Combat Simulator Player File"
		L_OPTIONS(106), // "PerfectHead Files"
	};

	switch (g_Menus[g_MpPlayerNum].unke42) {
	case 0:
	case 1:
	case 2:
	case 6:
	case 100:
	case 104:
		return langGet(names[0]);
	case 4:
	case 7:
	case 102:
	case 105:
		return langGet(names[1]);
	case 3:
	case 8:
	case 101:
	case 106:
		return langGet(names[2]);
	}

	return langGet(names[0]);
}

void func0f10898c(void)
{
	func0f0f0ca0(-1, false);

	switch (g_Menus[g_MpPlayerNum].unke42) {
	case 6:
	case 7:
	case 8:
	case 104:
	case 105:
	case 106:
		func00012cb4(g_Menus[g_MpPlayerNum].unke44, align16(var7f1b2f3c[g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone - 1]));
		break;
	case 100:
	case 101:
	case 102:
	case 103:
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		break;
	}
}

void func0f108a80(void)
{
	func0f0f0ca0(-1, false);

	switch (g_Menus[g_MpPlayerNum].unke42) {
	case 6:
	case 7:
	case 8:
		func00012cb4(g_Menus[g_MpPlayerNum].unke44,
				align16(var7f1b2f3c[g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone - 1]));
		break;
	case 100:
		g_Vars.unk00047c = g_Menus[g_MpPlayerNum].unke48;
		g_Vars.unk000480 = g_Menus[g_MpPlayerNum].unke4c;
		func0f1109c0();

		if (IS4MB()) {
			func0f0f820c(&g_MainMenu4MbMenuDialog, MENUROOT_4MBMAINMENU);
		} else {
			func0f0f820c(&g_CiMenuViaPcMenuDialog, MENUROOT_MAINMENU);
		}
		break;
	case 104:
	case 105:
	case 106:
		func0f1094e4(&var800a21e8,
				g_Menus[g_MpPlayerNum].unke42 - 98,
				g_Menus[g_MpPlayerNum].unke44);
		break;
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 101:
	case 102:
	case 103:
		break;
	}
}

s32 filemgrRetrySaveMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		filemgrRetrySave(2);
	}

	return 0;
}

s32 filemgrSaveElsewhereYesMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 sp1c;

		menuCloseDialog();

		switch (g_Menus[g_MpPlayerNum].unke42) {
		case 0:
		case 1:
		case 2:
		case 6:
			sp1c = 0;
			break;
		case 3:
		case 8:
			sp1c = 2;
			break;
		case 4:
		case 7:
			sp1c = 1;
			break;
		}

		filemgrPushSelectLocationDialog(g_Menus[g_MpPlayerNum].unke42 + 9, sp1c);
	}

	return 0;
}

s32 filemgrCancelSave2MenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuCloseDialog();
		func0f10898c();
		menuUpdateCurFrame();
	}

	return 0;
}

/**
 * Unused.
 */
s32 func0f108d14(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		filemgrRetrySave(2);
	}

	return 0;
}

s32 filemgrAcknowledgeFileLostMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuCloseDialog();
		func0f10898c();
		menuUpdateCurFrame();
	}

	return 0;
}

void filemgrEraseCorruptFile(void)
{
	s32 value;
	s32 i;

	value = pakSearch(g_Menus[g_MpPlayerNum].unke4c);

	if (value >= 0) {
		filemgrDeleteFile(value, g_Menus[g_MpPlayerNum].unke48);
	}

	for (i = 0; i < 4; i++) {
		if (g_FileLists[i]) {
			g_FileLists[i]->outdated = true;
		}
	}

	menuPushDialog(&g_FilemgrFileLostMenuDialog);
}

s32 filemgrInsertOriginalPakMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curframe &&
				g_Menus[g_MpPlayerNum].curframe->dialog == dialog) {
			filemgrRetrySave(0);
		}
	}

	return false;
}

s32 filemgrReinsertedOkMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		pakExecuteDebugOperations();
		filemgrRetrySave(1);
	}

	return 0;
}

s32 filemgrReinsertedCancelMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_Menus[g_MpPlayerNum].unke42 < 100 && g_Menus[g_MpPlayerNum].unke42 != 1) {
			func0f0f3704(&g_FilemgrSaveElsewhereMenuDialog);
		} else {
			menuPopDialog();
		}
	}

	return 0;
}

char *filemgrMenuTextInsertOriginalPak(struct menuitem *item)
{
	char fullbuffer[100];
	char namebuffer[100];
	s32 i;

	sprintf(namebuffer, filemgrMenuTextFileType(item));

	// Replace first line break in namebuffer with a terminator
	i = 0;

	while (namebuffer[i] != '\0') {
		if (namebuffer[i] == '\n') {
			namebuffer[i] = '\0';
		} else {
			i++;
		}
	}

	// "Please insert the Controller Pak containing your %s into any controller."
	sprintf(fullbuffer, langGet(L_OPTIONS(363)), namebuffer);

	textWrap(120, fullbuffer, g_StringPointer, g_FontHandelGothicSm1, g_FontHandelGothicSm2);

	return g_StringPointer;
}

/**
 * Context is:
 * 0 on tick while reinsert dialog is open
 * 1 when user selects OK on reinsert dialog
 * 2 when user selects Retry Save on error dialog
 */
void filemgrRetrySave(s32 context)
{
	s32 index = pakSearch(g_Menus[g_MpPlayerNum].unke4c);

	if (index == -1) {
		if (context == 1) {
			filemgrPushErrorDialog(FILEERROR_NOPAK);
		}

		if (context == 2) {
			func0f0f3704(&g_PakNotOriginalMenuDialog);
		}
	} else if (fileSave(index, true)) {
		if (context == 2) {
			g_Menus[g_MpPlayerNum].unke3c = index;

			if (g_Menus[g_MpPlayerNum].unke42 < 100) {
				filemgrPushErrorDialog(FILEERROR_SAVEFAILED);
			} else {
				filemgrPushErrorDialog(FILEERROR_LOADFAILED);
			}
		} else {
			func0f108324(g_Menus[g_MpPlayerNum].unke4c);

			if (g_Menus[g_MpPlayerNum].unke42 < 100) {
				func0f0f3704(&g_FilemgrSaveErrorMenuDialog);
			} else {
				filemgrEraseCorruptFile();
			}
		}
	}
}

bool fileSave(s32 arg0, bool arg1)
{
	s32 errno = 0;
	u32 sp40 = (g_Menus[g_MpPlayerNum].isretryingsave & 1) != 0;

	const s32 sp30[] = {0x80, 0x40, 0x20, 0x08};
	s32 sp2c;

	switch (g_Menus[g_MpPlayerNum].unke42) {
	case 2:
		sp40 = 1;
		// fall through
	case 0:
	case 1:
		errno = func0f10feac(arg0,
				g_Menus[g_MpPlayerNum].unke48,
				g_Menus[g_MpPlayerNum].unke4c);
		break;
	case 3:
		errno = func0f18d9fc(
				g_Menus[g_MpPlayerNum].unke44, arg0,
				g_Menus[g_MpPlayerNum].unke48,
				g_Menus[g_MpPlayerNum].unke4c);
		break;
	case 4:
		errno = func0f18e420(arg0,
				g_Menus[g_MpPlayerNum].unke48,
				g_Menus[g_MpPlayerNum].unke4c);
		sp40 = 1;
		break;
	case 6:
	case 7:
	case 8:
		sp2c = 0;
		func0f0d5690(g_Menus[g_MpPlayerNum].unke44, g_Menus[g_MpPlayerNum].unke53);
		errno = func0f116828(arg0,
				g_Menus[g_MpPlayerNum].unke48,
				sp30[g_Menus[g_MpPlayerNum].unke42 - 6],
				g_Menus[g_MpPlayerNum].unke44, &sp2c, 0);
		var80075bd0[g_Menus[g_MpPlayerNum].unke42 - 6] = 1;
		break;
	case 100:
		errno = func0f10fac8(arg0);
		break;
	case 101:
		errno = func0f18dac0(
				g_Menus[g_MpPlayerNum].unke44,
				arg0,
				g_Menus[g_MpPlayerNum].unke48,
				g_Menus[g_MpPlayerNum].unke4c);
		break;
	case 102:
		errno = func0f18e4c8(arg0,
				g_Menus[g_MpPlayerNum].unke48,
				g_Menus[g_MpPlayerNum].unke4c);
		break;
	case 104:
	case 105:
	case 106:
		errno = func0f116800(arg0,
				g_Menus[g_MpPlayerNum].unke48,
				g_Menus[g_MpPlayerNum].unke44, 0);
		break;
	}

	if (errno == 0 && arg1) {
		menuCloseDialog();
	}

	if (g_Menus[g_MpPlayerNum].unke42 < 100) {
		if (errno == 0) {
			func0f108a80();
		}

		if (sp40 && errno == 0) {
			menuPushDialog(&g_FilemgrFileSavedMenuDialog);
		}
	} else {
		if (errno == 0) {
			func0f108a80();
		}
	}

	menuUpdateCurFrame();

	return errno;
}

const char var7f1b3074[] = "FileAttemptOperation - pak %d op %d\n";
const char var7f1b309c[] = ">> blockWrite: file:%x pak:%x\n";
const char var7f1b30bc[] = ">> blockRead: file:%x pak:%x\n";
const char var7f1b30dc[] = "SUCCESS**->%d\n";
const char var7f1b30ec[] = "SUCCESS**->%d\n";
const char var7f1b30fc[] = ">>>>>>>>>>>>> FileWrite: type %d <<<<<<<<<<<<<<<\n";
const char var7f1b3130[] = "!!!!!!!!!!!! Wanted: %d\n";
const char var7f1b314c[] = "&&&&&&&&&&&&&&&&&&&&&&&&&&&PASSED**************\n";
const char var7f1b3180[] = "guid: %x gives pakno: %d\n";
const char var7f1b319c[] = "Invalidating pak %d\n";
const char var7f1b31b4[] = "YOUR TARGET: %x-%x\n";
const char var7f1b31c8[] = "MyResult: %d\n";
const char var7f1b31d8[] = "COULD NOT DELETE\n";
const char var7f1b31ec[] = "Multiplayer %d was using that file...\n";

bool func0f1094e4(struct savelocation_2d8 *arg0, s32 arg1, void *arg2)
{
	s32 value;

	if (arg1 != -1) {
		g_Menus[g_MpPlayerNum].unke42 = arg1;
		g_Menus[g_MpPlayerNum].unke44 = arg2;
		g_Menus[g_MpPlayerNum].isretryingsave = 0;
		var800a21f8.unk00 = 0;
	}

	g_Menus[g_MpPlayerNum].unke48 = arg0->unk00;
	g_Menus[g_MpPlayerNum].unke4c = arg0->unk04;

	if (arg1 != -1) {
		// empty
	}

	value = pakSearch(g_Menus[g_MpPlayerNum].unke4c);

	if (value == -1) {
		g_Menus[g_MpPlayerNum].isretryingsave |= 1;
		menuPushDialog(&g_PakNotOriginalMenuDialog);
		return false;
	}

	if (fileSave(value, false) != 0) {
		g_Menus[g_MpPlayerNum].isretryingsave |= 1;
		func0f108324(g_Menus[g_MpPlayerNum].unke4c);

		if (g_Menus[g_MpPlayerNum].unke42 < 100) {
			menuPushDialog(&g_FilemgrSaveErrorMenuDialog);
		} else {
			filemgrEraseCorruptFile();
		}

		return false;
	}

	return true;
}

void filemgrDeleteCurrentFile(void)
{
	bool error = false;
	s8 index = pakSearch(g_FilemgrFileToDelete.unk04);
	s32 i;

	if (index >= 0) {
		if (filemgrDeleteFile(index, g_FilemgrFileToDelete.unk00)) {
			error = true;
		}
	} else {
		error = true;
	}

	g_FileLists[g_Menus[g_MpPlayerNum].listnum]->outdated = true;

	if (error) {
		g_Menus[g_MpPlayerNum].unke3c = index;
		filemgrPushErrorDialog(FILEERROR_DELETEFAILED);
	} else {
		for (i = 0; i < 4; i++) {
			if (g_FilemgrFileToDelete.unk00 == g_MpPlayers[i].unk4c.unk00
					&& g_FilemgrFileToDelete.unk04 == g_MpPlayers[i].unk4c.unk04) {
				mpPlayerSetDefaults(i, true);
			}
		}
	}
}

struct menuitem g_FilemgrFileSavedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(346), 0x00000000, NULL }, // "File Saved."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(347), 0x00000000, NULL }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrFileSavedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS(345), // "Cool!"
	g_FilemgrFileSavedMenuItems,
	NULL,
	0x00000080,
	NULL,
};

struct menuitem g_FilemgrSaveErrorMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextDeviceName, 0x00000000, filemgrDeviceNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(348), 0x00000000, NULL }, // "An error occurred while trying to save"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(349), 0x00000000, filemgrRetrySaveMenuHandler }, // "Try Again"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(350), 0x00000000, filemgrSaveElsewhereYesMenuHandler }, // "Save Elsewhere"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(351), 0x00000000, filemgrCancelSave2MenuHandler }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrSaveErrorMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(u32)&filemgrMenuTextErrorTitle,
	g_FilemgrSaveErrorMenuItems,
	NULL,
	0x000000a0,
	NULL,
};

struct menuitem g_FilemgrFileLoadMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextDeviceName, 0x00000000, filemgrDeviceNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(251), 0x00000000, NULL }, // "The saved file has been erased due to corruption or damage."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(354), 0x00000000, filemgrAcknowledgeFileLostMenuHandler }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrFileLostMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(u32)&filemgrMenuTextErrorTitle,
	g_FilemgrFileLoadMenuItems,
	NULL,
	0x000000a0,
	NULL,
};

struct menuitem g_FilemgrSaveElsewhereMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(360), 0x00000000, NULL }, // "Would you like to save your file elsewhere?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(361), 0x00000000, filemgrSaveElsewhereYesMenuHandler }, // "Yes"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(362), 0x00000000, filemgrCancelSave2MenuHandler }, // "No"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrSaveElsewhereMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(359), // "Save"
	g_FilemgrSaveElsewhereMenuItems,
	NULL,
	0x000000a0,
	NULL,
};

struct menuitem g_PakNotOriginalMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextInsertOriginalPak, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(365), 0x00000000, filemgrReinsertedOkMenuHandler }, // "OK"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(366), 0x00000000, filemgrReinsertedCancelMenuHandler }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_PakNotOriginalMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(u32)&filemgrMenuTextErrorTitle,
	g_PakNotOriginalMenuItems,
	filemgrInsertOriginalPakMenuDialog,
	0x000000a0,
	NULL,
};

void func0f1097d0(s32 device)
{
	char *types[] = {"GAM", "MPG", "MPP", "CAM"};
	const u32 sizes[] = {0x80, 0x40, 0x20, 0x08};
	void *thing;

	if (g_FileLists[0]) {
		var800a21e8.unk00 = g_FileLists[0]->unk2d8[device].unk00;
		var800a21e8.unk04 = g_FileLists[0]->unk2d8[device].unk04;

		thing = func00012ab0(align16(var7f1b2f3c[g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone - 1]));

		if (thing) {
			func0f1094e4(&g_FilemgrFileToCopy, g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone + 103, thing);
		} else {
			filemgrPushErrorDialog(FILEERROR_OUTOFMEMORY);
		}

		var80075bd0[g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone - 1] = 1;
	}
}

const char var7f1b3234[] = "DestPakNo: %d (guid F:%x-%x:P)\n";
const char var7f1b3254[] = "Copy Memory Alloced\n";
const char var7f1b326c[] = "COULDNT GET THE RAM!\n";
const char var7f1b3284[] = "Saving...\n";

u32 var8007465c = 0x01020304;
u32 var80074660 = 0x00000000;

void func0f109954(s32 arg0)
{
	if (g_FileLists[0]) {
		g_FilemgrLoadedMainFile.unk00 = g_FileLists[0]->unk2d8[arg0].unk00;
		g_FilemgrLoadedMainFile.unk04 = g_FileLists[0]->unk2d8[arg0].unk04;

		func0f1094e4(&g_FilemgrLoadedMainFile, 0, NULL);
	}
}

void func0f1099a8(char *buffer, struct savelocation000 *arg1)
{
	char localbuffer[20];
	u32 sp20;

	localbuffer[0] = '\0';

	switch (g_FileLists[g_Menus[g_MpPlayerNum].listnum]->filetype) {
	case FILETYPE_SOLO:
	case FILETYPE_MPSETUP:
		func0f0d564c(arg1->unk06, localbuffer, 0);
		break;
	case FILETYPE_MPPLAYER:
		func0f18d9a4(arg1->unk06, localbuffer, &sp20);
		break;
	}

	sprintf(buffer, "%s", localbuffer);
}

const char var7f1b3294[] = "GETFileNameForThePurposesOfTheFileRenamingChecker: Unknown type %d\n";

void filemgrGetRenameName(char *buffer)
{
	s32 i;
	s32 j;

	switch (g_Menus[g_MpPlayerNum].unke3e) {
	case 0:
	case 9:
	case 10:
	case 11:
		strcpy(buffer, g_SoloSaveFile.name);
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 15:
	case 16:
	case 17:
		strcpy(buffer, g_Menus[g_MpPlayerNum].unke53);
		break;
	case 6:
	case 12:
		i = 0;
		j = 0;

		while (g_MpPlayers[g_MpPlayerNum].base.name[i] != '\0') {
			if (g_MpPlayers[g_MpPlayerNum].base.name[i] != '\n') {
				buffer[j] = g_MpPlayers[g_MpPlayerNum].base.name[i];
				j++;
			}

			i++;
		}

		buffer[j] = '\0';
		break;
	case 7:
	case 13:
		strcpy(buffer, g_MpSetup.name);
		break;
	}
}

void filemgrSetRenameName(char *name)
{
	switch (g_Menus[g_MpPlayerNum].unke3e) {
	case 0:
	case 9:
	case 10:
	case 11:
		strcpy(g_SoloSaveFile.name, name);
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 15:
	case 16:
	case 17:
		strcpy(g_Menus[g_MpPlayerNum].unke53, name);
		break;
	case 6:
	case 12:
		sprintf(g_MpPlayers[g_MpPlayerNum].base.name, "%s\n", name);
		break;
	case 7:
	case 13:
		strcpy(g_MpSetup.name, name);
		break;
	}
}

const char var7f1b32dc[] = "SetFileNameForThePurposesOfTheFileRenamingChecker: Unknown type %d\n";
const char var7f1b3320[] = "CheckFileName: Comparing range %d-%d\n";
const char var7f1b3348[] = "Compare '%s' to '%s' = %d\n";
const char var7f1b3364[] = "OI! DUPLICATE FILE NAME! NO!\n";
const char var7f1b3384[] = "()()()()()() Writing MPLAYER\n";
const char var7f1b33a4[] = "()()()()()() Writing MGAME\n";
const char var7f1b33c0[] = "Write Attempt Made...\n";
const char var7f1b33d8[] = "decided location: %d\n";

GLOBAL_ASM(
glabel filemgrIsNameAvailable
/*  f109c8c:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f109c90:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f109c94:	3c18800a */ 	lui	$t8,%hi(g_Menus+0xe3f)
/*  f109c98:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f109c9c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f109ca0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f109ca4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f109ca8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f109cac:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f109cb0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f109cb4:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f109cb8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f109cbc:	9318ee3f */ 	lbu	$t8,%lo(g_Menus+0xe3f)($t8)
/*  f109cc0:	3c038007 */ 	lui	$v1,%hi(g_FileLists)
/*  f109cc4:	3c058007 */ 	lui	$a1,%hi(var8007465c)
/*  f109cc8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f109ccc:	00791821 */ 	addu	$v1,$v1,$t9
/*  f109cd0:	8c635bc0 */ 	lw	$v1,%lo(g_FileLists)($v1)
/*  f109cd4:	00a42821 */ 	addu	$a1,$a1,$a0
/*  f109cd8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f109cdc:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f109ce0:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f109ce4:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f109ce8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f109cec:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f109cf0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f109cf4:	14600003 */ 	bnez	$v1,.L0f109d04
/*  f109cf8:	90a5465c */ 	lbu	$a1,%lo(var8007465c)($a1)
/*  f109cfc:	10000068 */ 	b	.L0f109ea0
/*  f109d00:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f109d04:
/*  f109d04:	00654021 */ 	addu	$t0,$v1,$a1
/*  f109d08:	81120300 */ 	lb	$s2,0x300($t0)
/*  f109d0c:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f109d10:	24110004 */ 	addiu	$s1,$zero,0x4
/*  f109d14:	16440003 */ 	bne	$s2,$a0,.L0f109d24
/*  f109d18:	28a10004 */ 	slti	$at,$a1,0x4
/*  f109d1c:	10000060 */ 	b	.L0f109ea0
/*  f109d20:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f109d24:
/*  f109d24:	10200009 */ 	beqz	$at,.L0f109d4c
/*  f109d28:	847502d0 */ 	lh	$s5,0x2d0($v1)
/*  f109d2c:	24620004 */ 	addiu	$v0,$v1,0x4
.L0f109d30:
/*  f109d30:	80430300 */ 	lb	$v1,0x300($v0)
/*  f109d34:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f109d38:	10830002 */ 	beq	$a0,$v1,.L0f109d44
/*  f109d3c:	00000000 */ 	nop
/*  f109d40:	0060a825 */ 	or	$s5,$v1,$zero
.L0f109d44:
/*  f109d44:	14b1fffa */ 	bne	$a1,$s1,.L0f109d30
/*  f109d48:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f109d4c:
/*  f109d4c:	27b40064 */ 	addiu	$s4,$sp,0x64
/*  f109d50:	a3a00064 */ 	sb	$zero,0x64($sp)
/*  f109d54:	0fc4269a */ 	jal	filemgrGetRenameName
/*  f109d58:	02802025 */ 	or	$a0,$s4,$zero
/*  f109d5c:	93a90064 */ 	lbu	$t1,0x64($sp)
/*  f109d60:	27a30064 */ 	addiu	$v1,$sp,0x64
/*  f109d64:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f109d68:	11200011 */ 	beqz	$t1,.L0f109db0
/*  f109d6c:	02408825 */ 	or	$s1,$s2,$zero
/*  f109d70:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f109d74:	28410061 */ 	slti	$at,$v0,0x61
.L0f109d78:
/*  f109d78:	14200005 */ 	bnez	$at,.L0f109d90
/*  f109d7c:	2841007b */ 	slti	$at,$v0,0x7b
/*  f109d80:	10200003 */ 	beqz	$at,.L0f109d90
/*  f109d84:	244bffe0 */ 	addiu	$t3,$v0,-32
/*  f109d88:	a06b0000 */ 	sb	$t3,0x0($v1)
/*  f109d8c:	316200ff */ 	andi	$v0,$t3,0xff
.L0f109d90:
/*  f109d90:	56020004 */ 	bnel	$s0,$v0,.L0f109da4
/*  f109d94:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f109d98:	10000002 */ 	b	.L0f109da4
/*  f109d9c:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f109da0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f109da4:
/*  f109da4:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f109da8:	5440fff3 */ 	bnezl	$v0,.L0f109d78
/*  f109dac:	28410061 */ 	slti	$at,$v0,0x61
.L0f109db0:
/*  f109db0:	0255082a */ 	slt	$at,$s2,$s5
/*  f109db4:	10200039 */ 	beqz	$at,.L0f109e9c
/*  f109db8:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f109dbc:	00129080 */ 	sll	$s2,$s2,0x2
/*  f109dc0:	02519023 */ 	subu	$s2,$s2,$s1
/*  f109dc4:	001290c0 */ 	sll	$s2,$s2,0x3
/*  f109dc8:	27b30040 */ 	addiu	$s3,$sp,0x40
.L0f109dcc:
/*  f109dcc:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f109dd0:	8d8c1448 */ 	lw	$t4,%lo(g_MpPlayerNum)($t4)
/*  f109dd4:	3c0e800a */ 	lui	$t6,%hi(g_Menus+0xe3f)
/*  f109dd8:	3c188007 */ 	lui	$t8,%hi(g_FileLists)
/*  f109ddc:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f109de0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f109de4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f109de8:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f109dec:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f109df0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f109df4:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f109df8:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f109dfc:	91ceee3f */ 	lbu	$t6,%lo(g_Menus+0xe3f)($t6)
/*  f109e00:	02602025 */ 	or	$a0,$s3,$zero
/*  f109e04:	00001025 */ 	or	$v0,$zero,$zero
/*  f109e08:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f109e0c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f109e10:	8f185bc0 */ 	lw	$t8,%lo(g_FileLists)($t8)
/*  f109e14:	0fc4266a */ 	jal	func0f1099a8
/*  f109e18:	03122821 */ 	addu	$a1,$t8,$s2
/*  f109e1c:	93b90040 */ 	lbu	$t9,0x40($sp)
/*  f109e20:	27a30040 */ 	addiu	$v1,$sp,0x40
/*  f109e24:	02802025 */ 	or	$a0,$s4,$zero
/*  f109e28:	13200011 */ 	beqz	$t9,.L0f109e70
/*  f109e2c:	00000000 */ 	nop
/*  f109e30:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f109e34:	28410061 */ 	slti	$at,$v0,0x61
.L0f109e38:
/*  f109e38:	14200005 */ 	bnez	$at,.L0f109e50
/*  f109e3c:	2841007b */ 	slti	$at,$v0,0x7b
/*  f109e40:	10200003 */ 	beqz	$at,.L0f109e50
/*  f109e44:	2449ffe0 */ 	addiu	$t1,$v0,-32
/*  f109e48:	a0690000 */ 	sb	$t1,0x0($v1)
/*  f109e4c:	312200ff */ 	andi	$v0,$t1,0xff
.L0f109e50:
/*  f109e50:	56020004 */ 	bnel	$s0,$v0,.L0f109e64
/*  f109e54:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f109e58:	10000002 */ 	b	.L0f109e64
/*  f109e5c:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f109e60:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f109e64:
/*  f109e64:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f109e68:	5440fff3 */ 	bnezl	$v0,.L0f109e38
/*  f109e6c:	28410061 */ 	slti	$at,$v0,0x61
.L0f109e70:
/*  f109e70:	0c004c9d */ 	jal	strcmp
/*  f109e74:	02602825 */ 	or	$a1,$s3,$zero
/*  f109e78:	02802025 */ 	or	$a0,$s4,$zero
/*  f109e7c:	0c004c9d */ 	jal	strcmp
/*  f109e80:	02602825 */ 	or	$a1,$s3,$zero
/*  f109e84:	14400003 */ 	bnez	$v0,.L0f109e94
/*  f109e88:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f109e8c:	10000004 */ 	b	.L0f109ea0
/*  f109e90:	00001025 */ 	or	$v0,$zero,$zero
.L0f109e94:
/*  f109e94:	1635ffcd */ 	bne	$s1,$s5,.L0f109dcc
/*  f109e98:	26520018 */ 	addiu	$s2,$s2,0x18
.L0f109e9c:
/*  f109e9c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f109ea0:
/*  f109ea0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f109ea4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f109ea8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f109eac:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f109eb0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f109eb4:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f109eb8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f109ebc:	03e00008 */ 	jr	$ra
/*  f109ec0:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

void func0f109ec4(void)
{
	if (g_FileLists[g_Menus[g_MpPlayerNum].listnum]->spacesfree[g_Menus[g_MpPlayerNum].device] > 0) {
		if (!filemgrIsNameAvailable(g_Menus[g_MpPlayerNum].device)) {
			menuPushDialog(&g_FilemgrDuplicateNameMenuDialog);
		} else {
			menuPopDialog();

			if (g_Menus[g_MpPlayerNum].unke3e == 0) {
				func0f109954(g_Menus[g_MpPlayerNum].device);
			} else if (g_Menus[g_MpPlayerNum].unke3e == 5) {
				// empty
			} else if (g_Menus[g_MpPlayerNum].unke3e == 6) {
				struct savelocation_2d8 thing;
				thing.unk00 = g_FileLists[g_Menus[g_MpPlayerNum].listnum]->unk2d8[g_Menus[g_MpPlayerNum].device].unk00;
				thing.unk04 = g_FileLists[g_Menus[g_MpPlayerNum].listnum]->unk2d8[g_Menus[g_MpPlayerNum].device].unk04;
				func0f1094e4(&thing, 3, (void *)g_MpPlayerNum);
			} else if (g_Menus[g_MpPlayerNum].unke3e == 7) {
				struct savelocation_2d8 thing;
				thing.unk00 = g_FileLists[g_Menus[g_MpPlayerNum].listnum]->unk2d8[g_Menus[g_MpPlayerNum].device].unk00;
				thing.unk04 = g_FileLists[g_Menus[g_MpPlayerNum].listnum]->unk2d8[g_Menus[g_MpPlayerNum].device].unk04;
				func0f1094e4(&thing, 4, NULL);
			} else if (g_Menus[g_MpPlayerNum].unke3e >= 9) {
				struct savelocation_2d8 thing;
				thing.unk00 = g_FileLists[g_Menus[g_MpPlayerNum].listnum]->unk2d8[g_Menus[g_MpPlayerNum].device].unk00;
				thing.unk04 = g_FileLists[g_Menus[g_MpPlayerNum].listnum]->unk2d8[g_Menus[g_MpPlayerNum].device].unk04;
				func0f1094e4(&thing, -1, NULL);
			} else {
				func0f1097d0(g_Menus[g_MpPlayerNum].device);
			}
		}
	}
}

s32 filemgrConfirmRenameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	char *name = data->keyboard.string;

	switch (operation) {
	case MENUOP_GETTEXT:
		filemgrGetRenameName(name);
		break;
	case MENUOP_SETTEXT:
		filemgrSetRenameName(name);
		break;
	case MENUOP_SET:
		func0f109ec4();
		break;
	}

	return 0;
}

s32 filemgrDuplicateRenameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPushDialog(&g_FilemgrRenameMenuDialog);
	}

	return 0;
}

s32 filemgrDuplicateCancelMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();
	}

	return 0;
}

char *filemgrMenuTextDeviceNameContainingDuplicateFile(struct menuitem *item)
{
	return filemgrGetDeviceName(g_Menus[g_MpPlayerNum].device);
}

char *filemgrMenuTextDuplicateFileName(struct menuitem *item)
{
	char buffer[32];

	filemgrGetRenameName(buffer);
	sprintf(g_StringPointer, "%s\n", buffer);

	return g_StringPointer;
}

struct menuitem g_FilemgrRenameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(239), 0x00000000, NULL }, // "Enter new file name:"
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, filemgrConfirmRenameMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrRenameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(238), // "Change File Name"
	g_FilemgrRenameMenuItems,
	NULL,
	0x00000080,
	NULL,
};

struct menuitem g_FilemgrDuplicateMenuMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&filemgrMenuTextDeviceNameContainingDuplicateFile, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS(233), 0x00000000, NULL }, // "already contains"
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS(234), 0x00000000, NULL }, // "a file named"
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, (u32)&filemgrMenuTextDuplicateFileName, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPWEAPONS(235), 0x00000000, filemgrDuplicateRenameMenuHandler }, // "Rename File"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPWEAPONS(236), 0x00000000, NULL }, // "Change Location"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPWEAPONS(237), 0x00000000, filemgrDuplicateCancelMenuHandler }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrDuplicateNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(232), // "Duplicate File Name"
	g_FilemgrDuplicateMenuMenuItems,
	NULL,
	0x00000080,
	NULL,
};

char *filemgrMenuTextLocationName2(struct menuitem *item)
{
	u16 names[] = {
		L_OPTIONS(112), // "Controller Pak 1"
		L_OPTIONS(113), // "Controller Pak 2"
		L_OPTIONS(114), // "Controller Pak 3"
		L_OPTIONS(115), // "Controller Pak 4"
		L_OPTIONS(111), // "Game Pak"
		L_OPTIONS(4),   // ""
	};

	if (g_FileLists[g_Menus[g_MpPlayerNum].listnum] == NULL) {
		return NULL;
	}

	if (g_FileLists[g_Menus[g_MpPlayerNum].listnum]->spacesfree[item->param] < 0) {
		return langGet(names[5]);
	}

	return langGet(names[item->param]);
}

char *filemgrMenuTextSaveLocationSpaces(struct menuitem *item)
{
	s32 spacesfree;

	if (g_FileLists[g_Menus[g_MpPlayerNum].listnum] == NULL) {
		return NULL;
	}

	spacesfree = g_FileLists[g_Menus[g_MpPlayerNum].listnum]->spacesfree[item->param];

	if (spacesfree < 0) {
		return "\n";
	}

	if (spacesfree == 0) {
		return langGet(L_OPTIONS(372)); // "Full"
	}

	sprintf(g_StringPointer, "%d", spacesfree);
	return g_StringPointer;
}

const char var7f1b33fc[] = "GOT OKed!, item->data = %d\n";
const char var7f1b3418[] = "GOT CANCELLED!\n";
const char var7f1b3428[] = "Picking Location, type %d wadtype %d wad %d\n";
const char var7f1b3458[] = "Torching file %d\n";
const char var7f1b346c[] = "Copying file %d\n";
const char var7f1b3480[] = "item: %x\n";
const char var7f1b348c[] = "Switched Wads Back\n";
const char var7f1b34a0[] = "MenuClosed\n";
const char var7f1b34ac[] = "Deleting files, wad %d\n";

/**
 * item->param is a SAVEDEVICE constant.
 */
s32 filemgrSelectLocationMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (g_FileLists[g_Menus[g_MpPlayerNum].listnum] == NULL) {
		return 0;
	}

	if (operation == MENUOP_CHECKDISABLED) {
		if (g_FileLists[g_Menus[g_MpPlayerNum].listnum]->spacesfree[item->param] < 1) {
			return true;
		}
	}

	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].device = item->param;
		func0f109ec4();
	}

	return 0;
}

s32 filemgrCancelSaveMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
	}

	return 0;
}

s32 filemgrDeleteFilesForSaveMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		filemgrPushDeleteFileDialog(g_Menus[g_MpPlayerNum].listnum);
		g_Menus[g_MpPlayerNum].data.filemgr.isdeletingforsave = true;
	}

	return 0;
}

void filemgrPushSelectLocationDialog(s32 arg0, u32 arg1)
{
	g_Menus[g_MpPlayerNum].unke3e = arg0;
	g_Menus[g_MpPlayerNum].listnum = func0f110cf8(arg1);

	func0f110da8();

	menuPushDialog(&g_FilemgrSelectLocationMenuDialog);
}

s32 filemgrConfirmDeleteMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		filemgrDeleteCurrentFile();
	}

	return 0;
}

char *filemgrMenuTextFileInUseDescription(struct menuitem *item)
{
	if (menuIsDialogOpen(&g_FilemgrCopyMenuDialog)) {
		return langGet(L_MPWEAPONS(240)); // "The file you are copying cannot be deleted."
	}

	return langGet(L_MPWEAPONS(160)); // "Cannot delete file as it is being used."
}

Gfx *filemgrRenderPerfectHeadThumbnail(Gfx *gdl, struct menuitemrenderdata *renderdata, u32 arg2, u32 arg3)
{
	struct textureconfig *texture = func0f111460(g_MpPlayerNum, arg2, arg3 & 0xffff);

	if (texture) {
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061360);

		gDPPipeSync(gdl++);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);

		func0f0b39c0(&gdl, texture, 1, 0, 2, 1, 0);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetTextureFilter(gdl++, G_TF_POINT);
		gDPSetEnvColor(gdl++, 0xff, 0xff, 0xff, renderdata->colour);

		gDPSetCombineLERP(gdl++,
				TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0);

		gDPLoadSync(gdl++);
		gDPTileSync(gdl++);

		gSPTextureRectangle(gdl++,
				((renderdata->x + 4) << 2) * g_ScaleX,
				(renderdata->y + 2) << 2,
				((renderdata->x + 20) << 2) * g_ScaleX,
				(renderdata->y + 18) << 2,
				G_TX_RENDERTILE, 0, 512, 1024 / g_ScaleX, -1024);

		gDPLoadSync(gdl++);
		gDPTileSync(gdl++);
		gDPPipeSync(gdl++);

		if (arg3) {
			// empty
		}
	}

	return gdl;
}

bool filemgrIsFileInUse(struct savelocation000 *arg0)
{
	s32 i;

	if (menuIsDialogOpen(&g_FilemgrCopyMenuDialog)
			&& arg0->unk00 == g_FilemgrFileToCopy.unk00
			&& arg0->unk04 == g_FilemgrFileToCopy.unk04) {
		return true;
	}

	if (menuIsDialogOpen(&g_FilemgrFileSelect4MbMenuDialog)) {
		return false;
	}

	if (g_MenuData.root == MENUROOT_FILEMGR) {
		return false;
	}

	if (arg0->unk00 == g_FilemgrLoadedMainFile.unk00 && arg0->unk04 == g_FilemgrLoadedMainFile.unk04) {
		return true;
	}

	if (arg0->unk00 == g_MpSetup.unk20.unk00 && arg0->unk04 == g_MpSetup.unk20.unk04) {
		return true;
	}

	for (i = 0; i < 4; i++) {
		if ((g_MpSetup.chrslots & (1 << i))
				&& g_MpPlayers[i].unk4c.unk00 == arg0->unk00
				&& g_MpPlayers[i].unk4c.unk04 == arg0->unk04) {
			return true;
		}
	}

	return false;
}

/**
 * item->param is 0 if copying, 1 if deleting.
 */
s32 filemgrFileToCopyOrDeleteListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data, bool isdelete)
{
	s32 x;
	s32 y;
	struct filelist *list = g_FileLists[0];
	s32 listnum = 0;

	if (item->param == 1) {
		listnum = g_Menus[g_MpPlayerNum].listnum;
		list = g_FileLists[g_Menus[g_MpPlayerNum].listnum];
	}

	if (list == NULL) {
		return 0;
	}

	switch (operation) {
	case MENUOP_GETOPTIONVALUE:
		data->list.value = 0x0fffff;
		break;
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = list->numfiles;
		break;
	case MENUOP_RENDER:
		{
			Gfx *gdl = data->type19.gdl;
			struct menuitemrenderdata *renderdata = data->type19.renderdata2;
			struct savelocation000 *location000 = &list->unk000[data->list.unk04];

			if (g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone == 4) {
				gdl = filemgrRenderPerfectHeadThumbnail(gdl, renderdata, location000->unk00, location000->unk04);
			} else {
				u32 colour = renderdata->colour;
				char text[32];

				if (isdelete && filemgrIsFileInUse(location000)) {
					colour = 0xff333300 | (colour & 0xff);
				}

				x = renderdata->x + 2;
				y = renderdata->y + 2;

				gdl = func0f153628(gdl);

				if (location000) {
					filemgrGetFileName(text, location000, g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone - 1);
					gdl = textRenderProjected(gdl, &x, &y, text, g_FontHandelGothicSm1, g_FontHandelGothicSm2,
							colour, viGetWidth(), viGetHeight(), 0, 1);
					y = renderdata->y + 12;
					x = renderdata->x + 2;
				}

				gdl = func0f153780(gdl);
			}

			return (u32)gdl;
		}
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = 11;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = list->unk30a;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return filemgrGetDeviceNameOrStartIndex(listnum, operation, data->list.value);
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = filemgrGetDeviceNameOrStartIndex(listnum, operation, data->list.value);
		return 0;
	}

	return 0;
}

s32 filemgrFileToDeleteListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (g_FileLists[g_Menus[g_MpPlayerNum].listnum] == NULL) {
		return 0;
	}

	if (operation == MENUOP_SET) {
		struct savelocation000 *thing = &g_FileLists[g_Menus[g_MpPlayerNum].listnum]->unk000[data->list.value];

		if (thing) {
			if (filemgrIsFileInUse(thing)) {
				func0f1083d0(thing, g_FileLists[g_Menus[g_MpPlayerNum].listnum]->filetype);
				menuPushDialog(&g_FilemgrFileInUseMenuDialog);
			} else {
				func0f1083d0(thing, g_FileLists[g_Menus[g_MpPlayerNum].listnum]->filetype);
				g_FilemgrFileToDelete.unk00 = thing->unk00;
				g_FilemgrFileToDelete.unk04 = thing->unk04;
				menuPushDialog(&g_FilemgrConfirmDeleteMenuDialog);
			}
		}
	}

	return filemgrFileToCopyOrDeleteListMenuHandler(operation, item, data, true);
}

s32 filemgrFileToCopyListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct filelist *list = g_FileLists[0];

	if (list == NULL) {
		return 0;
	}

	if (operation == MENUOP_SET) {
		struct savelocation000 *thing = &list->unk000[data->list.value];

		if (thing) {
			g_FilemgrFileToCopy.unk00 = thing->unk00;
			g_FilemgrFileToCopy.unk04 = thing->unk04;

			func0f1099a8(g_Menus[g_MpPlayerNum].unke53, thing);
			filemgrPushSelectLocationDialog(g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone, g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone - 1);
		}
	}

	return filemgrFileToCopyOrDeleteListMenuHandler(operation, item, data, false);
}

s32 filemgrCopyOrDeleteListMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_CLOSE) {
		if (g_Menus[g_MpPlayerNum].data.filemgr.isdeletingforsave == true) {
			g_Menus[g_MpPlayerNum].data.filemgr.isdeletingforsave = false;
		} else {
			func0f110c5c(0, FILETYPE_SOLO);
			g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone = 0;
		}
	}

	return 0;
}

void filemgrPushDeleteFileDialog(s32 listnum)
{
	struct filelist *list;

	g_Menus[g_MpPlayerNum].listnum = listnum;
	g_Menus[g_MpPlayerNum].data.filemgr.isdeletingforsave = false;
	g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone = 1;

	list = g_FileLists[g_Menus[g_MpPlayerNum].listnum];

	if (list) {
		g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone = list->filetype + 1;
	}

	menuPushDialog(&g_FilemgrDeleteMenuDialog);
}

s32 pakDeleteGameNoteMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		OSPfsState *note = &g_EditingPak->notes[g_Menus[g_MpPlayerNum].data.pak.noteindex];
		s32 result;

		g_Menus[g_MpPlayerNum].data.pak.unke24 = g_Menus[g_MpPlayerNum].data.pak.unke24 | (1 << g_Menus[g_MpPlayerNum].data.pak.device);

		menuPopDialog();

		result = pakDeleteGameNote(g_Menus[g_MpPlayerNum].data.pak.device,
				note->company_code, note->game_code, note->game_name, note->ext_name);

		g_Menus[g_MpPlayerNum].unke3c = g_Menus[g_MpPlayerNum].data.pak.device;

		if (result) {
			filemgrPushErrorDialog(FILEERROR_DELETENOTEFAILED);
		}
	}

	return 0;
}

s32 pakGameNoteListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 x;
	s32 y;
	Gfx *gdl;
	struct menuitemrenderdata *renderdata;
	OSPfsState *note;
	char tmpname[40];
	char tmpext[12];
	char generalbuffer[60];
	char extbuffer[60];
	char pagesbuffer[60];
	s32 textwidth;
	s32 textheight;

	if (g_EditingPak == NULL) {
		return 0;
	}

	switch (operation) {
	case MENUOP_GETOPTIONVALUE:
		data->list.value = 0x0fffff;
		break;
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = 16;
		break;
	case MENUOP_RENDER:
		gdl = data->type19.gdl;
		renderdata = data->type19.renderdata2;
		note = &g_EditingPak->notes[data->list.unk04];

		// Render note number (1-16)
		sprintf(generalbuffer, "%d:\n", data->list.unk04 + 1);
		x = renderdata->x + 4;
		y = renderdata->y + 1;
		gdl = textRenderProjected(gdl, &x, &y, generalbuffer, g_FontHandelGothicSm1, g_FontHandelGothicSm2,
				renderdata->colour, viGetWidth(), viGetHeight(), 0, 1);

		// Prepare buffers for remaining text
		if (g_EditingPak->notesinuse[data->list.unk04] == 1) {
			func0f11e618(note->game_name, tmpname, 16);
			func0f11e618(note->ext_name, tmpext, 4);

			tmpext[1] = '\0';

			sprintf(generalbuffer, "%s\n", tmpname);
			sprintf(extbuffer, "%s\n", tmpext);
			sprintf(pagesbuffer, "%d\n", note->file_size / 256);
		} else {
			sprintf(generalbuffer, langGet(L_OPTIONS(392))); // "Empty"
			sprintf(pagesbuffer, langGet(L_OPTIONS(393))); // "--"
			sprintf(extbuffer, "", tmpname, tmpext);
		}

		// Render note name
		x = renderdata->x + 20;
		y = renderdata->y + 1;
		gdl = textRenderProjected(gdl, &x, &y, generalbuffer, g_FontHandelGothicSm1, g_FontHandelGothicSm2,
				renderdata->colour, viGetWidth(), viGetHeight(), 0, 1);

		// Render ext character (for when a game has multiple notes)
		x = renderdata->x + 190;
		y = renderdata->y + 1;
		gdl = textRenderProjected(gdl, &x, &y, extbuffer, g_FontHandelGothicSm1, g_FontHandelGothicSm2,
				renderdata->colour, viGetWidth(), viGetHeight(), 0, 1);

		// Render number of pages
		textMeasure(&textheight, &textwidth, pagesbuffer, g_FontHandelGothicSm1, g_FontHandelGothicSm2, 0);

		x = renderdata->x + renderdata->width - textwidth - 6;
		y = renderdata->y + 1;
		gdl = textRenderProjected(gdl, &x, &y, pagesbuffer, g_FontHandelGothicSm1, g_FontHandelGothicSm2,
				renderdata->colour, viGetWidth(), viGetHeight(), 0, 1);

		return (u32)gdl;
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = 11;
		break;
	case MENUOP_SET:
		if (g_EditingPak->notesinuse[data->list.value] == true) {
			g_Menus[g_MpPlayerNum].data.pak.noteindex = data->list.value;
			menuPushDialog(&g_PakDeleteNoteMenuDialog);
		}
		break;
	}

	return 0;
}

const char var7f1b34dc[] = "GOT OKed!\n";
const char var7f1b34e8[] = "Try to find last opened file...\n";

s32 pakGameNotesMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curframe
				&& g_Menus[g_MpPlayerNum].curframe->dialog == dialog) {
			s32 value = func0f1168c4(g_Menus[g_MpPlayerNum].data.pak.device, &g_EditingPak);

			if (value) {
				menuCloseDialog();
				g_EditingPak = NULL;
				g_Menus[g_MpPlayerNum].unke3c = g_Menus[g_MpPlayerNum].data.pak.device;

				if (value == 1) {
					filemgrPushErrorDialog(FILEERROR_PAKREMOVED);
				}

				menuUpdateCurFrame();
			}
		}
	}

	return 0;
}

char *pakMenuTextPagesFree(struct menuitem *item)
{
	if (g_EditingPak == NULL) {
		sprintf(g_StringPointer, langGet(L_OPTIONS(394))); // "Pages Free: "
	} else {
		sprintf(g_StringPointer, langGet(L_OPTIONS(395)), g_EditingPak->pagesfree); // "Pages Free: %d"
	}

	return g_StringPointer;
}

char *pakMenuTextPagesUsed(struct menuitem *item)
{
	if (g_EditingPak == NULL) {
		sprintf(g_StringPointer2, langGet(L_OPTIONS(396))); // "Pages Used: "
	} else {
		sprintf(g_StringPointer2, langGet(L_OPTIONS(397)), g_EditingPak->pagesused); // "Pages Used: %d"
	}

	return g_StringPointer2;
}

char *pakMenuTextStatusMessage(struct menuitem *item)
{
	ubool haspdnote = false;
	ubool hasemptynote = false;
	s32 i;

	if (g_EditingPak == NULL) {
		return langGet(L_OPTIONS(398)); // "Perfect Dark note already exists on this Controller Pak."
	}

	for (i = 0; i < ARRAYCOUNT(g_EditingPak->notes); i++) {
		if (g_EditingPak->notesinuse[i] == true) {
			if (g_EditingPak->notes[i].company_code == ROM_COMPANYCODE
					&& g_EditingPak->notes[i].game_code == ROM_GAMECODE) {
				haspdnote = true;
			}
		} else {
			hasemptynote = true;
		}
	}

	if (haspdnote) {
		return langGet(L_OPTIONS(398)); // "Perfect Dark note already exists on this Controller Pak."
	}

	if (g_EditingPak->pagesfree < 28 || !hasemptynote) {
		return langGet(L_OPTIONS(400)); // "Controller Pak is too full to save note- 1 note and 28 pages required to save to Controller Pak."
	}

	return langGet(L_OPTIONS(399)); // "There is enough space for Perfect Dark note."
}

char *pakMenuTextEditingPakName(struct menuitem *item)
{
	return filemgrGetDeviceName(g_Menus[g_MpPlayerNum].data.pak.device);
}

s32 pakSelectionMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if (!pakIsConnected((s8)item->param)) {
			return true;
		}
	}

	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].data.pak.device = item->param;
		menuPushDialog(&g_PakGameNotesMenuDialog);
	}

	return 0;
}

s32 pakChoosePakMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		func0001398c(3);
		g_Menus[g_MpPlayerNum].data.pak.unke24 = 0;
		break;
	case MENUOP_TICK:
		var80062944 = 1;
		break;
	case MENUOP_CLOSE:
		if (g_Vars.stagenum != STAGE_BOOTPAKMENU) {
			s32 i;

			for (i = 0; i < 4; i++) {
				if (g_Menus[g_MpPlayerNum].data.pak.unke24 & (1 << i)) {
					g_Vars.unk0004e4 &= 0xfff0;
					g_Vars.unk0004e4 |= 0x0008;
					g_Vars.unk0004e4 |= 1 << (i + 8);
				}
			}
		}
		func000139c8();
		break;
	}

	return 0;
}

s32 filemgrOpenCopyFileMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone = item->param + 1;
		func0f110c5c(0, item->param);
		g_Menus[g_MpPlayerNum].listnum = 0;
		g_Menus[g_MpPlayerNum].data.filemgr.isdeletingforsave = false;
		menuPushDialog(&g_FilemgrCopyMenuDialog);
	}

	return 0;
}

s32 filemgrOpenDeleteFileMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone = item->param + 1;
		func0f110c5c(0, item->param);
		g_Menus[g_MpPlayerNum].unke3e = -1;
		filemgrPushDeleteFileDialog(0);
	}

	return 0;
}

s32 filemgrAgentNameKeyboardMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	char *name = data->keyboard.string;

	if (!g_FileLists[0]) {
		return 0;
	}

	switch (operation) {
	case MENUOP_GETTEXT:
		strcpy(name, g_SoloSaveFile.name);
		break;
	case MENUOP_SETTEXT:
		strcpy(g_SoloSaveFile.name, name);
		break;
	case MENUOP_SET:
		filemgrPushSelectLocationDialog(0, 0);
		g_Menus[g_MpPlayerNum].data.filemgr.unke2c = 1;
		break;
	}

	return 0;
}

s32 filemgrChooseAgentListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 x;
	s32 y;
	s32 pass;
	s32 i;
	s32 j;
	Gfx *gdl;
	struct menuitemrenderdata *renderdata;
	s32 texturenum;
	struct savelocation000 *location000;
	char name[12];
	u8 stage;
	u8 difficulty;
	u32 time;
	s32 days;
	s32 hours;
	s32 minutes;
	s32 seconds;
	char buffer[100];
	s32 textwidth;
	s32 textheight;

	if (g_FileLists[0] == NULL) {
		return 0;
	}

	switch (operation) {
	case MENUOP_GETOPTIONVALUE:
		data->list.value = 0x0fffff;
		break;
	case MENUOP_25:
		pass = false;

		if (data->list.unk04 == 1) {
			if (data->list.groupstartindex == 1 && g_Menus[g_MpPlayerNum].data.filemgr.unke2c == 1) {
				for (i = 0; i < g_FileLists[0]->numfiles; i++) {
					if (g_FilemgrLoadedMainFile.unk00 == g_FileLists[0]->unk000[i].unk00
							&& g_FilemgrLoadedMainFile.unk04 == g_FileLists[0]->unk000[i].unk04) {
						data->list.value = i;
					}
				}

				g_Menus[g_MpPlayerNum].data.filemgr.unke2c = 0;
			}

			if (g_FileLists[0]->unk30e) {
				pass = true;
			}
		} else {
			pass = true;
			g_Menus[g_MpPlayerNum].data.filemgr.unke2c = 0;
		}

		if (pass && g_Vars.unk00047c) {
			for (j = 0; j < g_FileLists[0]->numfiles; j++) {
				if (g_Vars.unk00047c == g_FileLists[0]->unk000[j].unk00
						&& g_Vars.unk000480 == g_FileLists[0]->unk000[j].unk04) {
					data->list.value = j;
					g_Vars.unk00047c = 0;
				}
			}
		}
		break;
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = g_FileLists[0]->numfiles + 1;
		break;
	case MENUOP_RENDER:
		gdl = data->type19.gdl;
		texturenum = 12;
		location000 = NULL;
		renderdata = data->type19.renderdata2;
		seconds = 0;
		minutes = 0;
		hours = 0;
		days = 0;

		if (data->list.unk04 != g_FileLists[0]->numfiles) {
			location000 = &g_FileLists[0]->unk000[data->list.unk04];

			if (location000) {
				savefileGetOverview(location000->unk06, name, &stage, &difficulty, &time);

				seconds = time % 60;
				time = time / 60;

				// The stage returned by the above function is offset by 1.
				// 0 = New recruit
				// 1 = Defection
				// ...
				// This is correctly capping it to Skedar Ruins
				if (stage > SOLOSTAGEINDEX_SKEDARRUINS + 1) {
					stage = SOLOSTAGEINDEX_SKEDARRUINS + 1;
				}

				if (difficulty > DIFF_PA) {
					difficulty = DIFF_PA;
				}

				texturenum = stage + 12;

				days = time / 1440;
				hours = (time - days * 1440) / 60;
				minutes = (time - days * 1440) - hours * 60;
			}
		}

		gDPPipeSync(gdl++);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);

		func0f0b39c0(&gdl, &var800ab5a8[texturenum], 2, 0, 2, 1, 0);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetTextureFilter(gdl++, G_TF_POINT);
		gDPSetEnvColor(gdl++, 0xff, 0xff, 0xff, renderdata->colour);
		gDPSetCombineLERP(gdl++,
				TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0);

		gSPTextureRectangle(gdl++,
				((renderdata->x + 4) << 2) * g_ScaleX,
				(renderdata->y + 2) << 2,
				((renderdata->x + 60) << 2) * g_ScaleX,
				(renderdata->y + 38) << 2,
				G_TX_RENDERTILE, 0, 1152, 1024 / g_ScaleX, -1024);

		x = renderdata->x + 62;
		y = renderdata->y + 4;
		gdl = func0f153628(gdl);

		if (data->list.unk04 == g_FileLists[0]->numfiles) {
			// "New Agent..."
			gdl = textRenderProjected(gdl, &x, &y, langGet(L_OPTIONS(403)),
					g_FontHandelGothicMd1, g_FontHandelGothicMd2, renderdata->colour, viGetWidth(), viGetHeight(), 0, 0);
		} else {
			if (location000) {
				// Render file name
				gdl = textRenderProjected(gdl, &x, &y, name,
						g_FontHandelGothicMd1, g_FontHandelGothicMd2, renderdata->colour, viGetWidth(), viGetHeight(), 0, 1);

				// Prepare and render stage name
				y = renderdata->y + 18;
				x = renderdata->x + 62;

				if (stage > 0) {
					sprintf(buffer, "%s %s",
							langGet(g_StageNames[stage - 1].name1),
							langGet(g_StageNames[stage - 1].name2));
				} else {
					// "New Recruit"
					strcpy(buffer, langGet(L_OPTIONS(404)));
				}

				strcat(buffer, "\n");
				gdl = textRenderProjected(gdl, &x, &y, buffer,
						g_FontHandelGothicSm1, g_FontHandelGothicSm2, renderdata->colour, viGetWidth(), viGetHeight(), 0, 0);

				// Prepare and render mission time
				x = renderdata->x + 62;
				y++;

				if (days > 0) {
					// "Mission Time:"
					sprintf(buffer, "%s %d:%02d:%02d", langGet(L_OPTIONS(405)), days, hours, minutes);
				} else {
					// "Mission Time:"
					sprintf(buffer, "%s %02d:%02d", langGet(L_OPTIONS(405)), hours, minutes);
				}

				// Useless - textwidth and textheight are not used
				textMeasure(&textheight, &textwidth, buffer, g_FontHandelGothicSm1, g_FontHandelGothicSm2, 0);

				gdl = textRenderProjected(gdl, &x, &y, buffer,
						g_FontHandelGothicSm1, g_FontHandelGothicSm2, renderdata->colour, viGetWidth(), viGetHeight(), 0, 0);

				// Render seconds part of mission time (uses a smaller font)
				y++;
				x++;
				sprintf(buffer, ".%02d", seconds);
				gdl = textRenderProjected(gdl, &x, &y, buffer,
						g_FontHandelGothicXs1, g_FontHandelGothicXs2, renderdata->colour, viGetWidth(), viGetHeight(), 0, 0);
			}
		}
		gdl = func0f153780(gdl);
		return (u32) gdl;
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = 40;
		break;
	case MENUOP_SET:
		if (data->list.value == g_FileLists[0]->numfiles) {
			savefileLoadDefaults(&g_SoloSaveFile);
			menuPushDialog(&g_FilemgrEnterNameMenuDialog);
		} else {
			struct savelocation000 *file = &g_FileLists[0]->unk000[data->list.value];

			if (file) {
				g_FilemgrLoadedMainFile.unk00 = file->unk00;
				g_FilemgrLoadedMainFile.unk04 = file->unk04;
				func0f1094e4(&g_FilemgrLoadedMainFile, 100, 0);
			}
		}
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = g_FileLists[0]->unk30a + 1;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		if (data->list.value >= g_FileLists[0]->unk30a) {
			return (u32) langGet(L_OPTIONS(402)); // "New..."
		}
		return filemgrGetDeviceNameOrStartIndex(0, operation, data->list.value);
	case MENUOP_GETGROUPSTARTINDEX:
		if (data->list.value >= g_FileLists[0]->unk30a) {
			data->list.groupstartindex = g_FileLists[0]->numfiles;
		} else {
			data->list.groupstartindex = filemgrGetDeviceNameOrStartIndex(0, operation, data->list.value);
		}
		return 0;
	}

	return 0;
}

s32 filemgrMainMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	s32 i;

	switch (operation) {
	case MENUOP_OPEN:
		g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone = 0;

		func0f110c5c(0, FILETYPE_SOLO);
		mpSetDefaultSetup();

		// Set MP player names to "Player 1" through 4 if blank
		for (i = 0; i < 4; i++) {
			if (g_MpPlayers[i].base.name[0] == '\0') {
				sprintf(g_MpPlayers[i].base.name, "%s %d\n", langGet(L_MISC(437)), i + 1);
			}
		}
		break;
	case MENUOP_CLOSE:
		func0f110bf8();
		break;
	}

	return 0;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel filemgrConsiderPushingFileSelectDialog
/*  f10d268:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10d26c:	8dce1728 */ 	lw	$t6,0x1728($t6)
/*  f10d270:	3c18800a */ 	lui	$t8,0x800a
/*  f10d274:	2718e5a0 */ 	addiu	$t8,$t8,-6752
/*  f10d278:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10d27c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10d280:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10d284:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10d288:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10d28c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10d290:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10d294:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f10d298:	9059083c */ 	lbu	$t9,0x83c($v0)
/*  f10d29c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10d2a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d2a4:	1720000f */ 	bnez	$t9,.PF0f10d2e4
/*  f10d2a8:	3c048007 */ 	lui	$a0,0x8007
/*  f10d2ac:	a040083b */ 	sb	$zero,0x83b($v0)
/*  f10d2b0:	2484527c */ 	addiu	$a0,$a0,0x527c
/*  f10d2b4:	0fc3e29d */ 	jal	0xf0f8a74
/*  f10d2b8:	24050006 */ 	li	$a1,0x6
/*  f10d2bc:	3c08800a */ 	lui	$t0,0x800a
/*  f10d2c0:	9508a992 */ 	lhu	$t0,-0x566e($t0)
/*  f10d2c4:	3c048007 */ 	lui	$a0,0x8007
/*  f10d2c8:	29010006 */ 	slti	$at,$t0,0x6
/*  f10d2cc:	14200003 */ 	bnez	$at,.PF0f10d2dc
/*  f10d2d0:	00000000 */ 	nop
/*  f10d2d4:	0fc3cda8 */ 	jal	0xf0f36a0
/*  f10d2d8:	24844810 */ 	addiu	$a0,$a0,0x4810
.PF0f10d2dc:
/*  f10d2dc:	10000002 */ 	b	.PF0f10d2e8
/*  f10d2e0:	24020001 */ 	li	$v0,0x1
.PF0f10d2e4:
/*  f10d2e4:	00001025 */ 	move	$v0,$zero
.PF0f10d2e8:
/*  f10d2e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d2ec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10d2f0:	03e00008 */ 	jr	$ra
/*  f10d2f4:	00000000 */ 	nop
);
#else
bool filemgrConsiderPushingFileSelectDialog(void)
{
	if (g_Menus[g_MpPlayerNum].unk83c == 0) {
		g_Menus[g_MpPlayerNum].playernum = 0;
		menuPushRootDialog(&g_FilemgrFileSelectMenuDialog, MENUROOT_FILEMGR);
		return true;
	}

	return false;
}
#endif

void pakPushPakMenuDialog(void)
{
	s32 prevplayernum = g_MpPlayerNum;
	g_MpPlayerNum = 0;
	menuPushRootDialog(&g_PakChoosePakMenuDialog, MENUROOT_BOOTPAKMGR);
	g_MpPlayerNum = prevplayernum;
}

struct menuitem g_FilemgrSelectLocationMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0,                         0x00000010, L_OPTIONS(368), L_OPTIONS(369), NULL }, // "Where", "Spaces"
	{ MENUITEMTYPE_SEPARATOR,   0,                         0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  SAVEDEVICE_GAMEPAK,        0x00000000, (u32)&filemgrMenuTextLocationName2, (u32)&filemgrMenuTextSaveLocationSpaces, filemgrSelectLocationMenuHandler },
	{ MENUITEMTYPE_SELECTABLE,  SAVEDEVICE_CONTROLLERPAK1, 0x00000000, (u32)&filemgrMenuTextLocationName2, (u32)&filemgrMenuTextSaveLocationSpaces, filemgrSelectLocationMenuHandler },
	{ MENUITEMTYPE_SELECTABLE,  SAVEDEVICE_CONTROLLERPAK2, 0x00000000, (u32)&filemgrMenuTextLocationName2, (u32)&filemgrMenuTextSaveLocationSpaces, filemgrSelectLocationMenuHandler },
	{ MENUITEMTYPE_SELECTABLE,  SAVEDEVICE_CONTROLLERPAK3, 0x00000000, (u32)&filemgrMenuTextLocationName2, (u32)&filemgrMenuTextSaveLocationSpaces, filemgrSelectLocationMenuHandler },
	{ MENUITEMTYPE_SELECTABLE,  SAVEDEVICE_CONTROLLERPAK4, 0x00000000, (u32)&filemgrMenuTextLocationName2, (u32)&filemgrMenuTextSaveLocationSpaces, filemgrSelectLocationMenuHandler },
	{ MENUITEMTYPE_SEPARATOR,   0,                         0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0,                         0x00000000, L_OPTIONS(370), 0x00000000, filemgrDeleteFilesForSaveMenuHandler }, // "Delete Files..."
	{ MENUITEMTYPE_SELECTABLE,  0,                         0x00000000, L_OPTIONS(371), 0x00000000, filemgrCancelSaveMenuHandler }, // "Cancel"
	{ MENUITEMTYPE_END,         0,                         0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrSelectLocationMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(367), // "Select Location"
	g_FilemgrSelectLocationMenuItems,
	NULL,
	0x00000080,
	NULL,
};

struct menuitem g_FilemgrConfirmDeleteMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&filemgrMenuTextDeleteFileName, 0x00000000, filemgrFileNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000230, (u32)&filemgrMenuTextDeviceName, 0x00000000, filemgrDeviceNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(380), 0x00000000, NULL }, // "Are you sure you want to delete this file?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(381), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(382), 0x00000000, filemgrConfirmDeleteMenuHandler }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrConfirmDeleteMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(379), // "Warning"
	g_FilemgrConfirmDeleteMenuItems,
	NULL,
	0x00000080,
	NULL,
};

struct menuitem g_FilemgrFileInUseMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&filemgrMenuTextDeleteFileName, 0x00000000, filemgrFileNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000230, (u32)&filemgrMenuTextDeviceName, 0x00000000, filemgrDeviceNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextFileInUseDescription, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS(161), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrFileInUseMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(159), // "Error"
	g_FilemgrFileInUseMenuItems,
	NULL,
	0x00000080,
	NULL,
};

struct menuitem g_FilemgrDeleteMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS(377), 0x00000000, NULL }, // "Select a file to delete:"
	{ MENUITEMTYPE_LIST,        1, 0x00200000, 0x00000000, 0x00000000, filemgrFileToDeleteListMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00004030, L_OPTIONS(378), 0x00000000, NULL }, // "Press B Button to exit."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrDeleteMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(376), // "Delete File"
	g_FilemgrDeleteMenuItems,
	filemgrCopyOrDeleteListMenuDialog,
	0x00000000,
	NULL,
};

struct menuitem g_FilemgrCopyMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS(374), 0x00000000, NULL }, // "Select a file to copy:"
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x00000000, 0x00000000, filemgrFileToCopyListMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00004030, L_OPTIONS(375), 0x00000000, NULL }, // "Press B Button to exit."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrCopyMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(373), // "Copy File"
	g_FilemgrCopyMenuItems,
	filemgrCopyOrDeleteListMenuDialog,
	0x00000000,
	NULL,
};

struct pakdata *g_EditingPak = NULL;

struct menuitem g_PakDeleteNoteMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(384), 0x00000000, NULL }, // "Are you sure you want to delete this game note?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(385), 0x00000000, NULL }, // "No"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(386), 0x00000000, pakDeleteGameNoteMenuHandler }, // "Yes"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_PakDeleteNoteMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(383), // "Delete Game Note"
	g_PakDeleteNoteMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_PakGameNotesMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(388), (u32)&pakMenuTextEditingPakName, NULL }, // "Delete Game Notes:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x0000010e, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(389), L_OPTIONS(390), NULL }, // "Note", "Pages"
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x000000c8, 0x0000006e, pakGameNoteListMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&pakMenuTextPagesFree, (u32)&pakMenuTextPagesUsed, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&pakMenuTextStatusMessage, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, L_OPTIONS(391), 0x00000000, NULL }, // "Press the B Button to exit."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_PakGameNotesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(387), // "Game Notes"
	g_PakGameNotesMenuItems,
	pakGameNotesMenuDialog,
	0x00000000,
	NULL,
};

struct menuitem g_PakChoosePakMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(108), 0x00000000, NULL }, // "Use this menu to delete game notes from your Controller Pak"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(109), 0x00000000, NULL }, // "Choose Controller Pak to Edit:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(112), 0x00000000, pakSelectionMenuHandler }, // "Controller Pak 1"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS(113), 0x00000000, pakSelectionMenuHandler }, // "Controller Pak 2"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS(114), 0x00000000, pakSelectionMenuHandler }, // "Controller Pak 3"
	{ MENUITEMTYPE_SELECTABLE,  3, 0x00000000, L_OPTIONS(115), 0x00000000, pakSelectionMenuHandler }, // "Controller Pak 4"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(110), 0x00000000, NULL }, // "Exit"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_PakChoosePakMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(107), // "Controller Pak Menu"
	g_PakChoosePakMenuItems,
	pakChoosePakMenuDialog,
	0x00000000,
	NULL,
};

struct menuitem g_FilemgrOperationsMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0,                 0x00004010, L_OPTIONS(100), 0x00000000, NULL }, // "Copy:"
	{ MENUITEMTYPE_SELECTABLE,  FILETYPE_SOLO,     0x00000000, L_OPTIONS(103), 0x00000000, filemgrOpenCopyFileMenuHandler }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  FILETYPE_MPSETUP , 0x00000000, L_OPTIONS(104), 0x00000000, filemgrOpenCopyFileMenuHandler }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  FILETYPE_MPPLAYER, 0x00000000, L_OPTIONS(105), 0x00000000, filemgrOpenCopyFileMenuHandler }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0,                 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0,                 0x00004010, L_OPTIONS(101), 0x00000000, NULL }, // "Delete:"
	{ MENUITEMTYPE_SELECTABLE,  FILETYPE_SOLO,     0x00000000, L_OPTIONS(103), 0x00000000, filemgrOpenDeleteFileMenuHandler }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  FILETYPE_MPSETUP,  0x00000000, L_OPTIONS(104), 0x00000000, filemgrOpenDeleteFileMenuHandler }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  FILETYPE_MPPLAYER, 0x00000000, L_OPTIONS(105), 0x00000000, filemgrOpenDeleteFileMenuHandler }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0,                 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0,                 0x00000004, L_OPTIONS(102), 0x00000000, (void *)&g_PakChoosePakMenuDialog }, // "Delete Game Notes..."
	{ MENUITEMTYPE_END,         0,                 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrOperationsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(99), // "Game Files"
	g_FilemgrOperationsMenuItems,
	NULL,
	0x00000020,
	NULL,
};

struct menuitem g_FilemgrEnterNameMenuItems[] = {
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000001, filemgrAgentNameKeyboardMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrEnterNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(401), // "Enter Agent Name"
	g_FilemgrEnterNameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_FilemgrFileSelectMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS(96), 0x00000000, NULL }, // "Choose Your Reality"
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x000000f5, 0x00000000, filemgrChooseAgentListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrFileSelectMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(95), // "Perfect Dark"
	g_FilemgrFileSelectMenuItems,
	filemgrMainMenuDialog,
	0x00000020,
	&g_FilemgrOperationsMenuDialog,
};
