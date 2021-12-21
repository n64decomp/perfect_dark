#include <ultra64.h>
#include "bss.h"
#include "data.h"
#include "types.h"

u8 g_SkelSkedarJoints[][2] = {
	{ 0,  0  },
	{ 1,  1  },
	{ 2,  2  },
	{ 3,  3  },
	{ 4,  4  },
	{ 5,  5  },
	{ 6,  6  },
	{ 7,  7  },
	{ 8,  15 },
	{ 9,  16 },
	{ 10, 17 },
	{ 11, 18 },
	{ 12, 19 },
	{ 13, 20 },
	{ 14, 21 },
	{ 15, 8  },
	{ 16, 9  },
	{ 17, 10 },
	{ 18, 11 },
	{ 19, 12 },
	{ 20, 13 },
	{ 21, 14 },
	{ 22, 29 },
	{ 23, 30 },
	{ 24, 31 },
	{ 25, 32 },
	{ 26, 33 },
	{ 27, 34 },
	{ 28, 35 },
	{ 29, 22 },
	{ 30, 23 },
	{ 31, 24 },
	{ 32, 25 },
	{ 33, 26 },
	{ 34, 27 },
	{ 35, 28 },
};

struct skeleton g_SkelSkedar = {
	SKEL_SKEDAR, ARRAYCOUNT(g_SkelSkedarJoints), g_SkelSkedarJoints,
};
