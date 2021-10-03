#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s32 osGbpakGetStatus(OSPfs *pfs, u8 *status)
{
	s32 ret;
	s32 i;
	u8 buffer[32];

	ret = __osContRamRead(pfs->queue, pfs->channel, 0x400, buffer);

	if (ret == PFS_ERR_NEW_PACK || buffer[31] != (OS_GBPAK_RSTB_DETECTION | OS_GBPAK_GBCART_ON)) {
		ret = osGbpakInit(pfs->queue, pfs, pfs->channel);

		if (ret != 0) {
			return ret;
		}
	}

	ret = __osContRamRead(pfs->queue, pfs->channel, 0x580, buffer);

	if (ret == 0) {
		ret = __osPfsGetStatus(pfs->queue, pfs->channel);

		if (ret != 0) {
			return ret;
		}

		*status = buffer[0];

		for (i = 1; i < 32; i++) {
			*status |= ((u8 *)buffer)[i];
		}

		*status &= (OS_GBPAK_RSTB_DETECTION | OS_GBPAK_GBCART_PULL);
		*status |= buffer[31];

		if ((*status & OS_GBPAK_GBCART_ON) == 0) {
			ret = PFS_ERR_NO_GBCART;
		} else if (*status & OS_GBPAK_GBCART_PULL) {
			ret = PFS_ERR_NEW_GBCART;
		}
	} else if (ret == PFS_ERR_NEW_PACK) {
		ret = PFS_ERR_CONTRFAIL;
	}

	return ret;
}
