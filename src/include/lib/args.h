#ifndef _IN_LIB_ARGS_H
#define _IN_LIB_ARGS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void arg_set_string(char *string);
s32 args_parse_debug_args(void);
char *arg_find_by_prefix(s32 occurrence, char *string);
void arg_get_level(s32 *stagenum);

#endif
