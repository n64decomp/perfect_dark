#include <ultra64.h>
#include "data.h"

void osViSetSpecialFeatures(u32 func)
{
	register u32 saveMask;

	saveMask = __osDisableInt();

	if (func & OS_VI_GAMMA_ON) {
		__osViNext->control |= VI_CTRL_GAMMA_ON;
	}

	if (func & OS_VI_GAMMA_OFF) {
		__osViNext->control &= ~VI_CTRL_GAMMA_ON;
	}

	if (func & OS_VI_GAMMA_DITHER_ON) {
		__osViNext->control |= VI_CTRL_GAMMA_DITHER_ON;
	}

	if (func & OS_VI_GAMMA_DITHER_OFF) {
		__osViNext->control &= ~VI_CTRL_GAMMA_DITHER_ON;
	}

	if (func & OS_VI_DIVOT_ON) {
		__osViNext->control |= VI_CTRL_DIVOT_ON;
	}

	if (func & OS_VI_DIVOT_OFF) {
		__osViNext->control &= ~VI_CTRL_DIVOT_ON;
	}

	if (func & OS_VI_DITHER_FILTER_ON) {
		__osViNext->control |= VI_CTRL_DITHER_FILTER_ON;
		__osViNext->control &= ~VI_CTRL_ANTIALIAS_MASK;
	}

	if (func & OS_VI_DITHER_FILTER_OFF) {
		__osViNext->control &= ~VI_CTRL_DITHER_FILTER_ON;
		__osViNext->control |= __osViNext->modep->comRegs.ctrl & VI_CTRL_ANTIALIAS_MASK;
	}

	__osViNext->state |= VI_STATE_08;

	__osRestoreInt(saveMask);
}
