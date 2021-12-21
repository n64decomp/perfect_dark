#include <ultra64.h>
#include "bss.h"
#include "data.h"
#include "types.h"

struct modelnode var8007c0dc;
struct modelnode var8007c0f4;
struct modelnode var8007c10c;
struct modelrodata_chrinfo var8007c124;
struct modelrodata_position var8007c130;
struct modelrodata_position var8007c148;

struct modelfiledata g_PlayerModelFileData = {
	(struct modelnode *) &var8007c0dc,
	&g_Skel0B,
	NULL,
	0,
	3,
	41.161228179932,
	0,
	NULL,
};

//                                                       rodata                             parent        next  prev  child
struct modelnode var8007c0dc = { MODELNODETYPE_CHRINFO,  (union modelrodata *)&var8007c124, NULL,         NULL, NULL, &var8007c0f4 };
struct modelnode var8007c0f4 = { MODELNODETYPE_POSITION, (union modelrodata *)&var8007c130, &var8007c0dc, NULL, NULL, &var8007c10c };
struct modelnode var8007c10c = { MODELNODETYPE_POSITION, (union modelrodata *)&var8007c148, &var8007c0f4, NULL, NULL, NULL };

struct modelrodata_chrinfo var8007c124 = {0, 1, 0, 0};

struct modelrodata_position var8007c130 = {
	{ 1.1779819726944f, 41.144371032715, 0 }, // pos
	MODELPART_0001, // part
	{ 2, -1, -1 },  // pieces
	0,              // draw distance
};

struct modelrodata_position var8007c148 = {
	{ -2.5760269165039, 480.42901611328, 0 }, // pos
	MODELPART_0002, // part
	{ 0, -1, -1 },  // pieces
	0,              // draw distance
};
