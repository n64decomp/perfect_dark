#include <os_internal.h>
#include "controller.h"
#include "siint.h"

extern OSTimer var80090ab0;
extern OSMesgQueue g_GbpakMesgQueue;
extern OSMesg var80090ae8;

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
		osSetTimer(&var80090ab0, 937500, 0, &g_GbpakMesgQueue, &var80090ae8);
		osRecvMesg(&g_GbpakMesgQueue, NULL, OS_MESG_BLOCK);
	}

	return ret;
}
