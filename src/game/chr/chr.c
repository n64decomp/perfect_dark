#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

const u32 var7f1a8680[] = {0xb8d1b717};
const u32 var7f1a8684[] = {0x00000000};
const u32 var7f1a8688[] = {0x00000000};
const u32 var7f1a868c[] = {0x00000000};

const char var7f1a8690[] = "chr/chr.c";
const char var7f1a869c[] = "selectanimnum";

const u32 var7f1a86ac[] = {0xc9742400};
const u32 var7f1a86b0[] = {0x411ffffe};
const u32 var7f1a86b4[] = {0x3f8ccccd};
const u32 var7f1a86b8[] = {0x3f8ccccd};
const u32 var7f1a86bc[] = {0x3f666666};
const u32 var7f1a86c0[] = {0x3f666666};
const u32 var7f1a86c4[] = {0x3dcccccd};
const u32 var7f1a86c8[] = {0x3f666666};
const u32 var7f1a86cc[] = {0x3f666666};
const u32 var7f1a86d0[] = {0x3f666666};
const u32 var7f1a86d4[] = {0x3f666666};
const u32 var7f1a86d8[] = {0x3f666666};
const u32 var7f1a86dc[] = {0x411ffffe};
const u32 var7f1a86e0[] = {0x411ffffe};
const u32 var7f1a86e4[] = {0x3f666666};
const u32 var7f1a86e8[] = {0x3f666666};
const u32 var7f1a86ec[] = {0x3f666666};
const u32 var7f1a86f0[] = {0x3f666666};
const u32 var7f1a86f4[] = {0xc7c35000};
const u32 var7f1a86f8[] = {0x3f666666};
const u32 var7f1a86fc[] = {0x3f666666};
const u32 var7f1a8700[] = {0xc7c35000};
const u32 var7f1a8704[] = {0x411ffffe};
const u32 var7f1a8708[] = {0xc6ea6000};
const u32 var7f1a870c[] = {0x411ffffe};
const u32 var7f1a8710[] = {0x3dccccd0};
const u32 var7f1a8714[] = {0x411ffffe};
const u32 var7f1a8718[] = {0x3dcccccd};
const u32 var7f1a871c[] = {0xbdcccccd};
const u32 var7f1a8720[] = {0x3dcccccd};
const u32 var7f1a8724[] = {0x411ffffe};
const u32 var7f1a8728[] = {0x3ec907a9};
const u32 var7f1a872c[] = {0x40c907a9};
const u32 var7f1a8730[] = {0x3fc907a9};
const u32 var7f1a8734[] = {0x3d776be4};
const u32 var7f1a8738[] = {0x3fc907a9};
const u32 var7f1a873c[] = {0x3da0d2ee};
const u32 var7f1a8740[] = {0x40c907a9};
const u32 var7f1a8744[] = {0x40c907a9};
const u32 var7f1a8748[] = {0x3fc90fdb};
const u32 var7f1a874c[] = {0x40c907a9};
const u32 var7f1a8750[] = {0x40c907a9};
const u32 var7f1a8754[] = {0x40c907a9};
const u32 var7f1a8758[] = {0x40c907a9};
const u32 var7f1a875c[] = {0x3f86051b};
const u32 var7f1a8760[] = {0xbf5f5dd8};
const u32 var7f1a8764[] = {0x3f5f5dd8};
const u32 var7f1a8768[] = {0x3f86051b};
const u32 var7f1a876c[] = {0xbf5f5dd8};
const u32 var7f1a8770[] = {0x40c907a9};
const u32 var7f1a8774[] = {0x40c907a9};
const u32 var7f1a8778[] = {0x40c907a9};
const u32 var7f1a877c[] = {0x40c907a9};
const u32 var7f1a8780[] = {0x3e86051b};
const u32 var7f1a8784[] = {0x40c907a9};
const u32 var7f1a8788[] = {0x3e86051b};
const u32 var7f1a878c[] = {0x3e32b17a};
const u32 var7f1a8790[] = {0x3e32b17a};
const u32 var7f1a8794[] = {0x40c907a9};
const u32 var7f1a8798[] = {0x40c907a9};
const u32 var7f1a879c[] = {0x40c907a9};
const u32 var7f1a87a0[] = {0x3fa8dd79};
const u32 var7f1a87a4[] = {0x3fc907a9};
const u32 var7f1a87a8[] = {0x404907a9};
const u32 var7f1a87ac[] = {0x3ecccccd};
const u32 var7f1a87b0[] = {0x40490fdb};
const u32 var7f1a87b4[] = {0x40490fdb};
const u32 var7f1a87b8[] = {0x3a83126f};
const u32 var7f1a87bc[] = {0x40c907a9};
const u32 var7f1a87c0[] = {0x3d333333};
const u32 var7f1a87c4[] = {0x3d333333};
const u32 var7f1a87c8[] = {0x4a742400};
const u32 var7f1a87cc[] = {0x48ef4200};
const u32 var7f1a87d0[] = {0x4a742400};
const u32 var7f1a87d4[] = {0x48ef4200};
const u32 var7f1a87d8[] = {0x41aa6666};
const u32 var7f1a87dc[] = {0x7f024dd0};
const u32 var7f1a87e0[] = {0x7f024dec};
const u32 var7f1a87e4[] = {0x7f024e08};
const u32 var7f1a87e8[] = {0x7f024e24};
const u32 var7f1a87ec[] = {0x7f024e40};
const u32 var7f1a87f0[] = {0x7f024e5c};
const u32 var7f1a87f4[] = {0x7f024e78};
const u32 var7f1a87f8[] = {0x7f024e94};
const u32 var7f1a87fc[] = {0x7f025174};
const u32 var7f1a8800[] = {0x7f025240};
const u32 var7f1a8804[] = {0x7f025240};
const u32 var7f1a8808[] = {0x7f025240};
const u32 var7f1a880c[] = {0x7f0251f8};
const u32 var7f1a8810[] = {0x7f0251f8};
const u32 var7f1a8814[] = {0x7f025240};
const u32 var7f1a8818[] = {0x7f025240};
const u32 var7f1a881c[] = {0x7f025240};
const u32 var7f1a8820[] = {0x7f025240};
const u32 var7f1a8824[] = {0x7f025240};
const u32 var7f1a8828[] = {0x7f025240};
const u32 var7f1a882c[] = {0x7f025240};
const u32 var7f1a8830[] = {0x7f025240};
const u32 var7f1a8834[] = {0x7f025240};
const u32 var7f1a8838[] = {0x7f025240};
const u32 var7f1a883c[] = {0x7f025174};
const u32 var7f1a8840[] = {0x7f025240};
const u32 var7f1a8844[] = {0x7f025240};
const u32 var7f1a8848[] = {0x7f025240};
const u32 var7f1a884c[] = {0x7f0251b8};
const u32 var7f1a8850[] = {0x7f0251b8};
const u32 var7f1a8854[] = {0x7f025240};
const u32 var7f1a8858[] = {0x7f025240};
const u32 var7f1a885c[] = {0x7f025240};
const u32 var7f1a8860[] = {0x7f025240};
const u32 var7f1a8864[] = {0x7f025240};
const u32 var7f1a8868[] = {0x7f025240};
const u32 var7f1a886c[] = {0x7f025240};
const u32 var7f1a8870[] = {0x7f025240};
const u32 var7f1a8874[] = {0x7f025240};
const u32 var7f1a8878[] = {0x7f0251b8};
const u32 var7f1a887c[] = {0x7f025240};
const u32 var7f1a8880[] = {0x7f025240};
const u32 var7f1a8884[] = {0x7f025240};
const u32 var7f1a8888[] = {0x7f025240};
const u32 var7f1a888c[] = {0x7f0251f8};
const u32 var7f1a8890[] = {0x7f025240};
const u32 var7f1a8894[] = {0x7f025240};
const u32 var7f1a8898[] = {0x7f025240};
const u32 var7f1a889c[] = {0x7f025240};
const u32 var7f1a88a0[] = {0x7f025240};
const u32 var7f1a88a4[] = {0x7f025240};
const u32 var7f1a88a8[] = {0x7f025240};
const u32 var7f1a88ac[] = {0x7f025240};
const u32 var7f1a88b0[] = {0x7f025240};
const u32 var7f1a88b4[] = {0x7f025240};
const u32 var7f1a88b8[] = {0x7f025240};
const u32 var7f1a88bc[] = {0x7f025240};
const u32 var7f1a88c0[] = {0x7f025240};
const u32 var7f1a88c4[] = {0x7f025240};
const u32 var7f1a88c8[] = {0x7f025240};
const u32 var7f1a88cc[] = {0x7f025240};
const u32 var7f1a88d0[] = {0x7f025240};
const u32 var7f1a88d4[] = {0x7f025240};
const u32 var7f1a88d8[] = {0x7f025240};
const u32 var7f1a88dc[] = {0x7f025240};
const u32 var7f1a88e0[] = {0x7f025240};
const u32 var7f1a88e4[] = {0x7f025240};
const u32 var7f1a88e8[] = {0x7f025240};
const u32 var7f1a88ec[] = {0x7f0251f8};
const u32 var7f1a88f0[] = {0x7f025174};
const u32 var7f1a88f4[] = {0x3c088889};
const u32 var7f1a88f8[] = {0x3b808081};
const u32 var7f1a88fc[] = {0x3b83126f};
const u32 var7f1a8900[] = {0x3ecccccd};
const u32 var7f1a8904[] = {0x7f027034};
const u32 var7f1a8908[] = {0x7f027078};
const u32 var7f1a890c[] = {0x7f026ce0};
const u32 var7f1a8910[] = {0x7f027078};
const u32 var7f1a8914[] = {0x7f027078};
const u32 var7f1a8918[] = {0x7f027078};
const u32 var7f1a891c[] = {0x7f027078};
const u32 var7f1a8920[] = {0x7f027078};
const u32 var7f1a8924[] = {0x7f027078};
const u32 var7f1a8928[] = {0x7f027078};
const u32 var7f1a892c[] = {0x7f02704c};
const u32 var7f1a8930[] = {0x7f027078};
const u32 var7f1a8934[] = {0x7f027078};
const u32 var7f1a8938[] = {0x7f027078};
const u32 var7f1a893c[] = {0x7f027078};
const u32 var7f1a8940[] = {0x7f027064};
const u32 var7f1a8944[] = {0x7f026d40};
const u32 var7f1a8948[] = {0x3d99999a};
const u32 var7f1a894c[] = {0x3c40c0c1};
const u32 var7f1a8950[] = {0x3c40c0c1};
const u32 var7f1a8954[] = {0x3bab8ba8};
const u32 var7f1a8958[] = {0x3bab8ba8};
const u32 var7f1a895c[] = {0x3f169697};
const u32 var7f1a8960[] = {0x3ea0a0a1};
const u32 var7f1a8964[] = {0x3e70f0f1};
const u32 var7f1a8968[] = {0x3e20a0a1};
const u32 var7f1a896c[] = {0x3c9309fe};
const u32 var7f1a8970[] = {0x40aaaaab};
const u32 var7f1a8974[] = {0x3b808081};
const u32 var7f1a8978[] = {0x3b808081};
const u32 var7f1a897c[] = {0x3b808081};
const u32 var7f1a8980[] = {0x3b808081};
const u32 var7f1a8984[] = {0x3c4ccccd};
const u32 var7f1a8988[] = {0x00000000};
const u32 var7f1a898c[] = {0x00000000};
const u32 var7f1a8990[] = {0x7f02ce04};
const u32 var7f1a8994[] = {0x7f02ce24};
const u32 var7f1a8998[] = {0x7f02ce24};
const u32 var7f1a899c[] = {0x7f02ce24};
const u32 var7f1a89a0[] = {0x7f02ce24};
const u32 var7f1a89a4[] = {0x7f02ce24};
const u32 var7f1a89a8[] = {0x7f02ce24};
const u32 var7f1a89ac[] = {0x7f02ce24};
const u32 var7f1a89b0[] = {0x7f02ce24};
const u32 var7f1a89b4[] = {0x7f02ce24};
const u32 var7f1a89b8[] = {0x7f02ce24};
const u32 var7f1a89bc[] = {0x7f02ce24};
const u32 var7f1a89c0[] = {0x7f02ce24};
const u32 var7f1a89c4[] = {0x7f02ce24};
const u32 var7f1a89c8[] = {0x7f02ce24};
const u32 var7f1a89cc[] = {0x7f02ce0c};
const u32 var7f1a89d0[] = {0x7f02ce14};
const u32 var7f1a89d4[] = {0x7f02ce24};
const u32 var7f1a89d8[] = {0x7f02ce24};
const u32 var7f1a89dc[] = {0x7f02ce24};
const u32 var7f1a89e0[] = {0x7f02ce24};
const u32 var7f1a89e4[] = {0x7f02ce24};
const u32 var7f1a89e8[] = {0x7f02ce24};
const u32 var7f1a89ec[] = {0x7f02ce24};
const u32 var7f1a89f0[] = {0x7f02ce24};
const u32 var7f1a89f4[] = {0x7f02ce24};
const u32 var7f1a89f8[] = {0x7f02ce1c};
const u32 var7f1a89fc[] = {0x7f02ce24};
const u32 var7f1a8a00[] = {0x7f02ce24};
const u32 var7f1a8a04[] = {0x7f02ce24};
const u32 var7f1a8a08[] = {0x7f02ce24};
const u32 var7f1a8a0c[] = {0x7f02ce04};
const u32 var7f1a8a10[] = {0x7f02ce24};
const u32 var7f1a8a14[] = {0x7f02ce24};
const u32 var7f1a8a18[] = {0x7f02ce24};
const u32 var7f1a8a1c[] = {0x7f02ce24};
const u32 var7f1a8a20[] = {0x7f02ce24};
const u32 var7f1a8a24[] = {0x7f02ce24};
const u32 var7f1a8a28[] = {0x7f02ce24};
const u32 var7f1a8a2c[] = {0x7f02ce24};
const u32 var7f1a8a30[] = {0x7f02ce24};
const u32 var7f1a8a34[] = {0x7f02ce24};
const u32 var7f1a8a38[] = {0x7f02ce24};
const u32 var7f1a8a3c[] = {0x7f02ce24};
const u32 var7f1a8a40[] = {0x7f02ce24};
const u32 var7f1a8a44[] = {0x7f02ce24};
const u32 var7f1a8a48[] = {0x7f02ce24};
const u32 var7f1a8a4c[] = {0x7f02ce24};
const u32 var7f1a8a50[] = {0x7f02ce24};
const u32 var7f1a8a54[] = {0x7f02ce24};
const u32 var7f1a8a58[] = {0x7f02ce24};
const u32 var7f1a8a5c[] = {0x7f02ce24};
const u32 var7f1a8a60[] = {0x7f02ce24};
const u32 var7f1a8a64[] = {0x7f02ce24};
const u32 var7f1a8a68[] = {0x7f02ce24};
const u32 var7f1a8a6c[] = {0x7f02ce04};
const u32 var7f1a8a70[] = {0x3dccccce};
const u32 var7f1a8a74[] = {0x3f4ccccd};
const u32 var7f1a8a78[] = {0x3d4ccccd};
const u32 var7f1a8a7c[] = {0x3ecccccd};
const u32 var7f1a8a80[] = {0x3ecccccd};
const u32 var7f1a8a84[] = {0x3dcccccd};
const u32 var7f1a8a88[] = {0x7f02de50};
const u32 var7f1a8a8c[] = {0x7f02de40};
const u32 var7f1a8a90[] = {0x7f02de68};
const u32 var7f1a8a94[] = {0x7f02de48};
const u32 var7f1a8a98[] = {0x7f02de60};
const u32 var7f1a8a9c[] = {0x7f02de58};
const u32 var7f1a8aa0[] = {0x7f02de94};
const u32 var7f1a8aa4[] = {0x7f02dea8};
const u32 var7f1a8aa8[] = {0x7f02dea4};
const u32 var7f1a8aac[] = {0x7f02de8c};
const u32 var7f1a8ab0[] = {0x7f02de9c};
const u32 var7f1a8ab4[] = {0x7f02dea8};
const u32 var7f1a8ab8[] = {0x00000000};
const u32 var7f1a8abc[] = {0x00000000};

const char var7f1a8ac0[] = "chraction.c";
const char var7f1a8acc[] = "chraction.c";
const char var7f1a8ad8[] = "chraction.c";
const char var7f1a8ae4[] = "aimadjust=%d";
const char var7f1a8af4[] = "chraction.c";
const char var7f1a8b00[] = "firing(%d) %d, beam(%d) %s";
const char var7f1a8b1c[] = "on";
const char var7f1a8b20[] = "off";
const char var7f1a8b24[] = "firecount(%d) = %d";
const char var7f1a8b38[] = "numshots(%d) = %d";
const char var7f1a8b4c[] = "Current dangerous items:";
const char var7f1a8b68[] = "    Grenade %x";
const char var7f1a8b78[] = "    Explosion %x";
const char var7f1a8b8c[] = "misc dangerous prop";
const char var7f1a8ba0[] = "chraction.c";
const char var7f1a8bac[] = "chraction.c";
const char var7f1a8bb8[] = "chraction.c";
const char var7f1a8bc4[] = "chraction.c";
const char var7f1a8bd0[] = "chraction.c";
const char var7f1a8bdc[] = "chraction.c";
const char var7f1a8be8[] = "CHARS -> FRAMETIMESCALEI(240)  = %d";
const char var7f1a8c0c[] = "CHARS -> numseenbond1      \t= %d/%d";
const char var7f1a8c30[] = "CHARS -> numseenbond2      \t= %d/%d";
const char var7f1a8c54[] = "CHARS -> numseenbond3      \t= %d/%d";
const char var7f1a8c78[] = "CHARS -> numseenbond       \t= %d/%d";
const char var7f1a8c9c[] = "CHARS -> DEAD = %d/%d";
const char var7f1a8cb4[] = "chrdisttopad : %x -> %d : Dist=%f";
const char var7f1a8cd8[] = "chraction.c";
const char var7f1a8ce4[] = "chraction.c";

const u32 var7f1a8cf0[] = {0x3c23d70a};
const u32 var7f1a8cf4[] = {0x3c23d70a};
const u32 var7f1a8cf8[] = {0x38c907a9};
const u32 var7f1a8cfc[] = {0x40c907a9};
const u32 var7f1a8d00[] = {0x46230028};
const u32 var7f1a8d04[] = {0x3f19999a};
const u32 var7f1a8d08[] = {0x3e32b17a};
const u32 var7f1a8d0c[] = {0x40c3721d};
const u32 var7f1a8d10[] = {0x40c907a9};
const u32 var7f1a8d14[] = {0x40a30028};
const u32 var7f1a8d18[] = {0x40a30028};
const u32 var7f1a8d1c[] = {0x3c23d70a};
const u32 var7f1a8d20[] = {0x3c23d70a};
const u32 var7f1a8d24[] = {0x3fc907a9};
const u32 var7f1a8d28[] = {0x4096c5bf};
const u32 var7f1a8d2c[] = {0x40c907a9};
const u32 var7f1a8d30[] = {0x405432c1};
const u32 var7f1a8d34[] = {0x403ddc91};
const u32 var7f1a8d38[] = {0x4016c5bf};
const u32 var7f1a8d3c[] = {0x407b4993};
const u32 var7f1a8d40[] = {0x4016c5bf};
const u32 var7f1a8d44[] = {0x407b4993};
const u32 var7f1a8d48[] = {0x4016c5bf};
const u32 var7f1a8d4c[] = {0x407b4993};
const u32 var7f1a8d50[] = {0x40c907a9};
const u32 var7f1a8d54[] = {0x3fa30028};
const u32 var7f1a8d58[] = {0x3c23d70a};
const u32 var7f1a8d5c[] = {0x3c23d70a};
const u32 var7f1a8d60[] = {0x471c4000};
const u32 var7f1a8d64[] = {0x481c4000};
const u32 var7f1a8d68[] = {0x491c4000};
const u32 var7f1a8d6c[] = {0x4a1c4000};
const u32 var7f1a8d70[] = {0x4006051b};
const u32 var7f1a8d74[] = {0x4086051c};
const u32 var7f1a8d78[] = {0x3f86051b};
const u32 var7f1a8d7c[] = {0x40a78662};
const u32 var7f1a8d80[] = {0x3ecccccd};
const u32 var7f1a8d84[] = {0x4006051b};
const u32 var7f1a8d88[] = {0x4086051c};
const u32 var7f1a8d8c[] = {0x3f333333};
const u32 var7f1a8d90[] = {0x3dcccccd};
const u32 var7f1a8d94[] = {0x3dcccccd};
const u32 var7f1a8d98[] = {0x3dcccccd};
const u32 var7f1a8d9c[] = {0x3f99999a};
const u32 var7f1a8da0[] = {0x3f99999a};
const u32 var7f1a8da4[] = {0x411fffff};
const u32 var7f1a8da8[] = {0x3a83126f};
const u32 var7f1a8dac[] = {0x411ffffe};
const u32 var7f1a8db0[] = {0x3ecccccd};
const u32 var7f1a8db4[] = {0x3ecccccd};
const u32 var7f1a8db8[] = {0x3f266666};
const u32 var7f1a8dbc[] = {0x3ecccccd};
const u32 var7f1a8dc0[] = {0x3ecccccd};
const u32 var7f1a8dc4[] = {0x3ecccccd};
const u32 var7f1a8dc8[] = {0x3ecccccd};
const u32 var7f1a8dcc[] = {0x3f266666};
const u32 var7f1a8dd0[] = {0x3f99999a};
const u32 var7f1a8dd4[] = {0x40c907a9};
const u32 var7f1a8dd8[] = {0x3fdf5dd8};
const u32 var7f1a8ddc[] = {0x40913033};
const u32 var7f1a8de0[] = {0x40c907a9};
const u32 var7f1a8de4[] = {0x461c4000};
const u32 var7f1a8de8[] = {0x3ff5b407};
const u32 var7f1a8dec[] = {0x408b9aa7};
const u32 var7f1a8df0[] = {0x471c4000};
const u32 var7f1a8df4[] = {0x3ff5b407};
const u32 var7f1a8df8[] = {0x408b9aa7};
const u32 var7f1a8dfc[] = {0x3f4907a9};
const u32 var7f1a8e00[] = {0x3af5c28f};
const u32 var7f1a8e04[] = {0x40afe6b4};
const u32 var7f1a8e08[] = {0x40490fdb};
const u32 var7f1a8e0c[] = {0x40c907a9};
const u32 var7f1a8e10[] = {0x4074803c};
const u32 var7f1a8e14[] = {0x7f039a54};
const u32 var7f1a8e18[] = {0x7f039a54};
const u32 var7f1a8e1c[] = {0x7f039a5c};
const u32 var7f1a8e20[] = {0x7f039a54};
const u32 var7f1a8e24[] = {0x7f039a88};
const u32 var7f1a8e28[] = {0x7f039a88};
const u32 var7f1a8e2c[] = {0x7f039a88};
const u32 var7f1a8e30[] = {0x7f039a88};
const u32 var7f1a8e34[] = {0x7f039a88};
const u32 var7f1a8e38[] = {0x7f039a88};
const u32 var7f1a8e3c[] = {0x7f039a88};
const u32 var7f1a8e40[] = {0x7f039a88};
const u32 var7f1a8e44[] = {0x7f039a88};
const u32 var7f1a8e48[] = {0x7f039a88};
const u32 var7f1a8e4c[] = {0x7f039a88};
const u32 var7f1a8e50[] = {0x7f039a88};
const u32 var7f1a8e54[] = {0x7f039a88};
const u32 var7f1a8e58[] = {0x7f039a88};
const u32 var7f1a8e5c[] = {0x7f039a88};
const u32 var7f1a8e60[] = {0x7f039a88};
const u32 var7f1a8e64[] = {0x7f039a88};
const u32 var7f1a8e68[] = {0x7f039a88};
const u32 var7f1a8e6c[] = {0x7f039a88};
const u32 var7f1a8e70[] = {0x7f039a88};
const u32 var7f1a8e74[] = {0x7f039a88};
const u32 var7f1a8e78[] = {0x7f039a88};
const u32 var7f1a8e7c[] = {0x7f039a54};
const u32 var7f1a8e80[] = {0x7f039a54};
const u32 var7f1a8e84[] = {0x7f039a54};
const u32 var7f1a8e88[] = {0x7f039a88};
const u32 var7f1a8e8c[] = {0x7f039a74};
const u32 var7f1a8e90[] = {0x40c907a9};
const u32 var7f1a8e94[] = {0x3f4907a9};
const u32 var7f1a8e98[] = {0x40afe6b4};
const u32 var7f1a8e9c[] = {0x4016c5bf};
const u32 var7f1a8ea0[] = {0x407b4993};
const u32 var7f1a8ea4[] = {0x40c907a9};
const u32 var7f1a8ea8[] = {0x3f4907a9};
const u32 var7f1a8eac[] = {0x40afe6b4};
const u32 var7f1a8eb0[] = {0x4016c5bf};
const u32 var7f1a8eb4[] = {0x407b4993};
const u32 var7f1a8eb8[] = {0x49742400};
const u32 var7f1a8ebc[] = {0x49742400};
const u32 var7f1a8ec0[] = {0x471c4000};
const u32 var7f1a8ec4[] = {0x3c23d70a};
const u32 var7f1a8ec8[] = {0x461c4000};
const u32 var7f1a8ecc[] = {0x3ecccccd};
const u32 var7f1a8ed0[] = {0x3f666666};
const u32 var7f1a8ed4[] = {0x44bb8000};
const u32 var7f1a8ed8[] = {0x3f59999a};
const u32 var7f1a8edc[] = {0x3eb2b17a};
const u32 var7f1a8ee0[] = {0x40bddc91};
const u32 var7f1a8ee4[] = {0x3e32b17a};
const u32 var7f1a8ee8[] = {0x40c3721d};
const u32 var7f1a8eec[] = {0x40c907a9};
const u32 var7f1a8ef0[] = {0x3f4907a9};
const u32 var7f1a8ef4[] = {0x40c907a9};
const u32 var7f1a8ef8[] = {0x40c907a9};
const u32 var7f1a8efc[] = {0x40c907a9};
const u32 var7f1a8f00[] = {0x40c907a9};
const u32 var7f1a8f04[] = {0x3f4907a9};
const u32 var7f1a8f08[] = {0x46230028};
const u32 var7f1a8f0c[] = {0x4a742400};
const u32 var7f1a8f10[] = {0x3c23d70a};
const u32 var7f1a8f14[] = {0x3c23d70a};
const u32 var7f1a8f18[] = {0x3c23d70a};
const u32 var7f1a8f1c[] = {0x3e99999a};
const u32 var7f1a8f20[] = {0x40c907a9};
const u32 var7f1a8f24[] = {0x3c8ef461};
const u32 var7f1a8f28[] = {0x40c907a9};
const u32 var7f1a8f2c[] = {0x40c907a9};
const u32 var7f1a8f30[] = {0x40c907a9};
const u32 var7f1a8f34[] = {0x3d80a8be};
const u32 var7f1a8f38[] = {0x40c907a9};
const u32 var7f1a8f3c[] = {0x40c907a9};
const u32 var7f1a8f40[] = {0x40490fdb};
const u32 var7f1a8f44[] = {0x3d4ccccd};
const u32 var7f1a8f48[] = {0x3ecccccd};
const u32 var7f1a8f4c[] = {0x481c4000};
const u32 var7f1a8f50[] = {0x3dcccccd};
const u32 var7f1a8f54[] = {0x3f0ccccd};
const u32 var7f1a8f58[] = {0x3dcccccd};
const u32 var7f1a8f5c[] = {0x3e19999a};
const u32 var7f1a8f60[] = {0x3dcccccd};
const u32 var7f1a8f64[] = {0x3d4ccccd};
const u32 var7f1a8f68[] = {0x3ccccccd};
const u32 var7f1a8f6c[] = {0x49742400};
const u32 var7f1a8f70[] = {0x3dcccccd};
const u32 var7f1a8f74[] = {0x3d4ccccd};
const u32 var7f1a8f78[] = {0x3f0ccccd};
const u32 var7f1a8f7c[] = {0x3d4ccccd};
const u32 var7f1a8f80[] = {0x3dcccccd};
const u32 var7f1a8f84[] = {0x3f0ccccd};
const u32 var7f1a8f88[] = {0x3dcccccd};
const u32 var7f1a8f8c[] = {0x3e19999a};
const u32 var7f1a8f90[] = {0x3dcccccd};
const u32 var7f1a8f94[] = {0x3d4ccccd};
const u32 var7f1a8f98[] = {0x40490fdb};
const u32 var7f1a8f9c[] = {0x40c907a9};
const u32 var7f1a8fa0[] = {0x49742400};
const u32 var7f1a8fa4[] = {0x40c907a9};
const u32 var7f1a8fa8[] = {0x40c907a9};
const u32 var7f1a8fac[] = {0x40c907a9};
const u32 var7f1a8fb0[] = {0x40c907a9};
const u32 var7f1a8fb4[] = {0x3dd66e92};
const u32 var7f1a8fb8[] = {0x40c907a9};
const u32 var7f1a8fbc[] = {0x40c907a9};
const u32 var7f1a8fc0[] = {0x40c907a9};
const u32 var7f1a8fc4[] = {0x40490fdb};
const u32 var7f1a8fc8[] = {0x40c907a9};
const u32 var7f1a8fcc[] = {0x4a1c4000};
const u32 var7f1a8fd0[] = {0x3c999f74};
const u32 var7f1a8fd4[] = {0x491c4000};
const u32 var7f1a8fd8[] = {0x3d1a1533};
const u32 var7f1a8fdc[] = {0x481c4000};
const u32 var7f1a8fe0[] = {0x3d992a68};
const u32 var7f1a8fe4[] = {0x471c4000};
const u32 var7f1a8fe8[] = {0x3e192a68};
const u32 var7f1a8fec[] = {0x3e80a8be};
const u32 var7f1a8ff0[] = {0x40c907a9};
const u32 var7f1a8ff4[] = {0x40c907a9};
const u32 var7f1a8ff8[] = {0x7f03fc18};
const u32 var7f1a8ffc[] = {0x7f03fc18};
const u32 var7f1a9000[] = {0x7f03fbf8};
const u32 var7f1a9004[] = {0x7f03fbf8};
const u32 var7f1a9008[] = {0x7f03fc18};
const u32 var7f1a900c[] = {0x7f03fc18};
const u32 var7f1a9010[] = {0x7f03fc18};
const u32 var7f1a9014[] = {0x7f03fc18};
const u32 var7f1a9018[] = {0x7f03fc18};
const u32 var7f1a901c[] = {0x7f03fc18};
const u32 var7f1a9020[] = {0x7f03fc18};
const u32 var7f1a9024[] = {0x7f03fc18};
const u32 var7f1a9028[] = {0x7f03fc18};
const u32 var7f1a902c[] = {0x7f03fc18};
const u32 var7f1a9030[] = {0x7f03fc18};
const u32 var7f1a9034[] = {0x7f03fc18};
const u32 var7f1a9038[] = {0x7f03fc18};
const u32 var7f1a903c[] = {0x7f03fc18};
const u32 var7f1a9040[] = {0x7f03fc18};
const u32 var7f1a9044[] = {0x7f03fc08};
const u32 var7f1a9048[] = {0x7f03fc08};
const u32 var7f1a904c[] = {0x7f03fc18};
const u32 var7f1a9050[] = {0x7f03fc18};
const u32 var7f1a9054[] = {0x7f03fc18};
const u32 var7f1a9058[] = {0x7f03fc18};
const u32 var7f1a905c[] = {0x7f03fc18};
const u32 var7f1a9060[] = {0x7f03fc18};
const u32 var7f1a9064[] = {0x7f03fc18};
const u32 var7f1a9068[] = {0x7f03fc18};
const u32 var7f1a906c[] = {0x7f03fc18};
const u32 var7f1a9070[] = {0x7f03fc18};
const u32 var7f1a9074[] = {0x7f03fc18};
const u32 var7f1a9078[] = {0x7f03fc18};
const u32 var7f1a907c[] = {0x7f03fc18};
const u32 var7f1a9080[] = {0x7f03fc18};
const u32 var7f1a9084[] = {0x7f03fc18};
const u32 var7f1a9088[] = {0x7f03fc18};
const u32 var7f1a908c[] = {0x7f03fc18};
const u32 var7f1a9090[] = {0x7f03fc18};
const u32 var7f1a9094[] = {0x7f03fc18};
const u32 var7f1a9098[] = {0x7f03fc18};
const u32 var7f1a909c[] = {0x7f03fc18};
const u32 var7f1a90a0[] = {0x7f03fc18};
const u32 var7f1a90a4[] = {0x3e23d70a};
const u32 var7f1a90a8[] = {0x3dcccccd};
const u32 var7f1a90ac[] = {0x3c23d70a};
const u32 var7f1a90b0[] = {0x41200419};
const u32 var7f1a90b4[] = {0x3f8ccccd};
const u32 var7f1a90b8[] = {0x7f7fffff};
const u32 var7f1a90bc[] = {0x3c23d70a};
const u32 var7f1a90c0[] = {0x3f199999};
const u32 var7f1a90c4[] = {0x411cf5c3};
const u32 var7f1a90c8[] = {0x3d638e39};
const u32 var7f1a90cc[] = {0x481c4000};
const u32 var7f1a90d0[] = {0x3fd55555};
const u32 var7f1a90d4[] = {0x3fd55555};
const u32 var7f1a90d8[] = {0x3fd55555};
const u32 var7f1a90dc[] = {0x461c4000};
const u32 var7f1a90e0[] = {0x7f0419b0};
const u32 var7f1a90e4[] = {0x7f0419b0};
const u32 var7f1a90e8[] = {0x7f0419b0};
const u32 var7f1a90ec[] = {0x7f0419b0};
const u32 var7f1a90f0[] = {0x7f0419b0};
const u32 var7f1a90f4[] = {0x7f0419b0};
const u32 var7f1a90f8[] = {0x7f0419b0};
const u32 var7f1a90fc[] = {0x7f0419b0};
const u32 var7f1a9100[] = {0x7f0419b0};
const u32 var7f1a9104[] = {0x7f0419b0};
const u32 var7f1a9108[] = {0x7f0419b0};
const u32 var7f1a910c[] = {0x7f0419b0};
const u32 var7f1a9110[] = {0x7f0419b0};
const u32 var7f1a9114[] = {0x7f0419b0};
const u32 var7f1a9118[] = {0x7f0419b0};
const u32 var7f1a911c[] = {0x7f0419b0};
const u32 var7f1a9120[] = {0x7f0419b0};
const u32 var7f1a9124[] = {0x7f0419bc};
const u32 var7f1a9128[] = {0x7f0419b0};
const u32 var7f1a912c[] = {0x7f0419b0};
const u32 var7f1a9130[] = {0x7f0419b0};
const u32 var7f1a9134[] = {0x7f0419bc};
const u32 var7f1a9138[] = {0x7f0419bc};
const u32 var7f1a913c[] = {0x7f0419bc};
const u32 var7f1a9140[] = {0x7f0419bc};
const u32 var7f1a9144[] = {0x7f0419bc};
const u32 var7f1a9148[] = {0x7f0419b0};
const u32 var7f1a914c[] = {0x7f0419b0};
const u32 var7f1a9150[] = {0x7f0419bc};
const u32 var7f1a9154[] = {0x7f0419bc};
const u32 var7f1a9158[] = {0x7f0419bc};
const u32 var7f1a915c[] = {0x7f0419bc};
const u32 var7f1a9160[] = {0x7f0419bc};
const u32 var7f1a9164[] = {0x7f0419bc};
const u32 var7f1a9168[] = {0x7f0419b0};
const u32 var7f1a916c[] = {0x7f0419b0};
const u32 var7f1a9170[] = {0x7f0419b0};
const u32 var7f1a9174[] = {0x7f0419b0};
const u32 var7f1a9178[] = {0x7f0419b0};
const u32 var7f1a917c[] = {0x7f0419b0};
const u32 var7f1a9180[] = {0x7f0419b0};
const u32 var7f1a9184[] = {0x7f0419b0};
const u32 var7f1a9188[] = {0x3d2aaaab};
const u32 var7f1a918c[] = {0x40c907a9};
const u32 var7f1a9190[] = {0x3e4ccccd};
const u32 var7f1a9194[] = {0x3f59999a};
const u32 var7f1a9198[] = {0x3e4ccccd};
const u32 var7f1a919c[] = {0x3f59999a};
const u32 var7f1a91a0[] = {0x3e4ccccd};
const u32 var7f1a91a4[] = {0x40c907a9};
const u32 var7f1a91a8[] = {0x3cf5c28f};
const u32 var7f1a91ac[] = {0x3cf5c28f};
const u32 var7f1a91b0[] = {0x3cf5c28f};
const u32 var7f1a91b4[] = {0x3cf5c28f};
const u32 var7f1a91b8[] = {0x404907a9};
const u32 var7f1a91bc[] = {0xbf0624dd};
const u32 var7f1a91c0[] = {0x3f0624dd};
const u32 var7f1a91c4[] = {0x404907a9};
const u32 var7f1a91c8[] = {0xbf0624dd};
const u32 var7f1a91cc[] = {0xbf0624dd};
const u32 var7f1a91d0[] = {0x3f0624dd};
const u32 var7f1a91d4[] = {0x3f0624dd};
const u32 var7f1a91d8[] = {0x3e19999a};
const u32 var7f1a91dc[] = {0x3e19999a};
const u32 var7f1a91e0[] = {0x3e4ccccd};
const u32 var7f1a91e4[] = {0x40c907a9};
const u32 var7f1a91e8[] = {0x40c907a9};
const u32 var7f1a91ec[] = {0x3bab8ba8};
const u32 var7f1a91f0[] = {0x40c907a9};
const u32 var7f1a91f4[] = {0x39a4af08};
const u32 var7f1a91f8[] = {0x404907a9};
const u32 var7f1a91fc[] = {0x3e992a68};
const u32 var7f1a9200[] = {0x3c7510a7};
const u32 var7f1a9204[] = {0x3ec907a9};
const u32 var7f1a9208[] = {0x3ca0d2ee};
const u32 var7f1a920c[] = {0x3fa0d2ee};
const u32 var7f1a9210[] = {0x3dc907a9};
const u32 var7f1a9214[] = {0x3e4907a9};
const u32 var7f1a9218[] = {0x3c7510a7};
const u32 var7f1a921c[] = {0x3ec907a9};
const u32 var7f1a9220[] = {0x3c20d2ee};
const u32 var7f1a9224[] = {0x3fa0d2ee};
const u32 var7f1a9228[] = {0x3d4907a9};
const u32 var7f1a922c[] = {0x3e00a8be};
const u32 var7f1a9230[] = {0x3c20d2ee};
const u32 var7f1a9234[] = {0x3c23d70a};
const u32 var7f1a9238[] = {0x3f733333};
const u32 var7f1a923c[] = {0x3f733333};
const u32 var7f1a9240[] = {0x3f99999a};
const u32 var7f1a9244[] = {0x3f99999a};
const u32 var7f1a9248[] = {0x3f733333};
const u32 var7f1a924c[] = {0x3f733333};
const u32 var7f1a9250[] = {0x3f99999a};
const u32 var7f1a9254[] = {0x3f99999a};
const u32 var7f1a9258[] = {0x3f4907a9};
const u32 var7f1a925c[] = {0x40c907a9};
const u32 var7f1a9260[] = {0x471c4000};
const u32 var7f1a9264[] = {0x404907a9};
const u32 var7f1a9268[] = {0x40c907a9};
const u32 var7f1a926c[] = {0x3fa147ae};
const u32 var7f1a9270[] = {0x3fa147ae};
const u32 var7f1a9274[] = {0x3fa147ae};
const u32 var7f1a9278[] = {0x3f8ccccd};
const u32 var7f1a927c[] = {0x3f8ccccd};
const u32 var7f1a9280[] = {0x3f99999a};
const u32 var7f1a9284[] = {0x3f4907a9};
const u32 var7f1a9288[] = {0x40afe6b4};
const u32 var7f1a928c[] = {0x3f99999a};
const u32 var7f1a9290[] = {0x3f99999a};
const u32 var7f1a9294[] = {0x44098000};
const u32 var7f1a9298[] = {0x40490fdb};
const u32 var7f1a929c[] = {0x7f0480d0};
const u32 var7f1a92a0[] = {0x7f0480e0};
const u32 var7f1a92a4[] = {0x7f0480f0};
const u32 var7f1a92a8[] = {0x7f048100};
const u32 var7f1a92ac[] = {0x7f048150};
const u32 var7f1a92b0[] = {0x7f048110};
const u32 var7f1a92b4[] = {0x7f048120};
const u32 var7f1a92b8[] = {0x7f048160};
const u32 var7f1a92bc[] = {0x7f048170};
const u32 var7f1a92c0[] = {0x7f048180};
const u32 var7f1a92c4[] = {0x7f048130};
const u32 var7f1a92c8[] = {0x7f048140};
const u32 var7f1a92cc[] = {0x7f048190};
const u32 var7f1a92d0[] = {0x7f0481a0};
const u32 var7f1a92d4[] = {0x7f0481b0};
const u32 var7f1a92d8[] = {0x7f0481c0};
const u32 var7f1a92dc[] = {0x7f048278};
const u32 var7f1a92e0[] = {0x7f0481e0};
const u32 var7f1a92e4[] = {0x7f0481f0};
const u32 var7f1a92e8[] = {0x7f048200};
const u32 var7f1a92ec[] = {0x7f048278};
const u32 var7f1a92f0[] = {0x7f0481d0};
const u32 var7f1a92f4[] = {0x7f048278};
const u32 var7f1a92f8[] = {0x7f048210};
const u32 var7f1a92fc[] = {0x7f048278};
const u32 var7f1a9300[] = {0x7f048278};
const u32 var7f1a9304[] = {0x7f048278};
const u32 var7f1a9308[] = {0x7f048278};
const u32 var7f1a930c[] = {0x7f048278};
const u32 var7f1a9310[] = {0x7f048230};
const u32 var7f1a9314[] = {0x7f048240};
const u32 var7f1a9318[] = {0x7f048220};
const u32 var7f1a931c[] = {0x7f048250};
const u32 var7f1a9320[] = {0x7f048260};
const u32 var7f1a9324[] = {0x7f048270};
const u32 var7f1a9328[] = {0x3c8ef461};
const u32 var7f1a932c[] = {0x40c907a9};
const u32 var7f1a9330[] = {0x40c907a9};
const u32 var7f1a9334[] = {0x40c907a9};
const u32 var7f1a9338[] = {0x40c907a9};
const u32 var7f1a933c[] = {0x3cc907a9};
const u32 var7f1a9340[] = {0x40490fdb};
const u32 var7f1a9344[] = {0x40c907a9};
const u32 var7f1a9348[] = {0x40490fdb};
const u32 var7f1a934c[] = {0x3cc907a9};
const u32 var7f1a9350[] = {0x40490fdb};
const u32 var7f1a9354[] = {0x40c907a9};
const u32 var7f1a9358[] = {0x40490fdb};
const u32 var7f1a935c[] = {0x40490fdb};
const u32 var7f1a9360[] = {0x40c907a9};
const u32 var7f1a9364[] = {0x3cc907a9};
const u32 var7f1a9368[] = {0x40490fdb};
const u32 var7f1a936c[] = {0x40c907a9};
const u32 var7f1a9370[] = {0x40490fdb};
const u32 var7f1a9374[] = {0x3cc907a9};
const u32 var7f1a9378[] = {0x40490fdb};
const u32 var7f1a937c[] = {0x40c907a9};
const u32 var7f1a9380[] = {0x40490fdb};

// <chrGetSameFloorDistanceToPad>
const u32 var7f1a9384[] = {0x4cbebc20};
// </chrGetSameFloorDistanceToPad>

// <chrResolveId>
const u32 var7f1a9388[] = {0x7f049960};
const u32 var7f1a938c[] = {0x7f049904};
const u32 var7f1a9390[] = {0x7f049b30};
const u32 var7f1a9394[] = {0x7f0498d0};
const u32 var7f1a9398[] = {0x7f04989c};
const u32 var7f1a939c[] = {0x7f0499b8};
const u32 var7f1a93a0[] = {0x7f049b30};
const u32 var7f1a93a4[] = {0x7f049868};
const u32 var7f1a93a8[] = {0x7f049860};
const u32 var7f1a93ac[] = {0x7f049840};
const u32 var7f1a93b0[] = {0x7f049848};
const u32 var7f1a93b4[] = {0x7f049850};
const u32 var7f1a93b8[] = {0x7f049858};
const u32 var7f1a93bc[] = {0x7f049af0};
const u32 var7f1a93c0[] = {0x7f049ab0};
const u32 var7f1a93c4[] = {0x7f049b30};
const u32 var7f1a93c8[] = {0x7f049a7c};
const u32 var7f1a93cc[] = {0x7f049a48};
const u32 var7f1a93d0[] = {0x7f049b30};
const u32 var7f1a93d4[] = {0x7f049b30};
const u32 var7f1a93d8[] = {0x7f049a14};
// </chrResolveId>

const u32 var7f1a93dc[] = {0x3c888889};
const u32 var7f1a93e0[] = {0x3f4ccccd};
const u32 var7f1a93e4[] = {0x40c907a9};
const u32 var7f1a93e8[] = {0x3fc907a9};
const u32 var7f1a93ec[] = {0x4096c5bf};
const u32 var7f1a93f0[] = {0x404907a9};
const u32 var7f1a93f4[] = {0x3fc907a9};
const u32 var7f1a93f8[] = {0x4096c5bf};
const u32 var7f1a93fc[] = {0x40c907a9};
const u32 var7f1a9400[] = {0x40c907a9};
const u32 var7f1a9404[] = {0x40c907a9};
const u32 var7f1a9408[] = {0x3f4907a9};
const u32 var7f1a940c[] = {0xc7c35000};
const u32 var7f1a9410[] = {0x40c907a9};
const u32 var7f1a9414[] = {0xc7c35000};
const u32 var7f1a9418[] = {0xc7c35000};
const u32 var7f1a941c[] = {0x3f4907a9};
const u32 var7f1a9420[] = {0x411ffffe};
const u32 var7f1a9424[] = {0x40c907a9};
const u32 var7f1a9428[] = {0x40c907a9};
const u32 var7f1a942c[] = {0x3c8ef461};
const u32 var7f1a9430[] = {0x40c907a9};
const u32 var7f1a9434[] = {0x40490fdb};
const u32 var7f1a9438[] = {0x439d8000};
const u32 var7f1a943c[] = {0x40490fdb};
const u32 var7f1a9440[] = {0x3fc90fdb};
const u32 var7f1a9444[] = {0x3fc90fdb};
const u32 var7f1a9448[] = {0x3f19999a};
const u32 var7f1a944c[] = {0x00000000};

const char var7f1a9450[] = " (%d)\n";
const char var7f1a9458[] = " (%d)\n";
const char var7f1a9460[] = "set shot list(void) doesn't work for g_Vars.CommandInfo.truck!\n";
const char var7f1a94a0[] = "set shot list(void) doesn't work for g_Vars.CommandInfo.heli!\n";
const char var7f1a94e0[] = "set shot list(void) doesn't work for g_Vars.CommandInfo.hovercar!\n";
const char var7f1a9524[] = "BOND IN ROOM \n";
const char var7f1a9534[] = "bond not in room \n";
const char var7f1a9548[] = "aTimer%s%s: %f\n";
const char var7f1a9558[] = "";
const char var7f1a955c[] = "";
const char var7f1a9560[] = "bTimer:%s%s %f\n";
const char var7f1a9570[] = "";
const char var7f1a9574[] = "";
const char var7f1a9578[] = "ai_ifbondintank: tank code has been removed.\n";
const char var7f1a95a8[] = "AI_BONDENABLECONTROL\n";
const char var7f1a95c0[] = "ai(void) enery tune on (%d, %d, %d)\n";
const char var7f1a95e8[] = "ai(void) enery tune off (%d)\n";
const char var7f1a9608[] = "%s%sAI_PRINT(void) height = %f ptop =  %f \n\n";
const char var7f1a9638[] = "";
const char var7f1a963c[] = "";
const char var7f1a9640[] = "Preset character = %d, my target = %d \n";
const char var7f1a9668[] = "characters target is %d \n";
const char var7f1a9684[] = "(DGD)chrai.c(void) aiIfChrsTargetIsChr does not support CHR_BOND as chr1!\n";
const char var7f1a96d0[] = "(DGD)chrai.c(void) aiIfChrsTargetIsChr does not support CHR_BOND as chr1!\n";
const char var7f1a971c[] = "DGD(void) (chrai.c) WARNING! attempt to use invalid CHR_PRESET1 - defaulting to JO\n";
const char var7f1a9770[] = "RISK CHECK = %d \n";
const char var7f1a9784[] = "aiIfOpportunityFireJumpF() called with no botdata!\n";
const char var7f1a97b8[] = "TARGET %d PASSED THE DISTANCE 2 TESTS \n";
const char var7f1a97e0[] = "%d I NOTICE THE TARGET %d\n";
const char var7f1a97fc[] = "%d I NOTICE THE TARGET %d\n";
const char var7f1a9818[] = "%d OPPORTUNITY FIRE A CHARACTER = %d \n";
const char var7f1a9840[] = "%d  CANNOT OPPORTUNITY FIRE A TARGET \n";
const char var7f1a9868[] = " RISK CHECK = %d \n";
const char var7f1a987c[] = "dist = %d \n";
const char var7f1a9888[] = "USING VOICE NUMBER %d \n";
const char var7f1a98a0[] = "SETORDERS COMMAND  \n";
const char var7f1a98b8[] = "SQUADRON MEMBER CHR NUMBER = %d \n";
const char var7f1a98dc[] = "DOING DIST CHECK \n";
const char var7f1a98f0[] = "%d SYNCHED WITH A CHARACTER %d \n";
const char var7f1a9914[] = "synched = %d \n";
const char var7f1a9924[] = "LEADER'S GOING TO COVER \n";
const char var7f1a9940[] = "LEADER IS BREAKING COVER \n";
const char var7f1a995c[] = " I AM SAFE TO BREAK COVER \n";
const char var7f1a9978[] = "not safe to break cover \n";
const char var7f1a9994[] = "LEADER IS COVER SEEN \n";
const char var7f1a99ac[] = "LEADER IS FLANKING LEFT \n";
const char var7f1a99c8[] = "LEADER IS FLANKING RIGHT \n";
const char var7f1a99e4[] = "LEADER IS DODGING \n";
const char var7f1a99f8[] = "LEADER IS THROWING GRENADE \n";
const char var7f1a9a18[] = "LEADER HAS SEEN FROM WAIT \n";
const char var7f1a9a34[] = "UNKNOWN LEADER ACTION \n";
const char var7f1a9a4c[] = "ORDERS CARRIED OUT  ";
const char var7f1a9a64[] = "WITHDRAWING!!!!!!!!!!!\n";
const char var7f1a9a7c[] = "CHECKING MY ORDERS  ";
const char var7f1a9a94[] = "ACTING ON MY ORDERS  ";
const char var7f1a9aac[] = "DOING DIST CHECK VS CHAR %d\n";
const char var7f1a9acc[] = "I'm just carrying out my ORDERS \n";
const char var7f1a9af0[] = "SQUAD IS DOING THAT ACTION\n";
const char var7f1a9b0c[] = "SQUAD NOT DOING ACTION\n";
const char var7f1a9b24[] = "g_Vars.CommandInfo.chrdata ->soundtimer = %d, g_Vars.CommandInfo.chrdata->talkgap = %d , soundgap = %d\n";
const char var7f1a9b8c[] = "RESETTING THE LISTENING \n";
const char var7f1a9ba8[] = "couldn't go to cover from danger !\n";
const char var7f1a9bcc[] = "couldn't find cover from danger !\n";
const char var7f1a9bf0[] = "Randnum = %d,    Alarmrandnum = %d \n";
const char var7f1a9c18[] = "IVE FOUND MY PAD %d \n";

GLOBAL_ASM(
glabel func0f01e050
/*  f01e050:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f01e054:	3c0b8008 */ 	lui	$t3,%hi(var8007f0b8)
/*  f01e058:	256bf0b8 */ 	addiu	$t3,$t3,%lo(var8007f0b8)
/*  f01e05c:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f01e060:	afb5001c */ 	sw	$s5,0x1c($sp)
/*  f01e064:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f01e068:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f01e06c:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f01e070:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f01e074:	11c0006d */ 	beqz	$t6,.L0f01e22c
/*  f01e078:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f01e07c:	ad600000 */ 	sw	$zero,0x0($t3)
/*  f01e080:	3c02800a */ 	lui	$v0,%hi(var800a3fc8)
/*  f01e084:	3c017f1b */ 	lui	$at,%hi(var7f1a8680)
/*  f01e088:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f01e08c:	3c14800a */ 	lui	$s4,%hi(var800a3fc0)
/*  f01e090:	3c12800a */ 	lui	$s2,%hi(var800a34d0)
/*  f01e094:	3c0c8008 */ 	lui	$t4,%hi(sparktable)
/*  f01e098:	44807000 */ 	mtc1	$zero,$f14
/*  f01e09c:	24423fc8 */ 	addiu	$v0,$v0,%lo(var800a3fc8)
/*  f01e0a0:	258cec80 */ 	addiu	$t4,$t4,%lo(sparktable)
/*  f01e0a4:	265234d0 */ 	addiu	$s2,$s2,%lo(var800a34d0)
/*  f01e0a8:	26943fc0 */ 	addiu	$s4,$s4,%lo(var800a3fc0)
/*  f01e0ac:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f01e0b0:	c4308680 */ 	lwc1	$f16,%lo(var7f1a8680)($at)
/*  f01e0b4:	00001825 */ 	or	$v1,$zero,$zero
/*  f01e0b8:	2413001c */ 	addiu	$s3,$zero,0x1c
/*  f01e0bc:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f01e0c0:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f01e0c4:	240d0028 */ 	addiu	$t5,$zero,0x28
.L0f01e0c8:
/*  f01e0c8:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f01e0cc:	8c450008 */ 	lw	$a1,0x8($v0)
/*  f01e0d0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f01e0d4:	01ed0019 */ 	multu	$t7,$t5
/*  f01e0d8:	0000c012 */ 	mflo	$t8
/*  f01e0dc:	01982021 */ 	addu	$a0,$t4,$t8
/*  f01e0e0:	94990010 */ 	lhu	$t9,0x10($a0)
/*  f01e0e4:	00b9082a */ 	slt	$at,$a1,$t9
/*  f01e0e8:	14200003 */ 	bnez	$at,.L0f01e0f8
/*  f01e0ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e0f0:	1000004c */ 	beqz	$zero,.L0f01e224
/*  f01e0f4:	ac400008 */ 	sw	$zero,0x8($v0)
.L0f01e0f8:
/*  f01e0f8:	10a0004a */ 	beqz	$a1,.L0f01e224
/*  f01e0fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e100:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f01e104:	00002825 */ 	or	$a1,$zero,$zero
/*  f01e108:	8ea60038 */ 	lw	$a2,0x38($s5)
/*  f01e10c:	15c00002 */ 	bnez	$t6,.L0f01e118
/*  f01e110:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e114:	ad710000 */ 	sw	$s1,0x0($t3)
.L0f01e118:
/*  f01e118:	18c00042 */ 	blez	$a2,.L0f01e224
/*  f01e11c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e120:	8c4a0004 */ 	lw	$t2,0x4($v0)
/*  f01e124:	8c46000c */ 	lw	$a2,0xc($v0)
.L0f01e128:
/*  f01e128:	8c4f0008 */ 	lw	$t7,0x8($v0)
/*  f01e12c:	00004825 */ 	or	$t1,$zero,$zero
/*  f01e130:	00d30019 */ 	multu	$a2,$s3
/*  f01e134:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f01e138:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f01e13c:	0000c812 */ 	mflo	$t9
/*  f01e140:	02594021 */ 	addu	$t0,$s2,$t9
/*  f01e144:	19400032 */ 	blez	$t2,.L0f01e210
/*  f01e148:	01003825 */ 	or	$a3,$t0,$zero
/*  f01e14c:	8cee0018 */ 	lw	$t6,0x18($a3)
.L0f01e150:
/*  f01e150:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f01e154:	2508001c */ 	addiu	$t0,$t0,0x1c
/*  f01e158:	11c00026 */ 	beqz	$t6,.L0f01e1f4
/*  f01e15c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e160:	c4e0000c */ 	lwc1	$f0,0xc($a3)
/*  f01e164:	c4840024 */ 	lwc1	$f4,0x24($a0)
/*  f01e168:	c4e20010 */ 	lwc1	$f2,0x10($a3)
/*  f01e16c:	c4ec0014 */ 	lwc1	$f12,0x14($a3)
/*  f01e170:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f01e174:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f01e178:	e4e8000c */ 	swc1	$f8,0xc($a3)
/*  f01e17c:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f01e180:	c486000c */ 	lwc1	$f6,0xc($a0)
/*  f01e184:	460a1482 */ 	mul.s	$f18,$f2,$f10
/*  f01e188:	46121101 */ 	sub.s	$f4,$f2,$f18
/*  f01e18c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f01e190:	e4e80010 */ 	swc1	$f8,0x10($a3)
/*  f01e194:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f01e198:	c4e20010 */ 	lwc1	$f2,0x10($a3)
/*  f01e19c:	460a6482 */ 	mul.s	$f18,$f12,$f10
/*  f01e1a0:	46027032 */ 	c.eq.s	$f14,$f2
/*  f01e1a4:	46126101 */ 	sub.s	$f4,$f12,$f18
/*  f01e1a8:	45000003 */ 	bc1f	.L0f01e1b8
/*  f01e1ac:	e4e40014 */ 	swc1	$f4,0x14($a3)
/*  f01e1b0:	e4f00010 */ 	swc1	$f16,0x10($a3)
/*  f01e1b4:	c4e20010 */ 	lwc1	$f2,0x10($a3)
.L0f01e1b8:
/*  f01e1b8:	c4e60000 */ 	lwc1	$f6,0x0($a3)
/*  f01e1bc:	c4e8000c */ 	lwc1	$f8,0xc($a3)
/*  f01e1c0:	c4f20004 */ 	lwc1	$f18,0x4($a3)
/*  f01e1c4:	8cef0018 */ 	lw	$t7,0x18($a3)
/*  f01e1c8:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f01e1cc:	c4e80014 */ 	lwc1	$f8,0x14($a3)
/*  f01e1d0:	c4e60008 */ 	lwc1	$f6,0x8($a3)
/*  f01e1d4:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f01e1d8:	e4ea0000 */ 	swc1	$f10,0x0($a3)
/*  f01e1dc:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f01e1e0:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f01e1e4:	e4e40004 */ 	swc1	$f4,0x4($a3)
/*  f01e1e8:	acf80018 */ 	sw	$t8,0x18($a3)
/*  f01e1ec:	e4ea0008 */ 	swc1	$f10,0x8($a3)
/*  f01e1f0:	8c4a0004 */ 	lw	$t2,0x4($v0)
.L0f01e1f4:
/*  f01e1f4:	15140003 */ 	bne	$t0,$s4,.L0f01e204
/*  f01e1f8:	012a082a */ 	slt	$at,$t1,$t2
/*  f01e1fc:	10000002 */ 	beqz	$zero,.L0f01e208
/*  f01e200:	02403825 */ 	or	$a3,$s2,$zero
.L0f01e204:
/*  f01e204:	24e7001c */ 	addiu	$a3,$a3,0x1c
.L0f01e208:
/*  f01e208:	5420ffd1 */ 	bnezl	$at,.L0f01e150
/*  f01e20c:	8cee0018 */ 	lw	$t6,0x18($a3)
.L0f01e210:
/*  f01e210:	8eb90038 */ 	lw	$t9,0x38($s5)
/*  f01e214:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f01e218:	00b9082a */ 	slt	$at,$a1,$t9
/*  f01e21c:	5420ffc2 */ 	bnezl	$at,.L0f01e128
/*  f01e220:	8c46000c */ 	lw	$a2,0xc($v0)
.L0f01e224:
/*  f01e224:	1470ffa8 */ 	bne	$v1,$s0,.L0f01e0c8
/*  f01e228:	24420024 */ 	addiu	$v0,$v0,0x24
.L0f01e22c:
/*  f01e22c:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f01e230:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f01e234:	8fb20010 */ 	lw	$s2,0x10($sp)
/*  f01e238:	8fb30014 */ 	lw	$s3,0x14($sp)
/*  f01e23c:	8fb40018 */ 	lw	$s4,0x18($sp)
/*  f01e240:	8fb5001c */ 	lw	$s5,0x1c($sp)
/*  f01e244:	03e00008 */ 	jr	$ra
/*  f01e248:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f01e24c:	00000000 */ 	sll	$zero,$zero,0x0
);
