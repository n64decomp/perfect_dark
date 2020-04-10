#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/cheats.h"
#include "game/game_107fb0.h"
#include "game/game_10ccd0.h"
#include "game/camdraw.h"
#include "game/timing.h"
#include "game/game_173a00.h"
#include "game/utils.h"
#include "game/game_177e00.h"
#include "game/game_179060.h"
#include "game/game_17f930.h"
#include "game/game_1a3340.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "stagesetup.h"
#include "types.h"

// 2da90
struct mptrack g_MpTracks[NUM_MPTRACKS] = {
	// Audio ID, duration, name, unlock after stage
	/*0x00*/ { 0x3a, 160, L_MISC(124), -1 }, // "Dark Combat"
	/*0x01*/ { 0x3b, 170, L_MISC(125), -1 }, // "Skedar Mystery"
	/*0x02*/ { 0x3d, 170, L_MISC(126), -1 }, // "CI Operative"
	/*0x03*/ { 0x3e, 180, L_MISC(127), -1 }, // "dataDyne Action"
	/*0x04*/ { 0x3f, 200, L_MISC(128), -1 }, // "Maian Tears"
	/*0x05*/ { 0x40, 197, L_MISC(129), -1 }, // "Alien Conflict"
	/*0x06*/ { 0x0d, 120, L_MISC(130), -1 }, // "Carrington Institute"
	/*0x07*/ { 0x09, 120, L_MISC(131), SOLOSTAGEINDEX_DEFECTION }, // "dD Central"
	/*0x08*/ { 0x10, 120, L_MISC(132), SOLOSTAGEINDEX_DEFECTION }, // "dD Central X"
	/*0x09*/ { 0x12, 120, L_MISC(133), SOLOSTAGEINDEX_INVESTIGATION }, // "dD Research"
	/*0x0a*/ { 0x13, 120, L_MISC(134), SOLOSTAGEINDEX_INVESTIGATION }, // "dD Research X"
	/*0x0b*/ { 0x02, 120, L_MISC(135), SOLOSTAGEINDEX_EXTRACTION }, // "dD Extraction"
	/*0x0c*/ { 0x11, 120, L_MISC(136), SOLOSTAGEINDEX_EXTRACTION }, // "dD Extraction X"
	/*0x0d*/ { 0x0c, 120, L_MISC(137), SOLOSTAGEINDEX_VILLA }, // "Carrington Villa"
	/*0x0e*/ { 0x27, 120, L_MISC(138), SOLOSTAGEINDEX_VILLA }, // "Carrington Villa X"
	/*0x0f*/ { 0x0e, 120, L_MISC(139), SOLOSTAGEINDEX_CHICAGO }, // "Chicago"
	/*0x10*/ { 0x28, 120, L_MISC(140), SOLOSTAGEINDEX_CHICAGO }, // "Chicago X"
	/*0x11*/ { 0x0f, 120, L_MISC(141), SOLOSTAGEINDEX_G5BUILDING }, // "G5 Building"
	/*0x12*/ { 0x29, 120, L_MISC(142), SOLOSTAGEINDEX_G5BUILDING }, // "G5 Building X"
	/*0x13*/ { 0x14, 120, L_MISC(143), SOLOSTAGEINDEX_INFILTRATION }, // "A51 Infiltration"
	/*0x14*/ { 0x2a, 120, L_MISC(144), SOLOSTAGEINDEX_INFILTRATION }, // "A51 Infiltration X"
	/*0x15*/ { 0x16, 120, L_MISC(145), SOLOSTAGEINDEX_RESCUE }, // "A51 Rescue"
	/*0x16*/ { 0x32, 120, L_MISC(146), SOLOSTAGEINDEX_RESCUE }, // "A51 Rescue X"
	/*0x17*/ { 0x06, 120, L_MISC(147), SOLOSTAGEINDEX_ESCAPE }, // "A51 Escape"
	/*0x18*/ { 0x33, 120, L_MISC(148), SOLOSTAGEINDEX_ESCAPE }, // "A51 Escape X"
	/*0x19*/ { 0x17, 120, L_MISC(149), SOLOSTAGEINDEX_AIRBASE }, // "Air Base"
	/*0x1a*/ { 0x34, 120, L_MISC(150), SOLOSTAGEINDEX_AIRBASE }, // "Air Base X"
	/*0x1b*/ { 0x18, 120, L_MISC(151), SOLOSTAGEINDEX_AIRFORCEONE }, // "Air Force One"
	/*0x1c*/ { 0x35, 120, L_MISC(152), SOLOSTAGEINDEX_AIRFORCEONE }, // "Air Force One X"
	/*0x1d*/ { 0x1d, 120, L_MISC(153), SOLOSTAGEINDEX_CRASHSITE }, // "Crash Site"
	/*0x1e*/ { 0x1e, 120, L_MISC(154), SOLOSTAGEINDEX_CRASHSITE }, // "Crash Site X"
	/*0x1f*/ { 0x1c, 120, L_MISC(155), SOLOSTAGEINDEX_PELAGIC }, // "Pelagic II"
	/*0x20*/ { 0x36, 120, L_MISC(156), SOLOSTAGEINDEX_PELAGIC }, // "Pelagic II X"
	/*0x21*/ { 0x07, 120, L_MISC(157), SOLOSTAGEINDEX_DEEPSEA }, // "Deep Sea"
	/*0x22*/ { 0x37, 120, L_MISC(158), SOLOSTAGEINDEX_DEEPSEA }, // "Deep Sea X"
	/*0x23*/ { 0x04, 120, L_MISC(159), SOLOSTAGEINDEX_DEFENSE }, // "Institute Defense"
	/*0x24*/ { 0x24, 120, L_MISC(160), SOLOSTAGEINDEX_DEFENSE }, // "Institute Defense X"
	/*0x25*/ { 0x1f, 120, L_MISC(161), SOLOSTAGEINDEX_ATTACKSHIP }, // "Attack Ship"
	/*0x26*/ { 0x20, 120, L_MISC(162), SOLOSTAGEINDEX_ATTACKSHIP }, // "Attack Ship X"
	/*0x27*/ { 0x21, 120, L_MISC(163), SOLOSTAGEINDEX_SKEDARRUINS }, // "Skedar Ruins"
	/*0x28*/ { 0x38, 120, L_MISC(164), SOLOSTAGEINDEX_SKEDARRUINS }, // "Skedar Ruins X"
	/*0x29*/ { 0x58, 120, L_MISC(165), SOLOSTAGEINDEX_SKEDARRUINS }, // "End Credits"
};

// 2db8c
struct mppreset g_MpPresets[NUM_MPPRESETS] = {
	{ L_MPWEAPONS(25), 0x07, {0} }, // "No Shield"
	{ L_MPWEAPONS(26), 0x0c, {0} }, // "Automatics"
	{ L_MPWEAPONS(27), 0x0d, {0} }, // "Rocket Launcher"
	{ L_MPWEAPONS(28), 0x0b, {0} }, // "Simulants"
	{ L_MPWEAPONS(29), 0x09, {0} }, // "King of the Hill"
	{ L_MPWEAPONS(30), 0x02, {0} }, // "Complex FarSight"
	{ L_MPWEAPONS(31), 0x08, {0} }, // "Hold the Briefcase"
	{ L_MPWEAPONS(32), 0x01, {0} }, // "Pistol One-Hit Kills"
	{ L_MPWEAPONS(33), 0x0a, {0} }, // "Capture the Case"
	{ L_MPWEAPONS(34), 0x05, {0} }, // "Cloaking"
	{ L_MPWEAPONS(35), 0x00, {0} }, // "Temple Explosives"
	{ L_MPWEAPONS(36), 0x04, {0} }, // "Slayer"
	{ L_MPWEAPONS(37), 0x03, {0} }, // "Tranquilizr"
	{ L_MPWEAPONS(38), 0x06, {0} }, // "Slow Motion"
};

u32 var80087cbc = 0x00000000;
u32 var80087cc0 = 0x00000001;

// 2dce4
u32 g_TeamColours[] = {
	0xff000000, // Red
	0xffff0000, // Yellow
	0x0000ff00, // Blue
	0xff00ff00, // Magenta
	0x00ffff00, // Cyan
	0xff885500, // Orange
	0x8800ff00, // Pink
	0x88445500, // Brown
};

u16 var80087ce4[] = {
	0xf801, 0xf801,
	0xffc1, 0xffc1,
	0x003f, 0x003f,
	0xf83f, 0xf83f,
	0x07ff, 0x07ff,
	0xfc55, 0xfc55,
	0xfc63, 0xfc63,
	0x8a15, 0x8a15,
	0x0000, 0x0000,
	0x0000, 0x0000,
	0x0000, 0x0000,
};

u8 g_NumMpSimulantChrs = 0;

struct var80087d14 var80087d14[] = {
	{ 90, 0.26175770163536,  0.52351540327072,  600, 10, 0.69802051782608, 0.34901025891304,  1000 },
	{ 60, 0.12215359508991,  0.24430719017982,  360, 10, 0.49733963608742, 0.13960410654545,  1000 },
	{ 30, 0.069802053272724, 0.13960410654545,  180, 4,  0.34901025891304, 0.08725256472826,  1500 },
	{ 15, 0.026175770908594, 0.069802053272724, 90,  2,  0.24430719017982, 0.034901026636362, 2500 },
	{ 0,  0,                 0.034901026636362, 45,  1,  0.17450512945652, 0,                 4000 },
	{ 0,  0,                 0,                 0,   0,  0.13960410654545, 0,                 4000 },
	{ 0,  0,                 0,                 0,   0,  0,                0,                 0    },
};

// 2de14
u32 g_MpBotCommands[NUM_MPBOTCOMMANDS] = {
	L_MISC(175), // "Follow"
	L_MISC(176), // "Attack"
	L_MISC(177), // "Defend"
	L_MISC(178), // "Hold"
	L_MISC(179), // "Normal"
	L_MISC(180), // "Download"
	L_MISC(181), // "Get Case"
	L_MISC(182), // "Tag Box"
	L_MISC(209), // "Save Case"
	L_MISC(210), // "Def Hill"
	L_MISC(211), // "Hold Hill"
	L_MISC(212), // "Get Case"
	L_MISC(213), // "Pop Cap"
	L_MISC(214), // "Protect"
};

u32 var80087e2c = 0x00000000;
u32 var80087e30 = 0x00000000;
u32 var80087e34 = 0x00000000;
u32 var80087e38 = 0x00000000;
u32 var80087e3c = 0x00000000;
u32 var80087e40 = 0x00000000;
u32 var80087e44 = 0x00000000;
u32 var80087e48 = 0x00000000;
u32 var80087e4c = 0x00000000;
u32 var80087e50 = 0x00000000;
u32 var80087e54 = 0x42f00000;
u32 var80087e58 = 0x461c4000;
u32 var80087e5c = 0x43960000;
u32 var80087e60 = 0x43e10000;
u32 var80087e64 = 0x458ca000;
u32 var80087e68 = 0x43960000;
u32 var80087e6c = 0x44160000;
u32 var80087e70 = 0x458ca000;
u32 var80087e74 = 0x44160000;
u32 var80087e78 = 0x44960000;
u32 var80087e7c = 0x458ca000;
u32 var80087e80 = 0x43160000;
u32 var80087e84 = 0x437a0000;
u32 var80087e88 = 0x458ca000;
u32 var80087e8c = 0x447a0000;
u32 var80087e90 = 0x44fa0000;
u32 var80087e94 = 0x453b8000;
u32 var80087e98 = 0x00000000;
u32 var80087e9c = 0x437a0000;
u32 var80087ea0 = 0x461c4000;
u32 var80087ea4 = 0x43e10000;
u32 var80087ea8 = 0x442f0000;
u32 var80087eac = 0x458ca000;
u32 var80087eb0 = 0x00000000;
u32 var80087eb4 = 0x08800000;
u32 var80087eb8 = 0x00000000;
u32 var80087ebc = 0x00000000;
u32 var80087ec0 = 0x0d0d0d0d;
u32 var80087ec4 = 0xc0000000;
u32 var80087ec8 = 0x00000000;
u32 var80087ecc = 0x00000000;
u32 var80087ed0 = 0x383c5458;
u32 var80087ed4 = 0xc400001e;
u32 var80087ed8 = 0x0000000a;
u32 var80087edc = 0x00002000;
u32 var80087ee0 = 0x343c5058;
u32 var80087ee4 = 0xc400001e;
u32 var80087ee8 = 0x0000000a;
u32 var80087eec = 0x00002000;
u32 var80087ef0 = 0x3c3c5858;
u32 var80087ef4 = 0xc400001e;
u32 var80087ef8 = 0x0000000a;
u32 var80087efc = 0x00002000;
u32 var80087f00 = 0x4c586878;
u32 var80087f04 = 0xc480001e;
u32 var80087f08 = 0x001e000a;
u32 var80087f0c = 0x000a2000;
u32 var80087f10 = 0x40585c78;
u32 var80087f14 = 0xc480001e;
u32 var80087f18 = 0x001e000a;
u32 var80087f1c = 0x000a2000;
u32 var80087f20 = 0x484c6478;
u32 var80087f24 = 0xc480001e;
u32 var80087f28 = 0x001e000a;
u32 var80087f2c = 0x000a4000;
u32 var80087f30 = 0x444c6078;
u32 var80087f34 = 0xc400001e;
u32 var80087f38 = 0x00000008;
u32 var80087f3c = 0x00006000;
u32 var80087f40 = 0xb4bcb8bc;
u32 var80087f44 = 0xc4000014;
u32 var80087f48 = 0x00000006;
u32 var80087f4c = 0x00006000;
u32 var80087f50 = 0x74808898;
u32 var80087f54 = 0xc8800064;
u32 var80087f58 = 0x0064001e;
u32 var80087f5c = 0x001e4000;
u32 var80087f60 = 0x7880848c;
u32 var80087f64 = 0xc8800096;
u32 var80087f68 = 0x00960032;
u32 var80087f6c = 0x00324000;
u32 var80087f70 = 0x98b00000;
u32 var80087f74 = 0xc8800064;
u32 var80087f78 = 0x00460019;
u32 var80087f7c = 0x000f4000;
u32 var80087f80 = 0xacbc0000;
u32 var80087f84 = 0x8880012c;
u32 var80087f88 = 0x00000028;
u32 var80087f8c = 0x00004000;
u32 var80087f90 = 0x808c0000;
u32 var80087f94 = 0xc8800064;
u32 var80087f98 = 0x0000001e;
u32 var80087f9c = 0x00006000;
u32 var80087fa0 = 0x7c940000;
u32 var80087fa4 = 0xc880005a;
u32 var80087fa8 = 0x0000001e;
u32 var80087fac = 0x00002000;
u32 var80087fb0 = 0x9cb40000;
u32 var80087fb4 = 0x88800096;
u32 var80087fb8 = 0x00000028;
u32 var80087fbc = 0x00004000;
u32 var80087fc0 = 0x94b00000;
u32 var80087fc4 = 0x88800078;
u32 var80087fc8 = 0x00000028;
u32 var80087fcc = 0x00004000;
u32 var80087fd0 = 0xa4bc0000;
u32 var80087fd4 = 0xc8c00078;
u32 var80087fd8 = 0x0014001e;
u32 var80087fdc = 0x00062000;
u32 var80087fe0 = 0x8c9c0000;
u32 var80087fe4 = 0xc4400012;
u32 var80087fe8 = 0x00120008;
u32 var80087fec = 0x0008d000;
u32 var80087ff0 = 0x90b00000;
u32 var80087ff4 = 0xc8000190;
u32 var80087ff8 = 0x00000050;
u32 var80087ffc = 0x00006000;
u32 var80088000 = 0x1c280000;
u32 var80088004 = 0x8880001e;
u32 var80088008 = 0x001e000a;
u32 var8008800c = 0x000a4000;
u32 var80088010 = 0xbcbc0000;
u32 var80088014 = 0x8d400010;
u32 var80088018 = 0x00000004;
u32 var8008801c = 0x00004000;
u32 var80088020 = 0xb0bc0000;
u32 var80088024 = 0xccc00014;
u32 var80088028 = 0x00140004;
u32 var8008802c = 0x00044000;
u32 var80088030 = 0xa0bc0000;
u32 var80088034 = 0xccc00002;
u32 var80088038 = 0x00020001;
u32 var8008803c = 0x00014000;
u32 var80088040 = 0xa8bc0000;
u32 var80088044 = 0xccc00002;
u32 var80088048 = 0x00020001;
u32 var8008804c = 0x00016000;
u32 var80088050 = 0x14281828;
u32 var80088054 = 0xc0800000;
u32 var80088058 = 0x00050000;
u32 var8008805c = 0x00012000;
u32 var80088060 = 0x6cb00000;
u32 var80088064 = 0xc880000f;
u32 var80088068 = 0x000f0005;
u32 var8008806c = 0x00059000;
u32 var80088070 = 0x30bc0000;
u32 var80088074 = 0xc8000014;
u32 var80088078 = 0x00180006;
u32 var8008807c = 0x00082000;
u32 var80088080 = 0x70700000;
u32 var80088084 = 0xc8000000;
u32 var80088088 = 0x00000000;
u32 var8008808c = 0x00002000;
u32 var80088090 = 0x24ac0000;
u32 var80088094 = 0xddc00006;
u32 var80088098 = 0x00060002;
u32 var8008809c = 0x00022000;
u32 var800880a0 = 0x20bc0000;
u32 var800880a4 = 0xddc00003;
u32 var800880a8 = 0x00030001;
u32 var800880ac = 0x00012000;
u32 var800880b0 = 0x0c0c0000;
u32 var800880b4 = 0x1c800005;
u32 var800880b8 = 0x00050001;
u32 var800880bc = 0x00012000;
u32 var800880c0 = 0x28b00000;
u32 var800880c4 = 0x1c800005;
u32 var800880c8 = 0x00050001;
u32 var800880cc = 0x00012000;
u32 var800880d0 = 0x2c9c0000;
u32 var800880d4 = 0x88800005;
u32 var800880d8 = 0x00050002;
u32 var800880dc = 0x00022000;
u32 var800880e0 = 0x08080000;
u32 var800880e4 = 0x08800000;
u32 var800880e8 = 0x00000000;
u32 var800880ec = 0x00002000;
u32 var800880f0 = 0x00000000;
u32 var800880f4 = 0x08800000;
u32 var800880f8 = 0x00000000;
u32 var800880fc = 0x00002000;
u32 var80088100 = 0x00000000;
u32 var80088104 = 0x08800000;
u32 var80088108 = 0x00000000;
u32 var8008810c = 0x00002000;
u32 var80088110 = 0x00000000;
u32 var80088114 = 0x08800000;
u32 var80088118 = 0x00000000;
u32 var8008811c = 0x00002000;
u32 var80088120 = 0x00000000;
u32 var80088124 = 0x08800000;
u32 var80088128 = 0x00000000;
u32 var8008812c = 0x00002000;
u32 var80088130 = 0x00000000;
u32 var80088134 = 0x08800000;
u32 var80088138 = 0x00000000;
u32 var8008813c = 0x00002000;
u32 var80088140 = 0x00000000;
u32 var80088144 = 0x08800000;
u32 var80088148 = 0x00000000;
u32 var8008814c = 0x00002000;
u32 var80088150 = 0x00000000;
u32 var80088154 = 0x08800000;
u32 var80088158 = 0x00000000;
u32 var8008815c = 0x00002000;
u32 var80088160 = 0x00000000;
u32 var80088164 = 0x08800000;
u32 var80088168 = 0x00000000;
u32 var8008816c = 0x00002000;
u32 var80088170 = 0x00000000;
u32 var80088174 = 0x08800000;
u32 var80088178 = 0x00000000;
u32 var8008817c = 0x00002000;
u32 var80088180 = 0x00000000;
u32 var80088184 = 0x08800000;
u32 var80088188 = 0x00000000;
u32 var8008818c = 0x00002000;
u32 var80088190 = 0x00000000;
u32 var80088194 = 0x08800000;
u32 var80088198 = 0x00000000;
u32 var8008819c = 0x00002000;
u32 var800881a0 = 0x04040000;
u32 var800881a4 = 0x08800000;
u32 var800881a8 = 0x00000000;
u32 var800881ac = 0x00002000;
u32 var800881b0 = 0x00000000;
u32 var800881b4 = 0x08800000;
u32 var800881b8 = 0x00000000;
u32 var800881bc = 0x00002000;
u32 var800881c0 = 0xdada0000;
u32 var800881c4 = 0x088004b0;
u32 var800881c8 = 0x00000000;
u32 var800881cc = 0x00002000;
u32 var800881d0 = 0x00000000;
u32 var800881d4 = 0x08800000;
u32 var800881d8 = 0x00000000;
u32 var800881dc = 0x00002000;
u32 var800881e0 = 0x00000000;
u32 var800881e4 = 0x08800000;
u32 var800881e8 = 0x00000000;
u32 var800881ec = 0x00002000;
u32 var800881f0 = 0x00000000;
u32 var800881f4 = 0x08800000;
u32 var800881f8 = 0x00000000;
u32 var800881fc = 0x00002000;
u32 var80088200 = 0x00000000;
u32 var80088204 = 0x08800000;
u32 var80088208 = 0x00000000;
u32 var8008820c = 0x00002000;
u32 var80088210 = 0x00000000;
u32 var80088214 = 0x08800000;
u32 var80088218 = 0x00000000;
u32 var8008821c = 0x00002000;
u32 var80088220 = 0x00000000;
u32 var80088224 = 0x08800000;
u32 var80088228 = 0x00000000;
u32 var8008822c = 0x00002000;
u32 var80088230 = 0x00000000;
u32 var80088234 = 0x08800000;
u32 var80088238 = 0x00000000;
u32 var8008823c = 0x00002000;
u32 var80088240 = 0x00000000;
u32 var80088244 = 0x08800000;
u32 var80088248 = 0x00000000;
u32 var8008824c = 0x00002000;
u32 var80088250 = 0x00000000;
u32 var80088254 = 0x08800000;
u32 var80088258 = 0x00000000;
u32 var8008825c = 0x00002000;
u32 var80088260 = 0x00000000;
u32 var80088264 = 0x08800000;
u32 var80088268 = 0x00000000;
u32 var8008826c = 0x00002000;
u32 var80088270 = 0x00000000;
u32 var80088274 = 0x08800000;
u32 var80088278 = 0x00000000;
u32 var8008827c = 0x00002000;
u32 var80088280 = 0x00000000;
u32 var80088284 = 0x08800000;
u32 var80088288 = 0x00000000;
u32 var8008828c = 0x00002000;
u32 var80088290 = 0x00000000;
u32 var80088294 = 0x08800000;
u32 var80088298 = 0x00000000;
u32 var8008829c = 0x00002000;
u32 var800882a0 = 0x00000000;
u32 var800882a4 = 0x08800000;
u32 var800882a8 = 0x00000000;
u32 var800882ac = 0x00002000;
u32 var800882b0 = 0x00000000;
u32 var800882b4 = 0x08800000;
u32 var800882b8 = 0x00000000;
u32 var800882bc = 0x00002000;
u32 var800882c0 = 0x00000000;
u32 var800882c4 = 0x08800000;
u32 var800882c8 = 0x00000000;
u32 var800882cc = 0x00002000;
u32 var800882d0 = 0x00000000;
u32 var800882d4 = 0x08800000;
u32 var800882d8 = 0x00000000;
u32 var800882dc = 0x00002000;
u32 var800882e0 = 0x00000000;
u32 var800882e4 = 0x08800000;
u32 var800882e8 = 0x00000000;
u32 var800882ec = 0x00002000;
u32 var800882f0 = 0x00000000;
u32 var800882f4 = 0x08800000;
u32 var800882f8 = 0x00000000;
u32 var800882fc = 0x00002000;
u32 var80088300 = 0x00000000;
u32 var80088304 = 0x08800000;
u32 var80088308 = 0x00000000;
u32 var8008830c = 0x00002000;
u32 var80088310 = 0x00000000;
u32 var80088314 = 0x08800000;
u32 var80088318 = 0x00000000;
u32 var8008831c = 0x00002000;
u32 var80088320 = 0x00000000;
u32 var80088324 = 0x08800000;
u32 var80088328 = 0x00000000;
u32 var8008832c = 0x00002000;
u32 var80088330 = 0x00000000;
u32 var80088334 = 0x08800000;
u32 var80088338 = 0x00000000;
u32 var8008833c = 0x00002000;
u32 var80088340 = 0x00000000;
u32 var80088344 = 0x08800000;
u32 var80088348 = 0x00000000;
u32 var8008834c = 0x00002000;
u32 var80088350 = 0x00000000;
u32 var80088354 = 0x08800000;
u32 var80088358 = 0x00000000;
u32 var8008835c = 0x00002000;
u32 var80088360 = 0x00000000;
u32 var80088364 = 0x08800000;
u32 var80088368 = 0x00000000;
u32 var8008836c = 0x00002000;
u32 var80088370 = 0x00000000;
u32 var80088374 = 0x08800000;
u32 var80088378 = 0x00000000;
u32 var8008837c = 0x00002000;
u32 var80088380 = 0x00000000;
u32 var80088384 = 0x08800000;
u32 var80088388 = 0x00000000;
u32 var8008838c = 0x00002000;
u32 var80088390 = 0x00000000;
u32 var80088394 = 0x08800000;
u32 var80088398 = 0x00000000;
u32 var8008839c = 0x00002000;
u32 var800883a0 = 0x00000000;
u32 var800883a4 = 0x08800000;
u32 var800883a8 = 0x00000000;
u32 var800883ac = 0x00002000;
u32 var800883b0 = 0x00000000;
u32 var800883b4 = 0x08800000;
u32 var800883b8 = 0x00000000;
u32 var800883bc = 0x00002000;
u32 var800883c0 = 0x00000000;
u32 var800883c4 = 0x08800000;
u32 var800883c8 = 0x00000000;
u32 var800883cc = 0x00002000;
u32 var800883d0 = 0x00000000;
u32 var800883d4 = 0x08800000;
u32 var800883d8 = 0x00000000;
u32 var800883dc = 0x00002000;
u32 var800883e0 = 0x00000000;
u32 var800883e4 = 0x08800000;
u32 var800883e8 = 0x00000000;
u32 var800883ec = 0x00002000;
u32 var800883f0 = 0x00000000;
u32 var800883f4 = 0x08800000;
u32 var800883f8 = 0x00000000;
u32 var800883fc = 0x00002000;
u32 var80088400 = 0x00000000;
u32 var80088404 = 0x08800000;
u32 var80088408 = 0x00000000;
u32 var8008840c = 0x00002000;
u32 var80088410 = 0x00000000;
u32 var80088414 = 0x08800000;
u32 var80088418 = 0x00000000;
u32 var8008841c = 0x00002000;
u32 var80088420 = 0x00000000;
u32 var80088424 = 0x08800000;
u32 var80088428 = 0x00000000;
u32 var8008842c = 0x00002000;
u32 var80088430 = 0x00000000;
u32 var80088434 = 0x08800000;
u32 var80088438 = 0x00000000;
u32 var8008843c = 0x00002000;
u32 var80088440 = 0x00000000;
u32 var80088444 = 0x08800000;
u32 var80088448 = 0x00000000;
u32 var8008844c = 0x00002000;
u32 var80088450 = 0x00000000;
u32 var80088454 = 0x08800000;
u32 var80088458 = 0x00000000;
u32 var8008845c = 0x00002000;
u32 var80088460 = 0xdcdc0000;
u32 var80088464 = 0x08800000;
u32 var80088468 = 0x00000000;
u32 var8008846c = 0x00002000;
u32 var80088470 = 0x00000000;
u32 var80088474 = 0x08800000;
u32 var80088478 = 0x00000000;
u32 var8008847c = 0x00002000;
u32 var80088480 = 0x00000000;
u32 var80088484 = 0x08800000;
u32 var80088488 = 0x00000000;
u32 var8008848c = 0x00002000;
u32 var80088490 = 0x16000000;
u32 var80088494 = 0x00000000;
u32 var80088498 = 0x00000000;
u32 var8008849c = 0x00000000;
u32 var800884a0 = 0x00000000;
u32 var800884a4 = 0x00000000;
u32 var800884a8 = 0x00000000;
u32 var800884ac = 0x00000000;
u32 g_MpChallengeIndex = 0;
u32 var800884b4 = 0;

// 2e4d8
struct challenge g_MpChallenges[NUM_CHALLENGES] = {
	{ L_OPTIONS(406), 0x0e }, // "Challenge 1"
	{ L_OPTIONS(407), 0x0f }, // "Challenge 2"
	{ L_OPTIONS(408), 0x10 }, // "Challenge 3"
	{ L_OPTIONS(409), 0x11 }, // "Challenge 4"
	{ L_OPTIONS(410), 0x12 }, // "Challenge 5"
	{ L_OPTIONS(411), 0x13 }, // "Challenge 6"
	{ L_OPTIONS(412), 0x14 }, // "Challenge 7"
	{ L_OPTIONS(413), 0x15 }, // "Challenge 8"
	{ L_OPTIONS(414), 0x16 }, // "Challenge 9"
	{ L_OPTIONS(415), 0x17 }, // "Challenge 10"
	{ L_OPTIONS(416), 0x18 }, // "Challenge 11"
	{ L_OPTIONS(417), 0x19 }, // "Challenge 12"
	{ L_OPTIONS(418), 0x1a }, // "Challenge 13"
	{ L_OPTIONS(419), 0x1b }, // "Challenge 14"
	{ L_OPTIONS(420), 0x1c }, // "Challenge 15"
	{ L_OPTIONS(421), 0x1d }, // "Challenge 16"
	{ L_OPTIONS(422), 0x1e }, // "Challenge 17"
	{ L_OPTIONS(423), 0x1f }, // "Challenge 18"
	{ L_OPTIONS(424), 0x20 }, // "Challenge 19"
	{ L_OPTIONS(425), 0x21 }, // "Challenge 20"
	{ L_OPTIONS(426), 0x22 }, // "Challenge 21"
	{ L_OPTIONS(427), 0x23 }, // "Challenge 22"
	{ L_OPTIONS(428), 0x24 }, // "Challenge 23"
	{ L_OPTIONS(429), 0x25 }, // "Challenge 24"
	{ L_OPTIONS(430), 0x26 }, // "Challenge 25"
	{ L_OPTIONS(431), 0x27 }, // "Challenge 26"
	{ L_OPTIONS(432), 0x28 }, // "Challenge 27"
	{ L_OPTIONS(433), 0x29 }, // "Challenge 28"
	{ L_OPTIONS(434), 0x2a }, // "Challenge 29"
	{ L_OPTIONS(435), 0x2b }, // "Challenge 30"
};

u32 var800887c4 = 0x007d1c20;
u32 var800887c8 = 0x007d5320;
u32 var800887cc = 0x007d5320;
u32 var800887d0 = 0x007d8a20;
u32 var800887d4 = 0x007d8a20;
u32 var800887d8 = 0x007dc120;
u32 var800887dc = 0x007dc120;
u32 var800887e0 = 0x007df820;
u32 var800887e4 = 0x007df820;
u32 var800887e8 = 0x007e2f20;
u32 var800887ec = 0x007e2f20;
u32 var800887f0 = 0x007e6620;
u32 var800887f4 = 0x007e6620;
u32 var800887f8 = 0x007e9d20;
u32 var800887fc = 0x00000000;
u32 var80088800 = 0x00000000;
u8 var80088804 = 0;
u32 var80088808 = 0x00000000;
u32 var8008880c = 0x00000000;
u32 var80088810 = 0x00000000;
u32 var80088814 = 0x00d600d7;
u32 var80088818 = 0x00d900d8;
u32 var8008881c = 0x00da00db;
u32 var80088820 = 0x00dc00dd;
u32 var80088824 = 0x00de00df;
u32 var80088828 = 0x00e000e1;
u32 var8008882c = 0x00e200e3;
u32 var80088830 = 0x00e400e5;
u32 var80088834 = 0x00e600e7;
u32 var80088838 = 0x00e800e9;
u32 var8008883c = 0x00ea00eb;
u32 var80088840 = 0x00f400f3;
u32 var80088844 = 0x00f200f1;
u32 var80088848 = 0x00f000ef;
u32 var8008884c = 0x00ee00ed;
u32 var80088850 = 0x00ec0000;
u32 var80088854 = 0x00000005;
u32 var80088858 = 0x00000006;
u32 var8008885c = 0x00000007;
u32 var80088860 = 0x00000008;
u32 var80088864 = 0x00000009;
u32 var80088868 = 0x0000000a;
u32 var8008886c = 0x0000000b;
u32 var80088870 = 0x0000000c;
u32 var80088874 = 0x00000011;
u32 var80088878 = 0x00000012;
u32 var8008887c = 0x00000013;
u32 var80088880 = 0x00000014;
u32 var80088884 = 0x00000015;
u32 var80088888 = 0x00000016;
u32 var8008888c = 0x00000017;
u32 var80088890 = 0x00000018;
u32 var80088894 = 0x00000019;
u32 var80088898 = 0x0000001a;
u32 var8008889c = 0x00000001;
u8 var800888a0 = 0;

// 2e8c4
struct chrbio g_ChrBios[10] = {
	// name, race, age, profile
	/*0x00*/ { L_MISC(219), L_MISC(220), L_MISC(221), L_MISC(222) }, // Joanna Dark
	/*0x01*/ { L_MISC(223), L_MISC(224), L_MISC(225), L_MISC(226) }, // Jonathan
	/*0x02*/ { L_MISC(227), L_MISC(228), L_MISC(229), L_MISC(230) }, // Daniel Carrington
	/*0x03*/ { L_MISC(231), L_MISC(232), L_MISC(233), L_MISC(234) }, // Cassandra De Vries
	/*0x04*/ { L_MISC(235), L_MISC(236), L_MISC(237), L_MISC(238) }, // Trent Easton
	/*0x05*/ { L_MISC(239), L_MISC(240), L_MISC(241), L_MISC(242) }, // Dr. Caroll
	/*0x06*/ { L_MISC(243), L_MISC(244), L_MISC(245), L_MISC(246) }, // Elvis
	/*0x07*/ { L_MISC(247), L_MISC(248), L_MISC(249), L_MISC(250) }, // Mr. Blonde
	/*0x08*/ { L_MISC(251), L_MISC(252), L_MISC(253), L_MISC(254) }, // Mr. Blonde (repeat)
	/*0x09*/ { L_MISC(255), L_MISC(256), L_MISC(257), L_MISC(258) }, // The U.S. President
};

// 2e964
u32 misc_bios[] = {
	// name, description
	L_MISC(259), L_MISC(260), // Maians
	L_MISC(261), L_MISC(262), // Skedar Warrior
	L_MISC(263), L_MISC(264), // Background
	L_MISC(265), L_MISC(266), // The Story
};

u32 var80088964 = 0;

// 2e988
u32 place_bios[] = {
	// name, description
	L_MISC(290), L_MISC(313), 0, 0, // Carrington Institute
	L_MISC(291), L_MISC(314), 0, 0, // Lucerne Tower
	L_MISC(292), L_MISC(315), 0, 0, // Laboratory Basement
	L_MISC(293), L_MISC(316), 0, 0, // Carrington Villa
	L_MISC(294), L_MISC(317), 0, 0, // Chicago
	L_MISC(295), L_MISC(318), 0, 0, // G5 Building
	L_MISC(296), L_MISC(319), 0, 0, // Area 51
	L_MISC(297), L_MISC(320), 0, 0, // Alaskan Air Base
	L_MISC(298), L_MISC(321), 0, 0, // Air Force One
	L_MISC(299), L_MISC(322), 0, 0, // Crash Site
	L_MISC(300), L_MISC(323), 0, 0, // Pelagic II
	L_MISC(301), L_MISC(324), 0, 0, // Cetan Ship
	L_MISC(302), L_MISC(325), 0, 0, // Skedar Assault Ship
	L_MISC(303), L_MISC(326), 0, 0, // Skedar Homeworld
	L_MISC(304), L_MISC(327), 0, 0, // Jumpship
	L_MISC(305), L_MISC(328), 0, 0, // HoverCrate
	L_MISC(306), L_MISC(329), 0, 0, // HoverBike
	L_MISC(307), L_MISC(330), 0, 0, // Cleaning Hovbot
	L_MISC(308), L_MISC(331), 0, 0, // Hovercopter
	L_MISC(309), L_MISC(332), 0, 0, // G5 Robot
	L_MISC(310), L_MISC(333), 0, 0, // A51 Interceptor
	L_MISC(311), L_MISC(334), 0, 0, // Maian Vessel
	L_MISC(312), L_MISC(335), 0, 0, // Skedar Shuttle
};

u8 var80088ad8 = 0x00000000;
u8 var80088adc = 0;

u8 g_CiDeviceSaveFileFlags[] = {
	SAVEFILEFLAG_CI_UPLINK_DONE,
	SAVEFILEFLAG_CI_ECMMINE_DONE,
	SAVEFILEFLAG_CI_CAMSPY_DONE,
	SAVEFILEFLAG_CI_NIGHTVISION_DONE,
	SAVEFILEFLAG_CI_DOORDECODER_DONE,
	SAVEFILEFLAG_CI_RTRACKER_DONE,
	SAVEFILEFLAG_CI_IR_DONE,
	SAVEFILEFLAG_CI_XRAY_DONE,
	SAVEFILEFLAG_CI_DISGUISE_DONE,
	SAVEFILEFLAG_CI_CLOAK_DONE,
};

u32 g_CiDeviceWeapons[] = {
	WEAPON_DATAUPLINK,
	WEAPON_ECMMINE,
	WEAPON_CAMSPY,
	WEAPON_NIGHTVISION,
	WEAPON_DOORDECODER,
	WEAPON_RTRACKER,
	WEAPON_IRSCANNER,
	WEAPON_XRAYSCANNER,
	WEAPON_DISGUISE41,
	WEAPON_CLOAKINGDEVICE,
};

u32 g_CiDeviceStageFlags[] = {
	STAGEFLAG_CI_TRIGGER_UPLINK,
	STAGEFLAG_CI_TRIGGER_ECMMINE,
	STAGEFLAG_CI_TRIGGER_CAMSPY,
	STAGEFLAG_CI_TRIGGER_NIGHTVISION,
	STAGEFLAG_CI_TRIGGER_DOORDECODER,
	STAGEFLAG_CI_TRIGGER_RTRACKER,
	STAGEFLAG_CI_TRIGGER_IR,
	STAGEFLAG_CI_TRIGGER_XRAY,
	STAGEFLAG_CI_TRIGGER_DISGUISE,
	STAGEFLAG_CI_TRIGGER_CLOAK,
};

// 2eb5c
u32 device_descriptions[] = {
	/*0*/ L_MISC(280), // Data uplink
	/*1*/ L_MISC(279), // ECM mine
	/*2*/ L_MISC(271), // CamSpy
	/*3*/ L_MISC(272), // Night vision
	/*4*/ L_MISC(273), // Door decoder
	/*5*/ L_MISC(277), // R-tracker
	/*6*/ L_MISC(276), // IR scanner
	/*7*/ L_MISC(274), // X-ray scanner
	/*8*/ L_MISC(275), // Disguise
	/*9*/ L_MISC(278), // Cloak
};

// 2eb84
u32 device_tips1[] = {
	/*0*/ L_MISC(357),
	/*1*/ L_MISC(358),
	/*2*/ L_MISC(359),
	/*3*/ L_MISC(360),
	/*4*/ L_MISC(361),
	/*5*/ L_MISC(362),
	/*6*/ L_MISC(363),
	/*7*/ L_MISC(364),
	/*8*/ L_MISC(365),
	/*9*/ L_MISC(366),
};

// 2ebac
u32 device_tips2[] = {
	/*0*/ L_MISC(367),
	/*1*/ L_MISC(368),
	/*2*/ L_MISC(369),
	/*3*/ L_MISC(370),
	/*4*/ L_MISC(371),
	/*5*/ L_MISC(372),
	/*6*/ L_MISC(373),
	/*7*/ L_MISC(374),
	/*8*/ L_MISC(375),
	/*9*/ L_MISC(376),
};

u8 var80088bb4 = 0;
u8 var80088bb8 = 0;
s16 g_HoloRooms[5] = { 0x0016, 0x0017, 0x0018, 0x0019, -1 };
u32 var80088bc8 = 0x0000599a;
u32 var80088bcc = 0x0000599b;
u32 var80088bd0 = 0x0000599c;
u32 var80088bd4 = 0x0000599d;
u32 var80088bd8 = 0x0000599e;
u32 var80088bdc = 0x0000599f;
u32 var80088be0 = 0x000059a0;
u32 var80088be4 = 0x00040000;
u32 var80088be8 = 0x00080000;
u32 var80088bec = 0x00100000;
u32 var80088bf0 = 0x00200000;
u32 var80088bf4 = 0x00400000;
u32 var80088bf8 = 0x00800000;
u32 var80088bfc = 0x01000000;
u32 var80088c00 = 0x02000000;
u32 var80088c04 = 0x00005950;
u32 var80088c08 = 0x00005951;
u32 var80088c0c = 0x00005952;
u32 var80088c10 = 0x00005953;
u32 var80088c14 = 0x00005954;
u32 var80088c18 = 0x00005955;
u32 var80088c1c = 0x00005956;
u32 var80088c20 = 0x00005957;
u32 var80088c24 = 0x00005958;
u32 var80088c28 = 0x00005959;
u32 var80088c2c = 0x0000595a;
u32 var80088c30 = 0x0000595b;
u32 var80088c34 = 0x0000595c;
u32 var80088c38 = 0x0000595d;
u32 var80088c3c = 0x0000595e;
u32 var80088c40 = 0x0000595f;
u32 var80088c44 = 0x00005960;
u32 var80088c48 = 0x00005961;
u32 var80088c4c = 0x00005962;
u32 var80088c50 = 0x00005963;
u32 var80088c54 = 0x00005964;
u32 var80088c58 = 0x000059a7;
u32 var80088c5c = 0x000059a8;
u32 var80088c60 = 0x000059a9;
u32 var80088c64 = 0x000059aa;
u32 var80088c68 = 0x000059ab;
u32 var80088c6c = 0x00000000;
u32 var80088c70 = 0x51b751b8;
u32 var80088c74 = 0x51b90000;

u16 g_FiringRangeFailReasons[] = {
	L_MPMENU(456), // "Not Failed"
	L_MPMENU(457), // "Out of Ammo"
	L_MPMENU(458), // "Time Over"
	L_MPMENU(459), // "Score Unattainable"
	L_MPMENU(460), // "Too Inaccurate"
};

u16 g_FiringRangeDifficultyNames[] = {
	L_MPMENU(439), // "Bronze"
	L_MPMENU(440), // "Silver"
	L_MPMENU(441), // "Gold"
};

u32 var80088c8c = 0x00000000;
u32 var80088c90 = 0x00000000;
u32 var80088c94 = 0x00000000;
u32 var80088c98 = 0x00000000;
u32 var80088c9c = 0x00000000;
u32 var80088ca0 = 0x00000000;
u32 var80088ca4 = 0x00000000;
u32 var80088ca8 = 0x00000000;

// 2eccc
struct menu_item menuitems_frdifficulty[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000012, L_MPMENU(444), L_MPMENU(445), NULL }, // "Select Difficulty:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPMENU(439), L_OPTIONS(3), menuhandlerFrDifficulty }, // "Bronze"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000020, L_MPMENU(440), L_OPTIONS(3), menuhandlerFrDifficulty }, // "Silver"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000020, L_MPMENU(441), L_OPTIONS(3), menuhandlerFrDifficulty }, // "Gold"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPMENU(429), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2ed58
struct menu_dialog menudialog_frdifficulty = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(442), // "Difficulty"
	menuitems_frdifficulty,
	NULL,
	0x00000200,
	NULL,
};

// 2ed70
struct menu_item menuitems_frweapon[] = {
	{ MENUITEMTYPE_CUSTOM,      0, 0x00200008, 0x000000aa, 0x00000000, menuhandler001a348c },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2ed98
struct menu_dialog g_FrWeaponListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(446), // "Weapon"
	menuitems_frweapon,
	NULL,
	0x00000200,
	NULL,
};

// 2edb0
struct menu_item menuitems_frtraininginfo[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(443), (u32)&frMenuTextDifficultyName, NULL }, // "Difficulty"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, (u32)&frMenuTextGoalScoreLabel, (u32)&frMenuTextGoalScoreValue, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, (u32)&frMenuTextMinAccuracyOrTargetsLabel, (u32)&frMenuTextMinAccuracyOrTargetsValue, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, (u32)&frMenuTextTimeLimitLabel, (u32)&frMenuTextTimeLimitValue, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, (u32)&frMenuTextAmmoLimitLabel, (u32)&frMenuTextAmmoLimitValue, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SCROLLABLE,  6, 0x00004000, 0x0000010e, 0x0000005f, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(3), L_MPMENU(428), menuhandler001a3340 }, // "", "Resume"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(3), L_MPMENU(430), menuhandler001a3448 }, // "", "Abort"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2ee8c
struct menu_dialog g_FrTrainingInfoMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(447), // "Training Info"
	menuitems_frtraininginfo,
	menudialog001a39a8,
	0x00000602,
	NULL,
};

// 2eea4
struct menu_item menuitems_frtraininginfo2[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(443), (u32)&frMenuTextDifficultyName, NULL }, // "Difficulty:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, (u32)&frMenuTextGoalScoreLabel, (u32)&frMenuTextGoalScoreValue, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, (u32)&frMenuTextMinAccuracyOrTargetsLabel, (u32)&frMenuTextMinAccuracyOrTargetsValue, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, (u32)&frMenuTextTimeLimitLabel, (u32)&frMenuTextTimeLimitValue, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, (u32)&frMenuTextAmmoLimitLabel, (u32)&frMenuTextAmmoLimitValue, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SCROLLABLE,  6, 0x00004000, 0x0000010e, 0x0000005f, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(3), L_MPMENU(427), menuhandler001a3340 }, // "", "Ok"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_OPTIONS(3), L_MPMENU(429), menuhandler001a3448 }, // "", "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2ef80
struct menu_dialog menudialog_frtraininginfo2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(447), // "Training Info"
	menuitems_frtraininginfo2,
	menudialog001a39a8,
	0x00000602,
	NULL,
};

// 2ef98
struct menu_item menuitems_frtrainingstats[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, L_MPMENU(449), 0x00000000, NULL }, // "Completed!"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(450), (u32)&frMenuTextScoreValue, NULL }, // "Score:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(451), (u32)&frMenuTextTargetsDestroyedValue, NULL }, // "Targets Destroyed:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(452), (u32)&frMenuTextDifficultyName, NULL }, // "Difficulty:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(453), (u32)&frMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(454), (u32)&frMenuTextWeaponName, NULL }, // "Weapon:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(455), (u32)&frMenuTextAccuracyValue, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_MODEL,       0, 0x00200002, 0x000000d2, 0x00000050, menuhandler001a44c0 },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS(252), 0x00000000, menuhandlerFrFailedContinue }, // "Continue"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f09c
struct menu_dialog menudialog_frtrainingstats = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU(448), // "Training Stats"
	menuitems_frtrainingstats,
	menudialog001a3af4,
	0x00000004,
	NULL,
};

// 2f0b4
struct menu_item menuitems_frtrainingstats2[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&frMenuTextFailReason, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(450), (u32)&frMenuTextScoreValue, NULL }, // "Score:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(451), (u32)&frMenuTextTargetsDestroyedValue, NULL }, // "Targets Destroyed:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(452), (u32)&frMenuTextDifficultyName, NULL }, // "Difficulty:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(453), (u32)&frMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(454), (u32)&frMenuTextWeaponName, NULL }, // "Weapon:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(455), (u32)&frMenuTextAccuracyValue, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_MODEL,       0, 0x00200002, 0x000000d2, 0x00000050, menuhandler001a44c0 },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS(252), 0x00000000, menuhandlerFrFailedContinue }, // "Continue"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f1b8
struct menu_dialog menudialog_frtrainingstats2 = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(448), // "Training Stats"
	menuitems_frtrainingstats2,
	menudialog001a3af4,
	0x00000004,
	NULL,
};

u32 var800891b0 = 0x00000000;
u32 var800891b4 = 0x51a50000; // "Character Profiles"
u32 var800891b8 = 0x00000000;
u32 var800891bc = 0x51a60000; // "Other Information"

// 2f1e0
struct menu_item menuitems_information[] = {
	{ MENUITEMTYPE_CUSTOM,      0, 0x00000008, 0x000000c8, 0x00000000, menuhandler001a5dc0 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f208
struct menu_dialog menudialog_information = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(418), // "Information"
	menuitems_information,
	NULL,
	0x00000000,
	NULL,
};

// 2f220
struct menu_item menuitems_nowsafe[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, L_MPMENU(437), 0x00000000, NULL }, // "It is now safe to turn off your computer"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(438), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f270
struct menu_dialog menudialog_nowsafe = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(436), // "Cheats"
	menuitems_nowsafe,
	NULL,
	0x00000200,
	NULL,
};

u32 var80089268 = 0x01000200;
u32 var8008926c = 0x03000400;
u32 var80089270 = 0x05000700;
u32 var80089274 = 0x08000900;
u32 var80089278 = 0x0a000b00;
u32 var8008927c = 0xff000000;
u32 var80089280 = 0x0300ff00;

// 2f2a4
struct menu_item menuitems_characterprofile[] = {
	{ MENUITEMTYPE_MODEL,       0, 0x00000002, 0x00000046, 0x00000096, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000003, L_MPMENU(432), (u32)&ciMenuTextBioName, NULL }, // "Name:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(433), (u32)&ciMenuTextBioAge, NULL }, // "Age:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(434), (u32)&ciMenuTextBioRace, NULL }, // "Race:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SCROLLABLE,  3, 0x00000000, 0x000000b4, 0x00000064, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000022, L_MPMENU(435), 0x00000000, NULL }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f358
struct menu_dialog menudialog_characterprofile = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(431), // "Character Profile"
	menuitems_characterprofile,
	menudialog001a5f48,
	0x00000002,
	NULL,
};

// 2f370
struct menu_item menuitems_2f370[] = {
	{ MENUITEMTYPE_SCROLLABLE,  4, 0x00000000, 0x000000c8, 0x00000096, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000022, L_MPMENU(414), 0x00000000, NULL }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f3c0
struct menu_dialog menudialog_2f3c0 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f1a6388,
	menuitems_2f370,
	NULL,
	0x00000200,
	NULL,
};

// 2f3d8
struct menu_item menuitems_devicelist[] = {
	{ MENUITEMTYPE_CUSTOM,      0, 0x00000008, 0x000000a0, 0x00000000, menuhandler001a63e4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f400
struct menu_dialog g_DeviceTrainingListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(417), // "Device List"
	menuitems_devicelist,
	NULL,
	0x00000000,
	NULL,
};

u32 var800893f8 = 0xfafa9664;
u32 var800893fc = 0x64326464;
u32 var80089400 = 0x32960000;

// 2f424
struct menu_item menuitems_2f424[] = {
	{ MENUITEMTYPE_SCROLLABLE,  5, 0x00000000, 0x000000aa, 0x000000be, NULL },
	{ MENUITEMTYPE_MODEL,       0, 0x00000003, 0x0000008c, 0x0000009c, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, (u32)&dtMenuTextOkOrResume, 0x00000000, menuhandlerDtOkOrResume },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, (u32)&dtMenuTextCancelOrAbort, 0x00000000, menuhandler001a6514 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f49c
struct menu_dialog g_DeviceTrainingDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f1a64a0,
	menuitems_2f424,
	menudialog001a6548,
	0x00000206,
	NULL,
};

// 2f4b4
struct menu_item menuitems_trainingstats_failed[] = {
	{ MENUITEMTYPE_LABEL,        0, 0x00000032, L_MPMENU(426), 0x00000000, NULL }, // "Failed!"
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,        0, 0x00000002, L_MPMENU(424), (u32)&dtMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SCROLLABLE,  11, 0x00000000, 0x00000082, 0x00000064, NULL },
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f52c
struct menu_dialog g_DeviceTrainingStatsFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(423), // "Training Stats"
	menuitems_trainingstats_failed,
	menudialogDeviceTrainingResults,
	0x00000200,
	&g_DeviceTrainingListMenuDialog,
};

// 2f544
struct menu_item menuitems_trainingstats_completed[] = {
	{ MENUITEMTYPE_LABEL,        0, 0x00000032, L_MPMENU(425), 0x00000000, NULL }, // "Completed!"
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,        0, 0x00000002, L_MPMENU(424), (u32)&dtMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SCROLLABLE,  12, 0x00000000, 0x00000082, 0x00000064, NULL },
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f5bc
struct menu_dialog g_DeviceTrainingStatsCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU(423), // "Training Stats"
	menuitems_trainingstats_completed,
	menudialogDeviceTrainingResults,
	0x00000200,
	&g_DeviceTrainingListMenuDialog,
};

// 2f5d4
struct menu_item menuitems_holotraining[] = {
	{ MENUITEMTYPE_CUSTOM,      0, 0x00000008, 0x000000a0, 0x00000000, menuhandler001a6950 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f5fc
struct menu_dialog g_HoloTrainingListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(416), // "Holotraining"
	menuitems_holotraining,
	NULL,
	0x00000000,
	NULL,
};

// 2f614
struct menu_item menuitems_2f614[] = {
	{ MENUITEMTYPE_SCROLLABLE,  8, 0x00000000, 0x000000aa, 0x000000be, NULL },
	{ MENUITEMTYPE_MODEL,       0, 0x00000003, 0x0000008c, 0x0000009c, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, (u32)&htMenuTextOkOrResume, 0x00000000, menuhandler001a6a34 },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, (u32)&htMenuTextCancelOrAbort, 0x00000000, menuhandler001a6a70 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f68c
struct menu_dialog g_HoloTrainingDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f1a6a04,
	menuitems_2f614,
	menudialog001a6aa4,
	0x00000206,
	NULL,
};

// 2f6a4
struct menu_item menuitems_trainingstats_failed2[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000032, L_MPMENU(426), 0x00000000, NULL }, // "Failed!"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(424), (u32)&htMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SCROLLABLE,  9, 0x00000000, 0x00000082, 0x00000064, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f71c
struct menu_dialog g_HoloTrainingStatsFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(423), // "Training Stats"
	menuitems_trainingstats_failed2,
	menudialogFiringRangeResults,
	0x00000200,
	&g_HoloTrainingListMenuDialog,
};

// 2f734
struct menu_item menuitems_trainingstats_completed2[] = {
	{ MENUITEMTYPE_LABEL,        0, 0x00000032, L_MPMENU(425), 0x00000000, NULL }, // "Completed!"
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,        0, 0x00000002, L_MPMENU(424), (u32)&htMenuTextTimeTakenValue, NULL }, // "Time Taken:"
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SCROLLABLE,  10, 0x00000000, 0x00000082, 0x00000064, NULL },
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f7ac
struct menu_dialog g_HoloTrainingStatsCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU(423), // "Training Stats"
	menuitems_trainingstats_completed2,
	menudialogFiringRangeResults,
	0x00000200,
	&g_HoloTrainingListMenuDialog,
};

u32 var800897a4 = 0x00000000;
u32 var800897a8 = 0x51a30000; // "Locations"
u32 var800897ac = 0x00000000;
u32 var800897b0 = 0x51a40000; // "Vehicles"

u32 var800897b4 = 0x1b0d0e10;
u32 var800897b8 = 0x11121316;
u32 var800897bc = 0x1718191a;
u32 var800897c0 = 0x1c1d0000;
u32 var800897c4 = 0xb7000500;
u32 var800897c8 = 0x0400ff00;

// 2f7ec
struct hoverprop hoverprops[] = {
	// File ID, Y offset, size
	{ 0x00c8,   7,    8 }, // dropship
	{ 0x00d7,  -5,  600 }, // hovercrate1
	{ 0x00d5, -10,   50 }, // hovbike
	{ 0x00d4, -20, 1000 }, // hooverbot
	{ 0x0097,  35,   30 }, // dd_hovercopter
	{ 0x0236,   0,   70 }, // chicrob
	{ 0x04b1, -30,  500 }, // a51interceptor
	{ 0x033e,   0,   15 }, // elvis_saucer
	{ 0x023f,   0,   10 }, // sk_shuttle
};

// 2f858
struct menu_item menuitems_2f858[] = {
	{ MENUITEMTYPE_MODEL,       0, 0x00200002, 0x00000104, 0x0000002c, menuhandler001a6ea4 },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SCROLLABLE,  7, 0x00000000, 0x00000104, 0x0000005a, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000022, L_MPMENU(414), 0x00000000, NULL }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f8d0
struct menu_item menuitems_holograph[] = {
	{ MENUITEMTYPE_MODEL,       0, 0x00000002, 0x00000104, 0x0000006e, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000022, L_MPMENU(414), 0x00000000, NULL }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f920
struct menu_dialog menudialog_holograph = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC(471), // "Holograph"
	menuitems_holograph,
	menudialog001a737c,
	0x00000202,
	NULL,
};

// 2f938
struct menu_dialog menudialog_2f938 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f1a6c8c,
	menuitems_2f858,
	NULL,
	0x00000202,
	&menudialog_holograph,
};

// 2f950
struct menu_dialog menudialog_2f950 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f1a6c8c,
	menuitems_2f858,
	NULL,
	0x00000202,
	NULL,
};

// 2f968
struct menu_item menuitems_hangarinformation[] = {
	{ MENUITEMTYPE_CUSTOM,      0, 0x00000008, 0x000000a0, 0x00000000, menuhandler001a6d4c },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f990
struct menu_dialog menudialog_hangarinformation = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(415), // "Hangar Information"
	menuitems_hangarinformation,
	NULL,
	0x00000000,
	NULL,
};

u32 var80089988 = 0x00000000;
u32 var8008998c = 0x00000000;
u32 var80089990 = (u32) &stagethinglist_22e60;
u32 var80089994 = (u32) &stagethinglist_221cc;
u32 var80089998 = (u32) &stagethinglist_22200;
u32 var8008999c = (u32) &stagethinglist_22220;
u32 var800899a0 = (u32) &stagethinglist_2208c;
u32 var800899a4 = (u32) &stagethinglist_20e54;
u32 var800899a8 = (u32) &stagethinglist_20ef8;
u32 var800899ac = (u32) &stagethinglist_20ea4;
u32 var800899b0 = (u32) &stagethinglist_20eec;
u32 var800899b4 = (u32) &stagethinglist_20ec8;
u32 var800899b8 = (u32) &stagethinglist_20e60;
u32 var800899bc = (u32) &stagethinglist_20e6c;
u32 var800899c0 = (u32) &stagethinglist_20e94;
u32 var800899c4 = (u32) &stagethinglist_20f0c;
u32 var800899c8 = (u32) &stagethinglist_20edc;
u32 var800899cc = (u32) &stagethinglist_20e80;
u32 var800899d0 = (u32) &stagethinglist_221a4;
u32 var800899d4 = (u32) &stagethinglist_220d0;
u32 var800899d8 = (u32) &stagethinglist_221e4;
u32 var800899dc = (u32) &stagethinglist_220a4;
u32 var800899e0 = (u32) &stagethinglist_20f18;
u32 var800899e4 = (u32) &stagethinglist_2224c;
u32 var800899e8 = (u32) &stagethinglist_20e48;
u32 var800899ec = (u32) &stagethinglist_22eb8;
u32 var800899f0 = (u32) &stagethinglist_20f24;
u32 var800899f4 = (u32) &stagethinglist_20f50;
u32 var800899f8 = (u32) &stagethinglist_20f5c;
u32 var800899fc = (u32) &stagethinglist_20f74;
u32 var80089a00 = (u32) &stagethinglist_221b4;
u32 var80089a04 = (u32) &stagethinglist_222b4;
u32 var80089a08 = (u32) &stagethinglist_22f0c;
u32 var80089a0c = (u32) &stagethinglist_22318;
u32 var80089a10 = (u32) &stagethinglist_22374;
u32 var80089a14 = (u32) &stagethinglist_20f84;
u32 var80089a18 = (u32) &stagethinglist_223d4;
u32 var80089a1c = (u32) &stagethinglist_22424;
u32 var80089a20 = (u32) &stagethinglist_22ec8;
u32 var80089a24 = (u32) &stagethinglist_20fb8;
u32 var80089a28 = (u32) &stagethinglist_2247c;
u32 var80089a2c = (u32) &stagethinglist_20fd8;
u32 var80089a30 = (u32) &stagethinglist_224d8;
u32 var80089a34 = (u32) &stagethinglist_22538;
u32 var80089a38 = (u32) &stagethinglist_2258c;
u32 var80089a3c = (u32) &stagethinglist_225d8;
u32 var80089a40 = (u32) &stagethinglist_22630;
u32 var80089a44 = (u32) &stagethinglist_22698;
u32 var80089a48 = (u32) &stagethinglist_226e8;
u32 var80089a4c = (u32) &stagethinglist_22754;
u32 var80089a50 = (u32) &stagethinglist_20e10;
u32 var80089a54 = (u32) &stagethinglist_227ac;
u32 var80089a58 = (u32) &stagethinglist_22804;
u32 var80089a5c = (u32) &stagethinglist_22f1c;
u32 var80089a60 = (u32) &stagethinglist_2285c;
u32 var80089a64 = (u32) &stagethinglist_228b4;
u32 var80089a68 = (u32) &stagethinglist_2291c;
u32 var80089a6c = (u32) &stagethinglist_22970;
u32 var80089a70 = (u32) &stagethinglist_229c4;
u32 var80089a74 = (u32) &stagethinglist_22a20;
u32 var80089a78 = (u32) &stagethinglist_22a78;
u32 var80089a7c = (u32) &stagethinglist_22adc;
u32 var80089a80 = (u32) &stagethinglist_22c54;
u32 var80089a84 = (u32) &stagethinglist_22b28;
u32 var80089a88 = (u32) &stagethinglist_22b80;
u32 var80089a8c = (u32) &stagethinglist_22be0;
u32 var80089a90 = (u32) &stagethinglist_22ca0;
u32 var80089a94 = (u32) &stagethinglist_22c3c;
u32 var80089a98 = (u32) &stagethinglist_20e3c;
u32 var80089a9c = (u32) &stagethinglist_22cf0;
u32 var80089aa0 = (u32) &stagethinglist_20fe8;
u32 var80089aa4 = (u32) &stagethinglist_22d40;
u32 var80089aa8 = (u32) &stagethinglist_20ff8;
u32 var80089aac = (u32) &stagethinglist_2100c;
u32 var80089ab0 = (u32) &stagethinglist_21018;
u32 var80089ab4 = (u32) &stagethinglist_22d90;
u32 var80089ab8 = (u32) &stagethinglist_22de0;
u32 var80089abc = (u32) &stagethinglist_21024;
u32 var80089ac0 = (u32) &stagethinglist_21034;
u32 var80089ac4 = (u32) &stagethinglist_22e34;
u32 var80089ac8 = (u32) &stagethinglist_21084;
u32 var80089acc = 0x00000000;
u32 var80089ad0 = 0x00000000;
u32 var80089ad4 = 0x0f6f1080;
u32 var80089ad8 = 0x00000f70;
u32 var80089adc = 0x00871000;
u32 var80089ae0 = 0x00000ff8;
u32 var80089ae4 = 0x021f17a0;
u32 var80089ae8 = 0x00001218;
u32 var80089aec = 0x019717a0;
u32 var80089af0 = 0x000013b0;
u32 var80089af4 = 0x006717a0;
u32 var80089af8 = 0x0ffaf006;
u32 var80089afc = 0x7fff0000;
u32 var80089b00 = 0x00000001;
u32 var80089b04 = 0x0002ffff;
u32 var80089b08 = 0x40000004;
u32 var80089b0c = 0x06330200;
u32 var80089b10 = 0x7ffffff8;
u32 var80089b14 = 0x00080040;
u32 var80089b18 = 0x00208000;
u32 var80089b1c = 0x01cccccc;
u32 var80089b20 = 0x0001ffff;
u32 var80089b24 = 0x00010001;
u32 var80089b28 = 0x0001ffff;
u32 var80089b2c = 0x00010001;
u32 var80089b30 = 0x00020002;
u32 var80089b34 = 0x00020002;
u32 var80089b38 = 0x00020002;
u32 var80089b3c = 0x00020002;
u32 var80089b40 = 0x00010000;
u32 var80089b44 = 0x00000001;
u32 var80089b48 = 0x00000001;
u32 var80089b4c = 0x00000001;
u32 var80089b50 = 0x00010000;
u32 var80089b54 = 0x0000ffff;
u32 var80089b58 = 0x00000001;
u32 var80089b5c = 0x0000ffff;
u32 var80089b60 = 0x00000000;
u32 var80089b64 = 0x0001ffff;
u32 var80089b68 = 0x00000000;
u32 var80089b6c = 0x00000001;
u32 var80089b70 = 0x17ac7fff;
u32 var80089b74 = 0x571d3a0c;
u32 var80089b78 = 0x00010002;
u32 var80089b7c = 0x01000200;
u32 var80089b80 = 0x40000040;
u32 var80089b84 = 0x000017a8;
u32 var80089b88 = 0x00ffffff;
u32 var80089b8c = 0x139c10a8;
u32 var80089b90 = 0x11fc1364;
u32 var80089b94 = 0x10a813b4;
u32 var80089b98 = 0x10a81530;
u32 var80089b9c = 0x154010a8;
u32 var80089ba0 = 0x17501784;
u32 var80089ba4 = 0x10a810a8;
u32 var80089ba8 = 0x120c1358;
u32 var80089bac = 0x135c1350;
u32 var80089bb0 = 0x10a81338;
u32 var80089bb4 = 0x13281308;
u32 var80089bb8 = 0x12c812c0;
u32 var80089bbc = 0x129c1284;
u32 var80089bc0 = 0x10a810a8;
u32 var80089bc4 = 0x124c17f4;
u32 var80089bc8 = 0x17f81850;
u32 var80089bcc = 0x1864199c;
u32 var80089bd0 = 0x17bc17d8;
u32 var80089bd4 = 0x10580000;
u32 var80089bd8 = 0x00000000;
u32 var80089bdc = 0x00000000;
u32 var80089be0 = 0x0000ffff;
u32 var80089be4 = 0x00000000;
u32 var80089be8 = 0xef080cff;
u32 var80089bec = 0x00000000;
u32 var80089bf0 = 0x00000000;
u32 var80089bf4 = 0x00000000;
u32 var80089bf8 = 0x00000000;
u32 var80089bfc = 0x80000040;
u32 var80089c00 = 0x00000000;
u32 var80089c04 = 0x00000000;
u32 var80089c08 = 0x40004000;
u32 var80089c0c = 0x00000000;
u32 var80089c10 = 0x00000000;
u32 var80089c14 = 0x00000000;
u32 var80089c18 = 0x00000000;
u32 var80089c1c = 0x00000000;
u32 var80089c20 = 0x00000000;
u32 var80089c24 = 0x00000000;
u32 var80089c28 = 0x00000000;
u32 var80089c2c = 0x00000000;
u32 var80089c30 = 0x00000000;
u32 var80089c34 = 0x00000000;
u32 var80089c38 = 0x00000000;
u32 var80089c3c = 0x00000000;
u32 var80089c40 = 0x00000000;
u32 var80089c44 = 0x00000000;
u32 var80089c48 = 0x00000000;
u32 var80089c4c = 0x00000000;
u32 var80089c50 = 0x00000000;
u32 var80089c54 = 0x00000000;
u32 var80089c58 = 0x00000000;
u32 var80089c5c = 0x00000000;
u32 var80089c60 = 0x00000000;
u32 var80089c64 = 0x00000000;
u32 var80089c68 = 0x00000000;
u32 var80089c6c = 0x00000000;
u32 var80089c70 = 0x80000000;
u32 var80089c74 = 0x80000000;
u32 var80089c78 = 0x00000000;
u32 var80089c7c = 0x00000000;
u32 var80089c80 = 0x00800000;
u32 var80089c84 = 0x00800000;
u32 var80089c88 = 0x7f000000;
u32 var80089c8c = 0x00000000;
u32 var80089c90 = 0x00000000;
u32 var80089c94 = 0x00000000;
u32 var80089c98 = 0x00000000;
u32 var80089c9c = 0x00000000;
u32 var80089ca0 = 0x00000000;
u32 var80089ca4 = 0x00000000;
u32 var80089ca8 = 0x007f0000;
u32 var80089cac = 0x00000000;
u32 var80089cb0 = 0x00000000;
u32 var80089cb4 = 0x00000000;
u32 var80089cb8 = 0x00000000;
u32 var80089cbc = 0x00000000;
u32 var80089cc0 = 0x00000000;
u32 var80089cc4 = 0x00000000;
u32 var80089cc8 = 0x00000000;
u32 var80089ccc = 0x00000000;
u32 var80089cd0 = 0x00000000;
u32 var80089cd4 = 0x00000000;
u32 var80089cd8 = 0xe0011fff;
u32 var80089cdc = 0x00040000;
u32 var80089ce0 = 0xff000000;
u32 var80089ce4 = 0xff000000;
u32 var80089ce8 = 0x00000000;
u32 var80089cec = 0x00000000;
u32 var80089cf0 = 0x000a141e;
u32 var80089cf4 = 0x28323c46;
u32 var80089cf8 = 0x505a646e;
u32 var80089cfc = 0x78828c96;
u32 var80089d00 = 0x026001b0;
u32 var80089d04 = 0x01d001f0;
u32 var80089d08 = 0x021001f0;
u32 var80089d0c = 0x01f001f0;
u32 var80089d10 = 0x01f001f0;
u32 var80089d14 = 0x01f00138;
u32 var80089d18 = 0x03300340;
u32 var80089d1c = 0x03500320;
u32 var80089d20 = 0x012c0070;
u32 var80089d24 = 0x01600270;
u32 var80089d28 = 0x01f00360;
u32 var80089d2c = 0x01100000;
u32 var80089d30 = 0x00000000;
u32 var80089d34 = 0x00000000;
u32 var80089d38 = 0x00000000;
u32 var80089d3c = 0x00000000;
u32 var80089d40 = 0x01000000;
u32 var80089d44 = 0x00ff0000;
u32 var80089d48 = 0x00000000;
u32 var80089d4c = 0x00000000;
u32 var80089d50 = 0x00000000;
u32 var80089d54 = 0x00000000;
u32 var80089d58 = 0x00000000;
u32 var80089d5c = 0x00000000;
u32 var80089d60 = 0x00000000;
u32 var80089d64 = 0x00000000;
u32 var80089d68 = 0x00000000;
u32 var80089d6c = 0x00000000;
u32 var80089d70 = 0x00000000;
u32 var80089d74 = 0x00000000;
u32 var80089d78 = 0x00000000;
u32 var80089d7c = 0x00000000;
u32 var80089d80 = 0x00000000;
u32 var80089d84 = 0x00000000;
u32 var80089d88 = 0x00000000;
u32 var80089d8c = 0x00000000;
u32 var80089d90 = 0x00000000;
u32 var80089d94 = 0x00000000;
u32 var80089d98 = 0x00000000;
u32 var80089d9c = 0x00000000;
u32 var80089da0 = 0x00000000;
u32 var80089da4 = 0x00000000;
u32 var80089da8 = 0x00000000;
u32 var80089dac = 0x00000000;
u32 var80089db0 = 0x00000000;
u32 var80089db4 = 0x00000000;
u32 var80089db8 = 0x00000000;
u32 var80089dbc = 0x00000000;
u32 var80089dc0 = 0x00000000;
u32 var80089dc4 = 0x00000000;
u32 var80089dc8 = 0x00000000;
u32 var80089dcc = 0x00000000;
u32 var80089dd0 = 0x00000000;
u32 var80089dd4 = 0x00000000;
u32 var80089dd8 = 0x00000000;
u32 var80089ddc = 0x00000000;
u32 var80089de0 = 0x00000000;
u32 var80089de4 = 0x00000000;
u32 var80089de8 = 0x00000000;
u32 var80089dec = 0x00000000;
u32 var80089df0 = 0x00000000;
u32 var80089df4 = 0x00000000;
u32 var80089df8 = 0x00000000;
u32 var80089dfc = 0x00000000;
u32 var80089e00 = 0x00000000;
u32 var80089e04 = 0x00000000;
u32 var80089e08 = 0x00000000;
u32 var80089e0c = 0x00000000;
u32 var80089e10 = 0x00000000;
u32 var80089e14 = 0x00000000;
u32 var80089e18 = 0x00000000;
u32 var80089e1c = 0x00000000;
u32 var80089e20 = 0x00000000;
u32 var80089e24 = 0x00000000;
u32 var80089e28 = 0x00000000;
u32 var80089e2c = 0x00000000;
u32 var80089e30 = 0x00000000;
u32 var80089e34 = 0x00000000;
u32 var80089e38 = 0x00000000;
u32 var80089e3c = 0x00000000;
u32 var80089e40 = 0x00000000;
u32 var80089e44 = 0x00000000;
u32 var80089e48 = 0x00000000;
u32 var80089e4c = 0x00000000;
u32 var80089e50 = 0x00000000;
u32 var80089e54 = 0x00000000;
u32 var80089e58 = 0x00000000;
u32 var80089e5c = 0x00000000;
u32 var80089e60 = 0x00000000;
u32 var80089e64 = 0x00000000;
u32 var80089e68 = 0x00000000;
u32 var80089e6c = 0x00000000;
u32 var80089e70 = 0x00000000;
u32 var80089e74 = 0x00000000;
u32 var80089e78 = 0x00000000;
u32 var80089e7c = 0x00000000;
u32 var80089e80 = 0x00000000;
u32 var80089e84 = 0x00000000;
u32 var80089e88 = 0x00000000;
u32 var80089e8c = 0x00000000;
u32 var80089e90 = 0x00000000;
u32 var80089e94 = 0x00000000;
u32 var80089e98 = 0x00000000;
u32 var80089e9c = 0x00000000;
u32 var80089ea0 = 0x00000000;
u32 var80089ea4 = 0x00000000;
u32 var80089ea8 = 0x00000000;
u32 var80089eac = 0x00000000;
u32 var80089eb0 = 0x00000000;
u32 var80089eb4 = 0x00000000;
u32 var80089eb8 = 0x00000000;
u32 var80089ebc = 0x00000000;
u32 var80089ec0 = 0x00000000;
u32 var80089ec4 = 0x00000000;
u32 var80089ec8 = 0x00000000;
u32 var80089ecc = 0x00000000;
u32 var80089ed0 = 0x00000000;
u32 var80089ed4 = 0x00000000;
u32 var80089ed8 = 0x00000000;
u32 var80089edc = 0x00000000;
u32 var80089ee0 = 0x00000000;
u32 var80089ee4 = 0x00000000;
u32 var80089ee8 = 0x00000000;
u32 var80089eec = 0x00000000;
u32 var80089ef0 = 0x00000000;
u32 var80089ef4 = 0x00000000;
u32 var80089ef8 = 0x00000000;
u32 var80089efc = 0x00000000;
u32 var80089f00 = 0x00000000;
u32 var80089f04 = 0x00000000;
u32 var80089f08 = 0x00000000;
u32 var80089f0c = 0x00000000;
u32 var80089f10 = 0x00000000;
u32 var80089f14 = 0x00000000;
u32 var80089f18 = 0x00000000;
u32 var80089f1c = 0x00000000;
u32 var80089f20 = 0x00000000;
u32 var80089f24 = 0x00000000;
u32 var80089f28 = 0x00000000;
u32 var80089f2c = 0x00000000;
u32 var80089f30 = 0x00000000;
u32 var80089f34 = 0x00000000;
u32 var80089f38 = 0x00000000;
u32 var80089f3c = 0x00000000;
u32 var80089f40 = 0x00000000;
u32 var80089f44 = 0x00000000;
u32 var80089f48 = 0x00000000;
u32 var80089f4c = 0x00000000;
u32 var80089f50 = 0x00000000;
u32 var80089f54 = 0x00000000;
u32 var80089f58 = 0x00000000;
u32 var80089f5c = 0x00000000;
u32 var80089f60 = 0x00000000;
u32 var80089f64 = 0x00000000;
u32 var80089f68 = 0x00000000;
u32 var80089f6c = 0x00000000;
u32 var80089f70 = 0x00000000;
u32 var80089f74 = 0x00000000;
u32 var80089f78 = 0x00000000;
u32 var80089f7c = 0x00000000;
u32 var80089f80 = 0x00000000;
u32 var80089f84 = 0x00000000;
u32 var80089f88 = 0x00000000;
u32 var80089f8c = 0x00000000;
u32 var80089f90 = 0x00000000;
u32 var80089f94 = 0x00000000;
u32 var80089f98 = 0x00000000;
u32 var80089f9c = 0x00000000;
u32 var80089fa0 = 0x00000000;
u32 var80089fa4 = 0x00000000;
u32 var80089fa8 = 0x00000000;
u32 var80089fac = 0x00000000;
u32 var80089fb0 = 0x00000000;
u32 var80089fb4 = 0x00000000;
u32 var80089fb8 = 0x00000000;
u32 var80089fbc = 0x00000000;
u32 var80089fc0 = 0x00000000;
u32 var80089fc4 = 0x00000000;
u32 var80089fc8 = 0x00000000;
u32 var80089fcc = 0x00000000;
u32 var80089fd0 = 0x00000000;
u32 var80089fd4 = 0x00000000;
u32 var80089fd8 = 0x00000000;
u32 var80089fdc = 0x00000000;
u32 var80089fe0 = 0x00000000;
u32 var80089fe4 = 0x00000000;
u32 var80089fe8 = 0x00000000;
u32 var80089fec = 0x00000000;
u32 var80089ff0 = 0x00000000;
u32 var80089ff4 = 0x00000000;
u32 var80089ff8 = 0x00000000;
u32 var80089ffc = 0x00000000;
u32 var8008a000 = 0x00000000;
u32 var8008a004 = 0x00000000;
u32 var8008a008 = 0x00000000;
u32 var8008a00c = 0x00000000;
u32 var8008a010 = 0x00000000;
u32 var8008a014 = 0x00000000;
u32 var8008a018 = 0x00000000;
u32 var8008a01c = 0x00000000;
u32 var8008a020 = 0x00000000;
u32 var8008a024 = 0x00000000;
u32 var8008a028 = 0x00000000;
u32 var8008a02c = 0x00000000;
u32 var8008a030 = 0x00000000;
u32 var8008a034 = 0x00000000;
u32 var8008a038 = 0x00000000;
u32 var8008a03c = 0x00000000;
u32 var8008a040 = 0x00000000;
u32 var8008a044 = 0x00000000;
u32 var8008a048 = 0x00000000;
u32 var8008a04c = 0x00000000;
u32 var8008a050 = 0x00000000;
u32 var8008a054 = 0x00000000;
u32 var8008a058 = 0x00000000;
u32 var8008a05c = 0x00000000;
u32 var8008a060 = 0x00000000;
u32 var8008a064 = 0x00000000;
u32 var8008a068 = 0x00000000;
u32 var8008a06c = 0x00000000;
u32 var8008a070 = 0x00000000;
u32 var8008a074 = 0x00000000;
u32 var8008a078 = 0x00000000;
u32 var8008a07c = 0x00000000;
u32 var8008a080 = 0x00000000;
u32 var8008a084 = 0x00000000;
u32 var8008a088 = 0x00000000;
u32 var8008a08c = 0x00000000;
u32 var8008a090 = 0x00000000;
u32 var8008a094 = 0x00000000;
u32 var8008a098 = 0x00000000;
u32 var8008a09c = 0x00000000;
u32 var8008a0a0 = 0x00000000;
u32 var8008a0a4 = 0x00000000;
u32 var8008a0a8 = 0x00000000;
u32 var8008a0ac = 0x00000000;
u32 var8008a0b0 = 0x00000000;
u32 var8008a0b4 = 0x00000000;
u32 var8008a0b8 = 0x00000000;
u32 var8008a0bc = 0x00000000;
u32 var8008a0c0 = 0x00000000;
u32 var8008a0c4 = 0x00000000;
u32 var8008a0c8 = 0x00000000;
u32 var8008a0cc = 0x00000000;
u32 var8008a0d0 = 0x00000000;
u32 var8008a0d4 = 0x00000000;
u32 var8008a0d8 = 0x00000000;
u32 var8008a0dc = 0x00000000;
u32 var8008a0e0 = 0x00000000;
u32 var8008a0e4 = 0x00000000;
u32 var8008a0e8 = 0x00000000;
u32 var8008a0ec = 0x00000000;
u32 var8008a0f0 = 0x00000000;
u32 var8008a0f4 = 0x00000000;
u32 var8008a0f8 = 0x00000000;
u32 var8008a0fc = 0x00000000;
u32 var8008a100 = 0x00000000;
u32 var8008a104 = 0x00000000;
u32 var8008a108 = 0x00000000;
u32 var8008a10c = 0x00000000;
u32 var8008a110 = 0x00000000;
u32 var8008a114 = 0x00000000;
u32 var8008a118 = 0x00000000;
u32 var8008a11c = 0x00000000;
u32 var8008a120 = 0x00000000;
u32 var8008a124 = 0x00000000;
u32 var8008a128 = 0x00000000;
u32 var8008a12c = 0x00000000;
u32 var8008a130 = 0x00000000;
u32 var8008a134 = 0x00000000;
u32 var8008a138 = 0x00000000;
u32 var8008a13c = 0x00000000;
u32 var8008a140 = 0x00000000;
u32 var8008a144 = 0x00000000;
u32 var8008a148 = 0x00000000;
u32 var8008a14c = 0x00000000;
u32 var8008a150 = 0x00000000;
u32 var8008a154 = 0x00000000;
u32 var8008a158 = 0x00000000;
u32 var8008a15c = 0x00000000;
u32 var8008a160 = 0x00000000;
u32 var8008a164 = 0x00000000;
u32 var8008a168 = 0x00000000;
u32 var8008a16c = 0x00000000;
u32 var8008a170 = 0x00000000;
u32 var8008a174 = 0x00000000;
u32 var8008a178 = 0x00000000;
u32 var8008a17c = 0x00000000;
u32 var8008a180 = 0x00000000;
u32 var8008a184 = 0x00000000;
u32 var8008a188 = 0x00000000;
u32 var8008a18c = 0x00000000;
u32 var8008a190 = 0x00000000;
u32 var8008a194 = 0x00000000;
u32 var8008a198 = 0x00000000;
u32 var8008a19c = 0x00000000;
u32 var8008a1a0 = 0x00000000;
u32 var8008a1a4 = 0x00000000;
u32 var8008a1a8 = 0x00000000;
u32 var8008a1ac = 0x00000000;
u32 var8008a1b0 = 0x00000000;
u32 var8008a1b4 = 0x00000000;
u32 var8008a1b8 = 0x00000000;
u32 var8008a1bc = 0x00000000;
u32 var8008a1c0 = 0x00000000;
u32 var8008a1c4 = 0x00000000;
u32 var8008a1c8 = 0x00000000;
u32 var8008a1cc = 0x00000000;
u32 var8008a1d0 = 0x00000000;
u32 var8008a1d4 = 0x00000000;
u32 var8008a1d8 = 0x00000000;
u32 var8008a1dc = 0x00000000;
u32 var8008a1e0 = 0x00000000;
u32 var8008a1e4 = 0x00000000;
u32 var8008a1e8 = 0x00000000;
u32 var8008a1ec = 0x00000000;
u32 var8008a1f0 = 0x00000000;
u32 var8008a1f4 = 0x00000000;
u32 var8008a1f8 = 0x00000000;
u32 var8008a1fc = 0x00000000;
u32 var8008a200 = 0x00000000;
u32 var8008a204 = 0x00000000;
u32 var8008a208 = 0x00000000;
u32 var8008a20c = 0x00000000;
u32 var8008a210 = 0x00000000;
u32 var8008a214 = 0x00000000;
u32 var8008a218 = 0x00000000;
u32 var8008a21c = 0x00000000;
u32 var8008a220 = 0x00000000;
u32 var8008a224 = 0x00000000;
u32 var8008a228 = 0x00000000;
u32 var8008a22c = 0x00000000;
u32 var8008a230 = 0x00000000;
u32 var8008a234 = 0x00000000;
u32 var8008a238 = 0x00000000;
u32 var8008a23c = 0x00000000;
u32 var8008a240 = 0x00000000;
u32 var8008a244 = 0x00000000;
u32 var8008a248 = 0x00000000;
u32 var8008a24c = 0x00000000;
u32 var8008a250 = 0x00000000;
u32 var8008a254 = 0x00000000;
u32 var8008a258 = 0x00000000;
u32 var8008a25c = 0x00000000;
u32 var8008a260 = 0x00000000;
u32 var8008a264 = 0x00000000;
u32 var8008a268 = 0x00000000;
u32 var8008a26c = 0x00000000;
u32 var8008a270 = 0x00000000;
u32 var8008a274 = 0x00000000;
u32 var8008a278 = 0x00000000;
u32 var8008a27c = 0x00000000;
u32 var8008a280 = 0x00000000;
u32 var8008a284 = 0x00000000;
u32 var8008a288 = 0x00000000;
u32 var8008a28c = 0x00000000;
u32 var8008a290 = 0x00000000;
u32 var8008a294 = 0x00000000;
u32 var8008a298 = 0x00000000;
u32 var8008a29c = 0x00000000;
u32 var8008a2a0 = 0x00000000;
u32 var8008a2a4 = 0x00000000;
u32 var8008a2a8 = 0x00000000;
u32 var8008a2ac = 0x00000000;
u32 var8008a2b0 = 0x00000000;
u32 var8008a2b4 = 0x00000000;
u32 var8008a2b8 = 0x00000000;
u32 var8008a2bc = 0x00000000;
u32 var8008a2c0 = 0x00000000;
u32 var8008a2c4 = 0x00000000;
u32 var8008a2c8 = 0x00000000;
u32 var8008a2cc = 0x00000000;
u32 var8008a2d0 = 0x00000000;
u32 var8008a2d4 = 0x0f7f1080;
u32 var8008a2d8 = 0x00000f80;
u32 var8008a2dc = 0x09bf1238;
u32 var8008a2e0 = 0x1ae8143c;
u32 var8008a2e4 = 0x12401d84;
u32 var8008a2e8 = 0x126c1b20;
u32 var8008a2ec = 0x12a81214;
u32 var8008a2f0 = 0x141c1310;
u32 var8008a2f4 = 0x13cc12e4;
u32 var8008a2f8 = 0x1fb01358;
u32 var8008a2fc = 0x16ec1408;
u32 var8008a300 = 0xf0000f00;
u32 var8008a304 = 0x00f0000f;
u32 var8008a308 = 0x00010010;
u32 var8008a30c = 0x01001000;
u32 var8008a310 = 0x00020004;
u32 var8008a314 = 0x00060008;
u32 var8008a318 = 0x000a000c;
u32 var8008a31c = 0x000e0010;
u32 var8008a320 = 0x00010001;
u32 var8008a324 = 0x00010001;
u32 var8008a328 = 0x00010001;
u32 var8008a32c = 0x00010001;
u32 var8008a330 = 0x00000020;
u32 var8008a334 = 0x00020800;
u32 var8008a338 = 0x00087fff;
u32 var8008a33c = 0x01000200;
u32 var8008a340 = 0x00010000;
u32 var8008a344 = 0x00000000;
u32 var8008a348 = 0x00010000;
u32 var8008a34c = 0x00000000;
u32 var8008a350 = 0x00000001;
u32 var8008a354 = 0x00000000;
u32 var8008a358 = 0x00000001;
u32 var8008a35c = 0x00000000;
u32 var8008a360 = 0x00000000;
u32 var8008a364 = 0x00010000;
u32 var8008a368 = 0x00000000;
u32 var8008a36c = 0x00010000;
u32 var8008a370 = 0x00000000;
u32 var8008a374 = 0x00000001;
u32 var8008a378 = 0x00000000;
u32 var8008a37c = 0x00000001;
u32 var8008a380 = 0x20004000;
u32 var8008a384 = 0x60008000;
u32 var8008a388 = 0xa000c000;
u32 var8008a38c = 0xe000ffff;
u32 var8008a390 = 0x0c3966ad;
u32 var8008a394 = 0x0d46ffdf;
u32 var8008a398 = 0x0b396696;
u32 var8008a39c = 0x0e5fffd8;
u32 var8008a3a0 = 0x0a446669;
u32 var8008a3a4 = 0x0f83ffd0;
u32 var8008a3a8 = 0x095a6626;
u32 var8008a3ac = 0x10b4ffc8;
u32 var8008a3b0 = 0x087d65cd;
u32 var8008a3b4 = 0x11f0ffbf;
u32 var8008a3b8 = 0x07ab655e;
u32 var8008a3bc = 0x1338ffb6;
u32 var8008a3c0 = 0x06e464d9;
u32 var8008a3c4 = 0x148cffac;
u32 var8008a3c8 = 0x0628643f;
u32 var8008a3cc = 0x15ebffa1;
u32 var8008a3d0 = 0x0577638f;
u32 var8008a3d4 = 0x1756ff96;
u32 var8008a3d8 = 0x04d162cb;
u32 var8008a3dc = 0x18cbff8a;
u32 var8008a3e0 = 0x043561f3;
u32 var8008a3e4 = 0x1a4cff7e;
u32 var8008a3e8 = 0x03a46106;
u32 var8008a3ec = 0x1bd7ff71;
u32 var8008a3f0 = 0x031c6007;
u32 var8008a3f4 = 0x1d6cff64;
u32 var8008a3f8 = 0x029f5ef5;
u32 var8008a3fc = 0x1f0bff56;
u32 var8008a400 = 0x022a5dd0;
u32 var8008a404 = 0x20b3ff48;
u32 var8008a408 = 0x01be5c9a;
u32 var8008a40c = 0x2264ff3a;
u32 var8008a410 = 0x015b5b53;
u32 var8008a414 = 0x241eff2c;
u32 var8008a418 = 0x010159fc;
u32 var8008a41c = 0x25e0ff1e;
u32 var8008a420 = 0x00ae5896;
u32 var8008a424 = 0x27a9ff10;
u32 var8008a428 = 0x00635720;
u32 var8008a42c = 0x297aff02;
u32 var8008a430 = 0x001f559d;
u32 var8008a434 = 0x2b50fef4;
u32 var8008a438 = 0xffe2540d;
u32 var8008a43c = 0x2d2cfee8;
u32 var8008a440 = 0xffac5270;
u32 var8008a444 = 0x2f0dfedb;
u32 var8008a448 = 0xff7c50c7;
u32 var8008a44c = 0x30f3fed0;
u32 var8008a450 = 0xff534f14;
u32 var8008a454 = 0x32dcfec6;
u32 var8008a458 = 0xff2e4d57;
u32 var8008a45c = 0x34c8febd;
u32 var8008a460 = 0xff0f4b91;
u32 var8008a464 = 0x36b6feb6;
u32 var8008a468 = 0xfef549c2;
u32 var8008a46c = 0x38a5feb0;
u32 var8008a470 = 0xfedf47ed;
u32 var8008a474 = 0x3a95feac;
u32 var8008a478 = 0xfece4611;
u32 var8008a47c = 0x3c85feab;
u32 var8008a480 = 0xfec04430;
u32 var8008a484 = 0x3e74feac;
u32 var8008a488 = 0xfeb6424a;
u32 var8008a48c = 0x4060feaf;
u32 var8008a490 = 0xfeaf4060;
u32 var8008a494 = 0x424afeb6;
u32 var8008a498 = 0xfeac3e74;
u32 var8008a49c = 0x4430fec0;
u32 var8008a4a0 = 0xfeab3c85;
u32 var8008a4a4 = 0x4611fece;
u32 var8008a4a8 = 0xfeac3a95;
u32 var8008a4ac = 0x47edfedf;
u32 var8008a4b0 = 0xfeb038a5;
u32 var8008a4b4 = 0x49c2fef5;
u32 var8008a4b8 = 0xfeb636b6;
u32 var8008a4bc = 0x4b91ff0f;
u32 var8008a4c0 = 0xfebd34c8;
u32 var8008a4c4 = 0x4d57ff2e;
u32 var8008a4c8 = 0xfec632dc;
u32 var8008a4cc = 0x4f14ff53;
u32 var8008a4d0 = 0xfed030f3;
u32 var8008a4d4 = 0x50c7ff7c;
u32 var8008a4d8 = 0xfedb2f0d;
u32 var8008a4dc = 0x5270ffac;
u32 var8008a4e0 = 0xfee82d2c;
u32 var8008a4e4 = 0x540dffe2;
u32 var8008a4e8 = 0xfef42b50;
u32 var8008a4ec = 0x559d001f;
u32 var8008a4f0 = 0xff02297a;
u32 var8008a4f4 = 0x57200063;
u32 var8008a4f8 = 0xff1027a9;
u32 var8008a4fc = 0x589600ae;
u32 var8008a500 = 0xff1e25e0;
u32 var8008a504 = 0x59fc0101;
u32 var8008a508 = 0xff2c241e;
u32 var8008a50c = 0x5b53015b;
u32 var8008a510 = 0xff3a2264;
u32 var8008a514 = 0x5c9a01be;
u32 var8008a518 = 0xff4820b3;
u32 var8008a51c = 0x5dd0022a;
u32 var8008a520 = 0xff561f0b;
u32 var8008a524 = 0x5ef5029f;
u32 var8008a528 = 0xff641d6c;
u32 var8008a52c = 0x6007031c;
u32 var8008a530 = 0xff711bd7;
u32 var8008a534 = 0x610603a4;
u32 var8008a538 = 0xff7e1a4c;
u32 var8008a53c = 0x61f30435;
u32 var8008a540 = 0xff8a18cb;
u32 var8008a544 = 0x62cb04d1;
u32 var8008a548 = 0xff961756;
u32 var8008a54c = 0x638f0577;
u32 var8008a550 = 0xffa115eb;
u32 var8008a554 = 0x643f0628;
u32 var8008a558 = 0xffac148c;
u32 var8008a55c = 0x64d906e4;
u32 var8008a560 = 0xffb61338;
u32 var8008a564 = 0x655e07ab;
u32 var8008a568 = 0xffbf11f0;
u32 var8008a56c = 0x65cd087d;
u32 var8008a570 = 0xffc810b4;
u32 var8008a574 = 0x6626095a;
u32 var8008a578 = 0xffd00f83;
u32 var8008a57c = 0x66690a44;
u32 var8008a580 = 0xffd80e5f;
u32 var8008a584 = 0x66960b39;
u32 var8008a588 = 0xffdf0d46;
u32 var8008a58c = 0x66ad0c39;
u32 var8008a590 = 0xfec4fb14;
u32 var8008a594 = 0xf4faec84;
u32 var8008a598 = 0xe1c4d4dc;
u32 var8008a59c = 0xc5e4a268;
u32 var8008a5a0 = 0x8e3a78ae;
u32 var8008a5a4 = 0x61f84a50;
u32 var8008a5a8 = 0x31f21916;
u32 var8008a5ac = 0x80000000;
u32 var8008a5b0 = 0xffb2fd3a;
u32 var8008a5b4 = 0xf854f10a;
u32 var8008a5b8 = 0xe76cdb94;
u32 var8008a5bc = 0xcda0bdae;
u32 var8008a5c0 = 0xabec9880;
u32 var8008a5c4 = 0x839cdae8;
u32 var8008a5c8 = 0xac7c7c68;
u32 var8008a5cc = 0x4b201920;
u32 var8008a5d0 = 0xb504a57e;
u32 var8008a5d4 = 0x00016a09;
u32 var8008a5d8 = 0x0002d413;
u32 var8008a5dc = 0x0005a827;
u32 var8008a5e0 = 0x0000fff3;
u32 var8008a5e4 = 0x005dff38;
u32 var8008a5e8 = 0x037af736;
u32 var8008a5ec = 0x0b37c00e;
u32 var8008a5f0 = 0x7fff3ff2;
u32 var8008a5f4 = 0x0b3708ca;
u32 var8008a5f8 = 0x037a00c8;
u32 var8008a5fc = 0x005d000d;
u32 var8008a600 = 0x0000fff3;
u32 var8008a604 = 0x005dff38;
u32 var8008a608 = 0x037af736;
u32 var8008a60c = 0x0b37c00e;
u32 var8008a610 = 0x7fff3ff2;
u32 var8008a614 = 0x0b3708ca;
u32 var8008a618 = 0x037a00c8;
u32 var8008a61c = 0x005d000d;
u32 var8008a620 = 0x0000fff2;
u32 var8008a624 = 0x005fff1d;
u32 var8008a628 = 0x0369f697;
u32 var8008a62c = 0x0a2abce7;
u32 var8008a630 = 0x7feb3ccb;
u32 var8008a634 = 0x0c2b082b;
u32 var8008a638 = 0x038500af;
u32 var8008a63c = 0x005b000b;
u32 var8008a640 = 0x0000fff2;
u32 var8008a644 = 0x005fff1d;
u32 var8008a648 = 0x0369f697;
u32 var8008a64c = 0x0a2abce7;
u32 var8008a650 = 0x7feb3ccb;
u32 var8008a654 = 0x0c2b082b;
u32 var8008a658 = 0x038500af;
u32 var8008a65c = 0x005b000b;
u32 var8008a660 = 0x0000fff1;
u32 var8008a664 = 0x0061ff02;
u32 var8008a668 = 0x0354f5f9;
u32 var8008a66c = 0x0905b9c4;
u32 var8008a670 = 0x7fb039a4;
u32 var8008a674 = 0x0d08078c;
u32 var8008a678 = 0x038c0098;
u32 var8008a67c = 0x0058000a;
u32 var8008a680 = 0x0000fff1;
u32 var8008a684 = 0x0061ff02;
u32 var8008a688 = 0x0354f5f9;
u32 var8008a68c = 0x0905b9c4;
u32 var8008a690 = 0x7fb039a4;
u32 var8008a694 = 0x0d08078c;
u32 var8008a698 = 0x038c0098;
u32 var8008a69c = 0x0058000a;
u32 var8008a6a0 = 0x0000ffef;
u32 var8008a6a4 = 0x0062fee6;
u32 var8008a6a8 = 0x033bf55c;
u32 var8008a6ac = 0x07c8b6a4;
u32 var8008a6b0 = 0x7f4d367e;
u32 var8008a6b4 = 0x0dce06ee;
u32 var8008a6b8 = 0x038f0080;
u32 var8008a6bc = 0x00560009;
u32 var8008a6c0 = 0x0000ffef;
u32 var8008a6c4 = 0x0062fee6;
u32 var8008a6c8 = 0x033bf55c;
u32 var8008a6cc = 0x07c8b6a4;
u32 var8008a6d0 = 0x7f4d367e;
u32 var8008a6d4 = 0x0dce06ee;
u32 var8008a6d8 = 0x038f0080;
u32 var8008a6dc = 0x00560009;
u32 var8008a6e0 = 0x0000ffee;
u32 var8008a6e4 = 0x0063feca;
u32 var8008a6e8 = 0x031cf4c3;
u32 var8008a6ec = 0x0671b38c;
u32 var8008a6f0 = 0x7ec2335d;
u32 var8008a6f4 = 0x0e7c0652;
u32 var8008a6f8 = 0x038e006b;
u32 var8008a6fc = 0x00530008;
u32 var8008a700 = 0x0000ffee;
u32 var8008a704 = 0x0063feca;
u32 var8008a708 = 0x031cf4c3;
u32 var8008a70c = 0x0671b38c;
u32 var8008a710 = 0x7ec2335d;
u32 var8008a714 = 0x0e7c0652;
u32 var8008a718 = 0x038e006b;
u32 var8008a71c = 0x00530008;
u32 var8008a720 = 0x0000ffec;
u32 var8008a724 = 0x0064feac;
u32 var8008a728 = 0x02f7f42c;
u32 var8008a72c = 0x0502b07c;
u32 var8008a730 = 0x7e123041;
u32 var8008a734 = 0x0f1405b7;
u32 var8008a738 = 0x038a0056;
u32 var8008a73c = 0x00500007;
u32 var8008a740 = 0x0000ffec;
u32 var8008a744 = 0x0064feac;
u32 var8008a748 = 0x02f7f42c;
u32 var8008a74c = 0x0502b07c;
u32 var8008a750 = 0x7e123041;
u32 var8008a754 = 0x0f1405b7;
u32 var8008a758 = 0x038a0056;
u32 var8008a75c = 0x00500007;
u32 var8008a760 = 0x0000ffeb;
u32 var8008a764 = 0x0064fe8e;
u32 var8008a768 = 0x02cef399;
u32 var8008a76c = 0x037aad75;
u32 var8008a770 = 0x7d3a2d2c;
u32 var8008a774 = 0x0f970520;
u32 var8008a778 = 0x03820043;
u32 var8008a77c = 0x004d0007;
u32 var8008a780 = 0x0000ffeb;
u32 var8008a784 = 0x0064fe8e;
u32 var8008a788 = 0x02cef399;
u32 var8008a78c = 0x037aad75;
u32 var8008a790 = 0x7d3a2d2c;
u32 var8008a794 = 0x0f970520;
u32 var8008a798 = 0x03820043;
u32 var8008a79c = 0x004d0007;
u32 var8008a7a0 = 0xffffffe9;
u32 var8008a7a4 = 0x0063fe6f;
u32 var8008a7a8 = 0x029ef30b;
u32 var8008a7ac = 0x01d8aa7b;
u32 var8008a7b0 = 0x7c3d2a1f;
u32 var8008a7b4 = 0x1004048b;
u32 var8008a7b8 = 0x03770030;
u32 var8008a7bc = 0x004a0006;
u32 var8008a7c0 = 0xffffffe9;
u32 var8008a7c4 = 0x0063fe6f;
u32 var8008a7c8 = 0x029ef30b;
u32 var8008a7cc = 0x01d8aa7b;
u32 var8008a7d0 = 0x7c3d2a1f;
u32 var8008a7d4 = 0x1004048b;
u32 var8008a7d8 = 0x03770030;
u32 var8008a7dc = 0x004a0006;
u32 var8008a7e0 = 0xffffffe7;
u32 var8008a7e4 = 0x0062fe4f;
u32 var8008a7e8 = 0x0269f282;
u32 var8008a7ec = 0x001fa78d;
u32 var8008a7f0 = 0x7b1a271c;
u32 var8008a7f4 = 0x105d03f9;
u32 var8008a7f8 = 0x036a001f;
u32 var8008a7fc = 0x00460006;
u32 var8008a800 = 0xffffffe7;
u32 var8008a804 = 0x0062fe4f;
u32 var8008a808 = 0x0269f282;
u32 var8008a80c = 0x001fa78d;
u32 var8008a810 = 0x7b1a271c;
u32 var8008a814 = 0x105d03f9;
u32 var8008a818 = 0x036a001f;
u32 var8008a81c = 0x00460006;
u32 var8008a820 = 0xffffffe4;
u32 var8008a824 = 0x0061fe2f;
u32 var8008a828 = 0x022ff1ff;
u32 var8008a82c = 0xfe4ca4af;
u32 var8008a830 = 0x79d32425;
u32 var8008a834 = 0x10a2036c;
u32 var8008a838 = 0x03590010;
u32 var8008a83c = 0x00430005;
u32 var8008a840 = 0xffffffe4;
u32 var8008a844 = 0x0061fe2f;
u32 var8008a848 = 0x022ff1ff;
u32 var8008a84c = 0xfe4ca4af;
u32 var8008a850 = 0x79d32425;
u32 var8008a854 = 0x10a2036c;
u32 var8008a858 = 0x03590010;
u32 var8008a85c = 0x00430005;
u32 var8008a860 = 0xffffffe2;
u32 var8008a864 = 0x005efe10;
u32 var8008a868 = 0x01eef184;
u32 var8008a86c = 0xfc61a1e1;
u32 var8008a870 = 0x78692139;
u32 var8008a874 = 0x10d302e3;
u32 var8008a878 = 0x03460001;
u32 var8008a87c = 0x00400004;
u32 var8008a880 = 0xffffffe2;
u32 var8008a884 = 0x005efe10;
u32 var8008a888 = 0x01eef184;
u32 var8008a88c = 0xfc61a1e1;
u32 var8008a890 = 0x78692139;
u32 var8008a894 = 0x10d302e3;
u32 var8008a898 = 0x03460001;
u32 var8008a89c = 0x00400004;
u32 var8008a8a0 = 0xffffffe0;
u32 var8008a8a4 = 0x005bfdf0;
u32 var8008a8a8 = 0x01a8f111;
u32 var8008a8ac = 0xfa5f9f27;
u32 var8008a8b0 = 0x76db1e5c;
u32 var8008a8b4 = 0x10f2025e;
u32 var8008a8b8 = 0x0331fff3;
u32 var8008a8bc = 0x003d0004;
u32 var8008a8c0 = 0xffffffe0;
u32 var8008a8c4 = 0x005bfdf0;
u32 var8008a8c8 = 0x01a8f111;
u32 var8008a8cc = 0xfa5f9f27;
u32 var8008a8d0 = 0x76db1e5c;
u32 var8008a8d4 = 0x10f2025e;
u32 var8008a8d8 = 0x0331fff3;
u32 var8008a8dc = 0x003d0004;
u32 var8008a8e0 = 0xffffffde;
u32 var8008a8e4 = 0x0057fdd0;
u32 var8008a8e8 = 0x015bf0a7;
u32 var8008a8ec = 0xf8459c80;
u32 var8008a8f0 = 0x752c1b8e;
u32 var8008a8f4 = 0x110001de;
u32 var8008a8f8 = 0x0319ffe7;
u32 var8008a8fc = 0x003a0003;
u32 var8008a900 = 0xffffffde;
u32 var8008a904 = 0x0057fdd0;
u32 var8008a908 = 0x015bf0a7;
u32 var8008a90c = 0xf8459c80;
u32 var8008a910 = 0x752c1b8e;
u32 var8008a914 = 0x110001de;
u32 var8008a918 = 0x0319ffe7;
u32 var8008a91c = 0x003a0003;
u32 var8008a920 = 0xfffeffdb;
u32 var8008a924 = 0x0053fdb0;
u32 var8008a928 = 0x0108f046;
u32 var8008a92c = 0xf61399ee;
u32 var8008a930 = 0x735c18d1;
u32 var8008a934 = 0x10fd0163;
u32 var8008a938 = 0x0300ffdc;
u32 var8008a93c = 0x00370003;
u32 var8008a940 = 0xfffeffdb;
u32 var8008a944 = 0x0053fdb0;
u32 var8008a948 = 0x0108f046;
u32 var8008a94c = 0xf61399ee;
u32 var8008a950 = 0x735c18d1;
u32 var8008a954 = 0x10fd0163;
u32 var8008a958 = 0x0300ffdc;
u32 var8008a95c = 0x00370003;
u32 var8008a960 = 0xfffeffd8;
u32 var8008a964 = 0x004dfd90;
u32 var8008a968 = 0x00b0eff0;
u32 var8008a96c = 0xf3cc9775;
u32 var8008a970 = 0x716c1624;
u32 var8008a974 = 0x10ea00ee;
u32 var8008a978 = 0x02e5ffd2;
u32 var8008a97c = 0x00330003;
u32 var8008a980 = 0xfffeffd8;
u32 var8008a984 = 0x004dfd90;
u32 var8008a988 = 0x00b0eff0;
u32 var8008a98c = 0xf3cc9775;
u32 var8008a990 = 0x716c1624;
u32 var8008a994 = 0x10ea00ee;
u32 var8008a998 = 0x02e5ffd2;
u32 var8008a99c = 0x00330003;
u32 var8008a9a0 = 0xfffeffd6;
u32 var8008a9a4 = 0x0047fd72;
u32 var8008a9a8 = 0x0051efa6;
u32 var8008a9ac = 0xf16f9514;
u32 var8008a9b0 = 0x6f5e138a;
u32 var8008a9b4 = 0x10c8007e;
u32 var8008a9b8 = 0x02caffc9;
u32 var8008a9bc = 0x00300003;
u32 var8008a9c0 = 0xfffeffd6;
u32 var8008a9c4 = 0x0047fd72;
u32 var8008a9c8 = 0x0051efa6;
u32 var8008a9cc = 0xf16f9514;
u32 var8008a9d0 = 0x6f5e138a;
u32 var8008a9d4 = 0x10c8007e;
u32 var8008a9d8 = 0x02caffc9;
u32 var8008a9dc = 0x00300003;
u32 var8008a9e0 = 0xfffeffd3;
u32 var8008a9e4 = 0x0040fd54;
u32 var8008a9e8 = 0xffecef68;
u32 var8008a9ec = 0xeefc92cd;
u32 var8008a9f0 = 0x6d331104;
u32 var8008a9f4 = 0x10980014;
u32 var8008a9f8 = 0x02acffc0;
u32 var8008a9fc = 0x002d0002;
u32 var8008aa00 = 0xfffeffd3;
u32 var8008aa04 = 0x0040fd54;
u32 var8008aa08 = 0xffecef68;
u32 var8008aa0c = 0xeefc92cd;
u32 var8008aa10 = 0x6d331104;
u32 var8008aa14 = 0x10980014;
u32 var8008aa18 = 0x02acffc0;
u32 var8008aa1c = 0x002d0002;
u32 var8008aa20 = 0x0030ffc9;
u32 var8008aa24 = 0x02ca007e;
u32 var8008aa28 = 0x10c8138a;
u32 var8008aa2c = 0x6f5e9514;
u32 var8008aa30 = 0xf16fefa6;
u32 var8008aa34 = 0x0051fd72;
u32 var8008aa38 = 0x0047ffd6;
u32 var8008aa3c = 0xfffe0003;
u32 var8008aa40 = 0x0030ffc9;
u32 var8008aa44 = 0x02ca007e;
u32 var8008aa48 = 0x10c8138a;
u32 var8008aa4c = 0x6f5e9514;
u32 var8008aa50 = 0xf16fefa6;
u32 var8008aa54 = 0x0051fd72;
u32 var8008aa58 = 0x0047ffd6;
u32 var8008aa5c = 0xfffe0003;
u32 var8008aa60 = 0x0033ffd2;
u32 var8008aa64 = 0x02e500ee;
u32 var8008aa68 = 0x10ea1624;
u32 var8008aa6c = 0x716c9775;
u32 var8008aa70 = 0xf3cceff0;
u32 var8008aa74 = 0x00b0fd90;
u32 var8008aa78 = 0x004dffd8;
u32 var8008aa7c = 0xfffe0003;
u32 var8008aa80 = 0x0033ffd2;
u32 var8008aa84 = 0x02e500ee;
u32 var8008aa88 = 0x10ea1624;
u32 var8008aa8c = 0x716c9775;
u32 var8008aa90 = 0xf3cceff0;
u32 var8008aa94 = 0x00b0fd90;
u32 var8008aa98 = 0x004dffd8;
u32 var8008aa9c = 0xfffe0003;
u32 var8008aaa0 = 0x0037ffdc;
u32 var8008aaa4 = 0x03000163;
u32 var8008aaa8 = 0x10fd18d1;
u32 var8008aaac = 0x735c99ee;
u32 var8008aab0 = 0xf613f046;
u32 var8008aab4 = 0x0108fdb0;
u32 var8008aab8 = 0x0053ffdb;
u32 var8008aabc = 0xfffe0003;
u32 var8008aac0 = 0x0037ffdc;
u32 var8008aac4 = 0x03000163;
u32 var8008aac8 = 0x10fd18d1;
u32 var8008aacc = 0x735c99ee;
u32 var8008aad0 = 0xf613f046;
u32 var8008aad4 = 0x0108fdb0;
u32 var8008aad8 = 0x0053ffdb;
u32 var8008aadc = 0xfffe0003;
u32 var8008aae0 = 0x003affe7;
u32 var8008aae4 = 0x031901de;
u32 var8008aae8 = 0x11001b8e;
u32 var8008aaec = 0x752c9c80;
u32 var8008aaf0 = 0xf845f0a7;
u32 var8008aaf4 = 0x015bfdd0;
u32 var8008aaf8 = 0x0057ffde;
u32 var8008aafc = 0xffff0003;
u32 var8008ab00 = 0x003affe7;
u32 var8008ab04 = 0x031901de;
u32 var8008ab08 = 0x11001b8e;
u32 var8008ab0c = 0x752c9c80;
u32 var8008ab10 = 0xf845f0a7;
u32 var8008ab14 = 0x015bfdd0;
u32 var8008ab18 = 0x0057ffde;
u32 var8008ab1c = 0xffff0004;
u32 var8008ab20 = 0x003dfff3;
u32 var8008ab24 = 0x0331025e;
u32 var8008ab28 = 0x10f21e5c;
u32 var8008ab2c = 0x76db9f27;
u32 var8008ab30 = 0xfa5ff111;
u32 var8008ab34 = 0x01a8fdf0;
u32 var8008ab38 = 0x005bffe0;
u32 var8008ab3c = 0xffff0004;
u32 var8008ab40 = 0x003dfff3;
u32 var8008ab44 = 0x0331025e;
u32 var8008ab48 = 0x10f21e5c;
u32 var8008ab4c = 0x76db9f27;
u32 var8008ab50 = 0xfa5ff111;
u32 var8008ab54 = 0x01a8fdf0;
u32 var8008ab58 = 0x005bffe0;
u32 var8008ab5c = 0xffff0004;
u32 var8008ab60 = 0x00400001;
u32 var8008ab64 = 0x034602e3;
u32 var8008ab68 = 0x10d32139;
u32 var8008ab6c = 0x7869a1e1;
u32 var8008ab70 = 0xfc61f184;
u32 var8008ab74 = 0x01eefe10;
u32 var8008ab78 = 0x005effe2;
u32 var8008ab7c = 0xffff0004;
u32 var8008ab80 = 0x00400001;
u32 var8008ab84 = 0x034602e3;
u32 var8008ab88 = 0x10d32139;
u32 var8008ab8c = 0x7869a1e1;
u32 var8008ab90 = 0xfc61f184;
u32 var8008ab94 = 0x01eefe10;
u32 var8008ab98 = 0x005effe2;
u32 var8008ab9c = 0xffff0005;
u32 var8008aba0 = 0x00430010;
u32 var8008aba4 = 0x0359036c;
u32 var8008aba8 = 0x10a22425;
u32 var8008abac = 0x79d3a4af;
u32 var8008abb0 = 0xfe4cf1ff;
u32 var8008abb4 = 0x022ffe2f;
u32 var8008abb8 = 0x0061ffe4;
u32 var8008abbc = 0xffff0005;
u32 var8008abc0 = 0x00430010;
u32 var8008abc4 = 0x0359036c;
u32 var8008abc8 = 0x10a22425;
u32 var8008abcc = 0x79d3a4af;
u32 var8008abd0 = 0xfe4cf1ff;
u32 var8008abd4 = 0x022ffe2f;
u32 var8008abd8 = 0x0061ffe4;
u32 var8008abdc = 0xffff0006;
u32 var8008abe0 = 0x0046001f;
u32 var8008abe4 = 0x036a03f9;
u32 var8008abe8 = 0x105d271c;
u32 var8008abec = 0x7b1aa78d;
u32 var8008abf0 = 0x001ff282;
u32 var8008abf4 = 0x0269fe4f;
u32 var8008abf8 = 0x0062ffe7;
u32 var8008abfc = 0xffff0006;
u32 var8008ac00 = 0x0046001f;
u32 var8008ac04 = 0x036a03f9;
u32 var8008ac08 = 0x105d271c;
u32 var8008ac0c = 0x7b1aa78d;
u32 var8008ac10 = 0x001ff282;
u32 var8008ac14 = 0x0269fe4f;
u32 var8008ac18 = 0x0062ffe7;
u32 var8008ac1c = 0xffff0006;
u32 var8008ac20 = 0x004a0030;
u32 var8008ac24 = 0x0377048b;
u32 var8008ac28 = 0x10042a1f;
u32 var8008ac2c = 0x7c3daa7b;
u32 var8008ac30 = 0x01d8f30b;
u32 var8008ac34 = 0x029efe6f;
u32 var8008ac38 = 0x0063ffe9;
u32 var8008ac3c = 0xffff0006;
u32 var8008ac40 = 0x004a0030;
u32 var8008ac44 = 0x0377048b;
u32 var8008ac48 = 0x10042a1f;
u32 var8008ac4c = 0x7c3daa7b;
u32 var8008ac50 = 0x01d8f30b;
u32 var8008ac54 = 0x029efe6f;
u32 var8008ac58 = 0x0063ffe9;
u32 var8008ac5c = 0xffff0007;
u32 var8008ac60 = 0x004d0043;
u32 var8008ac64 = 0x03820520;
u32 var8008ac68 = 0x0f972d2c;
u32 var8008ac6c = 0x7d3aad75;
u32 var8008ac70 = 0x037af399;
u32 var8008ac74 = 0x02cefe8e;
u32 var8008ac78 = 0x0064ffeb;
u32 var8008ac7c = 0x00000007;
u32 var8008ac80 = 0x004d0043;
u32 var8008ac84 = 0x03820520;
u32 var8008ac88 = 0x0f972d2c;
u32 var8008ac8c = 0x7d3aad75;
u32 var8008ac90 = 0x037af399;
u32 var8008ac94 = 0x02cefe8e;
u32 var8008ac98 = 0x0064ffeb;
u32 var8008ac9c = 0x00000007;
u32 var8008aca0 = 0x00500056;
u32 var8008aca4 = 0x038a05b7;
u32 var8008aca8 = 0x0f143041;
u32 var8008acac = 0x7e12b07c;
u32 var8008acb0 = 0x0502f42c;
u32 var8008acb4 = 0x02f7feac;
u32 var8008acb8 = 0x0064ffec;
u32 var8008acbc = 0x00000007;
u32 var8008acc0 = 0x00500056;
u32 var8008acc4 = 0x038a05b7;
u32 var8008acc8 = 0x0f143041;
u32 var8008accc = 0x7e12b07c;
u32 var8008acd0 = 0x0502f42c;
u32 var8008acd4 = 0x02f7feac;
u32 var8008acd8 = 0x0064ffec;
u32 var8008acdc = 0x00000008;
u32 var8008ace0 = 0x0053006b;
u32 var8008ace4 = 0x038e0652;
u32 var8008ace8 = 0x0e7c335d;
u32 var8008acec = 0x7ec2b38c;
u32 var8008acf0 = 0x0671f4c3;
u32 var8008acf4 = 0x031cfeca;
u32 var8008acf8 = 0x0063ffee;
u32 var8008acfc = 0x00000008;
u32 var8008ad00 = 0x0053006b;
u32 var8008ad04 = 0x038e0652;
u32 var8008ad08 = 0x0e7c335d;
u32 var8008ad0c = 0x7ec2b38c;
u32 var8008ad10 = 0x0671f4c3;
u32 var8008ad14 = 0x031cfeca;
u32 var8008ad18 = 0x0063ffee;
u32 var8008ad1c = 0x00000009;
u32 var8008ad20 = 0x00560080;
u32 var8008ad24 = 0x038f06ee;
u32 var8008ad28 = 0x0dce367e;
u32 var8008ad2c = 0x7f4db6a4;
u32 var8008ad30 = 0x07c8f55c;
u32 var8008ad34 = 0x033bfee6;
u32 var8008ad38 = 0x0062ffef;
u32 var8008ad3c = 0x00000009;
u32 var8008ad40 = 0x00560080;
u32 var8008ad44 = 0x038f06ee;
u32 var8008ad48 = 0x0dce367e;
u32 var8008ad4c = 0x7f4db6a4;
u32 var8008ad50 = 0x07c8f55c;
u32 var8008ad54 = 0x033bfee6;
u32 var8008ad58 = 0x0062ffef;
u32 var8008ad5c = 0x0000000a;
u32 var8008ad60 = 0x00580098;
u32 var8008ad64 = 0x038c078c;
u32 var8008ad68 = 0x0d0839a4;
u32 var8008ad6c = 0x7fb0b9c4;
u32 var8008ad70 = 0x0905f5f9;
u32 var8008ad74 = 0x0354ff02;
u32 var8008ad78 = 0x0061fff1;
u32 var8008ad7c = 0x0000000a;
u32 var8008ad80 = 0x00580098;
u32 var8008ad84 = 0x038c078c;
u32 var8008ad88 = 0x0d0839a4;
u32 var8008ad8c = 0x7fb0b9c4;
u32 var8008ad90 = 0x0905f5f9;
u32 var8008ad94 = 0x0354ff02;
u32 var8008ad98 = 0x0061fff1;
u32 var8008ad9c = 0x0000000b;
u32 var8008ada0 = 0x005b00af;
u32 var8008ada4 = 0x0385082b;
u32 var8008ada8 = 0x0c2b3ccb;
u32 var8008adac = 0x7febbce7;
u32 var8008adb0 = 0x0a2af697;
u32 var8008adb4 = 0x0369ff1d;
u32 var8008adb8 = 0x005ffff2;
u32 var8008adbc = 0x0000000b;
u32 var8008adc0 = 0x005b00af;
u32 var8008adc4 = 0x0385082b;
u32 var8008adc8 = 0x0c2b3ccb;
u32 var8008adcc = 0x7febbce7;
u32 var8008add0 = 0x0a2af697;
u32 var8008add4 = 0x0369ff1d;
u32 var8008add8 = 0x005ffff2;
u32 var8008addc = 0x0000000d;
u32 var8008ade0 = 0x005d00c8;
u32 var8008ade4 = 0x037a08ca;
u32 var8008ade8 = 0x0b373ff2;
u32 var8008adec = 0x7fffc00e;
u32 var8008adf0 = 0x0b37f736;
u32 var8008adf4 = 0x037aff38;
u32 var8008adf8 = 0x005dfff3;
u32 var8008adfc = 0x0000000d;
u32 var8008ae00 = 0x005d00c8;
u32 var8008ae04 = 0x037a08ca;
u32 var8008ae08 = 0x0b373ff2;
u32 var8008ae0c = 0x7fffc00e;
u32 var8008ae10 = 0x0b37f736;
u32 var8008ae14 = 0x037aff38;
u32 var8008ae18 = 0x005dfff3;
u32 var8008ae1c = 0x00000000;
