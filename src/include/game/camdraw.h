#ifndef _IN_GAME_CAMDRAW_H
#define _IN_GAME_CAMDRAW_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void phead_init(void);
void phead_reset(void);
void func0f14a52c(void);
void func0f14a560(void);
s32 func0f14a9f8(s32 index);
s32 func0f14aa70(void);
u16 func0f14ad14(s32 device);
s32 func0f14ad38(s32 device);
bool func0f14aea0(s32 device);
void func0f14aed0(s32 device);
void func0f14cf6c(void);
Gfx *func0f14f07c(Gfx *gdl, s32 headorbodynum, s32 x1, s32 y1, s32 x2, s32 y2);
bool func0f15015c(s8 device, s32 filenum, u8 *arg2);
void ph_get_guid(s32 index, struct fileguid *guid);
void phead_init2(void);

extern const char var7f1b6050[];
extern const char var7f1b6058[];
extern const char var7f1b606c[];
extern const char var7f1b6080[];
extern const char var7f1b6088[];
extern const char var7f1b6090[];
extern const char var7f1b6098[];

#endif
