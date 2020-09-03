#ifndef IN_GAME_DLIGHTS_H
#define IN_GAME_DLIGHTS_H
#include <ultra64.h>
#include "types.h"

u32 func0f000920(void);
struct light *roomGetLight(s32 roomnum, s32 lightnum);
u8 func0f0009c0(s32 roomnum);
u8 func0f000a10(s32 roomnum);
u8 func0f000b24(s32 roomnum);
u8 roomGetBrightness(s32 room);
s32 func0f000c54(s32 roomnum);
f32 roomGetUnk5c(s32 roomnum);
f32 func0f000dbc(s32 roomnum);
bool lightGetBboxCentre(s32 roomnum, u32 lightnum, struct coord *pos);
bool lightIsHealthy(s32 roomnum, s32 lightnum);
bool lightIsVulnerable(s32 roomnum, s32 lightnum);
bool lightIsOn(s32 roomnum, s32 lightnum);
void roomSetUnk52(s32 roomnum, s32 value);
void roomSetDefaults(struct room *room);
u32 func0f001138(void);
u32 func0f001300(void);
void roomInitLights(s32 roomnum);
u32 func0f001734(void);
void roomSetLightsFaulty(s32 roomnum, s32 chance);
void roomSetLightBroken(s32 roomnum, s32 lightnum);
void func0f001bdc(void);
u32 func0f001c0c(void);
u32 func0f00215c(void);
u32 func0f0023b8(void);
u32 func0f00259c(void);
u32 func0f002844(void);
void func0f002a98(void);
void roomSetLightsOn(s32 roomnum, s32 enable);
void roomSetLighting(s32 roomnum, s32 operation, u8 arg2, u8 arg3, u8 arg4);
u32 func0f002ef8(void);
void func0f0033b0(void);
void func0f003444(void);
u32 func0f0035c0(void);
u32 func0f00372c(void);
void func0f0037ac(void);
u32 func0f004314(void);
u32 func0f00438c(void);
u32 func0f004558(void);
u32 func0f004604(void);
void func0f004c6c(void);
u32 func0f00505c(void);
u32 func0f0053d0(void);
void func0f0056f4(s32 room1, struct coord *coord1, s32 room2, struct coord *coord2, s32 arg4, f32 *arg5, s32 arg6);
u32 func0f005bb0(void);

#endif
