#ifndef _IN_LIB_STR_H
#define _IN_LIB_STR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

char *strcpy(char *dst, char *src);
char *strncpy(char *dst, char *s2, s32 len);
char *strcat(char *dst, char *src);
s32 strcmp(char *s1, char *s2);
s32 strncmp(char *s1, char *s2, s32 len);
char toupper(char c);
s32 isdigit(char c);
s32 isalpha(char c);
s32 isspace(char c);
s32 strtol(char *arg0, char **arg1, s32 arg2);

#endif
