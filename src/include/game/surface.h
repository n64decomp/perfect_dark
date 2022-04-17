#ifndef IN_GAME_SURFACE_H
#define IN_GAME_SURFACE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void surfaceReset(void);

void surface0f173a08(void);
bool surface0f173a44(u32 value);
bool surface0f173a70(s32 index, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10);
bool surface0f173b8c(s32 index, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 texGetWidthAtLod(struct texloadthing *arg0, s32 lod);
s32 texGetHeightAtLod(struct texloadthing *arg0, s32 lod);
s32 tex0f173d60(struct texloadthing *arg0, s32 lod);
s32 tex0f173e10(struct texloadthing *arg0, s32 lod);
void surface0f173e50(struct texloadthing *arg0, s32 *arg1, s32 *arg2);
s32 surface0f173f18(s32 arg0);
u32 surface0f173f48(u32 arg0);
u32 surface0f173f78(void);
u32 surface0f1742e4(void);
u32 surface0f1743a0(void);
u32 surface0f1747a4(void);
u32 surface0f174b54(void);
u32 surface0f174f30(void);
u32 surface0f1751e4(void);
u32 surface0f175308(void);
u32 surface0f175490(void);
u32 surface0f1755dc(void);
u32 surface0f17563c(void);
s32 surface0f1756c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void surface0f175ef4(s32 arg0, s32 arg1, s32 arg2);

extern const char var7f1b7ba0[];
extern const char var7f1b7ba8[];
extern const char var7f1b7bb0[];
extern const char var7f1b7bb8[];
extern const char var7f1b7bc0[];
extern const char var7f1b7bc8[];
extern const char var7f1b7bd8[];
extern const char var7f1b7be0[];
extern const char var7f1b7be8[];
extern const char var7f1b7bec[];
extern const char var7f1b7bf4[];
extern const char var7f1b7c00[];
extern const char var7f1b7c04[];
extern const char var7f1b7c10[];
extern const char var7f1b7c18[];

#endif
