#include <ultra64.h>
#include "constants.h"
#include "game/game_0b3350.h"
#include "game/game_0b4950.h"
#include "game/bg.h"
#include "game/game_165670.h"
#include "bss.h"
#include "lib/vi.h"
#include "data.h"
#include "types.h"

struct coord var800a65f0;
u32 var800a65fc;

struct var800a6600 var800a6600;
u32 var800a6618;
u32 var800a661c;
struct envtype1 *var800a6620;
struct envtype1 *g_EnvTransitionFrom;
struct envtype1 *g_EnvTransitionTo;

f32 var80081050 = MAXFLOAT;
f32 var80081054 = 0;
struct environment g_Env = {900, 1000};
u32 var800810a8 = 0;
u32 var800810ac = 0;

//                   lensflare,    r,    g,    b,        x,       y,        z, texture size, orb size
struct sun sun_00        = { 1, 0xff, 0xff, 0xff, -1000000,  200000,    50000, 20, 48 };
struct sun sun_area51    = { 0, 0xff, 0xe0, 0x80,  -200000,  310000,  1000000, 20, 48 };
struct sun sun_villa     = { 1, 0xff, 0xff, 0xff, -1000000,  200000,    50000, 20, 48 };
struct sun sun_ci        = { 1, 0xff, 0xff, 0xff,   400000,  600000, -1000000, 20, 48 };
struct sun sun_skedar    = { 1, 0xff, 0xff, 0xff,  -400000,  600000,  1000000, 20, 48 };
struct sun sun_05        = { 1, 0xff, 0xff, 0xff,        0, 1000000,  1000000, 25, 60 };
struct sun sun_06        = { 1, 0xff, 0xff, 0xff,   400000,  600000,  1000000, 15, 36 };
struct sun sun_crashsite = { 1, 0xff, 0xd7, 0xf2,  1900000,  300000, -1400000, 22, 48 };
struct sun sun_airbase   = { 1, 0xff, 0xd7, 0xf2, -1200000,  200000,   150000, 30, 60 };

struct envtype1 g_EnvironmentsType1[] = {
	//                                                    |--- fog ----|  |---- sky -----|                     |----------- clouds -----------| |--------------- water ---------------|
	// stage                near    far    06    08   0a     min     max     r     g     b     sun             e  scale    1c     r     g     b 20 21  scale type   r     g     b    28
	{ STAGE_CRASHSITE,        15, 10000,    0,    0,   0, 0x03e2, 0x03e8, 0x9b, 0x2d, 0x1e, 1, &sun_crashsite, 1,  1500, 0x00, 0xfa, 0xfa, 0x00, 0, 0, -5000, 0, 0x00, 0x00, 0x00, 0x00 },
	{ STAGE_PELAGIC,          15, 15000, 3333, 4444, 600, 0x03e3, 0x03e8, 0x2d, 0x3e, 0x60, 0, NULL,           1,  5000, 0x00, 0xf0, 0xf0, 0xf0, 0, 0, -2000, 0, 0x14, 0x21, 0x2b, 0x00 },
	{ STAGE_VILLA,            15, 20000,    0,    0,   0, 0x03d5, 0x0417, 0x46, 0xa0, 0xff, 1, &sun_villa,     1,  5000, 0x00, 0xff, 0xff, 0xff, 0, 0, -1850, 1, 0x00, 0xff, 0xff, 0x00 },
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
	{ STAGE_INFILTRATION,  15, 12000, 0, 0, 0, 0x00, 0x00, 0x00, 1, &sun_area51,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_ESCAPE,        15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 1, &sun_area51,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_TEST_ARCH,     15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_DEEPSEA,       15, 10000, 0, 0, 0, 0x05, 0x00, 0x00, 0, NULL,         0, 0x9b, 0x9b, 0x9b,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_TEST_DEST,     15, 10000, 0, 0, 0, 0x10, 0x30, 0x60, 0, NULL,         1, 0xe6, 0xe6, 0xe6,  3000, 0, 1, 0xff, 0xff, 0x96,   -150,    2, 0, 0 },
	{ STAGE_TEST_LEN,      15, 10000, 0, 0, 0, 0x30, 0x40, 0x10, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_TEST_ASH,      15, 25000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_DEFENSE,       15, 10000, 0, 0, 0, 0x65, 0xb2, 0xff, 1, &sun_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_CITRAINING,    15, 10000, 0, 0, 0, 0x65, 0xb2, 0xff, 1, &sun_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_DUEL,          10, 10000, 0, 0, 0, 0x65, 0xb2, 0xff, 1, &sun_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_RETAKING,      15, 10000, 0, 0, 0, 0x65, 0xb2, 0xff, 1, &sun_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_DEFECTION,     10, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_MBR,           10, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_EXTRACTION,    10, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_SKEDARRUINS,   15, 10000, 0, 0, 0, 0x65, 0x65, 0xff, 3, &sun_skedar,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_WAR,           15, 10000, 0, 0, 0, 0x65, 0x65, 0xff, 3, &sun_skedar,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_TEST_RUN,      15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_MP_SKEDAR,     15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_TEST_SILO,     15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_CHICAGO,       10, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x50, 0x28, 0x0a,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_G5BUILDING,    15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x50, 0x28, 0x0a,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_AIRFORCEONE,   15, 20000, 0, 0, 0, 0x00, 0x10, 0x40, 0, NULL,         1, 0xff, 0xff, 0xff,  5000, 0, 1, 0xff, 0xff, 0xff,  -5000,    2, 0, 1 },
	{ STAGE_MP_RAVINE,     15, 10000, 0, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x50, 0x28, 0x0a,  5000, 0, 0, 0x00, 0x00, 0x00, -31000,    0, 0, 1 },
	{ STAGE_AIRBASE,       15, 20000, 0, 0, 0, 0x00, 0x10, 0x40, 1, &sun_airbase, 1, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
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

void env0f1657c0(s32 arg0, s32 arg1)
{
	// empty
}

struct environment *envGetCurrent(void)
{
	return &g_Env;
}

f32 env0f1657d8(void)
{
	return var80081050;
}

f32 env0f1657e4(void)
{
	return var80081050 * var80081050;
}

GLOBAL_ASM(
glabel env0f1657f8
.late_rodata
glabel var7f1b76e0
.word 0x3a83126f
glabel var7f1b76e4
.word 0x3a83126f
.text
/*  f1657f8:	3c0e800a */ 	lui	$t6,%hi(g_FogEnabled)
/*  f1657fc:	8dce65e0 */ 	lw	$t6,%lo(g_FogEnabled)($t6)
/*  f165800:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f165804:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f165808:	51c0005d */ 	beqzl	$t6,.L0f165980
/*  f16580c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f165810:	0c002fb8 */ 	jal	viGetZRange
/*  f165814:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f165818:	0fc5722e */ 	jal	currentPlayerGetScaleBg2Gfx
/*  f16581c:	00000000 */ 	nop
/*  f165820:	3c048008 */ 	lui	$a0,%hi(g_Env)
/*  f165824:	24841058 */ 	addiu	$a0,$a0,%lo(g_Env)
/*  f165828:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f16582c:	c7a20038 */ 	lwc1	$f2,0x38($sp)
/*  f165830:	c7b0003c */ 	lwc1	$f16,0x3c($sp)
/*  f165834:	448f2000 */ 	mtc1	$t7,$f4
/*  f165838:	3c017f1b */ 	lui	$at,%hi(var7f1b76e0)
/*  f16583c:	c42876e0 */ 	lwc1	$f8,%lo(var7f1b76e0)($at)
/*  f165840:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f165844:	8c980004 */ 	lw	$t8,0x4($a0)
/*  f165848:	3c03800a */ 	lui	$v1,%hi(var800a661c)
/*  f16584c:	2463661c */ 	addiu	$v1,$v1,%lo(var800a661c)
/*  f165850:	44982000 */ 	mtc1	$t8,$f4
/*  f165854:	46001083 */ 	div.s	$f2,$f2,$f0
/*  f165858:	3c017f1b */ 	lui	$at,%hi(var7f1b76e4)
/*  f16585c:	3c05800a */ 	lui	$a1,%hi(var800a6618)
/*  f165860:	24a56618 */ 	addiu	$a1,$a1,%lo(var800a6618)
/*  f165864:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f165868:	3c02800a */ 	lui	$v0,%hi(var800a6600)
/*  f16586c:	24426600 */ 	addiu	$v0,$v0,%lo(var800a6600)
/*  f165870:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f165874:	e46a0000 */ 	swc1	$f10,0x0($v1)
/*  f165878:	c42876e4 */ 	lwc1	$f8,%lo(var7f1b76e4)($at)
/*  f16587c:	3c018008 */ 	lui	$at,%hi(var80081050)
/*  f165880:	46008403 */ 	div.s	$f16,$f16,$f0
/*  f165884:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f165888:	e4aa0000 */ 	swc1	$f10,0x0($a1)
/*  f16588c:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f165890:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f165894:	c7a6001c */ 	lwc1	$f6,0x1c($sp)
/*  f165898:	46028481 */ 	sub.s	$f18,$f16,$f2
/*  f16589c:	46069202 */ 	mul.s	$f8,$f18,$f6
/*  f1658a0:	46081280 */ 	add.s	$f10,$f2,$f8
/*  f1658a4:	e42a1050 */ 	swc1	$f10,%lo(var80081050)($at)
/*  f1658a8:	c46c0000 */ 	lwc1	$f12,0x0($v1)
/*  f1658ac:	3c018008 */ 	lui	$at,%hi(var80081054)
/*  f1658b0:	c7aa001c */ 	lwc1	$f10,0x1c($sp)
/*  f1658b4:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*  f1658b8:	46041180 */ 	add.s	$f6,$f2,$f4
/*  f1658bc:	460c5101 */ 	sub.s	$f4,$f10,$f12
/*  f1658c0:	e4261054 */ 	swc1	$f6,%lo(var80081054)($at)
/*  f1658c4:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f1658c8:	3c014300 */ 	lui	$at,0x4300
/*  f1658cc:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f1658d0:	44813000 */ 	mtc1	$at,$f6
/*  f1658d4:	3c013f00 */ 	lui	$at,0x3f00
/*  f1658d8:	44815000 */ 	mtc1	$at,$f10
/*  f1658dc:	e7a8002c */ 	swc1	$f8,0x2c($sp)
/*  f1658e0:	46043203 */ 	div.s	$f8,$f6,$f4
/*  f1658e4:	3c014380 */ 	lui	$at,0x4380
/*  f1658e8:	e4500004 */ 	swc1	$f16,0x4($v0)
/*  f1658ec:	c44e0004 */ 	lwc1	$f14,0x4($v0)
/*  f1658f0:	460c5181 */ 	sub.s	$f6,$f10,$f12
/*  f1658f4:	44815000 */ 	mtc1	$at,$f10
/*  f1658f8:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f1658fc:	3c013f80 */ 	lui	$at,0x3f80
/*  f165900:	460a3182 */ 	mul.s	$f6,$f6,$f10
/*  f165904:	46043283 */ 	div.s	$f10,$f6,$f4
/*  f165908:	c7a6002c */ 	lwc1	$f6,0x2c($sp)
/*  f16590c:	e7a80028 */ 	swc1	$f8,0x28($sp)
/*  f165910:	46067101 */ 	sub.s	$f4,$f14,$f6
/*  f165914:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f165918:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f16591c:	46004287 */ 	neg.s	$f10,$f8
/*  f165920:	44814000 */ 	mtc1	$at,$f8
/*  f165924:	460e5102 */ 	mul.s	$f4,$f10,$f14
/*  f165928:	3c01437f */ 	lui	$at,0x437f
/*  f16592c:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f165930:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*  f165934:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f165938:	44815000 */ 	mtc1	$at,$f10
/*  f16593c:	3c013f80 */ 	lui	$at,0x3f80
/*  f165940:	46083103 */ 	div.s	$f4,$f6,$f8
/*  f165944:	44814000 */ 	mtc1	$at,$f8
/*  f165948:	3c01437f */ 	lui	$at,0x437f
/*  f16594c:	460a2183 */ 	div.s	$f6,$f4,$f10
/*  f165950:	c7aa0028 */ 	lwc1	$f10,0x28($sp)
/*  f165954:	46087100 */ 	add.s	$f4,$f14,$f8
/*  f165958:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*  f16595c:	e4460010 */ 	swc1	$f6,0x10($v0)
/*  f165960:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f165964:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*  f165968:	46083103 */ 	div.s	$f4,$f6,$f8
/*  f16596c:	44814000 */ 	mtc1	$at,$f8
/*  f165970:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f165974:	46083103 */ 	div.s	$f4,$f6,$f8
/*  f165978:	e4440014 */ 	swc1	$f4,0x14($v0)
/*  f16597c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f165980:
/*  f165980:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f165984:	03e00008 */ 	jr	$ra
/*  f165988:	00000000 */ 	nop
);

void envApplyType1(struct envtype1 *env)
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
		var800a65e8 = NULL;
	} else {
		var800a65f0.x = env->unk06;
		var800a65f0.y = env->unk08;
		var800a65f0.z = env->unk0a;
		var800a65e8 = &var800a65f0;
	}

	env0f1657f8();
}

void envApplyType2(struct envtype2 *env)
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
		var800a65e8 = NULL;
	} else {
		var800a65f0.x = env->unk08;
		var800a65f0.y = env->unk0a;
		var800a65f0.z = env->unk0c;
		var800a65e8 = &var800a65f0;
	}

	g_FogEnabled = false;

	var800a65e4 = env->unk34;
}

void envDisableSky(void)
{
	g_Env.sky_r = 0;
	g_Env.sky_g = 0;
	g_Env.sky_b = 0;

	g_Env.skyredfrac = 0;
	g_Env.skygreenfrac = 0;
	g_Env.skybluefrac = 0;
}

void envSetStageNum(s32 stagenum)
{
	// empty
}

void envChooseAndApply(s32 stagenum, bool allowoverride)
{
	struct envtype2 *finalenv = NULL;
	struct envtype2 *env2;
	struct envtype1 *env1;

	if (PLAYERCOUNT());

	var80081050 = MAXFLOAT;
	var80081054 = 0;

	if (allowoverride) {
		for (env1 = &g_EnvironmentsType1[0]; env1->stage != 0; env1++) {
			if (env1->stage == stagenum + 900) {
				var800a6620 = env1;
				g_EnvTransitionFrom = env1;
				g_EnvTransitionTo = env1 + 1;
				envApplyType1(var800a6620);
				return;
			}
		}
	}

	for (env1 = &g_EnvironmentsType1[0]; env1->stage != 0; env1++) {
		if (env1->stage == stagenum) {
			var800a6620 = env1;
			g_EnvTransitionFrom = env1;
			g_EnvTransitionTo = env1 + 1;
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

void envApplyTransitionFrac(f32 frac)
{
	static struct envtype1 tmp;

	tmp = *g_EnvTransitionFrom;

	tmp.near = g_EnvTransitionFrom->near + frac * ((f32)g_EnvTransitionTo->near - (f32)g_EnvTransitionFrom->near);
	tmp.far = g_EnvTransitionFrom->far + frac * ((f32)g_EnvTransitionTo->far - (f32)g_EnvTransitionFrom->far);
	tmp.fogmin = g_EnvTransitionFrom->fogmin + frac * ((f32)g_EnvTransitionTo->fogmin - (f32)g_EnvTransitionFrom->fogmin);
	tmp.fogmax = g_EnvTransitionFrom->fogmax + frac * ((f32)g_EnvTransitionTo->fogmax - (f32)g_EnvTransitionFrom->fogmax);

	tmp.sky_r = g_EnvTransitionFrom->sky_r + frac * ((f32)g_EnvTransitionTo->sky_r - (f32)g_EnvTransitionFrom->sky_r);
	tmp.sky_g = g_EnvTransitionFrom->sky_g + frac * ((f32)g_EnvTransitionTo->sky_g - (f32)g_EnvTransitionFrom->sky_g);
	tmp.sky_b = g_EnvTransitionFrom->sky_b + frac * ((f32)g_EnvTransitionTo->sky_b - (f32)g_EnvTransitionFrom->sky_b);

	tmp.sky_r &= 0xf8;
	tmp.sky_g &= 0xf8;
	tmp.sky_b &= 0xf8;

	envApplyType1(&tmp);
}

Gfx *envStartFog(Gfx *gdl, bool withalpha)
{
	if (!g_FogEnabled) {
		return gdl;
	}

	if (withalpha) {
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

	mtx = currentPlayerGetMatrix1740();

	sp24.x = pos->x - campos->x;
	sp24.y = pos->y - campos->y;
	sp24.z = pos->z - campos->z;

	tmp = sp24.f[0] * mtx->m[0][0] + sp24.f[1] * mtx->m[0][1] + sp24.f[2] * mtx->m[0][2];

	if (var80081050 + arg1 < tmp) {
		return false;
	}

	return true;
}

struct coord *env0f1667e8(void)
{
	return var800a65e8;
}

s32 env0f1667f4(struct prop *prop, f32 *arg1)
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
