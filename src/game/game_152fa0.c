#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s32 func0f152fa0(f32 arg0)
{
	u32 result;

	if (arg0 > 32767.9f) {
		arg0 = 32767.9f;
	}

	if (arg0 < -32767.9f) {
		arg0 = -32767.9f;
	}

	if (arg0 < 0) {
		result = arg0 * -65536;
		result = -result;
	} else {
		result = 65536 * arg0;
	}

	return result;
}

Gfx *func0f153134(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

	return gdl;
}
