#ifndef _IN_LIB_LIBC_XPRINTF_H
#define _IN_LIB_LIBC_XPRINTF_H
#include <ultra64.h>

typedef char *outfun(char*, const char*, size_t);
int _Printf(outfun prout, char *arg, const char *fmt, va_list args);

#endif
