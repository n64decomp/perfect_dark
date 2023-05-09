#include "versions.h"
#include <os.h>
#include <os_internal.h>
#include <R4300.h>
#include <rcp.h>
#include "constants.h"

typedef struct {
	unsigned int inst1;
	unsigned int inst2;
	unsigned int inst3;
	unsigned int inst4;
} __osExceptionVector;

extern __osExceptionVector __osExceptionPreamble;
extern s32 osAppNMIBuffer[];
extern OSPiHandle CartRomHandle;
extern OSPiHandle LeoDiskHandle;

s32 osViClock = VI_NTSC_CLOCK;

u32 _osShutdown = 0;
u32 __osGlobalIntMask = OS_IM_ALL;

void osInitialize(void)
{
	u32 pifdata;

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

	CartRomHandle.type = DEVICE_TYPE_INIT;
	CartRomHandle.latency = IO_READ(0xa4600014);
	CartRomHandle.pulse = IO_READ(0xa4600018);
	CartRomHandle.pageSize = IO_READ(0xa460001c);
	CartRomHandle.relDuration = IO_READ(0xa4600020);

	LeoDiskHandle.type = DEVICE_TYPE_INIT;
	LeoDiskHandle.latency = IO_READ(0xa4600024);
	LeoDiskHandle.pulse = IO_READ(0xa4600028);
	LeoDiskHandle.pageSize = IO_READ(0xa460002c);
	LeoDiskHandle.relDuration = IO_READ(0xa4600030);

	osMapTLBRdb();

	if (osResetType == RESETTYPE_COLD) {
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
