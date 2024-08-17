#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/vi.h"
#include "data.h"
#include "types.h"

Gfx *title_clear(Gfx *gdl)
{
	gDPSetCycleType(gdl++, G_CYC_FILL);
	gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, vi_get_width(), osVirtualToPhysical((void *)vi_get_back_buffer()));
	gDPSetFillColor(gdl++, 0x00010001);
	gDPFillRectangle(gdl++, 0, 0, vi_get_width() - 1, vi_get_height() - 1);

	return gdl;
}
