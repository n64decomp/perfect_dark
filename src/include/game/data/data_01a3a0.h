#ifndef IN_GAME_DATA_01A3A0_H
#define IN_GAME_DATA_01A3A0_H
#include <ultra64.h>

extern struct menudialog g_FilemgrErrorMenuDialog;
extern u16 savelocations2[];
extern u16 iomessages2[];
extern u16 filetypenames[];
extern struct menudialog g_FilemgrFileSavedMenuDialog;
extern struct menudialog g_FilemgrSaveErrorMenuDialog;
extern struct menudialog g_FilemgrFileLostMenuDialog;
extern struct menudialog g_FilemgrSaveElsewhereMenuDialog;
extern struct menudialog g_FilemgrInsertOriginalPakMenuDialog;
extern u32 var8007464c;
extern struct menudialog g_FilemgrChangeFileNameMenuDialog;
extern struct menudialog g_FilemgrDuplicateFileNameMenuDialog;
extern u16 savelocations3[];
extern struct menudialog g_FilemgrSelectLocationMenuDialog;
extern struct menudialog g_FilemgrConfirmDeleteMenuDialog;
extern struct menudialog g_FilemgrFileInUseMenuDialog;
extern struct menudialog g_FilemgrDeleteFileMenuDialog;
extern struct menudialog g_FilemgrCopyListMenuDialog;
extern struct pakdata *g_EditingPak;
extern struct menudialog g_PakDeleteGameNoteMenuDialog;
extern struct menudialog g_PakGameNotesMenuDialog;
extern struct menudialog g_PakChoosePakMenuDialog;
extern struct menudialog g_FilemgrEnterAgentNameMenuDialog;
extern struct menudialog g_FilemgrMainMenuDialog;
extern struct menudialog menudialog_fileselect2;
extern struct menudialog menudialog_mpquickgo2;
extern struct menudialog menudialog_1b1bc;
extern struct menudialog g_4MbMainMenu;
extern struct menudialog menudialog_mpdropout;
extern struct menudialog g_MpEditSimulant4MbMenuDialog;
extern struct menudialog g_4MbAdvancedSetupMenuDialog;
extern struct filelist *g_FileLists[4];
extern bool var80075bd0[4];
extern u32 var80075be0;
extern struct var80075c00 var80075c00[];
extern struct coord var80075c30;
extern u32 var80075c3c;
extern u32 var80075c48;
extern u32 var80075c54;
extern u32 var80075c94;
extern u32 g_WaypointHashes[2];
extern char var80075cb4[];
extern char var80075cc0[];
extern u32 g_PakDebugForceScrub;
extern u32 g_PakDebugPakDump;
extern u32 g_PakDebugPakCache;
extern u32 g_PakDebugPakInit;
extern u32 g_PakDebugWipeEeprom;
extern u32 g_PakDebugCorruptMe;
extern char g_PakNoteGameName[16];
extern char g_PakNoteExtName[4];
extern u8 var80075d10;
extern u32 var80075d18;
extern u32 var80075d2c;
extern u32 var80075d40;
extern u32 g_PakDebugDumpEeprom;
extern s32 var80075d60;
extern u32 var80075d64;
extern u32 var80075d68;

#endif
