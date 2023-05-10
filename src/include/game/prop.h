#ifndef IN_GAME_PROP_H
#define IN_GAME_PROP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern f32 g_AutoAimScale;

void propsTick(void);

void propsStop(void);

void propsSort(void);
void propDisable(struct prop *prop);
struct prop *propAllocate(void);
void propFree(struct prop *prop);
void propActivate(struct prop *prop);
void propActivateThisFrame(struct prop *prop);
void propDelist(struct prop *prop);
void propReparent(struct prop *mover, struct prop *adopter);
void propDetach(struct prop *prop);
Gfx *propsRender(Gfx *gdl, s16 renderroomnum, s32 renderpass, s16 *roomnumsbyprop);
void weaponPlayWhooshSound(s32 weaponnum, struct prop *prop);
struct prop *func0f061d54(s32 handnum, u32 arg1, u32 arg2);
void func0f061fa8(struct shotdata *shotdata, struct prop *prop, f32 arg2, s32 hitpart, struct modelnode *node, struct hitthing *hitthing, s32 arg6, struct modelnode *arg7, struct model *model, bool arg9, s32 arg10, struct coord *arg11, struct coord *arg12);
void handsTickAttack(void);
void propExecuteTickOperation(struct prop *prop, s32 op);
bool currentPlayerInteract(bool eyespy);
void propUnpause(struct prop *prop);
void propsTickPlayer(bool islastplayer);
void propsTickPadEffects(void);
void propSetPerimEnabled(struct prop *prop, bool enable);
void propsTestForPickup(void);
void autoaimTick(void);
u32 propDoorGetCdTypes(struct prop *prop);
bool propIsOfCdType(struct prop *prop, u32 types);
void roomsCopy(s16 *srcrooms, s16 *dstrooms);
void roomsAppend(s16 *newrooms, s16 *dstrooms, s32 maxlen);
bool arrayIntersects(s16 *a, s16 *b);
void propDeregisterRooms(struct prop *prop);
void propRegisterRooms(struct prop *prop);
void func0f065d1c(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms, s16 *morerooms, u32 arg5);
void func0f065dd8(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms);
void func0f065dfc(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms, s16 *morerooms, u32 arg5);
void func0f065e74(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms);
void func0f065e98(struct coord *pos, s16 *rooms, struct coord *pos2, s16 *rooms2);
void roomGetProps(s16 *room, s16 *propnums, s32 len);
void propGetBbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin);
bool propUpdateGeometry(struct prop *prop, u8 **start, u8 **end);

static inline void propEnable(struct prop *prop)
{
	prop->flags |= PROPFLAG_ENABLED;
}

#endif
