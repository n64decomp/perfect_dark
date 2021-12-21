#include <ultra64.h>
#include "bss.h"
#include "data.h"
#include "types.h"

u8 g_SkelCasingJoints[][2] = {
	{ 0, 0 },
};

struct skeleton g_SkelCasing = {
	SKEL_CASING, ARRAYCOUNT(g_SkelCasingJoints), g_SkelCasingJoints,
};
