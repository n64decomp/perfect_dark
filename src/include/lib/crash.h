#ifndef _IN_LIB_CRASH_H
#define _IN_LIB_CRASH_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern const char var70052700[];
extern const char var70052704[];
extern const char var70052708[];
extern const char var7005270c[];
extern const char var70052710[];
extern const char var70052714[];
extern const char var70052718[];
extern const char var7005271c[];
extern const char var70052720[];
extern const char var70052724[];
extern const char var70052728[];
extern const char var70052730[];
extern const char var70052738[];
extern const char var70052744[];
extern const char var70052770[];
extern const char var70052788[];
extern const char var700527b4[];
extern const char var700527dc[];
extern const char var700527e4[];
extern const char var700527e8[];
extern const char var70052800[];
extern const char var70052810[];
extern const char var7005281c[];
extern const char var70052824[];
extern const char var70052854[];
extern const char var70052864[];
extern const char var70052870[];
extern const char var700528a0[];
extern const char var700528a4[];
extern const char var700528a8[];
extern const char var700528ac[];
extern const char var700528b0[];
extern const char var700528b4[];
extern const char var700528b8[];
extern const char var700528bc[];
extern const char var700528c0[];
extern const char var700528c4[];
extern const char var700528c8[];
extern const char var700528cc[];
extern const char var700528d0[];
extern const char var700528d4[];
extern const char var700528d8[];
extern const char var700528dc[];
extern const char var700528e0[];
extern const char var700528e4[];
extern const char var700528e8[];
extern const char var700528ec[];
extern const char var700528f0[];
extern const char var700528f4[];
extern const char var700528f8[];
extern const char var700528fc[];
extern const char var70052900[];
extern const char var70052904[];
extern const char var70052908[];
extern const char var7005290c[];
extern const char var70052910[];
extern const char var70052914[];
extern const char var70052918[];
extern const char var7005291c[];
extern const char var70052920[];
extern const char var70052924[];
extern const char var70052928[];
extern const char var70052938[];
extern const char var70052944[];
extern const char var70052950[];
extern const char var7005295c[];
extern const char var70052968[];
extern const char var70052974[];
extern const char var70052978[];
extern const char var7005297c[];
extern const char var70052980[];
extern const char var70052984[];
extern const char var70052988[];
extern const char var7005298c[];
extern const char var70052990[];
extern const char var70052994[];
extern const char var70052998[];
extern const char var7005299c[];
extern const char var700529a0[];
extern const char var700529a4[];
extern const char var700529a8[];
extern const char var700529ac[];

#if VERSION == VERSION_NTSC_BETA
extern u8 g_CrashHasMessage;
#else
extern bool g_CrashEnabled;
#endif

void crashSetMessage(char *string);
void crashCreateThread(void);
u32 crashGetParentStackFrame(u32 *ptr, u32 *start, u32 sp, u32 *regs);
bool crashIsReturnAddress(u32 *instruction);
u32 crashGetStackEnd(u32 sp, s32 tid);
u32 crashGetStackStart(u32 arg0, s32 tid);
bool crashIsDouble(f32 value);
void crashPrintFloat(s32 index, f32 arg1);
void crashPrint2Floats(s32 index, f32 value1, f32 value2);
void crashPrint3Floats(s32 index, f32 value1, f32 value2, f32 value3);
void crashPutChar(s32 x, s32 y, char c);
void crashAppendChar(char c);
void crashScroll(s32 numlines);
void crashRenderChar(s32 x, s32 y, char c);
void crashReset(void);
void crashRenderFrame(u16 *fb);

#endif
