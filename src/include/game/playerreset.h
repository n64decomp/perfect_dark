#ifndef IN_GAME_PLAYERRESET_H
#define IN_GAME_PLAYERRESET_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void modelmgr_reset(void);
void modelmgr_set_lv_resetting(bool value);
void modelmgr_allocate_slots(s32 numobjs, s32 numchrs);
bool modelmgr_load_projectile_modeldefs(s32 weaponnum);
void player_init_eyespy(void);
void player_reset(void);

#endif
