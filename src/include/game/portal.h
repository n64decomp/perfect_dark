#ifndef _IN_GAME_PORTAL_H
#define _IN_GAME_PORTAL_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void portalSetXluFrac2(s32 portalnum, f32 frac);
void portalSetXluFrac(s32 portalnum, f32 frac);
f32 portalGetXluFrac(s32 arg0);
void portal0f0b65a8(s32 numportals);
void portalsReset(void);
void acousticReset(void);

#endif
