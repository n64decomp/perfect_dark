#ifndef IN_GAME_BG_H
#define IN_GAME_BG_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func0f158108(s32 roomnum, u8 *arg1, u8 *arg2);
struct var800a4640_00 *func0f158140(s32 roomnum);
Gfx *bgRenderSceneInXray(Gfx *gdl);
Gfx *bgRenderArtifacts(Gfx *gdl);
s32 stageGetIndex2(s32 stagenum);
f32 portal0f15b274(s32 portal);
void bgReset(s32 stagenum);
void bgBuildTables(s32 stagenum);
void bgStop(void);
void func0f15c880(f32 arg0);
f32 func0f15c888(void);
void currentPlayerSetScaleBg2Gfx(f32 arg0);
void func0f15c920(void);
void bgTick(void);
Gfx *bgRender(Gfx *gdl);
Gfx *currentPlayerScissorToViewport(Gfx *gdl);
Gfx *currentPlayerScissorWithinViewport(Gfx *gdl, s32 viewleft, s32 viewtop, s32 viewright, s32 viewbottom);
Gfx *boxRenderBorder(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2);
void boxCopy(struct screenbox *dst, struct screenbox *src);
bool roomIsOnscreen(s32 room);
bool roomIsStandby(s32 room);
bool roomIsOnPlayerScreen(s32 room, u32 playernum);
bool roomIsOnPlayerStandby(s32 room, u32 aibotindex);
s32 portalFindNumByVertices(struct portalvertices *pvertices);
u32 bgInflate(u8 *src, u8 *dst, u32 len);
void bgGarbageCollectRooms(s32 bytesneeded, bool desparate);
bool func0f15f20c(struct coord *arg0, struct coord *arg1, s32 *arg2, s32 *arg3);
bool bgTestLineIntersectsBbox(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3);
bool bgTestHitOnObj(struct coord *arg0, struct coord *arg1, struct coord *arg2, Gfx *gdl, Gfx *gdl2, struct gfxvtx *vertices, struct hitthing *hitthing);
bool bgTestHitOnChr(struct model *model, struct coord *arg1, struct coord *arg2, struct coord *arg3, Gfx *arg4, Gfx *arg5, struct gfxvtx *vertices, f32 *arg7, struct hitthing *hitthing);
bool bgTestHitInRoom(struct coord *frompos, struct coord *topos, s32 roomnum, struct hitthing *hitthing);
bool roomIsLoaded(s32 room);
bool roomContainsCoord(struct coord *pos, s16 roomnum);
bool func0f162128(struct coord *arg0, s16 roomnum);
void bgFindRoomsByPos(struct coord *pos, s16 *inrooms, s16 *aboverooms, s32 max, s16 *bestroom);
s32 roomsGetActive(s16 *rooms, s32 len);
s32 roomGetNeighbours(s32 room, s16 *rooms, s32 len);
bool roomsAreNeighbours(s32 roomnum1, s32 roomnum2);
void portalSetOpen(s32 portal, bool open);
s32 bg0f164e8c(struct coord *arg0, struct coord *arg1);
bool bgIsBboxOverlapping(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3);
void portalFindBbox(s32 portalnum, struct coord *bbmin, struct coord *bbmax);
void bgFindEnteredRooms(struct coord *bbmin, struct coord *upper, s16 *rooms, s32 maxlen, bool arg4);
void bgPreload(void);

#endif
