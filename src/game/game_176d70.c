#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_000920.h"
#include "game/game_005fd0.h"
#include "game/game_00c490.h"
#include "game/game_015470.h"
#include "game/chr/chr.h"
#include "game/game_0601b0.h"
#include "game/game_066310.h"
#include "game/game_096750.h"
#include "game/game_097a50.h"
#include "game/game_0b0420.h"
#include "game/game_0b28d0.h"
#include "game/game_0d4690.h"
#include "game/game_0dcdb0.h"
#include "game/game_0f09f0.h"
#include "game/game_107fb0.h"
#include "game/game_111600.h"
#include "game/game_115ab0.h"
#include "game/game_11ecf0.h"
#include "game/game_129900.h"
#include "game/pdoptions.h"
#include "game/game_152fa0.h"
#include "game/game_1668e0.h"
#include "game/game_16cfa0.h"
#include "game/game_176d70.h"
#include "game/game_187770.h"
#include "game/game_197600.h"
#include "game/game_1999b0.h"
#include "library/library_0e9d0.h"
#include "library/library_12dc0.h"
#include "library/library_233c0.h"

const char var7f1b7cb0[] = "UM_Make : In\n";
const char var7f1b7cc0[] = "UM_Make : Out\n";
const char var7f1b7cd0[] = "Utils -> ERROR at Line %d of %s\n";
const char var7f1b7cf4[] = "Utils -> UM_fVec3_NormaliseTo - Vec = %s%s (%f,%f,%f)\n";
const char var7f1b7d2c[] = "";
const char var7f1b7d30[] = "";
const char var7f1b7d34[] = "Utils -> Attempt to normalise zeo length vector\n";
const char var7f1b7d68[] = "utils.c";
const char var7f1b7d70[] = "UTILS -> DEBUG ERROR - UM_fVec3_MakeNormalTo - Cant normalise\n";
const char var7f1b7db0[] = "utils.c";
const char var7f1b7db8[] = "UTILS -> DEBUG ERROR - UM_fVec3_MakeNormalTo - Cant normalise\n";
const char var7f1b7df8[] = "utils.c";
const char var7f1b7e00[] = "WARNING - UTILS -> DEBUG - Triangle passed to Planar Poly Test\n";
const char var7f1b7e40[] = "utils.c";
const char var7f1b7e48[] = "utils.c";
const char var7f1b7e50[] = "UM_ZeroRunVerify_U8 - FAILED on item %d\n";

const u32 var7f1b7e7c[] = {0x3a83126f};
const u32 var7f1b7e80[] = {0x00000000};

const char var7f1b7e84[] = "\n";
const char var7f1b7e88[] = "";
const char var7f1b7e8c[] = "";
const char var7f1b7e90[] = "%d%%\n";
const char var7f1b7e98[] = "%d%%\n";
const char var7f1b7ea0[] = "%d%%\n";
const char var7f1b7ea8[] = "Menu99 -> Calling Camera Module Start\n";
const char var7f1b7ed0[] = "Menu99 -> Calling Camera Module Finish\n";
const char var7f1b7ef8[] = "%d\n";
const char var7f1b7efc[] = "%d\n";
const char var7f1b7f00[] = "%d\n";
const char var7f1b7f04[] = "%d\n";
const char var7f1b7f08[] = "%d\n";
const char var7f1b7f0c[] = "%d\n";
const char var7f1b7f10[] = "%d\n";
const char var7f1b7f14[] = "%d\n";
const char var7f1b7f18[] = "%d\n";
const char var7f1b7f1c[] = "%d\n";
const char var7f1b7f20[] = "%dM\n";
const char var7f1b7f28[] = "%dK\n";
const char var7f1b7f30[] = "%d\n";
const char var7f1b7f34[] = "%s%s%.1fkm\n";
const char var7f1b7f40[] = "";
const char var7f1b7f44[] = "";
const char var7f1b7f48[] = "--:--\n";
const char var7f1b7f50[] = "==:==\n";
const char var7f1b7f58[] = "%d:%02d.%02d";
const char var7f1b7f68[] = "%d:%02d:%02d";
const char var7f1b7f78[] = "%s%s%.1f%%";
const char var7f1b7f84[] = "";
const char var7f1b7f88[] = "";
const char var7f1b7f8c[] = "%s%s%.1f";
const char var7f1b7f98[] = "";
const char var7f1b7f9c[] = "";
const char var7f1b7fa0[] = "%s%s%.0f";
const char var7f1b7fac[] = "";
const char var7f1b7fb0[] = "";
const char var7f1b7fb4[] = "%s%s%.1fK";
const char var7f1b7fc0[] = "";
const char var7f1b7fc4[] = "";
const char var7f1b7fc8[] = "%s%s%.0fK";
const char var7f1b7fd4[] = "";
const char var7f1b7fd8[] = "";
const char var7f1b7fdc[] = "%s%s%.1fM";
const char var7f1b7fe8[] = "";
const char var7f1b7fec[] = "";
const char var7f1b7ff0[] = "%s%s%.0fM";
const char var7f1b7ffc[] = "";
const char var7f1b8000[] = "";
const char var7f1b8004[] = "";
const char var7f1b8008[] = "";
const char var7f1b800c[] = "%s%s%.00f%%\n";
const char var7f1b801c[] = "";
const char var7f1b8020[] = "";
const char var7f1b8024[] = "";
const char var7f1b8028[] = "\n";
const char var7f1b802c[] = "%s";
const char var7f1b8030[] = "";
const char var7f1b8034[] = "";
const char var7f1b8038[] = "%d:\n";
const char var7f1b8040[] = "";
const char var7f1b8044[] = "\n";
const char var7f1b8048[] = "%s:\n";
const char var7f1b8050[] = "\n";
const char var7f1b8054[] = "%d\n";
const char var7f1b8058[] = "%d\n";

const u32 var7f1b805c[] = {0x7f179248};
const u32 var7f1b8060[] = {0x7f17935c};
const u32 var7f1b8064[] = {0x7f17927c};
const u32 var7f1b8068[] = {0x7f1793a4};
const u32 var7f1b806c[] = {0x7f1793fc};
const u32 var7f1b8070[] = {0x7f1792cc};
const u32 var7f1b8074[] = {0x7f179310};
const u32 var7f1b8078[] = {0x7f179dd8};
const u32 var7f1b807c[] = {0x7f17a014};
const u32 var7f1b8080[] = {0x7f17a014};
const u32 var7f1b8084[] = {0x7f17a014};
const u32 var7f1b8088[] = {0x7f17a014};
const u32 var7f1b808c[] = {0x7f179f0c};
const u32 var7f1b8090[] = {0x7f179f04};
const u32 var7f1b8094[] = {0x7f17a014};
const u32 var7f1b8098[] = {0x7f17a014};
const u32 var7f1b809c[] = {0x7f17a014};
const u32 var7f1b80a0[] = {0x7f179dec};
const u32 var7f1b80a4[] = {0x7f17a014};
const u32 var7f1b80a8[] = {0x7f179ecc};
const u32 var7f1b80ac[] = {0x7f17a014};
const u32 var7f1b80b0[] = {0x7f179f0c};
const u32 var7f1b80b4[] = {0x7f17a014};
const u32 var7f1b80b8[] = {0x7f17a014};
const u32 var7f1b80bc[] = {0x7f17a014};
const u32 var7f1b80c0[] = {0x7f17a014};
const u32 var7f1b80c4[] = {0x7f17a014};
const u32 var7f1b80c8[] = {0x7f179eac};
const u32 var7f1b80cc[] = {0x3c23d70a};
const u32 var7f1b80d0[] = {0x41033333};
const u32 var7f1b80d4[] = {0xc0833333};
const u32 var7f1b80d8[] = {0xbe4ccccd};
const u32 var7f1b80dc[] = {0x3b03126f};
const u32 var7f1b80e0[] = {0x461c4000};
const u32 var7f1b80e4[] = {0x47c35000};
const u32 var7f1b80e8[] = {0x49742400};
const u32 var7f1b80ec[] = {0x4b189680};
const u32 var7f1b80f0[] = {0x7f17b52c};
const u32 var7f1b80f4[] = {0x7f17b82c};
const u32 var7f1b80f8[] = {0x7f17b82c};
const u32 var7f1b80fc[] = {0x7f17b82c};
const u32 var7f1b8100[] = {0x7f17b82c};
const u32 var7f1b8104[] = {0x7f17b70c};
const u32 var7f1b8108[] = {0x7f17b700};
const u32 var7f1b810c[] = {0x7f17b82c};
const u32 var7f1b8110[] = {0x7f17b82c};
const u32 var7f1b8114[] = {0x7f17b82c};
const u32 var7f1b8118[] = {0x7f17b540};
const u32 var7f1b811c[] = {0x7f17b82c};
const u32 var7f1b8120[] = {0x7f17b70c};
const u32 var7f1b8124[] = {0x7f17b82c};
const u32 var7f1b8128[] = {0x7f17b82c};
const u32 var7f1b812c[] = {0x7f17b82c};
const u32 var7f1b8130[] = {0x7f17b82c};
const u32 var7f1b8134[] = {0x7f17b82c};
const u32 var7f1b8138[] = {0x7f17b82c};
const u32 var7f1b813c[] = {0x7f17b82c};
const u32 var7f1b8140[] = {0x7f17b6e0};
const u32 var7f1b8144[] = {0x3c23d70a};
const u32 var7f1b8148[] = {0xbe99999a};
const u32 var7f1b814c[] = {0x3c23d70a};
const u32 var7f1b8150[] = {0x7f17baec};
const u32 var7f1b8154[] = {0x7f17bcb4};
const u32 var7f1b8158[] = {0x7f17bb1c};
const u32 var7f1b815c[] = {0x7f17bcdc};
const u32 var7f1b8160[] = {0x7f17bd20};
const u32 var7f1b8164[] = {0x7f17bbb4};
const u32 var7f1b8168[] = {0x7f17bca4};
const u32 var7f1b816c[] = {0x7f17be18};
const u32 var7f1b8170[] = {0x7f17be18};
const u32 var7f1b8174[] = {0x7f17be18};
const u32 var7f1b8178[] = {0x7f17be18};
const u32 var7f1b817c[] = {0x7f17be18};
const u32 var7f1b8180[] = {0x7f17be18};
const u32 var7f1b8184[] = {0x7f17be18};
const u32 var7f1b8188[] = {0x7f17be18};
const u32 var7f1b818c[] = {0x7f17bd80};
const u32 var7f1b8190[] = {0x7f17c028};
const u32 var7f1b8194[] = {0x7f17c144};
const u32 var7f1b8198[] = {0x7f17c034};
const u32 var7f1b819c[] = {0x7f17c150};
const u32 var7f1b81a0[] = {0x7f17c164};
const u32 var7f1b81a4[] = {0x7f17c064};
const u32 var7f1b81a8[] = {0x7f17c134};
const u32 var7f1b81ac[] = {0x7f17c71c};
const u32 var7f1b81b0[] = {0x7f17c994};
const u32 var7f1b81b4[] = {0x7f17c750};
const u32 var7f1b81b8[] = {0x7f17c9a0};
const u32 var7f1b81bc[] = {0x7f17c9bc};
const u32 var7f1b81c0[] = {0x7f17c7a4};
const u32 var7f1b81c4[] = {0x7f17c95c};
const u32 var7f1b81c8[] = {0x7f17ca1c};
const u32 var7f1b81cc[] = {0x7f17ca1c};
const u32 var7f1b81d0[] = {0x7f17ca1c};
const u32 var7f1b81d4[] = {0x7f17ca1c};
const u32 var7f1b81d8[] = {0x7f17ca1c};
const u32 var7f1b81dc[] = {0x7f17ca1c};
const u32 var7f1b81e0[] = {0x7f17ca1c};
const u32 var7f1b81e4[] = {0x7f17ca1c};
const u32 var7f1b81e8[] = {0x7f17c8f4};
const u32 var7f1b81ec[] = {0x7f17dcb4};
const u32 var7f1b81f0[] = {0x7f17df60};
const u32 var7f1b81f4[] = {0x7f17dcf0};
const u32 var7f1b81f8[] = {0x7f17df60};
const u32 var7f1b81fc[] = {0x7f17df60};
const u32 var7f1b8200[] = {0x7f17dd90};
const u32 var7f1b8204[] = {0x7f17dea0};
const u32 var7f1b8208[] = {0x7f17df60};
const u32 var7f1b820c[] = {0x7f17df60};
const u32 var7f1b8210[] = {0x7f17df60};
const u32 var7f1b8214[] = {0x7f17df60};
const u32 var7f1b8218[] = {0x7f17df60};
const u32 var7f1b821c[] = {0x7f17df60};
const u32 var7f1b8220[] = {0x7f17df20};
const u32 var7f1b8224[] = {0x7f17df60};
const u32 var7f1b8228[] = {0x7f17deec};
const u32 var7f1b822c[] = {0x7f17e540};
const u32 var7f1b8230[] = {0x7f17e600};
const u32 var7f1b8234[] = {0x7f17e9a8};
const u32 var7f1b8238[] = {0x7f17e608};
const u32 var7f1b823c[] = {0x7f17e610};
const u32 var7f1b8240[] = {0x7f17e550};
const u32 var7f1b8244[] = {0x7f17e5f0};
const u32 var7f1b8248[] = {0x7f17e9a8};
const u32 var7f1b824c[] = {0x7f17e9a8};
const u32 var7f1b8250[] = {0x7f17e9a8};
const u32 var7f1b8254[] = {0x7f17e9a8};
const u32 var7f1b8258[] = {0x7f17e9a8};
const u32 var7f1b825c[] = {0x7f17e9a8};
const u32 var7f1b8260[] = {0x7f17e9a8};
const u32 var7f1b8264[] = {0x7f17e9a8};
const u32 var7f1b8268[] = {0x7f17e9a8};
const u32 var7f1b826c[] = {0x7f17e9a8};
const u32 var7f1b8270[] = {0x7f17e9a8};
const u32 var7f1b8274[] = {0x7f17e618};
const u32 var7f1b8278[] = {0x7f17e9a0};
const u32 var7f1b827c[] = {0x7f17e9a8};
const u32 var7f1b8280[] = {0x7f17e9a8};
const u32 var7f1b8284[] = {0x7f17e9a8};
const u32 var7f1b8288[] = {0x7f17e524};
const u32 var7f1b828c[] = {0x7f17f160};
const u32 var7f1b8290[] = {0x7f17f17c};
const u32 var7f1b8294[] = {0x7f17f198};
const u32 var7f1b8298[] = {0x7f17f1e0};
const u32 var7f1b829c[] = {0x7f17f218};
const u32 var7f1b82a0[] = {0x7f17f400};
const u32 var7f1b82a4[] = {0x7f17f2b8};
const u32 var7f1b82a8[] = {0x7f17f400};
const u32 var7f1b82ac[] = {0x7f17f304};
const u32 var7f1b82b0[] = {0x7f17f370};
const u32 var7f1b82b4[] = {0x7f17f520};
const u32 var7f1b82b8[] = {0x7f17f598};
const u32 var7f1b82bc[] = {0x7f17f52c};
const u32 var7f1b82c0[] = {0x7f17f598};
const u32 var7f1b82c4[] = {0x7f17f598};
const u32 var7f1b82c8[] = {0x7f17f54c};
const u32 var7f1b82cc[] = {0x7f17f564};
const u32 var7f1b82d0[] = {0x7f17f598};
const u32 var7f1b82d4[] = {0x7f17f598};
const u32 var7f1b82d8[] = {0x7f17f598};
const u32 var7f1b82dc[] = {0x7f17f598};
const u32 var7f1b82e0[] = {0x7f17f598};
const u32 var7f1b82e4[] = {0x7f17f598};
const u32 var7f1b82e8[] = {0x7f17f598};
const u32 var7f1b82ec[] = {0x7f17f598};
const u32 var7f1b82f0[] = {0x7f17f598};
const u32 var7f1b82f4[] = {0x7f17f598};
const u32 var7f1b82f8[] = {0x7f17f598};
const u32 var7f1b82fc[] = {0x7f17f598};
const u32 var7f1b8300[] = {0x7f17f598};
const u32 var7f1b8304[] = {0x7f17f598};
const u32 var7f1b8308[] = {0x7f17f598};
const u32 var7f1b830c[] = {0x7f17f598};
const u32 var7f1b8310[] = {0x7f17f57c};
const u32 var7f1b8314[] = {0x7f17f5d8};
const u32 var7f1b8318[] = {0x7f17f678};
const u32 var7f1b831c[] = {0x7f17f604};
const u32 var7f1b8320[] = {0x7f17f678};
const u32 var7f1b8324[] = {0x7f17f678};
const u32 var7f1b8328[] = {0x7f17f62c};
const u32 var7f1b832c[] = {0x7f17f640};
const u32 var7f1b8330[] = {0x7f17f678};
const u32 var7f1b8334[] = {0x7f17f678};
const u32 var7f1b8338[] = {0x7f17f678};
const u32 var7f1b833c[] = {0x7f17f678};
const u32 var7f1b8340[] = {0x7f17f678};
const u32 var7f1b8344[] = {0x7f17f678};
const u32 var7f1b8348[] = {0x7f17f678};
const u32 var7f1b834c[] = {0x7f17f678};
const u32 var7f1b8350[] = {0x7f17f678};
const u32 var7f1b8354[] = {0x7f17f678};
const u32 var7f1b8358[] = {0x7f17f678};
const u32 var7f1b835c[] = {0x7f17f678};
const u32 var7f1b8360[] = {0x7f17f678};
const u32 var7f1b8364[] = {0x7f17f678};
const u32 var7f1b8368[] = {0x7f17f678};
const u32 var7f1b836c[] = {0x7f17f678};
const u32 var7f1b8370[] = {0x7f17f654};
const u32 var7f1b8374[] = {0x7f17f6c0};
const u32 var7f1b8378[] = {0x7f17f738};
const u32 var7f1b837c[] = {0x7f17f6cc};
const u32 var7f1b8380[] = {0x7f17f738};
const u32 var7f1b8384[] = {0x7f17f738};
const u32 var7f1b8388[] = {0x7f17f6f4};
const u32 var7f1b838c[] = {0x7f17f708};
const u32 var7f1b8390[] = {0x7f17f738};
const u32 var7f1b8394[] = {0x7f17f738};
const u32 var7f1b8398[] = {0x7f17f738};
const u32 var7f1b839c[] = {0x7f17f738};
const u32 var7f1b83a0[] = {0x7f17f738};
const u32 var7f1b83a4[] = {0x7f17f738};
const u32 var7f1b83a8[] = {0x7f17f738};
const u32 var7f1b83ac[] = {0x7f17f738};
const u32 var7f1b83b0[] = {0x7f17f738};
const u32 var7f1b83b4[] = {0x7f17f738};
const u32 var7f1b83b8[] = {0x7f17f738};
const u32 var7f1b83bc[] = {0x7f17f738};
const u32 var7f1b83c0[] = {0x7f17f738};
const u32 var7f1b83c4[] = {0x7f17f738};
const u32 var7f1b83c8[] = {0x7f17f738};
const u32 var7f1b83cc[] = {0x7f17f738};
const u32 var7f1b83d0[] = {0x7f17f71c};
const u32 var7f1b83d4[] = {0x7f17f798};
const u32 var7f1b83d8[] = {0x7f17f86c};
const u32 var7f1b83dc[] = {0x7f17f7cc};
const u32 var7f1b83e0[] = {0x7f17f86c};
const u32 var7f1b83e4[] = {0x7f17f86c};
const u32 var7f1b83e8[] = {0x7f17f820};
const u32 var7f1b83ec[] = {0x7f17f830};
const u32 var7f1b83f0[] = {0x7f17f86c};
const u32 var7f1b83f4[] = {0x7f17f86c};
const u32 var7f1b83f8[] = {0x7f17f86c};
const u32 var7f1b83fc[] = {0x7f17f86c};
const u32 var7f1b8400[] = {0x7f17f86c};
const u32 var7f1b8404[] = {0x7f17f86c};
const u32 var7f1b8408[] = {0x7f17f86c};
const u32 var7f1b840c[] = {0x7f17f86c};
const u32 var7f1b8410[] = {0x7f17f86c};
const u32 var7f1b8414[] = {0x7f17f86c};
const u32 var7f1b8418[] = {0x7f17f86c};
const u32 var7f1b841c[] = {0x7f17f86c};
const u32 var7f1b8420[] = {0x7f17f86c};
const u32 var7f1b8424[] = {0x7f17f86c};
const u32 var7f1b8428[] = {0x7f17f86c};
const u32 var7f1b842c[] = {0x7f17f86c};
const u32 var7f1b8430[] = {0x7f17f840};
const u32 var7f1b8434[] = {0x00000000};
const u32 var7f1b8438[] = {0x00000000};
const u32 var7f1b843c[] = {0x00000000};

const char var7f1b8440[] = "CaptureTheBriefcaseAddBankPad -> Adding New Pad %d  - Pad Id = %d-> Saving Pad\n";
const char var7f1b8490[] = "%d:%02d";
const char var7f1b8498[] = "%d:%02d";
const char var7f1b84a0[] = "%02d";
const char var7f1b84a8[] = "HackThatMacAddBankPad -> Adding New Pad %d  - Pad Id = %d-> Saving Pad\n";
const char var7f1b84f0[] = "HackThatMacReset -> Working\n";
const char var7f1b8510[] = "HackThatMacInitProps -> Start : %d Bank Pads\n";
const char var7f1b8540[] = "HackThatMacInitProps -> Adding prop %d (%x)\n";
const char var7f1b8570[] = "HackThatMacInitProps -> Mid : %d Bank Pads\n";
const char var7f1b859c[] = "HackThatMacInitProps -> Generating %d random box pads from %d in the bank\n";
const char var7f1b85e8[] = "HackThatMacInitProps -> %d/%d Random box pads generated - Listing\n";
const char var7f1b862c[] = "Pad %d -> Pad Id = %d\n";
const char var7f1b8644[] = "HackThatMacInitProps -> Building and adding custom prop %d - Pad=%d, Ptr=%08x\n";
const char var7f1b8694[] = "HackThatMacInitProps -> End\n";
const char var7f1b86b4[] = "HTM : Player %d - Term Pos = (%d,%d,%d)";
const char var7f1b86dc[] = "HTM : Player %d - Play Pos = (%d,%d,%d)";
const char var7f1b8704[] = "HTM : Player %d - T/P  Rel = (%d,%d,%d)";
const char var7f1b872c[] = "HTM : Player %d - Range XZ = %d";
const char var7f1b874c[] = "HTM : Player %d - Range Y  = %d";
const char var7f1b876c[] = "HTM : Player %d - Angle XZ = %d";
const char var7f1b878c[] = "HTM : Player %d - Dwnld Plr=%d, Dwnld Prop=%d\n";
const char var7f1b87bc[] = "HTM : Player %d - Download Time = %d";
const char var7f1b87e4[] = "PopACapReset -> num_mplayers=%d : Working\n";
const char var7f1b8810[] = "PopACapReset -> Generated %d victims for this game : Listing\n";
const char var7f1b8850[] = "PopACapReset -> Victim %d is player %d\n";
const char var7f1b8878[] = "PopACapReset -> Done\n";
const char var7f1b8890[] = "PopACapTick : Current Victim = %d (Player %d)\n";
const char var7f1b88c0[] = "%d:%02d";
const char var7f1b88c8[] = "%s\n";
const char var7f1b88cc[] = "%s\n";
const char var7f1b88d0[] = "%s:\n";
const char var7f1b88d8[] = "%s\n";

const u32 var7f1b88dc[] = {0x7f17febc};
const u32 var7f1b88e0[] = {0x7f17ff6c};
const u32 var7f1b88e4[] = {0x7f17fec8};
const u32 var7f1b88e8[] = {0x7f17ff6c};
const u32 var7f1b88ec[] = {0x7f17ff6c};
const u32 var7f1b88f0[] = {0x7f17fee4};
const u32 var7f1b88f4[] = {0x7f17ff34};
const u32 var7f1b88f8[] = {0x7f17ff6c};
const u32 var7f1b88fc[] = {0x7f17ff6c};
const u32 var7f1b8900[] = {0x7f17ff6c};
const u32 var7f1b8904[] = {0x7f17ff6c};
const u32 var7f1b8908[] = {0x7f17fe9c};
const u32 var7f1b890c[] = {0x7f17ff6c};
const u32 var7f1b8910[] = {0x7f17ff6c};
const u32 var7f1b8914[] = {0x7f17ff6c};
const u32 var7f1b8918[] = {0x7f17ff6c};
const u32 var7f1b891c[] = {0x7f17ff6c};
const u32 var7f1b8920[] = {0x7f17ff6c};
const u32 var7f1b8924[] = {0x7f17ff6c};
const u32 var7f1b8928[] = {0x7f17ff6c};
const u32 var7f1b892c[] = {0x7f17ff6c};
const u32 var7f1b8930[] = {0x7f17ff6c};
const u32 var7f1b8934[] = {0x7f17ff6c};
const u32 var7f1b8938[] = {0x7f17fe9c};
const u32 var7f1b893c[] = {0x3f733333};
const u32 var7f1b8940[] = {0x3d4ccccd};
const u32 var7f1b8944[] = {0x3f733333};
const u32 var7f1b8948[] = {0x3f733333};
const u32 var7f1b894c[] = {0x3d4ccccd};
const u32 var7f1b8950[] = {0x3d4ccccd};
const u32 var7f1b8954[] = {0x3e4ccccd};
const u32 var7f1b8958[] = {0x40c907a9};
const u32 var7f1b895c[] = {0x42652ee0};
const u32 var7f1b8960[] = {0x42652ee0};
const u32 var7f1b8964[] = {0x7f185110};
const u32 var7f1b8968[] = {0x7f18528c};
const u32 var7f1b896c[] = {0x7f18515c};
const u32 var7f1b8970[] = {0x7f1852c8};
const u32 var7f1b8974[] = {0x7f1852e4};
const u32 var7f1b8978[] = {0x7f1851c4};
const u32 var7f1b897c[] = {0x7f18522c};
const u32 var7f1b8980[] = {0x7f185f14};
const u32 var7f1b8984[] = {0x7f185f14};
const u32 var7f1b8988[] = {0x7f186168};
const u32 var7f1b898c[] = {0x7f186168};
const u32 var7f1b8990[] = {0x7f186168};
const u32 var7f1b8994[] = {0x7f186168};
const u32 var7f1b8998[] = {0x7f186168};
const u32 var7f1b899c[] = {0x7f185f14};
const u32 var7f1b89a0[] = {0x7f186168};
const u32 var7f1b89a4[] = {0x7f186168};
const u32 var7f1b89a8[] = {0x7f186168};
const u32 var7f1b89ac[] = {0x7f186168};
const u32 var7f1b89b0[] = {0x7f186168};
const u32 var7f1b89b4[] = {0x7f185f14};
const u32 var7f1b89b8[] = {0x7f185f14};
const u32 var7f1b89bc[] = {0x7f1862e4};
const u32 var7f1b89c0[] = {0x7f1862d4};
const u32 var7f1b89c4[] = {0x7f1862ec};
const u32 var7f1b89c8[] = {0x7f186254};
const u32 var7f1b89cc[] = {0x7f186260};
const u32 var7f1b89d0[] = {0x7f186320};
const u32 var7f1b89d4[] = {0x7f1863a0};
const u32 var7f1b89d8[] = {0x7f1863a8};
const u32 var7f1b89dc[] = {0x7f1863b0};
const u32 var7f1b89e0[] = {0x7f1863b8};
const u32 var7f1b89e4[] = {0x7f1863c0};
const u32 var7f1b89e8[] = {0x7f1863c8};
const u32 var7f1b89ec[] = {0x7f1863d0};
const u32 var7f1b89f0[] = {0x7f1863d8};
const u32 var7f1b89f4[] = {0x7f186328};
const u32 var7f1b89f8[] = {0x7f186328};
const u32 var7f1b89fc[] = {0x7f186380};

void func0f176d70(s32 arg0)
{
	var800845d8 = arg0;
}

s32 func0f176d7c(void)
{
	return var800845d8;
}

u32 func0f176d88(u32 arg0)
{
	if (arg0 & 3) {
		arg0 = (arg0 & 0xfffffffc) + 4;
	}

	return arg0;
}

u32 func0f176da4(u32 arg0)
{
	if (arg0 & 0xf) {
		arg0 = (arg0 & 0xfffffff0) + 0x10;
	}

	return arg0;
}

u32 func0f176dc0(u32 arg0)
{
	if (arg0 & 0x1f) {
		arg0 = (arg0 & 0xffffffe0) + 0x20;
	}

	return arg0;
}

GLOBAL_ASM(
glabel func0f176ddc
/*  f176ddc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f176de0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f176de4:	24042710 */ 	addiu	$a0,$zero,0x2710
/*  f176de8:	0c0048f2 */ 	jal	func000123c8
/*  f176dec:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f176df0:	3c01800b */ 	lui	$at,0x800b
/*  f176df4:	ac22c0d0 */ 	sw	$v0,-0x3f30($at)
/*  f176df8:	0fc5db69 */ 	jal	func0f176da4
/*  f176dfc:	24043900 */ 	addiu	$a0,$zero,0x3900
/*  f176e00:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f176e04:	00402025 */ 	or	$a0,$v0,$zero
/*  f176e08:	0c0048f2 */ 	jal	func000123c8
/*  f176e0c:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f176e10:	3c05800b */ 	lui	$a1,%hi(var800ac0e8)
/*  f176e14:	24a5c0e8 */ 	addiu	$a1,$a1,%lo(var800ac0e8)
/*  f176e18:	1040000e */ 	beqz	$v0,.L0f176e54
/*  f176e1c:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f176e20:	3c02800b */ 	lui	$v0,%hi(var800ac0e8)
/*  f176e24:	2442c0e8 */ 	addiu	$v0,$v0,%lo(var800ac0e8)
/*  f176e28:	00001825 */ 	or	$v1,$zero,$zero
/*  f176e2c:	24040190 */ 	addiu	$a0,$zero,0x190
.L0f176e30:
/*  f176e30:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f176e34:	0003c100 */ 	sll	$t8,$v1,0x4
/*  f176e38:	24630064 */ 	addiu	$v1,$v1,0x64
/*  f176e3c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f176e40:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f176e44:	1464fffa */ 	bne	$v1,$a0,.L0f176e30
/*  f176e48:	ac59fffc */ 	sw	$t9,-0x4($v0)
/*  f176e4c:	10000009 */ 	beqz	$zero,.L0f176e74
/*  f176e50:	8ca20000 */ 	lw	$v0,0x0($a1)
.L0f176e54:
/*  f176e54:	3c02800b */ 	lui	$v0,%hi(var800ac0e8)
/*  f176e58:	3c03800b */ 	lui	$v1,%hi(var800ac0f8)
/*  f176e5c:	2463c0f8 */ 	addiu	$v1,$v1,%lo(var800ac0f8)
/*  f176e60:	2442c0e8 */ 	addiu	$v0,$v0,%lo(var800ac0e8)
.L0f176e64:
/*  f176e64:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f176e68:	1443fffe */ 	bne	$v0,$v1,.L0f176e64
/*  f176e6c:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f176e70:	8ca20000 */ 	lw	$v0,0x0($a1)
.L0f176e74:
/*  f176e74:	8fa90018 */ 	lw	$t1,0x18($sp)
/*  f176e78:	3c018008 */ 	lui	$at,0x8008
/*  f176e7c:	24481900 */ 	addiu	$t0,$v0,0x1900
/*  f176e80:	ac284610 */ 	sw	$t0,0x4610($at)
/*  f176e84:	00495021 */ 	addu	$t2,$v0,$t1
/*  f176e88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f176e8c:	254bffff */ 	addiu	$t3,$t2,-1
/*  f176e90:	3c018008 */ 	lui	$at,0x8008
/*  f176e94:	3c0c8008 */ 	lui	$t4,0x8008
/*  f176e98:	8d8c4610 */ 	lw	$t4,0x4610($t4)
/*  f176e9c:	ac2b4618 */ 	sw	$t3,0x4618($at)
/*  f176ea0:	3c018008 */ 	lui	$at,0x8008
/*  f176ea4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f176ea8:	03e00008 */ 	jr	$ra
/*  f176eac:	ac2c4614 */ 	sw	$t4,0x4614($at)
/*  f176eb0:	0085001a */ 	div	$zero,$a0,$a1
/*  f176eb4:	00007010 */ 	mfhi	$t6
/*  f176eb8:	14a00002 */ 	bnez	$a1,.L0f176ec4
/*  f176ebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176ec0:	0007000d */ 	break	0x7
.L0f176ec4:
/*  f176ec4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f176ec8:	14a10004 */ 	bne	$a1,$at,.L0f176edc
/*  f176ecc:	3c018000 */ 	lui	$at,0x8000
/*  f176ed0:	14810002 */ 	bne	$a0,$at,.L0f176edc
/*  f176ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176ed8:	0006000d */ 	break	0x6
.L0f176edc:
/*  f176edc:	15c00003 */ 	bnez	$t6,.L0f176eec
/*  f176ee0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176ee4:	03e00008 */ 	jr	$ra
/*  f176ee8:	00801025 */ 	or	$v0,$a0,$zero
.L0f176eec:
/*  f176eec:	0085001a */ 	div	$zero,$a0,$a1
/*  f176ef0:	00007812 */ 	mflo	$t7
/*  f176ef4:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f176ef8:	14a00002 */ 	bnez	$a1,.L0f176f04
/*  f176efc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176f00:	0007000d */ 	break	0x7
.L0f176f04:
/*  f176f04:	2401ffff */ 	addiu	$at,$zero,-1
/*  f176f08:	14a10004 */ 	bne	$a1,$at,.L0f176f1c
/*  f176f0c:	3c018000 */ 	lui	$at,0x8000
/*  f176f10:	14810002 */ 	bne	$a0,$at,.L0f176f1c
/*  f176f14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176f18:	0006000d */ 	break	0x6
.L0f176f1c:
/*  f176f1c:	03050019 */ 	multu	$t8,$a1
/*  f176f20:	00001012 */ 	mflo	$v0
/*  f176f24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176f28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176f2c:	03e00008 */ 	jr	$ra
/*  f176f30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176f34:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f176f38:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f176f3c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f176f40:	e4c80000 */ 	swc1	$f8,0x0($a2)
/*  f176f44:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f176f48:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f176f4c:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f176f50:	e4d20004 */ 	swc1	$f18,0x4($a2)
/*  f176f54:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*  f176f58:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f176f5c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f176f60:	03e00008 */ 	jr	$ra
/*  f176f64:	e4c80008 */ 	swc1	$f8,0x8($a2)
/*  f176f68:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f176f6c:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f176f70:	c4ca0000 */ 	lwc1	$f10,0x0($a2)
/*  f176f74:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f176f78:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f176f7c:	e4f00000 */ 	swc1	$f16,0x0($a3)
/*  f176f80:	c4a40004 */ 	lwc1	$f4,0x4($a1)
/*  f176f84:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f176f88:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*  f176f8c:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f176f90:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f176f94:	e4ea0004 */ 	swc1	$f10,0x4($a3)
/*  f176f98:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f176f9c:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f176fa0:	c4c60008 */ 	lwc1	$f6,0x8($a2)
/*  f176fa4:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f176fa8:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f176fac:	03e00008 */ 	jr	$ra
/*  f176fb0:	e4e80008 */ 	swc1	$f8,0x8($a3)
/*  f176fb4:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f176fb8:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f176fbc:	c4ca0000 */ 	lwc1	$f10,0x0($a2)
/*  f176fc0:	c4f20000 */ 	lwc1	$f18,0x0($a3)
/*  f176fc4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f176fc8:	8fae0010 */ 	lw	$t6,0x10($sp)
/*  f176fcc:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f176fd0:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f176fd4:	e5c40000 */ 	swc1	$f4,0x0($t6)
/*  f176fd8:	c4a80004 */ 	lwc1	$f8,0x4($a1)
/*  f176fdc:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f176fe0:	c4d00004 */ 	lwc1	$f16,0x4($a2)
/*  f176fe4:	c4e40004 */ 	lwc1	$f4,0x4($a3)
/*  f176fe8:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f176fec:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f176ff0:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f176ff4:	e5c60004 */ 	swc1	$f6,0x4($t6)
/*  f176ff8:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f176ffc:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f177000:	c4d20008 */ 	lwc1	$f18,0x8($a2)
/*  f177004:	c4e60008 */ 	lwc1	$f6,0x8($a3)
/*  f177008:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f17700c:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f177010:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f177014:	03e00008 */ 	jr	$ra
/*  f177018:	e5c80008 */ 	swc1	$f8,0x8($t6)
/*  f17701c:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f177020:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f177024:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f177028:	e4c80000 */ 	swc1	$f8,0x0($a2)
/*  f17702c:	c4900004 */ 	lwc1	$f16,0x4($a0)
/*  f177030:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f177034:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f177038:	e4d20004 */ 	swc1	$f18,0x4($a2)
/*  f17703c:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f177040:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f177044:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f177048:	03e00008 */ 	jr	$ra
/*  f17704c:	e4c80008 */ 	swc1	$f8,0x8($a2)
/*  f177050:	44856000 */ 	mtc1	$a1,$f12
/*  f177054:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f177058:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f17705c:	e4c60000 */ 	swc1	$f6,0x0($a2)
/*  f177060:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f177064:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f177068:	e4ca0004 */ 	swc1	$f10,0x4($a2)
/*  f17706c:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f177070:	460c8482 */ 	mul.s	$f18,$f16,$f12
/*  f177074:	03e00008 */ 	jr	$ra
/*  f177078:	e4d20008 */ 	swc1	$f18,0x8($a2)
/*  f17707c:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f177080:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f177084:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f177088:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f17708c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f177090:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f177094:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f177098:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f17709c:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f1770a0:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f1770a4:	03e00008 */ 	jr	$ra
/*  f1770a8:	46102000 */ 	add.s	$f0,$f4,$f16
);

GLOBAL_ASM(
glabel func0f1770ac
/*  f1770ac:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f1770b0:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*  f1770b4:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f1770b8:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f1770bc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f1770c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1770c4:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f1770c8:	46124101 */ 	sub.s	$f4,$f8,$f18
/*  f1770cc:	e4c40000 */ 	swc1	$f4,0x0($a2)
/*  f1770d0:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f1770d4:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f1770d8:	c4b20000 */ 	lwc1	$f18,0x0($a1)
/*  f1770dc:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f1770e0:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f1770e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1770e8:	46124102 */ 	mul.s	$f4,$f8,$f18
/*  f1770ec:	46048181 */ 	sub.s	$f6,$f16,$f4
/*  f1770f0:	46003287 */ 	neg.s	$f10,$f6
/*  f1770f4:	e4ca0004 */ 	swc1	$f10,0x4($a2)
/*  f1770f8:	c4b20004 */ 	lwc1	$f18,0x4($a1)
/*  f1770fc:	c4880000 */ 	lwc1	$f8,0x0($a0)
/*  f177100:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f177104:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f177108:	46124402 */ 	mul.s	$f16,$f8,$f18
/*  f17710c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177110:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f177114:	460a8201 */ 	sub.s	$f8,$f16,$f10
/*  f177118:	03e00008 */ 	jr	$ra
/*  f17711c:	e4c80008 */ 	swc1	$f8,0x8($a2)
/*  f177120:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f177124:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*  f177128:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f17712c:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*  f177130:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f177134:	03e00008 */ 	jr	$ra
/*  f177138:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*  f17713c:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f177140:	46002187 */ 	neg.s	$f6,$f4
/*  f177144:	e4a60000 */ 	swc1	$f6,0x0($a1)
/*  f177148:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f17714c:	46004287 */ 	neg.s	$f10,$f8
/*  f177150:	e4aa0004 */ 	swc1	$f10,0x4($a1)
/*  f177154:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f177158:	46008487 */ 	neg.s	$f18,$f16
/*  f17715c:	03e00008 */ 	jr	$ra
/*  f177160:	e4b20008 */ 	swc1	$f18,0x8($a1)
);

GLOBAL_ASM(
glabel func0f177164
/*  f177164:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f177168:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17716c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f177170:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f177174:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f177178:	c4820004 */ 	lwc1	$f2,0x4($a0)
/*  f17717c:	c48c0008 */ 	lwc1	$f12,0x8($a0)
/*  f177180:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f177184:	3c018008 */ 	lui	$at,0x8008
/*  f177188:	c43045d4 */ 	lwc1	$f16,0x45d4($at)
/*  f17718c:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f177190:	3c038008 */ 	lui	$v1,%hi(var800845f4)
/*  f177194:	246345f4 */ 	addiu	$v1,$v1,%lo(var800845f4)
/*  f177198:	460c6282 */ 	mul.s	$f10,$f12,$f12
/*  f17719c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f1771a0:	460a4380 */ 	add.s	$f14,$f8,$f10
/*  f1771a4:	4610703c */ 	c.lt.s	$f14,$f16
/*  f1771a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1771ac:	4502000a */ 	bc1fl	.L0f1771d8
/*  f1771b0:	46007306 */ 	mov.s	$f12,$f14
/*  f1771b4:	c4720000 */ 	lwc1	$f18,0x0($v1)
/*  f1771b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1771bc:	e4920000 */ 	swc1	$f18,0x0($a0)
/*  f1771c0:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f1771c4:	e4840004 */ 	swc1	$f4,0x4($a0)
/*  f1771c8:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f1771cc:	10000014 */ 	beqz	$zero,.L0f177220
/*  f1771d0:	e4860008 */ 	swc1	$f6,0x8($a0)
/*  f1771d4:	46007306 */ 	mov.s	$f12,$f14
.L0f1771d8:
/*  f1771d8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1771dc:	0c012974 */ 	jal	sqrtf
/*  f1771e0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1771e4:	3c013f80 */ 	lui	$at,0x3f80
/*  f1771e8:	44814000 */ 	mtc1	$at,$f8
/*  f1771ec:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f1771f0:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f1771f4:	46004083 */ 	div.s	$f2,$f8,$f0
/*  f1771f8:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f1771fc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f177200:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f177204:	e4b00000 */ 	swc1	$f16,0x0($a1)
/*  f177208:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f17720c:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f177210:	e4a40004 */ 	swc1	$f4,0x4($a1)
/*  f177214:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f177218:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f17721c:	e4a80008 */ 	swc1	$f8,0x8($a1)
.L0f177220:
/*  f177220:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f177224:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f177228:	03e00008 */ 	jr	$ra
/*  f17722c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177230:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f177234:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f177238:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f17723c:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f177240:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f177244:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f177248:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f17724c:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f177250:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f177254:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f177258:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*  f17725c:	46128301 */ 	sub.s	$f12,$f16,$f18
/*  f177260:	c4d20008 */ 	lwc1	$f18,0x8($a2)
/*  f177264:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f177268:	00001025 */ 	or	$v0,$zero,$zero
/*  f17726c:	46126102 */ 	mul.s	$f4,$f12,$f18
/*  f177270:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f177274:	44803000 */ 	mtc1	$zero,$f6
/*  f177278:	46048200 */ 	add.s	$f8,$f16,$f4
/*  f17727c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f177280:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177284:	45000002 */ 	bc1f	.L0f177290
/*  f177288:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17728c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f177290:
/*  f177290:	03e00008 */ 	jr	$ra
/*  f177294:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177298:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f17729c:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f1772a0:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f1772a4:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f1772a8:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f1772ac:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f1772b0:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f1772b4:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f1772b8:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f1772bc:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f1772c0:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*  f1772c4:	46128301 */ 	sub.s	$f12,$f16,$f18
/*  f1772c8:	c4d20008 */ 	lwc1	$f18,0x8($a2)
/*  f1772cc:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f1772d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1772d4:	46126102 */ 	mul.s	$f4,$f12,$f18
/*  f1772d8:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f1772dc:	44803000 */ 	mtc1	$zero,$f6
/*  f1772e0:	46048200 */ 	add.s	$f8,$f16,$f4
/*  f1772e4:	4606403c */ 	c.lt.s	$f8,$f6
/*  f1772e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1772ec:	45000002 */ 	bc1f	.L0f1772f8
/*  f1772f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1772f4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1772f8:
/*  f1772f8:	03e00008 */ 	jr	$ra
/*  f1772fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177300:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f177304:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f177308:	44807000 */ 	mtc1	$zero,$f14
/*  f17730c:	3c018008 */ 	lui	$at,0x8008
/*  f177310:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f177314:	00001025 */ 	or	$v0,$zero,$zero
/*  f177318:	4600703c */ 	c.lt.s	$f14,$f0
/*  f17731c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177320:	45020004 */ 	bc1fl	.L0f177334
/*  f177324:	46000087 */ 	neg.s	$f2,$f0
/*  f177328:	10000002 */ 	beqz	$zero,.L0f177334
/*  f17732c:	46000086 */ 	mov.s	$f2,$f0
/*  f177330:	46000087 */ 	neg.s	$f2,$f0
.L0f177334:
/*  f177334:	c42c45d4 */ 	lwc1	$f12,0x45d4($at)
/*  f177338:	460c103c */ 	c.lt.s	$f2,$f12
/*  f17733c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177340:	4500001f */ 	bc1f	.L0f1773c0
/*  f177344:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177348:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f17734c:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f177350:	460a4001 */ 	sub.s	$f0,$f8,$f10
/*  f177354:	4600703c */ 	c.lt.s	$f14,$f0
/*  f177358:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17735c:	45020004 */ 	bc1fl	.L0f177370
/*  f177360:	46000087 */ 	neg.s	$f2,$f0
/*  f177364:	10000002 */ 	beqz	$zero,.L0f177370
/*  f177368:	46000086 */ 	mov.s	$f2,$f0
/*  f17736c:	46000087 */ 	neg.s	$f2,$f0
.L0f177370:
/*  f177370:	460c103c */ 	c.lt.s	$f2,$f12
/*  f177374:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177378:	45000011 */ 	bc1f	.L0f1773c0
/*  f17737c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177380:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f177384:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f177388:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f17738c:	4600703c */ 	c.lt.s	$f14,$f0
/*  f177390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177394:	45020004 */ 	bc1fl	.L0f1773a8
/*  f177398:	46000087 */ 	neg.s	$f2,$f0
/*  f17739c:	10000002 */ 	beqz	$zero,.L0f1773a8
/*  f1773a0:	46000086 */ 	mov.s	$f2,$f0
/*  f1773a4:	46000087 */ 	neg.s	$f2,$f0
.L0f1773a8:
/*  f1773a8:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1773ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1773b0:	45000003 */ 	bc1f	.L0f1773c0
/*  f1773b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1773b8:	03e00008 */ 	jr	$ra
/*  f1773bc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1773c0:
/*  f1773c0:	03e00008 */ 	jr	$ra
/*  f1773c4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1773c8
/*  f1773c8:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f1773cc:	c4a20000 */ 	lwc1	$f2,0x0($a1)
/*  f1773d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1773d4:	4602003c */ 	c.lt.s	$f0,$f2
/*  f1773d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1773dc:	4500001e */ 	bc1f	.L0f177458
/*  f1773e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1773e4:	46001107 */ 	neg.s	$f4,$f2
/*  f1773e8:	4600203c */ 	c.lt.s	$f4,$f0
/*  f1773ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1773f0:	45000019 */ 	bc1f	.L0f177458
/*  f1773f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1773f8:	c4800004 */ 	lwc1	$f0,0x4($a0)
/*  f1773fc:	c4a20004 */ 	lwc1	$f2,0x4($a1)
/*  f177400:	4602003c */ 	c.lt.s	$f0,$f2
/*  f177404:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177408:	45000013 */ 	bc1f	.L0f177458
/*  f17740c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177410:	46001187 */ 	neg.s	$f6,$f2
/*  f177414:	4600303c */ 	c.lt.s	$f6,$f0
/*  f177418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17741c:	4500000e */ 	bc1f	.L0f177458
/*  f177420:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177424:	c4800008 */ 	lwc1	$f0,0x8($a0)
/*  f177428:	c4a20008 */ 	lwc1	$f2,0x8($a1)
/*  f17742c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f177430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177434:	45000008 */ 	bc1f	.L0f177458
/*  f177438:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17743c:	46001207 */ 	neg.s	$f8,$f2
/*  f177440:	4600403c */ 	c.lt.s	$f8,$f0
/*  f177444:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177448:	45000003 */ 	bc1f	.L0f177458
/*  f17744c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177450:	03e00008 */ 	jr	$ra
/*  f177454:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f177458:
/*  f177458:	03e00008 */ 	jr	$ra
/*  f17745c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f177460
/*  f177460:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f177464:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f177468:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f17746c:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f177470:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f177474:	c4a80004 */ 	lwc1	$f8,0x4($a1)
/*  f177478:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f17747c:	c4920008 */ 	lwc1	$f18,0x8($a0)
/*  f177480:	c4b00008 */ 	lwc1	$f16,0x8($a1)
/*  f177484:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f177488:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f17748c:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f177490:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f177494:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f177498:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f17749c:	0c012974 */ 	jal	sqrtf
/*  f1774a0:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f1774a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1774a8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1774ac:	03e00008 */ 	jr	$ra
/*  f1774b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1774b4:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f1774b8:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f1774bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1774c0:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f1774c4:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f1774c8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f1774cc:	3c077f1b */ 	lui	$a3,%hi(var7f1b7d68)
/*  f1774d0:	24e77d68 */ 	addiu	$a3,$a3,%lo(var7f1b7d68)
/*  f1774d4:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f1774d8:	0fc5dc59 */ 	jal	func0f177164
/*  f1774dc:	240602be */ 	addiu	$a2,$zero,0x2be
/*  f1774e0:	14400003 */ 	bnez	$v0,.L0f1774f0
/*  f1774e4:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f1774e8:	10000024 */ 	beqz	$zero,.L0f17757c
/*  f1774ec:	00001025 */ 	or	$v0,$zero,$zero
.L0f1774f0:
/*  f1774f0:	3c077f1b */ 	lui	$a3,%hi(var7f1b7db0)
/*  f1774f4:	24e77db0 */ 	addiu	$a3,$a3,%lo(var7f1b7db0)
/*  f1774f8:	27a50028 */ 	addiu	$a1,$sp,0x28
/*  f1774fc:	0fc5dc59 */ 	jal	func0f177164
/*  f177500:	240602c6 */ 	addiu	$a2,$zero,0x2c6
/*  f177504:	14400003 */ 	bnez	$v0,.L0f177514
/*  f177508:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f17750c:	1000001b */ 	beqz	$zero,.L0f17757c
/*  f177510:	00001025 */ 	or	$v0,$zero,$zero
.L0f177514:
/*  f177514:	c7a40034 */ 	lwc1	$f4,0x34($sp)
/*  f177518:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*  f17751c:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*  f177520:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f177524:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f177528:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f17752c:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f177530:	46124400 */ 	add.s	$f16,$f8,$f18
/*  f177534:	c7b20030 */ 	lwc1	$f18,0x30($sp)
/*  f177538:	c7a8003c */ 	lwc1	$f8,0x3c($sp)
/*  f17753c:	46124482 */ 	mul.s	$f18,$f8,$f18
/*  f177540:	46128000 */ 	add.s	$f0,$f16,$f18
/*  f177544:	46000007 */ 	neg.s	$f0,$f0
/*  f177548:	460a0082 */ 	mul.s	$f2,$f0,$f10
/*  f17754c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177550:	46080302 */ 	mul.s	$f12,$f0,$f8
/*  f177554:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177558:	46040402 */ 	mul.s	$f16,$f0,$f4
/*  f17755c:	46103480 */ 	add.s	$f18,$f6,$f16
/*  f177560:	e4720000 */ 	swc1	$f18,0x0($v1)
/*  f177564:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f177568:	46025200 */ 	add.s	$f8,$f10,$f2
/*  f17756c:	e4680004 */ 	swc1	$f8,0x4($v1)
/*  f177570:	c7a40030 */ 	lwc1	$f4,0x30($sp)
/*  f177574:	460c2180 */ 	add.s	$f6,$f4,$f12
/*  f177578:	e4660008 */ 	swc1	$f6,0x8($v1)
.L0f17757c:
/*  f17757c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f177580:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f177584:	03e00008 */ 	jr	$ra
/*  f177588:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17758c:	c4820000 */ 	lwc1	$f2,0x0($a0)
/*  f177590:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f177594:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f177598:	c4a80004 */ 	lwc1	$f8,0x4($a1)
/*  f17759c:	46041001 */ 	sub.s	$f0,$f2,$f4
/*  f1775a0:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f1775a4:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f1775a8:	46083301 */ 	sub.s	$f12,$f6,$f8
/*  f1775ac:	c4c60004 */ 	lwc1	$f6,0x4($a2)
/*  f1775b0:	c4d20000 */ 	lwc1	$f18,0x0($a2)
/*  f1775b4:	46045381 */ 	sub.s	$f14,$f10,$f4
/*  f1775b8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1775bc:	e7a6000c */ 	swc1	$f6,0xc($sp)
/*  f1775c0:	46009282 */ 	mul.s	$f10,$f18,$f0
/*  f1775c4:	c7a4000c */ 	lwc1	$f4,0xc($sp)
/*  f1775c8:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*  f1775cc:	46046182 */ 	mul.s	$f6,$f12,$f4
/*  f1775d0:	e7a80008 */ 	swc1	$f8,0x8($sp)
/*  f1775d4:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f1775d8:	c7aa0008 */ 	lwc1	$f10,0x8($sp)
/*  f1775dc:	460a7182 */ 	mul.s	$f6,$f14,$f10
/*  f1775e0:	46064400 */ 	add.s	$f16,$f8,$f6
/*  f1775e4:	46008207 */ 	neg.s	$f8,$f16
/*  f1775e8:	e7a80004 */ 	swc1	$f8,0x4($sp)
/*  f1775ec:	c7a60004 */ 	lwc1	$f6,0x4($sp)
/*  f1775f0:	46123002 */ 	mul.s	$f0,$f6,$f18
/*  f1775f4:	46001200 */ 	add.s	$f8,$f2,$f0
/*  f1775f8:	46043302 */ 	mul.s	$f12,$f6,$f4
/*  f1775fc:	e4e80000 */ 	swc1	$f8,0x0($a3)
/*  f177600:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f177604:	460a3382 */ 	mul.s	$f14,$f6,$f10
/*  f177608:	460c2180 */ 	add.s	$f6,$f4,$f12
/*  f17760c:	e4e60004 */ 	swc1	$f6,0x4($a3)
/*  f177610:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f177614:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f177618:	460e5200 */ 	add.s	$f8,$f10,$f14
/*  f17761c:	03e00008 */ 	jr	$ra
/*  f177620:	e4e80008 */ 	swc1	$f8,0x8($a3)
/*  f177624:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f177628:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f17762c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f177630:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f177634:	3c077f1b */ 	lui	$a3,%hi(var7f1b7df8)
/*  f177638:	24e77df8 */ 	addiu	$a3,$a3,%lo(var7f1b7df8)
/*  f17763c:	24060303 */ 	addiu	$a2,$zero,0x303
/*  f177640:	0fc5dc59 */ 	jal	func0f177164
/*  f177644:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f177648:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f17764c:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*  f177650:	c4a20008 */ 	lwc1	$f2,0x8($a1)
/*  f177654:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f177658:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17765c:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f177660:	0c012974 */ 	jal	sqrtf
/*  f177664:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f177668:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f17766c:	8fa20020 */ 	lw	$v0,0x20($sp)
/*  f177670:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f177674:	c4a80000 */ 	lwc1	$f8,0x0($a1)
/*  f177678:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f17767c:	44808000 */ 	mtc1	$zero,$f16
/*  f177680:	46004303 */ 	div.s	$f12,$f8,$f0
/*  f177684:	e4500004 */ 	swc1	$f16,0x4($v0)
/*  f177688:	46000207 */ 	neg.s	$f8,$f0
/*  f17768c:	46005083 */ 	div.s	$f2,$f10,$f0
/*  f177690:	46006487 */ 	neg.s	$f18,$f12
/*  f177694:	e4520008 */ 	swc1	$f18,0x8($v0)
/*  f177698:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f17769c:	c4a40004 */ 	lwc1	$f4,0x4($a1)
/*  f1776a0:	e4680004 */ 	swc1	$f8,0x4($v1)
/*  f1776a4:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f1776a8:	e4660000 */ 	swc1	$f6,0x0($v1)
/*  f1776ac:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f1776b0:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f1776b4:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f1776b8:	e4720008 */ 	swc1	$f18,0x8($v1)
/*  f1776bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1776c0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1776c4:	03e00008 */ 	jr	$ra
/*  f1776c8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1776cc
/*  f1776cc:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f1776d0:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f1776d4:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*  f1776d8:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f1776dc:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f1776e0:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f1776e4:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f1776e8:	460a4301 */ 	sub.s	$f12,$f8,$f10
/*  f1776ec:	c4d20008 */ 	lwc1	$f18,0x8($a2)
/*  f1776f0:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f1776f4:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f1776f8:	46049381 */ 	sub.s	$f14,$f18,$f4
/*  f1776fc:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*  f177700:	460a6482 */ 	mul.s	$f18,$f12,$f10
/*  f177704:	3c018008 */ 	lui	$at,0x8008
/*  f177708:	c42045d4 */ 	lwc1	$f0,0x45d4($at)
/*  f17770c:	46067282 */ 	mul.s	$f10,$f14,$f6
/*  f177710:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f177714:	460a2400 */ 	add.s	$f16,$f4,$f10
/*  f177718:	4600803c */ 	c.lt.s	$f16,$f0
/*  f17771c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177720:	45000009 */ 	bc1f	.L0f177748
/*  f177724:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177728:	46000207 */ 	neg.s	$f8,$f0
/*  f17772c:	3c018008 */ 	lui	$at,0x8008
/*  f177730:	4610403c */ 	c.lt.s	$f8,$f16
/*  f177734:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177738:	45000003 */ 	bc1f	.L0f177748
/*  f17773c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177740:	03e00008 */ 	jr	$ra
/*  f177744:	c42045d0 */ 	lwc1	$f0,0x45d0($at)
.L0f177748:
/*  f177748:	46021482 */ 	mul.s	$f18,$f2,$f2
/*  f17774c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177750:	460c6182 */ 	mul.s	$f6,$f12,$f12
/*  f177754:	46069100 */ 	add.s	$f4,$f18,$f6
/*  f177758:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f17775c:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f177760:	46104003 */ 	div.s	$f0,$f8,$f16
/*  f177764:	03e00008 */ 	jr	$ra
/*  f177768:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f17776c
/*  f17776c:	44866000 */ 	mtc1	$a2,$f12
/*  f177770:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f177774:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f177778:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f17777c:	460c2002 */ 	mul.s	$f0,$f4,$f12
/*  f177780:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*  f177784:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f177788:	460c3082 */ 	mul.s	$f2,$f6,$f12
/*  f17778c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177790:	460c4382 */ 	mul.s	$f14,$f8,$f12
/*  f177794:	46005400 */ 	add.s	$f16,$f10,$f0
/*  f177798:	e4f00000 */ 	swc1	$f16,0x0($a3)
/*  f17779c:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f1777a0:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f1777a4:	e4e40004 */ 	swc1	$f4,0x4($a3)
/*  f1777a8:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f1777ac:	460e3200 */ 	add.s	$f8,$f6,$f14
/*  f1777b0:	03e00008 */ 	jr	$ra
/*  f1777b4:	e4e80008 */ 	swc1	$f8,0x8($a3)
/*  f1777b8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1777bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1777c0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1777c4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1777c8:	0fc5ddb3 */ 	jal	func0f1776cc
/*  f1777cc:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f1777d0:	44060000 */ 	mfc1	$a2,$f0
/*  f1777d4:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f1777d8:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f1777dc:	0fc5dddb */ 	jal	func0f17776c
/*  f1777e0:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f1777e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1777e8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1777ec:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1777f0:	03e00008 */ 	jr	$ra
/*  f1777f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1777f8
/*  f1777f8:	3c03800b */ 	lui	$v1,%hi(var800ac0f8)
/*  f1777fc:	3c02800b */ 	lui	$v0,%hi(var800ac108)
/*  f177800:	2442c108 */ 	addiu	$v0,$v0,%lo(var800ac108)
/*  f177804:	2463c0f8 */ 	addiu	$v1,$v1,%lo(var800ac0f8)
.L0f177808:
/*  f177808:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f17780c:	1462fffe */ 	bne	$v1,$v0,.L0f177808
/*  f177810:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f177814:	03e00008 */ 	jr	$ra
/*  f177818:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17781c:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f177820:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f177824:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f177828:	24010003 */ 	addiu	$at,$zero,0x3
/*  f17782c:	00808825 */ 	or	$s1,$a0,$zero
/*  f177830:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f177834:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f177838:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f17783c:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f177840:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f177844:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f177848:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f17784c:	14a10003 */ 	bne	$a1,$at,.L0f17785c
/*  f177850:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f177854:	1000005b */ 	beqz	$zero,.L0f1779c4
/*  f177858:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f17785c:
/*  f17785c:	c624000c */ 	lwc1	$f4,0xc($s1)
/*  f177860:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*  f177864:	27b00060 */ 	addiu	$s0,$sp,0x60
/*  f177868:	02003025 */ 	or	$a2,$s0,$zero
/*  f17786c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f177870:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f177874:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f177878:	e7a80078 */ 	swc1	$f8,0x78($sp)
/*  f17787c:	c6300004 */ 	lwc1	$f16,0x4($s1)
/*  f177880:	c62a0010 */ 	lwc1	$f10,0x10($s1)
/*  f177884:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f177888:	e7b2007c */ 	swc1	$f18,0x7c($sp)
/*  f17788c:	c6260008 */ 	lwc1	$f6,0x8($s1)
/*  f177890:	c6240014 */ 	lwc1	$f4,0x14($s1)
/*  f177894:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f177898:	e7a80080 */ 	swc1	$f8,0x80($sp)
/*  f17789c:	c6300000 */ 	lwc1	$f16,0x0($s1)
/*  f1778a0:	c62a0018 */ 	lwc1	$f10,0x18($s1)
/*  f1778a4:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f1778a8:	e7b2006c */ 	swc1	$f18,0x6c($sp)
/*  f1778ac:	c6260004 */ 	lwc1	$f6,0x4($s1)
/*  f1778b0:	c624001c */ 	lwc1	$f4,0x1c($s1)
/*  f1778b4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f1778b8:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f1778bc:	c6300008 */ 	lwc1	$f16,0x8($s1)
/*  f1778c0:	c62a0020 */ 	lwc1	$f10,0x20($s1)
/*  f1778c4:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f1778c8:	0fc5dc2b */ 	jal	func0f1770ac
/*  f1778cc:	e7b20074 */ 	swc1	$f18,0x74($sp)
/*  f1778d0:	3c077f1b */ 	lui	$a3,%hi(var7f1b7e40)
/*  f1778d4:	24e77e40 */ 	addiu	$a3,$a3,%lo(var7f1b7e40)
/*  f1778d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1778dc:	02002825 */ 	or	$a1,$s0,$zero
/*  f1778e0:	0fc5dc59 */ 	jal	func0f177164
/*  f1778e4:	2406044d */ 	addiu	$a2,$zero,0x44d
/*  f1778e8:	2aa10004 */ 	slti	$at,$s5,0x4
/*  f1778ec:	14200034 */ 	bnez	$at,.L0f1779c0
/*  f1778f0:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f1778f4:	3c017f1b */ 	lui	$at,%hi(var7f1b7e7c)
/*  f1778f8:	3c147f1b */ 	lui	$s4,%hi(var7f1b7e48)
/*  f1778fc:	4480a000 */ 	mtc1	$zero,$f20
/*  f177900:	26947e48 */ 	addiu	$s4,$s4,%lo(var7f1b7e48)
/*  f177904:	c4367e7c */ 	lwc1	$f22,%lo(var7f1b7e7c)($at)
/*  f177908:	26300024 */ 	addiu	$s0,$s1,0x24
/*  f17790c:	27b30050 */ 	addiu	$s3,$sp,0x50
.L0f177910:
/*  f177910:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f177914:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*  f177918:	02602025 */ 	or	$a0,$s3,$zero
/*  f17791c:	02602825 */ 	or	$a1,$s3,$zero
/*  f177920:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f177924:	24060455 */ 	addiu	$a2,$zero,0x455
/*  f177928:	02803825 */ 	or	$a3,$s4,$zero
/*  f17792c:	e7a80050 */ 	swc1	$f8,0x50($sp)
/*  f177930:	c6300004 */ 	lwc1	$f16,0x4($s1)
/*  f177934:	c60a0004 */ 	lwc1	$f10,0x4($s0)
/*  f177938:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f17793c:	e7b20054 */ 	swc1	$f18,0x54($sp)
/*  f177940:	c6260008 */ 	lwc1	$f6,0x8($s1)
/*  f177944:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f177948:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f17794c:	0fc5dc59 */ 	jal	func0f177164
/*  f177950:	e7a80058 */ 	swc1	$f8,0x58($sp)
/*  f177954:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*  f177958:	c7b00060 */ 	lwc1	$f16,0x60($sp)
/*  f17795c:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f177960:	c7a60064 */ 	lwc1	$f6,0x64($sp)
/*  f177964:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f177968:	c7b00058 */ 	lwc1	$f16,0x58($sp)
/*  f17796c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f177970:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f177974:	c7a40068 */ 	lwc1	$f4,0x68($sp)
/*  f177978:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f17797c:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f177980:	46065000 */ 	add.s	$f0,$f10,$f6
/*  f177984:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f177988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17798c:	45020004 */ 	bc1fl	.L0f1779a0
/*  f177990:	46000087 */ 	neg.s	$f2,$f0
/*  f177994:	10000002 */ 	beqz	$zero,.L0f1779a0
/*  f177998:	46000086 */ 	mov.s	$f2,$f0
/*  f17799c:	46000087 */ 	neg.s	$f2,$f0
.L0f1779a0:
/*  f1779a0:	4602b03c */ 	c.lt.s	$f22,$f2
/*  f1779a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1779a8:	45000003 */ 	bc1f	.L0f1779b8
/*  f1779ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1779b0:	10000004 */ 	beqz	$zero,.L0f1779c4
/*  f1779b4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1779b8:
/*  f1779b8:	1655ffd5 */ 	bne	$s2,$s5,.L0f177910
/*  f1779bc:	2610000c */ 	addiu	$s0,$s0,0xc
.L0f1779c0:
/*  f1779c0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1779c4:
/*  f1779c4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1779c8:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f1779cc:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f1779d0:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f1779d4:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f1779d8:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f1779dc:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f1779e0:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f1779e4:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f1779e8:	03e00008 */ 	jr	$ra
/*  f1779ec:	27bd0088 */ 	addiu	$sp,$sp,0x88
/*  f1779f0:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f1779f4:	afa40008 */ 	sw	$a0,0x8($sp)
/*  f1779f8:	afa5000c */ 	sw	$a1,0xc($sp)
/*  f1779fc:	afa60010 */ 	sw	$a2,0x10($sp)
/*  f177a00:	afa70014 */ 	sw	$a3,0x14($sp)
/*  f177a04:	03e00008 */ 	jr	$ra
/*  f177a08:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*  f177a0c:	03e00008 */ 	jr	$ra
/*  f177a10:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f177a14:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f177a18:	afa40008 */ 	sw	$a0,0x8($sp)
/*  f177a1c:	afa5000c */ 	sw	$a1,0xc($sp)
/*  f177a20:	afa60010 */ 	sw	$a2,0x10($sp)
/*  f177a24:	afa70014 */ 	sw	$a3,0x14($sp)
/*  f177a28:	03e00008 */ 	jr	$ra
/*  f177a2c:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*  f177a30:	03e00008 */ 	jr	$ra
/*  f177a34:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f177a38:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f177a3c:	afa40008 */ 	sw	$a0,0x8($sp)
/*  f177a40:	afa5000c */ 	sw	$a1,0xc($sp)
/*  f177a44:	afa60010 */ 	sw	$a2,0x10($sp)
/*  f177a48:	afa70014 */ 	sw	$a3,0x14($sp)
/*  f177a4c:	03e00008 */ 	jr	$ra
/*  f177a50:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0f177a54
/*  f177a54:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f177a58:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f177a5c:	00c08025 */ 	or	$s0,$a2,$zero
/*  f177a60:	00001025 */ 	or	$v0,$zero,$zero
/*  f177a64:	00001825 */ 	or	$v1,$zero,$zero
/*  f177a68:	18a0002d */ 	blez	$a1,.L0f177b20
/*  f177a6c:	00004025 */ 	or	$t0,$zero,$zero
/*  f177a70:	00803025 */ 	or	$a2,$a0,$zero
/*  f177a74:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f177a78:	240b00c8 */ 	addiu	$t3,$zero,0xc8
/*  f177a7c:	240a00ff */ 	addiu	$t2,$zero,0xff
.L0f177a80:
/*  f177a80:	90c40000 */ 	lbu	$a0,0x0($a2)
/*  f177a84:	50800023 */ 	beqzl	$a0,.L0f177b14
/*  f177a88:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f177a8c:	1040001d */ 	beqz	$v0,.L0f177b04
/*  f177a90:	02034821 */ 	addu	$t1,$s0,$v1
/*  f177a94:	00c77023 */ 	subu	$t6,$a2,$a3
/*  f177a98:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*  f177a9c:	55e0001a */ 	bnezl	$t7,.L0f177b08
/*  f177aa0:	a1240000 */ 	sb	$a0,0x0($t1)
/*  f177aa4:	a1200000 */ 	sb	$zero,0x0($t1)
/*  f177aa8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177aac:	150a0007 */ 	bne	$t0,$t2,.L0f177acc
/*  f177ab0:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f177ab4:	a12b0000 */ 	sb	$t3,0x0($t1)
/*  f177ab8:	a1200001 */ 	sb	$zero,0x1($t1)
/*  f177abc:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f177ac0:	25290002 */ 	addiu	$t1,$t1,0x2
/*  f177ac4:	1000000a */ 	beqz	$zero,.L0f177af0
/*  f177ac8:	2508ff38 */ 	addiu	$t0,$t0,-200
.L0f177acc:
/*  f177acc:	29010100 */ 	slti	$at,$t0,0x100
/*  f177ad0:	54200008 */ 	bnezl	$at,.L0f177af4
/*  f177ad4:	a1280000 */ 	sb	$t0,0x0($t1)
.L0f177ad8:
/*  f177ad8:	2508ff01 */ 	addiu	$t0,$t0,-255
/*  f177adc:	29010100 */ 	slti	$at,$t0,0x100
/*  f177ae0:	a12c0000 */ 	sb	$t4,0x0($t1)
/*  f177ae4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177ae8:	1020fffb */ 	beqz	$at,.L0f177ad8
/*  f177aec:	25290001 */ 	addiu	$t1,$t1,0x1
.L0f177af0:
/*  f177af0:	a1280000 */ 	sb	$t0,0x0($t1)
.L0f177af4:
/*  f177af4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177af8:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f177afc:	90c40000 */ 	lbu	$a0,0x0($a2)
/*  f177b00:	00004025 */ 	or	$t0,$zero,$zero
.L0f177b04:
/*  f177b04:	a1240000 */ 	sb	$a0,0x0($t1)
.L0f177b08:
/*  f177b08:	10000002 */ 	beqz	$zero,.L0f177b14
/*  f177b0c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177b10:	25080001 */ 	addiu	$t0,$t0,0x1
.L0f177b14:
/*  f177b14:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f177b18:	1445ffd9 */ 	bne	$v0,$a1,.L0f177a80
/*  f177b1c:	00c73021 */ 	addu	$a2,$a2,$a3
.L0f177b20:
/*  f177b20:	0203c021 */ 	addu	$t8,$s0,$v1
/*  f177b24:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177b28:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f177b2c:	0203c821 */ 	addu	$t9,$s0,$v1
/*  f177b30:	a3200000 */ 	sb	$zero,0x0($t9)
/*  f177b34:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f177b38:	24620001 */ 	addiu	$v0,$v1,0x1
/*  f177b3c:	03e00008 */ 	jr	$ra
/*  f177b40:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*  f177b44:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f177b48:	00803025 */ 	or	$a2,$a0,$zero
/*  f177b4c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f177b50:	14610003 */ 	bne	$v1,$at,.L0f177b60
/*  f177b54:	3c04800b */ 	lui	$a0,0x800b
/*  f177b58:	3c01800b */ 	lui	$at,0x800b
/*  f177b5c:	ac20c108 */ 	sw	$zero,-0x3ef8($at)
.L0f177b60:
/*  f177b60:	8c84c108 */ 	lw	$a0,-0x3ef8($a0)
/*  f177b64:	3c01800b */ 	lui	$at,0x800b
/*  f177b68:	00c43821 */ 	addu	$a3,$a2,$a0
/*  f177b6c:	90ee0000 */ 	lbu	$t6,0x0($a3)
/*  f177b70:	55c0000b */ 	bnezl	$t6,.L0f177ba0
/*  f177b74:	24780001 */ 	addiu	$t8,$v1,0x1
/*  f177b78:	90e20001 */ 	lbu	$v0,0x1($a3)
/*  f177b7c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f177b80:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f177b84:	10400005 */ 	beqz	$v0,.L0f177b9c
/*  f177b88:	00627821 */ 	addu	$t7,$v1,$v0
/*  f177b8c:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f177b90:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f177b94:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f177b98:	01e01825 */ 	or	$v1,$t7,$zero
.L0f177b9c:
/*  f177b9c:	24780001 */ 	addiu	$t8,$v1,0x1
.L0f177ba0:
/*  f177ba0:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f177ba4:	90e20000 */ 	lbu	$v0,0x0($a3)
/*  f177ba8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f177bac:	03e00008 */ 	jr	$ra
/*  f177bb0:	ac24c108 */ 	sw	$a0,-0x3ef8($at)
);

GLOBAL_ASM(
glabel func0f177bb4
/*  f177bb4:	14800003 */ 	bnez	$a0,.L0f177bc4
/*  f177bb8:	00001825 */ 	or	$v1,$zero,$zero
/*  f177bbc:	03e00008 */ 	jr	$ra
/*  f177bc0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f177bc4:
/*  f177bc4:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f177bc8:	3c078008 */ 	lui	$a3,0x8008
/*  f177bcc:	240fffff */ 	addiu	$t7,$zero,-1
/*  f177bd0:	15c00002 */ 	bnez	$t6,.L0f177bdc
/*  f177bd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177bd8:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f177bdc:
/*  f177bdc:	8ce74624 */ 	lw	$a3,0x4624($a3)
/*  f177be0:	3c018008 */ 	lui	$at,0x8008
/*  f177be4:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f177be8:	1ce00022 */ 	bgtz	$a3,.L0f177c74
/*  f177bec:	ac274624 */ 	sw	$a3,0x4624($at)
/*  f177bf0:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f177bf4:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f177bf8:	93080000 */ 	lbu	$t0,0x0($t8)
/*  f177bfc:	24590001 */ 	addiu	$t9,$v0,0x1
/*  f177c00:	03245821 */ 	addu	$t3,$t9,$a0
/*  f177c04:	51000004 */ 	beqzl	$t0,.L0f177c18
/*  f177c08:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f177c0c:	10000017 */ 	beqz	$zero,.L0f177c6c
/*  f177c10:	01001825 */ 	or	$v1,$t0,$zero
/*  f177c14:	acb90000 */ 	sw	$t9,0x0($a1)
.L0f177c18:
/*  f177c18:	91680000 */ 	lbu	$t0,0x0($t3)
/*  f177c1c:	03201025 */ 	or	$v0,$t9,$zero
/*  f177c20:	240a00ff */ 	addiu	$t2,$zero,0xff
/*  f177c24:	1100000f */ 	beqz	$t0,.L0f177c64
/*  f177c28:	00003825 */ 	or	$a3,$zero,$zero
/*  f177c2c:	15480009 */ 	bne	$t2,$t0,.L0f177c54
/*  f177c30:	01004825 */ 	or	$t1,$t0,$zero
/*  f177c34:	244c0001 */ 	addiu	$t4,$v0,0x1
.L0f177c38:
/*  f177c38:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f177c3c:	01846821 */ 	addu	$t5,$t4,$a0
/*  f177c40:	91a90000 */ 	lbu	$t1,0x0($t5)
/*  f177c44:	24e700ff */ 	addiu	$a3,$a3,0xff
/*  f177c48:	01801025 */ 	or	$v0,$t4,$zero
/*  f177c4c:	5149fffa */ 	beql	$t2,$t1,.L0f177c38
/*  f177c50:	244c0001 */ 	addiu	$t4,$v0,0x1
.L0f177c54:
/*  f177c54:	00e93821 */ 	addu	$a3,$a3,$t1
/*  f177c58:	3c018008 */ 	lui	$at,0x8008
/*  f177c5c:	10000003 */ 	beqz	$zero,.L0f177c6c
/*  f177c60:	ac274624 */ 	sw	$a3,0x4624($at)
.L0f177c64:
/*  f177c64:	03e00008 */ 	jr	$ra
/*  f177c68:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f177c6c:
/*  f177c6c:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f177c70:	acae0000 */ 	sw	$t6,0x0($a1)
.L0f177c74:
/*  f177c74:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f177c78:	00601025 */ 	or	$v0,$v1,$zero
/*  f177c7c:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f177c80:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f177c84:	03e00008 */ 	jr	$ra
/*  f177c88:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f177c8c
/*  f177c8c:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f177c90:	240effff */ 	addiu	$t6,$zero,-1
/*  f177c94:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f177c98:	54600004 */ 	bnezl	$v1,.L0f177cac
/*  f177c9c:	00647821 */ 	addu	$t7,$v1,$a0
/*  f177ca0:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f177ca4:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f177ca8:	00647821 */ 	addu	$t7,$v1,$a0
.L0f177cac:
/*  f177cac:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f177cb0:	17000020 */ 	bnez	$t8,.L0f177d34
/*  f177cb4:	24790001 */ 	addiu	$t9,$v1,0x1
.L0f177cb8:
/*  f177cb8:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f177cbc:	03244821 */ 	addu	$t1,$t9,$a0
/*  f177cc0:	91220000 */ 	lbu	$v0,0x0($t1)
/*  f177cc4:	10400014 */ 	beqz	$v0,.L0f177d18
/*  f177cc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177ccc:	14e2000b */ 	bne	$a3,$v0,.L0f177cfc
/*  f177cd0:	00401825 */ 	or	$v1,$v0,$zero
/*  f177cd4:	8cca0000 */ 	lw	$t2,0x0($a2)
.L0f177cd8:
/*  f177cd8:	254b00ff */ 	addiu	$t3,$t2,0xff
/*  f177cdc:	accb0000 */ 	sw	$t3,0x0($a2)
/*  f177ce0:	8cac0000 */ 	lw	$t4,0x0($a1)
/*  f177ce4:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f177ce8:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f177cec:	01a47821 */ 	addu	$t7,$t5,$a0
/*  f177cf0:	91e30000 */ 	lbu	$v1,0x0($t7)
/*  f177cf4:	50e3fff8 */ 	beql	$a3,$v1,.L0f177cd8
/*  f177cf8:	8cca0000 */ 	lw	$t2,0x0($a2)
.L0f177cfc:
/*  f177cfc:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f177d00:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f177d04:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f177d08:	8ca80000 */ 	lw	$t0,0x0($a1)
/*  f177d0c:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f177d10:	10000003 */ 	beqz	$zero,.L0f177d20
/*  f177d14:	aca90000 */ 	sw	$t1,0x0($a1)
.L0f177d18:
/*  f177d18:	03e00008 */ 	jr	$ra
/*  f177d1c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f177d20:
/*  f177d20:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f177d24:	00645021 */ 	addu	$t2,$v1,$a0
/*  f177d28:	914b0000 */ 	lbu	$t3,0x0($t2)
/*  f177d2c:	5160ffe2 */ 	beqzl	$t3,.L0f177cb8
/*  f177d30:	24790001 */ 	addiu	$t9,$v1,0x1
.L0f177d34:
/*  f177d34:	8ccc0000 */ 	lw	$t4,0x0($a2)
/*  f177d38:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f177d3c:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f177d40:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f177d44:	00647021 */ 	addu	$t6,$v1,$a0
/*  f177d48:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f177d4c:	246f0001 */ 	addiu	$t7,$v1,0x1
/*  f177d50:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f177d54:	03e00008 */ 	jr	$ra
/*  f177d58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177d5c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f177d60:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f177d64:	00808825 */ 	or	$s1,$a0,$zero
/*  f177d68:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f177d6c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f177d70:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f177d74:	00a08025 */ 	or	$s0,$a1,$zero
/*  f177d78:	27b20034 */ 	addiu	$s2,$sp,0x34
/*  f177d7c:	27b30030 */ 	addiu	$s3,$sp,0x30
/*  f177d80:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f177d84:	00a02025 */ 	or	$a0,$a1,$zero
/*  f177d88:	02402825 */ 	or	$a1,$s2,$zero
/*  f177d8c:	02603025 */ 	or	$a2,$s3,$zero
/*  f177d90:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f177d94:	0fc5deed */ 	jal	func0f177bb4
/*  f177d98:	afa00030 */ 	sw	$zero,0x30($sp)
/*  f177d9c:	0442000f */ 	bltzl	$v0,.L0f177ddc
/*  f177da0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f177da4:	8fae0030 */ 	lw	$t6,0x30($sp)
.L0f177da8:
/*  f177da8:	02002025 */ 	or	$a0,$s0,$zero
/*  f177dac:	02402825 */ 	or	$a1,$s2,$zero
/*  f177db0:	022e7821 */ 	addu	$t7,$s1,$t6
/*  f177db4:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f177db8:	10580003 */ 	beq	$v0,$t8,.L0f177dc8
/*  f177dbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177dc0:	10000006 */ 	beqz	$zero,.L0f177ddc
/*  f177dc4:	00001025 */ 	or	$v0,$zero,$zero
.L0f177dc8:
/*  f177dc8:	0fc5deed */ 	jal	func0f177bb4
/*  f177dcc:	02603025 */ 	or	$a2,$s3,$zero
/*  f177dd0:	0443fff5 */ 	bgezl	$v0,.L0f177da8
/*  f177dd4:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f177dd8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f177ddc:
/*  f177ddc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f177de0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f177de4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f177de8:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f177dec:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f177df0:	03e00008 */ 	jr	$ra
/*  f177df4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f177df8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177dfc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler00177e00
/*  f177e00:	24010001 */ 	addiu	$at,$zero,0x1
/*  f177e04:	1081000c */ 	beq	$a0,$at,.L0f177e38
/*  f177e08:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f177e0c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f177e10:	1081001b */ 	beq	$a0,$at,.L0f177e80
/*  f177e14:	00001025 */ 	or	$v0,$zero,$zero
/*  f177e18:	24010006 */ 	addiu	$at,$zero,0x6
/*  f177e1c:	1081003d */ 	beq	$a0,$at,.L0f177f14
/*  f177e20:	00001025 */ 	or	$v0,$zero,$zero
/*  f177e24:	24010007 */ 	addiu	$at,$zero,0x7
/*  f177e28:	10810053 */ 	beq	$a0,$at,.L0f177f78
/*  f177e2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f177e30:	10000067 */ 	beqz	$zero,.L0f177fd0
/*  f177e34:	00001025 */ 	or	$v0,$zero,$zero
.L0f177e38:
/*  f177e38:	3c05800b */ 	lui	$a1,%hi(g_MpSetup)
/*  f177e3c:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f177e40:	24a5cb88 */ 	addiu	$a1,$a1,%lo(g_MpSetup)
/*  f177e44:	00001025 */ 	or	$v0,$zero,$zero
/*  f177e48:	2408000c */ 	addiu	$t0,$zero,0xc
/*  f177e4c:	94ae0016 */ 	lhu	$t6,0x16($a1)
.L0f177e50:
/*  f177e50:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f177e54:	004fc004 */ 	sllv	$t8,$t7,$v0
/*  f177e58:	01d8c824 */ 	and	$t9,$t6,$t8
/*  f177e5c:	13200004 */ 	beqz	$t9,.L0f177e70
/*  f177e60:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f177e64:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f177e68:	25af0001 */ 	addiu	$t7,$t5,0x1
/*  f177e6c:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f177e70:
/*  f177e70:	5448fff7 */ 	bnel	$v0,$t0,.L0f177e50
/*  f177e74:	94ae0016 */ 	lhu	$t6,0x16($a1)
/*  f177e78:	10000055 */ 	beqz	$zero,.L0f177fd0
/*  f177e7c:	00001025 */ 	or	$v0,$zero,$zero
.L0f177e80:
/*  f177e80:	3c03800b */ 	lui	$v1,0x800b
/*  f177e84:	3c0b800b */ 	lui	$t3,%hi(g_MpSimulants)
/*  f177e88:	3c09800b */ 	lui	$t1,%hi(g_MpPlayers)
/*  f177e8c:	2529c7b8 */ 	addiu	$t1,$t1,%lo(g_MpPlayers)
/*  f177e90:	256bc538 */ 	addiu	$t3,$t3,%lo(g_MpSimulants)
/*  f177e94:	9463cb9e */ 	lhu	$v1,-0x3462($v1)
/*  f177e98:	00002825 */ 	or	$a1,$zero,$zero
/*  f177e9c:	240c004c */ 	addiu	$t4,$zero,0x4c
/*  f177ea0:	240a00a0 */ 	addiu	$t2,$zero,0xa0
/*  f177ea4:	2408000c */ 	addiu	$t0,$zero,0xc
/*  f177ea8:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f177eac:
/*  f177eac:	00aec004 */ 	sllv	$t8,$t6,$a1
/*  f177eb0:	0078c824 */ 	and	$t9,$v1,$t8
/*  f177eb4:	13200011 */ 	beqz	$t9,.L0f177efc
/*  f177eb8:	28a10004 */ 	slti	$at,$a1,0x4
/*  f177ebc:	10200006 */ 	beqz	$at,.L0f177ed8
/*  f177ec0:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f177ec4:	00aa0019 */ 	multu	$a1,$t2
/*  f177ec8:	00006812 */ 	mflo	$t5
/*  f177ecc:	012d3821 */ 	addu	$a3,$t1,$t5
/*  f177ed0:	10000005 */ 	beqz	$zero,.L0f177ee8
/*  f177ed4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f177ed8:
/*  f177ed8:	00ac0019 */ 	multu	$a1,$t4
/*  f177edc:	00007812 */ 	mflo	$t7
/*  f177ee0:	016f3821 */ 	addu	$a3,$t3,$t7
/*  f177ee4:	24e7fed0 */ 	addiu	$a3,$a3,-304
.L0f177ee8:
/*  f177ee8:	54440004 */ 	bnel	$v0,$a0,.L0f177efc
/*  f177eec:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f177ef0:	03e00008 */ 	jr	$ra
/*  f177ef4:	00e01025 */ 	or	$v0,$a3,$zero
/*  f177ef8:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f177efc:
/*  f177efc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f177f00:	54a8ffea */ 	bnel	$a1,$t0,.L0f177eac
/*  f177f04:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f177f08:	3c027f1b */ 	lui	$v0,%hi(var7f1b7e80)
/*  f177f0c:	03e00008 */ 	jr	$ra
/*  f177f10:	24427e80 */ 	addiu	$v0,$v0,%lo(var7f1b7e80)
.L0f177f14:
/*  f177f14:	3c03800b */ 	lui	$v1,0x800b
/*  f177f18:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f177f1c:	3c07800a */ 	lui	$a3,%hi(var8009deb0)
/*  f177f20:	24e7deb0 */ 	addiu	$a3,$a3,%lo(var8009deb0)
/*  f177f24:	25291448 */ 	addiu	$t1,$t1,%lo(g_MpPlayerNum)
/*  f177f28:	9463cb9e */ 	lhu	$v1,-0x3462($v1)
/*  f177f2c:	00002825 */ 	or	$a1,$zero,$zero
/*  f177f30:	2408000c */ 	addiu	$t0,$zero,0xc
/*  f177f34:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f177f38:
/*  f177f38:	00aec004 */ 	sllv	$t8,$t6,$a1
/*  f177f3c:	0078c824 */ 	and	$t9,$v1,$t8
/*  f177f40:	53200009 */ 	beqzl	$t9,.L0f177f68
/*  f177f44:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f177f48:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f177f4c:	54440005 */ 	bnel	$v0,$a0,.L0f177f64
/*  f177f50:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f177f54:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f177f58:	00ed7821 */ 	addu	$t7,$a3,$t5
/*  f177f5c:	a1e50000 */ 	sb	$a1,0x0($t7)
/*  f177f60:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f177f64:
/*  f177f64:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f177f68:
/*  f177f68:	54a8fff3 */ 	bnel	$a1,$t0,.L0f177f38
/*  f177f6c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f177f70:	10000017 */ 	beqz	$zero,.L0f177fd0
/*  f177f74:	00001025 */ 	or	$v0,$zero,$zero
.L0f177f78:
/*  f177f78:	3c05800b */ 	lui	$a1,%hi(g_MpSetup)
/*  f177f7c:	24a5cb88 */ 	addiu	$a1,$a1,%lo(g_MpSetup)
/*  f177f80:	00001825 */ 	or	$v1,$zero,$zero
/*  f177f84:	2408000c */ 	addiu	$t0,$zero,0xc
/*  f177f88:	94ae0016 */ 	lhu	$t6,0x16($a1)
.L0f177f8c:
/*  f177f8c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f177f90:	0078c804 */ 	sllv	$t9,$t8,$v1
/*  f177f94:	01d96824 */ 	and	$t5,$t6,$t9
/*  f177f98:	11a00009 */ 	beqz	$t5,.L0f177fc0
/*  f177f9c:	3c0f8007 */ 	lui	$t7,0x8007
/*  f177fa0:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f177fa4:	3c04800a */ 	lui	$a0,0x800a
/*  f177fa8:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f177fac:	9084deb0 */ 	lbu	$a0,-0x2150($a0)
/*  f177fb0:	54640003 */ 	bnel	$v1,$a0,.L0f177fc0
/*  f177fb4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f177fb8:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f177fbc:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f177fc0:
/*  f177fc0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177fc4:	5468fff1 */ 	bnel	$v1,$t0,.L0f177f8c
/*  f177fc8:	94ae0016 */ 	lhu	$t6,0x16($a1)
/*  f177fcc:	00001025 */ 	or	$v0,$zero,$zero
.L0f177fd0:
/*  f177fd0:	03e00008 */ 	jr	$ra
/*  f177fd4:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMpEndGame(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_Vars.currentplayer->aborted = true;
		func0000e684();
	}

	return 0;
}

/**
 * This is something near the top of the "End Game" dialog during gameplay.
 */
s32 menuhandler00178018(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MpSetup.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f178050
/*  f178050:	3c0e8007 */ 	lui	$t6,0x8007
/*  f178054:	8dce1440 */ 	lw	$t6,0x1440($t6)
/*  f178058:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f17805c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178060:	a1c00000 */ 	sb	$zero,0x0($t6)
/*  f178064:	90820001 */ 	lbu	$v0,0x1($a0)
/*  f178068:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17806c:	10400007 */ 	beqz	$v0,.L0f17808c
/*  f178070:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178074:	10410010 */ 	beq	$v0,$at,.L0f1780b8
/*  f178078:	24010002 */ 	addiu	$at,$zero,0x2
/*  f17807c:	10410019 */ 	beq	$v0,$at,.L0f1780e4
/*  f178080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178084:	10000021 */ 	beqz	$zero,.L0f17810c
/*  f178088:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17808c:
/*  f17808c:	0fc5b9f1 */ 	jal	textGet
/*  f178090:	24045072 */ 	addiu	$a0,$zero,0x5072
/*  f178094:	3c06800b */ 	lui	$a2,0x800b
/*  f178098:	90c6cb9a */ 	lbu	$a2,-0x3466($a2)
/*  f17809c:	3c048007 */ 	lui	$a0,0x8007
/*  f1780a0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1780a4:	00402825 */ 	or	$a1,$v0,$zero
/*  f1780a8:	0c004dad */ 	jal	sprintf
/*  f1780ac:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1780b0:	10000016 */ 	beqz	$zero,.L0f17810c
/*  f1780b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1780b8:
/*  f1780b8:	0fc5b9f1 */ 	jal	textGet
/*  f1780bc:	24045071 */ 	addiu	$a0,$zero,0x5071
/*  f1780c0:	3c06800b */ 	lui	$a2,0x800b
/*  f1780c4:	90c6cb9b */ 	lbu	$a2,-0x3465($a2)
/*  f1780c8:	3c048007 */ 	lui	$a0,0x8007
/*  f1780cc:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1780d0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1780d4:	0c004dad */ 	jal	sprintf
/*  f1780d8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1780dc:	1000000b */ 	beqz	$zero,.L0f17810c
/*  f1780e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1780e4:
/*  f1780e4:	0fc5b9f1 */ 	jal	textGet
/*  f1780e8:	24045071 */ 	addiu	$a0,$zero,0x5071
/*  f1780ec:	0fc62113 */ 	jal	func0f18844c
/*  f1780f0:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f1780f4:	3c048007 */ 	lui	$a0,0x8007
/*  f1780f8:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1780fc:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f178100:	0c004dad */ 	jal	sprintf
/*  f178104:	24460001 */ 	addiu	$a2,$v0,0x1
/*  f178108:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17810c:
/*  f17810c:	3c028007 */ 	lui	$v0,0x8007
/*  f178110:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f178114:	03e00008 */ 	jr	$ra
/*  f178118:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

s32 menuhandlerMpInGameLimitLabel(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		switch (item->param) {
		case 0: if (g_MpSetup.timelimit == 60) return true; break;
		case 1: if (g_MpSetup.scorelimit == 100) return true; break;
		case 2: if (g_MpSetup.teamscorelimit == 400) return true; break;
		}
	}

	return 0;
}

s32 menuhandlerMpPause(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		if (mpIsPaused()) {
			mpSetPaused(false);
		} else {
			mpSetPaused(true);
		}
	}

	if (operation == MENUOP_CHECKHIDDEN) {
		if (PLAYERCOUNT() == 1) {
			return true;
		}
	}

	if (operation == MENUOP_CHECKPREFOCUSED) {
		if (item->param == 1) {
			return true;
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f1782b8
/*  f1782b8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1782bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1782c0:	0fc62590 */ 	jal	mpIsPaused
/*  f1782c4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1782c8:	10400005 */ 	beqz	$v0,.L0f1782e0
/*  f1782cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1782d0:	0fc5b9f1 */ 	jal	textGet
/*  f1782d4:	24045121 */ 	addiu	$a0,$zero,0x5121
/*  f1782d8:	10000004 */ 	beqz	$zero,.L0f1782ec
/*  f1782dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1782e0:
/*  f1782e0:	0fc5b9f1 */ 	jal	textGet
/*  f1782e4:	24045120 */ 	addiu	$a0,$zero,0x5120
/*  f1782e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1782ec:
/*  f1782ec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1782f0:	03e00008 */ 	jr	$ra
/*  f1782f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1782f8
/*  f1782f8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1782fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178300:	0fc5b37e */ 	jal	getVar80084024
/*  f178304:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f178308:	3c048007 */ 	lui	$a0,0x8007
/*  f17830c:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f178310:	00402825 */ 	or	$a1,$v0,$zero
/*  f178314:	0fc355f8 */ 	jal	func0f0d57e0
/*  f178318:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f17831c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178320:	3c028007 */ 	lui	$v0,0x8007
/*  f178324:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f178328:	03e00008 */ 	jr	$ra
/*  f17832c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f178330
/*  f178330:	3c0e8007 */ 	lui	$t6,0x8007
/*  f178334:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f178338:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17833c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f178340:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f178344:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f178348:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17834c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f178350:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f178354:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f178358:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17835c:	3c04800a */ 	lui	$a0,0x800a
/*  f178360:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178364:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f178368:	0fc2c3f4 */ 	jal	weaponFindById
/*  f17836c:	8c84ee28 */ 	lw	$a0,-0x11d8($a0)
/*  f178370:	10400005 */ 	beqz	$v0,.L0f178388
/*  f178374:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178378:	0fc5b9f1 */ 	jal	textGet
/*  f17837c:	9444004a */ 	lhu	$a0,0x4a($v0)
/*  f178380:	10000004 */ 	beqz	$zero,.L0f178394
/*  f178384:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178388:
/*  f178388:	3c027f1b */ 	lui	$v0,%hi(var7f1b7e84)
/*  f17838c:	24427e84 */ 	addiu	$v0,$v0,%lo(var7f1b7e84)
/*  f178390:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178394:
/*  f178394:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f178398:	03e00008 */ 	jr	$ra
/*  f17839c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1783a0
/*  f1783a0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1783a4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1783a8:	3c02800a */ 	lui	$v0,0x800a
/*  f1783ac:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1783b0:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f1783b4:	9042deb0 */ 	lbu	$v0,-0x2150($v0)
/*  f1783b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1783bc:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1783c0:	28410004 */ 	slti	$at,$v0,0x4
/*  f1783c4:	10200008 */ 	beqz	$at,.L0f1783e8
/*  f1783c8:	00401825 */ 	or	$v1,$v0,$zero
/*  f1783cc:	00027880 */ 	sll	$t7,$v0,0x2
/*  f1783d0:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f1783d4:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f1783d8:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f1783dc:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f1783e0:	1000000a */ 	beqz	$zero,.L0f17840c
/*  f1783e4:	01f83021 */ 	addu	$a2,$t7,$t8
.L0f1783e8:
/*  f1783e8:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f1783ec:	0323c821 */ 	addu	$t9,$t9,$v1
/*  f1783f0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1783f4:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f1783f8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1783fc:	3c09800b */ 	lui	$t1,%hi(g_MpSimulants)
/*  f178400:	2529c538 */ 	addiu	$t1,$t1,%lo(g_MpSimulants)
/*  f178404:	2728fed0 */ 	addiu	$t0,$t9,-304
/*  f178408:	01093021 */ 	addu	$a2,$t0,$t1
.L0f17840c:
/*  f17840c:	24045118 */ 	addiu	$a0,$zero,0x5118
/*  f178410:	0fc5b9f1 */ 	jal	textGet
/*  f178414:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f178418:	3c048007 */ 	lui	$a0,0x8007
/*  f17841c:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f178420:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f178424:	0c004dad */ 	jal	sprintf
/*  f178428:	00402825 */ 	or	$a1,$v0,$zero
/*  f17842c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178430:	3c028007 */ 	lui	$v0,0x8007
/*  f178434:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f178438:	03e00008 */ 	jr	$ra
/*  f17843c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f178440:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f178444:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f178448:	03e00008 */ 	jr	$ra
/*  f17844c:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0f178450
/*  f178450:	3c0e8007 */ 	lui	$t6,0x8007
/*  f178454:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f178458:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17845c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f178460:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f178464:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f178468:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17846c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f178470:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f178474:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f178478:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17847c:	3c04800a */ 	lui	$a0,0x800a
/*  f178480:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178484:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f178488:	9084e83b */ 	lbu	$a0,-0x17c5($a0)
/*  f17848c:	0fc05840 */ 	jal	func0f016100
/*  f178490:	00002825 */ 	or	$a1,$zero,$zero
/*  f178494:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178498:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17849c:	03e00008 */ 	jr	$ra
/*  f1784a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1784a4
/*  f1784a4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1784a8:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1784ac:	3c18800a */ 	lui	$t8,0x800a
/*  f1784b0:	3c08800a */ 	lui	$t0,0x800a
/*  f1784b4:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f1784b8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1784bc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1784c0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1784c4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f1784c8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1784cc:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1784d0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1784d4:	9318e83b */ 	lbu	$t8,-0x17c5($t8)
/*  f1784d8:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f1784dc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1784e0:	01194021 */ 	addu	$t0,$t0,$t9
/*  f1784e4:	8d08a024 */ 	lw	$t0,-0x5fdc($t0)
/*  f1784e8:	03e00008 */ 	jr	$ra
/*  f1784ec:	8d021974 */ 	lw	$v0,0x1974($t0)
);

GLOBAL_ASM(
glabel func0f1784f0
/*  f1784f0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1784f4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1784f8:	3c18800a */ 	lui	$t8,0x800a
/*  f1784fc:	3c08800a */ 	lui	$t0,0x800a
/*  f178500:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f178504:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f178508:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17850c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f178510:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f178514:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f178518:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17851c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f178520:	9318e83b */ 	lbu	$t8,-0x17c5($t8)
/*  f178524:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f178528:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17852c:	01194021 */ 	addu	$t0,$t0,$t9
/*  f178530:	8d08a024 */ 	lw	$t0,-0x5fdc($t0)
/*  f178534:	03e00008 */ 	jr	$ra
/*  f178538:	8d021978 */ 	lw	$v0,0x1978($t0)
);

GLOBAL_ASM(
glabel func0f17853c
/*  f17853c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f178540:	3c0e8008 */ 	lui	$t6,%hi(rankings)
/*  f178544:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178548:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f17854c:	25ce4918 */ 	addiu	$t6,$t6,%lo(rankings)
/*  f178550:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f178554:	27a20018 */ 	addiu	$v0,$sp,0x18
/*  f178558:	3c088007 */ 	lui	$t0,0x8007
/*  f17855c:	ac410000 */ 	sw	$at,0x0($v0)
/*  f178560:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f178564:	3c0a800b */ 	lui	$t2,0x800b
/*  f178568:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f17856c:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f178570:	ac410008 */ 	sw	$at,0x8($v0)
/*  f178574:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f178578:	ac59000c */ 	sw	$t9,0xc($v0)
/*  f17857c:	8dc10010 */ 	lw	$at,0x10($t6)
/*  f178580:	ac410010 */ 	sw	$at,0x10($v0)
/*  f178584:	8dd90014 */ 	lw	$t9,0x14($t6)
/*  f178588:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f17858c:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f178590:	00084880 */ 	sll	$t1,$t0,0x2
/*  f178594:	01284821 */ 	addu	$t1,$t1,$t0
/*  f178598:	00094940 */ 	sll	$t1,$t1,0x5
/*  f17859c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f1785a0:	814ac7d6 */ 	lb	$t2,-0x382a($t2)
/*  f1785a4:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f1785a8:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f1785ac:	0fc5b9f1 */ 	jal	textGet
/*  f1785b0:	95840000 */ 	lhu	$a0,0x0($t4)
/*  f1785b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1785b8:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1785bc:	03e00008 */ 	jr	$ra
/*  f1785c0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler001785c4
/*  f1785c4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1785c8:	24010016 */ 	addiu	$at,$zero,0x16
/*  f1785cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1785d0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1785d4:	1481003b */ 	bne	$a0,$at,.L0f1786c4
/*  f1785d8:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1785dc:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1785e0:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1785e4:	3c18800b */ 	lui	$t8,0x800b
/*  f1785e8:	3c014220 */ 	lui	$at,0x4220
/*  f1785ec:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1785f0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1785f4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f1785f8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1785fc:	8318c7d6 */ 	lb	$t8,-0x382a($t8)
/*  f178600:	57000031 */ 	bnezl	$t8,.L0f1786c8
/*  f178604:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178608:	44816000 */ 	mtc1	$at,$f12
/*  f17860c:	0fc01ac2 */ 	jal	func0f006b08
/*  f178610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178614:	3c01437f */ 	lui	$at,0x437f
/*  f178618:	44812000 */ 	mtc1	$at,$f4
/*  f17861c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f178620:	8fb90020 */ 	lw	$t9,0x20($sp)
/*  f178624:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f178628:	3c05ffff */ 	lui	$a1,0xffff
/*  f17862c:	34a500ff */ 	ori	$a1,$a1,0xff
/*  f178630:	3c014f00 */ 	lui	$at,0x4f00
/*  f178634:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f178638:	4448f800 */ 	cfc1	$t0,$31
/*  f17863c:	44c6f800 */ 	ctc1	$a2,$31
/*  f178640:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178644:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f178648:	4446f800 */ 	cfc1	$a2,$31
/*  f17864c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178650:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f178654:	50c00013 */ 	beqzl	$a2,.L0f1786a4
/*  f178658:	44064000 */ 	mfc1	$a2,$f8
/*  f17865c:	44814000 */ 	mtc1	$at,$f8
/*  f178660:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f178664:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f178668:	44c6f800 */ 	ctc1	$a2,$31
/*  f17866c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178670:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f178674:	4446f800 */ 	cfc1	$a2,$31
/*  f178678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17867c:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f178680:	14c00005 */ 	bnez	$a2,.L0f178698
/*  f178684:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178688:	44064000 */ 	mfc1	$a2,$f8
/*  f17868c:	3c018000 */ 	lui	$at,0x8000
/*  f178690:	10000007 */ 	beqz	$zero,.L0f1786b0
/*  f178694:	00c13025 */ 	or	$a2,$a2,$at
.L0f178698:
/*  f178698:	10000005 */ 	beqz	$zero,.L0f1786b0
/*  f17869c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1786a0:	44064000 */ 	mfc1	$a2,$f8
.L0f1786a4:
/*  f1786a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1786a8:	04c0fffb */ 	bltz	$a2,.L0f178698
/*  f1786ac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1786b0:
/*  f1786b0:	44c8f800 */ 	ctc1	$t0,$31
/*  f1786b4:	0fc01a40 */ 	jal	func0f006900
/*  f1786b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1786bc:	8fa90020 */ 	lw	$t1,0x20($sp)
/*  f1786c0:	ad220004 */ 	sw	$v0,0x4($t1)
.L0f1786c4:
/*  f1786c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1786c8:
/*  f1786c8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1786cc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1786d0:	03e00008 */ 	jr	$ra
/*  f1786d4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler001786d8
/*  f1786d8:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f1786dc:	24010013 */ 	addiu	$at,$zero,0x13
/*  f1786e0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f1786e4:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f1786e8:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f1786ec:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f1786f0:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f1786f4:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f1786f8:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f1786fc:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f178700:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f178704:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f178708:	148100d5 */ 	bne	$a0,$at,.L0f178a60
/*  f17870c:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f178710:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f178714:	3c1e8007 */ 	lui	$s8,%hi(g_MpPlayerNum)
/*  f178718:	3c17800b */ 	lui	$s7,%hi(g_MpPlayers)
/*  f17871c:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f178720:	8cd50008 */ 	lw	$s5,0x8($a2)
/*  f178724:	3c14ba00 */ 	lui	$s4,0xba00
/*  f178728:	3c138008 */ 	lui	$s3,%hi(var8007fac0)
/*  f17872c:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f178730:	8eb80008 */ 	lw	$t8,0x8($s5)
/*  f178734:	0000b025 */ 	or	$s6,$zero,$zero
/*  f178738:	2673fac0 */ 	addiu	$s3,$s3,%lo(var8007fac0)
/*  f17873c:	01f89021 */ 	addu	$s2,$t7,$t8
/*  f178740:	2652fff1 */ 	addiu	$s2,$s2,-15
/*  f178744:	36940c02 */ 	ori	$s4,$s4,0xc02
/*  f178748:	26f7c7b8 */ 	addiu	$s7,$s7,%lo(g_MpPlayers)
/*  f17874c:	27de1448 */ 	addiu	$s8,$s8,%lo(g_MpPlayerNum)
/*  f178750:	00008025 */ 	or	$s0,$zero,$zero
/*  f178754:	8fb10090 */ 	lw	$s1,0x90($sp)
/*  f178758:	8fd90000 */ 	lw	$t9,0x0($s8)
.L0f17875c:
/*  f17875c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f178760:	020b6004 */ 	sllv	$t4,$t3,$s0
/*  f178764:	00194080 */ 	sll	$t0,$t9,0x2
/*  f178768:	01194021 */ 	addu	$t0,$t0,$t9
/*  f17876c:	00084140 */ 	sll	$t0,$t0,0x5
/*  f178770:	02e84821 */ 	addu	$t1,$s7,$t0
/*  f178774:	912a0094 */ 	lbu	$t2,0x94($t1)
/*  f178778:	014c6824 */ 	and	$t5,$t2,$t4
/*  f17877c:	51a000b2 */ 	beqzl	$t5,.L0f178a48
/*  f178780:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f178784:	12000009 */ 	beqz	$s0,.L0f1787ac
/*  f178788:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17878c:	1201000a */ 	beq	$s0,$at,.L0f1787b8
/*  f178790:	24010002 */ 	addiu	$at,$zero,0x2
/*  f178794:	1201000b */ 	beq	$s0,$at,.L0f1787c4
/*  f178798:	24010003 */ 	addiu	$at,$zero,0x3
/*  f17879c:	5201000d */ 	beql	$s0,$at,.L0f1787d4
/*  f1787a0:	3c1100bf */ 	lui	$s1,0xbf
/*  f1787a4:	1000000c */ 	beqz	$zero,.L0f1787d8
/*  f1787a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1787ac:
/*  f1787ac:	3c11ff7f */ 	lui	$s1,0xff7f
/*  f1787b0:	10000009 */ 	beqz	$zero,.L0f1787d8
/*  f1787b4:	36317fff */ 	ori	$s1,$s1,0x7fff
.L0f1787b8:
/*  f1787b8:	3c11bfbf */ 	lui	$s1,0xbfbf
/*  f1787bc:	10000006 */ 	beqz	$zero,.L0f1787d8
/*  f1787c0:	363100ff */ 	ori	$s1,$s1,0xff
.L0f1787c4:
/*  f1787c4:	3c1100ff */ 	lui	$s1,0xff
/*  f1787c8:	10000003 */ 	beqz	$zero,.L0f1787d8
/*  f1787cc:	363100ff */ 	ori	$s1,$s1,0xff
/*  f1787d0:	3c1100bf */ 	lui	$s1,0xbf
.L0f1787d4:
/*  f1787d4:	3631bfff */ 	ori	$s1,$s1,0xbfff
.L0f1787d8:
/*  f1787d8:	16c00053 */ 	bnez	$s6,.L0f178928
/*  f1787dc:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f1787e0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f1787e4:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f1787e8:	3c18e700 */ 	lui	$t8,0xe700
/*  f1787ec:	add80000 */ 	sw	$t8,0x0($t6)
/*  f1787f0:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f1787f4:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f1787f8:	3c09ba00 */ 	lui	$t1,0xba00
/*  f1787fc:	35291301 */ 	ori	$t1,$t1,0x1301
/*  f178800:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f178804:	afa800a4 */ 	sw	$t0,0xa4($sp)
/*  f178808:	af200004 */ 	sw	$zero,0x4($t9)
/*  f17880c:	af290000 */ 	sw	$t1,0x0($t9)
/*  f178810:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f178814:	3c0cb900 */ 	lui	$t4,0xb900
/*  f178818:	358c0002 */ 	ori	$t4,$t4,0x2
/*  f17881c:	256a0008 */ 	addiu	$t2,$t3,0x8
/*  f178820:	afaa00a4 */ 	sw	$t2,0xa4($sp)
/*  f178824:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f178828:	ad6c0000 */ 	sw	$t4,0x0($t3)
/*  f17882c:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f178830:	3c0fba00 */ 	lui	$t7,0xba00
/*  f178834:	35ef1001 */ 	ori	$t7,$t7,0x1001
/*  f178838:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f17883c:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f178840:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f178844:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f178848:	8fb800a4 */ 	lw	$t8,0xa4($sp)
/*  f17884c:	3c08ba00 */ 	lui	$t0,0xba00
/*  f178850:	35080903 */ 	ori	$t0,$t0,0x903
/*  f178854:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f178858:	afb900a4 */ 	sw	$t9,0xa4($sp)
/*  f17885c:	24090c00 */ 	addiu	$t1,$zero,0xc00
/*  f178860:	af090004 */ 	sw	$t1,0x4($t8)
/*  f178864:	af080000 */ 	sw	$t0,0x0($t8)
/*  f178868:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f17886c:	3c05800b */ 	lui	$a1,0x800b
/*  f178870:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f178874:	256a0008 */ 	addiu	$t2,$t3,0x8
/*  f178878:	afaa00a4 */ 	sw	$t2,0xa4($sp)
/*  f17887c:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f178880:	ad740000 */ 	sw	$s4,0x0($t3)
/*  f178884:	8ca5b5a8 */ 	lw	$a1,-0x4a58($a1)
/*  f178888:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f17888c:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f178890:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f178894:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f178898:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f17889c:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f1788a0:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1788a4:	00003825 */ 	or	$a3,$zero,$zero
/*  f1788a8:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f1788ac:	24a501a4 */ 	addiu	$a1,$a1,0x01a4
/*  f1788b0:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f1788b4:	3c18ba00 */ 	lui	$t8,0xba00
/*  f1788b8:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f1788bc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f1788c0:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f1788c4:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f1788c8:	add80000 */ 	sw	$t8,0x0($t6)
/*  f1788cc:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f1788d0:	3c09fcff */ 	lui	$t1,0xfcff
/*  f1788d4:	3c0bfffc */ 	lui	$t3,0xfffc
/*  f1788d8:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f1788dc:	afa800a4 */ 	sw	$t0,0xa4($sp)
/*  f1788e0:	356bf279 */ 	ori	$t3,$t3,0xf279
/*  f1788e4:	3529ffff */ 	ori	$t1,$t1,0xffff
/*  f1788e8:	af290000 */ 	sw	$t1,0x0($t9)
/*  f1788ec:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  f1788f0:	8faa00a4 */ 	lw	$t2,0xa4($sp)
/*  f1788f4:	3c18ff37 */ 	lui	$t8,0xff37
/*  f1788f8:	3c0ffc12 */ 	lui	$t7,0xfc12
/*  f1788fc:	254c0008 */ 	addiu	$t4,$t2,0x8
/*  f178900:	afac00a4 */ 	sw	$t4,0xa4($sp)
/*  f178904:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f178908:	ad540000 */ 	sw	$s4,0x0($t2)
/*  f17890c:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f178910:	35ef9a25 */ 	ori	$t7,$t7,0x9a25
/*  f178914:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f178918:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f17891c:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f178920:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f178924:	adaf0000 */ 	sw	$t7,0x0($t5)
.L0f178928:
/*  f178928:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f17892c:	3c09fb00 */ 	lui	$t1,0xfb00
/*  f178930:	264c000b */ 	addiu	$t4,$s2,0xb
/*  f178934:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f178938:	afa800a4 */ 	sw	$t0,0xa4($sp)
/*  f17893c:	af310004 */ 	sw	$s1,0x4($t9)
/*  f178940:	af290000 */ 	sw	$t1,0x0($t9)
/*  f178944:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f178948:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f17894c:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f178950:	01ae0019 */ 	multu	$t5,$t6
/*  f178954:	03201025 */ 	or	$v0,$t9,$zero
/*  f178958:	256a0008 */ 	addiu	$t2,$t3,0x8
/*  f17895c:	afaa00a4 */ 	sw	$t2,0xa4($sp)
/*  f178960:	8ea90004 */ 	lw	$t1,0x4($s5)
/*  f178964:	01601825 */ 	or	$v1,$t3,$zero
/*  f178968:	3c01e400 */ 	lui	$at,0xe400
/*  f17896c:	252b0009 */ 	addiu	$t3,$t1,0x9
/*  f178970:	000b5080 */ 	sll	$t2,$t3,0x2
/*  f178974:	314c0fff */ 	andi	$t4,$t2,0xfff
/*  f178978:	00007812 */ 	mflo	$t7
/*  f17897c:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f178980:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f178984:	03214025 */ 	or	$t0,$t9,$at
/*  f178988:	010c6825 */ 	or	$t5,$t0,$t4
/*  f17898c:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f178990:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f178994:	00127080 */ 	sll	$t6,$s2,0x2
/*  f178998:	8eab0004 */ 	lw	$t3,0x4($s5)
/*  f17899c:	01cf0019 */ 	multu	$t6,$t7
/*  f1789a0:	2652fff2 */ 	addiu	$s2,$s2,-14
/*  f1789a4:	256afffe */ 	addiu	$t2,$t3,-2
/*  f1789a8:	000a4080 */ 	sll	$t0,$t2,0x2
/*  f1789ac:	310c0fff */ 	andi	$t4,$t0,0xfff
/*  f1789b0:	3c08b300 */ 	lui	$t0,0xb300
/*  f1789b4:	0000c012 */ 	mflo	$t8
/*  f1789b8:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f1789bc:	00194b00 */ 	sll	$t1,$t9,0xc
/*  f1789c0:	012c6825 */ 	or	$t5,$t1,$t4
/*  f1789c4:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f1789c8:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f1789cc:	3c190010 */ 	lui	$t9,0x10
/*  f1789d0:	37390150 */ 	ori	$t9,$t9,0x150
/*  f1789d4:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f1789d8:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f1789dc:	3c18b400 */ 	lui	$t8,0xb400
/*  f1789e0:	add80000 */ 	sw	$t8,0x0($t6)
/*  f1789e4:	add90004 */ 	sw	$t9,0x4($t6)
/*  f1789e8:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f1789ec:	240c0400 */ 	addiu	$t4,$zero,0x400
/*  f1789f0:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1789f4:	256a0008 */ 	addiu	$t2,$t3,0x8
/*  f1789f8:	afaa00a4 */ 	sw	$t2,0xa4($sp)
/*  f1789fc:	ad680000 */ 	sw	$t0,0x0($t3)
/*  f178a00:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f178a04:	01602825 */ 	or	$a1,$t3,$zero
/*  f178a08:	0189001a */ 	div	$zero,$t4,$t1
/*  f178a0c:	00006812 */ 	mflo	$t5
/*  f178a10:	31aeffff */ 	andi	$t6,$t5,0xffff
/*  f178a14:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f178a18:	35f8fc00 */ 	ori	$t8,$t7,0xfc00
/*  f178a1c:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f178a20:	15200002 */ 	bnez	$t1,.L0f178a2c
/*  f178a24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178a28:	0007000d */ 	break	0x7
.L0f178a2c:
/*  f178a2c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f178a30:	15210004 */ 	bne	$t1,$at,.L0f178a44
/*  f178a34:	3c018000 */ 	lui	$at,0x8000
/*  f178a38:	15810002 */ 	bne	$t4,$at,.L0f178a44
/*  f178a3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178a40:	0006000d */ 	break	0x6
.L0f178a44:
/*  f178a44:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f178a48:
/*  f178a48:	24010004 */ 	addiu	$at,$zero,0x4
/*  f178a4c:	5601ff43 */ 	bnel	$s0,$at,.L0f17875c
/*  f178a50:	8fd90000 */ 	lw	$t9,0x0($s8)
/*  f178a54:	afb10090 */ 	sw	$s1,0x90($sp)
/*  f178a58:	10000002 */ 	beqz	$zero,.L0f178a64
/*  f178a5c:	8fa200a4 */ 	lw	$v0,0xa4($sp)
.L0f178a60:
/*  f178a60:	00001025 */ 	or	$v0,$zero,$zero
.L0f178a64:
/*  f178a64:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f178a68:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f178a6c:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f178a70:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f178a74:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f178a78:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f178a7c:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f178a80:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f178a84:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f178a88:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f178a8c:	03e00008 */ 	jr	$ra
/*  f178a90:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

GLOBAL_ASM(
glabel menuhandler00178a94
/*  f178a94:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f178a98:	24010016 */ 	addiu	$at,$zero,0x16
/*  f178a9c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178aa0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f178aa4:	1481003d */ 	bne	$a0,$at,.L0f178b9c
/*  f178aa8:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f178aac:	3c0e8007 */ 	lui	$t6,0x8007
/*  f178ab0:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f178ab4:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f178ab8:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f178abc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f178ac0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f178ac4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f178ac8:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f178acc:	90590095 */ 	lbu	$t9,0x95($v0)
/*  f178ad0:	90480096 */ 	lbu	$t0,0x96($v0)
/*  f178ad4:	3c014220 */ 	lui	$at,0x4220
/*  f178ad8:	53280031 */ 	beql	$t9,$t0,.L0f178ba0
/*  f178adc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178ae0:	44816000 */ 	mtc1	$at,$f12
/*  f178ae4:	0fc01ac2 */ 	jal	func0f006b08
/*  f178ae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178aec:	3c01437f */ 	lui	$at,0x437f
/*  f178af0:	44812000 */ 	mtc1	$at,$f4
/*  f178af4:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f178af8:	8fa90020 */ 	lw	$t1,0x20($sp)
/*  f178afc:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f178b00:	3c05ffff */ 	lui	$a1,0xffff
/*  f178b04:	34a500ff */ 	ori	$a1,$a1,0xff
/*  f178b08:	3c014f00 */ 	lui	$at,0x4f00
/*  f178b0c:	8d240004 */ 	lw	$a0,0x4($t1)
/*  f178b10:	444af800 */ 	cfc1	$t2,$31
/*  f178b14:	44c6f800 */ 	ctc1	$a2,$31
/*  f178b18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b1c:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f178b20:	4446f800 */ 	cfc1	$a2,$31
/*  f178b24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b28:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f178b2c:	50c00013 */ 	beqzl	$a2,.L0f178b7c
/*  f178b30:	44064000 */ 	mfc1	$a2,$f8
/*  f178b34:	44814000 */ 	mtc1	$at,$f8
/*  f178b38:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f178b3c:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f178b40:	44c6f800 */ 	ctc1	$a2,$31
/*  f178b44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b48:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f178b4c:	4446f800 */ 	cfc1	$a2,$31
/*  f178b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b54:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f178b58:	14c00005 */ 	bnez	$a2,.L0f178b70
/*  f178b5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b60:	44064000 */ 	mfc1	$a2,$f8
/*  f178b64:	3c018000 */ 	lui	$at,0x8000
/*  f178b68:	10000007 */ 	beqz	$zero,.L0f178b88
/*  f178b6c:	00c13025 */ 	or	$a2,$a2,$at
.L0f178b70:
/*  f178b70:	10000005 */ 	beqz	$zero,.L0f178b88
/*  f178b74:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f178b78:	44064000 */ 	mfc1	$a2,$f8
.L0f178b7c:
/*  f178b7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b80:	04c0fffb */ 	bltz	$a2,.L0f178b70
/*  f178b84:	00000000 */ 	sll	$zero,$zero,0x0
.L0f178b88:
/*  f178b88:	44caf800 */ 	ctc1	$t2,$31
/*  f178b8c:	0fc01a40 */ 	jal	func0f006900
/*  f178b90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178b94:	8fab0020 */ 	lw	$t3,0x20($sp)
/*  f178b98:	ad620004 */ 	sw	$v0,0x4($t3)
.L0f178b9c:
/*  f178b9c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178ba0:
/*  f178ba0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f178ba4:	00001025 */ 	or	$v0,$zero,$zero
/*  f178ba8:	03e00008 */ 	jr	$ra
/*  f178bac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f178bb0
/*  f178bb0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f178bb4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f178bb8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f178bbc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f178bc0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f178bc4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f178bc8:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f178bcc:	3c04800b */ 	lui	$a0,0x800b
/*  f178bd0:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f178bd4:	9084c84d */ 	lbu	$a0,-0x37b3($a0)
/*  f178bd8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178bdc:	0fc5b9f1 */ 	jal	textGet
/*  f178be0:	248458b9 */ 	addiu	$a0,$a0,0x58b9
/*  f178be4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178be8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f178bec:	03e00008 */ 	jr	$ra
/*  f178bf0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler00178bf4
/*  f178bf4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f178bf8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178bfc:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f178c00:	24010006 */ 	addiu	$at,$zero,0x6
/*  f178c04:	10810065 */ 	beq	$a0,$at,.L0f178d9c
/*  f178c08:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f178c0c:	24010011 */ 	addiu	$at,$zero,0x11
/*  f178c10:	10810006 */ 	beq	$a0,$at,.L0f178c2c
/*  f178c14:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f178c18:	24010012 */ 	addiu	$at,$zero,0x12
/*  f178c1c:	10810033 */ 	beq	$a0,$at,.L0f178cec
/*  f178c20:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f178c24:	10000061 */ 	beqz	$zero,.L0f178dac
/*  f178c28:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178c2c:
/*  f178c2c:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f178c30:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f178c34:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f178c38:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f178c3c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f178c40:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f178c44:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f178c48:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f178c4c:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f178c50:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f178c54:	00001825 */ 	or	$v1,$zero,$zero
/*  f178c58:	1138001a */ 	beq	$t1,$t8,.L0f178cc4
/*  f178c5c:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f178c60:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f178c64:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f178c68:	00f92821 */ 	addu	$a1,$a3,$t9
/*  f178c6c:	90ab0000 */ 	lbu	$t3,0x0($a1)
/*  f178c70:	01401021 */ 	addu	$v0,$t2,$zero
/*  f178c74:	2406000b */ 	addiu	$a2,$zero,0xb
/*  f178c78:	51600013 */ 	beqzl	$t3,.L0f178cc8
/*  f178c7c:	2861000b */ 	slti	$at,$v1,0xb
/*  f178c80:	90a40000 */ 	lbu	$a0,0x0($a1)
/*  f178c84:	a0440000 */ 	sb	$a0,0x0($v0)
.L0f178c88:
/*  f178c88:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f178c8c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f178c90:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f178c94:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f178c98:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f178c9c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f178ca0:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f178ca4:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f178ca8:	93040000 */ 	lbu	$a0,0x0($t8)
/*  f178cac:	51240006 */ 	beql	$t1,$a0,.L0f178cc8
/*  f178cb0:	2861000b */ 	slti	$at,$v1,0xb
/*  f178cb4:	50800004 */ 	beqzl	$a0,.L0f178cc8
/*  f178cb8:	2861000b */ 	slti	$at,$v1,0xb
/*  f178cbc:	5466fff2 */ 	bnel	$v1,$a2,.L0f178c88
/*  f178cc0:	a0440000 */ 	sb	$a0,0x0($v0)
.L0f178cc4:
/*  f178cc4:	2861000b */ 	slti	$at,$v1,0xb
.L0f178cc8:
/*  f178cc8:	10200037 */ 	beqz	$at,.L0f178da8
/*  f178ccc:	01431021 */ 	addu	$v0,$t2,$v1
.L0f178cd0:
/*  f178cd0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f178cd4:	2861000b */ 	slti	$at,$v1,0xb
/*  f178cd8:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f178cdc:	1420fffc */ 	bnez	$at,.L0f178cd0
/*  f178ce0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f178ce4:	10000031 */ 	beqz	$zero,.L0f178dac
/*  f178ce8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178cec:
/*  f178cec:	91590000 */ 	lbu	$t9,0x0($t2)
/*  f178cf0:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f178cf4:	00001825 */ 	or	$v1,$zero,$zero
/*  f178cf8:	13200014 */ 	beqz	$t9,.L0f178d4c
/*  f178cfc:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f178d00:	3c0b8007 */ 	lui	$t3,0x8007
/*  f178d04:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f178d08:	3c0e800b */ 	lui	$t6,%hi(g_MpPlayers)
/*  f178d0c:	25cec7b8 */ 	addiu	$t6,$t6,%lo(g_MpPlayers)
/*  f178d10:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f178d14:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f178d18:	000c6140 */ 	sll	$t4,$t4,0x5
/*  f178d1c:	018e2021 */ 	addu	$a0,$t4,$t6
/*  f178d20:	01401021 */ 	addu	$v0,$t2,$zero
/*  f178d24:	91450000 */ 	lbu	$a1,0x0($t2)
/*  f178d28:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f178d2c:
/*  f178d2c:	2861000b */ 	slti	$at,$v1,0xb
/*  f178d30:	a0850000 */ 	sb	$a1,0x0($a0)
/*  f178d34:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f178d38:	10200004 */ 	beqz	$at,.L0f178d4c
/*  f178d3c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f178d40:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f178d44:	54a0fff9 */ 	bnezl	$a1,.L0f178d2c
/*  f178d48:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f178d4c:
/*  f178d4c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f178d50:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f178d54:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f178d58:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f178d5c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f178d60:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f178d64:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f178d68:	03232021 */ 	addu	$a0,$t9,$v1
/*  f178d6c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f178d70:	2861000b */ 	slti	$at,$v1,0xb
/*  f178d74:	a08b0000 */ 	sb	$t3,0x0($a0)
/*  f178d78:	1020000b */ 	beqz	$at,.L0f178da8
/*  f178d7c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f178d80:
/*  f178d80:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f178d84:	2861000b */ 	slti	$at,$v1,0xb
/*  f178d88:	a0800000 */ 	sb	$zero,0x0($a0)
/*  f178d8c:	1420fffc */ 	bnez	$at,.L0f178d80
/*  f178d90:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f178d94:	10000005 */ 	beqz	$zero,.L0f178dac
/*  f178d98:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178d9c:
/*  f178d9c:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f178da0:	0fc42947 */ 	jal	func0f10a51c
/*  f178da4:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f178da8:
/*  f178da8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178dac:
/*  f178dac:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f178db0:	00001025 */ 	or	$v0,$zero,$zero
/*  f178db4:	03e00008 */ 	jr	$ra
/*  f178db8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f178dbc
/*  f178dbc:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f178dc0:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f178dc4:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f178dc8:	908f001e */ 	lbu	$t7,0x1e($a0)
/*  f178dcc:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
/*  f178dd0:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f178dd4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f178dd8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f178ddc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178de0:	11e1003f */ 	beq	$t7,$at,.L0f178ee0
/*  f178de4:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f178de8:	3c188006 */ 	lui	$t8,0x8006
/*  f178dec:	8f18d9d0 */ 	lw	$t8,-0x2630($t8)
/*  f178df0:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f178df4:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f178df8:	5700003a */ 	bnezl	$t8,.L0f178ee4
/*  f178dfc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f178e00:	8c790288 */ 	lw	$t9,0x288($v1)
/*  f178e04:	3c0b800a */ 	lui	$t3,%hi(var8009e000)
/*  f178e08:	256be000 */ 	addiu	$t3,$t3,%lo(var8009e000)
/*  f178e0c:	8f280070 */ 	lw	$t0,0x70($t9)
/*  f178e10:	000850c0 */ 	sll	$t2,$t0,0x3
/*  f178e14:	01485023 */ 	subu	$t2,$t2,$t0
/*  f178e18:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f178e1c:	01485021 */ 	addu	$t2,$t2,$t0
/*  f178e20:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f178e24:	01485023 */ 	subu	$t2,$t2,$t0
/*  f178e28:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f178e2c:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f178e30:	904c083c */ 	lbu	$t4,0x83c($v0)
/*  f178e34:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f178e38:	55800028 */ 	bnezl	$t4,.L0f178edc
/*  f178e3c:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*  f178e40:	8c6e0318 */ 	lw	$t6,0x318($v1)
/*  f178e44:	8c6d028c */ 	lw	$t5,0x28c($v1)
/*  f178e48:	11c00012 */ 	beqz	$t6,.L0f178e94
/*  f178e4c:	a04d083b */ 	sb	$t5,0x83b($v0)
/*  f178e50:	8c8f000c */ 	lw	$t7,0xc($a0)
/*  f178e54:	3c048008 */ 	lui	$a0,%hi(menudialog_2a8b0)
/*  f178e58:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f178e5c:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f178e60:	13000007 */ 	beqz	$t8,.L0f178e80
/*  f178e64:	24844890 */ 	addiu	$a0,$a0,%lo(menudialog_2a8b0)
/*  f178e68:	3c048008 */ 	lui	$a0,%hi(menudialog_2a908)
/*  f178e6c:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178e70:	248448e8 */ 	addiu	$a0,$a0,%lo(menudialog_2a908)
/*  f178e74:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f178e78:	10000017 */ 	beqz	$zero,.L0f178ed8
/*  f178e7c:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
.L0f178e80:
/*  f178e80:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178e84:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f178e88:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f178e8c:	10000012 */ 	beqz	$zero,.L0f178ed8
/*  f178e90:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
.L0f178e94:
/*  f178e94:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f178e98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178e9c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f178ea0:	14410008 */ 	bne	$v0,$at,.L0f178ec4
/*  f178ea4:	3c048007 */ 	lui	$a0,%hi(menudialog_196c8)
/*  f178ea8:	3c048007 */ 	lui	$a0,%hi(menudialog_status)
/*  f178eac:	248436c0 */ 	addiu	$a0,$a0,%lo(menudialog_status)
/*  f178eb0:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178eb4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f178eb8:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f178ebc:	10000006 */ 	beqz	$zero,.L0f178ed8
/*  f178ec0:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
.L0f178ec4:
/*  f178ec4:	248436a8 */ 	addiu	$a0,$a0,%lo(menudialog_196c8)
/*  f178ec8:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178ecc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f178ed0:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f178ed4:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
.L0f178ed8:
/*  f178ed8:	8fb9001c */ 	lw	$t9,0x1c($sp)
.L0f178edc:
/*  f178edc:	acd90000 */ 	sw	$t9,0x0($a2)
.L0f178ee0:
/*  f178ee0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f178ee4:
/*  f178ee4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f178ee8:	03e00008 */ 	jr	$ra
/*  f178eec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f178ef0
/*  f178ef0:	3c028007 */ 	lui	$v0,%hi(g_MpPlayerNum)
/*  f178ef4:	0005c0c0 */ 	sll	$t8,$a1,0x3
/*  f178ef8:	24421448 */ 	addiu	$v0,$v0,%lo(g_MpPlayerNum)
/*  f178efc:	0305c023 */ 	subu	$t8,$t8,$a1
/*  f178f00:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f178f04:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f178f08:	ac450000 */ 	sw	$a1,0x0($v0)
/*  f178f0c:	0305c021 */ 	addu	$t8,$t8,$a1
/*  f178f10:	3c19800b */ 	lui	$t9,0x800b
/*  f178f14:	8f39cb94 */ 	lw	$t9,-0x346c($t9)
/*  f178f18:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f178f1c:	0305c023 */ 	subu	$t8,$t8,$a1
/*  f178f20:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f178f24:	3c01800a */ 	lui	$at,0x800a
/*  f178f28:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f178f2c:	00380821 */ 	addu	$at,$at,$t8
/*  f178f30:	33280002 */ 	andi	$t0,$t9,0x2
/*  f178f34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f178f38:	a024e83b */ 	sb	$a0,-0x17c5($at)
/*  f178f3c:	11000027 */ 	beqz	$t0,.L0f178fdc
/*  f178f40:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f178f44:	3c09800b */ 	lui	$t1,0x800b
/*  f178f48:	9129cc10 */ 	lbu	$t1,-0x33f0($t1)
/*  f178f4c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f178f50:	3c048008 */ 	lui	$a0,%hi(menudialog_2aa30)
/*  f178f54:	1521001d */ 	bne	$t1,$at,.L0f178fcc
/*  f178f58:	24844a10 */ 	addiu	$a0,$a0,%lo(menudialog_2aa30)
/*  f178f5c:	3c0a800a */ 	lui	$t2,0x800a
/*  f178f60:	8d4a21d0 */ 	lw	$t2,0x21d0($t2)
/*  f178f64:	3c048008 */ 	lui	$a0,%hi(menudialog_2aa60)
/*  f178f68:	3c0b800a */ 	lui	$t3,0x800a
/*  f178f6c:	15400004 */ 	bnez	$t2,.L0f178f80
/*  f178f70:	24844a40 */ 	addiu	$a0,$a0,%lo(menudialog_2aa60)
/*  f178f74:	8d6b21d4 */ 	lw	$t3,0x21d4($t3)
/*  f178f78:	11600005 */ 	beqz	$t3,.L0f178f90
/*  f178f7c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f178f80:
/*  f178f80:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178f84:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f178f88:	10000018 */ 	beqz	$zero,.L0f178fec
/*  f178f8c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f178f90:
/*  f178f90:	0fc6714f */ 	jal	func0f19c53c
/*  f178f94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f178f98:	10400007 */ 	beqz	$v0,.L0f178fb8
/*  f178f9c:	3c048008 */ 	lui	$a0,%hi(menudialog_2aa78)
/*  f178fa0:	3c048008 */ 	lui	$a0,%hi(menudialog_2aa48)
/*  f178fa4:	24844a28 */ 	addiu	$a0,$a0,%lo(menudialog_2aa48)
/*  f178fa8:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178fac:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f178fb0:	1000000e */ 	beqz	$zero,.L0f178fec
/*  f178fb4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f178fb8:
/*  f178fb8:	24844a58 */ 	addiu	$a0,$a0,%lo(menudialog_2aa78)
/*  f178fbc:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178fc0:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f178fc4:	10000009 */ 	beqz	$zero,.L0f178fec
/*  f178fc8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f178fcc:
/*  f178fcc:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178fd0:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f178fd4:	10000005 */ 	beqz	$zero,.L0f178fec
/*  f178fd8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f178fdc:
/*  f178fdc:	3c048008 */ 	lui	$a0,%hi(menudialog_2aa18)
/*  f178fe0:	248449f8 */ 	addiu	$a0,$a0,%lo(menudialog_2aa18)
/*  f178fe4:	0fc3e0cc */ 	jal	func0f0f8330
/*  f178fe8:	24050005 */ 	addiu	$a1,$zero,0x5
.L0f178fec:
/*  f178fec:	3c0c8007 */ 	lui	$t4,0x8007
/*  f178ff0:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f178ff4:	3c0e800b */ 	lui	$t6,%hi(g_MpPlayers)
/*  f178ff8:	25cec7b8 */ 	addiu	$t6,$t6,%lo(g_MpPlayers)
/*  f178ffc:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f179000:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f179004:	000d6940 */ 	sll	$t5,$t5,0x5
/*  f179008:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f17900c:	94430048 */ 	lhu	$v1,0x48($v0)
/*  f179010:	306f4000 */ 	andi	$t7,$v1,0x4000
/*  f179014:	55e0000c */ 	bnezl	$t7,.L0f179048
/*  f179018:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17901c:	8c58004c */ 	lw	$t8,0x4c($v0)
/*  f179020:	57000009 */ 	bnezl	$t8,.L0f179048
/*  f179024:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f179028:	94590050 */ 	lhu	$t9,0x50($v0)
/*  f17902c:	3c048008 */ 	lui	$a0,%hi(menudialog_2ab34)
/*  f179030:	34684000 */ 	ori	$t0,$v1,0x4000
/*  f179034:	17200003 */ 	bnez	$t9,.L0f179044
/*  f179038:	24844b14 */ 	addiu	$a0,$a0,%lo(menudialog_2ab34)
/*  f17903c:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f179040:	a4480048 */ 	sh	$t0,0x48($v0)
.L0f179044:
/*  f179044:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f179048:
/*  f179048:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*  f17904c:	3c018007 */ 	lui	$at,0x8007
/*  f179050:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f179054:	03e00008 */ 	jr	$ra
/*  f179058:	ac291448 */ 	sw	$t1,0x1448($at)
/*  f17905c:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMpDropOut(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();
	}

	return 0;
}

GLOBAL_ASM(
glabel mpGetCurrentPlayerName
/*  f17909c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f1790a0:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f1790a4:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f1790a8:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f1790ac:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1790b0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1790b4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f1790b8:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f1790bc:	03e00008 */ 	jr	$ra
/*  f1790c0:	01f81021 */ 	addu	$v0,$t7,$t8
);

s32 menuhandlerMpTeamsLabel(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) == 0) {
			return true;
		}
	}

	return 0;
}

u32 func0f1790fc(void)
{
	return 17;
}

GLOBAL_ASM(
glabel func0f179104
/*  f179104:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f179108:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f17910c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f179110:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f179114:	3c108008 */ 	lui	$s0,%hi(mpstages)
/*  f179118:	3c118008 */ 	lui	$s1,%hi(var80084bf8)
/*  f17911c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f179120:	00009025 */ 	or	$s2,$zero,$zero
/*  f179124:	26314bf8 */ 	addiu	$s1,$s1,%lo(var80084bf8)
/*  f179128:	26104b98 */ 	addiu	$s0,$s0,%lo(mpstages)
.L0f17912c:
/*  f17912c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179130:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f179134:	10400002 */ 	beqz	$v0,.L0f179140
/*  f179138:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f17913c:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f179140:
/*  f179140:	0211082b */ 	sltu	$at,$s0,$s1
/*  f179144:	1420fff9 */ 	bnez	$at,.L0f17912c
/*  f179148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17914c:	0c004b70 */ 	jal	random
/*  f179150:	00000000 */ 	sll	$zero,$zero,0x0
/*  f179154:	0052001b */ 	divu	$zero,$v0,$s2
/*  f179158:	16400002 */ 	bnez	$s2,.L0f179164
/*  f17915c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f179160:	0007000d */ 	break	0x7
.L0f179164:
/*  f179164:	00008810 */ 	mfhi	$s1
/*  f179168:	3c128008 */ 	lui	$s2,%hi(var80084bf8)
/*  f17916c:	3c108008 */ 	lui	$s0,%hi(mpstages)
/*  f179170:	26104b98 */ 	addiu	$s0,$s0,%lo(mpstages)
/*  f179174:	26524bf8 */ 	addiu	$s2,$s2,%lo(var80084bf8)
/*  f179178:	00001825 */ 	or	$v1,$zero,$zero
.L0f17917c:
/*  f17917c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179180:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f179184:	50400007 */ 	beqzl	$v0,.L0f1791a4
/*  f179188:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f17918c:	56200004 */ 	bnezl	$s1,.L0f1791a0
/*  f179190:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f179194:	10000006 */ 	beqz	$zero,.L0f1791b0
/*  f179198:	86020000 */ 	lh	$v0,0x0($s0)
/*  f17919c:	2631ffff */ 	addiu	$s1,$s1,-1
.L0f1791a0:
/*  f1791a0:	26100006 */ 	addiu	$s0,$s0,0x6
.L0f1791a4:
/*  f1791a4:	1612fff5 */ 	bne	$s0,$s2,.L0f17917c
/*  f1791a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1791ac:	24020032 */ 	addiu	$v0,$zero,0x32
.L0f1791b0:
/*  f1791b0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1791b4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1791b8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1791bc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1791c0:	03e00008 */ 	jr	$ra
/*  f1791c4:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel menuhandler001791c8
/*  f1791c8:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f1791cc:	3c0f8008 */ 	lui	$t7,%hi(var80084c00)
/*  f1791d0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1791d4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1791d8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1791dc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1791e0:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f1791e4:	25ef4c00 */ 	addiu	$t7,$t7,%lo(var80084c00)
/*  f1791e8:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1791ec:	27ae0040 */ 	addiu	$t6,$sp,0x40
/*  f1791f0:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1791f4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1791f8:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1791fc:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f179200:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f179204:	adc10008 */ 	sw	$at,0x8($t6)
/*  f179208:	8de10010 */ 	lw	$at,0x10($t7)
/*  f17920c:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f179210:	8de80014 */ 	lw	$t0,0x14($t7)
/*  f179214:	2489ffff */ 	addiu	$t1,$a0,-1
/*  f179218:	adc10010 */ 	sw	$at,0x10($t6)
/*  f17921c:	2d210007 */ 	sltiu	$at,$t1,0x7
/*  f179220:	00c09025 */ 	or	$s2,$a2,$zero
/*  f179224:	00008825 */ 	or	$s1,$zero,$zero
/*  f179228:	1020009b */ 	beqz	$at,.L0f179498
/*  f17922c:	adc80014 */ 	sw	$t0,0x14($t6)
/*  f179230:	00094880 */ 	sll	$t1,$t1,0x2
/*  f179234:	3c017f1c */ 	lui	$at,%hi(var7f1b805c)
/*  f179238:	00290821 */ 	addu	$at,$at,$t1
/*  f17923c:	8c29805c */ 	lw	$t1,%lo(var7f1b805c)($at)
/*  f179240:	01200008 */ 	jr	$t1
/*  f179244:	00000000 */ 	sll	$zero,$zero,0x0
/*  f179248:	3c108008 */ 	lui	$s0,%hi(mpstages)
/*  f17924c:	26104b98 */ 	addiu	$s0,$s0,%lo(mpstages)
.L0f179250:
/*  f179250:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179254:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f179258:	10400002 */ 	beqz	$v0,.L0f179264
/*  f17925c:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f179260:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f179264:
/*  f179264:	3c0a8008 */ 	lui	$t2,0x8008
/*  f179268:	254a4bfe */ 	addiu	$t2,$t2,0x4bfe
/*  f17926c:	160afff8 */ 	bne	$s0,$t2,.L0f179250
/*  f179270:	00000000 */ 	sll	$zero,$zero,0x0
/*  f179274:	10000088 */ 	beqz	$zero,.L0f179498
/*  f179278:	ae510000 */ 	sw	$s1,0x0($s2)
/*  f17927c:	3c108008 */ 	lui	$s0,%hi(mpstages)
/*  f179280:	26104b98 */ 	addiu	$s0,$s0,%lo(mpstages)
.L0f179284:
/*  f179284:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179288:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f17928c:	10400009 */ 	beqz	$v0,.L0f1792b4
/*  f179290:	3c0c8008 */ 	lui	$t4,0x8008
/*  f179294:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f179298:	562b0006 */ 	bnel	$s1,$t3,.L0f1792b4
/*  f17929c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1792a0:	0fc5b9f1 */ 	jal	textGet
/*  f1792a4:	96040004 */ 	lhu	$a0,0x4($s0)
/*  f1792a8:	1000007d */ 	beqz	$zero,.L0f1794a0
/*  f1792ac:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1792b0:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1792b4:
/*  f1792b4:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f1792b8:	258c4bfe */ 	addiu	$t4,$t4,0x4bfe
/*  f1792bc:	160cfff1 */ 	bne	$s0,$t4,.L0f179284
/*  f1792c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1792c4:	10000075 */ 	beqz	$zero,.L0f17949c
/*  f1792c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1792cc:	3c108008 */ 	lui	$s0,%hi(mpstages)
/*  f1792d0:	26104b98 */ 	addiu	$s0,$s0,%lo(mpstages)
.L0f1792d4:
/*  f1792d4:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f1792d8:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f1792dc:	10400004 */ 	beqz	$v0,.L0f1792f0
/*  f1792e0:	3c198008 */ 	lui	$t9,0x8008
/*  f1792e4:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f1792e8:	122d0005 */ 	beq	$s1,$t5,.L0f179300
/*  f1792ec:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1792f0:
/*  f1792f0:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f1792f4:	27394bfe */ 	addiu	$t9,$t9,0x4bfe
/*  f1792f8:	1619fff6 */ 	bne	$s0,$t9,.L0f1792d4
/*  f1792fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f179300:
/*  f179300:	86180000 */ 	lh	$t8,0x0($s0)
/*  f179304:	3c01800b */ 	lui	$at,0x800b
/*  f179308:	10000063 */ 	beqz	$zero,.L0f179498
/*  f17930c:	a038cb99 */ 	sb	$t8,-0x3467($at)
/*  f179310:	3c108008 */ 	lui	$s0,%hi(mpstages)
/*  f179314:	26104b98 */ 	addiu	$s0,$s0,%lo(mpstages)
.L0f179318:
/*  f179318:	3c0e800b */ 	lui	$t6,0x800b
/*  f17931c:	91cecb99 */ 	lbu	$t6,-0x3467($t6)
/*  f179320:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f179324:	15cf0002 */ 	bne	$t6,$t7,.L0f179330
/*  f179328:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17932c:	ae510000 */ 	sw	$s1,0x0($s2)
.L0f179330:
/*  f179330:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179334:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f179338:	10400002 */ 	beqz	$v0,.L0f179344
/*  f17933c:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f179340:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f179344:
/*  f179344:	3c088008 */ 	lui	$t0,0x8008
/*  f179348:	25084bfe */ 	addiu	$t0,$t0,0x4bfe
/*  f17934c:	1608fff2 */ 	bne	$s0,$t0,.L0f179318
/*  f179350:	00000000 */ 	sll	$zero,$zero,0x0
/*  f179354:	10000051 */ 	beqz	$zero,.L0f17949c
/*  f179358:	00001025 */ 	or	$v0,$zero,$zero
/*  f17935c:	24090003 */ 	addiu	$t1,$zero,0x3
/*  f179360:	ae490000 */ 	sw	$t1,0x0($s2)
/*  f179364:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179368:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f17936c:	5440004b */ 	bnezl	$v0,.L0f17949c
/*  f179370:	00001025 */ 	or	$v0,$zero,$zero
/*  f179374:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179378:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f17937c:	54400047 */ 	bnezl	$v0,.L0f17949c
/*  f179380:	00001025 */ 	or	$v0,$zero,$zero
/*  f179384:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179388:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f17938c:	54400043 */ 	bnezl	$v0,.L0f17949c
/*  f179390:	00001025 */ 	or	$v0,$zero,$zero
/*  f179394:	8e4a0000 */ 	lw	$t2,0x0($s2)
/*  f179398:	254bffff */ 	addiu	$t3,$t2,-1
/*  f17939c:	1000003e */ 	beqz	$zero,.L0f179498
/*  f1793a0:	ae4b0000 */ 	sw	$t3,0x0($s2)
/*  f1793a4:	8e510000 */ 	lw	$s1,0x0($s2)
/*  f1793a8:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f1793ac:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f1793b0:	5440000d */ 	bnezl	$v0,.L0f1793e8
/*  f1793b4:	001160c0 */ 	sll	$t4,$s1,0x3
/*  f1793b8:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f1793bc:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f1793c0:	54400009 */ 	bnezl	$v0,.L0f1793e8
/*  f1793c4:	001160c0 */ 	sll	$t4,$s1,0x3
/*  f1793c8:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f1793cc:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f1793d0:	54400005 */ 	bnezl	$v0,.L0f1793e8
/*  f1793d4:	001160c0 */ 	sll	$t4,$s1,0x3
/*  f1793d8:	5a200003 */ 	blezl	$s1,.L0f1793e8
/*  f1793dc:	001160c0 */ 	sll	$t4,$s1,0x3
/*  f1793e0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1793e4:	001160c0 */ 	sll	$t4,$s1,0x3
.L0f1793e8:
/*  f1793e8:	03ac2021 */ 	addu	$a0,$sp,$t4
/*  f1793ec:	0fc5b9f1 */ 	jal	textGet
/*  f1793f0:	94840044 */ 	lhu	$a0,0x44($a0)
/*  f1793f4:	1000002a */ 	beqz	$zero,.L0f1794a0
/*  f1793f8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1793fc:	8e500000 */ 	lw	$s0,0x0($s2)
/*  f179400:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179404:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f179408:	5440000d */ 	bnezl	$v0,.L0f179440
/*  f17940c:	001068c0 */ 	sll	$t5,$s0,0x3
/*  f179410:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179414:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f179418:	54400009 */ 	bnezl	$v0,.L0f179440
/*  f17941c:	001068c0 */ 	sll	$t5,$s0,0x3
/*  f179420:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179424:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f179428:	14400004 */ 	bnez	$v0,.L0f17943c
/*  f17942c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f179430:	56010003 */ 	bnel	$s0,$at,.L0f179440
/*  f179434:	001068c0 */ 	sll	$t5,$s0,0x3
/*  f179438:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f17943c:
/*  f17943c:	001068c0 */ 	sll	$t5,$s0,0x3
.L0f179440:
/*  f179440:	27b90040 */ 	addiu	$t9,$sp,0x40
/*  f179444:	01b92821 */ 	addu	$a1,$t5,$t9
/*  f179448:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f17944c:	3c108008 */ 	lui	$s0,%hi(mpstages)
/*  f179450:	26104b98 */ 	addiu	$s0,$s0,%lo(mpstages)
/*  f179454:	1b00000f */ 	blez	$t8,.L0f179494
/*  f179458:	00001825 */ 	or	$v1,$zero,$zero
/*  f17945c:	92040002 */ 	lbu	$a0,0x2($s0)
.L0f179460:
/*  f179460:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f179464:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179468:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f17946c:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f179470:	10400002 */ 	beqz	$v0,.L0f17947c
/*  f179474:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f179478:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f17947c:
/*  f17947c:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f179480:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f179484:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f179488:	006e082a */ 	slt	$at,$v1,$t6
/*  f17948c:	5420fff4 */ 	bnezl	$at,.L0f179460
/*  f179490:	92040002 */ 	lbu	$a0,0x2($s0)
.L0f179494:
/*  f179494:	ae510008 */ 	sw	$s1,0x8($s2)
.L0f179498:
/*  f179498:	00001025 */ 	or	$v0,$zero,$zero
.L0f17949c:
/*  f17949c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f1794a0:
/*  f1794a0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1794a4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1794a8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1794ac:	03e00008 */ 	jr	$ra
/*  f1794b0:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

char *menuhandlerMpControlStyle(u32 operation, struct menu_item *item, s32 *value)
{
	u16 labels[4] = g_MpControlStyleLabels;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		*value = 4;
		break;
	case MENUOP_GETOPTIONTEXT:
		return textGet(labels[*value]);
	case MENUOP_SET:
		optionsSetControlMode(g_MpPlayerNum, *value);
		break;
	case MENUOP_GETOPTIONVALUE:
		*value = optionsGetControlMode(g_MpPlayerNum);
		break;
	}

	return NULL;
}

char *menuhandlerMpWeaponSlot(u32 operation, struct menu_item *item, s32 *value)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		*value = mpGetNumWeaponOptions();
		break;
	case MENUOP_GETOPTIONTEXT:
		return mpGetWeaponLabel(*value);
	case MENUOP_SET:
		mpSetWeaponSlot(item->param3, *value);
		break;
	case MENUOP_GETOPTIONVALUE:
		*value = mpGetWeaponSlot(item->param3);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f17960c
/*  f17960c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f179610:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f179614:	0fc62365 */ 	jal	mpGetWeaponSlot
/*  f179618:	90840001 */ 	lbu	$a0,0x1($a0)
/*  f17961c:	0fc6230f */ 	jal	mpGetWeaponLabel
/*  f179620:	00402025 */ 	or	$a0,$v0,$zero
/*  f179624:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f179628:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17962c:	03e00008 */ 	jr	$ra
/*  f179630:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMpWeaponSetDropdown(u32 operation, struct menu_item *item, s32 *value)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		*value = func0f189058(item->param);
		break;
	case MENUOP_GETOPTIONTEXT:
		return func0f1890a8(*value);
	case MENUOP_SET:
		func0f1895bc(*value);
		break;
	case MENUOP_GETOPTIONVALUE:
		*value = func0f18961c();
		break;
	}

	return 0;
}

s32 menuhandlerMpControlCheckbox(u32 operation, struct menu_item *item, s32 *value)
{
	u32 val;

	switch (operation) {
	case MENUOP_GET:
		if (item->param3 == OPTION_FORWARDPITCH) {
			if ((g_MpPlayers[g_MpPlayerNum].options & item->param3) == 0) {
				return true;
			}
			return false;
		}
		if ((g_MpPlayers[g_MpPlayerNum].options & item->param3) == 0) {
			return false;
		}
		return true;
	case MENUOP_SET:
		val = OPTION_FORWARDPITCH;

		if (item->param3 == val) {
			if (*value == 0) {
				*value = val;
			} else {
				*value = 0;
			}
		}

		g_MpPlayers[g_MpPlayerNum].options &= ~item->param3;

		if (*value) {
			g_MpPlayers[g_MpPlayerNum].options |= item->param3;
		}
	}

	return 0;
}

char *menuhandlerMpAimControl(u32 operation, struct menu_item *item, s32 *value)
{
	u16 labels[2] = g_MpAimModeLabels;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		*value = 2;
		break;
	case MENUOP_GETOPTIONTEXT:
		return textGet(labels[*value]);
	case MENUOP_SET:
		optionsSetAimControl(g_MpPlayerNum, *value);
		break;
	case MENUOP_GETOPTIONVALUE:
		*value = optionsGetAimControl(g_MpPlayerNum);
		break;
	}

	return NULL;
}

s32 menuhandlerMpCheckboxOption(u32 operation, struct menu_item *item, s32 *value)
{
	switch (operation) {
	case MENUOP_GET:
		if ((g_MpSetup.options & item->param3) == 0) {
			return false;
		}
		return true;
	case MENUOP_SET:
		g_MpSetup.options = g_MpSetup.options & ~item->param3;
		if (*value) {
			g_MpSetup.options = g_MpSetup.options | item->param3;
		}
	}

	return 0;
}

s32 menuhandlerMpTeamsEnabled(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE ||
				g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
			return true;
		}

		return false;
	}

	return menuhandlerMpCheckboxOption(operation, item, value);
}

s32 menuhandlerMpDisplayOptionCheckbox(u32 operation, struct menu_item *item, s32 *value)
{
	switch (operation) {
	case MENUOP_GET:
		if ((g_MpPlayers[g_MpPlayerNum].base.displayoptions & item->param3) == 0) {
			return false;
		}
		return true;
	case MENUOP_SET:
		g_MpPlayers[g_MpPlayerNum].base.displayoptions &= ~(u8)item->param3;

		if (*value) {
			g_MpPlayers[g_MpPlayerNum].base.displayoptions |= (u8)item->param3;
		}
		break;
	}

	return 0;
}

s32 menuhandlerMpConfirmSaveChr(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		func0f10a51c(6, 2);
	}

	return 0;
}

s32 menuhandlerMpPlayerName(u32 operation, struct menu_item *item, char **value)
{
	char *ptr = *value;

	switch (operation) {
	case MENUOP_GETTEXT:
		strcpy(ptr, &g_MpSetup.namebuffer);
		break;
	case MENUOP_SETTEXT:
		strcpy(&g_MpSetup.namebuffer, ptr);
		break;
	case MENUOP_SET:
		func0f10a51c(7, 1);
		break;
	}

	return 0;
}

s32 menuhandlerMpSaveSetupOverwrite(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		func0f1094e4(&g_MpSetup.saved, 4, 0);
	}

	return 0;
}

s32 menuhandlerMpSaveSetupCopy(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPushDialog(&menudialog_mpsavesetupname);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f179b58
/*  f179b58:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f179b5c:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f179b60:	03e00008 */ 	jr	$ra
/*  f179b64:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f179b68:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f179b6c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f179b70:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f179b74:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f179b78:	10810012 */ 	beq	$a0,$at,.L0f179bc4
/*  f179b7c:	00c03825 */ 	or	$a3,$a2,$zero
/*  f179b80:	24010009 */ 	addiu	$at,$zero,0x9
/*  f179b84:	10810006 */ 	beq	$a0,$at,.L0f179ba0
/*  f179b88:	3c0e8007 */ 	lui	$t6,0x8007
/*  f179b8c:	2401000a */ 	addiu	$at,$zero,0xa
/*  f179b90:	10810016 */ 	beq	$a0,$at,.L0f179bec
/*  f179b94:	3c057f1b */ 	lui	$a1,%hi(var7f1b7e90)
/*  f179b98:	1000001a */ 	beqz	$zero,.L0f179c04
/*  f179b9c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f179ba0:
/*  f179ba0:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f179ba4:	3c18800b */ 	lui	$t8,0x800b
/*  f179ba8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f179bac:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f179bb0:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f179bb4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f179bb8:	9718c7d0 */ 	lhu	$t8,-0x3830($t8)
/*  f179bbc:	10000010 */ 	beqz	$zero,.L0f179c00
/*  f179bc0:	acf80000 */ 	sw	$t8,0x0($a3)
.L0f179bc4:
/*  f179bc4:	3c088007 */ 	lui	$t0,0x8007
/*  f179bc8:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f179bcc:	90f90003 */ 	lbu	$t9,0x3($a3)
/*  f179bd0:	3c01800b */ 	lui	$at,0x800b
/*  f179bd4:	00084880 */ 	sll	$t1,$t0,0x2
/*  f179bd8:	01284821 */ 	addu	$t1,$t1,$t0
/*  f179bdc:	00094940 */ 	sll	$t1,$t1,0x5
/*  f179be0:	00290821 */ 	addu	$at,$at,$t1
/*  f179be4:	10000006 */ 	beqz	$zero,.L0f179c00
/*  f179be8:	a439c7d0 */ 	sh	$t9,-0x3830($at)
.L0f179bec:
/*  f179bec:	8ce60000 */ 	lw	$a2,0x0($a3)
/*  f179bf0:	8ce40004 */ 	lw	$a0,0x4($a3)
/*  f179bf4:	24a57e90 */ 	addiu	$a1,$a1,%lo(var7f1b7e90)
/*  f179bf8:	0c004dad */ 	jal	sprintf
/*  f179bfc:	24c60014 */ 	addiu	$a2,$a2,0x14
.L0f179c00:
/*  f179c00:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f179c04:
/*  f179c04:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f179c08:	00001025 */ 	or	$v0,$zero,$zero
/*  f179c0c:	03e00008 */ 	jr	$ra
/*  f179c10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f179c14:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f179c18:	24010006 */ 	addiu	$at,$zero,0x6
/*  f179c1c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f179c20:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f179c24:	10810012 */ 	beq	$a0,$at,.L0f179c70
/*  f179c28:	00c03825 */ 	or	$a3,$a2,$zero
/*  f179c2c:	24010009 */ 	addiu	$at,$zero,0x9
/*  f179c30:	10810006 */ 	beq	$a0,$at,.L0f179c4c
/*  f179c34:	3c0e8007 */ 	lui	$t6,0x8007
/*  f179c38:	2401000a */ 	addiu	$at,$zero,0xa
/*  f179c3c:	10810016 */ 	beq	$a0,$at,.L0f179c98
/*  f179c40:	3c057f1b */ 	lui	$a1,%hi(var7f1b7e98)
/*  f179c44:	1000001a */ 	beqz	$zero,.L0f179cb0
/*  f179c48:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f179c4c:
/*  f179c4c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f179c50:	3c18800b */ 	lui	$t8,0x800b
/*  f179c54:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f179c58:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f179c5c:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f179c60:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f179c64:	9718c7d2 */ 	lhu	$t8,-0x382e($t8)
/*  f179c68:	10000010 */ 	beqz	$zero,.L0f179cac
/*  f179c6c:	acf80000 */ 	sw	$t8,0x0($a3)
.L0f179c70:
/*  f179c70:	3c088007 */ 	lui	$t0,0x8007
/*  f179c74:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f179c78:	90f90003 */ 	lbu	$t9,0x3($a3)
/*  f179c7c:	3c01800b */ 	lui	$at,0x800b
/*  f179c80:	00084880 */ 	sll	$t1,$t0,0x2
/*  f179c84:	01284821 */ 	addu	$t1,$t1,$t0
/*  f179c88:	00094940 */ 	sll	$t1,$t1,0x5
/*  f179c8c:	00290821 */ 	addu	$at,$at,$t1
/*  f179c90:	10000006 */ 	beqz	$zero,.L0f179cac
/*  f179c94:	a439c7d2 */ 	sh	$t9,-0x382e($at)
.L0f179c98:
/*  f179c98:	8ce60000 */ 	lw	$a2,0x0($a3)
/*  f179c9c:	8ce40004 */ 	lw	$a0,0x4($a3)
/*  f179ca0:	24a57e98 */ 	addiu	$a1,$a1,%lo(var7f1b7e98)
/*  f179ca4:	0c004dad */ 	jal	sprintf
/*  f179ca8:	24c60014 */ 	addiu	$a2,$a2,0x14
.L0f179cac:
/*  f179cac:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f179cb0:
/*  f179cb0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f179cb4:	00001025 */ 	or	$v0,$zero,$zero
/*  f179cb8:	03e00008 */ 	jr	$ra
/*  f179cbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f179cc0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f179cc4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f179cc8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f179ccc:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f179cd0:	10810012 */ 	beq	$a0,$at,.L0f179d1c
/*  f179cd4:	00c03825 */ 	or	$a3,$a2,$zero
/*  f179cd8:	24010009 */ 	addiu	$at,$zero,0x9
/*  f179cdc:	10810006 */ 	beq	$a0,$at,.L0f179cf8
/*  f179ce0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f179ce4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f179ce8:	10810016 */ 	beq	$a0,$at,.L0f179d44
/*  f179cec:	3c057f1b */ 	lui	$a1,%hi(var7f1b7ea0)
/*  f179cf0:	1000001a */ 	beqz	$zero,.L0f179d5c
/*  f179cf4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f179cf8:
/*  f179cf8:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f179cfc:	3c18800b */ 	lui	$t8,0x800b
/*  f179d00:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f179d04:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f179d08:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f179d0c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f179d10:	9718c7d4 */ 	lhu	$t8,-0x382c($t8)
/*  f179d14:	10000010 */ 	beqz	$zero,.L0f179d58
/*  f179d18:	acf80000 */ 	sw	$t8,0x0($a3)
.L0f179d1c:
/*  f179d1c:	3c088007 */ 	lui	$t0,0x8007
/*  f179d20:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f179d24:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f179d28:	3c01800b */ 	lui	$at,0x800b
/*  f179d2c:	00084880 */ 	sll	$t1,$t0,0x2
/*  f179d30:	01284821 */ 	addu	$t1,$t1,$t0
/*  f179d34:	00094940 */ 	sll	$t1,$t1,0x5
/*  f179d38:	00290821 */ 	addu	$at,$at,$t1
/*  f179d3c:	10000006 */ 	beqz	$zero,.L0f179d58
/*  f179d40:	a439c7d4 */ 	sh	$t9,-0x382c($at)
.L0f179d44:
/*  f179d44:	8ce60000 */ 	lw	$a2,0x0($a3)
/*  f179d48:	8ce40004 */ 	lw	$a0,0x4($a3)
/*  f179d4c:	24a57ea0 */ 	addiu	$a1,$a1,%lo(var7f1b7ea0)
/*  f179d50:	0c004dad */ 	jal	sprintf
/*  f179d54:	24c60019 */ 	addiu	$a2,$a2,0x19
.L0f179d58:
/*  f179d58:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f179d5c:
/*  f179d5c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f179d60:	00001025 */ 	or	$v0,$zero,$zero
/*  f179d64:	03e00008 */ 	jr	$ra
/*  f179d68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f179d6c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f179d70:	24010006 */ 	addiu	$at,$zero,0x6
/*  f179d74:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f179d78:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f179d7c:	14810004 */ 	bne	$a0,$at,.L0f179d90
/*  f179d80:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f179d84:	3c048007 */ 	lui	$a0,0x8007
/*  f179d88:	0fc61fef */ 	jal	func0f187fbc
/*  f179d8c:	8c841448 */ 	lw	$a0,0x1448($a0)
.L0f179d90:
/*  f179d90:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f179d94:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f179d98:	00001025 */ 	or	$v0,$zero,$zero
/*  f179d9c:	03e00008 */ 	jr	$ra
/*  f179da0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f179da4
/*  f179da4:	248effff */ 	addiu	$t6,$a0,-1
/*  f179da8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f179dac:	2dc10015 */ 	sltiu	$at,$t6,0x15
/*  f179db0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f179db4:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f179db8:	10200096 */ 	beqz	$at,.L0f17a014
/*  f179dbc:	00801825 */ 	or	$v1,$a0,$zero
/*  f179dc0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f179dc4:	3c017f1c */ 	lui	$at,%hi(var7f1b8078)
/*  f179dc8:	002e0821 */ 	addu	$at,$at,$t6
/*  f179dcc:	8c2e8078 */ 	lw	$t6,%lo(var7f1b8078)($at)
/*  f179dd0:	01c00008 */ 	jr	$t6
/*  f179dd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f179dd8:	0fc62ee2 */ 	jal	mpGetNumBodies
/*  f179ddc:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f179de0:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f179de4:	1000008b */ 	beqz	$zero,.L0f17a014
/*  f179de8:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f179dec:	3c0f8007 */ 	lui	$t7,0x8007
/*  f179df0:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f179df4:	3c19800a */ 	lui	$t9,%hi(var8009e000)
/*  f179df8:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f179dfc:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f179e00:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f179e04:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f179e08:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f179e0c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f179e10:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f179e14:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f179e18:	2739e000 */ 	addiu	$t9,$t9,%lo(var8009e000)
/*  f179e1c:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f179e20:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f179e24:	03191021 */ 	addu	$v0,$t8,$t9
/*  f179e28:	8c4e0db4 */ 	lw	$t6,0xdb4($v0)
/*  f179e2c:	8ca40000 */ 	lw	$a0,0x0($a1)
/*  f179e30:	00095400 */ 	sll	$t2,$t1,0x10
/*  f179e34:	354bffff */ 	ori	$t3,$t2,0xffff
/*  f179e38:	00076600 */ 	sll	$t4,$a3,0x18
/*  f179e3c:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f179e40:	240801fc */ 	addiu	$t0,$zero,0x1fc
/*  f179e44:	016c6825 */ 	or	$t5,$t3,$t4
/*  f179e48:	29e101e1 */ 	slti	$at,$t7,0x1e1
/*  f179e4c:	a448089c */ 	sh	$t0,0x89c($v0)
/*  f179e50:	ac4d084c */ 	sw	$t5,0x84c($v0)
/*  f179e54:	14200003 */ 	bnez	$at,.L0f179e64
/*  f179e58:	ac4f0db4 */ 	sw	$t7,0xdb4($v0)
/*  f179e5c:	25f8fe20 */ 	addiu	$t8,$t7,-480
/*  f179e60:	ac580db4 */ 	sw	$t8,0xdb4($v0)
.L0f179e64:
/*  f179e64:	8c430db8 */ 	lw	$v1,0xdb8($v0)
/*  f179e68:	3c017f1c */ 	lui	$at,%hi(var7f1b80cc)
/*  f179e6c:	18600003 */ 	blez	$v1,.L0f179e7c
/*  f179e70:	0064c823 */ 	subu	$t9,$v1,$a0
/*  f179e74:	10000008 */ 	beqz	$zero,.L0f179e98
/*  f179e78:	ac590db8 */ 	sw	$t9,0xdb8($v0)
.L0f179e7c:
/*  f179e7c:	c42480cc */ 	lwc1	$f4,%lo(var7f1b80cc)($at)
/*  f179e80:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f179e84:	c44a0d64 */ 	lwc1	$f10,0xd64($v0)
/*  f179e88:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f179e8c:	46085000 */ 	add.s	$f0,$f10,$f8
/*  f179e90:	e4400d8c */ 	swc1	$f0,0xd8c($v0)
/*  f179e94:	e4400d64 */ 	swc1	$f0,0xd64($v0)
.L0f179e98:
/*  f179e98:	3c0141f0 */ 	lui	$at,0x41f0
/*  f179e9c:	44818000 */ 	mtc1	$at,$f16
/*  f179ea0:	ac400df4 */ 	sw	$zero,0xdf4($v0)
/*  f179ea4:	1000005b */ 	beqz	$zero,.L0f17a014
/*  f179ea8:	e4500d94 */ 	swc1	$f16,0xd94($v0)
/*  f179eac:	0fc62f1c */ 	jal	mpGetBodyUnk06
/*  f179eb0:	90c40003 */ 	lbu	$a0,0x3($a2)
/*  f179eb4:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f179eb8:	00402025 */ 	or	$a0,$v0,$zero
/*  f179ebc:	54400056 */ 	bnezl	$v0,.L0f17a018
/*  f179ec0:	00001025 */ 	or	$v0,$zero,$zero
/*  f179ec4:	10000054 */ 	beqz	$zero,.L0f17a018
/*  f179ec8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f179ecc:	3c098007 */ 	lui	$t1,0x8007
/*  f179ed0:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f179ed4:	3c01800a */ 	lui	$at,0x800a
/*  f179ed8:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f179edc:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f179ee0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f179ee4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f179ee8:	01495021 */ 	addu	$t2,$t2,$t1
/*  f179eec:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f179ef0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f179ef4:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f179ef8:	002a0821 */ 	addu	$at,$at,$t2
/*  f179efc:	10000045 */ 	beqz	$zero,.L0f17a014
/*  f179f00:	a028e840 */ 	sb	$t0,-0x17c0($at)
/*  f179f04:	10000043 */ 	beqz	$zero,.L0f17a014
/*  f179f08:	acc70000 */ 	sw	$a3,0x0($a2)
/*  f179f0c:	3c0b8007 */ 	lui	$t3,0x8007
/*  f179f10:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f179f14:	44800000 */ 	mtc1	$zero,$f0
/*  f179f18:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f179f1c:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f179f20:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f179f24:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f179f28:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f179f2c:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f179f30:	3c013f80 */ 	lui	$at,0x3f80
/*  f179f34:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f179f38:	44819000 */ 	mtc1	$at,$f18
/*  f179f3c:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f179f40:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f179f44:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f179f48:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f179f4c:	44050000 */ 	mfc1	$a1,$f0
/*  f179f50:	44060000 */ 	mfc1	$a2,$f0
/*  f179f54:	44070000 */ 	mfc1	$a3,$f0
/*  f179f58:	ac400dc0 */ 	sw	$zero,0xdc0($v0)
/*  f179f5c:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f179f60:	24440840 */ 	addiu	$a0,$v0,0x840
/*  f179f64:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f179f68:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f179f6c:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f179f70:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f179f74:	0fc3cdcb */ 	jal	func0f0f372c
/*  f179f78:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f179f7c:	3c0f8007 */ 	lui	$t7,0x8007
/*  f179f80:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f179f84:	3c017f1c */ 	lui	$at,%hi(var7f1b80d0)
/*  f179f88:	c42080d0 */ 	lwc1	$f0,%lo(var7f1b80d0)($at)
/*  f179f8c:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f179f90:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f179f94:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f179f98:	3c017f1c */ 	lui	$at,%hi(var7f1b80d4)
/*  f179f9c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f179fa0:	c42280d4 */ 	lwc1	$f2,%lo(var7f1b80d4)($at)
/*  f179fa4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f179fa8:	3c017f1c */ 	lui	$at,%hi(var7f1b80d8)
/*  f179fac:	3c19800a */ 	lui	$t9,%hi(var8009e000)
/*  f179fb0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f179fb4:	c42c80d8 */ 	lwc1	$f12,%lo(var7f1b80d8)($at)
/*  f179fb8:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f179fbc:	2739e000 */ 	addiu	$t9,$t9,%lo(var8009e000)
/*  f179fc0:	03191021 */ 	addu	$v0,$t8,$t9
/*  f179fc4:	3c017f1c */ 	lui	$at,%hi(var7f1b80dc)
/*  f179fc8:	e4400d50 */ 	swc1	$f0,0xd50($v0)
/*  f179fcc:	e4400d78 */ 	swc1	$f0,0xd78($v0)
/*  f179fd0:	e4420d54 */ 	swc1	$f2,0xd54($v0)
/*  f179fd4:	e4420d7c */ 	swc1	$f2,0xd7c($v0)
/*  f179fd8:	c42480dc */ 	lwc1	$f4,%lo(var7f1b80dc)($at)
/*  f179fdc:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f179fe0:	2409003c */ 	addiu	$t1,$zero,0x3c
/*  f179fe4:	24080078 */ 	addiu	$t0,$zero,0x78
/*  f179fe8:	240a0008 */ 	addiu	$t2,$zero,0x8
/*  f179fec:	2401000f */ 	addiu	$at,$zero,0xf
/*  f179ff0:	ac490db8 */ 	sw	$t1,0xdb8($v0)
/*  f179ff4:	ac480db4 */ 	sw	$t0,0xdb4($v0)
/*  f179ff8:	a04a0840 */ 	sb	$t2,0x840($v0)
/*  f179ffc:	e44c0d64 */ 	swc1	$f12,0xd64($v0)
/*  f17a000:	e44c0d8c */ 	swc1	$f12,0xd8c($v0)
/*  f17a004:	14610003 */ 	bne	$v1,$at,.L0f17a014
/*  f17a008:	e4440d5c */ 	swc1	$f4,0xd5c($v0)
/*  f17a00c:	240b0010 */ 	addiu	$t3,$zero,0x10
/*  f17a010:	a04b0840 */ 	sb	$t3,0x840($v0)
.L0f17a014:
/*  f17a014:	00001025 */ 	or	$v0,$zero,$zero
.L0f17a018:
/*  f17a018:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17a01c:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f17a020:	03e00008 */ 	jr	$ra
/*  f17a024:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMpCharacterBody(u32 operation, struct menu_item *item, struct numandtext *value)
{
	switch (operation) {
	case MENUOP_SET:
		if (g_MpPlayers[g_MpPlayerNum].base.headnum < mpGetNumHeads()) {
			if (!value->text) {
				g_MpPlayers[g_MpPlayerNum].base.headnum = func0f18bc9c(value->num);
			}
		}
		g_MpPlayers[g_MpPlayerNum].base.bodynum = value->num;
		func0f17b8f0();
		break;
	case MENUOP_CHECKPREFOCUSED:
		func0f179da4(operation, item, &value->num,
				g_MpPlayers[g_MpPlayerNum].base.bodynum,
				g_MpPlayers[g_MpPlayerNum].base.headnum, 1);
		return true;
	}

	return func0f179da4(operation, item, &value->num,
			g_MpPlayers[g_MpPlayerNum].base.bodynum,
			g_MpPlayers[g_MpPlayerNum].base.headnum, 1);
}

GLOBAL_ASM(
glabel menudialog0017a174
/*  f17a174:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f17a178:	24010064 */ 	addiu	$at,$zero,0x64
/*  f17a17c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a180:	1081001d */ 	beq	$a0,$at,.L0f17a1f8
/*  f17a184:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f17a188:	24010065 */ 	addiu	$at,$zero,0x65
/*  f17a18c:	1081001a */ 	beq	$a0,$at,.L0f17a1f8
/*  f17a190:	24010066 */ 	addiu	$at,$zero,0x66
/*  f17a194:	14810018 */ 	bne	$a0,$at,.L0f17a1f8
/*  f17a198:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17a19c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17a1a0:	3c02800a */ 	lui	$v0,0x800a
/*  f17a1a4:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17a1a8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17a1ac:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17a1b0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17a1b4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17a1b8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17a1bc:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17a1c0:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f17a1c4:	8c42e4f8 */ 	lw	$v0,-0x1b08($v0)
/*  f17a1c8:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f17a1cc:	54b8000b */ 	bnel	$a1,$t8,.L0f17a1fc
/*  f17a1d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17a1d4:	8ca30008 */ 	lw	$v1,0x8($a1)
/*  f17a1d8:	8c440008 */ 	lw	$a0,0x8($v0)
/*  f17a1dc:	24790014 */ 	addiu	$t9,$v1,0x14
/*  f17a1e0:	13240005 */ 	beq	$t9,$a0,.L0f17a1f8
/*  f17a1e4:	24650028 */ 	addiu	$a1,$v1,0x28
/*  f17a1e8:	10a40003 */ 	beq	$a1,$a0,.L0f17a1f8
/*  f17a1ec:	27a60028 */ 	addiu	$a2,$sp,0x28
/*  f17a1f0:	0fc5e80a */ 	jal	menuhandlerMpCharacterBody
/*  f17a1f4:	2404000b */ 	addiu	$a0,$zero,0xb
.L0f17a1f8:
/*  f17a1f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17a1fc:
/*  f17a1fc:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f17a200:	00001025 */ 	or	$v0,$zero,$zero
/*  f17a204:	03e00008 */ 	jr	$ra
/*  f17a208:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler0017a20c
/*  f17a20c:	27bdff38 */ 	addiu	$sp,$sp,-200
/*  f17a210:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f17a214:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f17a218:	00c08025 */ 	or	$s0,$a2,$zero
/*  f17a21c:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f17a220:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f17a224:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f17a228:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f17a22c:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f17a230:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f17a234:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f17a238:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f17a23c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f17a240:	10830009 */ 	beq	$a0,$v1,.L0f17a268
/*  f17a244:	afa500cc */ 	sw	$a1,0xcc($sp)
/*  f17a248:	24010013 */ 	addiu	$at,$zero,0x13
/*  f17a24c:	1081000b */ 	beq	$a0,$at,.L0f17a27c
/*  f17a250:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f17a254:	24010014 */ 	addiu	$at,$zero,0x14
/*  f17a258:	108100f1 */ 	beq	$a0,$at,.L0f17a620
/*  f17a25c:	240b001a */ 	addiu	$t3,$zero,0x1a
/*  f17a260:	100000f1 */ 	beqz	$zero,.L0f17a628
/*  f17a264:	00001025 */ 	or	$v0,$zero,$zero
.L0f17a268:
/*  f17a268:	3c048007 */ 	lui	$a0,0x8007
/*  f17a26c:	0fc670b3 */ 	jal	mpGetNumChallengesAvailable
/*  f17a270:	8c841448 */ 	lw	$a0,0x1448($a0)
/*  f17a274:	100000eb */ 	beqz	$zero,.L0f17a624
/*  f17a278:	ae020000 */ 	sw	$v0,0x0($s0)
.L0f17a27c:
/*  f17a27c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f17a280:	3c188009 */ 	lui	$t8,0x8009
/*  f17a284:	93180af0 */ 	lbu	$t8,0xaf0($t8)
/*  f17a288:	afae00c4 */ 	sw	$t6,0xc4($sp)
/*  f17a28c:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f17a290:	8e110008 */ 	lw	$s1,0x8($s0)
/*  f17a294:	14780002 */ 	bne	$v1,$t8,.L0f17a2a0
/*  f17a298:	afaf00bc */ 	sw	$t7,0xbc($sp)
/*  f17a29c:	24020002 */ 	addiu	$v0,$zero,0x2
.L0f17a2a0:
/*  f17a2a0:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f17a2a4:	8fa400c4 */ 	lw	$a0,0xc4($sp)
/*  f17a2a8:	272b000a */ 	addiu	$t3,$t9,0xa
/*  f17a2ac:	afab00b8 */ 	sw	$t3,0xb8($sp)
/*  f17a2b0:	8e2c0004 */ 	lw	$t4,0x4($s1)
/*  f17a2b4:	afa200ac */ 	sw	$v0,0xac($sp)
/*  f17a2b8:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f17a2bc:	0fc54d8a */ 	jal	func0f153628
/*  f17a2c0:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f17a2c4:	3c048007 */ 	lui	$a0,0x8007
/*  f17a2c8:	afa200c4 */ 	sw	$v0,0xc4($sp)
/*  f17a2cc:	8c841448 */ 	lw	$a0,0x1448($a0)
/*  f17a2d0:	0fc670df */ 	jal	mpChallengeGetNameWithArg
/*  f17a2d4:	8fa500bc */ 	lw	$a1,0xbc($sp)
/*  f17a2d8:	0c002f02 */ 	jal	func0000bc08
/*  f17a2dc:	00408025 */ 	or	$s0,$v0,$zero
/*  f17a2e0:	00029400 */ 	sll	$s2,$v0,0x10
/*  f17a2e4:	00127403 */ 	sra	$t6,$s2,0x10
/*  f17a2e8:	0c002f06 */ 	jal	func0000bc18
/*  f17a2ec:	01c09025 */ 	or	$s2,$t6,$zero
/*  f17a2f0:	3c0f8008 */ 	lui	$t7,0x8008
/*  f17a2f4:	3c188008 */ 	lui	$t8,0x8008
/*  f17a2f8:	8f18fb0c */ 	lw	$t8,-0x4f4($t8)
/*  f17a2fc:	8deffb10 */ 	lw	$t7,-0x4f0($t7)
/*  f17a300:	8fa400c4 */ 	lw	$a0,0xc4($sp)
/*  f17a304:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f17a308:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f17a30c:	8e39000c */ 	lw	$t9,0xc($s1)
/*  f17a310:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f17a314:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f17a318:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f17a31c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f17a320:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f17a324:	27a600b4 */ 	addiu	$a2,$sp,0xb4
/*  f17a328:	02003825 */ 	or	$a3,$s0,$zero
/*  f17a32c:	0fc5580f */ 	jal	func0f15603c
/*  f17a330:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f17a334:	afa200c4 */ 	sw	$v0,0xc4($sp)
/*  f17a338:	0fc54de0 */ 	jal	func0f153780
/*  f17a33c:	00402025 */ 	or	$a0,$v0,$zero
/*  f17a340:	244b0008 */ 	addiu	$t3,$v0,0x8
/*  f17a344:	afab00c4 */ 	sw	$t3,0xc4($sp)
/*  f17a348:	3c0ce700 */ 	lui	$t4,0xe700
/*  f17a34c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f17a350:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f17a354:	8fad00c4 */ 	lw	$t5,0xc4($sp)
/*  f17a358:	3c0fba00 */ 	lui	$t7,0xba00
/*  f17a35c:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f17a360:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f17a364:	afae00c4 */ 	sw	$t6,0xc4($sp)
/*  f17a368:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f17a36c:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f17a370:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f17a374:	3c0bb900 */ 	lui	$t3,0xb900
/*  f17a378:	356b0002 */ 	ori	$t3,$t3,0x2
/*  f17a37c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f17a380:	afb900c4 */ 	sw	$t9,0xc4($sp)
/*  f17a384:	af000004 */ 	sw	$zero,0x4($t8)
/*  f17a388:	af0b0000 */ 	sw	$t3,0x0($t8)
/*  f17a38c:	8fac00c4 */ 	lw	$t4,0xc4($sp)
/*  f17a390:	3c0eba00 */ 	lui	$t6,0xba00
/*  f17a394:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f17a398:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f17a39c:	afad00c4 */ 	sw	$t5,0xc4($sp)
/*  f17a3a0:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f17a3a4:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f17a3a8:	8faf00c4 */ 	lw	$t7,0xc4($sp)
/*  f17a3ac:	3c19ba00 */ 	lui	$t9,0xba00
/*  f17a3b0:	37390903 */ 	ori	$t9,$t9,0x903
/*  f17a3b4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17a3b8:	afb800c4 */ 	sw	$t8,0xc4($sp)
/*  f17a3bc:	240b0c00 */ 	addiu	$t3,$zero,0xc00
/*  f17a3c0:	3c05800b */ 	lui	$a1,0x800b
/*  f17a3c4:	adeb0004 */ 	sw	$t3,0x4($t7)
/*  f17a3c8:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f17a3cc:	8ca5b5a8 */ 	lw	$a1,-0x4a58($a1)
/*  f17a3d0:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f17a3d4:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f17a3d8:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f17a3dc:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f17a3e0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f17a3e4:	27a400c4 */ 	addiu	$a0,$sp,0xc4
/*  f17a3e8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f17a3ec:	00003825 */ 	or	$a3,$zero,$zero
/*  f17a3f0:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f17a3f4:	24a501a4 */ 	addiu	$a1,$a1,0x01a4
/*  f17a3f8:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f17a3fc:	3c18ba00 */ 	lui	$t8,0xba00
/*  f17a400:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f17a404:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f17a408:	afaf00c4 */ 	sw	$t7,0xc4($sp)
/*  f17a40c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f17a410:	add80000 */ 	sw	$t8,0x0($t6)
/*  f17a414:	8fb900c4 */ 	lw	$t9,0xc4($sp)
/*  f17a418:	3c0cba00 */ 	lui	$t4,0xba00
/*  f17a41c:	358c0c02 */ 	ori	$t4,$t4,0xc02
/*  f17a420:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f17a424:	afab00c4 */ 	sw	$t3,0xc4($sp)
/*  f17a428:	af200004 */ 	sw	$zero,0x4($t9)
/*  f17a42c:	af2c0000 */ 	sw	$t4,0x0($t9)
/*  f17a430:	8fad00ac */ 	lw	$t5,0xac($sp)
/*  f17a434:	00001825 */ 	or	$v1,$zero,$zero
/*  f17a438:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f17a43c:	19a00076 */ 	blez	$t5,.L0f17a618
/*  f17a440:	3c1eff37 */ 	lui	$s8,0xff37
/*  f17a444:	3c17fc12 */ 	lui	$s7,0xfc12
/*  f17a448:	3c16b2ef */ 	lui	$s6,0xb2ef
/*  f17a44c:	3c138008 */ 	lui	$s3,%hi(var8007fac0)
/*  f17a450:	2673fac0 */ 	addiu	$s3,$s3,%lo(var8007fac0)
/*  f17a454:	36d6ff00 */ 	ori	$s6,$s6,0xff00
/*  f17a458:	36f79a25 */ 	ori	$s7,$s7,0x9a25
/*  f17a45c:	37deffff */ 	ori	$s8,$s8,0xffff
/*  f17a460:	241500ff */ 	addiu	$s5,$zero,0xff
/*  f17a464:	3c14fb00 */ 	lui	$s4,0xfb00
.L0f17a468:
/*  f17a468:	3c048007 */ 	lui	$a0,0x8007
/*  f17a46c:	24720001 */ 	addiu	$s2,$v1,0x1
/*  f17a470:	02403025 */ 	or	$a2,$s2,$zero
/*  f17a474:	8c841448 */ 	lw	$a0,0x1448($a0)
/*  f17a478:	0fc670ef */ 	jal	func0f19c3bc
/*  f17a47c:	8fa500bc */ 	lw	$a1,0xbc($sp)
/*  f17a480:	1040000d */ 	beqz	$v0,.L0f17a4b8
/*  f17a484:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f17a488:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f17a48c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f17a490:	afaf00c4 */ 	sw	$t7,0xc4($sp)
/*  f17a494:	add40000 */ 	sw	$s4,0x0($t6)
/*  f17a498:	8e38000c */ 	lw	$t8,0xc($s1)
/*  f17a49c:	331900ff */ 	andi	$t9,$t8,0xff
/*  f17a4a0:	03350019 */ 	multu	$t9,$s5
/*  f17a4a4:	00005812 */ 	mflo	$t3
/*  f17a4a8:	000b6202 */ 	srl	$t4,$t3,0x8
/*  f17a4ac:	01966825 */ 	or	$t5,$t4,$s6
/*  f17a4b0:	1000000d */ 	beqz	$zero,.L0f17a4e8
/*  f17a4b4:	adcd0004 */ 	sw	$t5,0x4($t6)
.L0f17a4b8:
/*  f17a4b8:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f17a4bc:	afaf00c4 */ 	sw	$t7,0xc4($sp)
/*  f17a4c0:	add40000 */ 	sw	$s4,0x0($t6)
/*  f17a4c4:	8e38000c */ 	lw	$t8,0xc($s1)
/*  f17a4c8:	3c013040 */ 	lui	$at,0x3040
/*  f17a4cc:	34217000 */ 	ori	$at,$at,0x7000
/*  f17a4d0:	331900ff */ 	andi	$t9,$t8,0xff
/*  f17a4d4:	03350019 */ 	multu	$t9,$s5
/*  f17a4d8:	00005812 */ 	mflo	$t3
/*  f17a4dc:	000b6202 */ 	srl	$t4,$t3,0x8
/*  f17a4e0:	01816825 */ 	or	$t5,$t4,$at
/*  f17a4e4:	adcd0004 */ 	sw	$t5,0x4($t6)
.L0f17a4e8:
/*  f17a4e8:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f17a4ec:	3c01e400 */ 	lui	$at,0xe400
/*  f17a4f0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f17a4f4:	afaf00c4 */ 	sw	$t7,0xc4($sp)
/*  f17a4f8:	adde0004 */ 	sw	$s8,0x4($t6)
/*  f17a4fc:	add70000 */ 	sw	$s7,0x0($t6)
/*  f17a500:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f17a504:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f17a508:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f17a50c:	afb900c4 */ 	sw	$t9,0xc4($sp)
/*  f17a510:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f17a514:	03001825 */ 	or	$v1,$t8,$zero
/*  f17a518:	01706021 */ 	addu	$t4,$t3,$s0
/*  f17a51c:	258d000b */ 	addiu	$t5,$t4,0xb
/*  f17a520:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f17a524:	01cf0019 */ 	multu	$t6,$t7
/*  f17a528:	8e2d0004 */ 	lw	$t5,0x4($s1)
/*  f17a52c:	25ae0016 */ 	addiu	$t6,$t5,0x16
/*  f17a530:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17a534:	0000c012 */ 	mflo	$t8
/*  f17a538:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f17a53c:	00195b00 */ 	sll	$t3,$t9,0xc
/*  f17a540:	01616025 */ 	or	$t4,$t3,$at
/*  f17a544:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f17a548:	0198c825 */ 	or	$t9,$t4,$t8
/*  f17a54c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f17a550:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f17a554:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f17a558:	01706821 */ 	addu	$t5,$t3,$s0
/*  f17a55c:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f17a560:	01cf0019 */ 	multu	$t6,$t7
/*  f17a564:	8e2b0004 */ 	lw	$t3,0x4($s1)
/*  f17a568:	2610000d */ 	addiu	$s0,$s0,0xd
/*  f17a56c:	256d000b */ 	addiu	$t5,$t3,0xb
/*  f17a570:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f17a574:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f17a578:	240e0160 */ 	addiu	$t6,$zero,0x160
/*  f17a57c:	3c0db400 */ 	lui	$t5,0xb400
/*  f17a580:	00006012 */ 	mflo	$t4
/*  f17a584:	31980fff */ 	andi	$t8,$t4,0xfff
/*  f17a588:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f17a58c:	032f6025 */ 	or	$t4,$t9,$t7
/*  f17a590:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f17a594:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f17a598:	3c0cb300 */ 	lui	$t4,0xb300
/*  f17a59c:	02401825 */ 	or	$v1,$s2,$zero
/*  f17a5a0:	270b0008 */ 	addiu	$t3,$t8,0x8
/*  f17a5a4:	afab00c4 */ 	sw	$t3,0xc4($sp)
/*  f17a5a8:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f17a5ac:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f17a5b0:	8fb900c4 */ 	lw	$t9,0xc4($sp)
/*  f17a5b4:	03002025 */ 	or	$a0,$t8,$zero
/*  f17a5b8:	240b0400 */ 	addiu	$t3,$zero,0x400
/*  f17a5bc:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f17a5c0:	afaf00c4 */ 	sw	$t7,0xc4($sp)
/*  f17a5c4:	af2c0000 */ 	sw	$t4,0x0($t9)
/*  f17a5c8:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f17a5cc:	03201025 */ 	or	$v0,$t9,$zero
/*  f17a5d0:	0178001a */ 	div	$zero,$t3,$t8
/*  f17a5d4:	00006812 */ 	mflo	$t5
/*  f17a5d8:	31aeffff */ 	andi	$t6,$t5,0xffff
/*  f17a5dc:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f17a5e0:	372ffc00 */ 	ori	$t7,$t9,0xfc00
/*  f17a5e4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f17a5e8:	8fac00ac */ 	lw	$t4,0xac($sp)
/*  f17a5ec:	17000002 */ 	bnez	$t8,.L0f17a5f8
/*  f17a5f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17a5f4:	0007000d */ 	break	0x7
.L0f17a5f8:
/*  f17a5f8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17a5fc:	17010004 */ 	bne	$t8,$at,.L0f17a610
/*  f17a600:	3c018000 */ 	lui	$at,0x8000
/*  f17a604:	15610002 */ 	bne	$t3,$at,.L0f17a610
/*  f17a608:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17a60c:	0006000d */ 	break	0x6
.L0f17a610:
/*  f17a610:	164cff95 */ 	bne	$s2,$t4,.L0f17a468
/*  f17a614:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17a618:
/*  f17a618:	10000003 */ 	beqz	$zero,.L0f17a628
/*  f17a61c:	8fa200c4 */ 	lw	$v0,0xc4($sp)
.L0f17a620:
/*  f17a620:	ae0b0000 */ 	sw	$t3,0x0($s0)
.L0f17a624:
/*  f17a624:	00001025 */ 	or	$v0,$zero,$zero
.L0f17a628:
/*  f17a628:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f17a62c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f17a630:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f17a634:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f17a638:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f17a63c:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f17a640:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f17a644:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f17a648:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f17a64c:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f17a650:	03e00008 */ 	jr	$ra
/*  f17a654:	27bd00c8 */ 	addiu	$sp,$sp,0xc8
);

GLOBAL_ASM(
glabel func0f17a658
/*  f17a658:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17a65c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17a660:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17a664:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17a668:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17a66c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17a670:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17a674:	3c06800b */ 	lui	$a2,0x800b
/*  f17a678:	00cf3021 */ 	addu	$a2,$a2,$t7
/*  f17a67c:	3c048007 */ 	lui	$a0,0x8007
/*  f17a680:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a684:	3c057f1b */ 	lui	$a1,%hi(var7f1b7ef8)
/*  f17a688:	24a57ef8 */ 	addiu	$a1,$a1,%lo(var7f1b7ef8)
/*  f17a68c:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17a690:	0c004dad */ 	jal	sprintf
/*  f17a694:	8cc6c80c */ 	lw	$a2,-0x37f4($a2)
/*  f17a698:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17a69c:	3c028007 */ 	lui	$v0,0x8007
/*  f17a6a0:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17a6a4:	03e00008 */ 	jr	$ra
/*  f17a6a8:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17a6ac
/*  f17a6ac:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17a6b0:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17a6b4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17a6b8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17a6bc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17a6c0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17a6c4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17a6c8:	3c06800b */ 	lui	$a2,0x800b
/*  f17a6cc:	00cf3021 */ 	addu	$a2,$a2,$t7
/*  f17a6d0:	3c048007 */ 	lui	$a0,0x8007
/*  f17a6d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a6d8:	3c057f1b */ 	lui	$a1,%hi(var7f1b7efc)
/*  f17a6dc:	24a57efc */ 	addiu	$a1,$a1,%lo(var7f1b7efc)
/*  f17a6e0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17a6e4:	0c004dad */ 	jal	sprintf
/*  f17a6e8:	8cc6c810 */ 	lw	$a2,-0x37f0($a2)
/*  f17a6ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17a6f0:	3c028007 */ 	lui	$v0,0x8007
/*  f17a6f4:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17a6f8:	03e00008 */ 	jr	$ra
/*  f17a6fc:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17a700
/*  f17a700:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17a704:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17a708:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17a70c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17a710:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17a714:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17a718:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17a71c:	3c06800b */ 	lui	$a2,0x800b
/*  f17a720:	00cf3021 */ 	addu	$a2,$a2,$t7
/*  f17a724:	3c048007 */ 	lui	$a0,0x8007
/*  f17a728:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a72c:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f00)
/*  f17a730:	24a57f00 */ 	addiu	$a1,$a1,%lo(var7f1b7f00)
/*  f17a734:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17a738:	0c004dad */ 	jal	sprintf
/*  f17a73c:	8cc6c814 */ 	lw	$a2,-0x37ec($a2)
/*  f17a740:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17a744:	3c028007 */ 	lui	$v0,0x8007
/*  f17a748:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17a74c:	03e00008 */ 	jr	$ra
/*  f17a750:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17a754
/*  f17a754:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17a758:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17a75c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17a760:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17a764:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17a768:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17a76c:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17a770:	3c06800b */ 	lui	$a2,0x800b
/*  f17a774:	00cf3021 */ 	addu	$a2,$a2,$t7
/*  f17a778:	3c048007 */ 	lui	$a0,0x8007
/*  f17a77c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a780:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f04)
/*  f17a784:	24a57f04 */ 	addiu	$a1,$a1,%lo(var7f1b7f04)
/*  f17a788:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17a78c:	0c004dad */ 	jal	sprintf
/*  f17a790:	8cc6c818 */ 	lw	$a2,-0x37e8($a2)
/*  f17a794:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17a798:	3c028007 */ 	lui	$v0,0x8007
/*  f17a79c:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17a7a0:	03e00008 */ 	jr	$ra
/*  f17a7a4:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17a7a8
/*  f17a7a8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17a7ac:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17a7b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17a7b4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17a7b8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17a7bc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17a7c0:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17a7c4:	3c06800b */ 	lui	$a2,0x800b
/*  f17a7c8:	00cf3021 */ 	addu	$a2,$a2,$t7
/*  f17a7cc:	3c048007 */ 	lui	$a0,0x8007
/*  f17a7d0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a7d4:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f08)
/*  f17a7d8:	24a57f08 */ 	addiu	$a1,$a1,%lo(var7f1b7f08)
/*  f17a7dc:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17a7e0:	0c004dad */ 	jal	sprintf
/*  f17a7e4:	8cc6c81c */ 	lw	$a2,-0x37e4($a2)
/*  f17a7e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17a7ec:	3c028007 */ 	lui	$v0,0x8007
/*  f17a7f0:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17a7f4:	03e00008 */ 	jr	$ra
/*  f17a7f8:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17a7fc
/*  f17a7fc:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17a800:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17a804:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17a808:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17a80c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17a810:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17a814:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17a818:	3c06800b */ 	lui	$a2,0x800b
/*  f17a81c:	00cf3021 */ 	addu	$a2,$a2,$t7
/*  f17a820:	3c048007 */ 	lui	$a0,0x8007
/*  f17a824:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a828:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f0c)
/*  f17a82c:	24a57f0c */ 	addiu	$a1,$a1,%lo(var7f1b7f0c)
/*  f17a830:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17a834:	0c004dad */ 	jal	sprintf
/*  f17a838:	8cc6c834 */ 	lw	$a2,-0x37cc($a2)
/*  f17a83c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17a840:	3c028007 */ 	lui	$v0,0x8007
/*  f17a844:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17a848:	03e00008 */ 	jr	$ra
/*  f17a84c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17a850
/*  f17a850:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17a854:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17a858:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17a85c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17a860:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17a864:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17a868:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17a86c:	3c06800b */ 	lui	$a2,0x800b
/*  f17a870:	00cf3021 */ 	addu	$a2,$a2,$t7
/*  f17a874:	3c048007 */ 	lui	$a0,0x8007
/*  f17a878:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a87c:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f10)
/*  f17a880:	24a57f10 */ 	addiu	$a1,$a1,%lo(var7f1b7f10)
/*  f17a884:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17a888:	0c004dad */ 	jal	sprintf
/*  f17a88c:	8cc6c83c */ 	lw	$a2,-0x37c4($a2)
/*  f17a890:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17a894:	3c028007 */ 	lui	$v0,0x8007
/*  f17a898:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17a89c:	03e00008 */ 	jr	$ra
/*  f17a8a0:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17a8a4
/*  f17a8a4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17a8a8:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17a8ac:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17a8b0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17a8b4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17a8b8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17a8bc:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17a8c0:	3c06800b */ 	lui	$a2,0x800b
/*  f17a8c4:	00cf3021 */ 	addu	$a2,$a2,$t7
/*  f17a8c8:	3c048007 */ 	lui	$a0,0x8007
/*  f17a8cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a8d0:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f14)
/*  f17a8d4:	24a57f14 */ 	addiu	$a1,$a1,%lo(var7f1b7f14)
/*  f17a8d8:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17a8dc:	0c004dad */ 	jal	sprintf
/*  f17a8e0:	8cc6c840 */ 	lw	$a2,-0x37c0($a2)
/*  f17a8e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17a8e8:	3c028007 */ 	lui	$v0,0x8007
/*  f17a8ec:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17a8f0:	03e00008 */ 	jr	$ra
/*  f17a8f4:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17a8f8
/*  f17a8f8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17a8fc:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17a900:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17a904:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17a908:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17a90c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17a910:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17a914:	3c06800b */ 	lui	$a2,0x800b
/*  f17a918:	00cf3021 */ 	addu	$a2,$a2,$t7
/*  f17a91c:	3c048007 */ 	lui	$a0,0x8007
/*  f17a920:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a924:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f18)
/*  f17a928:	24a57f18 */ 	addiu	$a1,$a1,%lo(var7f1b7f18)
/*  f17a92c:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17a930:	0c004dad */ 	jal	sprintf
/*  f17a934:	8cc6c844 */ 	lw	$a2,-0x37bc($a2)
/*  f17a938:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17a93c:	3c028007 */ 	lui	$v0,0x8007
/*  f17a940:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17a944:	03e00008 */ 	jr	$ra
/*  f17a948:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17a94c
/*  f17a94c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17a950:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17a954:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17a958:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17a95c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17a960:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17a964:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17a968:	3c06800b */ 	lui	$a2,0x800b
/*  f17a96c:	00cf3021 */ 	addu	$a2,$a2,$t7
/*  f17a970:	3c048007 */ 	lui	$a0,0x8007
/*  f17a974:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a978:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f1c)
/*  f17a97c:	24a57f1c */ 	addiu	$a1,$a1,%lo(var7f1b7f1c)
/*  f17a980:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17a984:	0c004dad */ 	jal	sprintf
/*  f17a988:	8cc6c848 */ 	lw	$a2,-0x37b8($a2)
/*  f17a98c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17a990:	3c028007 */ 	lui	$v0,0x8007
/*  f17a994:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17a998:	03e00008 */ 	jr	$ra
/*  f17a99c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17a9a0
/*  f17a9a0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17a9a4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17a9a8:	3c06800b */ 	lui	$a2,0x800b
/*  f17a9ac:	3c020001 */ 	lui	$v0,0x1
/*  f17a9b0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17a9b4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17a9b8:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17a9bc:	00cf3021 */ 	addu	$a2,$a2,$t7
/*  f17a9c0:	8cc6c838 */ 	lw	$a2,-0x37c8($a2)
/*  f17a9c4:	344286a1 */ 	ori	$v0,$v0,0x86a1
/*  f17a9c8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17a9cc:	00c2082a */ 	slt	$at,$a2,$v0
/*  f17a9d0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17a9d4:	14200028 */ 	bnez	$at,.L0f17aa78
/*  f17a9d8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17a9dc:	240303e8 */ 	addiu	$v1,$zero,0x3e8
/*  f17a9e0:	00c3001a */ 	div	$zero,$a2,$v1
/*  f17a9e4:	14600002 */ 	bnez	$v1,.L0f17a9f0
/*  f17a9e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17a9ec:	0007000d */ 	break	0x7
.L0f17a9f0:
/*  f17a9f0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17a9f4:	14610004 */ 	bne	$v1,$at,.L0f17aa08
/*  f17a9f8:	3c018000 */ 	lui	$at,0x8000
/*  f17a9fc:	14c10002 */ 	bne	$a2,$at,.L0f17aa08
/*  f17aa00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17aa04:	0006000d */ 	break	0x6
.L0f17aa08:
/*  f17aa08:	00003012 */ 	mflo	$a2
/*  f17aa0c:	00c2082a */ 	slt	$at,$a2,$v0
/*  f17aa10:	14200012 */ 	bnez	$at,.L0f17aa5c
/*  f17aa14:	3c048007 */ 	lui	$a0,0x8007
/*  f17aa18:	00c3001a */ 	div	$zero,$a2,$v1
/*  f17aa1c:	14600002 */ 	bnez	$v1,.L0f17aa28
/*  f17aa20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17aa24:	0007000d */ 	break	0x7
.L0f17aa28:
/*  f17aa28:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17aa2c:	14610004 */ 	bne	$v1,$at,.L0f17aa40
/*  f17aa30:	3c018000 */ 	lui	$at,0x8000
/*  f17aa34:	14c10002 */ 	bne	$a2,$at,.L0f17aa40
/*  f17aa38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17aa3c:	0006000d */ 	break	0x6
.L0f17aa40:
/*  f17aa40:	00003012 */ 	mflo	$a2
/*  f17aa44:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f20)
/*  f17aa48:	24a57f20 */ 	addiu	$a1,$a1,%lo(var7f1b7f20)
/*  f17aa4c:	0c004dad */ 	jal	sprintf
/*  f17aa50:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17aa54:	1000000e */ 	beqz	$zero,.L0f17aa90
/*  f17aa58:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17aa5c:
/*  f17aa5c:	3c048007 */ 	lui	$a0,0x8007
/*  f17aa60:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f28)
/*  f17aa64:	24a57f28 */ 	addiu	$a1,$a1,%lo(var7f1b7f28)
/*  f17aa68:	0c004dad */ 	jal	sprintf
/*  f17aa6c:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17aa70:	10000007 */ 	beqz	$zero,.L0f17aa90
/*  f17aa74:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17aa78:
/*  f17aa78:	3c048007 */ 	lui	$a0,0x8007
/*  f17aa7c:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f30)
/*  f17aa80:	24a57f30 */ 	addiu	$a1,$a1,%lo(var7f1b7f30)
/*  f17aa84:	0c004dad */ 	jal	sprintf
/*  f17aa88:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17aa8c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17aa90:
/*  f17aa90:	3c028007 */ 	lui	$v0,0x8007
/*  f17aa94:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17aa98:	03e00008 */ 	jr	$ra
/*  f17aa9c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17aaa0
/*  f17aaa0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17aaa4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17aaa8:	3c18800b */ 	lui	$t8,0x800b
/*  f17aaac:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f17aab0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17aab4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17aab8:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17aabc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17aac0:	8f18c824 */ 	lw	$t8,-0x37dc($t8)
/*  f17aac4:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f17aac8:	3c048007 */ 	lui	$a0,0x8007
/*  f17aacc:	44982000 */ 	mtc1	$t8,$f4
/*  f17aad0:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f34)
/*  f17aad4:	3c067f1b */ 	lui	$a2,%hi(var7f1b7f40)
/*  f17aad8:	3c077f1b */ 	lui	$a3,%hi(var7f1b7f44)
/*  f17aadc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f17aae0:	24e77f44 */ 	addiu	$a3,$a3,%lo(var7f1b7f44)
/*  f17aae4:	24c67f40 */ 	addiu	$a2,$a2,%lo(var7f1b7f40)
/*  f17aae8:	24a57f34 */ 	addiu	$a1,$a1,%lo(var7f1b7f34)
/*  f17aaec:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17aaf0:	07010005 */ 	bgez	$t8,.L0f17ab08
/*  f17aaf4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f17aaf8:	3c014f80 */ 	lui	$at,0x4f80
/*  f17aafc:	44814000 */ 	mtc1	$at,$f8
/*  f17ab00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ab04:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f17ab08:
/*  f17ab08:	3c014120 */ 	lui	$at,0x4120
/*  f17ab0c:	44815000 */ 	mtc1	$at,$f10
/*  f17ab10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ab14:	460a3403 */ 	div.s	$f16,$f6,$f10
/*  f17ab18:	460084a1 */ 	cvt.d.s	$f18,$f16
/*  f17ab1c:	0c004dad */ 	jal	sprintf
/*  f17ab20:	f7b20010 */ 	sdc1	$f18,0x10($sp)
/*  f17ab24:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f17ab28:	3c028007 */ 	lui	$v0,0x8007
/*  f17ab2c:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17ab30:	03e00008 */ 	jr	$ra
/*  f17ab34:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f17ab38
/*  f17ab38:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17ab3c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17ab40:	3c02800b */ 	lui	$v0,0x800b
/*  f17ab44:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f17ab48:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17ab4c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17ab50:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17ab54:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f17ab58:	8c42c820 */ 	lw	$v0,-0x37e0($v0)
/*  f17ab5c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f17ab60:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f17ab64:	0048001b */ 	divu	$zero,$v0,$t0
/*  f17ab68:	00004810 */ 	mfhi	$t1
/*  f17ab6c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f17ab70:	15000002 */ 	bnez	$t0,.L0f17ab7c
/*  f17ab74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ab78:	0007000d */ 	break	0x7
.L0f17ab7c:
/*  f17ab7c:	3c017fff */ 	lui	$at,0x7fff
/*  f17ab80:	54400005 */ 	bnezl	$v0,.L0f17ab98
/*  f17ab84:	3421ffff */ 	ori	$at,$at,0xffff
/*  f17ab88:	3c027f1b */ 	lui	$v0,%hi(var7f1b7f48)
/*  f17ab8c:	10000052 */ 	beqz	$zero,.L0f17acd8
/*  f17ab90:	24427f48 */ 	addiu	$v0,$v0,%lo(var7f1b7f48)
/*  f17ab94:	3421ffff */ 	ori	$at,$at,0xffff
.L0f17ab98:
/*  f17ab98:	0041082b */ 	sltu	$at,$v0,$at
/*  f17ab9c:	14200004 */ 	bnez	$at,.L0f17abb0
/*  f17aba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17aba4:	3c027f1b */ 	lui	$v0,%hi(var7f1b7f50)
/*  f17aba8:	1000004b */ 	beqz	$zero,.L0f17acd8
/*  f17abac:	24427f50 */ 	addiu	$v0,$v0,%lo(var7f1b7f50)
.L0f17abb0:
/*  f17abb0:	0048001b */ 	divu	$zero,$v0,$t0
/*  f17abb4:	00001012 */ 	mflo	$v0
/*  f17abb8:	240a0018 */ 	addiu	$t2,$zero,0x18
/*  f17abbc:	15000002 */ 	bnez	$t0,.L0f17abc8
/*  f17abc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17abc4:	0007000d */ 	break	0x7
.L0f17abc8:
/*  f17abc8:	0048001b */ 	divu	$zero,$v0,$t0
/*  f17abcc:	00001812 */ 	mflo	$v1
/*  f17abd0:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f68)
/*  f17abd4:	15000002 */ 	bnez	$t0,.L0f17abe0
/*  f17abd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17abdc:	0007000d */ 	break	0x7
.L0f17abe0:
/*  f17abe0:	006a001a */ 	div	$zero,$v1,$t2
/*  f17abe4:	00003012 */ 	mflo	$a2
/*  f17abe8:	24a57f68 */ 	addiu	$a1,$a1,%lo(var7f1b7f68)
/*  f17abec:	15400002 */ 	bnez	$t2,.L0f17abf8
/*  f17abf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17abf4:	0007000d */ 	break	0x7
.L0f17abf8:
/*  f17abf8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17abfc:	15410004 */ 	bne	$t2,$at,.L0f17ac10
/*  f17ac00:	3c018000 */ 	lui	$at,0x8000
/*  f17ac04:	14610002 */ 	bne	$v1,$at,.L0f17ac10
/*  f17ac08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ac0c:	0006000d */ 	break	0x6
.L0f17ac10:
/*  f17ac10:	3c048007 */ 	lui	$a0,0x8007
/*  f17ac14:	14c0001a */ 	bnez	$a2,.L0f17ac80
/*  f17ac18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ac1c:	006a001a */ 	div	$zero,$v1,$t2
/*  f17ac20:	00003010 */ 	mfhi	$a2
/*  f17ac24:	3c048007 */ 	lui	$a0,0x8007
/*  f17ac28:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f58)
/*  f17ac2c:	0048001b */ 	divu	$zero,$v0,$t0
/*  f17ac30:	00003810 */ 	mfhi	$a3
/*  f17ac34:	24a57f58 */ 	addiu	$a1,$a1,%lo(var7f1b7f58)
/*  f17ac38:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17ac3c:	15400002 */ 	bnez	$t2,.L0f17ac48
/*  f17ac40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ac44:	0007000d */ 	break	0x7
.L0f17ac48:
/*  f17ac48:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17ac4c:	15410004 */ 	bne	$t2,$at,.L0f17ac60
/*  f17ac50:	3c018000 */ 	lui	$at,0x8000
/*  f17ac54:	14610002 */ 	bne	$v1,$at,.L0f17ac60
/*  f17ac58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ac5c:	0006000d */ 	break	0x6
.L0f17ac60:
/*  f17ac60:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f17ac64:	15000002 */ 	bnez	$t0,.L0f17ac70
/*  f17ac68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ac6c:	0007000d */ 	break	0x7
.L0f17ac70:
/*  f17ac70:	0c004dad */ 	jal	sprintf
/*  f17ac74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ac78:	10000015 */ 	beqz	$zero,.L0f17acd0
/*  f17ac7c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17ac80:
/*  f17ac80:	006a001a */ 	div	$zero,$v1,$t2
/*  f17ac84:	00003810 */ 	mfhi	$a3
/*  f17ac88:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17ac8c:	15400002 */ 	bnez	$t2,.L0f17ac98
/*  f17ac90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ac94:	0007000d */ 	break	0x7
.L0f17ac98:
/*  f17ac98:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17ac9c:	15410004 */ 	bne	$t2,$at,.L0f17acb0
/*  f17aca0:	3c018000 */ 	lui	$at,0x8000
/*  f17aca4:	14610002 */ 	bne	$v1,$at,.L0f17acb0
/*  f17aca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17acac:	0006000d */ 	break	0x6
.L0f17acb0:
/*  f17acb0:	0048001b */ 	divu	$zero,$v0,$t0
/*  f17acb4:	0000c010 */ 	mfhi	$t8
/*  f17acb8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f17acbc:	15000002 */ 	bnez	$t0,.L0f17acc8
/*  f17acc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17acc4:	0007000d */ 	break	0x7
.L0f17acc8:
/*  f17acc8:	0c004dad */ 	jal	sprintf
/*  f17accc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17acd0:
/*  f17acd0:	3c028007 */ 	lui	$v0,0x8007
/*  f17acd4:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f17acd8:
/*  f17acd8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f17acdc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f17ace0:	03e00008 */ 	jr	$ra
/*  f17ace4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f17ace8
/*  f17ace8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17acec:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17acf0:	3c18800b */ 	lui	$t8,0x800b
/*  f17acf4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f17acf8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17acfc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17ad00:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17ad04:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17ad08:	8f18c828 */ 	lw	$t8,-0x37d8($t8)
/*  f17ad0c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f17ad10:	3c048007 */ 	lui	$a0,0x8007
/*  f17ad14:	44982000 */ 	mtc1	$t8,$f4
/*  f17ad18:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f78)
/*  f17ad1c:	3c067f1b */ 	lui	$a2,%hi(var7f1b7f84)
/*  f17ad20:	3c077f1b */ 	lui	$a3,%hi(var7f1b7f88)
/*  f17ad24:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f17ad28:	24e77f88 */ 	addiu	$a3,$a3,%lo(var7f1b7f88)
/*  f17ad2c:	24c67f84 */ 	addiu	$a2,$a2,%lo(var7f1b7f84)
/*  f17ad30:	24a57f78 */ 	addiu	$a1,$a1,%lo(var7f1b7f78)
/*  f17ad34:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17ad38:	07010005 */ 	bgez	$t8,.L0f17ad50
/*  f17ad3c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f17ad40:	3c014f80 */ 	lui	$at,0x4f80
/*  f17ad44:	44814000 */ 	mtc1	$at,$f8
/*  f17ad48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ad4c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f17ad50:
/*  f17ad50:	3c014120 */ 	lui	$at,0x4120
/*  f17ad54:	44815000 */ 	mtc1	$at,$f10
/*  f17ad58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ad5c:	460a3403 */ 	div.s	$f16,$f6,$f10
/*  f17ad60:	460084a1 */ 	cvt.d.s	$f18,$f16
/*  f17ad64:	0c004dad */ 	jal	sprintf
/*  f17ad68:	f7b20010 */ 	sdc1	$f18,0x10($sp)
/*  f17ad6c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f17ad70:	3c028007 */ 	lui	$v0,0x8007
/*  f17ad74:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17ad78:	03e00008 */ 	jr	$ra
/*  f17ad7c:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f17ad80
/*  f17ad80:	3c01447a */ 	lui	$at,0x447a
/*  f17ad84:	44810000 */ 	mtc1	$at,$f0
/*  f17ad88:	44856000 */ 	mtc1	$a1,$f12
/*  f17ad8c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f17ad90:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f8c)
/*  f17ad94:	4600603c */ 	c.lt.s	$f12,$f0
/*  f17ad98:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f17ad9c:	24a57f8c */ 	addiu	$a1,$a1,%lo(var7f1b7f8c)
/*  f17ada0:	3c067f1b */ 	lui	$a2,%hi(var7f1b7f98)
/*  f17ada4:	45000009 */ 	bc1f	.L0f17adcc
/*  f17ada8:	3c017f1c */ 	lui	$at,%hi(var7f1b80e0)
/*  f17adac:	46006121 */ 	cvt.d.s	$f4,$f12
/*  f17adb0:	3c077f1b */ 	lui	$a3,%hi(var7f1b7f9c)
/*  f17adb4:	24e77f9c */ 	addiu	$a3,$a3,%lo(var7f1b7f9c)
/*  f17adb8:	f7a40010 */ 	sdc1	$f4,0x10($sp)
/*  f17adbc:	0c004dad */ 	jal	sprintf
/*  f17adc0:	24c67f98 */ 	addiu	$a2,$a2,%lo(var7f1b7f98)
/*  f17adc4:	10000052 */ 	beqz	$zero,.L0f17af10
/*  f17adc8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f17adcc:
/*  f17adcc:	c42680e0 */ 	lwc1	$f6,%lo(var7f1b80e0)($at)
/*  f17add0:	3c057f1b */ 	lui	$a1,%hi(var7f1b7fa0)
/*  f17add4:	3c067f1b */ 	lui	$a2,%hi(var7f1b7fac)
/*  f17add8:	4606603c */ 	c.lt.s	$f12,$f6
/*  f17addc:	24c67fac */ 	addiu	$a2,$a2,%lo(var7f1b7fac)
/*  f17ade0:	24a57fa0 */ 	addiu	$a1,$a1,%lo(var7f1b7fa0)
/*  f17ade4:	3c077f1b */ 	lui	$a3,%hi(var7f1b7fb0)
/*  f17ade8:	45000007 */ 	bc1f	.L0f17ae08
/*  f17adec:	3c017f1c */ 	lui	$at,%hi(var7f1b80e4)
/*  f17adf0:	46006221 */ 	cvt.d.s	$f8,$f12
/*  f17adf4:	24e77fb0 */ 	addiu	$a3,$a3,%lo(var7f1b7fb0)
/*  f17adf8:	0c004dad */ 	jal	sprintf
/*  f17adfc:	f7a80010 */ 	sdc1	$f8,0x10($sp)
/*  f17ae00:	10000043 */ 	beqz	$zero,.L0f17af10
/*  f17ae04:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f17ae08:
/*  f17ae08:	c42a80e4 */ 	lwc1	$f10,%lo(var7f1b80e4)($at)
/*  f17ae0c:	3c017f1c */ 	lui	$at,%hi(var7f1b80e8)
/*  f17ae10:	460a603c */ 	c.lt.s	$f12,$f10
/*  f17ae14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ae18:	4500000d */ 	bc1f	.L0f17ae50
/*  f17ae1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ae20:	46006303 */ 	div.s	$f12,$f12,$f0
/*  f17ae24:	3c057f1b */ 	lui	$a1,%hi(var7f1b7fb4)
/*  f17ae28:	3c067f1b */ 	lui	$a2,%hi(var7f1b7fc0)
/*  f17ae2c:	3c077f1b */ 	lui	$a3,%hi(var7f1b7fc4)
/*  f17ae30:	24e77fc4 */ 	addiu	$a3,$a3,%lo(var7f1b7fc4)
/*  f17ae34:	24c67fc0 */ 	addiu	$a2,$a2,%lo(var7f1b7fc0)
/*  f17ae38:	24a57fb4 */ 	addiu	$a1,$a1,%lo(var7f1b7fb4)
/*  f17ae3c:	46006421 */ 	cvt.d.s	$f16,$f12
/*  f17ae40:	0c004dad */ 	jal	sprintf
/*  f17ae44:	f7b00010 */ 	sdc1	$f16,0x10($sp)
/*  f17ae48:	10000031 */ 	beqz	$zero,.L0f17af10
/*  f17ae4c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f17ae50:
/*  f17ae50:	c43280e8 */ 	lwc1	$f18,%lo(var7f1b80e8)($at)
/*  f17ae54:	3c017f1c */ 	lui	$at,%hi(var7f1b80ec)
/*  f17ae58:	4612603c */ 	c.lt.s	$f12,$f18
/*  f17ae5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ae60:	4500000d */ 	bc1f	.L0f17ae98
/*  f17ae64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ae68:	46006303 */ 	div.s	$f12,$f12,$f0
/*  f17ae6c:	3c057f1b */ 	lui	$a1,%hi(var7f1b7fc8)
/*  f17ae70:	3c067f1b */ 	lui	$a2,%hi(var7f1b7fd4)
/*  f17ae74:	3c077f1b */ 	lui	$a3,%hi(var7f1b7fd8)
/*  f17ae78:	24e77fd8 */ 	addiu	$a3,$a3,%lo(var7f1b7fd8)
/*  f17ae7c:	24c67fd4 */ 	addiu	$a2,$a2,%lo(var7f1b7fd4)
/*  f17ae80:	24a57fc8 */ 	addiu	$a1,$a1,%lo(var7f1b7fc8)
/*  f17ae84:	46006121 */ 	cvt.d.s	$f4,$f12
/*  f17ae88:	0c004dad */ 	jal	sprintf
/*  f17ae8c:	f7a40010 */ 	sdc1	$f4,0x10($sp)
/*  f17ae90:	1000001f */ 	beqz	$zero,.L0f17af10
/*  f17ae94:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f17ae98:
/*  f17ae98:	c42680ec */ 	lwc1	$f6,%lo(var7f1b80ec)($at)
/*  f17ae9c:	4606603c */ 	c.lt.s	$f12,$f6
/*  f17aea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17aea4:	4502000f */ 	bc1fl	.L0f17aee4
/*  f17aea8:	46006303 */ 	div.s	$f12,$f12,$f0
/*  f17aeac:	46006303 */ 	div.s	$f12,$f12,$f0
/*  f17aeb0:	3c057f1b */ 	lui	$a1,%hi(var7f1b7fdc)
/*  f17aeb4:	3c067f1b */ 	lui	$a2,%hi(var7f1b7fe8)
/*  f17aeb8:	3c077f1b */ 	lui	$a3,%hi(var7f1b7fec)
/*  f17aebc:	24e77fec */ 	addiu	$a3,$a3,%lo(var7f1b7fec)
/*  f17aec0:	24c67fe8 */ 	addiu	$a2,$a2,%lo(var7f1b7fe8)
/*  f17aec4:	24a57fdc */ 	addiu	$a1,$a1,%lo(var7f1b7fdc)
/*  f17aec8:	46006303 */ 	div.s	$f12,$f12,$f0
/*  f17aecc:	46006221 */ 	cvt.d.s	$f8,$f12
/*  f17aed0:	0c004dad */ 	jal	sprintf
/*  f17aed4:	f7a80010 */ 	sdc1	$f8,0x10($sp)
/*  f17aed8:	1000000d */ 	beqz	$zero,.L0f17af10
/*  f17aedc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f17aee0:	46006303 */ 	div.s	$f12,$f12,$f0
.L0f17aee4:
/*  f17aee4:	3c057f1b */ 	lui	$a1,%hi(var7f1b7ff0)
/*  f17aee8:	3c067f1b */ 	lui	$a2,%hi(var7f1b7ffc)
/*  f17aeec:	3c077f1c */ 	lui	$a3,0x7f1c
/*  f17aef0:	24e78000 */ 	addiu	$a3,$a3,-32768
/*  f17aef4:	24c67ffc */ 	addiu	$a2,$a2,%lo(var7f1b7ffc)
/*  f17aef8:	24a57ff0 */ 	addiu	$a1,$a1,%lo(var7f1b7ff0)
/*  f17aefc:	46006303 */ 	div.s	$f12,$f12,$f0
/*  f17af00:	460062a1 */ 	cvt.d.s	$f10,$f12
/*  f17af04:	0c004dad */ 	jal	sprintf
/*  f17af08:	f7aa0010 */ 	sdc1	$f10,0x10($sp)
/*  f17af0c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f17af10:
/*  f17af10:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f17af14:	03e00008 */ 	jr	$ra
/*  f17af18:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f17af1c
/*  f17af1c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17af20:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17af24:	3c18800b */ 	lui	$t8,0x800b
/*  f17af28:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17af2c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17af30:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17af34:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17af38:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17af3c:	8f18c830 */ 	lw	$t8,-0x37d0($t8)
/*  f17af40:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17af44:	3c048007 */ 	lui	$a0,0x8007
/*  f17af48:	44982000 */ 	mtc1	$t8,$f4
/*  f17af4c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17af50:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17af54:	07010005 */ 	bgez	$t8,.L0f17af6c
/*  f17af58:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f17af5c:	3c014f80 */ 	lui	$at,0x4f80
/*  f17af60:	44814000 */ 	mtc1	$at,$f8
/*  f17af64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17af68:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f17af6c:
/*  f17af6c:	3c014120 */ 	lui	$at,0x4120
/*  f17af70:	44815000 */ 	mtc1	$at,$f10
/*  f17af74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17af78:	460a3403 */ 	div.s	$f16,$f6,$f10
/*  f17af7c:	44058000 */ 	mfc1	$a1,$f16
/*  f17af80:	0fc5eb60 */ 	jal	func0f17ad80
/*  f17af84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17af88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17af8c:	3c028007 */ 	lui	$v0,0x8007
/*  f17af90:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17af94:	03e00008 */ 	jr	$ra
/*  f17af98:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17af9c
/*  f17af9c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17afa0:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17afa4:	3c18800b */ 	lui	$t8,0x800b
/*  f17afa8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17afac:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17afb0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17afb4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17afb8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17afbc:	8f18c82c */ 	lw	$t8,-0x37d4($t8)
/*  f17afc0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17afc4:	3c048007 */ 	lui	$a0,0x8007
/*  f17afc8:	44982000 */ 	mtc1	$t8,$f4
/*  f17afcc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17afd0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17afd4:	07010005 */ 	bgez	$t8,.L0f17afec
/*  f17afd8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f17afdc:	3c014f80 */ 	lui	$at,0x4f80
/*  f17afe0:	44814000 */ 	mtc1	$at,$f8
/*  f17afe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17afe8:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f17afec:
/*  f17afec:	3c014120 */ 	lui	$at,0x4120
/*  f17aff0:	44815000 */ 	mtc1	$at,$f10
/*  f17aff4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17aff8:	460a3403 */ 	div.s	$f16,$f6,$f10
/*  f17affc:	44058000 */ 	mfc1	$a1,$f16
/*  f17b000:	0fc5eb60 */ 	jal	func0f17ad80
/*  f17b004:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17b008:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17b00c:	3c028007 */ 	lui	$v0,0x8007
/*  f17b010:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17b014:	03e00008 */ 	jr	$ra
/*  f17b018:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel menuhandlerMpMedal
/*  f17b01c:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f17b020:	24010013 */ 	addiu	$at,$zero,0x13
/*  f17b024:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f17b028:	148100c8 */ 	bne	$a0,$at,.L0f17b34c
/*  f17b02c:	afa50074 */ 	sw	$a1,0x74($sp)
/*  f17b030:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f17b034:	3c19e700 */ 	lui	$t9,0xe700
/*  f17b038:	3c0cba00 */ 	lui	$t4,0xba00
/*  f17b03c:	afae006c */ 	sw	$t6,0x6c($sp)
/*  f17b040:	8cc80008 */ 	lw	$t0,0x8($a2)
/*  f17b044:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f17b048:	afb8006c */ 	sw	$t8,0x6c($sp)
/*  f17b04c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f17b050:	add90000 */ 	sw	$t9,0x0($t6)
/*  f17b054:	8faa006c */ 	lw	$t2,0x6c($sp)
/*  f17b058:	358c1301 */ 	ori	$t4,$t4,0x1301
/*  f17b05c:	3c0fb900 */ 	lui	$t7,0xb900
/*  f17b060:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f17b064:	afab006c */ 	sw	$t3,0x6c($sp)
/*  f17b068:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f17b06c:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f17b070:	8fad006c */ 	lw	$t5,0x6c($sp)
/*  f17b074:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f17b078:	3c0aba00 */ 	lui	$t2,0xba00
/*  f17b07c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f17b080:	afae006c */ 	sw	$t6,0x6c($sp)
/*  f17b084:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f17b088:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f17b08c:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f17b090:	354a1001 */ 	ori	$t2,$t2,0x1001
/*  f17b094:	3c0dba00 */ 	lui	$t5,0xba00
/*  f17b098:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f17b09c:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f17b0a0:	af000004 */ 	sw	$zero,0x4($t8)
/*  f17b0a4:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f17b0a8:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f17b0ac:	35ad0903 */ 	ori	$t5,$t5,0x903
/*  f17b0b0:	240e0c00 */ 	addiu	$t6,$zero,0xc00
/*  f17b0b4:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f17b0b8:	afac006c */ 	sw	$t4,0x6c($sp)
/*  f17b0bc:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f17b0c0:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f17b0c4:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f17b0c8:	3c19ba00 */ 	lui	$t9,0xba00
/*  f17b0cc:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f17b0d0:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17b0d4:	afb8006c */ 	sw	$t8,0x6c($sp)
/*  f17b0d8:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f17b0dc:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f17b0e0:	3c05800b */ 	lui	$a1,0x800b
/*  f17b0e4:	8ca5b5a8 */ 	lw	$a1,-0x4a58($a1)
/*  f17b0e8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f17b0ec:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f17b0f0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f17b0f4:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f17b0f8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f17b0fc:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f17b100:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f17b104:	00003825 */ 	or	$a3,$zero,$zero
/*  f17b108:	afa80068 */ 	sw	$t0,0x68($sp)
/*  f17b10c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f17b110:	24a501a4 */ 	addiu	$a1,$a1,0x01a4
/*  f17b114:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f17b118:	8fa80068 */ 	lw	$t0,0x68($sp)
/*  f17b11c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f17b120:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f17b124:	afad006c */ 	sw	$t5,0x6c($sp)
/*  f17b128:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f17b12c:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f17b130:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f17b134:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f17b138:	3c19fcff */ 	lui	$t9,0xfcff
/*  f17b13c:	3c0afffc */ 	lui	$t2,0xfffc
/*  f17b140:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17b144:	afb8006c */ 	sw	$t8,0x6c($sp)
/*  f17b148:	354af279 */ 	ori	$t2,$t2,0xf279
/*  f17b14c:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f17b150:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f17b154:	adea0004 */ 	sw	$t2,0x4($t7)
/*  f17b158:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f17b15c:	3c0dba00 */ 	lui	$t5,0xba00
/*  f17b160:	35ad0c02 */ 	ori	$t5,$t5,0xc02
/*  f17b164:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f17b168:	afac006c */ 	sw	$t4,0x6c($sp)
/*  f17b16c:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f17b170:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f17b174:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f17b178:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17b17c:	91c50001 */ 	lbu	$a1,0x1($t6)
/*  f17b180:	50a0000a */ 	beqzl	$a1,.L0f17b1ac
/*  f17b184:	3c05ff7f */ 	lui	$a1,0xff7f
/*  f17b188:	10a1000a */ 	beq	$a1,$at,.L0f17b1b4
/*  f17b18c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f17b190:	10a1000b */ 	beq	$a1,$at,.L0f17b1c0
/*  f17b194:	24010003 */ 	addiu	$at,$zero,0x3
/*  f17b198:	50a1000d */ 	beql	$a1,$at,.L0f17b1d0
/*  f17b19c:	3c0500bf */ 	lui	$a1,0xbf
/*  f17b1a0:	1000000c */ 	beqz	$zero,.L0f17b1d4
/*  f17b1a4:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f17b1a8:	3c05ff7f */ 	lui	$a1,0xff7f
.L0f17b1ac:
/*  f17b1ac:	10000009 */ 	beqz	$zero,.L0f17b1d4
/*  f17b1b0:	34a57fff */ 	ori	$a1,$a1,0x7fff
.L0f17b1b4:
/*  f17b1b4:	3c05bfbf */ 	lui	$a1,0xbfbf
/*  f17b1b8:	10000006 */ 	beqz	$zero,.L0f17b1d4
/*  f17b1bc:	34a500ff */ 	ori	$a1,$a1,0xff
.L0f17b1c0:
/*  f17b1c0:	3c0500ff */ 	lui	$a1,0xff
/*  f17b1c4:	10000003 */ 	beqz	$zero,.L0f17b1d4
/*  f17b1c8:	34a500ff */ 	ori	$a1,$a1,0xff
/*  f17b1cc:	3c0500bf */ 	lui	$a1,0xbf
.L0f17b1d0:
/*  f17b1d0:	34a5bfff */ 	ori	$a1,$a1,0xbfff
.L0f17b1d4:
/*  f17b1d4:	8d18000c */ 	lw	$t8,0xc($t0)
/*  f17b1d8:	30af00ff */ 	andi	$t7,$a1,0xff
/*  f17b1dc:	8fad006c */ 	lw	$t5,0x6c($sp)
/*  f17b1e0:	331900ff */ 	andi	$t9,$t8,0xff
/*  f17b1e4:	01f90019 */ 	multu	$t7,$t9
/*  f17b1e8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f17b1ec:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f17b1f0:	00a16024 */ 	and	$t4,$a1,$at
/*  f17b1f4:	afae006c */ 	sw	$t6,0x6c($sp)
/*  f17b1f8:	3c18fb00 */ 	lui	$t8,0xfb00
/*  f17b1fc:	adb80000 */ 	sw	$t8,0x0($t5)
/*  f17b200:	01a01025 */ 	or	$v0,$t5,$zero
/*  f17b204:	3c068008 */ 	lui	$a2,%hi(var8007fac0)
/*  f17b208:	24c6fac0 */ 	addiu	$a2,$a2,%lo(var8007fac0)
/*  f17b20c:	00005012 */ 	mflo	$t2
/*  f17b210:	000a5a02 */ 	srl	$t3,$t2,0x8
/*  f17b214:	018b2825 */ 	or	$a1,$t4,$t3
/*  f17b218:	ada50004 */ 	sw	$a1,0x4($t5)
/*  f17b21c:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f17b220:	3c0cff37 */ 	lui	$t4,0xff37
/*  f17b224:	3c0afc12 */ 	lui	$t2,0xfc12
/*  f17b228:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f17b22c:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f17b230:	354a9a25 */ 	ori	$t2,$t2,0x9a25
/*  f17b234:	358cffff */ 	ori	$t4,$t4,0xffff
/*  f17b238:	adec0004 */ 	sw	$t4,0x4($t7)
/*  f17b23c:	adea0000 */ 	sw	$t2,0x0($t7)
/*  f17b240:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f17b244:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f17b248:	3c01e400 */ 	lui	$at,0xe400
/*  f17b24c:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f17b250:	afad006c */ 	sw	$t5,0x6c($sp)
/*  f17b254:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f17b258:	01602025 */ 	or	$a0,$t3,$zero
/*  f17b25c:	25d80014 */ 	addiu	$t8,$t6,0x14
/*  f17b260:	00187880 */ 	sll	$t7,$t8,0x2
/*  f17b264:	01f90019 */ 	multu	$t7,$t9
/*  f17b268:	8d0e0004 */ 	lw	$t6,0x4($t0)
/*  f17b26c:	25d8000b */ 	addiu	$t8,$t6,0xb
/*  f17b270:	00187880 */ 	sll	$t7,$t8,0x2
/*  f17b274:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f17b278:	00005012 */ 	mflo	$t2
/*  f17b27c:	314c0fff */ 	andi	$t4,$t2,0xfff
/*  f17b280:	000c5b00 */ 	sll	$t3,$t4,0xc
/*  f17b284:	01616825 */ 	or	$t5,$t3,$at
/*  f17b288:	01b95025 */ 	or	$t2,$t5,$t9
/*  f17b28c:	ac8a0000 */ 	sw	$t2,0x0($a0)
/*  f17b290:	8d0c0000 */ 	lw	$t4,0x0($t0)
/*  f17b294:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f17b298:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*  f17b29c:	258b0009 */ 	addiu	$t3,$t4,0x9
/*  f17b2a0:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f17b2a4:	01d80019 */ 	multu	$t6,$t8
/*  f17b2a8:	000a6080 */ 	sll	$t4,$t2,0x2
/*  f17b2ac:	318b0fff */ 	andi	$t3,$t4,0xfff
/*  f17b2b0:	240a0160 */ 	addiu	$t2,$zero,0x160
/*  f17b2b4:	00007812 */ 	mflo	$t7
/*  f17b2b8:	31ed0fff */ 	andi	$t5,$t7,0xfff
/*  f17b2bc:	000dcb00 */ 	sll	$t9,$t5,0xc
/*  f17b2c0:	032b7025 */ 	or	$t6,$t9,$t3
/*  f17b2c4:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f17b2c8:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f17b2cc:	3c0db400 */ 	lui	$t5,0xb400
/*  f17b2d0:	3c0bb300 */ 	lui	$t3,0xb300
/*  f17b2d4:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f17b2d8:	afaf006c */ 	sw	$t7,0x6c($sp)
/*  f17b2dc:	af0a0004 */ 	sw	$t2,0x4($t8)
/*  f17b2e0:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f17b2e4:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f17b2e8:	03001825 */ 	or	$v1,$t8,$zero
/*  f17b2ec:	24180400 */ 	addiu	$t8,$zero,0x400
/*  f17b2f0:	25990008 */ 	addiu	$t9,$t4,0x8
/*  f17b2f4:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f17b2f8:	ad8b0000 */ 	sw	$t3,0x0($t4)
/*  f17b2fc:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f17b300:	01802025 */ 	or	$a0,$t4,$zero
/*  f17b304:	030e001a */ 	div	$zero,$t8,$t6
/*  f17b308:	00007812 */ 	mflo	$t7
/*  f17b30c:	31edffff */ 	andi	$t5,$t7,0xffff
/*  f17b310:	000d5400 */ 	sll	$t2,$t5,0x10
/*  f17b314:	354cfc00 */ 	ori	$t4,$t2,0xfc00
/*  f17b318:	ac8c0004 */ 	sw	$t4,0x4($a0)
/*  f17b31c:	15c00002 */ 	bnez	$t6,.L0f17b328
/*  f17b320:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17b324:	0007000d */ 	break	0x7
.L0f17b328:
/*  f17b328:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17b32c:	15c10004 */ 	bne	$t6,$at,.L0f17b340
/*  f17b330:	3c018000 */ 	lui	$at,0x8000
/*  f17b334:	17010002 */ 	bne	$t8,$at,.L0f17b340
/*  f17b338:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17b33c:	0006000d */ 	break	0x6
.L0f17b340:
/*  f17b340:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*  f17b344:	10000003 */ 	beqz	$zero,.L0f17b354
/*  f17b348:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f17b34c:
/*  f17b34c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17b350:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f17b354:
/*  f17b354:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f17b358:	03e00008 */ 	jr	$ra
/*  f17b35c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f17b360
/*  f17b360:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17b364:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17b368:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17b36c:	0fc5b9f1 */ 	jal	textGet
/*  f17b370:	24045091 */ 	addiu	$a0,$zero,0x5091
/*  f17b374:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17b378:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17b37c:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f17b380:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f17b384:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17b388:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17b38c:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17b390:	3c048007 */ 	lui	$a0,0x8007
/*  f17b394:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17b398:	01f83021 */ 	addu	$a2,$t7,$t8
/*  f17b39c:	0c004dad */ 	jal	sprintf
/*  f17b3a0:	00402825 */ 	or	$a1,$v0,$zero
/*  f17b3a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17b3a8:	3c028007 */ 	lui	$v0,0x8007
/*  f17b3ac:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17b3b0:	03e00008 */ 	jr	$ra
/*  f17b3b4:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

s32 menuhandlerMpUsernamePassword(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MpPlayers[g_MpPlayerNum].title != MPPLAYERTITLE_PERFECT) {
			return true;
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f17b408
/*  f17b408:	3c0f8008 */ 	lui	$t7,%hi(var800851bc)
/*  f17b40c:	25ef51bc */ 	addiu	$t7,$t7,%lo(var800851bc)
/*  f17b410:	8de10000 */ 	lw	$at,0x0($t7)
/*  f17b414:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f17b418:	27ae0020 */ 	addiu	$t6,$sp,0x20
/*  f17b41c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f17b420:	8de10008 */ 	lw	$at,0x8($t7)
/*  f17b424:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f17b428:	3c0a8008 */ 	lui	$t2,%hi(var800851cc)
/*  f17b42c:	adc10008 */ 	sw	$at,0x8($t6)
/*  f17b430:	99e1000e */ 	lwr	$at,0xe($t7)
/*  f17b434:	254a51cc */ 	addiu	$t2,$t2,%lo(var800851cc)
/*  f17b438:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f17b43c:	b9c1000e */ 	swr	$at,0xe($t6)
/*  f17b440:	8d410000 */ 	lw	$at,0x0($t2)
/*  f17b444:	27a90014 */ 	addiu	$t1,$sp,0x14
/*  f17b448:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f17b44c:	ad210000 */ 	sw	$at,0x0($t1)
/*  f17b450:	95410008 */ 	lhu	$at,0x8($t2)
/*  f17b454:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f17b458:	27a30020 */ 	addiu	$v1,$sp,0x20
/*  f17b45c:	a5210008 */ 	sh	$at,0x8($t1)
/*  f17b460:	90990001 */ 	lbu	$t9,0x1($a0)
/*  f17b464:	00002025 */ 	or	$a0,$zero,$zero
/*  f17b468:	00001025 */ 	or	$v0,$zero,$zero
/*  f17b46c:	1720000f */ 	bnez	$t9,.L0f17b4ac
/*  f17b470:	2406000f */ 	addiu	$a2,$zero,0xf
/*  f17b474:	3c058007 */ 	lui	$a1,%hi(var80071440)
/*  f17b478:	24a51440 */ 	addiu	$a1,$a1,%lo(var80071440)
.L0f17b47c:
/*  f17b47c:	90780000 */ 	lbu	$t8,0x0($v1)
/*  f17b480:	8ca80000 */ 	lw	$t0,0x0($a1)
/*  f17b484:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17b488:	03047023 */ 	subu	$t6,$t8,$a0
/*  f17b48c:	01026021 */ 	addu	$t4,$t0,$v0
/*  f17b490:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f17b494:	25cffff7 */ 	addiu	$t7,$t6,-9
/*  f17b498:	24840009 */ 	addiu	$a0,$a0,0x9
/*  f17b49c:	1446fff7 */ 	bne	$v0,$a2,.L0f17b47c
/*  f17b4a0:	a18f0000 */ 	sb	$t7,0x0($t4)
/*  f17b4a4:	10000012 */ 	beqz	$zero,.L0f17b4f0
/*  f17b4a8:	8ca20000 */ 	lw	$v0,0x0($a1)
.L0f17b4ac:
/*  f17b4ac:	3c058007 */ 	lui	$a1,%hi(var80071440)
/*  f17b4b0:	24a51440 */ 	addiu	$a1,$a1,%lo(var80071440)
/*  f17b4b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f17b4b8:	27a30014 */ 	addiu	$v1,$sp,0x14
/*  f17b4bc:	00002025 */ 	or	$a0,$zero,$zero
/*  f17b4c0:	2406000a */ 	addiu	$a2,$zero,0xa
.L0f17b4c4:
/*  f17b4c4:	906b0000 */ 	lbu	$t3,0x0($v1)
/*  f17b4c8:	8cad0000 */ 	lw	$t5,0x0($a1)
/*  f17b4cc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17b4d0:	01644823 */ 	subu	$t1,$t3,$a0
/*  f17b4d4:	01a2c821 */ 	addu	$t9,$t5,$v0
/*  f17b4d8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f17b4dc:	252afffc */ 	addiu	$t2,$t1,-4
/*  f17b4e0:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f17b4e4:	1446fff7 */ 	bne	$v0,$a2,.L0f17b4c4
/*  f17b4e8:	a32a0000 */ 	sb	$t2,0x0($t9)
/*  f17b4ec:	8ca20000 */ 	lw	$v0,0x0($a1)
.L0f17b4f0:
/*  f17b4f0:	03e00008 */ 	jr	$ra
/*  f17b4f4:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f17b4f8
/*  f17b4f8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f17b4fc:	248effff */ 	addiu	$t6,$a0,-1
/*  f17b500:	2dc10015 */ 	sltiu	$at,$t6,0x15
/*  f17b504:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f17b508:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f17b50c:	102000c7 */ 	beqz	$at,.L0f17b82c
/*  f17b510:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f17b514:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17b518:	3c017f1c */ 	lui	$at,%hi(var7f1b80f0)
/*  f17b51c:	002e0821 */ 	addu	$at,$at,$t6
/*  f17b520:	8c2e80f0 */ 	lw	$t6,%lo(var7f1b80f0)($at)
/*  f17b524:	01c00008 */ 	jr	$t6
/*  f17b528:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17b52c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b530:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17b534:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17b538:	100000bc */ 	beqz	$zero,.L0f17b82c
/*  f17b53c:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f17b540:	3c0f8007 */ 	lui	$t7,0x8007
/*  f17b544:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f17b548:	3c017f1c */ 	lui	$at,%hi(var7f1b8144)
/*  f17b54c:	c4248144 */ 	lwc1	$f4,%lo(var7f1b8144)($at)
/*  f17b550:	3c01800a */ 	lui	$at,0x800a
/*  f17b554:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f17b558:	c4269fc4 */ 	lwc1	$f6,-0x603c($at)
/*  f17b55c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f17b560:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f17b564:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17b568:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f17b56c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f17b570:	3c19800a */ 	lui	$t9,%hi(var8009e000)
/*  f17b574:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f17b578:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f17b57c:	2739e000 */ 	addiu	$t9,$t9,%lo(var8009e000)
/*  f17b580:	03191821 */ 	addu	$v1,$t8,$t9
/*  f17b584:	c46a0d64 */ 	lwc1	$f10,0xd64($v1)
/*  f17b588:	46085000 */ 	add.s	$f0,$f10,$f8
/*  f17b58c:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f17b590:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b594:	e4600d64 */ 	swc1	$f0,0xd64($v1)
/*  f17b598:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f17b59c:	0062082a */ 	slt	$at,$v1,$v0
/*  f17b5a0:	1020001a */ 	beqz	$at,.L0f17b60c
/*  f17b5a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17b5a8:	0fc62ecb */ 	jal	mpGetHeadId
/*  f17b5ac:	306400ff */ 	andi	$a0,$v1,0xff
/*  f17b5b0:	3c088007 */ 	lui	$t0,0x8007
/*  f17b5b4:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f17b5b8:	3c0a800a */ 	lui	$t2,%hi(var8009e000)
/*  f17b5bc:	254ae000 */ 	addiu	$t2,$t2,%lo(var8009e000)
/*  f17b5c0:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f17b5c4:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17b5c8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f17b5cc:	01284821 */ 	addu	$t1,$t1,$t0
/*  f17b5d0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f17b5d4:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17b5d8:	00094900 */ 	sll	$t1,$t1,0x4
/*  f17b5dc:	00025880 */ 	sll	$t3,$v0,0x2
/*  f17b5e0:	01625821 */ 	addu	$t3,$t3,$v0
/*  f17b5e4:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f17b5e8:	906d0df1 */ 	lbu	$t5,0xdf1($v1)
/*  f17b5ec:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f17b5f0:	3c0c8008 */ 	lui	$t4,0x8008
/*  f17b5f4:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f17b5f8:	958ccf06 */ 	lhu	$t4,-0x30fa($t4)
/*  f17b5fc:	31aeff7f */ 	andi	$t6,$t5,0xff7f
/*  f17b600:	a06e0df1 */ 	sb	$t6,0xdf1($v1)
/*  f17b604:	1000002e */ 	beqz	$zero,.L0f17b6c0
/*  f17b608:	ac6c084c */ 	sw	$t4,0x84c($v1)
.L0f17b60c:
/*  f17b60c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17b614:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f17b618:	0fc52a7e */ 	jal	func0f14a9f8
/*  f17b61c:	01e22023 */ 	subu	$a0,$t7,$v0
/*  f17b620:	0fc62ed9 */ 	jal	mpGetBeauHeadId
/*  f17b624:	304400ff */ 	andi	$a0,$v0,0xff
/*  f17b628:	3c188007 */ 	lui	$t8,0x8007
/*  f17b62c:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f17b630:	3c08800a */ 	lui	$t0,%hi(var8009e000)
/*  f17b634:	2508e000 */ 	addiu	$t0,$t0,%lo(var8009e000)
/*  f17b638:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f17b63c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17b640:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17b644:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f17b648:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17b64c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17b650:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17b654:	00024880 */ 	sll	$t1,$v0,0x2
/*  f17b658:	01224821 */ 	addu	$t1,$t1,$v0
/*  f17b65c:	03281821 */ 	addu	$v1,$t9,$t0
/*  f17b660:	906c0df1 */ 	lbu	$t4,0xdf1($v1)
/*  f17b664:	00094880 */ 	sll	$t1,$t1,0x2
/*  f17b668:	3c0a8008 */ 	lui	$t2,0x8008
/*  f17b66c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f17b670:	954acf06 */ 	lhu	$t2,-0x30fa($t2)
/*  f17b674:	358d0080 */ 	ori	$t5,$t4,0x80
/*  f17b678:	a06d0df1 */ 	sb	$t5,0xdf1($v1)
/*  f17b67c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b680:	ac6a084c */ 	sw	$t2,0x84c($v1)
/*  f17b684:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17b688:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17b68c:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f17b690:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f17b694:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17b698:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17b69c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17b6a0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17b6a4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17b6a8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17b6ac:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17b6b0:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f17b6b4:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f17b6b8:	03224023 */ 	subu	$t0,$t9,$v0
/*  f17b6bc:	a0680df0 */ 	sb	$t0,0xdf0($v1)
.L0f17b6c0:
/*  f17b6c0:	3c0141f0 */ 	lui	$at,0x41f0
/*  f17b6c4:	44818000 */ 	mtc1	$at,$f16
/*  f17b6c8:	3c098008 */ 	lui	$t1,%hi(var80085448)
/*  f17b6cc:	25295448 */ 	addiu	$t1,$t1,%lo(var80085448)
/*  f17b6d0:	ac600db4 */ 	sw	$zero,0xdb4($v1)
/*  f17b6d4:	ac690df4 */ 	sw	$t1,0xdf4($v1)
/*  f17b6d8:	10000054 */ 	beqz	$zero,.L0f17b82c
/*  f17b6dc:	e4700d94 */ 	swc1	$f16,0xd94($v1)
/*  f17b6e0:	0fc62ed2 */ 	jal	mpGetHeadUnlockValue
/*  f17b6e4:	90c40003 */ 	lbu	$a0,0x3($a2)
/*  f17b6e8:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f17b6ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f17b6f0:	5440004f */ 	bnezl	$v0,.L0f17b830
/*  f17b6f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f17b6f8:	1000004d */ 	beqz	$zero,.L0f17b830
/*  f17b6fc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f17b700:	8faa003c */ 	lw	$t2,0x3c($sp)
/*  f17b704:	10000049 */ 	beqz	$zero,.L0f17b82c
/*  f17b708:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f17b70c:	3c0c8007 */ 	lui	$t4,0x8007
/*  f17b710:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f17b714:	3c01800a */ 	lui	$at,0x800a
/*  f17b718:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f17b71c:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f17b720:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17b724:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f17b728:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f17b72c:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f17b730:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17b734:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f17b738:	002d0821 */ 	addu	$at,$at,$t5
/*  f17b73c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b740:	a02be840 */ 	sb	$t3,-0x17c0($at)
/*  f17b744:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17b748:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17b74c:	44800000 */ 	mtc1	$zero,$f0
/*  f17b750:	3c013f80 */ 	lui	$at,0x3f80
/*  f17b754:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17b758:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17b75c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17b760:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17b764:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17b768:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17b76c:	44819000 */ 	mtc1	$at,$f18
/*  f17b770:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17b774:	3c19800a */ 	lui	$t9,%hi(var8009e000)
/*  f17b778:	2739e000 */ 	addiu	$t9,$t9,%lo(var8009e000)
/*  f17b77c:	25f80840 */ 	addiu	$t8,$t7,0x840
/*  f17b780:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f17b784:	44050000 */ 	mfc1	$a1,$f0
/*  f17b788:	44060000 */ 	mfc1	$a2,$f0
/*  f17b78c:	44070000 */ 	mfc1	$a3,$f0
/*  f17b790:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f17b794:	03192021 */ 	addu	$a0,$t8,$t9
/*  f17b798:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f17b79c:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f17b7a0:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f17b7a4:	0fc3cdcb */ 	jal	func0f0f372c
/*  f17b7a8:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f17b7ac:	3c098007 */ 	lui	$t1,0x8007
/*  f17b7b0:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f17b7b4:	3c017f1c */ 	lui	$at,%hi(var7f1b8148)
/*  f17b7b8:	3c0c800a */ 	lui	$t4,%hi(var8009e000)
/*  f17b7bc:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f17b7c0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f17b7c4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f17b7c8:	01495021 */ 	addu	$t2,$t2,$t1
/*  f17b7cc:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f17b7d0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f17b7d4:	c4228148 */ 	lwc1	$f2,%lo(var7f1b8148)($at)
/*  f17b7d8:	44800000 */ 	mtc1	$zero,$f0
/*  f17b7dc:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f17b7e0:	258ce000 */ 	addiu	$t4,$t4,%lo(var8009e000)
/*  f17b7e4:	014c1821 */ 	addu	$v1,$t2,$t4
/*  f17b7e8:	3c01c040 */ 	lui	$at,0xc040
/*  f17b7ec:	44812000 */ 	mtc1	$at,$f4
/*  f17b7f0:	3c017f1c */ 	lui	$at,%hi(var7f1b814c)
/*  f17b7f4:	e4600d50 */ 	swc1	$f0,0xd50($v1)
/*  f17b7f8:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f17b7fc:	e4600d78 */ 	swc1	$f0,0xd78($v1)
/*  f17b800:	e4640d7c */ 	swc1	$f4,0xd7c($v1)
/*  f17b804:	c426814c */ 	lwc1	$f6,%lo(var7f1b814c)($at)
/*  f17b808:	3c013f80 */ 	lui	$at,0x3f80
/*  f17b80c:	44815000 */ 	mtc1	$at,$f10
/*  f17b810:	3c0141f0 */ 	lui	$at,0x41f0
/*  f17b814:	44814000 */ 	mtc1	$at,$f8
/*  f17b818:	e4620d64 */ 	swc1	$f2,0xd64($v1)
/*  f17b81c:	e4620d8c */ 	swc1	$f2,0xd8c($v1)
/*  f17b820:	e4660d5c */ 	swc1	$f6,0xd5c($v1)
/*  f17b824:	e46a0d84 */ 	swc1	$f10,0xd84($v1)
/*  f17b828:	e4680d94 */ 	swc1	$f8,0xd94($v1)
.L0f17b82c:
/*  f17b82c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17b830:
/*  f17b830:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17b834:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f17b838:	03e00008 */ 	jr	$ra
/*  f17b83c:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMpCharacterHead(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_MpPlayers[g_MpPlayerNum].base.headnum = *value;
	}

	return func0f17b4f8(operation, item, value, g_MpPlayers[g_MpPlayerNum].base.headnum, 1);
}

GLOBAL_ASM(
glabel func0f17b8b0
/*  f17b8b0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17b8b4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17b8b8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17b8bc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17b8c0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17b8c4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17b8c8:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17b8cc:	3c04800b */ 	lui	$a0,0x800b
/*  f17b8d0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17b8d4:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f17b8d8:	0fc62f0c */ 	jal	mpGetBodyName
/*  f17b8dc:	9084c7c8 */ 	lbu	$a0,-0x3838($a0)
/*  f17b8e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17b8e4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17b8e8:	03e00008 */ 	jr	$ra
/*  f17b8ec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f17b8f0
/*  f17b8f0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17b8f4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17b8f8:	3c048008 */ 	lui	$a0,%hi(menuitems_mpcharacter)
/*  f17b8fc:	3c05becc */ 	lui	$a1,0xbecc
/*  f17b900:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f17b904:	0fc3c4e7 */ 	jal	func0f0f139c
/*  f17b908:	24845450 */ 	addiu	$a0,$a0,%lo(menuitems_mpcharacter)
/*  f17b90c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17b910:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17b914:	03e00008 */ 	jr	$ra
/*  f17b918:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler0017b91c
/*  f17b91c:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f17b920:	24010011 */ 	addiu	$at,$zero,0x11
/*  f17b924:	10810006 */ 	beq	$a0,$at,.L0f17b940
/*  f17b928:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f17b92c:	24010012 */ 	addiu	$at,$zero,0x12
/*  f17b930:	10810034 */ 	beq	$a0,$at,.L0f17ba04
/*  f17b934:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f17b938:	03e00008 */ 	jr	$ra
/*  f17b93c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17b940:
/*  f17b940:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f17b944:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f17b948:	8d040000 */ 	lw	$a0,0x0($t0)
/*  f17b94c:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f17b950:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f17b954:	00047080 */ 	sll	$t6,$a0,0x2
/*  f17b958:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f17b95c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f17b960:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f17b964:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f17b968:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f17b96c:	00001825 */ 	or	$v1,$zero,$zero
/*  f17b970:	1138001a */ 	beq	$t1,$t8,.L0f17b9dc
/*  f17b974:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f17b978:	0324c821 */ 	addu	$t9,$t9,$a0
/*  f17b97c:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f17b980:	00f92821 */ 	addu	$a1,$a3,$t9
/*  f17b984:	90ab0000 */ 	lbu	$t3,0x0($a1)
/*  f17b988:	00403021 */ 	addu	$a2,$v0,$zero
/*  f17b98c:	240a000b */ 	addiu	$t2,$zero,0xb
/*  f17b990:	51600013 */ 	beqzl	$t3,.L0f17b9e0
/*  f17b994:	2861000b */ 	slti	$at,$v1,0xb
/*  f17b998:	90a40000 */ 	lbu	$a0,0x0($a1)
/*  f17b99c:	a0c40000 */ 	sb	$a0,0x0($a2)
.L0f17b9a0:
/*  f17b9a0:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f17b9a4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17b9a8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17b9ac:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f17b9b0:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f17b9b4:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f17b9b8:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f17b9bc:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f17b9c0:	93040000 */ 	lbu	$a0,0x0($t8)
/*  f17b9c4:	51240006 */ 	beql	$t1,$a0,.L0f17b9e0
/*  f17b9c8:	2861000b */ 	slti	$at,$v1,0xb
/*  f17b9cc:	50800004 */ 	beqzl	$a0,.L0f17b9e0
/*  f17b9d0:	2861000b */ 	slti	$at,$v1,0xb
/*  f17b9d4:	546afff2 */ 	bnel	$v1,$t2,.L0f17b9a0
/*  f17b9d8:	a0c40000 */ 	sb	$a0,0x0($a2)
.L0f17b9dc:
/*  f17b9dc:	2861000b */ 	slti	$at,$v1,0xb
.L0f17b9e0:
/*  f17b9e0:	10200032 */ 	beqz	$at,.L0f17baac
/*  f17b9e4:	00433021 */ 	addu	$a2,$v0,$v1
.L0f17b9e8:
/*  f17b9e8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17b9ec:	2861000b */ 	slti	$at,$v1,0xb
/*  f17b9f0:	a0c00000 */ 	sb	$zero,0x0($a2)
/*  f17b9f4:	1420fffc */ 	bnez	$at,.L0f17b9e8
/*  f17b9f8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17b9fc:	03e00008 */ 	jr	$ra
/*  f17ba00:	00001025 */ 	or	$v0,$zero,$zero
.L0f17ba04:
/*  f17ba04:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f17ba08:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f17ba0c:	00001825 */ 	or	$v1,$zero,$zero
/*  f17ba10:	13200014 */ 	beqz	$t9,.L0f17ba64
/*  f17ba14:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f17ba18:	3c0b8007 */ 	lui	$t3,0x8007
/*  f17ba1c:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f17ba20:	3c0e800b */ 	lui	$t6,%hi(g_MpPlayers)
/*  f17ba24:	25cec7b8 */ 	addiu	$t6,$t6,%lo(g_MpPlayers)
/*  f17ba28:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f17ba2c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f17ba30:	000c6140 */ 	sll	$t4,$t4,0x5
/*  f17ba34:	018e2021 */ 	addu	$a0,$t4,$t6
/*  f17ba38:	00403021 */ 	addu	$a2,$v0,$zero
/*  f17ba3c:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f17ba40:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f17ba44:
/*  f17ba44:	2861000b */ 	slti	$at,$v1,0xb
/*  f17ba48:	a0850000 */ 	sb	$a1,0x0($a0)
/*  f17ba4c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f17ba50:	10200004 */ 	beqz	$at,.L0f17ba64
/*  f17ba54:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17ba58:	90c50000 */ 	lbu	$a1,0x0($a2)
/*  f17ba5c:	54a0fff9 */ 	bnezl	$a1,.L0f17ba44
/*  f17ba60:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f17ba64:
/*  f17ba64:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f17ba68:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f17ba6c:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f17ba70:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f17ba74:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17ba78:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f17ba7c:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f17ba80:	03232021 */ 	addu	$a0,$t9,$v1
/*  f17ba84:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17ba88:	2861000b */ 	slti	$at,$v1,0xb
/*  f17ba8c:	a08b0000 */ 	sb	$t3,0x0($a0)
/*  f17ba90:	10200006 */ 	beqz	$at,.L0f17baac
/*  f17ba94:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f17ba98:
/*  f17ba98:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17ba9c:	2861000b */ 	slti	$at,$v1,0xb
/*  f17baa0:	a0800000 */ 	sb	$zero,0x0($a0)
/*  f17baa4:	1420fffc */ 	bnez	$at,.L0f17ba98
/*  f17baa8:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f17baac:
/*  f17baac:	03e00008 */ 	jr	$ra
/*  f17bab0:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel menuhandler0017bab4
/*  f17bab4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f17bab8:	248fffff */ 	addiu	$t7,$a0,-1
/*  f17babc:	2de10010 */ 	sltiu	$at,$t7,0x10
/*  f17bac0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17bac4:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f17bac8:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f17bacc:	102000d2 */ 	beqz	$at,.L0f17be18
/*  f17bad0:	00c03825 */ 	or	$a3,$a2,$zero
/*  f17bad4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17bad8:	3c017f1c */ 	lui	$at,%hi(var7f1b8150)
/*  f17badc:	002f0821 */ 	addu	$at,$at,$t7
/*  f17bae0:	8c2f8150 */ 	lw	$t7,%lo(var7f1b8150)($at)
/*  f17bae4:	01e00008 */ 	jr	$t7
/*  f17bae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17baec:	0fc63703 */ 	jal	func0f18dc0c
/*  f17baf0:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17baf4:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17baf8:	3c038007 */ 	lui	$v1,0x8007
/*  f17bafc:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f17bb00:	8c635bc4 */ 	lw	$v1,0x5bc4($v1)
/*  f17bb04:	506000c5 */ 	beqzl	$v1,.L0f17be1c
/*  f17bb08:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bb0c:	847902d0 */ 	lh	$t9,0x2d0($v1)
/*  f17bb10:	00594021 */ 	addu	$t0,$v0,$t9
/*  f17bb14:	100000c0 */ 	beqz	$zero,.L0f17be18
/*  f17bb18:	ace80000 */ 	sw	$t0,0x0($a3)
/*  f17bb1c:	0fc63703 */ 	jal	func0f18dc0c
/*  f17bb20:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bb24:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bb28:	3c098007 */ 	lui	$t1,0x8007
/*  f17bb2c:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f17bb30:	0062082b */ 	sltu	$at,$v1,$v0
/*  f17bb34:	10200005 */ 	beqz	$at,.L0f17bb4c
/*  f17bb38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17bb3c:	0fc63719 */ 	jal	func0f18dc64
/*  f17bb40:	00602025 */ 	or	$a0,$v1,$zero
/*  f17bb44:	100000b6 */ 	beqz	$zero,.L0f17be20
/*  f17bb48:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17bb4c:
/*  f17bb4c:	8d295bc4 */ 	lw	$t1,0x5bc4($t1)
/*  f17bb50:	512000b2 */ 	beqzl	$t1,.L0f17be1c
/*  f17bb54:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bb58:	0fc63703 */ 	jal	func0f18dc0c
/*  f17bb5c:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bb60:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bb64:	3c0a8007 */ 	lui	$t2,0x8007
/*  f17bb68:	8d4a5bc4 */ 	lw	$t2,0x5bc4($t2)
/*  f17bb6c:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f17bb70:	00027080 */ 	sll	$t6,$v0,0x2
/*  f17bb74:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f17bb78:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f17bb7c:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f17bb80:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f17bb84:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f17bb88:	000e7823 */ 	negu	$t7,$t6
/*  f17bb8c:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f17bb90:	01af2021 */ 	addu	$a0,$t5,$t7
/*  f17bb94:	3c058007 */ 	lui	$a1,0x8007
/*  f17bb98:	8ca51440 */ 	lw	$a1,0x1440($a1)
/*  f17bb9c:	24840006 */ 	addiu	$a0,$a0,0x6
/*  f17bba0:	0fc35593 */ 	jal	func0f0d564c
/*  f17bba4:	00003025 */ 	or	$a2,$zero,$zero
/*  f17bba8:	3c028007 */ 	lui	$v0,0x8007
/*  f17bbac:	1000009b */ 	beqz	$zero,.L0f17be1c
/*  f17bbb0:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17bbb4:	0fc5fe8a */ 	jal	func0f17fa28
/*  f17bbb8:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bbbc:	0fc63703 */ 	jal	func0f18dc0c
/*  f17bbc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17bbc4:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bbc8:	3c188007 */ 	lui	$t8,0x8007
/*  f17bbcc:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f17bbd0:	0062082b */ 	sltu	$at,$v1,$v0
/*  f17bbd4:	10200005 */ 	beqz	$at,.L0f17bbec
/*  f17bbd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17bbdc:	0fc637b1 */ 	jal	func0f18dec4
/*  f17bbe0:	00602025 */ 	or	$a0,$v1,$zero
/*  f17bbe4:	1000001c */ 	beqz	$zero,.L0f17bc58
/*  f17bbe8:	8faf0034 */ 	lw	$t7,0x34($sp)
.L0f17bbec:
/*  f17bbec:	8f185bc4 */ 	lw	$t8,0x5bc4($t8)
/*  f17bbf0:	53000019 */ 	beqzl	$t8,.L0f17bc58
/*  f17bbf4:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f17bbf8:	0fc63703 */ 	jal	func0f18dc0c
/*  f17bbfc:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bc00:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bc04:	3c198007 */ 	lui	$t9,0x8007
/*  f17bc08:	8f395bc4 */ 	lw	$t9,0x5bc4($t9)
/*  f17bc0c:	8ce80000 */ 	lw	$t0,0x0($a3)
/*  f17bc10:	00025080 */ 	sll	$t2,$v0,0x2
/*  f17bc14:	01425023 */ 	subu	$t2,$t2,$v0
/*  f17bc18:	00084880 */ 	sll	$t1,$t0,0x2
/*  f17bc1c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17bc20:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f17bc24:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f17bc28:	000a6023 */ 	negu	$t4,$t2
/*  f17bc2c:	03295821 */ 	addu	$t3,$t9,$t1
/*  f17bc30:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f17bc34:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f17bc38:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f17bc3c:	24050066 */ 	addiu	$a1,$zero,0x66
/*  f17bc40:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f17bc44:	946d0004 */ 	lhu	$t5,0x4($v1)
/*  f17bc48:	00003025 */ 	or	$a2,$zero,$zero
/*  f17bc4c:	0fc42539 */ 	jal	func0f1094e4
/*  f17bc50:	a7ad0028 */ 	sh	$t5,0x28($sp)
/*  f17bc54:	8faf0034 */ 	lw	$t7,0x34($sp)
.L0f17bc58:
/*  f17bc58:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f17bc5c:	3c088009 */ 	lui	$t0,0x8009
/*  f17bc60:	91f80001 */ 	lbu	$t8,0x1($t7)
/*  f17bc64:	5458006d */ 	bnel	$v0,$t8,.L0f17be1c
/*  f17bc68:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bc6c:	91080af0 */ 	lbu	$t0,0xaf0($t0)
/*  f17bc70:	3c048008 */ 	lui	$a0,%hi(g_MpQuickGoMenuDialog)
/*  f17bc74:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f17bc78:	14480006 */ 	bne	$v0,$t0,.L0f17bc94
/*  f17bc7c:	24846500 */ 	addiu	$a0,$a0,%lo(g_MpQuickGoMenuDialog)
/*  f17bc80:	3c048007 */ 	lui	$a0,%hi(menudialog_mpquickgo2)
/*  f17bc84:	0fc3e083 */ 	jal	func0f0f820c
/*  f17bc88:	24845120 */ 	addiu	$a0,$a0,%lo(menudialog_mpquickgo2)
/*  f17bc8c:	10000063 */ 	beqz	$zero,.L0f17be1c
/*  f17bc90:	00001025 */ 	or	$v0,$zero,$zero
.L0f17bc94:
/*  f17bc94:	0fc3e083 */ 	jal	func0f0f820c
/*  f17bc98:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f17bc9c:	1000005f */ 	beqz	$zero,.L0f17be1c
/*  f17bca0:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bca4:	3c19000f */ 	lui	$t9,0xf
/*  f17bca8:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f17bcac:	1000005a */ 	beqz	$zero,.L0f17be18
/*  f17bcb0:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f17bcb4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f17bcb8:	ace90000 */ 	sw	$t1,0x0($a3)
/*  f17bcbc:	3c038007 */ 	lui	$v1,0x8007
/*  f17bcc0:	8c635bc4 */ 	lw	$v1,0x5bc4($v1)
/*  f17bcc4:	50600055 */ 	beqzl	$v1,.L0f17be1c
/*  f17bcc8:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bccc:	906b030a */ 	lbu	$t3,0x30a($v1)
/*  f17bcd0:	012b6021 */ 	addu	$t4,$t1,$t3
/*  f17bcd4:	10000050 */ 	beqz	$zero,.L0f17be18
/*  f17bcd8:	acec0000 */ 	sw	$t4,0x0($a3)
/*  f17bcdc:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f17bce0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17bce4:	14600005 */ 	bnez	$v1,.L0f17bcfc
/*  f17bce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17bcec:	0fc5b9f1 */ 	jal	textGet
/*  f17bcf0:	2404508d */ 	addiu	$a0,$zero,0x508d
/*  f17bcf4:	1000004a */ 	beqz	$zero,.L0f17be20
/*  f17bcf8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17bcfc:
/*  f17bcfc:	8dce5bc4 */ 	lw	$t6,0x5bc4($t6)
/*  f17bd00:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f17bd04:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f17bd08:	51c00044 */ 	beqzl	$t6,.L0f17be1c
/*  f17bd0c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bd10:	0fc421ae */ 	jal	func0f1086b8
/*  f17bd14:	2466ffff */ 	addiu	$a2,$v1,-1
/*  f17bd18:	10000041 */ 	beqz	$zero,.L0f17be20
/*  f17bd1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17bd20:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f17bd24:	15a00003 */ 	bnez	$t5,.L0f17bd34
/*  f17bd28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17bd2c:	1000003a */ 	beqz	$zero,.L0f17be18
/*  f17bd30:	ace00008 */ 	sw	$zero,0x8($a3)
.L0f17bd34:
/*  f17bd34:	0fc63703 */ 	jal	func0f18dc0c
/*  f17bd38:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bd3c:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bd40:	3c0f8007 */ 	lui	$t7,0x8007
/*  f17bd44:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f17bd48:	ace20008 */ 	sw	$v0,0x8($a3)
/*  f17bd4c:	8def5bc4 */ 	lw	$t7,0x5bc4($t7)
/*  f17bd50:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f17bd54:	51e00031 */ 	beqzl	$t7,.L0f17be1c
/*  f17bd58:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bd5c:	8ce60000 */ 	lw	$a2,0x0($a3)
/*  f17bd60:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bd64:	0fc421ae */ 	jal	func0f1086b8
/*  f17bd68:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f17bd6c:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bd70:	8cf80008 */ 	lw	$t8,0x8($a3)
/*  f17bd74:	03024021 */ 	addu	$t0,$t8,$v0
/*  f17bd78:	10000027 */ 	beqz	$zero,.L0f17be18
/*  f17bd7c:	ace80008 */ 	sw	$t0,0x8($a3)
/*  f17bd80:	0fc63703 */ 	jal	func0f18dc0c
/*  f17bd84:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bd88:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bd8c:	3c0a8007 */ 	lui	$t2,0x8007
/*  f17bd90:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f17bd94:	0322082b */ 	sltu	$at,$t9,$v0
/*  f17bd98:	1020000e */ 	beqz	$at,.L0f17bdd4
/*  f17bd9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17bda0:	8d4a1448 */ 	lw	$t2,0x1448($t2)
/*  f17bda4:	3c01800a */ 	lui	$at,0x800a
/*  f17bda8:	3409ffff */ 	dli	$t1,0xffff
/*  f17bdac:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f17bdb0:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f17bdb4:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f17bdb8:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f17bdbc:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f17bdc0:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f17bdc4:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f17bdc8:	002b0821 */ 	addu	$at,$at,$t3
/*  f17bdcc:	10000012 */ 	beqz	$zero,.L0f17be18
/*  f17bdd0:	ac29ee1c */ 	sw	$t1,-0x11e4($at)
.L0f17bdd4:
/*  f17bdd4:	0fc63703 */ 	jal	func0f18dc0c
/*  f17bdd8:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bddc:	3c0d8007 */ 	lui	$t5,0x8007
/*  f17bde0:	8dad1448 */ 	lw	$t5,0x1448($t5)
/*  f17bde4:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bde8:	3c01800a */ 	lui	$at,0x800a
/*  f17bdec:	000d78c0 */ 	sll	$t7,$t5,0x3
/*  f17bdf0:	01ed7823 */ 	subu	$t7,$t7,$t5
/*  f17bdf4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17bdf8:	01ed7821 */ 	addu	$t7,$t7,$t5
/*  f17bdfc:	8cec0000 */ 	lw	$t4,0x0($a3)
/*  f17be00:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17be04:	01ed7823 */ 	subu	$t7,$t7,$t5
/*  f17be08:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17be0c:	002f0821 */ 	addu	$at,$at,$t7
/*  f17be10:	01827023 */ 	subu	$t6,$t4,$v0
/*  f17be14:	ac2eee1c */ 	sw	$t6,-0x11e4($at)
.L0f17be18:
/*  f17be18:	00001025 */ 	or	$v0,$zero,$zero
.L0f17be1c:
/*  f17be1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17be20:
/*  f17be20:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f17be24:	03e00008 */ 	jr	$ra
/*  f17be28:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f17be2c
/*  f17be2c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17be30:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17be34:	3c02800a */ 	lui	$v0,0x800a
/*  f17be38:	3401ffff */ 	dli	$at,0xffff
/*  f17be3c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17be40:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17be44:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17be48:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17be4c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17be50:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17be54:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17be58:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f17be5c:	8c42ee1c */ 	lw	$v0,-0x11e4($v0)
/*  f17be60:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f17be64:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f17be68:	0041082b */ 	sltu	$at,$v0,$at
/*  f17be6c:	1020004e */ 	beqz	$at,.L0f17bfa8
/*  f17be70:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f17be74:	3c038007 */ 	lui	$v1,0x8007
/*  f17be78:	8c635bc4 */ 	lw	$v1,0x5bc4($v1)
/*  f17be7c:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f17be80:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f17be84:	10600048 */ 	beqz	$v1,.L0f17bfa8
/*  f17be88:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f17be8c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f17be90:	00782021 */ 	addu	$a0,$v1,$t8
/*  f17be94:	27b9003e */ 	addiu	$t9,$sp,0x3e
/*  f17be98:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f17be9c:	24840006 */ 	addiu	$a0,$a0,0x6
/*  f17bea0:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f17bea4:	27a60042 */ 	addiu	$a2,$sp,0x42
/*  f17bea8:	27a70040 */ 	addiu	$a3,$sp,0x40
/*  f17beac:	0fc638e7 */ 	jal	func0f18e39c
/*  f17beb0:	afa80038 */ 	sw	$t0,0x38($sp)
/*  f17beb4:	3c038008 */ 	lui	$v1,%hi(mpstages)
/*  f17beb8:	8fa80038 */ 	lw	$t0,0x38($sp)
/*  f17bebc:	24634b98 */ 	addiu	$v1,$v1,%lo(mpstages)
/*  f17bec0:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bec4:	97a40040 */ 	lhu	$a0,0x40($sp)
/*  f17bec8:	24050011 */ 	addiu	$a1,$zero,0x11
.L0f17becc:
/*  f17becc:	84690000 */ 	lh	$t1,0x0($v1)
/*  f17bed0:	54890003 */ 	bnel	$a0,$t1,.L0f17bee0
/*  f17bed4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f17bed8:	00404025 */ 	or	$t0,$v0,$zero
/*  f17bedc:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f17bee0:
/*  f17bee0:	1445fffa */ 	bne	$v0,$a1,.L0f17becc
/*  f17bee4:	24630006 */ 	addiu	$v1,$v1,0x6
/*  f17bee8:	97aa003e */ 	lhu	$t2,0x3e($sp)
/*  f17beec:	29410006 */ 	slti	$at,$t2,0x6
/*  f17bef0:	10200028 */ 	beqz	$at,.L0f17bf94
/*  f17bef4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17bef8:	11010026 */ 	beq	$t0,$at,.L0f17bf94
/*  f17befc:	97a20042 */ 	lhu	$v0,0x42($sp)
/*  f17bf00:	04400024 */ 	bltz	$v0,.L0f17bf94
/*  f17bf04:	93ab0044 */ 	lbu	$t3,0x44($sp)
/*  f17bf08:	11600022 */ 	beqz	$t3,.L0f17bf94
/*  f17bf0c:	28410009 */ 	slti	$at,$v0,0x9
/*  f17bf10:	10200020 */ 	beqz	$at,.L0f17bf94
/*  f17bf14:	2404508c */ 	addiu	$a0,$zero,0x508c
/*  f17bf18:	0fc5b9f1 */ 	jal	textGet
/*  f17bf1c:	afa80038 */ 	sw	$t0,0x38($sp)
/*  f17bf20:	97ac003e */ 	lhu	$t4,0x3e($sp)
/*  f17bf24:	3c048008 */ 	lui	$a0,0x8008
/*  f17bf28:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f17bf2c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f17bf30:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17bf34:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f17bf38:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f17bf3c:	0fc5b9f1 */ 	jal	textGet
/*  f17bf40:	94847148 */ 	lhu	$a0,0x7148($a0)
/*  f17bf44:	8fa80038 */ 	lw	$t0,0x38($sp)
/*  f17bf48:	3c048008 */ 	lui	$a0,0x8008
/*  f17bf4c:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f17bf50:	00087080 */ 	sll	$t6,$t0,0x2
/*  f17bf54:	01c87023 */ 	subu	$t6,$t6,$t0
/*  f17bf58:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f17bf5c:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f17bf60:	0fc5b9f1 */ 	jal	textGet
/*  f17bf64:	94844b9c */ 	lhu	$a0,0x4b9c($a0)
/*  f17bf68:	97af0042 */ 	lhu	$t7,0x42($sp)
/*  f17bf6c:	3c048007 */ 	lui	$a0,0x8007
/*  f17bf70:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17bf74:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f17bf78:	27a60044 */ 	addiu	$a2,$sp,0x44
/*  f17bf7c:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f17bf80:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f17bf84:	0c004dad */ 	jal	sprintf
/*  f17bf88:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f17bf8c:	10000004 */ 	beqz	$zero,.L0f17bfa0
/*  f17bf90:	3c028007 */ 	lui	$v0,0x8007
.L0f17bf94:
/*  f17bf94:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f17bf98:	10000005 */ 	beqz	$zero,.L0f17bfb0
/*  f17bf9c:	24428004 */ 	addiu	$v0,$v0,-32764
.L0f17bfa0:
/*  f17bfa0:	10000003 */ 	beqz	$zero,.L0f17bfb0
/*  f17bfa4:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f17bfa8:
/*  f17bfa8:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f17bfac:	24428008 */ 	addiu	$v0,$v0,-32760
.L0f17bfb0:
/*  f17bfb0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f17bfb4:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f17bfb8:	03e00008 */ 	jr	$ra
/*  f17bfbc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler0017bfc0
/*  f17bfc0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f17bfc4:	3c028007 */ 	lui	$v0,0x8007
/*  f17bfc8:	8c425bc0 */ 	lw	$v0,0x5bc0($v0)
/*  f17bfcc:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f17bfd0:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f17bfd4:	00802825 */ 	or	$a1,$a0,$zero
/*  f17bfd8:	00c09825 */ 	or	$s3,$a2,$zero
/*  f17bfdc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f17bfe0:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f17bfe4:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f17bfe8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f17bfec:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f17bff0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f17bff4:	14400003 */ 	bnez	$v0,.L0f17c004
/*  f17bff8:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f17bffc:	10000060 */ 	beqz	$zero,.L0f17c180
/*  f17c000:	00001025 */ 	or	$v0,$zero,$zero
.L0f17c004:
/*  f17c004:	24aeffff */ 	addiu	$t6,$a1,-1
/*  f17c008:	2dc10007 */ 	sltiu	$at,$t6,0x7
/*  f17c00c:	1020005b */ 	beqz	$at,.L0f17c17c
/*  f17c010:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17c014:	3c017f1c */ 	lui	$at,%hi(var7f1b8190)
/*  f17c018:	002e0821 */ 	addu	$at,$at,$t6
/*  f17c01c:	8c2e8190 */ 	lw	$t6,%lo(var7f1b8190)($at)
/*  f17c020:	01c00008 */ 	jr	$t6
/*  f17c024:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17c028:	844f02d0 */ 	lh	$t7,0x2d0($v0)
/*  f17c02c:	10000053 */ 	beqz	$zero,.L0f17c17c
/*  f17c030:	ae6f0000 */ 	sw	$t7,0x0($s3)
/*  f17c034:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f17c038:	3c108007 */ 	lui	$s0,%hi(var80071440)
/*  f17c03c:	26101440 */ 	addiu	$s0,$s0,%lo(var80071440)
/*  f17c040:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17c044:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17c048:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17c04c:	00592821 */ 	addu	$a1,$v0,$t9
/*  f17c050:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f17c054:	0fc42034 */ 	jal	func0f1080d0
/*  f17c058:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f17c05c:	10000048 */ 	beqz	$zero,.L0f17c180
/*  f17c060:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f17c064:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f17c068:	3c13800b */ 	lui	$s3,%hi(g_MpSetup)
/*  f17c06c:	3c11800b */ 	lui	$s1,%hi(g_MpPlayers)
/*  f17c070:	00084880 */ 	sll	$t1,$t0,0x2
/*  f17c074:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17c078:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f17c07c:	00499021 */ 	addu	$s2,$v0,$t1
/*  f17c080:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f17c084:	2631c7b8 */ 	addiu	$s1,$s1,%lo(g_MpPlayers)
/*  f17c088:	2673cb88 */ 	addiu	$s3,$s3,%lo(g_MpSetup)
/*  f17c08c:	00008025 */ 	or	$s0,$zero,$zero
/*  f17c090:	24140004 */ 	addiu	$s4,$zero,0x4
.L0f17c094:
/*  f17c094:	8e4a0000 */ 	lw	$t2,0x0($s2)
/*  f17c098:	8e2b004c */ 	lw	$t3,0x4c($s1)
/*  f17c09c:	554b0011 */ 	bnel	$t2,$t3,.L0f17c0e4
/*  f17c0a0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f17c0a4:	964c0004 */ 	lhu	$t4,0x4($s2)
/*  f17c0a8:	962d0050 */ 	lhu	$t5,0x50($s1)
/*  f17c0ac:	558d000d */ 	bnel	$t4,$t5,.L0f17c0e4
/*  f17c0b0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f17c0b4:	966e0016 */ 	lhu	$t6,0x16($s3)
/*  f17c0b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f17c0bc:	020fc004 */ 	sllv	$t8,$t7,$s0
/*  f17c0c0:	01d8c824 */ 	and	$t9,$t6,$t8
/*  f17c0c4:	17200005 */ 	bnez	$t9,.L0f17c0dc
/*  f17c0c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f17c0cc:	0fc62003 */ 	jal	func0f18800c
/*  f17c0d0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f17c0d4:	10000003 */ 	beqz	$zero,.L0f17c0e4
/*  f17c0d8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f17c0dc:
/*  f17c0dc:	0000a825 */ 	or	$s5,$zero,$zero
/*  f17c0e0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f17c0e4:
/*  f17c0e4:	1614ffeb */ 	bne	$s0,$s4,.L0f17c094
/*  f17c0e8:	263100a0 */ 	addiu	$s1,$s1,0xa0
/*  f17c0ec:	12a0000d */ 	beqz	$s5,.L0f17c124
/*  f17c0f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17c0f4:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f17c0f8:	afa80044 */ 	sw	$t0,0x44($sp)
/*  f17c0fc:	96490004 */ 	lhu	$t1,0x4($s2)
/*  f17c100:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f17c104:	a7a90048 */ 	sh	$t1,0x48($sp)
/*  f17c108:	3c068007 */ 	lui	$a2,0x8007
/*  f17c10c:	8cc61448 */ 	lw	$a2,0x1448($a2)
/*  f17c110:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f17c114:	0fc42539 */ 	jal	func0f1094e4
/*  f17c118:	24050065 */ 	addiu	$a1,$zero,0x65
/*  f17c11c:	10000018 */ 	beqz	$zero,.L0f17c180
/*  f17c120:	00001025 */ 	or	$v0,$zero,$zero
.L0f17c124:
/*  f17c124:	0fc42197 */ 	jal	func0f10865c
/*  f17c128:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f17c12c:	10000014 */ 	beqz	$zero,.L0f17c180
/*  f17c130:	00001025 */ 	or	$v0,$zero,$zero
/*  f17c134:	3c0a000f */ 	lui	$t2,0xf
/*  f17c138:	354affff */ 	ori	$t2,$t2,0xffff
/*  f17c13c:	1000000f */ 	beqz	$zero,.L0f17c17c
/*  f17c140:	ae6a0000 */ 	sw	$t2,0x0($s3)
/*  f17c144:	904b030a */ 	lbu	$t3,0x30a($v0)
/*  f17c148:	1000000c */ 	beqz	$zero,.L0f17c17c
/*  f17c14c:	ae6b0000 */ 	sw	$t3,0x0($s3)
/*  f17c150:	00002025 */ 	or	$a0,$zero,$zero
/*  f17c154:	0fc421ae */ 	jal	func0f1086b8
/*  f17c158:	8e660000 */ 	lw	$a2,0x0($s3)
/*  f17c15c:	10000009 */ 	beqz	$zero,.L0f17c184
/*  f17c160:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17c164:	00002025 */ 	or	$a0,$zero,$zero
/*  f17c168:	0fc421ae */ 	jal	func0f1086b8
/*  f17c16c:	8e660000 */ 	lw	$a2,0x0($s3)
/*  f17c170:	ae620008 */ 	sw	$v0,0x8($s3)
/*  f17c174:	10000002 */ 	beqz	$zero,.L0f17c180
/*  f17c178:	00001025 */ 	or	$v0,$zero,$zero
.L0f17c17c:
/*  f17c17c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17c180:
/*  f17c180:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f17c184:
/*  f17c184:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f17c188:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f17c18c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f17c190:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f17c194:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f17c198:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f17c19c:	03e00008 */ 	jr	$ra
/*  f17c1a0:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

s32 menuhandlerMpTimeLimitSlider(u32 operation, struct menu_item *item, struct numandtext *value)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		value->num = g_MpSetup.timelimit;
		break;
	case MENUOP_SET:
		g_MpSetup.timelimit = value->num;
		break;
	case MENUOP_GETSLIDERLABEL:
		if (value->num == 60) {
			sprintf(value->text, textGet(0x5070)); // "No Limit"
		} else {
			sprintf(value->text, textGet(0x5072), value->num + 1); // "%d Min"
		}
	}
	return 0;
}

s32 menuhandlerMpScoreLimitSlider(u32 operation, struct menu_item *item, struct numandtext *value)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		value->num = g_MpSetup.scorelimit;
		break;
	case MENUOP_SET:
		g_MpSetup.scorelimit = value->num;
		break;
	case MENUOP_GETSLIDERLABEL:
		if (value->num == 100) {
			sprintf(value->text, textGet(0x5070)); // "No Limit"
		} else {
			sprintf(value->text, textGet(0x5071), value->num + 1); // "%d"
		}
	}

	return 0;
}

s32 menuhandlerMpTeamScoreLimitSlider(u32 operation, struct menu_item *item, struct numandtext *value)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		value->num = func0f18844c();
		break;
	case MENUOP_SET:
		g_MpSetup.teamscorelimit = value->num;
		break;
	case MENUOP_GETSLIDERLABEL:
		if (value->num == 400) {
			sprintf(value->text, textGet(0x5070)); // "No Limit"
		} else {
			sprintf(value->text, textGet(0x5071), value->num + 1); // "%d"
		}
	}

	return 0;
}

s32 menuhandlerMpRestoreScoreDefaults(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f187fec();
	}

	return 0;
}

GLOBAL_ASM(
glabel menuhandlerMpHandicapPlayer
/*  f17c41c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f17c420:	24010006 */ 	addiu	$at,$zero,0x6
/*  f17c424:	1081001a */ 	beq	$a0,$at,.L0f17c490
/*  f17c428:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f17c42c:	24010009 */ 	addiu	$at,$zero,0x9
/*  f17c430:	1081000e */ 	beq	$a0,$at,.L0f17c46c
/*  f17c434:	2401000a */ 	addiu	$at,$zero,0xa
/*  f17c438:	1081001e */ 	beq	$a0,$at,.L0f17c4b4
/*  f17c43c:	24010018 */ 	addiu	$at,$zero,0x18
/*  f17c440:	14810033 */ 	bne	$a0,$at,.L0f17c510
/*  f17c444:	3c0e800b */ 	lui	$t6,0x800b
/*  f17c448:	90af0001 */ 	lbu	$t7,0x1($a1)
/*  f17c44c:	95cecb9e */ 	lhu	$t6,-0x3462($t6)
/*  f17c450:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f17c454:	01f8c804 */ 	sllv	$t9,$t8,$t7
/*  f17c458:	01d94024 */ 	and	$t0,$t6,$t9
/*  f17c45c:	5500002d */ 	bnezl	$t0,.L0f17c514
/*  f17c460:	00001025 */ 	or	$v0,$zero,$zero
/*  f17c464:	1000002b */ 	beqz	$zero,.L0f17c514
/*  f17c468:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f17c46c:
/*  f17c46c:	90a90001 */ 	lbu	$t1,0x1($a1)
/*  f17c470:	3c0b800b */ 	lui	$t3,0x800b
/*  f17c474:	00095080 */ 	sll	$t2,$t1,0x2
/*  f17c478:	01495021 */ 	addu	$t2,$t2,$t1
/*  f17c47c:	000a5140 */ 	sll	$t2,$t2,0x5
/*  f17c480:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f17c484:	916bc855 */ 	lbu	$t3,-0x37ab($t3)
/*  f17c488:	10000021 */ 	beqz	$zero,.L0f17c510
/*  f17c48c:	accb0000 */ 	sw	$t3,0x0($a2)
.L0f17c490:
/*  f17c490:	90ad0001 */ 	lbu	$t5,0x1($a1)
/*  f17c494:	94cc0002 */ 	lhu	$t4,0x2($a2)
/*  f17c498:	3c01800b */ 	lui	$at,0x800b
/*  f17c49c:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f17c4a0:	030dc021 */ 	addu	$t8,$t8,$t5
/*  f17c4a4:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f17c4a8:	00380821 */ 	addu	$at,$at,$t8
/*  f17c4ac:	10000018 */ 	beqz	$zero,.L0f17c510
/*  f17c4b0:	a02cc855 */ 	sb	$t4,-0x37ab($at)
.L0f17c4b4:
/*  f17c4b4:	90af0001 */ 	lbu	$t7,0x1($a1)
/*  f17c4b8:	3c04800b */ 	lui	$a0,0x800b
/*  f17c4bc:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f17c4c0:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f17c4c4:	01cf7021 */ 	addu	$t6,$t6,$t7
/*  f17c4c8:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f17c4cc:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f17c4d0:	0fc61ddc */ 	jal	func0f187770
/*  f17c4d4:	9084c855 */ 	lbu	$a0,-0x37ab($a0)
/*  f17c4d8:	3c0142c8 */ 	lui	$at,0x42c8
/*  f17c4dc:	44812000 */ 	mtc1	$at,$f4
/*  f17c4e0:	8fb90028 */ 	lw	$t9,0x28($sp)
/*  f17c4e4:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f17c4e8:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f17c4ec:	3c067f1c */ 	lui	$a2,0x7f1c
/*  f17c4f0:	3c077f1c */ 	lui	$a3,0x7f1c
/*  f17c4f4:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f17c4f8:	24e78020 */ 	addiu	$a3,$a3,-32736
/*  f17c4fc:	24c6801c */ 	addiu	$a2,$a2,-32740
/*  f17c500:	24a5800c */ 	addiu	$a1,$a1,-32756
/*  f17c504:	46003221 */ 	cvt.d.s	$f8,$f6
/*  f17c508:	0c004dad */ 	jal	sprintf
/*  f17c50c:	f7a80010 */ 	sdc1	$f8,0x10($sp)
.L0f17c510:
/*  f17c510:	00001025 */ 	or	$v0,$zero,$zero
.L0f17c514:
/*  f17c514:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f17c518:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f17c51c:	03e00008 */ 	jr	$ra
/*  f17c520:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f17c524
/*  f17c524:	90830001 */ 	lbu	$v1,0x1($a0)
/*  f17c528:	3c0e800b */ 	lui	$t6,0x800b
/*  f17c52c:	95cecb9e */ 	lhu	$t6,-0x3462($t6)
/*  f17c530:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f17c534:	006fc004 */ 	sllv	$t8,$t7,$v1
/*  f17c538:	01d8c824 */ 	and	$t9,$t6,$t8
/*  f17c53c:	13200008 */ 	beqz	$t9,.L0f17c560
/*  f17c540:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f17c544:	00034080 */ 	sll	$t0,$v1,0x2
/*  f17c548:	01034021 */ 	addu	$t0,$t0,$v1
/*  f17c54c:	3c09800b */ 	lui	$t1,%hi(g_MpPlayers)
/*  f17c550:	2529c7b8 */ 	addiu	$t1,$t1,%lo(g_MpPlayers)
/*  f17c554:	00084140 */ 	sll	$t0,$t0,0x5
/*  f17c558:	03e00008 */ 	jr	$ra
/*  f17c55c:	01091021 */ 	addu	$v0,$t0,$t1
.L0f17c560:
/*  f17c560:	24428024 */ 	addiu	$v0,$v0,-32732
/*  f17c564:	03e00008 */ 	jr	$ra
/*  f17c568:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMpRestoreHandicapDefaults(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		s32 i;

		for (i = 0; i < 4; i++) {
			g_MpPlayers[i].handicap = 0x80;
		}
	}

	return 0;
}

bool menudialogMpReady(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	if (operation == MENUOP_100) {
		if (g_MpPlayers[g_MpPlayerNum].unk4c && g_MpPlayers[g_MpPlayerNum].unk50) {
			func0f1094e4(&g_MpPlayers[g_MpPlayerNum].unk4c, 3, g_MpPlayerNum);
		}
	}

	return false;
}

bool menudialogMpSimulant(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	if (operation == MENUOP_102) {
		if ((u8)g_MpSimulants[g_MenuStack[g_MpPlayerNum].slotindex].base.name[0] == '\0') {
			menuPopDialog();
		}
	}

	return false;
}

GLOBAL_ASM(
glabel menuhandler0017c6a4
/*  f17c6a4:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f17c6a8:	3c0e8008 */ 	lui	$t6,%hi(var800857d0)
/*  f17c6ac:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f17c6b0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f17c6b4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f17c6b8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f17c6bc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f17c6c0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17c6c4:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f17c6c8:	25ce57d0 */ 	addiu	$t6,$t6,%lo(var800857d0)
/*  f17c6cc:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f17c6d0:	27b30040 */ 	addiu	$s3,$sp,0x40
/*  f17c6d4:	2488ffff */ 	addiu	$t0,$a0,-1
/*  f17c6d8:	ae610000 */ 	sw	$at,0x0($s3)
/*  f17c6dc:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f17c6e0:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f17c6e4:	00009025 */ 	or	$s2,$zero,$zero
/*  f17c6e8:	ae790004 */ 	sw	$t9,0x4($s3)
/*  f17c6ec:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f17c6f0:	ae610008 */ 	sw	$at,0x8($s3)
/*  f17c6f4:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f17c6f8:	2d010010 */ 	sltiu	$at,$t0,0x10
/*  f17c6fc:	102000c7 */ 	beqz	$at,.L0f17ca1c
/*  f17c700:	ae79000c */ 	sw	$t9,0xc($s3)
/*  f17c704:	00084080 */ 	sll	$t0,$t0,0x2
/*  f17c708:	3c017f1c */ 	lui	$at,%hi(var7f1b81ac)
/*  f17c70c:	00280821 */ 	addu	$at,$at,$t0
/*  f17c710:	8c2881ac */ 	lw	$t0,%lo(var7f1b81ac)($at)
/*  f17c714:	01000008 */ 	jr	$t0
/*  f17c718:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17c71c:	3c108008 */ 	lui	$s0,%hi(g_MpGeneralSimulants)
/*  f17c720:	3c118008 */ 	lui	$s1,%hi(g_MpBodies)
/*  f17c724:	263177bc */ 	addiu	$s1,$s1,%lo(g_MpBodies)
/*  f17c728:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpGeneralSimulants)
.L0f17c72c:
/*  f17c72c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f17c730:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17c734:	10400002 */ 	beqz	$v0,.L0f17c740
/*  f17c738:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17c73c:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f17c740:
/*  f17c740:	1611fffa */ 	bne	$s0,$s1,.L0f17c72c
/*  f17c744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17c748:	100000b4 */ 	beqz	$zero,.L0f17ca1c
/*  f17c74c:	ae920000 */ 	sw	$s2,0x0($s4)
/*  f17c750:	3c108008 */ 	lui	$s0,%hi(g_MpGeneralSimulants)
/*  f17c754:	3c118008 */ 	lui	$s1,%hi(g_MpBodies)
/*  f17c758:	263177bc */ 	addiu	$s1,$s1,%lo(g_MpBodies)
/*  f17c75c:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpGeneralSimulants)
.L0f17c760:
/*  f17c760:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f17c764:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17c768:	5040000a */ 	beqzl	$v0,.L0f17c794
/*  f17c76c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17c770:	8e890000 */ 	lw	$t1,0x0($s4)
/*  f17c774:	56490006 */ 	bnel	$s2,$t1,.L0f17c790
/*  f17c778:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17c77c:	0fc5b9f1 */ 	jal	textGet
/*  f17c780:	86040002 */ 	lh	$a0,0x2($s0)
/*  f17c784:	100000a7 */ 	beqz	$zero,.L0f17ca24
/*  f17c788:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17c78c:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f17c790:
/*  f17c790:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f17c794:
/*  f17c794:	1611fff2 */ 	bne	$s0,$s1,.L0f17c760
/*  f17c798:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17c79c:	100000a0 */ 	beqz	$zero,.L0f17ca20
/*  f17c7a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f17c7a4:	3c0a8007 */ 	lui	$t2,0x8007
/*  f17c7a8:	8d4a1448 */ 	lw	$t2,0x1448($t2)
/*  f17c7ac:	3c0c800a */ 	lui	$t4,0x800a
/*  f17c7b0:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f17c7b4:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f17c7b8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f17c7bc:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f17c7c0:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f17c7c4:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f17c7c8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f17c7cc:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f17c7d0:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f17c7d4:	8d8cee1c */ 	lw	$t4,-0x11e4($t4)
/*  f17c7d8:	3c18800b */ 	lui	$t8,0x800b
/*  f17c7dc:	05810007 */ 	bgez	$t4,.L0f17c7fc
/*  f17c7e0:	afac003c */ 	sw	$t4,0x3c($sp)
/*  f17c7e4:	0fc632ee */ 	jal	func0f18cbb8
/*  f17c7e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17c7ec:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f17c7f0:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f17c7f4:	1000000a */ 	beqz	$zero,.L0f17c820
/*  f17c7f8:	afad0038 */ 	sw	$t5,0x38($sp)
.L0f17c7fc:
/*  f17c7fc:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f17c800:	9718cb9e */ 	lhu	$t8,-0x3462($t8)
/*  f17c804:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f17c808:	25ee0004 */ 	addiu	$t6,$t7,0x4
/*  f17c80c:	01d94004 */ 	sllv	$t0,$t9,$t6
/*  f17c810:	03084824 */ 	and	$t1,$t8,$t0
/*  f17c814:	15200002 */ 	bnez	$t1,.L0f17c820
/*  f17c818:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f17c81c:	afaa0038 */ 	sw	$t2,0x38($sp)
.L0f17c820:
/*  f17c820:	3c108008 */ 	lui	$s0,%hi(g_MpGeneralSimulants)
/*  f17c824:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpGeneralSimulants)
/*  f17c828:	00008825 */ 	or	$s1,$zero,$zero
/*  f17c82c:	24130012 */ 	addiu	$s3,$zero,0x12
.L0f17c830:
/*  f17c830:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f17c834:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17c838:	50400005 */ 	beqzl	$v0,.L0f17c850
/*  f17c83c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17c840:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f17c844:	124b0004 */ 	beq	$s2,$t3,.L0f17c858
/*  f17c848:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17c84c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f17c850:
/*  f17c850:	1633fff7 */ 	bne	$s1,$s3,.L0f17c830
/*  f17c854:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f17c858:
/*  f17c858:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f17c85c:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f17c860:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f17c864:	11800006 */ 	beqz	$t4,.L0f17c880
/*  f17c868:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f17c86c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f17c870:	0fc63261 */ 	jal	func0f18c984
/*  f17c874:	322500ff */ 	andi	$a1,$s1,0xff
/*  f17c878:	1000000e */ 	beqz	$zero,.L0f17c8b4
/*  f17c87c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17c880:
/*  f17c880:	01ed7821 */ 	addu	$t7,$t7,$t5
/*  f17c884:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f17c888:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17c88c:	01ed7823 */ 	subu	$t7,$t7,$t5
/*  f17c890:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17c894:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f17c898:	01f91021 */ 	addu	$v0,$t7,$t9
/*  f17c89c:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f17c8a0:	17000004 */ 	bnez	$t8,.L0f17c8b4
/*  f17c8a4:	a04e0047 */ 	sb	$t6,0x47($v0)
/*  f17c8a8:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f17c8ac:	0fc632d8 */ 	jal	func0f18cb60
/*  f17c8b0:	92050001 */ 	lbu	$a1,0x1($s0)
.L0f17c8b4:
/*  f17c8b4:	0fc63377 */ 	jal	func0f18cddc
/*  f17c8b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17c8bc:	3c098007 */ 	lui	$t1,0x8007
/*  f17c8c0:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f17c8c4:	8e880000 */ 	lw	$t0,0x0($s4)
/*  f17c8c8:	3c01800a */ 	lui	$at,0x800a
/*  f17c8cc:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f17c8d0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f17c8d4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f17c8d8:	01495021 */ 	addu	$t2,$t2,$t1
/*  f17c8dc:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f17c8e0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f17c8e4:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f17c8e8:	002a0821 */ 	addu	$at,$at,$t2
/*  f17c8ec:	1000004b */ 	beqz	$zero,.L0f17ca1c
/*  f17c8f0:	ac28ee20 */ 	sw	$t0,-0x11e0($at)
/*  f17c8f4:	3c108008 */ 	lui	$s0,%hi(g_MpGeneralSimulants)
/*  f17c8f8:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpGeneralSimulants)
/*  f17c8fc:	00008825 */ 	or	$s1,$zero,$zero
/*  f17c900:	24130012 */ 	addiu	$s3,$zero,0x12
.L0f17c904:
/*  f17c904:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f17c908:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17c90c:	50400005 */ 	beqzl	$v0,.L0f17c924
/*  f17c910:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17c914:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f17c918:	124b0004 */ 	beq	$s2,$t3,.L0f17c92c
/*  f17c91c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17c920:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f17c924:
/*  f17c924:	1633fff7 */ 	bne	$s1,$s3,.L0f17c904
/*  f17c928:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f17c92c:
/*  f17c92c:	3c0c8007 */ 	lui	$t4,0x8007
/*  f17c930:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f17c934:	3c01800a */ 	lui	$at,0x800a
/*  f17c938:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f17c93c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17c940:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f17c944:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f17c948:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f17c94c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17c950:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f17c954:	002d0821 */ 	addu	$at,$at,$t5
/*  f17c958:	ac31ee24 */ 	sw	$s1,-0x11dc($at)
/*  f17c95c:	3c0f8007 */ 	lui	$t7,0x8007
/*  f17c960:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f17c964:	3c0e800a */ 	lui	$t6,0x800a
/*  f17c968:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f17c96c:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f17c970:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17c974:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f17c978:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17c97c:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f17c980:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17c984:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f17c988:	8dceee20 */ 	lw	$t6,-0x11e0($t6)
/*  f17c98c:	10000023 */ 	beqz	$zero,.L0f17ca1c
/*  f17c990:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f17c994:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f17c998:	10000020 */ 	beqz	$zero,.L0f17ca1c
/*  f17c99c:	ae980000 */ 	sw	$t8,0x0($s4)
/*  f17c9a0:	8e890000 */ 	lw	$t1,0x0($s4)
/*  f17c9a4:	000940c0 */ 	sll	$t0,$t1,0x3
/*  f17c9a8:	02685021 */ 	addu	$t2,$s3,$t0
/*  f17c9ac:	0fc5b9f1 */ 	jal	textGet
/*  f17c9b0:	95440004 */ 	lhu	$a0,0x4($t2)
/*  f17c9b4:	1000001b */ 	beqz	$zero,.L0f17ca24
/*  f17c9b8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17c9bc:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f17c9c0:	3c108008 */ 	lui	$s0,%hi(g_MpGeneralSimulants)
/*  f17c9c4:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpGeneralSimulants)
/*  f17c9c8:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f17c9cc:	026c6821 */ 	addu	$t5,$s3,$t4
/*  f17c9d0:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f17c9d4:	00008825 */ 	or	$s1,$zero,$zero
/*  f17c9d8:	59e00010 */ 	blezl	$t7,.L0f17ca1c
/*  f17c9dc:	ae920008 */ 	sw	$s2,0x8($s4)
.L0f17c9e0:
/*  f17c9e0:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f17c9e4:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17c9e8:	50400003 */ 	beqzl	$v0,.L0f17c9f8
/*  f17c9ec:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f17c9f0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17c9f4:	8e990000 */ 	lw	$t9,0x0($s4)
.L0f17c9f8:
/*  f17c9f8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17c9fc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17ca00:	001970c0 */ 	sll	$t6,$t9,0x3
/*  f17ca04:	026ec021 */ 	addu	$t8,$s3,$t6
/*  f17ca08:	8f090000 */ 	lw	$t1,0x0($t8)
/*  f17ca0c:	0229082a */ 	slt	$at,$s1,$t1
/*  f17ca10:	1420fff3 */ 	bnez	$at,.L0f17c9e0
/*  f17ca14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ca18:	ae920008 */ 	sw	$s2,0x8($s4)
.L0f17ca1c:
/*  f17ca1c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17ca20:
/*  f17ca20:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f17ca24:
/*  f17ca24:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f17ca28:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f17ca2c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f17ca30:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f17ca34:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f17ca38:	03e00008 */ 	jr	$ra
/*  f17ca3c:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func0f17ca40
/*  f17ca40:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17ca44:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17ca48:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17ca4c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17ca50:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17ca54:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17ca58:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17ca5c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17ca60:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17ca64:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17ca68:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17ca6c:	3c04800a */ 	lui	$a0,0x800a
/*  f17ca70:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f17ca74:	8c84ee24 */ 	lw	$a0,-0x11dc($a0)
/*  f17ca78:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17ca7c:	0fc5b9f1 */ 	jal	textGet
/*  f17ca80:	2484586a */ 	addiu	$a0,$a0,0x586a
/*  f17ca84:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17ca88:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17ca8c:	03e00008 */ 	jr	$ra
/*  f17ca90:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMpSimulantHead(u32 operation, struct menu_item *item, s32 *value)
{
	s32 start = 0;

	if (item->param2 == 1) {
		start = mpGetNumHeads();
	}

	/**
	 * Rare developers forgot to add a break statement to the first case,
	 * and when they noticed a problem their fix was to add an additional
	 * MENUOP_13 check in the next case.
	 */
	switch (operation) {
	case MENUOP_SET:
		g_MpSimulants[g_MenuStack[g_MpPlayerNum].slotindex].base.headnum = start + *value;
	case MENUOP_13:
		if (operation == MENUOP_13 && item->param2 == 1 && g_MpSimulants[g_MenuStack[g_MpPlayerNum].slotindex].base.headnum < start) {
			g_MpSimulants[g_MenuStack[g_MpPlayerNum].slotindex].base.headnum = start;
		}
		break;
	}

	return func0f17b4f8(operation, item, value, g_MpSimulants[g_MenuStack[g_MpPlayerNum].slotindex].base.headnum, 0);
}

s32 menuhandlerMpSimulantBody(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_MpSimulants[g_MenuStack[g_MpPlayerNum].slotindex].base.bodynum = *value;
	}

	return func0f179da4(operation, item, value,
			g_MpSimulants[g_MenuStack[g_MpPlayerNum].slotindex].base.bodynum,
			g_MpSimulants[g_MenuStack[g_MpPlayerNum].slotindex].base.headnum,
			0);
}

GLOBAL_ASM(
glabel menudialog0017ccfc
/*  f17ccfc:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f17cd00:	24010066 */ 	addiu	$at,$zero,0x66
/*  f17cd04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17cd08:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f17cd0c:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f17cd10:	1481001b */ 	bne	$a0,$at,.L0f17cd80
/*  f17cd14:	00a03825 */ 	or	$a3,$a1,$zero
/*  f17cd18:	3c0f8007 */ 	lui	$t7,0x8007
/*  f17cd1c:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f17cd20:	3c02800a */ 	lui	$v0,0x800a
/*  f17cd24:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f17cd28:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f17cd2c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f17cd30:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17cd34:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f17cd38:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f17cd3c:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f17cd40:	00581021 */ 	addu	$v0,$v0,$t8
/*  f17cd44:	8c42e4f8 */ 	lw	$v0,-0x1b08($v0)
/*  f17cd48:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f17cd4c:	54b9000d */ 	bnel	$a1,$t9,.L0f17cd84
/*  f17cd50:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f17cd54:	8ca30008 */ 	lw	$v1,0x8($a1)
/*  f17cd58:	8c440008 */ 	lw	$a0,0x8($v0)
/*  f17cd5c:	24650014 */ 	addiu	$a1,$v1,0x14
/*  f17cd60:	50640008 */ 	beql	$v1,$a0,.L0f17cd84
/*  f17cd64:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f17cd68:	10a40005 */ 	beq	$a1,$a0,.L0f17cd80
/*  f17cd6c:	27a60028 */ 	addiu	$a2,$sp,0x28
/*  f17cd70:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f17cd74:	0fc5e80a */ 	jal	menuhandlerMpCharacterBody
/*  f17cd78:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f17cd7c:	8fa7003c */ 	lw	$a3,0x3c($sp)
.L0f17cd80:
/*  f17cd80:	8fa40038 */ 	lw	$a0,0x38($sp)
.L0f17cd84:
/*  f17cd84:	00e02825 */ 	or	$a1,$a3,$zero
/*  f17cd88:	0fc5f186 */ 	jal	menudialogMpSimulant
/*  f17cd8c:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f17cd90:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17cd94:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f17cd98:	03e00008 */ 	jr	$ra
/*  f17cd9c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerMpSimulantDifficulty
/*  f17cda0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f17cda4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f17cda8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f17cdac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17cdb0:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f17cdb4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f17cdb8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f17cdbc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f17cdc0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17cdc4:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f17cdc8:	10810038 */ 	beq	$a0,$at,.L0f17ceac
/*  f17cdcc:	00009025 */ 	or	$s2,$zero,$zero
/*  f17cdd0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f17cdd4:	10810042 */ 	beq	$a0,$at,.L0f17cee0
/*  f17cdd8:	00008825 */ 	or	$s1,$zero,$zero
/*  f17cddc:	24130006 */ 	addiu	$s3,$zero,0x6
/*  f17cde0:	10930006 */ 	beq	$a0,$s3,.L0f17cdfc
/*  f17cde4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17cde8:	24010007 */ 	addiu	$at,$zero,0x7
/*  f17cdec:	10810014 */ 	beq	$a0,$at,.L0f17ce40
/*  f17cdf0:	3c188007 */ 	lui	$t8,0x8007
/*  f17cdf4:	10000050 */ 	beqz	$zero,.L0f17cf38
/*  f17cdf8:	00001025 */ 	or	$v0,$zero,$zero
.L0f17cdfc:
/*  f17cdfc:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17ce00:	3c04800a */ 	lui	$a0,0x800a
/*  f17ce04:	8e850000 */ 	lw	$a1,0x0($s4)
/*  f17ce08:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17ce0c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17ce10:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17ce14:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17ce18:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17ce1c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17ce20:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17ce24:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f17ce28:	0fc632d8 */ 	jal	func0f18cb60
/*  f17ce2c:	8c84ee1c */ 	lw	$a0,-0x11e4($a0)
/*  f17ce30:	0fc63377 */ 	jal	func0f18cddc
/*  f17ce34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ce38:	1000003f */ 	beqz	$zero,.L0f17cf38
/*  f17ce3c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17ce40:
/*  f17ce40:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f17ce44:	3c08800a */ 	lui	$t0,0x800a
/*  f17ce48:	3c02800b */ 	lui	$v0,0x800b
/*  f17ce4c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f17ce50:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17ce54:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17ce58:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f17ce5c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17ce60:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17ce64:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17ce68:	01194021 */ 	addu	$t0,$t0,$t9
/*  f17ce6c:	8d08ee1c */ 	lw	$t0,-0x11e4($t0)
/*  f17ce70:	00084880 */ 	sll	$t1,$t0,0x2
/*  f17ce74:	01284821 */ 	addu	$t1,$t1,$t0
/*  f17ce78:	00094880 */ 	sll	$t1,$t1,0x2
/*  f17ce7c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17ce80:	00094880 */ 	sll	$t1,$t1,0x2
/*  f17ce84:	00491021 */ 	addu	$v0,$v0,$t1
/*  f17ce88:	9042c580 */ 	lbu	$v0,-0x3a80($v0)
/*  f17ce8c:	04400005 */ 	bltz	$v0,.L0f17cea4
/*  f17ce90:	28410006 */ 	slti	$at,$v0,0x6
/*  f17ce94:	10200003 */ 	beqz	$at,.L0f17cea4
/*  f17ce98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ce9c:	10000025 */ 	beqz	$zero,.L0f17cf34
/*  f17cea0:	ae820000 */ 	sw	$v0,0x0($s4)
.L0f17cea4:
/*  f17cea4:	10000023 */ 	beqz	$zero,.L0f17cf34
/*  f17cea8:	ae800000 */ 	sw	$zero,0x0($s4)
.L0f17ceac:
/*  f17ceac:	3c108008 */ 	lui	$s0,%hi(g_MpGeneralSimulants)
/*  f17ceb0:	3c118008 */ 	lui	$s1,%hi(mpspecialsimulants)
/*  f17ceb4:	2631775c */ 	addiu	$s1,$s1,%lo(mpspecialsimulants)
/*  f17ceb8:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpGeneralSimulants)
.L0f17cebc:
/*  f17cebc:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f17cec0:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17cec4:	10400002 */ 	beqz	$v0,.L0f17ced0
/*  f17cec8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17cecc:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f17ced0:
/*  f17ced0:	1611fffa */ 	bne	$s0,$s1,.L0f17cebc
/*  f17ced4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ced8:	10000016 */ 	beqz	$zero,.L0f17cf34
/*  f17cedc:	ae920000 */ 	sw	$s2,0x0($s4)
.L0f17cee0:
/*  f17cee0:	3c108008 */ 	lui	$s0,%hi(g_MpGeneralSimulants)
/*  f17cee4:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpGeneralSimulants)
/*  f17cee8:	24130006 */ 	addiu	$s3,$zero,0x6
.L0f17ceec:
/*  f17ceec:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f17cef0:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17cef4:	5040000a */ 	beqzl	$v0,.L0f17cf20
/*  f17cef8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17cefc:	8e8a0000 */ 	lw	$t2,0x0($s4)
/*  f17cf00:	564a0006 */ 	bnel	$s2,$t2,.L0f17cf1c
/*  f17cf04:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17cf08:	0fc5b9f1 */ 	jal	textGet
/*  f17cf0c:	26245852 */ 	addiu	$a0,$s1,0x5852
/*  f17cf10:	1000000a */ 	beqz	$zero,.L0f17cf3c
/*  f17cf14:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17cf18:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f17cf1c:
/*  f17cf1c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f17cf20:
/*  f17cf20:	1633fff2 */ 	bne	$s1,$s3,.L0f17ceec
/*  f17cf24:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17cf28:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f17cf2c:	10000002 */ 	beqz	$zero,.L0f17cf38
/*  f17cf30:	24428028 */ 	addiu	$v0,$v0,-32728
.L0f17cf34:
/*  f17cf34:	00001025 */ 	or	$v0,$zero,$zero
.L0f17cf38:
/*  f17cf38:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f17cf3c:
/*  f17cf3c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f17cf40:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f17cf44:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f17cf48:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f17cf4c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f17cf50:	03e00008 */ 	jr	$ra
/*  f17cf54:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

s32 menuhandlerMpDeleteSimulant(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		mpRemoveSimulant(g_MenuStack[g_MpPlayerNum].slotindex);
		menuPopDialog();
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f17cfc0
/*  f17cfc0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17cfc4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17cfc8:	3c18800a */ 	lui	$t8,0x800a
/*  f17cfcc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17cfd0:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17cfd4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17cfd8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17cfdc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17cfe0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17cfe4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17cfe8:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17cfec:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17cff0:	8f18ee1c */ 	lw	$t8,-0x11e4($t8)
/*  f17cff4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17cff8:	3c08800b */ 	lui	$t0,%hi(g_MpSimulants)
/*  f17cffc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17d000:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f17d004:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17d008:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17d00c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17d010:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17d014:	2508c538 */ 	addiu	$t0,$t0,%lo(g_MpSimulants)
/*  f17d018:	3c048007 */ 	lui	$a0,0x8007
/*  f17d01c:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f17d020:	24a5802c */ 	addiu	$a1,$a1,-32724
/*  f17d024:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17d028:	0c004dad */ 	jal	sprintf
/*  f17d02c:	03283021 */ 	addu	$a2,$t9,$t0
/*  f17d030:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17d034:	3c028007 */ 	lui	$v0,0x8007
/*  f17d038:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17d03c:	03e00008 */ 	jr	$ra
/*  f17d040:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

s32 menuhandlerMpChangeSimulantType(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		s32 i;
		s32 count = 0;
		s32 maxunlocked = func0f18cd68(
				g_MpSimulants[g_MenuStack[g_MpPlayerNum].slotindex].base.simtype,
				g_MpSimulants[g_MenuStack[g_MpPlayerNum].slotindex].unk48);

		for (i = 0; i < maxunlocked; i++) {
			if (mpIsChallengeComplete(g_MpGeneralSimulants[i].unlockvalue)) {
				count++;
			}
		}

		g_MenuStack[g_MpPlayerNum].slotcount = count;

		menuPushDialog(&g_MpChangeSimulantMenuDialog);
	}

	return 0;
}

s32 menuhandlerMpClearAllSimulants(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		s32 i;
		for (i = 0; i < MAX_SIMULANTS; i++) {
			mpRemoveSimulant(i);
		}
	}

	return 0;
}

s32 menuhandlerMpAddSimulant(u32 operation, struct menu_item *item, s32 *value)
{
	switch (operation) {
	case MENUOP_SET:
		g_MenuStack[g_MpPlayerNum].slotindex = -1;
		menuPushDialog(&g_MpAddSimulantMenuDialog);
		break;
	case MENUOP_CHECKDISABLED:
		if (func0f18cc8c() == 0) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerMpSimulantSlot(u32 operation, struct menu_item *item, s32 *value)
{
	switch (operation) {
	case MENUOP_SET:
		g_MenuStack[g_MpPlayerNum].slotindex = item->param;

		if ((g_MpSetup.chrslots & (1 << (item->param + 4))) == 0) {
			menuPushDialog(&g_MpAddSimulantMenuDialog);
		} else if (var80090af0 == 1) {
			menuPushDialog(&menudialog_1b414);
		} else {
			menuPushDialog(&menudialog_mpeditsimulant);
		}
		break;
	case MENUOP_CHECKHIDDEN:
		if (item->param >= 4 && !mpIsChallengeComplete(CHALLENGE_UNK64)) {
			return true;
		}
		break;
	case MENUOP_CHECKDISABLED:
		if (!mpIsSimSlotEnabled(item->param)) {
			return true;
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f17d378
/*  f17d378:	90820001 */ 	lbu	$v0,0x1($a0)
/*  f17d37c:	3c0f800b */ 	lui	$t7,%hi(g_MpSimulants)
/*  f17d380:	25efc538 */ 	addiu	$t7,$t7,%lo(g_MpSimulants)
/*  f17d384:	00027080 */ 	sll	$t6,$v0,0x2
/*  f17d388:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f17d38c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17d390:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f17d394:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17d398:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f17d39c:	90780000 */ 	lbu	$t8,0x0($v1)
/*  f17d3a0:	24480004 */ 	addiu	$t0,$v0,0x4
/*  f17d3a4:	3c19800b */ 	lui	$t9,0x800b
/*  f17d3a8:	13000007 */ 	beqz	$t8,.L0f17d3c8
/*  f17d3ac:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f17d3b0:	9739cb9e */ 	lhu	$t9,-0x3462($t9)
/*  f17d3b4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f17d3b8:	01095004 */ 	sllv	$t2,$t1,$t0
/*  f17d3bc:	032a5824 */ 	and	$t3,$t9,$t2
/*  f17d3c0:	55600004 */ 	bnezl	$t3,.L0f17d3d4
/*  f17d3c4:	00601025 */ 	or	$v0,$v1,$zero
.L0f17d3c8:
/*  f17d3c8:	03e00008 */ 	jr	$ra
/*  f17d3cc:	24428030 */ 	addiu	$v0,$v0,-32720
/*  f17d3d0:	00601025 */ 	or	$v0,$v1,$zero
.L0f17d3d4:
/*  f17d3d4:	03e00008 */ 	jr	$ra
/*  f17d3d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d3dc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17d3e0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17d3e4:	90820001 */ 	lbu	$v0,0x1($a0)
/*  f17d3e8:	3c0f800b */ 	lui	$t7,0x800b
/*  f17d3ec:	3c18800b */ 	lui	$t8,0x800b
/*  f17d3f0:	00027080 */ 	sll	$t6,$v0,0x2
/*  f17d3f4:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f17d3f8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17d3fc:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f17d400:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17d404:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17d408:	91efc538 */ 	lbu	$t7,-0x3ac8($t7)
/*  f17d40c:	24590004 */ 	addiu	$t9,$v0,0x4
/*  f17d410:	11e00007 */ 	beqz	$t7,.L0f17d430
/*  f17d414:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d418:	9718cb9e */ 	lhu	$t8,-0x3462($t8)
/*  f17d41c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f17d420:	03284804 */ 	sllv	$t1,$t0,$t9
/*  f17d424:	03095024 */ 	and	$t2,$t8,$t1
/*  f17d428:	15400004 */ 	bnez	$t2,.L0f17d43c
/*  f17d42c:	3c048007 */ 	lui	$a0,0x8007
.L0f17d430:
/*  f17d430:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f17d434:	10000008 */ 	beqz	$zero,.L0f17d458
/*  f17d438:	24428034 */ 	addiu	$v0,$v0,-32716
.L0f17d43c:
/*  f17d43c:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f17d440:	24a58038 */ 	addiu	$a1,$a1,-32712
/*  f17d444:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17d448:	0c004dad */ 	jal	sprintf
/*  f17d44c:	24460001 */ 	addiu	$a2,$v0,0x1
/*  f17d450:	3c028007 */ 	lui	$v0,0x8007
/*  f17d454:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f17d458:
/*  f17d458:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17d45c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17d460:	03e00008 */ 	jr	$ra
/*  f17d464:	00000000 */ 	sll	$zero,$zero,0x0
);

bool menudialogMpSimulants(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	if (operation == MENUOP_100) {
		g_MenuStack[g_MpPlayerNum].slotcount = 0;
	}

	return false;
}

GLOBAL_ASM(
glabel func0f17d4b0
/*  f17d4b0:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f17d4b4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17d4b8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f17d4bc:	00e08025 */ 	or	$s0,$a3,$zero
/*  f17d4c0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f17d4c4:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f17d4c8:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f17d4cc:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f17d4d0:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f17d4d4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f17d4d8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f17d4dc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f17d4e0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f17d4e4:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f17d4e8:	14810090 */ 	bne	$a0,$at,.L0f17d72c
/*  f17d4ec:	afa60080 */ 	sw	$a2,0x80($sp)
/*  f17d4f0:	0fc6321f */ 	jal	func0f18c87c
/*  f17d4f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d4f8:	0050c821 */ 	addu	$t9,$v0,$s0
/*  f17d4fc:	2728ffff */ 	addiu	$t0,$t9,-1
/*  f17d500:	0110001a */ 	div	$zero,$t0,$s0
/*  f17d504:	3c0e8008 */ 	lui	$t6,%hi(var80085a74)
/*  f17d508:	25ce5a74 */ 	addiu	$t6,$t6,%lo(var80085a74)
/*  f17d50c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f17d510:	27b10064 */ 	addiu	$s1,$sp,0x64
/*  f17d514:	00009012 */ 	mflo	$s2
/*  f17d518:	ae210000 */ 	sw	$at,0x0($s1)
/*  f17d51c:	8dd80004 */ 	lw	$t8,0x4($t6)
/*  f17d520:	0040b825 */ 	or	$s7,$v0,$zero
/*  f17d524:	02009825 */ 	or	$s3,$s0,$zero
/*  f17d528:	ae380004 */ 	sw	$t8,0x4($s1)
/*  f17d52c:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f17d530:	0040a025 */ 	or	$s4,$v0,$zero
/*  f17d534:	ae210008 */ 	sw	$at,0x8($s1)
/*  f17d538:	8dd8000c */ 	lw	$t8,0xc($t6)
/*  f17d53c:	ae38000c */ 	sw	$t8,0xc($s1)
/*  f17d540:	16000002 */ 	bnez	$s0,.L0f17d54c
/*  f17d544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d548:	0007000d */ 	break	0x7
.L0f17d54c:
/*  f17d54c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17d550:	16010004 */ 	bne	$s0,$at,.L0f17d564
/*  f17d554:	3c018000 */ 	lui	$at,0x8000
/*  f17d558:	15010002 */ 	bne	$t0,$at,.L0f17d564
/*  f17d55c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d560:	0006000d */ 	break	0x6
.L0f17d564:
/*  f17d564:	0c004b70 */ 	jal	random
/*  f17d568:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d56c:	0057001b */ 	divu	$zero,$v0,$s7
/*  f17d570:	00001810 */ 	mfhi	$v1
/*  f17d574:	0060f025 */ 	or	$s8,$v1,$zero
/*  f17d578:	16e00002 */ 	bnez	$s7,.L0f17d584
/*  f17d57c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d580:	0007000d */ 	break	0x7
.L0f17d584:
/*  f17d584:	24690001 */ 	addiu	$t1,$v1,0x1
/*  f17d588:	16e00003 */ 	bnez	$s7,.L0f17d598
/*  f17d58c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d590:	10000067 */ 	beqz	$zero,.L0f17d730
/*  f17d594:	00001025 */ 	or	$v0,$zero,$zero
.L0f17d598:
/*  f17d598:	0137001a */ 	div	$zero,$t1,$s7
/*  f17d59c:	0000a810 */ 	mfhi	$s5
/*  f17d5a0:	16e00002 */ 	bnez	$s7,.L0f17d5ac
/*  f17d5a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d5a8:	0007000d */ 	break	0x7
.L0f17d5ac:
/*  f17d5ac:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17d5b0:	16e10004 */ 	bne	$s7,$at,.L0f17d5c4
/*  f17d5b4:	3c018000 */ 	lui	$at,0x8000
/*  f17d5b8:	15210002 */ 	bne	$t1,$at,.L0f17d5c4
/*  f17d5bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d5c0:	0006000d */ 	break	0x6
.L0f17d5c4:
/*  f17d5c4:	0fc631e5 */ 	jal	func0f18c794
/*  f17d5c8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f17d5cc:	0274082a */ 	slt	$at,$s3,$s4
/*  f17d5d0:	14200022 */ 	bnez	$at,.L0f17d65c
/*  f17d5d4:	0040b025 */ 	or	$s6,$v0,$zero
/*  f17d5d8:	0c004b70 */ 	jal	random
/*  f17d5dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d5e0:	0050001b */ 	divu	$zero,$v0,$s0
/*  f17d5e4:	00001810 */ 	mfhi	$v1
/*  f17d5e8:	16000002 */ 	bnez	$s0,.L0f17d5f4
/*  f17d5ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d5f0:	0007000d */ 	break	0x7
.L0f17d5f4:
/*  f17d5f4:	00035080 */ 	sll	$t2,$v1,0x2
.L0f17d5f8:
/*  f17d5f8:	022a1021 */ 	addu	$v0,$s1,$t2
/*  f17d5fc:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f17d600:	55600009 */ 	bnezl	$t3,.L0f17d628
/*  f17d604:	246f0001 */ 	addiu	$t7,$v1,0x1
/*  f17d608:	a2c30011 */ 	sb	$v1,0x11($s6)
/*  f17d60c:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f17d610:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f17d614:	2694ffff */ 	addiu	$s4,$s4,-1
/*  f17d618:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f17d61c:	10000032 */ 	beqz	$zero,.L0f17d6e8
/*  f17d620:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f17d624:	246f0001 */ 	addiu	$t7,$v1,0x1
.L0f17d628:
/*  f17d628:	01f0001a */ 	div	$zero,$t7,$s0
/*  f17d62c:	00001810 */ 	mfhi	$v1
/*  f17d630:	16000002 */ 	bnez	$s0,.L0f17d63c
/*  f17d634:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d638:	0007000d */ 	break	0x7
.L0f17d63c:
/*  f17d63c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17d640:	16010004 */ 	bne	$s0,$at,.L0f17d654
/*  f17d644:	3c018000 */ 	lui	$at,0x8000
/*  f17d648:	15e10002 */ 	bne	$t7,$at,.L0f17d654
/*  f17d64c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d650:	0006000d */ 	break	0x6
.L0f17d654:
/*  f17d654:	1000ffe8 */ 	beqz	$zero,.L0f17d5f8
/*  f17d658:	00035080 */ 	sll	$t2,$v1,0x2
.L0f17d65c:
/*  f17d65c:	0c004b70 */ 	jal	random
/*  f17d660:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d664:	0050001b */ 	divu	$zero,$v0,$s0
/*  f17d668:	00001810 */ 	mfhi	$v1
/*  f17d66c:	16000002 */ 	bnez	$s0,.L0f17d678
/*  f17d670:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d674:	0007000d */ 	break	0x7
.L0f17d678:
/*  f17d678:	00037080 */ 	sll	$t6,$v1,0x2
.L0f17d67c:
/*  f17d67c:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f17d680:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f17d684:	0312082a */ 	slt	$at,$t8,$s2
/*  f17d688:	5020000a */ 	beqzl	$at,.L0f17d6b4
/*  f17d68c:	24680001 */ 	addiu	$t0,$v1,0x1
/*  f17d690:	a2c30011 */ 	sb	$v1,0x11($s6)
/*  f17d694:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f17d698:	2694ffff */ 	addiu	$s4,$s4,-1
/*  f17d69c:	14800002 */ 	bnez	$a0,.L0f17d6a8
/*  f17d6a0:	24990001 */ 	addiu	$t9,$a0,0x1
/*  f17d6a4:	2673ffff */ 	addiu	$s3,$s3,-1
.L0f17d6a8:
/*  f17d6a8:	1000000f */ 	beqz	$zero,.L0f17d6e8
/*  f17d6ac:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f17d6b0:	24680001 */ 	addiu	$t0,$v1,0x1
.L0f17d6b4:
/*  f17d6b4:	0110001a */ 	div	$zero,$t0,$s0
/*  f17d6b8:	00001810 */ 	mfhi	$v1
/*  f17d6bc:	16000002 */ 	bnez	$s0,.L0f17d6c8
/*  f17d6c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d6c4:	0007000d */ 	break	0x7
.L0f17d6c8:
/*  f17d6c8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17d6cc:	16010004 */ 	bne	$s0,$at,.L0f17d6e0
/*  f17d6d0:	3c018000 */ 	lui	$at,0x8000
/*  f17d6d4:	15010002 */ 	bne	$t0,$at,.L0f17d6e0
/*  f17d6d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d6dc:	0006000d */ 	break	0x6
.L0f17d6e0:
/*  f17d6e0:	1000ffe6 */ 	beqz	$zero,.L0f17d67c
/*  f17d6e4:	00037080 */ 	sll	$t6,$v1,0x2
.L0f17d6e8:
/*  f17d6e8:	12be000e */ 	beq	$s5,$s8,.L0f17d724
/*  f17d6ec:	26a90001 */ 	addiu	$t1,$s5,0x1
/*  f17d6f0:	0137001a */ 	div	$zero,$t1,$s7
/*  f17d6f4:	0000a810 */ 	mfhi	$s5
/*  f17d6f8:	16e00002 */ 	bnez	$s7,.L0f17d704
/*  f17d6fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d700:	0007000d */ 	break	0x7
.L0f17d704:
/*  f17d704:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17d708:	16e10004 */ 	bne	$s7,$at,.L0f17d71c
/*  f17d70c:	3c018000 */ 	lui	$at,0x8000
/*  f17d710:	15210002 */ 	bne	$t1,$at,.L0f17d71c
/*  f17d714:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d718:	0006000d */ 	break	0x6
.L0f17d71c:
/*  f17d71c:	1000ffa9 */ 	beqz	$zero,.L0f17d5c4
/*  f17d720:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17d724:
/*  f17d724:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f17d728:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17d72c:
/*  f17d72c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17d730:
/*  f17d730:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f17d734:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f17d738:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f17d73c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f17d740:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f17d744:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f17d748:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f17d74c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f17d750:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f17d754:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f17d758:	03e00008 */ 	jr	$ra
/*  f17d75c:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

s32 menuhandlerMpTwoTeams(u32 operation, struct menu_item *item, s32 *value)
{
	return func0f17d4b0(operation, item, value, 2);
}

s32 menuhandlerMpThreeTeams(u32 operation, struct menu_item *item, s32 *value)
{
	return func0f17d4b0(operation, item, value, 3);
}

s32 menuhandlerMpFourTeams(u32 operation, struct menu_item *item, s32 *value)
{
	return func0f17d4b0(operation, item, value, 4);
}

s32 menuhandlerMpMaximumTeams(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		s32 i;
		u8 team = 0;

		for (i = 0; i != MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchr *mpchr;

				if (i < 4) {
					mpchr = &g_MpPlayers[i].base;
				} else {
					mpchr = &g_MpSimulants[i - 4].base;
				}

				mpchr->team = team++;

				if (team >= scenarioGetMaxTeams()) {
					team = 0;
				}
			}
		}

		menuPopDialog();
	}

	return 0;
}

s32 menuhandlerMpHumansVsSimulants(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		s32 i;

		for (i = 0; i != MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchr *mpchr;

				if (i < 4) {
					mpchr = &g_MpPlayers[i].base;
				} else {
					mpchr = &g_MpSimulants[i - 4].base;
				}

				mpchr->team = i < 4 ? 0 : 1;
			}
		}

		menuPopDialog();
	}

	return 0;
}

s32 menuhandlerMpHumanSimulantPairs(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		u8 team_ids[4] = g_TeamIdsForPairing; // literally {0, 1, 2, 3}
		s32 i;
		s32 playerindex = 0;
		s32 simindex = 0;

		for (i = 0; i != MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchr *mpchr;

				if (i < 4) {
					mpchr = &g_MpPlayers[i].base;
				} else {
					mpchr = &g_MpSimulants[i - 4].base;
				}

				if (i < 4) {
					mpchr->team = team_ids[playerindex++];
				} else {
					mpchr->team = team_ids[simindex++];

					if (simindex >= playerindex) {
						simindex = 0;
					}
				}
			}
		}

		menuPopDialog();
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f17da94
/*  f17da94:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17da98:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17da9c:	0fc631e5 */ 	jal	func0f18c794
/*  f17daa0:	90840001 */ 	lbu	$a0,0x1($a0)
/*  f17daa4:	10400003 */ 	beqz	$v0,.L0f17dab4
/*  f17daa8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17daac:	10000003 */ 	beqz	$zero,.L0f17dabc
/*  f17dab0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17dab4:
/*  f17dab4:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f17dab8:	24428040 */ 	addiu	$v0,$v0,-32704
.L0f17dabc:
/*  f17dabc:	03e00008 */ 	jr	$ra
/*  f17dac0:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f17dac4
/*  f17dac4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17dac8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17dacc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17dad0:	10810006 */ 	beq	$a0,$at,.L0f17daec
/*  f17dad4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f17dad8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f17dadc:	1081000a */ 	beq	$a0,$at,.L0f17db08
/*  f17dae0:	3c0e800b */ 	lui	$t6,0x800b
/*  f17dae4:	10000017 */ 	beqz	$zero,.L0f17db44
/*  f17dae8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17daec:
/*  f17daec:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17daf0:	0fc61902 */ 	jal	scenarioGetMaxTeams
/*  f17daf4:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f17daf8:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f17dafc:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f17db00:	10000010 */ 	beqz	$zero,.L0f17db44
/*  f17db04:	acc20000 */ 	sw	$v0,0x0($a2)
.L0f17db08:
/*  f17db08:	8dcecb94 */ 	lw	$t6,-0x346c($t6)
/*  f17db0c:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f17db10:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f17db14:	55e00004 */ 	bnezl	$t7,.L0f17db28
/*  f17db18:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f17db1c:	1000000b */ 	beqz	$zero,.L0f17db4c
/*  f17db20:	24428044 */ 	addiu	$v0,$v0,-32700
/*  f17db24:	8cd80000 */ 	lw	$t8,0x0($a2)
.L0f17db28:
/*  f17db28:	3c08800b */ 	lui	$t0,0x800b
/*  f17db2c:	2508cbb0 */ 	addiu	$t0,$t0,-13392
/*  f17db30:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17db34:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17db38:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17db3c:	10000003 */ 	beqz	$zero,.L0f17db4c
/*  f17db40:	03281021 */ 	addu	$v0,$t9,$t0
.L0f17db44:
/*  f17db44:	0fc5e431 */ 	jal	menuhandlerMpTeamsLabel
/*  f17db48:	8fa5001c */ 	lw	$a1,0x1c($sp)
.L0f17db4c:
/*  f17db4c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17db50:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17db54:	03e00008 */ 	jr	$ra
/*  f17db58:	00000000 */ 	sll	$zero,$zero,0x0
);

char *menuhandlerMpTeamSlot(u32 operation, struct menu_item *item, s32 *value)
{
	struct mpchr *mpchr;

	switch (operation) {
	case MENUOP_SET:
		mpchr = func0f18c794(item->param);
		mpchr->team = *value;
		break;
	case MENUOP_GETOPTIONVALUE:
		mpchr = func0f18c794(item->param);

		if (!mpchr) {
			*value = 0xff;
		} else {
			*value = mpchr->team;
		}

		break;
	case MENUOP_CHECKDISABLED:
		mpchr = func0f18c794(item->param);

		if (!mpchr) {
			return (char *)true;
		}

		return (char *)menuhandlerMpTeamsLabel(operation, item, value);
	}

	return func0f17dac4(operation, item, value);
}

GLOBAL_ASM(
glabel func0f17dc44
/*  f17dc44:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17dc48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17dc4c:	0fc630a9 */ 	jal	mpGetUsingMultipleTunes
/*  f17dc50:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17dc54:	10400005 */ 	beqz	$v0,.L0f17dc6c
/*  f17dc58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17dc5c:	0fc5b9f1 */ 	jal	textGet
/*  f17dc60:	24045045 */ 	addiu	$a0,$zero,0x5045
/*  f17dc64:	10000004 */ 	beqz	$zero,.L0f17dc78
/*  f17dc68:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17dc6c:
/*  f17dc6c:	0fc5b9f1 */ 	jal	textGet
/*  f17dc70:	24045044 */ 	addiu	$a0,$zero,0x5044
/*  f17dc74:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17dc78:
/*  f17dc78:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17dc7c:	03e00008 */ 	jr	$ra
/*  f17dc80:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler0017dc84
/*  f17dc84:	248effff */ 	addiu	$t6,$a0,-1
/*  f17dc88:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f17dc8c:	2dc10010 */ 	sltiu	$at,$t6,0x10
/*  f17dc90:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17dc94:	102000b2 */ 	beqz	$at,.L0f17df60
/*  f17dc98:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f17dc9c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17dca0:	3c017f1c */ 	lui	$at,%hi(var7f1b81ec)
/*  f17dca4:	002e0821 */ 	addu	$at,$at,$t6
/*  f17dca8:	8c2e81ec */ 	lw	$t6,%lo(var7f1b81ec)($at)
/*  f17dcac:	01c00008 */ 	jr	$t6
/*  f17dcb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17dcb4:	0fc63080 */ 	jal	func0f18c200
/*  f17dcb8:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17dcbc:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17dcc0:	0fc630a9 */ 	jal	mpGetUsingMultipleTunes
/*  f17dcc4:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f17dcc8:	10400005 */ 	beqz	$v0,.L0f17dce0
/*  f17dccc:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17dcd0:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f17dcd4:	25f80003 */ 	addiu	$t8,$t7,0x3
/*  f17dcd8:	100000a1 */ 	beqz	$zero,.L0f17df60
/*  f17dcdc:	acd80000 */ 	sw	$t8,0x0($a2)
.L0f17dce0:
/*  f17dce0:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f17dce4:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f17dce8:	1000009d */ 	beqz	$zero,.L0f17df60
/*  f17dcec:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f17dcf0:	0fc63080 */ 	jal	func0f18c200
/*  f17dcf4:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17dcf8:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17dcfc:	00402825 */ 	or	$a1,$v0,$zero
/*  f17dd00:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f17dd04:	0062082b */ 	sltu	$at,$v1,$v0
/*  f17dd08:	50200006 */ 	beqzl	$at,.L0f17dd24
/*  f17dd0c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f17dd10:	0fc63097 */ 	jal	mpGetTrackName
/*  f17dd14:	00602025 */ 	or	$a0,$v1,$zero
/*  f17dd18:	10000093 */ 	beqz	$zero,.L0f17df68
/*  f17dd1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17dd20:	afa5002c */ 	sw	$a1,0x2c($sp)
.L0f17dd24:
/*  f17dd24:	0fc630a9 */ 	jal	mpGetUsingMultipleTunes
/*  f17dd28:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17dd2c:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f17dd30:	1040000c */ 	beqz	$v0,.L0f17dd64
/*  f17dd34:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17dd38:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f17dd3c:	00055880 */ 	sll	$t3,$a1,0x2
/*  f17dd40:	000b6023 */ 	negu	$t4,$t3
/*  f17dd44:	00095080 */ 	sll	$t2,$t1,0x2
/*  f17dd48:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f17dd4c:	3c048008 */ 	lui	$a0,0x8008
/*  f17dd50:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f17dd54:	0fc5b9f1 */ 	jal	textGet
/*  f17dd58:	8c845cec */ 	lw	$a0,0x5cec($a0)
/*  f17dd5c:	10000082 */ 	beqz	$zero,.L0f17df68
/*  f17dd60:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17dd64:
/*  f17dd64:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f17dd68:	0005c080 */ 	sll	$t8,$a1,0x2
/*  f17dd6c:	0018c823 */ 	negu	$t9,$t8
/*  f17dd70:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17dd74:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f17dd78:	3c048008 */ 	lui	$a0,0x8008
/*  f17dd7c:	00882021 */ 	addu	$a0,$a0,$t0
/*  f17dd80:	0fc5b9f1 */ 	jal	textGet
/*  f17dd84:	8c845ce8 */ 	lw	$a0,0x5ce8($a0)
/*  f17dd88:	10000077 */ 	beqz	$zero,.L0f17df68
/*  f17dd8c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17dd90:	0fc63080 */ 	jal	func0f18c200
/*  f17dd94:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17dd98:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17dd9c:	00402025 */ 	or	$a0,$v0,$zero
/*  f17dda0:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f17dda4:	0062082b */ 	sltu	$at,$v1,$v0
/*  f17dda8:	5020000d */ 	beqzl	$at,.L0f17dde0
/*  f17ddac:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f17ddb0:	8cc90004 */ 	lw	$t1,0x4($a2)
/*  f17ddb4:	15200003 */ 	bnez	$t1,.L0f17ddc4
/*  f17ddb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ddbc:	0fc630e3 */ 	jal	func0f18c38c
/*  f17ddc0:	00602025 */ 	or	$a0,$v1,$zero
.L0f17ddc4:
/*  f17ddc4:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f17ddc8:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f17ddcc:	8c4b0458 */ 	lw	$t3,0x458($v0)
/*  f17ddd0:	356a0002 */ 	ori	$t2,$t3,0x2
/*  f17ddd4:	10000062 */ 	beqz	$zero,.L0f17df60
/*  f17ddd8:	ac4a0458 */ 	sw	$t2,0x458($v0)
/*  f17dddc:	afa40028 */ 	sw	$a0,0x28($sp)
.L0f17dde0:
/*  f17dde0:	0fc630a9 */ 	jal	mpGetUsingMultipleTunes
/*  f17dde4:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17dde8:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f17ddec:	10400024 */ 	beqz	$v0,.L0f17de80
/*  f17ddf0:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17ddf4:	8ccc0000 */ 	lw	$t4,0x0($a2)
/*  f17ddf8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17ddfc:	01841023 */ 	subu	$v0,$t4,$a0
/*  f17de00:	10400007 */ 	beqz	$v0,.L0f17de20
/*  f17de04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17de08:	1041000d */ 	beq	$v0,$at,.L0f17de40
/*  f17de0c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f17de10:	10410013 */ 	beq	$v0,$at,.L0f17de60
/*  f17de14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17de18:	10000052 */ 	beqz	$zero,.L0f17df64
/*  f17de1c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17de20:
/*  f17de20:	0fc630f9 */ 	jal	func0f18c3e4
/*  f17de24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17de28:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f17de2c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f17de30:	8c4d0458 */ 	lw	$t5,0x458($v0)
/*  f17de34:	35ae0002 */ 	ori	$t6,$t5,0x2
/*  f17de38:	10000049 */ 	beqz	$zero,.L0f17df60
/*  f17de3c:	ac4e0458 */ 	sw	$t6,0x458($v0)
.L0f17de40:
/*  f17de40:	0fc63103 */ 	jal	func0f18c40c
/*  f17de44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17de48:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f17de4c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f17de50:	8c580458 */ 	lw	$t8,0x458($v0)
/*  f17de54:	370f0002 */ 	ori	$t7,$t8,0x2
/*  f17de58:	10000041 */ 	beqz	$zero,.L0f17df60
/*  f17de5c:	ac4f0458 */ 	sw	$t7,0x458($v0)
.L0f17de60:
/*  f17de60:	0fc6310c */ 	jal	func0f18c430
/*  f17de64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17de68:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f17de6c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f17de70:	8c590458 */ 	lw	$t9,0x458($v0)
/*  f17de74:	37280002 */ 	ori	$t0,$t9,0x2
/*  f17de78:	10000039 */ 	beqz	$zero,.L0f17df60
/*  f17de7c:	ac480458 */ 	sw	$t0,0x458($v0)
.L0f17de80:
/*  f17de80:	0fc6311e */ 	jal	func0f18c478
/*  f17de84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17de88:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f17de8c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f17de90:	8c490458 */ 	lw	$t1,0x458($v0)
/*  f17de94:	352b0002 */ 	ori	$t3,$t1,0x2
/*  f17de98:	10000031 */ 	beqz	$zero,.L0f17df60
/*  f17de9c:	ac4b0458 */ 	sw	$t3,0x458($v0)
/*  f17dea0:	0fc630a9 */ 	jal	mpGetUsingMultipleTunes
/*  f17dea4:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17dea8:	10400005 */ 	beqz	$v0,.L0f17dec0
/*  f17deac:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17deb0:	3c0a000f */ 	lui	$t2,0xf
/*  f17deb4:	354affff */ 	ori	$t2,$t2,0xffff
/*  f17deb8:	10000029 */ 	beqz	$zero,.L0f17df60
/*  f17debc:	acca0000 */ 	sw	$t2,0x0($a2)
.L0f17dec0:
/*  f17dec0:	0fc63122 */ 	jal	func0f18c488
/*  f17dec4:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17dec8:	04410006 */ 	bgez	$v0,.L0f17dee4
/*  f17decc:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17ded0:	0fc63080 */ 	jal	func0f18c200
/*  f17ded4:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17ded8:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17dedc:	10000020 */ 	beqz	$zero,.L0f17df60
/*  f17dee0:	acc20000 */ 	sw	$v0,0x0($a2)
.L0f17dee4:
/*  f17dee4:	1000001e */ 	beqz	$zero,.L0f17df60
/*  f17dee8:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f17deec:	0fc63080 */ 	jal	func0f18c200
/*  f17def0:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17def4:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17def8:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f17defc:	0062082b */ 	sltu	$at,$v1,$v0
/*  f17df00:	50200018 */ 	beqzl	$at,.L0f17df64
/*  f17df04:	00001025 */ 	or	$v0,$zero,$zero
/*  f17df08:	0fc63088 */ 	jal	mpGetTrackAudioId
/*  f17df0c:	00602025 */ 	or	$a0,$v1,$zero
/*  f17df10:	0fc5b647 */ 	jal	func0f16d91c
/*  f17df14:	00402025 */ 	or	$a0,$v0,$zero
/*  f17df18:	10000012 */ 	beqz	$zero,.L0f17df64
/*  f17df1c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17df20:	0fc63080 */ 	jal	func0f18c200
/*  f17df24:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17df28:	0fc630a9 */ 	jal	mpGetUsingMultipleTunes
/*  f17df2c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f17df30:	1040000b */ 	beqz	$v0,.L0f17df60
/*  f17df34:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17df38:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f17df3c:	8fac001c */ 	lw	$t4,0x1c($sp)
/*  f17df40:	00602025 */ 	or	$a0,$v1,$zero
/*  f17df44:	006c082b */ 	sltu	$at,$v1,$t4
/*  f17df48:	50200006 */ 	beqzl	$at,.L0f17df64
/*  f17df4c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17df50:	0fc630ac */ 	jal	func0f18c2b0
/*  f17df54:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17df58:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17df5c:	acc20004 */ 	sw	$v0,0x4($a2)
.L0f17df60:
/*  f17df60:	00001025 */ 	or	$v0,$zero,$zero
.L0f17df64:
/*  f17df64:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17df68:
/*  f17df68:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f17df6c:	03e00008 */ 	jr	$ra
/*  f17df70:	00000000 */ 	sll	$zero,$zero,0x0
);

bool menudialogMpSelectTune(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	if (operation == MENUOP_100) {
		var800840e0 = 80;
	}

	if (operation == MENUOP_101) {
		var800840e0 = 15;
	}

	return false;
}

GLOBAL_ASM(
glabel func0f17dfac
/*  f17dfac:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17dfb0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17dfb4:	0fc630a9 */ 	jal	mpGetUsingMultipleTunes
/*  f17dfb8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17dfbc:	10400005 */ 	beqz	$v0,.L0f17dfd4
/*  f17dfc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17dfc4:	0fc5b9f1 */ 	jal	textGet
/*  f17dfc8:	24045042 */ 	addiu	$a0,$zero,0x5042
/*  f17dfcc:	1000000c */ 	beqz	$zero,.L0f17e000
/*  f17dfd0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17dfd4:
/*  f17dfd4:	0fc63122 */ 	jal	func0f18c488
/*  f17dfd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17dfdc:	04400005 */ 	bltz	$v0,.L0f17dff4
/*  f17dfe0:	00402025 */ 	or	$a0,$v0,$zero
/*  f17dfe4:	0fc63097 */ 	jal	mpGetTrackName
/*  f17dfe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17dfec:	10000004 */ 	beqz	$zero,.L0f17e000
/*  f17dff0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17dff4:
/*  f17dff4:	0fc5b9f1 */ 	jal	textGet
/*  f17dff8:	24045043 */ 	addiu	$a0,$zero,0x5043
/*  f17dffc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17e000:
/*  f17e000:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17e004:	03e00008 */ 	jr	$ra
/*  f17e008:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMpMultipleTunes(u32 operation, struct menu_item *item, s32 *value)
{
	switch (operation) {
	case MENUOP_GET:
		return mpGetUsingMultipleTunes();
	case MENUOP_SET:
		mpSetUsingMultipleTunes(*value);
		g_Vars.unk000458 |= 2;
	}

	return 0;
}

GLOBAL_ASM(
glabel menuhandler0017e06c
/*  f17e06c:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f17e070:	24010011 */ 	addiu	$at,$zero,0x11
/*  f17e074:	10810006 */ 	beq	$a0,$at,.L0f17e090
/*  f17e078:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f17e07c:	24010012 */ 	addiu	$at,$zero,0x12
/*  f17e080:	1081003f */ 	beq	$a0,$at,.L0f17e180
/*  f17e084:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f17e088:	03e00008 */ 	jr	$ra
/*  f17e08c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e090:
/*  f17e090:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f17e094:	25291448 */ 	addiu	$t1,$t1,%lo(g_MpPlayerNum)
/*  f17e098:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f17e09c:	240a0e70 */ 	addiu	$t2,$zero,0xe70
/*  f17e0a0:	3c08800a */ 	lui	$t0,%hi(var8009e000)
/*  f17e0a4:	01ca0019 */ 	multu	$t6,$t2
/*  f17e0a8:	2508e000 */ 	addiu	$t0,$t0,%lo(var8009e000)
/*  f17e0ac:	3c07800b */ 	lui	$a3,0x800b
/*  f17e0b0:	24e7cbb0 */ 	addiu	$a3,$a3,-13392
/*  f17e0b4:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f17e0b8:	00001825 */ 	or	$v1,$zero,$zero
/*  f17e0bc:	00007812 */ 	mflo	$t7
/*  f17e0c0:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f17e0c4:	8f040e1c */ 	lw	$a0,0xe1c($t8)
/*  f17e0c8:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f17e0cc:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f17e0d0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17e0d4:	00f96821 */ 	addu	$t5,$a3,$t9
/*  f17e0d8:	91ae0000 */ 	lbu	$t6,0x0($t5)
/*  f17e0dc:	00047880 */ 	sll	$t7,$a0,0x2
/*  f17e0e0:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f17e0e4:	116e001c */ 	beq	$t3,$t6,.L0f17e158
/*  f17e0e8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17e0ec:	00ef2821 */ 	addu	$a1,$a3,$t7
/*  f17e0f0:	90b80000 */ 	lbu	$t8,0x0($a1)
/*  f17e0f4:	00403021 */ 	addu	$a2,$v0,$zero
/*  f17e0f8:	240c000b */ 	addiu	$t4,$zero,0xb
/*  f17e0fc:	53000017 */ 	beqzl	$t8,.L0f17e15c
/*  f17e100:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e104:	90a40000 */ 	lbu	$a0,0x0($a1)
/*  f17e108:	a0c40000 */ 	sb	$a0,0x0($a2)
.L0f17e10c:
/*  f17e10c:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f17e110:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17e114:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17e118:	01aa0019 */ 	multu	$t5,$t2
/*  f17e11c:	00007012 */ 	mflo	$t6
/*  f17e120:	010e7821 */ 	addu	$t7,$t0,$t6
/*  f17e124:	8df80e1c */ 	lw	$t8,0xe1c($t7)
/*  f17e128:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17e12c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17e130:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17e134:	00f96821 */ 	addu	$t5,$a3,$t9
/*  f17e138:	01a37021 */ 	addu	$t6,$t5,$v1
/*  f17e13c:	91c40000 */ 	lbu	$a0,0x0($t6)
/*  f17e140:	51640006 */ 	beql	$t3,$a0,.L0f17e15c
/*  f17e144:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e148:	50800004 */ 	beqzl	$a0,.L0f17e15c
/*  f17e14c:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e150:	546cffee */ 	bnel	$v1,$t4,.L0f17e10c
/*  f17e154:	a0c40000 */ 	sb	$a0,0x0($a2)
.L0f17e158:
/*  f17e158:	2861000b */ 	slti	$at,$v1,0xb
.L0f17e15c:
/*  f17e15c:	10200048 */ 	beqz	$at,.L0f17e280
/*  f17e160:	00433021 */ 	addu	$a2,$v0,$v1
.L0f17e164:
/*  f17e164:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17e168:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e16c:	a0c00000 */ 	sb	$zero,0x0($a2)
/*  f17e170:	1420fffc */ 	bnez	$at,.L0f17e164
/*  f17e174:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17e178:	03e00008 */ 	jr	$ra
/*  f17e17c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e180:
/*  f17e180:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f17e184:	00001825 */ 	or	$v1,$zero,$zero
/*  f17e188:	3c188007 */ 	lui	$t8,0x8007
/*  f17e18c:	11e0001d */ 	beqz	$t7,.L0f17e204
/*  f17e190:	25291448 */ 	addiu	$t1,$t1,%lo(g_MpPlayerNum)
/*  f17e194:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f17e198:	3c0d800a */ 	lui	$t5,0x800a
/*  f17e19c:	00403021 */ 	addu	$a2,$v0,$zero
/*  f17e1a0:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f17e1a4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17e1a8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17e1ac:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f17e1b0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17e1b4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17e1b8:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17e1bc:	01b96821 */ 	addu	$t5,$t5,$t9
/*  f17e1c0:	8dadee1c */ 	lw	$t5,-0x11e4($t5)
/*  f17e1c4:	3c18800b */ 	lui	$t8,0x800b
/*  f17e1c8:	2718cbb0 */ 	addiu	$t8,$t8,-13392
/*  f17e1cc:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f17e1d0:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f17e1d4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17e1d8:	01d82021 */ 	addu	$a0,$t6,$t8
/*  f17e1dc:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f17e1e0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f17e1e4:
/*  f17e1e4:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e1e8:	a0850000 */ 	sb	$a1,0x0($a0)
/*  f17e1ec:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f17e1f0:	10200004 */ 	beqz	$at,.L0f17e204
/*  f17e1f4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17e1f8:	90c50000 */ 	lbu	$a1,0x0($a2)
/*  f17e1fc:	54a0fff9 */ 	bnezl	$a1,.L0f17e1e4
/*  f17e200:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f17e204:
/*  f17e204:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f17e208:	240a0e70 */ 	addiu	$t2,$zero,0xe70
/*  f17e20c:	3c08800a */ 	lui	$t0,%hi(var8009e000)
/*  f17e210:	032a0019 */ 	multu	$t9,$t2
/*  f17e214:	2508e000 */ 	addiu	$t0,$t0,%lo(var8009e000)
/*  f17e218:	3c07800b */ 	lui	$a3,0x800b
/*  f17e21c:	24e7cbb0 */ 	addiu	$a3,$a3,-13392
/*  f17e220:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f17e224:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f17e228:	00006812 */ 	mflo	$t5
/*  f17e22c:	010d7021 */ 	addu	$t6,$t0,$t5
/*  f17e230:	8dcf0e1c */ 	lw	$t7,0xe1c($t6)
/*  f17e234:	240d000a */ 	addiu	$t5,$zero,0xa
/*  f17e238:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f17e23c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f17e240:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f17e244:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f17e248:	03232021 */ 	addu	$a0,$t9,$v1
/*  f17e24c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17e250:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e254:	a08d0000 */ 	sb	$t5,0x0($a0)
/*  f17e258:	10200006 */ 	beqz	$at,.L0f17e274
/*  f17e25c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f17e260:
/*  f17e260:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17e264:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e268:	a0800000 */ 	sb	$zero,0x0($a0)
/*  f17e26c:	1420fffc */ 	bnez	$at,.L0f17e260
/*  f17e270:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f17e274:
/*  f17e274:	8c4e0458 */ 	lw	$t6,0x458($v0)
/*  f17e278:	35cf0002 */ 	ori	$t7,$t6,0x2
/*  f17e27c:	ac4f0458 */ 	sw	$t7,0x458($v0)
.L0f17e280:
/*  f17e280:	03e00008 */ 	jr	$ra
/*  f17e284:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0f17e288
/*  f17e288:	8c830008 */ 	lw	$v1,0x8($a0)
/*  f17e28c:	3c0f800b */ 	lui	$t7,0x800b
/*  f17e290:	25efcbb0 */ 	addiu	$t7,$t7,-13392
/*  f17e294:	2463a9f8 */ 	addiu	$v1,$v1,-22024
/*  f17e298:	00037080 */ 	sll	$t6,$v1,0x2
/*  f17e29c:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f17e2a0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17e2a4:	03e00008 */ 	jr	$ra
/*  f17e2a8:	01cf1021 */ 	addu	$v0,$t6,$t7
);

s32 menuhandlerMpTeamNameSlot(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_MenuStack[g_MpPlayerNum].slotindex = item->param2 - 0x5608;
		menuPushDialog(&g_MpChangeTeamNameMenuDialog);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f17e318
/*  f17e318:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f17e31c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17e320:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f17e324:	0fc5b9f1 */ 	jal	textGet
/*  f17e328:	24045038 */ 	addiu	$a0,$zero,0x5038
/*  f17e32c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17e330:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17e334:	3c04800a */ 	lui	$a0,0x800a
/*  f17e338:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f17e33c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17e340:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17e344:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17e348:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17e34c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17e350:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17e354:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17e358:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f17e35c:	0fc66dbe */ 	jal	func0f19b6f8
/*  f17e360:	8c84ee1c */ 	lw	$a0,-0x11e4($a0)
/*  f17e364:	3c048007 */ 	lui	$a0,0x8007
/*  f17e368:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17e36c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f17e370:	0c004dad */ 	jal	sprintf
/*  f17e374:	00403025 */ 	or	$a2,$v0,$zero
/*  f17e378:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17e37c:	3c028007 */ 	lui	$v0,0x8007
/*  f17e380:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17e384:	03e00008 */ 	jr	$ra
/*  f17e388:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

/**
 * An "Accept" item somewhere. Probably accepting a challenge.
 */
s32 menuhandler0017e38c(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		mpResetVar800884b4();
		menuPopDialog();
		mpSetCurrentChallenge(g_MenuStack[g_MpPlayerNum].slotindex);
	}

	return 0;
}

GLOBAL_ASM(
glabel menudialog0017e3fc
/*  f17e3fc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17e400:	24010064 */ 	addiu	$at,$zero,0x64
/*  f17e404:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17e408:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f17e40c:	10810008 */ 	beq	$a0,$at,.L0f17e430
/*  f17e410:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f17e414:	24010065 */ 	addiu	$at,$zero,0x65
/*  f17e418:	10810029 */ 	beq	$a0,$at,.L0f17e4c0
/*  f17e41c:	24010066 */ 	addiu	$at,$zero,0x66
/*  f17e420:	10810021 */ 	beq	$a0,$at,.L0f17e4a8
/*  f17e424:	3c09800b */ 	lui	$t1,0x800b
/*  f17e428:	10000026 */ 	beqz	$zero,.L0f17e4c4
/*  f17e42c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17e430:
/*  f17e430:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17e434:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17e438:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f17e43c:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f17e440:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17e444:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17e448:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17e44c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17e450:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17e454:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17e458:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17e45c:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f17e460:	ac400850 */ 	sw	$zero,0x850($v0)
/*  f17e464:	8c440e1c */ 	lw	$a0,0xe1c($v0)
/*  f17e468:	8c450844 */ 	lw	$a1,0x844($v0)
/*  f17e46c:	0fc66ea5 */ 	jal	mpGetNthAvailableChallengeSomething
/*  f17e470:	8c460848 */ 	lw	$a2,0x848($v0)
/*  f17e474:	3c198007 */ 	lui	$t9,0x8007
/*  f17e478:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f17e47c:	3c01800a */ 	lui	$at,0x800a
/*  f17e480:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f17e484:	01194023 */ 	subu	$t0,$t0,$t9
/*  f17e488:	00084080 */ 	sll	$t0,$t0,0x2
/*  f17e48c:	01194021 */ 	addu	$t0,$t0,$t9
/*  f17e490:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f17e494:	01194023 */ 	subu	$t0,$t0,$t9
/*  f17e498:	00084100 */ 	sll	$t0,$t0,0x4
/*  f17e49c:	00280821 */ 	addu	$at,$at,$t0
/*  f17e4a0:	10000007 */ 	beqz	$zero,.L0f17e4c0
/*  f17e4a4:	ac22ee20 */ 	sw	$v0,-0x11e0($at)
.L0f17e4a8:
/*  f17e4a8:	9129cc10 */ 	lbu	$t1,-0x33f0($t1)
/*  f17e4ac:	24010005 */ 	addiu	$at,$zero,0x5
/*  f17e4b0:	55210004 */ 	bnel	$t1,$at,.L0f17e4c4
/*  f17e4b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17e4b8:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f17e4bc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17e4c0:
/*  f17e4c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17e4c4:
/*  f17e4c4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17e4c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e4cc:	03e00008 */ 	jr	$ra
/*  f17e4d0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler0017e4d4
/*  f17e4d4:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f17e4d8:	248effff */ 	addiu	$t6,$a0,-1
/*  f17e4dc:	afb6004c */ 	sw	$s6,0x4c($sp)
/*  f17e4e0:	2dc10018 */ 	sltiu	$at,$t6,0x18
/*  f17e4e4:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f17e4e8:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f17e4ec:	afb70050 */ 	sw	$s7,0x50($sp)
/*  f17e4f0:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f17e4f4:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f17e4f8:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f17e4fc:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f17e500:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f17e504:	10200128 */ 	beqz	$at,.L0f17e9a8
/*  f17e508:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f17e50c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17e510:	3c017f1c */ 	lui	$at,%hi(var7f1b822c)
/*  f17e514:	002e0821 */ 	addu	$at,$at,$t6
/*  f17e518:	8c2e822c */ 	lw	$t6,%lo(var7f1b822c)($at)
/*  f17e51c:	01c00008 */ 	jr	$t6
/*  f17e520:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17e524:	3c0f800b */ 	lui	$t7,0x800b
/*  f17e528:	91efcc10 */ 	lbu	$t7,-0x33f0($t7)
/*  f17e52c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f17e530:	55e1011e */ 	bnel	$t7,$at,.L0f17e9ac
/*  f17e534:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e538:	1000011c */ 	beqz	$zero,.L0f17e9ac
/*  f17e53c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f17e540:	0fc66d99 */ 	jal	mpGetNumAvailableChallenges
/*  f17e544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17e548:	10000117 */ 	beqz	$zero,.L0f17e9a8
/*  f17e54c:	aec20000 */ 	sw	$v0,0x0($s6)
/*  f17e550:	8ed80004 */ 	lw	$t8,0x4($s6)
/*  f17e554:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f17e558:	3c0c8007 */ 	lui	$t4,0x8007
/*  f17e55c:	13000002 */ 	beqz	$t8,.L0f17e568
/*  f17e560:	3c0f8009 */ 	lui	$t7,0x8009
/*  f17e564:	aed90004 */ 	sw	$t9,0x4($s6)
.L0f17e568:
/*  f17e568:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f17e56c:	8ecb0000 */ 	lw	$t3,0x0($s6)
/*  f17e570:	3c01800a */ 	lui	$at,0x800a
/*  f17e574:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f17e578:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17e57c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f17e580:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f17e584:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f17e588:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17e58c:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f17e590:	002d0821 */ 	addu	$at,$at,$t5
/*  f17e594:	ac2bee1c */ 	sw	$t3,-0x11e4($at)
/*  f17e598:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f17e59c:	3c048008 */ 	lui	$a0,%hi(menudialog_2bfa8)
/*  f17e5a0:	15c00005 */ 	bnez	$t6,.L0f17e5b8
/*  f17e5a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17e5a8:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f17e5ac:	24845f88 */ 	addiu	$a0,$a0,%lo(menudialog_2bfa8)
/*  f17e5b0:	100000fe */ 	beqz	$zero,.L0f17e9ac
/*  f17e5b4:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e5b8:
/*  f17e5b8:	91ef0af0 */ 	lbu	$t7,0xaf0($t7)
/*  f17e5bc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17e5c0:	3c048008 */ 	lui	$a0,%hi(menudialog_2c0cc)
/*  f17e5c4:	15e10006 */ 	bne	$t7,$at,.L0f17e5e0
/*  f17e5c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17e5cc:	3c048007 */ 	lui	$a0,%hi(menudialog_1b1bc)
/*  f17e5d0:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f17e5d4:	2484519c */ 	addiu	$a0,$a0,%lo(menudialog_1b1bc)
/*  f17e5d8:	100000f4 */ 	beqz	$zero,.L0f17e9ac
/*  f17e5dc:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e5e0:
/*  f17e5e0:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f17e5e4:	248460ac */ 	addiu	$a0,$a0,%lo(menudialog_2c0cc)
/*  f17e5e8:	100000f0 */ 	beqz	$zero,.L0f17e9ac
/*  f17e5ec:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e5f0:	3c18000f */ 	lui	$t8,0xf
/*  f17e5f4:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f17e5f8:	100000eb */ 	beqz	$zero,.L0f17e9a8
/*  f17e5fc:	aed80000 */ 	sw	$t8,0x0($s6)
/*  f17e600:	100000e9 */ 	beqz	$zero,.L0f17e9a8
/*  f17e604:	aec00000 */ 	sw	$zero,0x0($s6)
/*  f17e608:	100000e8 */ 	beqz	$zero,.L0f17e9ac
/*  f17e60c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e610:	100000e5 */ 	beqz	$zero,.L0f17e9a8
/*  f17e614:	aec00008 */ 	sw	$zero,0x8($s6)
/*  f17e618:	8ed90000 */ 	lw	$t9,0x0($s6)
/*  f17e61c:	3c0c8009 */ 	lui	$t4,0x8009
/*  f17e620:	918c0af0 */ 	lbu	$t4,0xaf0($t4)
/*  f17e624:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17e628:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f17e62c:	8ed00008 */ 	lw	$s0,0x8($s6)
/*  f17e630:	2413000a */ 	addiu	$s3,$zero,0xa
/*  f17e634:	15810002 */ 	bne	$t4,$at,.L0f17e640
/*  f17e638:	24170004 */ 	addiu	$s7,$zero,0x4
/*  f17e63c:	24170002 */ 	addiu	$s7,$zero,0x2
.L0f17e640:
/*  f17e640:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f17e644:	8fa400b4 */ 	lw	$a0,0xb4($sp)
/*  f17e648:	256d000a */ 	addiu	$t5,$t3,0xa
/*  f17e64c:	afad00ac */ 	sw	$t5,0xac($sp)
/*  f17e650:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f17e654:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f17e658:	0fc54d8a */ 	jal	func0f153628
/*  f17e65c:	afaf00a8 */ 	sw	$t7,0xa8($sp)
/*  f17e660:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f17e664:	0fc66dbe */ 	jal	func0f19b6f8
/*  f17e668:	8ec40004 */ 	lw	$a0,0x4($s6)
/*  f17e66c:	0c002f02 */ 	jal	func0000bc08
/*  f17e670:	00408825 */ 	or	$s1,$v0,$zero
/*  f17e674:	00029400 */ 	sll	$s2,$v0,0x10
/*  f17e678:	0012c403 */ 	sra	$t8,$s2,0x10
/*  f17e67c:	0c002f06 */ 	jal	func0000bc18
/*  f17e680:	03009025 */ 	or	$s2,$t8,$zero
/*  f17e684:	3c198008 */ 	lui	$t9,0x8008
/*  f17e688:	3c0c8008 */ 	lui	$t4,0x8008
/*  f17e68c:	8d8cfb0c */ 	lw	$t4,-0x4f4($t4)
/*  f17e690:	8f39fb10 */ 	lw	$t9,-0x4f0($t9)
/*  f17e694:	8fa400b4 */ 	lw	$a0,0xb4($sp)
/*  f17e698:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f17e69c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f17e6a0:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f17e6a4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f17e6a8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f17e6ac:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f17e6b0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f17e6b4:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f17e6b8:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f17e6bc:	02203825 */ 	or	$a3,$s1,$zero
/*  f17e6c0:	0fc5580f */ 	jal	func0f15603c
/*  f17e6c4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f17e6c8:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f17e6cc:	0fc54de0 */ 	jal	func0f153780
/*  f17e6d0:	00402025 */ 	or	$a0,$v0,$zero
/*  f17e6d4:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f17e6d8:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f17e6dc:	3c0ee700 */ 	lui	$t6,0xe700
/*  f17e6e0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f17e6e4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f17e6e8:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f17e6ec:	3c19ba00 */ 	lui	$t9,0xba00
/*  f17e6f0:	37391301 */ 	ori	$t9,$t9,0x1301
/*  f17e6f4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17e6f8:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f17e6fc:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f17e700:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f17e704:	8fac00b4 */ 	lw	$t4,0xb4($sp)
/*  f17e708:	3c0db900 */ 	lui	$t5,0xb900
/*  f17e70c:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f17e710:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f17e714:	afab00b4 */ 	sw	$t3,0xb4($sp)
/*  f17e718:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f17e71c:	ad8d0000 */ 	sw	$t5,0x0($t4)
/*  f17e720:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f17e724:	3c18ba00 */ 	lui	$t8,0xba00
/*  f17e728:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f17e72c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f17e730:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f17e734:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f17e738:	add80000 */ 	sw	$t8,0x0($t6)
/*  f17e73c:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f17e740:	3c0bba00 */ 	lui	$t3,0xba00
/*  f17e744:	356b0903 */ 	ori	$t3,$t3,0x903
/*  f17e748:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f17e74c:	afac00b4 */ 	sw	$t4,0xb4($sp)
/*  f17e750:	240d0c00 */ 	addiu	$t5,$zero,0xc00
/*  f17e754:	3c05800b */ 	lui	$a1,0x800b
/*  f17e758:	af2d0004 */ 	sw	$t5,0x4($t9)
/*  f17e75c:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f17e760:	8ca5b5a8 */ 	lw	$a1,-0x4a58($a1)
/*  f17e764:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f17e768:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f17e76c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f17e770:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f17e774:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f17e778:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f17e77c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f17e780:	00003825 */ 	or	$a3,$zero,$zero
/*  f17e784:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f17e788:	24a501a4 */ 	addiu	$a1,$a1,0x01a4
/*  f17e78c:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f17e790:	3c0cba00 */ 	lui	$t4,0xba00
/*  f17e794:	358c1402 */ 	ori	$t4,$t4,0x1402
/*  f17e798:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f17e79c:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f17e7a0:	af000004 */ 	sw	$zero,0x4($t8)
/*  f17e7a4:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f17e7a8:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f17e7ac:	3c0eba00 */ 	lui	$t6,0xba00
/*  f17e7b0:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f17e7b4:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f17e7b8:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f17e7bc:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e7c0:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f17e7c4:	1ae00074 */ 	blez	$s7,.L0f17e998
/*  f17e7c8:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f17e7cc:	3c128008 */ 	lui	$s2,%hi(var8007fac0)
/*  f17e7d0:	2652fac0 */ 	addiu	$s2,$s2,%lo(var8007fac0)
/*  f17e7d4:	241500ff */ 	addiu	$s5,$zero,0xff
/*  f17e7d8:	3c14fb00 */ 	lui	$s4,0xfb00
/*  f17e7dc:	24510001 */ 	addiu	$s1,$v0,0x1
.L0f17e7e0:
/*  f17e7e0:	02202825 */ 	or	$a1,$s1,$zero
/*  f17e7e4:	0fc66e00 */ 	jal	func0f19b800
/*  f17e7e8:	8ec40004 */ 	lw	$a0,0x4($s6)
/*  f17e7ec:	1040000f */ 	beqz	$v0,.L0f17e82c
/*  f17e7f0:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f17e7f4:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f17e7f8:	3c01ffe5 */ 	lui	$at,0xffe5
/*  f17e7fc:	34216500 */ 	ori	$at,$at,0x6500
/*  f17e800:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17e804:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f17e808:	adf40000 */ 	sw	$s4,0x0($t7)
/*  f17e80c:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f17e810:	332c00ff */ 	andi	$t4,$t9,0xff
/*  f17e814:	01950019 */ 	multu	$t4,$s5
/*  f17e818:	00005812 */ 	mflo	$t3
/*  f17e81c:	000b6a02 */ 	srl	$t5,$t3,0x8
/*  f17e820:	01a17025 */ 	or	$t6,$t5,$at
/*  f17e824:	1000000c */ 	beqz	$zero,.L0f17e858
/*  f17e828:	adee0004 */ 	sw	$t6,0x4($t7)
.L0f17e82c:
/*  f17e82c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17e830:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f17e834:	adf40000 */ 	sw	$s4,0x0($t7)
/*  f17e838:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f17e83c:	3c014343 */ 	lui	$at,0x4343
/*  f17e840:	332c00ff */ 	andi	$t4,$t9,0xff
/*  f17e844:	01950019 */ 	multu	$t4,$s5
/*  f17e848:	00005812 */ 	mflo	$t3
/*  f17e84c:	000b6a02 */ 	srl	$t5,$t3,0x8
/*  f17e850:	01a17025 */ 	or	$t6,$t5,$at
/*  f17e854:	adee0004 */ 	sw	$t6,0x4($t7)
.L0f17e858:
/*  f17e858:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f17e85c:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f17e860:	3c0cff37 */ 	lui	$t4,0xff37
/*  f17e864:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17e868:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f17e86c:	358cffff */ 	ori	$t4,$t4,0xffff
/*  f17e870:	37399a25 */ 	ori	$t9,$t9,0x9a25
/*  f17e874:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f17e878:	adec0004 */ 	sw	$t4,0x4($t7)
/*  f17e87c:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f17e880:	01e01025 */ 	or	$v0,$t7,$zero
/*  f17e884:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f17e888:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f17e88c:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f17e890:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f17e894:	01601825 */ 	or	$v1,$t3,$zero
/*  f17e898:	3c01e400 */ 	lui	$at,0xe400
/*  f17e89c:	01d37821 */ 	addu	$t7,$t6,$s3
/*  f17e8a0:	25f8000b */ 	addiu	$t8,$t7,0xb
/*  f17e8a4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17e8a8:	032c0019 */ 	multu	$t9,$t4
/*  f17e8ac:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f17e8b0:	02201025 */ 	or	$v0,$s1,$zero
/*  f17e8b4:	27190016 */ 	addiu	$t9,$t8,0x16
/*  f17e8b8:	00196080 */ 	sll	$t4,$t9,0x2
/*  f17e8bc:	00005812 */ 	mflo	$t3
/*  f17e8c0:	316d0fff */ 	andi	$t5,$t3,0xfff
/*  f17e8c4:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f17e8c8:	01c17825 */ 	or	$t7,$t6,$at
/*  f17e8cc:	318b0fff */ 	andi	$t3,$t4,0xfff
/*  f17e8d0:	01eb6825 */ 	or	$t5,$t7,$t3
/*  f17e8d4:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f17e8d8:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f17e8dc:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f17e8e0:	01d3c021 */ 	addu	$t8,$t6,$s3
/*  f17e8e4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17e8e8:	032c0019 */ 	multu	$t9,$t4
/*  f17e8ec:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f17e8f0:	2673000d */ 	addiu	$s3,$s3,0xd
/*  f17e8f4:	25d8000b */ 	addiu	$t8,$t6,0xb
/*  f17e8f8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17e8fc:	332c0fff */ 	andi	$t4,$t9,0xfff
/*  f17e900:	24190160 */ 	addiu	$t9,$zero,0x160
/*  f17e904:	3c18b400 */ 	lui	$t8,0xb400
/*  f17e908:	00007812 */ 	mflo	$t7
/*  f17e90c:	31eb0fff */ 	andi	$t3,$t7,0xfff
/*  f17e910:	000b6b00 */ 	sll	$t5,$t3,0xc
/*  f17e914:	01ac7825 */ 	or	$t7,$t5,$t4
/*  f17e918:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f17e91c:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f17e920:	3c0fb300 */ 	lui	$t7,0xb300
/*  f17e924:	256e0008 */ 	addiu	$t6,$t3,0x8
/*  f17e928:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*  f17e92c:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f17e930:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f17e934:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f17e938:	01602025 */ 	or	$a0,$t3,$zero
/*  f17e93c:	240e0400 */ 	addiu	$t6,$zero,0x400
/*  f17e940:	25ac0008 */ 	addiu	$t4,$t5,0x8
/*  f17e944:	afac00b4 */ 	sw	$t4,0xb4($sp)
/*  f17e948:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f17e94c:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f17e950:	01a02825 */ 	or	$a1,$t5,$zero
/*  f17e954:	01cb001a */ 	div	$zero,$t6,$t3
/*  f17e958:	0000c012 */ 	mflo	$t8
/*  f17e95c:	3319ffff */ 	andi	$t9,$t8,0xffff
/*  f17e960:	00196c00 */ 	sll	$t5,$t9,0x10
/*  f17e964:	35acfc00 */ 	ori	$t4,$t5,0xfc00
/*  f17e968:	15600002 */ 	bnez	$t3,.L0f17e974
/*  f17e96c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17e970:	0007000d */ 	break	0x7
.L0f17e974:
/*  f17e974:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17e978:	15610004 */ 	bne	$t3,$at,.L0f17e98c
/*  f17e97c:	3c018000 */ 	lui	$at,0x8000
/*  f17e980:	15c10002 */ 	bne	$t6,$at,.L0f17e98c
/*  f17e984:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17e988:	0006000d */ 	break	0x6
.L0f17e98c:
/*  f17e98c:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f17e990:	5637ff93 */ 	bnel	$s1,$s7,.L0f17e7e0
/*  f17e994:	24510001 */ 	addiu	$s1,$v0,0x1
.L0f17e998:
/*  f17e998:	10000004 */ 	beqz	$zero,.L0f17e9ac
/*  f17e99c:	8fa200b4 */ 	lw	$v0,0xb4($sp)
/*  f17e9a0:	240f001a */ 	addiu	$t7,$zero,0x1a
/*  f17e9a4:	aecf0000 */ 	sw	$t7,0x0($s6)
.L0f17e9a8:
/*  f17e9a8:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e9ac:
/*  f17e9ac:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f17e9b0:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f17e9b4:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f17e9b8:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f17e9bc:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f17e9c0:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f17e9c4:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f17e9c8:	8fb6004c */ 	lw	$s6,0x4c($sp)
/*  f17e9cc:	8fb70050 */ 	lw	$s7,0x50($sp)
/*  f17e9d0:	03e00008 */ 	jr	$ra
/*  f17e9d4:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

/**
 * This is for a separator and fixed height thing in the dialog at:
 * Combat Simulator > Advanced Setup > Challenges > pick one > Accept
 */
s32 menuhandler0017e9d8(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MpSetup.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerMpAbortChallenge(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MpSetup.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	if (operation == MENUOP_SET) {
		func0f19c220();
	}

	return 0;
}

s32 menuhandlerMpStartChallenge(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MpSetup.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}
	if (operation == MENUOP_SET) {
		menuPushDialog(&g_MpReadyMenuDialog);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f17eac8
/*  f17eac8:	3c0e800b */ 	lui	$t6,0x800b
/*  f17eacc:	91cecc10 */ 	lbu	$t6,-0x33f0($t6)
/*  f17ead0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17ead4:	24010005 */ 	addiu	$at,$zero,0x5
/*  f17ead8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17eadc:	11c10005 */ 	beq	$t6,$at,.L0f17eaf4
/*  f17eae0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17eae4:	0fc5b9f1 */ 	jal	textGet
/*  f17eae8:	24045032 */ 	addiu	$a0,$zero,0x5032
/*  f17eaec:	1000000e */ 	beqz	$zero,.L0f17eb28
/*  f17eaf0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17eaf4:
/*  f17eaf4:	0fc66dfd */ 	jal	mpGetCurrentChallengeIndex
/*  f17eaf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17eafc:	0fc66daf */ 	jal	mpChallengeGetName
/*  f17eb00:	00402025 */ 	or	$a0,$v0,$zero
/*  f17eb04:	3c048007 */ 	lui	$a0,0x8007
/*  f17eb08:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f17eb0c:	24a58048 */ 	addiu	$a1,$a1,-32696
/*  f17eb10:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17eb14:	0c004dad */ 	jal	sprintf
/*  f17eb18:	00403025 */ 	or	$a2,$v0,$zero
/*  f17eb1c:	3c028007 */ 	lui	$v0,0x8007
/*  f17eb20:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17eb24:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17eb28:
/*  f17eb28:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17eb2c:	03e00008 */ 	jr	$ra
/*  f17eb30:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog0017eb34
/*  f17eb34:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17eb38:	24010066 */ 	addiu	$at,$zero,0x66
/*  f17eb3c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17eb40:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17eb44:	1481002c */ 	bne	$a0,$at,.L0f17ebf8
/*  f17eb48:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f17eb4c:	3c0f800b */ 	lui	$t7,0x800b
/*  f17eb50:	91efcc10 */ 	lbu	$t7,-0x33f0($t7)
/*  f17eb54:	24010005 */ 	addiu	$at,$zero,0x5
/*  f17eb58:	3c188007 */ 	lui	$t8,0x8007
/*  f17eb5c:	55e10027 */ 	bnel	$t7,$at,.L0f17ebfc
/*  f17eb60:	8fad0018 */ 	lw	$t5,0x18($sp)
/*  f17eb64:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f17eb68:	3c02800a */ 	lui	$v0,0x800a
/*  f17eb6c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f17eb70:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17eb74:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17eb78:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f17eb7c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17eb80:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17eb84:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17eb88:	00591021 */ 	addu	$v0,$v0,$t9
/*  f17eb8c:	8c42e4f8 */ 	lw	$v0,-0x1b08($v0)
/*  f17eb90:	5040001a */ 	beqzl	$v0,.L0f17ebfc
/*  f17eb94:	8fad0018 */ 	lw	$t5,0x18($sp)
/*  f17eb98:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f17eb9c:	54a80017 */ 	bnel	$a1,$t0,.L0f17ebfc
/*  f17eba0:	8fad0018 */ 	lw	$t5,0x18($sp)
/*  f17eba4:	0fc6709d */ 	jal	mpIsVar800884b4NonZero
/*  f17eba8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ebac:	14400012 */ 	bnez	$v0,.L0f17ebf8
/*  f17ebb0:	3c098007 */ 	lui	$t1,0x8007
/*  f17ebb4:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f17ebb8:	3c0b800a */ 	lui	$t3,%hi(var8009e000)
/*  f17ebbc:	256be000 */ 	addiu	$t3,$t3,%lo(var8009e000)
/*  f17ebc0:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f17ebc4:	01495023 */ 	subu	$t2,$t2,$t1
/*  f17ebc8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f17ebcc:	01495021 */ 	addu	$t2,$t2,$t1
/*  f17ebd0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f17ebd4:	01495023 */ 	subu	$t2,$t2,$t1
/*  f17ebd8:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f17ebdc:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f17ebe0:	3c0c4fac */ 	lui	$t4,0x4fac
/*  f17ebe4:	358c5ace */ 	ori	$t4,$t4,0x5ace
/*  f17ebe8:	ac4c0850 */ 	sw	$t4,0x850($v0)
/*  f17ebec:	8c440844 */ 	lw	$a0,0x844($v0)
/*  f17ebf0:	0fc67091 */ 	jal	mpCalculateVar800884b4
/*  f17ebf4:	8c450848 */ 	lw	$a1,0x848($v0)
.L0f17ebf8:
/*  f17ebf8:	8fad0018 */ 	lw	$t5,0x18($sp)
.L0f17ebfc:
/*  f17ebfc:	24010065 */ 	addiu	$at,$zero,0x65
/*  f17ec00:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17ec04:	55a10013 */ 	bnel	$t5,$at,.L0f17ec54
/*  f17ec08:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17ec0c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17ec10:	3c18800a */ 	lui	$t8,0x800a
/*  f17ec14:	3c014fac */ 	lui	$at,0x4fac
/*  f17ec18:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17ec1c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17ec20:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17ec24:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17ec28:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17ec2c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17ec30:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17ec34:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17ec38:	8f18e850 */ 	lw	$t8,-0x17b0($t8)
/*  f17ec3c:	34215ace */ 	ori	$at,$at,0x5ace
/*  f17ec40:	57010004 */ 	bnel	$t8,$at,.L0f17ec54
/*  f17ec44:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17ec48:	0fc6709a */ 	jal	mpResetVar800884b4
/*  f17ec4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ec50:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17ec54:
/*  f17ec54:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17ec58:	00001025 */ 	or	$v0,$zero,$zero
/*  f17ec5c:	03e00008 */ 	jr	$ra
/*  f17ec60:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandler0017ec64(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		mpSetCurrentChallenge(g_MenuStack[g_MpPlayerNum].slotindex);
		func0f0f820c(&g_MpQuickGoMenuDialog, 3);
	}

	return 0;
}

char *menuhandlerMpLock(u32 operation, struct menu_item *item, s32 *value)
{
	u16 labels[4] = mplockoptions;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		if (mpGetLockType() == MPLOCKTYPE_CHALLENGE) {
			*value = 1;
		} else {
			*value = 5;
		}
		break;
	case MENUOP_GETOPTIONTEXT:
		if (mpGetLockType() == MPLOCKTYPE_CHALLENGE) {
			return textGet(0x5031); // "Challenge"
		}
		if ((u32)*value <= 3) {
			return textGet(labels[*value]);
		}
		if (mpGetLockType() == MPLOCKTYPE_PLAYER) {
			return g_MpPlayers[mpGetLockPlayerNum()].base.name;
		}
		return mpGetCurrentPlayerName(item);
	case MENUOP_SET:
		if (mpGetLockType() != MPLOCKTYPE_CHALLENGE) {
			mpSetLock(*value, g_MpPlayerNum);
		}
		g_Vars.unk000458 |= 2;
		break;
	case MENUOP_GETOPTIONVALUE:
		if (mpGetLockType() == MPLOCKTYPE_CHALLENGE) {
			*value = 0;
		} else {
			*value = mpGetLockType();
		}
		break;
	}

	return NULL;
}

s32 menuhandlerMpSavePlayer(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		if (g_MpPlayers[g_MpPlayerNum].unk4c == 0) {
			func0f10a51c(6, 2);
		} else {
			menuPushDialog(&g_MpSaveChrMenuDialog);
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f17eed4
/*  f17eed4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f17eed8:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f17eedc:	3c18800b */ 	lui	$t8,0x800b
/*  f17eee0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17eee4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17eee8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17eeec:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17eef0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17eef4:	8f18c804 */ 	lw	$t8,-0x37fc($t8)
/*  f17eef8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17eefc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17ef00:	17000005 */ 	bnez	$t8,.L0f17ef18
/*  f17ef04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17ef08:	0fc5b9f1 */ 	jal	textGet
/*  f17ef0c:	24045026 */ 	addiu	$a0,$zero,0x5026
/*  f17ef10:	10000004 */ 	beqz	$zero,.L0f17ef24
/*  f17ef14:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17ef18:
/*  f17ef18:	0fc5b9f1 */ 	jal	textGet
/*  f17ef1c:	24045027 */ 	addiu	$a0,$zero,0x5027
/*  f17ef20:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17ef24:
/*  f17ef24:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17ef28:	03e00008 */ 	jr	$ra
/*  f17ef2c:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandler0017ef30(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		if (g_Vars.stagenum == STAGE_CITRAINING) {
			if (var80090af0 == 1) {
				func0f0f820c(&menudialog_mainmenu2, 2);
			} else {
				func0f0f820c(&menudialog_mainmenu, 2);
			}
		} else {
			func0f0f820c(&menudialog_196b0, 2);
		}
	}

	return 0;
}

s32 menuhandlerMpSaveSettings(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		if (g_MpSetup.saved == false) {
			menuPushDialog(&menudialog_mpsavesetupname);
		} else {
			func0f108324(g_MpSetup.unk24);
			menuPushDialog(&menudialog_mpsavesetup);
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f17f024
/*  f17f024:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17f028:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17f02c:	3c048008 */ 	lui	$a0,0x8008
/*  f17f030:	3c03800b */ 	lui	$v1,0x800b
/*  f17f034:	3c028008 */ 	lui	$v0,%hi(mpstages)
/*  f17f038:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17f03c:	24424b98 */ 	addiu	$v0,$v0,%lo(mpstages)
/*  f17f040:	9063cb99 */ 	lbu	$v1,-0x3467($v1)
/*  f17f044:	24844bfe */ 	addiu	$a0,$a0,0x4bfe
/*  f17f048:	844e0000 */ 	lh	$t6,0x0($v0)
.L0f17f04c:
/*  f17f04c:	546e0006 */ 	bnel	$v1,$t6,.L0f17f068
/*  f17f050:	24420006 */ 	addiu	$v0,$v0,0x6
/*  f17f054:	0fc5b9f1 */ 	jal	textGet
/*  f17f058:	94440004 */ 	lhu	$a0,0x4($v0)
/*  f17f05c:	10000007 */ 	beqz	$zero,.L0f17f07c
/*  f17f060:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17f064:	24420006 */ 	addiu	$v0,$v0,0x6
.L0f17f068:
/*  f17f068:	5444fff8 */ 	bnel	$v0,$a0,.L0f17f04c
/*  f17f06c:	844e0000 */ 	lh	$t6,0x0($v0)
/*  f17f070:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f17f074:	24428050 */ 	addiu	$v0,$v0,-32688
/*  f17f078:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17f07c:
/*  f17f07c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17f080:	03e00008 */ 	jr	$ra
/*  f17f084:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f17f088
/*  f17f088:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17f08c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17f090:	0fc62587 */ 	jal	func0f18961c
/*  f17f094:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f17f098:	0fc6242a */ 	jal	func0f1890a8
/*  f17f09c:	00402025 */ 	or	$a0,$v0,$zero
/*  f17f0a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17f0a4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17f0a8:	03e00008 */ 	jr	$ra
/*  f17f0ac:	00000000 */ 	sll	$zero,$zero,0x0
);

bool menudialogMpGameSetup(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	if (operation == MENUOP_100) {
		g_Vars.unk000490 = 1;
		g_Vars.unk00049c = 1;
	}

	return false;
}

bool menudialogMpQuickGo(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	if (operation == MENUOP_100) {
		g_Vars.unk000490 = 3;
	}

	return false;
}

GLOBAL_ASM(
glabel func0f17f100
/*  f17f100:	3c0e800a */ 	lui	$t6,0x800a
/*  f17f104:	8dcea470 */ 	lw	$t6,-0x5b90($t6)
/*  f17f108:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f17f10c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f17f110:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f17f114:	11c1004d */ 	beq	$t6,$at,.L0f17f24c
/*  f17f118:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17f11c:	00008025 */ 	or	$s0,$zero,$zero
.L0f17f120:
/*  f17f120:	0fc632ff */ 	jal	mpRemoveSimulant
/*  f17f124:	02002025 */ 	or	$a0,$s0,$zero
/*  f17f128:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f17f12c:	2a010008 */ 	slti	$at,$s0,0x8
/*  f17f130:	1420fffb */ 	bnez	$at,.L0f17f120
/*  f17f134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f138:	3c0f800a */ 	lui	$t7,0x800a
/*  f17f13c:	8defa470 */ 	lw	$t7,-0x5b90($t7)
/*  f17f140:	2de10005 */ 	sltiu	$at,$t7,0x5
/*  f17f144:	10200041 */ 	beqz	$at,.L0f17f24c
/*  f17f148:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17f14c:	3c017f1c */ 	lui	$at,%hi(var7f1b828c)
/*  f17f150:	002f0821 */ 	addu	$at,$at,$t7
/*  f17f154:	8c2f828c */ 	lw	$t7,%lo(var7f1b828c)($at)
/*  f17f158:	01e00008 */ 	jr	$t7
/*  f17f15c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f160:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f17f164:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f17f168:	8c98000c */ 	lw	$t8,0xc($a0)
/*  f17f16c:	2401fffd */ 	addiu	$at,$zero,-3
/*  f17f170:	0301c824 */ 	and	$t9,$t8,$at
/*  f17f174:	10000035 */ 	beqz	$zero,.L0f17f24c
/*  f17f178:	ac99000c */ 	sw	$t9,0xc($a0)
/*  f17f17c:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f17f180:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f17f184:	8c88000c */ 	lw	$t0,0xc($a0)
/*  f17f188:	2401fffd */ 	addiu	$at,$zero,-3
/*  f17f18c:	01014824 */ 	and	$t1,$t0,$at
/*  f17f190:	1000002e */ 	beqz	$zero,.L0f17f24c
/*  f17f194:	ac89000c */ 	sw	$t1,0xc($a0)
/*  f17f198:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f17f19c:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f17f1a0:	8c8a000c */ 	lw	$t2,0xc($a0)
/*  f17f1a4:	3c02800b */ 	lui	$v0,%hi(g_MpPlayers)
/*  f17f1a8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f17f1ac:	354b0002 */ 	ori	$t3,$t2,0x2
/*  f17f1b0:	ac8b000c */ 	sw	$t3,0xc($a0)
/*  f17f1b4:	3c04800a */ 	lui	$a0,0x800a
/*  f17f1b8:	24849fc4 */ 	addiu	$a0,$a0,-24636
/*  f17f1bc:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f17f1c0:	2442c7b8 */ 	addiu	$v0,$v0,%lo(g_MpPlayers)
.L0f17f1c4:
/*  f17f1c4:	806c04ac */ 	lb	$t4,0x4ac($v1)
/*  f17f1c8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17f1cc:	244200a0 */ 	addiu	$v0,$v0,0xa0
/*  f17f1d0:	1464fffc */ 	bne	$v1,$a0,.L0f17f1c4
/*  f17f1d4:	a04cff71 */ 	sb	$t4,-0x8f($v0)
/*  f17f1d8:	1000001d */ 	beqz	$zero,.L0f17f250
/*  f17f1dc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f17f1e0:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f17f1e4:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f17f1e8:	8c8d000c */ 	lw	$t5,0xc($a0)
/*  f17f1ec:	3c02800b */ 	lui	$v0,%hi(g_MpPlayers)
/*  f17f1f0:	3c03800b */ 	lui	$v1,%hi(var800aca38)
/*  f17f1f4:	35ae0002 */ 	ori	$t6,$t5,0x2
/*  f17f1f8:	ac8e000c */ 	sw	$t6,0xc($a0)
/*  f17f1fc:	2463ca38 */ 	addiu	$v1,$v1,%lo(var800aca38)
/*  f17f200:	2442c7b8 */ 	addiu	$v0,$v0,%lo(g_MpPlayers)
.L0f17f204:
/*  f17f204:	244200a0 */ 	addiu	$v0,$v0,0xa0
/*  f17f208:	1443fffe */ 	bne	$v0,$v1,.L0f17f204
/*  f17f20c:	a040ff71 */ 	sb	$zero,-0x8f($v0)
/*  f17f210:	1000000f */ 	beqz	$zero,.L0f17f250
/*  f17f214:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f17f218:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f17f21c:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f17f220:	8c8f000c */ 	lw	$t7,0xc($a0)
/*  f17f224:	3c02800b */ 	lui	$v0,%hi(g_MpPlayers)
/*  f17f228:	2442c7b8 */ 	addiu	$v0,$v0,%lo(g_MpPlayers)
/*  f17f22c:	35f80002 */ 	ori	$t8,$t7,0x2
/*  f17f230:	ac98000c */ 	sw	$t8,0xc($a0)
/*  f17f234:	00008025 */ 	or	$s0,$zero,$zero
/*  f17f238:	24030004 */ 	addiu	$v1,$zero,0x4
.L0f17f23c:
/*  f17f23c:	a0500011 */ 	sb	$s0,0x11($v0)
/*  f17f240:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f17f244:	1603fffd */ 	bne	$s0,$v1,.L0f17f23c
/*  f17f248:	244200a0 */ 	addiu	$v0,$v0,0xa0
.L0f17f24c:
/*  f17f24c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f17f250:
/*  f17f250:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f17f254:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f17f258:	03e00008 */ 	jr	$ra
/*  f17f25c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f17f260
/*  f17f260:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f17f264:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f17f268:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f17f26c:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f17f270:	8e6204b0 */ 	lw	$v0,0x4b0($s3)
/*  f17f274:	24010005 */ 	addiu	$at,$zero,0x5
/*  f17f278:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f17f27c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f17f280:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f17f284:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f17f288:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f17f28c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f17f290:	1041005b */ 	beq	$v0,$at,.L0f17f400
/*  f17f294:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17f298:	2c410005 */ 	sltiu	$at,$v0,0x5
/*  f17f29c:	10200058 */ 	beqz	$at,.L0f17f400
/*  f17f2a0:	00027080 */ 	sll	$t6,$v0,0x2
/*  f17f2a4:	3c017f1c */ 	lui	$at,%hi(var7f1b82a0)
/*  f17f2a8:	002e0821 */ 	addu	$at,$at,$t6
/*  f17f2ac:	8c2e82a0 */ 	lw	$t6,%lo(var7f1b82a0)($at)
/*  f17f2b0:	01c00008 */ 	jr	$t6
/*  f17f2b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f2b8:	8e6f04a4 */ 	lw	$t7,0x4a4($s3)
/*  f17f2bc:	0000b025 */ 	or	$s6,$zero,$zero
/*  f17f2c0:	19e0000c */ 	blez	$t7,.L0f17f2f4
/*  f17f2c4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17f2c8:
/*  f17f2c8:	0fc632ee */ 	jal	func0f18cbb8
/*  f17f2cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f2d0:	04400003 */ 	bltz	$v0,.L0f17f2e0
/*  f17f2d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f17f2d8:	0fc63261 */ 	jal	func0f18c984
/*  f17f2dc:	926504ab */ 	lbu	$a1,0x4ab($s3)
.L0f17f2e0:
/*  f17f2e0:	8e7804a4 */ 	lw	$t8,0x4a4($s3)
/*  f17f2e4:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f17f2e8:	02d8082a */ 	slt	$at,$s6,$t8
/*  f17f2ec:	1420fff6 */ 	bnez	$at,.L0f17f2c8
/*  f17f2f0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17f2f4:
/*  f17f2f4:	0fc63377 */ 	jal	func0f18cddc
/*  f17f2f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f2fc:	10000041 */ 	beqz	$zero,.L0f17f404
/*  f17f300:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f17f304:	8e7904a4 */ 	lw	$t9,0x4a4($s3)
/*  f17f308:	0000b025 */ 	or	$s6,$zero,$zero
/*  f17f30c:	1b20000c */ 	blez	$t9,.L0f17f340
/*  f17f310:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17f314:
/*  f17f314:	0fc632ee */ 	jal	func0f18cbb8
/*  f17f318:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f31c:	04400003 */ 	bltz	$v0,.L0f17f32c
/*  f17f320:	00402025 */ 	or	$a0,$v0,$zero
/*  f17f324:	0fc63261 */ 	jal	func0f18c984
/*  f17f328:	926504ab */ 	lbu	$a1,0x4ab($s3)
.L0f17f32c:
/*  f17f32c:	8e6804a4 */ 	lw	$t0,0x4a4($s3)
/*  f17f330:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f17f334:	02c8082a */ 	slt	$at,$s6,$t0
/*  f17f338:	1420fff6 */ 	bnez	$at,.L0f17f314
/*  f17f33c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17f340:
/*  f17f340:	0fc63377 */ 	jal	func0f18cddc
/*  f17f344:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f348:	3c02800b */ 	lui	$v0,%hi(g_MpSimulants)
/*  f17f34c:	3c04800b */ 	lui	$a0,%hi(var800ac798)
/*  f17f350:	2484c798 */ 	addiu	$a0,$a0,%lo(var800ac798)
/*  f17f354:	2442c538 */ 	addiu	$v0,$v0,%lo(g_MpSimulants)
/*  f17f358:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f17f35c:
/*  f17f35c:	2442004c */ 	addiu	$v0,$v0,0x4c
/*  f17f360:	1444fffe */ 	bne	$v0,$a0,.L0f17f35c
/*  f17f364:	a043ffc5 */ 	sb	$v1,-0x3b($v0)
/*  f17f368:	10000026 */ 	beqz	$zero,.L0f17f404
/*  f17f36c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f17f370:	0fc6321f */ 	jal	func0f18c87c
/*  f17f374:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f378:	2456ffff */ 	addiu	$s6,$v0,-1
/*  f17f37c:	06c0001e */ 	bltz	$s6,.L0f17f3f8
/*  f17f380:	2415004c */ 	addiu	$s5,$zero,0x4c
/*  f17f384:	3c14800b */ 	lui	$s4,%hi(g_MpSimulants)
/*  f17f388:	2694c538 */ 	addiu	$s4,$s4,%lo(g_MpSimulants)
/*  f17f38c:	02c02025 */ 	or	$a0,$s6,$zero
.L0f17f390:
/*  f17f390:	0fc631e5 */ 	jal	func0f18c794
/*  f17f394:	00008825 */ 	or	$s1,$zero,$zero
/*  f17f398:	8e6904a0 */ 	lw	$t1,0x4a0($s3)
/*  f17f39c:	00409025 */ 	or	$s2,$v0,$zero
/*  f17f3a0:	59200013 */ 	blezl	$t1,.L0f17f3f0
/*  f17f3a4:	26d6ffff */ 	addiu	$s6,$s6,-1
.L0f17f3a8:
/*  f17f3a8:	0fc632ee */ 	jal	func0f18cbb8
/*  f17f3ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f3b0:	04400009 */ 	bltz	$v0,.L0f17f3d8
/*  f17f3b4:	00408025 */ 	or	$s0,$v0,$zero
/*  f17f3b8:	00402025 */ 	or	$a0,$v0,$zero
/*  f17f3bc:	0fc63261 */ 	jal	func0f18c984
/*  f17f3c0:	926504ab */ 	lbu	$a1,0x4ab($s3)
/*  f17f3c4:	02150019 */ 	multu	$s0,$s5
/*  f17f3c8:	924a0011 */ 	lbu	$t2,0x11($s2)
/*  f17f3cc:	00005812 */ 	mflo	$t3
/*  f17f3d0:	028b6021 */ 	addu	$t4,$s4,$t3
/*  f17f3d4:	a18a0011 */ 	sb	$t2,0x11($t4)
.L0f17f3d8:
/*  f17f3d8:	8e6d04a0 */ 	lw	$t5,0x4a0($s3)
/*  f17f3dc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17f3e0:	022d082a */ 	slt	$at,$s1,$t5
/*  f17f3e4:	1420fff0 */ 	bnez	$at,.L0f17f3a8
/*  f17f3e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f3ec:	26d6ffff */ 	addiu	$s6,$s6,-1
.L0f17f3f0:
/*  f17f3f0:	06c3ffe7 */ 	bgezl	$s6,.L0f17f390
/*  f17f3f4:	02c02025 */ 	or	$a0,$s6,$zero
.L0f17f3f8:
/*  f17f3f8:	0fc63377 */ 	jal	func0f18cddc
/*  f17f3fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17f400:
/*  f17f400:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f17f404:
/*  f17f404:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f17f408:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f17f40c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f17f410:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f17f414:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f17f418:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f17f41c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f17f420:	03e00008 */ 	jr	$ra
/*  f17f424:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f17f428
/*  f17f428:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17f42c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17f430:	0fc5fc40 */ 	jal	func0f17f100
/*  f17f434:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f438:	3c0e8009 */ 	lui	$t6,0x8009
/*  f17f43c:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f17f440:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17f444:	3c048008 */ 	lui	$a0,%hi(g_MpQuickGoMenuDialog)
/*  f17f448:	15c10007 */ 	bne	$t6,$at,.L0f17f468
/*  f17f44c:	24846500 */ 	addiu	$a0,$a0,%lo(g_MpQuickGoMenuDialog)
/*  f17f450:	3c048007 */ 	lui	$a0,%hi(menudialog_mpquickgo2)
/*  f17f454:	24845120 */ 	addiu	$a0,$a0,%lo(menudialog_mpquickgo2)
/*  f17f458:	0fc3e083 */ 	jal	func0f0f820c
/*  f17f45c:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f17f460:	10000004 */ 	beqz	$zero,.L0f17f474
/*  f17f464:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17f468:
/*  f17f468:	0fc3e083 */ 	jal	func0f0f820c
/*  f17f46c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f17f470:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17f474:
/*  f17f474:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17f478:	03e00008 */ 	jr	$ra
/*  f17f47c:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMpFinishedSetup(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKPREFOCUSED) {
		return true;
	}

	if (operation == MENUOP_SET) {
		func0f17f428();
	}

	return 0;
}

s32 menuhandlerQuickTeamSeparator(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSONLY) {
			return true;
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel menuhandler0017f4fc
/*  f17f4fc:	248effff */ 	addiu	$t6,$a0,-1
/*  f17f500:	2dc10018 */ 	sltiu	$at,$t6,0x18
/*  f17f504:	10200024 */ 	beqz	$at,.L0f17f598
/*  f17f508:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17f50c:	3c017f1c */ 	lui	$at,%hi(var7f1b82b4)
/*  f17f510:	002e0821 */ 	addu	$at,$at,$t6
/*  f17f514:	8c2e82b4 */ 	lw	$t6,%lo(var7f1b82b4)($at)
/*  f17f518:	01c00008 */ 	jr	$t6
/*  f17f51c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f520:	240f0008 */ 	addiu	$t7,$zero,0x8
/*  f17f524:	1000001c */ 	beqz	$zero,.L0f17f598
/*  f17f528:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f17f52c:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f17f530:	3c08800b */ 	lui	$t0,0x800b
/*  f17f534:	2508cbb0 */ 	addiu	$t0,$t0,-13392
/*  f17f538:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17f53c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17f540:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17f544:	03e00008 */ 	jr	$ra
/*  f17f548:	03281021 */ 	addu	$v0,$t9,$t0
/*  f17f54c:	90aa0001 */ 	lbu	$t2,0x1($a1)
/*  f17f550:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f17f554:	3c01800a */ 	lui	$at,0x800a
/*  f17f558:	002a0821 */ 	addu	$at,$at,$t2
/*  f17f55c:	1000000e */ 	beqz	$zero,.L0f17f598
/*  f17f560:	a029a46c */ 	sb	$t1,-0x5b94($at)
/*  f17f564:	90ab0001 */ 	lbu	$t3,0x1($a1)
/*  f17f568:	3c0c800a */ 	lui	$t4,0x800a
/*  f17f56c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f17f570:	818ca46c */ 	lb	$t4,-0x5b94($t4)
/*  f17f574:	10000008 */ 	beqz	$zero,.L0f17f598
/*  f17f578:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f17f57c:	3c0d800a */ 	lui	$t5,0x800a
/*  f17f580:	8dada470 */ 	lw	$t5,-0x5b90($t5)
/*  f17f584:	24010002 */ 	addiu	$at,$zero,0x2
/*  f17f588:	51a10004 */ 	beql	$t5,$at,.L0f17f59c
/*  f17f58c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17f590:	03e00008 */ 	jr	$ra
/*  f17f594:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f17f598:
/*  f17f598:	00001025 */ 	or	$v0,$zero,$zero
.L0f17f59c:
/*  f17f59c:	03e00008 */ 	jr	$ra
/*  f17f5a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerMpNumberOfSimulants
/*  f17f5a4:	248effff */ 	addiu	$t6,$a0,-1
/*  f17f5a8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17f5ac:	2dc10018 */ 	sltiu	$at,$t6,0x18
/*  f17f5b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17f5b4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f17f5b8:	1020002f */ 	beqz	$at,.L0f17f678
/*  f17f5bc:	00c03825 */ 	or	$a3,$a2,$zero
/*  f17f5c0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17f5c4:	3c017f1c */ 	lui	$at,%hi(var7f1b8314)
/*  f17f5c8:	002e0821 */ 	addu	$at,$at,$t6
/*  f17f5cc:	8c2e8314 */ 	lw	$t6,%lo(var7f1b8314)($at)
/*  f17f5d0:	01c00008 */ 	jr	$t6
/*  f17f5d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f5d8:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f17f5dc:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f17f5e0:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f17f5e4:	14400004 */ 	bnez	$v0,.L0f17f5f8
/*  f17f5e8:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f17f5ec:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f17f5f0:	10000021 */ 	beqz	$zero,.L0f17f678
/*  f17f5f4:	acef0000 */ 	sw	$t7,0x0($a3)
.L0f17f5f8:
/*  f17f5f8:	24180008 */ 	addiu	$t8,$zero,0x8
/*  f17f5fc:	1000001e */ 	beqz	$zero,.L0f17f678
/*  f17f600:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f17f604:	8ce60000 */ 	lw	$a2,0x0($a3)
/*  f17f608:	3c048007 */ 	lui	$a0,0x8007
/*  f17f60c:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f17f610:	24a58054 */ 	addiu	$a1,$a1,-32684
/*  f17f614:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17f618:	0c004dad */ 	jal	sprintf
/*  f17f61c:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17f620:	3c028007 */ 	lui	$v0,0x8007
/*  f17f624:	10000015 */ 	beqz	$zero,.L0f17f67c
/*  f17f628:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17f62c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f17f630:	3c01800a */ 	lui	$at,0x800a
/*  f17f634:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f17f638:	1000000f */ 	beqz	$zero,.L0f17f678
/*  f17f63c:	ac28a464 */ 	sw	$t0,-0x5b9c($at)
/*  f17f640:	3c09800a */ 	lui	$t1,0x800a
/*  f17f644:	8d29a464 */ 	lw	$t1,-0x5b9c($t1)
/*  f17f648:	252affff */ 	addiu	$t2,$t1,-1
/*  f17f64c:	1000000a */ 	beqz	$zero,.L0f17f678
/*  f17f650:	acea0000 */ 	sw	$t2,0x0($a3)
/*  f17f654:	3c02800a */ 	lui	$v0,0x800a
/*  f17f658:	8c42a470 */ 	lw	$v0,-0x5b90($v0)
/*  f17f65c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17f660:	10410005 */ 	beq	$v0,$at,.L0f17f678
/*  f17f664:	24010003 */ 	addiu	$at,$zero,0x3
/*  f17f668:	50410004 */ 	beql	$v0,$at,.L0f17f67c
/*  f17f66c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17f670:	10000002 */ 	beqz	$zero,.L0f17f67c
/*  f17f674:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f17f678:
/*  f17f678:	00001025 */ 	or	$v0,$zero,$zero
.L0f17f67c:
/*  f17f67c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17f680:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17f684:	03e00008 */ 	jr	$ra
/*  f17f688:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerMpSimulantsPerTeam
/*  f17f68c:	248effff */ 	addiu	$t6,$a0,-1
/*  f17f690:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f17f694:	2dc10018 */ 	sltiu	$at,$t6,0x18
/*  f17f698:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17f69c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f17f6a0:	10200025 */ 	beqz	$at,.L0f17f738
/*  f17f6a4:	00c03825 */ 	or	$a3,$a2,$zero
/*  f17f6a8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17f6ac:	3c017f1c */ 	lui	$at,%hi(var7f1b8374)
/*  f17f6b0:	002e0821 */ 	addu	$at,$at,$t6
/*  f17f6b4:	8c2e8374 */ 	lw	$t6,%lo(var7f1b8374)($at)
/*  f17f6b8:	01c00008 */ 	jr	$t6
/*  f17f6bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f6c0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f17f6c4:	1000001c */ 	beqz	$zero,.L0f17f738
/*  f17f6c8:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f17f6cc:	8ce60000 */ 	lw	$a2,0x0($a3)
/*  f17f6d0:	3c048007 */ 	lui	$a0,0x8007
/*  f17f6d4:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f17f6d8:	24a58058 */ 	addiu	$a1,$a1,-32680
/*  f17f6dc:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f17f6e0:	0c004dad */ 	jal	sprintf
/*  f17f6e4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17f6e8:	3c028007 */ 	lui	$v0,0x8007
/*  f17f6ec:	10000013 */ 	beqz	$zero,.L0f17f73c
/*  f17f6f0:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f17f6f4:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f17f6f8:	3c01800a */ 	lui	$at,0x800a
/*  f17f6fc:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f17f700:	1000000d */ 	beqz	$zero,.L0f17f738
/*  f17f704:	ac39a460 */ 	sw	$t9,-0x5ba0($at)
/*  f17f708:	3c08800a */ 	lui	$t0,0x800a
/*  f17f70c:	8d08a460 */ 	lw	$t0,-0x5ba0($t0)
/*  f17f710:	2509ffff */ 	addiu	$t1,$t0,-1
/*  f17f714:	10000008 */ 	beqz	$zero,.L0f17f738
/*  f17f718:	ace90000 */ 	sw	$t1,0x0($a3)
/*  f17f71c:	3c0a800a */ 	lui	$t2,0x800a
/*  f17f720:	8d4aa470 */ 	lw	$t2,-0x5b90($t2)
/*  f17f724:	24010004 */ 	addiu	$at,$zero,0x4
/*  f17f728:	51410004 */ 	beql	$t2,$at,.L0f17f73c
/*  f17f72c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17f730:	10000002 */ 	beqz	$zero,.L0f17f73c
/*  f17f734:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f17f738:
/*  f17f738:	00001025 */ 	or	$v0,$zero,$zero
.L0f17f73c:
/*  f17f73c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17f740:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f17f744:	03e00008 */ 	jr	$ra
/*  f17f748:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler0017f74c
/*  f17f74c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f17f750:	248effff */ 	addiu	$t6,$a0,-1
/*  f17f754:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f17f758:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f17f75c:	2dc10018 */ 	sltiu	$at,$t6,0x18
/*  f17f760:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f17f764:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f17f768:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f17f76c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f17f770:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17f774:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f17f778:	1020003c */ 	beqz	$at,.L0f17f86c
/*  f17f77c:	00009025 */ 	or	$s2,$zero,$zero
/*  f17f780:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17f784:	3c017f1c */ 	lui	$at,%hi(var7f1b83d4)
/*  f17f788:	002e0821 */ 	addu	$at,$at,$t6
/*  f17f78c:	8c2e83d4 */ 	lw	$t6,%lo(var7f1b83d4)($at)
/*  f17f790:	01c00008 */ 	jr	$t6
/*  f17f794:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f798:	3c108008 */ 	lui	$s0,%hi(g_MpGeneralSimulants)
/*  f17f79c:	3c118008 */ 	lui	$s1,%hi(mpspecialsimulants)
/*  f17f7a0:	2631775c */ 	addiu	$s1,$s1,%lo(mpspecialsimulants)
/*  f17f7a4:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpGeneralSimulants)
.L0f17f7a8:
/*  f17f7a8:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f17f7ac:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17f7b0:	10400002 */ 	beqz	$v0,.L0f17f7bc
/*  f17f7b4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17f7b8:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f17f7bc:
/*  f17f7bc:	1611fffa */ 	bne	$s0,$s1,.L0f17f7a8
/*  f17f7c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17f7c4:	10000029 */ 	beqz	$zero,.L0f17f86c
/*  f17f7c8:	ae920000 */ 	sw	$s2,0x0($s4)
/*  f17f7cc:	3c108008 */ 	lui	$s0,%hi(g_MpGeneralSimulants)
/*  f17f7d0:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpGeneralSimulants)
/*  f17f7d4:	00008825 */ 	or	$s1,$zero,$zero
/*  f17f7d8:	24130006 */ 	addiu	$s3,$zero,0x6
.L0f17f7dc:
/*  f17f7dc:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f17f7e0:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17f7e4:	5040000a */ 	beqzl	$v0,.L0f17f810
/*  f17f7e8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17f7ec:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f17f7f0:	564f0006 */ 	bnel	$s2,$t7,.L0f17f80c
/*  f17f7f4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17f7f8:	0fc5b9f1 */ 	jal	textGet
/*  f17f7fc:	26245852 */ 	addiu	$a0,$s1,0x5852
/*  f17f800:	1000001c */ 	beqz	$zero,.L0f17f874
/*  f17f804:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17f808:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f17f80c:
/*  f17f80c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f17f810:
/*  f17f810:	1633fff2 */ 	bne	$s1,$s3,.L0f17f7dc
/*  f17f814:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17f818:	10000015 */ 	beqz	$zero,.L0f17f870
/*  f17f81c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17f820:	8e980000 */ 	lw	$t8,0x0($s4)
/*  f17f824:	3c01800a */ 	lui	$at,0x800a
/*  f17f828:	10000010 */ 	beqz	$zero,.L0f17f86c
/*  f17f82c:	ac38a468 */ 	sw	$t8,-0x5b98($at)
/*  f17f830:	3c19800a */ 	lui	$t9,0x800a
/*  f17f834:	8f39a468 */ 	lw	$t9,-0x5b98($t9)
/*  f17f838:	1000000c */ 	beqz	$zero,.L0f17f86c
/*  f17f83c:	ae990000 */ 	sw	$t9,0x0($s4)
/*  f17f840:	3c02800a */ 	lui	$v0,0x800a
/*  f17f844:	8c42a470 */ 	lw	$v0,-0x5b90($v0)
/*  f17f848:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17f84c:	10410007 */ 	beq	$v0,$at,.L0f17f86c
/*  f17f850:	24010003 */ 	addiu	$at,$zero,0x3
/*  f17f854:	10410005 */ 	beq	$v0,$at,.L0f17f86c
/*  f17f858:	24010004 */ 	addiu	$at,$zero,0x4
/*  f17f85c:	50410004 */ 	beql	$v0,$at,.L0f17f870
/*  f17f860:	00001025 */ 	or	$v0,$zero,$zero
/*  f17f864:	10000002 */ 	beqz	$zero,.L0f17f870
/*  f17f868:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f17f86c:
/*  f17f86c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17f870:
/*  f17f870:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f17f874:
/*  f17f874:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f17f878:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f17f87c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f17f880:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f17f884:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f17f888:	03e00008 */ 	jr	$ra
/*  f17f88c:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

s32 menuhandlerMpQuickTeamOption(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_Vars.mpquickteam = item->param;

		if (func0f18961c() >= func0f189058(0)) {
			func0f1895bc(0);
		}

		if (g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSONLY ||
				g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSANDSIMS) {
			if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL ||
					g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE) {
				g_MpSetup.scenario = MPSCENARIO_COMBAT;
			}
		}

		menuPushDialog(&g_MpQuickTeamGameSetupMenuDialog);
	}

	return 0;
}

bool menudialogCombatSimulator(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	if (operation == MENUOP_100) {
		g_Vars.unk000494 = 0;
		g_Vars.unk000495 = 0;
		g_Vars.unk000496 = 0;
		g_Vars.unk000497 = 0;
	}

	if (g_MenuStack[g_MpPlayerNum].unk00 &&
			g_MenuStack[g_MpPlayerNum].unk00->dialog == &g_CombatSimulatorMenuDialog &&
			operation == MENUOP_102) {
		g_Vars.unk000490 = 2;
		g_Vars.mpquickteam = MPQUICKTEAM_5;
		g_Vars.unk00049c = 0;
		mpResetVar800884b4();
		func0f19c220();
	}

	return false;
}

s32 menuhandlerMpAdvancedSetup(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f0f820c(&menudialog_mpgamesetup3, 3);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f17fa28
/*  f17fa28:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f17fa2c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f17fa30:	3c1f8007 */ 	lui	$ra,0x8007
/*  f17fa34:	27ff1448 */ 	addiu	$ra,$ra,0x1448
/*  f17fa38:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f17fa3c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f17fa40:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f17fa44:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f17fa48:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f17fa4c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f17fa50:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f17fa54:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f17fa58:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f17fa5c:	3c118008 */ 	lui	$s1,%hi(menudialog_mpsavesetupname)
/*  f17fa60:	3c128008 */ 	lui	$s2,%hi(menudialog_mpsavesetup)
/*  f17fa64:	3c138008 */ 	lui	$s3,%hi(g_MpAddSimulantMenuDialog)
/*  f17fa68:	3c148008 */ 	lui	$s4,%hi(g_MpChangeSimulantMenuDialog)
/*  f17fa6c:	3c158008 */ 	lui	$s5,%hi(menudialog_mpeditsimulant)
/*  f17fa70:	3c168008 */ 	lui	$s6,%hi(menudialog_mpcombatoptions)
/*  f17fa74:	3c178008 */ 	lui	$s7,%hi(menudialog_mpbriefcaseoptions)
/*  f17fa78:	3c1e8008 */ 	lui	$s8,%hi(menudialog_mpcaptureoptions)
/*  f17fa7c:	3c098008 */ 	lui	$t1,%hi(menudialog_mppopacapoptions)
/*  f17fa80:	3c088008 */ 	lui	$t0,%hi(menudialog_mphackeroptions)
/*  f17fa84:	3c078008 */ 	lui	$a3,%hi(menudialog_mphilloptions)
/*  f17fa88:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17fa8c:	24e76ce0 */ 	addiu	$a3,$a3,%lo(menudialog_mphilloptions)
/*  f17fa90:	25086dfc */ 	addiu	$t0,$t0,%lo(menudialog_mphackeroptions)
/*  f17fa94:	25296f80 */ 	addiu	$t1,$t1,%lo(menudialog_mppopacapoptions)
/*  f17fa98:	27de6b48 */ 	addiu	$s8,$s8,%lo(menudialog_mpcaptureoptions)
/*  f17fa9c:	26f769d4 */ 	addiu	$s7,$s7,%lo(menudialog_mpbriefcaseoptions)
/*  f17faa0:	26d668b8 */ 	addiu	$s6,$s6,%lo(menudialog_mpcombatoptions)
/*  f17faa4:	26b5592c */ 	addiu	$s5,$s5,%lo(menudialog_mpeditsimulant)
/*  f17faa8:	26945834 */ 	addiu	$s4,$s4,%lo(g_MpChangeSimulantMenuDialog)
/*  f17faac:	2673581c */ 	addiu	$s3,$s3,%lo(g_MpAddSimulantMenuDialog)
/*  f17fab0:	26524d80 */ 	addiu	$s2,$s2,%lo(menudialog_mpsavesetup)
/*  f17fab4:	26314cdc */ 	addiu	$s1,$s1,%lo(menudialog_mpsavesetupname)
/*  f17fab8:	00001025 */ 	or	$v0,$zero,$zero
/*  f17fabc:	afae0040 */ 	sw	$t6,0x40($sp)
/*  f17fac0:	0002c0c0 */ 	sll	$t8,$v0,0x3
.L0f17fac4:
/*  f17fac4:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f17fac8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f17facc:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f17fad0:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f17fad4:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f17fad8:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f17fadc:	3c19800a */ 	lui	$t9,0x800a
/*  f17fae0:	afe20000 */ 	sw	$v0,0x0($ra)
/*  f17fae4:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f17fae8:	8f39e4f8 */ 	lw	$t9,-0x1b08($t9)
/*  f17faec:	5320005f */ 	beqzl	$t9,.L0f17fc6c
/*  f17faf0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f17faf4:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f17faf8:	8fe20000 */ 	lw	$v0,0x0($ra)
.L0f17fafc:
/*  f17fafc:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f17fb00:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
/*  f17fb04:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f17fb08:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f17fb0c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17fb10:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f17fb14:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f17fb18:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f17fb1c:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f17fb20:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f17fb24:	870d04f4 */ 	lh	$t5,0x4f4($t8)
/*  f17fb28:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f17fb2c:	00005025 */ 	or	$t2,$zero,$zero
/*  f17fb30:	19a0003e */ 	blez	$t5,.L0f17fc2c
/*  f17fb34:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f17fb38:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f17fb3c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17fb40:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f17fb44:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17fb48:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f17fb4c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17fb50:	032f6021 */ 	addu	$t4,$t9,$t7
/*  f17fb54:	01805825 */ 	or	$t3,$t4,$zero
.L0f17fb58:
/*  f17fb58:	81620478 */ 	lb	$v0,0x478($t3)
/*  f17fb5c:	000a7080 */ 	sll	$t6,$t2,0x2
/*  f17fb60:	01ca7023 */ 	subu	$t6,$t6,$t2
/*  f17fb64:	1840002d */ 	blez	$v0,.L0f17fc1c
/*  f17fb68:	00002025 */ 	or	$a0,$zero,$zero
/*  f17fb6c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f17fb70:	018e2821 */ 	addu	$a1,$t4,$t6
/*  f17fb74:	00023080 */ 	sll	$a2,$v0,0x2
.L0f17fb78:
/*  f17fb78:	8ca30464 */ 	lw	$v1,0x464($a1)
/*  f17fb7c:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f17fb80:	0086082a */ 	slt	$at,$a0,$a2
/*  f17fb84:	10600023 */ 	beqz	$v1,.L0f17fc14
/*  f17fb88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fb8c:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f17fb90:	14510002 */ 	bne	$v0,$s1,.L0f17fb9c
/*  f17fb94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fb98:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fb9c:
/*  f17fb9c:	14520002 */ 	bne	$v0,$s2,.L0f17fba8
/*  f17fba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fba4:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fba8:
/*  f17fba8:	14530002 */ 	bne	$v0,$s3,.L0f17fbb4
/*  f17fbac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fbb0:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbb4:
/*  f17fbb4:	14540002 */ 	bne	$v0,$s4,.L0f17fbc0
/*  f17fbb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fbbc:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbc0:
/*  f17fbc0:	14550002 */ 	bne	$v0,$s5,.L0f17fbcc
/*  f17fbc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fbc8:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbcc:
/*  f17fbcc:	14560002 */ 	bne	$v0,$s6,.L0f17fbd8
/*  f17fbd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fbd4:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbd8:
/*  f17fbd8:	14570002 */ 	bne	$v0,$s7,.L0f17fbe4
/*  f17fbdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fbe0:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbe4:
/*  f17fbe4:	145e0002 */ 	bne	$v0,$s8,.L0f17fbf0
/*  f17fbe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fbec:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbf0:
/*  f17fbf0:	14470002 */ 	bne	$v0,$a3,.L0f17fbfc
/*  f17fbf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fbf8:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbfc:
/*  f17fbfc:	14480002 */ 	bne	$v0,$t0,.L0f17fc08
/*  f17fc00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fc04:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fc08:
/*  f17fc08:	14490002 */ 	bne	$v0,$t1,.L0f17fc14
/*  f17fc0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fc10:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fc14:
/*  f17fc14:	1420ffd8 */ 	bnez	$at,.L0f17fb78
/*  f17fc18:	24a50004 */ 	addiu	$a1,$a1,0x4
.L0f17fc1c:
/*  f17fc1c:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f17fc20:	014d082a */ 	slt	$at,$t2,$t5
/*  f17fc24:	1420ffcc */ 	bnez	$at,.L0f17fb58
/*  f17fc28:	256b0018 */ 	addiu	$t3,$t3,0x18
.L0f17fc2c:
/*  f17fc2c:	1600000b */ 	bnez	$s0,.L0f17fc5c
/*  f17fc30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fc34:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f17fc38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fc3c:	3c078008 */ 	lui	$a3,%hi(menudialog_mphilloptions)
/*  f17fc40:	3c088008 */ 	lui	$t0,%hi(menudialog_mphackeroptions)
/*  f17fc44:	3c098008 */ 	lui	$t1,%hi(menudialog_mppopacapoptions)
/*  f17fc48:	3c1f8007 */ 	lui	$ra,0x8007
/*  f17fc4c:	27ff1448 */ 	addiu	$ra,$ra,0x1448
/*  f17fc50:	25296f80 */ 	addiu	$t1,$t1,%lo(menudialog_mppopacapoptions)
/*  f17fc54:	25086dfc */ 	addiu	$t0,$t0,%lo(menudialog_mphackeroptions)
/*  f17fc58:	24e76ce0 */ 	addiu	$a3,$a3,%lo(menudialog_mphilloptions)
.L0f17fc5c:
/*  f17fc5c:	5200ffa7 */ 	beqzl	$s0,.L0f17fafc
/*  f17fc60:	8fe20000 */ 	lw	$v0,0x0($ra)
/*  f17fc64:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f17fc68:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f17fc6c:
/*  f17fc6c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f17fc70:	5441ff94 */ 	bnel	$v0,$at,.L0f17fac4
/*  f17fc74:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f17fc78:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f17fc7c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f17fc80:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f17fc84:	aff80000 */ 	sw	$t8,0x0($ra)
/*  f17fc88:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f17fc8c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f17fc90:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f17fc94:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f17fc98:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f17fc9c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f17fca0:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f17fca4:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f17fca8:	03e00008 */ 	jr	$ra
/*  f17fcac:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f17fcb0
/*  f17fcb0:	3c028007 */ 	lui	$v0,0x8007
/*  f17fcb4:	8c421448 */ 	lw	$v0,0x1448($v0)
/*  f17fcb8:	3c01800a */ 	lui	$at,0x800a
/*  f17fcbc:	3c0f8009 */ 	lui	$t7,0x8009
/*  f17fcc0:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f17fcc4:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f17fcc8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17fccc:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f17fcd0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f17fcd4:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f17fcd8:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f17fcdc:	91ef0af0 */ 	lbu	$t7,0xaf0($t7)
/*  f17fce0:	002e0821 */ 	addu	$at,$at,$t6
/*  f17fce4:	a022e83b */ 	sb	$v0,-0x17c5($at)
/*  f17fce8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f17fcec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17fcf0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f17fcf4:	15e10009 */ 	bne	$t7,$at,.L0f17fd1c
/*  f17fcf8:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f17fcfc:	3c048007 */ 	lui	$a0,%hi(g_4MbAdvancedSetupMenuDialog)
/*  f17fd00:	24845538 */ 	addiu	$a0,$a0,%lo(g_4MbAdvancedSetupMenuDialog)
/*  f17fd04:	0fc3e0cc */ 	jal	func0f0f8330
/*  f17fd08:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f17fd0c:	0fc3e0c0 */ 	jal	func0f0f8300
/*  f17fd10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fd14:	10000012 */ 	beqz	$zero,.L0f17fd60
/*  f17fd18:	8fb90028 */ 	lw	$t9,0x28($sp)
.L0f17fd1c:
/*  f17fd1c:	3c18800b */ 	lui	$t8,0x800b
/*  f17fd20:	9318cc10 */ 	lbu	$t8,-0x33f0($t8)
/*  f17fd24:	24010005 */ 	addiu	$at,$zero,0x5
/*  f17fd28:	3c048008 */ 	lui	$a0,%hi(menudialog_mpgamesetup3)
/*  f17fd2c:	17010007 */ 	bne	$t8,$at,.L0f17fd4c
/*  f17fd30:	2484646c */ 	addiu	$a0,$a0,%lo(menudialog_mpgamesetup3)
/*  f17fd34:	3c048008 */ 	lui	$a0,%hi(menudialog_mpchallengedetails2)
/*  f17fd38:	24846030 */ 	addiu	$a0,$a0,%lo(menudialog_mpchallengedetails2)
/*  f17fd3c:	0fc3e0cc */ 	jal	func0f0f8330
/*  f17fd40:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f17fd44:	10000003 */ 	beqz	$zero,.L0f17fd54
/*  f17fd48:	00000000 */ 	sll	$zero,$zero,0x0
.L0f17fd4c:
/*  f17fd4c:	0fc3e0cc */ 	jal	func0f0f8330
/*  f17fd50:	24050003 */ 	addiu	$a1,$zero,0x3
.L0f17fd54:
/*  f17fd54:	0fc3e0c0 */ 	jal	func0f0f8300
/*  f17fd58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fd5c:	8fb90028 */ 	lw	$t9,0x28($sp)
.L0f17fd60:
/*  f17fd60:	3c048009 */ 	lui	$a0,0x8009
/*  f17fd64:	2405809a */ 	addiu	$a1,$zero,-32614
/*  f17fd68:	1720000d */ 	bnez	$t9,.L0f17fda0
/*  f17fd6c:	00003025 */ 	or	$a2,$zero,$zero
/*  f17fd70:	3c01bf80 */ 	lui	$at,0xbf80
/*  f17fd74:	44812000 */ 	mtc1	$at,$f4
/*  f17fd78:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f17fd7c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f17fd80:	240affff */ 	addiu	$t2,$zero,-1
/*  f17fd84:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f17fd88:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f17fd8c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f17fd90:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f17fd94:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f17fd98:	0c004241 */ 	jal	func00010904
/*  f17fd9c:	e7a40014 */ 	swc1	$f4,0x14($sp)
.L0f17fda0:
/*  f17fda0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f17fda4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f17fda8:	03e00008 */ 	jr	$ra
/*  f17fdac:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMpDisplayTeam(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
			return false;
		}

		return true;
	}

	return menuhandlerMpCheckboxOption(operation, item, value);
}

s32 menuhandlerMpOneHitKills(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKDISABLED || operation == MENUOP_CHECKHIDDEN) {
		if (mpIsChallengeComplete(CHALLENGE_7)) {
			return false;
		}

		return true;
	}

	return menuhandlerMpCheckboxOption(operation, item, value);
}

GLOBAL_ASM(
glabel menuhandlerMpSlowMotion
/*  f17fe50:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f17fe54:	3c0e8008 */ 	lui	$t6,%hi(mpslowmotionoptions)
/*  f17fe58:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17fe5c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f17fe60:	25ce67c0 */ 	addiu	$t6,$t6,%lo(mpslowmotionoptions)
/*  f17fe64:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f17fe68:	27a20020 */ 	addiu	$v0,$sp,0x20
/*  f17fe6c:	2488ffff */ 	addiu	$t0,$a0,-1
/*  f17fe70:	ac410000 */ 	sw	$at,0x0($v0)
/*  f17fe74:	95c10004 */ 	lhu	$at,0x4($t6)
/*  f17fe78:	a4410004 */ 	sh	$at,0x4($v0)
/*  f17fe7c:	2d010018 */ 	sltiu	$at,$t0,0x18
/*  f17fe80:	1020003a */ 	beqz	$at,.L0f17ff6c
/*  f17fe84:	00084080 */ 	sll	$t0,$t0,0x2
/*  f17fe88:	3c017f1c */ 	lui	$at,%hi(var7f1b88dc)
/*  f17fe8c:	00280821 */ 	addu	$at,$at,$t0
/*  f17fe90:	8c2888dc */ 	lw	$t0,%lo(var7f1b88dc)($at)
/*  f17fe94:	01000008 */ 	jr	$t0
/*  f17fe98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17fe9c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f17fea0:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f17fea4:	10400003 */ 	beqz	$v0,.L0f17feb4
/*  f17fea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17feac:	10000030 */ 	beqz	$zero,.L0f17ff70
/*  f17feb0:	00001025 */ 	or	$v0,$zero,$zero
.L0f17feb4:
/*  f17feb4:	1000002e */ 	beqz	$zero,.L0f17ff70
/*  f17feb8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f17febc:	24090003 */ 	addiu	$t1,$zero,0x3
/*  f17fec0:	1000002a */ 	beqz	$zero,.L0f17ff6c
/*  f17fec4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f17fec8:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f17fecc:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f17fed0:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f17fed4:	0fc5b9f1 */ 	jal	textGet
/*  f17fed8:	95840000 */ 	lhu	$a0,0x0($t4)
/*  f17fedc:	10000025 */ 	beqz	$zero,.L0f17ff74
/*  f17fee0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17fee4:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f17fee8:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f17feec:	8c4d000c */ 	lw	$t5,0xc($v0)
/*  f17fef0:	2401ff3f */ 	addiu	$at,$zero,-193
/*  f17fef4:	01a1c024 */ 	and	$t8,$t5,$at
/*  f17fef8:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f17fefc:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f17ff00:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17ff04:	370e0040 */ 	ori	$t6,$t8,0x40
/*  f17ff08:	54610004 */ 	bnel	$v1,$at,.L0f17ff1c
/*  f17ff0c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f17ff10:	10000016 */ 	beqz	$zero,.L0f17ff6c
/*  f17ff14:	ac4e000c */ 	sw	$t6,0xc($v0)
/*  f17ff18:	24010002 */ 	addiu	$at,$zero,0x2
.L0f17ff1c:
/*  f17ff1c:	54610014 */ 	bnel	$v1,$at,.L0f17ff70
/*  f17ff20:	00001025 */ 	or	$v0,$zero,$zero
/*  f17ff24:	8c59000c */ 	lw	$t9,0xc($v0)
/*  f17ff28:	37280080 */ 	ori	$t0,$t9,0x80
/*  f17ff2c:	1000000f */ 	beqz	$zero,.L0f17ff6c
/*  f17ff30:	ac48000c */ 	sw	$t0,0xc($v0)
/*  f17ff34:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f17ff38:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f17ff3c:	8c43000c */ 	lw	$v1,0xc($v0)
/*  f17ff40:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f17ff44:	30690080 */ 	andi	$t1,$v1,0x80
/*  f17ff48:	11200003 */ 	beqz	$t1,.L0f17ff58
/*  f17ff4c:	306b0040 */ 	andi	$t3,$v1,0x40
/*  f17ff50:	10000006 */ 	beqz	$zero,.L0f17ff6c
/*  f17ff54:	acca0000 */ 	sw	$t2,0x0($a2)
.L0f17ff58:
/*  f17ff58:	11600003 */ 	beqz	$t3,.L0f17ff68
/*  f17ff5c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f17ff60:	10000002 */ 	beqz	$zero,.L0f17ff6c
/*  f17ff64:	accc0000 */ 	sw	$t4,0x0($a2)
.L0f17ff68:
/*  f17ff68:	acc00000 */ 	sw	$zero,0x0($a2)
.L0f17ff6c:
/*  f17ff6c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17ff70:
/*  f17ff70:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17ff74:
/*  f17ff74:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f17ff78:	03e00008 */ 	jr	$ra
/*  f17ff7c:	00000000 */ 	sll	$zero,$zero,0x0
);

void scenarioHtbInit(void)
{
	g_ScenarioData.htb.token = NULL;
}

GLOBAL_ASM(
glabel func0f17ff8c
/*  f17ff8c:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f17ff90:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f17ff94:	84580018 */ 	lh	$t8,0x18($v0)
/*  f17ff98:	00047400 */ 	sll	$t6,$a0,0x10
/*  f17ff9c:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f17ffa0:	2b01003c */ 	slti	$at,$t8,0x3c
/*  f17ffa4:	1020000b */ 	beqz	$at,.L0f17ffd4
/*  f17ffa8:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f17ffac:	3c19800b */ 	lui	$t9,0x800b
/*  f17ffb0:	8739c128 */ 	lh	$t9,-0x3ed8($t9)
/*  f17ffb4:	3c0a800b */ 	lui	$t2,0x800b
/*  f17ffb8:	3c01800b */ 	lui	$at,0x800b
/*  f17ffbc:	00194040 */ 	sll	$t0,$t9,0x1
/*  f17ffc0:	00484821 */ 	addu	$t1,$v0,$t0
/*  f17ffc4:	a52f001a */ 	sh	$t7,0x1a($t1)
/*  f17ffc8:	854ac128 */ 	lh	$t2,-0x3ed8($t2)
/*  f17ffcc:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f17ffd0:	a42bc128 */ 	sh	$t3,-0x3ed8($at)
.L0f17ffd4:
/*  f17ffd4:	03e00008 */ 	jr	$ra
/*  f17ffd8:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 scenarioHtbCallback08(void)
{
	return 1;
}

GLOBAL_ASM(
glabel func0f17ffe4
/*  f17ffe4:	3c02800a */ 	lui	$v0,0x800a
/*  f17ffe8:	8c42a2fc */ 	lw	$v0,-0x5d04($v0)
/*  f17ffec:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f17fff0:	00047400 */ 	sll	$t6,$a0,0x10
/*  f17fff4:	1040001e */ 	beqz	$v0,.L0f180070
/*  f17fff8:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f17fffc:	240900c1 */ 	addiu	$t1,$zero,0xc1
/*  f180000:	24080014 */ 	addiu	$t0,$zero,0x14
/*  f180004:	24070007 */ 	addiu	$a3,$zero,0x7
/*  f180008:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18000c:	90580000 */ 	lbu	$t8,0x0($v0)
.L0f180010:
/*  f180010:	54d80015 */ 	bnel	$a2,$t8,.L0f180068
/*  f180014:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f180018:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f18001c:	84790006 */ 	lh	$t9,0x6($v1)
/*  f180020:	54990011 */ 	bnel	$a0,$t9,.L0f180068
/*  f180024:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f180028:	90650003 */ 	lbu	$a1,0x3($v1)
/*  f18002c:	50e50004 */ 	beql	$a3,$a1,.L0f180040
/*  f180030:	846a0004 */ 	lh	$t2,0x4($v1)
/*  f180034:	5505000c */ 	bnel	$t0,$a1,.L0f180068
/*  f180038:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f18003c:	846a0004 */ 	lh	$t2,0x4($v1)
.L0f180040:
/*  f180040:	552a0009 */ 	bnel	$t1,$t2,.L0f180068
/*  f180044:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f180048:	8c6b0040 */ 	lw	$t3,0x40($v1)
/*  f18004c:	906d0002 */ 	lbu	$t5,0x2($v1)
/*  f180050:	356c0004 */ 	ori	$t4,$t3,0x4
/*  f180054:	31aefffb */ 	andi	$t6,$t5,0xfffb
/*  f180058:	ac6c0040 */ 	sw	$t4,0x40($v1)
/*  f18005c:	03e00008 */ 	jr	$ra
/*  f180060:	a06e0002 */ 	sb	$t6,0x2($v1)
/*  f180064:	8c420020 */ 	lw	$v0,0x20($v0)
.L0f180068:
/*  f180068:	5440ffe9 */ 	bnezl	$v0,.L0f180010
/*  f18006c:	90580000 */ 	lbu	$t8,0x0($v0)
.L0f180070:
/*  f180070:	03e00008 */ 	jr	$ra
/*  f180074:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f180078
/*  f180078:	3c01800b */ 	lui	$at,0x800b
/*  f18007c:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f180080:	3c04800b */ 	lui	$a0,0x800b
/*  f180084:	a420c128 */ 	sh	$zero,-0x3ed8($at)
/*  f180088:	2484c188 */ 	addiu	$a0,$a0,-15992
/*  f18008c:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f180090:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f180094:
/*  f180094:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f180098:	1464fffe */ 	bne	$v1,$a0,.L0f180094
/*  f18009c:	a4620018 */ 	sh	$v0,0x18($v1)
/*  f1800a0:	03e00008 */ 	jr	$ra
/*  f1800a4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1800a8
/*  f1800a8:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f1800ac:	3c0f8008 */ 	lui	$t7,%hi(var800869f0)
/*  f1800b0:	25ef69f0 */ 	addiu	$t7,$t7,%lo(var800869f0)
/*  f1800b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1800b8:	25e80060 */ 	addiu	$t0,$t7,0x60
/*  f1800bc:	27ae0080 */ 	addiu	$t6,$sp,0x80
.L0f1800c0:
/*  f1800c0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1800c4:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f1800c8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1800cc:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f1800d0:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f1800d4:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f1800d8:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f1800dc:	15e8fff8 */ 	bne	$t7,$t0,.L0f1800c0
/*  f1800e0:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f1800e4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1800e8:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1800ec:	3c02800a */ 	lui	$v0,0x800a
/*  f1800f0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1800f4:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1800f8:	8c42a2fc */ 	lw	$v0,-0x5d04($v0)
/*  f1800fc:	00002025 */ 	or	$a0,$zero,$zero
/*  f180100:	27a70024 */ 	addiu	$a3,$sp,0x24
/*  f180104:	10400013 */ 	beqz	$v0,.L0f180154
/*  f180108:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f18010c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f180110:	90490000 */ 	lbu	$t1,0x0($v0)
.L0f180114:
/*  f180114:	54a9000a */ 	bnel	$a1,$t1,.L0f180140
/*  f180118:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f18011c:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f180120:	00045880 */ 	sll	$t3,$a0,0x2
/*  f180124:	00eb6021 */ 	addu	$t4,$a3,$t3
/*  f180128:	906a0003 */ 	lbu	$t2,0x3($v1)
/*  f18012c:	54ca0004 */ 	bnel	$a2,$t2,.L0f180140
/*  f180130:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f180134:	ad830000 */ 	sw	$v1,0x0($t4)
/*  f180138:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18013c:	8c420020 */ 	lw	$v0,0x20($v0)
.L0f180140:
/*  f180140:	28810014 */ 	slti	$at,$a0,0x14
/*  f180144:	10400003 */ 	beqz	$v0,.L0f180154
/*  f180148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18014c:	5420fff1 */ 	bnezl	$at,.L0f180114
/*  f180150:	90490000 */ 	lbu	$t1,0x0($v0)
.L0f180154:
/*  f180154:	1880001c */ 	blez	$a0,.L0f1801c8
/*  f180158:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18015c:	0c004b70 */ 	jal	random
/*  f180160:	afa40074 */ 	sw	$a0,0x74($sp)
/*  f180164:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f180168:	27a70024 */ 	addiu	$a3,$sp,0x24
/*  f18016c:	3c058008 */ 	lui	$a1,%hi(var800869ec)
/*  f180170:	0044001b */ 	divu	$zero,$v0,$a0
/*  f180174:	24a569ec */ 	addiu	$a1,$a1,%lo(var800869ec)
/*  f180178:	3c06800b */ 	lui	$a2,%hi(g_ScenarioData)
/*  f18017c:	24c6c110 */ 	addiu	$a2,$a2,%lo(g_ScenarioData)
/*  f180180:	14800002 */ 	bnez	$a0,.L0f18018c
/*  f180184:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180188:	0007000d */ 	break	0x7
.L0f18018c:
/*  f18018c:	00002010 */ 	mfhi	$a0
/*  f180190:	00046880 */ 	sll	$t5,$a0,0x2
/*  f180194:	00edc821 */ 	addu	$t9,$a3,$t5
/*  f180198:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f18019c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1801a0:	87080006 */ 	lh	$t0,0x6($t8)
/*  f1801a4:	acc80014 */ 	sw	$t0,0x14($a2)
/*  f1801a8:	8f0f0040 */ 	lw	$t7,0x40($t8)
/*  f1801ac:	35ee0004 */ 	ori	$t6,$t7,0x4
/*  f1801b0:	af0e0040 */ 	sw	$t6,0x40($t8)
/*  f1801b4:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f1801b8:	90690002 */ 	lbu	$t1,0x2($v1)
/*  f1801bc:	352a0004 */ 	ori	$t2,$t1,0x4
/*  f1801c0:	10000017 */ 	beqz	$zero,.L0f180220
/*  f1801c4:	a06a0002 */ 	sb	$t2,0x2($v1)
.L0f1801c8:
/*  f1801c8:	3c06800b */ 	lui	$a2,%hi(g_ScenarioData)
/*  f1801cc:	24c6c110 */ 	addiu	$a2,$a2,%lo(g_ScenarioData)
/*  f1801d0:	84cb0018 */ 	lh	$t3,0x18($a2)
/*  f1801d4:	59600012 */ 	blezl	$t3,.L0f180220
/*  f1801d8:	acc00014 */ 	sw	$zero,0x14($a2)
/*  f1801dc:	0c004b70 */ 	jal	random
/*  f1801e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1801e4:	3c06800b */ 	lui	$a2,%hi(g_ScenarioData)
/*  f1801e8:	24c6c110 */ 	addiu	$a2,$a2,%lo(g_ScenarioData)
/*  f1801ec:	84cc0018 */ 	lh	$t4,0x18($a2)
/*  f1801f0:	004c001b */ 	divu	$zero,$v0,$t4
/*  f1801f4:	00006810 */ 	mfhi	$t5
/*  f1801f8:	000dc840 */ 	sll	$t9,$t5,0x1
/*  f1801fc:	00d9c021 */ 	addu	$t8,$a2,$t9
/*  f180200:	8708001a */ 	lh	$t0,0x1a($t8)
/*  f180204:	15800002 */ 	bnez	$t4,.L0f180210
/*  f180208:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18020c:	0007000d */ 	break	0x7
.L0f180210:
/*  f180210:	acc80014 */ 	sw	$t0,0x14($a2)
/*  f180214:	10000002 */ 	beqz	$zero,.L0f180220
/*  f180218:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18021c:	acc00014 */ 	sw	$zero,0x14($a2)
.L0f180220:
/*  f180220:	3c04800b */ 	lui	$a0,%hi(var800ac258)
/*  f180224:	2484c258 */ 	addiu	$a0,$a0,%lo(var800ac258)
/*  f180228:	27af0080 */ 	addiu	$t7,$sp,0x80
/*  f18022c:	25e90060 */ 	addiu	$t1,$t7,0x60
/*  f180230:	00805025 */ 	or	$t2,$a0,$zero
.L0f180234:
/*  f180234:	8de10000 */ 	lw	$at,0x0($t7)
/*  f180238:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f18023c:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f180240:	ad41fff4 */ 	sw	$at,-0xc($t2)
/*  f180244:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f180248:	ad41fff8 */ 	sw	$at,-0x8($t2)
/*  f18024c:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f180250:	15e9fff8 */ 	bne	$t7,$t1,.L0f180234
/*  f180254:	ad41fffc */ 	sw	$at,-0x4($t2)
/*  f180258:	8de10000 */ 	lw	$at,0x0($t7)
/*  f18025c:	240503e7 */ 	addiu	$a1,$zero,0x3e7
/*  f180260:	ad410000 */ 	sw	$at,0x0($t2)
/*  f180264:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f180268:	ad490004 */ 	sw	$t1,0x4($t2)
/*  f18026c:	8ccb0014 */ 	lw	$t3,0x14($a2)
/*  f180270:	0fc0359c */ 	jal	func0f00d670
/*  f180274:	a48b0006 */ 	sh	$t3,0x6($a0)
/*  f180278:	3c04800b */ 	lui	$a0,%hi(var800ac258)
/*  f18027c:	2484c258 */ 	addiu	$a0,$a0,%lo(var800ac258)
/*  f180280:	908c0002 */ 	lbu	$t4,0x2($a0)
/*  f180284:	8c990014 */ 	lw	$t9,0x14($a0)
/*  f180288:	3c06800b */ 	lui	$a2,%hi(g_ScenarioData)
/*  f18028c:	24c6c110 */ 	addiu	$a2,$a2,%lo(g_ScenarioData)
/*  f180290:	318dfffb */ 	andi	$t5,$t4,0xfffb
/*  f180294:	a08d0002 */ 	sb	$t5,0x2($a0)
/*  f180298:	13200004 */ 	beqz	$t9,.L0f1802ac
/*  f18029c:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f1802a0:	9328003f */ 	lbu	$t0,0x3f($t9)
/*  f1802a4:	350e0020 */ 	ori	$t6,$t0,0x20
/*  f1802a8:	a32e003f */ 	sb	$t6,0x3f($t9)
.L0f1802ac:
/*  f1802ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1802b0:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f1802b4:	03e00008 */ 	jr	$ra
/*  f1802b8:	00000000 */ 	sll	$zero,$zero,0x0
);

void scenarioHtbReset(void)
{
	var800869ec = 0;
	func0f1800a8();
}

void scenarioHtbCallback10(void)
{
	s32 i;
	u32 prevplayernum = g_Vars.currentplayernum;
	struct prop *prop;

	if (var800869ec && var800869ec->prop) {
		if (g_ScenarioData.htb.token == NULL || g_ScenarioData.htb.token->type != PROPTYPE_WEAPON) {
			var800869ec = NULL;
		} else {
			var800869ec->prop->timetoregen = 1200;
		}
	}

	g_ScenarioData.htb.token = NULL;

	// Check if briefcase is on the ground
	prop = g_Vars.unk00033c;

	while (prop) {
		if (prop->type == PROPTYPE_WEAPON) {
			struct weaponobj *weapon = prop->weapon;

			if (weapon->weapon_id == WEAPON_BRIEFCASE2) {
				g_ScenarioData.htb.token = prop;
			}
		}

		prop = prop->next;
	}

	// Check if a player is holding it
	if (g_ScenarioData.htb.token == NULL) {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);

			if (func0f112844()) {
				g_ScenarioData.htb.token = g_Vars.currentplayer->prop;
				break;
			}
		}
	}

	setCurrentPlayerNum(prevplayernum);

	// Check if a simulant is holding it
	if (g_ScenarioData.htb.token == NULL) {
		for (i = PLAYERCOUNT(); i < g_MpNumPlayers; i++) {
			if (g_MpPlayerChrs[i]->prop && g_MpPlayerChrs[i]->unk2d4->unk09c_00) {
				g_ScenarioData.htb.token = g_MpPlayerChrs[i]->prop;
				break;
			}
		}
	}

	if (g_ScenarioData.htb.token == NULL) {
		func0f1800a8();
	}

	if (g_ScenarioData.htb.token == NULL) {
		g_ScenarioData.htb.pos.x = 0;
		g_ScenarioData.htb.pos.y = 0;
		g_ScenarioData.htb.pos.z = 0;
	} else {
		struct coord *pos = &g_ScenarioData.htb.pos;
		pos->x = g_ScenarioData.htb.token->pos.x;
		pos->y = g_ScenarioData.htb.token->pos.y;
		pos->z = g_ScenarioData.htb.token->pos.z;
	}
}

void scenarioHtbCallback14(struct chrdata *chr)
{
	if (chr) {
		if (chr->unk2d4->unk09c_00) {
			chr->unk2d4->unk0a0 += g_Vars.lvupdate240;

			if (chr->unk2d4->unk0a0 >= SECSTOFRAMES240(30)) {
				func00010904(var80095200, 0x5b8, 0, -1, -1, -1, -1, -1);
				var800ac500[mpPlayerGetIndex(chr)]->unk3e++;
				chr->unk2d4->unk0a0 = 0;
			}
		} else {
			chr->unk2d4->unk0a0 = 0;
		}
	} else {
		if (func0f112844()) {
			g_Vars.unk000288->unk60 += g_Vars.lvupdate240;

			if (g_Vars.unk000288->unk60 >= SECSTOFRAMES240(30)) {
				func00010904(var80095200, 0x5b8, 0, -1, -1, -1, -1, -1);
				var800ac500[g_Vars.currentplayernum]->unk3e++;
				func0f0ddfa4(textGet(0x5418), 9, 1);
				g_Vars.unk000288->unk60 = 0;
			}
		} else {
			g_Vars.unk000288->unk60 = 0;
		}
	}
}

GLOBAL_ASM(
glabel scenarioHtbCallback18
/*  f18079c:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f1807a0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1807a4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1807a8:	0fc44a11 */ 	jal	func0f112844
/*  f1807ac:	00808025 */ 	or	$s0,$a0,$zero
/*  f1807b0:	50400067 */ 	beqzl	$v0,.L0f180950
/*  f1807b4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1807b8:	0c002f40 */ 	jal	func0000bd00
/*  f1807bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1807c0:	0c002f22 */ 	jal	func0000bc88
/*  f1807c4:	a7a2004a */ 	sh	$v0,0x4a($sp)
/*  f1807c8:	87af004a */ 	lh	$t7,0x4a($sp)
/*  f1807cc:	04410003 */ 	bgez	$v0,.L0f1807dc
/*  f1807d0:	00027043 */ 	sra	$t6,$v0,0x1
/*  f1807d4:	24410001 */ 	addiu	$at,$v0,0x1
/*  f1807d8:	00017043 */ 	sra	$t6,$at,0x1
.L0f1807dc:
/*  f1807dc:	01cf2821 */ 	addu	$a1,$t6,$t7
/*  f1807e0:	0c002f44 */ 	jal	func0000bd10
/*  f1807e4:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f1807e8:	3c19800a */ 	lui	$t9,0x800a
/*  f1807ec:	8f39a248 */ 	lw	$t9,-0x5db8($t9)
/*  f1807f0:	2458000a */ 	addiu	$t8,$v0,0xa
/*  f1807f4:	afb8008c */ 	sw	$t8,0x8c($sp)
/*  f1807f8:	8f2a0060 */ 	lw	$t2,0x60($t9)
/*  f1807fc:	24091c20 */ 	addiu	$t1,$zero,0x1c20
/*  f180800:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f180804:	012a1823 */ 	subu	$v1,$t1,$t2
/*  f180808:	0069001a */ 	div	$zero,$v1,$t1
/*  f18080c:	00004012 */ 	mflo	$t0
/*  f180810:	01003025 */ 	or	$a2,$t0,$zero
/*  f180814:	15200002 */ 	bnez	$t1,.L0f180820
/*  f180818:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18081c:	0007000d */ 	break	0x7
.L0f180820:
/*  f180820:	2401ffff */ 	addiu	$at,$zero,-1
/*  f180824:	15210004 */ 	bne	$t1,$at,.L0f180838
/*  f180828:	3c018000 */ 	lui	$at,0x8000
/*  f18082c:	14610002 */ 	bne	$v1,$at,.L0f180838
/*  f180830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180834:	0006000d */ 	break	0x6
.L0f180838:
/*  f180838:	01090019 */ 	multu	$t0,$t1
/*  f18083c:	240100f0 */ 	addiu	$at,$zero,0xf0
/*  f180840:	24a58490 */ 	addiu	$a1,$a1,-31600
/*  f180844:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f180848:	00005812 */ 	mflo	$t3
/*  f18084c:	006b1823 */ 	subu	$v1,$v1,$t3
/*  f180850:	246700ef */ 	addiu	$a3,$v1,0xef
/*  f180854:	00e1001a */ 	div	$zero,$a3,$at
/*  f180858:	00003812 */ 	mflo	$a3
/*  f18085c:	0c004dad */ 	jal	sprintf
/*  f180860:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180864:	0fc54d8a */ 	jal	func0f153628
/*  f180868:	02002025 */ 	or	$a0,$s0,$zero
/*  f18086c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f180870:	8dadfb04 */ 	lw	$t5,-0x4fc($t5)
/*  f180874:	3c078008 */ 	lui	$a3,0x8008
/*  f180878:	00408025 */ 	or	$s0,$v0,$zero
/*  f18087c:	8ce7fb08 */ 	lw	$a3,-0x4f8($a3)
/*  f180880:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f180884:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f180888:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*  f18088c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f180890:	0fc55cbe */ 	jal	func0f1572f8
/*  f180894:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f180898:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f18089c:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f1808a0:	8fa20094 */ 	lw	$v0,0x94($sp)
/*  f1808a4:	8fa6008c */ 	lw	$a2,0x8c($sp)
/*  f1808a8:	04e10003 */ 	bgez	$a3,.L0f1808b8
/*  f1808ac:	00077043 */ 	sra	$t6,$a3,0x1
/*  f1808b0:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f1808b4:	00017043 */ 	sra	$t6,$at,0x1
.L0f1808b8:
/*  f1808b8:	00ae2823 */ 	subu	$a1,$a1,$t6
/*  f1808bc:	00e53821 */ 	addu	$a3,$a3,$a1
/*  f1808c0:	00461021 */ 	addu	$v0,$v0,$a2
/*  f1808c4:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f1808c8:	afa20094 */ 	sw	$v0,0x94($sp)
/*  f1808cc:	afa70098 */ 	sw	$a3,0x98($sp)
/*  f1808d0:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f1808d4:	0fc54e64 */ 	jal	func0f153990
/*  f1808d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1808dc:	0c002f02 */ 	jal	func0000bc08
/*  f1808e0:	00408025 */ 	or	$s0,$v0,$zero
/*  f1808e4:	0c002f06 */ 	jal	func0000bc18
/*  f1808e8:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f1808ec:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1808f0:	3c188008 */ 	lui	$t8,0x8008
/*  f1808f4:	8f18fafc */ 	lw	$t8,-0x504($t8)
/*  f1808f8:	8deffb00 */ 	lw	$t7,-0x500($t7)
/*  f1808fc:	87ab0048 */ 	lh	$t3,0x48($sp)
/*  f180900:	3c1900ff */ 	lui	$t9,0xff
/*  f180904:	373900a0 */ 	ori	$t9,$t9,0xa0
/*  f180908:	240a00a0 */ 	addiu	$t2,$zero,0xa0
/*  f18090c:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f180910:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f180914:	02002025 */ 	or	$a0,$s0,$zero
/*  f180918:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f18091c:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f180920:	27a7004c */ 	addiu	$a3,$sp,0x4c
/*  f180924:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f180928:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f18092c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f180930:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f180934:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f180938:	0fc55b92 */ 	jal	func0f156e48
/*  f18093c:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f180940:	0fc54de0 */ 	jal	func0f153780
/*  f180944:	00402025 */ 	or	$a0,$v0,$zero
/*  f180948:	00408025 */ 	or	$s0,$v0,$zero
/*  f18094c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f180950:
/*  f180950:	02001025 */ 	or	$v0,$s0,$zero
/*  f180954:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f180958:	03e00008 */ 	jr	$ra
/*  f18095c:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

void scenarioHtbKill(struct mpchr *mpchr, s32 arg1, s32 *score, s32 *arg3)
{
	struct mpchr *loopmpchr;
	s32 i;

	*score = 0;
	*score = mpchr->unk3e;

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == arg1) {
				*score -= mpchr->unk24[i];
			} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				if (i < 4) {
					loopmpchr = &g_MpPlayers[i].base;
				} else {
					loopmpchr = &g_MpSimulants[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->unk24[i];
				} else {
					*score += mpchr->unk24[i];
				}
			} else {
				*score += mpchr->unk24[i];
			}
		}
	}

	*arg3 = mpchr->unk3c;
}

s32 scenarioHtbRadar(s32 value)
{
	if ((g_MpSetup.options & MPOPTION_SHOWONRADAR1) &&
			g_ScenarioData.htb.token != NULL &&
			g_ScenarioData.htb.token->type != PROPTYPE_PLAYER &&
			g_ScenarioData.htb.token->type != PROPTYPE_CHR) {
		struct coord dist;
		dist.x = g_ScenarioData.htb.pos.x - g_Vars.currentplayer->prop->pos.x;
		dist.y = g_ScenarioData.htb.pos.y - g_Vars.currentplayer->prop->pos.y;
		dist.z = g_ScenarioData.htb.pos.z - g_Vars.currentplayer->prop->pos.z;
		value = func0f18e9ec(value, g_ScenarioData.htb.token, &dist, 0xff0000, 0, 1);
	}

	return value;
}

bool scenarioHtbRadar2(s32 *displaylist, struct prop *prop)
{
	if ((g_MpSetup.options & MPOPTION_SHOWONRADAR1) &&
			g_ScenarioData.htb.token &&
			prop == g_ScenarioData.htb.token) {
		if (prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR) {
			struct coord dist;
			dist.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
			dist.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
			dist.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;

			if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				u32 colour = g_TeamColours[teamGetIndex(prop->chr->team)];
				*displaylist = func0f18e9ec(*displaylist, g_ScenarioData.htb.token, &dist, colour, 0, 1);
			} else {
				*displaylist = func0f18e9ec(*displaylist, g_ScenarioData.htb.token, &dist, 0xff0000, 0, 1);
			}

			return true;
		}
	}

	return false;
}

bool scenarioHtbHighlight(struct prop *prop, u32 *colour)
{
	if ((g_MpSetup.options & MPOPTION_HIGHLIGHTBRIEFCASE) && prop == g_ScenarioData.htb.token) {
		colour[0] = 0;
		colour[1] = 0xff;
		colour[2] = 0;
		colour[3] = 0x40;

		return true;
	}

	return false;
}

void scenarioCtcInit(void)
{
	s32 i, j, k;
	g_MpSetup.options |= MPOPTION_TEAMSENABLED;

	for (i = 0; i < 4; i++) {
		s32 j;
		g_ScenarioData.ctc.unk18[i].unk00 = i;
		g_ScenarioData.ctc.unk18[i].unk02 = 0;

		for (j = 0; j < 6; j++) {
			g_ScenarioData.ctc.unk18[i].unk04[j] = -1;
		}
	}

	for (i = 0; i != 4; i++) {
		g_ScenarioData.ctc.unk00[i] = 0;
		g_ScenarioData.ctc.unk08[i] = -1;
	}

	for (k = 0; k < MAX_MPCHRS; k++) {
		if (g_MpSetup.chrslots & (1 << k)) {
			struct mpchr *basedata;

			if (k < 4) {
				basedata = &g_MpPlayers[k].base;
			} else {
				basedata = &g_MpSimulants[k - 4].base;
			}

			while (basedata->team >= scenarioGetMaxTeams()) {
				basedata->team -= scenarioGetMaxTeams();
			}
		}
	}
}

s32 scenarioCtcCallback08(void)
{
	return 4;
}

void scenarioCtcCallback10(void)
{
	// empty
}

void scenarioCtcCallback14()
{
	// empty
}

GLOBAL_ASM(
glabel scenarioCtcReset
/*  f180e34:	27bdff28 */ 	addiu	$sp,$sp,-216
/*  f180e38:	3c0f8008 */ 	lui	$t7,%hi(var80086b60)
/*  f180e3c:	25ef6b60 */ 	addiu	$t7,$t7,%lo(var80086b60)
/*  f180e40:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f180e44:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f180e48:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f180e4c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f180e50:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f180e54:	25e90060 */ 	addiu	$t1,$t7,0x60
/*  f180e58:	27ae0050 */ 	addiu	$t6,$sp,0x50
.L0f180e5c:
/*  f180e5c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f180e60:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f180e64:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f180e68:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f180e6c:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f180e70:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f180e74:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f180e78:	15e9fff8 */ 	bne	$t7,$t1,.L0f180e5c
/*  f180e7c:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f180e80:	8de10000 */ 	lw	$at,0x0($t7)
/*  f180e84:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f180e88:	00009025 */ 	or	$s2,$zero,$zero
/*  f180e8c:	24030006 */ 	addiu	$v1,$zero,0x6
/*  f180e90:	adc10000 */ 	sw	$at,0x0($t6)
/*  f180e94:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f180e98:	00001025 */ 	or	$v0,$zero,$zero
.L0f180e9c:
/*  f180e9c:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f180ea0:
/*  f180ea0:	5443ffff */ 	bnel	$v0,$v1,.L0f180ea0
/*  f180ea4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f180ea8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f180eac:	2a410004 */ 	slti	$at,$s2,0x4
/*  f180eb0:	5420fffa */ 	bnezl	$at,.L0f180e9c
/*  f180eb4:	00001025 */ 	or	$v0,$zero,$zero
/*  f180eb8:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f180ebc:	3c03800b */ 	lui	$v1,0x800b
/*  f180ec0:	2463c118 */ 	addiu	$v1,$v1,-16104
/*  f180ec4:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f180ec8:	27a200b8 */ 	addiu	$v0,$sp,0xb8
.L0f180ecc:
/*  f180ecc:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f180ed0:	0203082b */ 	sltu	$at,$s0,$v1
/*  f180ed4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f180ed8:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f180edc:	1420fffb */ 	bnez	$at,.L0f180ecc
/*  f180ee0:	a600fffe */ 	sh	$zero,-0x2($s0)
/*  f180ee4:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f180ee8:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f180eec:	00009025 */ 	or	$s2,$zero,$zero
/*  f180ef0:	27b100b8 */ 	addiu	$s1,$sp,0xb8
.L0f180ef4:
/*  f180ef4:	0c004b70 */ 	jal	random
/*  f180ef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180efc:	304a0003 */ 	andi	$t2,$v0,0x3
/*  f180f00:	a60a0008 */ 	sh	$t2,0x8($s0)
/*  f180f04:	860b0008 */ 	lh	$t3,0x8($s0)
/*  f180f08:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f180f0c:	022c1821 */ 	addu	$v1,$s1,$t4
/*  f180f10:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f180f14:	15a0fff7 */ 	bnez	$t5,.L0f180ef4
/*  f180f18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180f1c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f180f20:	24010004 */ 	addiu	$at,$zero,0x4
/*  f180f24:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f180f28:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f180f2c:	1641fff1 */ 	bne	$s2,$at,.L0f180ef4
/*  f180f30:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f180f34:	3c13800b */ 	lui	$s3,%hi(g_ScenarioData)
/*  f180f38:	3c12800b */ 	lui	$s2,%hi(g_MpSetup)
/*  f180f3c:	2652cb88 */ 	addiu	$s2,$s2,%lo(g_MpSetup)
/*  f180f40:	2673c110 */ 	addiu	$s3,$s3,%lo(g_ScenarioData)
/*  f180f44:	00008825 */ 	or	$s1,$zero,$zero
/*  f180f48:	96580016 */ 	lhu	$t8,0x16($s2)
.L0f180f4c:
/*  f180f4c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f180f50:	02297804 */ 	sllv	$t7,$t1,$s1
/*  f180f54:	030f7024 */ 	and	$t6,$t8,$t7
/*  f180f58:	11c00034 */ 	beqz	$t6,.L0f18102c
/*  f180f5c:	2a210004 */ 	slti	$at,$s1,0x4
/*  f180f60:	10200008 */ 	beqz	$at,.L0f180f84
/*  f180f64:	00116080 */ 	sll	$t4,$s1,0x2
/*  f180f68:	00115080 */ 	sll	$t2,$s1,0x2
/*  f180f6c:	01515021 */ 	addu	$t2,$t2,$s1
/*  f180f70:	3c0b800b */ 	lui	$t3,%hi(g_MpPlayers)
/*  f180f74:	256bc7b8 */ 	addiu	$t3,$t3,%lo(g_MpPlayers)
/*  f180f78:	000a5140 */ 	sll	$t2,$t2,0x5
/*  f180f7c:	10000009 */ 	beqz	$zero,.L0f180fa4
/*  f180f80:	014b8021 */ 	addu	$s0,$t2,$t3
.L0f180f84:
/*  f180f84:	01916021 */ 	addu	$t4,$t4,$s1
/*  f180f88:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f180f8c:	01916023 */ 	subu	$t4,$t4,$s1
/*  f180f90:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f180f94:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f180f98:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f180f9c:	258dfed0 */ 	addiu	$t5,$t4,-304
/*  f180fa0:	01b98021 */ 	addu	$s0,$t5,$t9
.L0f180fa4:
/*  f180fa4:	0fc61902 */ 	jal	scenarioGetMaxTeams
/*  f180fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180fac:	92090011 */ 	lbu	$t1,0x11($s0)
/*  f180fb0:	0122082a */ 	slt	$at,$t1,$v0
/*  f180fb4:	1420000b */ 	bnez	$at,.L0f180fe4
/*  f180fb8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f180fbc:
/*  f180fbc:	0fc61902 */ 	jal	scenarioGetMaxTeams
/*  f180fc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180fc4:	92180011 */ 	lbu	$t8,0x11($s0)
/*  f180fc8:	03027823 */ 	subu	$t7,$t8,$v0
/*  f180fcc:	0fc61902 */ 	jal	scenarioGetMaxTeams
/*  f180fd0:	a20f0011 */ 	sb	$t7,0x11($s0)
/*  f180fd4:	920e0011 */ 	lbu	$t6,0x11($s0)
/*  f180fd8:	01c2082a */ 	slt	$at,$t6,$v0
/*  f180fdc:	1020fff7 */ 	beqz	$at,.L0f180fbc
/*  f180fe0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f180fe4:
/*  f180fe4:	0fc6343a */ 	jal	func0f18d0e8
/*  f180fe8:	02202025 */ 	or	$a0,$s1,$zero
/*  f180fec:	04400009 */ 	bltz	$v0,.L0f181014
/*  f180ff0:	00402025 */ 	or	$a0,$v0,$zero
/*  f180ff4:	0fc63410 */ 	jal	func0f18d040
/*  f180ff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180ffc:	50400006 */ 	beqzl	$v0,.L0f181018
/*  f181000:	920d0011 */ 	lbu	$t5,0x11($s0)
/*  f181004:	920a0011 */ 	lbu	$t2,0x11($s0)
/*  f181008:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f18100c:	014b6004 */ 	sllv	$t4,$t3,$t2
/*  f181010:	a04c0125 */ 	sb	$t4,0x125($v0)
.L0f181014:
/*  f181014:	920d0011 */ 	lbu	$t5,0x11($s0)
.L0f181018:
/*  f181018:	000dc840 */ 	sll	$t9,$t5,0x1
/*  f18101c:	02791021 */ 	addu	$v0,$s3,$t9
/*  f181020:	84490000 */ 	lh	$t1,0x0($v0)
/*  f181024:	25380001 */ 	addiu	$t8,$t1,0x1
/*  f181028:	a4580000 */ 	sh	$t8,0x0($v0)
.L0f18102c:
/*  f18102c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f181030:	2a21000c */ 	slti	$at,$s1,0xc
/*  f181034:	5420ffc5 */ 	bnezl	$at,.L0f180f4c
/*  f181038:	96580016 */ 	lhu	$t8,0x16($s2)
/*  f18103c:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f181040:	3c02800b */ 	lui	$v0,0x800b
/*  f181044:	2442c118 */ 	addiu	$v0,$v0,-16104
/*  f181048:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f18104c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f181050:	860f0000 */ 	lh	$t7,0x0($s0)
.L0f181054:
/*  f181054:	55e00003 */ 	bnezl	$t7,.L0f181064
/*  f181058:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f18105c:	a6080008 */ 	sh	$t0,0x8($s0)
/*  f181060:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f181064:
/*  f181064:	0202082b */ 	sltu	$at,$s0,$v0
/*  f181068:	5420fffa */ 	bnezl	$at,.L0f181054
/*  f18106c:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f181070:	00009025 */ 	or	$s2,$zero,$zero
/*  f181074:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f181078:
/*  f181078:	2a410004 */ 	slti	$at,$s2,0x4
/*  f18107c:	5420fffe */ 	bnezl	$at,.L0f181078
/*  f181080:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f181084:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f181088:	3c03800b */ 	lui	$v1,0x800b
/*  f18108c:	2463c120 */ 	addiu	$v1,$v1,-16096
/*  f181090:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
.L0f181094:
/*  f181094:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f181098:	0043082b */ 	sltu	$at,$v0,$v1
/*  f18109c:	1420fffd */ 	bnez	$at,.L0f181094
/*  f1810a0:	ac400054 */ 	sw	$zero,0x54($v0)
/*  f1810a4:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f1810a8:	3c02800b */ 	lui	$v0,0x800b
/*  f1810ac:	2442c118 */ 	addiu	$v0,$v0,-16104
/*  f1810b0:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
.L0f1810b4:
/*  f1810b4:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f1810b8:	0202082b */ 	sltu	$at,$s0,$v0
/*  f1810bc:	1420fffd */ 	bnez	$at,.L0f1810b4
/*  f1810c0:	a608000e */ 	sh	$t0,0xe($s0)
/*  f1810c4:	866e0000 */ 	lh	$t6,0x0($s3)
/*  f1810c8:	3c04800b */ 	lui	$a0,%hi(var800ac2c0)
/*  f1810cc:	2484c2c0 */ 	addiu	$a0,$a0,%lo(var800ac2c0)
/*  f1810d0:	11c00026 */ 	beqz	$t6,.L0f18116c
/*  f1810d4:	27ab0050 */ 	addiu	$t3,$sp,0x50
/*  f1810d8:	00806825 */ 	or	$t5,$a0,$zero
/*  f1810dc:	256c0060 */ 	addiu	$t4,$t3,0x60
.L0f1810e0:
/*  f1810e0:	8d610000 */ 	lw	$at,0x0($t3)
/*  f1810e4:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f1810e8:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f1810ec:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f1810f0:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f1810f4:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f1810f8:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f1810fc:	156cfff8 */ 	bne	$t3,$t4,.L0f1810e0
/*  f181100:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f181104:	8d610000 */ 	lw	$at,0x0($t3)
/*  f181108:	240503e8 */ 	addiu	$a1,$zero,0x3e8
/*  f18110c:	ada10000 */ 	sw	$at,0x0($t5)
/*  f181110:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*  f181114:	adac0004 */ 	sw	$t4,0x4($t5)
/*  f181118:	86790008 */ 	lh	$t9,0x8($s3)
/*  f18111c:	00194900 */ 	sll	$t1,$t9,0x4
/*  f181120:	0269c021 */ 	addu	$t8,$s3,$t1
/*  f181124:	870f0018 */ 	lh	$t7,0x18($t8)
/*  f181128:	0fc0359c */ 	jal	func0f00d670
/*  f18112c:	a48f0006 */ 	sh	$t7,0x6($a0)
/*  f181130:	3c0e800b */ 	lui	$t6,0x800b
/*  f181134:	8dcec2d4 */ 	lw	$t6,-0x3d2c($t6)
/*  f181138:	3c0a800b */ 	lui	$t2,0x800b
/*  f18113c:	914ac2c2 */ 	lbu	$t2,-0x3d3e($t2)
/*  f181140:	3c01800b */ 	lui	$at,0x800b
/*  f181144:	ac2ec168 */ 	sw	$t6,-0x3e98($at)
/*  f181148:	3c01800b */ 	lui	$at,0x800b
/*  f18114c:	314cfffb */ 	andi	$t4,$t2,0xfffb
/*  f181150:	a02cc2c2 */ 	sb	$t4,-0x3d3e($at)
/*  f181154:	3c01800b */ 	lui	$at,0x800b
/*  f181158:	a420c322 */ 	sh	$zero,-0x3cde($at)
/*  f18115c:	8e6b0058 */ 	lw	$t3,0x58($s3)
/*  f181160:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f181164:	856d0028 */ 	lh	$t5,0x28($t3)
/*  f181168:	a66d0010 */ 	sh	$t5,0x10($s3)
.L0f18116c:
/*  f18116c:	86790002 */ 	lh	$t9,0x2($s3)
/*  f181170:	3c04800b */ 	lui	$a0,%hi(var800ac328)
/*  f181174:	2410fffb */ 	addiu	$s0,$zero,-5
/*  f181178:	13200028 */ 	beqz	$t9,.L0f18121c
/*  f18117c:	2484c328 */ 	addiu	$a0,$a0,%lo(var800ac328)
/*  f181180:	27a90050 */ 	addiu	$t1,$sp,0x50
/*  f181184:	252f0060 */ 	addiu	$t7,$t1,0x60
/*  f181188:	00807025 */ 	or	$t6,$a0,$zero
.L0f18118c:
/*  f18118c:	8d210000 */ 	lw	$at,0x0($t1)
/*  f181190:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f181194:	25ce000c */ 	addiu	$t6,$t6,0x000c
/*  f181198:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f18119c:	8d21fff8 */ 	lw	$at,-0x8($t1)
/*  f1811a0:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f1811a4:	8d21fffc */ 	lw	$at,-0x4($t1)
/*  f1811a8:	152ffff8 */ 	bne	$t1,$t7,.L0f18118c
/*  f1811ac:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f1811b0:	8d210000 */ 	lw	$at,0x0($t1)
/*  f1811b4:	240503e9 */ 	addiu	$a1,$zero,0x3e9
/*  f1811b8:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1811bc:	8d2f0004 */ 	lw	$t7,0x4($t1)
/*  f1811c0:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f1811c4:	866a000a */ 	lh	$t2,0xa($s3)
/*  f1811c8:	000a6100 */ 	sll	$t4,$t2,0x4
/*  f1811cc:	026c5821 */ 	addu	$t3,$s3,$t4
/*  f1811d0:	856d0018 */ 	lh	$t5,0x18($t3)
/*  f1811d4:	0fc0359c */ 	jal	func0f00d670
/*  f1811d8:	a48d0006 */ 	sh	$t5,0x6($a0)
/*  f1811dc:	3c19800b */ 	lui	$t9,0x800b
/*  f1811e0:	8f39c33c */ 	lw	$t9,-0x3cc4($t9)
/*  f1811e4:	3c18800b */ 	lui	$t8,0x800b
/*  f1811e8:	9318c32a */ 	lbu	$t8,-0x3cd6($t8)
/*  f1811ec:	3c01800b */ 	lui	$at,0x800b
/*  f1811f0:	ac39c16c */ 	sw	$t9,-0x3e94($at)
/*  f1811f4:	3c01800b */ 	lui	$at,0x800b
/*  f1811f8:	03107824 */ 	and	$t7,$t8,$s0
/*  f1811fc:	a02fc32a */ 	sb	$t7,-0x3cd6($at)
/*  f181200:	3c01800b */ 	lui	$at,0x800b
/*  f181204:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f181208:	a429c38a */ 	sh	$t1,-0x3c76($at)
/*  f18120c:	8e6e005c */ 	lw	$t6,0x5c($s3)
/*  f181210:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f181214:	85ca0028 */ 	lh	$t2,0x28($t6)
/*  f181218:	a66a0012 */ 	sh	$t2,0x12($s3)
.L0f18121c:
/*  f18121c:	866c0004 */ 	lh	$t4,0x4($s3)
/*  f181220:	3c04800b */ 	lui	$a0,%hi(var800ac390)
/*  f181224:	2484c390 */ 	addiu	$a0,$a0,%lo(var800ac390)
/*  f181228:	11800027 */ 	beqz	$t4,.L0f1812c8
/*  f18122c:	27ab0050 */ 	addiu	$t3,$sp,0x50
/*  f181230:	0080c025 */ 	or	$t8,$a0,$zero
/*  f181234:	25790060 */ 	addiu	$t9,$t3,0x60
.L0f181238:
/*  f181238:	8d610000 */ 	lw	$at,0x0($t3)
/*  f18123c:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f181240:	2718000c */ 	addiu	$t8,$t8,0x000c
/*  f181244:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f181248:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f18124c:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f181250:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f181254:	1579fff8 */ 	bne	$t3,$t9,.L0f181238
/*  f181258:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f18125c:	8d610000 */ 	lw	$at,0x0($t3)
/*  f181260:	240503ea */ 	addiu	$a1,$zero,0x3ea
/*  f181264:	af010000 */ 	sw	$at,0x0($t8)
/*  f181268:	8d790004 */ 	lw	$t9,0x4($t3)
/*  f18126c:	af190004 */ 	sw	$t9,0x4($t8)
/*  f181270:	866f000c */ 	lh	$t7,0xc($s3)
/*  f181274:	000f4900 */ 	sll	$t1,$t7,0x4
/*  f181278:	02697021 */ 	addu	$t6,$s3,$t1
/*  f18127c:	85ca0018 */ 	lh	$t2,0x18($t6)
/*  f181280:	0fc0359c */ 	jal	func0f00d670
/*  f181284:	a48a0006 */ 	sh	$t2,0x6($a0)
/*  f181288:	3c0c800b */ 	lui	$t4,0x800b
/*  f18128c:	8d8cc3a4 */ 	lw	$t4,-0x3c5c($t4)
/*  f181290:	3c0d800b */ 	lui	$t5,0x800b
/*  f181294:	91adc392 */ 	lbu	$t5,-0x3c6e($t5)
/*  f181298:	3c01800b */ 	lui	$at,0x800b
/*  f18129c:	ac2cc170 */ 	sw	$t4,-0x3e90($at)
/*  f1812a0:	3c01800b */ 	lui	$at,0x800b
/*  f1812a4:	01b0c824 */ 	and	$t9,$t5,$s0
/*  f1812a8:	a039c392 */ 	sb	$t9,-0x3c6e($at)
/*  f1812ac:	3c01800b */ 	lui	$at,0x800b
/*  f1812b0:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f1812b4:	a42bc3f2 */ 	sh	$t3,-0x3c0e($at)
/*  f1812b8:	8e780060 */ 	lw	$t8,0x60($s3)
/*  f1812bc:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f1812c0:	870f0028 */ 	lh	$t7,0x28($t8)
/*  f1812c4:	a66f0014 */ 	sh	$t7,0x14($s3)
.L0f1812c8:
/*  f1812c8:	86690006 */ 	lh	$t1,0x6($s3)
/*  f1812cc:	3c04800b */ 	lui	$a0,%hi(var800ac3f8)
/*  f1812d0:	2484c3f8 */ 	addiu	$a0,$a0,%lo(var800ac3f8)
/*  f1812d4:	11200027 */ 	beqz	$t1,.L0f181374
/*  f1812d8:	27ae0050 */ 	addiu	$t6,$sp,0x50
/*  f1812dc:	00806825 */ 	or	$t5,$a0,$zero
/*  f1812e0:	25cc0060 */ 	addiu	$t4,$t6,0x60
.L0f1812e4:
/*  f1812e4:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1812e8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1812ec:	25ad000c */ 	addiu	$t5,$t5,0x000c
/*  f1812f0:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f1812f4:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f1812f8:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f1812fc:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f181300:	15ccfff8 */ 	bne	$t6,$t4,.L0f1812e4
/*  f181304:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f181308:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f18130c:	240503eb */ 	addiu	$a1,$zero,0x3eb
/*  f181310:	ada10000 */ 	sw	$at,0x0($t5)
/*  f181314:	8dcc0004 */ 	lw	$t4,0x4($t6)
/*  f181318:	adac0004 */ 	sw	$t4,0x4($t5)
/*  f18131c:	8679000e */ 	lh	$t9,0xe($s3)
/*  f181320:	00195900 */ 	sll	$t3,$t9,0x4
/*  f181324:	026bc021 */ 	addu	$t8,$s3,$t3
/*  f181328:	870f0018 */ 	lh	$t7,0x18($t8)
/*  f18132c:	0fc0359c */ 	jal	func0f00d670
/*  f181330:	a48f0006 */ 	sh	$t7,0x6($a0)
/*  f181334:	3c09800b */ 	lui	$t1,0x800b
/*  f181338:	8d29c40c */ 	lw	$t1,-0x3bf4($t1)
/*  f18133c:	3c0a800b */ 	lui	$t2,0x800b
/*  f181340:	914ac3fa */ 	lbu	$t2,-0x3c06($t2)
/*  f181344:	3c01800b */ 	lui	$at,0x800b
/*  f181348:	ac29c174 */ 	sw	$t1,-0x3e8c($at)
/*  f18134c:	3c01800b */ 	lui	$at,0x800b
/*  f181350:	01506024 */ 	and	$t4,$t2,$s0
/*  f181354:	a02cc3fa */ 	sb	$t4,-0x3c06($at)
/*  f181358:	3c01800b */ 	lui	$at,0x800b
/*  f18135c:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f181360:	a42ec45a */ 	sh	$t6,-0x3ba6($at)
/*  f181364:	8e6d0064 */ 	lw	$t5,0x64($s3)
/*  f181368:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f18136c:	85b90028 */ 	lh	$t9,0x28($t5)
/*  f181370:	a6790016 */ 	sh	$t9,0x16($s3)
.L0f181374:
/*  f181374:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f181378:	3c11800b */ 	lui	$s1,0x800b
/*  f18137c:	2631c118 */ 	addiu	$s1,$s1,-16104
/*  f181380:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f181384:	860b0000 */ 	lh	$t3,0x0($s0)
.L0f181388:
/*  f181388:	5160000a */ 	beqzl	$t3,.L0f1813b4
/*  f18138c:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f181390:	86040010 */ 	lh	$a0,0x10($s0)
/*  f181394:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f181398:	00003025 */ 	or	$a2,$zero,$zero
/*  f18139c:	11040004 */ 	beq	$t0,$a0,.L0f1813b0
/*  f1813a0:	00003825 */ 	or	$a3,$zero,$zero
/*  f1813a4:	0fc00b0a */ 	jal	func0f002c28
/*  f1813a8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1813ac:	2408ffff */ 	addiu	$t0,$zero,-1
.L0f1813b0:
/*  f1813b0:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f1813b4:
/*  f1813b4:	5611fff4 */ 	bnel	$s0,$s1,.L0f181388
/*  f1813b8:	860b0000 */ 	lh	$t3,0x0($s0)
/*  f1813bc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1813c0:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f1813c4:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f1813c8:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f1813cc:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f1813d0:	03e00008 */ 	jr	$ra
/*  f1813d4:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
);

void scenarioCtcKill(struct mpchr *mpchr, s32 arg1, s32 *score, s32 *arg3)
{
	struct mpchr *loopmpchr;
	s32 i;

	*score = 0;
	*score = mpchr->unk3e * 3;

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == arg1) {
				*score -= mpchr->unk24[i];
			} else {
				if (i < 4) {
					loopmpchr = &g_MpPlayers[i].base;
				} else {
					loopmpchr = &g_MpSimulants[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->unk24[i];
				} else {
					*score += mpchr->unk24[i];
				}
			}
		}
	}

	*arg3 = mpchr->unk3c;
}

s32 scenarioCtcRadar(s32 value)
{
	if (g_MpSetup.options & MPOPTION_SHOWONRADAR2) {
		s32 i;

		for (i = 0; i < scenarioGetMaxTeams(); i++) {
			if (g_ScenarioData.ctc.tokens[i] &&
					g_ScenarioData.ctc.tokens[i]->type != PROPTYPE_CHR &&
					g_ScenarioData.ctc.tokens[i]->type != PROPTYPE_PLAYER) {
				struct coord dist;
				dist.x = g_ScenarioData.ctc.tokens[i]->pos.x - g_Vars.currentplayer->prop->pos.x;
				dist.y = g_ScenarioData.ctc.tokens[i]->pos.y - g_Vars.currentplayer->prop->pos.y;
				dist.z = g_ScenarioData.ctc.tokens[i]->pos.z - g_Vars.currentplayer->prop->pos.z;
				value = func0f18e9ec(value, g_ScenarioData.ctc.tokens[i], &dist, g_TeamColours[i], 0, 1);
			}
		}
	}

	return value;
}

bool scenarioCtcRadar2(s32 *displaylist, struct prop *prop)
{
	s32 i;

	if (g_MpSetup.options & MPOPTION_SHOWONRADAR2) {
		for (i = 0; i < scenarioGetMaxTeams(); i++) {
			if (prop == g_ScenarioData.ctc.tokens[i] &&
					(g_ScenarioData.ctc.tokens[i]->type == PROPTYPE_CHR || g_ScenarioData.ctc.tokens[i]->type == PROPTYPE_PLAYER)) {
				struct coord dist;
				s32 colour = g_TeamColours[teamGetIndex(prop->chr->team)];
				dist.x = g_ScenarioData.ctc.tokens[i]->pos.x - g_Vars.currentplayer->prop->pos.x;
				dist.y = g_ScenarioData.ctc.tokens[i]->pos.y - g_Vars.currentplayer->prop->pos.y;
				dist.z = g_ScenarioData.ctc.tokens[i]->pos.z - g_Vars.currentplayer->prop->pos.z;
				*displaylist = func0f18e9ec(*displaylist, g_ScenarioData.ctc.tokens[i], &dist,
						g_TeamColours[i], colour, 1);
				return true;
			}
		}
	}

	return false;
}

GLOBAL_ASM(
glabel scenarioCtcHighlight
/*  f181764:	90860000 */ 	lbu	$a2,0x0($a0)
/*  f181768:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f18176c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f181770:	10c10006 */ 	beq	$a2,$at,.L0f18178c
/*  f181774:	00601025 */ 	or	$v0,$v1,$zero
/*  f181778:	24010004 */ 	addiu	$at,$zero,0x4
/*  f18177c:	10c10003 */ 	beq	$a2,$at,.L0f18178c
/*  f181780:	24010002 */ 	addiu	$at,$zero,0x2
/*  f181784:	54c1001c */ 	bnel	$a2,$at,.L0f1817f8
/*  f181788:	00001025 */ 	or	$v0,$zero,$zero
.L0f18178c:
/*  f18178c:	904e0003 */ 	lbu	$t6,0x3($v0)
/*  f181790:	24010008 */ 	addiu	$at,$zero,0x8
/*  f181794:	55c10018 */ 	bnel	$t6,$at,.L0f1817f8
/*  f181798:	00001025 */ 	or	$v0,$zero,$zero
/*  f18179c:	906f005c */ 	lbu	$t7,0x5c($v1)
/*  f1817a0:	24010057 */ 	addiu	$at,$zero,0x57
/*  f1817a4:	55e10014 */ 	bnel	$t7,$at,.L0f1817f8
/*  f1817a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1817ac:	84780062 */ 	lh	$t8,0x62($v1)
/*  f1817b0:	3c038008 */ 	lui	$v1,0x8008
/*  f1817b4:	240e004b */ 	addiu	$t6,$zero,0x4b
/*  f1817b8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1817bc:	00791821 */ 	addu	$v1,$v1,$t9
/*  f1817c0:	8c637cc4 */ 	lw	$v1,0x7cc4($v1)
/*  f1817c4:	acae000c */ 	sw	$t6,0xc($a1)
/*  f1817c8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1817cc:	00034602 */ 	srl	$t0,$v1,0x18
/*  f1817d0:	00035402 */ 	srl	$t2,$v1,0x10
/*  f1817d4:	00036202 */ 	srl	$t4,$v1,0x8
/*  f1817d8:	310900ff */ 	andi	$t1,$t0,0xff
/*  f1817dc:	314b00ff */ 	andi	$t3,$t2,0xff
/*  f1817e0:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f1817e4:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f1817e8:	acab0004 */ 	sw	$t3,0x4($a1)
/*  f1817ec:	03e00008 */ 	jr	$ra
/*  f1817f0:	acad0008 */ 	sw	$t5,0x8($a1)
/*  f1817f4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1817f8:
/*  f1817f8:	03e00008 */ 	jr	$ra
/*  f1817fc:	00000000 */ 	sll	$zero,$zero,0x0
);

//bool scenarioCtcHighlight(struct prop *prop, u32 *colour)
//{
//	if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR) {
//		if (prop->obj->type == OBJTYPE_WEAPON && prop->weapon->weapon_id == WEAPON_BRIEFCASE2) {
//			u32 teamcolour = g_TeamColours[prop->weapon->team];
//
//			colour[0] = teamcolour >> 24 & 0xff;
//			colour[1] = teamcolour >> 16 & 0xff;
//			colour[2] = teamcolour >> 8 & 0xff;
//			colour[3] = 75;
//
//			return true;
//		}
//	}
//
//	return false;
//}

GLOBAL_ASM(
glabel func0f181800
/*  f181800:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f181804:	24010009 */ 	addiu	$at,$zero,0x9
/*  f181808:	00001825 */ 	or	$v1,$zero,$zero
/*  f18180c:	14410008 */ 	bne	$v0,$at,.L0f181830
/*  f181810:	3c09800b */ 	lui	$t1,%hi(g_ScenarioData)
/*  f181814:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f181818:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*  f18181c:	3c01800b */ 	lui	$at,0x800b
/*  f181820:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f181824:	00380821 */ 	addu	$at,$at,$t8
/*  f181828:	a42ec128 */ 	sh	$t6,-0x3ed8($at)
/*  f18182c:	8c820000 */ 	lw	$v0,0x0($a0)
.L0f181830:
/*  f181830:	2401000a */ 	addiu	$at,$zero,0xa
/*  f181834:	14410017 */ 	bne	$v0,$at,.L0f181894
/*  f181838:	2529c110 */ 	addiu	$t1,$t1,%lo(g_ScenarioData)
/*  f18183c:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f181840:	2406000c */ 	addiu	$a2,$zero,0xc
/*  f181844:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f181848:	00194100 */ 	sll	$t0,$t9,0x4
/*  f18184c:	01092821 */ 	addu	$a1,$t0,$t1
.L0f181850:
/*  f181850:	84aa001c */ 	lh	$t2,0x1c($a1)
/*  f181854:	544a000d */ 	bnel	$v0,$t2,.L0f18188c
/*  f181858:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f18185c:	8c8b0008 */ 	lw	$t3,0x8($a0)
/*  f181860:	3c0f800b */ 	lui	$t7,%hi(g_ScenarioData)
/*  f181864:	25efc110 */ 	addiu	$t7,$t7,%lo(g_ScenarioData)
/*  f181868:	a4ab001c */ 	sh	$t3,0x1c($a1)
/*  f18186c:	8c8c0004 */ 	lw	$t4,0x4($a0)
/*  f181870:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f181874:	01af1021 */ 	addu	$v0,$t5,$t7
/*  f181878:	844e001a */ 	lh	$t6,0x1a($v0)
/*  f18187c:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f181880:	03e00008 */ 	jr	$ra
/*  f181884:	a458001a */ 	sh	$t8,0x1a($v0)
/*  f181888:	24630002 */ 	addiu	$v1,$v1,0x2
.L0f18188c:
/*  f18188c:	1466fff0 */ 	bne	$v1,$a2,.L0f181850
/*  f181890:	24a50002 */ 	addiu	$a1,$a1,0x2
.L0f181894:
/*  f181894:	03e00008 */ 	jr	$ra
/*  f181898:	00000000 */ 	sll	$zero,$zero,0x0
);

bool scenarioCtcCallback2c(f32 arg0, s32 arg1, s32 arg2, struct prop *prop, f32 *arg4)
{
	struct chrdata *chr = prop->chr;
	s32 index = teamGetIndex(chr->team);

	if (g_ScenarioData.ctc.unk18[g_ScenarioData.ctc.unk08[index]].unk02 > 0) {
		*arg4 = func0f0b69d0(arg0, arg1, arg2, prop,
				&g_ScenarioData.ctc.unk18[g_ScenarioData.ctc.unk08[index]].unk04[0],
				g_ScenarioData.ctc.unk18[g_ScenarioData.ctc.unk08[index]].unk02);
		return true;
	}

	return false;
}

s32 scenarioCtcGetMaxTeams(void)
{
	return 4;
}

bool scenarioCtcIsRoomHighlighted(s16 room)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_ScenarioData.ctc.baserooms[i] == room && g_ScenarioData.ctc.unk08[i] != -1) {
			return true;
		}
	}

	return false;
}

GLOBAL_ASM(
glabel scenarioCtcCallback38
/*  f1819a4:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f1819a8:	00047400 */ 	sll	$t6,$a0,0x10
/*  f1819ac:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f1819b0:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f1819b4:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f1819b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1819bc:	24080004 */ 	addiu	$t0,$zero,0x4
.L0f1819c0:
/*  f1819c0:	84780010 */ 	lh	$t8,0x10($v1)
/*  f1819c4:	1498002f */ 	bne	$a0,$t8,.L0f181a84
/*  f1819c8:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f1819cc:	3c038008 */ 	lui	$v1,0x8008
/*  f1819d0:	00791821 */ 	addu	$v1,$v1,$t9
/*  f1819d4:	8c637cc4 */ 	lw	$v1,0x7cc4($v1)
/*  f1819d8:	8ca90000 */ 	lw	$t1,0x0($a1)
/*  f1819dc:	3c013b00 */ 	lui	$at,0x3b00
/*  f1819e0:	00036602 */ 	srl	$t4,$v1,0x18
/*  f1819e4:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f1819e8:	25ae00ff */ 	addiu	$t6,$t5,0xff
/*  f1819ec:	448e5000 */ 	mtc1	$t6,$f10
/*  f1819f0:	44817000 */ 	mtc1	$at,$f14
/*  f1819f4:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f1819f8:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f1819fc:	44892000 */ 	mtc1	$t1,$f4
/*  f181a00:	00037c02 */ 	srl	$t7,$v1,0x10
/*  f181a04:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f181a08:	448a3000 */ 	mtc1	$t2,$f6
/*  f181a0c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f181a10:	460e8482 */ 	mul.s	$f18,$f16,$f14
/*  f181a14:	271900ff */ 	addiu	$t9,$t8,0xff
/*  f181a18:	44992000 */ 	mtc1	$t9,$f4
/*  f181a1c:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f181a20:	00034a02 */ 	srl	$t1,$v1,0x8
/*  f181a24:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f181a28:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f181a2c:	448b4000 */ 	mtc1	$t3,$f8
/*  f181a30:	46120002 */ 	mul.s	$f0,$f0,$f18
/*  f181a34:	254b00ff */ 	addiu	$t3,$t2,0xff
/*  f181a38:	448b5000 */ 	mtc1	$t3,$f10
/*  f181a3c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f181a40:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f181a44:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f181a48:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f181a4c:	46081082 */ 	mul.s	$f2,$f2,$f8
/*  f181a50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181a54:	460e8482 */ 	mul.s	$f18,$f16,$f14
/*  f181a58:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f181a5c:	46126302 */ 	mul.s	$f12,$f12,$f18
/*  f181a60:	440d2000 */ 	mfc1	$t5,$f4
/*  f181a64:	4600118d */ 	trunc.w.s	$f6,$f2
/*  f181a68:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f181a6c:	4600620d */ 	trunc.w.s	$f8,$f12
/*  f181a70:	440f3000 */ 	mfc1	$t7,$f6
/*  f181a74:	44194000 */ 	mfc1	$t9,$f8
/*  f181a78:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f181a7c:	03e00008 */ 	jr	$ra
/*  f181a80:	acf90000 */ 	sw	$t9,0x0($a3)
.L0f181a84:
/*  f181a84:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f181a88:	1448ffcd */ 	bne	$v0,$t0,.L0f1819c0
/*  f181a8c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f181a90:	03e00008 */ 	jr	$ra
/*  f181a94:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMpHillTime(u32 operation, struct menu_item *item, struct numandtext *value)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		value->num = g_Vars.mphilltime;
		break;
	case MENUOP_SET:
		g_Vars.mphilltime = (u8)value->num;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(value->text, textGet(0x5417), value->num + 10); // "%ds/Point"
		break;
	}

	return 0;
}

void scenarioKohCallback40(s32 *arg0)
{
	g_Vars.mphilltime = scenarioDefaultCallback40(arg0, 8);
}

void scenarioKohCallback44(s32 *arg0)
{
	scenarioDefaultCallback44(arg0, g_Vars.mphilltime, 8);
}

void scenarioKohInit(void)
{
	s32 i;

	g_MpSetup.options |= MPOPTION_TEAMSENABLED;
	g_ScenarioData.koh.hillindex = -1;
	g_ScenarioData.koh.hillcount = 0;
	g_ScenarioData.koh.unk00 = 0;
	g_ScenarioData.koh.occupiedteam = -1;
	g_ScenarioData.koh.unk06 = 0;
	g_ScenarioData.koh.hillroom = -1;
	g_ScenarioData.koh.unk10 = -1;
	g_ScenarioData.koh.hillpos.x = 0;
	g_ScenarioData.koh.hillpos.y = 0;
	g_ScenarioData.koh.hillpos.z = 0;
	g_ScenarioData.koh.unk30 = 0.25;
	g_ScenarioData.koh.unk34 = 1;
	g_ScenarioData.koh.unk38 = 0.25;

	for (i = 0; i < 9; i++) {
		g_ScenarioData.koh.hillpads[i] = -1;
	}
}

void scenarioKohReset(void)
{
	s16 pad_id = 0;
	struct pad pad;

	if (g_ScenarioData.koh.hillcount > 1) {
		g_ScenarioData.koh.hillindex = random() % g_ScenarioData.koh.hillcount;
		pad_id = g_ScenarioData.koh.hillpads[g_ScenarioData.koh.hillindex];
	} else {
		// @bug: If a stage setup file only has one hill, pad_id is not assigned
		// so it will always use the room that contains pad zero.
		g_ScenarioData.koh.hillindex = 0;
	}

	padUnpack(pad_id, 0x42, &pad);
	g_ScenarioData.koh.hillroom = pad.room;
	g_ScenarioData.koh.unk10 = -1;
	g_ScenarioData.koh.hillpos.x = pad.pos.x;
	g_ScenarioData.koh.hillpos.y = pad.pos.y;
	g_ScenarioData.koh.hillpos.z = pad.pos.z;
	g_ScenarioData.koh.hillpos.y = func0002a36c(&g_ScenarioData.koh.hillpos, &g_ScenarioData.koh.hillroom, 0, 0);
	g_ScenarioData.koh.unk08 = 0;
	func0f002c28(g_ScenarioData.koh.hillroom, 5, 0, 0, 0);
}

GLOBAL_ASM(
glabel scenarioKohCallback10
/*  f181cf0:	27bdfe78 */ 	addiu	$sp,$sp,-392
/*  f181cf4:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f181cf8:	3c13800b */ 	lui	$s3,%hi(g_ScenarioData)
/*  f181cfc:	2673c110 */ 	addiu	$s3,$s3,%lo(g_ScenarioData)
/*  f181d00:	866e000a */ 	lh	$t6,0xa($s3)
/*  f181d04:	2401ffff */ 	addiu	$at,$zero,-1
/*  f181d08:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f181d0c:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f181d10:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f181d14:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f181d18:	11c1024d */ 	beq	$t6,$at,.L0f182650
/*  f181d1c:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f181d20:	866f0008 */ 	lh	$t7,0x8($s3)
/*  f181d24:	00003825 */ 	or	$a3,$zero,$zero
/*  f181d28:	3c013f80 */ 	lui	$at,0x3f80
/*  f181d2c:	11e00058 */ 	beqz	$t7,.L0f181e90
/*  f181d30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181d34:	44811000 */ 	mtc1	$at,$f2
/*  f181d38:	3c017f1c */ 	lui	$at,%hi(var7f1b893c)
/*  f181d3c:	c42c893c */ 	lwc1	$f12,%lo(var7f1b893c)($at)
/*  f181d40:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f181d44:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f181d48:	a6780004 */ 	sh	$t8,0x4($s3)
/*  f181d4c:	4600603e */ 	c.le.s	$f12,$f0
/*  f181d50:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f181d54:	e7a20164 */ 	swc1	$f2,0x164($sp)
/*  f181d58:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f181d5c:	45000047 */ 	bc1f	.L0f181e7c
/*  f181d60:	e7a2015c */ 	swc1	$f2,0x15c($sp)
/*  f181d64:	c6640034 */ 	lwc1	$f4,0x34($s3)
/*  f181d68:	4604603e */ 	c.le.s	$f12,$f4
/*  f181d6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181d70:	45000042 */ 	bc1f	.L0f181e7c
/*  f181d74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181d78:	c6660038 */ 	lwc1	$f6,0x38($s3)
/*  f181d7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f181d80:	00003025 */ 	or	$a2,$zero,$zero
/*  f181d84:	4606603e */ 	c.le.s	$f12,$f6
/*  f181d88:	00003825 */ 	or	$a3,$zero,$zero
/*  f181d8c:	4500003b */ 	bc1f	.L0f181e7c
/*  f181d90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181d94:	8664000e */ 	lh	$a0,0xe($s3)
/*  f181d98:	0fc00b0a */ 	jal	func0f002c28
/*  f181d9c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f181da0:	8679000c */ 	lh	$t9,0xc($s3)
/*  f181da4:	00002025 */ 	or	$a0,$zero,$zero
/*  f181da8:	2b210002 */ 	slti	$at,$t9,0x2
/*  f181dac:	54200013 */ 	bnezl	$at,.L0f181dfc
/*  f181db0:	a660000a */ 	sh	$zero,0xa($s3)
/*  f181db4:	8670000a */ 	lh	$s0,0xa($s3)
.L0f181db8:
/*  f181db8:	0c004b70 */ 	jal	random
/*  f181dbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181dc0:	8668000c */ 	lh	$t0,0xc($s3)
/*  f181dc4:	0048001b */ 	divu	$zero,$v0,$t0
/*  f181dc8:	00004810 */ 	mfhi	$t1
/*  f181dcc:	a669000a */ 	sh	$t1,0xa($s3)
/*  f181dd0:	8663000a */ 	lh	$v1,0xa($s3)
/*  f181dd4:	15000002 */ 	bnez	$t0,.L0f181de0
/*  f181dd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181ddc:	0007000d */ 	break	0x7
.L0f181de0:
/*  f181de0:	1203fff5 */ 	beq	$s0,$v1,.L0f181db8
/*  f181de4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181de8:	00035040 */ 	sll	$t2,$v1,0x1
/*  f181dec:	026a5821 */ 	addu	$t3,$s3,$t2
/*  f181df0:	10000002 */ 	beqz	$zero,.L0f181dfc
/*  f181df4:	85640012 */ 	lh	$a0,0x12($t3)
/*  f181df8:	a660000a */ 	sh	$zero,0xa($s3)
.L0f181dfc:
/*  f181dfc:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f181e00:	0fc456ac */ 	jal	padUnpack
/*  f181e04:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f181e08:	8fac00f0 */ 	lw	$t4,0xf0($sp)
/*  f181e0c:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
/*  f181e10:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f181e14:	c7b200b0 */ 	lwc1	$f18,0xb0($sp)
/*  f181e18:	240dffff */ 	addiu	$t5,$zero,-1
/*  f181e1c:	3c04800b */ 	lui	$a0,0x800b
/*  f181e20:	3c05800b */ 	lui	$a1,0x800b
/*  f181e24:	a66d0010 */ 	sh	$t5,0x10($s3)
/*  f181e28:	24a5c11e */ 	addiu	$a1,$a1,-16098
/*  f181e2c:	2484c134 */ 	addiu	$a0,$a0,-16076
/*  f181e30:	00003025 */ 	or	$a2,$zero,$zero
/*  f181e34:	00003825 */ 	or	$a3,$zero,$zero
/*  f181e38:	a66c000e */ 	sh	$t4,0xe($s3)
/*  f181e3c:	e6680024 */ 	swc1	$f8,0x24($s3)
/*  f181e40:	e66a0028 */ 	swc1	$f10,0x28($s3)
/*  f181e44:	0c00a8db */ 	jal	func0002a36c
/*  f181e48:	e672002c */ 	swc1	$f18,0x2c($s3)
/*  f181e4c:	e6600028 */ 	swc1	$f0,0x28($s3)
/*  f181e50:	8664000e */ 	lh	$a0,0xe($s3)
/*  f181e54:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f181e58:	00003025 */ 	or	$a2,$zero,$zero
/*  f181e5c:	00003825 */ 	or	$a3,$zero,$zero
/*  f181e60:	0fc00b0a */ 	jal	func0f002c28
/*  f181e64:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f181e68:	240effff */ 	addiu	$t6,$zero,-1
/*  f181e6c:	a66e0004 */ 	sh	$t6,0x4($s3)
/*  f181e70:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f181e74:	a6600008 */ 	sh	$zero,0x8($s3)
/*  f181e78:	c6600030 */ 	lwc1	$f0,0x30($s3)
.L0f181e7c:
/*  f181e7c:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f181e80:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f181e84:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f181e88:	10000196 */ 	beqz	$zero,.L0f1824e4
/*  f181e8c:	c6700038 */ 	lwc1	$f16,0x38($s3)
.L0f181e90:
/*  f181e90:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f181e94:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f181e98:	8e83033c */ 	lw	$v1,0x33c($s4)
/*  f181e9c:	00003025 */ 	or	$a2,$zero,$zero
/*  f181ea0:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f181ea4:	1060001e */ 	beqz	$v1,.L0f181f20
/*  f181ea8:	24100006 */ 	addiu	$s0,$zero,0x6
/*  f181eac:	90620000 */ 	lbu	$v0,0x0($v1)
.L0f181eb0:
/*  f181eb0:	52020004 */ 	beql	$s0,$v0,.L0f181ec4
/*  f181eb4:	846f0028 */ 	lh	$t7,0x28($v1)
/*  f181eb8:	56420017 */ 	bnel	$s2,$v0,.L0f181f18
/*  f181ebc:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f181ec0:	846f0028 */ 	lh	$t7,0x28($v1)
.L0f181ec4:
/*  f181ec4:	8678000e */ 	lh	$t8,0xe($s3)
/*  f181ec8:	00008825 */ 	or	$s1,$zero,$zero
/*  f181ecc:	15f80002 */ 	bne	$t7,$t8,.L0f181ed8
/*  f181ed0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181ed4:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f181ed8:
/*  f181ed8:	5220000f */ 	beqzl	$s1,.L0f181f18
/*  f181edc:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f181ee0:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f181ee4:	afa70170 */ 	sw	$a3,0x170($sp)
/*  f181ee8:	afa60174 */ 	sw	$a2,0x174($sp)
/*  f181eec:	0fc0e6a5 */ 	jal	chrIsDead
/*  f181ef0:	afa30074 */ 	sw	$v1,0x74($sp)
/*  f181ef4:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f181ef8:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f181efc:	14400005 */ 	bnez	$v0,.L0f181f14
/*  f181f00:	8fa70170 */ 	lw	$a3,0x170($sp)
/*  f181f04:	0006c880 */ 	sll	$t9,$a2,0x2
/*  f181f08:	03b94021 */ 	addu	$t0,$sp,$t9
/*  f181f0c:	ad030078 */ 	sw	$v1,0x78($t0)
/*  f181f10:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f181f14:
/*  f181f14:	8c630020 */ 	lw	$v1,0x20($v1)
.L0f181f18:
/*  f181f18:	5460ffe5 */ 	bnezl	$v1,.L0f181eb0
/*  f181f1c:	90620000 */ 	lbu	$v0,0x0($v1)
.L0f181f20:
/*  f181f20:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f181f24:	27a3011c */ 	addiu	$v1,$sp,0x11c
.L0f181f28:
/*  f181f28:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f181f2c:	0043082b */ 	sltu	$at,$v0,$v1
/*  f181f30:	1420fffd */ 	bnez	$at,.L0f181f28
/*  f181f34:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f181f38:	00008025 */ 	or	$s0,$zero,$zero
/*  f181f3c:	18c00017 */ 	blez	$a2,.L0f181f9c
/*  f181f40:	00009025 */ 	or	$s2,$zero,$zero
/*  f181f44:	27a30078 */ 	addiu	$v1,$sp,0x78
/*  f181f48:	27b100fc */ 	addiu	$s1,$sp,0xfc
.L0f181f4c:
/*  f181f4c:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f181f50:	8d250004 */ 	lw	$a1,0x4($t1)
/*  f181f54:	90a40125 */ 	lbu	$a0,0x125($a1)
/*  f181f58:	afa70170 */ 	sw	$a3,0x170($sp)
/*  f181f5c:	afa60174 */ 	sw	$a2,0x174($sp)
/*  f181f60:	0fc63a5a */ 	jal	teamGetIndex
/*  f181f64:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f181f68:	00025080 */ 	sll	$t2,$v0,0x2
/*  f181f6c:	022a2021 */ 	addu	$a0,$s1,$t2
/*  f181f70:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f181f74:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f181f78:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f181f7c:	15600004 */ 	bnez	$t3,.L0f181f90
/*  f181f80:	8fa70170 */ 	lw	$a3,0x170($sp)
/*  f181f84:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f181f88:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f181f8c:	ac8c0000 */ 	sw	$t4,0x0($a0)
.L0f181f90:
/*  f181f90:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f181f94:	1606ffed */ 	bne	$s0,$a2,.L0f181f4c
/*  f181f98:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f181f9c:
/*  f181f9c:	16400005 */ 	bnez	$s2,.L0f181fb4
/*  f181fa0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f181fa4:	240dffff */ 	addiu	$t5,$zero,-1
/*  f181fa8:	a66d0004 */ 	sh	$t5,0x4($s3)
/*  f181fac:	10000120 */ 	beqz	$zero,.L0f182430
/*  f181fb0:	a6600006 */ 	sh	$zero,0x6($s3)
.L0f181fb4:
/*  f181fb4:	1641000b */ 	bne	$s2,$at,.L0f181fe4
/*  f181fb8:	00008025 */ 	or	$s0,$zero,$zero
/*  f181fbc:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f181fc0:	24030008 */ 	addiu	$v1,$zero,0x8
.L0f181fc4:
/*  f181fc4:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f181fc8:	55c0003d */ 	bnezl	$t6,.L0f1820c0
/*  f181fcc:	866a0004 */ 	lh	$t2,0x4($s3)
/*  f181fd0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f181fd4:	1603fffb */ 	bne	$s0,$v1,.L0f181fc4
/*  f181fd8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f181fdc:	10000038 */ 	beqz	$zero,.L0f1820c0
/*  f181fe0:	866a0004 */ 	lh	$t2,0x4($s3)
.L0f181fe4:
/*  f181fe4:	00008825 */ 	or	$s1,$zero,$zero
/*  f181fe8:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f181fec:	27a4011c */ 	addiu	$a0,$sp,0x11c
/*  f181ff0:	8c430000 */ 	lw	$v1,0x0($v0)
.L0f181ff4:
/*  f181ff4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f181ff8:	0223082a */ 	slt	$at,$s1,$v1
/*  f181ffc:	50200003 */ 	beqzl	$at,.L0f18200c
/*  f182000:	0044082b */ 	sltu	$at,$v0,$a0
/*  f182004:	00608825 */ 	or	$s1,$v1,$zero
/*  f182008:	0044082b */ 	sltu	$at,$v0,$a0
.L0f18200c:
/*  f18200c:	5420fff9 */ 	bnezl	$at,.L0f181ff4
/*  f182010:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f182014:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182018:	27a3011c */ 	addiu	$v1,$sp,0x11c
/*  f18201c:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f182020:
/*  f182020:	522f0003 */ 	beql	$s1,$t7,.L0f182030
/*  f182024:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f182028:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f18202c:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f182030:
/*  f182030:	0043082b */ 	sltu	$at,$v0,$v1
/*  f182034:	5420fffa */ 	bnezl	$at,.L0f182020
/*  f182038:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f18203c:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182040:	27a3011c */ 	addiu	$v1,$sp,0x11c
/*  f182044:	8c580000 */ 	lw	$t8,0x0($v0)
.L0f182048:
/*  f182048:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18204c:	0043082b */ 	sltu	$at,$v0,$v1
/*  f182050:	13000002 */ 	beqz	$t8,.L0f18205c
/*  f182054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182058:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f18205c:
/*  f18205c:	5420fffa */ 	bnezl	$at,.L0f182048
/*  f182060:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f182064:	28e10002 */ 	slti	$at,$a3,0x2
/*  f182068:	14200003 */ 	bnez	$at,.L0f182078
/*  f18206c:	00008025 */ 	or	$s0,$zero,$zero
/*  f182070:	10000002 */ 	beqz	$zero,.L0f18207c
/*  f182074:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f182078:
/*  f182078:	00003825 */ 	or	$a3,$zero,$zero
.L0f18207c:
/*  f18207c:	27a200fc */ 	addiu	$v0,$sp,0xfc
.L0f182080:
/*  f182080:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f182084:	53200005 */ 	beqzl	$t9,.L0f18209c
/*  f182088:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18208c:	86680004 */ 	lh	$t0,0x4($s3)
/*  f182090:	52080006 */ 	beql	$s0,$t0,.L0f1820ac
/*  f182094:	24030008 */ 	addiu	$v1,$zero,0x8
/*  f182098:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f18209c:
/*  f18209c:	2a010008 */ 	slti	$at,$s0,0x8
/*  f1820a0:	1420fff7 */ 	bnez	$at,.L0f182080
/*  f1820a4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1820a8:	24030008 */ 	addiu	$v1,$zero,0x8
.L0f1820ac:
/*  f1820ac:	16030003 */ 	bne	$s0,$v1,.L0f1820bc
/*  f1820b0:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f1820b4:	a6690004 */ 	sh	$t1,0x4($s3)
/*  f1820b8:	2410ffff */ 	addiu	$s0,$zero,-1
.L0f1820bc:
/*  f1820bc:	866a0004 */ 	lh	$t2,0x4($s3)
.L0f1820c0:
/*  f1820c0:	3c048009 */ 	lui	$a0,0x8009
/*  f1820c4:	240505b9 */ 	addiu	$a1,$zero,0x5b9
/*  f1820c8:	120a0070 */ 	beq	$s0,$t2,.L0f18228c
/*  f1820cc:	00003025 */ 	or	$a2,$zero,$zero
/*  f1820d0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1820d4:	44812000 */ 	mtc1	$at,$f4
/*  f1820d8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f1820dc:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1820e0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f1820e4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1820e8:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1820ec:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f1820f0:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f1820f4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f1820f8:	00008825 */ 	or	$s1,$zero,$zero
/*  f1820fc:	0c004241 */ 	jal	func00010904
/*  f182100:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f182104:	a6700004 */ 	sh	$s0,0x4($s3)
/*  f182108:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f18210c:	0fc5b9f1 */ 	jal	textGet
/*  f182110:	24045416 */ 	addiu	$a0,$zero,0x5416
/*  f182114:	00107080 */ 	sll	$t6,$s0,0x2
/*  f182118:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f18211c:	3c0f800b */ 	lui	$t7,0x800b
/*  f182120:	25efcbb0 */ 	addiu	$t7,$t7,-13392
/*  f182124:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f182128:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f18212c:	27a4011c */ 	addiu	$a0,$sp,0x11c
/*  f182130:	0c004dad */ 	jal	sprintf
/*  f182134:	00402825 */ 	or	$a1,$v0,$zero
/*  f182138:	8e98006c */ 	lw	$t8,0x6c($s4)
/*  f18213c:	27b0011c */ 	addiu	$s0,$sp,0x11c
/*  f182140:	8e92028c */ 	lw	$s2,0x28c($s4)
/*  f182144:	13000003 */ 	beqz	$t8,.L0f182154
/*  f182148:	00002825 */ 	or	$a1,$zero,$zero
/*  f18214c:	10000001 */ 	beqz	$zero,.L0f182154
/*  f182150:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f182154:
/*  f182154:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f182158:	00002025 */ 	or	$a0,$zero,$zero
/*  f18215c:	00001825 */ 	or	$v1,$zero,$zero
/*  f182160:	13200003 */ 	beqz	$t9,.L0f182170
/*  f182164:	00001025 */ 	or	$v0,$zero,$zero
/*  f182168:	10000001 */ 	beqz	$zero,.L0f182170
/*  f18216c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f182170:
/*  f182170:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f182174:	11000003 */ 	beqz	$t0,.L0f182184
/*  f182178:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18217c:	10000001 */ 	beqz	$zero,.L0f182184
/*  f182180:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f182184:
/*  f182184:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f182188:	11200003 */ 	beqz	$t1,.L0f182198
/*  f18218c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182190:	10000001 */ 	beqz	$zero,.L0f182198
/*  f182194:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f182198:
/*  f182198:	00435021 */ 	addu	$t2,$v0,$v1
/*  f18219c:	01445821 */ 	addu	$t3,$t2,$a0
/*  f1821a0:	01656021 */ 	addu	$t4,$t3,$a1
/*  f1821a4:	19800035 */ 	blez	$t4,.L0f18227c
/*  f1821a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1821ac:
/*  f1821ac:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1821b0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1821b4:	8e8d0284 */ 	lw	$t5,0x284($s4)
/*  f1821b8:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f1821bc:	8dc50004 */ 	lw	$a1,0x4($t6)
/*  f1821c0:	0fc63a5a */ 	jal	teamGetIndex
/*  f1821c4:	90a40125 */ 	lbu	$a0,0x125($a1)
/*  f1821c8:	866f0004 */ 	lh	$t7,0x4($s3)
/*  f1821cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1821d0:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1821d4:	144f0009 */ 	bne	$v0,$t7,.L0f1821fc
/*  f1821d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1821dc:	0fc5b9f1 */ 	jal	textGet
/*  f1821e0:	24045415 */ 	addiu	$a0,$zero,0x5415
/*  f1821e4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1821e8:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1821ec:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f1821f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1821f4:	10000004 */ 	beqz	$zero,.L0f182208
/*  f1821f8:	8e98006c */ 	lw	$t8,0x6c($s4)
.L0f1821fc:
/*  f1821fc:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f182200:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f182204:	8e98006c */ 	lw	$t8,0x6c($s4)
.L0f182208:
/*  f182208:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18220c:	00002825 */ 	or	$a1,$zero,$zero
/*  f182210:	13000003 */ 	beqz	$t8,.L0f182220
/*  f182214:	00002025 */ 	or	$a0,$zero,$zero
/*  f182218:	10000001 */ 	beqz	$zero,.L0f182220
/*  f18221c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f182220:
/*  f182220:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f182224:	00001825 */ 	or	$v1,$zero,$zero
/*  f182228:	00001025 */ 	or	$v0,$zero,$zero
/*  f18222c:	13200003 */ 	beqz	$t9,.L0f18223c
/*  f182230:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182234:	10000001 */ 	beqz	$zero,.L0f18223c
/*  f182238:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f18223c:
/*  f18223c:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f182240:	11000003 */ 	beqz	$t0,.L0f182250
/*  f182244:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182248:	10000001 */ 	beqz	$zero,.L0f182250
/*  f18224c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f182250:
/*  f182250:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f182254:	11200003 */ 	beqz	$t1,.L0f182264
/*  f182258:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18225c:	10000001 */ 	beqz	$zero,.L0f182264
/*  f182260:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f182264:
/*  f182264:	00435021 */ 	addu	$t2,$v0,$v1
/*  f182268:	01445821 */ 	addu	$t3,$t2,$a0
/*  f18226c:	01656021 */ 	addu	$t4,$t3,$a1
/*  f182270:	022c082a */ 	slt	$at,$s1,$t4
/*  f182274:	1420ffcd */ 	bnez	$at,.L0f1821ac
/*  f182278:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18227c:
/*  f18227c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f182280:	02402025 */ 	or	$a0,$s2,$zero
/*  f182284:	1000006b */ 	beqz	$zero,.L0f182434
/*  f182288:	86630004 */ 	lh	$v1,0x4($s3)
.L0f18228c:
/*  f18228c:	54e00069 */ 	bnezl	$a3,.L0f182434
/*  f182290:	86630004 */ 	lh	$v1,0x4($s3)
/*  f182294:	866d0006 */ 	lh	$t5,0x6($s3)
/*  f182298:	8e8e0034 */ 	lw	$t6,0x34($s4)
/*  f18229c:	8e990484 */ 	lw	$t9,0x484($s4)
/*  f1822a0:	3c048009 */ 	lui	$a0,0x8009
/*  f1822a4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f1822a8:	a66f0006 */ 	sh	$t7,0x6($s3)
/*  f1822ac:	00194100 */ 	sll	$t0,$t9,0x4
/*  f1822b0:	86780006 */ 	lh	$t8,0x6($s3)
/*  f1822b4:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1822b8:	00084100 */ 	sll	$t0,$t0,0x4
/*  f1822bc:	25090960 */ 	addiu	$t1,$t0,0x960
/*  f1822c0:	0309082a */ 	slt	$at,$t8,$t1
/*  f1822c4:	1420005a */ 	bnez	$at,.L0f182430
/*  f1822c8:	240505b8 */ 	addiu	$a1,$zero,0x5b8
/*  f1822cc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1822d0:	44813000 */ 	mtc1	$at,$f6
/*  f1822d4:	240affff */ 	addiu	$t2,$zero,-1
/*  f1822d8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f1822dc:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1822e0:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f1822e4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1822e8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1822ec:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f1822f0:	00003025 */ 	or	$a2,$zero,$zero
/*  f1822f4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f1822f8:	00009025 */ 	or	$s2,$zero,$zero
/*  f1822fc:	0c004241 */ 	jal	func00010904
/*  f182300:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f182304:	3c03800b */ 	lui	$v1,0x800b
/*  f182308:	8c63c530 */ 	lw	$v1,-0x3ad0($v1)
/*  f18230c:	3c10800b */ 	lui	$s0,%hi(g_MpPlayerChrs)
/*  f182310:	2610c4d0 */ 	addiu	$s0,$s0,%lo(g_MpPlayerChrs)
/*  f182314:	1860001e */ 	blez	$v1,.L0f182390
/*  f182318:	00002825 */ 	or	$a1,$zero,$zero
/*  f18231c:	3c11800b */ 	lui	$s1,%hi(var800ac500)
/*  f182320:	2631c500 */ 	addiu	$s1,$s1,%lo(var800ac500)
.L0f182324:
/*  f182324:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f182328:	91a40125 */ 	lbu	$a0,0x125($t5)
/*  f18232c:	0fc63a5a */ 	jal	teamGetIndex
/*  f182330:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f182334:	866e0004 */ 	lh	$t6,0x4($s3)
/*  f182338:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f18233c:	144e000c */ 	bne	$v0,$t6,.L0f182370
/*  f182340:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182344:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f182348:	8668000e */ 	lh	$t0,0xe($s3)
/*  f18234c:	0225c021 */ 	addu	$t8,$s1,$a1
/*  f182350:	8de3001c */ 	lw	$v1,0x1c($t7)
/*  f182354:	84790028 */ 	lh	$t9,0x28($v1)
/*  f182358:	17280005 */ 	bne	$t9,$t0,.L0f182370
/*  f18235c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182360:	8f020000 */ 	lw	$v0,0x0($t8)
/*  f182364:	8449003e */ 	lh	$t1,0x3e($v0)
/*  f182368:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f18236c:	a44a003e */ 	sh	$t2,0x3e($v0)
.L0f182370:
/*  f182370:	3c03800b */ 	lui	$v1,0x800b
/*  f182374:	8c63c530 */ 	lw	$v1,-0x3ad0($v1)
/*  f182378:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f18237c:	24a50004 */ 	addiu	$a1,$a1,0x0004
/*  f182380:	0243082a */ 	slt	$at,$s2,$v1
/*  f182384:	1420ffe7 */ 	bnez	$at,.L0f182324
/*  f182388:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f18238c:	00009025 */ 	or	$s2,$zero,$zero
.L0f182390:
/*  f182390:	1860001b */ 	blez	$v1,.L0f182400
/*  f182394:	8e91028c */ 	lw	$s1,0x28c($s4)
/*  f182398:	3c10800b */ 	lui	$s0,%hi(g_MpPlayerChrs)
/*  f18239c:	2610c4d0 */ 	addiu	$s0,$s0,%lo(g_MpPlayerChrs)
/*  f1823a0:	8e020000 */ 	lw	$v0,0x0($s0)
.L0f1823a4:
/*  f1823a4:	8c4b02d4 */ 	lw	$t3,0x2d4($v0)
/*  f1823a8:	1560000e */ 	bnez	$t3,.L0f1823e4
/*  f1823ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1823b0:	0fc63a5a */ 	jal	teamGetIndex
/*  f1823b4:	90440125 */ 	lbu	$a0,0x125($v0)
/*  f1823b8:	866c0004 */ 	lh	$t4,0x4($s3)
/*  f1823bc:	144c0009 */ 	bne	$v0,$t4,.L0f1823e4
/*  f1823c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1823c4:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1823c8:	02402025 */ 	or	$a0,$s2,$zero
/*  f1823cc:	0fc5b9f1 */ 	jal	textGet
/*  f1823d0:	24045414 */ 	addiu	$a0,$zero,0x5414
/*  f1823d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1823d8:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1823dc:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f1823e0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1823e4:
/*  f1823e4:	3c0d800b */ 	lui	$t5,0x800b
/*  f1823e8:	8dadc530 */ 	lw	$t5,-0x3ad0($t5)
/*  f1823ec:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1823f0:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f1823f4:	024d082a */ 	slt	$at,$s2,$t5
/*  f1823f8:	5420ffea */ 	bnezl	$at,.L0f1823a4
/*  f1823fc:	8e020000 */ 	lw	$v0,0x0($s0)
.L0f182400:
/*  f182400:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f182404:	02202025 */ 	or	$a0,$s1,$zero
/*  f182408:	240effff */ 	addiu	$t6,$zero,-1
/*  f18240c:	a66e0004 */ 	sh	$t6,0x4($s3)
/*  f182410:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f182414:	3c0f800b */ 	lui	$t7,0x800b
/*  f182418:	8defcb94 */ 	lw	$t7,-0x346c($t7)
/*  f18241c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f182420:	31f98000 */ 	andi	$t9,$t7,0x8000
/*  f182424:	53200003 */ 	beqzl	$t9,.L0f182434
/*  f182428:	86630004 */ 	lh	$v1,0x4($s3)
/*  f18242c:	a6680008 */ 	sh	$t0,0x8($s3)
.L0f182430:
/*  f182430:	86630004 */ 	lh	$v1,0x4($s3)
.L0f182434:
/*  f182434:	2401ffff */ 	addiu	$at,$zero,-1
/*  f182438:	3c028008 */ 	lui	$v0,0x8008
/*  f18243c:	1461000c */ 	bne	$v1,$at,.L0f182470
/*  f182440:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f182444:	3c013f80 */ 	lui	$at,0x3f80
/*  f182448:	44811000 */ 	mtc1	$at,$f2
/*  f18244c:	3c013e80 */ 	lui	$at,0x3e80
/*  f182450:	44817000 */ 	mtc1	$at,$f14
/*  f182454:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f182458:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f18245c:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f182460:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f182464:	e7ae0164 */ 	swc1	$f14,0x164($sp)
/*  f182468:	1000001e */ 	beqz	$zero,.L0f1824e4
/*  f18246c:	e7ae015c */ 	swc1	$f14,0x15c($sp)
.L0f182470:
/*  f182470:	00581021 */ 	addu	$v0,$v0,$t8
/*  f182474:	8c427cc4 */ 	lw	$v0,0x7cc4($v0)
/*  f182478:	3c013b00 */ 	lui	$at,0x3b00
/*  f18247c:	44811000 */ 	mtc1	$at,$f2
/*  f182480:	00024e02 */ 	srl	$t1,$v0,0x18
/*  f182484:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f182488:	254b00ff */ 	addiu	$t3,$t2,0xff
/*  f18248c:	448b4000 */ 	mtc1	$t3,$f8
/*  f182490:	00026402 */ 	srl	$t4,$v0,0x10
/*  f182494:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f182498:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f18249c:	25ae00ff */ 	addiu	$t6,$t5,0xff
/*  f1824a0:	448e2000 */ 	mtc1	$t6,$f4
/*  f1824a4:	00027a02 */ 	srl	$t7,$v0,0x8
/*  f1824a8:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f1824ac:	272800ff */ 	addiu	$t0,$t9,0xff
/*  f1824b0:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f1824b4:	44885000 */ 	mtc1	$t0,$f10
/*  f1824b8:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f1824bc:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f1824c0:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f1824c4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1824c8:	e7b20164 */ 	swc1	$f18,0x164($sp)
/*  f1824cc:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f1824d0:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f1824d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1824d8:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f1824dc:	e7a80160 */ 	swc1	$f8,0x160($sp)
/*  f1824e0:	e7a4015c */ 	swc1	$f4,0x15c($sp)
.L0f1824e4:
/*  f1824e4:	c7a60164 */ 	lwc1	$f6,0x164($sp)
/*  f1824e8:	46003032 */ 	c.eq.s	$f6,$f0
/*  f1824ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1824f0:	4503001c */ 	bc1tl	.L0f182564
/*  f1824f4:	c7a80160 */ 	lwc1	$f8,0x160($sp)
/*  f1824f8:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f1824fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f182500:	3c017f1c */ 	lui	$at,%hi(var7f1b8940)
/*  f182504:	58600017 */ 	blezl	$v1,.L0f182564
/*  f182508:	c7a80160 */ 	lwc1	$f8,0x160($sp)
/*  f18250c:	c4288940 */ 	lwc1	$f8,%lo(var7f1b8940)($at)
/*  f182510:	3c017f1c */ 	lui	$at,%hi(var7f1b8944)
/*  f182514:	c4208944 */ 	lwc1	$f0,%lo(var7f1b8944)($at)
/*  f182518:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f18251c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182520:	c66e0030 */ 	lwc1	$f14,0x30($s3)
/*  f182524:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182528:	0043082a */ 	slt	$at,$v0,$v1
/*  f18252c:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f182530:	5020000a */ 	beqzl	$at,.L0f18255c
/*  f182534:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f182538:	46121380 */ 	add.s	$f14,$f2,$f18
.L0f18253c:
/*  f18253c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182540:	0043082a */ 	slt	$at,$v0,$v1
/*  f182544:	e66e0030 */ 	swc1	$f14,0x30($s3)
/*  f182548:	c66e0030 */ 	lwc1	$f14,0x30($s3)
/*  f18254c:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f182550:	5420fffa */ 	bnezl	$at,.L0f18253c
/*  f182554:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f182558:	46121380 */ 	add.s	$f14,$f2,$f18
.L0f18255c:
/*  f18255c:	e66e0030 */ 	swc1	$f14,0x30($s3)
/*  f182560:	c7a80160 */ 	lwc1	$f8,0x160($sp)
.L0f182564:
/*  f182564:	3c017f1c */ 	lui	$at,%hi(var7f1b8948)
/*  f182568:	c4208948 */ 	lwc1	$f0,%lo(var7f1b8948)($at)
/*  f18256c:	460c4032 */ 	c.eq.s	$f8,$f12
/*  f182570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182574:	4503001a */ 	bc1tl	.L0f1825e0
/*  f182578:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f18257c:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f182580:	00001025 */ 	or	$v0,$zero,$zero
/*  f182584:	3c017f1c */ 	lui	$at,%hi(var7f1b894c)
/*  f182588:	58600015 */ 	blezl	$v1,.L0f1825e0
/*  f18258c:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f182590:	c426894c */ 	lwc1	$f6,%lo(var7f1b894c)($at)
/*  f182594:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f182598:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18259c:	c66e0034 */ 	lwc1	$f14,0x34($s3)
/*  f1825a0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1825a4:	0043082a */ 	slt	$at,$v0,$v1
/*  f1825a8:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f1825ac:	5020000a */ 	beqzl	$at,.L0f1825d8
/*  f1825b0:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f1825b4:	46121380 */ 	add.s	$f14,$f2,$f18
.L0f1825b8:
/*  f1825b8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1825bc:	0043082a */ 	slt	$at,$v0,$v1
/*  f1825c0:	e66e0034 */ 	swc1	$f14,0x34($s3)
/*  f1825c4:	c66e0034 */ 	lwc1	$f14,0x34($s3)
/*  f1825c8:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f1825cc:	5420fffa */ 	bnezl	$at,.L0f1825b8
/*  f1825d0:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f1825d4:	46121380 */ 	add.s	$f14,$f2,$f18
.L0f1825d8:
/*  f1825d8:	e66e0034 */ 	swc1	$f14,0x34($s3)
/*  f1825dc:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
.L0f1825e0:
/*  f1825e0:	46103032 */ 	c.eq.s	$f6,$f16
/*  f1825e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1825e8:	4503001a */ 	bc1tl	.L0f182654
/*  f1825ec:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1825f0:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f1825f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1825f8:	3c017f1c */ 	lui	$at,%hi(var7f1b8950)
/*  f1825fc:	58600015 */ 	blezl	$v1,.L0f182654
/*  f182600:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f182604:	c4288950 */ 	lwc1	$f8,%lo(var7f1b8950)($at)
/*  f182608:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f18260c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182610:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f182614:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182618:	0043082a */ 	slt	$at,$v0,$v1
/*  f18261c:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f182620:	5020000a */ 	beqzl	$at,.L0f18264c
/*  f182624:	46121400 */ 	add.s	$f16,$f2,$f18
/*  f182628:	46121400 */ 	add.s	$f16,$f2,$f18
.L0f18262c:
/*  f18262c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182630:	0043082a */ 	slt	$at,$v0,$v1
/*  f182634:	e6700038 */ 	swc1	$f16,0x38($s3)
/*  f182638:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f18263c:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f182640:	5420fffa */ 	bnezl	$at,.L0f18262c
/*  f182644:	46121400 */ 	add.s	$f16,$f2,$f18
/*  f182648:	46121400 */ 	add.s	$f16,$f2,$f18
.L0f18264c:
/*  f18264c:	e6700038 */ 	swc1	$f16,0x38($s3)
.L0f182650:
/*  f182650:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f182654:
/*  f182654:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f182658:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f18265c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f182660:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f182664:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f182668:	03e00008 */ 	jr	$ra
/*  f18266c:	27bd0188 */ 	addiu	$sp,$sp,0x188
);

GLOBAL_ASM(
glabel scenarioKohCallback18
/*  f182670:	3c0e800a */ 	lui	$t6,0x800a
/*  f182674:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f182678:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f18267c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f182680:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f182684:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f182688:	00808025 */ 	or	$s0,$a0,$zero
/*  f18268c:	8de20004 */ 	lw	$v0,0x4($t7)
/*  f182690:	0fc63a5a */ 	jal	teamGetIndex
/*  f182694:	90440125 */ 	lbu	$a0,0x125($v0)
/*  f182698:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f18269c:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f1826a0:	84780004 */ 	lh	$t8,0x4($v1)
/*  f1826a4:	54580094 */ 	bnel	$v0,$t8,.L0f1828f8
/*  f1826a8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1826ac:	84790008 */ 	lh	$t9,0x8($v1)
/*  f1826b0:	57200091 */ 	bnezl	$t9,.L0f1828f8
/*  f1826b4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1826b8:	0c002f40 */ 	jal	func0000bd00
/*  f1826bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1826c0:	0c002f22 */ 	jal	func0000bc88
/*  f1826c4:	a7a2004e */ 	sh	$v0,0x4e($sp)
/*  f1826c8:	87aa004e */ 	lh	$t2,0x4e($sp)
/*  f1826cc:	04410003 */ 	bgez	$v0,.L0f1826dc
/*  f1826d0:	00024843 */ 	sra	$t1,$v0,0x1
/*  f1826d4:	24410001 */ 	addiu	$at,$v0,0x1
/*  f1826d8:	00014843 */ 	sra	$t1,$at,0x1
.L0f1826dc:
/*  f1826dc:	012a2821 */ 	addu	$a1,$t1,$t2
/*  f1826e0:	0c002f44 */ 	jal	func0000bd10
/*  f1826e4:	afa50098 */ 	sw	$a1,0x98($sp)
/*  f1826e8:	3c04800a */ 	lui	$a0,0x800a
/*  f1826ec:	8c84a444 */ 	lw	$a0,-0x5bbc($a0)
/*  f1826f0:	240800f0 */ 	addiu	$t0,$zero,0xf0
/*  f1826f4:	3c0d800b */ 	lui	$t5,0x800b
/*  f1826f8:	00880019 */ 	multu	$a0,$t0
/*  f1826fc:	85adc116 */ 	lh	$t5,-0x3eea($t5)
/*  f182700:	24073840 */ 	addiu	$a3,$zero,0x3840
/*  f182704:	00047900 */ 	sll	$t7,$a0,0x4
/*  f182708:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f18270c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f182710:	25f80258 */ 	addiu	$t8,$t7,0x258
/*  f182714:	244b000a */ 	addiu	$t3,$v0,0xa
/*  f182718:	afab0094 */ 	sw	$t3,0x94($sp)
/*  f18271c:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f182720:	00006012 */ 	mflo	$t4
/*  f182724:	018d1823 */ 	subu	$v1,$t4,$t5
/*  f182728:	24630960 */ 	addiu	$v1,$v1,0x960
/*  f18272c:	0067001a */ 	div	$zero,$v1,$a3
/*  f182730:	00002812 */ 	mflo	$a1
/*  f182734:	00a03025 */ 	or	$a2,$a1,$zero
/*  f182738:	14e00002 */ 	bnez	$a3,.L0f182744
/*  f18273c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182740:	0007000d */ 	break	0x7
.L0f182744:
/*  f182744:	2401ffff */ 	addiu	$at,$zero,-1
/*  f182748:	14e10004 */ 	bne	$a3,$at,.L0f18275c
/*  f18274c:	3c018000 */ 	lui	$at,0x8000
/*  f182750:	14610002 */ 	bne	$v1,$at,.L0f18275c
/*  f182754:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182758:	0006000d */ 	break	0x6
.L0f18275c:
/*  f18275c:	00a70019 */ 	multu	$a1,$a3
/*  f182760:	24010e10 */ 	addiu	$at,$zero,0xe10
/*  f182764:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f182768:	00007012 */ 	mflo	$t6
/*  f18276c:	006e1823 */ 	subu	$v1,$v1,$t6
/*  f182770:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182774:	0301001a */ 	div	$zero,$t8,$at
/*  f182778:	0000c812 */ 	mflo	$t9
/*  f18277c:	53200015 */ 	beqzl	$t9,.L0f1827d4
/*  f182780:	246a00ef */ 	addiu	$t2,$v1,0xef
/*  f182784:	246900ef */ 	addiu	$t1,$v1,0xef
/*  f182788:	0128001a */ 	div	$zero,$t1,$t0
/*  f18278c:	00003812 */ 	mflo	$a3
/*  f182790:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f182794:	24a58498 */ 	addiu	$a1,$a1,-31592
/*  f182798:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f18279c:	15000002 */ 	bnez	$t0,.L0f1827a8
/*  f1827a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1827a4:	0007000d */ 	break	0x7
.L0f1827a8:
/*  f1827a8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1827ac:	15010004 */ 	bne	$t0,$at,.L0f1827c0
/*  f1827b0:	3c018000 */ 	lui	$at,0x8000
/*  f1827b4:	15210002 */ 	bne	$t1,$at,.L0f1827c0
/*  f1827b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1827bc:	0006000d */ 	break	0x6
.L0f1827c0:
/*  f1827c0:	0c004dad */ 	jal	sprintf
/*  f1827c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1827c8:	10000010 */ 	beqz	$zero,.L0f18280c
/*  f1827cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1827d0:	246a00ef */ 	addiu	$t2,$v1,0xef
.L0f1827d4:
/*  f1827d4:	0148001a */ 	div	$zero,$t2,$t0
/*  f1827d8:	00003012 */ 	mflo	$a2
/*  f1827dc:	24a584a0 */ 	addiu	$a1,$a1,-31584
/*  f1827e0:	15000002 */ 	bnez	$t0,.L0f1827ec
/*  f1827e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1827e8:	0007000d */ 	break	0x7
.L0f1827ec:
/*  f1827ec:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1827f0:	15010004 */ 	bne	$t0,$at,.L0f182804
/*  f1827f4:	3c018000 */ 	lui	$at,0x8000
/*  f1827f8:	15410002 */ 	bne	$t2,$at,.L0f182804
/*  f1827fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182800:	0006000d */ 	break	0x6
.L0f182804:
/*  f182804:	0c004dad */ 	jal	sprintf
/*  f182808:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18280c:
/*  f18280c:	0fc54d8a */ 	jal	func0f153628
/*  f182810:	02002025 */ 	or	$a0,$s0,$zero
/*  f182814:	3c0b8008 */ 	lui	$t3,0x8008
/*  f182818:	8d6bfb04 */ 	lw	$t3,-0x4fc($t3)
/*  f18281c:	3c078008 */ 	lui	$a3,0x8008
/*  f182820:	00408025 */ 	or	$s0,$v0,$zero
/*  f182824:	8ce7fb08 */ 	lw	$a3,-0x4f8($a3)
/*  f182828:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f18282c:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f182830:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f182834:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f182838:	0fc55cbe */ 	jal	func0f1572f8
/*  f18283c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f182840:	8fa700a0 */ 	lw	$a3,0xa0($sp)
/*  f182844:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f182848:	8fa2009c */ 	lw	$v0,0x9c($sp)
/*  f18284c:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f182850:	04e10003 */ 	bgez	$a3,.L0f182860
/*  f182854:	00076043 */ 	sra	$t4,$a3,0x1
/*  f182858:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f18285c:	00016043 */ 	sra	$t4,$at,0x1
.L0f182860:
/*  f182860:	00ac2823 */ 	subu	$a1,$a1,$t4
/*  f182864:	00e53821 */ 	addu	$a3,$a3,$a1
/*  f182868:	00461021 */ 	addu	$v0,$v0,$a2
/*  f18286c:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f182870:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f182874:	afa700a0 */ 	sw	$a3,0xa0($sp)
/*  f182878:	afa50098 */ 	sw	$a1,0x98($sp)
/*  f18287c:	0fc54e64 */ 	jal	func0f153990
/*  f182880:	02002025 */ 	or	$a0,$s0,$zero
/*  f182884:	0c002f02 */ 	jal	func0000bc08
/*  f182888:	00408025 */ 	or	$s0,$v0,$zero
/*  f18288c:	0c002f06 */ 	jal	func0000bc18
/*  f182890:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f182894:	3c0d8008 */ 	lui	$t5,0x8008
/*  f182898:	3c0e8008 */ 	lui	$t6,0x8008
/*  f18289c:	8dcefafc */ 	lw	$t6,-0x504($t6)
/*  f1828a0:	8dadfb00 */ 	lw	$t5,-0x500($t5)
/*  f1828a4:	87b9004c */ 	lh	$t9,0x4c($sp)
/*  f1828a8:	3c0f00ff */ 	lui	$t7,0xff
/*  f1828ac:	35ef00a0 */ 	ori	$t7,$t7,0xa0
/*  f1828b0:	241800a0 */ 	addiu	$t8,$zero,0xa0
/*  f1828b4:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1828b8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f1828bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1828c0:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f1828c4:	27a60094 */ 	addiu	$a2,$sp,0x94
/*  f1828c8:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f1828cc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1828d0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1828d4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1828d8:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1828dc:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1828e0:	0fc55b92 */ 	jal	func0f156e48
/*  f1828e4:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f1828e8:	0fc54de0 */ 	jal	func0f153780
/*  f1828ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f1828f0:	00408025 */ 	or	$s0,$v0,$zero
/*  f1828f4:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1828f8:
/*  f1828f8:	02001025 */ 	or	$v0,$s0,$zero
/*  f1828fc:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f182900:	03e00008 */ 	jr	$ra
/*  f182904:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

void scenarioKohKill(struct mpchr *mpchr, s32 arg1, s32 *score, s32 *arg3)
{
	struct mpchr *loopmpchr;
	s32 i;

	*score = 0;
	*score = mpchr->unk3e;

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == arg1) {
				*score -= mpchr->unk24[i];
			} else {
				if (i < 4) {
					loopmpchr = &g_MpPlayers[i].base;
				} else {
					loopmpchr = &g_MpSimulants[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->unk24[i];
				} else {
					*score += mpchr->unk24[i];
				}
			}
		}
	}

	*arg3 = mpchr->unk3c;
}

s32 scenarioKohRadar(s32 value)
{
	if (g_MpSetup.options & MPOPTION_HILLONRADAR && g_ScenarioData.koh.unk08 == 0) {
		struct coord dist;
		u32 colour;
		dist.x = g_ScenarioData.koh.hillpos.x - g_Vars.currentplayer->prop->pos.x;
		dist.y = g_ScenarioData.koh.hillpos.y - g_Vars.currentplayer->prop->pos.y;
		dist.z = g_ScenarioData.koh.hillpos.z - g_Vars.currentplayer->prop->pos.z;

		if (g_ScenarioData.koh.occupiedteam == -1) {
			colour = 0xff0000;
		} else {
			colour = g_TeamColours[g_ScenarioData.koh.occupiedteam];
		}

		value = func0f18e9ec(value, NULL, &dist, colour, 0, 1);
	}

	return value;
}

GLOBAL_ASM(
glabel func0f182aac
/*  f182aac:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f182ab0:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f182ab4:	8462000c */ 	lh	$v0,0xc($v1)
/*  f182ab8:	28410009 */ 	slti	$at,$v0,0x9
/*  f182abc:	10200008 */ 	beqz	$at,.L0f182ae0
/*  f182ac0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182ac4:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f182ac8:	00027840 */ 	sll	$t7,$v0,0x1
/*  f182acc:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f182ad0:	a70e0012 */ 	sh	$t6,0x12($t8)
/*  f182ad4:	8479000c */ 	lh	$t9,0xc($v1)
/*  f182ad8:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f182adc:	a468000c */ 	sh	$t0,0xc($v1)
.L0f182ae0:
/*  f182ae0:	03e00008 */ 	jr	$ra
/*  f182ae4:	00000000 */ 	sll	$zero,$zero,0x0
);

bool scenarioKohIsRoomHighlighted(s16 room)
{
	return room == g_ScenarioData.koh.hillroom;
}

GLOBAL_ASM(
glabel scenarioKohCallback38
/*  f182b08:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f182b0c:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f182b10:	8458000e */ 	lh	$t8,0xe($v0)
/*  f182b14:	00047400 */ 	sll	$t6,$a0,0x10
/*  f182b18:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f182b1c:	15f8001a */ 	bne	$t7,$t8,.L0f182b88
/*  f182b20:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f182b24:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f182b28:	8cc80000 */ 	lw	$t0,0x0($a2)
/*  f182b2c:	8ce90000 */ 	lw	$t1,0x0($a3)
/*  f182b30:	44992000 */ 	mtc1	$t9,$f4
/*  f182b34:	44883000 */ 	mtc1	$t0,$f6
/*  f182b38:	c44a0030 */ 	lwc1	$f10,0x30($v0)
/*  f182b3c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f182b40:	44894000 */ 	mtc1	$t1,$f8
/*  f182b44:	c4500034 */ 	lwc1	$f16,0x34($v0)
/*  f182b48:	c4520038 */ 	lwc1	$f18,0x38($v0)
/*  f182b4c:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f182b50:	460a0002 */ 	mul.s	$f0,$f0,$f10
/*  f182b54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182b58:	46101082 */ 	mul.s	$f2,$f2,$f16
/*  f182b5c:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f182b60:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f182b64:	46126302 */ 	mul.s	$f12,$f12,$f18
/*  f182b68:	440b2000 */ 	mfc1	$t3,$f4
/*  f182b6c:	4600118d */ 	trunc.w.s	$f6,$f2
/*  f182b70:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f182b74:	4600620d */ 	trunc.w.s	$f8,$f12
/*  f182b78:	440d3000 */ 	mfc1	$t5,$f6
/*  f182b7c:	440f4000 */ 	mfc1	$t7,$f8
/*  f182b80:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f182b84:	acef0000 */ 	sw	$t7,0x0($a3)
.L0f182b88:
/*  f182b88:	03e00008 */ 	jr	$ra
/*  f182b8c:	00000000 */ 	sll	$zero,$zero,0x0
);

void scenarioHtmInit(void)
{
	g_ScenarioData.htm.uplink = NULL;
}

s32 scenarioHtmCallback08(void)
{
	return 2;
}

GLOBAL_ASM(
glabel func0f182ba4
/*  f182ba4:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f182ba8:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f182bac:	84580000 */ 	lh	$t8,0x0($v0)
/*  f182bb0:	00047400 */ 	sll	$t6,$a0,0x10
/*  f182bb4:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f182bb8:	2b01003c */ 	slti	$at,$t8,0x3c
/*  f182bbc:	1020000b */ 	beqz	$at,.L0f182bec
/*  f182bc0:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f182bc4:	3c19800b */ 	lui	$t9,0x800b
/*  f182bc8:	8739c110 */ 	lh	$t9,-0x3ef0($t9)
/*  f182bcc:	3c0a800b */ 	lui	$t2,0x800b
/*  f182bd0:	3c01800b */ 	lui	$at,0x800b
/*  f182bd4:	00194040 */ 	sll	$t0,$t9,0x1
/*  f182bd8:	00484821 */ 	addu	$t1,$v0,$t0
/*  f182bdc:	a52f0004 */ 	sh	$t7,0x4($t1)
/*  f182be0:	854ac110 */ 	lh	$t2,-0x3ef0($t2)
/*  f182be4:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f182be8:	a42bc110 */ 	sh	$t3,-0x3ef0($at)
.L0f182bec:
/*  f182bec:	03e00008 */ 	jr	$ra
/*  f182bf0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f182bf4
/*  f182bf4:	3c04800b */ 	lui	$a0,%hi(g_ScenarioData)
/*  f182bf8:	2484c110 */ 	addiu	$a0,$a0,%lo(g_ScenarioData)
/*  f182bfc:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f182c00:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f182c04:	3c02800b */ 	lui	$v0,0x800b
/*  f182c08:	a4800000 */ 	sh	$zero,0x0($a0)
/*  f182c0c:	a4800002 */ 	sh	$zero,0x2($a0)
/*  f182c10:	ac800138 */ 	sw	$zero,0x138($a0)
/*  f182c14:	a48500d0 */ 	sh	$a1,0xd0($a0)
/*  f182c18:	a48500d2 */ 	sh	$a1,0xd2($a0)
/*  f182c1c:	ac8500d4 */ 	sw	$a1,0xd4($a0)
/*  f182c20:	ac800140 */ 	sw	$zero,0x140($a0)
/*  f182c24:	2442c140 */ 	addiu	$v0,$v0,-16064
/*  f182c28:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
.L0f182c2c:
/*  f182c2c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f182c30:	0062082b */ 	sltu	$at,$v1,$v0
/*  f182c34:	ac6000d4 */ 	sw	$zero,0xd4($v1)
/*  f182c38:	1420fffc */ 	bnez	$at,.L0f182c2c
/*  f182c3c:	ac600104 */ 	sw	$zero,0x104($v1)
/*  f182c40:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f182c44:	3c02800b */ 	lui	$v0,0x800b
/*  f182c48:	2442c188 */ 	addiu	$v0,$v0,-15992
/*  f182c4c:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
.L0f182c50:
/*  f182c50:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f182c54:	0062082b */ 	sltu	$at,$v1,$v0
/*  f182c58:	1420fffd */ 	bnez	$at,.L0f182c50
/*  f182c5c:	a4650002 */ 	sh	$a1,0x2($v1)
/*  f182c60:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f182c64:	3c04800b */ 	lui	$a0,0x800b
/*  f182c68:	2484c11c */ 	addiu	$a0,$a0,-16100
/*  f182c6c:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f182c70:	240200ff */ 	addiu	$v0,$zero,0xff
.L0f182c74:
/*  f182c74:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f182c78:	ac600070 */ 	sw	$zero,0x70($v1)
/*  f182c7c:	ac600074 */ 	sw	$zero,0x74($v1)
/*  f182c80:	a4650078 */ 	sh	$a1,0x78($v1)
/*  f182c84:	a062007a */ 	sb	$v0,0x7a($v1)
/*  f182c88:	1464fffa */ 	bne	$v1,$a0,.L0f182c74
/*  f182c8c:	a062007b */ 	sb	$v0,0x7b($v1)
/*  f182c90:	03e00008 */ 	jr	$ra
/*  f182c94:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f182c98
/*  f182c98:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f182c9c:	3c0f8008 */ 	lui	$t7,%hi(var80086e14)
/*  f182ca0:	25ef6e14 */ 	addiu	$t7,$t7,%lo(var80086e14)
/*  f182ca4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f182ca8:	25e80060 */ 	addiu	$t0,$t7,0x60
/*  f182cac:	27ae0080 */ 	addiu	$t6,$sp,0x80
.L0f182cb0:
/*  f182cb0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f182cb4:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f182cb8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f182cbc:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f182cc0:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f182cc4:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f182cc8:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f182ccc:	15e8fff8 */ 	bne	$t7,$t0,.L0f182cb0
/*  f182cd0:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f182cd4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f182cd8:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f182cdc:	3c02800a */ 	lui	$v0,0x800a
/*  f182ce0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f182ce4:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f182ce8:	8c42a2fc */ 	lw	$v0,-0x5d04($v0)
/*  f182cec:	00002025 */ 	or	$a0,$zero,$zero
/*  f182cf0:	27a70020 */ 	addiu	$a3,$sp,0x20
/*  f182cf4:	10400013 */ 	beqz	$v0,.L0f182d44
/*  f182cf8:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f182cfc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f182d00:	90490000 */ 	lbu	$t1,0x0($v0)
.L0f182d04:
/*  f182d04:	54a9000a */ 	bnel	$a1,$t1,.L0f182d30
/*  f182d08:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f182d0c:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f182d10:	00045880 */ 	sll	$t3,$a0,0x2
/*  f182d14:	00eb6021 */ 	addu	$t4,$a3,$t3
/*  f182d18:	906a0003 */ 	lbu	$t2,0x3($v1)
/*  f182d1c:	54ca0004 */ 	bnel	$a2,$t2,.L0f182d30
/*  f182d20:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f182d24:	ad830000 */ 	sw	$v1,0x0($t4)
/*  f182d28:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f182d2c:	8c420020 */ 	lw	$v0,0x20($v0)
.L0f182d30:
/*  f182d30:	28810014 */ 	slti	$at,$a0,0x14
/*  f182d34:	10400003 */ 	beqz	$v0,.L0f182d44
/*  f182d38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182d3c:	5420fff1 */ 	bnezl	$at,.L0f182d04
/*  f182d40:	90490000 */ 	lbu	$t1,0x0($v0)
.L0f182d44:
/*  f182d44:	1880001a */ 	blez	$a0,.L0f182db0
/*  f182d48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182d4c:	0c004b70 */ 	jal	random
/*  f182d50:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f182d54:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f182d58:	27a70020 */ 	addiu	$a3,$sp,0x20
/*  f182d5c:	3c058008 */ 	lui	$a1,%hi(var800869ec)
/*  f182d60:	0044001b */ 	divu	$zero,$v0,$a0
/*  f182d64:	24a569ec */ 	addiu	$a1,$a1,%lo(var800869ec)
/*  f182d68:	14800002 */ 	bnez	$a0,.L0f182d74
/*  f182d6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182d70:	0007000d */ 	break	0x7
.L0f182d74:
/*  f182d74:	00002010 */ 	mfhi	$a0
/*  f182d78:	00046880 */ 	sll	$t5,$a0,0x2
/*  f182d7c:	00edc821 */ 	addu	$t9,$a3,$t5
/*  f182d80:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f182d84:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f182d88:	8f080040 */ 	lw	$t0,0x40($t8)
/*  f182d8c:	350f0004 */ 	ori	$t7,$t0,0x4
/*  f182d90:	af0f0040 */ 	sw	$t7,0x40($t8)
/*  f182d94:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f182d98:	906e0002 */ 	lbu	$t6,0x2($v1)
/*  f182d9c:	35c90004 */ 	ori	$t1,$t6,0x4
/*  f182da0:	a0690002 */ 	sb	$t1,0x2($v1)
/*  f182da4:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f182da8:	10000015 */ 	beqz	$zero,.L0f182e00
/*  f182dac:	85460006 */ 	lh	$a2,0x6($t2)
.L0f182db0:
/*  f182db0:	3c0b800b */ 	lui	$t3,0x800b
/*  f182db4:	856bc110 */ 	lh	$t3,-0x3ef0($t3)
/*  f182db8:	59600011 */ 	blezl	$t3,.L0f182e00
/*  f182dbc:	00003025 */ 	or	$a2,$zero,$zero
/*  f182dc0:	0c004b70 */ 	jal	random
/*  f182dc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182dc8:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f182dcc:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f182dd0:	846c0000 */ 	lh	$t4,0x0($v1)
/*  f182dd4:	004c001b */ 	divu	$zero,$v0,$t4
/*  f182dd8:	00006810 */ 	mfhi	$t5
/*  f182ddc:	000dc840 */ 	sll	$t9,$t5,0x1
/*  f182de0:	0079c021 */ 	addu	$t8,$v1,$t9
/*  f182de4:	15800002 */ 	bnez	$t4,.L0f182df0
/*  f182de8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182dec:	0007000d */ 	break	0x7
.L0f182df0:
/*  f182df0:	87060004 */ 	lh	$a2,0x4($t8)
/*  f182df4:	10000002 */ 	beqz	$zero,.L0f182e00
/*  f182df8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182dfc:	00003025 */ 	or	$a2,$zero,$zero
.L0f182e00:
/*  f182e00:	3c04800b */ 	lui	$a0,%hi(var800ac460)
/*  f182e04:	2484c460 */ 	addiu	$a0,$a0,%lo(var800ac460)
/*  f182e08:	27a80080 */ 	addiu	$t0,$sp,0x80
/*  f182e0c:	250e0060 */ 	addiu	$t6,$t0,0x60
/*  f182e10:	00804825 */ 	or	$t1,$a0,$zero
.L0f182e14:
/*  f182e14:	8d010000 */ 	lw	$at,0x0($t0)
/*  f182e18:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f182e1c:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f182e20:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*  f182e24:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*  f182e28:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*  f182e2c:	8d01fffc */ 	lw	$at,-0x4($t0)
/*  f182e30:	150efff8 */ 	bne	$t0,$t6,.L0f182e14
/*  f182e34:	ad21fffc */ 	sw	$at,-0x4($t1)
/*  f182e38:	8d010000 */ 	lw	$at,0x0($t0)
/*  f182e3c:	240503e7 */ 	addiu	$a1,$zero,0x3e7
/*  f182e40:	ad210000 */ 	sw	$at,0x0($t1)
/*  f182e44:	8d0e0004 */ 	lw	$t6,0x4($t0)
/*  f182e48:	ad2e0004 */ 	sw	$t6,0x4($t1)
/*  f182e4c:	0fc0359c */ 	jal	func0f00d670
/*  f182e50:	a4860006 */ 	sh	$a2,0x6($a0)
/*  f182e54:	3c04800b */ 	lui	$a0,%hi(var800ac460)
/*  f182e58:	2484c460 */ 	addiu	$a0,$a0,%lo(var800ac460)
/*  f182e5c:	908a0002 */ 	lbu	$t2,0x2($a0)
/*  f182e60:	8c8c0014 */ 	lw	$t4,0x14($a0)
/*  f182e64:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f182e68:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f182e6c:	314bfffb */ 	andi	$t3,$t2,0xfffb
/*  f182e70:	a08b0002 */ 	sb	$t3,0x2($a0)
/*  f182e74:	11800004 */ 	beqz	$t4,.L0f182e88
/*  f182e78:	ac6c013c */ 	sw	$t4,0x13c($v1)
/*  f182e7c:	9199003f */ 	lbu	$t9,0x3f($t4)
/*  f182e80:	37380020 */ 	ori	$t8,$t9,0x20
/*  f182e84:	a198003f */ 	sb	$t8,0x3f($t4)
.L0f182e88:
/*  f182e88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f182e8c:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f182e90:	03e00008 */ 	jr	$ra
/*  f182e94:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel scenarioHtmReset
/*  f182e98:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f182e9c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f182ea0:	3c11800a */ 	lui	$s1,0x800a
/*  f182ea4:	8e31a2fc */ 	lw	$s1,-0x5d04($s1)
/*  f182ea8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f182eac:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f182eb0:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f182eb4:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f182eb8:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f182ebc:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f182ec0:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f182ec4:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f182ec8:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f182ecc:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f182ed0:	0200b025 */ 	or	$s6,$s0,$zero
/*  f182ed4:	12200017 */ 	beqz	$s1,.L0f182f34
/*  f182ed8:	00009025 */ 	or	$s2,$zero,$zero
/*  f182edc:	241500c1 */ 	addiu	$s5,$zero,0xc1
/*  f182ee0:	24140014 */ 	addiu	$s4,$zero,0x14
/*  f182ee4:	24130007 */ 	addiu	$s3,$zero,0x7
/*  f182ee8:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f182eec:	922e0000 */ 	lbu	$t6,0x0($s1)
.L0f182ef0:
/*  f182ef0:	564e000d */ 	bnel	$s2,$t6,.L0f182f28
/*  f182ef4:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f182ef8:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f182efc:	90430003 */ 	lbu	$v1,0x3($v0)
/*  f182f00:	52630004 */ 	beql	$s3,$v1,.L0f182f14
/*  f182f04:	844f0004 */ 	lh	$t7,0x4($v0)
/*  f182f08:	56830007 */ 	bnel	$s4,$v1,.L0f182f28
/*  f182f0c:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f182f10:	844f0004 */ 	lh	$t7,0x4($v0)
.L0f182f14:
/*  f182f14:	56af0004 */ 	bnel	$s5,$t7,.L0f182f28
/*  f182f18:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f182f1c:	0fc60ae9 */ 	jal	func0f182ba4
/*  f182f20:	84440006 */ 	lh	$a0,0x6($v0)
/*  f182f24:	8e310020 */ 	lw	$s1,0x20($s1)
.L0f182f28:
/*  f182f28:	5620fff1 */ 	bnezl	$s1,.L0f182ef0
/*  f182f2c:	922e0000 */ 	lbu	$t6,0x0($s1)
/*  f182f30:	00009025 */ 	or	$s2,$zero,$zero
.L0f182f34:
/*  f182f34:	0fc60ae7 */ 	jal	scenarioHtmCallback08
/*  f182f38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182f3c:	3c01800b */ 	lui	$at,0x800b
/*  f182f40:	0fc60ae7 */ 	jal	scenarioHtmCallback08
/*  f182f44:	a420c112 */ 	sh	$zero,-0x3eee($at)
/*  f182f48:	3c18800b */ 	lui	$t8,0x800b
/*  f182f4c:	8718c112 */ 	lh	$t8,-0x3eee($t8)
/*  f182f50:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f182f54:	2411000c */ 	addiu	$s1,$zero,0xc
/*  f182f58:	0302082a */ 	slt	$at,$t8,$v0
/*  f182f5c:	10200020 */ 	beqz	$at,.L0f182fe0
/*  f182f60:	00000000 */ 	sll	$zero,$zero,0x0
.L0f182f64:
/*  f182f64:	0c004b70 */ 	jal	random
/*  f182f68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182f6c:	3c19800b */ 	lui	$t9,0x800b
/*  f182f70:	8739c110 */ 	lh	$t9,-0x3ef0($t9)
/*  f182f74:	0059001b */ 	divu	$zero,$v0,$t9
/*  f182f78:	00001810 */ 	mfhi	$v1
/*  f182f7c:	00034040 */ 	sll	$t0,$v1,0x1
/*  f182f80:	02082821 */ 	addu	$a1,$s0,$t0
/*  f182f84:	84a40004 */ 	lh	$a0,0x4($a1)
/*  f182f88:	17200002 */ 	bnez	$t9,.L0f182f94
/*  f182f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182f90:	0007000d */ 	break	0x7
.L0f182f94:
/*  f182f94:	1880fff3 */ 	blez	$a0,.L0f182f64
/*  f182f98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182f9c:	3c09800b */ 	lui	$t1,0x800b
/*  f182fa0:	8529c112 */ 	lh	$t1,-0x3eee($t1)
/*  f182fa4:	3c0c800b */ 	lui	$t4,0x800b
/*  f182fa8:	3c01800b */ 	lui	$at,0x800b
/*  f182fac:	01310019 */ 	multu	$t1,$s1
/*  f182fb0:	00005012 */ 	mflo	$t2
/*  f182fb4:	020a5821 */ 	addu	$t3,$s0,$t2
/*  f182fb8:	a5640084 */ 	sh	$a0,0x84($t3)
/*  f182fbc:	858cc112 */ 	lh	$t4,-0x3eee($t4)
/*  f182fc0:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f182fc4:	a42dc112 */ 	sh	$t5,-0x3eee($at)
/*  f182fc8:	0fc60ae7 */ 	jal	scenarioHtmCallback08
/*  f182fcc:	a4b30004 */ 	sh	$s3,0x4($a1)
/*  f182fd0:	86ce0002 */ 	lh	$t6,0x2($s6)
/*  f182fd4:	01c2082a */ 	slt	$at,$t6,$v0
/*  f182fd8:	1420ffe2 */ 	bnez	$at,.L0f182f64
/*  f182fdc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f182fe0:
/*  f182fe0:	0fc60ae7 */ 	jal	scenarioHtmCallback08
/*  f182fe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182fe8:	3c0f800b */ 	lui	$t7,0x800b
/*  f182fec:	85efc112 */ 	lh	$t7,-0x3eee($t7)
/*  f182ff0:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f182ff4:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f182ff8:	19e00006 */ 	blez	$t7,.L0f183014
/*  f182ffc:	3c14800b */ 	lui	$s4,0x800b
/*  f183000:	86c20002 */ 	lh	$v0,0x2($s6)
/*  f183004:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f183008:
/*  f183008:	0242082a */ 	slt	$at,$s2,$v0
/*  f18300c:	5420fffe */ 	bnezl	$at,.L0f183008
/*  f183010:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f183014:
/*  f183014:	3c017f1c */ 	lui	$at,%hi(var7f1b8954)
/*  f183018:	3c130001 */ 	lui	$s3,0x1
/*  f18301c:	3c120020 */ 	lui	$s2,0x20
/*  f183020:	3c110042 */ 	lui	$s1,0x42
/*  f183024:	36310001 */ 	ori	$s1,$s1,0x1
/*  f183028:	36524000 */ 	ori	$s2,$s2,0x4000
/*  f18302c:	36732000 */ 	ori	$s3,$s3,0x2000
/*  f183030:	c4348954 */ 	lwc1	$f20,%lo(var7f1b8954)($at)
/*  f183034:	2694c11c */ 	addiu	$s4,$s4,-16100
/*  f183038:	4406a000 */ 	mfc1	$a2,$f20
.L0f18303c:
/*  f18303c:	24040156 */ 	addiu	$a0,$zero,0x156
/*  f183040:	86050084 */ 	lh	$a1,0x84($s0)
/*  f183044:	02203825 */ 	or	$a3,$s1,$zero
/*  f183048:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f18304c:	0fc61942 */ 	jal	func0f186508
/*  f183050:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f183054:	ae020080 */ 	sw	$v0,0x80($s0)
/*  f183058:	0fc5fff9 */ 	jal	func0f17ffe4
/*  f18305c:	86040084 */ 	lh	$a0,0x84($s0)
/*  f183060:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f183064:	5614fff5 */ 	bnel	$s0,$s4,.L0f18303c
/*  f183068:	4406a000 */ 	mfc1	$a2,$f20
/*  f18306c:	3c018008 */ 	lui	$at,0x8008
/*  f183070:	0fc60b26 */ 	jal	func0f182c98
/*  f183074:	ac2069ec */ 	sw	$zero,0x69ec($at)
/*  f183078:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f18307c:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f183080:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f183084:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f183088:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f18308c:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f183090:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f183094:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f183098:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f18309c:	03e00008 */ 	jr	$ra
/*  f1830a0:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

void scenarioHtmCallback10(void)
{
	u8 stack[8];
	s32 i;
	u32 prevplayernum = g_Vars.currentplayernum;
	struct prop *prop;

	if (var800869ec && var800869ec->prop) {
		if (g_ScenarioData.htm.uplink == NULL || g_ScenarioData.htm.uplink->type != PROPTYPE_WEAPON) {
			var800869ec = 0;
		} else {
			var800869ec->prop->timetoregen = 1200;
		}
	}

	g_ScenarioData.htm.uplink = NULL;

	// Check if uplink is on the ground
	prop = g_Vars.unk00033c;

	while (prop) {
		if (prop->type == PROPTYPE_WEAPON) {
			struct weaponobj *weapon = prop->weapon;

			if (weapon->weapon_id == WEAPON_DATAUPLINK) {
				g_ScenarioData.htm.uplink = prop;
			}
		}

		prop = prop->next;
	}

	// Check if a player is holding it
	if (g_ScenarioData.htm.uplink == NULL) {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);

			if (func0f112884()) {
				g_ScenarioData.htm.uplink = g_Vars.currentplayer->prop;
				break;
			}
		}
	}

	setCurrentPlayerNum(prevplayernum);

	// Check if a simulant is holding it
	if (g_ScenarioData.htm.uplink == NULL) {
		for (i = PLAYERCOUNT(); i < g_MpNumPlayers; i++) {
			if (g_MpPlayerChrs[i]->unk2d4->unk04c_05) {
				g_ScenarioData.htm.uplink = g_MpPlayerChrs[i]->prop;
				break;
			}
		}
	}

	if (g_ScenarioData.htm.uplink == NULL) {
		func0f182c98();
	}
}

GLOBAL_ASM(
glabel scenarioHtmCallback14
/*  f183380:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f183384:	afb4005c */ 	sw	$s4,0x5c($sp)
/*  f183388:	0080a025 */ 	or	$s4,$a0,$zero
/*  f18338c:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f183390:	afb50060 */ 	sw	$s5,0x60($sp)
/*  f183394:	afb30058 */ 	sw	$s3,0x58($sp)
/*  f183398:	afb20054 */ 	sw	$s2,0x54($sp)
/*  f18339c:	afb10050 */ 	sw	$s1,0x50($sp)
/*  f1833a0:	afb0004c */ 	sw	$s0,0x4c($sp)
/*  f1833a4:	10800008 */ 	beqz	$a0,.L0f1833c8
/*  f1833a8:	f7b40040 */ 	sdc1	$f20,0x40($sp)
/*  f1833ac:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f1833b0:	8dd3004c */ 	lw	$s3,0x4c($t6)
/*  f1833b4:	00137940 */ 	sll	$t7,$s3,0x5
/*  f1833b8:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1833bc:	000f9fc2 */ 	srl	$s3,$t7,0x1f
/*  f1833c0:	1000000d */ 	beqz	$zero,.L0f1833f8
/*  f1833c4:	00409025 */ 	or	$s2,$v0,$zero
.L0f1833c8:
/*  f1833c8:	0fc44a21 */ 	jal	func0f112884
/*  f1833cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1833d0:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f1833d4:	10800005 */ 	beqz	$a0,.L0f1833ec
/*  f1833d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1833dc:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f1833e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1833e4:	38440036 */ 	xori	$a0,$v0,0x36
/*  f1833e8:	2c840001 */ 	sltiu	$a0,$a0,0x1
.L0f1833ec:
/*  f1833ec:	3c12800a */ 	lui	$s2,0x800a
/*  f1833f0:	00809825 */ 	or	$s3,$a0,$zero
/*  f1833f4:	8e52a24c */ 	lw	$s2,-0x5db4($s2)
.L0f1833f8:
/*  f1833f8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1833fc:	3c11800b */ 	lui	$s1,%hi(g_ScenarioData)
/*  f183400:	3c15800b */ 	lui	$s5,%hi(g_ScenarioData)
/*  f183404:	4481a000 */ 	mtc1	$at,$f20
/*  f183408:	26b5c110 */ 	addiu	$s5,$s5,%lo(g_ScenarioData)
/*  f18340c:	2631c110 */ 	addiu	$s1,$s1,%lo(g_ScenarioData)
/*  f183410:	00008025 */ 	or	$s0,$zero,$zero
.L0f183414:
/*  f183414:	8e240080 */ 	lw	$a0,0x80($s1)
/*  f183418:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f18341c:	50800061 */ 	beqzl	$a0,.L0f1835a4
/*  f183420:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183424:	12800005 */ 	beqz	$s4,.L0f18343c
/*  f183428:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f18342c:	1260000b */ 	beqz	$s3,.L0f18345c
/*  f183430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183434:	10000009 */ 	beqz	$zero,.L0f18345c
/*  f183438:	02402825 */ 	or	$a1,$s2,$zero
.L0f18343c:
/*  f18343c:	8c620040 */ 	lw	$v0,0x40($v1)
/*  f183440:	3c01f000 */ 	lui	$at,0xf000
/*  f183444:	30594000 */ 	andi	$t9,$v0,0x4000
/*  f183448:	13200004 */ 	beqz	$t9,.L0f18345c
/*  f18344c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183450:	00412824 */ 	and	$a1,$v0,$at
/*  f183454:	00054702 */ 	srl	$t0,$a1,0x1c
/*  f183458:	01002825 */ 	or	$a1,$t0,$zero
.L0f18345c:
/*  f18345c:	56450051 */ 	bnel	$s2,$a1,.L0f1835a4
/*  f183460:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183464:	8c690040 */ 	lw	$t1,0x40($v1)
/*  f183468:	2401bfff */ 	addiu	$at,$zero,-16385
/*  f18346c:	3c0d800b */ 	lui	$t5,0x800b
/*  f183470:	01215024 */ 	and	$t2,$t1,$at
/*  f183474:	3c010fff */ 	lui	$at,0xfff
/*  f183478:	3421ffff */ 	ori	$at,$at,0xffff
/*  f18347c:	ac6a0040 */ 	sw	$t2,0x40($v1)
/*  f183480:	01416024 */ 	and	$t4,$t2,$at
/*  f183484:	1260002e */ 	beqz	$s3,.L0f183540
/*  f183488:	ac6c0040 */ 	sw	$t4,0x40($v1)
/*  f18348c:	8dadc1e4 */ 	lw	$t5,-0x3e1c($t5)
/*  f183490:	2401ffff */ 	addiu	$at,$zero,-1
/*  f183494:	00127080 */ 	sll	$t6,$s2,0x2
/*  f183498:	15a10041 */ 	bne	$t5,$at,.L0f1835a0
/*  f18349c:	02ae7821 */ 	addu	$t7,$s5,$t6
/*  f1834a0:	3c01800b */ 	lui	$at,0x800b
/*  f1834a4:	ac30c1e4 */ 	sw	$s0,-0x3e1c($at)
/*  f1834a8:	a432c1e0 */ 	sh	$s2,-0x3e20($at)
/*  f1834ac:	a432c1e2 */ 	sh	$s2,-0x3e1e($at)
/*  f1834b0:	1680003b */ 	bnez	$s4,.L0f1835a0
/*  f1834b4:	ade00108 */ 	sw	$zero,0x108($t7)
/*  f1834b8:	0fc5b9f1 */ 	jal	textGet
/*  f1834bc:	24045412 */ 	addiu	$a0,$zero,0x5412
/*  f1834c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1834c4:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1834c8:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f1834cc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1834d0:	3c18800b */ 	lui	$t8,0x800b
/*  f1834d4:	8f18c1e4 */ 	lw	$t8,-0x3e1c($t8)
/*  f1834d8:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f1834dc:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f1834e0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1834e4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1834e8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1834ec:	02b94021 */ 	addu	$t0,$s5,$t9
/*  f1834f0:	8d050080 */ 	lw	$a1,0x80($t0)
/*  f1834f4:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f1834f8:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1834fc:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f183500:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f183504:	e7b40038 */ 	swc1	$f20,0x38($sp)
/*  f183508:	e7b40034 */ 	swc1	$f20,0x34($sp)
/*  f18350c:	e7b40030 */ 	swc1	$f20,0x30($sp)
/*  f183510:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f183514:	e7b40024 */ 	swc1	$f20,0x24($sp)
/*  f183518:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f18351c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f183520:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f183524:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f183528:	00002025 */ 	or	$a0,$zero,$zero
/*  f18352c:	240601bf */ 	addiu	$a2,$zero,0x1bf
/*  f183530:	0fc24e7e */ 	jal	func0f0939f8
/*  f183534:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f183538:	1000001a */ 	beqz	$zero,.L0f1835a4
/*  f18353c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f183540:
/*  f183540:	56800018 */ 	bnezl	$s4,.L0f1835a4
/*  f183544:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183548:	0fc5b9f1 */ 	jal	textGet
/*  f18354c:	24045413 */ 	addiu	$a0,$zero,0x5413
/*  f183550:	00402025 */ 	or	$a0,$v0,$zero
/*  f183554:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f183558:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f18355c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f183560:	3c013f80 */ 	lui	$at,0x3f80
/*  f183564:	44812000 */ 	mtc1	$at,$f4
/*  f183568:	240d01cc */ 	addiu	$t5,$zero,0x1cc
/*  f18356c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f183570:	240fffff */ 	addiu	$t7,$zero,-1
/*  f183574:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f183578:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f18357c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f183580:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f183584:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f183588:	00002025 */ 	or	$a0,$zero,$zero
/*  f18358c:	00002825 */ 	or	$a1,$zero,$zero
/*  f183590:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f183594:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f183598:	0c0041c6 */ 	jal	func00010718
/*  f18359c:	e7a40014 */ 	swc1	$f4,0x14($sp)
.L0f1835a0:
/*  f1835a0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1835a4:
/*  f1835a4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1835a8:	1601ff9a */ 	bne	$s0,$at,.L0f183414
/*  f1835ac:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f1835b0:	3c19800b */ 	lui	$t9,0x800b
/*  f1835b4:	8739c1e0 */ 	lh	$t9,-0x3e20($t9)
/*  f1835b8:	3c08800b */ 	lui	$t0,0x800b
/*  f1835bc:	565900f1 */ 	bnel	$s2,$t9,.L0f183984
/*  f1835c0:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f1835c4:	8d08c1e4 */ 	lw	$t0,-0x3e1c($t0)
/*  f1835c8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1835cc:	00125880 */ 	sll	$t3,$s2,0x2
/*  f1835d0:	110100eb */ 	beq	$t0,$at,.L0f183980
/*  f1835d4:	00084880 */ 	sll	$t1,$t0,0x2
/*  f1835d8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1835dc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1835e0:	02a95021 */ 	addu	$t2,$s5,$t1
/*  f1835e4:	8d510080 */ 	lw	$s1,0x80($t2)
/*  f1835e8:	02ab9821 */ 	addu	$s3,$s5,$t3
/*  f1835ec:	266c0108 */ 	addiu	$t4,$s3,0x108
/*  f1835f0:	afac006c */ 	sw	$t4,0x6c($sp)
/*  f1835f4:	12800011 */ 	beqz	$s4,.L0f18363c
/*  f1835f8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1835fc:	8e90001c */ 	lw	$s0,0x1c($s4)
/*  f183600:	02802025 */ 	or	$a0,$s4,$zero
/*  f183604:	0fc0f917 */ 	jal	func0f03e45c
/*  f183608:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f18360c:	3c017f1c */ 	lui	$at,%hi(var7f1b8958)
/*  f183610:	c4268958 */ 	lwc1	$f6,%lo(var7f1b8958)($at)
/*  f183614:	3c017f1c */ 	lui	$at,%hi(var7f1b895c)
/*  f183618:	c42a895c */ 	lwc1	$f10,%lo(var7f1b895c)($at)
/*  f18361c:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f183620:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f183624:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f183628:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f18362c:	8da30020 */ 	lw	$v1,0x20($t5)
/*  f183630:	386e0001 */ 	xori	$t6,$v1,0x1
/*  f183634:	1000000b */ 	beqz	$zero,.L0f183664
/*  f183638:	2dc30001 */ 	sltiu	$v1,$t6,0x1
.L0f18363c:
/*  f18363c:	3c02800a */ 	lui	$v0,0x800a
/*  f183640:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f183644:	00002025 */ 	or	$a0,$zero,$zero
/*  f183648:	8c5000bc */ 	lw	$s0,0xbc($v0)
/*  f18364c:	c4460144 */ 	lwc1	$f6,0x144($v0)
/*  f183650:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f183654:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f183658:	e7a60098 */ 	swc1	$f6,0x98($sp)
/*  f18365c:	38430036 */ 	xori	$v1,$v0,0x36
/*  f183660:	2c630001 */ 	sltiu	$v1,$v1,0x1
.L0f183664:
/*  f183664:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*  f183668:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f18366c:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*  f183670:	c6060004 */ 	lwc1	$f6,0x4($s0)
/*  f183674:	460a4501 */ 	sub.s	$f20,$f8,$f10
/*  f183678:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f18367c:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f183680:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f183684:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f183688:	afa30078 */ 	sw	$v1,0x78($sp)
/*  f18368c:	460a4381 */ 	sub.s	$f14,$f8,$f10
/*  f183690:	e7a20080 */ 	swc1	$f2,0x80($sp)
/*  f183694:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f183698:	e7ae0084 */ 	swc1	$f14,0x84($sp)
/*  f18369c:	0c012974 */ 	jal	sqrtf
/*  f1836a0:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f1836a4:	c7a20080 */ 	lwc1	$f2,0x80($sp)
/*  f1836a8:	44804000 */ 	mtc1	$zero,$f8
/*  f1836ac:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f1836b0:	c7ae0084 */ 	lwc1	$f14,0x84($sp)
/*  f1836b4:	4602403c */ 	c.lt.s	$f8,$f2
/*  f1836b8:	46000486 */ 	mov.s	$f18,$f0
/*  f1836bc:	4600a306 */ 	mov.s	$f12,$f20
/*  f1836c0:	45020004 */ 	bc1fl	.L0f1836d4
/*  f1836c4:	46001407 */ 	neg.s	$f16,$f2
/*  f1836c8:	10000002 */ 	beqz	$zero,.L0f1836d4
/*  f1836cc:	46001406 */ 	mov.s	$f16,$f2
/*  f1836d0:	46001407 */ 	neg.s	$f16,$f2
.L0f1836d4:
/*  f1836d4:	afa30078 */ 	sw	$v1,0x78($sp)
/*  f1836d8:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*  f1836dc:	0fc259d4 */ 	jal	func0f096750
/*  f1836e0:	e7b20090 */ 	swc1	$f18,0x90($sp)
/*  f1836e4:	3c014334 */ 	lui	$at,0x4334
/*  f1836e8:	44816000 */ 	mtc1	$at,$f12
/*  f1836ec:	3c017f1c */ 	lui	$at,%hi(var7f1b8960)
/*  f1836f0:	c42a8960 */ 	lwc1	$f10,%lo(var7f1b8960)($at)
/*  f1836f4:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f1836f8:	44804000 */ 	mtc1	$zero,$f8
/*  f1836fc:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f183700:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f183704:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*  f183708:	c7b20090 */ 	lwc1	$f18,0x90($sp)
/*  f18370c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f183710:	46062080 */ 	add.s	$f2,$f4,$f6
/*  f183714:	460c103c */ 	c.lt.s	$f2,$f12
/*  f183718:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18371c:	45020009 */ 	bc1fl	.L0f183744
/*  f183720:	4602603c */ 	c.lt.s	$f12,$f2
/*  f183724:	44810000 */ 	mtc1	$at,$f0
/*  f183728:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18372c:	46001080 */ 	add.s	$f2,$f2,$f0
.L0f183730:
/*  f183730:	460c103c */ 	c.lt.s	$f2,$f12
/*  f183734:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183738:	4503fffd */ 	bc1tl	.L0f183730
/*  f18373c:	46001080 */ 	add.s	$f2,$f2,$f0
/*  f183740:	4602603c */ 	c.lt.s	$f12,$f2
.L0f183744:
/*  f183744:	3c0143b4 */ 	lui	$at,0x43b4
/*  f183748:	44810000 */ 	mtc1	$at,$f0
/*  f18374c:	3c01437a */ 	lui	$at,0x437a
/*  f183750:	45020007 */ 	bc1fl	.L0f183770
/*  f183754:	4602403c */ 	c.lt.s	$f8,$f2
/*  f183758:	46001081 */ 	sub.s	$f2,$f2,$f0
.L0f18375c:
/*  f18375c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f183760:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183764:	4503fffd */ 	bc1tl	.L0f18375c
/*  f183768:	46001081 */ 	sub.s	$f2,$f2,$f0
/*  f18376c:	4602403c */ 	c.lt.s	$f8,$f2
.L0f183770:
/*  f183770:	44810000 */ 	mtc1	$at,$f0
/*  f183774:	3c014348 */ 	lui	$at,0x4348
/*  f183778:	45030003 */ 	bc1tl	.L0f183788
/*  f18377c:	4612003c */ 	c.lt.s	$f0,$f18
/*  f183780:	46001087 */ 	neg.s	$f2,$f2
/*  f183784:	4612003c */ 	c.lt.s	$f0,$f18
.L0f183788:
/*  f183788:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18378c:	45030010 */ 	bc1tl	.L0f1837d0
/*  f183790:	4600903c */ 	c.lt.s	$f18,$f0
/*  f183794:	44815000 */ 	mtc1	$at,$f10
/*  f183798:	3c014234 */ 	lui	$at,0x4234
/*  f18379c:	4610503c */ 	c.lt.s	$f10,$f16
/*  f1837a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1837a4:	4503000a */ 	bc1tl	.L0f1837d0
/*  f1837a8:	4600903c */ 	c.lt.s	$f18,$f0
/*  f1837ac:	44812000 */ 	mtc1	$at,$f4
/*  f1837b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1837b4:	4602203c */ 	c.lt.s	$f4,$f2
/*  f1837b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1837bc:	45030004 */ 	bc1tl	.L0f1837d0
/*  f1837c0:	4600903c */ 	c.lt.s	$f18,$f0
/*  f1837c4:	1460003a */ 	bnez	$v1,.L0f1838b0
/*  f1837c8:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*  f1837cc:	4600903c */ 	c.lt.s	$f18,$f0
.L0f1837d0:
/*  f1837d0:	3c014348 */ 	lui	$at,0x4348
/*  f1837d4:	240fffff */ 	addiu	$t7,$zero,-1
/*  f1837d8:	45000009 */ 	bc1f	.L0f183800
/*  f1837dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1837e0:	44813000 */ 	mtc1	$at,$f6
/*  f1837e4:	3c01800b */ 	lui	$at,0x800b
/*  f1837e8:	4606803c */ 	c.lt.s	$f16,$f6
/*  f1837ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1837f0:	45000003 */ 	bc1f	.L0f183800
/*  f1837f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1837f8:	10000003 */ 	beqz	$zero,.L0f183808
/*  f1837fc:	a432c1e2 */ 	sh	$s2,-0x3e1e($at)
.L0f183800:
/*  f183800:	3c01800b */ 	lui	$at,0x800b
/*  f183804:	a42fc1e2 */ 	sh	$t7,-0x3e1e($at)
.L0f183808:
/*  f183808:	16800021 */ 	bnez	$s4,.L0f183890
/*  f18380c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183810:	0fc5b9f1 */ 	jal	textGet
/*  f183814:	24045411 */ 	addiu	$a0,$zero,0x5411
/*  f183818:	00402025 */ 	or	$a0,$v0,$zero
/*  f18381c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f183820:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f183824:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f183828:	3c18800b */ 	lui	$t8,0x800b
/*  f18382c:	8f18c1e4 */ 	lw	$t8,-0x3e1c($t8)
/*  f183830:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f183834:	3406ffff */ 	dli	$a2,0xffff
/*  f183838:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f18383c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f183840:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f183844:	02b94021 */ 	addu	$t0,$s5,$t9
/*  f183848:	0fc249af */ 	jal	func0f0926bc
/*  f18384c:	8d040080 */ 	lw	$a0,0x80($t0)
/*  f183850:	3c013f80 */ 	lui	$at,0x3f80
/*  f183854:	44814000 */ 	mtc1	$at,$f8
/*  f183858:	240901cc */ 	addiu	$t1,$zero,0x1cc
/*  f18385c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f183860:	240bffff */ 	addiu	$t3,$zero,-1
/*  f183864:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f183868:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f18386c:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f183870:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f183874:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f183878:	00002025 */ 	or	$a0,$zero,$zero
/*  f18387c:	00002825 */ 	or	$a1,$zero,$zero
/*  f183880:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f183884:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f183888:	0c0041c6 */ 	jal	func00010718
/*  f18388c:	e7a80014 */ 	swc1	$f8,0x14($sp)
.L0f183890:
/*  f183890:	3c01800b */ 	lui	$at,0x800b
/*  f183894:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f183898:	240dffff */ 	addiu	$t5,$zero,-1
/*  f18389c:	240effff */ 	addiu	$t6,$zero,-1
/*  f1838a0:	ac2dc1e4 */ 	sw	$t5,-0x3e1c($at)
/*  f1838a4:	a42ec1e0 */ 	sh	$t6,-0x3e20($at)
/*  f1838a8:	10000035 */ 	beqz	$zero,.L0f183980
/*  f1838ac:	ade00000 */ 	sw	$zero,0x0($t7)
.L0f1838b0:
/*  f1838b0:	3c19800a */ 	lui	$t9,0x800a
/*  f1838b4:	8f399ff4 */ 	lw	$t9,-0x600c($t9)
/*  f1838b8:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f1838bc:	03194021 */ 	addu	$t0,$t8,$t9
/*  f1838c0:	290112c1 */ 	slti	$at,$t0,0x12c1
/*  f1838c4:	1420002e */ 	bnez	$at,.L0f183980
/*  f1838c8:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f1838cc:	8e6a00d8 */ 	lw	$t2,0xd8($s3)
/*  f1838d0:	3c01800b */ 	lui	$at,0x800b
/*  f1838d4:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f1838d8:	ae6b00d8 */ 	sw	$t3,0xd8($s3)
/*  f1838dc:	16800022 */ 	bnez	$s4,.L0f183968
/*  f1838e0:	a432c1e2 */ 	sh	$s2,-0x3e1e($at)
/*  f1838e4:	0fc5b9f1 */ 	jal	textGet
/*  f1838e8:	24045410 */ 	addiu	$a0,$zero,0x5410
/*  f1838ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f1838f0:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1838f4:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f1838f8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1838fc:	3c0c800b */ 	lui	$t4,0x800b
/*  f183900:	8d8cc1e4 */ 	lw	$t4,-0x3e1c($t4)
/*  f183904:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f183908:	3406ffff */ 	dli	$a2,0xffff
/*  f18390c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f183910:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f183914:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f183918:	02ad7021 */ 	addu	$t6,$s5,$t5
/*  f18391c:	0fc249af */ 	jal	func0f0926bc
/*  f183920:	8dc40080 */ 	lw	$a0,0x80($t6)
/*  f183924:	3c013f80 */ 	lui	$at,0x3f80
/*  f183928:	44815000 */ 	mtc1	$at,$f10
/*  f18392c:	240f01c1 */ 	addiu	$t7,$zero,0x1c1
/*  f183930:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f183934:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f183938:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f18393c:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f183940:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f183944:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f183948:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f18394c:	00002025 */ 	or	$a0,$zero,$zero
/*  f183950:	00002825 */ 	or	$a1,$zero,$zero
/*  f183954:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f183958:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f18395c:	0c0041c6 */ 	jal	func00010718
/*  f183960:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f183964:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f183968:
/*  f183968:	3c01800b */ 	lui	$at,0x800b
/*  f18396c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f183970:	240affff */ 	addiu	$t2,$zero,-1
/*  f183974:	ac29c1e4 */ 	sw	$t1,-0x3e1c($at)
/*  f183978:	a42ac1e0 */ 	sh	$t2,-0x3e20($at)
/*  f18397c:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f183980:
/*  f183980:	8fbf0064 */ 	lw	$ra,0x64($sp)
.L0f183984:
/*  f183984:	d7b40040 */ 	ldc1	$f20,0x40($sp)
/*  f183988:	8fb0004c */ 	lw	$s0,0x4c($sp)
/*  f18398c:	8fb10050 */ 	lw	$s1,0x50($sp)
/*  f183990:	8fb20054 */ 	lw	$s2,0x54($sp)
/*  f183994:	8fb30058 */ 	lw	$s3,0x58($sp)
/*  f183998:	8fb4005c */ 	lw	$s4,0x5c($sp)
/*  f18399c:	8fb50060 */ 	lw	$s5,0x60($sp)
/*  f1839a0:	03e00008 */ 	jr	$ra
/*  f1839a4:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);

GLOBAL_ASM(
glabel scenarioHtmCallback18
/*  f1839a8:	3c02800a */ 	lui	$v0,0x800a
/*  f1839ac:	8c42a24c */ 	lw	$v0,-0x5db4($v0)
/*  f1839b0:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f1839b4:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f1839b8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f1839bc:	8c7900d4 */ 	lw	$t9,0xd4($v1)
/*  f1839c0:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f1839c4:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f1839c8:	8df80108 */ 	lw	$t8,0x108($t7)
/*  f1839cc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1839d0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1839d4:	00808025 */ 	or	$s0,$a0,$zero
/*  f1839d8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1839dc:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1839e0:	1321006e */ 	beq	$t9,$at,.L0f183b9c
/*  f1839e4:	afb80060 */ 	sw	$t8,0x60($sp)
/*  f1839e8:	3c09800b */ 	lui	$t1,0x800b
/*  f1839ec:	8529c1e0 */ 	lh	$t1,-0x3e20($t1)
/*  f1839f0:	5449006b */ 	bnel	$v0,$t1,.L0f183ba0
/*  f1839f4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1839f8:	0c002f40 */ 	jal	func0000bd00
/*  f1839fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183a00:	0c002f40 */ 	jal	func0000bd00
/*  f183a04:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f183a08:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f183a0c:	00115403 */ 	sra	$t2,$s1,0x10
/*  f183a10:	0c002f22 */ 	jal	func0000bc88
/*  f183a14:	01408825 */ 	or	$s1,$t2,$zero
/*  f183a18:	00515821 */ 	addu	$t3,$v0,$s1
/*  f183a1c:	0c002f44 */ 	jal	func0000bd10
/*  f183a20:	afab0058 */ 	sw	$t3,0x58($sp)
/*  f183a24:	0c002f22 */ 	jal	func0000bc88
/*  f183a28:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f183a2c:	8fac005c */ 	lw	$t4,0x5c($sp)
/*  f183a30:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f183a34:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f183a38:	02002025 */ 	or	$a0,$s0,$zero
/*  f183a3c:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f183a40:	04610003 */ 	bgez	$v1,.L0f183a50
/*  f183a44:	00037043 */ 	sra	$t6,$v1,0x1
/*  f183a48:	24610001 */ 	addiu	$at,$v1,0x1
/*  f183a4c:	00017043 */ 	sra	$t6,$at,0x1
.L0f183a50:
/*  f183a50:	24010003 */ 	addiu	$at,$zero,0x3
/*  f183a54:	0041001a */ 	div	$zero,$v0,$at
/*  f183a58:	44982000 */ 	mtc1	$t8,$f4
/*  f183a5c:	00002812 */ 	mflo	$a1
/*  f183a60:	44858000 */ 	mtc1	$a1,$f16
/*  f183a64:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f183a68:	01c01825 */ 	or	$v1,$t6,$zero
/*  f183a6c:	04a10003 */ 	bgez	$a1,.L0f183a7c
/*  f183a70:	00053043 */ 	sra	$a2,$a1,0x1
/*  f183a74:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f183a78:	00013043 */ 	sra	$a2,$at,0x1
.L0f183a7c:
/*  f183a7c:	3c014596 */ 	lui	$at,0x4596
/*  f183a80:	44814000 */ 	mtc1	$at,$f8
/*  f183a84:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f183a88:	00663823 */ 	subu	$a3,$v1,$a2
/*  f183a8c:	00c37821 */ 	addu	$t7,$a2,$v1
/*  f183a90:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f183a94:	afaf0044 */ 	sw	$t7,0x44($sp)
/*  f183a98:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f183a9c:	460a9102 */ 	mul.s	$f4,$f18,$f10
/*  f183aa0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f183aa4:	44093000 */ 	mfc1	$t1,$f6
/*  f183aa8:	0fc54d8a */ 	jal	func0f153628
/*  f183aac:	01278821 */ 	addu	$s1,$t1,$a3
/*  f183ab0:	3c056000 */ 	lui	$a1,0x6000
/*  f183ab4:	34a50060 */ 	ori	$a1,$a1,0x60
/*  f183ab8:	0fc54df7 */ 	jal	func0f1537dc
/*  f183abc:	00402025 */ 	or	$a0,$v0,$zero
/*  f183ac0:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f183ac4:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f183ac8:	3c08f600 */ 	lui	$t0,0xf600
/*  f183acc:	24660010 */ 	addiu	$a2,$v1,0x10
/*  f183ad0:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f183ad4:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f183ad8:	30ca03ff */ 	andi	$t2,$a2,0x3ff
/*  f183adc:	000a3080 */ 	sll	$a2,$t2,0x2
/*  f183ae0:	01c87825 */ 	or	$t7,$t6,$t0
/*  f183ae4:	01e6c025 */ 	or	$t8,$t7,$a2
/*  f183ae8:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f183aec:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f183af0:	24670008 */ 	addiu	$a3,$v1,0x8
/*  f183af4:	30f903ff */ 	andi	$t9,$a3,0x3ff
/*  f183af8:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f183afc:	000b6380 */ 	sll	$t4,$t3,0xe
/*  f183b00:	00194880 */ 	sll	$t1,$t9,0x2
/*  f183b04:	01896825 */ 	or	$t5,$t4,$t1
/*  f183b08:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f183b0c:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f183b10:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f183b14:	0fc54e0e */ 	jal	func0f153838
/*  f183b18:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f183b1c:	3c05c000 */ 	lui	$a1,0xc000
/*  f183b20:	34a500d0 */ 	ori	$a1,$a1,0xd0
/*  f183b24:	0fc54df7 */ 	jal	func0f1537dc
/*  f183b28:	00402025 */ 	or	$a0,$v0,$zero
/*  f183b2c:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f183b30:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f183b34:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f183b38:	24830001 */ 	addiu	$v1,$a0,0x1
/*  f183b3c:	0071082a */ 	slt	$at,$v1,$s1
/*  f183b40:	3c08f600 */ 	lui	$t0,0xf600
/*  f183b44:	10200010 */ 	beqz	$at,.L0f183b88
/*  f183b48:	00408025 */ 	or	$s0,$v0,$zero
.L0f183b4c:
/*  f183b4c:	306f03ff */ 	andi	$t7,$v1,0x3ff
/*  f183b50:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f183b54:	308a03ff */ 	andi	$t2,$a0,0x3ff
/*  f183b58:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f183b5c:	0308c825 */ 	or	$t9,$t8,$t0
/*  f183b60:	02001025 */ 	or	$v0,$s0,$zero
/*  f183b64:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f183b68:	03264825 */ 	or	$t1,$t9,$a2
/*  f183b6c:	01676025 */ 	or	$t4,$t3,$a3
/*  f183b70:	0071082a */ 	slt	$at,$v1,$s1
/*  f183b74:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f183b78:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f183b7c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f183b80:	1420fff2 */ 	bnez	$at,.L0f183b4c
/*  f183b84:	24840002 */ 	addiu	$a0,$a0,0x2
.L0f183b88:
/*  f183b88:	0fc54e0e */ 	jal	func0f153838
/*  f183b8c:	02002025 */ 	or	$a0,$s0,$zero
/*  f183b90:	0fc54de0 */ 	jal	func0f153780
/*  f183b94:	00402025 */ 	or	$a0,$v0,$zero
/*  f183b98:	00408025 */ 	or	$s0,$v0,$zero
.L0f183b9c:
/*  f183b9c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f183ba0:
/*  f183ba0:	02001025 */ 	or	$v0,$s0,$zero
/*  f183ba4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f183ba8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f183bac:	03e00008 */ 	jr	$ra
/*  f183bb0:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

void scenarioHtmKill(struct mpchr *mpchr, s32 arg1, s32 *score, s32 *arg3)
{
	struct mpchr *loopmpchr;
	s32 i;
	s32 index;

	*score = 0;
	index = func0f18d0e8(arg1);

	if (index >= 0) {
		*score += g_ScenarioData.htm.unk0d8[index] * 2;
	}

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == arg1) {
				*score -= mpchr->unk24[i];
			} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				if (i < 4) {
					loopmpchr = &g_MpPlayers[i].base;
				} else {
					loopmpchr = &g_MpSimulants[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->unk24[i];
				} else {
					*score += mpchr->unk24[i];
				}
			} else {
				*score += mpchr->unk24[i];
			}
		}
	}

	*arg3 = mpchr->unk3c;
}

GLOBAL_ASM(
glabel scenarioHtmRadar
/*  f183d10:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f183d14:	afb70048 */ 	sw	$s7,0x48($sp)
/*  f183d18:	3c17800b */ 	lui	$s7,%hi(g_MpSetup)
/*  f183d1c:	26f7cb88 */ 	addiu	$s7,$s7,%lo(g_MpSetup)
/*  f183d20:	8eee000c */ 	lw	$t6,0xc($s7)
/*  f183d24:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f183d28:	00808825 */ 	or	$s1,$a0,$zero
/*  f183d2c:	000e7b40 */ 	sll	$t7,$t6,0xd
/*  f183d30:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f183d34:	afb60044 */ 	sw	$s6,0x44($sp)
/*  f183d38:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f183d3c:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f183d40:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f183d44:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f183d48:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f183d4c:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f183d50:	05e10123 */ 	bgez	$t7,.L0f1841e0
/*  f183d54:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f183d58:	3c18800b */ 	lui	$t8,0x800b
/*  f183d5c:	8f18c24c */ 	lw	$t8,-0x3db4($t8)
/*  f183d60:	53000021 */ 	beqzl	$t8,.L0f183de8
/*  f183d64:	3c01437f */ 	lui	$at,0x437f
/*  f183d68:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f183d6c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f183d70:	1041001c */ 	beq	$v0,$at,.L0f183de4
/*  f183d74:	24010003 */ 	addiu	$at,$zero,0x3
/*  f183d78:	1041001a */ 	beq	$v0,$at,.L0f183de4
/*  f183d7c:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f183d80:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f183d84:	8ec20284 */ 	lw	$v0,0x284($s6)
/*  f183d88:	c7040008 */ 	lwc1	$f4,0x8($t8)
/*  f183d8c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f183d90:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f183d94:	03002825 */ 	or	$a1,$t8,$zero
/*  f183d98:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f183d9c:	c7260008 */ 	lwc1	$f6,0x8($t9)
/*  f183da0:	3c0700ff */ 	lui	$a3,0xff
/*  f183da4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f183da8:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f183dac:	8c4c00bc */ 	lw	$t4,0xbc($v0)
/*  f183db0:	c70a000c */ 	lwc1	$f10,0xc($t8)
/*  f183db4:	c590000c */ 	lwc1	$f16,0xc($t4)
/*  f183db8:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f183dbc:	e7b2009c */ 	swc1	$f18,0x9c($sp)
/*  f183dc0:	8c4d00bc */ 	lw	$t5,0xbc($v0)
/*  f183dc4:	c7040010 */ 	lwc1	$f4,0x10($t8)
/*  f183dc8:	c5a60010 */ 	lwc1	$f6,0x10($t5)
/*  f183dcc:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f183dd0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f183dd4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f183dd8:	0fc63a7b */ 	jal	func0f18e9ec
/*  f183ddc:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*  f183de0:	00408825 */ 	or	$s1,$v0,$zero
.L0f183de4:
/*  f183de4:	3c01437f */ 	lui	$at,0x437f
.L0f183de8:
/*  f183de8:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f183dec:	3c10800b */ 	lui	$s0,%hi(g_ScenarioData)
/*  f183df0:	3c158008 */ 	lui	$s5,%hi(g_TeamColours)
/*  f183df4:	3c14800b */ 	lui	$s4,0x800b
/*  f183df8:	4481b000 */ 	mtc1	$at,$f22
/*  f183dfc:	4480a000 */ 	mtc1	$zero,$f20
/*  f183e00:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f183e04:	2694c11c */ 	addiu	$s4,$s4,-16100
/*  f183e08:	26b57cc4 */ 	addiu	$s5,$s5,%lo(g_TeamColours)
/*  f183e0c:	2610c110 */ 	addiu	$s0,$s0,%lo(g_ScenarioData)
/*  f183e10:	27b30088 */ 	addiu	$s3,$sp,0x88
/*  f183e14:	241200ff */ 	addiu	$s2,$zero,0xff
/*  f183e18:	8e030080 */ 	lw	$v1,0x80($s0)
.L0f183e1c:
/*  f183e1c:	506000ee */ 	beqzl	$v1,.L0f1841d8
/*  f183e20:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f183e24:	8ec20284 */ 	lw	$v0,0x284($s6)
/*  f183e28:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f183e2c:	8e190080 */ 	lw	$t9,0x80($s0)
/*  f183e30:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f183e34:	8e0d0080 */ 	lw	$t5,0x80($s0)
/*  f183e38:	92040086 */ 	lbu	$a0,0x86($s0)
/*  f183e3c:	c5f00008 */ 	lwc1	$f16,0x8($t7)
/*  f183e40:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f183e44:	e7b20088 */ 	swc1	$f18,0x88($sp)
/*  f183e48:	8c4c00bc */ 	lw	$t4,0xbc($v0)
/*  f183e4c:	c724000c */ 	lwc1	$f4,0xc($t9)
/*  f183e50:	c586000c */ 	lwc1	$f6,0xc($t4)
/*  f183e54:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f183e58:	e7a8008c */ 	swc1	$f8,0x8c($sp)
/*  f183e5c:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f183e60:	c5aa0010 */ 	lwc1	$f10,0x10($t5)
/*  f183e64:	c7100010 */ 	lwc1	$f16,0x10($t8)
/*  f183e68:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f183e6c:	16440006 */ 	bne	$s2,$a0,.L0f183e88
/*  f183e70:	e7b20090 */ 	swc1	$f18,0x90($sp)
/*  f183e74:	4600a006 */ 	mov.s	$f0,$f20
/*  f183e78:	4600b086 */ 	mov.s	$f2,$f22
/*  f183e7c:	4600a306 */ 	mov.s	$f12,$f20
/*  f183e80:	10000033 */ 	beqz	$zero,.L0f183f50
/*  f183e84:	4600a386 */ 	mov.s	$f14,$f20
.L0f183e88:
/*  f183e88:	8eee000c */ 	lw	$t6,0xc($s7)
/*  f183e8c:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f183e90:	51e0002c */ 	beqzl	$t7,.L0f183f44
/*  f183e94:	4600a006 */ 	mov.s	$f0,$f20
/*  f183e98:	0fc63a5a */ 	jal	teamGetIndex
/*  f183e9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183ea0:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f183ea4:	02b96021 */ 	addu	$t4,$s5,$t9
/*  f183ea8:	8d830000 */ 	lw	$v1,0x0($t4)
/*  f183eac:	3c014f80 */ 	lui	$at,0x4f80
/*  f183eb0:	00036e02 */ 	srl	$t5,$v1,0x18
/*  f183eb4:	31b800ff */ 	andi	$t8,$t5,0xff
/*  f183eb8:	44982000 */ 	mtc1	$t8,$f4
/*  f183ebc:	00037402 */ 	srl	$t6,$v1,0x10
/*  f183ec0:	07010004 */ 	bgez	$t8,.L0f183ed4
/*  f183ec4:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f183ec8:	44813000 */ 	mtc1	$at,$f6
/*  f183ecc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183ed0:	46060000 */ 	add.s	$f0,$f0,$f6
.L0f183ed4:
/*  f183ed4:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f183ed8:	448f4000 */ 	mtc1	$t7,$f8
/*  f183edc:	0003ca02 */ 	srl	$t9,$v1,0x8
/*  f183ee0:	05e10005 */ 	bgez	$t7,.L0f183ef8
/*  f183ee4:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f183ee8:	3c014f80 */ 	lui	$at,0x4f80
/*  f183eec:	44815000 */ 	mtc1	$at,$f10
/*  f183ef0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183ef4:	460a1080 */ 	add.s	$f2,$f2,$f10
.L0f183ef8:
/*  f183ef8:	332c00ff */ 	andi	$t4,$t9,0xff
/*  f183efc:	448c8000 */ 	mtc1	$t4,$f16
/*  f183f00:	306d00ff */ 	andi	$t5,$v1,0xff
/*  f183f04:	05810005 */ 	bgez	$t4,.L0f183f1c
/*  f183f08:	46808320 */ 	cvt.s.w	$f12,$f16
/*  f183f0c:	3c014f80 */ 	lui	$at,0x4f80
/*  f183f10:	44819000 */ 	mtc1	$at,$f18
/*  f183f14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183f18:	46126300 */ 	add.s	$f12,$f12,$f18
.L0f183f1c:
/*  f183f1c:	448d2000 */ 	mtc1	$t5,$f4
/*  f183f20:	3c014f80 */ 	lui	$at,0x4f80
/*  f183f24:	05a1000a */ 	bgez	$t5,.L0f183f50
/*  f183f28:	468023a0 */ 	cvt.s.w	$f14,$f4
/*  f183f2c:	44813000 */ 	mtc1	$at,$f6
/*  f183f30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183f34:	46067380 */ 	add.s	$f14,$f14,$f6
/*  f183f38:	10000006 */ 	beqz	$zero,.L0f183f54
/*  f183f3c:	4458f800 */ 	cfc1	$t8,$31
/*  f183f40:	4600a006 */ 	mov.s	$f0,$f20
.L0f183f44:
/*  f183f44:	4600b086 */ 	mov.s	$f2,$f22
/*  f183f48:	4600a306 */ 	mov.s	$f12,$f20
/*  f183f4c:	4600a386 */ 	mov.s	$f14,$f20
.L0f183f50:
/*  f183f50:	4458f800 */ 	cfc1	$t8,$31
.L0f183f54:
/*  f183f54:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f183f58:	44c2f800 */ 	ctc1	$v0,$31
/*  f183f5c:	3c014f00 */ 	lui	$at,0x4f00
/*  f183f60:	02603025 */ 	or	$a2,$s3,$zero
/*  f183f64:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f183f68:	4442f800 */ 	cfc1	$v0,$31
/*  f183f6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183f70:	30420078 */ 	andi	$v0,$v0,0x78
/*  f183f74:	50400013 */ 	beqzl	$v0,.L0f183fc4
/*  f183f78:	44024000 */ 	mfc1	$v0,$f8
/*  f183f7c:	44814000 */ 	mtc1	$at,$f8
/*  f183f80:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f183f84:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f183f88:	44c2f800 */ 	ctc1	$v0,$31
/*  f183f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183f90:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f183f94:	4442f800 */ 	cfc1	$v0,$31
/*  f183f98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183f9c:	30420078 */ 	andi	$v0,$v0,0x78
/*  f183fa0:	14400005 */ 	bnez	$v0,.L0f183fb8
/*  f183fa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183fa8:	44024000 */ 	mfc1	$v0,$f8
/*  f183fac:	3c018000 */ 	lui	$at,0x8000
/*  f183fb0:	10000007 */ 	beqz	$zero,.L0f183fd0
/*  f183fb4:	00411025 */ 	or	$v0,$v0,$at
.L0f183fb8:
/*  f183fb8:	10000005 */ 	beqz	$zero,.L0f183fd0
/*  f183fbc:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f183fc0:	44024000 */ 	mfc1	$v0,$f8
.L0f183fc4:
/*  f183fc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183fc8:	0440fffb */ 	bltz	$v0,.L0f183fb8
/*  f183fcc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f183fd0:
/*  f183fd0:	44d8f800 */ 	ctc1	$t8,$31
/*  f183fd4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f183fd8:	00404025 */ 	or	$t0,$v0,$zero
/*  f183fdc:	3c014f00 */ 	lui	$at,0x4f00
/*  f183fe0:	444ef800 */ 	cfc1	$t6,$31
/*  f183fe4:	44c3f800 */ 	ctc1	$v1,$31
/*  f183fe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183fec:	460012a4 */ 	cvt.w.s	$f10,$f2
/*  f183ff0:	4443f800 */ 	cfc1	$v1,$31
/*  f183ff4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183ff8:	30630078 */ 	andi	$v1,$v1,0x78
/*  f183ffc:	50600013 */ 	beqzl	$v1,.L0f18404c
/*  f184000:	44035000 */ 	mfc1	$v1,$f10
/*  f184004:	44815000 */ 	mtc1	$at,$f10
/*  f184008:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f18400c:	460a1281 */ 	sub.s	$f10,$f2,$f10
/*  f184010:	44c3f800 */ 	ctc1	$v1,$31
/*  f184014:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184018:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f18401c:	4443f800 */ 	cfc1	$v1,$31
/*  f184020:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184024:	30630078 */ 	andi	$v1,$v1,0x78
/*  f184028:	14600005 */ 	bnez	$v1,.L0f184040
/*  f18402c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184030:	44035000 */ 	mfc1	$v1,$f10
/*  f184034:	3c018000 */ 	lui	$at,0x8000
/*  f184038:	10000007 */ 	beqz	$zero,.L0f184058
/*  f18403c:	00611825 */ 	or	$v1,$v1,$at
.L0f184040:
/*  f184040:	10000005 */ 	beqz	$zero,.L0f184058
/*  f184044:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f184048:	44035000 */ 	mfc1	$v1,$f10
.L0f18404c:
/*  f18404c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184050:	0460fffb */ 	bltz	$v1,.L0f184040
/*  f184054:	00000000 */ 	sll	$zero,$zero,0x0
.L0f184058:
/*  f184058:	44cef800 */ 	ctc1	$t6,$31
/*  f18405c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f184060:	00604825 */ 	or	$t1,$v1,$zero
/*  f184064:	3c014f00 */ 	lui	$at,0x4f00
/*  f184068:	444ff800 */ 	cfc1	$t7,$31
/*  f18406c:	44c4f800 */ 	ctc1	$a0,$31
/*  f184070:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184074:	46006424 */ 	cvt.w.s	$f16,$f12
/*  f184078:	4444f800 */ 	cfc1	$a0,$31
/*  f18407c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184080:	30840078 */ 	andi	$a0,$a0,0x78
/*  f184084:	50800013 */ 	beqzl	$a0,.L0f1840d4
/*  f184088:	44048000 */ 	mfc1	$a0,$f16
/*  f18408c:	44818000 */ 	mtc1	$at,$f16
/*  f184090:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f184094:	46106401 */ 	sub.s	$f16,$f12,$f16
/*  f184098:	44c4f800 */ 	ctc1	$a0,$31
/*  f18409c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1840a0:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f1840a4:	4444f800 */ 	cfc1	$a0,$31
/*  f1840a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1840ac:	30840078 */ 	andi	$a0,$a0,0x78
/*  f1840b0:	14800005 */ 	bnez	$a0,.L0f1840c8
/*  f1840b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1840b8:	44048000 */ 	mfc1	$a0,$f16
/*  f1840bc:	3c018000 */ 	lui	$at,0x8000
/*  f1840c0:	10000007 */ 	beqz	$zero,.L0f1840e0
/*  f1840c4:	00812025 */ 	or	$a0,$a0,$at
.L0f1840c8:
/*  f1840c8:	10000005 */ 	beqz	$zero,.L0f1840e0
/*  f1840cc:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f1840d0:	44048000 */ 	mfc1	$a0,$f16
.L0f1840d4:
/*  f1840d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1840d8:	0480fffb */ 	bltz	$a0,.L0f1840c8
/*  f1840dc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1840e0:
/*  f1840e0:	44cff800 */ 	ctc1	$t7,$31
/*  f1840e4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1840e8:	00805025 */ 	or	$t2,$a0,$zero
/*  f1840ec:	3c014f00 */ 	lui	$at,0x4f00
/*  f1840f0:	4459f800 */ 	cfc1	$t9,$31
/*  f1840f4:	44c5f800 */ 	ctc1	$a1,$31
/*  f1840f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1840fc:	460074a4 */ 	cvt.w.s	$f18,$f14
/*  f184100:	4445f800 */ 	cfc1	$a1,$31
/*  f184104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184108:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f18410c:	50a00013 */ 	beqzl	$a1,.L0f18415c
/*  f184110:	44059000 */ 	mfc1	$a1,$f18
/*  f184114:	44819000 */ 	mtc1	$at,$f18
/*  f184118:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f18411c:	46127481 */ 	sub.s	$f18,$f14,$f18
/*  f184120:	44c5f800 */ 	ctc1	$a1,$31
/*  f184124:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184128:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f18412c:	4445f800 */ 	cfc1	$a1,$31
/*  f184130:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184134:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f184138:	14a00005 */ 	bnez	$a1,.L0f184150
/*  f18413c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184140:	44059000 */ 	mfc1	$a1,$f18
/*  f184144:	3c018000 */ 	lui	$at,0x8000
/*  f184148:	10000007 */ 	beqz	$zero,.L0f184168
/*  f18414c:	00a12825 */ 	or	$a1,$a1,$at
.L0f184150:
/*  f184150:	10000005 */ 	beqz	$zero,.L0f184168
/*  f184154:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f184158:	44059000 */ 	mfc1	$a1,$f18
.L0f18415c:
/*  f18415c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184160:	04a0fffb */ 	bltz	$a1,.L0f184150
/*  f184164:	00000000 */ 	sll	$zero,$zero,0x0
.L0f184168:
/*  f184168:	44d9f800 */ 	ctc1	$t9,$31
/*  f18416c:	2c410100 */ 	sltiu	$at,$v0,0x100
/*  f184170:	14200002 */ 	bnez	$at,.L0f18417c
/*  f184174:	00a05825 */ 	or	$t3,$a1,$zero
/*  f184178:	240800ff */ 	addiu	$t0,$zero,0xff
.L0f18417c:
/*  f18417c:	2c610100 */ 	sltiu	$at,$v1,0x100
/*  f184180:	14200002 */ 	bnez	$at,.L0f18418c
/*  f184184:	00086600 */ 	sll	$t4,$t0,0x18
/*  f184188:	240900ff */ 	addiu	$t1,$zero,0xff
.L0f18418c:
/*  f18418c:	2c810100 */ 	sltiu	$at,$a0,0x100
/*  f184190:	14200002 */ 	bnez	$at,.L0f18419c
/*  f184194:	02202025 */ 	or	$a0,$s1,$zero
/*  f184198:	240a00ff */ 	addiu	$t2,$zero,0xff
.L0f18419c:
/*  f18419c:	2ca10100 */ 	sltiu	$at,$a1,0x100
/*  f1841a0:	14200002 */ 	bnez	$at,.L0f1841ac
/*  f1841a4:	00096c00 */ 	sll	$t5,$t1,0x10
/*  f1841a8:	240b00ff */ 	addiu	$t3,$zero,0xff
.L0f1841ac:
/*  f1841ac:	018dc025 */ 	or	$t8,$t4,$t5
/*  f1841b0:	000a7200 */ 	sll	$t6,$t2,0x8
/*  f1841b4:	030e7825 */ 	or	$t7,$t8,$t6
/*  f1841b8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f1841bc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1841c0:	01eb3825 */ 	or	$a3,$t7,$t3
/*  f1841c4:	8e050080 */ 	lw	$a1,0x80($s0)
/*  f1841c8:	0fc63a7b */ 	jal	func0f18e9ec
/*  f1841cc:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1841d0:	00408825 */ 	or	$s1,$v0,$zero
/*  f1841d4:	2610000c */ 	addiu	$s0,$s0,0xc
.L0f1841d8:
/*  f1841d8:	5614ff10 */ 	bnel	$s0,$s4,.L0f183e1c
/*  f1841dc:	8e030080 */ 	lw	$v1,0x80($s0)
.L0f1841e0:
/*  f1841e0:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f1841e4:	02201025 */ 	or	$v0,$s1,$zero
/*  f1841e8:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f1841ec:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f1841f0:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f1841f4:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f1841f8:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f1841fc:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f184200:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f184204:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f184208:	8fb60044 */ 	lw	$s6,0x44($sp)
/*  f18420c:	8fb70048 */ 	lw	$s7,0x48($sp)
/*  f184210:	03e00008 */ 	jr	$ra
/*  f184214:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

bool scenarioHtmRadar2(s32 *displaylist, struct prop *prop)
{
	if ((g_MpSetup.options & MPOPTION_SHOWONRADAR3) && g_ScenarioData.htm.uplink) {
		if (prop == g_ScenarioData.htm.uplink &&
				(prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR)) {
			struct coord dist;
			dist.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
			dist.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
			dist.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;

			if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				u32 colour = g_TeamColours[teamGetIndex(prop->chr->team)];
				*displaylist = func0f18e9ec(*displaylist, g_ScenarioData.htm.uplink, &dist, colour, 0, 1);
			} else {
				*displaylist = func0f18e9ec(*displaylist, g_ScenarioData.htm.uplink, &dist, 0xff0000, 0, 1);
			}

			return true;
		}
	}

	return false;
}

bool scenarioHtmHighlight(struct prop *prop, u32 *colour)
{
	if (g_MpSetup.options & MPOPTION_HIGHLIGHTTERMINAL) {
		bool highlight = false;

		if (prop == g_ScenarioData.htm.uplink) {
			highlight = true;
		} else {
			s32 i;

			for (i = 0; i < 1; i++) {
				if (g_ScenarioData.htm.unk080[i].prop == prop) {
					highlight = true;
					break;
				}
			}
		}

		if (highlight) {
			colour[0] = 0;
			colour[1] = 0xff;
			colour[2] = 0;
			colour[3] = 0x40;

			return true;
		}
	}

	return false;
}

GLOBAL_ASM(
glabel scenarioPacChooseVictims
/*  f1843d4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f1843d8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1843dc:	3c14800b */ 	lui	$s4,%hi(g_ScenarioData)
/*  f1843e0:	2694c110 */ 	addiu	$s4,$s4,%lo(g_ScenarioData)
/*  f1843e4:	240effff */ 	addiu	$t6,$zero,-1
/*  f1843e8:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f1843ec:	3c03800b */ 	lui	$v1,0x800b
/*  f1843f0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1843f4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1843f8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1843fc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f184400:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f184404:	ae8e0004 */ 	sw	$t6,0x4($s4)
/*  f184408:	a6800002 */ 	sh	$zero,0x2($s4)
/*  f18440c:	2463c128 */ 	addiu	$v1,$v1,-16088
/*  f184410:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
.L0f184414:
/*  f184414:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f184418:	a440001e */ 	sh	$zero,0x1e($v0)
/*  f18441c:	1443fffd */ 	bne	$v0,$v1,.L0f184414
/*  f184420:	a4400036 */ 	sh	$zero,0x36($v0)
/*  f184424:	3c13800b */ 	lui	$s3,%hi(g_MpNumPlayers)
/*  f184428:	2673c530 */ 	addiu	$s3,$s3,%lo(g_MpNumPlayers)
/*  f18442c:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f184430:	00008825 */ 	or	$s1,$zero,$zero
/*  f184434:	1880001f */ 	blez	$a0,.L0f1844b4
/*  f184438:	00008025 */ 	or	$s0,$zero,$zero
.L0f18443c:
/*  f18443c:	0c004b70 */ 	jal	random
/*  f184440:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f184444:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f184448:	0011c040 */ 	sll	$t8,$s1,0x1
/*  f18444c:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f184450:	0044001b */ 	divu	$zero,$v0,$a0
/*  f184454:	00001810 */ 	mfhi	$v1
/*  f184458:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f18445c:	14800002 */ 	bnez	$a0,.L0f184468
/*  f184460:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184464:	0007000d */ 	break	0x7
.L0f184468:
/*  f184468:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f18446c:	1a200009 */ 	blez	$s1,.L0f184494
/*  f184470:	00000000 */ 	sll	$zero,$zero,0x0
.L0f184474:
/*  f184474:	844f0008 */ 	lh	$t7,0x8($v0)
/*  f184478:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18447c:	146f0003 */ 	bne	$v1,$t7,.L0f18448c
/*  f184480:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184484:	10000003 */ 	beqz	$zero,.L0f184494
/*  f184488:	00009025 */ 	or	$s2,$zero,$zero
.L0f18448c:
/*  f18448c:	1611fff9 */ 	bne	$s0,$s1,.L0f184474
/*  f184490:	24420002 */ 	addiu	$v0,$v0,0x2
.L0f184494:
/*  f184494:	52400005 */ 	beqzl	$s2,.L0f1844ac
/*  f184498:	0224082a */ 	slt	$at,$s1,$a0
/*  f18449c:	a7230008 */ 	sh	$v1,0x8($t9)
/*  f1844a0:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f1844a4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1844a8:	0224082a */ 	slt	$at,$s1,$a0
.L0f1844ac:
/*  f1844ac:	5420ffe3 */ 	bnezl	$at,.L0f18443c
/*  f1844b0:	00008025 */ 	or	$s0,$zero,$zero
.L0f1844b4:
/*  f1844b4:	18800005 */ 	blez	$a0,.L0f1844cc
/*  f1844b8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1844bc:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1844c0:
/*  f1844c0:	0204082a */ 	slt	$at,$s0,$a0
/*  f1844c4:	5420fffe */ 	bnezl	$at,.L0f1844c0
/*  f1844c8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1844cc:
/*  f1844cc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1844d0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1844d4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1844d8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1844dc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1844e0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1844e4:	03e00008 */ 	jr	$ra
/*  f1844e8:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

//void scenarioPacChooseVictims(void)
//{
//	s32 i;
//	s32 j;
//
//	g_ScenarioData.pac.unk04 = -1;
//	g_ScenarioData.pac.unk02 = 0;
//
//	for (i = 0; i != MAX_MPCHRS; i++) {
//		g_ScenarioData.pac.unk20[i] = 0;
//		g_ScenarioData.pac.unk34[i] = 0;
//	}
//
//	i = 0;
//
//	while (i < g_MpNumPlayers) {
//		bool isnew = true;
//		s32 victimplayernum = random() % g_MpNumPlayers;
//
//		for (j = 0; j < i; j++) {
//			if (g_ScenarioData.pac.victims[j] == victimplayernum) {
//				isnew = false;
//				break;
//			}
//		}
//
//		if (isnew) {
//			g_ScenarioData.pac.victims[i] = victimplayernum;
//			i++;
//		}
//	}
//
//	for (i = 0; i < g_MpNumPlayers; i++) {
//		// This loop probably printed debug messages
//	}
//}

void scenarioPacInit(void)
{
	scenarioPacChooseVictims();
}

void scenarioPacReset(void)
{
	scenarioPacChooseVictims();
}

GLOBAL_ASM(
glabel scenarioPacHighlight
/*  f18452c:	3c0e800b */ 	lui	$t6,0x800b
/*  f184530:	8dcecb94 */ 	lw	$t6,-0x346c($t6)
/*  f184534:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f184538:	05e3001e */ 	bgezl	$t7,.L0f1845b4
/*  f18453c:	00001025 */ 	or	$v0,$zero,$zero
/*  f184540:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f184544:	24010006 */ 	addiu	$at,$zero,0x6
/*  f184548:	3c18800b */ 	lui	$t8,0x800b
/*  f18454c:	10410003 */ 	beq	$v0,$at,.L0f18455c
/*  f184550:	24010003 */ 	addiu	$at,$zero,0x3
/*  f184554:	54410017 */ 	bnel	$v0,$at,.L0f1845b4
/*  f184558:	00001025 */ 	or	$v0,$zero,$zero
.L0f18455c:
/*  f18455c:	8f18c114 */ 	lw	$t8,-0x3eec($t8)
/*  f184560:	2401ffff */ 	addiu	$at,$zero,-1
/*  f184564:	3c09800b */ 	lui	$t1,0x800b
/*  f184568:	13010011 */ 	beq	$t8,$at,.L0f1845b0
/*  f18456c:	00184040 */ 	sll	$t0,$t8,0x1
/*  f184570:	01284821 */ 	addu	$t1,$t1,$t0
/*  f184574:	8529c118 */ 	lh	$t1,-0x3ee8($t1)
/*  f184578:	3c0b800b */ 	lui	$t3,0x800b
/*  f18457c:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f184580:	00095080 */ 	sll	$t2,$t1,0x2
/*  f184584:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f184588:	8d6bc4d0 */ 	lw	$t3,-0x3b30($t3)
/*  f18458c:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f184590:	240d0040 */ 	addiu	$t5,$zero,0x40
/*  f184594:	172b0006 */ 	bne	$t9,$t3,.L0f1845b0
/*  f184598:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f18459c:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f1845a0:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f1845a4:	aca00008 */ 	sw	$zero,0x8($a1)
/*  f1845a8:	03e00008 */ 	jr	$ra
/*  f1845ac:	acad000c */ 	sw	$t5,0xc($a1)
.L0f1845b0:
/*  f1845b0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1845b4:
/*  f1845b4:	03e00008 */ 	jr	$ra
/*  f1845b8:	00000000 */ 	sll	$zero,$zero,0x0
);

//bool scenarioPacHighlight(struct prop *prop, u32 *colour)
//{
//	if ((g_MpSetup.options & MPOPTION_HIGHLIGHTTARGET) &&
//			(prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR) &&
//			g_ScenarioData.pac.victimindex != -1 &&
//			prop->chr == g_MpPlayerChrs[g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex]]) {
//		colour[0] = 0;
//		colour[1] = 0xff;
//		colour[2] = 0;
//		colour[3] = 0x40;
//
//		return true;
//	}
//
//	return false;
//}

GLOBAL_ASM(
glabel func0f1845bc
/*  f1845bc:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f1845c0:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f1845c4:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*  f1845c8:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f1845cc:	3c18800b */ 	lui	$t8,0x800b
/*  f1845d0:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f1845d4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f1845d8:	8f18c530 */ 	lw	$t8,-0x3ad0($t8)
/*  f1845dc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1845e0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1845e4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1845e8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1845ec:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1845f0:	170f0003 */ 	bne	$t8,$t7,.L0f184600
/*  f1845f4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1845f8:	3c01800b */ 	lui	$at,0x800b
/*  f1845fc:	ac20c114 */ 	sw	$zero,-0x3eec($at)
.L0f184600:
/*  f184600:	3c01800b */ 	lui	$at,0x800b
/*  f184604:	a420c112 */ 	sh	$zero,-0x3eee($at)
/*  f184608:	3c08800b */ 	lui	$t0,0x800b
/*  f18460c:	8d08c114 */ 	lw	$t0,-0x3eec($t0)
/*  f184610:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f184614:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f184618:	8e6b006c */ 	lw	$t3,0x6c($s3)
/*  f18461c:	00084840 */ 	sll	$t1,$t0,0x1
/*  f184620:	00495021 */ 	addu	$t2,$v0,$t1
/*  f184624:	85540008 */ 	lh	$s4,0x8($t2)
/*  f184628:	11600003 */ 	beqz	$t3,.L0f184638
/*  f18462c:	00008825 */ 	or	$s1,$zero,$zero
/*  f184630:	10000002 */ 	beqz	$zero,.L0f18463c
/*  f184634:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f184638:
/*  f184638:	00002825 */ 	or	$a1,$zero,$zero
.L0f18463c:
/*  f18463c:	8e6c0068 */ 	lw	$t4,0x68($s3)
/*  f184640:	00002025 */ 	or	$a0,$zero,$zero
/*  f184644:	00001825 */ 	or	$v1,$zero,$zero
/*  f184648:	11800003 */ 	beqz	$t4,.L0f184658
/*  f18464c:	00001025 */ 	or	$v0,$zero,$zero
/*  f184650:	10000001 */ 	beqz	$zero,.L0f184658
/*  f184654:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f184658:
/*  f184658:	8e6d0064 */ 	lw	$t5,0x64($s3)
/*  f18465c:	27b20048 */ 	addiu	$s2,$sp,0x48
/*  f184660:	11a00003 */ 	beqz	$t5,.L0f184670
/*  f184664:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184668:	10000001 */ 	beqz	$zero,.L0f184670
/*  f18466c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f184670:
/*  f184670:	8e6e0070 */ 	lw	$t6,0x70($s3)
/*  f184674:	11c00003 */ 	beqz	$t6,.L0f184684
/*  f184678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18467c:	10000001 */ 	beqz	$zero,.L0f184684
/*  f184680:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f184684:
/*  f184684:	00437821 */ 	addu	$t7,$v0,$v1
/*  f184688:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f18468c:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f184690:	5b200042 */ 	blezl	$t9,.L0f18479c
/*  f184694:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f184698:
/*  f184698:	16910008 */ 	bne	$s4,$s1,.L0f1846bc
/*  f18469c:	02802025 */ 	or	$a0,$s4,$zero
/*  f1846a0:	0fc5b9f1 */ 	jal	textGet
/*  f1846a4:	2404540d */ 	addiu	$a0,$zero,0x540d
/*  f1846a8:	02402025 */ 	or	$a0,$s2,$zero
/*  f1846ac:	0c004dad */ 	jal	sprintf
/*  f1846b0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1846b4:	10000018 */ 	beqz	$zero,.L0f184718
/*  f1846b8:	02202025 */ 	or	$a0,$s1,$zero
.L0f1846bc:
/*  f1846bc:	3c09800b */ 	lui	$t1,%hi(var800ac500)
/*  f1846c0:	2529c500 */ 	addiu	$t1,$t1,%lo(var800ac500)
/*  f1846c4:	00144080 */ 	sll	$t0,$s4,0x2
/*  f1846c8:	01098021 */ 	addu	$s0,$t0,$t1
/*  f1846cc:	0fc619e0 */ 	jal	func0f186780
/*  f1846d0:	02202825 */ 	or	$a1,$s1,$zero
/*  f1846d4:	10400009 */ 	beqz	$v0,.L0f1846fc
/*  f1846d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1846dc:	0fc5b9f1 */ 	jal	textGet
/*  f1846e0:	2404540e */ 	addiu	$a0,$zero,0x540e
/*  f1846e4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1846e8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1846ec:	0c004dad */ 	jal	sprintf
/*  f1846f0:	8e060000 */ 	lw	$a2,0x0($s0)
/*  f1846f4:	10000008 */ 	beqz	$zero,.L0f184718
/*  f1846f8:	02202025 */ 	or	$a0,$s1,$zero
.L0f1846fc:
/*  f1846fc:	0fc5b9f1 */ 	jal	textGet
/*  f184700:	2404540f */ 	addiu	$a0,$zero,0x540f
/*  f184704:	02402025 */ 	or	$a0,$s2,$zero
/*  f184708:	00402825 */ 	or	$a1,$v0,$zero
/*  f18470c:	0c004dad */ 	jal	sprintf
/*  f184710:	8e060000 */ 	lw	$a2,0x0($s0)
/*  f184714:	02202025 */ 	or	$a0,$s1,$zero
.L0f184718:
/*  f184718:	0fc619ae */ 	jal	func0f1866b8
/*  f18471c:	02402825 */ 	or	$a1,$s2,$zero
/*  f184720:	8e6a006c */ 	lw	$t2,0x6c($s3)
/*  f184724:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f184728:	00002825 */ 	or	$a1,$zero,$zero
/*  f18472c:	11400003 */ 	beqz	$t2,.L0f18473c
/*  f184730:	00002025 */ 	or	$a0,$zero,$zero
/*  f184734:	10000001 */ 	beqz	$zero,.L0f18473c
/*  f184738:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f18473c:
/*  f18473c:	8e6b0068 */ 	lw	$t3,0x68($s3)
/*  f184740:	00001825 */ 	or	$v1,$zero,$zero
/*  f184744:	00001025 */ 	or	$v0,$zero,$zero
/*  f184748:	11600003 */ 	beqz	$t3,.L0f184758
/*  f18474c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184750:	10000001 */ 	beqz	$zero,.L0f184758
/*  f184754:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f184758:
/*  f184758:	8e6c0064 */ 	lw	$t4,0x64($s3)
/*  f18475c:	11800003 */ 	beqz	$t4,.L0f18476c
/*  f184760:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184764:	10000001 */ 	beqz	$zero,.L0f18476c
/*  f184768:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f18476c:
/*  f18476c:	8e6d0070 */ 	lw	$t5,0x70($s3)
/*  f184770:	11a00003 */ 	beqz	$t5,.L0f184780
/*  f184774:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184778:	10000001 */ 	beqz	$zero,.L0f184780
/*  f18477c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f184780:
/*  f184780:	00437021 */ 	addu	$t6,$v0,$v1
/*  f184784:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f184788:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f18478c:	0238082a */ 	slt	$at,$s1,$t8
/*  f184790:	1420ffc1 */ 	bnez	$at,.L0f184698
/*  f184794:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184798:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f18479c:
/*  f18479c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1847a0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1847a4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1847a8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1847ac:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1847b0:	03e00008 */ 	jr	$ra
/*  f1847b4:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0f1847b8
/*  f1847b8:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f1847bc:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f1847c0:	8c6e0004 */ 	lw	$t6,0x4($v1)
/*  f1847c4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1847c8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1847cc:	00808025 */ 	or	$s0,$a0,$zero
/*  f1847d0:	05c00036 */ 	bltz	$t6,.L0f1848ac
/*  f1847d4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1847d8:	3c0f800b */ 	lui	$t7,0x800b
/*  f1847dc:	8defc114 */ 	lw	$t7,-0x3eec($t7)
/*  f1847e0:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f1847e4:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f1847e8:	87280008 */ 	lh	$t0,0x8($t9)
/*  f1847ec:	54a80030 */ 	bnel	$a1,$t0,.L0f1848b0
/*  f1847f0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1847f4:	1085002c */ 	beq	$a0,$a1,.L0f1848a8
/*  f1847f8:	3c01800b */ 	lui	$at,0x800b
/*  f1847fc:	04800026 */ 	bltz	$a0,.L0f184898
/*  f184800:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184804:	0fc619e0 */ 	jal	func0f186780
/*  f184808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18480c:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f184810:	1040000d */ 	beqz	$v0,.L0f184848
/*  f184814:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f184818:	0fc5b9f1 */ 	jal	textGet
/*  f18481c:	24045408 */ 	addiu	$a0,$zero,0x5408
/*  f184820:	02002025 */ 	or	$a0,$s0,$zero
/*  f184824:	0fc619ae */ 	jal	func0f1866b8
/*  f184828:	00402825 */ 	or	$a1,$v0,$zero
/*  f18482c:	0fc5b9f1 */ 	jal	textGet
/*  f184830:	24045409 */ 	addiu	$a0,$zero,0x5409
/*  f184834:	02002025 */ 	or	$a0,$s0,$zero
/*  f184838:	0fc619ae */ 	jal	func0f1866b8
/*  f18483c:	00402825 */ 	or	$a1,$v0,$zero
/*  f184840:	10000015 */ 	beqz	$zero,.L0f184898
/*  f184844:	00000000 */ 	sll	$zero,$zero,0x0
.L0f184848:
/*  f184848:	00104840 */ 	sll	$t1,$s0,0x1
/*  f18484c:	00691021 */ 	addu	$v0,$v1,$t1
/*  f184850:	844a0020 */ 	lh	$t2,0x20($v0)
/*  f184854:	2404540a */ 	addiu	$a0,$zero,0x540a
/*  f184858:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f18485c:	0fc5b9f1 */ 	jal	textGet
/*  f184860:	a44b0020 */ 	sh	$t3,0x20($v0)
/*  f184864:	02002025 */ 	or	$a0,$s0,$zero
/*  f184868:	0fc619ae */ 	jal	func0f1866b8
/*  f18486c:	00402825 */ 	or	$a1,$v0,$zero
/*  f184870:	0fc5b9f1 */ 	jal	textGet
/*  f184874:	2404540b */ 	addiu	$a0,$zero,0x540b
/*  f184878:	02002025 */ 	or	$a0,$s0,$zero
/*  f18487c:	0fc619ae */ 	jal	func0f1866b8
/*  f184880:	00402825 */ 	or	$a1,$v0,$zero
/*  f184884:	0fc5b9f1 */ 	jal	textGet
/*  f184888:	2404540c */ 	addiu	$a0,$zero,0x540c
/*  f18488c:	02002025 */ 	or	$a0,$s0,$zero
/*  f184890:	0fc619ae */ 	jal	func0f1866b8
/*  f184894:	00402825 */ 	or	$a1,$v0,$zero
.L0f184898:
/*  f184898:	0fc6116f */ 	jal	func0f1845bc
/*  f18489c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1848a0:	10000003 */ 	beqz	$zero,.L0f1848b0
/*  f1848a4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f1848a8:
/*  f1848a8:	a420c112 */ 	sh	$zero,-0x3eee($at)
.L0f1848ac:
/*  f1848ac:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f1848b0:
/*  f1848b0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1848b4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1848b8:	03e00008 */ 	jr	$ra
/*  f1848bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel scenarioPacCallback10
/*  f1848c0:	3c09800b */ 	lui	$t1,%hi(g_ScenarioData)
/*  f1848c4:	2529c110 */ 	addiu	$t1,$t1,%lo(g_ScenarioData)
/*  f1848c8:	8d2e0004 */ 	lw	$t6,0x4($t1)
/*  f1848cc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1848d0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1848d4:	15c10005 */ 	bne	$t6,$at,.L0f1848ec
/*  f1848d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1848dc:	0fc6116f */ 	jal	func0f1845bc
/*  f1848e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1848e4:	3c09800b */ 	lui	$t1,%hi(g_ScenarioData)
/*  f1848e8:	2529c110 */ 	addiu	$t1,$t1,%lo(g_ScenarioData)
.L0f1848ec:
/*  f1848ec:	3c0f800b */ 	lui	$t7,0x800b
/*  f1848f0:	8defc114 */ 	lw	$t7,-0x3eec($t7)
/*  f1848f4:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f1848f8:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f1848fc:	05e00042 */ 	bltz	$t7,.L0f184a08
/*  f184900:	3c0c800b */ 	lui	$t4,0x800b
/*  f184904:	8cf8006c */ 	lw	$t8,0x6c($a3)
/*  f184908:	00004025 */ 	or	$t0,$zero,$zero
/*  f18490c:	00002825 */ 	or	$a1,$zero,$zero
/*  f184910:	13000003 */ 	beqz	$t8,.L0f184920
/*  f184914:	00003025 */ 	or	$a2,$zero,$zero
/*  f184918:	10000001 */ 	beqz	$zero,.L0f184920
/*  f18491c:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f184920:
/*  f184920:	8cf90068 */ 	lw	$t9,0x68($a3)
/*  f184924:	00001025 */ 	or	$v0,$zero,$zero
/*  f184928:	13200003 */ 	beqz	$t9,.L0f184938
/*  f18492c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184930:	10000001 */ 	beqz	$zero,.L0f184938
/*  f184934:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f184938:
/*  f184938:	8cea0064 */ 	lw	$t2,0x64($a3)
/*  f18493c:	11400003 */ 	beqz	$t2,.L0f18494c
/*  f184940:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184944:	10000001 */ 	beqz	$zero,.L0f18494c
/*  f184948:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f18494c:
/*  f18494c:	8ceb0070 */ 	lw	$t3,0x70($a3)
/*  f184950:	11600003 */ 	beqz	$t3,.L0f184960
/*  f184954:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184958:	10000001 */ 	beqz	$zero,.L0f184960
/*  f18495c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f184960:
/*  f184960:	8d8cc114 */ 	lw	$t4,-0x3eec($t4)
/*  f184964:	00467021 */ 	addu	$t6,$v0,$a2
/*  f184968:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f18496c:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f184970:	012d1821 */ 	addu	$v1,$t1,$t5
/*  f184974:	84640008 */ 	lh	$a0,0x8($v1)
/*  f184978:	01e8c021 */ 	addu	$t8,$t7,$t0
/*  f18497c:	3c02800b */ 	lui	$v0,0x800b
/*  f184980:	0098082a */ 	slt	$at,$a0,$t8
/*  f184984:	10200006 */ 	beqz	$at,.L0f1849a0
/*  f184988:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f18498c:	00f95021 */ 	addu	$t2,$a3,$t9
/*  f184990:	8d4b0064 */ 	lw	$t3,0x64($t2)
/*  f184994:	8d6c00d8 */ 	lw	$t4,0xd8($t3)
/*  f184998:	5580001c */ 	bnezl	$t4,.L0f184a0c
/*  f18499c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1849a0:
/*  f1849a0:	9442c112 */ 	lhu	$v0,-0x3eee($v0)
/*  f1849a4:	8ced0034 */ 	lw	$t5,0x34($a3)
/*  f1849a8:	3c01800b */ 	lui	$at,0x800b
/*  f1849ac:	004d1021 */ 	addu	$v0,$v0,$t5
/*  f1849b0:	304effff */ 	andi	$t6,$v0,0xffff
/*  f1849b4:	a42ec112 */ 	sh	$t6,-0x3eee($at)
/*  f1849b8:	2dc13841 */ 	sltiu	$at,$t6,0x3841
/*  f1849bc:	14200012 */ 	bnez	$at,.L0f184a08
/*  f1849c0:	3c01800b */ 	lui	$at,0x800b
/*  f1849c4:	a420c112 */ 	sh	$zero,-0x3eee($at)
/*  f1849c8:	846f0008 */ 	lh	$t7,0x8($v1)
/*  f1849cc:	24045407 */ 	addiu	$a0,$zero,0x5407
/*  f1849d0:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f1849d4:	01381021 */ 	addu	$v0,$t1,$t8
/*  f1849d8:	84590038 */ 	lh	$t9,0x38($v0)
/*  f1849dc:	272a0001 */ 	addiu	$t2,$t9,0x1
/*  f1849e0:	0fc5b9f1 */ 	jal	textGet
/*  f1849e4:	a44a0038 */ 	sh	$t2,0x38($v0)
/*  f1849e8:	3c0b800b */ 	lui	$t3,0x800b
/*  f1849ec:	8d6bc114 */ 	lw	$t3,-0x3eec($t3)
/*  f1849f0:	3c04800b */ 	lui	$a0,0x800b
/*  f1849f4:	00402825 */ 	or	$a1,$v0,$zero
/*  f1849f8:	000b6040 */ 	sll	$t4,$t3,0x1
/*  f1849fc:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f184a00:	0fc619ae */ 	jal	func0f1866b8
/*  f184a04:	8484c118 */ 	lh	$a0,-0x3ee8($a0)
.L0f184a08:
/*  f184a08:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f184a0c:
/*  f184a0c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f184a10:	03e00008 */ 	jr	$ra
/*  f184a14:	00000000 */ 	sll	$zero,$zero,0x0
);

//void scenarioPacCallback10(void)
//{
//	if (g_ScenarioData.pac.victimindex == -1) {
//		func0f1845bc();
//	}
//
//	if (g_ScenarioData.pac.victimindex >= 0) {
//		if (PLAYERCOUNT() <= g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex] ||
//				g_Vars.players[g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex]]->isdead == false) {
//			g_ScenarioData.pac.age240 += g_Vars.lvupdate240;
//
//			if (g_ScenarioData.pac.age240 > SECSTOFRAMES240(60)) {
//				g_ScenarioData.pac.age240 = 0;
//				g_ScenarioData.pac.wincounts[g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex]]++;
//				func0f1866b8(g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex], textGet(0x5407)); // "Have a point for living!"
//			}
//		}
//	}
//}

GLOBAL_ASM(
glabel scenarioPacCallback18
/*  f184a18:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f184a1c:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f184a20:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f184a24:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f184a28:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f184a2c:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f184a30:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f184a34:	87290008 */ 	lh	$t1,0x8($t9)
/*  f184a38:	8c6e028c */ 	lw	$t6,0x28c($v1)
/*  f184a3c:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f184a40:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f184a44:	00808025 */ 	or	$s0,$a0,$zero
/*  f184a48:	15c9006e */ 	bne	$t6,$t1,.L0f184c04
/*  f184a4c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f184a50:	8c6a0284 */ 	lw	$t2,0x284($v1)
/*  f184a54:	3c0c800b */ 	lui	$t4,0x800b
/*  f184a58:	8d4b00d8 */ 	lw	$t3,0xd8($t2)
/*  f184a5c:	5560006a */ 	bnezl	$t3,.L0f184c08
/*  f184a60:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f184a64:	958cc112 */ 	lhu	$t4,-0x3eee($t4)
/*  f184a68:	240d3840 */ 	addiu	$t5,$zero,0x3840
/*  f184a6c:	01ac1823 */ 	subu	$v1,$t5,$t4
/*  f184a70:	0c002f40 */ 	jal	func0000bd00
/*  f184a74:	afa300a0 */ 	sw	$v1,0xa0($sp)
/*  f184a78:	0c002f22 */ 	jal	func0000bc88
/*  f184a7c:	a7a20046 */ 	sh	$v0,0x46($sp)
/*  f184a80:	87b80046 */ 	lh	$t8,0x46($sp)
/*  f184a84:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f184a88:	04410003 */ 	bgez	$v0,.L0f184a98
/*  f184a8c:	00027843 */ 	sra	$t7,$v0,0x1
/*  f184a90:	24410001 */ 	addiu	$at,$v0,0x1
/*  f184a94:	00017843 */ 	sra	$t7,$at,0x1
.L0f184a98:
/*  f184a98:	01f82821 */ 	addu	$a1,$t7,$t8
/*  f184a9c:	0c002f44 */ 	jal	func0000bd10
/*  f184aa0:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f184aa4:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f184aa8:	2446000a */ 	addiu	$a2,$v0,0xa
/*  f184aac:	afa60088 */ 	sw	$a2,0x88($sp)
/*  f184ab0:	04610002 */ 	bgez	$v1,.L0f184abc
/*  f184ab4:	24083840 */ 	addiu	$t0,$zero,0x3840
/*  f184ab8:	00001825 */ 	or	$v1,$zero,$zero
.L0f184abc:
/*  f184abc:	0068001a */ 	div	$zero,$v1,$t0
/*  f184ac0:	00001012 */ 	mflo	$v0
/*  f184ac4:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f184ac8:	15000002 */ 	bnez	$t0,.L0f184ad4
/*  f184acc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184ad0:	0007000d */ 	break	0x7
.L0f184ad4:
/*  f184ad4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f184ad8:	15010004 */ 	bne	$t0,$at,.L0f184aec
/*  f184adc:	3c018000 */ 	lui	$at,0x8000
/*  f184ae0:	14610002 */ 	bne	$v1,$at,.L0f184aec
/*  f184ae4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184ae8:	0006000d */ 	break	0x6
.L0f184aec:
/*  f184aec:	00480019 */ 	multu	$v0,$t0
/*  f184af0:	240100f0 */ 	addiu	$at,$zero,0xf0
/*  f184af4:	00403025 */ 	or	$a2,$v0,$zero
/*  f184af8:	24a588c0 */ 	addiu	$a1,$a1,-30528
/*  f184afc:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f184b00:	0000c812 */ 	mflo	$t9
/*  f184b04:	00791823 */ 	subu	$v1,$v1,$t9
/*  f184b08:	246700ef */ 	addiu	$a3,$v1,0xef
/*  f184b0c:	00e1001a */ 	div	$zero,$a3,$at
/*  f184b10:	00003812 */ 	mflo	$a3
/*  f184b14:	0c004dad */ 	jal	sprintf
/*  f184b18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184b1c:	0fc54d8a */ 	jal	func0f153628
/*  f184b20:	02002025 */ 	or	$a0,$s0,$zero
/*  f184b24:	3c098008 */ 	lui	$t1,0x8008
/*  f184b28:	8d29fb04 */ 	lw	$t1,-0x4fc($t1)
/*  f184b2c:	3c078008 */ 	lui	$a3,0x8008
/*  f184b30:	00408025 */ 	or	$s0,$v0,$zero
/*  f184b34:	8ce7fb08 */ 	lw	$a3,-0x4f8($a3)
/*  f184b38:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f184b3c:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f184b40:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f184b44:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f184b48:	0fc55cbe */ 	jal	func0f1572f8
/*  f184b4c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f184b50:	8fa70094 */ 	lw	$a3,0x94($sp)
/*  f184b54:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f184b58:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f184b5c:	8fa60088 */ 	lw	$a2,0x88($sp)
/*  f184b60:	04e10003 */ 	bgez	$a3,.L0f184b70
/*  f184b64:	00075043 */ 	sra	$t2,$a3,0x1
/*  f184b68:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f184b6c:	00015043 */ 	sra	$t2,$at,0x1
.L0f184b70:
/*  f184b70:	00aa2823 */ 	subu	$a1,$a1,$t2
/*  f184b74:	00e53821 */ 	addu	$a3,$a3,$a1
/*  f184b78:	00461021 */ 	addu	$v0,$v0,$a2
/*  f184b7c:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f184b80:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f184b84:	afa70094 */ 	sw	$a3,0x94($sp)
/*  f184b88:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f184b8c:	0fc54e64 */ 	jal	func0f153990
/*  f184b90:	02002025 */ 	or	$a0,$s0,$zero
/*  f184b94:	0c002f02 */ 	jal	func0000bc08
/*  f184b98:	00408025 */ 	or	$s0,$v0,$zero
/*  f184b9c:	0c002f06 */ 	jal	func0000bc18
/*  f184ba0:	a7a20044 */ 	sh	$v0,0x44($sp)
/*  f184ba4:	3c0b8008 */ 	lui	$t3,0x8008
/*  f184ba8:	3c0d8008 */ 	lui	$t5,0x8008
/*  f184bac:	8dadfafc */ 	lw	$t5,-0x504($t5)
/*  f184bb0:	8d6bfb00 */ 	lw	$t3,-0x500($t3)
/*  f184bb4:	87b80044 */ 	lh	$t8,0x44($sp)
/*  f184bb8:	3c0c00ff */ 	lui	$t4,0xff
/*  f184bbc:	358c00a0 */ 	ori	$t4,$t4,0xa0
/*  f184bc0:	240f00a0 */ 	addiu	$t7,$zero,0xa0
/*  f184bc4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f184bc8:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f184bcc:	02002025 */ 	or	$a0,$s0,$zero
/*  f184bd0:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f184bd4:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f184bd8:	27a70048 */ 	addiu	$a3,$sp,0x48
/*  f184bdc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f184be0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f184be4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f184be8:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f184bec:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f184bf0:	0fc55b92 */ 	jal	func0f156e48
/*  f184bf4:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f184bf8:	0fc54de0 */ 	jal	func0f153780
/*  f184bfc:	00402025 */ 	or	$a0,$v0,$zero
/*  f184c00:	00408025 */ 	or	$s0,$v0,$zero
.L0f184c04:
/*  f184c04:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f184c08:
/*  f184c08:	02001025 */ 	or	$v0,$s0,$zero
/*  f184c0c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f184c10:	03e00008 */ 	jr	$ra
/*  f184c14:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

void scenarioPacKill(struct mpchr *mpchr, s32 arg1, s32 *score, s32 *arg3)
{
	struct mpchr *loopmpchr;
	s32 i;
	s32 index;

	*score = 0;
	index = func0f18d0e8(arg1);

	if (index >= 0) {
		*score += g_ScenarioData.pac.unk20[index] * 2;
		*score += g_ScenarioData.pac.wincounts[index];
	}

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == arg1) {
				*score -= mpchr->unk24[i];
			} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				if (i < 4) {
					loopmpchr = &g_MpPlayers[i].base;
				} else {
					loopmpchr = &g_MpSimulants[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->unk24[i];
				} else {
					*score += mpchr->unk24[i];
				}
			} else {
				*score += mpchr->unk24[i];
			}
		}
	}

	*arg3 = mpchr->unk3c;
}

s32 scenarioPacRadar(s32 value)
{
	return value;
}

GLOBAL_ASM(
glabel scenarioPacRadar2
/*  f184d8c:	3c03800b */ 	lui	$v1,0x800b
/*  f184d90:	8c63cb94 */ 	lw	$v1,-0x346c($v1)
/*  f184d94:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f184d98:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f184d9c:	000372c0 */ 	sll	$t6,$v1,0xb
/*  f184da0:	05c10042 */ 	bgez	$t6,.L0f184eac
/*  f184da4:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f184da8:	3c0f800b */ 	lui	$t7,0x800b
/*  f184dac:	8defc114 */ 	lw	$t7,-0x3eec($t7)
/*  f184db0:	3c19800b */ 	lui	$t9,0x800b
/*  f184db4:	05e0003d */ 	bltz	$t7,.L0f184eac
/*  f184db8:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f184dbc:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f184dc0:	8739c118 */ 	lh	$t9,-0x3ee8($t9)
/*  f184dc4:	3c09800b */ 	lui	$t1,0x800b
/*  f184dc8:	3c02800a */ 	lui	$v0,0x800a
/*  f184dcc:	00194080 */ 	sll	$t0,$t9,0x2
/*  f184dd0:	01284821 */ 	addu	$t1,$t1,$t0
/*  f184dd4:	8d29c4d0 */ 	lw	$t1,-0x3b30($t1)
/*  f184dd8:	8d2a001c */ 	lw	$t2,0x1c($t1)
/*  f184ddc:	15450033 */ 	bne	$t2,$a1,.L0f184eac
/*  f184de0:	afaa0034 */ 	sw	$t2,0x34($sp)
/*  f184de4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f184de8:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f184dec:	306e0002 */ 	andi	$t6,$v1,0x2
/*  f184df0:	8c4b00bc */ 	lw	$t3,0xbc($v0)
/*  f184df4:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f184df8:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f184dfc:	c5660008 */ 	lwc1	$f6,0x8($t3)
/*  f184e00:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f184e04:	3c0700ff */ 	lui	$a3,0xff
/*  f184e08:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f184e0c:	e7a80038 */ 	swc1	$f8,0x38($sp)
/*  f184e10:	8c4c00bc */ 	lw	$t4,0xbc($v0)
/*  f184e14:	c4aa000c */ 	lwc1	$f10,0xc($a1)
/*  f184e18:	c590000c */ 	lwc1	$f16,0xc($t4)
/*  f184e1c:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f184e20:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f184e24:	8c4d00bc */ 	lw	$t5,0xbc($v0)
/*  f184e28:	c4a40010 */ 	lwc1	$f4,0x10($a1)
/*  f184e2c:	c5a60010 */ 	lwc1	$f6,0x10($t5)
/*  f184e30:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f184e34:	11c00014 */ 	beqz	$t6,.L0f184e88
/*  f184e38:	e7a80040 */ 	swc1	$f8,0x40($sp)
/*  f184e3c:	8caf0004 */ 	lw	$t7,0x4($a1)
/*  f184e40:	0fc63a5a */ 	jal	teamGetIndex
/*  f184e44:	91e40125 */ 	lbu	$a0,0x125($t7)
/*  f184e48:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f184e4c:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f184e50:	3c078008 */ 	lui	$a3,0x8008
/*  f184e54:	00f83821 */ 	addu	$a3,$a3,$t8
/*  f184e58:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f184e5c:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f184e60:	8ce77cc4 */ 	lw	$a3,0x7cc4($a3)
/*  f184e64:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f184e68:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f184e6c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f184e70:	0fc63a7b */ 	jal	func0f18e9ec
/*  f184e74:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f184e78:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f184e7c:	ad220000 */ 	sw	$v0,0x0($t1)
/*  f184e80:	1000000b */ 	beqz	$zero,.L0f184eb0
/*  f184e84:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f184e88:
/*  f184e88:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f184e8c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f184e90:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f184e94:	0fc63a7b */ 	jal	func0f18e9ec
/*  f184e98:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f184e9c:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f184ea0:	ad820000 */ 	sw	$v0,0x0($t4)
/*  f184ea4:	10000002 */ 	beqz	$zero,.L0f184eb0
/*  f184ea8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f184eac:
/*  f184eac:	00001025 */ 	or	$v0,$zero,$zero
.L0f184eb0:
/*  f184eb0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f184eb4:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f184eb8:	03e00008 */ 	jr	$ra
/*  f184ebc:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatch because the game jumps to pac properties directly
// while decomp loads the base pac address then uses offsets.
//bool scenarioPacRadar2(s32 *displaylist, struct prop *prop)
//{
//	if ((g_MpSetup.options & MPOPTION_SHOWONRADAR4) && g_ScenarioData.pac.victimindex >= 0) {
//		s32 index = g_ScenarioData.pac.victimindex;
//		struct prop *thing = g_MpPlayerChrs[g_ScenarioData.pac.victims[index]]->prop;
//
//		if (thing == prop) {
//			struct coord dist;
//			dist.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
//			dist.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
//			dist.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;
//
//			if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
//				u32 colour = g_TeamColours[teamGetIndex(prop->chr->team)];
//				*displaylist = func0f18e9ec(*displaylist, thing, &dist, colour, 0, 1);
//			} else {
//				*displaylist = func0f18e9ec(*displaylist, thing, &dist, 0xff0000, 0, 1);
//			}
//
//			return true;
//		}
//	}
//
//	return false;
//}

GLOBAL_ASM(
glabel menudialog00184ec0
/*  f184ec0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f184ec4:	24010066 */ 	addiu	$at,$zero,0x66
/*  f184ec8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f184ecc:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f184ed0:	14810032 */ 	bne	$a0,$at,.L0f184f9c
/*  f184ed4:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f184ed8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f184edc:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f184ee0:	3c19800b */ 	lui	$t9,0x800b
/*  f184ee4:	9339cb98 */ 	lbu	$t9,-0x3468($t9)
/*  f184ee8:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f184eec:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f184ef0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f184ef4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f184ef8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f184efc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f184f00:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f184f04:	3c18800a */ 	lui	$t8,0x800a
/*  f184f08:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f184f0c:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f184f10:	8f18e4f8 */ 	lw	$t8,-0x1b08($t8)
/*  f184f14:	3c098008 */ 	lui	$t1,%hi(g_MpScenarios)
/*  f184f18:	01194021 */ 	addu	$t0,$t0,$t9
/*  f184f1c:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f184f20:	25296f98 */ 	addiu	$t1,$t1,%lo(g_MpScenarios)
/*  f184f24:	01095021 */ 	addu	$t2,$t0,$t1
/*  f184f28:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f184f2c:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f184f30:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f184f34:	01201825 */ 	or	$v1,$t1,$zero
/*  f184f38:	108b0018 */ 	beq	$a0,$t3,.L0f184f9c
/*  f184f3c:	00001025 */ 	or	$v0,$zero,$zero
.L0f184f40:
/*  f184f40:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f184f44:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f184f48:	0045082a */ 	slt	$at,$v0,$a1
/*  f184f4c:	108c0003 */ 	beq	$a0,$t4,.L0f184f5c
/*  f184f50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184f54:	1420fffa */ 	bnez	$at,.L0f184f40
/*  f184f58:	24630048 */ 	addiu	$v1,$v1,0x48
.L0f184f5c:
/*  f184f5c:	3c0d8008 */ 	lui	$t5,%hi(mpscenarios)
/*  f184f60:	25ad7148 */ 	addiu	$t5,$t5,%lo(mpscenarios)
/*  f184f64:	006d082b */ 	sltu	$at,$v1,$t5
/*  f184f68:	5020000d */ 	beqzl	$at,.L0f184fa0
/*  f184f6c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f184f70:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f184f74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184f78:	3c0e800b */ 	lui	$t6,0x800b
/*  f184f7c:	91cecb98 */ 	lbu	$t6,-0x3468($t6)
/*  f184f80:	3c048008 */ 	lui	$a0,0x8008
/*  f184f84:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f184f88:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f184f8c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f184f90:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f184f94:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f184f98:	8c846f98 */ 	lw	$a0,0x6f98($a0)
.L0f184f9c:
/*  f184f9c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f184fa0:
/*  f184fa0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f184fa4:	00001025 */ 	or	$v0,$zero,$zero
/*  f184fa8:	03e00008 */ 	jr	$ra
/*  f184fac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f184fb0
/*  f184fb0:	3c0e800b */ 	lui	$t6,0x800b
/*  f184fb4:	91cecb98 */ 	lbu	$t6,-0x3468($t6)
/*  f184fb8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f184fbc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f184fc0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f184fc4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f184fc8:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f184fcc:	3c048008 */ 	lui	$a0,0x8008
/*  f184fd0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f184fd4:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f184fd8:	0fc5b9f1 */ 	jal	textGet
/*  f184fdc:	9484714a */ 	lhu	$a0,0x714a($a0)
/*  f184fe0:	3c048007 */ 	lui	$a0,0x8007
/*  f184fe4:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f184fe8:	24a588c8 */ 	addiu	$a1,$a1,-30520
/*  f184fec:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f184ff0:	0c004dad */ 	jal	sprintf
/*  f184ff4:	00403025 */ 	or	$a2,$v0,$zero
/*  f184ff8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f184ffc:	3c028007 */ 	lui	$v0,0x8007
/*  f185000:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f185004:	03e00008 */ 	jr	$ra
/*  f185008:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f18500c
/*  f18500c:	3c0e800b */ 	lui	$t6,0x800b
/*  f185010:	91cecb98 */ 	lbu	$t6,-0x3468($t6)
/*  f185014:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f185018:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f18501c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f185020:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f185024:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f185028:	3c048008 */ 	lui	$a0,0x8008
/*  f18502c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f185030:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f185034:	0fc5b9f1 */ 	jal	textGet
/*  f185038:	94847148 */ 	lhu	$a0,0x7148($a0)
/*  f18503c:	3c048007 */ 	lui	$a0,0x8007
/*  f185040:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f185044:	24a588cc */ 	addiu	$a1,$a1,-30516
/*  f185048:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f18504c:	0c004dad */ 	jal	sprintf
/*  f185050:	00403025 */ 	or	$a2,$v0,$zero
/*  f185054:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f185058:	3c028007 */ 	lui	$v0,0x8007
/*  f18505c:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f185060:	03e00008 */ 	jr	$ra
/*  f185064:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel menuhandler00185068
/*  f185068:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f18506c:	3c0e8008 */ 	lui	$t6,%hi(var8008716c)
/*  f185070:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f185074:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f185078:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f18507c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f185080:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f185084:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f185088:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18508c:	25ce716c */ 	addiu	$t6,$t6,%lo(var8008716c)
/*  f185090:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f185094:	27b30040 */ 	addiu	$s3,$sp,0x40
/*  f185098:	00c0a825 */ 	or	$s5,$a2,$zero
/*  f18509c:	ae610000 */ 	sw	$at,0x0($s3)
/*  f1850a0:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f1850a4:	00009025 */ 	or	$s2,$zero,$zero
/*  f1850a8:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f1850ac:	ae790004 */ 	sw	$t9,0x4($s3)
/*  f1850b0:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f1850b4:	3c02800a */ 	lui	$v0,0x800a
/*  f1850b8:	2489ffff */ 	addiu	$t1,$a0,-1
/*  f1850bc:	ae610008 */ 	sw	$at,0x8($s3)
/*  f1850c0:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f1850c4:	ae79000c */ 	sw	$t9,0xc($s3)
/*  f1850c8:	90a80001 */ 	lbu	$t0,0x1($a1)
/*  f1850cc:	51000009 */ 	beqzl	$t0,.L0f1850f4
/*  f1850d0:	2d210007 */ 	sltiu	$at,$t1,0x7
/*  f1850d4:	8c42a470 */ 	lw	$v0,-0x5b90($v0)
/*  f1850d8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1850dc:	50400004 */ 	beqzl	$v0,.L0f1850f0
/*  f1850e0:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1850e4:	54410003 */ 	bnel	$v0,$at,.L0f1850f4
/*  f1850e8:	2d210007 */ 	sltiu	$at,$t1,0x7
/*  f1850ec:	0000a025 */ 	or	$s4,$zero,$zero
.L0f1850f0:
/*  f1850f0:	2d210007 */ 	sltiu	$at,$t1,0x7
.L0f1850f4:
/*  f1850f4:	10200098 */ 	beqz	$at,.L0f185358
/*  f1850f8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1850fc:	3c017f1c */ 	lui	$at,%hi(var7f1b8964)
/*  f185100:	00290821 */ 	addu	$at,$at,$t1
/*  f185104:	8c298964 */ 	lw	$t1,%lo(var7f1b8964)($at)
/*  f185108:	01200008 */ 	jr	$t1
/*  f18510c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185110:	3c108008 */ 	lui	$s0,%hi(mpscenarios)
/*  f185114:	3c118008 */ 	lui	$s1,%hi(var8008716c)
/*  f185118:	2631716c */ 	addiu	$s1,$s1,%lo(var8008716c)
/*  f18511c:	26107148 */ 	addiu	$s0,$s0,%lo(mpscenarios)
.L0f185120:
/*  f185120:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f185124:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f185128:	50400008 */ 	beqzl	$v0,.L0f18514c
/*  f18512c:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f185130:	56800005 */ 	bnezl	$s4,.L0f185148
/*  f185134:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f185138:	920a0005 */ 	lbu	$t2,0x5($s0)
/*  f18513c:	55400003 */ 	bnezl	$t2,.L0f18514c
/*  f185140:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f185144:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f185148:
/*  f185148:	26100006 */ 	addiu	$s0,$s0,0x6
.L0f18514c:
/*  f18514c:	1611fff4 */ 	bne	$s0,$s1,.L0f185120
/*  f185150:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185154:	10000080 */ 	beqz	$zero,.L0f185358
/*  f185158:	aeb20000 */ 	sw	$s2,0x0($s5)
/*  f18515c:	3c108008 */ 	lui	$s0,%hi(mpscenarios)
/*  f185160:	3c118008 */ 	lui	$s1,%hi(var8008716c)
/*  f185164:	2631716c */ 	addiu	$s1,$s1,%lo(var8008716c)
/*  f185168:	26107148 */ 	addiu	$s0,$s0,%lo(mpscenarios)
.L0f18516c:
/*  f18516c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f185170:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f185174:	5040000f */ 	beqzl	$v0,.L0f1851b4
/*  f185178:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f18517c:	56800005 */ 	bnezl	$s4,.L0f185194
/*  f185180:	8eac0000 */ 	lw	$t4,0x0($s5)
/*  f185184:	920b0005 */ 	lbu	$t3,0x5($s0)
/*  f185188:	5560000a */ 	bnezl	$t3,.L0f1851b4
/*  f18518c:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f185190:	8eac0000 */ 	lw	$t4,0x0($s5)
.L0f185194:
/*  f185194:	564c0006 */ 	bnel	$s2,$t4,.L0f1851b0
/*  f185198:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f18519c:	0fc5b9f1 */ 	jal	textGet
/*  f1851a0:	96040000 */ 	lhu	$a0,0x0($s0)
/*  f1851a4:	1000006e */ 	beqz	$zero,.L0f185360
/*  f1851a8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1851ac:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f1851b0:
/*  f1851b0:	26100006 */ 	addiu	$s0,$s0,0x6
.L0f1851b4:
/*  f1851b4:	1611ffed */ 	bne	$s0,$s1,.L0f18516c
/*  f1851b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1851bc:	10000067 */ 	beqz	$zero,.L0f18535c
/*  f1851c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1851c4:	3c108008 */ 	lui	$s0,%hi(mpscenarios)
/*  f1851c8:	26107148 */ 	addiu	$s0,$s0,%lo(mpscenarios)
/*  f1851cc:	00008825 */ 	or	$s1,$zero,$zero
/*  f1851d0:	24130006 */ 	addiu	$s3,$zero,0x6
.L0f1851d4:
/*  f1851d4:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f1851d8:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f1851dc:	5040000d */ 	beqzl	$v0,.L0f185214
/*  f1851e0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1851e4:	56800005 */ 	bnezl	$s4,.L0f1851fc
/*  f1851e8:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f1851ec:	920d0005 */ 	lbu	$t5,0x5($s0)
/*  f1851f0:	55a00008 */ 	bnezl	$t5,.L0f185214
/*  f1851f4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1851f8:	8eb80000 */ 	lw	$t8,0x0($s5)
.L0f1851fc:
/*  f1851fc:	16580003 */ 	bne	$s2,$t8,.L0f18520c
/*  f185200:	3c01800b */ 	lui	$at,0x800b
/*  f185204:	10000005 */ 	beqz	$zero,.L0f18521c
/*  f185208:	a031cb98 */ 	sb	$s1,-0x3468($at)
.L0f18520c:
/*  f18520c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f185210:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f185214:
/*  f185214:	1633ffef */ 	bne	$s1,$s3,.L0f1851d4
/*  f185218:	26100006 */ 	addiu	$s0,$s0,0x6
.L0f18521c:
/*  f18521c:	0fc61521 */ 	jal	scenarioInit
/*  f185220:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185224:	1000004d */ 	beqz	$zero,.L0f18535c
/*  f185228:	00001025 */ 	or	$v0,$zero,$zero
/*  f18522c:	3c108008 */ 	lui	$s0,%hi(mpscenarios)
/*  f185230:	26107148 */ 	addiu	$s0,$s0,%lo(mpscenarios)
/*  f185234:	00008825 */ 	or	$s1,$zero,$zero
/*  f185238:	24130006 */ 	addiu	$s3,$zero,0x6
.L0f18523c:
/*  f18523c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f185240:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f185244:	5040000d */ 	beqzl	$v0,.L0f18527c
/*  f185248:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18524c:	16800004 */ 	bnez	$s4,.L0f185260
/*  f185250:	3c0e800b */ 	lui	$t6,0x800b
/*  f185254:	920f0005 */ 	lbu	$t7,0x5($s0)
/*  f185258:	55e00008 */ 	bnezl	$t7,.L0f18527c
/*  f18525c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f185260:
/*  f185260:	91cecb98 */ 	lbu	$t6,-0x3468($t6)
/*  f185264:	562e0004 */ 	bnel	$s1,$t6,.L0f185278
/*  f185268:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f18526c:	1000003a */ 	beqz	$zero,.L0f185358
/*  f185270:	aeb20000 */ 	sw	$s2,0x0($s5)
/*  f185274:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f185278:
/*  f185278:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18527c:
/*  f18527c:	1633ffef */ 	bne	$s1,$s3,.L0f18523c
/*  f185280:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f185284:	10000035 */ 	beqz	$zero,.L0f18535c
/*  f185288:	00001025 */ 	or	$v0,$zero,$zero
/*  f18528c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f185290:	12800009 */ 	beqz	$s4,.L0f1852b8
/*  f185294:	aeb90000 */ 	sw	$t9,0x0($s5)
/*  f185298:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f18529c:	2404001f */ 	addiu	$a0,$zero,0x1f
/*  f1852a0:	5440002e */ 	bnezl	$v0,.L0f18535c
/*  f1852a4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1852a8:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f1852ac:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f1852b0:	5440002a */ 	bnezl	$v0,.L0f18535c
/*  f1852b4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1852b8:
/*  f1852b8:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f1852bc:	2509ffff */ 	addiu	$t1,$t0,-1
/*  f1852c0:	10000025 */ 	beqz	$zero,.L0f185358
/*  f1852c4:	aea90000 */ 	sw	$t1,0x0($s5)
/*  f1852c8:	8eaa0000 */ 	lw	$t2,0x0($s5)
/*  f1852cc:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f1852d0:	026b6021 */ 	addu	$t4,$s3,$t3
/*  f1852d4:	0fc5b9f1 */ 	jal	textGet
/*  f1852d8:	95840004 */ 	lhu	$a0,0x4($t4)
/*  f1852dc:	10000020 */ 	beqz	$zero,.L0f185360
/*  f1852e0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1852e4:	8ead0000 */ 	lw	$t5,0x0($s5)
/*  f1852e8:	3c108008 */ 	lui	$s0,%hi(mpscenarios)
/*  f1852ec:	26107148 */ 	addiu	$s0,$s0,%lo(mpscenarios)
/*  f1852f0:	000dc0c0 */ 	sll	$t8,$t5,0x3
/*  f1852f4:	02787821 */ 	addu	$t7,$s3,$t8
/*  f1852f8:	8dee0000 */ 	lw	$t6,0x0($t7)
/*  f1852fc:	00008825 */ 	or	$s1,$zero,$zero
/*  f185300:	59c00015 */ 	blezl	$t6,.L0f185358
/*  f185304:	aeb20008 */ 	sw	$s2,0x8($s5)
.L0f185308:
/*  f185308:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f18530c:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f185310:	50400008 */ 	beqzl	$v0,.L0f185334
/*  f185314:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f185318:	56800005 */ 	bnezl	$s4,.L0f185330
/*  f18531c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f185320:	92190005 */ 	lbu	$t9,0x5($s0)
/*  f185324:	57200003 */ 	bnezl	$t9,.L0f185334
/*  f185328:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f18532c:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f185330:
/*  f185330:	8ea80000 */ 	lw	$t0,0x0($s5)
.L0f185334:
/*  f185334:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f185338:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f18533c:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f185340:	02695021 */ 	addu	$t2,$s3,$t1
/*  f185344:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f185348:	022b082a */ 	slt	$at,$s1,$t3
/*  f18534c:	1420ffee */ 	bnez	$at,.L0f185308
/*  f185350:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185354:	aeb20008 */ 	sw	$s2,0x8($s5)
.L0f185358:
/*  f185358:	00001025 */ 	or	$v0,$zero,$zero
.L0f18535c:
/*  f18535c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f185360:
/*  f185360:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f185364:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f185368:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18536c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f185370:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f185374:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f185378:	03e00008 */ 	jr	$ra
/*  f18537c:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

s32 menuhandlerMpOpenOptions(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPushDialog(g_MpScenarios[g_MpSetup.scenario].optionsdialog);
	}

	return 0;
}

void scenarioCallback40(s32 *arg0)
{
	if (g_MpScenarios[g_MpSetup.scenario].unk40) {
		g_MpScenarios[g_MpSetup.scenario].unk40(arg0);
	} else {
		scenarioDefaultCallback40(arg0, 8);
	}
}

void scenarioCallback44(s32 *arg0)
{
	if (g_MpScenarios[g_MpSetup.scenario].unk44) {
		g_MpScenarios[g_MpSetup.scenario].unk44(arg0);
	} else {
		scenarioDefaultCallback44(arg0, 0, 8);
	}
}

void scenarioInit(void)
{
	if (g_MpScenarios[g_MpSetup.scenario].initfunc) {
		g_MpScenarios[g_MpSetup.scenario].initfunc();
	}
}

s32 scenarioCallback08(void)
{
	s32 result = 0;

	if (g_MpScenarios[g_MpSetup.scenario].unk08) {
		result = g_MpScenarios[g_MpSetup.scenario].unk08();
	}

	return result;
}

void scenarioReset(void)
{
	if (g_MpScenarios[g_MpSetup.scenario].resetfunc) {
		g_MpScenarios[g_MpSetup.scenario].resetfunc();
	}
}

GLOBAL_ASM(
glabel func0f185568
/*  f185568:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f18556c:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f185570:	3c14800b */ 	lui	$s4,0x800b
/*  f185574:	2694cbb0 */ 	addiu	$s4,$s4,-13392
/*  f185578:	928f0060 */ 	lbu	$t7,0x60($s4)
/*  f18557c:	3c0e800a */ 	lui	$t6,0x800a
/*  f185580:	8dcea24c */ 	lw	$t6,-0x5db4($t6)
/*  f185584:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f185588:	24130005 */ 	addiu	$s3,$zero,0x5
/*  f18558c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f185590:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f185594:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f185598:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18559c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1855a0:	166f000a */ 	bne	$s3,$t7,.L0f1855cc
/*  f1855a4:	afae00b8 */ 	sw	$t6,0xb8($sp)
/*  f1855a8:	0fc66dfd */ 	jal	mpGetCurrentChallengeIndex
/*  f1855ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1855b0:	0fc66dbe */ 	jal	func0f19b6f8
/*  f1855b4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1855b8:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1855bc:	24a588d0 */ 	addiu	$a1,$a1,-30512
/*  f1855c0:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f1855c4:	0c004dad */ 	jal	sprintf
/*  f1855c8:	00403025 */ 	or	$a2,$v0,$zero
.L0f1855cc:
/*  f1855cc:	3c18800b */ 	lui	$t8,0x800b
/*  f1855d0:	9318cb98 */ 	lbu	$t8,-0x3468($t8)
/*  f1855d4:	3c048008 */ 	lui	$a0,0x8008
/*  f1855d8:	27b5007c */ 	addiu	$s5,$sp,0x7c
/*  f1855dc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1855e0:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1855e4:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f1855e8:	00992021 */ 	addu	$a0,$a0,$t9
/*  f1855ec:	0fc5b9f1 */ 	jal	textGet
/*  f1855f0:	94847148 */ 	lhu	$a0,0x7148($a0)
/*  f1855f4:	27b20040 */ 	addiu	$s2,$sp,0x40
/*  f1855f8:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1855fc:	24a588d8 */ 	addiu	$a1,$a1,-30504
/*  f185600:	02402025 */ 	or	$a0,$s2,$zero
/*  f185604:	0c004dad */ 	jal	sprintf
/*  f185608:	00403025 */ 	or	$a2,$v0,$zero
/*  f18560c:	3c03800b */ 	lui	$v1,0x800b
/*  f185610:	8c63c530 */ 	lw	$v1,-0x3ad0($v1)
/*  f185614:	3c10800b */ 	lui	$s0,%hi(g_MpPlayerChrs)
/*  f185618:	2610c4d0 */ 	addiu	$s0,$s0,%lo(g_MpPlayerChrs)
/*  f18561c:	18600018 */ 	blez	$v1,.L0f185680
/*  f185620:	00008825 */ 	or	$s1,$zero,$zero
.L0f185624:
/*  f185624:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f185628:	8d0902d4 */ 	lw	$t1,0x2d4($t0)
/*  f18562c:	55200011 */ 	bnezl	$t1,.L0f185674
/*  f185630:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f185634:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f185638:	02202025 */ 	or	$a0,$s1,$zero
/*  f18563c:	928a0060 */ 	lbu	$t2,0x60($s4)
/*  f185640:	02a02025 */ 	or	$a0,$s5,$zero
/*  f185644:	00002825 */ 	or	$a1,$zero,$zero
/*  f185648:	566a0004 */ 	bnel	$s3,$t2,.L0f18565c
/*  f18564c:	02402025 */ 	or	$a0,$s2,$zero
/*  f185650:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f185654:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f185658:	02402025 */ 	or	$a0,$s2,$zero
.L0f18565c:
/*  f18565c:	00002825 */ 	or	$a1,$zero,$zero
/*  f185660:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f185664:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f185668:	3c03800b */ 	lui	$v1,0x800b
/*  f18566c:	8c63c530 */ 	lw	$v1,-0x3ad0($v1)
/*  f185670:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f185674:
/*  f185674:	0223082a */ 	slt	$at,$s1,$v1
/*  f185678:	1420ffea */ 	bnez	$at,.L0f185624
/*  f18567c:	26100004 */ 	addiu	$s0,$s0,0x4
.L0f185680:
/*  f185680:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f185684:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*  f185688:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f18568c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f185690:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f185694:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f185698:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18569c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f1856a0:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f1856a4:	03e00008 */ 	jr	$ra
/*  f1856a8:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);

void scenarioCallback10(void)
{
	if (g_Vars.mplayerisrunning) {
		if (g_Vars.lvframenum == 5) {
			func0f185568();
		}

		if (g_MpScenarios[g_MpSetup.scenario].unk10) {
			g_MpScenarios[g_MpSetup.scenario].unk10();
		}
	}
}

void scenarioCallback14(struct chrdata *chr)
{
	if (g_Vars.mplayerisrunning && g_MpScenarios[g_MpSetup.scenario].unk14) {
		g_MpScenarios[g_MpSetup.scenario].unk14(chr);
	}
}

GLOBAL_ASM(
glabel func0f185774
/*  f185774:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f185778:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f18577c:	8d2e0318 */ 	lw	$t6,0x318($t1)
/*  f185780:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f185784:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f185788:	11c0011d */ 	beqz	$t6,.L0f185c00
/*  f18578c:	00802825 */ 	or	$a1,$a0,$zero
/*  f185790:	3c0a800b */ 	lui	$t2,%hi(g_MpSetup)
/*  f185794:	254acb88 */ 	addiu	$t2,$t2,%lo(g_MpSetup)
/*  f185798:	914f0010 */ 	lbu	$t7,0x10($t2)
/*  f18579c:	240b0048 */ 	addiu	$t3,$zero,0x48
/*  f1857a0:	3c088008 */ 	lui	$t0,%hi(g_MpScenarios)
/*  f1857a4:	01eb0019 */ 	multu	$t7,$t3
/*  f1857a8:	25086f98 */ 	addiu	$t0,$t0,%lo(g_MpScenarios)
/*  f1857ac:	0000c012 */ 	mflo	$t8
/*  f1857b0:	0118c821 */ 	addu	$t9,$t0,$t8
/*  f1857b4:	8f2c0018 */ 	lw	$t4,0x18($t9)
/*  f1857b8:	51800041 */ 	beqzl	$t4,.L0f1858c0
/*  f1857bc:	8d2d006c */ 	lw	$t5,0x6c($t1)
/*  f1857c0:	914d001e */ 	lbu	$t5,0x1e($t2)
/*  f1857c4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1857c8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1857cc:	51a1003c */ 	beql	$t5,$at,.L0f1858c0
/*  f1857d0:	8d2d006c */ 	lw	$t5,0x6c($t1)
/*  f1857d4:	8dce4038 */ 	lw	$t6,0x4038($t6)
/*  f1857d8:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1857dc:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f1857e0:	15c00036 */ 	bnez	$t6,.L0f1858bc
/*  f1857e4:	24830008 */ 	addiu	$v1,$a0,0x8
/*  f1857e8:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1857ec:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f1857f0:	3c18ba00 */ 	lui	$t8,0xba00
/*  f1857f4:	37180602 */ 	ori	$t8,$t8,0x602
/*  f1857f8:	241900c0 */ 	addiu	$t9,$zero,0xc0
/*  f1857fc:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f185800:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f185804:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f185808:	3c0cb600 */ 	lui	$t4,0xb600
/*  f18580c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f185810:	ac8d0004 */ 	sw	$t5,0x4($a0)
/*  f185814:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f185818:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f18581c:	3c0ee700 */ 	lui	$t6,0xe700
/*  f185820:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f185824:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f185828:	3c0fba00 */ 	lui	$t7,0xba00
/*  f18582c:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f185830:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f185834:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f185838:	24e20008 */ 	addiu	$v0,$a3,0x8
/*  f18583c:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f185840:	3c18ba00 */ 	lui	$t8,0xba00
/*  f185844:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f185848:	24430008 */ 	addiu	$v1,$v0,0x8
/*  f18584c:	3c190030 */ 	lui	$t9,0x30
/*  f185850:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f185854:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f185858:	3c0cb900 */ 	lui	$t4,0xb900
/*  f18585c:	3c0d0f0a */ 	lui	$t5,0xf0a
/*  f185860:	35ad4000 */ 	ori	$t5,$t5,0x4000
/*  f185864:	358c031d */ 	ori	$t4,$t4,0x31d
/*  f185868:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f18586c:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f185870:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f185874:	3c0eba00 */ 	lui	$t6,0xba00
/*  f185878:	35ce1701 */ 	ori	$t6,$t6,0x1701
/*  f18587c:	3c0f0080 */ 	lui	$t7,0x80
/*  f185880:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f185884:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f185888:	91580010 */ 	lbu	$t8,0x10($t2)
/*  f18588c:	24c40008 */ 	addiu	$a0,$a2,0x8
/*  f185890:	030b0019 */ 	multu	$t8,$t3
/*  f185894:	0000c812 */ 	mflo	$t9
/*  f185898:	01196021 */ 	addu	$t4,$t0,$t9
/*  f18589c:	8d990018 */ 	lw	$t9,0x18($t4)
/*  f1858a0:	0320f809 */ 	jalr	$t9
/*  f1858a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1858a8:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f1858ac:	3c0a800b */ 	lui	$t2,%hi(g_MpSetup)
/*  f1858b0:	254acb88 */ 	addiu	$t2,$t2,%lo(g_MpSetup)
/*  f1858b4:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f1858b8:	00402825 */ 	or	$a1,$v0,$zero
.L0f1858bc:
/*  f1858bc:	8d2d006c */ 	lw	$t5,0x6c($t1)
.L0f1858c0:
/*  f1858c0:	00004025 */ 	or	$t0,$zero,$zero
/*  f1858c4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1858c8:	11a00003 */ 	beqz	$t5,.L0f1858d8
/*  f1858cc:	00003825 */ 	or	$a3,$zero,$zero
/*  f1858d0:	10000001 */ 	beqz	$zero,.L0f1858d8
/*  f1858d4:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f1858d8:
/*  f1858d8:	8d2e0068 */ 	lw	$t6,0x68($t1)
/*  f1858dc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1858e0:	11c00003 */ 	beqz	$t6,.L0f1858f0
/*  f1858e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1858e8:	10000001 */ 	beqz	$zero,.L0f1858f0
/*  f1858ec:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1858f0:
/*  f1858f0:	8d2f0064 */ 	lw	$t7,0x64($t1)
/*  f1858f4:	11e00003 */ 	beqz	$t7,.L0f185904
/*  f1858f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1858fc:	10000001 */ 	beqz	$zero,.L0f185904
/*  f185900:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f185904:
/*  f185904:	8d380070 */ 	lw	$t8,0x70($t1)
/*  f185908:	13000003 */ 	beqz	$t8,.L0f185918
/*  f18590c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185910:	10000001 */ 	beqz	$zero,.L0f185918
/*  f185914:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f185918:
/*  f185918:	8d44000c */ 	lw	$a0,0xc($t2)
/*  f18591c:	00476021 */ 	addu	$t4,$v0,$a3
/*  f185920:	0186c821 */ 	addu	$t9,$t4,$a2
/*  f185924:	03281821 */ 	addu	$v1,$t9,$t0
/*  f185928:	308d0002 */ 	andi	$t5,$a0,0x2
/*  f18592c:	11a000b4 */ 	beqz	$t5,.L0f185c00
/*  f185930:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f185934:	308e0200 */ 	andi	$t6,$a0,0x200
/*  f185938:	11c000b1 */ 	beqz	$t6,.L0f185c00
/*  f18593c:	28610002 */ 	slti	$at,$v1,0x2
/*  f185940:	142000af */ 	bnez	$at,.L0f185c00
/*  f185944:	00a01025 */ 	or	$v0,$a1,$zero
/*  f185948:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f18594c:	8d2c028c */ 	lw	$t4,0x28c($t1)
/*  f185950:	3c19ba00 */ 	lui	$t9,0xba00
/*  f185954:	8df800bc */ 	lw	$t8,0xbc($t7)
/*  f185958:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f18595c:	24a30008 */ 	addiu	$v1,$a1,0x8
/*  f185960:	8f080004 */ 	lw	$t0,0x4($t8)
/*  f185964:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f185968:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f18596c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f185970:	3c0dba00 */ 	lui	$t5,0xba00
/*  f185974:	35ad0602 */ 	ori	$t5,$t5,0x602
/*  f185978:	240e00c0 */ 	addiu	$t6,$zero,0xc0
/*  f18597c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f185980:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f185984:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f185988:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f18598c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f185990:	3c0fb600 */ 	lui	$t7,0xb600
/*  f185994:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f185998:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f18599c:	3c0ce700 */ 	lui	$t4,0xe700
/*  f1859a0:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f1859a4:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1859a8:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f1859ac:	3c19ba00 */ 	lui	$t9,0xba00
/*  f1859b0:	37391301 */ 	ori	$t9,$t9,0x1301
/*  f1859b4:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f1859b8:	24e20008 */ 	addiu	$v0,$a3,0x8
/*  f1859bc:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f1859c0:	3c0dba00 */ 	lui	$t5,0xba00
/*  f1859c4:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*  f1859c8:	24430008 */ 	addiu	$v1,$v0,0x8
/*  f1859cc:	3c0e0030 */ 	lui	$t6,0x30
/*  f1859d0:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f1859d4:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f1859d8:	3c180f0a */ 	lui	$t8,0xf0a
/*  f1859dc:	3c0fb900 */ 	lui	$t7,0xb900
/*  f1859e0:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f1859e4:	37184000 */ 	ori	$t8,$t8,0x4000
/*  f1859e8:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1859ec:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f1859f0:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f1859f4:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1859f8:	358c1701 */ 	ori	$t4,$t4,0x1701
/*  f1859fc:	3c190080 */ 	lui	$t9,0x80
/*  f185a00:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f185a04:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f185a08:	24c50008 */ 	addiu	$a1,$a2,0x8
/*  f185a0c:	91040125 */ 	lbu	$a0,0x125($t0)
/*  f185a10:	0fc63a5a */ 	jal	teamGetIndex
/*  f185a14:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f185a18:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f185a1c:	00026880 */ 	sll	$t5,$v0,0x2
/*  f185a20:	3c048008 */ 	lui	$a0,0x8008
/*  f185a24:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f185a28:	8c847ce4 */ 	lw	$a0,0x7ce4($a0)
/*  f185a2c:	3c0ef700 */ 	lui	$t6,0xf700
/*  f185a30:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f185a34:	24650008 */ 	addiu	$a1,$v1,0x8
/*  f185a38:	ac640004 */ 	sw	$a0,0x4($v1)
/*  f185a3c:	0c002f40 */ 	jal	func0000bd00
/*  f185a40:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f185a44:	0c002f22 */ 	jal	func0000bc88
/*  f185a48:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f185a4c:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f185a50:	00463821 */ 	addu	$a3,$v0,$a2
/*  f185a54:	0c002f44 */ 	jal	func0000bd10
/*  f185a58:	afa70028 */ 	sw	$a3,0x28($sp)
/*  f185a5c:	0c002f26 */ 	jal	func0000bc98
/*  f185a60:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f185a64:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f185a68:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f185a6c:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f185a70:	29e10003 */ 	slti	$at,$t7,0x3
/*  f185a74:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f185a78:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f185a7c:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f185a80:	14200027 */ 	bnez	$at,.L0f185b20
/*  f185a84:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f185a88:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f185a8c:	310303ff */ 	andi	$v1,$t0,0x3ff
/*  f185a90:	00037880 */ 	sll	$t7,$v1,0x2
/*  f185a94:	2b010002 */ 	slti	$at,$t8,0x2
/*  f185a98:	10200013 */ 	beqz	$at,.L0f185ae8
/*  f185a9c:	01e01825 */ 	or	$v1,$t7,$zero
/*  f185aa0:	00482021 */ 	addu	$a0,$v0,$t0
/*  f185aa4:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f185aa8:	24edffff */ 	addiu	$t5,$a3,-1
/*  f185aac:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f185ab0:	308c03ff */ 	andi	$t4,$a0,0x3ff
/*  f185ab4:	000c2080 */ 	sll	$a0,$t4,0x2
/*  f185ab8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f185abc:	3c01f600 */ 	lui	$at,0xf600
/*  f185ac0:	30d903ff */ 	andi	$t9,$a2,0x3ff
/*  f185ac4:	00196b80 */ 	sll	$t5,$t9,0xe
/*  f185ac8:	01e1c025 */ 	or	$t8,$t7,$at
/*  f185acc:	00a01825 */ 	or	$v1,$a1,$zero
/*  f185ad0:	03046025 */ 	or	$t4,$t8,$a0
/*  f185ad4:	01a47025 */ 	or	$t6,$t5,$a0
/*  f185ad8:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f185adc:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f185ae0:	10000047 */ 	beqz	$zero,.L0f185c00
/*  f185ae4:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f185ae8:
/*  f185ae8:	24f8ffff */ 	addiu	$t8,$a3,-1
/*  f185aec:	330c03ff */ 	andi	$t4,$t8,0x3ff
/*  f185af0:	000ccb80 */ 	sll	$t9,$t4,0xe
/*  f185af4:	3c01f600 */ 	lui	$at,0xf600
/*  f185af8:	03216825 */ 	or	$t5,$t9,$at
/*  f185afc:	01af7025 */ 	or	$t6,$t5,$t7
/*  f185b00:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f185b04:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f185b08:	00a01025 */ 	or	$v0,$a1,$zero
/*  f185b0c:	03036025 */ 	or	$t4,$t8,$v1
/*  f185b10:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f185b14:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f185b18:	10000039 */ 	beqz	$zero,.L0f185c00
/*  f185b1c:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f185b20:
/*  f185b20:	913904e0 */ 	lbu	$t9,0x4e0($t1)
/*  f185b24:	00a01825 */ 	or	$v1,$a1,$zero
/*  f185b28:	00482021 */ 	addu	$a0,$v0,$t0
/*  f185b2c:	13200011 */ 	beqz	$t9,.L0f185b74
/*  f185b30:	8fac001c */ 	lw	$t4,0x1c($sp)
/*  f185b34:	2484fffe */ 	addiu	$a0,$a0,-2
/*  f185b38:	24efffff */ 	addiu	$t7,$a3,-1
/*  f185b3c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f185b40:	308d03ff */ 	andi	$t5,$a0,0x3ff
/*  f185b44:	000d2080 */ 	sll	$a0,$t5,0x2
/*  f185b48:	00186380 */ 	sll	$t4,$t8,0xe
/*  f185b4c:	3c01f600 */ 	lui	$at,0xf600
/*  f185b50:	30ce03ff */ 	andi	$t6,$a2,0x3ff
/*  f185b54:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f185b58:	0181c825 */ 	or	$t9,$t4,$at
/*  f185b5c:	03246825 */ 	or	$t5,$t9,$a0
/*  f185b60:	01e4c025 */ 	or	$t8,$t7,$a0
/*  f185b64:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f185b68:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f185b6c:	10000024 */ 	beqz	$zero,.L0f185c00
/*  f185b70:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f185b74:
/*  f185b74:	15800013 */ 	bnez	$t4,.L0f185bc4
/*  f185b78:	310303ff */ 	andi	$v1,$t0,0x3ff
/*  f185b7c:	00482021 */ 	addu	$a0,$v0,$t0
/*  f185b80:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f185b84:	24eeffff */ 	addiu	$t6,$a3,-1
/*  f185b88:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f185b8c:	309903ff */ 	andi	$t9,$a0,0x3ff
/*  f185b90:	00192080 */ 	sll	$a0,$t9,0x2
/*  f185b94:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f185b98:	3c01f600 */ 	lui	$at,0xf600
/*  f185b9c:	30cd03ff */ 	andi	$t5,$a2,0x3ff
/*  f185ba0:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f185ba4:	03016025 */ 	or	$t4,$t8,$at
/*  f185ba8:	00a01825 */ 	or	$v1,$a1,$zero
/*  f185bac:	0184c825 */ 	or	$t9,$t4,$a0
/*  f185bb0:	01c47825 */ 	or	$t7,$t6,$a0
/*  f185bb4:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f185bb8:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f185bbc:	10000010 */ 	beqz	$zero,.L0f185c00
/*  f185bc0:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f185bc4:
/*  f185bc4:	24ecffff */ 	addiu	$t4,$a3,-1
/*  f185bc8:	319903ff */ 	andi	$t9,$t4,0x3ff
/*  f185bcc:	00196b80 */ 	sll	$t5,$t9,0xe
/*  f185bd0:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f185bd4:	3c01f600 */ 	lui	$at,0xf600
/*  f185bd8:	01a17025 */ 	or	$t6,$t5,$at
/*  f185bdc:	01d87825 */ 	or	$t7,$t6,$t8
/*  f185be0:	03001825 */ 	or	$v1,$t8,$zero
/*  f185be4:	30d803ff */ 	andi	$t8,$a2,0x3ff
/*  f185be8:	00a01025 */ 	or	$v0,$a1,$zero
/*  f185bec:	00186380 */ 	sll	$t4,$t8,0xe
/*  f185bf0:	0183c825 */ 	or	$t9,$t4,$v1
/*  f185bf4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f185bf8:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f185bfc:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f185c00:
/*  f185c00:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f185c04:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f185c08:	00a01025 */ 	or	$v0,$a1,$zero
/*  f185c0c:	03e00008 */ 	jr	$ra
/*  f185c10:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f185c14
/*  f185c14:	3c0b800b */ 	lui	$t3,%hi(g_MpSetup)
/*  f185c18:	256bcb88 */ 	addiu	$t3,$t3,%lo(g_MpSetup)
/*  f185c1c:	916e0010 */ 	lbu	$t6,0x10($t3)
/*  f185c20:	3c028008 */ 	lui	$v0,0x8008
/*  f185c24:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f185c28:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f185c2c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f185c30:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f185c34:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f185c38:	8c426fb4 */ 	lw	$v0,0x6fb4($v0)
/*  f185c3c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f185c40:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f185c44:	00808025 */ 	or	$s0,$a0,$zero
/*  f185c48:	00a08825 */ 	or	$s1,$a1,$zero
/*  f185c4c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f185c50:	10400005 */ 	beqz	$v0,.L0f185c68
/*  f185c54:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f185c58:	0040f809 */ 	jalr	$v0
/*  f185c5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185c60:	1000003b */ 	beqz	$zero,.L0f185d50
/*  f185c64:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f185c68:
/*  f185c68:	3c09800b */ 	lui	$t1,%hi(g_MpSimulants)
/*  f185c6c:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f185c70:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f185c74:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f185c78:	2529c538 */ 	addiu	$t1,$t1,%lo(g_MpSimulants)
/*  f185c7c:	00001025 */ 	or	$v0,$zero,$zero
/*  f185c80:	02001825 */ 	or	$v1,$s0,$zero
/*  f185c84:	240a004c */ 	addiu	$t2,$zero,0x4c
/*  f185c88:	240800a0 */ 	addiu	$t0,$zero,0xa0
/*  f185c8c:	2405000c */ 	addiu	$a1,$zero,0xc
.L0f185c90:
/*  f185c90:	54510007 */ 	bnel	$v0,$s1,.L0f185cb0
/*  f185c94:	8d6d000c */ 	lw	$t5,0xc($t3)
/*  f185c98:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f185c9c:	84790024 */ 	lh	$t9,0x24($v1)
/*  f185ca0:	03196023 */ 	subu	$t4,$t8,$t9
/*  f185ca4:	10000023 */ 	beqz	$zero,.L0f185d34
/*  f185ca8:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f185cac:	8d6d000c */ 	lw	$t5,0xc($t3)
.L0f185cb0:
/*  f185cb0:	28410004 */ 	slti	$at,$v0,0x4
/*  f185cb4:	31ae0002 */ 	andi	$t6,$t5,0x2
/*  f185cb8:	51c0001b */ 	beqzl	$t6,.L0f185d28
/*  f185cbc:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f185cc0:	10200006 */ 	beqz	$at,.L0f185cdc
/*  f185cc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185cc8:	00480019 */ 	multu	$v0,$t0
/*  f185ccc:	00007812 */ 	mflo	$t7
/*  f185cd0:	00ef2021 */ 	addu	$a0,$a3,$t7
/*  f185cd4:	10000006 */ 	beqz	$zero,.L0f185cf0
/*  f185cd8:	92190011 */ 	lbu	$t9,0x11($s0)
.L0f185cdc:
/*  f185cdc:	004a0019 */ 	multu	$v0,$t2
/*  f185ce0:	0000c012 */ 	mflo	$t8
/*  f185ce4:	01382021 */ 	addu	$a0,$t1,$t8
/*  f185ce8:	2484fed0 */ 	addiu	$a0,$a0,-304
/*  f185cec:	92190011 */ 	lbu	$t9,0x11($s0)
.L0f185cf0:
/*  f185cf0:	908c0011 */ 	lbu	$t4,0x11($a0)
/*  f185cf4:	572c0007 */ 	bnel	$t9,$t4,.L0f185d14
/*  f185cf8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f185cfc:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f185d00:	846e0024 */ 	lh	$t6,0x24($v1)
/*  f185d04:	01ae7823 */ 	subu	$t7,$t5,$t6
/*  f185d08:	1000000a */ 	beqz	$zero,.L0f185d34
/*  f185d0c:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f185d10:	8cd80000 */ 	lw	$t8,0x0($a2)
.L0f185d14:
/*  f185d14:	84790024 */ 	lh	$t9,0x24($v1)
/*  f185d18:	03196021 */ 	addu	$t4,$t8,$t9
/*  f185d1c:	10000005 */ 	beqz	$zero,.L0f185d34
/*  f185d20:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f185d24:	8ccd0000 */ 	lw	$t5,0x0($a2)
.L0f185d28:
/*  f185d28:	846e0024 */ 	lh	$t6,0x24($v1)
/*  f185d2c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f185d30:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f185d34:
/*  f185d34:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f185d38:	1445ffd5 */ 	bne	$v0,$a1,.L0f185c90
/*  f185d3c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f185d40:	8618003c */ 	lh	$t8,0x3c($s0)
/*  f185d44:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*  f185d48:	af380000 */ 	sw	$t8,0x0($t9)
/*  f185d4c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f185d50:
/*  f185d50:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f185d54:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f185d58:	03e00008 */ 	jr	$ra
/*  f185d5c:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

s32 scenarioRadar(s32 value)
{
	if (g_Vars.mplayerisrunning && g_MpScenarios[g_MpSetup.scenario].radarfunc) {
		return g_MpScenarios[g_MpSetup.scenario].radarfunc(value);
	}

	return value;
}

bool scenarioRadar2(s32 *displaylist, struct prop *prop)
{
	if (g_Vars.mplayerisrunning && g_MpScenarios[g_MpSetup.scenario].radar2func) {
		return g_MpScenarios[g_MpSetup.scenario].radar2func(displaylist, prop);
	}

	return false;
}

GLOBAL_ASM(
glabel func0f185e20
/*  f185e20:	3c07800b */ 	lui	$a3,%hi(g_MpSetup)
/*  f185e24:	24e7cb88 */ 	addiu	$a3,$a3,%lo(g_MpSetup)
/*  f185e28:	90ee0010 */ 	lbu	$t6,0x10($a3)
/*  f185e2c:	3c028008 */ 	lui	$v0,0x8008
/*  f185e30:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f185e34:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f185e38:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f185e3c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f185e40:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f185e44:	8c426fc0 */ 	lw	$v0,0x6fc0($v0)
/*  f185e48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f185e4c:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f185e50:	5040000a */ 	beqzl	$v0,.L0f185e7c
/*  f185e54:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f185e58:	0040f809 */ 	jalr	$v0
/*  f185e5c:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f185e60:	3c07800b */ 	lui	$a3,%hi(g_MpSetup)
/*  f185e64:	24e7cb88 */ 	addiu	$a3,$a3,%lo(g_MpSetup)
/*  f185e68:	10400003 */ 	beqz	$v0,.L0f185e78
/*  f185e6c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f185e70:	100000be */ 	beqz	$zero,.L0f18616c
/*  f185e74:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f185e78:
/*  f185e78:	8fb80030 */ 	lw	$t8,0x30($sp)
.L0f185e7c:
/*  f185e7c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f185e80:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f185e84:	10410005 */ 	beq	$v0,$at,.L0f185e9c
/*  f185e88:	24010002 */ 	addiu	$at,$zero,0x2
/*  f185e8c:	10410003 */ 	beq	$v0,$at,.L0f185e9c
/*  f185e90:	24010004 */ 	addiu	$at,$zero,0x4
/*  f185e94:	54410032 */ 	bnel	$v0,$at,.L0f185f60
/*  f185e98:	24010003 */ 	addiu	$at,$zero,0x3
.L0f185e9c:
/*  f185e9c:	90e90010 */ 	lbu	$t1,0x10($a3)
/*  f185ea0:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f185ea4:	3c0c800a */ 	lui	$t4,0x800a
/*  f185ea8:	15200005 */ 	bnez	$t1,.L0f185ec0
/*  f185eac:	8f220004 */ 	lw	$v0,0x4($t9)
/*  f185eb0:	8cea000c */ 	lw	$t2,0xc($a3)
/*  f185eb4:	314b0020 */ 	andi	$t3,$t2,0x20
/*  f185eb8:	556000ac */ 	bnezl	$t3,.L0f18616c
/*  f185ebc:	00001025 */ 	or	$v0,$zero,$zero
.L0f185ec0:
/*  f185ec0:	8d8ca248 */ 	lw	$t4,-0x5db8($t4)
/*  f185ec4:	3c0f800b */ 	lui	$t7,0x800b
/*  f185ec8:	8d8d0070 */ 	lw	$t5,0x70($t4)
/*  f185ecc:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f185ed0:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f185ed4:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f185ed8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f185edc:	8defc7cc */ 	lw	$t7,-0x3834($t7)
/*  f185ee0:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f185ee4:	530000a1 */ 	beqzl	$t8,.L0f18616c
/*  f185ee8:	00001025 */ 	or	$v0,$zero,$zero
/*  f185eec:	90590003 */ 	lbu	$t9,0x3($v0)
/*  f185ef0:	2729fff9 */ 	addiu	$t1,$t9,-7
/*  f185ef4:	2d21000f */ 	sltiu	$at,$t1,0xf
/*  f185ef8:	1020009b */ 	beqz	$at,.L0f186168
/*  f185efc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f185f00:	3c017f1c */ 	lui	$at,%hi(var7f1b8980)
/*  f185f04:	00290821 */ 	addu	$at,$at,$t1
/*  f185f08:	8c298980 */ 	lw	$t1,%lo(var7f1b8980)($at)
/*  f185f0c:	01200008 */ 	jr	$t1
/*  f185f10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185f14:	240a00cd */ 	addiu	$t2,$zero,0xcd
/*  f185f18:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f185f1c:	3c0141a0 */ 	lui	$at,0x41a0
/*  f185f20:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f185f24:	acaa0004 */ 	sw	$t2,0x4($a1)
/*  f185f28:	acab0008 */ 	sw	$t3,0x8($a1)
/*  f185f2c:	44816000 */ 	mtc1	$at,$f12
/*  f185f30:	0fc01ac2 */ 	jal	func0f006b08
/*  f185f34:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f185f38:	3c01437f */ 	lui	$at,0x437f
/*  f185f3c:	44812000 */ 	mtc1	$at,$f4
/*  f185f40:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f185f44:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f185f48:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f185f4c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f185f50:	440d4000 */ 	mfc1	$t5,$f8
/*  f185f54:	10000085 */ 	beqz	$zero,.L0f18616c
/*  f185f58:	acad000c */ 	sw	$t5,0xc($a1)
/*  f185f5c:	24010003 */ 	addiu	$at,$zero,0x3
.L0f185f60:
/*  f185f60:	10410004 */ 	beq	$v0,$at,.L0f185f74
/*  f185f64:	00003025 */ 	or	$a2,$zero,$zero
/*  f185f68:	24010006 */ 	addiu	$at,$zero,0x6
/*  f185f6c:	5441007f */ 	bnel	$v0,$at,.L0f18616c
/*  f185f70:	00001025 */ 	or	$v0,$zero,$zero
.L0f185f74:
/*  f185f74:	8cee000c */ 	lw	$t6,0xc($a3)
/*  f185f78:	00001825 */ 	or	$v1,$zero,$zero
/*  f185f7c:	00004025 */ 	or	$t0,$zero,$zero
/*  f185f80:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f185f84:	11e00017 */ 	beqz	$t7,.L0f185fe4
/*  f185f88:	00002025 */ 	or	$a0,$zero,$zero
/*  f185f8c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f185f90:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f185f94:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f185f98:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f185f9c:	0fc3f594 */ 	jal	currentPlayerIsInTraining
/*  f185fa0:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f185fa4:	3c07800b */ 	lui	$a3,%hi(g_MpSetup)
/*  f185fa8:	24e7cb88 */ 	addiu	$a3,$a3,%lo(g_MpSetup)
/*  f185fac:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f185fb0:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f185fb4:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f185fb8:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f185fbc:	10400009 */ 	beqz	$v0,.L0f185fe4
/*  f185fc0:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f185fc4:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f185fc8:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f185fcc:	54590005 */ 	bnel	$v0,$t9,.L0f185fe4
/*  f185fd0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f185fd4:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f185fd8:	10000002 */ 	beqz	$zero,.L0f185fe4
/*  f185fdc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f185fe0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f185fe4:
/*  f185fe4:	14c00025 */ 	bnez	$a2,.L0f18607c
/*  f185fe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185fec:	14600023 */ 	bnez	$v1,.L0f18607c
/*  f185ff0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185ff4:	90e90010 */ 	lbu	$t1,0x10($a3)
/*  f185ff8:	8ce2000c */ 	lw	$v0,0xc($a3)
/*  f185ffc:	15200002 */ 	bnez	$t1,.L0f186008
/*  f186000:	304a0010 */ 	andi	$t2,$v0,0x10
/*  f186004:	1540001d */ 	bnez	$t2,.L0f18607c
.L0f186008:
/*  f186008:	304b0002 */ 	andi	$t3,$v0,0x2
/*  f18600c:	1160000e */ 	beqz	$t3,.L0f186048
/*  f186010:	3c0c800a */ 	lui	$t4,0x800a
/*  f186014:	8d8ca248 */ 	lw	$t4,-0x5db8($t4)
/*  f186018:	3c0f800b */ 	lui	$t7,0x800b
/*  f18601c:	8d8d0070 */ 	lw	$t5,0x70($t4)
/*  f186020:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f186024:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f186028:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18602c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f186030:	8defc7cc */ 	lw	$t7,-0x3834($t7)
/*  f186034:	31f80008 */ 	andi	$t8,$t7,0x8
/*  f186038:	13000003 */ 	beqz	$t8,.L0f186048
/*  f18603c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186040:	1000000e */ 	beqz	$zero,.L0f18607c
/*  f186044:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186048:
/*  f186048:	3c19800a */ 	lui	$t9,0x800a
/*  f18604c:	8f39a248 */ 	lw	$t9,-0x5db8($t9)
/*  f186050:	3c0b800b */ 	lui	$t3,0x800b
/*  f186054:	8f290070 */ 	lw	$t1,0x70($t9)
/*  f186058:	00095080 */ 	sll	$t2,$t1,0x2
/*  f18605c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f186060:	000a5140 */ 	sll	$t2,$t2,0x5
/*  f186064:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f186068:	8d6bc7cc */ 	lw	$t3,-0x3834($t3)
/*  f18606c:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f186070:	11800002 */ 	beqz	$t4,.L0f18607c
/*  f186074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186078:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f18607c:
/*  f18607c:	10800027 */ 	beqz	$a0,.L0f18611c
/*  f186080:	8fad0030 */ 	lw	$t5,0x30($sp)
/*  f186084:	8dae0004 */ 	lw	$t6,0x4($t5)
/*  f186088:	91c40125 */ 	lbu	$a0,0x125($t6)
/*  f18608c:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f186090:	0fc63a5a */ 	jal	teamGetIndex
/*  f186094:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f186098:	00027880 */ 	sll	$t7,$v0,0x2
/*  f18609c:	3c038008 */ 	lui	$v1,0x8008
/*  f1860a0:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f1860a4:	8c637cc4 */ 	lw	$v1,0x7cc4($v1)
/*  f1860a8:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f1860ac:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f1860b0:	0003c602 */ 	srl	$t8,$v1,0x18
/*  f1860b4:	00034c02 */ 	srl	$t1,$v1,0x10
/*  f1860b8:	00035a02 */ 	srl	$t3,$v1,0x8
/*  f1860bc:	331900ff */ 	andi	$t9,$t8,0xff
/*  f1860c0:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f1860c4:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f1860c8:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f1860cc:	acaa0004 */ 	sw	$t2,0x4($a1)
/*  f1860d0:	10c0000e */ 	beqz	$a2,.L0f18610c
/*  f1860d4:	acac0008 */ 	sw	$t4,0x8($a1)
/*  f1860d8:	3c0141a0 */ 	lui	$at,0x41a0
/*  f1860dc:	44816000 */ 	mtc1	$at,$f12
/*  f1860e0:	0fc01ac2 */ 	jal	func0f006b08
/*  f1860e4:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f1860e8:	3c014300 */ 	lui	$at,0x4300
/*  f1860ec:	44815000 */ 	mtc1	$at,$f10
/*  f1860f0:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f1860f4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1860f8:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f1860fc:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f186100:	440e9000 */ 	mfc1	$t6,$f18
/*  f186104:	10000019 */ 	beqz	$zero,.L0f18616c
/*  f186108:	acae000c */ 	sw	$t6,0xc($a1)
.L0f18610c:
/*  f18610c:	240f004b */ 	addiu	$t7,$zero,0x4b
/*  f186110:	acaf000c */ 	sw	$t7,0xc($a1)
/*  f186114:	10000015 */ 	beqz	$zero,.L0f18616c
/*  f186118:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18611c:
/*  f18611c:	11000012 */ 	beqz	$t0,.L0f186168
/*  f186120:	241800cd */ 	addiu	$t8,$zero,0xcd
/*  f186124:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f186128:	3c0141a0 */ 	lui	$at,0x41a0
/*  f18612c:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f186130:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f186134:	acb90008 */ 	sw	$t9,0x8($a1)
/*  f186138:	44816000 */ 	mtc1	$at,$f12
/*  f18613c:	0fc01ac2 */ 	jal	func0f006b08
/*  f186140:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f186144:	3c01434d */ 	lui	$at,0x434d
/*  f186148:	44812000 */ 	mtc1	$at,$f4
/*  f18614c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f186150:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f186154:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f186158:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f18615c:	440a4000 */ 	mfc1	$t2,$f8
/*  f186160:	10000002 */ 	beqz	$zero,.L0f18616c
/*  f186164:	acaa000c */ 	sw	$t2,0xc($a1)
.L0f186168:
/*  f186168:	00001025 */ 	or	$v0,$zero,$zero
.L0f18616c:
/*  f18616c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f186170:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f186174:	03e00008 */ 	jr	$ra
/*  f186178:	00000000 */ 	sll	$zero,$zero,0x0
);

f32 scenarioCallback2c(f32 arg0, s32 arg1, s32 arg2, struct prop *prop)
{
	f32 result;

	if (g_Vars.mplayerisrunning && g_MpScenarios[g_MpSetup.scenario].unk2c &&
			g_MpScenarios[g_MpSetup.scenario].unk2c(arg0, arg1, arg2, prop, &result)) {
		return result;
	}

	return func0f0b72a8(arg0, arg1, arg2, prop);
}

GLOBAL_ASM(
glabel func0f18620c
/*  f18620c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f186210:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f186214:	3c11800b */ 	lui	$s1,%hi(g_MpSetup)
/*  f186218:	2631cb88 */ 	addiu	$s1,$s1,%lo(g_MpSetup)
/*  f18621c:	922e0010 */ 	lbu	$t6,0x10($s1)
/*  f186220:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f186224:	3c10800a */ 	lui	$s0,%hi(var800a000c)
/*  f186228:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f18622c:	2de10005 */ 	sltiu	$at,$t7,0x5
/*  f186230:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f186234:	1020002d */ 	beqz	$at,.L0f1862ec
/*  f186238:	8e10d03c */ 	lw	$s0,-0x2fc4($s0)
/*  f18623c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f186240:	3c017f1c */ 	lui	$at,%hi(var7f1b89bc)
/*  f186244:	002f0821 */ 	addu	$at,$at,$t7
/*  f186248:	8c2f89bc */ 	lw	$t7,%lo(var7f1b89bc)($at)
/*  f18624c:	01e00008 */ 	jr	$t7
/*  f186250:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186254:	3c01800b */ 	lui	$at,0x800b
/*  f186258:	10000024 */ 	beqz	$zero,.L0f1862ec
/*  f18625c:	a420c11c */ 	sh	$zero,-0x3ee4($at)
/*  f186260:	3c18800b */ 	lui	$t8,0x800b
/*  f186264:	2707c110 */ 	addiu	$a3,$t8,-16112
/*  f186268:	3c08800b */ 	lui	$t0,0x800b
/*  f18626c:	2508c150 */ 	addiu	$t0,$t0,-16048
/*  f186270:	00e03025 */ 	or	$a2,$a3,$zero
/*  f186274:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f186278:	24040006 */ 	addiu	$a0,$zero,0x6
.L0f18627c:
/*  f18627c:	a4c50018 */ 	sh	$a1,0x18($a2)
/*  f186280:	a4c0001a */ 	sh	$zero,0x1a($a2)
/*  f186284:	00001025 */ 	or	$v0,$zero,$zero
/*  f186288:	00e01825 */ 	or	$v1,$a3,$zero
.L0f18628c:
/*  f18628c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f186290:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f186294:	1444fffd */ 	bne	$v0,$a0,.L0f18628c
/*  f186298:	a465001a */ 	sh	$a1,0x1a($v1)
/*  f18629c:	24e70010 */ 	addiu	$a3,$a3,0x10
/*  f1862a0:	00e8082b */ 	sltu	$at,$a3,$t0
/*  f1862a4:	1420fff5 */ 	bnez	$at,.L0f18627c
/*  f1862a8:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f1862ac:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f1862b0:	3c03800b */ 	lui	$v1,0x800b
/*  f1862b4:	2463c118 */ 	addiu	$v1,$v1,-16104
/*  f1862b8:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
.L0f1862bc:
/*  f1862bc:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f1862c0:	a440fffe */ 	sh	$zero,-0x2($v0)
/*  f1862c4:	1443fffd */ 	bne	$v0,$v1,.L0f1862bc
/*  f1862c8:	a4450006 */ 	sh	$a1,0x6($v0)
/*  f1862cc:	10000007 */ 	beqz	$zero,.L0f1862ec
/*  f1862d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1862d4:	0fc60afd */ 	jal	func0f182bf4
/*  f1862d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1862dc:	10000003 */ 	beqz	$zero,.L0f1862ec
/*  f1862e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1862e4:	0fc6001e */ 	jal	func0f180078
/*  f1862e8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1862ec:
/*  f1862ec:	52000042 */ 	beqzl	$s0,.L0f1863f8
/*  f1862f0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1862f4:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f1862f8:	2401000c */ 	addiu	$at,$zero,0xc
/*  f1862fc:	1041003d */ 	beq	$v0,$at,.L0f1863f4
/*  f186300:	2c41000c */ 	sltiu	$at,$v0,0xc
.L0f186304:
/*  f186304:	10200036 */ 	beqz	$at,.L0f1863e0
/*  f186308:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f18630c:	3c017f1c */ 	lui	$at,%hi(var7f1b89d0)
/*  f186310:	00390821 */ 	addu	$at,$at,$t9
/*  f186314:	8c3989d0 */ 	lw	$t9,%lo(var7f1b89d0)($at)
/*  f186318:	03200008 */ 	jr	$t9
/*  f18631c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186320:	10000030 */ 	beqz	$zero,.L0f1863e4
/*  f186324:	2610000c */ 	addiu	$s0,$s0,%lo(var800a000c)
/*  f186328:	92220010 */ 	lbu	$v0,0x10($s1)
/*  f18632c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f186330:	54410006 */ 	bnel	$v0,$at,.L0f18634c
/*  f186334:	24010002 */ 	addiu	$at,$zero,0x2
/*  f186338:	0fc60600 */ 	jal	func0f181800
/*  f18633c:	02002025 */ 	or	$a0,$s0,$zero
/*  f186340:	10000028 */ 	beqz	$zero,.L0f1863e4
/*  f186344:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f186348:	24010002 */ 	addiu	$at,$zero,0x2
.L0f18634c:
/*  f18634c:	54410006 */ 	bnel	$v0,$at,.L0f186368
/*  f186350:	24010001 */ 	addiu	$at,$zero,0x1
/*  f186354:	0fc60ae9 */ 	jal	func0f182ba4
/*  f186358:	8604000a */ 	lh	$a0,0xa($s0)
/*  f18635c:	10000021 */ 	beqz	$zero,.L0f1863e4
/*  f186360:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f186364:	24010001 */ 	addiu	$at,$zero,0x1
.L0f186368:
/*  f186368:	14410003 */ 	bne	$v0,$at,.L0f186378
/*  f18636c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186370:	0fc5ffe3 */ 	jal	func0f17ff8c
/*  f186374:	8604000a */ 	lh	$a0,0xa($s0)
.L0f186378:
/*  f186378:	1000001a */ 	beqz	$zero,.L0f1863e4
/*  f18637c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f186380:	92290010 */ 	lbu	$t1,0x10($s1)
/*  f186384:	24010004 */ 	addiu	$at,$zero,0x4
/*  f186388:	15210003 */ 	bne	$t1,$at,.L0f186398
/*  f18638c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186390:	0fc60aab */ 	jal	func0f182aac
/*  f186394:	02002025 */ 	or	$a0,$s0,$zero
.L0f186398:
/*  f186398:	10000012 */ 	beqz	$zero,.L0f1863e4
/*  f18639c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1863a0:	10000010 */ 	beqz	$zero,.L0f1863e4
/*  f1863a4:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f1863a8:	1000000e */ 	beqz	$zero,.L0f1863e4
/*  f1863ac:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f1863b0:	1000000c */ 	beqz	$zero,.L0f1863e4
/*  f1863b4:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f1863b8:	1000000a */ 	beqz	$zero,.L0f1863e4
/*  f1863bc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1863c0:	10000008 */ 	beqz	$zero,.L0f1863e4
/*  f1863c4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1863c8:	10000006 */ 	beqz	$zero,.L0f1863e4
/*  f1863cc:	26100028 */ 	addiu	$s0,$s0,0x28
/*  f1863d0:	10000004 */ 	beqz	$zero,.L0f1863e4
/*  f1863d4:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f1863d8:	10000002 */ 	beqz	$zero,.L0f1863e4
/*  f1863dc:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f1863e0:
/*  f1863e0:	26100004 */ 	addiu	$s0,$s0,0x4
.L0f1863e4:
/*  f1863e4:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f1863e8:	2401000c */ 	addiu	$at,$zero,0xc
/*  f1863ec:	5441ffc5 */ 	bnel	$v0,$at,.L0f186304
/*  f1863f0:	2c41000c */ 	sltiu	$at,$v0,0xc
.L0f1863f4:
/*  f1863f4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f1863f8:
/*  f1863f8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1863fc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f186400:	03e00008 */ 	jr	$ra
/*  f186404:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

s32 scenarioGetMaxTeams(void)
{
	if (g_MpScenarios[g_MpSetup.scenario].maxteamsfunc) {
		return g_MpScenarios[g_MpSetup.scenario].maxteamsfunc();
	}

	return MAX_TEAMS;
}

bool scenarioIsRoomHighlighted(s16 room)
{
	if (g_MpScenarios[g_MpSetup.scenario].isroomhighlightedfunc) {
		return g_MpScenarios[g_MpSetup.scenario].isroomhighlightedfunc(room);
	}

	return false;
}

void scenarioCallback38(s16 arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
	if (g_MpScenarios[g_MpSetup.scenario].unk38) {
		g_MpScenarios[g_MpSetup.scenario].unk38(arg0, arg1, arg2, arg3);
	}
}

GLOBAL_ASM(
glabel func0f186508
/*  f186508:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f18650c:	3c0f8008 */ 	lui	$t7,%hi(var800871fc)
/*  f186510:	25ef71fc */ 	addiu	$t7,$t7,%lo(var800871fc)
/*  f186514:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f186518:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f18651c:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f186520:	afa60080 */ 	sw	$a2,0x80($sp)
/*  f186524:	afa70084 */ 	sw	$a3,0x84($sp)
/*  f186528:	25e80054 */ 	addiu	$t0,$t7,0x54
/*  f18652c:	27ae001c */ 	addiu	$t6,$sp,0x1c
.L0f186530:
/*  f186530:	8de10000 */ 	lw	$at,0x0($t7)
/*  f186534:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f186538:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f18653c:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f186540:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f186544:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f186548:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f18654c:	15e8fff8 */ 	bne	$t7,$t0,.L0f186530
/*  f186550:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f186554:	8de10000 */ 	lw	$at,0x0($t7)
/*  f186558:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f18655c:	24040060 */ 	addiu	$a0,$zero,0x60
/*  f186560:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f186564:	adc10000 */ 	sw	$at,0x0($t6)
/*  f186568:	0c0048f2 */ 	jal	func000123c8
/*  f18656c:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f186570:	27a9001c */ 	addiu	$t1,$sp,0x1c
/*  f186574:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f186578:	252c0054 */ 	addiu	$t4,$t1,0x54
/*  f18657c:	00406825 */ 	or	$t5,$v0,$zero
.L0f186580:
/*  f186580:	8d210000 */ 	lw	$at,0x0($t1)
/*  f186584:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f186588:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f18658c:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f186590:	8d21fff8 */ 	lw	$at,-0x8($t1)
/*  f186594:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f186598:	8d21fffc */ 	lw	$at,-0x4($t1)
/*  f18659c:	152cfff8 */ 	bne	$t1,$t4,.L0f186580
/*  f1865a0:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f1865a4:	8d210000 */ 	lw	$at,0x0($t1)
/*  f1865a8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f1865ac:	00402025 */ 	or	$a0,$v0,$zero
/*  f1865b0:	ada10000 */ 	sw	$at,0x0($t5)
/*  f1865b4:	8d2c0004 */ 	lw	$t4,0x4($t1)
/*  f1865b8:	3c014380 */ 	lui	$at,0x4380
/*  f1865bc:	44813000 */ 	mtc1	$at,$f6
/*  f1865c0:	adac0004 */ 	sw	$t4,0x4($t5)
/*  f1865c4:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f1865c8:	3c014f00 */ 	lui	$at,0x4f00
/*  f1865cc:	2405007b */ 	addiu	$a1,$zero,0x7b
/*  f1865d0:	a4590004 */ 	sh	$t9,0x4($v0)
/*  f1865d4:	87b8007e */ 	lh	$t8,0x7e($sp)
/*  f1865d8:	a4580006 */ 	sh	$t8,0x6($v0)
/*  f1865dc:	8fa80084 */ 	lw	$t0,0x84($sp)
/*  f1865e0:	ac480008 */ 	sw	$t0,0x8($v0)
/*  f1865e4:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f1865e8:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f1865ec:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f1865f0:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f1865f4:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f1865f8:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f1865fc:	444bf800 */ 	cfc1	$t3,$31
/*  f186600:	44caf800 */ 	ctc1	$t2,$31
/*  f186604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186608:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f18660c:	444af800 */ 	cfc1	$t2,$31
/*  f186610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186614:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f186618:	51400013 */ 	beqzl	$t2,.L0f186668
/*  f18661c:	440a5000 */ 	mfc1	$t2,$f10
/*  f186620:	44815000 */ 	mtc1	$at,$f10
/*  f186624:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f186628:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f18662c:	44caf800 */ 	ctc1	$t2,$31
/*  f186630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186634:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f186638:	444af800 */ 	cfc1	$t2,$31
/*  f18663c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186640:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f186644:	15400005 */ 	bnez	$t2,.L0f18665c
/*  f186648:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18664c:	440a5000 */ 	mfc1	$t2,$f10
/*  f186650:	3c018000 */ 	lui	$at,0x8000
/*  f186654:	10000007 */ 	beqz	$zero,.L0f186674
/*  f186658:	01415025 */ 	or	$t2,$t2,$at
.L0f18665c:
/*  f18665c:	10000005 */ 	beqz	$zero,.L0f186674
/*  f186660:	240affff */ 	addiu	$t2,$zero,-1
/*  f186664:	440a5000 */ 	mfc1	$t2,$f10
.L0f186668:
/*  f186668:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18666c:	0540fffb */ 	bltz	$t2,.L0f18665c
/*  f186670:	00000000 */ 	sll	$zero,$zero,0x0
.L0f186674:
/*  f186674:	904c0002 */ 	lbu	$t4,0x2($v0)
/*  f186678:	44cbf800 */ 	ctc1	$t3,$31
/*  f18667c:	a44a0000 */ 	sh	$t2,0x0($v0)
/*  f186680:	3189fffb */ 	andi	$t1,$t4,0xfffb
/*  f186684:	0fc033b9 */ 	jal	func0f00cee4
/*  f186688:	a0490002 */ 	sb	$t1,0x2($v0)
/*  f18668c:	8fad0018 */ 	lw	$t5,0x18($sp)
/*  f186690:	0fc1812f */ 	jal	func0f0604bc
/*  f186694:	8da40014 */ 	lw	$a0,0x14($t5)
/*  f186698:	8fb90018 */ 	lw	$t9,0x18($sp)
/*  f18669c:	0fc180bc */ 	jal	propHide
/*  f1866a0:	8f240014 */ 	lw	$a0,0x14($t9)
/*  f1866a4:	8fb80018 */ 	lw	$t8,0x18($sp)
/*  f1866a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1866ac:	8f020014 */ 	lw	$v0,0x14($t8)
/*  f1866b0:	03e00008 */ 	jr	$ra
/*  f1866b4:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f1866b8
/*  f1866b8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1866bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1866c0:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f1866c4:	0480002a */ 	bltz	$a0,.L0f186770
/*  f1866c8:	00803825 */ 	or	$a3,$a0,$zero
/*  f1866cc:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f1866d0:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f1866d4:	8cae006c */ 	lw	$t6,0x6c($a1)
/*  f1866d8:	00003025 */ 	or	$a2,$zero,$zero
/*  f1866dc:	00001825 */ 	or	$v1,$zero,$zero
/*  f1866e0:	11c00003 */ 	beqz	$t6,.L0f1866f0
/*  f1866e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1866e8:	10000001 */ 	beqz	$zero,.L0f1866f0
/*  f1866ec:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1866f0:
/*  f1866f0:	8caf0068 */ 	lw	$t7,0x68($a1)
/*  f1866f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1866f8:	11e00003 */ 	beqz	$t7,.L0f186708
/*  f1866fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186700:	10000001 */ 	beqz	$zero,.L0f186708
/*  f186704:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186708:
/*  f186708:	8cb80064 */ 	lw	$t8,0x64($a1)
/*  f18670c:	13000003 */ 	beqz	$t8,.L0f18671c
/*  f186710:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186714:	10000001 */ 	beqz	$zero,.L0f18671c
/*  f186718:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f18671c:
/*  f18671c:	8cb90070 */ 	lw	$t9,0x70($a1)
/*  f186720:	13200003 */ 	beqz	$t9,.L0f186730
/*  f186724:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186728:	10000001 */ 	beqz	$zero,.L0f186730
/*  f18672c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186730:
/*  f186730:	00444021 */ 	addu	$t0,$v0,$a0
/*  f186734:	01034821 */ 	addu	$t1,$t0,$v1
/*  f186738:	01265021 */ 	addu	$t2,$t1,$a2
/*  f18673c:	00ea082a */ 	slt	$at,$a3,$t2
/*  f186740:	5020000c */ 	beqzl	$at,.L0f186774
/*  f186744:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f186748:	8cab028c */ 	lw	$t3,0x28c($a1)
/*  f18674c:	00e02025 */ 	or	$a0,$a3,$zero
/*  f186750:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186754:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f186758:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f18675c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186760:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f186764:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186768:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f18676c:	8fa4001c */ 	lw	$a0,0x1c($sp)
.L0f186770:
/*  f186770:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f186774:
/*  f186774:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f186778:	03e00008 */ 	jr	$ra
/*  f18677c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f186780
/*  f186780:	3c0e800b */ 	lui	$t6,0x800b
/*  f186784:	8dcecb94 */ 	lw	$t6,-0x346c($t6)
/*  f186788:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18678c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f186790:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f186794:	51e0003c */ 	beqzl	$t7,.L0f186888
/*  f186798:	00001025 */ 	or	$v0,$zero,$zero
/*  f18679c:	0482003a */ 	bltzl	$a0,.L0f186888
/*  f1867a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1867a4:	04a20038 */ 	bltzl	$a1,.L0f186888
/*  f1867a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1867ac:	0fc6341d */ 	jal	func0f18d074
/*  f1867b0:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f1867b4:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f1867b8:	0fc6341d */ 	jal	func0f18d074
/*  f1867bc:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f1867c0:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f1867c4:	04620030 */ 	bltzl	$v1,.L0f186888
/*  f1867c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1867cc:	0440002d */ 	bltz	$v0,.L0f186884
/*  f1867d0:	28610004 */ 	slti	$at,$v1,0x4
/*  f1867d4:	10200008 */ 	beqz	$at,.L0f1867f8
/*  f1867d8:	00034080 */ 	sll	$t0,$v1,0x2
/*  f1867dc:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f1867e0:	0303c021 */ 	addu	$t8,$t8,$v1
/*  f1867e4:	3c19800b */ 	lui	$t9,%hi(g_MpPlayers)
/*  f1867e8:	2739c7b8 */ 	addiu	$t9,$t9,%lo(g_MpPlayers)
/*  f1867ec:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f1867f0:	10000009 */ 	beqz	$zero,.L0f186818
/*  f1867f4:	03192021 */ 	addu	$a0,$t8,$t9
.L0f1867f8:
/*  f1867f8:	01034021 */ 	addu	$t0,$t0,$v1
/*  f1867fc:	00084080 */ 	sll	$t0,$t0,0x2
/*  f186800:	01034023 */ 	subu	$t0,$t0,$v1
/*  f186804:	00084080 */ 	sll	$t0,$t0,0x2
/*  f186808:	3c0a800b */ 	lui	$t2,%hi(g_MpSimulants)
/*  f18680c:	254ac538 */ 	addiu	$t2,$t2,%lo(g_MpSimulants)
/*  f186810:	2509fed0 */ 	addiu	$t1,$t0,-304
/*  f186814:	012a2021 */ 	addu	$a0,$t1,$t2
.L0f186818:
/*  f186818:	28410004 */ 	slti	$at,$v0,0x4
/*  f18681c:	10200008 */ 	beqz	$at,.L0f186840
/*  f186820:	00026880 */ 	sll	$t5,$v0,0x2
/*  f186824:	00025880 */ 	sll	$t3,$v0,0x2
/*  f186828:	01625821 */ 	addu	$t3,$t3,$v0
/*  f18682c:	3c0c800b */ 	lui	$t4,%hi(g_MpPlayers)
/*  f186830:	258cc7b8 */ 	addiu	$t4,$t4,%lo(g_MpPlayers)
/*  f186834:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f186838:	10000009 */ 	beqz	$zero,.L0f186860
/*  f18683c:	016c1821 */ 	addu	$v1,$t3,$t4
.L0f186840:
/*  f186840:	01a26821 */ 	addu	$t5,$t5,$v0
/*  f186844:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f186848:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18684c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f186850:	3c0f800b */ 	lui	$t7,%hi(g_MpSimulants)
/*  f186854:	25efc538 */ 	addiu	$t7,$t7,%lo(g_MpSimulants)
/*  f186858:	25aefed0 */ 	addiu	$t6,$t5,-304
/*  f18685c:	01cf1821 */ 	addu	$v1,$t6,$t7
.L0f186860:
/*  f186860:	90780011 */ 	lbu	$t8,0x11($v1)
/*  f186864:	90990011 */ 	lbu	$t9,0x11($a0)
/*  f186868:	00001825 */ 	or	$v1,$zero,$zero
/*  f18686c:	17190003 */ 	bne	$t8,$t9,.L0f18687c
/*  f186870:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186874:	10000004 */ 	beqz	$zero,.L0f186888
/*  f186878:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18687c:
/*  f18687c:	10000002 */ 	beqz	$zero,.L0f186888
/*  f186880:	00601025 */ 	or	$v0,$v1,$zero
.L0f186884:
/*  f186884:	00001025 */ 	or	$v0,$zero,$zero
.L0f186888:
/*  f186888:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18688c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f186890:	03e00008 */ 	jr	$ra
/*  f186894:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f186898
/*  f186898:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f18689c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1868a0:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f1868a4:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f1868a8:	afa40128 */ 	sw	$a0,0x128($sp)
/*  f1868ac:	afa5012c */ 	sw	$a1,0x12c($sp)
/*  f1868b0:	3c03800b */ 	lui	$v1,0x800b
/*  f1868b4:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f1868b8:	9063cb98 */ 	lbu	$v1,-0x3468($v1)
/*  f1868bc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1868c0:	afa20124 */ 	sw	$v0,0x124($sp)
/*  f1868c4:	146100a5 */ 	bne	$v1,$at,.L0f186b5c
/*  f1868c8:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f1868cc:	8c98001c */ 	lw	$t8,0x1c($a0)
/*  f1868d0:	3c01800b */ 	lui	$at,0x800b
/*  f1868d4:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f1868d8:	ac38c114 */ 	sw	$t8,-0x3eec($at)
/*  f1868dc:	8c9902d4 */ 	lw	$t9,0x2d4($a0)
/*  f1868e0:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f1868e4:	53200017 */ 	beqzl	$t9,.L0f186944
/*  f1868e8:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f1868ec:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1868f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1868f4:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1868f8:	3c0b800b */ 	lui	$t3,0x800b
/*  f1868fc:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f186900:	8d6bc500 */ 	lw	$t3,-0x3b00($t3)
/*  f186904:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f186908:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f18690c:	afab0050 */ 	sw	$t3,0x50($sp)
/*  f186910:	0fc21f03 */ 	jal	func0f087c0c
/*  f186914:	9185005c */ 	lbu	$a1,0x5c($t4)
/*  f186918:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f18691c:	24050057 */ 	addiu	$a1,$zero,0x57
/*  f186920:	8c8302d4 */ 	lw	$v1,0x2d4($a0)
/*  f186924:	906e009c */ 	lbu	$t6,0x9c($v1)
/*  f186928:	35d80080 */ 	ori	$t8,$t6,0x80
/*  f18692c:	0fc65fa3 */ 	jal	func0f197e8c
/*  f186930:	a078009c */ 	sb	$t8,0x9c($v1)
/*  f186934:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f186938:	10000020 */ 	beqz	$zero,.L0f1869bc
/*  f18693c:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f186940:	8e39028c */ 	lw	$t9,0x28c($s1)
.L0f186944:
/*  f186944:	3c0c800b */ 	lui	$t4,%hi(g_MpPlayers)
/*  f186948:	258cc7b8 */ 	addiu	$t4,$t4,%lo(g_MpPlayers)
/*  f18694c:	001979c0 */ 	sll	$t7,$t9,0x7
/*  f186950:	022f5021 */ 	addu	$t2,$s1,$t7
/*  f186954:	8d4200e4 */ 	lw	$v0,0xe4($t2)
/*  f186958:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f18695c:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f186960:	28410004 */ 	slti	$at,$v0,0x4
/*  f186964:	10200007 */ 	beqz	$at,.L0f186984
/*  f186968:	00027080 */ 	sll	$t6,$v0,0x2
/*  f18696c:	00025880 */ 	sll	$t3,$v0,0x2
/*  f186970:	01625821 */ 	addu	$t3,$t3,$v0
/*  f186974:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f186978:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f18697c:	10000008 */ 	beqz	$zero,.L0f1869a0
/*  f186980:	afad0050 */ 	sw	$t5,0x50($sp)
.L0f186984:
/*  f186984:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f186988:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18698c:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f186990:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f186994:	25d8fed0 */ 	addiu	$t8,$t6,-304
/*  f186998:	03197821 */ 	addu	$t7,$t8,$t9
/*  f18699c:	afaf0050 */ 	sw	$t7,0x50($sp)
.L0f1869a0:
/*  f1869a0:	0fc44762 */ 	jal	func0f111d88
/*  f1869a4:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f1869a8:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f1869ac:	0fc221f2 */ 	jal	func0f0887c8
/*  f1869b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1869b4:	0fc21f44 */ 	jal	func0f087d10
/*  f1869b8:	24040057 */ 	addiu	$a0,$zero,0x57
.L0f1869bc:
/*  f1869bc:	0fc5b9f1 */ 	jal	textGet
/*  f1869c0:	24045400 */ 	addiu	$a0,$zero,0x5400
/*  f1869c4:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f1869c8:	0fc28874 */ 	jal	func0f0a21d0
/*  f1869cc:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f1869d0:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1869d4:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f1869d8:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f1869dc:	0c004dad */ 	jal	sprintf
/*  f1869e0:	00403825 */ 	or	$a3,$v0,$zero
/*  f1869e4:	8e29006c */ 	lw	$t1,0x6c($s1)
/*  f1869e8:	8e2a028c */ 	lw	$t2,0x28c($s1)
/*  f1869ec:	00008025 */ 	or	$s0,$zero,$zero
/*  f1869f0:	11200003 */ 	beqz	$t1,.L0f186a00
/*  f1869f4:	afaa0118 */ 	sw	$t2,0x118($sp)
/*  f1869f8:	10000002 */ 	beqz	$zero,.L0f186a04
/*  f1869fc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186a00:
/*  f186a00:	00002025 */ 	or	$a0,$zero,$zero
.L0f186a04:
/*  f186a04:	8e280068 */ 	lw	$t0,0x68($s1)
/*  f186a08:	00001825 */ 	or	$v1,$zero,$zero
/*  f186a0c:	00002825 */ 	or	$a1,$zero,$zero
/*  f186a10:	11000003 */ 	beqz	$t0,.L0f186a20
/*  f186a14:	00001025 */ 	or	$v0,$zero,$zero
/*  f186a18:	10000001 */ 	beqz	$zero,.L0f186a20
/*  f186a1c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186a20:
/*  f186a20:	8e270064 */ 	lw	$a3,0x64($s1)
/*  f186a24:	10e00003 */ 	beqz	$a3,.L0f186a34
/*  f186a28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186a2c:	10000001 */ 	beqz	$zero,.L0f186a34
/*  f186a30:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f186a34:
/*  f186a34:	8e260070 */ 	lw	$a2,0x70($s1)
/*  f186a38:	10c00003 */ 	beqz	$a2,.L0f186a48
/*  f186a3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186a40:	10000001 */ 	beqz	$zero,.L0f186a48
/*  f186a44:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186a48:
/*  f186a48:	00455821 */ 	addu	$t3,$v0,$a1
/*  f186a4c:	01636021 */ 	addu	$t4,$t3,$v1
/*  f186a50:	01846821 */ 	addu	$t5,$t4,$a0
/*  f186a54:	19a0002d */ 	blez	$t5,.L0f186b0c
/*  f186a58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186a5c:	8fae0128 */ 	lw	$t6,0x128($sp)
.L0f186a60:
/*  f186a60:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f186a64:	8dd802d4 */ 	lw	$t8,0x2d4($t6)
/*  f186a68:	17000003 */ 	bnez	$t8,.L0f186a78
/*  f186a6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186a70:	1219000f */ 	beq	$s0,$t9,.L0f186ab0
/*  f186a74:	00000000 */ 	sll	$zero,$zero,0x0
.L0f186a78:
/*  f186a78:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186a7c:	02002025 */ 	or	$a0,$s0,$zero
/*  f186a80:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f186a84:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186a88:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f186a8c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186a90:	3c09800a */ 	lui	$t1,0x800a
/*  f186a94:	3c08800a */ 	lui	$t0,0x800a
/*  f186a98:	3c07800a */ 	lui	$a3,0x800a
/*  f186a9c:	3c06800a */ 	lui	$a2,0x800a
/*  f186aa0:	8cc6a030 */ 	lw	$a2,-0x5fd0($a2)
/*  f186aa4:	8ce7a024 */ 	lw	$a3,-0x5fdc($a3)
/*  f186aa8:	8d08a028 */ 	lw	$t0,-0x5fd8($t0)
/*  f186aac:	8d29a02c */ 	lw	$t1,-0x5fd4($t1)
.L0f186ab0:
/*  f186ab0:	11200003 */ 	beqz	$t1,.L0f186ac0
/*  f186ab4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f186ab8:	10000002 */ 	beqz	$zero,.L0f186ac4
/*  f186abc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186ac0:
/*  f186ac0:	00002025 */ 	or	$a0,$zero,$zero
.L0f186ac4:
/*  f186ac4:	11000003 */ 	beqz	$t0,.L0f186ad4
/*  f186ac8:	00001825 */ 	or	$v1,$zero,$zero
/*  f186acc:	10000001 */ 	beqz	$zero,.L0f186ad4
/*  f186ad0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186ad4:
/*  f186ad4:	10e00003 */ 	beqz	$a3,.L0f186ae4
/*  f186ad8:	00002825 */ 	or	$a1,$zero,$zero
/*  f186adc:	10000001 */ 	beqz	$zero,.L0f186ae4
/*  f186ae0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f186ae4:
/*  f186ae4:	10c00003 */ 	beqz	$a2,.L0f186af4
/*  f186ae8:	00001025 */ 	or	$v0,$zero,$zero
/*  f186aec:	10000001 */ 	beqz	$zero,.L0f186af4
/*  f186af0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186af4:
/*  f186af4:	00457821 */ 	addu	$t7,$v0,$a1
/*  f186af8:	01e35021 */ 	addu	$t2,$t7,$v1
/*  f186afc:	01445821 */ 	addu	$t3,$t2,$a0
/*  f186b00:	020b082a */ 	slt	$at,$s0,$t3
/*  f186b04:	5420ffd6 */ 	bnezl	$at,.L0f186a60
/*  f186b08:	8fae0128 */ 	lw	$t6,0x128($sp)
.L0f186b0c:
/*  f186b0c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186b10:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f186b14:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f186b18:	8fa30124 */ 	lw	$v1,0x124($sp)
/*  f186b1c:	8fa40124 */ 	lw	$a0,0x124($sp)
/*  f186b20:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
/*  f186b24:	51a00007 */ 	beqzl	$t5,.L0f186b44
/*  f186b28:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f186b2c:	8c6e0040 */ 	lw	$t6,0x40($v1)
/*  f186b30:	00001025 */ 	or	$v0,$zero,$zero
/*  f186b34:	35d80004 */ 	ori	$t8,$t6,0x4
/*  f186b38:	100001ce */ 	beqz	$zero,.L0f187274
/*  f186b3c:	ac780040 */ 	sw	$t8,0x40($v1)
/*  f186b40:	90860002 */ 	lbu	$a2,0x2($a0)
.L0f186b44:
/*  f186b44:	00002825 */ 	or	$a1,$zero,$zero
/*  f186b48:	30cf0004 */ 	andi	$t7,$a2,0x4
/*  f186b4c:	0fc1ab4b */ 	jal	setupParseObject
/*  f186b50:	01e03025 */ 	or	$a2,$t7,$zero
/*  f186b54:	100001c7 */ 	beqz	$zero,.L0f187274
/*  f186b58:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186b5c:
/*  f186b5c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f186b60:	146101be */ 	bne	$v1,$at,.L0f18725c
/*  f186b64:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f186b68:	8faa0128 */ 	lw	$t2,0x128($sp)
/*  f186b6c:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f186b70:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f186b74:	8d4302d4 */ 	lw	$v1,0x2d4($t2)
/*  f186b78:	5060000e */ 	beqzl	$v1,.L0f186bb4
/*  f186b7c:	8e2e028c */ 	lw	$t6,0x28c($s1)
/*  f186b80:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f186b84:	01402025 */ 	or	$a0,$t2,$zero
/*  f186b88:	00025880 */ 	sll	$t3,$v0,0x2
/*  f186b8c:	3c0c800b */ 	lui	$t4,0x800b
/*  f186b90:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f186b94:	8d8cc500 */ 	lw	$t4,-0x3b00($t4)
/*  f186b98:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f186b9c:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f186ba0:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f186ba4:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f186ba8:	10000019 */ 	beqz	$zero,.L0f186c10
/*  f186bac:	8da302d4 */ 	lw	$v1,0x2d4($t5)
/*  f186bb0:	8e2e028c */ 	lw	$t6,0x28c($s1)
.L0f186bb4:
/*  f186bb4:	3c0a800b */ 	lui	$t2,%hi(g_MpPlayers)
/*  f186bb8:	254ac7b8 */ 	addiu	$t2,$t2,%lo(g_MpPlayers)
/*  f186bbc:	000ec1c0 */ 	sll	$t8,$t6,0x7
/*  f186bc0:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f186bc4:	8f2200e4 */ 	lw	$v0,0xe4($t9)
/*  f186bc8:	3c0e800b */ 	lui	$t6,%hi(g_MpSimulants)
/*  f186bcc:	25cec538 */ 	addiu	$t6,$t6,%lo(g_MpSimulants)
/*  f186bd0:	28410004 */ 	slti	$at,$v0,0x4
/*  f186bd4:	10200007 */ 	beqz	$at,.L0f186bf4
/*  f186bd8:	00026080 */ 	sll	$t4,$v0,0x2
/*  f186bdc:	00027880 */ 	sll	$t7,$v0,0x2
/*  f186be0:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f186be4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f186be8:	01ea5821 */ 	addu	$t3,$t7,$t2
/*  f186bec:	10000008 */ 	beqz	$zero,.L0f186c10
/*  f186bf0:	afab0050 */ 	sw	$t3,0x50($sp)
.L0f186bf4:
/*  f186bf4:	01826021 */ 	addu	$t4,$t4,$v0
/*  f186bf8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f186bfc:	01826023 */ 	subu	$t4,$t4,$v0
/*  f186c00:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f186c04:	258dfed0 */ 	addiu	$t5,$t4,-304
/*  f186c08:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f186c0c:	afb80050 */ 	sw	$t8,0x50($sp)
.L0f186c10:
/*  f186c10:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f186c14:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f186c18:	932f0011 */ 	lbu	$t7,0x11($t9)
/*  f186c1c:	854b0062 */ 	lh	$t3,0x62($t2)
/*  f186c20:	15eb00c8 */ 	bne	$t7,$t3,.L0f186f44
/*  f186c24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186c28:	10600005 */ 	beqz	$v1,.L0f186c40
/*  f186c2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186c30:	8c6c009c */ 	lw	$t4,0x9c($v1)
/*  f186c34:	000c7040 */ 	sll	$t6,$t4,0x1
/*  f186c38:	05c20008 */ 	bltzl	$t6,.L0f186c5c
/*  f186c3c:	8fb80050 */ 	lw	$t8,0x50($sp)
.L0f186c40:
/*  f186c40:	546000b9 */ 	bnezl	$v1,.L0f186f28
/*  f186c44:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f186c48:	0fc44a11 */ 	jal	func0f112844
/*  f186c4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186c50:	504000b5 */ 	beqzl	$v0,.L0f186f28
/*  f186c54:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f186c58:	8fb80050 */ 	lw	$t8,0x50($sp)
.L0f186c5c:
/*  f186c5c:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f186c60:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f186c64:	8719003e */ 	lh	$t9,0x3e($t8)
/*  f186c68:	00008025 */ 	or	$s0,$zero,$zero
/*  f186c6c:	272a0001 */ 	addiu	$t2,$t9,0x1
/*  f186c70:	a70a003e */ 	sh	$t2,0x3e($t8)
/*  f186c74:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f186c78:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f186c7c:	8de3001c */ 	lw	$v1,0x1c($t7)
.L0f186c80:
/*  f186c80:	8c4b0058 */ 	lw	$t3,0x58($v0)
/*  f186c84:	506b0006 */ 	beql	$v1,$t3,.L0f186ca0
/*  f186c88:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
/*  f186c8c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f186c90:	2a010004 */ 	slti	$at,$s0,0x4
/*  f186c94:	1420fffa */ 	bnez	$at,.L0f186c80
/*  f186c98:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f186c9c:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
.L0f186ca0:
/*  f186ca0:	11a00009 */ 	beqz	$t5,.L0f186cc8
/*  f186ca4:	01802025 */ 	or	$a0,$t4,$zero
/*  f186ca8:	0fc66661 */ 	jal	func0f199984
/*  f186cac:	24050057 */ 	addiu	$a1,$zero,0x57
/*  f186cb0:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f186cb4:	8dc302d4 */ 	lw	$v1,0x2d4($t6)
/*  f186cb8:	9079009c */ 	lbu	$t9,0x9c($v1)
/*  f186cbc:	332affbf */ 	andi	$t2,$t9,0xffbf
/*  f186cc0:	10000014 */ 	beqz	$zero,.L0f186d14
/*  f186cc4:	a06a009c */ 	sb	$t2,0x9c($v1)
.L0f186cc8:
/*  f186cc8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f186ccc:	44812000 */ 	mtc1	$at,$f4
/*  f186cd0:	3c048009 */ 	lui	$a0,0x8009
/*  f186cd4:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f186cd8:	240fffff */ 	addiu	$t7,$zero,-1
/*  f186cdc:	240bffff */ 	addiu	$t3,$zero,-1
/*  f186ce0:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f186ce4:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f186ce8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f186cec:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f186cf0:	240505b8 */ 	addiu	$a1,$zero,0x5b8
/*  f186cf4:	00003025 */ 	or	$a2,$zero,$zero
/*  f186cf8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f186cfc:	0c004241 */ 	jal	func00010904
/*  f186d00:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f186d04:	0fc24494 */ 	jal	func0f091250
/*  f186d08:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d0c:	0fc447a9 */ 	jal	func0f111ea4
/*  f186d10:	24040057 */ 	addiu	$a0,$zero,0x57
.L0f186d14:
/*  f186d14:	0fc5b9f1 */ 	jal	textGet
/*  f186d18:	24045404 */ 	addiu	$a0,$zero,0x5404
/*  f186d1c:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d20:	0fc28874 */ 	jal	func0f0a21d0
/*  f186d24:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186d28:	00106880 */ 	sll	$t5,$s0,0x2
/*  f186d2c:	01b06823 */ 	subu	$t5,$t5,$s0
/*  f186d30:	3c0c800b */ 	lui	$t4,0x800b
/*  f186d34:	258ccbb0 */ 	addiu	$t4,$t4,-13392
/*  f186d38:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f186d3c:	01ac3021 */ 	addu	$a2,$t5,$t4
/*  f186d40:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f186d44:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186d48:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f186d4c:	0c004dad */ 	jal	sprintf
/*  f186d50:	00403825 */ 	or	$a3,$v0,$zero
/*  f186d54:	0fc5b9f1 */ 	jal	textGet
/*  f186d58:	24045405 */ 	addiu	$a0,$zero,0x5405
/*  f186d5c:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d60:	0fc28874 */ 	jal	func0f0a21d0
/*  f186d64:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186d68:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186d6c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f186d70:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f186d74:	0c004dad */ 	jal	sprintf
/*  f186d78:	00403825 */ 	or	$a3,$v0,$zero
/*  f186d7c:	0fc5b9f1 */ 	jal	textGet
/*  f186d80:	24045406 */ 	addiu	$a0,$zero,0x5406
/*  f186d84:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d88:	0fc28874 */ 	jal	func0f0a21d0
/*  f186d8c:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186d90:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186d94:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f186d98:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f186d9c:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f186da0:	0c004dad */ 	jal	sprintf
/*  f186da4:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f186da8:	8e39006c */ 	lw	$t9,0x6c($s1)
/*  f186dac:	8e2e028c */ 	lw	$t6,0x28c($s1)
/*  f186db0:	afb00114 */ 	sw	$s0,0x114($sp)
/*  f186db4:	00008025 */ 	or	$s0,$zero,$zero
/*  f186db8:	13200003 */ 	beqz	$t9,.L0f186dc8
/*  f186dbc:	afae0118 */ 	sw	$t6,0x118($sp)
/*  f186dc0:	10000002 */ 	beqz	$zero,.L0f186dcc
/*  f186dc4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186dc8:
/*  f186dc8:	00002025 */ 	or	$a0,$zero,$zero
.L0f186dcc:
/*  f186dcc:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f186dd0:	00001825 */ 	or	$v1,$zero,$zero
/*  f186dd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f186dd8:	11400003 */ 	beqz	$t2,.L0f186de8
/*  f186ddc:	00001025 */ 	or	$v0,$zero,$zero
/*  f186de0:	10000001 */ 	beqz	$zero,.L0f186de8
/*  f186de4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186de8:
/*  f186de8:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f186dec:	13000003 */ 	beqz	$t8,.L0f186dfc
/*  f186df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186df4:	10000001 */ 	beqz	$zero,.L0f186dfc
/*  f186df8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f186dfc:
/*  f186dfc:	8e2f0070 */ 	lw	$t7,0x70($s1)
/*  f186e00:	11e00003 */ 	beqz	$t7,.L0f186e10
/*  f186e04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186e08:	10000001 */ 	beqz	$zero,.L0f186e10
/*  f186e0c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186e10:
/*  f186e10:	00455821 */ 	addu	$t3,$v0,$a1
/*  f186e14:	01636821 */ 	addu	$t5,$t3,$v1
/*  f186e18:	01a46021 */ 	addu	$t4,$t5,$a0
/*  f186e1c:	1980003f */ 	blez	$t4,.L0f186f1c
/*  f186e20:	00000000 */ 	sll	$zero,$zero,0x0
.L0f186e24:
/*  f186e24:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186e28:	02002025 */ 	or	$a0,$s0,$zero
/*  f186e2c:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f186e30:	00107880 */ 	sll	$t7,$s0,0x2
/*  f186e34:	3c0b800b */ 	lui	$t3,0x800b
/*  f186e38:	8dd902d4 */ 	lw	$t9,0x2d4($t6)
/*  f186e3c:	8faa0118 */ 	lw	$t2,0x118($sp)
/*  f186e40:	016f5821 */ 	addu	$t3,$t3,$t7
/*  f186e44:	17200008 */ 	bnez	$t9,.L0f186e68
/*  f186e48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186e4c:	160a0006 */ 	bne	$s0,$t2,.L0f186e68
/*  f186e50:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f186e54:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186e58:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f186e5c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186e60:	10000011 */ 	beqz	$zero,.L0f186ea8
/*  f186e64:	8e2c006c */ 	lw	$t4,0x6c($s1)
.L0f186e68:
/*  f186e68:	8d6bc500 */ 	lw	$t3,-0x3b00($t3)
/*  f186e6c:	8fb80114 */ 	lw	$t8,0x114($sp)
/*  f186e70:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186e74:	916d0011 */ 	lbu	$t5,0x11($t3)
/*  f186e78:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f186e7c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186e80:	170d0006 */ 	bne	$t8,$t5,.L0f186e9c
/*  f186e84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186e88:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f186e8c:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f186e90:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186e94:	10000004 */ 	beqz	$zero,.L0f186ea8
/*  f186e98:	8e2c006c */ 	lw	$t4,0x6c($s1)
.L0f186e9c:
/*  f186e9c:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f186ea0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186ea4:	8e2c006c */ 	lw	$t4,0x6c($s1)
.L0f186ea8:
/*  f186ea8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f186eac:	00002025 */ 	or	$a0,$zero,$zero
/*  f186eb0:	11800003 */ 	beqz	$t4,.L0f186ec0
/*  f186eb4:	00001825 */ 	or	$v1,$zero,$zero
/*  f186eb8:	10000001 */ 	beqz	$zero,.L0f186ec0
/*  f186ebc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186ec0:
/*  f186ec0:	8e2e0068 */ 	lw	$t6,0x68($s1)
/*  f186ec4:	00002825 */ 	or	$a1,$zero,$zero
/*  f186ec8:	00001025 */ 	or	$v0,$zero,$zero
/*  f186ecc:	11c00003 */ 	beqz	$t6,.L0f186edc
/*  f186ed0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186ed4:	10000001 */ 	beqz	$zero,.L0f186edc
/*  f186ed8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186edc:
/*  f186edc:	8e390064 */ 	lw	$t9,0x64($s1)
/*  f186ee0:	13200003 */ 	beqz	$t9,.L0f186ef0
/*  f186ee4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186ee8:	10000001 */ 	beqz	$zero,.L0f186ef0
/*  f186eec:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f186ef0:
/*  f186ef0:	8e2a0070 */ 	lw	$t2,0x70($s1)
/*  f186ef4:	11400003 */ 	beqz	$t2,.L0f186f04
/*  f186ef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186efc:	10000001 */ 	beqz	$zero,.L0f186f04
/*  f186f00:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186f04:
/*  f186f04:	00457821 */ 	addu	$t7,$v0,$a1
/*  f186f08:	01e35821 */ 	addu	$t3,$t7,$v1
/*  f186f0c:	0164c021 */ 	addu	$t8,$t3,$a0
/*  f186f10:	0218082a */ 	slt	$at,$s0,$t8
/*  f186f14:	1420ffc3 */ 	bnez	$at,.L0f186e24
/*  f186f18:	00000000 */ 	sll	$zero,$zero,0x0
.L0f186f1c:
/*  f186f1c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186f20:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f186f24:	8fad0128 */ 	lw	$t5,0x128($sp)
.L0f186f28:
/*  f186f28:	8dac02d4 */ 	lw	$t4,0x2d4($t5)
/*  f186f2c:	11800003 */ 	beqz	$t4,.L0f186f3c
/*  f186f30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186f34:	100000cf */ 	beqz	$zero,.L0f187274
/*  f186f38:	00001025 */ 	or	$v0,$zero,$zero
.L0f186f3c:
/*  f186f3c:	100000cd */ 	beqz	$zero,.L0f187274
/*  f186f40:	00001025 */ 	or	$v0,$zero,$zero
.L0f186f44:
/*  f186f44:	10600005 */ 	beqz	$v1,.L0f186f5c
/*  f186f48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186f4c:	8c6e009c */ 	lw	$t6,0x9c($v1)
/*  f186f50:	000e5040 */ 	sll	$t2,$t6,0x1
/*  f186f54:	05410008 */ 	bgez	$t2,.L0f186f78
/*  f186f58:	00000000 */ 	sll	$zero,$zero,0x0
.L0f186f5c:
/*  f186f5c:	546000b8 */ 	bnezl	$v1,.L0f187240
/*  f186f60:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f186f64:	0fc44a11 */ 	jal	func0f112844
/*  f186f68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f186f6c:	144000b3 */ 	bnez	$v0,.L0f18723c
/*  f186f70:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f186f74:	8de302d4 */ 	lw	$v1,0x2d4($t7)
.L0f186f78:
/*  f186f78:	50600009 */ 	beqzl	$v1,.L0f186fa0
/*  f186f7c:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f186f80:	9078009c */ 	lbu	$t8,0x9c($v1)
/*  f186f84:	370d0040 */ 	ori	$t5,$t8,0x40
/*  f186f88:	a06d009c */ 	sb	$t5,0x9c($v1)
/*  f186f8c:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f186f90:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f186f94:	0fc21f03 */ 	jal	func0f087c0c
/*  f186f98:	9185005c */ 	lbu	$a1,0x5c($t4)
/*  f186f9c:	8faa0120 */ 	lw	$t2,0x120($sp)
.L0f186fa0:
/*  f186fa0:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f186fa4:	3c01800b */ 	lui	$at,0x800b
/*  f186fa8:	854f0062 */ 	lh	$t7,0x62($t2)
/*  f186fac:	8dd9001c */ 	lw	$t9,0x1c($t6)
/*  f186fb0:	24045401 */ 	addiu	$a0,$zero,0x5401
/*  f186fb4:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f186fb8:	002b0821 */ 	addu	$at,$at,$t3
/*  f186fbc:	0fc5b9f1 */ 	jal	textGet
/*  f186fc0:	ac39c168 */ 	sw	$t9,-0x3e98($at)
/*  f186fc4:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186fc8:	0fc28874 */ 	jal	func0f0a21d0
/*  f186fcc:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186fd0:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f186fd4:	3c10800b */ 	lui	$s0,0x800b
/*  f186fd8:	2610cbb0 */ 	addiu	$s0,$s0,-13392
/*  f186fdc:	870d0062 */ 	lh	$t5,0x62($t8)
/*  f186fe0:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f186fe4:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186fe8:	000d6080 */ 	sll	$t4,$t5,0x2
/*  f186fec:	018d6023 */ 	subu	$t4,$t4,$t5
/*  f186ff0:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f186ff4:	020c3821 */ 	addu	$a3,$s0,$t4
/*  f186ff8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f186ffc:	0c004dad */ 	jal	sprintf
/*  f187000:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187004:	0fc5b9f1 */ 	jal	textGet
/*  f187008:	24045402 */ 	addiu	$a0,$zero,0x5402
/*  f18700c:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f187010:	0fc28874 */ 	jal	func0f0a21d0
/*  f187014:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f187018:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f18701c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187020:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187024:	0c004dad */ 	jal	sprintf
/*  f187028:	00403825 */ 	or	$a3,$v0,$zero
/*  f18702c:	0fc5b9f1 */ 	jal	textGet
/*  f187030:	24045403 */ 	addiu	$a0,$zero,0x5403
/*  f187034:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f187038:	0fc28874 */ 	jal	func0f0a21d0
/*  f18703c:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f187040:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f187044:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f187048:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f18704c:	85ca0062 */ 	lh	$t2,0x62($t6)
/*  f187050:	00403825 */ 	or	$a3,$v0,$zero
/*  f187054:	000a7880 */ 	sll	$t7,$t2,0x2
/*  f187058:	01ea7823 */ 	subu	$t7,$t7,$t2
/*  f18705c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f187060:	0c004dad */ 	jal	sprintf
/*  f187064:	020f3021 */ 	addu	$a2,$s0,$t7
/*  f187068:	8e2b006c */ 	lw	$t3,0x6c($s1)
/*  f18706c:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f187070:	00008025 */ 	or	$s0,$zero,$zero
/*  f187074:	11600003 */ 	beqz	$t3,.L0f187084
/*  f187078:	afb90118 */ 	sw	$t9,0x118($sp)
/*  f18707c:	10000002 */ 	beqz	$zero,.L0f187088
/*  f187080:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f187084:
/*  f187084:	00002025 */ 	or	$a0,$zero,$zero
.L0f187088:
/*  f187088:	8e380068 */ 	lw	$t8,0x68($s1)
/*  f18708c:	00001825 */ 	or	$v1,$zero,$zero
/*  f187090:	00002825 */ 	or	$a1,$zero,$zero
/*  f187094:	13000003 */ 	beqz	$t8,.L0f1870a4
/*  f187098:	00001025 */ 	or	$v0,$zero,$zero
/*  f18709c:	10000001 */ 	beqz	$zero,.L0f1870a4
/*  f1870a0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1870a4:
/*  f1870a4:	8e2d0064 */ 	lw	$t5,0x64($s1)
/*  f1870a8:	11a00003 */ 	beqz	$t5,.L0f1870b8
/*  f1870ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1870b0:	10000001 */ 	beqz	$zero,.L0f1870b8
/*  f1870b4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1870b8:
/*  f1870b8:	8e2c0070 */ 	lw	$t4,0x70($s1)
/*  f1870bc:	11800003 */ 	beqz	$t4,.L0f1870cc
/*  f1870c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1870c4:	10000001 */ 	beqz	$zero,.L0f1870cc
/*  f1870c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1870cc:
/*  f1870cc:	00457021 */ 	addu	$t6,$v0,$a1
/*  f1870d0:	01c35021 */ 	addu	$t2,$t6,$v1
/*  f1870d4:	01447821 */ 	addu	$t7,$t2,$a0
/*  f1870d8:	19e0003f */ 	blez	$t7,.L0f1871d8
/*  f1870dc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1870e0:
/*  f1870e0:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1870e4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1870e8:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f1870ec:	00107080 */ 	sll	$t6,$s0,0x2
/*  f1870f0:	3c0a800b */ 	lui	$t2,0x800b
/*  f1870f4:	8f2b02d4 */ 	lw	$t3,0x2d4($t9)
/*  f1870f8:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f1870fc:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f187100:	15600008 */ 	bnez	$t3,.L0f187124
/*  f187104:	8fad0120 */ 	lw	$t5,0x120($sp)
/*  f187108:	16180006 */ 	bne	$s0,$t8,.L0f187124
/*  f18710c:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f187110:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f187114:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f187118:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18711c:	10000011 */ 	beqz	$zero,.L0f187164
/*  f187120:	8e39006c */ 	lw	$t9,0x6c($s1)
.L0f187124:
/*  f187124:	8d4ac500 */ 	lw	$t2,-0x3b00($t2)
/*  f187128:	85ac0062 */ 	lh	$t4,0x62($t5)
/*  f18712c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f187130:	914f0011 */ 	lbu	$t7,0x11($t2)
/*  f187134:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f187138:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f18713c:	158f0006 */ 	bne	$t4,$t7,.L0f187158
/*  f187140:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187144:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187148:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f18714c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f187150:	10000004 */ 	beqz	$zero,.L0f187164
/*  f187154:	8e39006c */ 	lw	$t9,0x6c($s1)
.L0f187158:
/*  f187158:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f18715c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f187160:	8e39006c */ 	lw	$t9,0x6c($s1)
.L0f187164:
/*  f187164:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f187168:	00002025 */ 	or	$a0,$zero,$zero
/*  f18716c:	13200003 */ 	beqz	$t9,.L0f18717c
/*  f187170:	00001825 */ 	or	$v1,$zero,$zero
/*  f187174:	10000001 */ 	beqz	$zero,.L0f18717c
/*  f187178:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f18717c:
/*  f18717c:	8e2b0068 */ 	lw	$t3,0x68($s1)
/*  f187180:	00002825 */ 	or	$a1,$zero,$zero
/*  f187184:	00001025 */ 	or	$v0,$zero,$zero
/*  f187188:	11600003 */ 	beqz	$t3,.L0f187198
/*  f18718c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187190:	10000001 */ 	beqz	$zero,.L0f187198
/*  f187194:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f187198:
/*  f187198:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f18719c:	13000003 */ 	beqz	$t8,.L0f1871ac
/*  f1871a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1871a4:	10000001 */ 	beqz	$zero,.L0f1871ac
/*  f1871a8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1871ac:
/*  f1871ac:	8e2d0070 */ 	lw	$t5,0x70($s1)
/*  f1871b0:	11a00003 */ 	beqz	$t5,.L0f1871c0
/*  f1871b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1871b8:	10000001 */ 	beqz	$zero,.L0f1871c0
/*  f1871bc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1871c0:
/*  f1871c0:	00457021 */ 	addu	$t6,$v0,$a1
/*  f1871c4:	01c35021 */ 	addu	$t2,$t6,$v1
/*  f1871c8:	01446021 */ 	addu	$t4,$t2,$a0
/*  f1871cc:	020c082a */ 	slt	$at,$s0,$t4
/*  f1871d0:	1420ffc3 */ 	bnez	$at,.L0f1870e0
/*  f1871d4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1871d8:
/*  f1871d8:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1871dc:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f1871e0:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f1871e4:	8df902d4 */ 	lw	$t9,0x2d4($t7)
/*  f1871e8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1871ec:	13200009 */ 	beqz	$t9,.L0f187214
/*  f1871f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1871f4:	0fc65fa3 */ 	jal	func0f197e8c
/*  f1871f8:	24050057 */ 	addiu	$a1,$zero,0x57
/*  f1871fc:	8fab0124 */ 	lw	$t3,0x124($sp)
/*  f187200:	00001025 */ 	or	$v0,$zero,$zero
/*  f187204:	8d780040 */ 	lw	$t8,0x40($t3)
/*  f187208:	370d0004 */ 	ori	$t5,$t8,0x4
/*  f18720c:	10000019 */ 	beqz	$zero,.L0f187274
/*  f187210:	ad6d0040 */ 	sw	$t5,0x40($t3)
.L0f187214:
/*  f187214:	0fc4483c */ 	jal	func0f1120f0
/*  f187218:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f18721c:	8fa40124 */ 	lw	$a0,0x124($sp)
/*  f187220:	00002825 */ 	or	$a1,$zero,$zero
/*  f187224:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f187228:	30ca0004 */ 	andi	$t2,$a2,0x4
/*  f18722c:	0fc1ab4b */ 	jal	setupParseObject
/*  f187230:	01403025 */ 	or	$a2,$t2,$zero
/*  f187234:	1000000f */ 	beqz	$zero,.L0f187274
/*  f187238:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18723c:
/*  f18723c:	8fac0128 */ 	lw	$t4,0x128($sp)
.L0f187240:
/*  f187240:	8d9902d4 */ 	lw	$t9,0x2d4($t4)
/*  f187244:	13200003 */ 	beqz	$t9,.L0f187254
/*  f187248:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18724c:	10000009 */ 	beqz	$zero,.L0f187274
/*  f187250:	00001025 */ 	or	$v0,$zero,$zero
.L0f187254:
/*  f187254:	10000007 */ 	beqz	$zero,.L0f187274
/*  f187258:	00001025 */ 	or	$v0,$zero,$zero
.L0f18725c:
/*  f18725c:	8df802d4 */ 	lw	$t8,0x2d4($t7)
/*  f187260:	00001025 */ 	or	$v0,$zero,$zero
/*  f187264:	13000003 */ 	beqz	$t8,.L0f187274
/*  f187268:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18726c:	10000001 */ 	beqz	$zero,.L0f187274
/*  f187270:	00001025 */ 	or	$v0,$zero,$zero
.L0f187274:
/*  f187274:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f187278:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f18727c:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f187280:	03e00008 */ 	jr	$ra
/*  f187284:	27bd0128 */ 	addiu	$sp,$sp,0x128
);

GLOBAL_ASM(
glabel func0f187288
/*  f187288:	27bdfef0 */ 	addiu	$sp,$sp,-272
/*  f18728c:	3c0e800b */ 	lui	$t6,0x800b
/*  f187290:	91cecb98 */ 	lbu	$t6,-0x3468($t6)
/*  f187294:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f187298:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f18729c:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f1872a0:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f1872a4:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f1872a8:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f1872ac:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f1872b0:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f1872b4:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f1872b8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1872bc:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f1872c0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f1872c4:	00a0b825 */ 	or	$s7,$a1,$zero
/*  f1872c8:	0080f025 */ 	or	$s8,$a0,$zero
/*  f1872cc:	15c10043 */ 	bne	$t6,$at,.L0f1873dc
/*  f1872d0:	8cb60004 */ 	lw	$s6,0x4($a1)
/*  f1872d4:	3c11800b */ 	lui	$s1,%hi(g_ScenarioData)
/*  f1872d8:	4480a000 */ 	mtc1	$zero,$f20
/*  f1872dc:	2631c110 */ 	addiu	$s1,$s1,%lo(g_ScenarioData)
/*  f1872e0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1872e4:	27b50070 */ 	addiu	$s5,$sp,0x70
/*  f1872e8:	27b400b0 */ 	addiu	$s4,$sp,0xb0
.L0f1872ec:
/*  f1872ec:	8fcf001c */ 	lw	$t7,0x1c($s8)
/*  f1872f0:	8e380058 */ 	lw	$t8,0x58($s1)
/*  f1872f4:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1872f8:	0010c840 */ 	sll	$t9,$s0,0x1
/*  f1872fc:	15f80033 */ 	bne	$t7,$t8,.L0f1873cc
/*  f187300:	3c08800b */ 	lui	$t0,%hi(g_ScenarioData)
/*  f187304:	2508c110 */ 	addiu	$t0,$t0,%lo(g_ScenarioData)
/*  f187308:	0fc1ab10 */ 	jal	func0f06ac40
/*  f18730c:	03289821 */ 	addu	$s3,$t9,$t0
/*  f187310:	ae370058 */ 	sw	$s7,0x58($s1)
/*  f187314:	a6d00062 */ 	sh	$s0,0x62($s6)
/*  f187318:	86690008 */ 	lh	$t1,0x8($s3)
/*  f18731c:	3c04800b */ 	lui	$a0,0x800b
/*  f187320:	8ef20004 */ 	lw	$s2,0x4($s7)
/*  f187324:	00095100 */ 	sll	$t2,$t1,0x4
/*  f187328:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f18732c:	8484c128 */ 	lh	$a0,-0x3ed8($a0)
/*  f187330:	2405004e */ 	addiu	$a1,$zero,0x4e
/*  f187334:	0fc456ac */ 	jal	padUnpack
/*  f187338:	02803025 */ 	or	$a2,$s4,$zero
/*  f18733c:	c7a400bc */ 	lwc1	$f4,0xbc($sp)
/*  f187340:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f187344:	c7b000c4 */ 	lwc1	$f16,0xc4($sp)
/*  f187348:	46002187 */ 	neg.s	$f6,$f4
/*  f18734c:	46004287 */ 	neg.s	$f10,$f8
/*  f187350:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f187354:	c7a600cc */ 	lwc1	$f6,0xcc($sp)
/*  f187358:	c7a800d0 */ 	lwc1	$f8,0xd0($sp)
/*  f18735c:	c7a400c8 */ 	lwc1	$f4,0xc8($sp)
/*  f187360:	46008487 */ 	neg.s	$f18,$f16
/*  f187364:	4405a000 */ 	mfc1	$a1,$f20
/*  f187368:	4406a000 */ 	mfc1	$a2,$f20
/*  f18736c:	4407a000 */ 	mfc1	$a3,$f20
/*  f187370:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f187374:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f187378:	02a02025 */ 	or	$a0,$s5,$zero
/*  f18737c:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f187380:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f187384:	0c005b56 */ 	jal	func00016d58
/*  f187388:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f18738c:	8e420018 */ 	lw	$v0,0x18($s2)
/*  f187390:	02a02825 */ 	or	$a1,$s5,$zero
/*  f187394:	50400004 */ 	beqzl	$v0,.L0f1873a8
/*  f187398:	8fab00f8 */ 	lw	$t3,0xf8($sp)
/*  f18739c:	0c0057c1 */ 	jal	func00015f04
/*  f1873a0:	c44c0014 */ 	lwc1	$f12,0x14($v0)
/*  f1873a4:	8fab00f8 */ 	lw	$t3,0xf8($sp)
.L0f1873a8:
/*  f1873a8:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1873ac:	a7ac006e */ 	sh	$t4,0x6e($sp)
/*  f1873b0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1873b4:	02802825 */ 	or	$a1,$s4,$zero
/*  f1873b8:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1873bc:	27a7006c */ 	addiu	$a3,$sp,0x6c
/*  f1873c0:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f1873c4:	0fc1a9cc */ 	jal	func0f06a730
/*  f1873c8:	a7ab006c */ 	sh	$t3,0x6c($sp)
.L0f1873cc:
/*  f1873cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1873d0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1873d4:	1601ffc5 */ 	bne	$s0,$at,.L0f1872ec
/*  f1873d8:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f1873dc:
/*  f1873dc:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f1873e0:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f1873e4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1873e8:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1873ec:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1873f0:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1873f4:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f1873f8:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f1873fc:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f187400:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f187404:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f187408:	03e00008 */ 	jr	$ra
/*  f18740c:	27bd0110 */ 	addiu	$sp,$sp,0x110
);

GLOBAL_ASM(
glabel func0f187410
/*  f187410:	3c0e800b */ 	lui	$t6,0x800b
/*  f187414:	91cecb98 */ 	lbu	$t6,-0x3468($t6)
/*  f187418:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f18741c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f187420:	24010002 */ 	addiu	$at,$zero,0x2
/*  f187424:	00808825 */ 	or	$s1,$a0,$zero
/*  f187428:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f18742c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f187430:	15c100a1 */ 	bne	$t6,$at,.L0f1876b8
/*  f187434:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f187438:	8cb80004 */ 	lw	$t8,0x4($a1)
/*  f18743c:	3c01800b */ 	lui	$at,0x800b
/*  f187440:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f187444:	afb80040 */ 	sw	$t8,0x40($sp)
/*  f187448:	8c99001c */ 	lw	$t9,0x1c($a0)
/*  f18744c:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f187450:	ac39c24c */ 	sw	$t9,-0x3db4($at)
/*  f187454:	8c8b02d4 */ 	lw	$t3,0x2d4($a0)
/*  f187458:	51600009 */ 	beqzl	$t3,.L0f187480
/*  f18745c:	8d4d028c */ 	lw	$t5,0x28c($t2)
/*  f187460:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f187464:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187468:	00026080 */ 	sll	$t4,$v0,0x2
/*  f18746c:	3c10800b */ 	lui	$s0,0x800b
/*  f187470:	020c8021 */ 	addu	$s0,$s0,$t4
/*  f187474:	10000017 */ 	beqz	$zero,.L0f1874d4
/*  f187478:	8e10c500 */ 	lw	$s0,-0x3b00($s0)
/*  f18747c:	8d4d028c */ 	lw	$t5,0x28c($t2)
.L0f187480:
/*  f187480:	3c19800b */ 	lui	$t9,%hi(g_MpPlayers)
/*  f187484:	2739c7b8 */ 	addiu	$t9,$t9,%lo(g_MpPlayers)
/*  f187488:	000d71c0 */ 	sll	$t6,$t5,0x7
/*  f18748c:	014e7821 */ 	addu	$t7,$t2,$t6
/*  f187490:	8de200e4 */ 	lw	$v0,0xe4($t7)
/*  f187494:	3c0d800b */ 	lui	$t5,%hi(g_MpSimulants)
/*  f187498:	25adc538 */ 	addiu	$t5,$t5,%lo(g_MpSimulants)
/*  f18749c:	28410004 */ 	slti	$at,$v0,0x4
/*  f1874a0:	10200006 */ 	beqz	$at,.L0f1874bc
/*  f1874a4:	00025880 */ 	sll	$t3,$v0,0x2
/*  f1874a8:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f1874ac:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f1874b0:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f1874b4:	10000007 */ 	beqz	$zero,.L0f1874d4
/*  f1874b8:	03198021 */ 	addu	$s0,$t8,$t9
.L0f1874bc:
/*  f1874bc:	01625821 */ 	addu	$t3,$t3,$v0
/*  f1874c0:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f1874c4:	01625823 */ 	subu	$t3,$t3,$v0
/*  f1874c8:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f1874cc:	256cfed0 */ 	addiu	$t4,$t3,-304
/*  f1874d0:	018d8021 */ 	addu	$s0,$t4,$t5
.L0f1874d4:
/*  f1874d4:	0fc5b9f1 */ 	jal	textGet
/*  f1874d8:	24045400 */ 	addiu	$a0,$zero,0x5400
/*  f1874dc:	24040036 */ 	addiu	$a0,$zero,0x36
/*  f1874e0:	0fc28874 */ 	jal	func0f0a21d0
/*  f1874e4:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f1874e8:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f1874ec:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f1874f0:	02003025 */ 	or	$a2,$s0,$zero
/*  f1874f4:	0c004dad */ 	jal	sprintf
/*  f1874f8:	00403825 */ 	or	$a3,$v0,$zero
/*  f1874fc:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f187500:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f187504:	8d49006c */ 	lw	$t1,0x6c($t2)
/*  f187508:	8d4e028c */ 	lw	$t6,0x28c($t2)
/*  f18750c:	00008025 */ 	or	$s0,$zero,$zero
/*  f187510:	11200003 */ 	beqz	$t1,.L0f187520
/*  f187514:	afae0044 */ 	sw	$t6,0x44($sp)
/*  f187518:	10000002 */ 	beqz	$zero,.L0f187524
/*  f18751c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f187520:
/*  f187520:	00002025 */ 	or	$a0,$zero,$zero
.L0f187524:
/*  f187524:	8d480068 */ 	lw	$t0,0x68($t2)
/*  f187528:	00001825 */ 	or	$v1,$zero,$zero
/*  f18752c:	00002825 */ 	or	$a1,$zero,$zero
/*  f187530:	11000003 */ 	beqz	$t0,.L0f187540
/*  f187534:	00001025 */ 	or	$v0,$zero,$zero
/*  f187538:	10000001 */ 	beqz	$zero,.L0f187540
/*  f18753c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f187540:
/*  f187540:	8d470064 */ 	lw	$a3,0x64($t2)
/*  f187544:	10e00003 */ 	beqz	$a3,.L0f187554
/*  f187548:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18754c:	10000001 */ 	beqz	$zero,.L0f187554
/*  f187550:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f187554:
/*  f187554:	8d460070 */ 	lw	$a2,0x70($t2)
/*  f187558:	10c00003 */ 	beqz	$a2,.L0f187568
/*  f18755c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187560:	10000001 */ 	beqz	$zero,.L0f187568
/*  f187564:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f187568:
/*  f187568:	00457821 */ 	addu	$t7,$v0,$a1
/*  f18756c:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f187570:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f187574:	1b20002c */ 	blez	$t9,.L0f187628
/*  f187578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18757c:	8e2b02d4 */ 	lw	$t3,0x2d4($s1)
.L0f187580:
/*  f187580:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f187584:	15600003 */ 	bnez	$t3,.L0f187594
/*  f187588:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18758c:	120c000f */ 	beq	$s0,$t4,.L0f1875cc
/*  f187590:	00000000 */ 	sll	$zero,$zero,0x0
.L0f187594:
/*  f187594:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f187598:	02002025 */ 	or	$a0,$s0,$zero
/*  f18759c:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f1875a0:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1875a4:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f1875a8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1875ac:	3c09800a */ 	lui	$t1,0x800a
/*  f1875b0:	3c08800a */ 	lui	$t0,0x800a
/*  f1875b4:	3c07800a */ 	lui	$a3,0x800a
/*  f1875b8:	3c06800a */ 	lui	$a2,0x800a
/*  f1875bc:	8cc6a030 */ 	lw	$a2,-0x5fd0($a2)
/*  f1875c0:	8ce7a024 */ 	lw	$a3,-0x5fdc($a3)
/*  f1875c4:	8d08a028 */ 	lw	$t0,-0x5fd8($t0)
/*  f1875c8:	8d29a02c */ 	lw	$t1,-0x5fd4($t1)
.L0f1875cc:
/*  f1875cc:	11200003 */ 	beqz	$t1,.L0f1875dc
/*  f1875d0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1875d4:	10000002 */ 	beqz	$zero,.L0f1875e0
/*  f1875d8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f1875dc:
/*  f1875dc:	00002025 */ 	or	$a0,$zero,$zero
.L0f1875e0:
/*  f1875e0:	11000003 */ 	beqz	$t0,.L0f1875f0
/*  f1875e4:	00001825 */ 	or	$v1,$zero,$zero
/*  f1875e8:	10000001 */ 	beqz	$zero,.L0f1875f0
/*  f1875ec:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1875f0:
/*  f1875f0:	10e00003 */ 	beqz	$a3,.L0f187600
/*  f1875f4:	00002825 */ 	or	$a1,$zero,$zero
/*  f1875f8:	10000001 */ 	beqz	$zero,.L0f187600
/*  f1875fc:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f187600:
/*  f187600:	10c00003 */ 	beqz	$a2,.L0f187610
/*  f187604:	00001025 */ 	or	$v0,$zero,$zero
/*  f187608:	10000001 */ 	beqz	$zero,.L0f187610
/*  f18760c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f187610:
/*  f187610:	00456821 */ 	addu	$t5,$v0,$a1
/*  f187614:	01a37021 */ 	addu	$t6,$t5,$v1
/*  f187618:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f18761c:	020f082a */ 	slt	$at,$s0,$t7
/*  f187620:	5420ffd7 */ 	bnezl	$at,.L0f187580
/*  f187624:	8e2b02d4 */ 	lw	$t3,0x2d4($s1)
.L0f187628:
/*  f187628:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f18762c:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f187630:	8e3802d4 */ 	lw	$t8,0x2d4($s1)
/*  f187634:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f187638:	13000010 */ 	beqz	$t8,.L0f18767c
/*  f18763c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187640:	0fc21f03 */ 	jal	func0f087c0c
/*  f187644:	24050036 */ 	addiu	$a1,$zero,0x36
/*  f187648:	02202025 */ 	or	$a0,$s1,$zero
/*  f18764c:	0fc65fa3 */ 	jal	func0f197e8c
/*  f187650:	24050036 */ 	addiu	$a1,$zero,0x36
/*  f187654:	8e2302d4 */ 	lw	$v1,0x2d4($s1)
/*  f187658:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f18765c:	00001025 */ 	or	$v0,$zero,$zero
/*  f187660:	906b004c */ 	lbu	$t3,0x4c($v1)
/*  f187664:	356c0004 */ 	ori	$t4,$t3,0x4
/*  f187668:	a06c004c */ 	sb	$t4,0x4c($v1)
/*  f18766c:	8c8d0040 */ 	lw	$t5,0x40($a0)
/*  f187670:	35ae0004 */ 	ori	$t6,$t5,0x4
/*  f187674:	10000016 */ 	beqz	$zero,.L0f1876d0
/*  f187678:	ac8e0040 */ 	sw	$t6,0x40($a0)
.L0f18767c:
/*  f18767c:	0fc44762 */ 	jal	func0f111d88
/*  f187680:	24040036 */ 	addiu	$a0,$zero,0x36
/*  f187684:	24040036 */ 	addiu	$a0,$zero,0x36
/*  f187688:	0fc221f2 */ 	jal	func0f0887c8
/*  f18768c:	00002825 */ 	or	$a1,$zero,$zero
/*  f187690:	0fc21f44 */ 	jal	func0f087d10
/*  f187694:	24040036 */ 	addiu	$a0,$zero,0x36
/*  f187698:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f18769c:	00002825 */ 	or	$a1,$zero,$zero
/*  f1876a0:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f1876a4:	30d80004 */ 	andi	$t8,$a2,0x4
/*  f1876a8:	0fc1ab4b */ 	jal	setupParseObject
/*  f1876ac:	03003025 */ 	or	$a2,$t8,$zero
/*  f1876b0:	10000007 */ 	beqz	$zero,.L0f1876d0
/*  f1876b4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1876b8:
/*  f1876b8:	8e3902d4 */ 	lw	$t9,0x2d4($s1)
/*  f1876bc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1876c0:	13200003 */ 	beqz	$t9,.L0f1876d0
/*  f1876c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1876c8:	10000001 */ 	beqz	$zero,.L0f1876d0
/*  f1876cc:	00001025 */ 	or	$v0,$zero,$zero
.L0f1876d0:
/*  f1876d0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1876d4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1876d8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1876dc:	03e00008 */ 	jr	$ra
/*  f1876e0:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0f1876e4
/*  f1876e4:	3c0e800b */ 	lui	$t6,0x800b
/*  f1876e8:	91cecb98 */ 	lbu	$t6,-0x3468($t6)
/*  f1876ec:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1876f0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1876f4:	15c10017 */ 	bne	$t6,$at,.L0f187754
/*  f1876f8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1876fc:	8ca30004 */ 	lw	$v1,0x4($a1)
/*  f187700:	8c6f0010 */ 	lw	$t7,0x10($v1)
/*  f187704:	31f82000 */ 	andi	$t8,$t7,0x2000
/*  f187708:	53000013 */ 	beqzl	$t8,.L0f187758
/*  f18770c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f187710:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f187714:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f187718:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f18771c:	3c010fff */ 	lui	$at,0xfff
/*  f187720:	3421ffff */ 	ori	$at,$at,0xffff
/*  f187724:	8c640040 */ 	lw	$a0,0x40($v1)
/*  f187728:	00025700 */ 	sll	$t2,$v0,0x1c
/*  f18772c:	30994000 */ 	andi	$t9,$a0,0x4000
/*  f187730:	17200008 */ 	bnez	$t9,.L0f187754
/*  f187734:	00814024 */ 	and	$t0,$a0,$at
/*  f187738:	3c01f000 */ 	lui	$at,0xf000
/*  f18773c:	01415824 */ 	and	$t3,$t2,$at
/*  f187740:	010b6025 */ 	or	$t4,$t0,$t3
/*  f187744:	ac680040 */ 	sw	$t0,0x40($v1)
/*  f187748:	ac6c0040 */ 	sw	$t4,0x40($v1)
/*  f18774c:	358e4000 */ 	ori	$t6,$t4,0x4000
/*  f187750:	ac6e0040 */ 	sw	$t6,0x40($v1)
.L0f187754:
/*  f187754:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f187758:
/*  f187758:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f18775c:	03e00008 */ 	jr	$ra
/*  f187760:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187764:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187768:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18776c:	00000000 */ 	sll	$zero,$zero,0x0
);
