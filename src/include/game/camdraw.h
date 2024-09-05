#ifndef _IN_GAME_CAMDRAW_H
#define _IN_GAME_CAMDRAW_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void camdraw_init(void);
void camdraw_reset(void);
void camdraw_start_gbpaks(void);
void camdraw_stop_gbpaks(void);
s32 phead_get_unk3a4(s32 index);
s32 phead_get_unk3b8(void);
u16 editor_get_unk05c(s32 device);
s32 editor_get_unk060(s32 device);
bool editor_needs_gbpak(s32 device);
void func0f14aed0(s32 device);
void editor_stop_autocalibrate(void);
Gfx *func0f14f07c(Gfx *gdl, s32 headorbodynum, s32 x1, s32 y1, s32 x2, s32 y2);
bool camdraw_get_filemgr_preview(s8 device, s32 filenum, u8 *arg2);
void phead_get_guid(s32 index, struct fileguid *guid);
void camdraw_init_afterpaks(void);

extern const char var7f1b6050[];
extern const char var7f1b6058[];
extern const char var7f1b606c[];
extern const char var7f1b6080[];
extern const char var7f1b6088[];
extern const char var7f1b6090[];
extern const char var7f1b6098[];

#endif
