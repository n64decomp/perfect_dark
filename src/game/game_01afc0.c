#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "types.h"

Gfx *func0f01afc0(Gfx *gdl)
{
	gDPSetCycleType(gdl++, G_CYC_FILL);
	gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viGetX(), osVirtualToPhysical((void *)viGetUnk28()));
	gDPSetFillColor(gdl++, 0x00010001);
	gDPFillRectangle(gdl++, 0, 0, viGetX() - 1, viGetY() - 1);

	return gdl;
}
