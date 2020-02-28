#ifndef _IN_LIB_LIB_481E0_H
#define _IN_LIB_LIB_481E0_H
#include <ultra64.h>
#include "types.h"

u32 func000481e0(void);
void osStartThread(OSThread *thread);
void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msgBuf, s32 count);
void func00048370(s32 arg0);
void func00048430(s32 arg0, s32 arg1);
u32 func00048510(void);

#endif
