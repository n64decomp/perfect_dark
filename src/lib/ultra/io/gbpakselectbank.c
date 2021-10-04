#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s32 __osGbpakSelectBank(OSPfs *pfs, u8 bank)
{
	s32 ret;
	s32 i;
	u8 buffer[8][4];

	if (bank >= 3) {
		return PFS_ERR_INVALID;
	}

	for (i = 0; i < 8; i++) {
		buffer[i][0] = bank;
		buffer[i][1] = bank;
		buffer[i][2] = bank;
		buffer[i][3] = bank;
	}

	ret = __osContRamWrite(pfs->queue, pfs->channel, 0x500, (u8 *)buffer, 0);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = osGbpakInit(pfs->queue, pfs, pfs->channel);

		if (ret == 0) {
			ret = __osContRamWrite(pfs->queue, pfs->channel, 0x500, (u8 *)buffer, 0);

			if (ret == PFS_ERR_NEW_PACK) {
				ret = PFS_ERR_CONTRFAIL;
			}
		}
	}

	if (ret == 0) {
		pfs->banks = bank;
	}

	return ret;
}
