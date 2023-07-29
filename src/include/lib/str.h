#ifndef _IN_LIB_STR_H
#define _IN_LIB_STR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

#ifdef PLATFORM_N64
char *strcpy(char *dst, const char *src);
char *strncpy(char *dst, const char *src, s32 len);
char *strcat(char *dst, const char *src);
s32 strcmp(const char *s1, const char *s2);
s32 strncmp(const char *s1, const char *s2, s32 len);
char toupper(char c);
s32 isdigit(char c);
s32 isalpha(char c);
s32 isspace(char c);
s32 strtol(const char *src, const char **endptr, s32 base);
#else
#include <string.h>
#include <ctype.h>
#endif

#endif
