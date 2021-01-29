#include <libultra_internal.h>
#include "game/data/data_000000.h"
#include "gvars/gvars.h"

typedef struct {
	unsigned int inst1;
	unsigned int inst2;
	unsigned int inst3;
	unsigned int inst4;
} __osExceptionVector;

extern __osExceptionVector __osExceptionPreamble;
extern u32 osAppNMIBuffer;

void osInitialize()
{
	u32 pifdata;

	__osFinalRom = TRUE;
	__osSetSR(__osGetSR() | SR_CU1);
	__osSetFpcCsr(FPCSR_FS | FPCSR_EV);

	while (__osSiRawReadIo(PIF_RAM_END - 3, &pifdata));

	while (__osSiRawWriteIo(PIF_RAM_END - 3, pifdata | 8));

	*(__osExceptionVector *)UT_VEC = __osExceptionPreamble;
	*(__osExceptionVector *)XUT_VEC = __osExceptionPreamble;
	*(__osExceptionVector *)ECC_VEC = __osExceptionPreamble;
	*(__osExceptionVector *)E_VEC = __osExceptionPreamble;

	osWritebackDCache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
	osInvalICache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
	func00005dc0();
	osMapTLBRdb();

	osClockRate = osClockRate * 3 / 4;

	if (osResetType == RESET_TYPE_COLD_RESET) {
		bzero(&osAppNMIBuffer, 0x40);
	}

	if (osTvType == OS_TV_PAL) {
		osViClock = VI_PAL_CLOCK;
	} else if (osTvType == OS_TV_MPAL) {
		osViClock = VI_NTSC_CLOCK;
	} else {
		osViClock = VI_NTSC_CLOCK;
	}

	if (__osGetCause() & CAUSE_IP5) {
		while (1);
	}

	*(u32 *)PHYS_TO_K1(AI_CONTROL_REG) = 1;
	*(u32 *)PHYS_TO_K1(AI_DACRATE_REG) = 0x3fff;
	*(u32 *)PHYS_TO_K1(AI_BITRATE_REG) = 0xf;
}
