#ifndef _IN_LIB_LIB_317F0_H
#define _IN_LIB_LIB_317F0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func00033090(struct sndstate *handle);
u32 func00033100(void);
u16 sndpCountStates(s16 *numfreeptr, s16 *numallocedptr);
void func00033378(void *fn);
struct sndstate *func00033390(s32 arg0, struct sndstate_08 *arg1);
void func00033634(void *fn);
bool audioIsPlaying(struct sndstate *handle);
struct sndstate *func00033820(s32 arg0, s16 soundnum, u16 arg2, u8 arg3, f32 arg4, u8 arg5, u8 arg6, struct sndstate **handleptr);
void audioStop(struct sndstate *handle);
void func00033bc0(struct sndstate *handle);
void func00033db0(void);
void func00033dd8(void);
void audioPostEvent(struct sndstate *handle, s16 type, s32 data);
u16 func00033ec4(u8 index);
struct sndstate *func00033f08(void);
ALMicroTime sndpGetCurTime(void);
void func00033f44(u8 index, u16 volume);

#endif
