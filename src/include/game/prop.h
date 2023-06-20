#ifndef IN_GAME_PROP_H
#define IN_GAME_PROP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern f32 g_AutoAimScale;

void propsTick(void);

void propsStop(void);

void propsSort(void);
void propEnable(struct prop *prop);
void propDisable(struct prop *prop);
struct prop *propAllocate(void);
void propFree(struct prop *prop);
void propActivate(struct prop *prop);
void propActivateThisFrame(struct prop *prop);
void propDelist(struct prop *prop);
void propReparent(struct prop *mover, struct prop *adopter);
void propDetach(struct prop *prop);
Gfx *propRender(Gfx *gdl, struct prop *prop, bool xlupass);
Gfx *propsRender(Gfx *gdl, RoomNum renderroomnum, s32 renderpass, RoomNum *roomnumsbyprop);
void weaponPlayWhooshSound(s32 weaponnum, struct prop *prop);
void func0f060bac(s32 weaponnum, struct prop *prop);
struct prop *shotCalculateHits(s32 handnum, bool arg1, struct coord *arg2, struct coord *arg3, struct coord *gunpos, struct coord *dir, u32 arg6, f32 arg7, bool arg8);
struct prop *func0f061d54(s32 handnum, u32 arg1, u32 arg2);
void shotCreate(s32 handnum, bool arg1, bool dorandom, s32 arg3, bool arg4);
void func0f061fa8(struct shotdata *shotdata, struct prop *prop, f32 arg2, s32 hitpart, struct modelnode *node, struct hitthing *hitthing, s32 arg6, struct modelnode *arg7, struct model *model, bool arg9, s32 arg10, struct coord *arg11, struct coord *arg12);
void handInflictMeleeDamage(s32 handnum, struct gset *gset, bool arg2);
void handTickAttack(s32 handnum);
void handsTickAttack(void);
void propExecuteTickOperation(struct prop *prop, s32 op);
struct prop *propFindForInteract(bool eyespy);
void propFindForUplink(void);
bool currentPlayerInteract(bool eyespy);
void propPause(struct prop *prop);
void propUnpause(struct prop *prop);
void propsTickPlayer(bool islastplayer);
void propsTickPadEffects(void);
void propSetPerimEnabled(struct prop *prop, bool enable);
void propsTestForPickup(void);
f32 func0f06438c(struct prop *prop, struct coord *arg1, f32 *arg2, f32 *arg3, f32 *arg4, bool throughobjects, bool cangangsta, s32 arg7);
void farsightChooseTarget(void);
void autoaimTick(void);
u32 propDoorGetCdTypes(struct prop *prop);
bool propIsOfCdType(struct prop *prop, u32 types);
void roomsCopy(RoomNum *srcrooms, RoomNum *dstrooms);
void roomsAppend(RoomNum *newrooms, RoomNum *dstrooms, s32 maxlen);
bool arrayIntersects(RoomNum *a, RoomNum *b);
bool propTryAddToChunk(s16 propnum, s32 chunkindex);
s32 roomAllocatePropListChunk(s32 room, s32 arg1);
void propRegisterRoom(struct prop *prop, RoomNum room);
void propDeregisterRoom(struct prop *prop, RoomNum room);
void propDeregisterRooms(struct prop *prop);
void propRegisterRooms(struct prop *prop);
void func0f065d1c(struct coord *pos, RoomNum *rooms, struct coord *newpos, RoomNum *newrooms, RoomNum *morerooms, u32 arg5);
void func0f065dd8(struct coord *pos, RoomNum *rooms, struct coord *newpos, RoomNum *newrooms);
void func0f065dfc(struct coord *pos, RoomNum *rooms, struct coord *newpos, RoomNum *newrooms, RoomNum *morerooms, u32 arg5);
void func0f065e74(struct coord *pos, RoomNum *rooms, struct coord *newpos, RoomNum *newrooms);
void func0f065e98(struct coord *pos, RoomNum *rooms, struct coord *pos2, RoomNum *rooms2);
void roomGetProps(RoomNum *room, s16 *propnums, s32 len);
void propsDefragRoomProps(void);
void propGetBbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin);
bool propUpdateGeometry(struct prop *prop, u8 **start, u8 **end);

#endif
