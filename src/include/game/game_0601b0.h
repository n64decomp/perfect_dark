#ifndef IN_GAME_GAME_0601B0_H
#define IN_GAME_GAME_0601B0_H
#include <ultra64.h>
#include "types.h"

extern f32 var80069880;

void func0f0601b0(void);
void propShow(struct prop *prop);
void propHide(struct prop *prop);
struct prop *propAllocate(void);
void propFree(struct prop *prop);
void propPrependToList1(struct prop *prop);
void propAppendToList1(struct prop *prop);
void propRemoveFromCurrentList(struct prop *prop);
void propReparent(struct prop *mover, struct prop *adopter);
void propDetach(struct prop *prop);
Gfx *propRender(Gfx *gdl, struct prop *prop, bool withalpha);
Gfx *propsRender(Gfx *gdl, s16 arg1, s32 arg2, s16 *arg3);
u32 func0f060984(void);
u32 func0f060bac(void);
void func0f060db8(s32 handnum, bool arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4, struct coord *arg5, u32 arg6, f32 arg7, bool arg8);
struct prop *func0f061d54(s32 handnum, u32 arg1, u32 arg2);
void handCreateBulletRaycast(s32 handnum, bool arg1, bool arg2, s32 arg3, bool arg4);
u32 func0f061fa8(void);
void handInflictCloseRangeDamage(s32 handnum, struct hand *hand, bool arg2);
void handTickAttack(s32 handnum);
void handsTickAttack(void);
void func0f062b64(struct prop *prop, s32 arg1);
struct prop *currentPlayerFindPropForInteract(bool eyespy);
void func0f062dd0(void);
bool currentPlayerInteract(bool eyespy);
void propPrependToList2(struct prop *prop);
void propMoveFromList2To1(struct prop *prop);
void func0f06302c(ubool arg0);
void func0f063dcc(void);
void func0f064178(struct prop *prop, s32 enable);
void func0f0641f4(void);
u32 func0f06438c(void);
u32 func0f064a24(void);
void func0f064ce8(void);
u32 func0f0654e8(struct prop *prop);
bool func0f06554c(struct prop *prop, u32 flags);
void roomsCopy(s16 *srcrooms, s16 *dstrooms);
void func0f0657d8(s16 *newrooms, s16 *rooms, u32 arg2);
bool arrayIntersects(s16 *a, s16 *b);
bool func0f0658e8(s16 arg0, s32 arg1);
u32 func0f06593c(void);
void func0f0659e4(struct prop *prop, s16 room);
void func0f065ae0(struct prop *prop, s16 room);
void func0f065c44(struct prop *prop);
void func0f065cb0(struct prop *prop);
void func0f065d1c(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms, s16 *morerooms, u32 arg5);
void func0f065dd8(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms);
void func0f065dfc(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms, s16 *morerooms, u32 arg5);
void func0f065e74(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms);
void func0f065e98(struct coord *pos, s16 *rooms, struct coord *pos2, s16 *rooms2);
void roomGetProps(s16 *room, s16 *propnums, u32 size);
u32 func0f066054(void);
void propGetBbox(struct prop *prop, f32 *width, f32 *ymax, f32 *ymin);
bool propUpdateGeometry(struct prop *prop, struct geo **arg1, struct geo **arg2);

#endif
