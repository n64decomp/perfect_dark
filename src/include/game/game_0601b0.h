#ifndef IN_GAME_GAME_0601B0_H
#define IN_GAME_GAME_0601B0_H
#include <ultra64.h>
#include "types.h"

u32 func0f0601b0(void);
void propHide(struct prop *prop);
u32 func0f060300(struct prop *prop);
struct prop *propAllocate(void);
void propFree(struct prop *prop);
void func0f0604bc(struct prop *prop);
void func0f060538(struct prop *prop);
void func0f0605c4(struct prop *prop);
void propReparent(struct prop *mover, struct prop *adopter);
void propDetach(struct prop *prop);
u32 func0f06071c(void);
u32 func0f0607c8(void);
u32 func0f060984(void);
u32 func0f060bac(void);
u32 func0f060db8(void);
u32 func0f061d54(void);
u32 func0f061ed4(void);
u32 func0f061fa8(void);
u32 func0f062270(void);
u32 func0f062794(void);
u32 func0f062b2c(void);
void func0f062b64(struct prop *prop, s32 arg1);
u32 func0f062cbc(void);
u32 func0f062dd0(void);
u32 func0f062e74(void);
u32 func0f062ef8(void);
u32 func0f062fac(void);
u32 func0f06302c(void);
u32 func0f063dcc(void);
void func0f064178(struct prop *prop, bool enable);
u32 func0f0641f4(void);
u32 func0f06438c(void);
u32 func0f064a24(void);
u32 func0f064ce8(void);
u32 func0f0654e8(void);
u32 func0f06554c(void);
void func0f0657a4(s16 *room, s16 *rooms);
u32 func0f0657d8(void);
bool arrayIntersects(s16 *a, s16 *b);
u32 func0f0658e8(void);
u32 func0f06593c(void);
u32 func0f0659e4(void);
u32 func0f065ae0(void);
void func0f065c44(struct prop *prop);
void func0f065cb0(struct prop *prop);
u32 func0f065d1c(void);
u32 func0f065dd8(void);
u32 func0f065dfc(void);
void func0f065e74(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms);
u32 func0f065e98(void);
void roomGetProps(s16 *room, s16 *propnums, u32 size);
u32 func0f066054(void);
void propGetBbox(struct prop *prop, f32 *width, f32 *ymax, f32 *ymin);
u32 func0f066290(void);

#endif
