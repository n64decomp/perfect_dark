#ifndef _ULTRA64_OS_MISC_H_
#define _ULTRA64_OS_MISC_H_

/* float properties */
#define _D0 0
#define _DBIAS 0x3ff
#define _DLONG 1
#define _DOFF 4
#define _FBIAS 0x7e
#define _FOFF 7
#define _FRND 1
#define _LBIAS 0x3ffe
#define _LOFF 15

/* integer properties */
#define _C2 1
#define _CSIGN 1
#define _ILONG 0
#define _MBMAX 8
#define NAN 2
#define INF 1
#define FINITE -1
#define _DFRAC ((1 << _DOFF) - 1)
#define _DMASK (0x7fff & ~_DFRAC)
#define _DMAX ((1 << (15 - _DOFF)) - 1)
#define _DNAN (0x8000 | _DMAX << _DOFF | 1 << (_DOFF - 1))
#define _DSIGN 0x8000
#define _D1 1 /* big-endian order */
#define _D2 2
#define _D3 3

#define FLAGS_SPACE 1
#define FLAGS_PLUS 2
#define FLAGS_MINUS 4
#define FLAGS_HASH 8
#define FLAGS_ZERO 16


typedef struct {
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

/* Miscellaneous OS functions */

void osInitialize(void);
u32 osGetCount(void);

u32 osVirtualToPhysical(void *);

f32 cosf(f32 arg0);
f32 sinf(f32 arg0);
f32 sqrtf(f32 arg0);

void *memcpy(void *, const void *, size_t);
size_t strlen(const char *s);
char *strchr(const char *s, int c);

#endif
