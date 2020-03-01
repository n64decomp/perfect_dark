#ifndef IN_GAME_GAME_0C79F0_H
#define IN_GAME_GAME_0C79F0_H
#include <ultra64.h>
#include "types.h"

u32 func0f0c79f0(void);
u32 func0f0c7a00(void);
void currentPlayerSetAutoAimY(bool enabled);
bool currentPlayerIsAutoAimYEnabled(void);
u32 func0f0c7a8c(void);
bool currentPlayerIsInSightAimMode(void);
void currentPlayerUpdateAutoAimYProp(struct prop *prop, f32 autoaimy);
void currentPlayerSetAutoAimX(bool enabled);
bool currentPlayerIsAutoAimXEnabled(void);
u32 func0f0c7bd0(void);
void currentPlayerUpdateAutoAimXProp(struct prop *prop, f32 autoaimx);
struct prop *currentPlayerGetHoverbike(void);
struct prop *currentPlayerGetGrabbedProp(void);
void currentPlayerGrabProp(struct prop *prop);
void currentPlayerSetMoveMode(u32 movemode);
void setMoveModeForAllPlayers(u32 movemode);
void func0f0c7f2c(void);
void func0f0c7f98(void);
void func0f0c8004(void);
f32 func0f0c805c(f32 value);
void currentPlayerUpdateSpeedVerta(f32 value);
f32 func0f0c82f8(f32 value);
void func0f0c8394(f32 value);
u32 func0f0c8598(void);
u32 func0f0c8aa8(void);
void func0f0c8b90(bool arg0, bool arg1, bool arg2, bool arg3);
void func0f0cb79c(struct player *player, struct coord *arg1, s16 *rooms);
void func0f0cb89c(struct player *player, s16 *rooms);
void func0f0cb8c4(struct player *player);
void func0f0cb904(struct coord *coord);
void func0f0cba88(f32 *a, f32 *b, struct coord *c, f32 mult1, f32 mult2);
void currentPlayerUpdateMoveInitSpeed(struct coord *newpos);
void currentPlayerUpdateFootsteps(bool arg0, bool arg1, bool arg2, bool arg3);
void func0f0cbf50(void);
u32 func0f0cc19c(void);
u32 func0f0cc3b8(void);
u32 func0f0cc654(void);
u32 func0f0cc680(void);
u32 func0f0cc6ac(void);

#endif
