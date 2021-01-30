#ifndef _IN_LIB_LIB_12DC0_H
#define _IN_LIB_LIB_12DC0_H
#include <ultra64.h>
#include "types.h"

void rngSetSeed(u32 amount);
u32 func00012e1c(u64 *value);
char *argParseString(char *str);
void func00012efc(char *string);
s32 func00012f30(void);
char *argFindByPrefix(s32 occurrence, char *string);
void argGetLevel(s32 *stagenum);
u32 random(void);

#endif
