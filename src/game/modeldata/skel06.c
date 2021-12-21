#include <ultra64.h>
#include "bss.h"
#include "data.h"
#include "types.h"

u8 g_Skel06Joints[][2] = {
	{ 0, 0 },
	{ 1, 1 },
	{ 2, 2 },
	{ 3, 3 },
	{ 4, 4 },
	{ 5, 5 },
	{ 6, 6 },
};

struct skeleton g_Skel06 = {
	SKEL_06, ARRAYCOUNT(g_Skel06Joints), g_Skel06Joints,
};
