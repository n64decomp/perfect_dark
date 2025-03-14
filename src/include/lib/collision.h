#ifndef _IN_LIB_COLLISION_H
#define _IN_LIB_COLLISION_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 func0f1577f0(f32 arg0[2], f32 arg1[2], f32 arg2[2], f32 arg3[2]);
f32 func0f1579cc(struct radiusxz *arg0, struct xz *arg1, struct xz *arg2, struct xz *arg3);

f32 cd_get_sqdistance(void);
void cd_get_edge(struct coord *pos1, struct coord *pos2, u32 line, char *file);
f32 cd_get_distance(void);
bool cd_has_distance(void);
struct prop *cd_get_obstacle_prop(void);
void cd_get_obstacle_pos(struct coord *pos, u32 line, char *file);
void cd_get_obstacle_normal(struct coord *normal);
u32 cd_get_geo_flags(void);
void cd_set_block_edge(struct coord *vtx1, struct coord *vtx2);
bool cd_get_block_edge(struct coord *vtx1, struct coord *vtx2);

bool cd_is_xz_in_geo(f32 x, f32 z, struct geo *tile);
void cd_get_props_on_platform(struct prop *platform, s16 *propnums, s32 len);
s32 cd_block_collides_with_cyl_laterally(struct geoblock *tile, f32 x, f32 z, f32 width, struct prop *prop, struct collision *collision);
bool cd_cyl_collides_with_cyl_laterally(struct geocyl *tile, f32 x, f32 z, f32 width, struct prop *prop, struct collision *collision);
bool cd_find_ladder(struct coord *pos, f32 width, f32 ymax, f32 ymin, RoomNum *rooms, u16 geoflags, struct coord *laddernormal);
bool is_cyl_touching_tile_with_flags(struct coord *pos, f32 radius, f32 ymax, f32 ymin, RoomNum *rooms, u16 geoflags);
f32 cd_find_ground_at_cyl_ctfril(struct coord *pos, f32 radius, RoomNum *rooms, u16 *floorcol, u8 *floortype, u16 *floorflags, RoomNum *floorroom, s32 *inlift, struct prop **lift);
f32 cd_return_zero(void);
f32 cd_find_ground_at_cyl_ct(struct coord *pos, f32 radius, RoomNum *rooms, u16 *floorcol, u8 *floortype);
f32 cd_find_ground_at_pos_ct(struct coord *pos, RoomNum *rooms, u16 *floorcol, u8 *floortype);
RoomNum cd_find_room_at_pos(struct coord *pos, RoomNum *nearrooms);

#if VERSION >= VERSION_NTSC_1_0
RoomNum cd_find_room_at_pos_ycf(struct coord *pos, RoomNum *rooms, f32 *y, u16 *floorcolptr, u16 *flagsptr);
RoomNum cd_find_ceiling_room_at_pos_ycf(struct coord *pos, RoomNum *rooms, f32 *y, u16 *floorcolptr, u16 *flagsptr);
#else
RoomNum cd_find_room_at_pos_ycf(struct coord *pos, RoomNum *rooms, f32 *y, u16 *floorcolptr);
RoomNum cd_find_ceiling_room_at_pos_ycf(struct coord *pos, RoomNum *rooms, f32 *y, u16 *floorcolptr);
#endif

RoomNum cd_find_room_at_pos_ycnp(struct coord *pos, RoomNum *rooms, f32 *y, u16 *floorcol, struct coord *normal, struct prop **propptr);
RoomNum cd_find_ceiling_room_at_pos_ycfn(struct coord *pos, RoomNum *rooms, f32 *y, u16 *floorcol, u16 *geoflags, struct coord *normal);

s32 cd_test_volume_simple(struct coord *pos, f32 radius, RoomNum *rooms, u32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cd_test_volume_closestedge(struct coord *frompos, struct coord *topos, f32 radius, RoomNum *rooms, u32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cd_test_volume_fromdir(struct coord *frompos, struct coord *topos, f32 radius, RoomNum *dstrooms, u32 types, bool checkvertical, f32 ymax, f32 ymin);

s32 cd_test_cylmove_oobok(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, u32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cd_test_cylmove_oobfail(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *torooms, u32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cd_test_cylmove_oobok_findclosest(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, u32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cd_test_cylmove_oobok_getfinalroom(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, u32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cd_test_cylmove_oobfail_findclosest(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *torooms, u32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cd_test_cylmove_oobfail_findclosest_finddist(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *torooms, f32 radius, u32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cd_test_cylmove_oobok_findclosest_getfinalroom(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, u32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cd_test_cylmove_oobok_findclosest_getfinalroom_finddist(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, f32 radius, u32 types, bool checkvertical, f32 ymax, f32 ymin);

s32 cd_test_los_oobok(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, u32 types, u16 geoflags);
s32 cd_test_los_oobok_autoflags(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, u32 types);
s32 cd_test_los_oobfail(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *torooms, u32 types, u16 geoflags);
s32 cd_test_los_oobtail_autoflags(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *torooms, u32 types);
s32 cd_test_los_oobfail_getfinalroom(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *torooms, RoomNum *finalrooms, u32 types, u16 geoflags);
s32 cd_test_los_oobok_findclosest(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, u32 types, u16 geoflags);
s32 cd_test_los_oobok_findclosest_autoflags(struct coord *pos, RoomNum *rooms, struct coord *pos2, u32 types);
s32 cd_test_los_oobok_getfinalroom(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, u32 types, u16 geoflags);
s32 cd_test_los_oobok_getfinalroom_autoflags(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, u32 types);

bool cd_test_line_intersects_prop(struct coord *frompos, struct coord *topos, struct prop *prop);
s32 cd_test_blockvolume(struct geoblock *block, RoomNum *rooms, u32 types);
s32 cd_test_blockmove(struct geoblock *block, RoomNum *rooms, u32 types);
bool cd_is_nearly_in_sight(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, f32 distance, u32 types);

#endif
