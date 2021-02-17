#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "data.h"
#include "types.h"

Gfx *func0f01afc0(Gfx *gdl)
{
	gDPSetCycleType(gdl++, G_CYC_FILL);
	gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viGetX(), osVirtualToPhysical((void *)viGetUnk28()));
	gDPSetFillColor(gdl++, 0x00010001);
	gDPFillRectangle(gdl++, 0, 0, viGetX() - 1, viGetY() - 1);

	return gdl;
}
