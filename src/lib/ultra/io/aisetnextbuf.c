#include <ultra64.h>

s32 osAiSetNextBuffer(void *bufPtr, u32 size)
{
	static u8 hdwrBugFlag = 0;
	char *bptr = bufPtr;

	if (hdwrBugFlag != 0) {
		bptr -= 0x2000;
	}

	if ((((u32)bufPtr + size) & 0x1fff) == 0) {
		hdwrBugFlag = 1;
	} else {
		hdwrBugFlag = 0;
	}

	if (__osAiDeviceBusy()) {
		return -1;
	}

	IO_WRITE(AI_DRAM_ADDR_REG, osVirtualToPhysical(bptr));
	IO_WRITE(AI_LEN_REG, size);

	return 0;
}
