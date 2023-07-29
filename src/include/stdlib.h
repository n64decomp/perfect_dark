#ifndef __N64_STDLIB_H__
#define __N64_STDLIB_H__

#ifndef PLATFORM_N64

#include_next <stdlib.h>
#undef errno // fuck off

#else // PLATFORM_N64

#ifndef	NULL
#define NULL	0
#endif
typedef struct lldiv_t
{
	long long quot;
	long long rem;
} lldiv_t;

typedef struct ldiv_t
{
	long quot;
	long rem;
} ldiv_t;

lldiv_t lldiv(long long num, long long denom);
ldiv_t ldiv(long num, long denom);

#endif // PLATFORM_N64

#endif /* !__N64_STDLIB_H__ */
