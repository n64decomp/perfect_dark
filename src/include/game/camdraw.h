#ifndef _IN_GAME_CAMDRAW_H
#define _IN_GAME_CAMDRAW_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func0f149c90(struct var800a45a0_484 *arg0);
u32 func0f149d58(void);
void func0f149e58(u8 *arg0, u32 size);
void func0f14a00c(bool arg0);
struct var8007f8e0 *func0f14a06c(s32 index);
void func0f14a16c(s32 arg0);
char *phGetStyleName(s32 stylenum);
char *phGetColourName(s32 colournum);
struct var8007f8dc *func0f14a20c(void);
void func0f14a240(void);
bool func0f14a2fc(s32 index, u32 line, char *file);
void phAllocate(void);
void func0f14a3c4(void);
void func0f14a52c(void);
void func0f14a560(void);
void func0f14a594(s32 arg0);
s32 func0f14a5a4(void);
void func0f14a678(void);
bool func0f14a8e8(void);
void func0f14a95c(void);
s32 func0f14a984(void);
s32 func0f14a9f8(s32 index);
void func0f14aa48(void);
s32 func0f14aa70(void);
void func0f14aac4(void);
void func0f14ab3c(void);
u16 func0f14ad14(s32 device);
s32 func0f14ad38(s32 device);
void func0f14ad58(s32 index);
bool func0f14aea0(s32 device);
void func0f14aed0(s32 device);
void func0f14b178(void);
void func0f14b228(struct var8007f8e0 *arg0);
void func0f14b394(struct var8007f8e0 *arg0);
void func0f14b484(u32 arg0);
void func0f14bc04(void);
void func0f14bd34(s32 index);
void func0f14bdbc(s32 index);
void func0f14bec8(s32 index);
void func0f14c1cc(s32 index);
void func0f14c50c(struct var8007f8e0 *arg0, struct var8007f8e0 *arg1, u32 line, char *file);
void func0f14c75c(struct var800a45a0_484 *arg0, u8 **arg1);
u32 func0f14c7dc(void);
u32 func0f14c814(u8 **arg0);
Gfx *func0f14c870(Gfx *gdl, struct var800a45a0_484 *arg1, f32 *arg2, f32 arg3, f32 arg4);
u32 func0f14cdb8(void);
u32 func0f14cf6c(void);
void func0f14d064(s32 index, u8 *arg1);
void func0f14d2c8(u8 *arg0, u32 arg1);
void func0f14d4f0(u8 *arg0, u32 arg1);
void func0f14d714(u8 *arg0, u32 arg1);
u32 func0f14d84c(void);
u32 func0f14d8d8(void);
void func0f14dac0(u8 *arg0, u8 **arg1);
void func0f14dc30(s32 arg0, bool arg1);
void func0f14def0(s32 arg0, u32 line, char *file);
u32 func0f14dfc0(void);
void func0f14e1c4(struct var8007f8e0 *arg0);
u32 func0f14e4ac(void);
void func0f14e790(u8 *arg0);
void func0f14e7e0(u8 *arg0);
u32 func0f14e884(void);
void func0f14ec2c(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
u32 func0f14ecd8(void);
void func0f14eeb0(f32 *arg0);
void func0f14ef50(f32 *arg0);
s32 func0f14f008(s32 index);
Gfx *func0f14f07c(Gfx *gdl, s32 headorbodynum, s32 x1, s32 y1, s32 x2, s32 y2);
u32 func0f14f4b8(void);
u32 func0f14f4e4(void);
u32 func0f14f510(void);
u32 func0f14f700(void);
u32 func0f14f76c(void);
u32 func0f14f7d4(void);
u32 func0f14f8cc(void);
u32 func0f14f974(void);
u32 func0f14faf8(void);
u32 func0f14fbfc(void);
u32 func0f14fdb0(void);
void func0f14ff94(struct var8007f8e0 *arg0);
u32 func0f150068(void);
bool func0f15015c(s8 device, s32 filenum, u8 *arg2);
void phGetGuid(s32 index, struct fileguid *guid);

extern const char var7f1b6050[];
extern const char var7f1b6058[];
extern const char var7f1b606c[];
extern const char var7f1b6080[];
extern const char var7f1b6088[];
extern const char var7f1b6090[];
extern const char var7f1b6098[];

#endif
