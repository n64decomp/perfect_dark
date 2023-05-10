#ifndef IN_GAME_DLIGHTS_H
#define IN_GAME_DLIGHTS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u8 func0f0009c0(s32 roomnum);
u8 func0f000a10(s32 roomnum);
u8 func0f000b24(s32 roomnum);
s32 func0f000c54(s32 roomnum);
f32 roomGetUnk5c(s32 roomnum);
f32 func0f000dbc(s32 roomnum);
bool lightGetBboxCentre(s32 roomnum, u32 lightnum, struct coord *pos);
bool lightIsHealthy(s32 roomnum, s32 lightnum);
bool lightIsVulnerable(s32 roomnum, s32 lightnum);
bool lightIsOn(s32 roomnum, s32 lightnum);
void roomSetUnk52(s32 roomnum, s32 value);
Gfx *lightsSetForRoom(Gfx *gdl, s16 roomnum);
Gfx *lightsSetDefault(Gfx *gdl);
void roomInitLights(s32 roomnum);
bool lightsHandleHit(struct coord *gunpos, struct coord *hitpos, s32 roomnum);
void roomSetLightsFaulty(s32 roomnum, s32 chance);
void roomSetLightBroken(s32 roomnum, s32 lightnum);
void lightsReset(void);
void func0f001c0c(void);
void func0f002a98(void);
void roomSetLightsOn(s32 roomnum, s32 enable);
void roomSetLighting(s32 roomnum, s32 operation, u8 arg2, u8 arg3, u8 arg4);
bool lightTickBroken(s32 roomnum, s32 lightnum);
void lightingTick(void);
void lightsTick(void);
void roomAdjustLighting(s32 roomnum, s32 start, s32 limit);
void roomHighlight(s32 roomnum);
void func0f0056f4(s32 room1, struct coord *coord1, s32 room2, struct coord *coord2, s32 arg4, f32 *arg5, s32 arg6);

#endif
