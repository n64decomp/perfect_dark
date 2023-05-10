#ifndef _IN_GAME_CHR_CHR_H
#define _IN_GAME_CHR_CHR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern s32 var80062964;

void chrSetChrnum(struct chrdata *chr, s16 chrnum);
void chrCalculatePushPos(struct chrdata *chr, struct coord *pos, s16 *rooms, bool arg3);

#if VERSION >= VERSION_NTSC_1_0
bool chr0f01f264(struct chrdata *chr, struct coord *pos, s16 *rooms, f32 arg3, bool arg4);
#else
bool chr0f01f264(struct chrdata *chr, struct coord *pos, s16 *rooms, f32 arg3);
#endif

s32 chrsGetNumFree(void);
s16 chrsGetNextUnusedChrnum(void);
struct prop *chr0f020b14(struct prop *prop, struct model *model, struct coord *pos, s16 *rooms, f32 arg3, u8 *ailist);
void chrRemove(struct prop *prop, bool removechr);
void chrFlinchBody(struct chrdata *chr);
void chrFlinchHead(struct chrdata *chr, f32 arg1);
void chr0f021fa8(struct chrdata *chr, struct coord *pos, s16 *rooms);
void chr0f0220ec(struct chrdata *chr, s32 lvupdate240, s32 arg2);
void chrUpdateCloak(struct chrdata *chr);
s32 chrGetCloakAlpha(struct chrdata *chr);
void chrSetPoisoned(struct chrdata *chr, struct prop *poisonprop);
bool chrTickBeams(struct prop *prop);
s32 chrTick(struct prop *prop);
void chrDropConcealedItems(struct chrdata *chr);
void chrSetHudpieceVisible(struct chrdata *chr, bool visible);
void chrDropItemsForOwnerReap(struct chrdata *chr);
void chrGetBloodColour(s16 bodynum, u8 *colour1, u32 *colour2);
Gfx *chrRender(struct prop *prop, Gfx *gdl, bool xlupass);
void chrEmitSparks(struct chrdata *chr, struct prop *prop, s32 hitpart, struct coord *coord, struct coord *coord2, struct chrdata *chr2);
void chr0f0260c4(struct model *model, s32 hitpart, struct modelnode *node, struct coord *arg3);
void chrDisfigure(struct chrdata *chr, struct coord *exppos, f32 damageradius);
f32 chr0f0278a4(struct chrdata *chr);
void chr0f027994(struct prop *prop, struct shotdata *shotdata, bool arg2, bool arg3);
void chrHit(struct shotdata *shotdata, struct hit *hit);
void chr0f028498(bool value);
void chrsCheckForNoise(f32 noiseradius);
bool chrCalculateAutoAim(struct prop *prop, struct coord *arg1, f32 *arg2, f32 *arg3);
void shieldhitCreate(struct prop *prop, f32 shield, struct prop *arg2, struct modelnode *node, struct model *model, s32 side, s16 *arg6);
void shieldhitsRemoveByProp(struct prop *prop);
void chr0f0295f8(f32 arg0, s32 *arg1, s32 *arg2, s32 *arg3);
Gfx *shieldhitRender(Gfx *gdl, struct prop *prop1, struct prop *prop2, s32 alpha, bool arg4, s32 cmnum1, s32 cmnum2, s32 cmnum3, s32 cmnum4);
void shieldhitsTick(void);
struct gfxvtx *chrAllocateVertices(s32 numvertices);
void chrsSetVar8006297c(u32 arg0);
u32 chrsGetVar8006297c(void);
void chrsSetVar80062980(u32 arg0);
u32 chrsGetVar80062980(void);
void chrSetPerimEnabled(struct chrdata *chr, bool enable);
void chrSetMaxDamage(struct chrdata *chr, f32 maxdamage);
f32 chrGetMaxDamage(struct chrdata *chr);
void chrAddHealth(struct chrdata *chr, f32 health);
f32 chrGetArmor(struct chrdata *chr);
void chrInit(struct prop *prop, u8 *ailist);
struct prop *chrAllocate(struct model *model, struct coord *pos, s16 *rooms, f32 faceangle, u8 *ailist);
void chrClearReferences(s32 propnum);
void chr0f0220ac(struct chrdata *chr);
void chrCloak(struct chrdata *chr, bool arg1);
void chrUncloak(struct chrdata *chr, bool value);
void chrUncloakTemporarily(struct chrdata *chr);
void chr0f02472c(void);
void chr0f028490(f32 arg1);
struct chrdata *chrFindByLiteralId(s32 chrnum);
struct prop *chrGetHeldUsableProp(struct chrdata *chr, s32 hand);
struct prop *chrGetTargetProp(struct chrdata *chr);
bool chrUpdateGeometry(struct prop *prop, u8 **start, u8 **end);
void chrGetBbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin);

static inline struct prop *chrGetHeldProp(struct chrdata *chr, s32 hand)
{
	return chr->weapons_held[hand];
}

#endif
