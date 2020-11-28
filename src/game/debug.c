#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/debug.h"
#include "gvars/gvars.h"
#include "types.h"

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

void debug0f11ecf0(s32 arg0)
{
	// empty
}

void debug0f11ecf8(s32 arg0, s32 arg1, s32 arg2)
{
	// empty
}

s32 debug0f11ed08(s32 arg0)
{
	return arg0;
}

void debug0f11ed10(s32 arg0, s32 arg1, s32 arg2)
{
	// empty
}

bool debug0f11ed20(void)
{
	return false;
}

void debug0f11ed28(s32 arg0)
{
	// empty
}

void debug0f11ed30(void)
{
	// empty
}

void debug0f11ed38(void)
{
	// empty
}

void debug0f11ed40(void)
{
	// empty
}

void debug0f11ed48(void)
{
	// empty
}

void debug0f11ed50(void)
{
	// empty
}

bool debug0f11ed58(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
	return false;
}

s32 debug0f11ed70(void)
{
	return 0;
}

bool debug0f11ed78(void)
{
	return true;
}

bool debug0f11ed80(void)
{
	return true;
}

bool debug0f11ed88(void)
{
	return false;
}

bool debug0f11ed90(void)
{
	return false;
}

void debug0f11ed98(s32 arg0)
{
	// empty
}

bool debug0f11eda0(void)
{
	return false;
}

bool debug0f11eda8(void)
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

bool debug0f11edc0(void)
{
	return false;
}

s32 debug0f11edc8(void)
{
	return var80075d70;
}

void debug0f11edd4(s32 arg0)
{
	var80075d70 = arg0;
}

bool debug0f11ede0(void)
{
	return false;
}

bool debug0f11ede8(void)
{
	return false;
}

bool debug0f11edf0(void)
{
	return false;
}

void debug0f11edf8(void)
{
	// empty
}

void debug0f11ee00(void)
{
	// empty
}

s32 debugIsTurboModeEnabled(void)
{
	return g_DebugTurboMode;
}

void debugSetTurboMode(bool enabled)
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

bool debug0f11ee30(void)
{
	return false;
}

bool debug0f11ee38(void)
{
	return false;
}

bool debug0f11ee40(void)
{
	return false;
}

bool debug0f11ee48(void)
{
	return false;
}

bool debug0f11ee50(void)
{
	return false;
}

bool debug0f11ee58(void)
{
	return false;
}

bool debug0f11ee60(void)
{
	return false;
}

bool debug0f11ee68(void)
{
	return false;
}

u32 debugGetSlowMotion(void)
{
	return SLOWMOTION_OFF;
}

bool debug0f11ee78(void)
{
	return false;
}

bool debug0f11ee80(void)
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

bool debug0f11ee98(void)
{
	return false;
}

bool debug0f11eea0(void)
{
	return false;
}

bool debug0f11eea8(void)
{
	return false;
}

bool debug0f11eeb0(void)
{
	return false;
}

bool debug0f11eeb8(void)
{
	return false;
}

bool debug0f11eec0(void)
{
	return false;
}

bool debug0f11eec8(void)
{
	return false;
}

bool debug0f11eed0(void)
{
	return false;
}

s32 debugGetMotionBlur(void)
{
	return 0;
}

bool debug0f11eee0(void)
{
	return false;
}

u32 dprint()
{
	return 0;
}

bool debug0f11eef0(void)
{
	return false;
}

bool debug0f11eef8(void)
{
	return true;
}

bool debug0f11ef00(void)
{
	return false;
}

bool debug0f11ef08(void)
{
	return false;
}

bool debug0f11ef10(void)
{
	return false;
}

bool debug0f11ef18(void)
{
	return false;
}

bool debug0f11ef20(void)
{
	return false;
}

bool debug0f11ef28(void)
{
	return false;
}

bool debug0f11ef30(void)
{
	return false;
}

bool debug0f11ef38(void)
{
	return false;
}

bool debug0f11ef40(void)
{
	return false;
}

bool debugAllowEndLevel(void)
{
	return true;
}

bool debug0f11ef50(void)
{
	return false;
}

bool debug0f11ef58(void)
{
	return false;
}

bool debug0f11ef60(void)
{
	return false;
}

bool debug0f11ef68(void)
{
	return false;
}

bool debug0f11ef70(void)
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

bool debug0f11ef88(void)
{
	return false;
}

bool debug0f11ef90(void)
{
	return false;
}

void debug0f11ef98(s32 arg0)
{
	// empty
}

void debug0f11efa0(void)
{
	// empty
}

void debug0f11efa8(void)
{
	// empty
}

void debug0f11efb0(s32 arg0, s32 arg1)
{
	// empty
}

void debug0f11efbc(s32 arg0)
{
	// empty
}

s32 debug0f11efc4(s32 arg0)
{
	return arg0;
}

void debug0f11efcc(void)
{
	// empty
}

void debug0f11efd4(void)
{
	// empty
}

void debug0f11efdc(s32 arg0)
{
	// empty
}
