#ifndef _IN_LIB_LIB_317F0_H
#define _IN_LIB_LIB_317F0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void sndpSetAddRefCallback(void *fn);
void sndpSetRemoveRefCallback(void *fn);
s32 sndGetState(struct sndstate *handle);
struct sndstate *func00033820(s32 arg0, s16 soundnum, u16 vol, ALPan pan, f32 pitch, u8 fxmix, u8 fxbus, struct sndstate **handleptr);
void audioStop(struct sndstate *handle);
void func00033db0(void);
void func00033dd8(void);
void audioPostEvent(struct sndstate *handle, s16 type, s32 data);
u16 func00033ec4(u8 index);
struct sndstate *sndpGetHeadState(void);
ALMicroTime sndpGetCurTime(void);
void func00033f44(u8 index, u16 volume);

#endif
