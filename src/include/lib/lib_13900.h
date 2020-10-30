#ifndef _IN_LIB_LIB_13900_H
#define _IN_LIB_LIB_13900_H
#include <ultra64.h>
#include "types.h"

void func00013900(void);
void func00013938(void);
u32 func00013974(void);
u32 func00013980(void);
void func0001398c(u32 arg0);
void func000139c8(void);
u32 func000139e8(void);
u32 func00013a40(void);
void func00013ab8(u32 arg0);
u32 func00013c4c(void);
void func00013c94(void);
void func00013dd4(void);
void func00013dfc(void);
void func00013e84(void);
u32 contGetConnectedControllers(void);
u32 func00014058(void);
void func00014238(void);
void func000142f0(void);
s32 contStartReadData(OSMesgQueue *mq);
void contReadData(void);
void contPoll(void);
void func00014810(bool arg0);
s32 contGetNumSamples(void);
s32 func00014848(s32 samplenum, s8 contpadnum);
s32 func00014904(s32 samplenum, s8 contpadnum);
s32 func000149c0(s32 samplenum, s8 contpadnum);
u16 func00014a78(s32 samplenum, s8 contpadnum, u16 mask);
u16 func00014b50(s32 samplenum, s8 contpadnum, u16 mask);
s32 func00014c98(u32 *arg0, s8 contpadnum, u16 mask);
s8 contGetStickX(s8 contpadnum);
s8 contGetStickY(s8 contpadnum);
u16 contGetButtons(s8 contpadnum, u16 mask);
u16 func00015020(s8 contpadnum, u16 mask);
u32 func000150c4(void);
u32 func000150e8(void);
u32 func00015144(void);
u32 func0001519c(void);
u32 func000152d0(void);
u32 func000153c4(void);
bool func000155b4(u32 arg0);
u32 func000155f4(void);
u32 func0001561c(void);

#endif
