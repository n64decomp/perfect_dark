#include <ultra64.h>
#include "bss.h"
#include "data.h"
#include "types.h"

u8 g_SkelClassicGunJoints[][2] = {
	{ 0, 0 },
	{ 1, 1 },
	{ 2, 2 },
	{ 5, 5 },
	{ 3, 3 },
	{ 4, 4 },
};

struct skeleton g_SkelClassicGun = {
	SKEL_CLASSICGUN, ARRAYCOUNT(g_SkelClassicGunJoints), g_SkelClassicGunJoints,
};
