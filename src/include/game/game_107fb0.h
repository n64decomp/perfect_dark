#ifndef IN_GAME_GAME_107FB0_H
#define IN_GAME_GAME_107FB0_H
#include <ultra64.h>
#include "types.h"

char *filemanGetDeviceName(s32 index);
char *filemanMenuTextDeviceName(struct menuitem *item);
void func0f1080d0(char *buffer, struct savelocation000 *arg1, u32 arg2);
char *filemanMenuTextDeleteFileName(struct menuitem *item);
void func0f108324(s32 arg0);
void func0f1083b0(struct savelocation000 *arg0);
void func0f1083d0(struct savelocation000 *arg0, s32 filetype);
char *filemanMenuTextFailReason(struct menuitem *item);
char *filemanMenuTextDeviceNameForError(struct menuitem *item);
void filemanPushErrorDialog(u16 errno);
s32 func0f1086b8(s32 arg0, s32 arg1, s32 arg2);
char *filemanMenuTextErrorTitle(struct menuitem *item);
char *filemanMenuTextFileType(struct menuitem *item);
void func0f10898c(void);
void func0f108a80(void);
void filemanEraseCorruptFile(void);
char *filemanMenuTextInsertOriginalPak(struct menuitem *item);
void func0f109038(s32 arg0);
bool fileSave(s32 arg0, bool arg1);
bool func0f1094e4(struct savelocation_2d8 *arg0, s32 arg1, void *arg2);
void filemanDeleteFile(void);
void func0f1097d0(s32 device);
void func0f109954(s32 arg0);
void func0f1099a8(char *buffer, struct savelocation000 *arg1);
void func0f109a68(char *buffer);
void func0f109bb4(char *name);
bool func0f109c8c(s32 arg0);
void func0f109ec4(void);
char *filemanMenuTextDeviceNameContainingDuplicateFile(struct menuitem *item);
char *filemanMenuTextDuplicateFileName(struct menuitem *item);
char *filemanMenuTextLocationName2(struct menuitem *item);
char *filemanMenuTextSaveLocationSpaces(struct menuitem *item);
void func0f10a51c(s32 arg0, u32 arg1);
char *filemanMenuTextFileInUseDescription(struct menuitem *item);
Gfx *filemanRenderPerfectHeadThumbnail(Gfx *gdl, struct menuitemrenderdata *renderdata, u32 arg2, u32 arg3);
bool func0f10a97c(struct savelocation000 *arg0);
s32 filemanFileToCopyOrDeleteListMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data, bool isdelete);
void filemanPushDeleteFileDialog(u32 arg0);
char *pakMenuTextPagesFree(struct menuitem *item);
char *pakMenuTextPagesUsed(struct menuitem *item);
char *pakMenuTextStatusMessage(struct menuitem *item);
char *pakMenuTextEditingPakName(struct menuitem *item);
bool filemanConsiderPushingFileSelectDialog(void);
void pakPushPakMenuDialog(void);
s32 fileListChooseAgentMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 pakGameNoteListMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanFileToCopyListMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanFileToDeleteListMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanInsertOriginalPakMenuDialog(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 filemanCopyOrDeleteListMenuDialog(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 pakGameNotesMenuDialog(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 pakChoosePakMenuDialog(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 filemanMainMenuDialog(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 filemanDeviceNameMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanFileNameMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanDeviceNameForErrorMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanRetrySaveMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanCancelSave2MenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanAcknowledgeFileLostMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanReinsertedOkMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanReinsertedCancelMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanDuplicateRenameMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanDuplicateCancelMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanCancelSaveMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanDeleteFilesForSaveMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanConfirmDeleteMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 pakDeleteGameNoteMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 pakSelectionMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanAgentNameKeyboardMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanOpenCopyFileMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanOpenDeleteFileMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanConfirmRenameMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanSaveElsewhereYesMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 filemanSelectLocationMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);

extern const char var7f1b3214[];
extern const char var7f1b3218[];
extern const char var7f1b321c[];
extern const char var7f1b3220[];

#endif
