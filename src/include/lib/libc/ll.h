#ifndef _IN_LIB_LIBC_LL_H
#define _IN_LIB_LIBC_LL_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

unsigned long long __ull_rshift(unsigned long long a0, unsigned long long a1);
unsigned long long __ull_rem(unsigned long long a0, unsigned long long a1);
unsigned long long __ull_div(unsigned long long a0, unsigned long long a1);
unsigned long long __ll_lshift(unsigned long long a0, unsigned long long a1);
long long __ll_rem(unsigned long long a0, long long a1);
long long __ll_div(long long a0, long long a1);
unsigned long long __ll_mul(unsigned long long a0, unsigned long long a1);
void __ull_divremi(unsigned long long *div, unsigned long long *rem, unsigned long long a2, unsigned short a3);
long long __ll_mod(long long a0, long long a1);
long long __ll_rshift(long long a0, long long a1);

#endif
