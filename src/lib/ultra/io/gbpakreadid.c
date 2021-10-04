#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

u32 g_OsGbNintendoData[] = {
	0xceed6666, 0xcc0d000b, 0x03730083, 0x000c000d,
	0x0008111f, 0x8889000e, 0xdccc6ee6, 0xddddd999,
	0xbbbb6763, 0x6e0eeccc, 0xdddc999f, 0xbbb9333e,
};

u8 g_OsGbCartVersions[] = {
	0x00, 0x01, 0x01, 0x01,
	0xff, 0x02, 0x02, 0xff,
	0x00, 0x00, 0xff, 0xff,
	0xff, 0xff, 0xff, 0x03,
	0x03, 0x03, 0x03, 0x03,
};

s32 osGbpakReadId(OSPfs *pfs, OSGbpakId *id, u8 *status)
{
	s32 i;
	s32 ret;
	u8 sum;
	u8 buffer[0x60];

	ret = osGbpakGetStatus(pfs, status);

	if (ret == PFS_ERR_NEW_GBCART) {
		ret = osGbpakGetStatus(pfs, status);
	}

	if (ret == PFS_ERR_NEW_GBCART) {
		return PFS_ERR_CONTRFAIL;
	}

	if (ret == 0) {
		if ((*status & OS_GBPAK_POWER) == 0) {
			ret = osGbpakPower(pfs, OS_GBPAK_POWER_ON);

			if (ret != 0) {
				return ret;
			}
		}

		ret = osGbpakReadWrite(pfs, PFS_READ, 0x100, buffer, 0x60);

		if (ret != 0) {
			return ret;
		}

		ret = osGbpakGetStatus(pfs, status);

		if (ret == PFS_ERR_NEW_GBCART) {
			ret = PFS_ERR_CONTRFAIL;
		}

		if (ret != 0) {
			return ret;
		}

		// Compare id->nintendo_chr with expected data
		if (bcmp(g_OsGbNintendoData, &buffer[4], sizeof(id->nintendo_chr)) != 0) {
			return PFS_ERR_CONTRFAIL;
		}

		// Sum game_title through to isum
		sum = 0;

		for (i = 0x34; i < 0x4e; i++) {
			sum += buffer[i];
		}

		sum = (sum + 25) & 0xff;

		if (sum != 0) {
			return PFS_ERR_CONTRFAIL;
		}

		bcopy(buffer, id, sizeof(OSGbpakId));

		if (id->cart_type < 20) {
			pfs->version = g_OsGbCartVersions[id->cart_type];
		}

		pfs->dir_size = id->ram_size;
	}

	return ret;
}
