#include <ultra64.h>
#include "bss.h"
#include "data.h"
#include "types.h"

u8 g_SkelUziJoints[][2] = {
	{ 0, 0 },
	{ 1, 1 },
	{ 2, 2 },
	{ 3, 3 },
	{ 6, 6 },
	{ 4, 4 },
	{ 5, 5 },
};

struct skeleton g_SkelUzi = {
	SKEL_UZI, ARRAYCOUNT(g_SkelUziJoints), g_SkelUziJoints,
};
