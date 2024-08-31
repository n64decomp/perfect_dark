#ifndef IN_GAME_BG_H
#define IN_GAME_BG_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bg_get_room_brightness_range(s32 roomnum, u8 *min, u8 *max);
struct drawslot *bg_get_room_draw_slot(s32 roomnum);
Gfx *bg_render_artifacts(Gfx *gdl);
s32 bg_get_stage_index(s32 stagenum);
f32 bg_calculate_portal_surface_area(s32 portal);
u32 not(u32 arg);
void bg_reset(s32 stagenum);
void bg_build_tables(s32 stagenum);
void bg_stop(void);
f32 bg_get_stage_translation_thing(void);
f32 bg_get_scale_bg2gfx(void);
void bg_set_scale_bg2gfx(f32 arg0);
void bg_tick(void);
Gfx *bg_render(Gfx *gdl);
Gfx *bg_scissor_to_viewport(Gfx *gdl);
Gfx *bg_scissor_within_viewport(Gfx *gdl, s32 viewleft, s32 viewtop, s32 viewright, s32 viewbottom);
bool bg_room_is_onscreen(s32 room);
bool bg_room_is_standby(s32 room);
bool bg_room_is_on_player_screen(s32 room, u32 playernum);
bool bg_room_is_on_player_standby(s32 room, u32 aibotindex);
void bg_garbage_collect_rooms(s32 bytesneeded, bool desparate);
bool bg_test_line_intersects_int_bbox(struct coord *arg0, struct coord *arg1, s32 *arg2, s32 *arg3);
bool bg_test_line_intersects_bbox(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3);
bool bg_test_hit_on_obj(struct coord *arg0, struct coord *arg1, struct coord *arg2, Gfx *gdl, Gfx *gdl2, Vtx *vertices, struct hitthing *hitthing);
bool bg_test_hit_on_chr(struct model *model, struct coord *arg1, struct coord *arg2, struct coord *arg3, Gfx *arg4, Gfx *arg5, Vtx *vertices, f32 *arg7, struct hitthing *hitthing);
bool bg_test_hit_in_room(struct coord *frompos, struct coord *topos, s32 roomnum, struct hitthing *hitthing);
bool bg_room_is_loaded(s32 room);
bool bg_room_contains_coord(struct coord *pos, RoomNum roomnum);
bool bg_test_pos_in_room(struct coord *pos, RoomNum roomnum);
void bg_find_rooms_by_pos(struct coord *pos, RoomNum *inrooms, RoomNum *aboverooms, s32 max, RoomNum *bestroom);
s32 bg_get_force_onscreen_rooms(RoomNum *rooms, s32 len);
s32 bg_room_get_neighbours(s32 room, RoomNum *rooms, s32 len);
bool bg_rooms_are_neighbours(s32 roomnum1, s32 roomnum2);
void bg_set_portal_open_state(s32 portal, bool open);
s32 bg_find_portal_between_positions(struct coord *pos1, struct coord *pos2);
bool bg_is_bbox_overlapping(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3);
void bg_calculate_portal_bbox(s32 portalnum, struct coord *bbmin, struct coord *bbmax);
void bg_find_entered_rooms(struct coord *bbmin, struct coord *bbmax, RoomNum *rooms, s32 maxlen, bool arg4);

#endif
