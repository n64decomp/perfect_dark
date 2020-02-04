#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "types.h"
#include "game/game_005fd0.h"
#include "game/chr/chr.h"
#include "game/game_066310.h"
#include "game/game_096750.h"
#include "game/game_097a50.h"
#include "game/game_0b0420.h"
#include "game/game_0b28d0.h"
#include "game/game_0d4690.h"
#include "game/game_0dcdb0.h"
#include "game/game_0f09f0.h"
#include "game/game_107fb0.h"
#include "game/game_10ccd0.h"
#include "game/game_111600.h"
#include "game/pad.h"
#include "game/game_129900.h"
#include "game/pdoptions.h"
#include "game/game_152fa0.h"
#include "game/game_1668e0.h"
#include "game/game_16cfa0.h"
#include "game/game_176d70.h"
#include "game/game_187770.h"
#include "game/game_197600.h"
#include "game/game_1999b0.h"
#include "game/game_19c990.h"
#include "game/game_1a3340.h"
#include "library/library_12dc0.h"
#include "library/library_16110.h"

const u32 var7f1b2120[] = {0xffffff00};
const u32 var7f1b2124[] = {0xffffff00};
const u32 var7f1b2128[] = {0xffffff00};
const u32 var7f1b212c[] = {0xffffff00};
const u32 var7f1b2130[] = {0xffffff00};
const u32 var7f1b2134[] = {0x4f4f4f00};
const u32 var7f1b2138[] = {0xffffff00};
const u32 var7f1b213c[] = {0xffffff00};
const u32 var7f1b2140[] = {0xffffff00};
const u32 var7f1b2144[] = {0xffffff00};
const u32 var7f1b2148[] = {0xffffff00};
const u32 var7f1b214c[] = {0xffffff00};
const u32 var7f1b2150[] = {0x00000000};
const u32 var7f1b2154[] = {0xffffff00};
const u32 var7f1b2158[] = {0xffffff00};
const u32 var7f1b215c[] = {0xffffff00};
const u32 var7f1b2160[] = {0xffffff00};
const u32 var7f1b2164[] = {0xffffff00};
const u32 var7f1b2168[] = {0xffffff00};
const u32 var7f1b216c[] = {0xffffff00};
const u32 var7f1b2170[] = {0x006f6faf};
const u32 var7f1b2174[] = {0xffffff00};
const u32 var7f1b2178[] = {0xffffff00};
const u32 var7f1b217c[] = {0xffffff00};
const u32 var7f1b2180[] = {0xffffff00};
const u32 var7f1b2184[] = {0xffffff00};
const u32 var7f1b2188[] = {0xffffff00};
const u32 var7f1b218c[] = {0x00000000};
const u32 var7f1b2190[] = {0xffffff00};
const u32 var7f1b2194[] = {0xffffff00};
const u32 var7f1b2198[] = {0xffffff00};
const u32 var7f1b219c[] = {0xffffff00};
const u32 var7f1b21a0[] = {0xffffff00};
const u32 var7f1b21a4[] = {0xffffff00};
const u32 var7f1b21a8[] = {0xffffff00};
const u32 var7f1b21ac[] = {0x006f6faf};
const u32 var7f1b21b0[] = {0xffffff00};
const u32 var7f1b21b4[] = {0xffffff00};
const u32 var7f1b21b8[] = {0xffffff00};
const u32 var7f1b21bc[] = {0xffffff00};
const u32 var7f1b21c0[] = {0xffffff00};
const u32 var7f1b21c4[] = {0xffffff00};
const u32 var7f1b21c8[] = {0x00000000};
const u32 var7f1b21cc[] = {0xffffff00};
const u32 var7f1b21d0[] = {0xffffff00};
const u32 var7f1b21d4[] = {0xffffff00};
const u32 var7f1b21d8[] = {0xff7f0000};
const u32 var7f1b21dc[] = {0xffffff00};
const u32 var7f1b21e0[] = {0xffffff00};
const u32 var7f1b21e4[] = {0x00ffff00};
const u32 var7f1b21e8[] = {0x006f6faf};
const u32 var7f1b21ec[] = {0xffffff00};
const u32 var7f1b21f0[] = {0xffffff00};
const u32 var7f1b21f4[] = {0xffffff00};
const u32 var7f1b21f8[] = {0xffffff00};
const u32 var7f1b21fc[] = {0xffffff00};
const u32 var7f1b2200[] = {0xffffff00};
const u32 var7f1b2204[] = {0x00000000};
const u32 var7f1b2208[] = {0xffffffff};
const u32 var7f1b220c[] = {0xffffff7f};
const u32 var7f1b2210[] = {0xffffffff};
const u32 var7f1b2214[] = {0xffffffff};
const u32 var7f1b2218[] = {0xffffff7f};
const u32 var7f1b221c[] = {0xffffffff};
const u32 var7f1b2220[] = {0xffffffff};
const u32 var7f1b2224[] = {0xffffffff};
const u32 var7f1b2228[] = {0xffffffff};
const u32 var7f1b222c[] = {0xffffffff};
const u32 var7f1b2230[] = {0xffffffff};
const u32 var7f1b2234[] = {0xffffff5f};
const u32 var7f1b2238[] = {0xffffffff};
const u32 var7f1b223c[] = {0xffffff7f};
const u32 var7f1b2240[] = {0xffffffff};
const u32 var7f1b2244[] = {0xffffffff};
const u32 var7f1b2248[] = {0xffffff7f};
const u32 var7f1b224c[] = {0xffffffff};
const u32 var7f1b2250[] = {0xffffffff};
const u32 var7f1b2254[] = {0xffffff7f};
const u32 var7f1b2258[] = {0xffffffff};
const u32 var7f1b225c[] = {0xffffffff};
const u32 var7f1b2260[] = {0xffffffff};
const u32 var7f1b2264[] = {0xffffffff};
const u32 var7f1b2268[] = {0xffffffff};
const u32 var7f1b226c[] = {0xffffffff};
const u32 var7f1b2270[] = {0xffffff5f};
const u32 var7f1b2274[] = {0xffffffff};
const u32 var7f1b2278[] = {0xffffff7f};
const u32 var7f1b227c[] = {0xffffffff};
const u32 var7f1b2280[] = {0x44444400};
const u32 var7f1b2284[] = {0x44444400};
const u32 var7f1b2288[] = {0x44444400};
const u32 var7f1b228c[] = {0x44444400};
const u32 var7f1b2290[] = {0x44444400};
const u32 var7f1b2294[] = {0x44444400};
const u32 var7f1b2298[] = {0x44444400};
const u32 var7f1b229c[] = {0x4f4f4f00};
const u32 var7f1b22a0[] = {0x44444400};
const u32 var7f1b22a4[] = {0x44444400};
const u32 var7f1b22a8[] = {0x44444400};
const u32 var7f1b22ac[] = {0x44444400};
const u32 var7f1b22b0[] = {0x44444400};
const u32 var7f1b22b4[] = {0x44444400};
const u32 var7f1b22b8[] = {0x00000000};
const u32 var7f1b22bc[] = {0x44444400};
const u32 var7f1b22c0[] = {0x44444400};
const u32 var7f1b22c4[] = {0x44444400};
const u32 var7f1b22c8[] = {0x44444400};
const u32 var7f1b22cc[] = {0x44444400};
const u32 var7f1b22d0[] = {0x44444400};
const u32 var7f1b22d4[] = {0x44444400};
const u32 var7f1b22d8[] = {0x006f6faf};
const u32 var7f1b22dc[] = {0x44444400};
const u32 var7f1b22e0[] = {0x44444400};
const u32 var7f1b22e4[] = {0x44444400};
const u32 var7f1b22e8[] = {0x44444400};
const u32 var7f1b22ec[] = {0x44444400};
const u32 var7f1b22f0[] = {0x44444400};
const u32 var7f1b22f4[] = {0x00000000};
const u32 var7f1b22f8[] = {0x44444400};
const u32 var7f1b22fc[] = {0x44444400};
const u32 var7f1b2300[] = {0x44444400};
const u32 var7f1b2304[] = {0x44444400};
const u32 var7f1b2308[] = {0x44444400};
const u32 var7f1b230c[] = {0x44444400};
const u32 var7f1b2310[] = {0x44444400};
const u32 var7f1b2314[] = {0x006f6faf};
const u32 var7f1b2318[] = {0x44444400};
const u32 var7f1b231c[] = {0x44444400};
const u32 var7f1b2320[] = {0x44444400};
const u32 var7f1b2324[] = {0x44444400};
const u32 var7f1b2328[] = {0x44444400};
const u32 var7f1b232c[] = {0x44444400};
const u32 var7f1b2330[] = {0x00000000};
const u32 var7f1b2334[] = {0x44444400};
const u32 var7f1b2338[] = {0x44444400};
const u32 var7f1b233c[] = {0x44444400};
const u32 var7f1b2340[] = {0x00ff0000};
const u32 var7f1b2344[] = {0x44444400};
const u32 var7f1b2348[] = {0x44444400};
const u32 var7f1b234c[] = {0xffff0000};
const u32 var7f1b2350[] = {0x006f6faf};
const u32 var7f1b2354[] = {0x44444400};
const u32 var7f1b2358[] = {0x44444400};
const u32 var7f1b235c[] = {0x44444400};
const u32 var7f1b2360[] = {0x44444400};
const u32 var7f1b2364[] = {0x44444400};
const u32 var7f1b2368[] = {0x44444400};
const u32 var7f1b236c[] = {0x00000000};
const u32 var7f1b2370[] = {0xffffffff};
const u32 var7f1b2374[] = {0xffffff7f};
const u32 var7f1b2378[] = {0xffffffff};
const u32 var7f1b237c[] = {0xffffffff};
const u32 var7f1b2380[] = {0xffffff7f};
const u32 var7f1b2384[] = {0xffffffff};
const u32 var7f1b2388[] = {0xffffffff};
const u32 var7f1b238c[] = {0xffffffff};
const u32 var7f1b2390[] = {0xffffffff};
const u32 var7f1b2394[] = {0xffffffff};
const u32 var7f1b2398[] = {0xffffffff};
const u32 var7f1b239c[] = {0xffffff5f};
const u32 var7f1b23a0[] = {0xffffffff};
const u32 var7f1b23a4[] = {0xffffff7f};
const u32 var7f1b23a8[] = {0xffffffff};
const u32 var7f1b23ac[] = {0xffffffff};
const u32 var7f1b23b0[] = {0xffffff7f};
const u32 var7f1b23b4[] = {0xffffffff};
const u32 var7f1b23b8[] = {0xffffffff};
const u32 var7f1b23bc[] = {0xffffff7f};
const u32 var7f1b23c0[] = {0xffffffff};
const u32 var7f1b23c4[] = {0xffffffff};
const u32 var7f1b23c8[] = {0xffffffff};
const u32 var7f1b23cc[] = {0xffffffff};
const u32 var7f1b23d0[] = {0xffffffff};
const u32 var7f1b23d4[] = {0xffffffff};
const u32 var7f1b23d8[] = {0xffffff5f};
const u32 var7f1b23dc[] = {0xffffffff};
const u32 var7f1b23e0[] = {0xffffff7f};
const u32 var7f1b23e4[] = {0xffffffff};
const u32 var7f1b23e8[] = {0x544d0000};
const u32 var7f1b23ec[] = {0x00000000};
const u32 var7f1b23f0[] = {0x00000000};
const u32 var7f1b23f4[] = {0x00000000};
const u32 var7f1b23f8[] = {0x00000000};
const u32 var7f1b23fc[] = {0x00000000};

const char var7f1b2400[] = "(BNC:Menu) findItem Warning: Item not found\n";
const char var7f1b2430[] = "(BNC:Menu) menuFirstFocus - Menu %s does not have any focusable item!\n";
const char var7f1b2478[] = "(BNC:Menu) menuLastFocus - Menu %s does not have any focusable item!\n";
const char var7f1b24c0[] = "Init menu %x\n";
const char var7f1b24d0[] = "[]-[] Added Main menu to ctl slot %d\n";
const char var7f1b24f8[] = "[]-[] Added Slide menu to ctl slot %d\n";
const char var7f1b2520[] = "[]-[] StackStart Stats: slides %d, ctlPtr %d slidePtr %d\n";
const char var7f1b255c[] = "$-$-$avePtr: %d\n";
const char var7f1b2570[] = "[]-[] Menu End: now %d slides\n";
const char var7f1b2590[] = "Freeing challenge mem\n";
const char var7f1b25a8[] = "IG:) style %d gbHead:%d\n";
const char var7f1b25c4[] = "GRABBED GUN MEM!\n";
const char var7f1b25d8[] = "Freeing challenge mem\n";
const char var7f1b25f0[] = "mzn";
const char var7f1b25f4[] = "mzf";

const u32 var7f1b25f8[] = {0xbf000000};
const u32 var7f1b25fc[] = {0x50000000};
const u32 var7f1b2600[] = {0xff000000};
const u32 var7f1b2604[] = {0xbfbf0000};
const u32 var7f1b2608[] = {0x50500000};
const u32 var7f1b260c[] = {0xffff0000};
const u32 var7f1b2610[] = {0x0000bf00};
const u32 var7f1b2614[] = {0x00005000};
const u32 var7f1b2618[] = {0x0000ff00};
const u32 var7f1b261c[] = {0xbf00bf00};
const u32 var7f1b2620[] = {0x50005000};
const u32 var7f1b2624[] = {0xff00ff00};
const u32 var7f1b2628[] = {0x00bfbf00};
const u32 var7f1b262c[] = {0x00505000};
const u32 var7f1b2630[] = {0x00ffff00};
const u32 var7f1b2634[] = {0xff885500};
const u32 var7f1b2638[] = {0x7f482000};
const u32 var7f1b263c[] = {0xff885500};
const u32 var7f1b2640[] = {0xff888800};
const u32 var7f1b2644[] = {0x7f484800};
const u32 var7f1b2648[] = {0xff888800};
const u32 var7f1b264c[] = {0x88445500};
const u32 var7f1b2650[] = {0x48242000};
const u32 var7f1b2654[] = {0x88445500};

const char var7f1b2658[] = "1\n";
const char var7f1b265c[] = "2\n";
const char var7f1b2660[] = "3\n";
const char var7f1b2664[] = "4\n";
const char var7f1b2668[] = "[]-[] Terminate Complete\n";
const char var7f1b2684[] = "Enabling control %d\n";
const char var7f1b269c[] = "NOT IN MODE MULTIINGAME!\n";
const char var7f1b26b8[] = "Numactive now:%d\n";
const char var7f1b26cc[] = "[]-[] SwitchMenuMode called, context %d\n";
const char var7f1b26f8[] = "cthresh";
const char var7f1b2700[] = "[]-[] slide from %d";
const char var7f1b2714[] = " to %d\n";
const char var7f1b271c[] = "UNPAUSE: enabling control 0\n";
const char var7f1b273c[] = "file: type %d guid %x-%x data %x err %d\n";
const char var7f1b2768[] = "StartSelects\n";
const char var7f1b2778[] = "bblur";
const char var7f1b2780[] = "cone";
const char var7f1b2788[] = "usePiece";
const char var7f1b2794[] = "%s%s";
const char var7f1b279c[] = "%s%s";
const char var7f1b27a4[] = "Tune Selector - mode %d\n";

const u32 var7f1b27c0[] = {0x7f0f0a30};
const u32 var7f1b27c4[] = {0x7f0f0a38};
const u32 var7f1b27c8[] = {0x7f0f0a40};
const u32 var7f1b27cc[] = {0x7f0f0a48};
const u32 var7f1b27d0[] = {0x7f0f0a50};
const u32 var7f1b27d4[] = {0x7f0f0a68};
const u32 var7f1b27d8[] = {0x7f0f0ab8};
const u32 var7f1b27dc[] = {0x7f0f0ab8};
const u32 var7f1b27e0[] = {0x7f0f0a70};
const u32 var7f1b27e4[] = {0x7f0f0a78};
const u32 var7f1b27e8[] = {0x7f0f0a80};
const u32 var7f1b27ec[] = {0x7f0f0ab8};
const u32 var7f1b27f0[] = {0x7f0f0a88};
const u32 var7f1b27f4[] = {0x7f0f0aa4};
const u32 var7f1b27f8[] = {0x3ecccccd};
const u32 var7f1b27fc[] = {0x3ed68d76};
const u32 var7f1b2800[] = {0x7f0f15e4};
const u32 var7f1b2804[] = {0x7f0f1610};
const u32 var7f1b2808[] = {0x7f0f1610};
const u32 var7f1b280c[] = {0x7f0f15d8};
const u32 var7f1b2810[] = {0x7f0f1610};
const u32 var7f1b2814[] = {0x7f0f1610};
const u32 var7f1b2818[] = {0x7f0f15cc};
const u32 var7f1b281c[] = {0x7f0f15cc};
const u32 var7f1b2820[] = {0x7f0f1610};
const u32 var7f1b2824[] = {0x7f0f1610};
const u32 var7f1b2828[] = {0x7f0f15f0};
const u32 var7f1b282c[] = {0x7f0f1608};
const u32 var7f1b2830[] = {0x7f0f15cc};
const u32 var7f1b2834[] = {0x7f0f15fc};
const u32 var7f1b2838[] = {0x7f0f1608};
const u32 var7f1b283c[] = {0x7f0f1610};
const u32 var7f1b2840[] = {0x7f0f1610};
const u32 var7f1b2844[] = {0x7f0f1610};
const u32 var7f1b2848[] = {0x7f0f15cc};
const u32 var7f1b284c[] = {0x7f0f1610};
const u32 var7f1b2850[] = {0x7f0f1608};
const u32 var7f1b2854[] = {0x7f0f15d8};
const u32 var7f1b2858[] = {0x7f0f15cc};
const u32 var7f1b285c[] = {0x7f0f15d8};
const u32 var7f1b2860[] = {0x7f0f19f4};
const u32 var7f1b2864[] = {0x7f0f1730};
const u32 var7f1b2868[] = {0x7f0f1d44};
const u32 var7f1b286c[] = {0x7f0f19f4};
const u32 var7f1b2870[] = {0x7f0f1bb4};
const u32 var7f1b2874[] = {0x7f0f1bf0};
const u32 var7f1b2878[] = {0x7f0f1cbc};
const u32 var7f1b287c[] = {0x7f0f1894};
const u32 var7f1b2880[] = {0x7f0f18ec};
const u32 var7f1b2884[] = {0x7f0f1d44};
const u32 var7f1b2888[] = {0x7f0f19a0};
const u32 var7f1b288c[] = {0x7f0f1784};
const u32 var7f1b2890[] = {0x7f0f171c};
const u32 var7f1b2894[] = {0x7f0f1ce0};
const u32 var7f1b2898[] = {0x7f0f1ccc};
const u32 var7f1b289c[] = {0x7f0f1cf4};
const u32 var7f1b28a0[] = {0x7f0f1d30};
const u32 var7f1b28a4[] = {0x7f0f198c};
const u32 var7f1b28a8[] = {0x7f0f1880};
const u32 var7f1b28ac[] = {0x7f0f16f4};
const u32 var7f1b28b0[] = {0x7f0f1708};
const u32 var7f1b28b4[] = {0x7f0f1d1c};
const u32 var7f1b28b8[] = {0x7f0f19c4};
const u32 var7f1b28bc[] = {0x7f0f16c8};
const u32 var7f1b28c0[] = {0x7f0f16b4};
const u32 var7f1b28c4[] = {0x7f0f26b0};
const u32 var7f1b28c8[] = {0x7f0f26cc};
const u32 var7f1b28cc[] = {0x7f0f26cc};
const u32 var7f1b28d0[] = {0x7f0f26cc};
const u32 var7f1b28d4[] = {0x7f0f26cc};
const u32 var7f1b28d8[] = {0x7f0f26b0};
const u32 var7f1b28dc[] = {0x7f0f26b0};
const u32 var7f1b28e0[] = {0x7f0f26cc};
const u32 var7f1b28e4[] = {0x7f0f26cc};
const u32 var7f1b28e8[] = {0x7f0f26cc};
const u32 var7f1b28ec[] = {0x7f0f26b0};
const u32 var7f1b28f0[] = {0x7f0f26cc};
const u32 var7f1b28f4[] = {0x7f0f26cc};
const u32 var7f1b28f8[] = {0x7f0f26cc};
const u32 var7f1b28fc[] = {0x7f0f26cc};
const u32 var7f1b2900[] = {0x7f0f26b8};
const u32 var7f1b2904[] = {0x7f0f26cc};
const u32 var7f1b2908[] = {0x7f0f26b0};
const u32 var7f1b290c[] = {0x7f0f26b0};
const u32 var7f1b2910[] = {0x7f0f26b8};
const u32 var7f1b2914[] = {0x7f0f26b0};
const u32 var7f1b2918[] = {0x7f0f26b8};
const u32 var7f1b291c[] = {0x7f0f26b0};
const u32 var7f1b2920[] = {0x7f0f26b8};
const u32 var7f1b2924[] = {0x7f0f26b0};
const u32 var7f1b2928[] = {0x40c90fdb};
const u32 var7f1b292c[] = {0x40f33333};
const u32 var7f1b2930[] = {0x3b03126f};
const u32 var7f1b2934[] = {0x3f7f7cee};
const u32 var7f1b2938[] = {0x3f7f7cee};
const u32 var7f1b293c[] = {0x3b03126f};
const u32 var7f1b2940[] = {0x3b03126f};
const u32 var7f1b2944[] = {0x3b03126f};
const u32 var7f1b2948[] = {0x40490fdb};
const u32 var7f1b294c[] = {0x7f0f74e4};
const u32 var7f1b2950[] = {0x7f0f7500};
const u32 var7f1b2954[] = {0x7f0f7500};
const u32 var7f1b2958[] = {0x7f0f74e4};
const u32 var7f1b295c[] = {0x7f0f74e4};
const u32 var7f1b2960[] = {0x7f0f7500};
const u32 var7f1b2964[] = {0x7f0f7500};
const u32 var7f1b2968[] = {0x7f0f74e4};
const u32 var7f1b296c[] = {0x7f0f74e4};
const u32 var7f1b2970[] = {0x7f0f78a8};
const u32 var7f1b2974[] = {0x7f0f7b00};
const u32 var7f1b2978[] = {0x7f0f7b00};
const u32 var7f1b297c[] = {0x7f0f7e70};
const u32 var7f1b2980[] = {0x7f0f7e70};
const u32 var7f1b2984[] = {0x7f0f7b00};
const u32 var7f1b2988[] = {0x7f0f7e70};
const u32 var7f1b298c[] = {0x7f0f7b00};
const u32 var7f1b2990[] = {0x7f0f78a8};
const u32 var7f1b2994[] = {0x7f0f8464};
const u32 var7f1b2998[] = {0x7f0f8464};
const u32 var7f1b299c[] = {0x7f0f846c};
const u32 var7f1b29a0[] = {0x7f0f846c};
const u32 var7f1b29a4[] = {0x7f0f846c};
const u32 var7f1b29a8[] = {0x7f0f8464};
const u32 var7f1b29ac[] = {0x7f0f8464};
const u32 var7f1b29b0[] = {0x7f0f8464};
const u32 var7f1b29b4[] = {0x7f0f8464};
const u32 var7f1b29b8[] = {0x7f0f8464};
const u32 var7f1b29bc[] = {0x7f0f846c};
const u32 var7f1b29c0[] = {0x7f0f846c};
const u32 var7f1b29c4[] = {0x7f0f8464};
const u32 var7f1b29c8[] = {0x7f0f856c};
const u32 var7f1b29cc[] = {0x7f0f8590};
const u32 var7f1b29d0[] = {0x7f0f8534};
const u32 var7f1b29d4[] = {0x7f0f85b8};
const u32 var7f1b29d8[] = {0x7f0f8590};
const u32 var7f1b29dc[] = {0x7f0f8590};
const u32 var7f1b29e0[] = {0x7f0f85a0};
const u32 var7f1b29e4[] = {0x7f0f85b8};
const u32 var7f1b29e8[] = {0x7f0f8590};
const u32 var7f1b29ec[] = {0x7f0f8544};
const u32 var7f1b29f0[] = {0x7f0f8560};
const u32 var7f1b29f4[] = {0x7f0f85b8};
const u32 var7f1b29f8[] = {0x7f0f8590};
const u32 var7f1b29fc[] = {0xc0490fdb};
const u32 var7f1b2a00[] = {0xc34d8000};
const u32 var7f1b2a04[] = {0x4374b333};
const u32 var7f1b2a08[] = {0x4288999a};
const u32 var7f1b2a0c[] = {0x3dfa0a52};
const u32 var7f1b2a10[] = {0x3c23d70a};
const u32 var7f1b2a14[] = {0x3d2c0831};
const u32 var7f1b2a18[] = {0x3d4ccccd};
const u32 var7f1b2a1c[] = {0x3e4ccccd};
const u32 var7f1b2a20[] = {0x3f4ccccd};
const u32 var7f1b2a24[] = {0x3f4ccccd};
const u32 var7f1b2a28[] = {0x3f4ccccd};
const u32 var7f1b2a2c[] = {0x3dcccccd};
const u32 var7f1b2a30[] = {0x3d23d70a};
const u32 var7f1b2a34[] = {0x3f4ccccd};
const u32 var7f1b2a38[] = {0x3f4ccccd};
const u32 var7f1b2a3c[] = {0x3f4ccccd};
const u32 var7f1b2a40[] = {0x3f333333};
const u32 var7f1b2a44[] = {0x3e99999a};
const u32 var7f1b2a48[] = {0x3f333333};
const u32 var7f1b2a4c[] = {0x3f333333};
const u32 var7f1b2a50[] = {0x3f333333};
const u32 var7f1b2a54[] = {0x3e99999a};
const u32 var7f1b2a58[] = {0x3e99999a};
const u32 var7f1b2a5c[] = {0x3e99999a};
const u32 var7f1b2a60[] = {0x3e4ccccd};
const u32 var7f1b2a64[] = {0x3f4ccccd};
const u32 var7f1b2a68[] = {0x7f0fa6e0};
const u32 var7f1b2a6c[] = {0x7f0fa6e0};
const u32 var7f1b2a70[] = {0x7f0fa6f4};
const u32 var7f1b2a74[] = {0x7f0fa6f4};
const u32 var7f1b2a78[] = {0x7f0fa6e0};
const u32 var7f1b2a7c[] = {0x7f0fa6f4};
const u32 var7f1b2a80[] = {0x7f0fa6f4};
const u32 var7f1b2a84[] = {0x7f0fa6f4};
const u32 var7f1b2a88[] = {0x7f0fa6f4};
const u32 var7f1b2a8c[] = {0x7f0fa6e0};
const u32 var7f1b2a90[] = {0x7f0fa6f4};
const u32 var7f1b2a94[] = {0x7f0fa6e0};
const u32 var7f1b2a98[] = {0x7f0fb414};
const u32 var7f1b2a9c[] = {0x7f0fb414};
const u32 var7f1b2aa0[] = {0x7f0fb33c};
const u32 var7f1b2aa4[] = {0x7f0fb3c4};
const u32 var7f1b2aa8[] = {0x7f0fb414};
const u32 var7f1b2aac[] = {0x7f0fb458};
const u32 var7f1b2ab0[] = {0x7f0fb458};
const u32 var7f1b2ab4[] = {0x7f0fb458};
const u32 var7f1b2ab8[] = {0x7f0fb458};
const u32 var7f1b2abc[] = {0x7f0fb458};
const u32 var7f1b2ac0[] = {0x7f0fb33c};
const u32 var7f1b2ac4[] = {0x7f0fb458};
const u32 var7f1b2ac8[] = {0x7f0fb414};
const u32 var7f1b2acc[] = {0x7f0fb4c8};
const u32 var7f1b2ad0[] = {0x7f0fb5b4};
const u32 var7f1b2ad4[] = {0x7f0fb84c};
const u32 var7f1b2ad8[] = {0x7f0fb978};
const u32 var7f1b2adc[] = {0x7f0fbaf4};
const u32 var7f1b2ae0[] = {0x7f0fbb88};
const u32 var7f1b2ae4[] = {0x7f0fb6b4};
const u32 var7f1b2ae8[] = {0x7f0fb5b4};
const u32 var7f1b2aec[] = {0x7f0fbb40};
const u32 var7f1b2af0[] = {0x3f847ae1};
const u32 var7f1b2af4[] = {0x47ae147b};
const u32 var7f1b2af8[] = {0xc34d8000};
const u32 var7f1b2afc[] = {0x4374b333};
const u32 var7f1b2b00[] = {0x7f0fd38c};
const u32 var7f1b2b04[] = {0x7f0fd370};
const u32 var7f1b2b08[] = {0x7f0fd370};
const u32 var7f1b2b0c[] = {0x7f0fd44c};
const u32 var7f1b2b10[] = {0x7f0fd468};
const u32 var7f1b2b14[] = {0x00000000};
const u32 var7f1b2b18[] = {0x00000000};
const u32 var7f1b2b1c[] = {0x00000000};
const u32 var7f1b2b20[] = {0x00010603};
const u32 var7f1b2b24[] = {0x04070502};
const u32 var7f1b2b28[] = {0x00000000};
const u32 var7f1b2b2c[] = {0x00000000};
const u32 var7f1b2b30[] = {0x00000000};

const char var7f1b2b34[] = "Here is where the activemenu sets favourites\n";
const char var7f1b2b64[] = "slot %d = guntype %d\n";
const char var7f1b2b7c[] = "put it in %d\n";
const char var7f1b2b8c[] = "activemenu: setting up for multiplayer\n";
const char var7f1b2bb4[] = "activemenu: setting up for single player\n";
const char var7f1b2be0[] = "Put guntype %d in slot %d\n";
const char var7f1b2bfc[] = "ActiveMenu: Two or more equipped items of guntype %d\n";
const char var7f1b2c34[] = "FAV: Added gun %d to slot %d\n";
const char var7f1b2c54[] = "";
const char var7f1b2c58[] = "obcol";
const char var7f1b2c60[] = "ibcol";
const char var7f1b2c68[] = "defcol";
const char var7f1b2c70[] = "favcol";
const char var7f1b2c78[] = "pickcol";
const char var7f1b2c80[] = "pickcol2";

const u32 var7f1b2c8c[] = {0x7f0fd724};
const u32 var7f1b2c90[] = {0x7f0fdc60};
const u32 var7f1b2c94[] = {0x7f0fdc60};
const u32 var7f1b2c98[] = {0x7f0fdc60};
const u32 var7f1b2c9c[] = {0x7f0fdc60};
const u32 var7f1b2ca0[] = {0x7f0fd894};
const u32 var7f1b2ca4[] = {0x7f0fd9d8};
const u32 var7f1b2ca8[] = {0x7f0fdc60};
const u32 var7f1b2cac[] = {0x7f0fdc60};
const u32 var7f1b2cb0[] = {0x7f0fdc60};
const u32 var7f1b2cb4[] = {0x7f0fdc60};
const u32 var7f1b2cb8[] = {0x7f0fdc60};
const u32 var7f1b2cbc[] = {0x7f0fdc60};
const u32 var7f1b2cc0[] = {0x7f0fdc60};
const u32 var7f1b2cc4[] = {0x7f0fdc60};
const u32 var7f1b2cc8[] = {0x7f0fdc60};
const u32 var7f1b2ccc[] = {0x7f0fdc60};
const u32 var7f1b2cd0[] = {0x7f0fdc60};
const u32 var7f1b2cd4[] = {0x7f0fd9ec};
const u32 var7f1b2cd8[] = {0x7f0fdc54};
const u32 var7f1b2cdc[] = {0x3e99999a};
const u32 var7f1b2ce0[] = {0x3f8ccccd};
const u32 var7f1b2ce4[] = {0x00000000};
const u32 var7f1b2ce8[] = {0x00000000};
const u32 var7f1b2cec[] = {0x00000000};

GLOBAL_ASM(
glabel func0f0f09f0
/*  f0f09f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f09f4:	44812000 */ 	mtc1	$at,$f4
/*  f0f09f8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0f09fc:	2c81000e */ 	sltiu	$at,$a0,0xe
/*  f0f0a00:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0f0a04:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0f0a08:	00004025 */ 	or	$t0,$zero,$zero
/*  f0f0a0c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f0a10:	10200029 */ 	beqz	$at,.L0f0f0ab8
/*  f0f0a14:	e7a40030 */ 	swc1	$f4,0x30($sp)
/*  f0f0a18:	00047080 */ 	sll	$t6,$a0,0x2
/*  f0f0a1c:	3c017f1b */ 	lui	$at,%hi(var7f1b27c0)
/*  f0f0a20:	002e0821 */ 	addu	$at,$at,$t6
/*  f0f0a24:	8c2e27c0 */ 	lw	$t6,%lo(var7f1b27c0)($at)
/*  f0f0a28:	01c00008 */ 	jr	$t6
/*  f0f0a2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0a30:	10000021 */ 	beqz	$zero,.L0f0f0ab8
/*  f0f0a34:	240305bb */ 	addiu	$v1,$zero,0x5bb
/*  f0f0a38:	1000001f */ 	beqz	$zero,.L0f0f0ab8
/*  f0f0a3c:	240305bc */ 	addiu	$v1,$zero,0x5bc
/*  f0f0a40:	1000001d */ 	beqz	$zero,.L0f0f0ab8
/*  f0f0a44:	24030441 */ 	addiu	$v1,$zero,0x441
/*  f0f0a48:	1000001b */ 	beqz	$zero,.L0f0f0ab8
/*  f0f0a4c:	240305dd */ 	addiu	$v1,$zero,0x5dd
/*  f0f0a50:	3c017f1b */ 	lui	$at,%hi(var7f1b27f8)
/*  f0f0a54:	c42627f8 */ 	lwc1	$f6,%lo(var7f1b27f8)($at)
/*  f0f0a58:	34038040 */ 	dli	$v1,0x8040
/*  f0f0a5c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f0a60:	10000015 */ 	beqz	$zero,.L0f0f0ab8
/*  f0f0a64:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f0f0a68:	10000013 */ 	beqz	$zero,.L0f0f0ab8
/*  f0f0a6c:	34038098 */ 	dli	$v1,0x8098
/*  f0f0a70:	10000011 */ 	beqz	$zero,.L0f0f0ab8
/*  f0f0a74:	240305dd */ 	addiu	$v1,$zero,0x5dd
/*  f0f0a78:	1000000f */ 	beqz	$zero,.L0f0f0ab8
/*  f0f0a7c:	2403043e */ 	addiu	$v1,$zero,0x43e
/*  f0f0a80:	1000000d */ 	beqz	$zero,.L0f0f0ab8
/*  f0f0a84:	2403043e */ 	addiu	$v1,$zero,0x43e
/*  f0f0a88:	3c014060 */ 	lui	$at,0x4060
/*  f0f0a8c:	44814000 */ 	mtc1	$at,$f8
/*  f0f0a90:	240300ea */ 	addiu	$v1,$zero,0xea
/*  f0f0a94:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f0a98:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0f0a9c:	10000006 */ 	beqz	$zero,.L0f0f0ab8
/*  f0f0aa0:	e7a80030 */ 	swc1	$f8,0x30($sp)
/*  f0f0aa4:	3c017f1b */ 	lui	$at,%hi(var7f1b27fc)
/*  f0f0aa8:	c42a27fc */ 	lwc1	$f10,%lo(var7f1b27fc)($at)
/*  f0f0aac:	2403002b */ 	addiu	$v1,$zero,0x2b
/*  f0f0ab0:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f0ab4:	e7aa0030 */ 	swc1	$f10,0x30($sp)
.L0f0f0ab8:
/*  f0f0ab8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f0abc:	10610030 */ 	beq	$v1,$at,.L0f0f0b80
/*  f0f0ac0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f0ac4:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f0f0ac8:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f0f0acc:	0c012230 */ 	jal	func000488c0
/*  f0f0ad0:	afa80038 */ 	sw	$t0,0x38($sp)
/*  f0f0ad4:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*  f0f0ad8:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f0f0adc:	0c012230 */ 	jal	func000488c0
/*  f0f0ae0:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
/*  f0f0ae4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f0ae8:	0c01210c */ 	jal	func00048430
/*  f0f0aec:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f0f0af0:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0f0af4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f0af8:	44818000 */ 	mtc1	$at,$f16
/*  f0f0afc:	00032c00 */ 	sll	$a1,$v1,0x10
/*  f0f0b00:	00057c03 */ 	sra	$t7,$a1,0x10
/*  f0f0b04:	3c048009 */ 	lui	$a0,0x8009
/*  f0f0b08:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0f0b0c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f0b10:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0f0b14:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0f0b18:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0f0b1c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f0b20:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0f0b24:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0f0b28:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f0b2c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0f0b30:	0c004241 */ 	jal	func00010904
/*  f0f0b34:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f0f0b38:	8fa80038 */ 	lw	$t0,0x38($sp)
/*  f0f0b3c:	10400007 */ 	beqz	$v0,.L0f0f0b5c
/*  f0f0b40:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f0b44:	11000005 */ 	beqz	$t0,.L0f0f0b5c
/*  f0f0b48:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f0f0b4c:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f0f0b50:	0c00cf94 */ 	jal	func00033e50
/*  f0f0b54:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f0f0b58:	8fa4002c */ 	lw	$a0,0x2c($sp)
.L0f0f0b5c:
/*  f0f0b5c:	10800005 */ 	beqz	$a0,.L0f0f0b74
/*  f0f0b60:	8faa0034 */ 	lw	$t2,0x34($sp)
/*  f0f0b64:	11400003 */ 	beqz	$t2,.L0f0f0b74
/*  f0f0b68:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0f0b6c:	0c00cf94 */ 	jal	func00033e50
/*  f0f0b70:	24064000 */ 	addiu	$a2,$zero,0x4000
.L0f0f0b74:
/*  f0f0b74:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f0b78:	0c01210c */ 	jal	func00048430
/*  f0f0b7c:	8fa50028 */ 	lw	$a1,0x28($sp)
.L0f0f0b80:
/*  f0f0b80:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f0b84:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0f0b88:	03e00008 */ 	jr	$ra
/*  f0f0b8c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f0b90
/*  f0f0b90:	3c02800a */ 	lui	$v0,0x800a
/*  f0f0b94:	8c4219c4 */ 	lw	$v0,0x19c4($v0)
/*  f0f0b98:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f0b9c:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f0ba0:	10410005 */ 	beq	$v0,$at,.L0f0f0bb8
/*  f0f0ba4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f0ba8:	1041000b */ 	beq	$v0,$at,.L0f0f0bd8
/*  f0f0bac:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f0bb0:	5441000c */ 	bnel	$v0,$at,.L0f0f0be4
/*  f0f0bb4:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f0bb8:
/*  f0f0bb8:	8dcea474 */ 	lw	$t6,-0x5b8c($t6)
/*  f0f0bbc:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0f0bc0:	15c10003 */ 	bne	$t6,$at,.L0f0f0bd0
/*  f0f0bc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0bc8:	03e00008 */ 	jr	$ra
/*  f0f0bcc:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f0bd0:
/*  f0f0bd0:	03e00008 */ 	jr	$ra
/*  f0f0bd4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f0bd8:
/*  f0f0bd8:	03e00008 */ 	jr	$ra
/*  f0f0bdc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0f0be0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f0be4:
/*  f0f0be4:	03e00008 */ 	jr	$ra
/*  f0f0be8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f0bec
/*  f0f0bec:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f0bf0:	8dcea248 */ 	lw	$t6,-0x5db8($t6)
/*  f0f0bf4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0f0bf8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f0bfc:	8dc30070 */ 	lw	$v1,0x70($t6)
/*  f0f0c00:	0fc3c2e4 */ 	jal	func0f0f0b90
/*  f0f0c04:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0f0c08:	10400012 */ 	beqz	$v0,.L0f0f0c54
/*  f0f0c0c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0f0c10:	28610004 */ 	slti	$at,$v1,0x4
/*  f0f0c14:	14200002 */ 	bnez	$at,.L0f0f0c20
/*  f0f0c18:	3c18800a */ 	lui	$t8,0x800a
/*  f0f0c1c:	2463fffc */ 	addiu	$v1,$v1,-4
.L0f0f0c20:
/*  f0f0c20:	000378c0 */ 	sll	$t7,$v1,0x3
/*  f0f0c24:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f0f0c28:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f0c2c:	01e37821 */ 	addu	$t7,$t7,$v1
/*  f0f0c30:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f0c34:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f0f0c38:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f0c3c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f0c40:	8f18e4f8 */ 	lw	$t8,-0x1b08($t8)
/*  f0f0c44:	53000004 */ 	beqzl	$t8,.L0f0f0c58
/*  f0f0c48:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f0c4c:	10000002 */ 	beqz	$zero,.L0f0f0c58
/*  f0f0c50:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f0c54:
/*  f0f0c54:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f0c58:
/*  f0f0c58:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f0c5c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0f0c60:	03e00008 */ 	jr	$ra
/*  f0f0c64:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f0c68
/*  f0f0c68:	3c02800a */ 	lui	$v0,%hi(var800a19c0)
/*  f0f0c6c:	244219c0 */ 	addiu	$v0,$v0,%lo(var800a19c0)
/*  f0f0c70:	904e0014 */ 	lbu	$t6,0x14($v0)
/*  f0f0c74:	15c00006 */ 	bnez	$t6,.L0f0f0c90
/*  f0f0c78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0c7c:	904f0015 */ 	lbu	$t7,0x15($v0)
/*  f0f0c80:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0f0c84:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0f0c88:	11e10003 */ 	beq	$t7,$at,.L0f0f0c98
/*  f0f0c8c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f0c90:
/*  f0f0c90:	03e00008 */ 	jr	$ra
/*  f0f0c94:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f0c98:
/*  f0f0c98:	03e00008 */ 	jr	$ra
/*  f0f0c9c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f0ca0
/*  f0f0ca0:	10a00004 */ 	beqz	$a1,.L0f0f0cb4
/*  f0f0ca4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f0ca8:	3c01800a */ 	lui	$at,0x800a
/*  f0f0cac:	03e00008 */ 	jr	$ra
/*  f0f0cb0:	a02419db */ 	sb	$a0,0x19db($at)
.L0f0f0cb4:
/*  f0f0cb4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0f0cb8:	3c01800a */ 	lui	$at,0x800a
/*  f0f0cbc:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f0cc0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f0cc4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f0cc8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f0ccc:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f0cd0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f0cd4:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f0cd8:	002f0821 */ 	addu	$at,$at,$t7
/*  f0f0cdc:	a024edf8 */ 	sb	$a0,-0x1208($at)
/*  f0f0ce0:	03e00008 */ 	jr	$ra
/*  f0f0ce4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f0ce8
/*  f0f0ce8:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0f0cec:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f0f0cf0:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0f0cf4:	3c038008 */ 	lui	$v1,0x8008
/*  f0f0cf8:	3c088008 */ 	lui	$t0,0x8008
/*  f0f0cfc:	00808825 */ 	or	$s1,$a0,$zero
/*  f0f0d00:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f0d04:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0f0d08:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f0f0d0c:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f0f0d10:	afa7009c */ 	sw	$a3,0x9c($sp)
/*  f0f0d14:	8c63fb10 */ 	lw	$v1,-0x4f0($v1)
/*  f0f0d18:	11c00005 */ 	beqz	$t6,.L0f0f0d30
/*  f0f0d1c:	8d08fb0c */ 	lw	$t0,-0x4f4($t0)
/*  f0f0d20:	3c038008 */ 	lui	$v1,0x8008
/*  f0f0d24:	3c088008 */ 	lui	$t0,0x8008
/*  f0f0d28:	8c63fb18 */ 	lw	$v1,-0x4e8($v1)
/*  f0f0d2c:	8d08fb14 */ 	lw	$t0,-0x4ec($t0)
.L0f0f0d30:
/*  f0f0d30:	8faf0098 */ 	lw	$t7,0x98($sp)
/*  f0f0d34:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0f0d38:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*  f0f0d3c:	3c0b8007 */ 	lui	$t3,%hi(var8007144c)
/*  f0f0d40:	01f83021 */ 	addu	$a2,$t7,$t8
/*  f0f0d44:	256b144c */ 	addiu	$t3,$t3,%lo(var8007144c)
/*  f0f0d48:	00095040 */ 	sll	$t2,$t1,0x1
/*  f0f0d4c:	04c10003 */ 	bgez	$a2,.L0f0f0d5c
/*  f0f0d50:	0006c843 */ 	sra	$t9,$a2,0x1
/*  f0f0d54:	24c10001 */ 	addiu	$at,$a2,0x1
/*  f0f0d58:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f0d5c:
/*  f0f0d5c:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f0f0d60:	94440000 */ 	lhu	$a0,0x0($v0)
/*  f0f0d64:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0f0d68:	afb90084 */ 	sw	$t9,0x84($sp)
/*  f0f0d6c:	afa30064 */ 	sw	$v1,0x64($sp)
/*  f0f0d70:	0fc5b9f1 */ 	jal	langGet
/*  f0f0d74:	afa80060 */ 	sw	$t0,0x60($sp)
/*  f0f0d78:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0f0d7c:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f0f0d80:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0f0d84:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f0d88:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0f0d8c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f0d90:	0fc55cbe */ 	jal	func0f1572f8
/*  f0f0d94:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f0d98:	0fc5b9f1 */ 	jal	langGet
/*  f0f0d9c:	240451ef */ 	addiu	$a0,$zero,0x51ef
/*  f0f0da0:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0f0da4:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0f0da8:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f0dac:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f0db0:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0f0db4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f0db8:	0fc55cbe */ 	jal	func0f1572f8
/*  f0f0dbc:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0f0dc0:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0f0dc4:	240151eb */ 	addiu	$at,$zero,0x51eb
/*  f0f0dc8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f0dcc:	95cf0000 */ 	lhu	$t7,0x0($t6)
/*  f0f0dd0:	55e10005 */ 	bnel	$t7,$at,.L0f0f0de8
/*  f0f0dd4:	8fa2007c */ 	lw	$v0,0x7c($sp)
/*  f0f0dd8:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f0f0ddc:	27190007 */ 	addiu	$t9,$t8,0x7
/*  f0f0de0:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f0f0de4:	8fa2007c */ 	lw	$v0,0x7c($sp)
.L0f0f0de8:
/*  f0f0de8:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f0f0dec:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f0df0:	2405007f */ 	addiu	$a1,$zero,0x7f
/*  f0f0df4:	00434821 */ 	addu	$t1,$v0,$v1
/*  f0f0df8:	05210003 */ 	bgez	$t1,.L0f0f0e08
/*  f0f0dfc:	00095043 */ 	sra	$t2,$t1,0x1
/*  f0f0e00:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f0e04:	00015043 */ 	sra	$t2,$at,0x1
.L0f0f0e08:
/*  f0f0e08:	00ca3023 */ 	subu	$a2,$a2,$t2
/*  f0f0e0c:	00c26021 */ 	addu	$t4,$a2,$v0
/*  f0f0e10:	01836821 */ 	addu	$t5,$t4,$v1
/*  f0f0e14:	24cbfffc */ 	addiu	$t3,$a2,-4
/*  f0f0e18:	25ae0007 */ 	addiu	$t6,$t5,0x7
/*  f0f0e1c:	afa60080 */ 	sw	$a2,0x80($sp)
/*  f0f0e20:	afab006c */ 	sw	$t3,0x6c($sp)
/*  f0f0e24:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0f0e28:	0fc54df7 */ 	jal	func0f1537dc
/*  f0f0e2c:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f0e30:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0f0e34:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f0f0e38:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0f0e3c:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f0f0e40:	8fac00a0 */ 	lw	$t4,0xa0($sp)
/*  f0f0e44:	3c10f600 */ 	lui	$s0,0xf600
/*  f0f0e48:	01f80019 */ 	multu	$t7,$t8
/*  f0f0e4c:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f0f0e50:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0f0e54:	8fb1006c */ 	lw	$s1,0x6c($sp)
/*  f0f0e58:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0f0e5c:	0000c812 */ 	mflo	$t9
/*  f0f0e60:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f0f0e64:	00095380 */ 	sll	$t2,$t1,0xe
/*  f0f0e68:	01505825 */ 	or	$t3,$t2,$s0
/*  f0f0e6c:	016e7825 */ 	or	$t7,$t3,$t6
/*  f0f0e70:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0f0e74:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f0e78:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f0f0e7c:	8fad0098 */ 	lw	$t5,0x98($sp)
/*  f0f0e80:	03190019 */ 	multu	$t8,$t9
/*  f0f0e84:	31ab03ff */ 	andi	$t3,$t5,0x3ff
/*  f0f0e88:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0f0e8c:	00004812 */ 	mflo	$t1
/*  f0f0e90:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0f0e94:	000a6380 */ 	sll	$t4,$t2,0xe
/*  f0f0e98:	018e7825 */ 	or	$t7,$t4,$t6
/*  f0f0e9c:	0fc54e0e */ 	jal	func0f153838
/*  f0f0ea0:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0f0ea4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f0ea8:	0fc54df7 */ 	jal	func0f1537dc
/*  f0f0eac:	24057f7f */ 	addiu	$a1,$zero,0x7f7f
/*  f0f0eb0:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0f0eb4:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f0f0eb8:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f0ebc:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0f0ec0:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f0ec4:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0f0ec8:	03190019 */ 	multu	$t8,$t9
/*  f0f0ecc:	318e03ff */ 	andi	$t6,$t4,0x3ff
/*  f0f0ed0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0f0ed4:	322e03ff */ 	andi	$t6,$s1,0x3ff
/*  f0f0ed8:	00004812 */ 	mflo	$t1
/*  f0f0edc:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0f0ee0:	000a6b80 */ 	sll	$t5,$t2,0xe
/*  f0f0ee4:	01b05825 */ 	or	$t3,$t5,$s0
/*  f0f0ee8:	016fc025 */ 	or	$t8,$t3,$t7
/*  f0f0eec:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0f0ef0:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f0f0ef4:	8fb90094 */ 	lw	$t9,0x94($sp)
/*  f0f0ef8:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f0f0efc:	03290019 */ 	multu	$t9,$t1
/*  f0f0f00:	00005012 */ 	mflo	$t2
/*  f0f0f04:	314d03ff */ 	andi	$t5,$t2,0x3ff
/*  f0f0f08:	000d6380 */ 	sll	$t4,$t5,0xe
/*  f0f0f0c:	018b7825 */ 	or	$t7,$t4,$t3
/*  f0f0f10:	0fc54e0e */ 	jal	func0f153838
/*  f0f0f14:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0f0f18:	3c057f7f */ 	lui	$a1,0x7f7f
/*  f0f0f1c:	34a5ff7f */ 	ori	$a1,$a1,0xff7f
/*  f0f0f20:	0fc54df7 */ 	jal	func0f1537dc
/*  f0f0f24:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f0f28:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0f0f2c:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f0f0f30:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f0f34:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0f0f38:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f0f3c:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f0f0f40:	03190019 */ 	multu	$t8,$t9
/*  f0f0f44:	258b0004 */ 	addiu	$t3,$t4,0x4
/*  f0f0f48:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f0f0f4c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0f0f50:	00004812 */ 	mflo	$t1
/*  f0f0f54:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0f0f58:	000a6b80 */ 	sll	$t5,$t2,0xe
/*  f0f0f5c:	01b07025 */ 	or	$t6,$t5,$s0
/*  f0f0f60:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0f0f64:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0f0f68:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0f0f6c:	8fa90094 */ 	lw	$t1,0x94($sp)
/*  f0f0f70:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0f0f74:	012a0019 */ 	multu	$t1,$t2
/*  f0f0f78:	25ee0002 */ 	addiu	$t6,$t7,0x2
/*  f0f0f7c:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0f0f80:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f0f84:	00006812 */ 	mflo	$t5
/*  f0f0f88:	31ac03ff */ 	andi	$t4,$t5,0x3ff
/*  f0f0f8c:	000c5b80 */ 	sll	$t3,$t4,0xe
/*  f0f0f90:	01794825 */ 	or	$t1,$t3,$t9
/*  f0f0f94:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f0f0f98:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0f0f9c:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f0f0fa0:	262bfffe */ 	addiu	$t3,$s1,-2
/*  f0f0fa4:	317903ff */ 	andi	$t9,$t3,0x3ff
/*  f0f0fa8:	014d0019 */ 	multu	$t2,$t5
/*  f0f0fac:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0f0fb0:	2639fffc */ 	addiu	$t9,$s1,-4
/*  f0f0fb4:	00006012 */ 	mflo	$t4
/*  f0f0fb8:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f0f0fbc:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0f0fc0:	01d0c025 */ 	or	$t8,$t6,$s0
/*  f0f0fc4:	03095025 */ 	or	$t2,$t8,$t1
/*  f0f0fc8:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f0f0fcc:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0f0fd0:	8fad0094 */ 	lw	$t5,0x94($sp)
/*  f0f0fd4:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0f0fd8:	00184880 */ 	sll	$t1,$t8,0x2
/*  f0f0fdc:	01ac0019 */ 	multu	$t5,$t4
/*  f0f0fe0:	00007812 */ 	mflo	$t7
/*  f0f0fe4:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0f0fe8:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f0f0fec:	01695025 */ 	or	$t2,$t3,$t1
/*  f0f0ff0:	0fc54e0e */ 	jal	func0f153838
/*  f0f0ff4:	ac4a000c */ 	sw	$t2,0xc($v0)
/*  f0f0ff8:	0fc54d8a */ 	jal	func0f153628
/*  f0f0ffc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f1000:	8fad0094 */ 	lw	$t5,0x94($sp)
/*  f0f1004:	8fac00ac */ 	lw	$t4,0xac($sp)
/*  f0f1008:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0f100c:	8fb800b0 */ 	lw	$t8,0xb0($sp)
/*  f0f1010:	01ac7821 */ 	addu	$t7,$t5,$t4
/*  f0f1014:	01eec821 */ 	addu	$t9,$t7,$t6
/*  f0f1018:	03381823 */ 	subu	$v1,$t9,$t8
/*  f0f101c:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0f1020:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f1024:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0f1028:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f102c:	04610003 */ 	bgez	$v1,.L0f0f103c
/*  f0f1030:	00035843 */ 	sra	$t3,$v1,0x1
/*  f0f1034:	24610001 */ 	addiu	$at,$v1,0x1
/*  f0f1038:	00015843 */ 	sra	$t3,$at,0x1
.L0f0f103c:
/*  f0f103c:	01601825 */ 	or	$v1,$t3,$zero
/*  f0f1040:	05210003 */ 	bgez	$t1,.L0f0f1050
/*  f0f1044:	00095043 */ 	sra	$t2,$t1,0x1
/*  f0f1048:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f104c:	00015043 */ 	sra	$t2,$at,0x1
.L0f0f1050:
/*  f0f1050:	006a6823 */ 	subu	$t5,$v1,$t2
/*  f0f1054:	25ac0002 */ 	addiu	$t4,$t5,0x2
/*  f0f1058:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0f105c:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f0f1060:	95e40000 */ 	lhu	$a0,0x0($t7)
/*  f0f1064:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f1068:	0fc5b9f1 */ 	jal	langGet
/*  f0f106c:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0f1070:	0c002f02 */ 	jal	func0000bc08
/*  f0f1074:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1078:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f107c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f1080:	0c002f02 */ 	jal	func0000bc08
/*  f0f1084:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0f1088:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0f108c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0f1090:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f0f1094:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f1098:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f109c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f10a0:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f10a4:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f10a8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f10ac:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f10b0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f10b4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f10b8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f10bc:	0fc5580f */ 	jal	func0f15603c
/*  f0f10c0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f10c4:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0f10c8:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f0f10cc:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f10d0:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f10d4:	05410003 */ 	bgez	$t2,.L0f0f10e4
/*  f0f10d8:	000a6843 */ 	sra	$t5,$t2,0x1
/*  f0f10dc:	25410001 */ 	addiu	$at,$t2,0x1
/*  f0f10e0:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f10e4:
/*  f0f10e4:	012d6023 */ 	subu	$t4,$t1,$t5
/*  f0f10e8:	258f0002 */ 	addiu	$t7,$t4,0x2
/*  f0f10ec:	24c60003 */ 	addiu	$a2,$a2,0x3
/*  f0f10f0:	afaf0088 */ 	sw	$t7,0x88($sp)
/*  f0f10f4:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f10f8:	0fc5b9f1 */ 	jal	langGet
/*  f0f10fc:	240451ef */ 	addiu	$a0,$zero,0x51ef
/*  f0f1100:	0c002f02 */ 	jal	func0000bc08
/*  f0f1104:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1108:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f110c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f1110:	0c002f02 */ 	jal	func0000bc08
/*  f0f1114:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0f1118:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0f111c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0f1120:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f0f1124:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f1128:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f112c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f1130:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f1134:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f1138:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f113c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f1140:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1144:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f1148:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f114c:	0fc5580f */ 	jal	func0f15603c
/*  f0f1150:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f1154:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0f1158:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f0f115c:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0f1160:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0f1164:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f1168:	05210003 */ 	bgez	$t1,.L0f0f1178
/*  f0f116c:	00096843 */ 	sra	$t5,$t1,0x1
/*  f0f1170:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f1174:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f1178:
/*  f0f1178:	014d6023 */ 	subu	$t4,$t2,$t5
/*  f0f117c:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0f1180:	95e40000 */ 	lhu	$a0,0x0($t7)
/*  f0f1184:	0fc5b9f1 */ 	jal	langGet
/*  f0f1188:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f118c:	0c002f02 */ 	jal	func0000bc08
/*  f0f1190:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1194:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f1198:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f119c:	0c002f02 */ 	jal	func0000bc08
/*  f0f11a0:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0f11a4:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0f11a8:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0f11ac:	3c0bbfbf */ 	lui	$t3,0xbfbf
/*  f0f11b0:	356bffff */ 	ori	$t3,$t3,0xffff
/*  f0f11b4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f11b8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f11bc:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f11c0:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f11c4:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f11c8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f11cc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f11d0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f11d4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f11d8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f11dc:	0fc5580f */ 	jal	func0f15603c
/*  f0f11e0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f11e4:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0f11e8:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f11ec:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f0f11f0:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f11f4:	05410003 */ 	bgez	$t2,.L0f0f1204
/*  f0f11f8:	000a6843 */ 	sra	$t5,$t2,0x1
/*  f0f11fc:	25410001 */ 	addiu	$at,$t2,0x1
/*  f0f1200:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f1204:
/*  f0f1204:	24c60003 */ 	addiu	$a2,$a2,0x3
/*  f0f1208:	012d6023 */ 	subu	$t4,$t1,$t5
/*  f0f120c:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0f1210:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f1214:	0fc5b9f1 */ 	jal	langGet
/*  f0f1218:	240451ef */ 	addiu	$a0,$zero,0x51ef
/*  f0f121c:	0c002f02 */ 	jal	func0000bc08
/*  f0f1220:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1224:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f1228:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0f122c:	0c002f02 */ 	jal	func0000bc08
/*  f0f1230:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0f1234:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f0f1238:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0f123c:	3c18bfbf */ 	lui	$t8,0xbfbf
/*  f0f1240:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f0f1244:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f1248:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f124c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f1250:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f1254:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f1258:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f125c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f1260:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1264:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f1268:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f126c:	0fc5580f */ 	jal	func0f15603c
/*  f0f1270:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f1274:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f0f1278:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0f127c:	240151eb */ 	addiu	$at,$zero,0x51eb
/*  f0f1280:	956a0000 */ 	lhu	$t2,0x0($t3)
/*  f0f1284:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f1288:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0f128c:	15410023 */ 	bne	$t2,$at,.L0f0f131c
/*  f0f1290:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f0f1294:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f0f1298:	05210003 */ 	bgez	$t1,.L0f0f12a8
/*  f0f129c:	00096843 */ 	sra	$t5,$t1,0x1
/*  f0f12a0:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f12a4:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f12a8:
/*  f0f12a8:	01ac7821 */ 	addu	$t7,$t5,$t4
/*  f0f12ac:	25eefff9 */ 	addiu	$t6,$t7,-7
/*  f0f12b0:	afae0088 */ 	sw	$t6,0x88($sp)
/*  f0f12b4:	0c002f02 */ 	jal	func0000bc08
/*  f0f12b8:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f12bc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f12c0:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0f12c4:	0c002f02 */ 	jal	func0000bc08
/*  f0f12c8:	03208025 */ 	or	$s0,$t9,$zero
/*  f0f12cc:	3c188008 */ 	lui	$t8,0x8008
/*  f0f12d0:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0f12d4:	8d6bfb04 */ 	lw	$t3,-0x4fc($t3)
/*  f0f12d8:	8f18fb08 */ 	lw	$t8,-0x4f8($t8)
/*  f0f12dc:	3c0abfbf */ 	lui	$t2,0xbfbf
/*  f0f12e0:	354affff */ 	ori	$t2,$t2,0xffff
/*  f0f12e4:	3c077f1b */ 	lui	$a3,%hi(var7f1b23e8)
/*  f0f12e8:	24e723e8 */ 	addiu	$a3,$a3,%lo(var7f1b23e8)
/*  f0f12ec:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0f12f0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f12f4:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f12f8:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f12fc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f1300:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f1304:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1308:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f130c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f1310:	0fc5580f */ 	jal	func0f15603c
/*  f0f1314:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f1318:	00408825 */ 	or	$s1,$v0,$zero
.L0f0f131c:
/*  f0f131c:	0fc54de0 */ 	jal	func0f153780
/*  f0f1320:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f1324:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f1328:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0f132c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0f1330:	03e00008 */ 	jr	$ra
/*  f0f1334:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0f0f1338
/*  f0f1338:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f133c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0f1340:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0f1344:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0f1348:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f134c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f1350:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f1354:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f1358:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f135c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f1360:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f1364:	01f82821 */ 	addu	$a1,$t7,$t8
/*  f0f1368:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f136c:	24020020 */ 	addiu	$v0,$zero,0x20
.L0f0f1370:
/*  f0f1370:	8cb90dfc */ 	lw	$t9,0xdfc($a1)
/*  f0f1374:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f0f1378:	14990003 */ 	bne	$a0,$t9,.L0f0f1388
/*  f0f137c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1380:	03e00008 */ 	jr	$ra
/*  f0f1384:	24a20dfc */ 	addiu	$v0,$a1,0xdfc
.L0f0f1388:
/*  f0f1388:	1462fff9 */ 	bne	$v1,$v0,.L0f0f1370
/*  f0f138c:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0f1390:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f1394:	03e00008 */ 	jr	$ra
/*  f0f1398:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f139c
/*  f0f139c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f13a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f13a4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0f13a8:	0fc3c4ce */ 	jal	func0f0f1338
/*  f0f13ac:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0f13b0:	10400003 */ 	beqz	$v0,.L0f0f13c0
/*  f0f13b4:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*  f0f13b8:	10000008 */ 	beqz	$zero,.L0f0f13dc
/*  f0f13bc:	e4440004 */ 	swc1	$f4,0x4($v0)
.L0f0f13c0:
/*  f0f13c0:	0fc3c4ce */ 	jal	func0f0f1338
/*  f0f13c4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f13c8:	10400004 */ 	beqz	$v0,.L0f0f13dc
/*  f0f13cc:	8fae0018 */ 	lw	$t6,0x18($sp)
/*  f0f13d0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0f13d4:	c7a6001c */ 	lwc1	$f6,0x1c($sp)
/*  f0f13d8:	e4460004 */ 	swc1	$f6,0x4($v0)
.L0f0f13dc:
/*  f0f13dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f13e0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f13e4:	03e00008 */ 	jr	$ra
/*  f0f13e8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f13ec
/*  f0f13ec:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f13f0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f13f4:	0fc3c4ce */ 	jal	func0f0f1338
/*  f0f13f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f13fc:	50400003 */ 	beqzl	$v0,.L0f0f140c
/*  f0f1400:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f1404:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f0f1408:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f140c:
/*  f0f140c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f1410:	03e00008 */ 	jr	$ra
/*  f0f1414:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f1418
/*  f0f1418:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f141c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0f1420:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0f1424:	3c014270 */ 	lui	$at,0x4270
/*  f0f1428:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f142c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f1430:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f1434:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f1438:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f143c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f1440:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f1444:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0f1448:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0f144c:	44810000 */ 	mtc1	$at,$f0
/*  f0f1450:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0f1454:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f0f1458:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f145c:	24050020 */ 	addiu	$a1,$zero,0x20
.L0f0f1460:
/*  f0f1460:	8c990dfc */ 	lw	$t9,0xdfc($a0)
/*  f0f1464:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f0f1468:	13200006 */ 	beqz	$t9,.L0f0f1484
/*  f0f146c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1470:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f0f1474:	c4840e00 */ 	lwc1	$f4,0xe00($a0)
/*  f0f1478:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0f147c:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0f1480:	e48a0e00 */ 	swc1	$f10,0xe00($a0)
.L0f0f1484:
/*  f0f1484:	1465fff6 */ 	bne	$v1,$a1,.L0f0f1460
/*  f0f1488:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f148c:	03e00008 */ 	jr	$ra
/*  f0f1490:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f1494
/*  f0f1494:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f1498:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0f149c:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0f14a0:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0f14a4:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f14a8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f14ac:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f14b0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f14b4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f14b8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f14bc:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f14c0:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f0f14c4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f14c8:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f0f14cc:
/*  f0f14cc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f14d0:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f0f14d4:	1444fffd */ 	bne	$v0,$a0,.L0f0f14cc
/*  f0f14d8:	ac600df4 */ 	sw	$zero,0xdf4($v1)
/*  f0f14dc:	03e00008 */ 	jr	$ra
/*  f0f14e0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f14e4
/*  f0f14e4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f14e8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f14ec:	14800003 */ 	bnez	$a0,.L0f0f14fc
/*  f0f14f0:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f14f4:	10000015 */ 	beqz	$zero,.L0f0f154c
/*  f0f14f8:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f14fc:
/*  f0f14fc:	2cc15a00 */ 	sltiu	$at,$a2,0x5a00
/*  f0f1500:	10200005 */ 	beqz	$at,.L0f0f1518
/*  f0f1504:	3c0e7f1a */ 	lui	$t6,0x7f1a
/*  f0f1508:	0fc5b9f1 */ 	jal	langGet
/*  f0f150c:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0f1510:	1000000f */ 	beqz	$zero,.L0f0f1550
/*  f0f1514:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f1518:
/*  f0f1518:	25ce78b0 */ 	addiu	$t6,$t6,0x78b0
/*  f0f151c:	01c6082b */ 	sltu	$at,$t6,$a2
/*  f0f1520:	10200003 */ 	beqz	$at,.L0f0f1530
/*  f0f1524:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1528:	10000008 */ 	beqz	$zero,.L0f0f154c
/*  f0f152c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f1530:
/*  f0f1530:	10c00005 */ 	beqz	$a2,.L0f0f1548
/*  f0f1534:	3c027f1b */ 	lui	$v0,%hi(var7f1b23ec)
/*  f0f1538:	00c0f809 */ 	jalr	$a2
/*  f0f153c:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0f1540:	10000003 */ 	beqz	$zero,.L0f0f1550
/*  f0f1544:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f1548:
/*  f0f1548:	244223ec */ 	addiu	$v0,$v0,%lo(var7f1b23ec)
.L0f0f154c:
/*  f0f154c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f1550:
/*  f0f1550:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f1554:	03e00008 */ 	jr	$ra
/*  f0f1558:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f155c
/*  f0f155c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f1560:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f1564:	00802825 */ 	or	$a1,$a0,$zero
/*  f0f1568:	0fc3c539 */ 	jal	func0f0f14e4
/*  f0f156c:	8c840008 */ 	lw	$a0,0x8($a0)
/*  f0f1570:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f1574:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f1578:	03e00008 */ 	jr	$ra
/*  f0f157c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f1580
/*  f0f1580:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f1584:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f1588:	00802825 */ 	or	$a1,$a0,$zero
/*  f0f158c:	0fc3c539 */ 	jal	func0f0f14e4
/*  f0f1590:	8c840004 */ 	lw	$a0,0x4($a0)
/*  f0f1594:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f1598:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f159c:	03e00008 */ 	jr	$ra
/*  f0f15a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f15a4
/*  f0f15a4:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0f15a8:	25cffffe */ 	addiu	$t7,$t6,-2
/*  f0f15ac:	2de10018 */ 	sltiu	$at,$t7,0x18
/*  f0f15b0:	10200017 */ 	beqz	$at,.L0f0f1610
/*  f0f15b4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f15b8:	3c017f1b */ 	lui	$at,%hi(var7f1b2800)
/*  f0f15bc:	002f0821 */ 	addu	$at,$at,$t7
/*  f0f15c0:	8c2f2800 */ 	lw	$t7,%lo(var7f1b2800)($at)
/*  f0f15c4:	01e00008 */ 	jr	$t7
/*  f0f15c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f15cc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f15d0:	03e00008 */ 	jr	$ra
/*  f0f15d4:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f0f15d8:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0f15dc:	03e00008 */ 	jr	$ra
/*  f0f15e0:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f0f15e4:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f0f15e8:	03e00008 */ 	jr	$ra
/*  f0f15ec:	aca80000 */ 	sw	$t0,0x0($a1)
/*  f0f15f0:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f0f15f4:	03e00008 */ 	jr	$ra
/*  f0f15f8:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f0f15fc:	240a0005 */ 	addiu	$t2,$zero,0x5
/*  f0f1600:	03e00008 */ 	jr	$ra
/*  f0f1604:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f0f1608:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f0f160c:	acab0000 */ 	sw	$t3,0x0($a1)
.L0f0f1610:
/*  f0f1610:	03e00008 */ 	jr	$ra
/*  f0f1614:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f1618
/*  f0f1618:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f0f161c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0f1620:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0f1624:	8dcefb10 */ 	lw	$t6,-0x4f0($t6)
/*  f0f1628:	8deffb0c */ 	lw	$t7,-0x4f4($t7)
/*  f0f162c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f1630:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0f1634:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0f1638:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0f163c:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0f1640:	afaf0064 */ 	sw	$t7,0x64($sp)
/*  f0f1644:	8c820010 */ 	lw	$v0,0x10($a0)
/*  f0f1648:	00808025 */ 	or	$s0,$a0,$zero
/*  f0f164c:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0f1650:	1040000e */ 	beqz	$v0,.L0f0f168c
/*  f0f1654:	00c09025 */ 	or	$s2,$a2,$zero
/*  f0f1658:	8c980004 */ 	lw	$t8,0x4($a0)
/*  f0f165c:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f0f1660:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f1664:	33190004 */ 	andi	$t9,$t8,0x4
/*  f0f1668:	17200008 */ 	bnez	$t9,.L0f0f168c
/*  f0f166c:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0f1670:	0040f809 */ 	jalr	$v0
/*  f0f1674:	afa70084 */ 	sw	$a3,0x84($sp)
/*  f0f1678:	10400004 */ 	beqz	$v0,.L0f0f168c
/*  f0f167c:	8fa70084 */ 	lw	$a3,0x84($sp)
/*  f0f1680:	a6200000 */ 	sh	$zero,0x0($s1)
/*  f0f1684:	100001b3 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1688:	a6400000 */ 	sh	$zero,0x0($s2)
.L0f0f168c:
/*  f0f168c:	92080000 */ 	lbu	$t0,0x0($s0)
/*  f0f1690:	2509ffff */ 	addiu	$t1,$t0,-1
/*  f0f1694:	2d210019 */ 	sltiu	$at,$t1,0x19
/*  f0f1698:	102001aa */ 	beqz	$at,.L0f0f1d44
/*  f0f169c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0f16a0:	3c017f1b */ 	lui	$at,%hi(var7f1b2860)
/*  f0f16a4:	00290821 */ 	addu	$at,$at,$t1
/*  f0f16a8:	8c292860 */ 	lw	$t1,%lo(var7f1b2860)($at)
/*  f0f16ac:	01200008 */ 	jr	$t1
/*  f0f16b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f16b4:	240a0096 */ 	addiu	$t2,$zero,0x96
/*  f0f16b8:	a64a0000 */ 	sh	$t2,0x0($s2)
/*  f0f16bc:	240b00e6 */ 	addiu	$t3,$zero,0xe6
/*  f0f16c0:	100001a4 */ 	beqz	$zero,.L0f0f1d54
/*  f0f16c4:	a62b0000 */ 	sh	$t3,0x0($s1)
/*  f0f16c8:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f0f16cc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f16d0:	240e007e */ 	addiu	$t6,$zero,0x7e
/*  f0f16d4:	15810004 */ 	bne	$t4,$at,.L0f0f16e8
/*  f0f16d8:	240f00d2 */ 	addiu	$t7,$zero,0xd2
/*  f0f16dc:	240d00aa */ 	addiu	$t5,$zero,0xaa
/*  f0f16e0:	10000002 */ 	beqz	$zero,.L0f0f16ec
/*  f0f16e4:	a64d0000 */ 	sh	$t5,0x0($s2)
.L0f0f16e8:
/*  f0f16e8:	a64e0000 */ 	sh	$t6,0x0($s2)
.L0f0f16ec:
/*  f0f16ec:	10000199 */ 	beqz	$zero,.L0f0f1d54
/*  f0f16f0:	a62f0000 */ 	sh	$t7,0x0($s1)
/*  f0f16f4:	2418005a */ 	addiu	$t8,$zero,0x5a
/*  f0f16f8:	a6380000 */ 	sh	$t8,0x0($s1)
/*  f0f16fc:	24190036 */ 	addiu	$t9,$zero,0x36
/*  f0f1700:	10000194 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1704:	a6590000 */ 	sh	$t9,0x0($s2)
/*  f0f1708:	24080018 */ 	addiu	$t0,$zero,0x18
/*  f0f170c:	a6280000 */ 	sh	$t0,0x0($s1)
/*  f0f1710:	24090006 */ 	addiu	$t1,$zero,0x6
/*  f0f1714:	1000018f */ 	beqz	$zero,.L0f0f1d54
/*  f0f1718:	a6490000 */ 	sh	$t1,0x0($s2)
/*  f0f171c:	240a0082 */ 	addiu	$t2,$zero,0x82
/*  f0f1720:	a62a0000 */ 	sh	$t2,0x0($s1)
/*  f0f1724:	240b0049 */ 	addiu	$t3,$zero,0x49
/*  f0f1728:	1000018a */ 	beqz	$zero,.L0f0f1d54
/*  f0f172c:	a64b0000 */ 	sh	$t3,0x0($s2)
/*  f0f1730:	8e020008 */ 	lw	$v0,0x8($s0)
/*  f0f1734:	240c0050 */ 	addiu	$t4,$zero,0x50
/*  f0f1738:	24180079 */ 	addiu	$t8,$zero,0x79
/*  f0f173c:	58400004 */ 	blezl	$v0,.L0f0f1750
/*  f0f1740:	a62c0000 */ 	sh	$t4,0x0($s1)
/*  f0f1744:	10000008 */ 	beqz	$zero,.L0f0f1768
/*  f0f1748:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f0f174c:	a62c0000 */ 	sh	$t4,0x0($s1)
.L0f0f1750:
/*  f0f1750:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f0f1754:	240f00b4 */ 	addiu	$t7,$zero,0xb4
/*  f0f1758:	31ae0040 */ 	andi	$t6,$t5,0x40
/*  f0f175c:	51c00003 */ 	beqzl	$t6,.L0f0f176c
/*  f0f1760:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0f1764:	a62f0000 */ 	sh	$t7,0x0($s1)
.L0f0f1768:
/*  f0f1768:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f0f176c:
/*  f0f176c:	18400003 */ 	blez	$v0,.L0f0f177c
/*  f0f1770:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1774:	10000177 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1778:	a6420000 */ 	sh	$v0,0x0($s2)
.L0f0f177c:
/*  f0f177c:	10000175 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1780:	a6580000 */ 	sh	$t8,0x0($s2)
/*  f0f1784:	0fc3c557 */ 	jal	func0f0f155c
/*  f0f1788:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f178c:	1040000b */ 	beqz	$v0,.L0f0f17bc
/*  f0f1790:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f1794:	3c057f1b */ 	lui	$a1,%hi(var7f1b23f0)
/*  f0f1798:	24a523f0 */ 	addiu	$a1,$a1,%lo(var7f1b23f0)
/*  f0f179c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f17a0:	0c004c9d */ 	jal	func00013274
/*  f0f17a4:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0f17a8:	14400004 */ 	bnez	$v0,.L0f0f17bc
/*  f0f17ac:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0f17b0:	a6200000 */ 	sh	$zero,0x0($s1)
/*  f0f17b4:	10000167 */ 	beqz	$zero,.L0f0f1d54
/*  f0f17b8:	a6400000 */ 	sh	$zero,0x0($s2)
.L0f0f17bc:
/*  f0f17bc:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f0f17c0:	10c0000a */ 	beqz	$a2,.L0f0f17ec
/*  f0f17c4:	afa0006c */ 	sw	$zero,0x6c($sp)
/*  f0f17c8:	3c198008 */ 	lui	$t9,0x8008
/*  f0f17cc:	8f39fb0c */ 	lw	$t9,-0x4f4($t9)
/*  f0f17d0:	3c078008 */ 	lui	$a3,0x8008
/*  f0f17d4:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f0f17d8:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0f17dc:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f17e0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f17e4:	0fc55cbe */ 	jal	func0f1572f8
/*  f0f17e8:	afb90010 */ 	sw	$t9,0x10($sp)
.L0f0f17ec:
/*  f0f17ec:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0f17f0:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f0f17f4:	25090014 */ 	addiu	$t1,$t0,0x14
/*  f0f17f8:	a6290000 */ 	sh	$t1,0x0($s1)
/*  f0f17fc:	a64a0000 */ 	sh	$t2,0x0($s2)
/*  f0f1800:	8e0b0010 */ 	lw	$t3,0x10($s0)
/*  f0f1804:	27b20040 */ 	addiu	$s2,$sp,0x40
/*  f0f1808:	51600153 */ 	beqzl	$t3,.L0f0f1d58
/*  f0f180c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f1810:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f0f1814:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f0f1818:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0f181c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f1820:	0320f809 */ 	jalr	$t9
/*  f0f1824:	02403025 */ 	or	$a2,$s2,$zero
/*  f0f1828:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f0f182c:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f0f1830:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0f1834:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f1838:	0320f809 */ 	jalr	$t9
/*  f0f183c:	02403025 */ 	or	$a2,$s2,$zero
/*  f0f1840:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0f1844:	8d8cfb0c */ 	lw	$t4,-0x4f4($t4)
/*  f0f1848:	3c078008 */ 	lui	$a3,0x8008
/*  f0f184c:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f0f1850:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0f1854:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f1858:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f185c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f1860:	0fc55cbe */ 	jal	func0f1572f8
/*  f0f1864:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f1868:	862d0000 */ 	lh	$t5,0x0($s1)
/*  f0f186c:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f0f1870:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0f1874:	25f8000a */ 	addiu	$t8,$t7,0xa
/*  f0f1878:	10000136 */ 	beqz	$zero,.L0f0f1d54
/*  f0f187c:	a6380000 */ 	sh	$t8,0x0($s1)
/*  f0f1880:	24080046 */ 	addiu	$t0,$zero,0x46
/*  f0f1884:	a6280000 */ 	sh	$t0,0x0($s1)
/*  f0f1888:	24090032 */ 	addiu	$t1,$zero,0x32
/*  f0f188c:	10000131 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1890:	a6490000 */ 	sh	$t1,0x0($s2)
/*  f0f1894:	10e00009 */ 	beqz	$a3,.L0f0f18bc
/*  f0f1898:	24190096 */ 	addiu	$t9,$zero,0x96
/*  f0f189c:	90ea006e */ 	lbu	$t2,0x6e($a3)
/*  f0f18a0:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f0f18a4:	240b0016 */ 	addiu	$t3,$zero,0x16
/*  f0f18a8:	51400005 */ 	beqzl	$t2,.L0f0f18c0
/*  f0f18ac:	a6390000 */ 	sh	$t9,0x0($s1)
/*  f0f18b0:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f0f18b4:	10000127 */ 	beqz	$zero,.L0f0f1d54
/*  f0f18b8:	a64b0000 */ 	sh	$t3,0x0($s2)
.L0f0f18bc:
/*  f0f18bc:	a6390000 */ 	sh	$t9,0x0($s1)
.L0f0f18c0:
/*  f0f18c0:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f0f18c4:	a64c0000 */ 	sh	$t4,0x0($s2)
/*  f0f18c8:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f0f18cc:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f0f18d0:	240f0016 */ 	addiu	$t7,$zero,0x16
/*  f0f18d4:	000d72c0 */ 	sll	$t6,$t5,0xb
/*  f0f18d8:	05c3011f */ 	bgezl	$t6,.L0f0f1d58
/*  f0f18dc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f18e0:	a64f0000 */ 	sh	$t7,0x0($s2)
/*  f0f18e4:	1000011b */ 	beqz	$zero,.L0f0f1d54
/*  f0f18e8:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f0f18ec:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f0f18f0:	3c098008 */ 	lui	$t1,0x8008
/*  f0f18f4:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0f18f8:	33080200 */ 	andi	$t0,$t8,0x200
/*  f0f18fc:	11000005 */ 	beqz	$t0,.L0f0f1914
/*  f0f1900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1904:	8d29fb08 */ 	lw	$t1,-0x4f8($t1)
/*  f0f1908:	8d4afb04 */ 	lw	$t2,-0x4fc($t2)
/*  f0f190c:	afa90068 */ 	sw	$t1,0x68($sp)
/*  f0f1910:	afaa0064 */ 	sw	$t2,0x64($sp)
.L0f0f1914:
/*  f0f1914:	0fc3c557 */ 	jal	func0f0f155c
/*  f0f1918:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f191c:	14400004 */ 	bnez	$v0,.L0f0f1930
/*  f0f1920:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f1924:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f0f1928:	10000015 */ 	beqz	$zero,.L0f0f1980
/*  f0f192c:	a6220000 */ 	sh	$v0,0x0($s1)
.L0f0f1930:
/*  f0f1930:	3c057f1b */ 	lui	$a1,%hi(var7f1b23f4)
/*  f0f1934:	24a523f4 */ 	addiu	$a1,$a1,%lo(var7f1b23f4)
/*  f0f1938:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0f193c:	0c004c9d */ 	jal	func00013274
/*  f0f1940:	afa60074 */ 	sw	$a2,0x74($sp)
/*  f0f1944:	14400004 */ 	bnez	$v0,.L0f0f1958
/*  f0f1948:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0f194c:	a6200000 */ 	sh	$zero,0x0($s1)
/*  f0f1950:	1000000b */ 	beqz	$zero,.L0f0f1980
/*  f0f1954:	a6400000 */ 	sh	$zero,0x0($s2)
.L0f0f1958:
/*  f0f1958:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0f195c:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0f1960:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f1964:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f1968:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f196c:	0fc55cbe */ 	jal	func0f1572f8
/*  f0f1970:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f1974:	87b90072 */ 	lh	$t9,0x72($sp)
/*  f0f1978:	272c0022 */ 	addiu	$t4,$t9,0x22
/*  f0f197c:	a62c0000 */ 	sh	$t4,0x0($s1)
.L0f0f1980:
/*  f0f1980:	240d000c */ 	addiu	$t5,$zero,0xc
/*  f0f1984:	100000f3 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1988:	a64d0000 */ 	sh	$t5,0x0($s2)
/*  f0f198c:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*  f0f1990:	a62e0000 */ 	sh	$t6,0x0($s1)
/*  f0f1994:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0f1998:	100000ee */ 	beqz	$zero,.L0f0f1d54
/*  f0f199c:	a64f0000 */ 	sh	$t7,0x0($s2)
/*  f0f19a0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f19a4:	a6380000 */ 	sh	$t8,0x0($s1)
/*  f0f19a8:	8e020008 */ 	lw	$v0,0x8($s0)
/*  f0f19ac:	24080005 */ 	addiu	$t0,$zero,0x5
/*  f0f19b0:	10400002 */ 	beqz	$v0,.L0f0f19bc
/*  f0f19b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f19b8:	a6220000 */ 	sh	$v0,0x0($s1)
.L0f0f19bc:
/*  f0f19bc:	100000e5 */ 	beqz	$zero,.L0f0f1d54
/*  f0f19c0:	a6480000 */ 	sh	$t0,0x0($s2)
/*  f0f19c4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0f19c8:	a6290000 */ 	sh	$t1,0x0($s1)
/*  f0f19cc:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f0f19d0:	2419000b */ 	addiu	$t9,$zero,0xb
/*  f0f19d4:	240c000d */ 	addiu	$t4,$zero,0xd
/*  f0f19d8:	314b0200 */ 	andi	$t3,$t2,0x200
/*  f0f19dc:	11600003 */ 	beqz	$t3,.L0f0f19ec
/*  f0f19e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f19e4:	100000db */ 	beqz	$zero,.L0f0f1d54
/*  f0f19e8:	a6590000 */ 	sh	$t9,0x0($s2)
.L0f0f19ec:
/*  f0f19ec:	100000d9 */ 	beqz	$zero,.L0f0f1d54
/*  f0f19f0:	a64c0000 */ 	sh	$t4,0x0($s2)
/*  f0f19f4:	0fc3c557 */ 	jal	func0f0f155c
/*  f0f19f8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f19fc:	14400004 */ 	bnez	$v0,.L0f0f1a10
/*  f0f1a00:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f1a04:	a6200000 */ 	sh	$zero,0x0($s1)
/*  f0f1a08:	100000d2 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1a0c:	a6400000 */ 	sh	$zero,0x0($s2)
.L0f0f1a10:
/*  f0f1a10:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0f1a14:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0f1a18:	3c057f1b */ 	lui	$a1,%hi(var7f1b23f8)
/*  f0f1a1c:	304d0200 */ 	andi	$t5,$v0,0x200
/*  f0f1a20:	11a00007 */ 	beqz	$t5,.L0f0f1a40
/*  f0f1a24:	0002c240 */ 	sll	$t8,$v0,0x9
/*  f0f1a28:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0f1a2c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0f1a30:	8dcefb08 */ 	lw	$t6,-0x4f8($t6)
/*  f0f1a34:	8deffb04 */ 	lw	$t7,-0x4fc($t7)
/*  f0f1a38:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0f1a3c:	afaf0064 */ 	sw	$t7,0x64($sp)
.L0f0f1a40:
/*  f0f1a40:	07010007 */ 	bgez	$t8,.L0f0f1a60
/*  f0f1a44:	24a523f8 */ 	addiu	$a1,$a1,%lo(var7f1b23f8)
/*  f0f1a48:	3c088008 */ 	lui	$t0,0x8008
/*  f0f1a4c:	3c098008 */ 	lui	$t1,0x8008
/*  f0f1a50:	8d08fb18 */ 	lw	$t0,-0x4e8($t0)
/*  f0f1a54:	8d29fb14 */ 	lw	$t1,-0x4ec($t1)
/*  f0f1a58:	afa80068 */ 	sw	$t0,0x68($sp)
/*  f0f1a5c:	afa90064 */ 	sw	$t1,0x64($sp)
.L0f0f1a60:
/*  f0f1a60:	0c004c9d */ 	jal	func00013274
/*  f0f1a64:	afa60074 */ 	sw	$a2,0x74($sp)
/*  f0f1a68:	14400005 */ 	bnez	$v0,.L0f0f1a80
/*  f0f1a6c:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0f1a70:	a6400000 */ 	sh	$zero,0x0($s2)
/*  f0f1a74:	864a0000 */ 	lh	$t2,0x0($s2)
/*  f0f1a78:	1000003d */ 	beqz	$zero,.L0f0f1b70
/*  f0f1a7c:	a62a0000 */ 	sh	$t2,0x0($s1)
.L0f0f1a80:
/*  f0f1a80:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0f1a84:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0f1a88:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f1a8c:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f1a90:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f1a94:	0fc55cbe */ 	jal	func0f1572f8
/*  f0f1a98:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f1a9c:	87b90072 */ 	lh	$t9,0x72($sp)
/*  f0f1aa0:	3c010040 */ 	lui	$at,0x40
/*  f0f1aa4:	34218000 */ 	ori	$at,$at,0x8000
/*  f0f1aa8:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0f1aac:	a62c0000 */ 	sh	$t4,0x0($s1)
/*  f0f1ab0:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f0f1ab4:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f1ab8:	31ae1010 */ 	andi	$t6,$t5,0x1010
/*  f0f1abc:	55c00005 */ 	bnezl	$t6,.L0f0f1ad4
/*  f0f1ac0:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f0f1ac4:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0f1ac8:	25f80014 */ 	addiu	$t8,$t7,0x14
/*  f0f1acc:	a6380000 */ 	sh	$t8,0x0($s1)
/*  f0f1ad0:	8fa8006c */ 	lw	$t0,0x6c($sp)
.L0f0f1ad4:
/*  f0f1ad4:	25090003 */ 	addiu	$t1,$t0,0x3
/*  f0f1ad8:	a6490000 */ 	sh	$t1,0x0($s2)
/*  f0f1adc:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0f1ae0:	304a0200 */ 	andi	$t2,$v0,0x200
/*  f0f1ae4:	51400006 */ 	beqzl	$t2,.L0f0f1b00
/*  f0f1ae8:	00416024 */ 	and	$t4,$v0,$at
/*  f0f1aec:	864b0000 */ 	lh	$t3,0x0($s2)
/*  f0f1af0:	2579fffe */ 	addiu	$t9,$t3,-2
/*  f0f1af4:	a6590000 */ 	sh	$t9,0x0($s2)
/*  f0f1af8:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0f1afc:	00416024 */ 	and	$t4,$v0,$at
.L0f0f1b00:
/*  f0f1b00:	5580001c */ 	bnezl	$t4,.L0f0f1b74
/*  f0f1b04:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0f1b08:	0fc3c539 */ 	jal	func0f0f14e4
/*  f0f1b0c:	8e04000c */ 	lw	$a0,0xc($s0)
/*  f0f1b10:	10400017 */ 	beqz	$v0,.L0f0f1b70
/*  f0f1b14:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f1b18:	3c0d7f1b */ 	lui	$t5,%hi(var7f1b23fc)
/*  f0f1b1c:	25ad23fc */ 	addiu	$t5,$t5,%lo(var7f1b23fc)
/*  f0f1b20:	104d0013 */ 	beq	$v0,$t5,.L0f0f1b70
/*  f0f1b24:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0f1b28:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f0f1b2c:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f1b30:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f1b34:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f1b38:	0fc55cbe */ 	jal	func0f1572f8
/*  f0f1b3c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f1b40:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0f1b44:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f0f1b48:	01f84021 */ 	addu	$t0,$t7,$t8
/*  f0f1b4c:	25090005 */ 	addiu	$t1,$t0,0x5
/*  f0f1b50:	a6290000 */ 	sh	$t1,0x0($s1)
/*  f0f1b54:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f0f1b58:	314b1000 */ 	andi	$t3,$t2,0x1000
/*  f0f1b5c:	51600005 */ 	beqzl	$t3,.L0f0f1b74
/*  f0f1b60:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0f1b64:	86390000 */ 	lh	$t9,0x0($s1)
/*  f0f1b68:	272cfffa */ 	addiu	$t4,$t9,-6
/*  f0f1b6c:	a62c0000 */ 	sh	$t4,0x0($s1)
.L0f0f1b70:
/*  f0f1b70:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f0f1b74:
/*  f0f1b74:	240e001c */ 	addiu	$t6,$zero,0x1c
/*  f0f1b78:	00026a40 */ 	sll	$t5,$v0,0x9
/*  f0f1b7c:	05a30007 */ 	bgezl	$t5,.L0f0f1b9c
/*  f0f1b80:	00024180 */ 	sll	$t0,$v0,0x6
/*  f0f1b84:	a64e0000 */ 	sh	$t6,0x0($s2)
/*  f0f1b88:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0f1b8c:	25f80024 */ 	addiu	$t8,$t7,0x24
/*  f0f1b90:	a6380000 */ 	sh	$t8,0x0($s1)
/*  f0f1b94:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0f1b98:	00024180 */ 	sll	$t0,$v0,0x6
.L0f0f1b9c:
/*  f0f1b9c:	0503006e */ 	bgezl	$t0,.L0f0f1d58
/*  f0f1ba0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f1ba4:	86490000 */ 	lh	$t1,0x0($s2)
/*  f0f1ba8:	252affff */ 	addiu	$t2,$t1,-1
/*  f0f1bac:	10000069 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1bb0:	a64a0000 */ 	sh	$t2,0x0($s2)
/*  f0f1bb4:	8e020008 */ 	lw	$v0,0x8($s0)
/*  f0f1bb8:	240b00f0 */ 	addiu	$t3,$zero,0xf0
/*  f0f1bbc:	24190096 */ 	addiu	$t9,$zero,0x96
/*  f0f1bc0:	58400004 */ 	blezl	$v0,.L0f0f1bd4
/*  f0f1bc4:	a62b0000 */ 	sh	$t3,0x0($s1)
/*  f0f1bc8:	10000002 */ 	beqz	$zero,.L0f0f1bd4
/*  f0f1bcc:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f0f1bd0:	a62b0000 */ 	sh	$t3,0x0($s1)
.L0f0f1bd4:
/*  f0f1bd4:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0f1bd8:	18400003 */ 	blez	$v0,.L0f0f1be8
/*  f0f1bdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1be0:	1000005c */ 	beqz	$zero,.L0f0f1d54
/*  f0f1be4:	a6420000 */ 	sh	$v0,0x0($s2)
.L0f0f1be8:
/*  f0f1be8:	1000005a */ 	beqz	$zero,.L0f0f1d54
/*  f0f1bec:	a6590000 */ 	sh	$t9,0x0($s2)
/*  f0f1bf0:	240c00f0 */ 	addiu	$t4,$zero,0xf0
/*  f0f1bf4:	3c03800a */ 	lui	$v1,%hi(var8009dfc8)
/*  f0f1bf8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f1bfc:	a62c0000 */ 	sh	$t4,0x0($s1)
/*  f0f1c00:	2463dfc8 */ 	addiu	$v1,$v1,%lo(var8009dfc8)
/*  f0f1c04:	946d0002 */ 	lhu	$t5,0x2($v1)
.L0f0f1c08:
/*  f0f1c08:	11a0000d */ 	beqz	$t5,.L0f0f1c40
/*  f0f1c0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1c10:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0f1c14:	0fc5b367 */ 	jal	getDifficulty
/*  f0f1c18:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0f1c1c:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0f1c20:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f1c24:	004e7804 */ 	sllv	$t7,$t6,$v0
/*  f0f1c28:	9478000e */ 	lhu	$t8,0xe($v1)
/*  f0f1c2c:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0f1c30:	01f84024 */ 	and	$t0,$t7,$t8
/*  f0f1c34:	11000002 */ 	beqz	$t0,.L0f0f1c40
/*  f0f1c38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1c3c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f0f1c40:
/*  f0f1c40:	3c09800a */ 	lui	$t1,%hi(var8009dfd4)
/*  f0f1c44:	2529dfd4 */ 	addiu	$t1,$t1,%lo(var8009dfd4)
/*  f0f1c48:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0f1c4c:	5469ffee */ 	bnel	$v1,$t1,.L0f0f1c08
/*  f0f1c50:	946d0002 */ 	lhu	$t5,0x2($v1)
/*  f0f1c54:	92020001 */ 	lbu	$v0,0x1($s0)
/*  f0f1c58:	000450c0 */ 	sll	$t2,$a0,0x3
/*  f0f1c5c:	01445021 */ 	addu	$t2,$t2,$a0
/*  f0f1c60:	14400005 */ 	bnez	$v0,.L0f0f1c78
/*  f0f1c64:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f1c68:	000a5040 */ 	sll	$t2,$t2,0x1
/*  f0f1c6c:	254b0009 */ 	addiu	$t3,$t2,0x9
/*  f0f1c70:	10000038 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1c74:	a64b0000 */ 	sh	$t3,0x0($s2)
.L0f0f1c78:
/*  f0f1c78:	14410006 */ 	bne	$v0,$at,.L0f0f1c94
/*  f0f1c7c:	0004c8c0 */ 	sll	$t9,$a0,0x3
/*  f0f1c80:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f0f1c84:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f0f1c88:	272c0009 */ 	addiu	$t4,$t9,0x9
/*  f0f1c8c:	10000031 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1c90:	a64c0000 */ 	sh	$t4,0x0($s2)
.L0f0f1c94:
/*  f0f1c94:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f1c98:	1441002e */ 	bne	$v0,$at,.L0f0f1d54
/*  f0f1c9c:	00046900 */ 	sll	$t5,$a0,0x4
/*  f0f1ca0:	01a46823 */ 	subu	$t5,$t5,$a0
/*  f0f1ca4:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f0f1ca8:	25ae0009 */ 	addiu	$t6,$t5,0x9
/*  f0f1cac:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f0f1cb0:	a64e0000 */ 	sh	$t6,0x0($s2)
/*  f0f1cb4:	10000027 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1cb8:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f0f1cbc:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f0f1cc0:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f0f1cc4:	10000023 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1cc8:	a6420000 */ 	sh	$v0,0x0($s2)
/*  f0f1ccc:	240f007d */ 	addiu	$t7,$zero,0x7d
/*  f0f1cd0:	a62f0000 */ 	sh	$t7,0x0($s1)
/*  f0f1cd4:	24180044 */ 	addiu	$t8,$zero,0x44
/*  f0f1cd8:	1000001e */ 	beqz	$zero,.L0f0f1d54
/*  f0f1cdc:	a6580000 */ 	sh	$t8,0x0($s2)
/*  f0f1ce0:	2408007d */ 	addiu	$t0,$zero,0x7d
/*  f0f1ce4:	a6280000 */ 	sh	$t0,0x0($s1)
/*  f0f1ce8:	2409003a */ 	addiu	$t1,$zero,0x3a
/*  f0f1cec:	10000019 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1cf0:	a6490000 */ 	sh	$t1,0x0($s2)
/*  f0f1cf4:	8e020008 */ 	lw	$v0,0x8($s0)
/*  f0f1cf8:	240b0042 */ 	addiu	$t3,$zero,0x42
/*  f0f1cfc:	10400003 */ 	beqz	$v0,.L0f0f1d0c
/*  f0f1d00:	244a0002 */ 	addiu	$t2,$v0,0x2
/*  f0f1d04:	10000002 */ 	beqz	$zero,.L0f0f1d10
/*  f0f1d08:	a62a0000 */ 	sh	$t2,0x0($s1)
.L0f0f1d0c:
/*  f0f1d0c:	a62b0000 */ 	sh	$t3,0x0($s1)
.L0f0f1d10:
/*  f0f1d10:	86390000 */ 	lh	$t9,0x0($s1)
/*  f0f1d14:	1000000f */ 	beqz	$zero,.L0f0f1d54
/*  f0f1d18:	a6590000 */ 	sh	$t9,0x0($s2)
/*  f0f1d1c:	240c0042 */ 	addiu	$t4,$zero,0x42
/*  f0f1d20:	a62c0000 */ 	sh	$t4,0x0($s1)
/*  f0f1d24:	862d0000 */ 	lh	$t5,0x0($s1)
/*  f0f1d28:	1000000a */ 	beqz	$zero,.L0f0f1d54
/*  f0f1d2c:	a64d0000 */ 	sh	$t5,0x0($s2)
/*  f0f1d30:	240e0082 */ 	addiu	$t6,$zero,0x82
/*  f0f1d34:	a62e0000 */ 	sh	$t6,0x0($s1)
/*  f0f1d38:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0f1d3c:	10000005 */ 	beqz	$zero,.L0f0f1d54
/*  f0f1d40:	a64f0000 */ 	sh	$t7,0x0($s2)
.L0f0f1d44:
/*  f0f1d44:	24180050 */ 	addiu	$t8,$zero,0x50
/*  f0f1d48:	a6380000 */ 	sh	$t8,0x0($s1)
/*  f0f1d4c:	2408000c */ 	addiu	$t0,$zero,0xc
/*  f0f1d50:	a6480000 */ 	sh	$t0,0x0($s2)
.L0f0f1d54:
/*  f0f1d54:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0f1d58:
/*  f0f1d58:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0f1d5c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0f1d60:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0f1d64:	03e00008 */ 	jr	$ra
/*  f0f1d68:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f0f1d6c
/*  f0f1d6c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0f1d70:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0f1d74:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0f1d78:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f1d7c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0f1d80:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0f1d84:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0f1d88:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0f1d8c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f1d90:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f1d94:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f1d98:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f0f1d9c:	8cc206d8 */ 	lw	$v0,0x6d8($a2)
/*  f0f1da0:	8c910008 */ 	lw	$s1,0x8($a0)
/*  f0f1da4:	84d7081e */ 	lh	$s7,0x81e($a2)
/*  f0f1da8:	8cd6065c */ 	lw	$s6,0x65c($a2)
/*  f0f1dac:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0f1db0:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f0f1db4:	00a0f025 */ 	or	$s8,$a1,$zero
/*  f0f1db8:	00009825 */ 	or	$s3,$zero,$zero
/*  f0f1dbc:	a0a00005 */ 	sb	$zero,0x5($a1)
/*  f0f1dc0:	a0b80004 */ 	sb	$t8,0x4($a1)
/*  f0f1dc4:	1220003a */ 	beqz	$s1,.L0f0f1eb0
/*  f0f1dc8:	a4b70006 */ 	sh	$s7,0x6($a1)
/*  f0f1dcc:	92390000 */ 	lbu	$t9,0x0($s1)
/*  f0f1dd0:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f0f1dd4:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0f1dd8:	13210035 */ 	beq	$t9,$at,.L0f0f1eb0
/*  f0f1ddc:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0f1de0:	00024880 */ 	sll	$t1,$v0,0x2
/*  f0f1de4:	01224821 */ 	addu	$t1,$t1,$v0
/*  f0f1de8:	00094840 */ 	sll	$t1,$t1,0x1
/*  f0f1dec:	00165080 */ 	sll	$t2,$s6,0x2
/*  f0f1df0:	010a9021 */ 	addu	$s2,$t0,$t2
/*  f0f1df4:	01098021 */ 	addu	$s0,$t0,$t1
/*  f0f1df8:	2415ffff */ 	addiu	$s5,$zero,-1
.L0f0f1dfc:
/*  f0f1dfc:	8e2b0004 */ 	lw	$t3,0x4($s1)
/*  f0f1e00:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f1e04:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f0f1e08:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f0f1e0c:	11800002 */ 	beqz	$t4,.L0f0f1e18
/*  f0f1e10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1e14:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f0f1e18:
/*  f0f1e18:	5280000d */ 	beqzl	$s4,.L0f0f1e50
/*  f0f1e1c:	afb50058 */ 	sw	$s5,0x58($sp)
/*  f0f1e20:	93cd0005 */ 	lbu	$t5,0x5($s8)
/*  f0f1e24:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f1e28:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f0f1e2c:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0f1e30:	a3ce0005 */ 	sb	$t6,0x5($s8)
/*  f0f1e34:	a6000660 */ 	sh	$zero,0x660($s0)
/*  f0f1e38:	a6000662 */ 	sh	$zero,0x662($s0)
/*  f0f1e3c:	a2000664 */ 	sb	$zero,0x664($s0)
/*  f0f1e40:	a2000668 */ 	sb	$zero,0x668($s0)
/*  f0f1e44:	a6160666 */ 	sh	$s6,0x666($s0)
/*  f0f1e48:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0f1e4c:	afb50058 */ 	sw	$s5,0x58($sp)
.L0f0f1e50:
/*  f0f1e50:	0fc3c569 */ 	jal	func0f0f15a4
/*  f0f1e54:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f0f1e58:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f0f1e5c:	8fa20064 */ 	lw	$v0,0x64($sp)
/*  f0f1e60:	51f50008 */ 	beql	$t7,$s5,.L0f0f1e84
/*  f0f1e64:	a25504ff */ 	sb	$s5,0x4ff($s2)
/*  f0f1e68:	a25704ff */ 	sb	$s7,0x4ff($s2)
/*  f0f1e6c:	87b8005a */ 	lh	$t8,0x5a($sp)
/*  f0f1e70:	02f8b821 */ 	addu	$s7,$s7,$t8
/*  f0f1e74:	0017cc00 */ 	sll	$t9,$s7,0x10
/*  f0f1e78:	10000002 */ 	beqz	$zero,.L0f0f1e84
/*  f0f1e7c:	0019bc03 */ 	sra	$s7,$t9,0x10
/*  f0f1e80:	a25504ff */ 	sb	$s5,0x4ff($s2)
.L0f0f1e84:
/*  f0f1e84:	a25304fe */ 	sb	$s3,0x4fe($s2)
/*  f0f1e88:	92080668 */ 	lbu	$t0,0x668($s0)
/*  f0f1e8c:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f0f1e90:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f0f1e94:	250a0001 */ 	addiu	$t2,$t0,0x1
/*  f0f1e98:	a20a0668 */ 	sb	$t2,0x668($s0)
/*  f0f1e9c:	922b0014 */ 	lbu	$t3,0x14($s1)
/*  f0f1ea0:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f0f1ea4:	26310014 */ 	addiu	$s1,$s1,0x14
/*  f0f1ea8:	1561ffd4 */ 	bne	$t3,$at,.L0f0f1dfc
/*  f0f1eac:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f0f1eb0:
/*  f0f1eb0:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0f1eb4:	244c0001 */ 	addiu	$t4,$v0,0x1
/*  f0f1eb8:	adac06d8 */ 	sw	$t4,0x6d8($t5)
/*  f0f1ebc:	adb6065c */ 	sw	$s6,0x65c($t5)
/*  f0f1ec0:	adb7081c */ 	sw	$s7,0x81c($t5)
/*  f0f1ec4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f1ec8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0f1ecc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0f1ed0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0f1ed4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0f1ed8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0f1edc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0f1ee0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f1ee4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f1ee8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f1eec:	03e00008 */ 	jr	$ra
/*  f0f1ef0:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f0f1ef4
/*  f0f1ef4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0f1ef8:	afb70024 */ 	sw	$s7,0x24($sp)
/*  f0f1efc:	afb60020 */ 	sw	$s6,0x20($sp)
/*  f0f1f00:	afb5001c */ 	sw	$s5,0x1c($sp)
/*  f0f1f04:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f0f1f08:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f0f1f0c:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0f1f10:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f0f1f14:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f0f1f18:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f0f1f1c:	8c8d0020 */ 	lw	$t5,0x20($a0)
/*  f0f1f20:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f1f24:	8dcf0010 */ 	lw	$t7,0x10($t6)
/*  f0f1f28:	3c19800a */ 	lui	$t9,0x800a
/*  f0f1f2c:	25adfff4 */ 	addiu	$t5,$t5,-12
/*  f0f1f30:	31f80040 */ 	andi	$t8,$t7,0x40
/*  f0f1f34:	57000076 */ 	bnezl	$t8,.L0f0f2110
/*  f0f1f38:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f0f1f3c:	8f3919c4 */ 	lw	$t9,0x19c4($t9)
/*  f0f1f40:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f1f44:	53210072 */ 	beql	$t9,$at,.L0f0f2110
/*  f0f1f48:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f0f1f4c:	8c8e0028 */ 	lw	$t6,0x28($a0)
/*  f0f1f50:	01ae082a */ 	slt	$at,$t5,$t6
/*  f0f1f54:	5020006e */ 	beqzl	$at,.L0f0f2110
/*  f0f1f58:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f0f1f5c:	90910005 */ 	lbu	$s1,0x5($a0)
/*  f0f1f60:	00006025 */ 	or	$t4,$zero,$zero
/*  f0f1f64:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0f1f68:	1a200068 */ 	blez	$s1,.L0f0f210c
/*  f0f1f6c:	3c19800a */ 	lui	$t9,%hi(var8009e000)
/*  f0f1f70:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f0f1f74:	2739e000 */ 	addiu	$t9,$t9,%lo(var8009e000)
/*  f0f1f78:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f0f1f7c:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f1f80:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f1f84:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f1f88:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f1f8c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f1f90:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f1f94:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f1f98:	03192821 */ 	addu	$a1,$t8,$t9
/*  f0f1f9c:	3c0b0020 */ 	lui	$t3,0x20
/*  f0f1fa0:	240a0012 */ 	addiu	$t2,$zero,0x12
/*  f0f1fa4:	24090005 */ 	addiu	$t1,$zero,0x5
/*  f0f1fa8:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f0f1fac:	24070014 */ 	addiu	$a3,$zero,0x14
/*  f0f1fb0:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f0f1fb4:	90ce0004 */ 	lbu	$t6,0x4($a2)
.L0f0f1fb8:
/*  f0f1fb8:	01cc9021 */ 	addu	$s2,$t6,$t4
/*  f0f1fbc:	02500019 */ 	multu	$s2,$s0
/*  f0f1fc0:	258c0001 */ 	addiu	$t4,$t4,0x1
/*  f0f1fc4:	00007812 */ 	mflo	$t7
/*  f0f1fc8:	00af1821 */ 	addu	$v1,$a1,$t7
/*  f0f1fcc:	84780662 */ 	lh	$t8,0x662($v1)
/*  f0f1fd0:	030d1023 */ 	subu	$v0,$t8,$t5
/*  f0f1fd4:	5840004b */ 	blezl	$v0,.L0f0f2104
/*  f0f1fd8:	0191082a */ 	slt	$at,$t4,$s1
/*  f0f1fdc:	90730668 */ 	lbu	$s3,0x668($v1)
/*  f0f1fe0:	00009025 */ 	or	$s2,$zero,$zero
/*  f0f1fe4:	5a600047 */ 	blezl	$s3,.L0f0f2104
/*  f0f1fe8:	0191082a */ 	slt	$at,$t4,$s1
.L0f0f1fec:
/*  f0f1fec:	58400040 */ 	blezl	$v0,.L0f0f20f0
/*  f0f1ff0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0f1ff4:	94790666 */ 	lhu	$t9,0x666($v1)
/*  f0f1ff8:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f1ffc:	0332a021 */ 	addu	$s4,$t9,$s2
/*  f0f2000:	00147080 */ 	sll	$t6,$s4,0x2
/*  f0f2004:	00aeb021 */ 	addu	$s6,$a1,$t6
/*  f0f2008:	92cf04fe */ 	lbu	$t7,0x4fe($s6)
/*  f0f200c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f0f2010:	01e70019 */ 	multu	$t7,$a3
/*  f0f2014:	8f2e0008 */ 	lw	$t6,0x8($t9)
/*  f0f2018:	0000c012 */ 	mflo	$t8
/*  f0f201c:	030ea821 */ 	addu	$s5,$t8,$t6
/*  f0f2020:	92b70000 */ 	lbu	$s7,0x0($s5)
/*  f0f2024:	52e80008 */ 	beql	$s7,$t0,.L0f0f2048
/*  f0f2028:	8eaf0004 */ 	lw	$t7,0x4($s5)
/*  f0f202c:	52e90022 */ 	beql	$s7,$t1,.L0f0f20b8
/*  f0f2030:	86d404fc */ 	lh	$s4,0x4fc($s6)
/*  f0f2034:	52ea0020 */ 	beql	$s7,$t2,.L0f0f20b8
/*  f0f2038:	86d404fc */ 	lh	$s4,0x4fc($s6)
/*  f0f203c:	10000024 */ 	beqz	$zero,.L0f0f20d0
/*  f0f2040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2044:	8eaf0004 */ 	lw	$t7,0x4($s5)
.L0f0f2048:
/*  f0f2048:	244e000a */ 	addiu	$t6,$v0,0xa
/*  f0f204c:	01ebc824 */ 	and	$t9,$t7,$t3
/*  f0f2050:	13200009 */ 	beqz	$t9,.L0f0f2078
/*  f0f2054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2058:	86d404fc */ 	lh	$s4,0x4fc($s6)
/*  f0f205c:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f2060:	0282c023 */ 	subu	$t8,$s4,$v0
/*  f0f2064:	2b01001e */ 	slti	$at,$t8,0x1e
/*  f0f2068:	10200019 */ 	beqz	$at,.L0f0f20d0
/*  f0f206c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2070:	10000017 */ 	beqz	$zero,.L0f0f20d0
/*  f0f2074:	2691ffe2 */ 	addiu	$s1,$s4,-30
.L0f0f2078:
/*  f0f2078:	01c4001a */ 	div	$zero,$t6,$a0
/*  f0f207c:	00007812 */ 	mflo	$t7
/*  f0f2080:	14800002 */ 	bnez	$a0,.L0f0f208c
/*  f0f2084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2088:	0007000d */ 	break	0x7
.L0f0f208c:
/*  f0f208c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f2090:	14810004 */ 	bne	$a0,$at,.L0f0f20a4
/*  f0f2094:	3c018000 */ 	lui	$at,0x8000
/*  f0f2098:	15c10002 */ 	bne	$t6,$at,.L0f0f20a4
/*  f0f209c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f20a0:	0006000d */ 	break	0x6
.L0f0f20a4:
/*  f0f20a4:	01e40019 */ 	multu	$t7,$a0
/*  f0f20a8:	00008812 */ 	mflo	$s1
/*  f0f20ac:	10000008 */ 	beqz	$zero,.L0f0f20d0
/*  f0f20b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f20b4:	86d404fc */ 	lh	$s4,0x4fc($s6)
.L0f0f20b8:
/*  f0f20b8:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f20bc:	0282c823 */ 	subu	$t9,$s4,$v0
/*  f0f20c0:	2b210032 */ 	slti	$at,$t9,0x32
/*  f0f20c4:	10200002 */ 	beqz	$at,.L0f0f20d0
/*  f0f20c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f20cc:	2691ffce */ 	addiu	$s1,$s4,-50
.L0f0f20d0:
/*  f0f20d0:	5a200007 */ 	blezl	$s1,.L0f0f20f0
/*  f0f20d4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0f20d8:	86d804fc */ 	lh	$t8,0x4fc($s6)
/*  f0f20dc:	00511023 */ 	subu	$v0,$v0,$s1
/*  f0f20e0:	03117023 */ 	subu	$t6,$t8,$s1
/*  f0f20e4:	a6ce04fc */ 	sh	$t6,0x4fc($s6)
/*  f0f20e8:	90730668 */ 	lbu	$s3,0x668($v1)
/*  f0f20ec:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f0f20f0:
/*  f0f20f0:	0253082a */ 	slt	$at,$s2,$s3
/*  f0f20f4:	1420ffbd */ 	bnez	$at,.L0f0f1fec
/*  f0f20f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f20fc:	90d10005 */ 	lbu	$s1,0x5($a2)
/*  f0f2100:	0191082a */ 	slt	$at,$t4,$s1
.L0f0f2104:
/*  f0f2104:	5420ffac */ 	bnezl	$at,.L0f0f1fb8
/*  f0f2108:	90ce0004 */ 	lbu	$t6,0x4($a2)
.L0f0f210c:
/*  f0f210c:	8fb00008 */ 	lw	$s0,0x8($sp)
.L0f0f2110:
/*  f0f2110:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f0f2114:	8fb20010 */ 	lw	$s2,0x10($sp)
/*  f0f2118:	8fb30014 */ 	lw	$s3,0x14($sp)
/*  f0f211c:	8fb40018 */ 	lw	$s4,0x18($sp)
/*  f0f2120:	8fb5001c */ 	lw	$s5,0x1c($sp)
/*  f0f2124:	8fb60020 */ 	lw	$s6,0x20($sp)
/*  f0f2128:	8fb70024 */ 	lw	$s7,0x24($sp)
/*  f0f212c:	03e00008 */ 	jr	$ra
/*  f0f2130:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f0f2134
/*  f0f2134:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0f2138:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0f213c:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f0f2140:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f0f2144:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f0f2148:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f0f214c:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f0f2150:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f0f2154:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0f2158:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0f215c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0f2160:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0f2164:	8c920008 */ 	lw	$s2,0x8($a0)
/*  f0f2168:	90a20004 */ 	lbu	$v0,0x4($a1)
/*  f0f216c:	00c0f025 */ 	or	$s8,$a2,$zero
/*  f0f2170:	12400030 */ 	beqz	$s2,.L0f0f2234
/*  f0f2174:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0f2178:	924f0000 */ 	lbu	$t7,0x0($s2)
/*  f0f217c:	2417001a */ 	addiu	$s7,$zero,0x1a
/*  f0f2180:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0f2184:	12ef002b */ 	beq	$s7,$t7,.L0f0f2234
/*  f0f2188:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f0f218c:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f0f2190:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f0f2194:	00d88021 */ 	addu	$s0,$a2,$t8
/*  f0f2198:	27b60068 */ 	addiu	$s6,$sp,0x68
/*  f0f219c:	27b5006a */ 	addiu	$s5,$sp,0x6a
/*  f0f21a0:	8fb30090 */ 	lw	$s3,0x90($sp)
/*  f0f21a4:	8e590004 */ 	lw	$t9,0x4($s2)
.L0f0f21a8:
/*  f0f21a8:	02402025 */ 	or	$a0,$s2,$zero
/*  f0f21ac:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f21b0:	33280001 */ 	andi	$t0,$t9,0x1
/*  f0f21b4:	11000002 */ 	beqz	$t0,.L0f0f21c0
/*  f0f21b8:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0f21bc:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f0f21c0:
/*  f0f21c0:	52800007 */ 	beqzl	$s4,.L0f0f21e0
/*  f0f21c4:	00134880 */ 	sll	$t1,$s3,0x2
/*  f0f21c8:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f0f21cc:	a6000660 */ 	sh	$zero,0x660($s0)
/*  f0f21d0:	a6000662 */ 	sh	$zero,0x662($s0)
/*  f0f21d4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0f21d8:	96130666 */ 	lhu	$s3,0x666($s0)
/*  f0f21dc:	00134880 */ 	sll	$t1,$s3,0x2
.L0f0f21e0:
/*  f0f21e0:	03c98821 */ 	addu	$s1,$s8,$t1
/*  f0f21e4:	0fc3c586 */ 	jal	func0f0f1618
/*  f0f21e8:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0f21ec:	860a0660 */ 	lh	$t2,0x660($s0)
/*  f0f21f0:	87ab006a */ 	lh	$t3,0x6a($sp)
/*  f0f21f4:	014b082a */ 	slt	$at,$t2,$t3
/*  f0f21f8:	50200003 */ 	beqzl	$at,.L0f0f2208
/*  f0f21fc:	87ac0068 */ 	lh	$t4,0x68($sp)
/*  f0f2200:	a60b0660 */ 	sh	$t3,0x660($s0)
/*  f0f2204:	87ac0068 */ 	lh	$t4,0x68($sp)
.L0f0f2208:
/*  f0f2208:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0f220c:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f0f2210:	a62c04fc */ 	sh	$t4,0x4fc($s1)
/*  f0f2214:	860d0662 */ 	lh	$t5,0x662($s0)
/*  f0f2218:	87ae0068 */ 	lh	$t6,0x68($sp)
/*  f0f221c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0f2220:	a60f0662 */ 	sh	$t7,0x662($s0)
/*  f0f2224:	92580000 */ 	lbu	$t8,0x0($s2)
/*  f0f2228:	56f8ffdf */ 	bnel	$s7,$t8,.L0f0f21a8
/*  f0f222c:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f0f2230:	afb30090 */ 	sw	$s3,0x90($sp)
.L0f0f2234:
/*  f0f2234:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f0f2238:	00008025 */ 	or	$s0,$zero,$zero
/*  f0f223c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f2240:	93220005 */ 	lbu	$v0,0x5($t9)
/*  f0f2244:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f2248:	8fab009c */ 	lw	$t3,0x9c($sp)
/*  f0f224c:	18400013 */ 	blez	$v0,.L0f0f229c
/*  f0f2250:	00023080 */ 	sll	$a2,$v0,0x2
/*  f0f2254:	93280004 */ 	lbu	$t0,0x4($t9)
/*  f0f2258:	00c23021 */ 	addu	$a2,$a2,$v0
/*  f0f225c:	00063040 */ 	sll	$a2,$a2,0x1
/*  f0f2260:	00084880 */ 	sll	$t1,$t0,0x2
/*  f0f2264:	01284821 */ 	addu	$t1,$t1,$t0
/*  f0f2268:	00094840 */ 	sll	$t1,$t1,0x1
/*  f0f226c:	03c92821 */ 	addu	$a1,$s8,$t1
/*  f0f2270:	00a31021 */ 	addu	$v0,$a1,$v1
.L0f0f2274:
/*  f0f2274:	84440662 */ 	lh	$a0,0x662($v0)
/*  f0f2278:	844a0660 */ 	lh	$t2,0x660($v0)
/*  f0f227c:	2463000a */ 	addiu	$v1,$v1,0xa
/*  f0f2280:	0204082a */ 	slt	$at,$s0,$a0
/*  f0f2284:	10200002 */ 	beqz	$at,.L0f0f2290
/*  f0f2288:	022a8821 */ 	addu	$s1,$s1,$t2
/*  f0f228c:	00808025 */ 	or	$s0,$a0,$zero
.L0f0f2290:
/*  f0f2290:	0066082a */ 	slt	$at,$v1,$a2
/*  f0f2294:	5420fff7 */ 	bnezl	$at,.L0f0f2274
/*  f0f2298:	00a31021 */ 	addu	$v0,$a1,$v1
.L0f0f229c:
/*  f0f229c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0f22a0:	0fc3c560 */ 	jal	func0f0f1580
/*  f0f22a4:	8d640000 */ 	lw	$a0,0x0($t3)
/*  f0f22a8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0f22ac:	8d8cfb0c */ 	lw	$t4,-0x4f4($t4)
/*  f0f22b0:	3c078008 */ 	lui	$a3,0x8008
/*  f0f22b4:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f0f22b8:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f0f22bc:	27a50080 */ 	addiu	$a1,$sp,0x80
/*  f0f22c0:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f22c4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f22c8:	0fc55cbe */ 	jal	func0f1572f8
/*  f0f22cc:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f22d0:	3c02800a */ 	lui	$v0,0x800a
/*  f0f22d4:	8c4219c4 */ 	lw	$v0,0x19c4($v0)
/*  f0f22d8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f22dc:	24030008 */ 	addiu	$v1,$zero,0x8
/*  f0f22e0:	10410008 */ 	beq	$v0,$at,.L0f0f2304
/*  f0f22e4:	8fad0080 */ 	lw	$t5,0x80($sp)
/*  f0f22e8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f22ec:	10410005 */ 	beq	$v0,$at,.L0f0f2304
/*  f0f22f0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f22f4:	10410003 */ 	beq	$v0,$at,.L0f0f2304
/*  f0f22f8:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0f22fc:	54410003 */ 	bnel	$v0,$at,.L0f0f230c
/*  f0f2300:	01a31021 */ 	addu	$v0,$t5,$v1
.L0f0f2304:
/*  f0f2304:	24030011 */ 	addiu	$v1,$zero,0x11
/*  f0f2308:	01a31021 */ 	addu	$v0,$t5,$v1
.L0f0f230c:
/*  f0f230c:	0222082a */ 	slt	$at,$s1,$v0
/*  f0f2310:	10200002 */ 	beqz	$at,.L0f0f231c
/*  f0f2314:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0f2318:	00408825 */ 	or	$s1,$v0,$zero
.L0f0f231c:
/*  f0f231c:	add10024 */ 	sw	$s1,0x24($t6)
/*  f0f2320:	add00028 */ 	sw	$s0,0x28($t6)
/*  f0f2324:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0f2328:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f0f232c:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f0f2330:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f0f2334:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f0f2338:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f0f233c:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f0f2340:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0f2344:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0f2348:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0f234c:	03e00008 */ 	jr	$ra
/*  f0f2350:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

GLOBAL_ASM(
glabel func0f0f2354
/*  f0f2354:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*  f0f2358:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f0f235c:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f0f2360:	90820004 */ 	lbu	$v0,0x4($a0)
/*  f0f2364:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f0f2368:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0f236c:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f0f2370:	908f0005 */ 	lbu	$t7,0x5($a0)
/*  f0f2374:	90830004 */ 	lbu	$v1,0x4($a0)
/*  f0f2378:	258c1448 */ 	addiu	$t4,$t4,%lo(g_MpPlayerNum)
/*  f0f237c:	24110014 */ 	addiu	$s1,$zero,0x14
/*  f0f2380:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f0f2384:	0058082a */ 	slt	$at,$v0,$t8
/*  f0f2388:	10200051 */ 	beqz	$at,.L0f0f24d0
/*  f0f238c:	240d000a */ 	addiu	$t5,$zero,0xa
/*  f0f2390:	3c0b800a */ 	lui	$t3,%hi(var8009e000)
/*  f0f2394:	256be000 */ 	addiu	$t3,$t3,%lo(var8009e000)
.L0f0f2398:
/*  f0f2398:	004d0019 */ 	multu	$v0,$t5
/*  f0f239c:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f0f23a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f23a4:	001970c0 */ 	sll	$t6,$t9,0x3
/*  f0f23a8:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f23ac:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f23b0:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f0f23b4:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f23b8:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f23bc:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f23c0:	0000c012 */ 	mflo	$t8
/*  f0f23c4:	016e7821 */ 	addu	$t7,$t3,$t6
/*  f0f23c8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0f23cc:	97290666 */ 	lhu	$t1,0x666($t9)
/*  f0f23d0:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f0f23d4:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f0f23d8:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f0f23dc:	004d0019 */ 	multu	$v0,$t5
/*  f0f23e0:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f23e4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f23e8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f23ec:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f23f0:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f23f4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f23f8:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f23fc:	01782821 */ 	addu	$a1,$t3,$t8
/*  f0f2400:	0000c812 */ 	mflo	$t9
/*  f0f2404:	00b94021 */ 	addu	$t0,$a1,$t9
/*  f0f2408:	910e0668 */ 	lbu	$t6,0x668($t0)
/*  f0f240c:	950f0666 */ 	lhu	$t7,0x666($t0)
/*  f0f2410:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0f2414:	0138082a */ 	slt	$at,$t1,$t8
/*  f0f2418:	10200024 */ 	beqz	$at,.L0f0f24ac
/*  f0f241c:	0009c880 */ 	sll	$t9,$t1,0x2
.L0f0f2420:
/*  f0f2420:	00b95021 */ 	addu	$t2,$a1,$t9
/*  f0f2424:	914e04fe */ 	lbu	$t6,0x4fe($t2)
/*  f0f2428:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f0f242c:	01d10019 */ 	multu	$t6,$s1
/*  f0f2430:	8f190008 */ 	lw	$t9,0x8($t8)
/*  f0f2434:	25380001 */ 	addiu	$t8,$t1,0x1
/*  f0f2438:	00007812 */ 	mflo	$t7
/*  f0f243c:	01f91021 */ 	addu	$v0,$t7,$t9
/*  f0f2440:	54500004 */ 	bnel	$v0,$s0,.L0f0f2454
/*  f0f2444:	854e04fc */ 	lh	$t6,0x4fc($t2)
/*  f0f2448:	10000036 */ 	beqz	$zero,.L0f0f2524
/*  f0f244c:	00601025 */ 	or	$v0,$v1,$zero
/*  f0f2450:	854e04fc */ 	lh	$t6,0x4fc($t2)
.L0f0f2454:
/*  f0f2454:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0f2458:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f0f245c:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f0f2460:	01c31821 */ 	addu	$v1,$t6,$v1
/*  f0f2464:	004d0019 */ 	multu	$v0,$t5
/*  f0f2468:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f0f246c:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f0f2470:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f2474:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f0f2478:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f247c:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f0f2480:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f2484:	01792821 */ 	addu	$a1,$t3,$t9
/*  f0f2488:	03004825 */ 	or	$t1,$t8,$zero
/*  f0f248c:	00007012 */ 	mflo	$t6
/*  f0f2490:	00ae4021 */ 	addu	$t0,$a1,$t6
/*  f0f2494:	91180668 */ 	lbu	$t8,0x668($t0)
/*  f0f2498:	950f0666 */ 	lhu	$t7,0x666($t0)
/*  f0f249c:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f0f24a0:	0139082a */ 	slt	$at,$t1,$t9
/*  f0f24a4:	5420ffde */ 	bnezl	$at,.L0f0f2420
/*  f0f24a8:	0009c880 */ 	sll	$t9,$t1,0x2
.L0f0f24ac:
/*  f0f24ac:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f0f24b0:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f0f24b4:	90980005 */ 	lbu	$t8,0x5($a0)
/*  f0f24b8:	90830004 */ 	lbu	$v1,0x4($a0)
/*  f0f24bc:	01c01025 */ 	or	$v0,$t6,$zero
/*  f0f24c0:	00787821 */ 	addu	$t7,$v1,$t8
/*  f0f24c4:	01cf082a */ 	slt	$at,$t6,$t7
/*  f0f24c8:	1420ffb3 */ 	bnez	$at,.L0f0f2398
/*  f0f24cc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f24d0:
/*  f0f24d0:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f0f24d4:	258c1448 */ 	addiu	$t4,$t4,%lo(g_MpPlayerNum)
/*  f0f24d8:	240d000a */ 	addiu	$t5,$zero,0xa
/*  f0f24dc:	ace30000 */ 	sw	$v1,0x0($a3)
/*  f0f24e0:	006d0019 */ 	multu	$v1,$t5
/*  f0f24e4:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f0f24e8:	3c0b800a */ 	lui	$t3,%hi(var8009e000)
/*  f0f24ec:	256be000 */ 	addiu	$t3,$t3,%lo(var8009e000)
/*  f0f24f0:	001970c0 */ 	sll	$t6,$t9,0x3
/*  f0f24f4:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f24f8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f24fc:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f0f2500:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f2504:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f2508:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f250c:	016ec021 */ 	addu	$t8,$t3,$t6
/*  f0f2510:	0000c812 */ 	mflo	$t9
/*  f0f2514:	03197021 */ 	addu	$t6,$t8,$t9
/*  f0f2518:	95cf0666 */ 	lhu	$t7,0x666($t6)
/*  f0f251c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f2520:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f0f2524:
/*  f0f2524:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f0f2528:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f0f252c:	03e00008 */ 	jr	$ra
/*  f0f2530:	27bd0010 */ 	addiu	$sp,$sp,0x10
);

GLOBAL_ASM(
glabel func0f0f2534
/*  f0f2534:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0f2538:	24030005 */ 	addiu	$v1,$zero,0x5
/*  f0f253c:	546e0010 */ 	bnel	$v1,$t6,.L0f0f2580
/*  f0f2540:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f2544:	90820001 */ 	lbu	$v0,0x1($a0)
/*  f0f2548:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f254c:	10410009 */ 	beq	$v0,$at,.L0f0f2574
/*  f0f2550:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f2554:	10410007 */ 	beq	$v0,$at,.L0f0f2574
/*  f0f2558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f255c:	10620005 */ 	beq	$v1,$v0,.L0f0f2574
/*  f0f2560:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f2564:	10410003 */ 	beq	$v0,$at,.L0f0f2574
/*  f0f2568:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f256c:	54410004 */ 	bnel	$v0,$at,.L0f0f2580
/*  f0f2570:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f2574:
/*  f0f2574:	03e00008 */ 	jr	$ra
/*  f0f2578:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0f257c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f2580:
/*  f0f2580:	03e00008 */ 	jr	$ra
/*  f0f2584:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f2588
/*  f0f2588:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0f258c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0f2590:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f2594:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0f2598:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f0f259c:	00808025 */ 	or	$s0,$a0,$zero
/*  f0f25a0:	3c048007 */ 	lui	$a0,0x8007
/*  f0f25a4:	31cf0400 */ 	andi	$t7,$t6,0x400
/*  f0f25a8:	11e00003 */ 	beqz	$t7,.L0f0f25b8
/*  f0f25ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f25b0:	1000002b */ 	beqz	$zero,.L0f0f2660
/*  f0f25b4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f25b8:
/*  f0f25b8:	0fc62ff6 */ 	jal	mpIsPlayerLockedOut
/*  f0f25bc:	8c841448 */ 	lw	$a0,0x1448($a0)
/*  f0f25c0:	10400007 */ 	beqz	$v0,.L0f0f25e0
/*  f0f25c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f25c8:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f0f25cc:	0018cb40 */ 	sll	$t9,$t8,0xd
/*  f0f25d0:	07210003 */ 	bgez	$t9,.L0f0f25e0
/*  f0f25d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f25d8:	10000021 */ 	beqz	$zero,.L0f0f2660
/*  f0f25dc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f25e0:
/*  f0f25e0:	0fc3c94d */ 	jal	func0f0f2534
/*  f0f25e4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f25e8:	50400004 */ 	beqzl	$v0,.L0f0f25fc
/*  f0f25ec:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f0f25f0:	1000001b */ 	beqz	$zero,.L0f0f2660
/*  f0f25f4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0f25f8:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f0f25fc:
/*  f0f25fc:	5040000e */ 	beqzl	$v0,.L0f0f2638
/*  f0f2600:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f2604:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f0f2608:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f0f260c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f2610:	31090004 */ 	andi	$t1,$t0,0x4
/*  f0f2614:	55200008 */ 	bnezl	$t1,.L0f0f2638
/*  f0f2618:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f261c:	0040f809 */ 	jalr	$v0
/*  f0f2620:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f0f2624:	50400004 */ 	beqzl	$v0,.L0f0f2638
/*  f0f2628:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f262c:	1000000c */ 	beqz	$zero,.L0f0f2660
/*  f0f2630:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0f2634:	02002025 */ 	or	$a0,$s0,$zero
.L0f0f2638:
/*  f0f2638:	27a5002e */ 	addiu	$a1,$sp,0x2e
/*  f0f263c:	27a6002c */ 	addiu	$a2,$sp,0x2c
/*  f0f2640:	0fc3c586 */ 	jal	func0f0f1618
/*  f0f2644:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0f2648:	87aa002c */ 	lh	$t2,0x2c($sp)
/*  f0f264c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f2650:	15400003 */ 	bnez	$t2,.L0f0f2660
/*  f0f2654:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2658:	10000001 */ 	beqz	$zero,.L0f0f2660
/*  f0f265c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f2660:
/*  f0f2660:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0f2664:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f2668:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0f266c:	03e00008 */ 	jr	$ra
/*  f0f2670:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f2674
/*  f0f2674:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0f2678:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f267c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0f2680:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f0f2684:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f0f2688:	908f0000 */ 	lbu	$t7,0x0($a0)
/*  f0f268c:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f0f2690:	2f010019 */ 	sltiu	$at,$t8,0x19
/*  f0f2694:	1020000d */ 	beqz	$at,.L0f0f26cc
/*  f0f2698:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f269c:	3c017f1b */ 	lui	$at,%hi(var7f1b28c4)
/*  f0f26a0:	00380821 */ 	addu	$at,$at,$t8
/*  f0f26a4:	8c3828c4 */ 	lw	$t8,%lo(var7f1b28c4)($at)
/*  f0f26a8:	03000008 */ 	jr	$t8
/*  f0f26ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f26b0:	1000000e */ 	beqz	$zero,.L0f0f26ec
/*  f0f26b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f26b8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f0f26bc:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f0f26c0:	27a6001c */ 	addiu	$a2,$sp,0x1c
/*  f0f26c4:	0fc3c8d5 */ 	jal	func0f0f2354
/*  f0f26c8:	27a70018 */ 	addiu	$a3,$sp,0x18
.L0f0f26cc:
/*  f0f26cc:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0f26d0:	0fc3c962 */ 	jal	func0f0f2588
/*  f0f26d4:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f0f26d8:	50400004 */ 	beqzl	$v0,.L0f0f26ec
/*  f0f26dc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0f26e0:	10000002 */ 	beqz	$zero,.L0f0f26ec
/*  f0f26e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f26e8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f26ec:
/*  f0f26ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f26f0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0f26f4:	03e00008 */ 	jr	$ra
/*  f0f26f8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f26fc
/*  f0f26fc:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f2700:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0f2704:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0f2708:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0f270c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f2710:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f2714:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f2718:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f271c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f2720:	00054080 */ 	sll	$t0,$a1,0x2
/*  f0f2724:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f2728:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f272c:	01054021 */ 	addu	$t0,$t0,$a1
/*  f0f2730:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0f2734:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f0f2738:	00084040 */ 	sll	$t0,$t0,0x1
/*  f0f273c:	00681021 */ 	addu	$v0,$v1,$t0
/*  f0f2740:	90590668 */ 	lbu	$t9,0x668($v0)
/*  f0f2744:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0f2748:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0f274c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0f2750:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0f2754:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f2758:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f275c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0f2760:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0f2764:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f2768:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f276c:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0f2770:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f0f2774:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f0f2778:	0000f025 */ 	or	$s8,$zero,$zero
/*  f0f277c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0f2780:	94520666 */ 	lhu	$s2,0x666($v0)
/*  f0f2784:	00009825 */ 	or	$s3,$zero,$zero
/*  f0f2788:	1b200033 */ 	blez	$t9,.L0f0f2858
/*  f0f278c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0f2790:	00128880 */ 	sll	$s1,$s2,0x2
/*  f0f2794:	00711021 */ 	addu	$v0,$v1,$s1
/*  f0f2798:	24170014 */ 	addiu	$s7,$zero,0x14
/*  f0f279c:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0f27a0:	904904fe */ 	lbu	$t1,0x4fe($v0)
.L0f0f27a4:
/*  f0f27a4:	8fab0068 */ 	lw	$t3,0x68($sp)
/*  f0f27a8:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f27ac:	01370019 */ 	multu	$t1,$s7
/*  f0f27b0:	8d6c0008 */ 	lw	$t4,0x8($t3)
/*  f0f27b4:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f0f27b8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0f27bc:	00005012 */ 	mflo	$t2
/*  f0f27c0:	014c8021 */ 	addu	$s0,$t2,$t4
/*  f0f27c4:	0fc3c99d */ 	jal	func0f0f2674
/*  f0f27c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f27cc:	10400009 */ 	beqz	$v0,.L0f0f27f4
/*  f0f27d0:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f0f27d4:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0f27d8:	0200f025 */ 	or	$s8,$s0,$zero
/*  f0f27dc:	8fae006c */ 	lw	$t6,0x6c($sp)
/*  f0f27e0:	028d082a */ 	slt	$at,$s4,$t5
/*  f0f27e4:	54200003 */ 	bnezl	$at,.L0f0f27f4
/*  f0f27e8:	add20000 */ 	sw	$s2,0x0($t6)
/*  f0f27ec:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f0f27f0:	add20000 */ 	sw	$s2,0x0($t6)
.L0f0f27f4:
/*  f0f27f4:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0f27f8:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f0f27fc:	3c19800a */ 	lui	$t9,%hi(var8009e000)
/*  f0f2800:	2739e000 */ 	addiu	$t9,$t9,%lo(var8009e000)
/*  f0f2804:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f2808:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f280c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f2810:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f2814:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f2818:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f281c:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f2820:	03191821 */ 	addu	$v1,$t8,$t9
/*  f0f2824:	00711021 */ 	addu	$v0,$v1,$s1
/*  f0f2828:	844904fc */ 	lh	$t1,0x4fc($v0)
/*  f0f282c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0f2830:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0f2834:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0f2838:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0f283c:	16a00006 */ 	bnez	$s5,.L0f0f2858
/*  f0f2840:	0134a021 */ 	addu	$s4,$t1,$s4
/*  f0f2844:	00685821 */ 	addu	$t3,$v1,$t0
/*  f0f2848:	916a0668 */ 	lbu	$t2,0x668($t3)
/*  f0f284c:	026a082a */ 	slt	$at,$s3,$t2
/*  f0f2850:	5420ffd4 */ 	bnezl	$at,.L0f0f27a4
/*  f0f2854:	904904fe */ 	lbu	$t1,0x4fe($v0)
.L0f0f2858:
/*  f0f2858:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f285c:	03c01025 */ 	or	$v0,$s8,$zero
/*  f0f2860:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0f2864:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f2868:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f286c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f2870:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0f2874:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0f2878:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0f287c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0f2880:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0f2884:	03e00008 */ 	jr	$ra
/*  f0f2888:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f0f288c
/*  f0f288c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0f2890:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f2894:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f0f2898:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0f289c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0f28a0:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f28a4:	908e0005 */ 	lbu	$t6,0x5($a0)
/*  f0f28a8:	00809025 */ 	or	$s2,$a0,$zero
/*  f0f28ac:	90900004 */ 	lbu	$s0,0x4($a0)
/*  f0f28b0:	19c00012 */ 	blez	$t6,.L0f0f28fc
/*  f0f28b4:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f28b8:	27b30034 */ 	addiu	$s3,$sp,0x34
/*  f0f28bc:	8e460000 */ 	lw	$a2,0x0($s2)
.L0f0f28c0:
/*  f0f28c0:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0f28c4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f28c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f28cc:	0fc3c9bf */ 	jal	func0f0f26fc
/*  f0f28d0:	02603825 */ 	or	$a3,$s3,$zero
/*  f0f28d4:	50400004 */ 	beqzl	$v0,.L0f0f28e8
/*  f0f28d8:	924f0005 */ 	lbu	$t7,0x5($s2)
/*  f0f28dc:	1000000c */ 	beqz	$zero,.L0f0f2910
/*  f0f28e0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f28e4:	924f0005 */ 	lbu	$t7,0x5($s2)
.L0f0f28e8:
/*  f0f28e8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f28ec:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0f28f0:	022f082a */ 	slt	$at,$s1,$t7
/*  f0f28f4:	5420fff2 */ 	bnezl	$at,.L0f0f28c0
/*  f0f28f8:	8e460000 */ 	lw	$a2,0x0($s2)
.L0f0f28fc:
/*  f0f28fc:	0fc3c560 */ 	jal	func0f0f1580
/*  f0f2900:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f2904:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0f2908:	8f020008 */ 	lw	$v0,0x8($t8)
/*  f0f290c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0f2910:
/*  f0f2910:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0f2914:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0f2918:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f0f291c:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f0f2920:	03e00008 */ 	jr	$ra
/*  f0f2924:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f0f2928
/*  f0f2928:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0f292c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f2930:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f0f2934:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0f2938:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0f293c:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f2940:	908e0004 */ 	lbu	$t6,0x4($a0)
/*  f0f2944:	90820005 */ 	lbu	$v0,0x5($a0)
/*  f0f2948:	00809025 */ 	or	$s2,$a0,$zero
/*  f0f294c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f2950:	01c28021 */ 	addu	$s0,$t6,$v0
/*  f0f2954:	18400012 */ 	blez	$v0,.L0f0f29a0
/*  f0f2958:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f0f295c:	27b3003c */ 	addiu	$s3,$sp,0x3c
/*  f0f2960:	8e460000 */ 	lw	$a2,0x0($s2)
.L0f0f2964:
/*  f0f2964:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0f2968:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f296c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f2970:	0fc3c9bf */ 	jal	func0f0f26fc
/*  f0f2974:	02603825 */ 	or	$a3,$s3,$zero
/*  f0f2978:	50400004 */ 	beqzl	$v0,.L0f0f298c
/*  f0f297c:	924f0005 */ 	lbu	$t7,0x5($s2)
/*  f0f2980:	1000000c */ 	beqz	$zero,.L0f0f29b4
/*  f0f2984:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f2988:	924f0005 */ 	lbu	$t7,0x5($s2)
.L0f0f298c:
/*  f0f298c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f2990:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f0f2994:	022f082a */ 	slt	$at,$s1,$t7
/*  f0f2998:	5420fff2 */ 	bnezl	$at,.L0f0f2964
/*  f0f299c:	8e460000 */ 	lw	$a2,0x0($s2)
.L0f0f29a0:
/*  f0f29a0:	0fc3c560 */ 	jal	func0f0f1580
/*  f0f29a4:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f29a8:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0f29ac:	8f020008 */ 	lw	$v0,0x8($t8)
/*  f0f29b0:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0f29b4:
/*  f0f29b4:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0f29b8:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0f29bc:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f0f29c0:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f0f29c4:	03e00008 */ 	jr	$ra
/*  f0f29c8:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f0f29cc
/*  f0f29cc:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0f29d0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0f29d4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f29d8:	00a09025 */ 	or	$s2,$a1,$zero
/*  f0f29dc:	00809825 */ 	or	$s3,$a0,$zero
/*  f0f29e0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f29e4:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0f29e8:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0f29ec:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0f29f0:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0f29f4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0f29f8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f29fc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f2a00:	00008025 */ 	or	$s0,$zero,$zero
/*  f0f2a04:	8e650008 */ 	lw	$a1,0x8($s3)
/*  f0f2a08:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f0f2a0c:	0fc3c8d5 */ 	jal	func0f0f2354
/*  f0f2a10:	27a70058 */ 	addiu	$a3,$sp,0x58
/*  f0f2a14:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f0f2a18:	3c168007 */ 	lui	$s6,%hi(g_MpPlayerNum)
/*  f0f2a1c:	3c15800a */ 	lui	$s5,%hi(var8009e000)
/*  f0f2a20:	26b5e000 */ 	addiu	$s5,$s5,%lo(var8009e000)
/*  f0f2a24:	26d61448 */ 	addiu	$s6,$s6,%lo(g_MpPlayerNum)
/*  f0f2a28:	241e0014 */ 	addiu	$s8,$zero,0x14
/*  f0f2a2c:	2417000a */ 	addiu	$s7,$zero,0xa
/*  f0f2a30:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f0f2a34:	8fb80058 */ 	lw	$t8,0x58($sp)
.L0f0f2a38:
/*  f0f2a38:	8ece0000 */ 	lw	$t6,0x0($s6)
/*  f0f2a3c:	00b22821 */ 	addu	$a1,$a1,$s2
/*  f0f2a40:	03170019 */ 	multu	$t8,$s7
/*  f0f2a44:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f2a48:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f2a4c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f2a50:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f2a54:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f2a58:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f2a5c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f2a60:	02af3821 */ 	addu	$a3,$s5,$t7
/*  f0f2a64:	0000c812 */ 	mflo	$t9
/*  f0f2a68:	00f91021 */ 	addu	$v0,$a3,$t9
/*  f0f2a6c:	94430666 */ 	lhu	$v1,0x666($v0)
/*  f0f2a70:	90480668 */ 	lbu	$t0,0x668($v0)
/*  f0f2a74:	01032021 */ 	addu	$a0,$t0,$v1
/*  f0f2a78:	00a4082a */ 	slt	$at,$a1,$a0
/*  f0f2a7c:	54200003 */ 	bnezl	$at,.L0f0f2a8c
/*  f0f2a80:	00a3082a */ 	slt	$at,$a1,$v1
/*  f0f2a84:	00602825 */ 	or	$a1,$v1,$zero
/*  f0f2a88:	00a3082a */ 	slt	$at,$a1,$v1
.L0f0f2a8c:
/*  f0f2a8c:	10200003 */ 	beqz	$at,.L0f0f2a9c
/*  f0f2a90:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f0f2a94:	2485ffff */ 	addiu	$a1,$a0,-1
/*  f0f2a98:	afa5005c */ 	sw	$a1,0x5c($sp)
.L0f0f2a9c:
/*  f0f2a9c:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*  f0f2aa0:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0f2aa4:	02602825 */ 	or	$a1,$s3,$zero
/*  f0f2aa8:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0f2aac:	00ea5821 */ 	addu	$t3,$a3,$t2
/*  f0f2ab0:	916c04fe */ 	lbu	$t4,0x4fe($t3)
/*  f0f2ab4:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*  f0f2ab8:	02403025 */ 	or	$a2,$s2,$zero
/*  f0f2abc:	019e0019 */ 	multu	$t4,$s8
/*  f0f2ac0:	00006812 */ 	mflo	$t5
/*  f0f2ac4:	01af8821 */ 	addu	$s1,$t5,$t7
/*  f0f2ac8:	0fc3c99d */ 	jal	func0f0f2674
/*  f0f2acc:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f2ad0:	10400002 */ 	beqz	$v0,.L0f0f2adc
/*  f0f2ad4:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f0f2ad8:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0f2adc:
/*  f0f2adc:	14b40002 */ 	bne	$a1,$s4,.L0f0f2ae8
/*  f0f2ae0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2ae4:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0f2ae8:
/*  f0f2ae8:	5200ffd3 */ 	beqzl	$s0,.L0f0f2a38
/*  f0f2aec:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f0f2af0:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f0f2af4:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f0f2af8:	ae710008 */ 	sw	$s1,0x8($s3)
/*  f0f2afc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f2b00:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0f2b04:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0f2b08:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0f2b0c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0f2b10:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0f2b14:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0f2b18:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f2b1c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f2b20:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f2b24:	03e00008 */ 	jr	$ra
/*  f0f2b28:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f0f2b2c
/*  f0f2b2c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0f2b30:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f0f2b34:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f0f2b38:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0f2b3c:	00808025 */ 	or	$s0,$a0,$zero
/*  f0f2b40:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f0f2b44:	27b6005c */ 	addiu	$s6,$sp,0x5c
/*  f0f2b48:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f2b4c:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f0f2b50:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f0f2b54:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0f2b58:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0f2b5c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f2b60:	00009025 */ 	or	$s2,$zero,$zero
/*  f0f2b64:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f0f2b68:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0f2b6c:	0fc3c8d5 */ 	jal	func0f0f2354
/*  f0f2b70:	27a70058 */ 	addiu	$a3,$sp,0x58
/*  f0f2b74:	00409825 */ 	or	$s3,$v0,$zero
/*  f0f2b78:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f0f2b7c:	8fae0058 */ 	lw	$t6,0x58($sp)
.L0f0f2b80:
/*  f0f2b80:	02602025 */ 	or	$a0,$s3,$zero
/*  f0f2b84:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f2b88:	01d57821 */ 	addu	$t7,$t6,$s5
/*  f0f2b8c:	afaf0058 */ 	sw	$t7,0x58($sp)
/*  f0f2b90:	92180005 */ 	lbu	$t8,0x5($s0)
/*  f0f2b94:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0f2b98:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f0f2b9c:	01f9082a */ 	slt	$at,$t7,$t9
/*  f0f2ba0:	54200005 */ 	bnezl	$at,.L0f0f2bb8
/*  f0f2ba4:	8fa80058 */ 	lw	$t0,0x58($sp)
/*  f0f2ba8:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f0f2bac:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0f2bb0:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0f2bb4:	8fa80058 */ 	lw	$t0,0x58($sp)
.L0f0f2bb8:
/*  f0f2bb8:	0102082a */ 	slt	$at,$t0,$v0
/*  f0f2bbc:	50200007 */ 	beqzl	$at,.L0f0f2bdc
/*  f0f2bc0:	8e060000 */ 	lw	$a2,0x0($s0)
/*  f0f2bc4:	92090005 */ 	lbu	$t1,0x5($s0)
/*  f0f2bc8:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f0f2bcc:	00495021 */ 	addu	$t2,$v0,$t1
/*  f0f2bd0:	254bffff */ 	addiu	$t3,$t2,-1
/*  f0f2bd4:	afab0058 */ 	sw	$t3,0x58($sp)
/*  f0f2bd8:	8e060000 */ 	lw	$a2,0x0($s0)
.L0f0f2bdc:
/*  f0f2bdc:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f2be0:	0fc3c9bf */ 	jal	func0f0f26fc
/*  f0f2be4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0f2be8:	10400002 */ 	beqz	$v0,.L0f0f2bf4
/*  f0f2bec:	00401825 */ 	or	$v1,$v0,$zero
/*  f0f2bf0:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f0f2bf4:
/*  f0f2bf4:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f0f2bf8:	15940002 */ 	bne	$t4,$s4,.L0f0f2c04
/*  f0f2bfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2c00:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f0f2c04:
/*  f0f2c04:	5220ffde */ 	beqzl	$s1,.L0f0f2b80
/*  f0f2c08:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f0f2c0c:	10600002 */ 	beqz	$v1,.L0f0f2c18
/*  f0f2c10:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0f2c14:	ae030008 */ 	sw	$v1,0x8($s0)
.L0f0f2c18:
/*  f0f2c18:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f2c1c:	02401025 */ 	or	$v0,$s2,$zero
/*  f0f2c20:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0f2c24:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0f2c28:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0f2c2c:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f0f2c30:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f0f2c34:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f0f2c38:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f0f2c3c:	03e00008 */ 	jr	$ra
/*  f0f2c40:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f0f2c44
/*  f0f2c44:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0f2c48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f2c4c:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0f2c50:	00a03825 */ 	or	$a3,$a1,$zero
/*  f0f2c54:	14a00005 */ 	bnez	$a1,.L0f0f2c6c
/*  f0f2c58:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f2c5c:	14c00003 */ 	bnez	$a2,.L0f0f2c6c
/*  f0f2c60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2c64:	1000001f */ 	beqz	$zero,.L0f0f2ce4
/*  f0f2c68:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f2c6c:
/*  f0f2c6c:	10c00007 */ 	beqz	$a2,.L0f0f2c8c
/*  f0f2c70:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0f2c74:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0f2c78:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0f2c7c:	0fc3ca73 */ 	jal	func0f0f29cc
/*  f0f2c80:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f0f2c84:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0f2c88:	8fa7003c */ 	lw	$a3,0x3c($sp)
.L0f0f2c8c:
/*  f0f2c8c:	10e00004 */ 	beqz	$a3,.L0f0f2ca0
/*  f0f2c90:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0f2c94:	0fc3cacb */ 	jal	func0f0f2b2c
/*  f0f2c98:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0f2c9c:	00401825 */ 	or	$v1,$v0,$zero
.L0f0f2ca0:
/*  f0f2ca0:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f0f2ca4:	8dc50008 */ 	lw	$a1,0x8($t6)
/*  f0f2ca8:	50a0000e */ 	beqzl	$a1,.L0f0f2ce4
/*  f0f2cac:	00601025 */ 	or	$v0,$v1,$zero
/*  f0f2cb0:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f0f2cb4:	5040000b */ 	beqzl	$v0,.L0f0f2ce4
/*  f0f2cb8:	00601025 */ 	or	$v0,$v1,$zero
/*  f0f2cbc:	8caf0004 */ 	lw	$t7,0x4($a1)
/*  f0f2cc0:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f0f2cc4:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f0f2cc8:	31f80004 */ 	andi	$t8,$t7,0x4
/*  f0f2ccc:	57000005 */ 	bnezl	$t8,.L0f0f2ce4
/*  f0f2cd0:	00601025 */ 	or	$v0,$v1,$zero
/*  f0f2cd4:	0040f809 */ 	jalr	$v0
/*  f0f2cd8:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0f2cdc:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0f2ce0:	00601025 */ 	or	$v0,$v1,$zero
.L0f0f2ce4:
/*  f0f2ce4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f2ce8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0f2cec:	03e00008 */ 	jr	$ra
/*  f0f2cf0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f2cf4
/*  f0f2cf4:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0f2cf8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0f2cfc:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0f2d00:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0f2d04:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f2d08:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f2d0c:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f0f2d10:	aca40000 */ 	sw	$a0,0x0($a1)
/*  f0f2d14:	3c02800a */ 	lui	$v0,0x800a
/*  f0f2d18:	8c4219c4 */ 	lw	$v0,0x19c4($v0)
/*  f0f2d1c:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0f2d20:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f2d24:	1041000d */ 	beq	$v0,$at,.L0f0f2d5c
/*  f0f2d28:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f2d2c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f2d30:	10410008 */ 	beq	$v0,$at,.L0f0f2d54
/*  f0f2d34:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f2d38:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0f2d3c:	10410005 */ 	beq	$v0,$at,.L0f0f2d54
/*  f0f2d40:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f2d44:	50410006 */ 	beql	$v0,$at,.L0f0f2d60
/*  f0f2d48:	a220006e */ 	sb	$zero,0x6e($s1)
/*  f0f2d4c:	10000004 */ 	beqz	$zero,.L0f0f2d60
/*  f0f2d50:	a220006e */ 	sb	$zero,0x6e($s1)
.L0f0f2d54:
/*  f0f2d54:	10000002 */ 	beqz	$zero,.L0f0f2d60
/*  f0f2d58:	a22e006e */ 	sb	$t6,0x6e($s1)
.L0f0f2d5c:
/*  f0f2d5c:	a220006e */ 	sb	$zero,0x6e($s1)
.L0f0f2d60:
/*  f0f2d60:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f0f2d64:	0fc3c75b */ 	jal	func0f0f1d6c
/*  f0f2d68:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f0f2d6c:	0fc3e95d */ 	jal	func0f0fa574
/*  f0f2d70:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f2d74:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0f2d78:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f2d7c:	44812000 */ 	mtc1	$at,$f4
/*  f0f2d80:	44803000 */ 	mtc1	$zero,$f6
/*  f0f2d84:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f0f2d88:	e6240040 */ 	swc1	$f4,0x40($s1)
/*  f0f2d8c:	e6260048 */ 	swc1	$f6,0x48($s1)
/*  f0f2d90:	0c004b70 */ 	jal	random
/*  f0f2d94:	a238003c */ 	sb	$t8,0x3c($s1)
/*  f0f2d98:	44824000 */ 	mtc1	$v0,$f8
/*  f0f2d9c:	3c03800a */ 	lui	$v1,%hi(var8009e000)
/*  f0f2da0:	3c058007 */ 	lui	$a1,%hi(g_MpPlayerNum)
/*  f0f2da4:	24a51448 */ 	addiu	$a1,$a1,%lo(g_MpPlayerNum)
/*  f0f2da8:	2463e000 */ 	addiu	$v1,$v1,%lo(var8009e000)
/*  f0f2dac:	24060e70 */ 	addiu	$a2,$zero,0xe70
/*  f0f2db0:	04410005 */ 	bgez	$v0,.L0f0f2dc8
/*  f0f2db4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0f2db8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0f2dbc:	44818000 */ 	mtc1	$at,$f16
/*  f0f2dc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2dc4:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0f2dc8:
/*  f0f2dc8:	3c012f80 */ 	lui	$at,0x2f80
/*  f0f2dcc:	44819000 */ 	mtc1	$at,$f18
/*  f0f2dd0:	3c017f1b */ 	lui	$at,%hi(var7f1b2928)
/*  f0f2dd4:	c4262928 */ 	lwc1	$f6,%lo(var7f1b2928)($at)
/*  f0f2dd8:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0f2ddc:	44808000 */ 	mtc1	$zero,$f16
/*  f0f2de0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f2de4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0f2de8:	e628004c */ 	swc1	$f8,0x4c($s1)
/*  f0f2dec:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f0f2df0:	03260019 */ 	multu	$t9,$a2
/*  f0f2df4:	00004012 */ 	mflo	$t0
/*  f0f2df8:	00684821 */ 	addu	$t1,$v1,$t0
/*  f0f2dfc:	8d2a04f8 */ 	lw	$t2,0x4f8($t1)
/*  f0f2e00:	a1400060 */ 	sb	$zero,0x60($t2)
/*  f0f2e04:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f0f2e08:	01660019 */ 	multu	$t3,$a2
/*  f0f2e0c:	00006012 */ 	mflo	$t4
/*  f0f2e10:	006c6821 */ 	addu	$t5,$v1,$t4
/*  f0f2e14:	8dae04f8 */ 	lw	$t6,0x4f8($t5)
/*  f0f2e18:	e5d00050 */ 	swc1	$f16,0x50($t6)
/*  f0f2e1c:	ae200054 */ 	sw	$zero,0x54($s1)
/*  f0f2e20:	ae200058 */ 	sw	$zero,0x58($s1)
/*  f0f2e24:	0fc3ca23 */ 	jal	func0f0f288c
/*  f0f2e28:	ae20005c */ 	sw	$zero,0x5c($s1)
/*  f0f2e2c:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f0f2e30:	ae220008 */ 	sw	$v0,0x8($s1)
/*  f0f2e34:	2412001a */ 	addiu	$s2,$zero,0x1a
/*  f0f2e38:	8df00008 */ 	lw	$s0,0x8($t7)
/*  f0f2e3c:	27b30044 */ 	addiu	$s3,$sp,0x44
/*  f0f2e40:	92180000 */ 	lbu	$t8,0x0($s0)
/*  f0f2e44:	52580014 */ 	beql	$s2,$t8,.L0f0f2e98
/*  f0f2e48:	8e250008 */ 	lw	$a1,0x8($s1)
/*  f0f2e4c:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f0f2e50:
/*  f0f2e50:	5040000d */ 	beqzl	$v0,.L0f0f2e88
/*  f0f2e54:	92090014 */ 	lbu	$t1,0x14($s0)
/*  f0f2e58:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0f2e5c:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f0f2e60:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f2e64:	33280004 */ 	andi	$t0,$t9,0x4
/*  f0f2e68:	55000007 */ 	bnezl	$t0,.L0f0f2e88
/*  f0f2e6c:	92090014 */ 	lbu	$t1,0x14($s0)
/*  f0f2e70:	0040f809 */ 	jalr	$v0
/*  f0f2e74:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f2e78:	50400003 */ 	beqzl	$v0,.L0f0f2e88
/*  f0f2e7c:	92090014 */ 	lbu	$t1,0x14($s0)
/*  f0f2e80:	ae300008 */ 	sw	$s0,0x8($s1)
/*  f0f2e84:	92090014 */ 	lbu	$t1,0x14($s0)
.L0f0f2e88:
/*  f0f2e88:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f0f2e8c:	5649fff0 */ 	bnel	$s2,$t1,.L0f0f2e50
/*  f0f2e90:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f0f2e94:	8e250008 */ 	lw	$a1,0x8($s1)
.L0f0f2e98:
/*  f0f2e98:	50a0000c */ 	beqzl	$a1,.L0f0f2ecc
/*  f0f2e9c:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f2ea0:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f0f2ea4:	50400009 */ 	beqzl	$v0,.L0f0f2ecc
/*  f0f2ea8:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f2eac:	8caa0004 */ 	lw	$t2,0x4($a1)
/*  f0f2eb0:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f0f2eb4:	314b0004 */ 	andi	$t3,$t2,0x4
/*  f0f2eb8:	55600004 */ 	bnezl	$t3,.L0f0f2ecc
/*  f0f2ebc:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f2ec0:	0040f809 */ 	jalr	$v0
/*  f0f2ec4:	27a60034 */ 	addiu	$a2,$sp,0x34
/*  f0f2ec8:	8fa70068 */ 	lw	$a3,0x68($sp)
.L0f0f2ecc:
/*  f0f2ecc:	ae20000c */ 	sw	$zero,0xc($s1)
/*  f0f2ed0:	ae200064 */ 	sw	$zero,0x64($s1)
/*  f0f2ed4:	ae200068 */ 	sw	$zero,0x68($s1)
/*  f0f2ed8:	8ce2000c */ 	lw	$v0,0xc($a3)
/*  f0f2edc:	24040064 */ 	addiu	$a0,$zero,0x64
/*  f0f2ee0:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0f2ee4:	50400005 */ 	beqzl	$v0,.L0f0f2efc
/*  f0f2ee8:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0f2eec:	0040f809 */ 	jalr	$v0
/*  f0f2ef0:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0f2ef4:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f2ef8:	00e02025 */ 	or	$a0,$a3,$zero
.L0f0f2efc:
/*  f0f2efc:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f2f00:	0fc3c84d */ 	jal	func0f0f2134
/*  f0f2f04:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f0f2f08:	0fc3dfa6 */ 	jal	func0f0f7e98
/*  f0f2f0c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f2f10:	8e2c002c */ 	lw	$t4,0x2c($s1)
/*  f0f2f14:	8e2d0030 */ 	lw	$t5,0x30($s1)
/*  f0f2f18:	8e2e0034 */ 	lw	$t6,0x34($s1)
/*  f0f2f1c:	8e2f0038 */ 	lw	$t7,0x38($s1)
/*  f0f2f20:	ae2c0014 */ 	sw	$t4,0x14($s1)
/*  f0f2f24:	ae2d0018 */ 	sw	$t5,0x18($s1)
/*  f0f2f28:	ae2e001c */ 	sw	$t6,0x1c($s1)
/*  f0f2f2c:	ae2f0020 */ 	sw	$t7,0x20($s1)
/*  f0f2f30:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f2f34:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0f2f38:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0f2f3c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0f2f40:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0f2f44:	03e00008 */ 	jr	$ra
/*  f0f2f48:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel menuPushDialog
/*  f0f2f4c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0f2f50:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f2f54:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0f2f58:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0f2f5c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0f2f60:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0f2f64:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0f2f68:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0f2f6c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f2f70:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f2f74:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f2f78:	1080009d */ 	beqz	$a0,.L0f0f31f0
/*  f0f2f7c:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f0f2f80:	3c158007 */ 	lui	$s5,%hi(g_MpPlayerNum)
/*  f0f2f84:	26b51448 */ 	addiu	$s5,$s5,%lo(g_MpPlayerNum)
/*  f0f2f88:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f0f2f8c:	24160e70 */ 	addiu	$s6,$zero,0xe70
/*  f0f2f90:	3c14800a */ 	lui	$s4,%hi(var8009e000)
/*  f0f2f94:	01f60019 */ 	multu	$t7,$s6
/*  f0f2f98:	2694e000 */ 	addiu	$s4,$s4,%lo(var8009e000)
/*  f0f2f9c:	0000c012 */ 	mflo	$t8
/*  f0f2fa0:	02982021 */ 	addu	$a0,$s4,$t8
/*  f0f2fa4:	0fc3cde9 */ 	jal	func0f0f37a4
/*  f0f2fa8:	24840840 */ 	addiu	$a0,$a0,0x840
/*  f0f2fac:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f0f2fb0:	03360019 */ 	multu	$t9,$s6
/*  f0f2fb4:	00004012 */ 	mflo	$t0
/*  f0f2fb8:	02881821 */ 	addu	$v1,$s4,$t0
/*  f0f2fbc:	846704f4 */ 	lh	$a3,0x4f4($v1)
/*  f0f2fc0:	28e10006 */ 	slti	$at,$a3,0x6
/*  f0f2fc4:	5020008b */ 	beqzl	$at,.L0f0f31f4
/*  f0f2fc8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f2fcc:	84690460 */ 	lh	$t1,0x460($v1)
/*  f0f2fd0:	00075080 */ 	sll	$t2,$a3,0x2
/*  f0f2fd4:	01475023 */ 	subu	$t2,$t2,$a3
/*  f0f2fd8:	2921000a */ 	slti	$at,$t1,0xa
/*  f0f2fdc:	10200084 */ 	beqz	$at,.L0f0f31f0
/*  f0f2fe0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0f2fe4:	24eb0001 */ 	addiu	$t3,$a3,0x1
/*  f0f2fe8:	006a8821 */ 	addu	$s1,$v1,$t2
/*  f0f2fec:	a46b04f4 */ 	sh	$t3,0x4f4($v1)
/*  f0f2ff0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f2ff4:	a22c0478 */ 	sb	$t4,0x478($s1)
/*  f0f2ff8:	a2200479 */ 	sb	$zero,0x479($s1)
/*  f0f2ffc:	8ead0000 */ 	lw	$t5,0x0($s5)
/*  f0f3000:	241e0070 */ 	addiu	$s8,$zero,0x70
/*  f0f3004:	26310464 */ 	addiu	$s1,$s1,0x464
/*  f0f3008:	01b60019 */ 	multu	$t5,$s6
/*  f0f300c:	00007012 */ 	mflo	$t6
/*  f0f3010:	028e1821 */ 	addu	$v1,$s4,$t6
/*  f0f3014:	84620460 */ 	lh	$v0,0x460($v1)
/*  f0f3018:	005e0019 */ 	multu	$v0,$s8
/*  f0f301c:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f0f3020:	a4780460 */ 	sh	$t8,0x460($v1)
/*  f0f3024:	00007812 */ 	mflo	$t7
/*  f0f3028:	006f8021 */ 	addu	$s0,$v1,$t7
/*  f0f302c:	ae300000 */ 	sw	$s0,0x0($s1)
/*  f0f3030:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f0f3034:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f3038:	03360019 */ 	multu	$t9,$s6
/*  f0f303c:	00004012 */ 	mflo	$t0
/*  f0f3040:	02884821 */ 	addu	$t1,$s4,$t0
/*  f0f3044:	ad3004f8 */ 	sw	$s0,0x4f8($t1)
/*  f0f3048:	a200006d */ 	sb	$zero,0x6d($s0)
/*  f0f304c:	8eaa0000 */ 	lw	$t2,0x0($s5)
/*  f0f3050:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f3054:	01560019 */ 	multu	$t2,$s6
/*  f0f3058:	00005812 */ 	mflo	$t3
/*  f0f305c:	028b3021 */ 	addu	$a2,$s4,$t3
/*  f0f3060:	0fc3cb3d */ 	jal	func0f0f2cf4
/*  f0f3064:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3068:	0c002f02 */ 	jal	func0000bc08
/*  f0f306c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3070:	8e0c001c */ 	lw	$t4,0x1c($s0)
/*  f0f3074:	004c6823 */ 	subu	$t5,$v0,$t4
/*  f0f3078:	05a10003 */ 	bgez	$t5,.L0f0f3088
/*  f0f307c:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f0f3080:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f0f3084:	00017043 */ 	sra	$t6,$at,0x1
.L0f0f3088:
/*  f0f3088:	0c002f06 */ 	jal	func0000bc18
/*  f0f308c:	ae0e002c */ 	sw	$t6,0x2c($s0)
/*  f0f3090:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f0f3094:	004fc023 */ 	subu	$t8,$v0,$t7
/*  f0f3098:	07010003 */ 	bgez	$t8,.L0f0f30a8
/*  f0f309c:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f30a0:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f30a4:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f30a8:
/*  f0f30a8:	ae190030 */ 	sw	$t9,0x30($s0)
/*  f0f30ac:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f0f30b0:	8fad0040 */ 	lw	$t5,0x40($sp)
/*  f0f30b4:	01160019 */ 	multu	$t0,$s6
/*  f0f30b8:	00004812 */ 	mflo	$t1
/*  f0f30bc:	02891821 */ 	addu	$v1,$s4,$t1
/*  f0f30c0:	906b0e40 */ 	lbu	$t3,0xe40($v1)
/*  f0f30c4:	356c0080 */ 	ori	$t4,$t3,0x80
/*  f0f30c8:	a06c0e40 */ 	sb	$t4,0xe40($v1)
/*  f0f30cc:	8db20014 */ 	lw	$s2,0x14($t5)
/*  f0f30d0:	12400037 */ 	beqz	$s2,.L0f0f31b0
/*  f0f30d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f30d8:	822e0014 */ 	lb	$t6,0x14($s1)
/*  f0f30dc:	2417ffff */ 	addiu	$s7,$zero,-1
/*  f0f30e0:	2413fec0 */ 	addiu	$s3,$zero,-320
/*  f0f30e4:	29c10005 */ 	slti	$at,$t6,0x5
/*  f0f30e8:	10200031 */ 	beqz	$at,.L0f0f31b0
/*  f0f30ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f30f0:	8eaf0000 */ 	lw	$t7,0x0($s5)
.L0f0f30f4:
/*  f0f30f4:	01f60019 */ 	multu	$t7,$s6
/*  f0f30f8:	0000c012 */ 	mflo	$t8
/*  f0f30fc:	02981821 */ 	addu	$v1,$s4,$t8
/*  f0f3100:	84620460 */ 	lh	$v0,0x460($v1)
/*  f0f3104:	2841000a */ 	slti	$at,$v0,0xa
/*  f0f3108:	10200023 */ 	beqz	$at,.L0f0f3198
/*  f0f310c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3110:	005e0019 */ 	multu	$v0,$s8
/*  f0f3114:	24480001 */ 	addiu	$t0,$v0,0x1
/*  f0f3118:	a4680460 */ 	sh	$t0,0x460($v1)
/*  f0f311c:	82290014 */ 	lb	$t1,0x14($s1)
/*  f0f3120:	02402025 */ 	or	$a0,$s2,$zero
/*  f0f3124:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0f3128:	022a5821 */ 	addu	$t3,$s1,$t2
/*  f0f312c:	0000c812 */ 	mflo	$t9
/*  f0f3130:	00798021 */ 	addu	$s0,$v1,$t9
/*  f0f3134:	ad700000 */ 	sw	$s0,0x0($t3)
/*  f0f3138:	822c0014 */ 	lb	$t4,0x14($s1)
/*  f0f313c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f3140:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f0f3144:	a22d0014 */ 	sb	$t5,0x14($s1)
/*  f0f3148:	a217006d */ 	sb	$s7,0x6d($s0)
/*  f0f314c:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f0f3150:	01d60019 */ 	multu	$t6,$s6
/*  f0f3154:	00007812 */ 	mflo	$t7
/*  f0f3158:	028f3021 */ 	addu	$a2,$s4,$t7
/*  f0f315c:	0fc3cb3d */ 	jal	func0f0f2cf4
/*  f0f3160:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3164:	ae130014 */ 	sw	$s3,0x14($s0)
/*  f0f3168:	0c002f06 */ 	jal	func0000bc18
/*  f0f316c:	ae13002c */ 	sw	$s3,0x2c($s0)
/*  f0f3170:	8e180020 */ 	lw	$t8,0x20($s0)
/*  f0f3174:	a200003c */ 	sb	$zero,0x3c($s0)
/*  f0f3178:	00581823 */ 	subu	$v1,$v0,$t8
/*  f0f317c:	04610003 */ 	bgez	$v1,.L0f0f318c
/*  f0f3180:	0003c843 */ 	sra	$t9,$v1,0x1
/*  f0f3184:	24610001 */ 	addiu	$at,$v1,0x1
/*  f0f3188:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f318c:
/*  f0f318c:	ae190018 */ 	sw	$t9,0x18($s0)
/*  f0f3190:	ae190030 */ 	sw	$t9,0x30($s0)
/*  f0f3194:	8e520014 */ 	lw	$s2,0x14($s2)
.L0f0f3198:
/*  f0f3198:	12400005 */ 	beqz	$s2,.L0f0f31b0
/*  f0f319c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f31a0:	82280014 */ 	lb	$t0,0x14($s1)
/*  f0f31a4:	29010005 */ 	slti	$at,$t0,0x5
/*  f0f31a8:	5420ffd2 */ 	bnezl	$at,.L0f0f30f4
/*  f0f31ac:	8eaf0000 */ 	lw	$t7,0x0($s5)
.L0f0f31b0:
/*  f0f31b0:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0f31b4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f31b8:	8fa90040 */ 	lw	$t1,0x40($sp)
/*  f0f31bc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f31c0:	91220000 */ 	lbu	$v0,0x0($t1)
/*  f0f31c4:	54410006 */ 	bnel	$v0,$at,.L0f0f31e0
/*  f0f31c8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f31cc:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0f31d0:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0f31d4:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f0f31d8:	91420000 */ 	lbu	$v0,0x0($t2)
/*  f0f31dc:	24010003 */ 	addiu	$at,$zero,0x3
.L0f0f31e0:
/*  f0f31e0:	54410004 */ 	bnel	$v0,$at,.L0f0f31f4
/*  f0f31e4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f31e8:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0f31ec:	2404000e */ 	addiu	$a0,$zero,0xe
.L0f0f31f0:
/*  f0f31f0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0f31f4:
/*  f0f31f4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f31f8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f31fc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f3200:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0f3204:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0f3208:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0f320c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0f3210:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0f3214:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0f3218:	03e00008 */ 	jr	$ra
/*  f0f321c:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f0f3220
/*  f0f3220:	3c03800a */ 	lui	$v1,0x800a
/*  f0f3224:	00641821 */ 	addu	$v1,$v1,$a0
/*  f0f3228:	90632029 */ 	lbu	$v1,0x2029($v1)
/*  f0f322c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0f3230:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f3234:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f3238:	1461003d */ 	bne	$v1,$at,.L0f0f3330
/*  f0f323c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f3240:	3c078007 */ 	lui	$a3,%hi(g_MpPlayerNum)
/*  f0f3244:	24e71448 */ 	addiu	$a3,$a3,%lo(g_MpPlayerNum)
/*  f0f3248:	3c03800a */ 	lui	$v1,%hi(var800a0b50)
/*  f0f324c:	8ce90000 */ 	lw	$t1,0x0($a3)
/*  f0f3250:	24630b50 */ 	addiu	$v1,$v1,%lo(var800a0b50)
/*  f0f3254:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f0f3258:
/*  f0f3258:	8c6e04f8 */ 	lw	$t6,0x4f8($v1)
/*  f0f325c:	51c00003 */ 	beqzl	$t6,.L0f0f326c
/*  f0f3260:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0f3264:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f0f3268:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f0f326c:
/*  f0f326c:	0441fffa */ 	bgez	$v0,.L0f0f3258
/*  f0f3270:	2463f190 */ 	addiu	$v1,$v1,-3696
/*  f0f3274:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f0f3278:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0f327c:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0f3280:	000278c0 */ 	sll	$t7,$v0,0x3
/*  f0f3284:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f0f3288:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f328c:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f0f3290:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f3294:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f0f3298:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f329c:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f0f32a0:	847904f4 */ 	lh	$t9,0x4f4($v1)
/*  f0f32a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f32a8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f32ac:	2b210002 */ 	slti	$at,$t9,0x2
/*  f0f32b0:	54200003 */ 	bnezl	$at,.L0f0f32c0
/*  f0f32b4:	8c6404f8 */ 	lw	$a0,0x4f8($v1)
/*  f0f32b8:	00004025 */ 	or	$t0,$zero,$zero
/*  f0f32bc:	8c6404f8 */ 	lw	$a0,0x4f8($v1)
.L0f0f32c0:
/*  f0f32c0:	1080000f */ 	beqz	$a0,.L0f0f3300
/*  f0f32c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f32c8:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0f32cc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f32d0:	3c0b8008 */ 	lui	$t3,%hi(menudialog_2aa60)
/*  f0f32d4:	904a0000 */ 	lbu	$t2,0x0($v0)
/*  f0f32d8:	256b4a40 */ 	addiu	$t3,$t3,%lo(menudialog_2aa60)
/*  f0f32dc:	15410008 */ 	bne	$t2,$at,.L0f0f3300
/*  f0f32e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f32e4:	11620005 */ 	beq	$t3,$v0,.L0f0f32fc
/*  f0f32e8:	00004025 */ 	or	$t0,$zero,$zero
/*  f0f32ec:	3c0c8008 */ 	lui	$t4,%hi(menudialog_2aa78)
/*  f0f32f0:	258c4a58 */ 	addiu	$t4,$t4,%lo(menudialog_2aa78)
/*  f0f32f4:	15820002 */ 	bne	$t4,$v0,.L0f0f3300
/*  f0f32f8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f32fc:
/*  f0f32fc:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0f3300:
/*  f0f3300:	11000009 */ 	beqz	$t0,.L0f0f3328
/*  f0f3304:	3c04800a */ 	lui	$a0,%hi(var800a22c0)
/*  f0f3308:	248422c0 */ 	addiu	$a0,$a0,%lo(var800a22c0)
/*  f0f330c:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f0f3310:	0fc42539 */ 	jal	func0f1094e4
/*  f0f3314:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0f3318:	3c078007 */ 	lui	$a3,%hi(g_MpPlayerNum)
/*  f0f331c:	24e71448 */ 	addiu	$a3,$a3,%lo(g_MpPlayerNum)
/*  f0f3320:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f0f3324:	8fa9001c */ 	lw	$t1,0x1c($sp)
.L0f0f3328:
/*  f0f3328:	10000019 */ 	beqz	$zero,.L0f0f3390
/*  f0f332c:	ace90000 */ 	sw	$t1,0x0($a3)
.L0f0f3330:
/*  f0f3330:	28610004 */ 	slti	$at,$v1,0x4
/*  f0f3334:	10200016 */ 	beqz	$at,.L0f0f3390
/*  f0f3338:	3c078007 */ 	lui	$a3,%hi(g_MpPlayerNum)
/*  f0f333c:	00037080 */ 	sll	$t6,$v1,0x2
/*  f0f3340:	24e71448 */ 	addiu	$a3,$a3,%lo(g_MpPlayerNum)
/*  f0f3344:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f0f3348:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f0f334c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f0f3350:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f0f3354:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f0f3358:	25cf004c */ 	addiu	$t7,$t6,0x4c
/*  f0f335c:	ace30000 */ 	sw	$v1,0x0($a3)
/*  f0f3360:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f0f3364:	00601025 */ 	or	$v0,$v1,$zero
/*  f0f3368:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f0f336c:	00603025 */ 	or	$a2,$v1,$zero
/*  f0f3370:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f0f3374:	0fc42539 */ 	jal	func0f1094e4
/*  f0f3378:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f337c:	8fb90018 */ 	lw	$t9,0x18($sp)
/*  f0f3380:	3c078007 */ 	lui	$a3,%hi(g_MpPlayerNum)
/*  f0f3384:	24e71448 */ 	addiu	$a3,$a3,%lo(g_MpPlayerNum)
/*  f0f3388:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f0f338c:	acf90000 */ 	sw	$t9,0x0($a3)
.L0f0f3390:
/*  f0f3390:	11000005 */ 	beqz	$t0,.L0f0f33a8
/*  f0f3394:	3c0a800a */ 	lui	$t2,0x800a
/*  f0f3398:	814a202e */ 	lb	$t2,0x202e($t2)
/*  f0f339c:	3c01800a */ 	lui	$at,0x800a
/*  f0f33a0:	254bffff */ 	addiu	$t3,$t2,-1
/*  f0f33a4:	a02b202e */ 	sb	$t3,0x202e($at)
.L0f0f33a8:
/*  f0f33a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f33ac:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0f33b0:	01001025 */ 	or	$v0,$t0,$zero
/*  f0f33b4:	03e00008 */ 	jr	$ra
/*  f0f33b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f33bc
/*  f0f33bc:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f33c0:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0f33c4:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0f33c8:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0f33cc:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f33d0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f33d4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f33d8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f33dc:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f33e0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f33e4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f33e8:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f33ec:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0f33f0:	01f88821 */ 	addu	$s1,$t7,$t8
/*  f0f33f4:	862304f4 */ 	lh	$v1,0x4f4($s1)
/*  f0f33f8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f33fc:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0f3400:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0f3404:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f3408:	18600055 */ 	blez	$v1,.L0f0f3560
/*  f0f340c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f3410:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f0f3414:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0f3418:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f341c:	02399021 */ 	addu	$s2,$s1,$t9
/*  f0f3420:	82420460 */ 	lb	$v0,0x460($s2)
/*  f0f3424:	2652044c */ 	addiu	$s2,$s2,0x44c
/*  f0f3428:	00008025 */ 	or	$s0,$zero,$zero
/*  f0f342c:	18400022 */ 	blez	$v0,.L0f0f34b8
/*  f0f3430:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0f3434:	02408825 */ 	or	$s1,$s2,$zero
/*  f0f3438:	27b30050 */ 	addiu	$s3,$sp,0x50
/*  f0f343c:	afa00050 */ 	sw	$zero,0x50($sp)
.L0f0f3440:
/*  f0f3440:	8e280000 */ 	lw	$t0,0x0($s1)
/*  f0f3444:	24040065 */ 	addiu	$a0,$zero,0x65
/*  f0f3448:	8d050000 */ 	lw	$a1,0x0($t0)
/*  f0f344c:	8ca2000c */ 	lw	$v0,0xc($a1)
/*  f0f3450:	50400004 */ 	beqzl	$v0,.L0f0f3464
/*  f0f3454:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f0f3458:	0040f809 */ 	jalr	$v0
/*  f0f345c:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f3460:	8fa90050 */ 	lw	$t1,0x50($sp)
.L0f0f3464:
/*  f0f3464:	52890066 */ 	beql	$s4,$t1,.L0f0f3600
/*  f0f3468:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f346c:	82420014 */ 	lb	$v0,0x14($s2)
/*  f0f3470:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0f3474:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0f3478:	0202082a */ 	slt	$at,$s0,$v0
/*  f0f347c:	5420fff0 */ 	bnezl	$at,.L0f0f3440
/*  f0f3480:	afa00050 */ 	sw	$zero,0x50($sp)
/*  f0f3484:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0f3488:	8d4a1448 */ 	lw	$t2,0x1448($t2)
/*  f0f348c:	3c0c800a */ 	lui	$t4,%hi(var8009e000)
/*  f0f3490:	258ce000 */ 	addiu	$t4,$t4,%lo(var8009e000)
/*  f0f3494:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f0f3498:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0f349c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f34a0:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0f34a4:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0f34a8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0f34ac:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f0f34b0:	016c8821 */ 	addu	$s1,$t3,$t4
/*  f0f34b4:	00008025 */ 	or	$s0,$zero,$zero
.L0f0f34b8:
/*  f0f34b8:	5840000a */ 	blezl	$v0,.L0f0f34e4
/*  f0f34bc:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0f34c0:	862d0460 */ 	lh	$t5,0x460($s1)
.L0f0f34c4:
/*  f0f34c4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0f34c8:	25aeffff */ 	addiu	$t6,$t5,-1
/*  f0f34cc:	a62e0460 */ 	sh	$t6,0x460($s1)
/*  f0f34d0:	824f0014 */ 	lb	$t7,0x14($s2)
/*  f0f34d4:	020f082a */ 	slt	$at,$s0,$t7
/*  f0f34d8:	5420fffa */ 	bnezl	$at,.L0f0f34c4
/*  f0f34dc:	862d0460 */ 	lh	$t5,0x460($s1)
/*  f0f34e0:	8e580000 */ 	lw	$t8,0x0($s2)
.L0f0f34e4:
/*  f0f34e4:	862f04f4 */ 	lh	$t7,0x4f4($s1)
/*  f0f34e8:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f0f34ec:	93190004 */ 	lbu	$t9,0x4($t8)
/*  f0f34f0:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f0f34f4:	00194080 */ 	sll	$t0,$t9,0x2
/*  f0f34f8:	01194021 */ 	addu	$t0,$t0,$t9
/*  f0f34fc:	00084040 */ 	sll	$t0,$t0,0x1
/*  f0f3500:	02284821 */ 	addu	$t1,$s1,$t0
/*  f0f3504:	952a0666 */ 	lhu	$t2,0x666($t1)
/*  f0f3508:	ae2a065c */ 	sw	$t2,0x65c($s1)
/*  f0f350c:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f0f3510:	916c0004 */ 	lbu	$t4,0x4($t3)
/*  f0f3514:	ae2c06d8 */ 	sw	$t4,0x6d8($s1)
/*  f0f3518:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f0f351c:	95ae0006 */ 	lhu	$t6,0x6($t5)
/*  f0f3520:	a63804f4 */ 	sh	$t8,0x4f4($s1)
/*  f0f3524:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0f3528:	ae2e081c */ 	sw	$t6,0x81c($s1)
/*  f0f352c:	3c198007 */ 	lui	$t9,0x8007
/*  f0f3530:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f0f3534:	3c09800a */ 	lui	$t1,%hi(var8009e000)
/*  f0f3538:	2529e000 */ 	addiu	$t1,$t1,%lo(var8009e000)
/*  f0f353c:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f0f3540:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0f3544:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0f3548:	01194021 */ 	addu	$t0,$t0,$t9
/*  f0f354c:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f0f3550:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0f3554:	00084100 */ 	sll	$t0,$t0,0x4
/*  f0f3558:	01098821 */ 	addu	$s1,$t0,$t1
/*  f0f355c:	862304f4 */ 	lh	$v1,0x4f4($s1)
.L0f0f3560:
/*  f0f3560:	3c02800a */ 	lui	$v0,%hi(var800a044c)
/*  f0f3564:	8042202e */ 	lb	$v0,0x202e($v0)
/*  f0f3568:	18400017 */ 	blez	$v0,.L0f0f35c8
/*  f0f356c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3570:	14600015 */ 	bnez	$v1,.L0f0f35c8
/*  f0f3574:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3578:	04400013 */ 	bltz	$v0,.L0f0f35c8
/*  f0f357c:	00408025 */ 	or	$s0,$v0,$zero
.L0f0f3580:
/*  f0f3580:	0fc3cc88 */ 	jal	func0f0f3220
/*  f0f3584:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f3588:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f0f358c:	0601fffc */ 	bgez	$s0,.L0f0f3580
/*  f0f3590:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3594:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0f3598:	8d4a1448 */ 	lw	$t2,0x1448($t2)
/*  f0f359c:	3c0c800a */ 	lui	$t4,%hi(var8009e000)
/*  f0f35a0:	258ce000 */ 	addiu	$t4,$t4,%lo(var8009e000)
/*  f0f35a4:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f0f35a8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0f35ac:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f35b0:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0f35b4:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0f35b8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0f35bc:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f0f35c0:	016c8821 */ 	addu	$s1,$t3,$t4
/*  f0f35c4:	862304f4 */ 	lh	$v1,0x4f4($s1)
.L0f0f35c8:
/*  f0f35c8:	14600003 */ 	bnez	$v1,.L0f0f35d8
/*  f0f35cc:	00036880 */ 	sll	$t5,$v1,0x2
/*  f0f35d0:	1000000a */ 	beqz	$zero,.L0f0f35fc
/*  f0f35d4:	ae2004f8 */ 	sw	$zero,0x4f8($s1)
.L0f0f35d8:
/*  f0f35d8:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f0f35dc:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0f35e0:	022d1021 */ 	addu	$v0,$s1,$t5
/*  f0f35e4:	804e0461 */ 	lb	$t6,0x461($v0)
/*  f0f35e8:	2442044c */ 	addiu	$v0,$v0,%lo(var800a044c)
/*  f0f35ec:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0f35f0:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0f35f4:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f0f35f8:	ae3904f8 */ 	sw	$t9,0x4f8($s1)
.L0f0f35fc:
/*  f0f35fc:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0f3600:
/*  f0f3600:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f3604:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f3608:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f360c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0f3610:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0f3614:	03e00008 */ 	jr	$ra
/*  f0f3618:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f0f361c
/*  f0f361c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f3620:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0f3624:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0f3628:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0f362c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f3630:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f3634:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f3638:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f363c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f3640:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f3644:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f3648:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f0f364c:	846404f4 */ 	lh	$a0,0x4f4($v1)
/*  f0f3650:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f3654:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f3658:	14800013 */ 	bnez	$a0,.L0f0f36a8
/*  f0f365c:	00045880 */ 	sll	$t3,$a0,0x2
/*  f0f3660:	3c08800a */ 	lui	$t0,0x800a
/*  f0f3664:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f0f3668:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f366c:	0fc3e010 */ 	jal	func0f0f8040
/*  f0f3670:	ad191c40 */ 	sw	$t9,0x1c40($t0)
/*  f0f3674:	3c098007 */ 	lui	$t1,0x8007
/*  f0f3678:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f0f367c:	3c01800a */ 	lui	$at,0x800a
/*  f0f3680:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0f3684:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0f3688:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0f368c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0f3690:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0f3694:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0f3698:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0f369c:	002a0821 */ 	addu	$at,$at,$t2
/*  f0f36a0:	1000000a */ 	beqz	$zero,.L0f0f36cc
/*  f0f36a4:	ac20e4f8 */ 	sw	$zero,-0x1b08($at)
.L0f0f36a8:
/*  f0f36a8:	01645823 */ 	subu	$t3,$t3,$a0
/*  f0f36ac:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0f36b0:	006b1021 */ 	addu	$v0,$v1,$t3
/*  f0f36b4:	804c0461 */ 	lb	$t4,0x461($v0)
/*  f0f36b8:	2442044c */ 	addiu	$v0,$v0,0x44c
/*  f0f36bc:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0f36c0:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0f36c4:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f0f36c8:	ac6f04f8 */ 	sw	$t7,0x4f8($v1)
.L0f0f36cc:
/*  f0f36cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f36d0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f36d4:	03e00008 */ 	jr	$ra
/*  f0f36d8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuPopDialog
/*  f0f36dc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f36e0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f36e4:	0fc3ccef */ 	jal	func0f0f33bc
/*  f0f36e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f36ec:	0fc3cd87 */ 	jal	func0f0f361c
/*  f0f36f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f36f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f36f8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f36fc:	03e00008 */ 	jr	$ra
/*  f0f3700:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f3704
/*  f0f3704:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f3708:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f370c:	0fc3ccef */ 	jal	func0f0f33bc
/*  f0f3710:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0f3714:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0f3718:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0f371c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f3720:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f3724:	03e00008 */ 	jr	$ra
/*  f0f3728:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f372c
/*  f0f372c:	44856000 */ 	mtc1	$a1,$f12
/*  f0f3730:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f0f3734:	93a50023 */ 	lbu	$a1,0x23($sp)
/*  f0f3738:	908f05b1 */ 	lbu	$t7,0x5b1($a0)
/*  f0f373c:	44867000 */ 	mtc1	$a2,$f14
/*  f0f3740:	30b90002 */ 	andi	$t9,$a1,0x2
/*  f0f3744:	35f80008 */ 	ori	$t8,$t7,0x8
/*  f0f3748:	a09805b1 */ 	sb	$t8,0x5b1($a0)
/*  f0f374c:	13200005 */ 	beqz	$t9,.L0f0f3764
/*  f0f3750:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0f3754:	e48c0538 */ 	swc1	$f12,0x538($a0)
/*  f0f3758:	e48e053c */ 	swc1	$f14,0x53c($a0)
/*  f0f375c:	c7a4000c */ 	lwc1	$f4,0xc($sp)
/*  f0f3760:	e4840540 */ 	swc1	$f4,0x540($a0)
.L0f0f3764:
/*  f0f3764:	30480004 */ 	andi	$t0,$v0,0x4
/*  f0f3768:	11000007 */ 	beqz	$t0,.L0f0f3788
/*  f0f376c:	30490001 */ 	andi	$t1,$v0,0x1
/*  f0f3770:	c7a60010 */ 	lwc1	$f6,0x10($sp)
/*  f0f3774:	e4860548 */ 	swc1	$f6,0x548($a0)
/*  f0f3778:	c7a80014 */ 	lwc1	$f8,0x14($sp)
/*  f0f377c:	e488054c */ 	swc1	$f8,0x54c($a0)
/*  f0f3780:	c7aa0018 */ 	lwc1	$f10,0x18($sp)
/*  f0f3784:	e48a0550 */ 	swc1	$f10,0x550($a0)
.L0f0f3788:
/*  f0f3788:	11200002 */ 	beqz	$t1,.L0f0f3794
/*  f0f378c:	c7b0001c */ 	lwc1	$f16,0x1c($sp)
/*  f0f3790:	e4900544 */ 	swc1	$f16,0x544($a0)
.L0f0f3794:
/*  f0f3794:	44809000 */ 	mtc1	$zero,$f18
/*  f0f3798:	a0850568 */ 	sb	$a1,0x568($a0)
/*  f0f379c:	03e00008 */ 	jr	$ra
/*  f0f37a0:	e4920564 */ 	swc1	$f18,0x564($a0)
);

GLOBAL_ASM(
glabel func0f0f37a4
/*  f0f37a4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f37a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f37ac:	8c8e0010 */ 	lw	$t6,0x10($a0)
/*  f0f37b0:	3c014fac */ 	lui	$at,0x4fac
/*  f0f37b4:	34215ace */ 	ori	$at,$at,0x5ace
/*  f0f37b8:	55c10005 */ 	bnel	$t6,$at,.L0f0f37d0
/*  f0f37bc:	44800000 */ 	mtc1	$zero,$f0
/*  f0f37c0:	0fc6709a */ 	jal	mpResetVar800884b4
/*  f0f37c4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0f37c8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0f37cc:	44800000 */ 	mtc1	$zero,$f0
.L0f0f37d0:
/*  f0f37d0:	908f05b1 */ 	lbu	$t7,0x5b1($a0)
/*  f0f37d4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f37d8:	44811000 */ 	mtc1	$at,$f2
/*  f0f37dc:	31f9ff7f */ 	andi	$t9,$t7,0xff7f
/*  f0f37e0:	332900bf */ 	andi	$t1,$t9,0xbf
/*  f0f37e4:	a09905b1 */ 	sb	$t9,0x5b1($a0)
/*  f0f37e8:	312b00df */ 	andi	$t3,$t1,0xdf
/*  f0f37ec:	a08905b1 */ 	sb	$t1,0x5b1($a0)
/*  f0f37f0:	316d00ef */ 	andi	$t5,$t3,0xef
/*  f0f37f4:	a08b05b1 */ 	sb	$t3,0x5b1($a0)
/*  f0f37f8:	31af00f7 */ 	andi	$t7,$t5,0xf7
/*  f0f37fc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f3800:	44812000 */ 	mtc1	$at,$f4
/*  f0f3804:	a08d05b1 */ 	sb	$t5,0x5b1($a0)
/*  f0f3808:	31f900fb */ 	andi	$t9,$t7,0xfb
/*  f0f380c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0f3810:	a08f05b1 */ 	sb	$t7,0x5b1($a0)
/*  f0f3814:	a09905b1 */ 	sb	$t9,0x5b1($a0)
/*  f0f3818:	332800fd */ 	andi	$t0,$t9,0xfd
/*  f0f381c:	a0800000 */ 	sb	$zero,0x0($a0)
/*  f0f3820:	ac80000c */ 	sw	$zero,0xc($a0)
/*  f0f3824:	ac800010 */ 	sw	$zero,0x10($a0)
/*  f0f3828:	ac800054 */ 	sw	$zero,0x54($a0)
/*  f0f382c:	ac800058 */ 	sw	$zero,0x58($a0)
/*  f0f3830:	a480005c */ 	sh	$zero,0x5c($a0)
/*  f0f3834:	a480005e */ 	sh	$zero,0x5e($a0)
/*  f0f3838:	a08005b0 */ 	sb	$zero,0x5b0($a0)
/*  f0f383c:	a08805b1 */ 	sb	$t0,0x5b1($a0)
/*  f0f3840:	ac8005b4 */ 	sw	$zero,0x5b4($a0)
/*  f0f3844:	a4820560 */ 	sh	$v0,0x560($a0)
/*  f0f3848:	a4820002 */ 	sh	$v0,0x2($a0)
/*  f0f384c:	a482056a */ 	sh	$v0,0x56a($a0)
/*  f0f3850:	e4800550 */ 	swc1	$f0,0x550($a0)
/*  f0f3854:	e480054c */ 	swc1	$f0,0x54c($a0)
/*  f0f3858:	e4800548 */ 	swc1	$f0,0x548($a0)
/*  f0f385c:	e4800540 */ 	swc1	$f0,0x540($a0)
/*  f0f3860:	e480053c */ 	swc1	$f0,0x53c($a0)
/*  f0f3864:	e4800538 */ 	swc1	$f0,0x538($a0)
/*  f0f3868:	e4800534 */ 	swc1	$f0,0x534($a0)
/*  f0f386c:	e4800530 */ 	swc1	$f0,0x530($a0)
/*  f0f3870:	e480052c */ 	swc1	$f0,0x52c($a0)
/*  f0f3874:	e4800528 */ 	swc1	$f0,0x528($a0)
/*  f0f3878:	e4800524 */ 	swc1	$f0,0x524($a0)
/*  f0f387c:	e4800520 */ 	swc1	$f0,0x520($a0)
/*  f0f3880:	e4800518 */ 	swc1	$f0,0x518($a0)
/*  f0f3884:	e4800514 */ 	swc1	$f0,0x514($a0)
/*  f0f3888:	e4800510 */ 	swc1	$f0,0x510($a0)
/*  f0f388c:	e4800558 */ 	swc1	$f0,0x558($a0)
/*  f0f3890:	e482055c */ 	swc1	$f2,0x55c($a0)
/*  f0f3894:	e482051c */ 	swc1	$f2,0x51c($a0)
/*  f0f3898:	e4820544 */ 	swc1	$f2,0x544($a0)
/*  f0f389c:	e4840554 */ 	swc1	$f4,0x554($a0)
/*  f0f38a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f38a4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f38a8:	03e00008 */ 	jr	$ra
/*  f0f38ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f38b0
/*  f0f38b0:	27bdfbc0 */ 	addiu	$sp,$sp,-1088
/*  f0f38b4:	3c02800a */ 	lui	$v0,0x800a
/*  f0f38b8:	8c42a474 */ 	lw	$v0,-0x5b8c($v0)
/*  f0f38bc:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0f38c0:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0f38c4:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0f38c8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f38cc:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0f38d0:	afa40440 */ 	sw	$a0,0x440($sp)
/*  f0f38d4:	1041001d */ 	beq	$v0,$at,.L0f0f394c
/*  f0f38d8:	afa60448 */ 	sw	$a2,0x448($sp)
/*  f0f38dc:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f0f38e0:	1041001a */ 	beq	$v0,$at,.L0f0f394c
/*  f0f38e4:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f38e8:	81cf1f95 */ 	lb	$t7,0x1f95($t6)
/*  f0f38ec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f38f0:	05e30008 */ 	bgezl	$t7,.L0f0f3914
/*  f0f38f4:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0f38f8:	10c10005 */ 	beq	$a2,$at,.L0f0f3910
/*  f0f38fc:	28c10003 */ 	slti	$at,$a2,0x3
/*  f0f3900:	50200004 */ 	beqzl	$at,.L0f0f3914
/*  f0f3904:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0f3908:	100005b9 */ 	beqz	$zero,.L0f0f4ff0
/*  f0f390c:	00801025 */ 	or	$v0,$a0,$zero
.L0f0f3910:
/*  f0f3910:	8e190004 */ 	lw	$t9,0x4($s0)
.L0f0f3914:
/*  f0f3914:	5720000e */ 	bnezl	$t9,.L0f0f3950
/*  f0f3918:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f0f391c:	0fc27801 */ 	jal	func0f09e004
/*  f0f3920:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f3924:	10400007 */ 	beqz	$v0,.L0f0f3944
/*  f0f3928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f392c:	0fc2777b */ 	jal	func0f09ddec
/*  f0f3930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3934:	0fc2777f */ 	jal	func0f09ddfc
/*  f0f3938:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0f393c:	10000003 */ 	beqz	$zero,.L0f0f394c
/*  f0f3940:	ae020008 */ 	sw	$v0,0x8($s0)
.L0f0f3944:
/*  f0f3944:	100005aa */ 	beqz	$zero,.L0f0f4ff0
/*  f0f3948:	8fa20440 */ 	lw	$v0,0x440($sp)
.L0f0f394c:
/*  f0f394c:	8e0a0004 */ 	lw	$t2,0x4($s0)
.L0f0f3950:
/*  f0f3950:	55400004 */ 	bnezl	$t2,.L0f0f3964
/*  f0f3954:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0f3958:	100005a5 */ 	beqz	$zero,.L0f0f4ff0
/*  f0f395c:	8fa20440 */ 	lw	$v0,0x440($sp)
/*  f0f3960:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f0f3964:
/*  f0f3964:	504000dc */ 	beqzl	$v0,.L0f0f3cd8
/*  f0f3968:	8e0a0054 */ 	lw	$t2,0x54($s0)
/*  f0f396c:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0f3970:	3c014fac */ 	lui	$at,0x4fac
/*  f0f3974:	34215ace */ 	ori	$at,$at,0x5ace
/*  f0f3978:	14620004 */ 	bne	$v1,$v0,.L0f0f398c
/*  f0f397c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3980:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f0f3984:	100000d3 */ 	beqz	$zero,.L0f0f3cd4
/*  f0f3988:	a2000000 */ 	sb	$zero,0x0($s0)
.L0f0f398c:
/*  f0f398c:	54610004 */ 	bnel	$v1,$at,.L0f0f39a0
/*  f0f3990:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0f3994:	0fc6709a */ 	jal	mpResetVar800884b4
/*  f0f3998:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f399c:	92020000 */ 	lbu	$v0,0x0($s0)
.L0f0f39a0:
/*  f0f39a0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f39a4:	14400004 */ 	bnez	$v0,.L0f0f39b8
/*  f0f39a8:	244cffff */ 	addiu	$t4,$v0,-1
/*  f0f39ac:	a20b0000 */ 	sb	$t3,0x0($s0)
/*  f0f39b0:	1000058f */ 	beqz	$zero,.L0f0f4ff0
/*  f0f39b4:	8fa20440 */ 	lw	$v0,0x440($sp)
.L0f0f39b8:
/*  f0f39b8:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0f39bc:	15a000c3 */ 	bnez	$t5,.L0f0f3ccc
/*  f0f39c0:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f0f39c4:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0f39c8:	3401ffff */ 	dli	$at,0xffff
/*  f0f39cc:	304effff */ 	andi	$t6,$v0,0xffff
/*  f0f39d0:	11c10002 */ 	beq	$t6,$at,.L0f0f39dc
/*  f0f39d4:	00027800 */ 	sll	$t7,$v0,0x0
/*  f0f39d8:	05e10092 */ 	bgez	$t7,.L0f0f3c24
.L0f0f39dc:
/*  f0f39dc:	0002c000 */ 	sll	$t8,$v0,0x0
/*  f0f39e0:	07010008 */ 	bgez	$t8,.L0f0f3a04
/*  f0f39e4:	3c01000f */ 	lui	$at,0xf
/*  f0f39e8:	3421fc00 */ 	ori	$at,$at,0xfc00
/*  f0f39ec:	00415024 */ 	and	$t2,$v0,$at
/*  f0f39f0:	305903ff */ 	andi	$t9,$v0,0x3ff
/*  f0f39f4:	000a5a82 */ 	srl	$t3,$t2,0xa
/*  f0f39f8:	afb90400 */ 	sw	$t9,0x400($sp)
/*  f0f39fc:	1000001a */ 	beqz	$zero,.L0f0f3a68
/*  f0f3a00:	afab0404 */ 	sw	$t3,0x404($sp)
.L0f0f3a04:
/*  f0f3a04:	00028c02 */ 	srl	$s1,$v0,0x10
/*  f0f3a08:	322c00ff */ 	andi	$t4,$s1,0xff
/*  f0f3a0c:	00026e02 */ 	srl	$t5,$v0,0x18
/*  f0f3a10:	01808825 */ 	or	$s1,$t4,$zero
/*  f0f3a14:	0fc62ee4 */ 	jal	mpGetBodyId
/*  f0f3a18:	31a400ff */ 	andi	$a0,$t5,0xff
/*  f0f3a1c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f0f3a20:	afa20404 */ 	sw	$v0,0x404($sp)
/*  f0f3a24:	0222082a */ 	slt	$at,$s1,$v0
/*  f0f3a28:	10200005 */ 	beqz	$at,.L0f0f3a40
/*  f0f3a2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3a30:	0fc62ecb */ 	jal	mpGetHeadId
/*  f0f3a34:	322400ff */ 	andi	$a0,$s1,0xff
/*  f0f3a38:	1000000b */ 	beqz	$zero,.L0f0f3a68
/*  f0f3a3c:	afa20400 */ 	sw	$v0,0x400($sp)
.L0f0f3a40:
/*  f0f3a40:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f0f3a44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3a48:	0fc52a7e */ 	jal	func0f14a9f8
/*  f0f3a4c:	02222023 */ 	subu	$a0,$s1,$v0
/*  f0f3a50:	0fc62ed9 */ 	jal	mpGetBeauHeadId
/*  f0f3a54:	304400ff */ 	andi	$a0,$v0,0xff
/*  f0f3a58:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f0f3a5c:	afa20400 */ 	sw	$v0,0x400($sp)
/*  f0f3a60:	02227823 */ 	subu	$t7,$s1,$v0
/*  f0f3a64:	a20f05b0 */ 	sb	$t7,0x5b0($s0)
.L0f0f3a68:
/*  f0f3a68:	8fb80404 */ 	lw	$t8,0x404($sp)
/*  f0f3a6c:	3c0a8008 */ 	lui	$t2,%hi(bodytable)
/*  f0f3a70:	254acf04 */ 	addiu	$t2,$t2,%lo(bodytable)
/*  f0f3a74:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f3a78:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f3a7c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f3a80:	032a8821 */ 	addu	$s1,$t9,$t2
/*  f0f3a84:	96220002 */ 	lhu	$v0,0x2($s1)
/*  f0f3a88:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3a8c:	a7a2040a */ 	sh	$v0,0x40a($sp)
/*  f0f3a90:	0fc59c15 */ 	jal	func0f167054
/*  f0f3a94:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f0f3a98:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f0f3a9c:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f3aa0:	346b003f */ 	ori	$t3,$v1,0x3f
/*  f0f3aa4:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f0f3aa8:	05e10005 */ 	bgez	$t7,.L0f0f3ac0
/*  f0f3aac:	3963003f */ 	xori	$v1,$t3,0x3f
/*  f0f3ab0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0f3ab4:	afb80400 */ 	sw	$t8,0x400($sp)
/*  f0f3ab8:	10000011 */ 	beqz	$zero,.L0f0f3b00
/*  f0f3abc:	3411ffff */ 	dli	$s1,0xffff
.L0f0f3ac0:
/*  f0f3ac0:	8fb90400 */ 	lw	$t9,0x400($sp)
/*  f0f3ac4:	3c118008 */ 	lui	$s1,0x8008
/*  f0f3ac8:	afa30420 */ 	sw	$v1,0x420($sp)
/*  f0f3acc:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0f3ad0:	01595021 */ 	addu	$t2,$t2,$t9
/*  f0f3ad4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0f3ad8:	022a8821 */ 	addu	$s1,$s1,$t2
/*  f0f3adc:	9631cf06 */ 	lhu	$s1,-0x30fa($s1)
/*  f0f3ae0:	0fc59c15 */ 	jal	func0f167054
/*  f0f3ae4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f3ae8:	8fab0420 */ 	lw	$t3,0x420($sp)
/*  f0f3aec:	244c003f */ 	addiu	$t4,$v0,0x3f
/*  f0f3af0:	358d003f */ 	ori	$t5,$t4,0x3f
/*  f0f3af4:	39ae003f */ 	xori	$t6,$t5,0x3f
/*  f0f3af8:	016e1821 */ 	addu	$v1,$t3,$t6
/*  f0f3afc:	afa30420 */ 	sw	$v1,0x420($sp)
.L0f0f3b00:
/*  f0f3b00:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f0f3b04:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f0f3b08:	24634000 */ 	addiu	$v1,$v1,0x4000
/*  f0f3b0c:	afa30420 */ 	sw	$v1,0x420($sp)
/*  f0f3b10:	27a40410 */ 	addiu	$a0,$sp,0x410
/*  f0f3b14:	03032821 */ 	addu	$a1,$t8,$v1
/*  f0f3b18:	0fc5cb9c */ 	jal	func0f172e70
/*  f0f3b1c:	03233023 */ 	subu	$a2,$t9,$v1
/*  f0f3b20:	8faa0400 */ 	lw	$t2,0x400($sp)
/*  f0f3b24:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f0f3b28:	27a70410 */ 	addiu	$a3,$sp,0x410
/*  f0f3b2c:	a60a0002 */ 	sh	$t2,0x2($s0)
/*  f0f3b30:	8fac0404 */ 	lw	$t4,0x404($sp)
/*  f0f3b34:	a60c056a */ 	sh	$t4,0x56a($s0)
/*  f0f3b38:	8fa60420 */ 	lw	$a2,0x420($sp)
/*  f0f3b3c:	0fc69de5 */ 	jal	func0f1a7794
/*  f0f3b40:	97a4040a */ 	lhu	$a0,0x40a($sp)
/*  f0f3b44:	ae020054 */ 	sw	$v0,0x54($s0)
/*  f0f3b48:	0fc59ca0 */ 	jal	func0f167280
/*  f0f3b4c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f3b50:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f3b54:	346d003f */ 	ori	$t5,$v1,0x3f
/*  f0f3b58:	39ab003f */ 	xori	$t3,$t5,0x3f
/*  f0f3b5c:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f3b60:	0c008b49 */ 	jal	func00022d24
/*  f0f3b64:	afab040c */ 	sw	$t3,0x40c($sp)
/*  f0f3b68:	8fae0400 */ 	lw	$t6,0x400($sp)
/*  f0f3b6c:	8fa3040c */ 	lw	$v1,0x40c($sp)
/*  f0f3b70:	3224ffff */ 	andi	$a0,$s1,0xffff
/*  f0f3b74:	05c10003 */ 	bgez	$t6,.L0f0f3b84
/*  f0f3b78:	8fb80420 */ 	lw	$t8,0x420($sp)
/*  f0f3b7c:	10000010 */ 	beqz	$zero,.L0f0f3bc0
/*  f0f3b80:	ae000058 */ 	sw	$zero,0x58($s0)
.L0f0f3b84:
/*  f0f3b84:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f0f3b88:	afb10040 */ 	sw	$s1,0x40($sp)
/*  f0f3b8c:	03033023 */ 	subu	$a2,$t8,$v1
/*  f0f3b90:	27a70410 */ 	addiu	$a3,$sp,0x410
/*  f0f3b94:	0fc69de5 */ 	jal	func0f1a7794
/*  f0f3b98:	01e32821 */ 	addu	$a1,$t7,$v1
/*  f0f3b9c:	ae020058 */ 	sw	$v0,0x58($s0)
/*  f0f3ba0:	0fc59ca0 */ 	jal	func0f167280
/*  f0f3ba4:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f3ba8:	8e040058 */ 	lw	$a0,0x58($s0)
/*  f0f3bac:	8fa50400 */ 	lw	$a1,0x400($sp)
/*  f0f3bb0:	0fc0b76f */ 	jal	func0f02ddbc
/*  f0f3bb4:	8fa60404 */ 	lw	$a2,0x404($sp)
/*  f0f3bb8:	0c008b49 */ 	jal	func00022d24
/*  f0f3bbc:	8e040058 */ 	lw	$a0,0x58($s0)
.L0f0f3bc0:
/*  f0f3bc0:	26040060 */ 	addiu	$a0,$s0,0x60
/*  f0f3bc4:	8e050054 */ 	lw	$a1,0x54($s0)
/*  f0f3bc8:	afa4003c */ 	sw	$a0,0x3c($sp)
/*  f0f3bcc:	26060110 */ 	addiu	$a2,$s0,0x110
/*  f0f3bd0:	0c008be9 */ 	jal	func00022fa4
/*  f0f3bd4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0f3bd8:	26110084 */ 	addiu	$s1,$s0,0x84
/*  f0f3bdc:	0c008c28 */ 	jal	func000230a0
/*  f0f3be0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f3be4:	24190100 */ 	addiu	$t9,$zero,0x100
/*  f0f3be8:	a6190062 */ 	sh	$t9,0x62($s0)
/*  f0f3bec:	ae110080 */ 	sw	$s1,0x80($s0)
/*  f0f3bf0:	8e060054 */ 	lw	$a2,0x54($s0)
/*  f0f3bf4:	8e070058 */ 	lw	$a3,0x58($s0)
/*  f0f3bf8:	8faa003c */ 	lw	$t2,0x3c($sp)
/*  f0f3bfc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f3c00:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0f3c04:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f3c08:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0f3c0c:	8fa50400 */ 	lw	$a1,0x400($sp)
/*  f0f3c10:	8fa40404 */ 	lw	$a0,0x404($sp)
/*  f0f3c14:	0fc0b3a3 */ 	jal	func0f02ce8c
/*  f0f3c18:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0f3c1c:	10000027 */ 	beqz	$zero,.L0f0f3cbc
/*  f0f3c20:	8e19000c */ 	lw	$t9,0xc($s0)
.L0f0f3c24:
/*  f0f3c24:	0fc59c15 */ 	jal	func0f167054
/*  f0f3c28:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3c2c:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f3c30:	346d003f */ 	ori	$t5,$v1,0x3f
/*  f0f3c34:	39ab003f */ 	xori	$t3,$t5,0x3f
/*  f0f3c38:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f0f3c3c:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f0f3c40:	25634000 */ 	addiu	$v1,$t3,0x4000
/*  f0f3c44:	afa30420 */ 	sw	$v1,0x420($sp)
/*  f0f3c48:	27a40410 */ 	addiu	$a0,$sp,0x410
/*  f0f3c4c:	01c32821 */ 	addu	$a1,$t6,$v1
/*  f0f3c50:	0fc5cb9c */ 	jal	func0f172e70
/*  f0f3c54:	01e33023 */ 	subu	$a2,$t7,$v1
/*  f0f3c58:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0f3c5c:	a6020002 */ 	sh	$v0,0x2($s0)
/*  f0f3c60:	a602056a */ 	sh	$v0,0x56a($s0)
/*  f0f3c64:	8fa60420 */ 	lw	$a2,0x420($sp)
/*  f0f3c68:	9604000e */ 	lhu	$a0,0xe($s0)
/*  f0f3c6c:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f0f3c70:	0fc69de5 */ 	jal	func0f1a7794
/*  f0f3c74:	27a70410 */ 	addiu	$a3,$sp,0x410
/*  f0f3c78:	ae020054 */ 	sw	$v0,0x54($s0)
/*  f0f3c7c:	0fc59ca0 */ 	jal	func0f167280
/*  f0f3c80:	8e04000c */ 	lw	$a0,0xc($s0)
/*  f0f3c84:	0c008b49 */ 	jal	func00022d24
/*  f0f3c88:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f3c8c:	26040060 */ 	addiu	$a0,$s0,0x60
/*  f0f3c90:	8e050054 */ 	lw	$a1,0x54($s0)
/*  f0f3c94:	26060110 */ 	addiu	$a2,$s0,0x110
/*  f0f3c98:	0c008be9 */ 	jal	func00022fa4
/*  f0f3c9c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0f3ca0:	26110084 */ 	addiu	$s1,$s0,0x84
/*  f0f3ca4:	0c008c28 */ 	jal	func000230a0
/*  f0f3ca8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f3cac:	24180100 */ 	addiu	$t8,$zero,0x100
/*  f0f3cb0:	a6180062 */ 	sh	$t8,0x62($s0)
/*  f0f3cb4:	ae110080 */ 	sw	$s1,0x80($s0)
/*  f0f3cb8:	8e19000c */ 	lw	$t9,0xc($s0)
.L0f0f3cbc:
/*  f0f3cbc:	a600005e */ 	sh	$zero,0x5e($s0)
/*  f0f3cc0:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f0f3cc4:	10000003 */ 	beqz	$zero,.L0f0f3cd4
/*  f0f3cc8:	ae190010 */ 	sw	$t9,0x10($s0)
.L0f0f3ccc:
/*  f0f3ccc:	100004c8 */ 	beqz	$zero,.L0f0f4ff0
/*  f0f3cd0:	8fa20440 */ 	lw	$v0,0x440($sp)
.L0f0f3cd4:
/*  f0f3cd4:	8e0a0054 */ 	lw	$t2,0x54($s0)
.L0f0f3cd8:
/*  f0f3cd8:	3c0d8007 */ 	lui	$t5,%hi(var80071480)
/*  f0f3cdc:	25ad1480 */ 	addiu	$t5,$t5,%lo(var80071480)
/*  f0f3ce0:	114004c2 */ 	beqz	$t2,.L0f0f4fec
/*  f0f3ce4:	27ac03b8 */ 	addiu	$t4,$sp,0x3b8
/*  f0f3ce8:	25ae003c */ 	addiu	$t6,$t5,0x3c
.L0f0f3cec:
/*  f0f3cec:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0f3cf0:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f0f3cf4:	258c000c */ 	addiu	$t4,$t4,0xc
/*  f0f3cf8:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*  f0f3cfc:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*  f0f3d00:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*  f0f3d04:	8da1fffc */ 	lw	$at,-0x4($t5)
/*  f0f3d08:	15aefff8 */ 	bne	$t5,$t6,.L0f0f3cec
/*  f0f3d0c:	ad81fffc */ 	sw	$at,-0x4($t4)
/*  f0f3d10:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0f3d14:	260f0060 */ 	addiu	$t7,$s0,0x60
/*  f0f3d18:	ad810000 */ 	sw	$at,0x0($t4)
/*  f0f3d1c:	8fb80448 */ 	lw	$t8,0x448($sp)
/*  f0f3d20:	afaf003c */ 	sw	$t7,0x3c($sp)
/*  f0f3d24:	2b010003 */ 	slti	$at,$t8,0x3
/*  f0f3d28:	1020001b */ 	beqz	$at,.L0f0f3d98
/*  f0f3d2c:	3c19800a */ 	lui	$t9,0x800a
/*  f0f3d30:	8f391f94 */ 	lw	$t9,0x1f94($t9)
/*  f0f3d34:	00195a80 */ 	sll	$t3,$t9,0xa
/*  f0f3d38:	05630018 */ 	bgezl	$t3,.L0f0f3d9c
/*  f0f3d3c:	8faa0440 */ 	lw	$t2,0x440($sp)
/*  f0f3d40:	0c002ca0 */ 	jal	func0000b280
/*  f0f3d44:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f3d48:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f3d4c:	0c002c74 */ 	jal	func0000b1d0
/*  f0f3d50:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3d54:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f3d58:	91ce1f95 */ 	lbu	$t6,0x1f95($t6)
/*  f0f3d5c:	8fac0448 */ 	lw	$t4,0x448($sp)
/*  f0f3d60:	3c01800a */ 	lui	$at,0x800a
/*  f0f3d64:	31cdffdf */ 	andi	$t5,$t6,0xffdf
/*  f0f3d68:	a02d1f95 */ 	sb	$t5,0x1f95($at)
/*  f0f3d6c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f3d70:	11810003 */ 	beq	$t4,$at,.L0f0f3d80
/*  f0f3d74:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f3d78:	0fc3d43f */ 	jal	func0f0f50fc
/*  f0f3d7c:	00402025 */ 	or	$a0,$v0,$zero
.L0f0f3d80:
/*  f0f3d80:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f0f3d84:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f3d88:	3c18b700 */ 	lui	$t8,0xb700
/*  f0f3d8c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f3d90:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0f3d94:	ac580000 */ 	sw	$t8,0x0($v0)
.L0f0f3d98:
/*  f0f3d98:	8faa0440 */ 	lw	$t2,0x440($sp)
.L0f0f3d9c:
/*  f0f3d9c:	3c0d8006 */ 	lui	$t5,%hi(var80061380)
/*  f0f3da0:	25ad1380 */ 	addiu	$t5,$t5,%lo(var80061380)
/*  f0f3da4:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0f3da8:	afab0440 */ 	sw	$t3,0x440($sp)
/*  f0f3dac:	3c0e0600 */ 	lui	$t6,0x600
/*  f0f3db0:	ad4e0000 */ 	sw	$t6,0x0($t2)
/*  f0f3db4:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0f3db8:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f3dbc:	3c180600 */ 	lui	$t8,0x600
/*  f0f3dc0:	3c198006 */ 	lui	$t9,%hi(var800613a0)
/*  f0f3dc4:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f3dc8:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f3dcc:	273913a0 */ 	addiu	$t9,$t9,%lo(var800613a0)
/*  f0f3dd0:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f3dd4:	afb90038 */ 	sw	$t9,0x38($sp)
/*  f0f3dd8:	ad990004 */ 	sw	$t9,0x4($t4)
/*  f0f3ddc:	afa00308 */ 	sw	$zero,0x308($sp)
/*  f0f3de0:	c6060554 */ 	lwc1	$f6,0x554($s0)
/*  f0f3de4:	44802000 */ 	mtc1	$zero,$f4
/*  f0f3de8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3dec:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0f3df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3df4:	4500005c */ 	bc1f	.L0f0f3f68
/*  f0f3df8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f3dfc:	afaa02f4 */ 	sw	$t2,0x2f4($sp)
/*  f0f3e00:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f3e04:	3c0b8008 */ 	lui	$t3,%hi(stagethinglist_22e60)
/*  f0f3e08:	256bce40 */ 	addiu	$t3,$t3,%lo(stagethinglist_22e60)
/*  f0f3e0c:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f0f3e10:	556e002f */ 	bnel	$t3,$t6,.L0f0f3ed0
/*  f0f3e14:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f0f3e18:	0c006a47 */ 	jal	func0001a91c
/*  f0f3e1c:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f0f3e20:	5040002b */ 	beqzl	$v0,.L0f0f3ed0
/*  f0f3e24:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f0f3e28:	8e0d0574 */ 	lw	$t5,0x574($s0)
/*  f0f3e2c:	3c0143f0 */ 	lui	$at,0x43f0
/*  f0f3e30:	44812000 */ 	mtc1	$at,$f4
/*  f0f3e34:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f3e38:	8c510004 */ 	lw	$s1,0x4($v0)
/*  f0f3e3c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0f3e40:	0fc01af4 */ 	jal	func0f006bd0
/*  f0f3e44:	46045303 */ 	div.s	$f12,$f10,$f4
/*  f0f3e48:	44806000 */ 	mtc1	$zero,$f12
/*  f0f3e4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f3e50:	44817000 */ 	mtc1	$at,$f14
/*  f0f3e54:	3c017f1b */ 	lui	$at,%hi(var7f1b292c)
/*  f0f3e58:	e7ac02fc */ 	swc1	$f12,0x2fc($sp)
/*  f0f3e5c:	c6260004 */ 	lwc1	$f6,0x4($s1)
/*  f0f3e60:	c428292c */ 	lwc1	$f8,%lo(var7f1b292c)($at)
/*  f0f3e64:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0f3e68:	3c014387 */ 	lui	$at,0x4387
/*  f0f3e6c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f3e70:	afac0308 */ 	sw	$t4,0x308($sp)
/*  f0f3e74:	e7ac0304 */ 	swc1	$f12,0x304($sp)
/*  f0f3e78:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0f3e7c:	46047181 */ 	sub.s	$f6,$f14,$f4
/*  f0f3e80:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0f3e84:	46007281 */ 	sub.s	$f10,$f14,$f0
/*  f0f3e88:	44813000 */ 	mtc1	$at,$f6
/*  f0f3e8c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0f3e90:	46086101 */ 	sub.s	$f4,$f12,$f8
/*  f0f3e94:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0f3e98:	e7a40300 */ 	swc1	$f4,0x300($sp)
/*  f0f3e9c:	44812000 */ 	mtc1	$at,$f4
/*  f0f3ea0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f3ea4:	44813000 */ 	mtc1	$at,$f6
/*  f0f3ea8:	46044080 */ 	add.s	$f2,$f8,$f4
/*  f0f3eac:	e6020554 */ 	swc1	$f2,0x554($s0)
/*  f0f3eb0:	c62a0004 */ 	lwc1	$f10,0x4($s1)
/*  f0f3eb4:	afa002f4 */ 	sw	$zero,0x2f4($sp)
/*  f0f3eb8:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f3ebc:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0f3ec0:	46081103 */ 	div.s	$f4,$f2,$f8
/*  f0f3ec4:	0fc1a2aa */ 	jal	func0f068aa8
/*  f0f3ec8:	e7a402f8 */ 	swc1	$f4,0x2f8($sp)
/*  f0f3ecc:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
.L0f0f3ed0:
/*  f0f3ed0:	11e00025 */ 	beqz	$t7,.L0f0f3f68
/*  f0f3ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3ed8:	0fc1a2aa */ 	jal	func0f068aa8
/*  f0f3edc:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f3ee0:	10400021 */ 	beqz	$v0,.L0f0f3f68
/*  f0f3ee4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3ee8:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f0f3eec:	c44a0004 */ 	lwc1	$f10,0x4($v0)
/*  f0f3ef0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f3ef4:	44817000 */ 	mtc1	$at,$f14
/*  f0f3ef8:	460a0181 */ 	sub.s	$f6,$f0,$f10
/*  f0f3efc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f3f00:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0f3f04:	46080101 */ 	sub.s	$f4,$f0,$f8
/*  f0f3f08:	46002287 */ 	neg.s	$f10,$f4
/*  f0f3f0c:	e7aa02fc */ 	swc1	$f10,0x2fc($sp)
/*  f0f3f10:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f0f3f14:	c4420010 */ 	lwc1	$f2,0x10($v0)
/*  f0f3f18:	46061201 */ 	sub.s	$f8,$f2,$f6
/*  f0f3f1c:	460e4102 */ 	mul.s	$f4,$f8,$f14
/*  f0f3f20:	46041281 */ 	sub.s	$f10,$f2,$f4
/*  f0f3f24:	46005187 */ 	neg.s	$f6,$f10
/*  f0f3f28:	e7a60300 */ 	swc1	$f6,0x300($sp)
/*  f0f3f2c:	c4480014 */ 	lwc1	$f8,0x14($v0)
/*  f0f3f30:	c44c0018 */ 	lwc1	$f12,0x18($v0)
/*  f0f3f34:	afb80308 */ 	sw	$t8,0x308($sp)
/*  f0f3f38:	46086101 */ 	sub.s	$f4,$f12,$f8
/*  f0f3f3c:	460e2282 */ 	mul.s	$f10,$f4,$f14
/*  f0f3f40:	460a6181 */ 	sub.s	$f6,$f12,$f10
/*  f0f3f44:	46003207 */ 	neg.s	$f8,$f6
/*  f0f3f48:	e7a80304 */ 	swc1	$f8,0x304($sp)
/*  f0f3f4c:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f0f3f50:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0f3f54:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0f3f58:	c6040554 */ 	lwc1	$f4,0x554($s0)
/*  f0f3f5c:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0f3f60:	46082283 */ 	div.s	$f10,$f4,$f8
/*  f0f3f64:	e7aa02f8 */ 	swc1	$f10,0x2f8($sp)
.L0f0f3f68:
/*  f0f3f68:	0c00566c */ 	jal	func000159b0
/*  f0f3f6c:	27a40350 */ 	addiu	$a0,$sp,0x350
/*  f0f3f70:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f3f74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f3f78:	17210083 */ 	bne	$t9,$at,.L0f0f4188
/*  f0f3f7c:	3c0a8009 */ 	lui	$t2,0x8009
/*  f0f3f80:	914a0af0 */ 	lbu	$t2,0xaf0($t2)
/*  f0f3f84:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f3f88:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f3f8c:	11410130 */ 	beq	$t2,$at,.L0f0f4450
/*  f0f3f90:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f3f94:	c6000538 */ 	lwc1	$f0,0x538($s0)
/*  f0f3f98:	c6060510 */ 	lwc1	$f6,0x510($s0)
/*  f0f3f9c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f3fa0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0f3fa4:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0f3fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3fac:	45030014 */ 	bc1tl	.L0f0f4000
/*  f0f3fb0:	c60c053c */ 	lwc1	$f12,0x53c($s0)
/*  f0f3fb4:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f0f3fb8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f3fbc:	3c017f1b */ 	lui	$at,%hi(var7f1b2930)
/*  f0f3fc0:	5960000f */ 	blezl	$t3,.L0f0f4000
/*  f0f3fc4:	c60c053c */ 	lwc1	$f12,0x53c($s0)
/*  f0f3fc8:	c4242930 */ 	lwc1	$f4,%lo(var7f1b2930)($at)
/*  f0f3fcc:	3c017f1b */ 	lui	$at,%hi(var7f1b2934)
/*  f0f3fd0:	46040082 */ 	mul.s	$f2,$f0,$f4
/*  f0f3fd4:	c4202934 */ 	lwc1	$f0,%lo(var7f1b2934)($at)
/*  f0f3fd8:	c6080510 */ 	lwc1	$f8,0x510($s0)
.L0f0f3fdc:
/*  f0f3fdc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f3fe0:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0f3fe4:	460a1180 */ 	add.s	$f6,$f2,$f10
/*  f0f3fe8:	e6060510 */ 	swc1	$f6,0x510($s0)
/*  f0f3fec:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0f3ff0:	004e082a */ 	slt	$at,$v0,$t6
/*  f0f3ff4:	5420fff9 */ 	bnezl	$at,.L0f0f3fdc
/*  f0f3ff8:	c6080510 */ 	lwc1	$f8,0x510($s0)
/*  f0f3ffc:	c60c053c */ 	lwc1	$f12,0x53c($s0)
.L0f0f4000:
/*  f0f4000:	c6040514 */ 	lwc1	$f4,0x514($s0)
/*  f0f4004:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f4008:	3c017f1b */ 	lui	$at,%hi(var7f1b2938)
/*  f0f400c:	46046032 */ 	c.eq.s	$f12,$f4
/*  f0f4010:	c4202938 */ 	lwc1	$f0,%lo(var7f1b2938)($at)
/*  f0f4014:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0f4018:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0f401c:	45030013 */ 	bc1tl	.L0f0f406c
/*  f0f4020:	c60c0540 */ 	lwc1	$f12,0x540($s0)
/*  f0f4024:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0f4028:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f402c:	3c017f1b */ 	lui	$at,%hi(var7f1b293c)
/*  f0f4030:	59a0000e */ 	blezl	$t5,.L0f0f406c
/*  f0f4034:	c60c0540 */ 	lwc1	$f12,0x540($s0)
/*  f0f4038:	c428293c */ 	lwc1	$f8,%lo(var7f1b293c)($at)
/*  f0f403c:	46086082 */ 	mul.s	$f2,$f12,$f8
/*  f0f4040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4044:	c60a0514 */ 	lwc1	$f10,0x514($s0)
.L0f0f4048:
/*  f0f4048:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f404c:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0f4050:	46061100 */ 	add.s	$f4,$f2,$f6
/*  f0f4054:	e6040514 */ 	swc1	$f4,0x514($s0)
/*  f0f4058:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0f405c:	004c082a */ 	slt	$at,$v0,$t4
/*  f0f4060:	5420fff9 */ 	bnezl	$at,.L0f0f4048
/*  f0f4064:	c60a0514 */ 	lwc1	$f10,0x514($s0)
/*  f0f4068:	c60c0540 */ 	lwc1	$f12,0x540($s0)
.L0f0f406c:
/*  f0f406c:	c6080518 */ 	lwc1	$f8,0x518($s0)
/*  f0f4070:	46086032 */ 	c.eq.s	$f12,$f8
/*  f0f4074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4078:	45030013 */ 	bc1tl	.L0f0f40c8
/*  f0f407c:	c60c0544 */ 	lwc1	$f12,0x544($s0)
/*  f0f4080:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0f4084:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f4088:	3c017f1b */ 	lui	$at,%hi(var7f1b2940)
/*  f0f408c:	59e0000e */ 	blezl	$t7,.L0f0f40c8
/*  f0f4090:	c60c0544 */ 	lwc1	$f12,0x544($s0)
/*  f0f4094:	c42a2940 */ 	lwc1	$f10,%lo(var7f1b2940)($at)
/*  f0f4098:	460a6082 */ 	mul.s	$f2,$f12,$f10
/*  f0f409c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f40a0:	c6060518 */ 	lwc1	$f6,0x518($s0)
.L0f0f40a4:
/*  f0f40a4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f40a8:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0f40ac:	46041200 */ 	add.s	$f8,$f2,$f4
/*  f0f40b0:	e6080518 */ 	swc1	$f8,0x518($s0)
/*  f0f40b4:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0f40b8:	0058082a */ 	slt	$at,$v0,$t8
/*  f0f40bc:	5420fff9 */ 	bnezl	$at,.L0f0f40a4
/*  f0f40c0:	c6060518 */ 	lwc1	$f6,0x518($s0)
/*  f0f40c4:	c60c0544 */ 	lwc1	$f12,0x544($s0)
.L0f0f40c8:
/*  f0f40c8:	c60e051c */ 	lwc1	$f14,0x51c($s0)
/*  f0f40cc:	460e6032 */ 	c.eq.s	$f12,$f14
/*  f0f40d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f40d4:	45030014 */ 	bc1tl	.L0f0f4128
/*  f0f40d8:	c60a0510 */ 	lwc1	$f10,0x510($s0)
/*  f0f40dc:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f40e0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f40e4:	3c017f1b */ 	lui	$at,%hi(var7f1b2944)
/*  f0f40e8:	5b20000f */ 	blezl	$t9,.L0f0f4128
/*  f0f40ec:	c60a0510 */ 	lwc1	$f10,0x510($s0)
/*  f0f40f0:	c42a2944 */ 	lwc1	$f10,%lo(var7f1b2944)($at)
/*  f0f40f4:	460a6082 */ 	mul.s	$f2,$f12,$f10
/*  f0f40f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f40fc:	c606051c */ 	lwc1	$f6,0x51c($s0)
.L0f0f4100:
/*  f0f4100:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f4104:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0f4108:	46041200 */ 	add.s	$f8,$f2,$f4
/*  f0f410c:	e608051c */ 	swc1	$f8,0x51c($s0)
/*  f0f4110:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0f4114:	004a082a */ 	slt	$at,$v0,$t2
/*  f0f4118:	5420fff9 */ 	bnezl	$at,.L0f0f4100
/*  f0f411c:	c606051c */ 	lwc1	$f6,0x51c($s0)
/*  f0f4120:	c60e051c */ 	lwc1	$f14,0x51c($s0)
/*  f0f4124:	c60a0510 */ 	lwc1	$f10,0x510($s0)
.L0f0f4128:
/*  f0f4128:	8d6b06c8 */ 	lw	$t3,0x6c8($t3)
/*  f0f412c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f4130:	e7aa0430 */ 	swc1	$f10,0x430($sp)
/*  f0f4134:	c6120518 */ 	lwc1	$f18,0x518($s0)
/*  f0f4138:	15610004 */ 	bne	$t3,$at,.L0f0f414c
/*  f0f413c:	c6100514 */ 	lwc1	$f16,0x514($s0)
/*  f0f4140:	c7a60430 */ 	lwc1	$f6,0x430($sp)
/*  f0f4144:	46063100 */ 	add.s	$f4,$f6,$f6
/*  f0f4148:	e7a40430 */ 	swc1	$f4,0x430($sp)
.L0f0f414c:
/*  f0f414c:	e7b0042c */ 	swc1	$f16,0x42c($sp)
/*  f0f4150:	e7b20428 */ 	swc1	$f18,0x428($sp)
/*  f0f4154:	e7ae0424 */ 	swc1	$f14,0x424($sp)
/*  f0f4158:	c6020548 */ 	lwc1	$f2,0x548($s0)
/*  f0f415c:	c60c054c */ 	lwc1	$f12,0x54c($s0)
/*  f0f4160:	c6000550 */ 	lwc1	$f0,0x550($s0)
/*  f0f4164:	e6020520 */ 	swc1	$f2,0x520($s0)
/*  f0f4168:	e60c0524 */ 	swc1	$f12,0x524($s0)
/*  f0f416c:	e6000528 */ 	swc1	$f0,0x528($s0)
/*  f0f4170:	e7a20398 */ 	swc1	$f2,0x398($sp)
/*  f0f4174:	e7ac039c */ 	swc1	$f12,0x39c($sp)
/*  f0f4178:	0c005923 */ 	jal	func0001648c
/*  f0f417c:	e7a003a0 */ 	swc1	$f0,0x3a0($sp)
/*  f0f4180:	100000b4 */ 	beqz	$zero,.L0f0f4454
/*  f0f4184:	3c01c2c8 */ 	lui	$at,0xc2c8
.L0f0f4188:
/*  f0f4188:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f418c:	3c01800a */ 	lui	$at,0x800a
/*  f0f4190:	00027300 */ 	sll	$t6,$v0,0xc
/*  f0f4194:	000e17c2 */ 	srl	$v0,$t6,0x1f
/*  f0f4198:	10400093 */ 	beqz	$v0,.L0f0f43e8
/*  f0f419c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f41a0:	c4289fc4 */ 	lwc1	$f8,-0x603c($at)
/*  f0f41a4:	3c014220 */ 	lui	$at,0x4220
/*  f0f41a8:	44815000 */ 	mtc1	$at,$f10
/*  f0f41ac:	c6040564 */ 	lwc1	$f4,0x564($s0)
/*  f0f41b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f41b4:	460a4183 */ 	div.s	$f6,$f8,$f10
/*  f0f41b8:	44815000 */ 	mtc1	$at,$f10
/*  f0f41bc:	3c017f1b */ 	lui	$at,%hi(var7f1b2948)
/*  f0f41c0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0f41c4:	e6080564 */ 	swc1	$f8,0x564($s0)
/*  f0f41c8:	c6000564 */ 	lwc1	$f0,0x564($s0)
/*  f0f41cc:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0f41d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f41d4:	45000010 */ 	bc1f	.L0f0f4218
/*  f0f41d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f41dc:	920c05b1 */ 	lbu	$t4,0x5b1($s0)
/*  f0f41e0:	c6040538 */ 	lwc1	$f4,0x538($s0)
/*  f0f41e4:	c606053c */ 	lwc1	$f6,0x53c($s0)
/*  f0f41e8:	318ffff7 */ 	andi	$t7,$t4,0xfff7
/*  f0f41ec:	a20f05b1 */ 	sb	$t7,0x5b1($s0)
/*  f0f41f0:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f41f4:	c6080540 */ 	lwc1	$f8,0x540($s0)
/*  f0f41f8:	c60a0544 */ 	lwc1	$f10,0x544($s0)
/*  f0f41fc:	0002c300 */ 	sll	$t8,$v0,0xc
/*  f0f4200:	001817c2 */ 	srl	$v0,$t8,0x1f
/*  f0f4204:	e6040510 */ 	swc1	$f4,0x510($s0)
/*  f0f4208:	e6060514 */ 	swc1	$f6,0x514($s0)
/*  f0f420c:	e6080518 */ 	swc1	$f8,0x518($s0)
/*  f0f4210:	10000075 */ 	beqz	$zero,.L0f0f43e8
/*  f0f4214:	e60a051c */ 	swc1	$f10,0x51c($s0)
.L0f0f4218:
/*  f0f4218:	c4242948 */ 	lwc1	$f4,%lo(var7f1b2948)($at)
/*  f0f421c:	46040302 */ 	mul.s	$f12,$f0,$f4
/*  f0f4220:	0c0068f4 */ 	jal	func0001a3d0
/*  f0f4224:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4228:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f422c:	44814000 */ 	mtc1	$at,$f8
/*  f0f4230:	46000187 */ 	neg.s	$f6,$f0
/*  f0f4234:	44812000 */ 	mtc1	$at,$f4
/*  f0f4238:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0f423c:	92020568 */ 	lbu	$v0,0x568($s0)
/*  f0f4240:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f4244:	44813000 */ 	mtc1	$at,$f6
/*  f0f4248:	304a0002 */ 	andi	$t2,$v0,0x2
/*  f0f424c:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f4250:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f4254:	46045080 */ 	add.s	$f2,$f10,$f4
/*  f0f4258:	46001386 */ 	mov.s	$f14,$f2
/*  f0f425c:	11400017 */ 	beqz	$t2,.L0f0f42bc
/*  f0f4260:	46023301 */ 	sub.s	$f12,$f6,$f2
/*  f0f4264:	c6080510 */ 	lwc1	$f8,0x510($s0)
/*  f0f4268:	c6040538 */ 	lwc1	$f4,0x538($s0)
/*  f0f426c:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0f4270:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4274:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f0f4278:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0f427c:	e7a80430 */ 	swc1	$f8,0x430($sp)
/*  f0f4280:	c6040514 */ 	lwc1	$f4,0x514($s0)
/*  f0f4284:	c606053c */ 	lwc1	$f6,0x53c($s0)
/*  f0f4288:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f0f428c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4290:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0f4294:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0f4298:	e7a4042c */ 	swc1	$f4,0x42c($sp)
/*  f0f429c:	c6060518 */ 	lwc1	$f6,0x518($s0)
/*  f0f42a0:	c6080540 */ 	lwc1	$f8,0x540($s0)
/*  f0f42a4:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f0f42a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f42ac:	46081102 */ 	mul.s	$f4,$f2,$f8
/*  f0f42b0:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0f42b4:	1000000b */ 	beqz	$zero,.L0f0f42e4
/*  f0f42b8:	e7a60428 */ 	swc1	$f6,0x428($sp)
.L0f0f42bc:
/*  f0f42bc:	c6000538 */ 	lwc1	$f0,0x538($s0)
/*  f0f42c0:	e6000510 */ 	swc1	$f0,0x510($s0)
/*  f0f42c4:	e7a00430 */ 	swc1	$f0,0x430($sp)
/*  f0f42c8:	c600053c */ 	lwc1	$f0,0x53c($s0)
/*  f0f42cc:	e6000514 */ 	swc1	$f0,0x514($s0)
/*  f0f42d0:	e7a0042c */ 	swc1	$f0,0x42c($sp)
/*  f0f42d4:	c6000540 */ 	lwc1	$f0,0x540($s0)
/*  f0f42d8:	e6000518 */ 	swc1	$f0,0x518($s0)
/*  f0f42dc:	e7a00428 */ 	swc1	$f0,0x428($sp)
/*  f0f42e0:	92020568 */ 	lbu	$v0,0x568($s0)
.L0f0f42e4:
/*  f0f42e4:	304b0001 */ 	andi	$t3,$v0,0x1
/*  f0f42e8:	5160000a */ 	beqzl	$t3,.L0f0f4314
/*  f0f42ec:	c6000544 */ 	lwc1	$f0,0x544($s0)
/*  f0f42f0:	c608051c */ 	lwc1	$f8,0x51c($s0)
/*  f0f42f4:	c6040544 */ 	lwc1	$f4,0x544($s0)
/*  f0f42f8:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0f42fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4300:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f0f4304:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0f4308:	10000005 */ 	beqz	$zero,.L0f0f4320
/*  f0f430c:	e7a80424 */ 	swc1	$f8,0x424($sp)
/*  f0f4310:	c6000544 */ 	lwc1	$f0,0x544($s0)
.L0f0f4314:
/*  f0f4314:	e600051c */ 	swc1	$f0,0x51c($s0)
/*  f0f4318:	e7a00424 */ 	swc1	$f0,0x424($sp)
/*  f0f431c:	92020568 */ 	lbu	$v0,0x568($s0)
.L0f0f4320:
/*  f0f4320:	304e0004 */ 	andi	$t6,$v0,0x4
/*  f0f4324:	51c00024 */ 	beqzl	$t6,.L0f0f43b8
/*  f0f4328:	c6020548 */ 	lwc1	$f2,0x548($s0)
/*  f0f432c:	c6040520 */ 	lwc1	$f4,0x520($s0)
/*  f0f4330:	27b10290 */ 	addiu	$s1,$sp,0x290
/*  f0f4334:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f4338:	e7a40290 */ 	swc1	$f4,0x290($sp)
/*  f0f433c:	c60a0524 */ 	lwc1	$f10,0x524($s0)
/*  f0f4340:	27a502bc */ 	addiu	$a1,$sp,0x2bc
/*  f0f4344:	e7aa0294 */ 	swc1	$f10,0x294($sp)
/*  f0f4348:	c6060528 */ 	lwc1	$f6,0x528($s0)
/*  f0f434c:	e7ae02d0 */ 	swc1	$f14,0x2d0($sp)
/*  f0f4350:	0fc25b28 */ 	jal	func0f096ca0
/*  f0f4354:	e7a60298 */ 	swc1	$f6,0x298($sp)
/*  f0f4358:	c6080548 */ 	lwc1	$f8,0x548($s0)
/*  f0f435c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f4360:	27a502ac */ 	addiu	$a1,$sp,0x2ac
/*  f0f4364:	e7a80290 */ 	swc1	$f8,0x290($sp)
/*  f0f4368:	c604054c */ 	lwc1	$f4,0x54c($s0)
/*  f0f436c:	e7a40294 */ 	swc1	$f4,0x294($sp)
/*  f0f4370:	c60a0550 */ 	lwc1	$f10,0x550($s0)
/*  f0f4374:	0fc25b28 */ 	jal	func0f096ca0
/*  f0f4378:	e7aa0298 */ 	swc1	$f10,0x298($sp)
/*  f0f437c:	c7ae02d0 */ 	lwc1	$f14,0x2d0($sp)
/*  f0f4380:	27b1029c */ 	addiu	$s1,$sp,0x29c
/*  f0f4384:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f4388:	44067000 */ 	mfc1	$a2,$f14
/*  f0f438c:	27a402bc */ 	addiu	$a0,$sp,0x2bc
/*  f0f4390:	0fc25cae */ 	jal	func0f0972b8
/*  f0f4394:	27a502ac */ 	addiu	$a1,$sp,0x2ac
/*  f0f4398:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f439c:	0fc25bb5 */ 	jal	func0f096ed4
/*  f0f43a0:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f43a4:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f43a8:	00026b00 */ 	sll	$t5,$v0,0xc
/*  f0f43ac:	1000000e */ 	beqz	$zero,.L0f0f43e8
/*  f0f43b0:	000d17c2 */ 	srl	$v0,$t5,0x1f
/*  f0f43b4:	c6020548 */ 	lwc1	$f2,0x548($s0)
.L0f0f43b8:
/*  f0f43b8:	c60c054c */ 	lwc1	$f12,0x54c($s0)
/*  f0f43bc:	c6000550 */ 	lwc1	$f0,0x550($s0)
/*  f0f43c0:	e6020520 */ 	swc1	$f2,0x520($s0)
/*  f0f43c4:	e60c0524 */ 	swc1	$f12,0x524($s0)
/*  f0f43c8:	e6000528 */ 	swc1	$f0,0x528($s0)
/*  f0f43cc:	e7a20398 */ 	swc1	$f2,0x398($sp)
/*  f0f43d0:	e7ac039c */ 	swc1	$f12,0x39c($sp)
/*  f0f43d4:	0c005923 */ 	jal	func0001648c
/*  f0f43d8:	e7a003a0 */ 	swc1	$f0,0x3a0($sp)
/*  f0f43dc:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f43e0:	00027b00 */ 	sll	$t7,$v0,0xc
/*  f0f43e4:	000f17c2 */ 	srl	$v0,$t7,0x1f
.L0f0f43e8:
/*  f0f43e8:	5440001a */ 	bnezl	$v0,.L0f0f4454
/*  f0f43ec:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f0f43f0:	c6000538 */ 	lwc1	$f0,0x538($s0)
/*  f0f43f4:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f43f8:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f43fc:	e6000510 */ 	swc1	$f0,0x510($s0)
/*  f0f4400:	e7a00430 */ 	swc1	$f0,0x430($sp)
/*  f0f4404:	c600053c */ 	lwc1	$f0,0x53c($s0)
/*  f0f4408:	e6000514 */ 	swc1	$f0,0x514($s0)
/*  f0f440c:	e7a0042c */ 	swc1	$f0,0x42c($sp)
/*  f0f4410:	c6000540 */ 	lwc1	$f0,0x540($s0)
/*  f0f4414:	e6000518 */ 	swc1	$f0,0x518($s0)
/*  f0f4418:	e7a00428 */ 	swc1	$f0,0x428($sp)
/*  f0f441c:	c6000544 */ 	lwc1	$f0,0x544($s0)
/*  f0f4420:	e600051c */ 	swc1	$f0,0x51c($s0)
/*  f0f4424:	e7a00424 */ 	swc1	$f0,0x424($sp)
/*  f0f4428:	c6020548 */ 	lwc1	$f2,0x548($s0)
/*  f0f442c:	c60c054c */ 	lwc1	$f12,0x54c($s0)
/*  f0f4430:	c6000550 */ 	lwc1	$f0,0x550($s0)
/*  f0f4434:	e6020520 */ 	swc1	$f2,0x520($s0)
/*  f0f4438:	e60c0524 */ 	swc1	$f12,0x524($s0)
/*  f0f443c:	e6000528 */ 	swc1	$f0,0x528($s0)
/*  f0f4440:	e7a20398 */ 	swc1	$f2,0x398($sp)
/*  f0f4444:	e7ac039c */ 	swc1	$f12,0x39c($sp)
/*  f0f4448:	0c005923 */ 	jal	func0001648c
/*  f0f444c:	e7a003a0 */ 	swc1	$f0,0x3a0($sp)
.L0f0f4450:
/*  f0f4450:	3c01c2c8 */ 	lui	$at,0xc2c8
.L0f0f4454:
/*  f0f4454:	44813000 */ 	mtc1	$at,$f6
/*  f0f4458:	c7a80428 */ 	lwc1	$f8,0x428($sp)
/*  f0f445c:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f4460:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f4464:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0f4468:	17210011 */ 	bne	$t9,$at,.L0f0f44b0
/*  f0f446c:	e7a4030c */ 	swc1	$f4,0x30c($sp)
/*  f0f4470:	3c0a8009 */ 	lui	$t2,0x8009
/*  f0f4474:	914a0af0 */ 	lbu	$t2,0xaf0($t2)
/*  f0f4478:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f447c:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0f4480:	51410035 */ 	beql	$t2,$at,.L0f0f4558
/*  f0f4484:	27a40390 */ 	addiu	$a0,$sp,0x390
/*  f0f4488:	8d6bfac0 */ 	lw	$t3,-0x540($t3)
/*  f0f448c:	c60a0510 */ 	lwc1	$f10,0x510($s0)
/*  f0f4490:	448b3000 */ 	mtc1	$t3,$f6
/*  f0f4494:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4498:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f449c:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0f44a0:	e7a40390 */ 	swc1	$f4,0x390($sp)
/*  f0f44a4:	c6060514 */ 	lwc1	$f6,0x514($s0)
/*  f0f44a8:	1000002a */ 	beqz	$zero,.L0f0f4554
/*  f0f44ac:	e7a60394 */ 	swc1	$f6,0x394($sp)
.L0f0f44b0:
/*  f0f44b0:	0c002f40 */ 	jal	func0000bd00
/*  f0f44b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f44b8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f44bc:	00117403 */ 	sra	$t6,$s1,0x10
/*  f0f44c0:	0c002f22 */ 	jal	func0000bc88
/*  f0f44c4:	01c08825 */ 	or	$s1,$t6,$zero
/*  f0f44c8:	44825000 */ 	mtc1	$v0,$f10
/*  f0f44cc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f44d0:	44812000 */ 	mtc1	$at,$f4
/*  f0f44d4:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0f44d8:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0f44dc:	8dadfac0 */ 	lw	$t5,-0x540($t5)
/*  f0f44e0:	c7aa0430 */ 	lwc1	$f10,0x430($sp)
/*  f0f44e4:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0f44e8:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f44ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f44f0:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0f44f4:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f0f44f8:	44915000 */ 	mtc1	$s1,$f10
/*  f0f44fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4500:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0f4504:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0f4508:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0f450c:	0c002f44 */ 	jal	func0000bd10
/*  f0f4510:	e7a80390 */ 	swc1	$f8,0x390($sp)
/*  f0f4514:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f4518:	00116403 */ 	sra	$t4,$s1,0x10
/*  f0f451c:	0c002f26 */ 	jal	func0000bc98
/*  f0f4520:	01808825 */ 	or	$s1,$t4,$zero
/*  f0f4524:	44822000 */ 	mtc1	$v0,$f4
/*  f0f4528:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f452c:	44815000 */ 	mtc1	$at,$f10
/*  f0f4530:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f4534:	c7a4042c */ 	lwc1	$f4,0x42c($sp)
/*  f0f4538:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0f453c:	44913000 */ 	mtc1	$s1,$f6
/*  f0f4540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4544:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0f4548:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0f454c:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0f4550:	e7a40394 */ 	swc1	$f4,0x394($sp)
.L0f0f4554:
/*  f0f4554:	27a40390 */ 	addiu	$a0,$sp,0x390
.L0f0f4558:
/*  f0f4558:	27a50398 */ 	addiu	$a1,$sp,0x398
/*  f0f455c:	0fc2d30f */ 	jal	func0f0b4c3c
/*  f0f4560:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0f4564:	0c00566c */ 	jal	func000159b0
/*  f0f4568:	27a40310 */ 	addiu	$a0,$sp,0x310
/*  f0f456c:	8e0205b4 */ 	lw	$v0,0x5b4($s0)
/*  f0f4570:	5040001d */ 	beqzl	$v0,.L0f0f45e8
/*  f0f4574:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f4578:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f0f457c:	241100ff */ 	addiu	$s1,$zero,0xff
/*  f0f4580:	00401825 */ 	or	$v1,$v0,$zero
/*  f0f4584:	52250018 */ 	beql	$s1,$a1,.L0f0f45e8
/*  f0f4588:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f458c:	8e040054 */ 	lw	$a0,0x54($s0)
.L0f0f4590:
/*  f0f4590:	0c006a47 */ 	jal	func0001a91c
/*  f0f4594:	afa3028c */ 	sw	$v1,0x28c($sp)
/*  f0f4598:	8fa3028c */ 	lw	$v1,0x28c($sp)
/*  f0f459c:	1040000d */ 	beqz	$v0,.L0f0f45d4
/*  f0f45a0:	00402825 */ 	or	$a1,$v0,$zero
/*  f0f45a4:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f45a8:	0c006a87 */ 	jal	func0001aa1c
/*  f0f45ac:	afa3028c */ 	sw	$v1,0x28c($sp)
/*  f0f45b0:	10400008 */ 	beqz	$v0,.L0f0f45d4
/*  f0f45b4:	8fa3028c */ 	lw	$v1,0x28c($sp)
/*  f0f45b8:	906f0001 */ 	lbu	$t7,0x1($v1)
/*  f0f45bc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f45c0:	51e00004 */ 	beqzl	$t7,.L0f0f45d4
/*  f0f45c4:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f0f45c8:	10000002 */ 	beqz	$zero,.L0f0f45d4
/*  f0f45cc:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0f45d0:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f0f45d4:
/*  f0f45d4:	90650002 */ 	lbu	$a1,0x2($v1)
/*  f0f45d8:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0f45dc:	5625ffec */ 	bnel	$s1,$a1,.L0f0f4590
/*  f0f45e0:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f45e4:	8fb90448 */ 	lw	$t9,0x448($sp)
.L0f0f45e8:
/*  f0f45e8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f45ec:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f45f0:	57210009 */ 	bnel	$t9,$at,.L0f0f4618
/*  f0f45f4:	c7a203a0 */ 	lwc1	$f2,0x3a0($sp)
/*  f0f45f8:	c60a0510 */ 	lwc1	$f10,0x510($s0)
/*  f0f45fc:	e7aa0398 */ 	swc1	$f10,0x398($sp)
/*  f0f4600:	c6080514 */ 	lwc1	$f8,0x514($s0)
/*  f0f4604:	e7a8039c */ 	swc1	$f8,0x39c($sp)
/*  f0f4608:	c6060518 */ 	lwc1	$f6,0x518($s0)
/*  f0f460c:	1000000e */ 	beqz	$zero,.L0f0f4648
/*  f0f4610:	e7a603a0 */ 	swc1	$f6,0x3a0($sp)
/*  f0f4614:	c7a203a0 */ 	lwc1	$f2,0x3a0($sp)
.L0f0f4618:
/*  f0f4618:	c7a4030c */ 	lwc1	$f4,0x30c($sp)
/*  f0f461c:	c7aa0398 */ 	lwc1	$f10,0x398($sp)
/*  f0f4620:	c7a6039c */ 	lwc1	$f6,0x39c($sp)
/*  f0f4624:	46022003 */ 	div.s	$f0,$f4,$f2
/*  f0f4628:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0f462c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4630:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0f4634:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4638:	46020082 */ 	mul.s	$f2,$f0,$f2
/*  f0f463c:	e7a80398 */ 	swc1	$f8,0x398($sp)
/*  f0f4640:	e7a4039c */ 	swc1	$f4,0x39c($sp)
/*  f0f4644:	e7a203a0 */ 	swc1	$f2,0x3a0($sp)
.L0f0f4648:
/*  f0f4648:	0c0059b7 */ 	jal	func000166dc
/*  f0f464c:	27a50310 */ 	addiu	$a1,$sp,0x310
/*  f0f4650:	8faa0308 */ 	lw	$t2,0x308($sp)
/*  f0f4654:	5140000a */ 	beqzl	$t2,.L0f0f4680
/*  f0f4658:	c7ac0424 */ 	lwc1	$f12,0x424($sp)
/*  f0f465c:	c7aa0424 */ 	lwc1	$f10,0x424($sp)
/*  f0f4660:	c7a802f8 */ 	lwc1	$f8,0x2f8($sp)
/*  f0f4664:	27a50310 */ 	addiu	$a1,$sp,0x310
/*  f0f4668:	46085302 */ 	mul.s	$f12,$f10,$f8
/*  f0f466c:	0c0057c1 */ 	jal	func00015f04
/*  f0f4670:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4674:	10000005 */ 	beqz	$zero,.L0f0f468c
/*  f0f4678:	8fab0308 */ 	lw	$t3,0x308($sp)
/*  f0f467c:	c7ac0424 */ 	lwc1	$f12,0x424($sp)
.L0f0f4680:
/*  f0f4680:	0c0057c1 */ 	jal	func00015f04
/*  f0f4684:	27a50310 */ 	addiu	$a1,$sp,0x310
/*  f0f4688:	8fab0308 */ 	lw	$t3,0x308($sp)
.L0f0f468c:
/*  f0f468c:	11600005 */ 	beqz	$t3,.L0f0f46a4
/*  f0f4690:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0f4694:	0c0059b7 */ 	jal	func000166dc
/*  f0f4698:	27a50204 */ 	addiu	$a1,$sp,0x204
/*  f0f469c:	1000000b */ 	beqz	$zero,.L0f0f46cc
/*  f0f46a0:	27b10244 */ 	addiu	$s1,$sp,0x244
.L0f0f46a4:
/*  f0f46a4:	c606052c */ 	lwc1	$f6,0x52c($s0)
/*  f0f46a8:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f46ac:	27a50204 */ 	addiu	$a1,$sp,0x204
/*  f0f46b0:	e7a60398 */ 	swc1	$f6,0x398($sp)
/*  f0f46b4:	c6040530 */ 	lwc1	$f4,0x530($s0)
/*  f0f46b8:	e7a4039c */ 	swc1	$f4,0x39c($sp)
/*  f0f46bc:	c60a0534 */ 	lwc1	$f10,0x534($s0)
/*  f0f46c0:	0c0059b7 */ 	jal	func000166dc
/*  f0f46c4:	e7aa03a0 */ 	swc1	$f10,0x3a0($sp)
/*  f0f46c8:	27b10244 */ 	addiu	$s1,$sp,0x244
.L0f0f46cc:
/*  f0f46cc:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f46d0:	27a40310 */ 	addiu	$a0,$sp,0x310
/*  f0f46d4:	0c005680 */ 	jal	0x15a00
/*  f0f46d8:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f46dc:	8fae0448 */ 	lw	$t6,0x448($sp)
/*  f0f46e0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f46e4:	55c1000f */ 	bnel	$t6,$at,.L0f0f4724
/*  f0f46e8:	26060014 */ 	addiu	$a2,$s0,0x14
/*  f0f46ec:	0fc4eb81 */ 	jal	func0f13ae04
/*  f0f46f0:	27a401c4 */ 	addiu	$a0,$sp,0x1c4
/*  f0f46f4:	27a401c4 */ 	addiu	$a0,$sp,0x1c4
/*  f0f46f8:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f46fc:	0c005680 */ 	jal	0x15a00
/*  f0f4700:	27a60184 */ 	addiu	$a2,$sp,0x184
/*  f0f4704:	26060014 */ 	addiu	$a2,$s0,0x14
/*  f0f4708:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0f470c:	27a40184 */ 	addiu	$a0,$sp,0x184
/*  f0f4710:	0c005680 */ 	jal	0x15a00
/*  f0f4714:	27a50204 */ 	addiu	$a1,$sp,0x204
/*  f0f4718:	10000006 */ 	beqz	$zero,.L0f0f4734
/*  f0f471c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4720:	26060014 */ 	addiu	$a2,$s0,0x14
.L0f0f4724:
/*  f0f4724:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0f4728:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f472c:	0c005680 */ 	jal	0x15a00
/*  f0f4730:	27a50204 */ 	addiu	$a1,$sp,0x204
.L0f0f4734:
/*  f0f4734:	0fc388d2 */ 	jal	func0f0e2348
/*  f0f4738:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f473c:	8fad0448 */ 	lw	$t5,0x448($sp)
/*  f0f4740:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f4744:	29a10003 */ 	slti	$at,$t5,0x3
/*  f0f4748:	5020006f */ 	beqzl	$at,.L0f0f4908
/*  f0f474c:	8e0a0054 */ 	lw	$t2,0x54($s0)
/*  f0f4750:	11a0000e */ 	beqz	$t5,.L0f0f478c
/*  f0f4754:	3c11800a */ 	lui	$s1,%hi(var800a2038)
/*  f0f4758:	0fc35272 */ 	jal	func0f0d49c8
/*  f0f475c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f4760:	244c0008 */ 	addiu	$t4,$v0,0x8
/*  f0f4764:	3c0f0103 */ 	lui	$t7,0x103
/*  f0f4768:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f0f476c:	afac0440 */ 	sw	$t4,0x440($sp)
/*  f0f4770:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0f4774:	0fc2d3fa */ 	jal	func0f0b4fe8
/*  f0f4778:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f477c:	0c012d20 */ 	jal	func0004b480
/*  f0f4780:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f4784:	1000005f */ 	beqz	$zero,.L0f0f4904
/*  f0f4788:	ae220004 */ 	sw	$v0,0x4($s1)
.L0f0f478c:
/*  f0f478c:	26312038 */ 	addiu	$s1,$s1,%lo(var800a2038)
/*  f0f4790:	3c18800a */ 	lui	$t8,0x800a
/*  f0f4794:	3c0b800a */ 	lui	$t3,0x800a
/*  f0f4798:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f479c:	8dce2040 */ 	lw	$t6,0x2040($t6)
/*  f0f47a0:	8d6b2044 */ 	lw	$t3,0x2044($t3)
/*  f0f47a4:	8f18203c */ 	lw	$t8,0x203c($t8)
/*  f0f47a8:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f0f47ac:	016e6823 */ 	subu	$t5,$t3,$t6
/*  f0f47b0:	448d2000 */ 	mtc1	$t5,$f4
/*  f0f47b4:	03195023 */ 	subu	$t2,$t8,$t9
/*  f0f47b8:	448a4000 */ 	mtc1	$t2,$f8
/*  f0f47bc:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0f47c0:	3c047f1b */ 	lui	$a0,%hi(var7f1b25f0)
/*  f0f47c4:	3c058007 */ 	lui	$a1,%hi(var800714c0)
/*  f0f47c8:	24a514c0 */ 	addiu	$a1,$a1,%lo(var800714c0)
/*  f0f47cc:	248425f0 */ 	addiu	$a0,$a0,%lo(var7f1b25f0)
/*  f0f47d0:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0f47d4:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f0f47d8:	0c0036cc */ 	jal	func0000db30
/*  f0f47dc:	e7a8017c */ 	swc1	$f8,0x17c($sp)
/*  f0f47e0:	3c047f1b */ 	lui	$a0,%hi(var7f1b25f4)
/*  f0f47e4:	3c058007 */ 	lui	$a1,%hi(var800714c4)
/*  f0f47e8:	24a514c4 */ 	addiu	$a1,$a1,%lo(var800714c4)
/*  f0f47ec:	0c0036cc */ 	jal	func0000db30
/*  f0f47f0:	248425f4 */ 	addiu	$a0,$a0,%lo(var7f1b25f4)
/*  f0f47f4:	0fc35272 */ 	jal	func0f0d49c8
/*  f0f47f8:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f47fc:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0f4800:	8deffac0 */ 	lw	$t7,-0x540($t7)
/*  f0f4804:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f0f4808:	3c05800a */ 	lui	$a1,0x800a
/*  f0f480c:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f4810:	018f0019 */ 	multu	$t4,$t7
/*  f0f4814:	84a52042 */ 	lh	$a1,0x2042($a1)
/*  f0f4818:	00002012 */ 	mflo	$a0
/*  f0f481c:	0004c400 */ 	sll	$t8,$a0,0x10
/*  f0f4820:	0c002f2a */ 	jal	func0000bca8
/*  f0f4824:	00182403 */ 	sra	$a0,$t8,0x10
/*  f0f4828:	3c0b800a */ 	lui	$t3,0x800a
/*  f0f482c:	8d6b203c */ 	lw	$t3,0x203c($t3)
/*  f0f4830:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0f4834:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0f4838:	8d8cfac0 */ 	lw	$t4,-0x540($t4)
/*  f0f483c:	016e6823 */ 	subu	$t5,$t3,$t6
/*  f0f4840:	3c0a800a */ 	lui	$t2,0x800a
/*  f0f4844:	01ac0019 */ 	multu	$t5,$t4
/*  f0f4848:	8d4aa244 */ 	lw	$t2,-0x5dbc($t2)
/*  f0f484c:	3c19800a */ 	lui	$t9,0x800a
/*  f0f4850:	8f392044 */ 	lw	$t9,0x2044($t9)
/*  f0f4854:	c54c1854 */ 	lwc1	$f12,0x1854($t2)
/*  f0f4858:	3c0a800a */ 	lui	$t2,0x800a
/*  f0f485c:	8d4a2040 */ 	lw	$t2,0x2040($t2)
/*  f0f4860:	c7ae017c */ 	lwc1	$f14,0x17c($sp)
/*  f0f4864:	032a3823 */ 	subu	$a3,$t9,$t2
/*  f0f4868:	00003012 */ 	mflo	$a2
/*  f0f486c:	00067c00 */ 	sll	$t7,$a2,0x10
/*  f0f4870:	00075c00 */ 	sll	$t3,$a3,0x10
/*  f0f4874:	000b3c03 */ 	sra	$a3,$t3,0x10
/*  f0f4878:	0c002f76 */ 	jal	func0000bdd8
/*  f0f487c:	000f3403 */ 	sra	$a2,$t7,0x10
/*  f0f4880:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0f4884:	8dad1448 */ 	lw	$t5,0x1448($t5)
/*  f0f4888:	3c0f800a */ 	lui	$t7,%hi(var800a2048)
/*  f0f488c:	25ef2048 */ 	addiu	$t7,$t7,%lo(var800a2048)
/*  f0f4890:	000d6140 */ 	sll	$t4,$t5,0x5
/*  f0f4894:	018f2821 */ 	addu	$a1,$t4,$t7
/*  f0f4898:	0c002bc0 */ 	jal	func0000af00
/*  f0f489c:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f48a0:	3c188007 */ 	lui	$t8,0x8007
/*  f0f48a4:	8f1814c0 */ 	lw	$t8,0x14c0($t8)
/*  f0f48a8:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f48ac:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f48b0:	44982000 */ 	mtc1	$t8,$f4
/*  f0f48b4:	3c198007 */ 	lui	$t9,0x8007
/*  f0f48b8:	07010005 */ 	bgez	$t8,.L0f0f48d0
/*  f0f48bc:	46802120 */ 	cvt.s.w	$f4,$f4
/*  f0f48c0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0f48c4:	44813000 */ 	mtc1	$at,$f6
/*  f0f48c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f48cc:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f0f48d0:
/*  f0f48d0:	8f3914c4 */ 	lw	$t9,0x14c4($t9)
/*  f0f48d4:	44052000 */ 	mfc1	$a1,$f4
/*  f0f48d8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0f48dc:	44995000 */ 	mtc1	$t9,$f10
/*  f0f48e0:	07210004 */ 	bgez	$t9,.L0f0f48f4
/*  f0f48e4:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f0f48e8:	44814000 */ 	mtc1	$at,$f8
/*  f0f48ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f48f0:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f0f48f4:
/*  f0f48f4:	44065000 */ 	mfc1	$a2,$f10
/*  f0f48f8:	0c002b29 */ 	jal	func0000aca4
/*  f0f48fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4900:	afa20440 */ 	sw	$v0,0x440($sp)
.L0f0f4904:
/*  f0f4904:	8e0a0054 */ 	lw	$t2,0x54($s0)
.L0f0f4908:
/*  f0f4908:	8544000e */ 	lh	$a0,0xe($t2)
/*  f0f490c:	00045980 */ 	sll	$t3,$a0,0x6
/*  f0f4910:	0fc59e7d */ 	jal	func0f1679f4
/*  f0f4914:	01602025 */ 	or	$a0,$t3,$zero
/*  f0f4918:	afa203b4 */ 	sw	$v0,0x3b4($sp)
/*  f0f491c:	8e0e0054 */ 	lw	$t6,0x54($s0)
/*  f0f4920:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f4924:	85cd000e */ 	lh	$t5,0xe($t6)
/*  f0f4928:	59a0000d */ 	blezl	$t5,.L0f0f4960
/*  f0f492c:	8605005c */ 	lh	$a1,0x5c($s0)
/*  f0f4930:	8faf03b4 */ 	lw	$t7,0x3b4($sp)
.L0f0f4934:
/*  f0f4934:	00116180 */ 	sll	$t4,$s1,0x6
/*  f0f4938:	0c00566c */ 	jal	func000159b0
/*  f0f493c:	018f2021 */ 	addu	$a0,$t4,$t7
/*  f0f4940:	8e180054 */ 	lw	$t8,0x54($s0)
/*  f0f4944:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f4948:	8719000e */ 	lh	$t9,0xe($t8)
/*  f0f494c:	0239082a */ 	slt	$at,$s1,$t9
/*  f0f4950:	5420fff8 */ 	bnezl	$at,.L0f0f4934
/*  f0f4954:	8faf03b4 */ 	lw	$t7,0x3b4($sp)
/*  f0f4958:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f495c:	8605005c */ 	lh	$a1,0x5c($s0)
.L0f0f4960:
/*  f0f4960:	8faa03b4 */ 	lw	$t2,0x3b4($sp)
/*  f0f4964:	10a00025 */ 	beqz	$a1,.L0f0f49fc
/*  f0f4968:	ae0a006c */ 	sw	$t2,0x6c($s0)
/*  f0f496c:	860b005e */ 	lh	$t3,0x5e($s0)
/*  f0f4970:	50ab0023 */ 	beql	$a1,$t3,.L0f0f4a00
/*  f0f4974:	8618005e */ 	lh	$t8,0x5e($s0)
/*  f0f4978:	8e0e05b0 */ 	lw	$t6,0x5b0($s0)
/*  f0f497c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4980:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f4984:	000e62c0 */ 	sll	$t4,$t6,0xb
/*  f0f4988:	05810014 */ 	bgez	$t4,.L0f0f49dc
/*  f0f498c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f4990:	3c01bf00 */ 	lui	$at,0xbf00
/*  f0f4994:	44812000 */ 	mtc1	$at,$f4
/*  f0f4998:	44803000 */ 	mtc1	$zero,$f6
/*  f0f499c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f49a0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f49a4:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f0f49a8:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0f49ac:	0c007733 */ 	jal	func0001dccc
/*  f0f49b0:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0f49b4:	0c007486 */ 	jal	func0001d218
/*  f0f49b8:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f49bc:	44825000 */ 	mtc1	$v0,$f10
/*  f0f49c0:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f49c4:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f0f49c8:	44055000 */ 	mfc1	$a1,$f10
/*  f0f49cc:	0c007806 */ 	jal	func0001e018
/*  f0f49d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f49d4:	10000008 */ 	beqz	$zero,.L0f0f49f8
/*  f0f49d8:	860f005c */ 	lh	$t7,0x5c($s0)
.L0f0f49dc:
/*  f0f49dc:	44814000 */ 	mtc1	$at,$f8
/*  f0f49e0:	44802000 */ 	mtc1	$zero,$f4
/*  f0f49e4:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f0f49e8:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0f49ec:	0c007733 */ 	jal	func0001dccc
/*  f0f49f0:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0f49f4:	860f005c */ 	lh	$t7,0x5c($s0)
.L0f0f49f8:
/*  f0f49f8:	a60f005e */ 	sh	$t7,0x5e($s0)
.L0f0f49fc:
/*  f0f49fc:	8618005e */ 	lh	$t8,0x5e($s0)
.L0f0f4a00:
/*  f0f4a00:	a600005c */ 	sh	$zero,0x5c($s0)
/*  f0f4a04:	13000023 */ 	beqz	$t8,.L0f0f4a94
/*  f0f4a08:	3c05800a */ 	lui	$a1,0x800a
/*  f0f4a0c:	8ca5a000 */ 	lw	$a1,-0x6000($a1)
/*  f0f4a10:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a14:	0c007b86 */ 	jal	func0001ee18
/*  f0f4a18:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0f4a1c:	8e1905b0 */ 	lw	$t9,0x5b0($s0)
/*  f0f4a20:	00195ac0 */ 	sll	$t3,$t9,0xb
/*  f0f4a24:	0561000c */ 	bgez	$t3,.L0f0f4a58
/*  f0f4a28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4a2c:	0c007486 */ 	jal	func0001d218
/*  f0f4a30:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a34:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f4a38:	0c00745f */ 	jal	func0001d17c
/*  f0f4a3c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a40:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0f4a44:	448e3000 */ 	mtc1	$t6,$f6
/*  f0f4a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4a4c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0f4a50:	10000004 */ 	beqz	$zero,.L0f0f4a64
/*  f0f4a54:	46005081 */ 	sub.s	$f2,$f10,$f0
.L0f0f4a58:
/*  f0f4a58:	0c00745f */ 	jal	func0001d17c
/*  f0f4a5c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a60:	46000086 */ 	mov.s	$f2,$f0
.L0f0f4a64:
/*  f0f4a64:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a68:	0c007486 */ 	jal	func0001d218
/*  f0f4a6c:	e7a20178 */ 	swc1	$f2,0x178($sp)
/*  f0f4a70:	244dffff */ 	addiu	$t5,$v0,-1
/*  f0f4a74:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f4a78:	c7a20178 */ 	lwc1	$f2,0x178($sp)
/*  f0f4a7c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0f4a80:	4602203e */ 	c.le.s	$f4,$f2
/*  f0f4a84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4a88:	45020003 */ 	bc1fl	.L0f0f4a98
/*  f0f4a8c:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f4a90:	a600005e */ 	sh	$zero,0x5e($s0)
.L0f0f4a94:
/*  f0f4a94:	8fa40040 */ 	lw	$a0,0x40($sp)
.L0f0f4a98:
/*  f0f4a98:	0c005746 */ 	jal	func00015d18
/*  f0f4a9c:	8fa503b4 */ 	lw	$a1,0x3b4($sp)
/*  f0f4aa0:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f4aa4:	27a403b8 */ 	addiu	$a0,$sp,0x3b8
/*  f0f4aa8:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0f4aac:	afac03b8 */ 	sw	$t4,0x3b8($sp)
/*  f0f4ab0:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f0f4ab4:	0c0073af */ 	jal	func0001cebc
/*  f0f4ab8:	afaf03c8 */ 	sw	$t7,0x3c8($sp)
/*  f0f4abc:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f4ac0:	3c188008 */ 	lui	$t8,%hi(stagethinglist_22c54)
/*  f0f4ac4:	2718cc34 */ 	addiu	$t8,$t8,%lo(stagethinglist_22c54)
/*  f0f4ac8:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f0f4acc:	57190092 */ 	bnel	$t8,$t9,.L0f0f4d18
/*  f0f4ad0:	8fb80440 */ 	lw	$t8,0x440($sp)
/*  f0f4ad4:	0c006a47 */ 	jal	func0001a91c
/*  f0f4ad8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4adc:	5040002e */ 	beqzl	$v0,.L0f0f4b98
/*  f0f4ae0:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f4ae4:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f0f4ae8:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0f4aec:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0f4af0:	84aa0010 */ 	lh	$t2,0x10($a1)
/*  f0f4af4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f4af8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f4afc:	19400025 */ 	blez	$t2,.L0f0f4b94
/*  f0f4b00:	24080064 */ 	addiu	$t0,$zero,0x64
/*  f0f4b04:	8d2d0000 */ 	lw	$t5,0x0($t1)
.L0f0f4b08:
/*  f0f4b08:	8cab000c */ 	lw	$t3,0xc($a1)
/*  f0f4b0c:	01a80019 */ 	multu	$t5,$t0
/*  f0f4b10:	01661021 */ 	addu	$v0,$t3,$a2
/*  f0f4b14:	844e0008 */ 	lh	$t6,0x8($v0)
/*  f0f4b18:	00006012 */ 	mflo	$t4
/*  f0f4b1c:	01cc7823 */ 	subu	$t7,$t6,$t4
/*  f0f4b20:	a44f0008 */ 	sh	$t7,0x8($v0)
/*  f0f4b24:	8cb8000c */ 	lw	$t8,0xc($a1)
/*  f0f4b28:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f0f4b2c:	872a0008 */ 	lh	$t2,0x8($t9)
/*  f0f4b30:	2941a000 */ 	slti	$at,$t2,-24576
/*  f0f4b34:	50200012 */ 	beqzl	$at,.L0f0f4b80
/*  f0f4b38:	84b80010 */ 	lh	$t8,0x10($a1)
/*  f0f4b3c:	84ab0010 */ 	lh	$t3,0x10($a1)
/*  f0f4b40:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f4b44:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f4b48:	5960000d */ 	blezl	$t3,.L0f0f4b80
/*  f0f4b4c:	84b80010 */ 	lh	$t8,0x10($a1)
/*  f0f4b50:	8cad000c */ 	lw	$t5,0xc($a1)
.L0f0f4b54:
/*  f0f4b54:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f4b58:	01a41021 */ 	addu	$v0,$t5,$a0
/*  f0f4b5c:	844e0008 */ 	lh	$t6,0x8($v0)
/*  f0f4b60:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f0f4b64:	25cc2000 */ 	addiu	$t4,$t6,0x2000
/*  f0f4b68:	a44c0008 */ 	sh	$t4,0x8($v0)
/*  f0f4b6c:	84af0010 */ 	lh	$t7,0x10($a1)
/*  f0f4b70:	006f082a */ 	slt	$at,$v1,$t7
/*  f0f4b74:	5420fff7 */ 	bnezl	$at,.L0f0f4b54
/*  f0f4b78:	8cad000c */ 	lw	$t5,0xc($a1)
/*  f0f4b7c:	84b80010 */ 	lh	$t8,0x10($a1)
.L0f0f4b80:
/*  f0f4b80:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f0f4b84:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f0f4b88:	00f8082a */ 	slt	$at,$a3,$t8
/*  f0f4b8c:	5420ffde */ 	bnezl	$at,.L0f0f4b08
/*  f0f4b90:	8d2d0000 */ 	lw	$t5,0x0($t1)
.L0f0f4b94:
/*  f0f4b94:	8e040054 */ 	lw	$a0,0x54($s0)
.L0f0f4b98:
/*  f0f4b98:	0c006a47 */ 	jal	func0001a91c
/*  f0f4b9c:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0f4ba0:	10400019 */ 	beqz	$v0,.L0f0f4c08
/*  f0f4ba4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f4ba8:	0c006949 */ 	jal	func0001a524
/*  f0f4bac:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4bb0:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0f4bb4:	0c00566c */ 	jal	func000159b0
/*  f0f4bb8:	27a40120 */ 	addiu	$a0,$sp,0x120
/*  f0f4bbc:	3c014080 */ 	lui	$at,0x4080
/*  f0f4bc0:	44816000 */ 	mtc1	$at,$f12
/*  f0f4bc4:	0fc01ad5 */ 	jal	func0f006b54
/*  f0f4bc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4bcc:	46000306 */ 	mov.s	$f12,$f0
/*  f0f4bd0:	0c0058ba */ 	jal	func000162e8
/*  f0f4bd4:	27a50120 */ 	addiu	$a1,$sp,0x120
/*  f0f4bd8:	8faa0160 */ 	lw	$t2,0x160($sp)
/*  f0f4bdc:	8fb903b4 */ 	lw	$t9,0x3b4($sp)
/*  f0f4be0:	27a50120 */ 	addiu	$a1,$sp,0x120
/*  f0f4be4:	000a5980 */ 	sll	$t3,$t2,0x6
/*  f0f4be8:	032b3821 */ 	addu	$a3,$t9,$t3
/*  f0f4bec:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0f4bf0:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f0f4bf4:	0c005680 */ 	jal	0x15a00
/*  f0f4bf8:	27a600e0 */ 	addiu	$a2,$sp,0xe0
/*  f0f4bfc:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0f4c00:	0c005746 */ 	jal	func00015d18
/*  f0f4c04:	27a400e0 */ 	addiu	$a0,$sp,0xe0
.L0f0f4c08:
/*  f0f4c08:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f4c0c:	0c006a47 */ 	jal	func0001a91c
/*  f0f4c10:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0f4c14:	1040003f */ 	beqz	$v0,.L0f0f4d14
/*  f0f4c18:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f4c1c:	3c02800a */ 	lui	$v0,%hi(var800a0040)
/*  f0f4c20:	8c4219c4 */ 	lw	$v0,0x19c4($v0)
/*  f0f4c24:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f4c28:	10410007 */ 	beq	$v0,$at,.L0f0f4c48
/*  f0f4c2c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f4c30:	10410005 */ 	beq	$v0,$at,.L0f0f4c48
/*  f0f4c34:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f4c38:	10410003 */ 	beq	$v0,$at,.L0f0f4c48
/*  f0f4c3c:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f4c40:	54410035 */ 	bnel	$v0,$at,.L0f0f4d18
/*  f0f4c44:	8fb80440 */ 	lw	$t8,0x440($sp)
.L0f0f4c48:
/*  f0f4c48:	0c006949 */ 	jal	func0001a524
/*  f0f4c4c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4c50:	8fad03b4 */ 	lw	$t5,0x3b4($sp)
/*  f0f4c54:	00027180 */ 	sll	$t6,$v0,0x6
/*  f0f4c58:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0f4c5c:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f0f4c60:	c4660030 */ 	lwc1	$f6,0x30($v1)
/*  f0f4c64:	27a500c8 */ 	addiu	$a1,$sp,0xc8
/*  f0f4c68:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*  f0f4c6c:	c46a0034 */ 	lwc1	$f10,0x34($v1)
/*  f0f4c70:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0f4c74:	c4680038 */ 	lwc1	$f8,0x38($v1)
/*  f0f4c78:	0fc2d341 */ 	jal	func0f0b4d04
/*  f0f4c7c:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
/*  f0f4c80:	0c002f02 */ 	jal	func0000bc08
/*  f0f4c84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4c88:	c7a400c8 */ 	lwc1	$f4,0xc8($sp)
/*  f0f4c8c:	3c198008 */ 	lui	$t9,0x8008
/*  f0f4c90:	8f39fac0 */ 	lw	$t9,-0x540($t9)
/*  f0f4c94:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0f4c98:	440f3000 */ 	mfc1	$t7,$f6
/*  f0f4c9c:	04410003 */ 	bgez	$v0,.L0f0f4cac
/*  f0f4ca0:	0002c043 */ 	sra	$t8,$v0,0x1
/*  f0f4ca4:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0f4ca8:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0f4cac:
/*  f0f4cac:	01f85023 */ 	subu	$t2,$t7,$t8
/*  f0f4cb0:	0159001a */ 	div	$zero,$t2,$t9
/*  f0f4cb4:	17200002 */ 	bnez	$t9,.L0f0f4cc0
/*  f0f4cb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4cbc:	0007000d */ 	break	0x7
.L0f0f4cc0:
/*  f0f4cc0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f4cc4:	17210004 */ 	bne	$t9,$at,.L0f0f4cd8
/*  f0f4cc8:	3c018000 */ 	lui	$at,0x8000
/*  f0f4ccc:	15410002 */ 	bne	$t2,$at,.L0f0f4cd8
/*  f0f4cd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4cd4:	0006000d */ 	break	0x6
.L0f0f4cd8:
/*  f0f4cd8:	3c01800a */ 	lui	$at,0x800a
/*  f0f4cdc:	00005812 */ 	mflo	$t3
/*  f0f4ce0:	ac2bde98 */ 	sw	$t3,-0x2168($at)
/*  f0f4ce4:	0c002f06 */ 	jal	func0000bc18
/*  f0f4ce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4cec:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0f4cf0:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f0f4cf4:	440e4000 */ 	mfc1	$t6,$f8
/*  f0f4cf8:	04410003 */ 	bgez	$v0,.L0f0f4d08
/*  f0f4cfc:	00026043 */ 	sra	$t4,$v0,0x1
/*  f0f4d00:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0f4d04:	00016043 */ 	sra	$t4,$at,0x1
.L0f0f4d08:
/*  f0f4d08:	3c01800a */ 	lui	$at,0x800a
/*  f0f4d0c:	01cc7823 */ 	subu	$t7,$t6,$t4
/*  f0f4d10:	ac2fde9c */ 	sw	$t7,-0x2164($at)
.L0f0f4d14:
/*  f0f4d14:	8fb80440 */ 	lw	$t8,0x440($sp)
.L0f0f4d18:
/*  f0f4d18:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f0f4d1c:	3c0b8000 */ 	lui	$t3,0x8000
/*  f0f4d20:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0f4d24:	afaa0440 */ 	sw	$t2,0x440($sp)
/*  f0f4d28:	356b0040 */ 	ori	$t3,$t3,0x40
/*  f0f4d2c:	37390002 */ 	ori	$t9,$t9,0x2
/*  f0f4d30:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0f4d34:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f0f4d38:	8fad0440 */ 	lw	$t5,0x440($sp)
/*  f0f4d3c:	3c0c0386 */ 	lui	$t4,0x386
/*  f0f4d40:	3c0f8007 */ 	lui	$t7,%hi(var80071470)
/*  f0f4d44:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0f4d48:	afae0440 */ 	sw	$t6,0x440($sp)
/*  f0f4d4c:	25ef1470 */ 	addiu	$t7,$t7,%lo(var80071470)
/*  f0f4d50:	358c0010 */ 	ori	$t4,$t4,0x10
/*  f0f4d54:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f0f4d58:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f0f4d5c:	8fb80440 */ 	lw	$t8,0x440($sp)
/*  f0f4d60:	3c0b8007 */ 	lui	$t3,%hi(var80071468)
/*  f0f4d64:	3c190388 */ 	lui	$t9,0x388
/*  f0f4d68:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0f4d6c:	afaa0440 */ 	sw	$t2,0x440($sp)
/*  f0f4d70:	37390010 */ 	ori	$t9,$t9,0x10
/*  f0f4d74:	256b1468 */ 	addiu	$t3,$t3,%lo(var80071468)
/*  f0f4d78:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f0f4d7c:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0f4d80:	8fad0440 */ 	lw	$t5,0x440($sp)
/*  f0f4d84:	3c0c0384 */ 	lui	$t4,0x384
/*  f0f4d88:	358c0010 */ 	ori	$t4,$t4,0x10
/*  f0f4d8c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0f4d90:	afae0440 */ 	sw	$t6,0x440($sp)
/*  f0f4d94:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f0f4d98:	0fc2d5ea */ 	jal	func0f0b57a8
/*  f0f4d9c:	afad00b8 */ 	sw	$t5,0xb8($sp)
/*  f0f4da0:	8fa500b8 */ 	lw	$a1,0xb8($sp)
/*  f0f4da4:	3c0a0382 */ 	lui	$t2,0x382
/*  f0f4da8:	354a0010 */ 	ori	$t2,$t2,0x10
/*  f0f4dac:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0f4db0:	8faf0440 */ 	lw	$t7,0x440($sp)
/*  f0f4db4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0f4db8:	afb80440 */ 	sw	$t8,0x440($sp)
/*  f0f4dbc:	adea0000 */ 	sw	$t2,0x0($t7)
/*  f0f4dc0:	0fc2d5ea */ 	jal	func0f0b57a8
/*  f0f4dc4:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f0f4dc8:	8fa600b4 */ 	lw	$a2,0xb4($sp)
/*  f0f4dcc:	24590010 */ 	addiu	$t9,$v0,0x10
/*  f0f4dd0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f4dd4:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f0f4dd8:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f4ddc:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0f4de0:	240effff */ 	addiu	$t6,$zero,-1
/*  f0f4de4:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f4de8:	afab03e8 */ 	sw	$t3,0x3e8($sp)
/*  f0f4dec:	afad03ec */ 	sw	$t5,0x3ec($sp)
/*  f0f4df0:	afae03f0 */ 	sw	$t6,0x3f0($sp)
/*  f0f4df4:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f4df8:	3c18b700 */ 	lui	$t8,0xb700
/*  f0f4dfc:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f4e00:	ad8a0004 */ 	sw	$t2,0x4($t4)
/*  f0f4e04:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f4e08:	8fb90440 */ 	lw	$t9,0x440($sp)
/*  f0f4e0c:	afab03bc */ 	sw	$t3,0x3bc($sp)
/*  f0f4e10:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0f4e14:	27a403b8 */ 	addiu	$a0,$sp,0x3b8
/*  f0f4e18:	0c0087bd */ 	jal	func00021ef4
/*  f0f4e1c:	afb903c4 */ 	sw	$t9,0x3c4($sp)
/*  f0f4e20:	8fad03c4 */ 	lw	$t5,0x3c4($sp)
/*  f0f4e24:	0c0059d8 */ 	jal	func00016760
/*  f0f4e28:	afad0440 */ 	sw	$t5,0x440($sp)
/*  f0f4e2c:	8e0e0054 */ 	lw	$t6,0x54($s0)
/*  f0f4e30:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f4e34:	85cc000e */ 	lh	$t4,0xe($t6)
/*  f0f4e38:	19800013 */ 	blez	$t4,.L0f0f4e88
/*  f0f4e3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4e40:	8e0f006c */ 	lw	$t7,0x6c($s0)
.L0f0f4e44:
/*  f0f4e44:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0f4e48:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f4e4c:	0c005746 */ 	jal	func00015d18
/*  f0f4e50:	01e22021 */ 	addu	$a0,$t7,$v0
/*  f0f4e54:	8e18006c */ 	lw	$t8,0x6c($s0)
/*  f0f4e58:	00115180 */ 	sll	$t2,$s1,0x6
/*  f0f4e5c:	27a40070 */ 	addiu	$a0,$sp,0x70
/*  f0f4e60:	0c005815 */ 	jal	func00016054
/*  f0f4e64:	030a2821 */ 	addu	$a1,$t8,$t2
/*  f0f4e68:	8e190054 */ 	lw	$t9,0x54($s0)
/*  f0f4e6c:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0f4e70:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f4e74:	872b000e */ 	lh	$t3,0xe($t9)
/*  f0f4e78:	24420040 */ 	addiu	$v0,$v0,%lo(var800a0040)
/*  f0f4e7c:	022b082a */ 	slt	$at,$s1,$t3
/*  f0f4e80:	5420fff0 */ 	bnezl	$at,.L0f0f4e44
/*  f0f4e84:	8e0f006c */ 	lw	$t7,0x6c($s0)
.L0f0f4e88:
/*  f0f4e88:	0c0059e1 */ 	jal	func00016784
/*  f0f4e8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f4e90:	8fad0448 */ 	lw	$t5,0x448($sp)
/*  f0f4e94:	29a10003 */ 	slti	$at,$t5,0x3
/*  f0f4e98:	50200005 */ 	beqzl	$at,.L0f0f4eb0
/*  f0f4e9c:	8fae0440 */ 	lw	$t6,0x440($sp)
/*  f0f4ea0:	0fc351e7 */ 	jal	func0f0d479c
/*  f0f4ea4:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f4ea8:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f4eac:	8fae0440 */ 	lw	$t6,0x440($sp)
.L0f0f4eb0:
/*  f0f4eb0:	3c0fe700 */ 	lui	$t7,0xe700
/*  f0f4eb4:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0f4eb8:	25cc0008 */ 	addiu	$t4,$t6,0x8
/*  f0f4ebc:	afac0440 */ 	sw	$t4,0x440($sp)
/*  f0f4ec0:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0f4ec4:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f0f4ec8:	8fb80440 */ 	lw	$t8,0x440($sp)
/*  f0f4ecc:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f0f4ed0:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0f4ed4:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0f4ed8:	afaa0440 */ 	sw	$t2,0x440($sp)
/*  f0f4edc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0f4ee0:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0f4ee4:	8fab0440 */ 	lw	$t3,0x440($sp)
/*  f0f4ee8:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f0f4eec:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f0f4ef0:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f0f4ef4:	afad0440 */ 	sw	$t5,0x440($sp)
/*  f0f4ef8:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f0f4efc:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0f4f00:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f4f04:	37187e24 */ 	ori	$t8,$t8,0x7e24
/*  f0f4f08:	240af9fc */ 	addiu	$t2,$zero,-1540
/*  f0f4f0c:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f4f10:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f4f14:	ad8a0004 */ 	sw	$t2,0x4($t4)
/*  f0f4f18:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f4f1c:	8fb90440 */ 	lw	$t9,0x440($sp)
/*  f0f4f20:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f0f4f24:	3c0db600 */ 	lui	$t5,0xb600
/*  f0f4f28:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f0f4f2c:	afab0440 */ 	sw	$t3,0x440($sp)
/*  f0f4f30:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f0f4f34:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f4f38:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f4f3c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0f4f40:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f0f4f44:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f4f48:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f4f4c:	240a2000 */ 	addiu	$t2,$zero,0x2000
/*  f0f4f50:	ad8a0004 */ 	sw	$t2,0x4($t4)
/*  f0f4f54:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f4f58:	27b00440 */ 	addiu	$s0,$sp,0x440
/*  f0f4f5c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0f4f60:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f4f64:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f4f68:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f4f6c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f4f70:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f4f74:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4f78:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0f4f7c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0f4f80:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f4f84:	8fad0440 */ 	lw	$t5,0x440($sp)
/*  f0f4f88:	3c0cb900 */ 	lui	$t4,0xb900
/*  f0f4f8c:	3c0f0050 */ 	lui	$t7,0x50
/*  f0f4f90:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0f4f94:	afae0440 */ 	sw	$t6,0x440($sp)
/*  f0f4f98:	35ef4240 */ 	ori	$t7,$t7,0x4240
/*  f0f4f9c:	358c031d */ 	ori	$t4,$t4,0x31d
/*  f0f4fa0:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f0f4fa4:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f0f4fa8:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f0f4fac:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f4fb0:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0f4fb4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f4fb8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f4fbc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f4fc0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4fc4:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0f4fc8:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0f4fcc:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f4fd0:	8fb90440 */ 	lw	$t9,0x440($sp)
/*  f0f4fd4:	3c0d0600 */ 	lui	$t5,0x600
/*  f0f4fd8:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f0f4fdc:	afab0440 */ 	sw	$t3,0x440($sp)
/*  f0f4fe0:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f4fe4:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f0f4fe8:	af2e0004 */ 	sw	$t6,0x4($t9)
.L0f0f4fec:
/*  f0f4fec:	8fa20440 */ 	lw	$v0,0x440($sp)
.L0f0f4ff0:
/*  f0f4ff0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f4ff4:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0f4ff8:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0f4ffc:	03e00008 */ 	jr	$ra
/*  f0f5000:	27bd0440 */ 	addiu	$sp,$sp,0x440
);

GLOBAL_ASM(
glabel func0f0f5004
/*  f0f5004:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0f5008:	3c0e7f1b */ 	lui	$t6,%hi(var7f1b25f8)
/*  f0f500c:	27a20000 */ 	addiu	$v0,$sp,0x0
/*  f0f5010:	3c03800b */ 	lui	$v1,%hi(g_MpPlayers)
/*  f0f5014:	3c078007 */ 	lui	$a3,%hi(g_MpPlayerNum)
/*  f0f5018:	25ce25f8 */ 	addiu	$t6,$t6,%lo(var7f1b25f8)
/*  f0f501c:	24e71448 */ 	addiu	$a3,$a3,%lo(g_MpPlayerNum)
/*  f0f5020:	2463c7b8 */ 	addiu	$v1,$v1,%lo(g_MpPlayers)
/*  f0f5024:	240800a0 */ 	addiu	$t0,$zero,0xa0
/*  f0f5028:	2409000c */ 	addiu	$t1,$zero,0xc
/*  f0f502c:	25d90060 */ 	addiu	$t9,$t6,0x60
/*  f0f5030:	00405025 */ 	or	$t2,$v0,$zero
.L0f0f5034:
/*  f0f5034:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0f5038:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f0f503c:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f0f5040:	ad41fff4 */ 	sw	$at,-0xc($t2)
/*  f0f5044:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f0f5048:	ad41fff8 */ 	sw	$at,-0x8($t2)
/*  f0f504c:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f0f5050:	15d9fff8 */ 	bne	$t6,$t9,.L0f0f5034
/*  f0f5054:	ad41fffc */ 	sw	$at,-0x4($t2)
/*  f0f5058:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f0f505c:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f0f5060:	01a80019 */ 	multu	$t5,$t0
/*  f0f5064:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f0f5068:	0000c012 */ 	mflo	$t8
/*  f0f506c:	00787821 */ 	addu	$t7,$v1,$t8
/*  f0f5070:	91f90011 */ 	lbu	$t9,0x11($t7)
/*  f0f5074:	03290019 */ 	multu	$t9,$t1
/*  f0f5078:	00007012 */ 	mflo	$t6
/*  f0f507c:	004e5021 */ 	addu	$t2,$v0,$t6
/*  f0f5080:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f0f5084:	018b6825 */ 	or	$t5,$t4,$t3
/*  f0f5088:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f0f508c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f0f5090:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f0f5094:	03280019 */ 	multu	$t9,$t0
/*  f0f5098:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f0f509c:	00007012 */ 	mflo	$t6
/*  f0f50a0:	006e5021 */ 	addu	$t2,$v1,$t6
/*  f0f50a4:	914c0011 */ 	lbu	$t4,0x11($t2)
/*  f0f50a8:	01890019 */ 	multu	$t4,$t1
/*  f0f50ac:	00005812 */ 	mflo	$t3
/*  f0f50b0:	004b6821 */ 	addu	$t5,$v0,$t3
/*  f0f50b4:	8db80004 */ 	lw	$t8,0x4($t5)
/*  f0f50b8:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f0f50bc:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f0f50c0:	8cec0000 */ 	lw	$t4,0x0($a3)
/*  f0f50c4:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f0f50c8:	01880019 */ 	multu	$t4,$t0
/*  f0f50cc:	31ca00ff */ 	andi	$t2,$t6,0xff
/*  f0f50d0:	00005812 */ 	mflo	$t3
/*  f0f50d4:	006b6821 */ 	addu	$t5,$v1,$t3
/*  f0f50d8:	91af0011 */ 	lbu	$t7,0x11($t5)
/*  f0f50dc:	01e90019 */ 	multu	$t7,$t1
/*  f0f50e0:	0000c012 */ 	mflo	$t8
/*  f0f50e4:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f0f50e8:	8f2e0008 */ 	lw	$t6,0x8($t9)
/*  f0f50ec:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f0f50f0:	014e6025 */ 	or	$t4,$t2,$t6
/*  f0f50f4:	03e00008 */ 	jr	$ra
/*  f0f50f8:	accc0000 */ 	sw	$t4,0x0($a2)
);

GLOBAL_ASM(
glabel func0f0f50fc
/*  f0f50fc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f5100:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f5104:	00801025 */ 	or	$v0,$a0,$zero
/*  f0f5108:	3c0ee700 */ 	lui	$t6,0xe700
/*  f0f510c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0f5110:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0f5114:	3c038008 */ 	lui	$v1,0x8008
/*  f0f5118:	3c0f800a */ 	lui	$t7,0x800a
/*  f0f511c:	8def2038 */ 	lw	$t7,0x2038($t7)
/*  f0f5120:	8c63fac0 */ 	lw	$v1,-0x540($v1)
/*  f0f5124:	3c058007 */ 	lui	$a1,%hi(var80071190)
/*  f0f5128:	24a51190 */ 	addiu	$a1,$a1,%lo(var80071190)
/*  f0f512c:	01e30019 */ 	multu	$t7,$v1
/*  f0f5130:	3c19800a */ 	lui	$t9,0x800a
/*  f0f5134:	3c068007 */ 	lui	$a2,%hi(var80071194)
/*  f0f5138:	24c61194 */ 	addiu	$a2,$a2,%lo(var80071194)
/*  f0f513c:	3c0a800a */ 	lui	$t2,0x800a
/*  f0f5140:	3c088007 */ 	lui	$t0,%hi(var80071198)
/*  f0f5144:	25081198 */ 	addiu	$t0,$t0,%lo(var80071198)
/*  f0f5148:	3c0b800a */ 	lui	$t3,0x800a
/*  f0f514c:	3c078007 */ 	lui	$a3,%hi(var8007119c)
/*  f0f5150:	24e7119c */ 	addiu	$a3,$a3,%lo(var8007119c)
/*  f0f5154:	0000c012 */ 	mflo	$t8
/*  f0f5158:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f0f515c:	8f39203c */ 	lw	$t9,0x203c($t9)
/*  f0f5160:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f5164:	03230019 */ 	multu	$t9,$v1
/*  f0f5168:	00004812 */ 	mflo	$t1
/*  f0f516c:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f0f5170:	8d4a2040 */ 	lw	$t2,0x2040($t2)
/*  f0f5174:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f0f5178:	8d6b2044 */ 	lw	$t3,0x2044($t3)
/*  f0f517c:	07010002 */ 	bgez	$t8,.L0f0f5188
/*  f0f5180:	aceb0000 */ 	sw	$t3,0x0($a3)
/*  f0f5184:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f0f5188:
/*  f0f5188:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f0f518c:	05a30003 */ 	bgezl	$t5,.L0f0f519c
/*  f0f5190:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0f5194:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f0f5198:	8d0e0000 */ 	lw	$t6,0x0($t0)
.L0f0f519c:
/*  f0f519c:	05c30003 */ 	bgezl	$t6,.L0f0f51ac
/*  f0f51a0:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f0f51a4:	ad000000 */ 	sw	$zero,0x0($t0)
/*  f0f51a8:	8cef0000 */ 	lw	$t7,0x0($a3)
.L0f0f51ac:
/*  f0f51ac:	05e10002 */ 	bgez	$t7,.L0f0f51b8
/*  f0f51b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f51b4:	ace00000 */ 	sw	$zero,0x0($a3)
.L0f0f51b8:
/*  f0f51b8:	0c002ef1 */ 	jal	func0000bbc4
/*  f0f51bc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0f51c0:	3c188007 */ 	lui	$t8,0x8007
/*  f0f51c4:	8f181190 */ 	lw	$t8,0x1190($t8)
/*  f0f51c8:	0058082a */ 	slt	$at,$v0,$t8
/*  f0f51cc:	10200005 */ 	beqz	$at,.L0f0f51e4
/*  f0f51d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f51d4:	0c002ef1 */ 	jal	func0000bbc4
/*  f0f51d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f51dc:	3c018007 */ 	lui	$at,0x8007
/*  f0f51e0:	ac221190 */ 	sw	$v0,0x1190($at)
.L0f0f51e4:
/*  f0f51e4:	0c002ef1 */ 	jal	func0000bbc4
/*  f0f51e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f51ec:	3c198007 */ 	lui	$t9,0x8007
/*  f0f51f0:	8f391194 */ 	lw	$t9,0x1194($t9)
/*  f0f51f4:	0059082a */ 	slt	$at,$v0,$t9
/*  f0f51f8:	10200005 */ 	beqz	$at,.L0f0f5210
/*  f0f51fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f5200:	0c002ef1 */ 	jal	func0000bbc4
/*  f0f5204:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f5208:	3c018007 */ 	lui	$at,0x8007
/*  f0f520c:	ac221194 */ 	sw	$v0,0x1194($at)
.L0f0f5210:
/*  f0f5210:	0c002ef5 */ 	jal	func0000bbd4
/*  f0f5214:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f5218:	3c098007 */ 	lui	$t1,0x8007
/*  f0f521c:	8d291198 */ 	lw	$t1,0x1198($t1)
/*  f0f5220:	0049082a */ 	slt	$at,$v0,$t1
/*  f0f5224:	10200005 */ 	beqz	$at,.L0f0f523c
/*  f0f5228:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f522c:	0c002ef5 */ 	jal	func0000bbd4
/*  f0f5230:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f5234:	3c018007 */ 	lui	$at,0x8007
/*  f0f5238:	ac221198 */ 	sw	$v0,0x1198($at)
.L0f0f523c:
/*  f0f523c:	0c002ef5 */ 	jal	func0000bbd4
/*  f0f5240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f5244:	3c078007 */ 	lui	$a3,%hi(var8007119c)
/*  f0f5248:	24e7119c */ 	addiu	$a3,$a3,%lo(var8007119c)
/*  f0f524c:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f0f5250:	0043082a */ 	slt	$at,$v0,$v1
/*  f0f5254:	10200009 */ 	beqz	$at,.L0f0f527c
/*  f0f5258:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f525c:	0c002ef5 */ 	jal	func0000bbd4
/*  f0f5260:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f5264:	3c018007 */ 	lui	$at,0x8007
/*  f0f5268:	ac22119c */ 	sw	$v0,0x119c($at)
/*  f0f526c:	3c038007 */ 	lui	$v1,0x8007
/*  f0f5270:	3c078007 */ 	lui	$a3,%hi(var8007119c)
/*  f0f5274:	24e7119c */ 	addiu	$a3,$a3,%lo(var8007119c)
/*  f0f5278:	8c63119c */ 	lw	$v1,0x119c($v1)
.L0f0f527c:
/*  f0f527c:	3c088007 */ 	lui	$t0,%hi(var80071194)
/*  f0f5280:	3c048007 */ 	lui	$a0,0x8007
/*  f0f5284:	8c841190 */ 	lw	$a0,0x1190($a0)
/*  f0f5288:	25081194 */ 	addiu	$t0,$t0,%lo(var80071194)
/*  f0f528c:	8d0a0000 */ 	lw	$t2,0x0($t0)
/*  f0f5290:	44842000 */ 	mtc1	$a0,$f4
/*  f0f5294:	3c058007 */ 	lui	$a1,0x8007
/*  f0f5298:	0144082a */ 	slt	$at,$t2,$a0
/*  f0f529c:	10200002 */ 	beqz	$at,.L0f0f52a8
/*  f0f52a0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f52a4:	ad040000 */ 	sw	$a0,0x0($t0)
.L0f0f52a8:
/*  f0f52a8:	8ca51198 */ 	lw	$a1,0x1198($a1)
/*  f0f52ac:	0065082a */ 	slt	$at,$v1,$a1
/*  f0f52b0:	50200003 */ 	beqzl	$at,.L0f0f52c0
/*  f0f52b4:	44858000 */ 	mtc1	$a1,$f16
/*  f0f52b8:	ace50000 */ 	sw	$a1,0x0($a3)
/*  f0f52bc:	44858000 */ 	mtc1	$a1,$f16
.L0f0f52c0:
/*  f0f52c0:	3c014080 */ 	lui	$at,0x4080
/*  f0f52c4:	44810000 */ 	mtc1	$at,$f0
/*  f0f52c8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0f52cc:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f0f52d0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0f52d4:	3c01ed00 */ 	lui	$at,0xed00
/*  f0f52d8:	24620008 */ 	addiu	$v0,$v1,0x8
/*  f0f52dc:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0f52e0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0f52e4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0f52e8:	440c5000 */ 	mfc1	$t4,$f10
/*  f0f52ec:	44193000 */ 	mfc1	$t9,$f6
/*  f0f52f0:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f0f52f4:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f0f52f8:	01c17825 */ 	or	$t7,$t6,$at
/*  f0f52fc:	33290fff */ 	andi	$t1,$t9,0xfff
/*  f0f5300:	01e95025 */ 	or	$t2,$t7,$t1
/*  f0f5304:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0f5308:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*  f0f530c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f0f5310:	448b4000 */ 	mtc1	$t3,$f8
/*  f0f5314:	44992000 */ 	mtc1	$t9,$f4
/*  f0f5318:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0f531c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f5320:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0f5324:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f5328:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0f532c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0f5330:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0f5334:	440d9000 */ 	mfc1	$t5,$f18
/*  f0f5338:	44095000 */ 	mfc1	$t1,$f10
/*  f0f533c:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f0f5340:	000ec300 */ 	sll	$t8,$t6,0xc
/*  f0f5344:	312a0fff */ 	andi	$t2,$t1,0xfff
/*  f0f5348:	030a5825 */ 	or	$t3,$t8,$t2
/*  f0f534c:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f0f5350:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f5354:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f5358:	03e00008 */ 	jr	$ra
/*  f0f535c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f5360
/*  f0f5360:	27bdfe18 */ 	addiu	$sp,$sp,-488
/*  f0f5364:	afbe0060 */ 	sw	$s8,0x60($sp)
/*  f0f5368:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f0f536c:	afb7005c */ 	sw	$s7,0x5c($sp)
/*  f0f5370:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f0f5374:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f0f5378:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f0f537c:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f0f5380:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f0f5384:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f0f5388:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f0f538c:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f0f5390:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f5394:	afa601f0 */ 	sw	$a2,0x1f0($sp)
/*  f0f5398:	afa701f4 */ 	sw	$a3,0x1f4($sp)
/*  f0f539c:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f0f53a0:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f0f53a4:	8fd80298 */ 	lw	$t8,0x298($s8)
/*  f0f53a8:	8cb50014 */ 	lw	$s5,0x14($a1)
/*  f0f53ac:	8cb30018 */ 	lw	$s3,0x18($a1)
/*  f0f53b0:	8cae001c */ 	lw	$t6,0x1c($a1)
/*  f0f53b4:	8caf0020 */ 	lw	$t7,0x20($a1)
/*  f0f53b8:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0f53bc:	02aeb021 */ 	addu	$s6,$s5,$t6
/*  f0f53c0:	07010005 */ 	bgez	$t8,.L0f0f53d8
/*  f0f53c4:	026fa021 */ 	addu	$s4,$s3,$t7
/*  f0f53c8:	8fd9029c */ 	lw	$t9,0x29c($s8)
/*  f0f53cc:	afa501ec */ 	sw	$a1,0x1ec($sp)
/*  f0f53d0:	0722000c */ 	bltzl	$t9,.L0f0f5404
/*  f0f53d4:	8fb001ec */ 	lw	$s0,0x1ec($sp)
.L0f0f53d8:
/*  f0f53d8:	0fc3f303 */ 	jal	func0f0fcc0c
/*  f0f53dc:	afb001ec */ 	sw	$s0,0x1ec($sp)
/*  f0f53e0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f53e4:	14410006 */ 	bne	$v0,$at,.L0f0f5400
/*  f0f53e8:	3c0b800a */ 	lui	$t3,0x800a
/*  f0f53ec:	8d6bdfc0 */ 	lw	$t3,-0x2040($t3)
/*  f0f53f0:	55600004 */ 	bnezl	$t3,.L0f0f5404
/*  f0f53f4:	8fb001ec */ 	lw	$s0,0x1ec($sp)
/*  f0f53f8:	1000081e */ 	beqz	$zero,.L0f0f7474
/*  f0f53fc:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f5400:
/*  f0f5400:	8fb001ec */ 	lw	$s0,0x1ec($sp)
.L0f0f5404:
/*  f0f5404:	4480a000 */ 	mtc1	$zero,$f20
/*  f0f5408:	3c197f1b */ 	lui	$t9,0x7f1b
/*  f0f540c:	c6040040 */ 	lwc1	$f4,0x40($s0)
/*  f0f5410:	27391fb0 */ 	addiu	$t9,$t9,0x1fb0
/*  f0f5414:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0f5418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f541c:	4502000c */ 	bc1fl	.L0f0f5450
/*  f0f5420:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f0f5424:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0f5428:	3c0e7f1b */ 	lui	$t6,0x7f1b
/*  f0f542c:	afb001ec */ 	sw	$s0,0x1ec($sp)
/*  f0f5430:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0f5434:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f5438:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f543c:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0f5440:	8dce1fd8 */ 	lw	$t6,0x1fd8($t6)
/*  f0f5444:	10000011 */ 	beqz	$zero,.L0f0f548c
/*  f0f5448:	afae01bc */ 	sw	$t6,0x1bc($sp)
/*  f0f544c:	920f003d */ 	lbu	$t7,0x3d($s0)
.L0f0f5450:
/*  f0f5450:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0f5454:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0f5458:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0f545c:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0f5460:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f5464:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f5468:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f546c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f5470:	03195821 */ 	addu	$t3,$t8,$t9
/*  f0f5474:	01b97021 */ 	addu	$t6,$t5,$t9
/*  f0f5478:	8dc50028 */ 	lw	$a1,0x28($t6)
/*  f0f547c:	8d640028 */ 	lw	$a0,0x28($t3)
/*  f0f5480:	0fc01a40 */ 	jal	func0f006900
/*  f0f5484:	afb001ec */ 	sw	$s0,0x1ec($sp)
/*  f0f5488:	afa201bc */ 	sw	$v0,0x1bc($sp)
.L0f0f548c:
/*  f0f548c:	0fc5580c */ 	jal	func0f156030
/*  f0f5490:	8fa401bc */ 	lw	$a0,0x1bc($sp)
/*  f0f5494:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0f5498:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f0f549c:	3c0b800a */ 	lui	$t3,%hi(var8009e000)
/*  f0f54a0:	3c018008 */ 	lui	$at,0x8008
/*  f0f54a4:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f54a8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f54ac:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f54b0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f54b4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f54b8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f54bc:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f54c0:	256be000 */ 	addiu	$t3,$t3,%lo(var8009e000)
/*  f0f54c4:	ac20fb9c */ 	sw	$zero,-0x464($at)
/*  f0f54c8:	030b1821 */ 	addu	$v1,$t8,$t3
/*  f0f54cc:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f54d0:	8c6c04f8 */ 	lw	$t4,0x4f8($v1)
/*  f0f54d4:	54ec002d */ 	bnel	$a3,$t4,.L0f0f558c
/*  f0f54d8:	8cf8001c */ 	lw	$t8,0x1c($a3)
/*  f0f54dc:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f0f54e0:	8faf01f4 */ 	lw	$t7,0x1f4($sp)
/*  f0f54e4:	8db90010 */ 	lw	$t9,0x10($t5)
/*  f0f54e8:	332e0002 */ 	andi	$t6,$t9,0x2
/*  f0f54ec:	51c00027 */ 	beqzl	$t6,.L0f0f558c
/*  f0f54f0:	8cf8001c */ 	lw	$t8,0x1c($a3)
/*  f0f54f4:	55e00025 */ 	bnezl	$t7,.L0f0f558c
/*  f0f54f8:	8cf8001c */ 	lw	$t8,0x1c($a3)
/*  f0f54fc:	8c780df0 */ 	lw	$t8,0xdf0($v1)
/*  f0f5500:	8fad01e8 */ 	lw	$t5,0x1e8($sp)
/*  f0f5504:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f5508:	00185b80 */ 	sll	$t3,$t8,0xe
/*  f0f550c:	000b67c2 */ 	srl	$t4,$t3,0x1f
/*  f0f5510:	1581001d */ 	bne	$t4,$at,.L0f0f5588
/*  f0f5514:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f0f5518:	afb901e8 */ 	sw	$t9,0x1e8($sp)
/*  f0f551c:	3c0eb700 */ 	lui	$t6,0xb700
/*  f0f5520:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f5524:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f0f5528:	adae0000 */ 	sw	$t6,0x0($t5)
/*  f0f552c:	3c188007 */ 	lui	$t8,0x8007
/*  f0f5530:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f0f5534:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f0f5538:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f0f553c:	001858c0 */ 	sll	$t3,$t8,0x3
/*  f0f5540:	01785823 */ 	subu	$t3,$t3,$t8
/*  f0f5544:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f5548:	01785821 */ 	addu	$t3,$t3,$t8
/*  f0f554c:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0f5550:	01785823 */ 	subu	$t3,$t3,$t8
/*  f0f5554:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f0f5558:	256c0840 */ 	addiu	$t4,$t3,0x840
/*  f0f555c:	018d2821 */ 	addu	$a1,$t4,$t5
/*  f0f5560:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5564:	0fc3ce2c */ 	jal	func0f0f38b0
/*  f0f5568:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0f556c:	24590008 */ 	addiu	$t9,$v0,0x8
/*  f0f5570:	afb901e8 */ 	sw	$t9,0x1e8($sp)
/*  f0f5574:	3c0eb600 */ 	lui	$t6,0xb600
/*  f0f5578:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f557c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0f5580:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0f5584:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.L0f0f5588:
/*  f0f5588:	8cf8001c */ 	lw	$t8,0x1c($a3)
.L0f0f558c:
/*  f0f558c:	3c0c8008 */ 	lui	$t4,%hi(g_MpReadyMenuDialog)
/*  f0f5590:	258c57b8 */ 	addiu	$t4,$t4,%lo(g_MpReadyMenuDialog)
/*  f0f5594:	a7b801ca */ 	sh	$t8,0x1ca($sp)
/*  f0f5598:	90eb0060 */ 	lbu	$t3,0x60($a3)
/*  f0f559c:	84f00022 */ 	lh	$s0,0x22($a3)
/*  f0f55a0:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f0f55a4:	55600029 */ 	bnezl	$t3,.L0f0f564c
/*  f0f55a8:	8ced0014 */ 	lw	$t5,0x14($a3)
/*  f0f55ac:	15840003 */ 	bne	$t4,$a0,.L0f0f55bc
/*  f0f55b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f55b4:	100007af */ 	beqz	$zero,.L0f0f7474
/*  f0f55b8:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f55bc:
/*  f0f55bc:	44813000 */ 	mtc1	$at,$f6
/*  f0f55c0:	8fcd0298 */ 	lw	$t5,0x298($s8)
/*  f0f55c4:	3c01800a */ 	lui	$at,0x800a
/*  f0f55c8:	c42819d0 */ 	lwc1	$f8,0x19d0($at)
/*  f0f55cc:	05a10004 */ 	bgez	$t5,.L0f0f55e0
/*  f0f55d0:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f0f55d4:	8fd9029c */ 	lw	$t9,0x29c($s8)
/*  f0f55d8:	0720000b */ 	bltz	$t9,.L0f0f5608
/*  f0f55dc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f55e0:
/*  f0f55e0:	0fc3f303 */ 	jal	func0f0fcc0c
/*  f0f55e4:	e7a00170 */ 	swc1	$f0,0x170($sp)
/*  f0f55e8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f55ec:	14410006 */ 	bne	$v0,$at,.L0f0f5608
/*  f0f55f0:	c7a00170 */ 	lwc1	$f0,0x170($sp)
/*  f0f55f4:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f55f8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f55fc:	44815000 */ 	mtc1	$at,$f10
/*  f0f5600:	c5d00050 */ 	lwc1	$f16,0x50($t6)
/*  f0f5604:	46105001 */ 	sub.s	$f0,$f10,$f16
.L0f0f5608:
/*  f0f5608:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0f560c:	44903000 */ 	mtc1	$s0,$f6
/*  f0f5610:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f5614:	44819000 */ 	mtc1	$at,$f18
/*  f0f5618:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f561c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f5620:	8cec0018 */ 	lw	$t4,0x18($a3)
/*  f0f5624:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f0f5628:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f0f562c:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0f5630:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0f5634:	44108000 */ 	mfc1	$s0,$f16
/*  f0f5638:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f563c:	0010c400 */ 	sll	$t8,$s0,0x10
/*  f0f5640:	00188403 */ 	sra	$s0,$t8,0x10
/*  f0f5644:	0190a021 */ 	addu	$s4,$t4,$s0
/*  f0f5648:	8ced0014 */ 	lw	$t5,0x14($a3)
.L0f0f564c:
/*  f0f564c:	afad01e0 */ 	sw	$t5,0x1e0($sp)
/*  f0f5650:	8ce20018 */ 	lw	$v0,0x18($a3)
/*  f0f5654:	02021821 */ 	addu	$v1,$s0,$v0
/*  f0f5658:	afa301d4 */ 	sw	$v1,0x1d4($sp)
/*  f0f565c:	afa30084 */ 	sw	$v1,0x84($sp)
/*  f0f5660:	0fc3c560 */ 	jal	func0f0f1580
/*  f0f5664:	afa201dc */ 	sw	$v0,0x1dc($sp)
/*  f0f5668:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f566c:	0040b825 */ 	or	$s7,$v0,$zero
/*  f0f5670:	c4f20040 */ 	lwc1	$f18,0x40($a3)
/*  f0f5674:	4614903c */ 	c.lt.s	$f18,$f20
/*  f0f5678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f567c:	4502000c */ 	bc1fl	.L0f0f56b0
/*  f0f5680:	90eb003d */ 	lbu	$t3,0x3d($a3)
/*  f0f5684:	90f9003c */ 	lbu	$t9,0x3c($a3)
/*  f0f5688:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f568c:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f5690:	03280019 */ 	multu	$t9,$t0
/*  f0f5694:	25291fb0 */ 	addiu	$t1,$t1,0x1fb0
/*  f0f5698:	00007012 */ 	mflo	$t6
/*  f0f569c:	012e7821 */ 	addu	$t7,$t1,$t6
/*  f0f56a0:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0f56a4:	10000016 */ 	beqz	$zero,.L0f0f5700
/*  f0f56a8:	afb801bc */ 	sw	$t8,0x1bc($sp)
/*  f0f56ac:	90eb003d */ 	lbu	$t3,0x3d($a3)
.L0f0f56b0:
/*  f0f56b0:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0f56b4:	3c0d7f1b */ 	lui	$t5,0x7f1b
/*  f0f56b8:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f0f56bc:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f0f56c0:	25ad1fb0 */ 	addiu	$t5,$t5,0x1fb0
/*  f0f56c4:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0f56c8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f56cc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f56d0:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f56d4:	018dc821 */ 	addu	$t9,$t4,$t5
/*  f0f56d8:	01edc021 */ 	addu	$t8,$t7,$t5
/*  f0f56dc:	8f050000 */ 	lw	$a1,0x0($t8)
/*  f0f56e0:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f0f56e4:	0fc01a40 */ 	jal	func0f006900
/*  f0f56e8:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f56ec:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f56f0:	25291fb0 */ 	addiu	$t1,$t1,0x1fb0
/*  f0f56f4:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f0f56f8:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f56fc:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.L0f0f5700:
/*  f0f5700:	c4e40040 */ 	lwc1	$f4,0x40($a3)
/*  f0f5704:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0f5708:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f570c:	45020009 */ 	bc1fl	.L0f0f5734
/*  f0f5710:	90ef003d */ 	lbu	$t7,0x3d($a3)
/*  f0f5714:	90eb003c */ 	lbu	$t3,0x3c($a3)
/*  f0f5718:	01680019 */ 	multu	$t3,$t0
/*  f0f571c:	00006012 */ 	mflo	$t4
/*  f0f5720:	012cc821 */ 	addu	$t9,$t1,$t4
/*  f0f5724:	8f2e0004 */ 	lw	$t6,0x4($t9)
/*  f0f5728:	10000012 */ 	beqz	$zero,.L0f0f5774
/*  f0f572c:	afae01b8 */ 	sw	$t6,0x1b8($sp)
/*  f0f5730:	90ef003d */ 	lbu	$t7,0x3d($a3)
.L0f0f5734:
/*  f0f5734:	90eb003c */ 	lbu	$t3,0x3c($a3)
/*  f0f5738:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f573c:	01e80019 */ 	multu	$t7,$t0
/*  f0f5740:	00006812 */ 	mflo	$t5
/*  f0f5744:	012dc021 */ 	addu	$t8,$t1,$t5
/*  f0f5748:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f0f574c:	01680019 */ 	multu	$t3,$t0
/*  f0f5750:	00006012 */ 	mflo	$t4
/*  f0f5754:	012cc821 */ 	addu	$t9,$t1,$t4
/*  f0f5758:	0fc01a40 */ 	jal	func0f006900
/*  f0f575c:	8f250004 */ 	lw	$a1,0x4($t9)
/*  f0f5760:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f5764:	25291fb0 */ 	addiu	$t1,$t1,0x1fb0
/*  f0f5768:	afa201b8 */ 	sw	$v0,0x1b8($sp)
/*  f0f576c:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f5770:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.L0f0f5774:
/*  f0f5774:	c4e60040 */ 	lwc1	$f6,0x40($a3)
/*  f0f5778:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0f577c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f5780:	45020009 */ 	bc1fl	.L0f0f57a8
/*  f0f5784:	90eb003d */ 	lbu	$t3,0x3d($a3)
/*  f0f5788:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0f578c:	01c80019 */ 	multu	$t6,$t0
/*  f0f5790:	00007812 */ 	mflo	$t7
/*  f0f5794:	012f6821 */ 	addu	$t5,$t1,$t7
/*  f0f5798:	8db80008 */ 	lw	$t8,0x8($t5)
/*  f0f579c:	1000000f */ 	beqz	$zero,.L0f0f57dc
/*  f0f57a0:	afb801b4 */ 	sw	$t8,0x1b4($sp)
/*  f0f57a4:	90eb003d */ 	lbu	$t3,0x3d($a3)
.L0f0f57a8:
/*  f0f57a8:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0f57ac:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f57b0:	01680019 */ 	multu	$t3,$t0
/*  f0f57b4:	00006012 */ 	mflo	$t4
/*  f0f57b8:	012cc821 */ 	addu	$t9,$t1,$t4
/*  f0f57bc:	8f240008 */ 	lw	$a0,0x8($t9)
/*  f0f57c0:	01c80019 */ 	multu	$t6,$t0
/*  f0f57c4:	00007812 */ 	mflo	$t7
/*  f0f57c8:	012f6821 */ 	addu	$t5,$t1,$t7
/*  f0f57cc:	0fc01a40 */ 	jal	func0f006900
/*  f0f57d0:	8da50008 */ 	lw	$a1,0x8($t5)
/*  f0f57d4:	afa201b4 */ 	sw	$v0,0x1b4($sp)
/*  f0f57d8:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.L0f0f57dc:
/*  f0f57dc:	8fb801e8 */ 	lw	$t8,0x1e8($sp)
/*  f0f57e0:	3c0cb600 */ 	lui	$t4,0xb600
/*  f0f57e4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f57e8:	270b0008 */ 	addiu	$t3,$t8,0x8
/*  f0f57ec:	afab01e8 */ 	sw	$t3,0x1e8($sp)
/*  f0f57f0:	af190004 */ 	sw	$t9,0x4($t8)
/*  f0f57f4:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f0f57f8:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f0f57fc:	8fb201b4 */ 	lw	$s2,0x1b4($sp)
/*  f0f5800:	8fb801b4 */ 	lw	$t8,0x1b4($sp)
/*  f0f5804:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0f5808:	2de10040 */ 	sltiu	$at,$t7,0x40
/*  f0f580c:	14200005 */ 	bnez	$at,.L0f0f5824
/*  f0f5810:	01c08825 */ 	or	$s1,$t6,$zero
/*  f0f5814:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f5818:	01c18824 */ 	and	$s1,$t6,$at
/*  f0f581c:	362d003f */ 	ori	$t5,$s1,0x3f
/*  f0f5820:	01a08825 */ 	or	$s1,$t5,$zero
.L0f0f5824:
/*  f0f5824:	330b00ff */ 	andi	$t3,$t8,0xff
/*  f0f5828:	2d610040 */ 	sltiu	$at,$t3,0x40
/*  f0f582c:	14200005 */ 	bnez	$at,.L0f0f5844
/*  f0f5830:	2419fc18 */ 	addiu	$t9,$zero,-1000
/*  f0f5834:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f5838:	03019024 */ 	and	$s2,$t8,$at
/*  f0f583c:	364c003f */ 	ori	$t4,$s2,0x3f
/*  f0f5840:	01809025 */ 	or	$s2,$t4,$zero
.L0f0f5844:
/*  f0f5844:	3c01800a */ 	lui	$at,0x800a
/*  f0f5848:	ac39de90 */ 	sw	$t9,-0x2170($at)
/*  f0f584c:	3c01800a */ 	lui	$at,0x800a
/*  f0f5850:	240f03e8 */ 	addiu	$t7,$zero,0x3e8
/*  f0f5854:	ac2fde94 */ 	sw	$t7,-0x216c($at)
/*  f0f5858:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0f585c:	3c03800a */ 	lui	$v1,0x800a
/*  f0f5860:	8dc40010 */ 	lw	$a0,0x10($t6)
/*  f0f5864:	308d0100 */ 	andi	$t5,$a0,0x100
/*  f0f5868:	11a00002 */ 	beqz	$t5,.L0f0f5874
/*  f0f586c:	01a02025 */ 	or	$a0,$t5,$zero
/*  f0f5870:	2673000b */ 	addiu	$s3,$s3,0xb
.L0f0f5874:
/*  f0f5874:	8c6319c4 */ 	lw	$v1,0x19c4($v1)
/*  f0f5878:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f587c:	10610060 */ 	beq	$v1,$at,.L0f0f5a00
/*  f0f5880:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f5884:	14610004 */ 	bne	$v1,$at,.L0f0f5898
/*  f0f5888:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f588c:	8fcb0318 */ 	lw	$t3,0x318($s8)
/*  f0f5890:	1160005b */ 	beqz	$t3,.L0f0f5a00
/*  f0f5894:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f5898:
/*  f0f5898:	3c10800a */ 	lui	$s0,%hi(var800a4634)
/*  f0f589c:	26104634 */ 	addiu	$s0,$s0,%lo(var800a4634)
/*  f0f58a0:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f0f58a4:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f58a8:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f58ac:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f58b0:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f58b4:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f58b8:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f58bc:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f58c0:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f58c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f58c8:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f58cc:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f58d0:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f58d4:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f58d8:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f58dc:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f58e0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f58e4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f58e8:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f58ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f58f0:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f58f4:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f58f8:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f58fc:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f5900:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f5904:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f5908:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f590c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f5910:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f5914:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5918:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f591c:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f5920:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f5924:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f5928:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f592c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f5930:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f5934:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f5938:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f593c:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f5940:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0f5944:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5948:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f594c:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f5950:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f5954:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f5958:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f595c:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f5960:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f5964:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f5968:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f596c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0f5970:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5974:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f5978:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f597c:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f5980:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f5984:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f5988:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f598c:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f5990:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f5994:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f5998:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f599c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f59a0:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f59a4:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f59a8:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f59ac:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f59b0:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f59b4:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f59b8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f59bc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f59c0:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f59c4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f59c8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f59cc:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f59d0:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f59d4:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f59d8:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f59dc:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f59e0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f59e4:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f59e8:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f59ec:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f59f0:	8dcd0000 */ 	lw	$t5,0x0($t6)
/*  f0f59f4:	8da40010 */ 	lw	$a0,0x10($t5)
/*  f0f59f8:	308b0100 */ 	andi	$t3,$a0,0x100
/*  f0f59fc:	01602025 */ 	or	$a0,$t3,$zero
.L0f0f5a00:
/*  f0f5a00:	148000e3 */ 	bnez	$a0,.L0f0f5d90
/*  f0f5a04:	3c03800a */ 	lui	$v1,0x800a
/*  f0f5a08:	8c6319c4 */ 	lw	$v1,0x19c4($v1)
/*  f0f5a0c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f5a10:	10610002 */ 	beq	$v1,$at,.L0f0f5a1c
/*  f0f5a14:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0f5a18:	1461000c */ 	bne	$v1,$at,.L0f0f5a4c
.L0f0f5a1c:
/*  f0f5a1c:	3c18800b */ 	lui	$t8,0x800b
/*  f0f5a20:	8f18cb94 */ 	lw	$t8,-0x346c($t8)
/*  f0f5a24:	330c0002 */ 	andi	$t4,$t8,0x2
/*  f0f5a28:	51800009 */ 	beqzl	$t4,.L0f0f5a50
/*  f0f5a2c:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f5a30:	8fd90490 */ 	lw	$t9,0x490($s8)
/*  f0f5a34:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f5a38:	27a401bc */ 	addiu	$a0,$sp,0x1bc
/*  f0f5a3c:	13210003 */ 	beq	$t9,$at,.L0f0f5a4c
/*  f0f5a40:	27a501b8 */ 	addiu	$a1,$sp,0x1b8
/*  f0f5a44:	0fc3d401 */ 	jal	func0f0f5004
/*  f0f5a48:	27a601b4 */ 	addiu	$a2,$sp,0x1b4
.L0f0f5a4c:
/*  f0f5a4c:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
.L0f0f5a50:
/*  f0f5a50:	87af01ca */ 	lh	$t7,0x1ca($sp)
/*  f0f5a54:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f5a58:	8fad01bc */ 	lw	$t5,0x1bc($sp)
/*  f0f5a5c:	8fab01b8 */ 	lw	$t3,0x1b8($sp)
/*  f0f5a60:	8fae01b4 */ 	lw	$t6,0x1b4($sp)
/*  f0f5a64:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f0f5a68:	24510002 */ 	addiu	$s1,$v0,0x2
/*  f0f5a6c:	2470fffe */ 	addiu	$s0,$v1,-2
/*  f0f5a70:	24d5000b */ 	addiu	$s5,$a2,0xb
/*  f0f5a74:	afb50010 */ 	sw	$s5,0x10($sp)
/*  f0f5a78:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f5a7c:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f5a80:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0f5a84:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5a88:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0f5a8c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f5a90:	0fc3873a */ 	jal	func0f0e1ce8
/*  f0f5a94:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0f5a98:	8fac01bc */ 	lw	$t4,0x1bc($sp)
/*  f0f5a9c:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f5aa0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0f5aa4:	319900ff */ 	andi	$t9,$t4,0xff
/*  f0f5aa8:	00197842 */ 	srl	$t7,$t9,0x1
/*  f0f5aac:	240b0028 */ 	addiu	$t3,$zero,0x28
/*  f0f5ab0:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0f5ab4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f5ab8:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0f5abc:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0f5ac0:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f5ac4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5ac8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f5acc:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f5ad0:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0f5ad4:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0f5ad8:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f0f5adc:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f5ae0:	24190028 */ 	addiu	$t9,$zero,0x28
/*  f0f5ae4:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f0f5ae8:	00186042 */ 	srl	$t4,$t8,0x1
/*  f0f5aec:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f5af0:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0f5af4:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f5af8:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f5afc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5b00:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f5b04:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f5b08:	afb50010 */ 	sw	$s5,0x10($sp)
/*  f0f5b0c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f5b10:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0f5b14:	24c6000a */ 	addiu	$a2,$a2,0xa
/*  f0f5b18:	8fb201e0 */ 	lw	$s2,0x1e0($sp)
/*  f0f5b1c:	8fb001dc */ 	lw	$s0,0x1dc($sp)
/*  f0f5b20:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5b24:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f0f5b28:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f0f5b2c:	afb001cc */ 	sw	$s0,0x1cc($sp)
/*  f0f5b30:	0fc54d8a */ 	jal	func0f153628
/*  f0f5b34:	afb201d0 */ 	sw	$s2,0x1d0($sp)
/*  f0f5b38:	8fad01f4 */ 	lw	$t5,0x1f4($sp)
/*  f0f5b3c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f5b40:	afa001b0 */ 	sw	$zero,0x1b0($sp)
/*  f0f5b44:	11a00003 */ 	beqz	$t5,.L0f0f5b54
/*  f0f5b48:	3c0e8007 */ 	lui	$t6,%hi(var800714c8)
/*  f0f5b4c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f5b50:	afab01b0 */ 	sw	$t3,0x1b0($sp)
.L0f0f5b54:
/*  f0f5b54:	25ce14c8 */ 	addiu	$t6,$t6,%lo(var800714c8)
/*  f0f5b58:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0f5b5c:	8fa301ec */ 	lw	$v1,0x1ec($sp)
/*  f0f5b60:	27b40154 */ 	addiu	$s4,$sp,0x154
/*  f0f5b64:	ae810000 */ 	sw	$at,0x0($s4)
/*  f0f5b68:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f0f5b6c:	ae990004 */ 	sw	$t9,0x4($s4)
/*  f0f5b70:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0f5b74:	ae810008 */ 	sw	$at,0x8($s4)
/*  f0f5b78:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f0f5b7c:	3c0e7f1b */ 	lui	$t6,0x7f1b
/*  f0f5b80:	25ce1fb0 */ 	addiu	$t6,$t6,0x1fb0
/*  f0f5b84:	ae99000c */ 	sw	$t9,0xc($s4)
/*  f0f5b88:	c4680040 */ 	lwc1	$f8,0x40($v1)
/*  f0f5b8c:	4614403c */ 	c.lt.s	$f8,$f20
/*  f0f5b90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f5b94:	4502000b */ 	bc1fl	.L0f0f5bc4
/*  f0f5b98:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0f5b9c:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0f5ba0:	3c0b7f1b */ 	lui	$t3,0x7f1b
/*  f0f5ba4:	000f6900 */ 	sll	$t5,$t7,0x4
/*  f0f5ba8:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f0f5bac:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f5bb0:	016d5821 */ 	addu	$t3,$t3,$t5
/*  f0f5bb4:	8d6b1fbc */ 	lw	$t3,0x1fbc($t3)
/*  f0f5bb8:	10000011 */ 	beqz	$zero,.L0f0f5c00
/*  f0f5bbc:	afab01bc */ 	sw	$t3,0x1bc($sp)
/*  f0f5bc0:	906c003d */ 	lbu	$t4,0x3d($v1)
.L0f0f5bc4:
/*  f0f5bc4:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0f5bc8:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0f5bcc:	000cc100 */ 	sll	$t8,$t4,0x4
/*  f0f5bd0:	000f6900 */ 	sll	$t5,$t7,0x4
/*  f0f5bd4:	030cc023 */ 	subu	$t8,$t8,$t4
/*  f0f5bd8:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f0f5bdc:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f5be0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f5be4:	030ec821 */ 	addu	$t9,$t8,$t6
/*  f0f5be8:	01ae5821 */ 	addu	$t3,$t5,$t6
/*  f0f5bec:	8d65000c */ 	lw	$a1,0xc($t3)
/*  f0f5bf0:	0fc01a40 */ 	jal	func0f006900
/*  f0f5bf4:	8f24000c */ 	lw	$a0,0xc($t9)
/*  f0f5bf8:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f0f5bfc:	8fa301ec */ 	lw	$v1,0x1ec($sp)
.L0f0f5c00:
/*  f0f5c00:	9062003c */ 	lbu	$v0,0x3c($v1)
/*  f0f5c04:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0f5c08:	3c057f1b */ 	lui	$a1,%hi(var7f1b2124)
/*  f0f5c0c:	00026100 */ 	sll	$t4,$v0,0x4
/*  f0f5c10:	01826023 */ 	subu	$t4,$t4,$v0
/*  f0f5c14:	000c1080 */ 	sll	$v0,$t4,0x2
/*  f0f5c18:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0f5c1c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0f5c20:	8ca52124 */ 	lw	$a1,%lo(var7f1b2124)($a1)
/*  f0f5c24:	0fc54f8e */ 	jal	func0f153e38
/*  f0f5c28:	8c84228c */ 	lw	$a0,0x228c($a0)
/*  f0f5c2c:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f5c30:	8fa501dc */ 	lw	$a1,0x1dc($sp)
/*  f0f5c34:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0f5c38:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0f5c3c:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f0f5c40:	0c002f06 */ 	jal	func0000bc18
/*  f0f5c44:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f5c48:	8faf01bc */ 	lw	$t7,0x1bc($sp)
/*  f0f5c4c:	3c118008 */ 	lui	$s1,%hi(var8007fb10)
/*  f0f5c50:	3c138008 */ 	lui	$s3,%hi(var8007fb0c)
/*  f0f5c54:	2673fb0c */ 	addiu	$s3,$s3,%lo(var8007fb0c)
/*  f0f5c58:	2631fb10 */ 	addiu	$s1,$s1,%lo(var8007fb10)
/*  f0f5c5c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0f5c60:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0f5c64:	87ae01ca */ 	lh	$t6,0x1ca($sp)
/*  f0f5c68:	31ed00ff */ 	andi	$t5,$t7,0xff
/*  f0f5c6c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f5c70:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5c74:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f0f5c78:	27a601cc */ 	addiu	$a2,$sp,0x1cc
/*  f0f5c7c:	02e03825 */ 	or	$a3,$s7,$zero
/*  f0f5c80:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f5c84:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f5c88:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f5c8c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f5c90:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f5c94:	0fc5580f */ 	jal	func0f15603c
/*  f0f5c98:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0f5c9c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f5ca0:	afb201d0 */ 	sw	$s2,0x1d0($sp)
/*  f0f5ca4:	0c002f06 */ 	jal	func0000bc18
/*  f0f5ca8:	afb001cc */ 	sw	$s0,0x1cc($sp)
/*  f0f5cac:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f0f5cb0:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f0f5cb4:	8fb801bc */ 	lw	$t8,0x1bc($sp)
/*  f0f5cb8:	87b901ca */ 	lh	$t9,0x1ca($sp)
/*  f0f5cbc:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5cc0:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f0f5cc4:	27a601cc */ 	addiu	$a2,$sp,0x1cc
/*  f0f5cc8:	02e03825 */ 	or	$a3,$s7,$zero
/*  f0f5ccc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f5cd0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f5cd4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f5cd8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f5cdc:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f5ce0:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f5ce4:	0fc5580f */ 	jal	func0f15603c
/*  f0f5ce8:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f5cec:	3c03800a */ 	lui	$v1,0x800a
/*  f0f5cf0:	8c6319c4 */ 	lw	$v1,0x19c4($v1)
/*  f0f5cf4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f5cf8:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f5cfc:	10610007 */ 	beq	$v1,$at,.L0f0f5d1c
/*  f0f5d00:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f5d04:	10610005 */ 	beq	$v1,$at,.L0f0f5d1c
/*  f0f5d08:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f5d0c:	10610003 */ 	beq	$v1,$at,.L0f0f5d1c
/*  f0f5d10:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0f5d14:	1461001b */ 	bne	$v1,$at,.L0f0f5d84
/*  f0f5d18:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f5d1c:
/*  f0f5d1c:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f0f5d20:	afb001cc */ 	sw	$s0,0x1cc($sp)
/*  f0f5d24:	2463fff7 */ 	addiu	$v1,$v1,-9
/*  f0f5d28:	0c002f06 */ 	jal	func0000bc18
/*  f0f5d2c:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f5d30:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0f5d34:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f0f5d38:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f0f5d3c:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f0f5d40:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f0f5d44:	028d7021 */ 	addu	$t6,$s4,$t5
/*  f0f5d48:	8dc70000 */ 	lw	$a3,0x0($t6)
/*  f0f5d4c:	8fb801bc */ 	lw	$t8,0x1bc($sp)
/*  f0f5d50:	87b901ca */ 	lh	$t9,0x1ca($sp)
/*  f0f5d54:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f5d58:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f5d5c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f5d60:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5d64:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f0f5d68:	27a601cc */ 	addiu	$a2,$sp,0x1cc
/*  f0f5d6c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f5d70:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f5d74:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f5d78:	0fc5580f */ 	jal	func0f15603c
/*  f0f5d7c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f5d80:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f5d84:
/*  f0f5d84:	0fc54de0 */ 	jal	func0f153780
/*  f0f5d88:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5d8c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f5d90:
/*  f0f5d90:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f5d94:	8fb501dc */ 	lw	$s5,0x1dc($sp)
/*  f0f5d98:	3c0f800a */ 	lui	$t7,0x800a
/*  f0f5d9c:	c4400048 */ 	lwc1	$f0,0x48($v0)
/*  f0f5da0:	26b5000b */ 	addiu	$s5,$s5,0xb
/*  f0f5da4:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f5da8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f5dac:	4503001b */ 	bc1tl	.L0f0f5e1c
/*  f0f5db0:	904b0060 */ 	lbu	$t3,0x60($v0)
/*  f0f5db4:	8def19c4 */ 	lw	$t7,0x19c4($t7)
/*  f0f5db8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f5dbc:	51e1001e */ 	beql	$t7,$at,.L0f0f5e38
/*  f0f5dc0:	8fac0084 */ 	lw	$t4,0x84($sp)
/*  f0f5dc4:	904d0060 */ 	lbu	$t5,0x60($v0)
/*  f0f5dc8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f5dcc:	29a10003 */ 	slti	$at,$t5,0x3
/*  f0f5dd0:	54200009 */ 	bnezl	$at,.L0f0f5df8
/*  f0f5dd4:	44060000 */ 	mfc1	$a2,$f0
/*  f0f5dd8:	44060000 */ 	mfc1	$a2,$f0
/*  f0f5ddc:	8c440014 */ 	lw	$a0,0x14($v0)
/*  f0f5de0:	8c450018 */ 	lw	$a1,0x18($v0)
/*  f0f5de4:	0fc54f08 */ 	jal	func0f153c20
/*  f0f5de8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0f5dec:	10000006 */ 	beqz	$zero,.L0f0f5e08
/*  f0f5df0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f5df4:	44060000 */ 	mfc1	$a2,$f0
.L0f0f5df8:
/*  f0f5df8:	8c440014 */ 	lw	$a0,0x14($v0)
/*  f0f5dfc:	0fc54f08 */ 	jal	func0f153c20
/*  f0f5e00:	8c450018 */ 	lw	$a1,0x18($v0)
/*  f0f5e04:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f0f5e08:
/*  f0f5e08:	3c018008 */ 	lui	$at,0x8008
/*  f0f5e0c:	ac2efb9c */ 	sw	$t6,-0x464($at)
/*  f0f5e10:	10000008 */ 	beqz	$zero,.L0f0f5e34
/*  f0f5e14:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f5e18:	904b0060 */ 	lbu	$t3,0x60($v0)
.L0f0f5e1c:
/*  f0f5e1c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f5e20:	55610005 */ 	bnel	$t3,$at,.L0f0f5e38
/*  f0f5e24:	8fac0084 */ 	lw	$t4,0x84($sp)
/*  f0f5e28:	0fc54f62 */ 	jal	func0f153d88
/*  f0f5e2c:	c44c0050 */ 	lwc1	$f12,0x50($v0)
/*  f0f5e30:	8fa201ec */ 	lw	$v0,0x1ec($sp)
.L0f0f5e34:
/*  f0f5e34:	8fac0084 */ 	lw	$t4,0x84($sp)
.L0f0f5e38:
/*  f0f5e38:	3c0b7f1b */ 	lui	$t3,0x7f1b
/*  f0f5e3c:	256b1fb0 */ 	addiu	$t3,$t3,0x1fb0
/*  f0f5e40:	0195082a */ 	slt	$at,$t4,$s5
/*  f0f5e44:	50200003 */ 	beqzl	$at,.L0f0f5e54
/*  f0f5e48:	c44a0040 */ 	lwc1	$f10,0x40($v0)
/*  f0f5e4c:	afb501d4 */ 	sw	$s5,0x1d4($sp)
/*  f0f5e50:	c44a0040 */ 	lwc1	$f10,0x40($v0)
.L0f0f5e54:
/*  f0f5e54:	4614503c */ 	c.lt.s	$f10,$f20
/*  f0f5e58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f5e5c:	4502000b */ 	bc1fl	.L0f0f5e8c
/*  f0f5e60:	904d003d */ 	lbu	$t5,0x3d($v0)
/*  f0f5e64:	9058003c */ 	lbu	$t8,0x3c($v0)
/*  f0f5e68:	3c0f7f1b */ 	lui	$t7,0x7f1b
/*  f0f5e6c:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0f5e70:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f5e74:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f5e78:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f0f5e7c:	8def1fc0 */ 	lw	$t7,0x1fc0($t7)
/*  f0f5e80:	10000011 */ 	beqz	$zero,.L0f0f5ec8
/*  f0f5e84:	afaf01bc */ 	sw	$t7,0x1bc($sp)
/*  f0f5e88:	904d003d */ 	lbu	$t5,0x3d($v0)
.L0f0f5e8c:
/*  f0f5e8c:	9058003c */ 	lbu	$t8,0x3c($v0)
/*  f0f5e90:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f5e94:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f0f5e98:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0f5e9c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f5ea0:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f5ea4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f5ea8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f5eac:	01cb6021 */ 	addu	$t4,$t6,$t3
/*  f0f5eb0:	032b7821 */ 	addu	$t7,$t9,$t3
/*  f0f5eb4:	8de50010 */ 	lw	$a1,0x10($t7)
/*  f0f5eb8:	0fc01a40 */ 	jal	func0f006900
/*  f0f5ebc:	8d840010 */ 	lw	$a0,0x10($t4)
/*  f0f5ec0:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f0f5ec4:	8fa201ec */ 	lw	$v0,0x1ec($sp)
.L0f0f5ec8:
/*  f0f5ec8:	8c4d000c */ 	lw	$t5,0xc($v0)
/*  f0f5ecc:	8fa401bc */ 	lw	$a0,0x1bc($sp)
/*  f0f5ed0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f5ed4:	51a0000b */ 	beqzl	$t5,.L0f0f5f04
/*  f0f5ed8:	c4500040 */ 	lwc1	$f16,0x40($v0)
/*  f0f5edc:	0fc01a40 */ 	jal	func0f006900
/*  f0f5ee0:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0f5ee4:	8fac01bc */ 	lw	$t4,0x1bc($sp)
/*  f0f5ee8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f5eec:	00417024 */ 	and	$t6,$v0,$at
/*  f0f5ef0:	319800ff */ 	andi	$t8,$t4,0xff
/*  f0f5ef4:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0f5ef8:	afb901bc */ 	sw	$t9,0x1bc($sp)
/*  f0f5efc:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f5f00:	c4500040 */ 	lwc1	$f16,0x40($v0)
.L0f0f5f04:
/*  f0f5f04:	3c187f1b */ 	lui	$t8,0x7f1b
/*  f0f5f08:	27181fb0 */ 	addiu	$t8,$t8,0x1fb0
/*  f0f5f0c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0f5f10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f5f14:	4502000b */ 	bc1fl	.L0f0f5f44
/*  f0f5f18:	904c003d */ 	lbu	$t4,0x3d($v0)
/*  f0f5f1c:	904b003c */ 	lbu	$t3,0x3c($v0)
/*  f0f5f20:	3c0d7f1b */ 	lui	$t5,0x7f1b
/*  f0f5f24:	000b7900 */ 	sll	$t7,$t3,0x4
/*  f0f5f28:	01eb7823 */ 	subu	$t7,$t7,$t3
/*  f0f5f2c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f5f30:	01af6821 */ 	addu	$t5,$t5,$t7
/*  f0f5f34:	8dad1fc4 */ 	lw	$t5,0x1fc4($t5)
/*  f0f5f38:	10000011 */ 	beqz	$zero,.L0f0f5f80
/*  f0f5f3c:	afad01b8 */ 	sw	$t5,0x1b8($sp)
/*  f0f5f40:	904c003d */ 	lbu	$t4,0x3d($v0)
.L0f0f5f44:
/*  f0f5f44:	904b003c */ 	lbu	$t3,0x3c($v0)
/*  f0f5f48:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f5f4c:	000c7100 */ 	sll	$t6,$t4,0x4
/*  f0f5f50:	000b7900 */ 	sll	$t7,$t3,0x4
/*  f0f5f54:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f0f5f58:	01eb7823 */ 	subu	$t7,$t7,$t3
/*  f0f5f5c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f5f60:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f5f64:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f0f5f68:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f0f5f6c:	8da50014 */ 	lw	$a1,0x14($t5)
/*  f0f5f70:	0fc01a40 */ 	jal	func0f006900
/*  f0f5f74:	8f240014 */ 	lw	$a0,0x14($t9)
/*  f0f5f78:	afa201b8 */ 	sw	$v0,0x1b8($sp)
/*  f0f5f7c:	8fa201ec */ 	lw	$v0,0x1ec($sp)
.L0f0f5f80:
/*  f0f5f80:	8fac01f4 */ 	lw	$t4,0x1f4($sp)
/*  f0f5f84:	8fa901e0 */ 	lw	$t1,0x1e0($sp)
/*  f0f5f88:	5580008a */ 	bnezl	$t4,.L0f0f61b4
/*  f0f5f8c:	904d0060 */ 	lbu	$t5,0x60($v0)
/*  f0f5f90:	90430060 */ 	lbu	$v1,0x60($v0)
/*  f0f5f94:	87ae01ca */ 	lh	$t6,0x1ca($sp)
/*  f0f5f98:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f5f9c:	14610014 */ 	bne	$v1,$at,.L0f0f5ff0
/*  f0f5fa0:	01c94021 */ 	addu	$t0,$t6,$t1
/*  f0f5fa4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f5fa8:	44819000 */ 	mtc1	$at,$f18
/*  f0f5fac:	8fb901d4 */ 	lw	$t9,0x1d4($sp)
/*  f0f5fb0:	8fab01bc */ 	lw	$t3,0x1bc($sp)
/*  f0f5fb4:	8faf01b8 */ 	lw	$t7,0x1b8($sp)
/*  f0f5fb8:	25300001 */ 	addiu	$s0,$t1,0x1
/*  f0f5fbc:	2511ffff */ 	addiu	$s1,$t0,-1
/*  f0f5fc0:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f5fc4:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f5fc8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5fcc:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f5fd0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0f5fd4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f5fd8:	e7b20020 */ 	swc1	$f18,0x20($sp)
/*  f0f5fdc:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f5fe0:	0fc3836b */ 	jal	func0f0e0dac
/*  f0f5fe4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f5fe8:	10000027 */ 	beqz	$zero,.L0f0f6088
/*  f0f5fec:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f5ff0:
/*  f0f5ff0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f5ff4:	14610013 */ 	bne	$v1,$at,.L0f0f6044
/*  f0f5ff8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5ffc:	8fb801d4 */ 	lw	$t8,0x1d4($sp)
/*  f0f6000:	8fad01bc */ 	lw	$t5,0x1bc($sp)
/*  f0f6004:	8fac01b8 */ 	lw	$t4,0x1b8($sp)
/*  f0f6008:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0f600c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f6010:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f6014:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0f6018:	c4440050 */ 	lwc1	$f4,0x50($v0)
/*  f0f601c:	25300001 */ 	addiu	$s0,$t1,0x1
/*  f0f6020:	2511ffff */ 	addiu	$s1,$t0,-1
/*  f0f6024:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f6028:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f602c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6030:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6034:	0fc3836b */ 	jal	func0f0e0dac
/*  f0f6038:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0f603c:	10000012 */ 	beqz	$zero,.L0f0f6088
/*  f0f6040:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f6044:
/*  f0f6044:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f6048:	44813000 */ 	mtc1	$at,$f6
/*  f0f604c:	8fae01d4 */ 	lw	$t6,0x1d4($sp)
/*  f0f6050:	8fb901bc */ 	lw	$t9,0x1bc($sp)
/*  f0f6054:	8fab01b8 */ 	lw	$t3,0x1b8($sp)
/*  f0f6058:	25300001 */ 	addiu	$s0,$t1,0x1
/*  f0f605c:	2511ffff */ 	addiu	$s1,$t0,-1
/*  f0f6060:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f6064:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f6068:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f606c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0f6070:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f6074:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f0f6078:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0f607c:	0fc3836b */ 	jal	func0f0e0dac
/*  f0f6080:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0f6084:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f6088:
/*  f0f6088:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f608c:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0f6090:	8df80010 */ 	lw	$t8,0x10($t7)
/*  f0f6094:	330d0100 */ 	andi	$t5,$t8,0x100
/*  f0f6098:	51a00046 */ 	beqzl	$t5,.L0f0f61b4
/*  f0f609c:	904d0060 */ 	lbu	$t5,0x60($v0)
/*  f0f60a0:	c4400040 */ 	lwc1	$f0,0x40($v0)
/*  f0f60a4:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f60a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f60ac:	4502000b */ 	bc1fl	.L0f0f60dc
/*  f0f60b0:	904b003d */ 	lbu	$t3,0x3d($v0)
/*  f0f60b4:	904c003c */ 	lbu	$t4,0x3c($v0)
/*  f0f60b8:	3c197f1b */ 	lui	$t9,0x7f1b
/*  f0f60bc:	27391fb0 */ 	addiu	$t9,$t9,0x1fb0
/*  f0f60c0:	000c7100 */ 	sll	$t6,$t4,0x4
/*  f0f60c4:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f0f60c8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f60cc:	01d91821 */ 	addu	$v1,$t6,$t9
/*  f0f60d0:	1000001b */ 	beqz	$zero,.L0f0f6140
/*  f0f60d4:	8c720000 */ 	lw	$s2,0x0($v1)
/*  f0f60d8:	904b003d */ 	lbu	$t3,0x3d($v0)
.L0f0f60dc:
/*  f0f60dc:	904c003c */ 	lbu	$t4,0x3c($v0)
/*  f0f60e0:	3c187f1b */ 	lui	$t8,0x7f1b
/*  f0f60e4:	000b7900 */ 	sll	$t7,$t3,0x4
/*  f0f60e8:	000c7100 */ 	sll	$t6,$t4,0x4
/*  f0f60ec:	27181fb0 */ 	addiu	$t8,$t8,0x1fb0
/*  f0f60f0:	01eb7823 */ 	subu	$t7,$t7,$t3
/*  f0f60f4:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f0f60f8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f60fc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f6100:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f0f6104:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f0f6108:	8f250000 */ 	lw	$a1,0x0($t9)
/*  f0f610c:	8da40000 */ 	lw	$a0,0x0($t5)
/*  f0f6110:	0fc01a40 */ 	jal	func0f006900
/*  f0f6114:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f6118:	00409025 */ 	or	$s2,$v0,$zero
/*  f0f611c:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f6120:	3c0c7f1b */ 	lui	$t4,0x7f1b
/*  f0f6124:	258c1fb0 */ 	addiu	$t4,$t4,0x1fb0
/*  f0f6128:	904f003c */ 	lbu	$t7,0x3c($v0)
/*  f0f612c:	c4400040 */ 	lwc1	$f0,0x40($v0)
/*  f0f6130:	000f6900 */ 	sll	$t5,$t7,0x4
/*  f0f6134:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f0f6138:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f613c:	01ac1821 */ 	addu	$v1,$t5,$t4
.L0f0f6140:
/*  f0f6140:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f6144:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0f6148:	45020004 */ 	bc1fl	.L0f0f615c
/*  f0f614c:	904e003d */ 	lbu	$t6,0x3d($v0)
/*  f0f6150:	1000000b */ 	beqz	$zero,.L0f0f6180
/*  f0f6154:	8c680008 */ 	lw	$t0,0x8($v1)
/*  f0f6158:	904e003d */ 	lbu	$t6,0x3d($v0)
.L0f0f615c:
/*  f0f615c:	8c650008 */ 	lw	$a1,0x8($v1)
/*  f0f6160:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f6164:	000ec100 */ 	sll	$t8,$t6,0x4
/*  f0f6168:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f0f616c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f6170:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0f6174:	0fc01a40 */ 	jal	func0f006900
/*  f0f6178:	8c841fb8 */ 	lw	$a0,0x1fb8($a0)
/*  f0f617c:	00404025 */ 	or	$t0,$v0,$zero
.L0f0f6180:
/*  f0f6180:	8fb901dc */ 	lw	$t9,0x1dc($sp)
/*  f0f6184:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6188:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f618c:	272f000c */ 	addiu	$t7,$t9,0xc
/*  f0f6190:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0f6194:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6198:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f619c:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f61a0:	0fc38bba */ 	jal	func0f0e2ee8
/*  f0f61a4:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0f61a8:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f61ac:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f61b0:	904d0060 */ 	lbu	$t5,0x60($v0)
.L0f0f61b4:
/*  f0f61b4:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f61b8:	87ac01ca */ 	lh	$t4,0x1ca($sp)
/*  f0f61bc:	15a00003 */ 	bnez	$t5,.L0f0f61cc
/*  f0f61c0:	24720002 */ 	addiu	$s2,$v1,0x2
/*  f0f61c4:	100004ab */ 	beqz	$zero,.L0f0f7474
/*  f0f61c8:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f61cc:
/*  f0f61cc:	01835821 */ 	addu	$t3,$t4,$v1
/*  f0f61d0:	0c002f40 */ 	jal	func0000bd00
/*  f0f61d4:	afab0088 */ 	sw	$t3,0x88($sp)
/*  f0f61d8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0f61dc:	8dcefac0 */ 	lw	$t6,-0x540($t6)
/*  f0f61e0:	004e001a */ 	div	$zero,$v0,$t6
/*  f0f61e4:	00009812 */ 	mflo	$s3
/*  f0f61e8:	15c00002 */ 	bnez	$t6,.L0f0f61f4
/*  f0f61ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f61f0:	0007000d */ 	break	0x7
.L0f0f61f4:
/*  f0f61f4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f61f8:	15c10004 */ 	bne	$t6,$at,.L0f0f620c
/*  f0f61fc:	3c018000 */ 	lui	$at,0x8000
/*  f0f6200:	14410002 */ 	bne	$v0,$at,.L0f0f620c
/*  f0f6204:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6208:	0006000d */ 	break	0x6
.L0f0f620c:
/*  f0f620c:	0c002f44 */ 	jal	func0000bd10
/*  f0f6210:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6214:	0c002f40 */ 	jal	func0000bd00
/*  f0f6218:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0f621c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6220:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f0f6224:	0c002f22 */ 	jal	func0000bc88
/*  f0f6228:	03008025 */ 	or	$s0,$t8,$zero
/*  f0f622c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0f6230:	8deffac0 */ 	lw	$t7,-0x540($t7)
/*  f0f6234:	0050c821 */ 	addu	$t9,$v0,$s0
/*  f0f6238:	032f001a */ 	div	$zero,$t9,$t7
/*  f0f623c:	00008812 */ 	mflo	$s1
/*  f0f6240:	15e00002 */ 	bnez	$t7,.L0f0f624c
/*  f0f6244:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6248:	0007000d */ 	break	0x7
.L0f0f624c:
/*  f0f624c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f6250:	15e10004 */ 	bne	$t7,$at,.L0f0f6264
/*  f0f6254:	3c018000 */ 	lui	$at,0x8000
/*  f0f6258:	17210002 */ 	bne	$t9,$at,.L0f0f6264
/*  f0f625c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6260:	0006000d */ 	break	0x6
.L0f0f6264:
/*  f0f6264:	0c002f44 */ 	jal	func0000bd10
/*  f0f6268:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f626c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6270:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0f6274:	0c002f26 */ 	jal	func0000bc98
/*  f0f6278:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0f627c:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f0f6280:	3c08800a */ 	lui	$t0,%hi(var800a2038)
/*  f0f6284:	25082038 */ 	addiu	$t0,$t0,%lo(var800a2038)
/*  f0f6288:	3c0a800a */ 	lui	$t2,%hi(var800a203c)
/*  f0f628c:	ad120000 */ 	sw	$s2,0x0($t0)
/*  f0f6290:	3c01800a */ 	lui	$at,0x800a
/*  f0f6294:	258bfffe */ 	addiu	$t3,$t4,-2
/*  f0f6298:	254a203c */ 	addiu	$t2,$t2,%lo(var800a203c)
/*  f0f629c:	ac2b203c */ 	sw	$t3,0x203c($at)
/*  f0f62a0:	8fae01d4 */ 	lw	$t6,0x1d4($sp)
/*  f0f62a4:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f0f62a8:	3c03800a */ 	lui	$v1,%hi(var800a2044)
/*  f0f62ac:	3c09800a */ 	lui	$t1,%hi(var800a2040)
/*  f0f62b0:	25292040 */ 	addiu	$t1,$t1,%lo(var800a2040)
/*  f0f62b4:	24632044 */ 	addiu	$v1,$v1,%lo(var800a2044)
/*  f0f62b8:	25d8ffff */ 	addiu	$t8,$t6,-1
/*  f0f62bc:	0093082a */ 	slt	$at,$a0,$s3
/*  f0f62c0:	ad350000 */ 	sw	$s5,0x0($t1)
/*  f0f62c4:	10200003 */ 	beqz	$at,.L0f0f62d4
/*  f0f62c8:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0f62cc:	10000469 */ 	beqz	$zero,.L0f0f7474
/*  f0f62d0:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f62d4:
/*  f0f62d4:	8c650000 */ 	lw	$a1,0x0($v1)
/*  f0f62d8:	00b4082a */ 	slt	$at,$a1,$s4
/*  f0f62dc:	50200004 */ 	beqzl	$at,.L0f0f62f0
/*  f0f62e0:	8d060000 */ 	lw	$a2,0x0($t0)
/*  f0f62e4:	10000463 */ 	beqz	$zero,.L0f0f7474
/*  f0f62e8:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f62ec:	8d060000 */ 	lw	$a2,0x0($t0)
.L0f0f62f0:
/*  f0f62f0:	0226082a */ 	slt	$at,$s1,$a2
/*  f0f62f4:	50200004 */ 	beqzl	$at,.L0f0f6308
/*  f0f62f8:	8d270000 */ 	lw	$a3,0x0($t1)
/*  f0f62fc:	1000045d */ 	beqz	$zero,.L0f0f7474
/*  f0f6300:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f6304:	8d270000 */ 	lw	$a3,0x0($t1)
.L0f0f6308:
/*  f0f6308:	00501821 */ 	addu	$v1,$v0,$s0
/*  f0f630c:	0067082a */ 	slt	$at,$v1,$a3
/*  f0f6310:	50200004 */ 	beqzl	$at,.L0f0f6324
/*  f0f6314:	0224082a */ 	slt	$at,$s1,$a0
/*  f0f6318:	10000456 */ 	beqz	$zero,.L0f0f7474
/*  f0f631c:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f6320:	0224082a */ 	slt	$at,$s1,$a0
.L0f0f6324:
/*  f0f6324:	50200004 */ 	beqzl	$at,.L0f0f6338
/*  f0f6328:	0065082a */ 	slt	$at,$v1,$a1
/*  f0f632c:	ad510000 */ 	sw	$s1,0x0($t2)
/*  f0f6330:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f6334:	0065082a */ 	slt	$at,$v1,$a1
.L0f0f6338:
/*  f0f6338:	10200004 */ 	beqz	$at,.L0f0f634c
/*  f0f633c:	3c01800a */ 	lui	$at,0x800a
/*  f0f6340:	ac232044 */ 	sw	$v1,0x2044($at)
/*  f0f6344:	3c05800a */ 	lui	$a1,0x800a
/*  f0f6348:	8ca52044 */ 	lw	$a1,0x2044($a1)
.L0f0f634c:
/*  f0f634c:	00d3082a */ 	slt	$at,$a2,$s3
/*  f0f6350:	50200003 */ 	beqzl	$at,.L0f0f6360
/*  f0f6354:	0094082a */ 	slt	$at,$a0,$s4
/*  f0f6358:	ad130000 */ 	sw	$s3,0x0($t0)
/*  f0f635c:	0094082a */ 	slt	$at,$a0,$s4
.L0f0f6360:
/*  f0f6360:	10200002 */ 	beqz	$at,.L0f0f636c
/*  f0f6364:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6368:	ad540000 */ 	sw	$s4,0x0($t2)
.L0f0f636c:
/*  f0f636c:	3c01800a */ 	lui	$at,0x800a
/*  f0f6370:	ac27de90 */ 	sw	$a3,-0x2170($at)
/*  f0f6374:	3c01800a */ 	lui	$at,0x800a
/*  f0f6378:	ac25de94 */ 	sw	$a1,-0x216c($at)
/*  f0f637c:	0fc3d43f */ 	jal	func0f0f50fc
/*  f0f6380:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6384:	3c198007 */ 	lui	$t9,0x8007
/*  f0f6388:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f0f638c:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f0f6390:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f0f6394:	001978c0 */ 	sll	$t7,$t9,0x3
/*  f0f6398:	01f97823 */ 	subu	$t7,$t7,$t9
/*  f0f639c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f63a0:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f0f63a4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f63a8:	01f97823 */ 	subu	$t7,$t7,$t9
/*  f0f63ac:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f63b0:	01ed1821 */ 	addu	$v1,$t7,$t5
/*  f0f63b4:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f63b8:	8c6c04f8 */ 	lw	$t4,0x4f8($v1)
/*  f0f63bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f63c0:	54ec0033 */ 	bnel	$a3,$t4,.L0f0f6490
/*  f0f63c4:	90f8003c */ 	lbu	$t8,0x3c($a3)
/*  f0f63c8:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f0f63cc:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
/*  f0f63d0:	8d6e0010 */ 	lw	$t6,0x10($t3)
/*  f0f63d4:	31d80002 */ 	andi	$t8,$t6,0x2
/*  f0f63d8:	5300002d */ 	beqzl	$t8,.L0f0f6490
/*  f0f63dc:	90f8003c */ 	lbu	$t8,0x3c($a3)
/*  f0f63e0:	5720002b */ 	bnezl	$t9,.L0f0f6490
/*  f0f63e4:	90f8003c */ 	lbu	$t8,0x3c($a3)
/*  f0f63e8:	8c6f0df0 */ 	lw	$t7,0xdf0($v1)
/*  f0f63ec:	3c0bb700 */ 	lui	$t3,0xb700
/*  f0f63f0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f63f4:	000f6380 */ 	sll	$t4,$t7,0xe
/*  f0f63f8:	05800024 */ 	bltz	$t4,.L0f0f648c
/*  f0f63fc:	3c188007 */ 	lui	$t8,0x8007
/*  f0f6400:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f0f6404:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0f6408:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f0f640c:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f0f6410:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f0f6414:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0f6418:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f641c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f6420:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f6424:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f6428:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f642c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f6430:	272f0840 */ 	addiu	$t7,$t9,0x840
/*  f0f6434:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f6438:	01ed2821 */ 	addu	$a1,$t7,$t5
/*  f0f643c:	0fc3ce2c */ 	jal	func0f0f38b0
/*  f0f6440:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f6444:	244c0008 */ 	addiu	$t4,$v0,0x8
/*  f0f6448:	afac01e8 */ 	sw	$t4,0x1e8($sp)
/*  f0f644c:	3c0bb600 */ 	lui	$t3,0xb600
/*  f0f6450:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f6454:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0f6458:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f0f645c:	8fd00284 */ 	lw	$s0,0x284($s8)
/*  f0f6460:	86040634 */ 	lh	$a0,0x634($s0)
/*  f0f6464:	0c002f2a */ 	jal	func0000bca8
/*  f0f6468:	86050636 */ 	lh	$a1,0x636($s0)
/*  f0f646c:	8fd00284 */ 	lw	$s0,0x284($s8)
/*  f0f6470:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f0f6474:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f0f6478:	86060630 */ 	lh	$a2,0x630($s0)
/*  f0f647c:	0c002f76 */ 	jal	func0000bdd8
/*  f0f6480:	86070632 */ 	lh	$a3,0x632($s0)
/*  f0f6484:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f6488:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.L0f0f648c:
/*  f0f648c:	90f8003c */ 	lbu	$t8,0x3c($a3)
.L0f0f6490:
/*  f0f6490:	57000008 */ 	bnezl	$t8,.L0f0f64b4
/*  f0f6494:	8fb901e0 */ 	lw	$t9,0x1e0($sp)
/*  f0f6498:	c4e80040 */ 	lwc1	$f8,0x40($a3)
/*  f0f649c:	00809825 */ 	or	$s3,$a0,$zero
/*  f0f64a0:	4608a03e */ 	c.le.s	$f20,$f8
/*  f0f64a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f64a8:	45020292 */ 	bc1fl	.L0f0f6ef4
/*  f0f64ac:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f64b0:	8fb901e0 */ 	lw	$t9,0x1e0($sp)
.L0f0f64b4:
/*  f0f64b4:	afa00130 */ 	sw	$zero,0x130($sp)
/*  f0f64b8:	afa001e4 */ 	sw	$zero,0x1e4($sp)
/*  f0f64bc:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f64c0:	afb90194 */ 	sw	$t9,0x194($sp)
/*  f0f64c4:	90ef0005 */ 	lbu	$t7,0x5($a3)
/*  f0f64c8:	59e001e7 */ 	blezl	$t7,.L0f0f6c68
/*  f0f64cc:	8fad01f4 */ 	lw	$t5,0x1f4($sp)
/*  f0f64d0:	afa401e8 */ 	sw	$a0,0x1e8($sp)
.L0f0f64d4:
/*  f0f64d4:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f64d8:	8fad01dc */ 	lw	$t5,0x1dc($sp)
/*  f0f64dc:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0f64e0:	8c4c0064 */ 	lw	$t4,0x64($v0)
/*  f0f64e4:	afa00128 */ 	sw	$zero,0x128($sp)
/*  f0f64e8:	01ac5821 */ 	addu	$t3,$t5,$t4
/*  f0f64ec:	256e000c */ 	addiu	$t6,$t3,0xc
/*  f0f64f0:	afae012c */ 	sw	$t6,0x12c($sp)
/*  f0f64f4:	9058003c */ 	lbu	$t8,0x3c($v0)
/*  f0f64f8:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0f64fc:	c44a0040 */ 	lwc1	$f10,0x40($v0)
/*  f0f6500:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0f6504:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f6508:	4614503c */ 	c.lt.s	$f10,$f20
/*  f0f650c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f6510:	00b92821 */ 	addu	$a1,$a1,$t9
/*  f0f6514:	8ca51fc8 */ 	lw	$a1,0x1fc8($a1)
/*  f0f6518:	45020005 */ 	bc1fl	.L0f0f6530
/*  f0f651c:	904f003d */ 	lbu	$t7,0x3d($v0)
/*  f0f6520:	afa50120 */ 	sw	$a1,0x120($sp)
/*  f0f6524:	1000000d */ 	beqz	$zero,.L0f0f655c
/*  f0f6528:	90430004 */ 	lbu	$v1,0x4($v0)
/*  f0f652c:	904f003d */ 	lbu	$t7,0x3d($v0)
.L0f0f6530:
/*  f0f6530:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0f6534:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f6538:	000f6900 */ 	sll	$t5,$t7,0x4
/*  f0f653c:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f0f6540:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f6544:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0f6548:	0fc01a40 */ 	jal	func0f006900
/*  f0f654c:	8c841fc8 */ 	lw	$a0,0x1fc8($a0)
/*  f0f6550:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0f6554:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f6558:	90430004 */ 	lbu	$v1,0x4($v0)
.L0f0f655c:
/*  f0f655c:	8fab0120 */ 	lw	$t3,0x120($sp)
/*  f0f6560:	8fb901e4 */ 	lw	$t9,0x1e4($sp)
/*  f0f6564:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f6568:	01617024 */ 	and	$t6,$t3,$at
/*  f0f656c:	35d8003f */ 	ori	$t8,$t6,0x3f
/*  f0f6570:	afb80120 */ 	sw	$t8,0x120($sp)
/*  f0f6574:	13200010 */ 	beqz	$t9,.L0f0f65b8
/*  f0f6578:	00798021 */ 	addu	$s0,$v1,$t9
/*  f0f657c:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0f6580:	8fa70194 */ 	lw	$a3,0x194($sp)
/*  f0f6584:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f6588:	8ded0010 */ 	lw	$t5,0x10($t7)
/*  f0f658c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6590:	24e5ffff */ 	addiu	$a1,$a3,-1
/*  f0f6594:	31ac0400 */ 	andi	$t4,$t5,0x400
/*  f0f6598:	15800007 */ 	bnez	$t4,.L0f0f65b8
/*  f0f659c:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f0f65a0:	8fab01d4 */ 	lw	$t3,0x1d4($sp)
/*  f0f65a4:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f65a8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f65ac:	0fc38bd7 */ 	jal	func0f0e2f5c
/*  f0f65b0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f65b4:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f65b8:
/*  f0f65b8:	8fae01f0 */ 	lw	$t6,0x1f0($sp)
/*  f0f65bc:	0010c880 */ 	sll	$t9,$s0,0x2
/*  f0f65c0:	0330c821 */ 	addu	$t9,$t9,$s0
/*  f0f65c4:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f0f65c8:	01d92821 */ 	addu	$a1,$t6,$t9
/*  f0f65cc:	84a40660 */ 	lh	$a0,0x660($a1)
/*  f0f65d0:	8faf0130 */ 	lw	$t7,0x130($sp)
/*  f0f65d4:	8fb801ec */ 	lw	$t8,0x1ec($sp)
/*  f0f65d8:	8fab01e4 */ 	lw	$t3,0x1e4($sp)
/*  f0f65dc:	01e46021 */ 	addu	$t4,$t7,$a0
/*  f0f65e0:	afac0130 */ 	sw	$t4,0x130($sp)
/*  f0f65e4:	afa40124 */ 	sw	$a0,0x124($sp)
/*  f0f65e8:	93030005 */ 	lbu	$v1,0x5($t8)
/*  f0f65ec:	256e0001 */ 	addiu	$t6,$t3,0x1
/*  f0f65f0:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f0f65f4:	15c30009 */ 	bne	$t6,$v1,.L0f0f661c
/*  f0f65f8:	00806825 */ 	or	$t5,$a0,$zero
/*  f0f65fc:	8faf01e0 */ 	lw	$t7,0x1e0($sp)
/*  f0f6600:	032f1023 */ 	subu	$v0,$t9,$t7
/*  f0f6604:	2442fffe */ 	addiu	$v0,$v0,-2
/*  f0f6608:	0182082a */ 	slt	$at,$t4,$v0
/*  f0f660c:	10200003 */ 	beqz	$at,.L0f0f661c
/*  f0f6610:	01a2c021 */ 	addu	$t8,$t5,$v0
/*  f0f6614:	030c5823 */ 	subu	$t3,$t8,$t4
/*  f0f6618:	afab0124 */ 	sw	$t3,0x124($sp)
.L0f0f661c:
/*  f0f661c:	90ae0668 */ 	lbu	$t6,0x668($a1)
/*  f0f6620:	8fb901dc */ 	lw	$t9,0x1dc($sp)
/*  f0f6624:	19c00187 */ 	blez	$t6,.L0f0f6c44
/*  f0f6628:	272f000c */ 	addiu	$t7,$t9,0xc
/*  f0f662c:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f0f6630:	afa50080 */ 	sw	$a1,0x80($sp)
/*  f0f6634:	8fb80080 */ 	lw	$t8,0x80($sp)
.L0f0f6638:
/*  f0f6638:	afa00114 */ 	sw	$zero,0x114($sp)
/*  f0f663c:	8fab01c0 */ 	lw	$t3,0x1c0($sp)
/*  f0f6640:	970c0666 */ 	lhu	$t4,0x666($t8)
/*  f0f6644:	8fae01f0 */ 	lw	$t6,0x1f0($sp)
/*  f0f6648:	8fad01ec */ 	lw	$t5,0x1ec($sp)
/*  f0f664c:	018b1821 */ 	addu	$v1,$t4,$t3
/*  f0f6650:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f0f6654:	01d91021 */ 	addu	$v0,$t6,$t9
/*  f0f6658:	904f04fe */ 	lbu	$t7,0x4fe($v0)
/*  f0f665c:	8dac0000 */ 	lw	$t4,0x0($t5)
/*  f0f6660:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f6664:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0f6668:	8d8b0008 */ 	lw	$t3,0x8($t4)
/*  f0f666c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f6670:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f6674:	030b3021 */ 	addu	$a2,$t8,$t3
/*  f0f6678:	afa60118 */ 	sw	$a2,0x118($sp)
/*  f0f667c:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f0f6680:	8dae0008 */ 	lw	$t6,0x8($t5)
/*  f0f6684:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f6688:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f668c:	54ce0008 */ 	bnel	$a2,$t6,.L0f0f66b0
/*  f0f6690:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f0f6694:	afb90114 */ 	sw	$t9,0x114($sp)
/*  f0f6698:	8daf000c */ 	lw	$t7,0xc($t5)
/*  f0f669c:	240c0003 */ 	addiu	$t4,$zero,0x3
/*  f0f66a0:	51e00003 */ 	beqzl	$t7,.L0f0f66b0
/*  f0f66a4:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f0f66a8:	afac0114 */ 	sw	$t4,0x114($sp)
/*  f0f66ac:	8fb8007c */ 	lw	$t8,0x7c($sp)
.L0f0f66b0:
/*  f0f66b0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f66b4:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0f66b8:	830204ff */ 	lb	$v0,0x4ff($t8)
/*  f0f66bc:	8fab01f0 */ 	lw	$t3,0x1f0($sp)
/*  f0f66c0:	8fb90194 */ 	lw	$t9,0x194($sp)
/*  f0f66c4:	10410003 */ 	beq	$v0,$at,.L0f0f66d4
/*  f0f66c8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0f66cc:	016e2821 */ 	addu	$a1,$t3,$t6
/*  f0f66d0:	24a506dc */ 	addiu	$a1,$a1,0x6dc
.L0f0f66d4:
/*  f0f66d4:	8fad0124 */ 	lw	$t5,0x124($sp)
/*  f0f66d8:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f0f66dc:	a7b90198 */ 	sh	$t9,0x198($sp)
/*  f0f66e0:	a7a3019a */ 	sh	$v1,0x19a($sp)
/*  f0f66e4:	a7ad019c */ 	sh	$t5,0x19c($sp)
/*  f0f66e8:	85ec04fc */ 	lh	$t4,0x4fc($t7)
/*  f0f66ec:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0f66f0:	00031400 */ 	sll	$v0,$v1,0x10
/*  f0f66f4:	0002c403 */ 	sra	$t8,$v0,0x10
/*  f0f66f8:	030c5821 */ 	addu	$t3,$t8,$t4
/*  f0f66fc:	016e082a */ 	slt	$at,$t3,$t6
/*  f0f6700:	03001025 */ 	or	$v0,$t8,$zero
/*  f0f6704:	10200002 */ 	beqz	$at,.L0f0f6710
/*  f0f6708:	a7ac019e */ 	sh	$t4,0x19e($sp)
/*  f0f670c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f6710:
/*  f0f6710:	8fb901d4 */ 	lw	$t9,0x1d4($sp)
/*  f0f6714:	87ad019e */ 	lh	$t5,0x19e($sp)
/*  f0f6718:	8faf0118 */ 	lw	$t7,0x118($sp)
/*  f0f671c:	0322082a */ 	slt	$at,$t9,$v0
/*  f0f6720:	10200002 */ 	beqz	$at,.L0f0f672c
/*  f0f6724:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6728:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f672c:
/*  f0f672c:	15a00002 */ 	bnez	$t5,.L0f0f6738
/*  f0f6730:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6734:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f6738:
/*  f0f6738:	54800133 */ 	bnezl	$a0,.L0f0f6c08
/*  f0f673c:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0f6740:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f0f6744:	8fb80114 */ 	lw	$t8,0x114($sp)
/*  f0f6748:	8fac01ec */ 	lw	$t4,0x1ec($sp)
/*  f0f674c:	afaf01a0 */ 	sw	$t7,0x1a0($sp)
/*  f0f6750:	afa501ac */ 	sw	$a1,0x1ac($sp)
/*  f0f6754:	afb801a4 */ 	sw	$t8,0x1a4($sp)
/*  f0f6758:	1160000e */ 	beqz	$t3,.L0f0f6794
/*  f0f675c:	afac01a8 */ 	sw	$t4,0x1a8($sp)
/*  f0f6760:	8fa30120 */ 	lw	$v1,0x120($sp)
/*  f0f6764:	87b00196 */ 	lh	$s0,0x196($sp)
/*  f0f6768:	87ae0126 */ 	lh	$t6,0x126($sp)
/*  f0f676c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6770:	2446ffff */ 	addiu	$a2,$v0,-1
/*  f0f6774:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0f6778:	afa00128 */ 	sw	$zero,0x128($sp)
/*  f0f677c:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0f6780:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0f6784:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f6788:	0fc38bd7 */ 	jal	func0f0e2f5c
/*  f0f678c:	020e3821 */ 	addu	$a3,$s0,$t6
/*  f0f6790:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f6794:
/*  f0f6794:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f0f6798:	8fb801f4 */ 	lw	$t8,0x1f4($sp)
/*  f0f679c:	8f2d0004 */ 	lw	$t5,0x4($t9)
/*  f0f67a0:	31af4000 */ 	andi	$t7,$t5,0x4000
/*  f0f67a4:	51e00046 */ 	beqzl	$t7,.L0f0f68c0
/*  f0f67a8:	8fb90114 */ 	lw	$t9,0x114($sp)
/*  f0f67ac:	17000043 */ 	bnez	$t8,.L0f0f68bc
/*  f0f67b0:	8fad01ec */ 	lw	$t5,0x1ec($sp)
/*  f0f67b4:	c5b00040 */ 	lwc1	$f16,0x40($t5)
/*  f0f67b8:	87b00198 */ 	lh	$s0,0x198($sp)
/*  f0f67bc:	87ae019c */ 	lh	$t6,0x19c($sp)
/*  f0f67c0:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0f67c4:	87b1019a */ 	lh	$s1,0x19a($sp)
/*  f0f67c8:	87b9019e */ 	lh	$t9,0x19e($sp)
/*  f0f67cc:	01d09021 */ 	addu	$s2,$t6,$s0
/*  f0f67d0:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f67d4:	45000009 */ 	bc1f	.L0f0f67fc
/*  f0f67d8:	03319821 */ 	addu	$s3,$t9,$s1
/*  f0f67dc:	91af003c */ 	lbu	$t7,0x3c($t5)
/*  f0f67e0:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0f67e4:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0f67e8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f67ec:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f67f0:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0f67f4:	10000011 */ 	beqz	$zero,.L0f0f683c
/*  f0f67f8:	8c841fd8 */ 	lw	$a0,0x1fd8($a0)
.L0f0f67fc:
/*  f0f67fc:	91cc003d */ 	lbu	$t4,0x3d($t6)
/*  f0f6800:	2402003c */ 	addiu	$v0,$zero,0x3c
/*  f0f6804:	91cd003c */ 	lbu	$t5,0x3c($t6)
/*  f0f6808:	01820019 */ 	multu	$t4,$v0
/*  f0f680c:	3c037f1b */ 	lui	$v1,0x7f1b
/*  f0f6810:	24631fb0 */ 	addiu	$v1,$v1,0x1fb0
/*  f0f6814:	8dc60044 */ 	lw	$a2,0x44($t6)
/*  f0f6818:	0000c812 */ 	mflo	$t9
/*  f0f681c:	00795821 */ 	addu	$t3,$v1,$t9
/*  f0f6820:	8d640028 */ 	lw	$a0,0x28($t3)
/*  f0f6824:	01a20019 */ 	multu	$t5,$v0
/*  f0f6828:	00007812 */ 	mflo	$t7
/*  f0f682c:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f0f6830:	0fc01a40 */ 	jal	func0f006900
/*  f0f6834:	8f050028 */ 	lw	$a1,0x28($t8)
/*  f0f6838:	00402025 */ 	or	$a0,$v0,$zero
.L0f0f683c:
/*  f0f683c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f6840:	00812824 */ 	and	$a1,$a0,$at
/*  f0f6844:	0fc01a40 */ 	jal	func0f006900
/*  f0f6848:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0f684c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6850:	0fc54df7 */ 	jal	func0f1537dc
/*  f0f6854:	00402825 */ 	or	$a1,$v0,$zero
/*  f0f6858:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0f685c:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f0f6860:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0f6864:	3c01f600 */ 	lui	$at,0xf600
/*  f0f6868:	327803ff */ 	andi	$t8,$s3,0x3ff
/*  f0f686c:	024c0019 */ 	multu	$s2,$t4
/*  f0f6870:	00187080 */ 	sll	$t6,$t8,0x2
/*  f0f6874:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0f6878:	0000c812 */ 	mflo	$t9
/*  f0f687c:	332b03ff */ 	andi	$t3,$t9,0x3ff
/*  f0f6880:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f0f6884:	01a17825 */ 	or	$t7,$t5,$at
/*  f0f6888:	01ee6025 */ 	or	$t4,$t7,$t6
/*  f0f688c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0f6890:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f6894:	322f03ff */ 	andi	$t7,$s1,0x3ff
/*  f0f6898:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f0f689c:	02190019 */ 	multu	$s0,$t9
/*  f0f68a0:	00005812 */ 	mflo	$t3
/*  f0f68a4:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f0f68a8:	000dc380 */ 	sll	$t8,$t5,0xe
/*  f0f68ac:	030e6025 */ 	or	$t4,$t8,$t6
/*  f0f68b0:	0fc54e0e */ 	jal	func0f153838
/*  f0f68b4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0f68b8:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f68bc:
/*  f0f68bc:	8fb90114 */ 	lw	$t9,0x114($sp)
.L0f0f68c0:
/*  f0f68c0:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f0f68c4:	532000c0 */ 	beqzl	$t9,.L0f0f6bc8
/*  f0f68c8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f68cc:	91620000 */ 	lbu	$v0,0x0($t3)
/*  f0f68d0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f68d4:	8fad01ec */ 	lw	$t5,0x1ec($sp)
/*  f0f68d8:	1041000b */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68dc:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f68e0:	10410009 */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68e4:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0f68e8:	10410007 */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68ec:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0f68f0:	10410005 */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68f4:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f68f8:	10410003 */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68fc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0f6900:	54410015 */ 	bnel	$v0,$at,.L0f0f6958
/*  f0f6904:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0f6908:
/*  f0f6908:	c5a00040 */ 	lwc1	$f0,0x40($t5)
/*  f0f690c:	4600a03e */ 	c.le.s	$f20,$f0
/*  f0f6910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6914:	45020005 */ 	bc1fl	.L0f0f692c
/*  f0f6918:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f691c:	91af003d */ 	lbu	$t7,0x3d($t5)
/*  f0f6920:	51e0000d */ 	beqzl	$t7,.L0f0f6958
/*  f0f6924:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f6928:	4614003c */ 	c.lt.s	$f0,$f20
.L0f0f692c:
/*  f0f692c:	8fb801ec */ 	lw	$t8,0x1ec($sp)
/*  f0f6930:	45000004 */ 	bc1f	.L0f0f6944
/*  f0f6934:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6938:	930e003c */ 	lbu	$t6,0x3c($t8)
/*  f0f693c:	51c00006 */ 	beqzl	$t6,.L0f0f6958
/*  f0f6940:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0f6944:
/*  f0f6944:	0fc55809 */ 	jal	func0f156024
/*  f0f6948:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f694c:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f0f6950:	91820000 */ 	lbu	$v0,0x0($t4)
/*  f0f6954:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0f6958:
/*  f0f6958:	10410008 */ 	beq	$v0,$at,.L0f0f697c
/*  f0f695c:	87a3019c */ 	lh	$v1,0x19c($sp)
/*  f0f6960:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0f6964:	10410005 */ 	beq	$v0,$at,.L0f0f697c
/*  f0f6968:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0f696c:	10410003 */ 	beq	$v0,$at,.L0f0f697c
/*  f0f6970:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0f6974:	54410094 */ 	bnel	$v0,$at,.L0f0f6bc8
/*  f0f6978:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.L0f0f697c:
/*  f0f697c:	87ab019e */ 	lh	$t3,0x19e($sp)
/*  f0f6980:	8fb70120 */ 	lw	$s7,0x120($sp)
/*  f0f6984:	87a20198 */ 	lh	$v0,0x198($sp)
/*  f0f6988:	87b9019a */ 	lh	$t9,0x19a($sp)
/*  f0f698c:	05610003 */ 	bgez	$t3,.L0f0f699c
/*  f0f6990:	000b6843 */ 	sra	$t5,$t3,0x1
/*  f0f6994:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0f6998:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f699c:
/*  f0f699c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f69a0:	0061001a */ 	div	$zero,$v1,$at
/*  f0f69a4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f69a8:	02e1c024 */ 	and	$t8,$s7,$at
/*  f0f69ac:	00007812 */ 	mflo	$t7
/*  f0f69b0:	370e002f */ 	ori	$t6,$t8,0x2f
/*  f0f69b4:	032d8021 */ 	addu	$s0,$t9,$t5
/*  f0f69b8:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f0f69bc:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f0f69c0:	0300b825 */ 	or	$s7,$t8,$zero
/*  f0f69c4:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f69c8:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0f69cc:	24510008 */ 	addiu	$s1,$v0,0x8
/*  f0f69d0:	0fc38926 */ 	jal	func0f0e2498
/*  f0f69d4:	004ff021 */ 	addu	$s8,$v0,$t7
/*  f0f69d8:	8fa30120 */ 	lw	$v1,0x120($sp)
/*  f0f69dc:	2615ffff */ 	addiu	$s5,$s0,-1
/*  f0f69e0:	2632fffd */ 	addiu	$s2,$s1,-3
/*  f0f69e4:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f69e8:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f69ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f69f0:	02802825 */ 	or	$a1,$s4,$zero
/*  f0f69f4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f69f8:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f69fc:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0f6a00:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6a04:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0f6a08:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f0f6a0c:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0f6a10:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f6a14:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6a18:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f6a1c:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6a20:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f6a24:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f6a28:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6a2c:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6a30:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f6a34:	8fa30120 */ 	lw	$v1,0x120($sp)
/*  f0f6a38:	26130001 */ 	addiu	$s3,$s0,0x1
/*  f0f6a3c:	26160002 */ 	addiu	$s6,$s0,0x2
/*  f0f6a40:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f6a44:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f6a48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6a4c:	02802825 */ 	or	$a1,$s4,$zero
/*  f0f6a50:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f6a54:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6a58:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0f6a5c:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6a60:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0f6a64:	8fb90120 */ 	lw	$t9,0x120($sp)
/*  f0f6a68:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0f6a6c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f6a70:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6a74:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f6a78:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f6a7c:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f6a80:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f6a84:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6a88:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6a8c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f6a90:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0f6a94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6a98:	2625fffe */ 	addiu	$a1,$s1,-2
/*  f0f6a9c:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f6aa0:	03c03825 */ 	or	$a3,$s8,$zero
/*  f0f6aa4:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f6aa8:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f0f6aac:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6ab0:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6ab4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0f6ab8:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f0f6abc:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6ac0:	87a20198 */ 	lh	$v0,0x198($sp)
/*  f0f6ac4:	8f0e0004 */ 	lw	$t6,0x4($t8)
/*  f0f6ac8:	87a3019c */ 	lh	$v1,0x19c($sp)
/*  f0f6acc:	8fa80120 */ 	lw	$t0,0x120($sp)
/*  f0f6ad0:	31cc0020 */ 	andi	$t4,$t6,0x20
/*  f0f6ad4:	1180003b */ 	beqz	$t4,.L0f0f6bc4
/*  f0f6ad8:	00433821 */ 	addu	$a3,$v0,$v1
/*  f0f6adc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f6ae0:	0061001a */ 	div	$zero,$v1,$at
/*  f0f6ae4:	00005812 */ 	mflo	$t3
/*  f0f6ae8:	00e0a025 */ 	or	$s4,$a3,$zero
/*  f0f6aec:	24f1fff8 */ 	addiu	$s1,$a3,-8
/*  f0f6af0:	00ebf023 */ 	subu	$s8,$a3,$t3
/*  f0f6af4:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6af8:	24e5fffb */ 	addiu	$a1,$a3,-5
/*  f0f6afc:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6b00:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f6b04:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0f6b08:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0f6b0c:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6b10:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6b14:	8fad0120 */ 	lw	$t5,0x120($sp)
/*  f0f6b18:	26320003 */ 	addiu	$s2,$s1,0x3
/*  f0f6b1c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f6b20:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f6b24:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f6b28:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6b2c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f6b30:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6b34:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f6b38:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6b3c:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6b40:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f6b44:	8faf0120 */ 	lw	$t7,0x120($sp)
/*  f0f6b48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6b4c:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f6b50:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f6b54:	02803825 */ 	or	$a3,$s4,$zero
/*  f0f6b58:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f6b5c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6b60:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0f6b64:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6b68:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0f6b6c:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f0f6b70:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0f6b74:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f6b78:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6b7c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f6b80:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f6b84:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f6b88:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f6b8c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6b90:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6b94:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0f6b98:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0f6b9c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6ba0:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0f6ba4:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f6ba8:	26270002 */ 	addiu	$a3,$s1,0x2
/*  f0f6bac:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f6bb0:	afb70014 */ 	sw	$s7,0x14($sp)
/*  f0f6bb4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6bb8:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6bbc:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0f6bc0:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f6bc4:
/*  f0f6bc4:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.L0f0f6bc8:
/*  f0f6bc8:	0fc3c167 */ 	jal	func0f0f059c
/*  f0f6bcc:	27a50198 */ 	addiu	$a1,$sp,0x198
/*  f0f6bd0:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f0f6bd4:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6bd8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f6bdc:	91790000 */ 	lbu	$t9,0x0($t3)
/*  f0f6be0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0f6be4:	57210003 */ 	bnel	$t9,$at,.L0f0f6bf4
/*  f0f6be8:	8faf0114 */ 	lw	$t7,0x114($sp)
/*  f0f6bec:	afad0128 */ 	sw	$t5,0x128($sp)
/*  f0f6bf0:	8faf0114 */ 	lw	$t7,0x114($sp)
.L0f0f6bf4:
/*  f0f6bf4:	51e00004 */ 	beqzl	$t7,.L0f0f6c08
/*  f0f6bf8:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0f6bfc:	0fc55809 */ 	jal	func0f156024
/*  f0f6c00:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f6c04:	8fae007c */ 	lw	$t6,0x7c($sp)
.L0f0f6c08:
/*  f0f6c08:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*  f0f6c0c:	8fb8012c */ 	lw	$t8,0x12c($sp)
/*  f0f6c10:	85cc04fc */ 	lh	$t4,0x4fc($t6)
/*  f0f6c14:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f0f6c18:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f0f6c1c:	030c5821 */ 	addu	$t3,$t8,$t4
/*  f0f6c20:	afad01c0 */ 	sw	$t5,0x1c0($sp)
/*  f0f6c24:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0f6c28:	904f0668 */ 	lbu	$t7,0x668($v0)
/*  f0f6c2c:	01af082a */ 	slt	$at,$t5,$t7
/*  f0f6c30:	5420fe81 */ 	bnezl	$at,.L0f0f6638
/*  f0f6c34:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f0f6c38:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f6c3c:	84440660 */ 	lh	$a0,0x660($v0)
/*  f0f6c40:	91c30005 */ 	lbu	$v1,0x5($t6)
.L0f0f6c44:
/*  f0f6c44:	8fab01e4 */ 	lw	$t3,0x1e4($sp)
/*  f0f6c48:	8fb80194 */ 	lw	$t8,0x194($sp)
/*  f0f6c4c:	25790001 */ 	addiu	$t9,$t3,0x1
/*  f0f6c50:	0323082a */ 	slt	$at,$t9,$v1
/*  f0f6c54:	03046021 */ 	addu	$t4,$t8,$a0
/*  f0f6c58:	afb901e4 */ 	sw	$t9,0x1e4($sp)
/*  f0f6c5c:	1420fe1d */ 	bnez	$at,.L0f0f64d4
/*  f0f6c60:	afac0194 */ 	sw	$t4,0x194($sp)
/*  f0f6c64:	8fad01f4 */ 	lw	$t5,0x1f4($sp)
.L0f0f6c68:
/*  f0f6c68:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6c6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f6c70:	15a00061 */ 	bnez	$t5,.L0f0f6df8
/*  f0f6c74:	8faf01e0 */ 	lw	$t7,0x1e0($sp)
/*  f0f6c78:	afaf0194 */ 	sw	$t7,0x194($sp)
/*  f0f6c7c:	0fc54df7 */ 	jal	func0f1537dc
/*  f0f6c80:	afa001e4 */ 	sw	$zero,0x1e4($sp)
/*  f0f6c84:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f6c88:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6c8c:	91c30005 */ 	lbu	$v1,0x5($t6)
/*  f0f6c90:	18600055 */ 	blez	$v1,.L0f0f6de8
/*  f0f6c94:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f6c98:
/*  f0f6c98:	8fac01ec */ 	lw	$t4,0x1ec($sp)
/*  f0f6c9c:	8fad01e4 */ 	lw	$t5,0x1e4($sp)
/*  f0f6ca0:	8fb801dc */ 	lw	$t8,0x1dc($sp)
/*  f0f6ca4:	91990004 */ 	lbu	$t9,0x4($t4)
/*  f0f6ca8:	8d8b0064 */ 	lw	$t3,0x64($t4)
/*  f0f6cac:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f0f6cb0:	032d8021 */ 	addu	$s0,$t9,$t5
/*  f0f6cb4:	00107080 */ 	sll	$t6,$s0,0x2
/*  f0f6cb8:	01d07021 */ 	addu	$t6,$t6,$s0
/*  f0f6cbc:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f0f6cc0:	030b8821 */ 	addu	$s1,$t8,$t3
/*  f0f6cc4:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0f6cc8:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f0f6ccc:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0f6cd0:	930b0668 */ 	lbu	$t3,0x668($t8)
/*  f0f6cd4:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f0f6cd8:	87b00196 */ 	lh	$s0,0x196($sp)
/*  f0f6cdc:	59600039 */ 	blezl	$t3,.L0f0f6dc4
/*  f0f6ce0:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f0f6ce4:	8fac0080 */ 	lw	$t4,0x80($sp)
.L0f0f6ce8:
/*  f0f6ce8:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*  f0f6cec:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f0f6cf0:	95990666 */ 	lhu	$t9,0x666($t4)
/*  f0f6cf4:	8fac01ec */ 	lw	$t4,0x1ec($sp)
/*  f0f6cf8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f6cfc:	032d1821 */ 	addu	$v1,$t9,$t5
/*  f0f6d00:	00037080 */ 	sll	$t6,$v1,0x2
/*  f0f6d04:	01ee2021 */ 	addu	$a0,$t7,$t6
/*  f0f6d08:	909804fe */ 	lbu	$t8,0x4fe($a0)
/*  f0f6d0c:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f0f6d10:	808204ff */ 	lb	$v0,0x4ff($a0)
/*  f0f6d14:	00185880 */ 	sll	$t3,$t8,0x2
/*  f0f6d18:	8f2d0008 */ 	lw	$t5,0x8($t9)
/*  f0f6d1c:	01785821 */ 	addu	$t3,$t3,$t8
/*  f0f6d20:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f6d24:	00004025 */ 	or	$t0,$zero,$zero
/*  f0f6d28:	afa4007c */ 	sw	$a0,0x7c($sp)
/*  f0f6d2c:	10410005 */ 	beq	$v0,$at,.L0f0f6d44
/*  f0f6d30:	016d4821 */ 	addu	$t1,$t3,$t5
/*  f0f6d34:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0f6d38:	01ee4021 */ 	addu	$t0,$t7,$t6
/*  f0f6d3c:	250806dc */ 	addiu	$t0,$t0,0x6dc
/*  f0f6d40:	afa4007c */ 	sw	$a0,0x7c($sp)
.L0f0f6d44:
/*  f0f6d44:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f0f6d48:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f0f6d4c:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f6d50:	87270660 */ 	lh	$a3,0x660($t9)
/*  f0f6d54:	856d04fc */ 	lh	$t5,0x4fc($t3)
/*  f0f6d58:	00102c00 */ 	sll	$a1,$s0,0x10
/*  f0f6d5c:	00113400 */ 	sll	$a2,$s1,0x10
/*  f0f6d60:	00066403 */ 	sra	$t4,$a2,0x10
/*  f0f6d64:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f0f6d68:	03002825 */ 	or	$a1,$t8,$zero
/*  f0f6d6c:	01803025 */ 	or	$a2,$t4,$zero
/*  f0f6d70:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0f6d74:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0f6d78:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6d7c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0f6d80:	0fc3c246 */ 	jal	func0f0f0918
/*  f0f6d84:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0f6d88:	8fac01c0 */ 	lw	$t4,0x1c0($sp)
/*  f0f6d8c:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0f6d90:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f0f6d94:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6d98:	85d804fc */ 	lh	$t8,0x4fc($t6)
/*  f0f6d9c:	25990001 */ 	addiu	$t9,$t4,0x1
/*  f0f6da0:	afb901c0 */ 	sw	$t9,0x1c0($sp)
/*  f0f6da4:	916d0668 */ 	lbu	$t5,0x668($t3)
/*  f0f6da8:	02388821 */ 	addu	$s1,$s1,$t8
/*  f0f6dac:	032d082a */ 	slt	$at,$t9,$t5
/*  f0f6db0:	5420ffcd */ 	bnezl	$at,.L0f0f6ce8
/*  f0f6db4:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f0f6db8:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f6dbc:	91e30005 */ 	lbu	$v1,0x5($t7)
/*  f0f6dc0:	8fb80080 */ 	lw	$t8,0x80($sp)
.L0f0f6dc4:
/*  f0f6dc4:	8fb901e4 */ 	lw	$t9,0x1e4($sp)
/*  f0f6dc8:	8fae0194 */ 	lw	$t6,0x194($sp)
/*  f0f6dcc:	870c0660 */ 	lh	$t4,0x660($t8)
/*  f0f6dd0:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f0f6dd4:	01a3082a */ 	slt	$at,$t5,$v1
/*  f0f6dd8:	01cc5821 */ 	addu	$t3,$t6,$t4
/*  f0f6ddc:	afad01e4 */ 	sw	$t5,0x1e4($sp)
/*  f0f6de0:	1420ffad */ 	bnez	$at,.L0f0f6c98
/*  f0f6de4:	afab0194 */ 	sw	$t3,0x194($sp)
.L0f0f6de8:
/*  f0f6de8:	0fc54e0e */ 	jal	func0f153838
/*  f0f6dec:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6df0:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6df4:	00402025 */ 	or	$a0,$v0,$zero
.L0f0f6df8:
/*  f0f6df8:	00809825 */ 	or	$s3,$a0,$zero
/*  f0f6dfc:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f6e00:	0c002f40 */ 	jal	func0000bd00
/*  f0f6e04:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f6e08:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6e0c:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0f6e10:	0c002f44 */ 	jal	func0000bd10
/*  f0f6e14:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0f6e18:	44829000 */ 	mtc1	$v0,$f18
/*  f0f6e1c:	44905000 */ 	mtc1	$s0,$f10
/*  f0f6e20:	3c014080 */ 	lui	$at,0x4080
/*  f0f6e24:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f6e28:	44810000 */ 	mtc1	$at,$f0
/*  f0f6e2c:	3c01ed00 */ 	lui	$at,0xed00
/*  f0f6e30:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0f6e34:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0f6e38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6e3c:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0f6e40:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0f6e44:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0f6e48:	440e4000 */ 	mfc1	$t6,$f8
/*  f0f6e4c:	440d2000 */ 	mfc1	$t5,$f4
/*  f0f6e50:	31cc0fff */ 	andi	$t4,$t6,0xfff
/*  f0f6e54:	01815825 */ 	or	$t3,$t4,$at
/*  f0f6e58:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f0f6e5c:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0f6e60:	01787025 */ 	or	$t6,$t3,$t8
/*  f0f6e64:	0c002f22 */ 	jal	func0000bc88
/*  f0f6e68:	ae6e0000 */ 	sw	$t6,0x0($s3)
/*  f0f6e6c:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f6e70:	00116403 */ 	sra	$t4,$s1,0x10
/*  f0f6e74:	0c002f40 */ 	jal	func0000bd00
/*  f0f6e78:	01808825 */ 	or	$s1,$t4,$zero
/*  f0f6e7c:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0f6e80:	0012cc03 */ 	sra	$t9,$s2,0x10
/*  f0f6e84:	0c002f44 */ 	jal	func0000bd10
/*  f0f6e88:	03209025 */ 	or	$s2,$t9,$zero
/*  f0f6e8c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6e90:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0f6e94:	0c002f26 */ 	jal	func0000bc98
/*  f0f6e98:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0f6e9c:	00507821 */ 	addu	$t7,$v0,$s0
/*  f0f6ea0:	448f3000 */ 	mtc1	$t7,$f6
/*  f0f6ea4:	02516021 */ 	addu	$t4,$s2,$s1
/*  f0f6ea8:	448c9000 */ 	mtc1	$t4,$f18
/*  f0f6eac:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f6eb0:	3c014080 */ 	lui	$at,0x4080
/*  f0f6eb4:	44810000 */ 	mtc1	$at,$f0
/*  f0f6eb8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f6ebc:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0f6ec0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6ec4:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0f6ec8:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0f6ecc:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0f6ed0:	44188000 */ 	mfc1	$t8,$f16
/*  f0f6ed4:	440d4000 */ 	mfc1	$t5,$f8
/*  f0f6ed8:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f0f6edc:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f0f6ee0:	000f5b00 */ 	sll	$t3,$t7,0xc
/*  f0f6ee4:	01cbc025 */ 	or	$t8,$t6,$t3
/*  f0f6ee8:	1000003e */ 	beqz	$zero,.L0f0f6fe4
/*  f0f6eec:	ae780004 */ 	sw	$t8,0x4($s3)
/*  f0f6ef0:	24840008 */ 	addiu	$a0,$a0,0x8
.L0f0f6ef4:
/*  f0f6ef4:	0c002f40 */ 	jal	func0000bd00
/*  f0f6ef8:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f6efc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6f00:	00106403 */ 	sra	$t4,$s0,0x10
/*  f0f6f04:	0c002f44 */ 	jal	func0000bd10
/*  f0f6f08:	01808025 */ 	or	$s0,$t4,$zero
/*  f0f6f0c:	44825000 */ 	mtc1	$v0,$f10
/*  f0f6f10:	44903000 */ 	mtc1	$s0,$f6
/*  f0f6f14:	3c014080 */ 	lui	$at,0x4080
/*  f0f6f18:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0f6f1c:	44810000 */ 	mtc1	$at,$f0
/*  f0f6f20:	3c01ed00 */ 	lui	$at,0xed00
/*  f0f6f24:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f6f28:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0f6f2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6f30:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0f6f34:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0f6f38:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0f6f3c:	440d2000 */ 	mfc1	$t5,$f4
/*  f0f6f40:	44188000 */ 	mfc1	$t8,$f16
/*  f0f6f44:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f0f6f48:	01e17025 */ 	or	$t6,$t7,$at
/*  f0f6f4c:	330c0fff */ 	andi	$t4,$t8,0xfff
/*  f0f6f50:	000ccb00 */ 	sll	$t9,$t4,0xc
/*  f0f6f54:	01d96825 */ 	or	$t5,$t6,$t9
/*  f0f6f58:	0c002f22 */ 	jal	func0000bc88
/*  f0f6f5c:	ae6d0000 */ 	sw	$t5,0x0($s3)
/*  f0f6f60:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f6f64:	00117c03 */ 	sra	$t7,$s1,0x10
/*  f0f6f68:	0c002f40 */ 	jal	func0000bd00
/*  f0f6f6c:	01e08825 */ 	or	$s1,$t7,$zero
/*  f0f6f70:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0f6f74:	00125c03 */ 	sra	$t3,$s2,0x10
/*  f0f6f78:	0c002f44 */ 	jal	func0000bd10
/*  f0f6f7c:	01609025 */ 	or	$s2,$t3,$zero
/*  f0f6f80:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6f84:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f0f6f88:	0c002f26 */ 	jal	func0000bc98
/*  f0f6f8c:	03008025 */ 	or	$s0,$t8,$zero
/*  f0f6f90:	00506021 */ 	addu	$t4,$v0,$s0
/*  f0f6f94:	448c9000 */ 	mtc1	$t4,$f18
/*  f0f6f98:	02517821 */ 	addu	$t7,$s2,$s1
/*  f0f6f9c:	448f8000 */ 	mtc1	$t7,$f16
/*  f0f6fa0:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f6fa4:	3c014080 */ 	lui	$at,0x4080
/*  f0f6fa8:	44813000 */ 	mtc1	$at,$f6
/*  f0f6fac:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0f6fb0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0f6fb4:	44812000 */ 	mtc1	$at,$f4
/*  f0f6fb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f6fbc:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0f6fc0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0f6fc4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0f6fc8:	44195000 */ 	mfc1	$t9,$f10
/*  f0f6fcc:	44184000 */ 	mfc1	$t8,$f8
/*  f0f6fd0:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f0f6fd4:	330c0fff */ 	andi	$t4,$t8,0xfff
/*  f0f6fd8:	000c7300 */ 	sll	$t6,$t4,0xc
/*  f0f6fdc:	01aec825 */ 	or	$t9,$t5,$t6
/*  f0f6fe0:	ae790004 */ 	sw	$t9,0x4($s3)
.L0f0f6fe4:
/*  f0f6fe4:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0f6fe8:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f0f6fec:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0f6ff0:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0f6ff4:	000f58c0 */ 	sll	$t3,$t7,0x3
/*  f0f6ff8:	016f5823 */ 	subu	$t3,$t3,$t7
/*  f0f6ffc:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f7000:	016f5821 */ 	addu	$t3,$t3,$t7
/*  f0f7004:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0f7008:	016f5823 */ 	subu	$t3,$t3,$t7
/*  f0f700c:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f0f7010:	01781821 */ 	addu	$v1,$t3,$t8
/*  f0f7014:	846c04f4 */ 	lh	$t4,0x4f4($v1)
/*  f0f7018:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f701c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0f7020:	91d9003c */ 	lbu	$t9,0x3c($t6)
/*  f0f7024:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f7028:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0f702c:	006d8821 */ 	addu	$s1,$v1,$t5
/*  f0f7030:	17200006 */ 	bnez	$t9,.L0f0f704c
/*  f0f7034:	2631044c */ 	addiu	$s1,$s1,0x44c
/*  f0f7038:	c5ca0040 */ 	lwc1	$f10,0x40($t6)
/*  f0f703c:	460aa03e */ 	c.le.s	$f20,$f10
/*  f0f7040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7044:	4502010b */ 	bc1fl	.L0f0f7474
/*  f0f7048:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f704c:
/*  f0f704c:	822b0015 */ 	lb	$t3,0x15($s1)
/*  f0f7050:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f7054:	000bc080 */ 	sll	$t8,$t3,0x2
/*  f0f7058:	02386021 */ 	addu	$t4,$s1,$t8
/*  f0f705c:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f0f7060:	55ed0104 */ 	bnel	$t7,$t5,.L0f0f7474
/*  f0f7064:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f7068:	82390014 */ 	lb	$t9,0x14($s1)
/*  f0f706c:	2b210002 */ 	slti	$at,$t9,0x2
/*  f0f7070:	142000ff */ 	bnez	$at,.L0f0f7470
/*  f0f7074:	3c014120 */ 	lui	$at,0x4120
/*  f0f7078:	44816000 */ 	mtc1	$at,$f12
/*  f0f707c:	0fc01ac2 */ 	jal	func0f006b08
/*  f0f7080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7084:	3c01437f */ 	lui	$at,0x437f
/*  f0f7088:	44818000 */ 	mtc1	$at,$f16
/*  f0f708c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0f7090:	3c014f00 */ 	lui	$at,0x4f00
/*  f0f7094:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f0f7098:	8fab01ec */ 	lw	$t3,0x1ec($sp)
/*  f0f709c:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f70a0:	444ef800 */ 	cfc1	$t6,$31
/*  f0f70a4:	44d0f800 */ 	ctc1	$s0,$31
/*  f0f70a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f70ac:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f0f70b0:	4450f800 */ 	cfc1	$s0,$31
/*  f0f70b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f70b8:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0f70bc:	52000013 */ 	beqzl	$s0,.L0f0f710c
/*  f0f70c0:	44102000 */ 	mfc1	$s0,$f4
/*  f0f70c4:	44812000 */ 	mtc1	$at,$f4
/*  f0f70c8:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0f70cc:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f0f70d0:	44d0f800 */ 	ctc1	$s0,$31
/*  f0f70d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f70d8:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0f70dc:	4450f800 */ 	cfc1	$s0,$31
/*  f0f70e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f70e4:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0f70e8:	16000005 */ 	bnez	$s0,.L0f0f7100
/*  f0f70ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f70f0:	44102000 */ 	mfc1	$s0,$f4
/*  f0f70f4:	3c018000 */ 	lui	$at,0x8000
/*  f0f70f8:	10000007 */ 	beqz	$zero,.L0f0f7118
/*  f0f70fc:	02018025 */ 	or	$s0,$s0,$at
.L0f0f7100:
/*  f0f7100:	10000005 */ 	beqz	$zero,.L0f0f7118
/*  f0f7104:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f0f7108:	44102000 */ 	mfc1	$s0,$f4
.L0f0f710c:
/*  f0f710c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7110:	0600fffb */ 	bltz	$s0,.L0f0f7100
/*  f0f7114:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f7118:
/*  f0f7118:	44cef800 */ 	ctc1	$t6,$31
/*  f0f711c:	c5660040 */ 	lwc1	$f6,0x40($t3)
/*  f0f7120:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0f7124:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7128:	4502000a */ 	bc1fl	.L0f0f7154
/*  f0f712c:	91ed003d */ 	lbu	$t5,0x3d($t7)
/*  f0f7130:	9178003c */ 	lbu	$t8,0x3c($t3)
/*  f0f7134:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0f7138:	00186100 */ 	sll	$t4,$t8,0x4
/*  f0f713c:	01986023 */ 	subu	$t4,$t4,$t8
/*  f0f7140:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f7144:	00ac2821 */ 	addu	$a1,$a1,$t4
/*  f0f7148:	10000011 */ 	beqz	$zero,.L0f0f7190
/*  f0f714c:	8ca51fb0 */ 	lw	$a1,0x1fb0($a1)
/*  f0f7150:	91ed003d */ 	lbu	$t5,0x3d($t7)
.L0f0f7154:
/*  f0f7154:	2402003c */ 	addiu	$v0,$zero,0x3c
/*  f0f7158:	91eb003c */ 	lbu	$t3,0x3c($t7)
/*  f0f715c:	01a20019 */ 	multu	$t5,$v0
/*  f0f7160:	3c037f1b */ 	lui	$v1,0x7f1b
/*  f0f7164:	24631fb0 */ 	addiu	$v1,$v1,0x1fb0
/*  f0f7168:	8de60044 */ 	lw	$a2,0x44($t7)
/*  f0f716c:	0000c812 */ 	mflo	$t9
/*  f0f7170:	00797021 */ 	addu	$t6,$v1,$t9
/*  f0f7174:	8dc40000 */ 	lw	$a0,0x0($t6)
/*  f0f7178:	01620019 */ 	multu	$t3,$v0
/*  f0f717c:	0000c012 */ 	mflo	$t8
/*  f0f7180:	00786021 */ 	addu	$t4,$v1,$t8
/*  f0f7184:	0fc01a40 */ 	jal	func0f006900
/*  f0f7188:	8d850000 */ 	lw	$a1,0x0($t4)
/*  f0f718c:	00402825 */ 	or	$a1,$v0,$zero
.L0f0f7190:
/*  f0f7190:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0f7194:	0fc01a40 */ 	jal	func0f006900
/*  f0f7198:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f719c:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0f71a0:	4481a000 */ 	mtc1	$at,$f20
/*  f0f71a4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f71a8:	0fc01ac2 */ 	jal	func0f006b08
/*  f0f71ac:	4600a306 */ 	mov.s	$f12,$f20
/*  f0f71b0:	8fad01dc */ 	lw	$t5,0x1dc($sp)
/*  f0f71b4:	8fb901d4 */ 	lw	$t9,0x1d4($sp)
/*  f0f71b8:	8fa501e0 */ 	lw	$a1,0x1e0($sp)
/*  f0f71bc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f71c0:	01b9a821 */ 	addu	$s5,$t5,$t9
/*  f0f71c4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f71c8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f71cc:	24070009 */ 	addiu	$a3,$zero,0x9
/*  f0f71d0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f71d4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f71d8:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0f71dc:	24a5fffb */ 	addiu	$a1,$a1,-5
/*  f0f71e0:	06a10003 */ 	bgez	$s5,.L0f0f71f0
/*  f0f71e4:	0015a043 */ 	sra	$s4,$s5,0x1
/*  f0f71e8:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f0f71ec:	0001a043 */ 	sra	$s4,$at,0x1
.L0f0f71f0:
/*  f0f71f0:	0fc38cc9 */ 	jal	func0f0e3324
/*  f0f71f4:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f71f8:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f71fc:	0fc01ac2 */ 	jal	func0f006b08
/*  f0f7200:	4600a306 */ 	mov.s	$f12,$f20
/*  f0f7204:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0f7208:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f0f720c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f7210:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f7214:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f7218:	24070009 */ 	addiu	$a3,$zero,0x9
/*  f0f721c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f7220:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f7224:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0f7228:	0fc38cc9 */ 	jal	func0f0e3324
/*  f0f722c:	24a50005 */ 	addiu	$a1,$a1,0x5
/*  f0f7230:	3c03800a */ 	lui	$v1,0x800a
/*  f0f7234:	8c6319c4 */ 	lw	$v1,0x19c4($v1)
/*  f0f7238:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f723c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f7240:	10610007 */ 	beq	$v1,$at,.L0f0f7260
/*  f0f7244:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0f7248:	10610005 */ 	beq	$v1,$at,.L0f0f7260
/*  f0f724c:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f7250:	10610003 */ 	beq	$v1,$at,.L0f0f7260
/*  f0f7254:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f7258:	54610086 */ 	bnel	$v1,$at,.L0f0f7474
/*  f0f725c:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f7260:
/*  f0f7260:	0fc54f93 */ 	jal	func0f153e4c
/*  f0f7264:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7268:	0fc54c6e */ 	jal	func0f1531b8
/*  f0f726c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f7270:	0fc54d8a */ 	jal	func0f153628
/*  f0f7274:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f7278:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f727c:	82230015 */ 	lb	$v1,0x15($s1)
/*  f0f7280:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0f7284:	04630004 */ 	bgezl	$v1,.L0f0f7298
/*  f0f7288:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0f728c:	82230014 */ 	lb	$v1,0x14($s1)
/*  f0f7290:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0f7294:	0003c080 */ 	sll	$t8,$v1,0x2
.L0f0f7298:
/*  f0f7298:	02386021 */ 	addu	$t4,$s1,$t8
/*  f0f729c:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f0f72a0:	0fc3c560 */ 	jal	func0f0f1580
/*  f0f72a4:	8de40000 */ 	lw	$a0,0x0($t7)
/*  f0f72a8:	3c138008 */ 	lui	$s3,%hi(var8007fb04)
/*  f0f72ac:	2673fb04 */ 	addiu	$s3,$s3,%lo(var8007fb04)
/*  f0f72b0:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f0f72b4:	3c128008 */ 	lui	$s2,%hi(var8007fb08)
/*  f0f72b8:	2652fb08 */ 	addiu	$s2,$s2,%lo(var8007fb08)
/*  f0f72bc:	27b600b0 */ 	addiu	$s6,$sp,0xb0
/*  f0f72c0:	27b700ac */ 	addiu	$s7,$sp,0xac
/*  f0f72c4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f72c8:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0f72cc:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0f72d0:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f0f72d4:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f72d8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f72dc:	0fc55cbe */ 	jal	func0f1572f8
/*  f0f72e0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0f72e4:	8fa200ac */ 	lw	$v0,0xac($sp)
/*  f0f72e8:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f72ec:	8fb901dc */ 	lw	$t9,0x1dc($sp)
/*  f0f72f0:	02822823 */ 	subu	$a1,$s4,$v0
/*  f0f72f4:	24a5fffd */ 	addiu	$a1,$a1,-3
/*  f0f72f8:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0f72fc:	00b9082a */ 	slt	$at,$a1,$t9
/*  f0f7300:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f7304:	10200009 */ 	beqz	$at,.L0f0f732c
/*  f0f7308:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f0f730c:	02a22823 */ 	subu	$a1,$s5,$v0
/*  f0f7310:	04a10003 */ 	bgez	$a1,.L0f0f7320
/*  f0f7314:	00057043 */ 	sra	$t6,$a1,0x1
/*  f0f7318:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f0f731c:	00017043 */ 	sra	$t6,$at,0x1
.L0f0f7320:
/*  f0f7320:	2463fffd */ 	addiu	$v1,$v1,-3
/*  f0f7324:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f7328:	afae01cc */ 	sw	$t6,0x1cc($sp)
.L0f0f732c:
/*  f0f732c:	0c002f06 */ 	jal	func0000bc18
/*  f0f7330:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7334:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f0f7338:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0f733c:	87af01ca */ 	lh	$t7,0x1ca($sp)
/*  f0f7340:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0f7344:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0f7348:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f734c:	27a501cc */ 	addiu	$a1,$sp,0x1cc
/*  f0f7350:	27a601d0 */ 	addiu	$a2,$sp,0x1d0
/*  f0f7354:	02003825 */ 	or	$a3,$s0,$zero
/*  f0f7358:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f735c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f7360:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f7364:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f7368:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f736c:	0fc5580f */ 	jal	func0f15603c
/*  f0f7370:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f7374:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f7378:	82230015 */ 	lb	$v1,0x15($s1)
/*  f0f737c:	822d0014 */ 	lb	$t5,0x14($s1)
/*  f0f7380:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f7384:	006d082a */ 	slt	$at,$v1,$t5
/*  f0f7388:	54200003 */ 	bnezl	$at,.L0f0f7398
/*  f0f738c:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f0f7390:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f7394:	0003c880 */ 	sll	$t9,$v1,0x2
.L0f0f7398:
/*  f0f7398:	02397021 */ 	addu	$t6,$s1,$t9
/*  f0f739c:	8dcb0000 */ 	lw	$t3,0x0($t6)
/*  f0f73a0:	0fc3c560 */ 	jal	func0f0f1580
/*  f0f73a4:	8d640000 */ 	lw	$a0,0x0($t3)
/*  f0f73a8:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0f73ac:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f73b0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0f73b4:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0f73b8:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f73bc:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f0f73c0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f73c4:	0fc55cbe */ 	jal	func0f1572f8
/*  f0f73c8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f73cc:	8fa200ac */ 	lw	$v0,0xac($sp)
/*  f0f73d0:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f0f73d4:	8fac01d4 */ 	lw	$t4,0x1d4($sp)
/*  f0f73d8:	26850003 */ 	addiu	$a1,$s4,0x3
/*  f0f73dc:	00a27821 */ 	addu	$t7,$a1,$v0
/*  f0f73e0:	24630007 */ 	addiu	$v1,$v1,0x7
/*  f0f73e4:	018f082a */ 	slt	$at,$t4,$t7
/*  f0f73e8:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f73ec:	10200009 */ 	beqz	$at,.L0f0f7414
/*  f0f73f0:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f0f73f4:	02a22823 */ 	subu	$a1,$s5,$v0
/*  f0f73f8:	04a10003 */ 	bgez	$a1,.L0f0f7408
/*  f0f73fc:	00056843 */ 	sra	$t5,$a1,0x1
/*  f0f7400:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f0f7404:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f7408:
/*  f0f7408:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0f740c:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f7410:	afad01cc */ 	sw	$t5,0x1cc($sp)
.L0f0f7414:
/*  f0f7414:	0c002f06 */ 	jal	func0000bc18
/*  f0f7418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f741c:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f0f7420:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0f7424:	87b801ca */ 	lh	$t8,0x1ca($sp)
/*  f0f7428:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0f742c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f7430:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f7434:	27a501cc */ 	addiu	$a1,$sp,0x1cc
/*  f0f7438:	27a601d0 */ 	addiu	$a2,$sp,0x1d0
/*  f0f743c:	02003825 */ 	or	$a3,$s0,$zero
/*  f0f7440:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f7444:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f7448:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f744c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f7450:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0f7454:	0fc5580f */ 	jal	func0f15603c
/*  f0f7458:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0f745c:	0fc54de0 */ 	jal	func0f153780
/*  f0f7460:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f7464:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f7468:	0fc54c6e */ 	jal	func0f1531b8
/*  f0f746c:	00002025 */ 	or	$a0,$zero,$zero
.L0f0f7470:
/*  f0f7470:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f7474:
/*  f0f7474:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0f7478:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f0f747c:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f0f7480:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f0f7484:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f0f7488:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f0f748c:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f0f7490:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f0f7494:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f0f7498:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*  f0f749c:	8fbe0060 */ 	lw	$s8,0x60($sp)
/*  f0f74a0:	03e00008 */ 	jr	$ra
/*  f0f74a4:	27bd01e8 */ 	addiu	$sp,$sp,0x1e8
);

GLOBAL_ASM(
glabel func0f0f74a8
/*  f0f74a8:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f74ac:	8dce19c4 */ 	lw	$t6,0x19c4($t6)
/*  f0f74b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f74b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f74b8:	25cffffd */ 	addiu	$t7,$t6,-3
/*  f0f74bc:	2de10009 */ 	sltiu	$at,$t7,0x9
/*  f0f74c0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0f74c4:	1020000e */ 	beqz	$at,.L0f0f7500
/*  f0f74c8:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f74cc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f74d0:	3c017f1b */ 	lui	$at,%hi(var7f1b294c)
/*  f0f74d4:	002f0821 */ 	addu	$at,$at,$t7
/*  f0f74d8:	8c2f294c */ 	lw	$t7,%lo(var7f1b294c)($at)
/*  f0f74dc:	01e00008 */ 	jr	$t7
/*  f0f74e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f74e4:	3c188007 */ 	lui	$t8,0x8007
/*  f0f74e8:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f0f74ec:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f74f0:	a0d80000 */ 	sb	$t8,0x0($a2)
/*  f0f74f4:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f0f74f8:	10000022 */ 	beqz	$zero,.L0f0f7584
/*  f0f74fc:	a1190000 */ 	sb	$t9,0x0($t0)
.L0f0f7500:
/*  f0f7500:	3c09800a */ 	lui	$t1,0x800a
/*  f0f7504:	8d29a248 */ 	lw	$t1,-0x5db8($t1)
/*  f0f7508:	8d240070 */ 	lw	$a0,0x70($t1)
/*  f0f750c:	0fc549d2 */ 	jal	optionsGetUnk45
/*  f0f7510:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f0f7514:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f0f7518:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f751c:	240affff */ 	addiu	$t2,$zero,-1
/*  f0f7520:	a0c20000 */ 	sb	$v0,0x0($a2)
/*  f0f7524:	8fab001c */ 	lw	$t3,0x1c($sp)
/*  f0f7528:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0f752c:	a16a0000 */ 	sb	$t2,0x0($t3)
/*  f0f7530:	8c6c0318 */ 	lw	$t4,0x318($v1)
/*  f0f7534:	55800014 */ 	bnezl	$t4,.L0f0f7588
/*  f0f7538:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f753c:	8c6d0288 */ 	lw	$t5,0x288($v1)
/*  f0f7540:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f0f7544:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0f7548:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f754c:	10410008 */ 	beq	$v0,$at,.L0f0f7570
/*  f0f7550:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f7554:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0f7558:	10410005 */ 	beq	$v0,$at,.L0f0f7570
/*  f0f755c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f7560:	10410003 */ 	beq	$v0,$at,.L0f0f7570
/*  f0f7564:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f7568:	54410007 */ 	bnel	$v0,$at,.L0f0f7588
/*  f0f756c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f7570:
/*  f0f7570:	8dcea248 */ 	lw	$t6,-0x5db8($t6)
/*  f0f7574:	0fc549d9 */ 	jal	optionsGetUnk46
/*  f0f7578:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0f757c:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f0f7580:	a1e20000 */ 	sb	$v0,0x0($t7)
.L0f0f7584:
/*  f0f7584:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f7588:
/*  f0f7588:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f758c:	03e00008 */ 	jr	$ra
/*  f0f7590:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f7594
/*  f0f7594:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f7598:	8dce19c4 */ 	lw	$t6,0x19c4($t6)
/*  f0f759c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f75a0:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0f75a4:	55c1005d */ 	bnel	$t6,$at,.L0f0f771c
/*  f0f75a8:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f0f75ac:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f0f75b0:	3c02800a */ 	lui	$v0,0x800a
/*  f0f75b4:	3c038007 */ 	lui	$v1,0x8007
/*  f0f75b8:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f75bc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f75c0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f75c4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f75c8:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f75cc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f75d0:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f75d4:	00581021 */ 	addu	$v0,$v0,$t8
/*  f0f75d8:	9042e83b */ 	lbu	$v0,-0x17c5($v0)
/*  f0f75dc:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f0f75e0:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f0f75e4:	8c6314d8 */ 	lw	$v1,0x14d8($v1)
/*  f0f75e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f75ec:	10610009 */ 	beq	$v1,$at,.L0f0f7614
/*  f0f75f0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f75f4:	10610009 */ 	beq	$v1,$at,.L0f0f761c
/*  f0f75f8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f75fc:	10610017 */ 	beq	$v1,$at,.L0f0f765c
/*  f0f7600:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f7604:	1061002a */ 	beq	$v1,$at,.L0f0f76b0
/*  f0f7608:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f760c:	03e00008 */ 	jr	$ra
/*  f0f7610:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f7614:
/*  f0f7614:	03e00008 */ 	jr	$ra
/*  f0f7618:	acc40000 */ 	sw	$a0,0x0($a2)
.L0f0f761c:
/*  f0f761c:	14400008 */ 	bnez	$v0,.L0f0f7640
/*  f0f7620:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7624:	04810004 */ 	bgez	$a0,.L0f0f7638
/*  f0f7628:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0f762c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f7630:	03e00008 */ 	jr	$ra
/*  f0f7634:	acd90000 */ 	sw	$t9,0x0($a2)
.L0f0f7638:
/*  f0f7638:	03e00008 */ 	jr	$ra
/*  f0f763c:	aca80000 */ 	sw	$t0,0x0($a1)
.L0f0f7640:
/*  f0f7640:	18800004 */ 	blez	$a0,.L0f0f7654
/*  f0f7644:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f7648:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f764c:	03e00008 */ 	jr	$ra
/*  f0f7650:	acc30000 */ 	sw	$v1,0x0($a2)
.L0f0f7654:
/*  f0f7654:	03e00008 */ 	jr	$ra
/*  f0f7658:	aca30000 */ 	sw	$v1,0x0($a1)
.L0f0f765c:
/*  f0f765c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7660:	14410003 */ 	bne	$v0,$at,.L0f0f7670
/*  f0f7664:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7668:	03e00008 */ 	jr	$ra
/*  f0f766c:	acc40000 */ 	sw	$a0,0x0($a2)
.L0f0f7670:
/*  f0f7670:	14400008 */ 	bnez	$v0,.L0f0f7694
/*  f0f7674:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7678:	04810004 */ 	bgez	$a0,.L0f0f768c
/*  f0f767c:	240affff */ 	addiu	$t2,$zero,-1
/*  f0f7680:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0f7684:	03e00008 */ 	jr	$ra
/*  f0f7688:	acc90000 */ 	sw	$t1,0x0($a2)
.L0f0f768c:
/*  f0f768c:	03e00008 */ 	jr	$ra
/*  f0f7690:	acaa0000 */ 	sw	$t2,0x0($a1)
.L0f0f7694:
/*  f0f7694:	18800004 */ 	blez	$a0,.L0f0f76a8
/*  f0f7698:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0f769c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f76a0:	03e00008 */ 	jr	$ra
/*  f0f76a4:	acc30000 */ 	sw	$v1,0x0($a2)
.L0f0f76a8:
/*  f0f76a8:	03e00008 */ 	jr	$ra
/*  f0f76ac:	acab0000 */ 	sw	$t3,0x0($a1)
.L0f0f76b0:
/*  f0f76b0:	10400003 */ 	beqz	$v0,.L0f0f76c0
/*  f0f76b4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f76b8:	1441000c */ 	bne	$v0,$at,.L0f0f76ec
/*  f0f76bc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f76c0:
/*  f0f76c0:	04810003 */ 	bgez	$a0,.L0f0f76d0
/*  f0f76c4:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0f76c8:	03e00008 */ 	jr	$ra
/*  f0f76cc:	accc0000 */ 	sw	$t4,0x0($a2)
.L0f0f76d0:
/*  f0f76d0:	14400004 */ 	bnez	$v0,.L0f0f76e4
/*  f0f76d4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f76d8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0f76dc:	03e00008 */ 	jr	$ra
/*  f0f76e0:	acad0000 */ 	sw	$t5,0x0($a1)
.L0f0f76e4:
/*  f0f76e4:	03e00008 */ 	jr	$ra
/*  f0f76e8:	aca30000 */ 	sw	$v1,0x0($a1)
.L0f0f76ec:
/*  f0f76ec:	18800004 */ 	blez	$a0,.L0f0f7700
/*  f0f76f0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f76f4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f76f8:	03e00008 */ 	jr	$ra
/*  f0f76fc:	acc30000 */ 	sw	$v1,0x0($a2)
.L0f0f7700:
/*  f0f7700:	14430003 */ 	bne	$v0,$v1,.L0f0f7710
/*  f0f7704:	240effff */ 	addiu	$t6,$zero,-1
/*  f0f7708:	03e00008 */ 	jr	$ra
/*  f0f770c:	acae0000 */ 	sw	$t6,0x0($a1)
.L0f0f7710:
/*  f0f7710:	03e00008 */ 	jr	$ra
/*  f0f7714:	aca30000 */ 	sw	$v1,0x0($a1)
/*  f0f7718:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f0f771c:
/*  f0f771c:	acc40000 */ 	sw	$a0,0x0($a2)
/*  f0f7720:	03e00008 */ 	jr	$ra
/*  f0f7724:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f7728
/*  f0f7728:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0f772c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f7730:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0f7734:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0f7738:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0f773c:	0c002f40 */ 	jal	func0000bd00
/*  f0f7740:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f0f7744:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0f7748:	8dcefac0 */ 	lw	$t6,-0x540($t6)
/*  f0f774c:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f0f7750:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f7754:	004e001a */ 	div	$zero,$v0,$t6
/*  f0f7758:	00003012 */ 	mflo	$a2
/*  f0f775c:	24c60014 */ 	addiu	$a2,$a2,0x14
/*  f0f7760:	15c00002 */ 	bnez	$t6,.L0f0f776c
/*  f0f7764:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7768:	0007000d */ 	break	0x7
.L0f0f776c:
/*  f0f776c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f7770:	15c10004 */ 	bne	$t6,$at,.L0f0f7784
/*  f0f7774:	3c018000 */ 	lui	$at,0x8000
/*  f0f7778:	14410002 */ 	bne	$v0,$at,.L0f0f7784
/*  f0f777c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7780:	0006000d */ 	break	0x6
.L0f0f7784:
/*  f0f7784:	afa60034 */ 	sw	$a2,0x34($sp)
/*  f0f7788:	0c002f44 */ 	jal	func0000bd10
/*  f0f778c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7790:	24430004 */ 	addiu	$v1,$v0,0x4
/*  f0f7794:	0c002f40 */ 	jal	func0000bd00
/*  f0f7798:	afa30030 */ 	sw	$v1,0x30($sp)
/*  f0f779c:	0c002f22 */ 	jal	func0000bc88
/*  f0f77a0:	a7a2001a */ 	sh	$v0,0x1a($sp)
/*  f0f77a4:	87af001a */ 	lh	$t7,0x1a($sp)
/*  f0f77a8:	3c198008 */ 	lui	$t9,0x8008
/*  f0f77ac:	8f39fac0 */ 	lw	$t9,-0x540($t9)
/*  f0f77b0:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0f77b4:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f0f77b8:	0319001a */ 	div	$zero,$t8,$t9
/*  f0f77bc:	00003812 */ 	mflo	$a3
/*  f0f77c0:	24e7ffec */ 	addiu	$a3,$a3,-20
/*  f0f77c4:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0f77c8:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f0f77cc:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f77d0:	17200002 */ 	bnez	$t9,.L0f0f77dc
/*  f0f77d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f77d8:	0007000d */ 	break	0x7
.L0f0f77dc:
/*  f0f77dc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f77e0:	17210004 */ 	bne	$t9,$at,.L0f0f77f4
/*  f0f77e4:	3c018000 */ 	lui	$at,0x8000
/*  f0f77e8:	17010002 */ 	bne	$t8,$at,.L0f0f77f4
/*  f0f77ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f77f0:	0006000d */ 	break	0x6
.L0f0f77f4:
/*  f0f77f4:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f0f77f8:	0c002f44 */ 	jal	func0000bd10
/*  f0f77fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7800:	0c002f26 */ 	jal	func0000bc98
/*  f0f7804:	a7a2001a */ 	sh	$v0,0x1a($sp)
/*  f0f7808:	87ae001a */ 	lh	$t6,0x1a($sp)
/*  f0f780c:	004e2021 */ 	addu	$a0,$v0,$t6
/*  f0f7810:	2484fffc */ 	addiu	$a0,$a0,-4
/*  f0f7814:	0fc3c2fb */ 	jal	func0f0f0bec
/*  f0f7818:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f0f781c:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f0f7820:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f0f7824:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0f7828:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f0f782c:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f0f7830:	10400011 */ 	beqz	$v0,.L0f0f7878
/*  f0f7834:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f7838:	24630016 */ 	addiu	$v1,$v1,0x16
/*  f0f783c:	afa30030 */ 	sw	$v1,0x30($sp)
/*  f0f7840:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f0f7844:	afa60034 */ 	sw	$a2,0x34($sp)
/*  f0f7848:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0f784c:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f0f7850:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7854:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f0f7858:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f0f785c:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0f7860:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f0f7864:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f0f7868:	14410003 */ 	bne	$v0,$at,.L0f0f7878
/*  f0f786c:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f7870:	2463fff8 */ 	addiu	$v1,$v1,-8
/*  f0f7874:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f0f7878:
/*  f0f7878:	3c02800a */ 	lui	$v0,%hi(var800a19c0)
/*  f0f787c:	244219c0 */ 	addiu	$v0,$v0,%lo(var800a19c0)
/*  f0f7880:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f0f7884:	25f8fffd */ 	addiu	$t8,$t7,-3
/*  f0f7888:	2f010009 */ 	sltiu	$at,$t8,0x9
/*  f0f788c:	10200178 */ 	beqz	$at,.L0f0f7e70
/*  f0f7890:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f7894:	3c017f1b */ 	lui	$at,%hi(var7f1b2970)
/*  f0f7898:	00380821 */ 	addu	$at,$at,$t8
/*  f0f789c:	8c382970 */ 	lw	$t8,%lo(var7f1b2970)($at)
/*  f0f78a0:	03000008 */ 	jr	$t8
/*  f0f78a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f78a8:	3c1f8007 */ 	lui	$ra,0x8007
/*  f0f78ac:	27ff1448 */ 	addiu	$ra,$ra,0x1448
/*  f0f78b0:	8ff90000 */ 	lw	$t9,0x0($ra)
/*  f0f78b4:	90580017 */ 	lbu	$t8,0x17($v0)
/*  f0f78b8:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f0f78bc:	001970c0 */ 	sll	$t6,$t9,0x3
/*  f0f78c0:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f78c4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f78c8:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f0f78cc:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f78d0:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f78d4:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f0f78d8:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f78dc:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0f78e0:	1f000004 */ 	bgtz	$t8,.L0f0f78f4
/*  f0f78e4:	91e5083b */ 	lbu	$a1,0x83b($t7)
/*  f0f78e8:	90590018 */ 	lbu	$t9,0x18($v0)
/*  f0f78ec:	5b200003 */ 	blezl	$t9,.L0f0f78fc
/*  f0f78f0:	904e0019 */ 	lbu	$t6,0x19($v0)
.L0f0f78f4:
/*  f0f78f4:	2463000a */ 	addiu	$v1,$v1,0xa
/*  f0f78f8:	904e0019 */ 	lbu	$t6,0x19($v0)
.L0f0f78fc:
/*  f0f78fc:	5dc00005 */ 	bgtzl	$t6,.L0f0f7914
/*  f0f7900:	2484fff6 */ 	addiu	$a0,$a0,-10
/*  f0f7904:	904f001a */ 	lbu	$t7,0x1a($v0)
/*  f0f7908:	19e00002 */ 	blez	$t7,.L0f0f7914
/*  f0f790c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7910:	2484fff6 */ 	addiu	$a0,$a0,-10
.L0f0f7914:
/*  f0f7914:	3c028007 */ 	lui	$v0,0x8007
/*  f0f7918:	8c4214d8 */ 	lw	$v0,0x14d8($v0)
/*  f0f791c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f7920:	1041000a */ 	beq	$v0,$at,.L0f0f794c
/*  f0f7924:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7928:	1041000f */ 	beq	$v0,$at,.L0f0f7968
/*  f0f792c:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0f7930:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f7934:	10410020 */ 	beq	$v0,$at,.L0f0f79b8
/*  f0f7938:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f793c:	10410047 */ 	beq	$v0,$at,.L0f0f7a5c
/*  f0f7940:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7944:	10000151 */ 	beqz	$zero,.L0f0f7e8c
/*  f0f7948:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f794c:
/*  f0f794c:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f7950:	ad870000 */ 	sw	$a3,0x0($t4)
/*  f0f7954:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0f7958:	af030000 */ 	sw	$v1,0x0($t8)
/*  f0f795c:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0f7960:	10000149 */ 	beqz	$zero,.L0f0f7e88
/*  f0f7964:	af240000 */ 	sw	$a0,0x0($t9)
.L0f0f7968:
/*  f0f7968:	adc30000 */ 	sw	$v1,0x0($t6)
/*  f0f796c:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7970:	00c77021 */ 	addu	$t6,$a2,$a3
/*  f0f7974:	14a00009 */ 	bnez	$a1,.L0f0f799c
/*  f0f7978:	ade40000 */ 	sw	$a0,0x0($t7)
/*  f0f797c:	00c7c021 */ 	addu	$t8,$a2,$a3
/*  f0f7980:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f7984:	07010003 */ 	bgez	$t8,.L0f0f7994
/*  f0f7988:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f798c:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f7990:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f7994:
/*  f0f7994:	1000013c */ 	beqz	$zero,.L0f0f7e88
/*  f0f7998:	ad990000 */ 	sw	$t9,0x0($t4)
.L0f0f799c:
/*  f0f799c:	05c10003 */ 	bgez	$t6,.L0f0f79ac
/*  f0f79a0:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f0f79a4:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f0f79a8:	00017843 */ 	sra	$t7,$at,0x1
.L0f0f79ac:
/*  f0f79ac:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0f79b0:	10000135 */ 	beqz	$zero,.L0f0f7e88
/*  f0f79b4:	ad870000 */ 	sw	$a3,0x0($t4)
.L0f0f79b8:
/*  f0f79b8:	10a00003 */ 	beqz	$a1,.L0f0f79c8
/*  f0f79bc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f79c0:	14a8001b */ 	bne	$a1,$t0,.L0f0f7a30
/*  f0f79c4:	0064c021 */ 	addu	$t8,$v1,$a0
.L0f0f79c8:
/*  f0f79c8:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0f79cc:	0064c821 */ 	addu	$t9,$v1,$a0
/*  f0f79d0:	af030000 */ 	sw	$v1,0x0($t8)
/*  f0f79d4:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f79d8:	07210003 */ 	bgez	$t9,.L0f0f79e8
/*  f0f79dc:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0f79e0:	27210001 */ 	addiu	$at,$t9,0x1
/*  f0f79e4:	00017043 */ 	sra	$t6,$at,0x1
.L0f0f79e8:
/*  f0f79e8:	14a00009 */ 	bnez	$a1,.L0f0f7a10
/*  f0f79ec:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f0f79f0:	00c7c021 */ 	addu	$t8,$a2,$a3
/*  f0f79f4:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f79f8:	07010003 */ 	bgez	$t8,.L0f0f7a08
/*  f0f79fc:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f7a00:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f7a04:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f7a08:
/*  f0f7a08:	1000011f */ 	beqz	$zero,.L0f0f7e88
/*  f0f7a0c:	ad990000 */ 	sw	$t9,0x0($t4)
.L0f0f7a10:
/*  f0f7a10:	00c77021 */ 	addu	$t6,$a2,$a3
/*  f0f7a14:	05c10003 */ 	bgez	$t6,.L0f0f7a24
/*  f0f7a18:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f0f7a1c:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f0f7a20:	00017843 */ 	sra	$t7,$at,0x1
.L0f0f7a24:
/*  f0f7a24:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0f7a28:	10000117 */ 	beqz	$zero,.L0f0f7e88
/*  f0f7a2c:	ad870000 */ 	sw	$a3,0x0($t4)
.L0f0f7a30:
/*  f0f7a30:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0f7a34:	07010003 */ 	bgez	$t8,.L0f0f7a44
/*  f0f7a38:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f7a3c:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f7a40:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f7a44:
/*  f0f7a44:	add90000 */ 	sw	$t9,0x0($t6)
/*  f0f7a48:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7a4c:	ade40000 */ 	sw	$a0,0x0($t7)
/*  f0f7a50:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f7a54:	1000010c */ 	beqz	$zero,.L0f0f7e88
/*  f0f7a58:	ad870000 */ 	sw	$a3,0x0($t4)
.L0f0f7a5c:
/*  f0f7a5c:	10a00003 */ 	beqz	$a1,.L0f0f7a6c
/*  f0f7a60:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7a64:	14a10009 */ 	bne	$a1,$at,.L0f0f7a8c
/*  f0f7a68:	00c77021 */ 	addu	$t6,$a2,$a3
.L0f0f7a6c:
/*  f0f7a6c:	00c7c021 */ 	addu	$t8,$a2,$a3
/*  f0f7a70:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f7a74:	07010003 */ 	bgez	$t8,.L0f0f7a84
/*  f0f7a78:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f7a7c:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f7a80:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f7a84:
/*  f0f7a84:	10000007 */ 	beqz	$zero,.L0f0f7aa4
/*  f0f7a88:	ad990000 */ 	sw	$t9,0x0($t4)
.L0f0f7a8c:
/*  f0f7a8c:	05c10003 */ 	bgez	$t6,.L0f0f7a9c
/*  f0f7a90:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f0f7a94:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f0f7a98:	00017843 */ 	sra	$t7,$at,0x1
.L0f0f7a9c:
/*  f0f7a9c:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0f7aa0:	ad870000 */ 	sw	$a3,0x0($t4)
.L0f0f7aa4:
/*  f0f7aa4:	10a00003 */ 	beqz	$a1,.L0f0f7ab4
/*  f0f7aa8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f7aac:	14a8000b */ 	bne	$a1,$t0,.L0f0f7adc
/*  f0f7ab0:	0064c021 */ 	addu	$t8,$v1,$a0
.L0f0f7ab4:
/*  f0f7ab4:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0f7ab8:	0064c821 */ 	addu	$t9,$v1,$a0
/*  f0f7abc:	af030000 */ 	sw	$v1,0x0($t8)
/*  f0f7ac0:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7ac4:	07210003 */ 	bgez	$t9,.L0f0f7ad4
/*  f0f7ac8:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0f7acc:	27210001 */ 	addiu	$at,$t9,0x1
/*  f0f7ad0:	00017043 */ 	sra	$t6,$at,0x1
.L0f0f7ad4:
/*  f0f7ad4:	100000ec */ 	beqz	$zero,.L0f0f7e88
/*  f0f7ad8:	adee0000 */ 	sw	$t6,0x0($t7)
.L0f0f7adc:
/*  f0f7adc:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0f7ae0:	07010003 */ 	bgez	$t8,.L0f0f7af0
/*  f0f7ae4:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f7ae8:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f7aec:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f7af0:
/*  f0f7af0:	add90000 */ 	sw	$t9,0x0($t6)
/*  f0f7af4:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7af8:	100000e3 */ 	beqz	$zero,.L0f0f7e88
/*  f0f7afc:	ade40000 */ 	sw	$a0,0x0($t7)
/*  f0f7b00:	3c1f8007 */ 	lui	$ra,0x8007
/*  f0f7b04:	27ff1448 */ 	addiu	$ra,$ra,0x1448
/*  f0f7b08:	8ff80000 */ 	lw	$t8,0x0($ra)
/*  f0f7b0c:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f0f7b10:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f0f7b14:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0f7b18:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f7b1c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f7b20:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f7b24:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f7b28:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f7b2c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f7b30:	01b97021 */ 	addu	$t6,$t5,$t9
/*  f0f7b34:	91cf083b */ 	lbu	$t7,0x83b($t6)
/*  f0f7b38:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f7b3c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0f7b40:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0f7b44:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f0f7b48:	8f2e0064 */ 	lw	$t6,0x64($t9)
/*  f0f7b4c:	3c188008 */ 	lui	$t8,0x8008
/*  f0f7b50:	8f18fac0 */ 	lw	$t8,-0x540($t8)
/*  f0f7b54:	85cf0634 */ 	lh	$t7,0x634($t6)
/*  f0f7b58:	00005025 */ 	or	$t2,$zero,$zero
/*  f0f7b5c:	01f8001a */ 	div	$zero,$t7,$t8
/*  f0f7b60:	0000c812 */ 	mflo	$t9
/*  f0f7b64:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f0f7b68:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f0f7b6c:	17000002 */ 	bnez	$t8,.L0f0f7b78
/*  f0f7b70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7b74:	0007000d */ 	break	0x7
.L0f0f7b78:
/*  f0f7b78:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f7b7c:	17010004 */ 	bne	$t8,$at,.L0f0f7b90
/*  f0f7b80:	3c018000 */ 	lui	$at,0x8000
/*  f0f7b84:	15e10002 */ 	bne	$t7,$at,.L0f0f7b90
/*  f0f7b88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7b8c:	0006000d */ 	break	0x6
.L0f0f7b90:
/*  f0f7b90:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f7b94:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f7b98:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f7b9c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f7ba0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f7ba4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f7ba8:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f7bac:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0f7bb0:	9319083b */ 	lbu	$t9,0x83b($t8)
/*  f0f7bb4:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0f7bb8:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f0f7bbc:	8df80064 */ 	lw	$t8,0x64($t7)
/*  f0f7bc0:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0f7bc4:	87190636 */ 	lh	$t9,0x636($t8)
/*  f0f7bc8:	add90000 */ 	sw	$t9,0x0($t6)
/*  f0f7bcc:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f0f7bd0:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f7bd4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f7bd8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f7bdc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f7be0:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f7be4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f7be8:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f7bec:	01b8c821 */ 	addu	$t9,$t5,$t8
/*  f0f7bf0:	932e083b */ 	lbu	$t6,0x83b($t9)
/*  f0f7bf4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0f7bf8:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f0f7bfc:	8f020064 */ 	lw	$v0,0x64($t8)
/*  f0f7c00:	3c188008 */ 	lui	$t8,0x8008
/*  f0f7c04:	8f18fac0 */ 	lw	$t8,-0x540($t8)
/*  f0f7c08:	84590630 */ 	lh	$t9,0x630($v0)
/*  f0f7c0c:	844e0634 */ 	lh	$t6,0x634($v0)
/*  f0f7c10:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f0f7c14:	01f8001a */ 	div	$zero,$t7,$t8
/*  f0f7c18:	0000c812 */ 	mflo	$t9
/*  f0f7c1c:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f0f7c20:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f0f7c24:	17000002 */ 	bnez	$t8,.L0f0f7c30
/*  f0f7c28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7c2c:	0007000d */ 	break	0x7
.L0f0f7c30:
/*  f0f7c30:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f7c34:	17010004 */ 	bne	$t8,$at,.L0f0f7c48
/*  f0f7c38:	3c018000 */ 	lui	$at,0x8000
/*  f0f7c3c:	15e10002 */ 	bne	$t7,$at,.L0f0f7c48
/*  f0f7c40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7c44:	0006000d */ 	break	0x6
.L0f0f7c48:
/*  f0f7c48:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f7c4c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f7c50:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f7c54:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f7c58:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f7c5c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f7c60:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f7c64:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0f7c68:	9319083b */ 	lbu	$t9,0x83b($t8)
/*  f0f7c6c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0f7c70:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f0f7c74:	8de20064 */ 	lw	$v0,0x64($t7)
/*  f0f7c78:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7c7c:	84580632 */ 	lh	$t8,0x632($v0)
/*  f0f7c80:	84590636 */ 	lh	$t9,0x636($v0)
/*  f0f7c84:	03197021 */ 	addu	$t6,$t8,$t9
/*  f0f7c88:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f0f7c8c:	8c65006c */ 	lw	$a1,0x6c($v1)
/*  f0f7c90:	10a00003 */ 	beqz	$a1,.L0f0f7ca0
/*  f0f7c94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7c98:	10000001 */ 	beqz	$zero,.L0f0f7ca0
/*  f0f7c9c:	240a0001 */ 	addiu	$t2,$zero,0x1
.L0f0f7ca0:
/*  f0f7ca0:	8c660068 */ 	lw	$a2,0x68($v1)
/*  f0f7ca4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f7ca8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f7cac:	10c00003 */ 	beqz	$a2,.L0f0f7cbc
/*  f0f7cb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7cb4:	10000001 */ 	beqz	$zero,.L0f0f7cbc
/*  f0f7cb8:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0f7cbc:
/*  f0f7cbc:	8c680064 */ 	lw	$t0,0x64($v1)
/*  f0f7cc0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f7cc4:	11000003 */ 	beqz	$t0,.L0f0f7cd4
/*  f0f7cc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7ccc:	10000001 */ 	beqz	$zero,.L0f0f7cd4
/*  f0f7cd0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f7cd4:
/*  f0f7cd4:	8c690070 */ 	lw	$t1,0x70($v1)
/*  f0f7cd8:	11200003 */ 	beqz	$t1,.L0f0f7ce8
/*  f0f7cdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7ce0:	10000001 */ 	beqz	$zero,.L0f0f7ce8
/*  f0f7ce4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f7ce8:
/*  f0f7ce8:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f0f7cec:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f0f7cf0:	032a7021 */ 	addu	$t6,$t9,$t2
/*  f0f7cf4:	29c10003 */ 	slti	$at,$t6,0x3
/*  f0f7cf8:	14200026 */ 	bnez	$at,.L0f0f7d94
/*  f0f7cfc:	00005025 */ 	or	$t2,$zero,$zero
/*  f0f7d00:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f0f7d04:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7d08:	3c05800a */ 	lui	$a1,0x800a
/*  f0f7d0c:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f7d10:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f7d14:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f7d18:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f7d1c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f7d20:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f7d24:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f7d28:	01b8c821 */ 	addu	$t9,$t5,$t8
/*  f0f7d2c:	9322083b */ 	lbu	$v0,0x83b($t9)
/*  f0f7d30:	3c06800a */ 	lui	$a2,0x800a
/*  f0f7d34:	50400004 */ 	beqzl	$v0,.L0f0f7d48
/*  f0f7d38:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f0f7d3c:	1441000b */ 	bne	$v0,$at,.L0f0f7d6c
/*  f0f7d40:	3c08800a */ 	lui	$t0,0x800a
/*  f0f7d44:	8d6e0000 */ 	lw	$t6,0x0($t3)
.L0f0f7d48:
/*  f0f7d48:	3c08800a */ 	lui	$t0,0x800a
/*  f0f7d4c:	3c09800a */ 	lui	$t1,0x800a
/*  f0f7d50:	25cf0016 */ 	addiu	$t7,$t6,0x16
/*  f0f7d54:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0f7d58:	8d29a030 */ 	lw	$t1,-0x5fd0($t1)
/*  f0f7d5c:	8d08a024 */ 	lw	$t0,-0x5fdc($t0)
/*  f0f7d60:	8cc6a028 */ 	lw	$a2,-0x5fd8($a2)
/*  f0f7d64:	1000000b */ 	beqz	$zero,.L0f0f7d94
/*  f0f7d68:	8ca5a02c */ 	lw	$a1,-0x5fd4($a1)
.L0f0f7d6c:
/*  f0f7d6c:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f0f7d70:	3c05800a */ 	lui	$a1,0x800a
/*  f0f7d74:	3c06800a */ 	lui	$a2,0x800a
/*  f0f7d78:	2719ffea */ 	addiu	$t9,$t8,-22
/*  f0f7d7c:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f0f7d80:	3c09800a */ 	lui	$t1,0x800a
/*  f0f7d84:	8d29a030 */ 	lw	$t1,-0x5fd0($t1)
/*  f0f7d88:	8d08a024 */ 	lw	$t0,-0x5fdc($t0)
/*  f0f7d8c:	8cc6a028 */ 	lw	$a2,-0x5fd8($a2)
/*  f0f7d90:	8ca5a02c */ 	lw	$a1,-0x5fd4($a1)
.L0f0f7d94:
/*  f0f7d94:	10a00003 */ 	beqz	$a1,.L0f0f7da4
/*  f0f7d98:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7d9c:	10000001 */ 	beqz	$zero,.L0f0f7da4
/*  f0f7da0:	240a0001 */ 	addiu	$t2,$zero,0x1
.L0f0f7da4:
/*  f0f7da4:	10c00003 */ 	beqz	$a2,.L0f0f7db4
/*  f0f7da8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f7dac:	10000001 */ 	beqz	$zero,.L0f0f7db4
/*  f0f7db0:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0f7db4:
/*  f0f7db4:	11000003 */ 	beqz	$t0,.L0f0f7dc4
/*  f0f7db8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f7dbc:	10000001 */ 	beqz	$zero,.L0f0f7dc4
/*  f0f7dc0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f7dc4:
/*  f0f7dc4:	11200003 */ 	beqz	$t1,.L0f0f7dd4
/*  f0f7dc8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f7dcc:	10000001 */ 	beqz	$zero,.L0f0f7dd4
/*  f0f7dd0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f7dd4:
/*  f0f7dd4:	00447021 */ 	addu	$t6,$v0,$a0
/*  f0f7dd8:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f0f7ddc:	01eac021 */ 	addu	$t8,$t7,$t2
/*  f0f7de0:	5701002a */ 	bnel	$t8,$at,.L0f0f7e8c
/*  f0f7de4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f7de8:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0f7dec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7df0:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f7df4:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f0f7df8:	3c1f8007 */ 	lui	$ra,0x8007
/*  f0f7dfc:	27ff1448 */ 	addiu	$ra,$ra,0x1448
/*  f0f7e00:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f0f7e04:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f0f7e08:	11020005 */ 	beq	$t0,$v0,.L0f0f7e20
/*  f0f7e0c:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f7e10:	3c198009 */ 	lui	$t9,0x8009
/*  f0f7e14:	93390af0 */ 	lbu	$t9,0xaf0($t9)
/*  f0f7e18:	5519001c */ 	bnel	$t0,$t9,.L0f0f7e8c
/*  f0f7e1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f7e20:
/*  f0f7e20:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f0f7e24:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f7e28:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f7e2c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f7e30:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f7e34:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f7e38:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f7e3c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f7e40:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0f7e44:	9319083b */ 	lbu	$t9,0x83b($t8)
/*  f0f7e48:	57200006 */ 	bnezl	$t9,.L0f0f7e64
/*  f0f7e4c:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f0f7e50:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f0f7e54:	25cf0016 */ 	addiu	$t7,$t6,0x16
/*  f0f7e58:	1000000b */ 	beqz	$zero,.L0f0f7e88
/*  f0f7e5c:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0f7e60:	8d980000 */ 	lw	$t8,0x0($t4)
.L0f0f7e64:
/*  f0f7e64:	2719ffea */ 	addiu	$t9,$t8,-22
/*  f0f7e68:	10000007 */ 	beqz	$zero,.L0f0f7e88
/*  f0f7e6c:	ad990000 */ 	sw	$t9,0x0($t4)
.L0f0f7e70:
/*  f0f7e70:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f7e74:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0f7e78:	adc30000 */ 	sw	$v1,0x0($t6)
/*  f0f7e7c:	ad870000 */ 	sw	$a3,0x0($t4)
/*  f0f7e80:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7e84:	ade40000 */ 	sw	$a0,0x0($t7)
.L0f0f7e88:
/*  f0f7e88:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f7e8c:
/*  f0f7e8c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0f7e90:	03e00008 */ 	jr	$ra
/*  f0f7e94:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f7e98
/*  f0f7e98:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0f7e9c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f7ea0:	00808025 */ 	or	$s0,$a0,$zero
/*  f0f7ea4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0f7ea8:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f0f7eac:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0f7eb0:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f0f7eb4:	0fc3ddca */ 	jal	func0f0f7728
/*  f0f7eb8:	27a70040 */ 	addiu	$a3,$sp,0x40
/*  f0f7ebc:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f0f7ec0:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f0f7ec4:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0f7ec8:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7ecc:	8e060024 */ 	lw	$a2,0x24($s0)
/*  f0f7ed0:	03191023 */ 	subu	$v0,$t8,$t9
/*  f0f7ed4:	2444fffa */ 	addiu	$a0,$v0,-6
/*  f0f7ed8:	01cf2823 */ 	subu	$a1,$t6,$t7
/*  f0f7edc:	24a5fffa */ 	addiu	$a1,$a1,-6
/*  f0f7ee0:	00c4082a */ 	slt	$at,$a2,$a0
/*  f0f7ee4:	10200002 */ 	beqz	$at,.L0f0f7ef0
/*  f0f7ee8:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0f7eec:	00c02025 */ 	or	$a0,$a2,$zero
.L0f0f7ef0:
/*  f0f7ef0:	8e020028 */ 	lw	$v0,0x28($s0)
/*  f0f7ef4:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0f7ef8:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f0f7efc:	0045082a */ 	slt	$at,$v0,$a1
/*  f0f7f00:	10200002 */ 	beqz	$at,.L0f0f7f0c
/*  f0f7f04:	01095021 */ 	addu	$t2,$t0,$t1
/*  f0f7f08:	00401825 */ 	or	$v1,$v0,$zero
.L0f0f7f0c:
/*  f0f7f0c:	01445823 */ 	subu	$t3,$t2,$a0
/*  f0f7f10:	05610003 */ 	bgez	$t3,.L0f0f7f20
/*  f0f7f14:	000b6043 */ 	sra	$t4,$t3,0x1
/*  f0f7f18:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0f7f1c:	00016043 */ 	sra	$t4,$at,0x1
.L0f0f7f20:
/*  f0f7f20:	ae0c002c */ 	sw	$t4,0x2c($s0)
/*  f0f7f24:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0f7f28:	8fad0044 */ 	lw	$t5,0x44($sp)
/*  f0f7f2c:	8207006d */ 	lb	$a3,0x6d($s0)
/*  f0f7f30:	ae040034 */ 	sw	$a0,0x34($s0)
/*  f0f7f34:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0f7f38:	01e3c023 */ 	subu	$t8,$t7,$v1
/*  f0f7f3c:	07010003 */ 	bgez	$t8,.L0f0f7f4c
/*  f0f7f40:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f7f44:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f7f48:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f7f4c:
/*  f0f7f4c:	ae190030 */ 	sw	$t9,0x30($s0)
/*  f0f7f50:	10e00036 */ 	beqz	$a3,.L0f0f802c
/*  f0f7f54:	ae030038 */ 	sw	$v1,0x38($s0)
/*  f0f7f58:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0f7f5c:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f0f7f60:	0fc3dd65 */ 	jal	func0f0f7594
/*  f0f7f64:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f0f7f68:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f0f7f6c:	05030006 */ 	bgezl	$t0,.L0f0f7f88
/*  f0f7f70:	8fac0030 */ 	lw	$t4,0x30($sp)
/*  f0f7f74:	8e090034 */ 	lw	$t1,0x34($s0)
/*  f0f7f78:	240afffc */ 	addiu	$t2,$zero,-4
/*  f0f7f7c:	01495823 */ 	subu	$t3,$t2,$t1
/*  f0f7f80:	ae0b002c */ 	sw	$t3,0x2c($s0)
/*  f0f7f84:	8fac0030 */ 	lw	$t4,0x30($sp)
.L0f0f7f88:
/*  f0f7f88:	59800017 */ 	blezl	$t4,.L0f0f7fe8
/*  f0f7f8c:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f0f7f90:	0c002f40 */ 	jal	func0000bd00
/*  f0f7f94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7f98:	0c002f22 */ 	jal	func0000bc88
/*  f0f7f9c:	a7a2002e */ 	sh	$v0,0x2e($sp)
/*  f0f7fa0:	87ad002e */ 	lh	$t5,0x2e($sp)
/*  f0f7fa4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0f7fa8:	8deffac0 */ 	lw	$t7,-0x540($t7)
/*  f0f7fac:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0f7fb0:	01cf001a */ 	div	$zero,$t6,$t7
/*  f0f7fb4:	0000c012 */ 	mflo	$t8
/*  f0f7fb8:	27190004 */ 	addiu	$t9,$t8,0x4
/*  f0f7fbc:	ae19002c */ 	sw	$t9,0x2c($s0)
/*  f0f7fc0:	15e00002 */ 	bnez	$t7,.L0f0f7fcc
/*  f0f7fc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7fc8:	0007000d */ 	break	0x7
.L0f0f7fcc:
/*  f0f7fcc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f7fd0:	15e10004 */ 	bne	$t7,$at,.L0f0f7fe4
/*  f0f7fd4:	3c018000 */ 	lui	$at,0x8000
/*  f0f7fd8:	15c10002 */ 	bne	$t6,$at,.L0f0f7fe4
/*  f0f7fdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7fe0:	0006000d */ 	break	0x6
.L0f0f7fe4:
/*  f0f7fe4:	8fa80034 */ 	lw	$t0,0x34($sp)
.L0f0f7fe8:
/*  f0f7fe8:	05030006 */ 	bgezl	$t0,.L0f0f8004
/*  f0f7fec:	8fac0034 */ 	lw	$t4,0x34($sp)
/*  f0f7ff0:	8e0a0038 */ 	lw	$t2,0x38($s0)
/*  f0f7ff4:	2409fffc */ 	addiu	$t1,$zero,-4
/*  f0f7ff8:	012a5823 */ 	subu	$t3,$t1,$t2
/*  f0f7ffc:	ae0b0030 */ 	sw	$t3,0x30($s0)
/*  f0f8000:	8fac0034 */ 	lw	$t4,0x34($sp)
.L0f0f8004:
/*  f0f8004:	5980000a */ 	blezl	$t4,.L0f0f8030
/*  f0f8008:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0f800c:	0c002f44 */ 	jal	func0000bd10
/*  f0f8010:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8014:	0c002f26 */ 	jal	func0000bc98
/*  f0f8018:	a7a2002e */ 	sh	$v0,0x2e($sp)
/*  f0f801c:	87ad002e */ 	lh	$t5,0x2e($sp)
/*  f0f8020:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0f8024:	25cf0004 */ 	addiu	$t7,$t6,0x4
/*  f0f8028:	ae0f0030 */ 	sw	$t7,0x30($s0)
.L0f0f802c:
/*  f0f802c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0f8030:
/*  f0f8030:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f8034:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f0f8038:	03e00008 */ 	jr	$ra
/*  f0f803c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f8040
/*  f0f8040:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f8044:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0f8048:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0f804c:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0f8050:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f8054:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f8058:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f805c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f8060:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f8064:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f8068:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f806c:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f0f8070:	3c04800a */ 	lui	$a0,%hi(var800a19c0)
/*  f0f8074:	248419c0 */ 	addiu	$a0,$a0,%lo(var800a19c0)
/*  f0f8078:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f0f807c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f8080:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0f8084:	2419000a */ 	addiu	$t9,$zero,0xa
/*  f0f8088:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f808c:	a44004f4 */ 	sh	$zero,0x4f4($v0)
/*  f0f8090:	a4400460 */ 	sh	$zero,0x460($v0)
/*  f0f8094:	ac40065c */ 	sw	$zero,0x65c($v0)
/*  f0f8098:	ac4006d8 */ 	sw	$zero,0x6d8($v0)
/*  f0f809c:	ac40081c */ 	sw	$zero,0x81c($v0)
/*  f0f80a0:	ac4004f8 */ 	sw	$zero,0x4f8($v0)
/*  f0f80a4:	14a30007 */ 	bne	$a1,$v1,.L0f0f80c4
/*  f0f80a8:	a059083c */ 	sb	$t9,0x83c($v0)
/*  f0f80ac:	9049083b */ 	lbu	$t1,0x83b($v0)
/*  f0f80b0:	3c018007 */ 	lui	$at,0x8007
/*  f0f80b4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f80b8:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0f80bc:	002a0821 */ 	addu	$at,$at,$t2
/*  f0f80c0:	ac280750 */ 	sw	$t0,0x750($at)
.L0f0f80c4:
/*  f0f80c4:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f0f80c8:	3c02800a */ 	lui	$v0,0x800a
/*  f0f80cc:	256cffff */ 	addiu	$t4,$t3,-1
/*  f0f80d0:	14a3000a */ 	bne	$a1,$v1,.L0f0f80fc
/*  f0f80d4:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f0f80d8:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0f80dc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f80e0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f80e4:	904d0250 */ 	lbu	$t5,0x250($v0)
/*  f0f80e8:	55a10005 */ 	bnel	$t5,$at,.L0f0f8100
/*  f0f80ec:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0f80f0:	a04e0250 */ 	sb	$t6,0x250($v0)
/*  f0f80f4:	3c03800a */ 	lui	$v1,0x800a
/*  f0f80f8:	8c6319c4 */ 	lw	$v1,0x19c4($v1)
.L0f0f80fc:
/*  f0f80fc:	24010007 */ 	addiu	$at,$zero,0x7
.L0f0f8100:
/*  f0f8100:	54610004 */ 	bnel	$v1,$at,.L0f0f8114
/*  f0f8104:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f8108:	0c003a57 */ 	jal	func0000e95c
/*  f0f810c:	2404005a */ 	addiu	$a0,$zero,0x5a
/*  f0f8110:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f8114:
/*  f0f8114:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f8118:	03e00008 */ 	jr	$ra
/*  f0f811c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f8120
/*  f0f8120:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0f8124:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0f8128:	3c128007 */ 	lui	$s2,%hi(g_MpPlayerNum)
/*  f0f812c:	26521448 */ 	addiu	$s2,$s2,%lo(g_MpPlayerNum)
/*  f0f8130:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f0f8134:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0f8138:	24130e70 */ 	addiu	$s3,$zero,0xe70
/*  f0f813c:	01d30019 */ 	multu	$t6,$s3
/*  f0f8140:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f8144:	3c11800a */ 	lui	$s1,%hi(var8009e000)
/*  f0f8148:	2631e000 */ 	addiu	$s1,$s1,%lo(var8009e000)
/*  f0f814c:	3c04800a */ 	lui	$a0,0x800a
/*  f0f8150:	8084202e */ 	lb	$a0,0x202e($a0)
/*  f0f8154:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0f8158:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f815c:	00007812 */ 	mflo	$t7
/*  f0f8160:	022f1021 */ 	addu	$v0,$s1,$t7
/*  f0f8164:	8c4304f8 */ 	lw	$v1,0x4f8($v0)
/*  f0f8168:	18800012 */ 	blez	$a0,.L0f0f81b4
/*  f0f816c:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f0f8170:	04800010 */ 	bltz	$a0,.L0f0f81b4
/*  f0f8174:	00808025 */ 	or	$s0,$a0,$zero
.L0f0f8178:
/*  f0f8178:	0fc3cc88 */ 	jal	func0f0f3220
/*  f0f817c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f8180:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f0f8184:	0601fffc */ 	bgez	$s0,.L0f0f8178
/*  f0f8188:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f818c:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0f8190:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0f8194:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f8198:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f819c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f81a0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f81a4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f81a8:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f81ac:	02391021 */ 	addu	$v0,$s1,$t9
/*  f0f81b0:	8c4304f8 */ 	lw	$v1,0x4f8($v0)
.L0f0f81b4:
/*  f0f81b4:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f0f81b8:	5503000e */ 	bnel	$t0,$v1,.L0f0f81f4
/*  f0f81bc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f81c0:	844904f4 */ 	lh	$t1,0x4f4($v0)
/*  f0f81c4:	5920000b */ 	blezl	$t1,.L0f0f81f4
/*  f0f81c8:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0f81cc:
/*  f0f81cc:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0f81d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f81d4:	8e4a0000 */ 	lw	$t2,0x0($s2)
/*  f0f81d8:	01530019 */ 	multu	$t2,$s3
/*  f0f81dc:	00005812 */ 	mflo	$t3
/*  f0f81e0:	022b6021 */ 	addu	$t4,$s1,$t3
/*  f0f81e4:	858d04f4 */ 	lh	$t5,0x4f4($t4)
/*  f0f81e8:	1da0fff8 */ 	bgtz	$t5,.L0f0f81cc
/*  f0f81ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f81f0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0f81f4:
/*  f0f81f4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0f81f8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0f81fc:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0f8200:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0f8204:	03e00008 */ 	jr	$ra
/*  f0f8208:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f0f820c
/*  f0f820c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0f8210:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0f8214:	3c138007 */ 	lui	$s3,%hi(g_MpPlayerNum)
/*  f0f8218:	26731448 */ 	addiu	$s3,$s3,%lo(g_MpPlayerNum)
/*  f0f821c:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0f8220:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f8224:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0f8228:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f822c:	3c11800a */ 	lui	$s1,%hi(var8009e000)
/*  f0f8230:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0f8234:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0f8238:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0f823c:	2631e000 */ 	addiu	$s1,$s1,%lo(var8009e000)
/*  f0f8240:	00008025 */ 	or	$s0,$zero,$zero
/*  f0f8244:	24120004 */ 	addiu	$s2,$zero,0x4
/*  f0f8248:	afae0028 */ 	sw	$t6,0x28($sp)
.L0f0f824c:
/*  f0f824c:	8e2f04f8 */ 	lw	$t7,0x4f8($s1)
/*  f0f8250:	51e00004 */ 	beqzl	$t7,.L0f0f8264
/*  f0f8254:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0f8258:	0fc3e048 */ 	jal	func0f0f8120
/*  f0f825c:	ae700000 */ 	sw	$s0,0x0($s3)
/*  f0f8260:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0f8264:
/*  f0f8264:	1612fff9 */ 	bne	$s0,$s2,.L0f0f824c
/*  f0f8268:	26310e70 */ 	addiu	$s1,$s1,0xe70
/*  f0f826c:	8fb80028 */ 	lw	$t8,0x28($sp)
/*  f0f8270:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f8274:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f0f8278:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f0f827c:	3c02800a */ 	lui	$v0,%hi(var800a19c0)
/*  f0f8280:	ae780000 */ 	sw	$t8,0x0($s3)
/*  f0f8284:	244219c0 */ 	addiu	$v0,$v0,%lo(var800a19c0)
/*  f0f8288:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0f828c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0f8290:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0f8294:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0f8298:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0f829c:	ac590008 */ 	sw	$t9,0x8($v0)
/*  f0f82a0:	03e00008 */ 	jr	$ra
/*  f0f82a4:	ac48000c */ 	sw	$t0,0xc($v0)
);

GLOBAL_ASM(
glabel func0f0f82a8
/*  f0f82a8:	3c07800a */ 	lui	$a3,%hi(var800a19c0)
/*  f0f82ac:	24e719c0 */ 	addiu	$a3,$a3,%lo(var800a19c0)
/*  f0f82b0:	90e30014 */ 	lbu	$v1,0x14($a3)
/*  f0f82b4:	90e60015 */ 	lbu	$a2,0x15($a3)
/*  f0f82b8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f82bc:	2c650001 */ 	sltiu	$a1,$v1,0x1
/*  f0f82c0:	10c10004 */ 	beq	$a2,$at,.L0f0f82d4
/*  f0f82c4:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0f82c8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f82cc:	14c10002 */ 	bne	$a2,$at,.L0f0f82d8
/*  f0f82d0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f82d4:
/*  f0f82d4:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f82d8:
/*  f0f82d8:	10830002 */ 	beq	$a0,$v1,.L0f0f82e4
/*  f0f82dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f82e0:	a0e40015 */ 	sb	$a0,0x15($a3)
.L0f0f82e4:
/*  f0f82e4:	10400004 */ 	beqz	$v0,.L0f0f82f8
/*  f0f82e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f82ec:	10a00002 */ 	beqz	$a1,.L0f0f82f8
/*  f0f82f0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f82f4:	a0ee0016 */ 	sb	$t6,0x16($a3)
.L0f0f82f8:
/*  f0f82f8:	03e00008 */ 	jr	$ra
/*  f0f82fc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f8300
/*  f0f8300:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f8304:	8dce19c0 */ 	lw	$t6,0x19c0($t6)
/*  f0f8308:	3c03800a */ 	lui	$v1,%hi(var800a19c0)
/*  f0f830c:	246319c0 */ 	addiu	$v1,$v1,%lo(var800a19c0)
/*  f0f8310:	15c00005 */ 	bnez	$t6,.L0f0f8328
/*  f0f8314:	3c02800a */ 	lui	$v0,%hi(var800a19c4)
/*  f0f8318:	244219c4 */ 	addiu	$v0,$v0,%lo(var800a19c4)
.L0f0f831c:
/*  f0f831c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f8320:	1462fffe */ 	bne	$v1,$v0,.L0f0f831c
/*  f0f8324:	a0600016 */ 	sb	$zero,0x16($v1)
.L0f0f8328:
/*  f0f8328:	03e00008 */ 	jr	$ra
/*  f0f832c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f8330
/*  f0f8330:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f8334:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0f8338:	3c03800a */ 	lui	$v1,%hi(var800a19c0)
/*  f0f833c:	246319c0 */ 	addiu	$v1,$v1,%lo(var800a19c0)
/*  f0f8340:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f8344:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f8348:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f834c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f8350:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f8354:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0f8358:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f835c:	907905d5 */ 	lbu	$t9,0x5d5($v1)
/*  f0f8360:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f8364:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0f8368:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f0f836c:	904b083b */ 	lbu	$t3,0x83b($v0)
/*  f0f8370:	3329ff7f */ 	andi	$t1,$t9,0xff7f
/*  f0f8374:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0f8378:	a06905d5 */ 	sb	$t1,0x5d5($v1)
/*  f0f837c:	312a00ef */ 	andi	$t2,$t1,0xef
/*  f0f8380:	3c018007 */ 	lui	$at,0x8007
/*  f0f8384:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0f8388:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f838c:	a4400460 */ 	sh	$zero,0x460($v0)
/*  f0f8390:	a44004f4 */ 	sh	$zero,0x4f4($v0)
/*  f0f8394:	a06a05d5 */ 	sb	$t2,0x5d5($v1)
/*  f0f8398:	002c0821 */ 	addu	$at,$at,$t4
/*  f0f839c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0f83a0:	ac200750 */ 	sw	$zero,0x750($at)
/*  f0f83a4:	0fc3c525 */ 	jal	func0f0f1494
/*  f0f83a8:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f0f83ac:	3c03800a */ 	lui	$v1,%hi(var800a19c0)
/*  f0f83b0:	246319c0 */ 	addiu	$v1,$v1,%lo(var800a19c0)
/*  f0f83b4:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0f83b8:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f0f83bc:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f83c0:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0f83c4:	14a10011 */ 	bne	$a1,$at,.L0f0f840c
/*  f0f83c8:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0f83cc:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0f83d0:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f0f83d4:	3c19800a */ 	lui	$t9,%hi(var8009e000)
/*  f0f83d8:	2739e000 */ 	addiu	$t9,$t9,%lo(var8009e000)
/*  f0f83dc:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f83e0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f83e4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f83e8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f83ec:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f83f0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f83f4:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f83f8:	03191021 */ 	addu	$v0,$t8,$t9
/*  f0f83fc:	90490e40 */ 	lbu	$t1,0xe40($v0)
/*  f0f8400:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0f8404:	352a0080 */ 	ori	$t2,$t1,0x80
/*  f0f8408:	a04a0e40 */ 	sb	$t2,0xe40($v0)
.L0f0f840c:
/*  f0f840c:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0f8410:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f0f8414:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f0f8418:	24aeffff */ 	addiu	$t6,$a1,-1
/*  f0f841c:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f0f8420:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0f8424:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f8428:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f0f842c:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0f8430:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0f8434:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f0f8438:	2dc1000d */ 	sltiu	$at,$t6,0xd
/*  f0f843c:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f0f8440:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f0f8444:	10200009 */ 	beqz	$at,.L0f0f846c
/*  f0f8448:	00a03025 */ 	or	$a2,$a1,$zero
/*  f0f844c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f8450:	3c017f1b */ 	lui	$at,%hi(var7f1b2994)
/*  f0f8454:	002e0821 */ 	addu	$at,$at,$t6
/*  f0f8458:	8c2e2994 */ 	lw	$t6,%lo(var7f1b2994)($at)
/*  f0f845c:	01c00008 */ 	jr	$t6
/*  f0f8460:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8464:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f8468:	ac6f0000 */ 	sw	$t7,0x0($v1)
.L0f0f846c:
/*  f0f846c:	906805d5 */ 	lbu	$t0,0x5d5($v1)
/*  f0f8470:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f8474:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f8478:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f847c:	3109ffbf */ 	andi	$t1,$t0,0xffbf
/*  f0f8480:	a0580820 */ 	sb	$t8,0x820($v0)
/*  f0f8484:	ac650004 */ 	sw	$a1,0x4($v1)
/*  f0f8488:	ac790008 */ 	sw	$t9,0x8($v1)
/*  f0f848c:	10c10007 */ 	beq	$a2,$at,.L0f0f84ac
/*  f0f8490:	a06905d5 */ 	sb	$t1,0x5d5($v1)
/*  f0f8494:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f8498:	10c10004 */ 	beq	$a2,$at,.L0f0f84ac
/*  f0f849c:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f84a0:	10c10002 */ 	beq	$a2,$at,.L0f0f84ac
/*  f0f84a4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f84a8:	14c10013 */ 	bne	$a2,$at,.L0f0f84f8
.L0f0f84ac:
/*  f0f84ac:	3c0a8009 */ 	lui	$t2,0x8009
/*  f0f84b0:	914a0af0 */ 	lbu	$t2,0xaf0($t2)
/*  f0f84b4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f84b8:	51410010 */ 	beql	$t2,$at,.L0f0f84fc
/*  f0f84bc:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0f84c0:	906b05d4 */ 	lbu	$t3,0x5d4($v1)
/*  f0f84c4:	51600006 */ 	beqzl	$t3,.L0f0f84e0
/*  f0f84c8:	8c6f05d4 */ 	lw	$t7,0x5d4($v1)
/*  f0f84cc:	8c6c05cc */ 	lw	$t4,0x5cc($v1)
/*  f0f84d0:	000c72c0 */ 	sll	$t6,$t4,0xb
/*  f0f84d4:	05c30009 */ 	bgezl	$t6,.L0f0f84fc
/*  f0f84d8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0f84dc:	8c6f05d4 */ 	lw	$t7,0x5d4($v1)
.L0f0f84e0:
/*  f0f84e0:	000fcac0 */ 	sll	$t9,$t7,0xb
/*  f0f84e4:	07220005 */ 	bltzl	$t9,.L0f0f84fc
/*  f0f84e8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0f84ec:	906905d5 */ 	lbu	$t1,0x5d5($v1)
/*  f0f84f0:	352a0008 */ 	ori	$t2,$t1,0x8
/*  f0f84f4:	a06a05d5 */ 	sb	$t2,0x5d5($v1)
.L0f0f84f8:
/*  f0f84f8:	8fa40020 */ 	lw	$a0,0x20($sp)
.L0f0f84fc:
/*  f0f84fc:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0f8500:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f0f8504:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f0f8508:	3c03800a */ 	lui	$v1,%hi(var800a19c0)
/*  f0f850c:	246319c0 */ 	addiu	$v1,$v1,%lo(var800a19c0)
/*  f0f8510:	24cbffff */ 	addiu	$t3,$a2,-1
/*  f0f8514:	2d61000d */ 	sltiu	$at,$t3,0xd
/*  f0f8518:	10200027 */ 	beqz	$at,.L0f0f85b8
/*  f0f851c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f8520:	3c017f1b */ 	lui	$at,%hi(var7f1b29c8)
/*  f0f8524:	002b0821 */ 	addu	$at,$at,$t3
/*  f0f8528:	8c2b29c8 */ 	lw	$t3,%lo(var7f1b29c8)($at)
/*  f0f852c:	01600008 */ 	jr	$t3
/*  f0f8530:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8534:	0fc3e0aa */ 	jal	func0f0f82a8
/*  f0f8538:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0f853c:	1000001e */ 	beqz	$zero,.L0f0f85b8
/*  f0f8540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8544:	0fc5b6c5 */ 	jal	func0f16db14
/*  f0f8548:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f854c:	3c03800a */ 	lui	$v1,%hi(var800a19c0)
/*  f0f8550:	246319c0 */ 	addiu	$v1,$v1,%lo(var800a19c0)
/*  f0f8554:	240c0009 */ 	addiu	$t4,$zero,0x9
/*  f0f8558:	10000017 */ 	beqz	$zero,.L0f0f85b8
/*  f0f855c:	a06c0014 */ 	sb	$t4,0x14($v1)
/*  f0f8560:	240d0009 */ 	addiu	$t5,$zero,0x9
/*  f0f8564:	10000014 */ 	beqz	$zero,.L0f0f85b8
/*  f0f8568:	a06d0014 */ 	sb	$t5,0x14($v1)
/*  f0f856c:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f0f8570:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f8574:	24180003 */ 	addiu	$t8,$zero,0x3
/*  f0f8578:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*  f0f857c:	15e10004 */ 	bne	$t7,$at,.L0f0f8590
/*  f0f8580:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8584:	a06005d4 */ 	sb	$zero,0x5d4($v1)
/*  f0f8588:	1000000b */ 	beqz	$zero,.L0f0f85b8
/*  f0f858c:	a0780015 */ 	sb	$t8,0x15($v1)
.L0f0f8590:
/*  f0f8590:	0fc3e0aa */ 	jal	func0f0f82a8
/*  f0f8594:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f8598:	10000007 */ 	beqz	$zero,.L0f0f85b8
/*  f0f859c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f85a0:	0fc5b6c5 */ 	jal	func0f16db14
/*  f0f85a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f85a8:	3c03800a */ 	lui	$v1,%hi(var800a19c0)
/*  f0f85ac:	246319c0 */ 	addiu	$v1,$v1,%lo(var800a19c0)
/*  f0f85b0:	24190005 */ 	addiu	$t9,$zero,0x5
/*  f0f85b4:	a0790014 */ 	sb	$t9,0x14($v1)
.L0f0f85b8:
/*  f0f85b8:	0fc3c2e4 */ 	jal	func0f0f0b90
/*  f0f85bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f85c0:	50400004 */ 	beqzl	$v0,.L0f0f85d4
/*  f0f85c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f85c8:	0fc2eda7 */ 	jal	func0f0bb69c
/*  f0f85cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f85d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f85d4:
/*  f0f85d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0f85d8:	03e00008 */ 	jr	$ra
/*  f0f85dc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f85e0
/*  f0f85e0:	3c0e8007 */ 	lui	$t6,%hi(g_MainMenuMenuDialog)
/*  f0f85e4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f85e8:	25ce3a5c */ 	addiu	$t6,$t6,%lo(g_MainMenuMenuDialog)
/*  f0f85ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f85f0:	148e0004 */ 	bne	$a0,$t6,.L0f0f8604
/*  f0f85f4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0f85f8:	0fc5b6c5 */ 	jal	func0f16db14
/*  f0f85fc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0f8600:	8fa40018 */ 	lw	$a0,0x18($sp)
.L0f0f8604:
/*  f0f8604:	0fc3e0cc */ 	jal	func0f0f8330
/*  f0f8608:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f0f860c:	0fc5b350 */ 	jal	func0f16cd40
/*  f0f8610:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f8614:	3c18800a */ 	lui	$t8,0x800a
/*  f0f8618:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f0f861c:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f0f8620:	af0f1a24 */ 	sw	$t7,0x1a24($t8)
/*  f0f8624:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f8628:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f862c:	03e00008 */ 	jr	$ra
/*  f0f8630:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f8634
/*  f0f8634:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f8638:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0f863c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0f8640:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f8644:	3c058007 */ 	lui	$a1,%hi(var800714dc)
/*  f0f8648:	3c047f1b */ 	lui	$a0,%hi(var7f1b26f8)
/*  f0f864c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0f8650:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f0f8654:	248426f8 */ 	addiu	$a0,$a0,%lo(var7f1b26f8)
/*  f0f8658:	0c0036cc */ 	jal	func0000db30
/*  f0f865c:	24a514dc */ 	addiu	$a1,$a1,%lo(var800714dc)
/*  f0f8660:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f0f8664:	3c068007 */ 	lui	$a2,0x8007
/*  f0f8668:	8cc614dc */ 	lw	$a2,0x14dc($a2)
/*  f0f866c:	8c440054 */ 	lw	$a0,0x54($v0)
/*  f0f8670:	0fc54f54 */ 	jal	func0f153d50
/*  f0f8674:	8c450058 */ 	lw	$a1,0x58($v0)
/*  f0f8678:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0f867c:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f0f8680:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0f8684:	0fc3d4d8 */ 	jal	func0f0f5360
/*  f0f8688:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f0f868c:	0fc54f93 */ 	jal	func0f153e4c
/*  f0f8690:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0f8694:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f8698:	8fa20018 */ 	lw	$v0,0x18($sp)
/*  f0f869c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f86a0:	03e00008 */ 	jr	$ra
/*  f0f86a4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f86a8
/*  f0f86a8:	3c038007 */ 	lui	$v1,0x8007
/*  f0f86ac:	8c631448 */ 	lw	$v1,0x1448($v1)
/*  f0f86b0:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0f86b4:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f0f86b8:	000370c0 */ 	sll	$t6,$v1,0x3
/*  f0f86bc:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f0f86c0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f86c4:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f0f86c8:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f86cc:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f0f86d0:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f0f86d4:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f86d8:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
/*  f0f86dc:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f0f86e0:	01cf8821 */ 	addu	$s1,$t6,$t7
/*  f0f86e4:	8e3004f8 */ 	lw	$s0,0x4f8($s1)
/*  f0f86e8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0f86ec:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0f86f0:	1200012a */ 	beqz	$s0,.L0f0f8b9c
/*  f0f86f4:	3c02800a */ 	lui	$v0,0x800a
/*  f0f86f8:	8c4219c4 */ 	lw	$v0,0x19c4($v0)
/*  f0f86fc:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f8700:	10410005 */ 	beq	$v0,$at,.L0f0f8718
/*  f0f8704:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f8708:	10410003 */ 	beq	$v0,$at,.L0f0f8718
/*  f0f870c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f8710:	14410056 */ 	bne	$v0,$at,.L0f0f886c
/*  f0f8714:	3c0d8007 */ 	lui	$t5,%hi(var800714e0)
.L0f0f8718:
/*  f0f8718:	0c002f02 */ 	jal	func0000bc08
/*  f0f871c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8720:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0f8724:	8dcefac0 */ 	lw	$t6,-0x540($t6)
/*  f0f8728:	3c188007 */ 	lui	$t8,0x8007
/*  f0f872c:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f0f8730:	000e7840 */ 	sll	$t7,$t6,0x1
/*  f0f8734:	004f001a */ 	div	$zero,$v0,$t7
/*  f0f8738:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0f873c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f8740:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f8744:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f8748:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f874c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f8750:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f8754:	3c10800a */ 	lui	$s0,0x800a
/*  f0f8758:	02198021 */ 	addu	$s0,$s0,$t9
/*  f0f875c:	8e10e4f8 */ 	lw	$s0,-0x1b08($s0)
/*  f0f8760:	0000c012 */ 	mflo	$t8
/*  f0f8764:	8e0b001c */ 	lw	$t3,0x1c($s0)
/*  f0f8768:	8e0a0014 */ 	lw	$t2,0x14($s0)
/*  f0f876c:	05610003 */ 	bgez	$t3,.L0f0f877c
/*  f0f8770:	000b6043 */ 	sra	$t4,$t3,0x1
/*  f0f8774:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0f8778:	00016043 */ 	sra	$t4,$at,0x1
.L0f0f877c:
/*  f0f877c:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f0f8780:	15e00002 */ 	bnez	$t7,.L0f0f878c
/*  f0f8784:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8788:	0007000d */ 	break	0x7
.L0f0f878c:
/*  f0f878c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f8790:	15e10004 */ 	bne	$t7,$at,.L0f0f87a4
/*  f0f8794:	3c018000 */ 	lui	$at,0x8000
/*  f0f8798:	14410002 */ 	bne	$v0,$at,.L0f0f87a4
/*  f0f879c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f87a0:	0006000d */ 	break	0x6
.L0f0f87a4:
/*  f0f87a4:	3c01800a */ 	lui	$at,0x800a
/*  f0f87a8:	01b8c823 */ 	subu	$t9,$t5,$t8
/*  f0f87ac:	0c002f06 */ 	jal	func0000bc18
/*  f0f87b0:	ac39de98 */ 	sw	$t9,-0x2168($at)
/*  f0f87b4:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0f87b8:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f0f87bc:	3c0c800a */ 	lui	$t4,%hi(var8009e000)
/*  f0f87c0:	258ce000 */ 	addiu	$t4,$t4,%lo(var8009e000)
/*  f0f87c4:	000b50c0 */ 	sll	$t2,$t3,0x3
/*  f0f87c8:	014b5023 */ 	subu	$t2,$t2,$t3
/*  f0f87cc:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0f87d0:	014b5021 */ 	addu	$t2,$t2,$t3
/*  f0f87d4:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0f87d8:	014b5023 */ 	subu	$t2,$t2,$t3
/*  f0f87dc:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0f87e0:	014c8821 */ 	addu	$s1,$t2,$t4
/*  f0f87e4:	8e3004f8 */ 	lw	$s0,0x4f8($s1)
/*  f0f87e8:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f87ec:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f87f0:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f0f87f4:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f0f87f8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f87fc:	05e10003 */ 	bgez	$t7,.L0f0f880c
/*  f0f8800:	000f6843 */ 	sra	$t5,$t7,0x1
/*  f0f8804:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0f8808:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f880c:
/*  f0f880c:	01cdc021 */ 	addu	$t8,$t6,$t5
/*  f0f8810:	04410003 */ 	bgez	$v0,.L0f0f8820
/*  f0f8814:	0002c843 */ 	sra	$t9,$v0,0x1
/*  f0f8818:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0f881c:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f8820:
/*  f0f8820:	3c01800a */ 	lui	$at,0x800a
/*  f0f8824:	03195823 */ 	subu	$t3,$t8,$t9
/*  f0f8828:	ac2bde9c */ 	sw	$t3,-0x2164($at)
/*  f0f882c:	0fc3e18d */ 	jal	func0f0f8634
/*  f0f8830:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f8834:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0f8838:	8d4a1448 */ 	lw	$t2,0x1448($t2)
/*  f0f883c:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f0f8840:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
/*  f0f8844:	000a60c0 */ 	sll	$t4,$t2,0x3
/*  f0f8848:	018a6023 */ 	subu	$t4,$t4,$t2
/*  f0f884c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f8850:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f0f8854:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0f8858:	018a6023 */ 	subu	$t4,$t4,$t2
/*  f0f885c:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f0f8860:	018f8821 */ 	addu	$s1,$t4,$t7
/*  f0f8864:	1000005b */ 	beqz	$zero,.L0f0f89d4
/*  f0f8868:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0f886c:
/*  f0f886c:	25ad14e0 */ 	addiu	$t5,$t5,%lo(var800714e0)
/*  f0f8870:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0f8874:	8dab0004 */ 	lw	$t3,0x4($t5)
/*  f0f8878:	27ae0088 */ 	addiu	$t6,$sp,0x88
/*  f0f887c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0f8880:	adcb0004 */ 	sw	$t3,0x4($t6)
/*  f0f8884:	862204f4 */ 	lh	$v0,0x4f4($s1)
/*  f0f8888:	000350c0 */ 	sll	$t2,$v1,0x3
/*  f0f888c:	01435023 */ 	subu	$t2,$t2,$v1
/*  f0f8890:	18400028 */ 	blez	$v0,.L0f0f8934
/*  f0f8894:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f8898:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0f889c:	01435021 */ 	addu	$t2,$t2,$v1
/*  f0f88a0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0f88a4:	01435023 */ 	subu	$t2,$t2,$v1
/*  f0f88a8:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0f88ac:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f0f88b0:	00024880 */ 	sll	$t1,$v0,0x2
/*  f0f88b4:	01224823 */ 	subu	$t1,$t1,$v0
/*  f0f88b8:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
/*  f0f88bc:	254c0464 */ 	addiu	$t4,$t2,0x464
/*  f0f88c0:	44800000 */ 	mtc1	$zero,$f0
/*  f0f88c4:	018f4021 */ 	addu	$t0,$t4,$t7
/*  f0f88c8:	000948c0 */ 	sll	$t1,$t1,0x3
.L0f0f88cc:
/*  f0f88cc:	81050014 */ 	lb	$a1,0x14($t0)
/*  f0f88d0:	24e70018 */ 	addiu	$a3,$a3,0x18
/*  f0f88d4:	01003025 */ 	or	$a2,$t0,$zero
/*  f0f88d8:	18a00013 */ 	blez	$a1,.L0f0f8928
/*  f0f88dc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f88e0:	00c02025 */ 	or	$a0,$a2,$zero
.L0f0f88e4:
/*  f0f88e4:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0f88e8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f88ec:	5050000c */ 	beql	$v0,$s0,.L0f0f8920
/*  f0f88f0:	0065082a */ 	slt	$at,$v1,$a1
/*  f0f88f4:	9059003c */ 	lbu	$t9,0x3c($v0)
/*  f0f88f8:	57200007 */ 	bnezl	$t9,.L0f0f8918
/*  f0f88fc:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0f8900:	c4440040 */ 	lwc1	$f4,0x40($v0)
/*  f0f8904:	4604003e */ 	c.le.s	$f0,$f4
/*  f0f8908:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f890c:	45020004 */ 	bc1fl	.L0f0f8920
/*  f0f8910:	0065082a */ 	slt	$at,$v1,$a1
/*  f0f8914:	afa20088 */ 	sw	$v0,0x88($sp)
.L0f0f8918:
/*  f0f8918:	80c50014 */ 	lb	$a1,0x14($a2)
/*  f0f891c:	0065082a */ 	slt	$at,$v1,$a1
.L0f0f8920:
/*  f0f8920:	1420fff0 */ 	bnez	$at,.L0f0f88e4
/*  f0f8924:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f0f8928:
/*  f0f8928:	00e9082a */ 	slt	$at,$a3,$t1
/*  f0f892c:	1420ffe7 */ 	bnez	$at,.L0f0f88cc
/*  f0f8930:	25080018 */ 	addiu	$t0,$t0,0x18
.L0f0f8934:
/*  f0f8934:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0f8938:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f893c:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f8940:	10a00011 */ 	beqz	$a1,.L0f0f8988
/*  f0f8944:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8948:	0fc3e18d */ 	jal	func0f0f8634
/*  f0f894c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f8950:	3c188007 */ 	lui	$t8,0x8007
/*  f0f8954:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f0f8958:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f0f895c:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f0f8960:	001870c0 */ 	sll	$t6,$t8,0x3
/*  f0f8964:	01d87023 */ 	subu	$t6,$t6,$t8
/*  f0f8968:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f896c:	01d87021 */ 	addu	$t6,$t6,$t8
/*  f0f8970:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f8974:	01d87023 */ 	subu	$t6,$t6,$t8
/*  f0f8978:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f897c:	01cd8821 */ 	addu	$s1,$t6,$t5
/*  f0f8980:	8e3004f8 */ 	lw	$s0,0x4f8($s1)
/*  f0f8984:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0f8988:
/*  f0f8988:	12000012 */ 	beqz	$s0,.L0f0f89d4
/*  f0f898c:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f8990:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f8994:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f8998:	0fc3e18d */ 	jal	func0f0f8634
/*  f0f899c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f89a0:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0f89a4:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f0f89a8:	3c0c800a */ 	lui	$t4,%hi(var8009e000)
/*  f0f89ac:	258ce000 */ 	addiu	$t4,$t4,%lo(var8009e000)
/*  f0f89b0:	000b50c0 */ 	sll	$t2,$t3,0x3
/*  f0f89b4:	014b5023 */ 	subu	$t2,$t2,$t3
/*  f0f89b8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0f89bc:	014b5021 */ 	addu	$t2,$t2,$t3
/*  f0f89c0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0f89c4:	014b5023 */ 	subu	$t2,$t2,$t3
/*  f0f89c8:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0f89cc:	014c8821 */ 	addu	$s1,$t2,$t4
/*  f0f89d0:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0f89d4:
/*  f0f89d4:	822f0df8 */ 	lb	$t7,0xdf8($s1)
/*  f0f89d8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f89dc:	51e10070 */ 	beql	$t7,$at,.L0f0f8ba0
/*  f0f89e0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0f89e4:	8e3904f8 */ 	lw	$t9,0x4f8($s1)
/*  f0f89e8:	3c0b800a */ 	lui	$t3,0x800a
/*  f0f89ec:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f0f89f0:	8f0e0010 */ 	lw	$t6,0x10($t8)
/*  f0f89f4:	31cd0080 */ 	andi	$t5,$t6,0x80
/*  f0f89f8:	55a00069 */ 	bnezl	$t5,.L0f0f8ba0
/*  f0f89fc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0f8a00:	8d6b19c0 */ 	lw	$t3,0x19c0($t3)
/*  f0f8a04:	27a40080 */ 	addiu	$a0,$sp,0x80
/*  f0f8a08:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f0f8a0c:	29610002 */ 	slti	$at,$t3,0x2
/*  f0f8a10:	1420001c */ 	bnez	$at,.L0f0f8a84
/*  f0f8a14:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f0f8a18:	0fc3ddca */ 	jal	func0f0f7728
/*  f0f8a1c:	27a70074 */ 	addiu	$a3,$sp,0x74
/*  f0f8a20:	3c0c8007 */ 	lui	$t4,0x8007
/*  f0f8a24:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f0f8a28:	3c19800a */ 	lui	$t9,0x800a
/*  f0f8a2c:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0f8a30:	000c78c0 */ 	sll	$t7,$t4,0x3
/*  f0f8a34:	01ec7823 */ 	subu	$t7,$t7,$t4
/*  f0f8a38:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f8a3c:	01ec7821 */ 	addu	$t7,$t7,$t4
/*  f0f8a40:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f8a44:	01ec7823 */ 	subu	$t7,$t7,$t4
/*  f0f8a48:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f8a4c:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f0f8a50:	8339edf8 */ 	lb	$t9,-0x1208($t9)
/*  f0f8a54:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f8a58:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0f8a5c:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0f8a60:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0f8a64:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f8a68:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f8a6c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0f8a70:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0f8a74:	0fc3c33a */ 	jal	func0f0f0ce8
/*  f0f8a78:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0f8a7c:	10000047 */ 	beqz	$zero,.L0f0f8b9c
/*  f0f8a80:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0f8a84:
/*  f0f8a84:	0c002f40 */ 	jal	func0000bd00
/*  f0f8a88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8a8c:	3c188008 */ 	lui	$t8,0x8008
/*  f0f8a90:	8f18fac0 */ 	lw	$t8,-0x540($t8)
/*  f0f8a94:	0058001a */ 	div	$zero,$v0,$t8
/*  f0f8a98:	00007012 */ 	mflo	$t6
/*  f0f8a9c:	afae0070 */ 	sw	$t6,0x70($sp)
/*  f0f8aa0:	17000002 */ 	bnez	$t8,.L0f0f8aac
/*  f0f8aa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8aa8:	0007000d */ 	break	0x7
.L0f0f8aac:
/*  f0f8aac:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f8ab0:	17010004 */ 	bne	$t8,$at,.L0f0f8ac4
/*  f0f8ab4:	3c018000 */ 	lui	$at,0x8000
/*  f0f8ab8:	14410002 */ 	bne	$v0,$at,.L0f0f8ac4
/*  f0f8abc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8ac0:	0006000d */ 	break	0x6
.L0f0f8ac4:
/*  f0f8ac4:	0c002f44 */ 	jal	func0000bd10
/*  f0f8ac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8acc:	0c002f40 */ 	jal	func0000bd00
/*  f0f8ad0:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f8ad4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f8ad8:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0f8adc:	0c002f22 */ 	jal	func0000bc88
/*  f0f8ae0:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0f8ae4:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0f8ae8:	8d4afac0 */ 	lw	$t2,-0x540($t2)
/*  f0f8aec:	00505821 */ 	addu	$t3,$v0,$s0
/*  f0f8af0:	016a001a */ 	div	$zero,$t3,$t2
/*  f0f8af4:	00006012 */ 	mflo	$t4
/*  f0f8af8:	afac0068 */ 	sw	$t4,0x68($sp)
/*  f0f8afc:	15400002 */ 	bnez	$t2,.L0f0f8b08
/*  f0f8b00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8b04:	0007000d */ 	break	0x7
.L0f0f8b08:
/*  f0f8b08:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f8b0c:	15410004 */ 	bne	$t2,$at,.L0f0f8b20
/*  f0f8b10:	3c018000 */ 	lui	$at,0x8000
/*  f0f8b14:	15610002 */ 	bne	$t3,$at,.L0f0f8b20
/*  f0f8b18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8b1c:	0006000d */ 	break	0x6
.L0f0f8b20:
/*  f0f8b20:	0c002f44 */ 	jal	func0000bd10
/*  f0f8b24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8b28:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f8b2c:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0f8b30:	0c002f26 */ 	jal	func0000bc98
/*  f0f8b34:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0f8b38:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f8b3c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0f8b40:	3c0b800a */ 	lui	$t3,0x800a
/*  f0f8b44:	0050c821 */ 	addu	$t9,$v0,$s0
/*  f0f8b48:	000e68c0 */ 	sll	$t5,$t6,0x3
/*  f0f8b4c:	01ae6823 */ 	subu	$t5,$t5,$t6
/*  f0f8b50:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f8b54:	01ae6821 */ 	addu	$t5,$t5,$t6
/*  f0f8b58:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0f8b5c:	01ae6823 */ 	subu	$t5,$t5,$t6
/*  f0f8b60:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f0f8b64:	016d5821 */ 	addu	$t3,$t3,$t5
/*  f0f8b68:	816bedf8 */ 	lb	$t3,-0x1208($t3)
/*  f0f8b6c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f8b70:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f8b74:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f8b78:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f8b7c:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f0f8b80:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f8b84:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f8b88:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f8b8c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0f8b90:	0fc3c33a */ 	jal	func0f0f0ce8
/*  f0f8b94:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f8b98:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0f8b9c:
/*  f0f8b9c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0f8ba0:
/*  f0f8ba0:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0f8ba4:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f0f8ba8:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f0f8bac:	03e00008 */ 	jr	$ra
/*  f0f8bb0:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

GLOBAL_ASM(
glabel func0f0f8bb4
/*  f0f8bb4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f8bb8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f8bbc:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0f8bc0:	00803825 */ 	or	$a3,$a0,$zero
/*  f0f8bc4:	10c00008 */ 	beqz	$a2,.L0f0f8be8
/*  f0f8bc8:	ac850008 */ 	sw	$a1,0x8($a0)
/*  f0f8bcc:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0f8bd0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0f8bd4:	0c0048f2 */ 	jal	malloc
/*  f0f8bd8:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f0f8bdc:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f0f8be0:	10000002 */ 	beqz	$zero,.L0f0f8bec
/*  f0f8be4:	ace20004 */ 	sw	$v0,0x4($a3)
.L0f0f8be8:
/*  f0f8be8:	ace00004 */ 	sw	$zero,0x4($a3)
.L0f0f8bec:
/*  f0f8bec:	44800000 */ 	mtc1	$zero,$f0
/*  f0f8bf0:	90f805b1 */ 	lbu	$t8,0x5b1($a3)
/*  f0f8bf4:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0f8bf8:	e4e0054c */ 	swc1	$f0,0x54c($a3)
/*  f0f8bfc:	3308ff7f */ 	andi	$t0,$t8,0xff7f
/*  f0f8c00:	310a00bf */ 	andi	$t2,$t0,0xbf
/*  f0f8c04:	c4e4054c */ 	lwc1	$f4,0x54c($a3)
/*  f0f8c08:	a0e805b1 */ 	sb	$t0,0x5b1($a3)
/*  f0f8c0c:	314c00ef */ 	andi	$t4,$t2,0xef
/*  f0f8c10:	a0ea05b1 */ 	sb	$t2,0x5b1($a3)
/*  f0f8c14:	340fffff */ 	dli	$t7,0xffff
/*  f0f8c18:	a0ec05b1 */ 	sb	$t4,0x5b1($a3)
/*  f0f8c1c:	318d00fb */ 	andi	$t5,$t4,0xfb
/*  f0f8c20:	a0e00000 */ 	sb	$zero,0x0($a3)
/*  f0f8c24:	acef000c */ 	sw	$t7,0xc($a3)
/*  f0f8c28:	ace00054 */ 	sw	$zero,0x54($a3)
/*  f0f8c2c:	ace00010 */ 	sw	$zero,0x10($a3)
/*  f0f8c30:	ace0056c */ 	sw	$zero,0x56c($a3)
/*  f0f8c34:	ace00570 */ 	sw	$zero,0x570($a3)
/*  f0f8c38:	ace005b4 */ 	sw	$zero,0x5b4($a3)
/*  f0f8c3c:	a0ed05b1 */ 	sb	$t5,0x5b1($a3)
/*  f0f8c40:	a4e20002 */ 	sh	$v0,0x2($a3)
/*  f0f8c44:	a4e2056a */ 	sh	$v0,0x56a($a3)
/*  f0f8c48:	e4e00538 */ 	swc1	$f0,0x538($a3)
/*  f0f8c4c:	e4e00510 */ 	swc1	$f0,0x510($a3)
/*  f0f8c50:	e4e0053c */ 	swc1	$f0,0x53c($a3)
/*  f0f8c54:	e4e00514 */ 	swc1	$f0,0x514($a3)
/*  f0f8c58:	e4e00540 */ 	swc1	$f0,0x540($a3)
/*  f0f8c5c:	e4e00518 */ 	swc1	$f0,0x518($a3)
/*  f0f8c60:	e4e00544 */ 	swc1	$f0,0x544($a3)
/*  f0f8c64:	e4e0051c */ 	swc1	$f0,0x51c($a3)
/*  f0f8c68:	e4e00548 */ 	swc1	$f0,0x548($a3)
/*  f0f8c6c:	e4e00520 */ 	swc1	$f0,0x520($a3)
/*  f0f8c70:	e4e00550 */ 	swc1	$f0,0x550($a3)
/*  f0f8c74:	e4e00528 */ 	swc1	$f0,0x528($a3)
/*  f0f8c78:	e4e00534 */ 	swc1	$f0,0x534($a3)
/*  f0f8c7c:	e4e00530 */ 	swc1	$f0,0x530($a3)
/*  f0f8c80:	e4e0052c */ 	swc1	$f0,0x52c($a3)
/*  f0f8c84:	e4e40524 */ 	swc1	$f4,0x524($a3)
/*  f0f8c88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f8c8c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f8c90:	03e00008 */ 	jr	$ra
/*  f0f8c94:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f8c98
/*  f0f8c98:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0f8c9c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0f8ca0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f8ca4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f8ca8:	0fc442fc */ 	jal	func0f110bf0
/*  f0f8cac:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f8cb0:	3c0e8009 */ 	lui	$t6,0x8009
/*  f0f8cb4:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f0f8cb8:	3c01800a */ 	lui	$at,0x800a
/*  f0f8cbc:	ac20dfc0 */ 	sw	$zero,-0x2040($at)
/*  f0f8cc0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f8cc4:	11c10005 */ 	beq	$t6,$at,.L0f0f8cdc
/*  f0f8cc8:	24044b00 */ 	addiu	$a0,$zero,0x4b00
/*  f0f8ccc:	0c0048f2 */ 	jal	malloc
/*  f0f8cd0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0f8cd4:	3c01800a */ 	lui	$at,0x800a
/*  f0f8cd8:	ac22dfbc */ 	sw	$v0,-0x2044($at)
.L0f0f8cdc:
/*  f0f8cdc:	3c11800a */ 	lui	$s1,%hi(var800a19c0)
/*  f0f8ce0:	263119c0 */ 	addiu	$s1,$s1,%lo(var800a19c0)
/*  f0f8ce4:	922f05d5 */ 	lbu	$t7,0x5d5($s1)
/*  f0f8ce8:	3c12800b */ 	lui	$s2,%hi(var800ab5a8)
/*  f0f8cec:	2652b5a8 */ 	addiu	$s2,$s2,%lo(var800ab5a8)
/*  f0f8cf0:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8cf4:	31f8ff7f */ 	andi	$t8,$t7,0xff7f
/*  f0f8cf8:	a23805d5 */ 	sb	$t8,0x5d5($s1)
/*  f0f8cfc:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d00:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f0f8d04:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d08:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d0c:	24840048 */ 	addiu	$a0,$a0,0x48
/*  f0f8d10:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d14:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d18:	24840264 */ 	addiu	$a0,$a0,0x264
/*  f0f8d1c:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d20:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d24:	24840270 */ 	addiu	$a0,$a0,0x270
/*  f0f8d28:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d2c:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d30:	2484027c */ 	addiu	$a0,$a0,0x27c
/*  f0f8d34:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d38:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d3c:	24840288 */ 	addiu	$a0,$a0,0x288
/*  f0f8d40:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d44:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d48:	24840294 */ 	addiu	$a0,$a0,0x294
/*  f0f8d4c:	3c19800a */ 	lui	$t9,0x800a
/*  f0f8d50:	8f39a474 */ 	lw	$t9,-0x5b8c($t9)
/*  f0f8d54:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0f8d58:	24100090 */ 	addiu	$s0,$zero,0x90
/*  f0f8d5c:	17210011 */ 	bne	$t9,$at,.L0f0f8da4
/*  f0f8d60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8d64:	8e480000 */ 	lw	$t0,0x0($s2)
.L0f0f8d68:
/*  f0f8d68:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d6c:	02082021 */ 	addu	$a0,$s0,$t0
/*  f0f8d70:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0f8d74:	24010198 */ 	addiu	$at,$zero,0x198
/*  f0f8d78:	5601fffb */ 	bnel	$s0,$at,.L0f0f8d68
/*  f0f8d7c:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f0f8d80:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d84:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d88:	24840198 */ 	addiu	$a0,$a0,0x198
/*  f0f8d8c:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d90:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d94:	248401b0 */ 	addiu	$a0,$a0,0x1b0
/*  f0f8d98:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d9c:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8da0:	248401a4 */ 	addiu	$a0,$a0,0x1a4
.L0f0f8da4:
/*  f0f8da4:	3c05800a */ 	lui	$a1,0x800a
/*  f0f8da8:	8ca5a2d4 */ 	lw	$a1,-0x5d2c($a1)
/*  f0f8dac:	10a00006 */ 	beqz	$a1,.L0f0f8dc8
/*  f0f8db0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f8db4:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8db8:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8dbc:	248401a4 */ 	addiu	$a0,$a0,0x1a4
/*  f0f8dc0:	3c05800a */ 	lui	$a1,0x800a
/*  f0f8dc4:	8ca5a2d4 */ 	lw	$a1,-0x5d2c($a1)
.L0f0f8dc8:
/*  f0f8dc8:	3c04800a */ 	lui	$a0,0x800a
/*  f0f8dcc:	3c02800a */ 	lui	$v0,%hi(var8009e000)
/*  f0f8dd0:	3c03800a */ 	lui	$v1,%hi(var800a19c0)
/*  f0f8dd4:	246319c0 */ 	addiu	$v1,$v1,%lo(var800a19c0)
/*  f0f8dd8:	2442e000 */ 	addiu	$v0,$v0,%lo(var8009e000)
/*  f0f8ddc:	8c84a474 */ 	lw	$a0,-0x5b8c($a0)
.L0f0f8de0:
/*  f0f8de0:	24420e70 */ 	addiu	$v0,$v0,0xe70
/*  f0f8de4:	0043082b */ 	sltu	$at,$v0,$v1
/*  f0f8de8:	1420fffd */ 	bnez	$at,.L0f0f8de0
/*  f0f8dec:	ac40f9d4 */ 	sw	$zero,-0x62c($v0)
/*  f0f8df0:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0f8df4:	1481000b */ 	bne	$a0,$at,.L0f0f8e24
/*  f0f8df8:	ae200020 */ 	sw	$zero,0x20($s1)
/*  f0f8dfc:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f0f8e00:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f0f8e04:	90490003 */ 	lbu	$t1,0x3($v0)
/*  f0f8e08:	904d0000 */ 	lbu	$t5,0x0($v0)
/*  f0f8e0c:	312bff7f */ 	andi	$t3,$t1,0xff7f
/*  f0f8e10:	a04b0003 */ 	sb	$t3,0x3($v0)
/*  f0f8e14:	316c00bf */ 	andi	$t4,$t3,0xbf
/*  f0f8e18:	31aefffe */ 	andi	$t6,$t5,0xfffe
/*  f0f8e1c:	a04c0003 */ 	sb	$t4,0x3($v0)
/*  f0f8e20:	a04e0000 */ 	sb	$t6,0x0($v0)
.L0f0f8e24:
/*  f0f8e24:	14a0004e */ 	bnez	$a1,.L0f0f8f60
/*  f0f8e28:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0f8e2c:	14810002 */ 	bne	$a0,$at,.L0f0f8e38
/*  f0f8e30:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f8e34:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f0f8e38:
/*  f0f8e38:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f0f8e3c:	14810002 */ 	bne	$a0,$at,.L0f0f8e48
/*  f0f8e40:	3c10800a */ 	lui	$s0,0x800a
/*  f0f8e44:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f0f8e48:
/*  f0f8e48:	18400015 */ 	blez	$v0,.L0f0f8ea0
/*  f0f8e4c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f8e50:	2610e840 */ 	addiu	$s0,$s0,-6080
.L0f0f8e54:
/*  f0f8e54:	3c0f8009 */ 	lui	$t7,0x8009
/*  f0f8e58:	91ef0af0 */ 	lbu	$t7,0xaf0($t7)
/*  f0f8e5c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f8e60:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f8e64:	15e10003 */ 	bne	$t7,$at,.L0f0f8e74
/*  f0f8e68:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0f8e6c:	10000003 */ 	beqz	$zero,.L0f0f8e7c
/*  f0f8e70:	3405b400 */ 	dli	$a1,0xb400
.L0f0f8e74:
/*  f0f8e74:	3c050002 */ 	lui	$a1,0x2
/*  f0f8e78:	34a55800 */ 	ori	$a1,$a1,0x5800
.L0f0f8e7c:
/*  f0f8e7c:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f0f8e80:	0fc3e2ed */ 	jal	func0f0f8bb4
/*  f0f8e84:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f0f8e88:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f0f8e8c:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f0f8e90:	26100e70 */ 	addiu	$s0,$s0,0xe70
/*  f0f8e94:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f8e98:	1462ffee */ 	bne	$v1,$v0,.L0f0f8e54
/*  f0f8e9c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f8ea0:
/*  f0f8ea0:	3c188009 */ 	lui	$t8,0x8009
/*  f0f8ea4:	93180af0 */ 	lbu	$t8,0xaf0($t8)
/*  f0f8ea8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f8eac:	3c04800a */ 	lui	$a0,%hi(var800a19dc)
/*  f0f8eb0:	13010004 */ 	beq	$t8,$at,.L0f0f8ec4
/*  f0f8eb4:	248419dc */ 	addiu	$a0,$a0,%lo(var800a19dc)
/*  f0f8eb8:	3405c800 */ 	dli	$a1,0xc800
/*  f0f8ebc:	0fc3e2ed */ 	jal	func0f0f8bb4
/*  f0f8ec0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0f8ec4:
/*  f0f8ec4:	24190259 */ 	addiu	$t9,$zero,0x259
/*  f0f8ec8:	44800000 */ 	mtc1	$zero,$f0
/*  f0f8ecc:	ae390028 */ 	sw	$t9,0x28($s1)
/*  f0f8ed0:	3c017f1b */ 	lui	$at,%hi(var7f1b29fc)
/*  f0f8ed4:	c42429fc */ 	lwc1	$f4,%lo(var7f1b29fc)($at)
/*  f0f8ed8:	e6200564 */ 	swc1	$f0,0x564($s1)
/*  f0f8edc:	e620056c */ 	swc1	$f0,0x56c($s1)
/*  f0f8ee0:	e6240568 */ 	swc1	$f4,0x568($s1)
/*  f0f8ee4:	c6260568 */ 	lwc1	$f6,0x568($s1)
/*  f0f8ee8:	c6280564 */ 	lwc1	$f8,0x564($s1)
/*  f0f8eec:	c62a056c */ 	lwc1	$f10,0x56c($s1)
/*  f0f8ef0:	3c017f1b */ 	lui	$at,%hi(var7f1b2a00)
/*  f0f8ef4:	e6260540 */ 	swc1	$f6,0x540($s1)
/*  f0f8ef8:	e628053c */ 	swc1	$f8,0x53c($s1)
/*  f0f8efc:	e62a0544 */ 	swc1	$f10,0x544($s1)
/*  f0f8f00:	c4302a00 */ 	lwc1	$f16,%lo(var7f1b2a00)($at)
/*  f0f8f04:	3c017f1b */ 	lui	$at,%hi(var7f1b2a04)
/*  f0f8f08:	922805cd */ 	lbu	$t0,0x5cd($s1)
/*  f0f8f0c:	e6300554 */ 	swc1	$f16,0x554($s1)
/*  f0f8f10:	c6320554 */ 	lwc1	$f18,0x554($s1)
/*  f0f8f14:	3109ff7f */ 	andi	$t1,$t0,0xff7f
/*  f0f8f18:	e632052c */ 	swc1	$f18,0x52c($s1)
/*  f0f8f1c:	c4242a04 */ 	lwc1	$f4,%lo(var7f1b2a04)($at)
/*  f0f8f20:	3c017f1b */ 	lui	$at,%hi(var7f1b2a08)
/*  f0f8f24:	e6240558 */ 	swc1	$f4,0x558($s1)
/*  f0f8f28:	c6260558 */ 	lwc1	$f6,0x558($s1)
/*  f0f8f2c:	e6260530 */ 	swc1	$f6,0x530($s1)
/*  f0f8f30:	c4282a08 */ 	lwc1	$f8,%lo(var7f1b2a08)($at)
/*  f0f8f34:	3c017f1b */ 	lui	$at,%hi(var7f1b2a0c)
/*  f0f8f38:	e628055c */ 	swc1	$f8,0x55c($s1)
/*  f0f8f3c:	c62a055c */ 	lwc1	$f10,0x55c($s1)
/*  f0f8f40:	e62a0534 */ 	swc1	$f10,0x534($s1)
/*  f0f8f44:	c4302a0c */ 	lwc1	$f16,%lo(var7f1b2a0c)($at)
/*  f0f8f48:	a22905cd */ 	sb	$t1,0x5cd($s1)
/*  f0f8f4c:	ae200590 */ 	sw	$zero,0x590($s1)
/*  f0f8f50:	e6300560 */ 	swc1	$f16,0x560($s1)
/*  f0f8f54:	c6320560 */ 	lwc1	$f18,0x560($s1)
/*  f0f8f58:	ae20059c */ 	sw	$zero,0x59c($s1)
/*  f0f8f5c:	e6320538 */ 	swc1	$f18,0x538($s1)
.L0f0f8f60:
/*  f0f8f60:	922a05d5 */ 	lbu	$t2,0x5d5($s1)
/*  f0f8f64:	3c02800a */ 	lui	$v0,%hi(var8009e000)
/*  f0f8f68:	3c03800a */ 	lui	$v1,%hi(var800a19c0)
/*  f0f8f6c:	314bfff7 */ 	andi	$t3,$t2,0xfff7
/*  f0f8f70:	44800000 */ 	mtc1	$zero,$f0
/*  f0f8f74:	a22005d4 */ 	sb	$zero,0x5d4($s1)
/*  f0f8f78:	a22b05d5 */ 	sb	$t3,0x5d5($s1)
/*  f0f8f7c:	246319c0 */ 	addiu	$v1,$v1,%lo(var800a19c0)
/*  f0f8f80:	2442e000 */ 	addiu	$v0,$v0,%lo(var8009e000)
/*  f0f8f84:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f0f8f88:
/*  f0f8f88:	24420e70 */ 	addiu	$v0,$v0,0xe70
/*  f0f8f8c:	0043082b */ 	sltu	$at,$v0,$v1
/*  f0f8f90:	ac40f688 */ 	sw	$zero,-0x978($v0)
/*  f0f8f94:	a440f684 */ 	sh	$zero,-0x97c($v0)
/*  f0f8f98:	a440f5f0 */ 	sh	$zero,-0xa10($v0)
/*  f0f8f9c:	a040f9b0 */ 	sb	$zero,-0x650($v0)
/*  f0f8fa0:	ac40f7ec */ 	sw	$zero,-0x814($v0)
/*  f0f8fa4:	ac40f9ac */ 	sw	$zero,-0x654($v0)
/*  f0f8fa8:	ac40f868 */ 	sw	$zero,-0x798($v0)
/*  f0f8fac:	a044ff88 */ 	sb	$a0,-0x78($v0)
/*  f0f8fb0:	a040ffd1 */ 	sb	$zero,-0x2f($v0)
/*  f0f8fb4:	ac40fff4 */ 	sw	$zero,-0xc($v0)
/*  f0f8fb8:	1420fff3 */ 	bnez	$at,.L0f0f8f88
/*  f0f8fbc:	ac40fff8 */ 	sw	$zero,-0x8($v0)
/*  f0f8fc0:	922c05d5 */ 	lbu	$t4,0x5d5($s1)
/*  f0f8fc4:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f0f8fc8:	3c02800a */ 	lui	$v0,%hi(var800a19c0)
/*  f0f8fcc:	3c03800a */ 	lui	$v1,0x800a
/*  f0f8fd0:	318dfffb */ 	andi	$t5,$t4,0xfffb
/*  f0f8fd4:	a2240668 */ 	sb	$a0,0x668($s1)
/*  f0f8fd8:	ae20000c */ 	sw	$zero,0xc($s1)
/*  f0f8fdc:	ae240008 */ 	sw	$a0,0x8($s1)
/*  f0f8fe0:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f0f8fe4:	ae200004 */ 	sw	$zero,0x4($s1)
/*  f0f8fe8:	e6200010 */ 	swc1	$f0,0x10($s1)
/*  f0f8fec:	a2200014 */ 	sb	$zero,0x14($s1)
/*  f0f8ff0:	a22d05d5 */ 	sb	$t5,0x5d5($s1)
/*  f0f8ff4:	a2250015 */ 	sb	$a1,0x15($s1)
/*  f0f8ff8:	a224001b */ 	sb	$a0,0x1b($s1)
/*  f0f8ffc:	246319c5 */ 	addiu	$v1,$v1,0x19c5
/*  f0f9000:	244219c0 */ 	addiu	$v0,$v0,%lo(var800a19c0)
.L0f0f9004:
/*  f0f9004:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f9008:	1443fffe */ 	bne	$v0,$v1,.L0f0f9004
/*  f0f900c:	a0450668 */ 	sb	$a1,0x668($v0)
/*  f0f9010:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f9014:	a220066e */ 	sb	$zero,0x66e($s1)
/*  f0f9018:	a220066f */ 	sb	$zero,0x66f($s1)
/*  f0f901c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f9020:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f9024:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f9028:	03e00008 */ 	jr	$ra
/*  f0f902c:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f0f9030
/*  f0f9030:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0f9034:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0f9038:	3c148007 */ 	lui	$s4,%hi(g_MpPlayerNum)
/*  f0f903c:	26941448 */ 	addiu	$s4,$s4,%lo(g_MpPlayerNum)
/*  f0f9040:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f0f9044:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0f9048:	24150e70 */ 	addiu	$s5,$zero,0xe70
/*  f0f904c:	01d50019 */ 	multu	$t6,$s5
/*  f0f9050:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0f9054:	3c13800a */ 	lui	$s3,%hi(var8009e000)
/*  f0f9058:	2673e000 */ 	addiu	$s3,$s3,%lo(var8009e000)
/*  f0f905c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f9060:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0f9064:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f9068:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f906c:	00802825 */ 	or	$a1,$a0,$zero
/*  f0f9070:	00007812 */ 	mflo	$t7
/*  f0f9074:	026f1821 */ 	addu	$v1,$s3,$t7
/*  f0f9078:	847804f4 */ 	lh	$t8,0x4f4($v1)
/*  f0f907c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f9080:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f9084:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f9088:	00791021 */ 	addu	$v0,$v1,$t9
/*  f0f908c:	80480460 */ 	lb	$t0,0x460($v0)
/*  f0f9090:	2442044c */ 	addiu	$v0,$v0,0x44c
/*  f0f9094:	29010002 */ 	slti	$at,$t0,0x2
/*  f0f9098:	542000a8 */ 	bnezl	$at,.L0f0f933c
/*  f0f909c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f90a0:	8c6a04f8 */ 	lw	$t2,0x4f8($v1)
/*  f0f90a4:	00044823 */ 	negu	$t1,$a0
/*  f0f90a8:	00806825 */ 	or	$t5,$a0,$zero
/*  f0f90ac:	a149006d */ 	sb	$t1,0x6d($t2)
/*  f0f90b0:	804b0015 */ 	lb	$t3,0x15($v0)
/*  f0f90b4:	016d7021 */ 	addu	$t6,$t3,$t5
/*  f0f90b8:	a04e0015 */ 	sb	$t6,0x15($v0)
/*  f0f90bc:	80440015 */ 	lb	$a0,0x15($v0)
/*  f0f90c0:	04830006 */ 	bgezl	$a0,.L0f0f90dc
/*  f0f90c4:	80590014 */ 	lb	$t9,0x14($v0)
/*  f0f90c8:	804f0014 */ 	lb	$t7,0x14($v0)
/*  f0f90cc:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f0f90d0:	a0580015 */ 	sb	$t8,0x15($v0)
/*  f0f90d4:	80440015 */ 	lb	$a0,0x15($v0)
/*  f0f90d8:	80590014 */ 	lb	$t9,0x14($v0)
.L0f0f90dc:
/*  f0f90dc:	0099082a */ 	slt	$at,$a0,$t9
/*  f0f90e0:	54200004 */ 	bnezl	$at,.L0f0f90f4
/*  f0f90e4:	8e880000 */ 	lw	$t0,0x0($s4)
/*  f0f90e8:	a0400015 */ 	sb	$zero,0x15($v0)
/*  f0f90ec:	80440015 */ 	lb	$a0,0x15($v0)
/*  f0f90f0:	8e880000 */ 	lw	$t0,0x0($s4)
.L0f0f90f4:
/*  f0f90f4:	00045080 */ 	sll	$t2,$a0,0x2
/*  f0f90f8:	004a6021 */ 	addu	$t4,$v0,$t2
/*  f0f90fc:	01150019 */ 	multu	$t0,$s5
/*  f0f9100:	8d8b0000 */ 	lw	$t3,0x0($t4)
/*  f0f9104:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f9108:	01602025 */ 	or	$a0,$t3,$zero
/*  f0f910c:	00004812 */ 	mflo	$t1
/*  f0f9110:	02691821 */ 	addu	$v1,$s3,$t1
/*  f0f9114:	14a1000a */ 	bne	$a1,$at,.L0f0f9140
/*  f0f9118:	ac6b04f8 */ 	sw	$t3,0x4f8($v1)
/*  f0f911c:	0fc3ca23 */ 	jal	func0f0f288c
/*  f0f9120:	afa50068 */ 	sw	$a1,0x68($sp)
/*  f0f9124:	8e8d0000 */ 	lw	$t5,0x0($s4)
/*  f0f9128:	01b50019 */ 	multu	$t5,$s5
/*  f0f912c:	00007012 */ 	mflo	$t6
/*  f0f9130:	026e7821 */ 	addu	$t7,$s3,$t6
/*  f0f9134:	8df804f8 */ 	lw	$t8,0x4f8($t7)
/*  f0f9138:	1000000a */ 	beqz	$zero,.L0f0f9164
/*  f0f913c:	af020008 */ 	sw	$v0,0x8($t8)
.L0f0f9140:
/*  f0f9140:	8c6404f8 */ 	lw	$a0,0x4f8($v1)
/*  f0f9144:	0fc3ca4a */ 	jal	func0f0f2928
/*  f0f9148:	afa50068 */ 	sw	$a1,0x68($sp)
/*  f0f914c:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f0f9150:	03350019 */ 	multu	$t9,$s5
/*  f0f9154:	00004012 */ 	mflo	$t0
/*  f0f9158:	02684821 */ 	addu	$t1,$s3,$t0
/*  f0f915c:	8d2a04f8 */ 	lw	$t2,0x4f8($t1)
/*  f0f9160:	ad420008 */ 	sw	$v0,0x8($t2)
.L0f0f9164:
/*  f0f9164:	8e8c0000 */ 	lw	$t4,0x0($s4)
/*  f0f9168:	2411001a */ 	addiu	$s1,$zero,0x1a
/*  f0f916c:	27b20050 */ 	addiu	$s2,$sp,0x50
/*  f0f9170:	01950019 */ 	multu	$t4,$s5
/*  f0f9174:	00005812 */ 	mflo	$t3
/*  f0f9178:	026b6821 */ 	addu	$t5,$s3,$t3
/*  f0f917c:	8da304f8 */ 	lw	$v1,0x4f8($t5)
/*  f0f9180:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0f9184:	8dd00008 */ 	lw	$s0,0x8($t6)
/*  f0f9188:	920f0000 */ 	lbu	$t7,0x0($s0)
/*  f0f918c:	522f0023 */ 	beql	$s1,$t7,.L0f0f921c
/*  f0f9190:	8c650008 */ 	lw	$a1,0x8($v1)
/*  f0f9194:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f0f9198:
/*  f0f9198:	50400012 */ 	beqzl	$v0,.L0f0f91e4
/*  f0f919c:	920b0014 */ 	lbu	$t3,0x14($s0)
/*  f0f91a0:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f0f91a4:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f0f91a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f91ac:	33190004 */ 	andi	$t9,$t8,0x4
/*  f0f91b0:	5720000c */ 	bnezl	$t9,.L0f0f91e4
/*  f0f91b4:	920b0014 */ 	lbu	$t3,0x14($s0)
/*  f0f91b8:	0040f809 */ 	jalr	$v0
/*  f0f91bc:	02403025 */ 	or	$a2,$s2,$zero
/*  f0f91c0:	50400008 */ 	beqzl	$v0,.L0f0f91e4
/*  f0f91c4:	920b0014 */ 	lbu	$t3,0x14($s0)
/*  f0f91c8:	8e880000 */ 	lw	$t0,0x0($s4)
/*  f0f91cc:	01150019 */ 	multu	$t0,$s5
/*  f0f91d0:	00004812 */ 	mflo	$t1
/*  f0f91d4:	02695021 */ 	addu	$t2,$s3,$t1
/*  f0f91d8:	8d4c04f8 */ 	lw	$t4,0x4f8($t2)
/*  f0f91dc:	ad900008 */ 	sw	$s0,0x8($t4)
/*  f0f91e0:	920b0014 */ 	lbu	$t3,0x14($s0)
.L0f0f91e4:
/*  f0f91e4:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f0f91e8:	562bffeb */ 	bnel	$s1,$t3,.L0f0f9198
/*  f0f91ec:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f0f91f0:	8e8d0000 */ 	lw	$t5,0x0($s4)
/*  f0f91f4:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f0f91f8:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f91fc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f9200:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0f9204:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f9208:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f920c:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f9210:	026e7821 */ 	addu	$t7,$s3,$t6
/*  f0f9214:	8de304f8 */ 	lw	$v1,0x4f8($t7)
/*  f0f9218:	8c650008 */ 	lw	$a1,0x8($v1)
.L0f0f921c:
/*  f0f921c:	50a00016 */ 	beqzl	$a1,.L0f0f9278
/*  f0f9220:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f9224:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f0f9228:	50400013 */ 	beqzl	$v0,.L0f0f9278
/*  f0f922c:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f9230:	8cb80004 */ 	lw	$t8,0x4($a1)
/*  f0f9234:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f0f9238:	33190004 */ 	andi	$t9,$t8,0x4
/*  f0f923c:	5720000e */ 	bnezl	$t9,.L0f0f9278
/*  f0f9240:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f9244:	0040f809 */ 	jalr	$v0
/*  f0f9248:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0f924c:	8e880000 */ 	lw	$t0,0x0($s4)
/*  f0f9250:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f0f9254:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0f9258:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0f925c:	01284821 */ 	addu	$t1,$t1,$t0
/*  f0f9260:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f0f9264:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0f9268:	00094900 */ 	sll	$t1,$t1,0x4
/*  f0f926c:	02695021 */ 	addu	$t2,$s3,$t1
/*  f0f9270:	8d4304f8 */ 	lw	$v1,0x4f8($t2)
/*  f0f9274:	8fac0068 */ 	lw	$t4,0x68($sp)
.L0f0f9278:
/*  f0f9278:	a06c006d */ 	sb	$t4,0x6d($v1)
/*  f0f927c:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f0f9280:	01750019 */ 	multu	$t3,$s5
/*  f0f9284:	00006812 */ 	mflo	$t5
/*  f0f9288:	026d7021 */ 	addu	$t6,$s3,$t5
/*  f0f928c:	0fc3dfa6 */ 	jal	func0f0f7e98
/*  f0f9290:	8dc404f8 */ 	lw	$a0,0x4f8($t6)
/*  f0f9294:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f0f9298:	44802000 */ 	mtc1	$zero,$f4
/*  f0f929c:	01f50019 */ 	multu	$t7,$s5
/*  f0f92a0:	0000c012 */ 	mflo	$t8
/*  f0f92a4:	0278c821 */ 	addu	$t9,$s3,$t8
/*  f0f92a8:	8f2304f8 */ 	lw	$v1,0x4f8($t9)
/*  f0f92ac:	8c68002c */ 	lw	$t0,0x2c($v1)
/*  f0f92b0:	ac680014 */ 	sw	$t0,0x14($v1)
/*  f0f92b4:	8e890000 */ 	lw	$t1,0x0($s4)
/*  f0f92b8:	01350019 */ 	multu	$t1,$s5
/*  f0f92bc:	00005012 */ 	mflo	$t2
/*  f0f92c0:	026a6021 */ 	addu	$t4,$s3,$t2
/*  f0f92c4:	8d8304f8 */ 	lw	$v1,0x4f8($t4)
/*  f0f92c8:	8c6b0030 */ 	lw	$t3,0x30($v1)
/*  f0f92cc:	ac6b0018 */ 	sw	$t3,0x18($v1)
/*  f0f92d0:	8e8d0000 */ 	lw	$t5,0x0($s4)
/*  f0f92d4:	01b50019 */ 	multu	$t5,$s5
/*  f0f92d8:	00007012 */ 	mflo	$t6
/*  f0f92dc:	026e7821 */ 	addu	$t7,$s3,$t6
/*  f0f92e0:	8df804f8 */ 	lw	$t8,0x4f8($t7)
/*  f0f92e4:	a300006d */ 	sb	$zero,0x6d($t8)
/*  f0f92e8:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f0f92ec:	03350019 */ 	multu	$t9,$s5
/*  f0f92f0:	00004012 */ 	mflo	$t0
/*  f0f92f4:	02684821 */ 	addu	$t1,$s3,$t0
/*  f0f92f8:	8d2a04f8 */ 	lw	$t2,0x4f8($t1)
/*  f0f92fc:	a1400060 */ 	sb	$zero,0x60($t2)
/*  f0f9300:	8e8c0000 */ 	lw	$t4,0x0($s4)
/*  f0f9304:	01950019 */ 	multu	$t4,$s5
/*  f0f9308:	00005812 */ 	mflo	$t3
/*  f0f930c:	026b6821 */ 	addu	$t5,$s3,$t3
/*  f0f9310:	8dae04f8 */ 	lw	$t6,0x4f8($t5)
/*  f0f9314:	e5c40050 */ 	swc1	$f4,0x50($t6)
/*  f0f9318:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f0f931c:	01f50019 */ 	multu	$t7,$s5
/*  f0f9320:	0000c012 */ 	mflo	$t8
/*  f0f9324:	02782021 */ 	addu	$a0,$s3,$t8
/*  f0f9328:	0fc3cde9 */ 	jal	func0f0f37a4
/*  f0f932c:	24840840 */ 	addiu	$a0,$a0,0x840
/*  f0f9330:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0f9334:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f9338:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0f933c:
/*  f0f933c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0f9340:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0f9344:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0f9348:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0f934c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0f9350:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0f9354:	03e00008 */ 	jr	$ra
/*  f0f9358:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f0f935c
/*  f0f935c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f9360:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0f9364:	27bdfee0 */ 	addiu	$sp,$sp,-288
/*  f0f9368:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0f936c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f9370:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f9374:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f9378:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f937c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f9380:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f9384:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f9388:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0f938c:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f0f9390:	8c590e40 */ 	lw	$t9,0xe40($v0)
/*  f0f9394:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0f9398:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f0f939c:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f0f93a0:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f0f93a4:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f0f93a8:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f0f93ac:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f0f93b0:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0f93b4:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0f93b8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0f93bc:	afa60128 */ 	sw	$a2,0x128($sp)
/*  f0f93c0:	afa0011c */ 	sw	$zero,0x11c($sp)
/*  f0f93c4:	8c930000 */ 	lw	$s3,0x0($a0)
/*  f0f93c8:	001947c2 */ 	srl	$t0,$t9,0x1f
/*  f0f93cc:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0f93d0:	0080f025 */ 	or	$s8,$a0,$zero
/*  f0f93d4:	15000005 */ 	bnez	$t0,.L0f0f93ec
/*  f0f93d8:	afa20114 */ 	sw	$v0,0x114($sp)
/*  f0f93dc:	3c098006 */ 	lui	$t1,0x8006
/*  f0f93e0:	8d29dd58 */ 	lw	$t1,-0x22a8($t1)
/*  f0f93e4:	5120001e */ 	beqzl	$t1,.L0f0f9460
/*  f0f93e8:	90580e40 */ 	lbu	$t8,0xe40($v0)
.L0f0f93ec:
/*  f0f93ec:	00002e00 */ 	sll	$a1,$zero,0x18
/*  f0f93f0:	00055603 */ 	sra	$t2,$a1,0x18
/*  f0f93f4:	314600ff */ 	andi	$a2,$t2,0xff
/*  f0f93f8:	a2260001 */ 	sb	$a2,0x1($s1)
/*  f0f93fc:	a2260000 */ 	sb	$a2,0x0($s1)
/*  f0f9400:	a22a0003 */ 	sb	$t2,0x3($s1)
/*  f0f9404:	a22a0002 */ 	sb	$t2,0x2($s1)
/*  f0f9408:	a2200014 */ 	sb	$zero,0x14($s1)
/*  f0f940c:	a2200007 */ 	sb	$zero,0x7($s1)
/*  f0f9410:	a2200006 */ 	sb	$zero,0x6($s1)
/*  f0f9414:	a2200005 */ 	sb	$zero,0x5($s1)
/*  f0f9418:	a2200004 */ 	sb	$zero,0x4($s1)
/*  f0f941c:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0f9420:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f0f9424:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f0f9428:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f0f942c:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f0f9430:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0f9434:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f9438:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f0f943c:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0f9440:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0f9444:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f0f9448:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f0f944c:	904e0e40 */ 	lbu	$t6,0xe40($v0)
/*  f0f9450:	01402825 */ 	or	$a1,$t2,$zero
/*  f0f9454:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f0f9458:	a04f0e40 */ 	sb	$t7,0xe40($v0)
/*  f0f945c:	90580e40 */ 	lbu	$t8,0xe40($v0)
.L0f0f9460:
/*  f0f9460:	a3a000da */ 	sb	$zero,0xda($sp)
/*  f0f9464:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0f9468:	3319ff7f */ 	andi	$t9,$t8,0xff7f
/*  f0f946c:	a0590e40 */ 	sb	$t9,0xe40($v0)
/*  f0f9470:	92280003 */ 	lbu	$t0,0x3($s1)
/*  f0f9474:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0f9478:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0f947c:	a3a800db */ 	sb	$t0,0xdb($sp)
/*  f0f9480:	82290000 */ 	lb	$t1,0x0($s1)
/*  f0f9484:	44807000 */ 	mtc1	$zero,$f14
/*  f0f9488:	a3a900d8 */ 	sb	$t1,0xd8($sp)
/*  f0f948c:	822a0001 */ 	lb	$t2,0x1($s1)
/*  f0f9490:	a3aa00d9 */ 	sb	$t2,0xd9($sp)
/*  f0f9494:	822b0004 */ 	lb	$t3,0x4($s1)
/*  f0f9498:	a3ab00dc */ 	sb	$t3,0xdc($sp)
/*  f0f949c:	822c0005 */ 	lb	$t4,0x5($s1)
/*  f0f94a0:	a3ac00dd */ 	sb	$t4,0xdd($sp)
/*  f0f94a4:	822d0008 */ 	lb	$t5,0x8($s1)
/*  f0f94a8:	a3ad00e0 */ 	sb	$t5,0xe0($sp)
/*  f0f94ac:	822e0009 */ 	lb	$t6,0x9($s1)
/*  f0f94b0:	a3a000e2 */ 	sb	$zero,0xe2($sp)
/*  f0f94b4:	a3ae00e1 */ 	sb	$t6,0xe1($sp)
/*  f0f94b8:	8e2f000c */ 	lw	$t7,0xc($s1)
/*  f0f94bc:	afaf00e4 */ 	sw	$t7,0xe4($sp)
/*  f0f94c0:	8e380010 */ 	lw	$t8,0x10($s1)
/*  f0f94c4:	afb800e8 */ 	sw	$t8,0xe8($sp)
/*  f0f94c8:	8fd90054 */ 	lw	$t9,0x54($s8)
/*  f0f94cc:	8fc9005c */ 	lw	$t1,0x5c($s8)
/*  f0f94d0:	c7c00040 */ 	lwc1	$f0,0x40($s8)
/*  f0f94d4:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0f94d8:	afc80054 */ 	sw	$t0,0x54($s8)
/*  f0f94dc:	8cea0000 */ 	lw	$t2,0x0($a3)
/*  f0f94e0:	01006025 */ 	or	$t4,$t0,$zero
/*  f0f94e4:	3c198007 */ 	lui	$t9,0x8007
/*  f0f94e8:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f0f94ec:	0164001a */ 	div	$zero,$t3,$a0
/*  f0f94f0:	00006812 */ 	mflo	$t5
/*  f0f94f4:	00007810 */ 	mfhi	$t7
/*  f0f94f8:	afcb005c */ 	sw	$t3,0x5c($s8)
/*  f0f94fc:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0f9500:	afce0054 */ 	sw	$t6,0x54($s8)
/*  f0f9504:	afcf005c */ 	sw	$t7,0x5c($s8)
/*  f0f9508:	8f3914dc */ 	lw	$t9,0x14dc($t9)
/*  f0f950c:	01601825 */ 	or	$v1,$t3,$zero
/*  f0f9510:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0f9514:	01d9001b */ 	divu	$zero,$t6,$t9
/*  f0f9518:	14800002 */ 	bnez	$a0,.L0f0f9524
/*  f0f951c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9520:	0007000d */ 	break	0x7
.L0f0f9524:
/*  f0f9524:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f9528:	14810004 */ 	bne	$a0,$at,.L0f0f953c
/*  f0f952c:	3c018000 */ 	lui	$at,0x8000
/*  f0f9530:	14610002 */ 	bne	$v1,$at,.L0f0f953c
/*  f0f9534:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9538:	0006000d */ 	break	0x6
.L0f0f953c:
/*  f0f953c:	00004010 */ 	mfhi	$t0
/*  f0f9540:	afc80054 */ 	sw	$t0,0x54($s8)
/*  f0f9544:	01c0c025 */ 	or	$t8,$t6,$zero
/*  f0f9548:	17200002 */ 	bnez	$t9,.L0f0f9554
/*  f0f954c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9550:	0007000d */ 	break	0x7
.L0f0f9554:
/*  f0f9554:	4500004b */ 	bc1f	.L0f0f9684
/*  f0f9558:	3c048007 */ 	lui	$a0,0x8007
/*  f0f955c:	8c841448 */ 	lw	$a0,0x1448($a0)
/*  f0f9560:	3c0a800a */ 	lui	$t2,0x800a
/*  f0f9564:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f9568:	000448c0 */ 	sll	$t1,$a0,0x3
/*  f0f956c:	01244823 */ 	subu	$t1,$t1,$a0
/*  f0f9570:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0f9574:	01244821 */ 	addu	$t1,$t1,$a0
/*  f0f9578:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f0f957c:	01244823 */ 	subu	$t1,$t1,$a0
/*  f0f9580:	00094900 */ 	sll	$t1,$t1,0x4
/*  f0f9584:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0f9588:	8d4ae4f8 */ 	lw	$t2,-0x1b08($t2)
/*  f0f958c:	57ca0034 */ 	bnel	$s8,$t2,.L0f0f9660
/*  f0f9590:	93c9003c */ 	lbu	$t1,0x3c($s8)
/*  f0f9594:	92700000 */ 	lbu	$s0,0x0($s3)
/*  f0f9598:	0fc62ff6 */ 	jal	mpIsPlayerLockedOut
/*  f0f959c:	afb10124 */ 	sw	$s1,0x124($sp)
/*  f0f95a0:	44807000 */ 	mtc1	$zero,$f14
/*  f0f95a4:	10400007 */ 	beqz	$v0,.L0f0f95c4
/*  f0f95a8:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f95ac:	8fcb0000 */ 	lw	$t3,0x0($s8)
/*  f0f95b0:	8d6c0010 */ 	lw	$t4,0x10($t3)
/*  f0f95b4:	318d0010 */ 	andi	$t5,$t4,0x10
/*  f0f95b8:	11a00002 */ 	beqz	$t5,.L0f0f95c4
/*  f0f95bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f95c0:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f0f95c4:
/*  f0f95c4:	8dce19c4 */ 	lw	$t6,0x19c4($t6)
/*  f0f95c8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f95cc:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0f95d0:	15c10017 */ 	bne	$t6,$at,.L0f0f9630
/*  f0f95d4:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0f95d8:	3c02800a */ 	lui	$v0,0x800a
/*  f0f95dc:	904219d4 */ 	lbu	$v0,0x19d4($v0)
/*  f0f95e0:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f95e4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0f95e8:	10410004 */ 	beq	$v0,$at,.L0f0f95fc
/*  f0f95ec:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f0f95f0:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0f95f4:	14410002 */ 	bne	$v0,$at,.L0f0f9600
/*  f0f95f8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f95fc:
/*  f0f95fc:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0f9600:
/*  f0f9600:	8deffc00 */ 	lw	$t7,-0x400($t7)
/*  f0f9604:	24010019 */ 	addiu	$at,$zero,0x19
/*  f0f9608:	55e1000a */ 	bnel	$t7,$at,.L0f0f9634
/*  f0f960c:	93c8003c */ 	lbu	$t0,0x3c($s8)
/*  f0f9610:	12420007 */ 	beq	$s2,$v0,.L0f0f9630
/*  f0f9614:	3c18800a */ 	lui	$t8,0x800a
/*  f0f9618:	931819d5 */ 	lbu	$t8,0x19d5($t8)
/*  f0f961c:	24190005 */ 	addiu	$t9,$zero,0x5
/*  f0f9620:	52580004 */ 	beql	$s2,$t8,.L0f0f9634
/*  f0f9624:	93c8003c */ 	lbu	$t0,0x3c($s8)
/*  f0f9628:	24100005 */ 	addiu	$s0,$zero,0x5
/*  f0f962c:	a3d9003c */ 	sb	$t9,0x3c($s8)
.L0f0f9630:
/*  f0f9630:	93c8003c */ 	lbu	$t0,0x3c($s8)
.L0f0f9634:
/*  f0f9634:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f9638:	44816000 */ 	mtc1	$at,$f12
/*  f0f963c:	12080005 */ 	beq	$s0,$t0,.L0f0f9654
/*  f0f9640:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f0f9644:	44802000 */ 	mtc1	$zero,$f4
/*  f0f9648:	a3d0003d */ 	sb	$s0,0x3d($s8)
/*  f0f964c:	afc00044 */ 	sw	$zero,0x44($s8)
/*  f0f9650:	e7c40040 */ 	swc1	$f4,0x40($s8)
.L0f0f9654:
/*  f0f9654:	10000072 */ 	beqz	$zero,.L0f0f9820
/*  f0f9658:	8fb10124 */ 	lw	$s1,0x124($sp)
/*  f0f965c:	93c9003c */ 	lbu	$t1,0x3c($s8)
.L0f0f9660:
/*  f0f9660:	44816000 */ 	mtc1	$at,$f12
/*  f0f9664:	11200005 */ 	beqz	$t1,.L0f0f967c
/*  f0f9668:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f966c:	44803000 */ 	mtc1	$zero,$f6
/*  f0f9670:	a3c0003d */ 	sb	$zero,0x3d($s8)
/*  f0f9674:	afc00044 */ 	sw	$zero,0x44($s8)
/*  f0f9678:	e7c60040 */ 	swc1	$f6,0x40($s8)
.L0f0f967c:
/*  f0f967c:	10000068 */ 	beqz	$zero,.L0f0f9820
/*  f0f9680:	24120003 */ 	addiu	$s2,$zero,0x3
.L0f0f9684:
/*  f0f9684:	3c02800a */ 	lui	$v0,0x800a
/*  f0f9688:	8c4219c4 */ 	lw	$v0,0x19c4($v0)
/*  f0f968c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f9690:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0f9694:	54410017 */ 	bnel	$v0,$at,.L0f0f96f4
/*  f0f9698:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f969c:	8d4afc00 */ 	lw	$t2,-0x400($t2)
/*  f0f96a0:	24010019 */ 	addiu	$at,$zero,0x19
/*  f0f96a4:	3c0b800a */ 	lui	$t3,0x800a
/*  f0f96a8:	55410012 */ 	bnel	$t2,$at,.L0f0f96f4
/*  f0f96ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f96b0:	916b19d4 */ 	lbu	$t3,0x19d4($t3)
/*  f0f96b4:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f0f96b8:	3c0c800a */ 	lui	$t4,0x800a
/*  f0f96bc:	524b000d */ 	beql	$s2,$t3,.L0f0f96f4
/*  f0f96c0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f96c4:	918c19d5 */ 	lbu	$t4,0x19d5($t4)
/*  f0f96c8:	524c000a */ 	beql	$s2,$t4,.L0f0f96f4
/*  f0f96cc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f96d0:	93cd003d */ 	lbu	$t5,0x3d($s8)
/*  f0f96d4:	240e0005 */ 	addiu	$t6,$zero,0x5
/*  f0f96d8:	51a00006 */ 	beqzl	$t5,.L0f0f96f4
/*  f0f96dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f96e0:	a3ce003d */ 	sb	$t6,0x3d($s8)
/*  f0f96e4:	3c02800a */ 	lui	$v0,0x800a
/*  f0f96e8:	8c4219c4 */ 	lw	$v0,0x19c4($v0)
/*  f0f96ec:	c7c00040 */ 	lwc1	$f0,0x40($s8)
/*  f0f96f0:	24010001 */ 	addiu	$at,$zero,0x1
.L0f0f96f4:
/*  f0f96f4:	14410011 */ 	bne	$v0,$at,.L0f0f973c
/*  f0f96f8:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f0f96fc:	93cf003c */ 	lbu	$t7,0x3c($s8)
/*  f0f9700:	3c02800a */ 	lui	$v0,0x800a
/*  f0f9704:	164f000d */ 	bne	$s2,$t7,.L0f0f973c
/*  f0f9708:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f970c:	904219d4 */ 	lbu	$v0,0x19d4($v0)
/*  f0f9710:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f9714:	10410002 */ 	beq	$v0,$at,.L0f0f9720
/*  f0f9718:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0f971c:	14410007 */ 	bne	$v0,$at,.L0f0f973c
.L0f0f9720:
/*  f0f9720:	3c017f1b */ 	lui	$at,%hi(var7f1b2a10)
/*  f0f9724:	c42a2a10 */ 	lwc1	$f10,%lo(var7f1b2a10)($at)
/*  f0f9728:	c4e80004 */ 	lwc1	$f8,0x4($a3)
/*  f0f972c:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0f9730:	46120100 */ 	add.s	$f4,$f0,$f18
/*  f0f9734:	10000007 */ 	beqz	$zero,.L0f0f9754
/*  f0f9738:	e7c40040 */ 	swc1	$f4,0x40($s8)
.L0f0f973c:
/*  f0f973c:	3c017f1b */ 	lui	$at,%hi(var7f1b2a14)
/*  f0f9740:	c4282a14 */ 	lwc1	$f8,%lo(var7f1b2a14)($at)
/*  f0f9744:	c4e60004 */ 	lwc1	$f6,0x4($a3)
/*  f0f9748:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0f974c:	460a0480 */ 	add.s	$f18,$f0,$f10
/*  f0f9750:	e7d20040 */ 	swc1	$f18,0x40($s8)
.L0f0f9754:
/*  f0f9754:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f9758:	44816000 */ 	mtc1	$at,$f12
/*  f0f975c:	c7c00040 */ 	lwc1	$f0,0x40($s8)
/*  f0f9760:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f9764:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0f9768:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f976c:	45020007 */ 	bc1fl	.L0f0f978c
/*  f0f9770:	3c01437f */ 	lui	$at,0x437f
/*  f0f9774:	44812000 */ 	mtc1	$at,$f4
/*  f0f9778:	93d8003d */ 	lbu	$t8,0x3d($s8)
/*  f0f977c:	e7c40040 */ 	swc1	$f4,0x40($s8)
/*  f0f9780:	c7c00040 */ 	lwc1	$f0,0x40($s8)
/*  f0f9784:	a3d8003c */ 	sb	$t8,0x3c($s8)
/*  f0f9788:	3c01437f */ 	lui	$at,0x437f
.L0f0f978c:
/*  f0f978c:	44813000 */ 	mtc1	$at,$f6
/*  f0f9790:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f9794:	3c014f00 */ 	lui	$at,0x4f00
/*  f0f9798:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0f979c:	4459f800 */ 	cfc1	$t9,$31
/*  f0f97a0:	44c8f800 */ 	ctc1	$t0,$31
/*  f0f97a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f97a8:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0f97ac:	4448f800 */ 	cfc1	$t0,$31
/*  f0f97b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f97b4:	31080078 */ 	andi	$t0,$t0,0x78
/*  f0f97b8:	51000013 */ 	beqzl	$t0,.L0f0f9808
/*  f0f97bc:	44085000 */ 	mfc1	$t0,$f10
/*  f0f97c0:	44815000 */ 	mtc1	$at,$f10
/*  f0f97c4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f97c8:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0f97cc:	44c8f800 */ 	ctc1	$t0,$31
/*  f0f97d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f97d4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0f97d8:	4448f800 */ 	cfc1	$t0,$31
/*  f0f97dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f97e0:	31080078 */ 	andi	$t0,$t0,0x78
/*  f0f97e4:	15000005 */ 	bnez	$t0,.L0f0f97fc
/*  f0f97e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f97ec:	44085000 */ 	mfc1	$t0,$f10
/*  f0f97f0:	3c018000 */ 	lui	$at,0x8000
/*  f0f97f4:	10000007 */ 	beqz	$zero,.L0f0f9814
/*  f0f97f8:	01014025 */ 	or	$t0,$t0,$at
.L0f0f97fc:
/*  f0f97fc:	10000005 */ 	beqz	$zero,.L0f0f9814
/*  f0f9800:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0f9804:	44085000 */ 	mfc1	$t0,$f10
.L0f0f9808:
/*  f0f9808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f980c:	0500fffb */ 	bltz	$t0,.L0f0f97fc
/*  f0f9810:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f9814:
/*  f0f9814:	44d9f800 */ 	ctc1	$t9,$31
/*  f0f9818:	afc80044 */ 	sw	$t0,0x44($s8)
/*  f0f981c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f9820:
/*  f0f9820:	93c20060 */ 	lbu	$v0,0x60($s8)
/*  f0f9824:	1642001b */ 	bne	$s2,$v0,.L0f0f9894
/*  f0f9828:	3c09800a */ 	lui	$t1,0x800a
/*  f0f982c:	912919d5 */ 	lbu	$t1,0x19d5($t1)
/*  f0f9830:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f9834:	51210018 */ 	beql	$t1,$at,.L0f0f9898
/*  f0f9838:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f983c:	c7d20048 */ 	lwc1	$f18,0x48($s8)
/*  f0f9840:	3c0142f0 */ 	lui	$at,0x42f0
/*  f0f9844:	460e903c */ 	c.lt.s	$f18,$f14
/*  f0f9848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f984c:	45020010 */ 	bc1fl	.L0f0f9890
/*  f0f9850:	e7ce0050 */ 	swc1	$f14,0x50($s8)
/*  f0f9854:	c4e40004 */ 	lwc1	$f4,0x4($a3)
/*  f0f9858:	44813000 */ 	mtc1	$at,$f6
/*  f0f985c:	c7ca0050 */ 	lwc1	$f10,0x50($s8)
/*  f0f9860:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f0f9864:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f0f9868:	e7d20050 */ 	swc1	$f18,0x50($s8)
/*  f0f986c:	c7c40050 */ 	lwc1	$f4,0x50($s8)
/*  f0f9870:	4604603c */ 	c.lt.s	$f12,$f4
/*  f0f9874:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9878:	45000002 */ 	bc1f	.L0f0f9884
/*  f0f987c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9880:	e7ce0048 */ 	swc1	$f14,0x48($s8)
.L0f0f9884:
/*  f0f9884:	10000003 */ 	beqz	$zero,.L0f0f9894
/*  f0f9888:	93c20060 */ 	lbu	$v0,0x60($s8)
/*  f0f988c:	e7ce0050 */ 	swc1	$f14,0x50($s8)
.L0f0f9890:
/*  f0f9890:	93c20060 */ 	lbu	$v0,0x60($s8)
.L0f0f9894:
/*  f0f9894:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0f9898:
/*  f0f9898:	14410014 */ 	bne	$v0,$at,.L0f0f98ec
/*  f0f989c:	3c017f1b */ 	lui	$at,%hi(var7f1b2a18)
/*  f0f98a0:	c4262a18 */ 	lwc1	$f6,%lo(var7f1b2a18)($at)
/*  f0f98a4:	c4ea0004 */ 	lwc1	$f10,0x4($a3)
/*  f0f98a8:	c7d20050 */ 	lwc1	$f18,0x50($s8)
/*  f0f98ac:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0f98b0:	46089101 */ 	sub.s	$f4,$f18,$f8
/*  f0f98b4:	e7c40050 */ 	swc1	$f4,0x50($s8)
/*  f0f98b8:	c7c60050 */ 	lwc1	$f6,0x50($s8)
/*  f0f98bc:	460e303c */ 	c.lt.s	$f6,$f14
/*  f0f98c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f98c4:	4502000a */ 	bc1fl	.L0f0f98f0
/*  f0f98c8:	93cb0060 */ 	lbu	$t3,0x60($s8)
/*  f0f98cc:	c7ca0048 */ 	lwc1	$f10,0x48($s8)
/*  f0f98d0:	e7ce0050 */ 	swc1	$f14,0x50($s8)
/*  f0f98d4:	240a0003 */ 	addiu	$t2,$zero,0x3
/*  f0f98d8:	460e503c */ 	c.lt.s	$f10,$f14
/*  f0f98dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f98e0:	45020003 */ 	bc1fl	.L0f0f98f0
/*  f0f98e4:	93cb0060 */ 	lbu	$t3,0x60($s8)
/*  f0f98e8:	a3ca0060 */ 	sb	$t2,0x60($s8)
.L0f0f98ec:
/*  f0f98ec:	93cb0060 */ 	lbu	$t3,0x60($s8)
.L0f0f98f0:
/*  f0f98f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f98f4:	5561003d */ 	bnel	$t3,$at,.L0f0f99ec
/*  f0f98f8:	93c90060 */ 	lbu	$t1,0x60($s8)
/*  f0f98fc:	8fcd0020 */ 	lw	$t5,0x20($s8)
/*  f0f9900:	c7c00050 */ 	lwc1	$f0,0x50($s8)
/*  f0f9904:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f9908:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f0f990c:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f0f9910:	44039000 */ 	mfc1	$v1,$f18
/*  f0f9914:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9918:	00602025 */ 	or	$a0,$v1,$zero
/*  f0f991c:	46001032 */ 	c.eq.s	$f2,$f0
/*  f0f9920:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9924:	45010018 */ 	bc1t	.L0f0f9988
/*  f0f9928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f992c:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0f9930:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f9934:	3c017f1b */ 	lui	$at,%hi(var7f1b2a1c)
/*  f0f9938:	19c00013 */ 	blez	$t6,.L0f0f9988
/*  f0f993c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9940:	c4242a1c */ 	lwc1	$f4,%lo(var7f1b2a1c)($at)
/*  f0f9944:	3c017f1b */ 	lui	$at,%hi(var7f1b2a20)
/*  f0f9948:	c4302a20 */ 	lwc1	$f16,%lo(var7f1b2a20)($at)
/*  f0f994c:	46041002 */ 	mul.s	$f0,$f2,$f4
/*  f0f9950:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9954:	c7c60050 */ 	lwc1	$f6,0x50($s8)
.L0f0f9958:
/*  f0f9958:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f995c:	46068282 */ 	mul.s	$f10,$f16,$f6
/*  f0f9960:	460a0480 */ 	add.s	$f18,$f0,$f10
/*  f0f9964:	e7d20050 */ 	swc1	$f18,0x50($s8)
/*  f0f9968:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f0f996c:	004f082a */ 	slt	$at,$v0,$t7
/*  f0f9970:	5420fff9 */ 	bnezl	$at,.L0f0f9958
/*  f0f9974:	c7c60050 */ 	lwc1	$f6,0x50($s8)
/*  f0f9978:	c7c00050 */ 	lwc1	$f0,0x50($s8)
/*  f0f997c:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f0f9980:	44034000 */ 	mfc1	$v1,$f8
/*  f0f9984:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f9988:
/*  f0f9988:	5483000b */ 	bnel	$a0,$v1,.L0f0f99b8
/*  f0f998c:	460c1201 */ 	sub.s	$f8,$f2,$f12
/*  f0f9990:	44842000 */ 	mtc1	$a0,$f4
/*  f0f9994:	8fd90020 */ 	lw	$t9,0x20($s8)
/*  f0f9998:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f999c:	44999000 */ 	mtc1	$t9,$f18
/*  f0f99a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f99a4:	468090a0 */ 	cvt.s.w	$f2,$f18
/*  f0f99a8:	460c3280 */ 	add.s	$f10,$f6,$f12
/*  f0f99ac:	e7ca0050 */ 	swc1	$f10,0x50($s8)
/*  f0f99b0:	c7c00050 */ 	lwc1	$f0,0x50($s8)
/*  f0f99b4:	460c1201 */ 	sub.s	$f8,$f2,$f12
.L0f0f99b8:
/*  f0f99b8:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0f99bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f99c0:	4502000a */ 	bc1fl	.L0f0f99ec
/*  f0f99c4:	93c90060 */ 	lbu	$t1,0x60($s8)
/*  f0f99c8:	460c1100 */ 	add.s	$f4,$f2,$f12
/*  f0f99cc:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f0f99d0:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0f99d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f99d8:	45020004 */ 	bc1fl	.L0f0f99ec
/*  f0f99dc:	93c90060 */ 	lbu	$t1,0x60($s8)
/*  f0f99e0:	a3c80060 */ 	sb	$t0,0x60($s8)
/*  f0f99e4:	e7cc0050 */ 	swc1	$f12,0x50($s8)
/*  f0f99e8:	93c90060 */ 	lbu	$t1,0x60($s8)
.L0f0f99ec:
/*  f0f99ec:	55200053 */ 	bnezl	$t1,.L0f0f9b3c
/*  f0f99f0:	c7c00048 */ 	lwc1	$f0,0x48($s8)
/*  f0f99f4:	8fcb0000 */ 	lw	$t3,0x0($s8)
/*  f0f99f8:	3c0a8008 */ 	lui	$t2,%hi(g_MpReadyMenuDialog)
/*  f0f99fc:	254a57b8 */ 	addiu	$t2,$t2,%lo(g_MpReadyMenuDialog)
/*  f0f9a00:	154b0013 */ 	bne	$t2,$t3,.L0f0f9a50
/*  f0f9a04:	3c017f1b */ 	lui	$at,%hi(var7f1b2a2c)
/*  f0f9a08:	c7c00050 */ 	lwc1	$f0,0x50($s8)
/*  f0f9a0c:	c4262a2c */ 	lwc1	$f6,%lo(var7f1b2a2c)($at)
/*  f0f9a10:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f9a14:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f9a18:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0f9a1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9a20:	45020007 */ 	bc1fl	.L0f0f9a40
/*  f0f9a24:	44814000 */ 	mtc1	$at,$f8
/*  f0f9a28:	3c017f1b */ 	lui	$at,%hi(var7f1b2a30)
/*  f0f9a2c:	c42a2a30 */ 	lwc1	$f10,%lo(var7f1b2a30)($at)
/*  f0f9a30:	460a0480 */ 	add.s	$f18,$f0,$f10
/*  f0f9a34:	10000040 */ 	beqz	$zero,.L0f0f9b38
/*  f0f9a38:	e7d20050 */ 	swc1	$f18,0x50($s8)
/*  f0f9a3c:	44814000 */ 	mtc1	$at,$f8
.L0f0f9a40:
/*  f0f9a40:	a3cc0060 */ 	sb	$t4,0x60($s8)
/*  f0f9a44:	e7ce0048 */ 	swc1	$f14,0x48($s8)
/*  f0f9a48:	1000003b */ 	beqz	$zero,.L0f0f9b38
/*  f0f9a4c:	e7c80050 */ 	swc1	$f8,0x50($s8)
.L0f0f9a50:
/*  f0f9a50:	8ced0298 */ 	lw	$t5,0x298($a3)
/*  f0f9a54:	05a10005 */ 	bgez	$t5,.L0f0f9a6c
/*  f0f9a58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9a5c:	8cee029c */ 	lw	$t6,0x29c($a3)
/*  f0f9a60:	afb10124 */ 	sw	$s1,0x124($sp)
/*  f0f9a64:	05c00024 */ 	bltz	$t6,.L0f0f9af8
/*  f0f9a68:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f9a6c:
/*  f0f9a6c:	0fc3f303 */ 	jal	func0f0fcc0c
/*  f0f9a70:	afb10124 */ 	sw	$s1,0x124($sp)
/*  f0f9a74:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f9a78:	44816000 */ 	mtc1	$at,$f12
/*  f0f9a7c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f9a80:	44807000 */ 	mtc1	$zero,$f14
/*  f0f9a84:	1441001c */ 	bne	$v0,$at,.L0f0f9af8
/*  f0f9a88:	3c0f800a */ 	lui	$t7,0x800a
/*  f0f9a8c:	8defdfc0 */ 	lw	$t7,-0x2040($t7)
/*  f0f9a90:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0f9a94:	3c18800a */ 	lui	$t8,0x800a
/*  f0f9a98:	11e00015 */ 	beqz	$t7,.L0f0f9af0
/*  f0f9a9c:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0f9aa0:	8f18a000 */ 	lw	$t8,-0x6000($t8)
/*  f0f9aa4:	3c014270 */ 	lui	$at,0x4270
/*  f0f9aa8:	44815000 */ 	mtc1	$at,$f10
/*  f0f9aac:	44982000 */ 	mtc1	$t8,$f4
/*  f0f9ab0:	c7c80050 */ 	lwc1	$f8,0x50($s8)
/*  f0f9ab4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f9ab8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f9abc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f9ac0:	460a3483 */ 	div.s	$f18,$f6,$f10
/*  f0f9ac4:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f0f9ac8:	e7c40050 */ 	swc1	$f4,0x50($s8)
/*  f0f9acc:	c7c60050 */ 	lwc1	$f6,0x50($s8)
/*  f0f9ad0:	4606603c */ 	c.lt.s	$f12,$f6
/*  f0f9ad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9ad8:	45000005 */ 	bc1f	.L0f0f9af0
/*  f0f9adc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9ae0:	44815000 */ 	mtc1	$at,$f10
/*  f0f9ae4:	a3d90060 */ 	sb	$t9,0x60($s8)
/*  f0f9ae8:	e7ce0048 */ 	swc1	$f14,0x48($s8)
/*  f0f9aec:	e7ca0050 */ 	swc1	$f10,0x50($s8)
.L0f0f9af0:
/*  f0f9af0:	10000011 */ 	beqz	$zero,.L0f0f9b38
/*  f0f9af4:	8fb10124 */ 	lw	$s1,0x124($sp)
.L0f0f9af8:
/*  f0f9af8:	3c08800a */ 	lui	$t0,0x800a
/*  f0f9afc:	910819d5 */ 	lbu	$t0,0x19d5($t0)
/*  f0f9b00:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0f9b04:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0f9b08:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0f9b0c:	11010004 */ 	beq	$t0,$at,.L0f0f9b20
/*  f0f9b10:	8fb10124 */ 	lw	$s1,0x124($sp)
/*  f0f9b14:	3c09800a */ 	lui	$t1,0x800a
/*  f0f9b18:	912919d4 */ 	lbu	$t1,0x19d4($t1)
/*  f0f9b1c:	11200006 */ 	beqz	$t1,.L0f0f9b38
.L0f0f9b20:
/*  f0f9b20:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f9b24:	44814000 */ 	mtc1	$at,$f8
/*  f0f9b28:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f9b2c:	a3ca0060 */ 	sb	$t2,0x60($s8)
/*  f0f9b30:	e7ce0048 */ 	swc1	$f14,0x48($s8)
/*  f0f9b34:	e7c80050 */ 	swc1	$f8,0x50($s8)
.L0f0f9b38:
/*  f0f9b38:	c7c00048 */ 	lwc1	$f0,0x48($s8)
.L0f0f9b3c:
/*  f0f9b3c:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0f9b40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9b44:	4503001e */ 	bc1tl	.L0f0f9bc0
/*  f0f9b48:	8fc40000 */ 	lw	$a0,0x0($s8)
/*  f0f9b4c:	93cb0060 */ 	lbu	$t3,0x60($s8)
/*  f0f9b50:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f0f9b54:	3c014416 */ 	lui	$at,0x4416
/*  f0f9b58:	164b0008 */ 	bne	$s2,$t3,.L0f0f9b7c
/*  f0f9b5c:	00036880 */ 	sll	$t5,$v1,0x2
/*  f0f9b60:	00036040 */ 	sll	$t4,$v1,0x1
/*  f0f9b64:	448c9000 */ 	mtc1	$t4,$f18
/*  f0f9b68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9b6c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f9b70:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f0f9b74:	10000007 */ 	beqz	$zero,.L0f0f9b94
/*  f0f9b78:	e7c60048 */ 	swc1	$f6,0x48($s8)
.L0f0f9b7c:
/*  f0f9b7c:	01a36821 */ 	addu	$t5,$t5,$v1
/*  f0f9b80:	448d5000 */ 	mtc1	$t5,$f10
/*  f0f9b84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9b88:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0f9b8c:	46080480 */ 	add.s	$f18,$f0,$f8
/*  f0f9b90:	e7d20048 */ 	swc1	$f18,0x48($s8)
.L0f0f9b94:
/*  f0f9b94:	44812000 */ 	mtc1	$at,$f4
/*  f0f9b98:	c7c60048 */ 	lwc1	$f6,0x48($s8)
/*  f0f9b9c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f9ba0:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0f9ba4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9ba8:	45020005 */ 	bc1fl	.L0f0f9bc0
/*  f0f9bac:	8fc40000 */ 	lw	$a0,0x0($s8)
/*  f0f9bb0:	44815000 */ 	mtc1	$at,$f10
/*  f0f9bb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9bb8:	e7ca0048 */ 	swc1	$f10,0x48($s8)
/*  f0f9bbc:	8fc40000 */ 	lw	$a0,0x0($s8)
.L0f0f9bc0:
/*  f0f9bc0:	afb10124 */ 	sw	$s1,0x124($sp)
/*  f0f9bc4:	8c8e0010 */ 	lw	$t6,0x10($a0)
/*  f0f9bc8:	31cf0200 */ 	andi	$t7,$t6,0x200
/*  f0f9bcc:	15e00004 */ 	bnez	$t7,.L0f0f9be0
/*  f0f9bd0:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0f9bd4:	8fa60114 */ 	lw	$a2,0x114($sp)
/*  f0f9bd8:	0fc3c84d */ 	jal	func0f0f2134
/*  f0f9bdc:	afb10124 */ 	sw	$s1,0x124($sp)
.L0f0f9be0:
/*  f0f9be0:	0fc3dfa6 */ 	jal	func0f0f7e98
/*  f0f9be4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0f9be8:	0fc3c7bd */ 	jal	func0f0f1ef4
/*  f0f9bec:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0f9bf0:	3c02800a */ 	lui	$v0,0x800a
/*  f0f9bf4:	8c4219c4 */ 	lw	$v0,0x19c4($v0)
/*  f0f9bf8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f9bfc:	10410005 */ 	beq	$v0,$at,.L0f0f9c14
/*  f0f9c00:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f9c04:	10410003 */ 	beq	$v0,$at,.L0f0f9c14
/*  f0f9c08:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f9c0c:	54410009 */ 	bnel	$v0,$at,.L0f0f9c34
/*  f0f9c10:	8fc5002c */ 	lw	$a1,0x2c($s8)
.L0f0f9c14:
/*  f0f9c14:	8fd8002c */ 	lw	$t8,0x2c($s8)
/*  f0f9c18:	8fd90030 */ 	lw	$t9,0x30($s8)
/*  f0f9c1c:	3c017f1b */ 	lui	$at,%hi(var7f1b2a40)
/*  f0f9c20:	afd80014 */ 	sw	$t8,0x14($s8)
/*  f0f9c24:	afd90018 */ 	sw	$t9,0x18($s8)
/*  f0f9c28:	1000004b */ 	beqz	$zero,.L0f0f9d58
/*  f0f9c2c:	c42c2a40 */ 	lwc1	$f12,%lo(var7f1b2a40)($at)
/*  f0f9c30:	8fc5002c */ 	lw	$a1,0x2c($s8)
.L0f0f9c34:
/*  f0f9c34:	8fc40014 */ 	lw	$a0,0x14($s8)
/*  f0f9c38:	3c03800a */ 	lui	$v1,0x800a
/*  f0f9c3c:	10a40021 */ 	beq	$a1,$a0,.L0f0f9cc4
/*  f0f9c40:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f9c44:	8c639fc0 */ 	lw	$v1,-0x6040($v1)
/*  f0f9c48:	44844000 */ 	mtc1	$a0,$f8
/*  f0f9c4c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f9c50:	1860000e */ 	blez	$v1,.L0f0f9c8c
/*  f0f9c54:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f0f9c58:	44859000 */ 	mtc1	$a1,$f18
/*  f0f9c5c:	3c017f1b */ 	lui	$at,%hi(var7f1b2a44)
/*  f0f9c60:	c4262a44 */ 	lwc1	$f6,%lo(var7f1b2a44)($at)
/*  f0f9c64:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f9c68:	3c017f1b */ 	lui	$at,%hi(var7f1b2a48)
/*  f0f9c6c:	c42c2a48 */ 	lwc1	$f12,%lo(var7f1b2a48)($at)
/*  f0f9c70:	46062082 */ 	mul.s	$f2,$f4,$f6
/*  f0f9c74:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f9c78:
/*  f0f9c78:	46006282 */ 	mul.s	$f10,$f12,$f0
/*  f0f9c7c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f9c80:	0043082a */ 	slt	$at,$v0,$v1
/*  f0f9c84:	1420fffc */ 	bnez	$at,.L0f0f9c78
/*  f0f9c88:	460a1000 */ 	add.s	$f0,$f2,$f10
.L0f0f9c8c:
/*  f0f9c8c:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f0f9c90:	44024000 */ 	mfc1	$v0,$f8
/*  f0f9c94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9c98:	10a2000a */ 	beq	$a1,$v0,.L0f0f9cc4
/*  f0f9c9c:	afc20014 */ 	sw	$v0,0x14($s8)
/*  f0f9ca0:	14c20008 */ 	bne	$a2,$v0,.L0f0f9cc4
/*  f0f9ca4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f9ca8:	0045082a */ 	slt	$at,$v0,$a1
/*  f0f9cac:	10200004 */ 	beqz	$at,.L0f0f9cc0
/*  f0f9cb0:	248affff */ 	addiu	$t2,$a0,-1
/*  f0f9cb4:	24490001 */ 	addiu	$t1,$v0,0x1
/*  f0f9cb8:	10000002 */ 	beqz	$zero,.L0f0f9cc4
/*  f0f9cbc:	afc90014 */ 	sw	$t1,0x14($s8)
.L0f0f9cc0:
/*  f0f9cc0:	afca0014 */ 	sw	$t2,0x14($s8)
.L0f0f9cc4:
/*  f0f9cc4:	8fc50030 */ 	lw	$a1,0x30($s8)
/*  f0f9cc8:	8fc40018 */ 	lw	$a0,0x18($s8)
/*  f0f9ccc:	3c017f1b */ 	lui	$at,%hi(var7f1b2a50)
/*  f0f9cd0:	c42c2a50 */ 	lwc1	$f12,%lo(var7f1b2a50)($at)
/*  f0f9cd4:	10a40020 */ 	beq	$a1,$a0,.L0f0f9d58
/*  f0f9cd8:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f9cdc:	3c03800a */ 	lui	$v1,0x800a
/*  f0f9ce0:	8c639fc0 */ 	lw	$v1,-0x6040($v1)
/*  f0f9ce4:	44849000 */ 	mtc1	$a0,$f18
/*  f0f9ce8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f9cec:	1860000c */ 	blez	$v1,.L0f0f9d20
/*  f0f9cf0:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f0f9cf4:	44852000 */ 	mtc1	$a1,$f4
/*  f0f9cf8:	3c017f1b */ 	lui	$at,%hi(var7f1b2a54)
/*  f0f9cfc:	c42a2a54 */ 	lwc1	$f10,%lo(var7f1b2a54)($at)
/*  f0f9d00:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f9d04:	460a3082 */ 	mul.s	$f2,$f6,$f10
/*  f0f9d08:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f9d0c:
/*  f0f9d0c:	46006202 */ 	mul.s	$f8,$f12,$f0
/*  f0f9d10:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f9d14:	0043082a */ 	slt	$at,$v0,$v1
/*  f0f9d18:	1420fffc */ 	bnez	$at,.L0f0f9d0c
/*  f0f9d1c:	46081000 */ 	add.s	$f0,$f2,$f8
.L0f0f9d20:
/*  f0f9d20:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f0f9d24:	44029000 */ 	mfc1	$v0,$f18
/*  f0f9d28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9d2c:	10a2000a */ 	beq	$a1,$v0,.L0f0f9d58
/*  f0f9d30:	afc20018 */ 	sw	$v0,0x18($s8)
/*  f0f9d34:	14c20008 */ 	bne	$a2,$v0,.L0f0f9d58
/*  f0f9d38:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f9d3c:	0045082a */ 	slt	$at,$v0,$a1
/*  f0f9d40:	10200004 */ 	beqz	$at,.L0f0f9d54
/*  f0f9d44:	248dffff */ 	addiu	$t5,$a0,-1
/*  f0f9d48:	244c0001 */ 	addiu	$t4,$v0,0x1
/*  f0f9d4c:	10000002 */ 	beqz	$zero,.L0f0f9d58
/*  f0f9d50:	afcc0018 */ 	sw	$t4,0x18($s8)
.L0f0f9d54:
/*  f0f9d54:	afcd0018 */ 	sw	$t5,0x18($s8)
.L0f0f9d58:
/*  f0f9d58:	8fc50034 */ 	lw	$a1,0x34($s8)
/*  f0f9d5c:	8fc4001c */ 	lw	$a0,0x1c($s8)
/*  f0f9d60:	3c03800a */ 	lui	$v1,0x800a
/*  f0f9d64:	10a4001f */ 	beq	$a1,$a0,.L0f0f9de4
/*  f0f9d68:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f9d6c:	8c639fc0 */ 	lw	$v1,-0x6040($v1)
/*  f0f9d70:	44842000 */ 	mtc1	$a0,$f4
/*  f0f9d74:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f9d78:	1860000c */ 	blez	$v1,.L0f0f9dac
/*  f0f9d7c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0f9d80:	44853000 */ 	mtc1	$a1,$f6
/*  f0f9d84:	3c017f1b */ 	lui	$at,%hi(var7f1b2a58)
/*  f0f9d88:	c4282a58 */ 	lwc1	$f8,%lo(var7f1b2a58)($at)
/*  f0f9d8c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0f9d90:	46085082 */ 	mul.s	$f2,$f10,$f8
/*  f0f9d94:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f9d98:
/*  f0f9d98:	46006482 */ 	mul.s	$f18,$f12,$f0
/*  f0f9d9c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f9da0:	0043082a */ 	slt	$at,$v0,$v1
/*  f0f9da4:	1420fffc */ 	bnez	$at,.L0f0f9d98
/*  f0f9da8:	46121000 */ 	add.s	$f0,$f2,$f18
.L0f0f9dac:
/*  f0f9dac:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f0f9db0:	44022000 */ 	mfc1	$v0,$f4
/*  f0f9db4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9db8:	10a2000a */ 	beq	$a1,$v0,.L0f0f9de4
/*  f0f9dbc:	afc2001c */ 	sw	$v0,0x1c($s8)
/*  f0f9dc0:	14c20008 */ 	bne	$a2,$v0,.L0f0f9de4
/*  f0f9dc4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f9dc8:	0045082a */ 	slt	$at,$v0,$a1
/*  f0f9dcc:	10200004 */ 	beqz	$at,.L0f0f9de0
/*  f0f9dd0:	2498ffff */ 	addiu	$t8,$a0,-1
/*  f0f9dd4:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f0f9dd8:	10000002 */ 	beqz	$zero,.L0f0f9de4
/*  f0f9ddc:	afcf001c */ 	sw	$t7,0x1c($s8)
.L0f0f9de0:
/*  f0f9de0:	afd8001c */ 	sw	$t8,0x1c($s8)
.L0f0f9de4:
/*  f0f9de4:	8fc50038 */ 	lw	$a1,0x38($s8)
/*  f0f9de8:	8fc40020 */ 	lw	$a0,0x20($s8)
/*  f0f9dec:	3c03800a */ 	lui	$v1,%hi(var800a044c)
/*  f0f9df0:	10a4001f */ 	beq	$a1,$a0,.L0f0f9e70
/*  f0f9df4:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f9df8:	8c639fc0 */ 	lw	$v1,-0x6040($v1)
/*  f0f9dfc:	44843000 */ 	mtc1	$a0,$f6
/*  f0f9e00:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f9e04:	1860000c */ 	blez	$v1,.L0f0f9e38
/*  f0f9e08:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f0f9e0c:	44855000 */ 	mtc1	$a1,$f10
/*  f0f9e10:	3c017f1b */ 	lui	$at,%hi(var7f1b2a5c)
/*  f0f9e14:	c4322a5c */ 	lwc1	$f18,%lo(var7f1b2a5c)($at)
/*  f0f9e18:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0f9e1c:	46124082 */ 	mul.s	$f2,$f8,$f18
/*  f0f9e20:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0f9e24:
/*  f0f9e24:	46006102 */ 	mul.s	$f4,$f12,$f0
/*  f0f9e28:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f9e2c:	0043082a */ 	slt	$at,$v0,$v1
/*  f0f9e30:	1420fffc */ 	bnez	$at,.L0f0f9e24
/*  f0f9e34:	46041000 */ 	add.s	$f0,$f2,$f4
.L0f0f9e38:
/*  f0f9e38:	4600018d */ 	trunc.w.s	$f6,$f0
/*  f0f9e3c:	44023000 */ 	mfc1	$v0,$f6
/*  f0f9e40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9e44:	10a2000a */ 	beq	$a1,$v0,.L0f0f9e70
/*  f0f9e48:	afc20020 */ 	sw	$v0,0x20($s8)
/*  f0f9e4c:	14c20008 */ 	bne	$a2,$v0,.L0f0f9e70
/*  f0f9e50:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f9e54:	0045082a */ 	slt	$at,$v0,$a1
/*  f0f9e58:	10200004 */ 	beqz	$at,.L0f0f9e6c
/*  f0f9e5c:	2489ffff */ 	addiu	$t1,$a0,-1
/*  f0f9e60:	24480001 */ 	addiu	$t0,$v0,0x1
/*  f0f9e64:	10000002 */ 	beqz	$zero,.L0f0f9e70
/*  f0f9e68:	afc80020 */ 	sw	$t0,0x20($s8)
.L0f0f9e6c:
/*  f0f9e6c:	afc90020 */ 	sw	$t1,0x20($s8)
.L0f0f9e70:
/*  f0f9e70:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f0f9e74:	24040066 */ 	addiu	$a0,$zero,0x66
/*  f0f9e78:	02602825 */ 	or	$a1,$s3,$zero
/*  f0f9e7c:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f0f9e80:	8e62000c */ 	lw	$v0,0xc($s3)
/*  f0f9e84:	50400004 */ 	beqzl	$v0,.L0f0f9e98
/*  f0f9e88:	8fcb000c */ 	lw	$t3,0xc($s8)
/*  f0f9e8c:	0040f809 */ 	jalr	$v0
/*  f0f9e90:	27a600f0 */ 	addiu	$a2,$sp,0xf0
/*  f0f9e94:	8fcb000c */ 	lw	$t3,0xc($s8)
.L0f0f9e98:
/*  f0f9e98:	3c0d800a */ 	lui	$t5,0x800a
/*  f0f9e9c:	27b600d8 */ 	addiu	$s6,$sp,0xd8
/*  f0f9ea0:	51600007 */ 	beqzl	$t3,.L0f0f9ec0
/*  f0f9ea4:	afc00010 */ 	sw	$zero,0x10($s8)
/*  f0f9ea8:	8fcc0010 */ 	lw	$t4,0x10($s8)
/*  f0f9eac:	8dad9fc0 */ 	lw	$t5,-0x6040($t5)
/*  f0f9eb0:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0f9eb4:	10000002 */ 	beqz	$zero,.L0f0f9ec0
/*  f0f9eb8:	afce0010 */ 	sw	$t6,0x10($s8)
/*  f0f9ebc:	afc00010 */ 	sw	$zero,0x10($s8)
.L0f0f9ec0:
/*  f0f9ec0:	93c30005 */ 	lbu	$v1,0x5($s8)
/*  f0f9ec4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f9ec8:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0f9ecc:	5860007c */ 	blezl	$v1,.L0f0fa0c0
/*  f0f9ed0:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0f9ed4:	93cf0004 */ 	lbu	$t7,0x4($s8)
.L0f0f9ed8:
/*  f0f9ed8:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0f9edc:	01e61021 */ 	addu	$v0,$t7,$a2
/*  f0f9ee0:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f0f9ee4:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f0f9ee8:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f0f9eec:	00b8b821 */ 	addu	$s7,$a1,$t8
/*  f0f9ef0:	92f90668 */ 	lbu	$t9,0x668($s7)
/*  f0f9ef4:	5b20006e */ 	blezl	$t9,.L0f0fa0b0
/*  f0f9ef8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0f9efc:	afa60104 */ 	sw	$a2,0x104($sp)
/*  f0f9f00:	96e80666 */ 	lhu	$t0,0x666($s7)
.L0f0f9f04:
/*  f0f9f04:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0f9f08:	8fcc0000 */ 	lw	$t4,0x0($s8)
/*  f0f9f0c:	01151021 */ 	addu	$v0,$t0,$s5
/*  f0f9f10:	00024880 */ 	sll	$t1,$v0,0x2
/*  f0f9f14:	00a9a021 */ 	addu	$s4,$a1,$t1
/*  f0f9f18:	928a04fe */ 	lbu	$t2,0x4fe($s4)
/*  f0f9f1c:	8d8d0008 */ 	lw	$t5,0x8($t4)
/*  f0f9f20:	3c048007 */ 	lui	$a0,0x8007
/*  f0f9f24:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f0f9f28:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0f9f2c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f9f30:	00009825 */ 	or	$s3,$zero,$zero
/*  f0f9f34:	8fb10124 */ 	lw	$s1,0x124($sp)
/*  f0f9f38:	8c841448 */ 	lw	$a0,0x1448($a0)
/*  f0f9f3c:	0fc62ff6 */ 	jal	mpIsPlayerLockedOut
/*  f0f9f40:	016d9021 */ 	addu	$s2,$t3,$t5
/*  f0f9f44:	50400008 */ 	beqzl	$v0,.L0f0f9f68
/*  f0f9f48:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f0f9f4c:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f0f9f50:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0f9f54:	05e30004 */ 	bgezl	$t7,.L0f0f9f68
/*  f0f9f58:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f0f9f5c:	10000013 */ 	beqz	$zero,.L0f0f9fac
/*  f0f9f60:	02c08825 */ 	or	$s1,$s6,$zero
/*  f0f9f64:	8e580004 */ 	lw	$t8,0x4($s2)
.L0f0f9f68:
/*  f0f9f68:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f0f9f6c:	07210009 */ 	bgez	$t9,.L0f0f9f94
/*  f0f9f70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9f74:	0fc62587 */ 	jal	func0f18961c
/*  f0f9f78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9f7c:	0fc62422 */ 	jal	func0f189088
/*  f0f9f80:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f9f84:	10500003 */ 	beq	$v0,$s0,.L0f0f9f94
/*  f0f9f88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f9f8c:	10000007 */ 	beqz	$zero,.L0f0f9fac
/*  f0f9f90:	02c08825 */ 	or	$s1,$s6,$zero
.L0f0f9f94:
/*  f0f9f94:	3c08800a */ 	lui	$t0,0x800a
/*  f0f9f98:	8d0819c4 */ 	lw	$t0,0x19c4($t0)
/*  f0f9f9c:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0f9fa0:	55010003 */ 	bnel	$t0,$at,.L0f0f9fb0
/*  f0f9fa4:	828204ff */ 	lb	$v0,0x4ff($s4)
/*  f0f9fa8:	02c08825 */ 	or	$s1,$s6,$zero
.L0f0f9fac:
/*  f0f9fac:	828204ff */ 	lb	$v0,0x4ff($s4)
.L0f0f9fb0:
/*  f0f9fb0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f9fb4:	8fa90114 */ 	lw	$t1,0x114($sp)
/*  f0f9fb8:	10410004 */ 	beq	$v0,$at,.L0f0f9fcc
/*  f0f9fbc:	3c0c8007 */ 	lui	$t4,0x8007
/*  f0f9fc0:	00025080 */ 	sll	$t2,$v0,0x2
/*  f0f9fc4:	012a9821 */ 	addu	$s3,$t1,$t2
/*  f0f9fc8:	267306dc */ 	addiu	$s3,$s3,0x6dc
.L0f0f9fcc:
/*  f0f9fcc:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f0f9fd0:	3c0d800a */ 	lui	$t5,0x800a
/*  f0f9fd4:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0f9fd8:	000c58c0 */ 	sll	$t3,$t4,0x3
/*  f0f9fdc:	016c5823 */ 	subu	$t3,$t3,$t4
/*  f0f9fe0:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f9fe4:	016c5821 */ 	addu	$t3,$t3,$t4
/*  f0f9fe8:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0f9fec:	016c5823 */ 	subu	$t3,$t3,$t4
/*  f0f9ff0:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f0f9ff4:	01ab6821 */ 	addu	$t5,$t5,$t3
/*  f0f9ff8:	8dadee40 */ 	lw	$t5,-0x11c0($t5)
/*  f0f9ffc:	000d77c2 */ 	srl	$t6,$t5,0x1f
/*  f0fa000:	55c00023 */ 	bnezl	$t6,.L0f0fa090
/*  f0fa004:	92e90668 */ 	lbu	$t1,0x668($s7)
/*  f0fa008:	8defdd58 */ 	lw	$t7,-0x22a8($t7)
/*  f0fa00c:	8fb40128 */ 	lw	$s4,0x128($sp)
/*  f0fa010:	15e0001e */ 	bnez	$t7,.L0f0fa08c
/*  f0fa014:	32980001 */ 	andi	$t8,$s4,0x1
/*  f0fa018:	13000017 */ 	beqz	$t8,.L0f0fa078
/*  f0fa01c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0fa020:	8fd90008 */ 	lw	$t9,0x8($s8)
/*  f0fa024:	56590015 */ 	bnel	$s2,$t9,.L0f0fa07c
/*  f0fa028:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0fa02c:	8fc8000c */ 	lw	$t0,0xc($s8)
/*  f0fa030:	36900002 */ 	ori	$s0,$s4,0x2
/*  f0fa034:	02402025 */ 	or	$a0,$s2,$zero
/*  f0fa038:	11000009 */ 	beqz	$t0,.L0f0fa060
/*  f0fa03c:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0fa040:	02402025 */ 	or	$a0,$s2,$zero
/*  f0fa044:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0fa048:	02203025 */ 	or	$a2,$s1,$zero
/*  f0fa04c:	36070004 */ 	ori	$a3,$s0,0x4
/*  f0fa050:	0fc3c1c1 */ 	jal	func0f0f0704
/*  f0fa054:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0fa058:	1000000c */ 	beqz	$zero,.L0f0fa08c
/*  f0fa05c:	afa2011c */ 	sw	$v0,0x11c($sp)
.L0f0fa060:
/*  f0fa060:	02203025 */ 	or	$a2,$s1,$zero
/*  f0fa064:	02003825 */ 	or	$a3,$s0,$zero
/*  f0fa068:	0fc3c1c1 */ 	jal	func0f0f0704
/*  f0fa06c:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0fa070:	10000006 */ 	beqz	$zero,.L0f0fa08c
/*  f0fa074:	afa2011c */ 	sw	$v0,0x11c($sp)
.L0f0fa078:
/*  f0fa078:	03c02825 */ 	or	$a1,$s8,$zero
.L0f0fa07c:
/*  f0fa07c:	02203025 */ 	or	$a2,$s1,$zero
/*  f0fa080:	02803825 */ 	or	$a3,$s4,$zero
/*  f0fa084:	0fc3c1c1 */ 	jal	func0f0f0704
/*  f0fa088:	afb30010 */ 	sw	$s3,0x10($sp)
.L0f0fa08c:
/*  f0fa08c:	92e90668 */ 	lbu	$t1,0x668($s7)
.L0f0fa090:
/*  f0fa090:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0fa094:	02a9082a */ 	slt	$at,$s5,$t1
/*  f0fa098:	5420ff9a */ 	bnezl	$at,.L0f0f9f04
/*  f0fa09c:	96e80666 */ 	lhu	$t0,0x666($s7)
/*  f0fa0a0:	93c30005 */ 	lbu	$v1,0x5($s8)
/*  f0fa0a4:	8fa60104 */ 	lw	$a2,0x104($sp)
/*  f0fa0a8:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0fa0ac:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f0fa0b0:
/*  f0fa0b0:	00c3082a */ 	slt	$at,$a2,$v1
/*  f0fa0b4:	5420ff88 */ 	bnezl	$at,.L0f0f9ed8
/*  f0fa0b8:	93cf0004 */ 	lbu	$t7,0x4($s8)
/*  f0fa0bc:	8fd00008 */ 	lw	$s0,0x8($s8)
.L0f0fa0c0:
/*  f0fa0c0:	1200000d */ 	beqz	$s0,.L0f0fa0f8
/*  f0fa0c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fa0c8:	0fc3c962 */ 	jal	func0f0f2588
/*  f0fa0cc:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0fa0d0:	10400009 */ 	beqz	$v0,.L0f0fa0f8
/*  f0fa0d4:	8faa0128 */ 	lw	$t2,0x128($sp)
/*  f0fa0d8:	314c0001 */ 	andi	$t4,$t2,0x1
/*  f0fa0dc:	11800006 */ 	beqz	$t4,.L0f0fa0f8
/*  f0fa0e0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0fa0e4:	8fae0124 */ 	lw	$t6,0x124($sp)
/*  f0fa0e8:	afab011c */ 	sw	$t3,0x11c($sp)
/*  f0fa0ec:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0fa0f0:	a1cd0001 */ 	sb	$t5,0x1($t6)
/*  f0fa0f4:	afc0000c */ 	sw	$zero,0xc($s8)
.L0f0fa0f8:
/*  f0fa0f8:	8faf011c */ 	lw	$t7,0x11c($sp)
/*  f0fa0fc:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f0fa100:	11e0006f */ 	beqz	$t7,.L0f0fa2c0
/*  f0fa104:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0fa108:	5320006e */ 	beqzl	$t9,.L0f0fa2c4
/*  f0fa10c:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa110:	8fc8000c */ 	lw	$t0,0xc($s8)
/*  f0fa114:	3c098007 */ 	lui	$t1,0x8007
/*  f0fa118:	5500006a */ 	bnezl	$t0,.L0f0fa2c4
/*  f0fa11c:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa120:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f0fa124:	3c0c800a */ 	lui	$t4,%hi(var8009e000)
/*  f0fa128:	258ce000 */ 	addiu	$t4,$t4,%lo(var8009e000)
/*  f0fa12c:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0fa130:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0fa134:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0fa138:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0fa13c:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0fa140:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0fa144:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0fa148:	014c1021 */ 	addu	$v0,$t2,$t4
/*  f0fa14c:	844b04f4 */ 	lh	$t3,0x4f4($v0)
/*  f0fa150:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa154:	8faf0124 */ 	lw	$t7,0x124($sp)
/*  f0fa158:	000b6880 */ 	sll	$t5,$t3,0x2
/*  f0fa15c:	01ab6823 */ 	subu	$t5,$t5,$t3
/*  f0fa160:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0fa164:	004d1821 */ 	addu	$v1,$v0,$t5
/*  f0fa168:	806e0460 */ 	lb	$t6,0x460($v1)
/*  f0fa16c:	2463044c */ 	addiu	$v1,$v1,%lo(var800a044c)
/*  f0fa170:	8fb90124 */ 	lw	$t9,0x124($sp)
/*  f0fa174:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0fa178:	1020000c */ 	beqz	$at,.L0f0fa1ac
/*  f0fa17c:	02008825 */ 	or	$s1,$s0,$zero
/*  f0fa180:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0fa184:	81e50000 */ 	lb	$a1,0x0($t7)
/*  f0fa188:	0fc3cb11 */ 	jal	func0f0f2c44
/*  f0fa18c:	81e60001 */ 	lb	$a2,0x1($t7)
/*  f0fa190:	8fd80008 */ 	lw	$t8,0x8($s8)
/*  f0fa194:	52380016 */ 	beql	$s1,$t8,.L0f0fa1f0
/*  f0fa198:	8fa90124 */ 	lw	$t1,0x124($sp)
/*  f0fa19c:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0fa1a0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0fa1a4:	10000012 */ 	beqz	$zero,.L0f0fa1f0
/*  f0fa1a8:	8fa90124 */ 	lw	$t1,0x124($sp)
.L0f0fa1ac:
/*  f0fa1ac:	02008825 */ 	or	$s1,$s0,$zero
/*  f0fa1b0:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0fa1b4:	83250000 */ 	lb	$a1,0x0($t9)
/*  f0fa1b8:	0fc3cb11 */ 	jal	func0f0f2c44
/*  f0fa1bc:	83260001 */ 	lb	$a2,0x1($t9)
/*  f0fa1c0:	10400005 */ 	beqz	$v0,.L0f0fa1d8
/*  f0fa1c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fa1c8:	0fc3e40c */ 	jal	func0f0f9030
/*  f0fa1cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa1d0:	10000007 */ 	beqz	$zero,.L0f0fa1f0
/*  f0fa1d4:	8fa90124 */ 	lw	$t1,0x124($sp)
.L0f0fa1d8:
/*  f0fa1d8:	8fc80008 */ 	lw	$t0,0x8($s8)
/*  f0fa1dc:	52280004 */ 	beql	$s1,$t0,.L0f0fa1f0
/*  f0fa1e0:	8fa90124 */ 	lw	$t1,0x124($sp)
/*  f0fa1e4:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0fa1e8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0fa1ec:	8fa90124 */ 	lw	$t1,0x124($sp)
.L0f0fa1f0:
/*  f0fa1f0:	91220003 */ 	lbu	$v0,0x3($t1)
/*  f0fa1f4:	50400020 */ 	beqzl	$v0,.L0f0fa278
/*  f0fa1f8:	8fcf0000 */ 	lw	$t7,0x0($s8)
/*  f0fa1fc:	8fca0000 */ 	lw	$t2,0x0($s8)
/*  f0fa200:	3c0b800a */ 	lui	$t3,0x800a
/*  f0fa204:	8d420010 */ 	lw	$v0,0x10($t2)
/*  f0fa208:	304c0800 */ 	andi	$t4,$v0,0x800
/*  f0fa20c:	11800013 */ 	beqz	$t4,.L0f0fa25c
/*  f0fa210:	304e0020 */ 	andi	$t6,$v0,0x20
/*  f0fa214:	8d6ba458 */ 	lw	$t3,-0x5ba8($t3)
/*  f0fa218:	3c0d8009 */ 	lui	$t5,0x8009
/*  f0fa21c:	1160000f */ 	beqz	$t3,.L0f0fa25c
/*  f0fa220:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa224:	91ad0af0 */ 	lbu	$t5,0xaf0($t5)
/*  f0fa228:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fa22c:	3c048008 */ 	lui	$a0,%hi(menudialog_2aba0)
/*  f0fa230:	15a10006 */ 	bne	$t5,$at,.L0f0fa24c
/*  f0fa234:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa238:	3c048007 */ 	lui	$a0,%hi(menudialog_mpdropout)
/*  f0fa23c:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0fa240:	248452fc */ 	addiu	$a0,$a0,%lo(menudialog_mpdropout)
/*  f0fa244:	1000001f */ 	beqz	$zero,.L0f0fa2c4
/*  f0fa248:	8fd00008 */ 	lw	$s0,0x8($s8)
.L0f0fa24c:
/*  f0fa24c:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0fa250:	24844b80 */ 	addiu	$a0,$a0,%lo(menudialog_2aba0)
/*  f0fa254:	1000001b */ 	beqz	$zero,.L0f0fa2c4
/*  f0fa258:	8fd00008 */ 	lw	$s0,0x8($s8)
.L0f0fa25c:
/*  f0fa25c:	55c00019 */ 	bnezl	$t6,.L0f0fa2c4
/*  f0fa260:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa264:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0fa268:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa26c:	10000015 */ 	beqz	$zero,.L0f0fa2c4
/*  f0fa270:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa274:	8fcf0000 */ 	lw	$t7,0x0($s8)
.L0f0fa278:
/*  f0fa278:	8df80010 */ 	lw	$t8,0x10($t7)
/*  f0fa27c:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0fa280:	53200010 */ 	beqzl	$t9,.L0f0fa2c4
/*  f0fa284:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa288:	93c80060 */ 	lbu	$t0,0x60($s8)
/*  f0fa28c:	8fa90124 */ 	lw	$t1,0x124($sp)
/*  f0fa290:	5900000c */ 	blezl	$t0,.L0f0fa2c4
/*  f0fa294:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa298:	912a0002 */ 	lbu	$t2,0x2($t1)
/*  f0fa29c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fa2a0:	304b0001 */ 	andi	$t3,$v0,0x1
/*  f0fa2a4:	314c0001 */ 	andi	$t4,$t2,0x1
/*  f0fa2a8:	11810003 */ 	beq	$t4,$at,.L0f0fa2b8
/*  f0fa2ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fa2b0:	55610004 */ 	bnel	$t3,$at,.L0f0fa2c4
/*  f0fa2b4:	8fd00008 */ 	lw	$s0,0x8($s8)
.L0f0fa2b8:
/*  f0fa2b8:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0fa2bc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fa2c0:
/*  f0fa2c0:	8fd00008 */ 	lw	$s0,0x8($s8)
.L0f0fa2c4:
/*  f0fa2c4:	8fcd0000 */ 	lw	$t5,0x0($s8)
/*  f0fa2c8:	1200002b */ 	beqz	$s0,.L0f0fa378
/*  f0fa2cc:	8da20010 */ 	lw	$v0,0x10($t5)
/*  f0fa2d0:	304e0008 */ 	andi	$t6,$v0,0x8
/*  f0fa2d4:	15c00028 */ 	bnez	$t6,.L0f0fa378
/*  f0fa2d8:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0fa2dc:	02002825 */ 	or	$a1,$s0,$zero
/*  f0fa2e0:	27a6007c */ 	addiu	$a2,$sp,0x7c
/*  f0fa2e4:	0fc3c8d5 */ 	jal	func0f0f2354
/*  f0fa2e8:	27a70078 */ 	addiu	$a3,$sp,0x78
/*  f0fa2ec:	8fcf0008 */ 	lw	$t7,0x8($s8)
/*  f0fa2f0:	8fa9007c */ 	lw	$t1,0x7c($sp)
/*  f0fa2f4:	8df80004 */ 	lw	$t8,0x4($t7)
/*  f0fa2f8:	0018cbc0 */ 	sll	$t9,$t8,0xf
/*  f0fa2fc:	0720001c */ 	bltz	$t9,.L0f0fa370
/*  f0fa300:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa304:	8fa80114 */ 	lw	$t0,0x114($sp)
/*  f0fa308:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0fa30c:	8fc40020 */ 	lw	$a0,0x20($s8)
/*  f0fa310:	010a6021 */ 	addu	$t4,$t0,$t2
/*  f0fa314:	858b04fc */ 	lh	$t3,0x4fc($t4)
/*  f0fa318:	248efff4 */ 	addiu	$t6,$a0,-12
/*  f0fa31c:	05610003 */ 	bgez	$t3,.L0f0fa32c
/*  f0fa320:	000b6843 */ 	sra	$t5,$t3,0x1
/*  f0fa324:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0fa328:	00016843 */ 	sra	$t5,$at,0x1
.L0f0fa32c:
/*  f0fa32c:	01a22821 */ 	addu	$a1,$t5,$v0
/*  f0fa330:	05c10003 */ 	bgez	$t6,.L0f0fa340
/*  f0fa334:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f0fa338:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f0fa33c:	00017843 */ 	sra	$t7,$at,0x1
.L0f0fa340:
/*  f0fa340:	01e51823 */ 	subu	$v1,$t7,$a1
/*  f0fa344:	58600003 */ 	blezl	$v1,.L0f0fa354
/*  f0fa348:	8fd80028 */ 	lw	$t8,0x28($s8)
/*  f0fa34c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fa350:	8fd80028 */ 	lw	$t8,0x28($s8)
.L0f0fa354:
/*  f0fa354:	00981023 */ 	subu	$v0,$a0,$t8
/*  f0fa358:	0062082a */ 	slt	$at,$v1,$v0
/*  f0fa35c:	10200002 */ 	beqz	$at,.L0f0fa368
/*  f0fa360:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa364:	00401825 */ 	or	$v1,$v0,$zero
.L0f0fa368:
/*  f0fa368:	10000025 */ 	beqz	$zero,.L0f0fa400
/*  f0fa36c:	afc30068 */ 	sw	$v1,0x68($s8)
.L0f0fa370:
/*  f0fa370:	10000023 */ 	beqz	$zero,.L0f0fa400
/*  f0fa374:	afc00068 */ 	sw	$zero,0x68($s8)
.L0f0fa378:
/*  f0fa378:	30590040 */ 	andi	$t9,$v0,0x40
/*  f0fa37c:	13200020 */ 	beqz	$t9,.L0f0fa400
/*  f0fa380:	8fa90124 */ 	lw	$t1,0x124($sp)
/*  f0fa384:	3c03800a */ 	lui	$v1,0x800a
/*  f0fa388:	8c639fc0 */ 	lw	$v1,-0x6040($v1)
/*  f0fa38c:	81280005 */ 	lb	$t0,0x5($t1)
/*  f0fa390:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0fa394:	812b0009 */ 	lb	$t3,0x9($t1)
/*  f0fa398:	01030019 */ 	multu	$t0,$v1
/*  f0fa39c:	8fce0068 */ 	lw	$t6,0x68($s8)
/*  f0fa3a0:	00005012 */ 	mflo	$t2
/*  f0fa3a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa3a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa3ac:	0141001a */ 	div	$zero,$t2,$at
/*  f0fa3b0:	00006012 */ 	mflo	$t4
/*  f0fa3b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa3b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa3bc:	01630019 */ 	multu	$t3,$v1
/*  f0fa3c0:	00006812 */ 	mflo	$t5
/*  f0fa3c4:	018d1023 */ 	subu	$v0,$t4,$t5
/*  f0fa3c8:	01c22821 */ 	addu	$a1,$t6,$v0
/*  f0fa3cc:	18a00003 */ 	blez	$a1,.L0f0fa3dc
/*  f0fa3d0:	afc50068 */ 	sw	$a1,0x68($s8)
/*  f0fa3d4:	afc00068 */ 	sw	$zero,0x68($s8)
/*  f0fa3d8:	00002825 */ 	or	$a1,$zero,$zero
.L0f0fa3dc:
/*  f0fa3dc:	8fd80020 */ 	lw	$t8,0x20($s8)
/*  f0fa3e0:	8fd90028 */ 	lw	$t9,0x28($s8)
/*  f0fa3e4:	03191023 */ 	subu	$v0,$t8,$t9
/*  f0fa3e8:	00a2082a */ 	slt	$at,$a1,$v0
/*  f0fa3ec:	50200004 */ 	beqzl	$at,.L0f0fa400
/*  f0fa3f0:	afc50064 */ 	sw	$a1,0x64($s8)
/*  f0fa3f4:	afc20068 */ 	sw	$v0,0x68($s8)
/*  f0fa3f8:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fa3fc:	afc50064 */ 	sw	$a1,0x64($s8)
.L0f0fa400:
/*  f0fa400:	8fc50068 */ 	lw	$a1,0x68($s8)
/*  f0fa404:	8fc40064 */ 	lw	$a0,0x64($s8)
/*  f0fa408:	3c03800a */ 	lui	$v1,0x800a
/*  f0fa40c:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0fa410:	10a40021 */ 	beq	$a1,$a0,.L0f0fa498
/*  f0fa414:	00803025 */ 	or	$a2,$a0,$zero
/*  f0fa418:	8c639fc0 */ 	lw	$v1,-0x6040($v1)
/*  f0fa41c:	44845000 */ 	mtc1	$a0,$f10
/*  f0fa420:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fa424:	1860000e */ 	blez	$v1,.L0f0fa460
/*  f0fa428:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f0fa42c:	44854000 */ 	mtc1	$a1,$f8
/*  f0fa430:	3c017f1b */ 	lui	$at,%hi(var7f1b2a60)
/*  f0fa434:	c4242a60 */ 	lwc1	$f4,%lo(var7f1b2a60)($at)
/*  f0fa438:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f0fa43c:	3c017f1b */ 	lui	$at,%hi(var7f1b2a64)
/*  f0fa440:	c42c2a64 */ 	lwc1	$f12,%lo(var7f1b2a64)($at)
/*  f0fa444:	46049082 */ 	mul.s	$f2,$f18,$f4
/*  f0fa448:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fa44c:
/*  f0fa44c:	46006182 */ 	mul.s	$f6,$f12,$f0
/*  f0fa450:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fa454:	0043082a */ 	slt	$at,$v0,$v1
/*  f0fa458:	1420fffc */ 	bnez	$at,.L0f0fa44c
/*  f0fa45c:	46061000 */ 	add.s	$f0,$f2,$f6
.L0f0fa460:
/*  f0fa460:	4600028d */ 	trunc.w.s	$f10,$f0
/*  f0fa464:	44025000 */ 	mfc1	$v0,$f10
/*  f0fa468:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa46c:	10a2000a */ 	beq	$a1,$v0,.L0f0fa498
/*  f0fa470:	afc20064 */ 	sw	$v0,0x64($s8)
/*  f0fa474:	14c20008 */ 	bne	$a2,$v0,.L0f0fa498
/*  f0fa478:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fa47c:	0045082a */ 	slt	$at,$v0,$a1
/*  f0fa480:	10200004 */ 	beqz	$at,.L0f0fa494
/*  f0fa484:	2489ffff */ 	addiu	$t1,$a0,-1
/*  f0fa488:	244a0001 */ 	addiu	$t2,$v0,0x1
/*  f0fa48c:	10000002 */ 	beqz	$zero,.L0f0fa498
/*  f0fa490:	afca0064 */ 	sw	$t2,0x64($s8)
.L0f0fa494:
/*  f0fa494:	afc90064 */ 	sw	$t1,0x64($s8)
.L0f0fa498:
/*  f0fa498:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f0fa49c:	3c0d800a */ 	lui	$t5,0x800a
/*  f0fa4a0:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0fa4a4:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f0fa4a8:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0fa4ac:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0fa4b0:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f0fa4b4:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0fa4b8:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0fa4bc:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f0fa4c0:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0fa4c4:	8dadee40 */ 	lw	$t5,-0x11c0($t5)
/*  f0fa4c8:	8fb80124 */ 	lw	$t8,0x124($sp)
/*  f0fa4cc:	3c088007 */ 	lui	$t0,0x8007
/*  f0fa4d0:	000d77c2 */ 	srl	$t6,$t5,0x1f
/*  f0fa4d4:	55c00005 */ 	bnezl	$t6,.L0f0fa4ec
/*  f0fa4d8:	a3000014 */ 	sb	$zero,0x14($t8)
/*  f0fa4dc:	8defdd58 */ 	lw	$t7,-0x22a8($t7)
/*  f0fa4e0:	51e00019 */ 	beqzl	$t7,.L0f0fa548
/*  f0fa4e4:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0fa4e8:	a3000014 */ 	sb	$zero,0x14($t8)
.L0f0fa4ec:
/*  f0fa4ec:	a3000007 */ 	sb	$zero,0x7($t8)
/*  f0fa4f0:	a3000006 */ 	sb	$zero,0x6($t8)
/*  f0fa4f4:	a3000005 */ 	sb	$zero,0x5($t8)
/*  f0fa4f8:	a3000004 */ 	sb	$zero,0x4($t8)
/*  f0fa4fc:	a3000003 */ 	sb	$zero,0x3($t8)
/*  f0fa500:	a3000002 */ 	sb	$zero,0x2($t8)
/*  f0fa504:	a3000001 */ 	sb	$zero,0x1($t8)
/*  f0fa508:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f0fa50c:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f0fa510:	3c09800a */ 	lui	$t1,%hi(var8009e000)
/*  f0fa514:	2529e000 */ 	addiu	$t1,$t1,%lo(var8009e000)
/*  f0fa518:	000850c0 */ 	sll	$t2,$t0,0x3
/*  f0fa51c:	01485023 */ 	subu	$t2,$t2,$t0
/*  f0fa520:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0fa524:	01485021 */ 	addu	$t2,$t2,$t0
/*  f0fa528:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0fa52c:	01485023 */ 	subu	$t2,$t2,$t0
/*  f0fa530:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0fa534:	01491021 */ 	addu	$v0,$t2,$t1
/*  f0fa538:	904b0e40 */ 	lbu	$t3,0xe40($v0)
/*  f0fa53c:	316cff7f */ 	andi	$t4,$t3,0xff7f
/*  f0fa540:	a04c0e40 */ 	sb	$t4,0xe40($v0)
/*  f0fa544:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f0fa548:
/*  f0fa548:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0fa54c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0fa550:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0fa554:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f0fa558:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f0fa55c:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f0fa560:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f0fa564:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f0fa568:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f0fa56c:	03e00008 */ 	jr	$ra
/*  f0fa570:	27bd0120 */ 	addiu	$sp,$sp,0x120
);

GLOBAL_ASM(
glabel func0f0fa574
/*  f0fa574:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0fa578:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0fa57c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0fa580:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0fa584:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f0fa588:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0fa58c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0fa590:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0fa594:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f0fa598:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0fa59c:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0fa5a0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0fa5a4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0fa5a8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0fa5ac:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0fa5b0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0fa5b4:	90830005 */ 	lbu	$v1,0x5($a0)
/*  f0fa5b8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0fa5bc:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0fa5c0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0fa5c4:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0fa5c8:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0fa5cc:	0080a825 */ 	or	$s5,$a0,$zero
/*  f0fa5d0:	01f89021 */ 	addu	$s2,$t7,$t8
/*  f0fa5d4:	1860002a */ 	blez	$v1,.L0f0fa680
/*  f0fa5d8:	0000b025 */ 	or	$s6,$zero,$zero
/*  f0fa5dc:	2417000a */ 	addiu	$s7,$zero,0xa
/*  f0fa5e0:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f0fa5e4:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f0fa5e8:	92b90004 */ 	lbu	$t9,0x4($s5)
.L0f0fa5ec:
/*  f0fa5ec:	00008025 */ 	or	$s0,$zero,$zero
/*  f0fa5f0:	03361021 */ 	addu	$v0,$t9,$s6
/*  f0fa5f4:	00570019 */ 	multu	$v0,$s7
/*  f0fa5f8:	00004012 */ 	mflo	$t0
/*  f0fa5fc:	02488821 */ 	addu	$s1,$s2,$t0
/*  f0fa600:	92290668 */ 	lbu	$t1,0x668($s1)
/*  f0fa604:	5920001b */ 	blezl	$t1,.L0f0fa674
/*  f0fa608:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f0fa60c:	962a0666 */ 	lhu	$t2,0x666($s1)
.L0f0fa610:
/*  f0fa610:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f0fa614:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fa618:	01501821 */ 	addu	$v1,$t2,$s0
/*  f0fa61c:	00035880 */ 	sll	$t3,$v1,0x2
/*  f0fa620:	024b1021 */ 	addu	$v0,$s2,$t3
/*  f0fa624:	904c04fe */ 	lbu	$t4,0x4fe($v0)
/*  f0fa628:	804404ff */ 	lb	$a0,0x4ff($v0)
/*  f0fa62c:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*  f0fa630:	01930019 */ 	multu	$t4,$s3
/*  f0fa634:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f0fa638:	00006812 */ 	mflo	$t5
/*  f0fa63c:	01af3021 */ 	addu	$a2,$t5,$t7
/*  f0fa640:	12840003 */ 	beq	$s4,$a0,.L0f0fa650
/*  f0fa644:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa648:	02582821 */ 	addu	$a1,$s2,$t8
/*  f0fa64c:	24a506dc */ 	addiu	$a1,$a1,0x6dc
.L0f0fa650:
/*  f0fa650:	0fc3c218 */ 	jal	func0f0f0860
/*  f0fa654:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0fa658:	92390668 */ 	lbu	$t9,0x668($s1)
/*  f0fa65c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0fa660:	0219082a */ 	slt	$at,$s0,$t9
/*  f0fa664:	5420ffea */ 	bnezl	$at,.L0f0fa610
/*  f0fa668:	962a0666 */ 	lhu	$t2,0x666($s1)
/*  f0fa66c:	92a30005 */ 	lbu	$v1,0x5($s5)
/*  f0fa670:	26d60001 */ 	addiu	$s6,$s6,0x1
.L0f0fa674:
/*  f0fa674:	02c3082a */ 	slt	$at,$s6,$v1
/*  f0fa678:	5420ffdc */ 	bnezl	$at,.L0f0fa5ec
/*  f0fa67c:	92b90004 */ 	lbu	$t9,0x4($s5)
.L0f0fa680:
/*  f0fa680:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0fa684:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0fa688:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0fa68c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0fa690:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0fa694:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0fa698:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0fa69c:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f0fa6a0:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f0fa6a4:	03e00008 */ 	jr	$ra
/*  f0fa6a8:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f0fa6ac
/*  f0fa6ac:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fa6b0:	8dce19c4 */ 	lw	$t6,0x19c4($t6)
/*  f0fa6b4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0fa6b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fa6bc:	25cffffe */ 	addiu	$t7,$t6,-2
/*  f0fa6c0:	2de1000c */ 	sltiu	$at,$t7,0xc
/*  f0fa6c4:	1020000b */ 	beqz	$at,.L0f0fa6f4
/*  f0fa6c8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0fa6cc:	3c017f1b */ 	lui	$at,%hi(var7f1b2a68)
/*  f0fa6d0:	002f0821 */ 	addu	$at,$at,$t7
/*  f0fa6d4:	8c2f2a68 */ 	lw	$t7,%lo(var7f1b2a68)($at)
/*  f0fa6d8:	01e00008 */ 	jr	$t7
/*  f0fa6dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa6e0:	0fc2ebce */ 	jal	func0f0baf38
/*  f0fa6e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fa6e8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0fa6ec:	3c018007 */ 	lui	$at,0x8007
/*  f0fa6f0:	ac380750 */ 	sw	$t8,0x750($at)
.L0f0fa6f4:
/*  f0fa6f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fa6f8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0fa6fc:	03e00008 */ 	jr	$ra
/*  f0fa700:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0fa704
/*  f0fa704:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0fa708:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0fa70c:	3c178007 */ 	lui	$s7,%hi(g_MpPlayerNum)
/*  f0fa710:	26f71448 */ 	addiu	$s7,$s7,%lo(g_MpPlayerNum)
/*  f0fa714:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0fa718:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0fa71c:	241e0e70 */ 	addiu	$s8,$zero,0xe70
/*  f0fa720:	01de0019 */ 	multu	$t6,$s8
/*  f0fa724:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0fa728:	3c16800a */ 	lui	$s6,%hi(var8009e000)
/*  f0fa72c:	26d6e000 */ 	addiu	$s6,$s6,%lo(var8009e000)
/*  f0fa730:	3c19800a */ 	lui	$t9,0x800a
/*  f0fa734:	8f3919c4 */ 	lw	$t9,0x19c4($t9)
/*  f0fa738:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0fa73c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fa740:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0fa744:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0fa748:	00007812 */ 	mflo	$t7
/*  f0fa74c:	02cf3821 */ 	addu	$a3,$s6,$t7
/*  f0fa750:	8cf804f8 */ 	lw	$t8,0x4f8($a3)
/*  f0fa754:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0fa758:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0fa75c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0fa760:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0fa764:	00006025 */ 	or	$t4,$zero,$zero
/*  f0fa768:	00004825 */ 	or	$t1,$zero,$zero
/*  f0fa76c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0fa770:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0fa774:	afa0011c */ 	sw	$zero,0x11c($sp)
/*  f0fa778:	afa700fc */ 	sw	$a3,0xfc($sp)
/*  f0fa77c:	17210005 */ 	bne	$t9,$at,.L0f0fa794
/*  f0fa780:	afb80100 */ 	sw	$t8,0x100($sp)
/*  f0fa784:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fa788:	8dcea24c */ 	lw	$t6,-0x5db4($t6)
/*  f0fa78c:	3c01800a */ 	lui	$at,0x800a
/*  f0fa790:	ac2e21b8 */ 	sw	$t6,0x21b8($at)
.L0f0fa794:
/*  f0fa794:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fa798:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fa79c:	0fc3c506 */ 	jal	func0f0f1418
/*  f0fa7a0:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fa7a4:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0fa7a8:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fa7ac:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fa7b0:	01fe0019 */ 	multu	$t7,$s8
/*  f0fa7b4:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0fa7b8:	a3a00106 */ 	sb	$zero,0x106($sp)
/*  f0fa7bc:	a3a00107 */ 	sb	$zero,0x107($sp)
/*  f0fa7c0:	a3a0010a */ 	sb	$zero,0x10a($sp)
/*  f0fa7c4:	a3a0010b */ 	sb	$zero,0x10b($sp)
/*  f0fa7c8:	00005025 */ 	or	$t2,$zero,$zero
/*  f0fa7cc:	00005825 */ 	or	$t3,$zero,$zero
/*  f0fa7d0:	3c0f800a */ 	lui	$t7,0x800a
/*  f0fa7d4:	0000c012 */ 	mflo	$t8
/*  f0fa7d8:	02d8c821 */ 	addu	$t9,$s6,$t8
/*  f0fa7dc:	8f2e04f8 */ 	lw	$t6,0x4f8($t9)
/*  f0fa7e0:	51c0031e */ 	beqzl	$t6,.L0f0fb45c
/*  f0fa7e4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fa7e8:	8def19c4 */ 	lw	$t7,0x19c4($t7)
/*  f0fa7ec:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0fa7f0:	afa000f8 */ 	sw	$zero,0xf8($sp)
/*  f0fa7f4:	15e1000b */ 	bne	$t7,$at,.L0f0fa824
/*  f0fa7f8:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f0fa7fc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0fa800:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0fa804:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f0fa808:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f0fa80c:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f0fa810:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f0fa814:	afb900e0 */ 	sw	$t9,0xe0($sp)
/*  f0fa818:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f0fa81c:	1000001b */ 	beqz	$zero,.L0f0fa88c
/*  f0fa820:	afaf00ec */ 	sw	$t7,0xec($sp)
.L0f0fa824:
/*  f0fa824:	27a400d7 */ 	addiu	$a0,$sp,0xd7
/*  f0fa828:	27a500d6 */ 	addiu	$a1,$sp,0xd6
/*  f0fa82c:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fa830:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fa834:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0fa838:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0fa83c:	0fc3dd2a */ 	jal	func0f0f74a8
/*  f0fa840:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fa844:	83a200d7 */ 	lb	$v0,0xd7($sp)
/*  f0fa848:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fa84c:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fa850:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0fa854:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0fa858:	04400004 */ 	bltz	$v0,.L0f0fa86c
/*  f0fa85c:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0fa860:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0fa864:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f0fa868:	afa300ec */ 	sw	$v1,0xec($sp)
.L0f0fa86c:
/*  f0fa86c:	83a200d6 */ 	lb	$v0,0xd6($sp)
/*  f0fa870:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0fa874:	04400005 */ 	bltz	$v0,.L0f0fa88c
/*  f0fa878:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0fa87c:	03b8c821 */ 	addu	$t9,$sp,$t8
/*  f0fa880:	af2200d8 */ 	sw	$v0,0xd8($t9)
/*  f0fa884:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fa888:	afa300ec */ 	sw	$v1,0xec($sp)
.L0f0fa88c:
/*  f0fa88c:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0fa890:	01de0019 */ 	multu	$t6,$s8
/*  f0fa894:	00007812 */ 	mflo	$t7
/*  f0fa898:	02cf3821 */ 	addu	$a3,$s6,$t7
/*  f0fa89c:	90e20e41 */ 	lbu	$v0,0xe41($a3)
/*  f0fa8a0:	1840001a */ 	blez	$v0,.L0f0fa90c
/*  f0fa8a4:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f0fa8a8:	331900ff */ 	andi	$t9,$t8,0xff
/*  f0fa8ac:	17200014 */ 	bnez	$t9,.L0f0fa900
/*  f0fa8b0:	a0f80e41 */ 	sb	$t8,0xe41($a3)
/*  f0fa8b4:	8cee0e48 */ 	lw	$t6,0xe48($a3)
/*  f0fa8b8:	8cef0e4c */ 	lw	$t7,0xe4c($a3)
/*  f0fa8bc:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0fa8c0:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0fa8c4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fa8c8:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fa8cc:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fa8d0:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0fa8d4:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0fa8d8:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fa8dc:	afae00cc */ 	sw	$t6,0xcc($sp)
/*  f0fa8e0:	0fc42539 */ 	jal	func0f1094e4
/*  f0fa8e4:	a7af00d0 */ 	sh	$t7,0xd0($sp)
/*  f0fa8e8:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fa8ec:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fa8f0:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0fa8f4:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0fa8f8:	10000004 */ 	beqz	$zero,.L0f0fa90c
/*  f0fa8fc:	8fac012c */ 	lw	$t4,0x12c($sp)
.L0f0fa900:
/*  f0fa900:	90f90e40 */ 	lbu	$t9,0xe40($a3)
/*  f0fa904:	372e0080 */ 	ori	$t6,$t9,0x80
/*  f0fa908:	a0ee0e40 */ 	sb	$t6,0xe40($a3)
.L0f0fa90c:
/*  f0fa90c:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f0fa910:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0fa914:	19e00083 */ 	blez	$t7,.L0f0fab24
/*  f0fa918:	27b300d8 */ 	addiu	$s3,$sp,0xd8
.L0f0fa91c:
/*  f0fa91c:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fa920:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fa924:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0fa928:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0fa92c:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fa930:	0c005384 */ 	jal	func00014e10
/*  f0fa934:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fa938:	00028600 */ 	sll	$s0,$v0,0x18
/*  f0fa93c:	0010c603 */ 	sra	$t8,$s0,0x18
/*  f0fa940:	03008025 */ 	or	$s0,$t8,$zero
/*  f0fa944:	0c0053ae */ 	jal	func00014eb8
/*  f0fa948:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fa94c:	00028e00 */ 	sll	$s1,$v0,0x18
/*  f0fa950:	0011ce03 */ 	sra	$t9,$s1,0x18
/*  f0fa954:	03208825 */ 	or	$s1,$t9,$zero
/*  f0fa958:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fa95c:	0c0053d8 */ 	jal	func00014f60
/*  f0fa960:	3405ffff */ 	dli	$a1,0xffff
/*  f0fa964:	3052ffff */ 	andi	$s2,$v0,0xffff
/*  f0fa968:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fa96c:	0c005408 */ 	jal	func00015020
/*  f0fa970:	3405ffff */ 	dli	$a1,0xffff
/*  f0fa974:	304e8000 */ 	andi	$t6,$v0,0x8000
/*  f0fa978:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fa97c:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fa980:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0fa984:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0fa988:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0fa98c:	11c00003 */ 	beqz	$t6,.L0f0fa99c
/*  f0fa990:	00403025 */ 	or	$a2,$v0,$zero
/*  f0fa994:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fa998:	a3af0106 */ 	sb	$t7,0x106($sp)
.L0f0fa99c:
/*  f0fa99c:	30d84000 */ 	andi	$t8,$a2,0x4000
/*  f0fa9a0:	13000003 */ 	beqz	$t8,.L0f0fa9b0
/*  f0fa9a4:	30ce2000 */ 	andi	$t6,$a2,0x2000
/*  f0fa9a8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fa9ac:	a3b90107 */ 	sb	$t9,0x107($sp)
.L0f0fa9b0:
/*  f0fa9b0:	11c00003 */ 	beqz	$t6,.L0f0fa9c0
/*  f0fa9b4:	30d81000 */ 	andi	$t8,$a2,0x1000
/*  f0fa9b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fa9bc:	a3af0106 */ 	sb	$t7,0x106($sp)
.L0f0fa9c0:
/*  f0fa9c0:	13000003 */ 	beqz	$t8,.L0f0fa9d0
/*  f0fa9c4:	324e0010 */ 	andi	$t6,$s2,0x10
/*  f0fa9c8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fa9cc:	afb900f8 */ 	sw	$t9,0xf8($sp)
.L0f0fa9d0:
/*  f0fa9d0:	11c00003 */ 	beqz	$t6,.L0f0fa9e0
/*  f0fa9d4:	02402825 */ 	or	$a1,$s2,$zero
/*  f0fa9d8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fa9dc:	a3af010a */ 	sb	$t7,0x10a($sp)
.L0f0fa9e0:
/*  f0fa9e0:	30b80020 */ 	andi	$t8,$a1,0x20
/*  f0fa9e4:	13000003 */ 	beqz	$t8,.L0f0fa9f4
/*  f0fa9e8:	30ae0008 */ 	andi	$t6,$a1,0x8
/*  f0fa9ec:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fa9f0:	a3b9010a */ 	sb	$t9,0x10a($sp)
.L0f0fa9f4:
/*  f0fa9f4:	05410003 */ 	bgez	$t2,.L0f0faa04
/*  f0fa9f8:	30cf0008 */ 	andi	$t7,$a2,0x8
/*  f0fa9fc:	10000002 */ 	beqz	$zero,.L0f0faa08
/*  f0faa00:	000a2023 */ 	negu	$a0,$t2
.L0f0faa04:
/*  f0faa04:	01402025 */ 	or	$a0,$t2,$zero
.L0f0faa08:
/*  f0faa08:	06010003 */ 	bgez	$s0,.L0f0faa18
/*  f0faa0c:	30b80004 */ 	andi	$t8,$a1,0x4
/*  f0faa10:	10000002 */ 	beqz	$zero,.L0f0faa1c
/*  f0faa14:	00101823 */ 	negu	$v1,$s0
.L0f0faa18:
/*  f0faa18:	02001825 */ 	or	$v1,$s0,$zero
.L0f0faa1c:
/*  f0faa1c:	0083082a */ 	slt	$at,$a0,$v1
/*  f0faa20:	10200002 */ 	beqz	$at,.L0f0faa2c
/*  f0faa24:	30d90004 */ 	andi	$t9,$a2,0x4
/*  f0faa28:	02005025 */ 	or	$t2,$s0,$zero
.L0f0faa2c:
/*  f0faa2c:	05610003 */ 	bgez	$t3,.L0f0faa3c
/*  f0faa30:	01602025 */ 	or	$a0,$t3,$zero
/*  f0faa34:	10000001 */ 	beqz	$zero,.L0f0faa3c
/*  f0faa38:	000b2023 */ 	negu	$a0,$t3
.L0f0faa3c:
/*  f0faa3c:	06210003 */ 	bgez	$s1,.L0f0faa4c
/*  f0faa40:	02201825 */ 	or	$v1,$s1,$zero
/*  f0faa44:	10000001 */ 	beqz	$zero,.L0f0faa4c
/*  f0faa48:	00111823 */ 	negu	$v1,$s1
.L0f0faa4c:
/*  f0faa4c:	0083082a */ 	slt	$at,$a0,$v1
/*  f0faa50:	10200002 */ 	beqz	$at,.L0f0faa5c
/*  f0faa54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0faa58:	02205825 */ 	or	$t3,$s1,$zero
.L0f0faa5c:
/*  f0faa5c:	11c00002 */ 	beqz	$t6,.L0f0faa68
/*  f0faa60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0faa64:	240cffff */ 	addiu	$t4,$zero,-1
.L0f0faa68:
/*  f0faa68:	11e00002 */ 	beqz	$t7,.L0f0faa74
/*  f0faa6c:	30ae0002 */ 	andi	$t6,$a1,0x2
/*  f0faa70:	2408ffff */ 	addiu	$t0,$zero,-1
.L0f0faa74:
/*  f0faa74:	13000002 */ 	beqz	$t8,.L0f0faa80
/*  f0faa78:	30cf0002 */ 	andi	$t7,$a2,0x2
/*  f0faa7c:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f0faa80:
/*  f0faa80:	13200002 */ 	beqz	$t9,.L0f0faa8c
/*  f0faa84:	30b80001 */ 	andi	$t8,$a1,0x1
/*  f0faa88:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0faa8c:
/*  f0faa8c:	11c00002 */ 	beqz	$t6,.L0f0faa98
/*  f0faa90:	30d90001 */ 	andi	$t9,$a2,0x1
/*  f0faa94:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f0faa98:
/*  f0faa98:	11e00002 */ 	beqz	$t7,.L0f0faaa4
/*  f0faa9c:	30ae0800 */ 	andi	$t6,$a1,0x800
/*  f0faaa0:	2415ffff */ 	addiu	$s5,$zero,-1
.L0f0faaa4:
/*  f0faaa4:	13000002 */ 	beqz	$t8,.L0f0faab0
/*  f0faaa8:	30cf0800 */ 	andi	$t7,$a2,0x800
/*  f0faaac:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0faab0:
/*  f0faab0:	13200002 */ 	beqz	$t9,.L0f0faabc
/*  f0faab4:	30b80400 */ 	andi	$t8,$a1,0x400
/*  f0faab8:	24150001 */ 	addiu	$s5,$zero,0x1
.L0f0faabc:
/*  f0faabc:	11c00002 */ 	beqz	$t6,.L0f0faac8
/*  f0faac0:	30d90400 */ 	andi	$t9,$a2,0x400
/*  f0faac4:	240cffff */ 	addiu	$t4,$zero,-1
.L0f0faac8:
/*  f0faac8:	11e00002 */ 	beqz	$t7,.L0f0faad4
/*  f0faacc:	30ae0200 */ 	andi	$t6,$a1,0x200
/*  f0faad0:	2408ffff */ 	addiu	$t0,$zero,-1
.L0f0faad4:
/*  f0faad4:	13000002 */ 	beqz	$t8,.L0f0faae0
/*  f0faad8:	30cf0200 */ 	andi	$t7,$a2,0x200
/*  f0faadc:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f0faae0:
/*  f0faae0:	13200002 */ 	beqz	$t9,.L0f0faaec
/*  f0faae4:	30b80100 */ 	andi	$t8,$a1,0x100
/*  f0faae8:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0faaec:
/*  f0faaec:	11c00002 */ 	beqz	$t6,.L0f0faaf8
/*  f0faaf0:	30d90100 */ 	andi	$t9,$a2,0x100
/*  f0faaf4:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f0faaf8:
/*  f0faaf8:	11e00002 */ 	beqz	$t7,.L0f0fab04
/*  f0faafc:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f0fab00:	2415ffff */ 	addiu	$s5,$zero,-1
.L0f0fab04:
/*  f0fab04:	13000002 */ 	beqz	$t8,.L0f0fab10
/*  f0fab08:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0fab0c:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0fab10:
/*  f0fab10:	13200002 */ 	beqz	$t9,.L0f0fab1c
/*  f0fab14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fab18:	24150001 */ 	addiu	$s5,$zero,0x1
.L0f0fab1c:
/*  f0fab1c:	168eff7f */ 	bne	$s4,$t6,.L0f0fa91c
/*  f0fab20:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f0fab24:
/*  f0fab24:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0fab28:	93ae0106 */ 	lbu	$t6,0x106($sp)
/*  f0fab2c:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f0fab30:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0fab34:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0fab38:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0fab3c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0fab40:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fab44:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0fab48:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0fab4c:	02d8c821 */ 	addu	$t9,$s6,$t8
/*  f0fab50:	11c00002 */ 	beqz	$t6,.L0f0fab5c
/*  f0fab54:	8f2404f8 */ 	lw	$a0,0x4f8($t9)
/*  f0fab58:	a3a00107 */ 	sb	$zero,0x107($sp)
.L0f0fab5c:
/*  f0fab5c:	11000002 */ 	beqz	$t0,.L0f0fab68
/*  f0fab60:	2406001e */ 	addiu	$a2,$zero,0x1e
/*  f0fab64:	01006025 */ 	or	$t4,$t0,$zero
.L0f0fab68:
/*  f0fab68:	12a00002 */ 	beqz	$s5,.L0f0fab74
/*  f0fab6c:	2413003c */ 	addiu	$s3,$zero,0x3c
/*  f0fab70:	02a04825 */ 	or	$t1,$s5,$zero
.L0f0fab74:
/*  f0fab74:	24110021 */ 	addiu	$s1,$zero,0x21
/*  f0fab78:	2414002c */ 	addiu	$s4,$zero,0x2c
/*  f0fab7c:	10800019 */ 	beqz	$a0,.L0f0fabe4
/*  f0fab80:	00009025 */ 	or	$s2,$zero,$zero
/*  f0fab84:	8c820008 */ 	lw	$v0,0x8($a0)
/*  f0fab88:	10400016 */ 	beqz	$v0,.L0f0fabe4
/*  f0fab8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fab90:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0fab94:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0fab98:	10610003 */ 	beq	$v1,$at,.L0f0faba8
/*  f0fab9c:	24010010 */ 	addiu	$at,$zero,0x10
/*  f0faba0:	54610009 */ 	bnel	$v1,$at,.L0f0fabc8
/*  f0faba4:	2401000d */ 	addiu	$at,$zero,0xd
.L0f0faba8:
/*  f0faba8:	8c8f000c */ 	lw	$t7,0xc($a0)
/*  f0fabac:	51e00006 */ 	beqzl	$t7,.L0f0fabc8
/*  f0fabb0:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0fabb4:	24100005 */ 	addiu	$s0,$zero,0x5
/*  f0fabb8:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f0fabbc:	2413001e */ 	addiu	$s3,$zero,0x1e
/*  f0fabc0:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f0fabc4:	2401000d */ 	addiu	$at,$zero,0xd
.L0f0fabc8:
/*  f0fabc8:	14610006 */ 	bne	$v1,$at,.L0f0fabe4
/*  f0fabcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fabd0:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0fabd4:	24100005 */ 	addiu	$s0,$zero,0x5
/*  f0fabd8:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f0fabdc:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f0fabe0:	2414000a */ 	addiu	$s4,$zero,0xa
.L0f0fabe4:
/*  f0fabe4:	15200004 */ 	bnez	$t1,.L0f0fabf8
/*  f0fabe8:	0000f825 */ 	or	$ra,$zero,$zero
/*  f0fabec:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fabf0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0fabf4:	a478082c */ 	sh	$t8,0x82c($v1)
.L0f0fabf8:
/*  f0fabf8:	12a00006 */ 	beqz	$s5,.L0f0fac14
/*  f0fabfc:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fac00:	a460082c */ 	sh	$zero,0x82c($v1)
/*  f0fac04:	ac600824 */ 	sw	$zero,0x824($v1)
/*  f0fac08:	a475082a */ 	sh	$s5,0x82a($v1)
/*  f0fac0c:	10000004 */ 	beqz	$zero,.L0f0fac20
/*  f0fac10:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f0fac14:
/*  f0fac14:	51200003 */ 	beqzl	$t1,.L0f0fac24
/*  f0fac18:	8c620824 */ 	lw	$v0,0x824($v1)
/*  f0fac1c:	8469082a */ 	lh	$t1,0x82a($v1)
.L0f0fac20:
/*  f0fac20:	8c620824 */ 	lw	$v0,0x824($v1)
.L0f0fac24:
/*  f0fac24:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fac28:	2841003d */ 	slti	$at,$v0,0x3d
/*  f0fac2c:	14200004 */ 	bnez	$at,.L0f0fac40
/*  f0fac30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fac34:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fac38:	a479082c */ 	sh	$t9,0x82c($v1)
/*  f0fac3c:	8c620824 */ 	lw	$v0,0x824($v1)
.L0f0fac40:
/*  f0fac40:	0050001a */ 	div	$zero,$v0,$s0
/*  f0fac44:	8dce9fc0 */ 	lw	$t6,-0x6040($t6)
/*  f0fac48:	00003812 */ 	mflo	$a3
/*  f0fac4c:	8478082c */ 	lh	$t8,0x82c($v1)
/*  f0fac50:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0fac54:	01f0001a */ 	div	$zero,$t7,$s0
/*  f0fac58:	16000002 */ 	bnez	$s0,.L0f0fac64
/*  f0fac5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fac60:	0007000d */ 	break	0x7
.L0f0fac64:
/*  f0fac64:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fac68:	16010004 */ 	bne	$s0,$at,.L0f0fac7c
/*  f0fac6c:	3c018000 */ 	lui	$at,0x8000
/*  f0fac70:	14410002 */ 	bne	$v0,$at,.L0f0fac7c
/*  f0fac74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fac78:	0006000d */ 	break	0x6
.L0f0fac7c:
/*  f0fac7c:	00006812 */ 	mflo	$t5
/*  f0fac80:	16000002 */ 	bnez	$s0,.L0f0fac8c
/*  f0fac84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fac88:	0007000d */ 	break	0x7
.L0f0fac8c:
/*  f0fac8c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fac90:	16010004 */ 	bne	$s0,$at,.L0f0faca4
/*  f0fac94:	3c018000 */ 	lui	$at,0x8000
/*  f0fac98:	15e10002 */ 	bne	$t7,$at,.L0f0faca4
/*  f0fac9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0faca0:	0006000d */ 	break	0x6
.L0f0faca4:
/*  f0faca4:	1700000b */ 	bnez	$t8,.L0f0facd4
/*  f0faca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0facac:	04e10003 */ 	bgez	$a3,.L0f0facbc
/*  f0facb0:	0007c843 */ 	sra	$t9,$a3,0x1
/*  f0facb4:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0facb8:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0facbc:
/*  f0facbc:	03203825 */ 	or	$a3,$t9,$zero
/*  f0facc0:	05a10003 */ 	bgez	$t5,.L0f0facd0
/*  f0facc4:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f0facc8:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f0faccc:	00017043 */ 	sra	$t6,$at,0x1
.L0f0facd0:
/*  f0facd0:	01c06825 */ 	or	$t5,$t6,$zero
.L0f0facd4:
/*  f0facd4:	05410003 */ 	bgez	$t2,.L0f0face4
/*  f0facd8:	a3a9010c */ 	sb	$t1,0x10c($sp)
/*  f0facdc:	10000002 */ 	beqz	$zero,.L0f0face8
/*  f0face0:	000a1023 */ 	negu	$v0,$t2
.L0f0face4:
/*  f0face4:	01401025 */ 	or	$v0,$t2,$zero
.L0f0face8:
/*  f0face8:	05610003 */ 	bgez	$t3,.L0f0facf8
/*  f0facec:	0046082a */ 	slt	$at,$v0,$a2
/*  f0facf0:	10000002 */ 	beqz	$zero,.L0f0facfc
/*  f0facf4:	000b1823 */ 	negu	$v1,$t3
.L0f0facf8:
/*  f0facf8:	01601825 */ 	or	$v1,$t3,$zero
.L0f0facfc:
/*  f0facfc:	14200065 */ 	bnez	$at,.L0f0fae94
/*  f0fad00:	0062082a */ 	slt	$at,$v1,$v0
/*  f0fad04:	14200003 */ 	bnez	$at,.L0f0fad14
/*  f0fad08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fad0c:	52400062 */ 	beqzl	$s2,.L0f0fae98
/*  f0fad10:	8fb800fc */ 	lw	$t8,0xfc($sp)
.L0f0fad14:
/*  f0fad14:	05410006 */ 	bgez	$t2,.L0f0fad30
/*  f0fad18:	28410047 */ 	slti	$at,$v0,0x47
/*  f0fad1c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fad20:	846f0828 */ 	lh	$t7,0x828($v1)
/*  f0fad24:	59e00003 */ 	blezl	$t7,.L0f0fad34
/*  f0fad28:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fad2c:	a4600828 */ 	sh	$zero,0x828($v1)
.L0f0fad30:
/*  f0fad30:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0fad34:
/*  f0fad34:	19400005 */ 	blez	$t2,.L0f0fad4c
/*  f0fad38:	84640828 */ 	lh	$a0,0x828($v1)
/*  f0fad3c:	04810003 */ 	bgez	$a0,.L0f0fad4c
/*  f0fad40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fad44:	a4600828 */ 	sh	$zero,0x828($v1)
/*  f0fad48:	84640828 */ 	lh	$a0,0x828($v1)
.L0f0fad4c:
/*  f0fad4c:	14800003 */ 	bnez	$a0,.L0f0fad5c
/*  f0fad50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fad54:	ac600824 */ 	sw	$zero,0x824($v1)
/*  f0fad58:	84640828 */ 	lh	$a0,0x828($v1)
.L0f0fad5c:
/*  f0fad5c:	54200003 */ 	bnezl	$at,.L0f0fad6c
/*  f0fad60:	00461023 */ 	subu	$v0,$v0,$a2
/*  f0fad64:	24020046 */ 	addiu	$v0,$zero,0x46
/*  f0fad68:	00461023 */ 	subu	$v0,$v0,$a2
.L0f0fad6c:
/*  f0fad6c:	02220019 */ 	multu	$s1,$v0
/*  f0fad70:	24190046 */ 	addiu	$t9,$zero,0x46
/*  f0fad74:	03267023 */ 	subu	$t6,$t9,$a2
/*  f0fad78:	0000c012 */ 	mflo	$t8
/*  f0fad7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fad80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fad84:	030e001a */ 	div	$zero,$t8,$t6
/*  f0fad88:	15c00002 */ 	bnez	$t6,.L0f0fad94
/*  f0fad8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fad90:	0007000d */ 	break	0x7
.L0f0fad94:
/*  f0fad94:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fad98:	15c10004 */ 	bne	$t6,$at,.L0f0fadac
/*  f0fad9c:	3c018000 */ 	lui	$at,0x8000
/*  f0fada0:	17010002 */ 	bne	$t8,$at,.L0f0fadac
/*  f0fada4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fada8:	0006000d */ 	break	0x6
.L0f0fadac:
/*  f0fadac:	00007812 */ 	mflo	$t7
/*  f0fadb0:	026f2823 */ 	subu	$a1,$s3,$t7
/*  f0fadb4:	28810003 */ 	slti	$at,$a0,0x3
/*  f0fadb8:	10200004 */ 	beqz	$at,.L0f0fadcc
/*  f0fadbc:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0fadc0:	2881fffe */ 	slti	$at,$a0,-2
/*  f0fadc4:	10200005 */ 	beqz	$at,.L0f0faddc
/*  f0fadc8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fadcc:
/*  f0fadcc:	04a10003 */ 	bgez	$a1,.L0f0faddc
/*  f0fadd0:	00051843 */ 	sra	$v1,$a1,0x1
/*  f0fadd4:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f0fadd8:	00011843 */ 	sra	$v1,$at,0x1
.L0f0faddc:
/*  f0faddc:	1860002f */ 	blez	$v1,.L0f0fae9c
/*  f0fade0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fade4:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f0fade8:	3c18800a */ 	lui	$t8,0x800a
/*  f0fadec:	8f189fc0 */ 	lw	$t8,-0x6040($t8)
/*  f0fadf0:	8f220824 */ 	lw	$v0,0x824($t9)
/*  f0fadf4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0fadf8:	0043001a */ 	div	$zero,$v0,$v1
/*  f0fadfc:	00587021 */ 	addu	$t6,$v0,$t8
/*  f0fae00:	00003812 */ 	mflo	$a3
/*  f0fae04:	14600002 */ 	bnez	$v1,.L0f0fae10
/*  f0fae08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fae0c:	0007000d */ 	break	0x7
.L0f0fae10:
/*  f0fae10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fae14:	14610004 */ 	bne	$v1,$at,.L0f0fae28
/*  f0fae18:	3c018000 */ 	lui	$at,0x8000
/*  f0fae1c:	14410002 */ 	bne	$v0,$at,.L0f0fae28
/*  f0fae20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fae24:	0006000d */ 	break	0x6
.L0f0fae28:
/*  f0fae28:	01c3001a */ 	div	$zero,$t6,$v1
/*  f0fae2c:	00006812 */ 	mflo	$t5
/*  f0fae30:	14600002 */ 	bnez	$v1,.L0f0fae3c
/*  f0fae34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fae38:	0007000d */ 	break	0x7
.L0f0fae3c:
/*  f0fae3c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fae40:	14610004 */ 	bne	$v1,$at,.L0f0fae54
/*  f0fae44:	3c018000 */ 	lui	$at,0x8000
/*  f0fae48:	15c10002 */ 	bne	$t6,$at,.L0f0fae54
/*  f0fae4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fae50:	0006000d */ 	break	0x6
.L0f0fae54:
/*  f0fae54:	05410003 */ 	bgez	$t2,.L0f0fae64
/*  f0fae58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fae5c:	10000001 */ 	beqz	$zero,.L0f0fae64
/*  f0fae60:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f0fae64:
/*  f0fae64:	10ed0002 */ 	beq	$a3,$t5,.L0f0fae70
/*  f0fae68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fae6c:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f0fae70:
/*  f0fae70:	14800002 */ 	bnez	$a0,.L0f0fae7c
/*  f0fae74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fae78:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f0fae7c:
/*  f0fae7c:	13e00007 */ 	beqz	$ra,.L0f0fae9c
/*  f0fae80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fae84:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f0fae88:	00897821 */ 	addu	$t7,$a0,$t1
/*  f0fae8c:	10000003 */ 	beqz	$zero,.L0f0fae9c
/*  f0fae90:	a72f0828 */ 	sh	$t7,0x828($t9)
.L0f0fae94:
/*  f0fae94:	8fb800fc */ 	lw	$t8,0xfc($sp)
.L0f0fae98:
/*  f0fae98:	a7000828 */ 	sh	$zero,0x828($t8)
.L0f0fae9c:
/*  f0fae9c:	10ed0002 */ 	beq	$a3,$t5,.L0f0faea8
/*  f0faea0:	3c19800a */ 	lui	$t9,0x800a
/*  f0faea4:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f0faea8:
/*  f0faea8:	17e00002 */ 	bnez	$ra,.L0f0faeb4
/*  f0faeac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0faeb0:	00004825 */ 	or	$t1,$zero,$zero
.L0f0faeb4:
/*  f0faeb4:	11000007 */ 	beqz	$t0,.L0f0faed4
/*  f0faeb8:	00006825 */ 	or	$t5,$zero,$zero
/*  f0faebc:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0faec0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0faec4:	a4600838 */ 	sh	$zero,0x838($v1)
/*  f0faec8:	ac600830 */ 	sw	$zero,0x830($v1)
/*  f0faecc:	10000005 */ 	beqz	$zero,.L0f0faee4
/*  f0faed0:	a4680836 */ 	sh	$t0,0x836($v1)
.L0f0faed4:
/*  f0faed4:	51800004 */ 	beqzl	$t4,.L0f0faee8
/*  f0faed8:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0faedc:	8fae00fc */ 	lw	$t6,0xfc($sp)
/*  f0faee0:	85cc0836 */ 	lh	$t4,0x836($t6)
.L0f0faee4:
/*  f0faee4:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0faee8:
/*  f0faee8:	8c620830 */ 	lw	$v0,0x830($v1)
/*  f0faeec:	2841003d */ 	slti	$at,$v0,0x3d
/*  f0faef0:	14200004 */ 	bnez	$at,.L0f0faf04
/*  f0faef4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0faef8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0faefc:	a46f0838 */ 	sh	$t7,0x838($v1)
/*  f0faf00:	8c620830 */ 	lw	$v0,0x830($v1)
.L0f0faf04:
/*  f0faf04:	0050001a */ 	div	$zero,$v0,$s0
/*  f0faf08:	8f399fc0 */ 	lw	$t9,-0x6040($t9)
/*  f0faf0c:	00003812 */ 	mflo	$a3
/*  f0faf10:	846e0838 */ 	lh	$t6,0x838($v1)
/*  f0faf14:	0059c021 */ 	addu	$t8,$v0,$t9
/*  f0faf18:	0310001a */ 	div	$zero,$t8,$s0
/*  f0faf1c:	16000002 */ 	bnez	$s0,.L0f0faf28
/*  f0faf20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0faf24:	0007000d */ 	break	0x7
.L0f0faf28:
/*  f0faf28:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0faf2c:	16010004 */ 	bne	$s0,$at,.L0f0faf40
/*  f0faf30:	3c018000 */ 	lui	$at,0x8000
/*  f0faf34:	14410002 */ 	bne	$v0,$at,.L0f0faf40
/*  f0faf38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0faf3c:	0006000d */ 	break	0x6
.L0f0faf40:
/*  f0faf40:	00004012 */ 	mflo	$t0
/*  f0faf44:	01601025 */ 	or	$v0,$t3,$zero
/*  f0faf48:	16000002 */ 	bnez	$s0,.L0f0faf54
/*  f0faf4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0faf50:	0007000d */ 	break	0x7
.L0f0faf54:
/*  f0faf54:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0faf58:	16010004 */ 	bne	$s0,$at,.L0f0faf6c
/*  f0faf5c:	3c018000 */ 	lui	$at,0x8000
/*  f0faf60:	17010002 */ 	bne	$t8,$at,.L0f0faf6c
/*  f0faf64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0faf68:	0006000d */ 	break	0x6
.L0f0faf6c:
/*  f0faf6c:	15c0000b */ 	bnez	$t6,.L0f0faf9c
/*  f0faf70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0faf74:	04e10003 */ 	bgez	$a3,.L0f0faf84
/*  f0faf78:	00077843 */ 	sra	$t7,$a3,0x1
/*  f0faf7c:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0faf80:	00017843 */ 	sra	$t7,$at,0x1
.L0f0faf84:
/*  f0faf84:	01e03825 */ 	or	$a3,$t7,$zero
/*  f0faf88:	05010003 */ 	bgez	$t0,.L0f0faf98
/*  f0faf8c:	0008c843 */ 	sra	$t9,$t0,0x1
/*  f0faf90:	25010001 */ 	addiu	$at,$t0,0x1
/*  f0faf94:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0faf98:
/*  f0faf98:	03204025 */ 	or	$t0,$t9,$zero
.L0f0faf9c:
/*  f0faf9c:	05610003 */ 	bgez	$t3,.L0f0fafac
/*  f0fafa0:	a3ac010d */ 	sb	$t4,0x10d($sp)
/*  f0fafa4:	10000001 */ 	beqz	$zero,.L0f0fafac
/*  f0fafa8:	000b1023 */ 	negu	$v0,$t3
.L0f0fafac:
/*  f0fafac:	05410003 */ 	bgez	$t2,.L0f0fafbc
/*  f0fafb0:	28410014 */ 	slti	$at,$v0,0x14
/*  f0fafb4:	10000002 */ 	beqz	$zero,.L0f0fafc0
/*  f0fafb8:	000a1823 */ 	negu	$v1,$t2
.L0f0fafbc:
/*  f0fafbc:	01401825 */ 	or	$v1,$t2,$zero
.L0f0fafc0:
/*  f0fafc0:	1420005d */ 	bnez	$at,.L0f0fb138
/*  f0fafc4:	0062082a */ 	slt	$at,$v1,$v0
/*  f0fafc8:	14200003 */ 	bnez	$at,.L0f0fafd8
/*  f0fafcc:	3c06800a */ 	lui	$a2,0x800a
/*  f0fafd0:	5240005a */ 	beqzl	$s2,.L0f0fb13c
/*  f0fafd4:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0fafd8:
/*  f0fafd8:	05610006 */ 	bgez	$t3,.L0f0faff4
/*  f0fafdc:	28410047 */ 	slti	$at,$v0,0x47
/*  f0fafe0:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fafe4:	84780834 */ 	lh	$t8,0x834($v1)
/*  f0fafe8:	07030003 */ 	bgezl	$t8,.L0f0faff8
/*  f0fafec:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0faff0:	a4600834 */ 	sh	$zero,0x834($v1)
.L0f0faff4:
/*  f0faff4:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0faff8:
/*  f0faff8:	19600005 */ 	blez	$t3,.L0f0fb010
/*  f0faffc:	84640834 */ 	lh	$a0,0x834($v1)
/*  f0fb000:	18800003 */ 	blez	$a0,.L0f0fb010
/*  f0fb004:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb008:	a4600834 */ 	sh	$zero,0x834($v1)
/*  f0fb00c:	84640834 */ 	lh	$a0,0x834($v1)
.L0f0fb010:
/*  f0fb010:	14800003 */ 	bnez	$a0,.L0f0fb020
/*  f0fb014:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb018:	ac600830 */ 	sw	$zero,0x830($v1)
/*  f0fb01c:	84640834 */ 	lh	$a0,0x834($v1)
.L0f0fb020:
/*  f0fb020:	14200002 */ 	bnez	$at,.L0f0fb02c
/*  f0fb024:	8cc69fc0 */ 	lw	$a2,-0x6040($a2)
/*  f0fb028:	24020046 */ 	addiu	$v0,$zero,0x46
.L0f0fb02c:
/*  f0fb02c:	2442ffec */ 	addiu	$v0,$v0,-20
/*  f0fb030:	02820019 */ 	multu	$s4,$v0
/*  f0fb034:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0fb038:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f0fb03c:	00007012 */ 	mflo	$t6
/*  f0fb040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb048:	01c1001a */ 	div	$zero,$t6,$at
/*  f0fb04c:	00007812 */ 	mflo	$t7
/*  f0fb050:	026f2823 */ 	subu	$a1,$s3,$t7
/*  f0fb054:	28810003 */ 	slti	$at,$a0,0x3
/*  f0fb058:	10200004 */ 	beqz	$at,.L0f0fb06c
/*  f0fb05c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0fb060:	2881fffe */ 	slti	$at,$a0,-2
/*  f0fb064:	10200006 */ 	beqz	$at,.L0f0fb080
/*  f0fb068:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fb06c:
/*  f0fb06c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fb070:	00a1001a */ 	div	$zero,$a1,$at
/*  f0fb074:	00001812 */ 	mflo	$v1
/*  f0fb078:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb07c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fb080:
/*  f0fb080:	5860002b */ 	blezl	$v1,.L0f0fb130
/*  f0fb084:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb088:	8f220830 */ 	lw	$v0,0x830($t9)
/*  f0fb08c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0fb090:	0043001a */ 	div	$zero,$v0,$v1
/*  f0fb094:	0046c021 */ 	addu	$t8,$v0,$a2
/*  f0fb098:	00003812 */ 	mflo	$a3
/*  f0fb09c:	14600002 */ 	bnez	$v1,.L0f0fb0a8
/*  f0fb0a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb0a4:	0007000d */ 	break	0x7
.L0f0fb0a8:
/*  f0fb0a8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fb0ac:	14610004 */ 	bne	$v1,$at,.L0f0fb0c0
/*  f0fb0b0:	3c018000 */ 	lui	$at,0x8000
/*  f0fb0b4:	14410002 */ 	bne	$v0,$at,.L0f0fb0c0
/*  f0fb0b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb0bc:	0006000d */ 	break	0x6
.L0f0fb0c0:
/*  f0fb0c0:	0303001a */ 	div	$zero,$t8,$v1
/*  f0fb0c4:	00004012 */ 	mflo	$t0
/*  f0fb0c8:	14600002 */ 	bnez	$v1,.L0f0fb0d4
/*  f0fb0cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb0d0:	0007000d */ 	break	0x7
.L0f0fb0d4:
/*  f0fb0d4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fb0d8:	14610004 */ 	bne	$v1,$at,.L0f0fb0ec
/*  f0fb0dc:	3c018000 */ 	lui	$at,0x8000
/*  f0fb0e0:	17010002 */ 	bne	$t8,$at,.L0f0fb0ec
/*  f0fb0e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb0e8:	0006000d */ 	break	0x6
.L0f0fb0ec:
/*  f0fb0ec:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb0f0:	19600003 */ 	blez	$t3,.L0f0fb100
/*  f0fb0f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb0f8:	10000001 */ 	beqz	$zero,.L0f0fb100
/*  f0fb0fc:	240cffff */ 	addiu	$t4,$zero,-1
.L0f0fb100:
/*  f0fb100:	10e80002 */ 	beq	$a3,$t0,.L0f0fb10c
/*  f0fb104:	008c7021 */ 	addu	$t6,$a0,$t4
/*  f0fb108:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f0fb10c:
/*  f0fb10c:	14800002 */ 	bnez	$a0,.L0f0fb118
/*  f0fb110:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb114:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f0fb118:
/*  f0fb118:	51a00005 */ 	beqzl	$t5,.L0f0fb130
/*  f0fb11c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb120:	a46e0834 */ 	sh	$t6,0x834($v1)
/*  f0fb124:	3c06800a */ 	lui	$a2,0x800a
/*  f0fb128:	8cc69fc0 */ 	lw	$a2,-0x6040($a2)
/*  f0fb12c:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0fb130:
/*  f0fb130:	10000006 */ 	beqz	$zero,.L0f0fb14c
/*  f0fb134:	8c620830 */ 	lw	$v0,0x830($v1)
.L0f0fb138:
/*  f0fb138:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0fb13c:
/*  f0fb13c:	3c06800a */ 	lui	$a2,0x800a
/*  f0fb140:	a4600834 */ 	sh	$zero,0x834($v1)
/*  f0fb144:	8cc69fc0 */ 	lw	$a2,-0x6040($a2)
/*  f0fb148:	8c620830 */ 	lw	$v0,0x830($v1)
.L0f0fb14c:
/*  f0fb14c:	10e80002 */ 	beq	$a3,$t0,.L0f0fb158
/*  f0fb150:	27b50104 */ 	addiu	$s5,$sp,0x104
/*  f0fb154:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f0fb158:
/*  f0fb158:	55a00003 */ 	bnezl	$t5,.L0f0fb168
/*  f0fb15c:	8c6f0824 */ 	lw	$t7,0x824($v1)
/*  f0fb160:	00006025 */ 	or	$t4,$zero,$zero
/*  f0fb164:	8c6f0824 */ 	lw	$t7,0x824($v1)
.L0f0fb168:
/*  f0fb168:	8fa500f8 */ 	lw	$a1,0xf8($sp)
/*  f0fb16c:	3c18800a */ 	lui	$t8,0x800a
/*  f0fb170:	01e6c821 */ 	addu	$t9,$t7,$a2
/*  f0fb174:	ac790824 */ 	sw	$t9,0x824($v1)
/*  f0fb178:	8f189fc0 */ 	lw	$t8,-0x6040($t8)
/*  f0fb17c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fb180:	00587021 */ 	addu	$t6,$v0,$t8
/*  f0fb184:	ac6e0830 */ 	sw	$t6,0x830($v1)
/*  f0fb188:	a3a90104 */ 	sb	$t1,0x104($sp)
/*  f0fb18c:	a3ac0105 */ 	sb	$t4,0x105($sp)
/*  f0fb190:	a3aa0108 */ 	sb	$t2,0x108($sp)
/*  f0fb194:	a3ab0109 */ 	sb	$t3,0x109($sp)
/*  f0fb198:	10a00003 */ 	beqz	$a1,.L0f0fb1a8
/*  f0fb19c:	a3a00118 */ 	sb	$zero,0x118($sp)
/*  f0fb1a0:	10000002 */ 	beqz	$zero,.L0f0fb1ac
/*  f0fb1a4:	a3af010e */ 	sb	$t7,0x10e($sp)
.L0f0fb1a8:
/*  f0fb1a8:	a3a0010e */ 	sb	$zero,0x10e($sp)
.L0f0fb1ac:
/*  f0fb1ac:	8ee30000 */ 	lw	$v1,0x0($s7)
/*  f0fb1b0:	007e0019 */ 	multu	$v1,$s8
/*  f0fb1b4:	0000c812 */ 	mflo	$t9
/*  f0fb1b8:	02d93821 */ 	addu	$a3,$s6,$t9
/*  f0fb1bc:	8ce404f8 */ 	lw	$a0,0x4f8($a3)
/*  f0fb1c0:	50800016 */ 	beqzl	$a0,.L0f0fb21c
/*  f0fb1c4:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb1c8:	50a00014 */ 	beqzl	$a1,.L0f0fb21c
/*  f0fb1cc:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb1d0:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f0fb1d4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fb1d8:	8f0e0010 */ 	lw	$t6,0x10($t8)
/*  f0fb1dc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0fb1e0:	31cf0004 */ 	andi	$t7,$t6,0x4
/*  f0fb1e4:	51e00004 */ 	beqzl	$t7,.L0f0fb1f8
/*  f0fb1e8:	8c820008 */ 	lw	$v0,0x8($a0)
/*  f0fb1ec:	a3b90106 */ 	sb	$t9,0x106($sp)
/*  f0fb1f0:	afb8011c */ 	sw	$t8,0x11c($sp)
/*  f0fb1f4:	8c820008 */ 	lw	$v0,0x8($a0)
.L0f0fb1f8:
/*  f0fb1f8:	50400008 */ 	beqzl	$v0,.L0f0fb21c
/*  f0fb1fc:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb200:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f0fb204:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fb208:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fb20c:	55c10003 */ 	bnel	$t6,$at,.L0f0fb21c
/*  f0fb210:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb214:	a3af0106 */ 	sb	$t7,0x106($sp)
/*  f0fb218:	84e204f4 */ 	lh	$v0,0x4f4($a3)
.L0f0fb21c:
/*  f0fb21c:	00009825 */ 	or	$s3,$zero,$zero
/*  f0fb220:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0fb224:	1840003a */ 	blez	$v0,.L0f0fb310
/*  f0fb228:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb22c:	afa00044 */ 	sw	$zero,0x44($sp)
.L0f0fb230:
/*  f0fb230:	0003c8c0 */ 	sll	$t9,$v1,0x3
/*  f0fb234:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb238:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fb23c:	0323c821 */ 	addu	$t9,$t9,$v1
/*  f0fb240:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fb244:	8fae0044 */ 	lw	$t6,0x44($sp)
/*  f0fb248:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb24c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fb250:	02d9c021 */ 	addu	$t8,$s6,$t9
/*  f0fb254:	030e9021 */ 	addu	$s2,$t8,$t6
/*  f0fb258:	824f0478 */ 	lb	$t7,0x478($s2)
/*  f0fb25c:	26520464 */ 	addiu	$s2,$s2,0x464
/*  f0fb260:	02408825 */ 	or	$s1,$s2,$zero
/*  f0fb264:	19e00024 */ 	blez	$t7,.L0f0fb2f8
/*  f0fb268:	00008025 */ 	or	$s0,$zero,$zero
/*  f0fb26c:	8ef80000 */ 	lw	$t8,0x0($s7)
.L0f0fb270:
/*  f0fb270:	26990001 */ 	addiu	$t9,$s4,0x1
/*  f0fb274:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fb278:	031e0019 */ 	multu	$t8,$s8
/*  f0fb27c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0fb280:	00007012 */ 	mflo	$t6
/*  f0fb284:	02ce7821 */ 	addu	$t7,$s6,$t6
/*  f0fb288:	85f804f4 */ 	lh	$t8,0x4f4($t7)
/*  f0fb28c:	17380008 */ 	bne	$t9,$t8,.L0f0fb2b0
/*  f0fb290:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb294:	824e0015 */ 	lb	$t6,0x15($s2)
/*  f0fb298:	160e0005 */ 	bne	$s0,$t6,.L0f0fb2b0
/*  f0fb29c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb2a0:	16600003 */ 	bnez	$s3,.L0f0fb2b0
/*  f0fb2a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb2a8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fb2ac:	24130001 */ 	addiu	$s3,$zero,0x1
.L0f0fb2b0:
/*  f0fb2b0:	0fc3e4d7 */ 	jal	func0f0f935c
/*  f0fb2b4:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f0fb2b8:	824f0014 */ 	lb	$t7,0x14($s2)
/*  f0fb2bc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0fb2c0:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0fb2c4:	020f082a */ 	slt	$at,$s0,$t7
/*  f0fb2c8:	5420ffe9 */ 	bnezl	$at,.L0f0fb270
/*  f0fb2cc:	8ef80000 */ 	lw	$t8,0x0($s7)
/*  f0fb2d0:	8ee30000 */ 	lw	$v1,0x0($s7)
/*  f0fb2d4:	0003c8c0 */ 	sll	$t9,$v1,0x3
/*  f0fb2d8:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb2dc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fb2e0:	0323c821 */ 	addu	$t9,$t9,$v1
/*  f0fb2e4:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fb2e8:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb2ec:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fb2f0:	02d93821 */ 	addu	$a3,$s6,$t9
/*  f0fb2f4:	84e204f4 */ 	lh	$v0,0x4f4($a3)
.L0f0fb2f8:
/*  f0fb2f8:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f0fb2fc:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0fb300:	0282082a */ 	slt	$at,$s4,$v0
/*  f0fb304:	270e0018 */ 	addiu	$t6,$t8,0x18
/*  f0fb308:	1420ffc9 */ 	bnez	$at,.L0f0fb230
/*  f0fb30c:	afae0044 */ 	sw	$t6,0x44($sp)
.L0f0fb310:
/*  f0fb310:	3c0f800a */ 	lui	$t7,0x800a
/*  f0fb314:	8def19c4 */ 	lw	$t7,0x19c4($t7)
/*  f0fb318:	25f9ffff */ 	addiu	$t9,$t7,-1
/*  f0fb31c:	2f21000d */ 	sltiu	$at,$t9,0xd
/*  f0fb320:	1020004d */ 	beqz	$at,.L0f0fb458
/*  f0fb324:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fb328:	3c017f1b */ 	lui	$at,%hi(var7f1b2a98)
/*  f0fb32c:	00390821 */ 	addu	$at,$at,$t9
/*  f0fb330:	8c392a98 */ 	lw	$t9,%lo(var7f1b2a98)($at)
/*  f0fb334:	03200008 */ 	jr	$t9
/*  f0fb338:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb33c:	83b8010e */ 	lb	$t8,0x10e($sp)
/*  f0fb340:	8fae011c */ 	lw	$t6,0x11c($sp)
/*  f0fb344:	53000045 */ 	beqzl	$t8,.L0f0fb45c
/*  f0fb348:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb34c:	55c00043 */ 	bnezl	$t6,.L0f0fb45c
/*  f0fb350:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb354:	8ce404f8 */ 	lw	$a0,0x4f8($a3)
/*  f0fb358:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0fb35c:	5080003f */ 	beqzl	$a0,.L0f0fb45c
/*  f0fb360:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb364:	8df9000c */ 	lw	$t9,0xc($t7)
/*  f0fb368:	3c18800a */ 	lui	$t8,0x800a
/*  f0fb36c:	5720003b */ 	bnezl	$t9,.L0f0fb45c
/*  f0fb370:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb374:	8f18a450 */ 	lw	$t8,-0x5bb0($t8)
/*  f0fb378:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0fb37c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fb380:	13010008 */ 	beq	$t8,$at,.L0f0fb3a4
/*  f0fb384:	3c048008 */ 	lui	$a0,%hi(g_MpReadyMenuDialog)
/*  f0fb388:	248457b8 */ 	addiu	$a0,$a0,%lo(g_MpReadyMenuDialog)
/*  f0fb38c:	10820005 */ 	beq	$a0,$v0,.L0f0fb3a4
/*  f0fb390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb394:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0fb398:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb39c:	1000002f */ 	beqz	$zero,.L0f0fb45c
/*  f0fb3a0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0fb3a4:
/*  f0fb3a4:	3c0e8008 */ 	lui	$t6,%hi(g_MpQuickTeamGameSetupMenuDialog)
/*  f0fb3a8:	25ce6680 */ 	addiu	$t6,$t6,%lo(g_MpQuickTeamGameSetupMenuDialog)
/*  f0fb3ac:	55c2002b */ 	bnel	$t6,$v0,.L0f0fb45c
/*  f0fb3b0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb3b4:	0fc5fd0a */ 	jal	func0f17f428
/*  f0fb3b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb3bc:	10000027 */ 	beqz	$zero,.L0f0fb45c
/*  f0fb3c0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb3c4:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0fb3c8:	8def0764 */ 	lw	$t7,0x764($t7)
/*  f0fb3cc:	51e00010 */ 	beqzl	$t7,.L0f0fb410
/*  f0fb3d0:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f0fb3d4:	0fc3e048 */ 	jal	func0f0f8120
/*  f0fb3d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb3dc:	3c198007 */ 	lui	$t9,0x8007
/*  f0fb3e0:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f0fb3e4:	3c0e800a */ 	lui	$t6,%hi(var8009e000)
/*  f0fb3e8:	25cee000 */ 	addiu	$t6,$t6,%lo(var8009e000)
/*  f0fb3ec:	0019c0c0 */ 	sll	$t8,$t9,0x3
/*  f0fb3f0:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f0fb3f4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0fb3f8:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f0fb3fc:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fb400:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f0fb404:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0fb408:	030e3821 */ 	addu	$a3,$t8,$t6
/*  f0fb40c:	240f000a */ 	addiu	$t7,$zero,0xa
.L0f0fb410:
/*  f0fb410:	a0ef083c */ 	sb	$t7,0x83c($a3)
/*  f0fb414:	83b9010e */ 	lb	$t9,0x10e($sp)
/*  f0fb418:	8fb8011c */ 	lw	$t8,0x11c($sp)
/*  f0fb41c:	5320000f */ 	beqzl	$t9,.L0f0fb45c
/*  f0fb420:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb424:	5700000d */ 	bnezl	$t8,.L0f0fb45c
/*  f0fb428:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb42c:	8cee04f8 */ 	lw	$t6,0x4f8($a3)
/*  f0fb430:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0fb434:	51c00009 */ 	beqzl	$t6,.L0f0fb45c
/*  f0fb438:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb43c:	8df90000 */ 	lw	$t9,0x0($t7)
/*  f0fb440:	8f380010 */ 	lw	$t8,0x10($t9)
/*  f0fb444:	330e0020 */ 	andi	$t6,$t8,0x20
/*  f0fb448:	55c00004 */ 	bnezl	$t6,.L0f0fb45c
/*  f0fb44c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb450:	0fc3e048 */ 	jal	func0f0f8120
/*  f0fb454:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fb458:
/*  f0fb458:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0fb45c:
/*  f0fb45c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0fb460:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0fb464:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0fb468:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0fb46c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0fb470:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0fb474:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0fb478:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0fb47c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0fb480:	03e00008 */ 	jr	$ra
/*  f0fb484:	27bd0130 */ 	addiu	$sp,$sp,0x130
);

GLOBAL_ASM(
glabel func0f0fb488
/*  f0fb488:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f0fb48c:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0fb490:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f0fb494:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0fb498:	44866000 */ 	mtc1	$a2,$f12
/*  f0fb49c:	2de10009 */ 	sltiu	$at,$t7,0x9
/*  f0fb4a0:	00808025 */ 	or	$s0,$a0,$zero
/*  f0fb4a4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0fb4a8:	102001b7 */ 	beqz	$at,.L0f0fbb88
/*  f0fb4ac:	afa50084 */ 	sw	$a1,0x84($sp)
/*  f0fb4b0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0fb4b4:	3c017f1b */ 	lui	$at,%hi(var7f1b2acc)
/*  f0fb4b8:	002f0821 */ 	addu	$at,$at,$t7
/*  f0fb4bc:	8c2f2acc */ 	lw	$t7,%lo(var7f1b2acc)($at)
/*  f0fb4c0:	01e00008 */ 	jr	$t7
/*  f0fb4c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb4c8:	3c01437f */ 	lui	$at,0x437f
/*  f0fb4cc:	44812000 */ 	mtc1	$at,$f4
/*  f0fb4d0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0fb4d4:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fb4d8:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0fb4dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fb4e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fb4e4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fb4e8:	4458f800 */ 	cfc1	$t8,$31
/*  f0fb4ec:	44c3f800 */ 	ctc1	$v1,$31
/*  f0fb4f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb4f4:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0fb4f8:	4443f800 */ 	cfc1	$v1,$31
/*  f0fb4fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb500:	30630078 */ 	andi	$v1,$v1,0x78
/*  f0fb504:	50600013 */ 	beqzl	$v1,.L0f0fb554
/*  f0fb508:	44034000 */ 	mfc1	$v1,$f8
/*  f0fb50c:	44814000 */ 	mtc1	$at,$f8
/*  f0fb510:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0fb514:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0fb518:	44c3f800 */ 	ctc1	$v1,$31
/*  f0fb51c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb520:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0fb524:	4443f800 */ 	cfc1	$v1,$31
/*  f0fb528:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb52c:	30630078 */ 	andi	$v1,$v1,0x78
/*  f0fb530:	14600005 */ 	bnez	$v1,.L0f0fb548
/*  f0fb534:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb538:	44034000 */ 	mfc1	$v1,$f8
/*  f0fb53c:	3c018000 */ 	lui	$at,0x8000
/*  f0fb540:	10000007 */ 	beqz	$zero,.L0f0fb560
/*  f0fb544:	00611825 */ 	or	$v1,$v1,$at
.L0f0fb548:
/*  f0fb548:	10000005 */ 	beqz	$zero,.L0f0fb560
/*  f0fb54c:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0fb550:	44034000 */ 	mfc1	$v1,$f8
.L0f0fb554:
/*  f0fb554:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb558:	0460fffb */ 	bltz	$v1,.L0f0fb548
/*  f0fb55c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fb560:
/*  f0fb560:	44d8f800 */ 	ctc1	$t8,$31
/*  f0fb564:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0fb568:	00612825 */ 	or	$a1,$v1,$at
/*  f0fb56c:	0fc38266 */ 	jal	func0f0e0998
/*  f0fb570:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0fb574:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0fb578:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0fb57c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fb580:	00038042 */ 	srl	$s0,$v1,0x1
/*  f0fb584:	02012825 */ 	or	$a1,$s0,$at
/*  f0fb588:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0fb58c:	2406ffe2 */ 	addiu	$a2,$zero,-30
/*  f0fb590:	0fc38266 */ 	jal	func0f0e0998
/*  f0fb594:	2407ffe2 */ 	addiu	$a3,$zero,-30
/*  f0fb598:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fb59c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0fb5a0:	2406001e */ 	addiu	$a2,$zero,0x1e
/*  f0fb5a4:	0fc38266 */ 	jal	func0f0e0998
/*  f0fb5a8:	2407001e */ 	addiu	$a3,$zero,0x1e
/*  f0fb5ac:	10000176 */ 	beqz	$zero,.L0f0fbb88
/*  f0fb5b0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fb5b4:	3c01437f */ 	lui	$at,0x437f
/*  f0fb5b8:	44815000 */ 	mtc1	$at,$f10
/*  f0fb5bc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fb5c0:	3c098006 */ 	lui	$t1,%hi(var800613a0)
/*  f0fb5c4:	460c5402 */ 	mul.s	$f16,$f10,$f12
/*  f0fb5c8:	252913a0 */ 	addiu	$t1,$t1,%lo(var800613a0)
/*  f0fb5cc:	3c080600 */ 	lui	$t0,0x600
/*  f0fb5d0:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f0fb5d4:	ae090004 */ 	sw	$t1,0x4($s0)
/*  f0fb5d8:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0fb5dc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fb5e0:	444af800 */ 	cfc1	$t2,$31
/*  f0fb5e4:	44c5f800 */ 	ctc1	$a1,$31
/*  f0fb5e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb5ec:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f0fb5f0:	4445f800 */ 	cfc1	$a1,$31
/*  f0fb5f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb5f8:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0fb5fc:	50a00013 */ 	beqzl	$a1,.L0f0fb64c
/*  f0fb600:	44059000 */ 	mfc1	$a1,$f18
/*  f0fb604:	44819000 */ 	mtc1	$at,$f18
/*  f0fb608:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fb60c:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f0fb610:	44c5f800 */ 	ctc1	$a1,$31
/*  f0fb614:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb618:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f0fb61c:	4445f800 */ 	cfc1	$a1,$31
/*  f0fb620:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb624:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0fb628:	14a00005 */ 	bnez	$a1,.L0f0fb640
/*  f0fb62c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb630:	44059000 */ 	mfc1	$a1,$f18
/*  f0fb634:	3c018000 */ 	lui	$at,0x8000
/*  f0fb638:	10000007 */ 	beqz	$zero,.L0f0fb658
/*  f0fb63c:	00a12825 */ 	or	$a1,$a1,$at
.L0f0fb640:
/*  f0fb640:	10000005 */ 	beqz	$zero,.L0f0fb658
/*  f0fb644:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0fb648:	44059000 */ 	mfc1	$a1,$f18
.L0f0fb64c:
/*  f0fb64c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb650:	04a0fffb */ 	bltz	$a1,.L0f0fb640
/*  f0fb654:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fb658:
/*  f0fb658:	44caf800 */ 	ctc1	$t2,$31
/*  f0fb65c:	0fc54df7 */ 	jal	func0f1537dc
/*  f0fb660:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb664:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f0fb668:	0c002f02 */ 	jal	func0000bc08
/*  f0fb66c:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0fb670:	0c002f06 */ 	jal	func0000bc18
/*  f0fb674:	a7a2003a */ 	sh	$v0,0x3a($sp)
/*  f0fb678:	87ae003a */ 	lh	$t6,0x3a($sp)
/*  f0fb67c:	304b03ff */ 	andi	$t3,$v0,0x3ff
/*  f0fb680:	8fa30070 */ 	lw	$v1,0x70($sp)
/*  f0fb684:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0fb688:	3c01f600 */ 	lui	$at,0xf600
/*  f0fb68c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0fb690:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0fb694:	01816825 */ 	or	$t5,$t4,$at
/*  f0fb698:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f0fb69c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fb6a0:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0fb6a4:	0fc54e0e */ 	jal	func0f153838
/*  f0fb6a8:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0fb6ac:	10000136 */ 	beqz	$zero,.L0f0fbb88
/*  f0fb6b0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fb6b4:	02001025 */ 	or	$v0,$s0,$zero
/*  f0fb6b8:	3c038006 */ 	lui	$v1,%hi(var800613a0)
/*  f0fb6bc:	246313a0 */ 	addiu	$v1,$v1,%lo(var800613a0)
/*  f0fb6c0:	3c080600 */ 	lui	$t0,0x600
/*  f0fb6c4:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f0fb6c8:	ac430004 */ 	sw	$v1,0x4($v0)
/*  f0fb6cc:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0fb6d0:	e7ac0088 */ 	swc1	$f12,0x88($sp)
/*  f0fb6d4:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0fb6d8:	0fc54df7 */ 	jal	func0f1537dc
/*  f0fb6dc:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f0fb6e0:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f0fb6e4:	0c002f02 */ 	jal	func0000bc08
/*  f0fb6e8:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0fb6ec:	0c002f06 */ 	jal	func0000bc18
/*  f0fb6f0:	a7a2003a */ 	sh	$v0,0x3a($sp)
/*  f0fb6f4:	87ac003a */ 	lh	$t4,0x3a($sp)
/*  f0fb6f8:	304903ff */ 	andi	$t1,$v0,0x3ff
/*  f0fb6fc:	8fa30068 */ 	lw	$v1,0x68($sp)
/*  f0fb700:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0fb704:	3c01f600 */ 	lui	$at,0xf600
/*  f0fb708:	318e03ff */ 	andi	$t6,$t4,0x3ff
/*  f0fb70c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0fb710:	01415825 */ 	or	$t3,$t2,$at
/*  f0fb714:	016f6825 */ 	or	$t5,$t3,$t7
/*  f0fb718:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fb71c:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0fb720:	0fc54e0e */ 	jal	func0f153838
/*  f0fb724:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0fb728:	0fc39400 */ 	jal	func0f0e5000
/*  f0fb72c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fb730:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fb734:	44810000 */ 	mtc1	$at,$f0
/*  f0fb738:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f0fb73c:	3c01437f */ 	lui	$at,0x437f
/*  f0fb740:	44814000 */ 	mtc1	$at,$f8
/*  f0fb744:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0fb748:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fb74c:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fb750:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fb754:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0fb758:	02001025 */ 	or	$v0,$s0,$zero
/*  f0fb75c:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0fb760:	3c190600 */ 	lui	$t9,0x600
/*  f0fb764:	4458f800 */ 	cfc1	$t8,$31
/*  f0fb768:	44c6f800 */ 	ctc1	$a2,$31
/*  f0fb76c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb770:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0fb774:	4446f800 */ 	cfc1	$a2,$31
/*  f0fb778:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb77c:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0fb780:	50c00013 */ 	beqzl	$a2,.L0f0fb7d0
/*  f0fb784:	44068000 */ 	mfc1	$a2,$f16
/*  f0fb788:	44818000 */ 	mtc1	$at,$f16
/*  f0fb78c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fb790:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0fb794:	44c6f800 */ 	ctc1	$a2,$31
/*  f0fb798:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb79c:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0fb7a0:	4446f800 */ 	cfc1	$a2,$31
/*  f0fb7a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb7a8:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0fb7ac:	14c00005 */ 	bnez	$a2,.L0f0fb7c4
/*  f0fb7b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb7b4:	44068000 */ 	mfc1	$a2,$f16
/*  f0fb7b8:	3c018000 */ 	lui	$at,0x8000
/*  f0fb7bc:	10000007 */ 	beqz	$zero,.L0f0fb7dc
/*  f0fb7c0:	00c13025 */ 	or	$a2,$a2,$at
.L0f0fb7c4:
/*  f0fb7c4:	10000005 */ 	beqz	$zero,.L0f0fb7dc
/*  f0fb7c8:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0fb7cc:	44068000 */ 	mfc1	$a2,$f16
.L0f0fb7d0:
/*  f0fb7d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb7d4:	04c0fffb */ 	bltz	$a2,.L0f0fb7c4
/*  f0fb7d8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fb7dc:
/*  f0fb7dc:	44d8f800 */ 	ctc1	$t8,$31
/*  f0fb7e0:	50c000ea */ 	beqzl	$a2,.L0f0fbb8c
/*  f0fb7e4:	02001025 */ 	or	$v0,$s0,$zero
/*  f0fb7e8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0fb7ec:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f0fb7f0:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0fb7f4:	0fc54df7 */ 	jal	func0f1537dc
/*  f0fb7f8:	ac480004 */ 	sw	$t0,0x4($v0)
/*  f0fb7fc:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f0fb800:	0c002f02 */ 	jal	func0000bc08
/*  f0fb804:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0fb808:	0c002f06 */ 	jal	func0000bc18
/*  f0fb80c:	a7a2003a */ 	sh	$v0,0x3a($sp)
/*  f0fb810:	87ae003a */ 	lh	$t6,0x3a($sp)
/*  f0fb814:	304903ff */ 	andi	$t1,$v0,0x3ff
/*  f0fb818:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f0fb81c:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0fb820:	3c01f600 */ 	lui	$at,0xf600
/*  f0fb824:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f0fb828:	000b7b80 */ 	sll	$t7,$t3,0xe
/*  f0fb82c:	01416025 */ 	or	$t4,$t2,$at
/*  f0fb830:	018f6825 */ 	or	$t5,$t4,$t7
/*  f0fb834:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fb838:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0fb83c:	0fc54e0e */ 	jal	func0f153838
/*  f0fb840:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0fb844:	100000d0 */ 	beqz	$zero,.L0f0fbb88
/*  f0fb848:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fb84c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fb850:	44810000 */ 	mtc1	$at,$f0
/*  f0fb854:	3c01437f */ 	lui	$at,0x437f
/*  f0fb858:	44812000 */ 	mtc1	$at,$f4
/*  f0fb85c:	460c0481 */ 	sub.s	$f18,$f0,$f12
/*  f0fb860:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fb864:	3c198006 */ 	lui	$t9,%hi(var800613a0)
/*  f0fb868:	273913a0 */ 	addiu	$t9,$t9,%lo(var800613a0)
/*  f0fb86c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0fb870:	3c180600 */ 	lui	$t8,0x600
/*  f0fb874:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f0fb878:	ae190004 */ 	sw	$t9,0x4($s0)
/*  f0fb87c:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0fb880:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fb884:	4448f800 */ 	cfc1	$t0,$31
/*  f0fb888:	44c6f800 */ 	ctc1	$a2,$31
/*  f0fb88c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb890:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0fb894:	4446f800 */ 	cfc1	$a2,$31
/*  f0fb898:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb89c:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0fb8a0:	50c00013 */ 	beqzl	$a2,.L0f0fb8f0
/*  f0fb8a4:	44064000 */ 	mfc1	$a2,$f8
/*  f0fb8a8:	44814000 */ 	mtc1	$at,$f8
/*  f0fb8ac:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fb8b0:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0fb8b4:	44c6f800 */ 	ctc1	$a2,$31
/*  f0fb8b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb8bc:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0fb8c0:	4446f800 */ 	cfc1	$a2,$31
/*  f0fb8c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb8c8:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0fb8cc:	14c00005 */ 	bnez	$a2,.L0f0fb8e4
/*  f0fb8d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb8d4:	44064000 */ 	mfc1	$a2,$f8
/*  f0fb8d8:	3c018000 */ 	lui	$at,0x8000
/*  f0fb8dc:	10000007 */ 	beqz	$zero,.L0f0fb8fc
/*  f0fb8e0:	00c13025 */ 	or	$a2,$a2,$at
.L0f0fb8e4:
/*  f0fb8e4:	10000005 */ 	beqz	$zero,.L0f0fb8fc
/*  f0fb8e8:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0fb8ec:	44064000 */ 	mfc1	$a2,$f8
.L0f0fb8f0:
/*  f0fb8f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb8f4:	04c0fffb */ 	bltz	$a2,.L0f0fb8e4
/*  f0fb8f8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fb8fc:
/*  f0fb8fc:	00064e00 */ 	sll	$t1,$a2,0x18
/*  f0fb900:	00065400 */ 	sll	$t2,$a2,0x10
/*  f0fb904:	012a7025 */ 	or	$t6,$t1,$t2
/*  f0fb908:	00065a00 */ 	sll	$t3,$a2,0x8
/*  f0fb90c:	01cb2825 */ 	or	$a1,$t6,$t3
/*  f0fb910:	34ac00ff */ 	ori	$t4,$a1,0xff
/*  f0fb914:	44c8f800 */ 	ctc1	$t0,$31
/*  f0fb918:	0fc54df7 */ 	jal	func0f1537dc
/*  f0fb91c:	01802825 */ 	or	$a1,$t4,$zero
/*  f0fb920:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0fb924:	0c002f02 */ 	jal	func0000bc08
/*  f0fb928:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0fb92c:	0c002f06 */ 	jal	func0000bc18
/*  f0fb930:	a7a2003a */ 	sh	$v0,0x3a($sp)
/*  f0fb934:	87b9003a */ 	lh	$t9,0x3a($sp)
/*  f0fb938:	304f03ff */ 	andi	$t7,$v0,0x3ff
/*  f0fb93c:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0fb940:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f0fb944:	3c01f600 */ 	lui	$at,0xf600
/*  f0fb948:	332803ff */ 	andi	$t0,$t9,0x3ff
/*  f0fb94c:	00084b80 */ 	sll	$t1,$t0,0xe
/*  f0fb950:	01a1c025 */ 	or	$t8,$t5,$at
/*  f0fb954:	03095025 */ 	or	$t2,$t8,$t1
/*  f0fb958:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fb95c:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0fb960:	0fc54e0e */ 	jal	func0f153838
/*  f0fb964:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0fb968:	0fc38e74 */ 	jal	func0f0e39d0
/*  f0fb96c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fb970:	10000085 */ 	beqz	$zero,.L0f0fbb88
/*  f0fb974:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fb978:	3c047f1b */ 	lui	$a0,%hi(var7f1b2778)
/*  f0fb97c:	3c058007 */ 	lui	$a1,%hi(var800714ec)
/*  f0fb980:	24a514ec */ 	addiu	$a1,$a1,%lo(var800714ec)
/*  f0fb984:	24842778 */ 	addiu	$a0,$a0,%lo(var7f1b2778)
/*  f0fb988:	0c0036cc */ 	jal	func0000db30
/*  f0fb98c:	e7ac0088 */ 	swc1	$f12,0x88($sp)
/*  f0fb990:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fb994:	91ce19d6 */ 	lbu	$t6,0x19d6($t6)
/*  f0fb998:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0fb99c:	11c00003 */ 	beqz	$t6,.L0f0fb9ac
/*  f0fb9a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fb9a4:	10000079 */ 	beqz	$zero,.L0f0fbb8c
/*  f0fb9a8:	02001025 */ 	or	$v0,$s0,$zero
.L0f0fb9ac:
/*  f0fb9ac:	8d6b14ec */ 	lw	$t3,0x14ec($t3)
/*  f0fb9b0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fb9b4:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0fb9b8:	11600073 */ 	beqz	$t3,.L0f0fbb88
/*  f0fb9bc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fb9c0:	0fc38266 */ 	jal	func0f0e0998
/*  f0fb9c4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fb9c8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fb9cc:	44810000 */ 	mtc1	$at,$f0
/*  f0fb9d0:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f0fb9d4:	3c0f8006 */ 	lui	$t7,%hi(var800613a0)
/*  f0fb9d8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fb9dc:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0fb9e0:	25ef13a0 */ 	addiu	$t7,$t7,%lo(var800613a0)
/*  f0fb9e4:	3c0c0600 */ 	lui	$t4,0x600
/*  f0fb9e8:	45020068 */ 	bc1fl	.L0f0fbb8c
/*  f0fb9ec:	02001025 */ 	or	$v0,$s0,$zero
/*  f0fb9f0:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0fb9f4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0fb9f8:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f0fb9fc:	3c01437f */ 	lui	$at,0x437f
/*  f0fba00:	44812000 */ 	mtc1	$at,$f4
/*  f0fba04:	46100481 */ 	sub.s	$f18,$f0,$f16
/*  f0fba08:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fba0c:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0fba10:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fba14:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0fba18:	444df800 */ 	cfc1	$t5,$31
/*  f0fba1c:	44c5f800 */ 	ctc1	$a1,$31
/*  f0fba20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fba24:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0fba28:	4445f800 */ 	cfc1	$a1,$31
/*  f0fba2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fba30:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0fba34:	50a00013 */ 	beqzl	$a1,.L0f0fba84
/*  f0fba38:	44054000 */ 	mfc1	$a1,$f8
/*  f0fba3c:	44814000 */ 	mtc1	$at,$f8
/*  f0fba40:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fba44:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0fba48:	44c5f800 */ 	ctc1	$a1,$31
/*  f0fba4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fba50:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0fba54:	4445f800 */ 	cfc1	$a1,$31
/*  f0fba58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fba5c:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0fba60:	14a00005 */ 	bnez	$a1,.L0f0fba78
/*  f0fba64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fba68:	44054000 */ 	mfc1	$a1,$f8
/*  f0fba6c:	3c018000 */ 	lui	$at,0x8000
/*  f0fba70:	10000007 */ 	beqz	$zero,.L0f0fba90
/*  f0fba74:	00a12825 */ 	or	$a1,$a1,$at
.L0f0fba78:
/*  f0fba78:	10000005 */ 	beqz	$zero,.L0f0fba90
/*  f0fba7c:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0fba80:	44054000 */ 	mfc1	$a1,$f8
.L0f0fba84:
/*  f0fba84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fba88:	04a0fffb */ 	bltz	$a1,.L0f0fba78
/*  f0fba8c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fba90:
/*  f0fba90:	3c01ff00 */ 	lui	$at,0xff00
/*  f0fba94:	00a1c825 */ 	or	$t9,$a1,$at
/*  f0fba98:	44cdf800 */ 	ctc1	$t5,$31
/*  f0fba9c:	0fc54df7 */ 	jal	func0f1537dc
/*  f0fbaa0:	03202825 */ 	or	$a1,$t9,$zero
/*  f0fbaa4:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f0fbaa8:	0c002f02 */ 	jal	func0000bc08
/*  f0fbaac:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0fbab0:	0c002f06 */ 	jal	func0000bc18
/*  f0fbab4:	a7a2003a */ 	sh	$v0,0x3a($sp)
/*  f0fbab8:	87aa003a */ 	lh	$t2,0x3a($sp)
/*  f0fbabc:	304803ff */ 	andi	$t0,$v0,0x3ff
/*  f0fbac0:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0fbac4:	0008c080 */ 	sll	$t8,$t0,0x2
/*  f0fbac8:	3c01f600 */ 	lui	$at,0xf600
/*  f0fbacc:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f0fbad0:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f0fbad4:	03014825 */ 	or	$t1,$t8,$at
/*  f0fbad8:	012b6025 */ 	or	$t4,$t1,$t3
/*  f0fbadc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fbae0:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f0fbae4:	0fc54e0e */ 	jal	func0f153838
/*  f0fbae8:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0fbaec:	10000026 */ 	beqz	$zero,.L0f0fbb88
/*  f0fbaf0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fbaf4:	0c002f02 */ 	jal	func0000bc08
/*  f0fbaf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbafc:	0c002f06 */ 	jal	func0000bc18
/*  f0fbb00:	a7a20038 */ 	sh	$v0,0x38($sp)
/*  f0fbb04:	3c198f00 */ 	lui	$t9,0x8f00
/*  f0fbb08:	373900ff */ 	ori	$t9,$t9,0xff
/*  f0fbb0c:	240f7f7f */ 	addiu	$t7,$zero,0x7f7f
/*  f0fbb10:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f0fbb14:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0fbb18:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0fbb1c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0fbb20:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fbb24:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fbb28:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fbb2c:	87a70038 */ 	lh	$a3,0x38($sp)
/*  f0fbb30:	0fc3873a */ 	jal	func0f0e1ce8
/*  f0fbb34:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0fbb38:	10000013 */ 	beqz	$zero,.L0f0fbb88
/*  f0fbb3c:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fbb40:	0c002f02 */ 	jal	func0000bc08
/*  f0fbb44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbb48:	0c002f06 */ 	jal	func0000bc18
/*  f0fbb4c:	a7a20038 */ 	sh	$v0,0x38($sp)
/*  f0fbb50:	3c033f3f */ 	lui	$v1,0x3f3f
/*  f0fbb54:	3c087f00 */ 	lui	$t0,0x7f00
/*  f0fbb58:	350800ff */ 	ori	$t0,$t0,0xff
/*  f0fbb5c:	346300ff */ 	ori	$v1,$v1,0xff
/*  f0fbb60:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0fbb64:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0fbb68:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0fbb6c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fbb70:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fbb74:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fbb78:	87a70038 */ 	lh	$a3,0x38($sp)
/*  f0fbb7c:	0fc3873a */ 	jal	func0f0e1ce8
/*  f0fbb80:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0fbb84:	00408025 */ 	or	$s0,$v0,$zero
.L0f0fbb88:
/*  f0fbb88:	02001025 */ 	or	$v0,$s0,$zero
.L0f0fbb8c:
/*  f0fbb8c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0fbb90:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0fbb94:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*  f0fbb98:	03e00008 */ 	jr	$ra
/*  f0fbb9c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0fbba0
/*  f0fbba0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0fbba4:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f0fbba8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fbbac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fbbb0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0fbbb4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0fbbb8:	11c10003 */ 	beq	$t6,$at,.L0f0fbbc8
/*  f0fbbbc:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0fbbc0:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0fbbc4:	15c10015 */ 	bne	$t6,$at,.L0f0fbc1c
.L0f0fbbc8:
/*  f0fbbc8:	3c047f1b */ 	lui	$a0,%hi(var7f1b2780)
/*  f0fbbcc:	3c058007 */ 	lui	$a1,%hi(var800714f0)
/*  f0fbbd0:	24a514f0 */ 	addiu	$a1,$a1,%lo(var800714f0)
/*  f0fbbd4:	0c0036cc */ 	jal	func0000db30
/*  f0fbbd8:	24842780 */ 	addiu	$a0,$a0,%lo(var7f1b2780)
/*  f0fbbdc:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0fbbe0:	8def14f0 */ 	lw	$t7,0x14f0($t7)
/*  f0fbbe4:	3c02800a */ 	lui	$v0,0x800a
/*  f0fbbe8:	51e0000d */ 	beqzl	$t7,.L0f0fbc20
/*  f0fbbec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fbbf0:	904219d5 */ 	lbu	$v0,0x19d5($v0)
/*  f0fbbf4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fbbf8:	10410005 */ 	beq	$v0,$at,.L0f0fbc10
/*  f0fbbfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbc00:	10400003 */ 	beqz	$v0,.L0f0fbc10
/*  f0fbc04:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0fbc08:	54410005 */ 	bnel	$v0,$at,.L0f0fbc20
/*  f0fbc0c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fbc10:
/*  f0fbc10:	0fc39064 */ 	jal	func0f0e4190
/*  f0fbc14:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0fbc18:	afa20018 */ 	sw	$v0,0x18($sp)
.L0f0fbc1c:
/*  f0fbc1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fbc20:
/*  f0fbc20:	8fa20018 */ 	lw	$v0,0x18($sp)
/*  f0fbc24:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0fbc28:	03e00008 */ 	jr	$ra
/*  f0fbc2c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0fbc30
/*  f0fbc30:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f0fbc34:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0fbc38:	3c118007 */ 	lui	$s1,%hi(g_MpPlayerNum)
/*  f0fbc3c:	26311448 */ 	addiu	$s1,$s1,%lo(g_MpPlayerNum)
/*  f0fbc40:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f0fbc44:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0fbc48:	8dce06c8 */ 	lw	$t6,0x6c8($t6)
/*  f0fbc4c:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f0fbc50:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0fbc54:	0080a825 */ 	or	$s5,$a0,$zero
/*  f0fbc58:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f0fbc5c:	afb70050 */ 	sw	$s7,0x50($sp)
/*  f0fbc60:	afb6004c */ 	sw	$s6,0x4c($sp)
/*  f0fbc64:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f0fbc68:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f0fbc6c:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f0fbc70:	144e0005 */ 	bne	$v0,$t6,.L0f0fbc88
/*  f0fbc74:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0fbc78:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0fbc7c:	3c018008 */ 	lui	$at,0x8008
/*  f0fbc80:	10000003 */ 	beqz	$zero,.L0f0fbc90
/*  f0fbc84:	ac2ffac0 */ 	sw	$t7,-0x540($at)
.L0f0fbc88:
/*  f0fbc88:	3c018008 */ 	lui	$at,0x8008
/*  f0fbc8c:	ac22fac0 */ 	sw	$v0,-0x540($at)
.L0f0fbc90:
/*  f0fbc90:	0fc351e7 */ 	jal	func0f0d479c
/*  f0fbc94:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fbc98:	3c138006 */ 	lui	$s3,%hi(var800613a0)
/*  f0fbc9c:	3c17800a */ 	lui	$s7,%hi(var800a19c0)
/*  f0fbca0:	267313a0 */ 	addiu	$s3,$s3,%lo(var800613a0)
/*  f0fbca4:	3c180600 */ 	lui	$t8,0x600
/*  f0fbca8:	26f719c0 */ 	addiu	$s7,$s7,%lo(var800a19c0)
/*  f0fbcac:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0fbcb0:	ac530004 */ 	sw	$s3,0x4($v0)
/*  f0fbcb4:	92e30015 */ 	lbu	$v1,0x15($s7)
/*  f0fbcb8:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f0fbcbc:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0fbcc0:	10610017 */ 	beq	$v1,$at,.L0f0fbd20
/*  f0fbcc4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fbcc8:	1460000c */ 	bnez	$v1,.L0f0fbcfc
/*  f0fbccc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fbcd0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fbcd4:	44812000 */ 	mtc1	$at,$f4
/*  f0fbcd8:	c6e60010 */ 	lwc1	$f6,0x10($s7)
/*  f0fbcdc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fbce0:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fbce4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0fbce8:	44064000 */ 	mfc1	$a2,$f8
/*  f0fbcec:	0fc3ed22 */ 	jal	func0f0fb488
/*  f0fbcf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbcf4:	1000000e */ 	beqz	$zero,.L0f0fbd30
/*  f0fbcf8:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fbcfc:
/*  f0fbcfc:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fbd00:	0fc3ed22 */ 	jal	func0f0fb488
/*  f0fbd04:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0fbd08:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fbd0c:	92e50015 */ 	lbu	$a1,0x15($s7)
/*  f0fbd10:	0fc3ed22 */ 	jal	func0f0fb488
/*  f0fbd14:	8ee60010 */ 	lw	$a2,0x10($s7)
/*  f0fbd18:	10000005 */ 	beqz	$zero,.L0f0fbd30
/*  f0fbd1c:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fbd20:
/*  f0fbd20:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fbd24:	0fc3ed22 */ 	jal	func0f0fb488
/*  f0fbd28:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0fbd2c:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fbd30:
/*  f0fbd30:	8ef905d4 */ 	lw	$t9,0x5d4($s7)
/*  f0fbd34:	240c040d */ 	addiu	$t4,$zero,0x40d
/*  f0fbd38:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fbd3c:	00195b00 */ 	sll	$t3,$t9,0xc
/*  f0fbd40:	0561000b */ 	bgez	$t3,.L0f0fbd70
/*  f0fbd44:	3c0a8009 */ 	lui	$t2,0x8009
/*  f0fbd48:	92ed05cd */ 	lbu	$t5,0x5cd($s7)
/*  f0fbd4c:	92f805d5 */ 	lbu	$t8,0x5d5($s7)
/*  f0fbd50:	a6e0007a */ 	sh	$zero,0x7a($s7)
/*  f0fbd54:	31aeffef */ 	andi	$t6,$t5,0xffef
/*  f0fbd58:	3319fff7 */ 	andi	$t9,$t8,0xfff7
/*  f0fbd5c:	a6ec0078 */ 	sh	$t4,0x78($s7)
/*  f0fbd60:	aee0059c */ 	sw	$zero,0x59c($s7)
/*  f0fbd64:	a2ee05cd */ 	sb	$t6,0x5cd($s7)
/*  f0fbd68:	a2ef05d4 */ 	sb	$t7,0x5d4($s7)
/*  f0fbd6c:	a2f905d5 */ 	sb	$t9,0x5d5($s7)
.L0f0fbd70:
/*  f0fbd70:	914a0af0 */ 	lbu	$t2,0xaf0($t2)
/*  f0fbd74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fbd78:	114100ab */ 	beq	$t2,$at,.L0f0fc028
/*  f0fbd7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbd80:	92eb05d4 */ 	lbu	$t3,0x5d4($s7)
/*  f0fbd84:	02a01025 */ 	or	$v0,$s5,$zero
/*  f0fbd88:	3c0cb700 */ 	lui	$t4,0xb700
/*  f0fbd8c:	116000a6 */ 	beqz	$t3,.L0f0fc028
/*  f0fbd90:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0fbd94:	00008025 */ 	or	$s0,$zero,$zero
/*  f0fbd98:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f0fbd9c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0fbda0:	0c004b70 */ 	jal	random
/*  f0fbda4:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f0fbda8:	44825000 */ 	mtc1	$v0,$f10
/*  f0fbdac:	3c014f80 */ 	lui	$at,0x4f80
/*  f0fbdb0:	04410004 */ 	bgez	$v0,.L0f0fbdc4
/*  f0fbdb4:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0fbdb8:	44819000 */ 	mtc1	$at,$f18
/*  f0fbdbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbdc0:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f0fbdc4:
/*  f0fbdc4:	3c012f80 */ 	lui	$at,0x2f80
/*  f0fbdc8:	44812000 */ 	mtc1	$at,$f4
/*  f0fbdcc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0fbdd0:	d42a2af0 */ 	ldc1	$f10,0x2af0($at)
/*  f0fbdd4:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0fbdd8:	46003221 */ 	cvt.d.s	$f8,$f6
/*  f0fbddc:	462a403c */ 	c.lt.d	$f8,$f10
/*  f0fbde0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbde4:	4502002d */ 	bc1fl	.L0f0fbe9c
/*  f0fbde8:	8ee30004 */ 	lw	$v1,0x4($s7)
/*  f0fbdec:	0c004b70 */ 	jal	random
/*  f0fbdf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbdf4:	44829000 */ 	mtc1	$v0,$f18
/*  f0fbdf8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0fbdfc:	04410004 */ 	bgez	$v0,.L0f0fbe10
/*  f0fbe00:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f0fbe04:	44812000 */ 	mtc1	$at,$f4
/*  f0fbe08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbe0c:	46048400 */ 	add.s	$f16,$f16,$f4
.L0f0fbe10:
/*  f0fbe10:	3c012f80 */ 	lui	$at,0x2f80
/*  f0fbe14:	44813000 */ 	mtc1	$at,$f6
/*  f0fbe18:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0fbe1c:	44815000 */ 	mtc1	$at,$f10
/*  f0fbe20:	46068202 */ 	mul.s	$f8,$f16,$f6
/*  f0fbe24:	3c017f1b */ 	lui	$at,%hi(var7f1b2af8)
/*  f0fbe28:	c4242af8 */ 	lwc1	$f4,%lo(var7f1b2af8)($at)
/*  f0fbe2c:	3c014220 */ 	lui	$at,0x4220
/*  f0fbe30:	44813000 */ 	mtc1	$at,$f6
/*  f0fbe34:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0fbe38:	46049400 */ 	add.s	$f16,$f18,$f4
/*  f0fbe3c:	46068201 */ 	sub.s	$f8,$f16,$f6
/*  f0fbe40:	0c004b70 */ 	jal	random
/*  f0fbe44:	e6e80554 */ 	swc1	$f8,0x554($s7)
/*  f0fbe48:	44825000 */ 	mtc1	$v0,$f10
/*  f0fbe4c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0fbe50:	04410004 */ 	bgez	$v0,.L0f0fbe64
/*  f0fbe54:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f0fbe58:	44812000 */ 	mtc1	$at,$f4
/*  f0fbe5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbe60:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f0fbe64:
/*  f0fbe64:	3c012f80 */ 	lui	$at,0x2f80
/*  f0fbe68:	44818000 */ 	mtc1	$at,$f16
/*  f0fbe6c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0fbe70:	44814000 */ 	mtc1	$at,$f8
/*  f0fbe74:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f0fbe78:	3c017f1b */ 	lui	$at,%hi(var7f1b2afc)
/*  f0fbe7c:	c4242afc */ 	lwc1	$f4,%lo(var7f1b2afc)($at)
/*  f0fbe80:	3c014220 */ 	lui	$at,0x4220
/*  f0fbe84:	44818000 */ 	mtc1	$at,$f16
/*  f0fbe88:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0fbe8c:	46045480 */ 	add.s	$f18,$f10,$f4
/*  f0fbe90:	46109181 */ 	sub.s	$f6,$f18,$f16
/*  f0fbe94:	e6e60558 */ 	swc1	$f6,0x558($s7)
/*  f0fbe98:	8ee30004 */ 	lw	$v1,0x4($s7)
.L0f0fbe9c:
/*  f0fbe9c:	3c12800a */ 	lui	$s2,%hi(var8009de9c)
/*  f0fbea0:	3c14800a */ 	lui	$s4,%hi(var8009de98)
/*  f0fbea4:	2694de98 */ 	addiu	$s4,$s4,%lo(var8009de98)
/*  f0fbea8:	2652de9c */ 	addiu	$s2,$s2,%lo(var8009de9c)
/*  f0fbeac:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f0fbeb0:	ae400000 */ 	sw	$zero,0x0($s2)
/*  f0fbeb4:	14c30005 */ 	bne	$a2,$v1,.L0f0fbecc
/*  f0fbeb8:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f0fbebc:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0fbec0:	5de00003 */ 	bgtzl	$t7,.L0f0fbed0
/*  f0fbec4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fbec8:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0fbecc:
/*  f0fbecc:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0fbed0:
/*  f0fbed0:	10610008 */ 	beq	$v1,$at,.L0f0fbef4
/*  f0fbed4:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f0fbed8:	10c30006 */ 	beq	$a2,$v1,.L0f0fbef4
/*  f0fbedc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0fbee0:	10610004 */ 	beq	$v1,$at,.L0f0fbef4
/*  f0fbee4:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0fbee8:	50610003 */ 	beql	$v1,$at,.L0f0fbef8
/*  f0fbeec:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0fbef0:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0fbef4:
/*  f0fbef4:	8e380000 */ 	lw	$t8,0x0($s1)
.L0f0fbef8:
/*  f0fbef8:	3c0a800a */ 	lui	$t2,0x800a
/*  f0fbefc:	3c047f1b */ 	lui	$a0,%hi(var7f1b2788)
/*  f0fbf00:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0fbf04:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0fbf08:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fbf0c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0fbf10:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fbf14:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0fbf18:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fbf1c:	01595021 */ 	addu	$t2,$t2,$t9
/*  f0fbf20:	8d4ae4f8 */ 	lw	$t2,-0x1b08($t2)
/*  f0fbf24:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f0fbf28:	24842788 */ 	addiu	$a0,$a0,%lo(var7f1b2788)
/*  f0fbf2c:	15400004 */ 	bnez	$t2,.L0f0fbf40
/*  f0fbf30:	3c058007 */ 	lui	$a1,%hi(var800714f4)
/*  f0fbf34:	50c30003 */ 	beql	$a2,$v1,.L0f0fbf44
/*  f0fbf38:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f0fbf3c:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0fbf40:
/*  f0fbf40:	8ec30284 */ 	lw	$v1,0x284($s6)
.L0f0fbf44:
/*  f0fbf44:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f0fbf48:	1040000c */ 	beqz	$v0,.L0f0fbf7c
/*  f0fbf4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbf50:	8c6c1c54 */ 	lw	$t4,0x1c54($v1)
/*  f0fbf54:	8c6b00c4 */ 	lw	$t3,0xc4($v1)
/*  f0fbf58:	01806827 */ 	nor	$t5,$t4,$zero
/*  f0fbf5c:	016d7024 */ 	and	$t6,$t3,$t5
/*  f0fbf60:	31cf0004 */ 	andi	$t7,$t6,0x4
/*  f0fbf64:	11e00005 */ 	beqz	$t7,.L0f0fbf7c
/*  f0fbf68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbf6c:	80580037 */ 	lb	$t8,0x37($v0)
/*  f0fbf70:	13000002 */ 	beqz	$t8,.L0f0fbf7c
/*  f0fbf74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbf78:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0fbf7c:
/*  f0fbf7c:	12000012 */ 	beqz	$s0,.L0f0fbfc8
/*  f0fbf80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbf84:	8ef9059c */ 	lw	$t9,0x59c($s7)
/*  f0fbf88:	240d040d */ 	addiu	$t5,$zero,0x40d
/*  f0fbf8c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0fbf90:	57200009 */ 	bnezl	$t9,.L0f0fbfb8
/*  f0fbf94:	86ef007a */ 	lh	$t7,0x7a($s7)
/*  f0fbf98:	92ec05cd */ 	lbu	$t4,0x5cd($s7)
/*  f0fbf9c:	a6e0007a */ 	sh	$zero,0x7a($s7)
/*  f0fbfa0:	a6ed0078 */ 	sh	$t5,0x78($s7)
/*  f0fbfa4:	358b0010 */ 	ori	$t3,$t4,0x10
/*  f0fbfa8:	a2eb05cd */ 	sb	$t3,0x5cd($s7)
/*  f0fbfac:	10000006 */ 	beqz	$zero,.L0f0fbfc8
/*  f0fbfb0:	aeee059c */ 	sw	$t6,0x59c($s7)
/*  f0fbfb4:	86ef007a */ 	lh	$t7,0x7a($s7)
.L0f0fbfb8:
/*  f0fbfb8:	15e00003 */ 	bnez	$t7,.L0f0fbfc8
/*  f0fbfbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbfc0:	aee0059c */ 	sw	$zero,0x59c($s7)
/*  f0fbfc4:	a2e005d4 */ 	sb	$zero,0x5d4($s7)
.L0f0fbfc8:
/*  f0fbfc8:	0c0036cc */ 	jal	func0000db30
/*  f0fbfcc:	24a514f4 */ 	addiu	$a1,$a1,%lo(var800714f4)
/*  f0fbfd0:	3c188007 */ 	lui	$t8,0x8007
/*  f0fbfd4:	8f1814f4 */ 	lw	$t8,0x14f4($t8)
/*  f0fbfd8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fbfdc:	3c05800a */ 	lui	$a1,%hi(var800a19dc)
/*  f0fbfe0:	1300000f */ 	beqz	$t8,.L0f0fc020
/*  f0fbfe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fbfe8:	92f905d5 */ 	lbu	$t9,0x5d5($s7)
/*  f0fbfec:	24a519dc */ 	addiu	$a1,$a1,%lo(var800a19dc)
/*  f0fbff0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fbff4:	332affdf */ 	andi	$t2,$t9,0xffdf
/*  f0fbff8:	0fc3ce2c */ 	jal	func0f0f38b0
/*  f0fbffc:	a2ea05d5 */ 	sb	$t2,0x5d5($s7)
/*  f0fc000:	3c0cb600 */ 	lui	$t4,0xb600
/*  f0fc004:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0fc008:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f0fc00c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0fc010:	92ee05d5 */ 	lbu	$t6,0x5d5($s7)
/*  f0fc014:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f0fc018:	35cf0020 */ 	ori	$t7,$t6,0x20
/*  f0fc01c:	a2ef05d5 */ 	sb	$t7,0x5d5($s7)
.L0f0fc020:
/*  f0fc020:	1000000a */ 	beqz	$zero,.L0f0fc04c
/*  f0fc024:	8ee205d4 */ 	lw	$v0,0x5d4($s7)
.L0f0fc028:
/*  f0fc028:	3c12800a */ 	lui	$s2,%hi(var8009de9c)
/*  f0fc02c:	3c14800a */ 	lui	$s4,%hi(var8009de98)
/*  f0fc030:	2694de98 */ 	addiu	$s4,$s4,%lo(var8009de98)
/*  f0fc034:	2652de9c */ 	addiu	$s2,$s2,%lo(var8009de9c)
/*  f0fc038:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f0fc03c:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f0fc040:	ae400000 */ 	sw	$zero,0x0($s2)
/*  f0fc044:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f0fc048:	8ee205d4 */ 	lw	$v0,0x5d4($s7)
.L0f0fc04c:
/*  f0fc04c:	000252c0 */ 	sll	$t2,$v0,0xb
/*  f0fc050:	05410005 */ 	bgez	$t2,.L0f0fc068
/*  f0fc054:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc058:	8eec0670 */ 	lw	$t4,0x670($s7)
/*  f0fc05c:	8eeb0674 */ 	lw	$t3,0x674($s7)
/*  f0fc060:	ae8c0000 */ 	sw	$t4,0x0($s4)
/*  f0fc064:	ae4b0000 */ 	sw	$t3,0x0($s2)
.L0f0fc068:
/*  f0fc068:	92e30015 */ 	lbu	$v1,0x15($s7)
/*  f0fc06c:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0fc070:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0fc074:	10610017 */ 	beq	$v1,$at,.L0f0fc0d4
/*  f0fc078:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc07c:	1460000c */ 	bnez	$v1,.L0f0fc0b0
/*  f0fc080:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc084:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fc088:	44814000 */ 	mtc1	$at,$f8
/*  f0fc08c:	c6ea0010 */ 	lwc1	$f10,0x10($s7)
/*  f0fc090:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc094:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fc098:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0fc09c:	44062000 */ 	mfc1	$a2,$f4
/*  f0fc0a0:	0fc3eee8 */ 	jal	func0f0fbba0
/*  f0fc0a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc0a8:	1000000d */ 	beqz	$zero,.L0f0fc0e0
/*  f0fc0ac:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc0b0:
/*  f0fc0b0:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fc0b4:	0fc3eee8 */ 	jal	func0f0fbba0
/*  f0fc0b8:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0fc0bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fc0c0:	92e50015 */ 	lbu	$a1,0x15($s7)
/*  f0fc0c4:	0fc3eee8 */ 	jal	func0f0fbba0
/*  f0fc0c8:	8ee60010 */ 	lw	$a2,0x10($s7)
/*  f0fc0cc:	10000004 */ 	beqz	$zero,.L0f0fc0e0
/*  f0fc0d0:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc0d4:
/*  f0fc0d4:	0fc3eee8 */ 	jal	func0f0fbba0
/*  f0fc0d8:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fc0dc:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc0e0:
/*  f0fc0e0:	92ed0014 */ 	lbu	$t5,0x14($s7)
/*  f0fc0e4:	55a00006 */ 	bnezl	$t5,.L0f0fc100
/*  f0fc0e8:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f0fc0ec:	92ee0015 */ 	lbu	$t6,0x15($s7)
/*  f0fc0f0:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0fc0f4:	51c10010 */ 	beql	$t6,$at,.L0f0fc138
/*  f0fc0f8:	8ef90000 */ 	lw	$t9,0x0($s7)
/*  f0fc0fc:	8ecf0284 */ 	lw	$t7,0x284($s6)
.L0f0fc100:
/*  f0fc100:	8de20480 */ 	lw	$v0,0x480($t7)
/*  f0fc104:	10400004 */ 	beqz	$v0,.L0f0fc118
/*  f0fc108:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc10c:	80580037 */ 	lb	$t8,0x37($v0)
/*  f0fc110:	57000009 */ 	bnezl	$t8,.L0f0fc138
/*  f0fc114:	8ef90000 */ 	lw	$t9,0x0($s7)
.L0f0fc118:
/*  f0fc118:	0fc35272 */ 	jal	func0f0d49c8
/*  f0fc11c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc120:	0fc2efde */ 	jal	func0f0bbf78
/*  f0fc124:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fc128:	0fc351e7 */ 	jal	func0f0d479c
/*  f0fc12c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fc130:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0fc134:	8ef90000 */ 	lw	$t9,0x0($s7)
.L0f0fc138:
/*  f0fc138:	5b20017b */ 	blezl	$t9,.L0f0fc728
/*  f0fc13c:	82f8001b */ 	lb	$t8,0x1b($s7)
/*  f0fc140:	0fc54eac */ 	jal	func0f153ab0
/*  f0fc144:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc148:	8ee30004 */ 	lw	$v1,0x4($s7)
/*  f0fc14c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fc150:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0fc154:	10610003 */ 	beq	$v1,$at,.L0f0fc164
/*  f0fc158:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0fc15c:	14610008 */ 	bne	$v1,$at,.L0f0fc180
/*  f0fc160:	00008025 */ 	or	$s0,$zero,$zero
.L0f0fc164:
/*  f0fc164:	8eca0288 */ 	lw	$t2,0x288($s6)
/*  f0fc168:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc16c:	8d4c0070 */ 	lw	$t4,0x70($t2)
/*  f0fc170:	0fc3e1aa */ 	jal	func0f0f86a8
/*  f0fc174:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f0fc178:	10000008 */ 	beqz	$zero,.L0f0fc19c
/*  f0fc17c:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc180:
/*  f0fc180:	ae300000 */ 	sw	$s0,0x0($s1)
/*  f0fc184:	0fc3e1aa */ 	jal	func0f0f86a8
/*  f0fc188:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc18c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0fc190:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fc194:	1601fffa */ 	bne	$s0,$at,.L0f0fc180
/*  f0fc198:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc19c:
/*  f0fc19c:	3c0b0103 */ 	lui	$t3,0x103
/*  f0fc1a0:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f0fc1a4:	356b0040 */ 	ori	$t3,$t3,0x40
/*  f0fc1a8:	02a08025 */ 	or	$s0,$s5,$zero
/*  f0fc1ac:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f0fc1b0:	0fc2d3fa */ 	jal	func0f0b4fe8
/*  f0fc1b4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f0fc1b8:	0c012d20 */ 	jal	func0004b480
/*  f0fc1bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fc1c0:	02a01825 */ 	or	$v1,$s5,$zero
/*  f0fc1c4:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0fc1c8:	3c0d0600 */ 	lui	$t5,0x600
/*  f0fc1cc:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0fc1d0:	ac730004 */ 	sw	$s3,0x4($v1)
/*  f0fc1d4:	0fc54ed0 */ 	jal	func0f153b40
/*  f0fc1d8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f0fc1dc:	8ee30004 */ 	lw	$v1,0x4($s7)
/*  f0fc1e0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fc1e4:	10610003 */ 	beq	$v1,$at,.L0f0fc1f4
/*  f0fc1e8:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0fc1ec:	54610148 */ 	bnel	$v1,$at,.L0f0fc710
/*  f0fc1f0:	02a01025 */ 	or	$v0,$s5,$zero
.L0f0fc1f4:
/*  f0fc1f4:	0c002f40 */ 	jal	func0000bd00
/*  f0fc1f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc1fc:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0fc200:	8dcefac0 */ 	lw	$t6,-0x540($t6)
/*  f0fc204:	004e001a */ 	div	$zero,$v0,$t6
/*  f0fc208:	00007812 */ 	mflo	$t7
/*  f0fc20c:	25f80014 */ 	addiu	$t8,$t7,0x14
/*  f0fc210:	15c00002 */ 	bnez	$t6,.L0f0fc21c
/*  f0fc214:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc218:	0007000d */ 	break	0x7
.L0f0fc21c:
/*  f0fc21c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fc220:	15c10004 */ 	bne	$t6,$at,.L0f0fc234
/*  f0fc224:	3c018000 */ 	lui	$at,0x8000
/*  f0fc228:	14410002 */ 	bne	$v0,$at,.L0f0fc234
/*  f0fc22c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc230:	0006000d */ 	break	0x6
.L0f0fc234:
/*  f0fc234:	afb800f0 */ 	sw	$t8,0xf0($sp)
/*  f0fc238:	0c002f44 */ 	jal	func0000bd10
/*  f0fc23c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc240:	24590004 */ 	addiu	$t9,$v0,0x4
/*  f0fc244:	0c002f40 */ 	jal	func0000bd00
/*  f0fc248:	afb900ec */ 	sw	$t9,0xec($sp)
/*  f0fc24c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fc250:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0fc254:	0c002f22 */ 	jal	func0000bc88
/*  f0fc258:	01408025 */ 	or	$s0,$t2,$zero
/*  f0fc25c:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0fc260:	8d6bfac0 */ 	lw	$t3,-0x540($t3)
/*  f0fc264:	00506021 */ 	addu	$t4,$v0,$s0
/*  f0fc268:	018b001a */ 	div	$zero,$t4,$t3
/*  f0fc26c:	00006812 */ 	mflo	$t5
/*  f0fc270:	25aeffec */ 	addiu	$t6,$t5,-20
/*  f0fc274:	15600002 */ 	bnez	$t3,.L0f0fc280
/*  f0fc278:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc27c:	0007000d */ 	break	0x7
.L0f0fc280:
/*  f0fc280:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fc284:	15610004 */ 	bne	$t3,$at,.L0f0fc298
/*  f0fc288:	3c018000 */ 	lui	$at,0x8000
/*  f0fc28c:	15810002 */ 	bne	$t4,$at,.L0f0fc298
/*  f0fc290:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc294:	0006000d */ 	break	0x6
.L0f0fc298:
/*  f0fc298:	afae00e8 */ 	sw	$t6,0xe8($sp)
/*  f0fc29c:	0c002f44 */ 	jal	func0000bd10
/*  f0fc2a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc2a4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fc2a8:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0fc2ac:	0c002f26 */ 	jal	func0000bc98
/*  f0fc2b0:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0fc2b4:	0050c021 */ 	addu	$t8,$v0,$s0
/*  f0fc2b8:	2719fffc */ 	addiu	$t9,$t8,-4
/*  f0fc2bc:	afb900e4 */ 	sw	$t9,0xe4($sp)
/*  f0fc2c0:	0fc54d8a */ 	jal	func0f153628
/*  f0fc2c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc2c8:	3c13800a */ 	lui	$s3,0x800a
/*  f0fc2cc:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0fc2d0:	26739fc4 */ 	addiu	$s3,$s3,-24636
/*  f0fc2d4:	00009025 */ 	or	$s2,$zero,$zero
/*  f0fc2d8:	27b400b8 */ 	addiu	$s4,$sp,0xb8
/*  f0fc2dc:	8ec20490 */ 	lw	$v0,0x490($s6)
.L0f0fc2e0:
/*  f0fc2e0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fc2e4:	02d25021 */ 	addu	$t2,$s6,$s2
/*  f0fc2e8:	54410013 */ 	bnel	$v0,$at,.L0f0fc338
/*  f0fc2ec:	8eeb0004 */ 	lw	$t3,0x4($s7)
/*  f0fc2f0:	814c0494 */ 	lb	$t4,0x494($t2)
/*  f0fc2f4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0fc2f8:	5180000f */ 	beqzl	$t4,.L0f0fc338
/*  f0fc2fc:	8eeb0004 */ 	lw	$t3,0x4($s7)
/*  f0fc300:	0fc5b9f1 */ 	jal	langGet
/*  f0fc304:	240451e2 */ 	addiu	$a0,$zero,0x51e2
/*  f0fc308:	00408825 */ 	or	$s1,$v0,$zero
/*  f0fc30c:	0fc5b9f1 */ 	jal	langGet
/*  f0fc310:	240459cd */ 	addiu	$a0,$zero,0x59cd
/*  f0fc314:	3c057f1b */ 	lui	$a1,%hi(var7f1b2794)
/*  f0fc318:	24a52794 */ 	addiu	$a1,$a1,%lo(var7f1b2794)
/*  f0fc31c:	02802025 */ 	or	$a0,$s4,$zero
/*  f0fc320:	02203025 */ 	or	$a2,$s1,$zero
/*  f0fc324:	0c004dad */ 	jal	sprintf
/*  f0fc328:	00403825 */ 	or	$a3,$v0,$zero
/*  f0fc32c:	10000023 */ 	beqz	$zero,.L0f0fc3bc
/*  f0fc330:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc334:	8eeb0004 */ 	lw	$t3,0x4($s7)
.L0f0fc338:
/*  f0fc338:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0fc33c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0fc340:	15610013 */ 	bne	$t3,$at,.L0f0fc390
/*  f0fc344:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fc348:	1441000d */ 	bne	$v0,$at,.L0f0fc380
/*  f0fc34c:	3c108007 */ 	lui	$s0,0x8007
/*  f0fc350:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0fc354:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0fc358:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0fc35c:	804d0494 */ 	lb	$t5,0x494($v0)
.L0f0fc360:
/*  f0fc360:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fc364:	11a00002 */ 	beqz	$t5,.L0f0fc370
/*  f0fc368:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc36c:	00008025 */ 	or	$s0,$zero,$zero
.L0f0fc370:
/*  f0fc370:	5453fffb */ 	bnel	$v0,$s3,.L0f0fc360
/*  f0fc374:	804d0494 */ 	lb	$t5,0x494($v0)
/*  f0fc378:	10000005 */ 	beqz	$zero,.L0f0fc390
/*  f0fc37c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fc380:
/*  f0fc380:	8e1014d8 */ 	lw	$s0,0x14d8($s0)
/*  f0fc384:	2e0e0002 */ 	sltiu	$t6,$s0,0x2
/*  f0fc388:	10000001 */ 	beqz	$zero,.L0f0fc390
/*  f0fc38c:	01c08025 */ 	or	$s0,$t6,$zero
.L0f0fc390:
/*  f0fc390:	0fc5b9f1 */ 	jal	langGet
/*  f0fc394:	240451e2 */ 	addiu	$a0,$zero,0x51e2
/*  f0fc398:	00408825 */ 	or	$s1,$v0,$zero
/*  f0fc39c:	0fc5b9f1 */ 	jal	langGet
/*  f0fc3a0:	240451e3 */ 	addiu	$a0,$zero,0x51e3
/*  f0fc3a4:	3c057f1b */ 	lui	$a1,%hi(var7f1b279c)
/*  f0fc3a8:	24a5279c */ 	addiu	$a1,$a1,%lo(var7f1b279c)
/*  f0fc3ac:	02802025 */ 	or	$a0,$s4,$zero
/*  f0fc3b0:	02203025 */ 	or	$a2,$s1,$zero
/*  f0fc3b4:	0c004dad */ 	jal	sprintf
/*  f0fc3b8:	00403825 */ 	or	$a3,$v0,$zero
.L0f0fc3bc:
/*  f0fc3bc:	120000cc */ 	beqz	$s0,.L0f0fc6f0
/*  f0fc3c0:	27a400e0 */ 	addiu	$a0,$sp,0xe0
/*  f0fc3c4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0fc3c8:	8deffb0c */ 	lw	$t7,-0x4f4($t7)
/*  f0fc3cc:	3c078008 */ 	lui	$a3,0x8008
/*  f0fc3d0:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f0fc3d4:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f0fc3d8:	02803025 */ 	or	$a2,$s4,$zero
/*  f0fc3dc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0fc3e0:	02f28821 */ 	addu	$s1,$s7,$s2
/*  f0fc3e4:	0fc55cbe */ 	jal	func0f1572f8
/*  f0fc3e8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0fc3ec:	0c005013 */ 	jal	func0001404c
/*  f0fc3f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc3f4:	3c19800b */ 	lui	$t9,0x800b
/*  f0fc3f8:	9739cb9e */ 	lhu	$t9,-0x3462($t9)
/*  f0fc3fc:	0040c027 */ 	nor	$t8,$v0,$zero
/*  f0fc400:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0fc404:	024c5804 */ 	sllv	$t3,$t4,$s2
/*  f0fc408:	03195025 */ 	or	$t2,$t8,$t9
/*  f0fc40c:	014b6824 */ 	and	$t5,$t2,$t3
/*  f0fc410:	55a00014 */ 	bnezl	$t5,.L0f0fc464
/*  f0fc414:	8ec30000 */ 	lw	$v1,0x0($s6)
/*  f0fc418:	8ec30000 */ 	lw	$v1,0x0($s6)
/*  f0fc41c:	92220017 */ 	lbu	$v0,0x17($s1)
/*  f0fc420:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f0fc424:	00037080 */ 	sll	$t6,$v1,0x2
/*  f0fc428:	284100ff */ 	slti	$at,$v0,0xff
/*  f0fc42c:	10200019 */ 	beqz	$at,.L0f0fc494
/*  f0fc430:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f0fc434:	01e2c023 */ 	subu	$t8,$t7,$v0
/*  f0fc438:	01d8082a */ 	slt	$at,$t6,$t8
/*  f0fc43c:	10200005 */ 	beqz	$at,.L0f0fc454
/*  f0fc440:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f0fc444:	004ec821 */ 	addu	$t9,$v0,$t6
/*  f0fc448:	a2390017 */ 	sb	$t9,0x17($s1)
/*  f0fc44c:	10000011 */ 	beqz	$zero,.L0f0fc494
/*  f0fc450:	332200ff */ 	andi	$v0,$t9,0xff
.L0f0fc454:
/*  f0fc454:	a22c0017 */ 	sb	$t4,0x17($s1)
/*  f0fc458:	1000000e */ 	beqz	$zero,.L0f0fc494
/*  f0fc45c:	318200ff */ 	andi	$v0,$t4,0xff
/*  f0fc460:	8ec30000 */ 	lw	$v1,0x0($s6)
.L0f0fc464:
/*  f0fc464:	92220017 */ 	lbu	$v0,0x17($s1)
/*  f0fc468:	000350c0 */ 	sll	$t2,$v1,0x3
/*  f0fc46c:	18400009 */ 	blez	$v0,.L0f0fc494
/*  f0fc470:	01435021 */ 	addu	$t2,$t2,$v1
/*  f0fc474:	0142082a */ 	slt	$at,$t2,$v0
/*  f0fc478:	10200004 */ 	beqz	$at,.L0f0fc48c
/*  f0fc47c:	004a5823 */ 	subu	$t3,$v0,$t2
/*  f0fc480:	a22b0017 */ 	sb	$t3,0x17($s1)
/*  f0fc484:	10000003 */ 	beqz	$zero,.L0f0fc494
/*  f0fc488:	316200ff */ 	andi	$v0,$t3,0xff
.L0f0fc48c:
/*  f0fc48c:	a2200017 */ 	sb	$zero,0x17($s1)
/*  f0fc490:	300200ff */ 	andi	$v0,$zero,0xff
.L0f0fc494:
/*  f0fc494:	18400096 */ 	blez	$v0,.L0f0fc6f0
/*  f0fc498:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0fc49c:	44816000 */ 	mtc1	$at,$f12
/*  f0fc4a0:	0fc01ac2 */ 	jal	func0f006b08
/*  f0fc4a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc4a8:	3c01437f */ 	lui	$at,0x437f
/*  f0fc4ac:	44819000 */ 	mtc1	$at,$f18
/*  f0fc4b0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0fc4b4:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fc4b8:	46120402 */ 	mul.s	$f16,$f0,$f18
/*  f0fc4bc:	240451e2 */ 	addiu	$a0,$zero,0x51e2
/*  f0fc4c0:	444df800 */ 	cfc1	$t5,$31
/*  f0fc4c4:	44cef800 */ 	ctc1	$t6,$31
/*  f0fc4c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc4cc:	460081a4 */ 	cvt.w.s	$f6,$f16
/*  f0fc4d0:	444ef800 */ 	cfc1	$t6,$31
/*  f0fc4d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc4d8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0fc4dc:	51c00013 */ 	beqzl	$t6,.L0f0fc52c
/*  f0fc4e0:	440e3000 */ 	mfc1	$t6,$f6
/*  f0fc4e4:	44813000 */ 	mtc1	$at,$f6
/*  f0fc4e8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0fc4ec:	46068181 */ 	sub.s	$f6,$f16,$f6
/*  f0fc4f0:	44cef800 */ 	ctc1	$t6,$31
/*  f0fc4f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc4f8:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0fc4fc:	444ef800 */ 	cfc1	$t6,$31
/*  f0fc500:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc504:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0fc508:	15c00005 */ 	bnez	$t6,.L0f0fc520
/*  f0fc50c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc510:	440e3000 */ 	mfc1	$t6,$f6
/*  f0fc514:	3c018000 */ 	lui	$at,0x8000
/*  f0fc518:	10000007 */ 	beqz	$zero,.L0f0fc538
/*  f0fc51c:	01c17025 */ 	or	$t6,$t6,$at
.L0f0fc520:
/*  f0fc520:	10000005 */ 	beqz	$zero,.L0f0fc538
/*  f0fc524:	240effff */ 	addiu	$t6,$zero,-1
/*  f0fc528:	440e3000 */ 	mfc1	$t6,$f6
.L0f0fc52c:
/*  f0fc52c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc530:	05c0fffb */ 	bltz	$t6,.L0f0fc520
/*  f0fc534:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fc538:
/*  f0fc538:	44cdf800 */ 	ctc1	$t5,$31
/*  f0fc53c:	0fc5b9f1 */ 	jal	langGet
/*  f0fc540:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f0fc544:	02802025 */ 	or	$a0,$s4,$zero
/*  f0fc548:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fc54c:	0c004dad */ 	jal	sprintf
/*  f0fc550:	26460001 */ 	addiu	$a2,$s2,0x1
/*  f0fc554:	2a410002 */ 	slti	$at,$s2,0x2
/*  f0fc558:	10200005 */ 	beqz	$at,.L0f0fc570
/*  f0fc55c:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f0fc560:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f0fc564:	25f80002 */ 	addiu	$t8,$t7,0x2
/*  f0fc568:	10000003 */ 	beqz	$zero,.L0f0fc578
/*  f0fc56c:	afb800a8 */ 	sw	$t8,0xa8($sp)
.L0f0fc570:
/*  f0fc570:	272cfff7 */ 	addiu	$t4,$t9,-9
/*  f0fc574:	afac00a8 */ 	sw	$t4,0xa8($sp)
.L0f0fc578:
/*  f0fc578:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fc57c:	12410004 */ 	beq	$s2,$at,.L0f0fc590
/*  f0fc580:	8faa00e8 */ 	lw	$t2,0xe8($sp)
/*  f0fc584:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fc588:	16410006 */ 	bne	$s2,$at,.L0f0fc5a4
/*  f0fc58c:	8faf00f0 */ 	lw	$t7,0xf0($sp)
.L0f0fc590:
/*  f0fc590:	8fab00dc */ 	lw	$t3,0xdc($sp)
/*  f0fc594:	014b6823 */ 	subu	$t5,$t2,$t3
/*  f0fc598:	25aefffe */ 	addiu	$t6,$t5,-2
/*  f0fc59c:	10000003 */ 	beqz	$zero,.L0f0fc5ac
/*  f0fc5a0:	afae00ac */ 	sw	$t6,0xac($sp)
.L0f0fc5a4:
/*  f0fc5a4:	25f80002 */ 	addiu	$t8,$t7,0x2
/*  f0fc5a8:	afb800ac */ 	sw	$t8,0xac($sp)
.L0f0fc5ac:
/*  f0fc5ac:	0c002f02 */ 	jal	func0000bc08
/*  f0fc5b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc5b4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fc5b8:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0fc5bc:	0c002f06 */ 	jal	func0000bc18
/*  f0fc5c0:	03208025 */ 	or	$s0,$t9,$zero
/*  f0fc5c4:	922b0017 */ 	lbu	$t3,0x17($s1)
/*  f0fc5c8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0fc5cc:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0fc5d0:	3c015070 */ 	lui	$at,0x5070
/*  f0fc5d4:	8d4afb0c */ 	lw	$t2,-0x4f4($t2)
/*  f0fc5d8:	8d8cfb10 */ 	lw	$t4,-0x4f0($t4)
/*  f0fc5dc:	3421ff00 */ 	ori	$at,$at,0xff00
/*  f0fc5e0:	01616825 */ 	or	$t5,$t3,$at
/*  f0fc5e4:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0fc5e8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc5ec:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f0fc5f0:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f0fc5f4:	02803825 */ 	or	$a3,$s4,$zero
/*  f0fc5f8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0fc5fc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0fc600:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0fc604:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0fc608:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0fc60c:	0fc5580f */ 	jal	func0f15603c
/*  f0fc610:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0fc614:	8ece0490 */ 	lw	$t6,0x490($s6)
/*  f0fc618:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fc61c:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0fc620:	15c1000f */ 	bne	$t6,$at,.L0f0fc660
/*  f0fc624:	02d27821 */ 	addu	$t7,$s6,$s2
/*  f0fc628:	81f80494 */ 	lb	$t8,0x494($t7)
/*  f0fc62c:	1300000c */ 	beqz	$t8,.L0f0fc660
/*  f0fc630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc634:	0fc5b9f1 */ 	jal	langGet
/*  f0fc638:	240459cd */ 	addiu	$a0,$zero,0x59cd
/*  f0fc63c:	02802025 */ 	or	$a0,$s4,$zero
/*  f0fc640:	0c004c4c */ 	jal	strcpy
/*  f0fc644:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fc648:	92230017 */ 	lbu	$v1,0x17($s1)
/*  f0fc64c:	3c01d000 */ 	lui	$at,0xd000
/*  f0fc650:	342120ff */ 	ori	$at,$at,0x20ff
/*  f0fc654:	0061c825 */ 	or	$t9,$v1,$at
/*  f0fc658:	1000000d */ 	beqz	$zero,.L0f0fc690
/*  f0fc65c:	03201825 */ 	or	$v1,$t9,$zero
.L0f0fc660:
/*  f0fc660:	0fc5b9f1 */ 	jal	langGet
/*  f0fc664:	240451e3 */ 	addiu	$a0,$zero,0x51e3
/*  f0fc668:	02802025 */ 	or	$a0,$s4,$zero
/*  f0fc66c:	0c004c4c */ 	jal	strcpy
/*  f0fc670:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fc674:	3c0400ff */ 	lui	$a0,0xff
/*  f0fc678:	3484ff00 */ 	ori	$a0,$a0,0xff00
/*  f0fc67c:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f0fc680:	0fc01a40 */ 	jal	func0f006900
/*  f0fc684:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*  f0fc688:	922c0017 */ 	lbu	$t4,0x17($s1)
/*  f0fc68c:	01821825 */ 	or	$v1,$t4,$v0
.L0f0fc690:
/*  f0fc690:	0c002f02 */ 	jal	func0000bc08
/*  f0fc694:	afa300a4 */ 	sw	$v1,0xa4($sp)
/*  f0fc698:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fc69c:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0fc6a0:	0c002f06 */ 	jal	func0000bc18
/*  f0fc6a4:	01408025 */ 	or	$s0,$t2,$zero
/*  f0fc6a8:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0fc6ac:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0fc6b0:	8dadfb0c */ 	lw	$t5,-0x4f4($t5)
/*  f0fc6b4:	8d6bfb10 */ 	lw	$t3,-0x4f0($t3)
/*  f0fc6b8:	8fa300a4 */ 	lw	$v1,0xa4($sp)
/*  f0fc6bc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc6c0:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f0fc6c4:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f0fc6c8:	02803825 */ 	or	$a3,$s4,$zero
/*  f0fc6cc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0fc6d0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0fc6d4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0fc6d8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0fc6dc:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0fc6e0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0fc6e4:	0fc5580f */ 	jal	func0f15603c
/*  f0fc6e8:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0fc6ec:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc6f0:
/*  f0fc6f0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0fc6f4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fc6f8:	5641fef9 */ 	bnel	$s2,$at,.L0f0fc2e0
/*  f0fc6fc:	8ec20490 */ 	lw	$v0,0x490($s6)
/*  f0fc700:	0fc54de0 */ 	jal	func0f153780
/*  f0fc704:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc708:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0fc70c:	02a01025 */ 	or	$v0,$s5,$zero
.L0f0fc710:
/*  f0fc710:	3c0eb700 */ 	lui	$t6,0xb700
/*  f0fc714:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fc718:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0fc71c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0fc720:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f0fc724:	82f8001b */ 	lb	$t8,0x1b($s7)
.L0f0fc728:
/*  f0fc728:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fc72c:	130100a1 */ 	beq	$t8,$at,.L0f0fc9b4
/*  f0fc730:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc734:	0c002f40 */ 	jal	func0000bd00
/*  f0fc738:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc73c:	3c198008 */ 	lui	$t9,0x8008
/*  f0fc740:	8f39fac0 */ 	lw	$t9,-0x540($t9)
/*  f0fc744:	0059001a */ 	div	$zero,$v0,$t9
/*  f0fc748:	00006012 */ 	mflo	$t4
/*  f0fc74c:	afac0098 */ 	sw	$t4,0x98($sp)
/*  f0fc750:	17200002 */ 	bnez	$t9,.L0f0fc75c
/*  f0fc754:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc758:	0007000d */ 	break	0x7
.L0f0fc75c:
/*  f0fc75c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fc760:	17210004 */ 	bne	$t9,$at,.L0f0fc774
/*  f0fc764:	3c018000 */ 	lui	$at,0x8000
/*  f0fc768:	14410002 */ 	bne	$v0,$at,.L0f0fc774
/*  f0fc76c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc770:	0006000d */ 	break	0x6
.L0f0fc774:
/*  f0fc774:	0c002f44 */ 	jal	func0000bd10
/*  f0fc778:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc77c:	0c002f40 */ 	jal	func0000bd00
/*  f0fc780:	afa20094 */ 	sw	$v0,0x94($sp)
/*  f0fc784:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fc788:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0fc78c:	0c002f22 */ 	jal	func0000bc88
/*  f0fc790:	01408025 */ 	or	$s0,$t2,$zero
/*  f0fc794:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0fc798:	8dadfac0 */ 	lw	$t5,-0x540($t5)
/*  f0fc79c:	00505821 */ 	addu	$t3,$v0,$s0
/*  f0fc7a0:	016d001a */ 	div	$zero,$t3,$t5
/*  f0fc7a4:	0000a012 */ 	mflo	$s4
/*  f0fc7a8:	15a00002 */ 	bnez	$t5,.L0f0fc7b4
/*  f0fc7ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc7b0:	0007000d */ 	break	0x7
.L0f0fc7b4:
/*  f0fc7b4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fc7b8:	15a10004 */ 	bne	$t5,$at,.L0f0fc7cc
/*  f0fc7bc:	3c018000 */ 	lui	$at,0x8000
/*  f0fc7c0:	15610002 */ 	bne	$t3,$at,.L0f0fc7cc
/*  f0fc7c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc7c8:	0006000d */ 	break	0x6
.L0f0fc7cc:
/*  f0fc7cc:	0c002f44 */ 	jal	func0000bd10
/*  f0fc7d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc7d4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fc7d8:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0fc7dc:	0c002f26 */ 	jal	func0000bc98
/*  f0fc7e0:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0fc7e4:	8ec7006c */ 	lw	$a3,0x6c($s6)
/*  f0fc7e8:	00504821 */ 	addu	$t1,$v0,$s0
/*  f0fc7ec:	00009025 */ 	or	$s2,$zero,$zero
/*  f0fc7f0:	10e00003 */ 	beqz	$a3,.L0f0fc800
/*  f0fc7f4:	00009825 */ 	or	$s3,$zero,$zero
/*  f0fc7f8:	10000002 */ 	beqz	$zero,.L0f0fc804
/*  f0fc7fc:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0fc800:
/*  f0fc800:	00004025 */ 	or	$t0,$zero,$zero
.L0f0fc804:
/*  f0fc804:	8ec40068 */ 	lw	$a0,0x68($s6)
/*  f0fc808:	50800004 */ 	beqzl	$a0,.L0f0fc81c
/*  f0fc80c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fc810:	10000002 */ 	beqz	$zero,.L0f0fc81c
/*  f0fc814:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0fc818:	00001825 */ 	or	$v1,$zero,$zero
.L0f0fc81c:
/*  f0fc81c:	8ec50064 */ 	lw	$a1,0x64($s6)
/*  f0fc820:	50a00004 */ 	beqzl	$a1,.L0f0fc834
/*  f0fc824:	00008825 */ 	or	$s1,$zero,$zero
/*  f0fc828:	10000002 */ 	beqz	$zero,.L0f0fc834
/*  f0fc82c:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f0fc830:	00008825 */ 	or	$s1,$zero,$zero
.L0f0fc834:
/*  f0fc834:	8ec60070 */ 	lw	$a2,0x70($s6)
/*  f0fc838:	50c00004 */ 	beqzl	$a2,.L0f0fc84c
/*  f0fc83c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fc840:	10000002 */ 	beqz	$zero,.L0f0fc84c
/*  f0fc844:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0fc848:	00001025 */ 	or	$v0,$zero,$zero
.L0f0fc84c:
/*  f0fc84c:	00517821 */ 	addu	$t7,$v0,$s1
/*  f0fc850:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f0fc854:	0308c821 */ 	addu	$t9,$t8,$t0
/*  f0fc858:	2b210003 */ 	slti	$at,$t9,0x3
/*  f0fc85c:	1420000a */ 	bnez	$at,.L0f0fc888
/*  f0fc860:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fc864:	8ec2028c */ 	lw	$v0,0x28c($s6)
/*  f0fc868:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fc86c:	10410003 */ 	beq	$v0,$at,.L0f0fc87c
/*  f0fc870:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fc874:	54410004 */ 	bnel	$v0,$at,.L0f0fc888
/*  f0fc878:	2412000f */ 	addiu	$s2,$zero,0xf
.L0f0fc87c:
/*  f0fc87c:	10000002 */ 	beqz	$zero,.L0f0fc888
/*  f0fc880:	2413000f */ 	addiu	$s3,$zero,0xf
/*  f0fc884:	2412000f */ 	addiu	$s2,$zero,0xf
.L0f0fc888:
/*  f0fc888:	10e00003 */ 	beqz	$a3,.L0f0fc898
/*  f0fc88c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fc890:	10000002 */ 	beqz	$zero,.L0f0fc89c
/*  f0fc894:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0fc898:
/*  f0fc898:	00004025 */ 	or	$t0,$zero,$zero
.L0f0fc89c:
/*  f0fc89c:	10800003 */ 	beqz	$a0,.L0f0fc8ac
/*  f0fc8a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fc8a4:	10000001 */ 	beqz	$zero,.L0f0fc8ac
/*  f0fc8a8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fc8ac:
/*  f0fc8ac:	10a00003 */ 	beqz	$a1,.L0f0fc8bc
/*  f0fc8b0:	00008825 */ 	or	$s1,$zero,$zero
/*  f0fc8b4:	10000001 */ 	beqz	$zero,.L0f0fc8bc
/*  f0fc8b8:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f0fc8bc:
/*  f0fc8bc:	10c00003 */ 	beqz	$a2,.L0f0fc8cc
/*  f0fc8c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fc8c4:	10000001 */ 	beqz	$zero,.L0f0fc8cc
/*  f0fc8c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0fc8cc:
/*  f0fc8cc:	00516021 */ 	addu	$t4,$v0,$s1
/*  f0fc8d0:	01835021 */ 	addu	$t2,$t4,$v1
/*  f0fc8d4:	01485821 */ 	addu	$t3,$t2,$t0
/*  f0fc8d8:	55610013 */ 	bnel	$t3,$at,.L0f0fc928
/*  f0fc8dc:	8ecf006c */ 	lw	$t7,0x6c($s6)
/*  f0fc8e0:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0fc8e4:	afa9008c */ 	sw	$t1,0x8c($sp)
/*  f0fc8e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fc8ec:	10410006 */ 	beq	$v0,$at,.L0f0fc908
/*  f0fc8f0:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f0fc8f4:	3c0d8009 */ 	lui	$t5,0x8009
/*  f0fc8f8:	91ad0af0 */ 	lbu	$t5,0xaf0($t5)
/*  f0fc8fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fc900:	55a10009 */ 	bnel	$t5,$at,.L0f0fc928
/*  f0fc904:	8ecf006c */ 	lw	$t7,0x6c($s6)
.L0f0fc908:
/*  f0fc908:	8ece028c */ 	lw	$t6,0x28c($s6)
/*  f0fc90c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fc910:	55c10004 */ 	bnel	$t6,$at,.L0f0fc924
/*  f0fc914:	2412000f */ 	addiu	$s2,$zero,0xf
/*  f0fc918:	10000002 */ 	beqz	$zero,.L0f0fc924
/*  f0fc91c:	2413000f */ 	addiu	$s3,$zero,0xf
/*  f0fc920:	2412000f */ 	addiu	$s2,$zero,0xf
.L0f0fc924:
/*  f0fc924:	8ecf006c */ 	lw	$t7,0x6c($s6)
.L0f0fc928:
/*  f0fc928:	8ec40068 */ 	lw	$a0,0x68($s6)
/*  f0fc92c:	8ec50064 */ 	lw	$a1,0x64($s6)
/*  f0fc930:	11e00003 */ 	beqz	$t7,.L0f0fc940
/*  f0fc934:	8ec60070 */ 	lw	$a2,0x70($s6)
/*  f0fc938:	10000002 */ 	beqz	$zero,.L0f0fc944
/*  f0fc93c:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0fc940:
/*  f0fc940:	00004025 */ 	or	$t0,$zero,$zero
.L0f0fc944:
/*  f0fc944:	10800003 */ 	beqz	$a0,.L0f0fc954
/*  f0fc948:	02803825 */ 	or	$a3,$s4,$zero
/*  f0fc94c:	10000002 */ 	beqz	$zero,.L0f0fc958
/*  f0fc950:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fc954:
/*  f0fc954:	00001825 */ 	or	$v1,$zero,$zero
.L0f0fc958:
/*  f0fc958:	10a00003 */ 	beqz	$a1,.L0f0fc968
/*  f0fc95c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc960:	10000002 */ 	beqz	$zero,.L0f0fc96c
/*  f0fc964:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f0fc968:
/*  f0fc968:	00008825 */ 	or	$s1,$zero,$zero
.L0f0fc96c:
/*  f0fc96c:	10c00003 */ 	beqz	$a2,.L0f0fc97c
/*  f0fc970:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f0fc974:	10000002 */ 	beqz	$zero,.L0f0fc980
/*  f0fc978:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0fc97c:
/*  f0fc97c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0fc980:
/*  f0fc980:	0051c021 */ 	addu	$t8,$v0,$s1
/*  f0fc984:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f0fc988:	82eb001b */ 	lb	$t3,0x1b($s7)
/*  f0fc98c:	03286021 */ 	addu	$t4,$t9,$t0
/*  f0fc990:	298a0002 */ 	slti	$t2,$t4,0x2
/*  f0fc994:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0fc998:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f0fc99c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0fc9a0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0fc9a4:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0fc9a8:	0fc3c33a */ 	jal	func0f0f0ce8
/*  f0fc9ac:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0fc9b0:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc9b4:
/*  f0fc9b4:	0fc35272 */ 	jal	func0f0d49c8
/*  f0fc9b8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc9bc:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f0fc9c0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0fc9c4:	3c018008 */ 	lui	$at,0x8008
/*  f0fc9c8:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0fc9cc:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0fc9d0:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f0fc9d4:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0fc9d8:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f0fc9dc:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f0fc9e0:	8fb6004c */ 	lw	$s6,0x4c($sp)
/*  f0fc9e4:	8fb70050 */ 	lw	$s7,0x50($sp)
/*  f0fc9e8:	ac2dfac0 */ 	sw	$t5,-0x540($at)
/*  f0fc9ec:	03e00008 */ 	jr	$ra
/*  f0fc9f0:	27bd0118 */ 	addiu	$sp,$sp,0x118
);

GLOBAL_ASM(
glabel func0f0fc9f4
/*  f0fc9f4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0fc9f8:	8dcefc00 */ 	lw	$t6,-0x400($t6)
/*  f0fc9fc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0fca00:	24010019 */ 	addiu	$at,$zero,0x19
/*  f0fca04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fca08:	15c10002 */ 	bne	$t6,$at,.L0f0fca14
/*  f0fca0c:	24040049 */ 	addiu	$a0,$zero,0x49
/*  f0fca10:	2404001b */ 	addiu	$a0,$zero,0x1b
.L0f0fca14:
/*  f0fca14:	3c02800a */ 	lui	$v0,0x800a
/*  f0fca18:	8c4219c4 */ 	lw	$v0,0x19c4($v0)
/*  f0fca1c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fca20:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0fca24:	14410010 */ 	bne	$v0,$at,.L0f0fca68
/*  f0fca28:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0fca2c:	8c6202a0 */ 	lw	$v0,0x2a0($v1)
/*  f0fca30:	8c4f00d8 */ 	lw	$t7,0xd8($v0)
/*  f0fca34:	15e00008 */ 	bnez	$t7,.L0f0fca58
/*  f0fca38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fca3c:	8c58048c */ 	lw	$t8,0x48c($v0)
/*  f0fca40:	17000005 */ 	bnez	$t8,.L0f0fca58
/*  f0fca44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fca48:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f0fca4c:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f0fca50:	14400003 */ 	bnez	$v0,.L0f0fca60
/*  f0fca54:	8fa4001c */ 	lw	$a0,0x1c($sp)
.L0f0fca58:
/*  f0fca58:	10000058 */ 	beqz	$zero,.L0f0fcbbc
/*  f0fca5c:	24020047 */ 	addiu	$v0,$zero,0x47
.L0f0fca60:
/*  f0fca60:	10000056 */ 	beqz	$zero,.L0f0fcbbc
/*  f0fca64:	00801025 */ 	or	$v0,$a0,$zero
.L0f0fca68:
/*  f0fca68:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0fca6c:	1441002e */ 	bne	$v0,$at,.L0f0fcb28
/*  f0fca70:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0fca74:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0fca78:	8c790298 */ 	lw	$t9,0x298($v1)
/*  f0fca7c:	07220019 */ 	bltzl	$t9,.L0f0fcae4
/*  f0fca80:	8c6e029c */ 	lw	$t6,0x29c($v1)
/*  f0fca84:	8c6202a0 */ 	lw	$v0,0x2a0($v1)
/*  f0fca88:	8c4800d8 */ 	lw	$t0,0xd8($v0)
/*  f0fca8c:	51000006 */ 	beqzl	$t0,.L0f0fcaa8
/*  f0fca90:	8c4b048c */ 	lw	$t3,0x48c($v0)
/*  f0fca94:	8c6902a4 */ 	lw	$t1,0x2a4($v1)
/*  f0fca98:	8d2a00d8 */ 	lw	$t2,0xd8($t1)
/*  f0fca9c:	1540000c */ 	bnez	$t2,.L0f0fcad0
/*  f0fcaa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcaa4:	8c4b048c */ 	lw	$t3,0x48c($v0)
.L0f0fcaa8:
/*  f0fcaa8:	15600009 */ 	bnez	$t3,.L0f0fcad0
/*  f0fcaac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcab0:	8c6c02a4 */ 	lw	$t4,0x2a4($v1)
/*  f0fcab4:	8d8d048c */ 	lw	$t5,0x48c($t4)
/*  f0fcab8:	15a00005 */ 	bnez	$t5,.L0f0fcad0
/*  f0fcabc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcac0:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f0fcac4:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f0fcac8:	14400003 */ 	bnez	$v0,.L0f0fcad8
/*  f0fcacc:	8fa4001c */ 	lw	$a0,0x1c($sp)
.L0f0fcad0:
/*  f0fcad0:	1000003a */ 	beqz	$zero,.L0f0fcbbc
/*  f0fcad4:	24020047 */ 	addiu	$v0,$zero,0x47
.L0f0fcad8:
/*  f0fcad8:	10000038 */ 	beqz	$zero,.L0f0fcbbc
/*  f0fcadc:	00801025 */ 	or	$v0,$a0,$zero
/*  f0fcae0:	8c6e029c */ 	lw	$t6,0x29c($v1)
.L0f0fcae4:
/*  f0fcae4:	05c00010 */ 	bltz	$t6,.L0f0fcb28
/*  f0fcae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcaec:	8c6202a0 */ 	lw	$v0,0x2a0($v1)
/*  f0fcaf0:	8c4f00d8 */ 	lw	$t7,0xd8($v0)
/*  f0fcaf4:	15e00008 */ 	bnez	$t7,.L0f0fcb18
/*  f0fcaf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcafc:	8c58048c */ 	lw	$t8,0x48c($v0)
/*  f0fcb00:	17000005 */ 	bnez	$t8,.L0f0fcb18
/*  f0fcb04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcb08:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f0fcb0c:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f0fcb10:	14400003 */ 	bnez	$v0,.L0f0fcb20
/*  f0fcb14:	8fa4001c */ 	lw	$a0,0x1c($sp)
.L0f0fcb18:
/*  f0fcb18:	10000028 */ 	beqz	$zero,.L0f0fcbbc
/*  f0fcb1c:	24020047 */ 	addiu	$v0,$zero,0x47
.L0f0fcb20:
/*  f0fcb20:	10000026 */ 	beqz	$zero,.L0f0fcbbc
/*  f0fcb24:	00801025 */ 	or	$v0,$a0,$zero
.L0f0fcb28:
/*  f0fcb28:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0fcb2c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0fcb30:	14410003 */ 	bne	$v0,$at,.L0f0fcb40
/*  f0fcb34:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0fcb38:	10000020 */ 	beqz	$zero,.L0f0fcbbc
/*  f0fcb3c:	24020059 */ 	addiu	$v0,$zero,0x59
.L0f0fcb40:
/*  f0fcb40:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fcb44:	10410003 */ 	beq	$v0,$at,.L0f0fcb54
/*  f0fcb48:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0fcb4c:	54410004 */ 	bnel	$v0,$at,.L0f0fcb60
/*  f0fcb50:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0fcb54:
/*  f0fcb54:	10000019 */ 	beqz	$zero,.L0f0fcbbc
/*  f0fcb58:	24020048 */ 	addiu	$v0,$zero,0x48
/*  f0fcb5c:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0fcb60:
/*  f0fcb60:	54410004 */ 	bnel	$v0,$at,.L0f0fcb74
/*  f0fcb64:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0fcb68:	10000014 */ 	beqz	$zero,.L0f0fcbbc
/*  f0fcb6c:	24020067 */ 	addiu	$v0,$zero,0x67
/*  f0fcb70:	24010007 */ 	addiu	$at,$zero,0x7
.L0f0fcb74:
/*  f0fcb74:	54410004 */ 	bnel	$v0,$at,.L0f0fcb88
/*  f0fcb78:	8c790314 */ 	lw	$t9,0x314($v1)
/*  f0fcb7c:	1000000f */ 	beqz	$zero,.L0f0fcbbc
/*  f0fcb80:	2402001b */ 	addiu	$v0,$zero,0x1b
/*  f0fcb84:	8c790314 */ 	lw	$t9,0x314($v1)
.L0f0fcb88:
/*  f0fcb88:	53200004 */ 	beqzl	$t9,.L0f0fcb9c
/*  f0fcb8c:	8c6204b4 */ 	lw	$v0,0x4b4($v1)
/*  f0fcb90:	1000000a */ 	beqz	$zero,.L0f0fcbbc
/*  f0fcb94:	24020067 */ 	addiu	$v0,$zero,0x67
/*  f0fcb98:	8c6204b4 */ 	lw	$v0,0x4b4($v1)
.L0f0fcb9c:
/*  f0fcb9c:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0fcba0:	10410003 */ 	beq	$v0,$at,.L0f0fcbb0
/*  f0fcba4:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f0fcba8:	54410004 */ 	bnel	$v0,$at,.L0f0fcbbc
/*  f0fcbac:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f0fcbb0:
/*  f0fcbb0:	10000002 */ 	beqz	$zero,.L0f0fcbbc
/*  f0fcbb4:	24020059 */ 	addiu	$v0,$zero,0x59
/*  f0fcbb8:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f0fcbbc:
/*  f0fcbbc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fcbc0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0fcbc4:	03e00008 */ 	jr	$ra
/*  f0fcbc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcbcc:	3c0e8006 */ 	lui	$t6,0x8006
/*  f0fcbd0:	91ce2940 */ 	lbu	$t6,0x2940($t6)
/*  f0fcbd4:	3c0f800a */ 	lui	$t7,0x800a
/*  f0fcbd8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fcbdc:	15c00007 */ 	bnez	$t6,.L0f0fcbfc
/*  f0fcbe0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcbe4:	8defa474 */ 	lw	$t7,-0x5b8c($t7)
/*  f0fcbe8:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0fcbec:	15e10003 */ 	bne	$t7,$at,.L0f0fcbfc
/*  f0fcbf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcbf4:	03e00008 */ 	jr	$ra
/*  f0fcbf8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0fcbfc:
/*  f0fcbfc:	03e00008 */ 	jr	$ra
/*  f0fcc00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcc04:	03e00008 */ 	jr	$ra
/*  f0fcc08:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0f0fcc0c
/*  f0fcc0c:	3c03800a */ 	lui	$v1,%hi(var800a19c0)
/*  f0fcc10:	246319c0 */ 	addiu	$v1,$v1,%lo(var800a19c0)
/*  f0fcc14:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0fcc18:	55c00004 */ 	bnezl	$t6,.L0f0fcc2c
/*  f0fcc1c:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f0fcc20:	03e00008 */ 	jr	$ra
/*  f0fcc24:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fcc28:	8c620004 */ 	lw	$v0,0x4($v1)
.L0f0fcc2c:
/*  f0fcc2c:	03e00008 */ 	jr	$ra
/*  f0fcc30:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler000fcc34
/*  f0fcc34:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0fcc38:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0fcc3c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0fcc40:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0fcc44:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0fcc48:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0fcc4c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0fcc50:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0fcc54:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0fcc58:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0fcc5c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0fcc60:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0fcc64:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0fcc68:	1481002a */ 	bne	$a0,$at,.L0f0fcd14
/*  f0fcc6c:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0fcc70:	3c1e8007 */ 	lui	$s8,%hi(menudialog_damagedcontrollerpak)
/*  f0fcc74:	3c178007 */ 	lui	$s7,%hi(g_PakAttemptRepairMenuDialog)
/*  f0fcc78:	3c168007 */ 	lui	$s6,%hi(g_PakRepairFailedMenuDialog)
/*  f0fcc7c:	3c158007 */ 	lui	$s5,%hi(menudialog_pakremoved)
/*  f0fcc80:	3c148007 */ 	lui	$s4,%hi(g_PakRepairSuccessMenuDialog)
/*  f0fcc84:	3c128007 */ 	lui	$s2,%hi(g_MpPlayerNum)
/*  f0fcc88:	3c11800a */ 	lui	$s1,%hi(var8009e000)
/*  f0fcc8c:	2631e000 */ 	addiu	$s1,$s1,%lo(var8009e000)
/*  f0fcc90:	26521448 */ 	addiu	$s2,$s2,%lo(g_MpPlayerNum)
/*  f0fcc94:	269415b0 */ 	addiu	$s4,$s4,%lo(g_PakRepairSuccessMenuDialog)
/*  f0fcc98:	26b51548 */ 	addiu	$s5,$s5,%lo(menudialog_pakremoved)
/*  f0fcc9c:	26d61618 */ 	addiu	$s6,$s6,%lo(g_PakRepairFailedMenuDialog)
/*  f0fcca0:	26f716a8 */ 	addiu	$s7,$s7,%lo(g_PakAttemptRepairMenuDialog)
/*  f0fcca4:	27de176c */ 	addiu	$s8,$s8,%lo(menudialog_damagedcontrollerpak)
/*  f0fcca8:	24130e70 */ 	addiu	$s3,$zero,0xe70
/*  f0fccac:	8e4e0000 */ 	lw	$t6,0x0($s2)
.L0f0fccb0:
/*  f0fccb0:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0fccb4:	01d30019 */ 	multu	$t6,$s3
/*  f0fccb8:	00007812 */ 	mflo	$t7
/*  f0fccbc:	022fc021 */ 	addu	$t8,$s1,$t7
/*  f0fccc0:	8f0304f8 */ 	lw	$v1,0x4f8($t8)
/*  f0fccc4:	10600011 */ 	beqz	$v1,.L0f0fcd0c
/*  f0fccc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcccc:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f0fccd0:	1282000c */ 	beq	$s4,$v0,.L0f0fcd04
/*  f0fccd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fccd8:	12a2000a */ 	beq	$s5,$v0,.L0f0fcd04
/*  f0fccdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcce0:	12c20008 */ 	beq	$s6,$v0,.L0f0fcd04
/*  f0fcce4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcce8:	12e20006 */ 	beq	$s7,$v0,.L0f0fcd04
/*  f0fccec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fccf0:	13c20004 */ 	beq	$s8,$v0,.L0f0fcd04
/*  f0fccf4:	3c198007 */ 	lui	$t9,%hi(menudialog_fullcontrollerpak)
/*  f0fccf8:	27391810 */ 	addiu	$t9,$t9,%lo(menudialog_fullcontrollerpak)
/*  f0fccfc:	17220003 */ 	bne	$t9,$v0,.L0f0fcd0c
/*  f0fcd00:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fcd04:
/*  f0fcd04:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0fcd08:	00008025 */ 	or	$s0,$zero,$zero
.L0f0fcd0c:
/*  f0fcd0c:	5200ffe8 */ 	beqzl	$s0,.L0f0fccb0
/*  f0fcd10:	8e4e0000 */ 	lw	$t6,0x0($s2)
.L0f0fcd14:
/*  f0fcd14:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fcd18:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0fcd1c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0fcd20:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0fcd24:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0fcd28:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0fcd2c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0fcd30:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0fcd34:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0fcd38:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0fcd3c:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0fcd40:	03e00008 */ 	jr	$ra
/*  f0fcd44:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel menudialog000fcd48
/*  f0fcd48:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0fcd4c:	24010066 */ 	addiu	$at,$zero,0x66
/*  f0fcd50:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fcd54:	14810019 */ 	bne	$a0,$at,.L0f0fcdbc
/*  f0fcd58:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0fcd5c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0fcd60:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0fcd64:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f0fcd68:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f0fcd6c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0fcd70:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0fcd74:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0fcd78:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0fcd7c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0fcd80:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0fcd84:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0fcd88:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f0fcd8c:	8c4304f8 */ 	lw	$v1,0x4f8($v0)
/*  f0fcd90:	5060000b */ 	beqzl	$v1,.L0f0fcdc0
/*  f0fcd94:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fcd98:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0fcd9c:	54b90008 */ 	bnel	$a1,$t9,.L0f0fcdc0
/*  f0fcda0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fcda4:	0c00556d */ 	jal	func000155b4
/*  f0fcda8:	80440e6c */ 	lb	$a0,0xe6c($v0)
/*  f0fcdac:	14400003 */ 	bnez	$v0,.L0f0fcdbc
/*  f0fcdb0:	3c048007 */ 	lui	$a0,%hi(menudialog_pakremoved)
/*  f0fcdb4:	0fc3cdc1 */ 	jal	func0f0f3704
/*  f0fcdb8:	24841548 */ 	addiu	$a0,$a0,%lo(menudialog_pakremoved)
.L0f0fcdbc:
/*  f0fcdbc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fcdc0:
/*  f0fcdc0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0fcdc4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fcdc8:	03e00008 */ 	jr	$ra
/*  f0fcdcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcdd0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0fcdd4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0fcdd8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fcddc:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0fcde0:	14810004 */ 	bne	$a0,$at,.L0f0fcdf4
/*  f0fcde4:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0fcde8:	3c048007 */ 	lui	$a0,%hi(menudialog_damagedcontrollerpak)
/*  f0fcdec:	0fc3cdc1 */ 	jal	func0f0f3704
/*  f0fcdf0:	2484176c */ 	addiu	$a0,$a0,%lo(menudialog_damagedcontrollerpak)
.L0f0fcdf4:
/*  f0fcdf4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fcdf8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0fcdfc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fce00:	03e00008 */ 	jr	$ra
/*  f0fce04:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerRepairPak(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		if (pakRepair(g_MenuStack[g_MpPlayerNum].unk974)) {
			func0f0f3704(&g_PakRepairSuccessMenuDialog);
		} else {
			func0f0f3704(&g_PakRepairFailedMenuDialog);
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f0fce8c
/*  f0fce8c:	0005c0c0 */ 	sll	$t8,$a1,0x3
/*  f0fce90:	0305c023 */ 	subu	$t8,$t8,$a1
/*  f0fce94:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0fce98:	0305c021 */ 	addu	$t8,$t8,$a1
/*  f0fce9c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fcea0:	0305c023 */ 	subu	$t8,$t8,$a1
/*  f0fcea4:	3c19800a */ 	lui	$t9,%hi(var8009e000)
/*  f0fcea8:	2739e000 */ 	addiu	$t9,$t9,%lo(var8009e000)
/*  f0fceac:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0fceb0:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f0fceb4:	03191021 */ 	addu	$v0,$t8,$t9
/*  f0fceb8:	8c4904f8 */ 	lw	$t1,0x4f8($v0)
/*  f0fcebc:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f0fcec0:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0fcec4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0fcec8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fcecc:	00803825 */ 	or	$a3,$a0,$zero
/*  f0fced0:	ad050000 */ 	sw	$a1,0x0($t0)
/*  f0fced4:	a0460e6c */ 	sb	$a2,0xe6c($v0)
/*  f0fced8:	1520002f */ 	bnez	$t1,.L0f0fcf98
/*  f0fcedc:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0fcee0:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fcee4:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0fcee8:	8cca006c */ 	lw	$t2,0x6c($a2)
/*  f0fceec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fcef0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fcef4:	11400003 */ 	beqz	$t2,.L0f0fcf04
/*  f0fcef8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fcefc:	10000001 */ 	beqz	$zero,.L0f0fcf04
/*  f0fcf00:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0fcf04:
/*  f0fcf04:	8ccb0068 */ 	lw	$t3,0x68($a2)
/*  f0fcf08:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fcf0c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fcf10:	11600003 */ 	beqz	$t3,.L0f0fcf20
/*  f0fcf14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcf18:	10000001 */ 	beqz	$zero,.L0f0fcf20
/*  f0fcf1c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fcf20:
/*  f0fcf20:	8ccc0064 */ 	lw	$t4,0x64($a2)
/*  f0fcf24:	11800003 */ 	beqz	$t4,.L0f0fcf34
/*  f0fcf28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcf2c:	10000001 */ 	beqz	$zero,.L0f0fcf34
/*  f0fcf30:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0fcf34:
/*  f0fcf34:	8ccd0070 */ 	lw	$t5,0x70($a2)
/*  f0fcf38:	11a00003 */ 	beqz	$t5,.L0f0fcf48
/*  f0fcf3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcf40:	10000001 */ 	beqz	$zero,.L0f0fcf48
/*  f0fcf44:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0fcf48:
/*  f0fcf48:	00447021 */ 	addu	$t6,$v0,$a0
/*  f0fcf4c:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f0fcf50:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f0fcf54:	1701000b */ 	bne	$t8,$at,.L0f0fcf84
/*  f0fcf58:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0fcf5c:	0fc3e0cc */ 	jal	func0f0f8330
/*  f0fcf60:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0fcf64:	0fc5b350 */ 	jal	func0f16cd40
/*  f0fcf68:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0fcf6c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fcf70:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0fcf74:	8cc90284 */ 	lw	$t1,0x284($a2)
/*  f0fcf78:	24190003 */ 	addiu	$t9,$zero,0x3
/*  f0fcf7c:	10000008 */ 	beqz	$zero,.L0f0fcfa0
/*  f0fcf80:	ad391a24 */ 	sw	$t9,0x1a24($t1)
.L0f0fcf84:
/*  f0fcf84:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0fcf88:	0fc3e0cc */ 	jal	func0f0f8330
/*  f0fcf8c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0fcf90:	10000004 */ 	beqz	$zero,.L0f0fcfa4
/*  f0fcf94:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fcf98:
/*  f0fcf98:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0fcf9c:	00e02025 */ 	or	$a0,$a3,$zero
.L0f0fcfa0:
/*  f0fcfa0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fcfa4:
/*  f0fcfa4:	8faa001c */ 	lw	$t2,0x1c($sp)
/*  f0fcfa8:	3c018007 */ 	lui	$at,0x8007
/*  f0fcfac:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0fcfb0:	03e00008 */ 	jr	$ra
/*  f0fcfb4:	ac2a1448 */ 	sw	$t2,0x1448($at)
);

GLOBAL_ASM(
glabel func0f0fcfb8
/*  f0fcfb8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0fcfbc:	3c0e8007 */ 	lui	$t6,%hi(savelocations)
/*  f0fcfc0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fcfc4:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f0fcfc8:	25ce16c0 */ 	addiu	$t6,$t6,%lo(savelocations)
/*  f0fcfcc:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0fcfd0:	27a3001c */ 	addiu	$v1,$sp,0x1c
/*  f0fcfd4:	3c088007 */ 	lui	$t0,0x8007
/*  f0fcfd8:	ac610000 */ 	sw	$at,0x0($v1)
/*  f0fcfdc:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f0fcfe0:	3c02800a */ 	lui	$v0,0x800a
/*  f0fcfe4:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f0fcfe8:	95c10008 */ 	lhu	$at,0x8($t6)
/*  f0fcfec:	a4610008 */ 	sh	$at,0x8($v1)
/*  f0fcff0:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f0fcff4:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f0fcff8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0fcffc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0fd000:	01284821 */ 	addu	$t1,$t1,$t0
/*  f0fd004:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f0fd008:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0fd00c:	00094900 */ 	sll	$t1,$t1,0x4
/*  f0fd010:	00491021 */ 	addu	$v0,$v0,$t1
/*  f0fd014:	9042ee6c */ 	lbu	$v0,-0x1194($v0)
/*  f0fd018:	28410005 */ 	slti	$at,$v0,0x5
/*  f0fd01c:	10200006 */ 	beqz	$at,.L0f0fd038
/*  f0fd020:	00025040 */ 	sll	$t2,$v0,0x1
/*  f0fd024:	006a5821 */ 	addu	$t3,$v1,$t2
/*  f0fd028:	0fc5b9f1 */ 	jal	langGet
/*  f0fd02c:	95640000 */ 	lhu	$a0,0x0($t3)
/*  f0fd030:	10000003 */ 	beqz	$zero,.L0f0fd040
/*  f0fd034:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fd038:
/*  f0fd038:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fd03c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fd040:
/*  f0fd040:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0fd044:	03e00008 */ 	jr	$ra
/*  f0fd048:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerRetrySavePak(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		g_Vars.unk0004e4 &= 0xfff0;
		g_Vars.unk0004e4 |= 8;
		g_Vars.unk0004e4 |= 1 << ((u8)g_MenuStack[g_MpPlayerNum].unk974 + 8);
	}

	return 0;
}

s32 menuhandlerWarnRepairPak(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPushDialog(&g_PakAttemptRepairMenuDialog);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f0fd118
/*  f0fd118:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0fd11c:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0fd120:	8cee0318 */ 	lw	$t6,0x318($a3)
/*  f0fd124:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fd128:	3c0f800b */ 	lui	$t7,0x800b
/*  f0fd12c:	51c0000a */ 	beqzl	$t6,.L0f0fd158
/*  f0fd130:	8ce90298 */ 	lw	$t1,0x298($a3)
/*  f0fd134:	95efcb9e */ 	lhu	$t7,-0x3462($t7)
/*  f0fd138:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0fd13c:	0098c804 */ 	sllv	$t9,$t8,$a0
/*  f0fd140:	01f94024 */ 	and	$t0,$t7,$t9
/*  f0fd144:	11000029 */ 	beqz	$t0,.L0f0fd1ec
/*  f0fd148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd14c:	03e00008 */ 	jr	$ra
/*  f0fd150:	00801025 */ 	or	$v0,$a0,$zero
/*  f0fd154:	8ce90298 */ 	lw	$t1,0x298($a3)
.L0f0fd158:
/*  f0fd158:	05230005 */ 	bgezl	$t1,.L0f0fd170
/*  f0fd15c:	8ceb006c */ 	lw	$t3,0x6c($a3)
/*  f0fd160:	8cea029c */ 	lw	$t2,0x29c($a3)
/*  f0fd164:	05400021 */ 	bltz	$t2,.L0f0fd1ec
/*  f0fd168:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd16c:	8ceb006c */ 	lw	$t3,0x6c($a3)
.L0f0fd170:
/*  f0fd170:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fd174:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fd178:	11600003 */ 	beqz	$t3,.L0f0fd188
/*  f0fd17c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fd180:	10000001 */ 	beqz	$zero,.L0f0fd188
/*  f0fd184:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0fd188:
/*  f0fd188:	8cec0068 */ 	lw	$t4,0x68($a3)
/*  f0fd18c:	11800003 */ 	beqz	$t4,.L0f0fd19c
/*  f0fd190:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd194:	10000001 */ 	beqz	$zero,.L0f0fd19c
/*  f0fd198:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0fd19c:
/*  f0fd19c:	8ced0064 */ 	lw	$t5,0x64($a3)
/*  f0fd1a0:	11a00003 */ 	beqz	$t5,.L0f0fd1b0
/*  f0fd1a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd1a8:	10000001 */ 	beqz	$zero,.L0f0fd1b0
/*  f0fd1ac:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0fd1b0:
/*  f0fd1b0:	8cee0070 */ 	lw	$t6,0x70($a3)
/*  f0fd1b4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fd1b8:	11c00003 */ 	beqz	$t6,.L0f0fd1c8
/*  f0fd1bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd1c0:	10000001 */ 	beqz	$zero,.L0f0fd1c8
/*  f0fd1c4:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0fd1c8:
/*  f0fd1c8:	00e6c021 */ 	addu	$t8,$a3,$a2
/*  f0fd1cc:	03057821 */ 	addu	$t7,$t8,$a1
/*  f0fd1d0:	01e2c821 */ 	addu	$t9,$t7,$v0
/*  f0fd1d4:	2b210002 */ 	slti	$at,$t9,0x2
/*  f0fd1d8:	14200004 */ 	bnez	$at,.L0f0fd1ec
/*  f0fd1dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fd1e0:	14810002 */ 	bne	$a0,$at,.L0f0fd1ec
/*  f0fd1e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd1e8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fd1ec:
/*  f0fd1ec:	03e00008 */ 	jr	$ra
/*  f0fd1f0:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f0fd1f4
/*  f0fd1f4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0fd1f8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fd1fc:	0fc3f446 */ 	jal	func0f0fd118
/*  f0fd200:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0fd204:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0fd208:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0fd20c:	8c6e000c */ 	lw	$t6,0xc($v1)
/*  f0fd210:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fd214:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0fd218:	29c10014 */ 	slti	$at,$t6,0x14
/*  f0fd21c:	10200002 */ 	beqz	$at,.L0f0fd228
/*  f0fd220:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f0fd224:	00002825 */ 	or	$a1,$zero,$zero
.L0f0fd228:
/*  f0fd228:	91ef2940 */ 	lbu	$t7,0x2940($t7)
/*  f0fd22c:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f0fd230:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fd234:	15e00002 */ 	bnez	$t7,.L0f0fd240
/*  f0fd238:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f0fd23c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0fd240:
/*  f0fd240:	8c7804b4 */ 	lw	$t8,0x4b4($v1)
/*  f0fd244:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f0fd248:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fd24c:	17010002 */ 	bne	$t8,$at,.L0f0fd258
/*  f0fd250:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f0fd254:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0fd258:
/*  f0fd258:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fd25c:	3c04800a */ 	lui	$a0,0x800a
/*  f0fd260:	00992021 */ 	addu	$a0,$a0,$t9
/*  f0fd264:	8c84e4f8 */ 	lw	$a0,-0x1b08($a0)
/*  f0fd268:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fd26c:	3c02800a */ 	lui	$v0,%hi(var800a19c0)
/*  f0fd270:	1080001d */ 	beqz	$a0,.L0f0fd2e8
/*  f0fd274:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0fd278:	8c830000 */ 	lw	$v1,0x0($a0)
/*  f0fd27c:	3c088007 */ 	lui	$t0,%hi(menudialog_damagedcontrollerpak)
/*  f0fd280:	2508176c */ 	addiu	$t0,$t0,%lo(menudialog_damagedcontrollerpak)
/*  f0fd284:	11030016 */ 	beq	$t0,$v1,.L0f0fd2e0
/*  f0fd288:	3c098007 */ 	lui	$t1,%hi(menudialog_cannotreadgameboy)
/*  f0fd28c:	25291878 */ 	addiu	$t1,$t1,%lo(menudialog_cannotreadgameboy)
/*  f0fd290:	11230013 */ 	beq	$t1,$v1,.L0f0fd2e0
/*  f0fd294:	3c0a8007 */ 	lui	$t2,%hi(menudialog_datalost)
/*  f0fd298:	254a191c */ 	addiu	$t2,$t2,%lo(menudialog_datalost)
/*  f0fd29c:	11430010 */ 	beq	$t2,$v1,.L0f0fd2e0
/*  f0fd2a0:	3c0b8007 */ 	lui	$t3,%hi(menudialog_fullcontrollerpak)
/*  f0fd2a4:	256b1810 */ 	addiu	$t3,$t3,%lo(menudialog_fullcontrollerpak)
/*  f0fd2a8:	1163000d */ 	beq	$t3,$v1,.L0f0fd2e0
/*  f0fd2ac:	3c0c8007 */ 	lui	$t4,%hi(g_PakAttemptRepairMenuDialog)
/*  f0fd2b0:	258c16a8 */ 	addiu	$t4,$t4,%lo(g_PakAttemptRepairMenuDialog)
/*  f0fd2b4:	1183000a */ 	beq	$t4,$v1,.L0f0fd2e0
/*  f0fd2b8:	3c0d8007 */ 	lui	$t5,%hi(menudialog_pakremoved)
/*  f0fd2bc:	25ad1548 */ 	addiu	$t5,$t5,%lo(menudialog_pakremoved)
/*  f0fd2c0:	11a30007 */ 	beq	$t5,$v1,.L0f0fd2e0
/*  f0fd2c4:	3c0e8007 */ 	lui	$t6,%hi(g_PakRepairSuccessMenuDialog)
/*  f0fd2c8:	25ce15b0 */ 	addiu	$t6,$t6,%lo(g_PakRepairSuccessMenuDialog)
/*  f0fd2cc:	11c30004 */ 	beq	$t6,$v1,.L0f0fd2e0
/*  f0fd2d0:	3c0f8007 */ 	lui	$t7,%hi(g_PakRepairFailedMenuDialog)
/*  f0fd2d4:	25ef1618 */ 	addiu	$t7,$t7,%lo(g_PakRepairFailedMenuDialog)
/*  f0fd2d8:	15e3000f */ 	bne	$t7,$v1,.L0f0fd318
/*  f0fd2dc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fd2e0:
/*  f0fd2e0:	1000000d */ 	beqz	$zero,.L0f0fd318
/*  f0fd2e4:	00002825 */ 	or	$a1,$zero,$zero
.L0f0fd2e8:
/*  f0fd2e8:	244219c0 */ 	addiu	$v0,$v0,%lo(var800a19c0)
/*  f0fd2ec:	90580015 */ 	lbu	$t8,0x15($v0)
/*  f0fd2f0:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0fd2f4:	57010008 */ 	bnel	$t8,$at,.L0f0fd318
/*  f0fd2f8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fd2fc:	90590014 */ 	lbu	$t9,0x14($v0)
/*  f0fd300:	57200005 */ 	bnezl	$t9,.L0f0fd318
/*  f0fd304:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fd308:	904805d4 */ 	lbu	$t0,0x5d4($v0)
/*  f0fd30c:	11000002 */ 	beqz	$t0,.L0f0fd318
/*  f0fd310:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd314:	00002825 */ 	or	$a1,$zero,$zero
.L0f0fd318:
/*  f0fd318:	03e00008 */ 	jr	$ra
/*  f0fd31c:	00a01025 */ 	or	$v0,$a1,$zero
);

GLOBAL_ASM(
glabel func0f0fd320
/*  f0fd320:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0fd324:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0fd328:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f0fd32c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fd330:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0fd334:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f0fd338:	0fc3f446 */ 	jal	func0f0fd118
/*  f0fd33c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0fd340:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f0fd344:	3c018007 */ 	lui	$at,0x8007
/*  f0fd348:	ac221448 */ 	sw	$v0,0x1448($at)
/*  f0fd34c:	2de10005 */ 	sltiu	$at,$t7,0x5
/*  f0fd350:	1020004a */ 	beqz	$at,.L0f0fd47c
/*  f0fd354:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0fd358:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0fd35c:	3c017f1b */ 	lui	$at,%hi(var7f1b2b00)
/*  f0fd360:	002f0821 */ 	addu	$at,$at,$t7
/*  f0fd364:	8c2f2b00 */ 	lw	$t7,%lo(var7f1b2b00)($at)
/*  f0fd368:	01e00008 */ 	jr	$t7
/*  f0fd36c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd370:	3c048007 */ 	lui	$a0,%hi(menudialog_damagedcontrollerpak)
/*  f0fd374:	2484176c */ 	addiu	$a0,$a0,%lo(menudialog_damagedcontrollerpak)
/*  f0fd378:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0fd37c:	0fc3f3a3 */ 	jal	func0f0fce8c
/*  f0fd380:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0fd384:	1000003e */ 	beqz	$zero,.L0f0fd480
/*  f0fd388:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fd38c:	3c048007 */ 	lui	$a0,0x8007
/*  f0fd390:	8c841448 */ 	lw	$a0,0x1448($a0)
/*  f0fd394:	3c19800a */ 	lui	$t9,%hi(var8009e000)
/*  f0fd398:	2739e000 */ 	addiu	$t9,$t9,%lo(var8009e000)
/*  f0fd39c:	0004c0c0 */ 	sll	$t8,$a0,0x3
/*  f0fd3a0:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f0fd3a4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0fd3a8:	0304c021 */ 	addu	$t8,$t8,$a0
/*  f0fd3ac:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fd3b0:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f0fd3b4:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0fd3b8:	03194021 */ 	addu	$t0,$t8,$t9
/*  f0fd3bc:	850604f4 */ 	lh	$a2,0x4f4($t0)
/*  f0fd3c0:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fd3c4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fd3c8:	18c00018 */ 	blez	$a2,.L0f0fd42c
/*  f0fd3cc:	000448c0 */ 	sll	$t1,$a0,0x3
/*  f0fd3d0:	01244823 */ 	subu	$t1,$t1,$a0
/*  f0fd3d4:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0fd3d8:	01244821 */ 	addu	$t1,$t1,$a0
/*  f0fd3dc:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f0fd3e0:	00062880 */ 	sll	$a1,$a2,0x2
/*  f0fd3e4:	00a62823 */ 	subu	$a1,$a1,$a2
/*  f0fd3e8:	01244823 */ 	subu	$t1,$t1,$a0
/*  f0fd3ec:	00094900 */ 	sll	$t1,$t1,0x4
/*  f0fd3f0:	3c068007 */ 	lui	$a2,%hi(menudialog_controllerpakmenu)
/*  f0fd3f4:	24c64c38 */ 	addiu	$a2,$a2,%lo(menudialog_controllerpakmenu)
/*  f0fd3f8:	01391821 */ 	addu	$v1,$t1,$t9
/*  f0fd3fc:	000528c0 */ 	sll	$a1,$a1,0x3
.L0f0fd400:
/*  f0fd400:	8c640464 */ 	lw	$a0,0x464($v1)
/*  f0fd404:	24420018 */ 	addiu	$v0,$v0,0x18
/*  f0fd408:	0045082a */ 	slt	$at,$v0,$a1
/*  f0fd40c:	10800005 */ 	beqz	$a0,.L0f0fd424
/*  f0fd410:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd414:	8c8a0000 */ 	lw	$t2,0x0($a0)
/*  f0fd418:	14ca0002 */ 	bne	$a2,$t2,.L0f0fd424
/*  f0fd41c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd420:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0fd424:
/*  f0fd424:	1420fff6 */ 	bnez	$at,.L0f0fd400
/*  f0fd428:	24630018 */ 	addiu	$v1,$v1,0x18
.L0f0fd42c:
/*  f0fd42c:	14e00013 */ 	bnez	$a3,.L0f0fd47c
/*  f0fd430:	3c048007 */ 	lui	$a0,%hi(menudialog_fullcontrollerpak)
/*  f0fd434:	24841810 */ 	addiu	$a0,$a0,%lo(menudialog_fullcontrollerpak)
/*  f0fd438:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0fd43c:	0fc3f3a3 */ 	jal	func0f0fce8c
/*  f0fd440:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0fd444:	1000000e */ 	beqz	$zero,.L0f0fd480
/*  f0fd448:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fd44c:	3c048007 */ 	lui	$a0,%hi(menudialog_cannotreadgameboy)
/*  f0fd450:	24841878 */ 	addiu	$a0,$a0,%lo(menudialog_cannotreadgameboy)
/*  f0fd454:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0fd458:	0fc3f3a3 */ 	jal	func0f0fce8c
/*  f0fd45c:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0fd460:	10000007 */ 	beqz	$zero,.L0f0fd480
/*  f0fd464:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fd468:	3c048007 */ 	lui	$a0,%hi(menudialog_datalost)
/*  f0fd46c:	2484191c */ 	addiu	$a0,$a0,%lo(menudialog_datalost)
/*  f0fd470:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0fd474:	0fc3f3a3 */ 	jal	func0f0fce8c
/*  f0fd478:	8fa60020 */ 	lw	$a2,0x20($sp)
.L0f0fd47c:
/*  f0fd47c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fd480:
/*  f0fd480:	8fab001c */ 	lw	$t3,0x1c($sp)
/*  f0fd484:	3c018007 */ 	lui	$at,0x8007
/*  f0fd488:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0fd48c:	03e00008 */ 	jr	$ra
/*  f0fd490:	ac2b1448 */ 	sw	$t3,0x1448($at)
);

GLOBAL_ASM(
glabel func0f0fd494
/*  f0fd494:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0fd498:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0fd49c:	3c10800a */ 	lui	$s0,%hi(var800a19c0)
/*  f0fd4a0:	261019c0 */ 	addiu	$s0,$s0,%lo(var800a19c0)
/*  f0fd4a4:	920f05d5 */ 	lbu	$t7,0x5d5($s0)
/*  f0fd4a8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0fd4ac:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0fd4b0:	35f80010 */ 	ori	$t8,$t7,0x10
/*  f0fd4b4:	0fc2d5be */ 	jal	func0f0b56f8
/*  f0fd4b8:	a21805d5 */ 	sb	$t8,0x5d5($s0)
/*  f0fd4bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fd4c0:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f0fd4c4:	0c0056da */ 	jal	0x15b68
/*  f0fd4c8:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f0fd4cc:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f0fd4d0:	0fc2d341 */ 	jal	func0f0b4d04
/*  f0fd4d4:	27a50030 */ 	addiu	$a1,$sp,0x30
/*  f0fd4d8:	0c002f02 */ 	jal	func0000bc08
/*  f0fd4dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd4e0:	c7a40030 */ 	lwc1	$f4,0x30($sp)
/*  f0fd4e4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0fd4e8:	44083000 */ 	mfc1	$t0,$f6
/*  f0fd4ec:	04410003 */ 	bgez	$v0,.L0f0fd4fc
/*  f0fd4f0:	00024843 */ 	sra	$t1,$v0,0x1
/*  f0fd4f4:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0fd4f8:	00014843 */ 	sra	$t1,$at,0x1
.L0f0fd4fc:
/*  f0fd4fc:	01095023 */ 	subu	$t2,$t0,$t1
/*  f0fd500:	0c002f06 */ 	jal	func0000bc18
/*  f0fd504:	ae0a0670 */ 	sw	$t2,0x670($s0)
/*  f0fd508:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f0fd50c:	920f05d5 */ 	lbu	$t7,0x5d5($s0)
/*  f0fd510:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0fd514:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0fd518:	31f8fff7 */ 	andi	$t8,$t7,0xfff7
/*  f0fd51c:	a21805d5 */ 	sb	$t8,0x5d5($s0)
/*  f0fd520:	440c5000 */ 	mfc1	$t4,$f10
/*  f0fd524:	04410003 */ 	bgez	$v0,.L0f0fd534
/*  f0fd528:	00026843 */ 	sra	$t5,$v0,0x1
/*  f0fd52c:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0fd530:	00016843 */ 	sra	$t5,$at,0x1
.L0f0fd534:
/*  f0fd534:	018d7023 */ 	subu	$t6,$t4,$t5
/*  f0fd538:	ae0e0674 */ 	sw	$t6,0x674($s0)
/*  f0fd53c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0fd540:	03e00008 */ 	jr	$ra
/*  f0fd544:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f0fd548
/*  f0fd548:	3c02800a */ 	lui	$v0,%hi(var800a19c0)
/*  f0fd54c:	244219c0 */ 	addiu	$v0,$v0,%lo(var800a19c0)
/*  f0fd550:	804e066e */ 	lb	$t6,0x66e($v0)
/*  f0fd554:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0fd558:	a1e40669 */ 	sb	$a0,0x669($t7)
/*  f0fd55c:	8058066e */ 	lb	$t8,0x66e($v0)
/*  f0fd560:	a040066f */ 	sb	$zero,0x66f($v0)
/*  f0fd564:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0fd568:	03e00008 */ 	jr	$ra
/*  f0fd56c:	a059066e */ 	sb	$t9,0x66e($v0)
);

GLOBAL_ASM(
glabel func0f0fd570
/*  f0fd570:	3c028007 */ 	lui	$v0,0x8007
/*  f0fd574:	8c421448 */ 	lw	$v0,0x1448($v0)
/*  f0fd578:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f0fd57c:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
/*  f0fd580:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f0fd584:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f0fd588:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0fd58c:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f0fd590:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0fd594:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f0fd598:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0fd59c:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f0fd5a0:	8c7804f8 */ 	lw	$t8,0x4f8($v1)
/*  f0fd5a4:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f0fd5a8:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f0fd5ac:	13000024 */ 	beqz	$t8,.L0f0fd640
/*  f0fd5b0:	00808025 */ 	or	$s0,$a0,$zero
/*  f0fd5b4:	846504f4 */ 	lh	$a1,0x4f4($v1)
/*  f0fd5b8:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f0fd5bc:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f0fd5c0:	18a0001f */ 	blez	$a1,.L0f0fd640
/*  f0fd5c4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fd5c8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fd5cc:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f0fd5d0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fd5d4:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f0fd5d8:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fd5dc:	032f1821 */ 	addu	$v1,$t9,$t7
/*  f0fd5e0:	00603025 */ 	or	$a2,$v1,$zero
.L0f0fd5e4:
/*  f0fd5e4:	80c70478 */ 	lb	$a3,0x478($a2)
/*  f0fd5e8:	00045080 */ 	sll	$t2,$a0,0x2
/*  f0fd5ec:	01445023 */ 	subu	$t2,$t2,$a0
/*  f0fd5f0:	18e0000f */ 	blez	$a3,.L0f0fd630
/*  f0fd5f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fd5f8:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0fd5fc:	006a4021 */ 	addu	$t0,$v1,$t2
.L0f0fd600:
/*  f0fd600:	8d090464 */ 	lw	$t1,0x464($t0)
/*  f0fd604:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fd608:	0047082a */ 	slt	$at,$v0,$a3
/*  f0fd60c:	11200006 */ 	beqz	$t1,.L0f0fd628
/*  f0fd610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd614:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*  f0fd618:	160b0003 */ 	bne	$s0,$t3,.L0f0fd628
/*  f0fd61c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd620:	10000008 */ 	beqz	$zero,.L0f0fd644
/*  f0fd624:	01201025 */ 	or	$v0,$t1,$zero
.L0f0fd628:
/*  f0fd628:	1420fff5 */ 	bnez	$at,.L0f0fd600
/*  f0fd62c:	25080004 */ 	addiu	$t0,$t0,0x4
.L0f0fd630:
/*  f0fd630:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0fd634:	0085082a */ 	slt	$at,$a0,$a1
/*  f0fd638:	1420ffea */ 	bnez	$at,.L0f0fd5e4
/*  f0fd63c:	24c60018 */ 	addiu	$a2,$a2,0x18
.L0f0fd640:
/*  f0fd640:	00001025 */ 	or	$v0,$zero,$zero
.L0f0fd644:
/*  f0fd644:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f0fd648:	03e00008 */ 	jr	$ra
/*  f0fd64c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

bool currentPlayerIsInTraining(void)
{
	return g_Vars.currentplayer->training;
}

void func0f0fd660(void)
{
	u32 prevplayernum = g_MpPlayerNum;

	if (!mpIsPaused()) {
		g_ActiveMenuThings[g_ActiveMenuIndex].unk33 = g_ActiveMenuThings[g_ActiveMenuIndex].unk32;
		g_Vars.currentplayer->activemenumode = 0;
		g_MpPlayerNum = g_Vars.unk000288[0].mpchrnum;
		func0f0f8330(&menudialog_picktarget, 8);
		g_MpPlayerNum = prevplayernum;
	}
}

GLOBAL_ASM(
glabel menuhandler000fd6f0
/*  f0fd6f0:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f0fd6f4:	248effff */ 	addiu	$t6,$a0,-1
/*  f0fd6f8:	2dc10014 */ 	sltiu	$at,$t6,0x14
/*  f0fd6fc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0fd700:	afa500bc */ 	sw	$a1,0xbc($sp)
/*  f0fd704:	10200156 */ 	beqz	$at,.L0f0fdc60
/*  f0fd708:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f0fd70c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0fd710:	3c017f1b */ 	lui	$at,%hi(var7f1b2c8c)
/*  f0fd714:	002e0821 */ 	addu	$at,$at,$t6
/*  f0fd718:	8c2e2c8c */ 	lw	$t6,%lo(var7f1b2c8c)($at)
/*  f0fd71c:	01c00008 */ 	jr	$t6
/*  f0fd720:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd724:	3c0f800a */ 	lui	$t7,0x800a
/*  f0fd728:	8def21b8 */ 	lw	$t7,0x21b8($t7)
/*  f0fd72c:	3c19800a */ 	lui	$t9,0x800a
/*  f0fd730:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0fd734:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0fd738:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0fd73c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fd740:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0fd744:	93392103 */ 	lbu	$t9,0x2103($t9)
/*  f0fd748:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0fd74c:	3c06800b */ 	lui	$a2,0x800b
/*  f0fd750:	1320004b */ 	beqz	$t9,.L0f0fd880
/*  f0fd754:	3c0e800b */ 	lui	$t6,0x800b
/*  f0fd758:	8d6e0284 */ 	lw	$t6,0x284($t3)
/*  f0fd75c:	8d6c006c */ 	lw	$t4,0x6c($t3)
/*  f0fd760:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fd764:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f0fd768:	00004825 */ 	or	$t1,$zero,$zero
/*  f0fd76c:	8df80004 */ 	lw	$t8,0x4($t7)
/*  f0fd770:	11800003 */ 	beqz	$t4,.L0f0fd780
/*  f0fd774:	afb800ac */ 	sw	$t8,0xac($sp)
/*  f0fd778:	10000001 */ 	beqz	$zero,.L0f0fd780
/*  f0fd77c:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0fd780:
/*  f0fd780:	8d6d0068 */ 	lw	$t5,0x68($t3)
/*  f0fd784:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fd788:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fd78c:	11a00003 */ 	beqz	$t5,.L0f0fd79c
/*  f0fd790:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd794:	10000001 */ 	beqz	$zero,.L0f0fd79c
/*  f0fd798:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0fd79c:
/*  f0fd79c:	8d7f0064 */ 	lw	$ra,0x64($t3)
/*  f0fd7a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fd7a4:	13e00003 */ 	beqz	$ra,.L0f0fd7b4
/*  f0fd7a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd7ac:	10000001 */ 	beqz	$zero,.L0f0fd7b4
/*  f0fd7b0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0fd7b4:
/*  f0fd7b4:	8d6a0070 */ 	lw	$t2,0x70($t3)
/*  f0fd7b8:	8faf00ac */ 	lw	$t7,0xac($sp)
/*  f0fd7bc:	11400003 */ 	beqz	$t2,.L0f0fd7cc
/*  f0fd7c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd7c4:	10000001 */ 	beqz	$zero,.L0f0fd7cc
/*  f0fd7c8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fd7cc:
/*  f0fd7cc:	8cc6c530 */ 	lw	$a2,-0x3ad0($a2)
/*  f0fd7d0:	0064c821 */ 	addu	$t9,$v1,$a0
/*  f0fd7d4:	03277021 */ 	addu	$t6,$t9,$a3
/*  f0fd7d8:	01c91021 */ 	addu	$v0,$t6,$t1
/*  f0fd7dc:	0046082a */ 	slt	$at,$v0,$a2
/*  f0fd7e0:	10200010 */ 	beqz	$at,.L0f0fd824
/*  f0fd7e4:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f0fd7e8:	3c19800b */ 	lui	$t9,%hi(g_MpPlayerChrs)
/*  f0fd7ec:	2739c4d0 */ 	addiu	$t9,$t9,%lo(g_MpPlayerChrs)
/*  f0fd7f0:	00067080 */ 	sll	$t6,$a2,0x2
/*  f0fd7f4:	01d92021 */ 	addu	$a0,$t6,$t9
/*  f0fd7f8:	03191021 */ 	addu	$v0,$t8,$t9
/*  f0fd7fc:	91e30125 */ 	lbu	$v1,0x125($t7)
/*  f0fd800:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f0fd804:
/*  f0fd804:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0fd808:	0044082b */ 	sltu	$at,$v0,$a0
/*  f0fd80c:	91f80125 */ 	lbu	$t8,0x125($t7)
/*  f0fd810:	10780002 */ 	beq	$v1,$t8,.L0f0fd81c
/*  f0fd814:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd818:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f0fd81c:
/*  f0fd81c:	5420fff9 */ 	bnezl	$at,.L0f0fd804
/*  f0fd820:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f0fd824:
/*  f0fd824:	11400003 */ 	beqz	$t2,.L0f0fd834
/*  f0fd828:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f0fd82c:	10000002 */ 	beqz	$zero,.L0f0fd838
/*  f0fd830:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0fd834:
/*  f0fd834:	00004825 */ 	or	$t1,$zero,$zero
.L0f0fd838:
/*  f0fd838:	11800003 */ 	beqz	$t4,.L0f0fd848
/*  f0fd83c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fd840:	10000001 */ 	beqz	$zero,.L0f0fd848
/*  f0fd844:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0fd848:
/*  f0fd848:	11a00003 */ 	beqz	$t5,.L0f0fd858
/*  f0fd84c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fd850:	10000001 */ 	beqz	$zero,.L0f0fd858
/*  f0fd854:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0fd858:
/*  f0fd858:	13e00003 */ 	beqz	$ra,.L0f0fd868
/*  f0fd85c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fd860:	10000001 */ 	beqz	$zero,.L0f0fd868
/*  f0fd864:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fd868:
/*  f0fd868:	00a37021 */ 	addu	$t6,$a1,$v1
/*  f0fd86c:	01c4c821 */ 	addu	$t9,$t6,$a0
/*  f0fd870:	03277821 */ 	addu	$t7,$t9,$a3
/*  f0fd874:	01e92821 */ 	addu	$a1,$t7,$t1
/*  f0fd878:	100000f9 */ 	beqz	$zero,.L0f0fdc60
/*  f0fd87c:	af050000 */ 	sw	$a1,0x0($t8)
.L0f0fd880:
/*  f0fd880:	8dcec530 */ 	lw	$t6,-0x3ad0($t6)
/*  f0fd884:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f0fd888:	25d9ffff */ 	addiu	$t9,$t6,-1
/*  f0fd88c:	100000f4 */ 	beqz	$zero,.L0f0fdc60
/*  f0fd890:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0fd894:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fd898:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f0fd89c:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f0fd8a0:	3c0f800a */ 	lui	$t7,%hi(g_ActiveMenuThings)
/*  f0fd8a4:	000ec8c0 */ 	sll	$t9,$t6,0x3
/*  f0fd8a8:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f0fd8ac:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0fd8b0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fd8b4:	25ef20d0 */ 	addiu	$t7,$t7,%lo(g_ActiveMenuThings)
/*  f0fd8b8:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0fd8bc:	032f5021 */ 	addu	$t2,$t9,$t7
/*  f0fd8c0:	8f020000 */ 	lw	$v0,0x0($t8)
/*  f0fd8c4:	81580000 */ 	lb	$t8,0x0($t2)
/*  f0fd8c8:	8d670284 */ 	lw	$a3,0x284($t3)
/*  f0fd8cc:	3c09800b */ 	lui	$t1,%hi(g_MpPlayerChrs)
/*  f0fd8d0:	2529c4d0 */ 	addiu	$t1,$t1,%lo(g_MpPlayerChrs)
/*  f0fd8d4:	00f87021 */ 	addu	$t6,$a3,$t8
/*  f0fd8d8:	91d91be5 */ 	lbu	$t9,0x1be5($t6)
/*  f0fd8dc:	3c06800b */ 	lui	$a2,%hi(var800ac4cc)
/*  f0fd8e0:	24c6c4cc */ 	addiu	$a2,$a2,%lo(var800ac4cc)
/*  f0fd8e4:	00197880 */ 	sll	$t7,$t9,0x2
/*  f0fd8e8:	012fc021 */ 	addu	$t8,$t1,$t7
/*  f0fd8ec:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f0fd8f0:	91480033 */ 	lbu	$t0,0x33($t2)
/*  f0fd8f4:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f0fd8f8:	8cf900bc */ 	lw	$t9,0xbc($a3)
/*  f0fd8fc:	8f240004 */ 	lw	$a0,0x4($t9)
.L0f0fd900:
/*  f0fd900:	1100000a */ 	beqz	$t0,.L0f0fd92c
/*  f0fd904:	24c60004 */ 	addiu	$a2,$a2,0x0004
/*  f0fd908:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f0fd90c:	10830005 */ 	beq	$a0,$v1,.L0f0fd924
/*  f0fd910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd914:	908f0125 */ 	lbu	$t7,0x125($a0)
/*  f0fd918:	90780125 */ 	lbu	$t8,0x125($v1)
/*  f0fd91c:	11f80008 */ 	beq	$t7,$t8,.L0f0fd940
/*  f0fd920:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fd924:
/*  f0fd924:	10000006 */ 	beqz	$zero,.L0f0fd940
/*  f0fd928:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f0fd92c:
/*  f0fd92c:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f0fd930:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f0fd934:	11c30002 */ 	beq	$t6,$v1,.L0f0fd940
/*  f0fd938:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd93c:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f0fd940:
/*  f0fd940:	0441ffef */ 	bgez	$v0,.L0f0fd900
/*  f0fd944:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd948:	1100001d */ 	beqz	$t0,.L0f0fd9c0
/*  f0fd94c:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0fd950:	a1400033 */ 	sb	$zero,0x33($t2)
/*  f0fd954:	90f91be6 */ 	lbu	$t9,0x1be6($a3)
/*  f0fd958:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fd95c:	1b20001a */ 	blez	$t9,.L0f0fd9c8
/*  f0fd960:	00e27821 */ 	addu	$t7,$a3,$v0
.L0f0fd964:
/*  f0fd964:	91f81be7 */ 	lbu	$t8,0x1be7($t7)
/*  f0fd968:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f0fd96c:	3c09800b */ 	lui	$t1,%hi(g_MpPlayerChrs)
/*  f0fd970:	2529c4d0 */ 	addiu	$t1,$t1,%lo(g_MpPlayerChrs)
/*  f0fd974:	00187080 */ 	sll	$t6,$t8,0x2
/*  f0fd978:	012ec821 */ 	addu	$t9,$t1,$t6
/*  f0fd97c:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f0fd980:	8de5001c */ 	lw	$a1,0x1c($t7)
/*  f0fd984:	afa6004c */ 	sw	$a2,0x4c($sp)
/*  f0fd988:	0fc6490e */ 	jal	func0f192438
/*  f0fd98c:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0fd990:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0fd994:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0fd998:	8d670284 */ 	lw	$a3,0x284($t3)
/*  f0fd99c:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0fd9a0:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0fd9a4:	90f81be6 */ 	lbu	$t8,0x1be6($a3)
/*  f0fd9a8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fd9ac:	0058082a */ 	slt	$at,$v0,$t8
/*  f0fd9b0:	5420ffec */ 	bnezl	$at,.L0f0fd964
/*  f0fd9b4:	00e27821 */ 	addu	$t7,$a3,$v0
/*  f0fd9b8:	10000003 */ 	beqz	$zero,.L0f0fd9c8
/*  f0fd9bc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fd9c0:
/*  f0fd9c0:	0fc6490e */ 	jal	func0f192438
/*  f0fd9c4:	8c65001c */ 	lw	$a1,0x1c($v1)
.L0f0fd9c8:
/*  f0fd9c8:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0fd9cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd9d0:	100000a4 */ 	beqz	$zero,.L0f0fdc64
/*  f0fd9d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fd9d8:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*  f0fd9dc:	3c0e000f */ 	lui	$t6,0xf
/*  f0fd9e0:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f0fd9e4:	1000009e */ 	beqz	$zero,.L0f0fdc60
/*  f0fd9e8:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0fd9ec:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f0fd9f0:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fd9f4:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f0fd9f8:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0fd9fc:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0fda00:	000ec8c0 */ 	sll	$t9,$t6,0x3
/*  f0fda04:	afb80094 */ 	sw	$t8,0x94($sp)
/*  f0fda08:	3c18800a */ 	lui	$t8,%hi(g_ActiveMenuThings)
/*  f0fda0c:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f0fda10:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fda14:	271820d0 */ 	addiu	$t8,$t8,%lo(g_ActiveMenuThings)
/*  f0fda18:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0fda1c:	03385021 */ 	addu	$t2,$t9,$t8
/*  f0fda20:	8dec0008 */ 	lw	$t4,0x8($t7)
/*  f0fda24:	8de30004 */ 	lw	$v1,0x4($t7)
/*  f0fda28:	814f0000 */ 	lb	$t7,0x0($t2)
/*  f0fda2c:	8d670284 */ 	lw	$a3,0x284($t3)
/*  f0fda30:	3c09800b */ 	lui	$t1,0x800b
/*  f0fda34:	3c04800b */ 	lui	$a0,%hi(var800ac4cc)
/*  f0fda38:	00ef7021 */ 	addu	$t6,$a3,$t7
/*  f0fda3c:	91d91be5 */ 	lbu	$t9,0x1be5($t6)
/*  f0fda40:	8cef00bc */ 	lw	$t7,0xbc($a3)
/*  f0fda44:	2484c4cc */ 	addiu	$a0,$a0,%lo(var800ac4cc)
/*  f0fda48:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f0fda4c:	01384821 */ 	addu	$t1,$t1,$t8
/*  f0fda50:	8d29c4d0 */ 	lw	$t1,-0x3b30($t1)
/*  f0fda54:	91480033 */ 	lbu	$t0,0x33($t2)
/*  f0fda58:	2405fffc */ 	addiu	$a1,$zero,-4
/*  f0fda5c:	8de60004 */ 	lw	$a2,0x4($t7)
/*  f0fda60:	24a50004 */ 	addiu	$a1,$a1,0x4
.L0f0fda64:
/*  f0fda64:	1100000a */ 	beqz	$t0,.L0f0fda90
/*  f0fda68:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f0fda6c:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0fda70:	10c20005 */ 	beq	$a2,$v0,.L0f0fda88
/*  f0fda74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fda78:	90ce0125 */ 	lbu	$t6,0x125($a2)
/*  f0fda7c:	90590125 */ 	lbu	$t9,0x125($v0)
/*  f0fda80:	11d90007 */ 	beq	$t6,$t9,.L0f0fdaa0
/*  f0fda84:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fda88:
/*  f0fda88:	10000005 */ 	beqz	$zero,.L0f0fdaa0
/*  f0fda8c:	2463ffff */ 	addiu	$v1,$v1,-1
.L0f0fda90:
/*  f0fda90:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f0fda94:	11380002 */ 	beq	$t1,$t8,.L0f0fdaa0
/*  f0fda98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fda9c:	2463ffff */ 	addiu	$v1,$v1,-1
.L0f0fdaa0:
/*  f0fdaa0:	0463fff0 */ 	bgezl	$v1,.L0f0fda64
/*  f0fdaa4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f0fdaa8:	3c0f800b */ 	lui	$t7,%hi(var800ac500)
/*  f0fdaac:	25efc500 */ 	addiu	$t7,$t7,%lo(var800ac500)
/*  f0fdab0:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f0fdab4:	afae0058 */ 	sw	$t6,0x58($sp)
/*  f0fdab8:	8dd80000 */ 	lw	$t8,0x0($t6)
/*  f0fdabc:	3c198007 */ 	lui	$t9,0x8007
/*  f0fdac0:	3c014220 */ 	lui	$at,0x4220
/*  f0fdac4:	930f0011 */ 	lbu	$t7,0x11($t8)
/*  f0fdac8:	8d98000c */ 	lw	$t8,0xc($t4)
/*  f0fdacc:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f0fdad0:	032ec821 */ 	addu	$t9,$t9,$t6
/*  f0fdad4:	8f391940 */ 	lw	$t9,0x1940($t9)
/*  f0fdad8:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f0fdadc:	032f7025 */ 	or	$t6,$t9,$t7
/*  f0fdae0:	afae0084 */ 	sw	$t6,0x84($sp)
/*  f0fdae4:	91980010 */ 	lbu	$t8,0x10($t4)
/*  f0fdae8:	53000038 */ 	beqzl	$t8,.L0f0fdbcc
/*  f0fdaec:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f0fdaf0:	44816000 */ 	mtc1	$at,$f12
/*  f0fdaf4:	0fc01ac2 */ 	jal	func0f006b08
/*  f0fdaf8:	afac0090 */ 	sw	$t4,0x90($sp)
/*  f0fdafc:	3c01437f */ 	lui	$at,0x437f
/*  f0fdb00:	44812000 */ 	mtc1	$at,$f4
/*  f0fdb04:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fdb08:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f0fdb0c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0fdb10:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fdb14:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0fdb18:	308500ff */ 	andi	$a1,$a0,0xff
/*  f0fdb1c:	4459f800 */ 	cfc1	$t9,$31
/*  f0fdb20:	44cff800 */ 	ctc1	$t7,$31
/*  f0fdb24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb28:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0fdb2c:	444ff800 */ 	cfc1	$t7,$31
/*  f0fdb30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb34:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0fdb38:	51e00013 */ 	beqzl	$t7,.L0f0fdb88
/*  f0fdb3c:	440f4000 */ 	mfc1	$t7,$f8
/*  f0fdb40:	44814000 */ 	mtc1	$at,$f8
/*  f0fdb44:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fdb48:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0fdb4c:	44cff800 */ 	ctc1	$t7,$31
/*  f0fdb50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb54:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0fdb58:	444ff800 */ 	cfc1	$t7,$31
/*  f0fdb5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb60:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0fdb64:	15e00005 */ 	bnez	$t7,.L0f0fdb7c
/*  f0fdb68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb6c:	440f4000 */ 	mfc1	$t7,$f8
/*  f0fdb70:	3c018000 */ 	lui	$at,0x8000
/*  f0fdb74:	10000007 */ 	beqz	$zero,.L0f0fdb94
/*  f0fdb78:	01e17825 */ 	or	$t7,$t7,$at
.L0f0fdb7c:
/*  f0fdb7c:	10000005 */ 	beqz	$zero,.L0f0fdb94
/*  f0fdb80:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0fdb84:	440f4000 */ 	mfc1	$t7,$f8
.L0f0fdb88:
/*  f0fdb88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb8c:	05e0fffb */ 	bltz	$t7,.L0f0fdb7c
/*  f0fdb90:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fdb94:
/*  f0fdb94:	44d9f800 */ 	ctc1	$t9,$31
/*  f0fdb98:	0fc01a40 */ 	jal	func0f006900
/*  f0fdb9c:	afaf0070 */ 	sw	$t7,0x70($sp)
/*  f0fdba0:	8fac0090 */ 	lw	$t4,0x90($sp)
/*  f0fdba4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0fdba8:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fdbac:	8d84000c */ 	lw	$a0,0xc($t4)
/*  f0fdbb0:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f0fdbb4:	00817025 */ 	or	$t6,$a0,$at
/*  f0fdbb8:	0fc01a40 */ 	jal	func0f006900
/*  f0fdbbc:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0fdbc0:	8fac0090 */ 	lw	$t4,0x90($sp)
/*  f0fdbc4:	afa20084 */ 	sw	$v0,0x84($sp)
/*  f0fdbc8:	8d980000 */ 	lw	$t8,0x0($t4)
.L0f0fdbcc:
/*  f0fdbcc:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0fdbd0:	2719000a */ 	addiu	$t9,$t8,0xa
/*  f0fdbd4:	afb9008c */ 	sw	$t9,0x8c($sp)
/*  f0fdbd8:	8d8f0004 */ 	lw	$t7,0x4($t4)
/*  f0fdbdc:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f0fdbe0:	0fc54d8a */ 	jal	func0f153628
/*  f0fdbe4:	afae0088 */ 	sw	$t6,0x88($sp)
/*  f0fdbe8:	0c002f02 */ 	jal	func0000bc08
/*  f0fdbec:	afa20094 */ 	sw	$v0,0x94($sp)
/*  f0fdbf0:	0c002f06 */ 	jal	func0000bc18
/*  f0fdbf4:	a7a2005c */ 	sh	$v0,0x5c($sp)
/*  f0fdbf8:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f0fdbfc:	3c198008 */ 	lui	$t9,0x8008
/*  f0fdc00:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0fdc04:	8f070000 */ 	lw	$a3,0x0($t8)
/*  f0fdc08:	87b8005c */ 	lh	$t8,0x5c($sp)
/*  f0fdc0c:	8deffb0c */ 	lw	$t7,-0x4f4($t7)
/*  f0fdc10:	8f39fb10 */ 	lw	$t9,-0x4f0($t9)
/*  f0fdc14:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0fdc18:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0fdc1c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0fdc20:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0fdc24:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0fdc28:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0fdc2c:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f0fdc30:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0fdc34:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0fdc38:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0fdc3c:	0fc5580f */ 	jal	func0f15603c
/*  f0fdc40:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0fdc44:	0fc54de0 */ 	jal	func0f153780
/*  f0fdc48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fdc4c:	10000006 */ 	beqz	$zero,.L0f0fdc68
/*  f0fdc50:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0fdc54:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f0fdc58:	2419000b */ 	addiu	$t9,$zero,0xb
/*  f0fdc5c:	adf90000 */ 	sw	$t9,0x0($t7)
.L0f0fdc60:
/*  f0fdc60:	00001025 */ 	or	$v0,$zero,$zero
.L0f0fdc64:
/*  f0fdc64:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0fdc68:
/*  f0fdc68:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f0fdc6c:	03e00008 */ 	jr	$ra
/*  f0fdc70:	00000000 */ 	sll	$zero,$zero,0x0
);

bool menudialogMpPickTarget(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	switch (operation) {
	case MENUOP_100:
		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		break;
	case MENUOP_102:
		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		break;
	case MENUOP_101:
		g_PlayersWithControl[g_Vars.currentplayernum] = true;
		break;
	}

	return false;
}

GLOBAL_ASM(
glabel func0f0fdd00
/*  f0fdd00:	3c03800a */ 	lui	$v1,0x800a
/*  f0fdd04:	8c63a434 */ 	lw	$v1,-0x5bcc($v1)
/*  f0fdd08:	00803825 */ 	or	$a3,$a0,$zero
/*  f0fdd0c:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0fdd10:	1860001a */ 	blez	$v1,.L0f0fdd7c
/*  f0fdd14:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fdd18:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0fdd1c:	2408fbff */ 	addiu	$t0,$zero,-1025
.L0f0fdd20:
/*  f0fdd20:	8c8504b8 */ 	lw	$a1,0x4b8($a0)
/*  f0fdd24:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fdd28:	50a00012 */ 	beqzl	$a1,.L0f0fdd74
/*  f0fdd2c:	0043082a */ 	slt	$at,$v0,$v1
/*  f0fdd30:	8ca60004 */ 	lw	$a2,0x4($a1)
/*  f0fdd34:	50c0000f */ 	beqzl	$a2,.L0f0fdd74
/*  f0fdd38:	0043082a */ 	slt	$at,$v0,$v1
/*  f0fdd3c:	50e00008 */ 	beqzl	$a3,.L0f0fdd60
/*  f0fdd40:	8cd80014 */ 	lw	$t8,0x14($a2)
/*  f0fdd44:	8cce0014 */ 	lw	$t6,0x14($a2)
/*  f0fdd48:	3c03800a */ 	lui	$v1,0x800a
/*  f0fdd4c:	01c87824 */ 	and	$t7,$t6,$t0
/*  f0fdd50:	accf0014 */ 	sw	$t7,0x14($a2)
/*  f0fdd54:	10000006 */ 	beqz	$zero,.L0f0fdd70
/*  f0fdd58:	8c63a434 */ 	lw	$v1,-0x5bcc($v1)
/*  f0fdd5c:	8cd80014 */ 	lw	$t8,0x14($a2)
.L0f0fdd60:
/*  f0fdd60:	3c03800a */ 	lui	$v1,0x800a
/*  f0fdd64:	37190400 */ 	ori	$t9,$t8,0x400
/*  f0fdd68:	acd90014 */ 	sw	$t9,0x14($a2)
/*  f0fdd6c:	8c63a434 */ 	lw	$v1,-0x5bcc($v1)
.L0f0fdd70:
/*  f0fdd70:	0043082a */ 	slt	$at,$v0,$v1
.L0f0fdd74:
/*  f0fdd74:	1420ffea */ 	bnez	$at,.L0f0fdd20
/*  f0fdd78:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f0fdd7c:
/*  f0fdd7c:	03e00008 */ 	jr	$ra
/*  f0fdd80:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0fdd84
/*  f0fdd84:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0fdd88:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0fdd8c:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f0fdd90:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f0fdd94:	8e6e0474 */ 	lw	$t6,0x474($s3)
/*  f0fdd98:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0fdd9c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0fdda0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0fdda4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0fdda8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0fddac:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0fddb0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0fddb4:	19c0002b */ 	blez	$t6,.L0f0fde64
/*  f0fddb8:	00008825 */ 	or	$s1,$zero,$zero
/*  f0fddbc:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0fddc0:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0fddc4:	24160020 */ 	addiu	$s6,$zero,0x20
/*  f0fddc8:	2415001f */ 	addiu	$s5,$zero,0x1f
/*  f0fddcc:	2414001e */ 	addiu	$s4,$zero,0x1e
/*  f0fddd0:	8e4204b8 */ 	lw	$v0,0x4b8($s2)
.L0f0fddd4:
/*  f0fddd4:	5040001e */ 	beqzl	$v0,.L0f0fde50
/*  f0fddd8:	8e790474 */ 	lw	$t9,0x474($s3)
/*  f0fdddc:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f0fdde0:	5200001b */ 	beqzl	$s0,.L0f0fde50
/*  f0fdde4:	8e790474 */ 	lw	$t9,0x474($s3)
/*  f0fdde8:	8e0f001c */ 	lw	$t7,0x1c($s0)
/*  f0fddec:	51e00018 */ 	beqzl	$t7,.L0f0fde50
/*  f0fddf0:	8e790474 */ 	lw	$t9,0x474($s3)
/*  f0fddf4:	0fc0e6a5 */ 	jal	chrIsDead
/*  f0fddf8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fddfc:	54400014 */ 	bnezl	$v0,.L0f0fde50
/*  f0fde00:	8e790474 */ 	lw	$t9,0x474($s3)
/*  f0fde04:	0c006134 */ 	jal	ailistFindById
/*  f0fde08:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f0fde0c:	8e180108 */ 	lw	$t8,0x108($s0)
/*  f0fde10:	5058000f */ 	beql	$v0,$t8,.L0f0fde50
/*  f0fde14:	8e790474 */ 	lw	$t9,0x474($s3)
/*  f0fde18:	82020007 */ 	lb	$v0,0x7($s0)
/*  f0fde1c:	5282000c */ 	beql	$s4,$v0,.L0f0fde50
/*  f0fde20:	8e790474 */ 	lw	$t9,0x474($s3)
/*  f0fde24:	52a2000a */ 	beql	$s5,$v0,.L0f0fde50
/*  f0fde28:	8e790474 */ 	lw	$t9,0x474($s3)
/*  f0fde2c:	52c20008 */ 	beql	$s6,$v0,.L0f0fde50
/*  f0fde30:	8e790474 */ 	lw	$t9,0x474($s3)
/*  f0fde34:	0fc0fe3d */ 	jal	chrStopFiring
/*  f0fde38:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fde3c:	0c006134 */ 	jal	ailistFindById
/*  f0fde40:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f0fde44:	ae020108 */ 	sw	$v0,0x108($s0)
/*  f0fde48:	a600010c */ 	sh	$zero,0x10c($s0)
/*  f0fde4c:	8e790474 */ 	lw	$t9,0x474($s3)
.L0f0fde50:
/*  f0fde50:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0fde54:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f0fde58:	0239082a */ 	slt	$at,$s1,$t9
/*  f0fde5c:	5420ffdd */ 	bnezl	$at,.L0f0fddd4
/*  f0fde60:	8e4204b8 */ 	lw	$v0,0x4b8($s2)
.L0f0fde64:
/*  f0fde64:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0fde68:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0fde6c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0fde70:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0fde74:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0fde78:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0fde7c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0fde80:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0fde84:	03e00008 */ 	jr	$ra
/*  f0fde88:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f0fde8c
/*  f0fde8c:	3c02800a */ 	lui	$v0,0x800a
/*  f0fde90:	8c42a434 */ 	lw	$v0,-0x5bcc($v0)
/*  f0fde94:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0fde98:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0fde9c:	1840001a */ 	blez	$v0,.L0f0fdf08
/*  f0fdea0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fdea4:	24080005 */ 	addiu	$t0,$zero,0x5
/*  f0fdea8:	24070004 */ 	addiu	$a3,$zero,0x4
.L0f0fdeac:
/*  f0fdeac:	8c8504b8 */ 	lw	$a1,0x4b8($a0)
/*  f0fdeb0:	50a00012 */ 	beqzl	$a1,.L0f0fdefc
/*  f0fdeb4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fdeb8:	8ca60004 */ 	lw	$a2,0x4($a1)
/*  f0fdebc:	50c0000f */ 	beqzl	$a2,.L0f0fdefc
/*  f0fdec0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fdec4:	80c50007 */ 	lb	$a1,0x7($a2)
/*  f0fdec8:	50e5000c */ 	beql	$a3,$a1,.L0f0fdefc
/*  f0fdecc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fded0:	5105000a */ 	beql	$t0,$a1,.L0f0fdefc
/*  f0fded4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fded8:	8cce001c */ 	lw	$t6,0x1c($a2)
/*  f0fdedc:	51c00007 */ 	beqzl	$t6,.L0f0fdefc
/*  f0fdee0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fdee4:	8ccf0020 */ 	lw	$t7,0x20($a2)
/*  f0fdee8:	51e00004 */ 	beqzl	$t7,.L0f0fdefc
/*  f0fdeec:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fdef0:	03e00008 */ 	jr	$ra
/*  f0fdef4:	00601025 */ 	or	$v0,$v1,$zero
/*  f0fdef8:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f0fdefc:
/*  f0fdefc:	0062082a */ 	slt	$at,$v1,$v0
/*  f0fdf00:	1420ffea */ 	bnez	$at,.L0f0fdeac
/*  f0fdf04:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f0fdf08:
/*  f0fdf08:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0fdf0c:	03e00008 */ 	jr	$ra
/*  f0fdf10:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0fdf14
/*  f0fdf14:	3c03800a */ 	lui	$v1,0x800a
/*  f0fdf18:	8c6321b8 */ 	lw	$v1,0x21b8($v1)
/*  f0fdf1c:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuThings)
/*  f0fdf20:	250820d0 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuThings)
/*  f0fdf24:	000370c0 */ 	sll	$t6,$v1,0x3
/*  f0fdf28:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f0fdf2c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0fdf30:	010e2821 */ 	addu	$a1,$t0,$t6
/*  f0fdf34:	80a70000 */ 	lb	$a3,0x0($a1)
/*  f0fdf38:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0fdf3c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0fdf40:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0fdf44:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0fdf48:	10e00006 */ 	beqz	$a3,.L0f0fdf64
/*  f0fdf4c:	00803025 */ 	or	$a2,$a0,$zero
/*  f0fdf50:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0fdf54:	10f0005c */ 	beq	$a3,$s0,.L0f0fe0c8
/*  f0fdf58:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0fdf5c:	1000007a */ 	beqz	$zero,.L0f0fe148
/*  f0fdf60:	3c19800a */ 	lui	$t9,0x800a
.L0f0fdf64:
/*  f0fdf64:	28c10005 */ 	slti	$at,$a2,0x5
/*  f0fdf68:	14200002 */ 	bnez	$at,.L0f0fdf74
/*  f0fdf6c:	000378c0 */ 	sll	$t7,$v1,0x3
/*  f0fdf70:	24c6ffff */ 	addiu	$a2,$a2,-1
.L0f0fdf74:
/*  f0fdf74:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f0fdf78:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0fdf7c:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f0fdf80:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f0fdf84:	93290020 */ 	lbu	$t1,0x20($t9)
/*  f0fdf88:	0fc44a54 */ 	jal	func0f112950
/*  f0fdf8c:	afa90040 */ 	sw	$t1,0x40($sp)
/*  f0fdf90:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0fdf94:	0082082a */ 	slt	$at,$a0,$v0
/*  f0fdf98:	502000b5 */ 	beqzl	$at,.L0f0fe270
/*  f0fdf9c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0fdfa0:	0fc44b11 */ 	jal	func0f112c44
/*  f0fdfa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdfa8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fdfac:	10400010 */ 	beqz	$v0,.L0f0fdff0
/*  f0fdfb0:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f0fdfb4:	0fc2c62f */ 	jal	currentPlayerHasWeaponEquipped
/*  f0fdfb8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fdfbc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fdfc0:	1041000b */ 	beq	$v0,$at,.L0f0fdff0
/*  f0fdfc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdfc8:	14400006 */ 	bnez	$v0,.L0f0fdfe4
/*  f0fdfcc:	00008825 */ 	or	$s1,$zero,$zero
/*  f0fdfd0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fdfd4:	0fc2c652 */ 	jal	func0f0b1948
/*  f0fdfd8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fdfdc:	10000004 */ 	beqz	$zero,.L0f0fdff0
/*  f0fdfe0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fdfe4:
/*  f0fdfe4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fdfe8:	0fc2c652 */ 	jal	func0f0b1948
/*  f0fdfec:	00002825 */ 	or	$a1,$zero,$zero
.L0f0fdff0:
/*  f0fdff0:	1220009e */ 	beqz	$s1,.L0f0fe26c
/*  f0fdff4:	3c0a8009 */ 	lui	$t2,0x8009
/*  f0fdff8:	914a8804 */ 	lbu	$t2,-0x77fc($t2)
/*  f0fdffc:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f0fe000:	1140000c */ 	beqz	$t2,.L0f0fe034
/*  f0fe004:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe008:	0fc67494 */ 	jal	func0f19d250
/*  f0fe00c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe010:	0fc6749a */ 	jal	func0f19d268
/*  f0fe014:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fe018:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0fe01c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0fe020:	8c6b0284 */ 	lw	$t3,0x284($v1)
/*  f0fe024:	916c0638 */ 	lbu	$t4,0x638($t3)
/*  f0fe028:	144c0002 */ 	bne	$v0,$t4,.L0f0fe034
/*  f0fe02c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe030:	00008825 */ 	or	$s1,$zero,$zero
.L0f0fe034:
/*  f0fe034:	5220008e */ 	beqzl	$s1,.L0f0fe270
/*  f0fe038:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0fe03c:	0fc44bd8 */ 	jal	func0f112f60
/*  f0fe040:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0fe044:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fe048:	0fc4473e */ 	jal	func0f111cf8
/*  f0fe04c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0fe050:	1040000f */ 	beqz	$v0,.L0f0fe090
/*  f0fe054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe058:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0fe05c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fe060:	10500003 */ 	beq	$v0,$s0,.L0f0fe070
/*  f0fe064:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fe068:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f0fe06c:	02002825 */ 	or	$a1,$s0,$zero
.L0f0fe070:
/*  f0fe070:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0fe074:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0fe078:	1050007c */ 	beq	$v0,$s0,.L0f0fe26c
/*  f0fe07c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0fe080:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f0fe084:	02002825 */ 	or	$a1,$s0,$zero
/*  f0fe088:	10000079 */ 	beqz	$zero,.L0f0fe270
/*  f0fe08c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0fe090:
/*  f0fe090:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0fe094:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fe098:	10500003 */ 	beq	$v0,$s0,.L0f0fe0a8
/*  f0fe09c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fe0a0:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f0fe0a4:	02002825 */ 	or	$a1,$s0,$zero
.L0f0fe0a8:
/*  f0fe0a8:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0fe0ac:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0fe0b0:	1040006e */ 	beqz	$v0,.L0f0fe26c
/*  f0fe0b4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0fe0b8:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f0fe0bc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fe0c0:	1000006b */ 	beqz	$zero,.L0f0fe270
/*  f0fe0c4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0fe0c8:
/*  f0fe0c8:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0fe0cc:	8c6d0284 */ 	lw	$t5,0x284($v1)
/*  f0fe0d0:	81a41580 */ 	lb	$a0,0x1580($t5)
/*  f0fe0d4:	18800018 */ 	blez	$a0,.L0f0fe138
/*  f0fe0d8:	28810024 */ 	slti	$at,$a0,0x24
/*  f0fe0dc:	10200016 */ 	beqz	$at,.L0f0fe138
/*  f0fe0e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe0e4:	8c6e0288 */ 	lw	$t6,0x288($v1)
/*  f0fe0e8:	2482ffff */ 	addiu	$v0,$a0,-1
/*  f0fe0ec:	0002c8c3 */ 	sra	$t9,$v0,0x3
/*  f0fe0f0:	8dcf0070 */ 	lw	$t7,0x70($t6)
/*  f0fe0f4:	3c0a800b */ 	lui	$t2,0x800b
/*  f0fe0f8:	304b0007 */ 	andi	$t3,$v0,0x7
/*  f0fe0fc:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0fe100:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0fe104:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f0fe108:	03194821 */ 	addu	$t1,$t8,$t9
/*  f0fe10c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0fe110:	914ac84f */ 	lbu	$t2,-0x37b1($t2)
/*  f0fe114:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0fe118:	016c6804 */ 	sllv	$t5,$t4,$t3
/*  f0fe11c:	014d7024 */ 	and	$t6,$t2,$t5
/*  f0fe120:	11c00005 */ 	beqz	$t6,.L0f0fe138
/*  f0fe124:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe128:	14d00050 */ 	bne	$a2,$s0,.L0f0fe26c
/*  f0fe12c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fe130:	1000004e */ 	beqz	$zero,.L0f0fe26c
/*  f0fe134:	a0af0030 */ 	sb	$t7,0x30($a1)
.L0f0fe138:
/*  f0fe138:	10d0004c */ 	beq	$a2,$s0,.L0f0fe26c
/*  f0fe13c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0fe140:	1000004a */ 	beqz	$zero,.L0f0fe26c
/*  f0fe144:	a0b80030 */ 	sb	$t8,0x30($a1)
.L0f0fe148:
/*  f0fe148:	8329dfeb */ 	lb	$t1,-0x2015($t9)
/*  f0fe14c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0fe150:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0fe154:	05230019 */ 	bgezl	$t1,.L0f0fe1bc
/*  f0fe158:	8c6c0318 */ 	lw	$t4,0x318($v1)
/*  f0fe15c:	0fc3f7a3 */ 	jal	func0f0fde8c
/*  f0fe160:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0fe164:	04400041 */ 	bltz	$v0,.L0f0fe26c
/*  f0fe168:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0fe16c:	14d00005 */ 	bne	$a2,$s0,.L0f0fe184
/*  f0fe170:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0fe174:	0fc3f740 */ 	jal	func0f0fdd00
/*  f0fe178:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0fe17c:	1000003c */ 	beqz	$zero,.L0f0fe270
/*  f0fe180:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0fe184:
/*  f0fe184:	54c10006 */ 	bnel	$a2,$at,.L0f0fe1a0
/*  f0fe188:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fe18c:	0fc3f740 */ 	jal	func0f0fdd00
/*  f0fe190:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fe194:	10000036 */ 	beqz	$zero,.L0f0fe270
/*  f0fe198:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0fe19c:	24010003 */ 	addiu	$at,$zero,0x3
.L0f0fe1a0:
/*  f0fe1a0:	54c10033 */ 	bnel	$a2,$at,.L0f0fe270
/*  f0fe1a4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0fe1a8:	0fc3f761 */ 	jal	func0f0fdd84
/*  f0fe1ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe1b0:	1000002f */ 	beqz	$zero,.L0f0fe270
/*  f0fe1b4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0fe1b8:	8c6c0318 */ 	lw	$t4,0x318($v1)
.L0f0fe1bc:
/*  f0fe1bc:	5180002c */ 	beqzl	$t4,.L0f0fe270
/*  f0fe1c0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0fe1c4:	90ab0032 */ 	lbu	$t3,0x32($a1)
/*  f0fe1c8:	5160001e */ 	beqzl	$t3,.L0f0fe244
/*  f0fe1cc:	8c690284 */ 	lw	$t1,0x284($v1)
/*  f0fe1d0:	8c710284 */ 	lw	$s1,0x284($v1)
/*  f0fe1d4:	3c0d800b */ 	lui	$t5,%hi(var800acb78)
/*  f0fe1d8:	25adcb78 */ 	addiu	$t5,$t5,%lo(var800acb78)
/*  f0fe1dc:	922a1be6 */ 	lbu	$t2,0x1be6($s1)
/*  f0fe1e0:	00cd1021 */ 	addu	$v0,$a2,$t5
/*  f0fe1e4:	00008025 */ 	or	$s0,$zero,$zero
/*  f0fe1e8:	59400021 */ 	blezl	$t2,.L0f0fe270
/*  f0fe1ec:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0fe1f0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0fe1f4:	02307021 */ 	addu	$t6,$s1,$s0
.L0f0fe1f8:
/*  f0fe1f8:	91cf1be7 */ 	lbu	$t7,0x1be7($t6)
/*  f0fe1fc:	8fa20020 */ 	lw	$v0,0x20($sp)
/*  f0fe200:	3c04800b */ 	lui	$a0,0x800b
/*  f0fe204:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0fe208:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0fe20c:	8c84c4d0 */ 	lw	$a0,-0x3b30($a0)
/*  f0fe210:	0fc65ebd */ 	jal	func0f197af4
/*  f0fe214:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f0fe218:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0fe21c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0fe220:	8c710284 */ 	lw	$s1,0x284($v1)
/*  f0fe224:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0fe228:	92391be6 */ 	lbu	$t9,0x1be6($s1)
/*  f0fe22c:	0219082a */ 	slt	$at,$s0,$t9
/*  f0fe230:	5420fff1 */ 	bnezl	$at,.L0f0fe1f8
/*  f0fe234:	02307021 */ 	addu	$t6,$s1,$s0
/*  f0fe238:	1000000d */ 	beqz	$zero,.L0f0fe270
/*  f0fe23c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0fe240:	8c690284 */ 	lw	$t1,0x284($v1)
.L0f0fe244:
/*  f0fe244:	3c04800b */ 	lui	$a0,0x800b
/*  f0fe248:	3c05800b */ 	lui	$a1,0x800b
/*  f0fe24c:	01276021 */ 	addu	$t4,$t1,$a3
/*  f0fe250:	918b1be5 */ 	lbu	$t3,0x1be5($t4)
/*  f0fe254:	00a62821 */ 	addu	$a1,$a1,$a2
/*  f0fe258:	90a5cb78 */ 	lbu	$a1,-0x3488($a1)
/*  f0fe25c:	000b5080 */ 	sll	$t2,$t3,0x2
/*  f0fe260:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f0fe264:	0fc65ebd */ 	jal	func0f197af4
/*  f0fe268:	8c84c4d0 */ 	lw	$a0,-0x3b30($a0)
.L0f0fe26c:
/*  f0fe26c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0fe270:
/*  f0fe270:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0fe274:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0fe278:	03e00008 */ 	jr	$ra
/*  f0fe27c:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f0fe280
/*  f0fe280:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fe284:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f0fe288:	3c02800a */ 	lui	$v0,0x800a
/*  f0fe28c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0fe290:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0fe294:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0fe298:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0fe29c:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f0fe2a0:	804220d0 */ 	lb	$v0,0x20d0($v0)
/*  f0fe2a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fe2a8:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0fe2ac:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f0fe2b0:	10400006 */ 	beqz	$v0,.L0f0fe2cc
/*  f0fe2b4:	00803825 */ 	or	$a3,$a0,$zero
/*  f0fe2b8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fe2bc:	104100a9 */ 	beq	$v0,$at,.L0f0fe564
/*  f0fe2c0:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe2c4:	1000011b */ 	beqz	$zero,.L0f0fe734
/*  f0fe2c8:	8fa40038 */ 	lw	$a0,0x38($sp)
.L0f0fe2cc:
/*  f0fe2cc:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fe2d0:	54e10009 */ 	bnel	$a3,$at,.L0f0fe2f8
/*  f0fe2d4:	28e10005 */ 	slti	$at,$a3,0x5
/*  f0fe2d8:	0fc5b9f1 */ 	jal	langGet
/*  f0fe2dc:	240458aa */ 	addiu	$a0,$zero,0x58aa
/*  f0fe2e0:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe2e4:	0c004c4c */ 	jal	strcpy
/*  f0fe2e8:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fe2ec:	10000153 */ 	beqz	$zero,.L0f0fe83c
/*  f0fe2f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fe2f4:	28e10005 */ 	slti	$at,$a3,0x5
.L0f0fe2f8:
/*  f0fe2f8:	14200002 */ 	bnez	$at,.L0f0fe304
/*  f0fe2fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe300:	24e7ffff */ 	addiu	$a3,$a3,-1
.L0f0fe304:
/*  f0fe304:	0fc44bd4 */ 	jal	func0f112f50
/*  f0fe308:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0fe30c:	3c18800a */ 	lui	$t8,0x800a
/*  f0fe310:	8f1821b8 */ 	lw	$t8,0x21b8($t8)
/*  f0fe314:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0fe318:	3c0a800a */ 	lui	$t2,0x800a
/*  f0fe31c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0fe320:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0fe324:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fe328:	03274821 */ 	addu	$t1,$t9,$a3
/*  f0fe32c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0fe330:	914a20f0 */ 	lbu	$t2,0x20f0($t2)
/*  f0fe334:	8fab0034 */ 	lw	$t3,0x34($sp)
/*  f0fe338:	144a0004 */ 	bne	$v0,$t2,.L0f0fe34c
/*  f0fe33c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe340:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*  f0fe344:	358d0002 */ 	ori	$t5,$t4,0x2
/*  f0fe348:	ad6d0000 */ 	sw	$t5,0x0($t3)
.L0f0fe34c:
/*  f0fe34c:	0fc44a54 */ 	jal	func0f112950
/*  f0fe350:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0fe354:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fe358:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f0fe35c:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0fe360:	3c04800a */ 	lui	$a0,0x800a
/*  f0fe364:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0fe368:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0fe36c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0fe370:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f0fe374:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0fe378:	908420f0 */ 	lbu	$a0,0x20f0($a0)
/*  f0fe37c:	3c057f1b */ 	lui	$a1,%hi(var7f1b2b28)
/*  f0fe380:	24a52b28 */ 	addiu	$a1,$a1,%lo(var7f1b2b28)
/*  f0fe384:	0082082a */ 	slt	$at,$a0,$v0
/*  f0fe388:	14200006 */ 	bnez	$at,.L0f0fe3a4
/*  f0fe38c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe390:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe394:	0c004c4c */ 	jal	strcpy
/*  f0fe398:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0fe39c:	1000004b */ 	beqz	$zero,.L0f0fe4cc
/*  f0fe3a0:	8fa70030 */ 	lw	$a3,0x30($sp)
.L0f0fe3a4:
/*  f0fe3a4:	0fc44b11 */ 	jal	func0f112c44
/*  f0fe3a8:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0fe3ac:	24010031 */ 	addiu	$at,$zero,0x31
/*  f0fe3b0:	14410037 */ 	bne	$v0,$at,.L0f0fe490
/*  f0fe3b4:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0fe3b8:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f0fe3bc:	0fc2a5dc */ 	jal	func0f0a9770
/*  f0fe3c0:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0fe3c4:	2405003c */ 	addiu	$a1,$zero,0x3c
/*  f0fe3c8:	0045001a */ 	div	$zero,$v0,$a1
/*  f0fe3cc:	00001812 */ 	mflo	$v1
/*  f0fe3d0:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0fe3d4:	14a00002 */ 	bnez	$a1,.L0f0fe3e0
/*  f0fe3d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe3dc:	0007000d */ 	break	0x7
.L0f0fe3e0:
/*  f0fe3e0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fe3e4:	14a10004 */ 	bne	$a1,$at,.L0f0fe3f8
/*  f0fe3e8:	3c018000 */ 	lui	$at,0x8000
/*  f0fe3ec:	14410002 */ 	bne	$v0,$at,.L0f0fe3f8
/*  f0fe3f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe3f4:	0006000d */ 	break	0x6
.L0f0fe3f8:
/*  f0fe3f8:	00650019 */ 	multu	$v1,$a1
/*  f0fe3fc:	afa30024 */ 	sw	$v1,0x24($sp)
/*  f0fe400:	240457eb */ 	addiu	$a0,$zero,0x57eb
/*  f0fe404:	0000c812 */ 	mflo	$t9
/*  f0fe408:	00594823 */ 	subu	$t1,$v0,$t9
/*  f0fe40c:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0fe410:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0fe414:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0fe418:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0fe41c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0fe420:	0145001a */ 	div	$zero,$t2,$a1
/*  f0fe424:	00006012 */ 	mflo	$t4
/*  f0fe428:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0fe42c:	14a00002 */ 	bnez	$a1,.L0f0fe438
/*  f0fe430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe434:	0007000d */ 	break	0x7
.L0f0fe438:
/*  f0fe438:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fe43c:	14a10004 */ 	bne	$a1,$at,.L0f0fe450
/*  f0fe440:	3c018000 */ 	lui	$at,0x8000
/*  f0fe444:	15410002 */ 	bne	$t2,$at,.L0f0fe450
/*  f0fe448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe44c:	0006000d */ 	break	0x6
.L0f0fe450:
/*  f0fe450:	0fc5b9f1 */ 	jal	langGet
/*  f0fe454:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe458:	8fad0020 */ 	lw	$t5,0x20($sp)
/*  f0fe45c:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0fe460:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fe464:	19a00003 */ 	blez	$t5,.L0f0fe474
/*  f0fe468:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe46c:	10000002 */ 	beqz	$zero,.L0f0fe478
/*  f0fe470:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0fe474:
/*  f0fe474:	00001025 */ 	or	$v0,$zero,$zero
.L0f0fe478:
/*  f0fe478:	8fab0024 */ 	lw	$t3,0x24($sp)
/*  f0fe47c:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0fe480:	0c004dad */ 	jal	sprintf
/*  f0fe484:	004b3021 */ 	addu	$a2,$v0,$t3
/*  f0fe488:	10000010 */ 	beqz	$zero,.L0f0fe4cc
/*  f0fe48c:	8fa70030 */ 	lw	$a3,0x30($sp)
.L0f0fe490:
/*  f0fe490:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fe494:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f0fe498:	3c04800a */ 	lui	$a0,0x800a
/*  f0fe49c:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0fe4a0:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0fe4a4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0fe4a8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0fe4ac:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f0fe4b0:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0fe4b4:	0fc44b89 */ 	jal	func0f112e24
/*  f0fe4b8:	908420f0 */ 	lbu	$a0,0x20f0($a0)
/*  f0fe4bc:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe4c0:	0c004c4c */ 	jal	strcpy
/*  f0fe4c4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fe4c8:	8fa70030 */ 	lw	$a3,0x30($sp)
.L0f0fe4cc:
/*  f0fe4cc:	3c19800a */ 	lui	$t9,0x800a
/*  f0fe4d0:	8f3921b8 */ 	lw	$t9,0x21b8($t9)
/*  f0fe4d4:	3c04800a */ 	lui	$a0,%hi(var800a0638)
/*  f0fe4d8:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0fe4dc:	001948c0 */ 	sll	$t1,$t9,0x3
/*  f0fe4e0:	01394823 */ 	subu	$t1,$t1,$t9
/*  f0fe4e4:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f0fe4e8:	01275021 */ 	addu	$t2,$t1,$a3
/*  f0fe4ec:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f0fe4f0:	0fc44b11 */ 	jal	func0f112c44
/*  f0fe4f4:	908420f0 */ 	lbu	$a0,0x20f0($a0)
/*  f0fe4f8:	0fc2c62f */ 	jal	currentPlayerHasWeaponEquipped
/*  f0fe4fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fe500:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fe504:	14410005 */ 	bne	$v0,$at,.L0f0fe51c
/*  f0fe508:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0fe50c:	8fac0034 */ 	lw	$t4,0x34($sp)
/*  f0fe510:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f0fe514:	35ab0008 */ 	ori	$t3,$t5,0x8
/*  f0fe518:	ad8b0000 */ 	sw	$t3,0x0($t4)
.L0f0fe51c:
/*  f0fe51c:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fe520:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f0fe524:	3c04800a */ 	lui	$a0,%hi(var800a0638)
/*  f0fe528:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0fe52c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0fe530:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0fe534:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f0fe538:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0fe53c:	0fc44b11 */ 	jal	func0f112c44
/*  f0fe540:	908420f0 */ 	lbu	$a0,0x20f0($a0)
/*  f0fe544:	0fc28745 */ 	jal	func0f0a1d14
/*  f0fe548:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fe54c:	144000ba */ 	bnez	$v0,.L0f0fe838
/*  f0fe550:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f0fe554:	8f290000 */ 	lw	$t1,0x0($t9)
/*  f0fe558:	352a0010 */ 	ori	$t2,$t1,0x10
/*  f0fe55c:	100000b6 */ 	beqz	$zero,.L0f0fe838
/*  f0fe560:	af2a0000 */ 	sw	$t2,0x0($t9)
.L0f0fe564:
/*  f0fe564:	3c057f1b */ 	lui	$a1,%hi(var7f1b2b2c)
/*  f0fe568:	24a52b2c */ 	addiu	$a1,$a1,%lo(var7f1b2b2c)
/*  f0fe56c:	0c004c4c */ 	jal	strcpy
/*  f0fe570:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0fe574:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0fe578:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fe57c:	54e10009 */ 	bnel	$a3,$at,.L0f0fe5a4
/*  f0fe580:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fe584:	0fc5b9f1 */ 	jal	langGet
/*  f0fe588:	240458ab */ 	addiu	$a0,$zero,0x58ab
/*  f0fe58c:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe590:	0c004c4c */ 	jal	strcpy
/*  f0fe594:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fe598:	100000a8 */ 	beqz	$zero,.L0f0fe83c
/*  f0fe59c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fe5a0:	24010001 */ 	addiu	$at,$zero,0x1
.L0f0fe5a4:
/*  f0fe5a4:	10e10003 */ 	beq	$a3,$at,.L0f0fe5b4
/*  f0fe5a8:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fe5ac:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0fe5b0:	14e100a1 */ 	bne	$a3,$at,.L0f0fe838
.L0f0fe5b4:
/*  f0fe5b4:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0fe5b8:	8cc40284 */ 	lw	$a0,0x284($a2)
/*  f0fe5bc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fe5c0:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0fe5c4:	0fc2c42e */ 	jal	func0f0b10b8
/*  f0fe5c8:	24840638 */ 	addiu	$a0,$a0,%lo(var800a0638)
/*  f0fe5cc:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fe5d0:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0fe5d4:	8cc40284 */ 	lw	$a0,0x284($a2)
/*  f0fe5d8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fe5dc:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0fe5e0:	0fc2c42e */ 	jal	func0f0b10b8
/*  f0fe5e4:	24840638 */ 	addiu	$a0,$a0,%lo(var800a0638)
/*  f0fe5e8:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0fe5ec:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fe5f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fe5f4:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0fe5f8:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f0fe5fc:	14e10027 */ 	bne	$a3,$at,.L0f0fe69c
/*  f0fe600:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fe604:	50400019 */ 	beqzl	$v0,.L0f0fe66c
/*  f0fe608:	8fa20034 */ 	lw	$v0,0x34($sp)
/*  f0fe60c:	8ccd0284 */ 	lw	$t5,0x284($a2)
/*  f0fe610:	81a41580 */ 	lb	$a0,0x1580($t5)
/*  f0fe614:	18800014 */ 	blez	$a0,.L0f0fe668
/*  f0fe618:	28810024 */ 	slti	$at,$a0,0x24
/*  f0fe61c:	50200013 */ 	beqzl	$at,.L0f0fe66c
/*  f0fe620:	8fa20034 */ 	lw	$v0,0x34($sp)
/*  f0fe624:	8ccb0288 */ 	lw	$t3,0x288($a2)
/*  f0fe628:	2483ffff */ 	addiu	$v1,$a0,-1
/*  f0fe62c:	000378c3 */ 	sra	$t7,$v1,0x3
/*  f0fe630:	8d6c0070 */ 	lw	$t4,0x70($t3)
/*  f0fe634:	3c09800b */ 	lui	$t1,0x800b
/*  f0fe638:	306a0007 */ 	andi	$t2,$v1,0x7
/*  f0fe63c:	000c7080 */ 	sll	$t6,$t4,0x2
/*  f0fe640:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f0fe644:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f0fe648:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0fe64c:	01384821 */ 	addu	$t1,$t1,$t8
/*  f0fe650:	9129c84f */ 	lbu	$t1,-0x37b1($t1)
/*  f0fe654:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fe658:	01596804 */ 	sllv	$t5,$t9,$t2
/*  f0fe65c:	012d5824 */ 	and	$t3,$t1,$t5
/*  f0fe660:	15600005 */ 	bnez	$t3,.L0f0fe678
/*  f0fe664:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fe668:
/*  f0fe668:	8fa20034 */ 	lw	$v0,0x34($sp)
.L0f0fe66c:
/*  f0fe66c:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f0fe670:	358e0002 */ 	ori	$t6,$t4,0x2
/*  f0fe674:	ac4e0000 */ 	sw	$t6,0x0($v0)
.L0f0fe678:
/*  f0fe678:	51000070 */ 	beqzl	$t0,.L0f0fe83c
/*  f0fe67c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fe680:	0fc5b9f1 */ 	jal	langGet
/*  f0fe684:	95040004 */ 	lhu	$a0,0x4($t0)
/*  f0fe688:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe68c:	0c004c4c */ 	jal	strcpy
/*  f0fe690:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fe694:	10000069 */ 	beqz	$zero,.L0f0fe83c
/*  f0fe698:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fe69c:
/*  f0fe69c:	51000019 */ 	beqzl	$t0,.L0f0fe704
/*  f0fe6a0:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0fe6a4:	8ccf0284 */ 	lw	$t7,0x284($a2)
/*  f0fe6a8:	81e41580 */ 	lb	$a0,0x1580($t7)
/*  f0fe6ac:	18800018 */ 	blez	$a0,.L0f0fe710
/*  f0fe6b0:	28810024 */ 	slti	$at,$a0,0x24
/*  f0fe6b4:	10200016 */ 	beqz	$at,.L0f0fe710
/*  f0fe6b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe6bc:	8cd80288 */ 	lw	$t8,0x288($a2)
/*  f0fe6c0:	2483ffff */ 	addiu	$v1,$a0,-1
/*  f0fe6c4:	000348c3 */ 	sra	$t1,$v1,0x3
/*  f0fe6c8:	8f190070 */ 	lw	$t9,0x70($t8)
/*  f0fe6cc:	3c0b800b */ 	lui	$t3,0x800b
/*  f0fe6d0:	306c0007 */ 	andi	$t4,$v1,0x7
/*  f0fe6d4:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0fe6d8:	01595021 */ 	addu	$t2,$t2,$t9
/*  f0fe6dc:	000a5140 */ 	sll	$t2,$t2,0x5
/*  f0fe6e0:	01496821 */ 	addu	$t5,$t2,$t1
/*  f0fe6e4:	016d5821 */ 	addu	$t3,$t3,$t5
/*  f0fe6e8:	916bc84f */ 	lbu	$t3,-0x37b1($t3)
/*  f0fe6ec:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0fe6f0:	018e7804 */ 	sllv	$t7,$t6,$t4
/*  f0fe6f4:	016fc024 */ 	and	$t8,$t3,$t7
/*  f0fe6f8:	13000005 */ 	beqz	$t8,.L0f0fe710
/*  f0fe6fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe700:	8fa30034 */ 	lw	$v1,0x34($sp)
.L0f0fe704:
/*  f0fe704:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0fe708:	372a0002 */ 	ori	$t2,$t9,0x2
/*  f0fe70c:	ac6a0000 */ 	sw	$t2,0x0($v1)
.L0f0fe710:
/*  f0fe710:	5040004a */ 	beqzl	$v0,.L0f0fe83c
/*  f0fe714:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fe718:	0fc5b9f1 */ 	jal	langGet
/*  f0fe71c:	94a40004 */ 	lhu	$a0,0x4($a1)
/*  f0fe720:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe724:	0c004c4c */ 	jal	strcpy
/*  f0fe728:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fe72c:	10000043 */ 	beqz	$zero,.L0f0fe83c
/*  f0fe730:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fe734:
/*  f0fe734:	3c057f1b */ 	lui	$a1,%hi(var7f1b2b30)
/*  f0fe738:	24a52b30 */ 	addiu	$a1,$a1,%lo(var7f1b2b30)
/*  f0fe73c:	0c004c4c */ 	jal	strcpy
/*  f0fe740:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0fe744:	3c09800a */ 	lui	$t1,0x800a
/*  f0fe748:	812ddfeb */ 	lb	$t5,-0x2015($t1)
/*  f0fe74c:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0fe750:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fe754:	05a10029 */ 	bgez	$t5,.L0f0fe7fc
/*  f0fe758:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe75c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fe760:	54e10009 */ 	bnel	$a3,$at,.L0f0fe788
/*  f0fe764:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fe768:	0fc5b9f1 */ 	jal	langGet
/*  f0fe76c:	240459da */ 	addiu	$a0,$zero,0x59da
/*  f0fe770:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe774:	0c004c4c */ 	jal	strcpy
/*  f0fe778:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fe77c:	1000002f */ 	beqz	$zero,.L0f0fe83c
/*  f0fe780:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fe784:	24010001 */ 	addiu	$at,$zero,0x1
.L0f0fe788:
/*  f0fe788:	54e10009 */ 	bnel	$a3,$at,.L0f0fe7b0
/*  f0fe78c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0fe790:	0fc5b9f1 */ 	jal	langGet
/*  f0fe794:	240459d8 */ 	addiu	$a0,$zero,0x59d8
/*  f0fe798:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe79c:	0c004c4c */ 	jal	strcpy
/*  f0fe7a0:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fe7a4:	10000025 */ 	beqz	$zero,.L0f0fe83c
/*  f0fe7a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fe7ac:	24010007 */ 	addiu	$at,$zero,0x7
.L0f0fe7b0:
/*  f0fe7b0:	54e10009 */ 	bnel	$a3,$at,.L0f0fe7d8
/*  f0fe7b4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fe7b8:	0fc5b9f1 */ 	jal	langGet
/*  f0fe7bc:	240459d9 */ 	addiu	$a0,$zero,0x59d9
/*  f0fe7c0:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe7c4:	0c004c4c */ 	jal	strcpy
/*  f0fe7c8:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fe7cc:	1000001b */ 	beqz	$zero,.L0f0fe83c
/*  f0fe7d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fe7d4:	24010003 */ 	addiu	$at,$zero,0x3
.L0f0fe7d8:
/*  f0fe7d8:	54e10018 */ 	bnel	$a3,$at,.L0f0fe83c
/*  f0fe7dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fe7e0:	0fc5b9f1 */ 	jal	langGet
/*  f0fe7e4:	240459db */ 	addiu	$a0,$zero,0x59db
/*  f0fe7e8:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe7ec:	0c004c4c */ 	jal	strcpy
/*  f0fe7f0:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fe7f4:	10000011 */ 	beqz	$zero,.L0f0fe83c
/*  f0fe7f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fe7fc:
/*  f0fe7fc:	14e10008 */ 	bne	$a3,$at,.L0f0fe820
/*  f0fe800:	3c04800b */ 	lui	$a0,0x800b
/*  f0fe804:	0fc5b9f1 */ 	jal	langGet
/*  f0fe808:	240458ac */ 	addiu	$a0,$zero,0x58ac
/*  f0fe80c:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe810:	0c004c4c */ 	jal	strcpy
/*  f0fe814:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fe818:	10000008 */ 	beqz	$zero,.L0f0fe83c
/*  f0fe81c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fe820:
/*  f0fe820:	00872021 */ 	addu	$a0,$a0,$a3
/*  f0fe824:	0fc648fb */ 	jal	mpGetBotCommandName
/*  f0fe828:	9084cb78 */ 	lbu	$a0,-0x3488($a0)
/*  f0fe82c:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0fe830:	0c004c4c */ 	jal	strcpy
/*  f0fe834:	00402825 */ 	or	$a1,$v0,$zero
.L0f0fe838:
/*  f0fe838:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fe83c:
/*  f0fe83c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0fe840:	03e00008 */ 	jr	$ra
/*  f0fe844:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0fe848
/*  f0fe848:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0fe84c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0fe850:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0fe854:	8d0e0284 */ 	lw	$t6,0x284($t0)
/*  f0fe858:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f0fe85c:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0fe860:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f0fe864:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f0fe868:	3c0f800a */ 	lui	$t7,0x800a
/*  f0fe86c:	25e420d0 */ 	addiu	$a0,$t7,0x20d0
/*  f0fe870:	3c12800b */ 	lui	$s2,0x800b
/*  f0fe874:	3c13800a */ 	lui	$s3,%hi(var800a21b0)
/*  f0fe878:	3c0c8008 */ 	lui	$t4,%hi(mpweaponstable)
/*  f0fe87c:	3c0a7f1b */ 	lui	$t2,%hi(var7f1b2b20)
/*  f0fe880:	a1c00250 */ 	sb	$zero,0x250($t6)
/*  f0fe884:	8d060318 */ 	lw	$a2,0x318($t0)
/*  f0fe888:	254a2b20 */ 	addiu	$t2,$t2,%lo(var7f1b2b20)
/*  f0fe88c:	258c7268 */ 	addiu	$t4,$t4,%lo(mpweaponstable)
/*  f0fe890:	267321b0 */ 	addiu	$s3,$s3,%lo(var800a21b0)
/*  f0fe894:	2652cb8e */ 	addiu	$s2,$s2,-13426
/*  f0fe898:	00801825 */ 	or	$v1,$a0,$zero
/*  f0fe89c:	2410005b */ 	addiu	$s0,$zero,0x5b
/*  f0fe8a0:	2411005c */ 	addiu	$s1,$zero,0x5c
/*  f0fe8a4:	240d000a */ 	addiu	$t5,$zero,0xa
/*  f0fe8a8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0fe8ac:	240900ff */ 	addiu	$t1,$zero,0xff
.L0f0fe8b0:
/*  f0fe8b0:	a0600030 */ 	sb	$zero,0x30($v1)
/*  f0fe8b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fe8b8:	00802825 */ 	or	$a1,$a0,$zero
.L0f0fe8bc:
/*  f0fe8bc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fe8c0:	28410008 */ 	slti	$at,$v0,0x8
/*  f0fe8c4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0fe8c8:	1420fffc */ 	bnez	$at,.L0f0fe8bc
/*  f0fe8cc:	a0a90027 */ 	sb	$t1,0x27($a1)
/*  f0fe8d0:	10c00018 */ 	beqz	$a2,.L0f0fe934
/*  f0fe8d4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fe8d8:	91580000 */ 	lbu	$t8,0x0($t2)
/*  f0fe8dc:	3c07800b */ 	lui	$a3,%hi(g_MpSetup)
/*  f0fe8e0:	24e7cb88 */ 	addiu	$a3,$a3,%lo(g_MpSetup)
/*  f0fe8e4:	0098c821 */ 	addu	$t9,$a0,$t8
/*  f0fe8e8:	a32b0028 */ 	sb	$t3,0x28($t9)
/*  f0fe8ec:	90ee0018 */ 	lbu	$t6,0x18($a3)
.L0f0fe8f0:
/*  f0fe8f0:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f0fe8f4:	01cd0019 */ 	multu	$t6,$t5
/*  f0fe8f8:	00007812 */ 	mflo	$t7
/*  f0fe8fc:	018fc021 */ 	addu	$t8,$t4,$t7
/*  f0fe900:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f0fe904:	10400009 */ 	beqz	$v0,.L0f0fe92c
/*  f0fe908:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe90c:	10500007 */ 	beq	$v0,$s0,.L0f0fe92c
/*  f0fe910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe914:	10510005 */ 	beq	$v0,$s1,.L0f0fe92c
/*  f0fe918:	0145c821 */ 	addu	$t9,$t2,$a1
/*  f0fe91c:	932e0000 */ 	lbu	$t6,0x0($t9)
/*  f0fe920:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0fe924:	008e7821 */ 	addu	$t7,$a0,$t6
/*  f0fe928:	a1e20028 */ 	sb	$v0,0x28($t7)
.L0f0fe92c:
/*  f0fe92c:	54f2fff0 */ 	bnel	$a3,$s2,.L0f0fe8f0
/*  f0fe930:	90ee0018 */ 	lbu	$t6,0x18($a3)
.L0f0fe934:
/*  f0fe934:	24840038 */ 	addiu	$a0,$a0,0x38
/*  f0fe938:	1493ffdd */ 	bne	$a0,$s3,.L0f0fe8b0
/*  f0fe93c:	24630038 */ 	addiu	$v1,$v1,0x38
/*  f0fe940:	8d18006c */ 	lw	$t8,0x6c($t0)
/*  f0fe944:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fe948:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fe94c:	13000003 */ 	beqz	$t8,.L0f0fe95c
/*  f0fe950:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fe954:	10000001 */ 	beqz	$zero,.L0f0fe95c
/*  f0fe958:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fe95c:
/*  f0fe95c:	8d190068 */ 	lw	$t9,0x68($t0)
/*  f0fe960:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fe964:	13200003 */ 	beqz	$t9,.L0f0fe974
/*  f0fe968:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe96c:	10000001 */ 	beqz	$zero,.L0f0fe974
/*  f0fe970:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0fe974:
/*  f0fe974:	8d0e0064 */ 	lw	$t6,0x64($t0)
/*  f0fe978:	11c00003 */ 	beqz	$t6,.L0f0fe988
/*  f0fe97c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe980:	10000001 */ 	beqz	$zero,.L0f0fe988
/*  f0fe984:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0fe988:
/*  f0fe988:	8d0f0070 */ 	lw	$t7,0x70($t0)
/*  f0fe98c:	11e00003 */ 	beqz	$t7,.L0f0fe99c
/*  f0fe990:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fe994:	10000001 */ 	beqz	$zero,.L0f0fe99c
/*  f0fe998:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0fe99c:
/*  f0fe99c:	0045c021 */ 	addu	$t8,$v0,$a1
/*  f0fe9a0:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0fe9a4:	03237021 */ 	addu	$t6,$t9,$v1
/*  f0fe9a8:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0fe9ac:	1420000a */ 	bnez	$at,.L0f0fe9d8
/*  f0fe9b0:	3c198008 */ 	lui	$t9,0x8008
/*  f0fe9b4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0fe9b8:	8deffb08 */ 	lw	$t7,-0x4f8($t7)
/*  f0fe9bc:	3c01800a */ 	lui	$at,0x800a
/*  f0fe9c0:	3c188008 */ 	lui	$t8,0x8008
/*  f0fe9c4:	8f18fb04 */ 	lw	$t8,-0x4fc($t8)
/*  f0fe9c8:	ac2f21b0 */ 	sw	$t7,0x21b0($at)
/*  f0fe9cc:	3c01800a */ 	lui	$at,0x800a
/*  f0fe9d0:	10000008 */ 	beqz	$zero,.L0f0fe9f4
/*  f0fe9d4:	ac3821b4 */ 	sw	$t8,0x21b4($at)
.L0f0fe9d8:
/*  f0fe9d8:	8f39fb10 */ 	lw	$t9,-0x4f0($t9)
/*  f0fe9dc:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0fe9e0:	8dcefb0c */ 	lw	$t6,-0x4f4($t6)
/*  f0fe9e4:	3c01800a */ 	lui	$at,0x800a
/*  f0fe9e8:	ac3921b0 */ 	sw	$t9,0x21b0($at)
/*  f0fe9ec:	3c01800a */ 	lui	$at,0x800a
/*  f0fe9f0:	ac2e21b4 */ 	sw	$t6,0x21b4($at)
.L0f0fe9f4:
/*  f0fe9f4:	3c01800a */ 	lui	$at,0x800a
/*  f0fe9f8:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f0fe9fc:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f0fea00:	8fb20010 */ 	lw	$s2,0x10($sp)
/*  f0fea04:	8fb30014 */ 	lw	$s3,0x14($sp)
/*  f0fea08:	ac2021b8 */ 	sw	$zero,0x21b8($at)
/*  f0fea0c:	03e00008 */ 	jr	$ra
/*  f0fea10:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f0fea14
/*  f0fea14:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0fea18:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f0fea1c:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f0fea20:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f0fea24:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f0fea28:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f0fea2c:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f0fea30:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0fea34:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0fea38:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0fea3c:	3c15800a */ 	lui	$s5,%hi(var800a21b0)
/*  f0fea40:	3c16800a */ 	lui	$s6,%hi(var800a21b4)
/*  f0fea44:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0fea48:	0000f025 */ 	or	$s8,$zero,$zero
/*  f0fea4c:	26d621b4 */ 	addiu	$s6,$s6,%lo(var800a21b4)
/*  f0fea50:	26b521b0 */ 	addiu	$s5,$s5,%lo(var800a21b0)
/*  f0fea54:	00008025 */ 	or	$s0,$zero,$zero
/*  f0fea58:	27b1005c */ 	addiu	$s1,$sp,0x5c
/*  f0fea5c:	27b2007c */ 	addiu	$s2,$sp,0x7c
/*  f0fea60:	27b3008c */ 	addiu	$s3,$sp,0x8c
/*  f0fea64:	27b40088 */ 	addiu	$s4,$sp,0x88
/*  f0fea68:	24170009 */ 	addiu	$s7,$zero,0x9
/*  f0fea6c:	02002025 */ 	or	$a0,$s0,$zero
.L0f0fea70:
/*  f0fea70:	02402825 */ 	or	$a1,$s2,$zero
/*  f0fea74:	0fc3f8a0 */ 	jal	func0f0fe280
/*  f0fea78:	02203025 */ 	or	$a2,$s1,$zero
/*  f0fea7c:	8ece0000 */ 	lw	$t6,0x0($s6)
/*  f0fea80:	02602025 */ 	or	$a0,$s3,$zero
/*  f0fea84:	02802825 */ 	or	$a1,$s4,$zero
/*  f0fea88:	02203025 */ 	or	$a2,$s1,$zero
/*  f0fea8c:	8ea70000 */ 	lw	$a3,0x0($s5)
/*  f0fea90:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0fea94:	0fc55cbe */ 	jal	func0f1572f8
/*  f0fea98:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0fea9c:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f0feaa0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0feaa4:	03c2082a */ 	slt	$at,$s8,$v0
/*  f0feaa8:	10200002 */ 	beqz	$at,.L0f0feab4
/*  f0feaac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0feab0:	0040f025 */ 	or	$s8,$v0,$zero
.L0f0feab4:
/*  f0feab4:	5617ffee */ 	bnel	$s0,$s7,.L0f0fea70
/*  f0feab8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0feabc:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0feac0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0feac4:	8c4f006c */ 	lw	$t7,0x6c($v0)
/*  f0feac8:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0feacc:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0fead0:	11e00003 */ 	beqz	$t7,.L0f0feae0
/*  f0fead4:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0fead8:	10000002 */ 	beqz	$zero,.L0f0feae4
/*  f0feadc:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0feae0:
/*  f0feae0:	00002825 */ 	or	$a1,$zero,$zero
.L0f0feae4:
/*  f0feae4:	8c580068 */ 	lw	$t8,0x68($v0)
/*  f0feae8:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f0feaec:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f0feaf0:	13000003 */ 	beqz	$t8,.L0f0feb00
/*  f0feaf4:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f0feaf8:	10000002 */ 	beqz	$zero,.L0f0feb04
/*  f0feafc:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0feb00:
/*  f0feb00:	00001825 */ 	or	$v1,$zero,$zero
.L0f0feb04:
/*  f0feb04:	8c590064 */ 	lw	$t9,0x64($v0)
/*  f0feb08:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f0feb0c:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f0feb10:	13200003 */ 	beqz	$t9,.L0f0feb20
/*  f0feb14:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0feb18:	10000002 */ 	beqz	$zero,.L0f0feb24
/*  f0feb1c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0feb20:
/*  f0feb20:	00002025 */ 	or	$a0,$zero,$zero
.L0f0feb24:
/*  f0feb24:	8c480070 */ 	lw	$t0,0x70($v0)
/*  f0feb28:	00001025 */ 	or	$v0,$zero,$zero
/*  f0feb2c:	11000003 */ 	beqz	$t0,.L0f0feb3c
/*  f0feb30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0feb34:	10000001 */ 	beqz	$zero,.L0f0feb3c
/*  f0feb38:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0feb3c:
/*  f0feb3c:	00444821 */ 	addu	$t1,$v0,$a0
/*  f0feb40:	01235021 */ 	addu	$t2,$t1,$v1
/*  f0feb44:	01455821 */ 	addu	$t3,$t2,$a1
/*  f0feb48:	29610002 */ 	slti	$at,$t3,0x2
/*  f0feb4c:	54200004 */ 	bnezl	$at,.L0f0feb60
/*  f0feb50:	27de0004 */ 	addiu	$s8,$s8,0x4
/*  f0feb54:	10000002 */ 	beqz	$zero,.L0f0feb60
/*  f0feb58:	27de0003 */ 	addiu	$s8,$s8,0x3
/*  f0feb5c:	27de0004 */ 	addiu	$s8,$s8,0x4
.L0f0feb60:
/*  f0feb60:	001e1400 */ 	sll	$v0,$s8,0x10
/*  f0feb64:	00026403 */ 	sra	$t4,$v0,0x10
/*  f0feb68:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f0feb6c:	27bd0090 */ 	addiu	$sp,$sp,0x90
/*  f0feb70:	03e00008 */ 	jr	$ra
/*  f0feb74:	01801025 */ 	or	$v0,$t4,$zero
);

void activemenuChangeScreen(s32 step)
{
	s32 maxscreenindex;

	g_ActiveMenuThings[g_ActiveMenuIndex].screenindex += step;

	if (g_Vars.mplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
		if (g_ActiveMenuThings[g_ActiveMenuIndex].unk32) {
			// Weapon selection, second function, and ...?
			maxscreenindex = 2;
		} else {
			// Num sims on team + 1 for weapon selection?
			maxscreenindex = g_Vars.currentplayer->unk1be6 + 1;
		}
	} else {
		// Solo missions, or MP with no teams
		if (g_MissionConfig.iscoop && func0f0fde8c() >= 0) {
			// Weapon selection, second function and AI buddy commands
			maxscreenindex = 2;
		} else {
			// Weapon selection and second function
			maxscreenindex = 1;
		}
	}

	if (g_ActiveMenuThings[g_ActiveMenuIndex].screenindex > maxscreenindex) {
		g_ActiveMenuThings[g_ActiveMenuIndex].screenindex = 0;
	}

	if (g_ActiveMenuThings[g_ActiveMenuIndex].screenindex < 0) {
		g_ActiveMenuThings[g_ActiveMenuIndex].screenindex = maxscreenindex;
	}

	g_ActiveMenuThings[g_ActiveMenuIndex].unk02 = 10;
	g_ActiveMenuThings[g_ActiveMenuIndex].unk0a = -123;
	g_ActiveMenuThings[g_ActiveMenuIndex].unk0e = 4;
	g_ActiveMenuThings[g_ActiveMenuIndex].unk14 = 0;
	g_ActiveMenuThings[g_ActiveMenuIndex].unk10 = 0;
	g_ActiveMenuThings[g_ActiveMenuIndex].unk18 = 0;
	g_ActiveMenuThings[g_ActiveMenuIndex].unk04 = func0f0fea14();
}

GLOBAL_ASM(
glabel func0f0fecd4
/*  f0fecd4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0fecd8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0fecdc:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0fece0:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0fece4:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0fece8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0fecec:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0fecf0:	0fc44a54 */ 	jal	func0f112950
/*  f0fecf4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0fecf8:	3c04800a */ 	lui	$a0,0x800a
/*  f0fecfc:	8c8421b8 */ 	lw	$a0,0x21b8($a0)
/*  f0fed00:	3c01800a */ 	lui	$at,0x800a
/*  f0fed04:	3c18800a */ 	lui	$t8,%hi(g_ActiveMenuThings)
/*  f0fed08:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f0fed0c:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f0fed10:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f0fed14:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0fed18:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f0fed1c:	002e0821 */ 	addu	$at,$at,$t6
/*  f0fed20:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0fed24:	271820d0 */ 	addiu	$t8,$t8,%lo(g_ActiveMenuThings)
/*  f0fed28:	00409825 */ 	or	$s3,$v0,$zero
/*  f0fed2c:	a0222101 */ 	sb	$v0,0x2101($at)
/*  f0fed30:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f0fed34:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f0fed38:	00008825 */ 	or	$s1,$zero,$zero
.L0f0fed3c:
/*  f0fed3c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0fed40:	2a210008 */ 	slti	$at,$s1,0x8
/*  f0fed44:	a0640020 */ 	sb	$a0,0x20($v1)
/*  f0fed48:	1420fffc */ 	bnez	$at,.L0f0fed3c
/*  f0fed4c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fed50:	18400029 */ 	blez	$v0,.L0f0fedf8
/*  f0fed54:	00008825 */ 	or	$s1,$zero,$zero
/*  f0fed58:	2415004d */ 	addiu	$s5,$zero,0x4d
/*  f0fed5c:	2414005d */ 	addiu	$s4,$zero,0x5d
/*  f0fed60:	241200ff */ 	addiu	$s2,$zero,0xff
/*  f0fed64:	24100008 */ 	addiu	$s0,$zero,0x8
.L0f0fed68:
/*  f0fed68:	0fc44b11 */ 	jal	func0f112c44
/*  f0fed6c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0fed70:	304400ff */ 	andi	$a0,$v0,0xff
/*  f0fed74:	18800003 */ 	blez	$a0,.L0f0fed84
/*  f0fed78:	28810042 */ 	slti	$at,$a0,0x42
/*  f0fed7c:	14200006 */ 	bnez	$at,.L0f0fed98
/*  f0fed80:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fed84:
/*  f0fed84:	12840004 */ 	beq	$s4,$a0,.L0f0fed98
/*  f0fed88:	24010044 */ 	addiu	$at,$zero,0x44
/*  f0fed8c:	10810002 */ 	beq	$a0,$at,.L0f0fed98
/*  f0fed90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fed94:	16a40014 */ 	bne	$s5,$a0,.L0f0fede8
.L0f0fed98:
/*  f0fed98:	3c19800a */ 	lui	$t9,0x800a
/*  f0fed9c:	8f3921b8 */ 	lw	$t9,0x21b8($t9)
/*  f0feda0:	3c09800a */ 	lui	$t1,%hi(g_ActiveMenuThings)
/*  f0feda4:	252920d0 */ 	addiu	$t1,$t1,%lo(g_ActiveMenuThings)
/*  f0feda8:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f0fedac:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0fedb0:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f0fedb4:	01091021 */ 	addu	$v0,$t0,$t1
/*  f0fedb8:	00001825 */ 	or	$v1,$zero,$zero
.L0f0fedbc:
/*  f0fedbc:	904a0028 */ 	lbu	$t2,0x28($v0)
/*  f0fedc0:	548a0007 */ 	bnel	$a0,$t2,.L0f0fede0
/*  f0fedc4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fedc8:	904b0020 */ 	lbu	$t3,0x20($v0)
/*  f0fedcc:	564b0007 */ 	bnel	$s2,$t3,.L0f0fedec
/*  f0fedd0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0fedd4:	10000004 */ 	beqz	$zero,.L0f0fede8
/*  f0fedd8:	a0510020 */ 	sb	$s1,0x20($v0)
/*  f0feddc:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f0fede0:
/*  f0fede0:	1470fff6 */ 	bne	$v1,$s0,.L0f0fedbc
/*  f0fede4:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f0fede8:
/*  f0fede8:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f0fedec:
/*  f0fedec:	1633ffde */ 	bne	$s1,$s3,.L0f0fed68
/*  f0fedf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fedf4:	00008825 */ 	or	$s1,$zero,$zero
.L0f0fedf8:
/*  f0fedf8:	24100008 */ 	addiu	$s0,$zero,0x8
/*  f0fedfc:	241200ff */ 	addiu	$s2,$zero,0xff
/*  f0fee00:	2414005d */ 	addiu	$s4,$zero,0x5d
/*  f0fee04:	1a60004f */ 	blez	$s3,.L0f0fef44
/*  f0fee08:	2415004d */ 	addiu	$s5,$zero,0x4d
.L0f0fee0c:
/*  f0fee0c:	3c0c800a */ 	lui	$t4,0x800a
/*  f0fee10:	8d8c21b8 */ 	lw	$t4,0x21b8($t4)
/*  f0fee14:	3c0e800a */ 	lui	$t6,%hi(g_ActiveMenuThings)
/*  f0fee18:	25ce20d0 */ 	addiu	$t6,$t6,%lo(g_ActiveMenuThings)
/*  f0fee1c:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f0fee20:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0fee24:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0fee28:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fee2c:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f0fee30:	00001825 */ 	or	$v1,$zero,$zero
.L0f0fee34:
/*  f0fee34:	904f0020 */ 	lbu	$t7,0x20($v0)
/*  f0fee38:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fee3c:	162f0002 */ 	bne	$s1,$t7,.L0f0fee48
/*  f0fee40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fee44:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0fee48:
/*  f0fee48:	1470fffa */ 	bne	$v1,$s0,.L0f0fee34
/*  f0fee4c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fee50:	5480003a */ 	bnezl	$a0,.L0f0fef3c
/*  f0fee54:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0fee58:	0fc44b11 */ 	jal	func0f112c44
/*  f0fee5c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0fee60:	304600ff */ 	andi	$a2,$v0,0xff
/*  f0fee64:	18c00004 */ 	blez	$a2,.L0f0fee78
/*  f0fee68:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0fee6c:	28810042 */ 	slti	$at,$a0,0x42
/*  f0fee70:	14200004 */ 	bnez	$at,.L0f0fee84
/*  f0fee74:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fee78:
/*  f0fee78:	12840002 */ 	beq	$s4,$a0,.L0f0fee84
/*  f0fee7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fee80:	16a4002d */ 	bne	$s5,$a0,.L0f0fef38
.L0f0fee84:
/*  f0fee84:	3c18800a */ 	lui	$t8,0x800a
/*  f0fee88:	8f1821b8 */ 	lw	$t8,0x21b8($t8)
/*  f0fee8c:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuThings)
/*  f0fee90:	250820d0 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuThings)
/*  f0fee94:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0fee98:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0fee9c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0feea0:	3c037f1b */ 	lui	$v1,%hi(var7f1b2b20)
/*  f0feea4:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0feea8:	24632b20 */ 	addiu	$v1,$v1,%lo(var7f1b2b20)
/*  f0feeac:	03282021 */ 	addu	$a0,$t9,$t0
/*  f0feeb0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0feeb4:
/*  f0feeb4:	90690000 */ 	lbu	$t1,0x0($v1)
/*  f0feeb8:	00895021 */ 	addu	$t2,$a0,$t1
/*  f0feebc:	914b0028 */ 	lbu	$t3,0x28($t2)
/*  f0feec0:	564b0004 */ 	bnel	$s2,$t3,.L0f0feed4
/*  f0feec4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0feec8:	10000005 */ 	beqz	$zero,.L0f0feee0
/*  f0feecc:	00402825 */ 	or	$a1,$v0,$zero
/*  f0feed0:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f0feed4:
/*  f0feed4:	28410008 */ 	slti	$at,$v0,0x8
/*  f0feed8:	1420fff6 */ 	bnez	$at,.L0f0feeb4
/*  f0feedc:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f0feee0:
/*  f0feee0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0feee4:	14a1000d */ 	bne	$a1,$at,.L0f0fef1c
/*  f0feee8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0feeec:	3c037f1b */ 	lui	$v1,%hi(var7f1b2b20)
/*  f0feef0:	24632b20 */ 	addiu	$v1,$v1,%lo(var7f1b2b20)
.L0f0feef4:
/*  f0feef4:	906c0000 */ 	lbu	$t4,0x0($v1)
/*  f0feef8:	008c6821 */ 	addu	$t5,$a0,$t4
/*  f0feefc:	91ae0020 */ 	lbu	$t6,0x20($t5)
/*  f0fef00:	564e0004 */ 	bnel	$s2,$t6,.L0f0fef14
/*  f0fef04:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fef08:	10000004 */ 	beqz	$zero,.L0f0fef1c
/*  f0fef0c:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fef10:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f0fef14:
/*  f0fef14:	1450fff7 */ 	bne	$v0,$s0,.L0f0feef4
/*  f0fef18:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f0fef1c:
/*  f0fef1c:	04a00006 */ 	bltz	$a1,.L0f0fef38
/*  f0fef20:	3c0f7f1b */ 	lui	$t7,%hi(var7f1b2b20)
/*  f0fef24:	01e57821 */ 	addu	$t7,$t7,$a1
/*  f0fef28:	91ef2b20 */ 	lbu	$t7,%lo(var7f1b2b20)($t7)
/*  f0fef2c:	008f1021 */ 	addu	$v0,$a0,$t7
/*  f0fef30:	a0510020 */ 	sb	$s1,0x20($v0)
/*  f0fef34:	a0460028 */ 	sb	$a2,0x28($v0)
.L0f0fef38:
/*  f0fef38:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f0fef3c:
/*  f0fef3c:	1633ffb3 */ 	bne	$s1,$s3,.L0f0fee0c
/*  f0fef40:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0fef44:
/*  f0fef44:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0fef48:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0fef4c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0fef50:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0fef54:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0fef58:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0fef5c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0fef60:	03e00008 */ 	jr	$ra
/*  f0fef64:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f0fef68
/*  f0fef68:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0fef6c:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0fef70:	8c830284 */ 	lw	$v1,0x284($a0)
/*  f0fef74:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0fef78:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fef7c:	8c6e1580 */ 	lw	$t6,0x1580($v1)
/*  f0fef80:	3c05800a */ 	lui	$a1,%hi(g_ActiveMenuIndex)
/*  f0fef84:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f0fef88:	55e0002a */ 	bnezl	$t7,.L0f0ff034
/*  f0fef8c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fef90:	8c98028c */ 	lw	$t8,0x28c($a0)
/*  f0fef94:	24a521b8 */ 	addiu	$a1,$a1,%lo(g_ActiveMenuIndex)
/*  f0fef98:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fef9c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f0fefa0:	a0790250 */ 	sb	$t9,0x250($v1)
/*  f0fefa4:	8c88028c */ 	lw	$t0,0x28c($a0)
/*  f0fefa8:	3c018007 */ 	lui	$at,0x8007
/*  f0fefac:	3c0c800a */ 	lui	$t4,%hi(g_ActiveMenuThings)
/*  f0fefb0:	00084880 */ 	sll	$t1,$t0,0x2
/*  f0fefb4:	00290821 */ 	addu	$at,$at,$t1
/*  f0fefb8:	ac200750 */ 	sw	$zero,0x750($at)
/*  f0fefbc:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f0fefc0:	44802000 */ 	mtc1	$zero,$f4
/*  f0fefc4:	258c20d0 */ 	addiu	$t4,$t4,%lo(g_ActiveMenuThings)
/*  f0fefc8:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f0fefcc:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0fefd0:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0fefd4:	016c1021 */ 	addu	$v0,$t3,$t4
/*  f0fefd8:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f0fefdc:	0fc3fb35 */ 	jal	func0f0fecd4
/*  f0fefe0:	e444001c */ 	swc1	$f4,0x1c($v0)
/*  f0fefe4:	0fc3fade */ 	jal	activemenuChangeScreen
/*  f0fefe8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fefec:	3c0d800a */ 	lui	$t5,0x800a
/*  f0feff0:	8dad21b8 */ 	lw	$t5,0x21b8($t5)
/*  f0feff4:	3c0f800a */ 	lui	$t7,%hi(g_ActiveMenuThings)
/*  f0feff8:	25ef20d0 */ 	addiu	$t7,$t7,%lo(g_ActiveMenuThings)
/*  f0feffc:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f0ff000:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0ff004:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0ff008:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f0ff00c:	84580004 */ 	lh	$t8,0x4($v0)
/*  f0ff010:	3c017f1b */ 	lui	$at,%hi(var7f1b2cdc)
/*  f0ff014:	27190005 */ 	addiu	$t9,$t8,0x5
/*  f0ff018:	a4590002 */ 	sh	$t9,0x2($v0)
/*  f0ff01c:	c4262cdc */ 	lwc1	$f6,%lo(var7f1b2cdc)($at)
/*  f0ff020:	a0400034 */ 	sb	$zero,0x34($v0)
/*  f0ff024:	a0400033 */ 	sb	$zero,0x33($v0)
/*  f0ff028:	a0400032 */ 	sb	$zero,0x32($v0)
/*  f0ff02c:	e4460018 */ 	swc1	$f6,0x18($v0)
/*  f0ff030:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ff034:
/*  f0ff034:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0ff038:	03e00008 */ 	jr	$ra
/*  f0ff03c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ff040
/*  f0ff040:	3c0e800a */ 	lui	$t6,0x800a
/*  f0ff044:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f0ff048:	3c04800a */ 	lui	$a0,0x800a
/*  f0ff04c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0ff050:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0ff054:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0ff058:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0ff05c:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f0ff060:	908420de */ 	lbu	$a0,0x20de($a0)
/*  f0ff064:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0ff068:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ff06c:	10810003 */ 	beq	$a0,$at,.L0f0ff07c
/*  f0ff070:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff074:	0fc3f7c5 */ 	jal	func0f0fdf14
/*  f0ff078:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ff07c:
/*  f0ff07c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0ff080:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0ff084:	8c580284 */ 	lw	$t8,0x284($v0)
/*  f0ff088:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0ff08c:	3c018007 */ 	lui	$at,0x8007
/*  f0ff090:	a3000250 */ 	sb	$zero,0x250($t8)
/*  f0ff094:	8c480284 */ 	lw	$t0,0x284($v0)
/*  f0ff098:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0ff09c:	ad191c40 */ 	sw	$t9,0x1c40($t0)
/*  f0ff0a0:	8c4a028c */ 	lw	$t2,0x28c($v0)
/*  f0ff0a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ff0a8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0ff0ac:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f0ff0b0:	002b0821 */ 	addu	$at,$at,$t3
/*  f0ff0b4:	03e00008 */ 	jr	$ra
/*  f0ff0b8:	ac290750 */ 	sw	$t1,0x750($at)
);

GLOBAL_ASM(
glabel func0f0ff0bc
/*  f0ff0bc:	3c0e800a */ 	lui	$t6,0x800a
/*  f0ff0c0:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f0ff0c4:	3c02800a */ 	lui	$v0,0x800a
/*  f0ff0c8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0ff0cc:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0ff0d0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0ff0d4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0ff0d8:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f0ff0dc:	804220d0 */ 	lb	$v0,0x20d0($v0)
/*  f0ff0e0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ff0e4:	3c07800a */ 	lui	$a3,0x800a
/*  f0ff0e8:	2c580001 */ 	sltiu	$t8,$v0,0x1
/*  f0ff0ec:	13000020 */ 	beqz	$t8,.L0f0ff170
/*  f0ff0f0:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0ff0f4:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0ff0f8:	8c59006c */ 	lw	$t9,0x6c($v0)
/*  f0ff0fc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ff100:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ff104:	13200003 */ 	beqz	$t9,.L0f0ff114
/*  f0ff108:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ff10c:	10000001 */ 	beqz	$zero,.L0f0ff114
/*  f0ff110:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0ff114:
/*  f0ff114:	8c4b0068 */ 	lw	$t3,0x68($v0)
/*  f0ff118:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ff11c:	11600003 */ 	beqz	$t3,.L0f0ff12c
/*  f0ff120:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff124:	10000001 */ 	beqz	$zero,.L0f0ff12c
/*  f0ff128:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ff12c:
/*  f0ff12c:	8c4c0064 */ 	lw	$t4,0x64($v0)
/*  f0ff130:	11800003 */ 	beqz	$t4,.L0f0ff140
/*  f0ff134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff138:	10000001 */ 	beqz	$zero,.L0f0ff140
/*  f0ff13c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff140:
/*  f0ff140:	8c4d0070 */ 	lw	$t5,0x70($v0)
/*  f0ff144:	11a00003 */ 	beqz	$t5,.L0f0ff154
/*  f0ff148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff14c:	10000001 */ 	beqz	$zero,.L0f0ff154
/*  f0ff150:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ff154:
/*  f0ff154:	00657021 */ 	addu	$t6,$v1,$a1
/*  f0ff158:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f0ff15c:	01e61021 */ 	addu	$v0,$t7,$a2
/*  f0ff160:	28580003 */ 	slti	$t8,$v0,0x3
/*  f0ff164:	3b020001 */ 	xori	$v0,$t8,0x1
/*  f0ff168:	5440003f */ 	bnezl	$v0,.L0f0ff268
/*  f0ff16c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ff170:
/*  f0ff170:	3c028009 */ 	lui	$v0,0x8009
/*  f0ff174:	90420af0 */ 	lbu	$v0,0xaf0($v0)
/*  f0ff178:	3c08800a */ 	lui	$t0,0x800a
/*  f0ff17c:	3c09800a */ 	lui	$t1,0x800a
/*  f0ff180:	3c0a800a */ 	lui	$t2,0x800a
/*  f0ff184:	38590001 */ 	xori	$t9,$v0,0x1
/*  f0ff188:	8d4aa030 */ 	lw	$t2,-0x5fd0($t2)
/*  f0ff18c:	8d29a024 */ 	lw	$t1,-0x5fdc($t1)
/*  f0ff190:	8d08a028 */ 	lw	$t0,-0x5fd8($t0)
/*  f0ff194:	17200018 */ 	bnez	$t9,.L0f0ff1f8
/*  f0ff198:	8ce7a02c */ 	lw	$a3,-0x5fd4($a3)
/*  f0ff19c:	10e00003 */ 	beqz	$a3,.L0f0ff1ac
/*  f0ff1a0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ff1a4:	10000001 */ 	beqz	$zero,.L0f0ff1ac
/*  f0ff1a8:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0ff1ac:
/*  f0ff1ac:	11000003 */ 	beqz	$t0,.L0f0ff1bc
/*  f0ff1b0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ff1b4:	10000001 */ 	beqz	$zero,.L0f0ff1bc
/*  f0ff1b8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ff1bc:
/*  f0ff1bc:	11200003 */ 	beqz	$t1,.L0f0ff1cc
/*  f0ff1c0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ff1c4:	10000001 */ 	beqz	$zero,.L0f0ff1cc
/*  f0ff1c8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff1cc:
/*  f0ff1cc:	11400003 */ 	beqz	$t2,.L0f0ff1dc
/*  f0ff1d0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ff1d4:	10000001 */ 	beqz	$zero,.L0f0ff1dc
/*  f0ff1d8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ff1dc:
/*  f0ff1dc:	00655821 */ 	addu	$t3,$v1,$a1
/*  f0ff1e0:	01646021 */ 	addu	$t4,$t3,$a0
/*  f0ff1e4:	01861021 */ 	addu	$v0,$t4,$a2
/*  f0ff1e8:	384d0002 */ 	xori	$t5,$v0,0x2
/*  f0ff1ec:	2da20001 */ 	sltiu	$v0,$t5,0x1
/*  f0ff1f0:	5440001d */ 	bnezl	$v0,.L0f0ff268
/*  f0ff1f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ff1f8:
/*  f0ff1f8:	10e00003 */ 	beqz	$a3,.L0f0ff208
/*  f0ff1fc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ff200:	10000001 */ 	beqz	$zero,.L0f0ff208
/*  f0ff204:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0ff208:
/*  f0ff208:	11000003 */ 	beqz	$t0,.L0f0ff218
/*  f0ff20c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ff210:	10000001 */ 	beqz	$zero,.L0f0ff218
/*  f0ff214:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ff218:
/*  f0ff218:	11200003 */ 	beqz	$t1,.L0f0ff228
/*  f0ff21c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ff220:	10000001 */ 	beqz	$zero,.L0f0ff228
/*  f0ff224:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff228:
/*  f0ff228:	11400003 */ 	beqz	$t2,.L0f0ff238
/*  f0ff22c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ff230:	10000001 */ 	beqz	$zero,.L0f0ff238
/*  f0ff234:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ff238:
/*  f0ff238:	00657021 */ 	addu	$t6,$v1,$a1
/*  f0ff23c:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f0ff240:	01e61021 */ 	addu	$v0,$t7,$a2
/*  f0ff244:	38580002 */ 	xori	$t8,$v0,0x2
/*  f0ff248:	2f020001 */ 	sltiu	$v0,$t8,0x1
/*  f0ff24c:	50400006 */ 	beqzl	$v0,.L0f0ff268
/*  f0ff250:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ff254:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0ff258:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff25c:	38590001 */ 	xori	$t9,$v0,0x1
/*  f0ff260:	2f220001 */ 	sltiu	$v0,$t9,0x1
/*  f0ff264:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ff268:
/*  f0ff268:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0ff26c:	03e00008 */ 	jr	$ra
/*  f0ff270:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ff274
/*  f0ff274:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0ff278:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0ff27c:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f0ff280:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0ff284:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ff288:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f0ff28c:	11c00003 */ 	beqz	$t6,.L0f0ff29c
/*  f0ff290:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0ff294:	10000002 */ 	beqz	$zero,.L0f0ff2a0
/*  f0ff298:	240a0001 */ 	addiu	$t2,$zero,0x1
.L0f0ff29c:
/*  f0ff29c:	00005025 */ 	or	$t2,$zero,$zero
.L0f0ff2a0:
/*  f0ff2a0:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f0ff2a4:	3c0c800a */ 	lui	$t4,%hi(g_ActiveMenuIndex)
/*  f0ff2a8:	258c21b8 */ 	addiu	$t4,$t4,%lo(g_ActiveMenuIndex)
/*  f0ff2ac:	51e00004 */ 	beqzl	$t7,.L0f0ff2c0
/*  f0ff2b0:	00004025 */ 	or	$t0,$zero,$zero
/*  f0ff2b4:	10000002 */ 	beqz	$zero,.L0f0ff2c0
/*  f0ff2b8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0ff2bc:	00004025 */ 	or	$t0,$zero,$zero
.L0f0ff2c0:
/*  f0ff2c0:	8c580064 */ 	lw	$t8,0x64($v0)
/*  f0ff2c4:	53000004 */ 	beqzl	$t8,.L0f0ff2d8
/*  f0ff2c8:	00004825 */ 	or	$t1,$zero,$zero
/*  f0ff2cc:	10000002 */ 	beqz	$zero,.L0f0ff2d8
/*  f0ff2d0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0ff2d4:	00004825 */ 	or	$t1,$zero,$zero
.L0f0ff2d8:
/*  f0ff2d8:	8c590070 */ 	lw	$t9,0x70($v0)
/*  f0ff2dc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ff2e0:	13200003 */ 	beqz	$t9,.L0f0ff2f0
/*  f0ff2e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff2e8:	10000001 */ 	beqz	$zero,.L0f0ff2f0
/*  f0ff2ec:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff2f0:
/*  f0ff2f0:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f0ff2f4:	240d0038 */ 	addiu	$t5,$zero,0x38
/*  f0ff2f8:	3c0b800a */ 	lui	$t3,%hi(g_ActiveMenuThings)
/*  f0ff2fc:	01cd0019 */ 	multu	$t6,$t5
/*  f0ff300:	256b20d0 */ 	addiu	$t3,$t3,%lo(g_ActiveMenuThings)
/*  f0ff304:	87a40042 */ 	lh	$a0,0x42($sp)
/*  f0ff308:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ff30c:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f0ff310:	00007812 */ 	mflo	$t7
/*  f0ff314:	016fc021 */ 	addu	$t8,$t3,$t7
/*  f0ff318:	87190002 */ 	lh	$t9,0x2($t8)
/*  f0ff31c:	03240019 */ 	multu	$t9,$a0
/*  f0ff320:	00007012 */ 	mflo	$t6
/*  f0ff324:	a4ce0000 */ 	sh	$t6,0x0($a2)
/*  f0ff328:	87a30046 */ 	lh	$v1,0x46($sp)
/*  f0ff32c:	00037880 */ 	sll	$t7,$v1,0x2
/*  f0ff330:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f0ff334:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0ff338:	01e37821 */ 	addu	$t7,$t7,$v1
/*  f0ff33c:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f0ff340:	25e3ffce */ 	addiu	$v1,$t7,-50
/*  f0ff344:	a4e30000 */ 	sh	$v1,0x0($a3)
/*  f0ff348:	87b80042 */ 	lh	$t8,0x42($sp)
/*  f0ff34c:	53010010 */ 	beql	$t8,$at,.L0f0ff390
/*  f0ff350:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0ff354:	5060000e */ 	beqzl	$v1,.L0f0ff390
/*  f0ff358:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0ff35c:	84d90000 */ 	lh	$t9,0x0($a2)
/*  f0ff360:	07210003 */ 	bgez	$t9,.L0f0ff370
/*  f0ff364:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0ff368:	27210001 */ 	addiu	$at,$t9,0x1
/*  f0ff36c:	00017043 */ 	sra	$t6,$at,0x1
.L0f0ff370:
/*  f0ff370:	a4ce0000 */ 	sh	$t6,0x0($a2)
/*  f0ff374:	84ef0000 */ 	lh	$t7,0x0($a3)
/*  f0ff378:	05e10003 */ 	bgez	$t7,.L0f0ff388
/*  f0ff37c:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f0ff380:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0ff384:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0ff388:
/*  f0ff388:	a4f80000 */ 	sh	$t8,0x0($a3)
/*  f0ff38c:	afa3001c */ 	sw	$v1,0x1c($sp)
.L0f0ff390:
/*  f0ff390:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0ff394:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0ff398:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0ff39c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0ff3a0:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f0ff3a4:	afa90030 */ 	sw	$t1,0x30($sp)
/*  f0ff3a8:	0fc3fc2f */ 	jal	func0f0ff0bc
/*  f0ff3ac:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f0ff3b0:	3c0b800a */ 	lui	$t3,%hi(g_ActiveMenuThings)
/*  f0ff3b4:	3c0c800a */ 	lui	$t4,%hi(g_ActiveMenuIndex)
/*  f0ff3b8:	258c21b8 */ 	addiu	$t4,$t4,%lo(g_ActiveMenuIndex)
/*  f0ff3bc:	256b20d0 */ 	addiu	$t3,$t3,%lo(g_ActiveMenuThings)
/*  f0ff3c0:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0ff3c4:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0ff3c8:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f0ff3cc:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ff3d0:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0ff3d4:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f0ff3d8:	8fa90030 */ 	lw	$t1,0x30($sp)
/*  f0ff3dc:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f0ff3e0:	10400029 */ 	beqz	$v0,.L0f0ff488
/*  f0ff3e4:	240d0038 */ 	addiu	$t5,$zero,0x38
/*  f0ff3e8:	14600002 */ 	bnez	$v1,.L0f0ff3f4
/*  f0ff3ec:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0ff3f0:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f0ff3f4:
/*  f0ff3f4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ff3f8:	54810012 */ 	bnel	$a0,$at,.L0f0ff444
/*  f0ff3fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ff400:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f0ff404:	032d0019 */ 	multu	$t9,$t5
/*  f0ff408:	00007012 */ 	mflo	$t6
/*  f0ff40c:	016e7821 */ 	addu	$t7,$t3,$t6
/*  f0ff410:	85f80004 */ 	lh	$t8,0x4($t7)
/*  f0ff414:	07010003 */ 	bgez	$t8,.L0f0ff424
/*  f0ff418:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0ff41c:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0ff420:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0ff424:
/*  f0ff424:	00197023 */ 	negu	$t6,$t9
/*  f0ff428:	01c27823 */ 	subu	$t7,$t6,$v0
/*  f0ff42c:	a4cf0000 */ 	sh	$t7,0x0($a2)
/*  f0ff430:	00a97021 */ 	addu	$t6,$a1,$t1
/*  f0ff434:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f0ff438:	10000043 */ 	beqz	$zero,.L0f0ff548
/*  f0ff43c:	01ea2021 */ 	addu	$a0,$t7,$t2
/*  f0ff440:	24010001 */ 	addiu	$at,$zero,0x1
.L0f0ff444:
/*  f0ff444:	5481000d */ 	bnel	$a0,$at,.L0f0ff47c
/*  f0ff448:	00a97021 */ 	addu	$t6,$a1,$t1
/*  f0ff44c:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f0ff450:	030d0019 */ 	multu	$t8,$t5
/*  f0ff454:	0000c812 */ 	mflo	$t9
/*  f0ff458:	01797021 */ 	addu	$t6,$t3,$t9
/*  f0ff45c:	85cf0004 */ 	lh	$t7,0x4($t6)
/*  f0ff460:	05e10003 */ 	bgez	$t7,.L0f0ff470
/*  f0ff464:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f0ff468:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0ff46c:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0ff470:
/*  f0ff470:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f0ff474:	a4d90000 */ 	sh	$t9,0x0($a2)
/*  f0ff478:	00a97021 */ 	addu	$t6,$a1,$t1
.L0f0ff47c:
/*  f0ff47c:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f0ff480:	10000031 */ 	beqz	$zero,.L0f0ff548
/*  f0ff484:	01ea2021 */ 	addu	$a0,$t7,$t2
.L0f0ff488:
/*  f0ff488:	00a9c021 */ 	addu	$t8,$a1,$t1
/*  f0ff48c:	0308c821 */ 	addu	$t9,$t8,$t0
/*  f0ff490:	032a2021 */ 	addu	$a0,$t9,$t2
/*  f0ff494:	28810002 */ 	slti	$at,$a0,0x2
/*  f0ff498:	54200016 */ 	bnezl	$at,.L0f0ff4f4
/*  f0ff49c:	28810003 */ 	slti	$at,$a0,0x3
/*  f0ff4a0:	5460002a */ 	bnezl	$v1,.L0f0ff54c
/*  f0ff4a4:	28810002 */ 	slti	$at,$a0,0x2
/*  f0ff4a8:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0ff4ac:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0ff4b0:	0fc3fc2f */ 	jal	func0f0ff0bc
/*  f0ff4b4:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0ff4b8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0ff4bc:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ff4c0:	14400021 */ 	bnez	$v0,.L0f0ff548
/*  f0ff4c4:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0ff4c8:	84ce0000 */ 	lh	$t6,0x0($a2)
/*  f0ff4cc:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0ff4d0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0ff4d4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0ff4d8:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f0ff4dc:	01e1001a */ 	div	$zero,$t7,$at
/*  f0ff4e0:	0000c012 */ 	mflo	$t8
/*  f0ff4e4:	a4d80000 */ 	sh	$t8,0x0($a2)
/*  f0ff4e8:	10000018 */ 	beqz	$zero,.L0f0ff54c
/*  f0ff4ec:	28810002 */ 	slti	$at,$a0,0x2
/*  f0ff4f0:	28810003 */ 	slti	$at,$a0,0x3
.L0f0ff4f4:
/*  f0ff4f4:	54200015 */ 	bnezl	$at,.L0f0ff54c
/*  f0ff4f8:	28810002 */ 	slti	$at,$a0,0x2
/*  f0ff4fc:	54600013 */ 	bnezl	$v1,.L0f0ff54c
/*  f0ff500:	28810002 */ 	slti	$at,$a0,0x2
/*  f0ff504:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0ff508:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0ff50c:	0fc3fc2f */ 	jal	func0f0ff0bc
/*  f0ff510:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0ff514:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0ff518:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ff51c:	1440000a */ 	bnez	$v0,.L0f0ff548
/*  f0ff520:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0ff524:	84d90000 */ 	lh	$t9,0x0($a2)
/*  f0ff528:	2401000e */ 	addiu	$at,$zero,0xe
/*  f0ff52c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0ff530:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0ff534:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f0ff538:	01c1001a */ 	div	$zero,$t6,$at
/*  f0ff53c:	00007812 */ 	mflo	$t7
/*  f0ff540:	a4cf0000 */ 	sh	$t7,0x0($a2)
/*  f0ff544:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ff548:
/*  f0ff548:	28810002 */ 	slti	$at,$a0,0x2
.L0f0ff54c:
/*  f0ff54c:	5420000b */ 	bnezl	$at,.L0f0ff57c
/*  f0ff550:	28810003 */ 	slti	$at,$a0,0x3
/*  f0ff554:	84f80000 */ 	lh	$t8,0x0($a3)
/*  f0ff558:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0ff55c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0ff560:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0ff564:	0321001a */ 	div	$zero,$t9,$at
/*  f0ff568:	00007012 */ 	mflo	$t6
/*  f0ff56c:	a4ee0000 */ 	sh	$t6,0x0($a3)
/*  f0ff570:	1000000d */ 	beqz	$zero,.L0f0ff5a8
/*  f0ff574:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0ff578:	28810003 */ 	slti	$at,$a0,0x3
.L0f0ff57c:
/*  f0ff57c:	5420000a */ 	bnezl	$at,.L0f0ff5a8
/*  f0ff580:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0ff584:	84ef0000 */ 	lh	$t7,0x0($a3)
/*  f0ff588:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0ff58c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0ff590:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0ff594:	0301001a */ 	div	$zero,$t8,$at
/*  f0ff598:	0000c812 */ 	mflo	$t9
/*  f0ff59c:	a4f90000 */ 	sh	$t9,0x0($a3)
/*  f0ff5a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff5a4:	afa40020 */ 	sw	$a0,0x20($sp)
.L0f0ff5a8:
/*  f0ff5a8:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0ff5ac:	0c002f22 */ 	jal	func0000bc88
/*  f0ff5b0:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0ff5b4:	0c002f40 */ 	jal	func0000bd00
/*  f0ff5b8:	a7a20024 */ 	sh	$v0,0x24($sp)
/*  f0ff5bc:	3c038008 */ 	lui	$v1,0x8008
/*  f0ff5c0:	8c63fac0 */ 	lw	$v1,-0x540($v1)
/*  f0ff5c4:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ff5c8:	87b90024 */ 	lh	$t9,0x24($sp)
/*  f0ff5cc:	0043001a */ 	div	$zero,$v0,$v1
/*  f0ff5d0:	84ce0000 */ 	lh	$t6,0x0($a2)
/*  f0ff5d4:	00007812 */ 	mflo	$t7
/*  f0ff5d8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0ff5dc:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0ff5e0:	00037040 */ 	sll	$t6,$v1,0x1
/*  f0ff5e4:	032e001a */ 	div	$zero,$t9,$t6
/*  f0ff5e8:	00007812 */ 	mflo	$t7
/*  f0ff5ec:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0ff5f0:	14600002 */ 	bnez	$v1,.L0f0ff5fc
/*  f0ff5f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff5f8:	0007000d */ 	break	0x7
.L0f0ff5fc:
/*  f0ff5fc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ff600:	14610004 */ 	bne	$v1,$at,.L0f0ff614
/*  f0ff604:	3c018000 */ 	lui	$at,0x8000
/*  f0ff608:	14410002 */ 	bne	$v0,$at,.L0f0ff614
/*  f0ff60c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff610:	0006000d */ 	break	0x6
.L0f0ff614:
/*  f0ff614:	15c00002 */ 	bnez	$t6,.L0f0ff620
/*  f0ff618:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff61c:	0007000d */ 	break	0x7
.L0f0ff620:
/*  f0ff620:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ff624:	15c10004 */ 	bne	$t6,$at,.L0f0ff638
/*  f0ff628:	3c018000 */ 	lui	$at,0x8000
/*  f0ff62c:	17210002 */ 	bne	$t9,$at,.L0f0ff638
/*  f0ff630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff634:	0006000d */ 	break	0x6
.L0f0ff638:
/*  f0ff638:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f0ff63c:	0c002f26 */ 	jal	func0000bc98
/*  f0ff640:	a4d90000 */ 	sh	$t9,0x0($a2)
/*  f0ff644:	0c002f44 */ 	jal	func0000bd10
/*  f0ff648:	a7a20024 */ 	sh	$v0,0x24($sp)
/*  f0ff64c:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0ff650:	87af0024 */ 	lh	$t7,0x24($sp)
/*  f0ff654:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0ff658:	84ee0000 */ 	lh	$t6,0x0($a3)
/*  f0ff65c:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ff660:	01c2c021 */ 	addu	$t8,$t6,$v0
/*  f0ff664:	05e10003 */ 	bgez	$t7,.L0f0ff674
/*  f0ff668:	000fc843 */ 	sra	$t9,$t7,0x1
/*  f0ff66c:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0ff670:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0ff674:
/*  f0ff674:	03197021 */ 	addu	$t6,$t8,$t9
/*  f0ff678:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0ff67c:	1481000b */ 	bne	$a0,$at,.L0f0ff6ac
/*  f0ff680:	a4ee0000 */ 	sh	$t6,0x0($a3)
/*  f0ff684:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0ff688:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0ff68c:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0ff690:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0ff694:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0ff698:	10620006 */ 	beq	$v1,$v0,.L0f0ff6b4
/*  f0ff69c:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ff6a0:	3c0f8009 */ 	lui	$t7,0x8009
/*  f0ff6a4:	91ef0af0 */ 	lbu	$t7,0xaf0($t7)
/*  f0ff6a8:	106f0002 */ 	beq	$v1,$t7,.L0f0ff6b4
.L0f0ff6ac:
/*  f0ff6ac:	28810003 */ 	slti	$at,$a0,0x3
/*  f0ff6b0:	1420000c */ 	bnez	$at,.L0f0ff6e4
.L0f0ff6b4:
/*  f0ff6b4:	3c18800a */ 	lui	$t8,0x800a
/*  f0ff6b8:	8f18a24c */ 	lw	$t8,-0x5db4($t8)
/*  f0ff6bc:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0ff6c0:	57200006 */ 	bnezl	$t9,.L0f0ff6dc
/*  f0ff6c4:	84d80000 */ 	lh	$t8,0x0($a2)
/*  f0ff6c8:	84ce0000 */ 	lh	$t6,0x0($a2)
/*  f0ff6cc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0ff6d0:	10000004 */ 	beqz	$zero,.L0f0ff6e4
/*  f0ff6d4:	a4cf0000 */ 	sh	$t7,0x0($a2)
/*  f0ff6d8:	84d80000 */ 	lh	$t8,0x0($a2)
.L0f0ff6dc:
/*  f0ff6dc:	2719fff8 */ 	addiu	$t9,$t8,-8
/*  f0ff6e0:	a4d90000 */ 	sh	$t9,0x0($a2)
.L0f0ff6e4:
/*  f0ff6e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ff6e8:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0ff6ec:	03e00008 */ 	jr	$ra
/*  f0ff6f0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ff6f4
/*  f0ff6f4:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0ff6f8:	3c0e800a */ 	lui	$t6,0x800a
/*  f0ff6fc:	8dce21b4 */ 	lw	$t6,0x21b4($t6)
/*  f0ff700:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0ff704:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0ff708:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f0ff70c:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f0ff710:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0ff714:	3c07800a */ 	lui	$a3,0x800a
/*  f0ff718:	8ce721b0 */ 	lw	$a3,0x21b0($a3)
/*  f0ff71c:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0ff720:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f0ff724:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f0ff728:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ff72c:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ff730:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ff734:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0ff738:	87af0056 */ 	lh	$t7,0x56($sp)
/*  f0ff73c:	87a9005a */ 	lh	$t1,0x5a($sp)
/*  f0ff740:	3c0b800a */ 	lui	$t3,0x800a
/*  f0ff744:	3c0c800a */ 	lui	$t4,0x800a
/*  f0ff748:	07010003 */ 	bgez	$t8,.L0f0ff758
/*  f0ff74c:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0ff750:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0ff754:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0ff758:
/*  f0ff758:	8d8c21b4 */ 	lw	$t4,0x21b4($t4)
/*  f0ff75c:	8d6b21b0 */ 	lw	$t3,0x21b0($t3)
/*  f0ff760:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f0ff764:	241800f0 */ 	addiu	$t8,$zero,0xf0
/*  f0ff768:	240e0140 */ 	addiu	$t6,$zero,0x140
/*  f0ff76c:	01f94023 */ 	subu	$t0,$t7,$t9
/*  f0ff770:	252afffc */ 	addiu	$t2,$t1,-4
/*  f0ff774:	afa80044 */ 	sw	$t0,0x44($sp)
/*  f0ff778:	afaa0040 */ 	sw	$t2,0x40($sp)
/*  f0ff77c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0ff780:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0ff784:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0ff788:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0ff78c:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0ff790:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0ff794:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ff798:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ff79c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0ff7a0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ff7a4:	0fc5580f */ 	jal	func0f15603c
/*  f0ff7a8:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0ff7ac:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0ff7b0:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0ff7b4:	03e00008 */ 	jr	$ra
/*  f0ff7b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ff7bc
/*  f0ff7bc:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0ff7c0:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0ff7c4:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0ff7c8:	8d4e006c */ 	lw	$t6,0x6c($t2)
/*  f0ff7cc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0ff7d0:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0ff7d4:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0ff7d8:	afa00078 */ 	sw	$zero,0x78($sp)
/*  f0ff7dc:	11c00003 */ 	beqz	$t6,.L0f0ff7ec
/*  f0ff7e0:	afa00074 */ 	sw	$zero,0x74($sp)
/*  f0ff7e4:	10000002 */ 	beqz	$zero,.L0f0ff7f0
/*  f0ff7e8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff7ec:
/*  f0ff7ec:	00002825 */ 	or	$a1,$zero,$zero
.L0f0ff7f0:
/*  f0ff7f0:	8d4f0068 */ 	lw	$t7,0x68($t2)
/*  f0ff7f4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ff7f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ff7fc:	11e00003 */ 	beqz	$t7,.L0f0ff80c
/*  f0ff800:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff804:	10000001 */ 	beqz	$zero,.L0f0ff80c
/*  f0ff808:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ff80c:
/*  f0ff80c:	8d580064 */ 	lw	$t8,0x64($t2)
/*  f0ff810:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ff814:	13000003 */ 	beqz	$t8,.L0f0ff824
/*  f0ff818:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff81c:	10000001 */ 	beqz	$zero,.L0f0ff824
/*  f0ff820:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ff824:
/*  f0ff824:	8d590070 */ 	lw	$t9,0x70($t2)
/*  f0ff828:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ff82c:	13200003 */ 	beqz	$t9,.L0f0ff83c
/*  f0ff830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff834:	10000001 */ 	beqz	$zero,.L0f0ff83c
/*  f0ff838:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0ff83c:
/*  f0ff83c:	00435821 */ 	addu	$t3,$v0,$v1
/*  f0ff840:	01646021 */ 	addu	$t4,$t3,$a0
/*  f0ff844:	01856821 */ 	addu	$t5,$t4,$a1
/*  f0ff848:	15a10006 */ 	bne	$t5,$at,.L0f0ff864
/*  f0ff84c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff850:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0ff854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff858:	10400002 */ 	beqz	$v0,.L0f0ff864
/*  f0ff85c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0ff860:	afae0074 */ 	sw	$t6,0x74($sp)
.L0f0ff864:
/*  f0ff864:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0ff868:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0ff86c:	8d46006c */ 	lw	$a2,0x6c($t2)
/*  f0ff870:	8d470068 */ 	lw	$a3,0x68($t2)
/*  f0ff874:	8d480064 */ 	lw	$t0,0x64($t2)
/*  f0ff878:	10c00003 */ 	beqz	$a2,.L0f0ff888
/*  f0ff87c:	8d490070 */ 	lw	$t1,0x70($t2)
/*  f0ff880:	10000002 */ 	beqz	$zero,.L0f0ff88c
/*  f0ff884:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff888:
/*  f0ff888:	00002825 */ 	or	$a1,$zero,$zero
.L0f0ff88c:
/*  f0ff88c:	10e00003 */ 	beqz	$a3,.L0f0ff89c
/*  f0ff890:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0ff894:	10000002 */ 	beqz	$zero,.L0f0ff8a0
/*  f0ff898:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ff89c:
/*  f0ff89c:	00002025 */ 	or	$a0,$zero,$zero
.L0f0ff8a0:
/*  f0ff8a0:	11000003 */ 	beqz	$t0,.L0f0ff8b0
/*  f0ff8a4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ff8a8:	10000001 */ 	beqz	$zero,.L0f0ff8b0
/*  f0ff8ac:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ff8b0:
/*  f0ff8b0:	11200003 */ 	beqz	$t1,.L0f0ff8c0
/*  f0ff8b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ff8b8:	10000001 */ 	beqz	$zero,.L0f0ff8c0
/*  f0ff8bc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0ff8c0:
/*  f0ff8c0:	00437821 */ 	addu	$t7,$v0,$v1
/*  f0ff8c4:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f0ff8c8:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f0ff8cc:	17210013 */ 	bne	$t9,$at,.L0f0ff91c
/*  f0ff8d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff8d4:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0ff8d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff8dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ff8e0:	10410024 */ 	beq	$v0,$at,.L0f0ff974
/*  f0ff8e4:	3c0b8009 */ 	lui	$t3,0x8009
/*  f0ff8e8:	916b0af0 */ 	lbu	$t3,0xaf0($t3)
/*  f0ff8ec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ff8f0:	3c06800a */ 	lui	$a2,0x800a
/*  f0ff8f4:	1161001f */ 	beq	$t3,$at,.L0f0ff974
/*  f0ff8f8:	3c07800a */ 	lui	$a3,0x800a
/*  f0ff8fc:	3c08800a */ 	lui	$t0,0x800a
/*  f0ff900:	3c09800a */ 	lui	$t1,0x800a
/*  f0ff904:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0ff908:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0ff90c:	8d29a030 */ 	lw	$t1,-0x5fd0($t1)
/*  f0ff910:	8d08a024 */ 	lw	$t0,-0x5fdc($t0)
/*  f0ff914:	8cc6a02c */ 	lw	$a2,-0x5fd4($a2)
/*  f0ff918:	8ce7a028 */ 	lw	$a3,-0x5fd8($a3)
.L0f0ff91c:
/*  f0ff91c:	10c00003 */ 	beqz	$a2,.L0f0ff92c
/*  f0ff920:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ff924:	10000001 */ 	beqz	$zero,.L0f0ff92c
/*  f0ff928:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ff92c:
/*  f0ff92c:	10e00003 */ 	beqz	$a3,.L0f0ff93c
/*  f0ff930:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ff934:	10000001 */ 	beqz	$zero,.L0f0ff93c
/*  f0ff938:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ff93c:
/*  f0ff93c:	11000003 */ 	beqz	$t0,.L0f0ff94c
/*  f0ff940:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ff944:	10000001 */ 	beqz	$zero,.L0f0ff94c
/*  f0ff948:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ff94c:
/*  f0ff94c:	11200003 */ 	beqz	$t1,.L0f0ff95c
/*  f0ff950:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ff954:	10000001 */ 	beqz	$zero,.L0f0ff95c
/*  f0ff958:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0ff95c:
/*  f0ff95c:	00446021 */ 	addu	$t4,$v0,$a0
/*  f0ff960:	01836821 */ 	addu	$t5,$t4,$v1
/*  f0ff964:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f0ff968:	29c10003 */ 	slti	$at,$t6,0x3
/*  f0ff96c:	1420000c */ 	bnez	$at,.L0f0ff9a0
/*  f0ff970:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ff974:
/*  f0ff974:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0ff978:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0ff97c:	8d4f028c */ 	lw	$t7,0x28c($t2)
/*  f0ff980:	24190008 */ 	addiu	$t9,$zero,0x8
/*  f0ff984:	240bfff8 */ 	addiu	$t3,$zero,-8
/*  f0ff988:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f0ff98c:	57000004 */ 	bnezl	$t8,.L0f0ff9a0
/*  f0ff990:	afab0078 */ 	sw	$t3,0x78($sp)
/*  f0ff994:	10000002 */ 	beqz	$zero,.L0f0ff9a0
/*  f0ff998:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f0ff99c:	afab0078 */ 	sw	$t3,0x78($sp)
.L0f0ff9a0:
/*  f0ff9a0:	3c0c800a */ 	lui	$t4,0x800a
/*  f0ff9a4:	8d8c21b8 */ 	lw	$t4,0x21b8($t4)
/*  f0ff9a8:	3c0e800a */ 	lui	$t6,0x800a
/*  f0ff9ac:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f0ff9b0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0ff9b4:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0ff9b8:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0ff9bc:	91ce2102 */ 	lbu	$t6,0x2102($t6)
/*  f0ff9c0:	15c00142 */ 	bnez	$t6,.L0f0ffecc
/*  f0ff9c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ff9c8:	8d4f0284 */ 	lw	$t7,0x284($t2)
/*  f0ff9cc:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0ff9d0:	3c0c800b */ 	lui	$t4,0x800b
/*  f0ff9d4:	3c0d800b */ 	lui	$t5,%hi(g_MpPlayerChrs)
/*  f0ff9d8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0ff9dc:	932b1be7 */ 	lbu	$t3,0x1be7($t9)
/*  f0ff9e0:	25adc4d0 */ 	addiu	$t5,$t5,%lo(g_MpPlayerChrs)
/*  f0ff9e4:	000b1080 */ 	sll	$v0,$t3,0x2
/*  f0ff9e8:	01826021 */ 	addu	$t4,$t4,$v0
/*  f0ff9ec:	8d8cc500 */ 	lw	$t4,-0x3b00($t4)
/*  f0ff9f0:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0ff9f4:	afae0048 */ 	sw	$t6,0x48($sp)
/*  f0ff9f8:	afab009c */ 	sw	$t3,0x9c($sp)
/*  f0ff9fc:	afac007c */ 	sw	$t4,0x7c($sp)
/*  f0ffa00:	8dd80000 */ 	lw	$t8,0x0($t6)
/*  f0ffa04:	8f0302d4 */ 	lw	$v1,0x2d4($t8)
/*  f0ffa08:	50600004 */ 	beqzl	$v1,.L0f0ffa1c
/*  f0ffa0c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ffa10:	10000002 */ 	beqz	$zero,.L0f0ffa1c
/*  f0ffa14:	8c640020 */ 	lw	$a0,0x20($v1)
/*  f0ffa18:	00002025 */ 	or	$a0,$zero,$zero
.L0f0ffa1c:
/*  f0ffa1c:	28810002 */ 	slti	$at,$a0,0x2
/*  f0ffa20:	14200003 */ 	bnez	$at,.L0f0ffa30
/*  f0ffa24:	28810033 */ 	slti	$at,$a0,0x33
/*  f0ffa28:	14200005 */ 	bnez	$at,.L0f0ffa40
/*  f0ffa2c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ffa30:
/*  f0ffa30:	0fc5b9f1 */ 	jal	langGet
/*  f0ffa34:	240458ad */ 	addiu	$a0,$zero,0x58ad
/*  f0ffa38:	10000004 */ 	beqz	$zero,.L0f0ffa4c
/*  f0ffa3c:	afa20080 */ 	sw	$v0,0x80($sp)
.L0f0ffa40:
/*  f0ffa40:	0fc28874 */ 	jal	func0f0a21d0
/*  f0ffa44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffa48:	afa20080 */ 	sw	$v0,0x80($sp)
.L0f0ffa4c:
/*  f0ffa4c:	3c19800a */ 	lui	$t9,0x800a
/*  f0ffa50:	8f3921b4 */ 	lw	$t9,0x21b4($t9)
/*  f0ffa54:	3c07800a */ 	lui	$a3,0x800a
/*  f0ffa58:	8ce721b0 */ 	lw	$a3,0x21b0($a3)
/*  f0ffa5c:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f0ffa60:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0ffa64:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ffa68:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ffa6c:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ffa70:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ffa74:	0c002f40 */ 	jal	func0000bd00
/*  f0ffa78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffa7c:	0c002f22 */ 	jal	func0000bc88
/*  f0ffa80:	a7a2004e */ 	sh	$v0,0x4e($sp)
/*  f0ffa84:	3c038008 */ 	lui	$v1,0x8008
/*  f0ffa88:	8c63fac0 */ 	lw	$v1,-0x540($v1)
/*  f0ffa8c:	87ae004e */ 	lh	$t6,0x4e($sp)
/*  f0ffa90:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f0ffa94:	0043001a */ 	div	$zero,$v0,$v1
/*  f0ffa98:	00005812 */ 	mflo	$t3
/*  f0ffa9c:	448b2000 */ 	mtc1	$t3,$f4
/*  f0ffaa0:	44998000 */ 	mtc1	$t9,$f16
/*  f0ffaa4:	01c3001a */ 	div	$zero,$t6,$v1
/*  f0ffaa8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ffaac:	3c013f00 */ 	lui	$at,0x3f00
/*  f0ffab0:	44810000 */ 	mtc1	$at,$f0
/*  f0ffab4:	00007812 */ 	mflo	$t7
/*  f0ffab8:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0ffabc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ffac0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ffac4:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0ffac8:	14600002 */ 	bnez	$v1,.L0f0ffad4
/*  f0ffacc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffad0:	0007000d */ 	break	0x7
.L0f0ffad4:
/*  f0ffad4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ffad8:	14610004 */ 	bne	$v1,$at,.L0f0ffaec
/*  f0ffadc:	3c018000 */ 	lui	$at,0x8000
/*  f0ffae0:	14410002 */ 	bne	$v0,$at,.L0f0ffaec
/*  f0ffae4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffae8:	0006000d */ 	break	0x6
.L0f0ffaec:
/*  f0ffaec:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0ffaf0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ffaf4:	8cd9006c */ 	lw	$t9,0x6c($a2)
/*  f0ffaf8:	440d5000 */ 	mfc1	$t5,$f10
/*  f0ffafc:	14600002 */ 	bnez	$v1,.L0f0ffb08
/*  f0ffb00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffb04:	0007000d */ 	break	0x7
.L0f0ffb08:
/*  f0ffb08:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ffb0c:	14610004 */ 	bne	$v1,$at,.L0f0ffb20
/*  f0ffb10:	3c018000 */ 	lui	$at,0x8000
/*  f0ffb14:	15c10002 */ 	bne	$t6,$at,.L0f0ffb20
/*  f0ffb18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffb1c:	0006000d */ 	break	0x6
.L0f0ffb20:
/*  f0ffb20:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0ffb24:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0ffb28:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f0ffb2c:	440c3000 */ 	mfc1	$t4,$f6
/*  f0ffb30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffb34:	030c7023 */ 	subu	$t6,$t8,$t4
/*  f0ffb38:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0ffb3c:	13200003 */ 	beqz	$t9,.L0f0ffb4c
/*  f0ffb40:	afaf0094 */ 	sw	$t7,0x94($sp)
/*  f0ffb44:	10000002 */ 	beqz	$zero,.L0f0ffb50
/*  f0ffb48:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ffb4c:
/*  f0ffb4c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0ffb50:
/*  f0ffb50:	8ccb0068 */ 	lw	$t3,0x68($a2)
/*  f0ffb54:	51600004 */ 	beqzl	$t3,.L0f0ffb68
/*  f0ffb58:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ffb5c:	10000002 */ 	beqz	$zero,.L0f0ffb68
/*  f0ffb60:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ffb64:	00002025 */ 	or	$a0,$zero,$zero
.L0f0ffb68:
/*  f0ffb68:	8cd80064 */ 	lw	$t8,0x64($a2)
/*  f0ffb6c:	53000004 */ 	beqzl	$t8,.L0f0ffb80
/*  f0ffb70:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ffb74:	10000002 */ 	beqz	$zero,.L0f0ffb80
/*  f0ffb78:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0ffb7c:	00001825 */ 	or	$v1,$zero,$zero
.L0f0ffb80:
/*  f0ffb80:	8ccc0070 */ 	lw	$t4,0x70($a2)
/*  f0ffb84:	51800004 */ 	beqzl	$t4,.L0f0ffb98
/*  f0ffb88:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ffb8c:	10000002 */ 	beqz	$zero,.L0f0ffb98
/*  f0ffb90:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0ffb94:	00001025 */ 	or	$v0,$zero,$zero
.L0f0ffb98:
/*  f0ffb98:	00437021 */ 	addu	$t6,$v0,$v1
/*  f0ffb9c:	01c46821 */ 	addu	$t5,$t6,$a0
/*  f0ffba0:	01a57821 */ 	addu	$t7,$t5,$a1
/*  f0ffba4:	29e10002 */ 	slti	$at,$t7,0x2
/*  f0ffba8:	14200006 */ 	bnez	$at,.L0f0ffbc4
/*  f0ffbac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffbb0:	0c002f44 */ 	jal	func0000bd10
/*  f0ffbb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffbb8:	24590005 */ 	addiu	$t9,$v0,0x5
/*  f0ffbbc:	10000005 */ 	beqz	$zero,.L0f0ffbd4
/*  f0ffbc0:	afb90090 */ 	sw	$t9,0x90($sp)
.L0f0ffbc4:
/*  f0ffbc4:	0c002f44 */ 	jal	func0000bd10
/*  f0ffbc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffbcc:	244b000a */ 	addiu	$t3,$v0,0xa
/*  f0ffbd0:	afab0090 */ 	sw	$t3,0x90($sp)
.L0f0ffbd4:
/*  f0ffbd4:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0ffbd8:	13000012 */ 	beqz	$t8,.L0f0ffc24
/*  f0ffbdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffbe0:	0c002f40 */ 	jal	func0000bd00
/*  f0ffbe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffbe8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0ffbec:	8d8cfac0 */ 	lw	$t4,-0x540($t4)
/*  f0ffbf0:	004c001a */ 	div	$zero,$v0,$t4
/*  f0ffbf4:	00007012 */ 	mflo	$t6
/*  f0ffbf8:	25cd0020 */ 	addiu	$t5,$t6,0x20
/*  f0ffbfc:	afad0094 */ 	sw	$t5,0x94($sp)
/*  f0ffc00:	15800002 */ 	bnez	$t4,.L0f0ffc0c
/*  f0ffc04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffc08:	0007000d */ 	break	0x7
.L0f0ffc0c:
/*  f0ffc0c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ffc10:	15810004 */ 	bne	$t4,$at,.L0f0ffc24
/*  f0ffc14:	3c018000 */ 	lui	$at,0x8000
/*  f0ffc18:	14410002 */ 	bne	$v0,$at,.L0f0ffc24
/*  f0ffc1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffc20:	0006000d */ 	break	0x6
.L0f0ffc24:
/*  f0ffc24:	3c0f800a */ 	lui	$t7,0x800a
/*  f0ffc28:	3c19800a */ 	lui	$t9,0x800a
/*  f0ffc2c:	8f3921b4 */ 	lw	$t9,0x21b4($t9)
/*  f0ffc30:	8def21b0 */ 	lw	$t7,0x21b0($t7)
/*  f0ffc34:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0ffc38:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f0ffc3c:	240c0140 */ 	addiu	$t4,$zero,0x140
/*  f0ffc40:	240e00f0 */ 	addiu	$t6,$zero,0xf0
/*  f0ffc44:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f0ffc48:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0ffc4c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0ffc50:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0ffc54:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0ffc58:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0ffc5c:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0ffc60:	8fa7007c */ 	lw	$a3,0x7c($sp)
/*  f0ffc64:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ffc68:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0ffc6c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0ffc70:	0fc55b92 */ 	jal	func0f156e48
/*  f0ffc74:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ffc78:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ffc7c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ffc80:	8d0d006c */ 	lw	$t5,0x6c($t0)
/*  f0ffc84:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0ffc88:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ffc8c:	11a00003 */ 	beqz	$t5,.L0f0ffc9c
/*  f0ffc90:	3c07800a */ 	lui	$a3,0x800a
/*  f0ffc94:	10000001 */ 	beqz	$zero,.L0f0ffc9c
/*  f0ffc98:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0ffc9c:
/*  f0ffc9c:	8d0f0068 */ 	lw	$t7,0x68($t0)
/*  f0ffca0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ffca4:	11e00003 */ 	beqz	$t7,.L0f0ffcb4
/*  f0ffca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffcac:	10000001 */ 	beqz	$zero,.L0f0ffcb4
/*  f0ffcb0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ffcb4:
/*  f0ffcb4:	8d190064 */ 	lw	$t9,0x64($t0)
/*  f0ffcb8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ffcbc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ffcc0:	13200003 */ 	beqz	$t9,.L0f0ffcd0
/*  f0ffcc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffcc8:	10000001 */ 	beqz	$zero,.L0f0ffcd0
/*  f0ffccc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ffcd0:
/*  f0ffcd0:	8d0b0070 */ 	lw	$t3,0x70($t0)
/*  f0ffcd4:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f0ffcd8:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f0ffcdc:	11600003 */ 	beqz	$t3,.L0f0ffcec
/*  f0ffce0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffce4:	10000001 */ 	beqz	$zero,.L0f0ffcec
/*  f0ffce8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ffcec:
/*  f0ffcec:	0064c021 */ 	addu	$t8,$v1,$a0
/*  f0ffcf0:	03056021 */ 	addu	$t4,$t8,$a1
/*  f0ffcf4:	01827021 */ 	addu	$t6,$t4,$v0
/*  f0ffcf8:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0ffcfc:	14200003 */ 	bnez	$at,.L0f0ffd0c
/*  f0ffd00:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f0ffd04:	10000009 */ 	beqz	$zero,.L0f0ffd2c
/*  f0ffd08:	00001025 */ 	or	$v0,$zero,$zero
.L0f0ffd0c:
/*  f0ffd0c:	448d4000 */ 	mtc1	$t5,$f8
/*  f0ffd10:	3c017f1b */ 	lui	$at,%hi(var7f1b2ce0)
/*  f0ffd14:	c4302ce0 */ 	lwc1	$f16,%lo(var7f1b2ce0)($at)
/*  f0ffd18:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ffd1c:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0ffd20:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0ffd24:	44022000 */ 	mfc1	$v0,$f4
/*  f0ffd28:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ffd2c:
/*  f0ffd2c:	3c18800a */ 	lui	$t8,0x800a
/*  f0ffd30:	8f1821b4 */ 	lw	$t8,0x21b4($t8)
/*  f0ffd34:	03225821 */ 	addu	$t3,$t9,$v0
/*  f0ffd38:	afab0090 */ 	sw	$t3,0x90($sp)
/*  f0ffd3c:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0ffd40:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0ffd44:	8ce721b0 */ 	lw	$a3,0x21b0($a3)
/*  f0ffd48:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ffd4c:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ffd50:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ffd54:	0c002f40 */ 	jal	func0000bd00
/*  f0ffd58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffd5c:	0c002f22 */ 	jal	func0000bc88
/*  f0ffd60:	a7a2004e */ 	sh	$v0,0x4e($sp)
/*  f0ffd64:	3c038008 */ 	lui	$v1,0x8008
/*  f0ffd68:	8c63fac0 */ 	lw	$v1,-0x540($v1)
/*  f0ffd6c:	87af004e */ 	lh	$t7,0x4e($sp)
/*  f0ffd70:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f0ffd74:	0043001a */ 	div	$zero,$v0,$v1
/*  f0ffd78:	00006012 */ 	mflo	$t4
/*  f0ffd7c:	448c3000 */ 	mtc1	$t4,$f6
/*  f0ffd80:	44989000 */ 	mtc1	$t8,$f18
/*  f0ffd84:	01e3001a */ 	div	$zero,$t7,$v1
/*  f0ffd88:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0ffd8c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0ffd90:	44810000 */ 	mtc1	$at,$f0
/*  f0ffd94:	14600002 */ 	bnez	$v1,.L0f0ffda0
/*  f0ffd98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffd9c:	0007000d */ 	break	0x7
.L0f0ffda0:
/*  f0ffda0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ffda4:	14610004 */ 	bne	$v1,$at,.L0f0ffdb8
/*  f0ffda8:	3c018000 */ 	lui	$at,0x8000
/*  f0ffdac:	14410002 */ 	bne	$v0,$at,.L0f0ffdb8
/*  f0ffdb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffdb4:	0006000d */ 	break	0x6
.L0f0ffdb8:
/*  f0ffdb8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0ffdbc:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0ffdc0:	0000c812 */ 	mflo	$t9
/*  f0ffdc4:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0ffdc8:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0ffdcc:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0ffdd0:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0ffdd4:	440d8000 */ 	mfc1	$t5,$f16
/*  f0ffdd8:	14600002 */ 	bnez	$v1,.L0f0ffde4
/*  f0ffddc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffde0:	0007000d */ 	break	0x7
.L0f0ffde4:
/*  f0ffde4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ffde8:	14610004 */ 	bne	$v1,$at,.L0f0ffdfc
/*  f0ffdec:	3c018000 */ 	lui	$at,0x8000
/*  f0ffdf0:	15e10002 */ 	bne	$t7,$at,.L0f0ffdfc
/*  f0ffdf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffdf8:	0006000d */ 	break	0x6
.L0f0ffdfc:
/*  f0ffdfc:	440e4000 */ 	mfc1	$t6,$f8
/*  f0ffe00:	01b95821 */ 	addu	$t3,$t5,$t9
/*  f0ffe04:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f0ffe08:	016e7823 */ 	subu	$t7,$t3,$t6
/*  f0ffe0c:	01edc821 */ 	addu	$t9,$t7,$t5
/*  f0ffe10:	13000012 */ 	beqz	$t8,.L0f0ffe5c
/*  f0ffe14:	afb90094 */ 	sw	$t9,0x94($sp)
/*  f0ffe18:	0c002f40 */ 	jal	func0000bd00
/*  f0ffe1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffe20:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0ffe24:	8d8cfac0 */ 	lw	$t4,-0x540($t4)
/*  f0ffe28:	004c001a */ 	div	$zero,$v0,$t4
/*  f0ffe2c:	00005812 */ 	mflo	$t3
/*  f0ffe30:	256e0020 */ 	addiu	$t6,$t3,0x20
/*  f0ffe34:	afae0094 */ 	sw	$t6,0x94($sp)
/*  f0ffe38:	15800002 */ 	bnez	$t4,.L0f0ffe44
/*  f0ffe3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffe40:	0007000d */ 	break	0x7
.L0f0ffe44:
/*  f0ffe44:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ffe48:	15810004 */ 	bne	$t4,$at,.L0f0ffe5c
/*  f0ffe4c:	3c018000 */ 	lui	$at,0x8000
/*  f0ffe50:	14410002 */ 	bne	$v0,$at,.L0f0ffe5c
/*  f0ffe54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ffe58:	0006000d */ 	break	0x6
.L0f0ffe5c:
/*  f0ffe5c:	3c0f800a */ 	lui	$t7,0x800a
/*  f0ffe60:	3c0d800a */ 	lui	$t5,0x800a
/*  f0ffe64:	8dad21b4 */ 	lw	$t5,0x21b4($t5)
/*  f0ffe68:	8def21b0 */ 	lw	$t7,0x21b0($t7)
/*  f0ffe6c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0ffe70:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f0ffe74:	240c0140 */ 	addiu	$t4,$zero,0x140
/*  f0ffe78:	240b00f0 */ 	addiu	$t3,$zero,0xf0
/*  f0ffe7c:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f0ffe80:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0ffe84:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0ffe88:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0ffe8c:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0ffe90:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0ffe94:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0ffe98:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0ffe9c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ffea0:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0ffea4:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ffea8:	0fc55b92 */ 	jal	func0f156e48
/*  f0ffeac:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ffeb0:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0ffeb4:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0ffeb8:	3c0d800a */ 	lui	$t5,0x800a
/*  f0ffebc:	8dada244 */ 	lw	$t5,-0x5dbc($t5)
/*  f0ffec0:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f0ffec4:	10000093 */ 	beqz	$zero,.L0f100114
/*  f0ffec8:	adaf1c04 */ 	sw	$t7,0x1c04($t5)
.L0f0ffecc:
/*  f0ffecc:	0fc5b9f1 */ 	jal	langGet
/*  f0ffed0:	240458d7 */ 	addiu	$a0,$zero,0x58d7
/*  f0ffed4:	3c19800a */ 	lui	$t9,0x800a
/*  f0ffed8:	8f3921b4 */ 	lw	$t9,0x21b4($t9)
/*  f0ffedc:	3c07800a */ 	lui	$a3,0x800a
/*  f0ffee0:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f0ffee4:	8ce721b0 */ 	lw	$a3,0x21b0($a3)
/*  f0ffee8:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f0ffeec:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0ffef0:	00403025 */ 	or	$a2,$v0,$zero
/*  f0ffef4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ffef8:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ffefc:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0fff00:	0c002f40 */ 	jal	func0000bd00
/*  f0fff04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fff08:	0c002f22 */ 	jal	func0000bc88
/*  f0fff0c:	a7a2004e */ 	sh	$v0,0x4e($sp)
/*  f0fff10:	3c038008 */ 	lui	$v1,0x8008
/*  f0fff14:	8c63fac0 */ 	lw	$v1,-0x540($v1)
/*  f0fff18:	87ae004e */ 	lh	$t6,0x4e($sp)
/*  f0fff1c:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f0fff20:	0043001a */ 	div	$zero,$v0,$v1
/*  f0fff24:	0000c012 */ 	mflo	$t8
/*  f0fff28:	44985000 */ 	mtc1	$t8,$f10
/*  f0fff2c:	14600002 */ 	bnez	$v1,.L0f0fff38
/*  f0fff30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fff34:	0007000d */ 	break	0x7
.L0f0fff38:
/*  f0fff38:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fff3c:	14610004 */ 	bne	$v1,$at,.L0f0fff50
/*  f0fff40:	3c018000 */ 	lui	$at,0x8000
/*  f0fff44:	14410002 */ 	bne	$v0,$at,.L0f0fff50
/*  f0fff48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fff4c:	0006000d */ 	break	0x6
.L0f0fff50:
/*  f0fff50:	01c3001a */ 	div	$zero,$t6,$v1
/*  f0fff54:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0fff58:	3c013f00 */ 	lui	$at,0x3f00
/*  f0fff5c:	44819000 */ 	mtc1	$at,$f18
/*  f0fff60:	44994000 */ 	mtc1	$t9,$f8
/*  f0fff64:	00007812 */ 	mflo	$t7
/*  f0fff68:	3c19800a */ 	lui	$t9,0x800a
/*  f0fff6c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0fff70:	8f39a02c */ 	lw	$t9,-0x5fd4($t9)
/*  f0fff74:	3c18800a */ 	lui	$t8,0x800a
/*  f0fff78:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fff7c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fff80:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0fff84:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0fff88:	440b3000 */ 	mfc1	$t3,$f6
/*  f0fff8c:	14600002 */ 	bnez	$v1,.L0f0fff98
/*  f0fff90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fff94:	0007000d */ 	break	0x7
.L0f0fff98:
/*  f0fff98:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fff9c:	14610004 */ 	bne	$v1,$at,.L0f0fffb0
/*  f0fffa0:	3c018000 */ 	lui	$at,0x8000
/*  f0fffa4:	15c10002 */ 	bne	$t6,$at,.L0f0fffb0
/*  f0fffa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fffac:	0006000d */ 	break	0x6
.L0f0fffb0:
/*  f0fffb0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0fffb4:	44818000 */ 	mtc1	$at,$f16
/*  f0fffb8:	016f6821 */ 	addu	$t5,$t3,$t7
/*  f0fffbc:	8fab0078 */ 	lw	$t3,0x78($sp)
/*  f0fffc0:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0fffc4:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0fffc8:	440c2000 */ 	mfc1	$t4,$f4
/*  f0fffcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fffd0:	01ac7023 */ 	subu	$t6,$t5,$t4
/*  f0fffd4:	01cb7821 */ 	addu	$t7,$t6,$t3
/*  f0fffd8:	13200003 */ 	beqz	$t9,.L0f0fffe8
/*  f0fffdc:	afaf0094 */ 	sw	$t7,0x94($sp)
/*  f0fffe0:	10000001 */ 	beqz	$zero,.L0f0fffe8
/*  f0fffe4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0fffe8:
/*  f0fffe8:	8f18a028 */ 	lw	$t8,-0x5fd8($t8)
/*  f0fffec:	3c0d800a */ 	lui	$t5,0x800a
/*  f0ffff0:	3c0c800a */ 	lui	$t4,0x800a
/*  f0ffff4:	13000003 */ 	beqz	$t8,.L0f100004
/*  f0ffff8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ffffc:	10000001 */ 	beqz	$zero,.L0f100004
/*  f100000:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f100004:
/*  f100004:	8dada024 */ 	lw	$t5,-0x5fdc($t5)
/*  f100008:	00001025 */ 	or	$v0,$zero,$zero
/*  f10000c:	11a00003 */ 	beqz	$t5,.L0f10001c
/*  f100010:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100014:	10000001 */ 	beqz	$zero,.L0f10001c
/*  f100018:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f10001c:
/*  f10001c:	8d8ca030 */ 	lw	$t4,-0x5fd0($t4)
/*  f100020:	11800003 */ 	beqz	$t4,.L0f100030
/*  f100024:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100028:	10000001 */ 	beqz	$zero,.L0f100030
/*  f10002c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f100030:
/*  f100030:	00437021 */ 	addu	$t6,$v0,$v1
/*  f100034:	01c45821 */ 	addu	$t3,$t6,$a0
/*  f100038:	01657821 */ 	addu	$t7,$t3,$a1
/*  f10003c:	29e10002 */ 	slti	$at,$t7,0x2
/*  f100040:	14200006 */ 	bnez	$at,.L0f10005c
/*  f100044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100048:	0c002f44 */ 	jal	func0000bd10
/*  f10004c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100050:	24590005 */ 	addiu	$t9,$v0,0x5
/*  f100054:	10000005 */ 	beqz	$zero,.L0f10006c
/*  f100058:	afb90090 */ 	sw	$t9,0x90($sp)
.L0f10005c:
/*  f10005c:	0c002f44 */ 	jal	func0000bd10
/*  f100060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100064:	2458000a */ 	addiu	$t8,$v0,0xa
/*  f100068:	afb80090 */ 	sw	$t8,0x90($sp)
.L0f10006c:
/*  f10006c:	8fad0074 */ 	lw	$t5,0x74($sp)
/*  f100070:	11a00012 */ 	beqz	$t5,.L0f1000bc
/*  f100074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100078:	0c002f40 */ 	jal	func0000bd00
/*  f10007c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100080:	3c0c8008 */ 	lui	$t4,0x8008
/*  f100084:	8d8cfac0 */ 	lw	$t4,-0x540($t4)
/*  f100088:	004c001a */ 	div	$zero,$v0,$t4
/*  f10008c:	00007012 */ 	mflo	$t6
/*  f100090:	25cb0020 */ 	addiu	$t3,$t6,0x20
/*  f100094:	afab0094 */ 	sw	$t3,0x94($sp)
/*  f100098:	15800002 */ 	bnez	$t4,.L0f1000a4
/*  f10009c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1000a0:	0007000d */ 	break	0x7
.L0f1000a4:
/*  f1000a4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1000a8:	15810004 */ 	bne	$t4,$at,.L0f1000bc
/*  f1000ac:	3c018000 */ 	lui	$at,0x8000
/*  f1000b0:	14410002 */ 	bne	$v0,$at,.L0f1000bc
/*  f1000b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1000b8:	0006000d */ 	break	0x6
.L0f1000bc:
/*  f1000bc:	3c0f800a */ 	lui	$t7,0x800a
/*  f1000c0:	3c19800a */ 	lui	$t9,0x800a
/*  f1000c4:	8f3921b4 */ 	lw	$t9,0x21b4($t9)
/*  f1000c8:	8def21b0 */ 	lw	$t7,0x21b0($t7)
/*  f1000cc:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f1000d0:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f1000d4:	240c0140 */ 	addiu	$t4,$zero,0x140
/*  f1000d8:	240e00f0 */ 	addiu	$t6,$zero,0xf0
/*  f1000dc:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f1000e0:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f1000e4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1000e8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f1000ec:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f1000f0:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f1000f4:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f1000f8:	8fa70070 */ 	lw	$a3,0x70($sp)
/*  f1000fc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f100100:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f100104:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f100108:	0fc55b92 */ 	jal	func0f156e48
/*  f10010c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f100110:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f100114:
/*  f100114:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f100118:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f10011c:	27bd0098 */ 	addiu	$sp,$sp,0x98
/*  f100120:	03e00008 */ 	jr	$ra
/*  f100124:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f100128
/*  f100128:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f10012c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f100130:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f100134:	8d0e006c */ 	lw	$t6,0x6c($t0)
/*  f100138:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f10013c:	00a08025 */ 	or	$s0,$a1,$zero
/*  f100140:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f100144:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f100148:	afa60078 */ 	sw	$a2,0x78($sp)
/*  f10014c:	afa7007c */ 	sw	$a3,0x7c($sp)
/*  f100150:	24090006 */ 	addiu	$t1,$zero,0x6
/*  f100154:	11c00003 */ 	beqz	$t6,.L0f100164
/*  f100158:	240a0006 */ 	addiu	$t2,$zero,0x6
/*  f10015c:	10000002 */ 	beqz	$zero,.L0f100168
/*  f100160:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f100164:
/*  f100164:	00002825 */ 	or	$a1,$zero,$zero
.L0f100168:
/*  f100168:	8d0f0068 */ 	lw	$t7,0x68($t0)
/*  f10016c:	00001825 */ 	or	$v1,$zero,$zero
/*  f100170:	00002025 */ 	or	$a0,$zero,$zero
/*  f100174:	11e00003 */ 	beqz	$t7,.L0f100184
/*  f100178:	00001025 */ 	or	$v0,$zero,$zero
/*  f10017c:	10000001 */ 	beqz	$zero,.L0f100184
/*  f100180:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f100184:
/*  f100184:	8d180064 */ 	lw	$t8,0x64($t0)
/*  f100188:	13000003 */ 	beqz	$t8,.L0f100198
/*  f10018c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100190:	10000001 */ 	beqz	$zero,.L0f100198
/*  f100194:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f100198:
/*  f100198:	8d190070 */ 	lw	$t9,0x70($t0)
/*  f10019c:	13200003 */ 	beqz	$t9,.L0f1001ac
/*  f1001a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1001a4:	10000001 */ 	beqz	$zero,.L0f1001ac
/*  f1001a8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1001ac:
/*  f1001ac:	00447021 */ 	addu	$t6,$v0,$a0
/*  f1001b0:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f1001b4:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f1001b8:	2b010002 */ 	slti	$at,$t8,0x2
/*  f1001bc:	14200003 */ 	bnez	$at,.L0f1001cc
/*  f1001c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1001c4:	24090005 */ 	addiu	$t1,$zero,0x5
/*  f1001c8:	240a0003 */ 	addiu	$t2,$zero,0x3
.L0f1001cc:
/*  f1001cc:	12000008 */ 	beqz	$s0,.L0f1001f0
/*  f1001d0:	3c057f1b */ 	lui	$a1,%hi(var7f1b2c54)
/*  f1001d4:	24a52c54 */ 	addiu	$a1,$a1,%lo(var7f1b2c54)
/*  f1001d8:	afa90068 */ 	sw	$t1,0x68($sp)
/*  f1001dc:	afaa0064 */ 	sw	$t2,0x64($sp)
/*  f1001e0:	0c004c9d */ 	jal	func00013274
/*  f1001e4:	afb00074 */ 	sw	$s0,0x74($sp)
/*  f1001e8:	14400003 */ 	bnez	$v0,.L0f1001f8
/*  f1001ec:	3c047f1b */ 	lui	$a0,%hi(var7f1b2c58)
.L0f1001f0:
/*  f1001f0:	10000232 */ 	beqz	$zero,.L0f100abc
/*  f1001f4:	8fa20070 */ 	lw	$v0,0x70($sp)
.L0f1001f8:
/*  f1001f8:	3c058007 */ 	lui	$a1,%hi(var800719ac)
/*  f1001fc:	24a519ac */ 	addiu	$a1,$a1,%lo(var800719ac)
/*  f100200:	0c0036cc */ 	jal	func0000db30
/*  f100204:	24842c58 */ 	addiu	$a0,$a0,%lo(var7f1b2c58)
/*  f100208:	3c047f1b */ 	lui	$a0,%hi(var7f1b2c60)
/*  f10020c:	3c058007 */ 	lui	$a1,%hi(var800719b0)
/*  f100210:	24a519b0 */ 	addiu	$a1,$a1,%lo(var800719b0)
/*  f100214:	0c0036cc */ 	jal	func0000db30
/*  f100218:	24842c60 */ 	addiu	$a0,$a0,%lo(var7f1b2c60)
/*  f10021c:	3c047f1b */ 	lui	$a0,%hi(var7f1b2c68)
/*  f100220:	3c058007 */ 	lui	$a1,%hi(var800719b4)
/*  f100224:	24a519b4 */ 	addiu	$a1,$a1,%lo(var800719b4)
/*  f100228:	0c0036cc */ 	jal	func0000db30
/*  f10022c:	24842c68 */ 	addiu	$a0,$a0,%lo(var7f1b2c68)
/*  f100230:	3c047f1b */ 	lui	$a0,%hi(var7f1b2c70)
/*  f100234:	3c058007 */ 	lui	$a1,%hi(var800719b8)
/*  f100238:	24a519b8 */ 	addiu	$a1,$a1,%lo(var800719b8)
/*  f10023c:	0c0036cc */ 	jal	func0000db30
/*  f100240:	24842c70 */ 	addiu	$a0,$a0,%lo(var7f1b2c70)
/*  f100244:	3c047f1b */ 	lui	$a0,%hi(var7f1b2c78)
/*  f100248:	3c058007 */ 	lui	$a1,%hi(var800719bc)
/*  f10024c:	24a519bc */ 	addiu	$a1,$a1,%lo(var800719bc)
/*  f100250:	0c0036cc */ 	jal	func0000db30
/*  f100254:	24842c78 */ 	addiu	$a0,$a0,%lo(var7f1b2c78)
/*  f100258:	3c047f1b */ 	lui	$a0,%hi(var7f1b2c80)
/*  f10025c:	3c058007 */ 	lui	$a1,%hi(var800719c0)
/*  f100260:	24a519c0 */ 	addiu	$a1,$a1,%lo(var800719c0)
/*  f100264:	0c0036cc */ 	jal	func0000db30
/*  f100268:	24842c80 */ 	addiu	$a0,$a0,%lo(var7f1b2c80)
/*  f10026c:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuIndex)
/*  f100270:	250821b8 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuIndex)
/*  f100274:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f100278:	24090038 */ 	addiu	$t1,$zero,0x38
/*  f10027c:	3c028007 */ 	lui	$v0,0x8007
/*  f100280:	03290019 */ 	multu	$t9,$t1
/*  f100284:	8c4219b0 */ 	lw	$v0,0x19b0($v0)
/*  f100288:	3c07800a */ 	lui	$a3,%hi(g_ActiveMenuThings)
/*  f10028c:	24e720d0 */ 	addiu	$a3,$a3,%lo(g_ActiveMenuThings)
/*  f100290:	305800ff */ 	andi	$t8,$v0,0xff
/*  f100294:	44983000 */ 	mtc1	$t8,$f6
/*  f100298:	8fa30080 */ 	lw	$v1,0x80($sp)
/*  f10029c:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f1002a0:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f1002a4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1002a8:	00007012 */ 	mflo	$t6
/*  f1002ac:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f1002b0:	07010005 */ 	bgez	$t8,.L0f1002c8
/*  f1002b4:	c5e40018 */ 	lwc1	$f4,0x18($t7)
/*  f1002b8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1002bc:	44815000 */ 	mtc1	$at,$f10
/*  f1002c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1002c4:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f1002c8:
/*  f1002c8:	46082402 */ 	mul.s	$f16,$f4,$f8
/*  f1002cc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1002d0:	4459f800 */ 	cfc1	$t9,$31
/*  f1002d4:	44cef800 */ 	ctc1	$t6,$31
/*  f1002d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1002dc:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f1002e0:	444ef800 */ 	cfc1	$t6,$31
/*  f1002e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1002e8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1002ec:	11c00012 */ 	beqz	$t6,.L0f100338
/*  f1002f0:	3c014f00 */ 	lui	$at,0x4f00
/*  f1002f4:	44819000 */ 	mtc1	$at,$f18
/*  f1002f8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1002fc:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f100300:	44cef800 */ 	ctc1	$t6,$31
/*  f100304:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100308:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f10030c:	444ef800 */ 	cfc1	$t6,$31
/*  f100310:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100314:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f100318:	15c00005 */ 	bnez	$t6,.L0f100330
/*  f10031c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100320:	440e9000 */ 	mfc1	$t6,$f18
/*  f100324:	3c018000 */ 	lui	$at,0x8000
/*  f100328:	10000007 */ 	beqz	$zero,.L0f100348
/*  f10032c:	01c17025 */ 	or	$t6,$t6,$at
.L0f100330:
/*  f100330:	10000005 */ 	beqz	$zero,.L0f100348
/*  f100334:	240effff */ 	addiu	$t6,$zero,-1
.L0f100338:
/*  f100338:	440e9000 */ 	mfc1	$t6,$f18
/*  f10033c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100340:	05c0fffb */ 	bltz	$t6,.L0f100330
/*  f100344:	00000000 */ 	sll	$zero,$zero,0x0
.L0f100348:
/*  f100348:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f10034c:	00417824 */ 	and	$t7,$v0,$at
/*  f100350:	44d9f800 */ 	ctc1	$t9,$31
/*  f100354:	24010001 */ 	addiu	$at,$zero,0x1
/*  f100358:	14610003 */ 	bne	$v1,$at,.L0f100368
/*  f10035c:	01cf8025 */ 	or	$s0,$t6,$t7
/*  f100360:	321800ff */ 	andi	$t8,$s0,0xff
/*  f100364:	03008025 */ 	or	$s0,$t8,$zero
.L0f100368:
/*  f100368:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f10036c:	10620004 */ 	beq	$v1,$v0,.L0f100380
/*  f100370:	31780010 */ 	andi	$t8,$t3,0x10
/*  f100374:	8fb90084 */ 	lw	$t9,0x84($sp)
/*  f100378:	332e0002 */ 	andi	$t6,$t9,0x2
/*  f10037c:	11c00002 */ 	beqz	$t6,.L0f100388
.L0f100380:
/*  f100380:	320f00ff */ 	andi	$t7,$s0,0xff
/*  f100384:	01e08025 */ 	or	$s0,$t7,$zero
.L0f100388:
/*  f100388:	13000003 */ 	beqz	$t8,.L0f100398
/*  f10038c:	03005825 */ 	or	$t3,$t8,$zero
/*  f100390:	321900ff */ 	andi	$t9,$s0,0xff
/*  f100394:	03208025 */ 	or	$s0,$t9,$zero
.L0f100398:
/*  f100398:	3c0e800a */ 	lui	$t6,0x800a
/*  f10039c:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f1003a0:	91cf0250 */ 	lbu	$t7,0x250($t6)
/*  f1003a4:	544f0003 */ 	bnel	$v0,$t7,.L0f1003b4
/*  f1003a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1003ac:	2410006f */ 	addiu	$s0,$zero,0x6f
/*  f1003b0:	02002825 */ 	or	$a1,$s0,$zero
.L0f1003b4:
/*  f1003b4:	0fc54df7 */ 	jal	func0f1537dc
/*  f1003b8:	afab0038 */ 	sw	$t3,0x38($sp)
/*  f1003bc:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuIndex)
/*  f1003c0:	250821b8 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuIndex)
/*  f1003c4:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f1003c8:	24090038 */ 	addiu	$t1,$zero,0x38
/*  f1003cc:	87b0007e */ 	lh	$s0,0x7e($sp)
/*  f1003d0:	01c90019 */ 	multu	$t6,$t1
/*  f1003d4:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f1003d8:	3c07800a */ 	lui	$a3,%hi(g_ActiveMenuThings)
/*  f1003dc:	24e720d0 */ 	addiu	$a3,$a3,%lo(g_ActiveMenuThings)
/*  f1003e0:	02182821 */ 	addu	$a1,$s0,$t8
/*  f1003e4:	30a603ff */ 	andi	$a2,$a1,0x3ff
/*  f1003e8:	0006c880 */ 	sll	$t9,$a2,0x2
/*  f1003ec:	03203025 */ 	or	$a2,$t9,$zero
/*  f1003f0:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f1003f4:	87bf007a */ 	lh	$ra,0x7a($sp)
/*  f1003f8:	00007812 */ 	mflo	$t7
/*  f1003fc:	00efc021 */ 	addu	$t8,$a3,$t7
/*  f100400:	87190004 */ 	lh	$t9,0x4($t8)
/*  f100404:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f100408:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f10040c:	3c0cf600 */ 	lui	$t4,0xf600
/*  f100410:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f100414:	07210003 */ 	bgez	$t9,.L0f100424
/*  f100418:	00197043 */ 	sra	$t6,$t9,0x1
/*  f10041c:	27210001 */ 	addiu	$at,$t9,0x1
/*  f100420:	00017043 */ 	sra	$t6,$at,0x1
.L0f100424:
/*  f100424:	01df7821 */ 	addu	$t7,$t6,$ra
/*  f100428:	01f80019 */ 	multu	$t7,$t8
/*  f10042c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f100430:	0000c812 */ 	mflo	$t9
/*  f100434:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f100438:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f10043c:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f100440:	0306c825 */ 	or	$t9,$t8,$a2
/*  f100444:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f100448:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f10044c:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f100450:	03290019 */ 	multu	$t9,$t1
/*  f100454:	020e6823 */ 	subu	$t5,$s0,$t6
/*  f100458:	25aa0001 */ 	addiu	$t2,$t5,0x1
/*  f10045c:	314f03ff */ 	andi	$t7,$t2,0x3ff
/*  f100460:	000f5080 */ 	sll	$t2,$t7,0x2
/*  f100464:	00007012 */ 	mflo	$t6
/*  f100468:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f10046c:	85f80004 */ 	lh	$t8,0x4($t7)
/*  f100470:	07010003 */ 	bgez	$t8,.L0f100480
/*  f100474:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f100478:	27010001 */ 	addiu	$at,$t8,0x1
/*  f10047c:	0001c843 */ 	sra	$t9,$at,0x1
.L0f100480:
/*  f100480:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f100484:	03f97023 */ 	subu	$t6,$ra,$t9
/*  f100488:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f10048c:	01f80019 */ 	multu	$t7,$t8
/*  f100490:	0000c812 */ 	mflo	$t9
/*  f100494:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f100498:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f10049c:	01eac025 */ 	or	$t8,$t7,$t2
/*  f1004a0:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1004a4:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f1004a8:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f1004ac:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f1004b0:	0fc54e0e */ 	jal	func0f153838
/*  f1004b4:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f1004b8:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f1004bc:	3c048007 */ 	lui	$a0,0x8007
/*  f1004c0:	8c8419ac */ 	lw	$a0,0x19ac($a0)
/*  f1004c4:	3c07800a */ 	lui	$a3,%hi(g_ActiveMenuThings)
/*  f1004c8:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuIndex)
/*  f1004cc:	250821b8 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuIndex)
/*  f1004d0:	24e720d0 */ 	addiu	$a3,$a3,%lo(g_ActiveMenuThings)
/*  f1004d4:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f1004d8:	24090038 */ 	addiu	$t1,$zero,0x38
/*  f1004dc:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f1004e0:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f1004e4:	11600002 */ 	beqz	$t3,.L0f1004f0
/*  f1004e8:	00808025 */ 	or	$s0,$a0,$zero
/*  f1004ec:	309000ff */ 	andi	$s0,$a0,0xff
.L0f1004f0:
/*  f1004f0:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f1004f4:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f1004f8:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f1004fc:	53220006 */ 	beql	$t9,$v0,.L0f100518
/*  f100500:	2410ff8f */ 	addiu	$s0,$zero,-113
/*  f100504:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f100508:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f10050c:	51e00003 */ 	beqzl	$t7,.L0f10051c
/*  f100510:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f100514:	2410ff8f */ 	addiu	$s0,$zero,-113
.L0f100518:
/*  f100518:	8d180000 */ 	lw	$t8,0x0($t0)
.L0f10051c:
/*  f10051c:	320f00ff */ 	andi	$t7,$s0,0xff
/*  f100520:	448f5000 */ 	mtc1	$t7,$f10
/*  f100524:	03090019 */ 	multu	$t8,$t1
/*  f100528:	3c014f80 */ 	lui	$at,0x4f80
/*  f10052c:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f100530:	0000c812 */ 	mflo	$t9
/*  f100534:	00f97021 */ 	addu	$t6,$a3,$t9
/*  f100538:	05e10004 */ 	bgez	$t7,.L0f10054c
/*  f10053c:	c5c60018 */ 	lwc1	$f6,0x18($t6)
/*  f100540:	44814000 */ 	mtc1	$at,$f8
/*  f100544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100548:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f10054c:
/*  f10054c:	46043402 */ 	mul.s	$f16,$f6,$f4
/*  f100550:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f100554:	3c014f00 */ 	lui	$at,0x4f00
/*  f100558:	3c0f800a */ 	lui	$t7,0x800a
/*  f10055c:	4458f800 */ 	cfc1	$t8,$31
/*  f100560:	44d9f800 */ 	ctc1	$t9,$31
/*  f100564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100568:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f10056c:	4459f800 */ 	cfc1	$t9,$31
/*  f100570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100574:	33390078 */ 	andi	$t9,$t9,0x78
/*  f100578:	53200013 */ 	beqzl	$t9,.L0f1005c8
/*  f10057c:	44199000 */ 	mfc1	$t9,$f18
/*  f100580:	44819000 */ 	mtc1	$at,$f18
/*  f100584:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f100588:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f10058c:	44d9f800 */ 	ctc1	$t9,$31
/*  f100590:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100594:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f100598:	4459f800 */ 	cfc1	$t9,$31
/*  f10059c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1005a0:	33390078 */ 	andi	$t9,$t9,0x78
/*  f1005a4:	17200005 */ 	bnez	$t9,.L0f1005bc
/*  f1005a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1005ac:	44199000 */ 	mfc1	$t9,$f18
/*  f1005b0:	3c018000 */ 	lui	$at,0x8000
/*  f1005b4:	10000007 */ 	beqz	$zero,.L0f1005d4
/*  f1005b8:	0321c825 */ 	or	$t9,$t9,$at
.L0f1005bc:
/*  f1005bc:	10000005 */ 	beqz	$zero,.L0f1005d4
/*  f1005c0:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f1005c4:	44199000 */ 	mfc1	$t9,$f18
.L0f1005c8:
/*  f1005c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1005cc:	0720fffb */ 	bltz	$t9,.L0f1005bc
/*  f1005d0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1005d4:
/*  f1005d4:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f1005d8:	44d8f800 */ 	ctc1	$t8,$31
/*  f1005dc:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1005e0:	91f80250 */ 	lbu	$t8,0x250($t7)
/*  f1005e4:	02017024 */ 	and	$t6,$s0,$at
/*  f1005e8:	032e8025 */ 	or	$s0,$t9,$t6
/*  f1005ec:	54580004 */ 	bnel	$v0,$t8,.L0f100600
/*  f1005f0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1005f4:	3c104f4f */ 	lui	$s0,0x4f4f
/*  f1005f8:	36104f7f */ 	ori	$s0,$s0,0x4f7f
/*  f1005fc:	02002825 */ 	or	$a1,$s0,$zero
.L0f100600:
/*  f100600:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f100604:	0fc54df7 */ 	jal	func0f1537dc
/*  f100608:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f10060c:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuIndex)
/*  f100610:	250821b8 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuIndex)
/*  f100614:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f100618:	24090038 */ 	addiu	$t1,$zero,0x38
/*  f10061c:	3c07800a */ 	lui	$a3,%hi(g_ActiveMenuThings)
/*  f100620:	03290019 */ 	multu	$t9,$t1
/*  f100624:	24e720d0 */ 	addiu	$a3,$a3,%lo(g_ActiveMenuThings)
/*  f100628:	87ab007a */ 	lh	$t3,0x7a($sp)
/*  f10062c:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f100630:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f100634:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f100638:	3c0cf600 */ 	lui	$t4,0xf600
/*  f10063c:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f100640:	24450018 */ 	addiu	$a1,$v0,0x18
/*  f100644:	24440020 */ 	addiu	$a0,$v0,0x20
/*  f100648:	00007012 */ 	mflo	$t6
/*  f10064c:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f100650:	85f80004 */ 	lh	$t8,0x4($t7)
/*  f100654:	07010003 */ 	bgez	$t8,.L0f100664
/*  f100658:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f10065c:	27010001 */ 	addiu	$at,$t8,0x1
/*  f100660:	0001c843 */ 	sra	$t9,$at,0x1
.L0f100664:
/*  f100664:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f100668:	032b7021 */ 	addu	$t6,$t9,$t3
/*  f10066c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f100670:	01f80019 */ 	multu	$t7,$t8
/*  f100674:	0000c812 */ 	mflo	$t9
/*  f100678:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f10067c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f100680:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f100684:	030ac825 */ 	or	$t9,$t8,$t2
/*  f100688:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f10068c:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f100690:	01c90019 */ 	multu	$t6,$t1
/*  f100694:	00007812 */ 	mflo	$t7
/*  f100698:	00efc021 */ 	addu	$t8,$a3,$t7
/*  f10069c:	87190004 */ 	lh	$t9,0x4($t8)
/*  f1006a0:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f1006a4:	07210003 */ 	bgez	$t9,.L0f1006b4
/*  f1006a8:	00197043 */ 	sra	$t6,$t9,0x1
/*  f1006ac:	27210001 */ 	addiu	$at,$t9,0x1
/*  f1006b0:	00017043 */ 	sra	$t6,$at,0x1
.L0f1006b4:
/*  f1006b4:	016e7823 */ 	subu	$t7,$t3,$t6
/*  f1006b8:	01f80019 */ 	multu	$t7,$t8
/*  f1006bc:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*  f1006c0:	0000c812 */ 	mflo	$t9
/*  f1006c4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1006c8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1006cc:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1006d0:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1006d4:	01eec025 */ 	or	$t8,$t7,$t6
/*  f1006d8:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1006dc:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f1006e0:	03290019 */ 	multu	$t9,$t1
/*  f1006e4:	00007812 */ 	mflo	$t7
/*  f1006e8:	00ef7021 */ 	addu	$t6,$a3,$t7
/*  f1006ec:	85d80004 */ 	lh	$t8,0x4($t6)
/*  f1006f0:	07010003 */ 	bgez	$t8,.L0f100700
/*  f1006f4:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f1006f8:	27010001 */ 	addiu	$at,$t8,0x1
/*  f1006fc:	0001c843 */ 	sra	$t9,$at,0x1
.L0f100700:
/*  f100700:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f100704:	032b7821 */ 	addu	$t7,$t9,$t3
/*  f100708:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f10070c:	01d80019 */ 	multu	$t6,$t8
/*  f100710:	0000c812 */ 	mflo	$t9
/*  f100714:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f100718:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f10071c:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f100720:	01ccc025 */ 	or	$t8,$t6,$t4
/*  f100724:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f100728:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f10072c:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f100730:	03197825 */ 	or	$t7,$t8,$t9
/*  f100734:	ac4f0008 */ 	sw	$t7,0x8($v0)
/*  f100738:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f10073c:	01c90019 */ 	multu	$t6,$t1
/*  f100740:	0000c012 */ 	mflo	$t8
/*  f100744:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f100748:	872f0004 */ 	lh	$t7,0x4($t9)
/*  f10074c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f100750:	05e10003 */ 	bgez	$t7,.L0f100760
/*  f100754:	000f7043 */ 	sra	$t6,$t7,0x1
/*  f100758:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f10075c:	00017043 */ 	sra	$t6,$at,0x1
.L0f100760:
/*  f100760:	016ec023 */ 	subu	$t8,$t3,$t6
/*  f100764:	03190019 */ 	multu	$t8,$t9
/*  f100768:	00007812 */ 	mflo	$t7
/*  f10076c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f100770:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f100774:	0306c825 */ 	or	$t9,$t8,$a2
/*  f100778:	ac59000c */ 	sw	$t9,0xc($v0)
/*  f10077c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f100780:	01e90019 */ 	multu	$t7,$t1
/*  f100784:	00007012 */ 	mflo	$t6
/*  f100788:	00eec021 */ 	addu	$t8,$a3,$t6
/*  f10078c:	87190004 */ 	lh	$t9,0x4($t8)
/*  f100790:	07210003 */ 	bgez	$t9,.L0f1007a0
/*  f100794:	00197843 */ 	sra	$t7,$t9,0x1
/*  f100798:	27210001 */ 	addiu	$at,$t9,0x1
/*  f10079c:	00017843 */ 	sra	$t7,$at,0x1
.L0f1007a0:
/*  f1007a0:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f1007a4:	016f7023 */ 	subu	$t6,$t3,$t7
/*  f1007a8:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f1007ac:	03190019 */ 	multu	$t8,$t9
/*  f1007b0:	00007812 */ 	mflo	$t7
/*  f1007b4:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f1007b8:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f1007bc:	030cc825 */ 	or	$t9,$t8,$t4
/*  f1007c0:	03267825 */ 	or	$t7,$t9,$a2
/*  f1007c4:	ac4f0010 */ 	sw	$t7,0x10($v0)
/*  f1007c8:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f1007cc:	01c90019 */ 	multu	$t6,$t1
/*  f1007d0:	0000c012 */ 	mflo	$t8
/*  f1007d4:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f1007d8:	872f0004 */ 	lh	$t7,0x4($t9)
/*  f1007dc:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f1007e0:	05e10003 */ 	bgez	$t7,.L0f1007f0
/*  f1007e4:	000f7043 */ 	sra	$t6,$t7,0x1
/*  f1007e8:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f1007ec:	00017043 */ 	sra	$t6,$at,0x1
.L0f1007f0:
/*  f1007f0:	016ec023 */ 	subu	$t8,$t3,$t6
/*  f1007f4:	03190019 */ 	multu	$t8,$t9
/*  f1007f8:	00007812 */ 	mflo	$t7
/*  f1007fc:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f100800:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f100804:	030ac825 */ 	or	$t9,$t8,$t2
/*  f100808:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f10080c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f100810:	01e90019 */ 	multu	$t7,$t1
/*  f100814:	00007012 */ 	mflo	$t6
/*  f100818:	00eec021 */ 	addu	$t8,$a3,$t6
/*  f10081c:	87190004 */ 	lh	$t9,0x4($t8)
/*  f100820:	07210003 */ 	bgez	$t9,.L0f100830
/*  f100824:	00197843 */ 	sra	$t7,$t9,0x1
/*  f100828:	27210001 */ 	addiu	$at,$t9,0x1
/*  f10082c:	00017843 */ 	sra	$t7,$at,0x1
.L0f100830:
/*  f100830:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f100834:	01eb7021 */ 	addu	$t6,$t7,$t3
/*  f100838:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f10083c:	03190019 */ 	multu	$t8,$t9
/*  f100840:	00007812 */ 	mflo	$t7
/*  f100844:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f100848:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f10084c:	030cc825 */ 	or	$t9,$t8,$t4
/*  f100850:	03267825 */ 	or	$t7,$t9,$a2
/*  f100854:	ac4f0018 */ 	sw	$t7,0x18($v0)
/*  f100858:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f10085c:	01c90019 */ 	multu	$t6,$t1
/*  f100860:	0000c012 */ 	mflo	$t8
/*  f100864:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f100868:	872f0004 */ 	lh	$t7,0x4($t9)
/*  f10086c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f100870:	05e10003 */ 	bgez	$t7,.L0f100880
/*  f100874:	000f7043 */ 	sra	$t6,$t7,0x1
/*  f100878:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f10087c:	00017043 */ 	sra	$t6,$at,0x1
.L0f100880:
/*  f100880:	01cbc021 */ 	addu	$t8,$t6,$t3
/*  f100884:	03190019 */ 	multu	$t8,$t9
/*  f100888:	00007812 */ 	mflo	$t7
/*  f10088c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f100890:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f100894:	030ac825 */ 	or	$t9,$t8,$t2
/*  f100898:	0fc54e0e */ 	jal	func0f153838
/*  f10089c:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f1008a0:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f1008a4:	3c07800a */ 	lui	$a3,%hi(g_ActiveMenuThings)
/*  f1008a8:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuIndex)
/*  f1008ac:	3c108007 */ 	lui	$s0,0x8007
/*  f1008b0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1008b4:	250821b8 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuIndex)
/*  f1008b8:	24e720d0 */ 	addiu	$a3,$a3,%lo(g_ActiveMenuThings)
/*  f1008bc:	24090038 */ 	addiu	$t1,$zero,0x38
/*  f1008c0:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f1008c4:	11e10005 */ 	beq	$t7,$at,.L0f1008dc
/*  f1008c8:	8e1019b4 */ 	lw	$s0,0x19b4($s0)
/*  f1008cc:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f1008d0:	31d80002 */ 	andi	$t8,$t6,0x2
/*  f1008d4:	53000003 */ 	beqzl	$t8,.L0f1008e4
/*  f1008d8:	8fb90084 */ 	lw	$t9,0x84($sp)
.L0f1008dc:
/*  f1008dc:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f1008e0:	8fb90084 */ 	lw	$t9,0x84($sp)
.L0f1008e4:
/*  f1008e4:	3c014120 */ 	lui	$at,0x4120
/*  f1008e8:	332f0008 */ 	andi	$t7,$t9,0x8
/*  f1008ec:	51e00034 */ 	beqzl	$t7,.L0f1009c0
/*  f1008f0:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f1008f4:	44816000 */ 	mtc1	$at,$f12
/*  f1008f8:	0fc01ad5 */ 	jal	func0f006b54
/*  f1008fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100900:	3c01437f */ 	lui	$at,0x437f
/*  f100904:	44815000 */ 	mtc1	$at,$f10
/*  f100908:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10090c:	3c04ffaf */ 	lui	$a0,0xffaf
/*  f100910:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f100914:	34848fff */ 	ori	$a0,$a0,0x8fff
/*  f100918:	3c014f00 */ 	lui	$at,0x4f00
/*  f10091c:	02002825 */ 	or	$a1,$s0,$zero
/*  f100920:	444ef800 */ 	cfc1	$t6,$31
/*  f100924:	44c6f800 */ 	ctc1	$a2,$31
/*  f100928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10092c:	460041a4 */ 	cvt.w.s	$f6,$f8
/*  f100930:	4446f800 */ 	cfc1	$a2,$31
/*  f100934:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100938:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f10093c:	50c00013 */ 	beqzl	$a2,.L0f10098c
/*  f100940:	44063000 */ 	mfc1	$a2,$f6
/*  f100944:	44813000 */ 	mtc1	$at,$f6
/*  f100948:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10094c:	46064181 */ 	sub.s	$f6,$f8,$f6
/*  f100950:	44c6f800 */ 	ctc1	$a2,$31
/*  f100954:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100958:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f10095c:	4446f800 */ 	cfc1	$a2,$31
/*  f100960:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100964:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f100968:	14c00005 */ 	bnez	$a2,.L0f100980
/*  f10096c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100970:	44063000 */ 	mfc1	$a2,$f6
/*  f100974:	3c018000 */ 	lui	$at,0x8000
/*  f100978:	10000007 */ 	beqz	$zero,.L0f100998
/*  f10097c:	00c13025 */ 	or	$a2,$a2,$at
.L0f100980:
/*  f100980:	10000005 */ 	beqz	$zero,.L0f100998
/*  f100984:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f100988:	44063000 */ 	mfc1	$a2,$f6
.L0f10098c:
/*  f10098c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100990:	04c0fffb */ 	bltz	$a2,.L0f100980
/*  f100994:	00000000 */ 	sll	$zero,$zero,0x0
.L0f100998:
/*  f100998:	44cef800 */ 	ctc1	$t6,$31
/*  f10099c:	0fc01a40 */ 	jal	func0f006900
/*  f1009a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1009a4:	3c07800a */ 	lui	$a3,%hi(g_ActiveMenuThings)
/*  f1009a8:	3c08800a */ 	lui	$t0,%hi(g_ActiveMenuIndex)
/*  f1009ac:	250821b8 */ 	addiu	$t0,$t0,%lo(g_ActiveMenuIndex)
/*  f1009b0:	24e720d0 */ 	addiu	$a3,$a3,%lo(g_ActiveMenuThings)
/*  f1009b4:	24090038 */ 	addiu	$t1,$zero,0x38
/*  f1009b8:	00408025 */ 	or	$s0,$v0,$zero
/*  f1009bc:	8d180000 */ 	lw	$t8,0x0($t0)
.L0f1009c0:
/*  f1009c0:	320e00ff */ 	andi	$t6,$s0,0xff
/*  f1009c4:	448e8000 */ 	mtc1	$t6,$f16
/*  f1009c8:	03090019 */ 	multu	$t8,$t1
/*  f1009cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f1009d0:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f1009d4:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f1009d8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f1009dc:	0000c812 */ 	mflo	$t9
/*  f1009e0:	00f97821 */ 	addu	$t7,$a3,$t9
/*  f1009e4:	05c10004 */ 	bgez	$t6,.L0f1009f8
/*  f1009e8:	c5e40018 */ 	lwc1	$f4,0x18($t7)
/*  f1009ec:	44815000 */ 	mtc1	$at,$f10
/*  f1009f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1009f4:	460a9480 */ 	add.s	$f18,$f18,$f10
.L0f1009f8:
/*  f1009f8:	46122202 */ 	mul.s	$f8,$f4,$f18
/*  f1009fc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f100a00:	3c014f00 */ 	lui	$at,0x4f00
/*  f100a04:	3c0e800a */ 	lui	$t6,0x800a
/*  f100a08:	87a7007a */ 	lh	$a3,0x7a($sp)
/*  f100a0c:	4458f800 */ 	cfc1	$t8,$31
/*  f100a10:	44d9f800 */ 	ctc1	$t9,$31
/*  f100a14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100a18:	460041a4 */ 	cvt.w.s	$f6,$f8
/*  f100a1c:	4459f800 */ 	cfc1	$t9,$31
/*  f100a20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100a24:	33390078 */ 	andi	$t9,$t9,0x78
/*  f100a28:	53200013 */ 	beqzl	$t9,.L0f100a78
/*  f100a2c:	44193000 */ 	mfc1	$t9,$f6
/*  f100a30:	44813000 */ 	mtc1	$at,$f6
/*  f100a34:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f100a38:	46064181 */ 	sub.s	$f6,$f8,$f6
/*  f100a3c:	44d9f800 */ 	ctc1	$t9,$31
/*  f100a40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100a44:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f100a48:	4459f800 */ 	cfc1	$t9,$31
/*  f100a4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100a50:	33390078 */ 	andi	$t9,$t9,0x78
/*  f100a54:	17200005 */ 	bnez	$t9,.L0f100a6c
/*  f100a58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100a5c:	44193000 */ 	mfc1	$t9,$f6
/*  f100a60:	3c018000 */ 	lui	$at,0x8000
/*  f100a64:	10000007 */ 	beqz	$zero,.L0f100a84
/*  f100a68:	0321c825 */ 	or	$t9,$t9,$at
.L0f100a6c:
/*  f100a6c:	10000005 */ 	beqz	$zero,.L0f100a84
/*  f100a70:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f100a74:	44193000 */ 	mfc1	$t9,$f6
.L0f100a78:
/*  f100a78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100a7c:	0720fffb */ 	bltz	$t9,.L0f100a6c
/*  f100a80:	00000000 */ 	sll	$zero,$zero,0x0
.L0f100a84:
/*  f100a84:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f100a88:	44d8f800 */ 	ctc1	$t8,$31
/*  f100a8c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f100a90:	91d80250 */ 	lbu	$t8,0x250($t6)
/*  f100a94:	02017824 */ 	and	$t7,$s0,$at
/*  f100a98:	24010002 */ 	addiu	$at,$zero,0x2
/*  f100a9c:	17010003 */ 	bne	$t8,$at,.L0f100aac
/*  f100aa0:	032f8025 */ 	or	$s0,$t9,$t7
/*  f100aa4:	3c104f4f */ 	lui	$s0,0x4f4f
/*  f100aa8:	36104f7f */ 	ori	$s0,$s0,0x4f7f
.L0f100aac:
/*  f100aac:	87b9007e */ 	lh	$t9,0x7e($sp)
/*  f100ab0:	02003025 */ 	or	$a2,$s0,$zero
/*  f100ab4:	0fc3fdbd */ 	jal	func0f0ff6f4
/*  f100ab8:	afb90010 */ 	sw	$t9,0x10($sp)
.L0f100abc:
/*  f100abc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f100ac0:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f100ac4:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f100ac8:	03e00008 */ 	jr	$ra
/*  f100acc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f100ad0
/*  f100ad0:	27bdfe28 */ 	addiu	$sp,$sp,-472
/*  f100ad4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f100ad8:	8dce06c8 */ 	lw	$t6,0x6c8($t6)
/*  f100adc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f100ae0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f100ae4:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f100ae8:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f100aec:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f100af0:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f100af4:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f100af8:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f100afc:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f100b00:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f100b04:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f100b08:	15c10005 */ 	bne	$t6,$at,.L0f100b20
/*  f100b0c:	afa401d8 */ 	sw	$a0,0x1d8($sp)
/*  f100b10:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f100b14:	3c018008 */ 	lui	$at,0x8008
/*  f100b18:	10000004 */ 	beqz	$zero,.L0f100b2c
/*  f100b1c:	ac2ffac0 */ 	sw	$t7,-0x540($at)
.L0f100b20:
/*  f100b20:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f100b24:	3c018008 */ 	lui	$at,0x8008
/*  f100b28:	ac38fac0 */ 	sw	$t8,-0x540($at)
.L0f100b2c:
/*  f100b2c:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f100b30:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f100b34:	8d79028c */ 	lw	$t9,0x28c($t3)
/*  f100b38:	3c01800a */ 	lui	$at,0x800a
/*  f100b3c:	ac3921b8 */ 	sw	$t9,0x21b8($at)
/*  f100b40:	8d6e0284 */ 	lw	$t6,0x284($t3)
/*  f100b44:	adc01c04 */ 	sw	$zero,0x1c04($t6)
/*  f100b48:	8d630284 */ 	lw	$v1,0x284($t3)
/*  f100b4c:	906f0250 */ 	lbu	$t7,0x250($v1)
/*  f100b50:	51e00353 */ 	beqzl	$t7,.L0f1018a0
/*  f100b54:	8c621c04 */ 	lw	$v0,0x1c04($v1)
/*  f100b58:	0fc54d8a */ 	jal	func0f153628
/*  f100b5c:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f100b60:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f100b64:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f100b68:	8d180318 */ 	lw	$t8,0x318($t0)
/*  f100b6c:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f100b70:	13000010 */ 	beqz	$t8,.L0f100bb4
/*  f100b74:	3c19800a */ 	lui	$t9,0x800a
/*  f100b78:	8f3921b8 */ 	lw	$t9,0x21b8($t9)
/*  f100b7c:	241e0038 */ 	addiu	$s8,$zero,0x38
/*  f100b80:	3c17800a */ 	lui	$s7,%hi(g_ActiveMenuThings)
/*  f100b84:	033e0019 */ 	multu	$t9,$s8
/*  f100b88:	26f720d0 */ 	addiu	$s7,$s7,%lo(g_ActiveMenuThings)
/*  f100b8c:	00007012 */ 	mflo	$t6
/*  f100b90:	02ee7821 */ 	addu	$t7,$s7,$t6
/*  f100b94:	81e20000 */ 	lb	$v0,0x0($t7)
/*  f100b98:	28410002 */ 	slti	$at,$v0,0x2
/*  f100b9c:	14200005 */ 	bnez	$at,.L0f100bb4
/*  f100ba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100ba4:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f100ba8:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f100bac:	932e1be5 */ 	lbu	$t6,0x1be5($t9)
/*  f100bb0:	afae01c4 */ 	sw	$t6,0x1c4($sp)
.L0f100bb4:
/*  f100bb4:	3c0f800a */ 	lui	$t7,0x800a
/*  f100bb8:	8def21b8 */ 	lw	$t7,0x21b8($t7)
/*  f100bbc:	241e0038 */ 	addiu	$s8,$zero,0x38
/*  f100bc0:	3c17800a */ 	lui	$s7,%hi(g_ActiveMenuThings)
/*  f100bc4:	01fe0019 */ 	multu	$t7,$s8
/*  f100bc8:	26f720d0 */ 	addiu	$s7,$s7,%lo(g_ActiveMenuThings)
/*  f100bcc:	2401ff85 */ 	addiu	$at,$zero,-123
/*  f100bd0:	0000c012 */ 	mflo	$t8
/*  f100bd4:	02f88021 */ 	addu	$s0,$s7,$t8
/*  f100bd8:	8619000a */ 	lh	$t9,0xa($s0)
/*  f100bdc:	57210021 */ 	bnel	$t9,$at,.L0f100c64
/*  f100be0:	9202000e */ 	lbu	$v0,0xe($s0)
/*  f100be4:	9202000e */ 	lbu	$v0,0xe($s0)
/*  f100be8:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f100bec:	26060006 */ 	addiu	$a2,$s0,0x6
/*  f100bf0:	0043001a */ 	div	$zero,$v0,$v1
/*  f100bf4:	00002010 */ 	mfhi	$a0
/*  f100bf8:	00002812 */ 	mflo	$a1
/*  f100bfc:	0005c400 */ 	sll	$t8,$a1,0x10
/*  f100c00:	00047400 */ 	sll	$t6,$a0,0x10
/*  f100c04:	14600002 */ 	bnez	$v1,.L0f100c10
/*  f100c08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100c0c:	0007000d */ 	break	0x7
.L0f100c10:
/*  f100c10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f100c14:	14610004 */ 	bne	$v1,$at,.L0f100c28
/*  f100c18:	3c018000 */ 	lui	$at,0x8000
/*  f100c1c:	14410002 */ 	bne	$v0,$at,.L0f100c28
/*  f100c20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100c24:	0006000d */ 	break	0x6
.L0f100c28:
/*  f100c28:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f100c2c:	00182c03 */ 	sra	$a1,$t8,0x10
/*  f100c30:	0fc3fc9d */ 	jal	func0f0ff274
/*  f100c34:	26070008 */ 	addiu	$a3,$s0,0x8
/*  f100c38:	3c0e800a */ 	lui	$t6,0x800a
/*  f100c3c:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f100c40:	01de0019 */ 	multu	$t6,$s8
/*  f100c44:	00007812 */ 	mflo	$t7
/*  f100c48:	02ef8021 */ 	addu	$s0,$s7,$t7
/*  f100c4c:	86180006 */ 	lh	$t8,0x6($s0)
/*  f100c50:	86190008 */ 	lh	$t9,0x8($s0)
/*  f100c54:	a618000a */ 	sh	$t8,0xa($s0)
/*  f100c58:	1000000d */ 	beqz	$zero,.L0f100c90
/*  f100c5c:	a619000c */ 	sh	$t9,0xc($s0)
/*  f100c60:	9202000e */ 	lbu	$v0,0xe($s0)
.L0f100c64:
/*  f100c64:	24010003 */ 	addiu	$at,$zero,0x3
/*  f100c68:	2606000a */ 	addiu	$a2,$s0,0xa
/*  f100c6c:	0041001a */ 	div	$zero,$v0,$at
/*  f100c70:	00002010 */ 	mfhi	$a0
/*  f100c74:	00002812 */ 	mflo	$a1
/*  f100c78:	0005c400 */ 	sll	$t8,$a1,0x10
/*  f100c7c:	00047400 */ 	sll	$t6,$a0,0x10
/*  f100c80:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f100c84:	00182c03 */ 	sra	$a1,$t8,0x10
/*  f100c88:	0fc3fc9d */ 	jal	func0f0ff274
/*  f100c8c:	2607000c */ 	addiu	$a3,$s0,0xc
.L0f100c90:
/*  f100c90:	0fc351e7 */ 	jal	func0f0d479c
/*  f100c94:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f100c98:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f100c9c:	0fc59e73 */ 	jal	func0f1679cc
/*  f100ca0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f100ca4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f100ca8:	0fc59e59 */ 	jal	func0f167964
/*  f100cac:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f100cb0:	8fae01d8 */ 	lw	$t6,0x1d8($sp)
/*  f100cb4:	3c18e700 */ 	lui	$t8,0xe700
/*  f100cb8:	00408025 */ 	or	$s0,$v0,$zero
/*  f100cbc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f100cc0:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f100cc4:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f100cc8:	add80000 */ 	sw	$t8,0x0($t6)
/*  f100ccc:	8fb901d8 */ 	lw	$t9,0x1d8($sp)
/*  f100cd0:	3c0fba00 */ 	lui	$t7,0xba00
/*  f100cd4:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f100cd8:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f100cdc:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f100ce0:	af200004 */ 	sw	$zero,0x4($t9)
/*  f100ce4:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f100ce8:	8fb801d8 */ 	lw	$t8,0x1d8($sp)
/*  f100cec:	3c0eb900 */ 	lui	$t6,0xb900
/*  f100cf0:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f100cf4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f100cf8:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f100cfc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f100d00:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f100d04:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f100d08:	3c19ba00 */ 	lui	$t9,0xba00
/*  f100d0c:	37390402 */ 	ori	$t9,$t9,0x402
/*  f100d10:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f100d14:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f100d18:	240e0020 */ 	addiu	$t6,$zero,0x20
/*  f100d1c:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f100d20:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f100d24:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f100d28:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f100d2c:	37397e24 */ 	ori	$t9,$t9,0x7e24
/*  f100d30:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f100d34:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f100d38:	240ef9fc */ 	addiu	$t6,$zero,-1540
/*  f100d3c:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f100d40:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f100d44:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f100d48:	3c19b600 */ 	lui	$t9,0xb600
/*  f100d4c:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f100d50:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f100d54:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f100d58:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f100d5c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f100d60:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f100d64:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f100d68:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f100d6c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f100d70:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f100d74:	27a401d8 */ 	addiu	$a0,$sp,0x1d8
/*  f100d78:	00002825 */ 	or	$a1,$zero,$zero
/*  f100d7c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f100d80:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f100d84:	00003825 */ 	or	$a3,$zero,$zero
/*  f100d88:	8fb901d8 */ 	lw	$t9,0x1d8($sp)
/*  f100d8c:	3c0fb900 */ 	lui	$t7,0xb900
/*  f100d90:	3c180050 */ 	lui	$t8,0x50
/*  f100d94:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f100d98:	27b301ba */ 	addiu	$s3,$sp,0x1ba
/*  f100d9c:	27b401b8 */ 	addiu	$s4,$sp,0x1b8
/*  f100da0:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f100da4:	37184240 */ 	ori	$t8,$t8,0x4240
/*  f100da8:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f100dac:	02803825 */ 	or	$a3,$s4,$zero
/*  f100db0:	02603025 */ 	or	$a2,$s3,$zero
/*  f100db4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f100db8:	00002825 */ 	or	$a1,$zero,$zero
/*  f100dbc:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f100dc0:	0fc3fc9d */ 	jal	func0f0ff274
/*  f100dc4:	af380004 */ 	sw	$t8,0x4($t9)
/*  f100dc8:	87b901ba */ 	lh	$t9,0x1ba($sp)
/*  f100dcc:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f100dd0:	2412fff6 */ 	addiu	$s2,$zero,-10
/*  f100dd4:	03310019 */ 	multu	$t9,$s1
/*  f100dd8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f100ddc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f100de0:	02603025 */ 	or	$a2,$s3,$zero
/*  f100de4:	02803825 */ 	or	$a3,$s4,$zero
/*  f100de8:	00007012 */ 	mflo	$t6
/*  f100dec:	a60e0000 */ 	sh	$t6,0x0($s0)
/*  f100df0:	87af01b8 */ 	lh	$t7,0x1b8($sp)
/*  f100df4:	a6120004 */ 	sh	$s2,0x4($s0)
/*  f100df8:	01f10019 */ 	multu	$t7,$s1
/*  f100dfc:	0000c012 */ 	mflo	$t8
/*  f100e00:	a6180002 */ 	sh	$t8,0x2($s0)
/*  f100e04:	0fc3fc9d */ 	jal	func0f0ff274
/*  f100e08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100e0c:	87b901ba */ 	lh	$t9,0x1ba($sp)
/*  f100e10:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f100e14:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f100e18:	03310019 */ 	multu	$t9,$s1
/*  f100e1c:	02603025 */ 	or	$a2,$s3,$zero
/*  f100e20:	02803825 */ 	or	$a3,$s4,$zero
/*  f100e24:	00007012 */ 	mflo	$t6
/*  f100e28:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f100e2c:	87af01b8 */ 	lh	$t7,0x1b8($sp)
/*  f100e30:	a6120010 */ 	sh	$s2,0x10($s0)
/*  f100e34:	01f10019 */ 	multu	$t7,$s1
/*  f100e38:	0000c012 */ 	mflo	$t8
/*  f100e3c:	a618000e */ 	sh	$t8,0xe($s0)
/*  f100e40:	0fc3fc9d */ 	jal	func0f0ff274
/*  f100e44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100e48:	87b901ba */ 	lh	$t9,0x1ba($sp)
/*  f100e4c:	00002025 */ 	or	$a0,$zero,$zero
/*  f100e50:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f100e54:	03310019 */ 	multu	$t9,$s1
/*  f100e58:	02603025 */ 	or	$a2,$s3,$zero
/*  f100e5c:	02803825 */ 	or	$a3,$s4,$zero
/*  f100e60:	00007012 */ 	mflo	$t6
/*  f100e64:	a60e0018 */ 	sh	$t6,0x18($s0)
/*  f100e68:	87af01b8 */ 	lh	$t7,0x1b8($sp)
/*  f100e6c:	a612001c */ 	sh	$s2,0x1c($s0)
/*  f100e70:	01f10019 */ 	multu	$t7,$s1
/*  f100e74:	0000c012 */ 	mflo	$t8
/*  f100e78:	a618001a */ 	sh	$t8,0x1a($s0)
/*  f100e7c:	0fc3fc9d */ 	jal	func0f0ff274
/*  f100e80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f100e84:	87b901ba */ 	lh	$t9,0x1ba($sp)
/*  f100e88:	8602000c */ 	lh	$v0,0xc($s0)
/*  f100e8c:	8607001a */ 	lh	$a3,0x1a($s0)
/*  f100e90:	03310019 */ 	multu	$t9,$s1
/*  f100e94:	86030002 */ 	lh	$v1,0x2($s0)
/*  f100e98:	00e33023 */ 	subu	$a2,$a3,$v1
/*  f100e9c:	00007012 */ 	mflo	$t6
/*  f100ea0:	a60e0024 */ 	sh	$t6,0x24($s0)
/*  f100ea4:	87af01b8 */ 	lh	$t7,0x1b8($sp)
/*  f100ea8:	86050024 */ 	lh	$a1,0x24($s0)
/*  f100eac:	a6120028 */ 	sh	$s2,0x28($s0)
/*  f100eb0:	01f10019 */ 	multu	$t7,$s1
/*  f100eb4:	00452023 */ 	subu	$a0,$v0,$a1
/*  f100eb8:	a6120034 */ 	sh	$s2,0x34($s0)
/*  f100ebc:	a6120040 */ 	sh	$s2,0x40($s0)
/*  f100ec0:	a612004c */ 	sh	$s2,0x4c($s0)
/*  f100ec4:	a6120058 */ 	sh	$s2,0x58($s0)
/*  f100ec8:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f100ecc:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f100ed0:	a200001f */ 	sb	$zero,0x1f($s0)
/*  f100ed4:	a200002b */ 	sb	$zero,0x2b($s0)
/*  f100ed8:	0000c012 */ 	mflo	$t8
/*  f100edc:	a6180026 */ 	sh	$t8,0x26($s0)
/*  f100ee0:	04810003 */ 	bgez	$a0,.L0f100ef0
/*  f100ee4:	0004c8c3 */ 	sra	$t9,$a0,0x3
/*  f100ee8:	24810007 */ 	addiu	$at,$a0,0x7
/*  f100eec:	0001c8c3 */ 	sra	$t9,$at,0x3
.L0f100ef0:
/*  f100ef0:	00197400 */ 	sll	$t6,$t9,0x10
/*  f100ef4:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f100ef8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f100efc:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f100f00:	860e000e */ 	lh	$t6,0xe($s0)
/*  f100f04:	04c10003 */ 	bgez	$a2,.L0f100f14
/*  f100f08:	0006c0c3 */ 	sra	$t8,$a2,0x3
/*  f100f0c:	24c10007 */ 	addiu	$at,$a2,0x7
/*  f100f10:	0001c0c3 */ 	sra	$t8,$at,0x3
.L0f100f14:
/*  f100f14:	03003025 */ 	or	$a2,$t8,$zero
/*  f100f18:	0044c823 */ 	subu	$t9,$v0,$a0
/*  f100f1c:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f100f20:	860f0018 */ 	lh	$t7,0x18($s0)
/*  f100f24:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f100f28:	0066c021 */ 	addu	$t8,$v1,$a2
/*  f100f2c:	a60e003e */ 	sh	$t6,0x3e($s0)
/*  f100f30:	860e0026 */ 	lh	$t6,0x26($s0)
/*  f100f34:	a6180032 */ 	sh	$t8,0x32($s0)
/*  f100f38:	a619003c */ 	sh	$t9,0x3c($s0)
/*  f100f3c:	00e6c023 */ 	subu	$t8,$a3,$a2
/*  f100f40:	a618004a */ 	sh	$t8,0x4a($s0)
/*  f100f44:	00a4c821 */ 	addu	$t9,$a1,$a0
/*  f100f48:	a60f0048 */ 	sh	$t7,0x48($s0)
/*  f100f4c:	a6190054 */ 	sh	$t9,0x54($s0)
/*  f100f50:	a2020037 */ 	sb	$v0,0x37($s0)
/*  f100f54:	a2020043 */ 	sb	$v0,0x43($s0)
/*  f100f58:	a202004f */ 	sb	$v0,0x4f($s0)
/*  f100f5c:	a202005b */ 	sb	$v0,0x5b($s0)
/*  f100f60:	3c0f2222 */ 	lui	$t7,0x2222
/*  f100f64:	a60e0056 */ 	sh	$t6,0x56($s0)
/*  f100f68:	35ef2200 */ 	ori	$t7,$t7,0x2200
/*  f100f6c:	2418004f */ 	addiu	$t8,$zero,0x4f
/*  f100f70:	aeaf0000 */ 	sw	$t7,0x0($s5)
/*  f100f74:	aeb80004 */ 	sw	$t8,0x4($s5)
/*  f100f78:	8fb101d8 */ 	lw	$s1,0x1d8($sp)
/*  f100f7c:	3c0f0704 */ 	lui	$t7,0x704
/*  f100f80:	35ef0008 */ 	ori	$t7,$t7,0x8
/*  f100f84:	262e0008 */ 	addiu	$t6,$s1,0x8
/*  f100f88:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f100f8c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f100f90:	0c012d20 */ 	jal	func0004b480
/*  f100f94:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f100f98:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f100f9c:	8fb201d8 */ 	lw	$s2,0x1d8($sp)
/*  f100fa0:	3c0e0470 */ 	lui	$t6,0x470
/*  f100fa4:	35ce0060 */ 	ori	$t6,$t6,0x60
/*  f100fa8:	26590008 */ 	addiu	$t9,$s2,0x8
/*  f100fac:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f100fb0:	02002025 */ 	or	$a0,$s0,$zero
/*  f100fb4:	0c012d20 */ 	jal	func0004b480
/*  f100fb8:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*  f100fbc:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f100fc0:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f100fc4:	3c19b100 */ 	lui	$t9,0xb100
/*  f100fc8:	37390046 */ 	ori	$t9,$t9,0x46
/*  f100fcc:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f100fd0:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f100fd4:	240e7654 */ 	addiu	$t6,$zero,0x7654
/*  f100fd8:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f100fdc:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f100fe0:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f100fe4:	3c19b100 */ 	lui	$t9,0xb100
/*  f100fe8:	3c0e4510 */ 	lui	$t6,0x4510
/*  f100fec:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f100ff0:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f100ff4:	35ce3740 */ 	ori	$t6,$t6,0x3740
/*  f100ff8:	37390507 */ 	ori	$t9,$t9,0x507
/*  f100ffc:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f101000:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f101004:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f101008:	3c0e7326 */ 	lui	$t6,0x7326
/*  f10100c:	3c19b100 */ 	lui	$t9,0xb100
/*  f101010:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f101014:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f101018:	37396316 */ 	ori	$t9,$t9,0x6316
/*  f10101c:	35ce5621 */ 	ori	$t6,$t6,0x5621
/*  f101020:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f101024:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f101028:	0fc35272 */ 	jal	func0f0d49c8
/*  f10102c:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f101030:	3c168007 */ 	lui	$s6,%hi(var800719a0)
/*  f101034:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f101038:	26d619a0 */ 	addiu	$s6,$s6,%lo(var800719a0)
/*  f10103c:	00009825 */ 	or	$s3,$zero,$zero
/*  f101040:	27b5015c */ 	addiu	$s5,$sp,0x15c
/*  f101044:	00008825 */ 	or	$s1,$zero,$zero
.L0f101048:
/*  f101048:	00132400 */ 	sll	$a0,$s3,0x10
.L0f10104c:
/*  f10104c:	00112c00 */ 	sll	$a1,$s1,0x10
/*  f101050:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f101054:	00047c03 */ 	sra	$t7,$a0,0x10
/*  f101058:	00008025 */ 	or	$s0,$zero,$zero
/*  f10105c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f101060:	03002825 */ 	or	$a1,$t8,$zero
/*  f101064:	27a60182 */ 	addiu	$a2,$sp,0x182
/*  f101068:	27a70180 */ 	addiu	$a3,$sp,0x180
/*  f10106c:	0fc3fc9d */ 	jal	func0f0ff274
/*  f101070:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f101074:	3c0e800a */ 	lui	$t6,0x800a
/*  f101078:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f10107c:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f101080:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f101084:	01de0019 */ 	multu	$t6,$s8
/*  f101088:	02799021 */ 	addu	$s2,$s3,$t9
/*  f10108c:	afa001d0 */ 	sw	$zero,0x1d0($sp)
/*  f101090:	3c0e800a */ 	lui	$t6,0x800a
/*  f101094:	00007812 */ 	mflo	$t7
/*  f101098:	02efc021 */ 	addu	$t8,$s7,$t7
/*  f10109c:	9319000e */ 	lbu	$t9,0xe($t8)
/*  f1010a0:	16590002 */ 	bne	$s2,$t9,.L0f1010ac
/*  f1010a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1010a8:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f1010ac:
/*  f1010ac:	81cfdfeb */ 	lb	$t7,-0x2015($t6)
/*  f1010b0:	05e10029 */ 	bgez	$t7,.L0f101158
/*  f1010b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1010b8:	0fc3f7a3 */ 	jal	func0f0fde8c
/*  f1010bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1010c0:	04400025 */ 	bltz	$v0,.L0f101158
/*  f1010c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1010c8:	16000042 */ 	bnez	$s0,.L0f1011d4
/*  f1010cc:	3c18800a */ 	lui	$t8,0x800a
/*  f1010d0:	8f1821b8 */ 	lw	$t8,0x21b8($t8)
/*  f1010d4:	031e0019 */ 	multu	$t8,$s8
/*  f1010d8:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f1010dc:	0000c812 */ 	mflo	$t9
/*  f1010e0:	02f97021 */ 	addu	$t6,$s7,$t9
/*  f1010e4:	81cf0000 */ 	lb	$t7,0x0($t6)
/*  f1010e8:	3c19800a */ 	lui	$t9,0x800a
/*  f1010ec:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f1010f0:	29e10002 */ 	slti	$at,$t7,0x2
/*  f1010f4:	14200037 */ 	bnez	$at,.L0f1011d4
/*  f1010f8:	00117080 */ 	sll	$t6,$s1,0x2
/*  f1010fc:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f101100:	02ce7821 */ 	addu	$t7,$s6,$t6
/*  f101104:	01f3c021 */ 	addu	$t8,$t7,$s3
/*  f101108:	93040000 */ 	lbu	$a0,0x0($t8)
/*  f10110c:	8f39a478 */ 	lw	$t9,-0x5b88($t9)
/*  f101110:	24010007 */ 	addiu	$at,$zero,0x7
/*  f101114:	14810007 */ 	bne	$a0,$at,.L0f101134
/*  f101118:	8f230004 */ 	lw	$v1,0x4($t9)
/*  f10111c:	8c790014 */ 	lw	$t9,0x14($v1)
/*  f101120:	332e0400 */ 	andi	$t6,$t9,0x400
/*  f101124:	11c0002b */ 	beqz	$t6,.L0f1011d4
/*  f101128:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10112c:	10000029 */ 	beqz	$zero,.L0f1011d4
/*  f101130:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f101134:
/*  f101134:	24010001 */ 	addiu	$at,$zero,0x1
/*  f101138:	14810026 */ 	bne	$a0,$at,.L0f1011d4
/*  f10113c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101140:	8c6f0014 */ 	lw	$t7,0x14($v1)
/*  f101144:	31f80400 */ 	andi	$t8,$t7,0x400
/*  f101148:	17000022 */ 	bnez	$t8,.L0f1011d4
/*  f10114c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101150:	10000020 */ 	beqz	$zero,.L0f1011d4
/*  f101154:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f101158:
/*  f101158:	3c19800a */ 	lui	$t9,0x800a
/*  f10115c:	8f39a2d8 */ 	lw	$t9,-0x5d28($t9)
/*  f101160:	1320001c */ 	beqz	$t9,.L0f1011d4
/*  f101164:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101168:	1600001a */ 	bnez	$s0,.L0f1011d4
/*  f10116c:	3c0e800a */ 	lui	$t6,0x800a
/*  f101170:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f101174:	01de0019 */ 	multu	$t6,$s8
/*  f101178:	00117080 */ 	sll	$t6,$s1,0x2
/*  f10117c:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f101180:	00007812 */ 	mflo	$t7
/*  f101184:	02efc021 */ 	addu	$t8,$s7,$t7
/*  f101188:	83190000 */ 	lb	$t9,0x0($t8)
/*  f10118c:	02ce7821 */ 	addu	$t7,$s6,$t6
/*  f101190:	01f3c021 */ 	addu	$t8,$t7,$s3
/*  f101194:	2b210002 */ 	slti	$at,$t9,0x2
/*  f101198:	1420000e */ 	bnez	$at,.L0f1011d4
/*  f10119c:	8fae01c4 */ 	lw	$t6,0x1c4($sp)
/*  f1011a0:	93190000 */ 	lbu	$t9,0x0($t8)
/*  f1011a4:	3c18800b */ 	lui	$t8,0x800b
/*  f1011a8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1011ac:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1011b0:	8f18c4d0 */ 	lw	$t8,-0x3b30($t8)
/*  f1011b4:	3c02800b */ 	lui	$v0,0x800b
/*  f1011b8:	00591021 */ 	addu	$v0,$v0,$t9
/*  f1011bc:	8f1902d4 */ 	lw	$t9,0x2d4($t8)
/*  f1011c0:	9042cb78 */ 	lbu	$v0,-0x3488($v0)
/*  f1011c4:	93230079 */ 	lbu	$v1,0x79($t9)
/*  f1011c8:	14430002 */ 	bne	$v0,$v1,.L0f1011d4
/*  f1011cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1011d0:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f1011d4:
/*  f1011d4:	3c0e800a */ 	lui	$t6,0x800a
/*  f1011d8:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f1011dc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1011e0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1011e4:	91cf0250 */ 	lbu	$t7,0x250($t6)
/*  f1011e8:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f1011ec:	15e10003 */ 	bne	$t7,$at,.L0f1011fc
/*  f1011f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1011f4:	3c144f4f */ 	lui	$s4,0x4f4f
/*  f1011f8:	36944f7f */ 	ori	$s4,$s4,0x4f7f
.L0f1011fc:
/*  f1011fc:	0fc3f8a0 */ 	jal	func0f0fe280
/*  f101200:	02a03025 */ 	or	$a2,$s5,$zero
/*  f101204:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f101208:	1662000f */ 	bne	$s3,$v0,.L0f101248
/*  f10120c:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f101210:	5622000e */ 	bnel	$s1,$v0,.L0f10124c
/*  f101214:	8fb901d0 */ 	lw	$t9,0x1d0($sp)
/*  f101218:	0fc3fc2f */ 	jal	func0f0ff0bc
/*  f10121c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101220:	14400011 */ 	bnez	$v0,.L0f101268
/*  f101224:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f101228:	87b80180 */ 	lh	$t8,0x180($sp)
/*  f10122c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f101230:	02803025 */ 	or	$a2,$s4,$zero
/*  f101234:	87a70182 */ 	lh	$a3,0x182($sp)
/*  f101238:	0fc3fdbd */ 	jal	func0f0ff6f4
/*  f10123c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f101240:	10000009 */ 	beqz	$zero,.L0f101268
/*  f101244:	afa201d8 */ 	sw	$v0,0x1d8($sp)
.L0f101248:
/*  f101248:	8fb901d0 */ 	lw	$t9,0x1d0($sp)
.L0f10124c:
/*  f10124c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f101250:	87a60182 */ 	lh	$a2,0x182($sp)
/*  f101254:	87a70180 */ 	lh	$a3,0x180($sp)
/*  f101258:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f10125c:	0fc4004a */ 	jal	func0f100128
/*  f101260:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f101264:	afa201d8 */ 	sw	$v0,0x1d8($sp)
.L0f101268:
/*  f101268:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f10126c:	00117400 */ 	sll	$t6,$s1,0x10
/*  f101270:	000e8c03 */ 	sra	$s1,$t6,0x10
/*  f101274:	2a210003 */ 	slti	$at,$s1,0x3
/*  f101278:	5420ff74 */ 	bnezl	$at,.L0f10104c
/*  f10127c:	00132400 */ 	sll	$a0,$s3,0x10
/*  f101280:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f101284:	0013c400 */ 	sll	$t8,$s3,0x10
/*  f101288:	00189c03 */ 	sra	$s3,$t8,0x10
/*  f10128c:	2a610003 */ 	slti	$at,$s3,0x3
/*  f101290:	5420ff6d */ 	bnezl	$at,.L0f101048
/*  f101294:	00008825 */ 	or	$s1,$zero,$zero
/*  f101298:	3c0e800a */ 	lui	$t6,0x800a
/*  f10129c:	81cfdfeb */ 	lb	$t7,-0x2015($t6)
/*  f1012a0:	05e10004 */ 	bgez	$t7,.L0f1012b4
/*  f1012a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1012a8:	0fc3f7a3 */ 	jal	func0f0fde8c
/*  f1012ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1012b0:	04410011 */ 	bgez	$v0,.L0f1012f8
.L0f1012b4:
/*  f1012b4:	3c18800a */ 	lui	$t8,0x800a
/*  f1012b8:	8f18a2d8 */ 	lw	$t8,-0x5d28($t8)
/*  f1012bc:	3c19800a */ 	lui	$t9,0x800a
/*  f1012c0:	1300000d */ 	beqz	$t8,.L0f1012f8
/*  f1012c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1012c8:	8f3921b8 */ 	lw	$t9,0x21b8($t9)
/*  f1012cc:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f1012d0:	033e0019 */ 	multu	$t9,$s8
/*  f1012d4:	00007012 */ 	mflo	$t6
/*  f1012d8:	02ee7821 */ 	addu	$t7,$s7,$t6
/*  f1012dc:	81e20000 */ 	lb	$v0,0x0($t7)
/*  f1012e0:	28410002 */ 	slti	$at,$v0,0x2
/*  f1012e4:	14200004 */ 	bnez	$at,.L0f1012f8
/*  f1012e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1012ec:	0fc3fdef */ 	jal	func0f0ff7bc
/*  f1012f0:	2445fffe */ 	addiu	$a1,$v0,-2
/*  f1012f4:	afa201d8 */ 	sw	$v0,0x1d8($sp)
.L0f1012f8:
/*  f1012f8:	3c18800a */ 	lui	$t8,0x800a
/*  f1012fc:	8f1821b8 */ 	lw	$t8,0x21b8($t8)
/*  f101300:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f101304:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f101308:	031e0019 */ 	multu	$t8,$s8
/*  f10130c:	0000c812 */ 	mflo	$t9
/*  f101310:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f101314:	820e0000 */ 	lb	$t6,0x0($s0)
/*  f101318:	29c10002 */ 	slti	$at,$t6,0x2
/*  f10131c:	14200005 */ 	bnez	$at,.L0f101334
/*  f101320:	24010001 */ 	addiu	$at,$zero,0x1
/*  f101324:	16610003 */ 	bne	$s3,$at,.L0f101334
/*  f101328:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10132c:	12210154 */ 	beq	$s1,$at,.L0f101880
/*  f101330:	00000000 */ 	sll	$zero,$zero,0x0
.L0f101334:
/*  f101334:	8c4f006c */ 	lw	$t7,0x6c($v0)
/*  f101338:	24120006 */ 	addiu	$s2,$zero,0x6
/*  f10133c:	24130006 */ 	addiu	$s3,$zero,0x6
/*  f101340:	51e00004 */ 	beqzl	$t7,.L0f101354
/*  f101344:	00003025 */ 	or	$a2,$zero,$zero
/*  f101348:	10000002 */ 	beqz	$zero,.L0f101354
/*  f10134c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f101350:	00003025 */ 	or	$a2,$zero,$zero
.L0f101354:
/*  f101354:	8c580068 */ 	lw	$t8,0x68($v0)
/*  f101358:	00002825 */ 	or	$a1,$zero,$zero
/*  f10135c:	13000003 */ 	beqz	$t8,.L0f10136c
/*  f101360:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101364:	10000001 */ 	beqz	$zero,.L0f10136c
/*  f101368:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f10136c:
/*  f10136c:	8c590064 */ 	lw	$t9,0x64($v0)
/*  f101370:	00002025 */ 	or	$a0,$zero,$zero
/*  f101374:	13200003 */ 	beqz	$t9,.L0f101384
/*  f101378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10137c:	10000001 */ 	beqz	$zero,.L0f101384
/*  f101380:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f101384:
/*  f101384:	8c4e0070 */ 	lw	$t6,0x70($v0)
/*  f101388:	00001825 */ 	or	$v1,$zero,$zero
/*  f10138c:	11c00003 */ 	beqz	$t6,.L0f10139c
/*  f101390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101394:	10000001 */ 	beqz	$zero,.L0f10139c
/*  f101398:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f10139c:
/*  f10139c:	00647821 */ 	addu	$t7,$v1,$a0
/*  f1013a0:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f1013a4:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f1013a8:	2b210002 */ 	slti	$at,$t9,0x2
/*  f1013ac:	14200003 */ 	bnez	$at,.L0f1013bc
/*  f1013b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1013b4:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f1013b8:	24130003 */ 	addiu	$s3,$zero,0x3
.L0f1013bc:
/*  f1013bc:	0c0068f7 */ 	jal	func0001a3dc
/*  f1013c0:	c60c001c */ 	lwc1	$f12,0x1c($s0)
/*  f1013c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f1013c8:	44812000 */ 	mtc1	$at,$f4
/*  f1013cc:	3c0142fe */ 	lui	$at,0x42fe
/*  f1013d0:	44814000 */ 	mtc1	$at,$f8
/*  f1013d4:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f1013d8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1013dc:	3c014f00 */ 	lui	$at,0x4f00
/*  f1013e0:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f1013e4:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f1013e8:	444ef800 */ 	cfc1	$t6,$31
/*  f1013ec:	44c2f800 */ 	ctc1	$v0,$31
/*  f1013f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1013f4:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f1013f8:	4442f800 */ 	cfc1	$v0,$31
/*  f1013fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101400:	30420078 */ 	andi	$v0,$v0,0x78
/*  f101404:	50400013 */ 	beqzl	$v0,.L0f101454
/*  f101408:	44028000 */ 	mfc1	$v0,$f16
/*  f10140c:	44818000 */ 	mtc1	$at,$f16
/*  f101410:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f101414:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f101418:	44c2f800 */ 	ctc1	$v0,$31
/*  f10141c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101420:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f101424:	4442f800 */ 	cfc1	$v0,$31
/*  f101428:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10142c:	30420078 */ 	andi	$v0,$v0,0x78
/*  f101430:	14400005 */ 	bnez	$v0,.L0f101448
/*  f101434:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101438:	44028000 */ 	mfc1	$v0,$f16
/*  f10143c:	3c018000 */ 	lui	$at,0x8000
/*  f101440:	10000007 */ 	beqz	$zero,.L0f101460
/*  f101444:	00411025 */ 	or	$v0,$v0,$at
.L0f101448:
/*  f101448:	10000005 */ 	beqz	$zero,.L0f101460
/*  f10144c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f101450:	44028000 */ 	mfc1	$v0,$f16
.L0f101454:
/*  f101454:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101458:	0440fffb */ 	bltz	$v0,.L0f101448
/*  f10145c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f101460:
/*  f101460:	44cef800 */ 	ctc1	$t6,$31
/*  f101464:	3c0e800a */ 	lui	$t6,0x800a
/*  f101468:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f10146c:	3c01ff00 */ 	lui	$at,0xff00
/*  f101470:	342100ff */ 	ori	$at,$at,0xff
/*  f101474:	00027a00 */ 	sll	$t7,$v0,0x8
/*  f101478:	01e1c025 */ 	or	$t8,$t7,$at
/*  f10147c:	91cf0250 */ 	lbu	$t7,0x250($t6)
/*  f101480:	0002cc00 */ 	sll	$t9,$v0,0x10
/*  f101484:	24010002 */ 	addiu	$at,$zero,0x2
/*  f101488:	15e10003 */ 	bne	$t7,$at,.L0f101498
/*  f10148c:	0319a025 */ 	or	$s4,$t8,$t9
/*  f101490:	3c144f4f */ 	lui	$s4,0x4f4f
/*  f101494:	36944f7f */ 	ori	$s4,$s4,0x4f7f
.L0f101498:
/*  f101498:	0fc54df7 */ 	jal	func0f1537dc
/*  f10149c:	02802825 */ 	or	$a1,$s4,$zero
/*  f1014a0:	3c18800a */ 	lui	$t8,0x800a
/*  f1014a4:	8f1821b8 */ 	lw	$t8,0x21b8($t8)
/*  f1014a8:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f1014ac:	031e0019 */ 	multu	$t8,$s8
/*  f1014b0:	0000c812 */ 	mflo	$t9
/*  f1014b4:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f1014b8:	86110004 */ 	lh	$s1,0x4($s0)
/*  f1014bc:	920f000e */ 	lbu	$t7,0xe($s0)
/*  f1014c0:	06210003 */ 	bgez	$s1,.L0f1014d0
/*  f1014c4:	00117043 */ 	sra	$t6,$s1,0x1
/*  f1014c8:	26210001 */ 	addiu	$at,$s1,0x1
/*  f1014cc:	00017043 */ 	sra	$t6,$at,0x1
.L0f1014d0:
/*  f1014d0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1014d4:	15e1003c */ 	bne	$t7,$at,.L0f1015c8
/*  f1014d8:	01c08825 */ 	or	$s1,$t6,$zero
/*  f1014dc:	0fc3fc2f */ 	jal	func0f0ff0bc
/*  f1014e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1014e4:	10400005 */ 	beqz	$v0,.L0f1014fc
/*  f1014e8:	3c18800a */ 	lui	$t8,0x800a
/*  f1014ec:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f1014f0:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f1014f4:	10000034 */ 	beqz	$zero,.L0f1015c8
/*  f1014f8:	00009825 */ 	or	$s3,$zero,$zero
.L0f1014fc:
/*  f1014fc:	8f18a02c */ 	lw	$t8,-0x5fd4($t8)
/*  f101500:	3c19800a */ 	lui	$t9,0x800a
/*  f101504:	3c0e800a */ 	lui	$t6,0x800a
/*  f101508:	13000003 */ 	beqz	$t8,.L0f101518
/*  f10150c:	3c0f800a */ 	lui	$t7,0x800a
/*  f101510:	10000002 */ 	beqz	$zero,.L0f10151c
/*  f101514:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f101518:
/*  f101518:	00003025 */ 	or	$a2,$zero,$zero
.L0f10151c:
/*  f10151c:	8f39a028 */ 	lw	$t9,-0x5fd8($t9)
/*  f101520:	00002825 */ 	or	$a1,$zero,$zero
/*  f101524:	00002025 */ 	or	$a0,$zero,$zero
/*  f101528:	13200003 */ 	beqz	$t9,.L0f101538
/*  f10152c:	00001825 */ 	or	$v1,$zero,$zero
/*  f101530:	10000001 */ 	beqz	$zero,.L0f101538
/*  f101534:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f101538:
/*  f101538:	8dcea024 */ 	lw	$t6,-0x5fdc($t6)
/*  f10153c:	27b00118 */ 	addiu	$s0,$sp,0x118
/*  f101540:	11c00003 */ 	beqz	$t6,.L0f101550
/*  f101544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101548:	10000001 */ 	beqz	$zero,.L0f101550
/*  f10154c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f101550:
/*  f101550:	8defa030 */ 	lw	$t7,-0x5fd0($t7)
/*  f101554:	11e00003 */ 	beqz	$t7,.L0f101564
/*  f101558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10155c:	10000001 */ 	beqz	$zero,.L0f101564
/*  f101560:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f101564:
/*  f101564:	0064c021 */ 	addu	$t8,$v1,$a0
/*  f101568:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f10156c:	03267021 */ 	addu	$t6,$t9,$a2
/*  f101570:	29c10002 */ 	slti	$at,$t6,0x2
/*  f101574:	14200014 */ 	bnez	$at,.L0f1015c8
/*  f101578:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f10157c:	27a50114 */ 	addiu	$a1,$sp,0x114
/*  f101580:	0fc3f8a0 */ 	jal	func0f0fe280
/*  f101584:	02003025 */ 	or	$a2,$s0,$zero
/*  f101588:	3c0f800a */ 	lui	$t7,0x800a
/*  f10158c:	8def21b4 */ 	lw	$t7,0x21b4($t7)
/*  f101590:	3c07800a */ 	lui	$a3,0x800a
/*  f101594:	8ce721b0 */ 	lw	$a3,0x21b0($a3)
/*  f101598:	27a4013c */ 	addiu	$a0,$sp,0x13c
/*  f10159c:	27a50138 */ 	addiu	$a1,$sp,0x138
/*  f1015a0:	02003025 */ 	or	$a2,$s0,$zero
/*  f1015a4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1015a8:	0fc55cbe */ 	jal	func0f1572f8
/*  f1015ac:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1015b0:	8fb10138 */ 	lw	$s1,0x138($sp)
/*  f1015b4:	06210003 */ 	bgez	$s1,.L0f1015c4
/*  f1015b8:	0011c043 */ 	sra	$t8,$s1,0x1
/*  f1015bc:	26210001 */ 	addiu	$at,$s1,0x1
/*  f1015c0:	0001c043 */ 	sra	$t8,$at,0x1
.L0f1015c4:
/*  f1015c4:	27110002 */ 	addiu	$s1,$t8,0x2
.L0f1015c8:
/*  f1015c8:	3c0f800a */ 	lui	$t7,0x800a
/*  f1015cc:	8def21b8 */ 	lw	$t7,0x21b8($t7)
/*  f1015d0:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
/*  f1015d4:	3c068008 */ 	lui	$a2,%hi(var8007fac0)
/*  f1015d8:	01fe0019 */ 	multu	$t7,$s8
/*  f1015dc:	24c6fac0 */ 	addiu	$a2,$a2,%lo(var8007fac0)
/*  f1015e0:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f1015e4:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f1015e8:	3c16f600 */ 	lui	$s6,0xf600
/*  f1015ec:	0000c012 */ 	mflo	$t8
/*  f1015f0:	02f88021 */ 	addu	$s0,$s7,$t8
/*  f1015f4:	86190006 */ 	lh	$t9,0x6($s0)
/*  f1015f8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f1015fc:	03317021 */ 	addu	$t6,$t9,$s1
/*  f101600:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f101604:	01f80019 */ 	multu	$t7,$t8
/*  f101608:	86180008 */ 	lh	$t8,0x8($s0)
/*  f10160c:	0000c812 */ 	mflo	$t9
/*  f101610:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f101614:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f101618:	0312c823 */ 	subu	$t9,$t8,$s2
/*  f10161c:	272e0001 */ 	addiu	$t6,$t9,0x1
/*  f101620:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f101624:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f101628:	03367025 */ 	or	$t6,$t9,$s6
/*  f10162c:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f101630:	3c19800a */ 	lui	$t9,0x800a
/*  f101634:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f101638:	8f3921b8 */ 	lw	$t9,0x21b8($t9)
/*  f10163c:	033e0019 */ 	multu	$t9,$s8
/*  f101640:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f101644:	00007012 */ 	mflo	$t6
/*  f101648:	02ee8021 */ 	addu	$s0,$s7,$t6
/*  f10164c:	860f0006 */ 	lh	$t7,0x6($s0)
/*  f101650:	01f1c023 */ 	subu	$t8,$t7,$s1
/*  f101654:	03190019 */ 	multu	$t8,$t9
/*  f101658:	86190008 */ 	lh	$t9,0x8($s0)
/*  f10165c:	00007012 */ 	mflo	$t6
/*  f101660:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f101664:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f101668:	03327023 */ 	subu	$t6,$t9,$s2
/*  f10166c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f101670:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f101674:	03387025 */ 	or	$t6,$t9,$t8
/*  f101678:	3c18800a */ 	lui	$t8,0x800a
/*  f10167c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f101680:	8f1821b8 */ 	lw	$t8,0x21b8($t8)
/*  f101684:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f101688:	031e0019 */ 	multu	$t8,$s8
/*  f10168c:	24790008 */ 	addiu	$t9,$v1,0x8
/*  f101690:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f101694:	00007012 */ 	mflo	$t6
/*  f101698:	02ee8021 */ 	addu	$s0,$s7,$t6
/*  f10169c:	860f0006 */ 	lh	$t7,0x6($s0)
/*  f1016a0:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1016a4:	01f1c821 */ 	addu	$t9,$t7,$s1
/*  f1016a8:	27380001 */ 	addiu	$t8,$t9,0x1
/*  f1016ac:	030e0019 */ 	multu	$t8,$t6
/*  f1016b0:	860e0008 */ 	lh	$t6,0x8($s0)
/*  f1016b4:	00007812 */ 	mflo	$t7
/*  f1016b8:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f1016bc:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f1016c0:	01d37821 */ 	addu	$t7,$t6,$s3
/*  f1016c4:	25f90001 */ 	addiu	$t9,$t7,0x1
/*  f1016c8:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1016cc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1016d0:	01f6c825 */ 	or	$t9,$t7,$s6
/*  f1016d4:	03387025 */ 	or	$t6,$t9,$t8
/*  f1016d8:	3c0f800a */ 	lui	$t7,0x800a
/*  f1016dc:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f1016e0:	8def21b8 */ 	lw	$t7,0x21b8($t7)
/*  f1016e4:	01fe0019 */ 	multu	$t7,$s8
/*  f1016e8:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f1016ec:	0000c812 */ 	mflo	$t9
/*  f1016f0:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f1016f4:	86180006 */ 	lh	$t8,0x6($s0)
/*  f1016f8:	03117023 */ 	subu	$t6,$t8,$s1
/*  f1016fc:	01cf0019 */ 	multu	$t6,$t7
/*  f101700:	860f0008 */ 	lh	$t7,0x8($s0)
/*  f101704:	0000c812 */ 	mflo	$t9
/*  f101708:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f10170c:	00187380 */ 	sll	$t6,$t8,0xe
/*  f101710:	01f3c821 */ 	addu	$t9,$t7,$s3
/*  f101714:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f101718:	00187880 */ 	sll	$t7,$t8,0x2
/*  f10171c:	01eec825 */ 	or	$t9,$t7,$t6
/*  f101720:	3c0e800a */ 	lui	$t6,0x800a
/*  f101724:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f101728:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f10172c:	8fa501d8 */ 	lw	$a1,0x1d8($sp)
/*  f101730:	01de0019 */ 	multu	$t6,$s8
/*  f101734:	24af0008 */ 	addiu	$t7,$a1,0x8
/*  f101738:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f10173c:	0000c812 */ 	mflo	$t9
/*  f101740:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f101744:	86180006 */ 	lh	$t8,0x6($s0)
/*  f101748:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f10174c:	03117823 */ 	subu	$t7,$t8,$s1
/*  f101750:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f101754:	01d90019 */ 	multu	$t6,$t9
/*  f101758:	86190008 */ 	lh	$t9,0x8($s0)
/*  f10175c:	0000c012 */ 	mflo	$t8
/*  f101760:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f101764:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f101768:	0333c021 */ 	addu	$t8,$t9,$s3
/*  f10176c:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f101770:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f101774:	0336c025 */ 	or	$t8,$t9,$s6
/*  f101778:	030e7825 */ 	or	$t7,$t8,$t6
/*  f10177c:	3c19800a */ 	lui	$t9,0x800a
/*  f101780:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f101784:	8f3921b8 */ 	lw	$t9,0x21b8($t9)
/*  f101788:	033e0019 */ 	multu	$t9,$s8
/*  f10178c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f101790:	0000c012 */ 	mflo	$t8
/*  f101794:	02f88021 */ 	addu	$s0,$s7,$t8
/*  f101798:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f10179c:	01d17823 */ 	subu	$t7,$t6,$s1
/*  f1017a0:	01f90019 */ 	multu	$t7,$t9
/*  f1017a4:	86190008 */ 	lh	$t9,0x8($s0)
/*  f1017a8:	0000c012 */ 	mflo	$t8
/*  f1017ac:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1017b0:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1017b4:	0332c023 */ 	subu	$t8,$t9,$s2
/*  f1017b8:	270e0001 */ 	addiu	$t6,$t8,0x1
/*  f1017bc:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1017c0:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f1017c4:	030f7025 */ 	or	$t6,$t8,$t7
/*  f1017c8:	3c0f800a */ 	lui	$t7,0x800a
/*  f1017cc:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f1017d0:	8def21b8 */ 	lw	$t7,0x21b8($t7)
/*  f1017d4:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
/*  f1017d8:	01fe0019 */ 	multu	$t7,$s8
/*  f1017dc:	24580008 */ 	addiu	$t8,$v0,0x8
/*  f1017e0:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f1017e4:	00007012 */ 	mflo	$t6
/*  f1017e8:	02ee8021 */ 	addu	$s0,$s7,$t6
/*  f1017ec:	86190006 */ 	lh	$t9,0x6($s0)
/*  f1017f0:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1017f4:	0331c021 */ 	addu	$t8,$t9,$s1
/*  f1017f8:	270f0001 */ 	addiu	$t7,$t8,0x1
/*  f1017fc:	01ee0019 */ 	multu	$t7,$t6
/*  f101800:	860e0008 */ 	lh	$t6,0x8($s0)
/*  f101804:	0000c812 */ 	mflo	$t9
/*  f101808:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f10180c:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f101810:	01d3c821 */ 	addu	$t9,$t6,$s3
/*  f101814:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f101818:	00187080 */ 	sll	$t6,$t8,0x2
/*  f10181c:	01d6c825 */ 	or	$t9,$t6,$s6
/*  f101820:	032fc025 */ 	or	$t8,$t9,$t7
/*  f101824:	3c0e800a */ 	lui	$t6,0x800a
/*  f101828:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f10182c:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f101830:	01de0019 */ 	multu	$t6,$s8
/*  f101834:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f101838:	0000c812 */ 	mflo	$t9
/*  f10183c:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f101840:	860f0006 */ 	lh	$t7,0x6($s0)
/*  f101844:	01f1c021 */ 	addu	$t8,$t7,$s1
/*  f101848:	030e0019 */ 	multu	$t8,$t6
/*  f10184c:	860e0008 */ 	lh	$t6,0x8($s0)
/*  f101850:	0000c812 */ 	mflo	$t9
/*  f101854:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f101858:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f10185c:	01d2c823 */ 	subu	$t9,$t6,$s2
/*  f101860:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f101864:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f101868:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f10186c:	03387825 */ 	or	$t7,$t9,$t8
/*  f101870:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f101874:	0fc54e0e */ 	jal	func0f153838
/*  f101878:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f10187c:	afa201d8 */ 	sw	$v0,0x1d8($sp)
.L0f101880:
/*  f101880:	0fc54de0 */ 	jal	func0f153780
/*  f101884:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f101888:	3c03800a */ 	lui	$v1,0x800a
/*  f10188c:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f101890:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f101894:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f101898:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f10189c:	8c621c04 */ 	lw	$v0,0x1c04($v1)
.L0f1018a0:
/*  f1018a0:	3c16f600 */ 	lui	$s6,0xf600
/*  f1018a4:	50400252 */ 	beqzl	$v0,.L0f1021f0
/*  f1018a8:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f1018ac:	c4400104 */ 	lwc1	$f0,0x104($v0)
/*  f1018b0:	c4520100 */ 	lwc1	$f18,0x100($v0)
/*  f1018b4:	3c013e00 */ 	lui	$at,0x3e00
/*  f1018b8:	44815000 */ 	mtc1	$at,$f10
/*  f1018bc:	46120101 */ 	sub.s	$f4,$f0,$f18
/*  f1018c0:	3c013e80 */ 	lui	$at,0x3e80
/*  f1018c4:	44819000 */ 	mtc1	$at,$f18
/*  f1018c8:	0000f025 */ 	or	$s8,$zero,$zero
/*  f1018cc:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f1018d0:	e7a60100 */ 	swc1	$f6,0x100($sp)
/*  f1018d4:	c4480180 */ 	lwc1	$f8,0x180($v0)
/*  f1018d8:	4612303c */ 	c.lt.s	$f6,$f18
/*  f1018dc:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f1018e0:	45000002 */ 	bc1f	.L0f1018ec
/*  f1018e4:	e7b000fc */ 	swc1	$f16,0xfc($sp)
/*  f1018e8:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f1018ec:
/*  f1018ec:	8d67006c */ 	lw	$a3,0x6c($t3)
/*  f1018f0:	50e00004 */ 	beqzl	$a3,.L0f101904
/*  f1018f4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1018f8:	10000002 */ 	beqz	$zero,.L0f101904
/*  f1018fc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f101900:	00003025 */ 	or	$a2,$zero,$zero
.L0f101904:
/*  f101904:	8d680068 */ 	lw	$t0,0x68($t3)
/*  f101908:	51000004 */ 	beqzl	$t0,.L0f10191c
/*  f10190c:	00002825 */ 	or	$a1,$zero,$zero
/*  f101910:	10000002 */ 	beqz	$zero,.L0f10191c
/*  f101914:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f101918:	00002825 */ 	or	$a1,$zero,$zero
.L0f10191c:
/*  f10191c:	8d690064 */ 	lw	$t1,0x64($t3)
/*  f101920:	51200004 */ 	beqzl	$t1,.L0f101934
/*  f101924:	00002025 */ 	or	$a0,$zero,$zero
/*  f101928:	10000002 */ 	beqz	$zero,.L0f101934
/*  f10192c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f101930:	00002025 */ 	or	$a0,$zero,$zero
.L0f101934:
/*  f101934:	8d6a0070 */ 	lw	$t2,0x70($t3)
/*  f101938:	51400004 */ 	beqzl	$t2,.L0f10194c
/*  f10193c:	00001825 */ 	or	$v1,$zero,$zero
/*  f101940:	10000002 */ 	beqz	$zero,.L0f10194c
/*  f101944:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f101948:	00001825 */ 	or	$v1,$zero,$zero
.L0f10194c:
/*  f10194c:	00647021 */ 	addu	$t6,$v1,$a0
/*  f101950:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f101954:	0326c021 */ 	addu	$t8,$t9,$a2
/*  f101958:	2b010002 */ 	slti	$at,$t8,0x2
/*  f10195c:	54200004 */ 	bnezl	$at,.L0f101970
/*  f101960:	24170040 */ 	addiu	$s7,$zero,0x40
/*  f101964:	10000002 */ 	beqz	$zero,.L0f101970
/*  f101968:	24170030 */ 	addiu	$s7,$zero,0x30
/*  f10196c:	24170040 */ 	addiu	$s7,$zero,0x40
.L0f101970:
/*  f101970:	50e00004 */ 	beqzl	$a3,.L0f101984
/*  f101974:	00003025 */ 	or	$a2,$zero,$zero
/*  f101978:	10000002 */ 	beqz	$zero,.L0f101984
/*  f10197c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f101980:	00003025 */ 	or	$a2,$zero,$zero
.L0f101984:
/*  f101984:	51000004 */ 	beqzl	$t0,.L0f101998
/*  f101988:	00002825 */ 	or	$a1,$zero,$zero
/*  f10198c:	10000002 */ 	beqz	$zero,.L0f101998
/*  f101990:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f101994:	00002825 */ 	or	$a1,$zero,$zero
.L0f101998:
/*  f101998:	51200004 */ 	beqzl	$t1,.L0f1019ac
/*  f10199c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1019a0:	10000002 */ 	beqz	$zero,.L0f1019ac
/*  f1019a4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1019a8:	00002025 */ 	or	$a0,$zero,$zero
.L0f1019ac:
/*  f1019ac:	51400004 */ 	beqzl	$t2,.L0f1019c0
/*  f1019b0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1019b4:	10000002 */ 	beqz	$zero,.L0f1019c0
/*  f1019b8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f1019bc:	00001825 */ 	or	$v1,$zero,$zero
.L0f1019c0:
/*  f1019c0:	00647821 */ 	addu	$t7,$v1,$a0
/*  f1019c4:	01e57021 */ 	addu	$t6,$t7,$a1
/*  f1019c8:	01c6c821 */ 	addu	$t9,$t6,$a2
/*  f1019cc:	2b210002 */ 	slti	$at,$t9,0x2
/*  f1019d0:	54200004 */ 	bnezl	$at,.L0f1019e4
/*  f1019d4:	2415000b */ 	addiu	$s5,$zero,0xb
/*  f1019d8:	10000002 */ 	beqz	$zero,.L0f1019e4
/*  f1019dc:	24150007 */ 	addiu	$s5,$zero,0x7
/*  f1019e0:	2415000b */ 	addiu	$s5,$zero,0xb
.L0f1019e4:
/*  f1019e4:	10e00003 */ 	beqz	$a3,.L0f1019f4
/*  f1019e8:	00009025 */ 	or	$s2,$zero,$zero
/*  f1019ec:	10000002 */ 	beqz	$zero,.L0f1019f8
/*  f1019f0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1019f4:
/*  f1019f4:	00003025 */ 	or	$a2,$zero,$zero
.L0f1019f8:
/*  f1019f8:	11000003 */ 	beqz	$t0,.L0f101a08
/*  f1019fc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f101a00:	10000002 */ 	beqz	$zero,.L0f101a0c
/*  f101a04:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f101a08:
/*  f101a08:	00002825 */ 	or	$a1,$zero,$zero
.L0f101a0c:
/*  f101a0c:	51200004 */ 	beqzl	$t1,.L0f101a20
/*  f101a10:	00002025 */ 	or	$a0,$zero,$zero
/*  f101a14:	10000002 */ 	beqz	$zero,.L0f101a20
/*  f101a18:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f101a1c:	00002025 */ 	or	$a0,$zero,$zero
.L0f101a20:
/*  f101a20:	51400004 */ 	beqzl	$t2,.L0f101a34
/*  f101a24:	00001825 */ 	or	$v1,$zero,$zero
/*  f101a28:	10000002 */ 	beqz	$zero,.L0f101a34
/*  f101a2c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f101a30:	00001825 */ 	or	$v1,$zero,$zero
.L0f101a34:
/*  f101a34:	0064c021 */ 	addu	$t8,$v1,$a0
/*  f101a38:	03057821 */ 	addu	$t7,$t8,$a1
/*  f101a3c:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f101a40:	15c10011 */ 	bne	$t6,$at,.L0f101a88
/*  f101a44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101a48:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f101a4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101a50:	24010001 */ 	addiu	$at,$zero,0x1
/*  f101a54:	10410021 */ 	beq	$v0,$at,.L0f101adc
/*  f101a58:	3c198009 */ 	lui	$t9,0x8009
/*  f101a5c:	93390af0 */ 	lbu	$t9,0xaf0($t9)
/*  f101a60:	24010001 */ 	addiu	$at,$zero,0x1
/*  f101a64:	3c07800a */ 	lui	$a3,0x800a
/*  f101a68:	1321001c */ 	beq	$t9,$at,.L0f101adc
/*  f101a6c:	3c08800a */ 	lui	$t0,0x800a
/*  f101a70:	3c09800a */ 	lui	$t1,0x800a
/*  f101a74:	3c0a800a */ 	lui	$t2,0x800a
/*  f101a78:	8d4aa030 */ 	lw	$t2,-0x5fd0($t2)
/*  f101a7c:	8d29a024 */ 	lw	$t1,-0x5fdc($t1)
/*  f101a80:	8ce7a02c */ 	lw	$a3,-0x5fd4($a3)
/*  f101a84:	8d08a028 */ 	lw	$t0,-0x5fd8($t0)
.L0f101a88:
/*  f101a88:	10e00003 */ 	beqz	$a3,.L0f101a98
/*  f101a8c:	00002825 */ 	or	$a1,$zero,$zero
/*  f101a90:	10000001 */ 	beqz	$zero,.L0f101a98
/*  f101a94:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f101a98:
/*  f101a98:	11000003 */ 	beqz	$t0,.L0f101aa8
/*  f101a9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f101aa0:	10000001 */ 	beqz	$zero,.L0f101aa8
/*  f101aa4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f101aa8:
/*  f101aa8:	11200003 */ 	beqz	$t1,.L0f101ab8
/*  f101aac:	00002025 */ 	or	$a0,$zero,$zero
/*  f101ab0:	10000001 */ 	beqz	$zero,.L0f101ab8
/*  f101ab4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f101ab8:
/*  f101ab8:	11400003 */ 	beqz	$t2,.L0f101ac8
/*  f101abc:	00001825 */ 	or	$v1,$zero,$zero
/*  f101ac0:	10000001 */ 	beqz	$zero,.L0f101ac8
/*  f101ac4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f101ac8:
/*  f101ac8:	0064c021 */ 	addu	$t8,$v1,$a0
/*  f101acc:	03027821 */ 	addu	$t7,$t8,$v0
/*  f101ad0:	01e57021 */ 	addu	$t6,$t7,$a1
/*  f101ad4:	29c10003 */ 	slti	$at,$t6,0x3
/*  f101ad8:	1420000c */ 	bnez	$at,.L0f101b0c
.L0f101adc:
/*  f101adc:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f101ae0:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f101ae4:	8d79028c */ 	lw	$t9,0x28c($t3)
/*  f101ae8:	8d67006c */ 	lw	$a3,0x6c($t3)
/*  f101aec:	8d680068 */ 	lw	$t0,0x68($t3)
/*  f101af0:	33380001 */ 	andi	$t8,$t9,0x1
/*  f101af4:	8d690064 */ 	lw	$t1,0x64($t3)
/*  f101af8:	17000003 */ 	bnez	$t8,.L0f101b08
/*  f101afc:	8d6a0070 */ 	lw	$t2,0x70($t3)
/*  f101b00:	10000002 */ 	beqz	$zero,.L0f101b0c
/*  f101b04:	24120008 */ 	addiu	$s2,$zero,0x8
.L0f101b08:
/*  f101b08:	2412fff8 */ 	addiu	$s2,$zero,-8
.L0f101b0c:
/*  f101b0c:	10e00003 */ 	beqz	$a3,.L0f101b1c
/*  f101b10:	24010001 */ 	addiu	$at,$zero,0x1
/*  f101b14:	10000002 */ 	beqz	$zero,.L0f101b20
/*  f101b18:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f101b1c:
/*  f101b1c:	00003025 */ 	or	$a2,$zero,$zero
.L0f101b20:
/*  f101b20:	51000004 */ 	beqzl	$t0,.L0f101b34
/*  f101b24:	00002825 */ 	or	$a1,$zero,$zero
/*  f101b28:	10000002 */ 	beqz	$zero,.L0f101b34
/*  f101b2c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f101b30:	00002825 */ 	or	$a1,$zero,$zero
.L0f101b34:
/*  f101b34:	51200004 */ 	beqzl	$t1,.L0f101b48
/*  f101b38:	00002025 */ 	or	$a0,$zero,$zero
/*  f101b3c:	10000002 */ 	beqz	$zero,.L0f101b48
/*  f101b40:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f101b44:	00002025 */ 	or	$a0,$zero,$zero
.L0f101b48:
/*  f101b48:	51400004 */ 	beqzl	$t2,.L0f101b5c
/*  f101b4c:	00001825 */ 	or	$v1,$zero,$zero
/*  f101b50:	10000002 */ 	beqz	$zero,.L0f101b5c
/*  f101b54:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f101b58:	00001825 */ 	or	$v1,$zero,$zero
.L0f101b5c:
/*  f101b5c:	00647821 */ 	addu	$t7,$v1,$a0
/*  f101b60:	01e57021 */ 	addu	$t6,$t7,$a1
/*  f101b64:	01c6c821 */ 	addu	$t9,$t6,$a2
/*  f101b68:	17210019 */ 	bne	$t9,$at,.L0f101bd0
/*  f101b6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101b70:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f101b74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101b78:	10400015 */ 	beqz	$v0,.L0f101bd0
/*  f101b7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101b80:	0c002f40 */ 	jal	func0000bd00
/*  f101b84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101b88:	3c188008 */ 	lui	$t8,0x8008
/*  f101b8c:	8f18fac0 */ 	lw	$t8,-0x540($t8)
/*  f101b90:	44972000 */ 	mtc1	$s7,$f4
/*  f101b94:	0058001a */ 	div	$zero,$v0,$t8
/*  f101b98:	00008012 */ 	mflo	$s0
/*  f101b9c:	26100020 */ 	addiu	$s0,$s0,0x20
/*  f101ba0:	17000002 */ 	bnez	$t8,.L0f101bac
/*  f101ba4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101ba8:	0007000d */ 	break	0x7
.L0f101bac:
/*  f101bac:	2401ffff */ 	addiu	$at,$zero,-1
/*  f101bb0:	17010004 */ 	bne	$t8,$at,.L0f101bc4
/*  f101bb4:	3c018000 */ 	lui	$at,0x8000
/*  f101bb8:	14410002 */ 	bne	$v0,$at,.L0f101bc4
/*  f101bbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101bc0:	0006000d */ 	break	0x6
.L0f101bc4:
/*  f101bc4:	468020a0 */ 	cvt.s.w	$f2,$f4
/*  f101bc8:	10000031 */ 	beqz	$zero,.L0f101c90
/*  f101bcc:	3c013e80 */ 	lui	$at,0x3e80
.L0f101bd0:
/*  f101bd0:	0c002f22 */ 	jal	func0000bc88
/*  f101bd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101bd8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f101bdc:	00117c03 */ 	sra	$t7,$s1,0x10
/*  f101be0:	0c002f40 */ 	jal	func0000bd00
/*  f101be4:	01e08825 */ 	or	$s1,$t7,$zero
/*  f101be8:	3c038008 */ 	lui	$v1,0x8008
/*  f101bec:	8c63fac0 */ 	lw	$v1,-0x540($v1)
/*  f101bf0:	44974000 */ 	mtc1	$s7,$f8
/*  f101bf4:	3c013f00 */ 	lui	$at,0x3f00
/*  f101bf8:	0043001a */ 	div	$zero,$v0,$v1
/*  f101bfc:	00007012 */ 	mflo	$t6
/*  f101c00:	44810000 */ 	mtc1	$at,$f0
/*  f101c04:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f101c08:	0223001a */ 	div	$zero,$s1,$v1
/*  f101c0c:	0000c812 */ 	mflo	$t9
/*  f101c10:	44995000 */ 	mtc1	$t9,$f10
/*  f101c14:	14600002 */ 	bnez	$v1,.L0f101c20
/*  f101c18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101c1c:	0007000d */ 	break	0x7
.L0f101c20:
/*  f101c20:	2401ffff */ 	addiu	$at,$zero,-1
/*  f101c24:	14610004 */ 	bne	$v1,$at,.L0f101c38
/*  f101c28:	3c018000 */ 	lui	$at,0x8000
/*  f101c2c:	14410002 */ 	bne	$v0,$at,.L0f101c38
/*  f101c30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101c34:	0006000d */ 	break	0x6
.L0f101c38:
/*  f101c38:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f101c3c:	14600002 */ 	bnez	$v1,.L0f101c48
/*  f101c40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101c44:	0007000d */ 	break	0x7
.L0f101c48:
/*  f101c48:	2401ffff */ 	addiu	$at,$zero,-1
/*  f101c4c:	14610004 */ 	bne	$v1,$at,.L0f101c60
/*  f101c50:	3c018000 */ 	lui	$at,0x8000
/*  f101c54:	16210002 */ 	bne	$s1,$at,.L0f101c60
/*  f101c58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101c5c:	0006000d */ 	break	0x6
.L0f101c60:
/*  f101c60:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f101c64:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f101c68:	46001102 */ 	mul.s	$f4,$f2,$f0
/*  f101c6c:	440f9000 */ 	mfc1	$t7,$f18
/*  f101c70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101c74:	01cfc821 */ 	addu	$t9,$t6,$t7
/*  f101c78:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f101c7c:	440e4000 */ 	mfc1	$t6,$f8
/*  f101c80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101c84:	032e7823 */ 	subu	$t7,$t9,$t6
/*  f101c88:	01f28021 */ 	addu	$s0,$t7,$s2
/*  f101c8c:	3c013e80 */ 	lui	$at,0x3e80
.L0f101c90:
/*  f101c90:	44815000 */ 	mtc1	$at,$f10
/*  f101c94:	44800000 */ 	mtc1	$zero,$f0
/*  f101c98:	c7b20100 */ 	lwc1	$f18,0x100($sp)
/*  f101c9c:	460a1402 */ 	mul.s	$f16,$f2,$f10
/*  f101ca0:	4600903c */ 	c.lt.s	$f18,$f0
/*  f101ca4:	4600818d */ 	trunc.w.s	$f6,$f16
/*  f101ca8:	44123000 */ 	mfc1	$s2,$f6
/*  f101cac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101cb0:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f101cb4:	02128821 */ 	addu	$s1,$s0,$s2
/*  f101cb8:	45000002 */ 	bc1f	.L0f101cc4
/*  f101cbc:	26330002 */ 	addiu	$s3,$s1,0x2
/*  f101cc0:	e7a00100 */ 	swc1	$f0,0x100($sp)
.L0f101cc4:
/*  f101cc4:	8fb901d8 */ 	lw	$t9,0x1d8($sp)
/*  f101cc8:	3c0fe700 */ 	lui	$t7,0xe700
/*  f101ccc:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f101cd0:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f101cd4:	af200004 */ 	sw	$zero,0x4($t9)
/*  f101cd8:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f101cdc:	8fb801d8 */ 	lw	$t8,0x1d8($sp)
/*  f101ce0:	3c0eba00 */ 	lui	$t6,0xba00
/*  f101ce4:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f101ce8:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f101cec:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f101cf0:	af000004 */ 	sw	$zero,0x4($t8)
/*  f101cf4:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f101cf8:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f101cfc:	3c0e0050 */ 	lui	$t6,0x50
/*  f101d00:	3c19b900 */ 	lui	$t9,0xb900
/*  f101d04:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f101d08:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f101d0c:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f101d10:	35ce4240 */ 	ori	$t6,$t6,0x4240
/*  f101d14:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f101d18:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f101d1c:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f101d20:	3c19fcff */ 	lui	$t9,0xfcff
/*  f101d24:	3c0efffd */ 	lui	$t6,0xfffd
/*  f101d28:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f101d2c:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f101d30:	35cef6fb */ 	ori	$t6,$t6,0xf6fb
/*  f101d34:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f101d38:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f101d3c:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f101d40:	0c002f26 */ 	jal	func0000bc98
/*  f101d44:	e7a20068 */ 	swc1	$f2,0x68($sp)
/*  f101d48:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f101d4c:	00147c03 */ 	sra	$t7,$s4,0x10
/*  f101d50:	0c002f44 */ 	jal	func0000bd10
/*  f101d54:	01e0a025 */ 	or	$s4,$t7,$zero
/*  f101d58:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f101d5c:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f101d60:	8c98006c */ 	lw	$t8,0x6c($a0)
/*  f101d64:	c7a20068 */ 	lwc1	$f2,0x68($sp)
/*  f101d68:	00001825 */ 	or	$v1,$zero,$zero
/*  f101d6c:	13000003 */ 	beqz	$t8,.L0f101d7c
/*  f101d70:	00003025 */ 	or	$a2,$zero,$zero
/*  f101d74:	10000001 */ 	beqz	$zero,.L0f101d7c
/*  f101d78:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f101d7c:
/*  f101d7c:	8c990068 */ 	lw	$t9,0x68($a0)
/*  f101d80:	00002825 */ 	or	$a1,$zero,$zero
/*  f101d84:	13200003 */ 	beqz	$t9,.L0f101d94
/*  f101d88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101d8c:	10000001 */ 	beqz	$zero,.L0f101d94
/*  f101d90:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f101d94:
/*  f101d94:	8c8e0064 */ 	lw	$t6,0x64($a0)
/*  f101d98:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f101d9c:	11c00003 */ 	beqz	$t6,.L0f101dac
/*  f101da0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101da4:	10000001 */ 	beqz	$zero,.L0f101dac
/*  f101da8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f101dac:
/*  f101dac:	8c8f0070 */ 	lw	$t7,0x70($a0)
/*  f101db0:	00002025 */ 	or	$a0,$zero,$zero
/*  f101db4:	c7a80100 */ 	lwc1	$f8,0x100($sp)
/*  f101db8:	11e00003 */ 	beqz	$t7,.L0f101dc8
/*  f101dbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f101dc0:	10000001 */ 	beqz	$zero,.L0f101dc8
/*  f101dc4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f101dc8:
/*  f101dc8:	0085c021 */ 	addu	$t8,$a0,$a1
/*  f101dcc:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f101dd0:	03237021 */ 	addu	$t6,$t9,$v1
/*  f101dd4:	29c10002 */ 	slti	$at,$t6,0x2
/*  f101dd8:	14200003 */ 	bnez	$at,.L0f101de8
/*  f101ddc:	00027c00 */ 	sll	$t7,$v0,0x10
/*  f101de0:	10000002 */ 	beqz	$zero,.L0f101dec
/*  f101de4:	24030013 */ 	addiu	$v1,$zero,0x13
.L0f101de8:
/*  f101de8:	24030022 */ 	addiu	$v1,$zero,0x22
.L0f101dec:
/*  f101dec:	000fc403 */ 	sra	$t8,$t7,0x10
/*  f101df0:	0314c821 */ 	addu	$t9,$t8,$s4
/*  f101df4:	13c0005e */ 	beqz	$s8,.L0f101f70
/*  f101df8:	03233823 */ 	subu	$a3,$t9,$v1
/*  f101dfc:	44928000 */ 	mtc1	$s2,$f16
/*  f101e00:	3c013e80 */ 	lui	$at,0x3e80
/*  f101e04:	44812000 */ 	mtc1	$at,$f4
/*  f101e08:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f101e0c:	8fb801d8 */ 	lw	$t8,0x1d8($sp)
/*  f101e10:	3c014080 */ 	lui	$at,0x4080
/*  f101e14:	3c0eff00 */ 	lui	$t6,0xff00
/*  f101e18:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f101e1c:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f101e20:	44812000 */ 	mtc1	$at,$f4
/*  f101e24:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f101e28:	3c0b8008 */ 	lui	$t3,%hi(var8007fac0)
/*  f101e2c:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f101e30:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f101e34:	35ce0060 */ 	ori	$t6,$t6,0x60
/*  f101e38:	256bfac0 */ 	addiu	$t3,$t3,%lo(var8007fac0)
/*  f101e3c:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f101e40:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f101e44:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f101e48:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f101e4c:	8fa501d8 */ 	lw	$a1,0x1d8($sp)
/*  f101e50:	022e0019 */ 	multu	$s1,$t6
/*  f101e54:	00f54821 */ 	addu	$t1,$a3,$s5
/*  f101e58:	312303ff */ 	andi	$v1,$t1,0x3ff
/*  f101e5c:	24b80008 */ 	addiu	$t8,$a1,0x8
/*  f101e60:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f101e64:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f101e68:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f101e6c:	03201825 */ 	or	$v1,$t9,$zero
/*  f101e70:	30e203ff */ 	andi	$v0,$a3,0x3ff
/*  f101e74:	440f8000 */ 	mfc1	$t7,$f16
/*  f101e78:	3c078008 */ 	lui	$a3,%hi(var8007fac0)
/*  f101e7c:	240d0080 */ 	addiu	$t5,$zero,0x80
/*  f101e80:	022f3023 */ 	subu	$a2,$s1,$t7
/*  f101e84:	00007812 */ 	mflo	$t7
/*  f101e88:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f101e8c:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f101e90:	03367025 */ 	or	$t6,$t9,$s6
/*  f101e94:	01c37825 */ 	or	$t7,$t6,$v1
/*  f101e98:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f101e9c:	8d790000 */ 	lw	$t9,0x0($t3)
/*  f101ea0:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f101ea4:	03001025 */ 	or	$v0,$t8,$zero
/*  f101ea8:	00d90019 */ 	multu	$a2,$t9
/*  f101eac:	24e7fac0 */ 	addiu	$a3,$a3,%lo(var8007fac0)
/*  f101eb0:	00007012 */ 	mflo	$t6
/*  f101eb4:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f101eb8:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f101ebc:	0302c825 */ 	or	$t9,$t8,$v0
/*  f101ec0:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f101ec4:	8fae01d8 */ 	lw	$t6,0x1d8($sp)
/*  f101ec8:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f101ecc:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f101ed0:	adcd0004 */ 	sw	$t5,0x4($t6)
/*  f101ed4:	adcc0000 */ 	sw	$t4,0x0($t6)
/*  f101ed8:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f101edc:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f101ee0:	00ce0019 */ 	multu	$a2,$t6
/*  f101ee4:	24990008 */ 	addiu	$t9,$a0,0x8
/*  f101ee8:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f101eec:	02173021 */ 	addu	$a2,$s0,$s7
/*  f101ef0:	00007812 */ 	mflo	$t7
/*  f101ef4:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f101ef8:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f101efc:	03367025 */ 	or	$t6,$t9,$s6
/*  f101f00:	01c37825 */ 	or	$t7,$t6,$v1
/*  f101f04:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f101f08:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f101f0c:	02180019 */ 	multu	$s0,$t8
/*  f101f10:	0000c812 */ 	mflo	$t9
/*  f101f14:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f101f18:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f101f1c:	01e2c025 */ 	or	$t8,$t7,$v0
/*  f101f20:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f101f24:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f101f28:	8fa501d8 */ 	lw	$a1,0x1d8($sp)
/*  f101f2c:	00cf0019 */ 	multu	$a2,$t7
/*  f101f30:	24ae0008 */ 	addiu	$t6,$a1,0x8
/*  f101f34:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f101f38:	0000c012 */ 	mflo	$t8
/*  f101f3c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f101f40:	00197380 */ 	sll	$t6,$t9,0xe
/*  f101f44:	01d67825 */ 	or	$t7,$t6,$s6
/*  f101f48:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f101f4c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f101f50:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f101f54:	02790019 */ 	multu	$s3,$t9
/*  f101f58:	00007012 */ 	mflo	$t6
/*  f101f5c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f101f60:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f101f64:	0302c825 */ 	or	$t9,$t8,$v0
/*  f101f68:	10000059 */ 	beqz	$zero,.L0f1020d0
/*  f101f6c:	acb90004 */ 	sw	$t9,0x4($a1)
.L0f101f70:
/*  f101f70:	8fae01d8 */ 	lw	$t6,0x1d8($sp)
/*  f101f74:	3c1800c0 */ 	lui	$t8,0xc0
/*  f101f78:	37180060 */ 	ori	$t8,$t8,0x60
/*  f101f7c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f101f80:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f101f84:	add80004 */ 	sw	$t8,0x4($t6)
/*  f101f88:	3c188008 */ 	lui	$t8,0x8008
/*  f101f8c:	adcc0000 */ 	sw	$t4,0x0($t6)
/*  f101f90:	8f18fac0 */ 	lw	$t8,-0x540($t8)
/*  f101f94:	8fa501d8 */ 	lw	$a1,0x1d8($sp)
/*  f101f98:	00f54821 */ 	addu	$t1,$a3,$s5
/*  f101f9c:	02380019 */ 	multu	$s1,$t8
/*  f101fa0:	312303ff */ 	andi	$v1,$t1,0x3ff
/*  f101fa4:	24ae0008 */ 	addiu	$t6,$a1,0x8
/*  f101fa8:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f101fac:	00037880 */ 	sll	$t7,$v1,0x2
/*  f101fb0:	01e01825 */ 	or	$v1,$t7,$zero
/*  f101fb4:	30e203ff */ 	andi	$v0,$a3,0x3ff
/*  f101fb8:	240d0080 */ 	addiu	$t5,$zero,0x80
/*  f101fbc:	0000c812 */ 	mflo	$t9
/*  f101fc0:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f101fc4:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f101fc8:	01f6c025 */ 	or	$t8,$t7,$s6
/*  f101fcc:	0303c825 */ 	or	$t9,$t8,$v1
/*  f101fd0:	3c0f8008 */ 	lui	$t7,0x8008
/*  f101fd4:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f101fd8:	8deffac0 */ 	lw	$t7,-0x540($t7)
/*  f101fdc:	00027080 */ 	sll	$t6,$v0,0x2
/*  f101fe0:	01c01025 */ 	or	$v0,$t6,$zero
/*  f101fe4:	020f0019 */ 	multu	$s0,$t7
/*  f101fe8:	0000c012 */ 	mflo	$t8
/*  f101fec:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f101ff0:	00197380 */ 	sll	$t6,$t9,0xe
/*  f101ff4:	01c27825 */ 	or	$t7,$t6,$v0
/*  f101ff8:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f101ffc:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f102000:	3c188008 */ 	lui	$t8,0x8008
/*  f102004:	8f18fac0 */ 	lw	$t8,-0x540($t8)
/*  f102008:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f10200c:	8faa01d8 */ 	lw	$t2,0x1d8($sp)
/*  f102010:	254f0008 */ 	addiu	$t7,$t2,0x8
/*  f102014:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f102018:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f10201c:	44199000 */ 	mfc1	$t9,$f18
/*  f102020:	00000000 */ 	sll	$zero,$zero,0x0
/*  f102024:	03303021 */ 	addu	$a2,$t9,$s0
/*  f102028:	00d80019 */ 	multu	$a2,$t8
/*  f10202c:	00c04025 */ 	or	$t0,$a2,$zero
/*  f102030:	02173021 */ 	addu	$a2,$s0,$s7
/*  f102034:	0000c812 */ 	mflo	$t9
/*  f102038:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f10203c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f102040:	01f6c025 */ 	or	$t8,$t7,$s6
/*  f102044:	0303c825 */ 	or	$t9,$t8,$v1
/*  f102048:	3c0e8008 */ 	lui	$t6,0x8008
/*  f10204c:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f102050:	8dcefac0 */ 	lw	$t6,-0x540($t6)
/*  f102054:	026e0019 */ 	multu	$s3,$t6
/*  f102058:	00007812 */ 	mflo	$t7
/*  f10205c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f102060:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f102064:	03227025 */ 	or	$t6,$t9,$v0
/*  f102068:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*  f10206c:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f102070:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f102074:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f102078:	aded0004 */ 	sw	$t5,0x4($t7)
/*  f10207c:	adec0000 */ 	sw	$t4,0x0($t7)
/*  f102080:	3c0f8008 */ 	lui	$t7,0x8008
/*  f102084:	8deffac0 */ 	lw	$t7,-0x540($t7)
/*  f102088:	8fa501d8 */ 	lw	$a1,0x1d8($sp)
/*  f10208c:	00cf0019 */ 	multu	$a2,$t7
/*  f102090:	24ae0008 */ 	addiu	$t6,$a1,0x8
/*  f102094:	afae01d8 */ 	sw	$t6,0x1d8($sp)
/*  f102098:	0000c012 */ 	mflo	$t8
/*  f10209c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1020a0:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1020a4:	01d67825 */ 	or	$t7,$t6,$s6
/*  f1020a8:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f1020ac:	3c198008 */ 	lui	$t9,0x8008
/*  f1020b0:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1020b4:	8f39fac0 */ 	lw	$t9,-0x540($t9)
/*  f1020b8:	01190019 */ 	multu	$t0,$t9
/*  f1020bc:	00007012 */ 	mflo	$t6
/*  f1020c0:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1020c4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f1020c8:	0302c825 */ 	or	$t9,$t8,$v0
/*  f1020cc:	acb90004 */ 	sw	$t9,0x4($a1)
.L0f1020d0:
/*  f1020d0:	44952000 */ 	mtc1	$s5,$f4
/*  f1020d4:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f1020d8:	3c013f40 */ 	lui	$at,0x3f40
/*  f1020dc:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f1020e0:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f1020e4:	44818000 */ 	mtc1	$at,$f16
/*  f1020e8:	afb801d8 */ 	sw	$t8,0x1d8($sp)
/*  f1020ec:	3c1900c0 */ 	lui	$t9,0xc0
/*  f1020f0:	37390060 */ 	ori	$t9,$t9,0x60
/*  f1020f4:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f1020f8:	adec0000 */ 	sw	$t4,0x0($t7)
/*  f1020fc:	46104182 */ 	mul.s	$f6,$f8,$f16
/*  f102100:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f102104:	3c1f8008 */ 	lui	$ra,0x8008
/*  f102108:	27fffac0 */ 	addiu	$ra,$ra,-1344
/*  f10210c:	46121102 */ 	mul.s	$f4,$f2,$f18
/*  f102110:	8ff80000 */ 	lw	$t8,0x0($ra)
/*  f102114:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f102118:	25250002 */ 	addiu	$a1,$t1,0x2
/*  f10211c:	30aa03ff */ 	andi	$t2,$a1,0x3ff
/*  f102120:	24990008 */ 	addiu	$t9,$a0,0x8
/*  f102124:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f102128:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f10212c:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f102130:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f102134:	44155000 */ 	mfc1	$s5,$f10
/*  f102138:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f10213c:	440f4000 */ 	mfc1	$t7,$f8
/*  f102140:	00b53821 */ 	addu	$a3,$a1,$s5
/*  f102144:	30ee03ff */ 	andi	$t6,$a3,0x3ff
/*  f102148:	01f04021 */ 	addu	$t0,$t7,$s0
/*  f10214c:	01180019 */ 	multu	$t0,$t8
/*  f102150:	000e3880 */ 	sll	$a3,$t6,0x2
/*  f102154:	0000c812 */ 	mflo	$t9
/*  f102158:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f10215c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f102160:	01f6c025 */ 	or	$t8,$t7,$s6
/*  f102164:	0307c825 */ 	or	$t9,$t8,$a3
/*  f102168:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f10216c:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f102170:	000a7080 */ 	sll	$t6,$t2,0x2
/*  f102174:	01c05025 */ 	or	$t2,$t6,$zero
/*  f102178:	020f0019 */ 	multu	$s0,$t7
/*  f10217c:	0000c012 */ 	mflo	$t8
/*  f102180:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f102184:	00197380 */ 	sll	$t6,$t9,0xe
/*  f102188:	01ca7825 */ 	or	$t7,$t6,$t2
/*  f10218c:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f102190:	8fb801d8 */ 	lw	$t8,0x1d8($sp)
/*  f102194:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f102198:	afb901d8 */ 	sw	$t9,0x1d8($sp)
/*  f10219c:	af0d0004 */ 	sw	$t5,0x4($t8)
/*  f1021a0:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f1021a4:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f1021a8:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
/*  f1021ac:	00d80019 */ 	multu	$a2,$t8
/*  f1021b0:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f1021b4:	afaf01d8 */ 	sw	$t7,0x1d8($sp)
/*  f1021b8:	0000c812 */ 	mflo	$t9
/*  f1021bc:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1021c0:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1021c4:	01f6c025 */ 	or	$t8,$t7,$s6
/*  f1021c8:	0307c825 */ 	or	$t9,$t8,$a3
/*  f1021cc:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1021d0:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f1021d4:	010e0019 */ 	multu	$t0,$t6
/*  f1021d8:	00007812 */ 	mflo	$t7
/*  f1021dc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1021e0:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f1021e4:	032a7025 */ 	or	$t6,$t9,$t2
/*  f1021e8:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f1021ec:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f1021f0:
/*  f1021f0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1021f4:	3c018008 */ 	lui	$at,0x8008
/*  f1021f8:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
/*  f1021fc:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f102200:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f102204:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f102208:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f10220c:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f102210:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f102214:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f102218:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f10221c:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f102220:	ac2ffac0 */ 	sw	$t7,-0x540($at)
/*  f102224:	03e00008 */ 	jr	$ra
/*  f102228:	27bd01d8 */ 	addiu	$sp,$sp,0x1d8
/*  f10222c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f102230
/*  f102230:	03e00008 */ 	jr	$ra
/*  f102234:	00000000 */ 	sll	$zero,$zero,0x0
/*  f102238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10223c:	00000000 */ 	sll	$zero,$zero,0x0
);
