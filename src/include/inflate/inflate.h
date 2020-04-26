#ifndef _IN_INFLATE_H
#define _IN_INFLATE_H
#include <ultra64.h>

struct huft {
	u8 e;                /* number of extra bits or operation */
	u8 b;                /* number of bits in this code or subcode */
	union {
		u16 n;            /* literal, length base, or distance base */
		struct huft *t;   /* pointer to next level of table */
	} v;
};

u32 inflate1173(void *src, void *dst, struct huft *hlist);

#endif
