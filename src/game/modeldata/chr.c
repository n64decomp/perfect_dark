#include <ultra64.h>
#include "bss.h"
#include "data.h"
#include "types.h"

u8 g_SkelChrJoints[][2] = {
	{ 0,  0  },
	{ 1,  1  },
	{ 2,  2  },
	{ 3,  4  },
	{ 4,  3  },
	{ 5,  6  },
	{ 6,  5  },
	{ 7,  8  },
	{ 8,  7  },
	{ 9,  10 },
	{ 10, 9  },
	{ 11, 12 },
	{ 12, 11 },
	{ 13, 14 },
	{ 14, 13 },
};

struct skeleton g_SkelChr = {
	SKEL_CHR, ARRAYCOUNT(g_SkelChrJoints), g_SkelChrJoints,
};
