#ifndef IN_GAME_FLOOR_H
#define IN_GAME_FLOOR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

static inline f32 floorf(f32 value)
{
	s32 ret;
	__asm__ ("floor.w.s %0, %1" : "=f"(ret) : "f"(value));
	return ret;
}

static inline s32 floor(f32 value)
{
	s32 ret;
	__asm__ ("floor.w.s %0, %1" : "=f"(ret) : "f"(value));
	return ret;
}

#endif
