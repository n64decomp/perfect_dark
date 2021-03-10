#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_000000.h"
#include "game/prop.h"
#include "game/game_015470.h"
#include "game/hudmsg.h"
#include "lib/lib_0c000.h"
#include "lib/main.h"
#include "lib/lib_3e730.h"
#include "gvars/gvars.h"
#include "stagesetup.h"
#include "data.h"
#include "types.h"

u32 var8005ce00 = 0x00000000;
u32 var8005ce04 = 0x00000000;
u32 var8005ce08 = 0x00000000;
u32 var8005ce0c = 0x00000000;
u8 *g_StackStartAddrs[7] = {0};
u8 *g_StackEndAddrs[7] = {0};
u8 *g_StackAllocatedPos = (u8 *)0x80400000;
u32 var8005ce4c = 0x00000002;
u32 var8005ce50 = 0x10000000;
u32 var8005ce54 = 0x00000000;
u32 var8005ce58 = 0x00000000;
u32 var8005ce5c = 0x00000000;
u32 var8005ce60 = 0x00000000;
u32 var8005ce64 = 0x00000000;
u32 var8005ce68 = 0x00000000;
u32 var8005ce6c = 0x02aea540;
u32 var8005ce70 = 0x00000000;
s32 var8005ce74 = 0;
f32 var8005ce78[2] = {1, 1};
f32 var8005ce80[2] = {1, 1};
u32 var8005ce88[2] = {0};
s32 var8005ce90 = 3;
u32 var8005ce94 = 0x00000001;
u32 var8005ce98 = 0x00000000;
u32 var8005ce9c = 0x00000000;
u32 var8005cea0 = 0x00000000;
u32 var8005cea4 = 0x00000000;
OSMesg var8005cea8 = (OSMesg)0x00040000;
u32 var8005ceac = 0x00000000;
u32 var8005ceb0 = 0x00000000;
u32 var8005ceb4 = 0x00000000;
u32 var8005ceb8 = 0x00000000;
u32 var8005cebc = 0x00000000;
u32 var8005cec0 = 0x00000000;
u32 var8005cec4 = 0x00000000;
u32 var8005cec8 = 0x00000001;
u32 var8005cecc = 0x00000000;
s8 var8005ced0 = 0x00000000;
u32 var8005ced4 = 0x00000000;
u32 var8005ced8 = 0x00000000;
u32 var8005cedc = 0x00000000;
u32 __osViDevMgr = 0x00000000;
u32 var8005cee4 = 0x00000000;
u32 var8005cee8 = 0x00000000;
u32 var8005ceec = 0x00000000;
u32 var8005cef0 = 0x00000000;
u32 var8005cef4 = 0x00000000;
u32 var8005cef8 = 0x00000000;
u32 var8005cefc = 0x00000000;
OSDevMgr __osPiDevMgr = {0};
u32 var8005cf1c = 0x00000000;
u32 __osCurrentHandle = (u32) &var800902a0;
u32 var8005cf24 = (u32) &var80090318;
u32 var8005cf28 = 0x00000000;
u32 var8005cf2c = 0x00000000;
u32 var8005cf30 = 0x00000000;
u32 var8005cf34 = 0x00000000;
u32 var8005cf38 = 0x00000000;
u32 var8005cf3c = 0x00000000;
u32 var8005cf40 = 0x00000000;
u32 var8005cf44 = 0x00000000;
u32 var8005cf48 = 0x00000000;
u32 var8005cf4c = 0x00000000;
u32 var8005cf50 = 0x00000000;
u32 var8005cf54 = 0x00000000;
u32 var8005cf58 = 0x00000000;
u32 var8005cf5c = 0x00000000;
OSTime osClockRate = 62500000;

#if !PAL
s32 osViClock = VI_NTSC_CLOCK;
#endif

u32 _osShutdown = 0;
u32 __osGlobalIntMask = OS_IM_ALL;

#if VERSION < VERSION_PAL_FINAL
u32 var8005cf74 = 0x00000000;
u32 var8005cf78 = 0x00000000;
u32 var8005cf7c = 0x00000000;
u32 var8005cf80 = 0x00000000;
#endif

u32 var8005cf84 = 0x00000000;
u32 var8005cf88 = 0x00000000;
u32 var8005cf8c = 0x00000000;
