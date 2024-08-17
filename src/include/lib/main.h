#ifndef _IN_LIB_MAIN_H
#define _IN_LIB_MAIN_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern s32 g_MainIsBooting;

void main_init(void);
void main_proc(void);
void main_override_variable(char *name, void *value);
void main_loop(void);
void main_tick(void);
void main_end_stage(void);
void main_change_to_stage(s32 stagenum);
void func0000e990(void);
void func0000e9c0(void);
s32 main_get_stage_num(void);

#endif
