#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

u64 g_Rng2Seed = 0xab8d9f7781280783;

/**
 * Generate a random number between 0 and 4294967295.
 */
u32 random2(void)
{
	g_Rng2Seed = ((g_Rng2Seed << 63) >> 31 | (g_Rng2Seed << 31) >> 32) ^ (g_Rng2Seed << 44) >> 32;
	g_Rng2Seed = ((g_Rng2Seed >> 20) & 0xfff) ^ g_Rng2Seed;

	return g_Rng2Seed;
}

/**
 * Set the given seed as the RNG seed. Add 1 to make sure it isn't 0.
 */
void rng2_set_seed(u64 seed)
{
	g_Rng2Seed = seed + 1;
}
