#ifndef _IN_LIB_COLLISION_H
#define _IN_LIB_COLLISION_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 func0f1577f0(void);
f32 func0f1578c8(struct coord *arg0, struct coord *arg1, struct coord *arg2);
f32 func0f1579cc(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3);

f32 cd00024e40(void);
void cd00024e4c(struct coord *arg0, struct coord *arg1, u32 line, char *file);
f32 cd00024e98(void);
s32 cd00024ea4(void);
struct prop *cdGetObstacle(void);
void cdGetPos(struct coord *pos, u32 line, char *file);
void cd00024ee8(struct coord *arg0);
u32 cdGetTileFlags(void);
void cd00024f6c(void);
void cd00024fb0(struct coord *arg0, struct coord *arg1, struct prop *prop);
void cd00025038(struct coord *arg0, struct coord *arg1, struct prop *prop, f32 arg3);
void cd000250cc(struct coord *arg0, struct coord *arg1, f32 width);
void cd00025168(struct prop *prop);
void cd000251ac(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct prop *prop);
void cd00025254(struct coord *arg0, struct coord *arg1, struct coord *pos, struct prop *prop, f32 arg4, struct geo *tile);
void cd00025314(struct coord *pos, struct coord *arg1);
bool cd00025364(struct coord *arg0, struct coord *arg1);
void cd000253c4(struct geoblock *tile);
s32 cd00025410(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
s32 cd000254d8(struct coord *arg0, struct coord *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 *arg6);
f32 cd00025654(f32 x1, f32 z1, f32 x2, f32 z2, f32 x3, f32 z3);
f32 cd00025724(f32 x1, f32 z1, f32 x2, f32 z2);
bool cd00025774(f32 x1, f32 z1, f32 x2, f32 z2, f32 x3, f32 z3);
void cd00025848(f32 tilex, f32 tilez, f32 tilewidth, f32 posx, f32 posz, f32 *x1, f32 *z1, f32 *x2, f32 *z2);
void cd00025928(struct geo *tile, struct coord *arg1);
void cdGetFloorCol(struct geo *tile, u16 *floorcol);
void cdGetFloorType(struct geo *tile, u8 *floortype);
f32 cdFindGroundInIntTileAtVertex(struct geotilei *tile, f32 x, f32 z, s32 vertexindex);
f32 cdFindGroundInIntTile(struct geotilei *tile, f32 x, f32 z);
f32 cdFindGroundInFltTile(struct geotilef *tile, f32 x, f32 z);
bool cdIs2dPointInIntTile(struct geotilei *tile, f32 x, f32 z);
bool cdIs2dPointInFltTile(struct geotilef *tile, f32 x, f32 z);
bool cdIs2dPointInBlock(struct geoblock *tile, f32 x, f32 z);
bool cdIs2dPointInCyl(struct geocyl *cyl, f32 x, f32 z);
bool func000266a4(f32 x, f32 z, struct geo *tile);
void cdGetPropsOnPlatform(struct prop *platform, s16 *propnums, s32 len);
bool cd00026a04(struct coord *pos, u8 *start, u8 *end, u16 flags, s32 room, struct geo **tileptr, s32 *roomptr, f32 *groundptr, bool arg8);
void cd00026e7c(struct coord *pos, s16 *rooms, u16 arg2, struct geo **tileptr, s16 *room, f32 *arg5, struct prop **arg6, s32 arg7);
bool cd0002709c(struct geotilei *tile, f32 x, f32 z, f32 width, struct prop *prop, struct collisionthing *thing);
bool cd000272f8(struct geotilef *tile, f32 x, f32 z, f32 radius, struct prop *prop, struct collisionthing *thing);
s32 cd000274e0(struct geoblock *tile, f32 x, f32 z, f32 width, struct prop *prop, struct collisionthing *thing);
bool cd000276c8(struct geocyl *tile, f32 x, f32 z, f32 width, struct prop *prop, struct collisionthing *thing);
void cd00027738(struct coord *pos, f32 width, u8 *start, u8 *end, u16 flags, bool checkvertical, f32 arg6, f32 arg7, struct prop *prop, struct collisionthing *things, s32 maxthings, s32 *thingnum, s32 roomnum);
void cd00027d1c(struct coord *pos, f32 radius, s16 *rooms, u32 types, u16 arg4, u32 arg5, f32 arg6, f32 arg7, struct collisionthing *arg8, s32 arg9);
u32 cd00027f78(void);
s32 cd00028200(struct geotilei *tile, struct coord *pos, f32 width, f32 y1, f32 y2);
u32 cd0002840c(void);
u32 cd00028638(void);
void cd0002885c(struct geocyl *cyl, f32 x, f32 z, f32 arg3, struct prop *prop, struct collisionthing *things, s32 maxthings, s32 *thingindex);
s32 cd00028914(u8 *start, u8 *end, struct coord *pos, f32 width, u16 flags, bool checkvertical, f32 arg6, f32 arg7, struct prop *prop, struct collisionthing *things, s32 maxthings, s32 *thingnum);
void cd00028df0(struct coord *pos, f32 width, s16 *rooms, u32 types, u16 arg4, u32 arg5, f32 ymax, f32 ymin, struct collisionthing *arg8, s32 arg9);
void cd0002901c(struct coord *pos, struct coord *dist, f32 width, struct collisionthing *arg3);
f32 cd000296a0(struct collisionthing *arg0, struct coord *pos, struct collisionthing **arg2, f32 width);
bool cd00029ffc(struct coord *pos, f32 width, f32 foreheadheight, f32 inversefeettoeyesheight, s16 *rooms, u16 arg5, struct coord *laddernormal);
bool cd0002a13c(struct coord *pos, f32 radius, f32 arg2, f32 arg3, s16 *rooms, u16 arg5);
f32 cdFindGroundY(struct coord *pos, f32 radius, s16 *rooms, u16 *floorcol, u8 *floortype, u16 *floorflags, s16 *floorroom, s32 *inlift, struct prop **lift);
f32 cd0002a324(void);
f32 cdFindGroundYSimple(struct coord *pos, f32 width, s16 *rooms, u16 *floorcol, u8 *floortype);
f32 cd0002a36c(struct coord *coord, s16 *rooms, u16 *floorcol, u8 *floortype);
s32 cd0002a400(struct coord *pos, s16 *rooms);

#if VERSION >= VERSION_NTSC_1_0
s16 cd0002a440(struct coord *pos, s16 *rooms, f32 *arg2, u16 *floorcolptr, u16 *flagsptr);
#else
s16 cd0002a440(struct coord *pos, s16 *rooms, f32 *arg2, u16 *floorcolptr);
#endif

s16 cd0002a4d0(struct coord *pos, s16 *rooms, f32 *arg2, u16 *floorcolptr, u16 *flagsptr);
s32 cd0002a564(struct coord *pos, s16 *rooms, f32 *arg2, u16 *floorcol, struct coord *arg4, struct prop **propptr);
s32 cd0002a5e4(struct coord *pos, s16 *rooms, f32 *arg2, u16 *floorcol, u16 *arg4, struct coord *arg5);
s32 cdTestVolume(struct coord *pos, f32 radius, s16 *rooms, s32 types, s32 arg4, f32 ymax, f32 ymin);
s32 cd0002a6fc(struct coord *pos, struct coord *pos2, f32 width, s16 *rooms, s32 types, bool arg5, f32 arg6, f32 arg7);
s32 cdTestAToB1(struct coord *origpos, struct coord *dstpos, f32 width, s16 *dstrooms, s32 types, s32 arg5, f32 ymax, f32 ymin);
bool cd0002aac0(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct geotilei *tile, s32 arg4, s32 arg5);
bool cd0002ab98(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct geotilef *tile, struct coord *arg4, struct coord *arg5);
u32 cd0002ac70(void);
u32 cd0002b128(void);
u32 cd0002b560(void);
u32 cd0002b954(void);
bool cd0002bd04(u8 *start, u8 *end, struct coord *arg2, struct coord *arg3, struct coord *arg4, s32 arg5, s32 arg6, s32 arg7, f32 arg8, f32 arg9);
void cd0002c328(struct geotilei *tile, struct coord *arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4);
void cd0002c528(struct geotilef *tile, struct coord *arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4);
bool cd0002c714(u8 *start, u8 *end, struct coord *arg2, struct coord *arg3, struct coord *arg4, u16 arg5, s32 arg6, s32 arg7, f32 ymax, f32 ymin, f32 *arg10, struct coord *arg11, struct coord *arg12, struct coord *arg13, struct geo **tile, s32 roomnum);
bool cd0002d15c(struct coord *pos, struct coord *coord2, s16 *rooms, u32 types, u16 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8);
s32 cd0002d3b0(struct coord *arg0, struct coord *arg1, s16 *arg2, s32 types, u16 arg4, s32 arg5, s32 arg6, f32 ymax, f32 ymin);
bool cd0002d6ac(struct coord *pos, s16 *rooms, struct coord *targetpos, u32 types, u32 arg4, f32 arg5, f32 arg6);
s32 cdTestAToB2(struct coord *pos, s16 *rooms, struct coord *coord2, s16 *rooms2, u32 types, s32 arg5, f32 arg6, f32 arg7);
bool cd0002d7c0(struct coord *pos, s16 *rooms, struct coord *arg2, u32 arg3, u32 arg4, f32 ymax, f32 ymin);
s32 cd0002d840(struct coord *arg0, s16 *arg1, struct coord *arg2, s16 *arg3, u32 types, s32 arg5, f32 ymax, f32 ymin);
s32 cd0002d8b8(struct coord *pos, s16 *rooms, struct coord *pos2, s16 *rooms2, s32 types, bool arg5, f32 ymax, f32 ymin);
s32 cdTestAToB3(struct coord *arg0, s16 *arg1, struct coord *arg2, s16 *arg3, f32 arg4, s32 types, s32 arg6, f32 ymax, f32 ymin);
s32 cd0002da50(struct coord *arg0, s16 *arg1, struct coord *arg2, s16 *arg3, u32 types, s32 arg5, f32 ymax, f32 ymin);
s32 cd0002dac8(struct coord *arg0, s16 *arg1, struct coord *arg2, s16 *arg3, f32 width, u32 types, s32 arg6, f32 ymax, f32 ymin);
bool cd0002db98(struct coord *viewpos, s16 *rooms, struct coord *targetpos, u32 types, u16 arg4);
bool cd0002dc18(struct coord *coord, s16 *rooms, struct coord *coord2, s32 arg3);
bool cdHasLineOfSight(struct coord *coord, s16 *rooms, struct coord *coord2, s16 *rooms2, s32 arg4, u16 arg5);
bool cd0002dcd0(struct coord *arg0, s16 *rooms1, struct coord *arg2, s16 *rooms2, u32 arg4);
bool cd0002dcfc(struct coord *pos, s16 *rooms, struct coord *pos2, s16 *rooms2, s16 *rooms3, u32 types, u16 arg6);
s32 cdTestAToB4(struct coord *pos, s16 *rooms, struct coord *pos2, u32 types, u16 arg4);
s32 cd0002de10(struct coord *pos, s16 *rooms, struct coord *pos2, u32 types);
s32 cd0002de34(struct coord *arg0, s16 *arg1, struct coord *arg2, s16 *arg3, u32 types, u16 arg5);
s32 cd0002deac(struct coord *arg0, s16 *arg1, struct coord *arg2, s16 *arg3, u32 types);
bool cd0002ded8(struct coord *arg0, struct coord *arg1, struct prop *prop);
bool cd0002dffc(struct geoblock *arg0, struct geoblock *arg1);
s32 cd0002e278(u8 *start, u8 *end, struct geoblock *ref, u16 flags);
s32 cd0002e4c4(struct geoblock *geo, s16 *rooms, u32 types);
u32 cd0002e680(void);
u32 cd0002e82c(void);
u32 cd0002e9d8(void);
u32 cd0002eb84(void);
bool cd0002ed30(u8 *start, u8 *end, struct geoblock *tile, s32 numvertices, struct coord *arg4, struct coord *arg5, s32 arg6, struct prop *prop);
s32 cd0002f02c(struct geoblock *block, s16 *rooms, s32 types);
bool cd0002f308(struct coord *viewpos, s16 *rooms, struct coord *targetpos, f32 distance, s32 arg4, u16 arg5);
bool cd0002f450(struct coord *viewpos, s16 *rooms, struct coord *targetpos, f32 distance, s32 arg4);

#endif
