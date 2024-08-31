#ifndef _IN_GAME_PORTAL_H
#define _IN_GAME_PORTAL_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void portal_set_xlu_frac2(s32 portalnum, f32 frac);
void portal_set_xlu_frac(s32 portalnum, f32 frac);
f32 portal_get_xlu_frac(s32 arg0);
void portal0f0b65a8(s32 numportals);
void portals_reset(void);
void acoustic_reset(void);

#endif
