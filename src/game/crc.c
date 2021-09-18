#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

void crcCalculateU32Pair(u8 *start, u8 *end, u32 *checksum)
{
	u8 *ptr;
	u32 salt = 0;
	u64 seed = 0x8f809f473108b3c1;
	u32 sum1 = 0;
	u32 sum2 = 0;

	for (ptr = start; ptr < end; ptr++, salt += 7) {
		seed += *ptr << (salt & 0x0f);
		sum1 ^= rngRotateSeed(&seed);
	}

	for (ptr = end - 1; ptr >= start; ptr--, salt += 3) {
		seed += *ptr << (salt & 0x0f);
		sum2 ^= rngRotateSeed(&seed);
	}

	checksum[0] = sum1;
	checksum[1] = sum2;
}

void crcCalculateU16Pair(u8 *start, u8 *end, u16 *checksum)
{
	u8 *ptr;
	u32 salt = 0;
	u64 seed = 0x8f809f473108b3c1;
	u32 sum1 = 0;
	u32 sum2 = 0;

	for (ptr = start; ptr < end; ptr++, salt += 7) {
		seed += *ptr << (salt & 0x0f);
		sum1 ^= rngRotateSeed(&seed);
	}

	for (ptr = end - 1; ptr >= start; ptr--, salt += 3) {
		seed += *ptr << (salt & 0x0f);
		sum2 ^= rngRotateSeed(&seed);
	}

	checksum[0] = sum1 & 0xffff;
	checksum[1] = sum2 & 0xffff;
}
