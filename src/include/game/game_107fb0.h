#ifndef IN_GAME_GAME_107FB0_H
#define IN_GAME_GAME_107FB0_H
#include <ultra64.h>
#include "types.h"

char *getSaveLocationName(s32 index);
char *pakMenuTextLocationName(struct menuitem *item);
void func0f1080d0(char *buffer, struct savelocation000 *arg1, u32 arg2);
char *func0f1082b0(struct menuitem *item);
void func0f108324(s32 arg0);
u32 func0f1083b0(void);
void func0f1083d0(struct savelocation000 *arg0, s32 arg1);
char *pakMenuTextFailReason(struct menuitem *item);
char *pakMenuTextDeviceNameForError(struct menuitem *item);
void func0f10865c(u16 arg0);
char *func0f1086b8(s32 arg0, s32 arg1, s32 arg2);
u32 func0f10876c(void);
char *pakMenuTextFileType(struct menuitem *item);
void func0f10898c(void);
u32 func0f108a80(void);
void func0f108d8c(void);
char *pakMenuTextPleaseInsertOriginalPak(struct menuitem *item);
void func0f109038(s32 arg0);
u32 func0f1091e0(void);
bool func0f1094e4(struct savelocation_2d8 *arg0, s32 arg1, void *arg2);
void pakDeleteFile(void);
void func0f1097d0(s32 device);
void func0f109954(s32 arg0);
void func0f1099a8(char *buffer, struct savelocation000 *arg1);
void func0f109a68(char *buffer);
void func0f109bb4(char *name);
u32 func0f109c8c(void);
void func0f109ec4(void);
char *pakMenuTextDeviceNameContainingDuplicateFile(struct menuitem *item);
char *pakMenuTextDuplicateFilename(struct menuitem *item);
char *pakMenuTextLocationName2(struct menuitem *item);
char *pakMenuTextSaveLocationSpaces(struct menuitem *item);
void func0f10a51c(s32 arg0, u32 arg1);
char *pakMenuTextDeleteErrorDescription(struct menuitem *item);
u32 func0f10a630(void);
bool func0f10a97c(struct savelocation000 *arg0);
s32 func0f10aad8(u32 operation, struct menuitem *item, union handlerdata *data, u32 arg3);
void func0f10b0c4(u32 arg0);
char *pakMenuTextPagesFree(struct menuitem *item);
char *pakMenuTextPagesUsed(struct menuitem *item);
char *pakMenuTextStatusMessage(struct menuitem *item);
char *pakMenuTextEditingPakName(struct menuitem *item);
bool pakConsiderPushingFileSelectMenuDialog(void);
void pakPushPakMenuDialog(void);
s32 menucustomChooseAgent(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menucustomDeleteGameNote(u32 operation, struct menuitem *item, union handlerdata *data);
s32 pakListFileToCopyMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 pakListFileToDeleteMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menudialog00108e58(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menudialog0010b014(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 pakGameNotesMenuDialog(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 pakControllerPakMenuMenuDialog(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 fileSelectMenuDialog(u32 operation, struct menudialog *dialog, union handlerdata *data);
s32 menuhandler00108014(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler00108254(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler001084b8(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerPakErrorTryAgain(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerPakCancelSave2(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAcknowledgePakFileLost(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler00108ecc(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler00108f08(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerPakRenameDuplicateSave(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerPakCancelDuplicateSave(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerPakCancelSave(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerDeleteFiles(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerPakConfirmDelete(u32 operation, struct menuitem *item, union handlerdata *data);
s32 pakDeleteGameNoteMenuHandler(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerPakSelection(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerAgentName(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerOpenCopyFile(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerOpenDeleteFile(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerRenameFile(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerSaveElsewhere(u32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerSaveLocation(u32 operation, struct menuitem *item, union handlerdata *data);

extern const char var7f1b3214[];
extern const char var7f1b3218[];
extern const char var7f1b321c[];
extern const char var7f1b3220[];

#endif
