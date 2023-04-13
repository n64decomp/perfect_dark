#ifndef IN_GAME_DLIGHTS_H
#define IN_GAME_DLIGHTS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 func0f000920(s32 portalnum1, s32 portalnum2);
struct light *roomGetLight(s32 roomnum, s32 lightnum);
u8 roomGetFinalBrightness(s32 roomnum);
u8 roomGetFinalBrightnessForPlayer(s32 roomnum);
u8 roomGetSettledRegionalBrightnessForPlayer(s32 roomnum);
u8 roomGetSettledLocalBrightness(s32 room);
s32 roomGetFlashBrightness(s32 roomnum);
f32 roomGetLightOpCurFrac(s32 roomnum);
f32 roomGetSettledLocalBrightnessFrac(s32 roomnum);
bool lightGetBboxCentre(s32 roomnum, u32 lightnum, struct coord *pos);
bool lightIsHealthy(s32 roomnum, s32 lightnum);
bool lightIsVulnerable(s32 roomnum, s32 lightnum);
bool lightIsOn(s32 roomnum, s32 lightnum);
void roomSetFlashBrightness(s32 roomnum, s32 value);
void roomSetDefaults(struct room *room);
Gfx *lightsSetForRoom(Gfx *gdl, s16 roomnum);
Gfx *lightsSetDefault(Gfx *gdl);
void roomInitLights(s32 roomnum);
bool lightsHandleHit(struct coord *gunpos, struct coord *hitpos, s32 roomnum);
void roomSetLightsFaulty(s32 roomnum, s32 chance);
void roomSetLightBroken(s32 roomnum, s32 lightnum);
void lightsReset(void);
void func0f001c0c(void);
void func0f00215c(u8 *arg0);
void func0f0023b8(void);
void func0f00259c(s32 roomnum);
void func0f002844(s32 roomnum, f32 arg1, s32 arg2, s32 portalnum);
void func0f002a98(void);
void roomSetLightsOn(s32 roomnum, s32 enable);
void roomSetLightOp(s32 roomnum, s32 operation, u8 br_to, u8 br_from, u8 duration60);
bool lightTickBroken(s32 roomnum, s32 lightnum);
void lightingTick(void);
void lightsConfigureForPerfectDarknessCutscene(void);
void lightsConfigureForPerfectDarknessGameplay(void);
void lightsTickPerfectDarkness(void);
void roomsTickLighting(void);
void lightsTick(void);
void roomFlashLighting(s32 roomnum, s32 start, s32 limit);
void roomFlashLocalLighting(s32 roomnum, s32 increment, s32 limit);
void roomHighlight(s32 roomnum);
void func0f004c6c(void);
void func0f00505c(void);
f32 func0f0053d0(s32 room1, struct coord *arg1, s32 portal1, s32 room2, struct coord *arg4, s32 portal2, f32 *arg6);
void func0f0056f4(s32 room1, struct coord *coord1, s32 room2, struct coord *coord2, s32 arg4, f32 *arg5, s32 arg6);
void func0f005bb0(void);

#endif
