#ifndef _IN_LIB_STR_H
#define _IN_LIB_STR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void strcpy(char *dst, const char *src);
void strncpy(char *dst, const char *src, s32 len);
void strcat(char *dst, const char *src);
s32 strcmp(const char *s1, const char *s2);

#endif
