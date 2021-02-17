#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_000000.h"
#include "game/prop.h"
#include "game/game_015470.h"
#include "game/hudmsg.h"
#include "lib/lib_0c000.h"
#include "lib/main.h"
#include "lib/lib_3e730.h"
#include "gvars/gvars.h"
#include "stagesetup.h"
#include "data.h"
#include "types.h"

u32 var8005ef10 = 0x47800000;
u32 var8005ef14 = 0x47800000;
u32 var8005ef18 = 0x00000000;
u32 var8005ef1c = 0x00000000;
u32 var8005ef20 = 0xfe000000;
u32 var8005ef24 = 0x00000000;
u32 var8005ef28 = 0x00000000;
u32 var8005ef2c = 0x00000000;
s32 g_NumGlobalAilists = 0;
s32 g_NumLvAilists = 0;
u32 var8005ef38 = 0x00000000;
u32 var8005ef3c = 0x00000000;
u32 var8005ef40 = 0x00040800;
u32 var8005ef44 = 0x00000000;
u32 var8005ef48 = 0x0c100000;
u32 var8005ef4c = 0x00000000;
u32 var8005ef50 = 0x00001400;
u32 var8005ef54 = 0x0018001c;
u32 var8005ef58 = 0x00000000;
u32 var8005ef5c = 0x70019574;
u32 var8005ef60 = 0x700190bc;
u32 var8005ef64 = 0x70018a28;
u32 var8005ef68 = 0x70019010;
u32 var8005ef6c = 0x7001954c;
u32 var8005ef70 = 0x70019554;
u32 var8005ef74 = 0x700194e0;
u32 var8005ef78 = 0x700194a4;
u32 var8005ef7c = 0x00000000;
u32 var8005ef80 = 0x70019c64;
u32 var8005ef84 = 0x70019c70;
u32 var8005ef88 = 0x70019c88;
u32 var8005ef8c = 0x70019cac;
u32 var8005ef90 = 0xff08ffff;
u32 var8005ef94 = 0xffffffff;
u32 var8005ef98 = 0x0c22ff44;
u32 var8005ef9c = 0x20ffffff;
u32 var8005efa0 = 0xffff04ff;
u32 var8005efa4 = 0xffffff00;
u32 var8005efa8 = 0x14000000;
u32 var8005efac = 0x00000000;
u32 var8005efb0 = 0x00000000;
u32 var8005efb4 = 0x00000000;
u32 var8005efb8 = 0x3f800000;
bool var8005efbc = false;
u32 var8005efc0 = 0x00000000;
void *var8005efc4 = NULL; // pointer to a function
void *var8005efc8 = NULL; // pointer to a function
u32 var8005efcc = 0x00000000;
u32 var8005efd0 = 0x00000000;
u32 var8005efd4 = 0x00000000;
u32 var8005efd8 = 0x00000000;
u32 var8005efdc = 0x00000001;
u32 var8005efe0 = 0x00000000;
u32 var8005efe4 = 0x00000000;
u32 var8005efe8 = 0x00000000;
u32 var8005efec = 0x00000000;
u32 var8005eff0 = 0x00000000;
u32 var8005eff4 = 0x00000000;
u32 var8005eff8 = 0xffffffff;
u32 var8005effc = 0x00000000;
u32 var8005f000 = 0x00000000;
u32 var8005f004 = 0x00000000;
s16 g_NumAnimations = 0x00000000;
struct animheader *g_Anims = NULL;
u32 var8005f010 = 0x00000000;
u32 var8005f014 = 0x00000000;
u32 var8005f018 = 0x000000b0;
u32 var8005f01c = 0x00000260;
u32 var8005f020 = 0x00000000;
u32 var8005f024 = 0x00000000;
u32 var8005f028 = 0x00000000;
u32 var8005f02c = 0x00000000;
u32 var8005f030 = 0x00000000;
u32 var8005f034 = 0x00000000;
u32 var8005f038 = 0x00000000;
u32 var8005f03c = 0x00000000;
u16 *var8005f040 = NULL;
u16 *var8005f044 = NULL;
u32 var8005f048 = 0x00000000;
u32 var8005f04c = 0x00000000;
u32 var8005f050 = 0x00000000;
u32 var8005f054 = 0x00000000;
u32 var8005f058 = 0x00000001;
u32 var8005f05c = 0x00000002;
u32 var8005f060 = 0x00000000;
u32 var8005f064 = 0x00000000;
u32 var8005f068 = 0x00000000;
u32 var8005f06c = 0x00001000;
u32 var8005f070 = 0x00000000;
u32 var8005f074 = 0x00000800;
u32 var8005f078 = (u32) &var8009a970;
u32 var8005f07c = 0x00000400;
u32 var8005f080 = 0x00000000;
u32 var8005f084 = 0x00000000;
u32 var8005f088 = 0x00000000;
u32 var8005f08c = 0x00000000;
u32 var8005f090 = 0x00000000;
u32 var8005f094 = 0x00000000;
u32 var8005f098 = 0x00000000;
u32 var8005f09c = 0x00000000;
u32 var8005f0a0 = 0x00000000;
u32 var8005f0a4 = 0x00000000;
u32 var8005f0a8 = 0x00000000;
u32 var8005f0ac = 0x00000000;
u32 var8005f0b0 = 0x00000000;
u32 var8005f0b4 = 0x00000000;
u32 var8005f0b8 = 0x00000001;
u32 var8005f0bc = 0x00000002;
u32 var8005f0c0 = 0x00000000;
u32 var8005f0c4 = 0x00000000;
u32 var8005f0c8 = 0x00000000;
u32 var8005f0cc = 0x00001000;
u32 var8005f0d0 = 0x00000000;
u32 var8005f0d4 = 0x00000800;
u32 var8005f0d8 = (u32) &var8009a970;
u32 var8005f0dc = 0x00000400;
u32 var8005f0e0 = 0x00000000;
u32 var8005f0e4 = 0x00000000;
u32 var8005f0e8 = 0x00000000;
u32 var8005f0ec = 0x00000000;
u32 var8005f0f0 = 0x00000000;
u32 var8005f0f4 = 0x00000000;
u32 var8005f0f8 = 0x00000000;
u32 var8005f0fc = 0x00000000;
u32 var8005f100 = 0x00000000;
u32 var8005f104 = 0x00000000;
u32 var8005f108 = (u32) &var8005f048;
u32 var8005f10c = 0x00000000;
u32 var8005f110 = 0x00000000;
u32 var8005f114 = 0x00000000;
u32 var8005f118 = 0x00000000;
u32 var8005f11c = 0x00000000;
u32 var8005f120 = 0x00000000;
u32 var8005f124 = 0x00000000;
u32 var8005f128 = 0x00000000;
u32 var8005f12c = (u32) &var8009c2d0;
u32 var8005f130 = 0x00000000;
u32 var8005f134 = 0x00000000;
u32 var8005f138 = 0x00000000;
u32 var8005f13c = 0x00000000;
u32 var8005f140 = 0x00000000;
u32 var8005f144 = 0x00000000;
u32 var8005f148 = 0x00000000;
u32 var8005f14c = 0x00000000;
u32 var8005f150 = 0x00000000;
u32 var8005f154 = 0x00002710;
u32 var8005f158 = 0x00004e20;
u32 var8005f15c = 0x00007530;
u32 var8005f160 = 0x00009c40;
u32 var8005f164 = 0x0000c350;
u32 var8005f168 = 0x0000ea60;
u32 var8005f16c = 0x00011170;
u32 var8005f170 = 0x00013880;
u32 var8005f174 = 0x00015f90;
u32 var8005f178 = 0x000186a0;
u32 var8005f17c = 0x0001adb0;
u32 var8005f180 = 0x0001adb0;
u32 var8005f184 = 0x0001d4c0;
u32 var8005f188 = 0x0001fbd0;
u32 var8005f18c = 0x000222e0;
u32 var8005f190 = 0x000249f0;
u32 var8005f194 = 0x00027100;
u32 var8005f198 = 0x00029810;
u32 var8005f19c = 0x0002e630;
u32 var8005f1a0 = 0x00030d40;
u32 var8005f1a4 = 0x00035b60;
u32 var8005f1a8 = 0x00038270;
u32 var8005f1ac = 0x0003d090;
u32 var8005f1b0 = 0x00041eb0;
u32 var8005f1b4 = 0x00046cd0;
u32 var8005f1b8 = 0x0004baf0;
u32 var8005f1bc = 0x00050910;
u32 var8005f1c0 = 0x00055730;
u32 var8005f1c4 = 0x0005cc60;
u32 var8005f1c8 = 0x00064190;
u32 var8005f1cc = 0x0006b6c0;
u32 var8005f1d0 = 0x00072bf0;
u32 var8005f1d4 = 0x0007a120;
u32 var8005f1d8 = 0x00083d60;
u32 var8005f1dc = 0x0008d9a0;
u32 var8005f1e0 = 0x000975e0;
u32 var8005f1e4 = 0x000a1220;
u32 var8005f1e8 = 0x000ad570;
u32 var8005f1ec = 0x000b98c0;
u32 var8005f1f0 = 0x000c8320;
u32 var8005f1f4 = 0x000d6d80;
u32 var8005f1f8 = 0x000e57e0;
u32 var8005f1fc = 0x000f4240;
u32 var8005f200 = 0x000f4240;
u32 var8005f204 = 0x0010c8e0;
u32 var8005f208 = 0x00124f80;
u32 var8005f20c = 0x0013d620;
u32 var8005f210 = 0x00155cc0;
u32 var8005f214 = 0x0016e360;
u32 var8005f218 = 0x00186a00;
u32 var8005f21c = 0x0019f0a0;
u32 var8005f220 = 0x001b7740;
u32 var8005f224 = 0x001e8480;
u32 var8005f228 = 0x00200b20;
u32 var8005f22c = 0x00231860;
u32 var8005f230 = 0x00249f00;
u32 var8005f234 = 0x0027ac40;
u32 var8005f238 = 0x002ab980;
u32 var8005f23c = 0x002dc6c0;
u32 var8005f240 = 0x0030d400;
u32 var8005f244 = 0x003567e0;
u32 var8005f248 = 0x00387520;
u32 var8005f24c = 0x003d0900;
u32 var8005f250 = 0x00419ce0;
u32 var8005f254 = 0x004630c0;
u32 var8005f258 = 0x004ac4a0;
u32 var8005f25c = 0x0050df20;
u32 var8005f260 = 0x0056f9a0;
u32 var8005f264 = 0x005d1420;
u32 var8005f268 = 0x00632ea0;
u32 var8005f26c = 0x006acfc0;
u32 var8005f270 = 0x007270e0;
u32 var8005f274 = 0x007b98a0;
u32 var8005f278 = 0x008339c0;
u32 var8005f27c = 0x008de820;
u32 var8005f280 = 0x00970fe0;
u32 var8005f284 = 0x00989680;
u32 var8005f288 = 0x00a7d8c0;
u32 var8005f28c = 0x00b71b00;
u32 var8005f290 = 0x00c65d40;
u32 var8005f294 = 0x00d59f80;
u32 var8005f298 = 0x00e4e1c0;
u32 var8005f29c = 0x00f42400;
u32 var8005f2a0 = 0x01036640;
u32 var8005f2a4 = 0x0112a880;
u32 var8005f2a8 = 0x0121eac0;
u32 var8005f2ac = 0x01406f40;
u32 var8005f2b0 = 0x014fb180;
u32 var8005f2b4 = 0x016e3600;
u32 var8005f2b8 = 0x018cba80;
u32 var8005f2bc = 0x01ab3f00;
u32 var8005f2c0 = 0x01c9c380;
u32 var8005f2c4 = 0x01e84800;
u32 var8005f2c8 = 0x0206cc80;
u32 var8005f2cc = 0x02349340;
u32 var8005f2d0 = 0x025317c0;
u32 var8005f2d4 = 0x0280de80;
u32 var8005f2d8 = 0x02aea540;
u32 var8005f2dc = 0x02ebae40;
u32 var8005f2e0 = 0x02faf080;
u32 var8005f2e4 = 0x03473bc0;
u32 var8005f2e8 = 0x03938700;
u32 var8005f2ec = 0x03dfd240;
u32 var8005f2f0 = 0x042c1d80;
u32 var8005f2f4 = 0x047868c0;
u32 var8005f2f8 = 0x04c4b400;
u32 var8005f2fc = 0x0510ff40;
u32 var8005f300 = 0x055d4a80;
u32 var8005f304 = 0x05a995c0;
u32 var8005f308 = 0x05f5e100;
u32 var8005f30c = 0x06422c40;
u32 var8005f310 = 0x068e7780;
u32 var8005f314 = 0x06dac2c0;
u32 var8005f318 = 0x07270e00;
u32 var8005f31c = 0x07735940;
u32 var8005f320 = 0x07bfa480;
u32 var8005f324 = 0x080befc0;
u32 var8005f328 = 0x08583b00;
u32 var8005f32c = 0x08a48640;
u32 var8005f330 = 0x08f0d180;
u32 var8005f334 = 0x093d1cc0;
u32 var8005f338 = 0x09896800;
u32 var8005f33c = 0x09d5b340;
u32 var8005f340 = 0x0a21fe80;
u32 var8005f344 = 0x0a6e49c0;
u32 var8005f348 = 0x0aba9500;
u32 var8005f34c = 0x3d4ccccd;
u32 var8005f350 = 0x3d4ccccd;
u32 var8005f354 = 0x3d75c28f;
u32 var8005f358 = 0x3d75c28f;
u32 var8005f35c = 0x3d75c28f;
u32 var8005f360 = 0x3d8f5c29;
u32 var8005f364 = 0x3d8f5c29;
u32 var8005f368 = 0x3da3d70a;
u32 var8005f36c = 0x3da3d70a;
u32 var8005f370 = 0x3db851ec;
u32 var8005f374 = 0x3dcccccd;
u32 var8005f378 = 0x3de147ae;
u32 var8005f37c = 0x3e051eb8;
u32 var8005f380 = 0x3e0f5c29;
u32 var8005f384 = 0x3e2e147b;
u32 var8005f388 = 0x3e4ccccd;
u32 var8005f38c = 0x3e800000;
u32 var8005f390 = 0x3ea8f5c3;
u32 var8005f394 = 0x3f000000;
u32 var8005f398 = 0x3f800000;
u32 var8005f39c = 0x3fa00000;
u32 var8005f3a0 = 0x3fc00000;
u32 var8005f3a4 = 0x3fe00000;
u32 var8005f3a8 = 0x40000000;
u32 var8005f3ac = 0x40100000;
u32 var8005f3b0 = 0x40200000;
u32 var8005f3b4 = 0x40300000;
u32 var8005f3b8 = 0x40400000;
u32 var8005f3bc = 0x40500000;
u32 var8005f3c0 = 0x40600000;
u32 var8005f3c4 = 0x40700000;
u32 var8005f3c8 = 0x40800000;
u32 var8005f3cc = 0x40880000;
u32 var8005f3d0 = 0x40900000;
u32 var8005f3d4 = 0x40980000;
u32 var8005f3d8 = 0x40a00000;
u32 var8005f3dc = 0x40a80000;
u32 var8005f3e0 = 0x40b00000;
u32 var8005f3e4 = 0x40b80000;
u32 var8005f3e8 = 0x40c00000;
u32 var8005f3ec = 0x40c80000;
u32 var8005f3f0 = 0x40d00000;
u32 var8005f3f4 = 0x40d80000;
u32 var8005f3f8 = 0x40e00000;
u32 var8005f3fc = 0x40e80000;
u32 var8005f400 = 0x40f00000;
u32 var8005f404 = 0x40f80000;
u32 var8005f408 = 0x41000000;
u32 var8005f40c = 0x41040000;
u32 var8005f410 = 0x41080000;
u32 var8005f414 = 0x410c0000;
u32 var8005f418 = 0x41100000;
u32 var8005f41c = 0x41140000;
u32 var8005f420 = 0x41180000;
u32 var8005f424 = 0x411c0000;
u32 var8005f428 = 0x41200000;
u32 var8005f42c = 0x41240000;
u32 var8005f430 = 0x41280000;
u32 var8005f434 = 0x412c0000;
u32 var8005f438 = 0x41300000;
u32 var8005f43c = 0x41340000;
u32 var8005f440 = 0x41380000;
u32 var8005f444 = 0x413c0000;
u32 var8005f448 = 0x41400000;
u32 var8005f44c = 0x41440000;
u32 var8005f450 = 0x41480000;
u32 var8005f454 = 0x414c0000;
u32 var8005f458 = 0x41500000;
u32 var8005f45c = 0x41540000;
u32 var8005f460 = 0x41580000;
u32 var8005f464 = 0x415c0000;
u32 var8005f468 = 0x41600000;
u32 var8005f46c = 0x41640000;
u32 var8005f470 = 0x41680000;
u32 var8005f474 = 0x416c0000;
u32 var8005f478 = 0x41700000;
u32 var8005f47c = 0x41740000;
u32 var8005f480 = 0x41780000;
u32 var8005f484 = 0x417c0000;
u32 var8005f488 = 0x41800000;
u32 var8005f48c = 0x41820000;
u32 var8005f490 = 0x41840000;
u32 var8005f494 = 0x41860000;
u32 var8005f498 = 0x41880000;
u32 var8005f49c = 0x418a0000;
u32 var8005f4a0 = 0x418c0000;
u32 var8005f4a4 = 0x418e0000;
u32 var8005f4a8 = 0x41900000;
u32 var8005f4ac = 0x41920000;
u32 var8005f4b0 = 0x41940000;
u32 var8005f4b4 = 0x41960000;
u32 var8005f4b8 = 0x41980000;
u32 var8005f4bc = 0x419a0000;
u32 var8005f4c0 = 0x419c0000;
u32 var8005f4c4 = 0x419e0000;
u32 var8005f4c8 = 0x41a00000;
u32 var8005f4cc = 0x41a20000;
u32 var8005f4d0 = 0x41a40000;
u32 var8005f4d4 = 0x41a60000;
u32 var8005f4d8 = 0x41a80000;
u32 var8005f4dc = 0x00000000;
u32 var8005f4e0 = 0x00000003;
u32 var8005f4e4 = 0x00000898;
u32 var8005f4e8 = 0x00000000;
u32 var8005f4ec = 0x000004a0;
u32 var8005f4f0 = 0x00002666;
u32 var8005f4f4 = 0xffffd99a;
u32 var8005f4f8 = 0x00000000;
u32 var8005f4fc = 0x00000000;
u32 var8005f500 = 0x00000000;
u32 var8005f504 = 0x00000000;
u32 var8005f508 = 0x000001a0;
u32 var8005f50c = 0x00000340;
u32 var8005f510 = 0x00000ccc;
u32 var8005f514 = 0xfffff334;
u32 var8005f518 = 0x00003fff;
u32 var8005f51c = 0x00000000;
u32 var8005f520 = 0x00000000;
u32 var8005f524 = 0x00000000;
u32 var8005f528 = 0x00000000;
u32 var8005f52c = 0x00000528;
u32 var8005f530 = 0x00001388;
u32 var8005f534 = 0x00000000;
u32 var8005f538 = 0x00000000;
u32 var8005f53c = 0x00000000;
u32 var8005f540 = 0x00000000;
u32 var8005f544 = 0x00005000;
u32 var8005f548 = 0x00000000;
u32 var8005f54c = 0x00000000;
u32 var8005f550 = 0x00000000;
u32 var8005f554 = 0x00000000;
u32 var8005f558 = 0x00000000;
u32 var8005f55c = 0x00000000;
u32 var8005f560 = 0x00000000;
u32 var8005f564 = 0x00000000;
u32 var8005f568 = 0x00000000;
u32 var8005f56c = 0x00000000;
u32 var8005f570 = 0x7fff7ffc;
u32 var8005f574 = 0x7ff57fe8;
u32 var8005f578 = 0x7fd77fc0;
u32 var8005f57c = 0x7fa57f84;
u32 var8005f580 = 0x7f5f7f34;
u32 var8005f584 = 0x7f057ed0;
u32 var8005f588 = 0x7e977e58;
u32 var8005f58c = 0x7e157dcd;
u32 var8005f590 = 0x7d7f7d2d;
u32 var8005f594 = 0x7cd67c7a;
u32 var8005f598 = 0x7c1a7bb4;
u32 var8005f59c = 0x7b497ada;
u32 var8005f5a0 = 0x7a6679ed;
u32 var8005f5a4 = 0x796f78ed;
u32 var8005f5a8 = 0x786677da;
u32 var8005f5ac = 0x774976b4;
u32 var8005f5b0 = 0x761a757b;
u32 var8005f5b4 = 0x74d87430;
u32 var8005f5b8 = 0x738472d3;
u32 var8005f5bc = 0x721e7164;
u32 var8005f5c0 = 0x70a66fe3;
u32 var8005f5c4 = 0x6f1c6e51;
u32 var8005f5c8 = 0x6d816cad;
u32 var8005f5cc = 0x6bd56af9;
u32 var8005f5d0 = 0x6a186933;
u32 var8005f5d4 = 0x684a675d;
u32 var8005f5d8 = 0x666c6577;
u32 var8005f5dc = 0x647e6381;
u32 var8005f5e0 = 0x6280617c;
u32 var8005f5e4 = 0x60735f67;
u32 var8005f5e8 = 0x5e575d43;
u32 var8005f5ec = 0x5c2c5b11;
u32 var8005f5f0 = 0x59f258d0;
u32 var8005f5f4 = 0x57aa5681;
u32 var8005f5f8 = 0x55555425;
u32 var8005f5fc = 0x52f251bc;
u32 var8005f600 = 0x50824f46;
u32 var8005f604 = 0x4e064cc3;
u32 var8005f608 = 0x4b7d4a35;
u32 var8005f60c = 0x48e9479b;
u32 var8005f610 = 0x464944f5;
u32 var8005f614 = 0x439e4245;
u32 var8005f618 = 0x40e93f8a;
u32 var8005f61c = 0x3e293cc6;
u32 var8005f620 = 0x3b6039f8;
u32 var8005f624 = 0x388d3721;
u32 var8005f628 = 0x35b23441;
u32 var8005f62c = 0x32ce3159;
u32 var8005f630 = 0x2fe22e69;
u32 var8005f634 = 0x2cef2b72;
u32 var8005f638 = 0x29f42875;
u32 var8005f63c = 0x26f32570;
u32 var8005f640 = 0x23ec2266;
u32 var8005f644 = 0x20df1f57;
u32 var8005f648 = 0x1dce1c43;
u32 var8005f64c = 0x1ab7192a;
u32 var8005f650 = 0x179c160e;
u32 var8005f654 = 0x147e12ed;
u32 var8005f658 = 0x115c0fca;
u32 var8005f65c = 0x0e380ca5;
u32 var8005f660 = 0x0b11097d;
u32 var8005f664 = 0x07e90654;
u32 var8005f668 = 0x04c0032a;
u32 var8005f66c = 0x01950000;
u32 var8005f670 = 0x00000000;
u32 var8005f674 = (u32) &var70054b40;
u32 var8005f678 = (u32) &var70054b68;
u32 var8005f67c = (u32) &var70054bb8;
u32 var8005f680 = (u32) &var70054c08;
u32 var8005f684 = (u32) &var70054c08;
u32 var8005f688 = (u32) &var70054c90;
u32 var8005f68c = (u32) &var70054d18;
u32 var8005f690 = (u32) &var70054e40;
u32 var8005f694 = (u32) &var70054f68;
u32 var8005f698 = (u32) &var70055090;
u32 var8005f69c = (u32) &var70055298;
u32 var8005f6a0 = (u32) &var700554a0;
u32 var8005f6a4 = (u32) &var700556a8;
u32 var8005f6a8 = (u32) &var70055eb0;
u32 var8005f6ac = (u32) &var70055eb0;
u32 var8005f6b0 = (u32) &var700566b8;
u32 var8005f6b4 = (u32) &var700566b8;
u32 var8005f6b8 = (u32) &var700566b8;
u32 var8005f6bc = (u32) &var700566b8;
u32 var8005f6c0 = (u32) &var700566b8;
u32 var8005f6c4 = (u32) &var700566b8;
u32 var8005f6c8 = (u32) &var700566b8;
u32 var8005f6cc = (u32) &var700566b8;
u32 var8005f6d0 = (u32) &var70056ec0;
u32 var8005f6d4 = (u32) &var70056ec0;
u32 var8005f6d8 = (u32) &var70056ec0;
u32 var8005f6dc = (u32) &var70056ec0;
u32 var8005f6e0 = (u32) &var70056ec0;
u32 var8005f6e4 = (u32) &var70056ec0;
u32 var8005f6e8 = (u32) &var70056ec0;
u32 var8005f6ec = (u32) &var70056ec0;
u32 var8005f6f0 = (u32) &var700576c8;
u32 var8005f6f4 = (u32) &var70057750;
u32 var8005f6f8 = 0x00000000;
u32 var8005f6fc = 0x00000000;
u32 var8005f700 = 0x00000000;
u32 var8005f704 = 0x00000000;
u32 var8005f708 = 0x00000000;
u32 var8005f70c = 0x00000000;

OSViMode osViModeTable[42] = {
	{OS_VI_NTSC_LPN1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(525),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(640),        //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(640),        //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_LPF1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(524),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(640),        //origin
				SCALE(1, 0.25),     //yScale
				HSTART(35, 509),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(640),        //origin
				SCALE(1, 0.75),     //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_LAN1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_ANTIALIAS_MODE_1 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(525),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(640),        //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(640),        //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_LAF1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_SERRATE_ON |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(524),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(640),        //origin
				SCALE(1, 0.25),     //yScale
				HSTART(35, 509),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(640),        //origin
				SCALE(1, 0.75),     //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_LPN2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_ANTIALIAS_MODE_3 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(525),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(1280),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_LPF2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(524),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(1, 0.25),     //yScale
				HSTART(35, 509),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(1280),       //origin
				SCALE(1, 0.75),     //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_LAN2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(525),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(1280),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_LAF2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_SERRATE_ON |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(524),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(1, 0.25),     //yScale
				HSTART(35, 509),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(1280),       //origin
				SCALE(1, 0.75),     //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_HPN1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(1280),          //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(524),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(1, 0),        //yScale
				HSTART(35, 509),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(2560),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_HPF1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(640),           //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(524),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(0.5, 0.5),    //yScale
				HSTART(35, 509),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(2560),       //origin
				SCALE(0.5, 0.5),    //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_HAN1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_SERRATE_ON |
				0x3000,           //ctrl
			WIDTH(1280),          //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(524),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(1, 0),        //yScale
				HSTART(35, 509),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(2560),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_HAF1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_SERRATE_ON |
				0x3000,           //ctrl
			WIDTH(640),           //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(524),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(0.5, 0.5),    //yScale
				HSTART(35, 509),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(2560),       //origin
				SCALE(0.5, 0.5),    //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_HPN2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_3 |
				0x3000,           //ctrl
			WIDTH(1280),          //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(524),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(2560),       //origin
				SCALE(1, 0),        //yScale
				HSTART(35, 509),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(5120),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_NTSC_HPF2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(640),           //width
			BURST(57, 34, 5, 62), //burst
			VSYNC(524),           //vSync
			HSYNC(3093, 0),       //hSync
			LEAP(3093, 3093),     //leap
			HSTART(108, 748),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(2560),       //origin
				SCALE(0.5, 0.5),    //yScale
				HSTART(35, 509),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(5120),       //origin
				SCALE(0.5, 0.5),    //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_PAL_LPN1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(625),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(640),         //origin
				SCALE(1, 0),         //yScale
				HSTART(95, 569),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(640),         //origin
				SCALE(1, 0),         //yScale
				HSTART(95, 569),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			}}},
	{OS_VI_PAL_LPF1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(624),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(640),         //origin
				SCALE(1, 0.25),      //yScale
				HSTART(93, 567),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(640),          //origin
				SCALE(1, 0.75),       //yScale
				HSTART(95, 569),      //vStart
				BURST(105, 2, 13, 0), //vBurst
				VINTR(2),             //vIntr
			}}},
	{OS_VI_PAL_LAN1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_ANTIALIAS_MODE_1 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(625),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(640),         //origin
				SCALE(1, 0),         //yScale
				HSTART(95, 569),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(640),         //origin
				SCALE(1, 0),         //yScale
				HSTART(95, 569),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			}}},
	{OS_VI_PAL_LAF1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_SERRATE_ON |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(624),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(640),         //origin
				SCALE(1, 0.25),      //yScale
				HSTART(93, 567),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(640),          //origin
				SCALE(1, 0.75),       //yScale
				HSTART(95, 569),      //vStart
				BURST(105, 2, 13, 0), //vBurst
				VINTR(2),             //vIntr
			}}},
	{OS_VI_PAL_LPN2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_ANTIALIAS_MODE_3 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(625),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),        //origin
				SCALE(1, 0),         //yScale
				HSTART(95, 569),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(1280),        //origin
				SCALE(1, 0),         //yScale
				HSTART(95, 569),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			}}},
	{OS_VI_PAL_LPF2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(624),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),        //origin
				SCALE(1, 0.25),      //yScale
				HSTART(93, 567),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(1280),         //origin
				SCALE(1, 0.75),       //yScale
				HSTART(95, 569),      //vStart
				BURST(105, 2, 13, 0), //vBurst
				VINTR(2),             //vIntr
			}}},
	{OS_VI_PAL_LAN2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(625),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),        //origin
				SCALE(1, 0),         //yScale
				HSTART(95, 569),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(1280),        //origin
				SCALE(1, 0),         //yScale
				HSTART(95, 569),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			}}},
	{OS_VI_PAL_LAF2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_SERRATE_ON |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(624),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),        //origin
				SCALE(1, 0.25),      //yScale
				HSTART(93, 567),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(1280),         //origin
				SCALE(1, 0.75),       //yScale
				HSTART(95, 569),      //vStart
				BURST(105, 2, 13, 0), //vBurst
				VINTR(2),             //vIntr
			}}},
	{OS_VI_PAL_HPN1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(1280),          //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(624),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),        //origin
				SCALE(1, 0),         //yScale
				HSTART(93, 567),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(2560),         //origin
				SCALE(1, 0),          //yScale
				HSTART(95, 569),      //vStart
				BURST(105, 2, 13, 0), //vBurst
				VINTR(2),             //vIntr
			}}},
	{OS_VI_PAL_HPF1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(640),           //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(624),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),        //origin
				SCALE(0.5, 0.5),     //yScale
				HSTART(93, 567),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(2560),         //origin
				SCALE(0.5, 0.5),      //yScale
				HSTART(95, 569),      //vStart
				BURST(105, 2, 13, 0), //vBurst
				VINTR(2),             //vIntr
			}}},
	{OS_VI_PAL_HAN1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_SERRATE_ON |
				0x3000,           //ctrl
			WIDTH(1280),          //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(624),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),        //origin
				SCALE(1, 0),         //yScale
				HSTART(93, 567),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(2560),         //origin
				SCALE(1, 0),          //yScale
				HSTART(95, 569),      //vStart
				BURST(105, 2, 13, 0), //vBurst
				VINTR(2),             //vIntr
			}}},
	{OS_VI_PAL_HAF1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_SERRATE_ON |
				0x3000,           //ctrl
			WIDTH(640),           //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(624),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),        //origin
				SCALE(0.5, 0.5),     //yScale
				HSTART(93, 567),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(2560),         //origin
				SCALE(0.5, 0.5),      //yScale
				HSTART(95, 569),      //vStart
				BURST(105, 2, 13, 0), //vBurst
				VINTR(2),             //vIntr
			}}},
	{OS_VI_PAL_HPN2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_3 |
				0x3000,           //ctrl
			WIDTH(1280),          //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(624),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(2560),        //origin
				SCALE(1, 0),         //yScale
				HSTART(93, 567),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(5120),         //origin
				SCALE(1, 0),          //yScale
				HSTART(95, 569),      //vStart
				BURST(105, 2, 13, 0), //vBurst
				VINTR(2),             //vIntr
			}}},
	{OS_VI_PAL_HPF2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(640),           //width
			BURST(58, 30, 4, 69), //burst
			VSYNC(624),           //vSync
			HSYNC(3177, 23),      //hSync
			LEAP(3183, 3181),     //leap
			HSTART(128, 768),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(2560),        //origin
				SCALE(0.5, 0.5),     //yScale
				HSTART(93, 567),     //vStart
				BURST(107, 2, 9, 0), //vBurst
				VINTR(2),            //vIntr
			},
			{
				//[1]
				ORIGIN(5120),         //origin
				SCALE(0.5, 0.5),      //yScale
				HSTART(95, 569),      //vStart
				BURST(105, 2, 13, 0), //vBurst
				VINTR(2),             //vIntr
			}}},
	{OS_VI_MPAL_LPN1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(525),           //vSync
			HSYNC(3089, 4),       //hSync
			LEAP(3097, 3098),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(640),        //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(640),        //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_LPF1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(524),           //vSync
			HSYNC(3088, 0),       //hSync
			LEAP(3100, 3100),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(640),        //origin
				SCALE(1, 0.25),     //yScale
				HSTART(35, 509),    //vStart
				BURST(2, 2, 11, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(640),        //origin
				SCALE(1, 0.75),     //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_LAN1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_ANTIALIAS_MODE_1 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(525),           //vSync
			HSYNC(3089, 4),       //hSync
			LEAP(3097, 3098),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(640),        //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(640),        //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_LAF1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_SERRATE_ON |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(524),           //vSync
			HSYNC(3088, 0),       //hSync
			LEAP(3100, 3100),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(640),        //origin
				SCALE(1, 0.25),     //yScale
				HSTART(35, 509),    //vStart
				BURST(2, 2, 11, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(640),        //origin
				SCALE(1, 0.75),     //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_LPN2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_ANTIALIAS_MODE_3 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(525),           //vSync
			HSYNC(3089, 4),       //hSync
			LEAP(3097, 3098),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(1280),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_LPF2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(524),           //vSync
			HSYNC(3088, 0),       //hSync
			LEAP(3100, 3100),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(1, 0.25),     //yScale
				HSTART(35, 509),    //vStart
				BURST(2, 2, 11, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(1280),       //origin
				SCALE(1, 0.75),     //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_LAN2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(525),           //vSync
			HSYNC(3089, 4),       //hSync
			LEAP(3097, 3098),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(1280),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_LAF2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_SERRATE_ON |
				0x3000,           //ctrl
			WIDTH(320),           //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(524),           //vSync
			HSYNC(3088, 0),       //hSync
			LEAP(3100, 3100),     //leap
			HSTART(108, 748),     //hStart
			SCALE(2, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(1, 0.25),     //yScale
				HSTART(35, 509),    //vStart
				BURST(2, 2, 11, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(1280),       //origin
				SCALE(1, 0.75),     //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_HPN1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(1280),          //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(524),           //vSync
			HSYNC(3088, 0),       //hSync
			LEAP(3100, 3100),     //leap
			HSTART(108, 748),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(1, 0),        //yScale
				HSTART(35, 509),    //vStart
				BURST(2, 2, 11, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(2560),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_HPF1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(640),           //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(524),           //vSync
			HSYNC(3088, 0),       //hSync
			LEAP(3100, 3100),     //leap
			HSTART(108, 748),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(0.5, 0.5),    //yScale
				HSTART(35, 509),    //vStart
				BURST(2, 2, 11, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(2560),       //origin
				SCALE(0.5, 0.5),    //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_HAN1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_SERRATE_ON |
				0x3000,           //ctrl
			WIDTH(1280),          //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(524),           //vSync
			HSYNC(3088, 0),       //hSync
			LEAP(3100, 3100),     //leap
			HSTART(108, 748),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(1, 0),        //yScale
				HSTART(35, 509),    //vStart
				BURST(2, 2, 11, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(2560),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_HAF1, //type
		{
			//comRegs
			VI_CTRL_TYPE_16 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_DIVOT_ON |
				VI_CTRL_SERRATE_ON |
				0x3000,           //ctrl
			WIDTH(640),           //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(524),           //vSync
			HSYNC(3088, 0),       //hSync
			LEAP(3100, 3100),     //leap
			HSTART(108, 748),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(1280),       //origin
				SCALE(0.5, 0.5),    //yScale
				HSTART(35, 509),    //vStart
				BURST(2, 2, 11, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(2560),       //origin
				SCALE(0.5, 0.5),    //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_HPN2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_3 |
				0x3000,           //ctrl
			WIDTH(1280),          //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(524),           //vSync
			HSYNC(3088, 0),       //hSync
			LEAP(3100, 3100),     //leap
			HSTART(108, 748),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(2560),       //origin
				SCALE(1, 0),        //yScale
				HSTART(35, 509),    //vStart
				BURST(2, 2, 11, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(5120),       //origin
				SCALE(1, 0),        //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
	{OS_VI_MPAL_HPF2, //type
		{
			//comRegs
			VI_CTRL_TYPE_32 |
				VI_CTRL_GAMMA_DITHER_ON |
				VI_CTRL_GAMMA_ON |
				VI_CTRL_SERRATE_ON |
				VI_CTRL_ANTIALIAS_MODE_2 |
				0x3000,           //ctrl
			WIDTH(640),           //width
			BURST(57, 30, 5, 70), //burst
			VSYNC(524),           //vSync
			HSYNC(3088, 0),       //hSync
			LEAP(3100, 3100),     //leap
			HSTART(108, 748),     //hStart
			SCALE(1, 0),          //xScale
			VCURRENT(0),          //vCurrent
		},
		{//fldRegs
			{
				//[0]
				ORIGIN(2560),       //origin
				SCALE(0.5, 0.5),    //yScale
				HSTART(35, 509),    //vStart
				BURST(2, 2, 11, 0), //vBurst
				VINTR(2),           //vIntr
			},
			{
				//[1]
				ORIGIN(5120),       //origin
				SCALE(0.5, 0.5),    //yScale
				HSTART(37, 511),    //vStart
				BURST(4, 2, 14, 0), //vBurst
				VINTR(2),           //vIntr
			}}},
};

u32 var80060430 = 0x2a000000;
u32 var80060434 = 0x0000320e;
u32 var80060438 = 0x00000140;
u32 var8006043c = 0x04541e3a;
u32 var80060440 = 0x00000271;
u32 var80060444 = 0x00170c69;
u32 var80060448 = 0x0c6f0c6d;
u32 var8006044c = 0x00800300;
u32 var80060450 = 0x00000200;
u32 var80060454 = 0x00000000;
u32 var80060458 = 0x00000280;
u32 var8006045c = 0x00000400;
u32 var80060460 = 0x002f0269;
u32 var80060464 = 0x0009026b;
u32 var80060468 = 0x00000002;
u32 var8006046c = 0x00000280;
u32 var80060470 = 0x00000400;
u32 var80060474 = 0x002f0269;
u32 var80060478 = 0x0009026b;
u32 var8006047c = 0x00000002;
u32 var80060480 = 0x2b000000;
u32 var80060484 = 0x0000324e;
u32 var80060488 = 0x00000140;
u32 var8006048c = 0x04541e3a;
u32 var80060490 = 0x00000270;
u32 var80060494 = 0x00170c69;
u32 var80060498 = 0x0c6f0c6d;
u32 var8006049c = 0x00800300;
u32 var800604a0 = 0x00000200;
u32 var800604a4 = 0x00000000;
u32 var800604a8 = 0x00000280;
u32 var800604ac = 0x01000400;
u32 var800604b0 = 0x002d0267;
u32 var800604b4 = 0x0009026b;
u32 var800604b8 = 0x00000002;
u32 var800604bc = 0x00000280;
u32 var800604c0 = 0x03000400;
u32 var800604c4 = 0x002f0269;
u32 var800604c8 = 0x000d0269;
u32 var800604cc = 0x00000002;
u32 var800604d0 = 0x2c000000;
u32 var800604d4 = 0x0000311e;
u32 var800604d8 = 0x00000140;
u32 var800604dc = 0x04541e3a;
u32 var800604e0 = 0x00000271;
u32 var800604e4 = 0x00170c69;
u32 var800604e8 = 0x0c6f0c6d;
u32 var800604ec = 0x00800300;
u32 var800604f0 = 0x00000200;
u32 var800604f4 = 0x00000000;
u32 var800604f8 = 0x00000280;
u32 var800604fc = 0x00000400;
u32 var80060500 = 0x002f0269;
u32 var80060504 = 0x0009026b;
u32 var80060508 = 0x00000002;
u32 var8006050c = 0x00000280;
u32 var80060510 = 0x00000400;
u32 var80060514 = 0x002f0269;
u32 var80060518 = 0x0009026b;
u32 var8006051c = 0x00000002;
u32 var80060520 = 0x2d000000;
u32 var80060524 = 0x0000305e;
u32 var80060528 = 0x00000140;
u32 var8006052c = 0x04541e3a;
u32 var80060530 = 0x00000270;
u32 var80060534 = 0x00170c69;
u32 var80060538 = 0x0c6f0c6d;
u32 var8006053c = 0x00800300;
u32 var80060540 = 0x00000200;
u32 var80060544 = 0x00000000;
u32 var80060548 = 0x00000280;
u32 var8006054c = 0x01000400;
u32 var80060550 = 0x002d0267;
u32 var80060554 = 0x0009026b;
u32 var80060558 = 0x00000002;
u32 var8006055c = 0x00000280;
u32 var80060560 = 0x03000400;
u32 var80060564 = 0x002f0269;
u32 var80060568 = 0x000d0269;
u32 var8006056c = 0x00000002;
u32 var80060570 = 0x2e000000;
u32 var80060574 = 0x0000330f;
u32 var80060578 = 0x00000140;
u32 var8006057c = 0x04541e3a;
u32 var80060580 = 0x00000271;
u32 var80060584 = 0x00170c69;
u32 var80060588 = 0x0c6f0c6d;
u32 var8006058c = 0x00800300;
u32 var80060590 = 0x00000200;
u32 var80060594 = 0x00000000;
u32 var80060598 = 0x00000500;
u32 var8006059c = 0x00000400;
u32 var800605a0 = 0x002f0269;
u32 var800605a4 = 0x0009026b;
u32 var800605a8 = 0x00000002;
u32 var800605ac = 0x00000500;
u32 var800605b0 = 0x00000400;
u32 var800605b4 = 0x002f0269;
u32 var800605b8 = 0x0009026b;
u32 var800605bc = 0x00000002;
u32 var800605c0 = 0x2f000000;
u32 var800605c4 = 0x0000324f;
u32 var800605c8 = 0x00000140;
u32 var800605cc = 0x04541e3a;
u32 var800605d0 = 0x00000270;
u32 var800605d4 = 0x00170c69;
u32 var800605d8 = 0x0c6f0c6d;
u32 var800605dc = 0x00800300;
u32 var800605e0 = 0x00000200;
u32 var800605e4 = 0x00000000;
u32 var800605e8 = 0x00000500;
u32 var800605ec = 0x01000400;
u32 var800605f0 = 0x002d0267;
u32 var800605f4 = 0x0009026b;
u32 var800605f8 = 0x00000002;
u32 var800605fc = 0x00000500;
u32 var80060600 = 0x03000400;
u32 var80060604 = 0x002f0269;
u32 var80060608 = 0x000d0269;
u32 var8006060c = 0x00000002;
u32 var80060610 = 0x30000000;
u32 var80060614 = 0x0000301f;
u32 var80060618 = 0x00000140;
u32 var8006061c = 0x04541e3a;
u32 var80060620 = 0x00000271;
u32 var80060624 = 0x00170c69;
u32 var80060628 = 0x0c6f0c6d;
u32 var8006062c = 0x00800300;
u32 var80060630 = 0x00000200;
u32 var80060634 = 0x00000000;
u32 var80060638 = 0x00000500;
u32 var8006063c = 0x00000400;
u32 var80060640 = 0x002f0269;
u32 var80060644 = 0x0009026b;
u32 var80060648 = 0x00000002;
u32 var8006064c = 0x00000500;
u32 var80060650 = 0x00000400;
u32 var80060654 = 0x002f0269;
u32 var80060658 = 0x0009026b;
u32 var8006065c = 0x00000002;
u32 var80060660 = 0x31000000;
u32 var80060664 = 0x0000305f;
u32 var80060668 = 0x00000140;
u32 var8006066c = 0x04541e3a;
u32 var80060670 = 0x00000270;
u32 var80060674 = 0x00170c69;
u32 var80060678 = 0x0c6f0c6d;
u32 var8006067c = 0x00800300;
u32 var80060680 = 0x00000200;
u32 var80060684 = 0x00000000;
u32 var80060688 = 0x00000500;
u32 var8006068c = 0x01000400;
u32 var80060690 = 0x002d0267;
u32 var80060694 = 0x0009026b;
u32 var80060698 = 0x00000002;
u32 var8006069c = 0x00000500;
u32 var800606a0 = 0x03000400;
u32 var800606a4 = 0x002f0269;
u32 var800606a8 = 0x000d0269;
u32 var800606ac = 0x00000002;
u32 var800606b0 = 0x32000000;
u32 var800606b4 = 0x0000324e;
u32 var800606b8 = 0x00000500;
u32 var800606bc = 0x04541e3a;
u32 var800606c0 = 0x00000270;
u32 var800606c4 = 0x00170c69;
u32 var800606c8 = 0x0c6f0c6d;
u32 var800606cc = 0x00800300;
u32 var800606d0 = 0x00000400;
u32 var800606d4 = 0x00000000;
u32 var800606d8 = 0x00000500;
u32 var800606dc = 0x00000400;
u32 var800606e0 = 0x002d0267;
u32 var800606e4 = 0x0009026b;
u32 var800606e8 = 0x00000002;
u32 var800606ec = 0x00000a00;
u32 var800606f0 = 0x00000400;
u32 var800606f4 = 0x002f0269;
u32 var800606f8 = 0x000d0269;
u32 var800606fc = 0x00000002;
u32 var80060700 = 0x33000000;
u32 var80060704 = 0x0000324e;
u32 var80060708 = 0x00000280;
u32 var8006070c = 0x04541e3a;
u32 var80060710 = 0x00000270;
u32 var80060714 = 0x00170c69;
u32 var80060718 = 0x0c6f0c6d;
u32 var8006071c = 0x00800300;
u32 var80060720 = 0x00000400;
u32 var80060724 = 0x00000000;
u32 var80060728 = 0x00000500;
u32 var8006072c = 0x02000800;
u32 var80060730 = 0x002d0267;
u32 var80060734 = 0x0009026b;
u32 var80060738 = 0x00000002;
u32 var8006073c = 0x00000a00;
u32 var80060740 = 0x02000800;
u32 var80060744 = 0x002f0269;
u32 var80060748 = 0x000d0269;
u32 var8006074c = 0x00000002;
u32 var80060750 = 0x34000000;
u32 var80060754 = 0x0000305e;
u32 var80060758 = 0x00000500;
u32 var8006075c = 0x04541e3a;
u32 var80060760 = 0x00000270;
u32 var80060764 = 0x00170c69;
u32 var80060768 = 0x0c6f0c6d;
u32 var8006076c = 0x00800300;
u32 var80060770 = 0x00000400;
u32 var80060774 = 0x00000000;
u32 var80060778 = 0x00000500;
u32 var8006077c = 0x00000400;
u32 var80060780 = 0x002d0267;
u32 var80060784 = 0x0009026b;
u32 var80060788 = 0x00000002;
u32 var8006078c = 0x00000a00;
u32 var80060790 = 0x00000400;
u32 var80060794 = 0x002f0269;
u32 var80060798 = 0x000d0269;
u32 var8006079c = 0x00000002;
u32 var800607a0 = 0x35000000;
u32 var800607a4 = 0x0000305e;
u32 var800607a8 = 0x00000280;
u32 var800607ac = 0x04541e3a;
u32 var800607b0 = 0x00000270;
u32 var800607b4 = 0x00170c69;
u32 var800607b8 = 0x0c6f0c6d;
u32 var800607bc = 0x00800300;
u32 var800607c0 = 0x00000400;
u32 var800607c4 = 0x00000000;
u32 var800607c8 = 0x00000500;
u32 var800607cc = 0x02000800;
u32 var800607d0 = 0x002d0267;
u32 var800607d4 = 0x0009026b;
u32 var800607d8 = 0x00000002;
u32 var800607dc = 0x00000a00;
u32 var800607e0 = 0x02000800;
u32 var800607e4 = 0x002f0269;
u32 var800607e8 = 0x000d0269;
u32 var800607ec = 0x00000002;
u32 var800607f0 = 0x36000000;
u32 var800607f4 = 0x0000334f;
u32 var800607f8 = 0x00000500;
u32 var800607fc = 0x04541e3a;
u32 var80060800 = 0x00000270;
u32 var80060804 = 0x00170c69;
u32 var80060808 = 0x0c6f0c6d;
u32 var8006080c = 0x00800300;
u32 var80060810 = 0x00000400;
u32 var80060814 = 0x00000000;
u32 var80060818 = 0x00000a00;
u32 var8006081c = 0x00000400;
u32 var80060820 = 0x002d0267;
u32 var80060824 = 0x0009026b;
u32 var80060828 = 0x00000002;
u32 var8006082c = 0x00001400;
u32 var80060830 = 0x00000400;
u32 var80060834 = 0x002f0269;
u32 var80060838 = 0x000d0269;
u32 var8006083c = 0x00000002;
u32 var80060840 = 0x37000000;
u32 var80060844 = 0x0000324f;
u32 var80060848 = 0x00000280;
u32 var8006084c = 0x04541e3a;
u32 var80060850 = 0x00000270;
u32 var80060854 = 0x00170c69;
u32 var80060858 = 0x0c6f0c6d;
u32 var8006085c = 0x00800300;
u32 var80060860 = 0x00000400;
u32 var80060864 = 0x00000000;
u32 var80060868 = 0x00000a00;
u32 var8006086c = 0x02000800;
u32 var80060870 = 0x002d0267;
u32 var80060874 = 0x0009026b;
u32 var80060878 = 0x00000002;
u32 var8006087c = 0x00001400;
u32 var80060880 = 0x02000800;
u32 var80060884 = 0x002f0269;
u32 var80060888 = 0x000d0269;
u32 var8006088c = 0x00000002;
u32 var80060890 = 0x00000000;
u32 var80060894 = 0x00000000;
u32 var80060898 = 0x00000000;
u32 var8006089c = 0x00000000;
OSTimer *__osTimerList = &var8009c760;
u32 var800608a4 = 0x00000000;
u32 var800608a8 = 0x00000000;
u32 var800608ac = 0x00000000;
__OSViContext var800608b0[2] = {0};
__OSViContext *__osViCurr = &var800608b0[0];
__OSViContext *__osViNext = &var800608b0[1];
u32 var80060918 = 0x00000000;
u32 var8006091c = 0x00000000;
u32 __osPiAccessQueueEnabled = 0x00000000;
u32 var80060924 = 0x00000000;
u32 var80060928 = 0x00000000;
u32 var8006092c = 0x00000000;
u32 __osThreadTail = 0x00000000;
u32 var80060934 = 0xffffffff;
OSThread *__osRunQueue = (OSThread *)&__osThreadTail;
OSThread *__osActiveQueue = (OSThread *)&__osThreadTail;
OSThread *__osRunningThread = NULL;
OSThread *__osFaultedThread = NULL;
u32 var80060948 = 0x00000000;
u32 var8006094c = 0x00000000;
u32 __osSiAccessQueueEnabled = 0x00000000;
u32 var80060954 = 0x00000000;
u32 var80060958 = 0x00000000;
u32 var8006095c = 0x00000000;
u32 __osContInitialized = 0x00000000;
u32 var80060964 = 0x00000000;
u32 var80060968 = 0x00000000;
u32 var8006096c = 0x00000000;
u32 var80060970 = 0xffffffff;
u32 var80060974 = 0x00000000;
u32 var80060978 = 0x00000000;
u32 var8006097c = 0x00000000;
u32 var80060980 = 0xffffffff;
u8 var80060984 = 0xfa;
u32 var80060988 = 0x00000000;
u32 var8006098c = 0x00000000;
u32 var80060990 = 0x00000000;
u32 var80060994 = 0x00000000;
u32 var80060998 = 0x00000000;
u32 var8006099c = 0x00000000;
u32 var800609a0 = 0x20202020;
u32 var800609a4 = 0x20202020;
u32 var800609a8 = 0x20202020;
u32 var800609ac = 0x20202020;
u32 var800609b0 = 0x20202020;
u32 var800609b4 = 0x20202020;
u32 var800609b8 = 0x20202020;
u32 var800609bc = 0x20202020;
u32 var800609c0 = 0x00000000;
u32 var800609c4 = 0x30303030;
u32 var800609c8 = 0x30303030;
u32 var800609cc = 0x30303030;
u32 var800609d0 = 0x30303030;
u32 var800609d4 = 0x30303030;
u32 var800609d8 = 0x30303030;
u32 var800609dc = 0x30303030;
u32 var800609e0 = 0x30303030;
u32 var800609e4 = 0x00000000;
u32 var800609e8 = 0x00000000;
u32 var800609ec = 0x00000000;
u32 var800609f0 = 0x00000032;
u32 var800609f4 = 0x00640096;
u32 var800609f8 = 0x00c900fb;
u32 var800609fc = 0x012d0160;
u32 var80060a00 = 0x019201c4;
u32 var80060a04 = 0x01f70229;
u32 var80060a08 = 0x025b028e;
u32 var80060a0c = 0x02c002f2;
u32 var80060a10 = 0x03240357;
u32 var80060a14 = 0x038903bb;
u32 var80060a18 = 0x03ee0420;
u32 var80060a1c = 0x04520484;
u32 var80060a20 = 0x04b704e9;
u32 var80060a24 = 0x051b054e;
u32 var80060a28 = 0x058005b2;
u32 var80060a2c = 0x05e40617;
u32 var80060a30 = 0x0649067b;
u32 var80060a34 = 0x06ad06e0;
u32 var80060a38 = 0x07120744;
u32 var80060a3c = 0x077607a9;
u32 var80060a40 = 0x07db080d;
u32 var80060a44 = 0x083f0871;
u32 var80060a48 = 0x08a408d6;
u32 var80060a4c = 0x0908093a;
u32 var80060a50 = 0x096c099f;
u32 var80060a54 = 0x09d10a03;
u32 var80060a58 = 0x0a350a67;
u32 var80060a5c = 0x0a990acb;
u32 var80060a60 = 0x0afe0b30;
u32 var80060a64 = 0x0b620b94;
u32 var80060a68 = 0x0bc60bf8;
u32 var80060a6c = 0x0c2a0c5c;
u32 var80060a70 = 0x0c8e0cc0;
u32 var80060a74 = 0x0cf20d25;
u32 var80060a78 = 0x0d570d89;
u32 var80060a7c = 0x0dbb0ded;
u32 var80060a80 = 0x0e1f0e51;
u32 var80060a84 = 0x0e830eb5;
u32 var80060a88 = 0x0ee70f19;
u32 var80060a8c = 0x0f4b0f7c;
u32 var80060a90 = 0x0fae0fe0;
u32 var80060a94 = 0x10121044;
u32 var80060a98 = 0x107610a8;
u32 var80060a9c = 0x10da110c;
u32 var80060aa0 = 0x113e116f;
u32 var80060aa4 = 0x11a111d3;
u32 var80060aa8 = 0x12051237;
u32 var80060aac = 0x1269129a;
u32 var80060ab0 = 0x12cc12fe;
u32 var80060ab4 = 0x13301361;
u32 var80060ab8 = 0x139313c5;
u32 var80060abc = 0x13f61428;
u32 var80060ac0 = 0x145a148c;
u32 var80060ac4 = 0x14bd14ef;
u32 var80060ac8 = 0x15201552;
u32 var80060acc = 0x158415b5;
u32 var80060ad0 = 0x15e71618;
u32 var80060ad4 = 0x164a167b;
u32 var80060ad8 = 0x16ad16df;
u32 var80060adc = 0x17101741;
u32 var80060ae0 = 0x177317a4;
u32 var80060ae4 = 0x17d61807;
u32 var80060ae8 = 0x1839186a;
u32 var80060aec = 0x189b18cd;
u32 var80060af0 = 0x18fe1930;
u32 var80060af4 = 0x19611992;
u32 var80060af8 = 0x19c319f5;
u32 var80060afc = 0x1a261a57;
u32 var80060b00 = 0x1a881aba;
u32 var80060b04 = 0x1aeb1b1c;
u32 var80060b08 = 0x1b4d1b7e;
u32 var80060b0c = 0x1baf1be1;
u32 var80060b10 = 0x1c121c43;
u32 var80060b14 = 0x1c741ca5;
u32 var80060b18 = 0x1cd61d07;
u32 var80060b1c = 0x1d381d69;
u32 var80060b20 = 0x1d9a1dcb;
u32 var80060b24 = 0x1dfc1e2d;
u32 var80060b28 = 0x1e5d1e8e;
u32 var80060b2c = 0x1ebf1ef0;
u32 var80060b30 = 0x1f211f52;
u32 var80060b34 = 0x1f821fb3;
u32 var80060b38 = 0x1fe42015;
u32 var80060b3c = 0x20452076;
u32 var80060b40 = 0x20a720d7;
u32 var80060b44 = 0x21082139;
u32 var80060b48 = 0x2169219a;
u32 var80060b4c = 0x21ca21fb;
u32 var80060b50 = 0x222b225c;
u32 var80060b54 = 0x228c22bd;
u32 var80060b58 = 0x22ed231d;
u32 var80060b5c = 0x234e237e;
u32 var80060b60 = 0x23ae23df;
u32 var80060b64 = 0x240f243f;
u32 var80060b68 = 0x247024a0;
u32 var80060b6c = 0x24d02500;
u32 var80060b70 = 0x25302560;
u32 var80060b74 = 0x259125c1;
u32 var80060b78 = 0x25f12621;
u32 var80060b7c = 0x26512681;
u32 var80060b80 = 0x26b126e1;
u32 var80060b84 = 0x27112740;
u32 var80060b88 = 0x277027a0;
u32 var80060b8c = 0x27d02800;
u32 var80060b90 = 0x2830285f;
u32 var80060b94 = 0x288f28bf;
u32 var80060b98 = 0x28ee291e;
u32 var80060b9c = 0x294e297d;
u32 var80060ba0 = 0x29ad29dd;
u32 var80060ba4 = 0x2a0c2a3c;
u32 var80060ba8 = 0x2a6b2a9b;
u32 var80060bac = 0x2aca2af9;
u32 var80060bb0 = 0x2b292b58;
u32 var80060bb4 = 0x2b872bb7;
u32 var80060bb8 = 0x2be62c15;
u32 var80060bbc = 0x2c442c74;
u32 var80060bc0 = 0x2ca32cd2;
u32 var80060bc4 = 0x2d012d30;
u32 var80060bc8 = 0x2d5f2d8e;
u32 var80060bcc = 0x2dbd2dec;
u32 var80060bd0 = 0x2e1b2e4a;
u32 var80060bd4 = 0x2e792ea8;
u32 var80060bd8 = 0x2ed72f06;
u32 var80060bdc = 0x2f342f63;
u32 var80060be0 = 0x2f922fc0;
u32 var80060be4 = 0x2fef301e;
u32 var80060be8 = 0x304c307b;
u32 var80060bec = 0x30a930d8;
u32 var80060bf0 = 0x31073135;
u32 var80060bf4 = 0x31633192;
u32 var80060bf8 = 0x31c031ef;
u32 var80060bfc = 0x321d324b;
u32 var80060c00 = 0x327932a8;
u32 var80060c04 = 0x32d63304;
u32 var80060c08 = 0x33323360;
u32 var80060c0c = 0x338e33bc;
u32 var80060c10 = 0x33ea3418;
u32 var80060c14 = 0x34463474;
u32 var80060c18 = 0x34a234d0;
u32 var80060c1c = 0x34fe352b;
u32 var80060c20 = 0x35593587;
u32 var80060c24 = 0x35b535e2;
u32 var80060c28 = 0x3610363d;
u32 var80060c2c = 0x366b3698;
u32 var80060c30 = 0x36c636f3;
u32 var80060c34 = 0x3721374e;
u32 var80060c38 = 0x377c37a9;
u32 var80060c3c = 0x37d63803;
u32 var80060c40 = 0x3831385e;
u32 var80060c44 = 0x388b38b8;
u32 var80060c48 = 0x38e53912;
u32 var80060c4c = 0x393f396c;
u32 var80060c50 = 0x399939c6;
u32 var80060c54 = 0x39f33a20;
u32 var80060c58 = 0x3a4d3a79;
u32 var80060c5c = 0x3aa63ad3;
u32 var80060c60 = 0x3b003b2c;
u32 var80060c64 = 0x3b593b85;
u32 var80060c68 = 0x3bb23bde;
u32 var80060c6c = 0x3c0b3c37;
u32 var80060c70 = 0x3c643c90;
u32 var80060c74 = 0x3cbc3ce9;
u32 var80060c78 = 0x3d153d41;
u32 var80060c7c = 0x3d6d3d99;
u32 var80060c80 = 0x3dc53df1;
u32 var80060c84 = 0x3e1d3e49;
u32 var80060c88 = 0x3e753ea1;
u32 var80060c8c = 0x3ecd3ef9;
u32 var80060c90 = 0x3f253f50;
u32 var80060c94 = 0x3f7c3fa8;
u32 var80060c98 = 0x3fd33fff;
u32 var80060c9c = 0x402b4056;
u32 var80060ca0 = 0x408240ad;
u32 var80060ca4 = 0x40d84104;
u32 var80060ca8 = 0x412f415a;
u32 var80060cac = 0x418641b1;
u32 var80060cb0 = 0x41dc4207;
u32 var80060cb4 = 0x4232425d;
u32 var80060cb8 = 0x428842b3;
u32 var80060cbc = 0x42de4309;
u32 var80060cc0 = 0x4334435f;
u32 var80060cc4 = 0x438943b4;
u32 var80060cc8 = 0x43df4409;
u32 var80060ccc = 0x4434445f;
u32 var80060cd0 = 0x448944b4;
u32 var80060cd4 = 0x44de4508;
u32 var80060cd8 = 0x4533455d;
u32 var80060cdc = 0x458745b1;
u32 var80060ce0 = 0x45dc4606;
u32 var80060ce4 = 0x4630465a;
u32 var80060ce8 = 0x468446ae;
u32 var80060cec = 0x46d84702;
u32 var80060cf0 = 0x472c4755;
u32 var80060cf4 = 0x477f47a9;
u32 var80060cf8 = 0x47d247fc;
u32 var80060cfc = 0x4826484f;
u32 var80060d00 = 0x487948a2;
u32 var80060d04 = 0x48cc48f5;
u32 var80060d08 = 0x491e4948;
u32 var80060d0c = 0x4971499a;
u32 var80060d10 = 0x49c349ec;
u32 var80060d14 = 0x4a154a3e;
u32 var80060d18 = 0x4a674a90;
u32 var80060d1c = 0x4ab94ae2;
u32 var80060d20 = 0x4b0b4b33;
u32 var80060d24 = 0x4b5c4b85;
u32 var80060d28 = 0x4bad4bd6;
u32 var80060d2c = 0x4bfe4c27;
u32 var80060d30 = 0x4c4f4c78;
u32 var80060d34 = 0x4ca04cc8;
u32 var80060d38 = 0x4cf04d19;
u32 var80060d3c = 0x4d414d69;
u32 var80060d40 = 0x4d914db9;
u32 var80060d44 = 0x4de14e09;
u32 var80060d48 = 0x4e314e58;
u32 var80060d4c = 0x4e804ea8;
u32 var80060d50 = 0x4ed04ef7;
u32 var80060d54 = 0x4f1f4f46;
u32 var80060d58 = 0x4f6e4f95;
u32 var80060d5c = 0x4fbd4fe4;
u32 var80060d60 = 0x500b5032;
u32 var80060d64 = 0x505a5081;
u32 var80060d68 = 0x50a850cf;
u32 var80060d6c = 0x50f6511d;
u32 var80060d70 = 0x5144516b;
u32 var80060d74 = 0x519151b8;
u32 var80060d78 = 0x51df5205;
u32 var80060d7c = 0x522c5253;
u32 var80060d80 = 0x527952a0;
u32 var80060d84 = 0x52c652ec;
u32 var80060d88 = 0x53135339;
u32 var80060d8c = 0x535f5385;
u32 var80060d90 = 0x53ab53d1;
u32 var80060d94 = 0x53f7541d;
u32 var80060d98 = 0x54435469;
u32 var80060d9c = 0x548f54b5;
u32 var80060da0 = 0x54da5500;
u32 var80060da4 = 0x5525554b;
u32 var80060da8 = 0x55715596;
u32 var80060dac = 0x55bb55e1;
u32 var80060db0 = 0x5606562b;
u32 var80060db4 = 0x56505675;
u32 var80060db8 = 0x569b56c0;
u32 var80060dbc = 0x56e55709;
u32 var80060dc0 = 0x572e5753;
u32 var80060dc4 = 0x5778579d;
u32 var80060dc8 = 0x57c157e6;
u32 var80060dcc = 0x580a582f;
u32 var80060dd0 = 0x58535878;
u32 var80060dd4 = 0x589c58c0;
u32 var80060dd8 = 0x58e55909;
u32 var80060ddc = 0x592d5951;
u32 var80060de0 = 0x59755999;
u32 var80060de4 = 0x59bd59e1;
u32 var80060de8 = 0x5a045a28;
u32 var80060dec = 0x5a4c5a6f;
u32 var80060df0 = 0x5a935ab7;
u32 var80060df4 = 0x5ada5afd;
u32 var80060df8 = 0x5b215b44;
u32 var80060dfc = 0x5b675b8b;
u32 var80060e00 = 0x5bae5bd1;
u32 var80060e04 = 0x5bf45c17;
u32 var80060e08 = 0x5c3a5c5d;
u32 var80060e0c = 0x5c7f5ca2;
u32 var80060e10 = 0x5cc55ce7;
u32 var80060e14 = 0x5d0a5d2d;
u32 var80060e18 = 0x5d4f5d71;
u32 var80060e1c = 0x5d945db6;
u32 var80060e20 = 0x5dd85dfa;
u32 var80060e24 = 0x5e1d5e3f;
u32 var80060e28 = 0x5e615e83;
u32 var80060e2c = 0x5ea55ec6;
u32 var80060e30 = 0x5ee85f0a;
u32 var80060e34 = 0x5f2c5f4d;
u32 var80060e38 = 0x5f6f5f90;
u32 var80060e3c = 0x5fb25fd3;
u32 var80060e40 = 0x5ff46016;
u32 var80060e44 = 0x60376058;
u32 var80060e48 = 0x6079609a;
u32 var80060e4c = 0x60bb60dc;
u32 var80060e50 = 0x60fd611e;
u32 var80060e54 = 0x613e615f;
u32 var80060e58 = 0x618061a0;
u32 var80060e5c = 0x61c161e1;
u32 var80060e60 = 0x62026222;
u32 var80060e64 = 0x62426263;
u32 var80060e68 = 0x628362a3;
u32 var80060e6c = 0x62c362e3;
u32 var80060e70 = 0x63036323;
u32 var80060e74 = 0x63426362;
u32 var80060e78 = 0x638263a1;
u32 var80060e7c = 0x63c163e0;
u32 var80060e80 = 0x6400641f;
u32 var80060e84 = 0x643f645e;
u32 var80060e88 = 0x647d649c;
u32 var80060e8c = 0x64bb64da;
u32 var80060e90 = 0x64f96518;
u32 var80060e94 = 0x65376556;
u32 var80060e98 = 0x65746593;
u32 var80060e9c = 0x65b265d0;
u32 var80060ea0 = 0x65ef660d;
u32 var80060ea4 = 0x662b664a;
u32 var80060ea8 = 0x66686686;
u32 var80060eac = 0x66a466c2;
u32 var80060eb0 = 0x66e066fe;
u32 var80060eb4 = 0x671c673a;
u32 var80060eb8 = 0x67576775;
u32 var80060ebc = 0x679267b0;
u32 var80060ec0 = 0x67cd67eb;
u32 var80060ec4 = 0x68086825;
u32 var80060ec8 = 0x68436860;
u32 var80060ecc = 0x687d689a;
u32 var80060ed0 = 0x68b768d4;
u32 var80060ed4 = 0x68f1690d;
u32 var80060ed8 = 0x692a6947;
u32 var80060edc = 0x69636980;
u32 var80060ee0 = 0x699c69b9;
u32 var80060ee4 = 0x69d569f1;
u32 var80060ee8 = 0x6a0e6a2a;
u32 var80060eec = 0x6a466a62;
u32 var80060ef0 = 0x6a7e6a9a;
u32 var80060ef4 = 0x6ab56ad1;
u32 var80060ef8 = 0x6aed6b08;
u32 var80060efc = 0x6b246b40;
u32 var80060f00 = 0x6b5b6b76;
u32 var80060f04 = 0x6b926bad;
u32 var80060f08 = 0x6bc86be3;
u32 var80060f0c = 0x6bfe6c19;
u32 var80060f10 = 0x6c346c4f;
u32 var80060f14 = 0x6c6a6c84;
u32 var80060f18 = 0x6c9f6cba;
u32 var80060f1c = 0x6cd46cef;
u32 var80060f20 = 0x6d096d23;
u32 var80060f24 = 0x6d3e6d58;
u32 var80060f28 = 0x6d726d8c;
u32 var80060f2c = 0x6da66dc0;
u32 var80060f30 = 0x6dda6df3;
u32 var80060f34 = 0x6e0d6e27;
u32 var80060f38 = 0x6e406e5a;
u32 var80060f3c = 0x6e736e8d;
u32 var80060f40 = 0x6ea66ebf;
u32 var80060f44 = 0x6ed96ef2;
u32 var80060f48 = 0x6f0b6f24;
u32 var80060f4c = 0x6f3d6f55;
u32 var80060f50 = 0x6f6e6f87;
u32 var80060f54 = 0x6fa06fb8;
u32 var80060f58 = 0x6fd16fe9;
u32 var80060f5c = 0x7002701a;
u32 var80060f60 = 0x7032704a;
u32 var80060f64 = 0x7062707a;
u32 var80060f68 = 0x709270aa;
u32 var80060f6c = 0x70c270da;
u32 var80060f70 = 0x70f27109;
u32 var80060f74 = 0x71217138;
u32 var80060f78 = 0x71507167;
u32 var80060f7c = 0x717e7196;
u32 var80060f80 = 0x71ad71c4;
u32 var80060f84 = 0x71db71f2;
u32 var80060f88 = 0x72097220;
u32 var80060f8c = 0x7236724d;
u32 var80060f90 = 0x7264727a;
u32 var80060f94 = 0x729172a7;
u32 var80060f98 = 0x72bd72d4;
u32 var80060f9c = 0x72ea7300;
u32 var80060fa0 = 0x7316732c;
u32 var80060fa4 = 0x73427358;
u32 var80060fa8 = 0x736e7383;
u32 var80060fac = 0x739973ae;
u32 var80060fb0 = 0x73c473d9;
u32 var80060fb4 = 0x73ef7404;
u32 var80060fb8 = 0x7419742e;
u32 var80060fbc = 0x74437458;
u32 var80060fc0 = 0x746d7482;
u32 var80060fc4 = 0x749774ac;
u32 var80060fc8 = 0x74c074d5;
u32 var80060fcc = 0x74ea74fe;
u32 var80060fd0 = 0x75127527;
u32 var80060fd4 = 0x753b754f;
u32 var80060fd8 = 0x75637577;
u32 var80060fdc = 0x758b759f;
u32 var80060fe0 = 0x75b375c7;
u32 var80060fe4 = 0x75da75ee;
u32 var80060fe8 = 0x76017615;
u32 var80060fec = 0x7628763b;
u32 var80060ff0 = 0x764f7662;
u32 var80060ff4 = 0x76757688;
u32 var80060ff8 = 0x769b76ae;
u32 var80060ffc = 0x76c176d3;
u32 var80061000 = 0x76e676f9;
u32 var80061004 = 0x770b771e;
u32 var80061008 = 0x77307742;
u32 var8006100c = 0x77547767;
u32 var80061010 = 0x7779778b;
u32 var80061014 = 0x779d77af;
u32 var80061018 = 0x77c077d2;
u32 var8006101c = 0x77e477f5;
u32 var80061020 = 0x78077818;
u32 var80061024 = 0x782a783b;
u32 var80061028 = 0x784c785d;
u32 var8006102c = 0x786e787f;
u32 var80061030 = 0x789078a1;
u32 var80061034 = 0x78b278c3;
u32 var80061038 = 0x78d378e4;
u32 var8006103c = 0x78f47905;
u32 var80061040 = 0x79157925;
u32 var80061044 = 0x79367946;
u32 var80061048 = 0x79567966;
u32 var8006104c = 0x79767985;
u32 var80061050 = 0x799579a5;
u32 var80061054 = 0x79b579c4;
u32 var80061058 = 0x79d479e3;
u32 var8006105c = 0x79f27a02;
u32 var80061060 = 0x7a117a20;
u32 var80061064 = 0x7a2f7a3e;
u32 var80061068 = 0x7a4d7a5b;
u32 var8006106c = 0x7a6a7a79;
u32 var80061070 = 0x7a877a96;
u32 var80061074 = 0x7aa47ab3;
u32 var80061078 = 0x7ac17acf;
u32 var8006107c = 0x7add7aeb;
u32 var80061080 = 0x7af97b07;
u32 var80061084 = 0x7b157b23;
u32 var80061088 = 0x7b317b3e;
u32 var8006108c = 0x7b4c7b59;
u32 var80061090 = 0x7b677b74;
u32 var80061094 = 0x7b817b8e;
u32 var80061098 = 0x7b9b7ba8;
u32 var8006109c = 0x7bb57bc2;
u32 var800610a0 = 0x7bcf7bdc;
u32 var800610a4 = 0x7be87bf5;
u32 var800610a8 = 0x7c027c0e;
u32 var800610ac = 0x7c1a7c27;
u32 var800610b0 = 0x7c337c3f;
u32 var800610b4 = 0x7c4b7c57;
u32 var800610b8 = 0x7c637c6f;
u32 var800610bc = 0x7c7a7c86;
u32 var800610c0 = 0x7c927c9d;
u32 var800610c4 = 0x7ca97cb4;
u32 var800610c8 = 0x7cbf7ccb;
u32 var800610cc = 0x7cd67ce1;
u32 var800610d0 = 0x7cec7cf7;
u32 var800610d4 = 0x7d027d0c;
u32 var800610d8 = 0x7d177d22;
u32 var800610dc = 0x7d2c7d37;
u32 var800610e0 = 0x7d417d4b;
u32 var800610e4 = 0x7d567d60;
u32 var800610e8 = 0x7d6a7d74;
u32 var800610ec = 0x7d7e7d88;
u32 var800610f0 = 0x7d917d9b;
u32 var800610f4 = 0x7da57dae;
u32 var800610f8 = 0x7db87dc1;
u32 var800610fc = 0x7dcb7dd4;
u32 var80061100 = 0x7ddd7de6;
u32 var80061104 = 0x7def7df8;
u32 var80061108 = 0x7e017e0a;
u32 var8006110c = 0x7e137e1b;
u32 var80061110 = 0x7e247e2c;
u32 var80061114 = 0x7e357e3d;
u32 var80061118 = 0x7e457e4d;
u32 var8006111c = 0x7e567e5e;
u32 var80061120 = 0x7e667e6d;
u32 var80061124 = 0x7e757e7d;
u32 var80061128 = 0x7e857e8c;
u32 var8006112c = 0x7e947e9b;
u32 var80061130 = 0x7ea37eaa;
u32 var80061134 = 0x7eb17eb8;
u32 var80061138 = 0x7ebf7ec6;
u32 var8006113c = 0x7ecd7ed4;
u32 var80061140 = 0x7edb7ee1;
u32 var80061144 = 0x7ee87eee;
u32 var80061148 = 0x7ef57efb;
u32 var8006114c = 0x7f017f08;
u32 var80061150 = 0x7f0e7f14;
u32 var80061154 = 0x7f1a7f20;
u32 var80061158 = 0x7f257f2b;
u32 var8006115c = 0x7f317f36;
u32 var80061160 = 0x7f3c7f41;
u32 var80061164 = 0x7f477f4c;
u32 var80061168 = 0x7f517f56;
u32 var8006116c = 0x7f5b7f60;
u32 var80061170 = 0x7f657f6a;
u32 var80061174 = 0x7f6f7f74;
u32 var80061178 = 0x7f787f7d;
u32 var8006117c = 0x7f817f85;
u32 var80061180 = 0x7f8a7f8e;
u32 var80061184 = 0x7f927f96;
u32 var80061188 = 0x7f9a7f9e;
u32 var8006118c = 0x7fa27fa6;
u32 var80061190 = 0x7fa97fad;
u32 var80061194 = 0x7fb07fb4;
u32 var80061198 = 0x7fb77fba;
u32 var8006119c = 0x7fbe7fc1;
u32 var800611a0 = 0x7fc47fc7;
u32 var800611a4 = 0x7fca7fcc;
u32 var800611a8 = 0x7fcf7fd2;
u32 var800611ac = 0x7fd47fd7;
u32 var800611b0 = 0x7fd97fdc;
u32 var800611b4 = 0x7fde7fe0;
u32 var800611b8 = 0x7fe27fe4;
u32 var800611bc = 0x7fe67fe8;
u32 var800611c0 = 0x7fea7fec;
u32 var800611c4 = 0x7fed7fef;
u32 var800611c8 = 0x7ff17ff2;
u32 var800611cc = 0x7ff37ff5;
u32 var800611d0 = 0x7ff67ff7;
u32 var800611d4 = 0x7ff87ff9;
u32 var800611d8 = 0x7ffa7ffb;
u32 var800611dc = 0x7ffb7ffc;
u32 var800611e0 = 0x7ffd7ffd;
u32 var800611e4 = 0x7ffe7ffe;
u32 var800611e8 = 0x7ffe7ffe;
u32 var800611ec = 0x7ffe7fff;
u32 var800611f0 = 0xceed6666;
u32 var800611f4 = 0xcc0d000b;
u32 var800611f8 = 0x03730083;
u32 var800611fc = 0x000c000d;
u32 var80061200 = 0x0008111f;
u32 var80061204 = 0x8889000e;
u32 var80061208 = 0xdccc6ee6;
u32 var8006120c = 0xddddd999;
u32 var80061210 = 0xbbbb6763;
u32 var80061214 = 0x6e0eeccc;
u32 var80061218 = 0xdddc999f;
u32 var8006121c = 0xbbb9333e;
u32 var80061220 = 0x00010101;
u32 var80061224 = 0xff0202ff;
u32 var80061228 = 0x0000ffff;
u32 var8006122c = 0xffffff03;
u32 var80061230 = 0x03030303;
u32 var80061234 = 0x00000000;
u32 var80061238 = 0x00000000;
u32 var8006123c = 0x00000000;

OSViMode osViModePalLan1 = {
	OS_VI_PAL_LAN1,  // type
	{
		// comRegs
		VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON |
			VI_CTRL_DIVOT_ON | VI_CTRL_ANTIALIAS_MODE_1 | 0x3000,  // ctrl
		WIDTH(320),                                                // width
		BURST(58, 30, 4, 69),                                      // burst
		VSYNC(625),                                                // vSync
		HSYNC(3177, 23),                                           // hSync
		LEAP(3183, 3181),                                          // leap
		HSTART(128, 768),                                          // hStart
		SCALE(2, 0),                                               // xScale
		VCURRENT(0),                                               // vCurrent
	},
	{// fldRegs
		{
			//[0]
			ORIGIN(640),          // origin
			SCALE(1, 0),          // yScale
			HSTART(95, 569),      // vStart
			BURST(107, 2, 9, 0),  // vBurst
			VINTR(2),             // vIntr
		},
		{
			//[1]
			ORIGIN(640),          // origin
			SCALE(1, 0),          // yScale
			HSTART(95, 569),      // vStart
			BURST(107, 2, 9, 0),  // vBurst
			VINTR(2),             // vIntr
		}}};

OSViMode osViModeMpalLan1 = {
	OS_VI_MPAL_LAN1,  // type
	{
		// comRegs
		VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON |
			VI_CTRL_DIVOT_ON | VI_CTRL_ANTIALIAS_MODE_1 | 0x3000,  // ctrl
		WIDTH(320),                                                // width
		BURST(57, 30, 5, 70),                                      // burst
		VSYNC(525),                                                // vSync
		HSYNC(3089, 4),                                            // hSync
		LEAP(3097, 3098),                                          // leap
		HSTART(108, 748),                                          // hStart
		SCALE(2, 0),                                               // xScale
		VCURRENT(0),                                               // vCurrent
	},
	{// fldRegs
		{
			//[0]
			ORIGIN(640),         // origin
			SCALE(1, 0),         // yScale
			HSTART(37, 511),     // vStart
			BURST(4, 2, 14, 0),  // vBurst
			VINTR(2),            // vIntr
		},
		{
			//[1]
			ORIGIN(640),         // origin
			SCALE(1, 0),         // yScale
			HSTART(37, 511),     // vStart
			BURST(4, 2, 14, 0),  // vBurst
			VINTR(2),            // vIntr
		}}};

OSViMode osViModeNtscLan1 = {
	OS_VI_NTSC_LAN1,  // type
	{
		// comRegs
		VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON |
			VI_CTRL_DIVOT_ON | VI_CTRL_ANTIALIAS_MODE_1 | 0x3000,  // ctrl
		WIDTH(320),                                                // width
		BURST(57, 34, 5, 62),                                      // burst
		VSYNC(525),                                                // vSync
		HSYNC(3093, 0),                                            // hSync
		LEAP(3093, 3093),                                          // leap
		HSTART(108, 748),                                          // hStart
		SCALE(2, 0),                                               // xScale
		VCURRENT(0),                                               // vCurrent
	},
	{// fldRegs
		{
			//[0]
			ORIGIN(640),         // origin
			SCALE(1, 0),         // yScale
			HSTART(37, 511),     // vStart
			BURST(4, 2, 14, 0),  // vBurst
			VINTR(2),            // vIntr
		},
		{
			//[1]
			ORIGIN(640),         // origin
			SCALE(1, 0),         // yScale
			HSTART(37, 511),     // vStart
			BURST(4, 2, 14, 0),  // vBurst
			VINTR(2),            // vIntr
		}}};

char ldigs[] = "0123456789abcdef";
char udigs[] = "0123456789ABCDEF";

u32 var80061358 = 0x00000000;
u32 var8006135c = 0x00000000;
u32 var80061360 = 0xb6000000;
u32 var80061364 = 0x001f3204;
u32 var80061368 = 0xbb000000;
u32 var8006136c = 0x00000000;
u32 var80061370 = 0xb7000000;
u32 var80061374 = 0x00000204;
u32 var80061378 = 0xb8000000;
u32 var8006137c = 0x00000000;
u32 var80061380 = 0xb6000000;
u32 var80061384 = 0x001f3204;
u32 var80061388 = 0xbb000000;
u32 var8006138c = 0x00000000;
u32 var80061390 = 0xb7000000;
u32 var80061394 = 0x00000205;
u32 var80061398 = 0xb8000000;
u32 var8006139c = 0x00000000;
u32 var800613a0 = 0xba001402;
u32 var800613a4 = 0x00000000;
u32 var800613a8 = 0xba001701;
u32 var800613ac = 0x00800000;
u32 var800613b0 = 0xba001001;
u32 var800613b4 = 0x00000000;
u32 var800613b8 = 0xba000e02;
u32 var800613bc = 0x00000000;
u32 var800613c0 = 0xba001102;
u32 var800613c4 = 0x00000000;
u32 var800613c8 = 0xba001301;
u32 var800613cc = 0x00080000;
u32 var800613d0 = 0xba000c02;
u32 var800613d4 = 0x00002000;
u32 var800613d8 = 0xba000903;
u32 var800613dc = 0x00000c00;
u32 var800613e0 = 0xfcffffff;
u32 var800613e4 = 0xfffe793c;
u32 var800613e8 = 0xba000801;
u32 var800613ec = 0x00000000;
u32 var800613f0 = 0xb9000002;
u32 var800613f4 = 0x00000000;
u32 var800613f8 = 0xb900031d;
u32 var800613fc = 0x0f0a4000;
u32 var80061400 = 0xba000602;
u32 var80061404 = 0x00000000;
u32 var80061408 = 0xba000402;
u32 var8006140c = 0x00000000;
u32 var80061410 = 0xe7000000;
u32 var80061414 = 0x00000000;
u32 var80061418 = 0xb8000000;
u32 var8006141c = 0x00000000;
