#ifndef _IN_LIB_COLLISION_H
#define _IN_LIB_COLLISION_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 func0f1577f0(f32 arg0[2], f32 arg1[2], f32 arg2[2], f32 arg3[2]);
f32 func0f1579cc(struct widthxz *arg0, struct xz *arg1, struct xz *arg2, struct xz *arg3);

f32 cd_00024e40(void);
void cd_get_edge(struct coord *pos1, struct coord *pos2, u32 line, char *file);
f32 cd_get_distance(void);
bool cd_has_distance(void);
struct prop *cd_get_obstacle_prop(void);
void cd_get_pos(struct coord *pos, u32 line, char *file);
void cd_get_obstacle_normal(struct coord *normal);
u32 cd_get_geo_flags(void);
void cd_set_saved_pos(struct coord *pos1, struct coord *pos2);
bool cd_get_saved_pos(struct coord *arg0, struct coord *arg1);
bool cd_is_2d_point_in_geo(f32 x, f32 z, struct geo *tile);
void cd_get_props_on_platform(struct prop *platform, s16 *propnums, s32 len);
s32 cd_000274e0_block(struct geoblock *tile, f32 x, f32 z, f32 width, struct prop *prop, struct collision *collision);
bool cd_000276c8_cyl(struct geocyl *tile, f32 x, f32 z, f32 width, struct prop *prop, struct collision *collision);
bool cd_find_ladder(struct coord *pos, f32 width, f32 ymax, f32 ymin, RoomNum *rooms, u16 geoflags, struct coord *laddernormal);
bool cd_0002a13c(struct coord *pos, f32 radius, f32 arg2, f32 arg3, RoomNum *rooms, u16 geoflags);
f32 cd_find_ground_info_at_cyl(struct coord *pos, f32 radius, RoomNum *rooms, u16 *floorcol, u8 *floortype, u16 *floorflags, RoomNum *floorroom, s32 *inlift, struct prop **lift);
f32 cd_return_zero(void);
f32 cd_find_ground_at_cyl(struct coord *pos, f32 radius, RoomNum *rooms, u16 *floorcol, u8 *floortype);
f32 cd_find_floor_y_colour_type_at_pos(struct coord *pos, RoomNum *rooms, u16 *floorcol, u8 *floortype);
s32 cd_find_floor_room_at_pos(struct coord *pos, RoomNum *nearrooms);

#if VERSION >= VERSION_NTSC_1_0
RoomNum cd_find_floor_room_y_colour_flags_at_pos(struct coord *pos, RoomNum *rooms, f32 *arg2, u16 *floorcolptr, u16 *flagsptr);
RoomNum cd_find_ceiling_room_y_colour_flags_at_pos(struct coord *pos, RoomNum *rooms, f32 *arg2, u16 *floorcolptr, u16 *flagsptr);
#else
RoomNum cd_find_floor_room_y_colour_flags_at_pos(struct coord *pos, RoomNum *rooms, f32 *arg2, u16 *floorcolptr);
RoomNum cd_find_ceiling_room_y_colour_flags_at_pos(struct coord *pos, RoomNum *rooms, f32 *arg2, u16 *floorcolptr);
#endif

RoomNum cd_find_floor_room_y_colour_normal_prop_at_pos(struct coord *pos, RoomNum *rooms, f32 *arg2, u16 *floorcol, struct coord *normal, struct prop **propptr);
RoomNum cd_find_ceiling_room_y_colour_flags_normal_at_pos(struct coord *pos, RoomNum *rooms, f32 *arg2, u16 *floorcol, u16 *geoflags, struct coord *normal);
s32 cd_test_volume(struct coord *pos, f32 radius, RoomNum *rooms, s32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cd_exam_cyl_move01(struct coord *pos, struct coord *pos2, f32 radius, RoomNum *rooms, s32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cd_exam_cyl_move02(struct coord *origpos, struct coord *dstpos, f32 width, RoomNum *dstrooms, s32 types, bool checkvertical, f32 ymax, f32 ymin);
bool cd_test_cyl_move01(struct coord *pos, RoomNum *rooms, struct coord *targetpos, u32 types, u32 arg4, f32 ymax, f32 ymin);
s32 cd_test_cyl_move02(struct coord *pos, RoomNum *rooms, struct coord *coord2, RoomNum *rooms2, u32 types, bool arg5, f32 ymax, f32 ymin);
s32 cd_exam_cyl_move03(struct coord *pos, RoomNum *rooms, struct coord *arg2, u32 types, u32 arg4, f32 ymax, f32 ymin);
s32 cd_test_cyl_move04(struct coord *arg0, RoomNum *arg1, struct coord *arg2, RoomNum *arg3, u32 types, s32 arg5, f32 ymax, f32 ymin);
s32 cd_exam_cyl_move05(struct coord *pos, RoomNum *rooms, struct coord *pos2, RoomNum *rooms2, s32 types, bool arg5, f32 ymax, f32 ymin);
s32 cd_exam_cyl_move06(struct coord *arg0, RoomNum *arg1, struct coord *arg2, RoomNum *arg3, f32 arg4, s32 types, s32 arg6, f32 ymax, f32 ymin);
s32 cd_exam_cyl_move07(struct coord *arg0, RoomNum *arg1, struct coord *arg2, RoomNum *arg3, u32 types, s32 arg5, f32 ymax, f32 ymin);
s32 cd_exam_cyl_move08(struct coord *arg0, RoomNum *arg1, struct coord *arg2, RoomNum *arg3, f32 width, u32 types, s32 arg6, f32 ymax, f32 ymin);
bool cd_test_los03(struct coord *viewpos, RoomNum *rooms, struct coord *targetpos, u32 types, u16 geoflags);
bool cd_test_los04(struct coord *coord, RoomNum *rooms, struct coord *coord2, s32 arg3);
bool cd_test_los05(struct coord *coord, RoomNum *rooms, struct coord *coord2, RoomNum *rooms2, s32 cdtypes, u16 geoflags);
bool cd_test_los06(struct coord *arg0, RoomNum *rooms1, struct coord *arg2, RoomNum *rooms2, u32 types);
bool cd_test_los07(struct coord *pos, RoomNum *rooms, struct coord *pos2, RoomNum *rooms2, RoomNum *rooms3, u32 types, u16 geoflags);
s32 cd_exam_los08(struct coord *pos, RoomNum *rooms, struct coord *pos2, u32 types, u16 geoflags);
s32 cd_exam_los09(struct coord *pos, RoomNum *rooms, struct coord *pos2, u32 types);
s32 cd_test_los10(struct coord *arg0, RoomNum *arg1, struct coord *arg2, RoomNum *arg3, u32 types, u16 geoflags);
s32 cd_test_los11(struct coord *arg0, RoomNum *arg1, struct coord *arg2, RoomNum *arg3, u32 types);
bool cd_0002ded8(struct coord *arg0, struct coord *arg1, struct prop *prop);
s32 cd_test_block_overlaps_any_prop(struct geoblock *geo, RoomNum *rooms, u32 types);
s32 cd_0002f02c(struct geoblock *block, RoomNum *rooms, s32 types);
bool cd_is_nearly_in_sight(struct coord *viewpos, RoomNum *rooms, struct coord *targetpos, f32 distance, s32 arg4);

#endif
