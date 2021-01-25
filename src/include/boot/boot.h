#ifndef _IN_BOOT_H
#define _IN_BOOT_H
#include <ultra64.h>

s32 func000010a4(void);
s32 func0000113c(void);
s32 func00001180(void);
s32 func000016cc(void);
s32 osGetMemSize(void);
void *allocateStack(s32 threadid, s32 size);
void func00001b28(u32 arg0);
s32 func00001e30(void);
s32 func00001fa8(void);
s32 func00002078(OSSched *sc);
void __scHandleRSP(OSSched *sc);
void __scHandleRetrace(OSSched *sc);
void __scAppendList(OSSched *sc, OSScTask *t);
void __scExec(OSSched *sc, OSScTask *sp, OSScTask *dp);
void __scMain(void *arg);
struct bootbufferthing *func0000244c(void);
void func00002400(void);
void func000024e8(void);
void func00002510(void);

#endif
