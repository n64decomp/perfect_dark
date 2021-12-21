#include <ultra64.h>
#include "bss.h"
#include "data.h"
#include "types.h"

u8 g_SkelChrGunJoints[][2] = {
	{ 0, 0 },
	{ 1, 1 },
};

struct skeleton g_SkelChrGun = {
	SKEL_CHRGUN, ARRAYCOUNT(g_SkelChrGunJoints), g_SkelChrGunJoints,
};
