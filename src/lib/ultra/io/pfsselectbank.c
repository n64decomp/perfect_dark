#include <ultra64.h>

s32 __osPfsSelectBank(OSPfs *pfs, u8 bank)
{
	u8 temp[8][4];
	int i;
	s32 ret;
	ret = 0;

	for (i = 0; i < 8; i++) {
		temp[i][1] = bank;
		temp[i][2] = bank;
		temp[i][3] = bank;
		temp[i][0] = bank;
	}

	ret = __osContRamWrite(pfs->queue, pfs->channel, 1024, (u8*)temp, FALSE);

	if (ret == 0) {
		pfs->activebank = bank;
	}

	return ret;
}
