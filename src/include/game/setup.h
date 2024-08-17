#ifndef IN_GAME_SETUP_H
#define IN_GAME_SETUP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void setup_prepare_pads(void);
void setup_load_waypoints(void);
void setup_prepare_cover(void);

void props_reset(void);
void setup_create_lift_door(struct linkliftdoorobj *link);
void setup_create_padlocked_door(struct padlockeddoorobj *link);
void setup_create_safe_item(struct safeitemobj *link);
void setup_create_conditional_scenery(struct linksceneryobj *link);
void setup_create_blocked_path(struct blockedpathobj *link);
void setup_reset_0f00cc8c(void);
void setup_reset_proxy_mines(void);
s32 setup_count_command_type(u32 type);
void setup_create_object(struct defaultobj *obj, s32 cmdindex);
void setup_place_weapon(struct weaponobj *weapon, s32 cmdindex);
void setup_create_hat(struct hatobj *hat, s32 cmdindex);
void setup_create_key(struct keyobj *key, s32 cmdindex);
void setup_create_mine(struct mineobj *mine, s32 cmdindex);
void setup_create_cctv(struct cctvobj *camera, s32 cmdindex);
void setup_create_autogun(struct autogunobj *autogun, s32 cmdindex);
void setup_create_hanging_monitors(struct hangingmonitorsobj *monitors, s32 cmdindex);
void setup_create_single_monitor(struct singlemonitorobj *monitor, s32 cmdindex);
void setup_create_multi_monitor(struct multimonitorobj *monitor, s32 cmdindex);
s32 setup_get_portal_by_pad(s32 padnum);
s32 setup_get_portal_by_door_pad(s32 padnum);
void setup_create_door(struct doorobj *door, s32 cmdindex);
void setup_create_hov(struct defaultobj *obj, struct hov *hov);
void setup_load_briefing(s32 stagenum, u8 *buffer, s32 bufferlen, struct briefing *briefing);
void setup_load_files(s32 stagenum);
void setup_create_props(s32 stagenum);

#endif
