#ifndef _IN_LIB_COLLISION_H
#define _IN_LIB_COLLISION_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 func0f1577f0(f32 arg0[2], f32 arg1[2], f32 arg2[2], f32 arg3[2]);
f32 func0f1578c8(struct widthxz *arg0, struct xz *arg1, struct xz *arg2);
f32 func0f1579cc(struct widthxz *arg0, struct xz *arg1, struct xz *arg2, struct xz *arg3);

f32 cd00024e40(void);
void cdGetEdge(struct coord *pos1, struct coord *pos2, u32 line, char *file);
f32 cd00024e98(void);
s32 cd00024ea4(void);
struct prop *cdGetObstacleProp(void);
void cdGetPos(struct coord *pos, u32 line, char *file);
void cdGetObstacleNormal(struct coord *normal);
u32 cdGetGeoFlags(void);
void cdSetSavedPos(struct coord *pos1, struct coord *pos2);
bool cdGetSavedPos(struct coord *arg0, struct coord *arg1);
void cdGetGeoNormal(struct geo *geo, struct coord *normal);
void cdGetFloorCol(struct geo *tile, u16 *floorcol);
void cdGetFloorType(struct geo *tile, u8 *floortype);
bool cd000266a4(f32 x, f32 z, struct geo *tile);
void cdGetPropsOnPlatform(struct prop *platform, s16 *propnums, s32 len);
s32 cd000274e0Block(struct geoblock *tile, f32 x, f32 z, f32 width, struct prop *prop, struct collision *collision);
bool cd000276c8Cyl(struct geocyl *tile, f32 x, f32 z, f32 width, struct prop *prop, struct collision *collision);
bool cdFindLadder(struct coord *pos, f32 width, f32 ymax, f32 ymin, RoomNum *rooms, u16 geoflags, struct coord *laddernormal);
bool cd0002a13c(struct coord *pos, f32 radius, f32 arg2, f32 arg3, RoomNum *rooms, u16 geoflags);
f32 cdFindGroundInfoAtCyl(struct coord *pos, f32 radius, RoomNum *rooms, u16 *floorcol, u8 *floortype, u16 *floorflags, RoomNum *floorroom, s32 *inlift, struct prop **lift);
f32 cdReturnZero(void);
f32 cdFindGroundAtCyl(struct coord *pos, f32 radius, RoomNum *rooms, u16 *floorcol, u8 *floortype);
f32 cdFindFloorYColourTypeAtPos(struct coord *pos, RoomNum *rooms, u16 *floorcol, u8 *floortype);
s32 cdFindFloorRoomAtPos(struct coord *pos, RoomNum *nearrooms);

#if VERSION >= VERSION_NTSC_1_0
RoomNum cdFindFloorRoomYColourFlagsAtPos(struct coord *pos, RoomNum *rooms, f32 *arg2, u16 *floorcolptr, u16 *flagsptr);
RoomNum cdFindCeilingRoomYColourFlagsAtPos(struct coord *pos, RoomNum *rooms, f32 *arg2, u16 *floorcolptr, u16 *flagsptr);
#else
RoomNum cdFindFloorRoomYColourFlagsAtPos(struct coord *pos, RoomNum *rooms, f32 *arg2, u16 *floorcolptr);
RoomNum cdFindCeilingRoomYColourFlagsAtPos(struct coord *pos, RoomNum *rooms, f32 *arg2, u16 *floorcolptr);
#endif

RoomNum cdFindFloorRoomYColourNormalPropAtPos(struct coord *pos, RoomNum *rooms, f32 *arg2, u16 *floorcol, struct coord *normal, struct prop **propptr);
RoomNum cdFindCeilingRoomYColourFlagsNormalAtPos(struct coord *pos, RoomNum *rooms, f32 *arg2, u16 *floorcol, u16 *geoflags, struct coord *normal);
s32 cdTestVolume(struct coord *pos, f32 radius, RoomNum *rooms, s32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cdExamCylMove01(struct coord *pos, struct coord *pos2, f32 radius, RoomNum *rooms, s32 types, bool checkvertical, f32 ymax, f32 ymin);
s32 cdExamCylMove02(struct coord *origpos, struct coord *dstpos, f32 width, RoomNum *dstrooms, s32 types, bool checkvertical, f32 ymax, f32 ymin);
bool cdTestCylMove01(struct coord *pos, RoomNum *rooms, struct coord *targetpos, u32 types, u32 arg4, f32 ymax, f32 ymin);
s32 cdTestCylMove02(struct coord *pos, RoomNum *rooms, struct coord *coord2, RoomNum *rooms2, u32 types, bool arg5, f32 ymax, f32 ymin);
s32 cdExamCylMove03(struct coord *pos, RoomNum *rooms, struct coord *arg2, u32 types, u32 arg4, f32 ymax, f32 ymin);
s32 cdTestCylMove04(struct coord *arg0, RoomNum *arg1, struct coord *arg2, RoomNum *arg3, u32 types, s32 arg5, f32 ymax, f32 ymin);
s32 cdExamCylMove05(struct coord *pos, RoomNum *rooms, struct coord *pos2, RoomNum *rooms2, s32 types, bool arg5, f32 ymax, f32 ymin);
s32 cdExamCylMove06(struct coord *arg0, RoomNum *arg1, struct coord *arg2, RoomNum *arg3, f32 arg4, s32 types, s32 arg6, f32 ymax, f32 ymin);
s32 cdExamCylMove07(struct coord *arg0, RoomNum *arg1, struct coord *arg2, RoomNum *arg3, u32 types, s32 arg5, f32 ymax, f32 ymin);
s32 cdExamCylMove08(struct coord *arg0, RoomNum *arg1, struct coord *arg2, RoomNum *arg3, f32 width, u32 types, s32 arg6, f32 ymax, f32 ymin);
bool cdTestLos03(struct coord *viewpos, RoomNum *rooms, struct coord *targetpos, u32 types, u16 geoflags);
bool cdTestLos04(struct coord *coord, RoomNum *rooms, struct coord *coord2, s32 arg3);
bool cdTestLos05(struct coord *coord, RoomNum *rooms, struct coord *coord2, RoomNum *rooms2, s32 cdtypes, u16 geoflags);
bool cdTestLos06(struct coord *arg0, RoomNum *rooms1, struct coord *arg2, RoomNum *rooms2, u32 types);
bool cdTestLos07(struct coord *pos, RoomNum *rooms, struct coord *pos2, RoomNum *rooms2, RoomNum *rooms3, u32 types, u16 geoflags);
s32 cdExamLos08(struct coord *pos, RoomNum *rooms, struct coord *pos2, u32 types, u16 geoflags);
s32 cdExamLos09(struct coord *pos, RoomNum *rooms, struct coord *pos2, u32 types);
s32 cdTestLos10(struct coord *arg0, RoomNum *arg1, struct coord *arg2, RoomNum *arg3, u32 types, u16 geoflags);
s32 cdTestLos11(struct coord *arg0, RoomNum *arg1, struct coord *arg2, RoomNum *arg3, u32 types);
bool cd0002ded8(struct coord *arg0, struct coord *arg1, struct prop *prop);
s32 cdTestBlockOverlapsAnyProp(struct geoblock *geo, RoomNum *rooms, u32 types);
s32 cd0002f02c(struct geoblock *block, RoomNum *rooms, s32 types);
bool cdIsNearlyInSight(struct coord *viewpos, RoomNum *rooms, struct coord *targetpos, f32 distance, s32 arg4);

#endif
