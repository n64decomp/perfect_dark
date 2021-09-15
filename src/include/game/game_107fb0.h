#ifndef IN_GAME_GAME_107FB0_H
#define IN_GAME_GAME_107FB0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

char *filemgrGetDeviceName(s32 index);
char *filemgrMenuTextDeviceName(struct menuitem *item);
void filemgrGetSelectName(char *buffer, struct filelistfile *file, u32 filetype);
char *filemgrMenuTextDeleteFileName(struct menuitem *item);
void func0f108324(s32 deviceserial);
void func0f1083b0(struct filelistfile *file);
void func0f1083d0(struct filelistfile *file, s32 filetype);
char *filemgrMenuTextFailReason(struct menuitem *item);
char *filemgrMenuTextDeviceNameForError(struct menuitem *item);
void filemgrPushErrorDialog(u16 errno);
s32 filemgrGetDeviceNameOrStartIndex(s32 listnum, s32 operation, s32 optionindex);
char *filemgrMenuTextErrorTitle(struct menuitem *item);
char *filemgrMenuTextFileType(struct menuitem *item);
void func0f10898c(void);
void filemgrHandleSuccess(void);
void filemgrEraseCorruptFile(void);
char *filemgrMenuTextInsertOriginalPak(struct menuitem *item);
void filemgrRetrySave(s32 arg0);
bool filemgrAttemptOperation(s32 device, bool closeonsuccess);
bool func0f1094e4(struct fileguid *guid, s32 fileop, void *arg2);
void filemgrDeleteCurrentFile(void);
void func0f1097d0(s32 device);
void func0f109954(s32 arg0);
void filemgrGetFileName(char *dst, struct filelistfile *file);
void filemgrGetRenameName(char *buffer);
void filemgrSetRenameName(char *name);
bool filemgrIsNameAvailable(s32 arg0);
void func0f109ec4(void);
char *filemgrMenuTextDeviceNameContainingDuplicateFile(struct menuitem *item);
char *filemgrMenuTextDuplicateFileName(struct menuitem *item);
char *filemgrMenuTextLocationName2(struct menuitem *item);
char *filemgrMenuTextSaveLocationSpaces(struct menuitem *item);
void filemgrPushSelectLocationDialog(s32 arg0, u32 filetype);
char *filemgrMenuTextFileInUseDescription(struct menuitem *item);
Gfx *filemgrRenderPerfectHeadThumbnail(Gfx *gdl, struct menuitemrenderdata *renderdata, s32 filenum, s32 deviceserial);
bool filemgrIsFileInUse(struct filelistfile *file);
s32 filemgrFileToCopyOrDeleteListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data, bool isdelete);
void filemgrPushDeleteFileDialog(s32 listnum);
char *pakMenuTextPagesFree(struct menuitem *item);
char *pakMenuTextPagesUsed(struct menuitem *item);
char *pakMenuTextStatusMessage(struct menuitem *item);
char *pakMenuTextEditingPakName(struct menuitem *item);
bool filemgrConsiderPushingFileSelectDialog(void);
void pakPushPakMenuDialog(void);
s32 filemgrChooseAgentListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 pakGameNoteListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrFileToCopyListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrFileToDeleteListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrInsertOriginalPakMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 filemgrCopyOrDeleteListMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 pakGameNotesMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 pakChoosePakMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 filemgrMainMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data);
s32 filemgrDeviceNameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrFileNameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrDeviceNameForErrorMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrRetrySaveMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrCancelSave2MenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrAcknowledgeFileLostMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrReinsertedOkMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrReinsertedCancelMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrDuplicateRenameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrDuplicateCancelMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrCancelSaveMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrDeleteFilesForSaveMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrConfirmDeleteMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 pakDeleteGameNoteMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 pakSelectionMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrAgentNameKeyboardMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrOpenCopyFileMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrOpenDeleteFileMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrConfirmRenameMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrSaveElsewhereYesMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrSelectLocationMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);

extern const char var7f1b3214[];
extern const char var7f1b3218[];
extern const char var7f1b321c[];
extern const char var7f1b3220[];

#endif
