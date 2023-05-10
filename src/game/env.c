#include <ultra64.h>
#include "constants.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/bg.h"
#include "bss.h"
#include "lib/vi.h"
#include "data.h"
#include "types.h"

struct coord var800a65f0;

struct var800a6600 var800a6600;
f32 var800a6618;
f32 var800a661c;
struct envtype1 *var800a6620;

f32 var80081050 = MAXFLOAT;
struct environment g_Env = {900, 1000};

//                   lensflare,    r,    g,    b,        x,       y,        z, texture size, orb size
struct sun suns_area51[] = { 0, 0xff, 0xe0, 0x80,  -200000,  310000,  1000000, 20, 48 };
struct sun suns_villa[]  = { 1, 0xff, 0xff, 0xff, -1000000,  200000,    50000, 20, 48 };
struct sun suns_ci[]     = { 1, 0xff, 0xff, 0xff,   400000,  600000, -1000000, 20, 48 };

struct sun suns_skedar[] = {
	{ 1, 0xff, 0xff, 0xff,  -400000,  600000,  1000000, 20, 48 },
	{ 1, 0xff, 0xff, 0xff,        0, 1000000,  1000000, 25, 60 },
	{ 1, 0xff, 0xff, 0xff,   400000,  600000,  1000000, 15, 36 },
};

struct sun suns_crashsite[] = { 1, 0xff, 0xd7, 0xf2,  1900000,  300000, -1400000, 22, 48 };
struct sun suns_airbase[]   = { 1, 0xff, 0xd7, 0xf2, -1200000,  200000,   150000, 30, 60 };

struct envtype1 g_EnvironmentsType1[] = {
	//                                                    |--- fog ----|  |---- sky -----|                     |----------- clouds -----------| |--------------- water ---------------|
	// stage                near    far    06    08   0a     min     max     r     g     b     sun             e  scale    1c     r     g     b 20 21  scale type   r     g     b    28
	{ STAGE_CRASHSITE,        15, 10000,    0,    0,   0, 0x03e2, 0x03e8, 0x9b, 0x2d, 0x1e, 1, suns_crashsite, 1,  1500, 0x00, 0xfa, 0xfa, 0x00, 0, 0, -5000, 0, 0x00, 0x00, 0x00, 0x00 },
	{ STAGE_PELAGIC,          15, 15000, 3333, 4444, 600, 0x03e3, 0x03e8, 0x2d, 0x3e, 0x60, 0, NULL,           1,  5000, 0x00, 0xf0, 0xf0, 0xf0, 0, 0, -2000, 0, 0x14, 0x21, 0x2b, 0x00 },
	{ STAGE_VILLA,            15, 20000,    0,    0,   0, 0x03d5, 0x0417, 0x46, 0xa0, 0xff, 1, suns_villa,     1,  5000, 0x00, 0xff, 0xff, 0xff, 0, 0, -1850, 1, 0x00, 0xff, 0xff, 0x00 },
	{ STAGE_PELAGIC + 900,    30, 15000, 3333, 4444, 600, 0x03e3, 0x03e8, 0x10, 0x30, 0x60, 0, NULL,           1,  5000, 0x00, 0xff, 0xff, 0xff, 0, 0, -1000, 0, 0x00, 0x00, 0x00, 0x00 },
	{ STAGE_24,                2, 25000,    0,    0,   0, 0x03e4, 0x03e8, 0x00, 0x00, 0x00, 0, NULL,           1, 10000, 0x00, 0xff, 0xff, 0xff, 0, 0,     0, 1, 0x00, 0xff, 0xff, 0x07 },
	{ STAGE_2B,                2,  2000, 2500, 3055, 750, 0x03bd, 0x03e8, 0x20, 0x10, 0x10, 0, NULL,           1,  5000, 0x00, 0x3a, 0x11, 0x00, 0, 0, -1000, 1, 0x00, 0xff, 0xff, 0x14 },
	{ STAGE_2B + 900,          2,  8000, 6000, 8000, 800, 0x03df, 0x03e8, 0x20, 0x10, 0x10, 0, NULL,           1,  5000, 0x00, 0x3a, 0x11, 0x00, 0, 0, -1000, 1, 0x00, 0xff, 0xff, 0x00 },
	{ 238,                    10,  6000,    0,    0,   0, 0x03e4, 0x03e8, 0x18, 0x18, 0x18, 0, NULL,           1, 10000, 0x00, 0x78, 0x78, 0x78, 0, 0,  -500, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 338,                    10,  6000,    0,    0,   0, 0x03e4, 0x03e8, 0x18, 0x18, 0x18, 0, NULL,           1, 10000, 0x00, 0x78, 0x78, 0x78, 0, 0,  -500, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 438,                    10,  6000,    0,    0,   0, 0x03e4, 0x03e8, 0x18, 0x18, 0x18, 0, NULL,           1, 10000, 0x00, 0x78, 0x78, 0x78, 0, 0,  -500, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 200,                    10,  7500,    0,    0,   0, 0x03e4, 0x03e8, 0x00, 0x00, 0x00, 0, NULL,           0,     0, 0x00, 0x00, 0x00, 0x00, 0, 0,     0, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 300,                    10,  6000,    0,    0,   0, 0x03e4, 0x03e8, 0x00, 0x00, 0x00, 0, NULL,           0,     0, 0x00, 0x00, 0x00, 0x00, 0, 0,     0, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 400,                    10,  5000,    0,    0,   0, 0x03e4, 0x03e8, 0x00, 0x00, 0x00, 0, NULL,           0,     0, 0x00, 0x00, 0x00, 0x00, 0, 0,     0, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0,                       0,     0,    0,    0,   0, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0, NULL,           0,     0, 0x00, 0x00, 0x00, 0x00, 0, 0,     0, 0, 0x00, 0x00, 0x00, 0x00 },
};

struct envtype2 g_EnvironmentsType2[] = {
	//                                                                            |-------- clouds --------|     |------------ water ------------|
	// stage             near    far 08 0a 0c     r     g     b     sun           e     r     g     b  scale 20  e     r     g     b   scale  type 30 34
	{ -1,                  15, 10000, 0, 0, 0, 0x00, 0x10, 0x40, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_RESCUE,        15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_MAIANSOS,      15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_ATTACKSHIP,    15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_INFILTRATION,  15, 12000, 0, 0, 0, 0x00, 0x00, 0x00, 1, suns_area51,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_ESCAPE,        15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 1, suns_area51,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_TEST_ARCH,     15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_DEEPSEA,       15, 10000, 0, 0, 0, 0x05, 0x00, 0x00, 0, NULL,         0, 0x9b, 0x9b, 0x9b,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_TEST_DEST,     15, 10000, 0, 0, 0, 0x10, 0x30, 0x60, 0, NULL,         1, 0xe6, 0xe6, 0xe6,  3000, 0, 1, 0xff, 0xff, 0x96,   -150,    2, 0, 0 },
	{ STAGE_TEST_LEN,      15, 10000, 0, 0, 0, 0x30, 0x40, 0x10, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_TEST_ASH,      15, 25000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_DEFENSE,       15, 10000, 0, 0, 0, 0x65, 0xb2, 0xff, 1, suns_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_CITRAINING,    15, 10000, 0, 0, 0, 0x65, 0xb2, 0xff, 1, suns_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_DUEL,          10, 10000, 0, 0, 0, 0x65, 0xb2, 0xff, 1, suns_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_RETAKING,      15, 10000, 0, 0, 0, 0x65, 0xb2, 0xff, 1, suns_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_DEFECTION,     10, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_MBR,           10, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_EXTRACTION,    10, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_SKEDARRUINS,   15, 10000, 0, 0, 0, 0x65, 0x65, 0xff, 3, suns_skedar,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_WAR,           15, 10000, 0, 0, 0, 0x65, 0x65, 0xff, 3, suns_skedar,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_TEST_RUN,      15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_MP_SKEDAR,     15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_TEST_SILO,     15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_CHICAGO,       10, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x50, 0x28, 0x0a,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_G5BUILDING,    15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x50, 0x28, 0x0a,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_AIRFORCEONE,   15, 20000, 0, 0, 0, 0x00, 0x10, 0x40, 0, NULL,         1, 0xff, 0xff, 0xff,  5000, 0, 1, 0xff, 0xff, 0xff,  -5000,    2, 0, 1 },
	{ STAGE_MP_RAVINE,     15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x50, 0x28, 0x0a,  5000, 0, 0, 0x00, 0x00, 0x00, -31000,    0, 0, 1 },
	{ STAGE_AIRBASE,       15, 20000, 0, 0, 0, 0x00, 0x10, 0x40, 1, suns_airbase, 1, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_INVESTIGATION, 15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_MP_PIPES,      15, 10000, 0, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x46, 0xc7, 0xba,  4500, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_G5BUILDING, 15, 10000, 0, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x5a, 0x90, 0xa5,  4500, 0, 0, 0x00, 0x00, 0x00, -20000,    0, 0, 0 },
	{ STAGE_MP_TEMPLE,     15, 10000, 0, 0, 0, 0x00, 0x10, 0x80, 0, NULL,         1, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0xff, 0xff,  -1850,    1, 0, 1 },
	{ STAGE_MP_COMPLEX,    15, 10000, 0, 0, 0, 0x02, 0x00, 0x00, 0, NULL,         1, 0x82, 0xaa, 0xc8,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_UFF,      10, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_OLD,      15, 30000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_LAM,      15, 20000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_BASE,       15, 20000, 0, 0, 0, 0x04, 0x00, 0x00, 0, NULL,         1, 0x82, 0xb4, 0x64,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP2,      15, 20000, 0, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x46, 0xc7, 0xba,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_AREA52,     15, 10000, 0, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x46, 0xc7, 0xba,  4500, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_WAREHOUSE,  15, 10000, 0, 0, 0, 0x02, 0x00, 0x00, 0, NULL,         1, 0x82, 0xaa, 0xc8,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_CARPARK,    15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x64, 0xc8, 0x86,  5500, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP6,      15, 20000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP7,      15, 20000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP8,      15, 20000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_RUINS,      15, 10000, 0, 0, 0, 0x03, 0x00, 0x00, 0, NULL,         1, 0x82, 0xe6, 0xaa,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_SEWERS,     15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x64, 0x64, 0x64,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_FELICITY,   10, 10000, 0, 0, 0, 0x04, 0x05, 0x00, 0, NULL,         1, 0x64, 0xd2, 0x82,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_FORTRESS,   15, 10000, 0, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x5a, 0x90, 0xa5,  5500, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_VILLA,      15, 10000, 0, 0, 0, 0x88, 0x88, 0xdc, 0, NULL,         1, 0xff, 0xaa, 0x2a,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP14,     15, 20000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_GRID,       15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP16,     15, 20000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP17,     15, 20000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x64, 0xc8, 0x86, 10000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP18,     15, 20000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP19,     15, 20000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP20,     15, 20000, 0, 0, 0, 0x00, 0x10, 0x3c, 0, NULL,         1, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ 0 },
};

void env0f1657f8(void)
{
	struct zrange zrange;
	f32 scale;
	f32 zfar;
	f32 znear;
	f32 sp28;
	f32 sp24;

	if (!g_FogEnabled) {
		return;
	}

	viGetZRange(&zrange);

	scale = g_Vars.currentplayerstats->scale_bg2gfx;

	zrange.near /= scale;
	zrange.far /= scale;

	var800a661c = g_Env.fogmin * 0.001f;
	var800a6618 = g_Env.fogmax * 0.001f;

	var80081050 = (zrange.far - zrange.near) * var800a6618 + zrange.f[0];

	var800a6600.znear = zrange.near;
	var800a6600.zfar = zrange.far;

	zfar = var800a6600.zfar;
	znear = var800a6600.znear;
	sp28 = 128.0f / (var800a6618 - var800a661c);
	sp24 = (0.5f - var800a661c) * 256.0f / (var800a6618 - var800a661c);

	var800a6600.unk10 = -sp28 * zfar * (znear + 1.0f) / (zfar - znear) / 255.0f;
	var800a6600.unk14 = ((zfar + 1.0f) * sp28 / (zfar - znear) + sp24) / 255.0f;
}

static void envApplyType1(struct envtype1 *env)
{
	g_FogEnabled = true;
	var800a65e4 = 0;

	viSetZRange(env->near, env->far);

	g_Env.fogmin = env->fogmin;
	g_Env.fogmax = env->fogmax;

	g_Env.sky_r = env->sky_r;
	g_Env.sky_g = env->sky_g;
	g_Env.sky_b = env->sky_b;
	g_Env.skyredfrac = g_Env.sky_r / 255.0f;
	g_Env.skygreenfrac = g_Env.sky_g / 255.0f;
	g_Env.skybluefrac = g_Env.sky_b / 255.0f;

	g_Env.numsuns = env->numsuns;
	g_Env.suns = env->suns;

	g_Env.clouds_enabled = env->clouds_enabled;
	g_Env.clouds_scale = env->clouds_scale;
	g_Env.unk18 = env->unk1c;
	g_Env.clouds_r = env->clouds_r;
	g_Env.clouds_g = env->clouds_g;
	g_Env.clouds_b = env->clouds_b;

	g_Env.water_enabled = env->water_enabled;
	g_Env.water_scale = env->water_scale;
	g_Env.water_type = env->water_type;
	g_Env.water_r = env->water_r;
	g_Env.water_g = env->water_g;
	g_Env.water_b = env->water_b;
	g_Env.unk40 = env->unk28;

	if (!env->unk06) {
		g_Env800a65e8 = NULL;
	} else {
		var800a65f0.x = env->unk06;
		var800a65f0.y = env->unk08;
		var800a65f0.z = env->unk0a;
		g_Env800a65e8 = &var800a65f0;
	}

	env0f1657f8();
}

static void envApplyType2(struct envtype2 *env)
{
	struct zrange zrange;

	viSetZRange(env->near, env->far);

	g_Env.sky_r = env->sky_r;
	g_Env.sky_g = env->sky_g;
	g_Env.sky_b = env->sky_b;

	g_Env.skyredfrac = g_Env.sky_r / 255.0f;
	g_Env.skygreenfrac = g_Env.sky_g / 255.0f;
	g_Env.skybluefrac = g_Env.sky_b / 255.0f;

	g_Env.numsuns = env->numsuns;
	g_Env.suns = env->suns;
	g_Env.clouds_enabled = env->clouds_enabled;
	g_Env.clouds_scale = env->clouds_scale;
	g_Env.unk18 = env->unk20;

	g_Env.clouds_r = env->clouds_r;
	g_Env.clouds_g = env->clouds_g;
	g_Env.clouds_b = env->clouds_b;

	g_Env.water_enabled = env->water_enabled;
	g_Env.water_scale = env->water_scale;
	g_Env.water_type = env->water_type;

	g_Env.water_r = env->water_r;
	g_Env.water_g = env->water_g;
	g_Env.water_b = env->water_b;
	g_Env.unk40 = env->unk30;

	if (!env->unk08) {
		g_Env800a65e8 = NULL;
	} else {
		var800a65f0.x = env->unk08;
		var800a65f0.y = env->unk0a;
		var800a65f0.z = env->unk0c;
		g_Env800a65e8 = &var800a65f0;
	}

	g_FogEnabled = false;

	var800a65e4 = env->unk34;
}

void envChooseAndApply(s32 stagenum, bool allowoverride)
{
	struct envtype2 *finalenv = NULL;
	struct envtype2 *env2;
	struct envtype1 *env1;

	if (PLAYERCOUNT());

	var80081050 = MAXFLOAT;

	if (allowoverride) {
		for (env1 = &g_EnvironmentsType1[0]; env1->stage != 0; env1++) {
			if (env1->stage == stagenum + 900) {
				var800a6620 = env1;
				envApplyType1(var800a6620);
				return;
			}
		}
	}

	for (env1 = &g_EnvironmentsType1[0]; env1->stage != 0; env1++) {
		if (env1->stage == stagenum) {
			var800a6620 = env1;
			envApplyType1(var800a6620);
			return;
		}
	}

	for (env2 = &g_EnvironmentsType2[0]; env2->stage != 0; env2++) {
		if (env2->stage == stagenum) {
			finalenv = env2;
		}
	}

	if (env2);

	if (finalenv == NULL) {
		finalenv = &g_EnvironmentsType2[0];
	}

	envApplyType2(finalenv);

	var800a6620 = NULL;
}

Gfx *envStartFog(Gfx *gdl, bool xlupass)
{
	if (!g_FogEnabled) {
		return gdl;
	}

	if (xlupass) {
		gDPSetFogColor(gdl++, g_Env.sky_r, g_Env.sky_g, g_Env.sky_b, 0xff);
		gSPFogPosition(gdl++, g_Env.fogmin, g_Env.fogmax);
	} else {
		gDPSetFogColor(gdl++, g_Env.sky_r, g_Env.sky_g, g_Env.sky_b, 0xff);
		gSPFogPosition(gdl++, g_Env.fogmin, g_Env.fogmax);
	}

	gSPSetGeometryMode(gdl++, G_FOG);
	gDPSetAlphaDither(gdl++, G_AD_NOISE);

	return gdl;
}

Gfx *envStopFog(Gfx *gdl)
{
	if (!g_FogEnabled) {
		return gdl;
	}

	gSPClearGeometryMode(gdl++, G_FOG);

	return gdl;
}

bool env0f1666f8(struct coord *pos, f32 arg1)
{
	struct coord sp24;
	Mtxf *mtx;
	struct coord *campos;
	f32 tmp;

	if (!g_FogEnabled) {
		return true;
	}

	campos = &g_Vars.currentplayer->cam_pos;

	if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
		return true;
	}

	mtx = g_Vars.currentplayer->worldtoscreenmtx;

	sp24.x = pos->x - campos->x;
	sp24.y = pos->y - campos->y;
	sp24.z = pos->z - campos->z;

	tmp = sp24.f[0] * mtx->m[0][0] + sp24.f[1] * mtx->m[0][1] + sp24.f[2] * mtx->m[0][2];

	if (var80081050 + arg1 < tmp) {
		return false;
	}

	return true;
}

s32 env0f1667f4(struct prop *prop, f32 arg1[4])
{
	if (!g_FogEnabled) {
		return 2;
	}

	if (prop->z < 0.0f) {
		return 2;
	}

	if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
		return 2;
	}

	arg1[0] = g_Env.skyredfrac;
	arg1[1] = g_Env.skygreenfrac;
	arg1[2] = g_Env.skybluefrac;
	arg1[3] = var800a6600.unk14 + var800a6600.unk10 / prop->z;

	if (arg1[3] < 0.0f) {
		return 2;
	}

	if (arg1[3] > 1.0f) {
		return 0;
	}

	return 1;
}
