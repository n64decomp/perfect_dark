#include <ultra64.h>
#include "constants.h"
#include "data.h"
#include "types.h"

f32 var800a6470[16 * 3];

u32 var800a6530;
u32 var800a6534;

#if VERSION < VERSION_NTSC_1_0
u8 var800aacb8nb[0x140];
#endif

struct var800a6538 var800a6538[16];
u32 g_BgRoomTestsDisabled;
u32 var800a65bc;
struct screenbox g_BgCmdScreenBox;
struct screenbox g_PortalScreenBbox;
u32 g_BgCmdThrowing;
s32 g_BgNumLightsChecksum;
s32 g_BgLightsOffsetChecksum;
