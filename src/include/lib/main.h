#ifndef _IN_LIB_MAIN_H
#define _IN_LIB_MAIN_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern s32 var8005dd18;

void mainInit(void);
void mainProc(void);
void func0000db30(char *string, void *ptr);
void mainLoop(void);
void mainTick(void);
void mainEndStage(void);
void mainSetStageNum(s32 stagenum);
void func0000e990(void);
void func0000e9c0(void);
s32 mainGetStageNum(void);

#endif
