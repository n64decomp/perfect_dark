#ifndef _IN_LIB_MP3_INTERNAL_H
#define _IN_LIB_MP3_INTERNAL_H
#include <ultra64.h>
#include "mp3.h"

bool mp3decInit(void);
bool mp3decSetSideInfo(struct asistream *stream);
bool mp3decDecodeFrame(struct asistream *stream);

s32 mp3main00043dd0(struct asistream *stream);

f32 func00045ed0(f32 arg0, f32 arg1);

s32 mp3utilGetBits(u8 *buffer, s32 *count, s32 numbits);
s32 mp3util000462f8(u8 *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 **arg6, u8 **arg7);
s32 mp3util000464a8(u8 *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s16 **arg5, u8 **arg6);

void func00046650(struct asistream_4f64 *arg0, s32 arg1, struct asistream_4f64 *arg2, struct asistream_4f64 *arg3, void *arg4);

void func00047550(struct asistream_4f64 *arg0, s32 arg1, struct asistream_4f64 *arg2, struct asistream_4f64 *arg3);

f32 func00047d20(f32 arg0);

f32 func00047ef0(f32 arg0);

#endif
