#ifndef _IN_GAME_GUNFX_H
#define _IN_GAME_GUNFX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void boltbeamsReset(void);
void lasersightsReset(void);

void beamCreate(struct beam *beam, s32 weaponnum, struct coord *from, struct coord *to);
void beamCreateForHand(s32 handnum);
Gfx *beamRenderGeneric(Gfx *gdl, struct textureconfig *arg1, f32 arg2, struct coord *arg3, u32 colour1, f32 arg5, struct coord *arg6, u32 colour2);
Gfx *func0f0acb90(Gfx *gdl, struct beam *beam, bool arg2, u32 arg3);
void beamTick(struct beam *beam);

struct casing *casingCreate(struct modelfiledata *modeldef, Mtxf *mtx);
void casingCreateForHand(s32 handnum, f32 ground, Mtxf *mtx);
void casingRender(struct casing *casing, Gfx **gdlptr);
void casingsRender(Gfx **gdlptr);

s32 boltbeamFindByProp(struct prop *prop);
s32 boltbeamCreate(struct prop *prop);
void boltbeamSetHeadPos(s32 beamnum, struct coord *pos);
void boltbeamSetTailPos(s32 beamnum, struct coord *pos);
void boltbeamIncrementHeadPos(s32 beamnum, f32 newlength, bool arg2);
void boltbeamSetAutomatic(s32 beamnum, f32 speed);
Gfx *boltbeamsRender(Gfx *gdl);
void boltbeamsTick(void);

bool lasersightExists(s32 id, s32 *index);
Gfx *lasersightRenderDot(Gfx *gdl);
Gfx *lasersightRenderBeam(Gfx *gdl);
void lasersightSetBeam(s32 id, s32 arg1, struct coord *near, struct coord *far);
void lasersightSetDot(s32 arg0, struct coord *pos, struct coord *rot);
void lasersightFree(s32 arg0);

#endif
