#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/cheats.h"
#include "game/game_107fb0.h"
#include "game/game_10c9c0.h"
#include "game/game_10ccd0.h"
#include "game/pak/pak.h"
#include "game/utils.h"
#include "game/game_177e00.h"
#include "game/game_179060.h"
#include "game/game_17f930.h"
#include "game/game_1a3340.h"
#include "gvars/gvars.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "stagesetup.h"
#include "types.h"

// 1a3c0
struct menu_item menuitems_1a3c0[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&func0f108550, 0x00000000, menuhandler001084b8 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&func0f108424, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(321), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1a410
struct menu_dialog menudialog_1a410 = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(320), // "Error"
	menuitems_1a3c0,
	NULL,
	0x00000080,
	NULL,
};

// 1a428
u16 savelocations2[] = {
	L_OPTIONS(111), // "Game Pak"
	L_OPTIONS(112), // "Controller Pak 1"
	L_OPTIONS(113), // "Controller Pak 2"
	L_OPTIONS(114), // "Controller Pak 3"
	L_OPTIONS(115), // "Controller Pak 4"
	0x0000,
};

// 1a434
u16 iomessages2[] = {
	L_OPTIONS(331), // "Error Loading Game"
	L_OPTIONS(332), // "Error Saving Game"
	L_OPTIONS(333), // "Error Loading Player"
	L_OPTIONS(334), // "Error Saving Player"
	L_OPTIONS(335), // "Error Loading PerfectHead"
	L_OPTIONS(336), // "Error Saving PerfectHead"
	L_OPTIONS(337), // "Error Reading File"
	L_OPTIONS(338), // "Error Writing File"
	L_OPTIONS(339), // "Error"
	0x0000,
};

// 1a448
u16 filetypenames[] = {
	L_OPTIONS(103), // "Single Player Agent File"
	L_OPTIONS(104), // "Combat Simulator Settings File"
	L_OPTIONS(105), // "Combat Simulator Player File"
	L_OPTIONS(106), // "PerfectHead Files"
};

// 1a450
struct menu_item menuitems_filesaved[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(346), 0x00000000, NULL }, // "File Saved."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(347), 0x00000000, NULL }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1a48c
struct menu_dialog menudialog_filesaved = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS(345), // "Cool!"
	menuitems_filesaved,
	NULL,
	0x00000080,
	NULL,
};

// 1a4a4
struct menu_item menuitems_saveerror[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&func0f108078, 0x00000000, menuhandler00108014 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(348), 0x00000000, NULL }, // "An error occurred while trying to save"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(349), 0x00000000, menuhandlerPakErrorTryAgain }, // "Try Again"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(350), 0x00000000, menuhandlerSaveElsewhere }, // "Save Elsewhere"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(351), 0x00000000, menuhandlerPakCancelSave2 }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1a51c
struct menu_dialog menudialog_saveerror = {
	MENUDIALOGTYPE_DANGER,
	(u32)&func0f10876c,
	menuitems_saveerror,
	NULL,
	0x000000a0,
	NULL,
};

// 1a534
struct menu_item menuitems_savelost[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&func0f108078, 0x00000000, menuhandler00108014 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(251), 0x00000000, NULL }, // "The saved file has been erased due to corruption or damage."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(354), 0x00000000, menuhandlerAcknowledgePakFileLost }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1a584
struct menu_dialog menudialog_savelost = {
	MENUDIALOGTYPE_DANGER,
	(u32)&func0f10876c,
	menuitems_savelost,
	NULL,
	0x000000a0,
	NULL,
};

// 1a59c
struct menu_item menuitems_saveelsewhere[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(360), 0x00000000, NULL }, // "Would you like to save your file elsewhere?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(361), 0x00000000, menuhandlerSaveElsewhere }, // "Yes"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(362), 0x00000000, menuhandlerPakCancelSave2 }, // "No"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1a5ec
struct menu_dialog g_SaveElsewhereMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(359), // "Save"
	menuitems_saveelsewhere,
	NULL,
	0x000000a0,
	NULL,
};

// 1a604
struct menu_item menuitems_1a604[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&func0f108f90, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(365), 0x00000000, menuhandler00108ecc }, // "OK"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(366), 0x00000000, menuhandler00108f08 }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1a654
struct menu_dialog menudialog_1a654 = {
	MENUDIALOGTYPE_DANGER,
	(u32)&func0f10876c,
	menuitems_1a604,
	menudialog00108e58,
	0x000000a0,
	NULL,
};

u32 var8007464c = (u32)&var7f1b3214;
u32 var80074650 = (u32)&var7f1b3218;
u32 var80074654 = (u32)&var7f1b321c;
u32 var80074658 = (u32)&var7f1b3220;
u32 var8007465c = 0x01020304;
u32 var80074660 = 0x00000000;

// 1a684
struct menu_item menuitems_changefilename[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(239), 0x00000000, NULL }, // "Enter new file name:"
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandlerRenameFile },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1a6c0
struct menu_dialog menudialog_changefilename = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(238), // "Change File Name"
	menuitems_changefilename,
	NULL,
	0x00000080,
	NULL,
};

// 1a6d8
struct menu_item menuitems_duplicatefilename[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&func0f10a19c, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS(233), 0x00000000, NULL }, // "already contains"
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS(234), 0x00000000, NULL }, // "a file named"
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, (u32)&func0f10a1ec, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPWEAPONS(235), 0x00000000, menuhandlerPakRenameDuplicateSave }, // "Rename File"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPWEAPONS(236), 0x00000000, NULL }, // "Change Location"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPWEAPONS(237), 0x00000000, menuhandlerPakCancelDuplicateSave }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1a778
struct menu_dialog menudialog_duplicatefilename = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(232), // "Duplicate File Name"
	menuitems_duplicatefilename,
	NULL,
	0x00000080,
	NULL,
};

// 1a790
u16 savelocations3[] = {
	L_OPTIONS(112), // "Controller Pak 1"
	L_OPTIONS(113), // "Controller Pak 2"
	L_OPTIONS(114), // "Controller Pak 3"
	L_OPTIONS(115), // "Controller Pak 4"
	L_OPTIONS(111), // "Game Pak"
	L_OPTIONS(4), // ""
};

// 1a79c
struct menu_item menuitems_selectlocation[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(368), L_OPTIONS(369), NULL }, // "Where", "Spaces"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  4, 0x00000000, (u32)&func0f10a22c, (u32)&func0f10a2ec, menuhandlerSaveLocation },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, (u32)&func0f10a22c, (u32)&func0f10a2ec, menuhandlerSaveLocation },
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, (u32)&func0f10a22c, (u32)&func0f10a2ec, menuhandlerSaveLocation },
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, (u32)&func0f10a22c, (u32)&func0f10a2ec, menuhandlerSaveLocation },
	{ MENUITEMTYPE_SELECTABLE,  3, 0x00000000, (u32)&func0f10a22c, (u32)&func0f10a2ec, menuhandlerSaveLocation },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(370), 0x00000000, menuhandlerDeleteFiles }, // "Delete Files..."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(371), 0x00000000, menuhandlerPakCancelSave }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1a878
struct menu_dialog menudialog_selectlocation = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(367), // "Select Location"
	menuitems_selectlocation,
	NULL,
	0x00000080,
	NULL,
};

// 1a890
struct menu_item menuitems_confirmdelete[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&func0f1082b0, 0x00000000, menuhandler00108254 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000230, (u32)&func0f108078, 0x00000000, menuhandler00108014 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(380), 0x00000000, NULL }, // "Are you sure you want to delete this file?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(381), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(382), 0x00000000, menuhandlerPakConfirmDelete }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1a908
struct menu_dialog menudialog_confirmdelete = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(379), // "Warning"
	menuitems_confirmdelete,
	NULL,
	0x00000080,
	NULL,
};

// 1a920
struct menu_item menuitems_1a920[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&func0f1082b0, 0x00000000, menuhandler00108254 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000230, (u32)&func0f108078, 0x00000000, menuhandler00108014 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&func0f10a5e8, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS(161), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1a984
struct menu_dialog menudialog_1a984 = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(159), // "Error"
	menuitems_1a920,
	NULL,
	0x00000080,
	NULL,
};

// 1a99c
struct menu_item menuitems_deletefile[] = {
	{ MENUITEMTYPE_LABEL,       0, L_SEVXB(16), L_OPTIONS(377), 0x00000000, NULL }, // "Select a file to delete:"
	{ MENUITEMTYPE_CUSTOM,      1, 0x00200000, 0x00000000, 0x00000000, menucustomFileToDelete },
	{ MENUITEMTYPE_LABEL,       0, L_SEVXB(48), L_OPTIONS(378), 0x00000000, NULL }, // "Press B Button to exit."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1a9ec
struct menu_dialog menudialog_deletefile = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(376), // "Delete File"
	menuitems_deletefile,
	menudialog0010b014,
	0x00000000,
	NULL,
};

// 1aa04
struct menu_item menuitems_copyfile[] = {
	{ MENUITEMTYPE_LABEL,       0, L_SEVXB(16), L_OPTIONS(374), 0x00000000, NULL }, // "Select a file to copy:"
	{ MENUITEMTYPE_CUSTOM,      0, 0x00200000, 0x00000000, 0x00000000, menucustomFileToCopy },
	{ MENUITEMTYPE_LABEL,       0, L_SEVXB(48), L_OPTIONS(375), 0x00000000, NULL }, // "Press B Button to exit."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1aa54
struct menu_dialog menudialog_copyfile = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(373), // "Copy File"
	menuitems_copyfile,
	menudialog0010b014,
	0x00000000,
	NULL,
};

u32 var80074a4c = 0x00000000;

// 1aa70
struct menu_item menuitems_deletegamenote[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(384), 0x00000000, NULL }, // "Are you sure you want to delete this game note?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(385), 0x00000000, NULL }, // "No"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(386), 0x00000000, menuhandler0010b14c }, // "Yes"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1aac0
struct menu_dialog menudialog_deletegamenote = {
	MENUDIALOGTYPE_DANGER,
	0x577f,
	menuitems_deletegamenote,
	NULL,
	0x00000000,
	NULL,
};

// 1aad8
struct menu_item menuitems_gamenotes[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(388), (u32)&func0f10b924, NULL }, // "Delete Game Notes:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x0000010e, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(389), L_OPTIONS(390), NULL }, // "Note", "Pages"
	{ MENUITEMTYPE_CUSTOM,      0, 0x00200000, 0x000000c8, 0x0000006e, menucustomDeleteGameNote },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&func0f10b75c, (u32)&func0f10b7cc, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, (u32)&func0f10b83c, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, L_OPTIONS(391), 0x00000000, NULL }, // "Press the B Button to exit."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1ab78
struct menu_dialog menudialog_gamenotes = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(387), // "Game Notes"
	menuitems_gamenotes,
	menudialog0010b674,
	0x00000000,
	NULL,
};

// 1ab90
struct menu_item menuitems_controllerpakmenu[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(108), 0x00000000, NULL }, // "Use this menu to delete game notes from your Controller Pak"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_OPTIONS(109), 0x00000000, NULL }, // "Choose Controller Pak to Edit:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(112), 0x00000000, menuhandlerPakSelection }, // "Controller Pak 1"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS(113), 0x00000000, menuhandlerPakSelection }, // "Controller Pak 2"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS(114), 0x00000000, menuhandlerPakSelection }, // "Controller Pak 3"
	{ MENUITEMTYPE_SELECTABLE,  3, 0x00000000, L_OPTIONS(115), 0x00000000, menuhandlerPakSelection }, // "Controller Pak 4"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(110), 0x00000000, NULL }, // "Exit"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1ac58
struct menu_dialog menudialog_controllerpakmenu = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(107), // "Controller Pak Menu"
	menuitems_controllerpakmenu,
	menudialog0010ba10,
	0x00000000,
	NULL,
};

// 1ac70
struct menu_item menuitems_gamefiles[] = {
	{ MENUITEMTYPE_LABEL,       0, L_SEVXB(16), L_OPTIONS(100), 0x00000000, NULL }, // "Copy:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(103), 0x00000000, menuhandlerOpenCopyFile }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS(104), 0x00000000, menuhandlerOpenCopyFile }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS(105), 0x00000000, menuhandlerOpenCopyFile }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, L_SEVXB(16), L_OPTIONS(101), 0x00000000, NULL }, // "Delete:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(103), 0x00000000, menuhandlerOpenDeleteFile }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS(104), 0x00000000, menuhandlerOpenDeleteFile }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS(105), 0x00000000, menuhandlerOpenDeleteFile }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_OPTIONS(102), 0x00000000, &menudialog_controllerpakmenu }, // "Delete Game Notes..."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1ad60
struct menu_dialog menudialog_gamefiles = {
	MENUDIALOGTYPE_DEFAULT,
	0x5663,
	menuitems_gamefiles,
	NULL,
	0x00000020,
	NULL,
};

// 1ad78
struct menu_item menuitems_enteragentname[] = {
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000001, menuhandlerAgentName },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1ada0
struct menu_dialog menudialog_enteragentname = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(401), // "Enter Agent Name"
	menuitems_enteragentname,
	NULL,
	0x00000000,
	NULL,
};

// 1adb8
struct menu_item menuitems_fileselect[] = {
	{ MENUITEMTYPE_LABEL,       0, L_SEVXB(16), L_OPTIONS(96), 0x00000000, NULL }, // "Choose Your Reality"
	{ MENUITEMTYPE_CUSTOM,      0, 0x00200000, 0x000000f5, 0x00000000, menucustomChooseAgent },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1adf4
struct menu_dialog menudialog_fileselect = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(95), // "Perfect Dark"
	menuitems_fileselect,
	menudialog0010c804,
	0x00000020,
	&menudialog_gamefiles,
};

u32 var80074dec = 0x00000000;

// 1ae10
struct menu_item menuitems_gamefiles2[] = {
	{ MENUITEMTYPE_LABEL,       0, L_SEVXB(16), L_OPTIONS(100), 0x00000000, NULL }, // "Copy:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(103), 0x00000000, menuhandlerOpenCopyFile }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS(104), 0x00000000, menuhandlerOpenCopyFile }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS(105), 0x00000000, menuhandlerOpenCopyFile }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, L_SEVXB(16), L_OPTIONS(101), 0x00000000, NULL }, // "Delete:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(103), 0x00000000, menuhandlerOpenDeleteFile }, // "Single Player Agent File"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_OPTIONS(104), 0x00000000, menuhandlerOpenDeleteFile }, // "Combat Simulator Settings File"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_OPTIONS(105), 0x00000000, menuhandlerOpenDeleteFile }, // "Combat Simulator Player File"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_OPTIONS(102), 0x00000000, &menudialog_controllerpakmenu }, // "Delete Game Notes..."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1af00
struct menu_dialog menudialog_gamefiles2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(99), // "Game Files"
	menuitems_gamefiles2,
	NULL,
	0x00000020,
	NULL,
};

// 1af18
struct menu_item menuitems_fileselect2[] = {
	{ MENUITEMTYPE_LABEL,       0, L_SEVXB(16), L_OPTIONS(96), 0x00000000, NULL }, // "Choose Your Reality"
	{ MENUITEMTYPE_CUSTOM,      0, 0x00200000, 0x000000f5, 0x00000000, menucustomChooseAgent },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1af54
struct menu_dialog menudialog_fileselect2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(95), // "Perfect Dark"
	menuitems_fileselect2,
	menudialog0010c804,
	0x00000020,
	&menudialog_gamefiles2,
};

// 1af6c
struct menu_item menuitems_audiovisual[] = {
	{ MENUITEMTYPE_SLIDER,      0, L_LEN(0), L_OPTIONS(308), L_MPMENU(0), menuhandlerSfxVolume }, // "Sound"
	{ MENUITEMTYPE_SLIDER,      0, L_LEN(0), L_OPTIONS(309), L_MPMENU(0), menuhandlerMusicVolume }, // "Music"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_OPTIONS(310), 0x00000000, menuhandlerSoundMode }, // "Sound Mode"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_OPTIONS(311), 0x00000000, menuhandlerScreenRatio }, // "Ratio"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_OPTIONS(312), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b00c
struct menu_dialog menudialog_1b00c = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(307), // "Audio/Visual"
	menuitems_audiovisual,
	menudialog0010559c,
	0x00000000,
	NULL,
};

// 1b024
struct menu_item menuitems_mpplayersetup[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(30), (u32)&mpGetCurrentPlayerName, &menudialog_mpplayername }, // "Name"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(33), 0x00000000, &menudialog_mpcontrol }, // "Control"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(34), 0x00000000, &menudialog_mpoptions }, // "Player Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(35), 0x00000000, &menudialog_mpplayerstats }, // "Statistics"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, &menudialog_mploadplayer }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, (u32)&mpMenuTextSavePlayerOrCopy, 0x00000000, menuhandlerMpSavePlayer },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b0c4
struct menu_dialog menudialog_mpplayersetup = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(28), // "Player Setup"
	menuitems_mpplayersetup,
	NULL,
	0x00000800,
	&menudialog_mpchallengedetails,
};

struct menu_dialog menudialog_mpdropout;

// 1b0dc
struct menu_item menuitems_mpquickgo2[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(456), 0x00000000, &g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, &menudialog_mploadplayer }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(458), 0x00000000, &menudialog_mpplayersetup }, // "Player Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(457), 0x00000000, &menudialog_mpdropout }, // "Drop Out"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b140
struct menu_dialog menudialog_mpquickgo2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC(460), // "Quick Go"
	menuitems_mpquickgo2,
	menudialogMpQuickGo,
	0x00000000,
	NULL,
};

// 1b158
struct menu_item menuitems_1b158[] = {
	{ MENUITEMTYPE_SCROLLABLE,  1, 0x00000000, 0x0000007c, 0x00000037, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(57), 0x00000000, menuhandler0010cabc }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(58), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b1bc
struct menu_dialog menudialog_1b1bc = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	menuitems_1b158,
	menudialog0017e3fc,
	0x00000000,
	NULL,
};

// 1b1d4
struct menu_item menuitems_mpcombatchallenges[] = {
	{ MENUITEMTYPE_CUSTOM,      1, 0x00200000, 0x00000078, 0x0000004d, menuhandler0017e4d4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b1fc
struct menu_dialog menudialog_mpcombatchallenges = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(50), // "Combat Challenges"
	menuitems_mpcombatchallenges,
	menudialog0017eb34,
	0x00000000,
	NULL,
};

// 1b214
struct menu_item menuitems_smallbutperfectmenu[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(441), 0x00000000, &menudialog_mpcombatchallenges }, // "Challenges"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(442), 0x00000001, &menudialog_mploadgamesettingstype1 }, // "Load/Preset Games"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(443), 0x00000002, &menudialog_mpquickteam }, // "Quick Start"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC(444), 0x00000003, menuhandler4MbAdvancedSetup }, // "Advanced Setup"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_OPTIONS(305), 0x00000000, &menudialog_1b00c }, // "Audio/Video"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_OPTIONS(306), 0x00000000, &menudialog_changeagent }, // "Change Agent"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b2b4
struct menu_dialog g_4MbMainMenu = {
	MENUDIALOGTYPE_DEFAULT,
	L_OPTIONS(302), // "Small but Perfect Menu"
	menuitems_smallbutperfectmenu,
	menudialog4MbMainMenu,
	0x00000030,
	NULL,
};

// 1b2cc
struct menu_item menuitems_mpdropout[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(196), 0x00000000, NULL }, // "Are you sure you want to drop out?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(197), 0x00000000, menuhandler4MbDropOut }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(198), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b31c
struct menu_dialog menudialog_mpdropout = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(195), // "Drop Out"
	menuitems_mpdropout,
	NULL,
	0x00000000,
	NULL,
};

// 1b334
struct menu_item menuitems_mpabort[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(53), 0x00000000, NULL }, // "Are you sure you want to abort the game?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(54), 0x00000000, menuhandler0010ca1c }, // "Abort"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(55), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b384
struct menu_dialog menudialog_mpabort = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(52), // "Abort"
	menuitems_mpabort,
	NULL,
	0x00000000,
	NULL,
};

// 1b39c
struct menu_item menuitems_1b39c[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU(95), 0x00000000, menuhandlerMpSimulantDifficulty }, // "Difficulty:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(96), 0x00000000, menuhandlerMpChangeSimulantType }, // "Change Type..."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(98), 0x00000000, menuhandlerMpDeleteSimulant }, // "Delete Simulant"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(99), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b414
struct menu_dialog g_MpEditSimulant4MbMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17cfc0,
	menuitems_1b39c,
	menudialogMpSimulant,
	0x00000010,
	NULL,
};

// 1b42c
struct menu_item menuitems_mpgamesetup[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU(19), (u32)&mpMenuTextScenarioShortName, &menudialog_mpscenario }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(21), 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(20), (u32)&mpMenuTextArenaName, &menudialog_mparena }, // "Arena"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU(44), 0x00000000, menuhandlerMpLock }, // "Lock"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(23), 0x00000000, &menudialog_mpweapons }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(24), 0x00000000, &menudialog_mplimits }, // "Limits"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS(184), 0x00000000, &menudialog_mpplayerhandicaps }, // "Player Handicaps"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(25), 0x00000000, &menudialog_mpsimulants }, // "Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(22), 0x00000000, &menudialog_mpteamcontrol }, // "Teams"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(36), 0x00000000, &g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060004, L_MPMENU(18), 0x00000000, &menudialog_mploadgamesettingstype0 }, // "Load Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU(26), 0x00000000, menuhandlerMpSaveSettings }, // "Save Settings"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b558
struct menu_dialog g_4MbAdvancedSetupMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	0x5011,
	menuitems_mpgamesetup,
	menudialogMpGameSetup,
	0x00000810,
	&menudialog_mpplayersetup,
};

// 1b570
struct menu_item menuitems_1b570[] = {
	{ MENUITEMTYPE_OBJECTIVES,  1, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(298), 0x00000000, menuhandlerAcceptMission }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(299), 0x00000000, menuhandlerDeclineMission }, // "Decline"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b5c0
struct menu_dialog menudialog_1b5c0 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f10ce74,
	menuitems_1b570,
	menudialog0010cd0c,
	0x0000000c,
	&menudialog_briefing,
};

// 1b5d8
struct menu_item menuitems_promptnextmission[] = {
	{ MENUITEMTYPE_OBJECTIVES,  1, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(298), 0x00000000, menuhandlerAcceptMission }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_OPTIONS(299), 0x00000000, menuhandlerDeclineMission }, // "Decline"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MISC(470), 0x00000000, menuhandlerReplayPreviousMission }, // "Replay Previous Mission"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b650
struct menu_dialog menudialog_promptnextmission = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f10cf2c,
	menuitems_promptnextmission,
	menudialog0010cd0c,
	0x0000000c,
	&menudialog_briefing,
};

// 1b668
struct menu_item menuitems_1b668[] = {
	{ MENUITEMTYPE_OBJECTIVES,  2, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(301), 0x00000000, NULL }, // "Press START"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b6b8
struct menu_item menuitems_1b6b8[] = {
	{ MENUITEMTYPE_OBJECTIVES,  0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(301), 0x00000000, NULL }, // "Press START"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b708
struct menu_dialog menudialog_1b708 = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(300), // "Objectives"
	menuitems_1b6b8,
	menudialog001063e4,
	0x00000048,
	NULL,
};

// 1b720
struct menu_dialog menudialog_1b720 = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS(300), // "Objectives"
	menuitems_1b6b8,
	menudialog001063e4,
	0x00000048,
	NULL,
};

// 1b738
struct menu_dialog menudialog_1b738 = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(300), // "Objectives"
	menuitems_1b668,
	menudialog001063e4,
	0x00000048,
	NULL,
};

// 1b750
struct menu_dialog menudialog_1b750 = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS(300), // "Objectives"
	menuitems_1b668,
	menudialog001063e4,
	0x00000048,
	NULL,
};

// 1b768
struct menu_item menuitems_1b768[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS(244), 0x00000000, menuhandlerContinueMission }, // "Continue"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS(245), 0x00000000, menuhandlerReplayLastLevel }, // "Replay Last Level"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1b7a4
struct menu_dialog menudialog_1b7a4 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f10d61c,
	menuitems_1b768,
	NULL,
	0x00000004,
	NULL,
};

// 1b7bc
struct menu_item menuitems_1b7bc[] = {
	{ MENUITEMTYPE_LABEL,       0, L_AME(16), L_OPTIONS(278), 0x00000000, NULL }, // "Mission Status:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&soloMenuTextMissionStatus, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, L_AME(16), L_OPTIONS(279), 0x00000000, NULL }, // "Agent Status:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&soloMenuTextAgentStatus, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, L_AME(16), L_OPTIONS(280), 0x00000000, NULL }, // "Mission Time:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&soloMenuTextMissionTime, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, L_AME(16), L_MPWEAPONS(129), 0x00000000, NULL }, // "Difficulty"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)soloMenuTextDifficulty, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, L_AME(16), L_OPTIONS(281), 0x00000000, NULL }, // "Weapon of Choice:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextWeaponOfChoiceName, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(282), (u32)&soloMenuTextNumKills, NULL }, // "Kills:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(283), (u32)&soloMenuTextAccuracy, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(284), (u32)&soloMenuTextNumShots, NULL }, // "Shot Total:"
	{ MENUITEMTYPE_LABEL,       0, L_AME(0), L_OPTIONS(285), (u32)&soloMenuTextNumHeadShots, NULL }, // "Head Shots:"
	{ MENUITEMTYPE_LABEL,       0, L_AME(0), L_OPTIONS(286), (u32)&soloMenuTextNumBodyShots, NULL }, // "Body Shots:"
	{ MENUITEMTYPE_LABEL,       0, L_AME(0), L_OPTIONS(287), (u32)&soloMenuTextNumLimbShots, NULL }, // "Limb Shots:"
	{ MENUITEMTYPE_LABEL,       0, L_AME(0), L_OPTIONS(288), (u32)&soloMenuTextNumOtherShots, NULL }, // "Others:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(289), 0x00000000, NULL }, // "Press START"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

u32 var80075968 = 0xff7f7fff;

// 1b98c
struct menu_item menuitems_1b98c[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(278), (u32)&soloMenuTextMissionStatus, NULL }, // "Mission Status:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(279), (u32)&soloMenuTextAgentStatus, NULL }, // "Agent Status:"
	{ MENUITEMTYPE_LABEL,       0, 0x01000000, L_OPTIONS(280), (u32)&soloMenuTextMissionTime, menuhandler0010e064 }, // "Mission Time:"
	{ MENUITEMTYPE_LABEL,       1, 0x01000000, L_MPWEAPONS(242), (u32)&soloMenuTextTargetTime, menuhandler0010e064 }, // "Target Time:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPWEAPONS(129), (u32)&soloMenuTextDifficulty, NULL }, // "Difficulty:"
	{ MENUITEMTYPE_SEPARATOR,   2, 0x00000000, 0x00000000, 0x00000000, menuhandler0010e064 },
	{ MENUITEMTYPE_LABEL,       2, 0x00000000, L_MPWEAPONS(243), 0x00000000, menuhandler0010e064 }, // "New Cheat Available!:"
	{ MENUITEMTYPE_LABEL,       3, 0x01000020, (u32)&soloMenuTextCheatName, 0x00000000, menuhandler0010e064 },
	{ MENUITEMTYPE_LABEL,       5, 0x01000020, (u32)&soloMenuTextCheatName2, 0x00000000, menuhandler0010e064 },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(281), (u32)&mpMenuTextWeaponOfChoiceName, NULL }, // "Weapon of Choice"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(282), (u32)&soloMenuTextNumKills, NULL }, // "Kills:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(283), (u32)&soloMenuTextAccuracy, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(284), (u32)&soloMenuTextNumShots, NULL }, // "Shot Total:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(285), (u32)&soloMenuTextNumHeadShots, NULL }, // "Head Shots:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(286), (u32)&soloMenuTextNumBodyShots, NULL }, // "Body Shots:"
	{ MENUITEMTYPE_LABEL,       6, 0x00000000, L_OPTIONS(287), (u32)&soloMenuTextNumLimbShots, menuhandler0010e064 }, // "Limb Shots:"
	{ MENUITEMTYPE_LABEL,       4, 0x00000000, L_OPTIONS(288), (u32)&soloMenuTextNumOtherShots, menuhandler0010e064 }, // "Others:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_OPTIONS(289), 0x00000000, NULL }, // "Press START"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 1bb44
struct menu_dialog menudialog_1bb44 = {
	MENUDIALOGTYPE_SUCCESS,
	(u32)&func0f10d588,
	menuitems_1b98c,
	menudialog0010dd28,
	0x00000048,
	&menudialog_1b720,
};

// 1bb5c
struct menu_dialog menudialog_1bb5c = {
	MENUDIALOGTYPE_DANGER,
	(u32)&func0f10d678,
	menuitems_1b98c,
	menudialog0010de58,
	0x00000048,
	&menudialog_1b708,
};

// 1bb74
struct menu_dialog menudialog_1bb74 = {
	MENUDIALOGTYPE_SUCCESS,
	(u32)&func0f10d588,
	menuitems_1b98c,
	menudialog0010dd28,
	0x00000048,
	&menudialog_1b720,
};

// 1bb8c
struct menu_dialog menudialog_1bb8c = {
	MENUDIALOGTYPE_DANGER,
	(u32)&func0f10d678,
	menuitems_1b98c,
	menudialog0010de58,
	0x00000048,
	&menudialog_1b708,
};

// 1bba4
struct menu_dialog menudialog_1bba4 = {
	MENUDIALOGTYPE_SUCCESS,
	L_OPTIONS(276), // "Completed"
	menuitems_1b7bc,
	menudialog0010dd28,
	0x00000048,
	&menudialog_1b750,
};

// 1bbbc
struct menu_dialog menudialog_1bbbc = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS(277), // "Failed"
	menuitems_1b7bc,
	menudialog0010de58,
	0x00000048,
	&menudialog_1b738,
};

u32 var80075bb4 = 0x00000000;
u32 var80075bb8 = 0x00000000;
u32 var80075bbc = 0x00000000;

struct savelocation *g_SaveLocations[] = {NULL, NULL, NULL, NULL};

u32 var80075bd0 = 0x00000001;
u32 var80075bd4 = 0x00000001;
u32 var80075bd8 = 0x00000001;
u32 var80075bdc = 0x00000001;
u32 var80075be0 = 0x00000000;
u32 var80075be4 = 0x00000000;
u32 var80075be8 = 0x00000000;
u32 var80075bec = 0x00000000;
u32 var80075bf0 = 0x00000000;
u32 var80075bf4 = 0x00000000;
u32 var80075bf8 = 0x00000000;
u32 var80075bfc = 0x00000000;

struct var80075c00 var80075c00[] = {
	{ 43, 9.5, 27, 0, 0,   1.5 },
	{ 41, 7.5, 17, 0, 1.5, 100 },
};

u32 var80075c30 = 0x00000000;
u32 var80075c34 = 0x00000000;
u32 var80075c38 = 0x00000000;
u32 var80075c3c = 0x00000000;
u32 var80075c40 = 0x00000000;
u32 var80075c44 = 0x3f800000;
u32 var80075c48 = 0x00000000;
u32 var80075c4c = 0x3f800000;
u32 var80075c50 = 0x00000000;
u32 var80075c54 = 0x00000000;
u32 var80075c58 = 0x00000001;
u32 var80075c5c = 0x00000003;
u32 var80075c60 = 0x00000000;
u32 var80075c64 = 0x00000000;
u32 var80075c68 = 0x00000000;
u32 var80075c6c = 0x00000000;
u32 var80075c70 = 0x00000000;
u32 var80075c74 = 0x00000000;
u32 var80075c78 = 0x00000000;
u32 var80075c7c = 0x00000000;
u32 var80075c80 = 0x00000000;
u32 var80075c84 = 0x00000000;
u32 var80075c88 = 0x00000000;
u32 var80075c8c = 0x00000000;
u32 var80075c90 = 0x00000000;
u32 var80075c94 = 0x00000000;
u32 var80075c98 = 0x00000000;
u32 var80075c9c = 0x00000000;
s32 g_WaypointHashes[2] = {0};
u32 var80075ca8 = 0x00000000;
u32 var80075cac = 0x00000000;

char var80075cb0[] = "4Y";
char var80075cb4[] = "PerfDark";
char var80075cc0[] = "PerfDark";

u32 var80075ccc = 0x00000400;
u32 var80075cd0 = 0x00000000;
u32 var80075cd4 = 0x00000000;
u32 var80075cd8 = 0x00000000;
u32 var80075cdc = 0x00000000;
u32 var80075ce0 = 0x00000000;
u32 var80075ce4 = 0x00000000;
u32 var80075ce8 = 0x00000001;
u32 var80075cec = 0x00000000;
u32 var80075cf0 = 0x00000000;
u32 var80075cf4 = 0x00000000;
u32 var80075cf8 = 0x291e2b1f;
u32 var80075cfc = 0x1e1c2d0f;
u32 var80075d00 = 0x1d1a2b24;
u32 var80075d04 = 0x00000000;
u32 var80075d08 = 0x00000000;
u32 var80075d0c = 0x00000000;
u32 var80075d10 = 0x00000000;
u32 var80075d14 = 0x00000001;
u32 var80075d18 = 0x00000010;
u32 var80075d1c = 0x00000008;
u32 var80075d20 = 0x00000020;
u32 var80075d24 = 0x00000040;
u32 var80075d28 = 0x00000080;
u32 var80075d2c = 0x00000002;
u32 var80075d30 = 0x00000003;
u32 var80075d34 = 0x00000005;
u32 var80075d38 = 0x00000005;
u32 var80075d3c = 0x00000005;
u32 var80075d40 = (u32)&var7f1b423c;
u32 var80075d44 = (u32)&var7f1b4244;
u32 var80075d48 = (u32)&var7f1b424c;
u32 var80075d4c = (u32)&var7f1b4254;
u32 var80075d50 = (u32)&var7f1b425c;
u32 var80075d54 = 0x00000000;
u32 var80075d58 = 0x00000000;
u32 var80075d5c = 0x00000000;
u32 var80075d60 = 0x00000002;
u32 var80075d64 = 0x00000002;
u32 var80075d68 = 0x00000002;
u32 var80075d6c = 0x00000002;
u32 var80075d70 = 0x00000000;
u32 var80075d74 = 0x00000000;
u32 var80075d78 = 0x00000000;
u32 var80075d7c = 0x00000000;
u32 var80075d80 = 0x00000000;
u32 var80075d84 = 0x00000000;
u32 var80075d88 = 0x00000000;
u32 var80075d8c = 0x00000000;
u32 var80075d90 = 0x00000000;
u32 var80075d94 = 0xbf800000;
u32 var80075d98 = 0x00000000;
u32 var80075d9c = 0x3f800000;
u32 var80075da0 = 0x00000000;
u32 var80075da4 = 0x00000000;
u32 var80075da8 = 0x3f800000;
u32 var80075dac = 0x00000000;
u32 var80075db0 = 0x00000000;
u32 var80075db4 = 0x3f800000;
u32 var80075db8 = 0x00000000;
u32 var80075dbc = 0x00000000;
u32 var80075dc0 = 0x00000000;
u32 var80075dc4 = 0x00000000;
u32 var80075dc8 = 0x00000000;
u32 var80075dcc = 0x00000000;
u32 var80075dd0 = 0x00000000;
u32 var80075dd4 = 0x00000000;
u32 var80075dd8 = 0x3f800000;
u32 var80075ddc = 0x00000000;
