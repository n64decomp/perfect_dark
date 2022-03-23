#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/vi.h"
#include "data.h"
#include "types.h"

Gfx *titleClear(Gfx *gdl)
{
	gDPSetCycleType(gdl++, G_CYC_FILL);
	gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viGetWidth(), osVirtualToPhysical((void *)viGetBackBuffer()));
	gDPSetFillColor(gdl++, 0x00010001);
	gDPFillRectangle(gdl++, 0, 0, viGetWidth() - 1, viGetHeight() - 1);

	return gdl;
}
