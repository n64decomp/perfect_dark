#ifndef _IN_BOOT_SCHED_H
#define _IN_BOOT_SCHED_H
#include <ultra64.h>

void func00001b28(u32 arg0);
void __scHandleRetraceViaPri(OSSched *sc, OSScTask *t);
void func00002078(OSSched *sc);
void __scHandleRSP(OSSched *sc);
void __scHandleRDP(OSSched *sc);
void __scHandleRetrace(OSSched *sc);
void __scAppendList(OSSched *sc, OSScTask *t);
void __scExec(OSSched *sc, OSScTask *sp, OSScTask *dp);
void __scMain(void *arg);
void __scYield(OSSched *sc);
struct bootbufferthing *bbufGetIndex0Buffer(void);
void bbufResetBuffers(void);
void bbufIncIndex0(void);
void bbufIncIndex1(void);
void bbufUpdateIndex2Buffer(void);
void func00002d90(void);

#endif
