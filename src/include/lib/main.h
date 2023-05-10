#ifndef _IN_LIB_MAIN_H
#define _IN_LIB_MAIN_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern s32 var8005dd18;
extern s32 g_StageNum;

void mainProc(void);
void mainEndStage(void);
void mainChangeToStage(s32 stagenum);
void func0000e990(void);
void func0000e9c0(void);

#endif
