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
Gfx *prop_render(Gfx *gdl, struct prop *prop, bool xlupass);
Gfx *props_render(Gfx *gdl, RoomNum renderroomnum, s32 renderpass, RoomNum *roomnumsbyprop);
void weapon_play_whoosh_sound(s32 weaponnum, struct prop *prop);
void func0f060bac(s32 weaponnum, struct prop *prop);
struct prop *shot_calculate_hits(s32 handnum, bool isshooting, struct coord *gunpos2d, struct coord *gundir2d, struct coord *gunpos3d, struct coord *gundir3d, u32 arg6, f32 distance, bool arg8);
struct prop *prop_find_aiming_at(s32 handnum, bool isshooting, u32 context);
void shot_create(s32 handnum, bool arg1, bool dorandom, s32 numshots, bool arg4);
void hit_create(struct shotdata *shotdata, struct prop *prop, f32 hitdistance, s32 hitpart, struct modelnode *bboxnode, struct hitthing *hitthing, s32 arg6, struct modelnode *dlnode, struct model *model, bool slowsbullet, bool bulletproof, struct coord *arg11, struct coord *arg12);
void hand_inflict_melee_damage(s32 handnum, struct gset *gset, bool arg2);
void hand_tick_attack(s32 handnum);
void hands_tick_attack(void);
void prop_execute_tick_operation(struct prop *prop, s32 op);
struct prop *prop_find_for_interact(bool eyespy);
void prop_find_for_uplink(void);
bool current_player_interact(bool eyespy);
void prop_pause(struct prop *prop);
void prop_unpause(struct prop *prop);
void props_tick_player(bool islastplayer);
void props_tick_pad_effects(void);
void prop_set_perim_enabled(struct prop *prop, bool enable);
void props_test_for_pickup(void);
f32 func0f06438c(struct prop *prop, struct coord *arg1, f32 *arg2, f32 *arg3, f32 *arg4, bool throughobjects, bool cangangsta, s32 arg7);
void farsight_choose_target(void);
void autoaim_tick(void);
u32 prop_door_get_cd_types(struct prop *prop);
bool prop_is_of_cd_type(struct prop *prop, u32 types);
void rooms_copy(RoomNum *srcrooms, RoomNum *dstrooms);
void rooms_append(RoomNum *newrooms, RoomNum *dstrooms, s32 maxlen);
bool array_intersects(RoomNum *a, RoomNum *b);
bool prop_try_add_to_chunk(s16 propnum, s32 chunkindex);
s32 room_allocate_prop_list_chunk(s32 room, s32 arg1);
void prop_register_room(struct prop *prop, RoomNum room);
void prop_deregister_room(struct prop *prop, RoomNum room);
void prop_deregister_rooms(struct prop *prop);
void prop_register_rooms(struct prop *prop);
void los_find_intersecting_rooms_properly(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, RoomNum *intersecting, s32 maxintersecting);
void los_find_final_room_properly(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms);
void los_find_intersecting_rooms_exhaustive(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, RoomNum *intersecting, s32 maxintersecting);
void los_find_final_room_exhaustive(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms);
void los_find_final_room_fast(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms);
void room_get_props(RoomNum *room, s16 *propnums, s32 len);
void props_defrag_room_props(void);
void prop_get_bbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin);
bool prop_update_geometry(struct prop *prop, u8 **start, u8 **end);

#endif
