#include <ultra64.h>
#include "constants.h"
#include "game/filelist.h"
#include "game/tex.h"
#include "game/savebuffer.h"
#include "game/menu.h"
#include "game/filemgr.h"
#include "game/bossfile.h"
#include "game/text.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/joy.h"
#include "lib/mema.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"

// bss
struct fileguid g_FilemgrFileToCopy;
struct fileguid var800a21e8;

#if VERSION >= VERSION_JPN_FINAL
struct fileguid g_FilemgrFileToDelete[MAX_PLAYERS];
#else
struct fileguid g_FilemgrFileToDelete;
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

void filemgr_retry_save(s32 context);
void filemgr_push_delete_file_dialog(s32 listnum);
bool filemgr_attempt_operation(s32 device, bool closeonsuccess);

#if PAL
MenuItemHandlerResult filemgr_handle_set_language(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Vars.language = item->param;
		lang_set_european(g_Vars.language);
		menu_pop_dialog();
	}

	return 0;
}

struct menuitem g_ChooseLanguageMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_DARKERBG,
		L_MPWEAPONS_261, // "Choose your language:"
		0,
		0,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		0,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		LANGUAGE_PAL_EN,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_262, // "English"
		0,
		filemgr_handle_set_language,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		LANGUAGE_PAL_FR,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_263, // "French"
		0,
		filemgr_handle_set_language,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		LANGUAGE_PAL_DE,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_264, // "German"
		0,
		filemgr_handle_set_language,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		LANGUAGE_PAL_IT,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_265, // "Italian"
		0,
		filemgr_handle_set_language,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		LANGUAGE_PAL_ES,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_266, // "Spanish"
		0,
		filemgr_handle_set_language,
	},
	{ MENUITEMTYPE_END },
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

char *filemgr_get_device_name(s32 index)
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
		return lang_get(names[index]);
	}

	return NULL;
}

MenuItemHandlerResult filemgr_device_name_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if ((g_Menus[g_MpPlayerNum].fm.device1 & 0x7f) >= SAVEDEVICE_INVALID) {
			return true;
		}
	}

	return 0;
}

char *filemgr_menu_text_device_name(struct menuitem *item)
{
	return filemgr_get_device_name(g_Menus[g_MpPlayerNum].fm.device1 & 0x7f);
}

void filemgr_get_select_name(char *buffer, struct filelistfile *file, u32 filetype)
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
		savebuffer_bitstring_to_cstring(file->name, tmpbuffer1, false);
		break;
	case FILETYPE_MPPLAYER:
		// MP Player filenames have the play duration appended to the name
		mpplayerfile_get_overview(file->name, namebuffer, &totalinseconds);
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

MenuItemHandlerResult filemgr_file_name_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_Menus[g_MpPlayerNum].fm.filetodelete == 0) {
			return true;
		}
	}

	return 0;
}

char *filemgr_menu_text_delete_file_name(struct menuitem *item)
{
	if (g_Menus[g_MpPlayerNum].fm.filetodelete) {
		filemgr_get_select_name(g_StringPointer,
				g_Menus[g_MpPlayerNum].fm.filetodelete,
				g_Menus[g_MpPlayerNum].fm.filetypetodelete);
		return g_StringPointer;
	}

	return NULL;
}

void filemgr_set_device1_by_serial(s32 deviceserial)
{
	s32 device = pak_find_by_serial(deviceserial);

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

void filemgr_set_device1_by_file(struct filelistfile *file)
{
	filemgr_set_device1_by_serial(file->deviceserial);
}

void filemgr_set_file_to_delete(struct filelistfile *file, s32 filetype)
{
	g_Menus[g_MpPlayerNum].fm.filetypetodelete = filetype;
	g_Menus[g_MpPlayerNum].fm.filetodelete = file;
	filemgr_set_device1_by_file(file);
}

char *filemgr_menu_text_fail_reason(struct menuitem *item)
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

	return lang_get(reasons[g_Menus[g_MpPlayerNum].fm.errno]);
}

/**
 * Unused.
 */
char *filemgr0f108484(struct menuitem *item)
{
	sprintf(g_StringPointer, "location: controller pak 1\n");
	return g_StringPointer;
}

MenuItemHandlerResult filemgr_device_name_for_error_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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

char *filemgr_menu_text_device_name_for_error(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s", filemgr_get_device_name(g_Menus[g_MpPlayerNum].fm.device1 & 0x7f));

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

void filemgr_push_error_dialog(u16 errno)
{
	g_Menus[g_MpPlayerNum].fm.errno = errno;

	menu_push_dialog(&g_FilemgrErrorMenuDialog);
}

struct menuitem g_FilemgrErrorMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		(uintptr_t) &filemgr_menu_text_device_name_for_error,
		0,
		filemgr_device_name_for_error_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		(uintptr_t) &filemgr_menu_text_fail_reason,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_321, // "Cancel"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
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
s32 filemgr_get_device_name_or_start_index(s32 listnum, s32 operation, s32 optionindex)
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
					return (s32)lang_get(names[i]);
				}

				return g_FileLists[listnum]->devicestartindexes[i];
			}

			remaining--;
		}
	}

	return 0;
}

char *filemgr_menu_text_error_title(struct menuitem *item)
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
		return lang_get(messages[0]);
	case FILEOP_SAVE_GAME_000:
	case FILEOP_SAVE_GAME_001:
	case FILEOP_SAVE_GAME_002:
	case FILEOP_SAVE_MPSETUP:
		return lang_get(messages[1]);
	case FILEOP_LOAD_MPPLAYER:
		return lang_get(messages[2]);
	case FILEOP_SAVE_MPPLAYER:
		return lang_get(messages[3]);
	case FILEOP_READ_GAME:
	case FILEOP_READ_MPSETUP:
	case FILEOP_READ_MPPLAYER:
		return lang_get(messages[6]);
	case FILEOP_WRITE_GAME:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_WRITE_MPPLAYER:
		return lang_get(messages[7]);
	}

	return lang_get(messages[8]);
}

#if VERSION >= VERSION_NTSC_1_0
char *filemgr_menu_text_file_type(struct menuitem *item)
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
		return lang_get(names[0]);
	case FILEOP_SAVE_MPSETUP:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_LOAD_MPSETUP:
	case FILEOP_READ_MPSETUP:
		return lang_get(names[1]);
	case FILEOP_SAVE_MPPLAYER:
	case FILEOP_WRITE_MPPLAYER:
	case FILEOP_LOAD_MPPLAYER:
	case FILEOP_READ_MPPLAYER:
		return lang_get(names[2]);
	}

	return lang_get(names[0]);
}
#endif

void func0f10898c(void)
{
	menu_set_banner(-1, false);

	switch (g_Menus[g_MpPlayerNum].fm.fileop) {
	case FILEOP_WRITE_GAME:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_WRITE_MPPLAYER:
	case FILEOP_READ_GAME:
	case FILEOP_READ_MPSETUP:
	case FILEOP_READ_MPPLAYER:
		mema_free(g_Menus[g_MpPlayerNum].fm.unke44, align16(g_FileTypeSizes[g_Menus[g_MpPlayerNum].fm.filetypeplusone - 1]));
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

void filemgr_handle_success(void)
{
	menu_set_banner(-1, false);

	switch (g_Menus[g_MpPlayerNum].fm.fileop) {
	case FILEOP_WRITE_GAME:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_WRITE_MPPLAYER:
		mema_free(g_Menus[g_MpPlayerNum].fm.unke44,
				align16(g_FileTypeSizes[g_Menus[g_MpPlayerNum].fm.filetypeplusone - 1]));
		break;
	case FILEOP_LOAD_GAME:
		g_Vars.bossfileid = g_Menus[g_MpPlayerNum].fm.fileid;
		g_Vars.bossdeviceserial = g_Menus[g_MpPlayerNum].fm.deviceserial;
		bossfile_save();

		if (IS4MB()) {
			menu_save_and_push_root_dialog(&g_MainMenu4MbMenuDialog, MENUROOT_4MBMAINMENU);
		} else {
			menu_save_and_push_root_dialog(&g_CiMenuViaPcMenuDialog, MENUROOT_MAINMENU);
		}
		break;
	case FILEOP_READ_GAME:
	case FILEOP_READ_MPSETUP:
	case FILEOP_READ_MPPLAYER:
		filemgr_save_or_load(&var800a21e8,
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

MenuItemHandlerResult filemgr_retry_save_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		filemgr_retry_save(2);
	}

	return 0;
}

MenuItemHandlerResult filemgr_save_elsewhere_yes_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 filetype;

		menu_close_dialog();

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

		filemgr_push_select_location_dialog(g_Menus[g_MpPlayerNum].fm.fileop + 9, filetype);
	}

	return 0;
}

MenuItemHandlerResult filemgr_cancel_save2_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menu_close_dialog();
		func0f10898c();
		menu_update_cur_frame();
	}

	return 0;
}

/**
 * Unused.
 */
MenuItemHandlerResult filemgr0f108d14(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		filemgr_retry_save(2);
	}

	return 0;
}

MenuItemHandlerResult filemgr_acknowledge_file_lost_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menu_close_dialog();
		func0f10898c();
		menu_update_cur_frame();
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
void filemgr_erase_corrupt_file(void)
{
	s32 device;
	s32 i;

	device = pak_find_by_serial(g_Menus[g_MpPlayerNum].fm.deviceserial);

	if (device >= 0) {
		pak_delete_file(device, g_Menus[g_MpPlayerNum].fm.fileid);
	}

	for (i = 0; i < ARRAYCOUNT(g_FileLists); i++) {
		if (g_FileLists[i]) {
			g_FileLists[i]->timeuntilupdate = 1;
		}
	}

	menu_push_dialog(&g_FilemgrFileLostMenuDialog);
}
#endif

MenuDialogHandlerResult filemgr_insert_original_pak_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curdialog &&
				g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef) {
			filemgr_retry_save(0);
		}
	}

	return false;
}

MenuItemHandlerResult filemgr_reinserted_ok_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		pak_execute_debug_operations();
		filemgr_retry_save(1);
	}

	return 0;
}

MenuItemHandlerResult filemgr_reinserted_cancel_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fm.fileop) && g_Menus[g_MpPlayerNum].fm.fileop != FILEOP_SAVE_GAME_001) {
			menu_replace_current_dialog(&g_FilemgrSaveElsewhereMenuDialog);
		} else {
			menu_pop_dialog();
		}
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
char *filemgr_menu_text_insert_original_pak(struct menuitem *item)
{
	char fullbuffer[100];
	char namebuffer[100];
	s32 i;

	sprintf(namebuffer, filemgr_menu_text_file_type(item));

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
	sprintf(fullbuffer, lang_get(L_OPTIONS_363), namebuffer);

	text_wrap(120, fullbuffer, g_StringPointer, g_CharsHandelGothicSm, g_FontHandelGothicSm);

	return g_StringPointer;
}
#endif

/**
 * Context is:
 * 0 on tick while reinsert dialog is open
 * 1 when user selects OK on reinsert dialog
 * 2 when user selects Retry Save on error dialog
 */
void filemgr_retry_save(s32 context)
{
	s32 device = pak_find_by_serial(g_Menus[g_MpPlayerNum].fm.deviceserial);

	if (device == -1) {
		if (context == 1) {
			filemgr_push_error_dialog(FILEERROR_NOPAK);
		}

		if (context == 2) {
			menu_replace_current_dialog(&g_PakNotOriginalMenuDialog);
		}
	} else if (filemgr_attempt_operation(device, true)) {
		if (context == 2) {
			g_Menus[g_MpPlayerNum].fm.device1 = device;

			if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fm.fileop)) {
				filemgr_push_error_dialog(FILEERROR_SAVEFAILED);
			} else {
				filemgr_push_error_dialog(FILEERROR_LOADFAILED);
			}
		} else {
			filemgr_set_device1_by_serial(g_Menus[g_MpPlayerNum].fm.deviceserial);

			if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fm.fileop)) {
				menu_replace_current_dialog(&g_FilemgrSaveErrorMenuDialog);
			} else {
#if VERSION >= VERSION_NTSC_1_0
				filemgr_erase_corrupt_file();
#else
				menu_replace_current_dialog(&g_FilemgrFileLostMenuDialog);
#endif
			}
		}
	}
}

bool filemgr_attempt_operation(s32 device, bool closeonsuccess)
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
		errno = gamefile_save(device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				g_Menus[g_MpPlayerNum].fm.deviceserial);
		break;
	case FILEOP_SAVE_MPPLAYER:
		errno = mpplayerfile_save(
				(s32) g_Menus[g_MpPlayerNum].fm.unke44, device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				g_Menus[g_MpPlayerNum].fm.deviceserial);
		break;
	case FILEOP_SAVE_MPSETUP:
		errno = mpsetupfile_save(device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				g_Menus[g_MpPlayerNum].fm.deviceserial);
		showfilesaved = true;
		break;
	case FILEOP_WRITE_GAME:
	case FILEOP_WRITE_MPSETUP:
	case FILEOP_WRITE_MPPLAYER:
		newfileid = 0;
#if VERSION >= VERSION_NTSC_1_0
		savebuffer_cstring_to_bitstring(g_Menus[g_MpPlayerNum].fm.unke44, g_Menus[g_MpPlayerNum].fm.filename);
#endif
		errno = pak_save_at_guid(device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				filetypes[g_Menus[g_MpPlayerNum].fm.fileop - 6],
				g_Menus[g_MpPlayerNum].fm.unke44, &newfileid, NULL);
		var80075bd0[g_Menus[g_MpPlayerNum].fm.fileop - 6] = 1;
		break;
	case FILEOP_LOAD_GAME:
		errno = gamefile_load(device);
		break;
	case FILEOP_LOAD_MPPLAYER:
		errno = mpplayerfile_load(
				(s32) g_Menus[g_MpPlayerNum].fm.unke44,
				device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				g_Menus[g_MpPlayerNum].fm.deviceserial);
		break;
	case FILEOP_LOAD_MPSETUP:
		errno = mpsetupfile_load(device,
				g_Menus[g_MpPlayerNum].fm.fileid,
				g_Menus[g_MpPlayerNum].fm.deviceserial);
		break;
	case FILEOP_READ_GAME:
	case FILEOP_READ_MPSETUP:
	case FILEOP_READ_MPPLAYER:
#if VERSION >= VERSION_NTSC_1_0
		errno = pak_read_body_at_guid(device, g_Menus[g_MpPlayerNum].fm.fileid, g_Menus[g_MpPlayerNum].fm.unke44, 0);
#else
		errno = pak_read_body_at_guid(device, g_Menus[g_MpPlayerNum].fm.fileid, g_Menus[g_MpPlayerNum].fm.unke44,
				g_FileTypeSizes[g_Menus[g_MpPlayerNum].fm.fileop - FILEOP_READ_GAME]);
#endif
		break;
	}

	if (errno == 0 && closeonsuccess) {
		menu_close_dialog();
	}

	if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fm.fileop)) {
		if (errno == 0) {
			filemgr_handle_success();
		}

		if (showfilesaved && errno == 0) {
			menu_push_dialog(&g_FilemgrFileSavedMenuDialog);
		}
	} else {
		if (errno == 0) {
			filemgr_handle_success();
		}
	}

	menu_update_cur_frame();

	return errno;
}

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
bool filemgr_save_or_load(struct fileguid *guid, s32 fileop, u32 playernum)
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

	device = pak_find_by_serial(g_Menus[g_MpPlayerNum].fm.deviceserial);

	if (device == -1) {
		// Original pak is no longer connected
		g_Menus[g_MpPlayerNum].fm.isretryingsave |= 1;
		menu_push_dialog(&g_PakNotOriginalMenuDialog);
		return false;
	}

	if (filemgr_attempt_operation(device, false) != 0) {
		// Operation failed
		g_Menus[g_MpPlayerNum].fm.isretryingsave |= 1;
		filemgr_set_device1_by_serial(g_Menus[g_MpPlayerNum].fm.deviceserial);

		if (FILEOP_IS_SAVE(g_Menus[g_MpPlayerNum].fm.fileop)) {
			menu_push_dialog(&g_FilemgrSaveErrorMenuDialog);
		} else {
			// File couldn't be loaded
#if VERSION >= VERSION_NTSC_1_0
			filemgr_erase_corrupt_file();
#else
			menu_push_dialog(&g_FilemgrFileLostMenuDialog);
#endif
		}

		return false;
	}

	return true;
}

void filemgr_delete_current_file(void)
{
#if VERSION >= VERSION_JPN_FINAL
	// JPN uses an array for g_FilemgrFileToDelete
	bool error = false;
	s8 device = pak_find_by_serial(g_FilemgrFileToDelete[g_MpPlayerNum].deviceserial);
	s32 i;

	if (device >= 0) {
		if (pak_delete_file(device, g_FilemgrFileToDelete[g_MpPlayerNum].fileid) != 0) {
			error = true;
		}
	} else {
		error = true;
	}

	g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->timeuntilupdate = 1;

	if (error) {
		g_Menus[g_MpPlayerNum].fm.device1 = device;
		filemgr_push_error_dialog(FILEERROR_DELETEFAILED);
	} else {
		// If deleting a loaded MP player, reset them to default
		for (i = 0; i < MAX_PLAYERS; i++) {
			if (g_FilemgrFileToDelete[g_MpPlayerNum].fileid == g_PlayerConfigsArray[i].fileguid.fileid
					&& g_FilemgrFileToDelete[g_MpPlayerNum].deviceserial == g_PlayerConfigsArray[i].fileguid.deviceserial) {
				mp_player_set_defaults(i, true);
			}
		}
	}
#else
	bool error = false;
	s8 device = pak_find_by_serial(g_FilemgrFileToDelete.deviceserial);
	s32 i;

	if (device >= 0) {
		if (pak_delete_file(device, g_FilemgrFileToDelete.fileid) != 0) {
			error = true;
		}
	} else {
		error = true;
	}

	g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->timeuntilupdate = 1;

	if (error) {
		g_Menus[g_MpPlayerNum].fm.device1 = device;
		filemgr_push_error_dialog(FILEERROR_DELETEFAILED);
	} else {
		// If deleting a loaded MP player, reset them to default
		for (i = 0; i < MAX_PLAYERS; i++) {
			if (g_FilemgrFileToDelete.fileid == g_PlayerConfigsArray[i].fileguid.fileid
					&& g_FilemgrFileToDelete.deviceserial == g_PlayerConfigsArray[i].fileguid.deviceserial) {
				mp_player_set_defaults(i, true);
			}
		}
	}
#endif
}

struct menuitem g_FilemgrFileSavedMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_OPTIONS_346, // "File Saved."
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_347, // "OK"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		(uintptr_t) &filemgr_menu_text_device_name,
		0,
		filemgr_device_name_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_OPTIONS_348, // "An error occurred while trying to save."
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_349, // "Try Again"
		0,
		filemgr_retry_save_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_350, // "Save Elsewhere"
		0,
		filemgr_save_elsewhere_yes_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_351, // "Cancel"
		0,
		filemgr_cancel_save2_menu_handler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_FilemgrSaveErrorMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(uintptr_t) &filemgr_menu_text_error_title,
	g_FilemgrSaveErrorMenuItems,
	NULL,
	MENUDIALOGFLAG_IGNOREBACK | MENUDIALOGFLAG_DISABLEBANNER,
	NULL,
};

struct menuitem g_FilemgrFileLostMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		(uintptr_t) &filemgr_menu_text_device_name,
		0,
		filemgr_device_name_menu_handler,
	},
#if VERSION >= VERSION_NTSC_1_0
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPWEAPONS_251, // "The saved file has been erased due to corruption or damage."
		0,
		NULL,
	},
#else
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_OPTIONS_352, // "An error occurred while trying to load."
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_353, // "Try Again"
		0,
		filemgr0f108d14,
	},
#endif
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_354, // "Cancel"
		0,
		filemgr_acknowledge_file_lost_menu_handler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_FilemgrFileLostMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(uintptr_t) &filemgr_menu_text_error_title,
	g_FilemgrFileLostMenuItems,
	NULL,
	MENUDIALOGFLAG_IGNOREBACK | MENUDIALOGFLAG_DISABLEBANNER,
	NULL,
};

struct menuitem g_FilemgrSaveElsewhereMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_OPTIONS_360, // "Would you like to save your file elsewhere?"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_361, // "Yes"
		0,
		filemgr_save_elsewhere_yes_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_362, // "No"
		0,
		filemgr_cancel_save2_menu_handler,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
#if VERSION >= VERSION_NTSC_1_0
		(uintptr_t) &filemgr_menu_text_insert_original_pak,
#else
		L_OPTIONS_363, // "Please insert the Controller Pak containing your %s into any controller."
#endif
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_365, // "OK"
		0,
		filemgr_reinserted_ok_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_366, // "Cancel"
		0,
		filemgr_reinserted_cancel_menu_handler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_PakNotOriginalMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	(uintptr_t) &filemgr_menu_text_error_title,
	g_PakNotOriginalMenuItems,
	filemgr_insert_original_pak_menu_dialog,
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

		thing = mema_alloc(align16(g_FileTypeSizes[g_Menus[g_MpPlayerNum].fm.filetypeplusone - 1]));

		if (thing) {
			filemgr_save_or_load(&g_FilemgrFileToCopy, g_Menus[g_MpPlayerNum].fm.filetypeplusone + 103, (s32) thing);
		} else {
			filemgr_push_error_dialog(FILEERROR_OUTOFMEMORY);
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

void filemgr_save_game_to_device(s32 device)
{
	if (g_FileLists[0]) {
		g_GameFileGuid.fileid = g_FileLists[0]->deviceguids[device].fileid;
		g_GameFileGuid.deviceserial = g_FileLists[0]->deviceguids[device].deviceserial;

		filemgr_save_or_load(&g_GameFileGuid, FILEOP_SAVE_GAME_000, 0);
	}
}

#if VERSION >= VERSION_NTSC_1_0
void filemgr_get_file_name(char *dst, struct filelistfile *file)
{
	char localbuffer[20];
	u32 playtime;

	localbuffer[0] = '\0';

	switch (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->filetype) {
	case FILETYPE_GAME:
	case FILETYPE_MPSETUP:
		savebuffer_bitstring_to_cstring(file->name, localbuffer, false);
		break;
	case FILETYPE_MPPLAYER:
		mpplayerfile_get_overview(file->name, localbuffer, &playtime);
		break;
	}

	sprintf(dst, "%s", localbuffer);
}
#endif

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b3294[] = "GETFileNameForThePurposesOfTheFileRenamingChecker: Unknown type %d\n";

void filemgr_get_rename_name(char *buffer)
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
void filemgr_set_rename_name(char *name)
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
bool filemgr_is_name_available(s32 device)
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
	// @dangerous: findname can overflow if filemgr_get_rename_name returns a long name.
	findname[0] = '\0';
	filemgr_get_rename_name(findname);

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
		filemgr_get_file_name(loopname, &g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->files[i]);

		// Convert loop filename to uppercase and remove trailing line break
		// @dangerous: loopname can overflow if filemgr_get_file_name returns a long name.
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
void filemgr_save_to_device(void)
{
	if (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->spacesfree[g_Menus[g_MpPlayerNum].fm.device2] > 0) {
		if (!filemgr_is_name_available(g_Menus[g_MpPlayerNum].fm.device2)) {
			menu_push_dialog(&g_FilemgrDuplicateNameMenuDialog);
		} else {
			menu_pop_dialog();

			if (g_Menus[g_MpPlayerNum].fm.unke3e == 0) {
				filemgr_save_game_to_device(g_Menus[g_MpPlayerNum].fm.device2);
			} else if (g_Menus[g_MpPlayerNum].fm.unke3e == 5) {
				// empty
			} else if (g_Menus[g_MpPlayerNum].fm.unke3e == 6) {
				struct fileguid guid;
				guid.fileid = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[g_Menus[g_MpPlayerNum].fm.device2].fileid;
				guid.deviceserial = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[g_Menus[g_MpPlayerNum].fm.device2].deviceserial;
				filemgr_save_or_load(&guid, FILEOP_SAVE_MPPLAYER, (u32)g_MpPlayerNum);
			} else if (g_Menus[g_MpPlayerNum].fm.unke3e == 7) {
				struct fileguid guid;
				guid.fileid = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[g_Menus[g_MpPlayerNum].fm.device2].fileid;
				guid.deviceserial = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[g_Menus[g_MpPlayerNum].fm.device2].deviceserial;
				filemgr_save_or_load(&guid, FILEOP_SAVE_MPSETUP, 0);
			} else if (g_Menus[g_MpPlayerNum].fm.unke3e >= 9) {
				struct fileguid guid;
				guid.fileid = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[g_Menus[g_MpPlayerNum].fm.device2].fileid;
				guid.deviceserial = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[g_Menus[g_MpPlayerNum].fm.device2].deviceserial;
				filemgr_save_or_load(&guid, -1, 0);
			} else {
				func0f1097d0(g_Menus[g_MpPlayerNum].fm.device2);
			}
		}
	}
}
#endif

#if VERSION >= VERSION_NTSC_1_0
MenuItemHandlerResult filemgr_confirm_rename_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	char *name = data->keyboard.string;

	switch (operation) {
	case MENUOP_GETTEXT:
		filemgr_get_rename_name(name);
		break;
	case MENUOP_SETTEXT:
		filemgr_set_rename_name(name);
		break;
	case MENUOP_SET:
		filemgr_save_to_device();
		break;
	}

	return 0;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
MenuItemHandlerResult filemgr_duplicate_rename_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menu_pop_dialog();
		menu_push_dialog(&g_FilemgrRenameMenuDialog);
	}

	return 0;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
MenuItemHandlerResult filemgr_duplicate_cancel_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menu_pop_dialog();
		menu_pop_dialog();
	}

	return 0;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
char *filemgr_menu_text_device_name_containing_duplicate_file(struct menuitem *item)
{
	return filemgr_get_device_name(g_Menus[g_MpPlayerNum].fm.device2);
}
#endif

#if VERSION >= VERSION_NTSC_1_0
char *filemgr_menu_text_duplicate_file_name(struct menuitem *item)
{
	char buffer[32];

	filemgr_get_rename_name(buffer);
	sprintf(g_StringPointer, "%s\n", buffer);

	return g_StringPointer;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
struct menuitem g_FilemgrRenameMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPWEAPONS_239, // "Enter new file name:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_KEYBOARD,
		0,
		0,
		0,
		0,
		filemgr_confirm_rename_menu_handler,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE,
		(uintptr_t) &filemgr_menu_text_device_name_containing_duplicate_file,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LESSHEIGHT,
		L_MPWEAPONS_233, // "already contains"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LESSHEIGHT,
		L_MPWEAPONS_234, // "a file named"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LESSHEIGHT,
		(uintptr_t) &filemgr_menu_text_duplicate_file_name,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPWEAPONS_235, // "Rename File"
		0,
		filemgr_duplicate_rename_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPWEAPONS_236, // "Change Location"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPWEAPONS_237, // "Cancel"
		0,
		filemgr_duplicate_cancel_menu_handler,
	},
	{ MENUITEMTYPE_END },
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

char *filemgr_menu_text_location_name2(struct menuitem *item)
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
		return lang_get(names[5]);
	}
#else
	if (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->spacesfree[item->param] <= 0) {
		return lang_get(names[5]);
	}
#endif

	return lang_get(names[item->param]);
}

char *filemgr_menu_text_save_location_spaces(struct menuitem *item)
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
		return lang_get(L_OPTIONS_372); // "Full"
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

/**
 * item->param is a SAVEDEVICE constant.
 */
MenuItemHandlerResult filemgr_select_location_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
#if VERSION >= VERSION_NTSC_1_0
		g_Menus[g_MpPlayerNum].fm.device2 = item->param;
		filemgr_save_to_device();
#else
		menu_pop_dialog();

		if (g_Menus[g_MpPlayerNum].fm.unke3e == 0) {
			filemgr_save_game_to_device(item->param);
		} else if (g_Menus[g_MpPlayerNum].fm.unke3e == 5) {
			// empty
		} else if (g_Menus[g_MpPlayerNum].fm.unke3e == 6) {
			struct fileguid guid;
			guid.fileid = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[item->param].fileid;
			guid.deviceserial = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[item->param].deviceserial;
			filemgr_save_or_load(&guid, FILEOP_SAVE_MPPLAYER, (u32)g_MpPlayerNum);
		} else if (g_Menus[g_MpPlayerNum].fm.unke3e == 7) {
			struct fileguid guid;
			guid.fileid = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[item->param].fileid;
			guid.deviceserial = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[item->param].deviceserial;
			filemgr_save_or_load(&guid, FILEOP_SAVE_MPSETUP, 0);
		} else if (g_Menus[g_MpPlayerNum].fm.unke3e >= 9) {
			struct fileguid guid;
			guid.fileid = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[item->param].fileid;
			guid.deviceserial = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->deviceguids[item->param].deviceserial;
			filemgr_save_or_load(&guid, -1, 0);
		} else {
			func0f1097d0(item->param);
		}
#endif
	}

	return 0;
}

MenuItemHandlerResult filemgr_cancel_save_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menu_pop_dialog();
	}

	return 0;
}

MenuItemHandlerResult filemgr_delete_files_for_save_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		filemgr_push_delete_file_dialog(g_Menus[g_MpPlayerNum].fm.listnum);
		g_Menus[g_MpPlayerNum].fm.isdeletingforsave = true;
	}

	return 0;
}

void filemgr_push_select_location_dialog(s32 arg0, u32 filetype)
{
	g_Menus[g_MpPlayerNum].fm.unke3e = arg0;
	g_Menus[g_MpPlayerNum].fm.listnum = filelist_find_or_create(filetype);

#if VERSION >= VERSION_NTSC_1_0
	filelists_tick();
#endif

	menu_push_dialog(&g_FilemgrSelectLocationMenuDialog);
}

#if VERSION >= VERSION_JPN_FINAL
bool filemgr_is_file_in_use(struct filelistfile *file)
{
	s32 i;

	if (menu_is_dialog_open(&g_FilemgrCopyMenuDialog)
			&& file->fileid == g_FilemgrFileToCopy.fileid
			&& file->deviceserial == g_FilemgrFileToCopy.deviceserial) {
		return true;
	}

	if (menu_is_dialog_open(&g_FilemgrFileSelect4MbMenuDialog)) {
		return false;
	}

	if (g_MenuData.root == MENUROOT_FILEMGR) {
		return false;
	}

	if (file->fileid == g_GameFileGuid.fileid && file->deviceserial == g_GameFileGuid.deviceserial) {
		return true;
	}

	if (file->fileid == g_MpSetup.fileguid.fileid && file->deviceserial == g_MpSetup.fileguid.deviceserial) {
		return true;
	}

	// JPN adds this loop
	for (i = 0; i < ARRAYCOUNT(g_Menus); i++) {
		if (i != g_MpPlayerNum
				&& g_Menus[i].curdialog
				&& g_Menus[i].curdialog->definition == &g_FilemgrConfirmDeleteMenuDialog
				&& file->fileid == g_FilemgrFileToDelete[i].fileid
				&& file->deviceserial == g_FilemgrFileToDelete[i].deviceserial) {
			return true;
		}
	}

	for (i = 0; i < MAX_PLAYERS; i++) {
		if ((g_MpSetup.chrslots & (1 << i))
				&& g_PlayerConfigsArray[i].fileguid.fileid == file->fileid
				&& g_PlayerConfigsArray[i].fileguid.deviceserial == file->deviceserial) {
			return true;
		}
	}

	return false;
}
#endif

MenuItemHandlerResult filemgr_confirm_delete_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
#if VERSION >= VERSION_JPN_FINAL
		struct filelistfile file;
		file.fileid = g_FilemgrFileToDelete[g_MpPlayerNum].fileid;
		file.deviceserial = g_FilemgrFileToDelete[g_MpPlayerNum].deviceserial;

		menu_pop_dialog();

		if (filemgr_is_file_in_use(&file)) {
			filemgr_push_error_dialog(FILEERROR_DELETEFAILED);
		} else {
			filemgr_delete_current_file();
		}
#else
		menu_pop_dialog();
		filemgr_delete_current_file();
#endif
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
char *filemgr_menu_text_file_in_use_description(struct menuitem *item)
{
	if (menu_is_dialog_open(&g_FilemgrCopyMenuDialog)) {
		return lang_get(L_MPWEAPONS_240); // "The file you are copying cannot be deleted."
	}

	return lang_get(L_MPWEAPONS_160); // "Cannot delete file as it is being used."
}
#endif

/**
 * This is a dirty decomp hack where we intentionally declare
 * an incorrect function signature in order to get a match.
 * phead_get_texture uses u16 as its last argument
 * but filemgr_render_perfect_head_thumbnail will only match if
 * it's an s32 with a 0xffff mask.
 */
struct textureconfig *phead_get_texture(s32 playernum, s32 fileid, s32 deviceserial);

Gfx *filemgr_render_perfect_head_thumbnail(Gfx *gdl, struct menuitemrenderdata *renderdata, s32 fileid, s32 deviceserial)
{
	struct textureconfig *texture = phead_get_texture(g_MpPlayerNum, fileid, deviceserial & 0xffff);

	if (texture) {
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061360);

		gDPPipeSync(gdl++);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);

		tex_select(&gdl, texture, 1, 0, 2, 1, NULL);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetTextureFilter(gdl++, G_TF_POINT);
		gDPSetEnvColor(gdl++, 0xff, 0xff, 0xff, renderdata->colour);

		gDPSetCombineLERP(gdl++,
				TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0);

		gDPLoadSync(gdl++);
		gDPTileSync(gdl++);

		gSPTextureRectangle(gdl++,
				((renderdata->x + 4) << 2) * g_UiScaleX,
				(renderdata->y + 2) << 2,
				((renderdata->x + 20) << 2) * g_UiScaleX,
				(renderdata->y + 18) << 2,
				G_TX_RENDERTILE, 0, 512, 1024 / g_UiScaleX, -1024);

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
bool filemgr_is_file_in_use(struct filelistfile *file)
{
	s32 i;

#if VERSION >= VERSION_NTSC_1_0
	if (menu_is_dialog_open(&g_FilemgrCopyMenuDialog)
			&& file->fileid == g_FilemgrFileToCopy.fileid
			&& file->deviceserial == g_FilemgrFileToCopy.deviceserial) {
		return true;
	}

	if (menu_is_dialog_open(&g_FilemgrFileSelect4MbMenuDialog)) {
		return false;
	}
#else
	if (g_MenuData.root == MENUROOT_FILEMGR
			&& menu_is_dialog_open(&g_FilemgrCopyMenuDialog)
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

	for (i = 0; i < MAX_PLAYERS; i++) {
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
MenuItemHandlerResult filemgr_file_to_copy_or_delete_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data, bool isdelete)
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
	case MENUOP_GETSELECTEDINDEX:
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
				gdl = filemgr_render_perfect_head_thumbnail(gdl, renderdata, file->fileid, file->deviceserial);
			} else {
				u32 colour = renderdata->colour;
				char text[32];

				if (isdelete && filemgr_is_file_in_use(file)) {
					colour = 0xff333300 | (colour & 0xff);
				}

				x = renderdata->x + 2;
				y = renderdata->y + 2;

				gdl = text_begin(gdl);

				if (file) {
					filemgr_get_select_name(text, file, g_Menus[g_MpPlayerNum].fm.filetypeplusone - 1);
					gdl = text_render_v2(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm,
							colour, vi_get_width(), vi_get_height(), 0, 1);
					y = renderdata->y + 12;
					x = renderdata->x + 2;
				}

				gdl = text_end(gdl);
			}

			return (uintptr_t) gdl;
		}
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = 11;
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = list->numdevices;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return filemgr_get_device_name_or_start_index(listnum, operation, data->list.value);
	case MENUOP_GETGROUPSTARTINDEX:
		data->list.groupstartindex = filemgr_get_device_name_or_start_index(listnum, operation, data->list.value);
		return 0;
	}

	return 0;
}

MenuItemHandlerResult filemgr_file_to_delete_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum] == NULL) {
		return 0;
	}

	if (operation == MENUOP_SET) {
		struct filelistfile *file = &g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->files[data->list.value];

		if (file) {
			if (filemgr_is_file_in_use(file)) {
				filemgr_set_file_to_delete(file, g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->filetype);
				menu_push_dialog(&g_FilemgrFileInUseMenuDialog);
			} else {
				filemgr_set_file_to_delete(file, g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum]->filetype);
#if VERSION >= VERSION_JPN_FINAL
				g_FilemgrFileToDelete[g_MpPlayerNum].fileid = file->fileid;
				g_FilemgrFileToDelete[g_MpPlayerNum].deviceserial = file->deviceserial;
#else
				g_FilemgrFileToDelete.fileid = file->fileid;
				g_FilemgrFileToDelete.deviceserial = file->deviceserial;
#endif
				menu_push_dialog(&g_FilemgrConfirmDeleteMenuDialog);
			}
		}
	}

	return filemgr_file_to_copy_or_delete_list_menu_handler(operation, item, data, true);
}

MenuItemHandlerResult filemgr_file_to_copy_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
			filemgr_get_file_name(g_Menus[g_MpPlayerNum].fm.filename, file);
#endif
			filemgr_push_select_location_dialog(g_Menus[g_MpPlayerNum].fm.filetypeplusone, g_Menus[g_MpPlayerNum].fm.filetypeplusone - 1);
		}
	}

	return filemgr_file_to_copy_or_delete_list_menu_handler(operation, item, data, false);
}

MenuDialogHandlerResult filemgr_copy_or_delete_list_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_CLOSE) {
		if (g_Menus[g_MpPlayerNum].fm.isdeletingforsave == true) {
			g_Menus[g_MpPlayerNum].fm.isdeletingforsave = false;
		} else {
			filelist_create(0, FILETYPE_GAME);
			g_Menus[g_MpPlayerNum].fm.filetypeplusone = 0;
		}
	}

	return 0;
}

void filemgr_push_delete_file_dialog(s32 listnum)
{
	struct filelist *list;

	g_Menus[g_MpPlayerNum].fm.listnum = listnum;
	g_Menus[g_MpPlayerNum].fm.isdeletingforsave = false;
	g_Menus[g_MpPlayerNum].fm.filetypeplusone = 1;

	list = g_FileLists[g_Menus[g_MpPlayerNum].fm.listnum];

	if (list) {
		g_Menus[g_MpPlayerNum].fm.filetypeplusone = list->filetype + 1;
	}

	menu_push_dialog(&g_FilemgrDeleteMenuDialog);
}

MenuItemHandlerResult pak_delete_game_note_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		OSPfsState *note = &g_EditingPak->notes[g_Menus[g_MpPlayerNum].fm.noteindex];
		s32 result;

		g_Menus[g_MpPlayerNum].fm.unke24 = g_Menus[g_MpPlayerNum].fm.unke24 | (1 << g_Menus[g_MpPlayerNum].fm.device);

		menu_pop_dialog();

		result = pak_delete_game_note(g_Menus[g_MpPlayerNum].fm.device,
				note->company_code, note->game_code, note->game_name, note->ext_name);

		g_Menus[g_MpPlayerNum].fm.device1 = g_Menus[g_MpPlayerNum].fm.device;

		if (result != PAK_ERR1_OK) {
			filemgr_push_error_dialog(FILEERROR_DELETENOTEFAILED);
		}
	}

	return 0;
}

/**
 * Handler for the note listing in the controller pak menu.
 */
MenuItemHandlerResult pak_game_note_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
	case MENUOP_GETSELECTEDINDEX:
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
		gdl = text_render_v2(gdl, &x, &y, generalbuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
				renderdata->colour, vi_get_width(), vi_get_height(), 0, 1);

		// Prepare buffers for remaining text
		if (g_EditingPak->notesinuse[data->list.unk04] == 1) {
			pak_n64_font_code_to_ascii(note->game_name, tmpname, 16);
			pak_n64_font_code_to_ascii(note->ext_name, tmpext, 4);

			tmpext[1] = '\0';

			sprintf(generalbuffer, "%s\n", tmpname);
			sprintf(extbuffer, "%s\n", tmpext);
			sprintf(pagesbuffer, "%d\n", note->file_size / 256);
		} else {
			sprintf(generalbuffer, lang_get(L_OPTIONS_392)); // "Empty"
			sprintf(pagesbuffer, lang_get(L_OPTIONS_393)); // "--"
			sprintf(extbuffer, "", tmpname, tmpext);
		}

		// Render note name
		x = renderdata->x + 20;
		y = renderdata->y + 1;
		gdl = text_render_v2(gdl, &x, &y, generalbuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
				renderdata->colour, vi_get_width(), vi_get_height(), 0, 1);

		// Render ext character (for when a game has multiple notes)
		x = renderdata->x + (VERSION == VERSION_JPN_FINAL ? 220 : 190);
		y = renderdata->y + 1;
		gdl = text_render_v2(gdl, &x, &y, extbuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
				renderdata->colour, vi_get_width(), vi_get_height(), 0, 1);

		// Render number of pages
		text_measure(&textheight, &textwidth, pagesbuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

		x = renderdata->x + renderdata->width - textwidth - 6;
		y = renderdata->y + 1;
		gdl = text_render_v2(gdl, &x, &y, pagesbuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
				renderdata->colour, vi_get_width(), vi_get_height(), 0, 1);

		return (uintptr_t) gdl;
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = VERSION == VERSION_JPN_FINAL ? LINEHEIGHT - 1 : LINEHEIGHT;
		break;
	case MENUOP_SET:
		if (g_EditingPak->notesinuse[data->list.value] == true) {
			g_Menus[g_MpPlayerNum].fm.noteindex = data->list.value;
			menu_push_dialog(&g_PakDeleteNoteMenuDialog);
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
MenuDialogHandlerResult pak_game_notes_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curdialog
				&& g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef) {
			PakErr1 ret = pak0f1168c4(g_Menus[g_MpPlayerNum].fm.device, &g_EditingPak);

			if (ret != PAK_ERR1_OK) {
				menu_close_dialog();
				g_EditingPak = NULL;
				g_Menus[g_MpPlayerNum].fm.device1 = g_Menus[g_MpPlayerNum].fm.device;

				if (ret == PAK_ERR1_NOPAK) {
					filemgr_push_error_dialog(FILEERROR_PAKREMOVED);
				}

				menu_update_cur_frame();
			}
		}
	}

	return 0;
}

char *pak_menu_text_pages_free(struct menuitem *item)
{
	if (g_EditingPak == NULL) {
		sprintf(g_StringPointer, lang_get(L_OPTIONS_394)); // "Pages Free: "
	} else {
		sprintf(g_StringPointer, lang_get(L_OPTIONS_395), g_EditingPak->pagesfree); // "Pages Free: %d"
	}

	return g_StringPointer;
}

char *pak_menu_text_pages_used(struct menuitem *item)
{
	if (g_EditingPak == NULL) {
		sprintf(g_StringPointer2, lang_get(L_OPTIONS_396)); // "Pages Used: "
	} else {
		sprintf(g_StringPointer2, lang_get(L_OPTIONS_397), g_EditingPak->pagesused); // "Pages Used: %d"
	}

	return g_StringPointer2;
}

char *pak_menu_text_status_message(struct menuitem *item)
{
	ubool haspdnote = false;
	ubool hasemptynote = false;
	s32 i;

	if (g_EditingPak == NULL) {
		return lang_get(L_OPTIONS_398); // "Perfect Dark note already exists on this Controller Pak."
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
		return lang_get(L_OPTIONS_398); // "Perfect Dark note already exists on this Controller Pak."
	}

	if (g_EditingPak->pagesfree < 28 || !hasemptynote) {
		return lang_get(L_OPTIONS_400); // "Controller Pak is too full to save note- 1 note and 28 pages required to save to Controller Pak."
	}

	return lang_get(L_OPTIONS_399); // "There is enough space for Perfect Dark note."
}

/**
 * Title for the note listing dialog.
 */
char *pak_menu_text_editing_pak_name(struct menuitem *item)
{
	return filemgr_get_device_name(g_Menus[g_MpPlayerNum].fm.device);
}

/**
 * A pak selection on the controller pak menu.
 *
 * Selecting one takes you to the note listing dialog.
 */
MenuItemHandlerResult pak_selection_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if (!mempak_is_okay((s8)item->param)) {
			return true;
		}
	}

	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].fm.device = item->param;
		menu_push_dialog(&g_PakGameNotesMenuDialog);
	}

	return 0;
}

/**
 * Controller pak menu.
 *
 * Lists the connected controller paks.
 */
MenuDialogHandlerResult pak_choose_pak_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
#if VERSION >= VERSION_NTSC_1_0
	switch (operation) {
	case MENUOP_OPEN:
		joy_set_pfs_poll_interval(3);
		g_Menus[g_MpPlayerNum].fm.unke24 = 0;
		break;
	case MENUOP_TICK:
		var80062944 = 1;
		break;
	case MENUOP_CLOSE:
		if (g_Vars.stagenum != STAGE_BOOTPAKMENU) {
			s32 i;

			for (i = 0; i < MAX_PLAYERS; i++) {
				if (g_Menus[g_MpPlayerNum].fm.unke24 & (1 << i)) {
					g_Vars.pakstocheck &= 0xfff0;
					g_Vars.pakstocheck |= 0x0008;
					g_Vars.pakstocheck |= 1 << (i + 8);
				}
			}
		}
		joy_set_default_pfs_poll_interval();
		break;
	}
#else
	switch (operation) {
	case MENUOP_OPEN:
		joy_set_pfs_poll_interval(3);
		joy_set_pfs_poll_interval(-1);
		g_Menus[g_MpPlayerNum].fm.unke24 = 0;
		break;
	case MENUOP_TICK:
		var80062944 = 1;
		break;
	case MENUOP_CLOSE:
		{
			s32 i;

			for (i = 0; i < MAX_PLAYERS; i++) {
				if (g_Menus[g_MpPlayerNum].fm.unke24 & (1 << i)) {
					pak0f1169c8(i, STAGE_BOOTPAKMENU == g_Vars.stagenum);
				}
			}
		}
		joy_set_default_pfs_poll_interval();
		pak0f1189d0();
		break;
	}
#endif

	return 0;
}

MenuItemHandlerResult filemgr_open_copy_file_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].fm.filetypeplusone = item->param + 1;
		filelist_create(0, item->param);

#if VERSION >= VERSION_NTSC_1_0
		g_Menus[g_MpPlayerNum].fm.listnum = 0;
#endif
		g_Menus[g_MpPlayerNum].fm.isdeletingforsave = false;

		menu_push_dialog(&g_FilemgrCopyMenuDialog);
	}

	return 0;
}

MenuItemHandlerResult filemgr_open_delete_file_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].fm.filetypeplusone = item->param + 1;
		filelist_create(0, item->param);
		g_Menus[g_MpPlayerNum].fm.unke3e = -1;
		filemgr_push_delete_file_dialog(0);
	}

	return 0;
}

MenuItemHandlerResult filemgr_agent_name_keyboard_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
		filemgr_push_select_location_dialog(0, FILETYPE_GAME);
		g_Menus[g_MpPlayerNum].fm.unke2c = 1;
		break;
	}

	return 0;
}

MenuItemHandlerResult filemgr_choose_agent_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data)
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
	case MENUOP_GETSELECTEDINDEX:
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
		texturenum = TEX_GENERAL_NEWAGENT;
		file = NULL;
		renderdata = data->type19.renderdata2;
		seconds = 0;
		minutes = 0;
		hours = 0;
		days = 0;

		if (data->list.unk04 != g_FileLists[0]->numfiles) {
			file = &g_FileLists[0]->files[data->list.unk04];

			if (file) {
				gamefile_get_overview(file->name, name, &stage, &difficulty, &time);

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

				texturenum += stage;

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

		tex_select(&gdl, &g_TexGeneralConfigs[texturenum], 2, 0, 2, 1, NULL);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetTextureFilter(gdl++, G_TF_POINT);
		gDPSetEnvColor(gdl++, 0xff, 0xff, 0xff, renderdata->colour);
		gDPSetCombineLERP(gdl++,
				TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0,
				TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0);

		gSPTextureRectangle(gdl++,
				((renderdata->x + 4) << 2) * g_UiScaleX,
				(renderdata->y + 2) << 2,
				((renderdata->x + 60) << 2) * g_UiScaleX,
				(renderdata->y + 38) << 2,
				G_TX_RENDERTILE, 0, 1152, 1024 / g_UiScaleX, -1024);

		x = renderdata->x + 62;
		y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 3 : 4);
		gdl = text_begin(gdl);

		if (data->list.unk04 == g_FileLists[0]->numfiles) {
			// "New Agent..."
			gdl = text_render_v2(gdl, &x, &y, lang_get(L_OPTIONS_403),
					g_CharsHandelGothicMd, g_FontHandelGothicMd, renderdata->colour, vi_get_width(), vi_get_height(), 0, 0);
		} else if (file) {
			// Render file name
			gdl = text_render_v2(gdl, &x, &y, name,
					g_CharsHandelGothicMd, g_FontHandelGothicMd, renderdata->colour, vi_get_width(), vi_get_height(), 0, 1);

			// Prepare and render stage name
			y = renderdata->y + (VERSION == VERSION_JPN_FINAL ? 16 : 18);
			x = renderdata->x + 62;

			if (stage > 0) {
				sprintf(buffer, "%s %s",
						lang_get(g_SoloStages[stage - 1].name1),
						lang_get(g_SoloStages[stage - 1].name2));
			} else {
				// "New Recruit"
				strcpy(buffer, lang_get(L_OPTIONS_404));
			}

			strcat(buffer, "\n");
			gdl = text_render_v2(gdl, &x, &y, buffer,
					g_CharsHandelGothicSm, g_FontHandelGothicSm, renderdata->colour, vi_get_width(), vi_get_height(), 0, 0);

			// Prepare and render mission time
			x = renderdata->x + 62;
			y++;

#if VERSION == VERSION_JPN_FINAL
			x -= 3;
#endif

			if (days > 0) {
				// "Mission Time:"
				sprintf(buffer, "%s %d:%02d:%02d", lang_get(L_OPTIONS_405), days, hours, minutes);
			} else {
				// "Mission Time:"
				sprintf(buffer, "%s %02d:%02d", lang_get(L_OPTIONS_405), hours, minutes);
			}

			// Useless - textwidth and textheight are not used
#if VERSION >= VERSION_JPN_FINAL
			text_measure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, -1);
#else
			text_measure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
#endif

			gdl = text_render_v2(gdl, &x, &y, buffer,
					g_CharsHandelGothicSm, g_FontHandelGothicSm, renderdata->colour, vi_get_width(), vi_get_height(), 0, 0);

			// Render seconds part of mission time (uses a smaller font)
			y += (VERSION == VERSION_JPN_FINAL) ? 3 : 1;
			x++;
			sprintf(buffer, ".%02d", seconds);
			gdl = text_render_v2(gdl, &x, &y, buffer,
					g_CharsHandelGothicXs, g_FontHandelGothicXs, renderdata->colour, vi_get_width(), vi_get_height(), 0, 0);
		}
		gdl = text_end(gdl);
		return (uintptr_t) gdl;
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = 40;
		break;
	case MENUOP_SET:
		if (data->list.value == g_FileLists[0]->numfiles) {
			// New agent
			gamefile_load_defaults(&g_GameFile);
			menu_push_dialog(&g_FilemgrEnterNameMenuDialog);
		} else {
			struct filelistfile *file = &g_FileLists[0]->files[data->list.value];

			if (file) {
				g_GameFileGuid.fileid = file->fileid;
				g_GameFileGuid.deviceserial = file->deviceserial;
				filemgr_save_or_load(&g_GameFileGuid, FILEOP_LOAD_GAME, 0);
			}
		}
		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = g_FileLists[0]->numdevices + 1;
		break;
	case MENUOP_GETOPTGROUPTEXT:
		if (data->list.value >= g_FileLists[0]->numdevices) {
			return (uintptr_t) lang_get(L_OPTIONS_402); // "New..."
		}
		return filemgr_get_device_name_or_start_index(0, operation, data->list.value);
	case MENUOP_GETGROUPSTARTINDEX:
		if (data->list.value >= g_FileLists[0]->numdevices) {
			data->list.groupstartindex = g_FileLists[0]->numfiles;
		} else {
			data->list.groupstartindex = filemgr_get_device_name_or_start_index(0, operation, data->list.value);
		}
		return 0;
	}

	return 0;
}

MenuDialogHandlerResult filemgr_main_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	s32 i;

	switch (operation) {
	case MENUOP_OPEN:
		g_Menus[g_MpPlayerNum].fm.filetypeplusone = 0;

		filelist_create(0, FILETYPE_GAME);
		mp_init();

		// Set MP player names to "Player 1" through 4 if blank
		for (i = 0; i < MAX_PLAYERS; i++) {
			if (g_PlayerConfigsArray[i].base.name[0] == '\0') {
				sprintf(g_PlayerConfigsArray[i].base.name, "%s %d\n", lang_get(L_MISC_437), i + 1);
			}
		}
		break;
	case MENUOP_CLOSE:
		func0f110bf8();
		break;
#if VERSION < VERSION_NTSC_1_0
	case MENUOP_TICK:
		filelists_tick();
		break;
#endif
	}

	return 0;
}

bool filemgr_consider_pushing_file_select_dialog(void)
{
	if (g_Menus[g_MpPlayerNum].openinhibit == 0) {
		g_Menus[g_MpPlayerNum].playernum = 0;
		menu_push_root_dialog(&g_FilemgrFileSelectMenuDialog, MENUROOT_FILEMGR);

#if PAL
		if (g_Vars.language >= 6) {
			menu_push_dialog(&g_ChooseLanguageMenuDialog);
		}
#endif

		return true;
	}

	return false;
}

void bootmenu_reset(void)
{
	s32 prevplayernum = g_MpPlayerNum;
	g_MpPlayerNum = 0;
	menu_push_root_dialog(&g_PakChoosePakMenuDialog, MENUROOT_BOOTPAKMGR);
	g_MpPlayerNum = prevplayernum;
}

struct menuitem g_FilemgrSelectLocationMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_OPTIONS_368, // "Where"
		L_OPTIONS_369, // "Spaces"
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		SAVEDEVICE_GAMEPAK,
		0,
		(uintptr_t)&filemgr_menu_text_location_name2,
		(uintptr_t)&filemgr_menu_text_save_location_spaces,
		filemgr_select_location_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		SAVEDEVICE_CONTROLLERPAK1,
		0,
		(uintptr_t)&filemgr_menu_text_location_name2,
		(uintptr_t)&filemgr_menu_text_save_location_spaces,
		filemgr_select_location_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		SAVEDEVICE_CONTROLLERPAK2,
		0,
		(uintptr_t)&filemgr_menu_text_location_name2,
		(uintptr_t)&filemgr_menu_text_save_location_spaces,
		filemgr_select_location_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		SAVEDEVICE_CONTROLLERPAK3,
		0,
		(uintptr_t)&filemgr_menu_text_location_name2,
		(uintptr_t)&filemgr_menu_text_save_location_spaces,
		filemgr_select_location_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		SAVEDEVICE_CONTROLLERPAK4,
		0,
		(uintptr_t)&filemgr_menu_text_location_name2,
		(uintptr_t)&filemgr_menu_text_save_location_spaces,
		filemgr_select_location_menu_handler,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_OPTIONS_370, // "Delete Files..."
		0,
		filemgr_delete_files_for_save_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_OPTIONS_371, // "Cancel"
		0,
		filemgr_cancel_save_menu_handler,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE,
		(uintptr_t)&filemgr_menu_text_delete_file_name,
		0,
		filemgr_file_name_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_SMALLFONT,
		(uintptr_t)&filemgr_menu_text_device_name,
		0,
		filemgr_device_name_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_OPTIONS_380, // "Are you sure you want to delete this file?"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_381, // "Cancel"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_382, // "OK"
		0,
		filemgr_confirm_delete_menu_handler,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE,
		(uintptr_t)&filemgr_menu_text_delete_file_name,
		0,
		filemgr_file_name_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_SMALLFONT,
		(uintptr_t)&filemgr_menu_text_device_name,
		0,
		filemgr_device_name_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
#if VERSION >= VERSION_NTSC_1_0
		(uintptr_t)&filemgr_menu_text_file_in_use_description,
#else
		0x54a0,
#endif
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_161, // "Cancel"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_DARKERBG,
		L_OPTIONS_377, // "Select a file to delete:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LIST,
		1,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		0,
		0,
		filemgr_file_to_delete_list_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_DARKERBG,
		L_OPTIONS_378, // "Press B Button to exit."
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_FilemgrDeleteMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_376, // "Delete File"
	g_FilemgrDeleteMenuItems,
	filemgr_copy_or_delete_list_menu_dialog,
	0,
	NULL,
};

struct menuitem g_FilemgrCopyMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_DARKERBG,
		L_OPTIONS_374, // "Select a file to copy:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LIST,
		0,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		0,
		0,
		filemgr_file_to_copy_list_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_DARKERBG,
		L_OPTIONS_375, // "Press B Button to exit."
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_FilemgrCopyMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_373, // "Copy File"
	g_FilemgrCopyMenuItems,
	filemgr_copy_or_delete_list_menu_dialog,
	0,
	NULL,
};

struct pakdata *g_EditingPak = NULL;

struct menuitem g_PakDeleteNoteMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_OPTIONS_384, // "Are you sure you want to delete this game note?"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_385, // "No"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_386, // "Yes"
		0,
		pak_delete_game_note_menu_handler,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_OPTIONS_388, // "Delete Game Notes:"
		(uintptr_t)&pak_menu_text_editing_pak_name,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x0000010e,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_OPTIONS_389, // "Note"
		L_OPTIONS_390, // "Pages"
		NULL,
	},
	{
		MENUITEMTYPE_LIST,
		0,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		0x000000c8,
		0x0000006e,
		pak_game_note_list_menu_handler,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		(uintptr_t)&pak_menu_text_pages_free,
		(uintptr_t)&pak_menu_text_pages_used,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		(uintptr_t)&pak_menu_text_status_message,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_391, // "Press the B Button to exit."
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_PakGameNotesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_387, // "Game Notes"
	g_PakGameNotesMenuItems,
	pak_game_notes_menu_dialog,
	0,
	NULL,
};

struct menuitem g_PakChoosePakMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_OPTIONS_108, // "Use this menu to delete game notes from your Controller Paks."
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_OPTIONS_109, // "Choose Controller Pak to Edit:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_OPTIONS_112, // "Controller Pak 1"
		0,
		pak_selection_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		1,
		0,
		L_OPTIONS_113, // "Controller Pak 2"
		0,
		pak_selection_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		2,
		0,
		L_OPTIONS_114, // "Controller Pak 3"
		0,
		pak_selection_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		3,
		0,
		L_OPTIONS_115, // "Controller Pak 4"
		0,
		pak_selection_menu_handler,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_OPTIONS_110, // "Exit"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_PakChoosePakMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_107, // "Controller Pak Menu"
	g_PakChoosePakMenuItems,
	pak_choose_pak_menu_dialog,
	0,
	NULL,
};

struct menuitem g_FilemgrOperationsMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_DARKERBG,
		L_OPTIONS_100, // "Copy:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		FILETYPE_GAME,
		0,
		L_OPTIONS_103, // "Single Player Agent File"
		0,
		filemgr_open_copy_file_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		FILETYPE_MPSETUP,
		0,
		L_OPTIONS_104, // "Combat Simulator Settings File"
		0,
		filemgr_open_copy_file_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		FILETYPE_MPPLAYER,
		0,
		L_OPTIONS_105, // "Combat Simulator Player File"
		0,
		filemgr_open_copy_file_menu_handler,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_DARKERBG,
		L_OPTIONS_101, // "Delete:"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		FILETYPE_GAME,
		0,
		L_OPTIONS_103, // "Single Player Agent File"
		0,
		filemgr_open_delete_file_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		FILETYPE_MPSETUP,
		0,
		L_OPTIONS_104, // "Combat Simulator Settings File"
		0,
		filemgr_open_delete_file_menu_handler,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		FILETYPE_MPPLAYER,
		0,
		L_OPTIONS_105, // "Combat Simulator Player File"
		0,
		filemgr_open_delete_file_menu_handler,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_OPTIONS_102, // "Delete Game Notes..."
		0,
		(void *)&g_PakChoosePakMenuDialog,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_KEYBOARD,
		0,
		0,
		0,
		0x00000001,
		filemgr_agent_name_keyboard_menu_handler,
	},
	{ MENUITEMTYPE_END },
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
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_DARKERBG,
		L_OPTIONS_096, // "Choose Your Reality"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LIST,
		0,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		0x000000f5,
		0,
		filemgr_choose_agent_list_menu_handler,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_FilemgrFileSelectMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS_095, // "Perfect Dark"
	g_FilemgrFileSelectMenuItems,
	filemgr_main_menu_dialog,
	MENUDIALOGFLAG_IGNOREBACK,
	&g_FilemgrOperationsMenuDialog,
};
