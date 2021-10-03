#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s32 osGbpakPower(OSPfs *pfs, s32 flag)
{
	s32 i;
	s32 ret;
	u8 buffer[32];

	for (i = 0; i < 32; i++) {
		buffer[i] = flag;
	}

	ret = __osContRamWrite(pfs->queue, pfs->channel, 0x580, buffer, 0);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = osGbpakInit(pfs->queue, pfs, pfs->channel);

		if (ret == 0) {
			ret = __osContRamWrite(pfs->queue, pfs->channel, 0x580, buffer, 0);

			if (ret == PFS_ERR_NEW_PACK) {
				ret = PFS_ERR_CONTRFAIL;
			}
		}
	}

	if (flag != OS_GBPAK_POWER_OFF) {
		osSetTimer(&var80090ab0, 937500, 0, &var80090ad0, &var80090ae8);
		osRecvMesg(&var80090ad0, NULL, OS_MESG_BLOCK);
	}

	return ret;
}
