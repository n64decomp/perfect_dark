#ifndef IN_GAME_PROP_H
#define IN_GAME_PROP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern f32 var80069880;

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
Gfx *propRender(Gfx *gdl, struct prop *prop, bool withalpha);
Gfx *propsRender(Gfx *gdl, s16 arg1, s32 arg2, s16 *arg3);
void weaponPlayWhooshSound(s32 weaponnum, struct prop *prop);
void func0f060bac(s32 weaponnum, struct prop *prop);
struct prop *shotCalculateHits(s32 handnum, bool arg1, struct coord *arg2, struct coord *arg3, struct coord *gunpos, struct coord *dir, u32 arg6, f32 arg7, bool arg8);
struct prop *func0f061d54(s32 handnum, u32 arg1, u32 arg2);
void handCreateBulletRaycast(s32 handnum, bool arg1, bool dorandom, s32 arg3, bool arg4);
void func0f061fa8(struct shotdata *shotdata, struct prop *prop, f32 arg2, s32 arg3, struct modelnode *node, void *arg5, s32 arg6, struct modelnode *arg7, struct model *model, s32 arg9, s32 arg10, void *arg11, void *arg12);
void handInflictCloseRangeDamage(s32 handnum, struct gset *gset, bool arg2);
void handTickAttack(s32 handnum);
void handsTickAttack(void);
void propExecuteTickOperation(struct prop *prop, s32 op);
struct prop *propFindForInteract(bool eyespy);
void propFindForUplink(void);
bool currentPlayerInteract(bool eyespy);
void propPause(struct prop *prop);
void propUnpause(struct prop *prop);
void propsTick(u32 islastplayer);
void propsTickPadEffects(void);
void propSetCollisionsEnabled(struct prop *prop, bool enable);
void func0f0641f4(void);
f32 func0f06438c(struct prop *prop, struct coord *arg1, f32 *arg2, f32 *arg3, f32 *arg4, s32 arg5, bool cangangsta, s32 arg7);
void farsightChooseTarget(void);
void autoaimTick(void);
u32 propDoorGetCdTypes(struct prop *prop);
bool propIsOfCdType(struct prop *prop, u32 types);
void roomsCopy(s16 *srcrooms, s16 *dstrooms);
void roomsAppend(s16 *newrooms, s16 *dstrooms, s32 maxlen);
bool arrayIntersects(s16 *a, s16 *b);
bool propTryAddToChunk(s16 propnum, s32 chunkindex);
s32 roomAllocatePropListChunk(s32 room, s32 arg1);
void propRegisterRoom(struct prop *prop, s16 room);
void propDeregisterRoom(struct prop *prop, s16 room);
void propDeregisterRooms(struct prop *prop);
void propRegisterRooms(struct prop *prop);
void func0f065d1c(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms, s16 *morerooms, u32 arg5);
void func0f065dd8(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms);
void func0f065dfc(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms, s16 *morerooms, u32 arg5);
void func0f065e74(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms);
void func0f065e98(struct coord *pos, s16 *rooms, struct coord *pos2, s16 *rooms2);
void roomGetProps(s16 *room, s16 *propnums, s32 len);
void propsDefragRoomProps(void);
void propGetBbox(struct prop *prop, f32 *width, f32 *ymax, f32 *ymin);
bool propUpdateGeometry(struct prop *prop, u8 **start, u8 **end);

#endif
