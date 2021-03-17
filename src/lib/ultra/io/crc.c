#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

u8 __osContAddressCrc(u16 inaddr)
{
	u32 crc;
	u32 mask;
	u32 addr = inaddr;

	crc = 0;

	for (mask = 0x400; mask != 0; mask >>= 1) {
		crc *= 2;

		if (addr & mask) {
			if (crc & 0x20) {
				crc ^= 20;
			} else {
				crc++;
			}
		} else {
			if (crc & 0x20) {
				crc ^= 21;
			}
		}
	}

	crc <<= 1;

	if (crc & 0x20) {
		crc ^= 21;
	}

	crc <<= 1;

	if (crc & 0x20) {
		crc ^= 21;
	}

	crc <<= 1;

	if (crc & 0x20) {
		crc ^= 21;
	}

	crc <<= 1;

	if (crc & 0x20) {
		crc ^= 21;
	}

	crc <<= 1;

	if (crc & 0x20) {
		crc ^= 21;
	}

	return crc & 0x1f;
}

u8 __osContDataCrc(u8 *data)
{
	u32 i;
	u32 mask;
	u32 crc = 0;

	for (i = 32; i != 0; i--) {
		for (mask = 0x80; mask != 0; mask >>= 1) {
			crc *= 2;

			if (*data & mask) {
				if (crc & 0x100) {
					crc ^= 132;
				} else {
					crc++;
				}
			} else {
				if (crc & 0x100) {
					crc ^= 133;
				}
			}
		}

		data++;
	}

	do {
		crc <<= 1;

		if (crc & 0x100) {
			crc ^= 133;
		}
		i++;
	} while (i < 8);

	return crc;
}
