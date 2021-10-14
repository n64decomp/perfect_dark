#ifndef _XSTDIO_H
#define _XSTDIO_H
#include <ultratypes.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct
{
	union {
		/* 00 */ long long s64;
		double f64;
	} value;
	/* 08 */ char *buff;
	/* 0c */ int n0;
	/* 10 */ int num_leading_zeros;
	/* 14 */ int part2_len;
	/* 18 */ int num_mid_zeros;
	/* 1c */ int part3_len;
	/* 20 */ int num_trailing_zeros;
	/* 24 */ int precision;
	/* 28 */ int width;
	/* 2c */ unsigned int size;
	/* 30 */ unsigned int flags;
	/* 34 */ char length;
} printf_struct;

#define FLAGS_SPACE 1
#define FLAGS_PLUS 2
#define FLAGS_MINUS 4
#define FLAGS_HASH 8
#define FLAGS_ZERO 16
typedef char *outfun(char*,const char*,size_t);

int _Printf(outfun prout, char *arg, const char *fmt, va_list args);
void _Litob(printf_struct *args, char type);
void _Ldtob(printf_struct *args, char type);

#endif
