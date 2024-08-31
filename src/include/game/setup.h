#ifndef IN_GAME_SETUP_H
#define IN_GAME_SETUP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void setup_prepare_pads(void);
void setup_load_waypoints(void);
void setup_prepare_cover(void);

void props_reset(void);
void setup_create_object(struct defaultobj *obj, s32 cmdindex);
void setup_place_weapon(struct weaponobj *weapon, s32 cmdindex);
void setup_load_briefing(s32 stagenum, u8 *buffer, s32 bufferlen, struct briefing *briefing);
void setup_load_files(s32 stagenum);
void setup_create_props(s32 stagenum);

#endif
