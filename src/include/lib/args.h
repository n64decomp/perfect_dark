#ifndef _IN_LIB_ARGS_H
#define _IN_LIB_ARGS_H
#include <ultra64.h>
#include "types.h"

char *argParseString(char *str);
void argSetString(char *string);
s32 argsParseDebugArgs(void);
char *argFindByPrefix(s32 occurrence, char *string);
void argGetLevel(s32 *stagenum);

#endif
