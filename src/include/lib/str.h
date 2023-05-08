#ifndef _IN_LIB_STR_H
#define _IN_LIB_STR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

char *strcpy(char *dst, const char *src);
char *strncpy(char *dst, const char *src, s32 len);
char *strcat(char *dst, const char *src);
s32 strcmp(const char *s1, const char *s2);
s32 strncmp(const char *s1, const char *s2, s32 len);

#endif
