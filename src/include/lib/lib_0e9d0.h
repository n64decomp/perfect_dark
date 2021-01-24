#ifndef _IN_LIB_LIB_0E9D0_H
#define _IN_LIB_LIB_0E9D0_H
#include <ultra64.h>
#include "types.h"

bool audioIsFiltered(s32 audioid);
u32 func0000e9d0(void);
u32 func0000e9dc(void);
void audioSetSfxVolume(u16 volume);
u32 func0000ea80(void);
void func0000eadc(void);
u32 func0000eb2c(void);
u32 func0000ed14(void);
u32 func0000ed68(void);
u32 func0000ee88(void);
u32 func0000efa8(void);
u32 func0000f0d4(void);
u32 func0000f228(void);
void audioSetSoundMode(u32 mode);
u32 func0000f49c(void);
u32 func0000f67c(void);
u32 func0000f804(void);
bool func0000fba0(s32 soundnum);
void func0000fbc4(s16 arg0);
u32 func0000fc48(void);
u32 func0000fd74(void);
void func0000fd9c(struct var80094ed8 *arg0, u16 volume);
void func0000fe18(void);
void func0000fe20(void);
void func0000fe50(void);
void func0000fe88(void);
u32 func00010360(void);
u32 func0001036c(void);
void audioAdjust(struct audiohandle **handle, u32 arg1, u32 arg2, s32 speakerweight, s16 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8);
struct audiohandle *func00010718(struct audiohandle **handle, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8);
s32 audioStart(s32 arg0, s16 sound, struct audiohandle **handle, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7);
u32 func00010ae4(void);
void envPlayNosedive(s32 room_id);
void envStopNosedive(void);
u32 func00010e10(void);
void envPlayUfoHum(s32 value);
void envStopUfoHum(void);
u32 func0001111c(void);

#endif
