#ifndef IN_GAME_CEIL_H
#define IN_GAME_CEIL_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

static inline f32 ceilf(f32 value)
{
	s32 ret;
	__asm__ ("ceil.w.s %0, %1" : "=f"(ret) : "f"(value));
	return ret;
}

static inline s32 ceil(f32 value)
{
	s32 ret;
	__asm__ ("ceil.w.s %0, %1" : "=f"(ret) : "f"(value));
	return ret;
}

#endif
