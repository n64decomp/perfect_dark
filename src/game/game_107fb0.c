#include <ultra64.h>
#include "constants.h"
#include "game/game_0b3350.h"
#include "game/game_0d4690.h"
#include "game/game_0f09f0.h"
#include "game/game_107fb0.h"
#include "game/game_110680.h"
#include "game/game_1531a0.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/lib_126b0.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"

// bss
struct savelocation_2d8 g_FilemgrFileToCopy;
struct savelocation_2d8 var800a21e8;
struct savelocation_2d8 g_FilemgrFileToDelete;
struct savelocation_2d8 var800a21f8;
struct gamefile g_GameFile;
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
s32 func0f1088d0pf(s32 operation, struct menuitem *item, union handlerdata *data);

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
/*  f1088f4:	0fc5bdd7 */ 	jal	func0f16f75c
/*  f1088f8:	31c4ffff */ 	andi	$a0,$t6,0xffff
/*  f1088fc:	0fc3cf8c */ 	jal	menuPopDialog
/*  f108900:	00000000 */ 	nop
.PF0f108904:
/*  f108904:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f108908:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10890c:	00001025 */ 	move	$v0,$zero
/*  f108910:	03e00008 */ 	jr	$ra
/*  f108914:	00000000 */ 	nop
);

struct menuitem g_ChooseLanguageMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,               0x00004010, L_MPWEAPONS_261, 0x00000000, 0x00000000     }, // "Choose your language:"
	{ MENUITEMTYPE_SEPARATOR,  0,               0x00000000, 0x00000000, 0x00000000, 0x00000000     },
	{ MENUITEMTYPE_SELECTABLE, LANGUAGE_PAL_EN, 0x00000020, L_MPWEAPONS_262, 0x00000000, func0f1088d0pf }, // "English"
	{ MENUITEMTYPE_SELECTABLE, LANGUAGE_PAL_FR, 0x00000020, L_MPWEAPONS_263, 0x00000000, func0f1088d0pf }, // "French"
	{ MENUITEMTYPE_SELECTABLE, LANGUAGE_PAL_DE, 0x00000020, L_MPWEAPONS_264, 0x00000000, func0f1088d0pf }, // "German"
	{ MENUITEMTYPE_SELECTABLE, LANGUAGE_PAL_IT, 0x00000020, L_MPWEAPONS_265, 0x00000000, func0f1088d0pf }, // "Italian"
	{ MENUITEMTYPE_SELECTABLE, LANGUAGE_PAL_ES, 0x00000020, L_MPWEAPONS_266, 0x00000000, func0f1088d0pf }, // "Spanish"
	{ MENUITEMTYPE_END,        0,               0x00000000, 0x00000000, 0x00000000, 0x00000000     },
};

struct menudialog g_ChooseLanguageMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_095,
	g_ChooseLanguageMenuItems,
	NULL,
	0x00000020,
	NULL,
};
#endif

char *filemgrGetDeviceName(s32 index)
{
	u16 names[] = {
		L_OPTIONS_112, // "Controller Pak 1"
		L_OPTIONS_113, // "Controller Pak 2"
		L_OPTIONS_114, // "Controller Pak 3"
		L_OPTIONS_115, // "Controller Pak 4"
		L_OPTIONS_111, // "Game Pak"
#if VERSION >= VERSION_NTSC_1_0
		L_MPWEAPONS_229, // "Controller Pak Not Found"
#endif
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

void filemgrGetSelectName(char *buffer, struct filelistfile *file, u32 filetype)
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
	case FILETYPE_GAME:
	case FILETYPE_MPSETUP:
		func0f0d564c(file->unk06, tmpbuffer1, false);
		break;
	case FILETYPE_MPPLAYER:
		// MP Player filenames have the play duration appended to the name
		mpplayerfileGetOverview(file->unk06, namebuffer, &totalinseconds);
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

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b2f28[] = "Setup: item = %x\n";
#endif

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
		filemgrGetSelectName(g_StringPointer,
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

void func0f1083b0(struct filelistfile *file)
{
	func0f108324(file->unk04);
}

void func0f1083d0(struct filelistfile *file, s32 filetype)
{
	g_Menus[g_MpPlayerNum].unke3d = filetype;
	g_Menus[g_MpPlayerNum].unke38 = file;
	func0f1083b0(file);
}

u16 g_PakFailReasons[] = {
	L_OPTIONS_322, // "The Controller Pak was not found in any controller."
	L_OPTIONS_323, // "File was not saved."
	L_OPTIONS_324, // "File would not load."
	L_OPTIONS_325, // "Could not delete the file."
	L_OPTIONS_326, // "Out of memory."
	L_OPTIONS_327, // "This player is already loaded for this game."
	L_OPTIONS_328, // "has been removed."
	L_OPTIONS_329, // "Controller Pak is damaged or incorrectly inserted."
	L_OPTIONS_330, // "Game note delete failed."
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

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b2f6c[] = "FileMan: Failure Handler\n";
const char var7f1b2f88[] = "Copy Memory Freed\n";
const char var7f1b2f9c[] = "FileMan: Success Handler\n";
const char var7f1b2fb8[] = "Copy Memory Freed\n";
const char var7f1b2fcc[] = ">> block read going write, target file is %x-%x\n";
const char var7f1b3000[] = "SaveElsewhere\n";
const char var7f1b3010[] = "DELETING: %x-%x\n";
const char var7f1b3024[] = "MyResult: %d\n";
const char var7f1b3034[] = "PakOperationSearch>> Search for pak: %x = %d\n";
#endif

void filemgrPushErrorDialog(u16 errno)
{
	g_Menus[g_MpPlayerNum].errno = errno;

	menuPushDialog(&g_FilemgrErrorMenuDialog);
}

struct menuitem g_FilemgrErrorMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextDeviceNameForError, 0x00000000, filemgrDeviceNameForErrorMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextFailReason, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS_321, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrErrorMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_320, // "Error"
	g_FilemgrErrorMenuItems,
	NULL,
	0x00000080,
	NULL,
};

s32 filemgrGetDeviceNameOrStartIndex(s32 listnum, s32 operation, s32 optionindex)
{
	u16 names[] = {
		L_OPTIONS_111, // "Game Pak"
		L_OPTIONS_112, // "Controller Pak 1"
		L_OPTIONS_113, // "Controller Pak 2"
		L_OPTIONS_114, // "Controller Pak 3"
		L_OPTIONS_115, // "Controller Pak 4"
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
		L_OPTIONS_331, // "Error Loading Game"
		L_OPTIONS_332, // "Error Saving Game"
		L_OPTIONS_333, // "Error Loading Player"
		L_OPTIONS_334, // "Error Saving Player"
		L_OPTIONS_335, // "Error Loading PerfectHead"
		L_OPTIONS_336, // "Error Saving PerfectHead"
		L_OPTIONS_337, // "Error Reading File"
		L_OPTIONS_338, // "Error Writing File"
		L_OPTIONS_339, // "Error"
	};

	switch (g_Menus[g_MpPlayerNum].fileop) {
	case FILEOP_LOAD_GAME:
	case FILEOP_LOAD_MPSETUP:
		return langGet(messages[0]);
	case FILEOP_SAVE_GAME_000:
	case FILEOP_SAVE_GAME_001:
	case FILEOP_SAVE_GAME_002:
	case FILEOP_SAVE_MPSETUP:
		return langGet(messages[1]);
	case FILEOP_LOAD_MPPLAYER:
		return langGet(messages[2]);
	case FILEOP_SAVE_MPPLAYER:
		return langGet(messages[3]);
	case FILEOP_READ_GAME:
	case FILEOP_READ_MPSETUP:
	case FILEOP_READ_MPPLAYER:
		return langGet(messages[6]);
	case FILEOP_WRITE_GAME:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_WRITE_MPPLAYER:
		return langGet(messages[7]);
	}

	return langGet(messages[8]);
}

#if VERSION >= VERSION_NTSC_1_0
char *filemgrMenuTextFileType(struct menuitem *item)
{
	u16 names[] = {
		L_OPTIONS_103, // "Single Player Agent File"
		L_OPTIONS_104, // "Combat Simulator Settings File"
		L_OPTIONS_105, // "Combat Simulator Player File"
		L_OPTIONS_106, // "PerfectHead Files"
	};

	switch (g_Menus[g_MpPlayerNum].fileop) {
	case FILEOP_SAVE_GAME_000:
	case FILEOP_SAVE_GAME_001:
	case FILEOP_SAVE_GAME_002:
	case FILEOP_WRITE_GAME:
	case FILEOP_LOAD_GAME:
	case FILEOP_READ_GAME:
		return langGet(names[0]);
	case FILEOP_SAVE_MPSETUP:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_LOAD_MPSETUP:
	case FILEOP_READ_MPSETUP:
		return langGet(names[1]);
	case FILEOP_SAVE_MPPLAYER:
	case FILEOP_WRITE_MPPLAYER:
	case FILEOP_LOAD_MPPLAYER:
	case FILEOP_READ_MPPLAYER:
		return langGet(names[2]);
	}

	return langGet(names[0]);
}
#endif

void func0f10898c(void)
{
	func0f0f0ca0(-1, false);

	switch (g_Menus[g_MpPlayerNum].fileop) {
	case FILEOP_WRITE_GAME:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_WRITE_MPPLAYER:
	case FILEOP_READ_GAME:
	case FILEOP_READ_MPSETUP:
	case FILEOP_READ_MPPLAYER:
		func00012cb4(g_Menus[g_MpPlayerNum].unke44, align16(var7f1b2f3c[g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone - 1]));
		break;
	case FILEOP_LOAD_GAME:
	case FILEOP_LOAD_MPPLAYER:
	case FILEOP_LOAD_MPSETUP:
	case FILEOP_103:
	case FILEOP_SAVE_GAME_000:
	case FILEOP_SAVE_GAME_001:
	case FILEOP_SAVE_GAME_002:
	case FILEOP_SAVE_MPPLAYER:
	case FILEOP_SAVE_MPSETUP:
	case FILEOP_005:
		break;
	}
}

void filemgrHandleSuccess(void)
{
	func0f0f0ca0(-1, false);

	switch (g_Menus[g_MpPlayerNum].fileop) {
	case FILEOP_WRITE_GAME:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_WRITE_MPPLAYER:
		func00012cb4(g_Menus[g_MpPlayerNum].unke44,
				align16(var7f1b2f3c[g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone - 1]));
		break;
	case FILEOP_LOAD_GAME:
		g_Vars.unk00047c = g_Menus[g_MpPlayerNum].unke48;
		g_Vars.unk000480 = g_Menus[g_MpPlayerNum].unke4c;
		bossfileSave();

		if (IS4MB()) {
			func0f0f820c(&g_MainMenu4MbMenuDialog, MENUROOT_4MBMAINMENU);
		} else {
			func0f0f820c(&g_CiMenuViaPcMenuDialog, MENUROOT_MAINMENU);
		}
		break;
	case FILEOP_READ_GAME:
	case FILEOP_READ_MPSETUP:
	case FILEOP_READ_MPPLAYER:
		func0f1094e4(&var800a21e8,
				g_Menus[g_MpPlayerNum].fileop - 98,
				g_Menus[g_MpPlayerNum].unke44);
		break;
	case FILEOP_SAVE_GAME_000:
	case FILEOP_SAVE_GAME_001:
	case FILEOP_SAVE_GAME_002:
	case FILEOP_SAVE_MPPLAYER:
	case FILEOP_SAVE_MPSETUP:
	case FILEOP_005:
	case FILEOP_LOAD_MPPLAYER:
	case FILEOP_LOAD_MPSETUP:
	case FILEOP_103:
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
		s32 filetype;

		menuCloseDialog();

		switch (g_Menus[g_MpPlayerNum].fileop) {
		case FILEOP_SAVE_GAME_000:
		case FILEOP_SAVE_GAME_001:
		case FILEOP_SAVE_GAME_002:
		case FILEOP_WRITE_GAME:
			filetype = FILETYPE_GAME;
			break;
		case FILEOP_SAVE_MPPLAYER:
		case FILEOP_WRITE_MPPLAYER:
			filetype = FILETYPE_MPPLAYER;
			break;
		case FILEOP_SAVE_MPSETUP:
		case FILEOP_WRITE_MPSETUP:
			filetype = FILETYPE_MPSETUP;
			break;
		}

		filemgrPushSelectLocationDialog(g_Menus[g_MpPlayerNum].fileop + 9, filetype);
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

#if VERSION >= VERSION_NTSC_1_0
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
			g_FileLists[i]->timeuntilupdate = 1;
		}
	}

	menuPushDialog(&g_FilemgrFileLostMenuDialog);
}
#endif

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
		if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fileop) && g_Menus[g_MpPlayerNum].fileop != FILEOP_SAVE_GAME_001) {
			func0f0f3704(&g_FilemgrSaveElsewhereMenuDialog);
		} else {
			menuPopDialog();
		}
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
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
	sprintf(fullbuffer, langGet(L_OPTIONS_363), namebuffer);

	textWrap(120, fullbuffer, g_StringPointer, g_CharsHandelGothicSm, g_FontHandelGothicSm);

	return g_StringPointer;
}
#endif

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
	} else if (filemgrAttemptOperation(index, true)) {
		if (context == 2) {
			g_Menus[g_MpPlayerNum].unke3c = index;

			if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fileop)) {
				filemgrPushErrorDialog(FILEERROR_SAVEFAILED);
			} else {
				filemgrPushErrorDialog(FILEERROR_LOADFAILED);
			}
		} else {
			func0f108324(g_Menus[g_MpPlayerNum].unke4c);

			if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fileop)) {
				func0f0f3704(&g_FilemgrSaveErrorMenuDialog);
			} else {
#if VERSION >= VERSION_NTSC_1_0
				filemgrEraseCorruptFile();
#else
				// Argument is wrong/mismatching
				func0f0f3704(&g_FilemgrSaveErrorMenuDialog);
#endif
			}
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
bool filemgrAttemptOperation(s32 arg0, bool closeonsuccess)
{
	s32 errno = 0;
	bool showfilesaved = (g_Menus[g_MpPlayerNum].isretryingsave & 1) != 0;

	const s32 sp30[] = {0x80, 0x40, 0x20, 0x08};
	s32 sp2c;

	switch (g_Menus[g_MpPlayerNum].fileop) {
	case FILEOP_SAVE_GAME_002:
		showfilesaved = true;
		// fall through
	case FILEOP_SAVE_GAME_000:
	case FILEOP_SAVE_GAME_001:
		errno = gamefileSave(arg0,
				g_Menus[g_MpPlayerNum].unke48,
				g_Menus[g_MpPlayerNum].unke4c);
		break;
	case FILEOP_SAVE_MPPLAYER:
		errno = mpplayerfileSave(
				(s32) g_Menus[g_MpPlayerNum].unke44, arg0,
				g_Menus[g_MpPlayerNum].unke48,
				g_Menus[g_MpPlayerNum].unke4c);
		break;
	case FILEOP_SAVE_MPSETUP:
		errno = mpsetupfileSave(arg0,
				g_Menus[g_MpPlayerNum].unke48,
				g_Menus[g_MpPlayerNum].unke4c);
		showfilesaved = true;
		break;
	case FILEOP_WRITE_GAME:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_WRITE_MPPLAYER:
		sp2c = 0;
		func0f0d5690(g_Menus[g_MpPlayerNum].unke44, g_Menus[g_MpPlayerNum].unke53);
		errno = func0f116828(arg0,
				g_Menus[g_MpPlayerNum].unke48,
				sp30[g_Menus[g_MpPlayerNum].fileop - 6],
				g_Menus[g_MpPlayerNum].unke44, &sp2c, 0);
		var80075bd0[g_Menus[g_MpPlayerNum].fileop - 6] = 1;
		break;
	case FILEOP_LOAD_GAME:
		errno = gamefileLoad(arg0);
		break;
	case FILEOP_LOAD_MPPLAYER:
		errno = mpplayerfileLoad(
				(s32) g_Menus[g_MpPlayerNum].unke44,
				arg0,
				g_Menus[g_MpPlayerNum].unke48,
				g_Menus[g_MpPlayerNum].unke4c);
		break;
	case FILEOP_LOAD_MPSETUP:
		errno = mpsetupfileLoad(arg0,
				g_Menus[g_MpPlayerNum].unke48,
				g_Menus[g_MpPlayerNum].unke4c);
		break;
	case FILEOP_READ_GAME:
	case FILEOP_READ_MPSETUP:
	case FILEOP_READ_MPPLAYER:
		errno = func0f116800(arg0,
				g_Menus[g_MpPlayerNum].unke48,
				g_Menus[g_MpPlayerNum].unke44, 0);
		break;
	}

	if (errno == 0 && closeonsuccess) {
		menuCloseDialog();
	}

	if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fileop)) {
		if (errno == 0) {
			filemgrHandleSuccess();
		}

		if (showfilesaved && errno == 0) {
			menuPushDialog(&g_FilemgrFileSavedMenuDialog);
		}
	} else {
		if (errno == 0) {
			filemgrHandleSuccess();
		}
	}

	menuUpdateCurFrame();

	return errno;
}
#else
const s32 var7f1ad258nb[] = {0x80, 0x40, 0x20, 0x08};

GLOBAL_ASM(
glabel filemgrAttemptOperation
.late_rodata
glabel var7f1ad3e8nb
.word filemgrAttemptOperation+0x1a8
glabel var7f1ad3ecnb
.word filemgrAttemptOperation+0x1b8
glabel var7f1ad3f0nb
.word filemgrAttemptOperation+0x1d4
glabel var7f1ad3f4nb
.word filemgrAttemptOperation+0x210
glabel var7f1ad3f8nb
.word filemgrAttemptOperation+0x1ec
glabel var7f1ad3fcnb
.word filemgrAttemptOperation+0x1ec
glabel var7f1ad400nb
.word filemgrAttemptOperation+0x1ec
glabel var7f1ad404nb
.word filemgrAttemptOperation+0x0dc
glabel var7f1ad408nb
.word filemgrAttemptOperation+0x0dc
glabel var7f1ad40cnb
.word filemgrAttemptOperation+0x0d4
glabel var7f1ad410nb
.word filemgrAttemptOperation+0x0f4
glabel var7f1ad414nb
.word filemgrAttemptOperation+0x110
glabel var7f1ad418nb
.word filemgrAttemptOperation+0x210
glabel var7f1ad41cnb
.word filemgrAttemptOperation+0x130
glabel var7f1ad420nb
.word filemgrAttemptOperation+0x130
glabel var7f1ad424nb
.word filemgrAttemptOperation+0x130
.text
/*  f104a8c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f104a90:	8dce3af0 */ 	lw	$t6,0x3af0($t6)
/*  f104a94:	3c18800a */ 	lui	$t8,0x800a
/*  f104a98:	271827c0 */ 	addiu	$t8,$t8,0x27c0
/*  f104a9c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f104aa0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f104aa4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f104aa8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f104aac:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f104ab0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f104ab4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f104ab8:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f104abc:	94590dac */ 	lhu	$t9,0xdac($v0)
/*  f104ac0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f104ac4:	3c0c7f1b */ 	lui	$t4,0x7f1b
/*  f104ac8:	332a0001 */ 	andi	$t2,$t9,0x1
/*  f104acc:	000a582b */ 	sltu	$t3,$zero,$t2
/*  f104ad0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f104ad4:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f104ad8:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f104adc:	afab0040 */ 	sw	$t3,0x40($sp)
/*  f104ae0:	258cd258 */ 	addiu	$t4,$t4,-11688
/*  f104ae4:	8d810000 */ 	lw	$at,0x0($t4)
/*  f104ae8:	27a90030 */ 	addiu	$t1,$sp,0x30
/*  f104aec:	90480d9e */ 	lbu	$t0,0xd9e($v0)
/*  f104af0:	ad210000 */ 	sw	$at,0x0($t1)
/*  f104af4:	8d8f0004 */ 	lw	$t7,0x4($t4)
/*  f104af8:	01001825 */ 	or	$v1,$t0,$zero
/*  f104afc:	00003025 */ 	or	$a2,$zero,$zero
/*  f104b00:	ad2f0004 */ 	sw	$t7,0x4($t1)
/*  f104b04:	8d810008 */ 	lw	$at,0x8($t4)
/*  f104b08:	2478ff9c */ 	addiu	$t8,$v1,-100
/*  f104b0c:	ad210008 */ 	sw	$at,0x8($t1)
/*  f104b10:	8d8f000c */ 	lw	$t7,0xc($t4)
/*  f104b14:	29010009 */ 	slti	$at,$t0,0x9
/*  f104b18:	14200009 */ 	bnez	$at,.NB0f104b40
/*  f104b1c:	ad2f000c */ 	sw	$t7,0xc($t1)
/*  f104b20:	2f010007 */ 	sltiu	$at,$t8,0x7
/*  f104b24:	1020005d */ 	beqz	$at,.NB0f104c9c
/*  f104b28:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f104b2c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f104b30:	00380821 */ 	addu	$at,$at,$t8
/*  f104b34:	8c38d3e8 */ 	lw	$t8,-0x2c18($at)
/*  f104b38:	03000008 */ 	jr	$t8
/*  f104b3c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f104b40:
/*  f104b40:	2c610009 */ 	sltiu	$at,$v1,0x9
/*  f104b44:	10200055 */ 	beqz	$at,.NB0f104c9c
/*  f104b48:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f104b4c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f104b50:	00390821 */ 	addu	$at,$at,$t9
/*  f104b54:	8c39d404 */ 	lw	$t9,-0x2bfc($at)
/*  f104b58:	03200008 */ 	jr	$t9
/*  f104b5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104b60:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f104b64:	afaa0040 */ 	sw	$t2,0x40($sp)
/*  f104b68:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f104b6c:	8c450da4 */ 	lw	$a1,0xda4($v0)
/*  f104b70:	0fc428e0 */ 	jal	gamefileSave
/*  f104b74:	94460daa */ 	lhu	$a2,0xdaa($v0)
/*  f104b78:	10000048 */ 	beqz	$zero,.NB0f104c9c
/*  f104b7c:	00403025 */ 	or	$a2,$v0,$zero
/*  f104b80:	8c440da0 */ 	lw	$a0,0xda0($v0)
/*  f104b84:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f104b88:	8c460da4 */ 	lw	$a2,0xda4($v0)
/*  f104b8c:	0fc61f00 */ 	jal	mpplayerfileSave
/*  f104b90:	94470daa */ 	lhu	$a3,0xdaa($v0)
/*  f104b94:	10000041 */ 	beqz	$zero,.NB0f104c9c
/*  f104b98:	00403025 */ 	or	$a2,$v0,$zero
/*  f104b9c:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f104ba0:	8c450da4 */ 	lw	$a1,0xda4($v0)
/*  f104ba4:	0fc62178 */ 	jal	mpsetupfileSave
/*  f104ba8:	94460daa */ 	lhu	$a2,0xdaa($v0)
/*  f104bac:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f104bb0:	00403025 */ 	or	$a2,$v0,$zero
/*  f104bb4:	10000039 */ 	beqz	$zero,.NB0f104c9c
/*  f104bb8:	afab0040 */ 	sw	$t3,0x40($sp)
/*  f104bbc:	00087080 */ 	sll	$t6,$t0,0x2
/*  f104bc0:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f104bc4:	012e6821 */ 	addu	$t5,$t1,$t6
/*  f104bc8:	8da6ffe8 */ 	lw	$a2,-0x18($t5)
/*  f104bcc:	27ac002c */ 	addiu	$t4,$sp,0x2c
/*  f104bd0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f104bd4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f104bd8:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f104bdc:	8c450da4 */ 	lw	$a1,0xda4($v0)
/*  f104be0:	0fc442fb */ 	jal	func0f116828
/*  f104be4:	8c470da0 */ 	lw	$a3,0xda0($v0)
/*  f104be8:	3c188007 */ 	lui	$t8,0x8007
/*  f104bec:	8f183af0 */ 	lw	$t8,0x3af0($t8)
/*  f104bf0:	3c0a800a */ 	lui	$t2,0x800a
/*  f104bf4:	3c018007 */ 	lui	$at,0x8007
/*  f104bf8:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f104bfc:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f104c00:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f104c04:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f104c08:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f104c0c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f104c10:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f104c14:	01595021 */ 	addu	$t2,$t2,$t9
/*  f104c18:	914a355e */ 	lbu	$t2,0x355e($t2)
/*  f104c1c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f104c20:	00403025 */ 	or	$a2,$v0,$zero
/*  f104c24:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f104c28:	002b0821 */ 	addu	$at,$at,$t3
/*  f104c2c:	1000001b */ 	beqz	$zero,.NB0f104c9c
/*  f104c30:	ac2f7f58 */ 	sw	$t7,0x7f58($at)
/*  f104c34:	0fc427fe */ 	jal	gamefileLoad
/*  f104c38:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f104c3c:	10000017 */ 	beqz	$zero,.NB0f104c9c
/*  f104c40:	00403025 */ 	or	$a2,$v0,$zero
/*  f104c44:	8c440da0 */ 	lw	$a0,0xda0($v0)
/*  f104c48:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f104c4c:	8c460da4 */ 	lw	$a2,0xda4($v0)
/*  f104c50:	0fc61f31 */ 	jal	mpplayerfileLoad
/*  f104c54:	94470daa */ 	lhu	$a3,0xdaa($v0)
/*  f104c58:	10000010 */ 	beqz	$zero,.NB0f104c9c
/*  f104c5c:	00403025 */ 	or	$a2,$v0,$zero
/*  f104c60:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f104c64:	8c450da4 */ 	lw	$a1,0xda4($v0)
/*  f104c68:	0fc621a2 */ 	jal	mpsetupfileLoad
/*  f104c6c:	94460daa */ 	lhu	$a2,0xdaa($v0)
/*  f104c70:	1000000a */ 	beqz	$zero,.NB0f104c9c
/*  f104c74:	00403025 */ 	or	$a2,$v0,$zero
/*  f104c78:	00087080 */ 	sll	$t6,$t0,0x2
/*  f104c7c:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f104c80:	00ee3821 */ 	addu	$a3,$a3,$t6
/*  f104c84:	8ce7d088 */ 	lw	$a3,-0x2f78($a3)
/*  f104c88:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f104c8c:	8c450da4 */ 	lw	$a1,0xda4($v0)
/*  f104c90:	0fc442f1 */ 	jal	func0f116800
/*  f104c94:	8c460da0 */ 	lw	$a2,0xda0($v0)
/*  f104c98:	00403025 */ 	or	$a2,$v0,$zero
.NB0f104c9c:
/*  f104c9c:	14c00006 */ 	bnez	$a2,.NB0f104cb8
/*  f104ca0:	8fad004c */ 	lw	$t5,0x4c($sp)
/*  f104ca4:	11a00004 */ 	beqz	$t5,.NB0f104cb8
/*  f104ca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104cac:	0fc3bfcf */ 	jal	menuCloseDialog
/*  f104cb0:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f104cb4:	8fa60044 */ 	lw	$a2,0x44($sp)
.NB0f104cb8:
/*  f104cb8:	3c0c8007 */ 	lui	$t4,0x8007
/*  f104cbc:	8d8c3af0 */ 	lw	$t4,0x3af0($t4)
/*  f104cc0:	3c19800a */ 	lui	$t9,0x800a
/*  f104cc4:	000cc0c0 */ 	sll	$t8,$t4,0x3
/*  f104cc8:	030cc023 */ 	subu	$t8,$t8,$t4
/*  f104ccc:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f104cd0:	030cc023 */ 	subu	$t8,$t8,$t4
/*  f104cd4:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f104cd8:	030cc023 */ 	subu	$t8,$t8,$t4
/*  f104cdc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f104ce0:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f104ce4:	9339355e */ 	lbu	$t9,0x355e($t9)
/*  f104ce8:	2b210064 */ 	slti	$at,$t9,0x64
/*  f104cec:	10200010 */ 	beqz	$at,.NB0f104d30
/*  f104cf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104cf4:	54c00005 */ 	bnezl	$a2,.NB0f104d0c
/*  f104cf8:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f104cfc:	0fc41127 */ 	jal	filemgrHandleSuccess
/*  f104d00:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f104d04:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f104d08:	8faa0040 */ 	lw	$t2,0x40($sp)
.NB0f104d0c:
/*  f104d0c:	1140000d */ 	beqz	$t2,.NB0f104d44
/*  f104d10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104d14:	14c0000b */ 	bnez	$a2,.NB0f104d44
/*  f104d18:	3c048007 */ 	lui	$a0,0x8007
/*  f104d1c:	248469d4 */ 	addiu	$a0,$a0,0x69d4
/*  f104d20:	0fc3beda */ 	jal	menuPushDialog
/*  f104d24:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f104d28:	10000006 */ 	beqz	$zero,.NB0f104d44
/*  f104d2c:	8fa60044 */ 	lw	$a2,0x44($sp)
.NB0f104d30:
/*  f104d30:	14c00004 */ 	bnez	$a2,.NB0f104d44
/*  f104d34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104d38:	0fc41127 */ 	jal	filemgrHandleSuccess
/*  f104d3c:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f104d40:	8fa60044 */ 	lw	$a2,0x44($sp)
.NB0f104d44:
/*  f104d44:	0fc3c058 */ 	jal	menuUpdateCurFrame
/*  f104d48:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f104d4c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f104d50:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f104d54:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f104d58:	03e00008 */ 	jr	$ra
/*  f104d5c:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
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
#endif

bool func0f1094e4(struct savelocation_2d8 *arg0, s32 fileop, void *arg2)
{
	s32 value;

	if (fileop != -1) {
		g_Menus[g_MpPlayerNum].fileop = fileop;
		g_Menus[g_MpPlayerNum].unke44 = arg2;
		g_Menus[g_MpPlayerNum].isretryingsave = 0;
		var800a21f8.unk00 = 0;
	}

	g_Menus[g_MpPlayerNum].unke48 = arg0->unk00;
	g_Menus[g_MpPlayerNum].unke4c = arg0->unk04;

	if (fileop != -1) {
		// empty
	}

	value = pakSearch(g_Menus[g_MpPlayerNum].unke4c);

	if (value == -1) {
		g_Menus[g_MpPlayerNum].isretryingsave |= 1;
		menuPushDialog(&g_PakNotOriginalMenuDialog);
		return false;
	}

	if (filemgrAttemptOperation(value, false) != 0) {
		g_Menus[g_MpPlayerNum].isretryingsave |= 1;
		func0f108324(g_Menus[g_MpPlayerNum].unke4c);

		if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fileop)) {
			menuPushDialog(&g_FilemgrSaveErrorMenuDialog);
		} else {
#if VERSION >= VERSION_NTSC_1_0
			filemgrEraseCorruptFile();
#else
			// Argument is wrong/mismatching
			menuPushDialog(&g_FilemgrSaveErrorMenuDialog);
#endif
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

	g_FileLists[g_Menus[g_MpPlayerNum].listnum]->timeuntilupdate = 1;

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
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_346, 0x00000000, NULL }, // "File Saved."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS_347, 0x00000000, NULL }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrFileSavedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS_345, // "Cool!"
	g_FilemgrFileSavedMenuItems,
	NULL,
	0x00000080,
	NULL,
};

struct menuitem g_FilemgrSaveErrorMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextDeviceName, 0x00000000, filemgrDeviceNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_348, 0x00000000, NULL }, // "An error occurred while trying to save"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_349, 0x00000000, filemgrRetrySaveMenuHandler }, // "Try Again"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_350, 0x00000000, filemgrSaveElsewhereYesMenuHandler }, // "Save Elsewhere"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_351, 0x00000000, filemgrCancelSave2MenuHandler }, // "Cancel"
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
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_251, 0x00000000, NULL }, // "The saved file has been erased due to corruption or damage."
#endif
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_354, 0x00000000, filemgrAcknowledgeFileLostMenuHandler }, // "Cancel"
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
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_360, 0x00000000, NULL }, // "Would you like to save your file elsewhere?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_361, 0x00000000, filemgrSaveElsewhereYesMenuHandler }, // "Yes"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_362, 0x00000000, filemgrCancelSave2MenuHandler }, // "No"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrSaveElsewhereMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_359, // "Save"
	g_FilemgrSaveElsewhereMenuItems,
	NULL,
	0x000000a0,
	NULL,
};

struct menuitem g_PakNotOriginalMenuItems[] = {
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextInsertOriginalPak, 0x00000000, NULL },
#endif
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_365, 0x00000000, filemgrReinsertedOkMenuHandler }, // "OK"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_366, 0x00000000, filemgrReinsertedCancelMenuHandler }, // "Cancel"
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

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b3234[] = "DestPakNo: %d (guid F:%x-%x:P)\n";
const char var7f1b3254[] = "Copy Memory Alloced\n";
const char var7f1b326c[] = "COULDNT GET THE RAM!\n";
const char var7f1b3284[] = "Saving...\n";
#endif

void func0f109954(s32 arg0)
{
	if (g_FileLists[0]) {
		g_FilemgrLoadedMainFile.unk00 = g_FileLists[0]->unk2d8[arg0].unk00;
		g_FilemgrLoadedMainFile.unk04 = g_FileLists[0]->unk2d8[arg0].unk04;

		func0f1094e4(&g_FilemgrLoadedMainFile, FILEOP_SAVE_GAME_000, NULL);
	}
}

#if VERSION >= VERSION_NTSC_1_0
void filemgrGetFileName(char *dst, struct filelistfile *file)
{
	char localbuffer[20];
	u32 playtime;

	localbuffer[0] = '\0';

	switch (g_FileLists[g_Menus[g_MpPlayerNum].listnum]->filetype) {
	case FILETYPE_GAME:
	case FILETYPE_MPSETUP:
		func0f0d564c(file->unk06, localbuffer, false);
		break;
	case FILETYPE_MPPLAYER:
		mpplayerfileGetOverview(file->unk06, localbuffer, &playtime);
		break;
	}

	sprintf(dst, "%s", localbuffer);
}
#endif

#if VERSION >= VERSION_NTSC_1_0
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
		strcpy(buffer, g_GameFile.name);
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
#endif

#if VERSION >= VERSION_NTSC_1_0
void filemgrSetRenameName(char *name)
{
	switch (g_Menus[g_MpPlayerNum].unke3e) {
	case 0:
	case 9:
	case 10:
	case 11:
		strcpy(g_GameFile.name, name);
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
#endif

#if VERSION >= VERSION_NTSC_1_0
bool filemgrIsNameAvailable(s32 device)
{
	static u8 lookup[] = {1, 2, 3, 4, 0};

	struct filelist *filelist;
	char findname[16];
	s32 deviceindex;
	s32 startindex;
	s32 endindex;
	s32 i;
	s32 j;
	char loopname[16];

	deviceindex = lookup[device];
	filelist = g_FileLists[g_Menus[g_MpPlayerNum].listnum];

	if (filelist == NULL) {
		return true;
	}

	// Determine which index to start searching at
	startindex = filelist->devicestartindexes[deviceindex];

	if (startindex == -1) {
		return true;
	}

	// Determine which index to stop searching at
	// (ie. start of a new device or end of the list)
	endindex = filelist->numfiles;

	for (i = 4; i > deviceindex; i--) {
		if (filelist->devicestartindexes[i] != -1) {
			endindex = filelist->devicestartindexes[i];
		}
	}

	// Get the filename to search for, make it uppercase and remove trailing line break.
	// @dangerous: findname can overflow if filemgrGetRenameName returns a long name.
	findname[0] = '\0';
	filemgrGetRenameName(findname);

	for (j = 0; findname[j] != '\0';) {
		if (findname[j] >= 'a' && findname[j] <= 'z') {
			findname[j] -= 32;
		}

		if (findname[j] == '\n') {
			findname[j] = '\0';
		} else {
			j++;
		}
	}

	osSyncPrintf("CheckFileName: Comparing range %d-%d\n", startindex, endindex);

	// Iterate files
	for (i = startindex; i < endindex; i++) {
		filemgrGetFileName(loopname, &g_FileLists[g_Menus[g_MpPlayerNum].listnum]->files[i]);

		// Convert loop filename to uppercase and remove trailing line break
		// @dangerous: loopname can overflow if filemgrGetFileName returns a long name.
		for (j = 0; loopname[j] != '\0';) {
			if (loopname[j] >= 'a' && loopname[j] <= 'z') {
				loopname[j] -= 32;
			}

			if (loopname[j] == '\n') {
				loopname[j] = '\0';
			} else {
				j++;
			}
		}

		// Compare names
		osSyncPrintf("Compare '%s' to '%s' = %d\n", findname, loopname, strcmp(findname, loopname));

		if (strcmp(findname, loopname) == 0) {
			osSyncPrintf("OI! DUPLICATE FILE NAME! NO!\n");
			return false;
		}
	}

	return true;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b3384[] = "()()()()()() Writing MPLAYER\n";
const char var7f1b33a4[] = "()()()()()() Writing MGAME\n";
const char var7f1b33c0[] = "Write Attempt Made...\n";
const char var7f1b33d8[] = "decided location: %d\n";

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
				func0f1094e4(&thing, FILEOP_SAVE_MPPLAYER, (void *)g_MpPlayerNum);
			} else if (g_Menus[g_MpPlayerNum].unke3e == 7) {
				struct savelocation_2d8 thing;
				thing.unk00 = g_FileLists[g_Menus[g_MpPlayerNum].listnum]->unk2d8[g_Menus[g_MpPlayerNum].device].unk00;
				thing.unk04 = g_FileLists[g_Menus[g_MpPlayerNum].listnum]->unk2d8[g_Menus[g_MpPlayerNum].device].unk04;
				func0f1094e4(&thing, FILEOP_SAVE_MPSETUP, NULL);
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
#endif

#if VERSION >= VERSION_NTSC_1_0
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
#endif

#if VERSION >= VERSION_NTSC_1_0
s32 filemgrDuplicateRenameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPushDialog(&g_FilemgrRenameMenuDialog);
	}

	return 0;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
s32 filemgrDuplicateCancelMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();
	}

	return 0;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
char *filemgrMenuTextDeviceNameContainingDuplicateFile(struct menuitem *item)
{
	return filemgrGetDeviceName(g_Menus[g_MpPlayerNum].device);
}
#endif

#if VERSION >= VERSION_NTSC_1_0
char *filemgrMenuTextDuplicateFileName(struct menuitem *item)
{
	char buffer[32];

	filemgrGetRenameName(buffer);
	sprintf(g_StringPointer, "%s\n", buffer);

	return g_StringPointer;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
struct menuitem g_FilemgrRenameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_239, 0x00000000, NULL }, // "Enter new file name:"
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, filemgrConfirmRenameMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrRenameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_238, // "Change File Name"
	g_FilemgrRenameMenuItems,
	NULL,
	0x00000080,
	NULL,
};
#endif

#if VERSION >= VERSION_NTSC_1_0
struct menuitem g_FilemgrDuplicateMenuMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&filemgrMenuTextDeviceNameContainingDuplicateFile, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS_233, 0x00000000, NULL }, // "already contains"
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS_234, 0x00000000, NULL }, // "a file named"
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, (u32)&filemgrMenuTextDuplicateFileName, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPWEAPONS_235, 0x00000000, filemgrDuplicateRenameMenuHandler }, // "Rename File"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPWEAPONS_236, 0x00000000, NULL }, // "Change Location"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPWEAPONS_237, 0x00000000, filemgrDuplicateCancelMenuHandler }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrDuplicateNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_232, // "Duplicate File Name"
	g_FilemgrDuplicateMenuMenuItems,
	NULL,
	0x00000080,
	NULL,
};
#endif

#if VERSION >= VERSION_NTSC_1_0
char *filemgrMenuTextLocationName2(struct menuitem *item)
{
	u16 names[] = {
		L_OPTIONS_112, // "Controller Pak 1"
		L_OPTIONS_113, // "Controller Pak 2"
		L_OPTIONS_114, // "Controller Pak 3"
		L_OPTIONS_115, // "Controller Pak 4"
#if VERSION >= VERSION_NTSC_1_0
		L_OPTIONS_111, // "Game Pak"
		L_OPTIONS_004,   // ""
#endif
	};

	if (g_FileLists[g_Menus[g_MpPlayerNum].listnum] == NULL) {
		return NULL;
	}

	if (g_FileLists[g_Menus[g_MpPlayerNum].listnum]->spacesfree[item->param] < 0) {
		return langGet(names[5]);
	}

	return langGet(names[item->param]);
}
#else
GLOBAL_ASM(
glabel filemgrMenuTextLocationName2
/*  f105228:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f10522c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f105230:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f105234:	25ce6bd8 */ 	addiu	$t6,$t6,0x6bd8
/*  f105238:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f10523c:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f105240:	3c088007 */ 	lui	$t0,0x8007
/*  f105244:	aca10000 */ 	sw	$at,0x0($a1)
/*  f105248:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f10524c:	3c0a800a */ 	lui	$t2,0x800a
/*  f105250:	3c028007 */ 	lui	$v0,0x8007
/*  f105254:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f105258:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f10525c:	aca10008 */ 	sw	$at,0x8($a1)
/*  f105260:	8d083af0 */ 	lw	$t0,0x3af0($t0)
/*  f105264:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f105268:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10526c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f105270:	01284823 */ 	subu	$t1,$t1,$t0
/*  f105274:	00094900 */ 	sll	$t1,$t1,0x4
/*  f105278:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10527c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f105280:	01495021 */ 	addu	$t2,$t2,$t1
/*  f105284:	914a355b */ 	lbu	$t2,0x355b($t2)
/*  f105288:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f10528c:	004b1021 */ 	addu	$v0,$v0,$t3
/*  f105290:	8c427f60 */ 	lw	$v0,0x7f60($v0)
/*  f105294:	54400004 */ 	bnezl	$v0,.NB0f1052a8
/*  f105298:	90830001 */ 	lbu	$v1,0x1($a0)
/*  f10529c:	1000000e */ 	beqz	$zero,.NB0f1052d8
/*  f1052a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1052a4:	90830001 */ 	lbu	$v1,0x1($a0)
.NB0f1052a8:
/*  f1052a8:	00436021 */ 	addu	$t4,$v0,$v1
/*  f1052ac:	818d02d2 */ 	lb	$t5,0x2d2($t4)
/*  f1052b0:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f1052b4:	00b87821 */ 	addu	$t7,$a1,$t8
/*  f1052b8:	1da00005 */ 	bgtz	$t5,.NB0f1052d0
/*  f1052bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1052c0:	0fc5a4dd */ 	jal	langGet
/*  f1052c4:	97a4002e */ 	lhu	$a0,0x2e($sp)
/*  f1052c8:	10000004 */ 	beqz	$zero,.NB0f1052dc
/*  f1052cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f1052d0:
/*  f1052d0:	0fc5a4dd */ 	jal	langGet
/*  f1052d4:	95e40000 */ 	lhu	$a0,0x0($t7)
.NB0f1052d8:
/*  f1052d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f1052dc:
/*  f1052dc:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1052e0:	03e00008 */ 	jr	$ra
/*  f1052e4:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

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
		return langGet(L_OPTIONS_372); // "Full"
	}

	sprintf(g_StringPointer, "%d", spacesfree);
	return g_StringPointer;
}

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f1053a0nb
/*  f1053a0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1053a4:	8dce3af0 */ 	lw	$t6,0x3af0($t6)
/*  f1053a8:	3c18800a */ 	lui	$t8,0x800a
/*  f1053ac:	3c098007 */ 	lui	$t1,0x8007
/*  f1053b0:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f1053b4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1053b8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f1053bc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1053c0:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1053c4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1053c8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1053cc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1053d0:	9318355b */ 	lbu	$t8,0x355b($t8)
/*  f1053d4:	25297f60 */ 	addiu	$t1,$t1,0x7f60
/*  f1053d8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f1053dc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1053e0:	01395021 */ 	addu	$t2,$t1,$t9
/*  f1053e4:	8d420000 */ 	lw	$v0,0x0($t2)
/*  f1053e8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1053ec:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f1053f0:	14400003 */ 	bnez	$v0,.NB0f105400
/*  f1053f4:	00a03825 */ 	or	$a3,$a1,$zero
/*  f1053f8:	1000006f */ 	beqz	$zero,.NB0f1055b8
/*  f1053fc:	00001025 */ 	or	$v0,$zero,$zero
.NB0f105400:
/*  f105400:	2401000c */ 	addiu	$at,$zero,0xc
/*  f105404:	54810009 */ 	bnel	$a0,$at,.NB0f10542c
/*  f105408:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10540c:	90eb0001 */ 	lbu	$t3,0x1($a3)
/*  f105410:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f105414:	818d02d2 */ 	lb	$t5,0x2d2($t4)
/*  f105418:	5da00004 */ 	bgtzl	$t5,.NB0f10542c
/*  f10541c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f105420:	10000065 */ 	beqz	$zero,.NB0f1055b8
/*  f105424:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f105428:	24010006 */ 	addiu	$at,$zero,0x6
.NB0f10542c:
/*  f10542c:	54810062 */ 	bnel	$a0,$at,.NB0f1055b8
/*  f105430:	00001025 */ 	or	$v0,$zero,$zero
/*  f105434:	0fc3c088 */ 	jal	menuPopDialog
/*  f105438:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f10543c:	3c088007 */ 	lui	$t0,0x8007
/*  f105440:	8d083af0 */ 	lw	$t0,0x3af0($t0)
/*  f105444:	3c0f800a */ 	lui	$t7,0x800a
/*  f105448:	25ef27c0 */ 	addiu	$t7,$t7,0x27c0
/*  f10544c:	000870c0 */ 	sll	$t6,$t0,0x3
/*  f105450:	01c87023 */ 	subu	$t6,$t6,$t0
/*  f105454:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f105458:	01c87023 */ 	subu	$t6,$t6,$t0
/*  f10545c:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f105460:	01c87023 */ 	subu	$t6,$t6,$t0
/*  f105464:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f105468:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f10546c:	90620d9a */ 	lbu	$v0,0xd9a($v1)
/*  f105470:	3c098007 */ 	lui	$t1,0x8007
/*  f105474:	25297f60 */ 	addiu	$t1,$t1,0x7f60
/*  f105478:	14400005 */ 	bnez	$v0,.NB0f105490
/*  f10547c:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f105480:	0fc41475 */ 	jal	func0f109954
/*  f105484:	90e40001 */ 	lbu	$a0,0x1($a3)
/*  f105488:	1000004b */ 	beqz	$zero,.NB0f1055b8
/*  f10548c:	00001025 */ 	or	$v0,$zero,$zero
.NB0f105490:
/*  f105490:	24010005 */ 	addiu	$at,$zero,0x5
/*  f105494:	10410047 */ 	beq	$v0,$at,.NB0f1055b4
/*  f105498:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10549c:	54410016 */ 	bnel	$v0,$at,.NB0f1054f8
/*  f1054a0:	24010007 */ 	addiu	$at,$zero,0x7
/*  f1054a4:	90780d9b */ 	lbu	$t8,0xd9b($v1)
/*  f1054a8:	90eb0001 */ 	lbu	$t3,0x1($a3)
/*  f1054ac:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f1054b0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1054b4:	01395021 */ 	addu	$t2,$t1,$t9
/*  f1054b8:	8d420000 */ 	lw	$v0,0x0($t2)
/*  f1054bc:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f1054c0:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f1054c4:	004c6821 */ 	addu	$t5,$v0,$t4
/*  f1054c8:	8dae02d8 */ 	lw	$t6,0x2d8($t5)
/*  f1054cc:	01003025 */ 	or	$a2,$t0,$zero
/*  f1054d0:	afae0038 */ 	sw	$t6,0x38($sp)
/*  f1054d4:	90ef0001 */ 	lbu	$t7,0x1($a3)
/*  f1054d8:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f1054dc:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f1054e0:	972a02dc */ 	lhu	$t2,0x2dc($t9)
/*  f1054e4:	0fc41358 */ 	jal	func0f1094e4
/*  f1054e8:	a7aa003c */ 	sh	$t2,0x3c($sp)
/*  f1054ec:	10000032 */ 	beqz	$zero,.NB0f1055b8
/*  f1054f0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1054f4:	24010007 */ 	addiu	$at,$zero,0x7
.NB0f1054f8:
/*  f1054f8:	54410016 */ 	bnel	$v0,$at,.NB0f105554
/*  f1054fc:	28410009 */ 	slti	$at,$v0,0x9
/*  f105500:	906b0d9b */ 	lbu	$t3,0xd9b($v1)
/*  f105504:	90ee0001 */ 	lbu	$t6,0x1($a3)
/*  f105508:	27a40030 */ 	addiu	$a0,$sp,0x30
/*  f10550c:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f105510:	012c6821 */ 	addu	$t5,$t1,$t4
/*  f105514:	8da20000 */ 	lw	$v0,0x0($t5)
/*  f105518:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10551c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f105520:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f105524:	8f1902d8 */ 	lw	$t9,0x2d8($t8)
/*  f105528:	00003025 */ 	or	$a2,$zero,$zero
/*  f10552c:	afb90030 */ 	sw	$t9,0x30($sp)
/*  f105530:	90ea0001 */ 	lbu	$t2,0x1($a3)
/*  f105534:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f105538:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f10553c:	958d02dc */ 	lhu	$t5,0x2dc($t4)
/*  f105540:	0fc41358 */ 	jal	func0f1094e4
/*  f105544:	a7ad0034 */ 	sh	$t5,0x34($sp)
/*  f105548:	1000001b */ 	beqz	$zero,.NB0f1055b8
/*  f10554c:	00001025 */ 	or	$v0,$zero,$zero
/*  f105550:	28410009 */ 	slti	$at,$v0,0x9
.NB0f105554:
/*  f105554:	14200015 */ 	bnez	$at,.NB0f1055ac
/*  f105558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10555c:	906e0d9b */ 	lbu	$t6,0xd9b($v1)
/*  f105560:	90f90001 */ 	lbu	$t9,0x1($a3)
/*  f105564:	27a40028 */ 	addiu	$a0,$sp,0x28
/*  f105568:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10556c:	012fc021 */ 	addu	$t8,$t1,$t7
/*  f105570:	8f020000 */ 	lw	$v0,0x0($t8)
/*  f105574:	001950c0 */ 	sll	$t2,$t9,0x3
/*  f105578:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f10557c:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f105580:	8d6c02d8 */ 	lw	$t4,0x2d8($t3)
/*  f105584:	00003025 */ 	or	$a2,$zero,$zero
/*  f105588:	afac0028 */ 	sw	$t4,0x28($sp)
/*  f10558c:	90ed0001 */ 	lbu	$t5,0x1($a3)
/*  f105590:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f105594:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f105598:	95f802dc */ 	lhu	$t8,0x2dc($t7)
/*  f10559c:	0fc41358 */ 	jal	func0f1094e4
/*  f1055a0:	a7b8002c */ 	sh	$t8,0x2c($sp)
/*  f1055a4:	10000004 */ 	beqz	$zero,.NB0f1055b8
/*  f1055a8:	00001025 */ 	or	$v0,$zero,$zero
.NB0f1055ac:
/*  f1055ac:	0fc41414 */ 	jal	func0f1097d0
/*  f1055b0:	90e40001 */ 	lbu	$a0,0x1($a3)
.NB0f1055b4:
/*  f1055b4:	00001025 */ 	or	$v0,$zero,$zero
.NB0f1055b8:
/*  f1055b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1055bc:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f1055c0:	03e00008 */ 	jr	$ra
/*  f1055c4:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b33fc[] = "GOT OKed!, item->data = %d\n";
const char var7f1b3418[] = "GOT CANCELLED!\n";
const char var7f1b3428[] = "Picking Location, type %d wadtype %d wad %d\n";
const char var7f1b3458[] = "Torching file %d\n";
const char var7f1b346c[] = "Copying file %d\n";
const char var7f1b3480[] = "item: %x\n";
const char var7f1b348c[] = "Switched Wads Back\n";
const char var7f1b34a0[] = "MenuClosed\n";
const char var7f1b34ac[] = "Deleting files, wad %d\n";
#endif

#if VERSION >= VERSION_NTSC_1_0
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
#endif

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

void filemgrPushSelectLocationDialog(s32 arg0, u32 filetype)
{
	g_Menus[g_MpPlayerNum].unke3e = arg0;
	g_Menus[g_MpPlayerNum].listnum = func0f110cf8(filetype);

#if VERSION >= VERSION_NTSC_1_0
	filelistsTick();
#endif

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

#if VERSION >= VERSION_NTSC_1_0
char *filemgrMenuTextFileInUseDescription(struct menuitem *item)
{
	if (menuIsDialogOpen(&g_FilemgrCopyMenuDialog)) {
		return langGet(L_MPWEAPONS_240); // "The file you are copying cannot be deleted."
	}

	return langGet(L_MPWEAPONS_160); // "Cannot delete file as it is being used."
}
#endif

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

bool filemgrIsFileInUse(struct filelistfile *file)
{
	s32 i;

#if VERSION >= VERSION_NTSC_1_0
	if (menuIsDialogOpen(&g_FilemgrCopyMenuDialog)
			&& file->unk00 == g_FilemgrFileToCopy.unk00
			&& file->unk04 == g_FilemgrFileToCopy.unk04) {
		return true;
	}

	if (menuIsDialogOpen(&g_FilemgrFileSelect4MbMenuDialog)) {
		return false;
	}
#else
	if (g_MenuData.root == MENUROOT_FILEMGR
			&& menuIsDialogOpen(&g_FilemgrCopyMenuDialog)
			&& file->unk00 == g_FilemgrFileToCopy.unk00
			&& file->unk04 == g_FilemgrFileToCopy.unk04) {
		return true;
	}
#endif

	if (g_MenuData.root == MENUROOT_FILEMGR) {
		return false;
	}

	if (file->unk00 == g_FilemgrLoadedMainFile.unk00 && file->unk04 == g_FilemgrLoadedMainFile.unk04) {
		return true;
	}

	if (file->unk00 == g_MpSetup.unk20.unk00 && file->unk04 == g_MpSetup.unk20.unk04) {
		return true;
	}

	for (i = 0; i < 4; i++) {
		if ((g_MpSetup.chrslots & (1 << i))
				&& g_MpPlayers[i].unk4c.unk00 == file->unk00
				&& g_MpPlayers[i].unk4c.unk04 == file->unk04) {
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
			struct filelistfile *file = &list->files[data->list.unk04];

			if (g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone == 4) {
				gdl = filemgrRenderPerfectHeadThumbnail(gdl, renderdata, file->unk00, file->unk04);
			} else {
				u32 colour = renderdata->colour;
				char text[32];

				if (isdelete && filemgrIsFileInUse(file)) {
					colour = 0xff333300 | (colour & 0xff);
				}

				x = renderdata->x + 2;
				y = renderdata->y + 2;

				gdl = func0f153628(gdl);

				if (file) {
					filemgrGetSelectName(text, file, g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone - 1);
					gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm,
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
		struct filelistfile *file = &g_FileLists[g_Menus[g_MpPlayerNum].listnum]->files[data->list.value];

		if (file) {
			if (filemgrIsFileInUse(file)) {
				func0f1083d0(file, g_FileLists[g_Menus[g_MpPlayerNum].listnum]->filetype);
				menuPushDialog(&g_FilemgrFileInUseMenuDialog);
			} else {
				func0f1083d0(file, g_FileLists[g_Menus[g_MpPlayerNum].listnum]->filetype);
				g_FilemgrFileToDelete.unk00 = file->unk00;
				g_FilemgrFileToDelete.unk04 = file->unk04;
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
		struct filelistfile *file = &list->files[data->list.value];

		if (file) {
			g_FilemgrFileToCopy.unk00 = file->unk00;
			g_FilemgrFileToCopy.unk04 = file->unk04;

#if VERSION >= VERSION_NTSC_1_0
			filemgrGetFileName(g_Menus[g_MpPlayerNum].unke53, file);
#endif
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
			func0f110c5c(0, FILETYPE_GAME);
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
		gdl = textRenderProjected(gdl, &x, &y, generalbuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
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
			sprintf(generalbuffer, langGet(L_OPTIONS_392)); // "Empty"
			sprintf(pagesbuffer, langGet(L_OPTIONS_393)); // "--"
			sprintf(extbuffer, "", tmpname, tmpext);
		}

		// Render note name
		x = renderdata->x + 20;
		y = renderdata->y + 1;
		gdl = textRenderProjected(gdl, &x, &y, generalbuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
				renderdata->colour, viGetWidth(), viGetHeight(), 0, 1);

		// Render ext character (for when a game has multiple notes)
		x = renderdata->x + 190;
		y = renderdata->y + 1;
		gdl = textRenderProjected(gdl, &x, &y, extbuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
				renderdata->colour, viGetWidth(), viGetHeight(), 0, 1);

		// Render number of pages
		textMeasure(&textheight, &textwidth, pagesbuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

		x = renderdata->x + renderdata->width - textwidth - 6;
		y = renderdata->y + 1;
		gdl = textRenderProjected(gdl, &x, &y, pagesbuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
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

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b34dc[] = "GOT OKed!\n";
const char var7f1b34e8[] = "Try to find last opened file...\n";
#endif

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
		sprintf(g_StringPointer, langGet(L_OPTIONS_394)); // "Pages Free: "
	} else {
		sprintf(g_StringPointer, langGet(L_OPTIONS_395), g_EditingPak->pagesfree); // "Pages Free: %d"
	}

	return g_StringPointer;
}

char *pakMenuTextPagesUsed(struct menuitem *item)
{
	if (g_EditingPak == NULL) {
		sprintf(g_StringPointer2, langGet(L_OPTIONS_396)); // "Pages Used: "
	} else {
		sprintf(g_StringPointer2, langGet(L_OPTIONS_397), g_EditingPak->pagesused); // "Pages Used: %d"
	}

	return g_StringPointer2;
}

char *pakMenuTextStatusMessage(struct menuitem *item)
{
	ubool haspdnote = false;
	ubool hasemptynote = false;
	s32 i;

	if (g_EditingPak == NULL) {
		return langGet(L_OPTIONS_398); // "Perfect Dark note already exists on this Controller Pak."
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
		return langGet(L_OPTIONS_398); // "Perfect Dark note already exists on this Controller Pak."
	}

	if (g_EditingPak->pagesfree < 28 || !hasemptynote) {
		return langGet(L_OPTIONS_400); // "Controller Pak is too full to save note- 1 note and 28 pages required to save to Controller Pak."
	}

	return langGet(L_OPTIONS_399); // "There is enough space for Perfect Dark note."
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

#if VERSION >= VERSION_NTSC_1_0
s32 pakChoosePakMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		joy0001398c(3);
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
		joy000139c8();
		break;
	}

	return 0;
}
#else
GLOBAL_ASM(
glabel pakChoosePakMenuDialog
/*  f106af8:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f106afc:	24010064 */ 	addiu	$at,$zero,0x64
/*  f106b00:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f106b04:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f106b08:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f106b0c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f106b10:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f106b14:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f106b18:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f106b1c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f106b20:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f106b24:	10810009 */ 	beq	$a0,$at,.NB0f106b4c
/*  f106b28:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f106b2c:	24010065 */ 	addiu	$at,$zero,0x65
/*  f106b30:	10810019 */ 	beq	$a0,$at,.NB0f106b98
/*  f106b34:	00008025 */ 	or	$s0,$zero,$zero
/*  f106b38:	24010066 */ 	addiu	$at,$zero,0x66
/*  f106b3c:	50810013 */ 	beql	$a0,$at,.NB0f106b8c
/*  f106b40:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f106b44:	10000036 */ 	beqz	$zero,.NB0f106c20
/*  f106b48:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f106b4c:
/*  f106b4c:	0c00529c */ 	jal	joy0001398c
/*  f106b50:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f106b54:	0c00529c */ 	jal	joy0001398c
/*  f106b58:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f106b5c:	3c128007 */ 	lui	$s2,0x8007
/*  f106b60:	26523af0 */ 	addiu	$s2,$s2,0x3af0
/*  f106b64:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f106b68:	24130dbc */ 	addiu	$s3,$zero,0xdbc
/*  f106b6c:	3c11800a */ 	lui	$s1,0x800a
/*  f106b70:	01d30019 */ 	multu	$t6,$s3
/*  f106b74:	263127c0 */ 	addiu	$s1,$s1,0x27c0
/*  f106b78:	00007812 */ 	mflo	$t7
/*  f106b7c:	022fc021 */ 	addu	$t8,$s1,$t7
/*  f106b80:	10000026 */ 	beqz	$zero,.NB0f106c1c
/*  f106b84:	af000d80 */ 	sw	$zero,0xd80($t8)
/*  f106b88:	24190001 */ 	addiu	$t9,$zero,0x1
.NB0f106b8c:
/*  f106b8c:	3c018006 */ 	lui	$at,0x8006
/*  f106b90:	10000022 */ 	beqz	$zero,.NB0f106c1c
/*  f106b94:	a0394e54 */ 	sb	$t9,0x4e54($at)
.NB0f106b98:
/*  f106b98:	3c14800a */ 	lui	$s4,0x800a
/*  f106b9c:	3c128007 */ 	lui	$s2,0x8007
/*  f106ba0:	3c11800a */ 	lui	$s1,0x800a
/*  f106ba4:	263127c0 */ 	addiu	$s1,$s1,0x27c0
/*  f106ba8:	26523af0 */ 	addiu	$s2,$s2,0x3af0
/*  f106bac:	2694e6c0 */ 	addiu	$s4,$s4,-6464
/*  f106bb0:	24160004 */ 	addiu	$s6,$zero,0x4
/*  f106bb4:	2415005b */ 	addiu	$s5,$zero,0x5b
/*  f106bb8:	24130dbc */ 	addiu	$s3,$zero,0xdbc
/*  f106bbc:	8e480000 */ 	lw	$t0,0x0($s2)
.NB0f106bc0:
/*  f106bc0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f106bc4:	00102600 */ 	sll	$a0,$s0,0x18
/*  f106bc8:	01130019 */ 	multu	$t0,$s3
/*  f106bcc:	00004812 */ 	mflo	$t1
/*  f106bd0:	02295021 */ 	addu	$t2,$s1,$t1
/*  f106bd4:	8d4b0d80 */ 	lw	$t3,0xd80($t2)
/*  f106bd8:	020c6804 */ 	sllv	$t5,$t4,$s0
/*  f106bdc:	016d7024 */ 	and	$t6,$t3,$t5
/*  f106be0:	51c00008 */ 	beqzl	$t6,.NB0f106c04
/*  f106be4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f106be8:	8e9804b4 */ 	lw	$t8,0x4b4($s4)
/*  f106bec:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f106bf0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f106bf4:	03152826 */ 	xor	$a1,$t8,$s5
/*  f106bf8:	0fc44356 */ 	jal	func0f1169c8
/*  f106bfc:	2ca50001 */ 	sltiu	$a1,$a1,0x1
/*  f106c00:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f106c04:
/*  f106c04:	5616ffee */ 	bnel	$s0,$s6,.NB0f106bc0
/*  f106c08:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f106c0c:	0c00529f */ 	jal	joy000139c8
/*  f106c10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106c14:	0fc44b4a */ 	jal	func0f1189d0
/*  f106c18:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f106c1c:
/*  f106c1c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f106c20:
/*  f106c20:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f106c24:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f106c28:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f106c2c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f106c30:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f106c34:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f106c38:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f106c3c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f106c40:	03e00008 */ 	jr	$ra
/*  f106c44:	00001025 */ 	or	$v0,$zero,$zero
);
#endif

s32 filemgrOpenCopyFileMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].data.filemgr.filetypeplusone = item->param + 1;
		func0f110c5c(0, item->param);

#if VERSION >= VERSION_NTSC_1_0
		g_Menus[g_MpPlayerNum].listnum = 0;
#endif
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
		strcpy(name, g_GameFile.name);
		break;
	case MENUOP_SETTEXT:
		strcpy(g_GameFile.name, name);
		break;
	case MENUOP_SET:
		filemgrPushSelectLocationDialog(0, FILETYPE_GAME);
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
	struct filelistfile *file;
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
					if (g_FilemgrLoadedMainFile.unk00 == g_FileLists[0]->files[i].unk00
							&& g_FilemgrLoadedMainFile.unk04 == g_FileLists[0]->files[i].unk04) {
						data->list.value = i;
					}
				}

				g_Menus[g_MpPlayerNum].data.filemgr.unke2c = 0;
			}

			if (g_FileLists[0]->updatedthisframe) {
				pass = true;
			}
		} else {
			pass = true;
			g_Menus[g_MpPlayerNum].data.filemgr.unke2c = 0;
		}

		if (pass && g_Vars.unk00047c) {
			for (j = 0; j < g_FileLists[0]->numfiles; j++) {
				if (g_Vars.unk00047c == g_FileLists[0]->files[j].unk00
						&& g_Vars.unk000480 == g_FileLists[0]->files[j].unk04) {
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
		file = NULL;
		renderdata = data->type19.renderdata2;
		seconds = 0;
		minutes = 0;
		hours = 0;
		days = 0;

		if (data->list.unk04 != g_FileLists[0]->numfiles) {
			file = &g_FileLists[0]->files[data->list.unk04];

			if (file) {
				gamefileGetOverview(file->unk06, name, &stage, &difficulty, &time);

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
			gdl = textRenderProjected(gdl, &x, &y, langGet(L_OPTIONS_403),
					g_CharsHandelGothicMd, g_FontHandelGothicMd, renderdata->colour, viGetWidth(), viGetHeight(), 0, 0);
		} else if (file) {
			// Render file name
			gdl = textRenderProjected(gdl, &x, &y, name,
					g_CharsHandelGothicMd, g_FontHandelGothicMd, renderdata->colour, viGetWidth(), viGetHeight(), 0, 1);

			// Prepare and render stage name
			y = renderdata->y + 18;
			x = renderdata->x + 62;

			if (stage > 0) {
				sprintf(buffer, "%s %s",
						langGet(g_StageNames[stage - 1].name1),
						langGet(g_StageNames[stage - 1].name2));
			} else {
				// "New Recruit"
				strcpy(buffer, langGet(L_OPTIONS_404));
			}

			strcat(buffer, "\n");
			gdl = textRenderProjected(gdl, &x, &y, buffer,
					g_CharsHandelGothicSm, g_FontHandelGothicSm, renderdata->colour, viGetWidth(), viGetHeight(), 0, 0);

			// Prepare and render mission time
			x = renderdata->x + 62;
			y++;

			if (days > 0) {
				// "Mission Time:"
				sprintf(buffer, "%s %d:%02d:%02d", langGet(L_OPTIONS_405), days, hours, minutes);
			} else {
				// "Mission Time:"
				sprintf(buffer, "%s %02d:%02d", langGet(L_OPTIONS_405), hours, minutes);
			}

			// Useless - textwidth and textheight are not used
			textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

			gdl = textRenderProjected(gdl, &x, &y, buffer,
					g_CharsHandelGothicSm, g_FontHandelGothicSm, renderdata->colour, viGetWidth(), viGetHeight(), 0, 0);

			// Render seconds part of mission time (uses a smaller font)
			y++;
			x++;
			sprintf(buffer, ".%02d", seconds);
			gdl = textRenderProjected(gdl, &x, &y, buffer,
					g_CharsHandelGothicXs, g_FontHandelGothicXs, renderdata->colour, viGetWidth(), viGetHeight(), 0, 0);
		}
		gdl = func0f153780(gdl);
		return (u32) gdl;
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = 40;
		break;
	case MENUOP_SET:
		if (data->list.value == g_FileLists[0]->numfiles) {
			gamefileLoadDefaults(&g_GameFile);
			menuPushDialog(&g_FilemgrEnterNameMenuDialog);
		} else {
			struct filelistfile *file = &g_FileLists[0]->files[data->list.value];

			if (file) {
				g_FilemgrLoadedMainFile.unk00 = file->unk00;
				g_FilemgrLoadedMainFile.unk04 = file->unk04;
				func0f1094e4(&g_FilemgrLoadedMainFile, FILEOP_LOAD_GAME, 0);
			}
		}
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = g_FileLists[0]->unk30a + 1;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		if (data->list.value >= g_FileLists[0]->unk30a) {
			return (u32) langGet(L_OPTIONS_402); // "New..."
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

		func0f110c5c(0, FILETYPE_GAME);
		mpSetDefaultSetup();

		// Set MP player names to "Player 1" through 4 if blank
		for (i = 0; i < 4; i++) {
			if (g_MpPlayers[i].base.name[0] == '\0') {
				sprintf(g_MpPlayers[i].base.name, "%s %d\n", langGet(L_MISC_437), i + 1);
			}
		}
		break;
	case MENUOP_CLOSE:
		func0f110bf8();
		break;
#if VERSION < VERSION_NTSC_1_0
	case MENUOP_TICK:
		filelistsTick();
		break;
#endif
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
/*  f10d2b4:	0fc3e29d */ 	jal	menuPushRootDialog
/*  f10d2b8:	24050006 */ 	li	$a1,0x6
/*  f10d2bc:	3c08800a */ 	lui	$t0,0x800a
/*  f10d2c0:	9508a992 */ 	lhu	$t0,-0x566e($t0)
/*  f10d2c4:	3c048007 */ 	lui	$a0,0x8007
/*  f10d2c8:	29010006 */ 	slti	$at,$t0,0x6
/*  f10d2cc:	14200003 */ 	bnez	$at,.PF0f10d2dc
/*  f10d2d0:	00000000 */ 	nop
/*  f10d2d4:	0fc3cda8 */ 	jal	menuPushDialog
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

#if VERSION >= VERSION_NTSC_1_0
struct menuitem g_FilemgrSelectLocationMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0,                         0x00000010, L_OPTIONS_368, L_OPTIONS_369, NULL }, // "Where", "Spaces"
	{ MENUITEMTYPE_SEPARATOR,   0,                         0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  SAVEDEVICE_GAMEPAK,        0x00000000, (u32)&filemgrMenuTextLocationName2, (u32)&filemgrMenuTextSaveLocationSpaces, filemgrSelectLocationMenuHandler },
	{ MENUITEMTYPE_SELECTABLE,  SAVEDEVICE_CONTROLLERPAK1, 0x00000000, (u32)&filemgrMenuTextLocationName2, (u32)&filemgrMenuTextSaveLocationSpaces, filemgrSelectLocationMenuHandler },
	{ MENUITEMTYPE_SELECTABLE,  SAVEDEVICE_CONTROLLERPAK2, 0x00000000, (u32)&filemgrMenuTextLocationName2, (u32)&filemgrMenuTextSaveLocationSpaces, filemgrSelectLocationMenuHandler },
	{ MENUITEMTYPE_SELECTABLE,  SAVEDEVICE_CONTROLLERPAK3, 0x00000000, (u32)&filemgrMenuTextLocationName2, (u32)&filemgrMenuTextSaveLocationSpaces, filemgrSelectLocationMenuHandler },
	{ MENUITEMTYPE_SELECTABLE,  SAVEDEVICE_CONTROLLERPAK4, 0x00000000, (u32)&filemgrMenuTextLocationName2, (u32)&filemgrMenuTextSaveLocationSpaces, filemgrSelectLocationMenuHandler },
	{ MENUITEMTYPE_SEPARATOR,   0,                         0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0,                         0x00000000, L_OPTIONS_370, 0x00000000, filemgrDeleteFilesForSaveMenuHandler }, // "Delete Files..."
	{ MENUITEMTYPE_SELECTABLE,  0,                         0x00000000, L_OPTIONS_371, 0x00000000, filemgrCancelSaveMenuHandler }, // "Cancel"
	{ MENUITEMTYPE_END,         0,                         0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrSelectLocationMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_367, // "Select Location"
	g_FilemgrSelectLocationMenuItems,
	NULL,
	0x00000080,
	NULL,
};
#endif

struct menuitem g_FilemgrConfirmDeleteMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&filemgrMenuTextDeleteFileName, 0x00000000, filemgrFileNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000230, (u32)&filemgrMenuTextDeviceName, 0x00000000, filemgrDeviceNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_380, 0x00000000, NULL }, // "Are you sure you want to delete this file?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS_381, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_382, 0x00000000, filemgrConfirmDeleteMenuHandler }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrConfirmDeleteMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_379, // "Warning"
	g_FilemgrConfirmDeleteMenuItems,
	NULL,
	0x00000080,
	NULL,
};

#if VERSION >= VERSION_NTSC_1_0
struct menuitem g_FilemgrFileInUseMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&filemgrMenuTextDeleteFileName, 0x00000000, filemgrFileNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000230, (u32)&filemgrMenuTextDeviceName, 0x00000000, filemgrDeviceNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextFileInUseDescription, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS_161, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrFileInUseMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_159, // "Error"
	g_FilemgrFileInUseMenuItems,
	NULL,
	0x00000080,
	NULL,
};
#endif

struct menuitem g_FilemgrDeleteMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS_377, 0x00000000, NULL }, // "Select a file to delete:"
	{ MENUITEMTYPE_LIST,        1, 0x00200000, 0x00000000, 0x00000000, filemgrFileToDeleteListMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00004030, L_OPTIONS_378, 0x00000000, NULL }, // "Press B Button to exit."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrDeleteMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_376, // "Delete File"
	g_FilemgrDeleteMenuItems,
	filemgrCopyOrDeleteListMenuDialog,
	0x00000000,
	NULL,
};

struct menuitem g_FilemgrCopyMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS_374, 0x00000000, NULL }, // "Select a file to copy:"
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x00000000, 0x00000000, filemgrFileToCopyListMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00004030, L_OPTIONS_375, 0x00000000, NULL }, // "Press B Button to exit."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrCopyMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_373, // "Copy File"
	g_FilemgrCopyMenuItems,
	filemgrCopyOrDeleteListMenuDialog,
	0x00000000,
	NULL,
};

struct pakdata *g_EditingPak = NULL;

struct menuitem g_PakDeleteNoteMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_384, 0x00000000, NULL }, // "Are you sure you want to delete this game note?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS_385, 0x00000000, NULL }, // "No"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_386, 0x00000000, pakDeleteGameNoteMenuHandler }, // "Yes"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_PakDeleteNoteMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_383, // "Delete Game Note"
	g_PakDeleteNoteMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_PakGameNotesMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_388, (u32)&pakMenuTextEditingPakName, NULL }, // "Delete Game Notes:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x0000010e, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_389, L_OPTIONS_390, NULL }, // "Note", "Pages"
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x000000c8, 0x0000006e, pakGameNoteListMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&pakMenuTextPagesFree, (u32)&pakMenuTextPagesUsed, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&pakMenuTextStatusMessage, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, L_OPTIONS_391, 0x00000000, NULL }, // "Press the B Button to exit."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_PakGameNotesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_387, // "Game Notes"
	g_PakGameNotesMenuItems,
	pakGameNotesMenuDialog,
	0x00000000,
	NULL,
};

struct menuitem g_PakChoosePakMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_108, 0x00000000, NULL }, // "Use this menu to delete game notes from your Controller Pak"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_109, 0x00000000, NULL }, // "Choose Controller Pak to Edit:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS_112, 0x00000000, pakSelectionMenuHandler }, // "Controller Pak 1"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS_113, 0x00000000, pakSelectionMenuHandler }, // "Controller Pak 2"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS_114, 0x00000000, pakSelectionMenuHandler }, // "Controller Pak 3"
	{ MENUITEMTYPE_SELECTABLE,  3, 0x00000000, L_OPTIONS_115, 0x00000000, pakSelectionMenuHandler }, // "Controller Pak 4"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS_110, 0x00000000, NULL }, // "Exit"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_PakChoosePakMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_107, // "Controller Pak Menu"
	g_PakChoosePakMenuItems,
	pakChoosePakMenuDialog,
	0x00000000,
	NULL,
};

struct menuitem g_FilemgrOperationsMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0,                 0x00004010, L_OPTIONS_100, 0x00000000, NULL }, // "Copy:"
	{ MENUITEMTYPE_SELECTABLE,  FILETYPE_GAME,     0x00000000, L_OPTIONS_103, 0x00000000, filemgrOpenCopyFileMenuHandler }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  FILETYPE_MPSETUP , 0x00000000, L_OPTIONS_104, 0x00000000, filemgrOpenCopyFileMenuHandler }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  FILETYPE_MPPLAYER, 0x00000000, L_OPTIONS_105, 0x00000000, filemgrOpenCopyFileMenuHandler }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0,                 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0,                 0x00004010, L_OPTIONS_101, 0x00000000, NULL }, // "Delete:"
	{ MENUITEMTYPE_SELECTABLE,  FILETYPE_GAME,     0x00000000, L_OPTIONS_103, 0x00000000, filemgrOpenDeleteFileMenuHandler }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  FILETYPE_MPSETUP,  0x00000000, L_OPTIONS_104, 0x00000000, filemgrOpenDeleteFileMenuHandler }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  FILETYPE_MPPLAYER, 0x00000000, L_OPTIONS_105, 0x00000000, filemgrOpenDeleteFileMenuHandler }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0,                 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0,                 0x00000004, L_OPTIONS_102, 0x00000000, (void *)&g_PakChoosePakMenuDialog }, // "Delete Game Notes..."
	{ MENUITEMTYPE_END,         0,                 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrOperationsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_099, // "Game Files"
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
	L_OPTIONS_401, // "Enter Agent Name"
	g_FilemgrEnterNameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_FilemgrFileSelectMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS_096, 0x00000000, NULL }, // "Choose Your Reality"
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x000000f5, 0x00000000, filemgrChooseAgentListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_FilemgrFileSelectMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_095, // "Perfect Dark"
	g_FilemgrFileSelectMenuItems,
	filemgrMainMenuDialog,
	0x00000020,
	&g_FilemgrOperationsMenuDialog,
};
