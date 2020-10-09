#ifndef _IN_LIB_LIB_0D520_H
#define _IN_LIB_LIB_0D520_H
#include <ultra64.h>
#include "types.h"

u32 mainInit(void);
void mainEntry(void);
void func0000db30(char *string, u32 *ptr);
void mainLoop(void);
void mainTick(void);
void mainEndStage(void);
void mainSetStageNum(s32 stagenum);
void func0000e990(void);
void func0000e9c0(void);
s32 mainGetStageNum(void);

#endif
