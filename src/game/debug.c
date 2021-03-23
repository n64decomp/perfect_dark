#include <ultra64.h>
#include "constants.h"
#include "game/debug.h"
#include "bss.h"
#include "data.h"
#include "types.h"

/**
 * This file is used by ntsc-1.0 and above which has the debug functions
 * ifdeffed out.
 *
 * ntsc-beta's debug implementations are in debug1.c and debug2.c.
 * Those files are only linked into ntsc-beta.
 *
 * Splitting it like this is temporary due to it being difficult to identify
 * which functions are the same between beta and 1.0.
 */

s32 var80075d60 = 0x00000002;
u32 var80075d64 = 0x00000002;
u32 var80075d68 = 0x00000002;
u32 var80075d6c = 0x00000002;
u32 var80075d70 = 0x00000000;
bool g_DebugTurboMode = false;
s32 var80075d78 = 0;
u32 var80075d7c = 0x00000000;
u32 var80075d80 = 0x00000000;
u32 var80075d84 = 0x00000000;
u32 var80075d88 = 0x00000000;
u32 var80075d8c = 0x00000000;
u32 var80075d90 = 0x00000000;
u32 var80075d94 = 0xbf800000;
u32 var80075d98 = 0x00000000;
u32 var80075d9c = 0x3f800000;
u32 var80075da0 = 0x00000000;
u32 var80075da4 = 0x00000000;
u32 var80075da8 = 0x3f800000;
u32 var80075dac = 0x00000000;
u32 var80075db0 = 0x00000000;
u32 var80075db4 = 0x3f800000;
u32 var80075db8 = 0x00000000;
u32 var80075dbc = 0x00000000;
u32 var80075dc0 = 0x00000000;
u32 var80075dc4 = 0x00000000;
u32 var80075dc8 = 0x00000000;
u32 var80075dcc = 0x00000000;
u32 var80075dd0 = 0x00000000;
u32 var80075dd4 = 0x00000000;
u32 var80075dd8 = 0x3f800000;
u32 var80075ddc = 0x00000000;

void debug0f11ecf0(s32 arg0) // not called
{
	// empty
}

void debug0f11ecf8(s32 arg0, s32 arg1, s32 arg2) // not called
{
	// empty
}

s32 debug0f11ed08(s32 arg0) // not called
{
	return arg0;
}

void debug0f11ed10(s32 arg0, s32 arg1, s32 arg2) // not called
{
	// empty
}

bool debug0f11ed20(void) // not called
{
	return false;
}

void debug0f11ed28(s32 arg0) // not called
{
	// empty
}

void debug0f11ed30(void) // not called
{
	// empty
}

void debug0f11ed38(void) // not called
{
	// empty
}

void debug0f11ed40(void) // not called
{
	// empty
}

void debug0f11ed48(void) // not called
{
	// empty
}

void debug0f11ed50(void) // not called
{
	// empty
}

bool debug0f11ed58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) // not called
{
	return false;
}

/**
 * If 1, would render something but the render function is stubbed.
 */
s32 debug0f11ed70(void)
{
	return 0;
}

bool debugEnableBgRendering(void)
{
	return true;
}

bool debugEnablePropRendering(void)
{
	return true;
}

bool debug0f11ed88(void) // not called
{
	return false;
}

bool debug0f11ed90(void) // not called
{
	return false;
}

void debug0f11ed98(s32 arg0) // not called
{
	// empty
}

bool debug0f11eda0(void) // not called
{
	return false;
}

bool debug0f11eda8(void) // not called
{
	return false;
}

bool debug0f11edb0(void)
{
	return false;
}

bool debug0f11edb8(void)
{
	return false;
}

bool debugIsRoomStateDebugEnabled(void)
{
	return false;
}

s32 debug0f11edc8(void) // not called
{
	return var80075d70;
}

void debug0f11edd4(s32 arg0) // not called
{
	var80075d70 = arg0;
}

bool debug0f11ede0(void) // not called
{
	return false;
}

bool debug0f11ede8(void) // not called
{
	return false;
}

bool debug0f11edf0(void) // not called
{
	return false;
}

void debug0f11edf8(void) // not called
{
	// empty
}

void debug0f11ee00(void) // not called
{
	// empty
}

s32 debugIsTurboModeEnabled(void)
{
	return g_DebugTurboMode;
}

void debugSetTurboMode(bool enabled) // not called
{
	g_DebugTurboMode = enabled;
}

bool debugForceAllObjectivesComplete(void)
{
	return false;
}

bool debug0f11ee28(void)
{
	return false;
}

bool debug0f11ee30(void) // not called
{
	return false;
}

bool debug0f11ee38(void) // not called
{
	return false;
}

bool debug0f11ee40(void)
{
	return false;
}

bool debug0f11ee48(void) // not called
{
	return false;
}

bool debug0f11ee50(void) // not called
{
	return false;
}

bool debug0f11ee58(void) // not called
{
	return false;
}

bool debug0f11ee60(void) // not called
{
	return false;
}

bool debug0f11ee68(void) // not called
{
	return false;
}

u32 debugGetSlowMotion(void)
{
	return SLOWMOTION_OFF;
}

bool debug0f11ee78(void) // not called
{
	return false;
}

bool debug0f11ee80(void) // not called
{
	return false;
}

bool debug0f11ee88(void)
{
	return false;
}

bool debug0f11ee90(void)
{
	return false;
}

bool debug0f11ee98(void) // not called
{
	return false;
}

bool debug0f11eea0(void) // not called
{
	return false;
}

bool debug0f11eea8(void)
{
	return false;
}

bool debugDangerousProps(void)
{
	return false;
}

bool debug0f11eeb8(void) // not called
{
	return false;
}

bool debug0f11eec0(void) // not called
{
	return false;
}

bool debug0f11eec8(void) // not called
{
	return false;
}

bool debug0f11eed0(void) // not called
{
	return false;
}

s32 debugGetMotionBlur(void)
{
	return 0;
}

bool debug0f11eee0(void) // not called
{
	return false;
}

u32 dprint()
{
	return 0;
}

bool debug0f11eef0(void) // not called
{
	return false;
}

bool debugEnableFootsteps(void)
{
	return true;
}

bool debug0f11ef00(void) // not called
{
	return false;
}

bool debug0f11ef08(void) // not called
{
	return false;
}

bool debug0f11ef10(void) // not called
{
	return false;
}

bool debug0f11ef18(void) // not called
{
	return false;
}

bool debug0f11ef20(void) // not called
{
	return false;
}

bool debug0f11ef28(void) // not called
{
	return false;
}

bool debug0f11ef30(void) // not called
{
	return false;
}

bool debug0f11ef38(void) // not called
{
	return false;
}

bool debug0f11ef40(void) // not called
{
	return false;
}

bool debugAllowEndLevel(void)
{
	return true;
}

bool debug0f11ef50(void) // not called
{
	return false;
}

bool debug0f11ef58(void) // not called
{
	return false;
}

bool debug0f11ef60(void) // not called
{
	return false;
}

bool debug0f11ef68(void) // not called
{
	return false;
}

bool debug0f11ef70(void) // not called
{
	return false;
}

bool debug0f11ef78(void)
{
	return false;
}

bool debug0f11ef80(void)
{
	return false;
}

bool debug0f11ef88(void) // not called
{
	return false;
}

bool debug0f11ef90(void) // not called
{
	return false;
}

void debug0f11ef98(s32 arg0) // not called
{
	// empty
}

void debug0f11efa0(void) // not called
{
	// empty
}

void debug0f11efa8(void) // not called
{
	// empty
}
