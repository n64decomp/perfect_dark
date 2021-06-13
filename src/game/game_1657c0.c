#include <ultra64.h>
#include "constants.h"
#include "game/game_0b3350.h"
#include "game/bg.h"
#include "game/game_165670.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "data.h"
#include "types.h"

struct coord var800a65f0;
u32 var800a65fc;
u32 var800a6600;
u32 var800a6604;
u32 var800a6608;
u32 var800a660c;
u32 var800a6610;
u32 var800a6614;
u32 var800a6618;
u32 var800a661c;
struct smallsky *var800a6620;
struct smallsky *var800a6624;
struct smallsky *var800a6628;
u32 var800a662c;
u32 var800a6630;
u32 var800a6634;
u32 var800a6638;
u32 var800a663c;
u32 var800a6640;
u32 var800a6644;
u32 var800a6648;
u32 var800a664c;
u32 var800a6650;
u32 var800a6654;
u32 var800a6658;
u32 var800a665c;

f32 var80081050 = MAXFLOAT;
f32 var80081054 = 0;
struct var80081058 var80081058 = {900, 1000};
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

struct smallsky g_SmallSkies[] = {
	//                                                             |------ sky ------|                  |-------------- clouds --------------|                      |-------- water --------|
	// stage                 blend  far  06    08   0a      0c      0e     r     g     b  e  sun             e    19     1a    1c     r     g     b    20      22    23  e     r     g     b    28
	{ STAGE_CRASHSITE,        15, 10000,    0,    0,   0, 0x03e2, 0x03e8, 0x9b, 0x2d, 0x1e, 1, &sun_crashsite, 1, 0x00,  1500, 0x00, 0xfa, 0xfa, 0x00, 0, 0, 0xec78, 0, 0x00, 0x00, 0x00, 0x00 },
	{ STAGE_PELAGIC,          15, 15000, 3333, 4444, 600, 0x03e3, 0x03e8, 0x2d, 0x3e, 0x60, 0, NULL,           1, 0x00,  5000, 0x00, 0xf0, 0xf0, 0xf0, 0, 0, 0xf830, 0, 0x14, 0x21, 0x2b, 0x00 },
	{ STAGE_VILLA,            15, 20000,    0,    0,   0, 0x03d5, 0x0417, 0x46, 0xa0, 0xff, 1, &sun_villa,     1, 0x00,  5000, 0x00, 0xff, 0xff, 0xff, 0, 0, 0xf8c6, 1, 0x00, 0xff, 0xff, 0x00 },
	{ STAGE_PELAGIC + 900,    30, 15000, 3333, 4444, 600, 0x03e3, 0x03e8, 0x10, 0x30, 0x60, 0, NULL,           1, 0x00,  5000, 0x00, 0xff, 0xff, 0xff, 0, 0, 0xfc18, 0, 0x00, 0x00, 0x00, 0x00 },
	{ STAGE_24,                2, 25000,    0,    0,   0, 0x03e4, 0x03e8, 0x00, 0x00, 0x00, 0, NULL,           1, 0x00, 10000, 0x00, 0xff, 0xff, 0xff, 0, 0, 0x0000, 1, 0x00, 0xff, 0xff, 0x07 },
	{ STAGE_2B,                2,  2000, 2500, 3055, 750, 0x03bd, 0x03e8, 0x20, 0x10, 0x10, 0, NULL,           1, 0x00,  5000, 0x00, 0x3a, 0x11, 0x00, 0, 0, 0xfc18, 1, 0x00, 0xff, 0xff, 0x14 },
	{ STAGE_2B + 900,          2,  8000, 6000, 8000, 800, 0x03df, 0x03e8, 0x20, 0x10, 0x10, 0, NULL,           1, 0x00,  5000, 0x00, 0x3a, 0x11, 0x00, 0, 0, 0xfc18, 1, 0x00, 0xff, 0xff, 0x00 },
	{ 0x00ee,                 10,  6000,    0,    0,   0, 0x03e4, 0x03e8, 0x18, 0x18, 0x18, 0, NULL,           1, 0x00, 10000, 0x00, 0x78, 0x78, 0x78, 0, 0, 0xfe0c, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x0152,                 10,  6000,    0,    0,   0, 0x03e4, 0x03e8, 0x18, 0x18, 0x18, 0, NULL,           1, 0x00, 10000, 0x00, 0x78, 0x78, 0x78, 0, 0, 0xfe0c, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x01b6,                 10,  6000,    0,    0,   0, 0x03e4, 0x03e8, 0x18, 0x18, 0x18, 0, NULL,           1, 0x00, 10000, 0x00, 0x78, 0x78, 0x78, 0, 0, 0xfe0c, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00c8,                 10,  7500,    0,    0,   0, 0x03e4, 0x03e8, 0x00, 0x00, 0x00, 0, NULL,           0, 0x00,     0, 0x00, 0x00, 0x00, 0x00, 0, 0, 0x0000, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x012c,                 10,  6000,    0,    0,   0, 0x03e4, 0x03e8, 0x00, 0x00, 0x00, 0, NULL,           0, 0x00,     0, 0x00, 0x00, 0x00, 0x00, 0, 0, 0x0000, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x0190,                 10,  5000,    0,    0,   0, 0x03e4, 0x03e8, 0x00, 0x00, 0x00, 0, NULL,           0, 0x00,     0, 0x00, 0x00, 0x00, 0x00, 0, 0, 0x0000, 0, 0x00, 0x00, 0x00, 0x00 },
	{ 0x0000,                  0,     0,    0,    0,   0, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0, NULL,           0, 0x00,     0, 0x00, 0x00, 0x00, 0x00, 0, 0, 0x0000, 0, 0x00, 0x00, 0x00, 0x00 },
};

struct sky g_Skies[] = {
	//                                                                         |-------- clouds --------|     |------------ water ------------|
	// stage               04  06    08 0c     r     g     b     sun           e     r     g     b  scale 20  e     r     g     b   scale  type 30 34
	{ -1,                  15, 10000, 0, 0, 0x00, 0x10, 0x40, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_RESCUE,        15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_MAIANSOS,      15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_ATTACKSHIP,    15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_INFILTRATION,  15, 12000, 0, 0, 0x00, 0x00, 0x00, 1, &sun_area51,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_ESCAPE,        15, 10000, 0, 0, 0x00, 0x00, 0x00, 1, &sun_area51,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_TEST_ARCH,     15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_DEEPSEA,       15, 10000, 0, 0, 0x05, 0x00, 0x00, 0, NULL,         0, 0x9b, 0x9b, 0x9b,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_TEST_DEST,     15, 10000, 0, 0, 0x10, 0x30, 0x60, 0, NULL,         1, 0xe6, 0xe6, 0xe6,  3000, 0, 1, 0xff, 0xff, 0x96,   -150,    2, 0, 0 },
	{ STAGE_TEST_LEN,      15, 10000, 0, 0, 0x30, 0x40, 0x10, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 0 },
	{ STAGE_TEST_ASH,      15, 25000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_DEFENSE,       15, 10000, 0, 0, 0x65, 0xb2, 0xff, 1, &sun_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_CITRAINING,    15, 10000, 0, 0, 0x65, 0xb2, 0xff, 1, &sun_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_DUEL,          10, 10000, 0, 0, 0x65, 0xb2, 0xff, 1, &sun_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_RETAKING,      15, 10000, 0, 0, 0x65, 0xb2, 0xff, 1, &sun_ci,      0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_DEFECTION,     10, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_MBR,           10, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_EXTRACTION,    10, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_SKEDARRUINS,   15, 10000, 0, 0, 0x65, 0x65, 0xff, 3, &sun_skedar,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_WAR,           15, 10000, 0, 0, 0x65, 0x65, 0xff, 3, &sun_skedar,  0, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_TEST_RUN,      15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,      0,    0, 0, 1 },
	{ STAGE_MP_SKEDAR,     15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_TEST_SILO,     15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x3a, 0x11, 0x00,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_CHICAGO,       10, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x50, 0x28, 0x0a,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_G5BUILDING,    15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x50, 0x28, 0x0a,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_AIRFORCEONE,   15, 20000, 0, 0, 0x00, 0x10, 0x40, 0, NULL,         1, 0xff, 0xff, 0xff,  5000, 0, 1, 0xff, 0xff, 0xff,  -5000,    2, 0, 1 },
	{ STAGE_MP_RAVINE,     15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x50, 0x28, 0x0a,  5000, 0, 0, 0x00, 0x00, 0x00, -31000,    0, 0, 1 },
	{ STAGE_AIRBASE,       15, 20000, 0, 0, 0x00, 0x10, 0x40, 1, &sun_airbase, 1, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_INVESTIGATION, 15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ STAGE_MP_PIPES,      15, 10000, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x46, 0xc7, 0xba,  4500, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_G5BUILDING, 15, 10000, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x5a, 0x90, 0xa5,  4500, 0, 0, 0x00, 0x00, 0x00, -20000,    0, 0, 0 },
	{ STAGE_MP_TEMPLE,     15, 10000, 0, 0, 0x00, 0x10, 0x80, 0, NULL,         1, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0xff, 0xff,  -1850,    1, 0, 1 },
	{ STAGE_MP_COMPLEX,    15, 10000, 0, 0, 0x02, 0x00, 0x00, 0, NULL,         1, 0x82, 0xaa, 0xc8,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_UFF,      10, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_OLD,      15, 30000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_LAM,      15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_BASE,       15, 20000, 0, 0, 0x04, 0x00, 0x00, 0, NULL,         1, 0x82, 0xb4, 0x64,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP2,      15, 20000, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x46, 0xc7, 0xba,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_AREA52,     15, 10000, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x46, 0xc7, 0xba,  4500, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_WAREHOUSE,  15, 10000, 0, 0, 0x02, 0x00, 0x00, 0, NULL,         1, 0x82, 0xaa, 0xc8,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_CARPARK,    15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x64, 0xc8, 0x86,  5500, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP6,      15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP7,      15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP8,      15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_RUINS,      15, 10000, 0, 0, 0x03, 0x00, 0x00, 0, NULL,         1, 0x82, 0xe6, 0xaa,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_SEWERS,     15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x64, 0x64, 0x64,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_FELICITY,   10, 10000, 0, 0, 0x04, 0x05, 0x00, 0, NULL,         1, 0x64, 0xd2, 0x82,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_FORTRESS,   15, 10000, 0, 0, 0x00, 0x00, 0x08, 0, NULL,         1, 0x5a, 0x90, 0xa5,  5500, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_VILLA,      15, 10000, 0, 0, 0x88, 0x88, 0xdc, 0, NULL,         1, 0xff, 0xaa, 0x2a,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP14,     15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_MP_GRID,       15, 10000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP16,     15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP17,     15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         1, 0x64, 0xc8, 0x86, 10000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP18,     15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP19,     15, 20000, 0, 0, 0x00, 0x00, 0x00, 0, NULL,         0, 0x1e, 0x1e, 0x1e,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 0 },
	{ STAGE_TEST_MP20,     15, 20000, 0, 0, 0x00, 0x10, 0x3c, 0, NULL,         1, 0xff, 0xff, 0xff,  5000, 0, 0, 0x00, 0x00, 0x00,  -5000,    0, 0, 1 },
	{ 0 },
};

GLOBAL_ASM(
glabel func0f1657c0
/*  f1657c0:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f1657c4:	03e00008 */ 	jr	$ra
/*  f1657c8:	afa50004 */ 	sw	$a1,0x4($sp)
);

GLOBAL_ASM(
glabel func0f1657cc
/*  f1657cc:	3c028008 */ 	lui	$v0,%hi(var80081058)
/*  f1657d0:	03e00008 */ 	jr	$ra
/*  f1657d4:	24421058 */ 	addiu	$v0,$v0,%lo(var80081058)
/*  f1657d8:	3c018008 */ 	lui	$at,%hi(var80081050)
/*  f1657dc:	03e00008 */ 	jr	$ra
/*  f1657e0:	c4201050 */ 	lwc1	$f0,%lo(var80081050)($at)
);

f32 func0f1657e4(void)
{
	return var80081050 * var80081050;
}

GLOBAL_ASM(
glabel func0f1657f8
.late_rodata
glabel var7f1b76e0
.word 0x3a83126f
glabel var7f1b76e4
.word 0x3a83126f
.text
/*  f1657f8:	3c0e800a */ 	lui	$t6,%hi(g_FogDisabled)
/*  f1657fc:	8dce65e0 */ 	lw	$t6,%lo(g_FogDisabled)($t6)
/*  f165800:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f165804:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f165808:	51c0005d */ 	beqzl	$t6,.L0f165980
/*  f16580c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f165810:	0c002fb8 */ 	jal	viGetZRange
/*  f165814:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f165818:	0fc5722e */ 	jal	currentPlayerGetScaleBg2Gfx
/*  f16581c:	00000000 */ 	nop
/*  f165820:	3c048008 */ 	lui	$a0,%hi(var80081058)
/*  f165824:	24841058 */ 	addiu	$a0,$a0,%lo(var80081058)
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

void func0f16598c(struct smallsky *sky)
{
	g_FogDisabled = true;
	var800a65e4 = 0;

	viSetZRange(sky->blend_multiplier, sky->sky_far);

	var80081058.unk00 = sky->unk0c;
	var80081058.unk04 = sky->unk0e;
	var80081058.sky_r = sky->sky_r;
	var80081058.sky_g = sky->sky_g;
	var80081058.sky_b = sky->sky_b;
	var80081058.unk44 = var80081058.sky_r / 255.0f;
	var80081058.unk48 = var80081058.sky_g / 255.0f;
	var80081058.unk4c = var80081058.sky_b / 255.0f;
	var80081058.sky_enabled = sky->sky_enabled;
	var80081058.sun = sky->sun;
	var80081058.clouds_enabled = sky->clouds_enabled;
	var80081058.unk14 = sky->unk1a;
	var80081058.unk18 = sky->unk1c;
	var80081058.clouds_r = sky->clouds_r;
	var80081058.clouds_g = sky->clouds_g;
	var80081058.clouds_b = sky->clouds_b;
	var80081058.unk28 = sky->unk20;
	var80081058.unk2c = sky->unk22;
	var80081058.water_enabled = sky->water_enabled;
	var80081058.water_r = sky->water_r;
	var80081058.water_g = sky->water_g;
	var80081058.water_b = sky->water_b;
	var80081058.unk40 = sky->unk28;

	if (!sky->unk06) {
		var800a65e8 = NULL;
	} else {
		var800a65f0.x = (f32)sky->unk06;
		var800a65f0.y = (f32)sky->unk08;
		var800a65f0.z = (f32)sky->unk0a;
		var800a65e8 = &var800a65f0;
	}

	func0f1657f8();
}

GLOBAL_ASM(
glabel func0f165c4c
/*  f165c4c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f165c50:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f165c54:	848f0006 */ 	lh	$t7,0x6($a0)
/*  f165c58:	848e0004 */ 	lh	$t6,0x4($a0)
/*  f165c5c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f165c60:	448f3000 */ 	mtc1	$t7,$f6
/*  f165c64:	448e2000 */ 	mtc1	$t6,$f4
/*  f165c68:	468033a0 */ 	cvt.s.w	$f14,$f6
/*  f165c6c:	0c002fa1 */ 	jal	viSetZRange
/*  f165c70:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f165c74:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f165c78:	3c028008 */ 	lui	$v0,%hi(var80081058)
/*  f165c7c:	24421058 */ 	addiu	$v0,$v0,%lo(var80081058)
/*  f165c80:	9098000e */ 	lbu	$t8,0xe($a0)
/*  f165c84:	3c01437f */ 	lui	$at,0x437f
/*  f165c88:	44810000 */ 	mtc1	$at,$f0
/*  f165c8c:	a0580008 */ 	sb	$t8,0x8($v0)
/*  f165c90:	9099000f */ 	lbu	$t9,0xf($a0)
/*  f165c94:	330900ff */ 	andi	$t1,$t8,0xff
/*  f165c98:	44894000 */ 	mtc1	$t1,$f8
/*  f165c9c:	a0590009 */ 	sb	$t9,0x9($v0)
/*  f165ca0:	90880010 */ 	lbu	$t0,0x10($a0)
/*  f165ca4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f165ca8:	05210005 */ 	bgez	$t1,.L0f165cc0
/*  f165cac:	a048000a */ 	sb	$t0,0xa($v0)
/*  f165cb0:	3c014f80 */ 	lui	$at,0x4f80
/*  f165cb4:	44818000 */ 	mtc1	$at,$f16
/*  f165cb8:	00000000 */ 	nop
/*  f165cbc:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f165cc0:
/*  f165cc0:	46005483 */ 	div.s	$f18,$f10,$f0
/*  f165cc4:	904a0009 */ 	lbu	$t2,0x9($v0)
/*  f165cc8:	3c014f80 */ 	lui	$at,0x4f80
/*  f165ccc:	448a2000 */ 	mtc1	$t2,$f4
/*  f165cd0:	00000000 */ 	nop
/*  f165cd4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f165cd8:	05410004 */ 	bgez	$t2,.L0f165cec
/*  f165cdc:	e4520044 */ 	swc1	$f18,0x44($v0)
/*  f165ce0:	44814000 */ 	mtc1	$at,$f8
/*  f165ce4:	00000000 */ 	nop
/*  f165ce8:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f165cec:
/*  f165cec:	46003403 */ 	div.s	$f16,$f6,$f0
/*  f165cf0:	904b000a */ 	lbu	$t3,0xa($v0)
/*  f165cf4:	3c014f80 */ 	lui	$at,0x4f80
/*  f165cf8:	448b5000 */ 	mtc1	$t3,$f10
/*  f165cfc:	00000000 */ 	nop
/*  f165d00:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f165d04:	05610004 */ 	bgez	$t3,.L0f165d18
/*  f165d08:	e4500048 */ 	swc1	$f16,0x48($v0)
/*  f165d0c:	44812000 */ 	mtc1	$at,$f4
/*  f165d10:	00000000 */ 	nop
/*  f165d14:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f165d18:
/*  f165d18:	46009203 */ 	div.s	$f8,$f18,$f0
/*  f165d1c:	3c014f80 */ 	lui	$at,0x4f80
/*  f165d20:	e448004c */ 	swc1	$f8,0x4c($v0)
/*  f165d24:	908c0011 */ 	lbu	$t4,0x11($a0)
/*  f165d28:	a04c000b */ 	sb	$t4,0xb($v0)
/*  f165d2c:	8c8d0014 */ 	lw	$t5,0x14($a0)
/*  f165d30:	ac4d000c */ 	sw	$t5,0xc($v0)
/*  f165d34:	908e0018 */ 	lbu	$t6,0x18($a0)
/*  f165d38:	a04e0010 */ 	sb	$t6,0x10($v0)
/*  f165d3c:	c486001c */ 	lwc1	$f6,0x1c($a0)
/*  f165d40:	e4460014 */ 	swc1	$f6,0x14($v0)
/*  f165d44:	848f0020 */ 	lh	$t7,0x20($a0)
/*  f165d48:	a44f0018 */ 	sh	$t7,0x18($v0)
/*  f165d4c:	90980019 */ 	lbu	$t8,0x19($a0)
/*  f165d50:	44988000 */ 	mtc1	$t8,$f16
/*  f165d54:	07010004 */ 	bgez	$t8,.L0f165d68
/*  f165d58:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f165d5c:	44812000 */ 	mtc1	$at,$f4
/*  f165d60:	00000000 */ 	nop
/*  f165d64:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f165d68:
/*  f165d68:	e44a001c */ 	swc1	$f10,0x1c($v0)
/*  f165d6c:	9099001a */ 	lbu	$t9,0x1a($a0)
/*  f165d70:	3c014f80 */ 	lui	$at,0x4f80
/*  f165d74:	44999000 */ 	mtc1	$t9,$f18
/*  f165d78:	07210004 */ 	bgez	$t9,.L0f165d8c
/*  f165d7c:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f165d80:	44813000 */ 	mtc1	$at,$f6
/*  f165d84:	00000000 */ 	nop
/*  f165d88:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f165d8c:
/*  f165d8c:	e4480020 */ 	swc1	$f8,0x20($v0)
/*  f165d90:	9088001b */ 	lbu	$t0,0x1b($a0)
/*  f165d94:	3c014f80 */ 	lui	$at,0x4f80
/*  f165d98:	44888000 */ 	mtc1	$t0,$f16
/*  f165d9c:	05010004 */ 	bgez	$t0,.L0f165db0
/*  f165da0:	46808120 */ 	cvt.s.w	$f4,$f16
/*  f165da4:	44815000 */ 	mtc1	$at,$f10
/*  f165da8:	00000000 */ 	nop
/*  f165dac:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f165db0:
/*  f165db0:	e4440024 */ 	swc1	$f4,0x24($v0)
/*  f165db4:	90890022 */ 	lbu	$t1,0x22($a0)
/*  f165db8:	3c014f80 */ 	lui	$at,0x4f80
/*  f165dbc:	a0490028 */ 	sb	$t1,0x28($v0)
/*  f165dc0:	c4920028 */ 	lwc1	$f18,0x28($a0)
/*  f165dc4:	e452002c */ 	swc1	$f18,0x2c($v0)
/*  f165dc8:	848a002c */ 	lh	$t2,0x2c($a0)
/*  f165dcc:	a44a0030 */ 	sh	$t2,0x30($v0)
/*  f165dd0:	908b0023 */ 	lbu	$t3,0x23($a0)
/*  f165dd4:	448b3000 */ 	mtc1	$t3,$f6
/*  f165dd8:	05610004 */ 	bgez	$t3,.L0f165dec
/*  f165ddc:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f165de0:	44818000 */ 	mtc1	$at,$f16
/*  f165de4:	00000000 */ 	nop
/*  f165de8:	46104200 */ 	add.s	$f8,$f8,$f16
.L0f165dec:
/*  f165dec:	e4480034 */ 	swc1	$f8,0x34($v0)
/*  f165df0:	908c0024 */ 	lbu	$t4,0x24($a0)
/*  f165df4:	3c014f80 */ 	lui	$at,0x4f80
/*  f165df8:	448c5000 */ 	mtc1	$t4,$f10
/*  f165dfc:	05810004 */ 	bgez	$t4,.L0f165e10
/*  f165e00:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f165e04:	44819000 */ 	mtc1	$at,$f18
/*  f165e08:	00000000 */ 	nop
/*  f165e0c:	46122100 */ 	add.s	$f4,$f4,$f18
.L0f165e10:
/*  f165e10:	e4440038 */ 	swc1	$f4,0x38($v0)
/*  f165e14:	908d0025 */ 	lbu	$t5,0x25($a0)
/*  f165e18:	3c014f80 */ 	lui	$at,0x4f80
/*  f165e1c:	448d3000 */ 	mtc1	$t5,$f6
/*  f165e20:	05a10004 */ 	bgez	$t5,.L0f165e34
/*  f165e24:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f165e28:	44814000 */ 	mtc1	$at,$f8
/*  f165e2c:	00000000 */ 	nop
/*  f165e30:	46088400 */ 	add.s	$f16,$f16,$f8
.L0f165e34:
/*  f165e34:	e450003c */ 	swc1	$f16,0x3c($v0)
/*  f165e38:	c48a0030 */ 	lwc1	$f10,0x30($a0)
/*  f165e3c:	3c01800a */ 	lui	$at,%hi(var800a65e8)
/*  f165e40:	e44a0040 */ 	swc1	$f10,0x40($v0)
/*  f165e44:	84830008 */ 	lh	$v1,0x8($a0)
/*  f165e48:	54600004 */ 	bnezl	$v1,.L0f165e5c
/*  f165e4c:	44839000 */ 	mtc1	$v1,$f18
/*  f165e50:	10000012 */ 	b	.L0f165e9c
/*  f165e54:	ac2065e8 */ 	sw	$zero,%lo(var800a65e8)($at)
/*  f165e58:	44839000 */ 	mtc1	$v1,$f18
.L0f165e5c:
/*  f165e5c:	3c02800a */ 	lui	$v0,%hi(var800a65f0)
/*  f165e60:	244265f0 */ 	addiu	$v0,$v0,%lo(var800a65f0)
/*  f165e64:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f165e68:	3c01800a */ 	lui	$at,%hi(var800a65e8)
/*  f165e6c:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f165e70:	848e000a */ 	lh	$t6,0xa($a0)
/*  f165e74:	448e3000 */ 	mtc1	$t6,$f6
/*  f165e78:	00000000 */ 	nop
/*  f165e7c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f165e80:	e4480004 */ 	swc1	$f8,0x4($v0)
/*  f165e84:	848f000c */ 	lh	$t7,0xc($a0)
/*  f165e88:	448f8000 */ 	mtc1	$t7,$f16
/*  f165e8c:	00000000 */ 	nop
/*  f165e90:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f165e94:	e44a0008 */ 	swc1	$f10,0x8($v0)
/*  f165e98:	ac2265e8 */ 	sw	$v0,%lo(var800a65e8)($at)
.L0f165e9c:
/*  f165e9c:	3c01800a */ 	lui	$at,%hi(g_FogDisabled)
/*  f165ea0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f165ea4:	ac2065e0 */ 	sw	$zero,%lo(g_FogDisabled)($at)
/*  f165ea8:	8c980034 */ 	lw	$t8,0x34($a0)
/*  f165eac:	3c01800a */ 	lui	$at,%hi(var800a65e4)
/*  f165eb0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f165eb4:	03e00008 */ 	jr	$ra
/*  f165eb8:	ac3865e4 */ 	sw	$t8,%lo(var800a65e4)($at)
/*  f165ebc:	3c028008 */ 	lui	$v0,%hi(var80081058)
/*  f165ec0:	24421058 */ 	addiu	$v0,$v0,%lo(var80081058)
/*  f165ec4:	44800000 */ 	mtc1	$zero,$f0
/*  f165ec8:	a0400008 */ 	sb	$zero,0x8($v0)
/*  f165ecc:	a0400009 */ 	sb	$zero,0x9($v0)
/*  f165ed0:	a040000a */ 	sb	$zero,0xa($v0)
/*  f165ed4:	e4400044 */ 	swc1	$f0,0x44($v0)
/*  f165ed8:	e4400048 */ 	swc1	$f0,0x48($v0)
/*  f165edc:	03e00008 */ 	jr	$ra
/*  f165ee0:	e440004c */ 	swc1	$f0,0x4c($v0)
);

void skySetStageNum(s32 stagenum)
{
	// empty
}

void func0f165eec(s32 stagenum, bool arg1)
{
	struct sky *finalsky = NULL;
	struct sky *sky;
	struct smallsky *smallsky;

	if (PLAYERCOUNT());

	var80081050 = MAXFLOAT;
	var80081054 = 0;

	if (arg1) {
		for (smallsky = &g_SmallSkies[0]; smallsky->stage != 0; smallsky++) {
			if (smallsky->stage == stagenum + 900) {
				var800a6620 = smallsky;
				var800a6624 = smallsky;
				var800a6628 = smallsky+ 1;
				func0f16598c(var800a6620);
				return;
			}
		}
	}

	for (smallsky = &g_SmallSkies[0]; smallsky->stage != 0; smallsky++) {
		if (smallsky->stage == stagenum) {
			var800a6620 = smallsky;
			var800a6624 = smallsky;
			var800a6628 = smallsky + 1;
			func0f16598c(var800a6620);
			return;
		}
	}

	for (sky = &g_Skies[0]; sky->stage != 0; sky++) {
		if (sky->stage == stagenum) {
			finalsky = sky;
		}
	}

	if (sky);

	if (finalsky == NULL) {
		finalsky = &g_Skies[0];
	}

	func0f165c4c(finalsky);

	var800a6620 = NULL;
}

GLOBAL_ASM(
glabel func0f1660a4
/*  f1660a4:	3c02800a */ 	lui	$v0,%hi(var800a6624)
/*  f1660a8:	8c426624 */ 	lw	$v0,%lo(var800a6624)($v0)
/*  f1660ac:	3c04800a */ 	lui	$a0,%hi(var800a6630)
/*  f1660b0:	24846630 */ 	addiu	$a0,$a0,%lo(var800a6630)
/*  f1660b4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1660b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1660bc:	00804025 */ 	or	$t0,$a0,$zero
/*  f1660c0:	0040c825 */ 	or	$t9,$v0,$zero
/*  f1660c4:	24580024 */ 	addiu	$t8,$v0,0x24
.L0f1660c8:
/*  f1660c8:	8f210000 */ 	lw	$at,0x0($t9)
/*  f1660cc:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f1660d0:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f1660d4:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f1660d8:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f1660dc:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f1660e0:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f1660e4:	1738fff8 */ 	bne	$t9,$t8,.L0f1660c8
/*  f1660e8:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f1660ec:	8f210000 */ 	lw	$at,0x0($t9)
/*  f1660f0:	3c03800a */ 	lui	$v1,%hi(var800a6628)
/*  f1660f4:	ad010000 */ 	sw	$at,0x0($t0)
/*  f1660f8:	8f380004 */ 	lw	$t8,0x4($t9)
/*  f1660fc:	3c01800a */ 	lui	$at,%hi(var800a6630)
/*  f166100:	ad180004 */ 	sw	$t8,0x4($t0)
/*  f166104:	8c636628 */ 	lw	$v1,%lo(var800a6628)($v1)
/*  f166108:	84490002 */ 	lh	$t1,0x2($v0)
/*  f16610c:	846a0002 */ 	lh	$t2,0x2($v1)
/*  f166110:	44892000 */ 	mtc1	$t1,$f4
/*  f166114:	448a3000 */ 	mtc1	$t2,$f6
/*  f166118:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f16611c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f166120:	46004281 */ 	sub.s	$f10,$f8,$f0
/*  f166124:	460a6102 */ 	mul.s	$f4,$f12,$f10
/*  f166128:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f16612c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f166130:	440c4000 */ 	mfc1	$t4,$f8
/*  f166134:	00000000 */ 	nop
/*  f166138:	a42c6632 */ 	sh	$t4,%lo(var800a6630+0x2)($at)
/*  f16613c:	844d0004 */ 	lh	$t5,0x4($v0)
/*  f166140:	846f0004 */ 	lh	$t7,0x4($v1)
/*  f166144:	448d5000 */ 	mtc1	$t5,$f10
/*  f166148:	448f2000 */ 	mtc1	$t7,$f4
/*  f16614c:	468050a0 */ 	cvt.s.w	$f2,$f10
/*  f166150:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f166154:	46023201 */ 	sub.s	$f8,$f6,$f2
/*  f166158:	46086282 */ 	mul.s	$f10,$f12,$f8
/*  f16615c:	460a1100 */ 	add.s	$f4,$f2,$f10
/*  f166160:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f166164:	44183000 */ 	mfc1	$t8,$f6
/*  f166168:	00000000 */ 	nop
/*  f16616c:	a4386634 */ 	sh	$t8,%lo(var800a6630+0x4)($at)
/*  f166170:	8459000c */ 	lh	$t9,0xc($v0)
/*  f166174:	8468000c */ 	lh	$t0,0xc($v1)
/*  f166178:	3c01800a */ 	lui	$at,%hi(var800a663c)
/*  f16617c:	44994000 */ 	mtc1	$t9,$f8
/*  f166180:	44885000 */ 	mtc1	$t0,$f10
/*  f166184:	468043a0 */ 	cvt.s.w	$f14,$f8
/*  f166188:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f16618c:	460e2181 */ 	sub.s	$f6,$f4,$f14
/*  f166190:	46066202 */ 	mul.s	$f8,$f12,$f6
/*  f166194:	46087280 */ 	add.s	$f10,$f14,$f8
/*  f166198:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f16619c:	440a2000 */ 	mfc1	$t2,$f4
/*  f1661a0:	00000000 */ 	nop
/*  f1661a4:	a42a663c */ 	sh	$t2,%lo(var800a663c)($at)
/*  f1661a8:	844b000e */ 	lh	$t3,0xe($v0)
/*  f1661ac:	846c000e */ 	lh	$t4,0xe($v1)
/*  f1661b0:	448b3000 */ 	mtc1	$t3,$f6
/*  f1661b4:	448c4000 */ 	mtc1	$t4,$f8
/*  f1661b8:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f1661bc:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1661c0:	46105101 */ 	sub.s	$f4,$f10,$f16
/*  f1661c4:	46046182 */ 	mul.s	$f6,$f12,$f4
/*  f1661c8:	46068200 */ 	add.s	$f8,$f16,$f6
/*  f1661cc:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1661d0:	440f5000 */ 	mfc1	$t7,$f10
/*  f1661d4:	00000000 */ 	nop
/*  f1661d8:	a42f663e */ 	sh	$t7,%lo(var800a6630+0xe)($at)
/*  f1661dc:	904e0010 */ 	lbu	$t6,0x10($v0)
/*  f1661e0:	3c014f80 */ 	lui	$at,0x4f80
/*  f1661e4:	448e2000 */ 	mtc1	$t6,$f4
/*  f1661e8:	05c10004 */ 	bgez	$t6,.L0f1661fc
/*  f1661ec:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f1661f0:	44813000 */ 	mtc1	$at,$f6
/*  f1661f4:	00000000 */ 	nop
/*  f1661f8:	46069480 */ 	add.s	$f18,$f18,$f6
.L0f1661fc:
/*  f1661fc:	90780010 */ 	lbu	$t8,0x10($v1)
/*  f166200:	3c014f80 */ 	lui	$at,0x4f80
/*  f166204:	44984000 */ 	mtc1	$t8,$f8
/*  f166208:	07010004 */ 	bgez	$t8,.L0f16621c
/*  f16620c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f166210:	44812000 */ 	mtc1	$at,$f4
/*  f166214:	00000000 */ 	nop
/*  f166218:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f16621c:
/*  f16621c:	46125181 */ 	sub.s	$f6,$f10,$f18
/*  f166220:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f166224:	3c014f00 */ 	lui	$at,0x4f00
/*  f166228:	46066202 */ 	mul.s	$f8,$f12,$f6
/*  f16622c:	46089100 */ 	add.s	$f4,$f18,$f8
/*  f166230:	4459f800 */ 	cfc1	$t9,$31
/*  f166234:	44c8f800 */ 	ctc1	$t0,$31
/*  f166238:	00000000 */ 	nop
/*  f16623c:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f166240:	4448f800 */ 	cfc1	$t0,$31
/*  f166244:	00000000 */ 	nop
/*  f166248:	31080078 */ 	andi	$t0,$t0,0x78
/*  f16624c:	51000013 */ 	beqzl	$t0,.L0f16629c
/*  f166250:	44085000 */ 	mfc1	$t0,$f10
/*  f166254:	44815000 */ 	mtc1	$at,$f10
/*  f166258:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f16625c:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f166260:	44c8f800 */ 	ctc1	$t0,$31
/*  f166264:	00000000 */ 	nop
/*  f166268:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f16626c:	4448f800 */ 	cfc1	$t0,$31
/*  f166270:	00000000 */ 	nop
/*  f166274:	31080078 */ 	andi	$t0,$t0,0x78
/*  f166278:	15000005 */ 	bnez	$t0,.L0f166290
/*  f16627c:	00000000 */ 	nop
/*  f166280:	44085000 */ 	mfc1	$t0,$f10
/*  f166284:	3c018000 */ 	lui	$at,0x8000
/*  f166288:	10000007 */ 	b	.L0f1662a8
/*  f16628c:	01014025 */ 	or	$t0,$t0,$at
.L0f166290:
/*  f166290:	10000005 */ 	b	.L0f1662a8
/*  f166294:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f166298:	44085000 */ 	mfc1	$t0,$f10
.L0f16629c:
/*  f16629c:	00000000 */ 	nop
/*  f1662a0:	0500fffb */ 	bltz	$t0,.L0f166290
/*  f1662a4:	00000000 */ 	nop
.L0f1662a8:
/*  f1662a8:	3c01800a */ 	lui	$at,%hi(var800a6640)
/*  f1662ac:	a0286640 */ 	sb	$t0,%lo(var800a6640)($at)
/*  f1662b0:	90490011 */ 	lbu	$t1,0x11($v0)
/*  f1662b4:	44d9f800 */ 	ctc1	$t9,$31
/*  f1662b8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1662bc:	44893000 */ 	mtc1	$t1,$f6
/*  f1662c0:	05210004 */ 	bgez	$t1,.L0f1662d4
/*  f1662c4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1662c8:	44812000 */ 	mtc1	$at,$f4
/*  f1662cc:	00000000 */ 	nop
/*  f1662d0:	46044200 */ 	add.s	$f8,$f8,$f4
.L0f1662d4:
/*  f1662d4:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*  f1662d8:	906a0011 */ 	lbu	$t2,0x11($v1)
/*  f1662dc:	c7a80018 */ 	lwc1	$f8,0x18($sp)
/*  f1662e0:	3c014f80 */ 	lui	$at,0x4f80
/*  f1662e4:	448a5000 */ 	mtc1	$t2,$f10
/*  f1662e8:	310900f8 */ 	andi	$t1,$t0,0xf8
/*  f1662ec:	05410004 */ 	bgez	$t2,.L0f166300
/*  f1662f0:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f1662f4:	44812000 */ 	mtc1	$at,$f4
/*  f1662f8:	00000000 */ 	nop
/*  f1662fc:	46043180 */ 	add.s	$f6,$f6,$f4
.L0f166300:
/*  f166300:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f166304:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f166308:	3c014f00 */ 	lui	$at,0x4f00
/*  f16630c:	460a6102 */ 	mul.s	$f4,$f12,$f10
/*  f166310:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f166314:	444bf800 */ 	cfc1	$t3,$31
/*  f166318:	44ccf800 */ 	ctc1	$t4,$31
/*  f16631c:	00000000 */ 	nop
/*  f166320:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f166324:	444cf800 */ 	cfc1	$t4,$31
/*  f166328:	00000000 */ 	nop
/*  f16632c:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f166330:	51800013 */ 	beqzl	$t4,.L0f166380
/*  f166334:	440c5000 */ 	mfc1	$t4,$f10
/*  f166338:	44815000 */ 	mtc1	$at,$f10
/*  f16633c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f166340:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f166344:	44ccf800 */ 	ctc1	$t4,$31
/*  f166348:	00000000 */ 	nop
/*  f16634c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f166350:	444cf800 */ 	cfc1	$t4,$31
/*  f166354:	00000000 */ 	nop
/*  f166358:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f16635c:	15800005 */ 	bnez	$t4,.L0f166374
/*  f166360:	00000000 */ 	nop
/*  f166364:	440c5000 */ 	mfc1	$t4,$f10
/*  f166368:	3c018000 */ 	lui	$at,0x8000
/*  f16636c:	10000007 */ 	b	.L0f16638c
/*  f166370:	01816025 */ 	or	$t4,$t4,$at
.L0f166374:
/*  f166374:	10000005 */ 	b	.L0f16638c
/*  f166378:	240cffff */ 	addiu	$t4,$zero,-1
/*  f16637c:	440c5000 */ 	mfc1	$t4,$f10
.L0f166380:
/*  f166380:	00000000 */ 	nop
/*  f166384:	0580fffb */ 	bltz	$t4,.L0f166374
/*  f166388:	00000000 */ 	nop
.L0f16638c:
/*  f16638c:	3c01800a */ 	lui	$at,%hi(var800a6640+0x1)
/*  f166390:	a02c6641 */ 	sb	$t4,%lo(var800a6640+0x1)($at)
/*  f166394:	904d0012 */ 	lbu	$t5,0x12($v0)
/*  f166398:	44cbf800 */ 	ctc1	$t3,$31
/*  f16639c:	3c014f80 */ 	lui	$at,0x4f80
/*  f1663a0:	448d4000 */ 	mtc1	$t5,$f8
/*  f1663a4:	318b00f8 */ 	andi	$t3,$t4,0xf8
/*  f1663a8:	05a10004 */ 	bgez	$t5,.L0f1663bc
/*  f1663ac:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f1663b0:	44813000 */ 	mtc1	$at,$f6
/*  f1663b4:	00000000 */ 	nop
/*  f1663b8:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f1663bc:
/*  f1663bc:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f1663c0:	906f0012 */ 	lbu	$t7,0x12($v1)
/*  f1663c4:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*  f1663c8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1663cc:	448f5000 */ 	mtc1	$t7,$f10
/*  f1663d0:	05e10004 */ 	bgez	$t7,.L0f1663e4
/*  f1663d4:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f1663d8:	44813000 */ 	mtc1	$at,$f6
/*  f1663dc:	00000000 */ 	nop
/*  f1663e0:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f1663e4:
/*  f1663e4:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f1663e8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1663ec:	3c014f00 */ 	lui	$at,0x4f00
/*  f1663f0:	460a6182 */ 	mul.s	$f6,$f12,$f10
/*  f1663f4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f1663f8:	444ef800 */ 	cfc1	$t6,$31
/*  f1663fc:	44d8f800 */ 	ctc1	$t8,$31
/*  f166400:	00000000 */ 	nop
/*  f166404:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f166408:	4458f800 */ 	cfc1	$t8,$31
/*  f16640c:	00000000 */ 	nop
/*  f166410:	33180078 */ 	andi	$t8,$t8,0x78
/*  f166414:	53000013 */ 	beqzl	$t8,.L0f166464
/*  f166418:	44185000 */ 	mfc1	$t8,$f10
/*  f16641c:	44815000 */ 	mtc1	$at,$f10
/*  f166420:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f166424:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f166428:	44d8f800 */ 	ctc1	$t8,$31
/*  f16642c:	00000000 */ 	nop
/*  f166430:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f166434:	4458f800 */ 	cfc1	$t8,$31
/*  f166438:	00000000 */ 	nop
/*  f16643c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f166440:	17000005 */ 	bnez	$t8,.L0f166458
/*  f166444:	00000000 */ 	nop
/*  f166448:	44185000 */ 	mfc1	$t8,$f10
/*  f16644c:	3c018000 */ 	lui	$at,0x8000
/*  f166450:	10000007 */ 	b	.L0f166470
/*  f166454:	0301c025 */ 	or	$t8,$t8,$at
.L0f166458:
/*  f166458:	10000005 */ 	b	.L0f166470
/*  f16645c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f166460:	44185000 */ 	mfc1	$t8,$f10
.L0f166464:
/*  f166464:	00000000 */ 	nop
/*  f166468:	0700fffb */ 	bltz	$t8,.L0f166458
/*  f16646c:	00000000 */ 	nop
.L0f166470:
/*  f166470:	3c01800a */ 	lui	$at,%hi(var800a6630)
/*  f166474:	a0386642 */ 	sb	$t8,%lo(var800a6630+0x12)($at)
/*  f166478:	44cef800 */ 	ctc1	$t6,$31
/*  f16647c:	330f00f8 */ 	andi	$t7,$t8,0xf8
/*  f166480:	a0296640 */ 	sb	$t1,%lo(var800a6630+0x10)($at)
/*  f166484:	a02b6641 */ 	sb	$t3,%lo(var800a6630+0x11)($at)
/*  f166488:	0fc59663 */ 	jal	func0f16598c
/*  f16648c:	a02f6642 */ 	sb	$t7,%lo(var800a6630+0x12)($at)
/*  f166490:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f166494:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f166498:	03e00008 */ 	jr	$ra
/*  f16649c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f1664a0
/*  f1664a0:	3c0e800a */ 	lui	$t6,%hi(g_FogDisabled)
/*  f1664a4:	8dce65e0 */ 	lw	$t6,%lo(g_FogDisabled)($t6)
/*  f1664a8:	15c00003 */ 	bnez	$t6,.L0f1664b8
/*  f1664ac:	00000000 */ 	nop
/*  f1664b0:	03e00008 */ 	jr	$ra
/*  f1664b4:	00801025 */ 	or	$v0,$a0,$zero
.L0f1664b8:
/*  f1664b8:	10a0003d */ 	beqz	$a1,.L0f1665b0
/*  f1664bc:	3c078008 */ 	lui	$a3,%hi(var80081058)
/*  f1664c0:	3c078008 */ 	lui	$a3,%hi(var80081058)
/*  f1664c4:	00801025 */ 	or	$v0,$a0,$zero
/*  f1664c8:	3c0ff800 */ 	lui	$t7,0xf800
/*  f1664cc:	24e71058 */ 	addiu	$a3,$a3,%lo(var80081058)
/*  f1664d0:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f1664d4:	90ed000a */ 	lbu	$t5,0xa($a3)
/*  f1664d8:	90ea0009 */ 	lbu	$t2,0x9($a3)
/*  f1664dc:	90f90008 */ 	lbu	$t9,0x8($a3)
/*  f1664e0:	01a07025 */ 	or	$t6,$t5,$zero
/*  f1664e4:	000a5c00 */ 	sll	$t3,$t2,0x10
/*  f1664e8:	00194600 */ 	sll	$t0,$t9,0x18
/*  f1664ec:	010b6025 */ 	or	$t4,$t0,$t3
/*  f1664f0:	000e7a00 */ 	sll	$t7,$t6,0x8
/*  f1664f4:	018fc025 */ 	or	$t8,$t4,$t7
/*  f1664f8:	371900ff */ 	ori	$t9,$t8,0xff
/*  f1664fc:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f166500:	3c09bc00 */ 	lui	$t1,0xbc00
/*  f166504:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f166508:	35290008 */ 	ori	$t1,$t1,0x8
/*  f16650c:	00801825 */ 	or	$v1,$a0,$zero
/*  f166510:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f166514:	8cea0004 */ 	lw	$t2,0x4($a3)
/*  f166518:	8ce50000 */ 	lw	$a1,0x0($a3)
/*  f16651c:	3c080001 */ 	lui	$t0,0x1
/*  f166520:	3508f400 */ 	ori	$t0,$t0,0xf400
/*  f166524:	01453023 */ 	subu	$a2,$t2,$a1
/*  f166528:	0106001a */ 	div	$zero,$t0,$a2
/*  f16652c:	00056023 */ 	negu	$t4,$a1
/*  f166530:	000c7a00 */ 	sll	$t7,$t4,0x8
/*  f166534:	01e8c021 */ 	addu	$t8,$t7,$t0
/*  f166538:	00005812 */ 	mflo	$t3
/*  f16653c:	316dffff */ 	andi	$t5,$t3,0xffff
/*  f166540:	000d7400 */ 	sll	$t6,$t5,0x10
/*  f166544:	0306001a */ 	div	$zero,$t8,$a2
/*  f166548:	0000c812 */ 	mflo	$t9
/*  f16654c:	3329ffff */ 	andi	$t1,$t9,0xffff
/*  f166550:	01c95025 */ 	or	$t2,$t6,$t1
/*  f166554:	ac6a0004 */ 	sw	$t2,0x4($v1)
/*  f166558:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f16655c:	14c00002 */ 	bnez	$a2,.L0f166568
/*  f166560:	00000000 */ 	nop
/*  f166564:	0007000d */ 	break	0x7
.L0f166568:
/*  f166568:	2401ffff */ 	addiu	$at,$zero,-1
/*  f16656c:	14c10004 */ 	bne	$a2,$at,.L0f166580
/*  f166570:	3c018000 */ 	lui	$at,0x8000
/*  f166574:	15010002 */ 	bne	$t0,$at,.L0f166580
/*  f166578:	00000000 */ 	nop
/*  f16657c:	0006000d */ 	break	0x6
.L0f166580:
/*  f166580:	01000821 */ 	addu	$at,$t0,$zero
/*  f166584:	14c00002 */ 	bnez	$a2,.L0f166590
/*  f166588:	00000000 */ 	nop
/*  f16658c:	0007000d */ 	break	0x7
.L0f166590:
/*  f166590:	2401ffff */ 	addiu	$at,$zero,-1
/*  f166594:	14c10004 */ 	bne	$a2,$at,.L0f1665a8
/*  f166598:	3c018000 */ 	lui	$at,0x8000
/*  f16659c:	17010002 */ 	bne	$t8,$at,.L0f1665a8
/*  f1665a0:	00000000 */ 	nop
/*  f1665a4:	0006000d */ 	break	0x6
.L0f1665a8:
/*  f1665a8:	1000003b */ 	b	.L0f166698
/*  f1665ac:	24850008 */ 	addiu	$a1,$a0,0x8
.L0f1665b0:
/*  f1665b0:	00801025 */ 	or	$v0,$a0,$zero
/*  f1665b4:	3c08f800 */ 	lui	$t0,0xf800
/*  f1665b8:	24e71058 */ 	addiu	$a3,$a3,%lo(var80081058)
/*  f1665bc:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f1665c0:	90e9000a */ 	lbu	$t1,0xa($a3)
/*  f1665c4:	90f80009 */ 	lbu	$t8,0x9($a3)
/*  f1665c8:	90ed0008 */ 	lbu	$t5,0x8($a3)
/*  f1665cc:	01205025 */ 	or	$t2,$t1,$zero
/*  f1665d0:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f1665d4:	000d6600 */ 	sll	$t4,$t5,0x18
/*  f1665d8:	01997025 */ 	or	$t6,$t4,$t9
/*  f1665dc:	000a4200 */ 	sll	$t0,$t2,0x8
/*  f1665e0:	01c85825 */ 	or	$t3,$t6,$t0
/*  f1665e4:	356d00ff */ 	ori	$t5,$t3,0xff
/*  f1665e8:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f1665ec:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f1665f0:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f1665f4:	35ef0008 */ 	ori	$t7,$t7,0x8
/*  f1665f8:	00801825 */ 	or	$v1,$a0,$zero
/*  f1665fc:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f166600:	8cf80004 */ 	lw	$t8,0x4($a3)
/*  f166604:	8ce50000 */ 	lw	$a1,0x0($a3)
/*  f166608:	3c0c0001 */ 	lui	$t4,0x1
/*  f16660c:	358cf400 */ 	ori	$t4,$t4,0xf400
/*  f166610:	03053023 */ 	subu	$a2,$t8,$a1
/*  f166614:	0186001a */ 	div	$zero,$t4,$a2
/*  f166618:	00057023 */ 	negu	$t6,$a1
/*  f16661c:	000e4200 */ 	sll	$t0,$t6,0x8
/*  f166620:	010c5821 */ 	addu	$t3,$t0,$t4
/*  f166624:	0000c812 */ 	mflo	$t9
/*  f166628:	3329ffff */ 	andi	$t1,$t9,0xffff
/*  f16662c:	00095400 */ 	sll	$t2,$t1,0x10
/*  f166630:	0166001a */ 	div	$zero,$t3,$a2
/*  f166634:	00006812 */ 	mflo	$t5
/*  f166638:	31afffff */ 	andi	$t7,$t5,0xffff
/*  f16663c:	014fc025 */ 	or	$t8,$t2,$t7
/*  f166640:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f166644:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f166648:	14c00002 */ 	bnez	$a2,.L0f166654
/*  f16664c:	00000000 */ 	nop
/*  f166650:	0007000d */ 	break	0x7
.L0f166654:
/*  f166654:	2401ffff */ 	addiu	$at,$zero,-1
/*  f166658:	14c10004 */ 	bne	$a2,$at,.L0f16666c
/*  f16665c:	3c018000 */ 	lui	$at,0x8000
/*  f166660:	15810002 */ 	bne	$t4,$at,.L0f16666c
/*  f166664:	00000000 */ 	nop
/*  f166668:	0006000d */ 	break	0x6
.L0f16666c:
/*  f16666c:	01800821 */ 	addu	$at,$t4,$zero
/*  f166670:	14c00002 */ 	bnez	$a2,.L0f16667c
/*  f166674:	00000000 */ 	nop
/*  f166678:	0007000d */ 	break	0x7
.L0f16667c:
/*  f16667c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f166680:	14c10004 */ 	bne	$a2,$at,.L0f166694
/*  f166684:	3c018000 */ 	lui	$at,0x8000
/*  f166688:	15610002 */ 	bne	$t3,$at,.L0f166694
/*  f16668c:	00000000 */ 	nop
/*  f166690:	0006000d */ 	break	0x6
.L0f166694:
/*  f166694:	24850008 */ 	addiu	$a1,$a0,0x8
.L0f166698:
/*  f166698:	3c0cb700 */ 	lui	$t4,0xb700
/*  f16669c:	3c190001 */ 	lui	$t9,0x1
/*  f1666a0:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f1666a4:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f1666a8:	3c09ba00 */ 	lui	$t1,0xba00
/*  f1666ac:	35290402 */ 	ori	$t1,$t1,0x402
/*  f1666b0:	240e0020 */ 	addiu	$t6,$zero,0x20
/*  f1666b4:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f1666b8:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f1666bc:	24a20008 */ 	addiu	$v0,$a1,0x8
/*  f1666c0:	03e00008 */ 	jr	$ra
/*  f1666c4:	00000000 */ 	nop
);

Gfx *gfxConsiderDisableFog(Gfx *gdl)
{
	if (!g_FogDisabled) {
		return gdl;
	}

	gSPClearGeometryMode(gdl++, G_FOG);

	return gdl;
}

GLOBAL_ASM(
glabel func0f1666f8
/*  f1666f8:	3c0e800a */ 	lui	$t6,%hi(g_FogDisabled)
/*  f1666fc:	8dce65e0 */ 	lw	$t6,%lo(g_FogDisabled)($t6)
/*  f166700:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f166704:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f166708:	15c00003 */ 	bnez	$t6,.L0f166718
/*  f16670c:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f166710:	10000031 */ 	b	.L0f1667d8
/*  f166714:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f166718:
/*  f166718:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f16671c:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f166720:	24010001 */ 	addiu	$at,$zero,0x1
/*  f166724:	944f0010 */ 	lhu	$t7,0x10($v0)
/*  f166728:	24431bb0 */ 	addiu	$v1,$v0,0x1bb0
/*  f16672c:	55e10004 */ 	bnel	$t7,$at,.L0f166740
/*  f166730:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f166734:	10000028 */ 	b	.L0f1667d8
/*  f166738:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f16673c:	afa3001c */ 	sw	$v1,0x1c($sp)
.L0f166740:
/*  f166740:	0fc2d5be */ 	jal	currentPlayerGetMatrix1740
/*  f166744:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f166748:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f16674c:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f166750:	3c018008 */ 	lui	$at,%hi(var80081050)
/*  f166754:	c4660000 */ 	lwc1	$f6,0x0($v1)
/*  f166758:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f16675c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f166760:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f166764:	c4700004 */ 	lwc1	$f16,0x4($v1)
/*  f166768:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f16676c:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f166770:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*  f166774:	e7b20028 */ 	swc1	$f18,0x28($sp)
/*  f166778:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f16677c:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f166780:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f166784:	c7a40028 */ 	lwc1	$f4,0x28($sp)
/*  f166788:	e7a8002c */ 	swc1	$f8,0x2c($sp)
/*  f16678c:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f166790:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f166794:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f166798:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f16679c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1667a0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f1667a4:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*  f1667a8:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f1667ac:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f1667b0:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f1667b4:	c4321050 */ 	lwc1	$f18,%lo(var80081050)($at)
/*  f1667b8:	460a3000 */ 	add.s	$f0,$f6,$f10
/*  f1667bc:	46089400 */ 	add.s	$f16,$f18,$f8
/*  f1667c0:	4600803c */ 	c.lt.s	$f16,$f0
/*  f1667c4:	00000000 */ 	nop
/*  f1667c8:	45000003 */ 	bc1f	.L0f1667d8
/*  f1667cc:	00000000 */ 	nop
/*  f1667d0:	10000001 */ 	b	.L0f1667d8
/*  f1667d4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1667d8:
/*  f1667d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1667dc:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1667e0:	03e00008 */ 	jr	$ra
/*  f1667e4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f1667e8
/*  f1667e8:	3c02800a */ 	lui	$v0,%hi(var800a65e8)
/*  f1667ec:	03e00008 */ 	jr	$ra
/*  f1667f0:	8c4265e8 */ 	lw	$v0,%lo(var800a65e8)($v0)
);

GLOBAL_ASM(
glabel func0f1667f4
/*  f1667f4:	3c0e800a */ 	lui	$t6,%hi(g_FogDisabled)
/*  f1667f8:	8dce65e0 */ 	lw	$t6,%lo(g_FogDisabled)($t6)
/*  f1667fc:	55c00004 */ 	bnezl	$t6,.L0f166810
/*  f166800:	44801000 */ 	mtc1	$zero,$f2
/*  f166804:	03e00008 */ 	jr	$ra
/*  f166808:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f16680c:	44801000 */ 	mtc1	$zero,$f2
.L0f166810:
/*  f166810:	c4840014 */ 	lwc1	$f4,0x14($a0)
/*  f166814:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f166818:	4602203c */ 	c.lt.s	$f4,$f2
/*  f16681c:	00000000 */ 	nop
/*  f166820:	45000003 */ 	bc1f	.L0f166830
/*  f166824:	00000000 */ 	nop
/*  f166828:	03e00008 */ 	jr	$ra
/*  f16682c:	24020002 */ 	addiu	$v0,$zero,0x2
.L0f166830:
/*  f166830:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f166834:	24010001 */ 	addiu	$at,$zero,0x1
/*  f166838:	3c028008 */ 	lui	$v0,%hi(var80081058)
/*  f16683c:	95f80010 */ 	lhu	$t8,0x10($t7)
/*  f166840:	24421058 */ 	addiu	$v0,$v0,%lo(var80081058)
/*  f166844:	57010004 */ 	bnel	$t8,$at,.L0f166858
/*  f166848:	c4460044 */ 	lwc1	$f6,0x44($v0)
/*  f16684c:	03e00008 */ 	jr	$ra
/*  f166850:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f166854:	c4460044 */ 	lwc1	$f6,0x44($v0)
.L0f166858:
/*  f166858:	3c03800a */ 	lui	$v1,%hi(var800a6600)
/*  f16685c:	24636600 */ 	addiu	$v1,$v1,%lo(var800a6600)
/*  f166860:	e4a60000 */ 	swc1	$f6,0x0($a1)
/*  f166864:	c4480048 */ 	lwc1	$f8,0x48($v0)
/*  f166868:	3c013f80 */ 	lui	$at,0x3f80
/*  f16686c:	e4a80004 */ 	swc1	$f8,0x4($a1)
/*  f166870:	c44a004c */ 	lwc1	$f10,0x4c($v0)
/*  f166874:	e4aa0008 */ 	swc1	$f10,0x8($a1)
/*  f166878:	c4920014 */ 	lwc1	$f18,0x14($a0)
/*  f16687c:	c4700010 */ 	lwc1	$f16,0x10($v1)
/*  f166880:	c4660014 */ 	lwc1	$f6,0x14($v1)
/*  f166884:	46128103 */ 	div.s	$f4,$f16,$f18
/*  f166888:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f16688c:	e4a8000c */ 	swc1	$f8,0xc($a1)
/*  f166890:	c4a0000c */ 	lwc1	$f0,0xc($a1)
/*  f166894:	4602003c */ 	c.lt.s	$f0,$f2
/*  f166898:	00000000 */ 	nop
/*  f16689c:	45020004 */ 	bc1fl	.L0f1668b0
/*  f1668a0:	44815000 */ 	mtc1	$at,$f10
/*  f1668a4:	03e00008 */ 	jr	$ra
/*  f1668a8:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f1668ac:	44815000 */ 	mtc1	$at,$f10
.L0f1668b0:
/*  f1668b0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1668b4:	4600503c */ 	c.lt.s	$f10,$f0
/*  f1668b8:	00000000 */ 	nop
/*  f1668bc:	45000003 */ 	bc1f	.L0f1668cc
/*  f1668c0:	00000000 */ 	nop
/*  f1668c4:	03e00008 */ 	jr	$ra
/*  f1668c8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1668cc:
/*  f1668cc:	03e00008 */ 	jr	$ra
/*  f1668d0:	00000000 */ 	nop
);
