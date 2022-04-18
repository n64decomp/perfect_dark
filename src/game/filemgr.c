#include <ultra64.h>
#include "constants.h"
#include "game/filelist.h"
#include "game/tex.h"
#include "game/savebuffer.h"
#include "game/menu.h"
#include "game/filemgr.h"
#include "game/bossfile.h"
#include "game/game_1531a0.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/mema.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"

// bss
struct fileguid g_FilemgrFileToCopy;
struct fileguid var800a21e8;
struct fileguid g_FilemgrFileToDelete;
#if VERSION == VERSION_JPN_FINAL
u8 jpnfill3[0x18];
#endif
s32 g_FilemgrLastPakError;
#if VERSION == VERSION_JPN_FINAL
u8 jpnfill4[8];
#endif
struct gamefile g_GameFile;
u32 var800a22bc;
struct fileguid g_GameFileGuid;

// These might be able to be removed by relocating their symbols
struct menudialogdef g_FilemgrCopyMenuDialog;
struct menudialogdef g_FilemgrConfirmDeleteMenuDialog;
struct menudialogdef g_FilemgrDeleteMenuDialog;
struct menudialogdef g_FilemgrEnterNameMenuDialog;
struct menudialogdef g_FilemgrErrorMenuDialog;
struct menudialogdef g_FilemgrFileInUseMenuDialog;
struct menudialogdef g_FilemgrFileLostMenuDialog;
struct menudialogdef g_FilemgrFileSavedMenuDialog;
struct menudialogdef g_FilemgrFileSelectMenuDialog;
struct menudialogdef g_FilemgrSaveElsewhereMenuDialog;
struct menudialogdef g_FilemgrSaveErrorMenuDialog;
struct menudialogdef g_FilemgrSelectLocationMenuDialog;
struct menudialogdef g_PakDeleteNoteMenuDialog;
struct menudialogdef g_PakGameNotesMenuDialog;
struct menudialogdef g_PakNotOriginalMenuDialog;
struct pakdata *g_EditingPak;

#if VERSION >= VERSION_NTSC_1_0
struct menudialogdef g_FilemgrDuplicateNameMenuDialog;
struct menudialogdef g_FilemgrRenameMenuDialog;
#endif

#if PAL
s32 filemgrHandleSetLanguage(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Vars.language = item->param;
		langSetEuropean(g_Vars.language);
		menuPopDialog();
	}

	return 0;
}

struct menuitem g_ChooseLanguageMenuItems[] = {
	{ MENUITEMTYPE_LABEL,      0,               0x00004010, L_MPWEAPONS_261, 0x00000000, 0x00000000     }, // "Choose your language:"
	{ MENUITEMTYPE_SEPARATOR,  0,               0x00000000, 0x00000000, 0x00000000, 0x00000000     },
	{ MENUITEMTYPE_SELECTABLE, LANGUAGE_PAL_EN, 0x00000020, L_MPWEAPONS_262, 0x00000000, filemgrHandleSetLanguage }, // "English"
	{ MENUITEMTYPE_SELECTABLE, LANGUAGE_PAL_FR, 0x00000020, L_MPWEAPONS_263, 0x00000000, filemgrHandleSetLanguage }, // "French"
	{ MENUITEMTYPE_SELECTABLE, LANGUAGE_PAL_DE, 0x00000020, L_MPWEAPONS_264, 0x00000000, filemgrHandleSetLanguage }, // "German"
	{ MENUITEMTYPE_SELECTABLE, LANGUAGE_PAL_IT, 0x00000020, L_MPWEAPONS_265, 0x00000000, filemgrHandleSetLanguage }, // "Italian"
	{ MENUITEMTYPE_SELECTABLE, LANGUAGE_PAL_ES, 0x00000020, L_MPWEAPONS_266, 0x00000000, filemgrHandleSetLanguage }, // "Spanish"
	{ MENUITEMTYPE_END,        0,               0x00000000, 0x00000000, 0x00000000, 0x00000000     },
};

struct menudialogdef g_ChooseLanguageMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_095,
	g_ChooseLanguageMenuItems,
	NULL,
	MENUDIALOGFLAG_IGNOREBACK,
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
		if ((g_Menus[g_MpPlayerNum].fm.device1 & 0x7f) >= SAVEDEVICE_INVALID) {
			return true;
		}
	}

	return 0;
}

char *filemgrMenuTextDeviceName(struct menuitem *item)
{
	return filemgrGetDeviceName(g_Menus[g_MpPlayerNum].fm.device1 & 0x7f);
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
		func0f0d564c(file->name, tmpbuffer1, false);
		break;
	case FILETYPE_MPPLAYER:
		// MP Player filenames have the play duration appended to the name
		mpplayerfileGetOverview(file->name, namebuffer, &totalinseconds);
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

// game, mpsetup, mpplayer, perfect head
const u32 g_FileTypeSizes[] = {0xa0, 0x31, 0x4e, 0x4a0};

s32 filemgrFileNameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_Menus[g_MpPlayerNum].fm.filetodelete == 0) {
			return true;
		}
	}

	return 0;
}

char *filemgrMenuTextDeleteFileName(struct menuitem *item)
{
	if (g_Menus[g_MpPlayerNum].fm.filetodelete) {
		filemgrGetSelectName(g_StringPointer,
				g_Menus[g_MpPlayerNum].fm.filetodelete,
				g_Menus[g_MpPlayerNum].fm.filetypetodelete);
		return g_StringPointer;
	}

	return NULL;
}

void filemgrSetDevice1BySerial(s32 deviceserial)
{
	s32 device = pakFindBySerial(deviceserial);

	if (device >= 0) {
		g_Menus[g_MpPlayerNum].fm.device1 = device;
	} else {
#if VERSION >= VERSION_NTSC_1_0
		g_Menus[g_MpPlayerNum].fm.device1 = SAVEDEVICE_INVALID;
#else
		g_Menus[g_MpPlayerNum].fm.device1 = 0x7f;
#endif
	}
}

void filemgrSetDevice1ByFile(struct filelistfile *file)
{
	filemgrSetDevice1BySerial(file->deviceserial);
}

void filemgrSetFileToDelete(struct filelistfile *file, s32 filetype)
{
	g_Menus[g_MpPlayerNum].fm.filetypetodelete = filetype;
	g_Menus[g_MpPlayerNum].fm.filetodelete = file;
	filemgrSetDevice1ByFile(file);
}

char *filemgrMenuTextFailReason(struct menuitem *item)
{
	static u16 reasons[] = {
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

	return langGet(reasons[g_Menus[g_MpPlayerNum].fm.errno]);
}

/**
 * Unused.
 */
char *filemgr0f108484(struct menuitem *item)
{
	sprintf(g_StringPointer, "location: controller pak 1\n");
	return g_StringPointer;
}

s32 filemgrDeviceNameForErrorMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if ((g_Menus[g_MpPlayerNum].fm.device1 & 0x7f) >= SAVEDEVICE_INVALID) {
			return true;
		}

		switch (g_Menus[g_MpPlayerNum].fm.errno) {
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
	sprintf(g_StringPointer, "%s", filemgrGetDeviceName(g_Menus[g_MpPlayerNum].fm.device1 & 0x7f));

	if (g_Menus[g_MpPlayerNum].fm.errno != FILEERROR_PAKREMOVED) {
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
	g_Menus[g_MpPlayerNum].fm.errno = errno;

	menuPushDialog(&g_FilemgrErrorMenuDialog);
}

struct menuitem g_FilemgrErrorMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextDeviceNameForError, 0x00000000, filemgrDeviceNameForErrorMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextFailReason, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS_321, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FilemgrErrorMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_320, // "Error"
	g_FilemgrErrorMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLEBANNER,
	NULL,
};

/**
 * For a file listing, iterate the devices until the one at optionindex is found.
 * Depending on operation, return the device name or index of the first file.
 */
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

	switch (g_Menus[g_MpPlayerNum].fm.fileop) {
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

	switch (g_Menus[g_MpPlayerNum].fm.fileop) {
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
	menuSetBanner(-1, false);

	switch (g_Menus[g_MpPlayerNum].fm.fileop) {
	case FILEOP_WRITE_GAME:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_WRITE_MPPLAYER:
	case FILEOP_READ_GAME:
	case FILEOP_READ_MPSETUP:
	case FILEOP_READ_MPPLAYER:
		memaFree(g_Menus[g_MpPlayerNum].fm.unke44, align16(g_FileTypeSizes[g_Menus[g_MpPlayerNum].fm.filetypeplusone - 1]));
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
	menuSetBanner(-1, false);

	switch (g_Menus[g_MpPlayerNum].fm.fileop) {
	case FILEOP_WRITE_GAME:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_WRITE_MPPLAYER:
		memaFree(g_Menus[g_MpPlayerNum].fm.unke44,
				align16(g_FileTypeSizes[g_Menus[g_MpPlayerNum].fm.filetypeplusone - 1]));
		break;
	case FILEOP_LOAD_GAME:
		g_Vars.bossfileid = g_Menus[g_MpPlayerNum].fm.fileid;
		g_Vars.bossdeviceserial = g_Menus[g_MpPlayerNum].fm.deviceserial;
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
		filemgrSaveOrLoad(&var800a21e8,
				g_Menus[g_MpPlayerNum].fm.fileop - 98,
				g_Menus[g_MpPlayerNum].fm.mpplayernum);
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

		switch (g_Menus[g_MpPlayerNum].fm.fileop) {
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

		filemgrPushSelectLocationDialog(g_Menus[g_MpPlayerNum].fm.fileop + 9, filetype);
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
s32 filemgr0f108d14(s32 operation, struct menuitem *item, union handlerdata *data)
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
	s32 device;
	s32 i;

	device = pakFindBySerial(g_Menus[g_MpPlayerNum].fm.deviceserial);

	if (device >= 0) {
		pakDeleteFile(device, g_Menus[g_MpPlayerNum].fm.fileid);
	}

	for (i = 0; i < 4; i++) {
		if (g_FileLists[i]) {
			g_FileLists[i]->timeuntilupdate = 1;
		}
	}

	menuPushDialog(&g_FilemgrFileLostMenuDialog);
}
#endif

s32 filemgrInsertOriginalPakMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curdialog &&
				g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef) {
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
		if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fm.fileop) && g_Menus[g_MpPlayerNum].fm.fileop != FILEOP_SAVE_GAME_001) {
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
	s32 device = pakFindBySerial(g_Menus[g_MpPlayerNum].fm.deviceserial);

	if (device == -1) {
		if (context == 1) {
			filemgrPushErrorDialog(FILEERROR_NOPAK);
		}

		if (context == 2) {
			func0f0f3704(&g_PakNotOriginalMenuDialog);
		}
	} else if (filemgrAttemptOperation(device, true)) {
		if (context == 2) {
			g_Menus[g_MpPlayerNum].fm.device1 = device;

			if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fm.fileop)) {
				filemgrPushErrorDialog(FILEERROR_SAVEFAILED);
			} else {
				filemgrPushErrorDialog(FILEERROR_LOADFAILED);
			}
		} else {
			filemgrSetDevice1BySerial(g_Menus[g_MpPlayerNum].fm.deviceserial);

			if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fm.fileop)) {
				func0f0f3704(&g_FilemgrSaveErrorMenuDialog);
			} else {
#if VERSION >= VERSION_NTSC_1_0
				filemgrEraseCorruptFile();
#else
				func0f0f3704(&g_FilemgrFileLostMenuDialog);
#endif
			}
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
bool filemgrAttemptOperation(s32 device, bool closeonsuccess)
{
	s32 errno = 0;
	bool showfilesaved = (g_Menus[g_MpPlayerNum].fm.isretryingsave & 1) != 0;

	const s32 filetypes[] = {
		PAKFILETYPE_GAME,
		PAKFILETYPE_MPSETUP,
		PAKFILETYPE_MPPLAYER,
		PAKFILETYPE_CAMERA,
	};

	s32 newfileid;

	switch (g_Menus[g_MpPlayerNum].fm.fileop) {
	case FILEOP_SAVE_GAME_002:
		showfilesaved = true;
		// fall through
	case FILEOP_SAVE_GAME_000:
	case FILEOP_SAVE_GAME_001:
		errno = gamefileSave(device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				g_Menus[g_MpPlayerNum].fm.deviceserial);
		break;
	case FILEOP_SAVE_MPPLAYER:
		errno = mpplayerfileSave(
				(s32) g_Menus[g_MpPlayerNum].fm.unke44, device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				g_Menus[g_MpPlayerNum].fm.deviceserial);
		break;
	case FILEOP_SAVE_MPSETUP:
		errno = mpsetupfileSave(device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				g_Menus[g_MpPlayerNum].fm.deviceserial);
		showfilesaved = true;
		break;
	case FILEOP_WRITE_GAME:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_WRITE_MPPLAYER:
		newfileid = 0;
		func0f0d5690(g_Menus[g_MpPlayerNum].fm.unke44, g_Menus[g_MpPlayerNum].fm.filename);
		errno = pakSaveAtGuid(device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				filetypes[g_Menus[g_MpPlayerNum].fm.fileop - 6],
				g_Menus[g_MpPlayerNum].fm.unke44, &newfileid, NULL);
		var80075bd0[g_Menus[g_MpPlayerNum].fm.fileop - 6] = 1;
		break;
	case FILEOP_LOAD_GAME:
		errno = gamefileLoad(device);
		break;
	case FILEOP_LOAD_MPPLAYER:
		errno = mpplayerfileLoad(
				(s32) g_Menus[g_MpPlayerNum].fm.unke44,
				device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				g_Menus[g_MpPlayerNum].fm.deviceserial);
		break;
	case FILEOP_LOAD_MPSETUP:
		errno = mpsetupfileLoad(device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				g_Menus[g_MpPlayerNum].fm.deviceserial);
		break;
	case FILEOP_READ_GAME:
	case FILEOP_READ_MPSETUP:
	case FILEOP_READ_MPPLAYER:
		errno = pakReadBodyAtGuid(device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				g_Menus[g_MpPlayerNum].fm.unke44, 0);
		break;
	}

	if (errno == 0 && closeonsuccess) {
		menuCloseDialog();
	}

	if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fm.fileop)) {
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
/*  f104be0:	0fc442fb */ 	jal	pakSaveAtGuid
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
/*  f104c90:	0fc442f1 */ 	jal	pakReadBodyAtGuid
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

/**
 * Save or load the file with the specified GUID.
 * If saving, it's assumed that the file has been saved previously.
 *
 * fileop determines the type of file, as well as whether it's a save or load
 * operation. If set to -1, the previous fileop is reused (eg. for retry).
 *
 * playernum is used when working with MP player files, otherwise ignored.
 *
 * Return true if it worked, otherwise false.
 */
bool filemgrSaveOrLoad(struct fileguid *guid, s32 fileop, u32 playernum)
{
	s32 device;

	if (fileop != -1) {
		// Common case - set new fileop
		g_Menus[g_MpPlayerNum].fm.fileop = fileop;
		g_Menus[g_MpPlayerNum].fm.mpplayernum = playernum;
		g_Menus[g_MpPlayerNum].fm.isretryingsave = 0;
		g_FilemgrLastPakError = 0;
	}

	g_Menus[g_MpPlayerNum].fm.fileid = guid->fileid;
	g_Menus[g_MpPlayerNum].fm.deviceserial = guid->deviceserial;

	if (fileop != -1) {
		// empty
	}

	device = pakFindBySerial(g_Menus[g_MpPlayerNum].fm.deviceserial);

	if (device == -1) {
		// Original pak is no longer connected
		g_Menus[g_MpPlayerNum].fm.isretryingsave |= 1;
		menuPushDialog(&g_PakNotOriginalMenuDialog);
		return false;
	}

	if (filemgrAttemptOperation(device, false) != 0) {
		// Operation failed
		g_Menus[g_MpPlayerNum].fm.isretryingsave |= 1;
		filemgrSetDevice1BySerial(g_Menus[g_MpPlayerNum].fm.deviceserial);

		if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fm.fileop)) {
			menuPushDialog(&g_FilemgrSaveErrorMenuDialog);
		} else {
			// File couldn't be loaded
#if VERSION >= VERSION_NTSC_1_0
			filemgrEraseCorruptFile();
#else
			menuPushDialog(&g_FilemgrFileLostMenuDialog);
#endif
		}

		return false;
	}

	return true;
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel filemgrDeleteCurrentFile
/*  f109820:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f109824:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f109828:	3c138007 */ 	lui	$s3,0x8007
/*  f10982c:	26731998 */ 	addiu	$s3,$s3,0x1998
/*  f109830:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f109834:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f109838:	3c14800a */ 	lui	$s4,0x800a
/*  f10983c:	269428f0 */ 	addiu	$s4,$s4,0x28f0
/*  f109840:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f109844:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f109848:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10984c:	028fc021 */ 	addu	$t8,$s4,$t7
/*  f109850:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f109854:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f109858:	00008025 */ 	move	$s0,$zero
/*  f10985c:	0fc47aac */ 	jal	pakFindBySerial
/*  f109860:	97040004 */ 	lhu	$a0,0x4($t8)
/*  f109864:	00028e00 */ 	sll	$s1,$v0,0x18
/*  f109868:	0011ce03 */ 	sra	$t9,$s1,0x18
/*  f10986c:	0440000d */ 	bltz	$v0,.JF0f1098a4
/*  f109870:	03208825 */ 	move	$s1,$t9
/*  f109874:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f109878:	00192600 */ 	sll	$a0,$t9,0x18
/*  f10987c:	00044603 */ 	sra	$t0,$a0,0x18
/*  f109880:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f109884:	028a5821 */ 	addu	$t3,$s4,$t2
/*  f109888:	8d650000 */ 	lw	$a1,0x0($t3)
/*  f10988c:	0fc45b04 */ 	jal	pakDeleteFile
/*  f109890:	01002025 */ 	move	$a0,$t0
/*  f109894:	50400005 */ 	beqzl	$v0,.JF0f1098ac
/*  f109898:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f10989c:	10000002 */ 	b	.JF0f1098a8
/*  f1098a0:	24100001 */ 	li	$s0,0x1
.JF0f1098a4:
/*  f1098a4:	24100001 */ 	li	$s0,0x1
.JF0f1098a8:
/*  f1098a8:	8e6d0000 */ 	lw	$t5,0x0($s3)
.JF0f1098ac:
/*  f1098ac:	24030e70 */ 	li	$v1,0xe70
/*  f1098b0:	3c02800a */ 	lui	$v0,0x800a
/*  f1098b4:	01a30019 */ 	multu	$t5,$v1
/*  f1098b8:	2442e700 */ 	addiu	$v0,$v0,-6400
/*  f1098bc:	3c088007 */ 	lui	$t0,0x8007
/*  f1098c0:	240c0001 */ 	li	$t4,0x1
/*  f1098c4:	24120004 */ 	li	$s2,0x4
/*  f1098c8:	00007012 */ 	mflo	$t6
/*  f1098cc:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f1098d0:	91f80e3f */ 	lbu	$t8,0xe3f($t7)
/*  f1098d4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1098d8:	01194021 */ 	addu	$t0,$t0,$t9
/*  f1098dc:	8d0861b0 */ 	lw	$t0,0x61b0($t0)
/*  f1098e0:	1200000a */ 	beqz	$s0,.JF0f10990c
/*  f1098e4:	a10c030c */ 	sb	$t4,0x30c($t0)
/*  f1098e8:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f1098ec:	24040003 */ 	li	$a0,0x3
/*  f1098f0:	01230019 */ 	multu	$t1,$v1
/*  f1098f4:	00005012 */ 	mflo	$t2
/*  f1098f8:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f1098fc:	0fc421f7 */ 	jal	filemgrPushErrorDialog
/*  f109900:	a1710e3c */ 	sb	$s1,0xe3c($t3)
/*  f109904:	10000016 */ 	b	.JF0f109960
/*  f109908:	8fbf002c */ 	lw	$ra,0x2c($sp)
.JF0f10990c:
/*  f10990c:	3c11800b */ 	lui	$s1,0x800b
/*  f109910:	2631d1e8 */ 	addiu	$s1,$s1,-11800
/*  f109914:	00008025 */ 	move	$s0,$zero
.JF0f109918:
/*  f109918:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f10991c:	8e38004c */ 	lw	$t8,0x4c($s1)
/*  f109920:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f109924:	028e1021 */ 	addu	$v0,$s4,$t6
/*  f109928:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f10992c:	55f80009 */ 	bnel	$t7,$t8,.JF0f109954
/*  f109930:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f109934:	94590004 */ 	lhu	$t9,0x4($v0)
/*  f109938:	962c0050 */ 	lhu	$t4,0x50($s1)
/*  f10993c:	02002025 */ 	move	$a0,$s0
/*  f109940:	572c0004 */ 	bnel	$t9,$t4,.JF0f109954
/*  f109944:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f109948:	0fc621cb */ 	jal	mpPlayerSetDefaults
/*  f10994c:	24050001 */ 	li	$a1,0x1
/*  f109950:	26100001 */ 	addiu	$s0,$s0,0x1
.JF0f109954:
/*  f109954:	1612fff0 */ 	bne	$s0,$s2,.JF0f109918
/*  f109958:	263100a0 */ 	addiu	$s1,$s1,0xa0
/*  f10995c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.JF0f109960:
/*  f109960:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f109964:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f109968:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f10996c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f109970:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f109974:	03e00008 */ 	jr	$ra
/*  f109978:	27bd0030 */ 	addiu	$sp,$sp,0x30
);
#else
void filemgrDeleteCurrentFile(void)
{
	bool error = false;
	s8 device = pakFindBySerial(g_FilemgrFileToDelete.deviceserial);
	s32 i;

	if (device >= 0) {
		if (pakDeleteFile(device, g_FilemgrFileToDelete.fileid) != 0) {
			error = true;
		}
	} else {
		error = true;
	}

	g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->timeuntilupdate = 1;

	if (error) {
		g_Menus[g_MpPlayerNum].fm.device1 = device;
		filemgrPushErrorDialog(FILEERROR_DELETEFAILED);
	} else {
		// If deleting a loaded MP player, reset them to default
		for (i = 0; i < 4; i++) {
			if (g_FilemgrFileToDelete.fileid == g_PlayerConfigsArray[i].fileguid.fileid
					&& g_FilemgrFileToDelete.deviceserial == g_PlayerConfigsArray[i].fileguid.deviceserial) {
				mpPlayerSetDefaults(i, true);
			}
		}
	}
}
#endif

struct menuitem g_FilemgrFileSavedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_346, 0x00000000, NULL }, // "File Saved."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS_347, 0x00000000, NULL }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FilemgrFileSavedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS_345, // "Cool!"
	g_FilemgrFileSavedMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLEBANNER,
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

struct menudialogdef g_FilemgrSaveErrorMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(u32)&filemgrMenuTextErrorTitle,
	g_FilemgrSaveErrorMenuItems,
	NULL,
	MENUDIALOGFLAG_IGNOREBACK | MENUDIALOGFLAG_DISABLEBANNER,
	NULL,
};

struct menuitem g_FilemgrFileLostMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextDeviceName, 0x00000000, filemgrDeviceNameMenuHandler },
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_251, 0x00000000, NULL }, // "The saved file has been erased due to corruption or damage."
#else
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_352, 0x00000000, NULL }, // "An error occurred while trying to load."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_353, 0x00000000, filemgr0f108d14 }, // "Try Again"
#endif
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_354, 0x00000000, filemgrAcknowledgeFileLostMenuHandler }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FilemgrFileLostMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(u32)&filemgrMenuTextErrorTitle,
	g_FilemgrFileLostMenuItems,
	NULL,
	MENUDIALOGFLAG_IGNOREBACK | MENUDIALOGFLAG_DISABLEBANNER,
	NULL,
};

struct menuitem g_FilemgrSaveElsewhereMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_360, 0x00000000, NULL }, // "Would you like to save your file elsewhere?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_361, 0x00000000, filemgrSaveElsewhereYesMenuHandler }, // "Yes"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_362, 0x00000000, filemgrCancelSave2MenuHandler }, // "No"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FilemgrSaveElsewhereMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_359, // "Save"
	g_FilemgrSaveElsewhereMenuItems,
	NULL,
	MENUDIALOGFLAG_IGNOREBACK | MENUDIALOGFLAG_DISABLEBANNER,
	NULL,
};

struct menuitem g_PakNotOriginalMenuItems[] = {
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextInsertOriginalPak, 0x00000000, NULL },
#else
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_363, 0x00000000, NULL },
#endif
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_365, 0x00000000, filemgrReinsertedOkMenuHandler }, // "OK"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_366, 0x00000000, filemgrReinsertedCancelMenuHandler }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_PakNotOriginalMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(u32)&filemgrMenuTextErrorTitle,
	g_PakNotOriginalMenuItems,
	filemgrInsertOriginalPakMenuDialog,
	MENUDIALOGFLAG_IGNOREBACK | MENUDIALOGFLAG_DISABLEBANNER,
	NULL,
};

void func0f1097d0(s32 device)
{
	char *typenames[] = {"GAM", "MPG", "MPP", "CAM"};
	const u32 typecodes[] = {0x80, 0x40, 0x20, 0x08};
	void *thing;

	if (g_FileLists[0]) {
		var800a21e8.fileid = g_FileLists[0]->deviceguids[device].fileid;
		var800a21e8.deviceserial = g_FileLists[0]->deviceguids[device].deviceserial;

		thing = memaAlloc(align16(g_FileTypeSizes[g_Menus[g_MpPlayerNum].fm.filetypeplusone - 1]));

		if (thing) {
			filemgrSaveOrLoad(&g_FilemgrFileToCopy, g_Menus[g_MpPlayerNum].fm.filetypeplusone + 103, (s32) thing);
		} else {
			filemgrPushErrorDialog(FILEERROR_OUTOFMEMORY);
		}

		var80075bd0[g_Menus[g_MpPlayerNum].fm.filetypeplusone - 1] = 1;
	}
}

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b3234[] = "DestPakNo: %d (guid F:%x-%x:P)\n";
const char var7f1b3254[] = "Copy Memory Alloced\n";
const char var7f1b326c[] = "COULDNT GET THE RAM!\n";
const char var7f1b3284[] = "Saving...\n";
#endif

void filemgrSaveGameToDevice(s32 device)
{
	if (g_FileLists[0]) {
		g_GameFileGuid.fileid = g_FileLists[0]->deviceguids[device].fileid;
		g_GameFileGuid.deviceserial = g_FileLists[0]->deviceguids[device].deviceserial;

		filemgrSaveOrLoad(&g_GameFileGuid, FILEOP_SAVE_GAME_000, 0);
	}
}

#if VERSION >= VERSION_NTSC_1_0
void filemgrGetFileName(char *dst, struct filelistfile *file)
{
	char localbuffer[20];
	u32 playtime;

	localbuffer[0] = '\0';

	switch (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->filetype) {
	case FILETYPE_GAME:
	case FILETYPE_MPSETUP:
		func0f0d564c(file->name, localbuffer, false);
		break;
	case FILETYPE_MPPLAYER:
		mpplayerfileGetOverview(file->name, localbuffer, &playtime);
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

	switch (g_Menus[g_MpPlayerNum].fm.unke3e) {
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
		strcpy(buffer, g_Menus[g_MpPlayerNum].fm.filename);
		break;
	case 6:
	case 12:
		i = 0;
		j = 0;

		while (g_PlayerConfigsArray[g_MpPlayerNum].base.name[i] != '\0') {
			if (g_PlayerConfigsArray[g_MpPlayerNum].base.name[i] != '\n') {
				buffer[j] = g_PlayerConfigsArray[g_MpPlayerNum].base.name[i];
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
	switch (g_Menus[g_MpPlayerNum].fm.unke3e) {
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
		strcpy(g_Menus[g_MpPlayerNum].fm.filename, name);
		break;
	case 6:
	case 12:
		sprintf(g_PlayerConfigsArray[g_MpPlayerNum].base.name, "%s\n", name);
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
	filelist = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum];

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
		filemgrGetFileName(loopname, &g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->files[i]);

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

/**
 * Used for both saving new files and copying files.
 */
void filemgrSaveToDevice(void)
{
	if (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->spacesfree[g_Menus[g_MpPlayerNum].fm.device2] > 0) {
		if (!filemgrIsNameAvailable(g_Menus[g_MpPlayerNum].fm.device2)) {
			menuPushDialog(&g_FilemgrDuplicateNameMenuDialog);
		} else {
			menuPopDialog();

			if (g_Menus[g_MpPlayerNum].fm.unke3e == 0) {
				filemgrSaveGameToDevice(g_Menus[g_MpPlayerNum].fm.device2);
			} else if (g_Menus[g_MpPlayerNum].fm.unke3e == 5) {
				// empty
			} else if (g_Menus[g_MpPlayerNum].fm.unke3e == 6) {
				struct fileguid guid;
				guid.fileid = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[g_Menus[g_MpPlayerNum].fm.device2].fileid;
				guid.deviceserial = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[g_Menus[g_MpPlayerNum].fm.device2].deviceserial;
				filemgrSaveOrLoad(&guid, FILEOP_SAVE_MPPLAYER, (u32)g_MpPlayerNum);
			} else if (g_Menus[g_MpPlayerNum].fm.unke3e == 7) {
				struct fileguid guid;
				guid.fileid = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[g_Menus[g_MpPlayerNum].fm.device2].fileid;
				guid.deviceserial = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[g_Menus[g_MpPlayerNum].fm.device2].deviceserial;
				filemgrSaveOrLoad(&guid, FILEOP_SAVE_MPSETUP, 0);
			} else if (g_Menus[g_MpPlayerNum].fm.unke3e >= 9) {
				struct fileguid guid;
				guid.fileid = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[g_Menus[g_MpPlayerNum].fm.device2].fileid;
				guid.deviceserial = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[g_Menus[g_MpPlayerNum].fm.device2].deviceserial;
				filemgrSaveOrLoad(&guid, -1, 0);
			} else {
				func0f1097d0(g_Menus[g_MpPlayerNum].fm.device2);
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
		filemgrSaveToDevice();
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
	return filemgrGetDeviceName(g_Menus[g_MpPlayerNum].fm.device2);
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

struct menudialogdef g_FilemgrRenameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_238, // "Change File Name"
	g_FilemgrRenameMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLEBANNER,
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

struct menudialogdef g_FilemgrDuplicateNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_232, // "Duplicate File Name"
	g_FilemgrDuplicateMenuMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLEBANNER,
	NULL,
};
#endif

char *filemgrMenuTextLocationName2(struct menuitem *item)
{
	u16 names[] = {
		L_OPTIONS_112, // "Controller Pak 1"
		L_OPTIONS_113, // "Controller Pak 2"
		L_OPTIONS_114, // "Controller Pak 3"
		L_OPTIONS_115, // "Controller Pak 4"
		L_OPTIONS_111, // "Game Pak"
		L_OPTIONS_004, // ""
	};

	if (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum] == NULL) {
		return NULL;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->spacesfree[item->param] < 0) {
		return langGet(names[5]);
	}
#else
	if (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->spacesfree[item->param] <= 0) {
		return langGet(names[5]);
	}
#endif

	return langGet(names[item->param]);
}

char *filemgrMenuTextSaveLocationSpaces(struct menuitem *item)
{
	s32 spacesfree;

	if (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum] == NULL) {
		return NULL;
	}

	spacesfree = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->spacesfree[item->param];

	if (spacesfree < 0) {
		return "\n";
	}

	if (spacesfree == 0) {
		return langGet(L_OPTIONS_372); // "Full"
	}

	sprintf(g_StringPointer, "%d", spacesfree);
	return g_StringPointer;
}

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
	if (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum] == NULL) {
		return 0;
	}

	if (operation == MENUOP_CHECKDISABLED) {
		if (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->spacesfree[item->param] < 1) {
			return true;
		}
	}

	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].fm.device2 = item->param;
		filemgrSaveToDevice();
	}

	return 0;
}
#else
GLOBAL_ASM(
glabel filemgrSelectLocationMenuHandler
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
/*  f105480:	0fc41475 */ 	jal	filemgrSaveGameToDevice
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
/*  f1054e4:	0fc41358 */ 	jal	filemgrSaveOrLoad
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
/*  f105540:	0fc41358 */ 	jal	filemgrSaveOrLoad
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
/*  f10559c:	0fc41358 */ 	jal	filemgrSaveOrLoad
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
		filemgrPushDeleteFileDialog(g_Menus[g_MpPlayerNum].fm.listnum);
		g_Menus[g_MpPlayerNum].fm.isdeletingforsave = true;
	}

	return 0;
}

void filemgrPushSelectLocationDialog(s32 arg0, u32 filetype)
{
	g_Menus[g_MpPlayerNum].fm.unke3e = arg0;
	g_Menus[g_MpPlayerNum].fm.listnum = filelistFindOrCreate(filetype);

#if VERSION >= VERSION_NTSC_1_0
	filelistsTick();
#endif

	menuPushDialog(&g_FilemgrSelectLocationMenuDialog);
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel filemgrIsFileInUse
/*  f10a758:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10a75c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10a760:	00808025 */ 	move	$s0,$a0
/*  f10a764:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f10a768:	3c048007 */ 	lui	$a0,0x8007
/*  f10a76c:	0fc3f89a */ 	jal	menuIsDialogOpen
/*  f10a770:	24845024 */ 	addiu	$a0,$a0,0x5024
/*  f10a774:	1040000d */ 	beqz	$v0,.JF0f10a7ac
/*  f10a778:	3c048007 */ 	lui	$a0,0x8007
/*  f10a77c:	3c02800a */ 	lui	$v0,0x800a
/*  f10a780:	244228e0 */ 	addiu	$v0,$v0,0x28e0
/*  f10a784:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f10a788:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f10a78c:	15cf0007 */ 	bne	$t6,$t7,.JF0f10a7ac
/*  f10a790:	00000000 */ 	nop
/*  f10a794:	94580004 */ 	lhu	$t8,0x4($v0)
/*  f10a798:	96190004 */ 	lhu	$t9,0x4($s0)
/*  f10a79c:	17190003 */ 	bne	$t8,$t9,.JF0f10a7ac
/*  f10a7a0:	00000000 */ 	nop
/*  f10a7a4:	10000062 */ 	b	.JF0f10a930
/*  f10a7a8:	24020001 */ 	li	$v0,0x1
.JF0f10a7ac:
/*  f10a7ac:	0fc3f89a */ 	jal	menuIsDialogOpen
/*  f10a7b0:	24845524 */ 	addiu	$a0,$a0,0x5524
/*  f10a7b4:	10400003 */ 	beqz	$v0,.JF0f10a7c4
/*  f10a7b8:	3c0a800a */ 	lui	$t2,0x800a
/*  f10a7bc:	1000005c */ 	b	.JF0f10a930
/*  f10a7c0:	00001025 */ 	move	$v0,$zero
.JF0f10a7c4:
/*  f10a7c4:	8d4a20c4 */ 	lw	$t2,0x20c4($t2)
/*  f10a7c8:	24010006 */ 	li	$at,0x6
/*  f10a7cc:	3c02800a */ 	lui	$v0,0x800a
/*  f10a7d0:	15410003 */ 	bne	$t2,$at,.JF0f10a7e0
/*  f10a7d4:	244229e0 */ 	addiu	$v0,$v0,0x29e0
/*  f10a7d8:	10000055 */ 	b	.JF0f10a930
/*  f10a7dc:	00001025 */ 	move	$v0,$zero
.JF0f10a7e0:
/*  f10a7e0:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f10a7e4:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f10a7e8:	15680007 */ 	bne	$t3,$t0,.JF0f10a808
/*  f10a7ec:	00000000 */ 	nop
/*  f10a7f0:	944c0004 */ 	lhu	$t4,0x4($v0)
/*  f10a7f4:	960d0004 */ 	lhu	$t5,0x4($s0)
/*  f10a7f8:	158d0003 */ 	bne	$t4,$t5,.JF0f10a808
/*  f10a7fc:	00000000 */ 	nop
/*  f10a800:	1000004b */ 	b	.JF0f10a930
/*  f10a804:	24020001 */ 	li	$v0,0x1
.JF0f10a808:
/*  f10a808:	3c02800b */ 	lui	$v0,0x800b
/*  f10a80c:	2442d5b8 */ 	addiu	$v0,$v0,-10824
/*  f10a810:	8c4e0020 */ 	lw	$t6,0x20($v0)
/*  f10a814:	3c09800a */ 	lui	$t1,0x800a
/*  f10a818:	252928f0 */ 	addiu	$t1,$t1,0x28f0
/*  f10a81c:	15c80007 */ 	bne	$t6,$t0,.JF0f10a83c
/*  f10a820:	3c048007 */ 	lui	$a0,0x8007
/*  f10a824:	944f0024 */ 	lhu	$t7,0x24($v0)
/*  f10a828:	96180004 */ 	lhu	$t8,0x4($s0)
/*  f10a82c:	15f80003 */ 	bne	$t7,$t8,.JF0f10a83c
/*  f10a830:	00000000 */ 	nop
/*  f10a834:	1000003e */ 	b	.JF0f10a930
/*  f10a838:	24020001 */ 	li	$v0,0x1
.JF0f10a83c:
/*  f10a83c:	3c078007 */ 	lui	$a3,0x8007
/*  f10a840:	3c05800a */ 	lui	$a1,0x800a
/*  f10a844:	24a5e700 */ 	addiu	$a1,$a1,-6400
/*  f10a848:	24e74ed8 */ 	addiu	$a3,$a3,0x4ed8
/*  f10a84c:	00001025 */ 	move	$v0,$zero
/*  f10a850:	8c841998 */ 	lw	$a0,0x1998($a0)
/*  f10a854:	24060e70 */ 	li	$a2,0xe70
.JF0f10a858:
/*  f10a858:	50440016 */ 	beql	$v0,$a0,.JF0f10a8b4
/*  f10a85c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10a860:	00460019 */ 	multu	$v0,$a2
/*  f10a864:	0000c812 */ 	mflo	$t9
/*  f10a868:	00b95021 */ 	addu	$t2,$a1,$t9
/*  f10a86c:	8d4304f8 */ 	lw	$v1,0x4f8($t2)
/*  f10a870:	50600010 */ 	beqzl	$v1,.JF0f10a8b4
/*  f10a874:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10a878:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f10a87c:	000260c0 */ 	sll	$t4,$v0,0x3
/*  f10a880:	012c1821 */ 	addu	$v1,$t1,$t4
/*  f10a884:	54eb000b */ 	bnel	$a3,$t3,.JF0f10a8b4
/*  f10a888:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10a88c:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f10a890:	550d0008 */ 	bnel	$t0,$t5,.JF0f10a8b4
/*  f10a894:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10a898:	960e0004 */ 	lhu	$t6,0x4($s0)
/*  f10a89c:	946f0004 */ 	lhu	$t7,0x4($v1)
/*  f10a8a0:	55cf0004 */ 	bnel	$t6,$t7,.JF0f10a8b4
/*  f10a8a4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10a8a8:	10000021 */ 	b	.JF0f10a930
/*  f10a8ac:	24020001 */ 	li	$v0,0x1
/*  f10a8b0:	24420001 */ 	addiu	$v0,$v0,0x1
.JF0f10a8b4:
/*  f10a8b4:	28410004 */ 	slti	$at,$v0,0x4
/*  f10a8b8:	1420ffe7 */ 	bnez	$at,.JF0f10a858
/*  f10a8bc:	00000000 */ 	nop
/*  f10a8c0:	3c04800b */ 	lui	$a0,0x800b
/*  f10a8c4:	3c05800b */ 	lui	$a1,0x800b
/*  f10a8c8:	24a5d1e8 */ 	addiu	$a1,$a1,-11800
/*  f10a8cc:	9484d5ce */ 	lhu	$a0,-0x2a32($a0)
/*  f10a8d0:	00001025 */ 	move	$v0,$zero
/*  f10a8d4:	24070004 */ 	li	$a3,0x4
/*  f10a8d8:	240600a0 */ 	li	$a2,0xa0
/*  f10a8dc:	24180001 */ 	li	$t8,0x1
.JF0f10a8e0:
/*  f10a8e0:	0058c804 */ 	sllv	$t9,$t8,$v0
/*  f10a8e4:	00995024 */ 	and	$t2,$a0,$t9
/*  f10a8e8:	5140000e */ 	beqzl	$t2,.JF0f10a924
/*  f10a8ec:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10a8f0:	00460019 */ 	multu	$v0,$a2
/*  f10a8f4:	00005812 */ 	mflo	$t3
/*  f10a8f8:	00ab1821 */ 	addu	$v1,$a1,$t3
/*  f10a8fc:	8c6c004c */ 	lw	$t4,0x4c($v1)
/*  f10a900:	550c0008 */ 	bnel	$t0,$t4,.JF0f10a924
/*  f10a904:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10a908:	960d0004 */ 	lhu	$t5,0x4($s0)
/*  f10a90c:	946e0050 */ 	lhu	$t6,0x50($v1)
/*  f10a910:	55ae0004 */ 	bnel	$t5,$t6,.JF0f10a924
/*  f10a914:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10a918:	10000005 */ 	b	.JF0f10a930
/*  f10a91c:	24020001 */ 	li	$v0,0x1
/*  f10a920:	24420001 */ 	addiu	$v0,$v0,0x1
.JF0f10a924:
/*  f10a924:	5447ffee */ 	bnel	$v0,$a3,.JF0f10a8e0
/*  f10a928:	24180001 */ 	li	$t8,0x1
/*  f10a92c:	00001025 */ 	move	$v0,$zero
.JF0f10a930:
/*  f10a930:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f10a934:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f10a938:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10a93c:	03e00008 */ 	jr	$ra
/*  f10a940:	00000000 */ 	nop
);
#endif

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel filemgrConfirmDeleteMenuHandler
/*  f10a944:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f10a948:	24010006 */ 	li	$at,0x6
/*  f10a94c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10a950:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f10a954:	14810016 */ 	bne	$a0,$at,.JF0f10a9b0
/*  f10a958:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f10a95c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10a960:	8dce1998 */ 	lw	$t6,0x1998($t6)
/*  f10a964:	3c18800a */ 	lui	$t8,0x800a
/*  f10a968:	271828f0 */ 	addiu	$t8,$t8,0x28f0
/*  f10a96c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10a970:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f10a974:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f10a978:	94480004 */ 	lhu	$t0,0x4($v0)
/*  f10a97c:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f10a980:	0fc3d0dc */ 	jal	menuPopDialog
/*  f10a984:	a7a80024 */ 	sh	$t0,0x24($sp)
/*  f10a988:	0fc429d6 */ 	jal	filemgrIsFileInUse
/*  f10a98c:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f10a990:	10400005 */ 	beqz	$v0,.JF0f10a9a8
/*  f10a994:	00000000 */ 	nop
/*  f10a998:	0fc421f7 */ 	jal	filemgrPushErrorDialog
/*  f10a99c:	24040003 */ 	li	$a0,0x3
/*  f10a9a0:	10000004 */ 	b	.JF0f10a9b4
/*  f10a9a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.JF0f10a9a8:
/*  f10a9a8:	0fc42608 */ 	jal	filemgrDeleteCurrentFile
/*  f10a9ac:	00000000 */ 	nop
.JF0f10a9b0:
/*  f10a9b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.JF0f10a9b4:
/*  f10a9b4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f10a9b8:	00001025 */ 	move	$v0,$zero
/*  f10a9bc:	03e00008 */ 	jr	$ra
/*  f10a9c0:	00000000 */ 	nop
);
#else
s32 filemgrConfirmDeleteMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		filemgrDeleteCurrentFile();
	}

	return 0;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
char *filemgrMenuTextFileInUseDescription(struct menuitem *item)
{
	if (menuIsDialogOpen(&g_FilemgrCopyMenuDialog)) {
		return langGet(L_MPWEAPONS_240); // "The file you are copying cannot be deleted."
	}

	return langGet(L_MPWEAPONS_160); // "Cannot delete file as it is being used."
}
#endif

/**
 * This is a dirty decomp hack where we intentionally declare
 * an incorrect function signature in order to get a match.
 * pheadGetTexture uses u16 as its last argument
 * but filemgrRenderPerfectHeadThumbnail will only match if
 * it's an s32 with a 0xffff mask.
 */
struct textureconfig *pheadGetTexture(s32 playernum, s32 fileid, s32 deviceserial);

Gfx *filemgrRenderPerfectHeadThumbnail(Gfx *gdl, struct menuitemrenderdata *renderdata, s32 fileid, s32 deviceserial)
{
	struct textureconfig *texture = pheadGetTexture(g_MpPlayerNum, fileid, deviceserial & 0xffff);

	if (texture) {
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061360);

		gDPPipeSync(gdl++);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);

		texSelect(&gdl, texture, 1, 0, 2, 1, NULL);

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

		if (deviceserial) {
			// empty
		}
	}

	return gdl;
}

#if VERSION < VERSION_JPN_FINAL
bool filemgrIsFileInUse(struct filelistfile *file)
{
	s32 i;

#if VERSION >= VERSION_NTSC_1_0
	if (menuIsDialogOpen(&g_FilemgrCopyMenuDialog)
			&& file->fileid == g_FilemgrFileToCopy.fileid
			&& file->deviceserial == g_FilemgrFileToCopy.deviceserial) {
		return true;
	}

	if (menuIsDialogOpen(&g_FilemgrFileSelect4MbMenuDialog)) {
		return false;
	}
#else
	if (g_MenuData.root == MENUROOT_FILEMGR
			&& menuIsDialogOpen(&g_FilemgrCopyMenuDialog)
			&& file->fileid == g_FilemgrFileToCopy.fileid
			&& file->deviceserial == g_FilemgrFileToCopy.deviceserial) {
		return true;
	}
#endif

	if (g_MenuData.root == MENUROOT_FILEMGR) {
		return false;
	}

	if (file->fileid == g_GameFileGuid.fileid && file->deviceserial == g_GameFileGuid.deviceserial) {
		return true;
	}

	if (file->fileid == g_MpSetup.fileguid.fileid && file->deviceserial == g_MpSetup.fileguid.deviceserial) {
		return true;
	}

	for (i = 0; i < 4; i++) {
		if ((g_MpSetup.chrslots & (1 << i))
				&& g_PlayerConfigsArray[i].fileguid.fileid == file->fileid
				&& g_PlayerConfigsArray[i].fileguid.deviceserial == file->deviceserial) {
			return true;
		}
	}

	return false;
}
#endif

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
		listnum = g_Menus[g_MpPlayerNum].fm.listnum;
		list = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum];
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

			if (g_Menus[g_MpPlayerNum].fm.filetypeplusone == 4) {
				gdl = filemgrRenderPerfectHeadThumbnail(gdl, renderdata, file->fileid, file->deviceserial);
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
					filemgrGetSelectName(text, file, g_Menus[g_MpPlayerNum].fm.filetypeplusone - 1);
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
		data->list.value = list->numdevices;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return filemgrGetDeviceNameOrStartIndex(listnum, operation, data->list.value);
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = filemgrGetDeviceNameOrStartIndex(listnum, operation, data->list.value);
		return 0;
	}

	return 0;
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel filemgrFileToDeleteListMenuHandler
/*  f10b018:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10b01c:	8dce1998 */ 	lw	$t6,0x1998($t6)
/*  f10b020:	24080e70 */ 	li	$t0,0xe70
/*  f10b024:	3c07800a */ 	lui	$a3,0x800a
/*  f10b028:	01c80019 */ 	multu	$t6,$t0
/*  f10b02c:	24e7e700 */ 	addiu	$a3,$a3,-6400
/*  f10b030:	3c038007 */ 	lui	$v1,0x8007
/*  f10b034:	246361b0 */ 	addiu	$v1,$v1,0x61b0
/*  f10b038:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10b03c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f10b040:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10b044:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f10b048:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f10b04c:	8fab0020 */ 	lw	$t3,0x20($sp)
/*  f10b050:	00007812 */ 	mflo	$t7
/*  f10b054:	00efc021 */ 	addu	$t8,$a3,$t7
/*  f10b058:	93190e3f */ 	lbu	$t9,0xe3f($t8)
/*  f10b05c:	24010006 */ 	li	$at,0x6
/*  f10b060:	00194880 */ 	sll	$t1,$t9,0x2
/*  f10b064:	00695021 */ 	addu	$t2,$v1,$t1
/*  f10b068:	8d420000 */ 	lw	$v0,0x0($t2)
/*  f10b06c:	14400003 */ 	bnez	$v0,.JF0f10b07c
/*  f10b070:	00000000 */ 	nop
/*  f10b074:	10000044 */ 	b	.JF0f10b188
/*  f10b078:	00001025 */ 	move	$v0,$zero
.JF0f10b07c:
/*  f10b07c:	1561003d */ 	bne	$t3,$at,.JF0f10b174
/*  f10b080:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f10b084:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f10b088:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f10b08c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f10b090:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f10b094:	004e3021 */ 	addu	$a2,$v0,$t6
/*  f10b098:	10c00036 */ 	beqz	$a2,.JF0f10b174
/*  f10b09c:	00c02025 */ 	move	$a0,$a2
/*  f10b0a0:	0fc429d6 */ 	jal	filemgrIsFileInUse
/*  f10b0a4:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f10b0a8:	3c038007 */ 	lui	$v1,0x8007
/*  f10b0ac:	3c07800a */ 	lui	$a3,0x800a
/*  f10b0b0:	24e7e700 */ 	addiu	$a3,$a3,-6400
/*  f10b0b4:	246361b0 */ 	addiu	$v1,$v1,0x61b0
/*  f10b0b8:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f10b0bc:	10400012 */ 	beqz	$v0,.JF0f10b108
/*  f10b0c0:	24080e70 */ 	li	$t0,0xe70
/*  f10b0c4:	3c0f8007 */ 	lui	$t7,0x8007
/*  f10b0c8:	8def1998 */ 	lw	$t7,0x1998($t7)
/*  f10b0cc:	00c02025 */ 	move	$a0,$a2
/*  f10b0d0:	01e80019 */ 	multu	$t7,$t0
/*  f10b0d4:	0000c012 */ 	mflo	$t8
/*  f10b0d8:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f10b0dc:	93290e3f */ 	lbu	$t1,0xe3f($t9)
/*  f10b0e0:	00095080 */ 	sll	$t2,$t1,0x2
/*  f10b0e4:	006a5821 */ 	addu	$t3,$v1,$t2
/*  f10b0e8:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*  f10b0ec:	0fc42154 */ 	jal	filemgrSetFileToDelete
/*  f10b0f0:	9185030b */ 	lbu	$a1,0x30b($t4)
/*  f10b0f4:	3c048007 */ 	lui	$a0,0x8007
/*  f10b0f8:	0fc3cef8 */ 	jal	menuPushDialog
/*  f10b0fc:	24844f54 */ 	addiu	$a0,$a0,0x4f54
/*  f10b100:	1000001d */ 	b	.JF0f10b178
/*  f10b104:	8fa40020 */ 	lw	$a0,0x20($sp)
.JF0f10b108:
/*  f10b108:	3c0d8007 */ 	lui	$t5,0x8007
/*  f10b10c:	8dad1998 */ 	lw	$t5,0x1998($t5)
/*  f10b110:	00c02025 */ 	move	$a0,$a2
/*  f10b114:	01a80019 */ 	multu	$t5,$t0
/*  f10b118:	00007012 */ 	mflo	$t6
/*  f10b11c:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f10b120:	91f80e3f */ 	lbu	$t8,0xe3f($t7)
/*  f10b124:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f10b128:	00794821 */ 	addu	$t1,$v1,$t9
/*  f10b12c:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f10b130:	9145030b */ 	lbu	$a1,0x30b($t2)
/*  f10b134:	0fc42154 */ 	jal	filemgrSetFileToDelete
/*  f10b138:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f10b13c:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f10b140:	3c0b8007 */ 	lui	$t3,0x8007
/*  f10b144:	8d6b1998 */ 	lw	$t3,0x1998($t3)
/*  f10b148:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f10b14c:	3c0d800a */ 	lui	$t5,0x800a
/*  f10b150:	25ad28f0 */ 	addiu	$t5,$t5,0x28f0
/*  f10b154:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f10b158:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f10b15c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f10b160:	94cf0004 */ 	lhu	$t7,0x4($a2)
/*  f10b164:	3c048007 */ 	lui	$a0,0x8007
/*  f10b168:	24844ed8 */ 	addiu	$a0,$a0,0x4ed8
/*  f10b16c:	0fc3cef8 */ 	jal	menuPushDialog
/*  f10b170:	a44f0004 */ 	sh	$t7,0x4($v0)
.JF0f10b174:
/*  f10b174:	8fa40020 */ 	lw	$a0,0x20($sp)
.JF0f10b178:
/*  f10b178:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f10b17c:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f10b180:	0fc42b56 */ 	jal	filemgrFileToCopyOrDeleteListMenuHandler
/*  f10b184:	24070001 */ 	li	$a3,0x1
.JF0f10b188:
/*  f10b188:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10b18c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10b190:	03e00008 */ 	jr	$ra
/*  f10b194:	00000000 */ 	nop
);
#else
s32 filemgrFileToDeleteListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum] == NULL) {
		return 0;
	}

	if (operation == MENUOP_SET) {
		struct filelistfile *file = &g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->files[data->list.value];

		if (file) {
			if (filemgrIsFileInUse(file)) {
				filemgrSetFileToDelete(file, g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->filetype);
				menuPushDialog(&g_FilemgrFileInUseMenuDialog);
			} else {
				filemgrSetFileToDelete(file, g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->filetype);
				g_FilemgrFileToDelete.fileid = file->fileid;
				g_FilemgrFileToDelete.deviceserial = file->deviceserial;
				menuPushDialog(&g_FilemgrConfirmDeleteMenuDialog);
			}
		}
	}

	return filemgrFileToCopyOrDeleteListMenuHandler(operation, item, data, true);
}
#endif

s32 filemgrFileToCopyListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct filelist *list = g_FileLists[0];

	if (list == NULL) {
		return 0;
	}

	if (operation == MENUOP_SET) {
		struct filelistfile *file = &list->files[data->list.value];

		if (file) {
			g_FilemgrFileToCopy.fileid = file->fileid;
			g_FilemgrFileToCopy.deviceserial = file->deviceserial;

#if VERSION >= VERSION_NTSC_1_0
			filemgrGetFileName(g_Menus[g_MpPlayerNum].fm.filename, file);
#endif
			filemgrPushSelectLocationDialog(g_Menus[g_MpPlayerNum].fm.filetypeplusone, g_Menus[g_MpPlayerNum].fm.filetypeplusone - 1);
		}
	}

	return filemgrFileToCopyOrDeleteListMenuHandler(operation, item, data, false);
}

s32 filemgrCopyOrDeleteListMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_CLOSE) {
		if (g_Menus[g_MpPlayerNum].fm.isdeletingforsave == true) {
			g_Menus[g_MpPlayerNum].fm.isdeletingforsave = false;
		} else {
			filelistCreate(0, FILETYPE_GAME);
			g_Menus[g_MpPlayerNum].fm.filetypeplusone = 0;
		}
	}

	return 0;
}

void filemgrPushDeleteFileDialog(s32 listnum)
{
	struct filelist *list;

	g_Menus[g_MpPlayerNum].fm.listnum = listnum;
	g_Menus[g_MpPlayerNum].fm.isdeletingforsave = false;
	g_Menus[g_MpPlayerNum].fm.filetypeplusone = 1;

	list = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum];

	if (list) {
		g_Menus[g_MpPlayerNum].fm.filetypeplusone = list->filetype + 1;
	}

	menuPushDialog(&g_FilemgrDeleteMenuDialog);
}

s32 pakDeleteGameNoteMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		OSPfsState *note = &g_EditingPak->notes[g_Menus[g_MpPlayerNum].fm.noteindex];
		s32 result;

		g_Menus[g_MpPlayerNum].fm.unke24 = g_Menus[g_MpPlayerNum].fm.unke24 | (1 << g_Menus[g_MpPlayerNum].fm.device);

		menuPopDialog();

		result = pakDeleteGameNote(g_Menus[g_MpPlayerNum].fm.device,
				note->company_code, note->game_code, note->game_name, note->ext_name);

		g_Menus[g_MpPlayerNum].fm.device1 = g_Menus[g_MpPlayerNum].fm.device;

		if (result) {
			filemgrPushErrorDialog(FILEERROR_DELETENOTEFAILED);
		}
	}

	return 0;
}

/**
 * Handler for the note listing in the controller pak menu.
 */
s32 pakGameNoteListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 x;
	s32 y;
	Gfx *gdl;
	struct menuitemrenderdata *renderdata;
	OSPfsState *note;
#if VERSION >= VERSION_JPN_FINAL
	char tmpname[52];
	char tmpext[20];
	char generalbuffer[80];
	char extbuffer[80];
	char pagesbuffer[80];
#elif VERSION >= VERSION_NTSC_1_0
	char tmpname[40];
	char tmpext[12];
	char generalbuffer[60];
	char extbuffer[60];
	char pagesbuffer[60];
#else
	char tmpname[20];
	char tmpext[8];
	char generalbuffer[28];
	char extbuffer[28];
	char pagesbuffer[28];
#endif
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
			pakN64FontCodeToAscii(note->game_name, tmpname, 16);
			pakN64FontCodeToAscii(note->ext_name, tmpext, 4);

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
		x = renderdata->x + (VERSION == VERSION_JPN_FINAL ? 220 : 190);
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
		data->list.value = VERSION == VERSION_JPN_FINAL ? LINEHEIGHT - 1 : LINEHEIGHT;
		break;
	case MENUOP_SET:
		if (g_EditingPak->notesinuse[data->list.value] == true) {
			g_Menus[g_MpPlayerNum].fm.noteindex = data->list.value;
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

/**
 * Controller pak note listing dialog.
 */
s32 pakGameNotesMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curdialog
				&& g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef) {
			s32 value = pak0f1168c4(g_Menus[g_MpPlayerNum].fm.device, &g_EditingPak);

			if (value) {
				menuCloseDialog();
				g_EditingPak = NULL;
				g_Menus[g_MpPlayerNum].fm.device1 = g_Menus[g_MpPlayerNum].fm.device;

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

/**
 * Title for the note listing dialog.
 */
char *pakMenuTextEditingPakName(struct menuitem *item)
{
	return filemgrGetDeviceName(g_Menus[g_MpPlayerNum].fm.device);
}

/**
 * A pak selection on the controller pak menu.
 *
 * Selecting one takes you to the note listing dialog.
 */
s32 pakSelectionMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if (!pakIsMemoryPak((s8)item->param)) {
			return true;
		}
	}

	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].fm.device = item->param;
		menuPushDialog(&g_PakGameNotesMenuDialog);
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
/**
 * Controller pak menu.
 *
 * Lists the connected controller paks.
 */
s32 pakChoosePakMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		joy0001398c(3);
		g_Menus[g_MpPlayerNum].fm.unke24 = 0;
		break;
	case MENUOP_TICK:
		var80062944 = 1;
		break;
	case MENUOP_CLOSE:
		if (g_Vars.stagenum != STAGE_BOOTPAKMENU) {
			s32 i;

			for (i = 0; i < 4; i++) {
				if (g_Menus[g_MpPlayerNum].fm.unke24 & (1 << i)) {
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
/*  f106bf8:	0fc44356 */ 	jal	pak0f1169c8
/*  f106bfc:	2ca50001 */ 	sltiu	$a1,$a1,0x1
/*  f106c00:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f106c04:
/*  f106c04:	5616ffee */ 	bnel	$s0,$s6,.NB0f106bc0
/*  f106c08:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f106c0c:	0c00529f */ 	jal	joy000139c8
/*  f106c10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106c14:	0fc44b4a */ 	jal	pak0f1189d0
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
		g_Menus[g_MpPlayerNum].fm.filetypeplusone = item->param + 1;
		filelistCreate(0, item->param);

#if VERSION >= VERSION_NTSC_1_0
		g_Menus[g_MpPlayerNum].fm.listnum = 0;
#endif
		g_Menus[g_MpPlayerNum].fm.isdeletingforsave = false;

		menuPushDialog(&g_FilemgrCopyMenuDialog);
	}

	return 0;
}

s32 filemgrOpenDeleteFileMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].fm.filetypeplusone = item->param + 1;
		filelistCreate(0, item->param);
		g_Menus[g_MpPlayerNum].fm.unke3e = -1;
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
		g_Menus[g_MpPlayerNum].fm.unke2c = 1;
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
			if (data->list.groupstartindex == 1 && g_Menus[g_MpPlayerNum].fm.unke2c == 1) {
				for (i = 0; i < g_FileLists[0]->numfiles; i++) {
					if (g_GameFileGuid.fileid == g_FileLists[0]->files[i].fileid
							&& g_GameFileGuid.deviceserial == g_FileLists[0]->files[i].deviceserial) {
						data->list.value = i;
					}
				}

				g_Menus[g_MpPlayerNum].fm.unke2c = 0;
			}

			if (g_FileLists[0]->updatedthisframe) {
				pass = true;
			}
		} else {
			pass = true;
			g_Menus[g_MpPlayerNum].fm.unke2c = 0;
		}

		if (pass && g_Vars.bossfileid) {
			for (j = 0; j < g_FileLists[0]->numfiles; j++) {
				if (g_Vars.bossfileid == g_FileLists[0]->files[j].fileid
						&& g_Vars.bossdeviceserial == g_FileLists[0]->files[j].deviceserial) {
					data->list.value = j;
					g_Vars.bossfileid = 0;
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
				gamefileGetOverview(file->name, name, &stage, &difficulty, &time);

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

		texSelect(&gdl, &g_TexGeneralConfigs[texturenum], 2, 0, 2, 1, NULL);

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
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 3 : 4);
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
			y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 16 : 18);
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

#if VERSION == VERSION_JPN_FINAL
			x -= 3;
#endif

			if (days > 0) {
				// "Mission Time:"
				sprintf(buffer, "%s %d:%02d:%02d", langGet(L_OPTIONS_405), days, hours, minutes);
			} else {
				// "Mission Time:"
				sprintf(buffer, "%s %02d:%02d", langGet(L_OPTIONS_405), hours, minutes);
			}

			// Useless - textwidth and textheight are not used
#if VERSION >= VERSION_JPN_FINAL
			textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, -1);
#else
			textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
#endif

			gdl = textRenderProjected(gdl, &x, &y, buffer,
					g_CharsHandelGothicSm, g_FontHandelGothicSm, renderdata->colour, viGetWidth(), viGetHeight(), 0, 0);

			// Render seconds part of mission time (uses a smaller font)
			y += (VERSION == VERSION_JPN_FINAL) ? 3 : 1;
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
			// New agent
			gamefileLoadDefaults(&g_GameFile);
			menuPushDialog(&g_FilemgrEnterNameMenuDialog);
		} else {
			struct filelistfile *file = &g_FileLists[0]->files[data->list.value];

			if (file) {
				g_GameFileGuid.fileid = file->fileid;
				g_GameFileGuid.deviceserial = file->deviceserial;
				filemgrSaveOrLoad(&g_GameFileGuid, FILEOP_LOAD_GAME, 0);
			}
		}
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = g_FileLists[0]->numdevices + 1;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		if (data->list.value >= g_FileLists[0]->numdevices) {
			return (u32) langGet(L_OPTIONS_402); // "New..."
		}
		return filemgrGetDeviceNameOrStartIndex(0, operation, data->list.value);
	case MENUOP_GETGROUPSTARTINDEX:
		if (data->list.value >= g_FileLists[0]->numdevices) {
			data->list.groupstartindex = g_FileLists[0]->numfiles;
		} else {
			data->list.groupstartindex = filemgrGetDeviceNameOrStartIndex(0, operation, data->list.value);
		}
		return 0;
	}

	return 0;
}

s32 filemgrMainMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	s32 i;

	switch (operation) {
	case MENUOP_OPEN:
		g_Menus[g_MpPlayerNum].fm.filetypeplusone = 0;

		filelistCreate(0, FILETYPE_GAME);
		mpInit();

		// Set MP player names to "Player 1" through 4 if blank
		for (i = 0; i < 4; i++) {
			if (g_PlayerConfigsArray[i].base.name[0] == '\0') {
				sprintf(g_PlayerConfigsArray[i].base.name, "%s %d\n", langGet(L_MISC_437), i + 1);
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

bool filemgrConsiderPushingFileSelectDialog(void)
{
	if (g_Menus[g_MpPlayerNum].openinhibit == 0) {
		g_Menus[g_MpPlayerNum].playernum = 0;
		menuPushRootDialog(&g_FilemgrFileSelectMenuDialog, MENUROOT_FILEMGR);

#if PAL
		if (g_Vars.language >= 6) {
			menuPushDialog(&g_ChooseLanguageMenuDialog);
		}
#endif

		return true;
	}

	return false;
}

void bootmenuReset(void)
{
	s32 prevplayernum = g_MpPlayerNum;
	g_MpPlayerNum = 0;
	menuPushRootDialog(&g_PakChoosePakMenuDialog, MENUROOT_BOOTPAKMGR);
	g_MpPlayerNum = prevplayernum;
}

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

struct menudialogdef g_FilemgrSelectLocationMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_367, // "Select Location"
	g_FilemgrSelectLocationMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLEBANNER,
	NULL,
};

struct menuitem g_FilemgrConfirmDeleteMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&filemgrMenuTextDeleteFileName, 0x00000000, filemgrFileNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000230, (u32)&filemgrMenuTextDeviceName, 0x00000000, filemgrDeviceNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_380, 0x00000000, NULL }, // "Are you sure you want to delete this file?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS_381, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_382, 0x00000000, filemgrConfirmDeleteMenuHandler }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FilemgrConfirmDeleteMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_379, // "Warning"
	g_FilemgrConfirmDeleteMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLEBANNER,
	NULL,
};

struct menuitem g_FilemgrFileInUseMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&filemgrMenuTextDeleteFileName, 0x00000000, filemgrFileNameMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00000230, (u32)&filemgrMenuTextDeviceName, 0x00000000, filemgrDeviceNameMenuHandler },
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&filemgrMenuTextFileInUseDescription, 0x00000000, NULL },
#else
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, 0x54a0, 0x00000000, NULL },
#endif
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS_161, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FilemgrFileInUseMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_159, // "Error"
	g_FilemgrFileInUseMenuItems,
	NULL,
	MENUDIALOGFLAG_DISABLEBANNER,
	NULL,
};

struct menuitem g_FilemgrDeleteMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS_377, 0x00000000, NULL }, // "Select a file to delete:"
	{ MENUITEMTYPE_LIST,        1, 0x00200000, 0x00000000, 0x00000000, filemgrFileToDeleteListMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00004030, L_OPTIONS_378, 0x00000000, NULL }, // "Press B Button to exit."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FilemgrDeleteMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_376, // "Delete File"
	g_FilemgrDeleteMenuItems,
	filemgrCopyOrDeleteListMenuDialog,
	0,
	NULL,
};

struct menuitem g_FilemgrCopyMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS_374, 0x00000000, NULL }, // "Select a file to copy:"
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x00000000, 0x00000000, filemgrFileToCopyListMenuHandler },
	{ MENUITEMTYPE_LABEL,       0, 0x00004030, L_OPTIONS_375, 0x00000000, NULL }, // "Press B Button to exit."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FilemgrCopyMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_373, // "Copy File"
	g_FilemgrCopyMenuItems,
	filemgrCopyOrDeleteListMenuDialog,
	0,
	NULL,
};

struct pakdata *g_EditingPak = NULL;

struct menuitem g_PakDeleteNoteMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS_384, 0x00000000, NULL }, // "Are you sure you want to delete this game note?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS_385, 0x00000000, NULL }, // "No"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS_386, 0x00000000, pakDeleteGameNoteMenuHandler }, // "Yes"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_PakDeleteNoteMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_383, // "Delete Game Note"
	g_PakDeleteNoteMenuItems,
	NULL,
	0,
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

struct menudialogdef g_PakGameNotesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_387, // "Game Notes"
	g_PakGameNotesMenuItems,
	pakGameNotesMenuDialog,
	0,
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

struct menudialogdef g_PakChoosePakMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_107, // "Controller Pak Menu"
	g_PakChoosePakMenuItems,
	pakChoosePakMenuDialog,
	0,
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

struct menudialogdef g_FilemgrOperationsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_099, // "Game Files"
	g_FilemgrOperationsMenuItems,
	NULL,
	MENUDIALOGFLAG_IGNOREBACK,
	NULL,
};

struct menuitem g_FilemgrEnterNameMenuItems[] = {
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000001, filemgrAgentNameKeyboardMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FilemgrEnterNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_401, // "Enter Agent Name"
	g_FilemgrEnterNameMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_FilemgrFileSelectMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004010, L_OPTIONS_096, 0x00000000, NULL }, // "Choose Your Reality"
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x000000f5, 0x00000000, filemgrChooseAgentListMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_FilemgrFileSelectMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_095, // "Perfect Dark"
	g_FilemgrFileSelectMenuItems,
	filemgrMainMenuDialog,
	MENUDIALOGFLAG_IGNOREBACK,
	&g_FilemgrOperationsMenuDialog,
};
