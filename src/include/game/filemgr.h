#ifndef IN_GAME_FILEMGR_H
#define IN_GAME_FILEMGR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern struct menudialogdef g_ChooseLanguageMenuDialog;

char *filemgrMenuTextDeviceName(struct menuitem *item);
void filemgrGetSelectName(char *buffer, struct filelistfile *file, u32 filetype);
void filemgrSetDevice1BySerial(s32 deviceserial);
void filemgrPushErrorDialog(u16 errno);
s32 filemgrGetDeviceNameOrStartIndex(s32 listnum, s32 operation, s32 optionindex);
bool filemgrSaveOrLoad(struct fileguid *guid, s32 fileop, u32 playernum);
void filemgrPushSelectLocationDialog(s32 arg0, u32 filetype);
Gfx *filemgrRenderPerfectHeadThumbnail(Gfx *gdl, struct menuitemrenderdata *renderdata, s32 filenum, s32 deviceserial);
bool filemgrConsiderPushingFileSelectDialog(void);
void bootmenuReset(void);
s32 filemgrChooseAgentListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrMainMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
s32 filemgrOpenCopyFileMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 filemgrOpenDeleteFileMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);

extern const char var7f1b3214[];
extern const char var7f1b3218[];
extern const char var7f1b321c[];
extern const char var7f1b3220[];

#endif
