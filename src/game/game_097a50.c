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
#include "game/game_0601b0.h"
#include "game/game_066310.h"
#include "game/game_096750.h"
#include "game/game_097a50.h"
#include "game/game_0abe70.h"
#include "game/game_0b0420.h"
#include "game/game_0b28d0.h"
#include "game/game_0c79f0.h"
#include "game/game_0d4690.h"
#include "game/cheats.h"
#include "game/game_111600.h"
#include "game/pad.h"
#include "game/game_11ecf0.h"
#include "game/game_129900.h"
#include "game/pdoptions.h"
#include "game/game_152fa0.h"
#include "game/game_1668e0.h"
#include "game/game_16cfa0.h"
#include "game/game_176080.h"
#include "game/game_187770.h"
#include "game/game_19c990.h"
#include "game/game_1a3340.h"
#include "library/library_12dc0.h"

const char var7f1ab890[] = "rontime";
const char var7f1ab898[] = "rofftime";
const char var7f1ab8a4[] = "gkef";
const char var7f1ab8ac[] = "changegunmem type %d CurrentPlayer->gunctrl.gunmemtype %d\n";
const char var7f1ab8e8[] = "LockTimer: %d\n";
const char var7f1ab8f8[] = "BriGun: Releasing gunmem - current gunmemtype %d gunmemnew %d\n";
const char var7f1ab938[] = "GiveMem: %d\n";
const char var7f1ab948[] = "BriGun:  BriGunLoadTick process GUN_LOADSTATE_LOAD_OBJ\n";
const char var7f1ab980[] = "BriGun:  Loading - %s, pMem 0x%08x Size %d\n";
const char var7f1ab9ac[] = "BriGun:  Warning: LoadSize > MemSize, clamping decomp. buffer from %d to %d (%d Bytes)\n";
const char var7f1aba04[] = "BriGun:  obLoadto at 0x%08x, size %d\n";
const char var7f1aba2c[] = "BriGun:  Used size %d (Ob Size %d)\n";
const char var7f1aba50[] = "BriGun:  block len %d usedsize %d\n";
const char var7f1aba74[] = "BriGun:  obln ram_len %d block_len %d\n";
const char var7f1aba9c[] = "BriGun:  new used size %d\n";
const char var7f1abab8[] = "BriGun:  Texture Block at 0x%08x size %d, endp 0x%08x\n";
const char var7f1abaf0[] = "BriGun:  Set Load State: GUN_LOADSTATE_DECOMPRESS_TEXTURES\n";
const char var7f1abb2c[] = "BriGun:  BriGunLoadTick process GUN_LOADSTATE_DECOMPRESS_TEXTURES\n";
const char var7f1abb70[] = "BriGun:  at texture %d\n";
const char var7f1abb88[] = "BriGun:  Uncompress %d of %d\n";
const char var7f1abba8[] = "BriGun:  Set Load State: GUN_LOADSTATE_DECOMPRESS_DLS\n";
const char var7f1abbe0[] = "BriGun:  BriGunLoadTick process GUN_LOADSTATE_DECOMPRESS_DLS\n";
const char var7f1abc20[] = "BriGun:  propgfx_decompress 0x%08x\n";
const char var7f1abc44[] = "BriGun:  DL waste space %d from %d (Used %d, Ramlen %d, ObSize %d)\n";
const char var7f1abc88[] = "Increase GUNSAVESIZE to %d!!!\n";
const char var7f1abca8[] = "BriGun:  Set Load State: GUN_LOADSTATE_LOADED\n";
const char var7f1abcd8[] = "need a new gun loading (lock %d gunmemnew %d)\n";
const char var7f1abd08[] = "loading gun file: %d type: %d\n";
const char var7f1abd28[] = "BriGun: Process MASTER_GUN_LOADSTATE_FLUX\n";
const char var7f1abd54[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_HANDS\n";
const char var7f1abd8c[] = "BriGun: Process MASTER_GUN_LOADSTATE_HANDS\n";
const char var7f1abdb8[] = "BriGun: Setup Hand Load\n";
const char var7f1abdd4[] = "Hand  : Using cached hands\n";
const char var7f1abdf0[] = "Hand  : Look ma no hands!\n";
const char var7f1abe0c[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_GUN\n";
const char var7f1abe40[] = "BriGun: Process MASTER_GUN_LOADSTATE_GUN\n";
const char var7f1abe6c[] = "BriGun: Setup Gun Load\n";
const char var7f1abe84[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_CARTS\n";
const char var7f1abebc[] = "BriGun: Process MASTER_GUN_LOADSTATE_CARTS\n";
const char var7f1abee8[] = "BriGun: Cart Loaded setting GUN_LOADSTATE_FLUX\n";
const char var7f1abf18[] = "BriGun: Cart loading - looking for carts\n";
const char var7f1abf44[] = "BriGun: Loading cart %d\n";
const char var7f1abf60[] = "BriGun: Request for cart %d ignored - cart already loaded\n";
const char var7f1abf9c[] = "BriGun: Compile Hand 0x%08x Gun 0x%0x8\n";
const char var7f1abfc4[] = "Gun   : Compiled Gun 0x%08x\n";
const char var7f1abfe4[] = "Gun   : Compiled Size %d\n";
const char var7f1ac000[] = "Hand  : Compiled Hand 0x%08x\n";
const char var7f1ac020[] = "Hand  : Compiled Size %d\n";
const char var7f1ac03c[] = "Gun   : Compile overhead %d bytes\n";
const char var7f1ac060[] = "Hand  : Hand Obj 0x%08x Gun Obj 0x%08x \n";
const char var7f1ac08c[] = "Gun   : After Comp : Base 0x%08x Free %d\n";
const char var7f1ac0b8[] = "Gun   : After Cached Setup : Base 0x%08x Free %d\n";
const char var7f1ac0ec[] = "Gun   : TotalUsed %d, Free %d\n";
const char var7f1ac10c[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_LOADED\n";
const char var7f1ac144[] = "GunLockTimer: %d\n";
const char var7f1ac158[] = "** error\n";
const char var7f1ac164[] = "** error\n";
const char var7f1ac170[] = "wantedfn %d tiggle %d\n";
const char var7f1ac188[] = "%d\n";
const char var7f1ac18c[] = "%02d:%02d:%02d\n";
const char var7f1ac19c[] = "%02d:%02d\n";

const u32 var7f1ac1a8[] = {0x461c4000};
const u32 var7f1ac1ac[] = {0x3f451eb8};
const u32 var7f1ac1b0[] = {0x3f333333};
const u32 var7f1ac1b4[] = {0x3f5f5dd8};
const u32 var7f1ac1b8[] = {0x3f5f5dd8};
const u32 var7f1ac1bc[] = {0x7f09a1b8};
const u32 var7f1ac1c0[] = {0x7f09a1b8};
const u32 var7f1ac1c4[] = {0x7f09a17c};
const u32 var7f1ac1c8[] = {0x7f09a17c};
const u32 var7f1ac1cc[] = {0x7f09a17c};
const u32 var7f1ac1d0[] = {0x7f09a17c};
const u32 var7f1ac1d4[] = {0x7f09a17c};
const u32 var7f1ac1d8[] = {0x7f09a17c};
const u32 var7f1ac1dc[] = {0x7f09a17c};
const u32 var7f1ac1e0[] = {0x7f09a17c};
const u32 var7f1ac1e4[] = {0x7f09a17c};
const u32 var7f1ac1e8[] = {0x7f09a17c};
const u32 var7f1ac1ec[] = {0x7f09a17c};
const u32 var7f1ac1f0[] = {0x7f09a17c};
const u32 var7f1ac1f4[] = {0x7f09a17c};
const u32 var7f1ac1f8[] = {0x7f09a17c};
const u32 var7f1ac1fc[] = {0x7f09a17c};
const u32 var7f1ac200[] = {0x7f09a17c};
const u32 var7f1ac204[] = {0x7f09a17c};
const u32 var7f1ac208[] = {0x7f09a17c};
const u32 var7f1ac20c[] = {0x7f09a17c};
const u32 var7f1ac210[] = {0x7f09a17c};
const u32 var7f1ac214[] = {0x7f09a17c};
const u32 var7f1ac218[] = {0x7f09a17c};
const u32 var7f1ac21c[] = {0x7f09a17c};
const u32 var7f1ac220[] = {0x7f09a17c};
const u32 var7f1ac224[] = {0x7f09a1b8};
const u32 var7f1ac228[] = {0x7f09a17c};
const u32 var7f1ac22c[] = {0x7f09a17c};
const u32 var7f1ac230[] = {0x7f09a1b8};
const u32 var7f1ac234[] = {0x7f09a1b8};
const u32 var7f1ac238[] = {0x7f09a17c};
const u32 var7f1ac23c[] = {0x7f09a1b8};
const u32 var7f1ac240[] = {0x7f09a1b8};
const u32 var7f1ac244[] = {0x7f09a1b8};
const u32 var7f1ac248[] = {0x7f09a17c};
const u32 var7f1ac24c[] = {0x7f09a17c};
const u32 var7f1ac250[] = {0x7f09a17c};
const u32 var7f1ac254[] = {0x7f09a17c};
const u32 var7f1ac258[] = {0x7f09a17c};
const u32 var7f1ac25c[] = {0x7f09a17c};
const u32 var7f1ac260[] = {0x7f09a17c};
const u32 var7f1ac264[] = {0x7f09a17c};
const u32 var7f1ac268[] = {0x7f09a17c};
const u32 var7f1ac26c[] = {0x7f09a17c};
const u32 var7f1ac270[] = {0x7f09a17c};
const u32 var7f1ac274[] = {0x7f09a17c};
const u32 var7f1ac278[] = {0x7f09a17c};
const u32 var7f1ac27c[] = {0x7f09a17c};
const u32 var7f1ac280[] = {0x7f09a17c};
const u32 var7f1ac284[] = {0x7f09a17c};
const u32 var7f1ac288[] = {0x7f09a17c};
const u32 var7f1ac28c[] = {0x7f09a17c};
const u32 var7f1ac290[] = {0x7f09a1b8};
const u32 var7f1ac294[] = {0x7f09a17c};
const u32 var7f1ac298[] = {0x7f09a17c};
const u32 var7f1ac29c[] = {0x7f09a17c};
const u32 var7f1ac2a0[] = {0x7f09a17c};
const u32 var7f1ac2a4[] = {0x7f09a17c};
const u32 var7f1ac2a8[] = {0x7f09a17c};
const u32 var7f1ac2ac[] = {0x7f09a17c};
const u32 var7f1ac2b0[] = {0x7f09a1b8};
const u32 var7f1ac2b4[] = {0x7f09a1b8};
const u32 var7f1ac2b8[] = {0x7f09a1b8};
const u32 var7f1ac2bc[] = {0x7f09a17c};
const u32 var7f1ac2c0[] = {0x7f09a17c};
const u32 var7f1ac2c4[] = {0x7f09a17c};
const u32 var7f1ac2c8[] = {0x7f09a17c};
const u32 var7f1ac2cc[] = {0x7f09a17c};
const u32 var7f1ac2d0[] = {0x7f09a17c};
const u32 var7f1ac2d4[] = {0x7f09a17c};
const u32 var7f1ac2d8[] = {0x7f09a17c};
const u32 var7f1ac2dc[] = {0x7f09a17c};
const u32 var7f1ac2e0[] = {0x7f09a17c};
const u32 var7f1ac2e4[] = {0x7f09a17c};
const u32 var7f1ac2e8[] = {0x7f09a17c};
const u32 var7f1ac2ec[] = {0x7f09a17c};
const u32 var7f1ac2f0[] = {0x7f09a17c};
const u32 var7f1ac2f4[] = {0x7f09a17c};
const u32 var7f1ac2f8[] = {0x7f09a17c};
const u32 var7f1ac2fc[] = {0x7f09a17c};
const u32 var7f1ac300[] = {0x7f09a17c};
const u32 var7f1ac304[] = {0x7f09a17c};
const u32 var7f1ac308[] = {0x7f09a17c};
const u32 var7f1ac30c[] = {0x7f09a17c};
const u32 var7f1ac310[] = {0x7f09a17c};
const u32 var7f1ac314[] = {0x7f09a17c};
const u32 var7f1ac318[] = {0x7f09a1b8};
const u32 var7f1ac31c[] = {0x3f5f5dd8};
const u32 var7f1ac320[] = {0x3ecccccd};
const u32 var7f1ac324[] = {0x3fc90fdb};
const u32 var7f1ac328[] = {0x40c907a9};
const u32 var7f1ac32c[] = {0x3fc90fdb};
const u32 var7f1ac330[] = {0x40490fdb};
const u32 var7f1ac334[] = {0x3ecccccd};
const u32 var7f1ac338[] = {0x3dcccccd};
const u32 var7f1ac33c[] = {0x3c23d70a};
const u32 var7f1ac340[] = {0x7f09b928};
const u32 var7f1ac344[] = {0x7f09b928};
const u32 var7f1ac348[] = {0x7f09b928};
const u32 var7f1ac34c[] = {0x7f09b928};
const u32 var7f1ac350[] = {0x7f09b928};
const u32 var7f1ac354[] = {0x7f09b928};
const u32 var7f1ac358[] = {0x7f09b928};
const u32 var7f1ac35c[] = {0x7f09b928};
const u32 var7f1ac360[] = {0x7f09b928};
const u32 var7f1ac364[] = {0x7f09b928};
const u32 var7f1ac368[] = {0x7f09b928};
const u32 var7f1ac36c[] = {0x7f09b928};
const u32 var7f1ac370[] = {0x7f09b928};
const u32 var7f1ac374[] = {0x7f09b9f8};
const u32 var7f1ac378[] = {0x7f09b9f8};
const u32 var7f1ac37c[] = {0x7f09b9f8};
const u32 var7f1ac380[] = {0x7f09b9f8};
const u32 var7f1ac384[] = {0x7f09b9f8};
const u32 var7f1ac388[] = {0x7f09b928};
const u32 var7f1ac38c[] = {0x7f09b9f8};
const u32 var7f1ac390[] = {0x7f09b9f8};
const u32 var7f1ac394[] = {0x7f09b9f8};
const u32 var7f1ac398[] = {0x7f09b9f8};
const u32 var7f1ac39c[] = {0x7f09b9f8};
const u32 var7f1ac3a0[] = {0x7f09b9f8};
const u32 var7f1ac3a4[] = {0x7f09b9f8};
const u32 var7f1ac3a8[] = {0x7f09b928};
const u32 var7f1ac3ac[] = {0x7f09b9f8};
const u32 var7f1ac3b0[] = {0x7f09b9f8};
const u32 var7f1ac3b4[] = {0x7f09b9f8};
const u32 var7f1ac3b8[] = {0x7f09b9f8};
const u32 var7f1ac3bc[] = {0x7f09b9f8};
const u32 var7f1ac3c0[] = {0x7f09b9f8};
const u32 var7f1ac3c4[] = {0x7f09b9f8};
const u32 var7f1ac3c8[] = {0x7f09b928};
const u32 var7f1ac3cc[] = {0x7f09b928};
const u32 var7f1ac3d0[] = {0x7f09bbd8};
const u32 var7f1ac3d4[] = {0x7f09bb9c};
const u32 var7f1ac3d8[] = {0x7f09bb9c};
const u32 var7f1ac3dc[] = {0x7f09bb9c};
const u32 var7f1ac3e0[] = {0x7f09bb9c};
const u32 var7f1ac3e4[] = {0x7f09bb9c};
const u32 var7f1ac3e8[] = {0x7f09ba7c};
const u32 var7f1ac3ec[] = {0x7f09bb9c};
const u32 var7f1ac3f0[] = {0x7f09bb9c};
const u32 var7f1ac3f4[] = {0x7f09bb9c};
const u32 var7f1ac3f8[] = {0x7f09bb9c};
const u32 var7f1ac3fc[] = {0x7f09ba7c};
const u32 var7f1ac400[] = {0x7f09bb9c};
const u32 var7f1ac404[] = {0x7f09bb9c};
const u32 var7f1ac408[] = {0x7f09bb9c};
const u32 var7f1ac40c[] = {0x7f09bb9c};
const u32 var7f1ac410[] = {0x7f09bb9c};
const u32 var7f1ac414[] = {0x7f09bb9c};
const u32 var7f1ac418[] = {0x7f09bb9c};
const u32 var7f1ac41c[] = {0x7f09bb9c};
const u32 var7f1ac420[] = {0x7f09bb9c};
const u32 var7f1ac424[] = {0x7f09ba7c};
const u32 var7f1ac428[] = {0x7f09bb9c};
const u32 var7f1ac42c[] = {0x7f09bb9c};
const u32 var7f1ac430[] = {0x7f09bb9c};
const u32 var7f1ac434[] = {0x7f09bbd8};
const u32 var7f1ac438[] = {0x7f09bb9c};
const u32 var7f1ac43c[] = {0x7f09bb08};
const u32 var7f1ac440[] = {0x7f09bb9c};
const u32 var7f1ac444[] = {0x7f09bbd8};
const u32 var7f1ac448[] = {0x7f09bbd8};
const u32 var7f1ac44c[] = {0x7f09bbd8};
const u32 var7f1ac450[] = {0x7f09bbd8};
const u32 var7f1ac454[] = {0x7f09bbd8};
const u32 var7f1ac458[] = {0x7f09bbd8};
const u32 var7f1ac45c[] = {0x7f09bb9c};
const u32 var7f1ac460[] = {0x7f09bb9c};
const u32 var7f1ac464[] = {0x7f09bb9c};
const u32 var7f1ac468[] = {0x7f09bb9c};
const u32 var7f1ac46c[] = {0x7f09bb9c};
const u32 var7f1ac470[] = {0x7f09bb9c};
const u32 var7f1ac474[] = {0x7f09bb9c};
const u32 var7f1ac478[] = {0x7f09bb9c};
const u32 var7f1ac47c[] = {0x7f09bb08};
const u32 var7f1ac480[] = {0x40047ae1};
const u32 var7f1ac484[] = {0x3f5f5dd8};
const u32 var7f1ac488[] = {0x7f09c9ec};
const u32 var7f1ac48c[] = {0x7f09c9ec};
const u32 var7f1ac490[] = {0x7f09c9b0};
const u32 var7f1ac494[] = {0x7f09c9b0};
const u32 var7f1ac498[] = {0x7f09c9b0};
const u32 var7f1ac49c[] = {0x7f09c9b0};
const u32 var7f1ac4a0[] = {0x7f09c9b0};
const u32 var7f1ac4a4[] = {0x7f09c9b0};
const u32 var7f1ac4a8[] = {0x7f09c9b0};
const u32 var7f1ac4ac[] = {0x7f09c9b0};
const u32 var7f1ac4b0[] = {0x7f09c9b0};
const u32 var7f1ac4b4[] = {0x7f09c9b0};
const u32 var7f1ac4b8[] = {0x7f09c9b0};
const u32 var7f1ac4bc[] = {0x7f09c9b0};
const u32 var7f1ac4c0[] = {0x7f09c9ec};
const u32 var7f1ac4c4[] = {0x7f09c9b0};
const u32 var7f1ac4c8[] = {0x7f09c9b0};
const u32 var7f1ac4cc[] = {0x7f09c9b0};
const u32 var7f1ac4d0[] = {0x7f09c9b0};
const u32 var7f1ac4d4[] = {0x7f09c9b0};
const u32 var7f1ac4d8[] = {0x7f09c91c};
const u32 var7f1ac4dc[] = {0x7f09c9b0};
const u32 var7f1ac4e0[] = {0x7f09c9b0};
const u32 var7f1ac4e4[] = {0x7f09c9b0};
const u32 var7f1ac4e8[] = {0x7f09c9b0};
const u32 var7f1ac4ec[] = {0x7f09c9b0};
const u32 var7f1ac4f0[] = {0x7f09c7b4};
const u32 var7f1ac4f4[] = {0x7f09c9ec};
const u32 var7f1ac4f8[] = {0x7f09c888};
const u32 var7f1ac4fc[] = {0x7f09c770};
const u32 var7f1ac500[] = {0x7f09c9ec};
const u32 var7f1ac504[] = {0x7f09c9ec};
const u32 var7f1ac508[] = {0x7f09c844};
const u32 var7f1ac50c[] = {0x7f09c844};
const u32 var7f1ac510[] = {0x7f09c7f8};
const u32 var7f1ac514[] = {0x7f09c9ec};
const u32 var7f1ac518[] = {0x7f09c9b0};
const u32 var7f1ac51c[] = {0x7f09c9b0};
const u32 var7f1ac520[] = {0x7f09c9b0};
const u32 var7f1ac524[] = {0x7f09c9b0};
const u32 var7f1ac528[] = {0x7f09c9b0};
const u32 var7f1ac52c[] = {0x7f09c9b0};
const u32 var7f1ac530[] = {0x7f09c9b0};
const u32 var7f1ac534[] = {0x7f09c9b0};
const u32 var7f1ac538[] = {0x7f09c888};
const u32 var7f1ac53c[] = {0x7f09c9b0};
const u32 var7f1ac540[] = {0x7f09c9b0};
const u32 var7f1ac544[] = {0x7f09c9b0};
const u32 var7f1ac548[] = {0x7f09c9b0};
const u32 var7f1ac54c[] = {0x7f09c9ec};
const u32 var7f1ac550[] = {0x7f09c6dc};
const u32 var7f1ac554[] = {0x7f09c9b0};
const u32 var7f1ac558[] = {0x7f09c9b0};
const u32 var7f1ac55c[] = {0x7f09c844};
const u32 var7f1ac560[] = {0x7f09c844};
const u32 var7f1ac564[] = {0x7f09c844};
const u32 var7f1ac568[] = {0x7f09c844};
const u32 var7f1ac56c[] = {0x7f09c844};
const u32 var7f1ac570[] = {0x7f09c844};
const u32 var7f1ac574[] = {0x7f09c9ec};
const u32 var7f1ac578[] = {0x7f09c9ec};
const u32 var7f1ac57c[] = {0x7f09c844};
const u32 var7f1ac580[] = {0x7f09c844};
const u32 var7f1ac584[] = {0x7f09c844};
const u32 var7f1ac588[] = {0x7f09c9ec};
const u32 var7f1ac58c[] = {0x7f09c9ec};
const u32 var7f1ac590[] = {0x7f09c9ec};
const u32 var7f1ac594[] = {0x7f09c9ec};
const u32 var7f1ac598[] = {0x7f09c9ec};
const u32 var7f1ac59c[] = {0x7f09c9ec};
const u32 var7f1ac5a0[] = {0x7f09c9ec};
const u32 var7f1ac5a4[] = {0x7f09c9ec};
const u32 var7f1ac5a8[] = {0x7f09c9ec};
const u32 var7f1ac5ac[] = {0x7f09c9ec};
const u32 var7f1ac5b0[] = {0x7f09c9ec};
const u32 var7f1ac5b4[] = {0x7f09c9ec};
const u32 var7f1ac5b8[] = {0x7f09c9ec};
const u32 var7f1ac5bc[] = {0x7f09c9ec};
const u32 var7f1ac5c0[] = {0x7f09c9ec};
const u32 var7f1ac5c4[] = {0x7f09c9b0};
const u32 var7f1ac5c8[] = {0x7f09c9ec};
const u32 var7f1ac5cc[] = {0x7f09c9b0};
const u32 var7f1ac5d0[] = {0x7f09c9b0};
const u32 var7f1ac5d4[] = {0x7f09c9b0};
const u32 var7f1ac5d8[] = {0x7f09c9b0};
const u32 var7f1ac5dc[] = {0x7f09c9b0};
const u32 var7f1ac5e0[] = {0x7f09c9b0};
const u32 var7f1ac5e4[] = {0x7f09c9ec};
const u32 var7f1ac5e8[] = {0x3f59999a};
const u32 var7f1ac5ec[] = {0x3f5f5dd8};
const u32 var7f1ac5f0[] = {0x7f09cc10};
const u32 var7f1ac5f4[] = {0x7f09cc28};
const u32 var7f1ac5f8[] = {0x7f09cc58};
const u32 var7f1ac5fc[] = {0x7f09cc88};
const u32 var7f1ac600[] = {0x7f09cc40};
const u32 var7f1ac604[] = {0x7f09cc70};
const u32 var7f1ac608[] = {0x7f09cccc};
const u32 var7f1ac60c[] = {0x7f09ccb8};
const u32 var7f1ac610[] = {0x7f09cca0};
const u32 var7f1ac614[] = {0x3da3d70a};
const u32 var7f1ac618[] = {0x3dcccccd};
const u32 var7f1ac61c[] = {0x3dcccccd};
const u32 var7f1ac620[] = {0x3dcccccd};
const u32 var7f1ac624[] = {0x3f7cb924};
const u32 var7f1ac628[] = {0x3c51b700};
const u32 var7f1ac62c[] = {0x3f4ccccd};
const u32 var7f1ac630[] = {0x3dcccccd};
const u32 var7f1ac634[] = {0x3dcccccd};
const u32 var7f1ac638[] = {0x40c907a9};
const u32 var7f1ac63c[] = {0x40333333};
const u32 var7f1ac640[] = {0x3f4ccccd};
const u32 var7f1ac644[] = {0x3e4ccccd};
const u32 var7f1ac648[] = {0x3dcccccd};
const u32 var7f1ac64c[] = {0x3e99999a};
const u32 var7f1ac650[] = {0x3f7cb924};
const u32 var7f1ac654[] = {0x3f7cb924};
const u32 var7f1ac658[] = {0x3c51b700};
const u32 var7f1ac65c[] = {0x3c888889};
const u32 var7f1ac660[] = {0x3e4ccccd};
const u32 var7f1ac664[] = {0x3dcccccd};
const u32 var7f1ac668[] = {0xbdcccccd};
const u32 var7f1ac66c[] = {0xbf4ccccd};
const u32 var7f1ac670[] = {0x7f09df30};
const u32 var7f1ac674[] = {0x7f09df40};
const u32 var7f1ac678[] = {0x7f09df40};
const u32 var7f1ac67c[] = {0x7f09df40};
const u32 var7f1ac680[] = {0x7f09df40};
const u32 var7f1ac684[] = {0x7f09df40};
const u32 var7f1ac688[] = {0x7f09df40};
const u32 var7f1ac68c[] = {0x7f09df40};
const u32 var7f1ac690[] = {0x7f09df40};
const u32 var7f1ac694[] = {0x7f09df40};
const u32 var7f1ac698[] = {0x7f09df30};
const u32 var7f1ac69c[] = {0x7f09df40};
const u32 var7f1ac6a0[] = {0x7f09df40};
const u32 var7f1ac6a4[] = {0x7f09df40};
const u32 var7f1ac6a8[] = {0x7f09df40};
const u32 var7f1ac6ac[] = {0x7f09df30};
const u32 var7f1ac6b0[] = {0x7f09df40};
const u32 var7f1ac6b4[] = {0x7f09df40};
const u32 var7f1ac6b8[] = {0x7f09df40};
const u32 var7f1ac6bc[] = {0x7f09df40};
const u32 var7f1ac6c0[] = {0x7f09df30};
const u32 var7f1ac6c4[] = {0x7f09df40};
const u32 var7f1ac6c8[] = {0x7f09df40};
const u32 var7f1ac6cc[] = {0x7f09df30};
const u32 var7f1ac6d0[] = {0x7f09e080};
const u32 var7f1ac6d4[] = {0x7f09e11c};
const u32 var7f1ac6d8[] = {0x7f09e0b8};
const u32 var7f1ac6dc[] = {0x7f09e110};
const u32 var7f1ac6e0[] = {0x7f09e11c};
const u32 var7f1ac6e4[] = {0x7f09e11c};
const u32 var7f1ac6e8[] = {0x7f09e11c};
const u32 var7f1ac6ec[] = {0x7f09e11c};
const u32 var7f1ac6f0[] = {0x7f09e11c};
const u32 var7f1ac6f4[] = {0x7f09e11c};
const u32 var7f1ac6f8[] = {0x7f09e118};
const u32 var7f1ac6fc[] = {0x7f09e118};
const u32 var7f1ac700[] = {0x4141999a};
const u32 var7f1ac704[] = {0x3dcccccd};
const u32 var7f1ac708[] = {0x4096c5bf};
const u32 var7f1ac70c[] = {0x404907a9};
const u32 var7f1ac710[] = {0x3fd55555};
const u32 var7f1ac714[] = {0x3eb2b179};
const u32 var7f1ac718[] = {0xbeb2b179};
const u32 var7f1ac71c[] = {0x3eb2b179};
const u32 var7f1ac720[] = {0x41ad5555};
const u32 var7f1ac724[] = {0x41855555};
const u32 var7f1ac728[] = {0x3fd55555};
const u32 var7f1ac72c[] = {0x3dcccccd};
const u32 var7f1ac730[] = {0x3fd55555};
const u32 var7f1ac734[] = {0x3e32b179};
const u32 var7f1ac738[] = {0xbe32b179};
const u32 var7f1ac73c[] = {0x3e32b179};
const u32 var7f1ac740[] = {0x3fd55555};
const u32 var7f1ac744[] = {0x3e99999a};
const u32 var7f1ac748[] = {0x3dcccccd};
const u32 var7f1ac74c[] = {0x3e99999a};
const u32 var7f1ac750[] = {0x3dcccccd};
const u32 var7f1ac754[] = {0xb3d6bf95};
const u32 var7f1ac758[] = {0x33d6bf95};
const u32 var7f1ac75c[] = {0xc5bb8000};
const u32 var7f1ac760[] = {0x3f6d4de3};
const u32 var7f1ac764[] = {0x3d9590e8};
const u32 var7f1ac768[] = {0x3e2aaaab};
const u32 var7f1ac76c[] = {0x7f0a2de0};
const u32 var7f1ac770[] = {0x7f0a2e00};
const u32 var7f1ac774[] = {0x7f0a2e20};
const u32 var7f1ac778[] = {0x7f0a2e38};
const u32 var7f1ac77c[] = {0x7f0a2e4c};
const u32 var7f1ac780[] = {0x7f0a2e60};
const u32 var7f1ac784[] = {0x7f0a2f10};
const u32 var7f1ac788[] = {0x7f0a3070};
const u32 var7f1ac78c[] = {0x7f0a3070};
const u32 var7f1ac790[] = {0x7f0a2fb4};
const u32 var7f1ac794[] = {0x7f0a2fdc};
const u32 var7f1ac798[] = {0x7f0a3070};
const u32 var7f1ac79c[] = {0x7f0a3070};
const u32 var7f1ac7a0[] = {0x7f0a3070};
const u32 var7f1ac7a4[] = {0x7f0a3070};
const u32 var7f1ac7a8[] = {0x7f0a3070};
const u32 var7f1ac7ac[] = {0x7f0a2f4c};
const u32 var7f1ac7b0[] = {0x7f0a3070};
const u32 var7f1ac7b4[] = {0x7f0a3070};
const u32 var7f1ac7b8[] = {0x7f0a3070};
const u32 var7f1ac7bc[] = {0x7f0a3070};
const u32 var7f1ac7c0[] = {0x7f0a2f88};
const u32 var7f1ac7c4[] = {0x7f0a3004};
const u32 var7f1ac7c8[] = {0x40490fdb};
const u32 var7f1ac7cc[] = {0x42853333};
const u32 var7f1ac7d0[] = {0x3c8efa35};
const u32 var7f1ac7d4[] = {0x3f19999a};
const u32 var7f1ac7d8[] = {0x3e4ccccd};
const u32 var7f1ac7dc[] = {0x7f0a35ac};
const u32 var7f1ac7e0[] = {0x7f0a36dc};
const u32 var7f1ac7e4[] = {0x7f0a35ac};
const u32 var7f1ac7e8[] = {0x7f0a35dc};
const u32 var7f1ac7ec[] = {0x7f0a35dc};
const u32 var7f1ac7f0[] = {0x7f0a36dc};
const u32 var7f1ac7f4[] = {0x7f0a360c};
const u32 var7f1ac7f8[] = {0x7f0a360c};
const u32 var7f1ac7fc[] = {0x7f0a363c};
const u32 var7f1ac800[] = {0x7f0a3664};
const u32 var7f1ac804[] = {0x7f0a36dc};
const u32 var7f1ac808[] = {0x7f0a3690};
const u32 var7f1ac80c[] = {0x7f0a3664};
const u32 var7f1ac810[] = {0x7f0a363c};
const u32 var7f1ac814[] = {0x7f0a363c};
const u32 var7f1ac818[] = {0x7f0a363c};
const u32 var7f1ac81c[] = {0x7f0a363c};
const u32 var7f1ac820[] = {0x7f0a36c4};
const u32 var7f1ac824[] = {0x7f0a36b8};
const u32 var7f1ac828[] = {0x3f28f5c3};
const u32 var7f1ac82c[] = {0x3f666666};
const u32 var7f1ac830[] = {0x7f0a372c};
const u32 var7f1ac834[] = {0x7f0a3740};
const u32 var7f1ac838[] = {0x7f0a372c};
const u32 var7f1ac83c[] = {0x7f0a372c};
const u32 var7f1ac840[] = {0x7f0a372c};
const u32 var7f1ac844[] = {0x7f0a3740};
const u32 var7f1ac848[] = {0x7f0a372c};
const u32 var7f1ac84c[] = {0x7f0a372c};
const u32 var7f1ac850[] = {0x7f0a3740};
const u32 var7f1ac854[] = {0x7f0a3740};
const u32 var7f1ac858[] = {0x7f0a3740};
const u32 var7f1ac85c[] = {0x7f0a3740};
const u32 var7f1ac860[] = {0x7f0a3740};
const u32 var7f1ac864[] = {0x7f0a3740};
const u32 var7f1ac868[] = {0x7f0a3740};
const u32 var7f1ac86c[] = {0x7f0a3740};
const u32 var7f1ac870[] = {0x7f0a3740};
const u32 var7f1ac874[] = {0x7f0a373c};
const u32 var7f1ac878[] = {0x7f0a3734};
const u32 var7f1ac87c[] = {0x3c23d70a};
const u32 var7f1ac880[] = {0x3f747ae1};
const u32 var7f1ac884[] = {0x47ae147b};
const u32 var7f1ac888[] = {0x33d6bf95};
const u32 var7f1ac88c[] = {0xbe0f5c29};
const u32 var7f1ac890[] = {0x3e19999a};
const u32 var7f1ac894[] = {0x40490fdb};
const u32 var7f1ac898[] = {0x3e4ccccd};
const u32 var7f1ac89c[] = {0x40490fdb};
const u32 var7f1ac8a0[] = {0x3e4ccccd};
const u32 var7f1ac8a4[] = {0x40c90fd0};
const u32 var7f1ac8a8[] = {0x3dcccccd};
const u32 var7f1ac8ac[] = {0x3dcccccd};
const u32 var7f1ac8b0[] = {0x3ecccccd};
const u32 var7f1ac8b4[] = {0x3f19999a};
const u32 var7f1ac8b8[] = {0x46fffe00};
const u32 var7f1ac8bc[] = {0x3c23d70a};
const u32 var7f1ac8c0[] = {0x3fd16873};
const u32 var7f1ac8c4[] = {0x3c23d70a};
const u32 var7f1ac8c8[] = {0x411fffff};
const u32 var7f1ac8cc[] = {0x3f088888};
const u32 var7f1ac8d0[] = {0x40c907a9};
const u32 var7f1ac8d4[] = {0x3d0bd8cf};
const u32 var7f1ac8d8[] = {0x40c907a9};
const u32 var7f1ac8dc[] = {0x3d0bd8cf};
const u32 var7f1ac8e0[] = {0x40c907a9};
const u32 var7f1ac8e4[] = {0x3d0bd8cf};
const u32 var7f1ac8e8[] = {0x3f088888};
const u32 var7f1ac8ec[] = {0x40c907a9};
const u32 var7f1ac8f0[] = {0x40c907a9};
const u32 var7f1ac8f4[] = {0x3c3d3463};
const u32 var7f1ac8f8[] = {0x40c907a9};
const u32 var7f1ac8fc[] = {0x3c3d3463};
const u32 var7f1ac900[] = {0x40c907a9};
const u32 var7f1ac904[] = {0x40c907a9};
const u32 var7f1ac908[] = {0x3bda10fd};
const u32 var7f1ac90c[] = {0x40c907a9};
const u32 var7f1ac910[] = {0x3bda10fd};
const u32 var7f1ac914[] = {0x3e99999a};
const u32 var7f1ac918[] = {0x3e8e38e4};
const u32 var7f1ac91c[] = {0x40c907a9};
const u32 var7f1ac920[] = {0x3fd33333};
const u32 var7f1ac924[] = {0x33333333};
const u32 var7f1ac928[] = {0x3fc33333};
const u32 var7f1ac92c[] = {0x33333333};
const u32 var7f1ac930[] = {0x3dccccce};
const u32 var7f1ac934[] = {0x40c907a9};
const u32 var7f1ac938[] = {0x411fffff};
const u32 var7f1ac93c[] = {0x7f0a550c};
const u32 var7f1ac940[] = {0x7f0a550c};
const u32 var7f1ac944[] = {0x7f0a550c};
const u32 var7f1ac948[] = {0x7f0a550c};
const u32 var7f1ac94c[] = {0x7f0a550c};
const u32 var7f1ac950[] = {0x7f0a550c};
const u32 var7f1ac954[] = {0x7f0a550c};
const u32 var7f1ac958[] = {0x7f0a550c};
const u32 var7f1ac95c[] = {0x7f0a550c};
const u32 var7f1ac960[] = {0x7f0a550c};
const u32 var7f1ac964[] = {0x7f0a550c};
const u32 var7f1ac968[] = {0x7f0a550c};
const u32 var7f1ac96c[] = {0x7f0a550c};
const u32 var7f1ac970[] = {0x7f0a550c};
const u32 var7f1ac974[] = {0x7f0a550c};
const u32 var7f1ac978[] = {0x7f0a550c};
const u32 var7f1ac97c[] = {0x7f0a550c};
const u32 var7f1ac980[] = {0x7f0a5540};
const u32 var7f1ac984[] = {0x7f0a550c};
const u32 var7f1ac988[] = {0x7f0a550c};
const u32 var7f1ac98c[] = {0x7f0a550c};
const u32 var7f1ac990[] = {0x7f0a5540};
const u32 var7f1ac994[] = {0x7f0a5540};
const u32 var7f1ac998[] = {0x7f0a5540};
const u32 var7f1ac99c[] = {0x7f0a5540};
const u32 var7f1ac9a0[] = {0x7f0a5540};
const u32 var7f1ac9a4[] = {0x7f0a550c};
const u32 var7f1ac9a8[] = {0x7f0a5528};
const u32 var7f1ac9ac[] = {0x7f0a5540};
const u32 var7f1ac9b0[] = {0x7f0a5540};
const u32 var7f1ac9b4[] = {0x7f0a5540};
const u32 var7f1ac9b8[] = {0x7f0a5540};
const u32 var7f1ac9bc[] = {0x7f0a5540};
const u32 var7f1ac9c0[] = {0x7f0a5540};
const u32 var7f1ac9c4[] = {0x7f0a550c};
const u32 var7f1ac9c8[] = {0x7f0a550c};
const u32 var7f1ac9cc[] = {0x7f0a550c};
const u32 var7f1ac9d0[] = {0x7f0a550c};
const u32 var7f1ac9d4[] = {0x7f0a550c};
const u32 var7f1ac9d8[] = {0x7f0a550c};
const u32 var7f1ac9dc[] = {0x7f0a550c};
const u32 var7f1ac9e0[] = {0x7f0a550c};
const u32 var7f1ac9e4[] = {0x40490fdb};
const u32 var7f1ac9e8[] = {0x3dccccce};
const u32 var7f1ac9ec[] = {0x7f0a61f4};
const u32 var7f1ac9f0[] = {0x7f0a6254};
const u32 var7f1ac9f4[] = {0x7f0a6254};
const u32 var7f1ac9f8[] = {0x7f0a6254};
const u32 var7f1ac9fc[] = {0x7f0a6254};
const u32 var7f1aca00[] = {0x7f0a6254};
const u32 var7f1aca04[] = {0x7f0a61fc};
const u32 var7f1aca08[] = {0x7f0a6254};
const u32 var7f1aca0c[] = {0x7f0a6254};
const u32 var7f1aca10[] = {0x7f0a6254};
const u32 var7f1aca14[] = {0x7f0a6210};
const u32 var7f1aca18[] = {0x7f0a6210};
const u32 var7f1aca1c[] = {0x7f0a6210};
const u32 var7f1aca20[] = {0x7f0a6210};
const u32 var7f1aca24[] = {0x7f0a6210};
const u32 var7f1aca28[] = {0x7f0a6254};
const u32 var7f1aca2c[] = {0x7f0a6254};
const u32 var7f1aca30[] = {0x7f0a6254};
const u32 var7f1aca34[] = {0x7f0a6254};
const u32 var7f1aca38[] = {0x7f0a6254};
const u32 var7f1aca3c[] = {0x7f0a6254};
const u32 var7f1aca40[] = {0x7f0a6254};
const u32 var7f1aca44[] = {0x7f0a6254};
const u32 var7f1aca48[] = {0x7f0a6254};
const u32 var7f1aca4c[] = {0x7f0a6254};
const u32 var7f1aca50[] = {0x7f0a6254};
const u32 var7f1aca54[] = {0x7f0a6254};
const u32 var7f1aca58[] = {0x7f0a6254};
const u32 var7f1aca5c[] = {0x7f0a6254};
const u32 var7f1aca60[] = {0x7f0a6254};
const u32 var7f1aca64[] = {0x7f0a6254};
const u32 var7f1aca68[] = {0x7f0a6254};
const u32 var7f1aca6c[] = {0x7f0a6254};
const u32 var7f1aca70[] = {0x7f0a6210};
const u32 var7f1aca74[] = {0x40490fdb};
const u32 var7f1aca78[] = {0x3dcccccd};
const u32 var7f1aca7c[] = {0x3d4ccccd};
const u32 var7f1aca80[] = {0x3ba3d70a};
const u32 var7f1aca84[] = {0x3cf5c28f};
const u32 var7f1aca88[] = {0x3ecccccd};
const u32 var7f1aca8c[] = {0x3faaaaab};
const u32 var7f1aca90[] = {0x3f3ebebf};
const u32 var7f1aca94[] = {0x453b8000};
const u32 var7f1aca98[] = {0x453b8000};
const u32 var7f1aca9c[] = {0x453b8000};
const u32 var7f1acaa0[] = {0x453b8000};
const u32 var7f1acaa4[] = {0x7f0a8a60};
const u32 var7f1acaa8[] = {0x7f0a8b50};
const u32 var7f1acaac[] = {0x7f0a8b50};
const u32 var7f1acab0[] = {0x7f0a8b50};
const u32 var7f1acab4[] = {0x7f0a8a60};
const u32 var7f1acab8[] = {0x7f0a8b50};
const u32 var7f1acabc[] = {0x7f0a8b50};
const u32 var7f1acac0[] = {0x7f0a8a0c};
const u32 var7f1acac4[] = {0x7f0a8a0c};
const u32 var7f1acac8[] = {0x7f0a8a0c};
const u32 var7f1acacc[] = {0x7f0a8a60};
const u32 var7f1acad0[] = {0x7f0a8a60};
const u32 var7f1acad4[] = {0x7f0a8b50};
const u32 var7f1acad8[] = {0x7f0a8b50};
const u32 var7f1acadc[] = {0x7f0a8b50};
const u32 var7f1acae0[] = {0x7f0a89a0};
const u32 var7f1acae4[] = {0x7f0a8a60};
const u32 var7f1acae8[] = {0x7f0a8b50};
const u32 var7f1acaec[] = {0x7f0a8b50};
const u32 var7f1acaf0[] = {0x7f0a8b50};
const u32 var7f1acaf4[] = {0x7f0a8b50};
const u32 var7f1acaf8[] = {0x7f0a8b50};
const u32 var7f1acafc[] = {0x7f0a8b50};
const u32 var7f1acb00[] = {0x7f0a8b50};
const u32 var7f1acb04[] = {0x7f0a8b50};
const u32 var7f1acb08[] = {0x7f0a8b50};
const u32 var7f1acb0c[] = {0x7f0a8a60};
const u32 var7f1acb10[] = {0x7f0a8b50};
const u32 var7f1acb14[] = {0x7f0a8a0c};
const u32 var7f1acb18[] = {0x7f0a8e6c};
const u32 var7f1acb1c[] = {0x7f0a8ee8};
const u32 var7f1acb20[] = {0x7f0a8ee8};
const u32 var7f1acb24[] = {0x7f0a8ee8};
const u32 var7f1acb28[] = {0x7f0a8e6c};
const u32 var7f1acb2c[] = {0x7f0a8e6c};
const u32 var7f1acb30[] = {0x7f0a8ee8};
const u32 var7f1acb34[] = {0x7f0a8ee8};
const u32 var7f1acb38[] = {0x7f0a8ee8};
const u32 var7f1acb3c[] = {0x7f0a8e6c};
const u32 var7f1acb40[] = {0x7f0a8ee8};
const u32 var7f1acb44[] = {0x7f0a8ee8};
const u32 var7f1acb48[] = {0x7f0a8ee8};
const u32 var7f1acb4c[] = {0x7f0a8ee8};
const u32 var7f1acb50[] = {0x7f0a8ee8};
const u32 var7f1acb54[] = {0x7f0a8ee8};
const u32 var7f1acb58[] = {0x7f0a8ee8};
const u32 var7f1acb5c[] = {0x7f0a8ee8};
const u32 var7f1acb60[] = {0x7f0a8ee8};
const u32 var7f1acb64[] = {0x7f0a8ee8};
const u32 var7f1acb68[] = {0x7f0a8ee8};
const u32 var7f1acb6c[] = {0x7f0a8ee8};
const u32 var7f1acb70[] = {0x7f0a8ee8};
const u32 var7f1acb74[] = {0x7f0a8e6c};
const u32 var7f1acb78[] = {0x7f0a8ee8};
const u32 var7f1acb7c[] = {0x7f0a8ee8};
const u32 var7f1acb80[] = {0x7f0a8ee8};
const u32 var7f1acb84[] = {0x7f0a8e6c};
const u32 var7f1acb88[] = {0x7f0a8ee8};
const u32 var7f1acb8c[] = {0x7f0a8ee8};
const u32 var7f1acb90[] = {0x7f0a8ee8};
const u32 var7f1acb94[] = {0x7f0a8ee8};
const u32 var7f1acb98[] = {0x7f0a8ee8};
const u32 var7f1acb9c[] = {0x7f0a8ee8};
const u32 var7f1acba0[] = {0x7f0a8ee8};
const u32 var7f1acba4[] = {0x7f0a8e6c};
const u32 var7f1acba8[] = {0x7f0a8e6c};
const u32 var7f1acbac[] = {0x7f0a8e6c};
const u32 var7f1acbb0[] = {0xc7c35000};
const u32 var7f1acbb4[] = {0x47c35000};
const u32 var7f1acbb8[] = {0x7f0a9934};
const u32 var7f1acbbc[] = {0x7f0a9974};
const u32 var7f1acbc0[] = {0x7f0a9950};
const u32 var7f1acbc4[] = {0x7f0a9974};
const u32 var7f1acbc8[] = {0x7f0a9974};
const u32 var7f1acbcc[] = {0x7f0a9974};
const u32 var7f1acbd0[] = {0x7f0a9974};
const u32 var7f1acbd4[] = {0x7f0a9974};
const u32 var7f1acbd8[] = {0x7f0a9974};
const u32 var7f1acbdc[] = {0x7f0a9974};
const u32 var7f1acbe0[] = {0x7f0a996c};
const u32 var7f1acbe4[] = {0x7f0a996c};
const u32 var7f1acbe8[] = {0x7f0a996c};
const u32 var7f1acbec[] = {0x7f0a996c};
const u32 var7f1acbf0[] = {0x7f0a996c};
const u32 var7f1acbf4[] = {0x7f0a996c};
const u32 var7f1acbf8[] = {0x7f0a996c};
const u32 var7f1acbfc[] = {0x7f0a996c};
const u32 var7f1acc00[] = {0x7f0a996c};
const u32 var7f1acc04[] = {0x7f0a996c};
const u32 var7f1acc08[] = {0x7f0a996c};
const u32 var7f1acc0c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f097a50
/*  f097a50:	3c013f80 */ 	lui	$at,0x3f80
/*  f097a54:	44819000 */ 	mtc1	$at,$f18
/*  f097a58:	44808000 */ 	mtc1	$zero,$f16
/*  f097a5c:	46009386 */ 	mov.s	$f14,$f18
/*  f097a60:	46109032 */ 	c.eq.s	$f18,$f16
/*  f097a64:	46008006 */ 	mov.s	$f0,$f16
/*  f097a68:	46008086 */ 	mov.s	$f2,$f16
/*  f097a6c:	45010009 */ 	bc1t	.L0f097a94
/*  f097a70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097a74:	46120000 */ 	add.s	$f0,$f0,$f18
.L0f097a78:
/*  f097a78:	460e1080 */ 	add.s	$f2,$f2,$f14
/*  f097a7c:	46006103 */ 	div.s	$f4,$f12,$f0
/*  f097a80:	46047382 */ 	mul.s	$f14,$f14,$f4
/*  f097a84:	46107032 */ 	c.eq.s	$f14,$f16
/*  f097a88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097a8c:	4502fffa */ 	bc1fl	.L0f097a78
/*  f097a90:	46120000 */ 	add.s	$f0,$f0,$f18
.L0f097a94:
/*  f097a94:	03e00008 */ 	jr	$ra
/*  f097a98:	46001006 */ 	mov.s	$f0,$f2
/*  f097a9c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f097aa0
/*  f097aa0:	3c013f80 */ 	lui	$at,0x3f80
/*  f097aa4:	44819000 */ 	mtc1	$at,$f18
/*  f097aa8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f097aac:	f7b80018 */ 	sdc1	$f24,0x18($sp)
/*  f097ab0:	46126101 */ 	sub.s	$f4,$f12,$f18
/*  f097ab4:	f7b60010 */ 	sdc1	$f22,0x10($sp)
/*  f097ab8:	3c014000 */ 	lui	$at,0x4000
/*  f097abc:	46126180 */ 	add.s	$f6,$f12,$f18
/*  f097ac0:	44808000 */ 	mtc1	$zero,$f16
/*  f097ac4:	4481b000 */ 	mtc1	$at,$f22
/*  f097ac8:	4480c000 */ 	mtc1	$zero,$f24
/*  f097acc:	46062003 */ 	div.s	$f0,$f4,$f6
/*  f097ad0:	f7b40008 */ 	sdc1	$f20,0x8($sp)
/*  f097ad4:	46000382 */ 	mul.s	$f14,$f0,$f0
/*  f097ad8:	46000086 */ 	mov.s	$f2,$f0
/*  f097adc:	46120503 */ 	div.s	$f20,$f0,$f18
.L0f097ae0:
/*  f097ae0:	460e1082 */ 	mul.s	$f2,$f2,$f14
/*  f097ae4:	46169480 */ 	add.s	$f18,$f18,$f22
/*  f097ae8:	4618a032 */ 	c.eq.s	$f20,$f24
/*  f097aec:	46148400 */ 	add.s	$f16,$f16,$f20
/*  f097af0:	4502fffb */ 	bc1fl	.L0f097ae0
/*  f097af4:	46120503 */ 	div.s	$f20,$f0,$f18
/*  f097af8:	d7b40008 */ 	ldc1	$f20,0x8($sp)
/*  f097afc:	d7b60010 */ 	ldc1	$f22,0x10($sp)
/*  f097b00:	d7b80018 */ 	ldc1	$f24,0x18($sp)
/*  f097b04:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f097b08:	03e00008 */ 	jr	$ra
/*  f097b0c:	46108000 */ 	add.s	$f0,$f16,$f16
/*  f097b10:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f097b14:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f097b18:	0fc25ea8 */ 	jal	func0f097aa0
/*  f097b1c:	e7ae001c */ 	swc1	$f14,0x1c($sp)
/*  f097b20:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*  f097b24:	46040302 */ 	mul.s	$f12,$f0,$f4
/*  f097b28:	0fc25e94 */ 	jal	func0f097a50
/*  f097b2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097b30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f097b34:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f097b38:	03e00008 */ 	jr	$ra
/*  f097b3c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f097b40
/*  f097b40:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f097b44:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f097b48:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f097b4c:	e4c80000 */ 	swc1	$f8,0x0($a2)
/*  f097b50:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f097b54:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f097b58:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f097b5c:	03e00008 */ 	jr	$ra
/*  f097b60:	e4d20004 */ 	swc1	$f18,0x4($a2)
);

GLOBAL_ASM(
glabel func0f097b64
/*  f097b64:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f097b68:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f097b6c:	44866000 */ 	mtc1	$a2,$f12
/*  f097b70:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f097b74:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f097b78:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f097b7c:	e4ea0000 */ 	swc1	$f10,0x0($a3)
/*  f097b80:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f097b84:	c4820004 */ 	lwc1	$f2,0x4($a0)
/*  f097b88:	46028481 */ 	sub.s	$f18,$f16,$f2
/*  f097b8c:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*  f097b90:	46041180 */ 	add.s	$f6,$f2,$f4
/*  f097b94:	03e00008 */ 	jr	$ra
/*  f097b98:	e4e60004 */ 	swc1	$f6,0x4($a3)
/*  f097b9c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f097ba0
/*  f097ba0:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f097ba4:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f097ba8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f097bac:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f097bb0:	3c04800a */ 	lui	$a0,0x800a
/*  f097bb4:	afa00030 */ 	sw	$zero,0x30($sp)
/*  f097bb8:	8084a24f */ 	lb	$a0,-0x5db1($a0)
/*  f097bbc:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*  f097bc0:	0c0054b4 */ 	jal	func000152d0
/*  f097bc4:	27a60028 */ 	addiu	$a2,$sp,0x28
/*  f097bc8:	3c0e800a */ 	lui	$t6,0x800a
/*  f097bcc:	8dcea248 */ 	lw	$t6,-0x5db8($t6)
/*  f097bd0:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f097bd4:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f097bd8:	28410004 */ 	slti	$at,$v0,0x4
/*  f097bdc:	1420003f */ 	bnez	$at,.L0f097cdc
/*  f097be0:	8faf002c */ 	lw	$t7,0x2c($sp)
/*  f097be4:	05e0003d */ 	bltz	$t7,.L0f097cdc
/*  f097be8:	8fb80028 */ 	lw	$t8,0x28($sp)
/*  f097bec:	0702003c */ 	bltzl	$t8,.L0f097ce0
/*  f097bf0:	8fac002c */ 	lw	$t4,0x2c($sp)
/*  f097bf4:	0fc45a45 */ 	jal	func0f116914
/*  f097bf8:	83a4002f */ 	lb	$a0,0x2f($sp)
/*  f097bfc:	38590001 */ 	xori	$t9,$v0,0x1
/*  f097c00:	2f390001 */ 	sltiu	$t9,$t9,0x1
/*  f097c04:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f097c08:	0fc45a45 */ 	jal	func0f116914
/*  f097c0c:	83a4002b */ 	lb	$a0,0x2b($sp)
/*  f097c10:	38430001 */ 	xori	$v1,$v0,0x1
/*  f097c14:	2c630001 */ 	sltiu	$v1,$v1,0x1
/*  f097c18:	afa30020 */ 	sw	$v1,0x20($sp)
/*  f097c1c:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f097c20:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f097c24:	24051000 */ 	addiu	$a1,$zero,0x1000
/*  f097c28:	14400003 */ 	bnez	$v0,.L0f097c38
/*  f097c2c:	8fa30020 */ 	lw	$v1,0x20($sp)
/*  f097c30:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f097c34:	afa80030 */ 	sw	$t0,0x30($sp)
.L0f097c38:
/*  f097c38:	8fa90024 */ 	lw	$t1,0x24($sp)
/*  f097c3c:	3c053e4c */ 	lui	$a1,0x3e4c
/*  f097c40:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f097c44:	1120001e */ 	beqz	$t1,.L0f097cc0
/*  f097c48:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f097c4c:	1060001c */ 	beqz	$v1,.L0f097cc0
/*  f097c50:	8faa0030 */ 	lw	$t2,0x30($sp)
/*  f097c54:	1140000f */ 	beqz	$t2,.L0f097c94
/*  f097c58:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f097c5c:	3c053e4c */ 	lui	$a1,0x3e4c
/*  f097c60:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f097c64:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f097c68:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f097c6c:	0fc47701 */ 	jal	func0f11dc04
/*  f097c70:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f097c74:	3c053e4c */ 	lui	$a1,0x3e4c
/*  f097c78:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f097c7c:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f097c80:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f097c84:	0fc47701 */ 	jal	func0f11dc04
/*  f097c88:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f097c8c:	1000001c */ 	beqz	$zero,.L0f097d00
/*  f097c90:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f097c94:
/*  f097c94:	24010001 */ 	addiu	$at,$zero,0x1
/*  f097c98:	15610002 */ 	bne	$t3,$at,.L0f097ca4
/*  f097c9c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f097ca0:	8fa40028 */ 	lw	$a0,0x28($sp)
.L0f097ca4:
/*  f097ca4:	3c053e4c */ 	lui	$a1,0x3e4c
/*  f097ca8:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f097cac:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f097cb0:	0fc47701 */ 	jal	func0f11dc04
/*  f097cb4:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f097cb8:	10000011 */ 	beqz	$zero,.L0f097d00
/*  f097cbc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f097cc0:
/*  f097cc0:	10600002 */ 	beqz	$v1,.L0f097ccc
/*  f097cc4:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f097cc8:	8fa40028 */ 	lw	$a0,0x28($sp)
.L0f097ccc:
/*  f097ccc:	0fc47701 */ 	jal	func0f11dc04
/*  f097cd0:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f097cd4:	1000000a */ 	beqz	$zero,.L0f097d00
/*  f097cd8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f097cdc:
/*  f097cdc:	8fac002c */ 	lw	$t4,0x2c($sp)
.L0f097ce0:
/*  f097ce0:	3c053e4c */ 	lui	$a1,0x3e4c
/*  f097ce4:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f097ce8:	05800004 */ 	bltz	$t4,.L0f097cfc
/*  f097cec:	01802025 */ 	or	$a0,$t4,$zero
/*  f097cf0:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f097cf4:	0fc47701 */ 	jal	func0f11dc04
/*  f097cf8:	24070004 */ 	addiu	$a3,$zero,0x4
.L0f097cfc:
/*  f097cfc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f097d00:
/*  f097d00:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f097d04:	03e00008 */ 	jr	$ra
/*  f097d08:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f097d0c
/*  f097d0c:	2401001b */ 	addiu	$at,$zero,0x1b
/*  f097d10:	54810004 */ 	bnel	$a0,$at,.L0f097d24
/*  f097d14:	24010013 */ 	addiu	$at,$zero,0x13
/*  f097d18:	03e00008 */ 	jr	$ra
/*  f097d1c:	00001025 */ 	or	$v0,$zero,$zero
/*  f097d20:	24010013 */ 	addiu	$at,$zero,0x13
.L0f097d24:
/*  f097d24:	54810004 */ 	bnel	$a0,$at,.L0f097d38
/*  f097d28:	24010008 */ 	addiu	$at,$zero,0x8
/*  f097d2c:	03e00008 */ 	jr	$ra
/*  f097d30:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f097d34:	24010008 */ 	addiu	$at,$zero,0x8
.L0f097d38:
/*  f097d38:	54810004 */ 	bnel	$a0,$at,.L0f097d4c
/*  f097d3c:	24010009 */ 	addiu	$at,$zero,0x9
/*  f097d40:	03e00008 */ 	jr	$ra
/*  f097d44:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f097d48:	24010009 */ 	addiu	$at,$zero,0x9
.L0f097d4c:
/*  f097d4c:	14810003 */ 	bne	$a0,$at,.L0f097d5c
/*  f097d50:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f097d54:	03e00008 */ 	jr	$ra
/*  f097d58:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f097d5c:
/*  f097d5c:	03e00008 */ 	jr	$ra
/*  f097d60:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f097d64
/*  f097d64:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f097d68:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f097d6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f097d70:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f097d74:	240a0004 */ 	addiu	$t2,$zero,0x4
/*  f097d78:	00001825 */ 	or	$v1,$zero,$zero
.L0f097d7c:
/*  f097d7c:	00002825 */ 	or	$a1,$zero,$zero
.L0f097d80:
/*  f097d80:	00027900 */ 	sll	$t7,$v0,0x4
/*  f097d84:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f097d88:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f097d8c:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f097d90:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f097d94:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f097d98:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f097d9c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f097da0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f097da4:	03053021 */ 	addu	$a2,$t8,$a1
/*  f097da8:	94c40d74 */ 	lhu	$a0,0xd74($a2)
/*  f097dac:	8d270038 */ 	lw	$a3,0x38($t1)
/*  f097db0:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f097db4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f097db8:	00e4082a */ 	slt	$at,$a3,$a0
/*  f097dbc:	10200004 */ 	beqz	$at,.L0f097dd0
/*  f097dc0:	00872023 */ 	subu	$a0,$a0,$a3
/*  f097dc4:	3099ffff */ 	andi	$t9,$a0,0xffff
/*  f097dc8:	10000002 */ 	beqz	$zero,.L0f097dd4
/*  f097dcc:	03202025 */ 	or	$a0,$t9,$zero
.L0f097dd0:
/*  f097dd0:	00002025 */ 	or	$a0,$zero,$zero
.L0f097dd4:
/*  f097dd4:	146affea */ 	bne	$v1,$t2,.L0f097d80
/*  f097dd8:	a4c40d74 */ 	sh	$a0,0xd74($a2)
/*  f097ddc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f097de0:	544bffe6 */ 	bnel	$v0,$t3,.L0f097d7c
/*  f097de4:	00001825 */ 	or	$v1,$zero,$zero
/*  f097de8:	03e00008 */ 	jr	$ra
/*  f097dec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f097df0
/*  f097df0:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f097df4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f097df8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f097dfc:	10410008 */ 	beq	$v0,$at,.L0f097e20
/*  f097e00:	24010005 */ 	addiu	$at,$zero,0x5
/*  f097e04:	1041000e */ 	beq	$v0,$at,.L0f097e40
/*  f097e08:	3c08800a */ 	lui	$t0,0x800a
/*  f097e0c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f097e10:	10410011 */ 	beq	$v0,$at,.L0f097e58
/*  f097e14:	3c0a800a */ 	lui	$t2,0x800a
/*  f097e18:	03e00008 */ 	jr	$ra
/*  f097e1c:	00601025 */ 	or	$v0,$v1,$zero
.L0f097e20:
/*  f097e20:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f097e24:	948f0002 */ 	lhu	$t7,0x2($a0)
/*  f097e28:	01eec007 */ 	srav	$t8,$t6,$t7
/*  f097e2c:	33190001 */ 	andi	$t9,$t8,0x1
/*  f097e30:	1720000e */ 	bnez	$t9,.L0f097e6c
/*  f097e34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097e38:	03e00008 */ 	jr	$ra
/*  f097e3c:	00001025 */ 	or	$v0,$zero,$zero
.L0f097e40:
/*  f097e40:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f097e44:	25090ddc */ 	addiu	$t1,$t0,0xddc
/*  f097e48:	10a90008 */ 	beq	$a1,$t1,.L0f097e6c
/*  f097e4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097e50:	03e00008 */ 	jr	$ra
/*  f097e54:	00001025 */ 	or	$v0,$zero,$zero
.L0f097e58:
/*  f097e58:	8d4aa244 */ 	lw	$t2,-0x5dbc($t2)
/*  f097e5c:	254b0638 */ 	addiu	$t3,$t2,0x638
/*  f097e60:	10ab0002 */ 	beq	$a1,$t3,.L0f097e6c
/*  f097e64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097e68:	00001825 */ 	or	$v1,$zero,$zero
.L0f097e6c:
/*  f097e6c:	03e00008 */ 	jr	$ra
/*  f097e70:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f097e74
/*  f097e74:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f097e78:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f097e7c:	87ae001a */ 	lh	$t6,0x1a($sp)
/*  f097e80:	24010035 */ 	addiu	$at,$zero,0x35
/*  f097e84:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f097e88:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f097e8c:	11c10004 */ 	beq	$t6,$at,.L0f097ea0
/*  f097e90:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f097e94:	24010036 */ 	addiu	$at,$zero,0x36
/*  f097e98:	15c10013 */ 	bne	$t6,$at,.L0f097ee8
/*  f097e9c:	00e02025 */ 	or	$a0,$a3,$zero
.L0f097ea0:
/*  f097ea0:	3c0f800a */ 	lui	$t7,0x800a
/*  f097ea4:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f097ea8:	8de41594 */ 	lw	$a0,0x1594($t7)
/*  f097eac:	5080001b */ 	beqzl	$a0,.L0f097f1c
/*  f097eb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f097eb4:	0c006a47 */ 	jal	func0001a91c
/*  f097eb8:	87a5001a */ 	lh	$a1,0x1a($sp)
/*  f097ebc:	50400017 */ 	beqzl	$v0,.L0f097f1c
/*  f097ec0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f097ec4:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f097ec8:	8fb80020 */ 	lw	$t8,0x20($sp)
/*  f097ecc:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*  f097ed0:	94790004 */ 	lhu	$t9,0x4($v1)
/*  f097ed4:	00194080 */ 	sll	$t0,$t9,0x2
/*  f097ed8:	03082021 */ 	addu	$a0,$t8,$t0
/*  f097edc:	248404b4 */ 	addiu	$a0,$a0,0x4b4
/*  f097ee0:	1000000d */ 	beqz	$zero,.L0f097f18
/*  f097ee4:	ac890000 */ 	sw	$t1,0x0($a0)
.L0f097ee8:
/*  f097ee8:	0c006a47 */ 	jal	func0001a91c
/*  f097eec:	87a5001a */ 	lh	$a1,0x1a($sp)
/*  f097ef0:	5040000a */ 	beqzl	$v0,.L0f097f1c
/*  f097ef4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f097ef8:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f097efc:	8faa0020 */ 	lw	$t2,0x20($sp)
/*  f097f00:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f097f04:	946b0004 */ 	lhu	$t3,0x4($v1)
/*  f097f08:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f097f0c:	014c2021 */ 	addu	$a0,$t2,$t4
/*  f097f10:	24840434 */ 	addiu	$a0,$a0,0x434
/*  f097f14:	ac8d0000 */ 	sw	$t5,0x0($a0)
.L0f097f18:
/*  f097f18:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f097f1c:
/*  f097f1c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f097f20:	03e00008 */ 	jr	$ra
/*  f097f24:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f097f28
/*  f097f28:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f097f2c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f097f30:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f097f34:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f097f38:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f097f3c:	00808825 */ 	or	$s1,$a0,$zero
/*  f097f40:	00a09025 */ 	or	$s2,$a1,$zero
/*  f097f44:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f097f48:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f097f4c:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f097f50:	00c08025 */ 	or	$s0,$a2,$zero
/*  f097f54:	10c0002d */ 	beqz	$a2,.L0f09800c
/*  f097f58:	00009825 */ 	or	$s3,$zero,$zero
/*  f097f5c:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f097f60:	24140003 */ 	addiu	$s4,$zero,0x3
/*  f097f64:	02002025 */ 	or	$a0,$s0,$zero
.L0f097f68:
/*  f097f68:	0fc25f7c */ 	jal	func0f097df0
/*  f097f6c:	02202825 */ 	or	$a1,$s1,$zero
/*  f097f70:	50400019 */ 	beqzl	$v0,.L0f097fd8
/*  f097f74:	920e0004 */ 	lbu	$t6,0x4($s0)
/*  f097f78:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f097f7c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f097f80:	02203025 */ 	or	$a2,$s1,$zero
/*  f097f84:	14400004 */ 	bnez	$v0,.L0f097f98
/*  f097f88:	02403825 */ 	or	$a3,$s2,$zero
/*  f097f8c:	0fc25f9d */ 	jal	func0f097e74
/*  f097f90:	86040006 */ 	lh	$a0,0x6($s0)
/*  f097f94:	92020004 */ 	lbu	$v0,0x4($s0)
.L0f097f98:
/*  f097f98:	16a20006 */ 	bne	$s5,$v0,.L0f097fb4
/*  f097f9c:	00002825 */ 	or	$a1,$zero,$zero
/*  f097fa0:	86040006 */ 	lh	$a0,0x6($s0)
/*  f097fa4:	02203025 */ 	or	$a2,$s1,$zero
/*  f097fa8:	0fc25f9d */ 	jal	func0f097e74
/*  f097fac:	02403825 */ 	or	$a3,$s2,$zero
/*  f097fb0:	92020004 */ 	lbu	$v0,0x4($s0)
.L0f097fb4:
/*  f097fb4:	1682000e */ 	bne	$s4,$v0,.L0f097ff0
/*  f097fb8:	02a02825 */ 	or	$a1,$s5,$zero
/*  f097fbc:	86040006 */ 	lh	$a0,0x6($s0)
/*  f097fc0:	02203025 */ 	or	$a2,$s1,$zero
/*  f097fc4:	0fc25f9d */ 	jal	func0f097e74
/*  f097fc8:	02403825 */ 	or	$a3,$s2,$zero
/*  f097fcc:	10000009 */ 	beqz	$zero,.L0f097ff4
/*  f097fd0:	920f000a */ 	lbu	$t7,0xa($s0)
/*  f097fd4:	920e0004 */ 	lbu	$t6,0x4($s0)
.L0f097fd8:
/*  f097fd8:	00002825 */ 	or	$a1,$zero,$zero
/*  f097fdc:	02203025 */ 	or	$a2,$s1,$zero
/*  f097fe0:	168e0003 */ 	bne	$s4,$t6,.L0f097ff0
/*  f097fe4:	02403825 */ 	or	$a3,$s2,$zero
/*  f097fe8:	0fc25f9d */ 	jal	func0f097e74
/*  f097fec:	86040006 */ 	lh	$a0,0x6($s0)
.L0f097ff0:
/*  f097ff0:	920f000a */ 	lbu	$t7,0xa($s0)
.L0f097ff4:
/*  f097ff4:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f097ff8:	15e00002 */ 	bnez	$t7,.L0f098004
/*  f097ffc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098000:	02a09825 */ 	or	$s3,$s5,$zero
.L0f098004:
/*  f098004:	5260ffd8 */ 	beqzl	$s3,.L0f097f68
/*  f098008:	02002025 */ 	or	$a0,$s0,$zero
.L0f09800c:
/*  f09800c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f098010:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f098014:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f098018:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f09801c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f098020:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f098024:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f098028:	03e00008 */ 	jr	$ra
/*  f09802c:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f098030
/*  f098030:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f098034:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f098038:	00809025 */ 	or	$s2,$a0,$zero
/*  f09803c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f098040:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f098044:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f098048:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f09804c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f098050:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f098054:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f098058:	00a09825 */ 	or	$s3,$a1,$zero
/*  f09805c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f098060:	90840000 */ 	lbu	$a0,0x0($a0)
/*  f098064:	00408025 */ 	or	$s0,$v0,$zero
/*  f098068:	02402025 */ 	or	$a0,$s2,$zero
/*  f09806c:	02602825 */ 	or	$a1,$s3,$zero
/*  f098070:	0fc25fca */ 	jal	func0f097f28
/*  f098074:	8c46003c */ 	lw	$a2,0x3c($v0)
/*  f098078:	24040042 */ 	addiu	$a0,$zero,0x42
/*  f09807c:	00002825 */ 	or	$a1,$zero,$zero
/*  f098080:	02403025 */ 	or	$a2,$s2,$zero
/*  f098084:	0fc25f9d */ 	jal	func0f097e74
/*  f098088:	02603825 */ 	or	$a3,$s3,$zero
/*  f09808c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f098090:	0200a825 */ 	or	$s5,$s0,$zero
/*  f098094:	24160008 */ 	addiu	$s6,$zero,0x8
.L0f098098:
/*  f098098:	8ea2001c */ 	lw	$v0,0x1c($s5)
/*  f09809c:	50400023 */ 	beqzl	$v0,.L0f09812c
/*  f0980a0:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f0980a4:	904e0010 */ 	lbu	$t6,0x10($v0)
/*  f0980a8:	02548821 */ 	addu	$s1,$s2,$s4
/*  f0980ac:	31cf0008 */ 	andi	$t7,$t6,0x8
/*  f0980b0:	51e0001e */ 	beqzl	$t7,.L0f09812c
/*  f0980b4:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f0980b8:	8e380228 */ 	lw	$t8,0x228($s1)
/*  f0980bc:	00008025 */ 	or	$s0,$zero,$zero
/*  f0980c0:	5b00001a */ 	blezl	$t8,.L0f09812c
/*  f0980c4:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f0980c8:	8e390220 */ 	lw	$t9,0x220($s1)
.L0f0980cc:
/*  f0980cc:	26040064 */ 	addiu	$a0,$s0,0x64
/*  f0980d0:	00045400 */ 	sll	$t2,$a0,0x10
/*  f0980d4:	0219082a */ 	slt	$at,$s0,$t9
/*  f0980d8:	1420000a */ 	bnez	$at,.L0f098104
/*  f0980dc:	000a2403 */ 	sra	$a0,$t2,0x10
/*  f0980e0:	26040064 */ 	addiu	$a0,$s0,0x64
/*  f0980e4:	00044400 */ 	sll	$t0,$a0,0x10
/*  f0980e8:	00082403 */ 	sra	$a0,$t0,0x10
/*  f0980ec:	00002825 */ 	or	$a1,$zero,$zero
/*  f0980f0:	02403025 */ 	or	$a2,$s2,$zero
/*  f0980f4:	0fc25f9d */ 	jal	func0f097e74
/*  f0980f8:	02603825 */ 	or	$a3,$s3,$zero
/*  f0980fc:	10000006 */ 	beqz	$zero,.L0f098118
/*  f098100:	8e2c0228 */ 	lw	$t4,0x228($s1)
.L0f098104:
/*  f098104:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f098108:	02403025 */ 	or	$a2,$s2,$zero
/*  f09810c:	0fc25f9d */ 	jal	func0f097e74
/*  f098110:	02603825 */ 	or	$a3,$s3,$zero
/*  f098114:	8e2c0228 */ 	lw	$t4,0x228($s1)
.L0f098118:
/*  f098118:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f09811c:	020c082a */ 	slt	$at,$s0,$t4
/*  f098120:	5420ffea */ 	bnezl	$at,.L0f0980cc
/*  f098124:	8e390220 */ 	lw	$t9,0x220($s1)
/*  f098128:	26940004 */ 	addiu	$s4,$s4,0x4
.L0f09812c:
/*  f09812c:	1696ffda */ 	bne	$s4,$s6,.L0f098098
/*  f098130:	26b50004 */ 	addiu	$s5,$s5,0x4
/*  f098134:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f098138:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f09813c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f098140:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f098144:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f098148:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f09814c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f098150:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f098154:	03e00008 */ 	jr	$ra
/*  f098158:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f09815c
/*  f09815c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f098160:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f098164:	8c8e068c */ 	lw	$t6,0x68c($a0)
/*  f098168:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09816c:	00802825 */ 	or	$a1,$a0,$zero
/*  f098170:	55c10018 */ 	bnel	$t6,$at,.L0f0981d4
/*  f098174:	44800000 */ 	mtc1	$zero,$f0
/*  f098178:	8c8206b0 */ 	lw	$v0,0x6b0($a0)
/*  f09817c:	50400015 */ 	beqzl	$v0,.L0f0981d4
/*  f098180:	44800000 */ 	mtc1	$zero,$f0
/*  f098184:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f098188:	24840384 */ 	addiu	$a0,$a0,0x384
/*  f09818c:	05e1000c */ 	bgez	$t7,.L0f0981c0
/*  f098190:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098194:	0c007486 */ 	jal	func0001d218
/*  f098198:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f09819c:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0981a0:	0c00745f */ 	jal	func0001d17c
/*  f0981a4:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0981a8:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f0981ac:	44982000 */ 	mtc1	$t8,$f4
/*  f0981b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0981b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0981b8:	10000007 */ 	beqz	$zero,.L0f0981d8
/*  f0981bc:	46003001 */ 	sub.s	$f0,$f6,$f0
.L0f0981c0:
/*  f0981c0:	0c00745f */ 	jal	func0001d17c
/*  f0981c4:	24a40384 */ 	addiu	$a0,$a1,0x384
/*  f0981c8:	10000004 */ 	beqz	$zero,.L0f0981dc
/*  f0981cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0981d0:	44800000 */ 	mtc1	$zero,$f0
.L0f0981d4:
/*  f0981d4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0981d8:
/*  f0981d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0981dc:
/*  f0981dc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0981e0:	03e00008 */ 	jr	$ra
/*  f0981e4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0981e8
/*  f0981e8:	27bdfea8 */ 	addiu	$sp,$sp,-344
/*  f0981ec:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0981f0:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f0981f4:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f0981f8:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f0981fc:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f098200:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f098204:	afa5015c */ 	sw	$a1,0x15c($sp)
/*  f098208:	908e0690 */ 	lbu	$t6,0x690($a0)
/*  f09820c:	8c98068c */ 	lw	$t8,0x68c($a0)
/*  f098210:	24010002 */ 	addiu	$at,$zero,0x2
/*  f098214:	31cfffe3 */ 	andi	$t7,$t6,0xffe3
/*  f098218:	00809825 */ 	or	$s3,$a0,$zero
/*  f09821c:	1701000f */ 	bne	$t8,$at,.L0f09825c
/*  f098220:	a08f0690 */ 	sb	$t7,0x690($a0)
/*  f098224:	0fc26057 */ 	jal	func0f09815c
/*  f098228:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09822c:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*  f098230:	0c007486 */ 	jal	func0001d218
/*  f098234:	26640384 */ 	addiu	$a0,$s3,0x384
/*  f098238:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f09823c:	44993000 */ 	mtc1	$t9,$f6
/*  f098240:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f098244:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f098248:	4604403e */ 	c.le.s	$f8,$f4
/*  f09824c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098250:	45020003 */ 	bc1fl	.L0f098260
/*  f098254:	8e680680 */ 	lw	$t0,0x680($s3)
/*  f098258:	ae60068c */ 	sw	$zero,0x68c($s3)
.L0f09825c:
/*  f09825c:	8e680680 */ 	lw	$t0,0x680($s3)
.L0f098260:
/*  f098260:	8e6a068c */ 	lw	$t2,0x68c($s3)
/*  f098264:	266d0384 */ 	addiu	$t5,$s3,0x384
/*  f098268:	29020000 */ 	slti	$v0,$t0,0x0
/*  f09826c:	394b0002 */ 	xori	$t3,$t2,0x2
/*  f098270:	2d6b0001 */ 	sltiu	$t3,$t3,0x1
/*  f098274:	38420001 */ 	xori	$v0,$v0,0x1
/*  f098278:	01626025 */ 	or	$t4,$t3,$v0
/*  f09827c:	5180017a */ 	beqzl	$t4,.L0f098868
/*  f098280:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f098284:	afad0058 */ 	sw	$t5,0x58($sp)
/*  f098288:	44806000 */ 	mtc1	$zero,$f12
/*  f09828c:	c66a06d0 */ 	lwc1	$f10,0x6d0($s3)
/*  f098290:	460a603c */ 	c.lt.s	$f12,$f10
/*  f098294:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098298:	45000005 */ 	bc1f	.L0f0982b0
/*  f09829c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0982a0:	8e680680 */ 	lw	$t0,0x680($s3)
/*  f0982a4:	ae600684 */ 	sw	$zero,0x684($s3)
/*  f0982a8:	29020000 */ 	slti	$v0,$t0,0x0
/*  f0982ac:	38420001 */ 	xori	$v0,$v0,0x1
.L0f0982b0:
/*  f0982b0:	5040004f */ 	beqzl	$v0,.L0f0983f0
/*  f0982b4:	8e6f0690 */ 	lw	$t7,0x690($s3)
/*  f0982b8:	8e6306b0 */ 	lw	$v1,0x6b0($s3)
/*  f0982bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0982c0:	926f06d6 */ 	lbu	$t7,0x6d6($s3)
/*  f0982c4:	8c6e0004 */ 	lw	$t6,0x4($v1)
/*  f0982c8:	44810000 */ 	mtc1	$at,$f0
/*  f0982cc:	3c017f1b */ 	lui	$at,%hi(var7f1ac1a8)
/*  f0982d0:	448e8000 */ 	mtc1	$t6,$f16
/*  f0982d4:	c426c1a8 */ 	lwc1	$f6,%lo(var7f1ac1a8)($at)
/*  f0982d8:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f0982dc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0982e0:	3c19800a */ 	lui	$t9,0x800a
/*  f0982e4:	1300001b */ 	beqz	$t8,.L0f098354
/*  f0982e8:	46069083 */ 	div.s	$f2,$f18,$f6
/*  f0982ec:	8f39a244 */ 	lw	$t9,-0x5dbc($t9)
/*  f0982f0:	832a0de4 */ 	lb	$t2,0xde4($t9)
/*  f0982f4:	11400017 */ 	beqz	$t2,.L0f098354
/*  f0982f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0982fc:	0c004b70 */ 	jal	random
/*  f098300:	e7a20148 */ 	swc1	$f2,0x148($sp)
/*  f098304:	44822000 */ 	mtc1	$v0,$f4
/*  f098308:	44806000 */ 	mtc1	$zero,$f12
/*  f09830c:	c7a20148 */ 	lwc1	$f2,0x148($sp)
/*  f098310:	04410005 */ 	bgez	$v0,.L0f098328
/*  f098314:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f098318:	3c014f80 */ 	lui	$at,0x4f80
/*  f09831c:	44815000 */ 	mtc1	$at,$f10
/*  f098320:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098324:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f098328:
/*  f098328:	3c012f80 */ 	lui	$at,0x2f80
/*  f09832c:	44818000 */ 	mtc1	$at,$f16
/*  f098330:	3c017f1b */ 	lui	$at,%hi(var7f1ac1ac)
/*  f098334:	c426c1ac */ 	lwc1	$f6,%lo(var7f1ac1ac)($at)
/*  f098338:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f09833c:	3c017f1b */ 	lui	$at,%hi(var7f1ac1b0)
/*  f098340:	c42ac1b0 */ 	lwc1	$f10,%lo(var7f1ac1b0)($at)
/*  f098344:	8e680680 */ 	lw	$t0,0x680($s3)
/*  f098348:	8e6306b0 */ 	lw	$v1,0x6b0($s3)
/*  f09834c:	46069102 */ 	mul.s	$f4,$f18,$f6
/*  f098350:	460a2000 */ 	add.s	$f0,$f4,$f10
.L0f098354:
/*  f098354:	10600018 */ 	beqz	$v1,.L0f0983b8
/*  f098358:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f09835c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f098360:	00082c00 */ 	sll	$a1,$t0,0x10
/*  f098364:	00055c03 */ 	sra	$t3,$a1,0x10
/*  f098368:	45000013 */ 	bc1f	.L0f0983b8
/*  f09836c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098370:	46020202 */ 	mul.s	$f8,$f0,$f2
/*  f098374:	44076000 */ 	mfc1	$a3,$f12
/*  f098378:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f09837c:	01602825 */ 	or	$a1,$t3,$zero
/*  f098380:	00003025 */ 	or	$a2,$zero,$zero
/*  f098384:	e7ac0014 */ 	swc1	$f12,0x14($sp)
/*  f098388:	0c007733 */ 	jal	func0001dccc
/*  f09838c:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f098390:	0c007486 */ 	jal	func0001d218
/*  f098394:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f098398:	44828000 */ 	mtc1	$v0,$f16
/*  f09839c:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f0983a0:	46808420 */ 	cvt.s.w	$f16,$f16
/*  f0983a4:	44058000 */ 	mfc1	$a1,$f16
/*  f0983a8:	0c007806 */ 	jal	func0001e018
/*  f0983ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0983b0:	1000000b */ 	beqz	$zero,.L0f0983e0
/*  f0983b4:	240dffff */ 	addiu	$t5,$zero,-1
.L0f0983b8:
/*  f0983b8:	46020482 */ 	mul.s	$f18,$f0,$f2
/*  f0983bc:	00082c00 */ 	sll	$a1,$t0,0x10
/*  f0983c0:	00056403 */ 	sra	$t4,$a1,0x10
/*  f0983c4:	44076000 */ 	mfc1	$a3,$f12
/*  f0983c8:	01802825 */ 	or	$a1,$t4,$zero
/*  f0983cc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0983d0:	e7ac0014 */ 	swc1	$f12,0x14($sp)
/*  f0983d4:	0c007733 */ 	jal	func0001dccc
/*  f0983d8:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0983dc:	240dffff */ 	addiu	$t5,$zero,-1
.L0f0983e0:
/*  f0983e0:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0983e4:	ae6d0680 */ 	sw	$t5,0x680($s3)
/*  f0983e8:	ae6e068c */ 	sw	$t6,0x68c($s3)
/*  f0983ec:	8e6f0690 */ 	lw	$t7,0x690($s3)
.L0f0983f0:
/*  f0983f0:	000fc840 */ 	sll	$t9,$t7,0x1
/*  f0983f4:	07210002 */ 	bgez	$t9,.L0f098400
/*  f0983f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0983fc:	ae600684 */ 	sw	$zero,0x684($s3)
.L0f098400:
/*  f098400:	0fc26057 */ 	jal	func0f09815c
/*  f098404:	02602025 */ 	or	$a0,$s3,$zero
/*  f098408:	4600018d */ 	trunc.w.s	$f6,$f0
/*  f09840c:	8e6b0684 */ 	lw	$t3,0x684($s3)
/*  f098410:	00004825 */ 	or	$t1,$zero,$zero
/*  f098414:	44023000 */ 	mfc1	$v0,$f6
/*  f098418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09841c:	0040a025 */ 	or	$s4,$v0,$zero
/*  f098420:	14400004 */ 	bnez	$v0,.L0f098434
/*  f098424:	01629021 */ 	addu	$s2,$t3,$v0
/*  f098428:	5a400003 */ 	blezl	$s2,.L0f098438
/*  f09842c:	8e6306b0 */ 	lw	$v1,0x6b0($s3)
/*  f098430:	2454ffff */ 	addiu	$s4,$v0,-1
.L0f098434:
/*  f098434:	8e6306b0 */ 	lw	$v1,0x6b0($s3)
.L0f098438:
/*  f098438:	506000a9 */ 	beqzl	$v1,.L0f0986e0
/*  f09843c:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f098440:	106000a6 */ 	beqz	$v1,.L0f0986dc
/*  f098444:	00608825 */ 	or	$s1,$v1,$zero
/*  f098448:	00008025 */ 	or	$s0,$zero,$zero
/*  f09844c:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f098450:
/*  f098450:	92230000 */ 	lbu	$v1,0x0($s1)
/*  f098454:	14600003 */ 	bnez	$v1,.L0f098464
/*  f098458:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09845c:	10000088 */ 	beqz	$zero,.L0f098680
/*  f098460:	01004825 */ 	or	$t1,$t0,$zero
.L0f098464:
/*  f098464:	11030003 */ 	beq	$t0,$v1,.L0f098474
/*  f098468:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09846c:	5461002f */ 	bnel	$v1,$at,.L0f09852c
/*  f098470:	24010003 */ 	addiu	$at,$zero,0x3
.L0f098474:
/*  f098474:	96270002 */ 	lhu	$a3,0x2($s1)
/*  f098478:	00001025 */ 	or	$v0,$zero,$zero
/*  f09847c:	27b8008c */ 	addiu	$t8,$sp,0x8c
/*  f098480:	0247082a */ 	slt	$at,$s2,$a3
/*  f098484:	1420007e */ 	bnez	$at,.L0f098680
/*  f098488:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09848c:	1a00000a */ 	blez	$s0,.L0f0984b8
/*  f098490:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f098494:	8e260004 */ 	lw	$a2,0x4($s1)
/*  f098498:	27a30104 */ 	addiu	$v1,$sp,0x104
.L0f09849c:
/*  f09849c:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0984a0:	54cc0003 */ 	bnel	$a2,$t4,.L0f0984b0
/*  f0984a4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0984a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0984ac:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f0984b0:
/*  f0984b0:	1450fffa */ 	bne	$v0,$s0,.L0f09849c
/*  f0984b4:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f0984b8:
/*  f0984b8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0984bc:	1481000a */ 	bne	$a0,$at,.L0f0984e8
/*  f0984c0:	240effff */ 	addiu	$t6,$zero,-1
/*  f0984c4:	8e260004 */ 	lw	$a2,0x4($s1)
/*  f0984c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0984cc:	00041080 */ 	sll	$v0,$a0,0x2
/*  f0984d0:	03a26821 */ 	addu	$t5,$sp,$v0
/*  f0984d4:	03a27821 */ 	addu	$t7,$sp,$v0
/*  f0984d8:	ada60104 */ 	sw	$a2,0x104($t5)
/*  f0984dc:	adee008c */ 	sw	$t6,0x8c($t7)
/*  f0984e0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0984e4:	96270002 */ 	lhu	$a3,0x2($s1)
.L0f0984e8:
/*  f0984e8:	00041080 */ 	sll	$v0,$a0,0x2
/*  f0984ec:	00581821 */ 	addu	$v1,$v0,$t8
/*  f0984f0:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0984f4:	0327082a */ 	slt	$at,$t9,$a3
/*  f0984f8:	10200061 */ 	beqz	$at,.L0f098680
/*  f0984fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098500:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f098504:	922a0000 */ 	lbu	$t2,0x0($s1)
/*  f098508:	03a26021 */ 	addu	$t4,$sp,$v0
/*  f09850c:	03a25821 */ 	addu	$t3,$sp,$v0
/*  f098510:	150a0003 */ 	bne	$t0,$t2,.L0f098520
/*  f098514:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098518:	10000059 */ 	beqz	$zero,.L0f098680
/*  f09851c:	ad6800c8 */ 	sw	$t0,0xc8($t3)
.L0f098520:
/*  f098520:	10000057 */ 	beqz	$zero,.L0f098680
/*  f098524:	ad8000c8 */ 	sw	$zero,0xc8($t4)
/*  f098528:	24010003 */ 	addiu	$at,$zero,0x3
.L0f09852c:
/*  f09852c:	10610006 */ 	beq	$v1,$at,.L0f098548
/*  f098530:	00601025 */ 	or	$v0,$v1,$zero
/*  f098534:	24010008 */ 	addiu	$at,$zero,0x8
/*  f098538:	50610025 */ 	beql	$v1,$at,.L0f0985d0
/*  f09853c:	8e6b0690 */ 	lw	$t3,0x690($s3)
/*  f098540:	1000004f */ 	beqz	$zero,.L0f098680
/*  f098544:	00000000 */ 	sll	$zero,$zero,0x0
.L0f098548:
/*  f098548:	8e6d0690 */ 	lw	$t5,0x690($s3)
/*  f09854c:	000d77c2 */ 	srl	$t6,$t5,0x1f
/*  f098550:	11c0004b */ 	beqz	$t6,.L0f098680
/*  f098554:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098558:	96270002 */ 	lhu	$a3,0x2($s1)
/*  f09855c:	0247082a */ 	slt	$at,$s2,$a3
/*  f098560:	14200047 */ 	bnez	$at,.L0f098680
/*  f098564:	0287082a */ 	slt	$at,$s4,$a3
/*  f098568:	10200045 */ 	beqz	$at,.L0f098680
/*  f09856c:	0292082a */ 	slt	$at,$s4,$s2
/*  f098570:	10200043 */ 	beqz	$at,.L0f098680
/*  f098574:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098578:	02602025 */ 	or	$a0,$s3,$zero
/*  f09857c:	0fc26057 */ 	jal	func0f09815c
/*  f098580:	afa90144 */ 	sw	$t1,0x144($sp)
/*  f098584:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f098588:	962f0002 */ 	lhu	$t7,0x2($s1)
/*  f09858c:	8e630684 */ 	lw	$v1,0x684($s3)
/*  f098590:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f098594:	44192000 */ 	mfc1	$t9,$f4
/*  f098598:	8fa90144 */ 	lw	$t1,0x144($sp)
/*  f09859c:	01f91023 */ 	subu	$v0,$t7,$t9
/*  f0985a0:	04410003 */ 	bgez	$v0,.L0f0985b0
/*  f0985a4:	00025043 */ 	sra	$t2,$v0,0x1
/*  f0985a8:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0985ac:	00015043 */ 	sra	$t2,$at,0x1
.L0f0985b0:
/*  f0985b0:	0143082a */ 	slt	$at,$t2,$v1
/*  f0985b4:	10200003 */ 	beqz	$at,.L0f0985c4
/*  f0985b8:	01401025 */ 	or	$v0,$t2,$zero
/*  f0985bc:	ae620684 */ 	sw	$v0,0x684($s3)
/*  f0985c0:	00401825 */ 	or	$v1,$v0,$zero
.L0f0985c4:
/*  f0985c4:	1000002e */ 	beqz	$zero,.L0f098680
/*  f0985c8:	00749021 */ 	addu	$s2,$v1,$s4
/*  f0985cc:	8e6b0690 */ 	lw	$t3,0x690($s3)
.L0f0985d0:
/*  f0985d0:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0985d4:	000c6fc2 */ 	srl	$t5,$t4,0x1f
/*  f0985d8:	11a00029 */ 	beqz	$t5,.L0f098680
/*  f0985dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0985e0:	96270002 */ 	lhu	$a3,0x2($s1)
/*  f0985e4:	0247082a */ 	slt	$at,$s2,$a3
/*  f0985e8:	14200025 */ 	bnez	$at,.L0f098680
/*  f0985ec:	0287082a */ 	slt	$at,$s4,$a3
/*  f0985f0:	10200023 */ 	beqz	$at,.L0f098680
/*  f0985f4:	0292082a */ 	slt	$at,$s4,$s2
/*  f0985f8:	10200021 */ 	beqz	$at,.L0f098680
/*  f0985fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098600:	8e260004 */ 	lw	$a2,0x4($s1)
/*  f098604:	02477023 */ 	subu	$t6,$s2,$a3
/*  f098608:	ae600684 */ 	sw	$zero,0x684($s3)
/*  f09860c:	00e6c023 */ 	subu	$t8,$a3,$a2
/*  f098610:	270f0001 */ 	addiu	$t7,$t8,0x1
/*  f098614:	01cf001a */ 	div	$zero,$t6,$t7
/*  f098618:	0000c810 */ 	mfhi	$t9
/*  f09861c:	00d91021 */ 	addu	$v0,$a2,$t9
/*  f098620:	44825000 */ 	mtc1	$v0,$f10
/*  f098624:	15e00002 */ 	bnez	$t7,.L0f098630
/*  f098628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09862c:	0007000d */ 	break	0x7
.L0f098630:
/*  f098630:	2401ffff */ 	addiu	$at,$zero,-1
/*  f098634:	15e10004 */ 	bne	$t7,$at,.L0f098648
/*  f098638:	3c018000 */ 	lui	$at,0x8000
/*  f09863c:	15c10002 */ 	bne	$t6,$at,.L0f098648
/*  f098640:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098644:	0006000d */ 	break	0x6
.L0f098648:
/*  f098648:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f09864c:	0040a025 */ 	or	$s4,$v0,$zero
/*  f098650:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f098654:	afa90144 */ 	sw	$t1,0x144($sp)
/*  f098658:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f09865c:	44055000 */ 	mfc1	$a1,$f10
/*  f098660:	0c007806 */ 	jal	func0001e018
/*  f098664:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098668:	926a0691 */ 	lbu	$t2,0x691($s3)
/*  f09866c:	8fb20078 */ 	lw	$s2,0x78($sp)
/*  f098670:	8fa90144 */ 	lw	$t1,0x144($sp)
/*  f098674:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f098678:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f09867c:	a26b0691 */ 	sb	$t3,0x691($s3)
.L0f098680:
/*  f098680:	1120ff73 */ 	beqz	$t1,.L0f098450
/*  f098684:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f098688:	5a000015 */ 	blezl	$s0,.L0f0986e0
/*  f09868c:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f098690:	1a000012 */ 	blez	$s0,.L0f0986dc
/*  f098694:	00001025 */ 	or	$v0,$zero,$zero
/*  f098698:	27a30104 */ 	addiu	$v1,$sp,0x104
/*  f09869c:	27a800c8 */ 	addiu	$t0,$sp,0xc8
.L0f0986a0:
/*  f0986a0:	84640002 */ 	lh	$a0,0x2($v1)
/*  f0986a4:	8d050000 */ 	lw	$a1,0x0($t0)
/*  f0986a8:	afa80050 */ 	sw	$t0,0x50($sp)
/*  f0986ac:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f0986b0:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0986b4:	02603025 */ 	or	$a2,$s3,$zero
/*  f0986b8:	0fc25f9d */ 	jal	func0f097e74
/*  f0986bc:	8fa7015c */ 	lw	$a3,0x15c($sp)
/*  f0986c0:	8fa20074 */ 	lw	$v0,0x74($sp)
/*  f0986c4:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0986c8:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f0986cc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0986d0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0986d4:	1450fff2 */ 	bne	$v0,$s0,.L0f0986a0
/*  f0986d8:	25080004 */ 	addiu	$t0,$t0,0x4
.L0f0986dc:
/*  f0986dc:	8fa40058 */ 	lw	$a0,0x58($sp)
.L0f0986e0:
/*  f0986e0:	8e650684 */ 	lw	$a1,0x684($s3)
/*  f0986e4:	0c007cc5 */ 	jal	func0001f314
/*  f0986e8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0986ec:	0fc26057 */ 	jal	func0f09815c
/*  f0986f0:	02602025 */ 	or	$a0,$s3,$zero
/*  f0986f4:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f0986f8:	8e6306b0 */ 	lw	$v1,0x6b0($s3)
/*  f0986fc:	00004025 */ 	or	$t0,$zero,$zero
/*  f098700:	3c013f80 */ 	lui	$at,0x3f80
/*  f098704:	44124000 */ 	mfc1	$s2,$f8
/*  f098708:	10600056 */ 	beqz	$v1,.L0f098864
/*  f09870c:	00608025 */ 	or	$s0,$v1,$zero
/*  f098710:	44818000 */ 	mtc1	$at,$f16
/*  f098714:	00008825 */ 	or	$s1,$zero,$zero
/*  f098718:	10600052 */ 	beqz	$v1,.L0f098864
/*  f09871c:	e7b00068 */ 	swc1	$f16,0x68($sp)
.L0f098720:
/*  f098720:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f098724:	54600004 */ 	bnezl	$v1,.L0f098738
/*  f098728:	96020002 */ 	lhu	$v0,0x2($s0)
/*  f09872c:	1000004b */ 	beqz	$zero,.L0f09885c
/*  f098730:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f098734:	96020002 */ 	lhu	$v0,0x2($s0)
.L0f098738:
/*  f098738:	0242082a */ 	slt	$at,$s2,$v0
/*  f09873c:	14200047 */ 	bnez	$at,.L0f09885c
/*  f098740:	0282082a */ 	slt	$at,$s4,$v0
/*  f098744:	10200045 */ 	beqz	$at,.L0f09885c
/*  f098748:	0292082a */ 	slt	$at,$s4,$s2
/*  f09874c:	10200043 */ 	beqz	$at,.L0f09885c
/*  f098750:	24010005 */ 	addiu	$at,$zero,0x5
/*  f098754:	10610007 */ 	beq	$v1,$at,.L0f098774
/*  f098758:	24010009 */ 	addiu	$at,$zero,0x9
/*  f09875c:	10610035 */ 	beq	$v1,$at,.L0f098834
/*  f098760:	2401000b */ 	addiu	$at,$zero,0xb
/*  f098764:	5061002b */ 	beql	$v1,$at,.L0f098814
/*  f098768:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f09876c:	1000003b */ 	beqz	$zero,.L0f09885c
/*  f098770:	00000000 */ 	sll	$zero,$zero,0x0
.L0f098774:
/*  f098774:	12200014 */ 	beqz	$s1,.L0f0987c8
/*  f098778:	00002025 */ 	or	$a0,$zero,$zero
/*  f09877c:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f098780:	c7b20068 */ 	lwc1	$f18,0x68($sp)
/*  f098784:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f098788:	240effff */ 	addiu	$t6,$zero,-1
/*  f09878c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f098790:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f098794:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f098798:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f09879c:	afa80070 */ 	sw	$t0,0x70($sp)
/*  f0987a0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0987a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0987a8:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f0987ac:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f0987b0:	00008825 */ 	or	$s1,$zero,$zero
/*  f0987b4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0987b8:	0c0041c6 */ 	jal	func00010718
/*  f0987bc:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0987c0:	10000026 */ 	beqz	$zero,.L0f09885c
/*  f0987c4:	8fa80070 */ 	lw	$t0,0x70($sp)
.L0f0987c8:
/*  f0987c8:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0987cc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0987d0:	44813000 */ 	mtc1	$at,$f6
/*  f0987d4:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0987d8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0987dc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0987e0:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0987e4:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0987e8:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0987ec:	afa80070 */ 	sw	$t0,0x70($sp)
/*  f0987f0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0987f4:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f0987f8:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f0987fc:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f098800:	0c0041c6 */ 	jal	func00010718
/*  f098804:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f098808:	10000014 */ 	beqz	$zero,.L0f09885c
/*  f09880c:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f098810:	8e0d0004 */ 	lw	$t5,0x4($s0)
.L0f098814:
/*  f098814:	3c01447a */ 	lui	$at,0x447a
/*  f098818:	44814000 */ 	mtc1	$at,$f8
/*  f09881c:	448d2000 */ 	mtc1	$t5,$f4
/*  f098820:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f098824:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f098828:	46085403 */ 	div.s	$f16,$f10,$f8
/*  f09882c:	1000000b */ 	beqz	$zero,.L0f09885c
/*  f098830:	e7b00068 */ 	swc1	$f16,0x68($sp)
.L0f098834:
/*  f098834:	8e780690 */ 	lw	$t8,0x690($s3)
/*  f098838:	926c0690 */ 	lbu	$t4,0x690($s3)
/*  f09883c:	001870c0 */ 	sll	$t6,$t8,0x3
/*  f098840:	000e7f42 */ 	srl	$t7,$t6,0x1d
/*  f098844:	25f90001 */ 	addiu	$t9,$t7,0x1
/*  f098848:	00195080 */ 	sll	$t2,$t9,0x2
/*  f09884c:	314b001c */ 	andi	$t3,$t2,0x1c
/*  f098850:	318dffe3 */ 	andi	$t5,$t4,0xffe3
/*  f098854:	016dc025 */ 	or	$t8,$t3,$t5
/*  f098858:	a2780690 */ 	sb	$t8,0x690($s3)
.L0f09885c:
/*  f09885c:	1100ffb0 */ 	beqz	$t0,.L0f098720
/*  f098860:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f098864:
/*  f098864:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f098868:
/*  f098868:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f09886c:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f098870:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f098874:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f098878:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f09887c:	03e00008 */ 	jr	$ra
/*  f098880:	27bd0158 */ 	addiu	$sp,$sp,0x158
);

GLOBAL_ASM(
glabel func0f098884
/*  f098884:	90820001 */ 	lbu	$v0,0x1($a0)
/*  f098888:	00001825 */ 	or	$v1,$zero,$zero
/*  f09888c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f098890:	14400003 */ 	bnez	$v0,.L0f0988a0
/*  f098894:	24010002 */ 	addiu	$at,$zero,0x2
/*  f098898:	03e00008 */ 	jr	$ra
/*  f09889c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0988a0:
/*  f0988a0:	14820006 */ 	bne	$a0,$v0,.L0f0988bc
/*  f0988a4:	3c0e800a */ 	lui	$t6,0x800a
/*  f0988a8:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0988ac:	81cf0de4 */ 	lb	$t7,0xde4($t6)
/*  f0988b0:	148f0002 */ 	bne	$a0,$t7,.L0f0988bc
/*  f0988b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0988b8:	00801825 */ 	or	$v1,$a0,$zero
.L0f0988bc:
/*  f0988bc:	54410006 */ 	bnel	$v0,$at,.L0f0988d8
/*  f0988c0:	00601025 */ 	or	$v0,$v1,$zero
/*  f0988c4:	90b80003 */ 	lbu	$t8,0x3($a1)
/*  f0988c8:	54980003 */ 	bnel	$a0,$t8,.L0f0988d8
/*  f0988cc:	00601025 */ 	or	$v0,$v1,$zero
/*  f0988d0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0988d4:	00601025 */ 	or	$v0,$v1,$zero
.L0f0988d8:
/*  f0988d8:	03e00008 */ 	jr	$ra
/*  f0988dc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0988e0
/*  f0988e0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0988e4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0988e8:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0988ec:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0988f0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0988f4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0988f8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0988fc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f098900:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f098904:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f098908:	2401000a */ 	addiu	$at,$zero,0xa
/*  f09890c:	00c08825 */ 	or	$s1,$a2,$zero
/*  f098910:	11c10032 */ 	beq	$t6,$at,.L0f0989dc
/*  f098914:	00a09825 */ 	or	$s3,$a1,$zero
/*  f098918:	00808025 */ 	or	$s0,$a0,$zero
/*  f09891c:	00009025 */ 	or	$s2,$zero,$zero
/*  f098920:	0c004b70 */ 	jal	random
/*  f098924:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f098928:	24010064 */ 	addiu	$at,$zero,0x64
/*  f09892c:	0041001b */ 	divu	$zero,$v0,$at
/*  f098930:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f098934:	0000b010 */ 	mfhi	$s6
/*  f098938:	24150007 */ 	addiu	$s5,$zero,0x7
/*  f09893c:	908f0000 */ 	lbu	$t7,0x0($a0)
/*  f098940:	24140006 */ 	addiu	$s4,$zero,0x6
/*  f098944:	11e00035 */ 	beqz	$t7,.L0f098a1c
/*  f098948:	02002025 */ 	or	$a0,$s0,$zero
.L0f09894c:
/*  f09894c:	0fc26221 */ 	jal	func0f098884
/*  f098950:	02202825 */ 	or	$a1,$s1,$zero
/*  f098954:	5040001c */ 	beqzl	$v0,.L0f0989c8
/*  f098958:	92080008 */ 	lbu	$t0,0x8($s0)
/*  f09895c:	5640001a */ 	bnezl	$s2,.L0f0989c8
/*  f098960:	92080008 */ 	lbu	$t0,0x8($s0)
/*  f098964:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f098968:	02602825 */ 	or	$a1,$s3,$zero
/*  f09896c:	02203025 */ 	or	$a2,$s1,$zero
/*  f098970:	16820006 */ 	bne	$s4,$v0,.L0f09898c
/*  f098974:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098978:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f09897c:	0fc26238 */ 	jal	func0f0988e0
/*  f098980:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f098984:	10000010 */ 	beqz	$zero,.L0f0989c8
/*  f098988:	92080008 */ 	lbu	$t0,0x8($s0)
.L0f09898c:
/*  f09898c:	56a2000e */ 	bnel	$s5,$v0,.L0f0989c8
/*  f098990:	92080008 */ 	lbu	$t0,0x8($s0)
/*  f098994:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f098998:	8e380748 */ 	lw	$t8,0x748($s1)
/*  f09899c:	5304000a */ 	beql	$t8,$a0,.L0f0989c8
/*  f0989a0:	92080008 */ 	lbu	$t0,0x8($s0)
/*  f0989a4:	96190002 */ 	lhu	$t9,0x2($s0)
/*  f0989a8:	02602825 */ 	or	$a1,$s3,$zero
/*  f0989ac:	02203025 */ 	or	$a2,$s1,$zero
/*  f0989b0:	02d9082b */ 	sltu	$at,$s6,$t9
/*  f0989b4:	50200004 */ 	beqzl	$at,.L0f0989c8
/*  f0989b8:	92080008 */ 	lbu	$t0,0x8($s0)
/*  f0989bc:	0fc26238 */ 	jal	func0f0988e0
/*  f0989c0:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0989c4:	92080008 */ 	lbu	$t0,0x8($s0)
.L0f0989c8:
/*  f0989c8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0989cc:	5500ffdf */ 	bnezl	$t0,.L0f09894c
/*  f0989d0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0989d4:	10000012 */ 	beqz	$zero,.L0f098a20
/*  f0989d8:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0989dc:
/*  f0989dc:	94890002 */ 	lhu	$t1,0x2($a0)
/*  f0989e0:	922a0690 */ 	lbu	$t2,0x690($s1)
/*  f0989e4:	923806d6 */ 	lbu	$t8,0x6d6($s1)
/*  f0989e8:	ae20068c */ 	sw	$zero,0x68c($s1)
/*  f0989ec:	314cff7f */ 	andi	$t4,$t2,0xff7f
/*  f0989f0:	318e00df */ 	andi	$t6,$t4,0xdf
/*  f0989f4:	a22c0690 */ 	sb	$t4,0x690($s1)
/*  f0989f8:	a22e0690 */ 	sb	$t6,0x690($s1)
/*  f0989fc:	31cf00bf */ 	andi	$t7,$t6,0xbf
/*  f098a00:	3319fffe */ 	andi	$t9,$t8,0xfffe
/*  f098a04:	ae2406b0 */ 	sw	$a0,0x6b0($s1)
/*  f098a08:	a2200691 */ 	sb	$zero,0x691($s1)
/*  f098a0c:	a22f0690 */ 	sb	$t7,0x690($s1)
/*  f098a10:	a23906d6 */ 	sb	$t9,0x6d6($s1)
/*  f098a14:	ae240748 */ 	sw	$a0,0x748($s1)
/*  f098a18:	ae290680 */ 	sw	$t1,0x680($s1)
.L0f098a1c:
/*  f098a1c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f098a20:
/*  f098a20:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f098a24:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f098a28:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f098a2c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f098a30:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f098a34:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f098a38:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f098a3c:	03e00008 */ 	jr	$ra
/*  f098a40:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f098a44
/*  f098a44:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f098a48:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f098a4c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f098a50:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f098a54:	8c8e068c */ 	lw	$t6,0x68c($a0)
/*  f098a58:	00a08025 */ 	or	$s0,$a1,$zero
/*  f098a5c:	00808825 */ 	or	$s1,$a0,$zero
/*  f098a60:	8c8206b0 */ 	lw	$v0,0x6b0($a0)
/*  f098a64:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f098a68:	15c00006 */ 	bnez	$t6,.L0f098a84
/*  f098a6c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f098a70:	8e2f0680 */ 	lw	$t7,0x680($s1)
/*  f098a74:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f098a78:	008f1026 */ 	xor	$v0,$a0,$t7
/*  f098a7c:	1000003b */ 	beqz	$zero,.L0f098b6c
/*  f098a80:	2c420001 */ 	sltiu	$v0,$v0,0x1
.L0f098a84:
/*  f098a84:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f098a88:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f098a8c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f098a90:	10600010 */ 	beqz	$v1,.L0f098ad4
/*  f098a94:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f098a98:
/*  f098a98:	14a30002 */ 	bne	$a1,$v1,.L0f098aa4
/*  f098a9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098aa0:	94480002 */ 	lhu	$t0,0x2($v0)
.L0f098aa4:
/*  f098aa4:	54e30006 */ 	bnel	$a3,$v1,.L0f098ac0
/*  f098aa8:	90430008 */ 	lbu	$v1,0x8($v0)
/*  f098aac:	8c580004 */ 	lw	$t8,0x4($v0)
/*  f098ab0:	56180003 */ 	bnel	$s0,$t8,.L0f098ac0
/*  f098ab4:	90430008 */ 	lbu	$v1,0x8($v0)
/*  f098ab8:	94460002 */ 	lhu	$a2,0x2($v0)
/*  f098abc:	90430008 */ 	lbu	$v1,0x8($v0)
.L0f098ac0:
/*  f098ac0:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f098ac4:	10600003 */ 	beqz	$v1,.L0f098ad4
/*  f098ac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098acc:	10c4fff2 */ 	beq	$a2,$a0,.L0f098a98
/*  f098ad0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f098ad4:
/*  f098ad4:	04c00025 */ 	bltz	$a2,.L0f098b6c
/*  f098ad8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f098adc:	8e390690 */ 	lw	$t9,0x690($s1)
/*  f098ae0:	02202025 */ 	or	$a0,$s1,$zero
/*  f098ae4:	00194fc2 */ 	srl	$t1,$t9,0x1f
/*  f098ae8:	5120000f */ 	beqzl	$t1,.L0f098b28
/*  f098aec:	02202025 */ 	or	$a0,$s1,$zero
/*  f098af0:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f098af4:	0fc26057 */ 	jal	func0f09815c
/*  f098af8:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f098afc:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f098b00:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f098b04:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f098b08:	440b2000 */ 	mfc1	$t3,$f4
/*  f098b0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098b10:	010b082a */ 	slt	$at,$t0,$t3
/*  f098b14:	54200004 */ 	bnezl	$at,.L0f098b28
/*  f098b18:	02202025 */ 	or	$a0,$s1,$zero
/*  f098b1c:	10000013 */ 	beqz	$zero,.L0f098b6c
/*  f098b20:	00001025 */ 	or	$v0,$zero,$zero
/*  f098b24:	02202025 */ 	or	$a0,$s1,$zero
.L0f098b28:
/*  f098b28:	0fc26057 */ 	jal	func0f09815c
/*  f098b2c:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f098b30:	8e2c0684 */ 	lw	$t4,0x684($s1)
/*  f098b34:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f098b38:	00001025 */ 	or	$v0,$zero,$zero
/*  f098b3c:	448c3000 */ 	mtc1	$t4,$f6
/*  f098b40:	44868000 */ 	mtc1	$a2,$f16
/*  f098b44:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f098b48:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f098b4c:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f098b50:	460a903e */ 	c.le.s	$f18,$f10
/*  f098b54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098b58:	45020005 */ 	bc1fl	.L0f098b70
/*  f098b5c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f098b60:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f098b64:	10000002 */ 	beqz	$zero,.L0f098b70
/*  f098b68:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f098b6c:
/*  f098b6c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f098b70:
/*  f098b70:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f098b74:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f098b78:	03e00008 */ 	jr	$ra
/*  f098b7c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f098b80:	8c8e068c */ 	lw	$t6,0x68c($a0)
/*  f098b84:	8c8206b0 */ 	lw	$v0,0x6b0($a0)
/*  f098b88:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f098b8c:	55c00004 */ 	bnezl	$t6,.L0f098ba0
/*  f098b90:	90440000 */ 	lbu	$a0,0x0($v0)
/*  f098b94:	03e00008 */ 	jr	$ra
/*  f098b98:	00001025 */ 	or	$v0,$zero,$zero
/*  f098b9c:	90440000 */ 	lbu	$a0,0x0($v0)
.L0f098ba0:
/*  f098ba0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f098ba4:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f098ba8:	5080000e */ 	beqzl	$a0,.L0f098be4
/*  f098bac:	2407ffff */ 	addiu	$a3,$zero,-1
.L0f098bb0:
/*  f098bb0:	54c40006 */ 	bnel	$a2,$a0,.L0f098bcc
/*  f098bb4:	90440008 */ 	lbu	$a0,0x8($v0)
/*  f098bb8:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f098bbc:	54af0003 */ 	bnel	$a1,$t7,.L0f098bcc
/*  f098bc0:	90440008 */ 	lbu	$a0,0x8($v0)
/*  f098bc4:	94430002 */ 	lhu	$v1,0x2($v0)
/*  f098bc8:	90440008 */ 	lbu	$a0,0x8($v0)
.L0f098bcc:
/*  f098bcc:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f098bd0:	50800004 */ 	beqzl	$a0,.L0f098be4
/*  f098bd4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f098bd8:	1067fff5 */ 	beq	$v1,$a3,.L0f098bb0
/*  f098bdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098be0:	2407ffff */ 	addiu	$a3,$zero,-1
.L0f098be4:
/*  f098be4:	54670003 */ 	bnel	$v1,$a3,.L0f098bf4
/*  f098be8:	00601025 */ 	or	$v0,$v1,$zero
/*  f098bec:	00001825 */ 	or	$v1,$zero,$zero
/*  f098bf0:	00601025 */ 	or	$v0,$v1,$zero
.L0f098bf4:
/*  f098bf4:	03e00008 */ 	jr	$ra
/*  f098bf8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f098bfc
/*  f098bfc:	8c82068c */ 	lw	$v0,0x68c($a0)
/*  f098c00:	0002702b */ 	sltu	$t6,$zero,$v0
/*  f098c04:	03e00008 */ 	jr	$ra
/*  f098c08:	01c01025 */ 	or	$v0,$t6,$zero
);

GLOBAL_ASM(
glabel func0f098c0c
/*  f098c0c:	908f0690 */ 	lbu	$t7,0x690($a0)
/*  f098c10:	908b06d6 */ 	lbu	$t3,0x6d6($a0)
/*  f098c14:	240effff */ 	addiu	$t6,$zero,-1
/*  f098c18:	31f9ff7f */ 	andi	$t9,$t7,0xff7f
/*  f098c1c:	332900df */ 	andi	$t1,$t9,0xdf
/*  f098c20:	a0990690 */ 	sb	$t9,0x690($a0)
/*  f098c24:	a0890690 */ 	sb	$t1,0x690($a0)
/*  f098c28:	312a00bf */ 	andi	$t2,$t1,0xbf
/*  f098c2c:	316cfffe */ 	andi	$t4,$t3,0xfffe
/*  f098c30:	ac8e0680 */ 	sw	$t6,0x680($a0)
/*  f098c34:	ac80068c */ 	sw	$zero,0x68c($a0)
/*  f098c38:	ac8006b0 */ 	sw	$zero,0x6b0($a0)
/*  f098c3c:	a0800691 */ 	sb	$zero,0x691($a0)
/*  f098c40:	a08a0690 */ 	sb	$t2,0x690($a0)
/*  f098c44:	03e00008 */ 	jr	$ra
/*  f098c48:	a08c06d6 */ 	sb	$t4,0x6d6($a0)
);

GLOBAL_ASM(
glabel func0f098c4c
/*  f098c4c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f098c50:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f098c54:	00803025 */ 	or	$a2,$a0,$zero
/*  f098c58:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f098c5c:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f098c60:	00a02025 */ 	or	$a0,$a1,$zero
/*  f098c64:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f098c68:	00027080 */ 	sll	$t6,$v0,0x2
/*  f098c6c:	3c0f8007 */ 	lui	$t7,0x8007
/*  f098c70:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f098c74:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f098c78:	8defff18 */ 	lw	$t7,-0xe8($t7)
/*  f098c7c:	3c18800a */ 	lui	$t8,0x800a
/*  f098c80:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f098c84:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f098c88:	27191580 */ 	addiu	$t9,$t8,0x1580
/*  f098c8c:	acd90008 */ 	sw	$t9,0x8($a2)
/*  f098c90:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f098c94:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f098c98:	03e00008 */ 	jr	$ra
/*  f098c9c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f098ca0
/*  f098ca0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f098ca4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f098ca8:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f098cac:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f098cb0:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f098cb4:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f098cb8:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f098cbc:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f098cc0:	0fc2c42e */ 	jal	func0f0b10b8
/*  f098cc4:	00c02025 */ 	or	$a0,$a2,$zero
/*  f098cc8:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f098ccc:	8fa90034 */ 	lw	$t1,0x34($sp)
/*  f098cd0:	14400003 */ 	bnez	$v0,.L0f098ce0
/*  f098cd4:	8faa0030 */ 	lw	$t2,0x30($sp)
/*  f098cd8:	10000043 */ 	beqz	$zero,.L0f098de8
/*  f098cdc:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f098ce0:
/*  f098ce0:	80440007 */ 	lb	$a0,0x7($v0)
/*  f098ce4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f098ce8:	5081003f */ 	beql	$a0,$at,.L0f098de8
/*  f098cec:	00601025 */ 	or	$v0,$v1,$zero
/*  f098cf0:	8d2e0008 */ 	lw	$t6,0x8($t1)
/*  f098cf4:	8fb80038 */ 	lw	$t8,0x38($sp)
/*  f098cf8:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f098cfc:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f098d00:	81e80064 */ 	lb	$t0,0x64($t7)
/*  f098d04:	00803025 */ 	or	$a2,$a0,$zero
/*  f098d08:	03193821 */ 	addu	$a3,$t8,$t9
/*  f098d0c:	05020036 */ 	bltzl	$t0,.L0f098de8
/*  f098d10:	00601025 */ 	or	$v0,$v1,$zero
/*  f098d14:	8ce40220 */ 	lw	$a0,0x220($a3)
/*  f098d18:	8ceb0228 */ 	lw	$t3,0x228($a3)
/*  f098d1c:	008b082a */ 	slt	$at,$a0,$t3
/*  f098d20:	50200031 */ 	beqzl	$at,.L0f098de8
/*  f098d24:	00601025 */ 	or	$v0,$v1,$zero
/*  f098d28:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f098d2c:	24010013 */ 	addiu	$at,$zero,0x13
/*  f098d30:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f098d34:	14410004 */ 	bne	$v0,$at,.L0f098d48
/*  f098d38:	24010001 */ 	addiu	$at,$zero,0x1
/*  f098d3c:	55410003 */ 	bnel	$t2,$at,.L0f098d4c
/*  f098d40:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f098d44:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f098d48:
/*  f098d48:	2401001c */ 	addiu	$at,$zero,0x1c
.L0f098d4c:
/*  f098d4c:	14410010 */ 	bne	$v0,$at,.L0f098d90
/*  f098d50:	24010001 */ 	addiu	$at,$zero,0x1
/*  f098d54:	5541000f */ 	bnel	$t2,$at,.L0f098d94
/*  f098d58:	0085082a */ 	slt	$at,$a0,$a1
/*  f098d5c:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f098d60:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f098d64:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f098d68:	0fc26d36 */ 	jal	func0f09b4d8
/*  f098d6c:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f098d70:	8fa90034 */ 	lw	$t1,0x34($sp)
/*  f098d74:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f098d78:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f098d7c:	8d2c0008 */ 	lw	$t4,0x8($t1)
/*  f098d80:	00402825 */ 	or	$a1,$v0,$zero
/*  f098d84:	8ce40220 */ 	lw	$a0,0x220($a3)
/*  f098d88:	01866821 */ 	addu	$t5,$t4,$a2
/*  f098d8c:	81a80064 */ 	lb	$t0,0x64($t5)
.L0f098d90:
/*  f098d90:	0085082a */ 	slt	$at,$a0,$a1
.L0f098d94:
/*  f098d94:	1020000b */ 	beqz	$at,.L0f098dc4
/*  f098d98:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f098d9c:	3c0e800a */ 	lui	$t6,0x800a
/*  f098da0:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f098da4:	00087880 */ 	sll	$t7,$t0,0x2
/*  f098da8:	00001825 */ 	or	$v1,$zero,$zero
/*  f098dac:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f098db0:	8f1917a8 */ 	lw	$t9,0x17a8($t8)
/*  f098db4:	5720000c */ 	bnezl	$t9,.L0f098de8
/*  f098db8:	00601025 */ 	or	$v0,$v1,$zero
/*  f098dbc:	10000009 */ 	beqz	$zero,.L0f098de4
/*  f098dc0:	2403ffff */ 	addiu	$v1,$zero,-1
.L0f098dc4:
/*  f098dc4:	3c0b800a */ 	lui	$t3,0x800a
/*  f098dc8:	8d6ba244 */ 	lw	$t3,-0x5dbc($t3)
/*  f098dcc:	00086080 */ 	sll	$t4,$t0,0x2
/*  f098dd0:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f098dd4:	8dae17a8 */ 	lw	$t6,0x17a8($t5)
/*  f098dd8:	55c00003 */ 	bnezl	$t6,.L0f098de8
/*  f098ddc:	00601025 */ 	or	$v0,$v1,$zero
/*  f098de0:	24030002 */ 	addiu	$v1,$zero,0x2
.L0f098de4:
/*  f098de4:	00601025 */ 	or	$v0,$v1,$zero
.L0f098de8:
/*  f098de8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f098dec:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f098df0:	03e00008 */ 	jr	$ra
/*  f098df4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f098df8
/*  f098df8:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f098dfc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f098e00:	00a08025 */ 	or	$s0,$a1,$zero
/*  f098e04:	00802825 */ 	or	$a1,$a0,$zero
/*  f098e08:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f098e0c:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f098e10:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f098e14:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f098e18:	0fc2c42e */ 	jal	func0f0b10b8
/*  f098e1c:	00c02025 */ 	or	$a0,$a2,$zero
/*  f098e20:	50400056 */ 	beqzl	$v0,.L0f098f7c
/*  f098e24:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f098e28:	80430007 */ 	lb	$v1,0x7($v0)
/*  f098e2c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f098e30:	50610052 */ 	beql	$v1,$at,.L0f098f7c
/*  f098e34:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f098e38:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*  f098e3c:	00602825 */ 	or	$a1,$v1,$zero
/*  f098e40:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f098e44:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f098e48:	81f80064 */ 	lb	$t8,0x64($t7)
/*  f098e4c:	0700004a */ 	bltz	$t8,.L0f098f78
/*  f098e50:	00033880 */ 	sll	$a3,$v1,0x2
/*  f098e54:	03273021 */ 	addu	$a2,$t9,$a3
/*  f098e58:	8cc90228 */ 	lw	$t1,0x228($a2)
/*  f098e5c:	8cca0220 */ 	lw	$t2,0x220($a2)
/*  f098e60:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f098e64:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f098e68:	012a1823 */ 	subu	$v1,$t1,$t2
/*  f098e6c:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f098e70:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f098e74:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f098e78:	0fc25f43 */ 	jal	func0f097d0c
/*  f098e7c:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f098e80:	3c0b8009 */ 	lui	$t3,0x8009
/*  f098e84:	916b8804 */ 	lbu	$t3,-0x77fc($t3)
/*  f098e88:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f098e8c:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f098e90:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f098e94:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f098e98:	11600002 */ 	beqz	$t3,.L0f098ea4
/*  f098e9c:	00402025 */ 	or	$a0,$v0,$zero
/*  f098ea0:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f098ea4:
/*  f098ea4:	93ac004b */ 	lbu	$t4,0x4b($sp)
/*  f098ea8:	93a90047 */ 	lbu	$t1,0x47($sp)
/*  f098eac:	11800008 */ 	beqz	$t4,.L0f098ed0
/*  f098eb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f098eb4:	04800006 */ 	bltz	$a0,.L0f098ed0
/*  f098eb8:	8fad0040 */ 	lw	$t5,0x40($sp)
/*  f098ebc:	00047040 */ 	sll	$t6,$a0,0x1
/*  f098ec0:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f098ec4:	95f8073c */ 	lhu	$t8,0x73c($t7)
/*  f098ec8:	0018ca03 */ 	sra	$t9,$t8,0x8
/*  f098ecc:	00791823 */ 	subu	$v1,$v1,$t9
.L0f098ed0:
/*  f098ed0:	51200003 */ 	beqzl	$t1,.L0f098ee0
/*  f098ed4:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f098ed8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f098edc:	8e0b0008 */ 	lw	$t3,0x8($s0)
.L0f098ee0:
/*  f098ee0:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f098ee4:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f098ee8:	01656021 */ 	addu	$t4,$t3,$a1
/*  f098eec:	818d0064 */ 	lb	$t5,0x64($t4)
/*  f098ef0:	8c8a0284 */ 	lw	$t2,0x284($a0)
/*  f098ef4:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f098ef8:	014e7821 */ 	addu	$t7,$t2,$t6
/*  f098efc:	8de217a8 */ 	lw	$v0,0x17a8($t7)
/*  f098f00:	0043082a */ 	slt	$at,$v0,$v1
/*  f098f04:	50200003 */ 	beqzl	$at,.L0f098f14
/*  f098f08:	8cd80220 */ 	lw	$t8,0x220($a2)
/*  f098f0c:	00401825 */ 	or	$v1,$v0,$zero
/*  f098f10:	8cd80220 */ 	lw	$t8,0x220($a2)
.L0f098f14:
/*  f098f14:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f098f18:	acd90220 */ 	sw	$t9,0x220($a2)
/*  f098f1c:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f098f20:	8c890284 */ 	lw	$t1,0x284($a0)
/*  f098f24:	01656021 */ 	addu	$t4,$t3,$a1
/*  f098f28:	818d0064 */ 	lb	$t5,0x64($t4)
/*  f098f2c:	000d5080 */ 	sll	$t2,$t5,0x2
/*  f098f30:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f098f34:	8c4e17a8 */ 	lw	$t6,0x17a8($v0)
/*  f098f38:	01c37823 */ 	subu	$t7,$t6,$v1
/*  f098f3c:	ac4f17a8 */ 	sw	$t7,0x17a8($v0)
/*  f098f40:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f098f44:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f098f48:	8f2b001c */ 	lw	$t3,0x1c($t9)
/*  f098f4c:	916c0010 */ 	lbu	$t4,0x10($t3)
/*  f098f50:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f098f54:	51a00009 */ 	beqzl	$t5,.L0f098f7c
/*  f098f58:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f098f5c:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f098f60:	8c890284 */ 	lw	$t1,0x284($a0)
/*  f098f64:	01457021 */ 	addu	$t6,$t2,$a1
/*  f098f68:	81cf0064 */ 	lb	$t7,0x64($t6)
/*  f098f6c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f098f70:	0138c821 */ 	addu	$t9,$t1,$t8
/*  f098f74:	af2017a8 */ 	sw	$zero,0x17a8($t9)
.L0f098f78:
/*  f098f78:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f098f7c:
/*  f098f7c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f098f80:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f098f84:	03e00008 */ 	jr	$ra
/*  f098f88:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f098f8c
/*  f098f8c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f098f90:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f098f94:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f098f98:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f098f9c:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f098fa0:	00a08825 */ 	or	$s1,$a1,$zero
/*  f098fa4:	00809825 */ 	or	$s3,$a0,$zero
/*  f098fa8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f098fac:	00008025 */ 	or	$s0,$zero,$zero
/*  f098fb0:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f098fb4:	02202025 */ 	or	$a0,$s1,$zero
.L0f098fb8:
/*  f098fb8:	0fc2c42e */ 	jal	func0f0b10b8
/*  f098fbc:	02002825 */ 	or	$a1,$s0,$zero
/*  f098fc0:	10400007 */ 	beqz	$v0,.L0f098fe0
/*  f098fc4:	02002025 */ 	or	$a0,$s0,$zero
/*  f098fc8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f098fcc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f098fd0:	02602825 */ 	or	$a1,$s3,$zero
/*  f098fd4:	02203025 */ 	or	$a2,$s1,$zero
/*  f098fd8:	0fc2637e */ 	jal	func0f098df8
/*  f098fdc:	00003825 */ 	or	$a3,$zero,$zero
.L0f098fe0:
/*  f098fe0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f098fe4:	5612fff4 */ 	bnel	$s0,$s2,.L0f098fb8
/*  f098fe8:	02202025 */ 	or	$a0,$s1,$zero
/*  f098fec:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f098ff0:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f098ff4:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f098ff8:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f098ffc:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f099000:	03e00008 */ 	jr	$ra
/*  f099004:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f099008
/*  f099008:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f09900c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f099010:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f099014:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f099018:	0fc26313 */ 	jal	func0f098c4c
/*  f09901c:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f099020:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f099024:	3c0f800a */ 	lui	$t7,0x800a
/*  f099028:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f09902c:	00037100 */ 	sll	$t6,$v1,0x4
/*  f099030:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f099034:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f099038:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f09903c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f099040:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f099044:	000e1880 */ 	sll	$v1,$t6,0x2
/*  f099048:	01e33021 */ 	addu	$a2,$t7,$v1
/*  f09904c:	24c60638 */ 	addiu	$a2,$a2,0x638
/*  f099050:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f099054:	00002025 */ 	or	$a0,$zero,$zero
/*  f099058:	0fc26328 */ 	jal	func0f098ca0
/*  f09905c:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*  f099060:	18400003 */ 	blez	$v0,.L0f099070
/*  f099064:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f099068:	1000000d */ 	beqz	$zero,.L0f0990a0
/*  f09906c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f099070:
/*  f099070:	3c18800a */ 	lui	$t8,0x800a
/*  f099074:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f099078:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f09907c:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*  f099080:	03033021 */ 	addu	$a2,$t8,$v1
/*  f099084:	0fc26328 */ 	jal	func0f098ca0
/*  f099088:	24c60638 */ 	addiu	$a2,$a2,0x638
/*  f09908c:	58400004 */ 	blezl	$v0,.L0f0990a0
/*  f099090:	00001025 */ 	or	$v0,$zero,$zero
/*  f099094:	10000002 */ 	beqz	$zero,.L0f0990a0
/*  f099098:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09909c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0990a0:
/*  f0990a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0990a4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0990a8:	03e00008 */ 	jr	$ra
/*  f0990ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0990b0
/*  f0990b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0990b4:	14800003 */ 	bnez	$a0,.L0f0990c4
/*  f0990b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0990bc:	1000002e */ 	beqz	$zero,.L0f099178
/*  f0990c0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0990c4:
/*  f0990c4:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0990c8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0990cc:	14400003 */ 	bnez	$v0,.L0f0990dc
/*  f0990d0:	304300ff */ 	andi	$v1,$v0,0xff
/*  f0990d4:	10000028 */ 	beqz	$zero,.L0f099178
/*  f0990d8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0990dc:
/*  f0990dc:	54610004 */ 	bnel	$v1,$at,.L0f0990f0
/*  f0990e0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0990e4:	10000024 */ 	beqz	$zero,.L0f099178
/*  f0990e8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0990ec:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0990f0:
/*  f0990f0:	5461000c */ 	bnel	$v1,$at,.L0f099124
/*  f0990f4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0990f8:	8c820014 */ 	lw	$v0,0x14($a0)
/*  f0990fc:	24010005 */ 	addiu	$at,$zero,0x5
/*  f099100:	10410007 */ 	beq	$v0,$at,.L0f099120
/*  f099104:	24010006 */ 	addiu	$at,$zero,0x6
/*  f099108:	10410005 */ 	beq	$v0,$at,.L0f099120
/*  f09910c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f099110:	50410004 */ 	beql	$v0,$at,.L0f099124
/*  f099114:	24010002 */ 	addiu	$at,$zero,0x2
/*  f099118:	10000017 */ 	beqz	$zero,.L0f099178
/*  f09911c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f099120:
/*  f099120:	24010002 */ 	addiu	$at,$zero,0x2
.L0f099124:
/*  f099124:	54610007 */ 	bnel	$v1,$at,.L0f099144
/*  f099128:	80820007 */ 	lb	$v0,0x7($a0)
/*  f09912c:	808e0007 */ 	lb	$t6,0x7($a0)
/*  f099130:	05c30004 */ 	bgezl	$t6,.L0f099144
/*  f099134:	80820007 */ 	lb	$v0,0x7($a0)
/*  f099138:	1000000f */ 	beqz	$zero,.L0f099178
/*  f09913c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f099140:	80820007 */ 	lb	$v0,0x7($a0)
.L0f099144:
/*  f099144:	0440000b */ 	bltz	$v0,.L0f099174
/*  f099148:	00027880 */ 	sll	$t7,$v0,0x2
/*  f09914c:	00afc021 */ 	addu	$t8,$a1,$t7
/*  f099150:	8f03001c */ 	lw	$v1,0x1c($t8)
/*  f099154:	50600008 */ 	beqzl	$v1,.L0f099178
/*  f099158:	00001025 */ 	or	$v0,$zero,$zero
/*  f09915c:	0fc2a61a */ 	jal	currentPlayerGetAmmoCount
/*  f099160:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f099164:	5c400004 */ 	bgtzl	$v0,.L0f099178
/*  f099168:	00001025 */ 	or	$v0,$zero,$zero
/*  f09916c:	10000002 */ 	beqz	$zero,.L0f099178
/*  f099170:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f099174:
/*  f099174:	00001025 */ 	or	$v0,$zero,$zero
.L0f099178:
/*  f099178:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09917c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f099180:	03e00008 */ 	jr	$ra
/*  f099184:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f099188
/*  f099188:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f09918c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f099190:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f099194:	0fc2c42e */ 	jal	func0f0b10b8
/*  f099198:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f09919c:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f0991a0:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0991a4:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0991a8:	91c40000 */ 	lbu	$a0,0x0($t6)
/*  f0991ac:	0fc2a31f */ 	jal	func0f0a8c7c
/*  f0991b0:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0991b4:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f0991b8:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0991bc:	144f0003 */ 	bne	$v0,$t7,.L0f0991cc
/*  f0991c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0991c4:	10000003 */ 	beqz	$zero,.L0f0991d4
/*  f0991c8:	00001025 */ 	or	$v0,$zero,$zero
.L0f0991cc:
/*  f0991cc:	0fc2642c */ 	jal	func0f0990b0
/*  f0991d0:	8fa50018 */ 	lw	$a1,0x18($sp)
.L0f0991d4:
/*  f0991d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0991d8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0991dc:	03e00008 */ 	jr	$ra
/*  f0991e0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0991e4
/*  f0991e4:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0991e8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0991ec:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0991f0:	00c08025 */ 	or	$s0,$a2,$zero
/*  f0991f4:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f0991f8:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0991fc:	0fc2a31f */ 	jal	func0f0a8c7c
/*  f099200:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f099204:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f099208:	8e0e0684 */ 	lw	$t6,0x684($s0)
/*  f09920c:	44802000 */ 	mtc1	$zero,$f4
/*  f099210:	a20005dc */ 	sb	$zero,0x5dc($s0)
/*  f099214:	ae000558 */ 	sw	$zero,0x558($s0)
/*  f099218:	ae0e0688 */ 	sw	$t6,0x688($s0)
/*  f09921c:	e60405fc */ 	swc1	$f4,0x5fc($s0)
/*  f099220:	0fc26f56 */ 	jal	func0f09bd58
/*  f099224:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f099228:	10400007 */ 	beqz	$v0,.L0f099248
/*  f09922c:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f099230:	0fc27346 */ 	jal	func0f09cd18
/*  f099234:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f099238:	50400004 */ 	beqzl	$v0,.L0f09924c
/*  f09923c:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f099240:	1000014a */ 	beqz	$zero,.L0f09976c
/*  f099244:	8fa2004c */ 	lw	$v0,0x4c($sp)
.L0f099248:
/*  f099248:	8faf0038 */ 	lw	$t7,0x38($sp)
.L0f09924c:
/*  f09924c:	92180003 */ 	lbu	$t8,0x3($s0)
/*  f099250:	02003025 */ 	or	$a2,$s0,$zero
/*  f099254:	55f80005 */ 	bnel	$t7,$t8,.L0f09926c
/*  f099258:	920a0690 */ 	lbu	$t2,0x690($s0)
/*  f09925c:	92190690 */ 	lbu	$t9,0x690($s0)
/*  f099260:	3329fffd */ 	andi	$t1,$t9,0xfffd
/*  f099264:	a2090690 */ 	sb	$t1,0x690($s0)
/*  f099268:	920a0690 */ 	lbu	$t2,0x690($s0)
.L0f09926c:
/*  f09926c:	820c0008 */ 	lb	$t4,0x8($s0)
/*  f099270:	314bfffe */ 	andi	$t3,$t2,0xfffe
/*  f099274:	11800106 */ 	beqz	$t4,.L0f099690
/*  f099278:	a20b0690 */ 	sb	$t3,0x690($s0)
/*  f09927c:	92040003 */ 	lbu	$a0,0x3($s0)
/*  f099280:	0fc26328 */ 	jal	func0f098ca0
/*  f099284:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f099288:	92030003 */ 	lbu	$v1,0x3($s0)
/*  f09928c:	8fad0038 */ 	lw	$t5,0x38($sp)
/*  f099290:	00404025 */ 	or	$t0,$v0,$zero
/*  f099294:	11a3003a */ 	beq	$t5,$v1,.L0f099380
/*  f099298:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09929c:	8e0e0024 */ 	lw	$t6,0x24($s0)
/*  f0992a0:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0992a4:	11c10036 */ 	beq	$t6,$at,.L0f099380
/*  f0992a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0992ac:	8e0f0690 */ 	lw	$t7,0x690($s0)
/*  f0992b0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0992b4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0992b8:	000fc980 */ 	sll	$t9,$t7,0x6
/*  f0992bc:	0721000a */ 	bgez	$t9,.L0f0992e8
/*  f0992c0:	01232023 */ 	subu	$a0,$t1,$v1
/*  f0992c4:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0992c8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0992cc:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f0992d0:	0fc26328 */ 	jal	func0f098ca0
/*  f0992d4:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f0992d8:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f0992dc:	04410002 */ 	bgez	$v0,.L0f0992e8
/*  f0992e0:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f0992e4:	00003825 */ 	or	$a3,$zero,$zero
.L0f0992e8:
/*  f0992e8:	10e00018 */ 	beqz	$a3,.L0f09934c
/*  f0992ec:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f0992f0:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f0992f4:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f0992f8:	15610014 */ 	bne	$t3,$at,.L0f09934c
/*  f0992fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099300:	1500000f */ 	bnez	$t0,.L0f099340
/*  f099304:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099308:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f09930c:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f099310:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f099314:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f099318:	a20c0003 */ 	sb	$t4,0x3($s0)
/*  f09931c:	afa80034 */ 	sw	$t0,0x34($sp)
/*  f099320:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f099324:	0fc27346 */ 	jal	func0f09cd18
/*  f099328:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f09932c:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f099330:	10400006 */ 	beqz	$v0,.L0f09934c
/*  f099334:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f099338:	1000010c */ 	beqz	$zero,.L0f09976c
/*  f09933c:	8fa2004c */ 	lw	$v0,0x4c($sp)
.L0f099340:
/*  f099340:	05010002 */ 	bgez	$t0,.L0f09934c
/*  f099344:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099348:	00003825 */ 	or	$a3,$zero,$zero
.L0f09934c:
/*  f09934c:	10e0000c */ 	beqz	$a3,.L0f099380
/*  f099350:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099354:	920d0690 */ 	lbu	$t5,0x690($s0)
/*  f099358:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f09935c:	31aefffd */ 	andi	$t6,$t5,0xfffd
/*  f099360:	a20e0690 */ 	sb	$t6,0x690($s0)
/*  f099364:	afa80034 */ 	sw	$t0,0x34($sp)
/*  f099368:	0fc27346 */ 	jal	func0f09cd18
/*  f09936c:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f099370:	10400003 */ 	beqz	$v0,.L0f099380
/*  f099374:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f099378:	100000fc */ 	beqz	$zero,.L0f09976c
/*  f09937c:	8fa2004c */ 	lw	$v0,0x4c($sp)
.L0f099380:
/*  f099380:	05010071 */ 	bgez	$t0,.L0f099548
/*  f099384:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f099388:	8de40000 */ 	lw	$a0,0x0($t7)
/*  f09938c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f099390:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f099394:	1040000f */ 	beqz	$v0,.L0f0993d4
/*  f099398:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f09939c:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f0993a0:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0993a4:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f0993a8:	17210004 */ 	bne	$t9,$at,.L0f0993bc
/*  f0993ac:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0993b0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0993b4:	11210007 */ 	beq	$t1,$at,.L0f0993d4
/*  f0993b8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0993bc:
/*  f0993bc:	0fc27346 */ 	jal	func0f09cd18
/*  f0993c0:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0993c4:	10400003 */ 	beqz	$v0,.L0f0993d4
/*  f0993c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0993cc:	100000e7 */ 	beqz	$zero,.L0f09976c
/*  f0993d0:	8fa2004c */ 	lw	$v0,0x4c($sp)
.L0f0993d4:
/*  f0993d4:	3c0a800a */ 	lui	$t2,0x800a
/*  f0993d8:	8d4aa244 */ 	lw	$t2,-0x5dbc($t2)
/*  f0993dc:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0993e0:	02003025 */ 	or	$a2,$s0,$zero
/*  f0993e4:	81441580 */ 	lb	$a0,0x1580($t2)
/*  f0993e8:	0004102a */ 	slt	$v0,$zero,$a0
/*  f0993ec:	50400016 */ 	beqzl	$v0,.L0f099448
/*  f0993f0:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f0993f4:	28820024 */ 	slti	$v0,$a0,0x24
/*  f0993f8:	10400012 */ 	beqz	$v0,.L0f099444
/*  f0993fc:	3c0b800a */ 	lui	$t3,0x800a
/*  f099400:	8d6ba248 */ 	lw	$t3,-0x5db8($t3)
/*  f099404:	2483ffff */ 	addiu	$v1,$a0,-1
/*  f099408:	000370c3 */ 	sra	$t6,$v1,0x3
/*  f09940c:	8d6c0070 */ 	lw	$t4,0x70($t3)
/*  f099410:	3c18800b */ 	lui	$t8,0x800b
/*  f099414:	30790007 */ 	andi	$t9,$v1,0x7
/*  f099418:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f09941c:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f099420:	000d6940 */ 	sll	$t5,$t5,0x5
/*  f099424:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f099428:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f09942c:	9318c84f */ 	lbu	$t8,-0x37b1($t8)
/*  f099430:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f099434:	03295004 */ 	sllv	$t2,$t1,$t9
/*  f099438:	030a1024 */ 	and	$v0,$t8,$t2
/*  f09943c:	0002582b */ 	sltu	$t3,$zero,$v0
/*  f099440:	01601025 */ 	or	$v0,$t3,$zero
.L0f099444:
/*  f099444:	8fac0038 */ 	lw	$t4,0x38($sp)
.L0f099448:
/*  f099448:	544c0092 */ 	bnel	$v0,$t4,.L0f099694
/*  f09944c:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f099450:	920d0003 */ 	lbu	$t5,0x3($s0)
/*  f099454:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f099458:	0fc26328 */ 	jal	func0f098ca0
/*  f09945c:	01cd2023 */ 	subu	$a0,$t6,$t5
/*  f099460:	920f0003 */ 	lbu	$t7,0x3($s0)
/*  f099464:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f099468:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f09946c:	02002025 */ 	or	$a0,$s0,$zero
/*  f099470:	0fc26462 */ 	jal	func0f099188
/*  f099474:	012f2823 */ 	subu	$a1,$t1,$t7
/*  f099478:	1040001a */ 	beqz	$v0,.L0f0994e4
/*  f09947c:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f099480:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f099484:	24010014 */ 	addiu	$at,$zero,0x14
/*  f099488:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f09948c:	13010015 */ 	beq	$t8,$at,.L0f0994e4
/*  f099490:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099494:	8f2a0008 */ 	lw	$t2,0x8($t9)
/*  f099498:	02002025 */ 	or	$a0,$s0,$zero
/*  f09949c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0994a0:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f0994a4:	000b7740 */ 	sll	$t6,$t3,0x1d
/*  f0994a8:	05c3000e */ 	bgezl	$t6,.L0f0994e4
/*  f0994ac:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0994b0:	920d0003 */ 	lbu	$t5,0x3($s0)
/*  f0994b4:	afa30030 */ 	sw	$v1,0x30($sp)
/*  f0994b8:	0fc2c42e */ 	jal	func0f0b10b8
/*  f0994bc:	012d2823 */ 	subu	$a1,$t1,$t5
/*  f0994c0:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0994c4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0994c8:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f0994cc:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0994d0:	13010004 */ 	beq	$t8,$at,.L0f0994e4
/*  f0994d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0994d8:	10000002 */ 	beqz	$zero,.L0f0994e4
/*  f0994dc:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0994e0:	2403ffff */ 	addiu	$v1,$zero,-1
.L0f0994e4:
/*  f0994e4:	04610005 */ 	bgez	$v1,.L0f0994fc
/*  f0994e8:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0994ec:	920a0690 */ 	lbu	$t2,0x690($s0)
/*  f0994f0:	354b0001 */ 	ori	$t3,$t2,0x1
/*  f0994f4:	10000066 */ 	beqz	$zero,.L0f099690
/*  f0994f8:	a20b0690 */ 	sb	$t3,0x690($s0)
.L0f0994fc:
/*  f0994fc:	8d840000 */ 	lw	$a0,0x0($t4)
/*  f099500:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f099504:	3c050400 */ 	lui	$a1,0x400
/*  f099508:	50400006 */ 	beqzl	$v0,.L0f099524
/*  f09950c:	920d0690 */ 	lbu	$t5,0x690($s0)
/*  f099510:	920e0003 */ 	lbu	$t6,0x3($s0)
/*  f099514:	24010001 */ 	addiu	$at,$zero,0x1
/*  f099518:	55c1005e */ 	bnel	$t6,$at,.L0f099694
/*  f09951c:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f099520:	920d0690 */ 	lbu	$t5,0x690($s0)
.L0f099524:
/*  f099524:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f099528:	35af0002 */ 	ori	$t7,$t5,0x2
/*  f09952c:	a20f0690 */ 	sb	$t7,0x690($s0)
/*  f099530:	0fc27346 */ 	jal	func0f09cd18
/*  f099534:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f099538:	50400056 */ 	beqzl	$v0,.L0f099694
/*  f09953c:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f099540:	1000008a */ 	beqz	$zero,.L0f09976c
/*  f099544:	8fa2004c */ 	lw	$v0,0x4c($sp)
.L0f099548:
/*  f099548:	5500001c */ 	bnezl	$t0,.L0f0995bc
/*  f09954c:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f099550:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f099554:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f099558:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f09955c:	5300000f */ 	beqzl	$t8,.L0f09959c
/*  f099560:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f099564:	8f2a0000 */ 	lw	$t2,0x0($t9)
/*  f099568:	5140000c */ 	beqzl	$t2,.L0f09959c
/*  f09956c:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f099570:	920b0690 */ 	lbu	$t3,0x690($s0)
/*  f099574:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f099578:	316cff7f */ 	andi	$t4,$t3,0xff7f
/*  f09957c:	a20c0690 */ 	sb	$t4,0x690($s0)
/*  f099580:	0fc27346 */ 	jal	func0f09cd18
/*  f099584:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f099588:	50400042 */ 	beqzl	$v0,.L0f099694
/*  f09958c:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f099590:	10000076 */ 	beqz	$zero,.L0f09976c
/*  f099594:	8fa2004c */ 	lw	$v0,0x4c($sp)
/*  f099598:	ae00001c */ 	sw	$zero,0x1c($s0)
.L0f09959c:
/*  f09959c:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f0995a0:	0fc27346 */ 	jal	func0f09cd18
/*  f0995a4:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0995a8:	5040003a */ 	beqzl	$v0,.L0f099694
/*  f0995ac:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0995b0:	1000006e */ 	beqz	$zero,.L0f09976c
/*  f0995b4:	8fa2004c */ 	lw	$v0,0x4c($sp)
/*  f0995b8:	8e0e000c */ 	lw	$t6,0xc($s0)
.L0f0995bc:
/*  f0995bc:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f0995c0:	55c0000a */ 	bnezl	$t6,.L0f0995ec
/*  f0995c4:	8f2a0000 */ 	lw	$t2,0x0($t9)
/*  f0995c8:	8e0906d4 */ 	lw	$t1,0x6d4($s0)
/*  f0995cc:	00097ec0 */ 	sll	$t7,$t1,0x1b
/*  f0995d0:	05e3001c */ 	bgezl	$t7,.L0f099644
/*  f0995d4:	8e020024 */ 	lw	$v0,0x24($s0)
/*  f0995d8:	92180003 */ 	lbu	$t8,0x3($s0)
/*  f0995dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0995e0:	57010018 */ 	bnel	$t8,$at,.L0f099644
/*  f0995e4:	8e020024 */ 	lw	$v0,0x24($s0)
/*  f0995e8:	8f2a0000 */ 	lw	$t2,0x0($t9)
.L0f0995ec:
/*  f0995ec:	3c0b800a */ 	lui	$t3,0x800a
/*  f0995f0:	51400014 */ 	beqzl	$t2,.L0f099644
/*  f0995f4:	8e020024 */ 	lw	$v0,0x24($s0)
/*  f0995f8:	8d6ba244 */ 	lw	$t3,-0x5dbc($t3)
/*  f0995fc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f099600:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f099604:	ad601600 */ 	sw	$zero,0x1600($t3)
/*  f099608:	920e06d7 */ 	lbu	$t6,0x6d7($s0)
/*  f09960c:	ae0c0020 */ 	sw	$t4,0x20($s0)
/*  f099610:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f099614:	31c9ffef */ 	andi	$t1,$t6,0xffef
/*  f099618:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f09961c:	ae000014 */ 	sw	$zero,0x14($s0)
/*  f099620:	a20906d7 */ 	sb	$t1,0x6d7($s0)
/*  f099624:	afa80034 */ 	sw	$t0,0x34($sp)
/*  f099628:	0fc27346 */ 	jal	func0f09cd18
/*  f09962c:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f099630:	10400003 */ 	beqz	$v0,.L0f099640
/*  f099634:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f099638:	1000004c */ 	beqz	$zero,.L0f09976c
/*  f09963c:	8fa2004c */ 	lw	$v0,0x4c($sp)
.L0f099640:
/*  f099640:	8e020024 */ 	lw	$v0,0x24($s0)
.L0f099644:
/*  f099644:	24010009 */ 	addiu	$at,$zero,0x9
/*  f099648:	50400012 */ 	beqzl	$v0,.L0f099694
/*  f09964c:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f099650:	ae020020 */ 	sw	$v0,0x20($s0)
/*  f099654:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f099658:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f09965c:	1441000c */ 	bne	$v0,$at,.L0f099690
/*  f099660:	ae000024 */ 	sw	$zero,0x24($s0)
/*  f099664:	29010002 */ 	slti	$at,$t0,0x2
/*  f099668:	5020000a */ 	beqzl	$at,.L0f099694
/*  f09966c:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f099670:	05000007 */ 	bltz	$t0,.L0f099690
/*  f099674:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f099678:	0fc27346 */ 	jal	func0f09cd18
/*  f09967c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f099680:	50400004 */ 	beqzl	$v0,.L0f099694
/*  f099684:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f099688:	10000038 */ 	beqz	$zero,.L0f09976c
/*  f09968c:	8fa2004c */ 	lw	$v0,0x4c($sp)
.L0f099690:
/*  f099690:	8faf0044 */ 	lw	$t7,0x44($sp)
.L0f099694:
/*  f099694:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f099698:	55e00034 */ 	bnezl	$t7,.L0f09976c
/*  f09969c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0996a0:	8f190008 */ 	lw	$t9,0x8($t8)
/*  f0996a4:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f0996a8:	3c0e800a */ 	lui	$t6,0x800a
/*  f0996ac:	8f2a0000 */ 	lw	$t2,0x0($t9)
/*  f0996b0:	00096900 */ 	sll	$t5,$t1,0x4
/*  f0996b4:	01a96823 */ 	subu	$t5,$t5,$t1
/*  f0996b8:	000a6740 */ 	sll	$t4,$t2,0x1d
/*  f0996bc:	05810005 */ 	bgez	$t4,.L0f0996d4
/*  f0996c0:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0996c4:	0fc2877d */ 	jal	func0f0a1df4
/*  f0996c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0996cc:	10000027 */ 	beqz	$zero,.L0f09976c
/*  f0996d0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0996d4:
/*  f0996d4:	01a96821 */ 	addu	$t5,$t5,$t1
/*  f0996d8:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0996dc:	920f0690 */ 	lbu	$t7,0x690($s0)
/*  f0996e0:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0996e4:	01a96821 */ 	addu	$t5,$t5,$t1
/*  f0996e8:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0996ec:	01cd1023 */ 	subu	$v0,$t6,$t5
/*  f0996f0:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f0996f4:	17000004 */ 	bnez	$t8,.L0f099708
/*  f0996f8:	24420ddc */ 	addiu	$v0,$v0,0xddc
/*  f0996fc:	82190008 */ 	lb	$t9,0x8($s0)
/*  f099700:	57200012 */ 	bnezl	$t9,.L0f09974c
/*  f099704:	904d0690 */ 	lbu	$t5,0x690($v0)
.L0f099708:
/*  f099708:	904a0690 */ 	lbu	$t2,0x690($v0)
/*  f09970c:	314b0001 */ 	andi	$t3,$t2,0x1
/*  f099710:	55600005 */ 	bnezl	$t3,.L0f099728
/*  f099714:	8e09000c */ 	lw	$t1,0xc($s0)
/*  f099718:	804c0008 */ 	lb	$t4,0x8($v0)
/*  f09971c:	5580000b */ 	bnezl	$t4,.L0f09974c
/*  f099720:	904d0690 */ 	lbu	$t5,0x690($v0)
/*  f099724:	8e09000c */ 	lw	$t1,0xc($s0)
.L0f099728:
/*  f099728:	15200004 */ 	bnez	$t1,.L0f09973c
/*  f09972c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099730:	8c4e000c */ 	lw	$t6,0xc($v0)
/*  f099734:	51c00005 */ 	beqzl	$t6,.L0f09974c
/*  f099738:	904d0690 */ 	lbu	$t5,0x690($v0)
.L0f09973c:
/*  f09973c:	0fc2877d */ 	jal	func0f0a1df4
/*  f099740:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f099744:	8fa20024 */ 	lw	$v0,0x24($sp)
/*  f099748:	904d0690 */ 	lbu	$t5,0x690($v0)
.L0f09974c:
/*  f09974c:	31b9fffe */ 	andi	$t9,$t5,0xfffe
/*  f099750:	a0590690 */ 	sb	$t9,0x690($v0)
/*  f099754:	920b0690 */ 	lbu	$t3,0x690($s0)
/*  f099758:	332a0001 */ 	andi	$t2,$t9,0x1
/*  f09975c:	316cfffe */ 	andi	$t4,$t3,0xfffe
/*  f099760:	014c4825 */ 	or	$t1,$t2,$t4
/*  f099764:	a2090690 */ 	sb	$t1,0x690($s0)
/*  f099768:	00001025 */ 	or	$v0,$zero,$zero
.L0f09976c:
/*  f09976c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f099770:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f099774:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f099778:	03e00008 */ 	jr	$ra
/*  f09977c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f099780
/*  f099780:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f099784:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f099788:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f09978c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f099790:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f099794:	ac8e00b4 */ 	sw	$t6,0xb4($a0)
/*  f099798:	00808025 */ 	or	$s0,$a0,$zero
/*  f09979c:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f0997a0:	0c0058ba */ 	jal	func000162e8
/*  f0997a4:	24850074 */ 	addiu	$a1,$a0,0x74
/*  f0997a8:	44802000 */ 	mtc1	$zero,$f4
/*  f0997ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0997b0:	e60400a4 */ 	swc1	$f4,0xa4($s0)
/*  f0997b4:	0c0068f4 */ 	jal	func0001a3d0
/*  f0997b8:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f0997bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0997c0:	44813000 */ 	mtc1	$at,$f6
/*  f0997c4:	3c01c2a0 */ 	lui	$at,0xc2a0
/*  f0997c8:	44815000 */ 	mtc1	$at,$f10
/*  f0997cc:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0997d0:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0997d4:	e61000a8 */ 	swc1	$f16,0xa8($s0)
/*  f0997d8:	0c0068f7 */ 	jal	func0001a3dc
/*  f0997dc:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f0997e0:	3c014170 */ 	lui	$at,0x4170
/*  f0997e4:	44819000 */ 	mtc1	$at,$f18
/*  f0997e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0997ec:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0997f0:	e60400ac */ 	swc1	$f4,0xac($s0)
/*  f0997f4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0997f8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0997fc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f099800:	03e00008 */ 	jr	$ra
/*  f099804:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f099808
/*  f099808:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f09980c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f099810:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f099814:	00c08025 */ 	or	$s0,$a2,$zero
/*  f099818:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f09981c:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f099820:	0fc2a31f */ 	jal	func0f0a8c7c
/*  f099824:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f099828:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f09982c:	820e0008 */ 	lb	$t6,0x8($s0)
/*  f099830:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f099834:	55c00008 */ 	bnezl	$t6,.L0f099858
/*  f099838:	8e020608 */ 	lw	$v0,0x608($s0)
/*  f09983c:	0fc27346 */ 	jal	func0f09cd18
/*  f099840:	00002825 */ 	or	$a1,$zero,$zero
/*  f099844:	50400004 */ 	beqzl	$v0,.L0f099858
/*  f099848:	8e020608 */ 	lw	$v0,0x608($s0)
/*  f09984c:	100000f0 */ 	beqz	$zero,.L0f099c10
/*  f099850:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*  f099854:	8e020608 */ 	lw	$v0,0x608($s0)
.L0f099858:
/*  f099858:	3c0f800a */ 	lui	$t7,0x800a
/*  f09985c:	5440001b */ 	bnezl	$v0,.L0f0998cc
/*  f099860:	24010001 */ 	addiu	$at,$zero,0x1
/*  f099864:	8defa2d8 */ 	lw	$t7,-0x5d28($t7)
/*  f099868:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f09986c:	24030010 */ 	addiu	$v1,$zero,0x10
/*  f099870:	11e00002 */ 	beqz	$t7,.L0f09987c
/*  f099874:	03001025 */ 	or	$v0,$t8,$zero
/*  f099878:	2403000c */ 	addiu	$v1,$zero,0xc
.L0f09987c:
/*  f09987c:	8e060614 */ 	lw	$a2,0x614($s0)
/*  f099880:	00c3082a */ 	slt	$at,$a2,$v1
/*  f099884:	54200004 */ 	bnezl	$at,.L0f099898
/*  f099888:	44862000 */ 	mtc1	$a2,$f4
/*  f09988c:	1000000e */ 	beqz	$zero,.L0f0998c8
/*  f099890:	ae180608 */ 	sw	$t8,0x608($s0)
/*  f099894:	44862000 */ 	mtc1	$a2,$f4
.L0f099898:
/*  f099898:	3c017f1b */ 	lui	$at,%hi(var7f1ac1b4)
/*  f09989c:	c428c1b4 */ 	lwc1	$f8,%lo(var7f1ac1b4)($at)
/*  f0998a0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0998a4:	44838000 */ 	mtc1	$v1,$f16
/*  f0998a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0998ac:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0998b0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0998b4:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f0998b8:	44052000 */ 	mfc1	$a1,$f4
/*  f0998bc:	0fc265e0 */ 	jal	func0f099780
/*  f0998c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0998c4:	8e020608 */ 	lw	$v0,0x608($s0)
.L0f0998c8:
/*  f0998c8:	24010001 */ 	addiu	$at,$zero,0x1
.L0f0998cc:
/*  f0998cc:	544100d0 */ 	bnel	$v0,$at,.L0f099c10
/*  f0998d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0998d4:	8e190684 */ 	lw	$t9,0x684($s0)
/*  f0998d8:	44803000 */ 	mtc1	$zero,$f6
/*  f0998dc:	a20005dc */ 	sb	$zero,0x5dc($s0)
/*  f0998e0:	ae190688 */ 	sw	$t9,0x688($s0)
/*  f0998e4:	e60605fc */ 	swc1	$f6,0x5fc($s0)
/*  f0998e8:	0fc26f56 */ 	jal	func0f09bd58
/*  f0998ec:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f0998f0:	10400035 */ 	beqz	$v0,.L0f0999c8
/*  f0998f4:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f0998f8:	0fc27346 */ 	jal	func0f09cd18
/*  f0998fc:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f099900:	10400031 */ 	beqz	$v0,.L0f0999c8
/*  f099904:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f099908:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f09990c:	8c480314 */ 	lw	$t0,0x314($v0)
/*  f099910:	3c098009 */ 	lui	$t1,0x8009
/*  f099914:	11000023 */ 	beqz	$t0,.L0f0999a4
/*  f099918:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09991c:	91290af0 */ 	lbu	$t1,0xaf0($t1)
/*  f099920:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f099924:	14c9001d */ 	bne	$a2,$t1,.L0f09999c
/*  f099928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09992c:	8c4a006c */ 	lw	$t2,0x6c($v0)
/*  f099930:	00002825 */ 	or	$a1,$zero,$zero
/*  f099934:	00001825 */ 	or	$v1,$zero,$zero
/*  f099938:	11400003 */ 	beqz	$t2,.L0f099948
/*  f09993c:	00002025 */ 	or	$a0,$zero,$zero
/*  f099940:	10000001 */ 	beqz	$zero,.L0f099948
/*  f099944:	00c02825 */ 	or	$a1,$a2,$zero
.L0f099948:
/*  f099948:	8c4b0068 */ 	lw	$t3,0x68($v0)
/*  f09994c:	11600003 */ 	beqz	$t3,.L0f09995c
/*  f099950:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099954:	10000001 */ 	beqz	$zero,.L0f09995c
/*  f099958:	00c01825 */ 	or	$v1,$a2,$zero
.L0f09995c:
/*  f09995c:	8c4c0064 */ 	lw	$t4,0x64($v0)
/*  f099960:	11800003 */ 	beqz	$t4,.L0f099970
/*  f099964:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099968:	10000001 */ 	beqz	$zero,.L0f099970
/*  f09996c:	00c02025 */ 	or	$a0,$a2,$zero
.L0f099970:
/*  f099970:	8c4d0070 */ 	lw	$t5,0x70($v0)
/*  f099974:	00001025 */ 	or	$v0,$zero,$zero
/*  f099978:	11a00003 */ 	beqz	$t5,.L0f099988
/*  f09997c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099980:	10000001 */ 	beqz	$zero,.L0f099988
/*  f099984:	00c01025 */ 	or	$v0,$a2,$zero
.L0f099988:
/*  f099988:	00447021 */ 	addu	$t6,$v0,$a0
/*  f09998c:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f099990:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f099994:	10d80003 */ 	beq	$a2,$t8,.L0f0999a4
/*  f099998:	00000000 */ 	sll	$zero,$zero,0x0
.L0f09999c:
/*  f09999c:	0fc4a33c */ 	jal	func0f128cf0
/*  f0999a0:	8fa40064 */ 	lw	$a0,0x64($sp)
.L0f0999a4:
/*  f0999a4:	0fc27e88 */ 	jal	func0f09fa20
/*  f0999a8:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f0999ac:	24190006 */ 	addiu	$t9,$zero,0x6
/*  f0999b0:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f0999b4:	ae190020 */ 	sw	$t9,0x20($s0)
/*  f0999b8:	ae080608 */ 	sw	$t0,0x608($s0)
/*  f0999bc:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f0999c0:	10000093 */ 	beqz	$zero,.L0f099c10
/*  f0999c4:	00001025 */ 	or	$v0,$zero,$zero
.L0f0999c8:
/*  f0999c8:	82090008 */ 	lb	$t1,0x8($s0)
/*  f0999cc:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f0999d0:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f0999d4:	5120008a */ 	beqzl	$t1,.L0f099c00
/*  f0999d8:	3c053f5f */ 	lui	$a1,0x3f5f
/*  f0999dc:	0fc26328 */ 	jal	func0f098ca0
/*  f0999e0:	02003025 */ 	or	$a2,$s0,$zero
/*  f0999e4:	8faa0060 */ 	lw	$t2,0x60($sp)
/*  f0999e8:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f0999ec:	24010020 */ 	addiu	$at,$zero,0x20
/*  f0999f0:	8d430000 */ 	lw	$v1,0x0($t2)
/*  f0999f4:	8fab0054 */ 	lw	$t3,0x54($sp)
/*  f0999f8:	10610003 */ 	beq	$v1,$at,.L0f099a08
/*  f0999fc:	24010021 */ 	addiu	$at,$zero,0x21
/*  f099a00:	54610005 */ 	bnel	$v1,$at,.L0f099a18
/*  f099a04:	24010022 */ 	addiu	$at,$zero,0x22
.L0f099a08:
/*  f099a08:	a20b0003 */ 	sb	$t3,0x3($s0)
/*  f099a0c:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f099a10:	8d830000 */ 	lw	$v1,0x0($t4)
/*  f099a14:	24010022 */ 	addiu	$at,$zero,0x22
.L0f099a18:
/*  f099a18:	1461000b */ 	bne	$v1,$at,.L0f099a48
/*  f099a1c:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f099a20:	920e0003 */ 	lbu	$t6,0x3($s0)
/*  f099a24:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f099a28:	11ae0007 */ 	beq	$t5,$t6,.L0f099a48
/*  f099a2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099a30:	0fc27346 */ 	jal	func0f09cd18
/*  f099a34:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f099a38:	10400003 */ 	beqz	$v0,.L0f099a48
/*  f099a3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099a40:	10000073 */ 	beqz	$zero,.L0f099c10
/*  f099a44:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f099a48:
/*  f099a48:	3c02800a */ 	lui	$v0,0x800a
/*  f099a4c:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f099a50:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f099a54:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f099a58:	8c4f1600 */ 	lw	$t7,0x1600($v0)
/*  f099a5c:	03382823 */ 	subu	$a1,$t9,$t8
/*  f099a60:	00054100 */ 	sll	$t0,$a1,0x4
/*  f099a64:	11e00034 */ 	beqz	$t7,.L0f099b38
/*  f099a68:	01054023 */ 	subu	$t0,$t0,$a1
/*  f099a6c:	00084080 */ 	sll	$t0,$t0,0x2
/*  f099a70:	01054021 */ 	addu	$t0,$t0,$a1
/*  f099a74:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f099a78:	01054021 */ 	addu	$t0,$t0,$a1
/*  f099a7c:	00084080 */ 	sll	$t0,$t0,0x2
/*  f099a80:	00484821 */ 	addu	$t1,$v0,$t0
/*  f099a84:	252a0638 */ 	addiu	$t2,$t1,0x638
/*  f099a88:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f099a8c:	afaa004c */ 	sw	$t2,0x4c($sp)
/*  f099a90:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f099a94:	0fc26313 */ 	jal	func0f098c4c
/*  f099a98:	27a40040 */ 	addiu	$a0,$sp,0x40
/*  f099a9c:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f099aa0:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f099aa4:	00002025 */ 	or	$a0,$zero,$zero
/*  f099aa8:	80cb0008 */ 	lb	$t3,0x8($a2)
/*  f099aac:	27a50040 */ 	addiu	$a1,$sp,0x40
/*  f099ab0:	51600016 */ 	beqzl	$t3,.L0f099b0c
/*  f099ab4:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f099ab8:	0fc26328 */ 	jal	func0f098ca0
/*  f099abc:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f099ac0:	04400002 */ 	bltz	$v0,.L0f099acc
/*  f099ac4:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f099ac8:	00001825 */ 	or	$v1,$zero,$zero
.L0f099acc:
/*  f099acc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f099ad0:	27a50040 */ 	addiu	$a1,$sp,0x40
/*  f099ad4:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f099ad8:	0fc26328 */ 	jal	func0f098ca0
/*  f099adc:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f099ae0:	04400002 */ 	bltz	$v0,.L0f099aec
/*  f099ae4:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f099ae8:	00001825 */ 	or	$v1,$zero,$zero
.L0f099aec:
/*  f099aec:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*  f099af0:	90850003 */ 	lbu	$a1,0x3($a0)
/*  f099af4:	0fc26462 */ 	jal	func0f099188
/*  f099af8:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f099afc:	10400002 */ 	beqz	$v0,.L0f099b08
/*  f099b00:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f099b04:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f099b08:
/*  f099b08:	8fa6004c */ 	lw	$a2,0x4c($sp)
.L0f099b0c:
/*  f099b0c:	24010008 */ 	addiu	$at,$zero,0x8
/*  f099b10:	8cc20604 */ 	lw	$v0,0x604($a2)
/*  f099b14:	10400004 */ 	beqz	$v0,.L0f099b28
/*  f099b18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099b1c:	10410002 */ 	beq	$v0,$at,.L0f099b28
/*  f099b20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099b24:	00001825 */ 	or	$v1,$zero,$zero
.L0f099b28:
/*  f099b28:	50600004 */ 	beqzl	$v1,.L0f099b3c
/*  f099b2c:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f099b30:	0fc2877d */ 	jal	func0f0a1df4
/*  f099b34:	00000000 */ 	sll	$zero,$zero,0x0
.L0f099b38:
/*  f099b38:	8fad0058 */ 	lw	$t5,0x58($sp)
.L0f099b3c:
/*  f099b3c:	29a10002 */ 	slti	$at,$t5,0x2
/*  f099b40:	50200028 */ 	beqzl	$at,.L0f099be4
/*  f099b44:	8e020024 */ 	lw	$v0,0x24($s0)
/*  f099b48:	05a00025 */ 	bltz	$t5,.L0f099be0
/*  f099b4c:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f099b50:	000fc900 */ 	sll	$t9,$t7,0x4
/*  f099b54:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f099b58:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f099b5c:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f099b60:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f099b64:	3c0e800a */ 	lui	$t6,0x800a
/*  f099b68:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f099b6c:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f099b70:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f099b74:	0019c023 */ 	negu	$t8,$t9
/*  f099b78:	01d84021 */ 	addu	$t0,$t6,$t8
/*  f099b7c:	8d0913e0 */ 	lw	$t1,0x13e0($t0)
/*  f099b80:	24010001 */ 	addiu	$at,$zero,0x1
/*  f099b84:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f099b88:	51210016 */ 	beql	$t1,$at,.L0f099be4
/*  f099b8c:	8e020024 */ 	lw	$v0,0x24($s0)
/*  f099b90:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f099b94:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f099b98:	0fc27346 */ 	jal	func0f09cd18
/*  f099b9c:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f099ba0:	1040000f */ 	beqz	$v0,.L0f099be0
/*  f099ba4:	8faa0060 */ 	lw	$t2,0x60($sp)
/*  f099ba8:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f099bac:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f099bb0:	240c000b */ 	addiu	$t4,$zero,0xb
/*  f099bb4:	15610008 */ 	bne	$t3,$at,.L0f099bd8
/*  f099bb8:	240d0011 */ 	addiu	$t5,$zero,0x11
/*  f099bbc:	240fffff */ 	addiu	$t7,$zero,-1
/*  f099bc0:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f099bc4:	ae0c0020 */ 	sw	$t4,0x20($s0)
/*  f099bc8:	ae0d0038 */ 	sw	$t5,0x38($s0)
/*  f099bcc:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f099bd0:	ae0f0018 */ 	sw	$t7,0x18($s0)
/*  f099bd4:	ae190608 */ 	sw	$t9,0x608($s0)
.L0f099bd8:
/*  f099bd8:	1000000d */ 	beqz	$zero,.L0f099c10
/*  f099bdc:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f099be0:
/*  f099be0:	8e020024 */ 	lw	$v0,0x24($s0)
.L0f099be4:
/*  f099be4:	50400006 */ 	beqzl	$v0,.L0f099c00
/*  f099be8:	3c053f5f */ 	lui	$a1,0x3f5f
/*  f099bec:	ae020020 */ 	sw	$v0,0x20($s0)
/*  f099bf0:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f099bf4:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f099bf8:	ae000024 */ 	sw	$zero,0x24($s0)
/*  f099bfc:	3c053f5f */ 	lui	$a1,0x3f5f
.L0f099c00:
/*  f099c00:	34a55dd8 */ 	ori	$a1,$a1,0x5dd8
/*  f099c04:	0fc265e0 */ 	jal	func0f099780
/*  f099c08:	02002025 */ 	or	$a0,$s0,$zero
/*  f099c0c:	00001025 */ 	or	$v0,$zero,$zero
.L0f099c10:
/*  f099c10:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f099c14:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f099c18:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f099c1c:	03e00008 */ 	jr	$ra
/*  f099c20:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f099c24
/*  f099c24:	8c8e0604 */ 	lw	$t6,0x604($a0)
/*  f099c28:	24010001 */ 	addiu	$at,$zero,0x1
/*  f099c2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f099c30:	15c10003 */ 	bne	$t6,$at,.L0f099c40
/*  f099c34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099c38:	03e00008 */ 	jr	$ra
/*  f099c3c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f099c40:
/*  f099c40:	03e00008 */ 	jr	$ra
/*  f099c44:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f099c48
/*  f099c48:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f099c4c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f099c50:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f099c54:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f099c58:	00c08025 */ 	or	$s0,$a2,$zero
/*  f099c5c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f099c60:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f099c64:	0fc2c41f */ 	jal	func0f0b107c
/*  f099c68:	00c02025 */ 	or	$a0,$a2,$zero
/*  f099c6c:	3c0e800a */ 	lui	$t6,0x800a
/*  f099c70:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f099c74:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f099c78:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f099c7c:	8dcf00d8 */ 	lw	$t7,0xd8($t6)
/*  f099c80:	00002825 */ 	or	$a1,$zero,$zero
/*  f099c84:	51e0000a */ 	beqzl	$t7,.L0f099cb0
/*  f099c88:	8e190618 */ 	lw	$t9,0x618($s0)
/*  f099c8c:	ae00068c */ 	sw	$zero,0x68c($s0)
/*  f099c90:	ae180680 */ 	sw	$t8,0x680($s0)
/*  f099c94:	0fc27346 */ 	jal	func0f09cd18
/*  f099c98:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f099c9c:	50400004 */ 	beqzl	$v0,.L0f099cb0
/*  f099ca0:	8e190618 */ 	lw	$t9,0x618($s0)
/*  f099ca4:	10000195 */ 	beqz	$zero,.L0f09a2fc
/*  f099ca8:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f099cac:	8e190618 */ 	lw	$t9,0x618($s0)
.L0f099cb0:
/*  f099cb0:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f099cb4:	3c08800a */ 	lui	$t0,0x800a
/*  f099cb8:	17200018 */ 	bnez	$t9,.L0f099d1c
/*  f099cbc:	00095100 */ 	sll	$t2,$t1,0x4
/*  f099cc0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f099cc4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f099cc8:	01495021 */ 	addu	$t2,$t2,$t1
/*  f099ccc:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f099cd0:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f099cd4:	01495021 */ 	addu	$t2,$t2,$t1
/*  f099cd8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f099cdc:	000a5823 */ 	negu	$t3,$t2
/*  f099ce0:	240cffff */ 	addiu	$t4,$zero,-1
/*  f099ce4:	ae0c0670 */ 	sw	$t4,0x670($s0)
/*  f099ce8:	ae000674 */ 	sw	$zero,0x674($s0)
/*  f099cec:	010b1021 */ 	addu	$v0,$t0,$t3
/*  f099cf0:	8c4d13e0 */ 	lw	$t5,0x13e0($v0)
/*  f099cf4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f099cf8:	24420ddc */ 	addiu	$v0,$v0,0xddc
/*  f099cfc:	55a10008 */ 	bnel	$t5,$at,.L0f099d20
/*  f099d00:	8e030608 */ 	lw	$v1,0x608($s0)
/*  f099d04:	8c4e0614 */ 	lw	$t6,0x614($v0)
/*  f099d08:	240f0009 */ 	addiu	$t7,$zero,0x9
/*  f099d0c:	29c10014 */ 	slti	$at,$t6,0x14
/*  f099d10:	50200003 */ 	beqzl	$at,.L0f099d20
/*  f099d14:	8e030608 */ 	lw	$v1,0x608($s0)
/*  f099d18:	ae0f0608 */ 	sw	$t7,0x608($s0)
.L0f099d1c:
/*  f099d1c:	8e030608 */ 	lw	$v1,0x608($s0)
.L0f099d20:
/*  f099d20:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f099d24:	24010009 */ 	addiu	$at,$zero,0x9
/*  f099d28:	1461001a */ 	bne	$v1,$at,.L0f099d94
/*  f099d2c:	00194900 */ 	sll	$t1,$t9,0x4
/*  f099d30:	01394823 */ 	subu	$t1,$t1,$t9
/*  f099d34:	00094880 */ 	sll	$t1,$t1,0x2
/*  f099d38:	01394821 */ 	addu	$t1,$t1,$t9
/*  f099d3c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f099d40:	3c18800a */ 	lui	$t8,0x800a
/*  f099d44:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f099d48:	01394821 */ 	addu	$t1,$t1,$t9
/*  f099d4c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f099d50:	00095023 */ 	negu	$t2,$t1
/*  f099d54:	030a1021 */ 	addu	$v0,$t8,$t2
/*  f099d58:	8c4813e0 */ 	lw	$t0,0x13e0($v0)
/*  f099d5c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f099d60:	24420ddc */ 	addiu	$v0,$v0,0xddc
/*  f099d64:	15010007 */ 	bne	$t0,$at,.L0f099d84
/*  f099d68:	00001825 */ 	or	$v1,$zero,$zero
/*  f099d6c:	8c4b0614 */ 	lw	$t3,0x614($v0)
/*  f099d70:	29610014 */ 	slti	$at,$t3,0x14
/*  f099d74:	50200004 */ 	beqzl	$at,.L0f099d88
/*  f099d78:	ae000614 */ 	sw	$zero,0x614($s0)
/*  f099d7c:	1000015f */ 	beqz	$zero,.L0f09a2fc
/*  f099d80:	00001025 */ 	or	$v0,$zero,$zero
.L0f099d84:
/*  f099d84:	ae000614 */ 	sw	$zero,0x614($s0)
.L0f099d88:
/*  f099d88:	ae000618 */ 	sw	$zero,0x618($s0)
/*  f099d8c:	ae000608 */ 	sw	$zero,0x608($s0)
/*  f099d90:	ae00061c */ 	sw	$zero,0x61c($s0)
.L0f099d94:
/*  f099d94:	54600095 */ 	bnezl	$v1,.L0f099fec
/*  f099d98:	24010001 */ 	addiu	$at,$zero,0x1
/*  f099d9c:	8e0c0618 */ 	lw	$t4,0x618($s0)
/*  f099da0:	8fad0030 */ 	lw	$t5,0x30($sp)
/*  f099da4:	8faa0030 */ 	lw	$t2,0x30($sp)
/*  f099da8:	5580003f */ 	bnezl	$t4,.L0f099ea8
/*  f099dac:	8fb80038 */ 	lw	$t8,0x38($sp)
/*  f099db0:	11a00034 */ 	beqz	$t5,.L0f099e84
/*  f099db4:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f099db8:	81a20007 */ 	lb	$v0,0x7($t5)
/*  f099dbc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f099dc0:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f099dc4:	50400004 */ 	beqzl	$v0,.L0f099dd8
/*  f099dc8:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f099dcc:	1441002d */ 	bne	$v0,$at,.L0f099e84
/*  f099dd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099dd4:	8dcf0004 */ 	lw	$t7,0x4($t6)
.L0f099dd8:
/*  f099dd8:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f099ddc:	01f94821 */ 	addu	$t1,$t7,$t9
/*  f099de0:	8d38001c */ 	lw	$t8,0x1c($t1)
/*  f099de4:	24690001 */ 	addiu	$t1,$v1,0x1
/*  f099de8:	8f04000c */ 	lw	$a0,0xc($t8)
/*  f099dec:	10800023 */ 	beqz	$a0,.L0f099e7c
/*  f099df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099df4:	8dca0000 */ 	lw	$t2,0x0($t6)
/*  f099df8:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f099dfc:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f099e00:	1141001e */ 	beq	$t2,$at,.L0f099e7c
/*  f099e04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099e08:	0fc26238 */ 	jal	func0f0988e0
/*  f099e0c:	02003025 */ 	or	$a2,$s0,$zero
/*  f099e10:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
/*  f099e14:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f099e18:	356c0001 */ 	ori	$t4,$t3,0x1
/*  f099e1c:	a20c06d6 */ 	sb	$t4,0x6d6($s0)
/*  f099e20:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f099e24:	8c6d0004 */ 	lw	$t5,0x4($v1)
/*  f099e28:	81f90007 */ 	lb	$t9,0x7($t7)
/*  f099e2c:	00194880 */ 	sll	$t1,$t9,0x2
/*  f099e30:	01a9c021 */ 	addu	$t8,$t5,$t1
/*  f099e34:	8f0e001c */ 	lw	$t6,0x1c($t8)
/*  f099e38:	91ca0010 */ 	lbu	$t2,0x10($t6)
/*  f099e3c:	31480004 */ 	andi	$t0,$t2,0x4
/*  f099e40:	51000005 */ 	beqzl	$t0,.L0f099e58
/*  f099e44:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f099e48:	920c0690 */ 	lbu	$t4,0x690($s0)
/*  f099e4c:	358f0020 */ 	ori	$t7,$t4,0x20
/*  f099e50:	a20f0690 */ 	sb	$t7,0x690($s0)
/*  f099e54:	8c620000 */ 	lw	$v0,0x0($v1)
.L0f099e58:
/*  f099e58:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f099e5c:	10410003 */ 	beq	$v0,$at,.L0f099e6c
/*  f099e60:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f099e64:	1441000d */ 	bne	$v0,$at,.L0f099e9c
/*  f099e68:	00000000 */ 	sll	$zero,$zero,0x0
.L0f099e6c:
/*  f099e6c:	921906d6 */ 	lbu	$t9,0x6d6($s0)
/*  f099e70:	332dff0f */ 	andi	$t5,$t9,0xff0f
/*  f099e74:	10000009 */ 	beqz	$zero,.L0f099e9c
/*  f099e78:	a20d06d6 */ 	sb	$t5,0x6d6($s0)
.L0f099e7c:
/*  f099e7c:	10000007 */ 	beqz	$zero,.L0f099e9c
/*  f099e80:	ae090608 */ 	sw	$t1,0x608($s0)
.L0f099e84:
/*  f099e84:	0fc27346 */ 	jal	func0f09cd18
/*  f099e88:	00002825 */ 	or	$a1,$zero,$zero
/*  f099e8c:	10400003 */ 	beqz	$v0,.L0f099e9c
/*  f099e90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f099e94:	10000119 */ 	beqz	$zero,.L0f09a2fc
/*  f099e98:	8fa20044 */ 	lw	$v0,0x44($sp)
.L0f099e9c:
/*  f099e9c:	10000052 */ 	beqz	$zero,.L0f099fe8
/*  f099ea0:	8e030608 */ 	lw	$v1,0x608($s0)
/*  f099ea4:	8fb80038 */ 	lw	$t8,0x38($sp)
.L0f099ea8:
/*  f099ea8:	81480007 */ 	lb	$t0,0x7($t2)
/*  f099eac:	02002025 */ 	or	$a0,$s0,$zero
/*  f099eb0:	8f0e0004 */ 	lw	$t6,0x4($t8)
/*  f099eb4:	00085880 */ 	sll	$t3,$t0,0x2
/*  f099eb8:	01cb6021 */ 	addu	$t4,$t6,$t3
/*  f099ebc:	8d8f001c */ 	lw	$t7,0x1c($t4)
/*  f099ec0:	91f90010 */ 	lbu	$t9,0x10($t7)
/*  f099ec4:	332d0004 */ 	andi	$t5,$t9,0x4
/*  f099ec8:	51a0002b */ 	beqzl	$t5,.L0f099f78
/*  f099ecc:	8e18060c */ 	lw	$t8,0x60c($s0)
/*  f099ed0:	0fc26291 */ 	jal	func0f098a44
/*  f099ed4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f099ed8:	5040001f */ 	beqzl	$v0,.L0f099f58
/*  f099edc:	ae00060c */ 	sw	$zero,0x60c($s0)
/*  f099ee0:	8e09060c */ 	lw	$t1,0x60c($s0)
/*  f099ee4:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f099ee8:	02003025 */ 	or	$a2,$s0,$zero
/*  f099eec:	31380010 */ 	andi	$t8,$t1,0x10
/*  f099ef0:	17000019 */ 	bnez	$t8,.L0f099f58
/*  f099ef4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f099ef8:	92040003 */ 	lbu	$a0,0x3($s0)
/*  f099efc:	0fc2637e */ 	jal	func0f098df8
/*  f099f00:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f099f04:	8e0a060c */ 	lw	$t2,0x60c($s0)
/*  f099f08:	92040003 */ 	lbu	$a0,0x3($s0)
/*  f099f0c:	02003025 */ 	or	$a2,$s0,$zero
/*  f099f10:	35480010 */ 	ori	$t0,$t2,0x10
/*  f099f14:	ae08060c */ 	sw	$t0,0x60c($s0)
/*  f099f18:	0fc26328 */ 	jal	func0f098ca0
/*  f099f1c:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f099f20:	28410002 */ 	slti	$at,$v0,0x2
/*  f099f24:	54200005 */ 	bnezl	$at,.L0f099f3c
/*  f099f28:	2401ffff */ 	addiu	$at,$zero,-1
/*  f099f2c:	920e0690 */ 	lbu	$t6,0x690($s0)
/*  f099f30:	31cbffdf */ 	andi	$t3,$t6,0xffdf
/*  f099f34:	a20b0690 */ 	sb	$t3,0x690($s0)
/*  f099f38:	2401ffff */ 	addiu	$at,$zero,-1
.L0f099f3c:
/*  f099f3c:	54410007 */ 	bnel	$v0,$at,.L0f099f5c
/*  f099f40:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f099f44:	920c0690 */ 	lbu	$t4,0x690($s0)
/*  f099f48:	318fffdf */ 	andi	$t7,$t4,0xffdf
/*  f099f4c:	10000002 */ 	beqz	$zero,.L0f099f58
/*  f099f50:	a20f0690 */ 	sb	$t7,0x690($s0)
/*  f099f54:	ae00060c */ 	sw	$zero,0x60c($s0)
.L0f099f58:
/*  f099f58:	8e19000c */ 	lw	$t9,0xc($s0)
.L0f099f5c:
/*  f099f5c:	53200017 */ 	beqzl	$t9,.L0f099fbc
/*  f099f60:	8e0b068c */ 	lw	$t3,0x68c($s0)
/*  f099f64:	920d0690 */ 	lbu	$t5,0x690($s0)
/*  f099f68:	31a9ffdf */ 	andi	$t1,$t5,0xffdf
/*  f099f6c:	10000012 */ 	beqz	$zero,.L0f099fb8
/*  f099f70:	a2090690 */ 	sb	$t1,0x690($s0)
/*  f099f74:	8e18060c */ 	lw	$t8,0x60c($s0)
.L0f099f78:
/*  f099f78:	02002025 */ 	or	$a0,$s0,$zero
/*  f099f7c:	330a0010 */ 	andi	$t2,$t8,0x10
/*  f099f80:	5540000e */ 	bnezl	$t2,.L0f099fbc
/*  f099f84:	8e0b068c */ 	lw	$t3,0x68c($s0)
/*  f099f88:	0fc26291 */ 	jal	func0f098a44
/*  f099f8c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f099f90:	10400009 */ 	beqz	$v0,.L0f099fb8
/*  f099f94:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f099f98:	92040003 */ 	lbu	$a0,0x3($s0)
/*  f099f9c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f099fa0:	02003025 */ 	or	$a2,$s0,$zero
/*  f099fa4:	0fc2637e */ 	jal	func0f098df8
/*  f099fa8:	00003825 */ 	or	$a3,$zero,$zero
/*  f099fac:	8e08060c */ 	lw	$t0,0x60c($s0)
/*  f099fb0:	350e0010 */ 	ori	$t6,$t0,0x10
/*  f099fb4:	ae0e060c */ 	sw	$t6,0x60c($s0)
.L0f099fb8:
/*  f099fb8:	8e0b068c */ 	lw	$t3,0x68c($s0)
.L0f099fbc:
/*  f099fbc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f099fc0:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f099fc4:	51610008 */ 	beql	$t3,$at,.L0f099fe8
/*  f099fc8:	8e030608 */ 	lw	$v1,0x608($s0)
/*  f099fcc:	0fc27346 */ 	jal	func0f09cd18
/*  f099fd0:	00002825 */ 	or	$a1,$zero,$zero
/*  f099fd4:	50400004 */ 	beqzl	$v0,.L0f099fe8
/*  f099fd8:	8e030608 */ 	lw	$v1,0x608($s0)
/*  f099fdc:	100000c7 */ 	beqz	$zero,.L0f09a2fc
/*  f099fe0:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f099fe4:	8e030608 */ 	lw	$v1,0x608($s0)
.L0f099fe8:
/*  f099fe8:	24010001 */ 	addiu	$at,$zero,0x1
.L0f099fec:
/*  f099fec:	5461001f */ 	bnel	$v1,$at,.L0f09a06c
/*  f099ff0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f099ff4:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f099ff8:	240f000b */ 	addiu	$t7,$zero,0xb
/*  f099ffc:	24790001 */ 	addiu	$t9,$v1,0x1
/*  f09a000:	28410010 */ 	slti	$at,$v0,0x10
/*  f09a004:	10200004 */ 	beqz	$at,.L0f09a018
/*  f09a008:	240d0011 */ 	addiu	$t5,$zero,0x11
/*  f09a00c:	820c0007 */ 	lb	$t4,0x7($s0)
/*  f09a010:	55800009 */ 	bnezl	$t4,.L0f09a038
/*  f09a014:	44822000 */ 	mtc1	$v0,$f4
.L0f09a018:
/*  f09a018:	ae0f0020 */ 	sw	$t7,0x20($s0)
/*  f09a01c:	ae190608 */ 	sw	$t9,0x608($s0)
/*  f09a020:	ae0d0038 */ 	sw	$t5,0x38($s0)
/*  f09a024:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f09a028:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f09a02c:	1000000e */ 	beqz	$zero,.L0f09a068
/*  f09a030:	03201825 */ 	or	$v1,$t9,$zero
/*  f09a034:	44822000 */ 	mtc1	$v0,$f4
.L0f09a038:
/*  f09a038:	3c017f1b */ 	lui	$at,%hi(var7f1ac1b8)
/*  f09a03c:	c428c1b8 */ 	lwc1	$f8,%lo(var7f1ac1b8)($at)
/*  f09a040:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f09a044:	3c014180 */ 	lui	$at,0x4180
/*  f09a048:	44818000 */ 	mtc1	$at,$f16
/*  f09a04c:	02002025 */ 	or	$a0,$s0,$zero
/*  f09a050:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f09a054:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f09a058:	44059000 */ 	mfc1	$a1,$f18
/*  f09a05c:	0fc265e0 */ 	jal	func0f099780
/*  f09a060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a064:	8e030608 */ 	lw	$v1,0x608($s0)
.L0f09a068:
/*  f09a068:	24010002 */ 	addiu	$at,$zero,0x2
.L0f09a06c:
/*  f09a06c:	54610069 */ 	bnel	$v1,$at,.L0f09a214
/*  f09a070:	24010003 */ 	addiu	$at,$zero,0x3
/*  f09a074:	8e090018 */ 	lw	$t1,0x18($s0)
/*  f09a078:	8fb80038 */ 	lw	$t8,0x38($sp)
/*  f09a07c:	5520004f */ 	bnezl	$t1,.L0f09a1bc
/*  f09a080:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09a084:	8f0a0000 */ 	lw	$t2,0x0($t8)
/*  f09a088:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f09a08c:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f09a090:	55410012 */ 	bnel	$t2,$at,.L0f09a0dc
/*  f09a094:	8e0a060c */ 	lw	$t2,0x60c($s0)
/*  f09a098:	81020007 */ 	lb	$v0,0x7($t0)
/*  f09a09c:	0442000f */ 	bltzl	$v0,.L0f09a0dc
/*  f09a0a0:	8e0a060c */ 	lw	$t2,0x60c($s0)
/*  f09a0a4:	8f0e0004 */ 	lw	$t6,0x4($t8)
/*  f09a0a8:	00025880 */ 	sll	$t3,$v0,0x2
/*  f09a0ac:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f09a0b0:	01cb6021 */ 	addu	$t4,$t6,$t3
/*  f09a0b4:	8d8f001c */ 	lw	$t7,0x1c($t4)
/*  f09a0b8:	8de4000c */ 	lw	$a0,0xc($t7)
/*  f09a0bc:	50800007 */ 	beqzl	$a0,.L0f09a0dc
/*  f09a0c0:	8e0a060c */ 	lw	$t2,0x60c($s0)
/*  f09a0c4:	0fc26238 */ 	jal	func0f0988e0
/*  f09a0c8:	02003025 */ 	or	$a2,$s0,$zero
/*  f09a0cc:	920d0690 */ 	lbu	$t5,0x690($s0)
/*  f09a0d0:	35a90040 */ 	ori	$t1,$t5,0x40
/*  f09a0d4:	a2090690 */ 	sb	$t1,0x690($s0)
/*  f09a0d8:	8e0a060c */ 	lw	$t2,0x60c($s0)
.L0f09a0dc:
/*  f09a0dc:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f09a0e0:	02003025 */ 	or	$a2,$s0,$zero
/*  f09a0e4:	31480010 */ 	andi	$t0,$t2,0x10
/*  f09a0e8:	15000004 */ 	bnez	$t0,.L0f09a0fc
/*  f09a0ec:	00003825 */ 	or	$a3,$zero,$zero
/*  f09a0f0:	92040003 */ 	lbu	$a0,0x3($s0)
/*  f09a0f4:	0fc2637e */ 	jal	func0f098df8
/*  f09a0f8:	afa00010 */ 	sw	$zero,0x10($sp)
.L0f09a0fc:
/*  f09a0fc:	3c18800a */ 	lui	$t8,0x800a
/*  f09a100:	8f189ff4 */ 	lw	$t8,-0x600c($t8)
/*  f09a104:	3c0e800a */ 	lui	$t6,0x800a
/*  f09a108:	5b00002c */ 	blezl	$t8,.L0f09a1bc
/*  f09a10c:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09a110:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f09a114:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09a118:	8dcb0000 */ 	lw	$t3,0x0($t6)
/*  f09a11c:	51610027 */ 	beql	$t3,$at,.L0f09a1bc
/*  f09a120:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09a124:	0fc2775f */ 	jal	func0f09dd7c
/*  f09a128:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a12c:	10400022 */ 	beqz	$v0,.L0f09a1b8
/*  f09a130:	3c0c8007 */ 	lui	$t4,0x8007
/*  f09a134:	8d8c0760 */ 	lw	$t4,0x760($t4)
/*  f09a138:	3c0f800a */ 	lui	$t7,0x800a
/*  f09a13c:	5580001f */ 	bnezl	$t4,.L0f09a1bc
/*  f09a140:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09a144:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f09a148:	8fad0038 */ 	lw	$t5,0x38($sp)
/*  f09a14c:	8df900d8 */ 	lw	$t9,0xd8($t7)
/*  f09a150:	5720001a */ 	bnezl	$t9,.L0f09a1bc
/*  f09a154:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09a158:	8da90000 */ 	lw	$t1,0x0($t5)
/*  f09a15c:	2d210058 */ 	sltiu	$at,$t1,0x58
/*  f09a160:	10200006 */ 	beqz	$at,.L0f09a17c
/*  f09a164:	00094880 */ 	sll	$t1,$t1,0x2
/*  f09a168:	3c017f1b */ 	lui	$at,%hi(var7f1ac1bc)
/*  f09a16c:	00290821 */ 	addu	$at,$at,$t1
/*  f09a170:	8c29c1bc */ 	lw	$t1,%lo(var7f1ac1bc)($at)
/*  f09a174:	01200008 */ 	jr	$t1
/*  f09a178:	00000000 */ 	sll	$zero,$zero,0x0
.L0f09a17c:
/*  f09a17c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09a180:	44812000 */ 	mtc1	$at,$f4
/*  f09a184:	3c048009 */ 	lui	$a0,0x8009
/*  f09a188:	240affff */ 	addiu	$t2,$zero,-1
/*  f09a18c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f09a190:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f09a194:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f09a198:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f09a19c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f09a1a0:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09a1a4:	2405804f */ 	addiu	$a1,$zero,-32689
/*  f09a1a8:	00003025 */ 	or	$a2,$zero,$zero
/*  f09a1ac:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09a1b0:	0c004241 */ 	jal	func00010904
/*  f09a1b4:	e7a40014 */ 	swc1	$f4,0x14($sp)
.L0f09a1b8:
/*  f09a1b8:	8e0e001c */ 	lw	$t6,0x1c($s0)
.L0f09a1bc:
/*  f09a1bc:	8e0b0038 */ 	lw	$t3,0x38($s0)
/*  f09a1c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f09a1c4:	3c053f5f */ 	lui	$a1,0x3f5f
/*  f09a1c8:	01cb082a */ 	slt	$at,$t6,$t3
/*  f09a1cc:	1420000d */ 	bnez	$at,.L0f09a204
/*  f09a1d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a1d4:	8e0c0018 */ 	lw	$t4,0x18($s0)
/*  f09a1d8:	240f000c */ 	addiu	$t7,$zero,0xc
/*  f09a1dc:	29810002 */ 	slti	$at,$t4,0x2
/*  f09a1e0:	14200008 */ 	bnez	$at,.L0f09a204
/*  f09a1e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a1e8:	8e190608 */ 	lw	$t9,0x608($s0)
/*  f09a1ec:	ae0f0020 */ 	sw	$t7,0x20($s0)
/*  f09a1f0:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f09a1f4:	27230001 */ 	addiu	$v1,$t9,0x1
/*  f09a1f8:	ae030608 */ 	sw	$v1,0x608($s0)
/*  f09a1fc:	10000004 */ 	beqz	$zero,.L0f09a210
/*  f09a200:	ae000018 */ 	sw	$zero,0x18($s0)
.L0f09a204:
/*  f09a204:	0fc265e0 */ 	jal	func0f099780
/*  f09a208:	34a55dd8 */ 	ori	$a1,$a1,0x5dd8
/*  f09a20c:	8e030608 */ 	lw	$v1,0x608($s0)
.L0f09a210:
/*  f09a210:	24010003 */ 	addiu	$at,$zero,0x3
.L0f09a214:
/*  f09a214:	14610038 */ 	bne	$v1,$at,.L0f09a2f8
/*  f09a218:	8fa90038 */ 	lw	$t1,0x38($sp)
/*  f09a21c:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f09a220:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f09a224:	3c18800a */ 	lui	$t8,0x800a
/*  f09a228:	55410003 */ 	bnel	$t2,$at,.L0f09a238
/*  f09a22c:	8e080018 */ 	lw	$t0,0x18($s0)
/*  f09a230:	ae00068c */ 	sw	$zero,0x68c($s0)
/*  f09a234:	8e080018 */ 	lw	$t0,0x18($s0)
.L0f09a238:
/*  f09a238:	55000004 */ 	bnezl	$t0,.L0f09a24c
/*  f09a23c:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09a240:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f09a244:	af001600 */ 	sw	$zero,0x1600($t8)
/*  f09a248:	8e0e001c */ 	lw	$t6,0x1c($s0)
.L0f09a24c:
/*  f09a24c:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f09a250:	29c10017 */ 	slti	$at,$t6,0x17
/*  f09a254:	50200010 */ 	beqzl	$at,.L0f09a298
/*  f09a258:	ae000020 */ 	sw	$zero,0x20($s0)
/*  f09a25c:	0fc2c6b4 */ 	jal	func0f0b1ad0
/*  f09a260:	8d640000 */ 	lw	$a0,0x0($t3)
/*  f09a264:	1040000b */ 	beqz	$v0,.L0f09a294
/*  f09a268:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f09a26c:	8d840000 */ 	lw	$a0,0x0($t4)
/*  f09a270:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f09a274:	24050040 */ 	addiu	$a1,$zero,0x40
/*  f09a278:	10400006 */ 	beqz	$v0,.L0f09a294
/*  f09a27c:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f09a280:	8de40000 */ 	lw	$a0,0x0($t7)
/*  f09a284:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f09a288:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f09a28c:	5040000c */ 	beqzl	$v0,.L0f09a2c0
/*  f09a290:	8e19001c */ 	lw	$t9,0x1c($s0)
.L0f09a294:
/*  f09a294:	ae000020 */ 	sw	$zero,0x20($s0)
.L0f09a298:
/*  f09a298:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f09a29c:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f09a2a0:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f09a2a4:	0fc27346 */ 	jal	func0f09cd18
/*  f09a2a8:	00002825 */ 	or	$a1,$zero,$zero
/*  f09a2ac:	50400013 */ 	beqzl	$v0,.L0f09a2fc
/*  f09a2b0:	00001025 */ 	or	$v0,$zero,$zero
/*  f09a2b4:	10000011 */ 	beqz	$zero,.L0f09a2fc
/*  f09a2b8:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f09a2bc:	8e19001c */ 	lw	$t9,0x1c($s0)
.L0f09a2c0:
/*  f09a2c0:	240d0017 */ 	addiu	$t5,$zero,0x17
/*  f09a2c4:	3c017f1b */ 	lui	$at,%hi(var7f1ac31c)
/*  f09a2c8:	01b94823 */ 	subu	$t1,$t5,$t9
/*  f09a2cc:	44893000 */ 	mtc1	$t1,$f6
/*  f09a2d0:	c42ac31c */ 	lwc1	$f10,%lo(var7f1ac31c)($at)
/*  f09a2d4:	3c0141b8 */ 	lui	$at,0x41b8
/*  f09a2d8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f09a2dc:	44819000 */ 	mtc1	$at,$f18
/*  f09a2e0:	02002025 */ 	or	$a0,$s0,$zero
/*  f09a2e4:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f09a2e8:	46128103 */ 	div.s	$f4,$f16,$f18
/*  f09a2ec:	44052000 */ 	mfc1	$a1,$f4
/*  f09a2f0:	0fc265e0 */ 	jal	func0f099780
/*  f09a2f4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f09a2f8:
/*  f09a2f8:	00001025 */ 	or	$v0,$zero,$zero
.L0f09a2fc:
/*  f09a2fc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f09a300:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f09a304:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f09a308:	03e00008 */ 	jr	$ra
/*  f09a30c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09a310
/*  f09a310:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f09a314:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f09a318:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f09a31c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f09a320:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f09a324:	8cce0618 */ 	lw	$t6,0x618($a2)
/*  f09a328:	00001825 */ 	or	$v1,$zero,$zero
/*  f09a32c:	55c00021 */ 	bnezl	$t6,.L0f09a3b4
/*  f09a330:	8cc9068c */ 	lw	$t1,0x68c($a2)
/*  f09a334:	90cf0003 */ 	lbu	$t7,0x3($a2)
/*  f09a338:	00c02025 */ 	or	$a0,$a2,$zero
/*  f09a33c:	55e0000c */ 	bnezl	$t7,.L0f09a370
/*  f09a340:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f09a344:	00c02025 */ 	or	$a0,$a2,$zero
/*  f09a348:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f09a34c:	0fc2c83a */ 	jal	func0f0b20e8
/*  f09a350:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f09a354:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f09a358:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f09a35c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f09a360:	00402025 */ 	or	$a0,$v0,$zero
/*  f09a364:	10000008 */ 	beqz	$zero,.L0f09a388
/*  f09a368:	a0d80003 */ 	sb	$t8,0x3($a2)
/*  f09a36c:	afa30018 */ 	sw	$v1,0x18($sp)
.L0f09a370:
/*  f09a370:	0fc2c846 */ 	jal	func0f0b2118
/*  f09a374:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f09a378:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f09a37c:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f09a380:	00402025 */ 	or	$a0,$v0,$zero
/*  f09a384:	a0c00003 */ 	sb	$zero,0x3($a2)
.L0f09a388:
/*  f09a388:	1040000e */ 	beqz	$v0,.L0f09a3c4
/*  f09a38c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a390:	0fc26238 */ 	jal	func0f0988e0
/*  f09a394:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f09a398:	3c08800a */ 	lui	$t0,0x800a
/*  f09a39c:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f09a3a0:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f09a3a4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f09a3a8:	10000006 */ 	beqz	$zero,.L0f09a3c4
/*  f09a3ac:	ad190dd4 */ 	sw	$t9,0xdd4($t0)
/*  f09a3b0:	8cc9068c */ 	lw	$t1,0x68c($a2)
.L0f09a3b4:
/*  f09a3b4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09a3b8:	15210002 */ 	bne	$t1,$at,.L0f09a3c4
/*  f09a3bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a3c0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f09a3c4:
/*  f09a3c4:	14600007 */ 	bnez	$v1,.L0f09a3e4
/*  f09a3c8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f09a3cc:	0fc27346 */ 	jal	func0f09cd18
/*  f09a3d0:	00002825 */ 	or	$a1,$zero,$zero
/*  f09a3d4:	50400004 */ 	beqzl	$v0,.L0f09a3e8
/*  f09a3d8:	00001025 */ 	or	$v0,$zero,$zero
/*  f09a3dc:	10000002 */ 	beqz	$zero,.L0f09a3e8
/*  f09a3e0:	8fa2002c */ 	lw	$v0,0x2c($sp)
.L0f09a3e4:
/*  f09a3e4:	00001025 */ 	or	$v0,$zero,$zero
.L0f09a3e8:
/*  f09a3e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09a3ec:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f09a3f0:	03e00008 */ 	jr	$ra
/*  f09a3f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09a3f8
/*  f09a3f8:	8ca80010 */ 	lw	$t0,0x10($a1)
/*  f09a3fc:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f09a400:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f09a404:	8d270284 */ 	lw	$a3,0x284($t1)
/*  f09a408:	310e0002 */ 	andi	$t6,$t0,0x2
/*  f09a40c:	00001025 */ 	or	$v0,$zero,$zero
/*  f09a410:	00001825 */ 	or	$v1,$zero,$zero
/*  f09a414:	11c0000e */ 	beqz	$t6,.L0f09a450
/*  f09a418:	24e61580 */ 	addiu	$a2,$a3,0x1580
/*  f09a41c:	8c8f0558 */ 	lw	$t7,0x558($a0)
/*  f09a420:	29e10003 */ 	slti	$at,$t7,0x3
/*  f09a424:	5020000b */ 	beqzl	$at,.L0f09a454
/*  f09a428:	310b1000 */ 	andi	$t3,$t0,0x1000
/*  f09a42c:	8cf80120 */ 	lw	$t8,0x120($a3)
/*  f09a430:	53000007 */ 	beqzl	$t8,.L0f09a450
/*  f09a434:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f09a438:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f09a43c:	24010100 */ 	addiu	$at,$zero,0x100
/*  f09a440:	332aff00 */ 	andi	$t2,$t9,0xff00
/*  f09a444:	51410003 */ 	beql	$t2,$at,.L0f09a454
/*  f09a448:	310b1000 */ 	andi	$t3,$t0,0x1000
/*  f09a44c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f09a450:
/*  f09a450:	310b1000 */ 	andi	$t3,$t0,0x1000
.L0f09a454:
/*  f09a454:	11600006 */ 	beqz	$t3,.L0f09a470
/*  f09a458:	00086b80 */ 	sll	$t5,$t0,0xe
/*  f09a45c:	8c8c0558 */ 	lw	$t4,0x558($a0)
/*  f09a460:	29810002 */ 	slti	$at,$t4,0x2
/*  f09a464:	10200002 */ 	beqz	$at,.L0f09a470
/*  f09a468:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a46c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f09a470:
/*  f09a470:	05a10006 */ 	bgez	$t5,.L0f09a48c
/*  f09a474:	3c070002 */ 	lui	$a3,0x2
/*  f09a478:	8c8e0558 */ 	lw	$t6,0x558($a0)
/*  f09a47c:	29c10005 */ 	slti	$at,$t6,0x5
/*  f09a480:	50200003 */ 	beqzl	$at,.L0f09a490
/*  f09a484:	310f0020 */ 	andi	$t7,$t0,0x20
/*  f09a488:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f09a48c:
/*  f09a48c:	310f0020 */ 	andi	$t7,$t0,0x20
.L0f09a490:
/*  f09a490:	11e00006 */ 	beqz	$t7,.L0f09a4ac
/*  f09a494:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a498:	8c980558 */ 	lw	$t8,0x558($a0)
/*  f09a49c:	2b010032 */ 	slti	$at,$t8,0x32
/*  f09a4a0:	10200002 */ 	beqz	$at,.L0f09a4ac
/*  f09a4a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a4a8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09a4ac:
/*  f09a4ac:	50600003 */ 	beqzl	$v1,.L0f09a4bc
/*  f09a4b0:	8c99000c */ 	lw	$t9,0xc($a0)
/*  f09a4b4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09a4b8:	8c99000c */ 	lw	$t9,0xc($a0)
.L0f09a4bc:
/*  f09a4bc:	57200008 */ 	bnezl	$t9,.L0f09a4e0
/*  f09a4c0:	80a20007 */ 	lb	$v0,0x7($a1)
/*  f09a4c4:	8c8a060c */ 	lw	$t2,0x60c($a0)
/*  f09a4c8:	314b0010 */ 	andi	$t3,$t2,0x10
/*  f09a4cc:	51600004 */ 	beqzl	$t3,.L0f09a4e0
/*  f09a4d0:	80a20007 */ 	lb	$v0,0x7($a1)
/*  f09a4d4:	50400063 */ 	beqzl	$v0,.L0f09a664
/*  f09a4d8:	8cac0000 */ 	lw	$t4,0x0($a1)
/*  f09a4dc:	80a20007 */ 	lb	$v0,0x7($a1)
.L0f09a4e0:
/*  f09a4e0:	0440000b */ 	bltz	$v0,.L0f09a510
/*  f09a4e4:	00026080 */ 	sll	$t4,$v0,0x2
/*  f09a4e8:	008c6821 */ 	addu	$t5,$a0,$t4
/*  f09a4ec:	8dae0220 */ 	lw	$t6,0x220($t5)
/*  f09a4f0:	00c27821 */ 	addu	$t7,$a2,$v0
/*  f09a4f4:	55c00007 */ 	bnezl	$t6,.L0f09a514
/*  f09a4f8:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f09a4fc:	81f80064 */ 	lb	$t8,0x64($t7)
/*  f09a500:	07020004 */ 	bltzl	$t8,.L0f09a514
/*  f09a504:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f09a508:	03e00008 */ 	jr	$ra
/*  f09a50c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f09a510:
/*  f09a510:	8cb90000 */ 	lw	$t9,0x0($a1)
.L0f09a514:
/*  f09a514:	24010100 */ 	addiu	$at,$zero,0x100
/*  f09a518:	332aff00 */ 	andi	$t2,$t9,0xff00
/*  f09a51c:	55410020 */ 	bnel	$t2,$at,.L0f09a5a0
/*  f09a520:	3c013f80 */ 	lui	$at,0x3f80
/*  f09a524:	80a20050 */ 	lb	$v0,0x50($a1)
/*  f09a528:	3c013f80 */ 	lui	$at,0x3f80
/*  f09a52c:	58400017 */ 	blezl	$v0,.L0f09a58c
/*  f09a530:	44811000 */ 	mtc1	$at,$f2
/*  f09a534:	3c013f80 */ 	lui	$at,0x3f80
/*  f09a538:	44811000 */ 	mtc1	$at,$f2
/*  f09a53c:	c4800660 */ 	lwc1	$f0,0x660($a0)
/*  f09a540:	4602003c */ 	c.lt.s	$f0,$f2
/*  f09a544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a548:	45000012 */ 	bc1f	.L0f09a594
/*  f09a54c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a550:	44823000 */ 	mtc1	$v0,$f6
/*  f09a554:	c5240044 */ 	lwc1	$f4,0x44($t1)
/*  f09a558:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09a55c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f09a560:	46082283 */ 	div.s	$f10,$f4,$f8
/*  f09a564:	460a0400 */ 	add.s	$f16,$f0,$f10
/*  f09a568:	e4900660 */ 	swc1	$f16,0x660($a0)
/*  f09a56c:	c4920660 */ 	lwc1	$f18,0x660($a0)
/*  f09a570:	4612103c */ 	c.lt.s	$f2,$f18
/*  f09a574:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a578:	45000006 */ 	bc1f	.L0f09a594
/*  f09a57c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a580:	03e00008 */ 	jr	$ra
/*  f09a584:	e4820660 */ 	swc1	$f2,0x660($a0)
/*  f09a588:	44811000 */ 	mtc1	$at,$f2
.L0f09a58c:
/*  f09a58c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a590:	e4820660 */ 	swc1	$f2,0x660($a0)
.L0f09a594:
/*  f09a594:	03e00008 */ 	jr	$ra
/*  f09a598:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09a59c:	3c013f80 */ 	lui	$at,0x3f80
.L0f09a5a0:
/*  f09a5a0:	44811000 */ 	mtc1	$at,$f2
/*  f09a5a4:	10600011 */ 	beqz	$v1,.L0f09a5ec
/*  f09a5a8:	e4820660 */ 	swc1	$f2,0x660($a0)
/*  f09a5ac:	8c8b0558 */ 	lw	$t3,0x558($a0)
/*  f09a5b0:	5960000e */ 	blezl	$t3,.L0f09a5ec
/*  f09a5b4:	ac800614 */ 	sw	$zero,0x614($a0)
/*  f09a5b8:	908c0000 */ 	lbu	$t4,0x0($a0)
/*  f09a5bc:	24010013 */ 	addiu	$at,$zero,0x13
/*  f09a5c0:	24020003 */ 	addiu	$v0,$zero,0x3
/*  f09a5c4:	55810003 */ 	bnel	$t4,$at,.L0f09a5d4
/*  f09a5c8:	8c8d0614 */ 	lw	$t5,0x614($a0)
/*  f09a5cc:	2402000d */ 	addiu	$v0,$zero,0xd
/*  f09a5d0:	8c8d0614 */ 	lw	$t5,0x614($a0)
.L0f09a5d4:
/*  f09a5d4:	01a2082a */ 	slt	$at,$t5,$v0
/*  f09a5d8:	50200004 */ 	beqzl	$at,.L0f09a5ec
/*  f09a5dc:	ac800614 */ 	sw	$zero,0x614($a0)
/*  f09a5e0:	03e00008 */ 	jr	$ra
/*  f09a5e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f09a5e8:	ac800614 */ 	sw	$zero,0x614($a0)
.L0f09a5ec:
/*  f09a5ec:	8ca80010 */ 	lw	$t0,0x10($a1)
/*  f09a5f0:	310e0002 */ 	andi	$t6,$t0,0x2
/*  f09a5f4:	11c00006 */ 	beqz	$t6,.L0f09a610
/*  f09a5f8:	31181000 */ 	andi	$t8,$t0,0x1000
/*  f09a5fc:	8c8f0558 */ 	lw	$t7,0x558($a0)
/*  f09a600:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09a604:	15e10002 */ 	bne	$t7,$at,.L0f09a610
/*  f09a608:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a60c:	00001825 */ 	or	$v1,$zero,$zero
.L0f09a610:
/*  f09a610:	13000006 */ 	beqz	$t8,.L0f09a62c
/*  f09a614:	01075024 */ 	and	$t2,$t0,$a3
/*  f09a618:	8c990558 */ 	lw	$t9,0x558($a0)
/*  f09a61c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09a620:	17210002 */ 	bne	$t9,$at,.L0f09a62c
/*  f09a624:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a628:	00001825 */ 	or	$v1,$zero,$zero
.L0f09a62c:
/*  f09a62c:	11400006 */ 	beqz	$t2,.L0f09a648
/*  f09a630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a634:	8c8b0558 */ 	lw	$t3,0x558($a0)
/*  f09a638:	24010004 */ 	addiu	$at,$zero,0x4
/*  f09a63c:	15610002 */ 	bne	$t3,$at,.L0f09a648
/*  f09a640:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a644:	00001825 */ 	or	$v1,$zero,$zero
.L0f09a648:
/*  f09a648:	10600003 */ 	beqz	$v1,.L0f09a658
/*  f09a64c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a650:	03e00008 */ 	jr	$ra
/*  f09a654:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09a658:
/*  f09a658:	03e00008 */ 	jr	$ra
/*  f09a65c:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f09a660:	8cac0000 */ 	lw	$t4,0x0($a1)
.L0f09a664:
/*  f09a664:	24010100 */ 	addiu	$at,$zero,0x100
/*  f09a668:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f09a66c:	318dff00 */ 	andi	$t5,$t4,0xff00
/*  f09a670:	15a1001f */ 	bne	$t5,$at,.L0f09a6f0
/*  f09a674:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a678:	80a20051 */ 	lb	$v0,0x51($a1)
/*  f09a67c:	58400018 */ 	blezl	$v0,.L0f09a6e0
/*  f09a680:	44801000 */ 	mtc1	$zero,$f2
/*  f09a684:	44801000 */ 	mtc1	$zero,$f2
/*  f09a688:	c4800660 */ 	lwc1	$f0,0x660($a0)
/*  f09a68c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f09a690:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a694:	45000014 */ 	bc1f	.L0f09a6e8
/*  f09a698:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a69c:	44822000 */ 	mtc1	$v0,$f4
/*  f09a6a0:	c5260044 */ 	lwc1	$f6,0x44($t1)
/*  f09a6a4:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f09a6a8:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f09a6ac:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f09a6b0:	460a0401 */ 	sub.s	$f16,$f0,$f10
/*  f09a6b4:	e4900660 */ 	swc1	$f16,0x660($a0)
/*  f09a6b8:	c4920660 */ 	lwc1	$f18,0x660($a0)
/*  f09a6bc:	4602903c */ 	c.lt.s	$f18,$f2
/*  f09a6c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a6c4:	45000003 */ 	bc1f	.L0f09a6d4
/*  f09a6c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a6cc:	03e00008 */ 	jr	$ra
/*  f09a6d0:	e4820660 */ 	swc1	$f2,0x660($a0)
.L0f09a6d4:
/*  f09a6d4:	03e00008 */ 	jr	$ra
/*  f09a6d8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09a6dc:	44801000 */ 	mtc1	$zero,$f2
.L0f09a6e0:
/*  f09a6e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a6e4:	e4820660 */ 	swc1	$f2,0x660($a0)
.L0f09a6e8:
/*  f09a6e8:	03e00008 */ 	jr	$ra
/*  f09a6ec:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f09a6f0:
/*  f09a6f0:	03e00008 */ 	jr	$ra
/*  f09a6f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09a6f8
/*  f09a6f8:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f09a6fc:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f09a700:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f09a704:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f09a708:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f09a70c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f09a710:	3c058007 */ 	lui	$a1,%hi(var80070120)
/*  f09a714:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f09a718:	00c08025 */ 	or	$s0,$a2,$zero
/*  f09a71c:	afae0054 */ 	sw	$t6,0x54($sp)
/*  f09a720:	2484b890 */ 	addiu	$a0,$a0,-18288
/*  f09a724:	24a50120 */ 	addiu	$a1,$a1,%lo(var80070120)
/*  f09a728:	0c0036cc */ 	jal	func0000db30
/*  f09a72c:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f09a730:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f09a734:	3c058007 */ 	lui	$a1,%hi(var80070124)
/*  f09a738:	24a50124 */ 	addiu	$a1,$a1,%lo(var80070124)
/*  f09a73c:	0c0036cc */ 	jal	func0000db30
/*  f09a740:	2484b898 */ 	addiu	$a0,$a0,-18280
/*  f09a744:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f09a748:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f09a74c:	a2060004 */ 	sb	$a2,0x4($s0)
/*  f09a750:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f09a754:	24010100 */ 	addiu	$at,$zero,0x100
/*  f09a758:	31f8ff00 */ 	andi	$t8,$t7,0xff00
/*  f09a75c:	57010023 */ 	bnel	$t8,$at,.L0f09a7ec
/*  f09a760:	920c0000 */ 	lbu	$t4,0x0($s0)
/*  f09a764:	c4e00040 */ 	lwc1	$f0,0x40($a3)
/*  f09a768:	c4e40044 */ 	lwc1	$f4,0x44($a3)
/*  f09a76c:	c6080660 */ 	lwc1	$f8,0x660($s0)
/*  f09a770:	3c014270 */ 	lui	$at,0x4270
/*  f09a774:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f09a778:	44817000 */ 	mtc1	$at,$f14
/*  f09a77c:	3c01800a */ 	lui	$at,0x800a
/*  f09a780:	c432a004 */ 	lwc1	$f18,-0x5ffc($at)
/*  f09a784:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f09a788:	c60805fc */ 	lwc1	$f8,0x5fc($s0)
/*  f09a78c:	460e9103 */ 	div.s	$f4,$f18,$f14
/*  f09a790:	460a0300 */ 	add.s	$f12,$f0,$f10
/*  f09a794:	460e6403 */ 	div.s	$f16,$f12,$f14
/*  f09a798:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f09a79c:	46083080 */ 	add.s	$f2,$f6,$f8
/*  f09a7a0:	4600128d */ 	trunc.w.s	$f10,$f2
/*  f09a7a4:	44025000 */ 	mfc1	$v0,$f10
/*  f09a7a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a7ac:	44829000 */ 	mtc1	$v0,$f18
/*  f09a7b0:	ae0205f8 */ 	sw	$v0,0x5f8($s0)
/*  f09a7b4:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f09a7b8:	46101101 */ 	sub.s	$f4,$f2,$f16
/*  f09a7bc:	1c400010 */ 	bgtz	$v0,.L0f09a800
/*  f09a7c0:	e60405fc */ 	swc1	$f4,0x5fc($s0)
/*  f09a7c4:	8e08060c */ 	lw	$t0,0x60c($s0)
/*  f09a7c8:	244b0001 */ 	addiu	$t3,$v0,0x1
/*  f09a7cc:	31090010 */ 	andi	$t1,$t0,0x10
/*  f09a7d0:	15200003 */ 	bnez	$t1,.L0f09a7e0
/*  f09a7d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a7d8:	10000009 */ 	beqz	$zero,.L0f09a800
/*  f09a7dc:	ae0b05f8 */ 	sw	$t3,0x5f8($s0)
.L0f09a7e0:
/*  f09a7e0:	10000007 */ 	beqz	$zero,.L0f09a800
/*  f09a7e4:	a2000004 */ 	sb	$zero,0x4($s0)
/*  f09a7e8:	920c0000 */ 	lbu	$t4,0x0($s0)
.L0f09a7ec:
/*  f09a7ec:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f09a7f0:	ae0605f8 */ 	sw	$a2,0x5f8($s0)
/*  f09a7f4:	55810003 */ 	bnel	$t4,$at,.L0f09a804
/*  f09a7f8:	8e0d0558 */ 	lw	$t5,0x558($s0)
/*  f09a7fc:	afa00054 */ 	sw	$zero,0x54($sp)
.L0f09a800:
/*  f09a800:	8e0d0558 */ 	lw	$t5,0x558($s0)
.L0f09a804:
/*  f09a804:	8e0e05f8 */ 	lw	$t6,0x5f8($s0)
/*  f09a808:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f09a80c:	ae0f0558 */ 	sw	$t7,0x558($s0)
/*  f09a810:	8cf80010 */ 	lw	$t8,0x10($a3)
/*  f09a814:	33192000 */ 	andi	$t9,$t8,0x2000
/*  f09a818:	53200004 */ 	beqzl	$t9,.L0f09a82c
/*  f09a81c:	a2060005 */ 	sb	$a2,0x5($s0)
/*  f09a820:	10000002 */ 	beqz	$zero,.L0f09a82c
/*  f09a824:	a2000005 */ 	sb	$zero,0x5($s0)
/*  f09a828:	a2060005 */ 	sb	$a2,0x5($s0)
.L0f09a82c:
/*  f09a82c:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f09a830:	0fc288c2 */ 	jal	func0f0a2308
/*  f09a834:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f09a838:	82020004 */ 	lb	$v0,0x4($s0)
/*  f09a83c:	44803000 */ 	mtc1	$zero,$f6
/*  f09a840:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f09a844:	10400036 */ 	beqz	$v0,.L0f09a920
/*  f09a848:	e6060250 */ 	swc1	$f6,0x250($s0)
/*  f09a84c:	8e09060c */ 	lw	$t1,0x60c($s0)
/*  f09a850:	8e080614 */ 	lw	$t0,0x614($s0)
/*  f09a854:	352a0020 */ 	ori	$t2,$t1,0x20
/*  f09a858:	ae0a060c */ 	sw	$t2,0x60c($s0)
/*  f09a85c:	354c0010 */ 	ori	$t4,$t2,0x10
/*  f09a860:	ae0c060c */ 	sw	$t4,0x60c($s0)
/*  f09a864:	ae0806a8 */ 	sw	$t0,0x6a8($s0)
/*  f09a868:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f09a86c:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f09a870:	8da50000 */ 	lw	$a1,0x0($t5)
/*  f09a874:	0fc25ee8 */ 	jal	func0f097ba0
/*  f09a878:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f09a87c:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f09a880:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f09a884:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f09a888:	11c00016 */ 	beqz	$t6,.L0f09a8e4
/*  f09a88c:	24010100 */ 	addiu	$at,$zero,0x100
/*  f09a890:	80e30007 */ 	lb	$v1,0x7($a3)
/*  f09a894:	04600013 */ 	bltz	$v1,.L0f09a8e4
/*  f09a898:	00037880 */ 	sll	$t7,$v1,0x2
/*  f09a89c:	020f1021 */ 	addu	$v0,$s0,$t7
/*  f09a8a0:	8c580220 */ 	lw	$t8,0x220($v0)
/*  f09a8a4:	8e1905f8 */ 	lw	$t9,0x5f8($s0)
/*  f09a8a8:	03194023 */ 	subu	$t0,$t8,$t9
/*  f09a8ac:	ac480220 */ 	sw	$t0,0x220($v0)
/*  f09a8b0:	80e90007 */ 	lb	$t1,0x7($a3)
/*  f09a8b4:	00095080 */ 	sll	$t2,$t1,0x2
/*  f09a8b8:	020a5821 */ 	addu	$t3,$s0,$t2
/*  f09a8bc:	8d640220 */ 	lw	$a0,0x220($t3)
/*  f09a8c0:	04830009 */ 	bgezl	$a0,.L0f09a8e8
/*  f09a8c4:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f09a8c8:	8e0c05f8 */ 	lw	$t4,0x5f8($s0)
/*  f09a8cc:	01846821 */ 	addu	$t5,$t4,$a0
/*  f09a8d0:	ae0d05f8 */ 	sw	$t5,0x5f8($s0)
/*  f09a8d4:	80ee0007 */ 	lb	$t6,0x7($a3)
/*  f09a8d8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f09a8dc:	020fc021 */ 	addu	$t8,$s0,$t7
/*  f09a8e0:	af000220 */ 	sw	$zero,0x220($t8)
.L0f09a8e4:
/*  f09a8e4:	8ce20000 */ 	lw	$v0,0x0($a3)
.L0f09a8e8:
/*  f09a8e8:	3059ff00 */ 	andi	$t9,$v0,0xff00
/*  f09a8ec:	53200008 */ 	beqzl	$t9,.L0f09a910
/*  f09a8f0:	ae0606ac */ 	sw	$a2,0x6ac($s0)
/*  f09a8f4:	13210005 */ 	beq	$t9,$at,.L0f09a90c
/*  f09a8f8:	24010200 */ 	addiu	$at,$zero,0x200
/*  f09a8fc:	13210006 */ 	beq	$t9,$at,.L0f09a918
/*  f09a900:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f09a904:	10000006 */ 	beqz	$zero,.L0f09a920
/*  f09a908:	82020004 */ 	lb	$v0,0x4($s0)
.L0f09a90c:
/*  f09a90c:	ae0606ac */ 	sw	$a2,0x6ac($s0)
.L0f09a910:
/*  f09a910:	10000003 */ 	beqz	$zero,.L0f09a920
/*  f09a914:	82020004 */ 	lb	$v0,0x4($s0)
.L0f09a918:
/*  f09a918:	ae0806ac */ 	sw	$t0,0x6ac($s0)
/*  f09a91c:	82020004 */ 	lb	$v0,0x4($s0)
.L0f09a920:
/*  f09a920:	1040009b */ 	beqz	$v0,.L0f09ab90
/*  f09a924:	02002025 */ 	or	$a0,$s0,$zero
/*  f09a928:	0fc2c78a */ 	jal	func0f0b1e28
/*  f09a92c:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f09a930:	1840001e */ 	blez	$v0,.L0f09a9ac
/*  f09a934:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f09a938:	8faa005c */ 	lw	$t2,0x5c($sp)
/*  f09a93c:	3c09800a */ 	lui	$t1,0x800a
/*  f09a940:	8d29a244 */ 	lw	$t1,-0x5dbc($t1)
/*  f09a944:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f09a948:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f09a94c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f09a950:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f09a954:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f09a958:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f09a95c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f09a960:	000b6023 */ 	negu	$t4,$t3
/*  f09a964:	3c02800a */ 	lui	$v0,0x800a
/*  f09a968:	012c6821 */ 	addu	$t5,$t1,$t4
/*  f09a96c:	8dae0fb4 */ 	lw	$t6,0xfb4($t5)
/*  f09a970:	8c429fc8 */ 	lw	$v0,-0x6038($v0)
/*  f09a974:	104e0011 */ 	beq	$v0,$t6,.L0f09a9bc
/*  f09a978:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a97c:	8e0f01d4 */ 	lw	$t7,0x1d4($s0)
/*  f09a980:	01e2082a */ 	slt	$at,$t7,$v0
/*  f09a984:	1020000d */ 	beqz	$at,.L0f09a9bc
/*  f09a988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a98c:	0fc2c78a */ 	jal	func0f0b1e28
/*  f09a990:	02002025 */ 	or	$a0,$s0,$zero
/*  f09a994:	3c18800a */ 	lui	$t8,0x800a
/*  f09a998:	8f189fc8 */ 	lw	$t8,-0x6038($t8)
/*  f09a99c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f09a9a0:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f09a9a4:	10000005 */ 	beqz	$zero,.L0f09a9bc
/*  f09a9a8:	ae1901d4 */ 	sw	$t9,0x1d4($s0)
.L0f09a9ac:
/*  f09a9ac:	82080004 */ 	lb	$t0,0x4($s0)
/*  f09a9b0:	11000002 */ 	beqz	$t0,.L0f09a9bc
/*  f09a9b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a9b8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f09a9bc:
/*  f09a9bc:	50600075 */ 	beqzl	$v1,.L0f09ab94
/*  f09a9c0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f09a9c4:	0c012230 */ 	jal	func000488c0
/*  f09a9c8:	00002025 */ 	or	$a0,$zero,$zero
/*  f09a9cc:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*  f09a9d0:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f09a9d4:	0c012230 */ 	jal	func000488c0
/*  f09a9d8:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
/*  f09a9dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f09a9e0:	0c01210c */ 	jal	func00048430
/*  f09a9e4:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f09a9e8:	8e0401cc */ 	lw	$a0,0x1cc($s0)
/*  f09a9ec:	50800008 */ 	beqzl	$a0,.L0f09aa10
/*  f09a9f0:	8e0401d0 */ 	lw	$a0,0x1d0($s0)
/*  f09a9f4:	0c00cdfc */ 	jal	func000337f0
/*  f09a9f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09a9fc:	50400004 */ 	beqzl	$v0,.L0f09aa10
/*  f09aa00:	8e0401d0 */ 	lw	$a0,0x1d0($s0)
/*  f09aa04:	0c00cec9 */ 	jal	func00033b24
/*  f09aa08:	8e0401cc */ 	lw	$a0,0x1cc($s0)
/*  f09aa0c:	8e0401d0 */ 	lw	$a0,0x1d0($s0)
.L0f09aa10:
/*  f09aa10:	10800007 */ 	beqz	$a0,.L0f09aa30
/*  f09aa14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09aa18:	0c00cdfc */ 	jal	func000337f0
/*  f09aa1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09aa20:	10400003 */ 	beqz	$v0,.L0f09aa30
/*  f09aa24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09aa28:	0c00cec9 */ 	jal	func00033b24
/*  f09aa2c:	8e0401d0 */ 	lw	$a0,0x1d0($s0)
.L0f09aa30:
/*  f09aa30:	0fc2c79a */ 	jal	func0f0b1e68
/*  f09aa34:	02002025 */ 	or	$a0,$s0,$zero
/*  f09aa38:	50400053 */ 	beqzl	$v0,.L0f09ab88
/*  f09aa3c:	00002025 */ 	or	$a0,$zero,$zero
/*  f09aa40:	8e0a01cc */ 	lw	$t2,0x1cc($s0)
/*  f09aa44:	00002025 */ 	or	$a0,$zero,$zero
/*  f09aa48:	55400017 */ 	bnezl	$t2,.L0f09aaa8
/*  f09aa4c:	8e0e01d0 */ 	lw	$t6,0x1d0($s0)
/*  f09aa50:	0fc2c79a */ 	jal	func0f0b1e68
/*  f09aa54:	02002025 */ 	or	$a0,$s0,$zero
/*  f09aa58:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09aa5c:	44814000 */ 	mtc1	$at,$f8
/*  f09aa60:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f09aa64:	00055c03 */ 	sra	$t3,$a1,0x10
/*  f09aa68:	3c048009 */ 	lui	$a0,0x8009
/*  f09aa6c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f09aa70:	240cffff */ 	addiu	$t4,$zero,-1
/*  f09aa74:	240dffff */ 	addiu	$t5,$zero,-1
/*  f09aa78:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f09aa7c:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f09aa80:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f09aa84:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09aa88:	01602825 */ 	or	$a1,$t3,$zero
/*  f09aa8c:	260601cc */ 	addiu	$a2,$s0,0x1cc
/*  f09aa90:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09aa94:	0c004241 */ 	jal	func00010904
/*  f09aa98:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f09aa9c:	10000018 */ 	beqz	$zero,.L0f09ab00
/*  f09aaa0:	00402025 */ 	or	$a0,$v0,$zero
/*  f09aaa4:	8e0e01d0 */ 	lw	$t6,0x1d0($s0)
.L0f09aaa8:
/*  f09aaa8:	55c00016 */ 	bnezl	$t6,.L0f09ab04
/*  f09aaac:	920b0000 */ 	lbu	$t3,0x0($s0)
/*  f09aab0:	0fc2c79a */ 	jal	func0f0b1e68
/*  f09aab4:	02002025 */ 	or	$a0,$s0,$zero
/*  f09aab8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09aabc:	44815000 */ 	mtc1	$at,$f10
/*  f09aac0:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f09aac4:	00057c03 */ 	sra	$t7,$a1,0x10
/*  f09aac8:	3c048009 */ 	lui	$a0,0x8009
/*  f09aacc:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f09aad0:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f09aad4:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f09aad8:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f09aadc:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f09aae0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f09aae4:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09aae8:	01e02825 */ 	or	$a1,$t7,$zero
/*  f09aaec:	260601d0 */ 	addiu	$a2,$s0,0x1d0
/*  f09aaf0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09aaf4:	0c004241 */ 	jal	func00010904
/*  f09aaf8:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f09aafc:	00402025 */ 	or	$a0,$v0,$zero
.L0f09ab00:
/*  f09ab00:	920b0000 */ 	lbu	$t3,0x0($s0)
.L0f09ab04:
/*  f09ab04:	3c0a800a */ 	lui	$t2,0x800a
/*  f09ab08:	8d4a9fc8 */ 	lw	$t2,-0x6038($t2)
/*  f09ab0c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f09ab10:	1561001c */ 	bne	$t3,$at,.L0f09ab84
/*  f09ab14:	ae0a01d8 */ 	sw	$t2,0x1d8($s0)
/*  f09ab18:	5080001b */ 	beqzl	$a0,.L0f09ab88
/*  f09ab1c:	00002025 */ 	or	$a0,$zero,$zero
/*  f09ab20:	c612023c */ 	lwc1	$f18,0x23c($s0)
/*  f09ab24:	3c013f80 */ 	lui	$at,0x3f80
/*  f09ab28:	44816000 */ 	mtc1	$at,$f12
/*  f09ab2c:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f09ab30:	3c014040 */ 	lui	$at,0x4040
/*  f09ab34:	44814000 */ 	mtc1	$at,$f8
/*  f09ab38:	3c017f1b */ 	lui	$at,%hi(var7f1ac320)
/*  f09ab3c:	44028000 */ 	mfc1	$v0,$f16
/*  f09ab40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ab44:	44822000 */ 	mtc1	$v0,$f4
/*  f09ab48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ab4c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f09ab50:	46083083 */ 	div.s	$f2,$f6,$f8
/*  f09ab54:	4602603c */ 	c.lt.s	$f12,$f2
/*  f09ab58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ab5c:	45000002 */ 	bc1f	.L0f09ab68
/*  f09ab60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ab64:	46006086 */ 	mov.s	$f2,$f12
.L0f09ab68:
/*  f09ab68:	c42ac320 */ 	lwc1	$f10,%lo(var7f1ac320)($at)
/*  f09ab6c:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f09ab70:	460a1482 */ 	mul.s	$f18,$f2,$f10
/*  f09ab74:	46126401 */ 	sub.s	$f16,$f12,$f18
/*  f09ab78:	e7b00034 */ 	swc1	$f16,0x34($sp)
/*  f09ab7c:	0c00cf94 */ 	jal	func00033e50
/*  f09ab80:	8fa60034 */ 	lw	$a2,0x34($sp)
.L0f09ab84:
/*  f09ab84:	00002025 */ 	or	$a0,$zero,$zero
.L0f09ab88:
/*  f09ab88:	0c01210c */ 	jal	func00048430
/*  f09ab8c:	8fa50040 */ 	lw	$a1,0x40($sp)
.L0f09ab90:
/*  f09ab90:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f09ab94:
/*  f09ab94:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f09ab98:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f09ab9c:	03e00008 */ 	jr	$ra
/*  f09aba0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09aba4
/*  f09aba4:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f09aba8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f09abac:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f09abb0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f09abb4:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f09abb8:	80ee0024 */ 	lb	$t6,0x24($a3)
/*  f09abbc:	00808025 */ 	or	$s0,$a0,$zero
/*  f09abc0:	afae005c */ 	sw	$t6,0x5c($sp)
/*  f09abc4:	80ef0025 */ 	lb	$t7,0x25($a3)
/*  f09abc8:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f09abcc:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f09abd0:	afaf0058 */ 	sw	$t7,0x58($sp)
/*  f09abd4:	80e80027 */ 	lb	$t0,0x27($a3)
/*  f09abd8:	80e20026 */ 	lb	$v0,0x26($a3)
/*  f09abdc:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f09abe0:	80e90018 */ 	lb	$t1,0x18($a3)
/*  f09abe4:	afa90048 */ 	sw	$t1,0x48($sp)
/*  f09abe8:	8caa0004 */ 	lw	$t2,0x4($a1)
/*  f09abec:	afaa0040 */ 	sw	$t2,0x40($sp)
/*  f09abf0:	8c8c06a8 */ 	lw	$t4,0x6a8($a0)
/*  f09abf4:	8c8b0614 */ 	lw	$t3,0x614($a0)
/*  f09abf8:	1c600003 */ 	bgtz	$v1,.L0f09ac08
/*  f09abfc:	016c8823 */ 	subu	$s1,$t3,$t4
/*  f09ac00:	100000dc */ 	beqz	$zero,.L0f09af74
/*  f09ac04:	afa00054 */ 	sw	$zero,0x54($sp)
.L0f09ac08:
/*  f09ac08:	8e0d0014 */ 	lw	$t5,0x14($s0)
/*  f09ac0c:	51a00023 */ 	beqzl	$t5,.L0f09ac9c
/*  f09ac10:	8e09060c */ 	lw	$t1,0x60c($s0)
/*  f09ac14:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f09ac18:	0222082a */ 	slt	$at,$s1,$v0
/*  f09ac1c:	51c0001f */ 	beqzl	$t6,.L0f09ac9c
/*  f09ac20:	8e09060c */ 	lw	$t1,0x60c($s0)
/*  f09ac24:	5420001d */ 	bnezl	$at,.L0f09ac9c
/*  f09ac28:	8e09060c */ 	lw	$t1,0x60c($s0)
/*  f09ac2c:	1840001a */ 	blez	$v0,.L0f09ac98
/*  f09ac30:	8faf004c */ 	lw	$t7,0x4c($sp)
/*  f09ac34:	05e20019 */ 	bltzl	$t7,.L0f09ac9c
/*  f09ac38:	8e09060c */ 	lw	$t1,0x60c($s0)
/*  f09ac3c:	8e02060c */ 	lw	$v0,0x60c($s0)
/*  f09ac40:	022fc821 */ 	addu	$t9,$s1,$t7
/*  f09ac44:	0323082a */ 	slt	$at,$t9,$v1
/*  f09ac48:	30580040 */ 	andi	$t8,$v0,0x40
/*  f09ac4c:	57000013 */ 	bnezl	$t8,.L0f09ac9c
/*  f09ac50:	8e09060c */ 	lw	$t1,0x60c($s0)
/*  f09ac54:	10200010 */ 	beqz	$at,.L0f09ac98
/*  f09ac58:	34480040 */ 	ori	$t0,$v0,0x40
/*  f09ac5c:	44807000 */ 	mtc1	$zero,$f14
/*  f09ac60:	c6040070 */ 	lwc1	$f4,0x70($s0)
/*  f09ac64:	c6060064 */ 	lwc1	$f6,0x64($s0)
/*  f09ac68:	c6080068 */ 	lwc1	$f8,0x68($s0)
/*  f09ac6c:	c60a006c */ 	lwc1	$f10,0x6c($s0)
/*  f09ac70:	ae08060c */ 	sw	$t0,0x60c($s0)
/*  f09ac74:	ae1106a8 */ 	sw	$s1,0x6a8($s0)
/*  f09ac78:	e6040050 */ 	swc1	$f4,0x50($s0)
/*  f09ac7c:	e60e0060 */ 	swc1	$f14,0x60($s0)
/*  f09ac80:	e60e0054 */ 	swc1	$f14,0x54($s0)
/*  f09ac84:	e60e0058 */ 	swc1	$f14,0x58($s0)
/*  f09ac88:	e60e005c */ 	swc1	$f14,0x5c($s0)
/*  f09ac8c:	e6060044 */ 	swc1	$f6,0x44($s0)
/*  f09ac90:	e6080048 */ 	swc1	$f8,0x48($s0)
/*  f09ac94:	e60a004c */ 	swc1	$f10,0x4c($s0)
.L0f09ac98:
/*  f09ac98:	8e09060c */ 	lw	$t1,0x60c($s0)
.L0f09ac9c:
/*  f09ac9c:	312a0040 */ 	andi	$t2,$t1,0x40
/*  f09aca0:	51400042 */ 	beqzl	$t2,.L0f09adac
/*  f09aca4:	0223082a */ 	slt	$at,$s1,$v1
/*  f09aca8:	8e0206a8 */ 	lw	$v0,0x6a8($s0)
/*  f09acac:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f09acb0:	02225823 */ 	subu	$t3,$s1,$v0
/*  f09acb4:	016c082a */ 	slt	$at,$t3,$t4
/*  f09acb8:	10200036 */ 	beqz	$at,.L0f09ad94
/*  f09acbc:	01916823 */ 	subu	$t5,$t4,$s1
/*  f09acc0:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f09acc4:	448e2000 */ 	mtc1	$t6,$f4
/*  f09acc8:	3c017f1b */ 	lui	$at,%hi(var7f1ac324)
/*  f09accc:	c428c324 */ 	lwc1	$f8,%lo(var7f1ac324)($at)
/*  f09acd0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f09acd4:	448c2000 */ 	mtc1	$t4,$f4
/*  f09acd8:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f09acdc:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f09ace0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f09ace4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f09ace8:	0c0068f4 */ 	jal	func0001a3d0
/*  f09acec:	46065303 */ 	div.s	$f12,$f10,$f6
/*  f09acf0:	3c013f00 */ 	lui	$at,0x3f00
/*  f09acf4:	44818000 */ 	mtc1	$at,$f16
/*  f09acf8:	c60c0050 */ 	lwc1	$f12,0x50($s0)
/*  f09acfc:	c60e0060 */ 	lwc1	$f14,0x60($s0)
/*  f09ad00:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f09ad04:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f09ad08:	44069000 */ 	mfc1	$a2,$f18
/*  f09ad0c:	0c006bfa */ 	jal	func0001afe8
/*  f09ad10:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f09ad14:	c6020044 */ 	lwc1	$f2,0x44($s0)
/*  f09ad18:	c6040054 */ 	lwc1	$f4,0x54($s0)
/*  f09ad1c:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f09ad20:	c60e0048 */ 	lwc1	$f14,0x48($s0)
/*  f09ad24:	46022281 */ 	sub.s	$f10,$f4,$f2
/*  f09ad28:	c6040058 */ 	lwc1	$f4,0x58($s0)
/*  f09ad2c:	c610004c */ 	lwc1	$f16,0x4c($s0)
/*  f09ad30:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f09ad34:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f09ad38:	460e2281 */ 	sub.s	$f10,$f4,$f14
/*  f09ad3c:	c604005c */ 	lwc1	$f4,0x5c($s0)
/*  f09ad40:	e6000070 */ 	swc1	$f0,0x70($s0)
/*  f09ad44:	ae1800b4 */ 	sw	$t8,0xb4($s0)
/*  f09ad48:	26050074 */ 	addiu	$a1,$s0,0x74
/*  f09ad4c:	46000306 */ 	mov.s	$f12,$f0
/*  f09ad50:	46023200 */ 	add.s	$f8,$f6,$f2
/*  f09ad54:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f09ad58:	46102281 */ 	sub.s	$f10,$f4,$f16
/*  f09ad5c:	e6080064 */ 	swc1	$f8,0x64($s0)
/*  f09ad60:	460e3200 */ 	add.s	$f8,$f6,$f14
/*  f09ad64:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f09ad68:	e6080068 */ 	swc1	$f8,0x68($s0)
/*  f09ad6c:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f09ad70:	e608006c */ 	swc1	$f8,0x6c($s0)
/*  f09ad74:	0c0058ba */ 	jal	func000162e8
/*  f09ad78:	afa50020 */ 	sw	$a1,0x20($sp)
/*  f09ad7c:	26040064 */ 	addiu	$a0,$s0,0x64
/*  f09ad80:	0c005775 */ 	jal	func00015dd4
/*  f09ad84:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f09ad88:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f09ad8c:	10000006 */ 	beqz	$zero,.L0f09ada8
/*  f09ad90:	8fa7006c */ 	lw	$a3,0x6c($sp)
.L0f09ad94:
/*  f09ad94:	0c00566c */ 	jal	func000159b0
/*  f09ad98:	26040074 */ 	addiu	$a0,$s0,0x74
/*  f09ad9c:	ae0000b4 */ 	sw	$zero,0xb4($s0)
/*  f09ada0:	1000008b */ 	beqz	$zero,.L0f09afd0
/*  f09ada4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09ada8:
/*  f09ada8:	0223082a */ 	slt	$at,$s1,$v1
.L0f09adac:
/*  f09adac:	50200072 */ 	beqzl	$at,.L0f09af78
/*  f09adb0:	8fb80054 */ 	lw	$t8,0x54($sp)
/*  f09adb4:	8e02060c */ 	lw	$v0,0x60c($s0)
/*  f09adb8:	26190074 */ 	addiu	$t9,$s0,0x74
/*  f09adbc:	26080064 */ 	addiu	$t0,$s0,0x64
/*  f09adc0:	304f0040 */ 	andi	$t7,$v0,0x40
/*  f09adc4:	15e0006b */ 	bnez	$t7,.L0f09af74
/*  f09adc8:	30490080 */ 	andi	$t1,$v0,0x80
/*  f09adcc:	c4e20028 */ 	lwc1	$f2,0x28($a3)
/*  f09add0:	c4e0002c */ 	lwc1	$f0,0x2c($a3)
/*  f09add4:	afa80028 */ 	sw	$t0,0x28($sp)
/*  f09add8:	1520000b */ 	bnez	$t1,.L0f09ae08
/*  f09addc:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f09ade0:	c6040070 */ 	lwc1	$f4,0x70($s0)
/*  f09ade4:	c60a0064 */ 	lwc1	$f10,0x64($s0)
/*  f09ade8:	c6060068 */ 	lwc1	$f6,0x68($s0)
/*  f09adec:	c608006c */ 	lwc1	$f8,0x6c($s0)
/*  f09adf0:	344a0080 */ 	ori	$t2,$v0,0x80
/*  f09adf4:	ae0a060c */ 	sw	$t2,0x60c($s0)
/*  f09adf8:	e6040050 */ 	swc1	$f4,0x50($s0)
/*  f09adfc:	e60a0044 */ 	swc1	$f10,0x44($s0)
/*  f09ae00:	e6060048 */ 	swc1	$f6,0x48($s0)
/*  f09ae04:	e608004c */ 	swc1	$f8,0x4c($s0)
.L0f09ae08:
/*  f09ae08:	3c017f1b */ 	lui	$at,%hi(var7f1ac328)
/*  f09ae0c:	c42cc328 */ 	lwc1	$f12,%lo(var7f1ac328)($at)
/*  f09ae10:	3c0143b4 */ 	lui	$at,0x43b4
/*  f09ae14:	44815000 */ 	mtc1	$at,$f10
/*  f09ae18:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f09ae1c:	460a2183 */ 	div.s	$f6,$f4,$f10
/*  f09ae20:	46066201 */ 	sub.s	$f8,$f12,$f6
/*  f09ae24:	e6080060 */ 	swc1	$f8,0x60($s0)
/*  f09ae28:	e7a20038 */ 	swc1	$f2,0x38($sp)
/*  f09ae2c:	0fc2c4c7 */ 	jal	func0f0b131c
/*  f09ae30:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f09ae34:	c60401c0 */ 	lwc1	$f4,0x1c0($s0)
/*  f09ae38:	c7a20038 */ 	lwc1	$f2,0x38($sp)
/*  f09ae3c:	3c01447a */ 	lui	$at,0x447a
/*  f09ae40:	46040281 */ 	sub.s	$f10,$f0,$f4
/*  f09ae44:	44816000 */ 	mtc1	$at,$f12
/*  f09ae48:	44802000 */ 	mtc1	$zero,$f4
/*  f09ae4c:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f09ae50:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f09ae54:	e6040058 */ 	swc1	$f4,0x58($s0)
/*  f09ae58:	0222082a */ 	slt	$at,$s1,$v0
/*  f09ae5c:	02226823 */ 	subu	$t5,$s1,$v0
/*  f09ae60:	460c3203 */ 	div.s	$f8,$f6,$f12
/*  f09ae64:	c60601c8 */ 	lwc1	$f6,0x1c8($s0)
/*  f09ae68:	e6080054 */ 	swc1	$f8,0x54($s0)
/*  f09ae6c:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f09ae70:	c56a0034 */ 	lwc1	$f10,0x34($t3)
/*  f09ae74:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f09ae78:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f09ae7c:	460c2283 */ 	div.s	$f10,$f4,$f12
/*  f09ae80:	1020000c */ 	beqz	$at,.L0f09aeb4
/*  f09ae84:	e60a005c */ 	swc1	$f10,0x5c($s0)
/*  f09ae88:	44913000 */ 	mtc1	$s1,$f6
/*  f09ae8c:	3c017f1b */ 	lui	$at,%hi(var7f1ac32c)
/*  f09ae90:	c424c32c */ 	lwc1	$f4,%lo(var7f1ac32c)($at)
/*  f09ae94:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f09ae98:	44823000 */ 	mtc1	$v0,$f6
/*  f09ae9c:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f09aea0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f09aea4:	0c0068f7 */ 	jal	func0001a3dc
/*  f09aea8:	46085303 */ 	div.s	$f12,$f10,$f8
/*  f09aeac:	10000010 */ 	beqz	$zero,.L0f09aef0
/*  f09aeb0:	46000486 */ 	mov.s	$f18,$f0
.L0f09aeb4:
/*  f09aeb4:	448d2000 */ 	mtc1	$t5,$f4
/*  f09aeb8:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f09aebc:	3c017f1b */ 	lui	$at,%hi(var7f1ac330)
/*  f09aec0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f09aec4:	c42ac330 */ 	lwc1	$f10,%lo(var7f1ac330)($at)
/*  f09aec8:	448e2000 */ 	mtc1	$t6,$f4
/*  f09aecc:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f09aed0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f09aed4:	0c0068f4 */ 	jal	func0001a3d0
/*  f09aed8:	46064303 */ 	div.s	$f12,$f8,$f6
/*  f09aedc:	3c013f00 */ 	lui	$at,0x3f00
/*  f09aee0:	44815000 */ 	mtc1	$at,$f10
/*  f09aee4:	44814000 */ 	mtc1	$at,$f8
/*  f09aee8:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f09aeec:	46082480 */ 	add.s	$f18,$f4,$f8
.L0f09aef0:
/*  f09aef0:	c60c0050 */ 	lwc1	$f12,0x50($s0)
/*  f09aef4:	c60e0060 */ 	lwc1	$f14,0x60($s0)
/*  f09aef8:	44069000 */ 	mfc1	$a2,$f18
/*  f09aefc:	0c006bfa */ 	jal	func0001afe8
/*  f09af00:	e7b20030 */ 	swc1	$f18,0x30($sp)
/*  f09af04:	c6020044 */ 	lwc1	$f2,0x44($s0)
/*  f09af08:	c6060054 */ 	lwc1	$f6,0x54($s0)
/*  f09af0c:	c7b20030 */ 	lwc1	$f18,0x30($sp)
/*  f09af10:	c60e0048 */ 	lwc1	$f14,0x48($s0)
/*  f09af14:	46023281 */ 	sub.s	$f10,$f6,$f2
/*  f09af18:	c6060058 */ 	lwc1	$f6,0x58($s0)
/*  f09af1c:	c610004c */ 	lwc1	$f16,0x4c($s0)
/*  f09af20:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f09af24:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f09af28:	460e3281 */ 	sub.s	$f10,$f6,$f14
/*  f09af2c:	c606005c */ 	lwc1	$f6,0x5c($s0)
/*  f09af30:	e6000070 */ 	swc1	$f0,0x70($s0)
/*  f09af34:	ae0c00b4 */ 	sw	$t4,0xb4($s0)
/*  f09af38:	46000306 */ 	mov.s	$f12,$f0
/*  f09af3c:	46022200 */ 	add.s	$f8,$f4,$f2
/*  f09af40:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f09af44:	46103281 */ 	sub.s	$f10,$f6,$f16
/*  f09af48:	e6080064 */ 	swc1	$f8,0x64($s0)
/*  f09af4c:	460e2200 */ 	add.s	$f8,$f4,$f14
/*  f09af50:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f09af54:	e6080068 */ 	swc1	$f8,0x68($s0)
/*  f09af58:	46102200 */ 	add.s	$f8,$f4,$f16
/*  f09af5c:	e608006c */ 	swc1	$f8,0x6c($s0)
/*  f09af60:	0c0058ba */ 	jal	func000162e8
/*  f09af64:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f09af68:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f09af6c:	0c005775 */ 	jal	func00015dd4
/*  f09af70:	8fa50020 */ 	lw	$a1,0x20($sp)
.L0f09af74:
/*  f09af74:	8fb80054 */ 	lw	$t8,0x54($sp)
.L0f09af78:
/*  f09af78:	8faf004c */ 	lw	$t7,0x4c($sp)
/*  f09af7c:	00001025 */ 	or	$v0,$zero,$zero
/*  f09af80:	0238082a */ 	slt	$at,$s1,$t8
/*  f09af84:	14200012 */ 	bnez	$at,.L0f09afd0
/*  f09af88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09af8c:	05e00009 */ 	bltz	$t7,.L0f09afb4
/*  f09af90:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f09af94:	8e190014 */ 	lw	$t9,0x14($s0)
/*  f09af98:	53200007 */ 	beqzl	$t9,.L0f09afb8
/*  f09af9c:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f09afa0:	8e08000c */ 	lw	$t0,0xc($s0)
/*  f09afa4:	51000004 */ 	beqzl	$t0,.L0f09afb8
/*  f09afa8:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f09afac:	10000008 */ 	beqz	$zero,.L0f09afd0
/*  f09afb0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09afb4:
/*  f09afb4:	8faa0048 */ 	lw	$t2,0x48($sp)
.L0f09afb8:
/*  f09afb8:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f09afbc:	022b082a */ 	slt	$at,$s1,$t3
/*  f09afc0:	14200003 */ 	bnez	$at,.L0f09afd0
/*  f09afc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09afc8:	10000001 */ 	beqz	$zero,.L0f09afd0
/*  f09afcc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09afd0:
/*  f09afd0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f09afd4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f09afd8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f09afdc:	03e00008 */ 	jr	$ra
/*  f09afe0:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f09afe4
/*  f09afe4:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f09afe8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f09afec:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f09aff0:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f09aff4:	00c08025 */ 	or	$s0,$a2,$zero
/*  f09aff8:	afa50074 */ 	sw	$a1,0x74($sp)
/*  f09affc:	0fc2c41f */ 	jal	func0f0b107c
/*  f09b000:	00c02025 */ 	or	$a0,$a2,$zero
/*  f09b004:	14400003 */ 	bnez	$v0,.L0f09b014
/*  f09b008:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f09b00c:	1000008f */ 	beqz	$zero,.L0f09b24c
/*  f09b010:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09b014:
/*  f09b014:	8e020608 */ 	lw	$v0,0x608($s0)
/*  f09b018:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f09b01c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f09b020:	14400023 */ 	bnez	$v0,.L0f09b0b0
/*  f09b024:	2484b8a4 */ 	addiu	$a0,$a0,-18268
/*  f09b028:	3c058007 */ 	lui	$a1,%hi(var80070128)
/*  f09b02c:	afae0064 */ 	sw	$t6,0x64($sp)
/*  f09b030:	0c0036cc */ 	jal	func0000db30
/*  f09b034:	24a50128 */ 	addiu	$a1,$a1,%lo(var80070128)
/*  f09b038:	8e0f0618 */ 	lw	$t7,0x618($s0)
/*  f09b03c:	55e00010 */ 	bnezl	$t7,.L0f09b080
/*  f09b040:	02002025 */ 	or	$a0,$s0,$zero
/*  f09b044:	44802000 */ 	mtc1	$zero,$f4
/*  f09b048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b04c:	e6040660 */ 	swc1	$f4,0x660($s0)
/*  f09b050:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f09b054:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f09b058:	8f04000c */ 	lw	$a0,0xc($t8)
/*  f09b05c:	50800007 */ 	beqzl	$a0,.L0f09b07c
/*  f09b060:	ae000558 */ 	sw	$zero,0x558($s0)
/*  f09b064:	0fc26238 */ 	jal	func0f0988e0
/*  f09b068:	02003025 */ 	or	$a2,$s0,$zero
/*  f09b06c:	92080690 */ 	lbu	$t0,0x690($s0)
/*  f09b070:	35090080 */ 	ori	$t1,$t0,0x80
/*  f09b074:	a2090690 */ 	sb	$t1,0x690($s0)
/*  f09b078:	ae000558 */ 	sw	$zero,0x558($s0)
.L0f09b07c:
/*  f09b07c:	02002025 */ 	or	$a0,$s0,$zero
.L0f09b080:
/*  f09b080:	0fc26291 */ 	jal	func0f098a44
/*  f09b084:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f09b088:	14400002 */ 	bnez	$v0,.L0f09b094
/*  f09b08c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f09b090:	afa00064 */ 	sw	$zero,0x64($sp)
.L0f09b094:
/*  f09b094:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f09b098:	51400003 */ 	beqzl	$t2,.L0f09b0a8
/*  f09b09c:	c6060660 */ 	lwc1	$f6,0x660($s0)
/*  f09b0a0:	ae0b0608 */ 	sw	$t3,0x608($s0)
/*  f09b0a4:	c6060660 */ 	lwc1	$f6,0x660($s0)
.L0f09b0a8:
/*  f09b0a8:	8e020608 */ 	lw	$v0,0x608($s0)
/*  f09b0ac:	e6060240 */ 	swc1	$f6,0x240($s0)
.L0f09b0b0:
/*  f09b0b0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09b0b4:	1441003a */ 	bne	$v0,$at,.L0f09b1a0
/*  f09b0b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f09b0bc:	0fc268fe */ 	jal	func0f09a3f8
/*  f09b0c0:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f09b0c4:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f09b0c8:	24010100 */ 	addiu	$at,$zero,0x100
/*  f09b0cc:	00401825 */ 	or	$v1,$v0,$zero
/*  f09b0d0:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f09b0d4:	31aeff00 */ 	andi	$t6,$t5,0xff00
/*  f09b0d8:	15c10010 */ 	bne	$t6,$at,.L0f09b11c
/*  f09b0dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b0e0:	8d840048 */ 	lw	$a0,0x48($t4)
/*  f09b0e4:	1080000d */ 	beqz	$a0,.L0f09b11c
/*  f09b0e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b0ec:	8d85004c */ 	lw	$a1,0x4c($t4)
/*  f09b0f0:	27a7002c */ 	addiu	$a3,$sp,0x2c
/*  f09b0f4:	10a00009 */ 	beqz	$a1,.L0f09b11c
/*  f09b0f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b0fc:	8e060660 */ 	lw	$a2,0x660($s0)
/*  f09b100:	0fc25ed9 */ 	jal	func0f097b64
/*  f09b104:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f09b108:	26040254 */ 	addiu	$a0,$s0,0x254
/*  f09b10c:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*  f09b110:	0fc25ed0 */ 	jal	func0f097b40
/*  f09b114:	26060284 */ 	addiu	$a2,$s0,0x284
/*  f09b118:	8fa30060 */ 	lw	$v1,0x60($sp)
.L0f09b11c:
/*  f09b11c:	18600007 */ 	blez	$v1,.L0f09b13c
/*  f09b120:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f09b124:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f09b128:	02003025 */ 	or	$a2,$s0,$zero
/*  f09b12c:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f09b130:	0fc269be */ 	jal	func0f09a6f8
/*  f09b134:	afa30060 */ 	sw	$v1,0x60($sp)
/*  f09b138:	8fa30060 */ 	lw	$v1,0x60($sp)
.L0f09b13c:
/*  f09b13c:	04600002 */ 	bltz	$v1,.L0f09b148
/*  f09b140:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09b144:	14610002 */ 	bne	$v1,$at,.L0f09b150
.L0f09b148:
/*  f09b148:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f09b14c:	ae0f0608 */ 	sw	$t7,0x608($s0)
.L0f09b150:
/*  f09b150:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f09b154:	c6080660 */ 	lwc1	$f8,0x660($s0)
/*  f09b158:	3c017f1b */ 	lui	$at,%hi(var7f1ac334)
/*  f09b15c:	13000008 */ 	beqz	$t8,.L0f09b180
/*  f09b160:	e6080240 */ 	swc1	$f8,0x240($s0)
/*  f09b164:	c420c334 */ 	lwc1	$f0,%lo(var7f1ac334)($at)
/*  f09b168:	c60a0240 */ 	lwc1	$f10,0x240($s0)
/*  f09b16c:	4600503c */ 	c.lt.s	$f10,$f0
/*  f09b170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b174:	45020003 */ 	bc1fl	.L0f09b184
/*  f09b178:	8e190014 */ 	lw	$t9,0x14($s0)
/*  f09b17c:	e6000240 */ 	swc1	$f0,0x240($s0)
.L0f09b180:
/*  f09b180:	8e190014 */ 	lw	$t9,0x14($s0)
.L0f09b184:
/*  f09b184:	13200004 */ 	beqz	$t9,.L0f09b198
/*  f09b188:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b18c:	92080690 */ 	lbu	$t0,0x690($s0)
/*  f09b190:	3109ff7f */ 	andi	$t1,$t0,0xff7f
/*  f09b194:	a2090690 */ 	sb	$t1,0x690($s0)
.L0f09b198:
/*  f09b198:	1000002c */ 	beqz	$zero,.L0f09b24c
/*  f09b19c:	00001025 */ 	or	$v0,$zero,$zero
.L0f09b1a0:
/*  f09b1a0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09b1a4:	54410029 */ 	bnel	$v0,$at,.L0f09b24c
/*  f09b1a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f09b1ac:	8e0a060c */ 	lw	$t2,0x60c($s0)
/*  f09b1b0:	02002025 */ 	or	$a0,$s0,$zero
/*  f09b1b4:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f09b1b8:	314b0020 */ 	andi	$t3,$t2,0x20
/*  f09b1bc:	11600007 */ 	beqz	$t3,.L0f09b1dc
/*  f09b1c0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f09b1c4:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f09b1c8:	0fc26ae9 */ 	jal	func0f09aba4
/*  f09b1cc:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f09b1d0:	00401825 */ 	or	$v1,$v0,$zero
/*  f09b1d4:	10000002 */ 	beqz	$zero,.L0f09b1e0
/*  f09b1d8:	c6000660 */ 	lwc1	$f0,0x660($s0)
.L0f09b1dc:
/*  f09b1dc:	c6000660 */ 	lwc1	$f0,0x660($s0)
.L0f09b1e0:
/*  f09b1e0:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f09b1e4:	24010013 */ 	addiu	$at,$zero,0x13
/*  f09b1e8:	15a10006 */ 	bne	$t5,$at,.L0f09b204
/*  f09b1ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b1f0:	8e0e068c */ 	lw	$t6,0x68c($s0)
/*  f09b1f4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09b1f8:	15c10002 */ 	bne	$t6,$at,.L0f09b204
/*  f09b1fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b200:	00001825 */ 	or	$v1,$zero,$zero
.L0f09b204:
/*  f09b204:	10600007 */ 	beqz	$v1,.L0f09b224
/*  f09b208:	e6000240 */ 	swc1	$f0,0x240($s0)
/*  f09b20c:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f09b210:	55800005 */ 	bnezl	$t4,.L0f09b228
/*  f09b214:	920f0000 */ 	lbu	$t7,0x0($s0)
/*  f09b218:	44808000 */ 	mtc1	$zero,$f16
/*  f09b21c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b220:	e6100240 */ 	swc1	$f16,0x240($s0)
.L0f09b224:
/*  f09b224:	920f0000 */ 	lbu	$t7,0x0($s0)
.L0f09b228:
/*  f09b228:	24010006 */ 	addiu	$at,$zero,0x6
/*  f09b22c:	15e10004 */ 	bne	$t7,$at,.L0f09b240
/*  f09b230:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b234:	44809000 */ 	mtc1	$zero,$f18
/*  f09b238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b23c:	e612023c */ 	swc1	$f18,0x23c($s0)
.L0f09b240:
/*  f09b240:	10000002 */ 	beqz	$zero,.L0f09b24c
/*  f09b244:	00601025 */ 	or	$v0,$v1,$zero
/*  f09b248:	00001025 */ 	or	$v0,$zero,$zero
.L0f09b24c:
/*  f09b24c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f09b250:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f09b254:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f09b258:	03e00008 */ 	jr	$ra
/*  f09b25c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09b260
/*  f09b260:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f09b264:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f09b268:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f09b26c:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f09b270:	00a08025 */ 	or	$s0,$a1,$zero
/*  f09b274:	0fc2c41f */ 	jal	func0f0b107c
/*  f09b278:	00a02025 */ 	or	$a0,$a1,$zero
/*  f09b27c:	14400003 */ 	bnez	$v0,.L0f09b28c
/*  f09b280:	00403825 */ 	or	$a3,$v0,$zero
/*  f09b284:	1000008f */ 	beqz	$zero,.L0f09b4c4
/*  f09b288:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09b28c:
/*  f09b28c:	8e030608 */ 	lw	$v1,0x608($s0)
/*  f09b290:	54600037 */ 	bnezl	$v1,.L0f09b370
/*  f09b294:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f09b298:	8e0e0618 */ 	lw	$t6,0x618($s0)
/*  f09b29c:	55c0001d */ 	bnezl	$t6,.L0f09b314
/*  f09b2a0:	8cee000c */ 	lw	$t6,0xc($a3)
/*  f09b2a4:	8c4f0010 */ 	lw	$t7,0x10($v0)
/*  f09b2a8:	000fc340 */ 	sll	$t8,$t7,0xd
/*  f09b2ac:	0703000d */ 	bgezl	$t8,.L0f09b2e4
/*  f09b2b0:	8c4a000c */ 	lw	$t2,0xc($v0)
/*  f09b2b4:	0fc447a9 */ 	jal	func0f111ea4
/*  f09b2b8:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f09b2bc:	3c02800a */ 	lui	$v0,0x800a
/*  f09b2c0:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f09b2c4:	90481583 */ 	lbu	$t0,0x1583($v0)
/*  f09b2c8:	35090008 */ 	ori	$t1,$t0,0x8
/*  f09b2cc:	0fc286ac */ 	jal	func0f0a1ab0
/*  f09b2d0:	a0491583 */ 	sb	$t1,0x1583($v0)
/*  f09b2d4:	a60006d4 */ 	sh	$zero,0x6d4($s0)
/*  f09b2d8:	1000007a */ 	beqz	$zero,.L0f09b4c4
/*  f09b2dc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09b2e0:	8c4a000c */ 	lw	$t2,0xc($v0)
.L0f09b2e4:
/*  f09b2e4:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f09b2e8:	02003025 */ 	or	$a2,$s0,$zero
/*  f09b2ec:	51400009 */ 	beqzl	$t2,.L0f09b314
/*  f09b2f0:	8cee000c */ 	lw	$t6,0xc($a3)
/*  f09b2f4:	8ce4000c */ 	lw	$a0,0xc($a3)
/*  f09b2f8:	0fc26238 */ 	jal	func0f0988e0
/*  f09b2fc:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f09b300:	920c0690 */ 	lbu	$t4,0x690($s0)
/*  f09b304:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f09b308:	358d0080 */ 	ori	$t5,$t4,0x80
/*  f09b30c:	a20d0690 */ 	sb	$t5,0x690($s0)
/*  f09b310:	8cee000c */ 	lw	$t6,0xc($a3)
.L0f09b314:
/*  f09b314:	02002025 */ 	or	$a0,$s0,$zero
/*  f09b318:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f09b31c:	11c00012 */ 	beqz	$t6,.L0f09b368
/*  f09b320:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f09b324:	8e0f0014 */ 	lw	$t7,0x14($s0)
/*  f09b328:	11e00004 */ 	beqz	$t7,.L0f09b33c
/*  f09b32c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b330:	92180690 */ 	lbu	$t8,0x690($s0)
/*  f09b334:	3319ff7f */ 	andi	$t9,$t8,0xff7f
/*  f09b338:	a2190690 */ 	sb	$t9,0x690($s0)
.L0f09b33c:
/*  f09b33c:	0fc26291 */ 	jal	func0f098a44
/*  f09b340:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f09b344:	10400006 */ 	beqz	$v0,.L0f09b360
/*  f09b348:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f09b34c:	92080690 */ 	lbu	$t0,0x690($s0)
/*  f09b350:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f09b354:	ae050608 */ 	sw	$a1,0x608($s0)
/*  f09b358:	3109ff7f */ 	andi	$t1,$t0,0xff7f
/*  f09b35c:	a2090690 */ 	sb	$t1,0x690($s0)
.L0f09b360:
/*  f09b360:	10000002 */ 	beqz	$zero,.L0f09b36c
/*  f09b364:	8e030608 */ 	lw	$v1,0x608($s0)
.L0f09b368:
/*  f09b368:	ae030608 */ 	sw	$v1,0x608($s0)
.L0f09b36c:
/*  f09b36c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f09b370:
/*  f09b370:	14a3000e */ 	bne	$a1,$v1,.L0f09b3ac
/*  f09b374:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09b378:	240a0003 */ 	addiu	$t2,$zero,0x3
/*  f09b37c:	a2050004 */ 	sb	$a1,0x4($s0)
/*  f09b380:	ae0a06ac */ 	sw	$t2,0x6ac($s0)
/*  f09b384:	80eb0007 */ 	lb	$t3,0x7($a3)
/*  f09b388:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f09b38c:	00001025 */ 	or	$v0,$zero,$zero
/*  f09b390:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f09b394:	020c1821 */ 	addu	$v1,$s0,$t4
/*  f09b398:	8c6d0220 */ 	lw	$t5,0x220($v1)
/*  f09b39c:	25aeffff */ 	addiu	$t6,$t5,-1
/*  f09b3a0:	ac6e0220 */ 	sw	$t6,0x220($v1)
/*  f09b3a4:	10000047 */ 	beqz	$zero,.L0f09b4c4
/*  f09b3a8:	ae0f0608 */ 	sw	$t7,0x608($s0)
.L0f09b3ac:
/*  f09b3ac:	1461001b */ 	bne	$v1,$at,.L0f09b41c
/*  f09b3b0:	24040037 */ 	addiu	$a0,$zero,0x37
/*  f09b3b4:	8cf8001c */ 	lw	$t8,0x1c($a3)
/*  f09b3b8:	8e190614 */ 	lw	$t9,0x614($s0)
/*  f09b3bc:	0319082a */ 	slt	$at,$t8,$t9
/*  f09b3c0:	50200004 */ 	beqzl	$at,.L0f09b3d4
/*  f09b3c4:	92080000 */ 	lbu	$t0,0x0($s0)
/*  f09b3c8:	1000003e */ 	beqz	$zero,.L0f09b4c4
/*  f09b3cc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09b3d0:	92080000 */ 	lbu	$t0,0x0($s0)
.L0f09b3d4:
/*  f09b3d4:	24010022 */ 	addiu	$at,$zero,0x22
/*  f09b3d8:	1501000e */ 	bne	$t0,$at,.L0f09b414
/*  f09b3dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b3e0:	0fc2a31f */ 	jal	func0f0a8c7c
/*  f09b3e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b3e8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f09b3ec:	14450009 */ 	bne	$v0,$a1,.L0f09b414
/*  f09b3f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b3f4:	8e090014 */ 	lw	$t1,0x14($s0)
/*  f09b3f8:	11200006 */ 	beqz	$t1,.L0f09b414
/*  f09b3fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b400:	8e0a000c */ 	lw	$t2,0xc($s0)
/*  f09b404:	11400003 */ 	beqz	$t2,.L0f09b414
/*  f09b408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b40c:	1000002d */ 	beqz	$zero,.L0f09b4c4
/*  f09b410:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09b414:
/*  f09b414:	1000002b */ 	beqz	$zero,.L0f09b4c4
/*  f09b418:	00001025 */ 	or	$v0,$zero,$zero
.L0f09b41c:
/*  f09b41c:	54830010 */ 	bnel	$a0,$v1,.L0f09b460
/*  f09b420:	920f0000 */ 	lbu	$t7,0x0($s0)
/*  f09b424:	02002025 */ 	or	$a0,$s0,$zero
/*  f09b428:	0fc26303 */ 	jal	func0f098c0c
/*  f09b42c:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f09b430:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f09b434:	8e0b0614 */ 	lw	$t3,0x614($s0)
/*  f09b438:	84ec0018 */ 	lh	$t4,0x18($a3)
/*  f09b43c:	258d00f0 */ 	addiu	$t5,$t4,0xf0
/*  f09b440:	01ab082a */ 	slt	$at,$t5,$t3
/*  f09b444:	10200003 */ 	beqz	$at,.L0f09b454
/*  f09b448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b44c:	1000001d */ 	beqz	$zero,.L0f09b4c4
/*  f09b450:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09b454:
/*  f09b454:	1000001b */ 	beqz	$zero,.L0f09b4c4
/*  f09b458:	00001025 */ 	or	$v0,$zero,$zero
/*  f09b45c:	920f0000 */ 	lbu	$t7,0x0($s0)
.L0f09b460:
/*  f09b460:	8e0e0614 */ 	lw	$t6,0x614($s0)
/*  f09b464:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f09b468:	15e10015 */ 	bne	$t7,$at,.L0f09b4c0
/*  f09b46c:	a60e06d4 */ 	sh	$t6,0x6d4($s0)
/*  f09b470:	92180003 */ 	lbu	$t8,0x3($s0)
/*  f09b474:	57000013 */ 	bnezl	$t8,.L0f09b4c4
/*  f09b478:	00001025 */ 	or	$v0,$zero,$zero
/*  f09b47c:	84f90018 */ 	lh	$t9,0x18($a3)
/*  f09b480:	860806d4 */ 	lh	$t0,0x6d4($s0)
/*  f09b484:	24090003 */ 	addiu	$t1,$zero,0x3
/*  f09b488:	0328082a */ 	slt	$at,$t9,$t0
/*  f09b48c:	5020000d */ 	beqzl	$at,.L0f09b4c4
/*  f09b490:	00001025 */ 	or	$v0,$zero,$zero
/*  f09b494:	a2050004 */ 	sb	$a1,0x4($s0)
/*  f09b498:	ae0906ac */ 	sw	$t1,0x6ac($s0)
/*  f09b49c:	80ea0007 */ 	lb	$t2,0x7($a3)
/*  f09b4a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f09b4a4:	000a6080 */ 	sll	$t4,$t2,0x2
/*  f09b4a8:	020c1821 */ 	addu	$v1,$s0,$t4
/*  f09b4ac:	8c6b0220 */ 	lw	$t3,0x220($v1)
/*  f09b4b0:	256dffff */ 	addiu	$t5,$t3,-1
/*  f09b4b4:	ac6d0220 */ 	sw	$t5,0x220($v1)
/*  f09b4b8:	10000002 */ 	beqz	$zero,.L0f09b4c4
/*  f09b4bc:	ae040608 */ 	sw	$a0,0x608($s0)
.L0f09b4c0:
/*  f09b4c0:	00001025 */ 	or	$v0,$zero,$zero
.L0f09b4c4:
/*  f09b4c4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f09b4c8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f09b4cc:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f09b4d0:	03e00008 */ 	jr	$ra
/*  f09b4d4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09b4d8
/*  f09b4d8:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f09b4dc:	14810006 */ 	bne	$a0,$at,.L0f09b4f8
/*  f09b4e0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09b4e4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09b4e8:	14a10003 */ 	bne	$a1,$at,.L0f09b4f8
/*  f09b4ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b4f0:	03e00008 */ 	jr	$ra
/*  f09b4f4:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f09b4f8:
/*  f09b4f8:	03e00008 */ 	jr	$ra
/*  f09b4fc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09b500
/*  f09b500:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f09b504:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f09b508:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f09b50c:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f09b510:	00a08025 */ 	or	$s0,$a1,$zero
/*  f09b514:	0fc2c41f */ 	jal	func0f0b107c
/*  f09b518:	00a02025 */ 	or	$a0,$a1,$zero
/*  f09b51c:	14400003 */ 	bnez	$v0,.L0f09b52c
/*  f09b520:	00403825 */ 	or	$a3,$v0,$zero
/*  f09b524:	100000bb */ 	beqz	$zero,.L0f09b814
/*  f09b528:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09b52c:
/*  f09b52c:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f09b530:	24010014 */ 	addiu	$at,$zero,0x14
/*  f09b534:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f09b538:	15c10027 */ 	bne	$t6,$at,.L0f09b5d8
/*  f09b53c:	24190004 */ 	addiu	$t9,$zero,0x4
/*  f09b540:	8e0f0618 */ 	lw	$t7,0x618($s0)
/*  f09b544:	3c017f1b */ 	lui	$at,%hi(var7f1ac338)
/*  f09b548:	55e00005 */ 	bnezl	$t7,.L0f09b560
/*  f09b54c:	8e080558 */ 	lw	$t0,0x558($s0)
/*  f09b550:	c424c338 */ 	lwc1	$f4,%lo(var7f1ac338)($at)
/*  f09b554:	ae000558 */ 	sw	$zero,0x558($s0)
/*  f09b558:	e6040240 */ 	swc1	$f4,0x240($s0)
/*  f09b55c:	8e080558 */ 	lw	$t0,0x558($s0)
.L0f09b560:
/*  f09b560:	8e0a000c */ 	lw	$t2,0xc($s0)
/*  f09b564:	a2180004 */ 	sb	$t8,0x4($s0)
/*  f09b568:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f09b56c:	ae1906ac */ 	sw	$t9,0x6ac($s0)
/*  f09b570:	11400013 */ 	beqz	$t2,.L0f09b5c0
/*  f09b574:	ae090558 */ 	sw	$t1,0x558($s0)
/*  f09b578:	3c013f80 */ 	lui	$at,0x3f80
/*  f09b57c:	44810000 */ 	mtc1	$at,$f0
/*  f09b580:	3c017f1b */ 	lui	$at,%hi(var7f1ac33c)
/*  f09b584:	c426c33c */ 	lwc1	$f6,%lo(var7f1ac33c)($at)
/*  f09b588:	3c01800a */ 	lui	$at,0x800a
/*  f09b58c:	c428a004 */ 	lwc1	$f8,-0x5ffc($at)
/*  f09b590:	c6100240 */ 	lwc1	$f16,0x240($s0)
/*  f09b594:	00001025 */ 	or	$v0,$zero,$zero
/*  f09b598:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f09b59c:	460a8480 */ 	add.s	$f18,$f16,$f10
/*  f09b5a0:	e6120240 */ 	swc1	$f18,0x240($s0)
/*  f09b5a4:	c6040240 */ 	lwc1	$f4,0x240($s0)
/*  f09b5a8:	4604003c */ 	c.lt.s	$f0,$f4
/*  f09b5ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b5b0:	45000007 */ 	bc1f	.L0f09b5d0
/*  f09b5b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b5b8:	10000096 */ 	beqz	$zero,.L0f09b814
/*  f09b5bc:	e6000240 */ 	swc1	$f0,0x240($s0)
.L0f09b5c0:
/*  f09b5c0:	44803000 */ 	mtc1	$zero,$f6
/*  f09b5c4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09b5c8:	10000092 */ 	beqz	$zero,.L0f09b814
/*  f09b5cc:	e6060240 */ 	swc1	$f6,0x240($s0)
.L0f09b5d0:
/*  f09b5d0:	10000090 */ 	beqz	$zero,.L0f09b814
/*  f09b5d4:	00001025 */ 	or	$v0,$zero,$zero
.L0f09b5d8:
/*  f09b5d8:	8e030608 */ 	lw	$v1,0x608($s0)
/*  f09b5dc:	5460002c */ 	bnezl	$v1,.L0f09b690
/*  f09b5e0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f09b5e4:	8e0b0618 */ 	lw	$t3,0x618($s0)
/*  f09b5e8:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f09b5ec:	240d000a */ 	addiu	$t5,$zero,0xa
/*  f09b5f0:	55600010 */ 	bnezl	$t3,.L0f09b634
/*  f09b5f4:	8ce8000c */ 	lw	$t0,0xc($a3)
/*  f09b5f8:	a20c0004 */ 	sb	$t4,0x4($s0)
/*  f09b5fc:	ae0d06ac */ 	sw	$t5,0x6ac($s0)
/*  f09b600:	8c4e000c */ 	lw	$t6,0xc($v0)
/*  f09b604:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f09b608:	02003025 */ 	or	$a2,$s0,$zero
/*  f09b60c:	51c00009 */ 	beqzl	$t6,.L0f09b634
/*  f09b610:	8ce8000c */ 	lw	$t0,0xc($a3)
/*  f09b614:	8ce4000c */ 	lw	$a0,0xc($a3)
/*  f09b618:	0fc26238 */ 	jal	func0f0988e0
/*  f09b61c:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f09b620:	92180690 */ 	lbu	$t8,0x690($s0)
/*  f09b624:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f09b628:	37190080 */ 	ori	$t9,$t8,0x80
/*  f09b62c:	a2190690 */ 	sb	$t9,0x690($s0)
/*  f09b630:	8ce8000c */ 	lw	$t0,0xc($a3)
.L0f09b634:
/*  f09b634:	02002025 */ 	or	$a0,$s0,$zero
/*  f09b638:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f09b63c:	11000012 */ 	beqz	$t0,.L0f09b688
/*  f09b640:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f09b644:	8e090014 */ 	lw	$t1,0x14($s0)
/*  f09b648:	11200004 */ 	beqz	$t1,.L0f09b65c
/*  f09b64c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b650:	920a0690 */ 	lbu	$t2,0x690($s0)
/*  f09b654:	314bff7f */ 	andi	$t3,$t2,0xff7f
/*  f09b658:	a20b0690 */ 	sb	$t3,0x690($s0)
.L0f09b65c:
/*  f09b65c:	0fc26291 */ 	jal	func0f098a44
/*  f09b660:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f09b664:	10400006 */ 	beqz	$v0,.L0f09b680
/*  f09b668:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f09b66c:	920d0690 */ 	lbu	$t5,0x690($s0)
/*  f09b670:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f09b674:	ae0c0608 */ 	sw	$t4,0x608($s0)
/*  f09b678:	31aeff7f */ 	andi	$t6,$t5,0xff7f
/*  f09b67c:	a20e0690 */ 	sb	$t6,0x690($s0)
.L0f09b680:
/*  f09b680:	10000002 */ 	beqz	$zero,.L0f09b68c
/*  f09b684:	8e030608 */ 	lw	$v1,0x608($s0)
.L0f09b688:
/*  f09b688:	ae030608 */ 	sw	$v1,0x608($s0)
.L0f09b68c:
/*  f09b68c:	24010003 */ 	addiu	$at,$zero,0x3
.L0f09b690:
/*  f09b690:	1461000b */ 	bne	$v1,$at,.L0f09b6c0
/*  f09b694:	02002025 */ 	or	$a0,$s0,$zero
/*  f09b698:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f09b69c:	0fc26291 */ 	jal	func0f098a44
/*  f09b6a0:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f09b6a4:	10400006 */ 	beqz	$v0,.L0f09b6c0
/*  f09b6a8:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f09b6ac:	92190690 */ 	lbu	$t9,0x690($s0)
/*  f09b6b0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f09b6b4:	ae180608 */ 	sw	$t8,0x608($s0)
/*  f09b6b8:	3328ff7f */ 	andi	$t0,$t9,0xff7f
/*  f09b6bc:	a2080690 */ 	sb	$t0,0x690($s0)
.L0f09b6c0:
/*  f09b6c0:	8e030608 */ 	lw	$v1,0x608($s0)
/*  f09b6c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09b6c8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f09b6cc:	14610036 */ 	bne	$v1,$at,.L0f09b7a8
/*  f09b6d0:	240a0004 */ 	addiu	$t2,$zero,0x4
/*  f09b6d4:	920b0000 */ 	lbu	$t3,0x0($s0)
/*  f09b6d8:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f09b6dc:	a2090004 */ 	sb	$t1,0x4($s0)
/*  f09b6e0:	1561001d */ 	bne	$t3,$at,.L0f09b758
/*  f09b6e4:	ae0a06ac */ 	sw	$t2,0x6ac($s0)
/*  f09b6e8:	80ec0007 */ 	lb	$t4,0x7($a3)
/*  f09b6ec:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f09b6f0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f09b6f4:	05820019 */ 	bltzl	$t4,.L0f09b75c
/*  f09b6f8:	8ce2000c */ 	lw	$v0,0xc($a3)
/*  f09b6fc:	0fc26d36 */ 	jal	func0f09b4d8
/*  f09b700:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f09b704:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f09b708:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f09b70c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f09b710:	80ed0007 */ 	lb	$t5,0x7($a3)
/*  f09b714:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f09b718:	020e1821 */ 	addu	$v1,$s0,$t6
/*  f09b71c:	8c6f0220 */ 	lw	$t7,0x220($v1)
/*  f09b720:	004f082a */ 	slt	$at,$v0,$t7
/*  f09b724:	5020000c */ 	beqzl	$at,.L0f09b758
/*  f09b728:	ac600220 */ 	sw	$zero,0x220($v1)
/*  f09b72c:	0fc26d36 */ 	jal	func0f09b4d8
/*  f09b730:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f09b734:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f09b738:	80f80007 */ 	lb	$t8,0x7($a3)
/*  f09b73c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f09b740:	02191821 */ 	addu	$v1,$s0,$t9
/*  f09b744:	8c680220 */ 	lw	$t0,0x220($v1)
/*  f09b748:	01024823 */ 	subu	$t1,$t0,$v0
/*  f09b74c:	10000002 */ 	beqz	$zero,.L0f09b758
/*  f09b750:	ac690220 */ 	sw	$t1,0x220($v1)
/*  f09b754:	ac600220 */ 	sw	$zero,0x220($v1)
.L0f09b758:
/*  f09b758:	8ce2000c */ 	lw	$v0,0xc($a3)
.L0f09b75c:
/*  f09b75c:	1040000b */ 	beqz	$v0,.L0f09b78c
/*  f09b760:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b764:	10400007 */ 	beqz	$v0,.L0f09b784
/*  f09b768:	02002025 */ 	or	$a0,$s0,$zero
/*  f09b76c:	0fc26291 */ 	jal	func0f098a44
/*  f09b770:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f09b774:	14400003 */ 	bnez	$v0,.L0f09b784
/*  f09b778:	240a0003 */ 	addiu	$t2,$zero,0x3
/*  f09b77c:	10000003 */ 	beqz	$zero,.L0f09b78c
/*  f09b780:	ae0a0608 */ 	sw	$t2,0x608($s0)
.L0f09b784:
/*  f09b784:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f09b788:	ae0b0608 */ 	sw	$t3,0x608($s0)
.L0f09b78c:
/*  f09b78c:	0fc41b99 */ 	jal	cheatIsActive
/*  f09b790:	00002025 */ 	or	$a0,$zero,$zero
/*  f09b794:	10400002 */ 	beqz	$v0,.L0f09b7a0
/*  f09b798:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f09b79c:	ae0c0608 */ 	sw	$t4,0x608($s0)
.L0f09b7a0:
/*  f09b7a0:	1000001c */ 	beqz	$zero,.L0f09b814
/*  f09b7a4:	00001025 */ 	or	$v0,$zero,$zero
.L0f09b7a8:
/*  f09b7a8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09b7ac:	14610019 */ 	bne	$v1,$at,.L0f09b814
/*  f09b7b0:	00001025 */ 	or	$v0,$zero,$zero
/*  f09b7b4:	0fc262ff */ 	jal	func0f098bfc
/*  f09b7b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f09b7bc:	14400003 */ 	bnez	$v0,.L0f09b7cc
/*  f09b7c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b7c4:	10000013 */ 	beqz	$zero,.L0f09b814
/*  f09b7c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09b7cc:
/*  f09b7cc:	0fc41b99 */ 	jal	cheatIsActive
/*  f09b7d0:	00002025 */ 	or	$a0,$zero,$zero
/*  f09b7d4:	50400008 */ 	beqzl	$v0,.L0f09b7f8
/*  f09b7d8:	8e0e0614 */ 	lw	$t6,0x614($s0)
/*  f09b7dc:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f09b7e0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09b7e4:	55a10004 */ 	bnel	$t5,$at,.L0f09b7f8
/*  f09b7e8:	8e0e0614 */ 	lw	$t6,0x614($s0)
/*  f09b7ec:	10000009 */ 	beqz	$zero,.L0f09b814
/*  f09b7f0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09b7f4:	8e0e0614 */ 	lw	$t6,0x614($s0)
.L0f09b7f8:
/*  f09b7f8:	29c1003d */ 	slti	$at,$t6,0x3d
/*  f09b7fc:	14200003 */ 	bnez	$at,.L0f09b80c
/*  f09b800:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b804:	10000003 */ 	beqz	$zero,.L0f09b814
/*  f09b808:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09b80c:
/*  f09b80c:	10000001 */ 	beqz	$zero,.L0f09b814
/*  f09b810:	00001025 */ 	or	$v0,$zero,$zero
.L0f09b814:
/*  f09b814:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f09b818:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f09b81c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f09b820:	03e00008 */ 	jr	$ra
/*  f09b824:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09b828
/*  f09b828:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f09b82c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f09b830:	0fc2c41f */ 	jal	func0f0b107c
/*  f09b834:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f09b838:	14400003 */ 	bnez	$v0,.L0f09b848
/*  f09b83c:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f09b840:	10000023 */ 	beqz	$zero,.L0f09b8d0
/*  f09b844:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09b848:
/*  f09b848:	8c830608 */ 	lw	$v1,0x608($a0)
/*  f09b84c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f09b850:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f09b854:	14600003 */ 	bnez	$v1,.L0f09b864
/*  f09b858:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09b85c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f09b860:	ac830608 */ 	sw	$v1,0x608($a0)
.L0f09b864:
/*  f09b864:	14c3000e */ 	bne	$a2,$v1,.L0f09b8a0
/*  f09b868:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b86c:	a0860004 */ 	sb	$a2,0x4($a0)
/*  f09b870:	8c4e0014 */ 	lw	$t6,0x14($v0)
/*  f09b874:	ac8e06ac */ 	sw	$t6,0x6ac($a0)
/*  f09b878:	80450007 */ 	lb	$a1,0x7($v0)
/*  f09b87c:	00001025 */ 	or	$v0,$zero,$zero
/*  f09b880:	04a00005 */ 	bltz	$a1,.L0f09b898
/*  f09b884:	00057880 */ 	sll	$t7,$a1,0x2
/*  f09b888:	008f1821 */ 	addu	$v1,$a0,$t7
/*  f09b88c:	8c780220 */ 	lw	$t8,0x220($v1)
/*  f09b890:	2719ffff */ 	addiu	$t9,$t8,-1
/*  f09b894:	ac790220 */ 	sw	$t9,0x220($v1)
.L0f09b898:
/*  f09b898:	1000000d */ 	beqz	$zero,.L0f09b8d0
/*  f09b89c:	ac880608 */ 	sw	$t0,0x608($a0)
.L0f09b8a0:
/*  f09b8a0:	5461000b */ 	bnel	$v1,$at,.L0f09b8d0
/*  f09b8a4:	00001025 */ 	or	$v0,$zero,$zero
/*  f09b8a8:	8c490018 */ 	lw	$t1,0x18($v0)
/*  f09b8ac:	8c8a0614 */ 	lw	$t2,0x614($a0)
/*  f09b8b0:	012a082a */ 	slt	$at,$t1,$t2
/*  f09b8b4:	10200003 */ 	beqz	$at,.L0f09b8c4
/*  f09b8b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b8bc:	10000004 */ 	beqz	$zero,.L0f09b8d0
/*  f09b8c0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09b8c4:
/*  f09b8c4:	10000002 */ 	beqz	$zero,.L0f09b8d0
/*  f09b8c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f09b8cc:	00001025 */ 	or	$v0,$zero,$zero
.L0f09b8d0:
/*  f09b8d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09b8d4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f09b8d8:	03e00008 */ 	jr	$ra
/*  f09b8dc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09b8e0
/*  f09b8e0:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f09b8e4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f09b8e8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f09b8ec:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f09b8f0:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f09b8f4:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f09b8f8:	afa00050 */ 	sw	$zero,0x50($sp)
/*  f09b8fc:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f09b900:	00c08025 */ 	or	$s0,$a2,$zero
/*  f09b904:	25f8fffe */ 	addiu	$t8,$t7,-2
/*  f09b908:	2f010024 */ 	sltiu	$at,$t8,0x24
/*  f09b90c:	1020003a */ 	beqz	$at,.L0f09b9f8
/*  f09b910:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f09b914:	3c017f1b */ 	lui	$at,%hi(var7f1ac340)
/*  f09b918:	00380821 */ 	addu	$at,$at,$t8
/*  f09b91c:	8c38c340 */ 	lw	$t8,%lo(var7f1ac340)($at)
/*  f09b920:	03000008 */ 	jr	$t8
/*  f09b924:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b928:	8e020614 */ 	lw	$v0,0x614($s0)
/*  f09b92c:	02002025 */ 	or	$a0,$s0,$zero
/*  f09b930:	2841001a */ 	slti	$at,$v0,0x1a
/*  f09b934:	14200004 */ 	bnez	$at,.L0f09b948
/*  f09b938:	2459ffe7 */ 	addiu	$t9,$v0,-25
/*  f09b93c:	ae190614 */ 	sw	$t9,0x614($s0)
/*  f09b940:	0fc26303 */ 	jal	func0f098c0c
/*  f09b944:	ae00060c */ 	sw	$zero,0x60c($s0)
.L0f09b948:
/*  f09b948:	8e08068c */ 	lw	$t0,0x68c($s0)
/*  f09b94c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09b950:	02002025 */ 	or	$a0,$s0,$zero
/*  f09b954:	11010022 */ 	beq	$t0,$at,.L0f09b9e0
/*  f09b958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b95c:	8e09060c */ 	lw	$t1,0x60c($s0)
/*  f09b960:	00002825 */ 	or	$a1,$zero,$zero
/*  f09b964:	8fab0058 */ 	lw	$t3,0x58($sp)
/*  f09b968:	312a0010 */ 	andi	$t2,$t1,0x10
/*  f09b96c:	15400013 */ 	bnez	$t2,.L0f09b9bc
/*  f09b970:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b974:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*  f09b978:	00001825 */ 	or	$v1,$zero,$zero
/*  f09b97c:	02002025 */ 	or	$a0,$s0,$zero
/*  f09b980:	11800005 */ 	beqz	$t4,.L0f09b998
/*  f09b984:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b988:	0fc2c41f */ 	jal	func0f0b107c
/*  f09b98c:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f09b990:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f09b994:	00401825 */ 	or	$v1,$v0,$zero
.L0f09b998:
/*  f09b998:	10600008 */ 	beqz	$v1,.L0f09b9bc
/*  f09b99c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b9a0:	8c64000c */ 	lw	$a0,0xc($v1)
/*  f09b9a4:	02003025 */ 	or	$a2,$s0,$zero
/*  f09b9a8:	10800004 */ 	beqz	$a0,.L0f09b9bc
/*  f09b9ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09b9b0:	0fc26238 */ 	jal	func0f0988e0
/*  f09b9b4:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f09b9b8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f09b9bc:
/*  f09b9bc:	54a00019 */ 	bnezl	$a1,.L0f09ba24
/*  f09b9c0:	2408000d */ 	addiu	$t0,$zero,0xd
/*  f09b9c4:	8e0d0614 */ 	lw	$t5,0x614($s0)
/*  f09b9c8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f09b9cc:	29a1001a */ 	slti	$at,$t5,0x1a
/*  f09b9d0:	54200014 */ 	bnezl	$at,.L0f09ba24
/*  f09b9d4:	2408000d */ 	addiu	$t0,$zero,0xd
/*  f09b9d8:	10000011 */ 	beqz	$zero,.L0f09ba20
/*  f09b9dc:	afae0050 */ 	sw	$t6,0x50($sp)
.L0f09b9e0:
/*  f09b9e0:	0fc26291 */ 	jal	func0f098a44
/*  f09b9e4:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f09b9e8:	1040000d */ 	beqz	$v0,.L0f09ba20
/*  f09b9ec:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f09b9f0:	1000000b */ 	beqz	$zero,.L0f09ba20
/*  f09b9f4:	afaf0050 */ 	sw	$t7,0x50($sp)
.L0f09b9f8:
/*  f09b9f8:	8e020614 */ 	lw	$v0,0x614($s0)
/*  f09b9fc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f09ba00:	02002025 */ 	or	$a0,$s0,$zero
/*  f09ba04:	2841001a */ 	slti	$at,$v0,0x1a
/*  f09ba08:	14200005 */ 	bnez	$at,.L0f09ba20
/*  f09ba0c:	2459ffe7 */ 	addiu	$t9,$v0,-25
/*  f09ba10:	afb80050 */ 	sw	$t8,0x50($sp)
/*  f09ba14:	ae190614 */ 	sw	$t9,0x614($s0)
/*  f09ba18:	0fc26303 */ 	jal	func0f098c0c
/*  f09ba1c:	ae00060c */ 	sw	$zero,0x60c($s0)
.L0f09ba20:
/*  f09ba20:	2408000d */ 	addiu	$t0,$zero,0xd
.L0f09ba24:
/*  f09ba24:	ae080020 */ 	sw	$t0,0x20($s0)
/*  f09ba28:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f09ba2c:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f09ba30:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f09ba34:	51200069 */ 	beqzl	$t1,.L0f09bbdc
/*  f09ba38:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f09ba3c:	8e02060c */ 	lw	$v0,0x60c($s0)
/*  f09ba40:	304a0010 */ 	andi	$t2,$v0,0x10
/*  f09ba44:	15400064 */ 	bnez	$t2,.L0f09bbd8
/*  f09ba48:	344b0010 */ 	ori	$t3,$v0,0x10
/*  f09ba4c:	ae0b060c */ 	sw	$t3,0x60c($s0)
/*  f09ba50:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f09ba54:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f09ba58:	25aeffff */ 	addiu	$t6,$t5,-1
/*  f09ba5c:	2dc1002c */ 	sltiu	$at,$t6,0x2c
/*  f09ba60:	1020004e */ 	beqz	$at,.L0f09bb9c
/*  f09ba64:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f09ba68:	3c017f1b */ 	lui	$at,%hi(var7f1ac3d0)
/*  f09ba6c:	002e0821 */ 	addu	$at,$at,$t6
/*  f09ba70:	8c2ec3d0 */ 	lw	$t6,%lo(var7f1ac3d0)($at)
/*  f09ba74:	01c00008 */ 	jr	$t6
/*  f09ba78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ba7c:	3c017f1b */ 	lui	$at,%hi(var7f1ac480)
/*  f09ba80:	c424c480 */ 	lwc1	$f4,%lo(var7f1ac480)($at)
/*  f09ba84:	00002025 */ 	or	$a0,$zero,$zero
/*  f09ba88:	0c012230 */ 	jal	func000488c0
/*  f09ba8c:	e7a40044 */ 	swc1	$f4,0x44($sp)
/*  f09ba90:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*  f09ba94:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f09ba98:	0c012230 */ 	jal	func000488c0
/*  f09ba9c:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
/*  f09baa0:	00002025 */ 	or	$a0,$zero,$zero
/*  f09baa4:	0c01210c */ 	jal	func00048430
/*  f09baa8:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f09baac:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09bab0:	44813000 */ 	mtc1	$at,$f6
/*  f09bab4:	3c048009 */ 	lui	$a0,0x8009
/*  f09bab8:	240fffff */ 	addiu	$t7,$zero,-1
/*  f09babc:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f09bac0:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f09bac4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f09bac8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f09bacc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f09bad0:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09bad4:	24058080 */ 	addiu	$a1,$zero,-32640
/*  f09bad8:	00003025 */ 	or	$a2,$zero,$zero
/*  f09badc:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09bae0:	0c004241 */ 	jal	func00010904
/*  f09bae4:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f09bae8:	10400004 */ 	beqz	$v0,.L0f09bafc
/*  f09baec:	00402025 */ 	or	$a0,$v0,$zero
/*  f09baf0:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f09baf4:	0c00cf94 */ 	jal	func00033e50
/*  f09baf8:	8fa60044 */ 	lw	$a2,0x44($sp)
.L0f09bafc:
/*  f09bafc:	00002025 */ 	or	$a0,$zero,$zero
/*  f09bb00:	0c01210c */ 	jal	func00048430
/*  f09bb04:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f09bb08:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f09bb0c:	44814000 */ 	mtc1	$at,$f8
/*  f09bb10:	00002025 */ 	or	$a0,$zero,$zero
/*  f09bb14:	0c012230 */ 	jal	func000488c0
/*  f09bb18:	e7a80038 */ 	swc1	$f8,0x38($sp)
/*  f09bb1c:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*  f09bb20:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f09bb24:	0c012230 */ 	jal	func000488c0
/*  f09bb28:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
/*  f09bb2c:	00002025 */ 	or	$a0,$zero,$zero
/*  f09bb30:	0c01210c */ 	jal	func00048430
/*  f09bb34:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f09bb38:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09bb3c:	44815000 */ 	mtc1	$at,$f10
/*  f09bb40:	3c048009 */ 	lui	$a0,0x8009
/*  f09bb44:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f09bb48:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f09bb4c:	240affff */ 	addiu	$t2,$zero,-1
/*  f09bb50:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f09bb54:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f09bb58:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f09bb5c:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09bb60:	24058052 */ 	addiu	$a1,$zero,-32686
/*  f09bb64:	00003025 */ 	or	$a2,$zero,$zero
/*  f09bb68:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09bb6c:	0c004241 */ 	jal	func00010904
/*  f09bb70:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f09bb74:	10400004 */ 	beqz	$v0,.L0f09bb88
/*  f09bb78:	00402025 */ 	or	$a0,$v0,$zero
/*  f09bb7c:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f09bb80:	0c00cf94 */ 	jal	func00033e50
/*  f09bb84:	8fa60038 */ 	lw	$a2,0x38($sp)
.L0f09bb88:
/*  f09bb88:	00002025 */ 	or	$a0,$zero,$zero
/*  f09bb8c:	0c01210c */ 	jal	func00048430
/*  f09bb90:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f09bb94:	10000011 */ 	beqz	$zero,.L0f09bbdc
/*  f09bb98:	8e0e000c */ 	lw	$t6,0xc($s0)
.L0f09bb9c:
/*  f09bb9c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09bba0:	44818000 */ 	mtc1	$at,$f16
/*  f09bba4:	3c048009 */ 	lui	$a0,0x8009
/*  f09bba8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f09bbac:	240cffff */ 	addiu	$t4,$zero,-1
/*  f09bbb0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f09bbb4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f09bbb8:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f09bbbc:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f09bbc0:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09bbc4:	24058052 */ 	addiu	$a1,$zero,-32686
/*  f09bbc8:	00003025 */ 	or	$a2,$zero,$zero
/*  f09bbcc:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09bbd0:	0c004241 */ 	jal	func00010904
/*  f09bbd4:	e7b00014 */ 	swc1	$f16,0x14($sp)
.L0f09bbd8:
/*  f09bbd8:	8e0e000c */ 	lw	$t6,0xc($s0)
.L0f09bbdc:
/*  f09bbdc:	00002825 */ 	or	$a1,$zero,$zero
/*  f09bbe0:	55c0000d */ 	bnezl	$t6,.L0f09bc18
/*  f09bbe4:	00001025 */ 	or	$v0,$zero,$zero
/*  f09bbe8:	ae000020 */ 	sw	$zero,0x20($s0)
/*  f09bbec:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f09bbf0:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f09bbf4:	0fc27346 */ 	jal	func0f09cd18
/*  f09bbf8:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f09bbfc:	10400003 */ 	beqz	$v0,.L0f09bc0c
/*  f09bc00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09bc04:	10000004 */ 	beqz	$zero,.L0f09bc18
/*  f09bc08:	8fa20064 */ 	lw	$v0,0x64($sp)
.L0f09bc0c:
/*  f09bc0c:	0fc26303 */ 	jal	func0f098c0c
/*  f09bc10:	02002025 */ 	or	$a0,$s0,$zero
/*  f09bc14:	00001025 */ 	or	$v0,$zero,$zero
.L0f09bc18:
/*  f09bc18:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f09bc1c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f09bc20:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f09bc24:	03e00008 */ 	jr	$ra
/*  f09bc28:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09bc2c
/*  f09bc2c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f09bc30:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f09bc34:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f09bc38:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f09bc3c:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f09bc40:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f09bc44:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f09bc48:	00001825 */ 	or	$v1,$zero,$zero
/*  f09bc4c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f09bc50:	11e00005 */ 	beqz	$t7,.L0f09bc68
/*  f09bc54:	00c02025 */ 	or	$a0,$a2,$zero
/*  f09bc58:	0fc2c41f */ 	jal	func0f0b107c
/*  f09bc5c:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f09bc60:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f09bc64:	00401825 */ 	or	$v1,$v0,$zero
.L0f09bc68:
/*  f09bc68:	10600021 */ 	beqz	$v1,.L0f09bcf0
/*  f09bc6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09bc70:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f09bc74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09bc78:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f09bc7c:	305800ff */ 	andi	$t8,$v0,0xff
/*  f09bc80:	1301000c */ 	beq	$t8,$at,.L0f09bcb4
/*  f09bc84:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f09bc88:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09bc8c:	1301000d */ 	beq	$t8,$at,.L0f09bcc4
/*  f09bc90:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f09bc94:	24010003 */ 	addiu	$at,$zero,0x3
/*  f09bc98:	1301000e */ 	beq	$t8,$at,.L0f09bcd4
/*  f09bc9c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f09bca0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f09bca4:	1301000f */ 	beq	$t8,$at,.L0f09bce4
/*  f09bca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09bcac:	10000010 */ 	beqz	$zero,.L0f09bcf0
/*  f09bcb0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f09bcb4:
/*  f09bcb4:	0fc26bf9 */ 	jal	func0f09afe4
/*  f09bcb8:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f09bcbc:	1000000c */ 	beqz	$zero,.L0f09bcf0
/*  f09bcc0:	00404025 */ 	or	$t0,$v0,$zero
.L0f09bcc4:
/*  f09bcc4:	0fc26c98 */ 	jal	func0f09b260
/*  f09bcc8:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f09bccc:	10000008 */ 	beqz	$zero,.L0f09bcf0
/*  f09bcd0:	00404025 */ 	or	$t0,$v0,$zero
.L0f09bcd4:
/*  f09bcd4:	0fc26d40 */ 	jal	func0f09b500
/*  f09bcd8:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f09bcdc:	10000004 */ 	beqz	$zero,.L0f09bcf0
/*  f09bce0:	00404025 */ 	or	$t0,$v0,$zero
.L0f09bce4:
/*  f09bce4:	0fc26e0a */ 	jal	func0f09b828
/*  f09bce8:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f09bcec:	00404025 */ 	or	$t0,$v0,$zero
.L0f09bcf0:
/*  f09bcf0:	11000014 */ 	beqz	$t0,.L0f09bd44
/*  f09bcf4:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f09bcf8:	93290000 */ 	lbu	$t1,0x0($t9)
/*  f09bcfc:	24010014 */ 	addiu	$at,$zero,0x14
/*  f09bd00:	00002825 */ 	or	$a1,$zero,$zero
/*  f09bd04:	15210007 */ 	bne	$t1,$at,.L0f09bd24
/*  f09bd08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09bd0c:	8f2a000c */ 	lw	$t2,0xc($t9)
/*  f09bd10:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f09bd14:	11400003 */ 	beqz	$t2,.L0f09bd24
/*  f09bd18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09bd1c:	a32b0003 */ 	sb	$t3,0x3($t9)
/*  f09bd20:	00004025 */ 	or	$t0,$zero,$zero
.L0f09bd24:
/*  f09bd24:	51000008 */ 	beqzl	$t0,.L0f09bd48
/*  f09bd28:	00001025 */ 	or	$v0,$zero,$zero
/*  f09bd2c:	0fc27346 */ 	jal	func0f09cd18
/*  f09bd30:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f09bd34:	50400004 */ 	beqzl	$v0,.L0f09bd48
/*  f09bd38:	00001025 */ 	or	$v0,$zero,$zero
/*  f09bd3c:	10000002 */ 	beqz	$zero,.L0f09bd48
/*  f09bd40:	8fa20034 */ 	lw	$v0,0x34($sp)
.L0f09bd44:
/*  f09bd44:	00001025 */ 	or	$v0,$zero,$zero
.L0f09bd48:
/*  f09bd48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09bd4c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f09bd50:	03e00008 */ 	jr	$ra
/*  f09bd54:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09bd58
/*  f09bd58:	3c0e8009 */ 	lui	$t6,0x8009
/*  f09bd5c:	91ce8804 */ 	lbu	$t6,-0x77fc($t6)
/*  f09bd60:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f09bd64:	3c03800a */ 	lui	$v1,0x800a
/*  f09bd68:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f09bd6c:	00802825 */ 	or	$a1,$a0,$zero
/*  f09bd70:	11c00013 */ 	beqz	$t6,.L0f09bdc0
/*  f09bd74:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f09bd78:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f09bd7c:	0fc67494 */ 	jal	func0f19d250
/*  f09bd80:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f09bd84:	0fc6749a */ 	jal	func0f19d268
/*  f09bd88:	00402025 */ 	or	$a0,$v0,$zero
/*  f09bd8c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f09bd90:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f09bd94:	3c18800a */ 	lui	$t8,0x800a
/*  f09bd98:	906f0638 */ 	lbu	$t7,0x638($v1)
/*  f09bd9c:	144f0008 */ 	bne	$v0,$t7,.L0f09bdc0
/*  f09bda0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09bda4:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f09bda8:	8f191580 */ 	lw	$t9,0x1580($t8)
/*  f09bdac:	00194f00 */ 	sll	$t1,$t9,0x1c
/*  f09bdb0:	05200003 */ 	bltz	$t1,.L0f09bdc0
/*  f09bdb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09bdb8:	1000003f */ 	beqz	$zero,.L0f09beb8
/*  f09bdbc:	00001025 */ 	or	$v0,$zero,$zero
.L0f09bdc0:
/*  f09bdc0:	54a0000e */ 	bnezl	$a1,.L0f09bdfc
/*  f09bdc4:	806d1582 */ 	lb	$t5,0x1582($v1)
/*  f09bdc8:	806a0de4 */ 	lb	$t2,0xde4($v1)
/*  f09bdcc:	5140000b */ 	beqzl	$t2,.L0f09bdfc
/*  f09bdd0:	806d1582 */ 	lb	$t5,0x1582($v1)
/*  f09bdd4:	8c6b13e0 */ 	lw	$t3,0x13e0($v1)
/*  f09bdd8:	24010008 */ 	addiu	$at,$zero,0x8
/*  f09bddc:	55610007 */ 	bnel	$t3,$at,.L0f09bdfc
/*  f09bde0:	806d1582 */ 	lb	$t5,0x1582($v1)
/*  f09bde4:	8c6c13e4 */ 	lw	$t4,0x13e4($v1)
/*  f09bde8:	55800004 */ 	bnezl	$t4,.L0f09bdfc
/*  f09bdec:	806d1582 */ 	lb	$t5,0x1582($v1)
/*  f09bdf0:	10000031 */ 	beqz	$zero,.L0f09beb8
/*  f09bdf4:	00001025 */ 	or	$v0,$zero,$zero
/*  f09bdf8:	806d1582 */ 	lb	$t5,0x1582($v1)
.L0f09bdfc:
/*  f09bdfc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f09be00:	05a00003 */ 	bltz	$t5,.L0f09be10
/*  f09be04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09be08:	1000002b */ 	beqz	$zero,.L0f09beb8
/*  f09be0c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09be10:
/*  f09be10:	54a40029 */ 	bnel	$a1,$a0,.L0f09beb8
/*  f09be14:	00001025 */ 	or	$v0,$zero,$zero
/*  f09be18:	14a40010 */ 	bne	$a1,$a0,.L0f09be5c
/*  f09be1c:	00057100 */ 	sll	$t6,$a1,0x4
/*  f09be20:	8c620c3c */ 	lw	$v0,0xc3c($v1)
/*  f09be24:	24010007 */ 	addiu	$at,$zero,0x7
/*  f09be28:	14820003 */ 	bne	$a0,$v0,.L0f09be38
/*  f09be2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09be30:	10000021 */ 	beqz	$zero,.L0f09beb8
/*  f09be34:	00001025 */ 	or	$v0,$zero,$zero
.L0f09be38:
/*  f09be38:	54410004 */ 	bnel	$v0,$at,.L0f09be4c
/*  f09be3c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f09be40:	1000001d */ 	beqz	$zero,.L0f09beb8
/*  f09be44:	00001025 */ 	or	$v0,$zero,$zero
/*  f09be48:	24010004 */ 	addiu	$at,$zero,0x4
.L0f09be4c:
/*  f09be4c:	54410004 */ 	bnel	$v0,$at,.L0f09be60
/*  f09be50:	01c57023 */ 	subu	$t6,$t6,$a1
/*  f09be54:	10000018 */ 	beqz	$zero,.L0f09beb8
/*  f09be58:	00001025 */ 	or	$v0,$zero,$zero
.L0f09be5c:
/*  f09be5c:	01c57023 */ 	subu	$t6,$t6,$a1
.L0f09be60:
/*  f09be60:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f09be64:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f09be68:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f09be6c:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f09be70:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f09be74:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f09be78:	81e20640 */ 	lb	$v0,0x640($t7)
/*  f09be7c:	10400006 */ 	beqz	$v0,.L0f09be98
/*  f09be80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09be84:	80791583 */ 	lb	$t9,0x1583($v1)
/*  f09be88:	07200003 */ 	bltz	$t9,.L0f09be98
/*  f09be8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09be90:	10000009 */ 	beqz	$zero,.L0f09beb8
/*  f09be94:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09be98:
/*  f09be98:	54400007 */ 	bnezl	$v0,.L0f09beb8
/*  f09be9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f09bea0:	80691583 */ 	lb	$t1,0x1583($v1)
/*  f09bea4:	05230004 */ 	bgezl	$t1,.L0f09beb8
/*  f09bea8:	00001025 */ 	or	$v0,$zero,$zero
/*  f09beac:	10000002 */ 	beqz	$zero,.L0f09beb8
/*  f09beb0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09beb4:	00001025 */ 	or	$v0,$zero,$zero
.L0f09beb8:
/*  f09beb8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09bebc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f09bec0:	03e00008 */ 	jr	$ra
/*  f09bec4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09bec8
/*  f09bec8:	00047100 */ 	sll	$t6,$a0,0x4
/*  f09becc:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f09bed0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f09bed4:	3c02800a */ 	lui	$v0,0x800a
/*  f09bed8:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f09bedc:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f09bee0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f09bee4:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f09bee8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f09beec:	004e1821 */ 	addu	$v1,$v0,$t6
/*  f09bef0:	8c6f0c3c */ 	lw	$t7,0xc3c($v1)
/*  f09bef4:	24010005 */ 	addiu	$at,$zero,0x5
/*  f09bef8:	55e10010 */ 	bnel	$t7,$at,.L0f09bf3c
/*  f09befc:	00001025 */ 	or	$v0,$zero,$zero
/*  f09bf00:	8c780c40 */ 	lw	$t8,0xc40($v1)
/*  f09bf04:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09bf08:	5701000c */ 	bnel	$t8,$at,.L0f09bf3c
/*  f09bf0c:	00001025 */ 	or	$v0,$zero,$zero
/*  f09bf10:	8c790650 */ 	lw	$t9,0x650($v1)
/*  f09bf14:	2b210003 */ 	slti	$at,$t9,0x3
/*  f09bf18:	54200008 */ 	bnezl	$at,.L0f09bf3c
/*  f09bf1c:	00001025 */ 	or	$v0,$zero,$zero
/*  f09bf20:	8c481580 */ 	lw	$t0,0x1580($v0)
/*  f09bf24:	00085700 */ 	sll	$t2,$t0,0x1c
/*  f09bf28:	05420004 */ 	bltzl	$t2,.L0f09bf3c
/*  f09bf2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f09bf30:	03e00008 */ 	jr	$ra
/*  f09bf34:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09bf38:	00001025 */ 	or	$v0,$zero,$zero
.L0f09bf3c:
/*  f09bf3c:	03e00008 */ 	jr	$ra
/*  f09bf40:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09bf44
/*  f09bf44:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f09bf48:	3c05800a */ 	lui	$a1,0x800a
/*  f09bf4c:	8ca5a244 */ 	lw	$a1,-0x5dbc($a1)
/*  f09bf50:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f09bf54:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f09bf58:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f09bf5c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f09bf60:	0fc2775f */ 	jal	func0f09dd7c
/*  f09bf64:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f09bf68:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f09bf6c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f09bf70:	14400002 */ 	bnez	$v0,.L0f09bf7c
/*  f09bf74:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f09bf78:	00001825 */ 	or	$v1,$zero,$zero
.L0f09bf7c:
/*  f09bf7c:	80ae1582 */ 	lb	$t6,0x1582($a1)
/*  f09bf80:	2401ffff */ 	addiu	$at,$zero,-1
/*  f09bf84:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f09bf88:	11c10002 */ 	beq	$t6,$at,.L0f09bf94
/*  f09bf8c:	00041100 */ 	sll	$v0,$a0,0x4
/*  f09bf90:	00001825 */ 	or	$v1,$zero,$zero
.L0f09bf94:
/*  f09bf94:	1486000f */ 	bne	$a0,$a2,.L0f09bfd4
/*  f09bf98:	00441023 */ 	subu	$v0,$v0,$a0
/*  f09bf9c:	0004c900 */ 	sll	$t9,$a0,0x4
/*  f09bfa0:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f09bfa4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f09bfa8:	0324c821 */ 	addu	$t9,$t9,$a0
/*  f09bfac:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f09bfb0:	0324c821 */ 	addu	$t9,$t9,$a0
/*  f09bfb4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f09bfb8:	90af1583 */ 	lbu	$t7,0x1583($a1)
/*  f09bfbc:	00b94021 */ 	addu	$t0,$a1,$t9
/*  f09bfc0:	81090640 */ 	lb	$t1,0x640($t0)
/*  f09bfc4:	000fc1c2 */ 	srl	$t8,$t7,0x7
/*  f09bfc8:	53090003 */ 	beql	$t8,$t1,.L0f09bfd8
/*  f09bfcc:	00021080 */ 	sll	$v0,$v0,0x2
/*  f09bfd0:	00001825 */ 	or	$v1,$zero,$zero
.L0f09bfd4:
/*  f09bfd4:	00021080 */ 	sll	$v0,$v0,0x2
.L0f09bfd8:
/*  f09bfd8:	8caa1584 */ 	lw	$t2,0x1584($a1)
/*  f09bfdc:	00441021 */ 	addu	$v0,$v0,$a0
/*  f09bfe0:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f09bfe4:	00441021 */ 	addu	$v0,$v0,$a0
/*  f09bfe8:	05400002 */ 	bltz	$t2,.L0f09bff4
/*  f09bfec:	00021080 */ 	sll	$v0,$v0,0x2
/*  f09bff0:	00001825 */ 	or	$v1,$zero,$zero
.L0f09bff4:
/*  f09bff4:	00025823 */ 	negu	$t3,$v0
/*  f09bff8:	00ab6021 */ 	addu	$t4,$a1,$t3
/*  f09bffc:	8d8d13e0 */ 	lw	$t5,0x13e0($t4)
/*  f09c000:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09c004:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f09c008:	14cd0002 */ 	bne	$a2,$t5,.L0f09c014
/*  f09c00c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c010:	00001825 */ 	or	$v1,$zero,$zero
.L0f09c014:
/*  f09c014:	03e00008 */ 	jr	$ra
/*  f09c018:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f09c01c
/*  f09c01c:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f09c020:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f09c024:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f09c028:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f09c02c:	afa50074 */ 	sw	$a1,0x74($sp)
/*  f09c030:	afa7007c */ 	sw	$a3,0x7c($sp)
/*  f09c034:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f09c038:	00c08025 */ 	or	$s0,$a2,$zero
/*  f09c03c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f09c040:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f09c044:	8cd80618 */ 	lw	$t8,0x618($a2)
/*  f09c048:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f09c04c:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f09c050:	57000008 */ 	bnezl	$t8,.L0f09c074
/*  f09c054:	8e020608 */ 	lw	$v0,0x608($s0)
/*  f09c058:	8cd90318 */ 	lw	$t9,0x318($a2)
/*  f09c05c:	57200004 */ 	bnezl	$t9,.L0f09c070
/*  f09c060:	ae000038 */ 	sw	$zero,0x38($s0)
/*  f09c064:	10000002 */ 	beqz	$zero,.L0f09c070
/*  f09c068:	ae000038 */ 	sw	$zero,0x38($s0)
/*  f09c06c:	ae000038 */ 	sw	$zero,0x38($s0)
.L0f09c070:
/*  f09c070:	8e020608 */ 	lw	$v0,0x608($s0)
.L0f09c074:
/*  f09c074:	1440004f */ 	bnez	$v0,.L0f09c1b4
/*  f09c078:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c07c:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f09c080:	afa00064 */ 	sw	$zero,0x64($sp)
/*  f09c084:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f09c088:	8d040000 */ 	lw	$a0,0x0($t0)
/*  f09c08c:	1040000f */ 	beqz	$v0,.L0f09c0cc
/*  f09c090:	8fa90070 */ 	lw	$t1,0x70($sp)
/*  f09c094:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f09c098:	24010022 */ 	addiu	$at,$zero,0x22
/*  f09c09c:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f09c0a0:	15410004 */ 	bne	$t2,$at,.L0f09c0b4
/*  f09c0a4:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c0a8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c0ac:	51610008 */ 	beql	$t3,$at,.L0f09c0d0
/*  f09c0b0:	ae000018 */ 	sw	$zero,0x18($s0)
.L0f09c0b4:
/*  f09c0b4:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f09c0b8:	0fc26328 */ 	jal	func0f098ca0
/*  f09c0bc:	02003025 */ 	or	$a2,$s0,$zero
/*  f09c0c0:	04410002 */ 	bgez	$v0,.L0f09c0cc
/*  f09c0c4:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f09c0c8:	afac0064 */ 	sw	$t4,0x64($sp)
.L0f09c0cc:
/*  f09c0cc:	ae000018 */ 	sw	$zero,0x18($s0)
.L0f09c0d0:
/*  f09c0d0:	8fad0064 */ 	lw	$t5,0x64($sp)
/*  f09c0d4:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f09c0d8:	55a0002e */ 	bnezl	$t5,.L0f09c194
/*  f09c0dc:	8e0b0608 */ 	lw	$t3,0x608($s0)
/*  f09c0e0:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f09c0e4:	5080001e */ 	beqzl	$a0,.L0f09c160
/*  f09c0e8:	8e0f060c */ 	lw	$t7,0x60c($s0)
/*  f09c0ec:	820f0008 */ 	lb	$t7,0x8($s0)
/*  f09c0f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c0f4:	55e1001a */ 	bnel	$t7,$at,.L0f09c160
/*  f09c0f8:	8e0f060c */ 	lw	$t7,0x60c($s0)
/*  f09c0fc:	961806d6 */ 	lhu	$t8,0x6d6($s0)
/*  f09c100:	0018cb02 */ 	srl	$t9,$t8,0xc
/*  f09c104:	53200007 */ 	beqzl	$t9,.L0f09c124
/*  f09c108:	8e0b0618 */ 	lw	$t3,0x618($s0)
/*  f09c10c:	8e0806d4 */ 	lw	$t0,0x6d4($s0)
/*  f09c110:	00084d00 */ 	sll	$t1,$t0,0x14
/*  f09c114:	00095742 */ 	srl	$t2,$t1,0x1d
/*  f09c118:	51400011 */ 	beqzl	$t2,.L0f09c160
/*  f09c11c:	8e0f060c */ 	lw	$t7,0x60c($s0)
/*  f09c120:	8e0b0618 */ 	lw	$t3,0x618($s0)
.L0f09c124:
/*  f09c124:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f09c128:	55600006 */ 	bnezl	$t3,.L0f09c144
/*  f09c12c:	8e0c068c */ 	lw	$t4,0x68c($s0)
/*  f09c130:	0fc26238 */ 	jal	func0f0988e0
/*  f09c134:	02003025 */ 	or	$a2,$s0,$zero
/*  f09c138:	10000019 */ 	beqz	$zero,.L0f09c1a0
/*  f09c13c:	8e020608 */ 	lw	$v0,0x608($s0)
/*  f09c140:	8e0c068c */ 	lw	$t4,0x68c($s0)
.L0f09c144:
/*  f09c144:	55800016 */ 	bnezl	$t4,.L0f09c1a0
/*  f09c148:	8e020608 */ 	lw	$v0,0x608($s0)
/*  f09c14c:	8e0d0608 */ 	lw	$t5,0x608($s0)
/*  f09c150:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f09c154:	10000011 */ 	beqz	$zero,.L0f09c19c
/*  f09c158:	ae0e0608 */ 	sw	$t6,0x608($s0)
/*  f09c15c:	8e0f060c */ 	lw	$t7,0x60c($s0)
.L0f09c160:
/*  f09c160:	961906d6 */ 	lhu	$t9,0x6d6($s0)
/*  f09c164:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c168:	35f80001 */ 	ori	$t8,$t7,0x1
/*  f09c16c:	00194302 */ 	srl	$t0,$t9,0xc
/*  f09c170:	15010003 */ 	bne	$t0,$at,.L0f09c180
/*  f09c174:	ae18060c */ 	sw	$t8,0x60c($s0)
/*  f09c178:	1000026d */ 	beqz	$zero,.L0f09cb30
/*  f09c17c:	00001025 */ 	or	$v0,$zero,$zero
.L0f09c180:
/*  f09c180:	8e090608 */ 	lw	$t1,0x608($s0)
/*  f09c184:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f09c188:	10000004 */ 	beqz	$zero,.L0f09c19c
/*  f09c18c:	ae0a0608 */ 	sw	$t2,0x608($s0)
/*  f09c190:	8e0b0608 */ 	lw	$t3,0x608($s0)
.L0f09c194:
/*  f09c194:	256c0001 */ 	addiu	$t4,$t3,0x1
/*  f09c198:	ae0c0608 */ 	sw	$t4,0x608($s0)
.L0f09c19c:
/*  f09c19c:	8e020608 */ 	lw	$v0,0x608($s0)
.L0f09c1a0:
/*  f09c1a0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c1a4:	14410003 */ 	bne	$v0,$at,.L0f09c1b4
/*  f09c1a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c1ac:	ae000614 */ 	sw	$zero,0x614($s0)
/*  f09c1b0:	8e020608 */ 	lw	$v0,0x608($s0)
.L0f09c1b4:
/*  f09c1b4:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f09c1b8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c1bc:	14410084 */ 	bne	$v0,$at,.L0f09c3d0
/*  f09c1c0:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f09c1c4:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f09c1c8:	8ccd0318 */ 	lw	$t5,0x318($a2)
/*  f09c1cc:	24030010 */ 	addiu	$v1,$zero,0x10
/*  f09c1d0:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c1d4:	11a00002 */ 	beqz	$t5,.L0f09c1e0
/*  f09c1d8:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f09c1dc:	2403000c */ 	addiu	$v1,$zero,0xc
.L0f09c1e0:
/*  f09c1e0:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*  f09c1e4:	51e00007 */ 	beqzl	$t7,.L0f09c204
/*  f09c1e8:	82080008 */ 	lb	$t0,0x8($s0)
/*  f09c1ec:	8e18060c */ 	lw	$t8,0x60c($s0)
/*  f09c1f0:	33190001 */ 	andi	$t9,$t8,0x1
/*  f09c1f4:	57200003 */ 	bnezl	$t9,.L0f09c204
/*  f09c1f8:	82080008 */ 	lb	$t0,0x8($s0)
/*  f09c1fc:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f09c200:	82080008 */ 	lb	$t0,0x8($s0)
.L0f09c204:
/*  f09c204:	55000003 */ 	bnezl	$t0,.L0f09c214
/*  f09c208:	8e0906d4 */ 	lw	$t1,0x6d4($s0)
/*  f09c20c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f09c210:	8e0906d4 */ 	lw	$t1,0x6d4($s0)
.L0f09c214:
/*  f09c214:	00095500 */ 	sll	$t2,$t1,0x14
/*  f09c218:	000a5f42 */ 	srl	$t3,$t2,0x1d
/*  f09c21c:	5560000a */ 	bnezl	$t3,.L0f09c248
/*  f09c220:	8ccd0284 */ 	lw	$t5,0x284($a2)
/*  f09c224:	960206d6 */ 	lhu	$v0,0x6d6($s0)
/*  f09c228:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c22c:	00026302 */ 	srl	$t4,$v0,0xc
/*  f09c230:	11810003 */ 	beq	$t4,$at,.L0f09c240
/*  f09c234:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09c238:	55810003 */ 	bnel	$t4,$at,.L0f09c248
/*  f09c23c:	8ccd0284 */ 	lw	$t5,0x284($a2)
.L0f09c240:
/*  f09c240:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f09c244:	8ccd0284 */ 	lw	$t5,0x284($a2)
.L0f09c248:
/*  f09c248:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c24c:	8dae1580 */ 	lw	$t6,0x1580($t5)
/*  f09c250:	000e7f00 */ 	sll	$t7,$t6,0x1c
/*  f09c254:	000fc7c2 */ 	srl	$t8,$t7,0x1f
/*  f09c258:	57010003 */ 	bnel	$t8,$at,.L0f09c268
/*  f09c25c:	8e020614 */ 	lw	$v0,0x614($s0)
/*  f09c260:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f09c264:	8e020614 */ 	lw	$v0,0x614($s0)
.L0f09c268:
/*  f09c268:	0043082a */ 	slt	$at,$v0,$v1
/*  f09c26c:	5420004a */ 	bnezl	$at,.L0f09c398
/*  f09c270:	44822000 */ 	mtc1	$v0,$f4
/*  f09c274:	14800030 */ 	bnez	$a0,.L0f09c338
/*  f09c278:	3c053f5f */ 	lui	$a1,0x3f5f
/*  f09c27c:	8cd90314 */ 	lw	$t9,0x314($a2)
/*  f09c280:	3c088009 */ 	lui	$t0,0x8009
/*  f09c284:	13200024 */ 	beqz	$t9,.L0f09c318
/*  f09c288:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c28c:	91080af0 */ 	lbu	$t0,0xaf0($t0)
/*  f09c290:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c294:	1501001e */ 	bne	$t0,$at,.L0f09c310
/*  f09c298:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c29c:	8cc9006c */ 	lw	$t1,0x6c($a2)
/*  f09c2a0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c2a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f09c2a8:	11200003 */ 	beqz	$t1,.L0f09c2b8
/*  f09c2ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c2b0:	10000001 */ 	beqz	$zero,.L0f09c2b8
/*  f09c2b4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f09c2b8:
/*  f09c2b8:	8cca0068 */ 	lw	$t2,0x68($a2)
/*  f09c2bc:	00001825 */ 	or	$v1,$zero,$zero
/*  f09c2c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f09c2c4:	11400003 */ 	beqz	$t2,.L0f09c2d4
/*  f09c2c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c2cc:	10000001 */ 	beqz	$zero,.L0f09c2d4
/*  f09c2d0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f09c2d4:
/*  f09c2d4:	8ccb0064 */ 	lw	$t3,0x64($a2)
/*  f09c2d8:	11600003 */ 	beqz	$t3,.L0f09c2e8
/*  f09c2dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c2e0:	10000001 */ 	beqz	$zero,.L0f09c2e8
/*  f09c2e4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f09c2e8:
/*  f09c2e8:	8ccc0070 */ 	lw	$t4,0x70($a2)
/*  f09c2ec:	11800003 */ 	beqz	$t4,.L0f09c2fc
/*  f09c2f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c2f4:	10000001 */ 	beqz	$zero,.L0f09c2fc
/*  f09c2f8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09c2fc:
/*  f09c2fc:	00436821 */ 	addu	$t5,$v0,$v1
/*  f09c300:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f09c304:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f09c308:	11e10003 */ 	beq	$t7,$at,.L0f09c318
/*  f09c30c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f09c310:
/*  f09c310:	0fc4a33c */ 	jal	func0f128cf0
/*  f09c314:	8fa40074 */ 	lw	$a0,0x74($sp)
.L0f09c318:
/*  f09c318:	0fc27e88 */ 	jal	func0f09fa20
/*  f09c31c:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f09c320:	8e190608 */ 	lw	$t9,0x608($s0)
/*  f09c324:	24180006 */ 	addiu	$t8,$zero,0x6
/*  f09c328:	ae180020 */ 	sw	$t8,0x20($s0)
/*  f09c32c:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f09c330:	10000014 */ 	beqz	$zero,.L0f09c384
/*  f09c334:	ae080608 */ 	sw	$t0,0x608($s0)
.L0f09c338:
/*  f09c338:	02002025 */ 	or	$a0,$s0,$zero
/*  f09c33c:	0fc265e0 */ 	jal	func0f099780
/*  f09c340:	34a55dd8 */ 	ori	$a1,$a1,0x5dd8
/*  f09c344:	3c09800a */ 	lui	$t1,0x800a
/*  f09c348:	8d29a244 */ 	lw	$t1,-0x5dbc($t1)
/*  f09c34c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c350:	8d2a1580 */ 	lw	$t2,0x1580($t1)
/*  f09c354:	000a5f00 */ 	sll	$t3,$t2,0x1c
/*  f09c358:	000b67c2 */ 	srl	$t4,$t3,0x1f
/*  f09c35c:	15810009 */ 	bne	$t4,$at,.L0f09c384
/*  f09c360:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c364:	820d0008 */ 	lb	$t5,0x8($s0)
/*  f09c368:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f09c36c:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f09c370:	11a00004 */ 	beqz	$t5,.L0f09c384
/*  f09c374:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f09c378:	a20e0004 */ 	sb	$t6,0x4($s0)
/*  f09c37c:	ae0f06ac */ 	sw	$t7,0x6ac($s0)
/*  f09c380:	a2180003 */ 	sb	$t8,0x3($s0)
.L0f09c384:
/*  f09c384:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f09c388:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f09c38c:	10000010 */ 	beqz	$zero,.L0f09c3d0
/*  f09c390:	8e020608 */ 	lw	$v0,0x608($s0)
/*  f09c394:	44822000 */ 	mtc1	$v0,$f4
.L0f09c398:
/*  f09c398:	3c017f1b */ 	lui	$at,%hi(var7f1ac484)
/*  f09c39c:	c428c484 */ 	lwc1	$f8,%lo(var7f1ac484)($at)
/*  f09c3a0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f09c3a4:	44838000 */ 	mtc1	$v1,$f16
/*  f09c3a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f09c3ac:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f09c3b0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f09c3b4:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f09c3b8:	44052000 */ 	mfc1	$a1,$f4
/*  f09c3bc:	0fc265e0 */ 	jal	func0f099780
/*  f09c3c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c3c4:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f09c3c8:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f09c3cc:	8e020608 */ 	lw	$v0,0x608($s0)
.L0f09c3d0:
/*  f09c3d0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09c3d4:	54410040 */ 	bnel	$v0,$at,.L0f09c4d8
/*  f09c3d8:	8e020608 */ 	lw	$v0,0x608($s0)
/*  f09c3dc:	8e19003c */ 	lw	$t9,0x3c($s0)
/*  f09c3e0:	ae00068c */ 	sw	$zero,0x68c($s0)
/*  f09c3e4:	53200007 */ 	beqzl	$t9,.L0f09c404
/*  f09c3e8:	8e0a0020 */ 	lw	$t2,0x20($s0)
/*  f09c3ec:	8e08001c */ 	lw	$t0,0x1c($s0)
/*  f09c3f0:	8e090038 */ 	lw	$t1,0x38($s0)
/*  f09c3f4:	0109082a */ 	slt	$at,$t0,$t1
/*  f09c3f8:	5420002a */ 	bnezl	$at,.L0f09c4a4
/*  f09c3fc:	8e020020 */ 	lw	$v0,0x20($s0)
/*  f09c400:	8e0a0020 */ 	lw	$t2,0x20($s0)
.L0f09c404:
/*  f09c404:	24010006 */ 	addiu	$at,$zero,0x6
/*  f09c408:	15410010 */ 	bne	$t2,$at,.L0f09c44c
/*  f09c40c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c410:	0fc26fd1 */ 	jal	func0f09bf44
/*  f09c414:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f09c418:	50400022 */ 	beqzl	$v0,.L0f09c4a4
/*  f09c41c:	8e020020 */ 	lw	$v0,0x20($s0)
/*  f09c420:	820c0008 */ 	lb	$t4,0x8($s0)
/*  f09c424:	240b0007 */ 	addiu	$t3,$zero,0x7
/*  f09c428:	ae0b0020 */ 	sw	$t3,0x20($s0)
/*  f09c42c:	1580001c */ 	bnez	$t4,.L0f09c4a0
/*  f09c430:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f09c434:	0fc27346 */ 	jal	func0f09cd18
/*  f09c438:	00002825 */ 	or	$a1,$zero,$zero
/*  f09c43c:	50400019 */ 	beqzl	$v0,.L0f09c4a4
/*  f09c440:	8e020020 */ 	lw	$v0,0x20($s0)
/*  f09c444:	100001ba */ 	beqz	$zero,.L0f09cb30
/*  f09c448:	8fa2007c */ 	lw	$v0,0x7c($sp)
.L0f09c44c:
/*  f09c44c:	0fc2775f */ 	jal	func0f09dd7c
/*  f09c450:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c454:	10400012 */ 	beqz	$v0,.L0f09c4a0
/*  f09c458:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f09c45c:	8dae0004 */ 	lw	$t6,0x4($t5)
/*  f09c460:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f09c464:	8dc40004 */ 	lw	$a0,0x4($t6)
/*  f09c468:	50800007 */ 	beqzl	$a0,.L0f09c488
/*  f09c46c:	8e090608 */ 	lw	$t1,0x608($s0)
/*  f09c470:	0fc26238 */ 	jal	func0f0988e0
/*  f09c474:	02003025 */ 	or	$a2,$s0,$zero
/*  f09c478:	92180690 */ 	lbu	$t8,0x690($s0)
/*  f09c47c:	37190040 */ 	ori	$t9,$t8,0x40
/*  f09c480:	a2190690 */ 	sb	$t9,0x690($s0)
/*  f09c484:	8e090608 */ 	lw	$t1,0x608($s0)
.L0f09c488:
/*  f09c488:	24080008 */ 	addiu	$t0,$zero,0x8
/*  f09c48c:	ae080020 */ 	sw	$t0,0x20($s0)
/*  f09c490:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f09c494:	ae0a0608 */ 	sw	$t2,0x608($s0)
/*  f09c498:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f09c49c:	ae000018 */ 	sw	$zero,0x18($s0)
.L0f09c4a0:
/*  f09c4a0:	8e020020 */ 	lw	$v0,0x20($s0)
.L0f09c4a4:
/*  f09c4a4:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f09c4a8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f09c4ac:	10410003 */ 	beq	$v0,$at,.L0f09c4bc
/*  f09c4b0:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f09c4b4:	24010007 */ 	addiu	$at,$zero,0x7
/*  f09c4b8:	14410006 */ 	bne	$v0,$at,.L0f09c4d4
.L0f09c4bc:
/*  f09c4bc:	3c053f5f */ 	lui	$a1,0x3f5f
/*  f09c4c0:	34a55dd8 */ 	ori	$a1,$a1,0x5dd8
/*  f09c4c4:	0fc265e0 */ 	jal	func0f099780
/*  f09c4c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f09c4cc:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f09c4d0:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
.L0f09c4d4:
/*  f09c4d4:	8e020608 */ 	lw	$v0,0x608($s0)
.L0f09c4d8:
/*  f09c4d8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f09c4dc:	24054000 */ 	addiu	$a1,$zero,0x4000
/*  f09c4e0:	54410176 */ 	bnel	$v0,$at,.L0f09cabc
/*  f09c4e4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f09c4e8:	8ccb0318 */ 	lw	$t3,0x318($a2)
/*  f09c4ec:	24020017 */ 	addiu	$v0,$zero,0x17
/*  f09c4f0:	51600003 */ 	beqzl	$t3,.L0f09c500
/*  f09c4f4:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f09c4f8:	2402000c */ 	addiu	$v0,$zero,0xc
/*  f09c4fc:	92040000 */ 	lbu	$a0,0x0($s0)
.L0f09c500:
/*  f09c500:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f09c504:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f09c508:	10400003 */ 	beqz	$v0,.L0f09c518
/*  f09c50c:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f09c510:	10000006 */ 	beqz	$zero,.L0f09c52c
/*  f09c514:	ae00068c */ 	sw	$zero,0x68c($s0)
.L0f09c518:
/*  f09c518:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*  f09c51c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f09c520:	51a00003 */ 	beqzl	$t5,.L0f09c530
/*  f09c524:	8e0f0018 */ 	lw	$t7,0x18($s0)
/*  f09c528:	afae0054 */ 	sw	$t6,0x54($sp)
.L0f09c52c:
/*  f09c52c:	8e0f0018 */ 	lw	$t7,0x18($s0)
.L0f09c530:
/*  f09c530:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f09c534:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f09c538:	55e0012d */ 	bnezl	$t7,.L0f09c9f0
/*  f09c53c:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09c540:	8cd80314 */ 	lw	$t8,0x314($a2)
/*  f09c544:	3c198009 */ 	lui	$t9,0x8009
/*  f09c548:	53000025 */ 	beqzl	$t8,.L0f09c5e0
/*  f09c54c:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f09c550:	93390af0 */ 	lbu	$t9,0xaf0($t9)
/*  f09c554:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c558:	1721001e */ 	bne	$t9,$at,.L0f09c5d4
/*  f09c55c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c560:	8cc8006c */ 	lw	$t0,0x6c($a2)
/*  f09c564:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c568:	00002825 */ 	or	$a1,$zero,$zero
/*  f09c56c:	11000003 */ 	beqz	$t0,.L0f09c57c
/*  f09c570:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c574:	10000001 */ 	beqz	$zero,.L0f09c57c
/*  f09c578:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f09c57c:
/*  f09c57c:	8cc90068 */ 	lw	$t1,0x68($a2)
/*  f09c580:	00001825 */ 	or	$v1,$zero,$zero
/*  f09c584:	00001025 */ 	or	$v0,$zero,$zero
/*  f09c588:	11200003 */ 	beqz	$t1,.L0f09c598
/*  f09c58c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c590:	10000001 */ 	beqz	$zero,.L0f09c598
/*  f09c594:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f09c598:
/*  f09c598:	8cca0064 */ 	lw	$t2,0x64($a2)
/*  f09c59c:	11400003 */ 	beqz	$t2,.L0f09c5ac
/*  f09c5a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c5a4:	10000001 */ 	beqz	$zero,.L0f09c5ac
/*  f09c5a8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f09c5ac:
/*  f09c5ac:	8ccb0070 */ 	lw	$t3,0x70($a2)
/*  f09c5b0:	11600003 */ 	beqz	$t3,.L0f09c5c0
/*  f09c5b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c5b8:	10000001 */ 	beqz	$zero,.L0f09c5c0
/*  f09c5bc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09c5c0:
/*  f09c5c0:	00436021 */ 	addu	$t4,$v0,$v1
/*  f09c5c4:	01846821 */ 	addu	$t5,$t4,$a0
/*  f09c5c8:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f09c5cc:	51c10004 */ 	beql	$t6,$at,.L0f09c5e0
/*  f09c5d0:	8fa40070 */ 	lw	$a0,0x70($sp)
.L0f09c5d4:
/*  f09c5d4:	0fc4a348 */ 	jal	func0f128d20
/*  f09c5d8:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f09c5dc:	8fa40070 */ 	lw	$a0,0x70($sp)
.L0f09c5e0:
/*  f09c5e0:	0fc263e3 */ 	jal	func0f098f8c
/*  f09c5e4:	02002825 */ 	or	$a1,$s0,$zero
/*  f09c5e8:	8faf0070 */ 	lw	$t7,0x70($sp)
/*  f09c5ec:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f09c5f0:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f09c5f4:	8de40000 */ 	lw	$a0,0x0($t7)
/*  f09c5f8:	10400015 */ 	beqz	$v0,.L0f09c650
/*  f09c5fc:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f09c600:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f09c604:	24010022 */ 	addiu	$at,$zero,0x22
/*  f09c608:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f09c60c:	17210004 */ 	bne	$t9,$at,.L0f09c620
/*  f09c610:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c614:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c618:	1101000d */ 	beq	$t0,$at,.L0f09c650
/*  f09c61c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f09c620:
/*  f09c620:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f09c624:	0fc26328 */ 	jal	func0f098ca0
/*  f09c628:	02003025 */ 	or	$a2,$s0,$zero
/*  f09c62c:	04410008 */ 	bgez	$v0,.L0f09c650
/*  f09c630:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f09c634:	0fc27346 */ 	jal	func0f09cd18
/*  f09c638:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f09c63c:	10400004 */ 	beqz	$v0,.L0f09c650
/*  f09c640:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f09c644:	ae090608 */ 	sw	$t1,0x608($s0)
/*  f09c648:	10000139 */ 	beqz	$zero,.L0f09cb30
/*  f09c64c:	8fa2007c */ 	lw	$v0,0x7c($sp)
.L0f09c650:
/*  f09c650:	3c0a800a */ 	lui	$t2,0x800a
/*  f09c654:	8d4aa244 */ 	lw	$t2,-0x5dbc($t2)
/*  f09c658:	3c0b800a */ 	lui	$t3,0x800a
/*  f09c65c:	3c0c800a */ 	lui	$t4,0x800a
/*  f09c660:	ad401600 */ 	sw	$zero,0x1600($t2)
/*  f09c664:	8d6b9ff4 */ 	lw	$t3,-0x600c($t3)
/*  f09c668:	596000e1 */ 	blezl	$t3,.L0f09c9f0
/*  f09c66c:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09c670:	8d8ca244 */ 	lw	$t4,-0x5dbc($t4)
/*  f09c674:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09c678:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f09c67c:	51a100dc */ 	beql	$t5,$at,.L0f09c9f0
/*  f09c680:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09c684:	0fc2775f */ 	jal	func0f09dd7c
/*  f09c688:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c68c:	104000d7 */ 	beqz	$v0,.L0f09c9ec
/*  f09c690:	3c0e8007 */ 	lui	$t6,0x8007
/*  f09c694:	8dce0760 */ 	lw	$t6,0x760($t6)
/*  f09c698:	3c0f800a */ 	lui	$t7,0x800a
/*  f09c69c:	55c000d4 */ 	bnezl	$t6,.L0f09c9f0
/*  f09c6a0:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09c6a4:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f09c6a8:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f09c6ac:	8df800d8 */ 	lw	$t8,0xd8($t7)
/*  f09c6b0:	570000cf */ 	bnezl	$t8,.L0f09c9f0
/*  f09c6b4:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09c6b8:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f09c6bc:	2d010058 */ 	sltiu	$at,$t0,0x58
/*  f09c6c0:	102000bb */ 	beqz	$at,.L0f09c9b0
/*  f09c6c4:	00084080 */ 	sll	$t0,$t0,0x2
/*  f09c6c8:	3c017f1b */ 	lui	$at,%hi(var7f1ac488)
/*  f09c6cc:	00280821 */ 	addu	$at,$at,$t0
/*  f09c6d0:	8c28c488 */ 	lw	$t0,%lo(var7f1ac488)($at)
/*  f09c6d4:	01000008 */ 	jr	$t0
/*  f09c6d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09c6dc:	3c014060 */ 	lui	$at,0x4060
/*  f09c6e0:	44813000 */ 	mtc1	$at,$f6
/*  f09c6e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c6e8:	0c012230 */ 	jal	func000488c0
/*  f09c6ec:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*  f09c6f0:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*  f09c6f4:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f09c6f8:	0c012230 */ 	jal	func000488c0
/*  f09c6fc:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
/*  f09c700:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c704:	0c01210c */ 	jal	func00048430
/*  f09c708:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f09c70c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09c710:	44814000 */ 	mtc1	$at,$f8
/*  f09c714:	3c048009 */ 	lui	$a0,0x8009
/*  f09c718:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f09c71c:	240affff */ 	addiu	$t2,$zero,-1
/*  f09c720:	240bffff */ 	addiu	$t3,$zero,-1
/*  f09c724:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f09c728:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f09c72c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f09c730:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09c734:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f09c738:	00003025 */ 	or	$a2,$zero,$zero
/*  f09c73c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09c740:	0c004241 */ 	jal	func00010904
/*  f09c744:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f09c748:	10400004 */ 	beqz	$v0,.L0f09c75c
/*  f09c74c:	00402025 */ 	or	$a0,$v0,$zero
/*  f09c750:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f09c754:	0c00cf94 */ 	jal	func00033e50
/*  f09c758:	8fa6004c */ 	lw	$a2,0x4c($sp)
.L0f09c75c:
/*  f09c75c:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c760:	0c01210c */ 	jal	func00048430
/*  f09c764:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f09c768:	100000a1 */ 	beqz	$zero,.L0f09c9f0
/*  f09c76c:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09c770:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09c774:	44818000 */ 	mtc1	$at,$f16
/*  f09c778:	3c048009 */ 	lui	$a0,0x8009
/*  f09c77c:	240cffff */ 	addiu	$t4,$zero,-1
/*  f09c780:	240dffff */ 	addiu	$t5,$zero,-1
/*  f09c784:	240effff */ 	addiu	$t6,$zero,-1
/*  f09c788:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f09c78c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f09c790:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f09c794:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09c798:	240500f2 */ 	addiu	$a1,$zero,0xf2
/*  f09c79c:	00003025 */ 	or	$a2,$zero,$zero
/*  f09c7a0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09c7a4:	0c004241 */ 	jal	func00010904
/*  f09c7a8:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f09c7ac:	10000090 */ 	beqz	$zero,.L0f09c9f0
/*  f09c7b0:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09c7b4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09c7b8:	44815000 */ 	mtc1	$at,$f10
/*  f09c7bc:	3c048009 */ 	lui	$a0,0x8009
/*  f09c7c0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f09c7c4:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f09c7c8:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f09c7cc:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f09c7d0:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f09c7d4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f09c7d8:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09c7dc:	240500e9 */ 	addiu	$a1,$zero,0xe9
/*  f09c7e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f09c7e4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09c7e8:	0c004241 */ 	jal	func00010904
/*  f09c7ec:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f09c7f0:	1000007f */ 	beqz	$zero,.L0f09c9f0
/*  f09c7f4:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09c7f8:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f09c7fc:	3c048009 */ 	lui	$a0,0x8009
/*  f09c800:	240500eb */ 	addiu	$a1,$zero,0xeb
/*  f09c804:	15000079 */ 	bnez	$t0,.L0f09c9ec
/*  f09c808:	00003025 */ 	or	$a2,$zero,$zero
/*  f09c80c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09c810:	44819000 */ 	mtc1	$at,$f18
/*  f09c814:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f09c818:	240affff */ 	addiu	$t2,$zero,-1
/*  f09c81c:	240bffff */ 	addiu	$t3,$zero,-1
/*  f09c820:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f09c824:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f09c828:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f09c82c:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09c830:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09c834:	0c004241 */ 	jal	func00010904
/*  f09c838:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f09c83c:	1000006c */ 	beqz	$zero,.L0f09c9f0
/*  f09c840:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09c844:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09c848:	44812000 */ 	mtc1	$at,$f4
/*  f09c84c:	3c048009 */ 	lui	$a0,0x8009
/*  f09c850:	240cffff */ 	addiu	$t4,$zero,-1
/*  f09c854:	240dffff */ 	addiu	$t5,$zero,-1
/*  f09c858:	240effff */ 	addiu	$t6,$zero,-1
/*  f09c85c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f09c860:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f09c864:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f09c868:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09c86c:	240500eb */ 	addiu	$a1,$zero,0xeb
/*  f09c870:	00003025 */ 	or	$a2,$zero,$zero
/*  f09c874:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09c878:	0c004241 */ 	jal	func00010904
/*  f09c87c:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f09c880:	1000005b */ 	beqz	$zero,.L0f09c9f0
/*  f09c884:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09c888:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f09c88c:	44813000 */ 	mtc1	$at,$f6
/*  f09c890:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c894:	0c012230 */ 	jal	func000488c0
/*  f09c898:	e7a60040 */ 	swc1	$f6,0x40($sp)
/*  f09c89c:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*  f09c8a0:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f09c8a4:	0c012230 */ 	jal	func000488c0
/*  f09c8a8:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
/*  f09c8ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c8b0:	0c01210c */ 	jal	func00048430
/*  f09c8b4:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f09c8b8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09c8bc:	44814000 */ 	mtc1	$at,$f8
/*  f09c8c0:	3c048009 */ 	lui	$a0,0x8009
/*  f09c8c4:	240fffff */ 	addiu	$t7,$zero,-1
/*  f09c8c8:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f09c8cc:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f09c8d0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f09c8d4:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f09c8d8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f09c8dc:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09c8e0:	240500e8 */ 	addiu	$a1,$zero,0xe8
/*  f09c8e4:	00003025 */ 	or	$a2,$zero,$zero
/*  f09c8e8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09c8ec:	0c004241 */ 	jal	func00010904
/*  f09c8f0:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f09c8f4:	10400004 */ 	beqz	$v0,.L0f09c908
/*  f09c8f8:	00402025 */ 	or	$a0,$v0,$zero
/*  f09c8fc:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f09c900:	0c00cf94 */ 	jal	func00033e50
/*  f09c904:	8fa60040 */ 	lw	$a2,0x40($sp)
.L0f09c908:
/*  f09c908:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c90c:	0c01210c */ 	jal	func00048430
/*  f09c910:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f09c914:	10000036 */ 	beqz	$zero,.L0f09c9f0
/*  f09c918:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09c91c:	3c017f1b */ 	lui	$at,%hi(var7f1ac5e8)
/*  f09c920:	c430c5e8 */ 	lwc1	$f16,%lo(var7f1ac5e8)($at)
/*  f09c924:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c928:	0c012230 */ 	jal	func000488c0
/*  f09c92c:	e7b00034 */ 	swc1	$f16,0x34($sp)
/*  f09c930:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*  f09c934:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f09c938:	0c012230 */ 	jal	func000488c0
/*  f09c93c:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
/*  f09c940:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c944:	0c01210c */ 	jal	func00048430
/*  f09c948:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f09c94c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09c950:	44815000 */ 	mtc1	$at,$f10
/*  f09c954:	3c048009 */ 	lui	$a0,0x8009
/*  f09c958:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f09c95c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f09c960:	240affff */ 	addiu	$t2,$zero,-1
/*  f09c964:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f09c968:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f09c96c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f09c970:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09c974:	240500e8 */ 	addiu	$a1,$zero,0xe8
/*  f09c978:	00003025 */ 	or	$a2,$zero,$zero
/*  f09c97c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09c980:	0c004241 */ 	jal	func00010904
/*  f09c984:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f09c988:	10400004 */ 	beqz	$v0,.L0f09c99c
/*  f09c98c:	00402025 */ 	or	$a0,$v0,$zero
/*  f09c990:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f09c994:	0c00cf94 */ 	jal	func00033e50
/*  f09c998:	8fa60034 */ 	lw	$a2,0x34($sp)
.L0f09c99c:
/*  f09c99c:	00002025 */ 	or	$a0,$zero,$zero
/*  f09c9a0:	0c01210c */ 	jal	func00048430
/*  f09c9a4:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f09c9a8:	10000011 */ 	beqz	$zero,.L0f09c9f0
/*  f09c9ac:	8e0e001c */ 	lw	$t6,0x1c($s0)
.L0f09c9b0:
/*  f09c9b0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09c9b4:	44819000 */ 	mtc1	$at,$f18
/*  f09c9b8:	3c048009 */ 	lui	$a0,0x8009
/*  f09c9bc:	240bffff */ 	addiu	$t3,$zero,-1
/*  f09c9c0:	240cffff */ 	addiu	$t4,$zero,-1
/*  f09c9c4:	240dffff */ 	addiu	$t5,$zero,-1
/*  f09c9c8:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f09c9cc:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f09c9d0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f09c9d4:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f09c9d8:	240500e8 */ 	addiu	$a1,$zero,0xe8
/*  f09c9dc:	00003025 */ 	or	$a2,$zero,$zero
/*  f09c9e0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09c9e4:	0c004241 */ 	jal	func00010904
/*  f09c9e8:	e7b20014 */ 	swc1	$f18,0x14($sp)
.L0f09c9ec:
/*  f09c9ec:	8e0e001c */ 	lw	$t6,0x1c($s0)
.L0f09c9f0:
/*  f09c9f0:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f09c9f4:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f09c9f8:	01cf082a */ 	slt	$at,$t6,$t7
/*  f09c9fc:	50200010 */ 	beqzl	$at,.L0f09ca40
/*  f09ca00:	8e090608 */ 	lw	$t1,0x608($s0)
/*  f09ca04:	0fc2c6b4 */ 	jal	func0f0b1ad0
/*  f09ca08:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f09ca0c:	1040000b */ 	beqz	$v0,.L0f09ca3c
/*  f09ca10:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f09ca14:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f09ca18:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f09ca1c:	24050040 */ 	addiu	$a1,$zero,0x40
/*  f09ca20:	10400006 */ 	beqz	$v0,.L0f09ca3c
/*  f09ca24:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f09ca28:	8d040000 */ 	lw	$a0,0x0($t0)
/*  f09ca2c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f09ca30:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f09ca34:	10400011 */ 	beqz	$v0,.L0f09ca7c
/*  f09ca38:	8fad0054 */ 	lw	$t5,0x54($sp)
.L0f09ca3c:
/*  f09ca3c:	8e090608 */ 	lw	$t1,0x608($s0)
.L0f09ca40:
/*  f09ca40:	ae000020 */ 	sw	$zero,0x20($s0)
/*  f09ca44:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f09ca48:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f09ca4c:	ae0a0608 */ 	sw	$t2,0x608($s0)
/*  f09ca50:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f09ca54:	24054000 */ 	addiu	$a1,$zero,0x4000
/*  f09ca58:	54400005 */ 	bnezl	$v0,.L0f09ca70
/*  f09ca5c:	ae00001c */ 	sw	$zero,0x1c($s0)
/*  f09ca60:	920b0690 */ 	lbu	$t3,0x690($s0)
/*  f09ca64:	316cffbf */ 	andi	$t4,$t3,0xffbf
/*  f09ca68:	a20c0690 */ 	sb	$t4,0x690($s0)
/*  f09ca6c:	ae00001c */ 	sw	$zero,0x1c($s0)
.L0f09ca70:
/*  f09ca70:	ae000018 */ 	sw	$zero,0x18($s0)
/*  f09ca74:	10000010 */ 	beqz	$zero,.L0f09cab8
/*  f09ca78:	8e020608 */ 	lw	$v0,0x608($s0)
.L0f09ca7c:
/*  f09ca7c:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f09ca80:	3c017f1b */ 	lui	$at,%hi(var7f1ac5ec)
/*  f09ca84:	c428c5ec */ 	lwc1	$f8,%lo(var7f1ac5ec)($at)
/*  f09ca88:	01ae7823 */ 	subu	$t7,$t5,$t6
/*  f09ca8c:	448f2000 */ 	mtc1	$t7,$f4
/*  f09ca90:	448d5000 */ 	mtc1	$t5,$f10
/*  f09ca94:	02002025 */ 	or	$a0,$s0,$zero
/*  f09ca98:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f09ca9c:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f09caa0:	46083402 */ 	mul.s	$f16,$f6,$f8
/*  f09caa4:	46128103 */ 	div.s	$f4,$f16,$f18
/*  f09caa8:	44052000 */ 	mfc1	$a1,$f4
/*  f09caac:	0fc265e0 */ 	jal	func0f099780
/*  f09cab0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09cab4:	8e020608 */ 	lw	$v0,0x608($s0)
.L0f09cab8:
/*  f09cab8:	24010004 */ 	addiu	$at,$zero,0x4
.L0f09cabc:
/*  f09cabc:	1441001b */ 	bne	$v0,$at,.L0f09cb2c
/*  f09cac0:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f09cac4:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f09cac8:	24054000 */ 	addiu	$a1,$zero,0x4000
/*  f09cacc:	8f280004 */ 	lw	$t0,0x4($t9)
/*  f09cad0:	51000010 */ 	beqzl	$t0,.L0f09cb14
/*  f09cad4:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f09cad8:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f09cadc:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f09cae0:	5440000c */ 	bnezl	$v0,.L0f09cb14
/*  f09cae4:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f09cae8:	8e09068c */ 	lw	$t1,0x68c($s0)
/*  f09caec:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f09caf0:	5520000f */ 	bnezl	$t1,.L0f09cb30
/*  f09caf4:	00001025 */ 	or	$v0,$zero,$zero
/*  f09caf8:	0fc27346 */ 	jal	func0f09cd18
/*  f09cafc:	00002825 */ 	or	$a1,$zero,$zero
/*  f09cb00:	5040000b */ 	beqzl	$v0,.L0f09cb30
/*  f09cb04:	00001025 */ 	or	$v0,$zero,$zero
/*  f09cb08:	10000009 */ 	beqz	$zero,.L0f09cb30
/*  f09cb0c:	8fa2007c */ 	lw	$v0,0x7c($sp)
/*  f09cb10:	8fa40074 */ 	lw	$a0,0x74($sp)
.L0f09cb14:
/*  f09cb14:	0fc27346 */ 	jal	func0f09cd18
/*  f09cb18:	00002825 */ 	or	$a1,$zero,$zero
/*  f09cb1c:	50400004 */ 	beqzl	$v0,.L0f09cb30
/*  f09cb20:	00001025 */ 	or	$v0,$zero,$zero
/*  f09cb24:	10000002 */ 	beqz	$zero,.L0f09cb30
/*  f09cb28:	8fa2007c */ 	lw	$v0,0x7c($sp)
.L0f09cb2c:
/*  f09cb2c:	00001025 */ 	or	$v0,$zero,$zero
.L0f09cb30:
/*  f09cb30:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f09cb34:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f09cb38:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f09cb3c:	03e00008 */ 	jr	$ra
/*  f09cb40:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09cb44
/*  f09cb44:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f09cb48:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f09cb4c:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f09cb50:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f09cb54:	03e00008 */ 	jr	$ra
/*  f09cb58:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0f09cb5c
/*  f09cb5c:	00057900 */ 	sll	$t7,$a1,0x4
/*  f09cb60:	01e57823 */ 	subu	$t7,$t7,$a1
/*  f09cb64:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f09cb68:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09cb6c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f09cb70:	01e57821 */ 	addu	$t7,$t7,$a1
/*  f09cb74:	8c4e0284 */ 	lw	$t6,0x284($v0)
/*  f09cb78:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f09cb7c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f09cb80:	01e57821 */ 	addu	$t7,$t7,$a1
/*  f09cb84:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f09cb88:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09cb8c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f09cb90:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f09cb94:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f09cb98:	8e030c3c */ 	lw	$v1,0xc3c($s0)
/*  f09cb9c:	00c08825 */ 	or	$s1,$a2,$zero
/*  f09cba0:	00003825 */ 	or	$a3,$zero,$zero
/*  f09cba4:	afa30024 */ 	sw	$v1,0x24($sp)
/*  f09cba8:	8e180c4c */ 	lw	$t8,0xc4c($s0)
/*  f09cbac:	a200063c */ 	sb	$zero,0x63c($s0)
/*  f09cbb0:	a200063d */ 	sb	$zero,0x63d($s0)
/*  f09cbb4:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f09cbb8:	ae190c4c */ 	sw	$t9,0xc4c($s0)
/*  f09cbbc:	8c480034 */ 	lw	$t0,0x34($v0)
/*  f09cbc0:	26100638 */ 	addiu	$s0,$s0,0x638
/*  f09cbc4:	5900000a */ 	blezl	$t0,.L0f09cbf0
/*  f09cbc8:	2c610009 */ 	sltiu	$at,$v1,0x9
/*  f09cbcc:	8e09001c */ 	lw	$t1,0x1c($s0)
/*  f09cbd0:	8c4a0038 */ 	lw	$t2,0x38($v0)
/*  f09cbd4:	8e0c0018 */ 	lw	$t4,0x18($s0)
/*  f09cbd8:	8e030604 */ 	lw	$v1,0x604($s0)
/*  f09cbdc:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f09cbe0:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f09cbe4:	ae0b001c */ 	sw	$t3,0x1c($s0)
/*  f09cbe8:	ae0d0018 */ 	sw	$t5,0x18($s0)
/*  f09cbec:	2c610009 */ 	sltiu	$at,$v1,0x9
.L0f09cbf0:
/*  f09cbf0:	10200036 */ 	beqz	$at,.L0f09cccc
/*  f09cbf4:	ae0000b4 */ 	sw	$zero,0xb4($s0)
/*  f09cbf8:	00037080 */ 	sll	$t6,$v1,0x2
/*  f09cbfc:	3c017f1b */ 	lui	$at,%hi(var7f1ac5f0)
/*  f09cc00:	002e0821 */ 	addu	$at,$at,$t6
/*  f09cc04:	8c2ec5f0 */ 	lw	$t6,%lo(var7f1ac5f0)($at)
/*  f09cc08:	01c00008 */ 	jr	$t6
/*  f09cc0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09cc10:	02003025 */ 	or	$a2,$s0,$zero
/*  f09cc14:	0fc26479 */ 	jal	func0f0991e4
/*  f09cc18:	02203825 */ 	or	$a3,$s1,$zero
/*  f09cc1c:	00403825 */ 	or	$a3,$v0,$zero
/*  f09cc20:	1000002a */ 	beqz	$zero,.L0f09cccc
/*  f09cc24:	8e030604 */ 	lw	$v1,0x604($s0)
/*  f09cc28:	02003025 */ 	or	$a2,$s0,$zero
/*  f09cc2c:	0fc26712 */ 	jal	func0f099c48
/*  f09cc30:	02203825 */ 	or	$a3,$s1,$zero
/*  f09cc34:	00403825 */ 	or	$a3,$v0,$zero
/*  f09cc38:	10000024 */ 	beqz	$zero,.L0f09cccc
/*  f09cc3c:	8e030604 */ 	lw	$v1,0x604($s0)
/*  f09cc40:	02003025 */ 	or	$a2,$s0,$zero
/*  f09cc44:	0fc26f0b */ 	jal	func0f09bc2c
/*  f09cc48:	02203825 */ 	or	$a3,$s1,$zero
/*  f09cc4c:	00403825 */ 	or	$a3,$v0,$zero
/*  f09cc50:	1000001e */ 	beqz	$zero,.L0f09cccc
/*  f09cc54:	8e030604 */ 	lw	$v1,0x604($s0)
/*  f09cc58:	02003025 */ 	or	$a2,$s0,$zero
/*  f09cc5c:	0fc272d1 */ 	jal	func0f09cb44
/*  f09cc60:	02203825 */ 	or	$a3,$s1,$zero
/*  f09cc64:	00403825 */ 	or	$a3,$v0,$zero
/*  f09cc68:	10000018 */ 	beqz	$zero,.L0f09cccc
/*  f09cc6c:	8e030604 */ 	lw	$v1,0x604($s0)
/*  f09cc70:	02003025 */ 	or	$a2,$s0,$zero
/*  f09cc74:	0fc27007 */ 	jal	func0f09c01c
/*  f09cc78:	02203825 */ 	or	$a3,$s1,$zero
/*  f09cc7c:	00403825 */ 	or	$a3,$v0,$zero
/*  f09cc80:	10000012 */ 	beqz	$zero,.L0f09cccc
/*  f09cc84:	8e030604 */ 	lw	$v1,0x604($s0)
/*  f09cc88:	02003025 */ 	or	$a2,$s0,$zero
/*  f09cc8c:	0fc26e38 */ 	jal	func0f09b8e0
/*  f09cc90:	02203825 */ 	or	$a3,$s1,$zero
/*  f09cc94:	00403825 */ 	or	$a3,$v0,$zero
/*  f09cc98:	1000000c */ 	beqz	$zero,.L0f09cccc
/*  f09cc9c:	8e030604 */ 	lw	$v1,0x604($s0)
/*  f09cca0:	02003025 */ 	or	$a2,$s0,$zero
/*  f09cca4:	0fc26602 */ 	jal	func0f099808
/*  f09cca8:	02203825 */ 	or	$a3,$s1,$zero
/*  f09ccac:	00403825 */ 	or	$a3,$v0,$zero
/*  f09ccb0:	10000006 */ 	beqz	$zero,.L0f09cccc
/*  f09ccb4:	8e030604 */ 	lw	$v1,0x604($s0)
/*  f09ccb8:	02003025 */ 	or	$a2,$s0,$zero
/*  f09ccbc:	0fc268c4 */ 	jal	func0f09a310
/*  f09ccc0:	02203825 */ 	or	$a3,$s1,$zero
/*  f09ccc4:	00403825 */ 	or	$a3,$v0,$zero
/*  f09ccc8:	8e030604 */ 	lw	$v1,0x604($s0)
.L0f09cccc:
/*  f09cccc:	8e020614 */ 	lw	$v0,0x614($s0)
/*  f09ccd0:	0007c023 */ 	negu	$t8,$a3
/*  f09ccd4:	ae02061c */ 	sw	$v0,0x61c($s0)
/*  f09ccd8:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f09ccdc:	51e30004 */ 	beql	$t7,$v1,.L0f09ccf0
/*  f09cce0:	8e080618 */ 	lw	$t0,0x618($s0)
/*  f09cce4:	10000006 */ 	beqz	$zero,.L0f09cd00
/*  f09cce8:	ae18061c */ 	sw	$t8,0x61c($s0)
/*  f09ccec:	8e080618 */ 	lw	$t0,0x618($s0)
.L0f09ccf0:
/*  f09ccf0:	0047c823 */ 	subu	$t9,$v0,$a3
/*  f09ccf4:	ae190614 */ 	sw	$t9,0x614($s0)
/*  f09ccf8:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f09ccfc:	ae090618 */ 	sw	$t1,0x618($s0)
.L0f09cd00:
/*  f09cd00:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f09cd04:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f09cd08:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f09cd0c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f09cd10:	03e00008 */ 	jr	$ra
/*  f09cd14:	00e01025 */ 	or	$v0,$a3,$zero
);

GLOBAL_ASM(
glabel func0f09cd18
/*  f09cd18:	00047900 */ 	sll	$t7,$a0,0x4
/*  f09cd1c:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f09cd20:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09cd24:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f09cd28:	3c0e800a */ 	lui	$t6,0x800a
/*  f09cd2c:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f09cd30:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f09cd34:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f09cd38:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09cd3c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f09cd40:	24010007 */ 	addiu	$at,$zero,0x7
/*  f09cd44:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f09cd48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f09cd4c:	00a03825 */ 	or	$a3,$a1,$zero
/*  f09cd50:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f09cd54:	14a1000e */ 	bne	$a1,$at,.L0f09cd90
/*  f09cd58:	24c60638 */ 	addiu	$a2,$a2,0x638
/*  f09cd5c:	90d80003 */ 	lbu	$t8,0x3($a2)
/*  f09cd60:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f09cd64:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f09cd68:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f09cd6c:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f09cd70:	00c02025 */ 	or	$a0,$a2,$zero
/*  f09cd74:	0fc2c42e */ 	jal	func0f0b10b8
/*  f09cd78:	03382823 */ 	subu	$a1,$t9,$t8
/*  f09cd7c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f09cd80:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f09cd84:	14400002 */ 	bnez	$v0,.L0f09cd90
/*  f09cd88:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f09cd8c:	00001825 */ 	or	$v1,$zero,$zero
.L0f09cd90:
/*  f09cd90:	50600008 */ 	beqzl	$v1,.L0f09cdb4
/*  f09cd94:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09cd98:	acc70604 */ 	sw	$a3,0x604($a2)
/*  f09cd9c:	acc00614 */ 	sw	$zero,0x614($a2)
/*  f09cda0:	acc0060c */ 	sw	$zero,0x60c($a2)
/*  f09cda4:	acc00618 */ 	sw	$zero,0x618($a2)
/*  f09cda8:	acc00608 */ 	sw	$zero,0x608($a2)
/*  f09cdac:	acc0061c */ 	sw	$zero,0x61c($a2)
/*  f09cdb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f09cdb4:
/*  f09cdb4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f09cdb8:	00601025 */ 	or	$v0,$v1,$zero
/*  f09cdbc:	03e00008 */ 	jr	$ra
/*  f09cdc0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09cdc4
/*  f09cdc4:	00047900 */ 	sll	$t7,$a0,0x4
/*  f09cdc8:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f09cdcc:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f09cdd0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09cdd4:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f09cdd8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f09cddc:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f09cde0:	8cce0284 */ 	lw	$t6,0x284($a2)
/*  f09cde4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f09cde8:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f09cdec:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09cdf0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f09cdf4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f09cdf8:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f09cdfc:	00809825 */ 	or	$s3,$a0,$zero
/*  f09ce00:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f09ce04:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f09ce08:	24630638 */ 	addiu	$v1,$v1,0x638
/*  f09ce0c:	27b20030 */ 	addiu	$s2,$sp,0x30
/*  f09ce10:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f09ce14:	24110014 */ 	addiu	$s1,$zero,0x14
/*  f09ce18:	02402025 */ 	or	$a0,$s2,$zero
/*  f09ce1c:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f09ce20:	0fc26313 */ 	jal	func0f098c4c
/*  f09ce24:	02602825 */ 	or	$a1,$s3,$zero
/*  f09ce28:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f09ce2c:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f09ce30:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f09ce34:	8cd00038 */ 	lw	$s0,0x38($a2)
/*  f09ce38:	8c780688 */ 	lw	$t8,0x688($v1)
/*  f09ce3c:	ac700684 */ 	sw	$s0,0x684($v1)
/*  f09ce40:	8cd90038 */ 	lw	$t9,0x38($a2)
/*  f09ce44:	03194021 */ 	addu	$t0,$t8,$t9
/*  f09ce48:	ac680688 */ 	sw	$t0,0x688($v1)
/*  f09ce4c:	02402025 */ 	or	$a0,$s2,$zero
.L0f09ce50:
/*  f09ce50:	02602825 */ 	or	$a1,$s3,$zero
/*  f09ce54:	0fc272d7 */ 	jal	func0f09cb5c
/*  f09ce58:	02003025 */ 	or	$a2,$s0,$zero
/*  f09ce5c:	00408025 */ 	or	$s0,$v0,$zero
/*  f09ce60:	18400003 */ 	blez	$v0,.L0f09ce70
/*  f09ce64:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f09ce68:	0623fff9 */ 	bgezl	$s1,.L0f09ce50
/*  f09ce6c:	02402025 */ 	or	$a0,$s2,$zero
.L0f09ce70:
/*  f09ce70:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f09ce74:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f09ce78:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f09ce7c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f09ce80:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f09ce84:	03e00008 */ 	jr	$ra
/*  f09ce88:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f09ce8c
/*  f09ce8c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f09ce90:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f09ce94:	0fc2854a */ 	jal	func0f0a1528
/*  f09ce98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ce9c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09cea0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f09cea4:	03e00008 */ 	jr	$ra
/*  f09cea8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09ceac
/*  f09ceac:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f09ceb0:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f09ceb4:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f09ceb8:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f09cebc:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f09cec0:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f09cec4:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f09cec8:	4480a000 */ 	mtc1	$zero,$f20
/*  f09cecc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f09ced0:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f09ced4:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f09ced8:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f09cedc:	00009025 */ 	or	$s2,$zero,$zero
/*  f09cee0:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f09cee4:	24150002 */ 	addiu	$s5,$zero,0x2
.L0f09cee8:
/*  f09cee8:	56400005 */ 	bnezl	$s2,.L0f09cf00
/*  f09ceec:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f09cef0:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f09cef4:	10000003 */ 	beqz	$zero,.L0f09cf04
/*  f09cef8:	26100ddc */ 	addiu	$s0,$s0,0xddc
/*  f09cefc:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f09cf00:
/*  f09cf00:	26100638 */ 	addiu	$s0,$s0,0x638
.L0f09cf04:
/*  f09cf04:	261103a8 */ 	addiu	$s1,$s0,0x3a8
/*  f09cf08:	e61406d0 */ 	swc1	$f20,0x6d0($s0)
/*  f09cf0c:	ae000604 */ 	sw	$zero,0x604($s0)
/*  f09cf10:	ae140680 */ 	sw	$s4,0x680($s0)
/*  f09cf14:	ae00068c */ 	sw	$zero,0x68c($s0)
/*  f09cf18:	0c008c28 */ 	jal	func000230a0
/*  f09cf1c:	02202025 */ 	or	$a0,$s1,$zero
/*  f09cf20:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f09cf24:	ae1103a4 */ 	sw	$s1,0x3a4($s0)
/*  f09cf28:	1655ffef */ 	bne	$s2,$s5,.L0f09cee8
/*  f09cf2c:	ae110554 */ 	sw	$s1,0x554($s0)
/*  f09cf30:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f09cf34:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f09cf38:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f09cf3c:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f09cf40:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f09cf44:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f09cf48:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f09cf4c:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f09cf50:	03e00008 */ 	jr	$ra
/*  f09cf54:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f09cf58
/*  f09cf58:	00047900 */ 	sll	$t7,$a0,0x4
/*  f09cf5c:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f09cf60:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09cf64:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f09cf68:	3c0e800a */ 	lui	$t6,0x800a
/*  f09cf6c:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f09cf70:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f09cf74:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f09cf78:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09cf7c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f09cf80:	03e00008 */ 	jr	$ra
/*  f09cf84:	c7000840 */ 	lwc1	$f0,0x840($t8)
);

GLOBAL_ASM(
glabel func0f09cf88
/*  f09cf88:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f09cf8c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f09cf90:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f09cf94:	3c10800a */ 	lui	$s0,0x800a
/*  f09cf98:	8e10a244 */ 	lw	$s0,-0x5dbc($s0)
/*  f09cf9c:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f09cfa0:	0fc2c6bc */ 	jal	func0f0b1af0
/*  f09cfa4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f09cfa8:	00002025 */ 	or	$a0,$zero,$zero
/*  f09cfac:	0fc2c6bc */ 	jal	func0f0b1af0
/*  f09cfb0:	27a50050 */ 	addiu	$a1,$sp,0x50
/*  f09cfb4:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f09cfb8:	0fc2c807 */ 	jal	func0f0b201c
/*  f09cfbc:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f09cfc0:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f09cfc4:	0fc2c807 */ 	jal	func0f0b201c
/*  f09cfc8:	27a50028 */ 	addiu	$a1,$sp,0x28
/*  f09cfcc:	0fc2883f */ 	jal	func0f0a20fc
/*  f09cfd0:	00002025 */ 	or	$a0,$zero,$zero
/*  f09cfd4:	1040000c */ 	beqz	$v0,.L0f09d008
/*  f09cfd8:	3c014270 */ 	lui	$at,0x4270
/*  f09cfdc:	c6040840 */ 	lwc1	$f4,0x840($s0)
/*  f09cfe0:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*  f09cfe4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f09cfe8:	e6080840 */ 	swc1	$f8,0x840($s0)
/*  f09cfec:	c6120840 */ 	lwc1	$f18,0x840($s0)
/*  f09cff0:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f09cff4:	4612503c */ 	c.lt.s	$f10,$f18
/*  f09cff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09cffc:	45020003 */ 	bc1fl	.L0f09d00c
/*  f09d000:	44818000 */ 	mtc1	$at,$f16
/*  f09d004:	e60a0840 */ 	swc1	$f10,0x840($s0)
.L0f09d008:
/*  f09d008:	44818000 */ 	mtc1	$at,$f16
.L0f09d00c:
/*  f09d00c:	3c01800a */ 	lui	$at,0x800a
/*  f09d010:	c420a00c */ 	lwc1	$f0,-0x5ff4($at)
/*  f09d014:	c7a40030 */ 	lwc1	$f4,0x30($sp)
/*  f09d018:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f09d01c:	c60e0840 */ 	lwc1	$f14,0x840($s0)
/*  f09d020:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f09d024:	c7aa0028 */ 	lwc1	$f10,0x28($sp)
/*  f09d028:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f09d02c:	460a7101 */ 	sub.s	$f4,$f14,$f10
/*  f09d030:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f09d034:	46123303 */ 	div.s	$f12,$f6,$f18
/*  f09d038:	c7a60038 */ 	lwc1	$f6,0x38($sp)
/*  f09d03c:	46103482 */ 	mul.s	$f18,$f6,$f16
/*  f09d040:	46124083 */ 	div.s	$f2,$f8,$f18
/*  f09d044:	4602603c */ 	c.lt.s	$f12,$f2
/*  f09d048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d04c:	45020003 */ 	bc1fl	.L0f09d05c
/*  f09d050:	460c7281 */ 	sub.s	$f10,$f14,$f12
/*  f09d054:	46001306 */ 	mov.s	$f12,$f2
/*  f09d058:	460c7281 */ 	sub.s	$f10,$f14,$f12
.L0f09d05c:
/*  f09d05c:	e60a0840 */ 	swc1	$f10,0x840($s0)
/*  f09d060:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*  f09d064:	c6040840 */ 	lwc1	$f4,0x840($s0)
/*  f09d068:	4606203c */ 	c.lt.s	$f4,$f6
/*  f09d06c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d070:	45000002 */ 	bc1f	.L0f09d07c
/*  f09d074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d078:	e6060840 */ 	swc1	$f6,0x840($s0)
.L0f09d07c:
/*  f09d07c:	0fc2883f */ 	jal	func0f0a20fc
/*  f09d080:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f09d084:	3c014270 */ 	lui	$at,0x4270
/*  f09d088:	44818000 */ 	mtc1	$at,$f16
/*  f09d08c:	1040000c */ 	beqz	$v0,.L0f09d0c0
/*  f09d090:	3c01800a */ 	lui	$at,0x800a
/*  f09d094:	c6080fe4 */ 	lwc1	$f8,0xfe4($s0)
/*  f09d098:	c7b20044 */ 	lwc1	$f18,0x44($sp)
/*  f09d09c:	46124280 */ 	add.s	$f10,$f8,$f18
/*  f09d0a0:	e60a0fe4 */ 	swc1	$f10,0xfe4($s0)
/*  f09d0a4:	c6060fe4 */ 	lwc1	$f6,0xfe4($s0)
/*  f09d0a8:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*  f09d0ac:	4606203c */ 	c.lt.s	$f4,$f6
/*  f09d0b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d0b4:	45000002 */ 	bc1f	.L0f09d0c0
/*  f09d0b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d0bc:	e6040fe4 */ 	swc1	$f4,0xfe4($s0)
.L0f09d0c0:
/*  f09d0c0:	c420a00c */ 	lwc1	$f0,-0x5ff4($at)
/*  f09d0c4:	c7a80044 */ 	lwc1	$f8,0x44($sp)
/*  f09d0c8:	c7aa0048 */ 	lwc1	$f10,0x48($sp)
/*  f09d0cc:	c60e0fe4 */ 	lwc1	$f14,0xfe4($s0)
/*  f09d0d0:	46080482 */ 	mul.s	$f18,$f0,$f8
/*  f09d0d4:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*  f09d0d8:	46105182 */ 	mul.s	$f6,$f10,$f16
/*  f09d0dc:	46047201 */ 	sub.s	$f8,$f14,$f4
/*  f09d0e0:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f09d0e4:	46069303 */ 	div.s	$f12,$f18,$f6
/*  f09d0e8:	c7b2004c */ 	lwc1	$f18,0x4c($sp)
/*  f09d0ec:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f09d0f0:	46065083 */ 	div.s	$f2,$f10,$f6
/*  f09d0f4:	4602603c */ 	c.lt.s	$f12,$f2
/*  f09d0f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d0fc:	45020003 */ 	bc1fl	.L0f09d10c
/*  f09d100:	460c7101 */ 	sub.s	$f4,$f14,$f12
/*  f09d104:	46001306 */ 	mov.s	$f12,$f2
/*  f09d108:	460c7101 */ 	sub.s	$f4,$f14,$f12
.L0f09d10c:
/*  f09d10c:	e6040fe4 */ 	swc1	$f4,0xfe4($s0)
/*  f09d110:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f09d114:	c6080fe4 */ 	lwc1	$f8,0xfe4($s0)
/*  f09d118:	4612403c */ 	c.lt.s	$f8,$f18
/*  f09d11c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d120:	45020003 */ 	bc1fl	.L0f09d130
/*  f09d124:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f09d128:	e6120fe4 */ 	swc1	$f18,0xfe4($s0)
/*  f09d12c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f09d130:
/*  f09d130:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f09d134:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f09d138:	03e00008 */ 	jr	$ra
/*  f09d13c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09d140
/*  f09d140:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f09d144:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f09d148:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f09d14c:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f09d150:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f09d154:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f09d158:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f09d15c:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f09d160:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f09d164:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f09d168:	0fc2c3f4 */ 	jal	weaponFindById
/*  f09d16c:	00402025 */ 	or	$a0,$v0,$zero
/*  f09d170:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f09d174:	3c05800a */ 	lui	$a1,0x800a
/*  f09d178:	8ca5a244 */ 	lw	$a1,-0x5dbc($a1)
/*  f09d17c:	00067900 */ 	sll	$t7,$a2,0x4
/*  f09d180:	01e67823 */ 	subu	$t7,$t7,$a2
/*  f09d184:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09d188:	01e67821 */ 	addu	$t7,$t7,$a2
/*  f09d18c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f09d190:	01e67821 */ 	addu	$t7,$t7,$a2
/*  f09d194:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09d198:	00af9021 */ 	addu	$s2,$a1,$t7
/*  f09d19c:	8e5807c8 */ 	lw	$t8,0x7c8($s2)
/*  f09d1a0:	27ae0060 */ 	addiu	$t6,$sp,0x60
/*  f09d1a4:	00061880 */ 	sll	$v1,$a2,0x2
/*  f09d1a8:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f09d1ac:	c4540038 */ 	lwc1	$f20,0x38($v0)
/*  f09d1b0:	006e8021 */ 	addu	$s0,$v1,$t6
/*  f09d1b4:	07210004 */ 	bgez	$t9,.L0f09d1c8
/*  f09d1b8:	33280003 */ 	andi	$t0,$t9,0x3
/*  f09d1bc:	11000002 */ 	beqz	$t0,.L0f09d1c8
/*  f09d1c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d1c4:	2508fffc */ 	addiu	$t0,$t0,-4
.L0f09d1c8:
/*  f09d1c8:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f09d1cc:	8e4a07c8 */ 	lw	$t2,0x7c8($s2)
/*  f09d1d0:	27a90058 */ 	addiu	$t1,$sp,0x58
/*  f09d1d4:	00692021 */ 	addu	$a0,$v1,$t1
/*  f09d1d8:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f09d1dc:	05610004 */ 	bgez	$t3,.L0f09d1f0
/*  f09d1e0:	316c0003 */ 	andi	$t4,$t3,0x3
/*  f09d1e4:	11800002 */ 	beqz	$t4,.L0f09d1f0
/*  f09d1e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d1ec:	258cfffc */ 	addiu	$t4,$t4,-4
.L0f09d1f0:
/*  f09d1f0:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f09d1f4:	ae4c07c8 */ 	sw	$t4,0x7c8($s2)
/*  f09d1f8:	0c004b70 */ 	jal	random
/*  f09d1fc:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f09d200:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f09d204:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f09d208:	44822000 */ 	mtc1	$v0,$f4
/*  f09d20c:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f09d210:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f09d214:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09d218:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f09d21c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f09d220:	3c012f80 */ 	lui	$at,0x2f80
/*  f09d224:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f09d228:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09d22c:	4481b000 */ 	mtc1	$at,$f22
/*  f09d230:	2413000c */ 	addiu	$s3,$zero,0xc
/*  f09d234:	00af8821 */ 	addu	$s1,$a1,$t7
/*  f09d238:	04410005 */ 	bgez	$v0,.L0f09d250
/*  f09d23c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f09d240:	3c014f80 */ 	lui	$at,0x4f80
/*  f09d244:	44814000 */ 	mtc1	$at,$f8
/*  f09d248:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d24c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f09d250:
/*  f09d250:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f09d254:	3c013f00 */ 	lui	$at,0x3f00
/*  f09d258:	44818000 */ 	mtc1	$at,$f16
/*  f09d25c:	3c017f1b */ 	lui	$at,%hi(var7f1ac614)
/*  f09d260:	c424c614 */ 	lwc1	$f4,%lo(var7f1ac614)($at)
/*  f09d264:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f09d268:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f09d26c:	03130019 */ 	multu	$t8,$s3
/*  f09d270:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f09d274:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d278:	46144182 */ 	mul.s	$f6,$f8,$f20
/*  f09d27c:	0000c812 */ 	mflo	$t9
/*  f09d280:	02394021 */ 	addu	$t0,$s1,$t9
/*  f09d284:	0c004b70 */ 	jal	random
/*  f09d288:	e5060768 */ 	swc1	$f6,0x768($t0)
/*  f09d28c:	44825000 */ 	mtc1	$v0,$f10
/*  f09d290:	04410005 */ 	bgez	$v0,.L0f09d2a8
/*  f09d294:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f09d298:	3c014f80 */ 	lui	$at,0x4f80
/*  f09d29c:	44819000 */ 	mtc1	$at,$f18
/*  f09d2a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d2a4:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f09d2a8:
/*  f09d2a8:	46168102 */ 	mul.s	$f4,$f16,$f22
/*  f09d2ac:	3c013f00 */ 	lui	$at,0x3f00
/*  f09d2b0:	44814000 */ 	mtc1	$at,$f8
/*  f09d2b4:	3c017f1b */ 	lui	$at,%hi(var7f1ac618)
/*  f09d2b8:	c42ac618 */ 	lwc1	$f10,%lo(var7f1ac618)($at)
/*  f09d2bc:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f09d2c0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09d2c4:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f09d2c8:	01330019 */ 	multu	$t1,$s3
/*  f09d2cc:	44812000 */ 	mtc1	$at,$f4
/*  f09d2d0:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f09d2d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d2d8:	46149402 */ 	mul.s	$f16,$f18,$f20
/*  f09d2dc:	00005012 */ 	mflo	$t2
/*  f09d2e0:	022a5821 */ 	addu	$t3,$s1,$t2
/*  f09d2e4:	e570076c */ 	swc1	$f16,0x76c($t3)
/*  f09d2e8:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f09d2ec:	01930019 */ 	multu	$t4,$s3
/*  f09d2f0:	00006812 */ 	mflo	$t5
/*  f09d2f4:	022d7021 */ 	addu	$t6,$s1,$t5
/*  f09d2f8:	0c004b70 */ 	jal	random
/*  f09d2fc:	e5c40770 */ 	swc1	$f4,0x770($t6)
/*  f09d300:	44824000 */ 	mtc1	$v0,$f8
/*  f09d304:	3c014f80 */ 	lui	$at,0x4f80
/*  f09d308:	04410004 */ 	bgez	$v0,.L0f09d31c
/*  f09d30c:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f09d310:	44815000 */ 	mtc1	$at,$f10
/*  f09d314:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d318:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f09d31c:
/*  f09d31c:	46163482 */ 	mul.s	$f18,$f6,$f22
/*  f09d320:	3c013f00 */ 	lui	$at,0x3f00
/*  f09d324:	44818000 */ 	mtc1	$at,$f16
/*  f09d328:	3c017f1b */ 	lui	$at,%hi(var7f1ac61c)
/*  f09d32c:	c428c61c */ 	lwc1	$f8,%lo(var7f1ac61c)($at)
/*  f09d330:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f09d334:	3c013f80 */ 	lui	$at,0x3f80
/*  f09d338:	46109101 */ 	sub.s	$f4,$f18,$f16
/*  f09d33c:	01f30019 */ 	multu	$t7,$s3
/*  f09d340:	44819000 */ 	mtc1	$at,$f18
/*  f09d344:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f09d348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d34c:	46145182 */ 	mul.s	$f6,$f10,$f20
/*  f09d350:	0000c012 */ 	mflo	$t8
/*  f09d354:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f09d358:	e7260798 */ 	swc1	$f6,0x798($t9)
/*  f09d35c:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f09d360:	01130019 */ 	multu	$t0,$s3
/*  f09d364:	00004812 */ 	mflo	$t1
/*  f09d368:	02295021 */ 	addu	$t2,$s1,$t1
/*  f09d36c:	0c004b70 */ 	jal	random
/*  f09d370:	e552079c */ 	swc1	$f18,0x79c($t2)
/*  f09d374:	44828000 */ 	mtc1	$v0,$f16
/*  f09d378:	3c014f80 */ 	lui	$at,0x4f80
/*  f09d37c:	04410004 */ 	bgez	$v0,.L0f09d390
/*  f09d380:	46808120 */ 	cvt.s.w	$f4,$f16
/*  f09d384:	44814000 */ 	mtc1	$at,$f8
/*  f09d388:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d38c:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f09d390:
/*  f09d390:	46162282 */ 	mul.s	$f10,$f4,$f22
/*  f09d394:	3c013f00 */ 	lui	$at,0x3f00
/*  f09d398:	44813000 */ 	mtc1	$at,$f6
/*  f09d39c:	3c017f1b */ 	lui	$at,%hi(var7f1ac620)
/*  f09d3a0:	c430c620 */ 	lwc1	$f16,%lo(var7f1ac620)($at)
/*  f09d3a4:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f09d3a8:	46065481 */ 	sub.s	$f18,$f10,$f6
/*  f09d3ac:	01730019 */ 	multu	$t3,$s3
/*  f09d3b0:	46109202 */ 	mul.s	$f8,$f18,$f16
/*  f09d3b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d3b8:	46144102 */ 	mul.s	$f4,$f8,$f20
/*  f09d3bc:	00006012 */ 	mflo	$t4
/*  f09d3c0:	022c6821 */ 	addu	$t5,$s1,$t4
/*  f09d3c4:	0c004b70 */ 	jal	random
/*  f09d3c8:	e5a407a0 */ 	swc1	$f4,0x7a0($t5)
/*  f09d3cc:	44825000 */ 	mtc1	$v0,$f10
/*  f09d3d0:	3c014f80 */ 	lui	$at,0x4f80
/*  f09d3d4:	04410004 */ 	bgez	$v0,.L0f09d3e8
/*  f09d3d8:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f09d3dc:	44819000 */ 	mtc1	$at,$f18
/*  f09d3e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d3e4:	46123180 */ 	add.s	$f6,$f6,$f18
.L0f09d3e8:
/*  f09d3e8:	46163402 */ 	mul.s	$f16,$f6,$f22
/*  f09d3ec:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f09d3f0:	3c013f40 */ 	lui	$at,0x3f40
/*  f09d3f4:	44814000 */ 	mtc1	$at,$f8
/*  f09d3f8:	01d30019 */ 	multu	$t6,$s3
/*  f09d3fc:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f09d400:	44815000 */ 	mtc1	$at,$f10
/*  f09d404:	46088102 */ 	mul.s	$f4,$f16,$f8
/*  f09d408:	460a2480 */ 	add.s	$f18,$f4,$f10
/*  f09d40c:	00007812 */ 	mflo	$t7
/*  f09d410:	022fc021 */ 	addu	$t8,$s1,$t7
/*  f09d414:	0c004b70 */ 	jal	random
/*  f09d418:	e7120738 */ 	swc1	$f18,0x738($t8)
/*  f09d41c:	44828000 */ 	mtc1	$v0,$f16
/*  f09d420:	3c014000 */ 	lui	$at,0x4000
/*  f09d424:	44813000 */ 	mtc1	$at,$f6
/*  f09d428:	04410005 */ 	bgez	$v0,.L0f09d440
/*  f09d42c:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f09d430:	3c014f80 */ 	lui	$at,0x4f80
/*  f09d434:	44812000 */ 	mtc1	$at,$f4
/*  f09d438:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d43c:	46044200 */ 	add.s	$f8,$f8,$f4
.L0f09d440:
/*  f09d440:	46164282 */ 	mul.s	$f10,$f8,$f22
/*  f09d444:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f09d448:	c65007d4 */ 	lwc1	$f16,0x7d4($s2)
/*  f09d44c:	03330019 */ 	multu	$t9,$s3
/*  f09d450:	460a3480 */ 	add.s	$f18,$f6,$f10
/*  f09d454:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f09d458:	00004012 */ 	mflo	$t0
/*  f09d45c:	02484821 */ 	addu	$t1,$s2,$t0
/*  f09d460:	0c004b70 */ 	jal	random
/*  f09d464:	e524073c */ 	swc1	$f4,0x73c($t1)
/*  f09d468:	44824000 */ 	mtc1	$v0,$f8
/*  f09d46c:	3c014f80 */ 	lui	$at,0x4f80
/*  f09d470:	04410004 */ 	bgez	$v0,.L0f09d484
/*  f09d474:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f09d478:	44815000 */ 	mtc1	$at,$f10
/*  f09d47c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d480:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f09d484:
/*  f09d484:	46163402 */ 	mul.s	$f16,$f6,$f22
/*  f09d488:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f09d48c:	3c013f00 */ 	lui	$at,0x3f00
/*  f09d490:	44819000 */ 	mtc1	$at,$f18
/*  f09d494:	01530019 */ 	multu	$t2,$s3
/*  f09d498:	3c014020 */ 	lui	$at,0x4020
/*  f09d49c:	44814000 */ 	mtc1	$at,$f8
/*  f09d4a0:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f09d4a4:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f09d4a8:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f09d4ac:	00005812 */ 	mflo	$t3
/*  f09d4b0:	024b6021 */ 	addu	$t4,$s2,$t3
/*  f09d4b4:	e58a0740 */ 	swc1	$f10,0x740($t4)
/*  f09d4b8:	8e4307d8 */ 	lw	$v1,0x7d8($s2)
/*  f09d4bc:	04610013 */ 	bgez	$v1,.L0f09d50c
/*  f09d4c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d4c4:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f09d4c8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09d4cc:	44818000 */ 	mtc1	$at,$f16
/*  f09d4d0:	01b30019 */ 	multu	$t5,$s3
/*  f09d4d4:	2403fffe */ 	addiu	$v1,$zero,-2
/*  f09d4d8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f09d4dc:	00007012 */ 	mflo	$t6
/*  f09d4e0:	024e1021 */ 	addu	$v0,$s2,$t6
/*  f09d4e4:	c4460738 */ 	lwc1	$f6,0x738($v0)
/*  f09d4e8:	46103482 */ 	mul.s	$f18,$f6,$f16
/*  f09d4ec:	e4520738 */ 	swc1	$f18,0x738($v0)
/*  f09d4f0:	8e4f07d8 */ 	lw	$t7,0x7d8($s2)
/*  f09d4f4:	146f0003 */ 	bne	$v1,$t7,.L0f09d504
/*  f09d4f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d4fc:	10000008 */ 	beqz	$zero,.L0f09d520
/*  f09d500:	ae5807d8 */ 	sw	$t8,0x7d8($s2)
.L0f09d504:
/*  f09d504:	10000006 */ 	beqz	$zero,.L0f09d520
/*  f09d508:	ae4307d8 */ 	sw	$v1,0x7d8($s2)
.L0f09d50c:
/*  f09d50c:	14430003 */ 	bne	$v0,$v1,.L0f09d51c
/*  f09d510:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f09d514:	10000002 */ 	beqz	$zero,.L0f09d520
/*  f09d518:	ae5907d8 */ 	sw	$t9,0x7d8($s2)
.L0f09d51c:
/*  f09d51c:	ae4207d8 */ 	sw	$v0,0x7d8($s2)
.L0f09d520:
/*  f09d520:	c64407d4 */ 	lwc1	$f4,0x7d4($s2)
/*  f09d524:	46002207 */ 	neg.s	$f8,$f4
/*  f09d528:	e64807d4 */ 	swc1	$f8,0x7d4($s2)
/*  f09d52c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f09d530:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f09d534:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f09d538:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f09d53c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f09d540:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f09d544:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f09d548:	03e00008 */ 	jr	$ra
/*  f09d54c:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f09d550
/*  f09d550:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f09d554:	3c0e8007 */ 	lui	$t6,%hi(var80070134)
/*  f09d558:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f09d55c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f09d560:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f09d564:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f09d568:	25ce0134 */ 	addiu	$t6,$t6,%lo(var80070134)
/*  f09d56c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f09d570:	27ac005c */ 	addiu	$t4,$sp,0x5c
/*  f09d574:	3c188007 */ 	lui	$t8,%hi(var80070140)
/*  f09d578:	ad810000 */ 	sw	$at,0x0($t4)
/*  f09d57c:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f09d580:	27180140 */ 	addiu	$t8,$t8,%lo(var80070140)
/*  f09d584:	27ad0050 */ 	addiu	$t5,$sp,0x50
/*  f09d588:	ad990004 */ 	sw	$t9,0x4($t4)
/*  f09d58c:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f09d590:	3c0f8007 */ 	lui	$t7,%hi(var8007014c)
/*  f09d594:	25ef014c */ 	addiu	$t7,$t7,%lo(var8007014c)
/*  f09d598:	ad810008 */ 	sw	$at,0x8($t4)
/*  f09d59c:	8f010000 */ 	lw	$at,0x0($t8)
/*  f09d5a0:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f09d5a4:	27ae0044 */ 	addiu	$t6,$sp,0x44
/*  f09d5a8:	ada10000 */ 	sw	$at,0x0($t5)
/*  f09d5ac:	8f010008 */ 	lw	$at,0x8($t8)
/*  f09d5b0:	adb90004 */ 	sw	$t9,0x4($t5)
/*  f09d5b4:	2403000c */ 	addiu	$v1,$zero,0xc
/*  f09d5b8:	ada10008 */ 	sw	$at,0x8($t5)
/*  f09d5bc:	8de10000 */ 	lw	$at,0x0($t7)
/*  f09d5c0:	8df90004 */ 	lw	$t9,0x4($t7)
/*  f09d5c4:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f09d5c8:	adc10000 */ 	sw	$at,0x0($t6)
/*  f09d5cc:	8de10008 */ 	lw	$at,0x8($t7)
/*  f09d5d0:	add90004 */ 	sw	$t9,0x4($t6)
/*  f09d5d4:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f09d5d8:	adc10008 */ 	sw	$at,0x8($t6)
/*  f09d5dc:	8c820190 */ 	lw	$v0,0x190($a0)
/*  f09d5e0:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f09d5e4:	00808025 */ 	or	$s0,$a0,$zero
/*  f09d5e8:	244d0003 */ 	addiu	$t5,$v0,0x3
/*  f09d5ec:	afb8003c */ 	sw	$t8,0x3c($sp)
/*  f09d5f0:	05a10004 */ 	bgez	$t5,.L0f09d604
/*  f09d5f4:	31ae0003 */ 	andi	$t6,$t5,0x3
/*  f09d5f8:	11c00002 */ 	beqz	$t6,.L0f09d604
/*  f09d5fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d600:	25cefffc */ 	addiu	$t6,$t6,-4
.L0f09d604:
/*  f09d604:	01c30019 */ 	multu	$t6,$v1
/*  f09d608:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f09d60c:	c6040194 */ 	lwc1	$f4,0x194($s0)
/*  f09d610:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f09d614:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f09d618:	00007812 */ 	mflo	$t7
/*  f09d61c:	020f4021 */ 	addu	$t0,$s0,$t7
/*  f09d620:	244f0002 */ 	addiu	$t7,$v0,0x2
/*  f09d624:	00430019 */ 	multu	$v0,$v1
/*  f09d628:	25040100 */ 	addiu	$a0,$t0,0x100
/*  f09d62c:	afa80034 */ 	sw	$t0,0x34($sp)
/*  f09d630:	0000c812 */ 	mflo	$t9
/*  f09d634:	02194821 */ 	addu	$t1,$s0,$t9
/*  f09d638:	25250100 */ 	addiu	$a1,$t1,0x100
/*  f09d63c:	07010004 */ 	bgez	$t8,.L0f09d650
/*  f09d640:	330d0003 */ 	andi	$t5,$t8,0x3
/*  f09d644:	11a00002 */ 	beqz	$t5,.L0f09d650
/*  f09d648:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d64c:	25adfffc */ 	addiu	$t5,$t5,-4
.L0f09d650:
/*  f09d650:	01a30019 */ 	multu	$t5,$v1
/*  f09d654:	afa90030 */ 	sw	$t1,0x30($sp)
/*  f09d658:	00007012 */ 	mflo	$t6
/*  f09d65c:	020e5021 */ 	addu	$t2,$s0,$t6
/*  f09d660:	25460100 */ 	addiu	$a2,$t2,0x100
/*  f09d664:	05e10004 */ 	bgez	$t7,.L0f09d678
/*  f09d668:	31f90003 */ 	andi	$t9,$t7,0x3
/*  f09d66c:	13200002 */ 	beqz	$t9,.L0f09d678
/*  f09d670:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d674:	2739fffc */ 	addiu	$t9,$t9,-4
.L0f09d678:
/*  f09d678:	03230019 */ 	multu	$t9,$v1
/*  f09d67c:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f09d680:	0000c012 */ 	mflo	$t8
/*  f09d684:	02185821 */ 	addu	$t3,$s0,$t8
/*  f09d688:	25670100 */ 	addiu	$a3,$t3,0x100
/*  f09d68c:	0fc25adc */ 	jal	func0f096b70
/*  f09d690:	afab0028 */ 	sw	$t3,0x28($sp)
/*  f09d694:	8fa40034 */ 	lw	$a0,0x34($sp)
/*  f09d698:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f09d69c:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f09d6a0:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f09d6a4:	c6060194 */ 	lwc1	$f6,0x194($s0)
/*  f09d6a8:	27ad0050 */ 	addiu	$t5,$sp,0x50
/*  f09d6ac:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f09d6b0:	24840130 */ 	addiu	$a0,$a0,0x130
/*  f09d6b4:	24a50130 */ 	addiu	$a1,$a1,0x130
/*  f09d6b8:	24c60130 */ 	addiu	$a2,$a2,0x130
/*  f09d6bc:	24e70130 */ 	addiu	$a3,$a3,0x130
/*  f09d6c0:	0fc25adc */ 	jal	func0f096b70
/*  f09d6c4:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f09d6c8:	8fa40034 */ 	lw	$a0,0x34($sp)
/*  f09d6cc:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f09d6d0:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f09d6d4:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f09d6d8:	c6080194 */ 	lwc1	$f8,0x194($s0)
/*  f09d6dc:	27ae0044 */ 	addiu	$t6,$sp,0x44
/*  f09d6e0:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f09d6e4:	24840160 */ 	addiu	$a0,$a0,0x160
/*  f09d6e8:	24a50160 */ 	addiu	$a1,$a1,0x160
/*  f09d6ec:	24c60160 */ 	addiu	$a2,$a2,0x160
/*  f09d6f0:	24e70160 */ 	addiu	$a3,$a3,0x160
/*  f09d6f4:	0fc25adc */ 	jal	func0f096b70
/*  f09d6f8:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f09d6fc:	8fa2003c */ 	lw	$v0,0x3c($sp)
/*  f09d700:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f09d704:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f09d708:	c45015f8 */ 	lwc1	$f16,0x15f8($v0)
/*  f09d70c:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f09d710:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f09d714:	c7aa0064 */ 	lwc1	$f10,0x64($sp)
/*  f09d718:	e7b2005c */ 	swc1	$f18,0x5c($sp)
/*  f09d71c:	c44615f8 */ 	lwc1	$f6,0x15f8($v0)
/*  f09d720:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f09d724:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*  f09d728:	c45015f8 */ 	lwc1	$f16,0x15f8($v0)
/*  f09d72c:	46105102 */ 	mul.s	$f4,$f10,$f16
/*  f09d730:	e7a40064 */ 	swc1	$f4,0x64($sp)
/*  f09d734:	c60601a4 */ 	lwc1	$f6,0x1a4($s0)
/*  f09d738:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f09d73c:	e7aa005c */ 	swc1	$f10,0x5c($sp)
/*  f09d740:	c61001a8 */ 	lwc1	$f16,0x1a8($s0)
/*  f09d744:	46104100 */ 	add.s	$f4,$f8,$f16
/*  f09d748:	0fc2c4bb */ 	jal	func0f0b12ec
/*  f09d74c:	e7a40060 */ 	swc1	$f4,0x60($sp)
/*  f09d750:	c7b2005c */ 	lwc1	$f18,0x5c($sp)
/*  f09d754:	8e2f0034 */ 	lw	$t7,0x34($s1)
/*  f09d758:	00001025 */ 	or	$v0,$zero,$zero
/*  f09d75c:	46009180 */ 	add.s	$f6,$f18,$f0
/*  f09d760:	3c017f1b */ 	lui	$at,%hi(var7f1ac624)
/*  f09d764:	19e00034 */ 	blez	$t7,.L0f09d838
/*  f09d768:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*  f09d76c:	c420c624 */ 	lwc1	$f0,%lo(var7f1ac624)($at)
/*  f09d770:	c60800dc */ 	lwc1	$f8,0xdc($s0)
.L0f09d774:
/*  f09d774:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f09d778:	c60600e0 */ 	lwc1	$f6,0xe0($s0)
/*  f09d77c:	46080402 */ 	mul.s	$f16,$f0,$f8
/*  f09d780:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f09d784:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f09d788:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f09d78c:	e60400dc */ 	swc1	$f4,0xdc($s0)
/*  f09d790:	c7b20060 */ 	lwc1	$f18,0x60($sp)
/*  f09d794:	c60400e4 */ 	lwc1	$f4,0xe4($s0)
/*  f09d798:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f09d79c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f09d7a0:	e60a00e0 */ 	swc1	$f10,0xe0($s0)
/*  f09d7a4:	c7b00064 */ 	lwc1	$f16,0x64($sp)
/*  f09d7a8:	c60a00e8 */ 	lwc1	$f10,0xe8($s0)
/*  f09d7ac:	46068480 */ 	add.s	$f18,$f16,$f6
/*  f09d7b0:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f09d7b4:	e61200e4 */ 	swc1	$f18,0xe4($s0)
/*  f09d7b8:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f09d7bc:	c61200ec */ 	lwc1	$f18,0xec($s0)
/*  f09d7c0:	46044400 */ 	add.s	$f16,$f8,$f4
/*  f09d7c4:	46120282 */ 	mul.s	$f10,$f0,$f18
/*  f09d7c8:	e61000e8 */ 	swc1	$f16,0xe8($s0)
/*  f09d7cc:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*  f09d7d0:	c61000f0 */ 	lwc1	$f16,0xf0($s0)
/*  f09d7d4:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f09d7d8:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f09d7dc:	e60800ec */ 	swc1	$f8,0xec($s0)
/*  f09d7e0:	c7a40058 */ 	lwc1	$f4,0x58($sp)
/*  f09d7e4:	c60800f4 */ 	lwc1	$f8,0xf4($s0)
/*  f09d7e8:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f09d7ec:	46080402 */ 	mul.s	$f16,$f0,$f8
/*  f09d7f0:	e60600f0 */ 	swc1	$f6,0xf0($s0)
/*  f09d7f4:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f09d7f8:	c60600f8 */ 	lwc1	$f6,0xf8($s0)
/*  f09d7fc:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f09d800:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f09d804:	e60400f4 */ 	swc1	$f4,0xf4($s0)
/*  f09d808:	c7b20048 */ 	lwc1	$f18,0x48($sp)
/*  f09d80c:	c60400fc */ 	lwc1	$f4,0xfc($s0)
/*  f09d810:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f09d814:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f09d818:	e60a00f8 */ 	swc1	$f10,0xf8($s0)
/*  f09d81c:	c7b0004c */ 	lwc1	$f16,0x4c($sp)
/*  f09d820:	46068480 */ 	add.s	$f18,$f16,$f6
/*  f09d824:	e61200fc */ 	swc1	$f18,0xfc($s0)
/*  f09d828:	8e390034 */ 	lw	$t9,0x34($s1)
/*  f09d82c:	0059082a */ 	slt	$at,$v0,$t9
/*  f09d830:	5420ffd0 */ 	bnezl	$at,.L0f09d774
/*  f09d834:	c60800dc */ 	lwc1	$f8,0xdc($s0)
.L0f09d838:
/*  f09d838:	3c017f1b */ 	lui	$at,%hi(var7f1ac628)
/*  f09d83c:	c420c628 */ 	lwc1	$f0,%lo(var7f1ac628)($at)
/*  f09d840:	c60800dc */ 	lwc1	$f8,0xdc($s0)
/*  f09d844:	3c014000 */ 	lui	$at,0x4000
/*  f09d848:	44811000 */ 	mtc1	$at,$f2
/*  f09d84c:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f09d850:	c61000e0 */ 	lwc1	$f16,0xe0($s0)
/*  f09d854:	c60800e4 */ 	lwc1	$f8,0xe4($s0)
/*  f09d858:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f09d85c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d860:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f09d864:	c61000e8 */ 	lwc1	$f16,0xe8($s0)
/*  f09d868:	e60400b8 */ 	swc1	$f4,0xb8($s0)
/*  f09d86c:	46023482 */ 	mul.s	$f18,$f6,$f2
/*  f09d870:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d874:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f09d878:	e61200bc */ 	swc1	$f18,0xbc($s0)
/*  f09d87c:	c61200ec */ 	lwc1	$f18,0xec($s0)
/*  f09d880:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f09d884:	c60a00f0 */ 	lwc1	$f10,0xf0($s0)
/*  f09d888:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f09d88c:	c61000f4 */ 	lwc1	$f16,0xf4($s0)
/*  f09d890:	46009202 */ 	mul.s	$f8,$f18,$f0
/*  f09d894:	e60400c0 */ 	swc1	$f4,0xc0($s0)
/*  f09d898:	c61200f8 */ 	lwc1	$f18,0xf8($s0)
/*  f09d89c:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f09d8a0:	e60600c4 */ 	swc1	$f6,0xc4($s0)
/*  f09d8a4:	c60a00fc */ 	lwc1	$f10,0xfc($s0)
/*  f09d8a8:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f09d8ac:	e60800c8 */ 	swc1	$f8,0xc8($s0)
/*  f09d8b0:	46009202 */ 	mul.s	$f8,$f18,$f0
/*  f09d8b4:	e60400cc */ 	swc1	$f4,0xcc($s0)
/*  f09d8b8:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f09d8bc:	e60600d0 */ 	swc1	$f6,0xd0($s0)
/*  f09d8c0:	e60800d4 */ 	swc1	$f8,0xd4($s0)
/*  f09d8c4:	e60400d8 */ 	swc1	$f4,0xd8($s0)
/*  f09d8c8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f09d8cc:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f09d8d0:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f09d8d4:	03e00008 */ 	jr	$ra
/*  f09d8d8:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f09d8dc
/*  f09d8dc:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f09d8e0:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f09d8e4:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f09d8e8:	44803000 */ 	mtc1	$zero,$f6
/*  f09d8ec:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f09d8f0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f09d8f4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f09d8f8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f09d8fc:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f09d900:	46006586 */ 	mov.s	$f22,$f12
/*  f09d904:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f09d908:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f09d90c:	afa70074 */ 	sw	$a3,0x74($sp)
/*  f09d910:	8c700284 */ 	lw	$s0,0x284($v1)
/*  f09d914:	45000002 */ 	bc1f	.L0f09d920
/*  f09d918:	46002406 */ 	mov.s	$f16,$f4
/*  f09d91c:	46002407 */ 	neg.s	$f16,$f4
.L0f09d920:
/*  f09d920:	3c017f1b */ 	lui	$at,%hi(var7f1ac62c)
/*  f09d924:	c428c62c */ 	lwc1	$f8,%lo(var7f1ac62c)($at)
/*  f09d928:	460e403c */ 	c.lt.s	$f8,$f14
/*  f09d92c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d930:	45000004 */ 	bc1f	.L0f09d944
/*  f09d934:	3c013f80 */ 	lui	$at,0x3f80
/*  f09d938:	4481a000 */ 	mtc1	$at,$f20
/*  f09d93c:	1000001f */ 	beqz	$zero,.L0f09d9bc
/*  f09d940:	e61415f8 */ 	swc1	$f20,0x15f8($s0)
.L0f09d944:
/*  f09d944:	3c017f1b */ 	lui	$at,%hi(var7f1ac634)
/*  f09d948:	c420c634 */ 	lwc1	$f0,%lo(var7f1ac634)($at)
/*  f09d94c:	3c013f80 */ 	lui	$at,0x3f80
/*  f09d950:	460e003c */ 	c.lt.s	$f0,$f14
/*  f09d954:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d958:	45020017 */ 	bc1fl	.L0f09d9b8
/*  f09d95c:	4481a000 */ 	mtc1	$at,$f20
/*  f09d960:	46007281 */ 	sub.s	$f10,$f14,$f0
/*  f09d964:	3c017f1b */ 	lui	$at,%hi(var7f1ac638)
/*  f09d968:	c432c638 */ 	lwc1	$f18,%lo(var7f1ac638)($at)
/*  f09d96c:	3c017f1b */ 	lui	$at,%hi(var7f1ac63c)
/*  f09d970:	c424c63c */ 	lwc1	$f4,%lo(var7f1ac63c)($at)
/*  f09d974:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f09d978:	e7b00050 */ 	swc1	$f16,0x50($sp)
/*  f09d97c:	0c0068f4 */ 	jal	func0001a3d0
/*  f09d980:	46043303 */ 	div.s	$f12,$f6,$f4
/*  f09d984:	3c013f80 */ 	lui	$at,0x3f80
/*  f09d988:	4481a000 */ 	mtc1	$at,$f20
/*  f09d98c:	3c017f1b */ 	lui	$at,%hi(var7f1ac640)
/*  f09d990:	c428c640 */ 	lwc1	$f8,%lo(var7f1ac640)($at)
/*  f09d994:	4600a281 */ 	sub.s	$f10,$f20,$f0
/*  f09d998:	3c017f1b */ 	lui	$at,%hi(var7f1ac644)
/*  f09d99c:	c426c644 */ 	lwc1	$f6,%lo(var7f1ac644)($at)
/*  f09d9a0:	c7b00050 */ 	lwc1	$f16,0x50($sp)
/*  f09d9a4:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f09d9a8:	46069100 */ 	add.s	$f4,$f18,$f6
/*  f09d9ac:	10000003 */ 	beqz	$zero,.L0f09d9bc
/*  f09d9b0:	e60415f8 */ 	swc1	$f4,0x15f8($s0)
/*  f09d9b4:	4481a000 */ 	mtc1	$at,$f20
.L0f09d9b8:
/*  f09d9b8:	e60015f8 */ 	swc1	$f0,0x15f8($s0)
.L0f09d9bc:
/*  f09d9bc:	0fc331a0 */ 	jal	func0f0cc680
/*  f09d9c0:	e7b00050 */ 	swc1	$f16,0x50($sp)
/*  f09d9c4:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f09d9c8:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f09d9cc:	1040000c */ 	beqz	$v0,.L0f09da00
/*  f09d9d0:	c7b00050 */ 	lwc1	$f16,0x50($sp)
/*  f09d9d4:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f09d9d8:	3c017f1b */ 	lui	$at,%hi(var7f1ac64c)
/*  f09d9dc:	c428c64c */ 	lwc1	$f8,%lo(var7f1ac64c)($at)
/*  f09d9e0:	c5ca0198 */ 	lwc1	$f10,0x198($t6)
/*  f09d9e4:	c61215f8 */ 	lwc1	$f18,0x15f8($s0)
/*  f09d9e8:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f09d9ec:	4600903c */ 	c.lt.s	$f18,$f0
/*  f09d9f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09d9f4:	45020003 */ 	bc1fl	.L0f09da04
/*  f09d9f8:	3c013f00 */ 	lui	$at,0x3f00
/*  f09d9fc:	e60015f8 */ 	swc1	$f0,0x15f8($s0)
.L0f09da00:
/*  f09da00:	3c013f00 */ 	lui	$at,0x3f00
.L0f09da04:
/*  f09da04:	44813000 */ 	mtc1	$at,$f6
/*  f09da08:	c60415f8 */ 	lwc1	$f4,0x15f8($s0)
/*  f09da0c:	46103002 */ 	mul.s	$f0,$f6,$f16
/*  f09da10:	4600203c */ 	c.lt.s	$f4,$f0
/*  f09da14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09da18:	45020003 */ 	bc1fl	.L0f09da28
/*  f09da1c:	8c6f0034 */ 	lw	$t7,0x34($v1)
/*  f09da20:	e60015f8 */ 	swc1	$f0,0x15f8($s0)
/*  f09da24:	8c6f0034 */ 	lw	$t7,0x34($v1)
.L0f09da28:
/*  f09da28:	00001025 */ 	or	$v0,$zero,$zero
/*  f09da2c:	3c017f1b */ 	lui	$at,%hi(var7f1ac650)
/*  f09da30:	19e0000d */ 	blez	$t7,.L0f09da68
/*  f09da34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09da38:	c60215f8 */ 	lwc1	$f2,0x15f8($s0)
/*  f09da3c:	c420c650 */ 	lwc1	$f0,%lo(var7f1ac650)($at)
/*  f09da40:	c60816f0 */ 	lwc1	$f8,0x16f0($s0)
.L0f09da44:
/*  f09da44:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f09da48:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f09da4c:	46025480 */ 	add.s	$f18,$f10,$f2
/*  f09da50:	e61216f0 */ 	swc1	$f18,0x16f0($s0)
/*  f09da54:	8c780034 */ 	lw	$t8,0x34($v1)
/*  f09da58:	0058082a */ 	slt	$at,$v0,$t8
/*  f09da5c:	5420fff9 */ 	bnezl	$at,.L0f09da44
/*  f09da60:	c60816f0 */ 	lwc1	$f8,0x16f0($s0)
/*  f09da64:	00001025 */ 	or	$v0,$zero,$zero
.L0f09da68:
/*  f09da68:	3c017f1b */ 	lui	$at,%hi(var7f1ac654)
/*  f09da6c:	c420c654 */ 	lwc1	$f0,%lo(var7f1ac654)($at)
/*  f09da70:	3c017f1b */ 	lui	$at,%hi(var7f1ac658)
/*  f09da74:	c42cc658 */ 	lwc1	$f12,%lo(var7f1ac658)($at)
/*  f09da78:	c60616f0 */ 	lwc1	$f6,0x16f0($s0)
/*  f09da7c:	3c017f1b */ 	lui	$at,%hi(var7f1ac65c)
/*  f09da80:	460c3102 */ 	mul.s	$f4,$f6,$f12
/*  f09da84:	e60415f8 */ 	swc1	$f4,0x15f8($s0)
/*  f09da88:	c428c65c */ 	lwc1	$f8,%lo(var7f1ac65c)($at)
/*  f09da8c:	46104082 */ 	mul.s	$f2,$f8,$f16
/*  f09da90:	4602b03c */ 	c.lt.s	$f22,$f2
/*  f09da94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09da98:	45020003 */ 	bc1fl	.L0f09daa8
/*  f09da9c:	8c790034 */ 	lw	$t9,0x34($v1)
/*  f09daa0:	46001586 */ 	mov.s	$f22,$f2
/*  f09daa4:	8c790034 */ 	lw	$t9,0x34($v1)
.L0f09daa8:
/*  f09daa8:	5b20000b */ 	blezl	$t9,.L0f09dad8
/*  f09daac:	c60416ec */ 	lwc1	$f4,0x16ec($s0)
/*  f09dab0:	c60a16ec */ 	lwc1	$f10,0x16ec($s0)
.L0f09dab4:
/*  f09dab4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f09dab8:	46005482 */ 	mul.s	$f18,$f10,$f0
/*  f09dabc:	46169180 */ 	add.s	$f6,$f18,$f22
/*  f09dac0:	e60616ec */ 	swc1	$f6,0x16ec($s0)
/*  f09dac4:	8c680034 */ 	lw	$t0,0x34($v1)
/*  f09dac8:	0048082a */ 	slt	$at,$v0,$t0
/*  f09dacc:	5420fff9 */ 	bnezl	$at,.L0f09dab4
/*  f09dad0:	c60a16ec */ 	lwc1	$f10,0x16ec($s0)
/*  f09dad4:	c60416ec */ 	lwc1	$f4,0x16ec($s0)
.L0f09dad8:
/*  f09dad8:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f09dadc:	460c2582 */ 	mul.s	$f22,$f4,$f12
/*  f09dae0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dae4:	4600b202 */ 	mul.s	$f8,$f22,$f0
/*  f09dae8:	e7a8004c */ 	swc1	$f8,0x4c($sp)
/*  f09daec:	c7b2004c */ 	lwc1	$f18,0x4c($sp)
/*  f09daf0:	c60a07cc */ 	lwc1	$f10,0x7cc($s0)
/*  f09daf4:	46125180 */ 	add.s	$f6,$f10,$f18
/*  f09daf8:	e7a60060 */ 	swc1	$f6,0x60($sp)
/*  f09dafc:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f09db00:	4604a03e */ 	c.le.s	$f20,$f4
/*  f09db04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09db08:	45000010 */ 	bc1f	.L0f09db4c
/*  f09db0c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f09db10:
/*  f09db10:	0fc27450 */ 	jal	func0f09d140
/*  f09db14:	00002025 */ 	or	$a0,$zero,$zero
/*  f09db18:	c7a80060 */ 	lwc1	$f8,0x60($sp)
/*  f09db1c:	46144281 */ 	sub.s	$f10,$f8,$f20
/*  f09db20:	e7aa0060 */ 	swc1	$f10,0x60($sp)
/*  f09db24:	8e0916e8 */ 	lw	$t1,0x16e8($s0)
/*  f09db28:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f09db2c:	ae0a16e8 */ 	sw	$t2,0x16e8($s0)
/*  f09db30:	c7b20060 */ 	lwc1	$f18,0x60($sp)
/*  f09db34:	4612a03e */ 	c.le.s	$f20,$f18
/*  f09db38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09db3c:	4501fff4 */ 	bc1t	.L0f09db10
/*  f09db40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09db44:	3c01800a */ 	lui	$at,0x800a
/*  f09db48:	c420a00c */ 	lwc1	$f0,-0x5ff4($at)
.L0f09db4c:
/*  f09db4c:	c60616e4 */ 	lwc1	$f6,0x16e4($s0)
/*  f09db50:	3c014270 */ 	lui	$at,0x4270
/*  f09db54:	4481b000 */ 	mtc1	$at,$f22
/*  f09db58:	46003100 */ 	add.s	$f4,$f6,$f0
/*  f09db5c:	e60416e4 */ 	swc1	$f4,0x16e4($s0)
/*  f09db60:	c60816e4 */ 	lwc1	$f8,0x16e4($s0)
/*  f09db64:	4608b03c */ 	c.lt.s	$f22,$f8
/*  f09db68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09db6c:	45020017 */ 	bc1fl	.L0f09dbcc
/*  f09db70:	c60016e0 */ 	lwc1	$f0,0x16e0($s0)
/*  f09db74:	44805000 */ 	mtc1	$zero,$f10
/*  f09db78:	0c004b70 */ 	jal	random
/*  f09db7c:	e60a16e4 */ 	swc1	$f10,0x16e4($s0)
/*  f09db80:	44829000 */ 	mtc1	$v0,$f18
/*  f09db84:	3c014f80 */ 	lui	$at,0x4f80
/*  f09db88:	04410004 */ 	bgez	$v0,.L0f09db9c
/*  f09db8c:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f09db90:	44812000 */ 	mtc1	$at,$f4
/*  f09db94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09db98:	46043180 */ 	add.s	$f6,$f6,$f4
.L0f09db9c:
/*  f09db9c:	3c012f80 */ 	lui	$at,0x2f80
/*  f09dba0:	44814000 */ 	mtc1	$at,$f8
/*  f09dba4:	3c013f00 */ 	lui	$at,0x3f00
/*  f09dba8:	44819000 */ 	mtc1	$at,$f18
/*  f09dbac:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f09dbb0:	3c017f1b */ 	lui	$at,%hi(var7f1ac660)
/*  f09dbb4:	c426c660 */ 	lwc1	$f6,%lo(var7f1ac660)($at)
/*  f09dbb8:	46125101 */ 	sub.s	$f4,$f10,$f18
/*  f09dbbc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f09dbc0:	46164283 */ 	div.s	$f10,$f8,$f22
/*  f09dbc4:	e60a16e0 */ 	swc1	$f10,0x16e0($s0)
/*  f09dbc8:	c60016e0 */ 	lwc1	$f0,0x16e0($s0)
.L0f09dbcc:
/*  f09dbcc:	c7a4004c */ 	lwc1	$f4,0x4c($sp)
/*  f09dbd0:	44809000 */ 	mtc1	$zero,$f18
/*  f09dbd4:	3c013f00 */ 	lui	$at,0x3f00
/*  f09dbd8:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f09dbdc:	44812000 */ 	mtc1	$at,$f4
/*  f09dbe0:	3c01bf00 */ 	lui	$at,0xbf00
/*  f09dbe4:	4606903c */ 	c.lt.s	$f18,$f6
/*  f09dbe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dbec:	45020005 */ 	bc1fl	.L0f09dc04
/*  f09dbf0:	c60016dc */ 	lwc1	$f0,0x16dc($s0)
/*  f09dbf4:	c60816dc */ 	lwc1	$f8,0x16dc($s0)
/*  f09dbf8:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f09dbfc:	e60a16dc */ 	swc1	$f10,0x16dc($s0)
/*  f09dc00:	c60016dc */ 	lwc1	$f0,0x16dc($s0)
.L0f09dc04:
/*  f09dc04:	4600203c */ 	c.lt.s	$f4,$f0
/*  f09dc08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dc0c:	45020008 */ 	bc1fl	.L0f09dc30
/*  f09dc10:	44811000 */ 	mtc1	$at,$f2
/*  f09dc14:	3c013f00 */ 	lui	$at,0x3f00
/*  f09dc18:	44819000 */ 	mtc1	$at,$f18
/*  f09dc1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dc20:	e61216dc */ 	swc1	$f18,0x16dc($s0)
/*  f09dc24:	10000020 */ 	beqz	$zero,.L0f09dca8
/*  f09dc28:	c60016dc */ 	lwc1	$f0,0x16dc($s0)
/*  f09dc2c:	44811000 */ 	mtc1	$at,$f2
.L0f09dc30:
/*  f09dc30:	3c017f1b */ 	lui	$at,%hi(var7f1ac664)
/*  f09dc34:	4602003c */ 	c.lt.s	$f0,$f2
/*  f09dc38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dc3c:	45000004 */ 	bc1f	.L0f09dc50
/*  f09dc40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dc44:	e60216dc */ 	swc1	$f2,0x16dc($s0)
/*  f09dc48:	10000017 */ 	beqz	$zero,.L0f09dca8
/*  f09dc4c:	c60016dc */ 	lwc1	$f0,0x16dc($s0)
.L0f09dc50:
/*  f09dc50:	c42cc664 */ 	lwc1	$f12,%lo(var7f1ac664)($at)
/*  f09dc54:	3c017f1b */ 	lui	$at,%hi(var7f1ac668)
/*  f09dc58:	460c003c */ 	c.lt.s	$f0,$f12
/*  f09dc5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dc60:	45020012 */ 	bc1fl	.L0f09dcac
/*  f09dc64:	8e0b16e8 */ 	lw	$t3,0x16e8($s0)
/*  f09dc68:	c422c668 */ 	lwc1	$f2,%lo(var7f1ac668)($at)
/*  f09dc6c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f09dc70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dc74:	4502000d */ 	bc1fl	.L0f09dcac
/*  f09dc78:	8e0b16e8 */ 	lw	$t3,0x16e8($s0)
/*  f09dc7c:	44803000 */ 	mtc1	$zero,$f6
/*  f09dc80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dc84:	4600303c */ 	c.lt.s	$f6,$f0
/*  f09dc88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dc8c:	45020005 */ 	bc1fl	.L0f09dca4
/*  f09dc90:	e60c16dc */ 	swc1	$f12,0x16dc($s0)
/*  f09dc94:	e60216dc */ 	swc1	$f2,0x16dc($s0)
/*  f09dc98:	10000003 */ 	beqz	$zero,.L0f09dca8
/*  f09dc9c:	c60016dc */ 	lwc1	$f0,0x16dc($s0)
/*  f09dca0:	e60c16dc */ 	swc1	$f12,0x16dc($s0)
.L0f09dca4:
/*  f09dca4:	c60016dc */ 	lwc1	$f0,0x16dc($s0)
.L0f09dca8:
/*  f09dca8:	8e0b16e8 */ 	lw	$t3,0x16e8($s0)
.L0f09dcac:
/*  f09dcac:	c7a80060 */ 	lwc1	$f8,0x60($sp)
/*  f09dcb0:	448b5000 */ 	mtc1	$t3,$f10
/*  f09dcb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dcb8:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f09dcbc:	46044480 */ 	add.s	$f18,$f8,$f4
/*  f09dcc0:	46009180 */ 	add.s	$f6,$f18,$f0
/*  f09dcc4:	4606a03e */ 	c.le.s	$f20,$f6
/*  f09dcc8:	e7a60064 */ 	swc1	$f6,0x64($sp)
/*  f09dccc:	4502000f */ 	bc1fl	.L0f09dd0c
/*  f09dcd0:	3c01bfe0 */ 	lui	$at,0xbfe0
.L0f09dcd4:
/*  f09dcd4:	0fc27450 */ 	jal	func0f09d140
/*  f09dcd8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f09dcdc:	c7aa0064 */ 	lwc1	$f10,0x64($sp)
/*  f09dce0:	46145201 */ 	sub.s	$f8,$f10,$f20
/*  f09dce4:	e7a80064 */ 	swc1	$f8,0x64($sp)
/*  f09dce8:	8e0c16e8 */ 	lw	$t4,0x16e8($s0)
/*  f09dcec:	258dffff */ 	addiu	$t5,$t4,-1
/*  f09dcf0:	ae0d16e8 */ 	sw	$t5,0x16e8($s0)
/*  f09dcf4:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*  f09dcf8:	4604a03e */ 	c.le.s	$f20,$f4
/*  f09dcfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dd00:	4501fff4 */ 	bc1t	.L0f09dcd4
/*  f09dd04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09dd08:	3c01bfe0 */ 	lui	$at,0xbfe0
.L0f09dd0c:
/*  f09dd0c:	44819000 */ 	mtc1	$at,$f18
/*  f09dd10:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f09dd14:	3c017f1b */ 	lui	$at,%hi(var7f1ac66c)
/*  f09dd18:	c428c66c */ 	lwc1	$f8,%lo(var7f1ac66c)($at)
/*  f09dd1c:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f09dd20:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f09dd24:	3c01c000 */ 	lui	$at,0xc000
/*  f09dd28:	44813000 */ 	mtc1	$at,$f6
/*  f09dd2c:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f09dd30:	c7a80070 */ 	lwc1	$f8,0x70($sp)
/*  f09dd34:	02001025 */ 	or	$v0,$s0,$zero
/*  f09dd38:	27a30060 */ 	addiu	$v1,$sp,0x60
/*  f09dd3c:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f09dd40:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f09dd44:	46125000 */ 	add.s	$f0,$f10,$f18
.L0f09dd48:
/*  f09dd48:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f09dd4c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f09dd50:	244207a4 */ 	addiu	$v0,$v0,0x7a4
/*  f09dd54:	e4400038 */ 	swc1	$f0,0x38($v0)
/*  f09dd58:	e442003c */ 	swc1	$f2,0x3c($v0)
/*  f09dd5c:	1464fffa */ 	bne	$v1,$a0,.L0f09dd48
/*  f09dd60:	e4440028 */ 	swc1	$f4,0x28($v0)
/*  f09dd64:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f09dd68:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f09dd6c:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f09dd70:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f09dd74:	03e00008 */ 	jr	$ra
/*  f09dd78:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f09dd7c
/*  f09dd7c:	3c03800a */ 	lui	$v1,0x800a
/*  f09dd80:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f09dd84:	906e15ea */ 	lbu	$t6,0x15ea($v1)
/*  f09dd88:	51c00004 */ 	beqzl	$t6,.L0f09dd9c
/*  f09dd8c:	8c621588 */ 	lw	$v0,0x1588($v1)
/*  f09dd90:	03e00008 */ 	jr	$ra
/*  f09dd94:	00001025 */ 	or	$v0,$zero,$zero
/*  f09dd98:	8c621588 */ 	lw	$v0,0x1588($v1)
.L0f09dd9c:
/*  f09dd9c:	2c4f0001 */ 	sltiu	$t7,$v0,0x1
/*  f09dda0:	15e00008 */ 	bnez	$t7,.L0f09ddc4
/*  f09dda4:	01e01025 */ 	or	$v0,$t7,$zero
/*  f09dda8:	8c621584 */ 	lw	$v0,0x1584($v1)
/*  f09ddac:	28580000 */ 	slti	$t8,$v0,0x0
/*  f09ddb0:	13000004 */ 	beqz	$t8,.L0f09ddc4
/*  f09ddb4:	03001025 */ 	or	$v0,$t8,$zero
/*  f09ddb8:	906215b0 */ 	lbu	$v0,0x15b0($v1)
/*  f09ddbc:	38590004 */ 	xori	$t9,$v0,0x4
/*  f09ddc0:	2f220001 */ 	sltiu	$v0,$t9,0x1
.L0f09ddc4:
/*  f09ddc4:	03e00008 */ 	jr	$ra
/*  f09ddc8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09ddcc
/*  f09ddcc:	3c0e800a */ 	lui	$t6,0x800a
/*  f09ddd0:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f09ddd4:	03e00008 */ 	jr	$ra
/*  f09ddd8:	8dc21588 */ 	lw	$v0,0x1588($t6)
/*  f09dddc:	3c0e800a */ 	lui	$t6,0x800a
/*  f09dde0:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f09dde4:	03e00008 */ 	jr	$ra
/*  f09dde8:	8dc21590 */ 	lw	$v0,0x1590($t6)
);

GLOBAL_ASM(
glabel func0f09ddec
/*  f09ddec:	3c0e800a */ 	lui	$t6,0x800a
/*  f09ddf0:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f09ddf4:	03e00008 */ 	jr	$ra
/*  f09ddf8:	8dc2158c */ 	lw	$v0,0x158c($t6)
);

GLOBAL_ASM(
glabel func0f09ddfc
/*  f09ddfc:	3c0e8009 */ 	lui	$t6,0x8009
/*  f09de00:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f09de04:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f09de08:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f09de0c:	14ce0020 */ 	bne	$a2,$t6,.L0f09de90
/*  f09de10:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f09de14:	8cef006c */ 	lw	$t7,0x6c($a3)
/*  f09de18:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09de1c:	00001025 */ 	or	$v0,$zero,$zero
/*  f09de20:	11e00003 */ 	beqz	$t7,.L0f09de30
/*  f09de24:	00001825 */ 	or	$v1,$zero,$zero
/*  f09de28:	10000001 */ 	beqz	$zero,.L0f09de30
/*  f09de2c:	00c01025 */ 	or	$v0,$a2,$zero
.L0f09de30:
/*  f09de30:	8cf80068 */ 	lw	$t8,0x68($a3)
/*  f09de34:	00002025 */ 	or	$a0,$zero,$zero
/*  f09de38:	00002825 */ 	or	$a1,$zero,$zero
/*  f09de3c:	13000003 */ 	beqz	$t8,.L0f09de4c
/*  f09de40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09de44:	10000001 */ 	beqz	$zero,.L0f09de4c
/*  f09de48:	00c01825 */ 	or	$v1,$a2,$zero
.L0f09de4c:
/*  f09de4c:	8cf90064 */ 	lw	$t9,0x64($a3)
/*  f09de50:	13200003 */ 	beqz	$t9,.L0f09de60
/*  f09de54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09de58:	10000001 */ 	beqz	$zero,.L0f09de60
/*  f09de5c:	00c02025 */ 	or	$a0,$a2,$zero
.L0f09de60:
/*  f09de60:	8ce80070 */ 	lw	$t0,0x70($a3)
/*  f09de64:	11000003 */ 	beqz	$t0,.L0f09de74
/*  f09de68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09de6c:	10000001 */ 	beqz	$zero,.L0f09de74
/*  f09de70:	00c02825 */ 	or	$a1,$a2,$zero
.L0f09de74:
/*  f09de74:	00a44821 */ 	addu	$t1,$a1,$a0
/*  f09de78:	01235021 */ 	addu	$t2,$t1,$v1
/*  f09de7c:	01425821 */ 	addu	$t3,$t2,$v0
/*  f09de80:	15610003 */ 	bne	$t3,$at,.L0f09de90
/*  f09de84:	3c028007 */ 	lui	$v0,0x8007
/*  f09de88:	03e00008 */ 	jr	$ra
/*  f09de8c:	8c4200ac */ 	lw	$v0,0xac($v0)
.L0f09de90:
/*  f09de90:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f09de94:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f09de98:	8cec006c */ 	lw	$t4,0x6c($a3)
/*  f09de9c:	8ce30068 */ 	lw	$v1,0x68($a3)
/*  f09dea0:	8ce40064 */ 	lw	$a0,0x64($a3)
/*  f09dea4:	11800003 */ 	beqz	$t4,.L0f09deb4
/*  f09dea8:	8ce50070 */ 	lw	$a1,0x70($a3)
/*  f09deac:	10000002 */ 	beqz	$zero,.L0f09deb8
/*  f09deb0:	00c01025 */ 	or	$v0,$a2,$zero
.L0f09deb4:
/*  f09deb4:	00001025 */ 	or	$v0,$zero,$zero
.L0f09deb8:
/*  f09deb8:	50600004 */ 	beqzl	$v1,.L0f09decc
/*  f09debc:	00001825 */ 	or	$v1,$zero,$zero
/*  f09dec0:	10000002 */ 	beqz	$zero,.L0f09decc
/*  f09dec4:	00c01825 */ 	or	$v1,$a2,$zero
/*  f09dec8:	00001825 */ 	or	$v1,$zero,$zero
.L0f09decc:
/*  f09decc:	50800004 */ 	beqzl	$a0,.L0f09dee0
/*  f09ded0:	00002025 */ 	or	$a0,$zero,$zero
/*  f09ded4:	10000002 */ 	beqz	$zero,.L0f09dee0
/*  f09ded8:	00c02025 */ 	or	$a0,$a2,$zero
/*  f09dedc:	00002025 */ 	or	$a0,$zero,$zero
.L0f09dee0:
/*  f09dee0:	50a00004 */ 	beqzl	$a1,.L0f09def4
/*  f09dee4:	00002825 */ 	or	$a1,$zero,$zero
/*  f09dee8:	10000002 */ 	beqz	$zero,.L0f09def4
/*  f09deec:	00c02825 */ 	or	$a1,$a2,$zero
/*  f09def0:	00002825 */ 	or	$a1,$zero,$zero
.L0f09def4:
/*  f09def4:	00a46821 */ 	addu	$t5,$a1,$a0
/*  f09def8:	01a37021 */ 	addu	$t6,$t5,$v1
/*  f09defc:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f09df00:	14cf000f */ 	bne	$a2,$t7,.L0f09df40
/*  f09df04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09df08:	8cf804b4 */ 	lw	$t8,0x4b4($a3)
/*  f09df0c:	2719ffe3 */ 	addiu	$t9,$t8,-29
/*  f09df10:	2f210018 */ 	sltiu	$at,$t9,0x18
/*  f09df14:	1020000a */ 	beqz	$at,.L0f09df40
/*  f09df18:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f09df1c:	3c017f1b */ 	lui	$at,%hi(var7f1ac670)
/*  f09df20:	00390821 */ 	addu	$at,$at,$t9
/*  f09df24:	8c39c670 */ 	lw	$t9,%lo(var7f1ac670)($at)
/*  f09df28:	03200008 */ 	jr	$t9
/*  f09df2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09df30:	3c028007 */ 	lui	$v0,0x8007
/*  f09df34:	8c4200a8 */ 	lw	$v0,0xa8($v0)
/*  f09df38:	03e00008 */ 	jr	$ra
/*  f09df3c:	24426400 */ 	addiu	$v0,$v0,0x6400
.L0f09df40:
/*  f09df40:	3c028007 */ 	lui	$v0,0x8007
/*  f09df44:	8c4200a8 */ 	lw	$v0,0xa8($v0)
/*  f09df48:	03e00008 */ 	jr	$ra
/*  f09df4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09df50
/*  f09df50:	3c0f800a */ 	lui	$t7,0x800a
/*  f09df54:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f09df58:	240e000b */ 	addiu	$t6,$zero,0xb
/*  f09df5c:	03e00008 */ 	jr	$ra
/*  f09df60:	a1ee15ea */ 	sb	$t6,0x15ea($t7)
);

GLOBAL_ASM(
glabel func0f09df64
/*  f09df64:	3c02800a */ 	lui	$v0,0x800a
/*  f09df68:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f09df6c:	240fffff */ 	addiu	$t7,$zero,-1
/*  f09df70:	904e15ea */ 	lbu	$t6,0x15ea($v0)
/*  f09df74:	55c00007 */ 	bnezl	$t6,.L0f09df94
/*  f09df78:	ac441584 */ 	sw	$a0,0x1584($v0)
/*  f09df7c:	a04015b0 */ 	sb	$zero,0x15b0($v0)
/*  f09df80:	a04015b1 */ 	sb	$zero,0x15b1($v0)
/*  f09df84:	ac441584 */ 	sw	$a0,0x1584($v0)
/*  f09df88:	03e00008 */ 	jr	$ra
/*  f09df8c:	a04f15eb */ 	sb	$t7,0x15eb($v0)
/*  f09df90:	ac441584 */ 	sw	$a0,0x1584($v0)
.L0f09df94:
/*  f09df94:	03e00008 */ 	jr	$ra
/*  f09df98:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09df9c
/*  f09df9c:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f09dfa0:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f09dfa4:	8c8f0284 */ 	lw	$t7,0x284($a0)
/*  f09dfa8:	340effff */ 	dli	$t6,0xffff
/*  f09dfac:	3c02800a */ 	lui	$v0,%hi(var8009da60)
/*  f09dfb0:	a5ee159c */ 	sh	$t6,0x159c($t7)
/*  f09dfb4:	8c980284 */ 	lw	$t8,0x284($a0)
/*  f09dfb8:	3c03800a */ 	lui	$v1,%hi(var8009d510)
/*  f09dfbc:	2442da60 */ 	addiu	$v0,$v0,%lo(var8009da60)
/*  f09dfc0:	af001594 */ 	sw	$zero,0x1594($t8)
/*  f09dfc4:	8c990284 */ 	lw	$t9,0x284($a0)
/*  f09dfc8:	2463d510 */ 	addiu	$v1,$v1,%lo(var8009d510)
/*  f09dfcc:	af2015a0 */ 	sw	$zero,0x15a0($t9)
/*  f09dfd0:	8c880284 */ 	lw	$t0,0x284($a0)
/*  f09dfd4:	ad0015a4 */ 	sw	$zero,0x15a4($t0)
/*  f09dfd8:	8c890284 */ 	lw	$t1,0x284($a0)
/*  f09dfdc:	a12015b0 */ 	sb	$zero,0x15b0($t1)
/*  f09dfe0:	8c8a0284 */ 	lw	$t2,0x284($a0)
/*  f09dfe4:	a14015b1 */ 	sb	$zero,0x15b1($t2)
.L0f09dfe8:
/*  f09dfe8:	24630044 */ 	addiu	$v1,$v1,0x44
/*  f09dfec:	0062082b */ 	sltu	$at,$v1,$v0
/*  f09dff0:	1420fffd */ 	bnez	$at,.L0f09dfe8
/*  f09dff4:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f09dff8:	3c018007 */ 	lui	$at,0x8007
/*  f09dffc:	03e00008 */ 	jr	$ra
/*  f09e000:	ac200524 */ 	sw	$zero,0x524($at)
);

GLOBAL_ASM(
glabel func0f09e004
/*  f09e004:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f09e008:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f09e00c:	8cc30284 */ 	lw	$v1,0x284($a2)
/*  f09e010:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f09e014:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f09e018:	906515ea */ 	lbu	$a1,0x15ea($v1)
/*  f09e01c:	54850004 */ 	bnel	$a0,$a1,.L0f09e030
/*  f09e020:	806215eb */ 	lb	$v0,0x15eb($v1)
/*  f09e024:	10000043 */ 	beqz	$zero,.L0f09e134
/*  f09e028:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09e02c:	806215eb */ 	lb	$v0,0x15eb($v1)
.L0f09e030:
/*  f09e030:	2ca1000c */ 	sltiu	$at,$a1,0xc
/*  f09e034:	0441000a */ 	bgez	$v0,.L0f09e060
/*  f09e038:	244effff */ 	addiu	$t6,$v0,-1
/*  f09e03c:	a06e15eb */ 	sb	$t6,0x15eb($v1)
/*  f09e040:	806f15eb */ 	lb	$t7,0x15eb($v1)
/*  f09e044:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09e048:	29e1fffe */ 	slti	$at,$t7,-2
/*  f09e04c:	50200039 */ 	beqzl	$at,.L0f09e134
/*  f09e050:	00001025 */ 	or	$v0,$zero,$zero
/*  f09e054:	a06015eb */ 	sb	$zero,0x15eb($v1)
/*  f09e058:	10000036 */ 	beqz	$zero,.L0f09e134
/*  f09e05c:	a06415ea */ 	sb	$a0,0x15ea($v1)
.L0f09e060:
/*  f09e060:	1020002e */ 	beqz	$at,.L0f09e11c
/*  f09e064:	00001025 */ 	or	$v0,$zero,$zero
/*  f09e068:	0005c080 */ 	sll	$t8,$a1,0x2
/*  f09e06c:	3c017f1b */ 	lui	$at,%hi(var7f1ac6d0)
/*  f09e070:	00380821 */ 	addu	$at,$at,$t8
/*  f09e074:	8c38c6d0 */ 	lw	$t8,%lo(var7f1ac6d0)($at)
/*  f09e078:	03000008 */ 	jr	$t8
/*  f09e07c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e080:	8c621588 */ 	lw	$v0,0x1588($v1)
/*  f09e084:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f09e088:	50820003 */ 	beql	$a0,$v0,.L0f09e098
/*  f09e08c:	ac641588 */ 	sw	$a0,0x1588($v1)
/*  f09e090:	ac621584 */ 	sw	$v0,0x1584($v1)
/*  f09e094:	ac641588 */ 	sw	$a0,0x1588($v1)
.L0f09e098:
/*  f09e098:	0fc277e7 */ 	jal	func0f09df9c
/*  f09e09c:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f09e0a0:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f09e0a4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09e0a8:	90681583 */ 	lbu	$t0,0x1583($v1)
/*  f09e0ac:	35090002 */ 	ori	$t1,$t0,0x2
/*  f09e0b0:	1000001a */ 	beqz	$zero,.L0f09e11c
/*  f09e0b4:	a0691583 */ 	sb	$t1,0x1583($v1)
/*  f09e0b8:	8cca0314 */ 	lw	$t2,0x314($a2)
/*  f09e0bc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09e0c0:	3c0c800a */ 	lui	$t4,0x800a
/*  f09e0c4:	51400003 */ 	beqzl	$t2,.L0f09e0d4
/*  f09e0c8:	8c6b19c8 */ 	lw	$t3,0x19c8($v1)
/*  f09e0cc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09e0d0:	8c6b19c8 */ 	lw	$t3,0x19c8($v1)
.L0f09e0d4:
/*  f09e0d4:	15600002 */ 	bnez	$t3,.L0f09e0e0
/*  f09e0d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e0dc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09e0e0:
/*  f09e0e0:	1481000e */ 	bne	$a0,$at,.L0f09e11c
/*  f09e0e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e0e8:	8d8cdfc0 */ 	lw	$t4,-0x2040($t4)
/*  f09e0ec:	1180000b */ 	beqz	$t4,.L0f09e11c
/*  f09e0f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e0f4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09e0f8:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f09e0fc:	0fc2e54e */ 	jal	func0f0b9538
/*  f09e100:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f09e104:	8fa20018 */ 	lw	$v0,0x18($sp)
/*  f09e108:	10000004 */ 	beqz	$zero,.L0f09e11c
/*  f09e10c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f09e110:	10000002 */ 	beqz	$zero,.L0f09e11c
/*  f09e114:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09e118:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09e11c:
/*  f09e11c:	10400004 */ 	beqz	$v0,.L0f09e130
/*  f09e120:	240dffff */ 	addiu	$t5,$zero,-1
/*  f09e124:	240e000a */ 	addiu	$t6,$zero,0xa
/*  f09e128:	a06d15eb */ 	sb	$t5,0x15eb($v1)
/*  f09e12c:	a06e15ea */ 	sb	$t6,0x15ea($v1)
.L0f09e130:
/*  f09e130:	00001025 */ 	or	$v0,$zero,$zero
.L0f09e134:
/*  f09e134:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09e138:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f09e13c:	03e00008 */ 	jr	$ra
/*  f09e140:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09e144
/*  f09e144:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f09e148:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f09e14c:	3c12800a */ 	lui	$s2,0x800a
/*  f09e150:	8e52a244 */ 	lw	$s2,-0x5dbc($s2)
/*  f09e154:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f09e158:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f09e15c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f09e160:	924215b1 */ 	lbu	$v0,0x15b1($s2)
/*  f09e164:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09e168:	5441004a */ 	bnel	$v0,$at,.L0f09e294
/*  f09e16c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09e170:	8e4615b8 */ 	lw	$a2,0x15b8($s2)
/*  f09e174:	8e4e15bc */ 	lw	$t6,0x15bc($s2)
/*  f09e178:	240f0010 */ 	addiu	$t7,$zero,0x10
/*  f09e17c:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f09e180:	8dd00000 */ 	lw	$s0,0x0($t6)
/*  f09e184:	3065000f */ 	andi	$a1,$v1,0xf
/*  f09e188:	10a00003 */ 	beqz	$a1,.L0f09e198
/*  f09e18c:	01e51023 */ 	subu	$v0,$t7,$a1
/*  f09e190:	00621821 */ 	addu	$v1,$v1,$v0
/*  f09e194:	02028023 */ 	subu	$s0,$s0,$v0
.L0f09e198:
/*  f09e198:	acc30000 */ 	sw	$v1,0x0($a2)
/*  f09e19c:	8e5815bc */ 	lw	$t8,0x15bc($s2)
/*  f09e1a0:	af100000 */ 	sw	$s0,0x0($t8)
/*  f09e1a4:	964415b2 */ 	lhu	$a0,0x15b2($s2)
/*  f09e1a8:	0fc59c15 */ 	jal	func0f167054
/*  f09e1ac:	afa30064 */ 	sw	$v1,0x64($sp)
/*  f09e1b0:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f09e1b4:	3479003f */ 	ori	$t9,$v1,0x3f
/*  f09e1b8:	3b23003f */ 	xori	$v1,$t9,0x3f
/*  f09e1bc:	34018000 */ 	dli	$at,0x8000
/*  f09e1c0:	00613821 */ 	addu	$a3,$v1,$at
/*  f09e1c4:	0207082b */ 	sltu	$at,$s0,$a3
/*  f09e1c8:	10200002 */ 	beqz	$at,.L0f09e1d4
/*  f09e1cc:	240b0007 */ 	addiu	$t3,$zero,0x7
/*  f09e1d0:	02003825 */ 	or	$a3,$s0,$zero
.L0f09e1d4:
/*  f09e1d4:	3c018006 */ 	lui	$at,0x8006
/*  f09e1d8:	a02bd9a0 */ 	sb	$t3,-0x2660($at)
/*  f09e1dc:	964415b2 */ 	lhu	$a0,0x15b2($s2)
/*  f09e1e0:	24050011 */ 	addiu	$a1,$zero,0x11
/*  f09e1e4:	0fc59c80 */ 	jal	func0f167200
/*  f09e1e8:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f09e1ec:	00408825 */ 	or	$s1,$v0,$zero
/*  f09e1f0:	0fc59ca0 */ 	jal	func0f167280
/*  f09e1f4:	964415b2 */ 	lhu	$a0,0x15b2($s2)
/*  f09e1f8:	24470e00 */ 	addiu	$a3,$v0,0xe00
/*  f09e1fc:	964415b2 */ 	lhu	$a0,0x15b2($s2)
/*  f09e200:	0fc59ca0 */ 	jal	func0f167280
/*  f09e204:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f09e208:	964c15b2 */ 	lhu	$t4,0x15b2($s2)
/*  f09e20c:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f09e210:	3c0e800a */ 	lui	$t6,%hi(var800a6680)
/*  f09e214:	25ce6680 */ 	addiu	$t6,$t6,%lo(var800a6680)
/*  f09e218:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f09e21c:	01ae4021 */ 	addu	$t0,$t5,$t6
/*  f09e220:	ad070004 */ 	sw	$a3,0x4($t0)
/*  f09e224:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f09e228:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f09e22c:	264415c0 */ 	addiu	$a0,$s2,0x15c0
/*  f09e230:	01e71821 */ 	addu	$v1,$t7,$a3
/*  f09e234:	2463000f */ 	addiu	$v1,$v1,0xf
/*  f09e238:	3478000f */ 	ori	$t8,$v1,0xf
/*  f09e23c:	3b05000f */ 	xori	$a1,$t8,0xf
/*  f09e240:	00af3823 */ 	subu	$a3,$a1,$t7
/*  f09e244:	0fc5cb9c */ 	jal	func0f172e70
/*  f09e248:	02073023 */ 	subu	$a2,$s0,$a3
/*  f09e24c:	0fc69dcc */ 	jal	func0f1a7730
/*  f09e250:	02202025 */ 	or	$a0,$s1,$zero
/*  f09e254:	02202025 */ 	or	$a0,$s1,$zero
/*  f09e258:	3c050500 */ 	lui	$a1,0x500
/*  f09e25c:	0c008a89 */ 	jal	func00022a24
/*  f09e260:	02203025 */ 	or	$a2,$s1,$zero
/*  f09e264:	8e4a15b4 */ 	lw	$t2,0x15b4($s2)
/*  f09e268:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f09e26c:	ad510000 */ 	sw	$s1,0x0($t2)
/*  f09e270:	ae4015d0 */ 	sw	$zero,0x15d0($s2)
/*  f09e274:	8fab0058 */ 	lw	$t3,0x58($sp)
/*  f09e278:	8d610000 */ 	lw	$at,0x0($t3)
/*  f09e27c:	ae4115d4 */ 	sw	$at,0x15d4($s2)
/*  f09e280:	8d6d0004 */ 	lw	$t5,0x4($t3)
/*  f09e284:	a24e15b1 */ 	sb	$t6,0x15b1($s2)
/*  f09e288:	1000008f */ 	beqz	$zero,.L0f09e4c8
/*  f09e28c:	ae4d15d8 */ 	sw	$t5,0x15d8($s2)
/*  f09e290:	24010002 */ 	addiu	$at,$zero,0x2
.L0f09e294:
/*  f09e294:	1441003f */ 	bne	$v0,$at,.L0f09e394
/*  f09e298:	3c0f800a */ 	lui	$t7,%hi(var800a6680)
/*  f09e29c:	965815b2 */ 	lhu	$t8,0x15b2($s2)
/*  f09e2a0:	25ef6680 */ 	addiu	$t7,$t7,%lo(var800a6680)
/*  f09e2a4:	264c15d4 */ 	addiu	$t4,$s2,0x15d4
/*  f09e2a8:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f09e2ac:	032f5021 */ 	addu	$t2,$t9,$t7
/*  f09e2b0:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f09e2b4:	afac0034 */ 	sw	$t4,0x34($sp)
/*  f09e2b8:	8d810000 */ 	lw	$at,0x0($t4)
/*  f09e2bc:	00003825 */ 	or	$a3,$zero,$zero
/*  f09e2c0:	ad410000 */ 	sw	$at,0x0($t2)
/*  f09e2c4:	8d980004 */ 	lw	$t8,0x4($t4)
/*  f09e2c8:	ad580004 */ 	sw	$t8,0x4($t2)
/*  f09e2cc:	8e5915b4 */ 	lw	$t9,0x15b4($s2)
/*  f09e2d0:	8e4315d0 */ 	lw	$v1,0x15d0($s2)
/*  f09e2d4:	8f310000 */ 	lw	$s1,0x0($t9)
/*  f09e2d8:	00038080 */ 	sll	$s0,$v1,0x2
/*  f09e2dc:	02038023 */ 	subu	$s0,$s0,$v1
/*  f09e2e0:	862f0016 */ 	lh	$t7,0x16($s1)
/*  f09e2e4:	00108080 */ 	sll	$s0,$s0,0x2
/*  f09e2e8:	006f082a */ 	slt	$at,$v1,$t7
/*  f09e2ec:	50200021 */ 	beqzl	$at,.L0f09e374
/*  f09e2f0:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f09e2f4:	8e220018 */ 	lw	$v0,0x18($s1)
.L0f09e2f8:
/*  f09e2f8:	264515c0 */ 	addiu	$a1,$s2,0x15c0
/*  f09e2fc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f09e300:	00506021 */ 	addu	$t4,$v0,$s0
/*  f09e304:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f09e308:	00502021 */ 	addu	$a0,$v0,$s0
/*  f09e30c:	29c10daf */ 	slti	$at,$t6,0xdaf
/*  f09e310:	5020000b */ 	beqzl	$at,.L0f09e340
/*  f09e314:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f09e318:	afa3007c */ 	sw	$v1,0x7c($sp)
/*  f09e31c:	0fc5cc04 */ 	jal	func0f173010
/*  f09e320:	afa70078 */ 	sw	$a3,0x78($sp)
/*  f09e324:	8e2a0018 */ 	lw	$t2,0x18($s1)
/*  f09e328:	8fa3007c */ 	lw	$v1,0x7c($sp)
/*  f09e32c:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f09e330:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f09e334:	01505821 */ 	addu	$t3,$t2,$s0
/*  f09e338:	a16d000b */ 	sb	$t5,0xb($t3)
/*  f09e33c:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f09e340:
/*  f09e340:	24010003 */ 	addiu	$at,$zero,0x3
/*  f09e344:	50e10061 */ 	beql	$a3,$at,.L0f09e4cc
/*  f09e348:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f09e34c:	8e5815d0 */ 	lw	$t8,0x15d0($s2)
/*  f09e350:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f09e354:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f09e358:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f09e35c:	ae5915d0 */ 	sw	$t9,0x15d0($s2)
/*  f09e360:	862f0016 */ 	lh	$t7,0x16($s1)
/*  f09e364:	006f082a */ 	slt	$at,$v1,$t7
/*  f09e368:	5420ffe3 */ 	bnezl	$at,.L0f09e2f8
/*  f09e36c:	8e220018 */ 	lw	$v0,0x18($s1)
/*  f09e370:	8fae0058 */ 	lw	$t6,0x58($sp)
.L0f09e374:
/*  f09e374:	8fac0034 */ 	lw	$t4,0x34($sp)
/*  f09e378:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f09e37c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f09e380:	ad810000 */ 	sw	$at,0x0($t4)
/*  f09e384:	8dcd0004 */ 	lw	$t5,0x4($t6)
/*  f09e388:	ad8d0004 */ 	sw	$t5,0x4($t4)
/*  f09e38c:	1000004e */ 	beqz	$zero,.L0f09e4c8
/*  f09e390:	a24b15b1 */ 	sb	$t3,0x15b1($s2)
.L0f09e394:
/*  f09e394:	24010003 */ 	addiu	$at,$zero,0x3
/*  f09e398:	5441004c */ 	bnel	$v0,$at,.L0f09e4cc
/*  f09e39c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f09e3a0:	965815b2 */ 	lhu	$t8,0x15b2($s2)
/*  f09e3a4:	3c0f800a */ 	lui	$t7,%hi(var800a6680)
/*  f09e3a8:	25ef6680 */ 	addiu	$t7,$t7,%lo(var800a6680)
/*  f09e3ac:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f09e3b0:	032f5021 */ 	addu	$t2,$t9,$t7
/*  f09e3b4:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f09e3b8:	8e4115d4 */ 	lw	$at,0x15d4($s2)
/*  f09e3bc:	265015c0 */ 	addiu	$s0,$s2,0x15c0
/*  f09e3c0:	3c060500 */ 	lui	$a2,0x500
/*  f09e3c4:	ad410000 */ 	sw	$at,0x0($t2)
/*  f09e3c8:	8e4d15d8 */ 	lw	$t5,0x15d8($s2)
/*  f09e3cc:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f09e3d0:	8e4b15b4 */ 	lw	$t3,0x15b4($s2)
/*  f09e3d4:	964515b2 */ 	lhu	$a1,0x15b2($s2)
/*  f09e3d8:	8d710000 */ 	lw	$s1,0x0($t3)
/*  f09e3dc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f09e3e0:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f09e3e4:	02202025 */ 	or	$a0,$s1,$zero
/*  f09e3e8:	0fc69d58 */ 	jal	func0f1a7560
/*  f09e3ec:	02203825 */ 	or	$a3,$s1,$zero
/*  f09e3f0:	0fc59c15 */ 	jal	func0f167054
/*  f09e3f4:	964415b2 */ 	lhu	$a0,0x15b2($s2)
/*  f09e3f8:	0fc59ca0 */ 	jal	func0f167280
/*  f09e3fc:	964415b2 */ 	lhu	$a0,0x15b2($s2)
/*  f09e400:	0fc59ca0 */ 	jal	func0f167280
/*  f09e404:	964415b2 */ 	lhu	$a0,0x15b2($s2)
/*  f09e408:	0fc59ca0 */ 	jal	func0f167280
/*  f09e40c:	964415b2 */ 	lhu	$a0,0x15b2($s2)
/*  f09e410:	0c008b49 */ 	jal	func00022d24
/*  f09e414:	02202025 */ 	or	$a0,$s1,$zero
/*  f09e418:	0fc5cbd5 */ 	jal	func0f172f54
/*  f09e41c:	02002025 */ 	or	$a0,$s0,$zero
/*  f09e420:	8e4615b8 */ 	lw	$a2,0x15b8($s2)
/*  f09e424:	8e5815bc */ 	lw	$t8,0x15bc($s2)
/*  f09e428:	2447003f */ 	addiu	$a3,$v0,0x3f
/*  f09e42c:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f09e430:	34f9003f */ 	ori	$t9,$a3,0x3f
/*  f09e434:	8f100000 */ 	lw	$s0,0x0($t8)
/*  f09e438:	3b2f003f */ 	xori	$t7,$t9,0x3f
/*  f09e43c:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f09e440:	8e4a15bc */ 	lw	$t2,0x15bc($s2)
/*  f09e444:	3c097f09 */ 	lui	$t1,0x7f09
/*  f09e448:	3c087f09 */ 	lui	$t0,0x7f09
/*  f09e44c:	01ee6023 */ 	subu	$t4,$t7,$t6
/*  f09e450:	252953cc */ 	addiu	$t1,$t1,0x53cc
/*  f09e454:	25055528 */ 	addiu	$a1,$t0,0x5528
/*  f09e458:	020c8023 */ 	subu	$s0,$s0,$t4
/*  f09e45c:	240d0004 */ 	addiu	$t5,$zero,0x4
/*  f09e460:	0125082b */ 	sltu	$at,$t1,$a1
/*  f09e464:	ad500000 */ 	sw	$s0,0x0($t2)
/*  f09e468:	a24d15b1 */ 	sb	$t5,0x15b1($s2)
/*  f09e46c:	01201825 */ 	or	$v1,$t1,$zero
/*  f09e470:	10200007 */ 	beqz	$at,.L0f09e490
/*  f09e474:	00002025 */ 	or	$a0,$zero,$zero
.L0f09e478:
/*  f09e478:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f09e47c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f09e480:	0065082b */ 	sltu	$at,$v1,$a1
/*  f09e484:	0160c027 */ 	nor	$t8,$t3,$zero
/*  f09e488:	1420fffb */ 	bnez	$at,.L0f09e478
/*  f09e48c:	00982023 */ 	subu	$a0,$a0,$t8
.L0f09e490:
/*  f09e490:	3c01f310 */ 	lui	$at,0xf310
/*  f09e494:	3421c53a */ 	ori	$at,$at,0xc53a
/*  f09e498:	1081000b */ 	beq	$a0,$at,.L0f09e4c8
/*  f09e49c:	2523000c */ 	addiu	$v1,$t1,0xc
/*  f09e4a0:	2465001c */ 	addiu	$a1,$v1,0x1c
/*  f09e4a4:	0065082b */ 	sltu	$at,$v1,$a1
/*  f09e4a8:	50200008 */ 	beqzl	$at,.L0f09e4cc
/*  f09e4ac:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f09e4b0:
/*  f09e4b0:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f09e4b4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f09e4b8:	0065082b */ 	sltu	$at,$v1,$a1
/*  f09e4bc:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f09e4c0:	1420fffb */ 	bnez	$at,.L0f09e4b0
/*  f09e4c4:	ac6ffffc */ 	sw	$t7,-0x4($v1)
.L0f09e4c8:
/*  f09e4c8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f09e4cc:
/*  f09e4cc:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f09e4d0:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f09e4d4:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f09e4d8:	03e00008 */ 	jr	$ra
/*  f09e4dc:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

GLOBAL_ASM(
glabel func0f09e4e0
/*  f09e4e0:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f09e4e4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f09e4e8:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f09e4ec:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f09e4f0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f09e4f4:	8eb20284 */ 	lw	$s2,0x284($s5)
/*  f09e4f8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f09e4fc:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f09e500:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f09e504:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f09e508:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f09e50c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f09e510:	924e15ea */ 	lbu	$t6,0x15ea($s2)
/*  f09e514:	51c00006 */ 	beqzl	$t6,.L0f09e530
/*  f09e518:	8e421584 */ 	lw	$v0,0x1584($s2)
/*  f09e51c:	0fc27801 */ 	jal	func0f09e004
/*  f09e520:	00002025 */ 	or	$a0,$zero,$zero
/*  f09e524:	50400151 */ 	beqzl	$v0,.L0f09ea6c
/*  f09e528:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f09e52c:	8e421584 */ 	lw	$v0,0x1584($s2)
.L0f09e530:
/*  f09e530:	0442014e */ 	bltzl	$v0,.L0f09ea6c
/*  f09e534:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f09e538:	824315eb */ 	lb	$v1,0x15eb($s2)
/*  f09e53c:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f09e540:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f09e544:	14600142 */ 	bnez	$v1,.L0f09ea50
/*  f09e548:	246dffff */ 	addiu	$t5,$v1,-1
/*  f09e54c:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f09e550:	0fc2e1cb */ 	jal	func0f0b872c
/*  f09e554:	00003025 */ 	or	$a2,$zero,$zero
/*  f09e558:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f09e55c:	3c198009 */ 	lui	$t9,0x8009
/*  f09e560:	93390af0 */ 	lbu	$t9,0xaf0($t9)
/*  f09e564:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f09e568:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f09e56c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f09e570:	3c118008 */ 	lui	$s1,0x8008
/*  f09e574:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f09e578:	02388821 */ 	addu	$s1,$s1,$t8
/*  f09e57c:	14d90002 */ 	bne	$a2,$t9,.L0f09e588
/*  f09e580:	9631cf14 */ 	lhu	$s1,-0x30ec($s1)
/*  f09e584:	241104e5 */ 	addiu	$s1,$zero,0x4e5
.L0f09e588:
/*  f09e588:	0fc2c686 */ 	jal	func0f0b1a18
/*  f09e58c:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f09e590:	924815b0 */ 	lbu	$t0,0x15b0($s2)
/*  f09e594:	24140004 */ 	addiu	$s4,$zero,0x4
/*  f09e598:	3053ffff */ 	andi	$s3,$v0,0xffff
/*  f09e59c:	16880003 */ 	bne	$s4,$t0,.L0f09e5ac
/*  f09e5a0:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f09e5a4:	8e491588 */ 	lw	$t1,0x1588($s2)
/*  f09e5a8:	1089012f */ 	beq	$a0,$t1,.L0f09ea68
.L0f09e5ac:
/*  f09e5ac:	304affff */ 	andi	$t2,$v0,0xffff
/*  f09e5b0:	11400121 */ 	beqz	$t2,.L0f09ea38
/*  f09e5b4:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f09e5b8:	00008025 */ 	or	$s0,$zero,$zero
/*  f09e5bc:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f09e5c0:	3c050002 */ 	lui	$a1,0x2
/*  f09e5c4:	10400002 */ 	beqz	$v0,.L0f09e5d0
/*  f09e5c8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f09e5cc:	00c08025 */ 	or	$s0,$a2,$zero
.L0f09e5d0:
/*  f09e5d0:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f09e5d4:	3c05800a */ 	lui	$a1,%hi(var8009d510)
/*  f09e5d8:	24a5d510 */ 	addiu	$a1,$a1,%lo(var8009d510)
/*  f09e5dc:	15660004 */ 	bne	$t3,$a2,.L0f09e5f0
/*  f09e5e0:	3c03800a */ 	lui	$v1,%hi(var8009da60)
/*  f09e5e4:	3233ffff */ 	andi	$s3,$s1,0xffff
/*  f09e5e8:	00008825 */ 	or	$s1,$zero,$zero
/*  f09e5ec:	00008025 */ 	or	$s0,$zero,$zero
.L0f09e5f0:
/*  f09e5f0:	924215b0 */ 	lbu	$v0,0x15b0($s2)
/*  f09e5f4:	3c048007 */ 	lui	$a0,%hi(var80070524)
/*  f09e5f8:	2463da60 */ 	addiu	$v1,$v1,%lo(var8009da60)
/*  f09e5fc:	14400019 */ 	bnez	$v0,.L0f09e664
/*  f09e600:	24840524 */ 	addiu	$a0,$a0,%lo(var80070524)
/*  f09e604:	00a01025 */ 	or	$v0,$a1,$zero
/*  f09e608:	8e4c1598 */ 	lw	$t4,0x1598($s2)
.L0f09e60c:
/*  f09e60c:	8c4d0040 */ 	lw	$t5,0x40($v0)
/*  f09e610:	558d0003 */ 	bnel	$t4,$t5,.L0f09e620
/*  f09e614:	24420044 */ 	addiu	$v0,$v0,0x44
/*  f09e618:	ac400040 */ 	sw	$zero,0x40($v0)
/*  f09e61c:	24420044 */ 	addiu	$v0,$v0,0x44
.L0f09e620:
/*  f09e620:	0043082b */ 	sltu	$at,$v0,$v1
/*  f09e624:	5420fff9 */ 	bnezl	$at,.L0f09e60c
/*  f09e628:	8e4c1598 */ 	lw	$t4,0x1598($s2)
/*  f09e62c:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f09e630:	00a01025 */ 	or	$v0,$a1,$zero
/*  f09e634:	8c4e0040 */ 	lw	$t6,0x40($v0)
.L0f09e638:
/*  f09e638:	24420044 */ 	addiu	$v0,$v0,0x44
/*  f09e63c:	0043082b */ 	sltu	$at,$v0,$v1
/*  f09e640:	11c00002 */ 	beqz	$t6,.L0f09e64c
/*  f09e644:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e648:	ac860000 */ 	sw	$a2,0x0($a0)
.L0f09e64c:
/*  f09e64c:	5420fffa */ 	bnezl	$at,.L0f09e638
/*  f09e650:	8c4e0040 */ 	lw	$t6,0x40($v0)
/*  f09e654:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f09e658:	ae401598 */ 	sw	$zero,0x1598($s2)
/*  f09e65c:	10000102 */ 	beqz	$zero,.L0f09ea68
/*  f09e660:	a24f15b0 */ 	sb	$t7,0x15b0($s2)
.L0f09e664:
/*  f09e664:	14c20028 */ 	bne	$a2,$v0,.L0f09e708
/*  f09e668:	24010002 */ 	addiu	$at,$zero,0x2
/*  f09e66c:	5200001d */ 	beqzl	$s0,.L0f09e6e4
/*  f09e670:	a640159c */ 	sh	$zero,0x159c($s2)
/*  f09e674:	9658159c */ 	lhu	$t8,0x159c($s2)
/*  f09e678:	53110020 */ 	beql	$t8,$s1,.L0f09e6fc
/*  f09e67c:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f09e680:	925915b1 */ 	lbu	$t9,0x15b1($s2)
/*  f09e684:	1720000f */ 	bnez	$t9,.L0f09e6c4
/*  f09e688:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e68c:	0fc2777b */ 	jal	func0f09ddec
/*  f09e690:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e694:	0fc2777f */ 	jal	func0f09ddfc
/*  f09e698:	ae4215a0 */ 	sw	$v0,0x15a0($s2)
/*  f09e69c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f09e6a0:	26491594 */ 	addiu	$t1,$s2,0x1594
/*  f09e6a4:	264a15a0 */ 	addiu	$t2,$s2,0x15a0
/*  f09e6a8:	264b15a4 */ 	addiu	$t3,$s2,0x15a4
/*  f09e6ac:	ae4215a4 */ 	sw	$v0,0x15a4($s2)
/*  f09e6b0:	a24815b1 */ 	sb	$t0,0x15b1($s2)
/*  f09e6b4:	a65115b2 */ 	sh	$s1,0x15b2($s2)
/*  f09e6b8:	ae4915b4 */ 	sw	$t1,0x15b4($s2)
/*  f09e6bc:	ae4a15b8 */ 	sw	$t2,0x15b8($s2)
/*  f09e6c0:	ae4b15bc */ 	sw	$t3,0x15bc($s2)
.L0f09e6c4:
/*  f09e6c4:	0fc27851 */ 	jal	func0f09e144
/*  f09e6c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e6cc:	924c15b1 */ 	lbu	$t4,0x15b1($s2)
/*  f09e6d0:	568c00e6 */ 	bnel	$s4,$t4,.L0f09ea6c
/*  f09e6d4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f09e6d8:	10000007 */ 	beqz	$zero,.L0f09e6f8
/*  f09e6dc:	a651159c */ 	sh	$s1,0x159c($s2)
/*  f09e6e0:	a640159c */ 	sh	$zero,0x159c($s2)
.L0f09e6e4:
/*  f09e6e4:	0fc2777b */ 	jal	func0f09ddec
/*  f09e6e8:	ae401594 */ 	sw	$zero,0x1594($s2)
/*  f09e6ec:	0fc2777f */ 	jal	func0f09ddfc
/*  f09e6f0:	ae4215a0 */ 	sw	$v0,0x15a0($s2)
/*  f09e6f4:	ae4215a4 */ 	sw	$v0,0x15a4($s2)
.L0f09e6f8:
/*  f09e6f8:	240d0002 */ 	addiu	$t5,$zero,0x2
.L0f09e6fc:
/*  f09e6fc:	a24d15b0 */ 	sb	$t5,0x15b0($s2)
/*  f09e700:	100000d9 */ 	beqz	$zero,.L0f09ea68
/*  f09e704:	a24015b1 */ 	sb	$zero,0x15b1($s2)
.L0f09e708:
/*  f09e708:	5441001a */ 	bnel	$v0,$at,.L0f09e774
/*  f09e70c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f09e710:	924e15b1 */ 	lbu	$t6,0x15b1($s2)
/*  f09e714:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f09e718:	26481590 */ 	addiu	$t0,$s2,0x1590
/*  f09e71c:	15c0000b */ 	bnez	$t6,.L0f09e74c
/*  f09e720:	264915a8 */ 	addiu	$t1,$s2,0x15a8
/*  f09e724:	8e4f15a0 */ 	lw	$t7,0x15a0($s2)
/*  f09e728:	8e5815a4 */ 	lw	$t8,0x15a4($s2)
/*  f09e72c:	264a15ac */ 	addiu	$t2,$s2,0x15ac
/*  f09e730:	a25915b1 */ 	sb	$t9,0x15b1($s2)
/*  f09e734:	a65315b2 */ 	sh	$s3,0x15b2($s2)
/*  f09e738:	ae4815b4 */ 	sw	$t0,0x15b4($s2)
/*  f09e73c:	ae4915b8 */ 	sw	$t1,0x15b8($s2)
/*  f09e740:	ae4a15bc */ 	sw	$t2,0x15bc($s2)
/*  f09e744:	ae4f15a8 */ 	sw	$t7,0x15a8($s2)
/*  f09e748:	ae5815ac */ 	sw	$t8,0x15ac($s2)
.L0f09e74c:
/*  f09e74c:	0fc27851 */ 	jal	func0f09e144
/*  f09e750:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e754:	924b15b1 */ 	lbu	$t3,0x15b1($s2)
/*  f09e758:	240c0003 */ 	addiu	$t4,$zero,0x3
/*  f09e75c:	568b00c3 */ 	bnel	$s4,$t3,.L0f09ea6c
/*  f09e760:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f09e764:	a24c15b0 */ 	sb	$t4,0x15b0($s2)
/*  f09e768:	100000bf */ 	beqz	$zero,.L0f09ea68
/*  f09e76c:	a24015b1 */ 	sb	$zero,0x15b1($s2)
/*  f09e770:	24010003 */ 	addiu	$at,$zero,0x3
.L0f09e774:
/*  f09e774:	544100bd */ 	bnel	$v0,$at,.L0f09ea6c
/*  f09e778:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f09e77c:	924315b1 */ 	lbu	$v1,0x15b1($s2)
/*  f09e780:	16830003 */ 	bne	$s4,$v1,.L0f09e790
/*  f09e784:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e788:	a24015b1 */ 	sb	$zero,0x15b1($s2)
/*  f09e78c:	300300ff */ 	andi	$v1,$zero,0xff
.L0f09e790:
/*  f09e790:	14600056 */ 	bnez	$v1,.L0f09e8ec
/*  f09e794:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e798:	8e4d1598 */ 	lw	$t5,0x1598($s2)
/*  f09e79c:	15a00053 */ 	bnez	$t5,.L0f09e8ec
/*  f09e7a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e7a4:	8eae006c */ 	lw	$t6,0x6c($s5)
/*  f09e7a8:	00003825 */ 	or	$a3,$zero,$zero
/*  f09e7ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f09e7b0:	11c00003 */ 	beqz	$t6,.L0f09e7c0
/*  f09e7b4:	00002825 */ 	or	$a1,$zero,$zero
/*  f09e7b8:	10000001 */ 	beqz	$zero,.L0f09e7c0
/*  f09e7bc:	00c03825 */ 	or	$a3,$a2,$zero
.L0f09e7c0:
/*  f09e7c0:	8eaf0068 */ 	lw	$t7,0x68($s5)
/*  f09e7c4:	00001025 */ 	or	$v0,$zero,$zero
/*  f09e7c8:	00009825 */ 	or	$s3,$zero,$zero
/*  f09e7cc:	11e00003 */ 	beqz	$t7,.L0f09e7dc
/*  f09e7d0:	26540638 */ 	addiu	$s4,$s2,0x638
/*  f09e7d4:	10000001 */ 	beqz	$zero,.L0f09e7dc
/*  f09e7d8:	00c02025 */ 	or	$a0,$a2,$zero
.L0f09e7dc:
/*  f09e7dc:	8eb80064 */ 	lw	$t8,0x64($s5)
/*  f09e7e0:	24160f48 */ 	addiu	$s6,$zero,0xf48
/*  f09e7e4:	13000003 */ 	beqz	$t8,.L0f09e7f4
/*  f09e7e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e7ec:	10000001 */ 	beqz	$zero,.L0f09e7f4
/*  f09e7f0:	00c02825 */ 	or	$a1,$a2,$zero
.L0f09e7f4:
/*  f09e7f4:	8eb90070 */ 	lw	$t9,0x70($s5)
/*  f09e7f8:	13200003 */ 	beqz	$t9,.L0f09e808
/*  f09e7fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e800:	10000001 */ 	beqz	$zero,.L0f09e808
/*  f09e804:	00c01025 */ 	or	$v0,$a2,$zero
.L0f09e808:
/*  f09e808:	00454021 */ 	addu	$t0,$v0,$a1
/*  f09e80c:	01044821 */ 	addu	$t1,$t0,$a0
/*  f09e810:	01275021 */ 	addu	$t2,$t1,$a3
/*  f09e814:	14ca0035 */ 	bne	$a2,$t2,.L0f09e8ec
.L0f09e818:
/*  f09e818:	02802025 */ 	or	$a0,$s4,$zero
/*  f09e81c:	00008825 */ 	or	$s1,$zero,$zero
/*  f09e820:	0fc2c40f */ 	jal	func0f0b103c
/*  f09e824:	2415ffff */ 	addiu	$s5,$zero,-1
/*  f09e828:	00408025 */ 	or	$s0,$v0,$zero
/*  f09e82c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f09e830:	82441580 */ 	lb	$a0,0x1580($s2)
/*  f09e834:	12000029 */ 	beqz	$s0,.L0f09e8dc
/*  f09e838:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f09e83c:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f09e840:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f09e844:	14cc0002 */ 	bne	$a2,$t4,.L0f09e850
/*  f09e848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e84c:	02008825 */ 	or	$s1,$s0,$zero
.L0f09e850:
/*  f09e850:	1040000d */ 	beqz	$v0,.L0f09e888
/*  f09e854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e858:	1220000b */ 	beqz	$s1,.L0f09e888
/*  f09e85c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e860:	82040007 */ 	lb	$a0,0x7($s0)
/*  f09e864:	00001825 */ 	or	$v1,$zero,$zero
/*  f09e868:	04800004 */ 	bltz	$a0,.L0f09e87c
/*  f09e86c:	00046880 */ 	sll	$t5,$a0,0x2
/*  f09e870:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f09e874:	10000001 */ 	beqz	$zero,.L0f09e87c
/*  f09e878:	8dc3001c */ 	lw	$v1,0x1c($t6)
.L0f09e87c:
/*  f09e87c:	10600002 */ 	beqz	$v1,.L0f09e888
/*  f09e880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e884:	8c750004 */ 	lw	$s5,0x4($v1)
.L0f09e888:
/*  f09e888:	06a20015 */ 	bltzl	$s5,.L0f09e8e0
/*  f09e88c:	267307a4 */ 	addiu	$s3,$s3,0x7a4
/*  f09e890:	8e4f1598 */ 	lw	$t7,0x1598($s2)
/*  f09e894:	0015c040 */ 	sll	$t8,$s5,0x1
/*  f09e898:	3c138007 */ 	lui	$s3,%hi(var800707a4)
/*  f09e89c:	15e0000d */ 	bnez	$t7,.L0f09e8d4
/*  f09e8a0:	02789821 */ 	addu	$s3,$s3,$t8
/*  f09e8a4:	967300b0 */ 	lhu	$s3,0xb0($s3)
/*  f09e8a8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f09e8ac:	26481598 */ 	addiu	$t0,$s2,0x1598
/*  f09e8b0:	264915a8 */ 	addiu	$t1,$s2,0x15a8
/*  f09e8b4:	264a15ac */ 	addiu	$t2,$s2,0x15ac
/*  f09e8b8:	a25915b1 */ 	sb	$t9,0x15b1($s2)
/*  f09e8bc:	ae4815b4 */ 	sw	$t0,0x15b4($s2)
/*  f09e8c0:	ae4915b8 */ 	sw	$t1,0x15b8($s2)
/*  f09e8c4:	ae4a15bc */ 	sw	$t2,0x15bc($s2)
/*  f09e8c8:	332300ff */ 	andi	$v1,$t9,0xff
/*  f09e8cc:	10000007 */ 	beqz	$zero,.L0f09e8ec
/*  f09e8d0:	a65315b2 */ 	sh	$s3,0x15b2($s2)
.L0f09e8d4:
/*  f09e8d4:	10000005 */ 	beqz	$zero,.L0f09e8ec
/*  f09e8d8:	924315b1 */ 	lbu	$v1,0x15b1($s2)
.L0f09e8dc:
/*  f09e8dc:	267307a4 */ 	addiu	$s3,$s3,%lo(var800707a4)
.L0f09e8e0:
/*  f09e8e0:	1676ffcd */ 	bne	$s3,$s6,.L0f09e818
/*  f09e8e4:	269407a4 */ 	addiu	$s4,$s4,0x7a4
/*  f09e8e8:	924315b1 */ 	lbu	$v1,0x15b1($s2)
.L0f09e8ec:
/*  f09e8ec:	10600005 */ 	beqz	$v1,.L0f09e904
/*  f09e8f0:	00008825 */ 	or	$s1,$zero,$zero
/*  f09e8f4:	0fc27851 */ 	jal	func0f09e144
/*  f09e8f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09e8fc:	1000005b */ 	beqz	$zero,.L0f09ea6c
/*  f09e900:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f09e904:
/*  f09e904:	26500638 */ 	addiu	$s0,$s2,0x638
/*  f09e908:	26160384 */ 	addiu	$s6,$s0,0x384
/*  f09e90c:	00009825 */ 	or	$s3,$zero,$zero
/*  f09e910:	265409bc */ 	addiu	$s4,$s2,0x9bc
/*  f09e914:	26550a6c */ 	addiu	$s5,$s2,0xa6c
.L0f09e918:
/*  f09e918:	02802025 */ 	or	$a0,$s4,$zero
/*  f09e91c:	8e451590 */ 	lw	$a1,0x1590($s2)
/*  f09e920:	02a03025 */ 	or	$a2,$s5,$zero
/*  f09e924:	0c008be9 */ 	jal	func00022fa4
/*  f09e928:	00003825 */ 	or	$a3,$zero,$zero
/*  f09e92c:	8e451594 */ 	lw	$a1,0x1594($s2)
/*  f09e930:	26040534 */ 	addiu	$a0,$s0,0x534
/*  f09e934:	260604b4 */ 	addiu	$a2,$s0,0x4b4
/*  f09e938:	50a00004 */ 	beqzl	$a1,.L0f09e94c
/*  f09e93c:	8e4b15a8 */ 	lw	$t3,0x15a8($s2)
/*  f09e940:	0c008be9 */ 	jal	func00022fa4
/*  f09e944:	00003825 */ 	or	$a3,$zero,$zero
/*  f09e948:	8e4b15a8 */ 	lw	$t3,0x15a8($s2)
.L0f09e94c:
/*  f09e94c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f09e950:	ae0b0794 */ 	sw	$t3,0x794($s0)
/*  f09e954:	8e4c1590 */ 	lw	$t4,0x1590($s2)
/*  f09e958:	8e4615a8 */ 	lw	$a2,0x15a8($s2)
/*  f09e95c:	0fc28ba5 */ 	jal	func0f0a2e94
/*  f09e960:	8d850000 */ 	lw	$a1,0x0($t4)
/*  f09e964:	8e4d15a8 */ 	lw	$t5,0x15a8($s2)
/*  f09e968:	8e4f15ac */ 	lw	$t7,0x15ac($s2)
/*  f09e96c:	8e591594 */ 	lw	$t9,0x1594($s2)
/*  f09e970:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f09e974:	01e2c023 */ 	subu	$t8,$t7,$v0
/*  f09e978:	02228821 */ 	addu	$s1,$s1,$v0
/*  f09e97c:	ae4e15a8 */ 	sw	$t6,0x15a8($s2)
/*  f09e980:	1320000e */ 	beqz	$t9,.L0f09e9bc
/*  f09e984:	ae5815ac */ 	sw	$t8,0x15ac($s2)
/*  f09e988:	ae0e0798 */ 	sw	$t6,0x798($s0)
/*  f09e98c:	8e491594 */ 	lw	$t1,0x1594($s2)
/*  f09e990:	8e4615a8 */ 	lw	$a2,0x15a8($s2)
/*  f09e994:	26040534 */ 	addiu	$a0,$s0,0x534
/*  f09e998:	0fc28ba5 */ 	jal	func0f0a2e94
/*  f09e99c:	8d250000 */ 	lw	$a1,0x0($t1)
/*  f09e9a0:	8e4a15a8 */ 	lw	$t2,0x15a8($s2)
/*  f09e9a4:	8e4c15ac */ 	lw	$t4,0x15ac($s2)
/*  f09e9a8:	02228821 */ 	addu	$s1,$s1,$v0
/*  f09e9ac:	01425821 */ 	addu	$t3,$t2,$v0
/*  f09e9b0:	01826823 */ 	subu	$t5,$t4,$v0
/*  f09e9b4:	ae4b15a8 */ 	sw	$t3,0x15a8($s2)
/*  f09e9b8:	ae4d15ac */ 	sw	$t5,0x15ac($s2)
.L0f09e9bc:
/*  f09e9bc:	267307a4 */ 	addiu	$s3,$s3,0x7a4
/*  f09e9c0:	24010f48 */ 	addiu	$at,$zero,0xf48
/*  f09e9c4:	261007a4 */ 	addiu	$s0,$s0,0x7a4
/*  f09e9c8:	269407a4 */ 	addiu	$s4,$s4,0x7a4
/*  f09e9cc:	26b507a4 */ 	addiu	$s5,$s5,0x7a4
/*  f09e9d0:	1661ffd1 */ 	bne	$s3,$at,.L0f09e918
/*  f09e9d4:	26d607a4 */ 	addiu	$s6,$s6,0x7a4
/*  f09e9d8:	8e4e15ac */ 	lw	$t6,0x15ac($s2)
/*  f09e9dc:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f09e9e0:	ae500dd4 */ 	sw	$s0,0xdd4($s2)
/*  f09e9e4:	2dc10c81 */ 	sltiu	$at,$t6,0xc81
/*  f09e9e8:	5420000b */ 	bnezl	$at,.L0f09ea18
/*  f09e9ec:	ae400dd8 */ 	sw	$zero,0xdd8($s2)
/*  f09e9f0:	8e5815a8 */ 	lw	$t8,0x15a8($s2)
/*  f09e9f4:	8e4815ac */ 	lw	$t0,0x15ac($s2)
/*  f09e9f8:	8e4f15a8 */ 	lw	$t7,0x15a8($s2)
/*  f09e9fc:	27190c80 */ 	addiu	$t9,$t8,0xc80
/*  f09ea00:	2509f380 */ 	addiu	$t1,$t0,-3200
/*  f09ea04:	ae5915a8 */ 	sw	$t9,0x15a8($s2)
/*  f09ea08:	ae4915ac */ 	sw	$t1,0x15ac($s2)
/*  f09ea0c:	10000002 */ 	beqz	$zero,.L0f09ea18
/*  f09ea10:	ae4f0dd8 */ 	sw	$t7,0xdd8($s2)
/*  f09ea14:	ae400dd8 */ 	sw	$zero,0xdd8($s2)
.L0f09ea18:
/*  f09ea18:	0fc2777f */ 	jal	func0f09ddfc
/*  f09ea1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ea20:	240a0004 */ 	addiu	$t2,$zero,0x4
/*  f09ea24:	a24a15b0 */ 	sb	$t2,0x15b0($s2)
/*  f09ea28:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f09ea2c:	ae501584 */ 	sw	$s0,0x1584($s2)
/*  f09ea30:	1000000d */ 	beqz	$zero,.L0f09ea68
/*  f09ea34:	ae4b1588 */ 	sw	$t3,0x1588($s2)
.L0f09ea38:
/*  f09ea38:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f09ea3c:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f09ea40:	a24c15b0 */ 	sb	$t4,0x15b0($s2)
/*  f09ea44:	ae441588 */ 	sw	$a0,0x1588($s2)
/*  f09ea48:	10000007 */ 	beqz	$zero,.L0f09ea68
/*  f09ea4c:	ae501584 */ 	sw	$s0,0x1584($s2)
.L0f09ea50:
/*  f09ea50:	a24d15eb */ 	sb	$t5,0x15eb($s2)
/*  f09ea54:	824e15eb */ 	lb	$t6,0x15eb($s2)
/*  f09ea58:	29c1fffe */ 	slti	$at,$t6,-2
/*  f09ea5c:	50200003 */ 	beqzl	$at,.L0f09ea6c
/*  f09ea60:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f09ea64:	a24015eb */ 	sb	$zero,0x15eb($s2)
.L0f09ea68:
/*  f09ea68:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f09ea6c:
/*  f09ea6c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f09ea70:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f09ea74:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f09ea78:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f09ea7c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f09ea80:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f09ea84:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f09ea88:	03e00008 */ 	jr	$ra
/*  f09ea8c:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

GLOBAL_ASM(
glabel func0f09ea90
/*  f09ea90:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f09ea94:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f09ea98:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f09ea9c:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f09eaa0:	8e2e0034 */ 	lw	$t6,0x34($s1)
/*  f09eaa4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f09eaa8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f09eaac:	19c00008 */ 	blez	$t6,.L0f09ead0
/*  f09eab0:	00008025 */ 	or	$s0,$zero,$zero
.L0f09eab4:
/*  f09eab4:	0fc27938 */ 	jal	func0f09e4e0
/*  f09eab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09eabc:	8e2f0034 */ 	lw	$t7,0x34($s1)
/*  f09eac0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f09eac4:	020f082a */ 	slt	$at,$s0,$t7
/*  f09eac8:	1420fffa */ 	bnez	$at,.L0f09eab4
/*  f09eacc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f09ead0:
/*  f09ead0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f09ead4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f09ead8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f09eadc:	03e00008 */ 	jr	$ra
/*  f09eae0:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f09eae4
/*  f09eae4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f09eae8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f09eaec:	0fc277e7 */ 	jal	func0f09df9c
/*  f09eaf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09eaf4:	3c03800a */ 	lui	$v1,0x800a
/*  f09eaf8:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f09eafc:	80621580 */ 	lb	$v0,0x1580($v1)
/*  f09eb00:	10400003 */ 	beqz	$v0,.L0f09eb10
/*  f09eb04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09eb08:	10000003 */ 	beqz	$zero,.L0f09eb18
/*  f09eb0c:	ac621584 */ 	sw	$v0,0x1584($v1)
.L0f09eb10:
/*  f09eb10:	10000026 */ 	beqz	$zero,.L0f09ebac
/*  f09eb14:	00001025 */ 	or	$v0,$zero,$zero
.L0f09eb18:
/*  f09eb18:	3c03800a */ 	lui	$v1,0x800a
/*  f09eb1c:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f09eb20:	2401ffff */ 	addiu	$at,$zero,-1
/*  f09eb24:	8c6e1588 */ 	lw	$t6,0x1588($v1)
/*  f09eb28:	51c10004 */ 	beql	$t6,$at,.L0f09eb3c
/*  f09eb2c:	906f15ea */ 	lbu	$t7,0x15ea($v1)
/*  f09eb30:	1000001e */ 	beqz	$zero,.L0f09ebac
/*  f09eb34:	00001025 */ 	or	$v0,$zero,$zero
/*  f09eb38:	906f15ea */ 	lbu	$t7,0x15ea($v1)
.L0f09eb3c:
/*  f09eb3c:	11e0000d */ 	beqz	$t7,.L0f09eb74
/*  f09eb40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09eb44:	0fc27801 */ 	jal	func0f09e004
/*  f09eb48:	00002025 */ 	or	$a0,$zero,$zero
/*  f09eb4c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f09eb50:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f09eb54:	8c780284 */ 	lw	$t8,0x284($v1)
/*  f09eb58:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f09eb5c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f09eb60:	931915ea */ 	lbu	$t9,0x15ea($t8)
/*  f09eb64:	13200003 */ 	beqz	$t9,.L0f09eb74
/*  f09eb68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09eb6c:	1000000f */ 	beqz	$zero,.L0f09ebac
/*  f09eb70:	ac680320 */ 	sw	$t0,0x320($v1)
.L0f09eb74:
/*  f09eb74:	0fc277e7 */ 	jal	func0f09df9c
/*  f09eb78:	00000000 */ 	sll	$zero,$zero,0x0
.L0f09eb7c:
/*  f09eb7c:	0fc27938 */ 	jal	func0f09e4e0
/*  f09eb80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09eb84:	0fc2775f */ 	jal	func0f09dd7c
/*  f09eb88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09eb8c:	1040fffb */ 	beqz	$v0,.L0f09eb7c
/*  f09eb90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09eb94:	3c03800a */ 	lui	$v1,0x800a
/*  f09eb98:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f09eb9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f09eba0:	90691583 */ 	lbu	$t1,0x1583($v1)
/*  f09eba4:	312afffd */ 	andi	$t2,$t1,0xfffd
/*  f09eba8:	a06a1583 */ 	sb	$t2,0x1583($v1)
.L0f09ebac:
/*  f09ebac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09ebb0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f09ebb4:	03e00008 */ 	jr	$ra
/*  f09ebb8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09ebbc
/*  f09ebbc:	3c0e800a */ 	lui	$t6,0x800a
/*  f09ebc0:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f09ebc4:	03e00008 */ 	jr	$ra
/*  f09ebc8:	8dc21598 */ 	lw	$v0,0x1598($t6)
);

GLOBAL_ASM(
glabel func0f09ebcc
/*  f09ebcc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f09ebd0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f09ebd4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f09ebd8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f09ebdc:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f09ebe0:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f09ebe4:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f09ebe8:	8c910014 */ 	lw	$s1,0x14($a0)
/*  f09ebec:	00808025 */ 	or	$s0,$a0,$zero
/*  f09ebf0:	5220004a */ 	beqzl	$s1,.L0f09ed1c
/*  f09ebf4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f09ebf8:	0fc1812f */ 	jal	func0f0604bc
/*  f09ebfc:	02202025 */ 	or	$a0,$s1,$zero
/*  f09ec00:	0fc180bc */ 	jal	propHide
/*  f09ec04:	02202025 */ 	or	$a0,$s1,$zero
/*  f09ec08:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f09ec0c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f09ec10:	0c0057c1 */ 	jal	func00015f04
/*  f09ec14:	c5cc0014 */ 	lwc1	$f12,0x14($t6)
/*  f09ec18:	02002025 */ 	or	$a0,$s0,$zero
/*  f09ec1c:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f09ec20:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f09ec24:	0fc1a960 */ 	jal	func0f06a580
/*  f09ec28:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f09ec2c:	920f0003 */ 	lbu	$t7,0x3($s0)
/*  f09ec30:	24010008 */ 	addiu	$at,$zero,0x8
/*  f09ec34:	15e10015 */ 	bne	$t7,$at,.L0f09ec8c
/*  f09ec38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ec3c:	9218005c */ 	lbu	$t8,0x5c($s0)
/*  f09ec40:	24010056 */ 	addiu	$at,$zero,0x56
/*  f09ec44:	17010011 */ 	bne	$t8,$at,.L0f09ec8c
/*  f09ec48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ec4c:	0fc2bb15 */ 	jal	func0f0aec54
/*  f09ec50:	02202025 */ 	or	$a0,$s1,$zero
/*  f09ec54:	2401ffff */ 	addiu	$at,$zero,-1
/*  f09ec58:	14410004 */ 	bne	$v0,$at,.L0f09ec6c
/*  f09ec5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f09ec60:	0fc2bb2a */ 	jal	func0f0aeca8
/*  f09ec64:	02202025 */ 	or	$a0,$s1,$zero
/*  f09ec68:	00402025 */ 	or	$a0,$v0,$zero
.L0f09ec6c:
/*  f09ec6c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f09ec70:	10410006 */ 	beq	$v0,$at,.L0f09ec8c
/*  f09ec74:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f09ec78:	0fc2bb4f */ 	jal	func0f0aed3c
/*  f09ec7c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f09ec80:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f09ec84:	0fc2bb5c */ 	jal	func0f0aed70
/*  f09ec88:	8fa50044 */ 	lw	$a1,0x44($sp)
.L0f09ec8c:
/*  f09ec8c:	0fc1a179 */ 	jal	func0f0685e4
/*  f09ec90:	02202025 */ 	or	$a0,$s1,$zero
/*  f09ec94:	8e190040 */ 	lw	$t9,0x40($s0)
/*  f09ec98:	33280080 */ 	andi	$t0,$t9,0x80
/*  f09ec9c:	5100001f */ 	beqzl	$t0,.L0f09ed1c
/*  f09eca0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f09eca4:	8e020048 */ 	lw	$v0,0x48($s0)
/*  f09eca8:	02202025 */ 	or	$a0,$s1,$zero
/*  f09ecac:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f09ecb0:	352a0001 */ 	ori	$t2,$t1,0x1
/*  f09ecb4:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f09ecb8:	8e0c0048 */ 	lw	$t4,0x48($s0)
/*  f09ecbc:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f09ecc0:	0fc1a1a5 */ 	jal	func0f068694
/*  f09ecc4:	ad8b0088 */ 	sw	$t3,0x88($t4)
/*  f09ecc8:	8e050048 */ 	lw	$a1,0x48($s0)
/*  f09eccc:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f09ecd0:	0c005746 */ 	jal	func00015d18
/*  f09ecd4:	24a50020 */ 	addiu	$a1,$a1,0x20
/*  f09ecd8:	8fa20038 */ 	lw	$v0,0x38($sp)
/*  f09ecdc:	8e0d0048 */ 	lw	$t5,0x48($s0)
/*  f09ece0:	3c19800a */ 	lui	$t9,0x800a
/*  f09ece4:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*  f09ece8:	e5a40004 */ 	swc1	$f4,0x4($t5)
/*  f09ecec:	8e0e0048 */ 	lw	$t6,0x48($s0)
/*  f09ecf0:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f09ecf4:	e5c60008 */ 	swc1	$f6,0x8($t6)
/*  f09ecf8:	8e0f0048 */ 	lw	$t7,0x48($s0)
/*  f09ecfc:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f09ed00:	e5e8000c */ 	swc1	$f8,0xc($t7)
/*  f09ed04:	8e180048 */ 	lw	$t8,0x48($s0)
/*  f09ed08:	af1000d4 */ 	sw	$s0,0xd4($t8)
/*  f09ed0c:	8e080048 */ 	lw	$t0,0x48($s0)
/*  f09ed10:	8f399fcc */ 	lw	$t9,-0x6034($t9)
/*  f09ed14:	ad1900d8 */ 	sw	$t9,0xd8($t0)
/*  f09ed18:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f09ed1c:
/*  f09ed1c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f09ed20:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f09ed24:	03e00008 */ 	jr	$ra
/*  f09ed28:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f09ed2c
/*  f09ed2c:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f09ed30:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f09ed34:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f09ed38:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f09ed3c:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f09ed40:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f09ed44:	8c820014 */ 	lw	$v0,0x14($a0)
/*  f09ed48:	00808025 */ 	or	$s0,$a0,$zero
/*  f09ed4c:	3c0e800a */ 	lui	$t6,0x800a
/*  f09ed50:	5040002d */ 	beqzl	$v0,.L0f09ee08
/*  f09ed54:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f09ed58:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f09ed5c:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f09ed60:	8dc200bc */ 	lw	$v0,0xbc($t6)
/*  f09ed64:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f09ed68:	24440028 */ 	addiu	$a0,$v0,0x28
/*  f09ed6c:	e7a40048 */ 	swc1	$f4,0x48($sp)
/*  f09ed70:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f09ed74:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*  f09ed78:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f09ed7c:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f09ed80:	0fc195e9 */ 	jal	func0f0657a4
/*  f09ed84:	e7a80050 */ 	swc1	$f8,0x50($sp)
/*  f09ed88:	8fa20034 */ 	lw	$v0,0x34($sp)
/*  f09ed8c:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f09ed90:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f09ed94:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f09ed98:	02002025 */ 	or	$a0,$s0,$zero
/*  f09ed9c:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f09eda0:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f09eda4:	8fa70060 */ 	lw	$a3,0x60($sp)
/*  f09eda8:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f09edac:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f09edb0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f09edb4:	0fc27af3 */ 	jal	func0f09ebcc
/*  f09edb8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f09edbc:	8e190040 */ 	lw	$t9,0x40($s0)
/*  f09edc0:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f09edc4:	33280080 */ 	andi	$t0,$t9,0x80
/*  f09edc8:	5100000f */ 	beqzl	$t0,.L0f09ee08
/*  f09edcc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f09edd0:	8e020048 */ 	lw	$v0,0x48($s0)
/*  f09edd4:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f09edd8:	352a0080 */ 	ori	$t2,$t1,0x80
/*  f09eddc:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f09ede0:	8e0b0048 */ 	lw	$t3,0x48($s0)
/*  f09ede4:	c46a0000 */ 	lwc1	$f10,0x0($v1)
/*  f09ede8:	e56a00c4 */ 	swc1	$f10,0xc4($t3)
/*  f09edec:	8e0c0048 */ 	lw	$t4,0x48($s0)
/*  f09edf0:	c4700004 */ 	lwc1	$f16,0x4($v1)
/*  f09edf4:	e59000c8 */ 	swc1	$f16,0xc8($t4)
/*  f09edf8:	8e0d0048 */ 	lw	$t5,0x48($s0)
/*  f09edfc:	c4720008 */ 	lwc1	$f18,0x8($v1)
/*  f09ee00:	e5b200cc */ 	swc1	$f18,0xcc($t5)
/*  f09ee04:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f09ee08:
/*  f09ee08:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f09ee0c:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f09ee10:	03e00008 */ 	jr	$ra
/*  f09ee14:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09ee18
/*  f09ee18:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f09ee1c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f09ee20:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f09ee24:	afa400b8 */ 	sw	$a0,0xb8($sp)
/*  f09ee28:	afa500bc */ 	sw	$a1,0xbc($sp)
/*  f09ee2c:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f09ee30:	afa700c4 */ 	sw	$a3,0xc4($sp)
/*  f09ee34:	00008025 */ 	or	$s0,$zero,$zero
/*  f09ee38:	0fc2c3f4 */ 	jal	weaponFindById
/*  f09ee3c:	90a40000 */ 	lbu	$a0,0x0($a1)
/*  f09ee40:	14400003 */ 	bnez	$v0,.L0f09ee50
/*  f09ee44:	8fa300bc */ 	lw	$v1,0xbc($sp)
/*  f09ee48:	100000a8 */ 	beqz	$zero,.L0f09f0ec
/*  f09ee4c:	00001025 */ 	or	$v0,$zero,$zero
.L0f09ee50:
/*  f09ee50:	906f0003 */ 	lbu	$t7,0x3($v1)
/*  f09ee54:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f09ee58:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f09ee5c:	8f280014 */ 	lw	$t0,0x14($t9)
/*  f09ee60:	55000004 */ 	bnezl	$t0,.L0f09ee74
/*  f09ee64:	90690000 */ 	lbu	$t1,0x0($v1)
/*  f09ee68:	100000a0 */ 	beqz	$zero,.L0f09f0ec
/*  f09ee6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f09ee70:	90690000 */ 	lbu	$t1,0x0($v1)
.L0f09ee74:
/*  f09ee74:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f09ee78:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f09ee7c:	1521001e */ 	bne	$t1,$at,.L0f09eef8
/*  f09ee80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ee84:	0c004b70 */ 	jal	random
/*  f09ee88:	afa800b0 */ 	sw	$t0,0xb0($sp)
/*  f09ee8c:	44822000 */ 	mtc1	$v0,$f4
/*  f09ee90:	8fa300c8 */ 	lw	$v1,0xc8($sp)
/*  f09ee94:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f09ee98:	04410005 */ 	bgez	$v0,.L0f09eeb0
/*  f09ee9c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f09eea0:	3c014f80 */ 	lui	$at,0x4f80
/*  f09eea4:	44814000 */ 	mtc1	$at,$f8
/*  f09eea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09eeac:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f09eeb0:
/*  f09eeb0:	3c012f80 */ 	lui	$at,0x2f80
/*  f09eeb4:	44815000 */ 	mtc1	$at,$f10
/*  f09eeb8:	3c017f1b */ 	lui	$at,%hi(var7f1ac700)
/*  f09eebc:	c432c700 */ 	lwc1	$f18,%lo(var7f1ac700)($at)
/*  f09eec0:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f09eec4:	3c0142b4 */ 	lui	$at,0x42b4
/*  f09eec8:	44814000 */ 	mtc1	$at,$f8
/*  f09eecc:	c46a0018 */ 	lwc1	$f10,0x18($v1)
/*  f09eed0:	8c660010 */ 	lw	$a2,0x10($v1)
/*  f09eed4:	8c670014 */ 	lw	$a3,0x14($v1)
/*  f09eed8:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f09eedc:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f09eee0:	46044183 */ 	div.s	$f6,$f8,$f4
/*  f09eee4:	44053000 */ 	mfc1	$a1,$f6
/*  f09eee8:	0c0012a0 */ 	jal	func00004a80
/*  f09eeec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09eef0:	10000004 */ 	beqz	$zero,.L0f09ef04
/*  f09eef4:	8fa800b0 */ 	lw	$t0,0xb0($sp)
.L0f09eef8:
/*  f09eef8:	0fc258d8 */ 	jal	func0f096360
/*  f09eefc:	afa800b0 */ 	sw	$t0,0xb0($sp)
/*  f09ef00:	8fa800b0 */ 	lw	$t0,0xb0($sp)
.L0f09ef04:
/*  f09ef04:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f09ef08:	2401000e */ 	addiu	$at,$zero,0xe
/*  f09ef0c:	8fa500bc */ 	lw	$a1,0xbc($sp)
/*  f09ef10:	914b0000 */ 	lbu	$t3,0x0($t2)
/*  f09ef14:	8fa600b8 */ 	lw	$a2,0xb8($sp)
/*  f09ef18:	5561000a */ 	bnel	$t3,$at,.L0f09ef44
/*  f09ef1c:	8d040014 */ 	lw	$a0,0x14($t0)
/*  f09ef20:	8d040014 */ 	lw	$a0,0x14($t0)
/*  f09ef24:	01402825 */ 	or	$a1,$t2,$zero
/*  f09ef28:	0fc22c9f */ 	jal	func0f08b27c
/*  f09ef2c:	8fa600b8 */ 	lw	$a2,0xb8($sp)
/*  f09ef30:	1040002a */ 	beqz	$v0,.L0f09efdc
/*  f09ef34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ef38:	10000028 */ 	beqz	$zero,.L0f09efdc
/*  f09ef3c:	00408025 */ 	or	$s0,$v0,$zero
/*  f09ef40:	8d040014 */ 	lw	$a0,0x14($t0)
.L0f09ef44:
/*  f09ef44:	0fc22d96 */ 	jal	func0f08b658
/*  f09ef48:	afa800b0 */ 	sw	$t0,0xb0($sp)
/*  f09ef4c:	8fa800b0 */ 	lw	$t0,0xb0($sp)
/*  f09ef50:	10400022 */ 	beqz	$v0,.L0f09efdc
/*  f09ef54:	00402825 */ 	or	$a1,$v0,$zero
/*  f09ef58:	850c0018 */ 	lh	$t4,0x18($t0)
/*  f09ef5c:	00408025 */ 	or	$s0,$v0,$zero
/*  f09ef60:	a44c0062 */ 	sh	$t4,0x62($v0)
/*  f09ef64:	84430062 */ 	lh	$v1,0x62($v0)
/*  f09ef68:	28610002 */ 	slti	$at,$v1,0x2
/*  f09ef6c:	14200002 */ 	bnez	$at,.L0f09ef78
/*  f09ef70:	00036880 */ 	sll	$t5,$v1,0x2
/*  f09ef74:	a44d0062 */ 	sh	$t5,0x62($v0)
.L0f09ef78:
/*  f09ef78:	9043005c */ 	lbu	$v1,0x5c($v0)
/*  f09ef7c:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f09ef80:	10610003 */ 	beq	$v1,$at,.L0f09ef90
/*  f09ef84:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f09ef88:	54610008 */ 	bnel	$v1,$at,.L0f09efac
/*  f09ef8c:	8d020014 */ 	lw	$v0,0x14($t0)
.L0f09ef90:
/*  f09ef90:	8ca40014 */ 	lw	$a0,0x14($a1)
/*  f09ef94:	afa800b0 */ 	sw	$t0,0xb0($sp)
/*  f09ef98:	0fc10e70 */ 	jal	registerDangerousProp
/*  f09ef9c:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f09efa0:	8fa500a4 */ 	lw	$a1,0xa4($sp)
/*  f09efa4:	8fa800b0 */ 	lw	$t0,0xb0($sp)
/*  f09efa8:	8d020014 */ 	lw	$v0,0x14($t0)
.L0f09efac:
/*  f09efac:	24010115 */ 	addiu	$at,$zero,0x115
/*  f09efb0:	10410007 */ 	beq	$v0,$at,.L0f09efd0
/*  f09efb4:	24010113 */ 	addiu	$at,$zero,0x113
/*  f09efb8:	10410005 */ 	beq	$v0,$at,.L0f09efd0
/*  f09efbc:	24010114 */ 	addiu	$at,$zero,0x114
/*  f09efc0:	10410003 */ 	beq	$v0,$at,.L0f09efd0
/*  f09efc4:	24010116 */ 	addiu	$at,$zero,0x116
/*  f09efc8:	14410004 */ 	bne	$v0,$at,.L0f09efdc
/*  f09efcc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f09efd0:
/*  f09efd0:	8cae0010 */ 	lw	$t6,0x10($a1)
/*  f09efd4:	35cf0008 */ 	ori	$t7,$t6,0x8
/*  f09efd8:	acaf0010 */ 	sw	$t7,0x10($a1)
.L0f09efdc:
/*  f09efdc:	12000042 */ 	beqz	$s0,.L0f09f0e8
/*  f09efe0:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f09efe4:	8fb800cc */ 	lw	$t8,0xcc($sp)
/*  f09efe8:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*  f09efec:	27b90060 */ 	addiu	$t9,$sp,0x60
/*  f09eff0:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f09eff4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f09eff8:	8d2b001c */ 	lw	$t3,0x1c($t1)
/*  f09effc:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f09f000:	02002025 */ 	or	$a0,$s0,$zero
/*  f09f004:	8fa600c4 */ 	lw	$a2,0xc4($sp)
/*  f09f008:	8fa700c8 */ 	lw	$a3,0xc8($sp)
/*  f09f00c:	0fc27af3 */ 	jal	func0f09ebcc
/*  f09f010:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f09f014:	8e0a0040 */ 	lw	$t2,0x40($s0)
/*  f09f018:	3c010fff */ 	lui	$at,0xfff
/*  f09f01c:	3421ffff */ 	ori	$at,$at,0xffff
/*  f09f020:	01416024 */ 	and	$t4,$t2,$at
/*  f09f024:	ae0c0040 */ 	sw	$t4,0x40($s0)
/*  f09f028:	3c0d800a */ 	lui	$t5,0x800a
/*  f09f02c:	8dada2d8 */ 	lw	$t5,-0x5d28($t5)
/*  f09f030:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f09f034:	11a00005 */ 	beqz	$t5,.L0f09f04c
/*  f09f038:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09f03c:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f09f040:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*  f09f044:	10000004 */ 	beqz	$zero,.L0f09f058
/*  f09f048:	8e0f0040 */ 	lw	$t7,0x40($s0)
.L0f09f04c:
/*  f09f04c:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f09f050:	8dc4001c */ 	lw	$a0,0x1c($t6)
/*  f09f054:	8e0f0040 */ 	lw	$t7,0x40($s0)
.L0f09f058:
/*  f09f058:	0002c700 */ 	sll	$t8,$v0,0x1c
/*  f09f05c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09f060:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f09f064:	332b0080 */ 	andi	$t3,$t9,0x80
/*  f09f068:	1160001f */ 	beqz	$t3,.L0f09f0e8
/*  f09f06c:	ae190040 */ 	sw	$t9,0x40($s0)
/*  f09f070:	8e020048 */ 	lw	$v0,0x48($s0)
/*  f09f074:	44810000 */ 	mtc1	$at,$f0
/*  f09f078:	3c017f1b */ 	lui	$at,%hi(var7f1ac704)
/*  f09f07c:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f09f080:	240e00f0 */ 	addiu	$t6,$zero,0xf0
/*  f09f084:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f09f088:	354c0002 */ 	ori	$t4,$t2,0x2
/*  f09f08c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f09f090:	8e0d0048 */ 	lw	$t5,0x48($s0)
/*  f09f094:	c430c704 */ 	lwc1	$f16,%lo(var7f1ac704)($at)
/*  f09f098:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f09f09c:	00002025 */ 	or	$a0,$zero,$zero
/*  f09f0a0:	e5b0008c */ 	swc1	$f16,0x8c($t5)
/*  f09f0a4:	8e0f0048 */ 	lw	$t7,0x48($s0)
/*  f09f0a8:	240680a9 */ 	addiu	$a2,$zero,-32599
/*  f09f0ac:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09f0b0:	adee00b4 */ 	sw	$t6,0xb4($t7)
/*  f09f0b4:	8e050014 */ 	lw	$a1,0x14($s0)
/*  f09f0b8:	afb9002c */ 	sw	$t9,0x2c($sp)
/*  f09f0bc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f09f0c0:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f09f0c4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f09f0c8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f09f0cc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f09f0d0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f09f0d4:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f09f0d8:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f09f0dc:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f09f0e0:	0fc24e7e */ 	jal	func0f0939f8
/*  f09f0e4:	e7a00024 */ 	swc1	$f0,0x24($sp)
.L0f09f0e8:
/*  f09f0e8:	02001025 */ 	or	$v0,$s0,$zero
.L0f09f0ec:
/*  f09f0ec:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f09f0f0:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f09f0f4:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f09f0f8:	03e00008 */ 	jr	$ra
/*  f09f0fc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09f100
/*  f09f100:	27bdfdc0 */ 	addiu	$sp,$sp,-576
/*  f09f104:	3c0f8007 */ 	lui	$t7,%hi(var800701ac)
/*  f09f108:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f09f10c:	afa50244 */ 	sw	$a1,0x244($sp)
/*  f09f110:	25ef01ac */ 	addiu	$t7,$t7,%lo(var800701ac)
/*  f09f114:	8de10000 */ 	lw	$at,0x0($t7)
/*  f09f118:	27ae0234 */ 	addiu	$t6,$sp,0x234
/*  f09f11c:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f09f120:	adc10000 */ 	sw	$at,0x0($t6)
/*  f09f124:	8de10008 */ 	lw	$at,0x8($t7)
/*  f09f128:	3c03800a */ 	lui	$v1,0x800a
/*  f09f12c:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f09f130:	adc10008 */ 	sw	$at,0x8($t6)
/*  f09f134:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f09f138:	28810002 */ 	slti	$at,$a0,0x2
/*  f09f13c:	00803825 */ 	or	$a3,$a0,$zero
/*  f09f140:	8c6a00bc */ 	lw	$t2,0xbc($v1)
/*  f09f144:	246b0310 */ 	addiu	$t3,$v1,0x310
/*  f09f148:	246c1c44 */ 	addiu	$t4,$v1,0x1c44
/*  f09f14c:	afab01d4 */ 	sw	$t3,0x1d4($sp)
/*  f09f150:	afac01d0 */ 	sw	$t4,0x1d0($sp)
/*  f09f154:	00003025 */ 	or	$a2,$zero,$zero
/*  f09f158:	14200003 */ 	bnez	$at,.L0f09f168
/*  f09f15c:	afaa01d8 */ 	sw	$t2,0x1d8($sp)
/*  f09f160:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f09f164:	2487fffe */ 	addiu	$a3,$a0,-2
.L0f09f168:
/*  f09f168:	00072900 */ 	sll	$a1,$a3,0x4
/*  f09f16c:	00a72823 */ 	subu	$a1,$a1,$a3
/*  f09f170:	00052880 */ 	sll	$a1,$a1,0x2
/*  f09f174:	00a72821 */ 	addu	$a1,$a1,$a3
/*  f09f178:	000528c0 */ 	sll	$a1,$a1,0x3
/*  f09f17c:	00a72821 */ 	addu	$a1,$a1,$a3
/*  f09f180:	00052880 */ 	sll	$a1,$a1,0x2
/*  f09f184:	00656821 */ 	addu	$t5,$v1,$a1
/*  f09f188:	25b90638 */ 	addiu	$t9,$t5,0x638
/*  f09f18c:	afb90158 */ 	sw	$t9,0x158($sp)
/*  f09f190:	00651021 */ 	addu	$v0,$v1,$a1
/*  f09f194:	c44409ac */ 	lwc1	$f4,0x9ac($v0)
/*  f09f198:	27a401f4 */ 	addiu	$a0,$sp,0x1f4
/*  f09f19c:	e7a4017c */ 	swc1	$f4,0x17c($sp)
/*  f09f1a0:	c44609b0 */ 	lwc1	$f6,0x9b0($v0)
/*  f09f1a4:	e7a60180 */ 	swc1	$f6,0x180($sp)
/*  f09f1a8:	c44809b4 */ 	lwc1	$f8,0x9b4($v0)
/*  f09f1ac:	afa70240 */ 	sw	$a3,0x240($sp)
/*  f09f1b0:	afa6015c */ 	sw	$a2,0x15c($sp)
/*  f09f1b4:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f09f1b8:	0c00566c */ 	jal	func000159b0
/*  f09f1bc:	e7a80184 */ 	swc1	$f8,0x184($sp)
/*  f09f1c0:	8fb80244 */ 	lw	$t8,0x244($sp)
/*  f09f1c4:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f09f1c8:	930e0000 */ 	lbu	$t6,0x0($t8)
/*  f09f1cc:	15c1000b */ 	bne	$t6,$at,.L0f09f1fc
/*  f09f1d0:	3c017f1b */ 	lui	$at,%hi(var7f1ac708)
/*  f09f1d4:	c42cc708 */ 	lwc1	$f12,%lo(var7f1ac708)($at)
/*  f09f1d8:	0c005900 */ 	jal	func00016400
/*  f09f1dc:	27a501f4 */ 	addiu	$a1,$sp,0x1f4
/*  f09f1e0:	3c017f1b */ 	lui	$at,%hi(var7f1ac70c)
/*  f09f1e4:	c42cc70c */ 	lwc1	$f12,%lo(var7f1ac70c)($at)
/*  f09f1e8:	0c0058ba */ 	jal	func000162e8
/*  f09f1ec:	27a50190 */ 	addiu	$a1,$sp,0x190
/*  f09f1f0:	27a40190 */ 	addiu	$a0,$sp,0x190
/*  f09f1f4:	0c00567f */ 	jal	func000159fc
/*  f09f1f8:	27a501f4 */ 	addiu	$a1,$sp,0x1f4
.L0f09f1fc:
/*  f09f1fc:	3c0f800a */ 	lui	$t7,0x800a
/*  f09f200:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f09f204:	8fa90034 */ 	lw	$t1,0x34($sp)
/*  f09f208:	27a50190 */ 	addiu	$a1,$sp,0x190
/*  f09f20c:	01e92021 */ 	addu	$a0,$t7,$t1
/*  f09f210:	0c005746 */ 	jal	func00015d18
/*  f09f214:	24840c58 */ 	addiu	$a0,$a0,0xc58
/*  f09f218:	27a40190 */ 	addiu	$a0,$sp,0x190
/*  f09f21c:	27a50194 */ 	addiu	$a1,$sp,0x194
/*  f09f220:	0c0011e4 */ 	jal	scaleTo1
/*  f09f224:	27a60198 */ 	addiu	$a2,$sp,0x198
/*  f09f228:	27a401a0 */ 	addiu	$a0,$sp,0x1a0
/*  f09f22c:	27a501a4 */ 	addiu	$a1,$sp,0x1a4
/*  f09f230:	0c0011e4 */ 	jal	scaleTo1
/*  f09f234:	27a601a8 */ 	addiu	$a2,$sp,0x1a8
/*  f09f238:	27a401b0 */ 	addiu	$a0,$sp,0x1b0
/*  f09f23c:	27a501b4 */ 	addiu	$a1,$sp,0x1b4
/*  f09f240:	0c0011e4 */ 	jal	scaleTo1
/*  f09f244:	27a601b8 */ 	addiu	$a2,$sp,0x1b8
/*  f09f248:	44800000 */ 	mtc1	$zero,$f0
/*  f09f24c:	27a40190 */ 	addiu	$a0,$sp,0x190
/*  f09f250:	27a501f4 */ 	addiu	$a1,$sp,0x1f4
/*  f09f254:	e7a001c0 */ 	swc1	$f0,0x1c0($sp)
/*  f09f258:	e7a001c4 */ 	swc1	$f0,0x1c4($sp)
/*  f09f25c:	0c00567f */ 	jal	func000159fc
/*  f09f260:	e7a001c8 */ 	swc1	$f0,0x1c8($sp)
/*  f09f264:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f09f268:	0fc30795 */ 	jal	func0f0c1e54
/*  f09f26c:	00002825 */ 	or	$a1,$zero,$zero
/*  f09f270:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
/*  f09f274:	240a003f */ 	addiu	$t2,$zero,0x3f
/*  f09f278:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f09f27c:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f09f280:	afa50038 */ 	sw	$a1,0x38($sp)
/*  f09f284:	27a6017c */ 	addiu	$a2,$sp,0x17c
/*  f09f288:	27a70160 */ 	addiu	$a3,$sp,0x160
/*  f09f28c:	0c00b7ab */ 	jal	func0002deac
/*  f09f290:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f09f294:	10400008 */ 	beqz	$v0,.L0f09f2b8
/*  f09f298:	8fab01d8 */ 	lw	$t3,0x1d8($sp)
/*  f09f29c:	c7aa017c */ 	lwc1	$f10,0x17c($sp)
/*  f09f2a0:	c7b00180 */ 	lwc1	$f16,0x180($sp)
/*  f09f2a4:	c7b20184 */ 	lwc1	$f18,0x184($sp)
/*  f09f2a8:	e7aa0170 */ 	swc1	$f10,0x170($sp)
/*  f09f2ac:	e7b00174 */ 	swc1	$f16,0x174($sp)
/*  f09f2b0:	1000000a */ 	beqz	$zero,.L0f09f2dc
/*  f09f2b4:	e7b20178 */ 	swc1	$f18,0x178($sp)
.L0f09f2b8:
/*  f09f2b8:	c5640008 */ 	lwc1	$f4,0x8($t3)
/*  f09f2bc:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f09f2c0:	27a50160 */ 	addiu	$a1,$sp,0x160
/*  f09f2c4:	e7a40170 */ 	swc1	$f4,0x170($sp)
/*  f09f2c8:	c566000c */ 	lwc1	$f6,0xc($t3)
/*  f09f2cc:	e7a60174 */ 	swc1	$f6,0x174($sp)
/*  f09f2d0:	c5680010 */ 	lwc1	$f8,0x10($t3)
/*  f09f2d4:	0fc195e9 */ 	jal	func0f0657a4
/*  f09f2d8:	e7a80178 */ 	swc1	$f8,0x178($sp)
.L0f09f2dc:
/*  f09f2dc:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f09f2e0:	0fc30795 */ 	jal	func0f0c1e54
/*  f09f2e4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f09f2e8:	27a401e8 */ 	addiu	$a0,$sp,0x1e8
/*  f09f2ec:	27a501dc */ 	addiu	$a1,$sp,0x1dc
/*  f09f2f0:	8fa60240 */ 	lw	$a2,0x240($sp)
/*  f09f2f4:	0fc2832c */ 	jal	func0f0a0cb0
/*  f09f2f8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f09f2fc:	0fc2d5de */ 	jal	func0f0b5778
/*  f09f300:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09f304:	00402025 */ 	or	$a0,$v0,$zero
/*  f09f308:	0c0056c4 */ 	jal	func00015b10
/*  f09f30c:	27a501dc */ 	addiu	$a1,$sp,0x1dc
/*  f09f310:	8fac015c */ 	lw	$t4,0x15c($sp)
/*  f09f314:	3c017f1b */ 	lui	$at,%hi(var7f1ac710)
/*  f09f318:	c7aa01dc */ 	lwc1	$f10,0x1dc($sp)
/*  f09f31c:	1180000d */ 	beqz	$t4,.L0f09f354
/*  f09f320:	8fa40158 */ 	lw	$a0,0x158($sp)
/*  f09f324:	c420c710 */ 	lwc1	$f0,%lo(var7f1ac710)($at)
/*  f09f328:	c7b201e0 */ 	lwc1	$f18,0x1e0($sp)
/*  f09f32c:	c7a601e4 */ 	lwc1	$f6,0x1e4($sp)
/*  f09f330:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f09f334:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09f338:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f09f33c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09f340:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f09f344:	e7b00234 */ 	swc1	$f16,0x234($sp)
/*  f09f348:	e7a40238 */ 	swc1	$f4,0x238($sp)
/*  f09f34c:	100000a9 */ 	beqz	$zero,.L0f09f5f4
/*  f09f350:	e7a8023c */ 	swc1	$f8,0x23c($sp)
.L0f09f354:
/*  f09f354:	0fc2c7aa */ 	jal	func0f0b1ea8
/*  f09f358:	3c050080 */ 	lui	$a1,0x80
/*  f09f35c:	10400087 */ 	beqz	$v0,.L0f09f57c
/*  f09f360:	3c017f1b */ 	lui	$at,%hi(var7f1ac714)
/*  f09f364:	00002025 */ 	or	$a0,$zero,$zero
/*  f09f368:	00002825 */ 	or	$a1,$zero,$zero
/*  f09f36c:	0fc18755 */ 	jal	func0f061d54
/*  f09f370:	00003025 */ 	or	$a2,$zero,$zero
/*  f09f374:	8fad0158 */ 	lw	$t5,0x158($sp)
/*  f09f378:	8db906b4 */ 	lw	$t9,0x6b4($t5)
/*  f09f37c:	13200071 */ 	beqz	$t9,.L0f09f544
/*  f09f380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09f384:	c5aa06b8 */ 	lwc1	$f10,0x6b8($t5)
/*  f09f388:	3c0541ad */ 	lui	$a1,0x41ad
/*  f09f38c:	34a55555 */ 	ori	$a1,$a1,0x5555
/*  f09f390:	e7aa014c */ 	swc1	$f10,0x14c($sp)
/*  f09f394:	c5b006bc */ 	lwc1	$f16,0x6bc($t5)
/*  f09f398:	27a40170 */ 	addiu	$a0,$sp,0x170
/*  f09f39c:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f09f3a0:	e7b00150 */ 	swc1	$f16,0x150($sp)
/*  f09f3a4:	c5b206c0 */ 	lwc1	$f18,0x6c0($t5)
/*  f09f3a8:	27a70140 */ 	addiu	$a3,$sp,0x140
/*  f09f3ac:	0fc100c7 */ 	jal	func0f04031c
/*  f09f3b0:	e7b20154 */ 	swc1	$f18,0x154($sp)
/*  f09f3b4:	c7a401dc */ 	lwc1	$f4,0x1dc($sp)
/*  f09f3b8:	c7a60140 */ 	lwc1	$f6,0x140($sp)
/*  f09f3bc:	c7aa01e0 */ 	lwc1	$f10,0x1e0($sp)
/*  f09f3c0:	c7b00144 */ 	lwc1	$f16,0x144($sp)
/*  f09f3c4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f09f3c8:	c7a60148 */ 	lwc1	$f6,0x148($sp)
/*  f09f3cc:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f09f3d0:	c7aa01e4 */ 	lwc1	$f10,0x1e4($sp)
/*  f09f3d4:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f09f3d8:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f09f3dc:	0fc25a74 */ 	jal	func0f0969d0
/*  f09f3e0:	46048300 */ 	add.s	$f12,$f16,$f4
/*  f09f3e4:	3c017f1b */ 	lui	$at,%hi(var7f1ac718)
/*  f09f3e8:	c428c714 */ 	lwc1	$f8,%lo(var7f1ac714)($at)
/*  f09f3ec:	e7a00138 */ 	swc1	$f0,0x138($sp)
/*  f09f3f0:	3c017f1b */ 	lui	$at,%hi(var7f1ac71c)
/*  f09f3f4:	4600403c */ 	c.lt.s	$f8,$f0
/*  f09f3f8:	27a400f8 */ 	addiu	$a0,$sp,0xf8
/*  f09f3fc:	c7a601dc */ 	lwc1	$f6,0x1dc($sp)
/*  f09f400:	45030007 */ 	bc1tl	.L0f09f420
/*  f09f404:	44800000 */ 	mtc1	$zero,$f0
/*  f09f408:	c432c718 */ 	lwc1	$f18,%lo(var7f1ac718)($at)
/*  f09f40c:	4612003c */ 	c.lt.s	$f0,$f18
/*  f09f410:	c7b20140 */ 	lwc1	$f18,0x140($sp)
/*  f09f414:	45020047 */ 	bc1fl	.L0f09f534
/*  f09f418:	c7a60144 */ 	lwc1	$f6,0x144($sp)
/*  f09f41c:	44800000 */ 	mtc1	$zero,$f0
.L0f09f420:
/*  f09f420:	3c013f80 */ 	lui	$at,0x3f80
/*  f09f424:	44812000 */ 	mtc1	$at,$f4
/*  f09f428:	c7aa01e0 */ 	lwc1	$f10,0x1e0($sp)
/*  f09f42c:	c7b001e4 */ 	lwc1	$f16,0x1e4($sp)
/*  f09f430:	44050000 */ 	mfc1	$a1,$f0
/*  f09f434:	44060000 */ 	mfc1	$a2,$f0
/*  f09f438:	44070000 */ 	mfc1	$a3,$f0
/*  f09f43c:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f09f440:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f09f444:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f09f448:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f09f44c:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f09f450:	0c005ad6 */ 	jal	func00016b58
/*  f09f454:	e7b00018 */ 	swc1	$f16,0x18($sp)
/*  f09f458:	44800000 */ 	mtc1	$zero,$f0
/*  f09f45c:	3c013f80 */ 	lui	$at,0x3f80
/*  f09f460:	44815000 */ 	mtc1	$at,$f10
/*  f09f464:	c7a80140 */ 	lwc1	$f8,0x140($sp)
/*  f09f468:	c7b20144 */ 	lwc1	$f18,0x144($sp)
/*  f09f46c:	c7a60148 */ 	lwc1	$f6,0x148($sp)
/*  f09f470:	44050000 */ 	mfc1	$a1,$f0
/*  f09f474:	44060000 */ 	mfc1	$a2,$f0
/*  f09f478:	44070000 */ 	mfc1	$a3,$f0
/*  f09f47c:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f09f480:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f09f484:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f09f488:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f09f48c:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*  f09f490:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f09f494:	0c005ad6 */ 	jal	func00016b58
/*  f09f498:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*  f09f49c:	27a400f8 */ 	addiu	$a0,$sp,0xf8
/*  f09f4a0:	0fc25c11 */ 	jal	func0f097044
/*  f09f4a4:	27a50068 */ 	addiu	$a1,$sp,0x68
/*  f09f4a8:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f09f4ac:	0fc25c11 */ 	jal	func0f097044
/*  f09f4b0:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f09f4b4:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f09f4b8:	0fc25db0 */ 	jal	func0f0976c0
/*  f09f4bc:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f09f4c0:	3c017f1b */ 	lui	$at,%hi(var7f1ac720)
/*  f09f4c4:	c430c71c */ 	lwc1	$f16,%lo(var7f1ac71c)($at)
/*  f09f4c8:	c7a40138 */ 	lwc1	$f4,0x138($sp)
/*  f09f4cc:	44804000 */ 	mtc1	$zero,$f8
/*  f09f4d0:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f09f4d4:	46048003 */ 	div.s	$f0,$f16,$f4
/*  f09f4d8:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f09f4dc:	4608003c */ 	c.lt.s	$f0,$f8
/*  f09f4e0:	46000086 */ 	mov.s	$f2,$f0
/*  f09f4e4:	45020003 */ 	bc1fl	.L0f09f4f4
/*  f09f4e8:	44061000 */ 	mfc1	$a2,$f2
/*  f09f4ec:	46000087 */ 	neg.s	$f2,$f0
/*  f09f4f0:	44061000 */ 	mfc1	$a2,$f2
.L0f09f4f4:
/*  f09f4f4:	0fc25cae */ 	jal	func0f0972b8
/*  f09f4f8:	27a70048 */ 	addiu	$a3,$sp,0x48
/*  f09f4fc:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f09f500:	0fc25bb5 */ 	jal	func0f096ed4
/*  f09f504:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f09f508:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f09f50c:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f09f510:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f09f514:	46009187 */ 	neg.s	$f6,$f18
/*  f09f518:	46005407 */ 	neg.s	$f16,$f10
/*  f09f51c:	46002207 */ 	neg.s	$f8,$f4
/*  f09f520:	e7a601dc */ 	swc1	$f6,0x1dc($sp)
/*  f09f524:	e7b001e0 */ 	swc1	$f16,0x1e0($sp)
/*  f09f528:	10000006 */ 	beqz	$zero,.L0f09f544
/*  f09f52c:	e7a801e4 */ 	swc1	$f8,0x1e4($sp)
/*  f09f530:	c7a60144 */ 	lwc1	$f6,0x144($sp)
.L0f09f534:
/*  f09f534:	c7aa0148 */ 	lwc1	$f10,0x148($sp)
/*  f09f538:	e7b201dc */ 	swc1	$f18,0x1dc($sp)
/*  f09f53c:	e7a601e0 */ 	swc1	$f6,0x1e0($sp)
/*  f09f540:	e7aa01e4 */ 	swc1	$f10,0x1e4($sp)
.L0f09f544:
/*  f09f544:	3c017f1b */ 	lui	$at,%hi(var7f1ac724)
/*  f09f548:	c420c720 */ 	lwc1	$f0,%lo(var7f1ac720)($at)
/*  f09f54c:	c7b001dc */ 	lwc1	$f16,0x1dc($sp)
/*  f09f550:	c7a801e0 */ 	lwc1	$f8,0x1e0($sp)
/*  f09f554:	c7a601e4 */ 	lwc1	$f6,0x1e4($sp)
/*  f09f558:	46008102 */ 	mul.s	$f4,$f16,$f0
/*  f09f55c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09f560:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f09f564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09f568:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f09f56c:	e7a40234 */ 	swc1	$f4,0x234($sp)
/*  f09f570:	e7b20238 */ 	swc1	$f18,0x238($sp)
/*  f09f574:	1000001f */ 	beqz	$zero,.L0f09f5f4
/*  f09f578:	e7aa023c */ 	swc1	$f10,0x23c($sp)
.L0f09f57c:
/*  f09f57c:	c420c724 */ 	lwc1	$f0,%lo(var7f1ac724)($at)
/*  f09f580:	c7b001dc */ 	lwc1	$f16,0x1dc($sp)
/*  f09f584:	c7a801e0 */ 	lwc1	$f8,0x1e0($sp)
/*  f09f588:	c7a601e4 */ 	lwc1	$f6,0x1e4($sp)
/*  f09f58c:	46008102 */ 	mul.s	$f4,$f16,$f0
/*  f09f590:	8fb80244 */ 	lw	$t8,0x244($sp)
/*  f09f594:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f09f598:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f09f59c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09f5a0:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f09f5a4:	e7a40234 */ 	swc1	$f4,0x234($sp)
/*  f09f5a8:	e7b20238 */ 	swc1	$f18,0x238($sp)
/*  f09f5ac:	c7b00238 */ 	lwc1	$f16,0x238($sp)
/*  f09f5b0:	e7aa023c */ 	swc1	$f10,0x23c($sp)
/*  f09f5b4:	93030000 */ 	lbu	$v1,0x0($t8)
/*  f09f5b8:	10610004 */ 	beq	$v1,$at,.L0f09f5cc
/*  f09f5bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09f5c0:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f09f5c4:	14610006 */ 	bne	$v1,$at,.L0f09f5e0
/*  f09f5c8:	c7a80238 */ 	lwc1	$f8,0x238($sp)
.L0f09f5cc:
/*  f09f5cc:	3c017f1b */ 	lui	$at,%hi(var7f1ac728)
/*  f09f5d0:	c420c728 */ 	lwc1	$f0,%lo(var7f1ac728)($at)
/*  f09f5d4:	46008100 */ 	add.s	$f4,$f16,$f0
/*  f09f5d8:	10000006 */ 	beqz	$zero,.L0f09f5f4
/*  f09f5dc:	e7a40238 */ 	swc1	$f4,0x238($sp)
.L0f09f5e0:
/*  f09f5e0:	3c0140a0 */ 	lui	$at,0x40a0
/*  f09f5e4:	44819000 */ 	mtc1	$at,$f18
/*  f09f5e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09f5ec:	46124180 */ 	add.s	$f6,$f8,$f18
/*  f09f5f0:	e7a60238 */ 	swc1	$f6,0x238($sp)
.L0f09f5f4:
/*  f09f5f4:	8fae0244 */ 	lw	$t6,0x244($sp)
/*  f09f5f8:	2401000e */ 	addiu	$at,$zero,0xe
/*  f09f5fc:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*  f09f600:	15e10003 */ 	bne	$t7,$at,.L0f09f610
/*  f09f604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09f608:	0fc284d3 */ 	jal	func0f0a134c
/*  f09f60c:	8fa40240 */ 	lw	$a0,0x240($sp)
.L0f09f610:
/*  f09f610:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f09f614:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f09f618:	8d090034 */ 	lw	$t1,0x34($t0)
/*  f09f61c:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
/*  f09f620:	8fa301d4 */ 	lw	$v1,0x1d4($sp)
/*  f09f624:	1920001e */ 	blez	$t1,.L0f09f6a0
/*  f09f628:	27a60170 */ 	addiu	$a2,$sp,0x170
/*  f09f62c:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f09f630:	c4700000 */ 	lwc1	$f16,0x0($v1)
/*  f09f634:	8fa401d0 */ 	lw	$a0,0x1d0($sp)
/*  f09f638:	c500004c */ 	lwc1	$f0,0x4c($t0)
/*  f09f63c:	46105101 */ 	sub.s	$f4,$f10,$f16
/*  f09f640:	c4880000 */ 	lwc1	$f8,0x0($a0)
/*  f09f644:	c7aa0234 */ 	lwc1	$f10,0x234($sp)
/*  f09f648:	46082480 */ 	add.s	$f18,$f4,$f8
/*  f09f64c:	46009183 */ 	div.s	$f6,$f18,$f0
/*  f09f650:	46065400 */ 	add.s	$f16,$f10,$f6
/*  f09f654:	e7b00234 */ 	swc1	$f16,0x234($sp)
/*  f09f658:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*  f09f65c:	c444000c */ 	lwc1	$f4,0xc($v0)
/*  f09f660:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f09f664:	46082481 */ 	sub.s	$f18,$f4,$f8
/*  f09f668:	c7a40238 */ 	lwc1	$f4,0x238($sp)
/*  f09f66c:	460a9180 */ 	add.s	$f6,$f18,$f10
/*  f09f670:	46003403 */ 	div.s	$f16,$f6,$f0
/*  f09f674:	46102200 */ 	add.s	$f8,$f4,$f16
/*  f09f678:	e7a80238 */ 	swc1	$f8,0x238($sp)
/*  f09f67c:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f09f680:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f09f684:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f09f688:	460a9181 */ 	sub.s	$f6,$f18,$f10
/*  f09f68c:	c7b2023c */ 	lwc1	$f18,0x23c($sp)
/*  f09f690:	46043400 */ 	add.s	$f16,$f6,$f4
/*  f09f694:	46008203 */ 	div.s	$f8,$f16,$f0
/*  f09f698:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f09f69c:	e7aa023c */ 	swc1	$f10,0x23c($sp)
.L0f09f6a0:
/*  f09f6a0:	8d0a0284 */ 	lw	$t2,0x284($t0)
/*  f09f6a4:	27ac01f4 */ 	addiu	$t4,$sp,0x1f4
/*  f09f6a8:	27b90234 */ 	addiu	$t9,$sp,0x234
/*  f09f6ac:	8d4b00bc */ 	lw	$t3,0xbc($t2)
/*  f09f6b0:	8fa50244 */ 	lw	$a1,0x244($sp)
/*  f09f6b4:	27a70160 */ 	addiu	$a3,$sp,0x160
/*  f09f6b8:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f09f6bc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f09f6c0:	0fc27b86 */ 	jal	func0f09ee18
/*  f09f6c4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f09f6c8:	1040005b */ 	beqz	$v0,.L0f09f838
/*  f09f6cc:	00402025 */ 	or	$a0,$v0,$zero
/*  f09f6d0:	904d0003 */ 	lbu	$t5,0x3($v0)
/*  f09f6d4:	24010008 */ 	addiu	$at,$zero,0x8
/*  f09f6d8:	8fa60244 */ 	lw	$a2,0x244($sp)
/*  f09f6dc:	55a10027 */ 	bnel	$t5,$at,.L0f09f77c
/*  f09f6e0:	8c8d0040 */ 	lw	$t5,0x40($a0)
/*  f09f6e4:	afa20188 */ 	sw	$v0,0x188($sp)
/*  f09f6e8:	90c30000 */ 	lbu	$v1,0x0($a2)
/*  f09f6ec:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f09f6f0:	54610013 */ 	bnel	$v1,$at,.L0f09f740
/*  f09f6f4:	24010035 */ 	addiu	$at,$zero,0x35
/*  f09f6f8:	90d80003 */ 	lbu	$t8,0x3($a2)
/*  f09f6fc:	8fae0158 */ 	lw	$t6,0x158($sp)
/*  f09f700:	5700000f */ 	bnezl	$t8,.L0f09f740
/*  f09f704:	24010035 */ 	addiu	$at,$zero,0x35
/*  f09f708:	85c306d4 */ 	lh	$v1,0x6d4($t6)
/*  f09f70c:	84450062 */ 	lh	$a1,0x62($v0)
/*  f09f710:	00037880 */ 	sll	$t7,$v1,0x2
/*  f09f714:	00af082a */ 	slt	$at,$a1,$t7
/*  f09f718:	10200003 */ 	beqz	$at,.L0f09f728
/*  f09f71c:	01e01825 */ 	or	$v1,$t7,$zero
/*  f09f720:	10000003 */ 	beqz	$zero,.L0f09f730
/*  f09f724:	a4400062 */ 	sh	$zero,0x62($v0)
.L0f09f728:
/*  f09f728:	00a34823 */ 	subu	$t1,$a1,$v1
/*  f09f72c:	a4490062 */ 	sh	$t1,0x62($v0)
.L0f09f730:
/*  f09f730:	90ca0003 */ 	lbu	$t2,0x3($a2)
/*  f09f734:	10000010 */ 	beqz	$zero,.L0f09f778
/*  f09f738:	a04a005f */ 	sb	$t2,0x5f($v0)
/*  f09f73c:	24010035 */ 	addiu	$at,$zero,0x35
.L0f09f740:
/*  f09f740:	1461000d */ 	bne	$v1,$at,.L0f09f778
/*  f09f744:	3c0b800a */ 	lui	$t3,0x800a
/*  f09f748:	8d6ba474 */ 	lw	$t3,-0x5b8c($t3)
/*  f09f74c:	24010026 */ 	addiu	$at,$zero,0x26
/*  f09f750:	5561000a */ 	bnel	$t3,$at,.L0f09f77c
/*  f09f754:	8c8d0040 */ 	lw	$t5,0x40($a0)
/*  f09f758:	0fc68606 */ 	jal	ciGetTrainingData
/*  f09f75c:	afa4018c */ 	sw	$a0,0x18c($sp)
/*  f09f760:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f09f764:	8fa4018c */ 	lw	$a0,0x18c($sp)
/*  f09f768:	000ccfc2 */ 	srl	$t9,$t4,0x1f
/*  f09f76c:	53200003 */ 	beqzl	$t9,.L0f09f77c
/*  f09f770:	8c8d0040 */ 	lw	$t5,0x40($a0)
/*  f09f774:	ac440008 */ 	sw	$a0,0x8($v0)
.L0f09f778:
/*  f09f778:	8c8d0040 */ 	lw	$t5,0x40($a0)
.L0f09f77c:
/*  f09f77c:	8fa60244 */ 	lw	$a2,0x244($sp)
/*  f09f780:	31b80080 */ 	andi	$t8,$t5,0x80
/*  f09f784:	5300002d */ 	beqzl	$t8,.L0f09f83c
/*  f09f788:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f09f78c:	8c820048 */ 	lw	$v0,0x48($a0)
/*  f09f790:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f09f794:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f09f798:	35cf0080 */ 	ori	$t7,$t6,0x80
/*  f09f79c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f09f7a0:	8c890048 */ 	lw	$t1,0x48($a0)
/*  f09f7a4:	c7a6017c */ 	lwc1	$f6,0x17c($sp)
/*  f09f7a8:	e52600c4 */ 	swc1	$f6,0xc4($t1)
/*  f09f7ac:	8c8a0048 */ 	lw	$t2,0x48($a0)
/*  f09f7b0:	c7a40180 */ 	lwc1	$f4,0x180($sp)
/*  f09f7b4:	e54400c8 */ 	swc1	$f4,0xc8($t2)
/*  f09f7b8:	8c8b0048 */ 	lw	$t3,0x48($a0)
/*  f09f7bc:	c7b00184 */ 	lwc1	$f16,0x184($sp)
/*  f09f7c0:	e57000cc */ 	swc1	$f16,0xcc($t3)
/*  f09f7c4:	90c30000 */ 	lbu	$v1,0x0($a2)
/*  f09f7c8:	5461000a */ 	bnel	$v1,$at,.L0f09f7f4
/*  f09f7cc:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f09f7d0:	90cc0003 */ 	lbu	$t4,0x3($a2)
/*  f09f7d4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09f7d8:	15810005 */ 	bne	$t4,$at,.L0f09f7f0
/*  f09f7dc:	3c013f80 */ 	lui	$at,0x3f80
/*  f09f7e0:	44819000 */ 	mtc1	$at,$f18
/*  f09f7e4:	8c990048 */ 	lw	$t9,0x48($a0)
/*  f09f7e8:	e732008c */ 	swc1	$f18,0x8c($t9)
/*  f09f7ec:	90c30000 */ 	lbu	$v1,0x0($a2)
.L0f09f7f0:
/*  f09f7f0:	2401001a */ 	addiu	$at,$zero,0x1a
.L0f09f7f4:
/*  f09f7f4:	14610010 */ 	bne	$v1,$at,.L0f09f838
/*  f09f7f8:	8fad0188 */ 	lw	$t5,0x188($sp)
/*  f09f7fc:	8da20048 */ 	lw	$v0,0x48($t5)
/*  f09f800:	3c017f1b */ 	lui	$at,%hi(var7f1ac72c)
/*  f09f804:	240a00f0 */ 	addiu	$t2,$zero,0xf0
/*  f09f808:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f09f80c:	370e0002 */ 	ori	$t6,$t8,0x2
/*  f09f810:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f09f814:	8faf0188 */ 	lw	$t7,0x188($sp)
/*  f09f818:	c428c72c */ 	lwc1	$f8,%lo(var7f1ac72c)($at)
/*  f09f81c:	8de90048 */ 	lw	$t1,0x48($t7)
/*  f09f820:	e528008c */ 	swc1	$f8,0x8c($t1)
/*  f09f824:	8deb0048 */ 	lw	$t3,0x48($t7)
/*  f09f828:	ad6a00b4 */ 	sw	$t2,0xb4($t3)
/*  f09f82c:	8dec0040 */ 	lw	$t4,0x40($t7)
/*  f09f830:	35990020 */ 	ori	$t9,$t4,0x20
/*  f09f834:	adf90040 */ 	sw	$t9,0x40($t7)
.L0f09f838:
/*  f09f838:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f09f83c:
/*  f09f83c:	27bd0240 */ 	addiu	$sp,$sp,0x240
/*  f09f840:	03e00008 */ 	jr	$ra
/*  f09f844:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09f848
/*  f09f848:	00047100 */ 	sll	$t6,$a0,0x4
/*  f09f84c:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f09f850:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f09f854:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f09f858:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f09f85c:	3c02800a */ 	lui	$v0,0x800a
/*  f09f860:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f09f864:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f09f868:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f09f86c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f09f870:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f09f874:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f09f878:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f09f87c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f09f880:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f09f884:	004e8821 */ 	addu	$s1,$v0,$t6
/*  f09f888:	8e300850 */ 	lw	$s0,0x850($s1)
/*  f09f88c:	26310638 */ 	addiu	$s1,$s1,0x638
/*  f09f890:	52000032 */ 	beqzl	$s0,.L0f09f95c
/*  f09f894:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f09f898:	8e120014 */ 	lw	$s2,0x14($s0)
/*  f09f89c:	5240002f */ 	beqzl	$s2,.L0f09f95c
/*  f09f8a0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f09f8a4:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f09f8a8:	262402f4 */ 	addiu	$a0,$s1,0x2f4
/*  f09f8ac:	afaf0030 */ 	sw	$t7,0x30($sp)
/*  f09f8b0:	8e38021c */ 	lw	$t8,0x21c($s1)
/*  f09f8b4:	8e130018 */ 	lw	$s3,0x18($s0)
/*  f09f8b8:	57000014 */ 	bnezl	$t8,.L0f09f90c
/*  f09f8bc:	8e680008 */ 	lw	$t0,0x8($s3)
/*  f09f8c0:	0c005746 */ 	jal	func00015d18
/*  f09f8c4:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f09f8c8:	44800000 */ 	mtc1	$zero,$f0
/*  f09f8cc:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f09f8d0:	e7a00064 */ 	swc1	$f0,0x64($sp)
/*  f09f8d4:	e7a00068 */ 	swc1	$f0,0x68($sp)
/*  f09f8d8:	e7a0006c */ 	swc1	$f0,0x6c($sp)
/*  f09f8dc:	8e190018 */ 	lw	$t9,0x18($s0)
/*  f09f8e0:	0c0057c1 */ 	jal	func00015f04
/*  f09f8e4:	c72c0014 */ 	lwc1	$f12,0x14($t9)
/*  f09f8e8:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f09f8ec:	02002025 */ 	or	$a0,$s0,$zero
/*  f09f8f0:	26250374 */ 	addiu	$a1,$s1,0x374
/*  f09f8f4:	27a60034 */ 	addiu	$a2,$sp,0x34
/*  f09f8f8:	0fc1a960 */ 	jal	func0f06a580
/*  f09f8fc:	24e70028 */ 	addiu	$a3,$a3,0x28
/*  f09f900:	0fc19711 */ 	jal	func0f065c44
/*  f09f904:	02402025 */ 	or	$a0,$s2,$zero
/*  f09f908:	8e680008 */ 	lw	$t0,0x8($s3)
.L0f09f90c:
/*  f09f90c:	8504000e */ 	lh	$a0,0xe($t0)
/*  f09f910:	00044980 */ 	sll	$t1,$a0,0x6
/*  f09f914:	0fc59e7d */ 	jal	func0f1679f4
/*  f09f918:	01202025 */ 	or	$a0,$t1,$zero
/*  f09f91c:	ae62000c */ 	sw	$v0,0xc($s3)
/*  f09f920:	26240620 */ 	addiu	$a0,$s1,0x620
/*  f09f924:	0c005746 */ 	jal	func00015d18
/*  f09f928:	00402825 */ 	or	$a1,$v0,$zero
/*  f09f92c:	8e6a0008 */ 	lw	$t2,0x8($s3)
/*  f09f930:	02602025 */ 	or	$a0,$s3,$zero
/*  f09f934:	0c0072c3 */ 	jal	func0001cb0c
/*  f09f938:	8d450000 */ 	lw	$a1,0x0($t2)
/*  f09f93c:	924b0001 */ 	lbu	$t3,0x1($s2)
/*  f09f940:	356c0042 */ 	ori	$t4,$t3,0x42
/*  f09f944:	a24c0001 */ 	sb	$t4,0x1($s2)
/*  f09f948:	8e6d000c */ 	lw	$t5,0xc($s3)
/*  f09f94c:	c5a40038 */ 	lwc1	$f4,0x38($t5)
/*  f09f950:	46002187 */ 	neg.s	$f6,$f4
/*  f09f954:	e6460014 */ 	swc1	$f6,0x14($s2)
/*  f09f958:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f09f95c:
/*  f09f95c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f09f960:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f09f964:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f09f968:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f09f96c:	03e00008 */ 	jr	$ra
/*  f09f970:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

GLOBAL_ASM(
glabel func0f09f974
/*  f09f974:	00047900 */ 	sll	$t7,$a0,0x4
/*  f09f978:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f09f97c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f09f980:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09f984:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f09f988:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f09f98c:	8c4e0284 */ 	lw	$t6,0x284($v0)
/*  f09f990:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f09f994:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f09f998:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f09f99c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09f9a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f09f9a4:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f09f9a8:	8c780850 */ 	lw	$t8,0x850($v1)
/*  f09f9ac:	24630638 */ 	addiu	$v1,$v1,0x638
/*  f09f9b0:	57000018 */ 	bnezl	$t8,.L0f09fa14
/*  f09f9b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09f9b8:	ac60021c */ 	sw	$zero,0x21c($v1)
/*  f09f9bc:	8c590284 */ 	lw	$t9,0x284($v0)
/*  f09f9c0:	8ca40040 */ 	lw	$a0,0x40($a1)
/*  f09f9c4:	24050053 */ 	addiu	$a1,$zero,0x53
/*  f09f9c8:	8f2800bc */ 	lw	$t0,0xbc($t9)
/*  f09f9cc:	8d060004 */ 	lw	$a2,0x4($t0)
/*  f09f9d0:	0fc22e20 */ 	jal	func0f08b880
/*  f09f9d4:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f09f9d8:	1040000d */ 	beqz	$v0,.L0f09fa10
/*  f09f9dc:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f09f9e0:	ac620218 */ 	sw	$v0,0x218($v1)
/*  f09f9e4:	ac60021c */ 	sw	$zero,0x21c($v1)
/*  f09f9e8:	8c4a0008 */ 	lw	$t2,0x8($v0)
/*  f09f9ec:	8c4c000c */ 	lw	$t4,0xc($v0)
/*  f09f9f0:	3c010080 */ 	lui	$at,0x80
/*  f09f9f4:	01415825 */ 	or	$t3,$t2,$at
/*  f09f9f8:	3c010200 */ 	lui	$at,0x200
/*  f09f9fc:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f09fa00:	01816825 */ 	or	$t5,$t4,$at
/*  f09fa04:	a4490062 */ 	sh	$t1,0x62($v0)
/*  f09fa08:	ac4b0008 */ 	sw	$t3,0x8($v0)
/*  f09fa0c:	ac4d000c */ 	sw	$t5,0xc($v0)
.L0f09fa10:
/*  f09fa10:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f09fa14:
/*  f09fa14:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f09fa18:	03e00008 */ 	jr	$ra
/*  f09fa1c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09fa20
/*  f09fa20:	00047900 */ 	sll	$t7,$a0,0x4
/*  f09fa24:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f09fa28:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09fa2c:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f09fa30:	3c0e800a */ 	lui	$t6,0x800a
/*  f09fa34:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f09fa38:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f09fa3c:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f09fa40:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f09fa44:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09fa48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f09fa4c:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f09fa50:	8c460850 */ 	lw	$a2,0x850($v0)
/*  f09fa54:	24420638 */ 	addiu	$v0,$v0,0x638
/*  f09fa58:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f09fa5c:	10c00005 */ 	beqz	$a2,.L0f09fa74
/*  f09fa60:	00c02025 */ 	or	$a0,$a2,$zero
/*  f09fa64:	0fc1acd3 */ 	jal	setupParseObjectWithArg2False
/*  f09fa68:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f09fa6c:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f09fa70:	ac400218 */ 	sw	$zero,0x218($v0)
.L0f09fa74:
/*  f09fa74:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09fa78:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f09fa7c:	03e00008 */ 	jr	$ra
/*  f09fa80:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f09fa84
/*  f09fa84:	3c02800a */ 	lui	$v0,0x800a
/*  f09fa88:	00042900 */ 	sll	$a1,$a0,0x4
/*  f09fa8c:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f09fa90:	00a42823 */ 	subu	$a1,$a1,$a0
/*  f09fa94:	27bdfd48 */ 	addiu	$sp,$sp,-696
/*  f09fa98:	00052880 */ 	sll	$a1,$a1,0x2
/*  f09fa9c:	00a42821 */ 	addu	$a1,$a1,$a0
/*  f09faa0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f09faa4:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f09faa8:	000528c0 */ 	sll	$a1,$a1,0x3
/*  f09faac:	8c4e00bc */ 	lw	$t6,0xbc($v0)
/*  f09fab0:	00a42821 */ 	addu	$a1,$a1,$a0
/*  f09fab4:	00052880 */ 	sll	$a1,$a1,0x2
/*  f09fab8:	00451821 */ 	addu	$v1,$v0,$a1
/*  f09fabc:	244f0310 */ 	addiu	$t7,$v0,0x310
/*  f09fac0:	24581c44 */ 	addiu	$t8,$v0,0x1c44
/*  f09fac4:	00808025 */ 	or	$s0,$a0,$zero
/*  f09fac8:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f09facc:	afb801ec */ 	sw	$t8,0x1ec($sp)
/*  f09fad0:	afae01f4 */ 	sw	$t6,0x1f4($sp)
/*  f09fad4:	24630638 */ 	addiu	$v1,$v1,0x638
/*  f09fad8:	90640000 */ 	lbu	$a0,0x0($v1)
/*  f09fadc:	afa50058 */ 	sw	$a1,0x58($sp)
/*  f09fae0:	0fc2c3f4 */ 	jal	weaponFindById
/*  f09fae4:	afa302b0 */ 	sw	$v1,0x2b0($sp)
/*  f09fae8:	10400225 */ 	beqz	$v0,.L0f0a0380
/*  f09faec:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*  f09faf0:	93280003 */ 	lbu	$t0,0x3($t9)
/*  f09faf4:	00084880 */ 	sll	$t1,$t0,0x2
/*  f09faf8:	00495021 */ 	addu	$t2,$v0,$t1
/*  f09fafc:	8d430014 */ 	lw	$v1,0x14($t2)
/*  f09fb00:	50600220 */ 	beqzl	$v1,.L0f0a0384
/*  f09fb04:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f09fb08:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f09fb0c:	24010201 */ 	addiu	$at,$zero,0x201
/*  f09fb10:	27a40270 */ 	addiu	$a0,$sp,0x270
/*  f09fb14:	5561021b */ 	bnel	$t3,$at,.L0f0a0384
/*  f09fb18:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f09fb1c:	0c00566c */ 	jal	func000159b0
/*  f09fb20:	afa301d8 */ 	sw	$v1,0x1d8($sp)
/*  f09fb24:	27a40204 */ 	addiu	$a0,$sp,0x204
/*  f09fb28:	27a501f8 */ 	addiu	$a1,$sp,0x1f8
/*  f09fb2c:	02003025 */ 	or	$a2,$s0,$zero
/*  f09fb30:	0fc2832c */ 	jal	func0f0a0cb0
/*  f09fb34:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f09fb38:	0fc2d5de */ 	jal	func0f0b5778
/*  f09fb3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09fb40:	00402025 */ 	or	$a0,$v0,$zero
/*  f09fb44:	0c0056c4 */ 	jal	func00015b10
/*  f09fb48:	27a501f8 */ 	addiu	$a1,$sp,0x1f8
/*  f09fb4c:	8fa402b0 */ 	lw	$a0,0x2b0($sp)
/*  f09fb50:	24010019 */ 	addiu	$at,$zero,0x19
/*  f09fb54:	c4840374 */ 	lwc1	$f4,0x374($a0)
/*  f09fb58:	e7a401e0 */ 	swc1	$f4,0x1e0($sp)
/*  f09fb5c:	c4860378 */ 	lwc1	$f6,0x378($a0)
/*  f09fb60:	e7a601e4 */ 	swc1	$f6,0x1e4($sp)
/*  f09fb64:	c488037c */ 	lwc1	$f8,0x37c($a0)
/*  f09fb68:	e7a801e8 */ 	swc1	$f8,0x1e8($sp)
/*  f09fb6c:	908c0000 */ 	lbu	$t4,0x0($a0)
/*  f09fb70:	55810016 */ 	bnel	$t4,$at,.L0f09fbcc
/*  f09fb74:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
/*  f09fb78:	908d0003 */ 	lbu	$t5,0x3($a0)
/*  f09fb7c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f09fb80:	c7aa01e0 */ 	lwc1	$f10,0x1e0($sp)
/*  f09fb84:	15a10010 */ 	bne	$t5,$at,.L0f09fbc8
/*  f09fb88:	c7b001f8 */ 	lwc1	$f16,0x1f8($sp)
/*  f09fb8c:	3c014248 */ 	lui	$at,0x4248
/*  f09fb90:	44810000 */ 	mtc1	$at,$f0
/*  f09fb94:	c7a801fc */ 	lwc1	$f8,0x1fc($sp)
/*  f09fb98:	c7a601e4 */ 	lwc1	$f6,0x1e4($sp)
/*  f09fb9c:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f09fba0:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f09fba4:	46080402 */ 	mul.s	$f16,$f0,$f8
/*  f09fba8:	c7b201e8 */ 	lwc1	$f18,0x1e8($sp)
/*  f09fbac:	e7a401e0 */ 	swc1	$f4,0x1e0($sp)
/*  f09fbb0:	c7a40200 */ 	lwc1	$f4,0x200($sp)
/*  f09fbb4:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f09fbb8:	46103280 */ 	add.s	$f10,$f6,$f16
/*  f09fbbc:	e7aa01e4 */ 	swc1	$f10,0x1e4($sp)
/*  f09fbc0:	46089180 */ 	add.s	$f6,$f18,$f8
/*  f09fbc4:	e7a601e8 */ 	swc1	$f6,0x1e8($sp)
.L0f09fbc8:
/*  f09fbc8:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
.L0f09fbcc:
/*  f09fbcc:	3c017f1b */ 	lui	$at,%hi(var7f1ac730)
/*  f09fbd0:	c420c730 */ 	lwc1	$f0,%lo(var7f1ac730)($at)
/*  f09fbd4:	8c4e004c */ 	lw	$t6,0x4c($v0)
/*  f09fbd8:	3c014270 */ 	lui	$at,0x4270
/*  f09fbdc:	44819000 */ 	mtc1	$at,$f18
/*  f09fbe0:	448e8000 */ 	mtc1	$t6,$f16
/*  f09fbe4:	3c050080 */ 	lui	$a1,0x80
/*  f09fbe8:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f09fbec:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f09fbf0:	46122203 */ 	div.s	$f8,$f4,$f18
/*  f09fbf4:	e7a80260 */ 	swc1	$f8,0x260($sp)
/*  f09fbf8:	8c4f0054 */ 	lw	$t7,0x54($v0)
/*  f09fbfc:	448f3000 */ 	mtc1	$t7,$f6
/*  f09fc00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09fc04:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f09fc08:	46008282 */ 	mul.s	$f10,$f16,$f0
/*  f09fc0c:	0fc2c7aa */ 	jal	func0f0b1ea8
/*  f09fc10:	e7aa025c */ 	swc1	$f10,0x25c($sp)
/*  f09fc14:	1040007a */ 	beqz	$v0,.L0f09fe00
/*  f09fc18:	00002025 */ 	or	$a0,$zero,$zero
/*  f09fc1c:	00002825 */ 	or	$a1,$zero,$zero
/*  f09fc20:	0fc18755 */ 	jal	func0f061d54
/*  f09fc24:	00003025 */ 	or	$a2,$zero,$zero
/*  f09fc28:	8fa302b0 */ 	lw	$v1,0x2b0($sp)
/*  f09fc2c:	8c7806b4 */ 	lw	$t8,0x6b4($v1)
/*  f09fc30:	53000074 */ 	beqzl	$t8,.L0f09fe04
/*  f09fc34:	c7ac0260 */ 	lwc1	$f12,0x260($sp)
/*  f09fc38:	c46406b8 */ 	lwc1	$f4,0x6b8($v1)
/*  f09fc3c:	27a401e0 */ 	addiu	$a0,$sp,0x1e0
/*  f09fc40:	8fa5025c */ 	lw	$a1,0x25c($sp)
/*  f09fc44:	e7a401c8 */ 	swc1	$f4,0x1c8($sp)
/*  f09fc48:	c47206bc */ 	lwc1	$f18,0x6bc($v1)
/*  f09fc4c:	27a601c8 */ 	addiu	$a2,$sp,0x1c8
/*  f09fc50:	27a701bc */ 	addiu	$a3,$sp,0x1bc
/*  f09fc54:	e7b201cc */ 	swc1	$f18,0x1cc($sp)
/*  f09fc58:	c46806c0 */ 	lwc1	$f8,0x6c0($v1)
/*  f09fc5c:	0fc100c7 */ 	jal	func0f04031c
/*  f09fc60:	e7a801d0 */ 	swc1	$f8,0x1d0($sp)
/*  f09fc64:	c7a601f8 */ 	lwc1	$f6,0x1f8($sp)
/*  f09fc68:	c7b001bc */ 	lwc1	$f16,0x1bc($sp)
/*  f09fc6c:	c7a401fc */ 	lwc1	$f4,0x1fc($sp)
/*  f09fc70:	c7b201c0 */ 	lwc1	$f18,0x1c0($sp)
/*  f09fc74:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f09fc78:	c7b001c4 */ 	lwc1	$f16,0x1c4($sp)
/*  f09fc7c:	46122202 */ 	mul.s	$f8,$f4,$f18
/*  f09fc80:	c7a40200 */ 	lwc1	$f4,0x200($sp)
/*  f09fc84:	46048482 */ 	mul.s	$f18,$f16,$f4
/*  f09fc88:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f09fc8c:	0fc25a74 */ 	jal	func0f0969d0
/*  f09fc90:	46069300 */ 	add.s	$f12,$f18,$f6
/*  f09fc94:	3c017f1b */ 	lui	$at,%hi(var7f1ac734)
/*  f09fc98:	c42ac734 */ 	lwc1	$f10,%lo(var7f1ac734)($at)
/*  f09fc9c:	27b00174 */ 	addiu	$s0,$sp,0x174
/*  f09fca0:	e7a001b4 */ 	swc1	$f0,0x1b4($sp)
/*  f09fca4:	4600503c */ 	c.lt.s	$f10,$f0
/*  f09fca8:	3c017f1b */ 	lui	$at,%hi(var7f1ac738)
/*  f09fcac:	02002025 */ 	or	$a0,$s0,$zero
/*  f09fcb0:	c7b001f8 */ 	lwc1	$f16,0x1f8($sp)
/*  f09fcb4:	45030008 */ 	bc1tl	.L0f09fcd8
/*  f09fcb8:	44801000 */ 	mtc1	$zero,$f2
/*  f09fcbc:	c428c738 */ 	lwc1	$f8,%lo(var7f1ac738)($at)
/*  f09fcc0:	c7aa01bc */ 	lwc1	$f10,0x1bc($sp)
/*  f09fcc4:	4608003c */ 	c.lt.s	$f0,$f8
/*  f09fcc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09fccc:	45020048 */ 	bc1fl	.L0f09fdf0
/*  f09fcd0:	c7a801c0 */ 	lwc1	$f8,0x1c0($sp)
/*  f09fcd4:	44801000 */ 	mtc1	$zero,$f2
.L0f09fcd8:
/*  f09fcd8:	3c013f80 */ 	lui	$at,0x3f80
/*  f09fcdc:	44813000 */ 	mtc1	$at,$f6
/*  f09fce0:	c7a401fc */ 	lwc1	$f4,0x1fc($sp)
/*  f09fce4:	c7b20200 */ 	lwc1	$f18,0x200($sp)
/*  f09fce8:	44051000 */ 	mfc1	$a1,$f2
/*  f09fcec:	44061000 */ 	mfc1	$a2,$f2
/*  f09fcf0:	44071000 */ 	mfc1	$a3,$f2
/*  f09fcf4:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f09fcf8:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f09fcfc:	e7a20024 */ 	swc1	$f2,0x24($sp)
/*  f09fd00:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f09fd04:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f09fd08:	0c005ad6 */ 	jal	func00016b58
/*  f09fd0c:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f09fd10:	44801000 */ 	mtc1	$zero,$f2
/*  f09fd14:	3c013f80 */ 	lui	$at,0x3f80
/*  f09fd18:	44812000 */ 	mtc1	$at,$f4
/*  f09fd1c:	c7aa01bc */ 	lwc1	$f10,0x1bc($sp)
/*  f09fd20:	c7a801c0 */ 	lwc1	$f8,0x1c0($sp)
/*  f09fd24:	c7b001c4 */ 	lwc1	$f16,0x1c4($sp)
/*  f09fd28:	44051000 */ 	mfc1	$a1,$f2
/*  f09fd2c:	44061000 */ 	mfc1	$a2,$f2
/*  f09fd30:	44071000 */ 	mfc1	$a3,$f2
/*  f09fd34:	27a40134 */ 	addiu	$a0,$sp,0x134
/*  f09fd38:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f09fd3c:	e7a20024 */ 	swc1	$f2,0x24($sp)
/*  f09fd40:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f09fd44:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f09fd48:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f09fd4c:	0c005ad6 */ 	jal	func00016b58
/*  f09fd50:	e7b00018 */ 	swc1	$f16,0x18($sp)
/*  f09fd54:	02002025 */ 	or	$a0,$s0,$zero
/*  f09fd58:	0fc25c11 */ 	jal	func0f097044
/*  f09fd5c:	27a500e4 */ 	addiu	$a1,$sp,0xe4
/*  f09fd60:	27b000d4 */ 	addiu	$s0,$sp,0xd4
/*  f09fd64:	02002825 */ 	or	$a1,$s0,$zero
/*  f09fd68:	0fc25c11 */ 	jal	func0f097044
/*  f09fd6c:	27a40134 */ 	addiu	$a0,$sp,0x134
/*  f09fd70:	27a400e4 */ 	addiu	$a0,$sp,0xe4
/*  f09fd74:	0fc25db0 */ 	jal	func0f0976c0
/*  f09fd78:	02002825 */ 	or	$a1,$s0,$zero
/*  f09fd7c:	3c017f1b */ 	lui	$at,%hi(var7f1ac73c)
/*  f09fd80:	c432c73c */ 	lwc1	$f18,%lo(var7f1ac73c)($at)
/*  f09fd84:	c7a601b4 */ 	lwc1	$f6,0x1b4($sp)
/*  f09fd88:	44801000 */ 	mtc1	$zero,$f2
/*  f09fd8c:	27a400e4 */ 	addiu	$a0,$sp,0xe4
/*  f09fd90:	46069003 */ 	div.s	$f0,$f18,$f6
/*  f09fd94:	02002825 */ 	or	$a1,$s0,$zero
/*  f09fd98:	4602003c */ 	c.lt.s	$f0,$f2
/*  f09fd9c:	46000306 */ 	mov.s	$f12,$f0
/*  f09fda0:	45020003 */ 	bc1fl	.L0f09fdb0
/*  f09fda4:	44066000 */ 	mfc1	$a2,$f12
/*  f09fda8:	46000307 */ 	neg.s	$f12,$f0
/*  f09fdac:	44066000 */ 	mfc1	$a2,$f12
.L0f09fdb0:
/*  f09fdb0:	0fc25cae */ 	jal	func0f0972b8
/*  f09fdb4:	27a700c4 */ 	addiu	$a3,$sp,0xc4
/*  f09fdb8:	27a400c4 */ 	addiu	$a0,$sp,0xc4
/*  f09fdbc:	0fc25bb5 */ 	jal	func0f096ed4
/*  f09fdc0:	27a500f4 */ 	addiu	$a1,$sp,0xf4
/*  f09fdc4:	c7aa0114 */ 	lwc1	$f10,0x114($sp)
/*  f09fdc8:	c7b00118 */ 	lwc1	$f16,0x118($sp)
/*  f09fdcc:	c7b2011c */ 	lwc1	$f18,0x11c($sp)
/*  f09fdd0:	46005207 */ 	neg.s	$f8,$f10
/*  f09fdd4:	46008107 */ 	neg.s	$f4,$f16
/*  f09fdd8:	46009187 */ 	neg.s	$f6,$f18
/*  f09fddc:	e7a801f8 */ 	swc1	$f8,0x1f8($sp)
/*  f09fde0:	e7a401fc */ 	swc1	$f4,0x1fc($sp)
/*  f09fde4:	10000006 */ 	beqz	$zero,.L0f09fe00
/*  f09fde8:	e7a60200 */ 	swc1	$f6,0x200($sp)
/*  f09fdec:	c7a801c0 */ 	lwc1	$f8,0x1c0($sp)
.L0f09fdf0:
/*  f09fdf0:	c7b001c4 */ 	lwc1	$f16,0x1c4($sp)
/*  f09fdf4:	e7aa01f8 */ 	swc1	$f10,0x1f8($sp)
/*  f09fdf8:	e7a801fc */ 	swc1	$f8,0x1fc($sp)
/*  f09fdfc:	e7b00200 */ 	swc1	$f16,0x200($sp)
.L0f09fe00:
/*  f09fe00:	c7ac0260 */ 	lwc1	$f12,0x260($sp)
.L0f09fe04:
/*  f09fe04:	c7a401f8 */ 	lwc1	$f4,0x1f8($sp)
/*  f09fe08:	c7a601fc */ 	lwc1	$f6,0x1fc($sp)
/*  f09fe0c:	c7a80200 */ 	lwc1	$f8,0x200($sp)
/*  f09fe10:	460c2482 */ 	mul.s	$f18,$f4,$f12
/*  f09fe14:	c7ae025c */ 	lwc1	$f14,0x25c($sp)
/*  f09fe18:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f09fe1c:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f09fe20:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f09fe24:	c440004c */ 	lwc1	$f0,0x4c($v0)
/*  f09fe28:	460c4402 */ 	mul.s	$f16,$f8,$f12
/*  f09fe2c:	e7b20250 */ 	swc1	$f18,0x250($sp)
/*  f09fe30:	8fb901d8 */ 	lw	$t9,0x1d8($sp)
/*  f09fe34:	460e2102 */ 	mul.s	$f4,$f4,$f14
/*  f09fe38:	e7aa0254 */ 	swc1	$f10,0x254($sp)
/*  f09fe3c:	46009482 */ 	mul.s	$f18,$f18,$f0
/*  f09fe40:	e7b00258 */ 	swc1	$f16,0x258($sp)
/*  f09fe44:	46122100 */ 	add.s	$f4,$f4,$f18
/*  f09fe48:	460e3482 */ 	mul.s	$f18,$f6,$f14
/*  f09fe4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09fe50:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f09fe54:	e7a40264 */ 	swc1	$f4,0x264($sp)
/*  f09fe58:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f09fe5c:	460e4482 */ 	mul.s	$f18,$f8,$f14
/*  f09fe60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09fe64:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f09fe68:	e7aa0268 */ 	swc1	$f10,0x268($sp)
/*  f09fe6c:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f09fe70:	e7aa026c */ 	swc1	$f10,0x26c($sp)
/*  f09fe74:	8f280010 */ 	lw	$t0,0x10($t9)
/*  f09fe78:	31090800 */ 	andi	$t1,$t0,0x800
/*  f09fe7c:	15200021 */ 	bnez	$t1,.L0f09ff04
/*  f09fe80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09fe84:	8c4a0034 */ 	lw	$t2,0x34($v0)
/*  f09fe88:	8fa401f4 */ 	lw	$a0,0x1f4($sp)
/*  f09fe8c:	8fa501f0 */ 	lw	$a1,0x1f0($sp)
/*  f09fe90:	5940001d */ 	blezl	$t2,.L0f09ff08
/*  f09fe94:	8c4b0284 */ 	lw	$t3,0x284($v0)
/*  f09fe98:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f09fe9c:	c4b00000 */ 	lwc1	$f16,0x0($a1)
/*  f09fea0:	8fa601ec */ 	lw	$a2,0x1ec($sp)
/*  f09fea4:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f09fea8:	c4c60000 */ 	lwc1	$f6,0x0($a2)
/*  f09feac:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f09feb0:	46005203 */ 	div.s	$f8,$f10,$f0
/*  f09feb4:	46082400 */ 	add.s	$f16,$f4,$f8
/*  f09feb8:	e7b00264 */ 	swc1	$f16,0x264($sp)
/*  f09febc:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f09fec0:	c492000c */ 	lwc1	$f18,0xc($a0)
/*  f09fec4:	c4c40004 */ 	lwc1	$f4,0x4($a2)
/*  f09fec8:	46069281 */ 	sub.s	$f10,$f18,$f6
/*  f09fecc:	c7b20268 */ 	lwc1	$f18,0x268($sp)
/*  f09fed0:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f09fed4:	46004403 */ 	div.s	$f16,$f8,$f0
/*  f09fed8:	46109180 */ 	add.s	$f6,$f18,$f16
/*  f09fedc:	e7a60268 */ 	swc1	$f6,0x268($sp)
/*  f09fee0:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f09fee4:	c48a0010 */ 	lwc1	$f10,0x10($a0)
/*  f09fee8:	c4d20008 */ 	lwc1	$f18,0x8($a2)
/*  f09feec:	46045201 */ 	sub.s	$f8,$f10,$f4
/*  f09fef0:	c7aa026c */ 	lwc1	$f10,0x26c($sp)
/*  f09fef4:	46124400 */ 	add.s	$f16,$f8,$f18
/*  f09fef8:	46008183 */ 	div.s	$f6,$f16,$f0
/*  f09fefc:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f09ff00:	e7a4026c */ 	swc1	$f4,0x26c($sp)
.L0f09ff04:
/*  f09ff04:	8c4b0284 */ 	lw	$t3,0x284($v0)
.L0f09ff08:
/*  f09ff08:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f09ff0c:	27a50210 */ 	addiu	$a1,$sp,0x210
/*  f09ff10:	016c2021 */ 	addu	$a0,$t3,$t4
/*  f09ff14:	0c005746 */ 	jal	func00015d18
/*  f09ff18:	2484092c */ 	addiu	$a0,$a0,0x92c
/*  f09ff1c:	44801000 */ 	mtc1	$zero,$f2
/*  f09ff20:	8fa702b0 */ 	lw	$a3,0x2b0($sp)
/*  f09ff24:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f09ff28:	e7a20240 */ 	swc1	$f2,0x240($sp)
/*  f09ff2c:	e7a20244 */ 	swc1	$f2,0x244($sp)
/*  f09ff30:	e7a20248 */ 	swc1	$f2,0x248($sp)
/*  f09ff34:	8ce20218 */ 	lw	$v0,0x218($a3)
/*  f09ff38:	3c01fdff */ 	lui	$at,0xfdff
/*  f09ff3c:	50400015 */ 	beqzl	$v0,.L0f09ff94
/*  f09ff40:	90e20000 */ 	lbu	$v0,0x0($a3)
/*  f09ff44:	aced021c */ 	sw	$t5,0x21c($a3)
/*  f09ff48:	8c4e000c */ 	lw	$t6,0xc($v0)
/*  f09ff4c:	3421ffff */ 	ori	$at,$at,0xffff
/*  f09ff50:	8c580008 */ 	lw	$t8,0x8($v0)
/*  f09ff54:	01c17824 */ 	and	$t7,$t6,$at
/*  f09ff58:	3c01ff7f */ 	lui	$at,0xff7f
/*  f09ff5c:	3421ffff */ 	ori	$at,$at,0xffff
/*  f09ff60:	0301c824 */ 	and	$t9,$t8,$at
/*  f09ff64:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f09ff68:	ac590008 */ 	sw	$t9,0x8($v0)
/*  f09ff6c:	8fa801d8 */ 	lw	$t0,0x1d8($sp)
/*  f09ff70:	00408025 */ 	or	$s0,$v0,$zero
/*  f09ff74:	240b0054 */ 	addiu	$t3,$zero,0x54
/*  f09ff78:	8d090010 */ 	lw	$t1,0x10($t0)
/*  f09ff7c:	00095040 */ 	sll	$t2,$t1,0x1
/*  f09ff80:	05410051 */ 	bgez	$t2,.L0f0a00c8
/*  f09ff84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ff88:	1000004f */ 	beqz	$zero,.L0f0a00c8
/*  f09ff8c:	a04b005c */ 	sb	$t3,0x5c($v0)
/*  f09ff90:	90e20000 */ 	lbu	$v0,0x0($a3)
.L0f09ff94:
/*  f09ff94:	24010018 */ 	addiu	$at,$zero,0x18
/*  f09ff98:	8fac01d8 */ 	lw	$t4,0x1d8($sp)
/*  f09ff9c:	10410004 */ 	beq	$v0,$at,.L0f09ffb0
/*  f09ffa0:	3c18800a */ 	lui	$t8,0x800a
/*  f09ffa4:	24010019 */ 	addiu	$at,$zero,0x19
/*  f09ffa8:	54410010 */ 	bnel	$v0,$at,.L0f09ffec
/*  f09ffac:	2401001b */ 	addiu	$at,$zero,0x1b
.L0f09ffb0:
/*  f09ffb0:	8d8d0010 */ 	lw	$t5,0x10($t4)
/*  f09ffb4:	24050053 */ 	addiu	$a1,$zero,0x53
/*  f09ffb8:	000d7040 */ 	sll	$t6,$t5,0x1
/*  f09ffbc:	05c10002 */ 	bgez	$t6,.L0f09ffc8
/*  f09ffc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09ffc4:	24050054 */ 	addiu	$a1,$zero,0x54
.L0f09ffc8:
/*  f09ffc8:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f09ffcc:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f09ffd0:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f09ffd4:	8de40040 */ 	lw	$a0,0x40($t7)
/*  f09ffd8:	0fc22e20 */ 	jal	func0f08b880
/*  f09ffdc:	8f260004 */ 	lw	$a2,0x4($t9)
/*  f09ffe0:	10000039 */ 	beqz	$zero,.L0f0a00c8
/*  f09ffe4:	00408025 */ 	or	$s0,$v0,$zero
/*  f09ffe8:	2401001b */ 	addiu	$at,$zero,0x1b
.L0f09ffec:
/*  f09ffec:	1441000e */ 	bne	$v0,$at,.L0f0a0028
/*  f09fff0:	3c09800a */ 	lui	$t1,0x800a
/*  f09fff4:	8d29a244 */ 	lw	$t1,-0x5dbc($t1)
/*  f09fff8:	8fa801d8 */ 	lw	$t0,0x1d8($sp)
/*  f09fffc:	24050056 */ 	addiu	$a1,$zero,0x56
/*  f0a0000:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0a0004:	8d040040 */ 	lw	$a0,0x40($t0)
/*  f0a0008:	0fc22e20 */ 	jal	func0f08b880
/*  f0a000c:	8d460004 */ 	lw	$a2,0x4($t2)
/*  f0a0010:	1040002d */ 	beqz	$v0,.L0f0a00c8
/*  f0a0014:	00408025 */ 	or	$s0,$v0,$zero
/*  f0a0018:	8fab02b0 */ 	lw	$t3,0x2b0($sp)
/*  f0a001c:	916c0003 */ 	lbu	$t4,0x3($t3)
/*  f0a0020:	10000029 */ 	beqz	$zero,.L0f0a00c8
/*  f0a0024:	a04c005f */ 	sb	$t4,0x5f($v0)
.L0f0a0028:
/*  f0a0028:	24010017 */ 	addiu	$at,$zero,0x17
/*  f0a002c:	1441000e */ 	bne	$v0,$at,.L0f0a0068
/*  f0a0030:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a0034:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a0038:	8fad01d8 */ 	lw	$t5,0x1d8($sp)
/*  f0a003c:	24050055 */ 	addiu	$a1,$zero,0x55
/*  f0a0040:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f0a0044:	8da40040 */ 	lw	$a0,0x40($t5)
/*  f0a0048:	0fc22e20 */ 	jal	func0f08b880
/*  f0a004c:	8de60004 */ 	lw	$a2,0x4($t7)
/*  f0a0050:	1040001d */ 	beqz	$v0,.L0f0a00c8
/*  f0a0054:	00408025 */ 	or	$s0,$v0,$zero
/*  f0a0058:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f0a005c:	93190003 */ 	lbu	$t9,0x3($t8)
/*  f0a0060:	10000019 */ 	beqz	$zero,.L0f0a00c8
/*  f0a0064:	a059005f */ 	sb	$t9,0x5f($v0)
.L0f0a0068:
/*  f0a0068:	24010012 */ 	addiu	$at,$zero,0x12
/*  f0a006c:	1441000e */ 	bne	$v0,$at,.L0f0a00a8
/*  f0a0070:	3c0d800a */ 	lui	$t5,0x800a
/*  f0a0074:	3c09800a */ 	lui	$t1,0x800a
/*  f0a0078:	8d29a244 */ 	lw	$t1,-0x5dbc($t1)
/*  f0a007c:	8fa801d8 */ 	lw	$t0,0x1d8($sp)
/*  f0a0080:	24050055 */ 	addiu	$a1,$zero,0x55
/*  f0a0084:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0a0088:	8d040040 */ 	lw	$a0,0x40($t0)
/*  f0a008c:	0fc22e20 */ 	jal	func0f08b880
/*  f0a0090:	8d460004 */ 	lw	$a2,0x4($t2)
/*  f0a0094:	1040000c */ 	beqz	$v0,.L0f0a00c8
/*  f0a0098:	00408025 */ 	or	$s0,$v0,$zero
/*  f0a009c:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f0a00a0:	10000009 */ 	beqz	$zero,.L0f0a00c8
/*  f0a00a4:	a04b005f */ 	sb	$t3,0x5f($v0)
.L0f0a00a8:
/*  f0a00a8:	8dada244 */ 	lw	$t5,-0x5dbc($t5)
/*  f0a00ac:	8fac01d8 */ 	lw	$t4,0x1d8($sp)
/*  f0a00b0:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0a00b4:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f0a00b8:	8d840040 */ 	lw	$a0,0x40($t4)
/*  f0a00bc:	0fc22d96 */ 	jal	func0f08b658
/*  f0a00c0:	8dc60004 */ 	lw	$a2,0x4($t6)
/*  f0a00c4:	00408025 */ 	or	$s0,$v0,$zero
.L0f0a00c8:
/*  f0a00c8:	520000ae */ 	beqzl	$s0,.L0f0a0384
/*  f0a00cc:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0a00d0:	afa000b8 */ 	sw	$zero,0xb8($sp)
/*  f0a00d4:	8e060018 */ 	lw	$a2,0x18($s0)
/*  f0a00d8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0a00dc:	50c00097 */ 	beqzl	$a2,.L0f0a033c
/*  f0a00e0:	afb800b8 */ 	sw	$t8,0xb8($sp)
/*  f0a00e4:	8ccf0008 */ 	lw	$t7,0x8($a2)
/*  f0a00e8:	3c0c800a */ 	lui	$t4,0x800a
/*  f0a00ec:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a00f0:	11e00091 */ 	beqz	$t7,.L0f0a0338
/*  f0a00f4:	27a501e0 */ 	addiu	$a1,$sp,0x1e0
/*  f0a00f8:	8fb801d8 */ 	lw	$t8,0x1d8($sp)
/*  f0a00fc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0a0100:	27a60210 */ 	addiu	$a2,$sp,0x210
/*  f0a0104:	8f190058 */ 	lw	$t9,0x58($t8)
/*  f0a0108:	a6190062 */ 	sh	$t9,0x62($s0)
/*  f0a010c:	86020062 */ 	lh	$v0,0x62($s0)
/*  f0a0110:	10410002 */ 	beq	$v0,$at,.L0f0a011c
/*  f0a0114:	00024080 */ 	sll	$t0,$v0,0x2
/*  f0a0118:	a6080062 */ 	sh	$t0,0x62($s0)
.L0f0a011c:
/*  f0a011c:	8e090040 */ 	lw	$t1,0x40($s0)
/*  f0a0120:	3c010fff */ 	lui	$at,0xfff
/*  f0a0124:	3421ffff */ 	ori	$at,$at,0xffff
/*  f0a0128:	01215024 */ 	and	$t2,$t1,$at
/*  f0a012c:	ae0a0040 */ 	sw	$t2,0x40($s0)
/*  f0a0130:	8d8ca24c */ 	lw	$t4,-0x5db4($t4)
/*  f0a0134:	27af0270 */ 	addiu	$t7,$sp,0x270
/*  f0a0138:	27a70264 */ 	addiu	$a3,$sp,0x264
/*  f0a013c:	000c6f00 */ 	sll	$t5,$t4,0x1c
/*  f0a0140:	014d7025 */ 	or	$t6,$t2,$t5
/*  f0a0144:	ae0e0040 */ 	sw	$t6,0x40($s0)
/*  f0a0148:	0fc27b4b */ 	jal	func0f09ed2c
/*  f0a014c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0a0150:	8e180040 */ 	lw	$t8,0x40($s0)
/*  f0a0154:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f0a0158:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a015c:	33190080 */ 	andi	$t9,$t8,0x80
/*  f0a0160:	13200073 */ 	beqz	$t9,.L0f0a0330
/*  f0a0164:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0a0168:	8c620010 */ 	lw	$v0,0x10($v1)
/*  f0a016c:	00024000 */ 	sll	$t0,$v0,0x0
/*  f0a0170:	05010007 */ 	bgez	$t0,.L0f0a0190
/*  f0a0174:	00026100 */ 	sll	$t4,$v0,0x4
/*  f0a0178:	8e050048 */ 	lw	$a1,0x48($s0)
/*  f0a017c:	3c014000 */ 	lui	$at,0x4000
/*  f0a0180:	8ca90000 */ 	lw	$t1,0x0($a1)
/*  f0a0184:	01215025 */ 	or	$t2,$t1,$at
/*  f0a0188:	10000007 */ 	beqz	$zero,.L0f0a01a8
/*  f0a018c:	acaa0000 */ 	sw	$t2,0x0($a1)
.L0f0a0190:
/*  f0a0190:	05810005 */ 	bgez	$t4,.L0f0a01a8
/*  f0a0194:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0198:	8e050048 */ 	lw	$a1,0x48($s0)
/*  f0a019c:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f0a01a0:	356d0010 */ 	ori	$t5,$t3,0x10
/*  f0a01a4:	acad0000 */ 	sw	$t5,0x0($a1)
.L0f0a01a8:
/*  f0a01a8:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a01ac:	8e180048 */ 	lw	$t8,0x48($s0)
/*  f0a01b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a01b4:	8dcf1630 */ 	lw	$t7,0x1630($t6)
/*  f0a01b8:	44814000 */ 	mtc1	$at,$f8
/*  f0a01bc:	af0f00e8 */ 	sw	$t7,0xe8($t8)
/*  f0a01c0:	c4600048 */ 	lwc1	$f0,0x48($v1)
/*  f0a01c4:	46004032 */ 	c.eq.s	$f8,$f0
/*  f0a01c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a01cc:	45030012 */ 	bc1tl	.L0f0a0218
/*  f0a01d0:	8e090048 */ 	lw	$t1,0x48($s0)
/*  f0a01d4:	8e060018 */ 	lw	$a2,0x18($s0)
/*  f0a01d8:	2604001c */ 	addiu	$a0,$s0,0x1c
/*  f0a01dc:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0a01e0:	c4d20014 */ 	lwc1	$f18,0x14($a2)
/*  f0a01e4:	46009402 */ 	mul.s	$f16,$f18,$f0
/*  f0a01e8:	e4d00014 */ 	swc1	$f16,0x14($a2)
/*  f0a01ec:	0c005755 */ 	jal	func00015d54
/*  f0a01f0:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f0a01f4:	8fb901d8 */ 	lw	$t9,0x1d8($sp)
/*  f0a01f8:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0a01fc:	0c0057c1 */ 	jal	func00015f04
/*  f0a0200:	c72c0048 */ 	lwc1	$f12,0x48($t9)
/*  f0a0204:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f0a0208:	0c005768 */ 	jal	func00015da0
/*  f0a020c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0a0210:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f0a0214:	8e090048 */ 	lw	$t1,0x48($s0)
.L0f0a0218:
/*  f0a0218:	240804b0 */ 	addiu	$t0,$zero,0x4b0
/*  f0a021c:	240f00f0 */ 	addiu	$t7,$zero,0xf0
/*  f0a0220:	a52800b2 */ 	sh	$t0,0xb2($t1)
/*  f0a0224:	8e0a0014 */ 	lw	$t2,0x14($s0)
/*  f0a0228:	8e0c0048 */ 	lw	$t4,0x48($s0)
/*  f0a022c:	3c017f1b */ 	lui	$at,%hi(var7f1ac740)
/*  f0a0230:	c54a000c */ 	lwc1	$f10,0xc($t2)
/*  f0a0234:	240affff */ 	addiu	$t2,$zero,-1
/*  f0a0238:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0a023c:	e58a00a8 */ 	swc1	$f10,0xa8($t4)
/*  f0a0240:	8e050048 */ 	lw	$a1,0x48($s0)
/*  f0a0244:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a0248:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a024c:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*  f0a0250:	e4a600ac */ 	swc1	$f6,0xac($a1)
/*  f0a0254:	8e0b0048 */ 	lw	$t3,0x48($s0)
/*  f0a0258:	c7a40250 */ 	lwc1	$f4,0x250($sp)
/*  f0a025c:	e5640010 */ 	swc1	$f4,0x10($t3)
/*  f0a0260:	8e0d0048 */ 	lw	$t5,0x48($s0)
/*  f0a0264:	c7a80254 */ 	lwc1	$f8,0x254($sp)
/*  f0a0268:	e5a80014 */ 	swc1	$f8,0x14($t5)
/*  f0a026c:	8e0e0048 */ 	lw	$t6,0x48($s0)
/*  f0a0270:	c7b20258 */ 	lwc1	$f18,0x258($sp)
/*  f0a0274:	e5d20018 */ 	swc1	$f18,0x18($t6)
/*  f0a0278:	8e180048 */ 	lw	$t8,0x48($s0)
/*  f0a027c:	af0f00b4 */ 	sw	$t7,0xb4($t8)
/*  f0a0280:	8e190048 */ 	lw	$t9,0x48($s0)
/*  f0a0284:	c470005c */ 	lwc1	$f16,0x5c($v1)
/*  f0a0288:	e730008c */ 	swc1	$f16,0x8c($t9)
/*  f0a028c:	c426c740 */ 	lwc1	$f6,%lo(var7f1ac740)($at)
/*  f0a0290:	c46a0050 */ 	lwc1	$f10,0x50($v1)
/*  f0a0294:	8e080048 */ 	lw	$t0,0x48($s0)
/*  f0a0298:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a029c:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f0a02a0:	e5040098 */ 	swc1	$f4,0x98($t0)
/*  f0a02a4:	84660060 */ 	lh	$a2,0x60($v1)
/*  f0a02a8:	58c00011 */ 	blezl	$a2,.L0f0a02f0
/*  f0a02ac:	8c6c0010 */ 	lw	$t4,0x10($v1)
/*  f0a02b0:	8e050014 */ 	lw	$a1,0x14($s0)
/*  f0a02b4:	44810000 */ 	mtc1	$at,$f0
/*  f0a02b8:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f0a02bc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0a02c0:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0a02c4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0a02c8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0a02cc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0a02d0:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0a02d4:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0a02d8:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0a02dc:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0a02e0:	0fc24e7e */ 	jal	func0f0939f8
/*  f0a02e4:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0a02e8:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f0a02ec:	8c6c0010 */ 	lw	$t4,0x10($v1)
.L0f0a02f0:
/*  f0a02f0:	318b0800 */ 	andi	$t3,$t4,0x800
/*  f0a02f4:	51600004 */ 	beqzl	$t3,.L0f0a0308
/*  f0a02f8:	8e050048 */ 	lw	$a1,0x48($s0)
/*  f0a02fc:	0fc2f52a */ 	jal	func0f0bd4a8
/*  f0a0300:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a0304:	8e050048 */ 	lw	$a1,0x48($s0)
.L0f0a0308:
/*  f0a0308:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a030c:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f0a0310:	8cad0000 */ 	lw	$t5,0x0($a1)
/*  f0a0314:	31ae0080 */ 	andi	$t6,$t5,0x80
/*  f0a0318:	51c00009 */ 	beqzl	$t6,.L0f0a0340
/*  f0a031c:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f0a0320:	0fc1ceba */ 	jal	func0f073ae8
/*  f0a0324:	27a70060 */ 	addiu	$a3,$sp,0x60
/*  f0a0328:	10000005 */ 	beqz	$zero,.L0f0a0340
/*  f0a032c:	8fb900b8 */ 	lw	$t9,0xb8($sp)
.L0f0a0330:
/*  f0a0330:	10000002 */ 	beqz	$zero,.L0f0a033c
/*  f0a0334:	afaf00b8 */ 	sw	$t7,0xb8($sp)
.L0f0a0338:
/*  f0a0338:	afb800b8 */ 	sw	$t8,0xb8($sp)
.L0f0a033c:
/*  f0a033c:	8fb900b8 */ 	lw	$t9,0xb8($sp)
.L0f0a0340:
/*  f0a0340:	53200010 */ 	beqzl	$t9,.L0f0a0384
/*  f0a0344:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0a0348:	8e040014 */ 	lw	$a0,0x14($s0)
/*  f0a034c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0a0350:	a6080062 */ 	sh	$t0,0x62($s0)
/*  f0a0354:	50800004 */ 	beqzl	$a0,.L0f0a0368
/*  f0a0358:	8e060018 */ 	lw	$a2,0x18($s0)
/*  f0a035c:	0fc1810e */ 	jal	func0f060438
/*  f0a0360:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0364:	8e060018 */ 	lw	$a2,0x18($s0)
.L0f0a0368:
/*  f0a0368:	50c00004 */ 	beqzl	$a2,.L0f0a037c
/*  f0a036c:	ae000014 */ 	sw	$zero,0x14($s0)
/*  f0a0370:	0fc2cc33 */ 	jal	func0f0b30cc
/*  f0a0374:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0a0378:	ae000014 */ 	sw	$zero,0x14($s0)
.L0f0a037c:
/*  f0a037c:	ae000018 */ 	sw	$zero,0x18($s0)
.L0f0a0380:
/*  f0a0380:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f0a0384:
/*  f0a0384:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0a0388:	27bd02b8 */ 	addiu	$sp,$sp,0x2b8
/*  f0a038c:	03e00008 */ 	jr	$ra
/*  f0a0390:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a0394
/*  f0a0394:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f0a0398:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f0a039c:	4486b000 */ 	mtc1	$a2,$f22
/*  f0a03a0:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f0a03a4:	afb70060 */ 	sw	$s7,0x60($sp)
/*  f0a03a8:	afb6005c */ 	sw	$s6,0x5c($sp)
/*  f0a03ac:	afb50058 */ 	sw	$s5,0x58($sp)
/*  f0a03b0:	afb40054 */ 	sw	$s4,0x54($sp)
/*  f0a03b4:	afb30050 */ 	sw	$s3,0x50($sp)
/*  f0a03b8:	afb2004c */ 	sw	$s2,0x4c($sp)
/*  f0a03bc:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f0a03c0:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f0a03c4:	f7be0038 */ 	sdc1	$f30,0x38($sp)
/*  f0a03c8:	f7bc0030 */ 	sdc1	$f28,0x30($sp)
/*  f0a03cc:	f7ba0028 */ 	sdc1	$f26,0x28($sp)
/*  f0a03d0:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f0a03d4:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f0a03d8:	e7ac00e0 */ 	swc1	$f12,0xe0($sp)
/*  f0a03dc:	e7ae00e4 */ 	swc1	$f14,0xe4($sp)
/*  f0a03e0:	0fc2d5f6 */ 	jal	func0f0b57d8
/*  f0a03e4:	afa700ec */ 	sw	$a3,0xec($sp)
/*  f0a03e8:	0fc2d5fa */ 	jal	func0f0b57e8
/*  f0a03ec:	46000706 */ 	mov.s	$f28,$f0
/*  f0a03f0:	3c0f8007 */ 	lui	$t7,%hi(var800701b8)
/*  f0a03f4:	25ef01b8 */ 	addiu	$t7,$t7,%lo(var800701b8)
/*  f0a03f8:	3c17800a */ 	lui	$s7,%hi(g_Vars)
/*  f0a03fc:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0a0400:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f0a0404:	26f79fc0 */ 	addiu	$s7,$s7,%lo(g_Vars)
/*  f0a0408:	8ef50284 */ 	lw	$s5,0x284($s7)
/*  f0a040c:	27ae00a8 */ 	addiu	$t6,$sp,0xa8
/*  f0a0410:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0a0414:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f0a0418:	c7a400e0 */ 	lwc1	$f4,0xe0($sp)
/*  f0a041c:	c7a600e4 */ 	lwc1	$f6,0xe4($sp)
/*  f0a0420:	46000786 */ 	mov.s	$f30,$f0
/*  f0a0424:	e7a400bc */ 	swc1	$f4,0xbc($sp)
/*  f0a0428:	e7a400b8 */ 	swc1	$f4,0xb8($sp)
/*  f0a042c:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*  f0a0430:	e7a600b0 */ 	swc1	$f6,0xb0($sp)
/*  f0a0434:	82a20de4 */ 	lb	$v0,0xde4($s5)
/*  f0a0438:	2c490001 */ 	sltiu	$t1,$v0,0x1
/*  f0a043c:	afa900ac */ 	sw	$t1,0xac($sp)
/*  f0a0440:	82a20640 */ 	lb	$v0,0x640($s5)
/*  f0a0444:	2c4a0001 */ 	sltiu	$t2,$v0,0x1
/*  f0a0448:	afaa00a8 */ 	sw	$t2,0xa8($sp)
/*  f0a044c:	82ab0de4 */ 	lb	$t3,0xde4($s5)
/*  f0a0450:	55600020 */ 	bnezl	$t3,.L0f0a04d4
/*  f0a0454:	92a80ddc */ 	lbu	$t0,0xddc($s5)
/*  f0a0458:	8eac0c3c */ 	lw	$t4,0xc3c($s5)
/*  f0a045c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a0460:	5581001c */ 	bnel	$t4,$at,.L0f0a04d4
/*  f0a0464:	92a80ddc */ 	lbu	$t0,0xddc($s5)
/*  f0a0468:	8ead0ce8 */ 	lw	$t5,0xce8($s5)
/*  f0a046c:	51a00019 */ 	beqzl	$t5,.L0f0a04d4
/*  f0a0470:	92a80ddc */ 	lbu	$t0,0xddc($s5)
/*  f0a0474:	92b90638 */ 	lbu	$t9,0x638($s5)
/*  f0a0478:	2401001b */ 	addiu	$at,$zero,0x1b
/*  f0a047c:	24100019 */ 	addiu	$s0,$zero,0x19
/*  f0a0480:	17210002 */ 	bne	$t9,$at,.L0f0a048c
/*  f0a0484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0488:	24100005 */ 	addiu	$s0,$zero,0x5
.L0f0a048c:
/*  f0a048c:	0fc26057 */ 	jal	func0f09815c
/*  f0a0490:	26a40638 */ 	addiu	$a0,$s5,0x638
/*  f0a0494:	46000506 */ 	mov.s	$f20,$f0
/*  f0a0498:	0c007486 */ 	jal	func0001d218
/*  f0a049c:	26a409bc */ 	addiu	$a0,$s5,0x9bc
/*  f0a04a0:	4600a20d */ 	trunc.w.s	$f8,$f20
/*  f0a04a4:	00507823 */ 	subu	$t7,$v0,$s0
/*  f0a04a8:	440e4000 */ 	mfc1	$t6,$f8
/*  f0a04ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a04b0:	01cf082a */ 	slt	$at,$t6,$t7
/*  f0a04b4:	50200007 */ 	beqzl	$at,.L0f0a04d4
/*  f0a04b8:	92a80ddc */ 	lbu	$t0,0xddc($s5)
/*  f0a04bc:	44800000 */ 	mtc1	$zero,$f0
/*  f0a04c0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a04c4:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f0a04c8:	e7a000b8 */ 	swc1	$f0,0xb8($sp)
/*  f0a04cc:	e7a000b0 */ 	swc1	$f0,0xb0($sp)
/*  f0a04d0:	92a80ddc */ 	lbu	$t0,0xddc($s5)
.L0f0a04d4:
/*  f0a04d4:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0a04d8:	8ee20284 */ 	lw	$v0,0x284($s7)
/*  f0a04dc:	15010012 */ 	bne	$t0,$at,.L0f0a0528
/*  f0a04e0:	00009825 */ 	or	$s3,$zero,$zero
/*  f0a04e4:	3c017f1b */ 	lui	$at,%hi(var7f1ac744)
/*  f0a04e8:	c432c744 */ 	lwc1	$f18,%lo(var7f1ac744)($at)
/*  f0a04ec:	c44a0148 */ 	lwc1	$f10,0x148($v0)
/*  f0a04f0:	c44601b4 */ 	lwc1	$f6,0x1b4($v0)
/*  f0a04f4:	3c017f1b */ 	lui	$at,%hi(var7f1ac748)
/*  f0a04f8:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0a04fc:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0a0500:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0a0504:	c424c748 */ 	lwc1	$f4,%lo(var7f1ac748)($at)
/*  f0a0508:	e7a800bc */ 	swc1	$f8,0xbc($sp)
/*  f0a050c:	c44a015c */ 	lwc1	$f10,0x15c($v0)
/*  f0a0510:	c44801b8 */ 	lwc1	$f8,0x1b8($v0)
/*  f0a0514:	afa900ac */ 	sw	$t1,0xac($sp)
/*  f0a0518:	46005487 */ 	neg.s	$f18,$f10
/*  f0a051c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0a0520:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0a0524:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
.L0f0a0528:
/*  f0a0528:	92aa0638 */ 	lbu	$t2,0x638($s5)
/*  f0a052c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a0530:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a0534:	15410011 */ 	bne	$t2,$at,.L0f0a057c
/*  f0a0538:	3c017f1b */ 	lui	$at,%hi(var7f1ac74c)
/*  f0a053c:	c424c74c */ 	lwc1	$f4,%lo(var7f1ac74c)($at)
/*  f0a0540:	c4520148 */ 	lwc1	$f18,0x148($v0)
/*  f0a0544:	c44801b4 */ 	lwc1	$f8,0x1b4($v0)
/*  f0a0548:	3c017f1b */ 	lui	$at,%hi(var7f1ac750)
/*  f0a054c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0a0550:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0a0554:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0a0558:	c426c750 */ 	lwc1	$f6,%lo(var7f1ac750)($at)
/*  f0a055c:	e7aa00b8 */ 	swc1	$f10,0xb8($sp)
/*  f0a0560:	c452015c */ 	lwc1	$f18,0x15c($v0)
/*  f0a0564:	c44a01b8 */ 	lwc1	$f10,0x1b8($v0)
/*  f0a0568:	afab00a8 */ 	sw	$t3,0xa8($sp)
/*  f0a056c:	46009107 */ 	neg.s	$f4,$f18
/*  f0a0570:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0a0574:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f0a0578:	e7b200b0 */ 	swc1	$f18,0xb0($sp)
.L0f0a057c:
/*  f0a057c:	904c1bfc */ 	lbu	$t4,0x1bfc($v0)
/*  f0a0580:	3c017f1b */ 	lui	$at,%hi(var7f1ac754)
/*  f0a0584:	11800003 */ 	beqz	$t4,.L0f0a0594
/*  f0a0588:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a058c:	afa200ac */ 	sw	$v0,0xac($sp)
/*  f0a0590:	afa200a8 */ 	sw	$v0,0xa8($sp)
.L0f0a0594:
/*  f0a0594:	c43ac754 */ 	lwc1	$f26,%lo(var7f1ac754)($at)
/*  f0a0598:	3c017f1b */ 	lui	$at,%hi(var7f1ac758)
/*  f0a059c:	c438c758 */ 	lwc1	$f24,%lo(var7f1ac758)($at)
/*  f0a05a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a05a4:	4481a000 */ 	mtc1	$at,$f20
/*  f0a05a8:	27b600a8 */ 	addiu	$s6,$sp,0xa8
.L0f0a05ac:
/*  f0a05ac:	8ecd0000 */ 	lw	$t5,0x0($s6)
/*  f0a05b0:	0013c900 */ 	sll	$t9,$s3,0x4
/*  f0a05b4:	0333c823 */ 	subu	$t9,$t9,$s3
/*  f0a05b8:	15a00040 */ 	bnez	$t5,.L0f0a06bc
/*  f0a05bc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0a05c0:	0333c821 */ 	addu	$t9,$t9,$s3
/*  f0a05c4:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0a05c8:	0333c821 */ 	addu	$t9,$t9,$s3
/*  f0a05cc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0a05d0:	02b98821 */ 	addu	$s1,$s5,$t9
/*  f0a05d4:	8e380cec */ 	lw	$t8,0xcec($s1)
/*  f0a05d8:	53000039 */ 	beqzl	$t8,.L0f0a06c0
/*  f0a05dc:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0a05e0:	8eee0314 */ 	lw	$t6,0x314($s7)
/*  f0a05e4:	26220638 */ 	addiu	$v0,$s1,0x638
/*  f0a05e8:	55c00035 */ 	bnezl	$t6,.L0f0a06c0
/*  f0a05ec:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0a05f0:	c44406b8 */ 	lwc1	$f4,0x6b8($v0)
/*  f0a05f4:	e7a40094 */ 	swc1	$f4,0x94($sp)
/*  f0a05f8:	c44606bc */ 	lwc1	$f6,0x6bc($v0)
/*  f0a05fc:	e7a60098 */ 	swc1	$f6,0x98($sp)
/*  f0a0600:	c44806c0 */ 	lwc1	$f8,0x6c0($v0)
/*  f0a0604:	0fc2d5be */ 	jal	func0f0b56f8
/*  f0a0608:	e7a8009c */ 	swc1	$f8,0x9c($sp)
/*  f0a060c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a0610:	0c0056d9 */ 	jal	func00015b64
/*  f0a0614:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0a0618:	c7a0009c */ 	lwc1	$f0,0x9c($sp)
/*  f0a061c:	3c017f1b */ 	lui	$at,%hi(var7f1ac75c)
/*  f0a0620:	4618003c */ 	c.lt.s	$f0,$f24
/*  f0a0624:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0628:	45000005 */ 	bc1f	.L0f0a0640
/*  f0a062c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0630:	4600d03c */ 	c.lt.s	$f26,$f0
/*  f0a0634:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0638:	45030021 */ 	bc1tl	.L0f0a06c0
/*  f0a063c:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f0a0640:
/*  f0a0640:	c42ac75c */ 	lwc1	$f10,%lo(var7f1ac75c)($at)
/*  f0a0644:	27af00b8 */ 	addiu	$t7,$sp,0xb8
/*  f0a0648:	028f8021 */ 	addu	$s0,$s4,$t7
/*  f0a064c:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0a0650:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f0a0654:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0a0658:	27a800b0 */ 	addiu	$t0,$sp,0xb0
/*  f0a065c:	45020018 */ 	bc1fl	.L0f0a06c0
/*  f0a0660:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0a0664:	0fc2d341 */ 	jal	func0f0b4d04
/*  f0a0668:	02889021 */ 	addu	$s2,$s4,$t0
/*  f0a066c:	c7b2008c */ 	lwc1	$f18,0x8c($sp)
/*  f0a0670:	e6120000 */ 	swc1	$f18,0x0($s0)
/*  f0a0674:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*  f0a0678:	0c002f22 */ 	jal	func0000bc88
/*  f0a067c:	e6440000 */ 	swc1	$f4,0x0($s2)
/*  f0a0680:	44824000 */ 	mtc1	$v0,$f8
/*  f0a0684:	c6060000 */ 	lwc1	$f6,0x0($s0)
/*  f0a0688:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0a068c:	460a3003 */ 	div.s	$f0,$f6,$f10
/*  f0a0690:	46000480 */ 	add.s	$f18,$f0,$f0
/*  f0a0694:	46149101 */ 	sub.s	$f4,$f18,$f20
/*  f0a0698:	0c002f26 */ 	jal	func0000bc98
/*  f0a069c:	e6040000 */ 	swc1	$f4,0x0($s0)
/*  f0a06a0:	44823000 */ 	mtc1	$v0,$f6
/*  f0a06a4:	c6480000 */ 	lwc1	$f8,0x0($s2)
/*  f0a06a8:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0a06ac:	460a4003 */ 	div.s	$f0,$f8,$f10
/*  f0a06b0:	46000480 */ 	add.s	$f18,$f0,$f0
/*  f0a06b4:	46149101 */ 	sub.s	$f4,$f18,$f20
/*  f0a06b8:	e6440000 */ 	swc1	$f4,0x0($s2)
.L0f0a06bc:
/*  f0a06bc:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f0a06c0:
/*  f0a06c0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a06c4:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f0a06c8:	1661ffb8 */ 	bne	$s3,$at,.L0f0a05ac
/*  f0a06cc:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f0a06d0:	c6a21670 */ 	lwc1	$f2,0x1670($s5)
/*  f0a06d4:	c6a61660 */ 	lwc1	$f6,0x1660($s5)
/*  f0a06d8:	c6a81664 */ 	lwc1	$f8,0x1664($s5)
/*  f0a06dc:	4602b032 */ 	c.eq.s	$f22,$f2
/*  f0a06e0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a06e4:	e6a61944 */ 	swc1	$f6,0x1944($s5)
/*  f0a06e8:	e6a81948 */ 	swc1	$f8,0x1948($s5)
/*  f0a06ec:	4503000d */ 	bc1tl	.L0f0a0724
/*  f0a06f0:	c7ae00ec */ 	lwc1	$f14,0xec($sp)
/*  f0a06f4:	4602a001 */ 	sub.s	$f0,$f20,$f2
/*  f0a06f8:	c6aa1668 */ 	lwc1	$f10,0x1668($s5)
/*  f0a06fc:	c6a6166c */ 	lwc1	$f6,0x166c($s5)
/*  f0a0700:	4616a301 */ 	sub.s	$f12,$f20,$f22
/*  f0a0704:	46005482 */ 	mul.s	$f18,$f10,$f0
/*  f0a0708:	e6b61670 */ 	swc1	$f22,0x1670($s5)
/*  f0a070c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a0710:	460c9103 */ 	div.s	$f4,$f18,$f12
/*  f0a0714:	460c4283 */ 	div.s	$f10,$f8,$f12
/*  f0a0718:	e6a41668 */ 	swc1	$f4,0x1668($s5)
/*  f0a071c:	e6aa166c */ 	swc1	$f10,0x166c($s5)
/*  f0a0720:	c7ae00ec */ 	lwc1	$f14,0xec($sp)
.L0f0a0724:
/*  f0a0724:	c6a21684 */ 	lwc1	$f2,0x1684($s5)
/*  f0a0728:	4616a301 */ 	sub.s	$f12,$f20,$f22
/*  f0a072c:	46027032 */ 	c.eq.s	$f14,$f2
/*  f0a0730:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0734:	4503000d */ 	bc1tl	.L0f0a076c
/*  f0a0738:	44812000 */ 	mtc1	$at,$f4
/*  f0a073c:	4602a001 */ 	sub.s	$f0,$f20,$f2
/*  f0a0740:	c6b2167c */ 	lwc1	$f18,0x167c($s5)
/*  f0a0744:	c6a81680 */ 	lwc1	$f8,0x1680($s5)
/*  f0a0748:	460ea401 */ 	sub.s	$f16,$f20,$f14
/*  f0a074c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0a0750:	e6ae1684 */ 	swc1	$f14,0x1684($s5)
/*  f0a0754:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0a0758:	46102183 */ 	div.s	$f6,$f4,$f16
/*  f0a075c:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f0a0760:	e6a6167c */ 	swc1	$f6,0x167c($s5)
/*  f0a0764:	e6b21680 */ 	swc1	$f18,0x1680($s5)
/*  f0a0768:	44812000 */ 	mtc1	$at,$f4
.L0f0a076c:
/*  f0a076c:	8ee90034 */ 	lw	$t1,0x34($s7)
/*  f0a0770:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a0774:	460e2181 */ 	sub.s	$f6,$f4,$f14
/*  f0a0778:	19200034 */ 	blez	$t1,.L0f0a084c
/*  f0a077c:	e7a6007c */ 	swc1	$f6,0x7c($sp)
/*  f0a0780:	3c017f1b */ 	lui	$at,%hi(var7f1ac760)
/*  f0a0784:	c420c760 */ 	lwc1	$f0,%lo(var7f1ac760)($at)
/*  f0a0788:	c7ae00e4 */ 	lwc1	$f14,0xe4($sp)
/*  f0a078c:	c7a200e0 */ 	lwc1	$f2,0xe0($sp)
/*  f0a0790:	27a200b8 */ 	addiu	$v0,$sp,0xb8
/*  f0a0794:	c6a81668 */ 	lwc1	$f8,0x1668($s5)
.L0f0a0798:
/*  f0a0798:	c6a4166c */ 	lwc1	$f4,0x166c($s5)
/*  f0a079c:	02a08825 */ 	or	$s1,$s5,$zero
/*  f0a07a0:	46164282 */ 	mul.s	$f10,$f8,$f22
/*  f0a07a4:	27b000b8 */ 	addiu	$s0,$sp,0xb8
/*  f0a07a8:	27b200b0 */ 	addiu	$s2,$sp,0xb0
/*  f0a07ac:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f0a07b0:	46025480 */ 	add.s	$f18,$f10,$f2
/*  f0a07b4:	460e3200 */ 	add.s	$f8,$f6,$f14
/*  f0a07b8:	e6b21668 */ 	swc1	$f18,0x1668($s5)
/*  f0a07bc:	e6a8166c */ 	swc1	$f8,0x166c($s5)
/*  f0a07c0:	c6320cd4 */ 	lwc1	$f18,0xcd4($s1)
/*  f0a07c4:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f0a07c8:	46120682 */ 	mul.s	$f26,$f0,$f18
/*  f0a07cc:	52420010 */ 	beql	$s2,$v0,.L0f0a0810
/*  f0a07d0:	c6180000 */ 	lwc1	$f24,0x0($s0)
.L0f0a07d4:
/*  f0a07d4:	c6180000 */ 	lwc1	$f24,0x0($s0)
/*  f0a07d8:	c6340cd8 */ 	lwc1	$f20,0xcd8($s1)
/*  f0a07dc:	c6321478 */ 	lwc1	$f18,0x1478($s1)
/*  f0a07e0:	461ac600 */ 	add.s	$f24,$f24,$f26
/*  f0a07e4:	46140502 */ 	mul.s	$f20,$f0,$f20
/*  f0a07e8:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f0a07ec:	263107a4 */ 	addiu	$s1,$s1,0x7a4
/*  f0a07f0:	e6380530 */ 	swc1	$f24,0x530($s1)
/*  f0a07f4:	c658fff8 */ 	lwc1	$f24,-0x8($s2)
/*  f0a07f8:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f0a07fc:	4614c500 */ 	add.s	$f20,$f24,$f20
/*  f0a0800:	46120682 */ 	mul.s	$f26,$f0,$f18
/*  f0a0804:	1642fff3 */ 	bne	$s2,$v0,.L0f0a07d4
/*  f0a0808:	e6340534 */ 	swc1	$f20,0x534($s1)
/*  f0a080c:	c6180000 */ 	lwc1	$f24,0x0($s0)
.L0f0a0810:
/*  f0a0810:	c6340cd8 */ 	lwc1	$f20,0xcd8($s1)
/*  f0a0814:	263107a4 */ 	addiu	$s1,$s1,0x7a4
/*  f0a0818:	461ac600 */ 	add.s	$f24,$f24,$f26
/*  f0a081c:	46140502 */ 	mul.s	$f20,$f0,$f20
/*  f0a0820:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f0a0824:	e6380530 */ 	swc1	$f24,0x530($s1)
/*  f0a0828:	c658fffc */ 	lwc1	$f24,-0x4($s2)
/*  f0a082c:	4614c500 */ 	add.s	$f20,$f24,$f20
/*  f0a0830:	e6340534 */ 	swc1	$f20,0x534($s1)
/*  f0a0834:	8eea0034 */ 	lw	$t2,0x34($s7)
/*  f0a0838:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0a083c:	028a082a */ 	slt	$at,$s4,$t2
/*  f0a0840:	5420ffd5 */ 	bnezl	$at,.L0f0a0798
/*  f0a0844:	c6a81668 */ 	lwc1	$f8,0x1668($s5)
/*  f0a0848:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0a084c:
/*  f0a084c:	3c014040 */ 	lui	$at,0x4040
/*  f0a0850:	4481a000 */ 	mtc1	$at,$f20
/*  f0a0854:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a0858:	4481d000 */ 	mtc1	$at,$f26
/*  f0a085c:	c6a61668 */ 	lwc1	$f6,0x1668($s5)
/*  f0a0860:	c6a4166c */ 	lwc1	$f4,0x166c($s5)
/*  f0a0864:	461ae382 */ 	mul.s	$f14,$f28,$f26
/*  f0a0868:	3c014080 */ 	lui	$at,0x4080
/*  f0a086c:	460c3482 */ 	mul.s	$f18,$f6,$f12
/*  f0a0870:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0874:	461c9202 */ 	mul.s	$f8,$f18,$f28
/*  f0a0878:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a087c:	461a4282 */ 	mul.s	$f10,$f8,$f26
/*  f0a0880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0884:	461af402 */ 	mul.s	$f16,$f30,$f26
/*  f0a0888:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a088c:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0a0890:	460e5000 */ 	add.s	$f0,$f10,$f14
/*  f0a0894:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0a0898:	461e3482 */ 	mul.s	$f18,$f6,$f30
/*  f0a089c:	e6a01660 */ 	swc1	$f0,0x1660($s5)
/*  f0a08a0:	461a9202 */ 	mul.s	$f8,$f18,$f26
/*  f0a08a4:	46104280 */ 	add.s	$f10,$f8,$f16
/*  f0a08a8:	45000005 */ 	bc1f	.L0f0a08c0
/*  f0a08ac:	e6aa1664 */ 	swc1	$f10,0x1664($s5)
/*  f0a08b0:	3c014080 */ 	lui	$at,0x4080
/*  f0a08b4:	4481c000 */ 	mtc1	$at,$f24
/*  f0a08b8:	10000009 */ 	beqz	$zero,.L0f0a08e0
/*  f0a08bc:	e6b41660 */ 	swc1	$f20,0x1660($s5)
.L0f0a08c0:
/*  f0a08c0:	4481c000 */ 	mtc1	$at,$f24
/*  f0a08c4:	c6a41660 */ 	lwc1	$f4,0x1660($s5)
/*  f0a08c8:	4618e001 */ 	sub.s	$f0,$f28,$f24
/*  f0a08cc:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0a08d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a08d4:	45020003 */ 	bc1fl	.L0f0a08e4
/*  f0a08d8:	c6a21664 */ 	lwc1	$f2,0x1664($s5)
/*  f0a08dc:	e6a01660 */ 	swc1	$f0,0x1660($s5)
.L0f0a08e0:
/*  f0a08e0:	c6a21664 */ 	lwc1	$f2,0x1664($s5)
.L0f0a08e4:
/*  f0a08e4:	4614103c */ 	c.lt.s	$f2,$f20
/*  f0a08e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a08ec:	45020004 */ 	bc1fl	.L0f0a0900
/*  f0a08f0:	4618f001 */ 	sub.s	$f0,$f30,$f24
/*  f0a08f4:	10000007 */ 	beqz	$zero,.L0f0a0914
/*  f0a08f8:	e6b41664 */ 	swc1	$f20,0x1664($s5)
/*  f0a08fc:	4618f001 */ 	sub.s	$f0,$f30,$f24
.L0f0a0900:
/*  f0a0900:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0a0904:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0908:	45020003 */ 	bc1fl	.L0f0a0918
/*  f0a090c:	e7ae0074 */ 	swc1	$f14,0x74($sp)
/*  f0a0910:	e6a01664 */ 	swc1	$f0,0x1664($s5)
.L0f0a0914:
/*  f0a0914:	e7ae0074 */ 	swc1	$f14,0x74($sp)
.L0f0a0918:
/*  f0a0918:	0fc2d5fe */ 	jal	func0f0b57f8
/*  f0a091c:	e7b00070 */ 	swc1	$f16,0x70($sp)
/*  f0a0920:	c6a61660 */ 	lwc1	$f6,0x1660($s5)
/*  f0a0924:	46003480 */ 	add.s	$f18,$f6,$f0
/*  f0a0928:	0fc2d602 */ 	jal	func0f0b5808
/*  f0a092c:	e6b21660 */ 	swc1	$f18,0x1660($s5)
/*  f0a0930:	c6a81664 */ 	lwc1	$f8,0x1664($s5)
/*  f0a0934:	3c017f1b */ 	lui	$at,%hi(var7f1ac764)
/*  f0a0938:	00009825 */ 	or	$s3,$zero,$zero
/*  f0a093c:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f0a0940:	02a08825 */ 	or	$s1,$s5,$zero
/*  f0a0944:	24100002 */ 	addiu	$s0,$zero,0x2
/*  f0a0948:	e6aa1664 */ 	swc1	$f10,0x1664($s5)
/*  f0a094c:	c436c764 */ 	lwc1	$f22,%lo(var7f1ac764)($at)
.L0f0a0950:
/*  f0a0950:	c6240cd4 */ 	lwc1	$f4,0xcd4($s1)
/*  f0a0954:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f0a0958:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f0a095c:	c6240cd8 */ 	lwc1	$f4,0xcd8($s1)
/*  f0a0960:	461c3482 */ 	mul.s	$f18,$f6,$f28
/*  f0a0964:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0968:	461a9202 */ 	mul.s	$f8,$f18,$f26
/*  f0a096c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0970:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f0a0974:	460a4000 */ 	add.s	$f0,$f8,$f10
/*  f0a0978:	461e3482 */ 	mul.s	$f18,$f6,$f30
/*  f0a097c:	e6200ccc */ 	swc1	$f0,0xccc($s1)
/*  f0a0980:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f0a0984:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0a0988:	461a9202 */ 	mul.s	$f8,$f18,$f26
/*  f0a098c:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0a0990:	45000003 */ 	bc1f	.L0f0a09a0
/*  f0a0994:	e6240cd0 */ 	swc1	$f4,0xcd0($s1)
/*  f0a0998:	10000008 */ 	beqz	$zero,.L0f0a09bc
/*  f0a099c:	e6340ccc */ 	swc1	$f20,0xccc($s1)
.L0f0a09a0:
/*  f0a09a0:	4618e001 */ 	sub.s	$f0,$f28,$f24
/*  f0a09a4:	c6260ccc */ 	lwc1	$f6,0xccc($s1)
/*  f0a09a8:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0a09ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a09b0:	45020003 */ 	bc1fl	.L0f0a09c0
/*  f0a09b4:	c6220cd0 */ 	lwc1	$f2,0xcd0($s1)
/*  f0a09b8:	e6200ccc */ 	swc1	$f0,0xccc($s1)
.L0f0a09bc:
/*  f0a09bc:	c6220cd0 */ 	lwc1	$f2,0xcd0($s1)
.L0f0a09c0:
/*  f0a09c0:	4614103c */ 	c.lt.s	$f2,$f20
/*  f0a09c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a09c8:	45020004 */ 	bc1fl	.L0f0a09dc
/*  f0a09cc:	4618f001 */ 	sub.s	$f0,$f30,$f24
/*  f0a09d0:	10000007 */ 	beqz	$zero,.L0f0a09f0
/*  f0a09d4:	e6340cd0 */ 	swc1	$f20,0xcd0($s1)
/*  f0a09d8:	4618f001 */ 	sub.s	$f0,$f30,$f24
.L0f0a09dc:
/*  f0a09dc:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0a09e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a09e4:	45000002 */ 	bc1f	.L0f0a09f0
/*  f0a09e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a09ec:	e6200cd0 */ 	swc1	$f0,0xcd0($s1)
.L0f0a09f0:
/*  f0a09f0:	0fc2d5fe */ 	jal	func0f0b57f8
/*  f0a09f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a09f8:	c6320ccc */ 	lwc1	$f18,0xccc($s1)
/*  f0a09fc:	46009200 */ 	add.s	$f8,$f18,$f0
/*  f0a0a00:	0fc2d602 */ 	jal	func0f0b5808
/*  f0a0a04:	e6280ccc */ 	swc1	$f8,0xccc($s1)
/*  f0a0a08:	c62a0cd0 */ 	lwc1	$f10,0xcd0($s1)
/*  f0a0a0c:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0a0a10:	263107a4 */ 	addiu	$s1,$s1,0x7a4
/*  f0a0a14:	46005100 */ 	add.s	$f4,$f10,$f0
/*  f0a0a18:	1670ffcd */ 	bne	$s3,$s0,.L0f0a0950
/*  f0a0a1c:	e624052c */ 	swc1	$f4,0x52c($s1)
/*  f0a0a20:	8eeb0034 */ 	lw	$t3,0x34($s7)
/*  f0a0a24:	c7a000ec */ 	lwc1	$f0,0xec($sp)
/*  f0a0a28:	59600011 */ 	blezl	$t3,.L0f0a0a70
/*  f0a0a2c:	c7a0007c */ 	lwc1	$f0,0x7c($sp)
/*  f0a0a30:	c6a6167c */ 	lwc1	$f6,0x167c($s5)
.L0f0a0a34:
/*  f0a0a34:	c7a800e0 */ 	lwc1	$f8,0xe0($sp)
/*  f0a0a38:	c6a41680 */ 	lwc1	$f4,0x1680($s5)
/*  f0a0a3c:	46003482 */ 	mul.s	$f18,$f6,$f0
/*  f0a0a40:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0a0a44:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0a0a48:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f0a0a4c:	e6aa167c */ 	swc1	$f10,0x167c($s5)
/*  f0a0a50:	c7b200e4 */ 	lwc1	$f18,0xe4($sp)
/*  f0a0a54:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f0a0a58:	e6a81680 */ 	swc1	$f8,0x1680($s5)
/*  f0a0a5c:	8eec0034 */ 	lw	$t4,0x34($s7)
/*  f0a0a60:	028c082a */ 	slt	$at,$s4,$t4
/*  f0a0a64:	5420fff3 */ 	bnezl	$at,.L0f0a0a34
/*  f0a0a68:	c6a6167c */ 	lwc1	$f6,0x167c($s5)
/*  f0a0a6c:	c7a0007c */ 	lwc1	$f0,0x7c($sp)
.L0f0a0a70:
/*  f0a0a70:	c6aa167c */ 	lwc1	$f10,0x167c($s5)
/*  f0a0a74:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*  f0a0a78:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0a0a7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0a80:	461c2182 */ 	mul.s	$f6,$f4,$f28
/*  f0a0a84:	c6a41680 */ 	lwc1	$f4,0x1680($s5)
/*  f0a0a88:	461a3482 */ 	mul.s	$f18,$f6,$f26
/*  f0a0a8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0a90:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0a0a94:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f0a0a98:	461e3482 */ 	mul.s	$f18,$f6,$f30
/*  f0a0a9c:	e6aa1674 */ 	swc1	$f10,0x1674($s5)
/*  f0a0aa0:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f0a0aa4:	461a9202 */ 	mul.s	$f8,$f18,$f26
/*  f0a0aa8:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0a0aac:	0fc2d5fe */ 	jal	func0f0b57f8
/*  f0a0ab0:	e6a41678 */ 	swc1	$f4,0x1678($s5)
/*  f0a0ab4:	c6a61674 */ 	lwc1	$f6,0x1674($s5)
/*  f0a0ab8:	46003480 */ 	add.s	$f18,$f6,$f0
/*  f0a0abc:	0fc2d602 */ 	jal	func0f0b5808
/*  f0a0ac0:	e6b21674 */ 	swc1	$f18,0x1674($s5)
/*  f0a0ac4:	c6a81678 */ 	lwc1	$f8,0x1678($s5)
/*  f0a0ac8:	27b000c8 */ 	addiu	$s0,$sp,0xc8
/*  f0a0acc:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a0ad0:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f0a0ad4:	26a41674 */ 	addiu	$a0,$s5,0x1674
/*  f0a0ad8:	3c06447a */ 	lui	$a2,0x447a
/*  f0a0adc:	0fc2d30f */ 	jal	func0f0b4c3c
/*  f0a0ae0:	e6aa1678 */ 	swc1	$f10,0x1678($s5)
/*  f0a0ae4:	0fc2a4f8 */ 	jal	func0f0a93e0
/*  f0a0ae8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a0aec:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0a0af0:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f0a0af4:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f0a0af8:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f0a0afc:	d7ba0028 */ 	ldc1	$f26,0x28($sp)
/*  f0a0b00:	d7bc0030 */ 	ldc1	$f28,0x30($sp)
/*  f0a0b04:	d7be0038 */ 	ldc1	$f30,0x38($sp)
/*  f0a0b08:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f0a0b0c:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f0a0b10:	8fb2004c */ 	lw	$s2,0x4c($sp)
/*  f0a0b14:	8fb30050 */ 	lw	$s3,0x50($sp)
/*  f0a0b18:	8fb40054 */ 	lw	$s4,0x54($sp)
/*  f0a0b1c:	8fb50058 */ 	lw	$s5,0x58($sp)
/*  f0a0b20:	8fb6005c */ 	lw	$s6,0x5c($sp)
/*  f0a0b24:	8fb70060 */ 	lw	$s7,0x60($sp)
/*  f0a0b28:	03e00008 */ 	jr	$ra
/*  f0a0b2c:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
);

GLOBAL_ASM(
glabel func0f0a0b30
/*  f0a0b30:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a0b34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a0b38:	e7ac0018 */ 	swc1	$f12,0x18($sp)
/*  f0a0b3c:	e7ae001c */ 	swc1	$f14,0x1c($sp)
/*  f0a0b40:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0a0b44:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0a0b48:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a0b4c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a0b50:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a0b54:	8c4e0024 */ 	lw	$t6,0x24($v0)
/*  f0a0b58:	c7a20020 */ 	lwc1	$f2,0x20($sp)
/*  f0a0b5c:	c7ac0018 */ 	lwc1	$f12,0x18($sp)
/*  f0a0b60:	c5c00014 */ 	lwc1	$f0,0x14($t6)
/*  f0a0b64:	44061000 */ 	mfc1	$a2,$f2
/*  f0a0b68:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0a0b6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0b70:	45020003 */ 	bc1fl	.L0f0a0b80
/*  f0a0b74:	44070000 */ 	mfc1	$a3,$f0
/*  f0a0b78:	46001006 */ 	mov.s	$f0,$f2
/*  f0a0b7c:	44070000 */ 	mfc1	$a3,$f0
.L0f0a0b80:
/*  f0a0b80:	0fc280e5 */ 	jal	func0f0a0394
/*  f0a0b84:	c7ae001c */ 	lwc1	$f14,0x1c($sp)
/*  f0a0b88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a0b8c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a0b90:	03e00008 */ 	jr	$ra
/*  f0a0b94:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a0b98
/*  f0a0b98:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a0b9c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a0ba0:	e7ac0018 */ 	swc1	$f12,0x18($sp)
/*  f0a0ba4:	e7ae001c */ 	swc1	$f14,0x1c($sp)
/*  f0a0ba8:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0a0bac:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a0bb0:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a0bb4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a0bb8:	8c4e0024 */ 	lw	$t6,0x24($v0)
/*  f0a0bbc:	3c063f71 */ 	lui	$a2,0x3f71
/*  f0a0bc0:	34c6eb85 */ 	ori	$a2,$a2,0xeb85
/*  f0a0bc4:	c5c00014 */ 	lwc1	$f0,0x14($t6)
/*  f0a0bc8:	c7ac0018 */ 	lwc1	$f12,0x18($sp)
/*  f0a0bcc:	c7ae001c */ 	lwc1	$f14,0x1c($sp)
/*  f0a0bd0:	44070000 */ 	mfc1	$a3,$f0
/*  f0a0bd4:	0fc280e5 */ 	jal	func0f0a0394
/*  f0a0bd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0bdc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a0be0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a0be4:	03e00008 */ 	jr	$ra
/*  f0a0be8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a0bec
/*  f0a0bec:	3c02800a */ 	lui	$v0,0x800a
/*  f0a0bf0:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a0bf4:	c4441660 */ 	lwc1	$f4,0x1660($v0)
/*  f0a0bf8:	e4840000 */ 	swc1	$f4,0x0($a0)
/*  f0a0bfc:	c4461664 */ 	lwc1	$f6,0x1664($v0)
/*  f0a0c00:	03e00008 */ 	jr	$ra
/*  f0a0c04:	e4a60000 */ 	swc1	$f6,0x0($a1)
);

GLOBAL_ASM(
glabel func0f0a0c08
/*  f0a0c08:	44800000 */ 	mtc1	$zero,$f0
/*  f0a0c0c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a0c10:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a0c14:	e4800000 */ 	swc1	$f0,0x0($a0)
/*  f0a0c18:	e4800004 */ 	swc1	$f0,0x4($a0)
/*  f0a0c1c:	e4800008 */ 	swc1	$f0,0x8($a0)
/*  f0a0c20:	3c04800a */ 	lui	$a0,%hi(var800a1660)
/*  f0a0c24:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f0a0c28:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0a0c2c:	0fc2d30f */ 	jal	func0f0b4c3c
/*  f0a0c30:	24841660 */ 	addiu	$a0,$a0,%lo(var800a1660)
/*  f0a0c34:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a0c38:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a0c3c:	03e00008 */ 	jr	$ra
/*  f0a0c40:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a0c44
/*  f0a0c44:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a0c48:	44800000 */ 	mtc1	$zero,$f0
/*  f0a0c4c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a0c50:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0a0c54:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0a0c58:	e4a00000 */ 	swc1	$f0,0x0($a1)
/*  f0a0c5c:	e4a00004 */ 	swc1	$f0,0x4($a1)
/*  f0a0c60:	e4a00008 */ 	swc1	$f0,0x8($a1)
/*  f0a0c64:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f0a0c68:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a0c6c:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a0c70:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0a0c74:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0a0c78:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0a0c7c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0a0c80:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0a0c84:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0a0c88:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0a0c8c:	01d82021 */ 	addu	$a0,$t6,$t8
/*  f0a0c90:	24840ccc */ 	addiu	$a0,$a0,0xccc
/*  f0a0c94:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f0a0c98:	0fc2d30f */ 	jal	func0f0b4c3c
/*  f0a0c9c:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0a0ca0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a0ca4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a0ca8:	03e00008 */ 	jr	$ra
/*  f0a0cac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a0cb0
/*  f0a0cb0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0a0cb4:	44801000 */ 	mtc1	$zero,$f2
/*  f0a0cb8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a0cbc:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f0a0cc0:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f0a0cc4:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0a0cc8:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0a0ccc:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0a0cd0:	0fc2c43b */ 	jal	func0f0b10ec
/*  f0a0cd4:	e7a2003c */ 	swc1	$f2,0x3c($sp)
/*  f0a0cd8:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a0cdc:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a0ce0:	c7a2003c */ 	lwc1	$f2,0x3c($sp)
/*  f0a0ce4:	10400007 */ 	beqz	$v0,.L0f0a0d04
/*  f0a0ce8:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f0a0cec:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0a0cf0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a0cf4:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0a0cf8:	57010003 */ 	bnel	$t8,$at,.L0f0a0d08
/*  f0a0cfc:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0a0d00:	c4420020 */ 	lwc1	$f2,0x20($v0)
.L0f0a0d04:
/*  f0a0d04:	8fa40050 */ 	lw	$a0,0x50($sp)
.L0f0a0d08:
/*  f0a0d08:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f0a0d0c:	e7a2003c */ 	swc1	$f2,0x3c($sp)
/*  f0a0d10:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a0d14:	0fc2c601 */ 	jal	func0f0b1804
/*  f0a0d18:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0a0d1c:	10400013 */ 	beqz	$v0,.L0f0a0d6c
/*  f0a0d20:	c7a2003c */ 	lwc1	$f2,0x3c($sp)
/*  f0a0d24:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f0a0d28:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*  f0a0d2c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a0d30:	00084900 */ 	sll	$t1,$t0,0x4
/*  f0a0d34:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0a0d38:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0a0d3c:	01284821 */ 	addu	$t1,$t1,$t0
/*  f0a0d40:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f0a0d44:	01284821 */ 	addu	$t1,$t1,$t0
/*  f0a0d48:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0a0d4c:	03295021 */ 	addu	$t2,$t9,$t1
/*  f0a0d50:	8d4b0b90 */ 	lw	$t3,0xb90($t2)
/*  f0a0d54:	15610005 */ 	bne	$t3,$at,.L0f0a0d6c
/*  f0a0d58:	3c013e80 */ 	lui	$at,0x3e80
/*  f0a0d5c:	44812000 */ 	mtc1	$at,$f4
/*  f0a0d60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0d64:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0a0d68:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a0d6c:
/*  f0a0d6c:	0fc331a0 */ 	jal	func0f0cc680
/*  f0a0d70:	e7a2003c */ 	swc1	$f2,0x3c($sp)
/*  f0a0d74:	14400006 */ 	bnez	$v0,.L0f0a0d90
/*  f0a0d78:	c7a2003c */ 	lwc1	$f2,0x3c($sp)
/*  f0a0d7c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a0d80:	44813000 */ 	mtc1	$at,$f6
/*  f0a0d84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0d88:	46061082 */ 	mul.s	$f2,$f2,$f6
/*  f0a0d8c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a0d90:
/*  f0a0d90:	8fac002c */ 	lw	$t4,0x2c($sp)
/*  f0a0d94:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f0a0d98:	818d0de4 */ 	lb	$t5,0xde4($t4)
/*  f0a0d9c:	11a00005 */ 	beqz	$t5,.L0f0a0db4
/*  f0a0da0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0da4:	44814000 */ 	mtc1	$at,$f8
/*  f0a0da8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0dac:	46081082 */ 	mul.s	$f2,$f2,$f8
/*  f0a0db0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a0db4:
/*  f0a0db4:	0c002f9d */ 	jal	func0000be74
/*  f0a0db8:	e7a2003c */ 	swc1	$f2,0x3c($sp)
/*  f0a0dbc:	3c0142f0 */ 	lui	$at,0x42f0
/*  f0a0dc0:	44815000 */ 	mtc1	$at,$f10
/*  f0a0dc4:	c7a2003c */ 	lwc1	$f2,0x3c($sp)
/*  f0a0dc8:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f0a0dcc:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f0a0dd0:	46008483 */ 	div.s	$f18,$f16,$f0
/*  f0a0dd4:	11c00020 */ 	beqz	$t6,.L0f0a0e58
/*  f0a0dd8:	e7b20038 */ 	swc1	$f18,0x38($sp)
/*  f0a0ddc:	0c004b70 */ 	jal	random
/*  f0a0de0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0de4:	0c004b70 */ 	jal	random
/*  f0a0de8:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0a0dec:	44822000 */ 	mtc1	$v0,$f4
/*  f0a0df0:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f0a0df4:	04410005 */ 	bgez	$v0,.L0f0a0e0c
/*  f0a0df8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a0dfc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a0e00:	44814000 */ 	mtc1	$at,$f8
/*  f0a0e04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0e08:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0a0e0c:
/*  f0a0e0c:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a0e10:	44815000 */ 	mtc1	$at,$f10
/*  f0a0e14:	448f9000 */ 	mtc1	$t7,$f18
/*  f0a0e18:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a0e1c:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0a0e20:	05e10004 */ 	bgez	$t7,.L0f0a0e34
/*  f0a0e24:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0a0e28:	44814000 */ 	mtc1	$at,$f8
/*  f0a0e2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0e30:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f0a0e34:
/*  f0a0e34:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a0e38:	44813000 */ 	mtc1	$at,$f6
/*  f0a0e3c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a0e40:	44819000 */ 	mtc1	$at,$f18
/*  f0a0e44:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f0a0e48:	46125201 */ 	sub.s	$f8,$f10,$f18
/*  f0a0e4c:	46088082 */ 	mul.s	$f2,$f16,$f8
/*  f0a0e50:	10000003 */ 	beqz	$zero,.L0f0a0e60
/*  f0a0e54:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a0e58:
/*  f0a0e58:	44801000 */ 	mtc1	$zero,$f2
/*  f0a0e5c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a0e60:
/*  f0a0e60:	0fc2d5f6 */ 	jal	func0f0b57d8
/*  f0a0e64:	e7a20034 */ 	swc1	$f2,0x34($sp)
/*  f0a0e68:	0c002f06 */ 	jal	func0000bc18
/*  f0a0e6c:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0a0e70:	0fc2d60a */ 	jal	func0f0b5828
/*  f0a0e74:	a7a20022 */ 	sh	$v0,0x22($sp)
/*  f0a0e78:	c7a20034 */ 	lwc1	$f2,0x34($sp)
/*  f0a0e7c:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*  f0a0e80:	87b80022 */ 	lh	$t8,0x22($sp)
/*  f0a0e84:	c7aa001c */ 	lwc1	$f10,0x1c($sp)
/*  f0a0e88:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f0a0e8c:	44988000 */ 	mtc1	$t8,$f16
/*  f0a0e90:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f0a0e94:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f0a0e98:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f0a0e9c:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f0a0ea0:	c50a1660 */ 	lwc1	$f10,0x1660($t0)
/*  f0a0ea4:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f0a0ea8:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f0a0eac:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f0a0eb0:	1320001f */ 	beqz	$t9,.L0f0a0f30
/*  f0a0eb4:	e7b00040 */ 	swc1	$f16,0x40($sp)
/*  f0a0eb8:	0c004b70 */ 	jal	random
/*  f0a0ebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0ec0:	0c004b70 */ 	jal	random
/*  f0a0ec4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0a0ec8:	8fa90024 */ 	lw	$t1,0x24($sp)
/*  f0a0ecc:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a0ed0:	44810000 */ 	mtc1	$at,$f0
/*  f0a0ed4:	44894000 */ 	mtc1	$t1,$f8
/*  f0a0ed8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a0edc:	05210004 */ 	bgez	$t1,.L0f0a0ef0
/*  f0a0ee0:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f0a0ee4:	44812000 */ 	mtc1	$at,$f4
/*  f0a0ee8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0eec:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f0a0ef0:
/*  f0a0ef0:	46009182 */ 	mul.s	$f6,$f18,$f0
/*  f0a0ef4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a0ef8:	44815000 */ 	mtc1	$at,$f10
/*  f0a0efc:	44824000 */ 	mtc1	$v0,$f8
/*  f0a0f00:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a0f04:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0a0f08:	04410004 */ 	bgez	$v0,.L0f0a0f1c
/*  f0a0f0c:	460a3401 */ 	sub.s	$f16,$f6,$f10
/*  f0a0f10:	44819000 */ 	mtc1	$at,$f18
/*  f0a0f14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0f18:	46122100 */ 	add.s	$f4,$f4,$f18
.L0f0a0f1c:
/*  f0a0f1c:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0a0f20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a0f24:	46103082 */ 	mul.s	$f2,$f6,$f16
/*  f0a0f28:	10000003 */ 	beqz	$zero,.L0f0a0f38
/*  f0a0f2c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a0f30:
/*  f0a0f30:	44801000 */ 	mtc1	$zero,$f2
/*  f0a0f34:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a0f38:
/*  f0a0f38:	0fc2d5fa */ 	jal	func0f0b57e8
/*  f0a0f3c:	e7a20034 */ 	swc1	$f2,0x34($sp)
/*  f0a0f40:	0c002f06 */ 	jal	func0000bc18
/*  f0a0f44:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0a0f48:	c7a20034 */ 	lwc1	$f2,0x34($sp)
/*  f0a0f4c:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*  f0a0f50:	c7b2001c */ 	lwc1	$f18,0x1c($sp)
/*  f0a0f54:	44823000 */ 	mtc1	$v0,$f6
/*  f0a0f58:	460a1202 */ 	mul.s	$f8,$f2,$f10
/*  f0a0f5c:	8faa002c */ 	lw	$t2,0x2c($sp)
/*  f0a0f60:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f0a0f64:	44800000 */ 	mtc1	$zero,$f0
/*  f0a0f68:	27a40040 */ 	addiu	$a0,$sp,0x40
/*  f0a0f6c:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0a0f70:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0a0f74:	46124102 */ 	mul.s	$f4,$f8,$f18
/*  f0a0f78:	c5481664 */ 	lwc1	$f8,0x1664($t2)
/*  f0a0f7c:	46102283 */ 	div.s	$f10,$f4,$f16
/*  f0a0f80:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f0a0f84:	e7b20044 */ 	swc1	$f18,0x44($sp)
/*  f0a0f88:	e4600000 */ 	swc1	$f0,0x0($v1)
/*  f0a0f8c:	e4600004 */ 	swc1	$f0,0x4($v1)
/*  f0a0f90:	e4600008 */ 	swc1	$f0,0x8($v1)
/*  f0a0f94:	0fc2d30f */ 	jal	func0f0b4c3c
/*  f0a0f98:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f0a0f9c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a0fa0:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0a0fa4:	03e00008 */ 	jr	$ra
/*  f0a0fa8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a0fac
/*  f0a0fac:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f0a0fb0:	44801000 */ 	mtc1	$zero,$f2
/*  f0a0fb4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0a0fb8:	afa400a8 */ 	sw	$a0,0xa8($sp)
/*  f0a0fbc:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f0a0fc0:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f0a0fc4:	afa700b4 */ 	sw	$a3,0xb4($sp)
/*  f0a0fc8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0a0fcc:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a0fd0:	e7a200a4 */ 	swc1	$f2,0xa4($sp)
/*  f0a0fd4:	1040000d */ 	beqz	$v0,.L0f0a100c
/*  f0a0fd8:	c7a200a4 */ 	lwc1	$f2,0xa4($sp)
/*  f0a0fdc:	8fae00b0 */ 	lw	$t6,0xb0($sp)
/*  f0a0fe0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0a0fe4:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0a0fe8:	8f030014 */ 	lw	$v1,0x14($t8)
/*  f0a0fec:	50600008 */ 	beqzl	$v1,.L0f0a1010
/*  f0a0ff0:	8fa900b4 */ 	lw	$t1,0xb4($sp)
/*  f0a0ff4:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0a0ff8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a0ffc:	332800ff */ 	andi	$t0,$t9,0xff
/*  f0a1000:	55010003 */ 	bnel	$t0,$at,.L0f0a1010
/*  f0a1004:	8fa900b4 */ 	lw	$t1,0xb4($sp)
/*  f0a1008:	c4620020 */ 	lwc1	$f2,0x20($v1)
.L0f0a100c:
/*  f0a100c:	8fa900b4 */ 	lw	$t1,0xb4($sp)
.L0f0a1010:
/*  f0a1010:	5120000d */ 	beqzl	$t1,.L0f0a1048
/*  f0a1014:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*  f0a1018:	8fa400ac */ 	lw	$a0,0xac($sp)
/*  f0a101c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0a1020:	0fc2c601 */ 	jal	func0f0b1804
/*  f0a1024:	e7a200a4 */ 	swc1	$f2,0xa4($sp)
/*  f0a1028:	10400006 */ 	beqz	$v0,.L0f0a1044
/*  f0a102c:	c7a200a4 */ 	lwc1	$f2,0xa4($sp)
/*  f0a1030:	3c013e80 */ 	lui	$at,0x3e80
/*  f0a1034:	44812000 */ 	mtc1	$at,$f4
/*  f0a1038:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a103c:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0a1040:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a1044:
/*  f0a1044:	8faa00b8 */ 	lw	$t2,0xb8($sp)
.L0f0a1048:
/*  f0a1048:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f0a104c:	15400005 */ 	bnez	$t2,.L0f0a1064
/*  f0a1050:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a1054:	44813000 */ 	mtc1	$at,$f6
/*  f0a1058:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a105c:	46061082 */ 	mul.s	$f2,$f2,$f6
/*  f0a1060:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a1064:
/*  f0a1064:	11600005 */ 	beqz	$t3,.L0f0a107c
/*  f0a1068:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f0a106c:	44814000 */ 	mtc1	$at,$f8
/*  f0a1070:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1074:	46081082 */ 	mul.s	$f2,$f2,$f8
/*  f0a1078:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a107c:
/*  f0a107c:	0c002f9d */ 	jal	func0000be74
/*  f0a1080:	e7a200a4 */ 	swc1	$f2,0xa4($sp)
/*  f0a1084:	3c0142f0 */ 	lui	$at,0x42f0
/*  f0a1088:	44815000 */ 	mtc1	$at,$f10
/*  f0a108c:	c7a200a4 */ 	lwc1	$f2,0xa4($sp)
/*  f0a1090:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f0a1094:	46008483 */ 	div.s	$f18,$f16,$f0
/*  f0a1098:	0c004b70 */ 	jal	random
/*  f0a109c:	e7b200a0 */ 	swc1	$f18,0xa0($sp)
/*  f0a10a0:	0c004b70 */ 	jal	random
/*  f0a10a4:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f0a10a8:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f0a10ac:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a10b0:	44810000 */ 	mtc1	$at,$f0
/*  f0a10b4:	448c2000 */ 	mtc1	$t4,$f4
/*  f0a10b8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a10bc:	05810004 */ 	bgez	$t4,.L0f0a10d0
/*  f0a10c0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a10c4:	44814000 */ 	mtc1	$at,$f8
/*  f0a10c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a10cc:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0a10d0:
/*  f0a10d0:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f0a10d4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a10d8:	44818000 */ 	mtc1	$at,$f16
/*  f0a10dc:	44822000 */ 	mtc1	$v0,$f4
/*  f0a10e0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a10e4:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0a10e8:	04410004 */ 	bgez	$v0,.L0f0a10fc
/*  f0a10ec:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0a10f0:	44813000 */ 	mtc1	$at,$f6
/*  f0a10f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a10f8:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f0a10fc:
/*  f0a10fc:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0a1100:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f0a1104:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f0a1108:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a110c:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0a1110:	0c004b70 */ 	jal	random
/*  f0a1114:	e7a60098 */ 	swc1	$f6,0x98($sp)
/*  f0a1118:	0c004b70 */ 	jal	random
/*  f0a111c:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f0a1120:	3c03800a */ 	lui	$v1,%hi(var800a0638)
/*  f0a1124:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f0a1128:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f0a112c:	8fad0038 */ 	lw	$t5,0x38($sp)
/*  f0a1130:	c4681728 */ 	lwc1	$f8,0x1728($v1)
/*  f0a1134:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a1138:	448d8000 */ 	mtc1	$t5,$f16
/*  f0a113c:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0a1140:	44810000 */ 	mtc1	$at,$f0
/*  f0a1144:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a1148:	46808120 */ 	cvt.s.w	$f4,$f16
/*  f0a114c:	05a10004 */ 	bgez	$t5,.L0f0a1160
/*  f0a1150:	e7b20048 */ 	swc1	$f18,0x48($sp)
/*  f0a1154:	44813000 */ 	mtc1	$at,$f6
/*  f0a1158:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a115c:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f0a1160:
/*  f0a1160:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f0a1164:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a1168:	44815000 */ 	mtc1	$at,$f10
/*  f0a116c:	44828000 */ 	mtc1	$v0,$f16
/*  f0a1170:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a1174:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0a1178:	04410004 */ 	bgez	$v0,.L0f0a118c
/*  f0a117c:	460a4481 */ 	sub.s	$f18,$f8,$f10
/*  f0a1180:	44812000 */ 	mtc1	$at,$f4
/*  f0a1184:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1188:	46043180 */ 	add.s	$f6,$f6,$f4
.L0f0a118c:
/*  f0a118c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a1190:	c7b000a0 */ 	lwc1	$f16,0xa0($sp)
/*  f0a1194:	c466172c */ 	lwc1	$f6,0x172c($v1)
/*  f0a1198:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a119c:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f0a11a0:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0a11a4:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0a11a8:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f0a11ac:	44819000 */ 	mtc1	$at,$f18
/*  f0a11b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a11b4:	e7b20050 */ 	swc1	$f18,0x50($sp)
/*  f0a11b8:	46105102 */ 	mul.s	$f4,$f10,$f16
/*  f0a11bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a11c0:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0a11c4:	0c0011e4 */ 	jal	scaleTo1
/*  f0a11c8:	e7a8004c */ 	swc1	$f8,0x4c($sp)
/*  f0a11cc:	8fa200a8 */ 	lw	$v0,0xa8($sp)
/*  f0a11d0:	44800000 */ 	mtc1	$zero,$f0
/*  f0a11d4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a11d8:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f0a11dc:	44812000 */ 	mtc1	$at,$f4
/*  f0a11e0:	44050000 */ 	mfc1	$a1,$f0
/*  f0a11e4:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0a11e8:	c4500004 */ 	lwc1	$f16,0x4($v0)
/*  f0a11ec:	44060000 */ 	mfc1	$a2,$f0
/*  f0a11f0:	44070000 */ 	mfc1	$a3,$f0
/*  f0a11f4:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f0a11f8:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0a11fc:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f0a1200:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0a1204:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0a1208:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0a120c:	0c005ad6 */ 	jal	func00016b58
/*  f0a1210:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*  f0a1214:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f0a1218:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f0a121c:	0c0056c5 */ 	jal	0x15b14
/*  f0a1220:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0a1224:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0a1228:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f0a122c:	03e00008 */ 	jr	$ra
/*  f0a1230:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1234:	00067900 */ 	sll	$t7,$a2,0x4
/*  f0a1238:	01e67823 */ 	subu	$t7,$t7,$a2
/*  f0a123c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a1240:	01e67821 */ 	addu	$t7,$t7,$a2
/*  f0a1244:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a1248:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a124c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0a1250:	01e67821 */ 	addu	$t7,$t7,$a2
/*  f0a1254:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a1258:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f0a125c:	80780c14 */ 	lb	$t8,0xc14($v1)
/*  f0a1260:	24630638 */ 	addiu	$v1,$v1,%lo(var800a0638)
/*  f0a1264:	57000004 */ 	bnezl	$t8,.L0f0a1278
/*  f0a1268:	c46405ec */ 	lwc1	$f4,0x5ec($v1)
/*  f0a126c:	03e00008 */ 	jr	$ra
/*  f0a1270:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a1274:	c46405ec */ 	lwc1	$f4,0x5ec($v1)
.L0f0a1278:
/*  f0a1278:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a127c:	e4840000 */ 	swc1	$f4,0x0($a0)
/*  f0a1280:	c46605f0 */ 	lwc1	$f6,0x5f0($v1)
/*  f0a1284:	e4860004 */ 	swc1	$f6,0x4($a0)
/*  f0a1288:	c46805f4 */ 	lwc1	$f8,0x5f4($v1)
/*  f0a128c:	e4880008 */ 	swc1	$f8,0x8($a0)
/*  f0a1290:	c46a05e0 */ 	lwc1	$f10,0x5e0($v1)
/*  f0a1294:	e4aa0000 */ 	swc1	$f10,0x0($a1)
/*  f0a1298:	c47005e4 */ 	lwc1	$f16,0x5e4($v1)
/*  f0a129c:	e4b00004 */ 	swc1	$f16,0x4($a1)
/*  f0a12a0:	c47205e8 */ 	lwc1	$f18,0x5e8($v1)
/*  f0a12a4:	e4b20008 */ 	swc1	$f18,0x8($a1)
/*  f0a12a8:	03e00008 */ 	jr	$ra
/*  f0a12ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a12b0
/*  f0a12b0:	00067900 */ 	sll	$t7,$a2,0x4
/*  f0a12b4:	01e67823 */ 	subu	$t7,$t7,$a2
/*  f0a12b8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a12bc:	01e67821 */ 	addu	$t7,$t7,$a2
/*  f0a12c0:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a12c4:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a12c8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0a12cc:	01e67821 */ 	addu	$t7,$t7,$a2
/*  f0a12d0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a12d4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0a12d8:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f0a12dc:	a0580c14 */ 	sb	$t8,0xc14($v0)
/*  f0a12e0:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f0a12e4:	24420638 */ 	addiu	$v0,$v0,0x638
/*  f0a12e8:	e44405ec */ 	swc1	$f4,0x5ec($v0)
/*  f0a12ec:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f0a12f0:	e44605f0 */ 	swc1	$f6,0x5f0($v0)
/*  f0a12f4:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f0a12f8:	e44805f4 */ 	swc1	$f8,0x5f4($v0)
/*  f0a12fc:	c4aa0000 */ 	lwc1	$f10,0x0($a1)
/*  f0a1300:	e44a05e0 */ 	swc1	$f10,0x5e0($v0)
/*  f0a1304:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f0a1308:	e45005e4 */ 	swc1	$f16,0x5e4($v0)
/*  f0a130c:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f0a1310:	03e00008 */ 	jr	$ra
/*  f0a1314:	e45205e8 */ 	swc1	$f18,0x5e8($v0)
);

GLOBAL_ASM(
glabel func0f0a1318
/*  f0a1318:	00047900 */ 	sll	$t7,$a0,0x4
/*  f0a131c:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f0a1320:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a1324:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f0a1328:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a132c:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a1330:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0a1334:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f0a1338:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a133c:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f0a1340:	24630638 */ 	addiu	$v1,$v1,0x638
/*  f0a1344:	03e00008 */ 	jr	$ra
/*  f0a1348:	8c6205f8 */ 	lw	$v0,0x5f8($v1)
);

GLOBAL_ASM(
glabel func0f0a134c
/*  f0a134c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0a1350:	00047100 */ 	sll	$t6,$a0,0x4
/*  f0a1354:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f0a1358:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0a135c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0a1360:	3c15800a */ 	lui	$s5,0x800a
/*  f0a1364:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f0a1368:	8eb5a244 */ 	lw	$s5,-0x5dbc($s5)
/*  f0a136c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0a1370:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f0a1374:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0a1378:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0a137c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0a1380:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0a1384:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0a1388:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0a138c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0a1390:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0a1394:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0a1398:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a139c:	02ae7821 */ 	addu	$t7,$s5,$t6
/*  f0a13a0:	81f80640 */ 	lb	$t8,0x640($t7)
/*  f0a13a4:	0080f025 */ 	or	$s8,$a0,$zero
/*  f0a13a8:	00009025 */ 	or	$s2,$zero,$zero
/*  f0a13ac:	13000027 */ 	beqz	$t8,.L0f0a144c
/*  f0a13b0:	02a09825 */ 	or	$s3,$s5,$zero
/*  f0a13b4:	24170002 */ 	addiu	$s7,$zero,0x2
/*  f0a13b8:	2416ffff */ 	addiu	$s6,$zero,-1
.L0f0a13bc:
/*  f0a13bc:	827915e4 */ 	lb	$t9,0x15e4($s3)
/*  f0a13c0:	001e4100 */ 	sll	$t0,$s8,0x4
/*  f0a13c4:	011e4023 */ 	subu	$t0,$t0,$s8
/*  f0a13c8:	0720001d */ 	bltz	$t9,.L0f0a1440
/*  f0a13cc:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0a13d0:	011e4021 */ 	addu	$t0,$t0,$s8
/*  f0a13d4:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f0a13d8:	011e4021 */ 	addu	$t0,$t0,$s8
/*  f0a13dc:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0a13e0:	02a88821 */ 	addu	$s1,$s5,$t0
/*  f0a13e4:	00124880 */ 	sll	$t1,$s2,0x2
/*  f0a13e8:	02298021 */ 	addu	$s0,$s1,$t1
/*  f0a13ec:	8e0a0860 */ 	lw	$t2,0x860($s0)
/*  f0a13f0:	8e0b0858 */ 	lw	$t3,0x858($s0)
/*  f0a13f4:	82a41580 */ 	lb	$a0,0x1580($s5)
/*  f0a13f8:	0fc25f43 */ 	jal	func0f097d0c
/*  f0a13fc:	014ba023 */ 	subu	$s4,$t2,$t3
/*  f0a1400:	10560005 */ 	beq	$v0,$s6,.L0f0a1418
/*  f0a1404:	00146200 */ 	sll	$t4,$s4,0x8
/*  f0a1408:	00027040 */ 	sll	$t6,$v0,0x1
/*  f0a140c:	022e7821 */ 	addu	$t7,$s1,$t6
/*  f0a1410:	358d00ff */ 	ori	$t5,$t4,0xff
/*  f0a1414:	a5ed0d74 */ 	sh	$t5,0xd74($t7)
.L0f0a1418:
/*  f0a1418:	8e030858 */ 	lw	$v1,0x858($s0)
/*  f0a141c:	58600008 */ 	blezl	$v1,.L0f0a1440
/*  f0a1420:	ae000858 */ 	sw	$zero,0x858($s0)
/*  f0a1424:	827815e4 */ 	lb	$t8,0x15e4($s3)
/*  f0a1428:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0a142c:	02b91021 */ 	addu	$v0,$s5,$t9
/*  f0a1430:	8c4817a8 */ 	lw	$t0,0x17a8($v0)
/*  f0a1434:	01034821 */ 	addu	$t1,$t0,$v1
/*  f0a1438:	ac4917a8 */ 	sw	$t1,0x17a8($v0)
/*  f0a143c:	ae000858 */ 	sw	$zero,0x858($s0)
.L0f0a1440:
/*  f0a1440:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0a1444:	1657ffdd */ 	bne	$s2,$s7,.L0f0a13bc
/*  f0a1448:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f0a144c:
/*  f0a144c:	3c0a800a */ 	lui	$t2,0x800a
/*  f0a1450:	8d4aa2d4 */ 	lw	$t2,-0x5d2c($t2)
/*  f0a1454:	3c0b8009 */ 	lui	$t3,0x8009
/*  f0a1458:	11400025 */ 	beqz	$t2,.L0f0a14f0
/*  f0a145c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1460:	916b0af0 */ 	lbu	$t3,0xaf0($t3)
/*  f0a1464:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a1468:	3c0c800a */ 	lui	$t4,0x800a
/*  f0a146c:	14cb001e */ 	bne	$a2,$t3,.L0f0a14e8
/*  f0a1470:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a1474:	8d8ca02c */ 	lw	$t4,-0x5fd4($t4)
/*  f0a1478:	3c0d800a */ 	lui	$t5,0x800a
/*  f0a147c:	3c0f800a */ 	lui	$t7,0x800a
/*  f0a1480:	11800003 */ 	beqz	$t4,.L0f0a1490
/*  f0a1484:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a1488:	10000001 */ 	beqz	$zero,.L0f0a1490
/*  f0a148c:	00c02825 */ 	or	$a1,$a2,$zero
.L0f0a1490:
/*  f0a1490:	8dcea028 */ 	lw	$t6,-0x5fd8($t6)
/*  f0a1494:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a1498:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a149c:	11c00003 */ 	beqz	$t6,.L0f0a14ac
/*  f0a14a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a14a4:	10000001 */ 	beqz	$zero,.L0f0a14ac
/*  f0a14a8:	00c01825 */ 	or	$v1,$a2,$zero
.L0f0a14ac:
/*  f0a14ac:	8dada024 */ 	lw	$t5,-0x5fdc($t5)
/*  f0a14b0:	11a00003 */ 	beqz	$t5,.L0f0a14c0
/*  f0a14b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a14b8:	10000001 */ 	beqz	$zero,.L0f0a14c0
/*  f0a14bc:	00c02025 */ 	or	$a0,$a2,$zero
.L0f0a14c0:
/*  f0a14c0:	8defa030 */ 	lw	$t7,-0x5fd0($t7)
/*  f0a14c4:	11e00003 */ 	beqz	$t7,.L0f0a14d4
/*  f0a14c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a14cc:	10000001 */ 	beqz	$zero,.L0f0a14d4
/*  f0a14d0:	00c01025 */ 	or	$v0,$a2,$zero
.L0f0a14d4:
/*  f0a14d4:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f0a14d8:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f0a14dc:	03254021 */ 	addu	$t0,$t9,$a1
/*  f0a14e0:	10c80003 */ 	beq	$a2,$t0,.L0f0a14f0
/*  f0a14e4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a14e8:
/*  f0a14e8:	0fc4a33c */ 	jal	func0f128cf0
/*  f0a14ec:	03c02025 */ 	or	$a0,$s8,$zero
.L0f0a14f0:
/*  f0a14f0:	0fc27e88 */ 	jal	func0f09fa20
/*  f0a14f4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0a14f8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0a14fc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a1500:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0a1504:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0a1508:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0a150c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0a1510:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0a1514:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0a1518:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0a151c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0a1520:	03e00008 */ 	jr	$ra
/*  f0a1524:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f0a1528
/*  f0a1528:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0a152c:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f0a1530:	3c03800a */ 	lui	$v1,0x800a
/*  f0a1534:	8c75a244 */ 	lw	$s5,-0x5dbc($v1)
/*  f0a1538:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f0a153c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0a1540:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f0a1544:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f0a1548:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f0a154c:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f0a1550:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0a1554:	26b41580 */ 	addiu	$s4,$s5,0x1580
/*  f0a1558:	828e0002 */ 	lb	$t6,0x2($s4)
/*  f0a155c:	05c200e6 */ 	bltzl	$t6,.L0f0a18f8
/*  f0a1560:	82a20de4 */ 	lb	$v0,0xde4($s5)
/*  f0a1564:	0fc26fb2 */ 	jal	func0f09bec8
/*  f0a1568:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a156c:	504000f6 */ 	beqzl	$v0,.L0f0a1948
/*  f0a1570:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0a1574:	0fc26fb2 */ 	jal	func0f09bec8
/*  f0a1578:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a157c:	504000f2 */ 	beqzl	$v0,.L0f0a1948
/*  f0a1580:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0a1584:	82b01580 */ 	lb	$s0,0x1580($s5)
/*  f0a1588:	82b10de4 */ 	lb	$s1,0xde4($s5)
/*  f0a158c:	0fc2c62f */ 	jal	currentPlayerHasWeaponEquipped
/*  f0a1590:	82840002 */ 	lb	$a0,0x2($s4)
/*  f0a1594:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0a1598:	10410002 */ 	beq	$v0,$at,.L0f0a15a4
/*  f0a159c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0a15a0:	a2920002 */ 	sb	$s2,0x2($s4)
.L0f0a15a4:
/*  f0a15a4:	82980003 */ 	lb	$t8,0x3($s4)
/*  f0a15a8:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0a15ac:	07010009 */ 	bgez	$t8,.L0f0a15d4
/*  f0a15b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a15b4:	82840002 */ 	lb	$a0,0x2($s4)
/*  f0a15b8:	0fc4473e */ 	jal	func0f111cf8
/*  f0a15bc:	00802825 */ 	or	$a1,$a0,$zero
/*  f0a15c0:	14400004 */ 	bnez	$v0,.L0f0a15d4
/*  f0a15c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a15c8:	92990003 */ 	lbu	$t9,0x3($s4)
/*  f0a15cc:	3328ff7f */ 	andi	$t0,$t9,0xff7f
/*  f0a15d0:	a2880003 */ 	sb	$t0,0x3($s4)
.L0f0a15d4:
/*  f0a15d4:	0fc35cd9 */ 	jal	func0f0d7364
/*  f0a15d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a15dc:	0fc284d3 */ 	jal	func0f0a134c
/*  f0a15e0:	02402025 */ 	or	$a0,$s2,$zero
/*  f0a15e4:	0fc284d3 */ 	jal	func0f0a134c
/*  f0a15e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a15ec:	24060032 */ 	addiu	$a2,$zero,0x32
/*  f0a15f0:	16060005 */ 	bne	$s0,$a2,.L0f0a1608
/*  f0a15f4:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0a15f8:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0a15fc:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0a1600:	8ca90284 */ 	lw	$t1,0x284($a1)
/*  f0a1604:	ad200120 */ 	sw	$zero,0x120($t1)
.L0f0a1608:
/*  f0a1608:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0a160c:	1601000f */ 	bne	$s0,$at,.L0f0a164c
/*  f0a1610:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0a1614:	c6a40874 */ 	lwc1	$f4,0x874($s5)
/*  f0a1618:	828b0064 */ 	lb	$t3,0x64($s4)
/*  f0a161c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a1620:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0a1624:	02ac2021 */ 	addu	$a0,$s5,$t4
/*  f0a1628:	8c8317a8 */ 	lw	$v1,0x17a8($a0)
/*  f0a162c:	44023000 */ 	mfc1	$v0,$f6
/*  f0a1630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1634:	0062082a */ 	slt	$at,$v1,$v0
/*  f0a1638:	50200003 */ 	beqzl	$at,.L0f0a1648
/*  f0a163c:	00626823 */ 	subu	$t5,$v1,$v0
/*  f0a1640:	00601025 */ 	or	$v0,$v1,$zero
/*  f0a1644:	00626823 */ 	subu	$t5,$v1,$v0
.L0f0a1648:
/*  f0a1648:	ac8d17a8 */ 	sw	$t5,0x17a8($a0)
.L0f0a164c:
/*  f0a164c:	5606000f */ 	bnel	$s0,$a2,.L0f0a168c
/*  f0a1650:	82840002 */ 	lb	$a0,0x2($s4)
/*  f0a1654:	44804000 */ 	mtc1	$zero,$f8
/*  f0a1658:	8cae0284 */ 	lw	$t6,0x284($a1)
/*  f0a165c:	3c014270 */ 	lui	$at,0x4270
/*  f0a1660:	44818000 */ 	mtc1	$at,$f16
/*  f0a1664:	e5c81844 */ 	swc1	$f8,0x1844($t6)
/*  f0a1668:	8ca30284 */ 	lw	$v1,0x284($a1)
/*  f0a166c:	c46a1844 */ 	lwc1	$f10,0x1844($v1)
/*  f0a1670:	e46a1840 */ 	swc1	$f10,0x1840($v1)
/*  f0a1674:	8caf0284 */ 	lw	$t7,0x284($a1)
/*  f0a1678:	e5f01850 */ 	swc1	$f16,0x1850($t7)
/*  f0a167c:	8ca30284 */ 	lw	$v1,0x284($a1)
/*  f0a1680:	c4721850 */ 	lwc1	$f18,0x1850($v1)
/*  f0a1684:	e4721848 */ 	swc1	$f18,0x1848($v1)
/*  f0a1688:	82840002 */ 	lb	$a0,0x2($s4)
.L0f0a168c:
/*  f0a168c:	26a20ddc */ 	addiu	$v0,$s5,0xddc
/*  f0a1690:	14800005 */ 	bnez	$a0,.L0f0a16a8
/*  f0a1694:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1698:	a0400008 */ 	sb	$zero,0x8($v0)
/*  f0a169c:	a2a00640 */ 	sb	$zero,0x640($s5)
/*  f0a16a0:	1000000a */ 	beqz	$zero,.L0f0a16cc
/*  f0a16a4:	a2800000 */ 	sb	$zero,0x0($s4)
.L0f0a16a8:
/*  f0a16a8:	0fc277d9 */ 	jal	func0f09df64
/*  f0a16ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a16b0:	82980002 */ 	lb	$t8,0x2($s4)
/*  f0a16b4:	26a20ddc */ 	addiu	$v0,$s5,0xddc
/*  f0a16b8:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0a16bc:	a2980000 */ 	sb	$t8,0x0($s4)
/*  f0a16c0:	a0520008 */ 	sb	$s2,0x8($v0)
/*  f0a16c4:	a2b20640 */ 	sb	$s2,0x640($s5)
/*  f0a16c8:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
.L0f0a16cc:
/*  f0a16cc:	82990000 */ 	lb	$t9,0x0($s4)
/*  f0a16d0:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0a16d4:	57210005 */ 	bnel	$t9,$at,.L0f0a16ec
/*  f0a16d8:	828c0003 */ 	lb	$t4,0x3($s4)
/*  f0a16dc:	92890003 */ 	lbu	$t1,0x3($s4)
/*  f0a16e0:	352a0080 */ 	ori	$t2,$t1,0x80
/*  f0a16e4:	a28a0003 */ 	sb	$t2,0x3($s4)
/*  f0a16e8:	828c0003 */ 	lb	$t4,0x3($s4)
.L0f0a16ec:
/*  f0a16ec:	2a01002d */ 	slti	$at,$s0,0x2d
/*  f0a16f0:	05800002 */ 	bltz	$t4,.L0f0a16fc
/*  f0a16f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a16f8:	a0400008 */ 	sb	$zero,0x8($v0)
.L0f0a16fc:
/*  f0a16fc:	10200004 */ 	beqz	$at,.L0f0a1710
/*  f0a1700:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1704:	1a000002 */ 	blez	$s0,.L0f0a1710
/*  f0a1708:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a170c:	a2b01581 */ 	sb	$s0,0x1581($s5)
.L0f0a1710:
/*  f0a1710:	52200006 */ 	beqzl	$s1,.L0f0a172c
/*  f0a1714:	92b81583 */ 	lbu	$t8,0x1583($s5)
/*  f0a1718:	92ae1583 */ 	lbu	$t6,0x1583($s5)
/*  f0a171c:	35cf0040 */ 	ori	$t7,$t6,0x40
/*  f0a1720:	10000004 */ 	beqz	$zero,.L0f0a1734
/*  f0a1724:	a2af1583 */ 	sb	$t7,0x1583($s5)
/*  f0a1728:	92b81583 */ 	lbu	$t8,0x1583($s5)
.L0f0a172c:
/*  f0a172c:	3319ffbf */ 	andi	$t9,$t8,0xffbf
/*  f0a1730:	a2b91583 */ 	sb	$t9,0x1583($s5)
.L0f0a1734:
/*  f0a1734:	8ca30284 */ 	lw	$v1,0x284($a1)
/*  f0a1738:	240affff */ 	addiu	$t2,$zero,-1
/*  f0a173c:	4480a000 */ 	mtc1	$zero,$f20
/*  f0a1740:	90681583 */ 	lbu	$t0,0x1583($v1)
/*  f0a1744:	00008825 */ 	or	$s1,$zero,$zero
/*  f0a1748:	02a08025 */ 	or	$s0,$s5,$zero
/*  f0a174c:	3109ffdf */ 	andi	$t1,$t0,0xffdf
/*  f0a1750:	a0691583 */ 	sb	$t1,0x1583($v1)
/*  f0a1754:	8cab0284 */ 	lw	$t3,0x284($a1)
/*  f0a1758:	00009025 */ 	or	$s2,$zero,$zero
/*  f0a175c:	26b309e0 */ 	addiu	$s3,$s5,0x9e0
/*  f0a1760:	a56a024e */ 	sh	$t2,0x24e($t3)
.L0f0a1764:
/*  f0a1764:	920c0d0e */ 	lbu	$t4,0xd0e($s0)
/*  f0a1768:	92180d0f */ 	lbu	$t8,0xd0f($s0)
/*  f0a176c:	e6140874 */ 	swc1	$f20,0x874($s0)
/*  f0a1770:	318eff0f */ 	andi	$t6,$t4,0xff0f
/*  f0a1774:	3308ffdf */ 	andi	$t0,$t8,0xffdf
/*  f0a1778:	a20e0d0e */ 	sb	$t6,0xd0e($s0)
/*  f0a177c:	31cf00f1 */ 	andi	$t7,$t6,0xf1
/*  f0a1780:	a2080d0f */ 	sb	$t0,0xd0f($s0)
/*  f0a1784:	310900ef */ 	andi	$t1,$t0,0xef
/*  f0a1788:	a20f0d0e */ 	sb	$t7,0xd0e($s0)
/*  f0a178c:	a2090d0f */ 	sb	$t1,0xd0f($s0)
/*  f0a1790:	e6140878 */ 	swc1	$f20,0x878($s0)
/*  f0a1794:	e614087c */ 	swc1	$f20,0x87c($s0)
/*  f0a1798:	e6140868 */ 	swc1	$f20,0x868($s0)
/*  f0a179c:	e6140db8 */ 	swc1	$f20,0xdb8($s0)
/*  f0a17a0:	ae000b90 */ 	sw	$zero,0xb90($s0)
/*  f0a17a4:	e6140888 */ 	swc1	$f20,0x888($s0)
/*  f0a17a8:	ae00080c */ 	sw	$zero,0x80c($s0)
/*  f0a17ac:	ae000810 */ 	sw	$zero,0x810($s0)
/*  f0a17b0:	a200063b */ 	sb	$zero,0x63b($s0)
/*  f0a17b4:	828a0000 */ 	lb	$t2,0x0($s4)
/*  f0a17b8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0a17bc:	a20a0638 */ 	sb	$t2,0x638($s0)
/*  f0a17c0:	928b0068 */ 	lbu	$t3,0x68($s4)
/*  f0a17c4:	e6140d08 */ 	swc1	$f20,0xd08($s0)
/*  f0a17c8:	024b6007 */ 	srav	$t4,$t3,$s2
/*  f0a17cc:	318d000f */ 	andi	$t5,$t4,0xf
/*  f0a17d0:	0fc2af4c */ 	jal	func0f0abd30
/*  f0a17d4:	a20d0639 */ 	sb	$t5,0x639($s0)
/*  f0a17d8:	0c008c28 */ 	jal	func000230a0
/*  f0a17dc:	02602025 */ 	or	$a0,$s3,$zero
/*  f0a17e0:	8e040d84 */ 	lw	$a0,0xd84($s0)
/*  f0a17e4:	50800008 */ 	beqzl	$a0,.L0f0a1808
/*  f0a17e8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0a17ec:	0c00cdfc */ 	jal	func000337f0
/*  f0a17f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a17f4:	50400004 */ 	beqzl	$v0,.L0f0a1808
/*  f0a17f8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0a17fc:	0c00cec9 */ 	jal	func00033b24
/*  f0a1800:	8e040d84 */ 	lw	$a0,0xd84($s0)
/*  f0a1804:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f0a1808:
/*  f0a1808:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a180c:	261007a4 */ 	addiu	$s0,$s0,0x7a4
/*  f0a1810:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f0a1814:	1621ffd3 */ 	bne	$s1,$at,.L0f0a1764
/*  f0a1818:	267307a4 */ 	addiu	$s3,$s3,0x7a4
/*  f0a181c:	0fc44bdc */ 	jal	func0f112f70
/*  f0a1820:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1824:	82820000 */ 	lb	$v0,0x0($s4)
/*  f0a1828:	240effff */ 	addiu	$t6,$zero,-1
/*  f0a182c:	24010040 */ 	addiu	$at,$zero,0x40
/*  f0a1830:	a28e0002 */ 	sb	$t6,0x2($s4)
/*  f0a1834:	10410004 */ 	beq	$v0,$at,.L0f0a1848
/*  f0a1838:	a2800067 */ 	sb	$zero,0x67($s4)
/*  f0a183c:	24010041 */ 	addiu	$at,$zero,0x41
/*  f0a1840:	54410027 */ 	bnel	$v0,$at,.L0f0a18e0
/*  f0a1844:	92990003 */ 	lbu	$t9,0x3($s4)
.L0f0a1848:
/*  f0a1848:	8eaf00bc */ 	lw	$t7,0xbc($s5)
/*  f0a184c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a1850:	44812000 */ 	mtc1	$at,$f4
/*  f0a1854:	8df00004 */ 	lw	$s0,0x4($t7)
/*  f0a1858:	3c048009 */ 	lui	$a0,0x8009
/*  f0a185c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0a1860:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0a1864:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0a1868:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0a186c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0a1870:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0a1874:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0a1878:	2405042e */ 	addiu	$a1,$zero,0x42e
/*  f0a187c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0a1880:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a1884:	0c004241 */ 	jal	func00010904
/*  f0a1888:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0a188c:	3c03800a */ 	lui	$v1,0x800a
/*  f0a1890:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f0a1894:	3c010008 */ 	lui	$at,0x8
/*  f0a1898:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a189c:	906a1c50 */ 	lbu	$t2,0x1c50($v1)
/*  f0a18a0:	354b0040 */ 	ori	$t3,$t2,0x40
/*  f0a18a4:	a06b1c50 */ 	sb	$t3,0x1c50($v1)
/*  f0a18a8:	8e0c0014 */ 	lw	$t4,0x14($s0)
/*  f0a18ac:	01816825 */ 	or	$t5,$t4,$at
/*  f0a18b0:	ae0d0014 */ 	sw	$t5,0x14($s0)
/*  f0a18b4:	8dcea474 */ 	lw	$t6,-0x5b8c($t6)
/*  f0a18b8:	24010035 */ 	addiu	$at,$zero,0x35
/*  f0a18bc:	35b81000 */ 	ori	$t8,$t5,0x1000
/*  f0a18c0:	15c10002 */ 	bne	$t6,$at,.L0f0a18cc
/*  f0a18c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a18c8:	ae180014 */ 	sw	$t8,0x14($s0)
.L0f0a18cc:
/*  f0a18cc:	0fc447a9 */ 	jal	func0f111ea4
/*  f0a18d0:	82840000 */ 	lb	$a0,0x0($s4)
/*  f0a18d4:	0fc2870b */ 	jal	func0f0a1c2c
/*  f0a18d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a18dc:	92990003 */ 	lbu	$t9,0x3($s4)
.L0f0a18e0:
/*  f0a18e0:	a680006c */ 	sh	$zero,0x6c($s4)
/*  f0a18e4:	a280006e */ 	sb	$zero,0x6e($s4)
/*  f0a18e8:	3328fff7 */ 	andi	$t0,$t9,0xfff7
/*  f0a18ec:	10000015 */ 	beqz	$zero,.L0f0a1944
/*  f0a18f0:	a2880003 */ 	sb	$t0,0x3($s4)
/*  f0a18f4:	82a20de4 */ 	lb	$v0,0xde4($s5)
.L0f0a18f8:
/*  f0a18f8:	10400004 */ 	beqz	$v0,.L0f0a190c
/*  f0a18fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1900:	82aa1583 */ 	lb	$t2,0x1583($s5)
/*  f0a1904:	05410006 */ 	bgez	$t2,.L0f0a1920
/*  f0a1908:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a190c:
/*  f0a190c:	5440000e */ 	bnezl	$v0,.L0f0a1948
/*  f0a1910:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0a1914:	82ac1583 */ 	lb	$t4,0x1583($s5)
/*  f0a1918:	0583000b */ 	bgezl	$t4,.L0f0a1948
/*  f0a191c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f0a1920:
/*  f0a1920:	0fc26fb2 */ 	jal	func0f09bec8
/*  f0a1924:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a1928:	50400007 */ 	beqzl	$v0,.L0f0a1948
/*  f0a192c:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0a1930:	0fc284d3 */ 	jal	func0f0a134c
/*  f0a1934:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a1938:	92ad1583 */ 	lbu	$t5,0x1583($s5)
/*  f0a193c:	000d71c2 */ 	srl	$t6,$t5,0x7
/*  f0a1940:	a2ae0de4 */ 	sb	$t6,0xde4($s5)
.L0f0a1944:
/*  f0a1944:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f0a1948:
/*  f0a1948:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0a194c:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f0a1950:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f0a1954:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f0a1958:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f0a195c:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f0a1960:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f0a1964:	03e00008 */ 	jr	$ra
/*  f0a1968:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel currentPlayerEquipWeaponInCutscene
/*  f0a196c:	3c02800a */ 	lui	$v0,0x800a
/*  f0a1970:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a1974:	804e1580 */ 	lb	$t6,0x1580($v0)
/*  f0a1978:	548e0006 */ 	bnel	$a0,$t6,.L0f0a1994
/*  f0a197c:	90581583 */ 	lbu	$t8,0x1583($v0)
/*  f0a1980:	804f1582 */ 	lb	$t7,0x1582($v0)
/*  f0a1984:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0a1988:	11e10005 */ 	beq	$t7,$at,.L0f0a19a0
/*  f0a198c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1990:	90581583 */ 	lbu	$t8,0x1583($v0)
.L0f0a1994:
/*  f0a1994:	a0441582 */ 	sb	$a0,0x1582($v0)
/*  f0a1998:	3319fffb */ 	andi	$t9,$t8,0xfffb
/*  f0a199c:	a0591583 */ 	sb	$t9,0x1583($v0)
.L0f0a19a0:
/*  f0a19a0:	03e00008 */ 	jr	$ra
/*  f0a19a4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel getCurrentPlayerWeaponId
/*  f0a19a8:	00047100 */ 	sll	$t6,$a0,0x4
/*  f0a19ac:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f0a19b0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0a19b4:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f0a19b8:	3c03800a */ 	lui	$v1,0x800a
/*  f0a19bc:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f0a19c0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0a19c4:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f0a19c8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0a19cc:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f0a19d0:	81f80640 */ 	lb	$t8,0x640($t7)
/*  f0a19d4:	57000004 */ 	bnezl	$t8,.L0f0a19e8
/*  f0a19d8:	80621580 */ 	lb	$v0,0x1580($v1)
/*  f0a19dc:	03e00008 */ 	jr	$ra
/*  f0a19e0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a19e4:	80621580 */ 	lb	$v0,0x1580($v1)
.L0f0a19e8:
/*  f0a19e8:	03e00008 */ 	jr	$ra
/*  f0a19ec:	00000000 */ 	sll	$zero,$zero,0x0
);

u32 getCurrentPlayerWeaponIdWrapper(u32 arg0)
{
	return getCurrentPlayerWeaponId(arg0);
}

GLOBAL_ASM(
glabel func0f0a1a10
/*  f0a1a10:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a1a14:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a1a18:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0a1a1c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a1a20:	24050400 */ 	addiu	$a1,$zero,0x400
/*  f0a1a24:	1040000b */ 	beqz	$v0,.L0f0a1a54
/*  f0a1a28:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0a1a2c:	0fc2a685 */ 	jal	func0f0a9a14
/*  f0a1a30:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a1a34:	10400005 */ 	beqz	$v0,.L0f0a1a4c
/*  f0a1a38:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0a1a3c:	0fc2a69d */ 	jal	func0f0a9a74
/*  f0a1a40:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a1a44:	58400004 */ 	blezl	$v0,.L0f0a1a58
/*  f0a1a48:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a1a4c:
/*  f0a1a4c:	10000002 */ 	beqz	$zero,.L0f0a1a58
/*  f0a1a50:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a1a54:
/*  f0a1a54:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a1a58:
/*  f0a1a58:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a1a5c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a1a60:	03e00008 */ 	jr	$ra
/*  f0a1a64:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a1a68
/*  f0a1a68:	3c02800a */ 	lui	$v0,0x800a
/*  f0a1a6c:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a1a70:	00802825 */ 	or	$a1,$a0,$zero
/*  f0a1a74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a1a78:	80431582 */ 	lb	$v1,0x1582($v0)
/*  f0a1a7c:	04620004 */ 	bltzl	$v1,.L0f0a1a90
/*  f0a1a80:	80441580 */ 	lb	$a0,0x1580($v0)
/*  f0a1a84:	10000002 */ 	beqz	$zero,.L0f0a1a90
/*  f0a1a88:	00602025 */ 	or	$a0,$v1,$zero
/*  f0a1a8c:	80441580 */ 	lb	$a0,0x1580($v0)
.L0f0a1a90:
/*  f0a1a90:	804f1583 */ 	lb	$t7,0x1583($v0)
/*  f0a1a94:	05e00004 */ 	bltz	$t7,.L0f0a1aa8
/*  f0a1a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1a9c:	14a10002 */ 	bne	$a1,$at,.L0f0a1aa8
/*  f0a1aa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1aa4:	00002025 */ 	or	$a0,$zero,$zero
.L0f0a1aa8:
/*  f0a1aa8:	03e00008 */ 	jr	$ra
/*  f0a1aac:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel func0f0a1ab0
/*  f0a1ab0:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0a1ab4:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0a1ab8:	8c4e02ac */ 	lw	$t6,0x2ac($v0)
/*  f0a1abc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0a1ac0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a1ac4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0a1ac8:	11c1001c */ 	beq	$t6,$at,.L0f0a1b3c
/*  f0a1acc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a1ad0:	8c500284 */ 	lw	$s0,0x284($v0)
/*  f0a1ad4:	0fc44727 */ 	jal	func0f111c9c
/*  f0a1ad8:	82041581 */ 	lb	$a0,0x1581($s0)
/*  f0a1adc:	10400015 */ 	beqz	$v0,.L0f0a1b34
/*  f0a1ae0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a1ae4:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f0a1ae8:	82051581 */ 	lb	$a1,0x1581($s0)
/*  f0a1aec:	82041581 */ 	lb	$a0,0x1581($s0)
/*  f0a1af0:	0fc4473e */ 	jal	func0f111cf8
/*  f0a1af4:	00802825 */ 	or	$a1,$a0,$zero
/*  f0a1af8:	820f1581 */ 	lb	$t7,0x1581($s0)
/*  f0a1afc:	8e191580 */ 	lw	$t9,0x1580($s0)
/*  f0a1b00:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a1b04:	004f0019 */ 	multu	$v0,$t7
/*  f0a1b08:	00194640 */ 	sll	$t0,$t9,0x19
/*  f0a1b0c:	00084fc2 */ 	srl	$t1,$t0,0x1f
/*  f0a1b10:	0000c012 */ 	mflo	$t8
/*  f0a1b14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1b18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1b1c:	03090019 */ 	multu	$t8,$t1
/*  f0a1b20:	00002812 */ 	mflo	$a1
/*  f0a1b24:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f0a1b28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1b2c:	10000004 */ 	beqz	$zero,.L0f0a1b40
/*  f0a1b30:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0a1b34:
/*  f0a1b34:	0fc2877d */ 	jal	func0f0a1df4
/*  f0a1b38:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a1b3c:
/*  f0a1b3c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0a1b40:
/*  f0a1b40:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a1b44:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0a1b48:	03e00008 */ 	jr	$ra
/*  f0a1b4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a1b50
/*  f0a1b50:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0a1b54:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0a1b58:	8c4e02ac */ 	lw	$t6,0x2ac($v0)
/*  f0a1b5c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0a1b60:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a1b64:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a1b68:	11c1002c */ 	beq	$t6,$at,.L0f0a1c1c
/*  f0a1b6c:	8c430284 */ 	lw	$v1,0x284($v0)
/*  f0a1b70:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a1b74:	0fc2869a */ 	jal	func0f0a1a68
/*  f0a1b78:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0a1b7c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0a1b80:	0fc2869a */ 	jal	func0f0a1a68
/*  f0a1b84:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a1b88:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f0a1b8c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0a1b90:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0a1b94:	29e1002d */ 	slti	$at,$t7,0x2d
/*  f0a1b98:	10200003 */ 	beqz	$at,.L0f0a1ba8
/*  f0a1b9c:	2841002d */ 	slti	$at,$v0,0x2d
/*  f0a1ba0:	1420000c */ 	bnez	$at,.L0f0a1bd4
/*  f0a1ba4:	27a40024 */ 	addiu	$a0,$sp,0x24
.L0f0a1ba8:
/*  f0a1ba8:	80781581 */ 	lb	$t8,0x1581($v1)
/*  f0a1bac:	afb80024 */ 	sw	$t8,0x24($sp)
/*  f0a1bb0:	8c681580 */ 	lw	$t0,0x1580($v1)
/*  f0a1bb4:	80791581 */ 	lb	$t9,0x1581($v1)
/*  f0a1bb8:	00084e40 */ 	sll	$t1,$t0,0x19
/*  f0a1bbc:	000957c2 */ 	srl	$t2,$t1,0x1f
/*  f0a1bc0:	032a0019 */ 	multu	$t9,$t2
/*  f0a1bc4:	00005812 */ 	mflo	$t3
/*  f0a1bc8:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0a1bcc:	10000007 */ 	beqz	$zero,.L0f0a1bec
/*  f0a1bd0:	8fac0020 */ 	lw	$t4,0x20($sp)
.L0f0a1bd4:
/*  f0a1bd4:	27a50020 */ 	addiu	$a1,$sp,0x20
/*  f0a1bd8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0a1bdc:	0fc448bb */ 	jal	func0f1122ec
/*  f0a1be0:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0a1be4:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0a1be8:	8fac0020 */ 	lw	$t4,0x20($sp)
.L0f0a1bec:
/*  f0a1bec:	8fad0024 */ 	lw	$t5,0x24($sp)
/*  f0a1bf0:	518d0006 */ 	beql	$t4,$t5,.L0f0a1c0c
/*  f0a1bf4:	90681583 */ 	lbu	$t0,0x1583($v1)
/*  f0a1bf8:	906e1583 */ 	lbu	$t6,0x1583($v1)
/*  f0a1bfc:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f0a1c00:	10000004 */ 	beqz	$zero,.L0f0a1c14
/*  f0a1c04:	a06f1583 */ 	sb	$t7,0x1583($v1)
/*  f0a1c08:	90681583 */ 	lbu	$t0,0x1583($v1)
.L0f0a1c0c:
/*  f0a1c0c:	35090080 */ 	ori	$t1,$t0,0x80
/*  f0a1c10:	a0691583 */ 	sb	$t1,0x1583($v1)
.L0f0a1c14:
/*  f0a1c14:	0fc2865b */ 	jal	currentPlayerEquipWeaponInCutscene
/*  f0a1c18:	8fa40024 */ 	lw	$a0,0x24($sp)
.L0f0a1c1c:
/*  f0a1c1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a1c20:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0a1c24:	03e00008 */ 	jr	$ra
/*  f0a1c28:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a1c2c
/*  f0a1c2c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0a1c30:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0a1c34:	8c4e02ac */ 	lw	$t6,0x2ac($v0)
/*  f0a1c38:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0a1c3c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a1c40:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a1c44:	11c1002f */ 	beq	$t6,$at,.L0f0a1d04
/*  f0a1c48:	8c430284 */ 	lw	$v1,0x284($v0)
/*  f0a1c4c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a1c50:	0fc2869a */ 	jal	func0f0a1a68
/*  f0a1c54:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0a1c58:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0a1c5c:	0fc2869a */ 	jal	func0f0a1a68
/*  f0a1c60:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a1c64:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0a1c68:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0a1c6c:	14410002 */ 	bne	$v0,$at,.L0f0a1c78
/*  f0a1c70:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0a1c74:	afa00020 */ 	sw	$zero,0x20($sp)
.L0f0a1c78:
/*  f0a1c78:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f0a1c7c:	8fb80020 */ 	lw	$t8,0x20($sp)
/*  f0a1c80:	29e1002d */ 	slti	$at,$t7,0x2d
/*  f0a1c84:	10200003 */ 	beqz	$at,.L0f0a1c94
/*  f0a1c88:	2b01002d */ 	slti	$at,$t8,0x2d
/*  f0a1c8c:	1420000c */ 	bnez	$at,.L0f0a1cc0
/*  f0a1c90:	27a40024 */ 	addiu	$a0,$sp,0x24
.L0f0a1c94:
/*  f0a1c94:	80791581 */ 	lb	$t9,0x1581($v1)
/*  f0a1c98:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f0a1c9c:	8c691580 */ 	lw	$t1,0x1580($v1)
/*  f0a1ca0:	80681581 */ 	lb	$t0,0x1581($v1)
/*  f0a1ca4:	00095640 */ 	sll	$t2,$t1,0x19
/*  f0a1ca8:	000a5fc2 */ 	srl	$t3,$t2,0x1f
/*  f0a1cac:	010b0019 */ 	multu	$t0,$t3
/*  f0a1cb0:	00006012 */ 	mflo	$t4
/*  f0a1cb4:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0a1cb8:	10000007 */ 	beqz	$zero,.L0f0a1cd8
/*  f0a1cbc:	8fad0020 */ 	lw	$t5,0x20($sp)
.L0f0a1cc0:
/*  f0a1cc0:	27a50020 */ 	addiu	$a1,$sp,0x20
/*  f0a1cc4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0a1cc8:	0fc4494f */ 	jal	func0f11253c
/*  f0a1ccc:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0a1cd0:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0a1cd4:	8fad0020 */ 	lw	$t5,0x20($sp)
.L0f0a1cd8:
/*  f0a1cd8:	55a00006 */ 	bnezl	$t5,.L0f0a1cf4
/*  f0a1cdc:	90791583 */ 	lbu	$t9,0x1583($v1)
/*  f0a1ce0:	906e1583 */ 	lbu	$t6,0x1583($v1)
/*  f0a1ce4:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f0a1ce8:	10000004 */ 	beqz	$zero,.L0f0a1cfc
/*  f0a1cec:	a06f1583 */ 	sb	$t7,0x1583($v1)
/*  f0a1cf0:	90791583 */ 	lbu	$t9,0x1583($v1)
.L0f0a1cf4:
/*  f0a1cf4:	37290080 */ 	ori	$t1,$t9,0x80
/*  f0a1cf8:	a0691583 */ 	sb	$t1,0x1583($v1)
.L0f0a1cfc:
/*  f0a1cfc:	0fc2865b */ 	jal	currentPlayerEquipWeaponInCutscene
/*  f0a1d00:	8fa40024 */ 	lw	$a0,0x24($sp)
.L0f0a1d04:
/*  f0a1d04:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a1d08:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0a1d0c:	03e00008 */ 	jr	$ra
/*  f0a1d10:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a1d14
/*  f0a1d14:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0a1d18:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0a1d1c:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0a1d20:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0a1d24:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0a1d28:	00809825 */ 	or	$s3,$a0,$zero
/*  f0a1d2c:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0a1d30:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0a1d34:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0a1d38:	00009025 */ 	or	$s2,$zero,$zero
/*  f0a1d3c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a1d40:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0a1d44:	14400003 */ 	bnez	$v0,.L0f0a1d54
/*  f0a1d48:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0a1d4c:	10000020 */ 	beqz	$zero,.L0f0a1dd0
/*  f0a1d50:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a1d54:
/*  f0a1d54:	00008025 */ 	or	$s0,$zero,$zero
/*  f0a1d58:	24110002 */ 	addiu	$s1,$zero,0x2
/*  f0a1d5c:	02602025 */ 	or	$a0,$s3,$zero
.L0f0a1d60:
/*  f0a1d60:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f0a1d64:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a1d68:	5040000f */ 	beqzl	$v0,.L0f0a1da8
/*  f0a1d6c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0a1d70:	80440007 */ 	lb	$a0,0x7($v0)
/*  f0a1d74:	0480000b */ 	bltz	$a0,.L0f0a1da4
/*  f0a1d78:	00047080 */ 	sll	$t6,$a0,0x2
/*  f0a1d7c:	028e7821 */ 	addu	$t7,$s4,$t6
/*  f0a1d80:	8de3001c */ 	lw	$v1,0x1c($t7)
/*  f0a1d84:	50600008 */ 	beqzl	$v1,.L0f0a1da8
/*  f0a1d88:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0a1d8c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0a1d90:	0fc2a61a */ 	jal	currentPlayerGetAmmoCount
/*  f0a1d94:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f0a1d98:	58400003 */ 	blezl	$v0,.L0f0a1da8
/*  f0a1d9c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0a1da0:	24150001 */ 	addiu	$s5,$zero,0x1
.L0f0a1da4:
/*  f0a1da4:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0a1da8:
/*  f0a1da8:	5611ffed */ 	bnel	$s0,$s1,.L0f0a1d60
/*  f0a1dac:	02602025 */ 	or	$a0,$s3,$zero
/*  f0a1db0:	16400003 */ 	bnez	$s2,.L0f0a1dc0
/*  f0a1db4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a1db8:	10000005 */ 	beqz	$zero,.L0f0a1dd0
/*  f0a1dbc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a1dc0:
/*  f0a1dc0:	16a10003 */ 	bne	$s5,$at,.L0f0a1dd0
/*  f0a1dc4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a1dc8:	10000001 */ 	beqz	$zero,.L0f0a1dd0
/*  f0a1dcc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a1dd0:
/*  f0a1dd0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0a1dd4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0a1dd8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0a1ddc:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0a1de0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0a1de4:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0a1de8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0a1dec:	03e00008 */ 	jr	$ra
/*  f0a1df0:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f0a1df4
/*  f0a1df4:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0a1df8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a1dfc:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a1e00:	8c6f0284 */ 	lw	$t7,0x284($v1)
/*  f0a1e04:	240effff */ 	addiu	$t6,$zero,-1
/*  f0a1e08:	8c7902ac */ 	lw	$t9,0x2ac($v1)
/*  f0a1e0c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0a1e10:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0a1e14:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0a1e18:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0a1e1c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0a1e20:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0a1e24:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0a1e28:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0a1e2c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0a1e30:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a1e34:	afae0050 */ 	sw	$t6,0x50($sp)
/*  f0a1e38:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f0a1e3c:	81f81580 */ 	lb	$t8,0x1580($t7)
/*  f0a1e40:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a1e44:	241effff */ 	addiu	$s8,$zero,-1
/*  f0a1e48:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0a1e4c:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f0a1e50:	13210083 */ 	beq	$t9,$at,.L0f0a2060
/*  f0a1e54:	afb80044 */ 	sw	$t8,0x44($sp)
/*  f0a1e58:	3c138007 */ 	lui	$s3,%hi(var800701c0)
/*  f0a1e5c:	267301c0 */ 	addiu	$s3,$s3,%lo(var800701c0)
/*  f0a1e60:	3c170010 */ 	lui	$s7,0x10
/*  f0a1e64:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f0a1e68:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0a1e6c:
/*  f0a1e6c:	0fc44727 */ 	jal	func0f111c9c
/*  f0a1e70:	92640000 */ 	lbu	$a0,0x0($s3)
/*  f0a1e74:	10400031 */ 	beqz	$v0,.L0f0a1f3c
/*  f0a1e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1e7c:	92700000 */ 	lbu	$s0,0x0($s3)
/*  f0a1e80:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a1e84:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a1e88:	00409025 */ 	or	$s2,$v0,$zero
/*  f0a1e8c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a1e90:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f0a1e94:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a1e98:	00408825 */ 	or	$s1,$v0,$zero
/*  f0a1e9c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a1ea0:	0fc2642c */ 	jal	func0f0990b0
/*  f0a1ea4:	02402825 */ 	or	$a1,$s2,$zero
/*  f0a1ea8:	14400006 */ 	bnez	$v0,.L0f0a1ec4
/*  f0a1eac:	24010012 */ 	addiu	$at,$zero,0x12
/*  f0a1eb0:	8e280010 */ 	lw	$t0,0x10($s1)
/*  f0a1eb4:	01174824 */ 	and	$t1,$t0,$s7
/*  f0a1eb8:	15200002 */ 	bnez	$t1,.L0f0a1ec4
/*  f0a1ebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1ec0:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f0a1ec4:
/*  f0a1ec4:	16010005 */ 	bne	$s0,$at,.L0f0a1edc
/*  f0a1ec8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a1ecc:	16a00003 */ 	bnez	$s5,.L0f0a1edc
/*  f0a1ed0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1ed4:	1000000e */ 	beqz	$zero,.L0f0a1f10
/*  f0a1ed8:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f0a1edc:
/*  f0a1edc:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f0a1ee0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a1ee4:	00408825 */ 	or	$s1,$v0,$zero
/*  f0a1ee8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a1eec:	0fc2642c */ 	jal	func0f0990b0
/*  f0a1ef0:	02402825 */ 	or	$a1,$s2,$zero
/*  f0a1ef4:	54400007 */ 	bnezl	$v0,.L0f0a1f14
/*  f0a1ef8:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f0a1efc:	8e2a0010 */ 	lw	$t2,0x10($s1)
/*  f0a1f00:	01575824 */ 	and	$t3,$t2,$s7
/*  f0a1f04:	55600003 */ 	bnezl	$t3,.L0f0a1f14
/*  f0a1f08:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f0a1f0c:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f0a1f10:
/*  f0a1f10:	8fac0044 */ 	lw	$t4,0x44($sp)
.L0f0a1f14:
/*  f0a1f14:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0a1f18:	160c0003 */ 	bne	$s0,$t4,.L0f0a1f28
/*  f0a1f1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1f20:	10000006 */ 	beqz	$zero,.L0f0a1f3c
/*  f0a1f24:	afad0048 */ 	sw	$t5,0x48($sp)
.L0f0a1f28:
/*  f0a1f28:	12800004 */ 	beqz	$s4,.L0f0a1f3c
/*  f0a1f2c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f0a1f30:	15d60002 */ 	bne	$t6,$s6,.L0f0a1f3c
/*  f0a1f34:	0200f025 */ 	or	$s8,$s0,$zero
/*  f0a1f38:	afb00050 */ 	sw	$s0,0x50($sp)
.L0f0a1f3c:
/*  f0a1f3c:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0a1f40:	25ef01e3 */ 	addiu	$t7,$t7,0x1e3
/*  f0a1f44:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0a1f48:	026f082b */ 	sltu	$at,$s3,$t7
/*  f0a1f4c:	50200007 */ 	beqzl	$at,.L0f0a1f6c
/*  f0a1f50:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f0a1f54:	53d6ffc5 */ 	beql	$s8,$s6,.L0f0a1e6c
/*  f0a1f58:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a1f5c:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f0a1f60:	5300ffc2 */ 	beqzl	$t8,.L0f0a1e6c
/*  f0a1f64:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a1f68:	8fb90048 */ 	lw	$t9,0x48($sp)
.L0f0a1f6c:
/*  f0a1f6c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a1f70:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a1f74:	17200002 */ 	bnez	$t9,.L0f0a1f80
/*  f0a1f78:	02c09025 */ 	or	$s2,$s6,$zero
/*  f0a1f7c:	8fbe0050 */ 	lw	$s8,0x50($sp)
.L0f0a1f80:
/*  f0a1f80:	17d60002 */ 	bne	$s8,$s6,.L0f0a1f8c
/*  f0a1f84:	3c108007 */ 	lui	$s0,%hi(var800701e4)
/*  f0a1f88:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f0a1f8c:
/*  f0a1f8c:	17c10018 */ 	bne	$s8,$at,.L0f0a1ff0
/*  f0a1f90:	261001e4 */ 	addiu	$s0,$s0,%lo(var800701e4)
/*  f0a1f94:	3c138007 */ 	lui	$s3,0x8007
/*  f0a1f98:	267301eb */ 	addiu	$s3,$s3,0x1eb
/*  f0a1f9c:	92110000 */ 	lbu	$s1,0x0($s0)
.L0f0a1fa0:
/*  f0a1fa0:	0fc44727 */ 	jal	func0f111c9c
/*  f0a1fa4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0a1fa8:	10400008 */ 	beqz	$v0,.L0f0a1fcc
/*  f0a1fac:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0a1fb0:	8fa80044 */ 	lw	$t0,0x44($sp)
/*  f0a1fb4:	16280002 */ 	bne	$s1,$t0,.L0f0a1fc0
/*  f0a1fb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1fbc:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f0a1fc0:
/*  f0a1fc0:	16560002 */ 	bne	$s2,$s6,.L0f0a1fcc
/*  f0a1fc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a1fc8:	02209025 */ 	or	$s2,$s1,$zero
.L0f0a1fcc:
/*  f0a1fcc:	5613fff4 */ 	bnel	$s0,$s3,.L0f0a1fa0
/*  f0a1fd0:	92110000 */ 	lbu	$s1,0x0($s0)
/*  f0a1fd4:	16560002 */ 	bne	$s2,$s6,.L0f0a1fe0
/*  f0a1fd8:	0240f025 */ 	or	$s8,$s2,$zero
/*  f0a1fdc:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f0a1fe0:
/*  f0a1fe0:	12800002 */ 	beqz	$s4,.L0f0a1fec
/*  f0a1fe4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0a1fe8:	241effff */ 	addiu	$s8,$zero,-1
.L0f0a1fec:
/*  f0a1fec:	afa90040 */ 	sw	$t1,0x40($sp)
.L0f0a1ff0:
/*  f0a1ff0:	07c0001b */ 	bltz	$s8,.L0f0a2060
/*  f0a1ff4:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f0a1ff8:	13ca0019 */ 	beq	$s8,$t2,.L0f0a2060
/*  f0a1ffc:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0a2000:	0fc4473e */ 	jal	func0f111cf8
/*  f0a2004:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0a2008:	10400006 */ 	beqz	$v0,.L0f0a2024
/*  f0a200c:	3c02800a */ 	lui	$v0,0x800a
/*  f0a2010:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a2014:	904c1583 */ 	lbu	$t4,0x1583($v0)
/*  f0a2018:	358d0080 */ 	ori	$t5,$t4,0x80
/*  f0a201c:	10000006 */ 	beqz	$zero,.L0f0a2038
/*  f0a2020:	a04d1583 */ 	sb	$t5,0x1583($v0)
.L0f0a2024:
/*  f0a2024:	3c02800a */ 	lui	$v0,0x800a
/*  f0a2028:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a202c:	904e1583 */ 	lbu	$t6,0x1583($v0)
/*  f0a2030:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f0a2034:	a04f1583 */ 	sb	$t7,0x1583($v0)
.L0f0a2038:
/*  f0a2038:	0fc2865b */ 	jal	currentPlayerEquipWeaponInCutscene
/*  f0a203c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0a2040:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f0a2044:	3c02800a */ 	lui	$v0,0x800a
/*  f0a2048:	53000006 */ 	beqzl	$t8,.L0f0a2064
/*  f0a204c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0a2050:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a2054:	90481583 */ 	lbu	$t0,0x1583($v0)
/*  f0a2058:	35090004 */ 	ori	$t1,$t0,0x4
/*  f0a205c:	a0491583 */ 	sb	$t1,0x1583($v0)
.L0f0a2060:
/*  f0a2060:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0a2064:
/*  f0a2064:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a2068:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0a206c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0a2070:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0a2074:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0a2078:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0a207c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0a2080:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0a2084:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0a2088:	03e00008 */ 	jr	$ra
/*  f0a208c:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel currentPlayerEquipWeapon
/*  f0a2090:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a2094:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a2098:	1481000e */ 	bne	$a0,$at,.L0f0a20d4
/*  f0a209c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a20a0:	14a00007 */ 	bnez	$a1,.L0f0a20c0
/*  f0a20a4:	3c02800a */ 	lui	$v0,0x800a
/*  f0a20a8:	3c02800a */ 	lui	$v0,0x800a
/*  f0a20ac:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a20b0:	904e1583 */ 	lbu	$t6,0x1583($v0)
/*  f0a20b4:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f0a20b8:	1000000c */ 	beqz	$zero,.L0f0a20ec
/*  f0a20bc:	a04f1583 */ 	sb	$t7,0x1583($v0)
.L0f0a20c0:
/*  f0a20c0:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a20c4:	90591583 */ 	lbu	$t9,0x1583($v0)
/*  f0a20c8:	37280080 */ 	ori	$t0,$t9,0x80
/*  f0a20cc:	10000007 */ 	beqz	$zero,.L0f0a20ec
/*  f0a20d0:	a0481583 */ 	sb	$t0,0x1583($v0)
.L0f0a20d4:
/*  f0a20d4:	28a1005e */ 	slti	$at,$a1,0x5e
/*  f0a20d8:	14200002 */ 	bnez	$at,.L0f0a20e4
/*  f0a20dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a20e0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0a20e4:
/*  f0a20e4:	0fc2865b */ 	jal	currentPlayerEquipWeaponInCutscene
/*  f0a20e8:	00a02025 */ 	or	$a0,$a1,$zero
.L0f0a20ec:
/*  f0a20ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a20f0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a20f4:	03e00008 */ 	jr	$ra
/*  f0a20f8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a20fc
/*  f0a20fc:	00047900 */ 	sll	$t7,$a0,0x4
/*  f0a2100:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f0a2104:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a2108:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f0a210c:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a2110:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a2114:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0a2118:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f0a211c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a2120:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0a2124:	03e00008 */ 	jr	$ra
/*  f0a2128:	8302063c */ 	lb	$v0,0x63c($t8)
);

GLOBAL_ASM(
glabel func0f0a212c
/*  f0a212c:	00047900 */ 	sll	$t7,$a0,0x4
/*  f0a2130:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f0a2134:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a2138:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f0a213c:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a2140:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a2144:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0a2148:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f0a214c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a2150:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0a2154:	03e00008 */ 	jr	$ra
/*  f0a2158:	8f020ce4 */ 	lw	$v0,0xce4($t8)
);

GLOBAL_ASM(
glabel func0f0a215c
/*  f0a215c:	00047080 */ 	sll	$t6,$a0,0x2
/*  f0a2160:	3c028007 */ 	lui	$v0,0x8007
/*  f0a2164:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f0a2168:	8c42ff18 */ 	lw	$v0,-0xe8($v0)
/*  f0a216c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a2170:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a2174:	10400005 */ 	beqz	$v0,.L0f0a218c
/*  f0a2178:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a217c:	0fc5b9f1 */ 	jal	langGet
/*  f0a2180:	94440046 */ 	lhu	$a0,0x46($v0)
/*  f0a2184:	10000004 */ 	beqz	$zero,.L0f0a2198
/*  f0a2188:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0a218c:
/*  f0a218c:	3c027f1b */ 	lui	$v0,0x7f1b
/*  f0a2190:	2442c158 */ 	addiu	$v0,$v0,-16040
/*  f0a2194:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0a2198:
/*  f0a2198:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a219c:	03e00008 */ 	jr	$ra
/*  f0a21a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a21a4
/*  f0a21a4:	00047080 */ 	sll	$t6,$a0,0x2
/*  f0a21a8:	3c038007 */ 	lui	$v1,0x8007
/*  f0a21ac:	006e1821 */ 	addu	$v1,$v1,$t6
/*  f0a21b0:	8c63ff18 */ 	lw	$v1,-0xe8($v1)
/*  f0a21b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a21b8:	10600003 */ 	beqz	$v1,.L0f0a21c8
/*  f0a21bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a21c0:	03e00008 */ 	jr	$ra
/*  f0a21c4:	94620046 */ 	lhu	$v0,0x46($v1)
.L0f0a21c8:
/*  f0a21c8:	03e00008 */ 	jr	$ra
/*  f0a21cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a21d0
/*  f0a21d0:	00047080 */ 	sll	$t6,$a0,0x2
/*  f0a21d4:	3c028007 */ 	lui	$v0,0x8007
/*  f0a21d8:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f0a21dc:	8c42ff18 */ 	lw	$v0,-0xe8($v0)
/*  f0a21e0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a21e4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a21e8:	10400005 */ 	beqz	$v0,.L0f0a2200
/*  f0a21ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a21f0:	0fc5b9f1 */ 	jal	langGet
/*  f0a21f4:	94440044 */ 	lhu	$a0,0x44($v0)
/*  f0a21f8:	10000004 */ 	beqz	$zero,.L0f0a220c
/*  f0a21fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0a2200:
/*  f0a2200:	3c027f1b */ 	lui	$v0,0x7f1b
/*  f0a2204:	2442c164 */ 	addiu	$v0,$v0,-16028
/*  f0a2208:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0a220c:
/*  f0a220c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a2210:	03e00008 */ 	jr	$ra
/*  f0a2214:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a2218
/*  f0a2218:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a221c:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a2220:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0a2224:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a2228:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0a222c:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0a2230:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0a2234:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a2238:	0fc2a685 */ 	jal	func0f0a9a14
/*  f0a223c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a2240:	1040000f */ 	beqz	$v0,.L0f0a2280
/*  f0a2244:	8fb80020 */ 	lw	$t8,0x20($sp)
/*  f0a2248:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0a224c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0a2250:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0a2254:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0a2258:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f0a225c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0a2260:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0a2264:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0a2268:	01f91021 */ 	addu	$v0,$t7,$t9
/*  f0a226c:	8c48065c */ 	lw	$t0,0x65c($v0)
/*  f0a2270:	24090009 */ 	addiu	$t1,$zero,0x9
/*  f0a2274:	55000003 */ 	bnezl	$t0,.L0f0a2284
/*  f0a2278:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a227c:	ac49065c */ 	sw	$t1,0x65c($v0)
.L0f0a2280:
/*  f0a2280:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0a2284:
/*  f0a2284:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0a2288:	03e00008 */ 	jr	$ra
/*  f0a228c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a2290
/*  f0a2290:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0a2294:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a2298:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a229c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a22a0:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f0a22a4:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*  f0a22a8:	0c0068f4 */ 	jal	func0001a3d0
/*  f0a22ac:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0a22b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a22b4:	44812000 */ 	mtc1	$at,$f4
/*  f0a22b8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0a22bc:	44814000 */ 	mtc1	$at,$f8
/*  f0a22c0:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0a22c4:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f0a22c8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0a22cc:	e5ea07f0 */ 	swc1	$f10,0x7f0($t7)
/*  f0a22d0:	0c0068f4 */ 	jal	func0001a3d0
/*  f0a22d4:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*  f0a22d8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a22dc:	44818000 */ 	mtc1	$at,$f16
/*  f0a22e0:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0a22e4:	44812000 */ 	mtc1	$at,$f4
/*  f0a22e8:	46008481 */ 	sub.s	$f18,$f16,$f0
/*  f0a22ec:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f0a22f0:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0a22f4:	e7060f94 */ 	swc1	$f6,0xf94($t8)
/*  f0a22f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a22fc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0a2300:	03e00008 */ 	jr	$ra
/*  f0a2304:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a2308
/*  f0a2308:	0004c100 */ 	sll	$t8,$a0,0x4
/*  f0a230c:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f0a2310:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0a2314:	0304c021 */ 	addu	$t8,$t8,$a0
/*  f0a2318:	3c0f800a */ 	lui	$t7,0x800a
/*  f0a231c:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f0a2320:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0a2324:	0304c021 */ 	addu	$t8,$t8,$a0
/*  f0a2328:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0a232c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0a2330:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0a2334:	03e00008 */ 	jr	$ra
/*  f0a2338:	af2e084c */ 	sw	$t6,0x84c($t9)
);

GLOBAL_ASM(
glabel func0f0a233c
/*  f0a233c:	44801000 */ 	mtc1	$zero,$f2
/*  f0a2340:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0a2344:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a2348:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0a234c:	0fc2c43b */ 	jal	func0f0b10ec
/*  f0a2350:	e7a2002c */ 	swc1	$f2,0x2c($sp)
/*  f0a2354:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0a2358:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0a235c:	c7a2002c */ 	lwc1	$f2,0x2c($sp)
/*  f0a2360:	10400007 */ 	beqz	$v0,.L0f0a2380
/*  f0a2364:	8cc40284 */ 	lw	$a0,0x284($a2)
/*  f0a2368:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f0a236c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a2370:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0a2374:	55e10003 */ 	bnel	$t7,$at,.L0f0a2384
/*  f0a2378:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f0a237c:	c4420030 */ 	lwc1	$f2,0x30($v0)
.L0f0a2380:
/*  f0a2380:	8fb80030 */ 	lw	$t8,0x30($sp)
.L0f0a2384:
/*  f0a2384:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0a2388:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0a238c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0a2390:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0a2394:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0a2398:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0a239c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0a23a0:	00991821 */ 	addu	$v1,$a0,$t9
/*  f0a23a4:	8c68084c */ 	lw	$t0,0x84c($v1)
/*  f0a23a8:	51000017 */ 	beqzl	$t0,.L0f0a2408
/*  f0a23ac:	8c690858 */ 	lw	$t1,0x858($v1)
/*  f0a23b0:	c4600848 */ 	lwc1	$f0,0x848($v1)
/*  f0a23b4:	3c013e80 */ 	lui	$at,0x3e80
/*  f0a23b8:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0a23bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a23c0:	4502000a */ 	bc1fl	.L0f0a23ec
/*  f0a23c4:	4600103e */ 	c.le.s	$f2,$f0
/*  f0a23c8:	44812000 */ 	mtc1	$at,$f4
/*  f0a23cc:	c4c8004c */ 	lwc1	$f8,0x4c($a2)
/*  f0a23d0:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f0a23d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a23d8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0a23dc:	460a0400 */ 	add.s	$f16,$f0,$f10
/*  f0a23e0:	e4700848 */ 	swc1	$f16,0x848($v1)
/*  f0a23e4:	c4600848 */ 	lwc1	$f0,0x848($v1)
/*  f0a23e8:	4600103e */ 	c.le.s	$f2,$f0
.L0f0a23ec:
/*  f0a23ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a23f0:	45020026 */ 	bc1fl	.L0f0a248c
/*  f0a23f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a23f8:	e4620848 */ 	swc1	$f2,0x848($v1)
/*  f0a23fc:	10000022 */ 	beqz	$zero,.L0f0a2488
/*  f0a2400:	ac60084c */ 	sw	$zero,0x84c($v1)
/*  f0a2404:	8c690858 */ 	lw	$t1,0x858($v1)
.L0f0a2408:
/*  f0a2408:	24640638 */ 	addiu	$a0,$v1,0x638
/*  f0a240c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f0a2410:	5920001e */ 	blezl	$t1,.L0f0a248c
/*  f0a2414:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a2418:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0a241c:	0fc26291 */ 	jal	func0f098a44
/*  f0a2420:	e7a2002c */ 	swc1	$f2,0x2c($sp)
/*  f0a2424:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0a2428:	44806000 */ 	mtc1	$zero,$f12
/*  f0a242c:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0a2430:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0a2434:	10400014 */ 	beqz	$v0,.L0f0a2488
/*  f0a2438:	c7a2002c */ 	lwc1	$f2,0x2c($sp)
/*  f0a243c:	c4600848 */ 	lwc1	$f0,0x848($v1)
/*  f0a2440:	3c017f1b */ 	lui	$at,%hi(var7f1ac768)
/*  f0a2444:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0a2448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a244c:	4502000a */ 	bc1fl	.L0f0a2478
/*  f0a2450:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0a2454:	c432c768 */ 	lwc1	$f18,%lo(var7f1ac768)($at)
/*  f0a2458:	c4c6004c */ 	lwc1	$f6,0x4c($a2)
/*  f0a245c:	46121102 */ 	mul.s	$f4,$f2,$f18
/*  f0a2460:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2464:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0a2468:	46080281 */ 	sub.s	$f10,$f0,$f8
/*  f0a246c:	e46a0848 */ 	swc1	$f10,0x848($v1)
/*  f0a2470:	c4600848 */ 	lwc1	$f0,0x848($v1)
/*  f0a2474:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0a2478:
/*  f0a2478:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a247c:	45020003 */ 	bc1fl	.L0f0a248c
/*  f0a2480:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a2484:	e46c0848 */ 	swc1	$f12,0x848($v1)
.L0f0a2488:
/*  f0a2488:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0a248c:
/*  f0a248c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0a2490:	03e00008 */ 	jr	$ra
/*  f0a2494:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a2498
/*  f0a2498:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0a249c:	e7ac0028 */ 	swc1	$f12,0x28($sp)
/*  f0a24a0:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f0a24a4:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*  f0a24a8:	c7a40028 */ 	lwc1	$f4,0x28($sp)
/*  f0a24ac:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f0a24b0:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f0a24b4:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f0a24b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a24bc:	46087001 */ 	sub.s	$f0,$f14,$f8
/*  f0a24c0:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f0a24c4:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f0a24c8:	46000402 */ 	mul.s	$f16,$f0,$f0
/*  f0a24cc:	0c012974 */ 	jal	sqrtf
/*  f0a24d0:	46105300 */ 	add.s	$f12,$f10,$f16
/*  f0a24d4:	c7a2001c */ 	lwc1	$f2,0x1c($sp)
/*  f0a24d8:	0fc25a9f */ 	jal	func0f096a7c
/*  f0a24dc:	46001303 */ 	div.s	$f12,$f2,$f0
/*  f0a24e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a24e4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0a24e8:	03e00008 */ 	jr	$ra
/*  f0a24ec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a24f0
/*  f0a24f0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0a24f4:	00803825 */ 	or	$a3,$a0,$zero
/*  f0a24f8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a24fc:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0a2500:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0a2504:	27a50018 */ 	addiu	$a1,$sp,0x18
/*  f0a2508:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0a250c:	0fc28311 */ 	jal	func0f0a0c44
/*  f0a2510:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f0a2514:	3c01447a */ 	lui	$at,0x447a
/*  f0a2518:	44810000 */ 	mtc1	$at,$f0
/*  f0a251c:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*  f0a2520:	c7a80028 */ 	lwc1	$f8,0x28($sp)
/*  f0a2524:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f0a2528:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0a252c:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0a2530:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0a2534:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2538:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0a253c:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f0a2540:	e7aa0028 */ 	swc1	$f10,0x28($sp)
/*  f0a2544:	e7b2002c */ 	swc1	$f18,0x2c($sp)
/*  f0a2548:	e4e60000 */ 	swc1	$f6,0x0($a3)
/*  f0a254c:	c7a40028 */ 	lwc1	$f4,0x28($sp)
/*  f0a2550:	e4e40004 */ 	swc1	$f4,0x4($a3)
/*  f0a2554:	c7a8002c */ 	lwc1	$f8,0x2c($sp)
/*  f0a2558:	e4e80008 */ 	swc1	$f8,0x8($a3)
/*  f0a255c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a2560:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0a2564:	03e00008 */ 	jr	$ra
/*  f0a2568:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a256c:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a2570:	8dced148 */ 	lw	$t6,-0x2eb8($t6)
/*  f0a2574:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f0a2578:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a257c:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0a2580:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0a2584:	148e0053 */ 	bne	$a0,$t6,.L0f0a26d4
/*  f0a2588:	00803825 */ 	or	$a3,$a0,$zero
/*  f0a258c:	3c02800a */ 	lui	$v0,%hi(var8009d144)
/*  f0a2590:	2442d144 */ 	addiu	$v0,$v0,%lo(var8009d144)
/*  f0a2594:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f0a2598:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a259c:	946406d6 */ 	lhu	$a0,0x6d6($v1)
/*  f0a25a0:	00047b02 */ 	srl	$t7,$a0,0xc
/*  f0a25a4:	15e10025 */ 	bne	$t7,$at,.L0f0a263c
/*  f0a25a8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0a25ac:	c4a40030 */ 	lwc1	$f4,0x30($a1)
/*  f0a25b0:	e46406dc */ 	swc1	$f4,0x6dc($v1)
/*  f0a25b4:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f0a25b8:	c4a60034 */ 	lwc1	$f6,0x34($a1)
/*  f0a25bc:	e70606e0 */ 	swc1	$f6,0x6e0($t8)
/*  f0a25c0:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f0a25c4:	c4a80038 */ 	lwc1	$f8,0x38($a1)
/*  f0a25c8:	e72806e4 */ 	swc1	$f8,0x6e4($t9)
/*  f0a25cc:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f0a25d0:	c4aa0000 */ 	lwc1	$f10,0x0($a1)
/*  f0a25d4:	e50a06f4 */ 	swc1	$f10,0x6f4($t0)
/*  f0a25d8:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f0a25dc:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f0a25e0:	e53006f8 */ 	swc1	$f16,0x6f8($t1)
/*  f0a25e4:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f0a25e8:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f0a25ec:	e55206fc */ 	swc1	$f18,0x6fc($t2)
/*  f0a25f0:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f0a25f4:	c4a40010 */ 	lwc1	$f4,0x10($a1)
/*  f0a25f8:	e5640700 */ 	swc1	$f4,0x700($t3)
/*  f0a25fc:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f0a2600:	c4a60014 */ 	lwc1	$f6,0x14($a1)
/*  f0a2604:	e5860704 */ 	swc1	$f6,0x704($t4)
/*  f0a2608:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f0a260c:	c4a80018 */ 	lwc1	$f8,0x18($a1)
/*  f0a2610:	e5a80708 */ 	swc1	$f8,0x708($t5)
/*  f0a2614:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f0a2618:	c4aa0020 */ 	lwc1	$f10,0x20($a1)
/*  f0a261c:	e5ca070c */ 	swc1	$f10,0x70c($t6)
/*  f0a2620:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0a2624:	c4b00024 */ 	lwc1	$f16,0x24($a1)
/*  f0a2628:	e5f00710 */ 	swc1	$f16,0x710($t7)
/*  f0a262c:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f0a2630:	c4b20028 */ 	lwc1	$f18,0x28($a1)
/*  f0a2634:	10000027 */ 	beqz	$zero,.L0f0a26d4
/*  f0a2638:	e7120714 */ 	swc1	$f18,0x714($t8)
.L0f0a263c:
/*  f0a263c:	28810002 */ 	slti	$at,$a0,0x2
/*  f0a2640:	14200024 */ 	bnez	$at,.L0f0a26d4
/*  f0a2644:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2648:	c46406dc */ 	lwc1	$f4,0x6dc($v1)
/*  f0a264c:	e6040030 */ 	swc1	$f4,0x30($s0)
/*  f0a2650:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f0a2654:	c72606e0 */ 	lwc1	$f6,0x6e0($t9)
/*  f0a2658:	e6060034 */ 	swc1	$f6,0x34($s0)
/*  f0a265c:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f0a2660:	c50806e4 */ 	lwc1	$f8,0x6e4($t0)
/*  f0a2664:	e6080038 */ 	swc1	$f8,0x38($s0)
/*  f0a2668:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f0a266c:	c52a06f4 */ 	lwc1	$f10,0x6f4($t1)
/*  f0a2670:	e60a0000 */ 	swc1	$f10,0x0($s0)
/*  f0a2674:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f0a2678:	c55006f8 */ 	lwc1	$f16,0x6f8($t2)
/*  f0a267c:	e6100004 */ 	swc1	$f16,0x4($s0)
/*  f0a2680:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f0a2684:	c57206fc */ 	lwc1	$f18,0x6fc($t3)
/*  f0a2688:	e6120008 */ 	swc1	$f18,0x8($s0)
/*  f0a268c:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f0a2690:	c5840700 */ 	lwc1	$f4,0x700($t4)
/*  f0a2694:	e6040010 */ 	swc1	$f4,0x10($s0)
/*  f0a2698:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f0a269c:	c5a60704 */ 	lwc1	$f6,0x704($t5)
/*  f0a26a0:	e6060014 */ 	swc1	$f6,0x14($s0)
/*  f0a26a4:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f0a26a8:	c5c80708 */ 	lwc1	$f8,0x708($t6)
/*  f0a26ac:	e6080018 */ 	swc1	$f8,0x18($s0)
/*  f0a26b0:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0a26b4:	c5ea070c */ 	lwc1	$f10,0x70c($t7)
/*  f0a26b8:	e60a0020 */ 	swc1	$f10,0x20($s0)
/*  f0a26bc:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f0a26c0:	c7100710 */ 	lwc1	$f16,0x710($t8)
/*  f0a26c4:	e6100024 */ 	swc1	$f16,0x24($s0)
/*  f0a26c8:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f0a26cc:	c7320714 */ 	lwc1	$f18,0x714($t9)
/*  f0a26d0:	e6120028 */ 	swc1	$f18,0x28($s0)
.L0f0a26d4:
/*  f0a26d4:	3c08800a */ 	lui	$t0,0x800a
/*  f0a26d8:	8d08d0dc */ 	lw	$t0,-0x2f24($t0)
/*  f0a26dc:	3c01800a */ 	lui	$at,0x800a
/*  f0a26e0:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f0a26e4:	14e80013 */ 	bne	$a3,$t0,.L0f0a2734
/*  f0a26e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a26ec:	44800000 */ 	mtc1	$zero,$f0
/*  f0a26f0:	c424d140 */ 	lwc1	$f4,-0x2ec0($at)
/*  f0a26f4:	afa700b8 */ 	sw	$a3,0xb8($sp)
/*  f0a26f8:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f0a26fc:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0a2700:	0c00566c */ 	jal	func000159b0
/*  f0a2704:	e7a40034 */ 	swc1	$f4,0x34($sp)
/*  f0a2708:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*  f0a270c:	0c005923 */ 	jal	func0001648c
/*  f0a2710:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0a2714:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a2718:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0a271c:	0c005680 */ 	jal	0x15a00
/*  f0a2720:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f0a2724:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f0a2728:	0c005746 */ 	jal	func00015d18
/*  f0a272c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a2730:	8fa700b8 */ 	lw	$a3,0xb8($sp)
.L0f0a2734:
/*  f0a2734:	3c02800a */ 	lui	$v0,%hi(var8009d0f0)
/*  f0a2738:	2442d0f0 */ 	addiu	$v0,$v0,%lo(var8009d0f0)
/*  f0a273c:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f0a2740:	3c01800a */ 	lui	$at,0x800a
/*  f0a2744:	10e90007 */ 	beq	$a3,$t1,.L0f0a2764
/*  f0a2748:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a274c:	8c4a0004 */ 	lw	$t2,0x4($v0)
/*  f0a2750:	10ea0004 */ 	beq	$a3,$t2,.L0f0a2764
/*  f0a2754:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2758:	8c4b0008 */ 	lw	$t3,0x8($v0)
/*  f0a275c:	54eb0016 */ 	bnel	$a3,$t3,.L0f0a27b8
/*  f0a2760:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0a2764:
/*  f0a2764:	c420d140 */ 	lwc1	$f0,-0x2ec0($at)
/*  f0a2768:	44803000 */ 	mtc1	$zero,$f6
/*  f0a276c:	44804000 */ 	mtc1	$zero,$f8
/*  f0a2770:	46000007 */ 	neg.s	$f0,$f0
/*  f0a2774:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f0a2778:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f0a277c:	e7a6002c */ 	swc1	$f6,0x2c($sp)
/*  f0a2780:	e7a80030 */ 	swc1	$f8,0x30($sp)
/*  f0a2784:	0c00566c */ 	jal	func000159b0
/*  f0a2788:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f0a278c:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*  f0a2790:	0c005923 */ 	jal	func0001648c
/*  f0a2794:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0a2798:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a279c:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0a27a0:	0c005680 */ 	jal	0x15a00
/*  f0a27a4:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f0a27a8:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f0a27ac:	0c005746 */ 	jal	func00015d18
/*  f0a27b0:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a27b4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0a27b8:
/*  f0a27b8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a27bc:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f0a27c0:	03e00008 */ 	jr	$ra
/*  f0a27c4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a27c8
/*  f0a27c8:	3c04800a */ 	lui	$a0,%hi(var800a0638)
/*  f0a27cc:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f0a27d0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0a27d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a27d8:	24840638 */ 	addiu	$a0,$a0,%lo(var800a0638)
/*  f0a27dc:	0fc2c40f */ 	jal	func0f0b103c
/*  f0a27e0:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f0a27e4:	10400017 */ 	beqz	$v0,.L0f0a2844
/*  f0a27e8:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0a27ec:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f0a27f0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0a27f4:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0a27f8:	15e10012 */ 	bne	$t7,$at,.L0f0a2844
/*  f0a27fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2800:	8c980604 */ 	lw	$t8,0x604($a0)
/*  f0a2804:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0a2808:	1701000e */ 	bne	$t8,$at,.L0f0a2844
/*  f0a280c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2810:	8c9906b0 */ 	lw	$t9,0x6b0($a0)
/*  f0a2814:	1320000b */ 	beqz	$t9,.L0f0a2844
/*  f0a2818:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a281c:	8c88068c */ 	lw	$t0,0x68c($a0)
/*  f0a2820:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a2824:	15010007 */ 	bne	$t0,$at,.L0f0a2844
/*  f0a2828:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a282c:	0fc26291 */ 	jal	func0f098a44
/*  f0a2830:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0a2834:	14400003 */ 	bnez	$v0,.L0f0a2844
/*  f0a2838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a283c:	10000022 */ 	beqz	$zero,.L0f0a28c8
/*  f0a2840:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a2844:
/*  f0a2844:	3c04800a */ 	lui	$a0,%hi(var800a0ddc)
/*  f0a2848:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f0a284c:	80890de4 */ 	lb	$t1,0xde4($a0)
/*  f0a2850:	24840ddc */ 	addiu	$a0,$a0,%lo(var800a0ddc)
/*  f0a2854:	5120001c */ 	beqzl	$t1,.L0f0a28c8
/*  f0a2858:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a285c:	0fc2c40f */ 	jal	func0f0b103c
/*  f0a2860:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f0a2864:	10400017 */ 	beqz	$v0,.L0f0a28c4
/*  f0a2868:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0a286c:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f0a2870:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0a2874:	314b00ff */ 	andi	$t3,$t2,0xff
/*  f0a2878:	55610013 */ 	bnel	$t3,$at,.L0f0a28c8
/*  f0a287c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a2880:	8c8c0604 */ 	lw	$t4,0x604($a0)
/*  f0a2884:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0a2888:	5581000f */ 	bnel	$t4,$at,.L0f0a28c8
/*  f0a288c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a2890:	8c8d06b0 */ 	lw	$t5,0x6b0($a0)
/*  f0a2894:	51a0000c */ 	beqzl	$t5,.L0f0a28c8
/*  f0a2898:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a289c:	8c8e068c */ 	lw	$t6,0x68c($a0)
/*  f0a28a0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a28a4:	55c10008 */ 	bnel	$t6,$at,.L0f0a28c8
/*  f0a28a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a28ac:	0fc26291 */ 	jal	func0f098a44
/*  f0a28b0:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0a28b4:	54400004 */ 	bnezl	$v0,.L0f0a28c8
/*  f0a28b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a28bc:	10000002 */ 	beqz	$zero,.L0f0a28c8
/*  f0a28c0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a28c4:
/*  f0a28c4:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a28c8:
/*  f0a28c8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a28cc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0a28d0:	03e00008 */ 	jr	$ra
/*  f0a28d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a28d8:	3c04800a */ 	lui	$a0,%hi(var800a0638)
/*  f0a28dc:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f0a28e0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0a28e4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a28e8:	24840638 */ 	addiu	$a0,$a0,%lo(var800a0638)
/*  f0a28ec:	0fc2c40f */ 	jal	func0f0b103c
/*  f0a28f0:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f0a28f4:	10400013 */ 	beqz	$v0,.L0f0a2944
/*  f0a28f8:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0a28fc:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f0a2900:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0a2904:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0a2908:	15e1000e */ 	bne	$t7,$at,.L0f0a2944
/*  f0a290c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2910:	8c980604 */ 	lw	$t8,0x604($a0)
/*  f0a2914:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0a2918:	1701000a */ 	bne	$t8,$at,.L0f0a2944
/*  f0a291c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2920:	8c9906b0 */ 	lw	$t9,0x6b0($a0)
/*  f0a2924:	13200007 */ 	beqz	$t9,.L0f0a2944
/*  f0a2928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a292c:	8c88068c */ 	lw	$t0,0x68c($a0)
/*  f0a2930:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a2934:	15010003 */ 	bne	$t0,$at,.L0f0a2944
/*  f0a2938:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a293c:	1000001e */ 	beqz	$zero,.L0f0a29b8
/*  f0a2940:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a2944:
/*  f0a2944:	3c04800a */ 	lui	$a0,%hi(var800a0ddc)
/*  f0a2948:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f0a294c:	80890de4 */ 	lb	$t1,0xde4($a0)
/*  f0a2950:	24840ddc */ 	addiu	$a0,$a0,%lo(var800a0ddc)
/*  f0a2954:	51200018 */ 	beqzl	$t1,.L0f0a29b8
/*  f0a2958:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a295c:	0fc2c40f */ 	jal	func0f0b103c
/*  f0a2960:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f0a2964:	10400013 */ 	beqz	$v0,.L0f0a29b4
/*  f0a2968:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0a296c:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f0a2970:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0a2974:	314b00ff */ 	andi	$t3,$t2,0xff
/*  f0a2978:	5561000f */ 	bnel	$t3,$at,.L0f0a29b8
/*  f0a297c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a2980:	8c8c0604 */ 	lw	$t4,0x604($a0)
/*  f0a2984:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0a2988:	5581000b */ 	bnel	$t4,$at,.L0f0a29b8
/*  f0a298c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a2990:	8c8d06b0 */ 	lw	$t5,0x6b0($a0)
/*  f0a2994:	51a00008 */ 	beqzl	$t5,.L0f0a29b8
/*  f0a2998:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a299c:	8c8e068c */ 	lw	$t6,0x68c($a0)
/*  f0a29a0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a29a4:	55c10004 */ 	bnel	$t6,$at,.L0f0a29b8
/*  f0a29a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a29ac:	10000002 */ 	beqz	$zero,.L0f0a29b8
/*  f0a29b0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a29b4:
/*  f0a29b4:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a29b8:
/*  f0a29b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a29bc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0a29c0:	03e00008 */ 	jr	$ra
/*  f0a29c4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a29c8
/*  f0a29c8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0a29cc:	3c02800a */ 	lui	$v0,0x800a
/*  f0a29d0:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a29d4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0a29d8:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0a29dc:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0a29e0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0a29e4:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0a29e8:	804e1580 */ 	lb	$t6,0x1580($v0)
/*  f0a29ec:	51c0002a */ 	beqzl	$t6,.L0f0a2a98
/*  f0a29f0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0a29f4:	804f1582 */ 	lb	$t7,0x1582($v0)
/*  f0a29f8:	00008825 */ 	or	$s1,$zero,$zero
/*  f0a29fc:	00408025 */ 	or	$s0,$v0,$zero
/*  f0a2a00:	51e00025 */ 	beqzl	$t7,.L0f0a2a98
/*  f0a2a04:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0a2a08:	80580de4 */ 	lb	$t8,0xde4($v0)
/*  f0a2a0c:	4480a000 */ 	mtc1	$zero,$f20
/*  f0a2a10:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f0a2a14:	53000008 */ 	beqzl	$t8,.L0f0a2a38
/*  f0a2a18:	804c0640 */ 	lb	$t4,0x640($v0)
/*  f0a2a1c:	905914b2 */ 	lbu	$t9,0x14b2($v0)
/*  f0a2a20:	3328ff0f */ 	andi	$t0,$t9,0xff0f
/*  f0a2a24:	350a0010 */ 	ori	$t2,$t0,0x10
/*  f0a2a28:	a04a14b2 */ 	sb	$t2,0x14b2($v0)
/*  f0a2a2c:	314b00f1 */ 	andi	$t3,$t2,0xf1
/*  f0a2a30:	a04b14b2 */ 	sb	$t3,0x14b2($v0)
/*  f0a2a34:	804c0640 */ 	lb	$t4,0x640($v0)
.L0f0a2a38:
/*  f0a2a38:	11800007 */ 	beqz	$t4,.L0f0a2a58
/*  f0a2a3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2a40:	904d0d0e */ 	lbu	$t5,0xd0e($v0)
/*  f0a2a44:	31aeff0f */ 	andi	$t6,$t5,0xff0f
/*  f0a2a48:	35d80010 */ 	ori	$t8,$t6,0x10
/*  f0a2a4c:	a0580d0e */ 	sb	$t8,0xd0e($v0)
/*  f0a2a50:	331900f1 */ 	andi	$t9,$t8,0xf1
/*  f0a2a54:	a0590d0e */ 	sb	$t9,0xd0e($v0)
.L0f0a2a58:
/*  f0a2a58:	e6140874 */ 	swc1	$f20,0x874($s0)
/*  f0a2a5c:	e6140878 */ 	swc1	$f20,0x878($s0)
/*  f0a2a60:	e614087c */ 	swc1	$f20,0x87c($s0)
/*  f0a2a64:	02202025 */ 	or	$a0,$s1,$zero
/*  f0a2a68:	0fc27346 */ 	jal	func0f09cd18
/*  f0a2a6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a2a70:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0a2a74:	1632fff8 */ 	bne	$s1,$s2,.L0f0a2a58
/*  f0a2a78:	261007a4 */ 	addiu	$s0,$s0,0x7a4
/*  f0a2a7c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a2a80:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f0a2a84:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a2a88:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a2a8c:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f0a2a90:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a2a94:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0a2a98:
/*  f0a2a98:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0a2a9c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0a2aa0:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0a2aa4:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0a2aa8:	03e00008 */ 	jr	$ra
/*  f0a2aac:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f0a2ab0
/*  f0a2ab0:	24010020 */ 	addiu	$at,$zero,0x20
/*  f0a2ab4:	10810007 */ 	beq	$a0,$at,.L0f0a2ad4
/*  f0a2ab8:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0a2abc:	10810005 */ 	beq	$a0,$at,.L0f0a2ad4
/*  f0a2ac0:	24010035 */ 	addiu	$at,$zero,0x35
/*  f0a2ac4:	10810003 */ 	beq	$a0,$at,.L0f0a2ad4
/*  f0a2ac8:	2401003e */ 	addiu	$at,$zero,0x3e
/*  f0a2acc:	14810003 */ 	bne	$a0,$at,.L0f0a2adc
/*  f0a2ad0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a2ad4:
/*  f0a2ad4:	03e00008 */ 	jr	$ra
/*  f0a2ad8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a2adc:
/*  f0a2adc:	03e00008 */ 	jr	$ra
/*  f0a2ae0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a2ae4
/*  f0a2ae4:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0a2ae8:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f0a2aec:	3c14800a */ 	lui	$s4,0x800a
/*  f0a2af0:	8e94a244 */ 	lw	$s4,-0x5dbc($s4)
/*  f0a2af4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0a2af8:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f0a2afc:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0a2b00:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0a2b04:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0a2b08:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0a2b0c:	92840638 */ 	lbu	$a0,0x638($s4)
/*  f0a2b10:	3c050800 */ 	lui	$a1,0x800
/*  f0a2b14:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a2b18:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f0a2b1c:	1440009a */ 	bnez	$v0,.L0f0a2d88
/*  f0a2b20:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0a2b24:	28c1002c */ 	slti	$at,$a2,0x2c
/*  f0a2b28:	10200097 */ 	beqz	$at,.L0f0a2d88
/*  f0a2b2c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a2b30:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a2b34:	8c6e0298 */ 	lw	$t6,0x298($v1)
/*  f0a2b38:	05c2000f */ 	bltzl	$t6,.L0f0a2b78
/*  f0a2b3c:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0a2b40:	8c7802a0 */ 	lw	$t8,0x2a0($v1)
/*  f0a2b44:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f0a2b48:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f0a2b4c:	11f90005 */ 	beq	$t7,$t9,.L0f0a2b64
/*  f0a2b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2b54:	8c6802a4 */ 	lw	$t0,0x2a4($v1)
/*  f0a2b58:	8d0900bc */ 	lw	$t1,0xbc($t0)
/*  f0a2b5c:	55e90006 */ 	bnel	$t7,$t1,.L0f0a2b78
/*  f0a2b60:	8fa60048 */ 	lw	$a2,0x48($sp)
.L0f0a2b64:
/*  f0a2b64:	0fc28aac */ 	jal	func0f0a2ab0
/*  f0a2b68:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0a2b6c:	54400087 */ 	bnezl	$v0,.L0f0a2d8c
/*  f0a2b70:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0a2b74:	8fa60048 */ 	lw	$a2,0x48($sp)
.L0f0a2b78:
/*  f0a2b78:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a2b7c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a2b80:	28c10002 */ 	slti	$at,$a2,0x2
/*  f0a2b84:	54200081 */ 	bnezl	$at,.L0f0a2d8c
/*  f0a2b88:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0a2b8c:	828a1582 */ 	lb	$t2,0x1582($s4)
/*  f0a2b90:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0a2b94:	5541007d */ 	bnel	$t2,$at,.L0f0a2d8c
/*  f0a2b98:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0a2b9c:	8e8b00bc */ 	lw	$t3,0xbc($s4)
/*  f0a2ba0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0a2ba4:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0a2ba8:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*  f0a2bac:	afad0038 */ 	sw	$t5,0x38($sp)
/*  f0a2bb0:	14c10006 */ 	bne	$a2,$at,.L0f0a2bcc
/*  f0a2bb4:	afac0044 */ 	sw	$t4,0x44($sp)
/*  f0a2bb8:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0a2bbc:	2401ff7f */ 	addiu	$at,$zero,-129
/*  f0a2bc0:	8c4e00c4 */ 	lw	$t6,0xc4($v0)
/*  f0a2bc4:	01c1c024 */ 	and	$t8,$t6,$at
/*  f0a2bc8:	ac5800c4 */ 	sw	$t8,0xc4($v0)
.L0f0a2bcc:
/*  f0a2bcc:	24010031 */ 	addiu	$at,$zero,0x31
/*  f0a2bd0:	54c10007 */ 	bnel	$a2,$at,.L0f0a2bf0
/*  f0a2bd4:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f0a2bd8:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0a2bdc:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f0a2be0:	8c5900c4 */ 	lw	$t9,0xc4($v0)
/*  f0a2be4:	03214024 */ 	and	$t0,$t9,$at
/*  f0a2be8:	ac4800c4 */ 	sw	$t0,0xc4($v0)
/*  f0a2bec:	2401001e */ 	addiu	$at,$zero,0x1e
.L0f0a2bf0:
/*  f0a2bf0:	10c10003 */ 	beq	$a2,$at,.L0f0a2c00
/*  f0a2bf4:	00008825 */ 	or	$s1,$zero,$zero
/*  f0a2bf8:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f0a2bfc:	14c10018 */ 	bne	$a2,$at,.L0f0a2c60
.L0f0a2c00:
/*  f0a2c00:	02808025 */ 	or	$s0,$s4,$zero
/*  f0a2c04:	26920638 */ 	addiu	$s2,$s4,0x638
/*  f0a2c08:	24130002 */ 	addiu	$s3,$zero,0x2
.L0f0a2c0c:
/*  f0a2c0c:	0fc2c41f */ 	jal	func0f0b107c
/*  f0a2c10:	02402025 */ 	or	$a0,$s2,$zero
/*  f0a2c14:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0a2c18:	31e900ff */ 	andi	$t1,$t7,0xff
/*  f0a2c1c:	5669000d */ 	bnel	$s3,$t1,.L0f0a2c54
/*  f0a2c20:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0a2c24:	8e0a0c3c */ 	lw	$t2,0xc3c($s0)
/*  f0a2c28:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0a2c2c:	55410009 */ 	bnel	$t2,$at,.L0f0a2c54
/*  f0a2c30:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0a2c34:	8e0b0c40 */ 	lw	$t3,0xc40($s0)
/*  f0a2c38:	26240002 */ 	addiu	$a0,$s1,0x2
/*  f0a2c3c:	02402825 */ 	or	$a1,$s2,$zero
/*  f0a2c40:	55600004 */ 	bnezl	$t3,.L0f0a2c54
/*  f0a2c44:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0a2c48:	0fc27c40 */ 	jal	func0f09f100
/*  f0a2c4c:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f0a2c50:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f0a2c54:
/*  f0a2c54:	261007a4 */ 	addiu	$s0,$s0,0x7a4
/*  f0a2c58:	1633ffec */ 	bne	$s1,$s3,.L0f0a2c0c
/*  f0a2c5c:	265207a4 */ 	addiu	$s2,$s2,0x7a4
.L0f0a2c60:
/*  f0a2c60:	24130002 */ 	addiu	$s3,$zero,0x2
/*  f0a2c64:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0a2c68:	0fc22e2e */ 	jal	func0f08b8b8
/*  f0a2c6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a2c70:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0a2c74:	0fc22e2e */ 	jal	func0f08b8b8
/*  f0a2c78:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a2c7c:	0fc4a2bd */ 	jal	func0f128af4
/*  f0a2c80:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0a2c84:	0440001e */ 	bltz	$v0,.L0f0a2d00
/*  f0a2c88:	00402825 */ 	or	$a1,$v0,$zero
/*  f0a2c8c:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f0a2c90:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0a2c94:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0a2c98:	11800019 */ 	beqz	$t4,.L0f0a2d00
/*  f0a2c9c:	3c072000 */ 	lui	$a3,0x2000
/*  f0a2ca0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0a2ca4:	0fc22e3a */ 	jal	func0f08b8e8
/*  f0a2ca8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0a2cac:	10400014 */ 	beqz	$v0,.L0f0a2d00
/*  f0a2cb0:	00408825 */ 	or	$s1,$v0,$zero
/*  f0a2cb4:	8c4d0004 */ 	lw	$t5,0x4($v0)
/*  f0a2cb8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a2cbc:	11a00010 */ 	beqz	$t5,.L0f0a2d00
/*  f0a2cc0:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0a2cc4:	0fc20a59 */ 	jal	func0f082964
/*  f0a2cc8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a2ccc:	8e0e0040 */ 	lw	$t6,0x40($s0)
/*  f0a2cd0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0a2cd4:	31d80080 */ 	andi	$t8,$t6,0x80
/*  f0a2cd8:	13000007 */ 	beqz	$t8,.L0f0a2cf8
/*  f0a2cdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2ce0:	8e080048 */ 	lw	$t0,0x48($s0)
/*  f0a2ce4:	241900f0 */ 	addiu	$t9,$zero,0xf0
/*  f0a2ce8:	ad1900b4 */ 	sw	$t9,0xb4($t0)
/*  f0a2cec:	8e090048 */ 	lw	$t1,0x48($s0)
/*  f0a2cf0:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f0a2cf4:	ad2f0108 */ 	sw	$t7,0x108($t1)
.L0f0a2cf8:
/*  f0a2cf8:	0fc20c1f */ 	jal	func0f08307c
/*  f0a2cfc:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0a2d00:
/*  f0a2d00:	0fc447a9 */ 	jal	func0f111ea4
/*  f0a2d04:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0a2d08:	928a14b2 */ 	lbu	$t2,0x14b2($s4)
/*  f0a2d0c:	92980d0e */ 	lbu	$t8,0xd0e($s4)
/*  f0a2d10:	ae8013e0 */ 	sw	$zero,0x13e0($s4)
/*  f0a2d14:	314bff0f */ 	andi	$t3,$t2,0xff0f
/*  f0a2d18:	3319ff0f */ 	andi	$t9,$t8,0xff0f
/*  f0a2d1c:	968a0010 */ 	lhu	$t2,0x10($s4)
/*  f0a2d20:	356d0010 */ 	ori	$t5,$t3,0x10
/*  f0a2d24:	372f0010 */ 	ori	$t7,$t9,0x10
/*  f0a2d28:	a28d14b2 */ 	sb	$t5,0x14b2($s4)
/*  f0a2d2c:	31ae00f1 */ 	andi	$t6,$t5,0xf1
/*  f0a2d30:	a28f0d0e */ 	sb	$t7,0xd0e($s4)
/*  f0a2d34:	31e900f1 */ 	andi	$t1,$t7,0xf1
/*  f0a2d38:	a28e14b2 */ 	sb	$t6,0x14b2($s4)
/*  f0a2d3c:	a2890d0e */ 	sb	$t1,0xd0e($s4)
/*  f0a2d40:	166a000b */ 	bne	$s3,$t2,.L0f0a2d70
/*  f0a2d44:	ae800c3c */ 	sw	$zero,0xc3c($s4)
/*  f0a2d48:	3c0b800a */ 	lui	$t3,0x800a
/*  f0a2d4c:	8d6ba244 */ 	lw	$t3,-0x5dbc($t3)
/*  f0a2d50:	8d620264 */ 	lw	$v0,0x264($t3)
/*  f0a2d54:	50400006 */ 	beqzl	$v0,.L0f0a2d70
/*  f0a2d58:	a6800010 */ 	sh	$zero,0x10($s4)
/*  f0a2d5c:	8c4c0014 */ 	lw	$t4,0x14($v0)
/*  f0a2d60:	51800003 */ 	beqzl	$t4,.L0f0a2d70
/*  f0a2d64:	a6800010 */ 	sh	$zero,0x10($s4)
/*  f0a2d68:	a4400062 */ 	sh	$zero,0x62($v0)
/*  f0a2d6c:	a6800010 */ 	sh	$zero,0x10($s4)
.L0f0a2d70:
/*  f0a2d70:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a2d74:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f0a2d78:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a2d7c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a2d80:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f0a2d84:	00002825 */ 	or	$a1,$zero,$zero
.L0f0a2d88:
/*  f0a2d88:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0a2d8c:
/*  f0a2d8c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0a2d90:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0a2d94:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0a2d98:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f0a2d9c:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f0a2da0:	03e00008 */ 	jr	$ra
/*  f0a2da4:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f0a2da8
/*  f0a2da8:	10800038 */ 	beqz	$a0,.L0f0a2e8c
/*  f0a2dac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2db0:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0a2db4:	24060006 */ 	addiu	$a2,$zero,0x6
/*  f0a2db8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0a2dbc:	10c20033 */ 	beq	$a2,$v0,.L0f0a2e8c
/*  f0a2dc0:	2c410006 */ 	sltiu	$at,$v0,0x6
.L0f0a2dc4:
/*  f0a2dc4:	1020002f */ 	beqz	$at,.L0f0a2e84
/*  f0a2dc8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0a2dcc:	3c017f1b */ 	lui	$at,%hi(var7f1ac76c)
/*  f0a2dd0:	002e0821 */ 	addu	$at,$at,$t6
/*  f0a2dd4:	8c2ec76c */ 	lw	$t6,%lo(var7f1ac76c)($at)
/*  f0a2dd8:	01c00008 */ 	jr	$t6
/*  f0a2ddc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2de0:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f0a2de4:	8c850008 */ 	lw	$a1,0x8($a0)
/*  f0a2de8:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0a2dec:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f0a2df0:	8c8ffffc */ 	lw	$t7,-0x4($a0)
/*  f0a2df4:	acaf0014 */ 	sw	$t7,0x14($a1)
/*  f0a2df8:	10000022 */ 	beqz	$zero,.L0f0a2e84
/*  f0a2dfc:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0a2e00:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f0a2e04:	8c850008 */ 	lw	$a1,0x8($a0)
/*  f0a2e08:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0a2e0c:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f0a2e10:	8c98fffc */ 	lw	$t8,-0x4($a0)
/*  f0a2e14:	acb80014 */ 	sw	$t8,0x14($a1)
/*  f0a2e18:	1000001a */ 	beqz	$zero,.L0f0a2e84
/*  f0a2e1c:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0a2e20:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f0a2e24:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0a2e28:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f0a2e2c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0a2e30:	10000014 */ 	beqz	$zero,.L0f0a2e84
/*  f0a2e34:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0a2e38:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f0a2e3c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0a2e40:	a4600000 */ 	sh	$zero,0x0($v1)
/*  f0a2e44:	1000000f */ 	beqz	$zero,.L0f0a2e84
/*  f0a2e48:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0a2e4c:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f0a2e50:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0a2e54:	a4600000 */ 	sh	$zero,0x0($v1)
/*  f0a2e58:	1000000a */ 	beqz	$zero,.L0f0a2e84
/*  f0a2e5c:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0a2e60:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f0a2e64:	8c990008 */ 	lw	$t9,0x8($a0)
/*  f0a2e68:	24840014 */ 	addiu	$a0,$a0,0x14
/*  f0a2e6c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0a2e70:	8c88fff8 */ 	lw	$t0,-0x8($a0)
/*  f0a2e74:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f0a2e78:	8c89fffc */ 	lw	$t1,-0x4($a0)
/*  f0a2e7c:	ac690008 */ 	sw	$t1,0x8($v1)
/*  f0a2e80:	8c820000 */ 	lw	$v0,0x0($a0)
.L0f0a2e84:
/*  f0a2e84:	54c2ffcf */ 	bnel	$a2,$v0,.L0f0a2dc4
/*  f0a2e88:	2c410006 */ 	sltiu	$at,$v0,0x6
.L0f0a2e8c:
/*  f0a2e8c:	03e00008 */ 	jr	$ra
/*  f0a2e90:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a2e94
/*  f0a2e94:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0a2e98:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0a2e9c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0a2ea0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0a2ea4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0a2ea8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a2eac:	00c08825 */ 	or	$s1,$a2,$zero
/*  f0a2eb0:	0080a025 */ 	or	$s4,$a0,$zero
/*  f0a2eb4:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f0a2eb8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0a2ebc:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0a2ec0:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0a2ec4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0a2ec8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0a2ecc:	00009825 */ 	or	$s3,$zero,$zero
/*  f0a2ed0:	10a0007d */ 	beqz	$a1,.L0f0a30c8
/*  f0a2ed4:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0a2ed8:	241e0005 */ 	addiu	$s8,$zero,0x5
/*  f0a2edc:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f0a2ee0:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f0a2ee4:	96020000 */ 	lhu	$v0,0x0($s0)
.L0f0a2ee8:
/*  f0a2ee8:	304e00ff */ 	andi	$t6,$v0,0xff
/*  f0a2eec:	25cffff8 */ 	addiu	$t7,$t6,-8
/*  f0a2ef0:	2de10011 */ 	sltiu	$at,$t7,0x11
/*  f0a2ef4:	1020005e */ 	beqz	$at,.L0f0a3070
/*  f0a2ef8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a2efc:	3c017f1b */ 	lui	$at,%hi(var7f1ac784)
/*  f0a2f00:	002f0821 */ 	addu	$at,$at,$t7
/*  f0a2f04:	8c2fc784 */ 	lw	$t7,%lo(var7f1ac784)($at)
/*  f0a2f08:	01e00008 */ 	jr	$t7
/*  f0a2f0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a2f10:	8e120004 */ 	lw	$s2,0x4($s0)
/*  f0a2f14:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a2f18:	0c006a87 */ 	jal	func0001aa1c
/*  f0a2f1c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a2f20:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f0a2f24:	8e580008 */ 	lw	$t8,0x8($s2)
/*  f0a2f28:	26310010 */ 	addiu	$s1,$s1,0x10
/*  f0a2f2c:	26730010 */ 	addiu	$s3,$s3,0x10
/*  f0a2f30:	ae180014 */ 	sw	$t8,0x14($s0)
/*  f0a2f34:	ae20fff0 */ 	sw	$zero,-0x10($s1)
/*  f0a2f38:	ae22fff4 */ 	sw	$v0,-0xc($s1)
/*  f0a2f3c:	ae30fff8 */ 	sw	$s0,-0x8($s1)
/*  f0a2f40:	8e590008 */ 	lw	$t9,0x8($s2)
/*  f0a2f44:	1000004a */ 	beqz	$zero,.L0f0a3070
/*  f0a2f48:	ae39fffc */ 	sw	$t9,-0x4($s1)
/*  f0a2f4c:	8e120004 */ 	lw	$s2,0x4($s0)
/*  f0a2f50:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a2f54:	0c006a87 */ 	jal	func0001aa1c
/*  f0a2f58:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a2f5c:	ac550000 */ 	sw	$s5,0x0($v0)
/*  f0a2f60:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f0a2f64:	26310010 */ 	addiu	$s1,$s1,0x10
/*  f0a2f68:	26730010 */ 	addiu	$s3,$s3,0x10
/*  f0a2f6c:	ae080014 */ 	sw	$t0,0x14($s0)
/*  f0a2f70:	ae35fff0 */ 	sw	$s5,-0x10($s1)
/*  f0a2f74:	ae22fff4 */ 	sw	$v0,-0xc($s1)
/*  f0a2f78:	ae30fff8 */ 	sw	$s0,-0x8($s1)
/*  f0a2f7c:	8e490000 */ 	lw	$t1,0x0($s2)
/*  f0a2f80:	1000003b */ 	beqz	$zero,.L0f0a3070
/*  f0a2f84:	ae29fffc */ 	sw	$t1,-0x4($s1)
/*  f0a2f88:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a2f8c:	0c006a87 */ 	jal	func0001aa1c
/*  f0a2f90:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a2f94:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f0a2f98:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0a2f9c:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f0a2fa0:	ae2a0000 */ 	sw	$t2,0x0($s1)
/*  f0a2fa4:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0a2fa8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f0a2fac:	10000030 */ 	beqz	$zero,.L0f0a3070
/*  f0a2fb0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f0a2fb4:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a2fb8:	0c006a87 */ 	jal	func0001aa1c
/*  f0a2fbc:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a2fc0:	a4400000 */ 	sh	$zero,0x0($v0)
/*  f0a2fc4:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f0a2fc8:	ae2b0000 */ 	sw	$t3,0x0($s1)
/*  f0a2fcc:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0a2fd0:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f0a2fd4:	10000026 */ 	beqz	$zero,.L0f0a3070
/*  f0a2fd8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f0a2fdc:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a2fe0:	0c006a87 */ 	jal	func0001aa1c
/*  f0a2fe4:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a2fe8:	a4400000 */ 	sh	$zero,0x0($v0)
/*  f0a2fec:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f0a2ff0:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f0a2ff4:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0a2ff8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f0a2ffc:	1000001c */ 	beqz	$zero,.L0f0a3070
/*  f0a3000:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f0a3004:	8e120004 */ 	lw	$s2,0x4($s0)
/*  f0a3008:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a300c:	0c006a87 */ 	jal	func0001aa1c
/*  f0a3010:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a3014:	8e4d000c */ 	lw	$t5,0xc($s2)
/*  f0a3018:	26310014 */ 	addiu	$s1,$s1,0x14
/*  f0a301c:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f0a3020:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f0a3024:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f0a3028:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0a302c:	86580010 */ 	lh	$t8,0x10($s2)
/*  f0a3030:	8e4f000c */ 	lw	$t7,0xc($s2)
/*  f0a3034:	03170019 */ 	multu	$t8,$s7
/*  f0a3038:	0000c812 */ 	mflo	$t9
/*  f0a303c:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f0a3040:	25090007 */ 	addiu	$t1,$t0,0x7
/*  f0a3044:	352a0007 */ 	ori	$t2,$t1,0x7
/*  f0a3048:	394b0007 */ 	xori	$t3,$t2,0x7
/*  f0a304c:	ac4b0008 */ 	sw	$t3,0x8($v0)
/*  f0a3050:	ae3effec */ 	sw	$s8,-0x14($s1)
/*  f0a3054:	ae22fff0 */ 	sw	$v0,-0x10($s1)
/*  f0a3058:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f0a305c:	ae2cfff4 */ 	sw	$t4,-0xc($s1)
/*  f0a3060:	8c4d0004 */ 	lw	$t5,0x4($v0)
/*  f0a3064:	ae2dfff8 */ 	sw	$t5,-0x8($s1)
/*  f0a3068:	8c4e0008 */ 	lw	$t6,0x8($v0)
/*  f0a306c:	ae2efffc */ 	sw	$t6,-0x4($s1)
.L0f0a3070:
/*  f0a3070:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f0a3074:	10400003 */ 	beqz	$v0,.L0f0a3084
/*  f0a3078:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a307c:	10000010 */ 	beqz	$zero,.L0f0a30c0
/*  f0a3080:	00408025 */ 	or	$s0,$v0,$zero
.L0f0a3084:
/*  f0a3084:	1200000e */ 	beqz	$s0,.L0f0a30c0
/*  f0a3088:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a308c:	8ec30008 */ 	lw	$v1,0x8($s6)
.L0f0a3090:
/*  f0a3090:	56030004 */ 	bnel	$s0,$v1,.L0f0a30a4
/*  f0a3094:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0a3098:	10000009 */ 	beqz	$zero,.L0f0a30c0
/*  f0a309c:	00008025 */ 	or	$s0,$zero,$zero
/*  f0a30a0:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f0a30a4:
/*  f0a30a4:	50400004 */ 	beqzl	$v0,.L0f0a30b8
/*  f0a30a8:	8e100008 */ 	lw	$s0,0x8($s0)
/*  f0a30ac:	10000004 */ 	beqz	$zero,.L0f0a30c0
/*  f0a30b0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0a30b4:	8e100008 */ 	lw	$s0,0x8($s0)
.L0f0a30b8:
/*  f0a30b8:	1600fff5 */ 	bnez	$s0,.L0f0a3090
/*  f0a30bc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a30c0:
/*  f0a30c0:	5600ff89 */ 	bnezl	$s0,.L0f0a2ee8
/*  f0a30c4:	96020000 */ 	lhu	$v0,0x0($s0)
.L0f0a30c8:
/*  f0a30c8:	24180006 */ 	addiu	$t8,$zero,0x6
/*  f0a30cc:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f0a30d0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0a30d4:	26620004 */ 	addiu	$v0,$s3,0x4
/*  f0a30d8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0a30dc:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0a30e0:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0a30e4:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0a30e8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0a30ec:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0a30f0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0a30f4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0a30f8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a30fc:	03e00008 */ 	jr	$ra
/*  f0a3100:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f0a3104
/*  f0a3104:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a3108:	8dcea24c */ 	lw	$t6,-0x5db4($t6)
/*  f0a310c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0a3110:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a3114:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0a3118:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0a311c:	3c02800a */ 	lui	$v0,0x800a
/*  f0a3120:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a3124:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0a3128:	3c048007 */ 	lui	$a0,%hi(var80070200)
/*  f0a312c:	904f0ddc */ 	lbu	$t7,0xddc($v0)
/*  f0a3130:	24840200 */ 	addiu	$a0,$a0,%lo(var80070200)
/*  f0a3134:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a3138:	15e10003 */ 	bne	$t7,$at,.L0f0a3148
/*  f0a313c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3140:	0fc26238 */ 	jal	func0f0988e0
/*  f0a3144:	24460ddc */ 	addiu	$a2,$v0,0xddc
.L0f0a3148:
/*  f0a3148:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0a314c:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0a3150:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a3154:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0a3158:	03e00008 */ 	jr	$ra
/*  f0a315c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a3160
/*  f0a3160:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0a3164:	3c0f8007 */ 	lui	$t7,%hi(var80070210)
/*  f0a3168:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0a316c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a3170:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f0a3174:	25ef0210 */ 	addiu	$t7,$t7,%lo(var80070210)
/*  f0a3178:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0a317c:	27ae0038 */ 	addiu	$t6,$sp,0x38
/*  f0a3180:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f0a3184:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0a3188:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0a318c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0a3190:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0a3194:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f0a3198:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0a319c:	8d0a0284 */ 	lw	$t2,0x284($t0)
/*  f0a31a0:	00808025 */ 	or	$s0,$a0,$zero
/*  f0a31a4:	8d4b1580 */ 	lw	$t3,0x1580($t2)
/*  f0a31a8:	000b6ec0 */ 	sll	$t5,$t3,0x1b
/*  f0a31ac:	05a30031 */ 	bgezl	$t5,.L0f0a3274
/*  f0a31b0:	8e0b068c */ 	lw	$t3,0x68c($s0)
/*  f0a31b4:	50e0002f */ 	beqzl	$a3,.L0f0a3274
/*  f0a31b8:	8e0b068c */ 	lw	$t3,0x68c($s0)
/*  f0a31bc:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f0a31c0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a31c4:	333800ff */ 	andi	$t8,$t9,0xff
/*  f0a31c8:	5701002a */ 	bnel	$t8,$at,.L0f0a3274
/*  f0a31cc:	8e0b068c */ 	lw	$t3,0x68c($s0)
/*  f0a31d0:	8c820604 */ 	lw	$v0,0x604($a0)
/*  f0a31d4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0a31d8:	50400007 */ 	beqzl	$v0,.L0f0a31f8
/*  f0a31dc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a31e0:	10820004 */ 	beq	$a0,$v0,.L0f0a31f4
/*  f0a31e4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0a31e8:	10410002 */ 	beq	$v0,$at,.L0f0a31f4
/*  f0a31ec:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0a31f0:	1441001f */ 	bne	$v0,$at,.L0f0a3270
.L0f0a31f4:
/*  f0a31f4:	3c013f80 */ 	lui	$at,0x3f80
.L0f0a31f8:
/*  f0a31f8:	44811000 */ 	mtc1	$at,$f2
/*  f0a31fc:	c60406d0 */ 	lwc1	$f4,0x6d0($s0)
/*  f0a3200:	4602203c */ 	c.lt.s	$f4,$f2
/*  f0a3204:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3208:	45020017 */ 	bc1fl	.L0f0a3268
/*  f0a320c:	ae000744 */ 	sw	$zero,0x744($s0)
/*  f0a3210:	8e0e0744 */ 	lw	$t6,0x744($s0)
/*  f0a3214:	8d0f0034 */ 	lw	$t7,0x34($t0)
/*  f0a3218:	01cf4821 */ 	addu	$t1,$t6,$t7
/*  f0a321c:	2921003d */ 	slti	$at,$t1,0x3d
/*  f0a3220:	1420000e */ 	bnez	$at,.L0f0a325c
/*  f0a3224:	ae090744 */ 	sw	$t1,0x744($s0)
/*  f0a3228:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0a322c:	44814000 */ 	mtc1	$at,$f8
/*  f0a3230:	c5060044 */ 	lwc1	$f6,0x44($t0)
/*  f0a3234:	c61006d0 */ 	lwc1	$f16,0x6d0($s0)
/*  f0a3238:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0a323c:	460a8480 */ 	add.s	$f18,$f16,$f10
/*  f0a3240:	e61206d0 */ 	swc1	$f18,0x6d0($s0)
/*  f0a3244:	c60406d0 */ 	lwc1	$f4,0x6d0($s0)
/*  f0a3248:	4604103c */ 	c.lt.s	$f2,$f4
/*  f0a324c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3250:	45000002 */ 	bc1f	.L0f0a325c
/*  f0a3254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3258:	e60206d0 */ 	swc1	$f2,0x6d0($s0)
.L0f0a325c:
/*  f0a325c:	10000049 */ 	beqz	$zero,.L0f0a3384
/*  f0a3260:	c60006d0 */ 	lwc1	$f0,0x6d0($s0)
/*  f0a3264:	ae000744 */ 	sw	$zero,0x744($s0)
.L0f0a3268:
/*  f0a3268:	10000046 */ 	beqz	$zero,.L0f0a3384
/*  f0a326c:	c60006d0 */ 	lwc1	$f0,0x6d0($s0)
.L0f0a3270:
/*  f0a3270:	8e0b068c */ 	lw	$t3,0x68c($s0)
.L0f0a3274:
/*  f0a3274:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0a3278:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0a327c:	44811000 */ 	mtc1	$at,$f2
/*  f0a3280:	148b0003 */ 	bne	$a0,$t3,.L0f0a3290
/*  f0a3284:	3c014170 */ 	lui	$at,0x4170
/*  f0a3288:	44811000 */ 	mtc1	$at,$f2
/*  f0a328c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a3290:
/*  f0a3290:	44806000 */ 	mtc1	$zero,$f12
/*  f0a3294:	c60006d0 */ 	lwc1	$f0,0x6d0($s0)
/*  f0a3298:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a329c:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0a32a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a32a4:	45020036 */ 	bc1fl	.L0f0a3380
/*  f0a32a8:	ae000744 */ 	sw	$zero,0x744($s0)
/*  f0a32ac:	44813000 */ 	mtc1	$at,$f6
/*  f0a32b0:	8e0c0744 */ 	lw	$t4,0x744($s0)
/*  f0a32b4:	8d0d0034 */ 	lw	$t5,0x34($t0)
/*  f0a32b8:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0a32bc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a32c0:	018dc821 */ 	addu	$t9,$t4,$t5
/*  f0a32c4:	ae190744 */ 	sw	$t9,0x744($s0)
/*  f0a32c8:	45000003 */ 	bc1f	.L0f0a32d8
/*  f0a32cc:	241800f4 */ 	addiu	$t8,$zero,0xf4
/*  f0a32d0:	ae180744 */ 	sw	$t8,0x744($s0)
/*  f0a32d4:	c60006d0 */ 	lwc1	$f0,0x6d0($s0)
.L0f0a32d8:
/*  f0a32d8:	8e0e0744 */ 	lw	$t6,0x744($s0)
/*  f0a32dc:	29c10079 */ 	slti	$at,$t6,0x79
/*  f0a32e0:	54200003 */ 	bnezl	$at,.L0f0a32f0
/*  f0a32e4:	8e0f068c */ 	lw	$t7,0x68c($s0)
/*  f0a32e8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a32ec:	8e0f068c */ 	lw	$t7,0x68c($s0)
.L0f0a32f0:
/*  f0a32f0:	548f000a */ 	bnel	$a0,$t7,.L0f0a331c
/*  f0a32f4:	8e020604 */ 	lw	$v0,0x604($s0)
/*  f0a32f8:	50e00008 */ 	beqzl	$a3,.L0f0a331c
/*  f0a32fc:	8e020604 */ 	lw	$v0,0x604($s0)
/*  f0a3300:	8ce90000 */ 	lw	$t1,0x0($a3)
/*  f0a3304:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a3308:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f0a330c:	51410003 */ 	beql	$t2,$at,.L0f0a331c
/*  f0a3310:	8e020604 */ 	lw	$v0,0x604($s0)
/*  f0a3314:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a3318:	8e020604 */ 	lw	$v0,0x604($s0)
.L0f0a331c:
/*  f0a331c:	10400008 */ 	beqz	$v0,.L0f0a3340
/*  f0a3320:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3324:	10820006 */ 	beq	$a0,$v0,.L0f0a3340
/*  f0a3328:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0a332c:	10410004 */ 	beq	$v0,$at,.L0f0a3340
/*  f0a3330:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0a3334:	10410002 */ 	beq	$v0,$at,.L0f0a3340
/*  f0a3338:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a333c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a3340:
/*  f0a3340:	50600007 */ 	beqzl	$v1,.L0f0a3360
/*  f0a3344:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0a3348:	c5080044 */ 	lwc1	$f8,0x44($t0)
/*  f0a334c:	46024403 */ 	div.s	$f16,$f8,$f2
/*  f0a3350:	46100281 */ 	sub.s	$f10,$f0,$f16
/*  f0a3354:	e60a06d0 */ 	swc1	$f10,0x6d0($s0)
/*  f0a3358:	c60006d0 */ 	lwc1	$f0,0x6d0($s0)
/*  f0a335c:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0a3360:
/*  f0a3360:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3364:	45000003 */ 	bc1f	.L0f0a3374
/*  f0a3368:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a336c:	e60c06d0 */ 	swc1	$f12,0x6d0($s0)
/*  f0a3370:	c60006d0 */ 	lwc1	$f0,0x6d0($s0)
.L0f0a3374:
/*  f0a3374:	10000003 */ 	beqz	$zero,.L0f0a3384
/*  f0a3378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a337c:	ae000744 */ 	sw	$zero,0x744($s0)
.L0f0a3380:
/*  f0a3380:	c60006d0 */ 	lwc1	$f0,0x6d0($s0)
.L0f0a3384:
/*  f0a3384:	3c017f1b */ 	lui	$at,%hi(var7f1ac7c8)
/*  f0a3388:	c432c7c8 */ 	lwc1	$f18,%lo(var7f1ac7c8)($at)
/*  f0a338c:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0a3390:	46120302 */ 	mul.s	$f12,$f0,$f18
/*  f0a3394:	0c0068f4 */ 	jal	func0001a3d0
/*  f0a3398:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a339c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a33a0:	44813000 */ 	mtc1	$at,$f6
/*  f0a33a4:	46000107 */ 	neg.s	$f4,$f0
/*  f0a33a8:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f0a33ac:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0a33b0:	44818000 */ 	mtc1	$at,$f16
/*  f0a33b4:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0a33b8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a33bc:	11600005 */ 	beqz	$t3,.L0f0a33d4
/*  f0a33c0:	46104300 */ 	add.s	$f12,$f8,$f16
/*  f0a33c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a33c8:	44811000 */ 	mtc1	$at,$f2
/*  f0a33cc:	10000003 */ 	beqz	$zero,.L0f0a33dc
/*  f0a33d0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a33d4:
/*  f0a33d4:	44811000 */ 	mtc1	$at,$f2
/*  f0a33d8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a33dc:
/*  f0a33dc:	3c017f1b */ 	lui	$at,%hi(var7f1ac7cc)
/*  f0a33e0:	c42ac7cc */ 	lwc1	$f10,%lo(var7f1ac7cc)($at)
/*  f0a33e4:	3c017f1b */ 	lui	$at,%hi(var7f1ac7d0)
/*  f0a33e8:	c424c7d0 */ 	lwc1	$f4,%lo(var7f1ac7d0)($at)
/*  f0a33ec:	460a6482 */ 	mul.s	$f18,$f12,$f10
/*  f0a33f0:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f0a33f4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0a33f8:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0a33fc:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0a3400:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3404:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0a3408:	0c005923 */ 	jal	func0001648c
/*  f0a340c:	e7a80040 */ 	swc1	$f8,0x40($sp)
/*  f0a3410:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f0a3414:	0c0056f8 */ 	jal	func00015be0
/*  f0a3418:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f0a341c:	3c014080 */ 	lui	$at,0x4080
/*  f0a3420:	44818000 */ 	mtc1	$at,$f16
/*  f0a3424:	c60a06d0 */ 	lwc1	$f10,0x6d0($s0)
/*  f0a3428:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0a342c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a3430:	460a8482 */ 	mul.s	$f18,$f16,$f10
/*  f0a3434:	c4c40004 */ 	lwc1	$f4,0x4($a2)
/*  f0a3438:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f0a343c:	e4c60004 */ 	swc1	$f6,0x4($a2)
/*  f0a3440:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0a3444:	51800006 */ 	beqzl	$t4,.L0f0a3460
/*  f0a3448:	44811000 */ 	mtc1	$at,$f2
/*  f0a344c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a3450:	44811000 */ 	mtc1	$at,$f2
/*  f0a3454:	10000004 */ 	beqz	$zero,.L0f0a3468
/*  f0a3458:	c60006d0 */ 	lwc1	$f0,0x6d0($s0)
/*  f0a345c:	44811000 */ 	mtc1	$at,$f2
.L0f0a3460:
/*  f0a3460:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3464:	c60006d0 */ 	lwc1	$f0,0x6d0($s0)
.L0f0a3468:
/*  f0a3468:	c4c80000 */ 	lwc1	$f8,0x0($a2)
/*  f0a346c:	46000400 */ 	add.s	$f16,$f0,$f0
/*  f0a3470:	46028282 */ 	mul.s	$f10,$f16,$f2
/*  f0a3474:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0a3478:	e4c40000 */ 	swc1	$f4,0x0($a2)
/*  f0a347c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0a3480:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a3484:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0a3488:	03e00008 */ 	jr	$ra
/*  f0a348c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a3490
/*  f0a3490:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0a3494:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0a3498:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a349c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0a34a0:	808e0004 */ 	lb	$t6,0x4($a0)
/*  f0a34a4:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a34a8:	00808025 */ 	or	$s0,$a0,$zero
/*  f0a34ac:	11c00015 */ 	beqz	$t6,.L0f0a3504
/*  f0a34b0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a34b4:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0a34b8:	10c10003 */ 	beq	$a2,$at,.L0f0a34c8
/*  f0a34bc:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0a34c0:	14c1000b */ 	bne	$a2,$at,.L0f0a34f0
/*  f0a34c4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a34c8:
/*  f0a34c8:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f0a34cc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a34d0:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0a34d4:	1701000b */ 	bne	$t8,$at,.L0f0a3504
/*  f0a34d8:	3c017f1b */ 	lui	$at,%hi(var7f1ac7d4)
/*  f0a34dc:	c426c7d4 */ 	lwc1	$f6,%lo(var7f1ac7d4)($at)
/*  f0a34e0:	c6040780 */ 	lwc1	$f4,0x780($s0)
/*  f0a34e4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0a34e8:	10000006 */ 	beqz	$zero,.L0f0a3504
/*  f0a34ec:	e6080780 */ 	swc1	$f8,0x780($s0)
.L0f0a34f0:
/*  f0a34f0:	3c017f1b */ 	lui	$at,%hi(var7f1ac7d8)
/*  f0a34f4:	c430c7d8 */ 	lwc1	$f16,%lo(var7f1ac7d8)($at)
/*  f0a34f8:	c60a0780 */ 	lwc1	$f10,0x780($s0)
/*  f0a34fc:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f0a3500:	e6120780 */ 	swc1	$f18,0x780($s0)
.L0f0a3504:
/*  f0a3504:	3c0142f0 */ 	lui	$at,0x42f0
/*  f0a3508:	44813000 */ 	mtc1	$at,$f6
/*  f0a350c:	c4640044 */ 	lwc1	$f4,0x44($v1)
/*  f0a3510:	c60a0780 */ 	lwc1	$f10,0x780($s0)
/*  f0a3514:	44801000 */ 	mtc1	$zero,$f2
/*  f0a3518:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f0a351c:	46085401 */ 	sub.s	$f16,$f10,$f8
/*  f0a3520:	e6100780 */ 	swc1	$f16,0x780($s0)
/*  f0a3524:	c6120780 */ 	lwc1	$f18,0x780($s0)
/*  f0a3528:	4602903c */ 	c.lt.s	$f18,$f2
/*  f0a352c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3530:	45000002 */ 	bc1f	.L0f0a353c
/*  f0a3534:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3538:	e6020780 */ 	swc1	$f2,0x780($s0)
.L0f0a353c:
/*  f0a353c:	50e00068 */ 	beqzl	$a3,.L0f0a36e0
/*  f0a3540:	820c06d7 */ 	lb	$t4,0x6d7($s0)
/*  f0a3544:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f0a3548:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a354c:	332800ff */ 	andi	$t0,$t9,0xff
/*  f0a3550:	55010063 */ 	bnel	$t0,$at,.L0f0a36e0
/*  f0a3554:	820c06d7 */ 	lb	$t4,0x6d7($s0)
/*  f0a3558:	8c690284 */ 	lw	$t1,0x284($v1)
/*  f0a355c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a3560:	44810000 */ 	mtc1	$at,$f0
/*  f0a3564:	812a0de4 */ 	lb	$t2,0xde4($t1)
/*  f0a3568:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f0a356c:	51400004 */ 	beqzl	$t2,.L0f0a3580
/*  f0a3570:	920b06d7 */ 	lbu	$t3,0x6d7($s0)
/*  f0a3574:	44810000 */ 	mtc1	$at,$f0
/*  f0a3578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a357c:	920b06d7 */ 	lbu	$t3,0x6d7($s0)
.L0f0a3580:
/*  f0a3580:	24cdfffe */ 	addiu	$t5,$a2,-2
/*  f0a3584:	2da10013 */ 	sltiu	$at,$t5,0x13
/*  f0a3588:	316cffbf */ 	andi	$t4,$t3,0xffbf
/*  f0a358c:	10200053 */ 	beqz	$at,.L0f0a36dc
/*  f0a3590:	a20c06d7 */ 	sb	$t4,0x6d7($s0)
/*  f0a3594:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0a3598:	3c017f1b */ 	lui	$at,%hi(var7f1ac7dc)
/*  f0a359c:	002d0821 */ 	addu	$at,$at,$t5
/*  f0a35a0:	8c2dc7dc */ 	lw	$t5,%lo(var7f1ac7dc)($at)
/*  f0a35a4:	01a00008 */ 	jr	$t5
/*  f0a35a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a35ac:	c6060780 */ 	lwc1	$f6,0x780($s0)
/*  f0a35b0:	3c017f1b */ 	lui	$at,%hi(var7f1ac828)
/*  f0a35b4:	c424c828 */ 	lwc1	$f4,%lo(var7f1ac828)($at)
/*  f0a35b8:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f0a35bc:	460a203c */ 	c.lt.s	$f4,$f10
/*  f0a35c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a35c4:	45020046 */ 	bc1fl	.L0f0a36e0
/*  f0a35c8:	820c06d7 */ 	lb	$t4,0x6d7($s0)
/*  f0a35cc:	920f06d7 */ 	lbu	$t7,0x6d7($s0)
/*  f0a35d0:	35f80080 */ 	ori	$t8,$t7,0x80
/*  f0a35d4:	10000041 */ 	beqz	$zero,.L0f0a36dc
/*  f0a35d8:	a21806d7 */ 	sb	$t8,0x6d7($s0)
/*  f0a35dc:	c6100780 */ 	lwc1	$f16,0x780($s0)
/*  f0a35e0:	3c013f40 */ 	lui	$at,0x3f40
/*  f0a35e4:	44814000 */ 	mtc1	$at,$f8
/*  f0a35e8:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0a35ec:	4612403c */ 	c.lt.s	$f8,$f18
/*  f0a35f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a35f4:	4502003a */ 	bc1fl	.L0f0a36e0
/*  f0a35f8:	820c06d7 */ 	lb	$t4,0x6d7($s0)
/*  f0a35fc:	920806d7 */ 	lbu	$t0,0x6d7($s0)
/*  f0a3600:	35090080 */ 	ori	$t1,$t0,0x80
/*  f0a3604:	10000035 */ 	beqz	$zero,.L0f0a36dc
/*  f0a3608:	a20906d7 */ 	sb	$t1,0x6d7($s0)
/*  f0a360c:	c6040780 */ 	lwc1	$f4,0x780($s0)
/*  f0a3610:	3c017f1b */ 	lui	$at,%hi(var7f1ac82c)
/*  f0a3614:	c426c82c */ 	lwc1	$f6,%lo(var7f1ac82c)($at)
/*  f0a3618:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0a361c:	460a303c */ 	c.lt.s	$f6,$f10
/*  f0a3620:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3624:	4502002e */ 	bc1fl	.L0f0a36e0
/*  f0a3628:	820c06d7 */ 	lb	$t4,0x6d7($s0)
/*  f0a362c:	920b06d7 */ 	lbu	$t3,0x6d7($s0)
/*  f0a3630:	356c0080 */ 	ori	$t4,$t3,0x80
/*  f0a3634:	10000029 */ 	beqz	$zero,.L0f0a36dc
/*  f0a3638:	a20c06d7 */ 	sb	$t4,0x6d7($s0)
/*  f0a363c:	920d06d7 */ 	lbu	$t5,0x6d7($s0)
/*  f0a3640:	8e180558 */ 	lw	$t8,0x558($s0)
/*  f0a3644:	31aeffbf */ 	andi	$t6,$t5,0xffbf
/*  f0a3648:	35cf0040 */ 	ori	$t7,$t6,0x40
/*  f0a364c:	2b01000f */ 	slti	$at,$t8,0xf
/*  f0a3650:	14200022 */ 	bnez	$at,.L0f0a36dc
/*  f0a3654:	a20f06d7 */ 	sb	$t7,0x6d7($s0)
/*  f0a3658:	35e90080 */ 	ori	$t1,$t7,0x80
/*  f0a365c:	1000001f */ 	beqz	$zero,.L0f0a36dc
/*  f0a3660:	a20906d7 */ 	sb	$t1,0x6d7($s0)
/*  f0a3664:	8e0a0558 */ 	lw	$t2,0x558($s0)
/*  f0a3668:	29410015 */ 	slti	$at,$t2,0x15
/*  f0a366c:	54200005 */ 	bnezl	$at,.L0f0a3684
/*  f0a3670:	920f06d7 */ 	lbu	$t7,0x6d7($s0)
/*  f0a3674:	920c06d7 */ 	lbu	$t4,0x6d7($s0)
/*  f0a3678:	358d0080 */ 	ori	$t5,$t4,0x80
/*  f0a367c:	a20d06d7 */ 	sb	$t5,0x6d7($s0)
/*  f0a3680:	920f06d7 */ 	lbu	$t7,0x6d7($s0)
.L0f0a3684:
/*  f0a3684:	35f80040 */ 	ori	$t8,$t7,0x40
/*  f0a3688:	10000014 */ 	beqz	$zero,.L0f0a36dc
/*  f0a368c:	a21806d7 */ 	sb	$t8,0x6d7($s0)
/*  f0a3690:	921906d7 */ 	lbu	$t9,0x6d7($s0)
/*  f0a3694:	8e0a0558 */ 	lw	$t2,0x558($s0)
/*  f0a3698:	3328ffbf */ 	andi	$t0,$t9,0xffbf
/*  f0a369c:	35090040 */ 	ori	$t1,$t0,0x40
/*  f0a36a0:	2941001a */ 	slti	$at,$t2,0x1a
/*  f0a36a4:	1420000d */ 	bnez	$at,.L0f0a36dc
/*  f0a36a8:	a20906d7 */ 	sb	$t1,0x6d7($s0)
/*  f0a36ac:	352d0080 */ 	ori	$t5,$t1,0x80
/*  f0a36b0:	1000000a */ 	beqz	$zero,.L0f0a36dc
/*  f0a36b4:	a20d06d7 */ 	sb	$t5,0x6d7($s0)
/*  f0a36b8:	920f06d7 */ 	lbu	$t7,0x6d7($s0)
/*  f0a36bc:	35f80040 */ 	ori	$t8,$t7,0x40
/*  f0a36c0:	a21806d7 */ 	sb	$t8,0x6d7($s0)
/*  f0a36c4:	82190004 */ 	lb	$t9,0x4($s0)
/*  f0a36c8:	53200005 */ 	beqzl	$t9,.L0f0a36e0
/*  f0a36cc:	820c06d7 */ 	lb	$t4,0x6d7($s0)
/*  f0a36d0:	920906d7 */ 	lbu	$t1,0x6d7($s0)
/*  f0a36d4:	352a0080 */ 	ori	$t2,$t1,0x80
/*  f0a36d8:	a20a06d7 */ 	sb	$t2,0x6d7($s0)
.L0f0a36dc:
/*  f0a36dc:	820c06d7 */ 	lb	$t4,0x6d7($s0)
.L0f0a36e0:
/*  f0a36e0:	24d9fffe */ 	addiu	$t9,$a2,-2
/*  f0a36e4:	0583002f */ 	bgezl	$t4,.L0f0a37a4
/*  f0a36e8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0a36ec:	8e0d0604 */ 	lw	$t5,0x604($s0)
/*  f0a36f0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0a36f4:	55a10005 */ 	bnel	$t5,$at,.L0f0a370c
/*  f0a36f8:	2f210013 */ 	sltiu	$at,$t9,0x13
/*  f0a36fc:	8e0e06d4 */ 	lw	$t6,0x6d4($s0)
/*  f0a3700:	000ec640 */ 	sll	$t8,$t6,0x19
/*  f0a3704:	07010026 */ 	bgez	$t8,.L0f0a37a0
/*  f0a3708:	2f210013 */ 	sltiu	$at,$t9,0x13
.L0f0a370c:
/*  f0a370c:	1020000c */ 	beqz	$at,.L0f0a3740
/*  f0a3710:	24020011 */ 	addiu	$v0,$zero,0x11
/*  f0a3714:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0a3718:	3c017f1b */ 	lui	$at,%hi(var7f1ac830)
/*  f0a371c:	00390821 */ 	addu	$at,$at,$t9
/*  f0a3720:	8c39c830 */ 	lw	$t9,%lo(var7f1ac830)($at)
/*  f0a3724:	03200008 */ 	jr	$t9
/*  f0a3728:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a372c:	10000004 */ 	beqz	$zero,.L0f0a3740
/*  f0a3730:	2402000f */ 	addiu	$v0,$zero,0xf
/*  f0a3734:	10000002 */ 	beqz	$zero,.L0f0a3740
/*  f0a3738:	24020010 */ 	addiu	$v0,$zero,0x10
/*  f0a373c:	24020012 */ 	addiu	$v0,$zero,0x12
.L0f0a3740:
/*  f0a3740:	8c680284 */ 	lw	$t0,0x284($v1)
/*  f0a3744:	240affff */ 	addiu	$t2,$zero,-1
/*  f0a3748:	00023400 */ 	sll	$a2,$v0,0x10
/*  f0a374c:	8d091ba0 */ 	lw	$t1,0x1ba0($t0)
/*  f0a3750:	a7aa0026 */ 	sh	$t2,0x26($sp)
/*  f0a3754:	00065c03 */ 	sra	$t3,$a2,0x10
/*  f0a3758:	a7a90024 */ 	sh	$t1,0x24($sp)
/*  f0a375c:	c6100374 */ 	lwc1	$f16,0x374($s0)
/*  f0a3760:	01603025 */ 	or	$a2,$t3,$zero
/*  f0a3764:	27a40028 */ 	addiu	$a0,$sp,0x28
/*  f0a3768:	e7b00028 */ 	swc1	$f16,0x28($sp)
/*  f0a376c:	c6080378 */ 	lwc1	$f8,0x378($s0)
/*  f0a3770:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f0a3774:	e7a8002c */ 	swc1	$f8,0x2c($sp)
/*  f0a3778:	c612037c */ 	lwc1	$f18,0x37c($s0)
/*  f0a377c:	e7b20030 */ 	swc1	$f18,0x30($sp)
/*  f0a3780:	e6020780 */ 	swc1	$f2,0x780($s0)
/*  f0a3784:	0fc4b915 */ 	jal	func0f12e454
/*  f0a3788:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f0a378c:	50400005 */ 	beqzl	$v0,.L0f0a37a4
/*  f0a3790:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0a3794:	920c06d7 */ 	lbu	$t4,0x6d7($s0)
/*  f0a3798:	318dff7f */ 	andi	$t5,$t4,0xff7f
/*  f0a379c:	a20d06d7 */ 	sb	$t5,0x6d7($s0)
.L0f0a37a0:
/*  f0a37a0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0a37a4:
/*  f0a37a4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a37a8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0a37ac:	03e00008 */ 	jr	$ra
/*  f0a37b0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a37b4
/*  f0a37b4:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0a37b8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a37bc:	00808025 */ 	or	$s0,$a0,$zero
/*  f0a37c0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0a37c4:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0a37c8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0a37cc:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f0a37d0:	afa700a4 */ 	sw	$a3,0xa4($sp)
/*  f0a37d4:	0c006a47 */ 	jal	func0001a91c
/*  f0a37d8:	24050034 */ 	addiu	$a1,$zero,0x34
/*  f0a37dc:	104000ac */ 	beqz	$v0,.L0f0a3a90
/*  f0a37e0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a37e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a37e8:	0c006949 */ 	jal	func0001a524
/*  f0a37ec:	afa20094 */ 	sw	$v0,0x94($sp)
/*  f0a37f0:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f0a37f4:	00027980 */ 	sll	$t7,$v0,0x6
/*  f0a37f8:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f0a37fc:	c4640030 */ 	lwc1	$f4,0x30($v1)
/*  f0a3800:	e7a40064 */ 	swc1	$f4,0x64($sp)
/*  f0a3804:	c4660034 */ 	lwc1	$f6,0x34($v1)
/*  f0a3808:	e7a60068 */ 	swc1	$f6,0x68($sp)
/*  f0a380c:	c4680038 */ 	lwc1	$f8,0x38($v1)
/*  f0a3810:	0fc2d5de */ 	jal	func0f0b5778
/*  f0a3814:	e7a8006c */ 	swc1	$f8,0x6c($sp)
/*  f0a3818:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a381c:	0c0056d9 */ 	jal	func00015b64
/*  f0a3820:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0a3824:	8e1800b4 */ 	lw	$t8,0xb4($s0)
/*  f0a3828:	3c02800a */ 	lui	$v0,0x800a
/*  f0a382c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a3830:	17000009 */ 	bnez	$t8,.L0f0a3858
/*  f0a3834:	260402b4 */ 	addiu	$a0,$s0,0x2b4
/*  f0a3838:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a383c:	8c481c54 */ 	lw	$t0,0x1c54($v0)
/*  f0a3840:	8c5900c4 */ 	lw	$t9,0xc4($v0)
/*  f0a3844:	01004827 */ 	nor	$t1,$t0,$zero
/*  f0a3848:	03295024 */ 	and	$t2,$t9,$t1
/*  f0a384c:	314b0002 */ 	andi	$t3,$t2,0x2
/*  f0a3850:	51600044 */ 	beqzl	$t3,.L0f0a3964
/*  f0a3854:	8e0c068c */ 	lw	$t4,0x68c($s0)
.L0f0a3858:
/*  f0a3858:	44801000 */ 	mtc1	$zero,$f2
/*  f0a385c:	44815000 */ 	mtc1	$at,$f10
/*  f0a3860:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0a3864:	e7a20088 */ 	swc1	$f2,0x88($sp)
/*  f0a3868:	e7a2008c */ 	swc1	$f2,0x8c($sp)
/*  f0a386c:	0c0056c4 */ 	jal	func00015b10
/*  f0a3870:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f0a3874:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f0a3878:	c7b2008c */ 	lwc1	$f18,0x8c($sp)
/*  f0a387c:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*  f0a3880:	c7a60064 */ 	lwc1	$f6,0x64($sp)
/*  f0a3884:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*  f0a3888:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f0a388c:	e7b00048 */ 	swc1	$f16,0x48($sp)
/*  f0a3890:	e7b2004c */ 	swc1	$f18,0x4c($sp)
/*  f0a3894:	e7a40050 */ 	swc1	$f4,0x50($sp)
/*  f0a3898:	e7a6003c */ 	swc1	$f6,0x3c($sp)
/*  f0a389c:	e7a80040 */ 	swc1	$f8,0x40($sp)
/*  f0a38a0:	0fc2d5be */ 	jal	func0f0b56f8
/*  f0a38a4:	e7aa0044 */ 	swc1	$f10,0x44($sp)
/*  f0a38a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a38ac:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f0a38b0:	0c0056da */ 	jal	0x15b68
/*  f0a38b4:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0a38b8:	0fc2d5de */ 	jal	func0f0b5778
/*  f0a38bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a38c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a38c4:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f0a38c8:	0c0056c5 */ 	jal	0x15b14
/*  f0a38cc:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f0a38d0:	3c0143fa */ 	lui	$at,0x43fa
/*  f0a38d4:	44810000 */ 	mtc1	$at,$f0
/*  f0a38d8:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f0a38dc:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f0a38e0:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*  f0a38e4:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0a38e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a38ec:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0a38f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a38f4:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0a38f8:	e7b20088 */ 	swc1	$f18,0x88($sp)
/*  f0a38fc:	e7a6008c */ 	swc1	$f6,0x8c($sp)
/*  f0a3900:	0fc2d5de */ 	jal	func0f0b5778
/*  f0a3904:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f0a3908:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a390c:	0c0056c4 */ 	jal	func00015b10
/*  f0a3910:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0a3914:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f0a3918:	c7b20064 */ 	lwc1	$f18,0x64($sp)
/*  f0a391c:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*  f0a3920:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*  f0a3924:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0a3928:	c7b2006c */ 	lwc1	$f18,0x6c($sp)
/*  f0a392c:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f0a3930:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0a3934:	e7a40088 */ 	swc1	$f4,0x88($sp)
/*  f0a3938:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0a393c:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0a3940:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f0a3944:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a3948:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0a394c:	e7a40090 */ 	swc1	$f4,0x90($sp)
/*  f0a3950:	0fc2c09a */ 	jal	func0f0b0268
/*  f0a3954:	27a70088 */ 	addiu	$a3,$sp,0x88
/*  f0a3958:	1000004e */ 	beqz	$zero,.L0f0a3a94
/*  f0a395c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0a3960:	8e0c068c */ 	lw	$t4,0x68c($s0)
.L0f0a3964:
/*  f0a3964:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a3968:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a396c:	15810002 */ 	bne	$t4,$at,.L0f0a3978
/*  f0a3970:	24441660 */ 	addiu	$a0,$v0,0x1660
/*  f0a3974:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a3978:
/*  f0a3978:	10600012 */ 	beqz	$v1,.L0f0a39c4
/*  f0a397c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0a3980:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0a3984:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a3988:	0c006949 */ 	jal	func0001a524
/*  f0a398c:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f0a3990:	44801000 */ 	mtc1	$zero,$f2
/*  f0a3994:	3c0143fa */ 	lui	$at,0x43fa
/*  f0a3998:	44810000 */ 	mtc1	$at,$f0
/*  f0a399c:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f0a39a0:	00027180 */ 	sll	$t6,$v0,0x6
/*  f0a39a4:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0a39a8:	e7a20088 */ 	swc1	$f2,0x88($sp)
/*  f0a39ac:	e7a2008c */ 	swc1	$f2,0x8c($sp)
/*  f0a39b0:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f0a39b4:	0c0056d9 */ 	jal	func00015b64
/*  f0a39b8:	01ae2021 */ 	addu	$a0,$t5,$t6
/*  f0a39bc:	10000011 */ 	beqz	$zero,.L0f0a3a04
/*  f0a39c0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a39c4:
/*  f0a39c4:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0a39c8:	0fc2d30f */ 	jal	func0f0b4c3c
/*  f0a39cc:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f0a39d0:	3c0143fa */ 	lui	$at,0x43fa
/*  f0a39d4:	44810000 */ 	mtc1	$at,$f0
/*  f0a39d8:	c7a60088 */ 	lwc1	$f6,0x88($sp)
/*  f0a39dc:	c7aa008c */ 	lwc1	$f10,0x8c($sp)
/*  f0a39e0:	c7b20090 */ 	lwc1	$f18,0x90($sp)
/*  f0a39e4:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a39e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a39ec:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0a39f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a39f4:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0a39f8:	e7a80088 */ 	swc1	$f8,0x88($sp)
/*  f0a39fc:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*  f0a3a00:	e7a40090 */ 	swc1	$f4,0x90($sp)
.L0f0a3a04:
/*  f0a3a04:	0fc2d5de */ 	jal	func0f0b5778
/*  f0a3a08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3a0c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a3a10:	0c0056d9 */ 	jal	func00015b64
/*  f0a3a14:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0a3a18:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0a3a1c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a3a20:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0a3a24:	0fc2c09a */ 	jal	func0f0b0268
/*  f0a3a28:	27a70088 */ 	addiu	$a3,$sp,0x88
/*  f0a3a2c:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0a3a30:	55e00018 */ 	bnezl	$t7,.L0f0a3a94
/*  f0a3a34:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0a3a38:	8e1806b4 */ 	lw	$t8,0x6b4($s0)
/*  f0a3a3c:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f0a3a40:	53000014 */ 	beqzl	$t8,.L0f0a3a94
/*  f0a3a44:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0a3a48:	55000012 */ 	bnezl	$t0,.L0f0a3a94
/*  f0a3a4c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0a3a50:	c60606b8 */ 	lwc1	$f6,0x6b8($s0)
/*  f0a3a54:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0a3a58:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f0a3a5c:	e7a6007c */ 	swc1	$f6,0x7c($sp)
/*  f0a3a60:	c60806bc */ 	lwc1	$f8,0x6bc($s0)
/*  f0a3a64:	27a60070 */ 	addiu	$a2,$sp,0x70
/*  f0a3a68:	e7a80080 */ 	swc1	$f8,0x80($sp)
/*  f0a3a6c:	c60a06c0 */ 	lwc1	$f10,0x6c0($s0)
/*  f0a3a70:	e7aa0084 */ 	swc1	$f10,0x84($sp)
/*  f0a3a74:	c61006c4 */ 	lwc1	$f16,0x6c4($s0)
/*  f0a3a78:	e7b00070 */ 	swc1	$f16,0x70($sp)
/*  f0a3a7c:	c61206c8 */ 	lwc1	$f18,0x6c8($s0)
/*  f0a3a80:	e7b20074 */ 	swc1	$f18,0x74($sp)
/*  f0a3a84:	c60406cc */ 	lwc1	$f4,0x6cc($s0)
/*  f0a3a88:	0fc2c0d0 */ 	jal	func0f0b0340
/*  f0a3a8c:	e7a40078 */ 	swc1	$f4,0x78($sp)
.L0f0a3a90:
/*  f0a3a90:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0a3a94:
/*  f0a3a94:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a3a98:	27bd0098 */ 	addiu	$sp,$sp,0x98
/*  f0a3a9c:	03e00008 */ 	jr	$ra
/*  f0a3aa0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a3aa4
/*  f0a3aa4:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0a3aa8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0a3aac:	00808025 */ 	or	$s0,$a0,$zero
/*  f0a3ab0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0a3ab4:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f0a3ab8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0a3abc:	0c006a47 */ 	jal	func0001a91c
/*  f0a3ac0:	2405002c */ 	addiu	$a1,$zero,0x2c
/*  f0a3ac4:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f0a3ac8:	c6000244 */ 	lwc1	$f0,0x244($s0)
/*  f0a3acc:	c6020240 */ 	lwc1	$f2,0x240($s0)
/*  f0a3ad0:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0a3ad4:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0a3ad8:	4602003e */ 	c.le.s	$f0,$f2
/*  f0a3adc:	3c017f1b */ 	lui	$at,%hi(var7f1ac87c)
/*  f0a3ae0:	45020017 */ 	bc1fl	.L0f0a3b40
/*  f0a3ae4:	c4900044 */ 	lwc1	$f16,0x44($a0)
/*  f0a3ae8:	44806000 */ 	mtc1	$zero,$f12
/*  f0a3aec:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a3af0:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0a3af4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3af8:	4500000e */ 	bc1f	.L0f0a3b34
/*  f0a3afc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3b00:	c424c87c */ 	lwc1	$f4,%lo(var7f1ac87c)($at)
/*  f0a3b04:	3c01800a */ 	lui	$at,0x800a
/*  f0a3b08:	c426a004 */ 	lwc1	$f6,-0x5ffc($at)
/*  f0a3b0c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0a3b10:	46081280 */ 	add.s	$f10,$f2,$f8
/*  f0a3b14:	e60a0240 */ 	swc1	$f10,0x240($s0)
/*  f0a3b18:	c6020240 */ 	lwc1	$f2,0x240($s0)
/*  f0a3b1c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0a3b20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3b24:	45000003 */ 	bc1f	.L0f0a3b34
/*  f0a3b28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3b2c:	e60c0240 */ 	swc1	$f12,0x240($s0)
/*  f0a3b30:	c6020240 */ 	lwc1	$f2,0x240($s0)
.L0f0a3b34:
/*  f0a3b34:	10000023 */ 	beqz	$zero,.L0f0a3bc4
/*  f0a3b38:	e6020244 */ 	swc1	$f2,0x244($s0)
/*  f0a3b3c:	c4900044 */ 	lwc1	$f16,0x44($a0)
.L0f0a3b40:
/*  f0a3b40:	d424c880 */ 	ldc1	$f4,-0x3780($at)
/*  f0a3b44:	3c017f1b */ 	lui	$at,%hi(var7f1ac888)
/*  f0a3b48:	460084a1 */ 	cvt.d.s	$f18,$f16
/*  f0a3b4c:	c428c888 */ 	lwc1	$f8,%lo(var7f1ac888)($at)
/*  f0a3b50:	46249182 */ 	mul.d	$f6,$f18,$f4
/*  f0a3b54:	3c017f1b */ 	lui	$at,%hi(var7f1ac88c)
/*  f0a3b58:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0a3b5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3b60:	4500000e */ 	bc1f	.L0f0a3b9c
/*  f0a3b64:	46203320 */ 	cvt.s.d	$f12,$f6
/*  f0a3b68:	c42ac88c */ 	lwc1	$f10,%lo(var7f1ac88c)($at)
/*  f0a3b6c:	3c017f1b */ 	lui	$at,%hi(var7f1ac890)
/*  f0a3b70:	e60a0240 */ 	swc1	$f10,0x240($s0)
/*  f0a3b74:	c430c890 */ 	lwc1	$f16,%lo(var7f1ac890)($at)
/*  f0a3b78:	3c014080 */ 	lui	$at,0x4080
/*  f0a3b7c:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0a3b80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3b84:	45020006 */ 	bc1fl	.L0f0a3ba0
/*  f0a3b88:	c6040240 */ 	lwc1	$f4,0x240($s0)
/*  f0a3b8c:	44819000 */ 	mtc1	$at,$f18
/*  f0a3b90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3b94:	46126302 */ 	mul.s	$f12,$f12,$f18
/*  f0a3b98:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a3b9c:
/*  f0a3b9c:	c6040240 */ 	lwc1	$f4,0x240($s0)
.L0f0a3ba0:
/*  f0a3ba0:	46040081 */ 	sub.s	$f2,$f0,$f4
/*  f0a3ba4:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0a3ba8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3bac:	45020003 */ 	bc1fl	.L0f0a3bbc
/*  f0a3bb0:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f0a3bb4:	46006086 */ 	mov.s	$f2,$f12
/*  f0a3bb8:	46020181 */ 	sub.s	$f6,$f0,$f2
.L0f0a3bbc:
/*  f0a3bbc:	44806000 */ 	mtc1	$zero,$f12
/*  f0a3bc0:	e6060244 */ 	swc1	$f6,0x244($s0)
.L0f0a3bc4:
/*  f0a3bc4:	c6000244 */ 	lwc1	$f0,0x244($s0)
/*  f0a3bc8:	3c017f1b */ 	lui	$at,%hi(var7f1ac894)
/*  f0a3bcc:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0a3bd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3bd4:	45000017 */ 	bc1f	.L0f0a3c34
/*  f0a3bd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3bdc:	c428c894 */ 	lwc1	$f8,%lo(var7f1ac894)($at)
/*  f0a3be0:	46080302 */ 	mul.s	$f12,$f0,$f8
/*  f0a3be4:	0c0068f4 */ 	jal	func0001a3d0
/*  f0a3be8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3bec:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a3bf0:	44815000 */ 	mtc1	$at,$f10
/*  f0a3bf4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a3bf8:	44819000 */ 	mtc1	$at,$f18
/*  f0a3bfc:	46005401 */ 	sub.s	$f16,$f10,$f0
/*  f0a3c00:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0a3c04:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0a3c08:	c4860044 */ 	lwc1	$f6,0x44($a0)
/*  f0a3c0c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0a3c10:	3c017f1b */ 	lui	$at,%hi(var7f1ac898)
/*  f0a3c14:	c42ac898 */ 	lwc1	$f10,%lo(var7f1ac898)($at)
/*  f0a3c18:	c612023c */ 	lwc1	$f18,0x23c($s0)
/*  f0a3c1c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0a3c20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3c24:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0a3c28:	46109101 */ 	sub.s	$f4,$f18,$f16
/*  f0a3c2c:	10000017 */ 	beqz	$zero,.L0f0a3c8c
/*  f0a3c30:	e604023c */ 	swc1	$f4,0x23c($s0)
.L0f0a3c34:
/*  f0a3c34:	3c017f1b */ 	lui	$at,%hi(var7f1ac89c)
/*  f0a3c38:	c426c89c */ 	lwc1	$f6,%lo(var7f1ac89c)($at)
/*  f0a3c3c:	46060302 */ 	mul.s	$f12,$f0,$f6
/*  f0a3c40:	0c0068f4 */ 	jal	func0001a3d0
/*  f0a3c44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3c48:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a3c4c:	44814000 */ 	mtc1	$at,$f8
/*  f0a3c50:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a3c54:	44819000 */ 	mtc1	$at,$f18
/*  f0a3c58:	46004281 */ 	sub.s	$f10,$f8,$f0
/*  f0a3c5c:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0a3c60:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0a3c64:	c4840044 */ 	lwc1	$f4,0x44($a0)
/*  f0a3c68:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f0a3c6c:	3c017f1b */ 	lui	$at,%hi(var7f1ac8a0)
/*  f0a3c70:	c428c8a0 */ 	lwc1	$f8,%lo(var7f1ac8a0)($at)
/*  f0a3c74:	c612023c */ 	lwc1	$f18,0x23c($s0)
/*  f0a3c78:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0a3c7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3c80:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0a3c84:	46125400 */ 	add.s	$f16,$f10,$f18
/*  f0a3c88:	e610023c */ 	swc1	$f16,0x23c($s0)
.L0f0a3c8c:
/*  f0a3c8c:	3c017f1b */ 	lui	$at,%hi(var7f1ac8a4)
/*  f0a3c90:	c422c8a4 */ 	lwc1	$f2,%lo(var7f1ac8a4)($at)
/*  f0a3c94:	c600023c */ 	lwc1	$f0,0x23c($s0)
/*  f0a3c98:	3c01800a */ 	lui	$at,0x800a
/*  f0a3c9c:	46020103 */ 	div.s	$f4,$f0,$f2
/*  f0a3ca0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a3ca4:	44023000 */ 	mfc1	$v0,$f6
/*  f0a3ca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3cac:	44824000 */ 	mtc1	$v0,$f8
/*  f0a3cb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3cb4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0a3cb8:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f0a3cbc:	46120401 */ 	sub.s	$f16,$f0,$f18
/*  f0a3cc0:	e610023c */ 	swc1	$f16,0x23c($s0)
/*  f0a3cc4:	c604023c */ 	lwc1	$f4,0x23c($s0)
/*  f0a3cc8:	e424d140 */ 	swc1	$f4,-0x2ec0($at)
/*  f0a3ccc:	8e03074c */ 	lw	$v1,0x74c($s0)
/*  f0a3cd0:	3c017f1b */ 	lui	$at,%hi(var7f1ac8a8)
/*  f0a3cd4:	14600019 */ 	bnez	$v1,.L0f0a3d3c
/*  f0a3cd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3cdc:	c422c8a8 */ 	lwc1	$f2,%lo(var7f1ac8a8)($at)
/*  f0a3ce0:	c6060244 */ 	lwc1	$f6,0x244($s0)
/*  f0a3ce4:	4606103c */ 	c.lt.s	$f2,$f6
/*  f0a3ce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3cec:	45000013 */ 	bc1f	.L0f0a3d3c
/*  f0a3cf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3cf4:	8c8f0034 */ 	lw	$t7,0x34($a0)
/*  f0a3cf8:	3c048009 */ 	lui	$a0,0x8009
/*  f0a3cfc:	2405805e */ 	addiu	$a1,$zero,-32674
/*  f0a3d00:	11e0000e */ 	beqz	$t7,.L0f0a3d3c
/*  f0a3d04:	2606074c */ 	addiu	$a2,$s0,0x74c
/*  f0a3d08:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a3d0c:	44814000 */ 	mtc1	$at,$f8
/*  f0a3d10:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0a3d14:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0a3d18:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0a3d1c:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0a3d20:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0a3d24:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0a3d28:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0a3d2c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a3d30:	0c004241 */ 	jal	func00010904
/*  f0a3d34:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0a3d38:	8e03074c */ 	lw	$v1,0x74c($s0)
.L0f0a3d3c:
/*  f0a3d3c:	3c017f1b */ 	lui	$at,%hi(var7f1ac8ac)
/*  f0a3d40:	1060002a */ 	beqz	$v1,.L0f0a3dec
/*  f0a3d44:	c422c8ac */ 	lwc1	$f2,%lo(var7f1ac8ac)($at)
/*  f0a3d48:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a3d4c:	44819000 */ 	mtc1	$at,$f18
/*  f0a3d50:	c60a0244 */ 	lwc1	$f10,0x244($s0)
/*  f0a3d54:	3c017f1b */ 	lui	$at,%hi(var7f1ac8b0)
/*  f0a3d58:	c424c8b0 */ 	lwc1	$f4,%lo(var7f1ac8b0)($at)
/*  f0a3d5c:	46125403 */ 	div.s	$f16,$f10,$f18
/*  f0a3d60:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f0a3d64:	3c017f1b */ 	lui	$at,%hi(var7f1ac8b4)
/*  f0a3d68:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0a3d6c:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f0a3d70:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f0a3d74:	c6000244 */ 	lwc1	$f0,0x244($s0)
/*  f0a3d78:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0a3d7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3d80:	45000005 */ 	bc1f	.L0f0a3d98
/*  f0a3d84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3d88:	0c00cec9 */ 	jal	func00033b24
/*  f0a3d8c:	8e04074c */ 	lw	$a0,0x74c($s0)
/*  f0a3d90:	10000017 */ 	beqz	$zero,.L0f0a3df0
/*  f0a3d94:	8faa0044 */ 	lw	$t2,0x44($sp)
.L0f0a3d98:
/*  f0a3d98:	c428c8b4 */ 	lwc1	$f8,%lo(var7f1ac8b4)($at)
/*  f0a3d9c:	3c017f1b */ 	lui	$at,%hi(var7f1ac8b8)
/*  f0a3da0:	4608003c */ 	c.lt.s	$f0,$f8
/*  f0a3da4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3da8:	4500000a */ 	bc1f	.L0f0a3dd4
/*  f0a3dac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a3db0:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f0a3db4:	c432c8b8 */ 	lwc1	$f18,%lo(var7f1ac8b8)($at)
/*  f0a3db8:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a3dbc:	44812000 */ 	mtc1	$at,$f4
/*  f0a3dc0:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f0a3dc4:	46048183 */ 	div.s	$f6,$f16,$f4
/*  f0a3dc8:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0a3dcc:	44064000 */ 	mfc1	$a2,$f8
/*  f0a3dd0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a3dd4:
/*  f0a3dd4:	0c00cf94 */ 	jal	func00033e50
/*  f0a3dd8:	8e04074c */ 	lw	$a0,0x74c($s0)
/*  f0a3ddc:	8e04074c */ 	lw	$a0,0x74c($s0)
/*  f0a3de0:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f0a3de4:	0c00cf94 */ 	jal	func00033e50
/*  f0a3de8:	8fa60034 */ 	lw	$a2,0x34($sp)
.L0f0a3dec:
/*  f0a3dec:	8faa0044 */ 	lw	$t2,0x44($sp)
.L0f0a3df0:
/*  f0a3df0:	1140000f */ 	beqz	$t2,.L0f0a3e30
/*  f0a3df4:	01402025 */ 	or	$a0,$t2,$zero
/*  f0a3df8:	0c006949 */ 	jal	func0001a524
/*  f0a3dfc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a3e00:	3c01800a */ 	lui	$at,0x800a
/*  f0a3e04:	ac22d0dc */ 	sw	$v0,-0x2f24($at)
/*  f0a3e08:	3c0b7f0a */ 	lui	$t3,0x7f0a
/*  f0a3e0c:	3c10800a */ 	lui	$s0,%hi(var8009d0f0)
/*  f0a3e10:	256b256c */ 	addiu	$t3,$t3,0x256c
/*  f0a3e14:	3c018006 */ 	lui	$at,0x8006
/*  f0a3e18:	2610d0f0 */ 	addiu	$s0,$s0,%lo(var8009d0f0)
/*  f0a3e1c:	ac2befcc */ 	sw	$t3,-0x1034($at)
/*  f0a3e20:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0a3e24:	ae0c0008 */ 	sw	$t4,0x8($s0)
/*  f0a3e28:	ae0c0004 */ 	sw	$t4,0x4($s0)
/*  f0a3e2c:	ae0c0000 */ 	sw	$t4,0x0($s0)
.L0f0a3e30:
/*  f0a3e30:	3c10800a */ 	lui	$s0,%hi(var8009d0f0)
/*  f0a3e34:	2610d0f0 */ 	addiu	$s0,$s0,%lo(var8009d0f0)
/*  f0a3e38:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*  f0a3e3c:	0c006a47 */ 	jal	func0001a91c
/*  f0a3e40:	2405002d */ 	addiu	$a1,$zero,0x2d
/*  f0a3e44:	10400004 */ 	beqz	$v0,.L0f0a3e58
/*  f0a3e48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a3e4c:	0c006949 */ 	jal	func0001a524
/*  f0a3e50:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a3e54:	ae020000 */ 	sw	$v0,0x0($s0)
.L0f0a3e58:
/*  f0a3e58:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*  f0a3e5c:	0c006a47 */ 	jal	func0001a91c
/*  f0a3e60:	2405002e */ 	addiu	$a1,$zero,0x2e
/*  f0a3e64:	10400004 */ 	beqz	$v0,.L0f0a3e78
/*  f0a3e68:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a3e6c:	0c006949 */ 	jal	func0001a524
/*  f0a3e70:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a3e74:	ae020004 */ 	sw	$v0,0x4($s0)
.L0f0a3e78:
/*  f0a3e78:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*  f0a3e7c:	0c006a47 */ 	jal	func0001a91c
/*  f0a3e80:	2405002f */ 	addiu	$a1,$zero,0x2f
/*  f0a3e84:	10400004 */ 	beqz	$v0,.L0f0a3e98
/*  f0a3e88:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a3e8c:	0c006949 */ 	jal	func0001a524
/*  f0a3e90:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a3e94:	ae020008 */ 	sw	$v0,0x8($s0)
.L0f0a3e98:
/*  f0a3e98:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0a3e9c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0a3ea0:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0a3ea4:	03e00008 */ 	jr	$ra
/*  f0a3ea8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a3eac
/*  f0a3eac:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f0a3eb0:	3c0f8007 */ 	lui	$t7,%hi(var8007021c)
/*  f0a3eb4:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f0a3eb8:	afb70050 */ 	sw	$s7,0x50($sp)
/*  f0a3ebc:	afb6004c */ 	sw	$s6,0x4c($sp)
/*  f0a3ec0:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f0a3ec4:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f0a3ec8:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f0a3ecc:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f0a3ed0:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0a3ed4:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0a3ed8:	f7ba0028 */ 	sdc1	$f26,0x28($sp)
/*  f0a3edc:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f0a3ee0:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f0a3ee4:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f0a3ee8:	25ef021c */ 	addiu	$t7,$t7,%lo(var8007021c)
/*  f0a3eec:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0a3ef0:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f0a3ef4:	27ae0088 */ 	addiu	$t6,$sp,0x88
/*  f0a3ef8:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0a3efc:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f0a3f00:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f0a3f04:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0a3f08:	00808025 */ 	or	$s0,$a0,$zero
/*  f0a3f0c:	00a0b825 */ 	or	$s7,$a1,$zero
/*  f0a3f10:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f0a3f14:	0fc2c536 */ 	jal	func0f0b14d8
/*  f0a3f18:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0a3f1c:	3c014000 */ 	lui	$at,0x4000
/*  f0a3f20:	44812000 */ 	mtc1	$at,$f4
/*  f0a3f24:	3c014268 */ 	lui	$at,0x4268
/*  f0a3f28:	44814000 */ 	mtc1	$at,$f8
/*  f0a3f2c:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0a3f30:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a3f34:	44818000 */ 	mtc1	$at,$f16
/*  f0a3f38:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a3f3c:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0a3f40:	2405002a */ 	addiu	$a1,$zero,0x2a
/*  f0a3f44:	0c006a47 */ 	jal	func0001a91c
/*  f0a3f48:	460a8681 */ 	sub.s	$f26,$f16,$f10
/*  f0a3f4c:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0a3f50:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a3f54:	0c006a47 */ 	jal	func0001a91c
/*  f0a3f58:	2405002b */ 	addiu	$a1,$zero,0x2b
/*  f0a3f5c:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f0a3f60:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a3f64:	0c006a47 */ 	jal	func0001a91c
/*  f0a3f68:	2405002c */ 	addiu	$a1,$zero,0x2c
/*  f0a3f6c:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0a3f70:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a3f74:	0c006a47 */ 	jal	func0001a91c
/*  f0a3f78:	2405002d */ 	addiu	$a1,$zero,0x2d
/*  f0a3f7c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0a3f80:	4481c000 */ 	mtc1	$at,$f24
/*  f0a3f84:	4480b000 */ 	mtc1	$zero,$f22
/*  f0a3f88:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f0a3f8c:	00009025 */ 	or	$s2,$zero,$zero
/*  f0a3f90:	00009825 */ 	or	$s3,$zero,$zero
/*  f0a3f94:	27b40098 */ 	addiu	$s4,$sp,0x98
/*  f0a3f98:	24160004 */ 	addiu	$s6,$zero,0x4
/*  f0a3f9c:	27b50070 */ 	addiu	$s5,$sp,0x70
.L0f0a3fa0:
/*  f0a3fa0:	8e840000 */ 	lw	$a0,0x0($s4)
/*  f0a3fa4:	3c014080 */ 	lui	$at,0x4080
/*  f0a3fa8:	50800028 */ 	beqzl	$a0,.L0f0a404c
/*  f0a3fac:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0a3fb0:	44819000 */ 	mtc1	$at,$f18
/*  f0a3fb4:	27a90088 */ 	addiu	$t1,$sp,0x88
/*  f0a3fb8:	02698821 */ 	addu	$s1,$s3,$t1
/*  f0a3fbc:	4612d502 */ 	mul.s	$f20,$f26,$f18
/*  f0a3fc0:	0c006949 */ 	jal	func0001a524
/*  f0a3fc4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a3fc8:	44922000 */ 	mtc1	$s2,$f4
/*  f0a3fcc:	00401825 */ 	or	$v1,$v0,$zero
/*  f0a3fd0:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0a3fd4:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0a3fd8:	4600a181 */ 	sub.s	$f6,$f20,$f0
/*  f0a3fdc:	45000002 */ 	bc1f	.L0f0a3fe8
/*  f0a3fe0:	e6260000 */ 	swc1	$f6,0x0($s1)
/*  f0a3fe4:	e6360000 */ 	swc1	$f22,0x0($s1)
.L0f0a3fe8:
/*  f0a3fe8:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*  f0a3fec:	00035180 */ 	sll	$t2,$v1,0x6
/*  f0a3ff0:	02ea8021 */ 	addu	$s0,$s7,$t2
/*  f0a3ff4:	46184402 */ 	mul.s	$f16,$f8,$f24
/*  f0a3ff8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a3ffc:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0a4000:	e6300000 */ 	swc1	$f16,0x0($s1)
/*  f0a4004:	e7b60070 */ 	swc1	$f22,0x70($sp)
/*  f0a4008:	e7b60074 */ 	swc1	$f22,0x74($sp)
/*  f0a400c:	c62a0000 */ 	lwc1	$f10,0x0($s1)
/*  f0a4010:	0c0056c4 */ 	jal	func00015b10
/*  f0a4014:	e7aa0078 */ 	swc1	$f10,0x78($sp)
/*  f0a4018:	c6120030 */ 	lwc1	$f18,0x30($s0)
/*  f0a401c:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f0a4020:	c6080034 */ 	lwc1	$f8,0x34($s0)
/*  f0a4024:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0a4028:	c6120038 */ 	lwc1	$f18,0x38($s0)
/*  f0a402c:	e6060030 */ 	swc1	$f6,0x30($s0)
/*  f0a4030:	c7b00074 */ 	lwc1	$f16,0x74($sp)
/*  f0a4034:	46104280 */ 	add.s	$f10,$f8,$f16
/*  f0a4038:	e60a0034 */ 	swc1	$f10,0x34($s0)
/*  f0a403c:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f0a4040:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0a4044:	e6060038 */ 	swc1	$f6,0x38($s0)
/*  f0a4048:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f0a404c:
/*  f0a404c:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f0a4050:	1656ffd3 */ 	bne	$s2,$s6,.L0f0a3fa0
/*  f0a4054:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f0a4058:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f0a405c:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f0a4060:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f0a4064:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f0a4068:	d7ba0028 */ 	ldc1	$f26,0x28($sp)
/*  f0a406c:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0a4070:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0a4074:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f0a4078:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0a407c:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f0a4080:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f0a4084:	8fb6004c */ 	lw	$s6,0x4c($sp)
/*  f0a4088:	8fb70050 */ 	lw	$s7,0x50($sp)
/*  f0a408c:	03e00008 */ 	jr	$ra
/*  f0a4090:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

GLOBAL_ASM(
glabel func0f0a4094
/*  f0a4094:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0a4098:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a409c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0a40a0:	00803825 */ 	or	$a3,$a0,$zero
/*  f0a40a4:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f0a40a8:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0a40ac:	0c006a47 */ 	jal	func0001a91c
/*  f0a40b0:	24050028 */ 	addiu	$a1,$zero,0x28
/*  f0a40b4:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f0a40b8:	10400034 */ 	beqz	$v0,.L0f0a418c
/*  f0a40bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a40c0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a40c4:	0c006949 */ 	jal	func0001a524
/*  f0a40c8:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f0a40cc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a40d0:	44811000 */ 	mtc1	$at,$f2
/*  f0a40d4:	3c017f1b */ 	lui	$at,%hi(var7f1ac8bc)
/*  f0a40d8:	c424c8bc */ 	lwc1	$f4,%lo(var7f1ac8bc)($at)
/*  f0a40dc:	3c01800a */ 	lui	$at,0x800a
/*  f0a40e0:	c426a004 */ 	lwc1	$f6,-0x5ffc($at)
/*  f0a40e4:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f0a40e8:	3c01c120 */ 	lui	$at,0xc120
/*  f0a40ec:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0a40f0:	c4ea0250 */ 	lwc1	$f10,0x250($a3)
/*  f0a40f4:	44819000 */ 	mtc1	$at,$f18
/*  f0a40f8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0a40fc:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f0a4100:	e4f00250 */ 	swc1	$f16,0x250($a3)
/*  f0a4104:	c4e00250 */ 	lwc1	$f0,0x250($a3)
/*  f0a4108:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a410c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4110:	45000003 */ 	bc1f	.L0f0a4120
/*  f0a4114:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4118:	e4e20250 */ 	swc1	$f2,0x250($a3)
/*  f0a411c:	c4e00250 */ 	lwc1	$f0,0x250($a3)
.L0f0a4120:
/*  f0a4120:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0a4124:	3c017f1b */ 	lui	$at,%hi(var7f1ac8c0)
/*  f0a4128:	c426c8c0 */ 	lwc1	$f6,%lo(var7f1ac8c0)($at)
/*  f0a412c:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0a4130:	44801000 */ 	mtc1	$zero,$f2
/*  f0a4134:	00037980 */ 	sll	$t7,$v1,0x6
/*  f0a4138:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f0a413c:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f0a4140:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f0a4144:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f0a4148:	e7a20028 */ 	swc1	$f2,0x28($sp)
/*  f0a414c:	e7a2002c */ 	swc1	$f2,0x2c($sp)
/*  f0a4150:	0c0056c4 */ 	jal	func00015b10
/*  f0a4154:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f0a4158:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0a415c:	c7b00024 */ 	lwc1	$f16,0x24($sp)
/*  f0a4160:	c4880030 */ 	lwc1	$f8,0x30($a0)
/*  f0a4164:	c4840034 */ 	lwc1	$f4,0x34($a0)
/*  f0a4168:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f0a416c:	c4880038 */ 	lwc1	$f8,0x38($a0)
/*  f0a4170:	e4920030 */ 	swc1	$f18,0x30($a0)
/*  f0a4174:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*  f0a4178:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0a417c:	e48a0034 */ 	swc1	$f10,0x34($a0)
/*  f0a4180:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f0a4184:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f0a4188:	e4920038 */ 	swc1	$f18,0x38($a0)
.L0f0a418c:
/*  f0a418c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a4190:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0a4194:	03e00008 */ 	jr	$ra
/*  f0a4198:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a419c
/*  f0a419c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0a41a0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0a41a4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a41a8:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0a41ac:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0a41b0:	808e0005 */ 	lb	$t6,0x5($a0)
/*  f0a41b4:	44801000 */ 	mtc1	$zero,$f2
/*  f0a41b8:	00808025 */ 	or	$s0,$a0,$zero
/*  f0a41bc:	11c00004 */ 	beqz	$t6,.L0f0a41d0
/*  f0a41c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a41c4:	44812000 */ 	mtc1	$at,$f4
/*  f0a41c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a41cc:	e484023c */ 	swc1	$f4,0x23c($a0)
.L0f0a41d0:
/*  f0a41d0:	c600023c */ 	lwc1	$f0,0x23c($s0)
/*  f0a41d4:	3c188007 */ 	lui	$t8,%hi(var8007022c)
/*  f0a41d8:	3c01800a */ 	lui	$at,0x800a
/*  f0a41dc:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a41e0:	2718022c */ 	addiu	$t8,$t8,%lo(var8007022c)
/*  f0a41e4:	27af0028 */ 	addiu	$t7,$sp,0x28
/*  f0a41e8:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0a41ec:	45020011 */ 	bc1fl	.L0f0a4234
/*  f0a41f0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a41f4:	c426a004 */ 	lwc1	$f6,-0x5ffc($at)
/*  f0a41f8:	3c0140c0 */ 	lui	$at,0x40c0
/*  f0a41fc:	44814000 */ 	mtc1	$at,$f8
/*  f0a4200:	3c017f1b */ 	lui	$at,%hi(var7f1ac8c4)
/*  f0a4204:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0a4208:	460a0401 */ 	sub.s	$f16,$f0,$f10
/*  f0a420c:	e610023c */ 	swc1	$f16,0x23c($s0)
/*  f0a4210:	c432c8c4 */ 	lwc1	$f18,%lo(var7f1ac8c4)($at)
/*  f0a4214:	c600023c */ 	lwc1	$f0,0x23c($s0)
/*  f0a4218:	4612003c */ 	c.lt.s	$f0,$f18
/*  f0a421c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4220:	45020004 */ 	bc1fl	.L0f0a4234
/*  f0a4224:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a4228:	e602023c */ 	swc1	$f2,0x23c($s0)
/*  f0a422c:	c600023c */ 	lwc1	$f0,0x23c($s0)
/*  f0a4230:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0a4234:
/*  f0a4234:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4238:	4502003a */ 	bc1fl	.L0f0a4324
/*  f0a423c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0a4240:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0a4244:	8f080004 */ 	lw	$t0,0x4($t8)
/*  f0a4248:	24050050 */ 	addiu	$a1,$zero,0x50
/*  f0a424c:	ade10000 */ 	sw	$at,0x0($t7)
/*  f0a4250:	8f010008 */ 	lw	$at,0x8($t8)
/*  f0a4254:	ade80004 */ 	sw	$t0,0x4($t7)
/*  f0a4258:	0c006a47 */ 	jal	func0001a91c
/*  f0a425c:	ade10008 */ 	sw	$at,0x8($t7)
/*  f0a4260:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f0a4264:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0a4268:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a426c:	1040002c */ 	beqz	$v0,.L0f0a4320
/*  f0a4270:	ad490000 */ 	sw	$t1,0x0($t2)
/*  f0a4274:	0c006949 */ 	jal	func0001a524
/*  f0a4278:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a427c:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f0a4280:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a4284:	44812000 */ 	mtc1	$at,$f4
/*  f0a4288:	c606023c */ 	lwc1	$f6,0x23c($s0)
/*  f0a428c:	3c014100 */ 	lui	$at,0x4100
/*  f0a4290:	44815000 */ 	mtc1	$at,$f10
/*  f0a4294:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0a4298:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a429c:	44819000 */ 	mtc1	$at,$f18
/*  f0a42a0:	8fab003c */ 	lw	$t3,0x3c($sp)
/*  f0a42a4:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0a42a8:	00026180 */ 	sll	$t4,$v0,0x6
/*  f0a42ac:	016c2821 */ 	addu	$a1,$t3,$t4
/*  f0a42b0:	0c0057aa */ 	jal	func00015ea8
/*  f0a42b4:	46128300 */ 	add.s	$f12,$f16,$f18
/*  f0a42b8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a42bc:	44810000 */ 	mtc1	$at,$f0
/*  f0a42c0:	c604023c */ 	lwc1	$f4,0x23c($s0)
/*  f0a42c4:	3c014040 */ 	lui	$at,0x4040
/*  f0a42c8:	44814000 */ 	mtc1	$at,$f8
/*  f0a42cc:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0a42d0:	8fae0034 */ 	lw	$t6,0x34($sp)
/*  f0a42d4:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f0a42d8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0a42dc:	000ec980 */ 	sll	$t9,$t6,0x6
/*  f0a42e0:	01b92821 */ 	addu	$a1,$t5,$t9
/*  f0a42e4:	afa50020 */ 	sw	$a1,0x20($sp)
/*  f0a42e8:	0c00577c */ 	jal	func00015df0
/*  f0a42ec:	46005300 */ 	add.s	$f12,$f10,$f0
/*  f0a42f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a42f4:	44818000 */ 	mtc1	$at,$f16
/*  f0a42f8:	c612023c */ 	lwc1	$f18,0x23c($s0)
/*  f0a42fc:	3c014040 */ 	lui	$at,0x4040
/*  f0a4300:	44813000 */ 	mtc1	$at,$f6
/*  f0a4304:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f0a4308:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a430c:	44815000 */ 	mtc1	$at,$f10
/*  f0a4310:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f0a4314:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0a4318:	0c005793 */ 	jal	func00015e4c
/*  f0a431c:	460a4300 */ 	add.s	$f12,$f8,$f10
.L0f0a4320:
/*  f0a4320:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0a4324:
/*  f0a4324:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a4328:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0a432c:	03e00008 */ 	jr	$ra
/*  f0a4330:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a4334
/*  f0a4334:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0a4338:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0a433c:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0a4340:	808e0004 */ 	lb	$t6,0x4($a0)
/*  f0a4344:	00808025 */ 	or	$s0,$a0,$zero
/*  f0a4348:	51c0001f */ 	beqzl	$t6,.L0f0a43c8
/*  f0a434c:	c600023c */ 	lwc1	$f0,0x23c($s0)
/*  f0a4350:	908f0003 */ 	lbu	$t7,0x3($a0)
/*  f0a4354:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a4358:	55e1001b */ 	bnel	$t7,$at,.L0f0a43c8
/*  f0a435c:	c600023c */ 	lwc1	$f0,0x23c($s0)
/*  f0a4360:	8c98074c */ 	lw	$t8,0x74c($a0)
/*  f0a4364:	3c19800a */ 	lui	$t9,0x800a
/*  f0a4368:	57000013 */ 	bnezl	$t8,.L0f0a43b8
/*  f0a436c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a4370:	8f399ff4 */ 	lw	$t9,-0x600c($t9)
/*  f0a4374:	3c048009 */ 	lui	$a0,0x8009
/*  f0a4378:	24050065 */ 	addiu	$a1,$zero,0x65
/*  f0a437c:	1320000d */ 	beqz	$t9,.L0f0a43b4
/*  f0a4380:	2606074c */ 	addiu	$a2,$s0,0x74c
/*  f0a4384:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a4388:	44812000 */ 	mtc1	$at,$f4
/*  f0a438c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0a4390:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0a4394:	240affff */ 	addiu	$t2,$zero,-1
/*  f0a4398:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0a439c:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0a43a0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0a43a4:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0a43a8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a43ac:	0c004241 */ 	jal	func00010904
/*  f0a43b0:	e7a40014 */ 	swc1	$f4,0x14($sp)
.L0f0a43b4:
/*  f0a43b4:	3c013f80 */ 	lui	$at,0x3f80
.L0f0a43b8:
/*  f0a43b8:	44813000 */ 	mtc1	$at,$f6
/*  f0a43bc:	10000019 */ 	beqz	$zero,.L0f0a4424
/*  f0a43c0:	e606023c */ 	swc1	$f6,0x23c($s0)
/*  f0a43c4:	c600023c */ 	lwc1	$f0,0x23c($s0)
.L0f0a43c8:
/*  f0a43c8:	44804000 */ 	mtc1	$zero,$f8
/*  f0a43cc:	3c01800a */ 	lui	$at,0x800a
/*  f0a43d0:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0a43d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a43d8:	4502000a */ 	bc1fl	.L0f0a4404
/*  f0a43dc:	8e04074c */ 	lw	$a0,0x74c($s0)
/*  f0a43e0:	c42aa004 */ 	lwc1	$f10,-0x5ffc($at)
/*  f0a43e4:	3c014120 */ 	lui	$at,0x4120
/*  f0a43e8:	44818000 */ 	mtc1	$at,$f16
/*  f0a43ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a43f0:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f0a43f4:	46120101 */ 	sub.s	$f4,$f0,$f18
/*  f0a43f8:	1000000a */ 	beqz	$zero,.L0f0a4424
/*  f0a43fc:	e604023c */ 	swc1	$f4,0x23c($s0)
/*  f0a4400:	8e04074c */ 	lw	$a0,0x74c($s0)
.L0f0a4404:
/*  f0a4404:	50800008 */ 	beqzl	$a0,.L0f0a4428
/*  f0a4408:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0a440c:	0c00cdfc */ 	jal	func000337f0
/*  f0a4410:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4414:	50400004 */ 	beqzl	$v0,.L0f0a4428
/*  f0a4418:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0a441c:	0c00cec9 */ 	jal	func00033b24
/*  f0a4420:	8e04074c */ 	lw	$a0,0x74c($s0)
.L0f0a4424:
/*  f0a4424:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0a4428:
/*  f0a4428:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0a442c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0a4430:	03e00008 */ 	jr	$ra
/*  f0a4434:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a4438
/*  f0a4438:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f0a443c:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a4440:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a4444:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0a4448:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f0a444c:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f0a4450:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0a4454:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f0a4458:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0a445c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0a4460:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0a4464:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f0a4468:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0a446c:	00c09825 */ 	or	$s3,$a2,$zero
/*  f0a4470:	0080a025 */ 	or	$s4,$a0,$zero
/*  f0a4474:	00e0a825 */ 	or	$s5,$a3,$zero
/*  f0a4478:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f0a447c:	10c00030 */ 	beqz	$a2,.L0f0a4540
/*  f0a4480:	c5d60078 */ 	lwc1	$f22,0x78($t6)
/*  f0a4484:	8c8f0690 */ 	lw	$t7,0x690($a0)
/*  f0a4488:	00008825 */ 	or	$s1,$zero,$zero
/*  f0a448c:	3c017f1b */ 	lui	$at,%hi(var7f1ac8c8)
/*  f0a4490:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0a4494:	0018cf42 */ 	srl	$t9,$t8,0x1d
/*  f0a4498:	1b200029 */ 	blez	$t9,.L0f0a4540
/*  f0a449c:	24120006 */ 	addiu	$s2,$zero,0x6
/*  f0a44a0:	c434c8c8 */ 	lwc1	$f20,%lo(var7f1ac8c8)($at)
/*  f0a44a4:	27b0004c */ 	addiu	$s0,$sp,0x4c
.L0f0a44a8:
/*  f0a44a8:	0c004b70 */ 	jal	random
/*  f0a44ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a44b0:	0052001b */ 	divu	$zero,$v0,$s2
/*  f0a44b4:	00002810 */ 	mfhi	$a1
/*  f0a44b8:	24a5000a */ 	addiu	$a1,$a1,0xa
/*  f0a44bc:	02602025 */ 	or	$a0,$s3,$zero
/*  f0a44c0:	16400002 */ 	bnez	$s2,.L0f0a44cc
/*  f0a44c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a44c8:	0007000d */ 	break	0x7
.L0f0a44cc:
/*  f0a44cc:	0c006a47 */ 	jal	func0001a91c
/*  f0a44d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a44d4:	10400013 */ 	beqz	$v0,.L0f0a4524
/*  f0a44d8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a44dc:	0c006949 */ 	jal	func0001a524
/*  f0a44e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a44e4:	00024180 */ 	sll	$t0,$v0,0x6
/*  f0a44e8:	02a82021 */ 	addu	$a0,$s5,$t0
/*  f0a44ec:	0c005746 */ 	jal	func00015d18
/*  f0a44f0:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a44f4:	4600a306 */ 	mov.s	$f12,$f20
/*  f0a44f8:	0c0057c1 */ 	jal	func00015f04
/*  f0a44fc:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a4500:	0fc2d5de */ 	jal	func0f0b5778
/*  f0a4504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4508:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a450c:	0c00567f */ 	jal	func000159fc
/*  f0a4510:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a4514:	4405b000 */ 	mfc1	$a1,$f22
/*  f0a4518:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0a451c:	0fc2b780 */ 	jal	func0f0ade00
/*  f0a4520:	02003025 */ 	or	$a2,$s0,$zero
.L0f0a4524:
/*  f0a4524:	8e890690 */ 	lw	$t1,0x690($s4)
/*  f0a4528:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0a452c:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0a4530:	000a5f42 */ 	srl	$t3,$t2,0x1d
/*  f0a4534:	022b082a */ 	slt	$at,$s1,$t3
/*  f0a4538:	1420ffdb */ 	bnez	$at,.L0f0a44a8
/*  f0a453c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a4540:
/*  f0a4540:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0a4544:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0a4548:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f0a454c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0a4550:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0a4554:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0a4558:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0a455c:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0a4560:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0a4564:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0a4568:	03e00008 */ 	jr	$ra
/*  f0a456c:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

GLOBAL_ASM(
glabel func0f0a4570
/*  f0a4570:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a4574:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a4578:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0a457c:	8c820218 */ 	lw	$v0,0x218($a0)
/*  f0a4580:	00803825 */ 	or	$a3,$a0,$zero
/*  f0a4584:	1440000a */ 	bnez	$v0,.L0f0a45b0
/*  f0a4588:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a458c:	8c8e0220 */ 	lw	$t6,0x220($a0)
/*  f0a4590:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0a4594:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0a4598:	19c00005 */ 	blez	$t6,.L0f0a45b0
/*  f0a459c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a45a0:	0fc27e5d */ 	jal	func0f09f974
/*  f0a45a4:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f0a45a8:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f0a45ac:	8ce20218 */ 	lw	$v0,0x218($a3)
.L0f0a45b0:
/*  f0a45b0:	50400004 */ 	beqzl	$v0,.L0f0a45c4
/*  f0a45b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a45b8:	0fc27e12 */ 	jal	func0f09f848
/*  f0a45bc:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0a45c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0a45c4:
/*  f0a45c4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a45c8:	03e00008 */ 	jr	$ra
/*  f0a45cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a45d0
/*  f0a45d0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a45d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a45d8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0a45dc:	8c8206d4 */ 	lw	$v0,0x6d4($a0)
/*  f0a45e0:	00003825 */ 	or	$a3,$zero,$zero
/*  f0a45e4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a45e8:	00027500 */ 	sll	$t6,$v0,0x14
/*  f0a45ec:	000e7f42 */ 	srl	$t7,$t6,0x1d
/*  f0a45f0:	11e00008 */ 	beqz	$t7,.L0f0a4614
/*  f0a45f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a45f8:	11e10011 */ 	beq	$t7,$at,.L0f0a4640
/*  f0a45fc:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0a4600:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a4604:	11e10012 */ 	beq	$t7,$at,.L0f0a4650
/*  f0a4608:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0a460c:	10000013 */ 	beqz	$zero,.L0f0a465c
/*  f0a4610:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a4614:
/*  f0a4614:	10c00006 */ 	beqz	$a2,.L0f0a4630
/*  f0a4618:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0a461c:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0a4620:	0c006a47 */ 	jal	func0001a91c
/*  f0a4624:	2405002a */ 	addiu	$a1,$zero,0x2a
/*  f0a4628:	1000000c */ 	beqz	$zero,.L0f0a465c
/*  f0a462c:	00403825 */ 	or	$a3,$v0,$zero
.L0f0a4630:
/*  f0a4630:	0c006a47 */ 	jal	func0001a91c
/*  f0a4634:	24050037 */ 	addiu	$a1,$zero,0x37
/*  f0a4638:	10000008 */ 	beqz	$zero,.L0f0a465c
/*  f0a463c:	00403825 */ 	or	$a3,$v0,$zero
.L0f0a4640:
/*  f0a4640:	0c006a47 */ 	jal	func0001a91c
/*  f0a4644:	2405002b */ 	addiu	$a1,$zero,0x2b
/*  f0a4648:	10000004 */ 	beqz	$zero,.L0f0a465c
/*  f0a464c:	00403825 */ 	or	$a3,$v0,$zero
.L0f0a4650:
/*  f0a4650:	0c006a47 */ 	jal	func0001a91c
/*  f0a4654:	2405002b */ 	addiu	$a1,$zero,0x2b
/*  f0a4658:	00403825 */ 	or	$a3,$v0,$zero
.L0f0a465c:
/*  f0a465c:	10e0000b */ 	beqz	$a3,.L0f0a468c
/*  f0a4660:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0a4664:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0a4668:	0c006949 */ 	jal	func0001a524
/*  f0a466c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a4670:	3c01800a */ 	lui	$at,0x800a
/*  f0a4674:	ac22d148 */ 	sw	$v0,-0x2eb8($at)
/*  f0a4678:	3c187f0a */ 	lui	$t8,0x7f0a
/*  f0a467c:	2718256c */ 	addiu	$t8,$t8,0x256c
/*  f0a4680:	3c018006 */ 	lui	$at,0x8006
/*  f0a4684:	10000003 */ 	beqz	$zero,.L0f0a4694
/*  f0a4688:	ac38efcc */ 	sw	$t8,-0x1034($at)
.L0f0a468c:
/*  f0a468c:	3c01800a */ 	lui	$at,0x800a
/*  f0a4690:	ac39d148 */ 	sw	$t9,-0x2eb8($at)
.L0f0a4694:
/*  f0a4694:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a4698:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a469c:	03e00008 */ 	jr	$ra
/*  f0a46a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a46a4
/*  f0a46a4:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f0a46a8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0a46ac:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0a46b0:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0a46b4:	afa500e4 */ 	sw	$a1,0xe4($sp)
/*  f0a46b8:	afa600e8 */ 	sw	$a2,0xe8($sp)
/*  f0a46bc:	948206d6 */ 	lhu	$v0,0x6d6($a0)
/*  f0a46c0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a46c4:	00808025 */ 	or	$s0,$a0,$zero
/*  f0a46c8:	00027302 */ 	srl	$t6,$v0,0xc
/*  f0a46cc:	11c30005 */ 	beq	$t6,$v1,.L0f0a46e4
/*  f0a46d0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a46d4:	11c10194 */ 	beq	$t6,$at,.L0f0a4d28
/*  f0a46d8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a46dc:	100001d5 */ 	beqz	$zero,.L0f0a4e34
/*  f0a46e0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0a46e4:
/*  f0a46e4:	8e0206d4 */ 	lw	$v0,0x6d4($s0)
/*  f0a46e8:	00027d00 */ 	sll	$t7,$v0,0x14
/*  f0a46ec:	000fc742 */ 	srl	$t8,$t7,0x1d
/*  f0a46f0:	13000007 */ 	beqz	$t8,.L0f0a4710
/*  f0a46f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a46f8:	1303006f */ 	beq	$t8,$v1,.L0f0a48b8
/*  f0a46fc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a4700:	530100e8 */ 	beql	$t8,$at,.L0f0a4aa4
/*  f0a4704:	44802000 */ 	mtc1	$zero,$f4
/*  f0a4708:	10000147 */ 	beqz	$zero,.L0f0a4c28
/*  f0a470c:	3c014348 */ 	lui	$at,0x4348
.L0f0a4710:
/*  f0a4710:	0c004b70 */ 	jal	random
/*  f0a4714:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4718:	3c017f1b */ 	lui	$at,%hi(var7f1ac8cc)
/*  f0a471c:	c420c8cc */ 	lwc1	$f0,%lo(var7f1ac8cc)($at)
/*  f0a4720:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4724:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a4728:	4481a000 */ 	mtc1	$at,$f20
/*  f0a472c:	04410005 */ 	bgez	$v0,.L0f0a4744
/*  f0a4730:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a4734:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4738:	44814000 */ 	mtc1	$at,$f8
/*  f0a473c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4740:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0a4744:
/*  f0a4744:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f0a4748:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a474c:	44818000 */ 	mtc1	$at,$f16
/*  f0a4750:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a4754:	44814000 */ 	mtc1	$at,$f8
/*  f0a4758:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0a475c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0a4760:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4764:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0a4768:	46003280 */ 	add.s	$f10,$f6,$f0
/*  f0a476c:	0c004b70 */ 	jal	random
/*  f0a4770:	e60a06e8 */ 	swc1	$f10,0x6e8($s0)
/*  f0a4774:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4778:	3c014020 */ 	lui	$at,0x4020
/*  f0a477c:	44810000 */ 	mtc1	$at,$f0
/*  f0a4780:	04410005 */ 	bgez	$v0,.L0f0a4798
/*  f0a4784:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a4788:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a478c:	44812000 */ 	mtc1	$at,$f4
/*  f0a4790:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4794:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f0a4798:
/*  f0a4798:	46149202 */ 	mul.s	$f8,$f18,$f20
/*  f0a479c:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a47a0:	44815000 */ 	mtc1	$at,$f10
/*  f0a47a4:	44809000 */ 	mtc1	$zero,$f18
/*  f0a47a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a47ac:	e61206f0 */ 	swc1	$f18,0x6f0($s0)
/*  f0a47b0:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0a47b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a47b8:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0a47bc:	46008100 */ 	add.s	$f4,$f16,$f0
/*  f0a47c0:	0c004b70 */ 	jal	random
/*  f0a47c4:	e60406ec */ 	swc1	$f4,0x6ec($s0)
/*  f0a47c8:	44824000 */ 	mtc1	$v0,$f8
/*  f0a47cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a47d0:	04410004 */ 	bgez	$v0,.L0f0a47e4
/*  f0a47d4:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0a47d8:	44815000 */ 	mtc1	$at,$f10
/*  f0a47dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a47e0:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f0a47e4:
/*  f0a47e4:	46143002 */ 	mul.s	$f0,$f6,$f20
/*  f0a47e8:	3c017f1b */ 	lui	$at,%hi(var7f1ac8d0)
/*  f0a47ec:	c424c8d0 */ 	lwc1	$f4,%lo(var7f1ac8d0)($at)
/*  f0a47f0:	3c014338 */ 	lui	$at,0x4338
/*  f0a47f4:	44814000 */ 	mtc1	$at,$f8
/*  f0a47f8:	3c017f1b */ 	lui	$at,%hi(var7f1ac8d4)
/*  f0a47fc:	c426c8d4 */ 	lwc1	$f6,%lo(var7f1ac8d4)($at)
/*  f0a4800:	46000400 */ 	add.s	$f16,$f0,$f0
/*  f0a4804:	46048482 */ 	mul.s	$f18,$f16,$f4
/*  f0a4808:	46089283 */ 	div.s	$f10,$f18,$f8
/*  f0a480c:	46065401 */ 	sub.s	$f16,$f10,$f6
/*  f0a4810:	0c004b70 */ 	jal	random
/*  f0a4814:	e7b000d0 */ 	swc1	$f16,0xd0($sp)
/*  f0a4818:	44822000 */ 	mtc1	$v0,$f4
/*  f0a481c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4820:	04410004 */ 	bgez	$v0,.L0f0a4834
/*  f0a4824:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f0a4828:	44814000 */ 	mtc1	$at,$f8
/*  f0a482c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4830:	46089480 */ 	add.s	$f18,$f18,$f8
.L0f0a4834:
/*  f0a4834:	46149002 */ 	mul.s	$f0,$f18,$f20
/*  f0a4838:	3c017f1b */ 	lui	$at,%hi(var7f1ac8d8)
/*  f0a483c:	c426c8d8 */ 	lwc1	$f6,%lo(var7f1ac8d8)($at)
/*  f0a4840:	3c014338 */ 	lui	$at,0x4338
/*  f0a4844:	44812000 */ 	mtc1	$at,$f4
/*  f0a4848:	3c017f1b */ 	lui	$at,%hi(var7f1ac8dc)
/*  f0a484c:	c432c8dc */ 	lwc1	$f18,%lo(var7f1ac8dc)($at)
/*  f0a4850:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f0a4854:	46065402 */ 	mul.s	$f16,$f10,$f6
/*  f0a4858:	46048203 */ 	div.s	$f8,$f16,$f4
/*  f0a485c:	46124281 */ 	sub.s	$f10,$f8,$f18
/*  f0a4860:	0c004b70 */ 	jal	random
/*  f0a4864:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0a4868:	44823000 */ 	mtc1	$v0,$f6
/*  f0a486c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4870:	04410004 */ 	bgez	$v0,.L0f0a4884
/*  f0a4874:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0a4878:	44812000 */ 	mtc1	$at,$f4
/*  f0a487c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4880:	46048400 */ 	add.s	$f16,$f16,$f4
.L0f0a4884:
/*  f0a4884:	46148002 */ 	mul.s	$f0,$f16,$f20
/*  f0a4888:	3c017f1b */ 	lui	$at,%hi(var7f1ac8e0)
/*  f0a488c:	c432c8e0 */ 	lwc1	$f18,%lo(var7f1ac8e0)($at)
/*  f0a4890:	3c014338 */ 	lui	$at,0x4338
/*  f0a4894:	44813000 */ 	mtc1	$at,$f6
/*  f0a4898:	3c017f1b */ 	lui	$at,%hi(var7f1ac8e4)
/*  f0a489c:	c430c8e4 */ 	lwc1	$f16,%lo(var7f1ac8e4)($at)
/*  f0a48a0:	46000200 */ 	add.s	$f8,$f0,$f0
/*  f0a48a4:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f0a48a8:	46065103 */ 	div.s	$f4,$f10,$f6
/*  f0a48ac:	46102201 */ 	sub.s	$f8,$f4,$f16
/*  f0a48b0:	100000dc */ 	beqz	$zero,.L0f0a4c24
/*  f0a48b4:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
.L0f0a48b8:
/*  f0a48b8:	0c004b70 */ 	jal	random
/*  f0a48bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a48c0:	3c017f1b */ 	lui	$at,%hi(var7f1ac8e8)
/*  f0a48c4:	c420c8e8 */ 	lwc1	$f0,%lo(var7f1ac8e8)($at)
/*  f0a48c8:	44829000 */ 	mtc1	$v0,$f18
/*  f0a48cc:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a48d0:	4481a000 */ 	mtc1	$at,$f20
/*  f0a48d4:	04410005 */ 	bgez	$v0,.L0f0a48ec
/*  f0a48d8:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f0a48dc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a48e0:	44813000 */ 	mtc1	$at,$f6
/*  f0a48e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a48e8:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f0a48ec:
/*  f0a48ec:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0a48f0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a48f4:	44818000 */ 	mtc1	$at,$f16
/*  f0a48f8:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a48fc:	44813000 */ 	mtc1	$at,$f6
/*  f0a4900:	3c014040 */ 	lui	$at,0x4040
/*  f0a4904:	46102201 */ 	sub.s	$f8,$f4,$f16
/*  f0a4908:	44812000 */ 	mtc1	$at,$f4
/*  f0a490c:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f0a4910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4914:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f0a4918:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a491c:	46002402 */ 	mul.s	$f16,$f4,$f0
/*  f0a4920:	46105200 */ 	add.s	$f8,$f10,$f16
/*  f0a4924:	46004487 */ 	neg.s	$f18,$f8
/*  f0a4928:	0c004b70 */ 	jal	random
/*  f0a492c:	e61206e8 */ 	swc1	$f18,0x6e8($s0)
/*  f0a4930:	44823000 */ 	mtc1	$v0,$f6
/*  f0a4934:	3c014020 */ 	lui	$at,0x4020
/*  f0a4938:	44810000 */ 	mtc1	$at,$f0
/*  f0a493c:	04410005 */ 	bgez	$v0,.L0f0a4954
/*  f0a4940:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0a4944:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4948:	44815000 */ 	mtc1	$at,$f10
/*  f0a494c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4950:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f0a4954:
/*  f0a4954:	46142402 */ 	mul.s	$f16,$f4,$f20
/*  f0a4958:	3c013e00 */ 	lui	$at,0x3e00
/*  f0a495c:	44819000 */ 	mtc1	$at,$f18
/*  f0a4960:	46008202 */ 	mul.s	$f8,$f16,$f0
/*  f0a4964:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4968:	46124182 */ 	mul.s	$f6,$f8,$f18
/*  f0a496c:	46003280 */ 	add.s	$f10,$f6,$f0
/*  f0a4970:	0c004b70 */ 	jal	random
/*  f0a4974:	e60a06ec */ 	swc1	$f10,0x6ec($s0)
/*  f0a4978:	44822000 */ 	mtc1	$v0,$f4
/*  f0a497c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4980:	04410004 */ 	bgez	$v0,.L0f0a4994
/*  f0a4984:	46802420 */ 	cvt.s.w	$f16,$f4
/*  f0a4988:	44814000 */ 	mtc1	$at,$f8
/*  f0a498c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4990:	46088400 */ 	add.s	$f16,$f16,$f8
.L0f0a4994:
/*  f0a4994:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f0a4998:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a499c:	44813000 */ 	mtc1	$at,$f6
/*  f0a49a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a49a4:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f0a49a8:	46005107 */ 	neg.s	$f4,$f10
/*  f0a49ac:	0c004b70 */ 	jal	random
/*  f0a49b0:	e60406f0 */ 	swc1	$f4,0x6f0($s0)
/*  f0a49b4:	44824000 */ 	mtc1	$v0,$f8
/*  f0a49b8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a49bc:	04410004 */ 	bgez	$v0,.L0f0a49d0
/*  f0a49c0:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f0a49c4:	44819000 */ 	mtc1	$at,$f18
/*  f0a49c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a49cc:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f0a49d0:
/*  f0a49d0:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f0a49d4:	3c014040 */ 	lui	$at,0x4040
/*  f0a49d8:	44815000 */ 	mtc1	$at,$f10
/*  f0a49dc:	3c017f1b */ 	lui	$at,%hi(var7f1ac8ec)
/*  f0a49e0:	c428c8ec */ 	lwc1	$f8,%lo(var7f1ac8ec)($at)
/*  f0a49e4:	3c014350 */ 	lui	$at,0x4350
/*  f0a49e8:	44818000 */ 	mtc1	$at,$f16
/*  f0a49ec:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f0a49f0:	46082482 */ 	mul.s	$f18,$f4,$f8
/*  f0a49f4:	46109183 */ 	div.s	$f6,$f18,$f16
/*  f0a49f8:	0c004b70 */ 	jal	random
/*  f0a49fc:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*  f0a4a00:	44825000 */ 	mtc1	$v0,$f10
/*  f0a4a04:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4a08:	04410004 */ 	bgez	$v0,.L0f0a4a1c
/*  f0a4a0c:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0a4a10:	44814000 */ 	mtc1	$at,$f8
/*  f0a4a14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4a18:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f0a4a1c:
/*  f0a4a1c:	46142002 */ 	mul.s	$f0,$f4,$f20
/*  f0a4a20:	3c017f1b */ 	lui	$at,%hi(var7f1ac8f0)
/*  f0a4a24:	c430c8f0 */ 	lwc1	$f16,%lo(var7f1ac8f0)($at)
/*  f0a4a28:	3c014408 */ 	lui	$at,0x4408
/*  f0a4a2c:	44815000 */ 	mtc1	$at,$f10
/*  f0a4a30:	3c017f1b */ 	lui	$at,%hi(var7f1ac8f4)
/*  f0a4a34:	c424c8f4 */ 	lwc1	$f4,%lo(var7f1ac8f4)($at)
/*  f0a4a38:	46000480 */ 	add.s	$f18,$f0,$f0
/*  f0a4a3c:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f0a4a40:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f0a4a44:	46044481 */ 	sub.s	$f18,$f8,$f4
/*  f0a4a48:	0c004b70 */ 	jal	random
/*  f0a4a4c:	e7b200d4 */ 	swc1	$f18,0xd4($sp)
/*  f0a4a50:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4a54:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4a58:	04410004 */ 	bgez	$v0,.L0f0a4a6c
/*  f0a4a5c:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0a4a60:	44815000 */ 	mtc1	$at,$f10
/*  f0a4a64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4a68:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f0a4a6c:
/*  f0a4a6c:	46143002 */ 	mul.s	$f0,$f6,$f20
/*  f0a4a70:	3c017f1b */ 	lui	$at,%hi(var7f1ac8f8)
/*  f0a4a74:	c424c8f8 */ 	lwc1	$f4,%lo(var7f1ac8f8)($at)
/*  f0a4a78:	3c014408 */ 	lui	$at,0x4408
/*  f0a4a7c:	44818000 */ 	mtc1	$at,$f16
/*  f0a4a80:	3c017f1b */ 	lui	$at,%hi(var7f1ac8fc)
/*  f0a4a84:	c426c8fc */ 	lwc1	$f6,%lo(var7f1ac8fc)($at)
/*  f0a4a88:	46000200 */ 	add.s	$f8,$f0,$f0
/*  f0a4a8c:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f0a4a90:	46109283 */ 	div.s	$f10,$f18,$f16
/*  f0a4a94:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0a4a98:	10000062 */ 	beqz	$zero,.L0f0a4c24
/*  f0a4a9c:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
/*  f0a4aa0:	44802000 */ 	mtc1	$zero,$f4
.L0f0a4aa4:
/*  f0a4aa4:	0c004b70 */ 	jal	random
/*  f0a4aa8:	e60406e8 */ 	swc1	$f4,0x6e8($s0)
/*  f0a4aac:	3c014020 */ 	lui	$at,0x4020
/*  f0a4ab0:	44810000 */ 	mtc1	$at,$f0
/*  f0a4ab4:	44829000 */ 	mtc1	$v0,$f18
/*  f0a4ab8:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a4abc:	4481a000 */ 	mtc1	$at,$f20
/*  f0a4ac0:	04410005 */ 	bgez	$v0,.L0f0a4ad8
/*  f0a4ac4:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f0a4ac8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4acc:	44815000 */ 	mtc1	$at,$f10
/*  f0a4ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4ad4:	460a8400 */ 	add.s	$f16,$f16,$f10
.L0f0a4ad8:
/*  f0a4ad8:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f0a4adc:	3c013e00 */ 	lui	$at,0x3e00
/*  f0a4ae0:	44812000 */ 	mtc1	$at,$f4
/*  f0a4ae4:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a4ae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4aec:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f0a4af0:	46009280 */ 	add.s	$f10,$f18,$f0
/*  f0a4af4:	0c004b70 */ 	jal	random
/*  f0a4af8:	e60a06ec */ 	swc1	$f10,0x6ec($s0)
/*  f0a4afc:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4b00:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4b04:	04410004 */ 	bgez	$v0,.L0f0a4b18
/*  f0a4b08:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0a4b0c:	44814000 */ 	mtc1	$at,$f8
/*  f0a4b10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4b14:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0a4b18:
/*  f0a4b18:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0a4b1c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a4b20:	44819000 */ 	mtc1	$at,$f18
/*  f0a4b24:	3c013e80 */ 	lui	$at,0x3e80
/*  f0a4b28:	44818000 */ 	mtc1	$at,$f16
/*  f0a4b2c:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f0a4b30:	46105202 */ 	mul.s	$f8,$f10,$f16
/*  f0a4b34:	0c004b70 */ 	jal	random
/*  f0a4b38:	e60806f0 */ 	swc1	$f8,0x6f0($s0)
/*  f0a4b3c:	44823000 */ 	mtc1	$v0,$f6
/*  f0a4b40:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4b44:	04410004 */ 	bgez	$v0,.L0f0a4b58
/*  f0a4b48:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0a4b4c:	44819000 */ 	mtc1	$at,$f18
/*  f0a4b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4b54:	46122100 */ 	add.s	$f4,$f4,$f18
.L0f0a4b58:
/*  f0a4b58:	46142282 */ 	mul.s	$f10,$f4,$f20
/*  f0a4b5c:	3c014040 */ 	lui	$at,0x4040
/*  f0a4b60:	44818000 */ 	mtc1	$at,$f16
/*  f0a4b64:	3c017f1b */ 	lui	$at,%hi(var7f1ac900)
/*  f0a4b68:	c426c900 */ 	lwc1	$f6,%lo(var7f1ac900)($at)
/*  f0a4b6c:	3c0143b8 */ 	lui	$at,0x43b8
/*  f0a4b70:	44812000 */ 	mtc1	$at,$f4
/*  f0a4b74:	46105200 */ 	add.s	$f8,$f10,$f16
/*  f0a4b78:	46064482 */ 	mul.s	$f18,$f8,$f6
/*  f0a4b7c:	46049283 */ 	div.s	$f10,$f18,$f4
/*  f0a4b80:	0c004b70 */ 	jal	random
/*  f0a4b84:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
/*  f0a4b88:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4b8c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4b90:	04410004 */ 	bgez	$v0,.L0f0a4ba4
/*  f0a4b94:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f0a4b98:	44813000 */ 	mtc1	$at,$f6
/*  f0a4b9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4ba0:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f0a4ba4:
/*  f0a4ba4:	46144002 */ 	mul.s	$f0,$f8,$f20
/*  f0a4ba8:	3c017f1b */ 	lui	$at,%hi(var7f1ac904)
/*  f0a4bac:	c424c904 */ 	lwc1	$f4,%lo(var7f1ac904)($at)
/*  f0a4bb0:	3c01446c */ 	lui	$at,0x446c
/*  f0a4bb4:	44818000 */ 	mtc1	$at,$f16
/*  f0a4bb8:	3c017f1b */ 	lui	$at,%hi(var7f1ac908)
/*  f0a4bbc:	c428c908 */ 	lwc1	$f8,%lo(var7f1ac908)($at)
/*  f0a4bc0:	46000480 */ 	add.s	$f18,$f0,$f0
/*  f0a4bc4:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0a4bc8:	46105183 */ 	div.s	$f6,$f10,$f16
/*  f0a4bcc:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0a4bd0:	0c004b70 */ 	jal	random
/*  f0a4bd4:	e7b200d4 */ 	swc1	$f18,0xd4($sp)
/*  f0a4bd8:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4bdc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4be0:	04410004 */ 	bgez	$v0,.L0f0a4bf4
/*  f0a4be4:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0a4be8:	44818000 */ 	mtc1	$at,$f16
/*  f0a4bec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4bf0:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0a4bf4:
/*  f0a4bf4:	46145002 */ 	mul.s	$f0,$f10,$f20
/*  f0a4bf8:	3c017f1b */ 	lui	$at,%hi(var7f1ac90c)
/*  f0a4bfc:	c428c90c */ 	lwc1	$f8,%lo(var7f1ac90c)($at)
/*  f0a4c00:	3c01446c */ 	lui	$at,0x446c
/*  f0a4c04:	44812000 */ 	mtc1	$at,$f4
/*  f0a4c08:	3c017f1b */ 	lui	$at,%hi(var7f1ac910)
/*  f0a4c0c:	c42ac910 */ 	lwc1	$f10,%lo(var7f1ac910)($at)
/*  f0a4c10:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f0a4c14:	46083482 */ 	mul.s	$f18,$f6,$f8
/*  f0a4c18:	46049403 */ 	div.s	$f16,$f18,$f4
/*  f0a4c1c:	460a8181 */ 	sub.s	$f6,$f16,$f10
/*  f0a4c20:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
.L0f0a4c24:
/*  f0a4c24:	3c014348 */ 	lui	$at,0x4348
.L0f0a4c28:
/*  f0a4c28:	44819000 */ 	mtc1	$at,$f18
/*  f0a4c2c:	c60806dc */ 	lwc1	$f8,0x6dc($s0)
/*  f0a4c30:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0a4c34:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0a4c38:	46124101 */ 	sub.s	$f4,$f8,$f18
/*  f0a4c3c:	0c005923 */ 	jal	func0001648c
/*  f0a4c40:	e60406d8 */ 	swc1	$f4,0x6d8($s0)
/*  f0a4c44:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0a4c48:	0c005768 */ 	jal	func00015da0
/*  f0a4c4c:	26050718 */ 	addiu	$a1,$s0,0x718
/*  f0a4c50:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a4c54:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a4c58:	8c790034 */ 	lw	$t9,0x34($v1)
/*  f0a4c5c:	5b20002e */ 	blezl	$t9,.L0f0a4d18
/*  f0a4c60:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
/*  f0a4c64:	8e0806d4 */ 	lw	$t0,0x6d4($s0)
/*  f0a4c68:	00084d00 */ 	sll	$t1,$t0,0x14
/*  f0a4c6c:	00095742 */ 	srl	$t2,$t1,0x1d
/*  f0a4c70:	51400029 */ 	beqzl	$t2,.L0f0a4d18
/*  f0a4c74:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
/*  f0a4c78:	c6100324 */ 	lwc1	$f16,0x324($s0)
/*  f0a4c7c:	c60a0364 */ 	lwc1	$f10,0x364($s0)
/*  f0a4c80:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0a4c84:	260402f4 */ 	addiu	$a0,$s0,0x2f4
/*  f0a4c88:	460a8181 */ 	sub.s	$f6,$f16,$f10
/*  f0a4c8c:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0a4c90:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0a4c94:	e7a80084 */ 	swc1	$f8,0x84($sp)
/*  f0a4c98:	c6040368 */ 	lwc1	$f4,0x368($s0)
/*  f0a4c9c:	c6120328 */ 	lwc1	$f18,0x328($s0)
/*  f0a4ca0:	46049401 */ 	sub.s	$f16,$f18,$f4
/*  f0a4ca4:	46008283 */ 	div.s	$f10,$f16,$f0
/*  f0a4ca8:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f0a4cac:	c608036c */ 	lwc1	$f8,0x36c($s0)
/*  f0a4cb0:	c606032c */ 	lwc1	$f6,0x32c($s0)
/*  f0a4cb4:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0a4cb8:	46009103 */ 	div.s	$f4,$f18,$f0
/*  f0a4cbc:	0c005d62 */ 	jal	func00017588
/*  f0a4cc0:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f0a4cc4:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f0a4cc8:	0c0056c4 */ 	jal	func00015b10
/*  f0a4ccc:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f0a4cd0:	3c017f1b */ 	lui	$at,%hi(var7f1ac914)
/*  f0a4cd4:	c420c914 */ 	lwc1	$f0,%lo(var7f1ac914)($at)
/*  f0a4cd8:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*  f0a4cdc:	c61006e8 */ 	lwc1	$f16,0x6e8($s0)
/*  f0a4ce0:	c61206ec */ 	lwc1	$f18,0x6ec($s0)
/*  f0a4ce4:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f0a4ce8:	46068200 */ 	add.s	$f8,$f16,$f6
/*  f0a4cec:	c60606f0 */ 	lwc1	$f6,0x6f0($s0)
/*  f0a4cf0:	e60806e8 */ 	swc1	$f8,0x6e8($s0)
/*  f0a4cf4:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f0a4cf8:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0a4cfc:	460a9400 */ 	add.s	$f16,$f18,$f10
/*  f0a4d00:	e61006ec */ 	swc1	$f16,0x6ec($s0)
/*  f0a4d04:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f0a4d08:	46004102 */ 	mul.s	$f4,$f8,$f0
/*  f0a4d0c:	46043480 */ 	add.s	$f18,$f6,$f4
/*  f0a4d10:	e61206f0 */ 	swc1	$f18,0x6f0($s0)
/*  f0a4d14:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
.L0f0a4d18:
/*  f0a4d18:	316cff0f */ 	andi	$t4,$t3,0xff0f
/*  f0a4d1c:	358d0020 */ 	ori	$t5,$t4,0x20
/*  f0a4d20:	10000043 */ 	beqz	$zero,.L0f0a4e30
/*  f0a4d24:	a20d06d6 */ 	sb	$t5,0x6d6($s0)
.L0f0a4d28:
/*  f0a4d28:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a4d2c:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f0a4d30:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0a4d34:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f0a4d38:	8dcf00d8 */ 	lw	$t7,0xd8($t6)
/*  f0a4d3c:	11e00008 */ 	beqz	$t7,.L0f0a4d60
/*  f0a4d40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4d44:	44811000 */ 	mtc1	$at,$f2
/*  f0a4d48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4d4c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a4d50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4d54:	45000002 */ 	bc1f	.L0f0a4d60
/*  f0a4d58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4d5c:	46001006 */ 	mov.s	$f0,$f2
.L0f0a4d60:
/*  f0a4d60:	3c017f1b */ 	lui	$at,%hi(var7f1ac918)
/*  f0a4d64:	c42ac918 */ 	lwc1	$f10,%lo(var7f1ac918)($at)
/*  f0a4d68:	c60e06e0 */ 	lwc1	$f14,0x6e0($s0)
/*  f0a4d6c:	c60806d8 */ 	lwc1	$f8,0x6d8($s0)
/*  f0a4d70:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f0a4d74:	c60206ec */ 	lwc1	$f2,0x6ec($s0)
/*  f0a4d78:	4608703c */ 	c.lt.s	$f14,$f8
/*  f0a4d7c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a4d80:	45000006 */ 	bc1f	.L0f0a4d9c
/*  f0a4d84:	46101301 */ 	sub.s	$f12,$f2,$f16
/*  f0a4d88:	921806d6 */ 	lbu	$t8,0x6d6($s0)
/*  f0a4d8c:	3319ff0f */ 	andi	$t9,$t8,0xff0f
/*  f0a4d90:	37280030 */ 	ori	$t0,$t9,0x30
/*  f0a4d94:	10000026 */ 	beqz	$zero,.L0f0a4e30
/*  f0a4d98:	a20806d6 */ 	sb	$t0,0x6d6($s0)
.L0f0a4d9c:
/*  f0a4d9c:	44813000 */ 	mtc1	$at,$f6
/*  f0a4da0:	460c1480 */ 	add.s	$f18,$f2,$f12
/*  f0a4da4:	c60806dc */ 	lwc1	$f8,0x6dc($s0)
/*  f0a4da8:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0a4dac:	c60606e8 */ 	lwc1	$f6,0x6e8($s0)
/*  f0a4db0:	e60c06ec */ 	swc1	$f12,0x6ec($s0)
/*  f0a4db4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a4db8:	26040718 */ 	addiu	$a0,$s0,0x718
/*  f0a4dbc:	260506f4 */ 	addiu	$a1,$s0,0x6f4
/*  f0a4dc0:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f0a4dc4:	460a7400 */ 	add.s	$f16,$f14,$f10
/*  f0a4dc8:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0a4dcc:	c60a06e4 */ 	lwc1	$f10,0x6e4($s0)
/*  f0a4dd0:	e61006e0 */ 	swc1	$f16,0x6e0($s0)
/*  f0a4dd4:	c61006f0 */ 	lwc1	$f16,0x6f0($s0)
/*  f0a4dd8:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f0a4ddc:	46044480 */ 	add.s	$f18,$f8,$f4
/*  f0a4de0:	e61206dc */ 	swc1	$f18,0x6dc($s0)
/*  f0a4de4:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0a4de8:	e60806e4 */ 	swc1	$f8,0x6e4($s0)
/*  f0a4dec:	8c690034 */ 	lw	$t1,0x34($v1)
/*  f0a4df0:	59200010 */ 	blezl	$t1,.L0f0a4e34
/*  f0a4df4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0a4df8:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0a4dfc:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f0a4e00:	8fa40030 */ 	lw	$a0,0x30($sp)
.L0f0a4e04:
/*  f0a4e04:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f0a4e08:	0c005844 */ 	jal	func00016110
/*  f0a4e0c:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0a4e10:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a4e14:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0a4e18:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a4e1c:	8c6a0034 */ 	lw	$t2,0x34($v1)
/*  f0a4e20:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0a4e24:	004a082a */ 	slt	$at,$v0,$t2
/*  f0a4e28:	5420fff6 */ 	bnezl	$at,.L0f0a4e04
/*  f0a4e2c:	8fa40030 */ 	lw	$a0,0x30($sp)
.L0f0a4e30:
/*  f0a4e30:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0a4e34:
/*  f0a4e34:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0a4e38:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0a4e3c:	03e00008 */ 	jr	$ra
/*  f0a4e40:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
);

GLOBAL_ASM(
glabel func0f0a4e44
/*  f0a4e44:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f0a4e48:	3c0e8007 */ 	lui	$t6,%hi(var80070238)
/*  f0a4e4c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0a4e50:	afb70040 */ 	sw	$s7,0x40($sp)
/*  f0a4e54:	afb6003c */ 	sw	$s6,0x3c($sp)
/*  f0a4e58:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f0a4e5c:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f0a4e60:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f0a4e64:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f0a4e68:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0a4e6c:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0a4e70:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0a4e74:	afa60120 */ 	sw	$a2,0x120($sp)
/*  f0a4e78:	25ce0238 */ 	addiu	$t6,$t6,%lo(var80070238)
/*  f0a4e7c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0a4e80:	8fb10128 */ 	lw	$s1,0x128($sp)
/*  f0a4e84:	27b300c4 */ 	addiu	$s3,$sp,0xc4
/*  f0a4e88:	ae610000 */ 	sw	$at,0x0($s3)
/*  f0a4e8c:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f0a4e90:	0080b025 */ 	or	$s6,$a0,$zero
/*  f0a4e94:	00e0a025 */ 	or	$s4,$a3,$zero
/*  f0a4e98:	ae790004 */ 	sw	$t9,0x4($s3)
/*  f0a4e9c:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0a4ea0:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f0a4ea4:	ae610008 */ 	sw	$at,0x8($s3)
/*  f0a4ea8:	8c880558 */ 	lw	$t0,0x558($a0)
/*  f0a4eac:	8ed205f8 */ 	lw	$s2,0x5f8($s6)
/*  f0a4eb0:	0111001a */ 	div	$zero,$t0,$s1
/*  f0a4eb4:	00008010 */ 	mfhi	$s0
/*  f0a4eb8:	16200002 */ 	bnez	$s1,.L0f0a4ec4
/*  f0a4ebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4ec0:	0007000d */ 	break	0x7
.L0f0a4ec4:
/*  f0a4ec4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0a4ec8:	16210004 */ 	bne	$s1,$at,.L0f0a4edc
/*  f0a4ecc:	3c018000 */ 	lui	$at,0x8000
/*  f0a4ed0:	15010002 */ 	bne	$t0,$at,.L0f0a4edc
/*  f0a4ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4ed8:	0006000d */ 	break	0x6
.L0f0a4edc:
/*  f0a4edc:	0c004b70 */ 	jal	random
/*  f0a4ee0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4ee4:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4ee8:	27b700d8 */ 	addiu	$s7,$sp,0xd8
/*  f0a4eec:	04410005 */ 	bgez	$v0,.L0f0a4f04
/*  f0a4ef0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a4ef4:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4ef8:	44814000 */ 	mtc1	$at,$f8
/*  f0a4efc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4f00:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0a4f04:
/*  f0a4f04:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a4f08:	44815000 */ 	mtc1	$at,$f10
/*  f0a4f0c:	3c013e80 */ 	lui	$at,0x3e80
/*  f0a4f10:	44819000 */ 	mtc1	$at,$f18
/*  f0a4f14:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0a4f18:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a4f1c:	44814000 */ 	mtc1	$at,$f8
/*  f0a4f20:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0a4f24:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0a4f28:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0a4f2c:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*  f0a4f30:	c6aa0028 */ 	lwc1	$f10,0x28($s5)
/*  f0a4f34:	0c00566c */ 	jal	func000159b0
/*  f0a4f38:	e7aa00b0 */ 	swc1	$f10,0xb0($sp)
/*  f0a4f3c:	12800017 */ 	beqz	$s4,.L0f0a4f9c
/*  f0a4f40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4f44:	8e890010 */ 	lw	$t1,0x10($s4)
/*  f0a4f48:	312a0001 */ 	andi	$t2,$t1,0x1
/*  f0a4f4c:	11400013 */ 	beqz	$t2,.L0f0a4f9c
/*  f0a4f50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4f54:	0c004b70 */ 	jal	random
/*  f0a4f58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4f5c:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4f60:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4f64:	04410004 */ 	bgez	$v0,.L0f0a4f78
/*  f0a4f68:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a4f6c:	44812000 */ 	mtc1	$at,$f4
/*  f0a4f70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4f74:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f0a4f78:
/*  f0a4f78:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a4f7c:	44814000 */ 	mtc1	$at,$f8
/*  f0a4f80:	3c017f1b */ 	lui	$at,%hi(var7f1ac91c)
/*  f0a4f84:	c42ac91c */ 	lwc1	$f10,%lo(var7f1ac91c)($at)
/*  f0a4f88:	46089182 */ 	mul.s	$f6,$f18,$f8
/*  f0a4f8c:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0a4f90:	460a3302 */ 	mul.s	$f12,$f6,$f10
/*  f0a4f94:	0c005900 */ 	jal	func00016400
/*  f0a4f98:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a4f9c:
/*  f0a4f9c:	0c004b70 */ 	jal	random
/*  f0a4fa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4fa4:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4fa8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4fac:	04410004 */ 	bgez	$v0,.L0f0a4fc0
/*  f0a4fb0:	46808120 */ 	cvt.s.w	$f4,$f16
/*  f0a4fb4:	44819000 */ 	mtc1	$at,$f18
/*  f0a4fb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4fbc:	46122100 */ 	add.s	$f4,$f4,$f18
.L0f0a4fc0:
/*  f0a4fc0:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a4fc4:	44814000 */ 	mtc1	$at,$f8
/*  f0a4fc8:	3c017f1b */ 	lui	$at,%hi(var7f1ac930)
/*  f0a4fcc:	d430c920 */ 	ldc1	$f16,-0x36e0($at)
/*  f0a4fd0:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0a4fd4:	3c017f1b */ 	lui	$at,%hi(var7f1ac934)
/*  f0a4fd8:	d424c928 */ 	ldc1	$f4,-0x36d8($at)
/*  f0a4fdc:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0a4fe0:	460032a1 */ 	cvt.d.s	$f10,$f6
/*  f0a4fe4:	46305482 */ 	mul.d	$f18,$f10,$f16
/*  f0a4fe8:	46249201 */ 	sub.d	$f8,$f18,$f4
/*  f0a4fec:	0c005900 */ 	jal	func00016400
/*  f0a4ff0:	46204320 */ 	cvt.s.d	$f12,$f8
/*  f0a4ff4:	8fab0138 */ 	lw	$t3,0x138($sp)
/*  f0a4ff8:	8fb5012c */ 	lw	$s5,0x12c($sp)
/*  f0a4ffc:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0a5000:	000b6180 */ 	sll	$t4,$t3,0x6
/*  f0a5004:	02aca021 */ 	addu	$s4,$s5,$t4
/*  f0a5008:	0c00567f */ 	jal	func000159fc
/*  f0a500c:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a5010:	c7ac00b4 */ 	lwc1	$f12,0xb4($sp)
/*  f0a5014:	0c0057c1 */ 	jal	func00015f04
/*  f0a5018:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0a501c:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0a5020:	0c0057aa */ 	jal	func00015ea8
/*  f0a5024:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0a5028:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0a502c:	0c005746 */ 	jal	func00015d18
/*  f0a5030:	02802825 */ 	or	$a1,$s4,$zero
/*  f0a5034:	16400006 */ 	bnez	$s2,.L0f0a5050
/*  f0a5038:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a503c:	8fb70130 */ 	lw	$s7,0x130($sp)
/*  f0a5040:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0a5044:	12e10002 */ 	beq	$s7,$at,.L0f0a5050
/*  f0a5048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a504c:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f0a5050:
/*  f0a5050:	1a40000d */ 	blez	$s2,.L0f0a5088
/*  f0a5054:	8fb70130 */ 	lw	$s7,0x130($sp)
/*  f0a5058:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0a505c:	00106880 */ 	sll	$t5,$s0,0x2
.L0f0a5060:
/*  f0a5060:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0a5064:	026dc021 */ 	addu	$t8,$s3,$t5
/*  f0a5068:	0211082a */ 	slt	$at,$s0,$s1
/*  f0a506c:	14200002 */ 	bnez	$at,.L0f0a5078
/*  f0a5070:	af070000 */ 	sw	$a3,0x0($t8)
/*  f0a5074:	00008025 */ 	or	$s0,$zero,$zero
.L0f0a5078:
/*  f0a5078:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0a507c:	5452fff8 */ 	bnel	$v0,$s2,.L0f0a5060
/*  f0a5080:	00106880 */ 	sll	$t5,$s0,0x2
/*  f0a5084:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a5088:
/*  f0a5088:	1a20000f */ 	blez	$s1,.L0f0a50c8
/*  f0a508c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0a5090:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a5094:	27a400c4 */ 	addiu	$a0,$sp,0xc4
/*  f0a5098:	8fa60134 */ 	lw	$a2,0x134($sp)
.L0f0a509c:
/*  f0a509c:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0a50a0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0a50a4:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f0a50a8:	11e00005 */ 	beqz	$t7,.L0f0a50c0
/*  f0a50ac:	00c37021 */ 	addu	$t6,$a2,$v1
/*  f0a50b0:	8dc50000 */ 	lw	$a1,0x0($t6)
/*  f0a50b4:	10a00002 */ 	beqz	$a1,.L0f0a50c0
/*  f0a50b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a50bc:	aca70000 */ 	sw	$a3,0x0($a1)
.L0f0a50c0:
/*  f0a50c0:	1451fff6 */ 	bne	$v0,$s1,.L0f0a509c
/*  f0a50c4:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f0a50c8:
/*  f0a50c8:	24120050 */ 	addiu	$s2,$zero,0x50
/*  f0a50cc:	8fb40140 */ 	lw	$s4,0x140($sp)
/*  f0a50d0:	27b10070 */ 	addiu	$s1,$sp,0x70
/*  f0a50d4:	8fa40120 */ 	lw	$a0,0x120($sp)
.L0f0a50d8:
/*  f0a50d8:	0c006a47 */ 	jal	func0001a91c
/*  f0a50dc:	02402825 */ 	or	$a1,$s2,$zero
/*  f0a50e0:	10400077 */ 	beqz	$v0,.L0f0a52c0
/*  f0a50e4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a50e8:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0a50ec:	12e10074 */ 	beq	$s7,$at,.L0f0a52c0
/*  f0a50f0:	24010013 */ 	addiu	$at,$zero,0x13
/*  f0a50f4:	12e10072 */ 	beq	$s7,$at,.L0f0a52c0
/*  f0a50f8:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f0a50fc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5100:	c426c930 */ 	lwc1	$f6,%lo(var7f1ac930)($at)
/*  f0a5104:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f0a5108:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a510c:	460a3502 */ 	mul.s	$f20,$f6,$f10
/*  f0a5110:	0c006949 */ 	jal	func0001a524
/*  f0a5114:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5118:	c6100000 */ 	lwc1	$f16,0x0($s0)
/*  f0a511c:	c7b200d8 */ 	lwc1	$f18,0xd8($sp)
/*  f0a5120:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*  f0a5124:	c7a600e8 */ 	lwc1	$f6,0xe8($sp)
/*  f0a5128:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0a512c:	c6120008 */ 	lwc1	$f18,0x8($s0)
/*  f0a5130:	00409825 */ 	or	$s3,$v0,$zero
/*  f0a5134:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0a5138:	c7a800f8 */ 	lwc1	$f8,0xf8($sp)
/*  f0a513c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0a5140:	46089182 */ 	mul.s	$f6,$f18,$f8
/*  f0a5144:	460a2400 */ 	add.s	$f16,$f4,$f10
/*  f0a5148:	c7aa0108 */ 	lwc1	$f10,0x108($sp)
/*  f0a514c:	46068100 */ 	add.s	$f4,$f16,$f6
/*  f0a5150:	c7b000dc */ 	lwc1	$f16,0xdc($sp)
/*  f0a5154:	46045480 */ 	add.s	$f18,$f10,$f4
/*  f0a5158:	c7a400ec */ 	lwc1	$f4,0xec($sp)
/*  f0a515c:	e7b20060 */ 	swc1	$f18,0x60($sp)
/*  f0a5160:	c6080000 */ 	lwc1	$f8,0x0($s0)
/*  f0a5164:	c60a0004 */ 	lwc1	$f10,0x4($s0)
/*  f0a5168:	46104182 */ 	mul.s	$f6,$f8,$f16
/*  f0a516c:	c6100008 */ 	lwc1	$f16,0x8($s0)
/*  f0a5170:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f0a5174:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f0a5178:	460a8102 */ 	mul.s	$f4,$f16,$f10
/*  f0a517c:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f0a5180:	c7b2010c */ 	lwc1	$f18,0x10c($sp)
/*  f0a5184:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0a5188:	c7a800e0 */ 	lwc1	$f8,0xe0($sp)
/*  f0a518c:	46069400 */ 	add.s	$f16,$f18,$f6
/*  f0a5190:	c7a600f0 */ 	lwc1	$f6,0xf0($sp)
/*  f0a5194:	e7b00064 */ 	swc1	$f16,0x64($sp)
/*  f0a5198:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f0a519c:	c6120004 */ 	lwc1	$f18,0x4($s0)
/*  f0a51a0:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0a51a4:	c6080008 */ 	lwc1	$f8,0x8($s0)
/*  f0a51a8:	46069402 */ 	mul.s	$f16,$f18,$f6
/*  f0a51ac:	c7b20100 */ 	lwc1	$f18,0x100($sp)
/*  f0a51b0:	46124182 */ 	mul.s	$f6,$f8,$f18
/*  f0a51b4:	46102280 */ 	add.s	$f10,$f4,$f16
/*  f0a51b8:	c7b00110 */ 	lwc1	$f16,0x110($sp)
/*  f0a51bc:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f0a51c0:	46048200 */ 	add.s	$f8,$f16,$f4
/*  f0a51c4:	0c00566c */ 	jal	func000159b0
/*  f0a51c8:	e7a80068 */ 	swc1	$f8,0x68($sp)
/*  f0a51cc:	0c004b70 */ 	jal	random
/*  f0a51d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a51d4:	44829000 */ 	mtc1	$v0,$f18
/*  f0a51d8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0a51dc:	04410005 */ 	bgez	$v0,.L0f0a51f4
/*  f0a51e0:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f0a51e4:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a51e8:	44813000 */ 	mtc1	$at,$f6
/*  f0a51ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a51f0:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f0a51f4:
/*  f0a51f4:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a51f8:	44818000 */ 	mtc1	$at,$f16
/*  f0a51fc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5200:	c428c934 */ 	lwc1	$f8,%lo(var7f1ac934)($at)
/*  f0a5204:	46105102 */ 	mul.s	$f4,$f10,$f16
/*  f0a5208:	c7b00064 */ 	lwc1	$f16,0x64($sp)
/*  f0a520c:	c7a60060 */ 	lwc1	$f6,0x60($sp)
/*  f0a5210:	46003287 */ 	neg.s	$f10,$f6
/*  f0a5214:	46082482 */ 	mul.s	$f18,$f4,$f8
/*  f0a5218:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*  f0a521c:	46008107 */ 	neg.s	$f4,$f16
/*  f0a5220:	44065000 */ 	mfc1	$a2,$f10
/*  f0a5224:	44072000 */ 	mfc1	$a3,$f4
/*  f0a5228:	44059000 */ 	mfc1	$a1,$f18
/*  f0a522c:	46004487 */ 	neg.s	$f18,$f8
/*  f0a5230:	0c005c0a */ 	jal	func00017028
/*  f0a5234:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0a5238:	4600a306 */ 	mov.s	$f12,$f20
/*  f0a523c:	0c0057c1 */ 	jal	func00015f04
/*  f0a5240:	02202825 */ 	or	$a1,$s1,$zero
/*  f0a5244:	c6a60030 */ 	lwc1	$f6,0x30($s5)
/*  f0a5248:	c6ca01c0 */ 	lwc1	$f10,0x1c0($s6)
/*  f0a524c:	c6a40034 */ 	lwc1	$f4,0x34($s5)
/*  f0a5250:	c6c801c4 */ 	lwc1	$f8,0x1c4($s6)
/*  f0a5254:	460a3401 */ 	sub.s	$f16,$f6,$f10
/*  f0a5258:	c6ca01c8 */ 	lwc1	$f10,0x1c8($s6)
/*  f0a525c:	c6a60038 */ 	lwc1	$f6,0x38($s5)
/*  f0a5260:	46082481 */ 	sub.s	$f18,$f4,$f8
/*  f0a5264:	44068000 */ 	mfc1	$a2,$f16
/*  f0a5268:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a526c:	460a3401 */ 	sub.s	$f16,$f6,$f10
/*  f0a5270:	44079000 */ 	mfc1	$a3,$f18
/*  f0a5274:	24050000 */ 	addiu	$a1,$zero,0x0
/*  f0a5278:	0c005ba6 */ 	jal	func00016e98
/*  f0a527c:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f0a5280:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a5284:	0c00567f */ 	jal	func000159fc
/*  f0a5288:	02202825 */ 	or	$a1,$s1,$zero
/*  f0a528c:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0a5290:	0c0059c4 */ 	jal	func00016710
/*  f0a5294:	02202825 */ 	or	$a1,$s1,$zero
/*  f0a5298:	8fa4013c */ 	lw	$a0,0x13c($sp)
/*  f0a529c:	0c00567f */ 	jal	func000159fc
/*  f0a52a0:	02202825 */ 	or	$a1,$s1,$zero
/*  f0a52a4:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f0a52a8:	0c005775 */ 	jal	func00015dd4
/*  f0a52ac:	02202825 */ 	or	$a1,$s1,$zero
/*  f0a52b0:	0013c980 */ 	sll	$t9,$s3,0x6
/*  f0a52b4:	02b92821 */ 	addu	$a1,$s5,$t9
/*  f0a52b8:	0c005746 */ 	jal	func00015d18
/*  f0a52bc:	02202025 */ 	or	$a0,$s1,$zero
.L0f0a52c0:
/*  f0a52c0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0a52c4:	24010053 */ 	addiu	$at,$zero,0x53
/*  f0a52c8:	5641ff83 */ 	bnel	$s2,$at,.L0f0a50d8
/*  f0a52cc:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f0a52d0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0a52d4:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0a52d8:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0a52dc:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0a52e0:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f0a52e4:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f0a52e8:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f0a52ec:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f0a52f0:	8fb6003c */ 	lw	$s6,0x3c($sp)
/*  f0a52f4:	8fb70040 */ 	lw	$s7,0x40($sp)
/*  f0a52f8:	03e00008 */ 	jr	$ra
/*  f0a52fc:	27bd0118 */ 	addiu	$sp,$sp,0x118
);

GLOBAL_ASM(
glabel func0f0a5300
/*  f0a5300:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f0a5304:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a5308:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a530c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0a5310:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0a5314:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a5318:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f0a531c:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f0a5320:	afa60080 */ 	sw	$a2,0x80($sp)
/*  f0a5324:	afa70084 */ 	sw	$a3,0x84($sp)
/*  f0a5328:	afae0070 */ 	sw	$t6,0x70($sp)
/*  f0a532c:	904f1583 */ 	lbu	$t7,0x1583($v0)
/*  f0a5330:	31f8fff7 */ 	andi	$t8,$t7,0xfff7
/*  f0a5334:	a0581583 */ 	sb	$t8,0x1583($v0)
/*  f0a5338:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f0a533c:	53200055 */ 	beqzl	$t9,.L0f0a5494
/*  f0a5340:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f0a5344:	8c680284 */ 	lw	$t0,0x284($v1)
/*  f0a5348:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f0a534c:	8fa90084 */ 	lw	$t1,0x84($sp)
/*  f0a5350:	c5040078 */ 	lwc1	$f4,0x78($t0)
/*  f0a5354:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0a5358:	1080003b */ 	beqz	$a0,.L0f0a5448
/*  f0a535c:	e7a40074 */ 	swc1	$f4,0x74($sp)
/*  f0a5360:	11210039 */ 	beq	$t1,$at,.L0f0a5448
/*  f0a5364:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0a5368:	11210037 */ 	beq	$t1,$at,.L0f0a5448
/*  f0a536c:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0a5370:	1521000a */ 	bne	$t1,$at,.L0f0a539c
/*  f0a5374:	2405003c */ 	addiu	$a1,$zero,0x3c
/*  f0a5378:	8faa0078 */ 	lw	$t2,0x78($sp)
/*  f0a537c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a5380:	24050031 */ 	addiu	$a1,$zero,0x31
/*  f0a5384:	8d4b0558 */ 	lw	$t3,0x558($t2)
/*  f0a5388:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f0a538c:	15810003 */ 	bne	$t4,$at,.L0f0a539c
/*  f0a5390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5394:	10000001 */ 	beqz	$zero,.L0f0a539c
/*  f0a5398:	24050030 */ 	addiu	$a1,$zero,0x30
.L0f0a539c:
/*  f0a539c:	0c006a47 */ 	jal	func0001a91c
/*  f0a53a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a53a4:	10400017 */ 	beqz	$v0,.L0f0a5404
/*  f0a53a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a53ac:	0c006949 */ 	jal	func0001a524
/*  f0a53b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a53b4:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f0a53b8:	00027180 */ 	sll	$t6,$v0,0x6
/*  f0a53bc:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f0a53c0:	0c005746 */ 	jal	func00015d18
/*  f0a53c4:	01ae2021 */ 	addu	$a0,$t5,$t6
/*  f0a53c8:	3c017f1b */ 	lui	$at,%hi(var7f1ac938)
/*  f0a53cc:	c42cc938 */ 	lwc1	$f12,%lo(var7f1ac938)($at)
/*  f0a53d0:	0c0057c1 */ 	jal	func00015f04
/*  f0a53d4:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f0a53d8:	0fc2d5de */ 	jal	func0f0b5778
/*  f0a53dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a53e0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a53e4:	0c00567f */ 	jal	func000159fc
/*  f0a53e8:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f0a53ec:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f0a53f0:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f0a53f4:	0fc2b780 */ 	jal	func0f0ade00
/*  f0a53f8:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f0a53fc:	10000007 */ 	beqz	$zero,.L0f0a541c
/*  f0a5400:	24040046 */ 	addiu	$a0,$zero,0x46
.L0f0a5404:
/*  f0a5404:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0a5408:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f0a540c:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f0a5410:	0fc2b780 */ 	jal	func0f0ade00
/*  f0a5414:	24c602f4 */ 	addiu	$a2,$a2,0x2f4
/*  f0a5418:	24040046 */ 	addiu	$a0,$zero,0x46
.L0f0a541c:
/*  f0a541c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a5420:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0a5424:	0fc25f9d */ 	jal	func0f097e74
/*  f0a5428:	8fa70088 */ 	lw	$a3,0x88($sp)
/*  f0a542c:	24040047 */ 	addiu	$a0,$zero,0x47
/*  f0a5430:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a5434:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0a5438:	0fc25f9d */ 	jal	func0f097e74
/*  f0a543c:	8fa70088 */ 	lw	$a3,0x88($sp)
/*  f0a5440:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a5444:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
.L0f0a5448:
/*  f0a5448:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f0a544c:	24010201 */ 	addiu	$at,$zero,0x201
/*  f0a5450:	8de20000 */ 	lw	$v0,0x0($t7)
/*  f0a5454:	14410007 */ 	bne	$v0,$at,.L0f0a5474
/*  f0a5458:	304800ff */ 	andi	$t0,$v0,0xff
/*  f0a545c:	8c780284 */ 	lw	$t8,0x284($v1)
/*  f0a5460:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f0a5464:	0fc0897d */ 	jal	chrUncloakTemporarily
/*  f0a5468:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f0a546c:	10000009 */ 	beqz	$zero,.L0f0a5494
/*  f0a5470:	8fab0080 */ 	lw	$t3,0x80($sp)
.L0f0a5474:
/*  f0a5474:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a5478:	55010006 */ 	bnel	$t0,$at,.L0f0a5494
/*  f0a547c:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f0a5480:	8c690284 */ 	lw	$t1,0x284($v1)
/*  f0a5484:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0a5488:	0fc0897d */ 	jal	chrUncloakTemporarily
/*  f0a548c:	8d440004 */ 	lw	$a0,0x4($t2)
/*  f0a5490:	8fab0080 */ 	lw	$t3,0x80($sp)
.L0f0a5494:
/*  f0a5494:	51600012 */ 	beqzl	$t3,.L0f0a54e0
/*  f0a5498:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0a549c:	8d620000 */ 	lw	$v0,0x0($t3)
/*  f0a54a0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0a54a4:	304300ff */ 	andi	$v1,$v0,0xff
/*  f0a54a8:	10610003 */ 	beq	$v1,$at,.L0f0a54b8
/*  f0a54ac:	304c0200 */ 	andi	$t4,$v0,0x200
/*  f0a54b0:	51800003 */ 	beqzl	$t4,.L0f0a54c0
/*  f0a54b4:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0a54b8:
/*  f0a54b8:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f0a54bc:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0a54c0:
/*  f0a54c0:	54610003 */ 	bnel	$v1,$at,.L0f0a54d0
/*  f0a54c4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a54c8:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f0a54cc:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0a54d0:
/*  f0a54d0:	54610003 */ 	bnel	$v1,$at,.L0f0a54e0
/*  f0a54d4:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0a54d8:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f0a54dc:	8fad0070 */ 	lw	$t5,0x70($sp)
.L0f0a54e0:
/*  f0a54e0:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0a54e4:	11a00016 */ 	beqz	$t5,.L0f0a5540
/*  f0a54e8:	25cffffe */ 	addiu	$t7,$t6,-2
/*  f0a54ec:	2de1002a */ 	sltiu	$at,$t7,0x2a
/*  f0a54f0:	10200013 */ 	beqz	$at,.L0f0a5540
/*  f0a54f4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a54f8:	3c017f1b */ 	lui	$at,%hi(var7f1ac93c)
/*  f0a54fc:	002f0821 */ 	addu	$at,$at,$t7
/*  f0a5500:	8c2fc93c */ 	lw	$t7,%lo(var7f1ac93c)($at)
/*  f0a5504:	01e00008 */ 	jr	$t7
/*  f0a5508:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a550c:	0fc2b04e */ 	jal	func0f0ac138
/*  f0a5510:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f0a5514:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f0a5518:	8f190028 */ 	lw	$t9,0x28($t8)
/*  f0a551c:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0a5520:	10000007 */ 	beqz	$zero,.L0f0a5540
/*  f0a5524:	af080028 */ 	sw	$t0,0x28($t8)
/*  f0a5528:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0a552c:	8d2a0028 */ 	lw	$t2,0x28($t1)
/*  f0a5530:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f0a5534:	ad2b0028 */ 	sw	$t3,0x28($t1)
/*  f0a5538:	0fc2b04e */ 	jal	func0f0ac138
/*  f0a553c:	8fa4007c */ 	lw	$a0,0x7c($sp)
.L0f0a5540:
/*  f0a5540:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a5544:	27bd0078 */ 	addiu	$sp,$sp,0x78
/*  f0a5548:	03e00008 */ 	jr	$ra
/*  f0a554c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a5550
/*  f0a5550:	27bdfcf8 */ 	addiu	$sp,$sp,-776
/*  f0a5554:	3c0f8007 */ 	lui	$t7,%hi(var80070244)
/*  f0a5558:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0a555c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0a5560:	afa00280 */ 	sw	$zero,0x280($sp)
/*  f0a5564:	25ef0244 */ 	addiu	$t7,$t7,%lo(var80070244)
/*  f0a5568:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0a556c:	27ae0274 */ 	addiu	$t6,$sp,0x274
/*  f0a5570:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f0a5574:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0a5578:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0a557c:	3c0b8007 */ 	lui	$t3,%hi(var80070250)
/*  f0a5580:	256b0250 */ 	addiu	$t3,$t3,%lo(var80070250)
/*  f0a5584:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f0a5588:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0a558c:	8d610000 */ 	lw	$at,0x0($t3)
/*  f0a5590:	27aa01e4 */ 	addiu	$t2,$sp,0x1e4
/*  f0a5594:	8d790004 */ 	lw	$t9,0x4($t3)
/*  f0a5598:	ad410000 */ 	sw	$at,0x0($t2)
/*  f0a559c:	8d610008 */ 	lw	$at,0x8($t3)
/*  f0a55a0:	00041900 */ 	sll	$v1,$a0,0x4
/*  f0a55a4:	00641823 */ 	subu	$v1,$v1,$a0
/*  f0a55a8:	00031880 */ 	sll	$v1,$v1,0x2
/*  f0a55ac:	3c02800a */ 	lui	$v0,0x800a
/*  f0a55b0:	00641821 */ 	addu	$v1,$v1,$a0
/*  f0a55b4:	ad590004 */ 	sw	$t9,0x4($t2)
/*  f0a55b8:	ad410008 */ 	sw	$at,0x8($t2)
/*  f0a55bc:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a55c0:	000318c0 */ 	sll	$v1,$v1,0x3
/*  f0a55c4:	00641821 */ 	addu	$v1,$v1,$a0
/*  f0a55c8:	00031880 */ 	sll	$v1,$v1,0x2
/*  f0a55cc:	00438021 */ 	addu	$s0,$v0,$v1
/*  f0a55d0:	26100638 */ 	addiu	$s0,$s0,0x638
/*  f0a55d4:	afa001e0 */ 	sw	$zero,0x1e0($sp)
/*  f0a55d8:	afb001d4 */ 	sw	$s0,0x1d4($sp)
/*  f0a55dc:	afa001cc */ 	sw	$zero,0x1cc($sp)
/*  f0a55e0:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f0a55e4:	afa40308 */ 	sw	$a0,0x308($sp)
/*  f0a55e8:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f0a55ec:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f0a55f0:	afa201c4 */ 	sw	$v0,0x1c4($sp)
/*  f0a55f4:	afa001b8 */ 	sw	$zero,0x1b8($sp)
/*  f0a55f8:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a55fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a5600:	8fb80308 */ 	lw	$t8,0x308($sp)
/*  f0a5604:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a5608:	afa201c0 */ 	sw	$v0,0x1c0($sp)
/*  f0a560c:	17010007 */ 	bne	$t8,$at,.L0f0a562c
/*  f0a5610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5614:	8fae01c4 */ 	lw	$t6,0x1c4($sp)
/*  f0a5618:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0a561c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0a5620:	15c10002 */ 	bne	$t6,$at,.L0f0a562c
/*  f0a5624:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5628:	afaf01b8 */ 	sw	$t7,0x1b8($sp)
.L0f0a562c:
/*  f0a562c:	0fc2c40f */ 	jal	func0f0b103c
/*  f0a5630:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a5634:	10400007 */ 	beqz	$v0,.L0f0a5654
/*  f0a5638:	afa201d0 */ 	sw	$v0,0x1d0($sp)
/*  f0a563c:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f0a5640:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a5644:	312d00ff */ 	andi	$t5,$t1,0xff
/*  f0a5648:	55a10003 */ 	bnel	$t5,$at,.L0f0a5658
/*  f0a564c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a5650:	afa201cc */ 	sw	$v0,0x1cc($sp)
.L0f0a5654:
/*  f0a5654:	02002025 */ 	or	$a0,$s0,$zero
.L0f0a5658:
/*  f0a5658:	0fc27554 */ 	jal	func0f09d550
/*  f0a565c:	8fa50308 */ 	lw	$a1,0x308($sp)
/*  f0a5660:	8fac0308 */ 	lw	$t4,0x308($sp)
/*  f0a5664:	1580002b */ 	bnez	$t4,.L0f0a5714
/*  f0a5668:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a566c:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f0a5670:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a5674:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a5678:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a567c:	24050040 */ 	addiu	$a1,$zero,0x40
/*  f0a5680:	10400013 */ 	beqz	$v0,.L0f0a56d0
/*  f0a5684:	3c01800a */ 	lui	$at,0x800a
/*  f0a5688:	3c014000 */ 	lui	$at,0x4000
/*  f0a568c:	44811000 */ 	mtc1	$at,$f2
/*  f0a5690:	3c01800a */ 	lui	$at,0x800a
/*  f0a5694:	c420a00c */ 	lwc1	$f0,-0x5ff4($at)
/*  f0a5698:	3c014370 */ 	lui	$at,0x4370
/*  f0a569c:	44813000 */ 	mtc1	$at,$f6
/*  f0a56a0:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f0a56a4:	c60a01bc */ 	lwc1	$f10,0x1bc($s0)
/*  f0a56a8:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f0a56ac:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f0a56b0:	e61001bc */ 	swc1	$f16,0x1bc($s0)
/*  f0a56b4:	c61201bc */ 	lwc1	$f18,0x1bc($s0)
/*  f0a56b8:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0a56bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a56c0:	4502003f */ 	bc1fl	.L0f0a57c0
/*  f0a56c4:	8faa0308 */ 	lw	$t2,0x308($sp)
/*  f0a56c8:	1000003c */ 	beqz	$zero,.L0f0a57bc
/*  f0a56cc:	e60201bc */ 	swc1	$f2,0x1bc($s0)
.L0f0a56d0:
/*  f0a56d0:	c420a00c */ 	lwc1	$f0,-0x5ff4($at)
/*  f0a56d4:	3c014370 */ 	lui	$at,0x4370
/*  f0a56d8:	44813000 */ 	mtc1	$at,$f6
/*  f0a56dc:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f0a56e0:	c60801bc */ 	lwc1	$f8,0x1bc($s0)
/*  f0a56e4:	46062283 */ 	div.s	$f10,$f4,$f6
/*  f0a56e8:	44802000 */ 	mtc1	$zero,$f4
/*  f0a56ec:	460a4401 */ 	sub.s	$f16,$f8,$f10
/*  f0a56f0:	e61001bc */ 	swc1	$f16,0x1bc($s0)
/*  f0a56f4:	c61201bc */ 	lwc1	$f18,0x1bc($s0)
/*  f0a56f8:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0a56fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5700:	4502002f */ 	bc1fl	.L0f0a57c0
/*  f0a5704:	8faa0308 */ 	lw	$t2,0x308($sp)
/*  f0a5708:	44803000 */ 	mtc1	$zero,$f6
/*  f0a570c:	1000002b */ 	beqz	$zero,.L0f0a57bc
/*  f0a5710:	e60601bc */ 	swc1	$f6,0x1bc($s0)
.L0f0a5714:
/*  f0a5714:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f0a5718:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a571c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a5720:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a5724:	24050040 */ 	addiu	$a1,$zero,0x40
/*  f0a5728:	10400013 */ 	beqz	$v0,.L0f0a5778
/*  f0a572c:	3c01800a */ 	lui	$at,0x800a
/*  f0a5730:	3c01c000 */ 	lui	$at,0xc000
/*  f0a5734:	44811000 */ 	mtc1	$at,$f2
/*  f0a5738:	3c01800a */ 	lui	$at,0x800a
/*  f0a573c:	c420a00c */ 	lwc1	$f0,-0x5ff4($at)
/*  f0a5740:	3c014370 */ 	lui	$at,0x4370
/*  f0a5744:	44815000 */ 	mtc1	$at,$f10
/*  f0a5748:	46000200 */ 	add.s	$f8,$f0,$f0
/*  f0a574c:	c61201bc */ 	lwc1	$f18,0x1bc($s0)
/*  f0a5750:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f0a5754:	46109101 */ 	sub.s	$f4,$f18,$f16
/*  f0a5758:	e60401bc */ 	swc1	$f4,0x1bc($s0)
/*  f0a575c:	c60601bc */ 	lwc1	$f6,0x1bc($s0)
/*  f0a5760:	4602303c */ 	c.lt.s	$f6,$f2
/*  f0a5764:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5768:	45020015 */ 	bc1fl	.L0f0a57c0
/*  f0a576c:	8faa0308 */ 	lw	$t2,0x308($sp)
/*  f0a5770:	10000012 */ 	beqz	$zero,.L0f0a57bc
/*  f0a5774:	e60201bc */ 	swc1	$f2,0x1bc($s0)
.L0f0a5778:
/*  f0a5778:	c420a00c */ 	lwc1	$f0,-0x5ff4($at)
/*  f0a577c:	3c014370 */ 	lui	$at,0x4370
/*  f0a5780:	44815000 */ 	mtc1	$at,$f10
/*  f0a5784:	46000200 */ 	add.s	$f8,$f0,$f0
/*  f0a5788:	c61001bc */ 	lwc1	$f16,0x1bc($s0)
/*  f0a578c:	44803000 */ 	mtc1	$zero,$f6
/*  f0a5790:	460a4483 */ 	div.s	$f18,$f8,$f10
/*  f0a5794:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0a5798:	e60401bc */ 	swc1	$f4,0x1bc($s0)
/*  f0a579c:	c60801bc */ 	lwc1	$f8,0x1bc($s0)
/*  f0a57a0:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0a57a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a57a8:	45020005 */ 	bc1fl	.L0f0a57c0
/*  f0a57ac:	8faa0308 */ 	lw	$t2,0x308($sp)
/*  f0a57b0:	44805000 */ 	mtc1	$zero,$f10
/*  f0a57b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a57b8:	e60a01bc */ 	swc1	$f10,0x1bc($s0)
.L0f0a57bc:
/*  f0a57bc:	8faa0308 */ 	lw	$t2,0x308($sp)
.L0f0a57c0:
/*  f0a57c0:	55400017 */ 	bnezl	$t2,.L0f0a5820
/*  f0a57c4:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f0a57c8:	0fc2c4c7 */ 	jal	func0f0b131c
/*  f0a57cc:	01402025 */ 	or	$a0,$t2,$zero
/*  f0a57d0:	c61200b8 */ 	lwc1	$f18,0xb8($s0)
/*  f0a57d4:	c61001b0 */ 	lwc1	$f16,0x1b0($s0)
/*  f0a57d8:	8fab01c0 */ 	lw	$t3,0x1c0($sp)
/*  f0a57dc:	46120100 */ 	add.s	$f4,$f0,$f18
/*  f0a57e0:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f0a57e4:	e7a60274 */ 	swc1	$f6,0x274($sp)
/*  f0a57e8:	c60a00bc */ 	lwc1	$f10,0xbc($s0)
/*  f0a57ec:	c5680030 */ 	lwc1	$f8,0x30($t3)
/*  f0a57f0:	c61001b4 */ 	lwc1	$f16,0x1b4($s0)
/*  f0a57f4:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f0a57f8:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0a57fc:	e7a40278 */ 	swc1	$f4,0x278($sp)
/*  f0a5800:	c60800c0 */ 	lwc1	$f8,0xc0($s0)
/*  f0a5804:	c5660034 */ 	lwc1	$f6,0x34($t3)
/*  f0a5808:	c61001b8 */ 	lwc1	$f16,0x1b8($s0)
/*  f0a580c:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0a5810:	460a8480 */ 	add.s	$f18,$f16,$f10
/*  f0a5814:	1000002e */ 	beqz	$zero,.L0f0a58d0
/*  f0a5818:	e7b2027c */ 	swc1	$f18,0x27c($sp)
/*  f0a581c:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
.L0f0a5820:
/*  f0a5820:	3c0140d0 */ 	lui	$at,0x40d0
/*  f0a5824:	13200016 */ 	beqz	$t9,.L0f0a5880
/*  f0a5828:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a582c:	44812000 */ 	mtc1	$at,$f4
/*  f0a5830:	c60600b8 */ 	lwc1	$f6,0xb8($s0)
/*  f0a5834:	c61001b0 */ 	lwc1	$f16,0x1b0($s0)
/*  f0a5838:	3c01c184 */ 	lui	$at,0xc184
/*  f0a583c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0a5840:	44819000 */ 	mtc1	$at,$f18
/*  f0a5844:	3c01c180 */ 	lui	$at,0xc180
/*  f0a5848:	46104281 */ 	sub.s	$f10,$f8,$f16
/*  f0a584c:	e7aa0274 */ 	swc1	$f10,0x274($sp)
/*  f0a5850:	c60400bc */ 	lwc1	$f4,0xbc($s0)
/*  f0a5854:	c60801b4 */ 	lwc1	$f8,0x1b4($s0)
/*  f0a5858:	44815000 */ 	mtc1	$at,$f10
/*  f0a585c:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0a5860:	46064400 */ 	add.s	$f16,$f8,$f6
/*  f0a5864:	e7b00278 */ 	swc1	$f16,0x278($sp)
/*  f0a5868:	c61200c0 */ 	lwc1	$f18,0xc0($s0)
/*  f0a586c:	c60801b8 */ 	lwc1	$f8,0x1b8($s0)
/*  f0a5870:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f0a5874:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0a5878:	10000015 */ 	beqz	$zero,.L0f0a58d0
/*  f0a587c:	e7a6027c */ 	swc1	$f6,0x27c($sp)
.L0f0a5880:
/*  f0a5880:	0fc2c4c7 */ 	jal	func0f0b131c
/*  f0a5884:	8fa40308 */ 	lw	$a0,0x308($sp)
/*  f0a5888:	c61000b8 */ 	lwc1	$f16,0xb8($s0)
/*  f0a588c:	c61201b0 */ 	lwc1	$f18,0x1b0($s0)
/*  f0a5890:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f0a5894:	46100280 */ 	add.s	$f10,$f0,$f16
/*  f0a5898:	46125201 */ 	sub.s	$f8,$f10,$f18
/*  f0a589c:	e7a80274 */ 	swc1	$f8,0x274($sp)
/*  f0a58a0:	c60600bc */ 	lwc1	$f6,0xbc($s0)
/*  f0a58a4:	c7040030 */ 	lwc1	$f4,0x30($t8)
/*  f0a58a8:	c60a01b4 */ 	lwc1	$f10,0x1b4($s0)
/*  f0a58ac:	46062400 */ 	add.s	$f16,$f4,$f6
/*  f0a58b0:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f0a58b4:	e7b20278 */ 	swc1	$f18,0x278($sp)
/*  f0a58b8:	c60400c0 */ 	lwc1	$f4,0xc0($s0)
/*  f0a58bc:	c7080034 */ 	lwc1	$f8,0x34($t8)
/*  f0a58c0:	c60a01b8 */ 	lwc1	$f10,0x1b8($s0)
/*  f0a58c4:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0a58c8:	46065400 */ 	add.s	$f16,$f10,$f6
/*  f0a58cc:	e7b0027c */ 	swc1	$f16,0x27c($sp)
.L0f0a58d0:
/*  f0a58d0:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0a58d4:	44810000 */ 	mtc1	$at,$f0
/*  f0a58d8:	8fae01d8 */ 	lw	$t6,0x1d8($sp)
/*  f0a58dc:	3c014248 */ 	lui	$at,0x4248
/*  f0a58e0:	44811000 */ 	mtc1	$at,$f2
/*  f0a58e4:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0a58e8:	44814000 */ 	mtc1	$at,$f8
/*  f0a58ec:	c5d21968 */ 	lwc1	$f18,0x1968($t6)
/*  f0a58f0:	c7b00278 */ 	lwc1	$f16,0x278($sp)
/*  f0a58f4:	3c014170 */ 	lui	$at,0x4170
/*  f0a58f8:	46089102 */ 	mul.s	$f4,$f18,$f8
/*  f0a58fc:	46002283 */ 	div.s	$f10,$f4,$f0
/*  f0a5900:	44812000 */ 	mtc1	$at,$f4
/*  f0a5904:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f0a5908:	46068480 */ 	add.s	$f18,$f16,$f6
/*  f0a590c:	e7b20278 */ 	swc1	$f18,0x278($sp)
/*  f0a5910:	c5c81968 */ 	lwc1	$f8,0x1968($t6)
/*  f0a5914:	c7b2027c */ 	lwc1	$f18,0x27c($sp)
/*  f0a5918:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f0a591c:	46005403 */ 	div.s	$f16,$f10,$f0
/*  f0a5920:	46028182 */ 	mul.s	$f6,$f16,$f2
/*  f0a5924:	46069201 */ 	sub.s	$f8,$f18,$f6
/*  f0a5928:	e7a8027c */ 	swc1	$f8,0x27c($sp)
/*  f0a592c:	820f0004 */ 	lb	$t7,0x4($s0)
/*  f0a5930:	11e00054 */ 	beqz	$t7,.L0f0a5a84
/*  f0a5934:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5938:	8fa201cc */ 	lw	$v0,0x1cc($sp)
/*  f0a593c:	3c09800a */ 	lui	$t1,0x800a
/*  f0a5940:	10400050 */ 	beqz	$v0,.L0f0a5a84
/*  f0a5944:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5948:	8d299ff4 */ 	lw	$t1,-0x600c($t1)
/*  f0a594c:	1120004d */ 	beqz	$t1,.L0f0a5a84
/*  f0a5950:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5954:	8c4d0014 */ 	lw	$t5,0x14($v0)
/*  f0a5958:	11a0004a */ 	beqz	$t5,.L0f0a5a84
/*  f0a595c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5960:	0c004b70 */ 	jal	random
/*  f0a5964:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5968:	44822000 */ 	mtc1	$v0,$f4
/*  f0a596c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a5970:	04410004 */ 	bgez	$v0,.L0f0a5984
/*  f0a5974:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0a5978:	44818000 */ 	mtc1	$at,$f16
/*  f0a597c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5980:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0a5984:
/*  f0a5984:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a5988:	44819000 */ 	mtc1	$at,$f18
/*  f0a598c:	8fac01cc */ 	lw	$t4,0x1cc($sp)
/*  f0a5990:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a5994:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f0a5998:	44814000 */ 	mtc1	$at,$f8
/*  f0a599c:	8d8a0014 */ 	lw	$t2,0x14($t4)
/*  f0a59a0:	c6120284 */ 	lwc1	$f18,0x284($s0)
/*  f0a59a4:	c5500000 */ 	lwc1	$f16,0x0($t2)
/*  f0a59a8:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0a59ac:	c7a80274 */ 	lwc1	$f8,0x274($sp)
/*  f0a59b0:	46102282 */ 	mul.s	$f10,$f4,$f16
/*  f0a59b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a59b8:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f0a59bc:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0a59c0:	0c004b70 */ 	jal	random
/*  f0a59c4:	e7a40274 */ 	swc1	$f4,0x274($sp)
/*  f0a59c8:	44828000 */ 	mtc1	$v0,$f16
/*  f0a59cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a59d0:	04410004 */ 	bgez	$v0,.L0f0a59e4
/*  f0a59d4:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f0a59d8:	44819000 */ 	mtc1	$at,$f18
/*  f0a59dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a59e0:	46125280 */ 	add.s	$f10,$f10,$f18
.L0f0a59e4:
/*  f0a59e4:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a59e8:	44814000 */ 	mtc1	$at,$f8
/*  f0a59ec:	8fab01cc */ 	lw	$t3,0x1cc($sp)
/*  f0a59f0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a59f4:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0a59f8:	44812000 */ 	mtc1	$at,$f4
/*  f0a59fc:	8d790014 */ 	lw	$t9,0x14($t3)
/*  f0a5a00:	c6080284 */ 	lwc1	$f8,0x284($s0)
/*  f0a5a04:	c7320004 */ 	lwc1	$f18,0x4($t9)
/*  f0a5a08:	46043401 */ 	sub.s	$f16,$f6,$f4
/*  f0a5a0c:	c7a40278 */ 	lwc1	$f4,0x278($sp)
/*  f0a5a10:	46128282 */ 	mul.s	$f10,$f16,$f18
/*  f0a5a14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5a18:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0a5a1c:	46062400 */ 	add.s	$f16,$f4,$f6
/*  f0a5a20:	0c004b70 */ 	jal	random
/*  f0a5a24:	e7b00278 */ 	swc1	$f16,0x278($sp)
/*  f0a5a28:	44829000 */ 	mtc1	$v0,$f18
/*  f0a5a2c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a5a30:	04410004 */ 	bgez	$v0,.L0f0a5a44
/*  f0a5a34:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f0a5a38:	44814000 */ 	mtc1	$at,$f8
/*  f0a5a3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5a40:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f0a5a44:
/*  f0a5a44:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a5a48:	44812000 */ 	mtc1	$at,$f4
/*  f0a5a4c:	8fb801cc */ 	lw	$t8,0x1cc($sp)
/*  f0a5a50:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a5a54:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0a5a58:	44818000 */ 	mtc1	$at,$f16
/*  f0a5a5c:	8f0e0014 */ 	lw	$t6,0x14($t8)
/*  f0a5a60:	c6040284 */ 	lwc1	$f4,0x284($s0)
/*  f0a5a64:	c5c80008 */ 	lwc1	$f8,0x8($t6)
/*  f0a5a68:	46103481 */ 	sub.s	$f18,$f6,$f16
/*  f0a5a6c:	c7b0027c */ 	lwc1	$f16,0x27c($sp)
/*  f0a5a70:	46089282 */ 	mul.s	$f10,$f18,$f8
/*  f0a5a74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5a78:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0a5a7c:	46068480 */ 	add.s	$f18,$f16,$f6
/*  f0a5a80:	e7b2027c */ 	swc1	$f18,0x27c($sp)
.L0f0a5a84:
/*  f0a5a84:	0fc2d5f6 */ 	jal	func0f0b57d8
/*  f0a5a88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5a8c:	0fc2d5fe */ 	jal	func0f0b57f8
/*  f0a5a90:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*  f0a5a94:	0fc2d5f6 */ 	jal	func0f0b57d8
/*  f0a5a98:	e7a00064 */ 	swc1	$f0,0x64($sp)
/*  f0a5a9c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a5aa0:	44811000 */ 	mtc1	$at,$f2
/*  f0a5aa4:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f0a5aa8:	c7b00060 */ 	lwc1	$f16,0x60($sp)
/*  f0a5aac:	c7aa0064 */ 	lwc1	$f10,0x64($sp)
/*  f0a5ab0:	c5e81674 */ 	lwc1	$f8,0x1674($t7)
/*  f0a5ab4:	46028182 */ 	mul.s	$f6,$f16,$f2
/*  f0a5ab8:	8fa901c0 */ 	lw	$t1,0x1c0($sp)
/*  f0a5abc:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0a5ac0:	8d2d0024 */ 	lw	$t5,0x24($t1)
/*  f0a5ac4:	46062481 */ 	sub.s	$f18,$f4,$f6
/*  f0a5ac8:	c5a8000c */ 	lwc1	$f8,0xc($t5)
/*  f0a5acc:	46089282 */ 	mul.s	$f10,$f18,$f8
/*  f0a5ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5ad4:	46020402 */ 	mul.s	$f16,$f0,$f2
/*  f0a5ad8:	46105103 */ 	div.s	$f4,$f10,$f16
/*  f0a5adc:	0fc2d602 */ 	jal	func0f0b5808
/*  f0a5ae0:	e604076c */ 	swc1	$f4,0x76c($s0)
/*  f0a5ae4:	0fc2d5fa */ 	jal	func0f0b57e8
/*  f0a5ae8:	e7a00064 */ 	swc1	$f0,0x64($sp)
/*  f0a5aec:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a5af0:	44813000 */ 	mtc1	$at,$f6
/*  f0a5af4:	8fac01d8 */ 	lw	$t4,0x1d8($sp)
/*  f0a5af8:	c7aa0064 */ 	lwc1	$f10,0x64($sp)
/*  f0a5afc:	46060482 */ 	mul.s	$f18,$f0,$f6
/*  f0a5b00:	c5881678 */ 	lwc1	$f8,0x1678($t4)
/*  f0a5b04:	460a4401 */ 	sub.s	$f16,$f8,$f10
/*  f0a5b08:	4610903c */ 	c.lt.s	$f18,$f16
/*  f0a5b0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5b10:	4500001a */ 	bc1f	.L0f0a5b7c
/*  f0a5b14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5b18:	0fc2d5fa */ 	jal	func0f0b57e8
/*  f0a5b1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5b20:	0fc2d602 */ 	jal	func0f0b5808
/*  f0a5b24:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*  f0a5b28:	0fc2d5fa */ 	jal	func0f0b57e8
/*  f0a5b2c:	e7a00064 */ 	swc1	$f0,0x64($sp)
/*  f0a5b30:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a5b34:	44819000 */ 	mtc1	$at,$f18
/*  f0a5b38:	8faa01d8 */ 	lw	$t2,0x1d8($sp)
/*  f0a5b3c:	c7aa0060 */ 	lwc1	$f10,0x60($sp)
/*  f0a5b40:	c7a60064 */ 	lwc1	$f6,0x64($sp)
/*  f0a5b44:	c5441678 */ 	lwc1	$f4,0x1678($t2)
/*  f0a5b48:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f0a5b4c:	8fab01c0 */ 	lw	$t3,0x1c0($sp)
/*  f0a5b50:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0a5b54:	44819000 */ 	mtc1	$at,$f18
/*  f0a5b58:	8d790024 */ 	lw	$t9,0x24($t3)
/*  f0a5b5c:	46104101 */ 	sub.s	$f4,$f8,$f16
/*  f0a5b60:	c7260008 */ 	lwc1	$f6,0x8($t9)
/*  f0a5b64:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f0a5b68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5b6c:	46120202 */ 	mul.s	$f8,$f0,$f18
/*  f0a5b70:	46085403 */ 	div.s	$f16,$f10,$f8
/*  f0a5b74:	10000019 */ 	beqz	$zero,.L0f0a5bdc
/*  f0a5b78:	e6100770 */ 	swc1	$f16,0x770($s0)
.L0f0a5b7c:
/*  f0a5b7c:	0fc2d5fa */ 	jal	func0f0b57e8
/*  f0a5b80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5b84:	0fc2d602 */ 	jal	func0f0b5808
/*  f0a5b88:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*  f0a5b8c:	0fc2d5fa */ 	jal	func0f0b57e8
/*  f0a5b90:	e7a00064 */ 	swc1	$f0,0x64($sp)
/*  f0a5b94:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a5b98:	44814000 */ 	mtc1	$at,$f8
/*  f0a5b9c:	8fb801d8 */ 	lw	$t8,0x1d8($sp)
/*  f0a5ba0:	c7aa0060 */ 	lwc1	$f10,0x60($sp)
/*  f0a5ba4:	c7a60064 */ 	lwc1	$f6,0x64($sp)
/*  f0a5ba8:	c7041678 */ 	lwc1	$f4,0x1678($t8)
/*  f0a5bac:	46085402 */ 	mul.s	$f16,$f10,$f8
/*  f0a5bb0:	8fae01c0 */ 	lw	$t6,0x1c0($sp)
/*  f0a5bb4:	46062481 */ 	sub.s	$f18,$f4,$f6
/*  f0a5bb8:	44814000 */ 	mtc1	$at,$f8
/*  f0a5bbc:	8dcf0024 */ 	lw	$t7,0x24($t6)
/*  f0a5bc0:	46109101 */ 	sub.s	$f4,$f18,$f16
/*  f0a5bc4:	c5e60004 */ 	lwc1	$f6,0x4($t7)
/*  f0a5bc8:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f0a5bcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5bd0:	46080482 */ 	mul.s	$f18,$f0,$f8
/*  f0a5bd4:	46125403 */ 	div.s	$f16,$f10,$f18
/*  f0a5bd8:	e6100770 */ 	swc1	$f16,0x770($s0)
.L0f0a5bdc:
/*  f0a5bdc:	c600076c */ 	lwc1	$f0,0x76c($s0)
/*  f0a5be0:	c6020770 */ 	lwc1	$f2,0x770($s0)
/*  f0a5be4:	c7a40274 */ 	lwc1	$f4,0x274($sp)
/*  f0a5be8:	c7a80278 */ 	lwc1	$f8,0x278($sp)
/*  f0a5bec:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0a5bf0:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f0a5bf4:	24050040 */ 	addiu	$a1,$zero,0x40
/*  f0a5bf8:	46024281 */ 	sub.s	$f10,$f8,$f2
/*  f0a5bfc:	e7a60274 */ 	swc1	$f6,0x274($sp)
/*  f0a5c00:	e7aa0278 */ 	swc1	$f10,0x278($sp)
/*  f0a5c04:	a2090007 */ 	sb	$t1,0x7($s0)
/*  f0a5c08:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a5c0c:	8fa401c4 */ 	lw	$a0,0x1c4($sp)
/*  f0a5c10:	50400018 */ 	beqzl	$v0,.L0f0a5c74
/*  f0a5c14:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0a5c18:	8fa401c4 */ 	lw	$a0,0x1c4($sp)
/*  f0a5c1c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a5c20:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f0a5c24:	54400013 */ 	bnezl	$v0,.L0f0a5c74
/*  f0a5c28:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0a5c2c:	8e020020 */ 	lw	$v0,0x20($s0)
/*  f0a5c30:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a5c34:	1041000e */ 	beq	$v0,$at,.L0f0a5c70
/*  f0a5c38:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0a5c3c:	5041000d */ 	beql	$v0,$at,.L0f0a5c74
/*  f0a5c40:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0a5c44:	0fc2775f */ 	jal	func0f09dd7c
/*  f0a5c48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5c4c:	50400009 */ 	beqzl	$v0,.L0f0a5c74
/*  f0a5c50:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0a5c54:	820d0008 */ 	lb	$t5,0x8($s0)
/*  f0a5c58:	51a00006 */ 	beqzl	$t5,.L0f0a5c74
/*  f0a5c5c:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0a5c60:	0fc27773 */ 	jal	func0f09ddcc
/*  f0a5c64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5c68:	54400003 */ 	bnezl	$v0,.L0f0a5c78
/*  f0a5c6c:	820c0007 */ 	lb	$t4,0x7($s0)
.L0f0a5c70:
/*  f0a5c70:	a2000007 */ 	sb	$zero,0x7($s0)
.L0f0a5c74:
/*  f0a5c74:	820c0007 */ 	lb	$t4,0x7($s0)
.L0f0a5c78:
/*  f0a5c78:	11800031 */ 	beqz	$t4,.L0f0a5d40
/*  f0a5c7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5c80:	8faa01d8 */ 	lw	$t2,0x1d8($sp)
/*  f0a5c84:	8d421590 */ 	lw	$v0,0x1590($t2)
/*  f0a5c88:	8444000e */ 	lh	$a0,0xe($v0)
/*  f0a5c8c:	afa20280 */ 	sw	$v0,0x280($sp)
/*  f0a5c90:	00045980 */ 	sll	$t3,$a0,0x6
/*  f0a5c94:	0fc59e7d */ 	jal	func0f1679f4
/*  f0a5c98:	01602025 */ 	or	$a0,$t3,$zero
/*  f0a5c9c:	afa20304 */ 	sw	$v0,0x304($sp)
/*  f0a5ca0:	8fa401c4 */ 	lw	$a0,0x1c4($sp)
/*  f0a5ca4:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a5ca8:	3c050200 */ 	lui	$a1,0x200
/*  f0a5cac:	10400012 */ 	beqz	$v0,.L0f0a5cf8
/*  f0a5cb0:	8fb90280 */ 	lw	$t9,0x280($sp)
/*  f0a5cb4:	8738000e */ 	lh	$t8,0xe($t9)
/*  f0a5cb8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a5cbc:	8fa40304 */ 	lw	$a0,0x304($sp)
/*  f0a5cc0:	1b00000d */ 	blez	$t8,.L0f0a5cf8
/*  f0a5cc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5cc8:	afa201c8 */ 	sw	$v0,0x1c8($sp)
.L0f0a5ccc:
/*  f0a5ccc:	0c00566c */ 	jal	func000159b0
/*  f0a5cd0:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f0a5cd4:	8fae0280 */ 	lw	$t6,0x280($sp)
/*  f0a5cd8:	8fa201c8 */ 	lw	$v0,0x1c8($sp)
/*  f0a5cdc:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0a5ce0:	85cf000e */ 	lh	$t7,0xe($t6)
/*  f0a5ce4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0a5ce8:	24840040 */ 	addiu	$a0,$a0,0x40
/*  f0a5cec:	004f082a */ 	slt	$at,$v0,$t7
/*  f0a5cf0:	5420fff6 */ 	bnezl	$at,.L0f0a5ccc
/*  f0a5cf4:	afa201c8 */ 	sw	$v0,0x1c8($sp)
.L0f0a5cf8:
/*  f0a5cf8:	0fc28b6a */ 	jal	func0f0a2da8
/*  f0a5cfc:	8e040794 */ 	lw	$a0,0x794($s0)
/*  f0a5d00:	8fa901d8 */ 	lw	$t1,0x1d8($sp)
/*  f0a5d04:	8d2d1594 */ 	lw	$t5,0x1594($t1)
/*  f0a5d08:	51a00004 */ 	beqzl	$t5,.L0f0a5d1c
/*  f0a5d0c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a5d10:	0fc28b6a */ 	jal	func0f0a2da8
/*  f0a5d14:	8e040798 */ 	lw	$a0,0x798($s0)
/*  f0a5d18:	02002025 */ 	or	$a0,$s0,$zero
.L0f0a5d1c:
/*  f0a5d1c:	0fc2600c */ 	jal	func0f098030
/*  f0a5d20:	8fa50280 */ 	lw	$a1,0x280($sp)
/*  f0a5d24:	8fa401c4 */ 	lw	$a0,0x1c4($sp)
/*  f0a5d28:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a5d2c:	24052000 */ 	addiu	$a1,$zero,0x2000
/*  f0a5d30:	10400003 */ 	beqz	$v0,.L0f0a5d40
/*  f0a5d34:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a5d38:	0fc2607a */ 	jal	func0f0981e8
/*  f0a5d3c:	8fa50280 */ 	lw	$a1,0x280($sp)
.L0f0a5d40:
/*  f0a5d40:	0c00566c */ 	jal	func000159b0
/*  f0a5d44:	27a40234 */ 	addiu	$a0,$sp,0x234
/*  f0a5d48:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0a5d4c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0a5d50:	8d0c006c */ 	lw	$t4,0x6c($t0)
/*  f0a5d54:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a5d58:	51800004 */ 	beqzl	$t4,.L0f0a5d6c
/*  f0a5d5c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a5d60:	10000002 */ 	beqz	$zero,.L0f0a5d6c
/*  f0a5d64:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a5d68:	00002825 */ 	or	$a1,$zero,$zero
.L0f0a5d6c:
/*  f0a5d6c:	8d0a0068 */ 	lw	$t2,0x68($t0)
/*  f0a5d70:	51400004 */ 	beqzl	$t2,.L0f0a5d84
/*  f0a5d74:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a5d78:	10000002 */ 	beqz	$zero,.L0f0a5d84
/*  f0a5d7c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a5d80:	00002025 */ 	or	$a0,$zero,$zero
.L0f0a5d84:
/*  f0a5d84:	8d0b0064 */ 	lw	$t3,0x64($t0)
/*  f0a5d88:	51600004 */ 	beqzl	$t3,.L0f0a5d9c
/*  f0a5d8c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a5d90:	10000002 */ 	beqz	$zero,.L0f0a5d9c
/*  f0a5d94:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a5d98:	00001825 */ 	or	$v1,$zero,$zero
.L0f0a5d9c:
/*  f0a5d9c:	8d190070 */ 	lw	$t9,0x70($t0)
/*  f0a5da0:	53200004 */ 	beqzl	$t9,.L0f0a5db4
/*  f0a5da4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a5da8:	10000002 */ 	beqz	$zero,.L0f0a5db4
/*  f0a5dac:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a5db0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a5db4:
/*  f0a5db4:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f0a5db8:	03047021 */ 	addu	$t6,$t8,$a0
/*  f0a5dbc:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0a5dc0:	15e10012 */ 	bne	$t7,$at,.L0f0a5e0c
/*  f0a5dc4:	3c098009 */ 	lui	$t1,0x8009
/*  f0a5dc8:	91290af0 */ 	lbu	$t1,0xaf0($t1)
/*  f0a5dcc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a5dd0:	8fa401c4 */ 	lw	$a0,0x1c4($sp)
/*  f0a5dd4:	5121000e */ 	beql	$t1,$at,.L0f0a5e10
/*  f0a5dd8:	8e0a00b4 */ 	lw	$t2,0xb4($s0)
/*  f0a5ddc:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a5de0:	3c050008 */ 	lui	$a1,0x8
/*  f0a5de4:	10400009 */ 	beqz	$v0,.L0f0a5e0c
/*  f0a5de8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a5dec:	27ad0284 */ 	addiu	$t5,$sp,0x284
/*  f0a5df0:	27ac0234 */ 	addiu	$t4,$sp,0x234
/*  f0a5df4:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0a5df8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0a5dfc:	8fa50308 */ 	lw	$a1,0x308($sp)
/*  f0a5e00:	27a60274 */ 	addiu	$a2,$sp,0x274
/*  f0a5e04:	0fc28c58 */ 	jal	func0f0a3160
/*  f0a5e08:	8fa701d0 */ 	lw	$a3,0x1d0($sp)
.L0f0a5e0c:
/*  f0a5e0c:	8e0a00b4 */ 	lw	$t2,0xb4($s0)
.L0f0a5e10:
/*  f0a5e10:	51400017 */ 	beqzl	$t2,.L0f0a5e70
/*  f0a5e14:	44800000 */ 	mtc1	$zero,$f0
/*  f0a5e18:	c7b20274 */ 	lwc1	$f18,0x274($sp)
/*  f0a5e1c:	c61000a4 */ 	lwc1	$f16,0xa4($s0)
/*  f0a5e20:	c7a60278 */ 	lwc1	$f6,0x278($sp)
/*  f0a5e24:	26040074 */ 	addiu	$a0,$s0,0x74
/*  f0a5e28:	46109100 */ 	add.s	$f4,$f18,$f16
/*  f0a5e2c:	c7b2027c */ 	lwc1	$f18,0x27c($sp)
/*  f0a5e30:	27a50234 */ 	addiu	$a1,$sp,0x234
/*  f0a5e34:	e7a40274 */ 	swc1	$f4,0x274($sp)
/*  f0a5e38:	c60800a8 */ 	lwc1	$f8,0xa8($s0)
/*  f0a5e3c:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0a5e40:	e7aa0278 */ 	swc1	$f10,0x278($sp)
/*  f0a5e44:	c61000ac */ 	lwc1	$f16,0xac($s0)
/*  f0a5e48:	46109100 */ 	add.s	$f4,$f18,$f16
/*  f0a5e4c:	0c0056f8 */ 	jal	func00015be0
/*  f0a5e50:	e7a4027c */ 	swc1	$f4,0x27c($sp)
/*  f0a5e54:	44800000 */ 	mtc1	$zero,$f0
/*  f0a5e58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5e5c:	e7a00264 */ 	swc1	$f0,0x264($sp)
/*  f0a5e60:	e7a00268 */ 	swc1	$f0,0x268($sp)
/*  f0a5e64:	10000007 */ 	beqz	$zero,.L0f0a5e84
/*  f0a5e68:	e7a0026c */ 	swc1	$f0,0x26c($sp)
/*  f0a5e6c:	44800000 */ 	mtc1	$zero,$f0
.L0f0a5e70:
/*  f0a5e70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5e74:	e6000070 */ 	swc1	$f0,0x70($s0)
/*  f0a5e78:	e6000064 */ 	swc1	$f0,0x64($s0)
/*  f0a5e7c:	e6000068 */ 	swc1	$f0,0x68($s0)
/*  f0a5e80:	e600006c */ 	swc1	$f0,0x6c($s0)
.L0f0a5e84:
/*  f0a5e84:	c60600c4 */ 	lwc1	$f6,0xc4($s0)
/*  f0a5e88:	44050000 */ 	mfc1	$a1,$f0
/*  f0a5e8c:	44060000 */ 	mfc1	$a2,$f0
/*  f0a5e90:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f0a5e94:	c60800c8 */ 	lwc1	$f8,0xc8($s0)
/*  f0a5e98:	44070000 */ 	mfc1	$a3,$f0
/*  f0a5e9c:	27a40284 */ 	addiu	$a0,$sp,0x284
/*  f0a5ea0:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0a5ea4:	c60a00cc */ 	lwc1	$f10,0xcc($s0)
/*  f0a5ea8:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*  f0a5eac:	c61200d0 */ 	lwc1	$f18,0xd0($s0)
/*  f0a5eb0:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f0a5eb4:	c61000d4 */ 	lwc1	$f16,0xd4($s0)
/*  f0a5eb8:	e7b00020 */ 	swc1	$f16,0x20($sp)
/*  f0a5ebc:	c60400d8 */ 	lwc1	$f4,0xd8($s0)
/*  f0a5ec0:	0c005b56 */ 	jal	func00016d58
/*  f0a5ec4:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*  f0a5ec8:	27a40284 */ 	addiu	$a0,$sp,0x284
/*  f0a5ecc:	0c0056f8 */ 	jal	func00015be0
/*  f0a5ed0:	27a50234 */ 	addiu	$a1,$sp,0x234
/*  f0a5ed4:	44800000 */ 	mtc1	$zero,$f0
/*  f0a5ed8:	3c017f1b */ 	lui	$at,%hi(var7f1ac9e4)
/*  f0a5edc:	c426c9e4 */ 	lwc1	$f6,%lo(var7f1ac9e4)($at)
/*  f0a5ee0:	27a401a4 */ 	addiu	$a0,$sp,0x1a4
/*  f0a5ee4:	27a50164 */ 	addiu	$a1,$sp,0x164
/*  f0a5ee8:	e7a001a4 */ 	swc1	$f0,0x1a4($sp)
/*  f0a5eec:	e7a001ac */ 	swc1	$f0,0x1ac($sp)
/*  f0a5ef0:	0c005923 */ 	jal	func0001648c
/*  f0a5ef4:	e7a601a8 */ 	swc1	$f6,0x1a8($sp)
/*  f0a5ef8:	44804000 */ 	mtc1	$zero,$f8
/*  f0a5efc:	27a40118 */ 	addiu	$a0,$sp,0x118
/*  f0a5f00:	8fa50308 */ 	lw	$a1,0x308($sp)
/*  f0a5f04:	0fc2893c */ 	jal	func0f0a24f0
/*  f0a5f08:	e7a801a8 */ 	swc1	$f8,0x1a8($sp)
/*  f0a5f0c:	c7ac0118 */ 	lwc1	$f12,0x118($sp)
/*  f0a5f10:	c7ae0120 */ 	lwc1	$f14,0x120($sp)
/*  f0a5f14:	8fa60274 */ 	lw	$a2,0x274($sp)
/*  f0a5f18:	0fc28926 */ 	jal	func0f0a2498
/*  f0a5f1c:	8fa7027c */ 	lw	$a3,0x27c($sp)
/*  f0a5f20:	46000287 */ 	neg.s	$f10,$f0
/*  f0a5f24:	c7ac011c */ 	lwc1	$f12,0x11c($sp)
/*  f0a5f28:	e7aa01a8 */ 	swc1	$f10,0x1a8($sp)
/*  f0a5f2c:	c7ae0120 */ 	lwc1	$f14,0x120($sp)
/*  f0a5f30:	8fa60278 */ 	lw	$a2,0x278($sp)
/*  f0a5f34:	0fc28926 */ 	jal	func0f0a2498
/*  f0a5f38:	8fa7027c */ 	lw	$a3,0x27c($sp)
/*  f0a5f3c:	e7a001a4 */ 	swc1	$f0,0x1a4($sp)
/*  f0a5f40:	c7b201a4 */ 	lwc1	$f18,0x1a4($sp)
/*  f0a5f44:	27a401a4 */ 	addiu	$a0,$sp,0x1a4
/*  f0a5f48:	27a50124 */ 	addiu	$a1,$sp,0x124
/*  f0a5f4c:	e6120234 */ 	swc1	$f18,0x234($s0)
/*  f0a5f50:	c7b001a8 */ 	lwc1	$f16,0x1a8($sp)
/*  f0a5f54:	0c005923 */ 	jal	func0001648c
/*  f0a5f58:	e6100238 */ 	swc1	$f16,0x238($s0)
/*  f0a5f5c:	27a40124 */ 	addiu	$a0,$sp,0x124
/*  f0a5f60:	27a50164 */ 	addiu	$a1,$sp,0x164
/*  f0a5f64:	0c005680 */ 	jal	0x15a00
/*  f0a5f68:	27a60284 */ 	addiu	$a2,$sp,0x284
/*  f0a5f6c:	27a40284 */ 	addiu	$a0,$sp,0x284
/*  f0a5f70:	0c00567f */ 	jal	func000159fc
/*  f0a5f74:	27a50234 */ 	addiu	$a1,$sp,0x234
/*  f0a5f78:	27a40234 */ 	addiu	$a0,$sp,0x234
/*  f0a5f7c:	0c005746 */ 	jal	func00015d18
/*  f0a5f80:	27a502c4 */ 	addiu	$a1,$sp,0x2c4
/*  f0a5f84:	27a40274 */ 	addiu	$a0,$sp,0x274
/*  f0a5f88:	0c005775 */ 	jal	func00015dd4
/*  f0a5f8c:	27a502c4 */ 	addiu	$a1,$sp,0x2c4
/*  f0a5f90:	260502b4 */ 	addiu	$a1,$s0,0x2b4
/*  f0a5f94:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f0a5f98:	0c005746 */ 	jal	func00015d18
/*  f0a5f9c:	27a402c4 */ 	addiu	$a0,$sp,0x2c4
/*  f0a5fa0:	260402f4 */ 	addiu	$a0,$s0,0x2f4
/*  f0a5fa4:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f0a5fa8:	0c005746 */ 	jal	func00015d18
/*  f0a5fac:	26050334 */ 	addiu	$a1,$s0,0x334
/*  f0a5fb0:	0fc2d5de */ 	jal	func0f0b5778
/*  f0a5fb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5fb8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a5fbc:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f0a5fc0:	0c0056f9 */ 	jal	func00015be4
/*  f0a5fc4:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0a5fc8:	820b0007 */ 	lb	$t3,0x7($s0)
/*  f0a5fcc:	116001c4 */ 	beqz	$t3,.L0f0a66e0
/*  f0a5fd0:	2405005a */ 	addiu	$a1,$zero,0x5a
/*  f0a5fd4:	8fa40280 */ 	lw	$a0,0x280($sp)
.L0f0a5fd8:
/*  f0a5fd8:	0c006a47 */ 	jal	func0001a91c
/*  f0a5fdc:	afa50114 */ 	sw	$a1,0x114($sp)
/*  f0a5fe0:	1040000c */ 	beqz	$v0,.L0f0a6014
/*  f0a5fe4:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0a5fe8:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f0a5fec:	8fa901e0 */ 	lw	$t1,0x1e0($sp)
/*  f0a5ff0:	94790004 */ 	lhu	$t9,0x4($v1)
/*  f0a5ff4:	00096880 */ 	sll	$t5,$t1,0x2
/*  f0a5ff8:	03ad6021 */ 	addu	$t4,$sp,$t5
/*  f0a5ffc:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f0a6000:	02187021 */ 	addu	$t6,$s0,$t8
/*  f0a6004:	25cf0434 */ 	addiu	$t7,$t6,0x434
/*  f0a6008:	ad8f01e4 */ 	sw	$t7,0x1e4($t4)
/*  f0a600c:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f0a6010:	afaa01e0 */ 	sw	$t2,0x1e0($sp)
.L0f0a6014:
/*  f0a6014:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0a6018:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f0a601c:	54a1ffee */ 	bnel	$a1,$at,.L0f0a5fd8
/*  f0a6020:	8fa40280 */ 	lw	$a0,0x280($sp)
/*  f0a6024:	8fa20304 */ 	lw	$v0,0x304($sp)
/*  f0a6028:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f0a602c:	ae020390 */ 	sw	$v0,0x390($s0)
/*  f0a6030:	ae020540 */ 	sw	$v0,0x540($s0)
/*  f0a6034:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a6038:	8fa401c4 */ 	lw	$a0,0x1c4($sp)
/*  f0a603c:	10400008 */ 	beqz	$v0,.L0f0a6060
/*  f0a6040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6044:	8fab0308 */ 	lw	$t3,0x308($sp)
/*  f0a6048:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a604c:	15610004 */ 	bne	$t3,$at,.L0f0a6060
/*  f0a6050:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a6054:	44816000 */ 	mtc1	$at,$f12
/*  f0a6058:	0c005789 */ 	jal	func00015e24
/*  f0a605c:	27a502c4 */ 	addiu	$a1,$sp,0x2c4
.L0f0a6060:
/*  f0a6060:	3c017f1b */ 	lui	$at,%hi(var7f1ac9e8)
/*  f0a6064:	c42cc9e8 */ 	lwc1	$f12,%lo(var7f1ac9e8)($at)
/*  f0a6068:	0c0057c1 */ 	jal	func00015f04
/*  f0a606c:	27a502c4 */ 	addiu	$a1,$sp,0x2c4
/*  f0a6070:	27a402c4 */ 	addiu	$a0,$sp,0x2c4
/*  f0a6074:	0c005746 */ 	jal	func00015d18
/*  f0a6078:	8fa50304 */ 	lw	$a1,0x304($sp)
/*  f0a607c:	8e190690 */ 	lw	$t9,0x690($s0)
/*  f0a6080:	0019c0c0 */ 	sll	$t8,$t9,0x3
/*  f0a6084:	00187742 */ 	srl	$t6,$t8,0x1d
/*  f0a6088:	19c00018 */ 	blez	$t6,.L0f0a60ec
/*  f0a608c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6090:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*  f0a6094:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f0a6098:	11e1000d */ 	beq	$t7,$at,.L0f0a60d0
/*  f0a609c:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f0a60a0:	11e10003 */ 	beq	$t7,$at,.L0f0a60b0
/*  f0a60a4:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f0a60a8:	15e10010 */ 	bne	$t7,$at,.L0f0a60ec
/*  f0a60ac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a60b0:
/*  f0a60b0:	920d06d6 */ 	lbu	$t5,0x6d6($s0)
/*  f0a60b4:	31acff0f */ 	andi	$t4,$t5,0xff0f
/*  f0a60b8:	358a0010 */ 	ori	$t2,$t4,0x10
/*  f0a60bc:	314b00f1 */ 	andi	$t3,$t2,0xf1
/*  f0a60c0:	a20a06d6 */ 	sb	$t2,0x6d6($s0)
/*  f0a60c4:	35790002 */ 	ori	$t9,$t3,0x2
/*  f0a60c8:	10000008 */ 	beqz	$zero,.L0f0a60ec
/*  f0a60cc:	a21906d6 */ 	sb	$t9,0x6d6($s0)
.L0f0a60d0:
/*  f0a60d0:	921806d6 */ 	lbu	$t8,0x6d6($s0)
/*  f0a60d4:	330eff0f */ 	andi	$t6,$t8,0xff0f
/*  f0a60d8:	35cd0010 */ 	ori	$t5,$t6,0x10
/*  f0a60dc:	31ac00f1 */ 	andi	$t4,$t5,0xf1
/*  f0a60e0:	a20d06d6 */ 	sb	$t5,0x6d6($s0)
/*  f0a60e4:	35890004 */ 	ori	$t1,$t4,0x4
/*  f0a60e8:	a20906d6 */ 	sb	$t1,0x6d6($s0)
.L0f0a60ec:
/*  f0a60ec:	3c01800a */ 	lui	$at,0x800a
/*  f0a60f0:	ac30d144 */ 	sw	$s0,-0x2ebc($at)
/*  f0a60f4:	960a06d6 */ 	lhu	$t2,0x6d6($s0)
/*  f0a60f8:	000a5b02 */ 	srl	$t3,$t2,0xc
/*  f0a60fc:	19600004 */ 	blez	$t3,.L0f0a6110
/*  f0a6100:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a6104:	8fa50280 */ 	lw	$a1,0x280($sp)
/*  f0a6108:	0fc29174 */ 	jal	func0f0a45d0
/*  f0a610c:	8fa601b8 */ 	lw	$a2,0x1b8($sp)
.L0f0a6110:
/*  f0a6110:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0a6114:	3c01800a */ 	lui	$at,0x800a
/*  f0a6118:	8fb901c4 */ 	lw	$t9,0x1c4($sp)
/*  f0a611c:	3c03800a */ 	lui	$v1,%hi(var8009d0f0)
/*  f0a6120:	ac28d0dc */ 	sw	$t0,-0x2f24($at)
/*  f0a6124:	2463d0f0 */ 	addiu	$v1,$v1,%lo(var8009d0f0)
/*  f0a6128:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0a612c:	ac680008 */ 	sw	$t0,0x8($v1)
/*  f0a6130:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f0a6134:	13210008 */ 	beq	$t9,$at,.L0f0a6158
/*  f0a6138:	ac680000 */ 	sw	$t0,0x0($v1)
/*  f0a613c:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f0a6140:	17210009 */ 	bne	$t9,$at,.L0f0a6168
/*  f0a6144:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6148:	0fc290cd */ 	jal	func0f0a4334
/*  f0a614c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a6150:	10000005 */ 	beqz	$zero,.L0f0a6168
/*  f0a6154:	2408ffff */ 	addiu	$t0,$zero,-1
.L0f0a6158:
/*  f0a6158:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a615c:	0fc28ea9 */ 	jal	func0f0a3aa4
/*  f0a6160:	8fa50280 */ 	lw	$a1,0x280($sp)
/*  f0a6164:	2408ffff */ 	addiu	$t0,$zero,-1
.L0f0a6168:
/*  f0a6168:	3c188007 */ 	lui	$t8,%hi(var8007025c)
/*  f0a616c:	27a600d0 */ 	addiu	$a2,$sp,0xd0
/*  f0a6170:	2718025c */ 	addiu	$t8,$t8,%lo(var8007025c)
/*  f0a6174:	27a702c4 */ 	addiu	$a3,$sp,0x2c4
/*  f0a6178:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a617c:	270f003c */ 	addiu	$t7,$t8,0x3c
/*  f0a6180:	00c06825 */ 	or	$t5,$a2,$zero
.L0f0a6184:
/*  f0a6184:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0a6188:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f0a618c:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f0a6190:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f0a6194:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*  f0a6198:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f0a619c:	8f01fffc */ 	lw	$at,-0x4($t8)
/*  f0a61a0:	170ffff8 */ 	bne	$t8,$t7,.L0f0a6184
/*  f0a61a4:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f0a61a8:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0a61ac:	ada10000 */ 	sw	$at,0x0($t5)
/*  f0a61b0:	afa700d0 */ 	sw	$a3,0xd0($sp)
/*  f0a61b4:	8e0c0390 */ 	lw	$t4,0x390($s0)
/*  f0a61b8:	8faa01c4 */ 	lw	$t2,0x1c4($sp)
/*  f0a61bc:	afac00e0 */ 	sw	$t4,0xe0($sp)
/*  f0a61c0:	8e09068c */ 	lw	$t1,0x68c($s0)
/*  f0a61c4:	254bffec */ 	addiu	$t3,$t2,-20
/*  f0a61c8:	2d610022 */ 	sltiu	$at,$t3,0x22
/*  f0a61cc:	11200002 */ 	beqz	$t1,.L0f0a61d8
/*  f0a61d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a61d4:	00002025 */ 	or	$a0,$zero,$zero
.L0f0a61d8:
/*  f0a61d8:	1020001e */ 	beqz	$at,.L0f0a6254
/*  f0a61dc:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0a61e0:	3c017f1b */ 	lui	$at,%hi(var7f1ac9ec)
/*  f0a61e4:	002b0821 */ 	addu	$at,$at,$t3
/*  f0a61e8:	8c2bc9ec */ 	lw	$t3,%lo(var7f1ac9ec)($at)
/*  f0a61ec:	01600008 */ 	jr	$t3
/*  f0a61f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a61f4:	10000017 */ 	beqz	$zero,.L0f0a6254
/*  f0a61f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a61fc:	8fb901d8 */ 	lw	$t9,0x1d8($sp)
/*  f0a6200:	8f2e0ffc */ 	lw	$t6,0xffc($t9)
/*  f0a6204:	55c00003 */ 	bnezl	$t6,.L0f0a6214
/*  f0a6208:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f0a620c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a6210:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
.L0f0a6214:
/*  f0a6214:	8fad01d8 */ 	lw	$t5,0x1d8($sp)
/*  f0a6218:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f0a621c:	8df80858 */ 	lw	$t8,0x858($t7)
/*  f0a6220:	01ac4821 */ 	addu	$t1,$t5,$t4
/*  f0a6224:	57000003 */ 	bnezl	$t8,.L0f0a6234
/*  f0a6228:	8d220c3c */ 	lw	$v0,0xc3c($t1)
/*  f0a622c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a6230:	8d220c3c */ 	lw	$v0,0xc3c($t1)
.L0f0a6234:
/*  f0a6234:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0a6238:	54410003 */ 	bnel	$v0,$at,.L0f0a6248
/*  f0a623c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0a6240:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a6244:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0a6248:
/*  f0a6248:	54410003 */ 	bnel	$v0,$at,.L0f0a6258
/*  f0a624c:	8faa01d8 */ 	lw	$t2,0x1d8($sp)
/*  f0a6250:	00002025 */ 	or	$a0,$zero,$zero
.L0f0a6254:
/*  f0a6254:	8faa01d8 */ 	lw	$t2,0x1d8($sp)
.L0f0a6258:
/*  f0a6258:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f0a625c:	961906d6 */ 	lhu	$t9,0x6d6($s0)
/*  f0a6260:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0a6264:	014b1821 */ 	addu	$v1,$t2,$t3
/*  f0a6268:	00197302 */ 	srl	$t6,$t9,0xc
/*  f0a626c:	11c00002 */ 	beqz	$t6,.L0f0a6278
/*  f0a6270:	8c620c3c */ 	lw	$v0,0xc3c($v1)
/*  f0a6274:	00002025 */ 	or	$a0,$zero,$zero
.L0f0a6278:
/*  f0a6278:	1441000a */ 	bne	$v0,$at,.L0f0a62a4
/*  f0a627c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6280:	8c6f0c40 */ 	lw	$t7,0xc40($v1)
/*  f0a6284:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f0a6288:	29e10002 */ 	slti	$at,$t7,0x2
/*  f0a628c:	10200005 */ 	beqz	$at,.L0f0a62a4
/*  f0a6290:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6294:	8f0d0008 */ 	lw	$t5,0x8($t8)
/*  f0a6298:	11a00002 */ 	beqz	$t5,.L0f0a62a4
/*  f0a629c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a62a0:	00002025 */ 	or	$a0,$zero,$zero
.L0f0a62a4:
/*  f0a62a4:	10800030 */ 	beqz	$a0,.L0f0a6368
/*  f0a62a8:	26050384 */ 	addiu	$a1,$s0,0x384
/*  f0a62ac:	8fac01d8 */ 	lw	$t4,0x1d8($sp)
/*  f0a62b0:	8d890dd4 */ 	lw	$t1,0xdd4($t4)
/*  f0a62b4:	55090013 */ 	bnel	$t0,$t1,.L0f0a6304
/*  f0a62b8:	8e0d038c */ 	lw	$t5,0x38c($s0)
/*  f0a62bc:	0c00566c */ 	jal	func000159b0
/*  f0a62c0:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0a62c4:	8fab01d8 */ 	lw	$t3,0x1d8($sp)
/*  f0a62c8:	8e060390 */ 	lw	$a2,0x390($s0)
/*  f0a62cc:	27aa0084 */ 	addiu	$t2,$sp,0x84
/*  f0a62d0:	afaa00d0 */ 	sw	$t2,0xd0($sp)
/*  f0a62d4:	8d790dd8 */ 	lw	$t9,0xdd8($t3)
/*  f0a62d8:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0a62dc:	26050384 */ 	addiu	$a1,$s0,0x384
/*  f0a62e0:	afa600c4 */ 	sw	$a2,0xc4($sp)
/*  f0a62e4:	0c0073af */ 	jal	func0001cebc
/*  f0a62e8:	afb900e0 */ 	sw	$t9,0xe0($sp)
/*  f0a62ec:	8faf01d8 */ 	lw	$t7,0x1d8($sp)
/*  f0a62f0:	8fa600c4 */ 	lw	$a2,0xc4($sp)
/*  f0a62f4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0a62f8:	adee0dd4 */ 	sw	$t6,0xdd4($t7)
/*  f0a62fc:	ae060390 */ 	sw	$a2,0x390($s0)
/*  f0a6300:	8e0d038c */ 	lw	$t5,0x38c($s0)
.L0f0a6304:
/*  f0a6304:	8fb801d8 */ 	lw	$t8,0x1d8($sp)
/*  f0a6308:	8e060390 */ 	lw	$a2,0x390($s0)
/*  f0a630c:	85ac000e */ 	lh	$t4,0xe($t5)
/*  f0a6310:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a6314:	8f050dd8 */ 	lw	$a1,0xdd8($t8)
/*  f0a6318:	19800015 */ 	blez	$t4,.L0f0a6370
/*  f0a631c:	27a402c4 */ 	addiu	$a0,$sp,0x2c4
.L0f0a6320:
/*  f0a6320:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0a6324:	afa500c8 */ 	sw	$a1,0xc8($sp)
/*  f0a6328:	0c0056f9 */ 	jal	func00015be4
/*  f0a632c:	afa600c4 */ 	sw	$a2,0xc4($sp)
/*  f0a6330:	8fa901d4 */ 	lw	$t1,0x1d4($sp)
/*  f0a6334:	8fa200cc */ 	lw	$v0,0xcc($sp)
/*  f0a6338:	8fa500c8 */ 	lw	$a1,0xc8($sp)
/*  f0a633c:	8d2a038c */ 	lw	$t2,0x38c($t1)
/*  f0a6340:	8fa600c4 */ 	lw	$a2,0xc4($sp)
/*  f0a6344:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0a6348:	854b000e */ 	lh	$t3,0xe($t2)
/*  f0a634c:	24a50040 */ 	addiu	$a1,$a1,0x40
/*  f0a6350:	24c60040 */ 	addiu	$a2,$a2,0x40
/*  f0a6354:	004b082a */ 	slt	$at,$v0,$t3
/*  f0a6358:	5420fff1 */ 	bnezl	$at,.L0f0a6320
/*  f0a635c:	27a402c4 */ 	addiu	$a0,$sp,0x2c4
/*  f0a6360:	10000003 */ 	beqz	$zero,.L0f0a6370
/*  f0a6364:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a6368:
/*  f0a6368:	0c0073af */ 	jal	func0001cebc
/*  f0a636c:	00c02025 */ 	or	$a0,$a2,$zero
.L0f0a6370:
/*  f0a6370:	3c018006 */ 	lui	$at,0x8006
/*  f0a6374:	ac20efcc */ 	sw	$zero,-0x1034($at)
/*  f0a6378:	8fa40280 */ 	lw	$a0,0x280($sp)
/*  f0a637c:	0c006a47 */ 	jal	func0001a91c
/*  f0a6380:	24050033 */ 	addiu	$a1,$zero,0x33
/*  f0a6384:	10400020 */ 	beqz	$v0,.L0f0a6408
/*  f0a6388:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a638c:	0c006949 */ 	jal	func0001a524
/*  f0a6390:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a6394:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f0a6398:	0fc288cf */ 	jal	func0f0a233c
/*  f0a639c:	8fa40308 */ 	lw	$a0,0x308($sp)
/*  f0a63a0:	44800000 */ 	mtc1	$zero,$f0
/*  f0a63a4:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f0a63a8:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f0a63ac:	e7a00074 */ 	swc1	$f0,0x74($sp)
/*  f0a63b0:	e7a00078 */ 	swc1	$f0,0x78($sp)
/*  f0a63b4:	c6040210 */ 	lwc1	$f4,0x210($s0)
/*  f0a63b8:	000e7980 */ 	sll	$t7,$t6,0x6
/*  f0a63bc:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f0a63c0:	46002187 */ 	neg.s	$f6,$f4
/*  f0a63c4:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0a63c8:	e7a6007c */ 	swc1	$f6,0x7c($sp)
/*  f0a63cc:	0c0056c4 */ 	jal	func00015b10
/*  f0a63d0:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f0a63d4:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0a63d8:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f0a63dc:	c4880030 */ 	lwc1	$f8,0x30($a0)
/*  f0a63e0:	c4900034 */ 	lwc1	$f16,0x34($a0)
/*  f0a63e4:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f0a63e8:	c4880038 */ 	lwc1	$f8,0x38($a0)
/*  f0a63ec:	e4920030 */ 	swc1	$f18,0x30($a0)
/*  f0a63f0:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f0a63f4:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f0a63f8:	e4860034 */ 	swc1	$f6,0x34($a0)
/*  f0a63fc:	c7aa007c */ 	lwc1	$f10,0x7c($sp)
/*  f0a6400:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f0a6404:	e4920038 */ 	swc1	$f18,0x38($a0)
.L0f0a6408:
/*  f0a6408:	8fb801e4 */ 	lw	$t8,0x1e4($sp)
/*  f0a640c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a6410:	53000003 */ 	beqzl	$t8,.L0f0a6420
/*  f0a6414:	8fad01e8 */ 	lw	$t5,0x1e8($sp)
/*  f0a6418:	af000000 */ 	sw	$zero,0x0($t8)
/*  f0a641c:	8fad01e8 */ 	lw	$t5,0x1e8($sp)
.L0f0a6420:
/*  f0a6420:	51a00003 */ 	beqzl	$t5,.L0f0a6430
/*  f0a6424:	8fac01ec */ 	lw	$t4,0x1ec($sp)
/*  f0a6428:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f0a642c:	8fac01ec */ 	lw	$t4,0x1ec($sp)
.L0f0a6430:
/*  f0a6430:	51800003 */ 	beqzl	$t4,.L0f0a6440
/*  f0a6434:	8fa901c4 */ 	lw	$t1,0x1c4($sp)
/*  f0a6438:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f0a643c:	8fa901c4 */ 	lw	$t1,0x1c4($sp)
.L0f0a6440:
/*  f0a6440:	24010013 */ 	addiu	$at,$zero,0x13
/*  f0a6444:	8fa50304 */ 	lw	$a1,0x304($sp)
/*  f0a6448:	11210012 */ 	beq	$t1,$at,.L0f0a6494
/*  f0a644c:	8fa601e4 */ 	lw	$a2,0x1e4($sp)
/*  f0a6450:	24010015 */ 	addiu	$at,$zero,0x15
/*  f0a6454:	11210006 */ 	beq	$t1,$at,.L0f0a6470
/*  f0a6458:	8fa40280 */ 	lw	$a0,0x280($sp)
/*  f0a645c:	24010017 */ 	addiu	$at,$zero,0x17
/*  f0a6460:	11210007 */ 	beq	$t1,$at,.L0f0a6480
/*  f0a6464:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a6468:	1000000d */ 	beqz	$zero,.L0f0a64a0
/*  f0a646c:	8fa40280 */ 	lw	$a0,0x280($sp)
.L0f0a6470:
/*  f0a6470:	0fc28fab */ 	jal	func0f0a3eac
/*  f0a6474:	8fa50304 */ 	lw	$a1,0x304($sp)
/*  f0a6478:	10000009 */ 	beqz	$zero,.L0f0a64a0
/*  f0a647c:	8fa40280 */ 	lw	$a0,0x280($sp)
.L0f0a6480:
/*  f0a6480:	8fa50304 */ 	lw	$a1,0x304($sp)
/*  f0a6484:	0fc29025 */ 	jal	func0f0a4094
/*  f0a6488:	8fa60280 */ 	lw	$a2,0x280($sp)
/*  f0a648c:	10000004 */ 	beqz	$zero,.L0f0a64a0
/*  f0a6490:	8fa40280 */ 	lw	$a0,0x280($sp)
.L0f0a6494:
/*  f0a6494:	0fc29067 */ 	jal	func0f0a419c
/*  f0a6498:	8fa70280 */ 	lw	$a3,0x280($sp)
/*  f0a649c:	8fa40280 */ 	lw	$a0,0x280($sp)
.L0f0a64a0:
/*  f0a64a0:	0c006a47 */ 	jal	func0001a91c
/*  f0a64a4:	24050032 */ 	addiu	$a1,$zero,0x32
/*  f0a64a8:	8faa01c4 */ 	lw	$t2,0x1c4($sp)
/*  f0a64ac:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0a64b0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a64b4:	1541001b */ 	bne	$t2,$at,.L0f0a6524
/*  f0a64b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a64bc:	820b0005 */ 	lb	$t3,0x5($s0)
/*  f0a64c0:	55600006 */ 	bnezl	$t3,.L0f0a64dc
/*  f0a64c4:	8e050558 */ 	lw	$a1,0x558($s0)
/*  f0a64c8:	820e0004 */ 	lb	$t6,0x4($s0)
/*  f0a64cc:	3c05800a */ 	lui	$a1,0x800a
/*  f0a64d0:	11c0000b */ 	beqz	$t6,.L0f0a6500
/*  f0a64d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a64d8:	8e050558 */ 	lw	$a1,0x558($s0)
.L0f0a64dc:
/*  f0a64dc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0a64e0:	8fa40280 */ 	lw	$a0,0x280($sp)
/*  f0a64e4:	00a1001a */ 	div	$zero,$a1,$at
/*  f0a64e8:	0000c810 */ 	mfhi	$t9
/*  f0a64ec:	2725001e */ 	addiu	$a1,$t9,0x1e
/*  f0a64f0:	0c006a47 */ 	jal	func0001a91c
/*  f0a64f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a64f8:	1000000a */ 	beqz	$zero,.L0f0a6524
/*  f0a64fc:	00402025 */ 	or	$a0,$v0,$zero
.L0f0a6500:
/*  f0a6500:	8ca59fcc */ 	lw	$a1,-0x6034($a1)
/*  f0a6504:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0a6508:	8fa40280 */ 	lw	$a0,0x280($sp)
/*  f0a650c:	00a1001a */ 	div	$zero,$a1,$at
/*  f0a6510:	00007810 */ 	mfhi	$t7
/*  f0a6514:	25e5001e */ 	addiu	$a1,$t7,0x1e
/*  f0a6518:	0c006a47 */ 	jal	func0001a91c
/*  f0a651c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6520:	00402025 */ 	or	$a0,$v0,$zero
.L0f0a6524:
/*  f0a6524:	10400038 */ 	beqz	$v0,.L0f0a6608
/*  f0a6528:	8faa01c4 */ 	lw	$t2,0x1c4($sp)
/*  f0a652c:	0c006949 */ 	jal	func0001a524
/*  f0a6530:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a6534:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f0a6538:	00026980 */ 	sll	$t5,$v0,0x6
/*  f0a653c:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f0a6540:	030d2021 */ 	addu	$a0,$t8,$t5
/*  f0a6544:	c4900030 */ 	lwc1	$f16,0x30($a0)
/*  f0a6548:	26050620 */ 	addiu	$a1,$s0,0x620
/*  f0a654c:	e6100374 */ 	swc1	$f16,0x374($s0)
/*  f0a6550:	c4840034 */ 	lwc1	$f4,0x34($a0)
/*  f0a6554:	e6040378 */ 	swc1	$f4,0x378($s0)
/*  f0a6558:	c4860038 */ 	lwc1	$f6,0x38($a0)
/*  f0a655c:	0c005746 */ 	jal	func00015d18
/*  f0a6560:	e606037c */ 	swc1	$f6,0x37c($s0)
/*  f0a6564:	0fc2d5de */ 	jal	func0f0b5778
/*  f0a6568:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a656c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a6570:	0c0056d9 */ 	jal	func00015b64
/*  f0a6574:	26050374 */ 	addiu	$a1,$s0,0x374
/*  f0a6578:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*  f0a657c:	8fac0304 */ 	lw	$t4,0x304($sp)
/*  f0a6580:	820b0005 */ 	lb	$t3,0x5($s0)
/*  f0a6584:	00024980 */ 	sll	$t1,$v0,0x6
/*  f0a6588:	01895021 */ 	addu	$t2,$t4,$t1
/*  f0a658c:	c5480038 */ 	lwc1	$f8,0x38($t2)
/*  f0a6590:	46004287 */ 	neg.s	$f10,$f8
/*  f0a6594:	1160005e */ 	beqz	$t3,.L0f0a6710
/*  f0a6598:	e60a0380 */ 	swc1	$f10,0x380($s0)
/*  f0a659c:	8fae01e0 */ 	lw	$t6,0x1e0($sp)
/*  f0a65a0:	8fb901c4 */ 	lw	$t9,0x1c4($sp)
/*  f0a65a4:	24010013 */ 	addiu	$at,$zero,0x13
/*  f0a65a8:	59c0005a */ 	blezl	$t6,.L0f0a6714
/*  f0a65ac:	8fac01c4 */ 	lw	$t4,0x1c4($sp)
/*  f0a65b0:	13210057 */ 	beq	$t9,$at,.L0f0a6710
/*  f0a65b4:	3c0f800a */ 	lui	$t7,0x800a
/*  f0a65b8:	8def9ff4 */ 	lw	$t7,-0x600c($t7)
/*  f0a65bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a65c0:	8fa501c0 */ 	lw	$a1,0x1c0($sp)
/*  f0a65c4:	11e00052 */ 	beqz	$t7,.L0f0a6710
/*  f0a65c8:	8fa60280 */ 	lw	$a2,0x280($sp)
/*  f0a65cc:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f0a65d0:	27ad01e4 */ 	addiu	$t5,$sp,0x1e4
/*  f0a65d4:	27ac0234 */ 	addiu	$t4,$sp,0x234
/*  f0a65d8:	27a901f4 */ 	addiu	$t1,$sp,0x1f4
/*  f0a65dc:	afa90028 */ 	sw	$t1,0x28($sp)
/*  f0a65e0:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f0a65e4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0a65e8:	8fa701d0 */ 	lw	$a3,0x1d0($sp)
/*  f0a65ec:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0a65f0:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0a65f4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0a65f8:	0fc29391 */ 	jal	func0f0a4e44
/*  f0a65fc:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0a6600:	10000044 */ 	beqz	$zero,.L0f0a6714
/*  f0a6604:	8fac01c4 */ 	lw	$t4,0x1c4($sp)
.L0f0a6608:
/*  f0a6608:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f0a660c:	1141000a */ 	beq	$t2,$at,.L0f0a6638
/*  f0a6610:	8fa40280 */ 	lw	$a0,0x280($sp)
/*  f0a6614:	24010020 */ 	addiu	$at,$zero,0x20
/*  f0a6618:	11410007 */ 	beq	$t2,$at,.L0f0a6638
/*  f0a661c:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0a6620:	11410005 */ 	beq	$t2,$at,.L0f0a6638
/*  f0a6624:	24010021 */ 	addiu	$at,$zero,0x21
/*  f0a6628:	11410003 */ 	beq	$t2,$at,.L0f0a6638
/*  f0a662c:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f0a6630:	1541001f */ 	bne	$t2,$at,.L0f0a66b0
/*  f0a6634:	26050620 */ 	addiu	$a1,$s0,0x620
.L0f0a6638:
/*  f0a6638:	0c006a47 */ 	jal	func0001a91c
/*  f0a663c:	24050037 */ 	addiu	$a1,$zero,0x37
/*  f0a6640:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a6644:	0c006949 */ 	jal	func0001a524
/*  f0a6648:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a664c:	8fab0304 */ 	lw	$t3,0x304($sp)
/*  f0a6650:	00027980 */ 	sll	$t7,$v0,0x6
/*  f0a6654:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f0a6658:	016f2021 */ 	addu	$a0,$t3,$t7
/*  f0a665c:	c4920030 */ 	lwc1	$f18,0x30($a0)
/*  f0a6660:	26050620 */ 	addiu	$a1,$s0,0x620
/*  f0a6664:	e6120374 */ 	swc1	$f18,0x374($s0)
/*  f0a6668:	c4900034 */ 	lwc1	$f16,0x34($a0)
/*  f0a666c:	e6100378 */ 	swc1	$f16,0x378($s0)
/*  f0a6670:	c4840038 */ 	lwc1	$f4,0x38($a0)
/*  f0a6674:	0c005746 */ 	jal	func00015d18
/*  f0a6678:	e604037c */ 	swc1	$f4,0x37c($s0)
/*  f0a667c:	0fc2d5de */ 	jal	func0f0b5778
/*  f0a6680:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6684:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a6688:	0c0056d9 */ 	jal	func00015b64
/*  f0a668c:	26050374 */ 	addiu	$a1,$s0,0x374
/*  f0a6690:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f0a6694:	8fae0304 */ 	lw	$t6,0x304($sp)
/*  f0a6698:	0018c980 */ 	sll	$t9,$t8,0x6
/*  f0a669c:	01d96821 */ 	addu	$t5,$t6,$t9
/*  f0a66a0:	c5a60038 */ 	lwc1	$f6,0x38($t5)
/*  f0a66a4:	46003207 */ 	neg.s	$f8,$f6
/*  f0a66a8:	10000019 */ 	beqz	$zero,.L0f0a6710
/*  f0a66ac:	e6080380 */ 	swc1	$f8,0x380($s0)
.L0f0a66b0:
/*  f0a66b0:	c60a0324 */ 	lwc1	$f10,0x324($s0)
/*  f0a66b4:	c6120328 */ 	lwc1	$f18,0x328($s0)
/*  f0a66b8:	c610032c */ 	lwc1	$f16,0x32c($s0)
/*  f0a66bc:	e60a0374 */ 	swc1	$f10,0x374($s0)
/*  f0a66c0:	e6120378 */ 	swc1	$f18,0x378($s0)
/*  f0a66c4:	e610037c */ 	swc1	$f16,0x37c($s0)
/*  f0a66c8:	0c005746 */ 	jal	func00015d18
/*  f0a66cc:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0a66d0:	c60402ec */ 	lwc1	$f4,0x2ec($s0)
/*  f0a66d4:	46002187 */ 	neg.s	$f6,$f4
/*  f0a66d8:	1000000d */ 	beqz	$zero,.L0f0a6710
/*  f0a66dc:	e6060380 */ 	swc1	$f6,0x380($s0)
.L0f0a66e0:
/*  f0a66e0:	c6080324 */ 	lwc1	$f8,0x324($s0)
/*  f0a66e4:	c60a0328 */ 	lwc1	$f10,0x328($s0)
/*  f0a66e8:	c612032c */ 	lwc1	$f18,0x32c($s0)
/*  f0a66ec:	e6080374 */ 	swc1	$f8,0x374($s0)
/*  f0a66f0:	e60a0378 */ 	swc1	$f10,0x378($s0)
/*  f0a66f4:	e612037c */ 	swc1	$f18,0x37c($s0)
/*  f0a66f8:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0a66fc:	0c005746 */ 	jal	func00015d18
/*  f0a6700:	26050620 */ 	addiu	$a1,$s0,0x620
/*  f0a6704:	c61002ec */ 	lwc1	$f16,0x2ec($s0)
/*  f0a6708:	46008107 */ 	neg.s	$f4,$f16
/*  f0a670c:	e6040380 */ 	swc1	$f4,0x380($s0)
.L0f0a6710:
/*  f0a6710:	8fac01c4 */ 	lw	$t4,0x1c4($sp)
.L0f0a6714:
/*  f0a6714:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0a6718:	1181000a */ 	beq	$t4,$at,.L0f0a6744
/*  f0a671c:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0a6720:	11810008 */ 	beq	$t4,$at,.L0f0a6744
/*  f0a6724:	24010018 */ 	addiu	$at,$zero,0x18
/*  f0a6728:	1581000f */ 	bne	$t4,$at,.L0f0a6768
/*  f0a672c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a6730:	8fa50308 */ 	lw	$a1,0x308($sp)
/*  f0a6734:	0fc2915c */ 	jal	func0f0a4570
/*  f0a6738:	8fa601d0 */ 	lw	$a2,0x1d0($sp)
/*  f0a673c:	1000000b */ 	beqz	$zero,.L0f0a676c
/*  f0a6740:	820f0004 */ 	lb	$t7,0x4($s0)
.L0f0a6744:
/*  f0a6744:	8e090690 */ 	lw	$t1,0x690($s0)
/*  f0a6748:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a674c:	8fa50308 */ 	lw	$a1,0x308($sp)
/*  f0a6750:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0a6754:	000a5f42 */ 	srl	$t3,$t2,0x1d
/*  f0a6758:	19600003 */ 	blez	$t3,.L0f0a6768
/*  f0a675c:	8fa60280 */ 	lw	$a2,0x280($sp)
/*  f0a6760:	0fc2910e */ 	jal	func0f0a4438
/*  f0a6764:	8fa70304 */ 	lw	$a3,0x304($sp)
.L0f0a6768:
/*  f0a6768:	820f0004 */ 	lb	$t7,0x4($s0)
.L0f0a676c:
/*  f0a676c:	11e0000c */ 	beqz	$t7,.L0f0a67a0
/*  f0a6770:	3c18800a */ 	lui	$t8,0x800a
/*  f0a6774:	8f189ff4 */ 	lw	$t8,-0x600c($t8)
/*  f0a6778:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a677c:	8fa50308 */ 	lw	$a1,0x308($sp)
/*  f0a6780:	13000007 */ 	beqz	$t8,.L0f0a67a0
/*  f0a6784:	8fa601d0 */ 	lw	$a2,0x1d0($sp)
/*  f0a6788:	8fae0280 */ 	lw	$t6,0x280($sp)
/*  f0a678c:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f0a6790:	8fa701c4 */ 	lw	$a3,0x1c4($sp)
/*  f0a6794:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0a6798:	0fc294c0 */ 	jal	func0f0a5300
/*  f0a679c:	afb90014 */ 	sw	$t9,0x14($sp)
.L0f0a67a0:
/*  f0a67a0:	3c0d800a */ 	lui	$t5,0x800a
/*  f0a67a4:	8dada02c */ 	lw	$t5,-0x5fd4($t5)
/*  f0a67a8:	3c0c800a */ 	lui	$t4,0x800a
/*  f0a67ac:	3c09800a */ 	lui	$t1,0x800a
/*  f0a67b0:	11a00003 */ 	beqz	$t5,.L0f0a67c0
/*  f0a67b4:	3c0a800a */ 	lui	$t2,0x800a
/*  f0a67b8:	10000002 */ 	beqz	$zero,.L0f0a67c4
/*  f0a67bc:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0a67c0:
/*  f0a67c0:	00002825 */ 	or	$a1,$zero,$zero
.L0f0a67c4:
/*  f0a67c4:	8d8ca028 */ 	lw	$t4,-0x5fd8($t4)
/*  f0a67c8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a67cc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a67d0:	11800003 */ 	beqz	$t4,.L0f0a67e0
/*  f0a67d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a67d8:	10000001 */ 	beqz	$zero,.L0f0a67e0
/*  f0a67dc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0a67e0:
/*  f0a67e0:	8d29a024 */ 	lw	$t1,-0x5fdc($t1)
/*  f0a67e4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a67e8:	11200003 */ 	beqz	$t1,.L0f0a67f8
/*  f0a67ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a67f0:	10000001 */ 	beqz	$zero,.L0f0a67f8
/*  f0a67f4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a67f8:
/*  f0a67f8:	8d4aa030 */ 	lw	$t2,-0x5fd0($t2)
/*  f0a67fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a6800:	3c0e8009 */ 	lui	$t6,0x8009
/*  f0a6804:	11400003 */ 	beqz	$t2,.L0f0a6814
/*  f0a6808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a680c:	10000001 */ 	beqz	$zero,.L0f0a6814
/*  f0a6810:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a6814:
/*  f0a6814:	00435821 */ 	addu	$t3,$v0,$v1
/*  f0a6818:	01647821 */ 	addu	$t7,$t3,$a0
/*  f0a681c:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f0a6820:	5701000e */ 	bnel	$t8,$at,.L0f0a685c
/*  f0a6824:	960d06d6 */ 	lhu	$t5,0x6d6($s0)
/*  f0a6828:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f0a682c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a6830:	3c19800a */ 	lui	$t9,0x800a
/*  f0a6834:	51c10009 */ 	beql	$t6,$at,.L0f0a685c
/*  f0a6838:	960d06d6 */ 	lhu	$t5,0x6d6($s0)
/*  f0a683c:	8f399ff4 */ 	lw	$t9,-0x600c($t9)
/*  f0a6840:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a6844:	8fa50308 */ 	lw	$a1,0x308($sp)
/*  f0a6848:	13200003 */ 	beqz	$t9,.L0f0a6858
/*  f0a684c:	8fa601c4 */ 	lw	$a2,0x1c4($sp)
/*  f0a6850:	0fc28d24 */ 	jal	func0f0a3490
/*  f0a6854:	8fa701d0 */ 	lw	$a3,0x1d0($sp)
.L0f0a6858:
/*  f0a6858:	960d06d6 */ 	lhu	$t5,0x6d6($s0)
.L0f0a685c:
/*  f0a685c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a6860:	8fa50280 */ 	lw	$a1,0x280($sp)
/*  f0a6864:	000d6302 */ 	srl	$t4,$t5,0xc
/*  f0a6868:	19800003 */ 	blez	$t4,.L0f0a6878
/*  f0a686c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6870:	0fc291a9 */ 	jal	func0f0a46a4
/*  f0a6874:	8fa601b8 */ 	lw	$a2,0x1b8($sp)
.L0f0a6878:
/*  f0a6878:	3c09800a */ 	lui	$t1,0x800a
/*  f0a687c:	8d29a02c */ 	lw	$t1,-0x5fd4($t1)
/*  f0a6880:	3c02800a */ 	lui	$v0,0x800a
/*  f0a6884:	3c03800a */ 	lui	$v1,0x800a
/*  f0a6888:	3c06800a */ 	lui	$a2,0x800a
/*  f0a688c:	8cc6a030 */ 	lw	$a2,-0x5fd0($a2)
/*  f0a6890:	8c63a024 */ 	lw	$v1,-0x5fdc($v1)
/*  f0a6894:	11200003 */ 	beqz	$t1,.L0f0a68a4
/*  f0a6898:	8c42a028 */ 	lw	$v0,-0x5fd8($v0)
/*  f0a689c:	10000002 */ 	beqz	$zero,.L0f0a68a8
/*  f0a68a0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0a68a4:
/*  f0a68a4:	00002825 */ 	or	$a1,$zero,$zero
.L0f0a68a8:
/*  f0a68a8:	10400003 */ 	beqz	$v0,.L0f0a68b8
/*  f0a68ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a68b0:	10000002 */ 	beqz	$zero,.L0f0a68bc
/*  f0a68b4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0a68b8:
/*  f0a68b8:	00002025 */ 	or	$a0,$zero,$zero
.L0f0a68bc:
/*  f0a68bc:	10600003 */ 	beqz	$v1,.L0f0a68cc
/*  f0a68c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a68c4:	10000002 */ 	beqz	$zero,.L0f0a68d0
/*  f0a68c8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a68cc:
/*  f0a68cc:	00001825 */ 	or	$v1,$zero,$zero
.L0f0a68d0:
/*  f0a68d0:	10c00003 */ 	beqz	$a2,.L0f0a68e0
/*  f0a68d4:	3c188009 */ 	lui	$t8,0x8009
/*  f0a68d8:	10000001 */ 	beqz	$zero,.L0f0a68e0
/*  f0a68dc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a68e0:
/*  f0a68e0:	00435021 */ 	addu	$t2,$v0,$v1
/*  f0a68e4:	01445821 */ 	addu	$t3,$t2,$a0
/*  f0a68e8:	01657821 */ 	addu	$t7,$t3,$a1
/*  f0a68ec:	15e10013 */ 	bne	$t7,$at,.L0f0a693c
/*  f0a68f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a68f4:	93180af0 */ 	lbu	$t8,0xaf0($t8)
/*  f0a68f8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a68fc:	1301000f */ 	beq	$t8,$at,.L0f0a693c
/*  f0a6900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6904:	820e0007 */ 	lb	$t6,0x7($s0)
/*  f0a6908:	8fb901c4 */ 	lw	$t9,0x1c4($sp)
/*  f0a690c:	11c0000b */ 	beqz	$t6,.L0f0a693c
/*  f0a6910:	2b210002 */ 	slti	$at,$t9,0x2
/*  f0a6914:	14200009 */ 	bnez	$at,.L0f0a693c
/*  f0a6918:	2b210005 */ 	slti	$at,$t9,0x5
/*  f0a691c:	10200007 */ 	beqz	$at,.L0f0a693c
/*  f0a6920:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a6924:	8fa50280 */ 	lw	$a1,0x280($sp)
/*  f0a6928:	8fa60308 */ 	lw	$a2,0x308($sp)
/*  f0a692c:	0fc28ded */ 	jal	func0f0a37b4
/*  f0a6930:	8fa70304 */ 	lw	$a3,0x304($sp)
/*  f0a6934:	10000004 */ 	beqz	$zero,.L0f0a6948
/*  f0a6938:	ae000684 */ 	sw	$zero,0x684($s0)
.L0f0a693c:
/*  f0a693c:	0fc2c0f6 */ 	jal	func0f0b03d8
/*  f0a6940:	8fa40308 */ 	lw	$a0,0x308($sp)
/*  f0a6944:	ae000684 */ 	sw	$zero,0x684($s0)
.L0f0a6948:
/*  f0a6948:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0a694c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0a6950:	27bd0308 */ 	addiu	$sp,$sp,0x308
/*  f0a6954:	03e00008 */ 	jr	$ra
/*  f0a6958:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a695c
/*  f0a695c:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f0a6960:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f0a6964:	3c014200 */ 	lui	$at,0x4200
/*  f0a6968:	4481f000 */ 	mtc1	$at,$f30
/*  f0a696c:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f0a6970:	3c017f1b */ 	lui	$at,%hi(var7f1aca74)
/*  f0a6974:	c43cca74 */ 	lwc1	$f28,%lo(var7f1aca74)($at)
/*  f0a6978:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f0a697c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a6980:	4481d000 */ 	mtc1	$at,$f26
/*  f0a6984:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f0a6988:	3c017f1b */ 	lui	$at,%hi(var7f1aca78)
/*  f0a698c:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0a6990:	c438ca78 */ 	lwc1	$f24,%lo(var7f1aca78)($at)
/*  f0a6994:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f0a6998:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0a699c:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0a69a0:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f0a69a4:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0a69a8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0a69ac:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f0a69b0:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f0a69b4:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f0a69b8:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0a69bc:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0a69c0:	3c158009 */ 	lui	$s5,%hi(var80095200)
/*  f0a69c4:	3c168006 */ 	lui	$s6,%hi(var80061630)
/*  f0a69c8:	4481b000 */ 	mtc1	$at,$f22
/*  f0a69cc:	4480a000 */ 	mtc1	$zero,$f20
/*  f0a69d0:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f0a69d4:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0a69d8:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0a69dc:	8e920284 */ 	lw	$s2,0x284($s4)
/*  f0a69e0:	26d61630 */ 	addiu	$s6,$s6,%lo(var80061630)
/*  f0a69e4:	26b55200 */ 	addiu	$s5,$s5,%lo(var80095200)
/*  f0a69e8:	00009825 */ 	or	$s3,$zero,$zero
/*  f0a69ec:	24170f48 */ 	addiu	$s7,$zero,0xf48
/*  f0a69f0:	27be0094 */ 	addiu	$s8,$sp,0x94
.L0f0a69f4:
/*  f0a69f4:	824e0640 */ 	lb	$t6,0x640($s2)
/*  f0a69f8:	00008825 */ 	or	$s1,$zero,$zero
/*  f0a69fc:	26500638 */ 	addiu	$s0,$s2,0x638
/*  f0a6a00:	51c00077 */ 	beqzl	$t6,.L0f0a6be0
/*  f0a6a04:	267307a4 */ 	addiu	$s3,$s3,0x7a4
/*  f0a6a08:	0fc26709 */ 	jal	func0f099c24
/*  f0a6a0c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a6a10:	50400004 */ 	beqzl	$v0,.L0f0a6a24
/*  f0a6a14:	920f0003 */ 	lbu	$t7,0x3($s0)
/*  f0a6a18:	10000035 */ 	beqz	$zero,.L0f0a6af0
/*  f0a6a1c:	e614023c */ 	swc1	$f20,0x23c($s0)
/*  f0a6a20:	920f0003 */ 	lbu	$t7,0x3($s0)
.L0f0a6a24:
/*  f0a6a24:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a6a28:	15e10024 */ 	bne	$t7,$at,.L0f0a6abc
/*  f0a6a2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6a30:	c600023c */ 	lwc1	$f0,0x23c($s0)
/*  f0a6a34:	8e190220 */ 	lw	$t9,0x220($s0)
/*  f0a6a38:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f0a6a3c:	2b210002 */ 	slti	$at,$t9,0x2
/*  f0a6a40:	44032000 */ 	mfc1	$v1,$f4
/*  f0a6a44:	5420000d */ 	bnezl	$at,.L0f0a6a7c
/*  f0a6a48:	4600b03c */ 	c.lt.s	$f22,$f0
/*  f0a6a4c:	4616003c */ 	c.lt.s	$f0,$f22
/*  f0a6a50:	3c017f1b */ 	lui	$at,%hi(var7f1aca7c)
/*  f0a6a54:	45020009 */ 	bc1fl	.L0f0a6a7c
/*  f0a6a58:	4600b03c */ 	c.lt.s	$f22,$f0
/*  f0a6a5c:	c686004c */ 	lwc1	$f6,0x4c($s4)
/*  f0a6a60:	c428ca7c */ 	lwc1	$f8,%lo(var7f1aca7c)($at)
/*  f0a6a64:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f0a6a68:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0a6a6c:	460a0400 */ 	add.s	$f16,$f0,$f10
/*  f0a6a70:	e610023c */ 	swc1	$f16,0x23c($s0)
/*  f0a6a74:	c600023c */ 	lwc1	$f0,0x23c($s0)
/*  f0a6a78:	4600b03c */ 	c.lt.s	$f22,$f0
.L0f0a6a7c:
/*  f0a6a7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6a80:	45020004 */ 	bc1fl	.L0f0a6a94
/*  f0a6a84:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f0a6a88:	e616023c */ 	swc1	$f22,0x23c($s0)
/*  f0a6a8c:	c600023c */ 	lwc1	$f0,0x23c($s0)
/*  f0a6a90:	4600048d */ 	trunc.w.s	$f18,$f0
.L0f0a6a94:
/*  f0a6a94:	44029000 */ 	mfc1	$v0,$f18
/*  f0a6a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6a9c:	50620015 */ 	beql	$v1,$v0,.L0f0a6af4
/*  f0a6aa0:	8e03074c */ 	lw	$v1,0x74c($s0)
/*  f0a6aa4:	8e020220 */ 	lw	$v0,0x220($s0)
/*  f0a6aa8:	28410002 */ 	slti	$at,$v0,0x2
/*  f0a6aac:	14200010 */ 	bnez	$at,.L0f0a6af0
/*  f0a6ab0:	2449ffff */ 	addiu	$t1,$v0,-1
/*  f0a6ab4:	1000000e */ 	beqz	$zero,.L0f0a6af0
/*  f0a6ab8:	ae090220 */ 	sw	$t1,0x220($s0)
.L0f0a6abc:
/*  f0a6abc:	3c017f1b */ 	lui	$at,%hi(var7f1aca80)
/*  f0a6ac0:	c426ca80 */ 	lwc1	$f6,%lo(var7f1aca80)($at)
/*  f0a6ac4:	c684004c */ 	lwc1	$f4,0x4c($s4)
/*  f0a6ac8:	c60a023c */ 	lwc1	$f10,0x23c($s0)
/*  f0a6acc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0a6ad0:	46085401 */ 	sub.s	$f16,$f10,$f8
/*  f0a6ad4:	e610023c */ 	swc1	$f16,0x23c($s0)
/*  f0a6ad8:	c612023c */ 	lwc1	$f18,0x23c($s0)
/*  f0a6adc:	4614903c */ 	c.lt.s	$f18,$f20
/*  f0a6ae0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6ae4:	45020003 */ 	bc1fl	.L0f0a6af4
/*  f0a6ae8:	8e03074c */ 	lw	$v1,0x74c($s0)
/*  f0a6aec:	e614023c */ 	swc1	$f20,0x23c($s0)
.L0f0a6af0:
/*  f0a6af0:	8e03074c */ 	lw	$v1,0x74c($s0)
.L0f0a6af4:
/*  f0a6af4:	14600017 */ 	bnez	$v1,.L0f0a6b54
/*  f0a6af8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6afc:	c604023c */ 	lwc1	$f4,0x23c($s0)
/*  f0a6b00:	4604c03c */ 	c.lt.s	$f24,$f4
/*  f0a6b04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6b08:	45000012 */ 	bc1f	.L0f0a6b54
/*  f0a6b0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6b10:	12200010 */ 	beqz	$s1,.L0f0a6b54
/*  f0a6b14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6b18:	8e8a0034 */ 	lw	$t2,0x34($s4)
/*  f0a6b1c:	24058065 */ 	addiu	$a1,$zero,-32667
/*  f0a6b20:	2606074c */ 	addiu	$a2,$s0,0x74c
/*  f0a6b24:	1140000b */ 	beqz	$t2,.L0f0a6b54
/*  f0a6b28:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a6b2c:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0a6b30:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0a6b34:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0a6b38:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0a6b3c:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0a6b40:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0a6b44:	8ea40000 */ 	lw	$a0,0x0($s5)
/*  f0a6b48:	0c004241 */ 	jal	func00010904
/*  f0a6b4c:	e7ba0014 */ 	swc1	$f26,0x14($sp)
/*  f0a6b50:	8e03074c */ 	lw	$v1,0x74c($s0)
.L0f0a6b54:
/*  f0a6b54:	50600022 */ 	beqzl	$v1,.L0f0a6be0
/*  f0a6b58:	267307a4 */ 	addiu	$s3,$s3,0x7a4
/*  f0a6b5c:	c6c60000 */ 	lwc1	$f6,0x0($s6)
/*  f0a6b60:	461c3282 */ 	mul.s	$f10,$f6,$f28
/*  f0a6b64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6b68:	461e5302 */ 	mul.s	$f12,$f10,$f30
/*  f0a6b6c:	0c0068f7 */ 	jal	func0001a3dc
/*  f0a6b70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6b74:	3c014040 */ 	lui	$at,0x4040
/*  f0a6b78:	44818000 */ 	mtc1	$at,$f16
/*  f0a6b7c:	c608023c */ 	lwc1	$f8,0x23c($s0)
/*  f0a6b80:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a6b84:	44812000 */ 	mtc1	$at,$f4
/*  f0a6b88:	46104483 */ 	div.s	$f18,$f8,$f16
/*  f0a6b8c:	3c017f1b */ 	lui	$at,%hi(var7f1aca84)
/*  f0a6b90:	c42aca84 */ 	lwc1	$f10,%lo(var7f1aca84)($at)
/*  f0a6b94:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0a6b98:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f0a6b9c:	46064400 */ 	add.s	$f16,$f8,$f6
/*  f0a6ba0:	e7b00094 */ 	swc1	$f16,0x94($sp)
/*  f0a6ba4:	c604023c */ 	lwc1	$f4,0x23c($s0)
/*  f0a6ba8:	4618203c */ 	c.lt.s	$f4,$f24
/*  f0a6bac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6bb0:	45010003 */ 	bc1t	.L0f0a6bc0
/*  f0a6bb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6bb8:	16200005 */ 	bnez	$s1,.L0f0a6bd0
/*  f0a6bbc:	24050010 */ 	addiu	$a1,$zero,0x10
.L0f0a6bc0:
/*  f0a6bc0:	0c00cec9 */ 	jal	func00033b24
/*  f0a6bc4:	8e04074c */ 	lw	$a0,0x74c($s0)
/*  f0a6bc8:	10000005 */ 	beqz	$zero,.L0f0a6be0
/*  f0a6bcc:	267307a4 */ 	addiu	$s3,$s3,0x7a4
.L0f0a6bd0:
/*  f0a6bd0:	8e04074c */ 	lw	$a0,0x74c($s0)
/*  f0a6bd4:	0c00cf94 */ 	jal	func00033e50
/*  f0a6bd8:	8fc60000 */ 	lw	$a2,0x0($s8)
/*  f0a6bdc:	267307a4 */ 	addiu	$s3,$s3,0x7a4
.L0f0a6be0:
/*  f0a6be0:	1677ff84 */ 	bne	$s3,$s7,.L0f0a69f4
/*  f0a6be4:	265207a4 */ 	addiu	$s2,$s2,0x7a4
/*  f0a6be8:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f0a6bec:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0a6bf0:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f0a6bf4:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f0a6bf8:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f0a6bfc:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f0a6c00:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f0a6c04:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0a6c08:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0a6c0c:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0a6c10:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0a6c14:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0a6c18:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0a6c1c:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0a6c20:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f0a6c24:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f0a6c28:	03e00008 */ 	jr	$ra
/*  f0a6c2c:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

GLOBAL_ASM(
glabel func0f0a6c30
/*  f0a6c30:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a6c34:	8dcea24c */ 	lw	$t6,-0x5db4($t6)
/*  f0a6c38:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0a6c3c:	3c03800a */ 	lui	$v1,0x800a
/*  f0a6c40:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0a6c44:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a6c48:	15c00004 */ 	bnez	$t6,.L0f0a6c5c
/*  f0a6c4c:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f0a6c50:	0fc2434d */ 	jal	func0f090d34
/*  f0a6c54:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0a6c58:	8fa3004c */ 	lw	$v1,0x4c($sp)
.L0f0a6c5c:
/*  f0a6c5c:	8c6f1580 */ 	lw	$t7,0x1580($v1)
/*  f0a6c60:	000fcf80 */ 	sll	$t9,$t7,0x1e
/*  f0a6c64:	07210003 */ 	bgez	$t9,.L0f0a6c74
/*  f0a6c68:	3c02800a */ 	lui	$v0,%hi(var800a07a4)
/*  f0a6c6c:	10000006 */ 	beqz	$zero,.L0f0a6c88
/*  f0a6c70:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
.L0f0a6c74:
/*  f0a6c74:	0fc27aa4 */ 	jal	func0f09ea90
/*  f0a6c78:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0a6c7c:	3c02800a */ 	lui	$v0,%hi(var800a07a4)
/*  f0a6c80:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a6c84:	8fa3004c */ 	lw	$v1,0x4c($sp)
.L0f0a6c88:
/*  f0a6c88:	8c491c54 */ 	lw	$t1,0x1c54($v0)
/*  f0a6c8c:	8c4800c4 */ 	lw	$t0,0xc4($v0)
/*  f0a6c90:	01205027 */ 	nor	$t2,$t1,$zero
/*  f0a6c94:	010a2024 */ 	and	$a0,$t0,$t2
/*  f0a6c98:	308b0004 */ 	andi	$t3,$a0,0x4
/*  f0a6c9c:	5560000c */ 	bnezl	$t3,.L0f0a6cd0
/*  f0a6ca0:	30980002 */ 	andi	$t8,$a0,0x2
/*  f0a6ca4:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f0a6ca8:	3c0c800a */ 	lui	$t4,0x800a
/*  f0a6cac:	50400008 */ 	beqzl	$v0,.L0f0a6cd0
/*  f0a6cb0:	30980002 */ 	andi	$t8,$a0,0x2
/*  f0a6cb4:	a0400037 */ 	sb	$zero,0x37($v0)
/*  f0a6cb8:	8d8ca244 */ 	lw	$t4,-0x5dbc($t4)
/*  f0a6cbc:	8d8e1c54 */ 	lw	$t6,0x1c54($t4)
/*  f0a6cc0:	8d8d00c4 */ 	lw	$t5,0xc4($t4)
/*  f0a6cc4:	01c07827 */ 	nor	$t7,$t6,$zero
/*  f0a6cc8:	01af2024 */ 	and	$a0,$t5,$t7
/*  f0a6ccc:	30980002 */ 	andi	$t8,$a0,0x2
.L0f0a6cd0:
/*  f0a6cd0:	1300001f */ 	beqz	$t8,.L0f0a6d50
/*  f0a6cd4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a6cd8:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0a6cdc:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0a6ce0:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0a6ce4:	14410004 */ 	bne	$v0,$at,.L0f0a6cf8
/*  f0a6ce8:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0a6cec:	8c7917a4 */ 	lw	$t9,0x17a4($v1)
/*  f0a6cf0:	53200018 */ 	beqzl	$t9,.L0f0a6d54
/*  f0a6cf4:	8c6d17a4 */ 	lw	$t5,0x17a4($v1)
.L0f0a6cf8:
/*  f0a6cf8:	94690010 */ 	lhu	$t1,0x10($v1)
/*  f0a6cfc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a6d00:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a6d04:	11210003 */ 	beq	$t1,$at,.L0f0a6d14
/*  f0a6d08:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f0a6d0c:	10000006 */ 	beqz	$zero,.L0f0a6d28
/*  f0a6d10:	ac600254 */ 	sw	$zero,0x254($v1)
.L0f0a6d14:
/*  f0a6d14:	3c0a800a */ 	lui	$t2,0x800a
/*  f0a6d18:	8d4a9ff4 */ 	lw	$t2,-0x600c($t2)
/*  f0a6d1c:	8c680254 */ 	lw	$t0,0x254($v1)
/*  f0a6d20:	010a5821 */ 	addu	$t3,$t0,$t2
/*  f0a6d24:	ac6b0254 */ 	sw	$t3,0x254($v1)
.L0f0a6d28:
/*  f0a6d28:	240c0008 */ 	addiu	$t4,$zero,0x8
/*  f0a6d2c:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0a6d30:	a4620010 */ 	sh	$v0,0x10($v1)
/*  f0a6d34:	a0640251 */ 	sb	$a0,0x251($v1)
/*  f0a6d38:	a06c0252 */ 	sb	$t4,0x252($v1)
/*  f0a6d3c:	a0640253 */ 	sb	$a0,0x253($v1)
/*  f0a6d40:	a06e0270 */ 	sb	$t6,0x270($v1)
/*  f0a6d44:	a0600271 */ 	sb	$zero,0x271($v1)
/*  f0a6d48:	10000029 */ 	beqz	$zero,.L0f0a6df0
/*  f0a6d4c:	a0620272 */ 	sb	$v0,0x272($v1)
.L0f0a6d50:
/*  f0a6d50:	8c6d17a4 */ 	lw	$t5,0x17a4($v1)
.L0f0a6d54:
/*  f0a6d54:	55a00022 */ 	bnezl	$t5,.L0f0a6de0
/*  f0a6d58:	946d0010 */ 	lhu	$t5,0x10($v1)
/*  f0a6d5c:	906f0638 */ 	lbu	$t7,0x638($v1)
/*  f0a6d60:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0a6d64:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a6d68:	15e10016 */ 	bne	$t7,$at,.L0f0a6dc4
/*  f0a6d6c:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f0a6d70:	94780010 */ 	lhu	$t8,0x10($v1)
/*  f0a6d74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a6d78:	240a0010 */ 	addiu	$t2,$zero,0x10
/*  f0a6d7c:	13010003 */ 	beq	$t8,$at,.L0f0a6d8c
/*  f0a6d80:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f0a6d84:	10000006 */ 	beqz	$zero,.L0f0a6da0
/*  f0a6d88:	ac600254 */ 	sw	$zero,0x254($v1)
.L0f0a6d8c:
/*  f0a6d8c:	3c09800a */ 	lui	$t1,0x800a
/*  f0a6d90:	8d299ff4 */ 	lw	$t1,-0x600c($t1)
/*  f0a6d94:	8c790254 */ 	lw	$t9,0x254($v1)
/*  f0a6d98:	03294021 */ 	addu	$t0,$t9,$t1
/*  f0a6d9c:	ac680254 */ 	sw	$t0,0x254($v1)
.L0f0a6da0:
/*  f0a6da0:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f0a6da4:	a4620010 */ 	sh	$v0,0x10($v1)
/*  f0a6da8:	a06a0251 */ 	sb	$t2,0x251($v1)
/*  f0a6dac:	a0640252 */ 	sb	$a0,0x252($v1)
/*  f0a6db0:	a06b0253 */ 	sb	$t3,0x253($v1)
/*  f0a6db4:	a0600270 */ 	sb	$zero,0x270($v1)
/*  f0a6db8:	a0620271 */ 	sb	$v0,0x271($v1)
/*  f0a6dbc:	1000000c */ 	beqz	$zero,.L0f0a6df0
/*  f0a6dc0:	a06c0272 */ 	sb	$t4,0x272($v1)
.L0f0a6dc4:
/*  f0a6dc4:	946e0010 */ 	lhu	$t6,0x10($v1)
/*  f0a6dc8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a6dcc:	51c10009 */ 	beql	$t6,$at,.L0f0a6df4
/*  f0a6dd0:	806f1580 */ 	lb	$t7,0x1580($v1)
/*  f0a6dd4:	10000006 */ 	beqz	$zero,.L0f0a6df0
/*  f0a6dd8:	a4600010 */ 	sh	$zero,0x10($v1)
/*  f0a6ddc:	946d0010 */ 	lhu	$t5,0x10($v1)
.L0f0a6de0:
/*  f0a6de0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a6de4:	51a10003 */ 	beql	$t5,$at,.L0f0a6df4
/*  f0a6de8:	806f1580 */ 	lb	$t7,0x1580($v1)
/*  f0a6dec:	a4600010 */ 	sh	$zero,0x10($v1)
.L0f0a6df0:
/*  f0a6df0:	806f1580 */ 	lb	$t7,0x1580($v1)
.L0f0a6df4:
/*  f0a6df4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a6df8:	15e10004 */ 	bne	$t7,$at,.L0f0a6e0c
/*  f0a6dfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6e00:	0fc29a57 */ 	jal	func0f0a695c
/*  f0a6e04:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0a6e08:	8fa3004c */ 	lw	$v1,0x4c($sp)
.L0f0a6e0c:
/*  f0a6e0c:	3c18800a */ 	lui	$t8,0x800a
/*  f0a6e10:	8f189ff4 */ 	lw	$t8,-0x600c($t8)
/*  f0a6e14:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a6e18:	00608025 */ 	or	$s0,$v1,$zero
/*  f0a6e1c:	1700000e */ 	bnez	$t8,.L0f0a6e58
/*  f0a6e20:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a6e24:
/*  f0a6e24:	8e190d84 */ 	lw	$t9,0xd84($s0)
/*  f0a6e28:	53200008 */ 	beqzl	$t9,.L0f0a6e4c
/*  f0a6e2c:	244207a4 */ 	addiu	$v0,$v0,%lo(var800a07a4)
/*  f0a6e30:	8e040d84 */ 	lw	$a0,0xd84($s0)
/*  f0a6e34:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0a6e38:	0c00cec9 */ 	jal	func00033b24
/*  f0a6e3c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0a6e40:	8fa20020 */ 	lw	$v0,0x20($sp)
/*  f0a6e44:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0a6e48:	244207a4 */ 	addiu	$v0,$v0,%lo(var800a07a4)
.L0f0a6e4c:
/*  f0a6e4c:	24010f48 */ 	addiu	$at,$zero,0xf48
/*  f0a6e50:	1441fff4 */ 	bne	$v0,$at,.L0f0a6e24
/*  f0a6e54:	261007a4 */ 	addiu	$s0,$s0,0x7a4
.L0f0a6e58:
/*  f0a6e58:	3c02800a */ 	lui	$v0,0x800a
/*  f0a6e5c:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a6e60:	80641580 */ 	lb	$a0,0x1580($v1)
/*  f0a6e64:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0a6e68:	8c481c54 */ 	lw	$t0,0x1c54($v0)
/*  f0a6e6c:	8c4900c4 */ 	lw	$t1,0xc4($v0)
/*  f0a6e70:	01005027 */ 	nor	$t2,$t0,$zero
/*  f0a6e74:	012a5824 */ 	and	$t3,$t1,$t2
/*  f0a6e78:	316c0080 */ 	andi	$t4,$t3,0x80
/*  f0a6e7c:	11800049 */ 	beqz	$t4,.L0f0a6fa4
/*  f0a6e80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6e84:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0a6e88:	54810042 */ 	bnel	$a0,$at,.L0f0a6f94
/*  f0a6e8c:	8c6900c4 */ 	lw	$t1,0xc4($v1)
/*  f0a6e90:	8c6e00bc */ 	lw	$t6,0xbc($v1)
/*  f0a6e94:	8dc20004 */ 	lw	$v0,0x4($t6)
/*  f0a6e98:	8c4d0014 */ 	lw	$t5,0x14($v0)
/*  f0a6e9c:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f0a6ea0:	05e1006b */ 	bgez	$t7,.L0f0a7050
/*  f0a6ea4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6ea8:	945802e0 */ 	lhu	$t8,0x2e0($v0)
/*  f0a6eac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a6eb0:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0a6eb4:	17210066 */ 	bne	$t9,$at,.L0f0a7050
/*  f0a6eb8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a6ebc:	44811000 */ 	mtc1	$at,$f2
/*  f0a6ec0:	3c01800a */ 	lui	$at,0x800a
/*  f0a6ec4:	c424a004 */ 	lwc1	$f4,-0x5ffc($at)
/*  f0a6ec8:	3c017f1b */ 	lui	$at,%hi(var7f1aca88)
/*  f0a6ecc:	c426ca88 */ 	lwc1	$f6,%lo(var7f1aca88)($at)
/*  f0a6ed0:	c46a0874 */ 	lwc1	$f10,0x874($v1)
/*  f0a6ed4:	24620638 */ 	addiu	$v0,$v1,0x638
/*  f0a6ed8:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0a6edc:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f0a6ee0:	e4700874 */ 	swc1	$f16,0x874($v1)
/*  f0a6ee4:	c4720874 */ 	lwc1	$f18,0x874($v1)
/*  f0a6ee8:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0a6eec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6ef0:	45000057 */ 	bc1f	.L0f0a7050
/*  f0a6ef4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6ef8:	c440023c */ 	lwc1	$f0,0x23c($v0)
/*  f0a6efc:	8c440220 */ 	lw	$a0,0x220($v0)
/*  f0a6f00:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f0a6f04:	44052000 */ 	mfc1	$a1,$f4
/*  f0a6f08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6f0c:	0085082a */ 	slt	$at,$a0,$a1
/*  f0a6f10:	50200003 */ 	beqzl	$at,.L0f0a6f20
/*  f0a6f14:	44853000 */ 	mtc1	$a1,$f6
/*  f0a6f18:	00802825 */ 	or	$a1,$a0,$zero
/*  f0a6f1c:	44853000 */ 	mtc1	$a1,$f6
.L0f0a6f20:
/*  f0a6f20:	00854823 */ 	subu	$t1,$a0,$a1
/*  f0a6f24:	ac490220 */ 	sw	$t1,0x220($v0)
/*  f0a6f28:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0a6f2c:	460a0201 */ 	sub.s	$f8,$f0,$f10
/*  f0a6f30:	15200047 */ 	bnez	$t1,.L0f0a7050
/*  f0a6f34:	e448023c */ 	swc1	$f8,0x23c($v0)
/*  f0a6f38:	8c4b0604 */ 	lw	$t3,0x604($v0)
/*  f0a6f3c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a6f40:	11610043 */ 	beq	$t3,$at,.L0f0a7050
/*  f0a6f44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6f48:	c450023c */ 	lwc1	$f16,0x23c($v0)
/*  f0a6f4c:	806e15e4 */ 	lb	$t6,0x15e4($v1)
/*  f0a6f50:	3c02800a */ 	lui	$v0,0x800a
/*  f0a6f54:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0a6f58:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f0a6f5c:	006d7821 */ 	addu	$t7,$v1,$t5
/*  f0a6f60:	8df817a8 */ 	lw	$t8,0x17a8($t7)
/*  f0a6f64:	44049000 */ 	mfc1	$a0,$f18
/*  f0a6f68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6f6c:	0304082a */ 	slt	$at,$t8,$a0
/*  f0a6f70:	10200037 */ 	beqz	$at,.L0f0a7050
/*  f0a6f74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6f78:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a6f7c:	2401ff7f */ 	addiu	$at,$zero,-129
/*  f0a6f80:	8c5900c4 */ 	lw	$t9,0xc4($v0)
/*  f0a6f84:	03214024 */ 	and	$t0,$t9,$at
/*  f0a6f88:	10000031 */ 	beqz	$zero,.L0f0a7050
/*  f0a6f8c:	ac4800c4 */ 	sw	$t0,0xc4($v0)
/*  f0a6f90:	8c6900c4 */ 	lw	$t1,0xc4($v1)
.L0f0a6f94:
/*  f0a6f94:	2401ff7f */ 	addiu	$at,$zero,-129
/*  f0a6f98:	01215024 */ 	and	$t2,$t1,$at
/*  f0a6f9c:	1000002c */ 	beqz	$zero,.L0f0a7050
/*  f0a6fa0:	ac6a00c4 */ 	sw	$t2,0xc4($v1)
.L0f0a6fa4:
/*  f0a6fa4:	1481002a */ 	bne	$a0,$at,.L0f0a7050
/*  f0a6fa8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a6fac:	44811000 */ 	mtc1	$at,$f2
/*  f0a6fb0:	c4640874 */ 	lwc1	$f4,0x874($v1)
/*  f0a6fb4:	24620638 */ 	addiu	$v0,$v1,0x638
/*  f0a6fb8:	4604103c */ 	c.lt.s	$f2,$f4
/*  f0a6fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6fc0:	45000023 */ 	bc1f	.L0f0a7050
/*  f0a6fc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6fc8:	c440023c */ 	lwc1	$f0,0x23c($v0)
/*  f0a6fcc:	8c440220 */ 	lw	$a0,0x220($v0)
/*  f0a6fd0:	4600018d */ 	trunc.w.s	$f6,$f0
/*  f0a6fd4:	44053000 */ 	mfc1	$a1,$f6
/*  f0a6fd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a6fdc:	0085082a */ 	slt	$at,$a0,$a1
/*  f0a6fe0:	50200003 */ 	beqzl	$at,.L0f0a6ff0
/*  f0a6fe4:	44855000 */ 	mtc1	$a1,$f10
/*  f0a6fe8:	00802825 */ 	or	$a1,$a0,$zero
/*  f0a6fec:	44855000 */ 	mtc1	$a1,$f10
.L0f0a6ff0:
/*  f0a6ff0:	00856023 */ 	subu	$t4,$a0,$a1
/*  f0a6ff4:	ac4c0220 */ 	sw	$t4,0x220($v0)
/*  f0a6ff8:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0a6ffc:	46080401 */ 	sub.s	$f16,$f0,$f8
/*  f0a7000:	e450023c */ 	swc1	$f16,0x23c($v0)
/*  f0a7004:	c440023c */ 	lwc1	$f0,0x23c($v0)
/*  f0a7008:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a700c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7010:	4500000f */ 	bc1f	.L0f0a7050
/*  f0a7014:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7018:	806d15e4 */ 	lb	$t5,0x15e4($v1)
/*  f0a701c:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f0a7020:	44802000 */ 	mtc1	$zero,$f4
/*  f0a7024:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f0a7028:	006f3021 */ 	addu	$a2,$v1,$t7
/*  f0a702c:	44059000 */ 	mfc1	$a1,$f18
/*  f0a7030:	8cc417a8 */ 	lw	$a0,0x17a8($a2)
/*  f0a7034:	0085082a */ 	slt	$at,$a0,$a1
/*  f0a7038:	50200003 */ 	beqzl	$at,.L0f0a7048
/*  f0a703c:	0085c023 */ 	subu	$t8,$a0,$a1
/*  f0a7040:	00802825 */ 	or	$a1,$a0,$zero
/*  f0a7044:	0085c023 */ 	subu	$t8,$a0,$a1
.L0f0a7048:
/*  f0a7048:	acd817a8 */ 	sw	$t8,0x17a8($a2)
/*  f0a704c:	e444023c */ 	swc1	$f4,0x23c($v0)
.L0f0a7050:
/*  f0a7050:	0fc25f59 */ 	jal	func0f097d64
/*  f0a7054:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0a7058:	0fc29554 */ 	jal	func0f0a5550
/*  f0a705c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a7060:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0a7064:	80790de4 */ 	lb	$t9,0xde4($v1)
/*  f0a7068:	53200006 */ 	beqzl	$t9,.L0f0a7084
/*  f0a706c:	906814b2 */ 	lbu	$t0,0x14b2($v1)
/*  f0a7070:	0fc29554 */ 	jal	func0f0a5550
/*  f0a7074:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a7078:	10000004 */ 	beqz	$zero,.L0f0a708c
/*  f0a707c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7080:	906814b2 */ 	lbu	$t0,0x14b2($v1)
.L0f0a7084:
/*  f0a7084:	3109ff0f */ 	andi	$t1,$t0,0xff0f
/*  f0a7088:	a06914b2 */ 	sb	$t1,0x14b2($v1)
.L0f0a708c:
/*  f0a708c:	0fc2a31f */ 	jal	func0f0a8c7c
/*  f0a7090:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7094:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0a7098:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a709c:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f0a70a0:	03e00008 */ 	jr	$ra
/*  f0a70a4:	00000000 */ 	sll	$zero,$zero,0x0
);

s8 freeFireslotWrapper(s32 fireslot_id)
{
	return freeFireslot(fireslot_id);
}

s8 freeFireslot(s32 fireslot_id)
{
	if (fireslot_id >= 0 && fireslot_id < NUM_FIRESLOTS) {
		g_Fireslots[fireslot_id].unk00 = -1;
	}

	return -1;
}

GLOBAL_ASM(
glabel func0f0a70f8
/*  f0a70f8:	3c04800a */ 	lui	$a0,%hi(g_Fireslots)
/*  f0a70fc:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0a7100:	2484d150 */ 	addiu	$a0,$a0,%lo(g_Fireslots)
/*  f0a7104:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a7108:	24050014 */ 	addiu	$a1,$zero,0x14
.L0f0a710c:
/*  f0a710c:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f0a7110:	05c10004 */ 	bgez	$t6,.L0f0a7124
/*  f0a7114:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0a7118:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0a711c:	03e00008 */ 	jr	$ra
/*  f0a7120:	a08f0004 */ 	sb	$t7,0x4($a0)
.L0f0a7124:
/*  f0a7124:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0a7128:	1445fff8 */ 	bne	$v0,$a1,.L0f0a710c
/*  f0a712c:	24840030 */ 	addiu	$a0,$a0,0x30
/*  f0a7130:	03e00008 */ 	jr	$ra
/*  f0a7134:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f0a7138
/*  f0a7138:	27bdfeb0 */ 	addiu	$sp,$sp,-336
/*  f0a713c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0a7140:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f0a7144:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f0a7148:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f0a714c:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0a7150:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0a7154:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0a7158:	afa40150 */ 	sw	$a0,0x150($sp)
/*  f0a715c:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0a7160:	3c198007 */ 	lui	$t9,%hi(var8007029c)
/*  f0a7164:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f0a7168:	2739029c */ 	addiu	$t9,$t9,%lo(var8007029c)
/*  f0a716c:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f0a7170:	272a003c */ 	addiu	$t2,$t9,0x3c
/*  f0a7174:	27b8010c */ 	addiu	$t8,$sp,0x10c
/*  f0a7178:	afaf014c */ 	sw	$t7,0x14c($sp)
.L0f0a717c:
/*  f0a717c:	8f210000 */ 	lw	$at,0x0($t9)
/*  f0a7180:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f0a7184:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f0a7188:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f0a718c:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f0a7190:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f0a7194:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f0a7198:	172afff8 */ 	bne	$t9,$t2,.L0f0a717c
/*  f0a719c:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f0a71a0:	8f210000 */ 	lw	$at,0x0($t9)
/*  f0a71a4:	af010000 */ 	sw	$at,0x0($t8)
/*  f0a71a8:	8e330284 */ 	lw	$s3,0x284($s1)
/*  f0a71ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a71b0:	966b0010 */ 	lhu	$t3,0x10($s3)
/*  f0a71b4:	1561000d */ 	bne	$t3,$at,.L0f0a71ec
/*  f0a71b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a71bc:	24040f48 */ 	addiu	$a0,$zero,0xf48
/*  f0a71c0:	8e2c0284 */ 	lw	$t4,0x284($s1)
.L0f0a71c4:
/*  f0a71c4:	01821821 */ 	addu	$v1,$t4,$v0
/*  f0a71c8:	8c6d0854 */ 	lw	$t5,0x854($v1)
/*  f0a71cc:	244207a4 */ 	addiu	$v0,$v0,0x7a4
/*  f0a71d0:	11a00002 */ 	beqz	$t5,.L0f0a71dc
/*  f0a71d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a71d8:	ac600850 */ 	sw	$zero,0x850($v1)
.L0f0a71dc:
/*  f0a71dc:	5444fff9 */ 	bnel	$v0,$a0,.L0f0a71c4
/*  f0a71e0:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f0a71e4:	100002d5 */ 	beqz	$zero,.L0f0a7d3c
/*  f0a71e8:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0a71ec:
/*  f0a71ec:	0fc5d9ad */ 	jal	func0f1766b4
/*  f0a71f0:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a71f4:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a71f8:	0c002ca0 */ 	jal	func0000b280
/*  f0a71fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a7200:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a7204:	0c002c74 */ 	jal	func0000b1d0
/*  f0a7208:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a720c:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f0a7210:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f0a7214:	0c002f40 */ 	jal	func0000bd00
/*  f0a7218:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0a721c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a7220:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0a7224:	0c002f44 */ 	jal	func0000bd10
/*  f0a7228:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0a722c:	44822000 */ 	mtc1	$v0,$f4
/*  f0a7230:	44908000 */ 	mtc1	$s0,$f16
/*  f0a7234:	3c014080 */ 	lui	$at,0x4080
/*  f0a7238:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a723c:	44810000 */ 	mtc1	$at,$f0
/*  f0a7240:	3c01ed00 */ 	lui	$at,0xed00
/*  f0a7244:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a7248:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a724c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7250:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0a7254:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0a7258:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a725c:	44085000 */ 	mfc1	$t0,$f10
/*  f0a7260:	440b3000 */ 	mfc1	$t3,$f6
/*  f0a7264:	310a0fff */ 	andi	$t2,$t0,0xfff
/*  f0a7268:	0141c825 */ 	or	$t9,$t2,$at
/*  f0a726c:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f0a7270:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f0a7274:	032d7025 */ 	or	$t6,$t9,$t5
/*  f0a7278:	0c002f22 */ 	jal	func0000bc88
/*  f0a727c:	aeae0000 */ 	sw	$t6,0x0($s5)
/*  f0a7280:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0a7284:	00127c03 */ 	sra	$t7,$s2,0x10
/*  f0a7288:	0c002f40 */ 	jal	func0000bd00
/*  f0a728c:	01e09025 */ 	or	$s2,$t7,$zero
/*  f0a7290:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f0a7294:	00144c03 */ 	sra	$t1,$s4,0x10
/*  f0a7298:	0c002f44 */ 	jal	func0000bd10
/*  f0a729c:	0120a025 */ 	or	$s4,$t1,$zero
/*  f0a72a0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a72a4:	00104403 */ 	sra	$t0,$s0,0x10
/*  f0a72a8:	0c002f26 */ 	jal	func0000bc98
/*  f0a72ac:	01008025 */ 	or	$s0,$t0,$zero
/*  f0a72b0:	00505021 */ 	addu	$t2,$v0,$s0
/*  f0a72b4:	448a4000 */ 	mtc1	$t2,$f8
/*  f0a72b8:	0292c821 */ 	addu	$t9,$s4,$s2
/*  f0a72bc:	44992000 */ 	mtc1	$t9,$f4
/*  f0a72c0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0a72c4:	3c014080 */ 	lui	$at,0x4080
/*  f0a72c8:	44810000 */ 	mtc1	$at,$f0
/*  f0a72cc:	3c053fc0 */ 	lui	$a1,0x3fc0
/*  f0a72d0:	3c06447a */ 	lui	$a2,0x447a
/*  f0a72d4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a72d8:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0a72dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a72e0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a72e4:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0a72e8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0a72ec:	440b9000 */ 	mfc1	$t3,$f18
/*  f0a72f0:	440e5000 */ 	mfc1	$t6,$f10
/*  f0a72f4:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f0a72f8:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f0a72fc:	000f4b00 */ 	sll	$t1,$t7,0xc
/*  f0a7300:	01894025 */ 	or	$t0,$t4,$t1
/*  f0a7304:	aea80004 */ 	sw	$t0,0x4($s5)
/*  f0a7308:	0c002b29 */ 	jal	func0000aca4
/*  f0a730c:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a7310:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f0a7314:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a7318:	91581bfc */ 	lbu	$t8,0x1bfc($t2)
/*  f0a731c:	53000016 */ 	beqzl	$t8,.L0f0a7378
/*  f0a7320:	8e2b006c */ 	lw	$t3,0x6c($s1)
/*  f0a7324:	0fc54bc7 */ 	jal	optionsGetScreenRatio
/*  f0a7328:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a732c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a7330:	14410008 */ 	bne	$v0,$at,.L0f0a7354
/*  f0a7334:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7338:	0fc2f4d6 */ 	jal	func0f0bd358
/*  f0a733c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7340:	3c017f1b */ 	lui	$at,%hi(var7f1aca8c)
/*  f0a7344:	c430ca8c */ 	lwc1	$f16,%lo(var7f1aca8c)($at)
/*  f0a7348:	46100082 */ 	mul.s	$f2,$f0,$f16
/*  f0a734c:	10000005 */ 	beqz	$zero,.L0f0a7364
/*  f0a7350:	44061000 */ 	mfc1	$a2,$f2
.L0f0a7354:
/*  f0a7354:	0fc2f4d6 */ 	jal	func0f0bd358
/*  f0a7358:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a735c:	46000086 */ 	mov.s	$f2,$f0
/*  f0a7360:	44061000 */ 	mfc1	$a2,$f2
.L0f0a7364:
/*  f0a7364:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a7368:	0c002c3a */ 	jal	func0000b0e8
/*  f0a736c:	3c054270 */ 	lui	$a1,0x4270
/*  f0a7370:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a7374:	8e2b006c */ 	lw	$t3,0x6c($s1)
.L0f0a7378:
/*  f0a7378:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a737c:	51600004 */ 	beqzl	$t3,.L0f0a7390
/*  f0a7380:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a7384:	10000002 */ 	beqz	$zero,.L0f0a7390
/*  f0a7388:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a738c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0a7390:
/*  f0a7390:	8e390068 */ 	lw	$t9,0x68($s1)
/*  f0a7394:	53200004 */ 	beqzl	$t9,.L0f0a73a8
/*  f0a7398:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a739c:	10000002 */ 	beqz	$zero,.L0f0a73a8
/*  f0a73a0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a73a4:	00002025 */ 	or	$a0,$zero,$zero
.L0f0a73a8:
/*  f0a73a8:	8e2d0064 */ 	lw	$t5,0x64($s1)
/*  f0a73ac:	51a00004 */ 	beqzl	$t5,.L0f0a73c0
/*  f0a73b0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a73b4:	10000002 */ 	beqz	$zero,.L0f0a73c0
/*  f0a73b8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a73bc:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a73c0:
/*  f0a73c0:	8e2e0070 */ 	lw	$t6,0x70($s1)
/*  f0a73c4:	51c00004 */ 	beqzl	$t6,.L0f0a73d8
/*  f0a73c8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a73cc:	10000002 */ 	beqz	$zero,.L0f0a73d8
/*  f0a73d0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a73d4:	00001825 */ 	or	$v1,$zero,$zero
.L0f0a73d8:
/*  f0a73d8:	00627821 */ 	addu	$t7,$v1,$v0
/*  f0a73dc:	01e46021 */ 	addu	$t4,$t7,$a0
/*  f0a73e0:	01854821 */ 	addu	$t1,$t4,$a1
/*  f0a73e4:	15210008 */ 	bne	$t1,$at,.L0f0a7408
/*  f0a73e8:	3c088009 */ 	lui	$t0,0x8009
/*  f0a73ec:	91080af0 */ 	lbu	$t0,0xaf0($t0)
/*  f0a73f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a73f4:	51010005 */ 	beql	$t0,$at,.L0f0a740c
/*  f0a73f8:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a73fc:	0fc2be93 */ 	jal	func0f0afa4c
/*  f0a7400:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a7404:	afa2014c */ 	sw	$v0,0x14c($sp)
.L0f0a7408:
/*  f0a7408:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0a740c:
/*  f0a740c:	26700638 */ 	addiu	$s0,$s3,0x638
/*  f0a7410:	8fb500e4 */ 	lw	$s5,0xe4($sp)
/*  f0a7414:	24120019 */ 	addiu	$s2,$zero,0x19
.L0f0a7418:
/*  f0a7418:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f0a741c:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a7420:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f0a7424:	820a0007 */ 	lb	$t2,0x7($s0)
/*  f0a7428:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a742c:	260501dc */ 	addiu	$a1,$s0,0x1dc
/*  f0a7430:	114001f2 */ 	beqz	$t2,.L0f0a7bfc
/*  f0a7434:	00003025 */ 	or	$a2,$zero,$zero
/*  f0a7438:	26180384 */ 	addiu	$t8,$s0,0x384
/*  f0a743c:	afb8003c */ 	sw	$t8,0x3c($sp)
/*  f0a7440:	0fc2b2e4 */ 	jal	func0f0acb90
/*  f0a7444:	00003825 */ 	or	$a3,$zero,$zero
/*  f0a7448:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a744c:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f0a7450:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a7454:	34058000 */ 	dli	$a1,0x8000
/*  f0a7458:	10400030 */ 	beqz	$v0,.L0f0a751c
/*  f0a745c:	8fab014c */ 	lw	$t3,0x14c($sp)
/*  f0a7460:	25790008 */ 	addiu	$t9,$t3,0x8
/*  f0a7464:	afb9014c */ 	sw	$t9,0x14c($sp)
/*  f0a7468:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f0a746c:	3c0e8000 */ 	lui	$t6,0x8000
/*  f0a7470:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f0a7474:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f0a7478:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f0a747c:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f0a7480:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0a7484:	3c090386 */ 	lui	$t1,0x386
/*  f0a7488:	3c088007 */ 	lui	$t0,%hi(var80070098)
/*  f0a748c:	25ec0008 */ 	addiu	$t4,$t7,0x8
/*  f0a7490:	afac014c */ 	sw	$t4,0x14c($sp)
/*  f0a7494:	25080098 */ 	addiu	$t0,$t0,%lo(var80070098)
/*  f0a7498:	35290010 */ 	ori	$t1,$t1,0x10
/*  f0a749c:	ade90000 */ 	sw	$t1,0x0($t7)
/*  f0a74a0:	ade80004 */ 	sw	$t0,0x4($t7)
/*  f0a74a4:	8faa014c */ 	lw	$t2,0x14c($sp)
/*  f0a74a8:	3c0b0388 */ 	lui	$t3,0x388
/*  f0a74ac:	3c198007 */ 	lui	$t9,%hi(var80070090)
/*  f0a74b0:	25580008 */ 	addiu	$t8,$t2,0x8
/*  f0a74b4:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f0a74b8:	27390090 */ 	addiu	$t9,$t9,%lo(var80070090)
/*  f0a74bc:	356b0010 */ 	ori	$t3,$t3,0x10
/*  f0a74c0:	ad4b0000 */ 	sw	$t3,0x0($t2)
/*  f0a74c4:	ad590004 */ 	sw	$t9,0x4($t2)
/*  f0a74c8:	8fad014c */ 	lw	$t5,0x14c($sp)
/*  f0a74cc:	3c0f0384 */ 	lui	$t7,0x384
/*  f0a74d0:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f0a74d4:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0a74d8:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f0a74dc:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0a74e0:	0fc2d5ea */ 	jal	func0f0b57a8
/*  f0a74e4:	afad00d4 */ 	sw	$t5,0xd4($sp)
/*  f0a74e8:	8fa500d4 */ 	lw	$a1,0xd4($sp)
/*  f0a74ec:	3c080382 */ 	lui	$t0,0x382
/*  f0a74f0:	35080010 */ 	ori	$t0,$t0,0x10
/*  f0a74f4:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0a74f8:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f0a74fc:	25890008 */ 	addiu	$t1,$t4,0x8
/*  f0a7500:	afa9014c */ 	sw	$t1,0x14c($sp)
/*  f0a7504:	ad880000 */ 	sw	$t0,0x0($t4)
/*  f0a7508:	0fc2d5ea */ 	jal	func0f0b57a8
/*  f0a750c:	afac00d0 */ 	sw	$t4,0xd0($sp)
/*  f0a7510:	8fa300d0 */ 	lw	$v1,0xd0($sp)
/*  f0a7514:	244a0010 */ 	addiu	$t2,$v0,0x10
/*  f0a7518:	ac6a0004 */ 	sw	$t2,0x4($v1)
.L0f0a751c:
/*  f0a751c:	8fb8014c */ 	lw	$t8,0x14c($sp)
/*  f0a7520:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f0a7524:	3739000e */ 	ori	$t9,$t9,0xe
/*  f0a7528:	270b0008 */ 	addiu	$t3,$t8,0x8
/*  f0a752c:	afab014c */ 	sw	$t3,0x14c($sp)
/*  f0a7530:	3c014396 */ 	lui	$at,0x4396
/*  f0a7534:	44817000 */ 	mtc1	$at,$f14
/*  f0a7538:	44806000 */ 	mtc1	$zero,$f12
/*  f0a753c:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0a7540:	0c005b73 */ 	jal	func00016dcc
/*  f0a7544:	afb800cc */ 	sw	$t8,0xcc($sp)
/*  f0a7548:	8fa300cc */ 	lw	$v1,0xcc($sp)
/*  f0a754c:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f0a7550:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0a7554:	0c006a47 */ 	jal	func0001a91c
/*  f0a7558:	8e04038c */ 	lw	$a0,0x38c($s0)
/*  f0a755c:	10400014 */ 	beqz	$v0,.L0f0a75b0
/*  f0a7560:	afa200e8 */ 	sw	$v0,0xe8($sp)
/*  f0a7564:	8e04038c */ 	lw	$a0,0x38c($s0)
/*  f0a7568:	0c006a47 */ 	jal	func0001a91c
/*  f0a756c:	24050011 */ 	addiu	$a1,$zero,0x11
/*  f0a7570:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0a7574:	0c006a87 */ 	jal	func0001aa1c
/*  f0a7578:	00402825 */ 	or	$a1,$v0,$zero
/*  f0a757c:	10400003 */ 	beqz	$v0,.L0f0a758c
/*  f0a7580:	3c06800a */ 	lui	$a2,%hi(var8009cf88)
/*  f0a7584:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0a7588:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L0f0a758c:
/*  f0a758c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0a7590:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0a7594:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0a7598:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0a759c:	24c6cf88 */ 	addiu	$a2,$a2,%lo(var8009cf88)
/*  f0a75a0:	8fa7014c */ 	lw	$a3,0x14c($sp)
/*  f0a75a4:	0fc1fefe */ 	jal	func0f07fbf8
/*  f0a75a8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0a75ac:	afa2014c */ 	sw	$v0,0x14c($sp)
.L0f0a75b0:
/*  f0a75b0:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0a75b4:	8e250284 */ 	lw	$a1,0x284($s1)
/*  f0a75b8:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f0a75bc:	afac013c */ 	sw	$t4,0x13c($sp)
/*  f0a75c0:	afaf0118 */ 	sw	$t7,0x118($sp)
/*  f0a75c4:	8ca300d8 */ 	lw	$v1,0xd8($a1)
/*  f0a75c8:	3c078007 */ 	lui	$a3,0x8007
/*  f0a75cc:	14600013 */ 	bnez	$v1,.L0f0a761c
/*  f0a75d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a75d4:	8ce70764 */ 	lw	$a3,0x764($a3)
/*  f0a75d8:	14e00010 */ 	bnez	$a3,.L0f0a761c
/*  f0a75dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a75e0:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a75e4:	50400007 */ 	beqzl	$v0,.L0f0a7604
/*  f0a75e8:	8caa1c54 */ 	lw	$t2,0x1c54($a1)
/*  f0a75ec:	1040000b */ 	beqz	$v0,.L0f0a761c
/*  f0a75f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a75f4:	80490037 */ 	lb	$t1,0x37($v0)
/*  f0a75f8:	15200008 */ 	bnez	$t1,.L0f0a761c
/*  f0a75fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7600:	8caa1c54 */ 	lw	$t2,0x1c54($a1)
.L0f0a7604:
/*  f0a7604:	8ca800c4 */ 	lw	$t0,0xc4($a1)
/*  f0a7608:	0140c027 */ 	nor	$t8,$t2,$zero
/*  f0a760c:	01185824 */ 	and	$t3,$t0,$t8
/*  f0a7610:	31790001 */ 	andi	$t9,$t3,0x1
/*  f0a7614:	57200016 */ 	bnezl	$t9,.L0f0a7670
/*  f0a7618:	92681615 */ 	lbu	$t0,0x1615($s3)
.L0f0a761c:
/*  f0a761c:	14600078 */ 	bnez	$v1,.L0f0a7800
/*  f0a7620:	3c078007 */ 	lui	$a3,0x8007
/*  f0a7624:	8ce70764 */ 	lw	$a3,0x764($a3)
/*  f0a7628:	54e00076 */ 	bnezl	$a3,.L0f0a7804
/*  f0a762c:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a7630:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a7634:	50400007 */ 	beqzl	$v0,.L0f0a7654
/*  f0a7638:	8caf1c54 */ 	lw	$t7,0x1c54($a1)
/*  f0a763c:	50400071 */ 	beqzl	$v0,.L0f0a7804
/*  f0a7640:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a7644:	804d0037 */ 	lb	$t5,0x37($v0)
/*  f0a7648:	55a0006e */ 	bnezl	$t5,.L0f0a7804
/*  f0a764c:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a7650:	8caf1c54 */ 	lw	$t7,0x1c54($a1)
.L0f0a7654:
/*  f0a7654:	8cae00c4 */ 	lw	$t6,0xc4($a1)
/*  f0a7658:	01e06027 */ 	nor	$t4,$t7,$zero
/*  f0a765c:	01cc4824 */ 	and	$t1,$t6,$t4
/*  f0a7660:	312a0008 */ 	andi	$t2,$t1,0x8
/*  f0a7664:	51400067 */ 	beqzl	$t2,.L0f0a7804
/*  f0a7668:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a766c:	92681615 */ 	lbu	$t0,0x1615($s3)
.L0f0a7670:
/*  f0a7670:	92781614 */ 	lbu	$t8,0x1614($s3)
/*  f0a7674:	26641614 */ 	addiu	$a0,$s3,0x1614
/*  f0a7678:	0118082a */ 	slt	$at,$t0,$t8
/*  f0a767c:	50200009 */ 	beqzl	$at,.L0f0a76a4
/*  f0a7680:	90820002 */ 	lbu	$v0,0x2($a0)
/*  f0a7684:	90830000 */ 	lbu	$v1,0x0($a0)
/*  f0a7688:	908b0002 */ 	lbu	$t3,0x2($a0)
/*  f0a768c:	0163082a */ 	slt	$at,$t3,$v1
/*  f0a7690:	50200004 */ 	beqzl	$at,.L0f0a76a4
/*  f0a7694:	90820002 */ 	lbu	$v0,0x2($a0)
/*  f0a7698:	1000000a */ 	beqz	$zero,.L0f0a76c4
/*  f0a769c:	00601025 */ 	or	$v0,$v1,$zero
/*  f0a76a0:	90820002 */ 	lbu	$v0,0x2($a0)
.L0f0a76a4:
/*  f0a76a4:	90860001 */ 	lbu	$a2,0x1($a0)
/*  f0a76a8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0a76ac:	0046082a */ 	slt	$at,$v0,$a2
/*  f0a76b0:	10200003 */ 	beqz	$at,.L0f0a76c0
/*  f0a76b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a76b8:	10000001 */ 	beqz	$zero,.L0f0a76c0
/*  f0a76bc:	00c01825 */ 	or	$v1,$a2,$zero
.L0f0a76c0:
/*  f0a76c0:	00601025 */ 	or	$v0,$v1,$zero
.L0f0a76c4:
/*  f0a76c4:	90890003 */ 	lbu	$t1,0x3($a0)
/*  f0a76c8:	0002ce00 */ 	sll	$t9,$v0,0x18
/*  f0a76cc:	00026c00 */ 	sll	$t5,$v0,0x10
/*  f0a76d0:	032d7825 */ 	or	$t7,$t9,$t5
/*  f0a76d4:	00027200 */ 	sll	$t6,$v0,0x8
/*  f0a76d8:	01ee6025 */ 	or	$t4,$t7,$t6
/*  f0a76dc:	012c5021 */ 	addu	$t2,$t1,$t4
/*  f0a76e0:	afaa0140 */ 	sw	$t2,0x140($sp)
/*  f0a76e4:	8ca300d8 */ 	lw	$v1,0xd8($a1)
/*  f0a76e8:	14600021 */ 	bnez	$v1,.L0f0a7770
/*  f0a76ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a76f0:	14e0001f */ 	bnez	$a3,.L0f0a7770
/*  f0a76f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a76f8:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a76fc:	50400007 */ 	beqzl	$v0,.L0f0a771c
/*  f0a7700:	8cab1c54 */ 	lw	$t3,0x1c54($a1)
/*  f0a7704:	1040001a */ 	beqz	$v0,.L0f0a7770
/*  f0a7708:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a770c:	80480037 */ 	lb	$t0,0x37($v0)
/*  f0a7710:	15000017 */ 	bnez	$t0,.L0f0a7770
/*  f0a7714:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7718:	8cab1c54 */ 	lw	$t3,0x1c54($a1)
.L0f0a771c:
/*  f0a771c:	8cb800c4 */ 	lw	$t8,0xc4($a1)
/*  f0a7720:	3c02800a */ 	lui	$v0,0x800a
/*  f0a7724:	0160c827 */ 	nor	$t9,$t3,$zero
/*  f0a7728:	03196824 */ 	and	$t5,$t8,$t9
/*  f0a772c:	31af0001 */ 	andi	$t7,$t5,0x1
/*  f0a7730:	11e0000f */ 	beqz	$t7,.L0f0a7770
/*  f0a7734:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7738:	9042caef */ 	lbu	$v0,-0x3511($v0)
/*  f0a773c:	3c06800a */ 	lui	$a2,0x800a
/*  f0a7740:	90c6caf0 */ 	lbu	$a2,-0x3510($a2)
/*  f0a7744:	00027600 */ 	sll	$t6,$v0,0x18
/*  f0a7748:	00024c00 */ 	sll	$t1,$v0,0x10
/*  f0a774c:	01c96025 */ 	or	$t4,$t6,$t1
/*  f0a7750:	00025200 */ 	sll	$t2,$v0,0x8
/*  f0a7754:	018a4025 */ 	or	$t0,$t4,$t2
/*  f0a7758:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0a775c:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f0a7760:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0a7764:	00c8a821 */ 	addu	$s5,$a2,$t0
/*  f0a7768:	1000001f */ 	beqz	$zero,.L0f0a77e8
/*  f0a776c:	afa600bc */ 	sw	$a2,0xbc($sp)
.L0f0a7770:
/*  f0a7770:	5460001e */ 	bnezl	$v1,.L0f0a77ec
/*  f0a7774:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0a7778:	54e0001c */ 	bnezl	$a3,.L0f0a77ec
/*  f0a777c:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0a7780:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a7784:	50400007 */ 	beqzl	$v0,.L0f0a77a4
/*  f0a7788:	8cb91c54 */ 	lw	$t9,0x1c54($a1)
/*  f0a778c:	50400017 */ 	beqzl	$v0,.L0f0a77ec
/*  f0a7790:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0a7794:	804b0037 */ 	lb	$t3,0x37($v0)
/*  f0a7798:	55600014 */ 	bnezl	$t3,.L0f0a77ec
/*  f0a779c:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0a77a0:	8cb91c54 */ 	lw	$t9,0x1c54($a1)
.L0f0a77a4:
/*  f0a77a4:	8cb800c4 */ 	lw	$t8,0xc4($a1)
/*  f0a77a8:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f0a77ac:	03206827 */ 	nor	$t5,$t9,$zero
/*  f0a77b0:	030d7824 */ 	and	$t7,$t8,$t5
/*  f0a77b4:	31ee0008 */ 	andi	$t6,$t7,0x8
/*  f0a77b8:	11c0000b */ 	beqz	$t6,.L0f0a77e8
/*  f0a77bc:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f0a77c0:	00024e00 */ 	sll	$t1,$v0,0x18
/*  f0a77c4:	00006400 */ 	sll	$t4,$zero,0x10
/*  f0a77c8:	012c5025 */ 	or	$t2,$t1,$t4
/*  f0a77cc:	00004200 */ 	sll	$t0,$zero,0x8
/*  f0a77d0:	01485825 */ 	or	$t3,$t2,$t0
/*  f0a77d4:	00aba821 */ 	addu	$s5,$a1,$t3
/*  f0a77d8:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0a77dc:	afa000a4 */ 	sw	$zero,0xa4($sp)
/*  f0a77e0:	afa000a8 */ 	sw	$zero,0xa8($sp)
/*  f0a77e4:	afa500ac */ 	sw	$a1,0xac($sp)
.L0f0a77e8:
/*  f0a77e8:	8fb900ec */ 	lw	$t9,0xec($sp)
.L0f0a77ec:
/*  f0a77ec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a77f0:	5721003d */ 	bnel	$t9,$at,.L0f0a78e8
/*  f0a77f4:	8e6f00bc */ 	lw	$t7,0xbc($s3)
/*  f0a77f8:	1000003a */ 	beqz	$zero,.L0f0a78e4
/*  f0a77fc:	afb50140 */ 	sw	$s5,0x140($sp)
.L0f0a7800:
/*  f0a7800:	926d1614 */ 	lbu	$t5,0x1614($s3)
.L0f0a7804:
/*  f0a7804:	92781617 */ 	lbu	$t8,0x1617($s3)
/*  f0a7808:	92691615 */ 	lbu	$t1,0x1615($s3)
/*  f0a780c:	92681616 */ 	lbu	$t0,0x1616($s3)
/*  f0a7810:	000d7e00 */ 	sll	$t7,$t5,0x18
/*  f0a7814:	030f7025 */ 	or	$t6,$t8,$t7
/*  f0a7818:	00096400 */ 	sll	$t4,$t1,0x10
/*  f0a781c:	01cc5025 */ 	or	$t2,$t6,$t4
/*  f0a7820:	00085a00 */ 	sll	$t3,$t0,0x8
/*  f0a7824:	014bc825 */ 	or	$t9,$t2,$t3
/*  f0a7828:	afb90140 */ 	sw	$t9,0x140($sp)
/*  f0a782c:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f0a7830:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a7834:	0320a825 */ 	or	$s5,$t9,$zero
/*  f0a7838:	15a1002a */ 	bne	$t5,$at,.L0f0a78e4
/*  f0a783c:	3c04ff00 */ 	lui	$a0,0xff00
/*  f0a7840:	3c014248 */ 	lui	$at,0x4248
/*  f0a7844:	44812000 */ 	mtc1	$at,$f4
/*  f0a7848:	c612023c */ 	lwc1	$f18,0x23c($s0)
/*  f0a784c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a7850:	3c014f00 */ 	lui	$at,0x4f00
/*  f0a7854:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0a7858:	3484007f */ 	ori	$a0,$a0,0x7f
/*  f0a785c:	4458f800 */ 	cfc1	$t8,$31
/*  f0a7860:	44c6f800 */ 	ctc1	$a2,$31
/*  f0a7864:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7868:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0a786c:	4446f800 */ 	cfc1	$a2,$31
/*  f0a7870:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7874:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0a7878:	50c00013 */ 	beqzl	$a2,.L0f0a78c8
/*  f0a787c:	44064000 */ 	mfc1	$a2,$f8
/*  f0a7880:	44814000 */ 	mtc1	$at,$f8
/*  f0a7884:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a7888:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0a788c:	44c6f800 */ 	ctc1	$a2,$31
/*  f0a7890:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7894:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0a7898:	4446f800 */ 	cfc1	$a2,$31
/*  f0a789c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a78a0:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0a78a4:	14c00005 */ 	bnez	$a2,.L0f0a78bc
/*  f0a78a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a78ac:	44064000 */ 	mfc1	$a2,$f8
/*  f0a78b0:	3c018000 */ 	lui	$at,0x8000
/*  f0a78b4:	10000007 */ 	beqz	$zero,.L0f0a78d4
/*  f0a78b8:	00c13025 */ 	or	$a2,$a2,$at
.L0f0a78bc:
/*  f0a78bc:	10000005 */ 	beqz	$zero,.L0f0a78d4
/*  f0a78c0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0a78c4:	44064000 */ 	mfc1	$a2,$f8
.L0f0a78c8:
/*  f0a78c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a78cc:	04c0fffb */ 	bltz	$a2,.L0f0a78bc
/*  f0a78d0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a78d4:
/*  f0a78d4:	44d8f800 */ 	ctc1	$t8,$31
/*  f0a78d8:	0fc01a40 */ 	jal	func0f006900
/*  f0a78dc:	03202825 */ 	or	$a1,$t9,$zero
/*  f0a78e0:	afa20140 */ 	sw	$v0,0x140($sp)
.L0f0a78e4:
/*  f0a78e4:	8e6f00bc */ 	lw	$t7,0xbc($s3)
.L0f0a78e8:
/*  f0a78e8:	0fc08af9 */ 	jal	func0f022be4
/*  f0a78ec:	8de40004 */ 	lw	$a0,0x4($t7)
/*  f0a78f0:	284100ff */ 	slti	$at,$v0,0xff
/*  f0a78f4:	1020000f */ 	beqz	$at,.L0f0a7934
/*  f0a78f8:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0a78fc:	44825000 */ 	mtc1	$v0,$f10
/*  f0a7900:	3c017f1b */ 	lui	$at,%hi(var7f1aca90)
/*  f0a7904:	c432ca90 */ 	lwc1	$f18,%lo(var7f1aca90)($at)
/*  f0a7908:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0a790c:	8fa40140 */ 	lw	$a0,0x140($sp)
/*  f0a7910:	240e0005 */ 	addiu	$t6,$zero,0x5
/*  f0a7914:	afae013c */ 	sw	$t6,0x13c($sp)
/*  f0a7918:	afa40144 */ 	sw	$a0,0x144($sp)
/*  f0a791c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0a7920:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a7924:	44033000 */ 	mfc1	$v1,$f6
/*  f0a7928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a792c:	24750041 */ 	addiu	$s5,$v1,0x41
/*  f0a7930:	afb50140 */ 	sw	$s5,0x140($sp)
.L0f0a7934:
/*  f0a7934:	0c0059d8 */ 	jal	func00016760
/*  f0a7938:	afac0110 */ 	sw	$t4,0x110($sp)
/*  f0a793c:	8e020218 */ 	lw	$v0,0x218($s0)
/*  f0a7940:	50400017 */ 	beqzl	$v0,.L0f0a79a0
/*  f0a7944:	8fa400ec */ 	lw	$a0,0xec($sp)
/*  f0a7948:	8c460018 */ 	lw	$a2,0x18($v0)
/*  f0a794c:	afa00094 */ 	sw	$zero,0x94($sp)
/*  f0a7950:	50c00013 */ 	beqzl	$a2,.L0f0a79a0
/*  f0a7954:	8fa400ec */ 	lw	$a0,0xec($sp)
/*  f0a7958:	8cc80008 */ 	lw	$t0,0x8($a2)
/*  f0a795c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0a7960:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0a7964:	1100000d */ 	beqz	$t0,.L0f0a799c
/*  f0a7968:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0a796c:	afaa0094 */ 	sw	$t2,0x94($sp)
/*  f0a7970:	0c0087bd */ 	jal	func00021ef4
/*  f0a7974:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f0a7978:	8fa60098 */ 	lw	$a2,0x98($sp)
/*  f0a797c:	8ccb0008 */ 	lw	$t3,0x8($a2)
/*  f0a7980:	8cc4000c */ 	lw	$a0,0xc($a2)
/*  f0a7984:	0fc30cfc */ 	jal	func0f0c33f0
/*  f0a7988:	8565000e */ 	lh	$a1,0xe($t3)
/*  f0a798c:	8e0d021c */ 	lw	$t5,0x21c($s0)
/*  f0a7990:	51a00003 */ 	beqzl	$t5,.L0f0a79a0
/*  f0a7994:	8fa400ec */ 	lw	$a0,0xec($sp)
/*  f0a7998:	ae000218 */ 	sw	$zero,0x218($s0)
.L0f0a799c:
/*  f0a799c:	8fa400ec */ 	lw	$a0,0xec($sp)
.L0f0a79a0:
/*  f0a79a0:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a79a4:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f0a79a8:	1040000e */ 	beqz	$v0,.L0f0a79e4
/*  f0a79ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a79b0:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f0a79b4:	3c0fb600 */ 	lui	$t7,0xb600
/*  f0a79b8:	24093000 */ 	addiu	$t1,$zero,0x3000
/*  f0a79bc:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0a79c0:	afb90118 */ 	sw	$t9,0x118($sp)
/*  f0a79c4:	af090004 */ 	sw	$t1,0x4($t8)
/*  f0a79c8:	16800004 */ 	bnez	$s4,.L0f0a79dc
/*  f0a79cc:	af0f0000 */ 	sw	$t7,0x0($t8)
/*  f0a79d0:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f0a79d4:	10000003 */ 	beqz	$zero,.L0f0a79e4
/*  f0a79d8:	afae0148 */ 	sw	$t6,0x148($sp)
.L0f0a79dc:
/*  f0a79dc:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f0a79e0:	afac0148 */ 	sw	$t4,0x148($sp)
.L0f0a79e4:
/*  f0a79e4:	8e28006c */ 	lw	$t0,0x6c($s1)
/*  f0a79e8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a79ec:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a79f0:	11000003 */ 	beqz	$t0,.L0f0a7a00
/*  f0a79f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a79f8:	10000001 */ 	beqz	$zero,.L0f0a7a00
/*  f0a79fc:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0a7a00:
/*  f0a7a00:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f0a7a04:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a7a08:	11400003 */ 	beqz	$t2,.L0f0a7a18
/*  f0a7a0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7a10:	10000001 */ 	beqz	$zero,.L0f0a7a18
/*  f0a7a14:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0a7a18:
/*  f0a7a18:	8e2b0064 */ 	lw	$t3,0x64($s1)
/*  f0a7a1c:	11600003 */ 	beqz	$t3,.L0f0a7a2c
/*  f0a7a20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7a24:	10000001 */ 	beqz	$zero,.L0f0a7a2c
/*  f0a7a28:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a7a2c:
/*  f0a7a2c:	8e2d0070 */ 	lw	$t5,0x70($s1)
/*  f0a7a30:	11a00003 */ 	beqz	$t5,.L0f0a7a40
/*  f0a7a34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7a38:	10000001 */ 	beqz	$zero,.L0f0a7a40
/*  f0a7a3c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a7a40:
/*  f0a7a40:	0062c021 */ 	addu	$t8,$v1,$v0
/*  f0a7a44:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0a7a48:	03257821 */ 	addu	$t7,$t9,$a1
/*  f0a7a4c:	15e10036 */ 	bne	$t7,$at,.L0f0a7b28
/*  f0a7a50:	24050041 */ 	addiu	$a1,$zero,0x41
/*  f0a7a54:	0c006a47 */ 	jal	func0001a91c
/*  f0a7a58:	8e04038c */ 	lw	$a0,0x38c($s0)
/*  f0a7a5c:	50400033 */ 	beqzl	$v0,.L0f0a7b2c
/*  f0a7a60:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0a7a64:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0a7a68:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a7a6c:	84890010 */ 	lh	$t1,0x10($a0)
/*  f0a7a70:	5920002e */ 	blezl	$t1,.L0f0a7b2c
/*  f0a7a74:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0a7a78:	8e2a0034 */ 	lw	$t2,0x34($s1)
.L0f0a7a7c:
/*  f0a7a7c:	8c8e000c */ 	lw	$t6,0xc($a0)
/*  f0a7a80:	00056080 */ 	sll	$t4,$a1,0x2
/*  f0a7a84:	01520019 */ 	multu	$t2,$s2
/*  f0a7a88:	01856023 */ 	subu	$t4,$t4,$a1
/*  f0a7a8c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0a7a90:	01cc1021 */ 	addu	$v0,$t6,$t4
/*  f0a7a94:	8448000a */ 	lh	$t0,0xa($v0)
/*  f0a7a98:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f0a7a9c:	0325c823 */ 	subu	$t9,$t9,$a1
/*  f0a7aa0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0a7aa4:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0a7aa8:	00005812 */ 	mflo	$t3
/*  f0a7aac:	010b6823 */ 	subu	$t5,$t0,$t3
/*  f0a7ab0:	a44d0008 */ 	sh	$t5,0x8($v0)
/*  f0a7ab4:	8c98000c */ 	lw	$t8,0xc($a0)
/*  f0a7ab8:	03197821 */ 	addu	$t7,$t8,$t9
/*  f0a7abc:	85e9000a */ 	lh	$t1,0xa($t7)
/*  f0a7ac0:	2921a000 */ 	slti	$at,$t1,-24576
/*  f0a7ac4:	50200014 */ 	beqzl	$at,.L0f0a7b18
/*  f0a7ac8:	84980010 */ 	lh	$t8,0x10($a0)
/*  f0a7acc:	848e0010 */ 	lh	$t6,0x10($a0)
/*  f0a7ad0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a7ad4:	59c00010 */ 	blezl	$t6,.L0f0a7b18
/*  f0a7ad8:	84980010 */ 	lh	$t8,0x10($a0)
/*  f0a7adc:	8c8c000c */ 	lw	$t4,0xc($a0)
.L0f0a7ae0:
/*  f0a7ae0:	00035080 */ 	sll	$t2,$v1,0x2
/*  f0a7ae4:	01435023 */ 	subu	$t2,$t2,$v1
/*  f0a7ae8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0a7aec:	018a1021 */ 	addu	$v0,$t4,$t2
/*  f0a7af0:	8448000a */ 	lh	$t0,0xa($v0)
/*  f0a7af4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0a7af8:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0a7afc:	250b2000 */ 	addiu	$t3,$t0,0x2000
/*  f0a7b00:	a44b0008 */ 	sh	$t3,0x8($v0)
/*  f0a7b04:	848d0010 */ 	lh	$t5,0x10($a0)
/*  f0a7b08:	006d082a */ 	slt	$at,$v1,$t5
/*  f0a7b0c:	5420fff4 */ 	bnezl	$at,.L0f0a7ae0
/*  f0a7b10:	8c8c000c */ 	lw	$t4,0xc($a0)
/*  f0a7b14:	84980010 */ 	lh	$t8,0x10($a0)
.L0f0a7b18:
/*  f0a7b18:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0a7b1c:	00b8082a */ 	slt	$at,$a1,$t8
/*  f0a7b20:	5420ffd6 */ 	bnezl	$at,.L0f0a7a7c
/*  f0a7b24:	8e2a0034 */ 	lw	$t2,0x34($s1)
.L0f0a7b28:
/*  f0a7b28:	27a4010c */ 	addiu	$a0,$sp,0x10c
.L0f0a7b2c:
/*  f0a7b2c:	0c0087bd */ 	jal	func00021ef4
/*  f0a7b30:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0a7b34:	8e791594 */ 	lw	$t9,0x1594($s3)
/*  f0a7b38:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0a7b3c:	53200013 */ 	beqzl	$t9,.L0f0a7b8c
/*  f0a7b40:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f0a7b44:	8def02dc */ 	lw	$t7,0x2dc($t7)
/*  f0a7b48:	8fa90140 */ 	lw	$t1,0x140($sp)
/*  f0a7b4c:	51e0000f */ 	beqzl	$t7,.L0f0a7b8c
/*  f0a7b50:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f0a7b54:	afa9007c */ 	sw	$t1,0x7c($sp)
/*  f0a7b58:	8e0e0390 */ 	lw	$t6,0x390($s0)
/*  f0a7b5c:	26050534 */ 	addiu	$a1,$s0,0x534
/*  f0a7b60:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0a7b64:	ae0e0540 */ 	sw	$t6,0x540($s0)
/*  f0a7b68:	0c007308 */ 	jal	func0001cc20
/*  f0a7b6c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0a7b70:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0a7b74:	afb50140 */ 	sw	$s5,0x140($sp)
/*  f0a7b78:	0c0087bd */ 	jal	func00021ef4
/*  f0a7b7c:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0a7b80:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f0a7b84:	afa40140 */ 	sw	$a0,0x140($sp)
/*  f0a7b88:	8fac0118 */ 	lw	$t4,0x118($sp)
.L0f0a7b8c:
/*  f0a7b8c:	8fa400ec */ 	lw	$a0,0xec($sp)
/*  f0a7b90:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f0a7b94:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a7b98:	afac014c */ 	sw	$t4,0x14c($sp)
/*  f0a7b9c:	10400007 */ 	beqz	$v0,.L0f0a7bbc
/*  f0a7ba0:	8faa014c */ 	lw	$t2,0x14c($sp)
/*  f0a7ba4:	25480008 */ 	addiu	$t0,$t2,0x8
/*  f0a7ba8:	afa8014c */ 	sw	$t0,0x14c($sp)
/*  f0a7bac:	3c0bb600 */ 	lui	$t3,0xb600
/*  f0a7bb0:	240d3000 */ 	addiu	$t5,$zero,0x3000
/*  f0a7bb4:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0a7bb8:	ad4b0000 */ 	sw	$t3,0x0($t2)
.L0f0a7bbc:
/*  f0a7bbc:	8e18038c */ 	lw	$t8,0x38c($s0)
/*  f0a7bc0:	8e040390 */ 	lw	$a0,0x390($s0)
/*  f0a7bc4:	0fc30cfc */ 	jal	func0f0c33f0
/*  f0a7bc8:	8705000e */ 	lh	$a1,0xe($t8)
/*  f0a7bcc:	0c0059e1 */ 	jal	func00016784
/*  f0a7bd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7bd4:	8fb9014c */ 	lw	$t9,0x14c($sp)
/*  f0a7bd8:	3c09bc00 */ 	lui	$t1,0xbc00
/*  f0a7bdc:	3529000e */ 	ori	$t1,$t1,0xe
/*  f0a7be0:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f0a7be4:	afaf014c */ 	sw	$t7,0x14c($sp)
/*  f0a7be8:	af290000 */ 	sw	$t1,0x0($t9)
/*  f0a7bec:	0c002adb */ 	jal	func0000ab6c
/*  f0a7bf0:	afb90074 */ 	sw	$t9,0x74($sp)
/*  f0a7bf4:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f0a7bf8:	ac620004 */ 	sw	$v0,0x4($v1)
.L0f0a7bfc:
/*  f0a7bfc:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0a7c00:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a7c04:	1681fe04 */ 	bne	$s4,$at,.L0f0a7418
/*  f0a7c08:	261007a4 */ 	addiu	$s0,$s0,0x7a4
/*  f0a7c0c:	afb500e4 */ 	sw	$s5,0xe4($sp)
/*  f0a7c10:	0fc2baf8 */ 	jal	func0f0aebe0
/*  f0a7c14:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f0a7c18:	0fc5d8a6 */ 	jal	func0f176298
/*  f0a7c1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7c20:	0fc5d8ab */ 	jal	func0f1762ac
/*  f0a7c24:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a7c28:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a7c2c:	0c002c74 */ 	jal	func0000b1d0
/*  f0a7c30:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a7c34:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f0a7c38:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f0a7c3c:	0c002f40 */ 	jal	func0000bd00
/*  f0a7c40:	00408825 */ 	or	$s1,$v0,$zero
/*  f0a7c44:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a7c48:	00106403 */ 	sra	$t4,$s0,0x10
/*  f0a7c4c:	0c002f44 */ 	jal	func0000bd10
/*  f0a7c50:	01808025 */ 	or	$s0,$t4,$zero
/*  f0a7c54:	44824000 */ 	mtc1	$v0,$f8
/*  f0a7c58:	44902000 */ 	mtc1	$s0,$f4
/*  f0a7c5c:	3c014080 */ 	lui	$at,0x4080
/*  f0a7c60:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0a7c64:	44810000 */ 	mtc1	$at,$f0
/*  f0a7c68:	3c01ed00 */ 	lui	$at,0xed00
/*  f0a7c6c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a7c70:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0a7c74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7c78:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a7c7c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0a7c80:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0a7c84:	44089000 */ 	mfc1	$t0,$f18
/*  f0a7c88:	44195000 */ 	mfc1	$t9,$f10
/*  f0a7c8c:	310b0fff */ 	andi	$t3,$t0,0xfff
/*  f0a7c90:	01616825 */ 	or	$t5,$t3,$at
/*  f0a7c94:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f0a7c98:	000f4b00 */ 	sll	$t1,$t7,0xc
/*  f0a7c9c:	01a97025 */ 	or	$t6,$t5,$t1
/*  f0a7ca0:	0c002f22 */ 	jal	func0000bc88
/*  f0a7ca4:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f0a7ca8:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0a7cac:	00126403 */ 	sra	$t4,$s2,0x10
/*  f0a7cb0:	0c002f40 */ 	jal	func0000bd00
/*  f0a7cb4:	01809025 */ 	or	$s2,$t4,$zero
/*  f0a7cb8:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f0a7cbc:	00145403 */ 	sra	$t2,$s4,0x10
/*  f0a7cc0:	0c002f44 */ 	jal	func0000bd10
/*  f0a7cc4:	0140a025 */ 	or	$s4,$t2,$zero
/*  f0a7cc8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a7ccc:	00104403 */ 	sra	$t0,$s0,0x10
/*  f0a7cd0:	0c002f26 */ 	jal	func0000bc98
/*  f0a7cd4:	01008025 */ 	or	$s0,$t0,$zero
/*  f0a7cd8:	00505821 */ 	addu	$t3,$v0,$s0
/*  f0a7cdc:	448b8000 */ 	mtc1	$t3,$f16
/*  f0a7ce0:	02926821 */ 	addu	$t5,$s4,$s2
/*  f0a7ce4:	448d5000 */ 	mtc1	$t5,$f10
/*  f0a7ce8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a7cec:	3c014080 */ 	lui	$at,0x4080
/*  f0a7cf0:	44812000 */ 	mtc1	$at,$f4
/*  f0a7cf4:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0a7cf8:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0a7cfc:	44819000 */ 	mtc1	$at,$f18
/*  f0a7d00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7d04:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0a7d08:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0a7d0c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a7d10:	44194000 */ 	mfc1	$t9,$f8
/*  f0a7d14:	440e3000 */ 	mfc1	$t6,$f6
/*  f0a7d18:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f0a7d1c:	31cc0fff */ 	andi	$t4,$t6,0xfff
/*  f0a7d20:	000c5300 */ 	sll	$t2,$t4,0xc
/*  f0a7d24:	01ea4025 */ 	or	$t0,$t7,$t2
/*  f0a7d28:	ae280004 */ 	sw	$t0,0x4($s1)
/*  f0a7d2c:	8fb80150 */ 	lw	$t8,0x150($sp)
/*  f0a7d30:	8fab014c */ 	lw	$t3,0x14c($sp)
/*  f0a7d34:	af0b0000 */ 	sw	$t3,0x0($t8)
/*  f0a7d38:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0a7d3c:
/*  f0a7d3c:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0a7d40:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0a7d44:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f0a7d48:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f0a7d4c:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f0a7d50:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f0a7d54:	03e00008 */ 	jr	$ra
/*  f0a7d58:	27bd0150 */ 	addiu	$sp,$sp,0x150
);

GLOBAL_ASM(
glabel func0f0a7d5c
/*  f0a7d5c:	3c03800a */ 	lui	$v1,%hi(var8009d0e0)
/*  f0a7d60:	3c02800a */ 	lui	$v0,%hi(var8009d0f0)
/*  f0a7d64:	2442d0f0 */ 	addiu	$v0,$v0,%lo(var8009d0f0)
/*  f0a7d68:	2463d0e0 */ 	addiu	$v1,$v1,%lo(var8009d0e0)
/*  f0a7d6c:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f0a7d70:
/*  f0a7d70:	55c00004 */ 	bnezl	$t6,.L0f0a7d84
/*  f0a7d74:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0a7d78:	03e00008 */ 	jr	$ra
/*  f0a7d7c:	00601025 */ 	or	$v0,$v1,$zero
/*  f0a7d80:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f0a7d84:
/*  f0a7d84:	5462fffa */ 	bnel	$v1,$v0,.L0f0a7d70
/*  f0a7d88:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0a7d8c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a7d90:	03e00008 */ 	jr	$ra
/*  f0a7d94:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a7d98
/*  f0a7d98:	27bdff38 */ 	addiu	$sp,$sp,-200
/*  f0a7d9c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0a7da0:	afa500cc */ 	sw	$a1,0xcc($sp)
/*  f0a7da4:	afa600d0 */ 	sw	$a2,0xd0($sp)
/*  f0a7da8:	0c004b70 */ 	jal	random
/*  f0a7dac:	afa400c8 */ 	sw	$a0,0xc8($sp)
/*  f0a7db0:	0c004b70 */ 	jal	random
/*  f0a7db4:	afa200c4 */ 	sw	$v0,0xc4($sp)
/*  f0a7db8:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a7dbc:	8dce9ff4 */ 	lw	$t6,-0x600c($t6)
/*  f0a7dc0:	8fa700c8 */ 	lw	$a3,0xc8($sp)
/*  f0a7dc4:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0a7dc8:	19c0018a */ 	blez	$t6,.L0f0a83f4
/*  f0a7dcc:	8fa300d0 */ 	lw	$v1,0xd0($sp)
/*  f0a7dd0:	0460000f */ 	bltz	$v1,.L0f0a7e10
/*  f0a7dd4:	28610daf */ 	slti	$at,$v1,0xdaf
/*  f0a7dd8:	1020000d */ 	beqz	$at,.L0f0a7e10
/*  f0a7ddc:	3c0f800b */ 	lui	$t7,0x800b
/*  f0a7de0:	8defabc0 */ 	lw	$t7,-0x5440($t7)
/*  f0a7de4:	0003c0c0 */ 	sll	$t8,$v1,0x3
/*  f0a7de8:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0a7dec:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0a7df0:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f0a7df4:	00084f02 */ 	srl	$t1,$t0,0x1c
/*  f0a7df8:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0a7dfc:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0a7e00:	8d6b4458 */ 	lw	$t3,0x4458($t3)
/*  f0a7e04:	856c0008 */ 	lh	$t4,0x8($t3)
/*  f0a7e08:	5180017b */ 	beqzl	$t4,.L0f0a83f8
/*  f0a7e0c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f0a7e10:
/*  f0a7e10:	90e20000 */ 	lbu	$v0,0x0($a3)
/*  f0a7e14:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0a7e18:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a7e1c:	1041000d */ 	beq	$v0,$at,.L0f0a7e54
/*  f0a7e20:	8fa500cc */ 	lw	$a1,0xcc($sp)
/*  f0a7e24:	24010021 */ 	addiu	$at,$zero,0x21
/*  f0a7e28:	1041000a */ 	beq	$v0,$at,.L0f0a7e54
/*  f0a7e2c:	24010020 */ 	addiu	$at,$zero,0x20
/*  f0a7e30:	10410008 */ 	beq	$v0,$at,.L0f0a7e54
/*  f0a7e34:	2401003d */ 	addiu	$at,$zero,0x3d
/*  f0a7e38:	10410006 */ 	beq	$v0,$at,.L0f0a7e54
/*  f0a7e3c:	2401003e */ 	addiu	$at,$zero,0x3e
/*  f0a7e40:	10410004 */ 	beq	$v0,$at,.L0f0a7e54
/*  f0a7e44:	2401003f */ 	addiu	$at,$zero,0x3f
/*  f0a7e48:	10410002 */ 	beq	$v0,$at,.L0f0a7e54
/*  f0a7e4c:	24010035 */ 	addiu	$at,$zero,0x35
/*  f0a7e50:	14410014 */ 	bne	$v0,$at,.L0f0a7ea4
.L0f0a7e54:
/*  f0a7e54:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a7e58:	44810000 */ 	mtc1	$at,$f0
/*  f0a7e5c:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0a7e60:	240effff */ 	addiu	$t6,$zero,-1
/*  f0a7e64:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f0a7e68:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0a7e6c:	240680aa */ 	addiu	$a2,$zero,-32598
/*  f0a7e70:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a7e74:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0a7e78:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0a7e7c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0a7e80:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0a7e84:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0a7e88:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0a7e8c:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0a7e90:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0a7e94:	0fc24e7e */ 	jal	func0f0939f8
/*  f0a7e98:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0a7e9c:	10000156 */ 	beqz	$zero,.L0f0a83f8
/*  f0a7ea0:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f0a7ea4:
/*  f0a7ea4:	0fc29f57 */ 	jal	func0f0a7d5c
/*  f0a7ea8:	afa700c8 */ 	sw	$a3,0xc8($sp)
/*  f0a7eac:	8fa700c8 */ 	lw	$a3,0xc8($sp)
/*  f0a7eb0:	104000fa */ 	beqz	$v0,.L0f0a829c
/*  f0a7eb4:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0a7eb8:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*  f0a7ebc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0a7ec0:	8fb800cc */ 	lw	$t8,0xcc($sp)
/*  f0a7ec4:	91e20000 */ 	lbu	$v0,0x0($t7)
/*  f0a7ec8:	10410003 */ 	beq	$v0,$at,.L0f0a7ed8
/*  f0a7ecc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a7ed0:	14410077 */ 	bne	$v0,$at,.L0f0a80b0
/*  f0a7ed4:	240bffff */ 	addiu	$t3,$zero,-1
.L0f0a7ed8:
/*  f0a7ed8:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f0a7edc:	afa000b0 */ 	sw	$zero,0xb0($sp)
/*  f0a7ee0:	0fc0cfe8 */ 	jal	chrGetShield
/*  f0a7ee4:	afa700c8 */ 	sw	$a3,0xc8($sp)
/*  f0a7ee8:	44802000 */ 	mtc1	$zero,$f4
/*  f0a7eec:	8fa700c8 */ 	lw	$a3,0xc8($sp)
/*  f0a7ef0:	24190064 */ 	addiu	$t9,$zero,0x64
/*  f0a7ef4:	4600203c */ 	c.lt.s	$f4,$f0
/*  f0a7ef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7efc:	45020004 */ 	bc1fl	.L0f0a7f10
/*  f0a7f00:	90e20000 */ 	lbu	$v0,0x0($a3)
/*  f0a7f04:	10000036 */ 	beqz	$zero,.L0f0a7fe0
/*  f0a7f08:	a7b900b6 */ 	sh	$t9,0xb6($sp)
/*  f0a7f0c:	90e20000 */ 	lbu	$v0,0x0($a3)
.L0f0a7f10:
/*  f0a7f10:	2404001a */ 	addiu	$a0,$zero,0x1a
/*  f0a7f14:	240805f6 */ 	addiu	$t0,$zero,0x5f6
/*  f0a7f18:	10820005 */ 	beq	$a0,$v0,.L0f0a7f30
/*  f0a7f1c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0a7f20:	10820003 */ 	beq	$a0,$v0,.L0f0a7f30
/*  f0a7f24:	24010056 */ 	addiu	$at,$zero,0x56
/*  f0a7f28:	14410004 */ 	bne	$v0,$at,.L0f0a7f3c
/*  f0a7f2c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a7f30:
/*  f0a7f30:	a7a800b6 */ 	sh	$t0,0xb6($sp)
/*  f0a7f34:	1000002a */ 	beqz	$zero,.L0f0a7fe0
/*  f0a7f38:	afa900b0 */ 	sw	$t1,0xb0($sp)
.L0f0a7f3c:
/*  f0a7f3c:	1062000e */ 	beq	$v1,$v0,.L0f0a7f78
/*  f0a7f40:	3c0b8007 */ 	lui	$t3,%hi(var800702e0)
/*  f0a7f44:	90ea0003 */ 	lbu	$t2,0x3($a3)
/*  f0a7f48:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a7f4c:	146a0019 */ 	bne	$v1,$t2,.L0f0a7fb4
/*  f0a7f50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a7f54:	10410008 */ 	beq	$v0,$at,.L0f0a7f78
/*  f0a7f58:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0a7f5c:	10410006 */ 	beq	$v0,$at,.L0f0a7f78
/*  f0a7f60:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0a7f64:	10410004 */ 	beq	$v0,$at,.L0f0a7f78
/*  f0a7f68:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0a7f6c:	10410002 */ 	beq	$v0,$at,.L0f0a7f78
/*  f0a7f70:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0a7f74:	1441000f */ 	bne	$v0,$at,.L0f0a7fb4
.L0f0a7f78:
/*  f0a7f78:	256b02e0 */ 	addiu	$t3,$t3,%lo(var800702e0)
/*  f0a7f7c:	8d610000 */ 	lw	$at,0x0($t3)
/*  f0a7f80:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f0a7f84:	ac410000 */ 	sw	$at,0x0($v0)
/*  f0a7f88:	95610004 */ 	lhu	$at,0x4($t3)
/*  f0a7f8c:	a4410004 */ 	sh	$at,0x4($v0)
/*  f0a7f90:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f0a7f94:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0a7f98:	01c1001b */ 	divu	$zero,$t6,$at
/*  f0a7f9c:	00007810 */ 	mfhi	$t7
/*  f0a7fa0:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f0a7fa4:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f0a7fa8:	87280000 */ 	lh	$t0,0x0($t9)
/*  f0a7fac:	1000000c */ 	beqz	$zero,.L0f0a7fe0
/*  f0a7fb0:	a7a800b6 */ 	sh	$t0,0xb6($sp)
.L0f0a7fb4:
/*  f0a7fb4:	3c098007 */ 	lui	$t1,%hi(var800702e8)
/*  f0a7fb8:	252902e8 */ 	addiu	$t1,$t1,%lo(var800702e8)
/*  f0a7fbc:	8d210000 */ 	lw	$at,0x0($t1)
/*  f0a7fc0:	27a2009c */ 	addiu	$v0,$sp,0x9c
/*  f0a7fc4:	ac410000 */ 	sw	$at,0x0($v0)
/*  f0a7fc8:	8fad00c4 */ 	lw	$t5,0xc4($sp)
/*  f0a7fcc:	31ae0001 */ 	andi	$t6,$t5,0x1
/*  f0a7fd0:	000e7840 */ 	sll	$t7,$t6,0x1
/*  f0a7fd4:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0a7fd8:	87190000 */ 	lh	$t9,0x0($t8)
/*  f0a7fdc:	a7b900b6 */ 	sh	$t9,0xb6($sp)
.L0f0a7fe0:
/*  f0a7fe0:	87a800b6 */ 	lh	$t0,0xb6($sp)
/*  f0a7fe4:	8fac00cc */ 	lw	$t4,0xcc($sp)
/*  f0a7fe8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0a7fec:	1101002b */ 	beq	$t0,$at,.L0f0a809c
/*  f0a7ff0:	25840008 */ 	addiu	$a0,$t4,0x8
/*  f0a7ff4:	27aa00a8 */ 	addiu	$t2,$sp,0xa8
/*  f0a7ff8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0a7ffc:	25850028 */ 	addiu	$a1,$t4,0x28
/*  f0a8000:	01003025 */ 	or	$a2,$t0,$zero
/*  f0a8004:	0fc253bd */ 	jal	func0f094ef4
/*  f0a8008:	27a700ac */ 	addiu	$a3,$sp,0xac
/*  f0a800c:	8fa900ac */ 	lw	$t1,0xac($sp)
/*  f0a8010:	3c048009 */ 	lui	$a0,0x8009
/*  f0a8014:	87a500b6 */ 	lh	$a1,0xb6($sp)
/*  f0a8018:	11200020 */ 	beqz	$t1,.L0f0a809c
/*  f0a801c:	8fa600bc */ 	lw	$a2,0xbc($sp)
/*  f0a8020:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a8024:	44813000 */ 	mtc1	$at,$f6
/*  f0a8028:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0a802c:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0a8030:	240effff */ 	addiu	$t6,$zero,-1
/*  f0a8034:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0a8038:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0a803c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0a8040:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0a8044:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a8048:	0c004241 */ 	jal	func00010904
/*  f0a804c:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0a8050:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*  f0a8054:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a8058:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0a805c:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0a8060:	8fa700a8 */ 	lw	$a3,0xa8($sp)
/*  f0a8064:	87b900b6 */ 	lh	$t9,0xb6($sp)
/*  f0a8068:	1300000c */ 	beqz	$t8,.L0f0a809c
/*  f0a806c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0a8070:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a8074:	44814000 */ 	mtc1	$at,$f8
/*  f0a8078:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0a807c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0a8080:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0a8084:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0a8088:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0a808c:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0a8090:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0a8094:	0c004128 */ 	jal	func000104a0
/*  f0a8098:	e7a80014 */ 	swc1	$f8,0x14($sp)
.L0f0a809c:
/*  f0a809c:	8fa900b0 */ 	lw	$t1,0xb0($sp)
/*  f0a80a0:	5120007f */ 	beqzl	$t1,.L0f0a82a0
/*  f0a80a4:	8fa200d0 */ 	lw	$v0,0xd0($sp)
/*  f0a80a8:	100000d3 */ 	beqz	$zero,.L0f0a83f8
/*  f0a80ac:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f0a80b0:
/*  f0a80b0:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*  f0a80b4:	24012710 */ 	addiu	$at,$zero,0x2710
/*  f0a80b8:	a7ab009a */ 	sh	$t3,0x9a($sp)
/*  f0a80bc:	15a10004 */ 	bne	$t5,$at,.L0f0a80d0
/*  f0a80c0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a80c4:	240e0064 */ 	addiu	$t6,$zero,0x64
/*  f0a80c8:	1000003d */ 	beqz	$zero,.L0f0a81c0
/*  f0a80cc:	a7ae009a */ 	sh	$t6,0x9a($sp)
.L0f0a80d0:
/*  f0a80d0:	90e20000 */ 	lbu	$v0,0x0($a3)
/*  f0a80d4:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f0a80d8:	2404001a */ 	addiu	$a0,$zero,0x1a
/*  f0a80dc:	14410019 */ 	bne	$v0,$at,.L0f0a8144
/*  f0a80e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a80e4:	90f80003 */ 	lbu	$t8,0x3($a3)
/*  f0a80e8:	1300000a */ 	beqz	$t8,.L0f0a8114
/*  f0a80ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a80f0:	90ef0002 */ 	lbu	$t7,0x2($a3)
/*  f0a80f4:	31f90003 */ 	andi	$t9,$t7,0x3
/*  f0a80f8:	17200010 */ 	bnez	$t9,.L0f0a813c
/*  f0a80fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8100:	0c004b70 */ 	jal	random
/*  f0a8104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8108:	304c0001 */ 	andi	$t4,$v0,0x1
/*  f0a810c:	1180000b */ 	beqz	$t4,.L0f0a813c
/*  f0a8110:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a8114:
/*  f0a8114:	0c004b70 */ 	jal	random
/*  f0a8118:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a811c:	30480001 */ 	andi	$t0,$v0,0x1
/*  f0a8120:	15000005 */ 	bnez	$t0,.L0f0a8138
/*  f0a8124:	2409005c */ 	addiu	$t1,$zero,0x5c
/*  f0a8128:	240a005b */ 	addiu	$t2,$zero,0x5b
/*  f0a812c:	a7aa009a */ 	sh	$t2,0x9a($sp)
/*  f0a8130:	10000023 */ 	beqz	$zero,.L0f0a81c0
/*  f0a8134:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a8138:
/*  f0a8138:	a7a9009a */ 	sh	$t1,0x9a($sp)
.L0f0a813c:
/*  f0a813c:	10000020 */ 	beqz	$zero,.L0f0a81c0
/*  f0a8140:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a8144:
/*  f0a8144:	10820003 */ 	beq	$a0,$v0,.L0f0a8154
/*  f0a8148:	24010056 */ 	addiu	$at,$zero,0x56
/*  f0a814c:	14410005 */ 	bne	$v0,$at,.L0f0a8164
/*  f0a8150:	3c0d8007 */ 	lui	$t5,%hi(var800702ec)
.L0f0a8154:
/*  f0a8154:	240b8079 */ 	addiu	$t3,$zero,-32647
/*  f0a8158:	a7ab009a */ 	sh	$t3,0x9a($sp)
/*  f0a815c:	10000018 */ 	beqz	$zero,.L0f0a81c0
/*  f0a8160:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a8164:
/*  f0a8164:	27a20060 */ 	addiu	$v0,$sp,0x60
/*  f0a8168:	25ad02ec */ 	addiu	$t5,$t5,%lo(var800702ec)
/*  f0a816c:	25af0024 */ 	addiu	$t7,$t5,0x24
/*  f0a8170:	0040c825 */ 	or	$t9,$v0,$zero
.L0f0a8174:
/*  f0a8174:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0a8178:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f0a817c:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f0a8180:	af21fff4 */ 	sw	$at,-0xc($t9)
/*  f0a8184:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*  f0a8188:	af21fff8 */ 	sw	$at,-0x8($t9)
/*  f0a818c:	8da1fffc */ 	lw	$at,-0x4($t5)
/*  f0a8190:	15affff8 */ 	bne	$t5,$t7,.L0f0a8174
/*  f0a8194:	af21fffc */ 	sw	$at,-0x4($t9)
/*  f0a8198:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0a819c:	af210000 */ 	sw	$at,0x0($t9)
/*  f0a81a0:	8fac00c4 */ 	lw	$t4,0xc4($sp)
/*  f0a81a4:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0a81a8:	0181001b */ 	divu	$zero,$t4,$at
/*  f0a81ac:	00004010 */ 	mfhi	$t0
/*  f0a81b0:	00085040 */ 	sll	$t2,$t0,0x1
/*  f0a81b4:	004a4821 */ 	addu	$t1,$v0,$t2
/*  f0a81b8:	852b0000 */ 	lh	$t3,0x0($t1)
/*  f0a81bc:	a7ab009a */ 	sh	$t3,0x9a($sp)
.L0f0a81c0:
/*  f0a81c0:	87b8009a */ 	lh	$t8,0x9a($sp)
/*  f0a81c4:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*  f0a81c8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0a81cc:	13010031 */ 	beq	$t8,$at,.L0f0a8294
/*  f0a81d0:	25c40008 */ 	addiu	$a0,$t6,0x8
/*  f0a81d4:	27af008c */ 	addiu	$t7,$sp,0x8c
/*  f0a81d8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0a81dc:	25c50028 */ 	addiu	$a1,$t6,0x28
/*  f0a81e0:	03003025 */ 	or	$a2,$t8,$zero
/*  f0a81e4:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f0a81e8:	0fc253bd */ 	jal	func0f094ef4
/*  f0a81ec:	afa30094 */ 	sw	$v1,0x94($sp)
/*  f0a81f0:	8fad0090 */ 	lw	$t5,0x90($sp)
/*  f0a81f4:	8fa30094 */ 	lw	$v1,0x94($sp)
/*  f0a81f8:	3c048009 */ 	lui	$a0,0x8009
/*  f0a81fc:	11a00025 */ 	beqz	$t5,.L0f0a8294
/*  f0a8200:	87a5009a */ 	lh	$a1,0x9a($sp)
/*  f0a8204:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a8208:	44815000 */ 	mtc1	$at,$f10
/*  f0a820c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0a8210:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0a8214:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0a8218:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0a821c:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0a8220:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0a8224:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0a8228:	8fa600bc */ 	lw	$a2,0xbc($sp)
/*  f0a822c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a8230:	afa30094 */ 	sw	$v1,0x94($sp)
/*  f0a8234:	0c004241 */ 	jal	func00010904
/*  f0a8238:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f0a823c:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f0a8240:	8fa30094 */ 	lw	$v1,0x94($sp)
/*  f0a8244:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a8248:	8d490000 */ 	lw	$t1,0x0($t2)
/*  f0a824c:	8fa60090 */ 	lw	$a2,0x90($sp)
/*  f0a8250:	8fa7008c */ 	lw	$a3,0x8c($sp)
/*  f0a8254:	1120000f */ 	beqz	$t1,.L0f0a8294
/*  f0a8258:	01402025 */ 	or	$a0,$t2,$zero
/*  f0a825c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a8260:	44818000 */ 	mtc1	$at,$f16
/*  f0a8264:	87ab009a */ 	lh	$t3,0x9a($sp)
/*  f0a8268:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0a826c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0a8270:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0a8274:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0a8278:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0a827c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0a8280:	afa30094 */ 	sw	$v1,0x94($sp)
/*  f0a8284:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0a8288:	0c004128 */ 	jal	func000104a0
/*  f0a828c:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f0a8290:	8fa30094 */ 	lw	$v1,0x94($sp)
.L0f0a8294:
/*  f0a8294:	54600058 */ 	bnezl	$v1,.L0f0a83f8
/*  f0a8298:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f0a829c:
/*  f0a829c:	8fa200d0 */ 	lw	$v0,0xd0($sp)
.L0f0a82a0:
/*  f0a82a0:	04400054 */ 	bltz	$v0,.L0f0a83f4
/*  f0a82a4:	28410daf */ 	slti	$at,$v0,0xdaf
/*  f0a82a8:	10200052 */ 	beqz	$at,.L0f0a83f4
/*  f0a82ac:	3c0d800b */ 	lui	$t5,0x800b
/*  f0a82b0:	8dadabc0 */ 	lw	$t5,-0x5440($t5)
/*  f0a82b4:	000218c0 */ 	sll	$v1,$v0,0x3
/*  f0a82b8:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0a82bc:	01a3c821 */ 	addu	$t9,$t5,$v1
/*  f0a82c0:	8f2c0000 */ 	lw	$t4,0x0($t9)
/*  f0a82c4:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0a82c8:	000c4702 */ 	srl	$t0,$t4,0x1c
/*  f0a82cc:	00084880 */ 	sll	$t1,$t0,0x2
/*  f0a82d0:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0a82d4:	8d4a4458 */ 	lw	$t2,0x4458($t2)
/*  f0a82d8:	51400047 */ 	beqzl	$t2,.L0f0a83f8
/*  f0a82dc:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0a82e0:	a7ab005e */ 	sh	$t3,0x5e($sp)
/*  f0a82e4:	0fc29f57 */ 	jal	func0f0a7d5c
/*  f0a82e8:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f0a82ec:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0a82f0:	10400040 */ 	beqz	$v0,.L0f0a83f4
/*  f0a82f4:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0a82f8:	3c0e800b */ 	lui	$t6,0x800b
/*  f0a82fc:	8dceabc0 */ 	lw	$t6,-0x5440($t6)
/*  f0a8300:	3c048008 */ 	lui	$a0,0x8008
/*  f0a8304:	8fac00c0 */ 	lw	$t4,0xc0($sp)
/*  f0a8308:	01c3c021 */ 	addu	$t8,$t6,$v1
/*  f0a830c:	8f0f0000 */ 	lw	$t7,0x0($t8)
/*  f0a8310:	000f6f02 */ 	srl	$t5,$t7,0x1c
/*  f0a8314:	000dc880 */ 	sll	$t9,$t5,0x2
/*  f0a8318:	00992021 */ 	addu	$a0,$a0,$t9
/*  f0a831c:	8c844458 */ 	lw	$a0,0x4458($a0)
/*  f0a8320:	84850008 */ 	lh	$a1,0x8($a0)
/*  f0a8324:	58a0001e */ 	blezl	$a1,.L0f0a83a0
/*  f0a8328:	8fb900bc */ 	lw	$t9,0xbc($sp)
/*  f0a832c:	0185001b */ 	divu	$zero,$t4,$a1
/*  f0a8330:	8c880000 */ 	lw	$t0,0x0($a0)
/*  f0a8334:	00001010 */ 	mfhi	$v0
/*  f0a8338:	00024840 */ 	sll	$t1,$v0,0x1
/*  f0a833c:	01095021 */ 	addu	$t2,$t0,$t1
/*  f0a8340:	954b0000 */ 	lhu	$t3,0x0($t2)
/*  f0a8344:	14a00002 */ 	bnez	$a1,.L0f0a8350
/*  f0a8348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a834c:	0007000d */ 	break	0x7
.L0f0a8350:
/*  f0a8350:	a7ab005e */ 	sh	$t3,0x5e($sp)
/*  f0a8354:	87ae005e */ 	lh	$t6,0x5e($sp)
/*  f0a8358:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0a835c:	3c048009 */ 	lui	$a0,0x8009
/*  f0a8360:	11c1000e */ 	beq	$t6,$at,.L0f0a839c
/*  f0a8364:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0a8368:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a836c:	44819000 */ 	mtc1	$at,$f18
/*  f0a8370:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0a8374:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0a8378:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0a837c:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0a8380:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0a8384:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0a8388:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0a838c:	8fa600bc */ 	lw	$a2,0xbc($sp)
/*  f0a8390:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a8394:	0c004241 */ 	jal	func00010904
/*  f0a8398:	e7b20014 */ 	swc1	$f18,0x14($sp)
.L0f0a839c:
/*  f0a839c:	8fb900bc */ 	lw	$t9,0xbc($sp)
.L0f0a83a0:
/*  f0a83a0:	87ac005e */ 	lh	$t4,0x5e($sp)
/*  f0a83a4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0a83a8:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f0a83ac:	50800012 */ 	beqzl	$a0,.L0f0a83f8
/*  f0a83b0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0a83b4:	1181000f */ 	beq	$t4,$at,.L0f0a83f4
/*  f0a83b8:	8fa800cc */ 	lw	$t0,0xcc($sp)
/*  f0a83bc:	3c017f1b */ 	lui	$at,%hi(var7f1aca94)
/*  f0a83c0:	c424ca94 */ 	lwc1	$f4,%lo(var7f1aca94)($at)
/*  f0a83c4:	3c07451c */ 	lui	$a3,0x451c
/*  f0a83c8:	25090028 */ 	addiu	$t1,$t0,0x28
/*  f0a83cc:	240a7fff */ 	addiu	$t2,$zero,0x7fff
/*  f0a83d0:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0a83d4:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0a83d8:	34e74000 */ 	ori	$a3,$a3,0x4000
/*  f0a83dc:	25050008 */ 	addiu	$a1,$t0,0x8
/*  f0a83e0:	3c0643c8 */ 	lui	$a2,0x43c8
/*  f0a83e4:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0a83e8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0a83ec:	0fc25417 */ 	jal	func0f09505c
/*  f0a83f0:	e7a40010 */ 	swc1	$f4,0x10($sp)
.L0f0a83f4:
/*  f0a83f4:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f0a83f8:
/*  f0a83f8:	27bd00c8 */ 	addiu	$sp,$sp,0xc8
/*  f0a83fc:	03e00008 */ 	jr	$ra
/*  f0a8400:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a8404
/*  f0a8404:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a8408:	8dce9ff4 */ 	lw	$t6,-0x600c($t6)
/*  f0a840c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0a8410:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0a8414:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0a8418:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0a841c:	19c00026 */ 	blez	$t6,.L0f0a84b8
/*  f0a8420:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0a8424:	0fc29f57 */ 	jal	func0f0a7d5c
/*  f0a8428:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a842c:	10400022 */ 	beqz	$v0,.L0f0a84b8
/*  f0a8430:	00403025 */ 	or	$a2,$v0,$zero
/*  f0a8434:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a8438:	44812000 */ 	mtc1	$at,$f4
/*  f0a843c:	3c048009 */ 	lui	$a0,0x8009
/*  f0a8440:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0a8444:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0a8448:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0a844c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0a8450:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0a8454:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0a8458:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0a845c:	24058077 */ 	addiu	$a1,$zero,-32649
/*  f0a8460:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a8464:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f0a8468:	0c004241 */ 	jal	func00010904
/*  f0a846c:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0a8470:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0a8474:	3c07451c */ 	lui	$a3,0x451c
/*  f0a8478:	34e74000 */ 	ori	$a3,$a3,0x4000
/*  f0a847c:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f0a8480:	3c0643c8 */ 	lui	$a2,0x43c8
/*  f0a8484:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f0a8488:	1080000b */ 	beqz	$a0,.L0f0a84b8
/*  f0a848c:	3c017f1b */ 	lui	$at,%hi(var7f1aca98)
/*  f0a8490:	c426ca98 */ 	lwc1	$f6,%lo(var7f1aca98)($at)
/*  f0a8494:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f0a8498:	24098077 */ 	addiu	$t1,$zero,-32649
/*  f0a849c:	240a7fff */ 	addiu	$t2,$zero,0x7fff
/*  f0a84a0:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0a84a4:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0a84a8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0a84ac:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f0a84b0:	0fc25417 */ 	jal	func0f09505c
/*  f0a84b4:	afa80014 */ 	sw	$t0,0x14($sp)
.L0f0a84b8:
/*  f0a84b8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0a84bc:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0a84c0:	03e00008 */ 	jr	$ra
/*  f0a84c4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a84c8
/*  f0a84c8:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f0a84cc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0a84d0:	afa400a8 */ 	sw	$a0,0xa8($sp)
/*  f0a84d4:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f0a84d8:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f0a84dc:	0c004b70 */ 	jal	random
/*  f0a84e0:	afa700b4 */ 	sw	$a3,0xb4($sp)
/*  f0a84e4:	0c004b70 */ 	jal	random
/*  f0a84e8:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0a84ec:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a84f0:	8dce9ff4 */ 	lw	$t6,-0x600c($t6)
/*  f0a84f4:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f0a84f8:	8fa200b0 */ 	lw	$v0,0xb0($sp)
/*  f0a84fc:	59c00101 */ 	blezl	$t6,.L0f0a8904
/*  f0a8500:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0a8504:	0440000e */ 	bltz	$v0,.L0f0a8540
/*  f0a8508:	28410daf */ 	slti	$at,$v0,0xdaf
/*  f0a850c:	1020000c */ 	beqz	$at,.L0f0a8540
/*  f0a8510:	3c0f800b */ 	lui	$t7,0x800b
/*  f0a8514:	8defabc0 */ 	lw	$t7,-0x5440($t7)
/*  f0a8518:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f0a851c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0a8520:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0a8524:	8f290000 */ 	lw	$t1,0x0($t9)
/*  f0a8528:	00095702 */ 	srl	$t2,$t1,0x1c
/*  f0a852c:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f0a8530:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f0a8534:	8d8c4458 */ 	lw	$t4,0x4458($t4)
/*  f0a8538:	858d0008 */ 	lh	$t5,0x8($t4)
/*  f0a853c:	11a000f0 */ 	beqz	$t5,.L0f0a8900
.L0f0a8540:
/*  f0a8540:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0a8544:	0fc29f57 */ 	jal	func0f0a7d5c
/*  f0a8548:	afae0098 */ 	sw	$t6,0x98($sp)
/*  f0a854c:	104000a5 */ 	beqz	$v0,.L0f0a87e4
/*  f0a8550:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f0a8554:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f0a8558:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0a855c:	a7af0096 */ 	sh	$t7,0x96($sp)
/*  f0a8560:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f0a8564:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f0a8568:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a856c:	5441002a */ 	bnel	$v0,$at,.L0f0a8618
/*  f0a8570:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f0a8574:	afa00098 */ 	sw	$zero,0x98($sp)
/*  f0a8578:	90980003 */ 	lbu	$t8,0x3($a0)
/*  f0a857c:	1300000a */ 	beqz	$t8,.L0f0a85a8
/*  f0a8580:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8584:	90990002 */ 	lbu	$t9,0x2($a0)
/*  f0a8588:	33290003 */ 	andi	$t1,$t9,0x3
/*  f0a858c:	55200080 */ 	bnezl	$t1,.L0f0a8790
/*  f0a8590:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f0a8594:	0c004b70 */ 	jal	random
/*  f0a8598:	afa30090 */ 	sw	$v1,0x90($sp)
/*  f0a859c:	304a0001 */ 	andi	$t2,$v0,0x1
/*  f0a85a0:	1140007a */ 	beqz	$t2,.L0f0a878c
/*  f0a85a4:	8fa30090 */ 	lw	$v1,0x90($sp)
.L0f0a85a8:
/*  f0a85a8:	3c0b8007 */ 	lui	$t3,%hi(var80070314)
/*  f0a85ac:	256b0314 */ 	addiu	$t3,$t3,%lo(var80070314)
/*  f0a85b0:	8d610000 */ 	lw	$at,0x0($t3)
/*  f0a85b4:	27a2008c */ 	addiu	$v0,$sp,0x8c
/*  f0a85b8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0a85bc:	ac410000 */ 	sw	$at,0x0($v0)
/*  f0a85c0:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0a85c4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a85c8:	44812000 */ 	mtc1	$at,$f4
/*  f0a85cc:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f0a85d0:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f0a85d4:	00594821 */ 	addu	$t1,$v0,$t9
/*  f0a85d8:	85250000 */ 	lh	$a1,0x0($t1)
/*  f0a85dc:	3c048009 */ 	lui	$a0,0x8009
/*  f0a85e0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0a85e4:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0a85e8:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0a85ec:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0a85f0:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0a85f4:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0a85f8:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0a85fc:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a8600:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0a8604:	0c004241 */ 	jal	func00010904
/*  f0a8608:	a7a50096 */ 	sh	$a1,0x96($sp)
/*  f0a860c:	1000005f */ 	beqz	$zero,.L0f0a878c
/*  f0a8610:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a8614:	2401001a */ 	addiu	$at,$zero,0x1a
.L0f0a8618:
/*  f0a8618:	10410003 */ 	beq	$v0,$at,.L0f0a8628
/*  f0a861c:	240e8079 */ 	addiu	$t6,$zero,-32647
/*  f0a8620:	24010056 */ 	addiu	$at,$zero,0x56
/*  f0a8624:	14410012 */ 	bne	$v0,$at,.L0f0a8670
.L0f0a8628:
/*  f0a8628:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a862c:	44813000 */ 	mtc1	$at,$f6
/*  f0a8630:	3c048009 */ 	lui	$a0,0x8009
/*  f0a8634:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0a8638:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0a863c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0a8640:	a7ae0096 */ 	sh	$t6,0x96($sp)
/*  f0a8644:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0a8648:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0a864c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0a8650:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0a8654:	24058079 */ 	addiu	$a1,$zero,-32647
/*  f0a8658:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0a865c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a8660:	0c004241 */ 	jal	func00010904
/*  f0a8664:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0a8668:	10000048 */ 	beqz	$zero,.L0f0a878c
/*  f0a866c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a8670:
/*  f0a8670:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0a8674:	1041000e */ 	beq	$v0,$at,.L0f0a86b0
/*  f0a8678:	240980aa */ 	addiu	$t1,$zero,-32598
/*  f0a867c:	24010021 */ 	addiu	$at,$zero,0x21
/*  f0a8680:	1041000b */ 	beq	$v0,$at,.L0f0a86b0
/*  f0a8684:	24010020 */ 	addiu	$at,$zero,0x20
/*  f0a8688:	10410009 */ 	beq	$v0,$at,.L0f0a86b0
/*  f0a868c:	2401003d */ 	addiu	$at,$zero,0x3d
/*  f0a8690:	10410007 */ 	beq	$v0,$at,.L0f0a86b0
/*  f0a8694:	2401003e */ 	addiu	$at,$zero,0x3e
/*  f0a8698:	10410005 */ 	beq	$v0,$at,.L0f0a86b0
/*  f0a869c:	2401003f */ 	addiu	$at,$zero,0x3f
/*  f0a86a0:	10410003 */ 	beq	$v0,$at,.L0f0a86b0
/*  f0a86a4:	24010035 */ 	addiu	$at,$zero,0x35
/*  f0a86a8:	14410013 */ 	bne	$v0,$at,.L0f0a86f8
/*  f0a86ac:	3c0b8007 */ 	lui	$t3,%hi(var80070318)
.L0f0a86b0:
/*  f0a86b0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a86b4:	44814000 */ 	mtc1	$at,$f8
/*  f0a86b8:	3c048009 */ 	lui	$a0,0x8009
/*  f0a86bc:	240affff */ 	addiu	$t2,$zero,-1
/*  f0a86c0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0a86c4:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0a86c8:	a7a90096 */ 	sh	$t1,0x96($sp)
/*  f0a86cc:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0a86d0:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0a86d4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0a86d8:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0a86dc:	240580aa */ 	addiu	$a1,$zero,-32598
/*  f0a86e0:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0a86e4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a86e8:	0c004241 */ 	jal	func00010904
/*  f0a86ec:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0a86f0:	10000026 */ 	beqz	$zero,.L0f0a878c
/*  f0a86f4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a86f8:
/*  f0a86f8:	27a20044 */ 	addiu	$v0,$sp,0x44
/*  f0a86fc:	256b0318 */ 	addiu	$t3,$t3,%lo(var80070318)
/*  f0a8700:	25780048 */ 	addiu	$t8,$t3,0x48
/*  f0a8704:	0040c825 */ 	or	$t9,$v0,$zero
.L0f0a8708:
/*  f0a8708:	8d610000 */ 	lw	$at,0x0($t3)
/*  f0a870c:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f0a8710:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f0a8714:	af21fff4 */ 	sw	$at,-0xc($t9)
/*  f0a8718:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f0a871c:	af21fff8 */ 	sw	$at,-0x8($t9)
/*  f0a8720:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f0a8724:	1578fff8 */ 	bne	$t3,$t8,.L0f0a8708
/*  f0a8728:	af21fffc */ 	sw	$at,-0x4($t9)
/*  f0a872c:	8fa900a0 */ 	lw	$t1,0xa0($sp)
/*  f0a8730:	24010024 */ 	addiu	$at,$zero,0x24
/*  f0a8734:	3c048009 */ 	lui	$a0,0x8009
/*  f0a8738:	0121001b */ 	divu	$zero,$t1,$at
/*  f0a873c:	00005010 */ 	mfhi	$t2
/*  f0a8740:	000a6840 */ 	sll	$t5,$t2,0x1
/*  f0a8744:	004d6021 */ 	addu	$t4,$v0,$t5
/*  f0a8748:	85850000 */ 	lh	$a1,0x0($t4)
/*  f0a874c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a8750:	44815000 */ 	mtc1	$at,$f10
/*  f0a8754:	240effff */ 	addiu	$t6,$zero,-1
/*  f0a8758:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0a875c:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0a8760:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0a8764:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0a8768:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0a876c:	afa30090 */ 	sw	$v1,0x90($sp)
/*  f0a8770:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0a8774:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0a8778:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a877c:	a7a50096 */ 	sh	$a1,0x96($sp)
/*  f0a8780:	0c004241 */ 	jal	func00010904
/*  f0a8784:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f0a8788:	8fa30090 */ 	lw	$v1,0x90($sp)
.L0f0a878c:
/*  f0a878c:	8fb900a4 */ 	lw	$t9,0xa4($sp)
.L0f0a8790:
/*  f0a8790:	3c07451c */ 	lui	$a3,0x451c
/*  f0a8794:	34e74000 */ 	ori	$a3,$a3,0x4000
/*  f0a8798:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f0a879c:	8fa500ac */ 	lw	$a1,0xac($sp)
/*  f0a87a0:	3c0643c8 */ 	lui	$a2,0x43c8
/*  f0a87a4:	1080000d */ 	beqz	$a0,.L0f0a87dc
/*  f0a87a8:	3c017f1b */ 	lui	$at,%hi(var7f1aca9c)
/*  f0a87ac:	c430ca9c */ 	lwc1	$f16,%lo(var7f1aca9c)($at)
/*  f0a87b0:	8fa900b4 */ 	lw	$t1,0xb4($sp)
/*  f0a87b4:	87aa0096 */ 	lh	$t2,0x96($sp)
/*  f0a87b8:	240d7fff */ 	addiu	$t5,$zero,0x7fff
/*  f0a87bc:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0a87c0:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0a87c4:	afa30090 */ 	sw	$v1,0x90($sp)
/*  f0a87c8:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f0a87cc:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0a87d0:	0fc25417 */ 	jal	func0f09505c
/*  f0a87d4:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0a87d8:	8fa30090 */ 	lw	$v1,0x90($sp)
.L0f0a87dc:
/*  f0a87dc:	54600049 */ 	bnezl	$v1,.L0f0a8904
/*  f0a87e0:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0a87e4:
/*  f0a87e4:	8fac0098 */ 	lw	$t4,0x98($sp)
/*  f0a87e8:	51800046 */ 	beqzl	$t4,.L0f0a8904
/*  f0a87ec:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0a87f0:	0fc29f57 */ 	jal	func0f0a7d5c
/*  f0a87f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a87f8:	10400041 */ 	beqz	$v0,.L0f0a8900
/*  f0a87fc:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f0a8800:	8fa300b0 */ 	lw	$v1,0xb0($sp)
/*  f0a8804:	0460003e */ 	bltz	$v1,.L0f0a8900
/*  f0a8808:	28610daf */ 	slti	$at,$v1,0xdaf
/*  f0a880c:	1020003c */ 	beqz	$at,.L0f0a8900
/*  f0a8810:	3c0f800b */ 	lui	$t7,0x800b
/*  f0a8814:	8defabc0 */ 	lw	$t7,-0x5440($t7)
/*  f0a8818:	000370c0 */ 	sll	$t6,$v1,0x3
/*  f0a881c:	3c028008 */ 	lui	$v0,0x8008
/*  f0a8820:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0a8824:	8f0b0000 */ 	lw	$t3,0x0($t8)
/*  f0a8828:	240affff */ 	addiu	$t2,$zero,-1
/*  f0a882c:	000bcf02 */ 	srl	$t9,$t3,0x1c
/*  f0a8830:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0a8834:	00491021 */ 	addu	$v0,$v0,$t1
/*  f0a8838:	8c424458 */ 	lw	$v0,0x4458($v0)
/*  f0a883c:	84480008 */ 	lh	$t0,0x8($v0)
/*  f0a8840:	59000030 */ 	blezl	$t0,.L0f0a8904
/*  f0a8844:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0a8848:	1040001b */ 	beqz	$v0,.L0f0a88b8
/*  f0a884c:	a7aa0042 */ 	sh	$t2,0x42($sp)
/*  f0a8850:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f0a8854:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f0a8858:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0a885c:	01a8001b */ 	divu	$zero,$t5,$t0
/*  f0a8860:	00001810 */ 	mfhi	$v1
/*  f0a8864:	00037840 */ 	sll	$t7,$v1,0x1
/*  f0a8868:	018f7021 */ 	addu	$t6,$t4,$t7
/*  f0a886c:	95d80000 */ 	lhu	$t8,0x0($t6)
/*  f0a8870:	44819000 */ 	mtc1	$at,$f18
/*  f0a8874:	15000002 */ 	bnez	$t0,.L0f0a8880
/*  f0a8878:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a887c:	0007000d */ 	break	0x7
.L0f0a8880:
/*  f0a8880:	3c048009 */ 	lui	$a0,0x8009
/*  f0a8884:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0a8888:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0a888c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0a8890:	a7b80042 */ 	sh	$t8,0x42($sp)
/*  f0a8894:	87a50042 */ 	lh	$a1,0x42($sp)
/*  f0a8898:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0a889c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0a88a0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0a88a4:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0a88a8:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0a88ac:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0a88b0:	0c004241 */ 	jal	func00010904
/*  f0a88b4:	e7b20014 */ 	swc1	$f18,0x14($sp)
.L0f0a88b8:
/*  f0a88b8:	8faa00a4 */ 	lw	$t2,0xa4($sp)
/*  f0a88bc:	3c07451c */ 	lui	$a3,0x451c
/*  f0a88c0:	34e74000 */ 	ori	$a3,$a3,0x4000
/*  f0a88c4:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f0a88c8:	8fa500ac */ 	lw	$a1,0xac($sp)
/*  f0a88cc:	3c0643c8 */ 	lui	$a2,0x43c8
/*  f0a88d0:	1080000b */ 	beqz	$a0,.L0f0a8900
/*  f0a88d4:	3c017f1b */ 	lui	$at,%hi(var7f1acaa0)
/*  f0a88d8:	c424caa0 */ 	lwc1	$f4,%lo(var7f1acaa0)($at)
/*  f0a88dc:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f0a88e0:	87ac0042 */ 	lh	$t4,0x42($sp)
/*  f0a88e4:	240f7fff */ 	addiu	$t7,$zero,0x7fff
/*  f0a88e8:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0a88ec:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0a88f0:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0a88f4:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0a88f8:	0fc25417 */ 	jal	func0f09505c
/*  f0a88fc:	afac0018 */ 	sw	$t4,0x18($sp)
.L0f0a8900:
/*  f0a8900:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0a8904:
/*  f0a8904:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f0a8908:	03e00008 */ 	jr	$ra
/*  f0a890c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a8910
/*  f0a8910:	00047900 */ 	sll	$t7,$a0,0x4
/*  f0a8914:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f0a8918:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a891c:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f0a8920:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a8924:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a8928:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0a892c:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f0a8930:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0a8934:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f0a8938:	8c580644 */ 	lw	$t8,0x644($v0)
/*  f0a893c:	24420638 */ 	addiu	$v0,$v0,0x638
/*  f0a8940:	ac45000c */ 	sw	$a1,0xc($v0)
/*  f0a8944:	14a00003 */ 	bnez	$a1,.L0f0a8954
/*  f0a8948:	ac580010 */ 	sw	$t8,0x10($v0)
/*  f0a894c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0a8950:	ac590014 */ 	sw	$t9,0x14($v0)
.L0f0a8954:
/*  f0a8954:	03e00008 */ 	jr	$ra
/*  f0a8958:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a895c
/*  f0a895c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a8960:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a8964:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0a8968:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0a896c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a8970:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0a8974:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0a8978:	244efffa */ 	addiu	$t6,$v0,-6
/*  f0a897c:	2dc1001d */ 	sltiu	$at,$t6,0x1d
/*  f0a8980:	10200073 */ 	beqz	$at,.L0f0a8b50
/*  f0a8984:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f0a8988:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0a898c:	3c017f1b */ 	lui	$at,%hi(var7f1acaa4)
/*  f0a8990:	002e0821 */ 	addu	$at,$at,$t6
/*  f0a8994:	8c2ecaa4 */ 	lw	$t6,%lo(var7f1acaa4)($at)
/*  f0a8998:	01c00008 */ 	jr	$t6
/*  f0a899c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a89a0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0a89a4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0a89a8:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0a89ac:	90781583 */ 	lbu	$t8,0x1583($v1)
/*  f0a89b0:	37190020 */ 	ori	$t9,$t8,0x20
/*  f0a89b4:	10a00003 */ 	beqz	$a1,.L0f0a89c4
/*  f0a89b8:	a0791583 */ 	sb	$t9,0x1583($v1)
/*  f0a89bc:	100000a0 */ 	beqz	$zero,.L0f0a8c40
/*  f0a89c0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a89c4:
/*  f0a89c4:	8fa90018 */ 	lw	$t1,0x18($sp)
/*  f0a89c8:	29210032 */ 	slti	$at,$t1,0x32
/*  f0a89cc:	50200004 */ 	beqzl	$at,.L0f0a89e0
/*  f0a89d0:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0a89d4:	1000009a */ 	beqz	$zero,.L0f0a8c40
/*  f0a89d8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a89dc:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0a89e0:
/*  f0a89e0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a89e4:	906a063b */ 	lbu	$t2,0x63b($v1)
/*  f0a89e8:	51410004 */ 	beql	$t2,$at,.L0f0a89fc
/*  f0a89ec:	906c0d0f */ 	lbu	$t4,0xd0f($v1)
/*  f0a89f0:	10000093 */ 	beqz	$zero,.L0f0a8c40
/*  f0a89f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a89f8:	906c0d0f */ 	lbu	$t4,0xd0f($v1)
.L0f0a89fc:
/*  f0a89fc:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f0a8a00:	358d0010 */ 	ori	$t5,$t4,0x10
/*  f0a8a04:	1000008e */ 	beqz	$zero,.L0f0a8c40
/*  f0a8a08:	a06d0d0f */ 	sb	$t5,0xd0f($v1)
/*  f0a8a0c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0a8a10:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0a8a14:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0a8a18:	906f1583 */ 	lbu	$t7,0x1583($v1)
/*  f0a8a1c:	35f80020 */ 	ori	$t8,$t7,0x20
/*  f0a8a20:	a0781583 */ 	sb	$t8,0x1583($v1)
/*  f0a8a24:	8fb90020 */ 	lw	$t9,0x20($sp)
/*  f0a8a28:	1320000b */ 	beqz	$t9,.L0f0a8a58
/*  f0a8a2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8a30:	0fc2a31f */ 	jal	func0f0a8c7c
/*  f0a8a34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8a38:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0a8a3c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a8a40:	14410005 */ 	bne	$v0,$at,.L0f0a8a58
/*  f0a8a44:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0a8a48:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0a8a4c:	906a0d0f */ 	lbu	$t2,0xd0f($v1)
/*  f0a8a50:	354b0010 */ 	ori	$t3,$t2,0x10
/*  f0a8a54:	a06b0d0f */ 	sb	$t3,0xd0f($v1)
.L0f0a8a58:
/*  f0a8a58:	10000079 */ 	beqz	$zero,.L0f0a8c40
/*  f0a8a5c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a8a60:	14a00039 */ 	bnez	$a1,.L0f0a8b48
/*  f0a8a64:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0a8a68:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0a8a6c:	8d0c0284 */ 	lw	$t4,0x284($t0)
/*  f0a8a70:	81871580 */ 	lb	$a3,0x1580($t4)
/*  f0a8a74:	0007102a */ 	slt	$v0,$zero,$a3
/*  f0a8a78:	10400031 */ 	beqz	$v0,.L0f0a8b40
/*  f0a8a7c:	28e30024 */ 	slti	$v1,$a3,0x24
/*  f0a8a80:	1060002f */ 	beqz	$v1,.L0f0a8b40
/*  f0a8a84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8a88:	10400014 */ 	beqz	$v0,.L0f0a8adc
/*  f0a8a8c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a8a90:	10600012 */ 	beqz	$v1,.L0f0a8adc
/*  f0a8a94:	00602025 */ 	or	$a0,$v1,$zero
/*  f0a8a98:	8d0d0288 */ 	lw	$t5,0x288($t0)
/*  f0a8a9c:	24e2ffff */ 	addiu	$v0,$a3,-1
/*  f0a8aa0:	0002c0c3 */ 	sra	$t8,$v0,0x3
/*  f0a8aa4:	8dae0070 */ 	lw	$t6,0x70($t5)
/*  f0a8aa8:	3c09800b */ 	lui	$t1,0x800b
/*  f0a8aac:	304a0007 */ 	andi	$t2,$v0,0x7
/*  f0a8ab0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0a8ab4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0a8ab8:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f0a8abc:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0a8ac0:	01394821 */ 	addu	$t1,$t1,$t9
/*  f0a8ac4:	9129c84f */ 	lbu	$t1,-0x37b1($t1)
/*  f0a8ac8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0a8acc:	014b6004 */ 	sllv	$t4,$t3,$t2
/*  f0a8ad0:	012c2024 */ 	and	$a0,$t1,$t4
/*  f0a8ad4:	0004682b */ 	sltu	$t5,$zero,$a0
/*  f0a8ad8:	01a02025 */ 	or	$a0,$t5,$zero
.L0f0a8adc:
/*  f0a8adc:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a8ae0:	8dcea248 */ 	lw	$t6,-0x5db8($t6)
/*  f0a8ae4:	24e2ffff */ 	addiu	$v0,$a3,-1
/*  f0a8ae8:	0002c8c3 */ 	sra	$t9,$v0,0x3
/*  f0a8aec:	8dcf0070 */ 	lw	$t7,0x70($t6)
/*  f0a8af0:	3c0a800b */ 	lui	$t2,%hi(g_MpPlayers)
/*  f0a8af4:	254ac7b8 */ 	addiu	$t2,$t2,%lo(g_MpPlayers)
/*  f0a8af8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0a8afc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0a8b00:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f0a8b04:	03195821 */ 	addu	$t3,$t8,$t9
/*  f0a8b08:	016a1821 */ 	addu	$v1,$t3,$t2
/*  f0a8b0c:	30490007 */ 	andi	$t1,$v0,0x7
/*  f0a8b10:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0a8b14:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0a8b18:	012c3004 */ 	sllv	$a2,$t4,$t1
/*  f0a8b1c:	11a40005 */ 	beq	$t5,$a0,.L0f0a8b34
/*  f0a8b20:	90650097 */ 	lbu	$a1,0x97($v1)
/*  f0a8b24:	00a67825 */ 	or	$t7,$a1,$a2
/*  f0a8b28:	a06f0097 */ 	sb	$t7,0x97($v1)
/*  f0a8b2c:	10000044 */ 	beqz	$zero,.L0f0a8c40
/*  f0a8b30:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a8b34:
/*  f0a8b34:	00c0c027 */ 	nor	$t8,$a2,$zero
/*  f0a8b38:	00b8c824 */ 	and	$t9,$a1,$t8
/*  f0a8b3c:	a0790097 */ 	sb	$t9,0x97($v1)
.L0f0a8b40:
/*  f0a8b40:	1000003f */ 	beqz	$zero,.L0f0a8c40
/*  f0a8b44:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a8b48:
/*  f0a8b48:	1000003d */ 	beqz	$zero,.L0f0a8c40
/*  f0a8b4c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a8b50:
/*  f0a8b50:	10a00008 */ 	beqz	$a1,.L0f0a8b74
/*  f0a8b54:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0a8b58:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0a8b5c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0a8b60:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0a8b64:	906a1583 */ 	lbu	$t2,0x1583($v1)
/*  f0a8b68:	354c0020 */ 	ori	$t4,$t2,0x20
/*  f0a8b6c:	10000033 */ 	beqz	$zero,.L0f0a8c3c
/*  f0a8b70:	a06c1583 */ 	sb	$t4,0x1583($v1)
.L0f0a8b74:
/*  f0a8b74:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0a8b78:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0a8b7c:	81271580 */ 	lb	$a3,0x1580($t1)
/*  f0a8b80:	0007102a */ 	slt	$v0,$zero,$a3
/*  f0a8b84:	1040002d */ 	beqz	$v0,.L0f0a8c3c
/*  f0a8b88:	28e30024 */ 	slti	$v1,$a3,0x24
/*  f0a8b8c:	5060002c */ 	beqzl	$v1,.L0f0a8c40
/*  f0a8b90:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a8b94:	50400015 */ 	beqzl	$v0,.L0f0a8bec
/*  f0a8b98:	8d0d0288 */ 	lw	$t5,0x288($t0)
/*  f0a8b9c:	10600012 */ 	beqz	$v1,.L0f0a8be8
/*  f0a8ba0:	24e2ffff */ 	addiu	$v0,$a3,-1
/*  f0a8ba4:	8d0d0288 */ 	lw	$t5,0x288($t0)
/*  f0a8ba8:	0002c0c3 */ 	sra	$t8,$v0,0x3
/*  f0a8bac:	3c0b800b */ 	lui	$t3,%hi(g_MpPlayers)
/*  f0a8bb0:	8dae0070 */ 	lw	$t6,0x70($t5)
/*  f0a8bb4:	256bc7b8 */ 	addiu	$t3,$t3,%lo(g_MpPlayers)
/*  f0a8bb8:	304a0007 */ 	andi	$t2,$v0,0x7
/*  f0a8bbc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0a8bc0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0a8bc4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f0a8bc8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0a8bcc:	032b1821 */ 	addu	$v1,$t9,$t3
/*  f0a8bd0:	90650097 */ 	lbu	$a1,0x97($v1)
/*  f0a8bd4:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0a8bd8:	014c3004 */ 	sllv	$a2,$t4,$t2
/*  f0a8bdc:	00a64824 */ 	and	$t1,$a1,$a2
/*  f0a8be0:	55200014 */ 	bnezl	$t1,.L0f0a8c34
/*  f0a8be4:	00c07827 */ 	nor	$t7,$a2,$zero
.L0f0a8be8:
/*  f0a8be8:	8d0d0288 */ 	lw	$t5,0x288($t0)
.L0f0a8bec:
/*  f0a8bec:	24e2ffff */ 	addiu	$v0,$a3,-1
/*  f0a8bf0:	0002c0c3 */ 	sra	$t8,$v0,0x3
/*  f0a8bf4:	8dae0070 */ 	lw	$t6,0x70($t5)
/*  f0a8bf8:	3c0b800b */ 	lui	$t3,%hi(g_MpPlayers)
/*  f0a8bfc:	256bc7b8 */ 	addiu	$t3,$t3,%lo(g_MpPlayers)
/*  f0a8c00:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0a8c04:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0a8c08:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f0a8c0c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0a8c10:	032b1821 */ 	addu	$v1,$t9,$t3
/*  f0a8c14:	906c0097 */ 	lbu	$t4,0x97($v1)
/*  f0a8c18:	304a0007 */ 	andi	$t2,$v0,0x7
/*  f0a8c1c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0a8c20:	01496804 */ 	sllv	$t5,$t1,$t2
/*  f0a8c24:	018d7025 */ 	or	$t6,$t4,$t5
/*  f0a8c28:	10000004 */ 	beqz	$zero,.L0f0a8c3c
/*  f0a8c2c:	a06e0097 */ 	sb	$t6,0x97($v1)
/*  f0a8c30:	00c07827 */ 	nor	$t7,$a2,$zero
.L0f0a8c34:
/*  f0a8c34:	00afc024 */ 	and	$t8,$a1,$t7
/*  f0a8c38:	a0780097 */ 	sb	$t8,0x97($v1)
.L0f0a8c3c:
/*  f0a8c3c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a8c40:
/*  f0a8c40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a8c44:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a8c48:	03e00008 */ 	jr	$ra
/*  f0a8c4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a8c50
/*  f0a8c50:	3c02800a */ 	lui	$v0,0x800a
/*  f0a8c54:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a8c58:	8c4e0d0c */ 	lw	$t6,0xd0c($v0)
/*  f0a8c5c:	000ec6c0 */ 	sll	$t8,$t6,0x1b
/*  f0a8c60:	07000004 */ 	bltz	$t8,.L0f0a8c74
/*  f0a8c64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8c68:	90591583 */ 	lbu	$t9,0x1583($v0)
/*  f0a8c6c:	3328ffdf */ 	andi	$t0,$t9,0xffdf
/*  f0a8c70:	a0481583 */ 	sb	$t0,0x1583($v0)
.L0f0a8c74:
/*  f0a8c74:	03e00008 */ 	jr	$ra
/*  f0a8c78:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a8c7c
/*  f0a8c7c:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0a8c80:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0a8c84:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f0a8c88:	80431580 */ 	lb	$v1,0x1580($v0)
/*  f0a8c8c:	1860001e */ 	blez	$v1,.L0f0a8d08
/*  f0a8c90:	28610024 */ 	slti	$at,$v1,0x24
/*  f0a8c94:	5020001d */ 	beqzl	$at,.L0f0a8d0c
/*  f0a8c98:	8c591580 */ 	lw	$t9,0x1580($v0)
/*  f0a8c9c:	8cae0288 */ 	lw	$t6,0x288($a1)
/*  f0a8ca0:	2464ffff */ 	addiu	$a0,$v1,-1
/*  f0a8ca4:	0004c8c3 */ 	sra	$t9,$a0,0x3
/*  f0a8ca8:	8dcf0070 */ 	lw	$t7,0x70($t6)
/*  f0a8cac:	3c09800b */ 	lui	$t1,0x800b
/*  f0a8cb0:	308a0007 */ 	andi	$t2,$a0,0x7
/*  f0a8cb4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0a8cb8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0a8cbc:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f0a8cc0:	03194021 */ 	addu	$t0,$t8,$t9
/*  f0a8cc4:	01284821 */ 	addu	$t1,$t1,$t0
/*  f0a8cc8:	9129c84f */ 	lbu	$t1,-0x37b1($t1)
/*  f0a8ccc:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0a8cd0:	014b6004 */ 	sllv	$t4,$t3,$t2
/*  f0a8cd4:	012c6824 */ 	and	$t5,$t1,$t4
/*  f0a8cd8:	51a0000c */ 	beqzl	$t5,.L0f0a8d0c
/*  f0a8cdc:	8c591580 */ 	lw	$t9,0x1580($v0)
/*  f0a8ce0:	8c4e1580 */ 	lw	$t6,0x1580($v0)
/*  f0a8ce4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a8ce8:	000e7e80 */ 	sll	$t7,$t6,0x1a
/*  f0a8cec:	000fc7c2 */ 	srl	$t8,$t7,0x1f
/*  f0a8cf0:	17010003 */ 	bne	$t8,$at,.L0f0a8d00
/*  f0a8cf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8cf8:	03e00008 */ 	jr	$ra
/*  f0a8cfc:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a8d00:
/*  f0a8d00:	03e00008 */ 	jr	$ra
/*  f0a8d04:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a8d08:
/*  f0a8d08:	8c591580 */ 	lw	$t9,0x1580($v0)
.L0f0a8d0c:
/*  f0a8d0c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a8d10:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a8d14:	00194680 */ 	sll	$t0,$t9,0x1a
/*  f0a8d18:	00085fc2 */ 	srl	$t3,$t0,0x1f
/*  f0a8d1c:	15610003 */ 	bne	$t3,$at,.L0f0a8d2c
/*  f0a8d20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8d24:	03e00008 */ 	jr	$ra
/*  f0a8d28:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a8d2c:
/*  f0a8d2c:	03e00008 */ 	jr	$ra
/*  f0a8d30:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a8d34
/*  f0a8d34:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f0a8d38:	3c0f8007 */ 	lui	$t7,%hi(var80070360)
/*  f0a8d3c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0a8d40:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0a8d44:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0a8d48:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a8d4c:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f0a8d50:	25ef0360 */ 	addiu	$t7,$t7,%lo(var80070360)
/*  f0a8d54:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0a8d58:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f0a8d5c:	27ae0068 */ 	addiu	$t6,$sp,0x68
/*  f0a8d60:	3c02800a */ 	lui	$v0,0x800a
/*  f0a8d64:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0a8d68:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f0a8d6c:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a8d70:	8c491580 */ 	lw	$t1,0x1580($v0)
/*  f0a8d74:	00409025 */ 	or	$s2,$v0,$zero
/*  f0a8d78:	312a0001 */ 	andi	$t2,$t1,0x1
/*  f0a8d7c:	1140002b */ 	beqz	$t2,.L0f0a8e2c
/*  f0a8d80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8d84:	8c4b00bc */ 	lw	$t3,0xbc($v0)
/*  f0a8d88:	8d700004 */ 	lw	$s0,0x4($t3)
/*  f0a8d8c:	0fc44a54 */ 	jal	func0f112950
/*  f0a8d90:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f0a8d94:	28410002 */ 	slti	$at,$v0,0x2
/*  f0a8d98:	14200005 */ 	bnez	$at,.L0f0a8db0
/*  f0a8d9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8da0:	0fc44580 */ 	jal	func0f111600
/*  f0a8da4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8da8:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f0a8dac:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0a8db0:
/*  f0a8db0:	3c02800a */ 	lui	$v0,0x800a
/*  f0a8db4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a8db8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a8dbc:	804c1580 */ 	lb	$t4,0x1580($v0)
/*  f0a8dc0:	5181000a */ 	beql	$t4,$at,.L0f0a8dec
/*  f0a8dc4:	90591583 */ 	lbu	$t9,0x1583($v0)
/*  f0a8dc8:	804d1582 */ 	lb	$t5,0x1582($v0)
/*  f0a8dcc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a8dd0:	51a10006 */ 	beql	$t5,$at,.L0f0a8dec
/*  f0a8dd4:	90591583 */ 	lbu	$t9,0x1583($v0)
/*  f0a8dd8:	0fc2865b */ 	jal	currentPlayerEquipWeaponInCutscene
/*  f0a8ddc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a8de0:	3c02800a */ 	lui	$v0,0x800a
/*  f0a8de4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a8de8:	90591583 */ 	lbu	$t9,0x1583($v0)
.L0f0a8dec:
/*  f0a8dec:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a8df0:	3c01dfff */ 	lui	$at,0xdfff
/*  f0a8df4:	3338ff7f */ 	andi	$t8,$t9,0xff7f
/*  f0a8df8:	a0581583 */ 	sb	$t8,0x1583($v0)
/*  f0a8dfc:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a8e00:	3421ffff */ 	ori	$at,$at,0xffff
/*  f0a8e04:	adc000c4 */ 	sw	$zero,0xc4($t6)
/*  f0a8e08:	920f02e1 */ 	lbu	$t7,0x2e1($s0)
/*  f0a8e0c:	8e0b0014 */ 	lw	$t3,0x14($s0)
/*  f0a8e10:	a60002da */ 	sh	$zero,0x2da($s0)
/*  f0a8e14:	31e9ff01 */ 	andi	$t1,$t7,0xff01
/*  f0a8e18:	a20902e1 */ 	sb	$t1,0x2e1($s0)
/*  f0a8e1c:	312a00fe */ 	andi	$t2,$t1,0xfe
/*  f0a8e20:	01616024 */ 	and	$t4,$t3,$at
/*  f0a8e24:	a20a02e1 */ 	sb	$t2,0x2e1($s0)
/*  f0a8e28:	ae0c0014 */ 	sw	$t4,0x14($s0)
.L0f0a8e2c:
/*  f0a8e2c:	0fc44a54 */ 	jal	func0f112950
/*  f0a8e30:	00008825 */ 	or	$s1,$zero,$zero
/*  f0a8e34:	18400031 */ 	blez	$v0,.L0f0a8efc
/*  f0a8e38:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a8e3c:
/*  f0a8e3c:	0fc44b11 */ 	jal	func0f112c44
/*  f0a8e40:	02202025 */ 	or	$a0,$s1,$zero
/*  f0a8e44:	244dffe6 */ 	addiu	$t5,$v0,-26
/*  f0a8e48:	2da10026 */ 	sltiu	$at,$t5,0x26
/*  f0a8e4c:	10200026 */ 	beqz	$at,.L0f0a8ee8
/*  f0a8e50:	00408025 */ 	or	$s0,$v0,$zero
/*  f0a8e54:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0a8e58:	3c017f1b */ 	lui	$at,%hi(var7f1acb18)
/*  f0a8e5c:	002d0821 */ 	addu	$at,$at,$t5
/*  f0a8e60:	8c2dcb18 */ 	lw	$t5,%lo(var7f1acb18)($at)
/*  f0a8e64:	01a00008 */ 	jr	$t5
/*  f0a8e68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8e6c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a8e70:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a8e74:	1040001c */ 	beqz	$v0,.L0f0a8ee8
/*  f0a8e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8e7c:	8c59001c */ 	lw	$t9,0x1c($v0)
/*  f0a8e80:	13200019 */ 	beqz	$t9,.L0f0a8ee8
/*  f0a8e84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8e88:	0fc2a61a */ 	jal	currentPlayerGetAmmoCount
/*  f0a8e8c:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f0a8e90:	14400015 */ 	bnez	$v0,.L0f0a8ee8
/*  f0a8e94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8e98:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0a8e9c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a8ea0:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f0a8ea4:	0fc447a9 */ 	jal	func0f111ea4
/*  f0a8ea8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a8eac:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f0a8eb0:	160e000d */ 	bne	$s0,$t6,.L0f0a8ee8
/*  f0a8eb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8eb8:	0fc44727 */ 	jal	func0f111c9c
/*  f0a8ebc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a8ec0:	14400009 */ 	bnez	$v0,.L0f0a8ee8
/*  f0a8ec4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8ec8:	0fc44bdc */ 	jal	func0f112f70
/*  f0a8ecc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8ed0:	3c0f800a */ 	lui	$t7,0x800a
/*  f0a8ed4:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f0a8ed8:	0fc44b11 */ 	jal	func0f112c44
/*  f0a8edc:	8de41874 */ 	lw	$a0,0x1874($t7)
/*  f0a8ee0:	0fc2865b */ 	jal	currentPlayerEquipWeaponInCutscene
/*  f0a8ee4:	00402025 */ 	or	$a0,$v0,$zero
.L0f0a8ee8:
/*  f0a8ee8:	0fc44a54 */ 	jal	func0f112950
/*  f0a8eec:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0a8ef0:	0222082a */ 	slt	$at,$s1,$v0
/*  f0a8ef4:	1420ffd1 */ 	bnez	$at,.L0f0a8e3c
/*  f0a8ef8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a8efc:
/*  f0a8efc:	3c08800a */ 	lui	$t0,0x800a
/*  f0a8f00:	8d08a26c */ 	lw	$t0,-0x5d94($t0)
/*  f0a8f04:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a8f08:	15010007 */ 	bne	$t0,$at,.L0f0a8f28
/*  f0a8f0c:	3c09800a */ 	lui	$t1,0x800a
/*  f0a8f10:	8d29a244 */ 	lw	$t1,-0x5dbc($t1)
/*  f0a8f14:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f0a8f18:	3c0a800a */ 	lui	$t2,0x800a
/*  f0a8f1c:	a1200de0 */ 	sb	$zero,0xde0($t1)
/*  f0a8f20:	8d4aa244 */ 	lw	$t2,-0x5dbc($t2)
/*  f0a8f24:	a140063c */ 	sb	$zero,0x63c($t2)
.L0f0a8f28:
/*  f0a8f28:	8e4b1604 */ 	lw	$t3,0x1604($s2)
/*  f0a8f2c:	ae4b1608 */ 	sw	$t3,0x1608($s2)
/*  f0a8f30:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f0a8f34:	ae4c1604 */ 	sw	$t4,0x1604($s2)
/*  f0a8f38:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0a8f3c:	55a00005 */ 	bnezl	$t5,.L0f0a8f54
/*  f0a8f40:	8e581604 */ 	lw	$t8,0x1604($s2)
/*  f0a8f44:	11600002 */ 	beqz	$t3,.L0f0a8f50
/*  f0a8f48:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a8f4c:	ae461600 */ 	sw	$a2,0x1600($s2)
.L0f0a8f50:
/*  f0a8f50:	8e581604 */ 	lw	$t8,0x1604($s2)
.L0f0a8f54:
/*  f0a8f54:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a8f58:	3c0f800a */ 	lui	$t7,0x800a
/*  f0a8f5c:	5300006c */ 	beqzl	$t8,.L0f0a9110
/*  f0a8f60:	ae40160c */ 	sw	$zero,0x160c($s2)
/*  f0a8f64:	8e4e160c */ 	lw	$t6,0x160c($s2)
/*  f0a8f68:	8def9ff4 */ 	lw	$t7,-0x600c($t7)
/*  f0a8f6c:	82490de4 */ 	lb	$t1,0xde4($s2)
/*  f0a8f70:	01cf4021 */ 	addu	$t0,$t6,$t7
/*  f0a8f74:	11200043 */ 	beqz	$t1,.L0f0a9084
/*  f0a8f78:	ae48160c */ 	sw	$t0,0x160c($s2)
/*  f0a8f7c:	824a0640 */ 	lb	$t2,0x640($s2)
/*  f0a8f80:	51400041 */ 	beqzl	$t2,.L0f0a9088
/*  f0a8f84:	8e421610 */ 	lw	$v0,0x1610($s2)
/*  f0a8f88:	824b1580 */ 	lb	$t3,0x1580($s2)
/*  f0a8f8c:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0a8f90:	1161003c */ 	beq	$t3,$at,.L0f0a9084
/*  f0a8f94:	29010051 */ 	slti	$at,$t0,0x51
/*  f0a8f98:	54200020 */ 	bnezl	$at,.L0f0a901c
/*  f0a8f9c:	8e4f1608 */ 	lw	$t7,0x1608($s2)
/*  f0a8fa0:	8e4d1610 */ 	lw	$t5,0x1610($s2)
/*  f0a8fa4:	000dc880 */ 	sll	$t9,$t5,0x2
/*  f0a8fa8:	03b9c021 */ 	addu	$t8,$sp,$t9
/*  f0a8fac:	af060068 */ 	sw	$a2,0x68($t8)
/*  f0a8fb0:	8e4e1610 */ 	lw	$t6,0x1610($s2)
/*  f0a8fb4:	0fc26402 */ 	jal	func0f099008
/*  f0a8fb8:	00ce2023 */ 	subu	$a0,$a2,$t6
/*  f0a8fbc:	5440000f */ 	bnezl	$v0,.L0f0a8ffc
/*  f0a8fc0:	8e4d1610 */ 	lw	$t5,0x1610($s2)
/*  f0a8fc4:	8e4f1610 */ 	lw	$t7,0x1610($s2)
/*  f0a8fc8:	000f4100 */ 	sll	$t0,$t7,0x4
/*  f0a8fcc:	010f4023 */ 	subu	$t0,$t0,$t7
/*  f0a8fd0:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0a8fd4:	010f4021 */ 	addu	$t0,$t0,$t7
/*  f0a8fd8:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f0a8fdc:	010f4021 */ 	addu	$t0,$t0,$t7
/*  f0a8fe0:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0a8fe4:	00084823 */ 	negu	$t1,$t0
/*  f0a8fe8:	02495021 */ 	addu	$t2,$s2,$t1
/*  f0a8fec:	8d4b0de8 */ 	lw	$t3,0xde8($t2)
/*  f0a8ff0:	11600007 */ 	beqz	$t3,.L0f0a9010
/*  f0a8ff4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a8ff8:	8e4d1610 */ 	lw	$t5,0x1610($s2)
.L0f0a8ffc:
/*  f0a8ffc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0a9000:	000dc880 */ 	sll	$t9,$t5,0x2
/*  f0a9004:	0019c023 */ 	negu	$t8,$t9
/*  f0a9008:	03b87021 */ 	addu	$t6,$sp,$t8
/*  f0a900c:	adcc006c */ 	sw	$t4,0x6c($t6)
.L0f0a9010:
/*  f0a9010:	10000040 */ 	beqz	$zero,.L0f0a9114
/*  f0a9014:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a9018:	8e4f1608 */ 	lw	$t7,0x1608($s2)
.L0f0a901c:
/*  f0a901c:	55e0000f */ 	bnezl	$t7,.L0f0a905c
/*  f0a9020:	8e4d1610 */ 	lw	$t5,0x1610($s2)
/*  f0a9024:	8e481610 */ 	lw	$t0,0x1610($s2)
/*  f0a9028:	0fc26402 */ 	jal	func0f099008
/*  f0a902c:	00c82023 */ 	subu	$a0,$a2,$t0
/*  f0a9030:	54400006 */ 	bnezl	$v0,.L0f0a904c
/*  f0a9034:	8e491610 */ 	lw	$t1,0x1610($s2)
/*  f0a9038:	0fc26402 */ 	jal	func0f099008
/*  f0a903c:	8e441610 */ 	lw	$a0,0x1610($s2)
/*  f0a9040:	54400006 */ 	bnezl	$v0,.L0f0a905c
/*  f0a9044:	8e4d1610 */ 	lw	$t5,0x1610($s2)
/*  f0a9048:	8e491610 */ 	lw	$t1,0x1610($s2)
.L0f0a904c:
/*  f0a904c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0a9050:	01495823 */ 	subu	$t3,$t2,$t1
/*  f0a9054:	ae4b1610 */ 	sw	$t3,0x1610($s2)
/*  f0a9058:	8e4d1610 */ 	lw	$t5,0x1610($s2)
.L0f0a905c:
/*  f0a905c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a9060:	000dc880 */ 	sll	$t9,$t5,0x2
/*  f0a9064:	03b96021 */ 	addu	$t4,$sp,$t9
/*  f0a9068:	ad860068 */ 	sw	$a2,0x68($t4)
/*  f0a906c:	8e581610 */ 	lw	$t8,0x1610($s2)
/*  f0a9070:	00187080 */ 	sll	$t6,$t8,0x2
/*  f0a9074:	000e7823 */ 	negu	$t7,$t6
/*  f0a9078:	03af4021 */ 	addu	$t0,$sp,$t7
/*  f0a907c:	10000024 */ 	beqz	$zero,.L0f0a9110
/*  f0a9080:	ad00006c */ 	sw	$zero,0x6c($t0)
.L0f0a9084:
/*  f0a9084:	8e421610 */ 	lw	$v0,0x1610($s2)
.L0f0a9088:
/*  f0a9088:	00021900 */ 	sll	$v1,$v0,0x4
/*  f0a908c:	00621823 */ 	subu	$v1,$v1,$v0
/*  f0a9090:	00031880 */ 	sll	$v1,$v1,0x2
/*  f0a9094:	00621821 */ 	addu	$v1,$v1,$v0
/*  f0a9098:	000318c0 */ 	sll	$v1,$v1,0x3
/*  f0a909c:	00621821 */ 	addu	$v1,$v1,$v0
/*  f0a90a0:	00031880 */ 	sll	$v1,$v1,0x2
/*  f0a90a4:	02435021 */ 	addu	$t2,$s2,$v1
/*  f0a90a8:	81490640 */ 	lb	$t1,0x640($t2)
/*  f0a90ac:	00035823 */ 	negu	$t3,$v1
/*  f0a90b0:	024b6821 */ 	addu	$t5,$s2,$t3
/*  f0a90b4:	55200007 */ 	bnezl	$t1,.L0f0a90d4
/*  f0a90b8:	82581580 */ 	lb	$t8,0x1580($s2)
/*  f0a90bc:	81b90de4 */ 	lb	$t9,0xde4($t5)
/*  f0a90c0:	00c26023 */ 	subu	$t4,$a2,$v0
/*  f0a90c4:	53200003 */ 	beqzl	$t9,.L0f0a90d4
/*  f0a90c8:	82581580 */ 	lb	$t8,0x1580($s2)
/*  f0a90cc:	ae4c1610 */ 	sw	$t4,0x1610($s2)
/*  f0a90d0:	82581580 */ 	lb	$t8,0x1580($s2)
.L0f0a90d4:
/*  f0a90d4:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0a90d8:	57010003 */ 	bnel	$t8,$at,.L0f0a90e8
/*  f0a90dc:	8e4e1610 */ 	lw	$t6,0x1610($s2)
/*  f0a90e0:	ae401610 */ 	sw	$zero,0x1610($s2)
/*  f0a90e4:	8e4e1610 */ 	lw	$t6,0x1610($s2)
.L0f0a90e8:
/*  f0a90e8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0a90ec:	03af4021 */ 	addu	$t0,$sp,$t7
/*  f0a90f0:	ad060068 */ 	sw	$a2,0x68($t0)
/*  f0a90f4:	8e4a1610 */ 	lw	$t2,0x1610($s2)
/*  f0a90f8:	000a4880 */ 	sll	$t1,$t2,0x2
/*  f0a90fc:	00095823 */ 	negu	$t3,$t1
/*  f0a9100:	03ab6821 */ 	addu	$t5,$sp,$t3
/*  f0a9104:	10000002 */ 	beqz	$zero,.L0f0a9110
/*  f0a9108:	ada0006c */ 	sw	$zero,0x6c($t5)
/*  f0a910c:	ae40160c */ 	sw	$zero,0x160c($s2)
.L0f0a9110:
/*  f0a9110:	00002025 */ 	or	$a0,$zero,$zero
.L0f0a9114:
/*  f0a9114:	0fc2a244 */ 	jal	func0f0a8910
/*  f0a9118:	8fa50068 */ 	lw	$a1,0x68($sp)
/*  f0a911c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a9120:	0fc2a244 */ 	jal	func0f0a8910
/*  f0a9124:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0a9128:	3c19800a */ 	lui	$t9,0x800a
/*  f0a912c:	8f39a26c */ 	lw	$t9,-0x5d94($t9)
/*  f0a9130:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a9134:	3c0c800a */ 	lui	$t4,0x800a
/*  f0a9138:	17210038 */ 	bne	$t9,$at,.L0f0a921c
/*  f0a913c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9140:	8d8c9ff4 */ 	lw	$t4,-0x600c($t4)
/*  f0a9144:	19800035 */ 	blez	$t4,.L0f0a921c
/*  f0a9148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a914c:	0fc27371 */ 	jal	func0f09cdc4
/*  f0a9150:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a9154:	0fc27371 */ 	jal	func0f09cdc4
/*  f0a9158:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a915c:	0fc273a3 */ 	jal	func0f09ce8c
/*  f0a9160:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9164:	0fc41b99 */ 	jal	cheatIsActive
/*  f0a9168:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0a916c:	10400025 */ 	beqz	$v0,.L0f0a9204
/*  f0a9170:	3c02800a */ 	lui	$v0,0x800a
/*  f0a9174:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a9178:	24580ddc */ 	addiu	$t8,$v0,0xddc
/*  f0a917c:	afb80044 */ 	sw	$t8,0x44($sp)
/*  f0a9180:	24510638 */ 	addiu	$s1,$v0,0x638
/*  f0a9184:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a9188:	92240000 */ 	lbu	$a0,0x0($s1)
/*  f0a918c:	00408025 */ 	or	$s0,$v0,$zero
/*  f0a9190:	00003025 */ 	or	$a2,$zero,$zero
.L0f0a9194:
/*  f0a9194:	12000013 */ 	beqz	$s0,.L0f0a91e4
/*  f0a9198:	00062880 */ 	sll	$a1,$a2,0x2
/*  f0a919c:	02057021 */ 	addu	$t6,$s0,$a1
/*  f0a91a0:	8dc2001c */ 	lw	$v0,0x1c($t6)
/*  f0a91a4:	50400010 */ 	beqzl	$v0,.L0f0a91e8
/*  f0a91a8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0a91ac:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f0a91b0:	afa6004c */ 	sw	$a2,0x4c($sp)
/*  f0a91b4:	0fc2a644 */ 	jal	func0f0a9910
/*  f0a91b8:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f0a91bc:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f0a91c0:	10400008 */ 	beqz	$v0,.L0f0a91e4
/*  f0a91c4:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0a91c8:	02251021 */ 	addu	$v0,$s1,$a1
/*  f0a91cc:	8c4f0228 */ 	lw	$t7,0x228($v0)
/*  f0a91d0:	ac4f0220 */ 	sw	$t7,0x220($v0)
/*  f0a91d4:	8fa80044 */ 	lw	$t0,0x44($sp)
/*  f0a91d8:	01051821 */ 	addu	$v1,$t0,$a1
/*  f0a91dc:	8c6a0228 */ 	lw	$t2,0x228($v1)
/*  f0a91e0:	ac6a0220 */ 	sw	$t2,0x220($v1)
.L0f0a91e4:
/*  f0a91e4:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f0a91e8:
/*  f0a91e8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a91ec:	14c1ffe9 */ 	bne	$a2,$at,.L0f0a9194
/*  f0a91f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a91f4:	0fc2a660 */ 	jal	func0f0a9980
/*  f0a91f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a91fc:	10000007 */ 	beqz	$zero,.L0f0a921c
/*  f0a9200:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a9204:
/*  f0a9204:	0fc41b99 */ 	jal	cheatIsActive
/*  f0a9208:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0a920c:	10400003 */ 	beqz	$v0,.L0f0a921c
/*  f0a9210:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9214:	0fc2a660 */ 	jal	func0f0a9980
/*  f0a9218:	00002025 */ 	or	$a0,$zero,$zero
.L0f0a921c:
/*  f0a921c:	0fc273e2 */ 	jal	func0f09cf88
/*  f0a9220:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9224:	86491618 */ 	lh	$t1,0x1618($s2)
/*  f0a9228:	27b0003c */ 	addiu	$s0,$sp,0x3c
/*  f0a922c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a9230:	11200009 */ 	beqz	$t1,.L0f0a9258
/*  f0a9234:	3c0d800a */ 	lui	$t5,0x800a
/*  f0a9238:	3c0b800a */ 	lui	$t3,0x800a
/*  f0a923c:	8d6ba244 */ 	lw	$t3,-0x5dbc($t3)
/*  f0a9240:	26451614 */ 	addiu	$a1,$s2,0x1614
/*  f0a9244:	9646161a */ 	lhu	$a2,0x161a($s2)
/*  f0a9248:	0fc1a451 */ 	jal	func0f069144
/*  f0a924c:	8d6400bc */ 	lw	$a0,0xbc($t3)
/*  f0a9250:	10000008 */ 	beqz	$zero,.L0f0a9274
/*  f0a9254:	a6401618 */ 	sh	$zero,0x1618($s2)
.L0f0a9258:
/*  f0a9258:	8dada244 */ 	lw	$t5,-0x5dbc($t5)
/*  f0a925c:	9646161a */ 	lhu	$a2,0x161a($s2)
/*  f0a9260:	0fc1a451 */ 	jal	func0f069144
/*  f0a9264:	8da400bc */ 	lw	$a0,0xbc($t5)
/*  f0a9268:	26441614 */ 	addiu	$a0,$s2,0x1614
/*  f0a926c:	0fc1a5c4 */ 	jal	func0f069710
/*  f0a9270:	02002825 */ 	or	$a1,$s0,$zero
.L0f0a9274:
/*  f0a9274:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0a9278:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a927c:	00408025 */ 	or	$s0,$v0,$zero
/*  f0a9280:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0a9284:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a9288:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a928c:	0fc44c1f */ 	jal	func0f11307c
/*  f0a9290:	00402825 */ 	or	$a1,$v0,$zero
/*  f0a9294:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0a9298:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a929c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0a92a0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0a92a4:	03e00008 */ 	jr	$ra
/*  f0a92a8:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func0f0a92ac
/*  f0a92ac:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0a92b0:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0a92b4:	8d2e006c */ 	lw	$t6,0x6c($t1)
/*  f0a92b8:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f0a92bc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a92c0:	11c00003 */ 	beqz	$t6,.L0f0a92d0
/*  f0a92c4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a92c8:	10000001 */ 	beqz	$zero,.L0f0a92d0
/*  f0a92cc:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a92d0:
/*  f0a92d0:	8d2f0068 */ 	lw	$t7,0x68($t1)
/*  f0a92d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a92d8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a92dc:	11e00003 */ 	beqz	$t7,.L0f0a92ec
/*  f0a92e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0a92e4:	10000001 */ 	beqz	$zero,.L0f0a92ec
/*  f0a92e8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0a92ec:
/*  f0a92ec:	8d380064 */ 	lw	$t8,0x64($t1)
/*  f0a92f0:	8fae0000 */ 	lw	$t6,0x0($sp)
/*  f0a92f4:	13000003 */ 	beqz	$t8,.L0f0a9304
/*  f0a92f8:	31c80001 */ 	andi	$t0,$t6,0x1
/*  f0a92fc:	10000001 */ 	beqz	$zero,.L0f0a9304
/*  f0a9300:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0a9304:
/*  f0a9304:	8d390070 */ 	lw	$t9,0x70($t1)
/*  f0a9308:	00026880 */ 	sll	$t5,$v0,0x2
/*  f0a930c:	012d3821 */ 	addu	$a3,$t1,$t5
/*  f0a9310:	13200003 */ 	beqz	$t9,.L0f0a9320
/*  f0a9314:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9318:	10000001 */ 	beqz	$zero,.L0f0a9320
/*  f0a931c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0a9320:
/*  f0a9320:	00c55021 */ 	addu	$t2,$a2,$a1
/*  f0a9324:	01445821 */ 	addu	$t3,$t2,$a0
/*  f0a9328:	01636021 */ 	addu	$t4,$t3,$v1
/*  f0a932c:	19800026 */ 	blez	$t4,.L0f0a93c8
/*  f0a9330:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9334:	8ce30064 */ 	lw	$v1,0x64($a3)
.L0f0a9338:
/*  f0a9338:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0a933c:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0a9340:	90781583 */ 	lbu	$t8,0x1583($v1)
/*  f0a9344:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a9348:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a934c:	3319fffe */ 	andi	$t9,$t8,0xfffe
/*  f0a9350:	01195025 */ 	or	$t2,$t0,$t9
/*  f0a9354:	a06a1583 */ 	sb	$t2,0x1583($v1)
/*  f0a9358:	8d2b006c */ 	lw	$t3,0x6c($t1)
/*  f0a935c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a9360:	00003025 */ 	or	$a2,$zero,$zero
/*  f0a9364:	11600003 */ 	beqz	$t3,.L0f0a9374
/*  f0a9368:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a936c:	10000001 */ 	beqz	$zero,.L0f0a9374
/*  f0a9370:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a9374:
/*  f0a9374:	8d2c0068 */ 	lw	$t4,0x68($t1)
/*  f0a9378:	11800003 */ 	beqz	$t4,.L0f0a9388
/*  f0a937c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9380:	10000001 */ 	beqz	$zero,.L0f0a9388
/*  f0a9384:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0a9388:
/*  f0a9388:	8d2d0064 */ 	lw	$t5,0x64($t1)
/*  f0a938c:	11a00003 */ 	beqz	$t5,.L0f0a939c
/*  f0a9390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9394:	10000001 */ 	beqz	$zero,.L0f0a939c
/*  f0a9398:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0a939c:
/*  f0a939c:	8d2e0070 */ 	lw	$t6,0x70($t1)
/*  f0a93a0:	11c00003 */ 	beqz	$t6,.L0f0a93b0
/*  f0a93a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a93a8:	10000001 */ 	beqz	$zero,.L0f0a93b0
/*  f0a93ac:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0a93b0:
/*  f0a93b0:	00c57821 */ 	addu	$t7,$a2,$a1
/*  f0a93b4:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f0a93b8:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f0a93bc:	0059082a */ 	slt	$at,$v0,$t9
/*  f0a93c0:	5420ffdd */ 	bnezl	$at,.L0f0a9338
/*  f0a93c4:	8ce30064 */ 	lw	$v1,0x64($a3)
.L0f0a93c8:
/*  f0a93c8:	03e00008 */ 	jr	$ra
/*  f0a93cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a93d0
/*  f0a93d0:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a93d4:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0a93d8:	03e00008 */ 	jr	$ra
/*  f0a93dc:	adc41620 */ 	sw	$a0,0x1620($t6)
);

GLOBAL_ASM(
glabel func0f0a93e0
/*  f0a93e0:	3c02800a */ 	lui	$v0,0x800a
/*  f0a93e4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a93e8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0a93ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a93f0:	00802825 */ 	or	$a1,$a0,$zero
/*  f0a93f4:	afa50020 */ 	sw	$a1,0x20($sp)
/*  f0a93f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a93fc:	0fc2c4bb */ 	jal	func0f0b12ec
/*  f0a9400:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0a9404:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f0a9408:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f0a940c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a9410:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f0a9414:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f0a9418:	e44607f8 */ 	swc1	$f6,0x7f8($v0)
/*  f0a941c:	c4a80004 */ 	lwc1	$f8,0x4($a1)
/*  f0a9420:	e44807fc */ 	swc1	$f8,0x7fc($v0)
/*  f0a9424:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f0a9428:	0fc2c4bb */ 	jal	func0f0b12ec
/*  f0a942c:	e44a0800 */ 	swc1	$f10,0x800($v0)
/*  f0a9430:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f0a9434:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f0a9438:	c4b00000 */ 	lwc1	$f16,0x0($a1)
/*  f0a943c:	46100480 */ 	add.s	$f18,$f0,$f16
/*  f0a9440:	e4520f9c */ 	swc1	$f18,0xf9c($v0)
/*  f0a9444:	c4a40004 */ 	lwc1	$f4,0x4($a1)
/*  f0a9448:	e4440fa0 */ 	swc1	$f4,0xfa0($v0)
/*  f0a944c:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*  f0a9450:	e4460fa4 */ 	swc1	$f6,0xfa4($v0)
/*  f0a9454:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a9458:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0a945c:	03e00008 */ 	jr	$ra
/*  f0a9460:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a9464
/*  f0a9464:	3c02800a */ 	lui	$v0,0x800a
/*  f0a9468:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a946c:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f0a9470:	e4400b94 */ 	swc1	$f0,0xb94($v0)
/*  f0a9474:	e4401338 */ 	swc1	$f0,0x1338($v0)
/*  f0a9478:	c4800004 */ 	lwc1	$f0,0x4($a0)
/*  f0a947c:	e4400b98 */ 	swc1	$f0,0xb98($v0)
/*  f0a9480:	e440133c */ 	swc1	$f0,0x133c($v0)
/*  f0a9484:	c4800008 */ 	lwc1	$f0,0x8($a0)
/*  f0a9488:	e4400b9c */ 	swc1	$f0,0xb9c($v0)
/*  f0a948c:	03e00008 */ 	jr	$ra
/*  f0a9490:	e4401340 */ 	swc1	$f0,0x1340($v0)
);

GLOBAL_ASM(
glabel func0f0a9494
/*  f0a9494:	10800006 */ 	beqz	$a0,.L0f0a94b0
/*  f0a9498:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a949c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a94a0:	10810009 */ 	beq	$a0,$at,.L0f0a94c8
/*  f0a94a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a94a8:	03e00008 */ 	jr	$ra
/*  f0a94ac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a94b0:
/*  f0a94b0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a94b4:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f0a94b8:	adc00cec */ 	sw	$zero,0xcec($t6)
/*  f0a94bc:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0a94c0:	8c4f0cec */ 	lw	$t7,0xcec($v0)
/*  f0a94c4:	ac4f1490 */ 	sw	$t7,0x1490($v0)
.L0f0a94c8:
/*  f0a94c8:	03e00008 */ 	jr	$ra
/*  f0a94cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a94d0
/*  f0a94d0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a94d4:	3c02800a */ 	lui	$v0,0x800a
/*  f0a94d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a94dc:	00803825 */ 	or	$a3,$a0,$zero
/*  f0a94e0:	10800008 */ 	beqz	$a0,.L0f0a9504
/*  f0a94e4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a94e8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a94ec:	10830039 */ 	beq	$a0,$v1,.L0f0a95d4
/*  f0a94f0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a94f4:	10810037 */ 	beq	$a0,$at,.L0f0a95d4
/*  f0a94f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a94fc:	10000038 */ 	beqz	$zero,.L0f0a95e0
/*  f0a9500:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0a9504:
/*  f0a9504:	3c017f1b */ 	lui	$at,%hi(var7f1acbb0)
/*  f0a9508:	c422cbb0 */ 	lwc1	$f2,%lo(var7f1acbb0)($at)
/*  f0a950c:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*  f0a9510:	3c017f1b */ 	lui	$at,%hi(var7f1acbb4)
/*  f0a9514:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a9518:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a951c:	45020030 */ 	bc1fl	.L0f0a95e0
/*  f0a9520:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a9524:	c42ccbb4 */ 	lwc1	$f12,%lo(var7f1acbb4)($at)
/*  f0a9528:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0a952c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9530:	4502002b */ 	bc1fl	.L0f0a95e0
/*  f0a9534:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a9538:	c4a00004 */ 	lwc1	$f0,0x4($a1)
/*  f0a953c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a9540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9544:	45020026 */ 	bc1fl	.L0f0a95e0
/*  f0a9548:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a954c:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0a9550:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9554:	45020022 */ 	bc1fl	.L0f0a95e0
/*  f0a9558:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a955c:	c4a00008 */ 	lwc1	$f0,0x8($a1)
/*  f0a9560:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a9564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9568:	4502001d */ 	bc1fl	.L0f0a95e0
/*  f0a956c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a9570:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0a9574:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a9578:	45020019 */ 	bc1fl	.L0f0a95e0
/*  f0a957c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a9580:	ac430cec */ 	sw	$v1,0xcec($v0)
/*  f0a9584:	ac431490 */ 	sw	$v1,0x1490($v0)
/*  f0a9588:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*  f0a958c:	e4400cf0 */ 	swc1	$f0,0xcf0($v0)
/*  f0a9590:	e4401494 */ 	swc1	$f0,0x1494($v0)
/*  f0a9594:	c4a00004 */ 	lwc1	$f0,0x4($a1)
/*  f0a9598:	e4400cf4 */ 	swc1	$f0,0xcf4($v0)
/*  f0a959c:	e4401498 */ 	swc1	$f0,0x1498($v0)
/*  f0a95a0:	c4a00008 */ 	lwc1	$f0,0x8($a1)
/*  f0a95a4:	e4400cf8 */ 	swc1	$f0,0xcf8($v0)
/*  f0a95a8:	e440149c */ 	swc1	$f0,0x149c($v0)
/*  f0a95ac:	c4c00000 */ 	lwc1	$f0,0x0($a2)
/*  f0a95b0:	e4400cfc */ 	swc1	$f0,0xcfc($v0)
/*  f0a95b4:	e44014a0 */ 	swc1	$f0,0x14a0($v0)
/*  f0a95b8:	c4c00004 */ 	lwc1	$f0,0x4($a2)
/*  f0a95bc:	e4400d00 */ 	swc1	$f0,0xd00($v0)
/*  f0a95c0:	e44014a4 */ 	swc1	$f0,0x14a4($v0)
/*  f0a95c4:	c4c00008 */ 	lwc1	$f0,0x8($a2)
/*  f0a95c8:	e4400d04 */ 	swc1	$f0,0xd04($v0)
/*  f0a95cc:	10000003 */ 	beqz	$zero,.L0f0a95dc
/*  f0a95d0:	e44014a8 */ 	swc1	$f0,0x14a8($v0)
.L0f0a95d4:
/*  f0a95d4:	0fc2c0d0 */ 	jal	func0f0b0340
/*  f0a95d8:	24e4ffff */ 	addiu	$a0,$a3,-1
.L0f0a95dc:
/*  f0a95dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0a95e0:
/*  f0a95e0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a95e4:	03e00008 */ 	jr	$ra
/*  f0a95e8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a95ec
/*  f0a95ec:	10a00008 */ 	beqz	$a1,.L0f0a9610
/*  f0a95f0:	3c02800a */ 	lui	$v0,0x800a
/*  f0a95f4:	3c02800a */ 	lui	$v0,0x800a
/*  f0a95f8:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a95fc:	00807827 */ 	nor	$t7,$a0,$zero
/*  f0a9600:	8c4e16d8 */ 	lw	$t6,0x16d8($v0)
/*  f0a9604:	01cfc024 */ 	and	$t8,$t6,$t7
/*  f0a9608:	03e00008 */ 	jr	$ra
/*  f0a960c:	ac5816d8 */ 	sw	$t8,0x16d8($v0)
.L0f0a9610:
/*  f0a9610:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0a9614:	8c5916d8 */ 	lw	$t9,0x16d8($v0)
/*  f0a9618:	03244025 */ 	or	$t0,$t9,$a0
/*  f0a961c:	ac4816d8 */ 	sw	$t0,0x16d8($v0)
/*  f0a9620:	03e00008 */ 	jr	$ra
/*  f0a9624:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel currentPlayerGiveAmmo
/*  f0a9628:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0a962c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0a9630:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0a9634:	00809025 */ 	or	$s2,$a0,$zero
/*  f0a9638:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0a963c:	3c11800a */ 	lui	$s1,0x800a
/*  f0a9640:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a9644:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0a9648:	8e31a244 */ 	lw	$s1,-0x5dbc($s1)
/*  f0a964c:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0a9650:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a9654:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f0a9658:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f0a965c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a9660:	0fc2a685 */ 	jal	func0f0a9a14
/*  f0a9664:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a9668:	14520002 */ 	bne	$v0,$s2,.L0f0a9674
/*  f0a966c:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f0a9670:	00008025 */ 	or	$s0,$zero,$zero
.L0f0a9674:
/*  f0a9674:	0fc2a685 */ 	jal	func0f0a9a14
/*  f0a9678:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a967c:	14520002 */ 	bne	$v0,$s2,.L0f0a9688
/*  f0a9680:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0a9684:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0a9688:
/*  f0a9688:	12010013 */ 	beq	$s0,$at,.L0f0a96d8
/*  f0a968c:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f0a9690:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a9694:	0fc2c613 */ 	jal	func0f0b184c
/*  f0a9698:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a969c:	1040000e */ 	beqz	$v0,.L0f0a96d8
/*  f0a96a0:	00107080 */ 	sll	$t6,$s0,0x2
/*  f0a96a4:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f0a96a8:	8c4f0858 */ 	lw	$t7,0x858($v0)
/*  f0a96ac:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0a96b0:	8c430860 */ 	lw	$v1,0x860($v0)
/*  f0a96b4:	00124880 */ 	sll	$t1,$s2,0x2
/*  f0a96b8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0a96bc:	0079082a */ 	slt	$at,$v1,$t9
/*  f0a96c0:	10200002 */ 	beqz	$at,.L0f0a96cc
/*  f0a96c4:	ac590858 */ 	sw	$t9,0x858($v0)
/*  f0a96c8:	ac430858 */ 	sw	$v1,0x858($v0)
.L0f0a96cc:
/*  f0a96cc:	02295021 */ 	addu	$t2,$s1,$t1
/*  f0a96d0:	10000021 */ 	beqz	$zero,.L0f0a9758
/*  f0a96d4:	ad4017a8 */ 	sw	$zero,0x17a8($t2)
.L0f0a96d8:
/*  f0a96d8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0a96dc:	1201000d */ 	beq	$s0,$at,.L0f0a9714
/*  f0a96e0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a96e4:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f0a96e8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a96ec:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0a96f0:	0fc2c613 */ 	jal	func0f0b184c
/*  f0a96f4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0a96f8:	10400006 */ 	beqz	$v0,.L0f0a9714
/*  f0a96fc:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f0a9700:	00105880 */ 	sll	$t3,$s0,0x2
/*  f0a9704:	022b1021 */ 	addu	$v0,$s1,$t3
/*  f0a9708:	8c4c0ffc */ 	lw	$t4,0xffc($v0)
/*  f0a970c:	8c4d0858 */ 	lw	$t5,0x858($v0)
/*  f0a9710:	018d1821 */ 	addu	$v1,$t4,$t5
.L0f0a9714:
/*  f0a9714:	00127080 */ 	sll	$t6,$s2,0x2
/*  f0a9718:	01d27023 */ 	subu	$t6,$t6,$s2
/*  f0a971c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0a9720:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0a9724:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0a9728:	8def0368 */ 	lw	$t7,0x368($t7)
/*  f0a972c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0a9730:	00124080 */ 	sll	$t0,$s2,0x2
/*  f0a9734:	01e31023 */ 	subu	$v0,$t7,$v1
/*  f0a9738:	0044082a */ 	slt	$at,$v0,$a0
/*  f0a973c:	10200005 */ 	beqz	$at,.L0f0a9754
/*  f0a9740:	02284821 */ 	addu	$t1,$s1,$t0
/*  f0a9744:	0012c080 */ 	sll	$t8,$s2,0x2
/*  f0a9748:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f0a974c:	10000002 */ 	beqz	$zero,.L0f0a9758
/*  f0a9750:	af2217a8 */ 	sw	$v0,0x17a8($t9)
.L0f0a9754:
/*  f0a9754:	ad2417a8 */ 	sw	$a0,0x17a8($t1)
.L0f0a9758:
/*  f0a9758:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0a975c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a9760:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0a9764:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0a9768:	03e00008 */ 	jr	$ra
/*  f0a976c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f0a9770
/*  f0a9770:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0a9774:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0a9778:	3c02800a */ 	lui	$v0,0x800a
/*  f0a977c:	8c55a244 */ 	lw	$s5,-0x5dbc($v0)
/*  f0a9780:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f0a9784:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f0a9788:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0a978c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0a9790:	00047080 */ 	sll	$t6,$a0,0x2
/*  f0a9794:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0a9798:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0a979c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0a97a0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0a97a4:	02ae7821 */ 	addu	$t7,$s5,$t6
/*  f0a97a8:	0080b825 */ 	or	$s7,$a0,$zero
/*  f0a97ac:	8df217a8 */ 	lw	$s2,0x17a8($t7)
/*  f0a97b0:	24130002 */ 	addiu	$s3,$zero,0x2
/*  f0a97b4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a97b8:	02a0b025 */ 	or	$s6,$s5,$zero
.L0f0a97bc:
/*  f0a97bc:	82b80640 */ 	lb	$t8,0x640($s5)
/*  f0a97c0:	00008025 */ 	or	$s0,$zero,$zero
/*  f0a97c4:	02c08825 */ 	or	$s1,$s6,$zero
/*  f0a97c8:	53000019 */ 	beqzl	$t8,.L0f0a9830
/*  f0a97cc:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f0a97d0:
/*  f0a97d0:	823915e4 */ 	lb	$t9,0x15e4($s1)
/*  f0a97d4:	02002825 */ 	or	$a1,$s0,$zero
/*  f0a97d8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a97dc:	56f90011 */ 	bnel	$s7,$t9,.L0f0a9824
/*  f0a97e0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0a97e4:	0fc2c613 */ 	jal	func0f0b184c
/*  f0a97e8:	92a40638 */ 	lbu	$a0,0x638($s5)
/*  f0a97ec:	1040000c */ 	beqz	$v0,.L0f0a9820
/*  f0a97f0:	00144100 */ 	sll	$t0,$s4,0x4
/*  f0a97f4:	01144023 */ 	subu	$t0,$t0,$s4
/*  f0a97f8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0a97fc:	01144021 */ 	addu	$t0,$t0,$s4
/*  f0a9800:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f0a9804:	01144021 */ 	addu	$t0,$t0,$s4
/*  f0a9808:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0a980c:	02c84821 */ 	addu	$t1,$s6,$t0
/*  f0a9810:	00105080 */ 	sll	$t2,$s0,0x2
/*  f0a9814:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f0a9818:	8d6c0858 */ 	lw	$t4,0x858($t3)
/*  f0a981c:	01929021 */ 	addu	$s2,$t4,$s2
.L0f0a9820:
/*  f0a9820:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0a9824:
/*  f0a9824:	1613ffea */ 	bne	$s0,$s3,.L0f0a97d0
/*  f0a9828:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0a982c:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f0a9830:
/*  f0a9830:	1693ffe2 */ 	bne	$s4,$s3,.L0f0a97bc
/*  f0a9834:	26b507a4 */ 	addiu	$s5,$s5,0x7a4
/*  f0a9838:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0a983c:	02401025 */ 	or	$v0,$s2,$zero
/*  f0a9840:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0a9844:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0a9848:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0a984c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0a9850:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0a9854:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0a9858:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f0a985c:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f0a9860:	03e00008 */ 	jr	$ra
/*  f0a9864:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel currentPlayerGetAmmoCount
/*  f0a9868:	3c02800a */ 	lui	$v0,0x800a
/*  f0a986c:	8c47a244 */ 	lw	$a3,-0x5dbc($v0)
/*  f0a9870:	00047080 */ 	sll	$t6,$a0,0x2
/*  f0a9874:	00003025 */ 	or	$a2,$zero,$zero
/*  f0a9878:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f0a987c:	8de317a8 */ 	lw	$v1,0x17a8($t7)
/*  f0a9880:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f0a9884:	00e02825 */ 	or	$a1,$a3,$zero
.L0f0a9888:
/*  f0a9888:	80f80640 */ 	lb	$t8,0x640($a3)
/*  f0a988c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a9890:	00a04025 */ 	or	$t0,$a1,$zero
/*  f0a9894:	53000013 */ 	beqzl	$t8,.L0f0a98e4
/*  f0a9898:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f0a989c:
/*  f0a989c:	811915e4 */ 	lb	$t9,0x15e4($t0)
/*  f0a98a0:	00065100 */ 	sll	$t2,$a2,0x4
/*  f0a98a4:	01465023 */ 	subu	$t2,$t2,$a2
/*  f0a98a8:	1499000a */ 	bne	$a0,$t9,.L0f0a98d4
/*  f0a98ac:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0a98b0:	01465021 */ 	addu	$t2,$t2,$a2
/*  f0a98b4:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0a98b8:	01465021 */ 	addu	$t2,$t2,$a2
/*  f0a98bc:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0a98c0:	00aa5821 */ 	addu	$t3,$a1,$t2
/*  f0a98c4:	00026080 */ 	sll	$t4,$v0,0x2
/*  f0a98c8:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f0a98cc:	8dae0858 */ 	lw	$t6,0x858($t5)
/*  f0a98d0:	01c31821 */ 	addu	$v1,$t6,$v1
.L0f0a98d4:
/*  f0a98d4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0a98d8:	1449fff0 */ 	bne	$v0,$t1,.L0f0a989c
/*  f0a98dc:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f0a98e0:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f0a98e4:
/*  f0a98e4:	14c9ffe8 */ 	bne	$a2,$t1,.L0f0a9888
/*  f0a98e8:	24e707a4 */ 	addiu	$a3,$a3,0x7a4
/*  f0a98ec:	03e00008 */ 	jr	$ra
/*  f0a98f0:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f0a98f4
/*  f0a98f4:	00047080 */ 	sll	$t6,$a0,0x2
/*  f0a98f8:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f0a98fc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0a9900:	3c028007 */ 	lui	$v0,0x8007
/*  f0a9904:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f0a9908:	03e00008 */ 	jr	$ra
/*  f0a990c:	8c420368 */ 	lw	$v0,0x368($v0)
);

GLOBAL_ASM(
glabel func0f0a9910
/*  f0a9910:	248efff4 */ 	addiu	$t6,$a0,-12
/*  f0a9914:	2dc10015 */ 	sltiu	$at,$t6,0x15
/*  f0a9918:	10200016 */ 	beqz	$at,.L0f0a9974
/*  f0a991c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0a9920:	3c017f1b */ 	lui	$at,%hi(var7f1acbb8)
/*  f0a9924:	002e0821 */ 	addu	$at,$at,$t6
/*  f0a9928:	8c2ecbb8 */ 	lw	$t6,%lo(var7f1acbb8)($at)
/*  f0a992c:	01c00008 */ 	jr	$t6
/*  f0a9930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9934:	3c0f800a */ 	lui	$t7,0x800a
/*  f0a9938:	8defa474 */ 	lw	$t7,-0x5b8c($t7)
/*  f0a993c:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f0a9940:	55e1000d */ 	bnel	$t7,$at,.L0f0a9978
/*  f0a9944:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a9948:	03e00008 */ 	jr	$ra
/*  f0a994c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a9950:	3c18800a */ 	lui	$t8,0x800a
/*  f0a9954:	8f18a474 */ 	lw	$t8,-0x5b8c($t8)
/*  f0a9958:	24010031 */ 	addiu	$at,$zero,0x31
/*  f0a995c:	57010006 */ 	bnel	$t8,$at,.L0f0a9978
/*  f0a9960:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a9964:	03e00008 */ 	jr	$ra
/*  f0a9968:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a996c:	03e00008 */ 	jr	$ra
/*  f0a9970:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a9974:
/*  f0a9974:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a9978:
/*  f0a9978:	03e00008 */ 	jr	$ra
/*  f0a997c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a9980
/*  f0a9980:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0a9984:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0a9988:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0a998c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0a9990:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0a9994:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a9998:	3c128007 */ 	lui	$s2,%hi(var80070368)
/*  f0a999c:	00808825 */ 	or	$s1,$a0,$zero
/*  f0a99a0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0a99a4:	26520368 */ 	addiu	$s2,$s2,%lo(var80070368)
/*  f0a99a8:	00008025 */ 	or	$s0,$zero,$zero
/*  f0a99ac:	2413000c */ 	addiu	$s3,$zero,0xc
/*  f0a99b0:	24140021 */ 	addiu	$s4,$zero,0x21
.L0f0a99b4:
/*  f0a99b4:	16200004 */ 	bnez	$s1,.L0f0a99c8
/*  f0a99b8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a99bc:	0fc2a644 */ 	jal	func0f0a9910
/*  f0a99c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a99c4:	00401825 */ 	or	$v1,$v0,$zero
.L0f0a99c8:
/*  f0a99c8:	50600008 */ 	beqzl	$v1,.L0f0a99ec
/*  f0a99cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0a99d0:	02130019 */ 	multu	$s0,$s3
/*  f0a99d4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a99d8:	00007012 */ 	mflo	$t6
/*  f0a99dc:	024e7821 */ 	addu	$t7,$s2,$t6
/*  f0a99e0:	0fc2a58a */ 	jal	currentPlayerGiveAmmo
/*  f0a99e4:	8de50000 */ 	lw	$a1,0x0($t7)
/*  f0a99e8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0a99ec:
/*  f0a99ec:	1614fff1 */ 	bne	$s0,$s4,.L0f0a99b4
/*  f0a99f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a99f4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0a99f8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a99fc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0a9a00:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0a9a04:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0a9a08:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0a9a0c:	03e00008 */ 	jr	$ra
/*  f0a9a10:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f0a9a14
/*  f0a9a14:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a9a18:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a9a1c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a9a20:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0a9a24:	14400003 */ 	bnez	$v0,.L0f0a9a34
/*  f0a9a28:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a9a2c:	1000000d */ 	beqz	$zero,.L0f0a9a64
/*  f0a9a30:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a9a34:
/*  f0a9a34:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0a9a38:	00037080 */ 	sll	$t6,$v1,0x2
/*  f0a9a3c:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0a9a40:	8df8001c */ 	lw	$t8,0x1c($t7)
/*  f0a9a44:	01c01825 */ 	or	$v1,$t6,$zero
/*  f0a9a48:	0083c821 */ 	addu	$t9,$a0,$v1
/*  f0a9a4c:	57000004 */ 	bnezl	$t8,.L0f0a9a60
/*  f0a9a50:	8f28001c */ 	lw	$t0,0x1c($t9)
/*  f0a9a54:	10000003 */ 	beqz	$zero,.L0f0a9a64
/*  f0a9a58:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a9a5c:	8f28001c */ 	lw	$t0,0x1c($t9)
.L0f0a9a60:
/*  f0a9a60:	8d020000 */ 	lw	$v0,0x0($t0)
.L0f0a9a64:
/*  f0a9a64:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a9a68:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a9a6c:	03e00008 */ 	jr	$ra
/*  f0a9a70:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a9a74
/*  f0a9a74:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a9a78:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a9a7c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a9a80:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0a9a84:	1040000a */ 	beqz	$v0,.L0f0a9ab0
/*  f0a9a88:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f0a9a8c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0a9a90:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0a9a94:	8f03001c */ 	lw	$v1,0x1c($t8)
/*  f0a9a98:	50600006 */ 	beqzl	$v1,.L0f0a9ab4
/*  f0a9a9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a9aa0:	0fc2a5dc */ 	jal	func0f0a9770
/*  f0a9aa4:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f0a9aa8:	10000003 */ 	beqz	$zero,.L0f0a9ab8
/*  f0a9aac:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0a9ab0:
/*  f0a9ab0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a9ab4:
/*  f0a9ab4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0a9ab8:
/*  f0a9ab8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a9abc:	03e00008 */ 	jr	$ra
/*  f0a9ac0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a9ac4
/*  f0a9ac4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a9ac8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a9acc:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0a9ad0:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a9ad4:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0a9ad8:	10400009 */ 	beqz	$v0,.L0f0a9b00
/*  f0a9adc:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f0a9ae0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0a9ae4:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0a9ae8:	8f03001c */ 	lw	$v1,0x1c($t8)
/*  f0a9aec:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f0a9af0:	50600004 */ 	beqzl	$v1,.L0f0a9b04
/*  f0a9af4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a9af8:	0fc2a58a */ 	jal	currentPlayerGiveAmmo
/*  f0a9afc:	8c640000 */ 	lw	$a0,0x0($v1)
.L0f0a9b00:
/*  f0a9b00:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0a9b04:
/*  f0a9b04:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0a9b08:	03e00008 */ 	jr	$ra
/*  f0a9b0c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a9b10
/*  f0a9b10:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0a9b14:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0a9b18:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a9b1c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0a9b20:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f0a9b24:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0a9b28:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0a9b2c:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0a9b30:	8f03001c */ 	lw	$v1,0x1c($t8)
/*  f0a9b34:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a9b38:	10600009 */ 	beqz	$v1,.L0f0a9b60
/*  f0a9b3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9b40:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0a9b44:	3c028007 */ 	lui	$v0,0x8007
/*  f0a9b48:	00194080 */ 	sll	$t0,$t9,0x2
/*  f0a9b4c:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0a9b50:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0a9b54:	00481021 */ 	addu	$v0,$v0,$t0
/*  f0a9b58:	10000001 */ 	beqz	$zero,.L0f0a9b60
/*  f0a9b5c:	8c420368 */ 	lw	$v0,0x368($v0)
.L0f0a9b60:
/*  f0a9b60:	03e00008 */ 	jr	$ra
/*  f0a9b64:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f0a9b68
/*  f0a9b68:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0a9b6c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0a9b70:	8dcefafc */ 	lw	$t6,-0x504($t6)
/*  f0a9b74:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0a9b78:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f0a9b7c:	00c08025 */ 	or	$s0,$a2,$zero
/*  f0a9b80:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0a9b84:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0a9b88:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f0a9b8c:	3c078008 */ 	lui	$a3,0x8008
/*  f0a9b90:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f0a9b94:	afa00058 */ 	sw	$zero,0x58($sp)
/*  f0a9b98:	8ce7fb00 */ 	lw	$a3,-0x500($a3)
/*  f0a9b9c:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f0a9ba0:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f0a9ba4:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f0a9ba8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0a9bac:	afa00054 */ 	sw	$zero,0x54($sp)
/*  f0a9bb0:	afa00050 */ 	sw	$zero,0x50($sp)
/*  f0a9bb4:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f0a9bb8:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f0a9bbc:	0fc55cbe */ 	jal	func0f1572f8
/*  f0a9bc0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0a9bc4:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*  f0a9bc8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a9bcc:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f0a9bd0:	14430006 */ 	bne	$v0,$v1,.L0f0a9bec
/*  f0a9bd4:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0a9bd8:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0a9bdc:	afb0005c */ 	sw	$s0,0x5c($sp)
/*  f0a9be0:	02081021 */ 	addu	$v0,$s0,$t0
/*  f0a9be4:	10000012 */ 	beqz	$zero,.L0f0a9c30
/*  f0a9be8:	afa20054 */ 	sw	$v0,0x54($sp)
.L0f0a9bec:
/*  f0a9bec:	14400006 */ 	bnez	$v0,.L0f0a9c08
/*  f0a9bf0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a9bf4:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0a9bf8:	afb00054 */ 	sw	$s0,0x54($sp)
/*  f0a9bfc:	02087823 */ 	subu	$t7,$s0,$t0
/*  f0a9c00:	1000000b */ 	beqz	$zero,.L0f0a9c30
/*  f0a9c04:	afaf005c */ 	sw	$t7,0x5c($sp)
.L0f0a9c08:
/*  f0a9c08:	14410009 */ 	bne	$v0,$at,.L0f0a9c30
/*  f0a9c0c:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0a9c10:	05010003 */ 	bgez	$t0,.L0f0a9c20
/*  f0a9c14:	0008c043 */ 	sra	$t8,$t0,0x1
/*  f0a9c18:	25010001 */ 	addiu	$at,$t0,0x1
/*  f0a9c1c:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0a9c20:
/*  f0a9c20:	03101021 */ 	addu	$v0,$t8,$s0
/*  f0a9c24:	0048c823 */ 	subu	$t9,$v0,$t0
/*  f0a9c28:	afb9005c */ 	sw	$t9,0x5c($sp)
/*  f0a9c2c:	afa20054 */ 	sw	$v0,0x54($sp)
.L0f0a9c30:
/*  f0a9c30:	8fa20074 */ 	lw	$v0,0x74($sp)
/*  f0a9c34:	27a70054 */ 	addiu	$a3,$sp,0x54
/*  f0a9c38:	27ad0050 */ 	addiu	$t5,$sp,0x50
/*  f0a9c3c:	14430007 */ 	bne	$v0,$v1,.L0f0a9c5c
/*  f0a9c40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9c44:	8fa20070 */ 	lw	$v0,0x70($sp)
/*  f0a9c48:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f0a9c4c:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f0a9c50:	00491821 */ 	addu	$v1,$v0,$t1
/*  f0a9c54:	10000014 */ 	beqz	$zero,.L0f0a9ca8
/*  f0a9c58:	afa30050 */ 	sw	$v1,0x50($sp)
.L0f0a9c5c:
/*  f0a9c5c:	14400007 */ 	bnez	$v0,.L0f0a9c7c
/*  f0a9c60:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a9c64:	8fa20070 */ 	lw	$v0,0x70($sp)
/*  f0a9c68:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f0a9c6c:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f0a9c70:	00495023 */ 	subu	$t2,$v0,$t1
/*  f0a9c74:	1000000c */ 	beqz	$zero,.L0f0a9ca8
/*  f0a9c78:	afaa0058 */ 	sw	$t2,0x58($sp)
.L0f0a9c7c:
/*  f0a9c7c:	1441000a */ 	bne	$v0,$at,.L0f0a9ca8
/*  f0a9c80:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f0a9c84:	8fa20070 */ 	lw	$v0,0x70($sp)
/*  f0a9c88:	05210003 */ 	bgez	$t1,.L0f0a9c98
/*  f0a9c8c:	00095843 */ 	sra	$t3,$t1,0x1
/*  f0a9c90:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0a9c94:	00015843 */ 	sra	$t3,$at,0x1
.L0f0a9c98:
/*  f0a9c98:	01621821 */ 	addu	$v1,$t3,$v0
/*  f0a9c9c:	00696023 */ 	subu	$t4,$v1,$t1
/*  f0a9ca0:	afac0058 */ 	sw	$t4,0x58($sp)
/*  f0a9ca4:	afa30050 */ 	sw	$v1,0x50($sp)
.L0f0a9ca8:
/*  f0a9ca8:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f0a9cac:	0fc54e16 */ 	jal	func0f153858
/*  f0a9cb0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0a9cb4:	0c002f02 */ 	jal	func0000bc08
/*  f0a9cb8:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f0a9cbc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a9cc0:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0a9cc4:	0c002f06 */ 	jal	func0000bc18
/*  f0a9cc8:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0a9ccc:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0a9cd0:	3c188008 */ 	lui	$t8,0x8008
/*  f0a9cd4:	8f18fafc */ 	lw	$t8,-0x504($t8)
/*  f0a9cd8:	8deffb00 */ 	lw	$t7,-0x500($t7)
/*  f0a9cdc:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f0a9ce0:	240a00a0 */ 	addiu	$t2,$zero,0xa0
/*  f0a9ce4:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0a9ce8:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f0a9cec:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f0a9cf0:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0a9cf4:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0a9cf8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0a9cfc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0a9d00:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0a9d04:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0a9d08:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0a9d0c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0a9d10:	0fc55b92 */ 	jal	func0f156e48
/*  f0a9d14:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0a9d18:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0a9d1c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0a9d20:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f0a9d24:	03e00008 */ 	jr	$ra
/*  f0a9d28:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a9d2c
/*  f0a9d2c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0a9d30:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0a9d34:	00a03025 */ 	or	$a2,$a1,$zero
/*  f0a9d38:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0a9d3c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0a9d40:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0a9d44:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0a9d48:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f0a9d4c:	24a5c188 */ 	addiu	$a1,$a1,-15992
/*  f0a9d50:	0c004dad */ 	jal	sprintf
/*  f0a9d54:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*  f0a9d58:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0a9d5c:	8faf004c */ 	lw	$t7,0x4c($sp)
/*  f0a9d60:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f0a9d64:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0a9d68:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*  f0a9d6c:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0a9d70:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0a9d74:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0a9d78:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0a9d7c:	0fc2a6da */ 	jal	func0f0a9b68
/*  f0a9d80:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0a9d84:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0a9d88:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0a9d8c:	03e00008 */ 	jr	$ra
/*  f0a9d90:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a9d94
/*  f0a9d94:	a4800000 */ 	sh	$zero,0x0($a0)
/*  f0a9d98:	a0800005 */ 	sb	$zero,0x5($a0)
/*  f0a9d9c:	a0800004 */ 	sb	$zero,0x4($a0)
/*  f0a9da0:	03e00008 */ 	jr	$ra
/*  f0a9da4:	a4800002 */ 	sh	$zero,0x2($a0)
);

GLOBAL_ASM(
glabel func0f0a9da8
/*  f0a9da8:	28c10015 */ 	slti	$at,$a2,0x15
/*  f0a9dac:	54200023 */ 	bnezl	$at,.L0f0a9e3c
/*  f0a9db0:	80880005 */ 	lb	$t0,0x5($a0)
/*  f0a9db4:	00e50019 */ 	multu	$a3,$a1
/*  f0a9db8:	00007012 */ 	mflo	$t6
/*  f0a9dbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9dc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9dc4:	01c6001a */ 	div	$zero,$t6,$a2
/*  f0a9dc8:	00001812 */ 	mflo	$v1
/*  f0a9dcc:	00601025 */ 	or	$v0,$v1,$zero
/*  f0a9dd0:	14c00002 */ 	bnez	$a2,.L0f0a9ddc
/*  f0a9dd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9dd8:	0007000d */ 	break	0x7
.L0f0a9ddc:
/*  f0a9ddc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0a9de0:	14c10004 */ 	bne	$a2,$at,.L0f0a9df4
/*  f0a9de4:	3c018000 */ 	lui	$at,0x8000
/*  f0a9de8:	15c10002 */ 	bne	$t6,$at,.L0f0a9df4
/*  f0a9dec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9df0:	0006000d */ 	break	0x6
.L0f0a9df4:
/*  f0a9df4:	58a00005 */ 	blezl	$a1,.L0f0a9e0c
/*  f0a9df8:	80830004 */ 	lb	$v1,0x4($a0)
/*  f0a9dfc:	5c600003 */ 	bgtzl	$v1,.L0f0a9e0c
/*  f0a9e00:	80830004 */ 	lb	$v1,0x4($a0)
/*  f0a9e04:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a9e08:	80830004 */ 	lb	$v1,0x4($a0)
.L0f0a9e0c:
/*  f0a9e0c:	00e03025 */ 	or	$a2,$a3,$zero
/*  f0a9e10:	54430008 */ 	bnel	$v0,$v1,.L0f0a9e34
/*  f0a9e14:	a4850000 */ 	sh	$a1,0x0($a0)
/*  f0a9e18:	848f0000 */ 	lh	$t7,0x0($a0)
/*  f0a9e1c:	24780001 */ 	addiu	$t8,$v1,0x1
/*  f0a9e20:	00af082a */ 	slt	$at,$a1,$t7
/*  f0a9e24:	50200003 */ 	beqzl	$at,.L0f0a9e34
/*  f0a9e28:	a4850000 */ 	sh	$a1,0x0($a0)
/*  f0a9e2c:	a0980004 */ 	sb	$t8,0x4($a0)
/*  f0a9e30:	a4850000 */ 	sh	$a1,0x0($a0)
.L0f0a9e34:
/*  f0a9e34:	00402825 */ 	or	$a1,$v0,$zero
/*  f0a9e38:	80880005 */ 	lb	$t0,0x5($a0)
.L0f0a9e3c:
/*  f0a9e3c:	80830004 */ 	lb	$v1,0x4($a0)
/*  f0a9e40:	3c0e800a */ 	lui	$t6,0x800a
/*  f0a9e44:	05010003 */ 	bgez	$t0,.L0f0a9e54
/*  f0a9e48:	00a31023 */ 	subu	$v0,$a1,$v1
/*  f0a9e4c:	5c400005 */ 	bgtzl	$v0,.L0f0a9e64
/*  f0a9e50:	0068c821 */ 	addu	$t9,$v1,$t0
.L0f0a9e54:
/*  f0a9e54:	19000009 */ 	blez	$t0,.L0f0a9e7c
/*  f0a9e58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9e5c:	04410007 */ 	bgez	$v0,.L0f0a9e7c
/*  f0a9e60:	0068c821 */ 	addu	$t9,$v1,$t0
.L0f0a9e64:
/*  f0a9e64:	a0990004 */ 	sb	$t9,0x4($a0)
/*  f0a9e68:	80890004 */ 	lb	$t1,0x4($a0)
/*  f0a9e6c:	a0800005 */ 	sb	$zero,0x5($a0)
/*  f0a9e70:	a4800002 */ 	sh	$zero,0x2($a0)
/*  f0a9e74:	80880005 */ 	lb	$t0,0x5($a0)
/*  f0a9e78:	00a91023 */ 	subu	$v0,$a1,$t1
.L0f0a9e7c:
/*  f0a9e7c:	0501000a */ 	bgez	$t0,.L0f0a9ea8
/*  f0a9e80:	0048082a */ 	slt	$at,$v0,$t0
/*  f0a9e84:	50200009 */ 	beqzl	$at,.L0f0a9eac
/*  f0a9e88:	a0820005 */ 	sb	$v0,0x5($a0)
/*  f0a9e8c:	848b0002 */ 	lh	$t3,0x2($a0)
/*  f0a9e90:	00081823 */ 	negu	$v1,$t0
/*  f0a9e94:	00035180 */ 	sll	$t2,$v1,0x6
/*  f0a9e98:	014b082a */ 	slt	$at,$t2,$t3
/*  f0a9e9c:	50200003 */ 	beqzl	$at,.L0f0a9eac
/*  f0a9ea0:	a0820005 */ 	sb	$v0,0x5($a0)
/*  f0a9ea4:	a48a0002 */ 	sh	$t2,0x2($a0)
.L0f0a9ea8:
/*  f0a9ea8:	a0820005 */ 	sb	$v0,0x5($a0)
.L0f0a9eac:
/*  f0a9eac:	80880005 */ 	lb	$t0,0x5($a0)
/*  f0a9eb0:	19000006 */ 	blez	$t0,.L0f0a9ecc
/*  f0a9eb4:	2901fffd */ 	slti	$at,$t0,-3
/*  f0a9eb8:	28c10006 */ 	slti	$at,$a2,0x6
/*  f0a9ebc:	10200008 */ 	beqz	$at,.L0f0a9ee0
/*  f0a9ec0:	00c03825 */ 	or	$a3,$a2,$zero
/*  f0a9ec4:	10000006 */ 	beqz	$zero,.L0f0a9ee0
/*  f0a9ec8:	24070006 */ 	addiu	$a3,$zero,0x6
.L0f0a9ecc:
/*  f0a9ecc:	10200004 */ 	beqz	$at,.L0f0a9ee0
/*  f0a9ed0:	24070008 */ 	addiu	$a3,$zero,0x8
/*  f0a9ed4:	00083823 */ 	negu	$a3,$t0
/*  f0a9ed8:	00076040 */ 	sll	$t4,$a3,0x1
/*  f0a9edc:	25870008 */ 	addiu	$a3,$t4,0x8
.L0f0a9ee0:
/*  f0a9ee0:	51000035 */ 	beqzl	$t0,.L0f0a9fb8
/*  f0a9ee4:	a4800002 */ 	sh	$zero,0x2($a0)
/*  f0a9ee8:	85ce9ffa */ 	lh	$t6,-0x6006($t6)
/*  f0a9eec:	848d0002 */ 	lh	$t5,0x2($a0)
/*  f0a9ef0:	01c70019 */ 	multu	$t6,$a3
/*  f0a9ef4:	00007812 */ 	mflo	$t7
/*  f0a9ef8:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0a9efc:	a4980002 */ 	sh	$t8,0x2($a0)
/*  f0a9f00:	84820002 */ 	lh	$v0,0x2($a0)
/*  f0a9f04:	28410100 */ 	slti	$at,$v0,0x100
/*  f0a9f08:	1420002b */ 	bnez	$at,.L0f0a9fb8
/*  f0a9f0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9f10:	80880005 */ 	lb	$t0,0x5($a0)
/*  f0a9f14:	28410100 */ 	slti	$at,$v0,0x100
/*  f0a9f18:	19000014 */ 	blez	$t0,.L0f0a9f6c
/*  f0a9f1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9f20:	28410100 */ 	slti	$at,$v0,0x100
/*  f0a9f24:	14200024 */ 	bnez	$at,.L0f0a9fb8
/*  f0a9f28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9f2c:	19000022 */ 	blez	$t0,.L0f0a9fb8
/*  f0a9f30:	244bffc0 */ 	addiu	$t3,$v0,-64
.L0f0a9f34:
/*  f0a9f34:	a48b0002 */ 	sh	$t3,0x2($a0)
/*  f0a9f38:	80890004 */ 	lb	$t1,0x4($a0)
/*  f0a9f3c:	84820002 */ 	lh	$v0,0x2($a0)
/*  f0a9f40:	2519ffff */ 	addiu	$t9,$t0,-1
/*  f0a9f44:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f0a9f48:	28410100 */ 	slti	$at,$v0,0x100
/*  f0a9f4c:	a0990005 */ 	sb	$t9,0x5($a0)
/*  f0a9f50:	14200019 */ 	bnez	$at,.L0f0a9fb8
/*  f0a9f54:	a08a0004 */ 	sb	$t2,0x4($a0)
/*  f0a9f58:	80880005 */ 	lb	$t0,0x5($a0)
/*  f0a9f5c:	5d00fff5 */ 	bgtzl	$t0,.L0f0a9f34
/*  f0a9f60:	244bffc0 */ 	addiu	$t3,$v0,-64
/*  f0a9f64:	03e00008 */ 	jr	$ra
/*  f0a9f68:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0a9f6c:
/*  f0a9f6c:	14200012 */ 	bnez	$at,.L0f0a9fb8
/*  f0a9f70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9f74:	05010010 */ 	bgez	$t0,.L0f0a9fb8
/*  f0a9f78:	244fffc0 */ 	addiu	$t7,$v0,-64
.L0f0a9f7c:
/*  f0a9f7c:	a48f0002 */ 	sh	$t7,0x2($a0)
/*  f0a9f80:	808e0004 */ 	lb	$t6,0x4($a0)
/*  f0a9f84:	84820002 */ 	lh	$v0,0x2($a0)
/*  f0a9f88:	250c0001 */ 	addiu	$t4,$t0,0x1
/*  f0a9f8c:	25cdffff */ 	addiu	$t5,$t6,-1
/*  f0a9f90:	28410100 */ 	slti	$at,$v0,0x100
/*  f0a9f94:	a08c0005 */ 	sb	$t4,0x5($a0)
/*  f0a9f98:	14200007 */ 	bnez	$at,.L0f0a9fb8
/*  f0a9f9c:	a08d0004 */ 	sb	$t5,0x4($a0)
/*  f0a9fa0:	80880005 */ 	lb	$t0,0x5($a0)
/*  f0a9fa4:	0502fff5 */ 	bltzl	$t0,.L0f0a9f7c
/*  f0a9fa8:	244fffc0 */ 	addiu	$t7,$v0,-64
/*  f0a9fac:	03e00008 */ 	jr	$ra
/*  f0a9fb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a9fb4:	a4800002 */ 	sh	$zero,0x2($a0)
.L0f0a9fb8:
/*  f0a9fb8:	03e00008 */ 	jr	$ra
/*  f0a9fbc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0a9fc0
/*  f0a9fc0:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f0a9fc4:	afa600d8 */ 	sw	$a2,0xd8($sp)
/*  f0a9fc8:	8faf00d8 */ 	lw	$t7,0xd8($sp)
/*  f0a9fcc:	8fae00e0 */ 	lw	$t6,0xe0($sp)
/*  f0a9fd0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0a9fd4:	8fb100ec */ 	lw	$s1,0xec($sp)
/*  f0a9fd8:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0a9fdc:	8fb700e4 */ 	lw	$s7,0xe4($sp)
/*  f0a9fe0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0a9fe4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a9fe8:	00808025 */ 	or	$s0,$a0,$zero
/*  f0a9fec:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0a9ff0:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*  f0a9ff4:	afa700dc */ 	sw	$a3,0xdc($sp)
/*  f0a9ff8:	01cf9023 */ 	subu	$s2,$t6,$t7
/*  f0a9ffc:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0aa000:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0aa004:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0aa008:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0aa00c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0aa010:	02403825 */ 	or	$a3,$s2,$zero
/*  f0aa014:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0aa018:	afb100b4 */ 	sw	$s1,0xb4($sp)
/*  f0aa01c:	02203025 */ 	or	$a2,$s1,$zero
/*  f0aa020:	0fc2a76a */ 	jal	func0f0a9da8
/*  f0aa024:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0aa028:	2a210015 */ 	slti	$at,$s1,0x15
/*  f0aa02c:	8fa900e0 */ 	lw	$t1,0xe0($sp)
/*  f0aa030:	8fab00d8 */ 	lw	$t3,0xd8($sp)
/*  f0aa034:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f0aa038:	14200008 */ 	bnez	$at,.L0f0aa05c
/*  f0aa03c:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f0aa040:	82f80004 */ 	lb	$t8,0x4($s7)
/*  f0aa044:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f0aa048:	afb200b4 */ 	sw	$s2,0xb4($sp)
/*  f0aa04c:	44982000 */ 	mtc1	$t8,$f4
/*  f0aa050:	01323023 */ 	subu	$a2,$t1,$s2
/*  f0aa054:	1000002b */ 	beqz	$zero,.L0f0aa104
/*  f0aa058:	46802020 */ 	cvt.s.w	$f0,$f4
.L0f0aa05c:
/*  f0aa05c:	0251001a */ 	div	$zero,$s2,$s1
/*  f0aa060:	00001012 */ 	mflo	$v0
/*  f0aa064:	24470001 */ 	addiu	$a3,$v0,0x1
/*  f0aa068:	82f90004 */ 	lb	$t9,0x4($s7)
/*  f0aa06c:	00510019 */ 	multu	$v0,$s1
/*  f0aa070:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0aa074:	44993000 */ 	mtc1	$t9,$f6
/*  f0aa078:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa07c:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f0aa080:	16200002 */ 	bnez	$s1,.L0f0aa08c
/*  f0aa084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa088:	0007000d */ 	break	0x7
.L0f0aa08c:
/*  f0aa08c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0aa090:	16210004 */ 	bne	$s1,$at,.L0f0aa0a4
/*  f0aa094:	3c018000 */ 	lui	$at,0x8000
/*  f0aa098:	16410002 */ 	bne	$s2,$at,.L0f0aa0a4
/*  f0aa09c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa0a0:	0006000d */ 	break	0x6
.L0f0aa0a4:
/*  f0aa0a4:	00007012 */ 	mflo	$t6
/*  f0aa0a8:	01d22023 */ 	subu	$a0,$t6,$s2
/*  f0aa0ac:	00802825 */ 	or	$a1,$a0,$zero
/*  f0aa0b0:	00f10019 */ 	multu	$a3,$s1
/*  f0aa0b4:	00007812 */ 	mflo	$t7
/*  f0aa0b8:	01f21823 */ 	subu	$v1,$t7,$s2
/*  f0aa0bc:	04810002 */ 	bgez	$a0,.L0f0aa0c8
/*  f0aa0c0:	00603025 */ 	or	$a2,$v1,$zero
/*  f0aa0c4:	00042823 */ 	negu	$a1,$a0
.L0f0aa0c8:
/*  f0aa0c8:	04630003 */ 	bgezl	$v1,.L0f0aa0d8
/*  f0aa0cc:	00c5082a */ 	slt	$at,$a2,$a1
/*  f0aa0d0:	00033023 */ 	negu	$a2,$v1
/*  f0aa0d4:	00c5082a */ 	slt	$at,$a2,$a1
.L0f0aa0d8:
/*  f0aa0d8:	10200002 */ 	beqz	$at,.L0f0aa0e4
/*  f0aa0dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa0e0:	00e0b025 */ 	or	$s6,$a3,$zero
.L0f0aa0e4:
/*  f0aa0e4:	02d10019 */ 	multu	$s6,$s1
/*  f0aa0e8:	2ac10003 */ 	slti	$at,$s6,0x3
/*  f0aa0ec:	0000c012 */ 	mflo	$t8
/*  f0aa0f0:	01381023 */ 	subu	$v0,$t1,$t8
/*  f0aa0f4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0aa0f8:	10200002 */ 	beqz	$at,.L0f0aa104
/*  f0aa0fc:	00403025 */ 	or	$a2,$v0,$zero
/*  f0aa100:	2446ffff */ 	addiu	$a2,$v0,-1
.L0f0aa104:
/*  f0aa104:	16c0008c */ 	bnez	$s6,.L0f0aa338
/*  f0aa108:	02002025 */ 	or	$a0,$s0,$zero
/*  f0aa10c:	01268823 */ 	subu	$s1,$t1,$a2
/*  f0aa110:	44914000 */ 	mtc1	$s1,$f8
/*  f0aa114:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f0aa118:	02002025 */ 	or	$a0,$s0,$zero
/*  f0aa11c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0aa120:	44999000 */ 	mtc1	$t9,$f18
/*  f0aa124:	44894000 */ 	mtc1	$t1,$f8
/*  f0aa128:	8fa500f0 */ 	lw	$a1,0xf0($sp)
/*  f0aa12c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0aa130:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0aa134:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0aa138:	46048183 */ 	div.s	$f6,$f16,$f4
/*  f0aa13c:	46065481 */ 	sub.s	$f18,$f10,$f6
/*  f0aa140:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f0aa144:	44128000 */ 	mfc1	$s2,$f16
/*  f0aa148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa14c:	00d2082a */ 	slt	$at,$a2,$s2
/*  f0aa150:	1020003f */ 	beqz	$at,.L0f0aa250
/*  f0aa154:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa158:	0fc54df7 */ 	jal	func0f1537dc
/*  f0aa15c:	afa600bc */ 	sw	$a2,0xbc($sp)
/*  f0aa160:	8faf00f8 */ 	lw	$t7,0xf8($sp)
/*  f0aa164:	8fa600bc */ 	lw	$a2,0xbc($sp)
/*  f0aa168:	8fa900e0 */ 	lw	$t1,0xe0($sp)
/*  f0aa16c:	8fab00d8 */ 	lw	$t3,0xd8($sp)
/*  f0aa170:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f0aa174:	11e0001c */ 	beqz	$t7,.L0f0aa1e8
/*  f0aa178:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f0aa17c:	3c138008 */ 	lui	$s3,%hi(var8007fac0)
/*  f0aa180:	2673fac0 */ 	addiu	$s3,$s3,%lo(var8007fac0)
/*  f0aa184:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0aa188:	3c0af600 */ 	lui	$t2,0xf600
/*  f0aa18c:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0aa190:	01980019 */ 	multu	$t4,$t8
/*  f0aa194:	0000c812 */ 	mflo	$t9
/*  f0aa198:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0aa19c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0aa1a0:	022bc821 */ 	addu	$t9,$s1,$t3
/*  f0aa1a4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0aa1a8:	01eac025 */ 	or	$t8,$t7,$t2
/*  f0aa1ac:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0aa1b0:	030fc825 */ 	or	$t9,$t8,$t7
/*  f0aa1b4:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0aa1b8:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0aa1bc:	01ae0019 */ 	multu	$t5,$t6
/*  f0aa1c0:	01327023 */ 	subu	$t6,$t1,$s2
/*  f0aa1c4:	0000c012 */ 	mflo	$t8
/*  f0aa1c8:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0aa1cc:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f0aa1d0:	01cbc021 */ 	addu	$t8,$t6,$t3
/*  f0aa1d4:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0aa1d8:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f0aa1dc:	032ec025 */ 	or	$t8,$t9,$t6
/*  f0aa1e0:	10000018 */ 	beqz	$zero,.L0f0aa244
/*  f0aa1e4:	ac580004 */ 	sw	$t8,0x4($v0)
.L0f0aa1e8:
/*  f0aa1e8:	3c138008 */ 	lui	$s3,%hi(var8007fac0)
/*  f0aa1ec:	2673fac0 */ 	addiu	$s3,$s3,%lo(var8007fac0)
/*  f0aa1f0:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f0aa1f4:	3c0af600 */ 	lui	$t2,0xf600
/*  f0aa1f8:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0aa1fc:	018f0019 */ 	multu	$t4,$t7
/*  f0aa200:	0000c812 */ 	mflo	$t9
/*  f0aa204:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0aa208:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0aa20c:	325903ff */ 	andi	$t9,$s2,0x3ff
/*  f0aa210:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0aa214:	030a7825 */ 	or	$t7,$t8,$t2
/*  f0aa218:	01eec025 */ 	or	$t8,$t7,$t6
/*  f0aa21c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0aa220:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0aa224:	01b90019 */ 	multu	$t5,$t9
/*  f0aa228:	30d903ff */ 	andi	$t9,$a2,0x3ff
/*  f0aa22c:	00007812 */ 	mflo	$t7
/*  f0aa230:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0aa234:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0aa238:	00197880 */ 	sll	$t7,$t9,0x2
/*  f0aa23c:	030f7025 */ 	or	$t6,$t8,$t7
/*  f0aa240:	ac4e0004 */ 	sw	$t6,0x4($v0)
.L0f0aa244:
/*  f0aa244:	0fc54e0e */ 	jal	func0f153838
/*  f0aa248:	02002025 */ 	or	$a0,$s0,$zero
/*  f0aa24c:	00408025 */ 	or	$s0,$v0,$zero
.L0f0aa250:
/*  f0aa250:	3c138008 */ 	lui	$s3,%hi(var8007fac0)
/*  f0aa254:	2673fac0 */ 	addiu	$s3,$s3,%lo(var8007fac0)
/*  f0aa258:	02002025 */ 	or	$a0,$s0,$zero
/*  f0aa25c:	0fc54df7 */ 	jal	func0f1537dc
/*  f0aa260:	8fa500f4 */ 	lw	$a1,0xf4($sp)
/*  f0aa264:	8fb900f8 */ 	lw	$t9,0xf8($sp)
/*  f0aa268:	8fa900e0 */ 	lw	$t1,0xe0($sp)
/*  f0aa26c:	3c0af600 */ 	lui	$t2,0xf600
/*  f0aa270:	8fab00d8 */ 	lw	$t3,0xd8($sp)
/*  f0aa274:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f0aa278:	1320001a */ 	beqz	$t9,.L0f0aa2e4
/*  f0aa27c:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f0aa280:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0aa284:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0aa288:	01980019 */ 	multu	$t4,$t8
/*  f0aa28c:	00007812 */ 	mflo	$t7
/*  f0aa290:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0aa294:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0aa298:	01327823 */ 	subu	$t7,$t1,$s2
/*  f0aa29c:	01eb7021 */ 	addu	$t6,$t7,$t3
/*  f0aa2a0:	032ac025 */ 	or	$t8,$t9,$t2
/*  f0aa2a4:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0aa2a8:	00197880 */ 	sll	$t7,$t9,0x2
/*  f0aa2ac:	030f7025 */ 	or	$t6,$t8,$t7
/*  f0aa2b0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0aa2b4:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0aa2b8:	01b90019 */ 	multu	$t5,$t9
/*  f0aa2bc:	0129c823 */ 	subu	$t9,$t1,$t1
/*  f0aa2c0:	0000c012 */ 	mflo	$t8
/*  f0aa2c4:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0aa2c8:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0aa2cc:	032bc021 */ 	addu	$t8,$t9,$t3
/*  f0aa2d0:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0aa2d4:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f0aa2d8:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f0aa2dc:	1000014e */ 	beqz	$zero,.L0f0aa818
/*  f0aa2e0:	ac580004 */ 	sw	$t8,0x4($v0)
.L0f0aa2e4:
/*  f0aa2e4:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f0aa2e8:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0aa2ec:	018f0019 */ 	multu	$t4,$t7
/*  f0aa2f0:	00007012 */ 	mflo	$t6
/*  f0aa2f4:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0aa2f8:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f0aa2fc:	312e03ff */ 	andi	$t6,$t1,0x3ff
/*  f0aa300:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f0aa304:	030a7825 */ 	or	$t7,$t8,$t2
/*  f0aa308:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f0aa30c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0aa310:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0aa314:	01ae0019 */ 	multu	$t5,$t6
/*  f0aa318:	324e03ff */ 	andi	$t6,$s2,0x3ff
/*  f0aa31c:	00007812 */ 	mflo	$t7
/*  f0aa320:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f0aa324:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f0aa328:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0aa32c:	030fc825 */ 	or	$t9,$t8,$t7
/*  f0aa330:	10000139 */ 	beqz	$zero,.L0f0aa818
/*  f0aa334:	ac590004 */ 	sw	$t9,0x4($v0)
.L0f0aa338:
/*  f0aa338:	8fa500f0 */ 	lw	$a1,0xf0($sp)
/*  f0aa33c:	afa600bc */ 	sw	$a2,0xbc($sp)
/*  f0aa340:	0fc54df7 */ 	jal	func0f1537dc
/*  f0aa344:	e7a000b8 */ 	swc1	$f0,0xb8($sp)
/*  f0aa348:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f0aa34c:	8fa600bc */ 	lw	$a2,0xbc($sp)
/*  f0aa350:	8fa900e0 */ 	lw	$t1,0xe0($sp)
/*  f0aa354:	8fab00d8 */ 	lw	$t3,0xd8($sp)
/*  f0aa358:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f0aa35c:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f0aa360:	c7a000b8 */ 	lwc1	$f0,0xb8($sp)
/*  f0aa364:	00408025 */ 	or	$s0,$v0,$zero
/*  f0aa368:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f0aa36c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0aa370:	19c000f2 */ 	blez	$t6,.L0f0aa73c
/*  f0aa374:	00c0a825 */ 	or	$s5,$a2,$zero
/*  f0aa378:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f0aa37c:	252fffff */ 	addiu	$t7,$t1,-1
/*  f0aa380:	3c138008 */ 	lui	$s3,%hi(var8007fac0)
/*  f0aa384:	2673fac0 */ 	addiu	$s3,$s3,%lo(var8007fac0)
/*  f0aa388:	44022000 */ 	mfc1	$v0,$f4
/*  f0aa38c:	afaf0040 */ 	sw	$t7,0x40($sp)
/*  f0aa390:	00c0f025 */ 	or	$s8,$a2,$zero
/*  f0aa394:	00d64021 */ 	addu	$t0,$a2,$s6
/*  f0aa398:	3c0af600 */ 	lui	$t2,0xf600
/*  f0aa39c:	8fa70094 */ 	lw	$a3,0x94($sp)
/*  f0aa3a0:	01c2a023 */ 	subu	$s4,$t6,$v0
/*  f0aa3a4:	afa20050 */ 	sw	$v0,0x50($sp)
.L0f0aa3a8:
/*  f0aa3a8:	82e40005 */ 	lb	$a0,0x5($s7)
/*  f0aa3ac:	00002825 */ 	or	$a1,$zero,$zero
/*  f0aa3b0:	18800031 */ 	blez	$a0,.L0f0aa478
/*  f0aa3b4:	0284c823 */ 	subu	$t9,$s4,$a0
/*  f0aa3b8:	0239082a */ 	slt	$at,$s1,$t9
/*  f0aa3bc:	1420004f */ 	bnez	$at,.L0f0aa4fc
/*  f0aa3c0:	0234082a */ 	slt	$at,$s1,$s4
/*  f0aa3c4:	1020004d */ 	beqz	$at,.L0f0aa4fc
/*  f0aa3c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa3cc:	86f80002 */ 	lh	$t8,0x2($s7)
/*  f0aa3d0:	02917023 */ 	subu	$t6,$s4,$s1
/*  f0aa3d4:	000e7980 */ 	sll	$t7,$t6,0x6
/*  f0aa3d8:	030f1823 */ 	subu	$v1,$t8,$t7
/*  f0aa3dc:	24630040 */ 	addiu	$v1,$v1,0x40
/*  f0aa3e0:	04600046 */ 	bltz	$v1,.L0f0aa4fc
/*  f0aa3e4:	28610040 */ 	slti	$at,$v1,0x40
/*  f0aa3e8:	14200015 */ 	bnez	$at,.L0f0aa440
/*  f0aa3ec:	2404ffbf */ 	addiu	$a0,$zero,-65
/*  f0aa3f0:	00031080 */ 	sll	$v0,$v1,0x2
/*  f0aa3f4:	2442ff04 */ 	addiu	$v0,$v0,-252
/*  f0aa3f8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0aa3fc:	0041001a */ 	div	$zero,$v0,$at
/*  f0aa400:	00003012 */ 	mflo	$a2
/*  f0aa404:	2cc10100 */ 	sltiu	$at,$a2,0x100
/*  f0aa408:	14200002 */ 	bnez	$at,.L0f0aa414
/*  f0aa40c:	8fa400f4 */ 	lw	$a0,0xf4($sp)
/*  f0aa410:	240600ff */ 	addiu	$a2,$zero,0xff
.L0f0aa414:
/*  f0aa414:	2405ffbf */ 	addiu	$a1,$zero,-65
/*  f0aa418:	0fc01a40 */ 	jal	func0f006900
/*  f0aa41c:	afa80044 */ 	sw	$t0,0x44($sp)
/*  f0aa420:	8fa80044 */ 	lw	$t0,0x44($sp)
/*  f0aa424:	8fa900e0 */ 	lw	$t1,0xe0($sp)
/*  f0aa428:	3c0af600 */ 	lui	$t2,0xf600
/*  f0aa42c:	8fab00d8 */ 	lw	$t3,0xd8($sp)
/*  f0aa430:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f0aa434:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f0aa438:	1000000c */ 	beqz	$zero,.L0f0aa46c
/*  f0aa43c:	00403825 */ 	or	$a3,$v0,$zero
.L0f0aa440:
/*  f0aa440:	8fa500f0 */ 	lw	$a1,0xf0($sp)
/*  f0aa444:	00033080 */ 	sll	$a2,$v1,0x2
/*  f0aa448:	0fc01a40 */ 	jal	func0f006900
/*  f0aa44c:	afa80044 */ 	sw	$t0,0x44($sp)
/*  f0aa450:	8fa80044 */ 	lw	$t0,0x44($sp)
/*  f0aa454:	8fa900e0 */ 	lw	$t1,0xe0($sp)
/*  f0aa458:	3c0af600 */ 	lui	$t2,0xf600
/*  f0aa45c:	8fab00d8 */ 	lw	$t3,0xd8($sp)
/*  f0aa460:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f0aa464:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f0aa468:	00403825 */ 	or	$a3,$v0,$zero
.L0f0aa46c:
/*  f0aa46c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0aa470:	10000022 */ 	beqz	$zero,.L0f0aa4fc
/*  f0aa474:	82e40005 */ 	lb	$a0,0x5($s7)
.L0f0aa478:
/*  f0aa478:	04810020 */ 	bgez	$a0,.L0f0aa4fc
/*  f0aa47c:	02847023 */ 	subu	$t6,$s4,$a0
/*  f0aa480:	022e082a */ 	slt	$at,$s1,$t6
/*  f0aa484:	1020001d */ 	beqz	$at,.L0f0aa4fc
/*  f0aa488:	0234082a */ 	slt	$at,$s1,$s4
/*  f0aa48c:	1420001b */ 	bnez	$at,.L0f0aa4fc
/*  f0aa490:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f0aa494:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0aa498:	02387823 */ 	subu	$t7,$s1,$t8
/*  f0aa49c:	01f97021 */ 	addu	$t6,$t7,$t9
/*  f0aa4a0:	86ef0002 */ 	lh	$t7,0x2($s7)
/*  f0aa4a4:	000ec180 */ 	sll	$t8,$t6,0x6
/*  f0aa4a8:	01f83023 */ 	subu	$a2,$t7,$t8
/*  f0aa4ac:	04c00013 */ 	bltz	$a2,.L0f0aa4fc
/*  f0aa4b0:	2cc10100 */ 	sltiu	$at,$a2,0x100
/*  f0aa4b4:	14200003 */ 	bnez	$at,.L0f0aa4c4
/*  f0aa4b8:	8fa500f4 */ 	lw	$a1,0xf4($sp)
/*  f0aa4bc:	1000000e */ 	beqz	$zero,.L0f0aa4f8
/*  f0aa4c0:	8fa700f0 */ 	lw	$a3,0xf0($sp)
.L0f0aa4c4:
/*  f0aa4c4:	34b900ff */ 	ori	$t9,$a1,0xff
/*  f0aa4c8:	03202825 */ 	or	$a1,$t9,$zero
/*  f0aa4cc:	8fa400f0 */ 	lw	$a0,0xf0($sp)
/*  f0aa4d0:	0fc01a40 */ 	jal	func0f006900
/*  f0aa4d4:	afa80044 */ 	sw	$t0,0x44($sp)
/*  f0aa4d8:	8fa80044 */ 	lw	$t0,0x44($sp)
/*  f0aa4dc:	8fa900e0 */ 	lw	$t1,0xe0($sp)
/*  f0aa4e0:	3c0af600 */ 	lui	$t2,0xf600
/*  f0aa4e4:	8fab00d8 */ 	lw	$t3,0xd8($sp)
/*  f0aa4e8:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f0aa4ec:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f0aa4f0:	00403825 */ 	or	$a3,$v0,$zero
/*  f0aa4f4:	82e40005 */ 	lb	$a0,0x5($s7)
.L0f0aa4f8:
/*  f0aa4f8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0aa4fc:
/*  f0aa4fc:	04810007 */ 	bgez	$a0,.L0f0aa51c
/*  f0aa500:	2ac10003 */ 	slti	$at,$s6,0x3
/*  f0aa504:	02847023 */ 	subu	$t6,$s4,$a0
/*  f0aa508:	162e0008 */ 	bne	$s1,$t6,.L0f0aa52c
/*  f0aa50c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa510:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f0aa514:	10000005 */ 	beqz	$zero,.L0f0aa52c
/*  f0aa518:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0aa51c:
/*  f0aa51c:	16340003 */ 	bne	$s1,$s4,.L0f0aa52c
/*  f0aa520:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa524:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f0aa528:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0aa52c:
/*  f0aa52c:	5020003a */ 	beqzl	$at,.L0f0aa618
/*  f0aa530:	03c0a825 */ 	or	$s5,$s8,$zero
/*  f0aa534:	10a00035 */ 	beqz	$a1,.L0f0aa60c
/*  f0aa538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa53c:	06400032 */ 	bltz	$s2,.L0f0aa608
/*  f0aa540:	8faf00f8 */ 	lw	$t7,0xf8($sp)
/*  f0aa544:	51e0001c */ 	beqzl	$t7,.L0f0aa5b8
/*  f0aa548:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0aa54c:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0aa550:	02001025 */ 	or	$v0,$s0,$zero
/*  f0aa554:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0aa558:	01980019 */ 	multu	$t4,$t8
/*  f0aa55c:	0000c812 */ 	mflo	$t9
/*  f0aa560:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0aa564:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0aa568:	0135c823 */ 	subu	$t9,$t1,$s5
/*  f0aa56c:	032b7021 */ 	addu	$t6,$t9,$t3
/*  f0aa570:	01eac025 */ 	or	$t8,$t7,$t2
/*  f0aa574:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0aa578:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f0aa57c:	03197025 */ 	or	$t6,$t8,$t9
/*  f0aa580:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0aa584:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f0aa588:	01af0019 */ 	multu	$t5,$t7
/*  f0aa58c:	01327823 */ 	subu	$t7,$t1,$s2
/*  f0aa590:	0000c012 */ 	mflo	$t8
/*  f0aa594:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0aa598:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0aa59c:	01ebc021 */ 	addu	$t8,$t7,$t3
/*  f0aa5a0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0aa5a4:	00197880 */ 	sll	$t7,$t9,0x2
/*  f0aa5a8:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f0aa5ac:	10000016 */ 	beqz	$zero,.L0f0aa608
/*  f0aa5b0:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0aa5b4:	8e790000 */ 	lw	$t9,0x0($s3)
.L0f0aa5b8:
/*  f0aa5b8:	02001025 */ 	or	$v0,$s0,$zero
/*  f0aa5bc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0aa5c0:	01990019 */ 	multu	$t4,$t9
/*  f0aa5c4:	00007012 */ 	mflo	$t6
/*  f0aa5c8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0aa5cc:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0aa5d0:	324e03ff */ 	andi	$t6,$s2,0x3ff
/*  f0aa5d4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0aa5d8:	030ac825 */ 	or	$t9,$t8,$t2
/*  f0aa5dc:	032fc025 */ 	or	$t8,$t9,$t7
/*  f0aa5e0:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0aa5e4:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0aa5e8:	01ae0019 */ 	multu	$t5,$t6
/*  f0aa5ec:	32ae03ff */ 	andi	$t6,$s5,0x3ff
/*  f0aa5f0:	0000c812 */ 	mflo	$t9
/*  f0aa5f4:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0aa5f8:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0aa5fc:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f0aa600:	03197825 */ 	or	$t7,$t8,$t9
/*  f0aa604:	ac4f0004 */ 	sw	$t7,0x4($v0)
.L0f0aa608:
/*  f0aa608:	03c0a825 */ 	or	$s5,$s8,$zero
.L0f0aa60c:
/*  f0aa60c:	10000003 */ 	beqz	$zero,.L0f0aa61c
/*  f0aa610:	01009025 */ 	or	$s2,$t0,$zero
/*  f0aa614:	03c0a825 */ 	or	$s5,$s8,$zero
.L0f0aa618:
/*  f0aa618:	2512ffff */ 	addiu	$s2,$t0,-1
.L0f0aa61c:
/*  f0aa61c:	10a00005 */ 	beqz	$a1,.L0f0aa634
/*  f0aa620:	02001025 */ 	or	$v0,$s0,$zero
/*  f0aa624:	3c0efa00 */ 	lui	$t6,0xfa00
/*  f0aa628:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0aa62c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0aa630:	ac470004 */ 	sw	$a3,0x4($v0)
.L0f0aa634:
/*  f0aa634:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f0aa638:	8fb900f8 */ 	lw	$t9,0xf8($sp)
/*  f0aa63c:	0258082a */ 	slt	$at,$s2,$t8
/*  f0aa640:	14200004 */ 	bnez	$at,.L0f0aa654
/*  f0aa644:	2ac10002 */ 	slti	$at,$s6,0x2
/*  f0aa648:	54200003 */ 	bnezl	$at,.L0f0aa658
/*  f0aa64c:	2ac10003 */ 	slti	$at,$s6,0x3
/*  f0aa650:	01209025 */ 	or	$s2,$t1,$zero
.L0f0aa654:
/*  f0aa654:	2ac10003 */ 	slti	$at,$s6,0x3
.L0f0aa658:
/*  f0aa658:	54200033 */ 	bnezl	$at,.L0f0aa728
/*  f0aa65c:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f0aa660:	5320001c */ 	beqzl	$t9,.L0f0aa6d4
/*  f0aa664:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0aa668:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f0aa66c:	02001025 */ 	or	$v0,$s0,$zero
/*  f0aa670:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0aa674:	018f0019 */ 	multu	$t4,$t7
/*  f0aa678:	00007012 */ 	mflo	$t6
/*  f0aa67c:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0aa680:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0aa684:	01357023 */ 	subu	$t6,$t1,$s5
/*  f0aa688:	01cbc021 */ 	addu	$t8,$t6,$t3
/*  f0aa68c:	032a7825 */ 	or	$t7,$t9,$t2
/*  f0aa690:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0aa694:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0aa698:	01eec025 */ 	or	$t8,$t7,$t6
/*  f0aa69c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0aa6a0:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0aa6a4:	01b90019 */ 	multu	$t5,$t9
/*  f0aa6a8:	0132c823 */ 	subu	$t9,$t1,$s2
/*  f0aa6ac:	00007812 */ 	mflo	$t7
/*  f0aa6b0:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0aa6b4:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0aa6b8:	032b7821 */ 	addu	$t7,$t9,$t3
/*  f0aa6bc:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0aa6c0:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f0aa6c4:	03197825 */ 	or	$t7,$t8,$t9
/*  f0aa6c8:	10000016 */ 	beqz	$zero,.L0f0aa724
/*  f0aa6cc:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0aa6d0:	8e6e0000 */ 	lw	$t6,0x0($s3)
.L0f0aa6d4:
/*  f0aa6d4:	02001025 */ 	or	$v0,$s0,$zero
/*  f0aa6d8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0aa6dc:	018e0019 */ 	multu	$t4,$t6
/*  f0aa6e0:	0000c012 */ 	mflo	$t8
/*  f0aa6e4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0aa6e8:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0aa6ec:	325803ff */ 	andi	$t8,$s2,0x3ff
/*  f0aa6f0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0aa6f4:	01ea7025 */ 	or	$t6,$t7,$t2
/*  f0aa6f8:	01d97825 */ 	or	$t7,$t6,$t9
/*  f0aa6fc:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0aa700:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0aa704:	01b80019 */ 	multu	$t5,$t8
/*  f0aa708:	32b803ff */ 	andi	$t8,$s5,0x3ff
/*  f0aa70c:	00007012 */ 	mflo	$t6
/*  f0aa710:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0aa714:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0aa718:	00187080 */ 	sll	$t6,$t8,0x2
/*  f0aa71c:	01eec825 */ 	or	$t9,$t7,$t6
/*  f0aa720:	ac590004 */ 	sw	$t9,0x4($v0)
.L0f0aa724:
/*  f0aa724:	8fb800b4 */ 	lw	$t8,0xb4($sp)
.L0f0aa728:
/*  f0aa728:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0aa72c:	03d6f021 */ 	addu	$s8,$s8,$s6
/*  f0aa730:	1638ff1d */ 	bne	$s1,$t8,.L0f0aa3a8
/*  f0aa734:	01164021 */ 	addu	$t0,$t0,$s6
/*  f0aa738:	afa70094 */ 	sw	$a3,0x94($sp)
.L0f0aa73c:
/*  f0aa73c:	3c138008 */ 	lui	$s3,%hi(var8007fac0)
/*  f0aa740:	2ac10003 */ 	slti	$at,$s6,0x3
/*  f0aa744:	2673fac0 */ 	addiu	$s3,$s3,%lo(var8007fac0)
/*  f0aa748:	10200033 */ 	beqz	$at,.L0f0aa818
/*  f0aa74c:	3c0af600 */ 	lui	$t2,0xf600
/*  f0aa750:	8faf00f8 */ 	lw	$t7,0xf8($sp)
/*  f0aa754:	51e0001c */ 	beqzl	$t7,.L0f0aa7c8
/*  f0aa758:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0aa75c:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0aa760:	02001025 */ 	or	$v0,$s0,$zero
/*  f0aa764:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0aa768:	018e0019 */ 	multu	$t4,$t6
/*  f0aa76c:	0000c812 */ 	mflo	$t9
/*  f0aa770:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0aa774:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f0aa778:	0135c823 */ 	subu	$t9,$t1,$s5
/*  f0aa77c:	032bc021 */ 	addu	$t8,$t9,$t3
/*  f0aa780:	01ea7025 */ 	or	$t6,$t7,$t2
/*  f0aa784:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0aa788:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f0aa78c:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f0aa790:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0aa794:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f0aa798:	01af0019 */ 	multu	$t5,$t7
/*  f0aa79c:	01327823 */ 	subu	$t7,$t1,$s2
/*  f0aa7a0:	00007012 */ 	mflo	$t6
/*  f0aa7a4:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0aa7a8:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f0aa7ac:	01eb7021 */ 	addu	$t6,$t7,$t3
/*  f0aa7b0:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0aa7b4:	00197880 */ 	sll	$t7,$t9,0x2
/*  f0aa7b8:	030f7025 */ 	or	$t6,$t8,$t7
/*  f0aa7bc:	10000016 */ 	beqz	$zero,.L0f0aa818
/*  f0aa7c0:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0aa7c4:	8e790000 */ 	lw	$t9,0x0($s3)
.L0f0aa7c8:
/*  f0aa7c8:	02001025 */ 	or	$v0,$s0,$zero
/*  f0aa7cc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0aa7d0:	01990019 */ 	multu	$t4,$t9
/*  f0aa7d4:	0000c012 */ 	mflo	$t8
/*  f0aa7d8:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0aa7dc:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0aa7e0:	325803ff */ 	andi	$t8,$s2,0x3ff
/*  f0aa7e4:	00187880 */ 	sll	$t7,$t8,0x2
/*  f0aa7e8:	01cac825 */ 	or	$t9,$t6,$t2
/*  f0aa7ec:	032f7025 */ 	or	$t6,$t9,$t7
/*  f0aa7f0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0aa7f4:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0aa7f8:	01b80019 */ 	multu	$t5,$t8
/*  f0aa7fc:	32b803ff */ 	andi	$t8,$s5,0x3ff
/*  f0aa800:	0000c812 */ 	mflo	$t9
/*  f0aa804:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0aa808:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0aa80c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0aa810:	01d97825 */ 	or	$t7,$t6,$t9
/*  f0aa814:	ac4f0004 */ 	sw	$t7,0x4($v0)
.L0f0aa818:
/*  f0aa818:	0fc54e0e */ 	jal	func0f153838
/*  f0aa81c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0aa820:	3c18b900 */ 	lui	$t8,0xb900
/*  f0aa824:	3c0e0050 */ 	lui	$t6,0x50
/*  f0aa828:	35ce41c8 */ 	ori	$t6,$t6,0x41c8
/*  f0aa82c:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f0aa830:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0aa834:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0aa838:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0aa83c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0aa840:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0aa844:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0aa848:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0aa84c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0aa850:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0aa854:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0aa858:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0aa85c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0aa860:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
/*  f0aa864:	03e00008 */ 	jr	$ra
/*  f0aa868:	24420008 */ 	addiu	$v0,$v0,0x8
);

GLOBAL_ASM(
glabel func0f0aa86c
/*  f0aa86c:	3c0e800a */ 	lui	$t6,0x800a
/*  f0aa870:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0aa874:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0aa878:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0aa87c:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f0aa880:	0c002f44 */ 	jal	func0000bd10
/*  f0aa884:	afae012c */ 	sw	$t6,0x12c($sp)
/*  f0aa888:	0c002f26 */ 	jal	func0000bc98
/*  f0aa88c:	a7a20076 */ 	sh	$v0,0x76($sp)
/*  f0aa890:	87af0076 */ 	lh	$t7,0x76($sp)
/*  f0aa894:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0aa898:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0aa89c:	8d0e006c */ 	lw	$t6,0x6c($t0)
/*  f0aa8a0:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0aa8a4:	2719fff3 */ 	addiu	$t9,$t8,-13
/*  f0aa8a8:	11c00003 */ 	beqz	$t6,.L0f0aa8b8
/*  f0aa8ac:	afb90128 */ 	sw	$t9,0x128($sp)
/*  f0aa8b0:	10000002 */ 	beqz	$zero,.L0f0aa8bc
/*  f0aa8b4:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0aa8b8:
/*  f0aa8b8:	00003025 */ 	or	$a2,$zero,$zero
.L0f0aa8bc:
/*  f0aa8bc:	8d0f0068 */ 	lw	$t7,0x68($t0)
/*  f0aa8c0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0aa8c4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0aa8c8:	11e00003 */ 	beqz	$t7,.L0f0aa8d8
/*  f0aa8cc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0aa8d0:	10000001 */ 	beqz	$zero,.L0f0aa8d8
/*  f0aa8d4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0aa8d8:
/*  f0aa8d8:	8d180064 */ 	lw	$t8,0x64($t0)
/*  f0aa8dc:	13000003 */ 	beqz	$t8,.L0f0aa8ec
/*  f0aa8e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa8e4:	10000001 */ 	beqz	$zero,.L0f0aa8ec
/*  f0aa8e8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0aa8ec:
/*  f0aa8ec:	8d190070 */ 	lw	$t9,0x70($t0)
/*  f0aa8f0:	13200003 */ 	beqz	$t9,.L0f0aa900
/*  f0aa8f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa8f8:	10000001 */ 	beqz	$zero,.L0f0aa900
/*  f0aa8fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0aa900:
/*  f0aa900:	8d18028c */ 	lw	$t8,0x28c($t0)
/*  f0aa904:	00457021 */ 	addu	$t6,$v0,$a1
/*  f0aa908:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f0aa90c:	afb80120 */ 	sw	$t8,0x120($sp)
/*  f0aa910:	8fb8012c */ 	lw	$t8,0x12c($sp)
/*  f0aa914:	01e63821 */ 	addu	$a3,$t7,$a2
/*  f0aa918:	24190009 */ 	addiu	$t9,$zero,0x9
/*  f0aa91c:	240e0024 */ 	addiu	$t6,$zero,0x24
/*  f0aa920:	240f0039 */ 	addiu	$t7,$zero,0x39
/*  f0aa924:	afa70124 */ 	sw	$a3,0x124($sp)
/*  f0aa928:	afa00110 */ 	sw	$zero,0x110($sp)
/*  f0aa92c:	afb9010c */ 	sw	$t9,0x10c($sp)
/*  f0aa930:	afae0108 */ 	sw	$t6,0x108($sp)
/*  f0aa934:	afaf0104 */ 	sw	$t7,0x104($sp)
/*  f0aa938:	83041580 */ 	lb	$a0,0x1580($t8)
/*  f0aa93c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0aa940:	afa70060 */ 	sw	$a3,0x60($sp)
/*  f0aa944:	8fb9012c */ 	lw	$t9,0x12c($sp)
/*  f0aa948:	afa200fc */ 	sw	$v0,0xfc($sp)
/*  f0aa94c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0aa950:	8f2e00d8 */ 	lw	$t6,0xd8($t9)
/*  f0aa954:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0aa958:	51c00004 */ 	beqzl	$t6,.L0f0aa96c
/*  f0aa95c:	8c6f0284 */ 	lw	$t7,0x284($v1)
/*  f0aa960:	10000457 */ 	beqz	$zero,.L0f0abac0
/*  f0aa964:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f0aa968:	8c6f0284 */ 	lw	$t7,0x284($v1)
.L0f0aa96c:
/*  f0aa96c:	8df81580 */ 	lw	$t8,0x1580($t7)
/*  f0aa970:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0aa974:	53200004 */ 	beqzl	$t9,.L0f0aa988
/*  f0aa978:	8c6e000c */ 	lw	$t6,0xc($v1)
/*  f0aa97c:	10000450 */ 	beqz	$zero,.L0f0abac0
/*  f0aa980:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f0aa984:	8c6e000c */ 	lw	$t6,0xc($v1)
.L0f0aa988:
/*  f0aa988:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0aa98c:	29c10005 */ 	slti	$at,$t6,0x5
/*  f0aa990:	10200003 */ 	beqz	$at,.L0f0aa9a0
/*  f0aa994:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aa998:	10000449 */ 	beqz	$zero,.L0f0abac0
/*  f0aa99c:	8fa20130 */ 	lw	$v0,0x130($sp)
.L0f0aa9a0:
/*  f0aa9a0:	8def06c8 */ 	lw	$t7,0x6c8($t7)
/*  f0aa9a4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0aa9a8:	144f0004 */ 	bne	$v0,$t7,.L0f0aa9bc
/*  f0aa9ac:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f0aa9b0:	3c018008 */ 	lui	$at,0x8008
/*  f0aa9b4:	10000003 */ 	beqz	$zero,.L0f0aa9c4
/*  f0aa9b8:	ac38fac0 */ 	sw	$t8,-0x540($at)
.L0f0aa9bc:
/*  f0aa9bc:	3c018008 */ 	lui	$at,0x8008
/*  f0aa9c0:	ac22fac0 */ 	sw	$v0,-0x540($at)
.L0f0aa9c4:
/*  f0aa9c4:	0fc54d8a */ 	jal	func0f153628
/*  f0aa9c8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0aa9cc:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0aa9d0:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0aa9d4:	2b210002 */ 	slti	$at,$t9,0x2
/*  f0aa9d8:	1420002a */ 	bnez	$at,.L0f0aaa84
/*  f0aa9dc:	240e0005 */ 	addiu	$t6,$zero,0x5
/*  f0aa9e0:	240f001a */ 	addiu	$t7,$zero,0x1a
/*  f0aa9e4:	2418002f */ 	addiu	$t8,$zero,0x2f
/*  f0aa9e8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0aa9ec:	afae010c */ 	sw	$t6,0x10c($sp)
/*  f0aa9f0:	afaf0108 */ 	sw	$t7,0x108($sp)
/*  f0aa9f4:	17210015 */ 	bne	$t9,$at,.L0f0aaa4c
/*  f0aa9f8:	afb80104 */ 	sw	$t8,0x104($sp)
/*  f0aa9fc:	3c0e8009 */ 	lui	$t6,0x8009
/*  f0aaa00:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f0aaa04:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0aaa08:	51c10009 */ 	beql	$t6,$at,.L0f0aaa30
/*  f0aaa0c:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f0aaa10:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0aaa14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aaa18:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0aaa1c:	10410007 */ 	beq	$v0,$at,.L0f0aaa3c
/*  f0aaa20:	8faf0120 */ 	lw	$t7,0x120($sp)
/*  f0aaa24:	55e00006 */ 	bnezl	$t7,.L0f0aaa40
/*  f0aaa28:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f0aaa2c:	8fb80128 */ 	lw	$t8,0x128($sp)
.L0f0aaa30:
/*  f0aaa30:	2719000a */ 	addiu	$t9,$t8,0xa
/*  f0aaa34:	10000019 */ 	beqz	$zero,.L0f0aaa9c
/*  f0aaa38:	afb90128 */ 	sw	$t9,0x128($sp)
.L0f0aaa3c:
/*  f0aaa3c:	8fae0128 */ 	lw	$t6,0x128($sp)
.L0f0aaa40:
/*  f0aaa40:	25cf0002 */ 	addiu	$t7,$t6,0x2
/*  f0aaa44:	10000015 */ 	beqz	$zero,.L0f0aaa9c
/*  f0aaa48:	afaf0128 */ 	sw	$t7,0x128($sp)
.L0f0aaa4c:
/*  f0aaa4c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0aaa50:	8fb90120 */ 	lw	$t9,0x120($sp)
/*  f0aaa54:	2b010003 */ 	slti	$at,$t8,0x3
/*  f0aaa58:	14200010 */ 	bnez	$at,.L0f0aaa9c
/*  f0aaa5c:	2b210002 */ 	slti	$at,$t9,0x2
/*  f0aaa60:	10200005 */ 	beqz	$at,.L0f0aaa78
/*  f0aaa64:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f0aaa68:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f0aaa6c:	25cf000a */ 	addiu	$t7,$t6,0xa
/*  f0aaa70:	1000000a */ 	beqz	$zero,.L0f0aaa9c
/*  f0aaa74:	afaf0128 */ 	sw	$t7,0x128($sp)
.L0f0aaa78:
/*  f0aaa78:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f0aaa7c:	10000007 */ 	beqz	$zero,.L0f0aaa9c
/*  f0aaa80:	afb90128 */ 	sw	$t9,0x128($sp)
.L0f0aaa84:
/*  f0aaa84:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0aaa88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aaa8c:	10400003 */ 	beqz	$v0,.L0f0aaa9c
/*  f0aaa90:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f0aaa94:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0aaa98:	afaf0128 */ 	sw	$t7,0x128($sp)
.L0f0aaa9c:
/*  f0aaa9c:	8fa2012c */ 	lw	$v0,0x12c($sp)
/*  f0aaaa0:	3c18ff00 */ 	lui	$t8,0xff00
/*  f0aaaa4:	3c0e800a */ 	lui	$t6,0x800a
/*  f0aaaa8:	8dce9ff4 */ 	lw	$t6,-0x600c($t6)
/*  f0aaaac:	37180040 */ 	ori	$t8,$t8,0x40
/*  f0aaab0:	afb800f4 */ 	sw	$t8,0xf4($sp)
/*  f0aaab4:	9059063b */ 	lbu	$t9,0x63b($v0)
/*  f0aaab8:	24420638 */ 	addiu	$v0,$v0,0x638
/*  f0aaabc:	000e7840 */ 	sll	$t7,$t6,0x1
/*  f0aaac0:	afaf00ec */ 	sw	$t7,0xec($sp)
/*  f0aaac4:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f0aaac8:	27a400dc */ 	addiu	$a0,$sp,0xdc
/*  f0aaacc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0aaad0:	0fc26313 */ 	jal	func0f098c4c
/*  f0aaad4:	afb900f0 */ 	sw	$t9,0xf0($sp)
/*  f0aaad8:	0fc2a31f */ 	jal	func0f0a8c7c
/*  f0aaadc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aaae0:	afa200e8 */ 	sw	$v0,0xe8($sp)
/*  f0aaae4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0aaae8:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f0aaaec:	0fc26328 */ 	jal	func0f098ca0
/*  f0aaaf0:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f0aaaf4:	04400003 */ 	bltz	$v0,.L0f0aab04
/*  f0aaaf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aaafc:	8fb800e8 */ 	lw	$t8,0xe8($sp)
/*  f0aab00:	afb800f0 */ 	sw	$t8,0xf0($sp)
.L0f0aab04:
/*  f0aab04:	0c002f40 */ 	jal	func0000bd00
/*  f0aab08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aab0c:	0c002f22 */ 	jal	func0000bc88
/*  f0aab10:	a7a20076 */ 	sh	$v0,0x76($sp)
/*  f0aab14:	87b90076 */ 	lh	$t9,0x76($sp)
/*  f0aab18:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0aab1c:	8deffac0 */ 	lw	$t7,-0x540($t7)
/*  f0aab20:	00597021 */ 	addu	$t6,$v0,$t9
/*  f0aab24:	8fb9010c */ 	lw	$t9,0x10c($sp)
/*  f0aab28:	01cf001a */ 	div	$zero,$t6,$t7
/*  f0aab2c:	15e00002 */ 	bnez	$t7,.L0f0aab38
/*  f0aab30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aab34:	0007000d */ 	break	0x7
.L0f0aab38:
/*  f0aab38:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0aab3c:	15e10004 */ 	bne	$t7,$at,.L0f0aab50
/*  f0aab40:	3c018000 */ 	lui	$at,0x8000
/*  f0aab44:	15c10002 */ 	bne	$t6,$at,.L0f0aab50
/*  f0aab48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aab4c:	0006000d */ 	break	0x6
.L0f0aab50:
/*  f0aab50:	0000c012 */ 	mflo	$t8
/*  f0aab54:	03197023 */ 	subu	$t6,$t8,$t9
/*  f0aab58:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0aab5c:	25cfffe8 */ 	addiu	$t7,$t6,-24
/*  f0aab60:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0aab64:	1701000f */ 	bne	$t8,$at,.L0f0aaba4
/*  f0aab68:	afaf0100 */ 	sw	$t7,0x100($sp)
/*  f0aab6c:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0aab70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aab74:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0aab78:	10e20004 */ 	beq	$a3,$v0,.L0f0aab8c
/*  f0aab7c:	3c198009 */ 	lui	$t9,0x8009
/*  f0aab80:	93390af0 */ 	lbu	$t9,0xaf0($t9)
/*  f0aab84:	54f90008 */ 	bnel	$a3,$t9,.L0f0aaba8
/*  f0aab88:	8fb90060 */ 	lw	$t9,0x60($sp)
.L0f0aab8c:
/*  f0aab8c:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f0aab90:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0aab94:	15c00003 */ 	bnez	$t6,.L0f0aaba4
/*  f0aab98:	25f8000f */ 	addiu	$t8,$t7,0xf
/*  f0aab9c:	1000000b */ 	beqz	$zero,.L0f0aabcc
/*  f0aaba0:	afb80100 */ 	sw	$t8,0x100($sp)
.L0f0aaba4:
/*  f0aaba4:	8fb90060 */ 	lw	$t9,0x60($sp)
.L0f0aaba8:
/*  f0aaba8:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f0aabac:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0aabb0:	2b210003 */ 	slti	$at,$t9,0x3
/*  f0aabb4:	14200005 */ 	bnez	$at,.L0f0aabcc
/*  f0aabb8:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f0aabbc:	15e00003 */ 	bnez	$t7,.L0f0aabcc
/*  f0aabc0:	8fb80100 */ 	lw	$t8,0x100($sp)
/*  f0aabc4:	2719000f */ 	addiu	$t9,$t8,0xf
/*  f0aabc8:	afb90100 */ 	sw	$t9,0x100($sp)
.L0f0aabcc:
/*  f0aabcc:	8fa600f0 */ 	lw	$a2,0xf0($sp)
/*  f0aabd0:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f0aabd4:	54c70014 */ 	bnel	$a2,$a3,.L0f0aac28
/*  f0aabd8:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f0aabdc:	914215e7 */ 	lbu	$v0,0x15e7($t2)
/*  f0aabe0:	254a1580 */ 	addiu	$t2,$t2,0x1580
/*  f0aabe4:	284100ff */ 	slti	$at,$v0,0xff
/*  f0aabe8:	1020000e */ 	beqz	$at,.L0f0aac24
/*  f0aabec:	28410080 */ 	slti	$at,$v0,0x80
/*  f0aabf0:	10200003 */ 	beqz	$at,.L0f0aac00
/*  f0aabf4:	240e0080 */ 	addiu	$t6,$zero,0x80
/*  f0aabf8:	a14e0067 */ 	sb	$t6,0x67($t2)
/*  f0aabfc:	31c200ff */ 	andi	$v0,$t6,0xff
.L0f0aac00:
/*  f0aac00:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f0aac04:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f0aac08:	004f1821 */ 	addu	$v1,$v0,$t7
/*  f0aac0c:	28610100 */ 	slti	$at,$v1,0x100
/*  f0aac10:	54200004 */ 	bnezl	$at,.L0f0aac24
/*  f0aac14:	a1430067 */ 	sb	$v1,0x67($t2)
/*  f0aac18:	10000002 */ 	beqz	$zero,.L0f0aac24
/*  f0aac1c:	a1580067 */ 	sb	$t8,0x67($t2)
/*  f0aac20:	a1430067 */ 	sb	$v1,0x67($t2)
.L0f0aac24:
/*  f0aac24:	8faa012c */ 	lw	$t2,0x12c($sp)
.L0f0aac28:
/*  f0aac28:	254a1580 */ 	addiu	$t2,$t2,0x1580
/*  f0aac2c:	14c0000a */ 	bnez	$a2,.L0f0aac58
/*  f0aac30:	91420067 */ 	lbu	$v0,0x67($t2)
/*  f0aac34:	18400008 */ 	blez	$v0,.L0f0aac58
/*  f0aac38:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0aac3c:	00591823 */ 	subu	$v1,$v0,$t9
/*  f0aac40:	04610004 */ 	bgez	$v1,.L0f0aac54
/*  f0aac44:	306200ff */ 	andi	$v0,$v1,0xff
/*  f0aac48:	a1400067 */ 	sb	$zero,0x67($t2)
/*  f0aac4c:	10000002 */ 	beqz	$zero,.L0f0aac58
/*  f0aac50:	300200ff */ 	andi	$v0,$zero,0xff
.L0f0aac54:
/*  f0aac54:	a1430067 */ 	sb	$v1,0x67($t2)
.L0f0aac58:
/*  f0aac58:	28410081 */ 	slti	$at,$v0,0x81
/*  f0aac5c:	14200007 */ 	bnez	$at,.L0f0aac7c
/*  f0aac60:	00027040 */ 	sll	$t6,$v0,0x1
/*  f0aac64:	25cfff00 */ 	addiu	$t7,$t6,-256
/*  f0aac68:	3c01ff00 */ 	lui	$at,0xff00
/*  f0aac6c:	34210040 */ 	ori	$at,$at,0x40
/*  f0aac70:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f0aac74:	0301c825 */ 	or	$t9,$t8,$at
/*  f0aac78:	afb900f4 */ 	sw	$t9,0xf4($sp)
.L0f0aac7c:
/*  f0aac7c:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0aac80:	8fa500f4 */ 	lw	$a1,0xf4($sp)
/*  f0aac84:	0fc54df7 */ 	jal	func0f1537dc
/*  f0aac88:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0aac8c:	3c068008 */ 	lui	$a2,%hi(var8007fac0)
/*  f0aac90:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0aac94:	24c6fac0 */ 	addiu	$a2,$a2,%lo(var8007fac0)
/*  f0aac98:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f0aac9c:	25f8fffe */ 	addiu	$t8,$t7,-2
/*  f0aaca0:	8fa50128 */ 	lw	$a1,0x128($sp)
/*  f0aaca4:	03190019 */ 	multu	$t8,$t9
/*  f0aaca8:	3c01f600 */ 	lui	$at,0xf600
/*  f0aacac:	30a303ff */ 	andi	$v1,$a1,0x3ff
/*  f0aacb0:	00037080 */ 	sll	$t6,$v1,0x2
/*  f0aacb4:	01c01825 */ 	or	$v1,$t6,$zero
/*  f0aacb8:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0aacbc:	00007012 */ 	mflo	$t6
/*  f0aacc0:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0aacc4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0aacc8:	0301c825 */ 	or	$t9,$t8,$at
/*  f0aaccc:	03237025 */ 	or	$t6,$t9,$v1
/*  f0aacd0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0aacd4:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0aacd8:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f0aacdc:	25f8fff3 */ 	addiu	$t8,$t7,-13
/*  f0aace0:	03190019 */ 	multu	$t8,$t9
/*  f0aace4:	24b9fff5 */ 	addiu	$t9,$a1,-11
/*  f0aace8:	00007012 */ 	mflo	$t6
/*  f0aacec:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0aacf0:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0aacf4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0aacf8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0aacfc:	030fc825 */ 	or	$t9,$t8,$t7
/*  f0aad00:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0aad04:	0fc54e0e */ 	jal	func0f153838
/*  f0aad08:	afa30060 */ 	sw	$v1,0x60($sp)
/*  f0aad0c:	3c0e800a */ 	lui	$t6,0x800a
/*  f0aad10:	8dcea248 */ 	lw	$t6,-0x5db8($t6)
/*  f0aad14:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0aad18:	0fc54a16 */ 	jal	optionsGetShowGunFunction
/*  f0aad1c:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0aad20:	10400163 */ 	beqz	$v0,.L0f0ab2b0
/*  f0aad24:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0aad28:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*  f0aad2c:	8fa500f0 */ 	lw	$a1,0xf0($sp)
/*  f0aad30:	93040000 */ 	lbu	$a0,0x0($t8)
/*  f0aad34:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f0aad38:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0aad3c:	0fc44bd4 */ 	jal	func0f112f50
/*  f0aad40:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0aad44:	0fc44b3e */ 	jal	func0f112cf8
/*  f0aad48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0aad4c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0aad50:	0fc5b9f1 */ 	jal	langGet
/*  f0aad54:	a7a200ba */ 	sh	$v0,0xba($sp)
/*  f0aad58:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0aad5c:	97a300ba */ 	lhu	$v1,0xba($sp)
/*  f0aad60:	00403025 */ 	or	$a2,$v0,$zero
/*  f0aad64:	954f0072 */ 	lhu	$t7,0x72($t2)
/*  f0aad68:	3c02800a */ 	lui	$v0,0x800a
/*  f0aad6c:	27a400c4 */ 	addiu	$a0,$sp,0xc4
/*  f0aad70:	106f0003 */ 	beq	$v1,$t7,.L0f0aad80
/*  f0aad74:	27a500c0 */ 	addiu	$a1,$sp,0xc0
/*  f0aad78:	a140006f */ 	sb	$zero,0x6f($t2)
/*  f0aad7c:	a5430072 */ 	sh	$v1,0x72($t2)
.L0f0aad80:
/*  f0aad80:	9143006f */ 	lbu	$v1,0x6f($t2)
/*  f0aad84:	3c078008 */ 	lui	$a3,0x8008
/*  f0aad88:	286100ff */ 	slti	$at,$v1,0xff
/*  f0aad8c:	5020008b */ 	beqzl	$at,.L0f0aafbc
/*  f0aad90:	8fa200bc */ 	lw	$v0,0xbc($sp)
/*  f0aad94:	8c429ff8 */ 	lw	$v0,-0x6008($v0)
/*  f0aad98:	3c1955ff */ 	lui	$t9,0x55ff
/*  f0aad9c:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f0aada0:	00627021 */ 	addu	$t6,$v1,$v0
/*  f0aada4:	29c10100 */ 	slti	$at,$t6,0x100
/*  f0aada8:	14200004 */ 	bnez	$at,.L0f0aadbc
/*  f0aadac:	afb900d0 */ 	sw	$t9,0xd0($sp)
/*  f0aadb0:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f0aadb4:	10000003 */ 	beqz	$zero,.L0f0aadc4
/*  f0aadb8:	a158006f */ 	sb	$t8,0x6f($t2)
.L0f0aadbc:
/*  f0aadbc:	0062c821 */ 	addu	$t9,$v1,$v0
/*  f0aadc0:	a159006f */ 	sb	$t9,0x6f($t2)
.L0f0aadc4:
/*  f0aadc4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0aadc8:	8dcefb04 */ 	lw	$t6,-0x4fc($t6)
/*  f0aadcc:	8ce7fb08 */ 	lw	$a3,-0x4f8($a3)
/*  f0aadd0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0aadd4:	afa600d4 */ 	sw	$a2,0xd4($sp)
/*  f0aadd8:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0aaddc:	0fc55cbe */ 	jal	func0f1572f8
/*  f0aade0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0aade4:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f0aade8:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0aadec:	00002825 */ 	or	$a1,$zero,$zero
/*  f0aadf0:	270f0002 */ 	addiu	$t7,$t8,0x2
/*  f0aadf4:	afaf00c0 */ 	sw	$t7,0xc0($sp)
/*  f0aadf8:	9142006f */ 	lbu	$v0,0x6f($t2)
/*  f0aadfc:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f0aae00:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f0aae04:	032f082a */ 	slt	$at,$t9,$t7
/*  f0aae08:	50200003 */ 	beqzl	$at,.L0f0aae18
/*  f0aae0c:	8fae0124 */ 	lw	$t6,0x124($sp)
/*  f0aae10:	afb900c0 */ 	sw	$t9,0xc0($sp)
/*  f0aae14:	8fae0124 */ 	lw	$t6,0x124($sp)
.L0f0aae18:
/*  f0aae18:	8fb80100 */ 	lw	$t8,0x100($sp)
/*  f0aae1c:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*  f0aae20:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0aae24:	14200007 */ 	bnez	$at,.L0f0aae44
/*  f0aae28:	03197823 */ 	subu	$t7,$t8,$t9
/*  f0aae2c:	8fb80100 */ 	lw	$t8,0x100($sp)
/*  f0aae30:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*  f0aae34:	03197823 */ 	subu	$t7,$t8,$t9
/*  f0aae38:	25eefff3 */ 	addiu	$t6,$t7,-13
/*  f0aae3c:	10000003 */ 	beqz	$zero,.L0f0aae4c
/*  f0aae40:	afae00cc */ 	sw	$t6,0xcc($sp)
.L0f0aae44:
/*  f0aae44:	25eefffe */ 	addiu	$t6,$t7,-2
/*  f0aae48:	afae00cc */ 	sw	$t6,0xcc($sp)
.L0f0aae4c:
/*  f0aae4c:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f0aae50:	8fb900c4 */ 	lw	$t9,0xc4($sp)
/*  f0aae54:	03197823 */ 	subu	$t7,$t8,$t9
/*  f0aae58:	25eefff1 */ 	addiu	$t6,$t7,-15
/*  f0aae5c:	afae00c8 */ 	sw	$t6,0xc8($sp)
/*  f0aae60:	9143006f */ 	lbu	$v1,0x6f($t2)
/*  f0aae64:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f0aae68:	286100c1 */ 	slti	$at,$v1,0xc1
/*  f0aae6c:	1420000d */ 	bnez	$at,.L0f0aaea4
/*  f0aae70:	0003c200 */ 	sll	$t8,$v1,0x8
/*  f0aae74:	3c01ffff */ 	lui	$at,0xffff
/*  f0aae78:	342140c0 */ 	ori	$at,$at,0x40c0
/*  f0aae7c:	0303c023 */ 	subu	$t8,$t8,$v1
/*  f0aae80:	0301c821 */ 	addu	$t9,$t8,$at
/*  f0aae84:	2401003f */ 	addiu	$at,$zero,0x3f
/*  f0aae88:	0321001b */ 	divu	$zero,$t9,$at
/*  f0aae8c:	00007812 */ 	mflo	$t7
/*  f0aae90:	3c0155ff */ 	lui	$at,0x55ff
/*  f0aae94:	01cf1023 */ 	subu	$v0,$t6,$t7
/*  f0aae98:	3421ff00 */ 	ori	$at,$at,0xff00
/*  f0aae9c:	0041c025 */ 	or	$t8,$v0,$at
/*  f0aaea0:	afb800d0 */ 	sw	$t8,0xd0($sp)
.L0f0aaea4:
/*  f0aaea4:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0aaea8:	0fc54df7 */ 	jal	func0f1537dc
/*  f0aaeac:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0aaeb0:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0aaeb4:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f0aaeb8:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f0aaebc:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0aaec0:	272efff5 */ 	addiu	$t6,$t9,-11
/*  f0aaec4:	3c01f600 */ 	lui	$at,0xf600
/*  f0aaec8:	01cf0019 */ 	multu	$t6,$t7
/*  f0aaecc:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0aaed0:	0000c012 */ 	mflo	$t8
/*  f0aaed4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0aaed8:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0aaedc:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0aaee0:	01c17825 */ 	or	$t7,$t6,$at
/*  f0aaee4:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f0aaee8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0aaeec:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*  f0aaef0:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0aaef4:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f0aaef8:	01f80019 */ 	multu	$t7,$t8
/*  f0aaefc:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*  f0aaf00:	0000c812 */ 	mflo	$t9
/*  f0aaf04:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0aaf08:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0aaf0c:	2719ffff */ 	addiu	$t9,$t8,-1
/*  f0aaf10:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0aaf14:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f0aaf18:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f0aaf1c:	0fc54e0e */ 	jal	func0f153838
/*  f0aaf20:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0aaf24:	3c018006 */ 	lui	$at,0x8006
/*  f0aaf28:	c4241630 */ 	lwc1	$f4,0x1630($at)
/*  f0aaf2c:	3c014248 */ 	lui	$at,0x4248
/*  f0aaf30:	44813000 */ 	mtc1	$at,$f6
/*  f0aaf34:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0aaf38:	00002825 */ 	or	$a1,$zero,$zero
/*  f0aaf3c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0aaf40:	24060032 */ 	addiu	$a2,$zero,0x32
/*  f0aaf44:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0aaf48:	44045000 */ 	mfc1	$a0,$f10
/*  f0aaf4c:	0fc54f54 */ 	jal	func0f153d50
/*  f0aaf50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aaf54:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0aaf58:	0fc54f8e */ 	jal	func0f153e38
/*  f0aaf5c:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0aaf60:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0aaf64:	8deffb08 */ 	lw	$t7,-0x4f8($t7)
/*  f0aaf68:	3c188008 */ 	lui	$t8,0x8008
/*  f0aaf6c:	8f18fb04 */ 	lw	$t8,-0x4fc($t8)
/*  f0aaf70:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*  f0aaf74:	8fae00c0 */ 	lw	$t6,0xc0($sp)
/*  f0aaf78:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0aaf7c:	240f03e8 */ 	addiu	$t7,$zero,0x3e8
/*  f0aaf80:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0aaf84:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0aaf88:	27a500cc */ 	addiu	$a1,$sp,0xcc
/*  f0aaf8c:	27a600c8 */ 	addiu	$a2,$sp,0xc8
/*  f0aaf90:	8fa700d4 */ 	lw	$a3,0xd4($sp)
/*  f0aaf94:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0aaf98:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0aaf9c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0aafa0:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0aafa4:	0fc5580f */ 	jal	func0f15603c
/*  f0aafa8:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0aafac:	0fc54f93 */ 	jal	func0f153e4c
/*  f0aafb0:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0aafb4:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0aafb8:	8fa200bc */ 	lw	$v0,0xbc($sp)
.L0f0aafbc:
/*  f0aafbc:	504000bd */ 	beqzl	$v0,.L0f0ab2b4
/*  f0aafc0:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f0aafc4:	94440004 */ 	lhu	$a0,0x4($v0)
/*  f0aafc8:	0fc5b9f1 */ 	jal	langGet
/*  f0aafcc:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0aafd0:	3c18ff55 */ 	lui	$t8,0xff55
/*  f0aafd4:	8fa300bc */ 	lw	$v1,0xbc($sp)
/*  f0aafd8:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0aafdc:	371855ff */ 	ori	$t8,$t8,0x55ff
/*  f0aafe0:	afb800d0 */ 	sw	$t8,0xd0($sp)
/*  f0aafe4:	94790004 */ 	lhu	$t9,0x4($v1)
/*  f0aafe8:	9544006c */ 	lhu	$a0,0x6c($t2)
/*  f0aafec:	13240005 */ 	beq	$t9,$a0,.L0f0ab004
/*  f0aaff0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aaff4:	914e0067 */ 	lbu	$t6,0x67($t2)
/*  f0aaff8:	29c10081 */ 	slti	$at,$t6,0x81
/*  f0aaffc:	50200004 */ 	beqzl	$at,.L0f0ab010
/*  f0ab000:	a140006e */ 	sb	$zero,0x6e($t2)
.L0f0ab004:
/*  f0ab004:	14800005 */ 	bnez	$a0,.L0f0ab01c
/*  f0ab008:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab00c:	a140006e */ 	sb	$zero,0x6e($t2)
.L0f0ab010:
/*  f0ab010:	946f0004 */ 	lhu	$t7,0x4($v1)
/*  f0ab014:	a54f006c */ 	sh	$t7,0x6c($t2)
/*  f0ab018:	31e4ffff */ 	andi	$a0,$t7,0xffff
.L0f0ab01c:
/*  f0ab01c:	0fc5b9f1 */ 	jal	langGet
/*  f0ab020:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ab024:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0ab028:	00403025 */ 	or	$a2,$v0,$zero
/*  f0ab02c:	3c02800a */ 	lui	$v0,0x800a
/*  f0ab030:	9143006e */ 	lbu	$v1,0x6e($t2)
/*  f0ab034:	8fb80100 */ 	lw	$t8,0x100($sp)
/*  f0ab038:	27a400c4 */ 	addiu	$a0,$sp,0xc4
/*  f0ab03c:	286100ff */ 	slti	$at,$v1,0xff
/*  f0ab040:	1020009b */ 	beqz	$at,.L0f0ab2b0
/*  f0ab044:	27a500c0 */ 	addiu	$a1,$sp,0xc0
/*  f0ab048:	8c429ff8 */ 	lw	$v0,-0x6008($v0)
/*  f0ab04c:	2719fff5 */ 	addiu	$t9,$t8,-11
/*  f0ab050:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f0ab054:	00627021 */ 	addu	$t6,$v1,$v0
/*  f0ab058:	29c10100 */ 	slti	$at,$t6,0x100
/*  f0ab05c:	14200004 */ 	bnez	$at,.L0f0ab070
/*  f0ab060:	3c078008 */ 	lui	$a3,0x8008
/*  f0ab064:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f0ab068:	10000003 */ 	beqz	$zero,.L0f0ab078
/*  f0ab06c:	a14f006e */ 	sb	$t7,0x6e($t2)
.L0f0ab070:
/*  f0ab070:	0062c821 */ 	addu	$t9,$v1,$v0
/*  f0ab074:	a159006e */ 	sb	$t9,0x6e($t2)
.L0f0ab078:
/*  f0ab078:	8fae00f0 */ 	lw	$t6,0xf0($sp)
/*  f0ab07c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ab080:	55c1000a */ 	bnel	$t6,$at,.L0f0ab0ac
/*  f0ab084:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f0ab088:	8fb800bc */ 	lw	$t8,0xbc($sp)
/*  f0ab08c:	954f006c */ 	lhu	$t7,0x6c($t2)
/*  f0ab090:	3c0effff */ 	lui	$t6,0xffff
/*  f0ab094:	97190004 */ 	lhu	$t9,0x4($t8)
/*  f0ab098:	35ce55ff */ 	ori	$t6,$t6,0x55ff
/*  f0ab09c:	55f90003 */ 	bnel	$t7,$t9,.L0f0ab0ac
/*  f0ab0a0:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f0ab0a4:	afae00d0 */ 	sw	$t6,0xd0($sp)
/*  f0ab0a8:	8fb800f0 */ 	lw	$t8,0xf0($sp)
.L0f0ab0ac:
/*  f0ab0ac:	8fb900bc */ 	lw	$t9,0xbc($sp)
/*  f0ab0b0:	17000008 */ 	bnez	$t8,.L0f0ab0d4
/*  f0ab0b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab0b8:	954f006c */ 	lhu	$t7,0x6c($t2)
/*  f0ab0bc:	972e0004 */ 	lhu	$t6,0x4($t9)
/*  f0ab0c0:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*  f0ab0c4:	3c0100ff */ 	lui	$at,0xff
/*  f0ab0c8:	11ee0002 */ 	beq	$t7,$t6,.L0f0ab0d4
/*  f0ab0cc:	0301c825 */ 	or	$t9,$t8,$at
/*  f0ab0d0:	afb900d0 */ 	sw	$t9,0xd0($sp)
.L0f0ab0d4:
/*  f0ab0d4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0ab0d8:	8deffb04 */ 	lw	$t7,-0x4fc($t7)
/*  f0ab0dc:	8ce7fb08 */ 	lw	$a3,-0x4f8($a3)
/*  f0ab0e0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ab0e4:	afa600d4 */ 	sw	$a2,0xd4($sp)
/*  f0ab0e8:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ab0ec:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ab0f0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ab0f4:	8fae00c0 */ 	lw	$t6,0xc0($sp)
/*  f0ab0f8:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0ab0fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ab100:	25d80002 */ 	addiu	$t8,$t6,0x2
/*  f0ab104:	afb800c0 */ 	sw	$t8,0xc0($sp)
/*  f0ab108:	9142006e */ 	lbu	$v0,0x6e($t2)
/*  f0ab10c:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f0ab110:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f0ab114:	0338082a */ 	slt	$at,$t9,$t8
/*  f0ab118:	50200003 */ 	beqzl	$at,.L0f0ab128
/*  f0ab11c:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0ab120:	afb900c0 */ 	sw	$t9,0xc0($sp)
/*  f0ab124:	8faf0100 */ 	lw	$t7,0x100($sp)
.L0f0ab128:
/*  f0ab128:	8fae00c0 */ 	lw	$t6,0xc0($sp)
/*  f0ab12c:	01eec823 */ 	subu	$t9,$t7,$t6
/*  f0ab130:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f0ab134:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f0ab138:	2738fff3 */ 	addiu	$t8,$t9,-13
/*  f0ab13c:	afb800cc */ 	sw	$t8,0xcc($sp)
/*  f0ab140:	01eec823 */ 	subu	$t9,$t7,$t6
/*  f0ab144:	2738ffff */ 	addiu	$t8,$t9,-1
/*  f0ab148:	afb800c8 */ 	sw	$t8,0xc8($sp)
/*  f0ab14c:	9143006e */ 	lbu	$v1,0x6e($t2)
/*  f0ab150:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f0ab154:	286100c1 */ 	slti	$at,$v1,0xc1
/*  f0ab158:	1420000e */ 	bnez	$at,.L0f0ab194
/*  f0ab15c:	00037a00 */ 	sll	$t7,$v1,0x8
/*  f0ab160:	3c01ffff */ 	lui	$at,0xffff
/*  f0ab164:	342140c0 */ 	ori	$at,$at,0x40c0
/*  f0ab168:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f0ab16c:	01e17021 */ 	addu	$t6,$t7,$at
/*  f0ab170:	2401003f */ 	addiu	$at,$zero,0x3f
/*  f0ab174:	01c1001b */ 	divu	$zero,$t6,$at
/*  f0ab178:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*  f0ab17c:	0000c812 */ 	mflo	$t9
/*  f0ab180:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ab184:	03191023 */ 	subu	$v0,$t8,$t9
/*  f0ab188:	01e17024 */ 	and	$t6,$t7,$at
/*  f0ab18c:	01c2c025 */ 	or	$t8,$t6,$v0
/*  f0ab190:	afb800d0 */ 	sw	$t8,0xd0($sp)
.L0f0ab194:
/*  f0ab194:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ab198:	0fc54df7 */ 	jal	func0f1537dc
/*  f0ab19c:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ab1a0:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0ab1a4:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f0ab1a8:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0ab1ac:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0ab1b0:	3c01f600 */ 	lui	$at,0xf600
/*  f0ab1b4:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0ab1b8:	032f0019 */ 	multu	$t9,$t7
/*  f0ab1bc:	00007012 */ 	mflo	$t6
/*  f0ab1c0:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0ab1c4:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f0ab1c8:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0ab1cc:	03217825 */ 	or	$t7,$t9,$at
/*  f0ab1d0:	25d80003 */ 	addiu	$t8,$t6,0x3
/*  f0ab1d4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0ab1d8:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0ab1dc:	01eec025 */ 	or	$t8,$t7,$t6
/*  f0ab1e0:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0ab1e4:	8fb900cc */ 	lw	$t9,0xcc($sp)
/*  f0ab1e8:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0ab1ec:	272fffff */ 	addiu	$t7,$t9,-1
/*  f0ab1f0:	01ee0019 */ 	multu	$t7,$t6
/*  f0ab1f4:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*  f0ab1f8:	0000c012 */ 	mflo	$t8
/*  f0ab1fc:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0ab200:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0ab204:	25d8ffff */ 	addiu	$t8,$t6,-1
/*  f0ab208:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0ab20c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0ab210:	01eec025 */ 	or	$t8,$t7,$t6
/*  f0ab214:	0fc54e0e */ 	jal	func0f153838
/*  f0ab218:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0ab21c:	3c018006 */ 	lui	$at,0x8006
/*  f0ab220:	c4301630 */ 	lwc1	$f16,0x1630($at)
/*  f0ab224:	3c014248 */ 	lui	$at,0x4248
/*  f0ab228:	44819000 */ 	mtc1	$at,$f18
/*  f0ab22c:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0ab230:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ab234:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0ab238:	24060032 */ 	addiu	$a2,$zero,0x32
/*  f0ab23c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0ab240:	44043000 */ 	mfc1	$a0,$f6
/*  f0ab244:	0fc54f54 */ 	jal	func0f153d50
/*  f0ab248:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab24c:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0ab250:	0fc54f8e */ 	jal	func0f153e38
/*  f0ab254:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0ab258:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0ab25c:	8deffb08 */ 	lw	$t7,-0x4f8($t7)
/*  f0ab260:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0ab264:	8dcefb04 */ 	lw	$t6,-0x4fc($t6)
/*  f0ab268:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*  f0ab26c:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*  f0ab270:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ab274:	240f03e8 */ 	addiu	$t7,$zero,0x3e8
/*  f0ab278:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0ab27c:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ab280:	27a500cc */ 	addiu	$a1,$sp,0xcc
/*  f0ab284:	27a600c8 */ 	addiu	$a2,$sp,0xc8
/*  f0ab288:	8fa700d4 */ 	lw	$a3,0xd4($sp)
/*  f0ab28c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ab290:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ab294:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0ab298:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0ab29c:	0fc5580f */ 	jal	func0f15603c
/*  f0ab2a0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0ab2a4:	0fc54f93 */ 	jal	func0f153e4c
/*  f0ab2a8:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0ab2ac:	8faa0058 */ 	lw	$t2,0x58($sp)
.L0f0ab2b0:
/*  f0ab2b0:	8fa500fc */ 	lw	$a1,0xfc($sp)
.L0f0ab2b4:
/*  f0ab2b4:	8fae005c */ 	lw	$t6,0x5c($sp)
/*  f0ab2b8:	50a0000a */ 	beqzl	$a1,.L0f0ab2e4
/*  f0ab2bc:	8fb80110 */ 	lw	$t8,0x110($sp)
/*  f0ab2c0:	91d80003 */ 	lbu	$t8,0x3($t6)
/*  f0ab2c4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0ab2c8:	00b97821 */ 	addu	$t7,$a1,$t9
/*  f0ab2cc:	8de20014 */ 	lw	$v0,0x14($t7)
/*  f0ab2d0:	50400004 */ 	beqzl	$v0,.L0f0ab2e4
/*  f0ab2d4:	8fb80110 */ 	lw	$t8,0x110($sp)
/*  f0ab2d8:	804e0007 */ 	lb	$t6,0x7($v0)
/*  f0ab2dc:	afae0110 */ 	sw	$t6,0x110($sp)
/*  f0ab2e0:	8fb80110 */ 	lw	$t8,0x110($sp)
.L0f0ab2e4:
/*  f0ab2e4:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0ab2e8:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*  f0ab2ec:	57030014 */ 	bnel	$t8,$v1,.L0f0ab340
/*  f0ab2f0:	8fb90110 */ 	lw	$t9,0x110($sp)
/*  f0ab2f4:	932f0003 */ 	lbu	$t7,0x3($t9)
/*  f0ab2f8:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f0ab2fc:	000ec023 */ 	negu	$t8,$t6
/*  f0ab300:	00b8c821 */ 	addu	$t9,$a1,$t8
/*  f0ab304:	8f220018 */ 	lw	$v0,0x18($t9)
/*  f0ab308:	50400004 */ 	beqzl	$v0,.L0f0ab31c
/*  f0ab30c:	8fae0110 */ 	lw	$t6,0x110($sp)
/*  f0ab310:	804f0007 */ 	lb	$t7,0x7($v0)
/*  f0ab314:	afaf0110 */ 	sw	$t7,0x110($sp)
/*  f0ab318:	8fae0110 */ 	lw	$t6,0x110($sp)
.L0f0ab31c:
/*  f0ab31c:	55c30008 */ 	bnel	$t6,$v1,.L0f0ab340
/*  f0ab320:	8fb90110 */ 	lw	$t9,0x110($sp)
/*  f0ab324:	0fc54de0 */ 	jal	func0f153780
/*  f0ab328:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ab32c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0ab330:	3c018008 */ 	lui	$at,0x8008
/*  f0ab334:	100001e2 */ 	beqz	$zero,.L0f0abac0
/*  f0ab338:	ac38fac0 */ 	sw	$t8,-0x540($at)
/*  f0ab33c:	8fb90110 */ 	lw	$t9,0x110($sp)
.L0f0ab340:
/*  f0ab340:	814f0069 */ 	lb	$t7,0x69($t2)
/*  f0ab344:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f0ab348:	132f000d */ 	beq	$t9,$t7,.L0f0ab380
/*  f0ab34c:	24841568 */ 	addiu	$a0,$a0,0x1568
/*  f0ab350:	0fc2a765 */ 	jal	func0f0a9d94
/*  f0ab354:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ab358:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f0ab35c:	0fc2a765 */ 	jal	func0f0a9d94
/*  f0ab360:	2484078c */ 	addiu	$a0,$a0,0x78c
/*  f0ab364:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0ab368:	0fc2a765 */ 	jal	func0f0a9d94
/*  f0ab36c:	2544005c */ 	addiu	$a0,$t2,0x5c
/*  f0ab370:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0ab374:	8fae0110 */ 	lw	$t6,0x110($sp)
/*  f0ab378:	a14e0069 */ 	sb	$t6,0x69($t2)
/*  f0ab37c:	8fa500fc */ 	lw	$a1,0xfc($sp)
.L0f0ab380:
/*  f0ab380:	8fb8012c */ 	lw	$t8,0x12c($sp)
/*  f0ab384:	8fa20110 */ 	lw	$v0,0x110($sp)
/*  f0ab388:	27190ddc */ 	addiu	$t9,$t8,0xddc
/*  f0ab38c:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f0ab390:	830f0de4 */ 	lb	$t7,0xde4($t8)
/*  f0ab394:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0ab398:	00ae2021 */ 	addu	$a0,$a1,$t6
/*  f0ab39c:	51e00076 */ 	beqzl	$t7,.L0f0ab578
/*  f0ab3a0:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f0ab3a4:	8c99001c */ 	lw	$t9,0x1c($a0)
/*  f0ab3a8:	53200073 */ 	beqzl	$t9,.L0f0ab578
/*  f0ab3ac:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f0ab3b0:	930f0ddc */ 	lbu	$t7,0xddc($t8)
/*  f0ab3b4:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0ab3b8:	51e1006f */ 	beql	$t7,$at,.L0f0ab578
/*  f0ab3bc:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f0ab3c0:	afae0050 */ 	sw	$t6,0x50($sp)
/*  f0ab3c4:	afa40054 */ 	sw	$a0,0x54($sp)
/*  f0ab3c8:	0c002f40 */ 	jal	func0000bd00
/*  f0ab3cc:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ab3d0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0ab3d4:	8dcefac0 */ 	lw	$t6,-0x540($t6)
/*  f0ab3d8:	8faf0124 */ 	lw	$t7,0x124($sp)
/*  f0ab3dc:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f0ab3e0:	004e001a */ 	div	$zero,$v0,$t6
/*  f0ab3e4:	0000c812 */ 	mflo	$t9
/*  f0ab3e8:	27380018 */ 	addiu	$t8,$t9,0x18
/*  f0ab3ec:	afb80100 */ 	sw	$t8,0x100($sp)
/*  f0ab3f0:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0ab3f4:	15c00002 */ 	bnez	$t6,.L0f0ab400
/*  f0ab3f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab3fc:	0007000d */ 	break	0x7
.L0f0ab400:
/*  f0ab400:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ab404:	15c10004 */ 	bne	$t6,$at,.L0f0ab418
/*  f0ab408:	3c018000 */ 	lui	$at,0x8000
/*  f0ab40c:	14410002 */ 	bne	$v0,$at,.L0f0ab418
/*  f0ab410:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab414:	0006000d */ 	break	0x6
.L0f0ab418:
/*  f0ab418:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0ab41c:	55e10015 */ 	bnel	$t7,$at,.L0f0ab474
/*  f0ab420:	8fae0124 */ 	lw	$t6,0x124($sp)
/*  f0ab424:	afa40054 */ 	sw	$a0,0x54($sp)
/*  f0ab428:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0ab42c:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ab430:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ab434:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f0ab438:	10410006 */ 	beq	$v0,$at,.L0f0ab454
/*  f0ab43c:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0ab440:	3c0e8009 */ 	lui	$t6,0x8009
/*  f0ab444:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f0ab448:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ab44c:	55c10009 */ 	bnel	$t6,$at,.L0f0ab474
/*  f0ab450:	8fae0124 */ 	lw	$t6,0x124($sp)
.L0f0ab454:
/*  f0ab454:	8fb90120 */ 	lw	$t9,0x120($sp)
/*  f0ab458:	8fb80100 */ 	lw	$t8,0x100($sp)
/*  f0ab45c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ab460:	17210003 */ 	bne	$t9,$at,.L0f0ab470
/*  f0ab464:	270ffff2 */ 	addiu	$t7,$t8,-14
/*  f0ab468:	1000000b */ 	beqz	$zero,.L0f0ab498
/*  f0ab46c:	afaf0100 */ 	sw	$t7,0x100($sp)
.L0f0ab470:
/*  f0ab470:	8fae0124 */ 	lw	$t6,0x124($sp)
.L0f0ab474:
/*  f0ab474:	8fb90120 */ 	lw	$t9,0x120($sp)
/*  f0ab478:	29c10003 */ 	slti	$at,$t6,0x3
/*  f0ab47c:	14200006 */ 	bnez	$at,.L0f0ab498
/*  f0ab480:	33380001 */ 	andi	$t8,$t9,0x1
/*  f0ab484:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ab488:	17010003 */ 	bne	$t8,$at,.L0f0ab498
/*  f0ab48c:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0ab490:	25eefff2 */ 	addiu	$t6,$t7,-14
/*  f0ab494:	afae0100 */ 	sw	$t6,0x100($sp)
.L0f0ab498:
/*  f0ab498:	8fa90060 */ 	lw	$t1,0x60($sp)
/*  f0ab49c:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0ab4a0:	01391821 */ 	addu	$v1,$t1,$t9
/*  f0ab4a4:	8c680228 */ 	lw	$t0,0x228($v1)
/*  f0ab4a8:	59000033 */ 	blezl	$t0,.L0f0ab578
/*  f0ab4ac:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f0ab4b0:	8c98001c */ 	lw	$t8,0x1c($a0)
/*  f0ab4b4:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ab4b8:	930f0010 */ 	lbu	$t7,0x10($t8)
/*  f0ab4bc:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f0ab4c0:	31ee0002 */ 	andi	$t6,$t7,0x2
/*  f0ab4c4:	15c0002b */ 	bnez	$t6,.L0f0ab574
/*  f0ab4c8:	8faf0108 */ 	lw	$t7,0x108($sp)
/*  f0ab4cc:	8fae0104 */ 	lw	$t6,0x104($sp)
/*  f0ab4d0:	030f1023 */ 	subu	$v0,$t8,$t7
/*  f0ab4d4:	244ffffd */ 	addiu	$t7,$v0,-3
/*  f0ab4d8:	004e3023 */ 	subu	$a2,$v0,$t6
/*  f0ab4dc:	252e078c */ 	addiu	$t6,$t1,0x78c
/*  f0ab4e0:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0ab4e4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ab4e8:	8c790220 */ 	lw	$t9,0x220($v1)
/*  f0ab4ec:	8fb8010c */ 	lw	$t8,0x10c($sp)
/*  f0ab4f0:	8fa50100 */ 	lw	$a1,0x100($sp)
/*  f0ab4f4:	3c0f00ff */ 	lui	$t7,0xff
/*  f0ab4f8:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f0ab4fc:	00b83821 */ 	addu	$a3,$a1,$t8
/*  f0ab500:	3c180030 */ 	lui	$t8,0x30
/*  f0ab504:	37180080 */ 	ori	$t8,$t8,0x80
/*  f0ab508:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0ab50c:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f0ab510:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f0ab514:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ab518:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0ab51c:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0ab520:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ab524:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0ab528:	24c6fffd */ 	addiu	$a2,$a2,-3
/*  f0ab52c:	0fc2a7f0 */ 	jal	func0f0a9fc0
/*  f0ab530:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0ab534:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0ab538:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0ab53c:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f0ab540:	3c1800ff */ 	lui	$t8,0xff
/*  f0ab544:	8c650220 */ 	lw	$a1,0x220($v1)
/*  f0ab548:	371800a0 */ 	ori	$t8,$t8,0xa0
/*  f0ab54c:	25d9fff8 */ 	addiu	$t9,$t6,-8
/*  f0ab550:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ab554:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0ab558:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ab55c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ab560:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0ab564:	0fc2a74b */ 	jal	func0f0a9d2c
/*  f0ab568:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f0ab56c:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0ab570:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0ab574:
/*  f0ab574:	8faf005c */ 	lw	$t7,0x5c($sp)
.L0f0ab578:
/*  f0ab578:	8fb90110 */ 	lw	$t9,0x110($sp)
/*  f0ab57c:	81ee0008 */ 	lb	$t6,0x8($t7)
/*  f0ab580:	0159c021 */ 	addu	$t8,$t2,$t9
/*  f0ab584:	11c00149 */ 	beqz	$t6,.L0f0abaac
/*  f0ab588:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab58c:	830f0064 */ 	lb	$t7,0x64($t8)
/*  f0ab590:	8fae012c */ 	lw	$t6,0x12c($sp)
/*  f0ab594:	05e00145 */ 	bltz	$t7,.L0f0abaac
/*  f0ab598:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f0ab59c:	830f15e4 */ 	lb	$t7,0x15e4($t8)
/*  f0ab5a0:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0ab5a4:	afae0050 */ 	sw	$t6,0x50($sp)
/*  f0ab5a8:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ab5ac:	0c002f40 */ 	jal	func0000bd00
/*  f0ab5b0:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f0ab5b4:	0c002f22 */ 	jal	func0000bc88
/*  f0ab5b8:	a7a20076 */ 	sh	$v0,0x76($sp)
/*  f0ab5bc:	87b80076 */ 	lh	$t8,0x76($sp)
/*  f0ab5c0:	3c198008 */ 	lui	$t9,0x8008
/*  f0ab5c4:	8f39fac0 */ 	lw	$t9,-0x540($t9)
/*  f0ab5c8:	00587821 */ 	addu	$t7,$v0,$t8
/*  f0ab5cc:	8fb8010c */ 	lw	$t8,0x10c($sp)
/*  f0ab5d0:	01f9001a */ 	div	$zero,$t7,$t9
/*  f0ab5d4:	00007012 */ 	mflo	$t6
/*  f0ab5d8:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0ab5dc:	17200002 */ 	bnez	$t9,.L0f0ab5e8
/*  f0ab5e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab5e4:	0007000d */ 	break	0x7
.L0f0ab5e8:
/*  f0ab5e8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ab5ec:	17210004 */ 	bne	$t9,$at,.L0f0ab600
/*  f0ab5f0:	3c018000 */ 	lui	$at,0x8000
/*  f0ab5f4:	15e10002 */ 	bne	$t7,$at,.L0f0ab600
/*  f0ab5f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab5fc:	0006000d */ 	break	0x6
.L0f0ab600:
/*  f0ab600:	01d87823 */ 	subu	$t7,$t6,$t8
/*  f0ab604:	8fae0124 */ 	lw	$t6,0x124($sp)
/*  f0ab608:	25f9ffe8 */ 	addiu	$t9,$t7,-24
/*  f0ab60c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0ab610:	15c10011 */ 	bne	$t6,$at,.L0f0ab658
/*  f0ab614:	afb90100 */ 	sw	$t9,0x100($sp)
/*  f0ab618:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0ab61c:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ab620:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ab624:	10410006 */ 	beq	$v0,$at,.L0f0ab640
/*  f0ab628:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0ab62c:	3c188009 */ 	lui	$t8,0x8009
/*  f0ab630:	93180af0 */ 	lbu	$t8,0xaf0($t8)
/*  f0ab634:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ab638:	57010008 */ 	bnel	$t8,$at,.L0f0ab65c
/*  f0ab63c:	8fb80124 */ 	lw	$t8,0x124($sp)
.L0f0ab640:
/*  f0ab640:	8faf0120 */ 	lw	$t7,0x120($sp)
/*  f0ab644:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f0ab648:	15e00003 */ 	bnez	$t7,.L0f0ab658
/*  f0ab64c:	272e000f */ 	addiu	$t6,$t9,0xf
/*  f0ab650:	1000000a */ 	beqz	$zero,.L0f0ab67c
/*  f0ab654:	afae0100 */ 	sw	$t6,0x100($sp)
.L0f0ab658:
/*  f0ab658:	8fb80124 */ 	lw	$t8,0x124($sp)
.L0f0ab65c:
/*  f0ab65c:	8faf0120 */ 	lw	$t7,0x120($sp)
/*  f0ab660:	2b010003 */ 	slti	$at,$t8,0x3
/*  f0ab664:	14200005 */ 	bnez	$at,.L0f0ab67c
/*  f0ab668:	31f90001 */ 	andi	$t9,$t7,0x1
/*  f0ab66c:	17200003 */ 	bnez	$t9,.L0f0ab67c
/*  f0ab670:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f0ab674:	25d8000f */ 	addiu	$t8,$t6,0xf
/*  f0ab678:	afb80100 */ 	sw	$t8,0x100($sp)
.L0f0ab67c:
/*  f0ab67c:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f0ab680:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f0ab684:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0ab688:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0ab68c:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*  f0ab690:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0ab694:	8faf00fc */ 	lw	$t7,0xfc($sp)
/*  f0ab698:	03294021 */ 	addu	$t0,$t9,$t1
/*  f0ab69c:	8d030228 */ 	lw	$v1,0x228($t0)
/*  f0ab6a0:	8f0c17a8 */ 	lw	$t4,0x17a8($t8)
/*  f0ab6a4:	01e97021 */ 	addu	$t6,$t7,$t1
/*  f0ab6a8:	58600038 */ 	blezl	$v1,.L0f0ab78c
/*  f0ab6ac:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f0ab6b0:	8dc2001c */ 	lw	$v0,0x1c($t6)
/*  f0ab6b4:	50400035 */ 	beqzl	$v0,.L0f0ab78c
/*  f0ab6b8:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f0ab6bc:	90580010 */ 	lbu	$t8,0x10($v0)
/*  f0ab6c0:	272e078c */ 	addiu	$t6,$t9,0x78c
/*  f0ab6c4:	3c1900ff */ 	lui	$t9,0xff
/*  f0ab6c8:	330f0002 */ 	andi	$t7,$t8,0x2
/*  f0ab6cc:	15e0002e */ 	bnez	$t7,.L0f0ab788
/*  f0ab6d0:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f0ab6d4:	8faf0108 */ 	lw	$t7,0x108($sp)
/*  f0ab6d8:	8fa50100 */ 	lw	$a1,0x100($sp)
/*  f0ab6dc:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0ab6e0:	030f1023 */ 	subu	$v0,$t8,$t7
/*  f0ab6e4:	8fb80104 */ 	lw	$t8,0x104($sp)
/*  f0ab6e8:	8faf010c */ 	lw	$t7,0x10c($sp)
/*  f0ab6ec:	244efff8 */ 	addiu	$t6,$v0,-8
/*  f0ab6f0:	00583023 */ 	subu	$a2,$v0,$t8
/*  f0ab6f4:	2458fffd */ 	addiu	$t8,$v0,-3
/*  f0ab6f8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ab6fc:	00af3821 */ 	addu	$a3,$a1,$t7
/*  f0ab700:	8d0f0220 */ 	lw	$t7,0x220($t0)
/*  f0ab704:	3c180030 */ 	lui	$t8,0x30
/*  f0ab708:	37180080 */ 	ori	$t8,$t8,0x80
/*  f0ab70c:	37390040 */ 	ori	$t9,$t9,0x40
/*  f0ab710:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f0ab714:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0ab718:	afac00a0 */ 	sw	$t4,0xa0($sp)
/*  f0ab71c:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ab720:	afa80038 */ 	sw	$t0,0x38($sp)
/*  f0ab724:	afae0054 */ 	sw	$t6,0x54($sp)
/*  f0ab728:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ab72c:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0ab730:	24c6fffd */ 	addiu	$a2,$a2,-3
/*  f0ab734:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ab738:	0fc2a7f0 */ 	jal	func0f0a9fc0
/*  f0ab73c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0ab740:	8fa80038 */ 	lw	$t0,0x38($sp)
/*  f0ab744:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f0ab748:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f0ab74c:	3c1800ff */ 	lui	$t8,0xff
/*  f0ab750:	8d050220 */ 	lw	$a1,0x220($t0)
/*  f0ab754:	371800a0 */ 	ori	$t8,$t8,0xa0
/*  f0ab758:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0ab75c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ab760:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ab764:	00003825 */ 	or	$a3,$zero,$zero
/*  f0ab768:	24c6fffe */ 	addiu	$a2,$a2,-2
/*  f0ab76c:	0fc2a74b */ 	jal	func0f0a9d2c
/*  f0ab770:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ab774:	8fa80038 */ 	lw	$t0,0x38($sp)
/*  f0ab778:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0ab77c:	8fac00a0 */ 	lw	$t4,0xa0($sp)
/*  f0ab780:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0ab784:	8fa90050 */ 	lw	$t1,0x50($sp)
.L0f0ab788:
/*  f0ab788:	8fb900a4 */ 	lw	$t9,0xa4($sp)
.L0f0ab78c:
/*  f0ab78c:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0ab790:	8faf00fc */ 	lw	$t7,0xfc($sp)
/*  f0ab794:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0ab798:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0ab79c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0ab7a0:	016e5821 */ 	addu	$t3,$t3,$t6
/*  f0ab7a4:	8d6b0368 */ 	lw	$t3,0x368($t3)
/*  f0ab7a8:	01e9c021 */ 	addu	$t8,$t7,$t1
/*  f0ab7ac:	5960003e */ 	blezl	$t3,.L0f0ab8a8
/*  f0ab7b0:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f0ab7b4:	8f19001c */ 	lw	$t9,0x1c($t8)
/*  f0ab7b8:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0ab7bc:	01804825 */ 	or	$t1,$t4,$zero
/*  f0ab7c0:	93220010 */ 	lbu	$v0,0x10($t9)
/*  f0ab7c4:	25f8fffe */ 	addiu	$t8,$t7,-2
/*  f0ab7c8:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f0ab7cc:	55c00036 */ 	bnezl	$t6,.L0f0ab8a8
/*  f0ab7d0:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f0ab7d4:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f0ab7d8:	8fae0108 */ 	lw	$t6,0x108($sp)
/*  f0ab7dc:	afb80054 */ 	sw	$t8,0x54($sp)
/*  f0ab7e0:	8fb8010c */ 	lw	$t8,0x10c($sp)
/*  f0ab7e4:	032e3023 */ 	subu	$a2,$t9,$t6
/*  f0ab7e8:	30590002 */ 	andi	$t9,$v0,0x2
/*  f0ab7ec:	254d005c */ 	addiu	$t5,$t2,0x5c
/*  f0ab7f0:	1320000d */ 	beqz	$t9,.L0f0ab828
/*  f0ab7f4:	01f83821 */ 	addu	$a3,$t7,$t8
/*  f0ab7f8:	8d180228 */ 	lw	$t8,0x228($t0)
/*  f0ab7fc:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0ab800:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f0ab804:	1b000003 */ 	blez	$t8,.L0f0ab814
/*  f0ab808:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f0ab80c:	8d190220 */ 	lw	$t9,0x220($t0)
/*  f0ab810:	01994821 */ 	addu	$t1,$t4,$t9
.L0f0ab814:
/*  f0ab814:	8c6e0228 */ 	lw	$t6,0x228($v1)
/*  f0ab818:	59c00004 */ 	blezl	$t6,.L0f0ab82c
/*  f0ab81c:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f0ab820:	8c6f0220 */ 	lw	$t7,0x220($v1)
/*  f0ab824:	012f4821 */ 	addu	$t1,$t1,$t7
.L0f0ab828:
/*  f0ab828:	8fb80128 */ 	lw	$t8,0x128($sp)
.L0f0ab82c:
/*  f0ab82c:	3c190040 */ 	lui	$t9,0x40
/*  f0ab830:	3c0e00ff */ 	lui	$t6,0xff
/*  f0ab834:	35cec040 */ 	ori	$t6,$t6,0xc040
/*  f0ab838:	37393080 */ 	ori	$t9,$t9,0x3080
/*  f0ab83c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0ab840:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f0ab844:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0ab848:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f0ab84c:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ab850:	8fa50100 */ 	lw	$a1,0x100($sp)
/*  f0ab854:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ab858:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0ab85c:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0ab860:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0ab864:	afa9009c */ 	sw	$t1,0x9c($sp)
/*  f0ab868:	0fc2a7f0 */ 	jal	func0f0a9fc0
/*  f0ab86c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ab870:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f0ab874:	3c0e00ff */ 	lui	$t6,0xff
/*  f0ab878:	35cec0a0 */ 	ori	$t6,$t6,0xc0a0
/*  f0ab87c:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0ab880:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ab884:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0ab888:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ab88c:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f0ab890:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0ab894:	00003825 */ 	or	$a3,$zero,$zero
/*  f0ab898:	0fc2a74b */ 	jal	func0f0a9d2c
/*  f0ab89c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ab8a0:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0ab8a4:	8faf005c */ 	lw	$t7,0x5c($sp)
.L0f0ab8a8:
/*  f0ab8a8:	24010023 */ 	addiu	$at,$zero,0x23
/*  f0ab8ac:	24090e10 */ 	addiu	$t1,$zero,0xe10
/*  f0ab8b0:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f0ab8b4:	3c03800a */ 	lui	$v1,0x800a
/*  f0ab8b8:	1701007c */ 	bne	$t8,$at,.L0f0abaac
/*  f0ab8bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab8c0:	8c63a41c */ 	lw	$v1,-0x5be4($v1)
/*  f0ab8c4:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f0ab8c8:	8faf010c */ 	lw	$t7,0x10c($sp)
/*  f0ab8cc:	0069001a */ 	div	$zero,$v1,$t1
/*  f0ab8d0:	0000c812 */ 	mflo	$t9
/*  f0ab8d4:	afb9005c */ 	sw	$t9,0x5c($sp)
/*  f0ab8d8:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0ab8dc:	8fae0108 */ 	lw	$t6,0x108($sp)
/*  f0ab8e0:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f0ab8e4:	afb80044 */ 	sw	$t8,0x44($sp)
/*  f0ab8e8:	15200002 */ 	bnez	$t1,.L0f0ab8f4
/*  f0ab8ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab8f0:	0007000d */ 	break	0x7
.L0f0ab8f4:
/*  f0ab8f4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ab8f8:	15210004 */ 	bne	$t1,$at,.L0f0ab90c
/*  f0ab8fc:	3c018000 */ 	lui	$at,0x8000
/*  f0ab900:	14610002 */ 	bne	$v1,$at,.L0f0ab90c
/*  f0ab904:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab908:	0006000d */ 	break	0x6
.L0f0ab90c:
/*  f0ab90c:	032e7823 */ 	subu	$t7,$t9,$t6
/*  f0ab910:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*  f0ab914:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f0ab918:	afb80060 */ 	sw	$t8,0x60($sp)
/*  f0ab91c:	5b20002e */ 	blezl	$t9,.L0f0ab9d8
/*  f0ab920:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f0ab924:	03290019 */ 	multu	$t9,$t1
/*  f0ab928:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0ab92c:	03203025 */ 	or	$a2,$t9,$zero
/*  f0ab930:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0ab934:	24a5c18c */ 	addiu	$a1,$a1,-15988
/*  f0ab938:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f0ab93c:	00007012 */ 	mflo	$t6
/*  f0ab940:	006e1023 */ 	subu	$v0,$v1,$t6
/*  f0ab944:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab948:	0048001a */ 	div	$zero,$v0,$t0
/*  f0ab94c:	00003812 */ 	mflo	$a3
/*  f0ab950:	15000002 */ 	bnez	$t0,.L0f0ab95c
/*  f0ab954:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab958:	0007000d */ 	break	0x7
.L0f0ab95c:
/*  f0ab95c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ab960:	15010004 */ 	bne	$t0,$at,.L0f0ab974
/*  f0ab964:	3c018000 */ 	lui	$at,0x8000
/*  f0ab968:	14410002 */ 	bne	$v0,$at,.L0f0ab974
/*  f0ab96c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab970:	0006000d */ 	break	0x6
.L0f0ab974:
/*  f0ab974:	00e80019 */ 	multu	$a3,$t0
/*  f0ab978:	00007812 */ 	mflo	$t7
/*  f0ab97c:	004fc023 */ 	subu	$t8,$v0,$t7
/*  f0ab980:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0ab984:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0ab988:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0ab98c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0ab990:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0ab994:	0328001a */ 	div	$zero,$t9,$t0
/*  f0ab998:	00007012 */ 	mflo	$t6
/*  f0ab99c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ab9a0:	15000002 */ 	bnez	$t0,.L0f0ab9ac
/*  f0ab9a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab9a8:	0007000d */ 	break	0x7
.L0f0ab9ac:
/*  f0ab9ac:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ab9b0:	15010004 */ 	bne	$t0,$at,.L0f0ab9c4
/*  f0ab9b4:	3c018000 */ 	lui	$at,0x8000
/*  f0ab9b8:	17210002 */ 	bne	$t9,$at,.L0f0ab9c4
/*  f0ab9bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab9c0:	0006000d */ 	break	0x6
.L0f0ab9c4:
/*  f0ab9c4:	0c004dad */ 	jal	sprintf
/*  f0ab9c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab9cc:	1000002b */ 	beqz	$zero,.L0f0aba7c
/*  f0ab9d0:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f0ab9d4:	8faf005c */ 	lw	$t7,0x5c($sp)
.L0f0ab9d8:
/*  f0ab9d8:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0ab9dc:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0ab9e0:	01e90019 */ 	multu	$t7,$t1
/*  f0ab9e4:	24a5c19c */ 	addiu	$a1,$a1,-15972
/*  f0ab9e8:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f0ab9ec:	0000c012 */ 	mflo	$t8
/*  f0ab9f0:	00781023 */ 	subu	$v0,$v1,$t8
/*  f0ab9f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ab9f8:	0048001a */ 	div	$zero,$v0,$t0
/*  f0ab9fc:	00003012 */ 	mflo	$a2
/*  f0aba00:	15000002 */ 	bnez	$t0,.L0f0aba0c
/*  f0aba04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aba08:	0007000d */ 	break	0x7
.L0f0aba0c:
/*  f0aba0c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0aba10:	15010004 */ 	bne	$t0,$at,.L0f0aba24
/*  f0aba14:	3c018000 */ 	lui	$at,0x8000
/*  f0aba18:	14410002 */ 	bne	$v0,$at,.L0f0aba24
/*  f0aba1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aba20:	0006000d */ 	break	0x6
.L0f0aba24:
/*  f0aba24:	00c80019 */ 	multu	$a2,$t0
/*  f0aba28:	0000c812 */ 	mflo	$t9
/*  f0aba2c:	00597023 */ 	subu	$t6,$v0,$t9
/*  f0aba30:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0aba34:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0aba38:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0aba3c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0aba40:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0aba44:	01e8001a */ 	div	$zero,$t7,$t0
/*  f0aba48:	00003812 */ 	mflo	$a3
/*  f0aba4c:	15000002 */ 	bnez	$t0,.L0f0aba58
/*  f0aba50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aba54:	0007000d */ 	break	0x7
.L0f0aba58:
/*  f0aba58:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0aba5c:	15010004 */ 	bne	$t0,$at,.L0f0aba70
/*  f0aba60:	3c018000 */ 	lui	$at,0x8000
/*  f0aba64:	15e10002 */ 	bne	$t7,$at,.L0f0aba70
/*  f0aba68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aba6c:	0006000d */ 	break	0x6
.L0f0aba70:
/*  f0aba70:	0c004dad */ 	jal	sprintf
/*  f0aba74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0aba78:	8fa60044 */ 	lw	$a2,0x44($sp)
.L0f0aba7c:
/*  f0aba7c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0aba80:	3c1900ff */ 	lui	$t9,0xff
/*  f0aba84:	3739c0a0 */ 	ori	$t9,$t9,0xc0a0
/*  f0aba88:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0aba8c:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0aba90:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0aba94:	00003825 */ 	or	$a3,$zero,$zero
/*  f0aba98:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0aba9c:	24c6fffe */ 	addiu	$a2,$a2,-2
/*  f0abaa0:	0fc2a6da */ 	jal	func0f0a9b68
/*  f0abaa4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0abaa8:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0abaac:
/*  f0abaac:	0fc54de0 */ 	jal	func0f153780
/*  f0abab0:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0abab4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0abab8:	3c018008 */ 	lui	$at,0x8008
/*  f0ababc:	ac2efac0 */ 	sw	$t6,-0x540($at)
.L0f0abac0:
/*  f0abac0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0abac4:	27bd0130 */ 	addiu	$sp,$sp,0x130
/*  f0abac8:	03e00008 */ 	jr	$ra
/*  f0abacc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0abad0
/*  f0abad0:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0abad4:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0abad8:	8c6e045c */ 	lw	$t6,0x45c($v1)
/*  f0abadc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0abae0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0abae4:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f0abae8:	29e14651 */ 	slti	$at,$t7,0x4651
/*  f0abaec:	14200003 */ 	bnez	$at,.L0f0abafc
/*  f0abaf0:	ac6f045c */ 	sw	$t7,0x45c($v1)
/*  f0abaf4:	24194650 */ 	addiu	$t9,$zero,0x4650
/*  f0abaf8:	ac79045c */ 	sw	$t9,0x45c($v1)
.L0f0abafc:
/*  f0abafc:	8c680464 */ 	lw	$t0,0x464($v1)
/*  f0abb00:	5500001b */ 	bnezl	$t0,.L0f0abb70
/*  f0abb04:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0abb08:	0fc5ae15 */ 	jal	func0f16b854
/*  f0abb0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abb10:	10400003 */ 	beqz	$v0,.L0f0abb20
/*  f0abb14:	3c048009 */ 	lui	$a0,0x8009
/*  f0abb18:	10000002 */ 	beqz	$zero,.L0f0abb24
/*  f0abb1c:	240202ad */ 	addiu	$v0,$zero,0x2ad
.L0f0abb20:
/*  f0abb20:	240205c9 */ 	addiu	$v0,$zero,0x5c9
.L0f0abb24:
/*  f0abb24:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0abb28:	44812000 */ 	mtc1	$at,$f4
/*  f0abb2c:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0abb30:	00054c03 */ 	sra	$t1,$a1,0x10
/*  f0abb34:	240affff */ 	addiu	$t2,$zero,-1
/*  f0abb38:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0abb3c:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0abb40:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0abb44:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0abb48:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0abb4c:	01202825 */ 	or	$a1,$t1,$zero
/*  f0abb50:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0abb54:	00003025 */ 	or	$a2,$zero,$zero
/*  f0abb58:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0abb5c:	0c004241 */ 	jal	func00010904
/*  f0abb60:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0abb64:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0abb68:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0abb6c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0abb70:
/*  f0abb70:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0abb74:	ac6d0464 */ 	sw	$t5,0x464($v1)
/*  f0abb78:	03e00008 */ 	jr	$ra
/*  f0abb7c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f0abb80
/*  f0abb80:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0abb84:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0abb88:	8c4e045c */ 	lw	$t6,0x45c($v0)
/*  f0abb8c:	01c47823 */ 	subu	$t7,$t6,$a0
/*  f0abb90:	1de00003 */ 	bgtz	$t7,.L0f0abba0
/*  f0abb94:	ac4f045c */ 	sw	$t7,0x45c($v0)
/*  f0abb98:	ac40045c */ 	sw	$zero,0x45c($v0)
/*  f0abb9c:	ac400464 */ 	sw	$zero,0x464($v0)
.L0f0abba0:
/*  f0abba0:	03e00008 */ 	jr	$ra
/*  f0abba4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0abba8
/*  f0abba8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0abbac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0abbb0:	0fc5ae15 */ 	jal	func0f16b854
/*  f0abbb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abbb8:	10400005 */ 	beqz	$v0,.L0f0abbd0
/*  f0abbbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abbc0:	0fc2aee0 */ 	jal	func0f0abb80
/*  f0abbc4:	240404b0 */ 	addiu	$a0,$zero,0x4b0
/*  f0abbc8:	10000004 */ 	beqz	$zero,.L0f0abbdc
/*  f0abbcc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0abbd0:
/*  f0abbd0:	0fc2aeb4 */ 	jal	func0f0abad0
/*  f0abbd4:	24040258 */ 	addiu	$a0,$zero,0x258
/*  f0abbd8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0abbdc:
/*  f0abbdc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0abbe0:	03e00008 */ 	jr	$ra
/*  f0abbe4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0abbe8
/*  f0abbe8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0abbec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0abbf0:	0fc5ae15 */ 	jal	func0f16b854
/*  f0abbf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abbf8:	10400005 */ 	beqz	$v0,.L0f0abc10
/*  f0abbfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abc00:	0fc2aeb4 */ 	jal	func0f0abad0
/*  f0abc04:	240404b0 */ 	addiu	$a0,$zero,0x4b0
/*  f0abc08:	10000004 */ 	beqz	$zero,.L0f0abc1c
/*  f0abc0c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0abc10:
/*  f0abc10:	0fc2aee0 */ 	jal	func0f0abb80
/*  f0abc14:	24040258 */ 	addiu	$a0,$zero,0x258
/*  f0abc18:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0abc1c:
/*  f0abc1c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0abc20:	03e00008 */ 	jr	$ra
/*  f0abc24:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0abc28
/*  f0abc28:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0abc2c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0abc30:	8c6e0468 */ 	lw	$t6,0x468($v1)
/*  f0abc34:	11c0000d */ 	beqz	$t6,.L0f0abc6c
/*  f0abc38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abc3c:	8c62045c */ 	lw	$v0,0x45c($v1)
/*  f0abc40:	1840000a */ 	blez	$v0,.L0f0abc6c
/*  f0abc44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abc48:	8c6f04cc */ 	lw	$t7,0x4cc($v1)
/*  f0abc4c:	15e00007 */ 	bnez	$t7,.L0f0abc6c
/*  f0abc50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abc54:	8c780038 */ 	lw	$t8,0x38($v1)
/*  f0abc58:	0058c823 */ 	subu	$t9,$v0,$t8
/*  f0abc5c:	1f200003 */ 	bgtz	$t9,.L0f0abc6c
/*  f0abc60:	ac79045c */ 	sw	$t9,0x45c($v1)
/*  f0abc64:	ac60045c */ 	sw	$zero,0x45c($v1)
/*  f0abc68:	ac600464 */ 	sw	$zero,0x464($v1)
.L0f0abc6c:
/*  f0abc6c:	03e00008 */ 	jr	$ra
/*  f0abc70:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0abc74
/*  f0abc74:	10a00008 */ 	beqz	$a1,.L0f0abc98
/*  f0abc78:	3c02800a */ 	lui	$v0,0x800a
/*  f0abc7c:	3c02800a */ 	lui	$v0,0x800a
/*  f0abc80:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0abc84:	00807827 */ 	nor	$t7,$a0,$zero
/*  f0abc88:	8c4e17a4 */ 	lw	$t6,0x17a4($v0)
/*  f0abc8c:	01cfc024 */ 	and	$t8,$t6,$t7
/*  f0abc90:	03e00008 */ 	jr	$ra
/*  f0abc94:	ac5817a4 */ 	sw	$t8,0x17a4($v0)
.L0f0abc98:
/*  f0abc98:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0abc9c:	8c5917a4 */ 	lw	$t9,0x17a4($v0)
/*  f0abca0:	03244025 */ 	or	$t0,$t9,$a0
/*  f0abca4:	ac4817a4 */ 	sw	$t0,0x17a4($v0)
/*  f0abca8:	03e00008 */ 	jr	$ra
/*  f0abcac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0abcb0
/*  f0abcb0:	3c02800a */ 	lui	$v0,0x800a
/*  f0abcb4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0abcb8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0abcbc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0abcc0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0abcc4:	8c4e17a4 */ 	lw	$t6,0x17a4($v0)
/*  f0abcc8:	00808025 */ 	or	$s0,$a0,$zero
/*  f0abccc:	15c0000c */ 	bnez	$t6,.L0f0abd00
/*  f0abcd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abcd4:	8c4f192c */ 	lw	$t7,0x192c($v0)
/*  f0abcd8:	15e00009 */ 	bnez	$t7,.L0f0abd00
/*  f0abcdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abce0:	0fc2c7d6 */ 	jal	func0f0b1f58
/*  f0abce4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abce8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0abcec:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0abcf0:	0fc37292 */ 	jal	func0f0dca48
/*  f0abcf4:	00403025 */ 	or	$a2,$v0,$zero
/*  f0abcf8:	10000008 */ 	beqz	$zero,.L0f0abd1c
/*  f0abcfc:	00408025 */ 	or	$s0,$v0,$zero
.L0f0abd00:
/*  f0abd00:	0fc2c7d6 */ 	jal	func0f0b1f58
/*  f0abd04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abd08:	02002025 */ 	or	$a0,$s0,$zero
/*  f0abd0c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0abd10:	0fc37292 */ 	jal	func0f0dca48
/*  f0abd14:	00403025 */ 	or	$a2,$v0,$zero
/*  f0abd18:	00408025 */ 	or	$s0,$v0,$zero
.L0f0abd1c:
/*  f0abd1c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0abd20:	02001025 */ 	or	$v0,$s0,$zero
/*  f0abd24:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0abd28:	03e00008 */ 	jr	$ra
/*  f0abd2c:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f0abd30
/*  f0abd30:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0abd34:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0abd38:	00021080 */ 	sll	$v0,$v0,0x2
/*  f0abd3c:	3c03800a */ 	lui	$v1,0x800a
/*  f0abd40:	00441021 */ 	addu	$v0,$v0,$a0
/*  f0abd44:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f0abd48:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0abd4c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0abd50:	00441021 */ 	addu	$v0,$v0,$a0
/*  f0abd54:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0abd58:	00021080 */ 	sll	$v0,$v0,0x2
/*  f0abd5c:	00808025 */ 	or	$s0,$a0,$zero
/*  f0abd60:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0abd64:	00622821 */ 	addu	$a1,$v1,$v0
/*  f0abd68:	90a40638 */ 	lbu	$a0,0x638($a1)
/*  f0abd6c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f0abd70:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f0abd74:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0abd78:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0abd7c:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f0abd80:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f0abd84:	00002025 */ 	or	$a0,$zero,$zero
/*  f0abd88:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f0abd8c:	240c0022 */ 	addiu	$t4,$zero,0x22
/*  f0abd90:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0abd94:	240affff */ 	addiu	$t2,$zero,-1
/*  f0abd98:	24691580 */ 	addiu	$t1,$v1,0x1580
/*  f0abd9c:	24a80638 */ 	addiu	$t0,$a1,0x638
.L0f0abda0:
/*  f0abda0:	16000002 */ 	bnez	$s0,.L0f0abdac
/*  f0abda4:	01247021 */ 	addu	$t6,$t1,$a0
/*  f0abda8:	a1ca0064 */ 	sb	$t2,0x64($t6)
.L0f0abdac:
/*  f0abdac:	10400013 */ 	beqz	$v0,.L0f0abdfc
/*  f0abdb0:	00042880 */ 	sll	$a1,$a0,0x2
/*  f0abdb4:	00453021 */ 	addu	$a2,$v0,$a1
/*  f0abdb8:	8cc3001c */ 	lw	$v1,0x1c($a2)
/*  f0abdbc:	50600010 */ 	beqzl	$v1,.L0f0abe00
/*  f0abdc0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0abdc4:	16000005 */ 	bnez	$s0,.L0f0abddc
/*  f0abdc8:	01053821 */ 	addu	$a3,$t0,$a1
/*  f0abdcc:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0abdd0:	0124c021 */ 	addu	$t8,$t1,$a0
/*  f0abdd4:	a30f0064 */ 	sb	$t7,0x64($t8)
/*  f0abdd8:	8cc3001c */ 	lw	$v1,0x1c($a2)
.L0f0abddc:
/*  f0abddc:	84790008 */ 	lh	$t9,0x8($v1)
/*  f0abde0:	160b0005 */ 	bne	$s0,$t3,.L0f0abdf8
/*  f0abde4:	acf90228 */ 	sw	$t9,0x228($a3)
/*  f0abde8:	910e0000 */ 	lbu	$t6,0x0($t0)
/*  f0abdec:	558e0003 */ 	bnel	$t4,$t6,.L0f0abdfc
/*  f0abdf0:	ace00220 */ 	sw	$zero,0x220($a3)
/*  f0abdf4:	ace00228 */ 	sw	$zero,0x228($a3)
.L0f0abdf8:
/*  f0abdf8:	ace00220 */ 	sw	$zero,0x220($a3)
.L0f0abdfc:
/*  f0abdfc:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f0abe00:
/*  f0abe00:	148dffe7 */ 	bne	$a0,$t5,.L0f0abda0
/*  f0abe04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abe08:	3c013f80 */ 	lui	$at,0x3f80
/*  f0abe0c:	44810000 */ 	mtc1	$at,$f0
/*  f0abe10:	2504078c */ 	addiu	$a0,$t0,0x78c
/*  f0abe14:	e5000254 */ 	swc1	$f0,0x254($t0)
/*  f0abe18:	e5000258 */ 	swc1	$f0,0x258($t0)
/*  f0abe1c:	e5000284 */ 	swc1	$f0,0x284($t0)
/*  f0abe20:	e5000288 */ 	swc1	$f0,0x288($t0)
/*  f0abe24:	812f0064 */ 	lb	$t7,0x64($t1)
/*  f0abe28:	05e2000c */ 	bltzl	$t7,.L0f0abe5c
/*  f0abe2c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0abe30:	0fc2a765 */ 	jal	func0f0a9d94
/*  f0abe34:	afa90024 */ 	sw	$t1,0x24($sp)
/*  f0abe38:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f0abe3c:	8fa90024 */ 	lw	$t1,0x24($sp)
/*  f0abe40:	17000004 */ 	bnez	$t8,.L0f0abe54
/*  f0abe44:	2524005c */ 	addiu	$a0,$t1,0x5c
/*  f0abe48:	0fc2a765 */ 	jal	func0f0a9d94
/*  f0abe4c:	afa90024 */ 	sw	$t1,0x24($sp)
/*  f0abe50:	8fa90024 */ 	lw	$t1,0x24($sp)
.L0f0abe54:
/*  f0abe54:	a1200069 */ 	sb	$zero,0x69($t1)
/*  f0abe58:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0abe5c:
/*  f0abe5c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0abe60:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0abe64:	03e00008 */ 	jr	$ra
/*  f0abe68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0abe6c:	00000000 */ 	sll	$zero,$zero,0x0
);
