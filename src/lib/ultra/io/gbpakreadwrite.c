#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s32 osGbpakReadWrite(OSPfs *pfs, u16 flag, u16 address, u8 *buffer, u16 size)
{
	s32 i;
	s32 ret;
	u8 bank;
	u16 addr;

	bank = address >> 14;

	if (bank != pfs->banks) {
		ret = __osGbpakSelectBank(pfs, bank);

		if (ret != 0) {
			return ret;
		}
	}

	size = size >> 5;
	address = (address | 0xc000) >> 5;

	if (flag == PFS_WRITE) {
		for (i = 0; i < size; i++) {
			ret = __osContRamWrite(pfs->queue, pfs->channel, address, buffer, 0);

			if (ret != 0) {
				break;
			}

			address++;

			if (address >= 0x800 && i < size - 1) {
				bank++;
				ret = __osGbpakSelectBank(pfs, bank);

				if (ret != 0) {
					break;
				}

				address = 0x600;
			}

			buffer += BLOCKSIZE;
		}
	} else {
		for (i = 0; i < size; i++) {
			ret = __osContRamRead(pfs->queue, pfs->channel, address, buffer);

			if (ret != 0) {
				break;
			}

			address++;

			if (address >= 0x800 && i < size - 1) {
				bank++;
				ret = __osGbpakSelectBank(pfs, bank);

				if (ret != 0) {
					break;
				}

				address = 0x600;
			}

			buffer += BLOCKSIZE;
		}
	}

	if (ret == PFS_ERR_NEW_PACK) {
		ret = PFS_ERR_CONTRFAIL;
	}

	return ret;
}
