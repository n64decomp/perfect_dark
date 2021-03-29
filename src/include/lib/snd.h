#ifndef _IN_LIB_SND_H
#define _IN_LIB_SND_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool sndIsFiltered(s32 audioid);
u32 snd0000e9d0(void);
u16 snd0000e9dc(void);
void sndSetSfxVolume(u16 volume);
u32 snd0000ea80(void);
void snd0000eadc(void);
void snd0000eb2c(void);
u32 snd0000ed14(void);
u32 snd0000ed68(void);
u32 snd0000ee88(void);
u32 snd0000efa8(void);
u32 snd0000f0d4(void);
u32 snd0000f228(void);
void sndSetSoundMode(s32 mode);
u32 snd0000f49c(void);
void snd0000f67c(struct var80094ed8 *arg0);
void sndInit(void);
bool snd0000fba0(s32 soundnum);
void snd0000fbc4(s16 arg0);
u32 snd0000fc48(void);
u32 snd0000fd74(void);
void snd0000fd9c(struct var80094ed8 *arg0, u16 volume);
void snd0000fe18(void);
void snd0000fe20(void);
void snd0000fe50(void);
void sndTick(void);
u32 snd00010360(void);
u32 snd0001036c(void);
void sndAdjust(struct audiohandle **handle, s32 arg1, s32 arg2, s32 speakerweight, s16 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8);
struct audiohandle *snd00010718(struct audiohandle **handle, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8);
struct audiohandle *sndStart(s32 arg0, s16 sound, struct audiohandle **handle, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7);
u32 snd00010ae4(void);
void sndPlayNosedive(s32 seconds);
void sndStopNosedive(void);
void sndTickNosedive(void);
void sndPlayUfoHum(s32 value);
void sndStopUfoHum(void);
u32 sndTickUfoHum(void);

#endif
