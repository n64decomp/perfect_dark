#ifndef IN_GAME_PROP_H
#define IN_GAME_PROP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern f32 g_AutoAimScale;

void props_tick(void);

void props_stop(void);

void props_sort(void);
void prop_enable(struct prop *prop);
void prop_disable(struct prop *prop);
struct prop *prop_allocate(void);
void prop_free(struct prop *prop);
void prop_activate(struct prop *prop);
void prop_activate_this_frame(struct prop *prop);
void prop_delist(struct prop *prop);
void prop_reparent(struct prop *mover, struct prop *adopter);
void prop_detach(struct prop *prop);
Gfx *props_render(Gfx *gdl, RoomNum renderroomnum, s32 renderpass, RoomNum *roomnumsbyprop);
void weapon_play_melee_miss_sound(s32 weaponnum, struct prop *prop);
struct prop *prop_find_aiming_at(s32 handnum, bool isshooting, u32 context);
void hit_create(struct shotdata *shotdata, struct prop *prop, f32 hitdistance, s32 hitpart, struct modelnode *bboxnode, struct hitthing *hitthing, s32 arg6, struct modelnode *dlnode, struct model *model, bool slowsbullet, bool bulletproof, struct coord *arg11, struct coord *arg12);
void hands_tick_attack(void);
void prop_execute_tick_operation(struct prop *prop, s32 op);
bool current_player_interact(bool eyespy);
void prop_unpause(struct prop *prop);
void props_tick_player(bool islastplayer);
void props_tick_pad_effects(void);
void prop_set_perim_enabled(struct prop *prop, bool enable);
void props_test_for_pickup(void);
void autoaim_tick(void);
u32 prop_door_get_cd_types(struct prop *prop);
bool prop_is_of_cd_type(struct prop *prop, u32 types);
void rooms_copy(RoomNum *srcrooms, RoomNum *dstrooms);
void rooms_append(RoomNum *newrooms, RoomNum *dstrooms, s32 maxlen);
bool array_intersects(RoomNum *a, RoomNum *b);
void prop_deregister_rooms(struct prop *prop);
void prop_register_rooms(struct prop *prop);
void los_find_intersecting_rooms_properly(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, RoomNum *intersecting, s32 maxintersecting);
void los_find_final_room_properly(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms);
void los_find_intersecting_rooms_exhaustive(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, RoomNum *intersecting, s32 maxintersecting);
void los_find_final_room_exhaustive(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms);
void los_find_final_room_fast(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms);
void room_get_props(RoomNum *room, s16 *propnums, s32 len);
void prop_get_bbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin);
bool prop_get_geometry(struct prop *prop, u8 **start, u8 **end);

#endif
