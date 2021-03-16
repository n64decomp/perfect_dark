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

#define BLOCKSIZE 32

#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

#define ERRCK(fn) \
    ret = fn;     \
    if (ret != 0) \
        return ret;

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

typedef char *va_list;

#define _FP 1
#define _INT 0
#define _STRUCT 2

#define _VA_FP_SAVE_AREA 0x10
#define _VA_ALIGN(p, a) (((unsigned int)(((char *)p) + ((a) > 4 ? (a) : 4) - 1)) & -((a) > 4 ? (a) : 4))
#define va_start(vp, parmN) (vp = ((va_list)&parmN + sizeof(parmN)))

#define __va_stack_arg(list, mode)                                 \
  (                                                                \
      ((list) = (char *)_VA_ALIGN(list, __builtin_alignof(mode)) + \
                _VA_ALIGN(sizeof(mode), 4)),                       \
      (((char *)list) - (_VA_ALIGN(sizeof(mode), 4) - sizeof(mode))))

#define __va_double_arg(list, mode)                                                                  \
  (                                                                                                  \
      (((long)list & 0x1) /* 1 byte aligned? */                                                      \
           ? (list = (char *)((long)list + 7), (char *)((long)list - 6 - _VA_FP_SAVE_AREA))          \
           : (((long)list & 0x2) /* 2 byte aligned? */                                               \
                  ? (list = (char *)((long)list + 10), (char *)((long)list - 24 - _VA_FP_SAVE_AREA)) \
                  : __va_stack_arg(list, mode))))

#define va_arg(list, mode) ((mode *)(((__builtin_classof(mode) == _FP &&          \
                                       __builtin_alignof(mode) == sizeof(double)) \
                                          ? __va_double_arg(list, mode)           \
                                          : __va_stack_arg(list, mode))))[-1]
#define va_end(__list)

#define EEPROM_MAXBLOCKS	64
#define EEP16K_MAXBLOCKS	256
#define EEPROM_BLOCK_SIZE	8

/*
 * PI/EPI
 */
#define PI_DOMAIN1      0
#define PI_DOMAIN2      1

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
