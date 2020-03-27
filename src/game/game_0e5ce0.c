#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_005fd0.h"
#include "game/game_095320.h"
#include "game/game_0b3350.h"
#include "game/game_0e0770.h"
#include "game/game_0e5ce0.h"
#include "game/game_0f09f0.h"
#include "game/game_1531a0.h"
#include "game/game_167ae0.h"
#include "game/game_19aa80.h"
#include "game/game_19c990.h"
#include "game/lang.h"
#include "game/mplayer.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d520.h"
#include "lib/lib_13130.h"
#include "types.h"

const char var7f1adfa0[] = "brcol";
const char var7f1adfa8[] = "%d: ";
const char var7f1adfb0[] = "%s";
const char var7f1adfb4[] = "";
const char var7f1adfb8[] = "";
const char var7f1adfbc[] = "";
const char var7f1adfc0[] = "%d\n";
const char var7f1adfc4[] = "";
const char var7f1adfc8[] = "";
const char var7f1adfcc[] = "";
const char var7f1adfd0[] = "";
const char var7f1adfd4[] = "";
const char var7f1adfd8[] = "";
const char var7f1adfdc[] = "";
const char var7f1adfe0[] = "";
const char var7f1adfe4[] = "";
const char var7f1adfe8[] = "";
const char var7f1adfec[] = "";
const char var7f1adff0[] = "";
const char var7f1adff4[] = "";
const char var7f1adff8[] = "";
const char var7f1adffc[] = "";
const char var7f1ae000[] = "";
const char var7f1ae004[] = "";
const char var7f1ae008[] = "";
const char var7f1ae00c[] = "";
const char var7f1ae010[] = "";
const char var7f1ae014[] = "";
const char var7f1ae018[] = "";
const char var7f1ae01c[] = "";
const char var7f1ae020[] = "";
const char var7f1ae024[] = "";
const char var7f1ae028[] = "";
const char var7f1ae02c[] = "";
const char var7f1ae030[] = "";
const char var7f1ae034[] = "";
const char var7f1ae038[] = "";
const char var7f1ae03c[] = "";
const char var7f1ae040[] = "";
const char var7f1ae044[] = "";
const char var7f1ae048[] = "";
const char var7f1ae04c[] = "";
const char var7f1ae050[] = "";
const char var7f1ae054[] = "";
const char var7f1ae058[] = "";
const char var7f1ae05c[] = "";
const char var7f1ae060[] = "";
const char var7f1ae064[] = "";
const char var7f1ae068[] = "";
const char var7f1ae06c[] = "";
const char var7f1ae070[] = "";
const char var7f1ae074[] = "";
const char var7f1ae078[] = "";
const char var7f1ae07c[] = "";
const char var7f1ae080[] = "";
const char var7f1ae084[] = "";
const char var7f1ae088[] = "";
const char var7f1ae08c[] = "";
const char var7f1ae090[] = "";
const char var7f1ae094[] = "";
const char var7f1ae098[] = "";
const char var7f1ae09c[] = "";
const char var7f1ae0a0[] = "";
const char var7f1ae0a4[] = "";
const char var7f1ae0a8[] = "";
const char var7f1ae0ac[] = "";
const char var7f1ae0b0[] = "";
const char var7f1ae0b4[] = "";
const char var7f1ae0b8[] = "";
const char var7f1ae0bc[] = "";
const char var7f1ae0c0[] = "";
const char var7f1ae0c4[] = "";
const char var7f1ae0c8[] = "";
const char var7f1ae0cc[] = "";
const char var7f1ae0d0[] = "";
const char var7f1ae0d4[] = "";
const char var7f1ae0d8[] = "";
const char var7f1ae0dc[] = "";
const char var7f1ae0e0[] = "";
const char var7f1ae0e4[] = "";
const char var7f1ae0e8[] = "";
const char var7f1ae0ec[] = "";
const char var7f1ae0f0[] = "";
const char var7f1ae0f4[] = "";
const char var7f1ae0f8[] = "";
const char var7f1ae0fc[] = "";
const char var7f1ae100[] = "";
const char var7f1ae104[] = "";
const char var7f1ae108[] = "";
const char var7f1ae10c[] = "";
const char var7f1ae110[] = "";
const char var7f1ae114[] = "";
const char var7f1ae118[] = "";
const char var7f1ae11c[] = "";
const char var7f1ae120[] = "";
const char var7f1ae124[] = "";
const char var7f1ae128[] = "";
const char var7f1ae12c[] = "";
const char var7f1ae130[] = "";
const char var7f1ae134[] = "";
const char var7f1ae138[] = "";
const char var7f1ae13c[] = "";
const char var7f1ae140[] = "";
const char var7f1ae144[] = "";
const char var7f1ae148[] = "";
const char var7f1ae14c[] = "";
const char var7f1ae150[] = "";
const char var7f1ae154[] = "";
const char var7f1ae158[] = "";
const char var7f1ae15c[] = "";
const char var7f1ae160[] = "";
const char var7f1ae164[] = "";
const char var7f1ae168[] = "";
const char var7f1ae16c[] = "";
const char var7f1ae170[] = "";
const char var7f1ae174[] = "";
const char var7f1ae178[] = "";
const char var7f1ae17c[] = "";
const char var7f1ae180[] = "";
const char var7f1ae184[] = "";
const char var7f1ae188[] = "";
const char var7f1ae18c[] = "";
const char var7f1ae190[] = "";
const char var7f1ae194[] = "";
const char var7f1ae198[] = "";
const char var7f1ae19c[] = "";
const char var7f1ae1a0[] = "";
const char var7f1ae1a4[] = "";
const char var7f1ae1a8[] = "";
const char var7f1ae1ac[] = "";
const char var7f1ae1b0[] = "";
const char var7f1ae1b4[] = "";
const char var7f1ae1b8[] = "";
const char var7f1ae1bc[] = "";
const char var7f1ae1c0[] = "";
const char var7f1ae1c4[] = "";
const char var7f1ae1c8[] = "";
const char var7f1ae1cc[] = "";
const char var7f1ae1d0[] = "";
const char var7f1ae1d4[] = "";
const char var7f1ae1d8[] = "";
const char var7f1ae1dc[] = "";
const char var7f1ae1e0[] = "";
const char var7f1ae1e4[] = "";
const char var7f1ae1e8[] = "";
const char var7f1ae1ec[] = "";
const char var7f1ae1f0[] = "";
const char var7f1ae1f4[] = "";
const char var7f1ae1f8[] = "";
const char var7f1ae1fc[] = "";
const char var7f1ae200[] = "";
const char var7f1ae204[] = "";
const char var7f1ae208[] = "";
const char var7f1ae20c[] = "";
const char var7f1ae210[] = "";
const char var7f1ae214[] = "";
const char var7f1ae218[] = "";
const char var7f1ae21c[] = "";
const char var7f1ae220[] = "";
const char var7f1ae224[] = "";
const char var7f1ae228[] = "";
const char var7f1ae22c[] = "";
const char var7f1ae230[] = "";
const char var7f1ae234[] = "";
const char var7f1ae238[] = "";
const char var7f1ae23c[] = "";
const char var7f1ae240[] = "";
const char var7f1ae244[] = "";
const char var7f1ae248[] = "";
const char var7f1ae24c[] = "";
const char var7f1ae250[] = "";
const char var7f1ae254[] = "";
const char var7f1ae258[] = "";
const char var7f1ae25c[] = "";
const char var7f1ae260[] = "";
const char var7f1ae264[] = "";
const char var7f1ae268[] = "";
const char var7f1ae26c[] = "";
const char var7f1ae270[] = "";
const char var7f1ae274[] = "";
const char var7f1ae278[] = "";
const char var7f1ae27c[] = "";
const char var7f1ae280[] = "";
const char var7f1ae284[] = "";
const char var7f1ae288[] = "";
const char var7f1ae28c[] = "";
const char var7f1ae290[] = "";
const char var7f1ae294[] = "";
const char var7f1ae298[] = "";
const char var7f1ae29c[] = "";
const char var7f1ae2a0[] = "";
const char var7f1ae2a4[] = "";
const char var7f1ae2a8[] = "";
const char var7f1ae2ac[] = "";
const char var7f1ae2b0[] = "";
const char var7f1ae2b4[] = "";
const char var7f1ae2b8[] = "";
const char var7f1ae2bc[] = "";
const char var7f1ae2c0[] = "";
const char var7f1ae2c4[] = "";
const char var7f1ae2c8[] = "";
const char var7f1ae2cc[] = "";
const char var7f1ae2d0[] = "";
const char var7f1ae2d4[] = "";
const char var7f1ae2d8[] = "";
const char var7f1ae2dc[] = "";
const char var7f1ae2e0[] = "";
const char var7f1ae2e4[] = "";
const char var7f1ae2e8[] = "";
const char var7f1ae2ec[] = "";
const char var7f1ae2f0[] = "";
const char var7f1ae2f4[] = "";
const char var7f1ae2f8[] = "";
const char var7f1ae2fc[] = "";
const char var7f1ae300[] = "";
const char var7f1ae304[] = "";
const char var7f1ae308[] = "";
const char var7f1ae30c[] = "";
const char var7f1ae310[] = "";
const char var7f1ae314[] = "";
const char var7f1ae318[] = "";
const char var7f1ae31c[] = "";
const char var7f1ae320[] = "";
const char var7f1ae324[] = "";
const char var7f1ae328[] = "";
const char var7f1ae32c[] = "";
const char var7f1ae330[] = "";
const char var7f1ae334[] = "";
const char var7f1ae338[] = "";
const char var7f1ae33c[] = "";
const char var7f1ae340[] = "";
const char var7f1ae344[] = "";
const char var7f1ae348[] = "";
const char var7f1ae34c[] = "";
const char var7f1ae350[] = "";
const char var7f1ae354[] = "";
const char var7f1ae358[] = "";
const char var7f1ae35c[] = "";
const char var7f1ae360[] = "";
const char var7f1ae364[] = "";
const char var7f1ae368[] = "";
const char var7f1ae36c[] = "";
const char var7f1ae370[] = "";
const char var7f1ae374[] = "";
const char var7f1ae378[] = "";
const char var7f1ae37c[] = "";
const char var7f1ae380[] = "";
const char var7f1ae384[] = "";
const char var7f1ae388[] = "";
const char var7f1ae38c[] = "";
const char var7f1ae390[] = "";
const char var7f1ae394[] = "";
const char var7f1ae398[] = "";
const char var7f1ae39c[] = "";
const char var7f1ae3a0[] = "";
const char var7f1ae3a4[] = "";
const char var7f1ae3a8[] = "";
const char var7f1ae3ac[] = "";
const char var7f1ae3b0[] = "";
const char var7f1ae3b4[] = "";
const char var7f1ae3b8[] = "";
const char var7f1ae3bc[] = "";
const char var7f1ae3c0[] = "";
const char var7f1ae3c4[] = "";
const char var7f1ae3c8[] = "";
const char var7f1ae3cc[] = "";
const char var7f1ae3d0[] = "";
const char var7f1ae3d4[] = "";
const char var7f1ae3d8[] = "";
const char var7f1ae3dc[] = "";
const char var7f1ae3e0[] = "";
const char var7f1ae3e4[] = "";
const char var7f1ae3e8[] = "";
const char var7f1ae3ec[] = "";
const char var7f1ae3f0[] = "";
const char var7f1ae3f4[] = "";
const char var7f1ae3f8[] = "";
const char var7f1ae3fc[] = "";
const char var7f1ae400[] = "";
const char var7f1ae404[] = "";
const char var7f1ae408[] = "";
const char var7f1ae40c[] = "";
const char var7f1ae410[] = "";
const char var7f1ae414[] = "";
const char var7f1ae418[] = "";
const char var7f1ae41c[] = "";
const char var7f1ae420[] = "";
const char var7f1ae424[] = "";
const char var7f1ae428[] = "";
const char var7f1ae42c[] = "";
const char var7f1ae430[] = "";
const char var7f1ae434[] = "";
const char var7f1ae438[] = "";
const char var7f1ae43c[] = "";
const char var7f1ae440[] = "";
const char var7f1ae444[] = "";
const char var7f1ae448[] = "";
const char var7f1ae44c[] = "";
const char var7f1ae450[] = "";
const char var7f1ae454[] = "";
const char var7f1ae458[] = "";
const char var7f1ae45c[] = "";
const char var7f1ae460[] = "";
const char var7f1ae464[] = "";
const char var7f1ae468[] = "";
const char var7f1ae46c[] = "";
const char var7f1ae470[] = "";
const char var7f1ae474[] = "";
const char var7f1ae478[] = "";
const char var7f1ae47c[] = "";
const char var7f1ae480[] = "";
const char var7f1ae484[] = "";
const char var7f1ae488[] = "";
const char var7f1ae48c[] = "";
const char var7f1ae490[] = "";
const char var7f1ae494[] = "";
const char var7f1ae498[] = "";
const char var7f1ae49c[] = "";
const char var7f1ae4a0[] = "";
const char var7f1ae4a4[] = "";
const char var7f1ae4a8[] = "";
const char var7f1ae4ac[] = "";
const char var7f1ae4b0[] = "";
const char var7f1ae4b4[] = "";
const char var7f1ae4b8[] = "";
const char var7f1ae4bc[] = "";
const char var7f1ae4c0[] = "";
const char var7f1ae4c4[] = "";
const char var7f1ae4c8[] = "";
const char var7f1ae4cc[] = "";
const char var7f1ae4d0[] = "";
const char var7f1ae4d4[] = "";
const char var7f1ae4d8[] = "";
const char var7f1ae4dc[] = "";
const char var7f1ae4e0[] = "";
const char var7f1ae4e4[] = "";
const char var7f1ae4e8[] = "";
const char var7f1ae4ec[] = "";
const char var7f1ae4f0[] = "";
const char var7f1ae4f4[] = "";
const char var7f1ae4f8[] = "";
const char var7f1ae4fc[] = "";
const char var7f1ae500[] = "";
const char var7f1ae504[] = "";
const char var7f1ae508[] = "";
const char var7f1ae50c[] = "";
const char var7f1ae510[] = "";
const char var7f1ae514[] = "";
const char var7f1ae518[] = "";
const char var7f1ae51c[] = "";
const char var7f1ae520[] = "";
const char var7f1ae524[] = "";
const char var7f1ae528[] = "";
const char var7f1ae52c[] = "";
const char var7f1ae530[] = "";
const char var7f1ae534[] = "";
const char var7f1ae538[] = "";
const char var7f1ae53c[] = "";
const char var7f1ae540[] = "";
const char var7f1ae544[] = "";
const char var7f1ae548[] = "";
const char var7f1ae54c[] = "";
const char var7f1ae550[] = "";
const char var7f1ae554[] = "";
const char var7f1ae558[] = "";
const char var7f1ae55c[] = "";
const char var7f1ae560[] = "";
const char var7f1ae564[] = "";
const char var7f1ae568[] = "";
const char var7f1ae56c[] = "";
const char var7f1ae570[] = "";
const char var7f1ae574[] = "";
const char var7f1ae578[] = "";
const char var7f1ae57c[] = "";
const char var7f1ae580[] = "";
const char var7f1ae584[] = "";
const char var7f1ae588[] = "";
const char var7f1ae58c[] = "";
const char var7f1ae590[] = "";
const char var7f1ae594[] = "";
const char var7f1ae598[] = "";
const char var7f1ae59c[] = "";
const char var7f1ae5a0[] = "";
const char var7f1ae5a4[] = "";
const char var7f1ae5a8[] = "";
const char var7f1ae5ac[] = "";
const char var7f1ae5b0[] = "";
const char var7f1ae5b4[] = "";
const char var7f1ae5b8[] = "";
const char var7f1ae5bc[] = "";
const char var7f1ae5c0[] = "";
const char var7f1ae5c4[] = "";
const char var7f1ae5c8[] = "";
const char var7f1ae5cc[] = "";
const char var7f1ae5d0[] = "";
const char var7f1ae5d4[] = "";
const char var7f1ae5d8[] = "";
const char var7f1ae5dc[] = "";
const char var7f1ae5e0[] = "";
const char var7f1ae5e4[] = "";
const char var7f1ae5e8[] = "";
const char var7f1ae5ec[] = "";
const char var7f1ae5f0[] = "";
const char var7f1ae5f4[] = "";
const char var7f1ae5f8[] = "";
const char var7f1ae5fc[] = "";
const char var7f1ae600[] = "";
const char var7f1ae604[] = "";
const char var7f1ae608[] = "";
const char var7f1ae60c[] = "";
const char var7f1ae610[] = "";
const char var7f1ae614[] = "";
const char var7f1ae618[] = "";
const char var7f1ae61c[] = "";
const char var7f1ae620[] = "";
const char var7f1ae624[] = "";
const char var7f1ae628[] = "";
const char var7f1ae62c[] = "";
const char var7f1ae630[] = "";
const char var7f1ae634[] = "";
const char var7f1ae638[] = "";
const char var7f1ae63c[] = "";
const char var7f1ae640[] = "";
const char var7f1ae644[] = "";
const char var7f1ae648[] = "";
const char var7f1ae64c[] = "";
const char var7f1ae650[] = "";
const char var7f1ae654[] = "";
const char var7f1ae658[] = "";
const char var7f1ae65c[] = "";
const char var7f1ae660[] = "";
const char var7f1ae664[] = "";
const char var7f1ae668[] = "";
const char var7f1ae66c[] = "";
const char var7f1ae670[] = "";
const char var7f1ae674[] = "";
const char var7f1ae678[] = "";
const char var7f1ae67c[] = "";
const char var7f1ae680[] = "";
const char var7f1ae684[] = "";
const char var7f1ae688[] = "";
const char var7f1ae68c[] = "";
const char var7f1ae690[] = "";
const char var7f1ae694[] = "";
const char var7f1ae698[] = "";
const char var7f1ae69c[] = "";
const char var7f1ae6a0[] = "";
const char var7f1ae6a4[] = "";
const char var7f1ae6a8[] = "";
const char var7f1ae6ac[] = "";
const char var7f1ae6b0[] = "";
const char var7f1ae6b4[] = "";
const char var7f1ae6b8[] = "";
const char var7f1ae6bc[] = "";
const char var7f1ae6c0[] = "";
const char var7f1ae6c4[] = "";
const char var7f1ae6c8[] = "";
const char var7f1ae6cc[] = "";
const char var7f1ae6d0[] = "";
const char var7f1ae6d4[] = "";
const char var7f1ae6d8[] = "";
const char var7f1ae6dc[] = "";
const char var7f1ae6e0[] = "";
const char var7f1ae6e4[] = "";
const char var7f1ae6e8[] = "";
const char var7f1ae6ec[] = "";
const char var7f1ae6f0[] = "";
const char var7f1ae6f4[] = "";
const char var7f1ae6f8[] = "";
const char var7f1ae6fc[] = "";
const char var7f1ae700[] = "";
const char var7f1ae704[] = "";
const char var7f1ae708[] = "";
const char var7f1ae70c[] = "";
const char var7f1ae710[] = "";
const char var7f1ae714[] = "";
const char var7f1ae718[] = "";
const char var7f1ae71c[] = "";
const char var7f1ae720[] = "";
const char var7f1ae724[] = "";
const char var7f1ae728[] = "";
const char var7f1ae72c[] = "";
const char var7f1ae730[] = "";
const char var7f1ae734[] = "";
const char var7f1ae738[] = "";
const char var7f1ae73c[] = "";
const char var7f1ae740[] = "";
const char var7f1ae744[] = "";
const char var7f1ae748[] = "";
const char var7f1ae74c[] = "";
const char var7f1ae750[] = "";
const char var7f1ae754[] = "";
const char var7f1ae758[] = "";
const char var7f1ae75c[] = "";
const char var7f1ae760[] = "";
const char var7f1ae764[] = "";
const char var7f1ae768[] = "";
const char var7f1ae76c[] = "";
const char var7f1ae770[] = "";
const char var7f1ae774[] = "";
const char var7f1ae778[] = "";
const char var7f1ae77c[] = "";
const char var7f1ae780[] = "";
const char var7f1ae784[] = "";
const char var7f1ae788[] = "";
const char var7f1ae78c[] = "";
const char var7f1ae790[] = "";
const char var7f1ae794[] = "";
const char var7f1ae798[] = "";
const char var7f1ae79c[] = "";
const char var7f1ae7a0[] = "";
const char var7f1ae7a4[] = "";
const char var7f1ae7a8[] = "";
const char var7f1ae7ac[] = "";
const char var7f1ae7b0[] = "";
const char var7f1ae7b4[] = "";
const char var7f1ae7b8[] = "";
const char var7f1ae7bc[] = "";
const char var7f1ae7c0[] = "";
const char var7f1ae7c4[] = "";
const char var7f1ae7c8[] = "";
const char var7f1ae7cc[] = "";
const char var7f1ae7d0[] = "";
const char var7f1ae7d4[] = "";
const char var7f1ae7d8[] = "";
const char var7f1ae7dc[] = "";
const char var7f1ae7e0[] = "";
const char var7f1ae7e4[] = "";
const char var7f1ae7e8[] = "";
const char var7f1ae7ec[] = "";
const char var7f1ae7f0[] = "";
const char var7f1ae7f4[] = "";
const char var7f1ae7f8[] = "";
const char var7f1ae7fc[] = "";
const char var7f1ae800[] = "";
const char var7f1ae804[] = "";
const char var7f1ae808[] = "";
const char var7f1ae80c[] = "";
const char var7f1ae810[] = "";
const char var7f1ae814[] = "";
const char var7f1ae818[] = "";
const char var7f1ae81c[] = "";
const char var7f1ae820[] = "";
const char var7f1ae824[] = "";
const char var7f1ae828[] = "";
const char var7f1ae82c[] = "";
const char var7f1ae830[] = "";
const char var7f1ae834[] = "";
const char var7f1ae838[] = "";
const char var7f1ae83c[] = "";
const char var7f1ae840[] = "";
const char var7f1ae844[] = "";
const char var7f1ae848[] = "";
const char var7f1ae84c[] = "";
const char var7f1ae850[] = "";
const char var7f1ae854[] = "";
const char var7f1ae858[] = "";
const char var7f1ae85c[] = "";
const char var7f1ae860[] = "";
const char var7f1ae864[] = "";
const char var7f1ae868[] = "";
const char var7f1ae86c[] = "";
const char var7f1ae870[] = "";
const char var7f1ae874[] = "";
const char var7f1ae878[] = "";
const char var7f1ae87c[] = "";
const char var7f1ae880[] = "";
const char var7f1ae884[] = "";
const char var7f1ae888[] = "";
const char var7f1ae88c[] = "";
const char var7f1ae890[] = "";
const char var7f1ae894[] = "";
const char var7f1ae898[] = "";
const char var7f1ae89c[] = "";
const char var7f1ae8a0[] = "";
const char var7f1ae8a4[] = "";
const char var7f1ae8a8[] = "";
const char var7f1ae8ac[] = "";
const char var7f1ae8b0[] = "";
const char var7f1ae8b4[] = "";
const char var7f1ae8b8[] = "";
const char var7f1ae8bc[] = "";
const char var7f1ae8c0[] = "";
const char var7f1ae8c4[] = "";
const char var7f1ae8c8[] = "";
const char var7f1ae8cc[] = "";
const char var7f1ae8d0[] = "";
const char var7f1ae8d4[] = "";
const char var7f1ae8d8[] = "";
const char var7f1ae8dc[] = "";
const char var7f1ae8e0[] = "";
const char var7f1ae8e4[] = "";
const char var7f1ae8e8[] = "";
const char var7f1ae8ec[] = "";
const char var7f1ae8f0[] = "";
const char var7f1ae8f4[] = "";
const char var7f1ae8f8[] = "";
const char var7f1ae8fc[] = "";
const char var7f1ae900[] = "";
const char var7f1ae904[] = "";
const char var7f1ae908[] = "";
const char var7f1ae90c[] = "";
const char var7f1ae910[] = "";
const char var7f1ae914[] = "";
const char var7f1ae918[] = "";
const char var7f1ae91c[] = "";
const char var7f1ae920[] = "";
const char var7f1ae924[] = "";
const char var7f1ae928[] = "";
const char var7f1ae92c[] = "";
const char var7f1ae930[] = "";
const char var7f1ae934[] = "";
const char var7f1ae938[] = "";
const char var7f1ae93c[] = "";
const char var7f1ae940[] = "";
const char var7f1ae944[] = "";
const char var7f1ae948[] = "";
const char var7f1ae94c[] = "";
const char var7f1ae950[] = "";
const char var7f1ae954[] = "";
const char var7f1ae958[] = "";
const char var7f1ae95c[] = "";
const char var7f1ae960[] = "";
const char var7f1ae964[] = "";
const char var7f1ae968[] = "";
const char var7f1ae96c[] = "";
const char var7f1ae970[] = "";
const char var7f1ae974[] = "";
const char var7f1ae978[] = "";
const char var7f1ae97c[] = "";
const char var7f1ae980[] = "";
const char var7f1ae984[] = "";
const char var7f1ae988[] = "";
const char var7f1ae98c[] = "";
const char var7f1ae990[] = "";
const char var7f1ae994[] = "";
const char var7f1ae998[] = "";
const char var7f1ae99c[] = "";
const char var7f1ae9a0[] = "";
const char var7f1ae9a4[] = "";
const char var7f1ae9a8[] = "";
const char var7f1ae9ac[] = "";
const char var7f1ae9b0[] = "";
const char var7f1ae9b4[] = "";
const char var7f1ae9b8[] = "";
const char var7f1ae9bc[] = "";
const char var7f1ae9c0[] = "";
const char var7f1ae9c4[] = "";
const char var7f1ae9c8[] = "";
const char var7f1ae9cc[] = "";
const char var7f1ae9d0[] = "";
const char var7f1ae9d4[] = "";
const char var7f1ae9d8[] = "";
const char var7f1ae9dc[] = "";
const char var7f1ae9e0[] = "";
const char var7f1ae9e4[] = "";
const char var7f1ae9e8[] = "";
const char var7f1ae9ec[] = "";
const char var7f1ae9f0[] = "";
const char var7f1ae9f4[] = "";
const char var7f1ae9f8[] = "";
const char var7f1ae9fc[] = "";
const char var7f1aea00[] = "";
const char var7f1aea04[] = "";
const char var7f1aea08[] = "";
const char var7f1aea0c[] = "";
const char var7f1aea10[] = "";
const char var7f1aea14[] = "";
const char var7f1aea18[] = "";
const char var7f1aea1c[] = "";
const char var7f1aea20[] = "";
const char var7f1aea24[] = "";
const char var7f1aea28[] = "";
const char var7f1aea2c[] = "";
const char var7f1aea30[] = "";
const char var7f1aea34[] = "";
const char var7f1aea38[] = "";
const char var7f1aea3c[] = "";
const char var7f1aea40[] = "";
const char var7f1aea44[] = "";
const char var7f1aea48[] = "";
const char var7f1aea4c[] = "";
const char var7f1aea50[] = "";
const char var7f1aea54[] = "";
const char var7f1aea58[] = "";
const char var7f1aea5c[] = "";
const char var7f1aea60[] = "";
const char var7f1aea64[] = "";
const char var7f1aea68[] = "";
const char var7f1aea6c[] = "";
const char var7f1aea70[] = "";
const char var7f1aea74[] = "";
const char var7f1aea78[] = "";
const char var7f1aea7c[] = "";
const char var7f1aea80[] = "";
const char var7f1aea84[] = "";
const char var7f1aea88[] = "";
const char var7f1aea8c[] = "";
const char var7f1aea90[] = "";
const char var7f1aea94[] = "";
const char var7f1aea98[] = "";
const char var7f1aea9c[] = "";
const char var7f1aeaa0[] = "";
const char var7f1aeaa4[] = "";
const char var7f1aeaa8[] = "";
const char var7f1aeaac[] = "";
const char var7f1aeab0[] = "";
const char var7f1aeab4[] = "";
const char var7f1aeab8[] = "";
const char var7f1aeabc[] = "";
const char var7f1aeac0[] = "";
const char var7f1aeac4[] = "";
const char var7f1aeac8[] = "";
const char var7f1aeacc[] = "";
const char var7f1aead0[] = "";
const char var7f1aead4[] = "";
const char var7f1aead8[] = "";
const char var7f1aeadc[] = "";
const char var7f1aeae0[] = "";
const char var7f1aeae4[] = "";
const char var7f1aeae8[] = "";
const char var7f1aeaec[] = "";
const char var7f1aeaf0[] = "";
const char var7f1aeaf4[] = "";
const char var7f1aeaf8[] = "";
const char var7f1aeafc[] = "";
const char var7f1aeb00[] = "";
const char var7f1aeb04[] = "";
const char var7f1aeb08[] = "";
const char var7f1aeb0c[] = "";
const char var7f1aeb10[] = "";
const char var7f1aeb14[] = "";
const char var7f1aeb18[] = "";
const char var7f1aeb1c[] = "";
const char var7f1aeb20[] = "";
const char var7f1aeb24[] = "";
const char var7f1aeb28[] = "";
const char var7f1aeb2c[] = "";
const char var7f1aeb30[] = "";
const char var7f1aeb34[] = "";
const char var7f1aeb38[] = "";
const char var7f1aeb3c[] = "";
const char var7f1aeb40[] = "";
const char var7f1aeb44[] = "";
const char var7f1aeb48[] = "";
const char var7f1aeb4c[] = "";
const char var7f1aeb50[] = "";
const char var7f1aeb54[] = "";
const char var7f1aeb58[] = "";
const char var7f1aeb5c[] = "";
const char var7f1aeb60[] = "";
const char var7f1aeb64[] = "";
const char var7f1aeb68[] = "";
const char var7f1aeb6c[] = "";
const char var7f1aeb70[] = "";
const char var7f1aeb74[] = "";
const char var7f1aeb78[] = "";
const char var7f1aeb7c[] = "";
const char var7f1aeb80[] = "";
const char var7f1aeb84[] = "";
const char var7f1aeb88[] = "";
const char var7f1aeb8c[] = "";
const char var7f1aeb90[] = "";
const char var7f1aeb94[] = "";
const char var7f1aeb98[] = "";
const char var7f1aeb9c[] = "";
const char var7f1aeba0[] = "";
const char var7f1aeba4[] = "";
const char var7f1aeba8[] = "";
const char var7f1aebac[] = "";
const char var7f1aebb0[] = "";
const char var7f1aebb4[] = "";
const char var7f1aebb8[] = "";
const char var7f1aebbc[] = "";
const char var7f1aebc0[] = "";
const char var7f1aebc4[] = "";
const char var7f1aebc8[] = "";
const char var7f1aebcc[] = "";
const char var7f1aebd0[] = "";
const char var7f1aebd4[] = "";
const char var7f1aebd8[] = "";
const char var7f1aebdc[] = "";
const char var7f1aebe0[] = "";
const char var7f1aebe4[] = "";
const char var7f1aebe8[] = "";
const char var7f1aebec[] = "";
const char var7f1aebf0[] = "";
const char var7f1aebf4[] = "";
const char var7f1aebf8[] = "";
const char var7f1aebfc[] = "";
const char var7f1aec00[] = "";
const char var7f1aec04[] = "";
const char var7f1aec08[] = "";
const char var7f1aec0c[] = "";
const char var7f1aec10[] = "";
const char var7f1aec14[] = "";
const char var7f1aec18[] = "";
const char var7f1aec1c[] = "";
const char var7f1aec20[] = "";
const char var7f1aec24[] = "";
const char var7f1aec28[] = "";
const char var7f1aec2c[] = "";
const char var7f1aec30[] = "";
const char var7f1aec34[] = "";
const char var7f1aec38[] = "";
const char var7f1aec3c[] = "";
const char var7f1aec40[] = "";
const char var7f1aec44[] = "";
const char var7f1aec48[] = "";
const char var7f1aec4c[] = "";
const char var7f1aec50[] = "";
const char var7f1aec54[] = "";
const char var7f1aec58[] = "";
const char var7f1aec5c[] = "";
const char var7f1aec60[] = "";
const char var7f1aec64[] = "";
const char var7f1aec68[] = "";
const char var7f1aec6c[] = "";
const char var7f1aec70[] = "";
const char var7f1aec74[] = "";
const char var7f1aec78[] = "";
const char var7f1aec7c[] = "";
const char var7f1aec80[] = "";
const char var7f1aec84[] = "";
const char var7f1aec88[] = "";
const char var7f1aec8c[] = "";
const char var7f1aec90[] = "";
const char var7f1aec94[] = "";
const char var7f1aec98[] = "";
const char var7f1aec9c[] = "";
const char var7f1aeca0[] = "";
const char var7f1aeca4[] = "";
const char var7f1aeca8[] = "";
const char var7f1aecac[] = "";
const char var7f1aecb0[] = "";
const char var7f1aecb4[] = "";
const char var7f1aecb8[] = "";
const char var7f1aecbc[] = "";
const char var7f1aecc0[] = "";
const char var7f1aecc4[] = "";
const char var7f1aecc8[] = "";
const char var7f1aeccc[] = "";
const char var7f1aecd0[] = "";
const char var7f1aecd4[] = "";
const char var7f1aecd8[] = "";
const char var7f1aecdc[] = "";
const char var7f1aece0[] = "";
const char var7f1aece4[] = "";
const char var7f1aece8[] = "";
const char var7f1aecec[] = "";
const char var7f1aecf0[] = "";
const char var7f1aecf4[] = "";
const char var7f1aecf8[] = "";
const char var7f1aecfc[] = "";
const char var7f1aed00[] = "";
const char var7f1aed04[] = "";
const char var7f1aed08[] = "";
const char var7f1aed0c[] = "";
const char var7f1aed10[] = "";
const char var7f1aed14[] = "";
const char var7f1aed18[] = "";
const char var7f1aed1c[] = "";
const char var7f1aed20[] = "";
const char var7f1aed24[] = "";
const char var7f1aed28[] = "";
const char var7f1aed2c[] = "";
const char var7f1aed30[] = "";
const char var7f1aed34[] = "";
const char var7f1aed38[] = "";
const char var7f1aed3c[] = "";
const char var7f1aed40[] = "";
const char var7f1aed44[] = "";
const char var7f1aed48[] = "";
const char var7f1aed4c[] = "";
const char var7f1aed50[] = "";
const char var7f1aed54[] = "";
const char var7f1aed58[] = "";
const char var7f1aed5c[] = "";
const char var7f1aed60[] = "";
const char var7f1aed64[] = "";
const char var7f1aed68[] = "";
const char var7f1aed6c[] = "";
const char var7f1aed70[] = "";
const char var7f1aed74[] = "";
const char var7f1aed78[] = "";
const char var7f1aed7c[] = "";
const char var7f1aed80[] = "";
const char var7f1aed84[] = "";
const char var7f1aed88[] = "";
const char var7f1aed8c[] = "";
const char var7f1aed90[] = "";
const char var7f1aed94[] = "";
const char var7f1aed98[] = "";
const char var7f1aed9c[] = "";
const char var7f1aeda0[] = "";
const char var7f1aeda4[] = "";
const char var7f1aeda8[] = "";
const char var7f1aedac[] = "";
const char var7f1aedb0[] = "";
const char var7f1aedb4[] = "";
const char var7f1aedb8[] = "";
const char var7f1aedbc[] = "";
const char var7f1aedc0[] = "";
const char var7f1aedc4[] = "";
const char var7f1aedc8[] = "";
const char var7f1aedcc[] = "";
const char var7f1aedd0[] = "";
const char var7f1aedd4[] = "";
const char var7f1aedd8[] = "";
const char var7f1aeddc[] = "";
const char var7f1aede0[] = "";
const char var7f1aede4[] = "";
const char var7f1aede8[] = "";
const char var7f1aedec[] = "";
const char var7f1aedf0[] = "";
const char var7f1aedf4[] = "";
const char var7f1aedf8[] = "";
const char var7f1aedfc[] = "";
const char var7f1aee00[] = "";
const char var7f1aee04[] = "";
const char var7f1aee08[] = "";
const char var7f1aee0c[] = "";
const char var7f1aee10[] = "";
const char var7f1aee14[] = "";
const char var7f1aee18[] = "";
const char var7f1aee1c[] = "";
const char var7f1aee20[] = "";
const char var7f1aee24[] = "";
const char var7f1aee28[] = "";
const char var7f1aee2c[] = "";
const char var7f1aee30[] = "";
const char var7f1aee34[] = "";
const char var7f1aee38[] = "";
const char var7f1aee3c[] = "";
const char var7f1aee40[] = "";
const char var7f1aee44[] = "";
const char var7f1aee48[] = "";
const char var7f1aee4c[] = "";
const char var7f1aee50[] = "";
const char var7f1aee54[] = "";
const char var7f1aee58[] = "";
const char var7f1aee5c[] = "";
const char var7f1aee60[] = "";
const char var7f1aee64[] = "";
const char var7f1aee68[] = "";
const char var7f1aee6c[] = "";
const char var7f1aee70[] = "";
const char var7f1aee74[] = "";
const char var7f1aee78[] = "";
const char var7f1aee7c[] = "";
const char var7f1aee80[] = "";
const char var7f1aee84[] = "";
const char var7f1aee88[] = "";
const char var7f1aee8c[] = "";
const char var7f1aee90[] = "";
const char var7f1aee94[] = "";
const char var7f1aee98[] = "";
const char var7f1aee9c[] = "";
const char var7f1aeea0[] = "";
const char var7f1aeea4[] = "";
const char var7f1aeea8[] = "";
const char var7f1aeeac[] = "";
const char var7f1aeeb0[] = "";
const char var7f1aeeb4[] = "";
const char var7f1aeeb8[] = "";
const char var7f1aeebc[] = "";
const char var7f1aeec0[] = "";
const char var7f1aeec4[] = "";
const char var7f1aeec8[] = "";
const char var7f1aeecc[] = "";
const char var7f1aeed0[] = "";
const char var7f1aeed4[] = "";
const char var7f1aeed8[] = "";
const char var7f1aeedc[] = "";
const char var7f1aeee0[] = "";
const char var7f1aeee4[] = "";
const char var7f1aeee8[] = "";
const char var7f1aeeec[] = "";
const char var7f1aeef0[] = "";
const char var7f1aeef4[] = "";
const char var7f1aeef8[] = "";
const char var7f1aeefc[] = "";
const char var7f1aef00[] = "";
const char var7f1aef04[] = "";
const char var7f1aef08[] = "";
const char var7f1aef0c[] = "";
const char var7f1aef10[] = "";
const char var7f1aef14[] = "";
const char var7f1aef18[] = "";
const char var7f1aef1c[] = "";
const char var7f1aef20[] = "";
const char var7f1aef24[] = "";
const char var7f1aef28[] = "";
const char var7f1aef2c[] = "";
const char var7f1aef30[] = "";
const char var7f1aef34[] = "";
const char var7f1aef38[] = "";
const char var7f1aef3c[] = "";
const char var7f1aef40[] = "";
const char var7f1aef44[] = "";
const char var7f1aef48[] = "";
const char var7f1aef4c[] = "";
const char var7f1aef50[] = "";
const char var7f1aef54[] = "";
const char var7f1aef58[] = "";
const char var7f1aef5c[] = "";
const char var7f1aef60[] = "";
const char var7f1aef64[] = "";
const char var7f1aef68[] = "";
const char var7f1aef6c[] = "";
const char var7f1aef70[] = "";
const char var7f1aef74[] = "";
const char var7f1aef78[] = "";
const char var7f1aef7c[] = "";
const char var7f1aef80[] = "";
const char var7f1aef84[] = "";
const char var7f1aef88[] = "";
const char var7f1aef8c[] = "";
const char var7f1aef90[] = "";
const char var7f1aef94[] = "";
const char var7f1aef98[] = "";
const char var7f1aef9c[] = "";
const char var7f1aefa0[] = "";
const char var7f1aefa4[] = "";
const char var7f1aefa8[] = "";
const char var7f1aefac[] = "";
const char var7f1aefb0[] = "";
const char var7f1aefb4[] = "";
const char var7f1aefb8[] = "";
const char var7f1aefbc[] = "";
const char var7f1aefc0[] = "";
const char var7f1aefc4[] = "";
const char var7f1aefc8[] = "";
const char var7f1aefcc[] = "";
const char var7f1aefd0[] = "";
const char var7f1aefd4[] = "";
const char var7f1aefd8[] = "";
const char var7f1aefdc[] = "";
const char var7f1aefe0[] = "";
const char var7f1aefe4[] = "";
const char var7f1aefe8[] = "";
const char var7f1aefec[] = "";
const char var7f1aeff0[] = "";
const char var7f1aeff4[] = "";
const char var7f1aeff8[] = "";
const char var7f1aeffc[] = "";
const char var7f1af000[] = "";
const char var7f1af004[] = "";
const char var7f1af008[] = "";
const char var7f1af00c[] = "";
const char var7f1af010[] = "";
const char var7f1af014[] = "";
const char var7f1af018[] = "";
const char var7f1af01c[] = "";
const char var7f1af020[] = "";
const char var7f1af024[] = "";
const char var7f1af028[] = "";
const char var7f1af02c[] = "";
const char var7f1af030[] = "";
const char var7f1af034[] = "";
const char var7f1af038[] = "";
const char var7f1af03c[] = "";
const char var7f1af040[] = "";
const char var7f1af044[] = "";
const char var7f1af048[] = "";
const char var7f1af04c[] = "";
const char var7f1af050[] = "";
const char var7f1af054[] = "";
const char var7f1af058[] = "";
const char var7f1af05c[] = "";
const char var7f1af060[] = "";
const char var7f1af064[] = "";
const char var7f1af068[] = "";
const char var7f1af06c[] = "";
const char var7f1af070[] = "";
const char var7f1af074[] = "";
const char var7f1af078[] = "";
const char var7f1af07c[] = "";
const char var7f1af080[] = "";
const char var7f1af084[] = "";
const char var7f1af088[] = "";
const char var7f1af08c[] = "";
const char var7f1af090[] = "";
const char var7f1af094[] = "";
const char var7f1af098[] = "";
const char var7f1af09c[] = "";
const char var7f1af0a0[] = "";
const char var7f1af0a4[] = "";
const char var7f1af0a8[] = "";
const char var7f1af0ac[] = "";
const char var7f1af0b0[] = "";
const char var7f1af0b4[] = "";
const char var7f1af0b8[] = "";
const char var7f1af0bc[] = "";
const char var7f1af0c0[] = "";
const char var7f1af0c4[] = "";
const char var7f1af0c8[] = "";
const char var7f1af0cc[] = "";
const char var7f1af0d0[] = "";
const char var7f1af0d4[] = "";
const char var7f1af0d8[] = "";
const char var7f1af0dc[] = "";
const char var7f1af0e0[] = "";
const char var7f1af0e4[] = "";
const char var7f1af0e8[] = "";
const char var7f1af0ec[] = "";
const char var7f1af0f0[] = "";
const char var7f1af0f4[] = "";
const char var7f1af0f8[] = "";
const char var7f1af0fc[] = "";
const char var7f1af100[] = "";
const char var7f1af104[] = "";
const char var7f1af108[] = "";
const char var7f1af10c[] = "";
const char var7f1af110[] = "";
const char var7f1af114[] = "";
const char var7f1af118[] = "";
const char var7f1af11c[] = "";
const char var7f1af120[] = "";
const char var7f1af124[] = "";
const char var7f1af128[] = "";
const char var7f1af12c[] = "";
const char var7f1af130[] = "";
const char var7f1af134[] = "";
const char var7f1af138[] = "";
const char var7f1af13c[] = "";
const char var7f1af140[] = "";
const char var7f1af144[] = "";
const char var7f1af148[] = "";
const char var7f1af14c[] = "";
const char var7f1af150[] = "";
const char var7f1af154[] = "";
const char var7f1af158[] = "";
const char var7f1af15c[] = "";
const char var7f1af160[] = "";
const char var7f1af164[] = "";
const char var7f1af168[] = "";
const char var7f1af16c[] = "";
const char var7f1af170[] = "";
const char var7f1af174[] = "";
const char var7f1af178[] = "";
const char var7f1af17c[] = "";
const char var7f1af180[] = "";
const char var7f1af184[] = "";
const char var7f1af188[] = "";
const char var7f1af18c[] = "";
const char var7f1af190[] = "";
const char var7f1af194[] = "";
const char var7f1af198[] = "";
const char var7f1af19c[] = "";
const char var7f1af1a0[] = "";
const char var7f1af1a4[] = "";
const char var7f1af1a8[] = "";
const char var7f1af1ac[] = "";
const char var7f1af1b0[] = "";
const char var7f1af1b4[] = "";
const char var7f1af1b8[] = "";
const char var7f1af1bc[] = "";
const char var7f1af1c0[] = "";
const char var7f1af1c4[] = "";
const char var7f1af1c8[] = "";
const char var7f1af1cc[] = "";
const char var7f1af1d0[] = "";
const char var7f1af1d4[] = "";
const char var7f1af1d8[] = "";
const char var7f1af1dc[] = "";
const char var7f1af1e0[] = "";
const char var7f1af1e4[] = "";
const char var7f1af1e8[] = "";
const char var7f1af1ec[] = "";
const char var7f1af1f0[] = "";
const char var7f1af1f4[] = "";
const char var7f1af1f8[] = "";
const char var7f1af1fc[] = "";
const char var7f1af200[] = "";
const char var7f1af204[] = "";
const char var7f1af208[] = "";
const char var7f1af20c[] = "";
const char var7f1af210[] = "";
const char var7f1af214[] = "";
const char var7f1af218[] = "";
const char var7f1af21c[] = "";
const char var7f1af220[] = "";
const char var7f1af224[] = "";
const char var7f1af228[] = "";
const char var7f1af22c[] = "";
const char var7f1af230[] = "";
const char var7f1af234[] = "";
const char var7f1af238[] = "";
const char var7f1af23c[] = "";
const char var7f1af240[] = "";
const char var7f1af244[] = "";
const char var7f1af248[] = "";
const char var7f1af24c[] = "";
const char var7f1af250[] = "";
const char var7f1af254[] = "";
const char var7f1af258[] = "";
const char var7f1af25c[] = "";
const char var7f1af260[] = "";
const char var7f1af264[] = "";
const char var7f1af268[] = "";
const char var7f1af26c[] = "";
const char var7f1af270[] = "";
const char var7f1af274[] = "";
const char var7f1af278[] = "";
const char var7f1af27c[] = "";
const char var7f1af280[] = "";
const char var7f1af284[] = "";
const char var7f1af288[] = "";
const char var7f1af28c[] = "";
const char var7f1af290[] = "";
const char var7f1af294[] = "";
const char var7f1af298[] = "";
const char var7f1af29c[] = "";
const char var7f1af2a0[] = "";
const char var7f1af2a4[] = "";
const char var7f1af2a8[] = "";
const char var7f1af2ac[] = "";
const char var7f1af2b0[] = "";
const char var7f1af2b4[] = "";
const char var7f1af2b8[] = "";
const char var7f1af2bc[] = "";
const char var7f1af2c0[] = "";
const char var7f1af2c4[] = "";
const char var7f1af2c8[] = "";
const char var7f1af2cc[] = "";
const char var7f1af2d0[] = "";
const char var7f1af2d4[] = "";
const char var7f1af2d8[] = "";
const char var7f1af2dc[] = "";
const char var7f1af2e0[] = "";
const char var7f1af2e4[] = "";
const char var7f1af2e8[] = "";
const char var7f1af2ec[] = "";
const char var7f1af2f0[] = "";
const char var7f1af2f4[] = "";
const char var7f1af2f8[] = "";
const char var7f1af2fc[] = "";
const char var7f1af300[] = "";
const char var7f1af304[] = "";
const char var7f1af308[] = "";
const char var7f1af30c[] = "";
const char var7f1af310[] = "";
const char var7f1af314[] = "";
const char var7f1af318[] = "";
const char var7f1af31c[] = "";
const char var7f1af320[] = "";
const char var7f1af324[] = "";
const char var7f1af328[] = "";
const char var7f1af32c[] = "";
const char var7f1af330[] = "";
const char var7f1af334[] = "";
const char var7f1af338[] = "";
const char var7f1af33c[] = "";
const char var7f1af340[] = "";
const char var7f1af344[] = "";
const char var7f1af348[] = "";
const char var7f1af34c[] = "";
const char var7f1af350[] = "";
const char var7f1af354[] = "";
const char var7f1af358[] = "";
const char var7f1af35c[] = "";
const char var7f1af360[] = "";
const char var7f1af364[] = "";
const char var7f1af368[] = "";
const char var7f1af36c[] = "";
const char var7f1af370[] = "";
const char var7f1af374[] = "";
const char var7f1af378[] = "";
const char var7f1af37c[] = "";
const char var7f1af380[] = "";
const char var7f1af384[] = "";
const char var7f1af388[] = "";
const char var7f1af38c[] = "";
const char var7f1af390[] = "";
const char var7f1af394[] = "";
const char var7f1af398[] = "";
const char var7f1af39c[] = "";
const char var7f1af3a0[] = "";
const char var7f1af3a4[] = "";
const char var7f1af3a8[] = "";
const char var7f1af3ac[] = "";
const char var7f1af3b0[] = "";
const char var7f1af3b4[] = "";
const char var7f1af3b8[] = "";
const char var7f1af3bc[] = "";
const char var7f1af3c0[] = "";
const char var7f1af3c4[] = "";
const char var7f1af3c8[] = "";
const char var7f1af3cc[] = "";
const char var7f1af3d0[] = "";
const char var7f1af3d4[] = "";
const char var7f1af3d8[] = "";
const char var7f1af3dc[] = "";
const char var7f1af3e0[] = "";
const char var7f1af3e4[] = "";
const char var7f1af3e8[] = "";
const char var7f1af3ec[] = "";
const char var7f1af3f0[] = "";
const char var7f1af3f4[] = "";
const char var7f1af3f8[] = "";
const char var7f1af3fc[] = "";
const char var7f1af400[] = "";
const char var7f1af404[] = "";
const char var7f1af408[] = "";
const char var7f1af40c[] = "";
const char var7f1af410[] = "";
const char var7f1af414[] = "";
const char var7f1af418[] = "";
const char var7f1af41c[] = "";
const char var7f1af420[] = "";
const char var7f1af424[] = "";
const char var7f1af428[] = "";
const char var7f1af42c[] = "";
const char var7f1af430[] = "";
const char var7f1af434[] = "";
const char var7f1af438[] = "";
const char var7f1af43c[] = "";
const char var7f1af440[] = "";
const char var7f1af444[] = "";
const char var7f1af448[] = "";
const char var7f1af44c[] = "";
const char var7f1af450[] = "";
const char var7f1af454[] = "";
const char var7f1af458[] = "";
const char var7f1af45c[] = "";
const char var7f1af460[] = "";
const char var7f1af464[] = "";
const char var7f1af468[] = "";
const char var7f1af46c[] = "";
const char var7f1af470[] = "";
const char var7f1af474[] = "";
const char var7f1af478[] = "";
const char var7f1af47c[] = "";
const char var7f1af480[] = "";
const char var7f1af484[] = "";
const char var7f1af488[] = "";
const char var7f1af48c[] = "";
const char var7f1af490[] = "";
const char var7f1af494[] = "";
const char var7f1af498[] = "";
const char var7f1af49c[] = "";
const char var7f1af4a0[] = "";
const char var7f1af4a4[] = "";
const char var7f1af4a8[] = "";
const char var7f1af4ac[] = "";
const char var7f1af4b0[] = "";
const char var7f1af4b4[] = "";
const char var7f1af4b8[] = "";
const char var7f1af4bc[] = "";
const char var7f1af4c0[] = "";
const char var7f1af4c4[] = "";
const char var7f1af4c8[] = "";
const char var7f1af4cc[] = "";
const char var7f1af4d0[] = "";
const char var7f1af4d4[] = "";
const char var7f1af4d8[] = "";
const char var7f1af4dc[] = "";
const char var7f1af4e0[] = "";
const char var7f1af4e4[] = "";
const char var7f1af4e8[] = "";
const char var7f1af4ec[] = "";
const char var7f1af4f0[] = "";
const char var7f1af4f4[] = "";
const char var7f1af4f8[] = "";
const char var7f1af4fc[] = "";
const char var7f1af500[] = "";
const char var7f1af504[] = "";
const char var7f1af508[] = "";
const char var7f1af50c[] = "";
const char var7f1af510[] = "";
const char var7f1af514[] = "";
const char var7f1af518[] = "";
const char var7f1af51c[] = "";
const char var7f1af520[] = "";
const char var7f1af524[] = "";
const char var7f1af528[] = "";
const char var7f1af52c[] = "";
const char var7f1af530[] = "";
const char var7f1af534[] = "";
const char var7f1af538[] = "";
const char var7f1af53c[] = "";
const char var7f1af540[] = "";
const char var7f1af544[] = "";
const char var7f1af548[] = "";
const char var7f1af54c[] = "";
const char var7f1af550[] = "";
const char var7f1af554[] = "";
const char var7f1af558[] = "";
const char var7f1af55c[] = "";
const char var7f1af560[] = "";
const char var7f1af564[] = "";
const char var7f1af568[] = "";
const char var7f1af56c[] = "";
const char var7f1af570[] = "";
const char var7f1af574[] = "";
const char var7f1af578[] = "";
const char var7f1af57c[] = "";
const char var7f1af580[] = "";
const char var7f1af584[] = "";
const char var7f1af588[] = "";
const char var7f1af58c[] = "";
const char var7f1af590[] = "";
const char var7f1af594[] = "";
const char var7f1af598[] = "";
const char var7f1af59c[] = "";
const char var7f1af5a0[] = "";
const char var7f1af5a4[] = "";
const char var7f1af5a8[] = "";
const char var7f1af5ac[] = "";
const char var7f1af5b0[] = "";
const char var7f1af5b4[] = "";
const char var7f1af5b8[] = "";
const char var7f1af5bc[] = "";
const char var7f1af5c0[] = "";
const char var7f1af5c4[] = "";
const char var7f1af5c8[] = "";
const char var7f1af5cc[] = "";
const char var7f1af5d0[] = "";
const char var7f1af5d4[] = "";
const char var7f1af5d8[] = "";
const char var7f1af5dc[] = "";
const char var7f1af5e0[] = "";
const char var7f1af5e4[] = "";
const char var7f1af5e8[] = "";
const char var7f1af5ec[] = "";
const char var7f1af5f0[] = "";
const char var7f1af5f4[] = "";
const char var7f1af5f8[] = "";
const char var7f1af5fc[] = "";
const char var7f1af600[] = "";
const char var7f1af604[] = "";
const char var7f1af608[] = "";
const char var7f1af60c[] = "";
const char var7f1af610[] = "";
const char var7f1af614[] = "";
const char var7f1af618[] = "";
const char var7f1af61c[] = "";
const char var7f1af620[] = "";
const char var7f1af624[] = "";
const char var7f1af628[] = "";
const char var7f1af62c[] = "";
const char var7f1af630[] = "";
const char var7f1af634[] = "";
const char var7f1af638[] = "";
const char var7f1af63c[] = "";
const char var7f1af640[] = "";
const char var7f1af644[] = "";
const char var7f1af648[] = "";
const char var7f1af64c[] = "";
const char var7f1af650[] = "";
const char var7f1af654[] = "";
const char var7f1af658[] = "";
const char var7f1af65c[] = "";
const char var7f1af660[] = "";
const char var7f1af664[] = "";
const char var7f1af668[] = "";
const char var7f1af66c[] = "";
const char var7f1af670[] = "";
const char var7f1af674[] = "";
const char var7f1af678[] = "";
const char var7f1af67c[] = "";
const char var7f1af680[] = "";
const char var7f1af684[] = "";
const char var7f1af688[] = "";
const char var7f1af68c[] = "";
const char var7f1af690[] = "";
const char var7f1af694[] = "";
const char var7f1af698[] = "";
const char var7f1af69c[] = "";
const char var7f1af6a0[] = "";
const char var7f1af6a4[] = "";
const char var7f1af6a8[] = "";
const char var7f1af6ac[] = "";
const char var7f1af6b0[] = "";
const char var7f1af6b4[] = "";
const char var7f1af6b8[] = "";
const char var7f1af6bc[] = "";
const char var7f1af6c0[] = "";
const char var7f1af6c4[] = "";
const char var7f1af6c8[] = "";
const char var7f1af6cc[] = "";
const char var7f1af6d0[] = "";
const char var7f1af6d4[] = "";
const char var7f1af6d8[] = "";
const char var7f1af6dc[] = "";
const char var7f1af6e0[] = "";
const char var7f1af6e4[] = "";
const char var7f1af6e8[] = "";
const char var7f1af6ec[] = "";
const char var7f1af6f0[] = "";
const char var7f1af6f4[] = "";
const char var7f1af6f8[] = "";
const char var7f1af6fc[] = "";
const char var7f1af700[] = "";
const char var7f1af704[] = "";
const char var7f1af708[] = "";
const char var7f1af70c[] = "";
const char var7f1af710[] = "";
const char var7f1af714[] = "";
const char var7f1af718[] = "";
const char var7f1af71c[] = "";
const char var7f1af720[] = "";
const char var7f1af724[] = "";
const char var7f1af728[] = "";
const char var7f1af72c[] = "";
const char var7f1af730[] = "";
const char var7f1af734[] = "";
const char var7f1af738[] = "";
const char var7f1af73c[] = "";
const char var7f1af740[] = "";
const char var7f1af744[] = "";
const char var7f1af748[] = "";
const char var7f1af74c[] = "";
const char var7f1af750[] = "";
const char var7f1af754[] = "";
const char var7f1af758[] = "";
const char var7f1af75c[] = "";
const char var7f1af760[] = "";
const char var7f1af764[] = "";
const char var7f1af768[] = "";
const char var7f1af76c[] = "";
const char var7f1af770[] = "";
const char var7f1af774[] = "";
const char var7f1af778[] = "";
const char var7f1af77c[] = "";
const char var7f1af780[] = "";
const char var7f1af784[] = "";
const char var7f1af788[] = "";
const char var7f1af78c[] = "";
const char var7f1af790[] = "";
const char var7f1af794[] = "";
const char var7f1af798[] = "";
const char var7f1af79c[] = "";
const char var7f1af7a0[] = "";
const char var7f1af7a4[] = "";
const char var7f1af7a8[] = "";
const char var7f1af7ac[] = "";
const char var7f1af7b0[] = "";
const char var7f1af7b4[] = "";
const char var7f1af7b8[] = "";
const char var7f1af7bc[] = "";
const char var7f1af7c0[] = "";
const char var7f1af7c4[] = "";
const char var7f1af7c8[] = "";
const char var7f1af7cc[] = "";
const char var7f1af7d0[] = "";
const char var7f1af7d4[] = "";
const char var7f1af7d8[] = "";
const char var7f1af7dc[] = "";
const char var7f1af7e0[] = "";
const char var7f1af7e4[] = "";
const char var7f1af7e8[] = "";
const char var7f1af7ec[] = "";
const char var7f1af7f0[] = "";
const char var7f1af7f4[] = "";
const char var7f1af7f8[] = "";
const char var7f1af7fc[] = "";
const char var7f1af800[] = "";
const char var7f1af804[] = "";
const char var7f1af808[] = "";
const char var7f1af80c[] = "";
const char var7f1af810[] = "";
const char var7f1af814[] = "";
const char var7f1af818[] = "";
const char var7f1af81c[] = "";
const char var7f1af820[] = "";
const char var7f1af824[] = "";
const char var7f1af828[] = "";
const char var7f1af82c[] = "";
const char var7f1af830[] = "";
const char var7f1af834[] = "";
const char var7f1af838[] = "";
const char var7f1af83c[] = "";
const char var7f1af840[] = "";
const char var7f1af844[] = "";
const char var7f1af848[] = "";
const char var7f1af84c[] = "";
const char var7f1af850[] = "";
const char var7f1af854[] = "";
const char var7f1af858[] = "";
const char var7f1af85c[] = "";
const char var7f1af860[] = "";
const char var7f1af864[] = "";
const char var7f1af868[] = "";
const char var7f1af86c[] = "";
const char var7f1af870[] = "";
const char var7f1af874[] = "";
const char var7f1af878[] = "";
const char var7f1af87c[] = "";
const char var7f1af880[] = "";
const char var7f1af884[] = "";
const char var7f1af888[] = "";
const char var7f1af88c[] = "";
const char var7f1af890[] = "";
const char var7f1af894[] = "";
const char var7f1af898[] = "";
const char var7f1af89c[] = "";
const char var7f1af8a0[] = "";
const char var7f1af8a4[] = "";
const char var7f1af8a8[] = "";
const char var7f1af8ac[] = "";
const char var7f1af8b0[] = "";
const char var7f1af8b4[] = "";
const char var7f1af8b8[] = "";
const char var7f1af8bc[] = "";
const char var7f1af8c0[] = "";
const char var7f1af8c4[] = "";
const char var7f1af8c8[] = "";
const char var7f1af8cc[] = "";
const char var7f1af8d0[] = "";
const char var7f1af8d4[] = "";
const char var7f1af8d8[] = "";
const char var7f1af8dc[] = "";
const char var7f1af8e0[] = "";
const char var7f1af8e4[] = "";
const char var7f1af8e8[] = "";
const char var7f1af8ec[] = "";
const char var7f1af8f0[] = "";
const char var7f1af8f4[] = "";
const char var7f1af8f8[] = "";
const char var7f1af8fc[] = "";
const char var7f1af900[] = "";
const char var7f1af904[] = "";
const char var7f1af908[] = "";
const char var7f1af90c[] = "";
const char var7f1af910[] = "";
const char var7f1af914[] = "";
const char var7f1af918[] = "";
const char var7f1af91c[] = "";
const char var7f1af920[] = "";
const char var7f1af924[] = "";
const char var7f1af928[] = "";
const char var7f1af92c[] = "";
const char var7f1af930[] = "";
const char var7f1af934[] = "";
const char var7f1af938[] = "";
const char var7f1af93c[] = "";
const char var7f1af940[] = "";
const char var7f1af944[] = "";
const char var7f1af948[] = "";
const char var7f1af94c[] = "";
const char var7f1af950[] = "";
const char var7f1af954[] = "";
const char var7f1af958[] = "";
const char var7f1af95c[] = "";
const char var7f1af960[] = "";
const char var7f1af964[] = "";
const char var7f1af968[] = "";
const char var7f1af96c[] = "";
const char var7f1af970[] = "";
const char var7f1af974[] = "";
const char var7f1af978[] = "";
const char var7f1af97c[] = "";
const char var7f1af980[] = "";
const char var7f1af984[] = "";
const char var7f1af988[] = "";
const char var7f1af98c[] = "";
const char var7f1af990[] = "";
const char var7f1af994[] = "";
const char var7f1af998[] = "";
const char var7f1af99c[] = "";
const char var7f1af9a0[] = "";
const char var7f1af9a4[] = "";
const char var7f1af9a8[] = "";
const char var7f1af9ac[] = "";
const char var7f1af9b0[] = "";
const char var7f1af9b4[] = "";
const char var7f1af9b8[] = "";
const char var7f1af9bc[] = "";
const char var7f1af9c0[] = "";
const char var7f1af9c4[] = "";
const char var7f1af9c8[] = "";
const char var7f1af9cc[] = "";
const char var7f1af9d0[] = "";
const char var7f1af9d4[] = "";
const char var7f1af9d8[] = "";
const char var7f1af9dc[] = "";
const char var7f1af9e0[] = "";
const char var7f1af9e4[] = "";
const char var7f1af9e8[] = "";
const char var7f1af9ec[] = "";
const char var7f1af9f0[] = "";
const char var7f1af9f4[] = "";
const char var7f1af9f8[] = "";
const char var7f1af9fc[] = "";
const char var7f1afa00[] = "";
const char var7f1afa04[] = "";
const char var7f1afa08[] = "";
const char var7f1afa0c[] = "";
const char var7f1afa10[] = "";
const char var7f1afa14[] = "";
const char var7f1afa18[] = "";
const char var7f1afa1c[] = "";
const char var7f1afa20[] = "";
const char var7f1afa24[] = "";
const char var7f1afa28[] = "";
const char var7f1afa2c[] = "";
const char var7f1afa30[] = "";
const char var7f1afa34[] = "";
const char var7f1afa38[] = "";
const char var7f1afa3c[] = "";
const char var7f1afa40[] = "";
const char var7f1afa44[] = "";
const char var7f1afa48[] = "";
const char var7f1afa4c[] = "";
const char var7f1afa50[] = "";
const char var7f1afa54[] = "";
const char var7f1afa58[] = "";
const char var7f1afa5c[] = "";
const char var7f1afa60[] = "";
const char var7f1afa64[] = "";
const char var7f1afa68[] = "";
const char var7f1afa6c[] = "";
const char var7f1afa70[] = "";
const char var7f1afa74[] = "";
const char var7f1afa78[] = "";
const char var7f1afa7c[] = "";
const char var7f1afa80[] = "";
const char var7f1afa84[] = "";
const char var7f1afa88[] = "";
const char var7f1afa8c[] = "";
const char var7f1afa90[] = "";
const char var7f1afa94[] = "";
const char var7f1afa98[] = "";
const char var7f1afa9c[] = "";
const char var7f1afaa0[] = "";
const char var7f1afaa4[] = "";
const char var7f1afaa8[] = "";
const char var7f1afaac[] = "";
const char var7f1afab0[] = "";
const char var7f1afab4[] = "";
const char var7f1afab8[] = "";
const char var7f1afabc[] = "";
const char var7f1afac0[] = "";
const char var7f1afac4[] = "";
const char var7f1afac8[] = "";
const char var7f1afacc[] = "";
const char var7f1afad0[] = "";
const char var7f1afad4[] = "";
const char var7f1afad8[] = "";
const char var7f1afadc[] = "";
const char var7f1afae0[] = "";
const char var7f1afae4[] = "";
const char var7f1afae8[] = "";
const char var7f1afaec[] = "";
const char var7f1afaf0[] = "";
const char var7f1afaf4[] = "";
const char var7f1afaf8[] = "";
const char var7f1afafc[] = "";
const char var7f1afb00[] = "";
const char var7f1afb04[] = "";
const char var7f1afb08[] = "";
const char var7f1afb0c[] = "";
const char var7f1afb10[] = "";
const char var7f1afb14[] = "";
const char var7f1afb18[] = "";
const char var7f1afb1c[] = "";
const char var7f1afb20[] = "";
const char var7f1afb24[] = "";
const char var7f1afb28[] = "";
const char var7f1afb2c[] = "";
const char var7f1afb30[] = "";
const char var7f1afb34[] = "";
const char var7f1afb38[] = "";
const char var7f1afb3c[] = "";
const char var7f1afb40[] = "";
const char var7f1afb44[] = "";
const char var7f1afb48[] = "";
const char var7f1afb4c[] = "";
const char var7f1afb50[] = "";
const char var7f1afb54[] = "";
const char var7f1afb58[] = "";
const char var7f1afb5c[] = "";
const char var7f1afb60[] = "";
const char var7f1afb64[] = "";
const char var7f1afb68[] = "";
const char var7f1afb6c[] = "";
const char var7f1afb70[] = "";
const char var7f1afb74[] = "";
const char var7f1afb78[] = "";
const char var7f1afb7c[] = "";
const char var7f1afb80[] = "";
const char var7f1afb84[] = "";
const char var7f1afb88[] = "";
const char var7f1afb8c[] = "";
const char var7f1afb90[] = "";
const char var7f1afb94[] = "";
const char var7f1afb98[] = "";
const char var7f1afb9c[] = "";
const char var7f1afba0[] = "";
const char var7f1afba4[] = "";
const char var7f1afba8[] = "";
const char var7f1afbac[] = "";
const char var7f1afbb0[] = "";
const char var7f1afbb4[] = "";
const char var7f1afbb8[] = "";
const char var7f1afbbc[] = "";
const char var7f1afbc0[] = "";
const char var7f1afbc4[] = "";
const char var7f1afbc8[] = "";
const char var7f1afbcc[] = "";
const char var7f1afbd0[] = "";
const char var7f1afbd4[] = "";
const char var7f1afbd8[] = "";
const char var7f1afbdc[] = "";
const char var7f1afbe0[] = "";
const char var7f1afbe4[] = "";
const char var7f1afbe8[] = "";
const char var7f1afbec[] = "";
const char var7f1afbf0[] = "";
const char var7f1afbf4[] = "";
const char var7f1afbf8[] = "";
const char var7f1afbfc[] = "";
const char var7f1afc00[] = "";
const char var7f1afc04[] = "";
const char var7f1afc08[] = "";
const char var7f1afc0c[] = "";
const char var7f1afc10[] = "";
const char var7f1afc14[] = "";
const char var7f1afc18[] = "";
const char var7f1afc1c[] = "";
const char var7f1afc20[] = "";
const char var7f1afc24[] = "";
const char var7f1afc28[] = "";
const char var7f1afc2c[] = "";
const char var7f1afc30[] = "";
const char var7f1afc34[] = "";
const char var7f1afc38[] = "";
const char var7f1afc3c[] = "";
const char var7f1afc40[] = "";
const char var7f1afc44[] = "";
const char var7f1afc48[] = "";
const char var7f1afc4c[] = "";
const char var7f1afc50[] = "";
const char var7f1afc54[] = "";
const char var7f1afc58[] = "";
const char var7f1afc5c[] = "";
const char var7f1afc60[] = "";
const char var7f1afc64[] = "";
const char var7f1afc68[] = "";
const char var7f1afc6c[] = "";
const char var7f1afc70[] = "";
const char var7f1afc74[] = "";
const char var7f1afc78[] = "";
const char var7f1afc7c[] = "";
const char var7f1afc80[] = "";
const char var7f1afc84[] = "";
const char var7f1afc88[] = "";
const char var7f1afc8c[] = "";
const char var7f1afc90[] = "";
const char var7f1afc94[] = "";
const char var7f1afc98[] = "";
const char var7f1afc9c[] = "";
const char var7f1afca0[] = "";
const char var7f1afca4[] = "";
const char var7f1afca8[] = "";
const char var7f1afcac[] = "";
const char var7f1afcb0[] = "";
const char var7f1afcb4[] = "";
const char var7f1afcb8[] = "";
const char var7f1afcbc[] = "";
const char var7f1afcc0[] = "";
const char var7f1afcc4[] = "";
const char var7f1afcc8[] = "";
const char var7f1afccc[] = "";
const char var7f1afcd0[] = "";
const char var7f1afcd4[] = "";
const char var7f1afcd8[] = "";
const char var7f1afcdc[] = "";
const char var7f1afce0[] = "";
const char var7f1afce4[] = "";
const char var7f1afce8[] = "";
const char var7f1afcec[] = "";
const char var7f1afcf0[] = "";
const char var7f1afcf4[] = "";
const char var7f1afcf8[] = "";
const char var7f1afcfc[] = "";
const char var7f1afd00[] = "";
const char var7f1afd04[] = "";
const char var7f1afd08[] = "";
const char var7f1afd0c[] = "";
const char var7f1afd10[] = "";
const char var7f1afd14[] = "";
const char var7f1afd18[] = "";
const char var7f1afd1c[] = "";
const char var7f1afd20[] = "";
const char var7f1afd24[] = "";
const char var7f1afd28[] = "";
const char var7f1afd2c[] = "";
const char var7f1afd30[] = "";
const char var7f1afd34[] = "";
const char var7f1afd38[] = "";
const char var7f1afd3c[] = "";
const char var7f1afd40[] = "";
const char var7f1afd44[] = "";
const char var7f1afd48[] = "";
const char var7f1afd4c[] = "";
const char var7f1afd50[] = "";
const char var7f1afd54[] = "";
const char var7f1afd58[] = "";
const char var7f1afd5c[] = "";
const char var7f1afd60[] = "";
const char var7f1afd64[] = "";
const char var7f1afd68[] = "";
const char var7f1afd6c[] = "";
const char var7f1afd70[] = "";
const char var7f1afd74[] = "";
const char var7f1afd78[] = "";
const char var7f1afd7c[] = "";
const char var7f1afd80[] = "";
const char var7f1afd84[] = "";
const char var7f1afd88[] = "";
const char var7f1afd8c[] = "";
const char var7f1afd90[] = "";
const char var7f1afd94[] = "";
const char var7f1afd98[] = "";
const char var7f1afd9c[] = "";
const char var7f1afda0[] = "";
const char var7f1afda4[] = "";
const char var7f1afda8[] = "";
const char var7f1afdac[] = "";
const char var7f1afdb0[] = "";
const char var7f1afdb4[] = "";
const char var7f1afdb8[] = "";
const char var7f1afdbc[] = "";
const char var7f1afdc0[] = "";
const char var7f1afdc4[] = "";
const char var7f1afdc8[] = "";
const char var7f1afdcc[] = "";
const char var7f1afdd0[] = "";
const char var7f1afdd4[] = "";
const char var7f1afdd8[] = "";
const char var7f1afddc[] = "";
const char var7f1afde0[] = "";
const char var7f1afde4[] = "";
const char var7f1afde8[] = "";
const char var7f1afdec[] = "";
const char var7f1afdf0[] = "";
const char var7f1afdf4[] = "";
const char var7f1afdf8[] = "";
const char var7f1afdfc[] = "";
const char var7f1afe00[] = "";
const char var7f1afe04[] = "";
const char var7f1afe08[] = "";
const char var7f1afe0c[] = "";
const char var7f1afe10[] = "";
const char var7f1afe14[] = "";
const char var7f1afe18[] = "";
const char var7f1afe1c[] = "";
const char var7f1afe20[] = "";
const char var7f1afe24[] = "";
const char var7f1afe28[] = "";
const char var7f1afe2c[] = "";
const char var7f1afe30[] = "";
const char var7f1afe34[] = "";
const char var7f1afe38[] = "";
const char var7f1afe3c[] = "";
const char var7f1afe40[] = "";
const char var7f1afe44[] = "";
const char var7f1afe48[] = "";
const char var7f1afe4c[] = "";
const char var7f1afe50[] = "";
const char var7f1afe54[] = "";
const char var7f1afe58[] = "";
const char var7f1afe5c[] = "";
const char var7f1afe60[] = "";
const char var7f1afe64[] = "";
const char var7f1afe68[] = "";
const char var7f1afe6c[] = "";
const char var7f1afe70[] = "";
const char var7f1afe74[] = "";
const char var7f1afe78[] = "";
const char var7f1afe7c[] = "";
const char var7f1afe80[] = "";
const char var7f1afe84[] = "";
const char var7f1afe88[] = "";
const char var7f1afe8c[] = "";
const char var7f1afe90[] = "";
const char var7f1afe94[] = "";
const char var7f1afe98[] = "";
const char var7f1afe9c[] = "";
const char var7f1afea0[] = "";
const char var7f1afea4[] = "";
const char var7f1afea8[] = "";
const char var7f1afeac[] = "";
const char var7f1afeb0[] = "";
const char var7f1afeb4[] = "";
const char var7f1afeb8[] = "";
const char var7f1afebc[] = "";
const char var7f1afec0[] = "";
const char var7f1afec4[] = "";
const char var7f1afec8[] = "";
const char var7f1afecc[] = "";
const char var7f1afed0[] = "";
const char var7f1afed4[] = "";
const char var7f1afed8[] = "";
const char var7f1afedc[] = "";
const char var7f1afee0[] = "";
const char var7f1afee4[] = "";
const char var7f1afee8[] = "";
const char var7f1afeec[] = "";
const char var7f1afef0[] = "";
const char var7f1afef4[] = "";
const char var7f1afef8[] = "";
const char var7f1afefc[] = "";
const char var7f1aff00[] = "";
const char var7f1aff04[] = "";
const char var7f1aff08[] = "";
const char var7f1aff0c[] = "";
const char var7f1aff10[] = "";
const char var7f1aff14[] = "";
const char var7f1aff18[] = "";
const char var7f1aff1c[] = "";
const char var7f1aff20[] = "";
const char var7f1aff24[] = "";
const char var7f1aff28[] = "";
const char var7f1aff2c[] = "";
const char var7f1aff30[] = "";
const char var7f1aff34[] = "";
const char var7f1aff38[] = "";
const char var7f1aff3c[] = "";
const char var7f1aff40[] = "";
const char var7f1aff44[] = "";
const char var7f1aff48[] = "";
const char var7f1aff4c[] = "";
const char var7f1aff50[] = "";
const char var7f1aff54[] = "";
const char var7f1aff58[] = "";
const char var7f1aff5c[] = "";
const char var7f1aff60[] = "";
const char var7f1aff64[] = "";
const char var7f1aff68[] = "";
const char var7f1aff6c[] = "";
const char var7f1aff70[] = "";
const char var7f1aff74[] = "";
const char var7f1aff78[] = "";
const char var7f1aff7c[] = "";
const char var7f1aff80[] = "";
const char var7f1aff84[] = "";
const char var7f1aff88[] = "";
const char var7f1aff8c[] = "";
const char var7f1aff90[] = "";
const char var7f1aff94[] = "";
const char var7f1aff98[] = "";
const char var7f1aff9c[] = "";
const char var7f1affa0[] = "";
const char var7f1affa4[] = "";
const char var7f1affa8[] = "";
const char var7f1affac[] = "";
const char var7f1affb0[] = "";
const char var7f1affb4[] = "";
const char var7f1affb8[] = "";
const char var7f1affbc[] = "";
const char var7f1affc0[] = "";
const char var7f1affc4[] = "";
const char var7f1affc8[] = "";
const char var7f1affcc[] = "";
const char var7f1affd0[] = "";
const char var7f1affd4[] = "";
const char var7f1affd8[] = "";
const char var7f1affdc[] = "";
const char var7f1affe0[] = "";
const char var7f1affe4[] = "";
const char var7f1affe8[] = "";
const char var7f1affec[] = "";
const char var7f1afff0[] = "";
const char var7f1afff4[] = "";
const char var7f1afff8[] = "";
const char var7f1afffc[] = "";
const char var7f1b0000[] = "";
const char var7f1b0004[] = "";
const char var7f1b0008[] = "";
const char var7f1b000c[] = "";
const char var7f1b0010[] = "";
const char var7f1b0014[] = "";
const char var7f1b0018[] = "";
const char var7f1b001c[] = "";
const char var7f1b0020[] = "";
const char var7f1b0024[] = "";
const char var7f1b0028[] = "";
const char var7f1b002c[] = "";
const char var7f1b0030[] = "";
const char var7f1b0034[] = "";
const char var7f1b0038[] = "";
const char var7f1b003c[] = "";
const char var7f1b0040[] = "";
const char var7f1b0044[] = "";
const char var7f1b0048[] = "";
const char var7f1b004c[] = "";
const char var7f1b0050[] = "";
const char var7f1b0054[] = "";
const char var7f1b0058[] = "";
const char var7f1b005c[] = "";
const char var7f1b0060[] = "";
const char var7f1b0064[] = "";
const char var7f1b0068[] = "";
const char var7f1b006c[] = "";
const char var7f1b0070[] = "";
const char var7f1b0074[] = "";
const char var7f1b0078[] = "";
const char var7f1b007c[] = "";
const char var7f1b0080[] = "";
const char var7f1b0084[] = "";
const char var7f1b0088[] = "";
const char var7f1b008c[] = "";
const char var7f1b0090[] = "";
const char var7f1b0094[] = "";
const char var7f1b0098[] = "";
const char var7f1b009c[] = "";
const char var7f1b00a0[] = "";
const char var7f1b00a4[] = "";
const char var7f1b00a8[] = "";
const char var7f1b00ac[] = "";
const char var7f1b00b0[] = "";
const char var7f1b00b4[] = "";
const char var7f1b00b8[] = "";
const char var7f1b00bc[] = "";
const char var7f1b00c0[] = "";
const char var7f1b00c4[] = "";
const char var7f1b00c8[] = "";
const char var7f1b00cc[] = "";
const char var7f1b00d0[] = "";
const char var7f1b00d4[] = "";
const char var7f1b00d8[] = "";
const char var7f1b00dc[] = "";
const char var7f1b00e0[] = "";
const char var7f1b00e4[] = "";
const char var7f1b00e8[] = "";
const char var7f1b00ec[] = "";
const char var7f1b00f0[] = "";
const char var7f1b00f4[] = "";
const char var7f1b00f8[] = "";
const char var7f1b00fc[] = "";
const char var7f1b0100[] = "";
const char var7f1b0104[] = "";
const char var7f1b0108[] = "";
const char var7f1b010c[] = "";
const char var7f1b0110[] = "";
const char var7f1b0114[] = "";
const char var7f1b0118[] = "";
const char var7f1b011c[] = "";
const char var7f1b0120[] = "";
const char var7f1b0124[] = "";
const char var7f1b0128[] = "";
const char var7f1b012c[] = "";
const char var7f1b0130[] = "";
const char var7f1b0134[] = "";
const char var7f1b0138[] = "";
const char var7f1b013c[] = "";
const char var7f1b0140[] = "";
const char var7f1b0144[] = "";
const char var7f1b0148[] = "";
const char var7f1b014c[] = "";
const char var7f1b0150[] = "";
const char var7f1b0154[] = "";
const char var7f1b0158[] = "";
const char var7f1b015c[] = "";
const char var7f1b0160[] = "";
const char var7f1b0164[] = "";
const char var7f1b0168[] = "";
const char var7f1b016c[] = "";
const char var7f1b0170[] = "";
const char var7f1b0174[] = "";
const char var7f1b0178[] = "";
const char var7f1b017c[] = "";
const char var7f1b0180[] = "";
const char var7f1b0184[] = "";
const char var7f1b0188[] = "";
const char var7f1b018c[] = "";
const char var7f1b0190[] = "";
const char var7f1b0194[] = "";
const char var7f1b0198[] = "";
const char var7f1b019c[] = "";
const char var7f1b01a0[] = "";
const char var7f1b01a4[] = "";
const char var7f1b01a8[] = "";
const char var7f1b01ac[] = "";
const char var7f1b01b0[] = "";
const char var7f1b01b4[] = "";
const char var7f1b01b8[] = "";
const char var7f1b01bc[] = "";
const char var7f1b01c0[] = "";
const char var7f1b01c4[] = "";
const char var7f1b01c8[] = "";
const char var7f1b01cc[] = "";
const char var7f1b01d0[] = "";
const char var7f1b01d4[] = "";
const char var7f1b01d8[] = "";
const char var7f1b01dc[] = "";
const char var7f1b01e0[] = "";
const char var7f1b01e4[] = "";
const char var7f1b01e8[] = "";
const char var7f1b01ec[] = "";
const char var7f1b01f0[] = "";
const char var7f1b01f4[] = "";
const char var7f1b01f8[] = "";
const char var7f1b01fc[] = "";
const char var7f1b0200[] = "";
const char var7f1b0204[] = "";
const char var7f1b0208[] = "";
const char var7f1b020c[] = "";
const char var7f1b0210[] = "";
const char var7f1b0214[] = "";
const char var7f1b0218[] = "";
const char var7f1b021c[] = "";
const char var7f1b0220[] = "";
const char var7f1b0224[] = "";
const char var7f1b0228[] = "";
const char var7f1b022c[] = "";
const char var7f1b0230[] = "";
const char var7f1b0234[] = "";
const char var7f1b0238[] = "";
const char var7f1b023c[] = "";
const char var7f1b0240[] = "";
const char var7f1b0244[] = "";
const char var7f1b0248[] = "";
const char var7f1b024c[] = "";
const char var7f1b0250[] = "";
const char var7f1b0254[] = "";
const char var7f1b0258[] = "";
const char var7f1b025c[] = "";
const char var7f1b0260[] = "";
const char var7f1b0264[] = "";
const char var7f1b0268[] = "";
const char var7f1b026c[] = "";
const char var7f1b0270[] = "";
const char var7f1b0274[] = "";
const char var7f1b0278[] = "";
const char var7f1b027c[] = "";
const char var7f1b0280[] = "";
const char var7f1b0284[] = "";
const char var7f1b0288[] = "";
const char var7f1b028c[] = "";
const char var7f1b0290[] = "";
const char var7f1b0294[] = "";
const char var7f1b0298[] = "";
const char var7f1b029c[] = "";
const char var7f1b02a0[] = "";
const char var7f1b02a4[] = "";
const char var7f1b02a8[] = "";
const char var7f1b02ac[] = "";
const char var7f1b02b0[] = "";
const char var7f1b02b4[] = "";
const char var7f1b02b8[] = "";
const char var7f1b02bc[] = "";
const char var7f1b02c0[] = "";
const char var7f1b02c4[] = "";
const char var7f1b02c8[] = "";
const char var7f1b02cc[] = "";
const char var7f1b02d0[] = "";
const char var7f1b02d4[] = "";
const char var7f1b02d8[] = "";
const char var7f1b02dc[] = "";
const char var7f1b02e0[] = "";
const char var7f1b02e4[] = "";
const char var7f1b02e8[] = "";
const char var7f1b02ec[] = "";
const char var7f1b02f0[] = "";
const char var7f1b02f4[] = "";
const char var7f1b02f8[] = "";
const char var7f1b02fc[] = "";
const char var7f1b0300[] = "";
const char var7f1b0304[] = "";
const char var7f1b0308[] = "";
const char var7f1b030c[] = "";
const char var7f1b0310[] = "";
const char var7f1b0314[] = "";
const char var7f1b0318[] = "";
const char var7f1b031c[] = "";
const char var7f1b0320[] = "";
const char var7f1b0324[] = "";
const char var7f1b0328[] = "";
const char var7f1b032c[] = "";
const char var7f1b0330[] = "";
const char var7f1b0334[] = "";
const char var7f1b0338[] = "";
const char var7f1b033c[] = "";
const char var7f1b0340[] = "";
const char var7f1b0344[] = "";
const char var7f1b0348[] = "";
const char var7f1b034c[] = "";
const char var7f1b0350[] = "";
const char var7f1b0354[] = "";
const char var7f1b0358[] = "";
const char var7f1b035c[] = "";
const char var7f1b0360[] = "";
const char var7f1b0364[] = "";
const char var7f1b0368[] = "";
const char var7f1b036c[] = "";
const char var7f1b0370[] = "";
const char var7f1b0374[] = "";
const char var7f1b0378[] = "";
const char var7f1b037c[] = "";
const char var7f1b0380[] = "";
const char var7f1b0384[] = "";
const char var7f1b0388[] = "";
const char var7f1b038c[] = "";
const char var7f1b0390[] = "";
const char var7f1b0394[] = "";
const char var7f1b0398[] = "";
const char var7f1b039c[] = "";
const char var7f1b03a0[] = "";
const char var7f1b03a4[] = "";
const char var7f1b03a8[] = "";
const char var7f1b03ac[] = "";
const char var7f1b03b0[] = "";
const char var7f1b03b4[] = "";
const char var7f1b03b8[] = "";
const char var7f1b03bc[] = "";
const char var7f1b03c0[] = "";
const char var7f1b03c4[] = "";
const char var7f1b03c8[] = "";
const char var7f1b03cc[] = "";
const char var7f1b03d0[] = "";
const char var7f1b03d4[] = "";
const char var7f1b03d8[] = "";
const char var7f1b03dc[] = "";
const char var7f1b03e0[] = "";
const char var7f1b03e4[] = "";
const char var7f1b03e8[] = "";
const char var7f1b03ec[] = "";
const char var7f1b03f0[] = "";
const char var7f1b03f4[] = "";
const char var7f1b03f8[] = "";
const char var7f1b03fc[] = "";
const char var7f1b0400[] = "";
const char var7f1b0404[] = "";
const char var7f1b0408[] = "";
const char var7f1b040c[] = "";
const char var7f1b0410[] = "";
const char var7f1b0414[] = "";
const char var7f1b0418[] = "";
const char var7f1b041c[] = "";
const char var7f1b0420[] = "";
const char var7f1b0424[] = "";
const char var7f1b0428[] = "";
const char var7f1b042c[] = "";
const char var7f1b0430[] = "";
const char var7f1b0434[] = "";
const char var7f1b0438[] = "";
const char var7f1b043c[] = "";
const char var7f1b0440[] = "";
const char var7f1b0444[] = "";
const char var7f1b0448[] = "";
const char var7f1b044c[] = "";
const char var7f1b0450[] = "";
const char var7f1b0454[] = "";
const char var7f1b0458[] = "";
const char var7f1b045c[] = "";
const char var7f1b0460[] = "";
const char var7f1b0464[] = "";
const char var7f1b0468[] = "";
const char var7f1b046c[] = "";
const char var7f1b0470[] = "";
const char var7f1b0474[] = "";
const char var7f1b0478[] = "";
const char var7f1b047c[] = "";
const char var7f1b0480[] = "";
const char var7f1b0484[] = "";
const char var7f1b0488[] = "";
const char var7f1b048c[] = "";
const char var7f1b0490[] = "";
const char var7f1b0494[] = "";
const char var7f1b0498[] = "";
const char var7f1b049c[] = "";
const char var7f1b04a0[] = "";
const char var7f1b04a4[] = "";
const char var7f1b04a8[] = "";
const char var7f1b04ac[] = "";
const char var7f1b04b0[] = "";
const char var7f1b04b4[] = "";
const char var7f1b04b8[] = "";
const char var7f1b04bc[] = "";
const char var7f1b04c0[] = "";
const char var7f1b04c4[] = "";
const char var7f1b04c8[] = "";
const char var7f1b04cc[] = "";
const char var7f1b04d0[] = "";
const char var7f1b04d4[] = "";
const char var7f1b04d8[] = "";
const char var7f1b04dc[] = "";
const char var7f1b04e0[] = "";
const char var7f1b04e4[] = "";
const char var7f1b04e8[] = "";
const char var7f1b04ec[] = "";
const char var7f1b04f0[] = "";
const char var7f1b04f4[] = "";
const char var7f1b04f8[] = "";
const char var7f1b04fc[] = "";
const char var7f1b0500[] = "";
const char var7f1b0504[] = "";
const char var7f1b0508[] = "";
const char var7f1b050c[] = "";
const char var7f1b0510[] = "";
const char var7f1b0514[] = "";
const char var7f1b0518[] = "";
const char var7f1b051c[] = "";
const char var7f1b0520[] = "";
const char var7f1b0524[] = "";
const char var7f1b0528[] = "";
const char var7f1b052c[] = "";
const char var7f1b0530[] = "";
const char var7f1b0534[] = "";
const char var7f1b0538[] = "";
const char var7f1b053c[] = "";
const char var7f1b0540[] = "";
const char var7f1b0544[] = "";
const char var7f1b0548[] = "";
const char var7f1b054c[] = "";
const char var7f1b0550[] = "";
const char var7f1b0554[] = "";
const char var7f1b0558[] = "";
const char var7f1b055c[] = "";
const char var7f1b0560[] = "";
const char var7f1b0564[] = "";
const char var7f1b0568[] = "";
const char var7f1b056c[] = "";
const char var7f1b0570[] = "";
const char var7f1b0574[] = "";
const char var7f1b0578[] = "";
const char var7f1b057c[] = "";
const char var7f1b0580[] = "";
const char var7f1b0584[] = "";
const char var7f1b0588[] = "";
const char var7f1b058c[] = "";
const char var7f1b0590[] = "";
const char var7f1b0594[] = "";
const char var7f1b0598[] = "";
const char var7f1b059c[] = "";
const char var7f1b05a0[] = "";
const char var7f1b05a4[] = "";
const char var7f1b05a8[] = "";
const char var7f1b05ac[] = "";
const char var7f1b05b0[] = "";
const char var7f1b05b4[] = "";
const char var7f1b05b8[] = "";
const char var7f1b05bc[] = "";
const char var7f1b05c0[] = "";
const char var7f1b05c4[] = "";
const char var7f1b05c8[] = "";
const char var7f1b05cc[] = "";
const char var7f1b05d0[] = "";
const char var7f1b05d4[] = "";
const char var7f1b05d8[] = "";
const char var7f1b05dc[] = "";
const char var7f1b05e0[] = "";
const char var7f1b05e4[] = "";
const char var7f1b05e8[] = "";
const char var7f1b05ec[] = "";
const char var7f1b05f0[] = "";
const char var7f1b05f4[] = "";
const char var7f1b05f8[] = "";
const char var7f1b05fc[] = "";
const char var7f1b0600[] = "";
const char var7f1b0604[] = "";
const char var7f1b0608[] = "";
const char var7f1b060c[] = "";
const char var7f1b0610[] = "";
const char var7f1b0614[] = "";
const char var7f1b0618[] = "";
const char var7f1b061c[] = "";
const char var7f1b0620[] = "";
const char var7f1b0624[] = "";
const char var7f1b0628[] = "";
const char var7f1b062c[] = "";
const char var7f1b0630[] = "";
const char var7f1b0634[] = "";
const char var7f1b0638[] = "";
const char var7f1b063c[] = "";
const char var7f1b0640[] = "";
const char var7f1b0644[] = "";
const char var7f1b0648[] = "";
const char var7f1b064c[] = "";
const char var7f1b0650[] = "";
const char var7f1b0654[] = "";
const char var7f1b0658[] = "";
const char var7f1b065c[] = "";
const char var7f1b0660[] = "";
const char var7f1b0664[] = "";
const char var7f1b0668[] = "";
const char var7f1b066c[] = "";
const char var7f1b0670[] = "";
const char var7f1b0674[] = "";
const char var7f1b0678[] = "";
const char var7f1b067c[] = "";
const char var7f1b0680[] = "";
const char var7f1b0684[] = "";
const char var7f1b0688[] = "";
const char var7f1b068c[] = "";
const char var7f1b0690[] = "";
const char var7f1b0694[] = "";
const char var7f1b0698[] = "";
const char var7f1b069c[] = "";
const char var7f1b06a0[] = "";
const char var7f1b06a4[] = "";
const char var7f1b06a8[] = "";
const char var7f1b06ac[] = "";
const char var7f1b06b0[] = "";
const char var7f1b06b4[] = "";
const char var7f1b06b8[] = "";
const char var7f1b06bc[] = "";
const char var7f1b06c0[] = "";
const char var7f1b06c4[] = "";
const char var7f1b06c8[] = "";
const char var7f1b06cc[] = "";
const char var7f1b06d0[] = "";
const char var7f1b06d4[] = "";
const char var7f1b06d8[] = "";
const char var7f1b06dc[] = "";
const char var7f1b06e0[] = "";
const char var7f1b06e4[] = "";
const char var7f1b06e8[] = "";
const char var7f1b06ec[] = "";
const char var7f1b06f0[] = "";
const char var7f1b06f4[] = "";
const char var7f1b06f8[] = "";
const char var7f1b06fc[] = "";
const char var7f1b0700[] = "";
const char var7f1b0704[] = "";
const char var7f1b0708[] = "";
const char var7f1b070c[] = "";
const char var7f1b0710[] = "";
const char var7f1b0714[] = "";
const char var7f1b0718[] = "";
const char var7f1b071c[] = "";
const char var7f1b0720[] = "";
const char var7f1b0724[] = "";
const char var7f1b0728[] = "";
const char var7f1b072c[] = "";
const char var7f1b0730[] = "";
const char var7f1b0734[] = "";
const char var7f1b0738[] = "";
const char var7f1b073c[] = "";
const char var7f1b0740[] = "";
const char var7f1b0744[] = "";
const char var7f1b0748[] = "";
const char var7f1b074c[] = "";
const char var7f1b0750[] = "";
const char var7f1b0754[] = "";
const char var7f1b0758[] = "";
const char var7f1b075c[] = "";
const char var7f1b0760[] = "";
const char var7f1b0764[] = "";
const char var7f1b0768[] = "";
const char var7f1b076c[] = "";
const char var7f1b0770[] = "";
const char var7f1b0774[] = "";
const char var7f1b0778[] = "";
const char var7f1b077c[] = "";
const char var7f1b0780[] = "";
const char var7f1b0784[] = "";
const char var7f1b0788[] = "";
const char var7f1b078c[] = "";
const char var7f1b0790[] = "";
const char var7f1b0794[] = "";
const char var7f1b0798[] = "";
const char var7f1b079c[] = "";
const char var7f1b07a0[] = "";
const char var7f1b07a4[] = "";
const char var7f1b07a8[] = "";
const char var7f1b07ac[] = "";
const char var7f1b07b0[] = "";
const char var7f1b07b4[] = "";
const char var7f1b07b8[] = "";
const char var7f1b07bc[] = "";
const char var7f1b07c0[] = "";
const char var7f1b07c4[] = "";
const char var7f1b07c8[] = "";
const char var7f1b07cc[] = "";
const char var7f1b07d0[] = "";
const char var7f1b07d4[] = "";
const char var7f1b07d8[] = "";
const char var7f1b07dc[] = "";
const char var7f1b07e0[] = "";
const char var7f1b07e4[] = "";
const char var7f1b07e8[] = "";
const char var7f1b07ec[] = "";
const char var7f1b07f0[] = "";
const char var7f1b07f4[] = "";
const char var7f1b07f8[] = "";
const char var7f1b07fc[] = "";
const char var7f1b0800[] = "";
const char var7f1b0804[] = "";
const char var7f1b0808[] = "";
const char var7f1b080c[] = "";
const char var7f1b0810[] = "";
const char var7f1b0814[] = "";
const char var7f1b0818[] = "";
const char var7f1b081c[] = "";
const char var7f1b0820[] = "";
const char var7f1b0824[] = "";
const char var7f1b0828[] = "";
const char var7f1b082c[] = "";
const char var7f1b0830[] = "";
const char var7f1b0834[] = "";
const char var7f1b0838[] = "";
const char var7f1b083c[] = "";
const char var7f1b0840[] = "";
const char var7f1b0844[] = "";
const char var7f1b0848[] = "";
const char var7f1b084c[] = "";
const char var7f1b0850[] = "";
const char var7f1b0854[] = "";
const char var7f1b0858[] = "";
const char var7f1b085c[] = "";
const char var7f1b0860[] = "";
const char var7f1b0864[] = "";
const char var7f1b0868[] = "";
const char var7f1b086c[] = "";
const char var7f1b0870[] = "";
const char var7f1b0874[] = "";
const char var7f1b0878[] = "";
const char var7f1b087c[] = "";
const char var7f1b0880[] = "";
const char var7f1b0884[] = "";
const char var7f1b0888[] = "";
const char var7f1b088c[] = "";
const char var7f1b0890[] = "";
const char var7f1b0894[] = "";
const char var7f1b0898[] = "";
const char var7f1b089c[] = "";
const char var7f1b08a0[] = "";
const char var7f1b08a4[] = "";
const char var7f1b08a8[] = "";
const char var7f1b08ac[] = "";
const char var7f1b08b0[] = "";
const char var7f1b08b4[] = "";
const char var7f1b08b8[] = "";
const char var7f1b08bc[] = "";
const char var7f1b08c0[] = "";
const char var7f1b08c4[] = "";
const char var7f1b08c8[] = "";
const char var7f1b08cc[] = "";
const char var7f1b08d0[] = "";
const char var7f1b08d4[] = "";
const char var7f1b08d8[] = "";
const char var7f1b08dc[] = "";
const char var7f1b08e0[] = "";
const char var7f1b08e4[] = "";
const char var7f1b08e8[] = "";
const char var7f1b08ec[] = "";
const char var7f1b08f0[] = "";
const char var7f1b08f4[] = "";
const char var7f1b08f8[] = "";
const char var7f1b08fc[] = "";
const char var7f1b0900[] = "";
const char var7f1b0904[] = "";
const char var7f1b0908[] = "";
const char var7f1b090c[] = "";
const char var7f1b0910[] = "";
const char var7f1b0914[] = "";
const char var7f1b0918[] = "";
const char var7f1b091c[] = "";
const char var7f1b0920[] = "";
const char var7f1b0924[] = "";
const char var7f1b0928[] = "";
const char var7f1b092c[] = "";
const char var7f1b0930[] = "";
const char var7f1b0934[] = "";
const char var7f1b0938[] = "";
const char var7f1b093c[] = "";
const char var7f1b0940[] = "";
const char var7f1b0944[] = "";
const char var7f1b0948[] = "";
const char var7f1b094c[] = "";
const char var7f1b0950[] = "";
const char var7f1b0954[] = "";
const char var7f1b0958[] = "";
const char var7f1b095c[] = "";
const char var7f1b0960[] = "";
const char var7f1b0964[] = "";
const char var7f1b0968[] = "";
const char var7f1b096c[] = "";
const char var7f1b0970[] = "";
const char var7f1b0974[] = "";
const char var7f1b0978[] = "";
const char var7f1b097c[] = "";
const char var7f1b0980[] = "";
const char var7f1b0984[] = "";
const char var7f1b0988[] = "";
const char var7f1b098c[] = "";
const char var7f1b0990[] = "";
const char var7f1b0994[] = "";
const char var7f1b0998[] = "";
const char var7f1b099c[] = "";
const char var7f1b09a0[] = "";
const char var7f1b09a4[] = "";
const char var7f1b09a8[] = "";
const char var7f1b09ac[] = "";
const char var7f1b09b0[] = "";
const char var7f1b09b4[] = "";
const char var7f1b09b8[] = "";
const char var7f1b09bc[] = "";
const char var7f1b09c0[] = "";
const char var7f1b09c4[] = "";
const char var7f1b09c8[] = "";
const char var7f1b09cc[] = "";
const char var7f1b09d0[] = "";
const char var7f1b09d4[] = "";
const char var7f1b09d8[] = "";
const char var7f1b09dc[] = "";
const char var7f1b09e0[] = "";
const char var7f1b09e4[] = "";
const char var7f1b09e8[] = "";
const char var7f1b09ec[] = "";
const char var7f1b09f0[] = "";
const char var7f1b09f4[] = "";
const char var7f1b09f8[] = "";
const char var7f1b09fc[] = "";
const char var7f1b0a00[] = "";
const char var7f1b0a04[] = "";
const char var7f1b0a08[] = "";
const char var7f1b0a0c[] = "";
const char var7f1b0a10[] = "";
const char var7f1b0a14[] = "";
const char var7f1b0a18[] = "";
const char var7f1b0a1c[] = "";
const char var7f1b0a20[] = "";
const char var7f1b0a24[] = "";
const char var7f1b0a28[] = "";
const char var7f1b0a2c[] = "";
const char var7f1b0a30[] = "";
const char var7f1b0a34[] = "";
const char var7f1b0a38[] = "";
const char var7f1b0a3c[] = "";
const char var7f1b0a40[] = "";
const char var7f1b0a44[] = "";
const char var7f1b0a48[] = "";
const char var7f1b0a4c[] = "";
const char var7f1b0a50[] = "";
const char var7f1b0a54[] = "";
const char var7f1b0a58[] = "";
const char var7f1b0a5c[] = "";
const char var7f1b0a60[] = "";
const char var7f1b0a64[] = "";
const char var7f1b0a68[] = "";
const char var7f1b0a6c[] = "";
const char var7f1b0a70[] = "";
const char var7f1b0a74[] = "";
const char var7f1b0a78[] = "";
const char var7f1b0a7c[] = "";
const char var7f1b0a80[] = "";
const char var7f1b0a84[] = "";
const char var7f1b0a88[] = "";
const char var7f1b0a8c[] = "";
const char var7f1b0a90[] = "";
const char var7f1b0a94[] = "";
const char var7f1b0a98[] = "";
const char var7f1b0a9c[] = "";
const char var7f1b0aa0[] = "";
const char var7f1b0aa4[] = "";
const char var7f1b0aa8[] = "";
const char var7f1b0aac[] = "";
const char var7f1b0ab0[] = "";
const char var7f1b0ab4[] = "";
const char var7f1b0ab8[] = "";
const char var7f1b0abc[] = "";
const char var7f1b0ac0[] = "";
const char var7f1b0ac4[] = "";
const char var7f1b0ac8[] = "";
const char var7f1b0acc[] = "";
const char var7f1b0ad0[] = "";
const char var7f1b0ad4[] = "";
const char var7f1b0ad8[] = "";
const char var7f1b0adc[] = "";
const char var7f1b0ae0[] = "";
const char var7f1b0ae4[] = "";
const char var7f1b0ae8[] = "";
const char var7f1b0aec[] = "";
const char var7f1b0af0[] = "";
const char var7f1b0af4[] = "";
const char var7f1b0af8[] = "";
const char var7f1b0afc[] = "";
const char var7f1b0b00[] = "";
const char var7f1b0b04[] = "";
const char var7f1b0b08[] = "";
const char var7f1b0b0c[] = "";
const char var7f1b0b10[] = "";
const char var7f1b0b14[] = "";
const char var7f1b0b18[] = "";
const char var7f1b0b1c[] = "";
const char var7f1b0b20[] = "";
const char var7f1b0b24[] = "";
const char var7f1b0b28[] = "";
const char var7f1b0b2c[] = "";
const char var7f1b0b30[] = "";
const char var7f1b0b34[] = "";
const char var7f1b0b38[] = "";
const char var7f1b0b3c[] = "";
const char var7f1b0b40[] = "";
const char var7f1b0b44[] = "";
const char var7f1b0b48[] = "";
const char var7f1b0b4c[] = "";
const char var7f1b0b50[] = "";
const char var7f1b0b54[] = "";
const char var7f1b0b58[] = "";
const char var7f1b0b5c[] = "";
const char var7f1b0b60[] = "";
const char var7f1b0b64[] = "";
const char var7f1b0b68[] = "";
const char var7f1b0b6c[] = "";
const char var7f1b0b70[] = "";
const char var7f1b0b74[] = "";
const char var7f1b0b78[] = "";
const char var7f1b0b7c[] = "";
const char var7f1b0b80[] = "";
const char var7f1b0b84[] = "";
const char var7f1b0b88[] = "";
const char var7f1b0b8c[] = "";
const char var7f1b0b90[] = "";
const char var7f1b0b94[] = "";
const char var7f1b0b98[] = "";
const char var7f1b0b9c[] = "";
const char var7f1b0ba0[] = "";
const char var7f1b0ba4[] = "";
const char var7f1b0ba8[] = "";
const char var7f1b0bac[] = "";
const char var7f1b0bb0[] = "";
const char var7f1b0bb4[] = "";
const char var7f1b0bb8[] = "";
const char var7f1b0bbc[] = "";
const char var7f1b0bc0[] = "";
const char var7f1b0bc4[] = "";
const char var7f1b0bc8[] = "";
const char var7f1b0bcc[] = "";
const char var7f1b0bd0[] = "";
const char var7f1b0bd4[] = "";
const char var7f1b0bd8[] = "";
const char var7f1b0bdc[] = "";
const char var7f1b0be0[] = "";
const char var7f1b0be4[] = "";
const char var7f1b0be8[] = "";
const char var7f1b0bec[] = "";
const char var7f1b0bf0[] = "";
const char var7f1b0bf4[] = "";
const char var7f1b0bf8[] = "";
const char var7f1b0bfc[] = "";
const char var7f1b0c00[] = "";
const char var7f1b0c04[] = "";
const char var7f1b0c08[] = "";
const char var7f1b0c0c[] = "";
const char var7f1b0c10[] = "";
const char var7f1b0c14[] = "";
const char var7f1b0c18[] = "";
const char var7f1b0c1c[] = "";
const char var7f1b0c20[] = "";
const char var7f1b0c24[] = "";
const char var7f1b0c28[] = "";
const char var7f1b0c2c[] = "";
const char var7f1b0c30[] = "";
const char var7f1b0c34[] = "";
const char var7f1b0c38[] = "";
const char var7f1b0c3c[] = "";
const char var7f1b0c40[] = "";
const char var7f1b0c44[] = "";
const char var7f1b0c48[] = "";
const char var7f1b0c4c[] = "";
const char var7f1b0c50[] = "";
const char var7f1b0c54[] = "";
const char var7f1b0c58[] = "";
const char var7f1b0c5c[] = "";
const char var7f1b0c60[] = "";
const char var7f1b0c64[] = "";
const char var7f1b0c68[] = "";
const char var7f1b0c6c[] = "";
const char var7f1b0c70[] = "";
const char var7f1b0c74[] = "";
const char var7f1b0c78[] = "";
const char var7f1b0c7c[] = "";
const char var7f1b0c80[] = "";
const char var7f1b0c84[] = "";
const char var7f1b0c88[] = "";
const char var7f1b0c8c[] = "";
const char var7f1b0c90[] = "";
const char var7f1b0c94[] = "";
const char var7f1b0c98[] = "";
const char var7f1b0c9c[] = "";
const char var7f1b0ca0[] = "";
const char var7f1b0ca4[] = "";
const char var7f1b0ca8[] = "";
const char var7f1b0cac[] = "";
const char var7f1b0cb0[] = "";
const char var7f1b0cb4[] = "";
const char var7f1b0cb8[] = "";
const char var7f1b0cbc[] = "";
const char var7f1b0cc0[] = "";
const char var7f1b0cc4[] = "";
const char var7f1b0cc8[] = "";
const char var7f1b0ccc[] = "";
const char var7f1b0cd0[] = "";
const char var7f1b0cd4[] = "";
const char var7f1b0cd8[] = "";
const char var7f1b0cdc[] = "";
const char var7f1b0ce0[] = "";
const char var7f1b0ce4[] = "";
const char var7f1b0ce8[] = "";
const char var7f1b0cec[] = "";
const char var7f1b0cf0[] = "";
const char var7f1b0cf4[] = "";
const char var7f1b0cf8[] = "";
const char var7f1b0cfc[] = "";
const char var7f1b0d00[] = "";
const char var7f1b0d04[] = "";
const char var7f1b0d08[] = "";
const char var7f1b0d0c[] = "";
const char var7f1b0d10[] = "";
const char var7f1b0d14[] = "";
const char var7f1b0d18[] = "";
const char var7f1b0d1c[] = "";
const char var7f1b0d20[] = "";
const char var7f1b0d24[] = "";
const char var7f1b0d28[] = "";
const char var7f1b0d2c[] = "";
const char var7f1b0d30[] = "";
const char var7f1b0d34[] = "";
const char var7f1b0d38[] = "";
const char var7f1b0d3c[] = "";
const char var7f1b0d40[] = "";
const char var7f1b0d44[] = "";
const char var7f1b0d48[] = "";
const char var7f1b0d4c[] = "";
const char var7f1b0d50[] = "";
const char var7f1b0d54[] = "";
const char var7f1b0d58[] = "";
const char var7f1b0d5c[] = "";
const char var7f1b0d60[] = "";
const char var7f1b0d64[] = "";
const char var7f1b0d68[] = "";
const char var7f1b0d6c[] = "";
const char var7f1b0d70[] = "";
const char var7f1b0d74[] = "";
const char var7f1b0d78[] = "";
const char var7f1b0d7c[] = "";
const char var7f1b0d80[] = "";
const char var7f1b0d84[] = "";
const char var7f1b0d88[] = "";
const char var7f1b0d8c[] = "";
const char var7f1b0d90[] = "";
const char var7f1b0d94[] = "";
const char var7f1b0d98[] = "";
const char var7f1b0d9c[] = "";
const char var7f1b0da0[] = "";
const char var7f1b0da4[] = "";
const char var7f1b0da8[] = "";
const char var7f1b0dac[] = "";
const char var7f1b0db0[] = "";
const char var7f1b0db4[] = "";
const char var7f1b0db8[] = "";
const char var7f1b0dbc[] = "";
const char var7f1b0dc0[] = "";
const char var7f1b0dc4[] = "";
const char var7f1b0dc8[] = "";
const char var7f1b0dcc[] = "";
const char var7f1b0dd0[] = "";
const char var7f1b0dd4[] = "";
const char var7f1b0dd8[] = "";
const char var7f1b0ddc[] = "";
const char var7f1b0de0[] = "";
const char var7f1b0de4[] = "";
const char var7f1b0de8[] = "";
const char var7f1b0dec[] = "";
const char var7f1b0df0[] = "";
const char var7f1b0df4[] = "";
const char var7f1b0df8[] = "";
const char var7f1b0dfc[] = "";
const char var7f1b0e00[] = "";
const char var7f1b0e04[] = "";
const char var7f1b0e08[] = "";
const char var7f1b0e0c[] = "";
const char var7f1b0e10[] = "";
const char var7f1b0e14[] = "";
const char var7f1b0e18[] = "";
const char var7f1b0e1c[] = "";
const char var7f1b0e20[] = "";
const char var7f1b0e24[] = "";
const char var7f1b0e28[] = "";
const char var7f1b0e2c[] = "";
const char var7f1b0e30[] = "";
const char var7f1b0e34[] = "";
const char var7f1b0e38[] = "";
const char var7f1b0e3c[] = "";
const char var7f1b0e40[] = "";
const char var7f1b0e44[] = "";
const char var7f1b0e48[] = "";
const char var7f1b0e4c[] = "";
const char var7f1b0e50[] = "";
const char var7f1b0e54[] = "";
const char var7f1b0e58[] = "";
const char var7f1b0e5c[] = "";
const char var7f1b0e60[] = "";
const char var7f1b0e64[] = "";
const char var7f1b0e68[] = "";
const char var7f1b0e6c[] = "";
const char var7f1b0e70[] = "";
const char var7f1b0e74[] = "";
const char var7f1b0e78[] = "";
const char var7f1b0e7c[] = "";
const char var7f1b0e80[] = "";
const char var7f1b0e84[] = "";
const char var7f1b0e88[] = "";
const char var7f1b0e8c[] = "";
const char var7f1b0e90[] = "";
const char var7f1b0e94[] = "";
const char var7f1b0e98[] = "";
const char var7f1b0e9c[] = "";
const char var7f1b0ea0[] = "";
const char var7f1b0ea4[] = "";
const char var7f1b0ea8[] = "";
const char var7f1b0eac[] = "";
const char var7f1b0eb0[] = "";
const char var7f1b0eb4[] = "";
const char var7f1b0eb8[] = "";
const char var7f1b0ebc[] = "";
const char var7f1b0ec0[] = "";
const char var7f1b0ec4[] = "";
const char var7f1b0ec8[] = "";
const char var7f1b0ecc[] = "";
const char var7f1b0ed0[] = "";
const char var7f1b0ed4[] = "";
const char var7f1b0ed8[] = "";
const char var7f1b0edc[] = "";
const char var7f1b0ee0[] = "";
const char var7f1b0ee4[] = "";
const char var7f1b0ee8[] = "";
const char var7f1b0eec[] = "";
const char var7f1b0ef0[] = "";
const char var7f1b0ef4[] = "";
const char var7f1b0ef8[] = "";
const char var7f1b0efc[] = "";
const char var7f1b0f00[] = "";
const char var7f1b0f04[] = "";
const char var7f1b0f08[] = "";
const char var7f1b0f0c[] = "";
const char var7f1b0f10[] = "";
const char var7f1b0f14[] = "";
const char var7f1b0f18[] = "";
const char var7f1b0f1c[] = "";
const char var7f1b0f20[] = "";
const char var7f1b0f24[] = "";
const char var7f1b0f28[] = "";
const char var7f1b0f2c[] = "";
const char var7f1b0f30[] = "";
const char var7f1b0f34[] = "";
const char var7f1b0f38[] = "";
const char var7f1b0f3c[] = "";
const char var7f1b0f40[] = "";
const char var7f1b0f44[] = "";
const char var7f1b0f48[] = "";
const char var7f1b0f4c[] = "";
const char var7f1b0f50[] = "";
const char var7f1b0f54[] = "";
const char var7f1b0f58[] = "";
const char var7f1b0f5c[] = "";
const char var7f1b0f60[] = "";
const char var7f1b0f64[] = "";
const char var7f1b0f68[] = "";
const char var7f1b0f6c[] = "";
const char var7f1b0f70[] = "";
const char var7f1b0f74[] = "";
const char var7f1b0f78[] = "";
const char var7f1b0f7c[] = "";
const char var7f1b0f80[] = "";
const char var7f1b0f84[] = "";
const char var7f1b0f88[] = "";
const char var7f1b0f8c[] = "";
const char var7f1b0f90[] = "";
const char var7f1b0f94[] = "";
const char var7f1b0f98[] = "";
const char var7f1b0f9c[] = "";
const char var7f1b0fa0[] = "";
const char var7f1b0fa4[] = "";
const char var7f1b0fa8[] = "";
const char var7f1b0fac[] = "";
const char var7f1b0fb0[] = "";
const char var7f1b0fb4[] = "";
const char var7f1b0fb8[] = "";
const char var7f1b0fbc[] = "";
const char var7f1b0fc0[] = "";
const char var7f1b0fc4[] = "";
const char var7f1b0fc8[] = "";
const char var7f1b0fcc[] = "";
const char var7f1b0fd0[] = "";
const char var7f1b0fd4[] = "";
const char var7f1b0fd8[] = "";
const char var7f1b0fdc[] = "";
const char var7f1b0fe0[] = "";
const char var7f1b0fe4[] = "";
const char var7f1b0fe8[] = "";
const char var7f1b0fec[] = "";
const char var7f1b0ff0[] = "";
const char var7f1b0ff4[] = "";
const char var7f1b0ff8[] = "";
const char var7f1b0ffc[] = "";
const char var7f1b1000[] = "";
const char var7f1b1004[] = "";
const char var7f1b1008[] = "";
const char var7f1b100c[] = "";
const char var7f1b1010[] = "";
const char var7f1b1014[] = "";
const char var7f1b1018[] = "";
const char var7f1b101c[] = "";
const char var7f1b1020[] = "";
const char var7f1b1024[] = "";
const char var7f1b1028[] = "";
const char var7f1b102c[] = "";
const char var7f1b1030[] = "";
const char var7f1b1034[] = "";
const char var7f1b1038[] = "";
const char var7f1b103c[] = "";
const char var7f1b1040[] = "";
const char var7f1b1044[] = "";
const char var7f1b1048[] = "";
const char var7f1b104c[] = "";
const char var7f1b1050[] = "";
const char var7f1b1054[] = "";
const char var7f1b1058[] = "";
const char var7f1b105c[] = "";
const char var7f1b1060[] = "";
const char var7f1b1064[] = "";
const char var7f1b1068[] = "";
const char var7f1b106c[] = "";
const char var7f1b1070[] = "";
const char var7f1b1074[] = "";
const char var7f1b1078[] = "";
const char var7f1b107c[] = "";
const char var7f1b1080[] = "";
const char var7f1b1084[] = "";
const char var7f1b1088[] = "";
const char var7f1b108c[] = "";
const char var7f1b1090[] = "";
const char var7f1b1094[] = "";
const char var7f1b1098[] = "";
const char var7f1b109c[] = "";
const char var7f1b10a0[] = "";
const char var7f1b10a4[] = "";
const char var7f1b10a8[] = "";
const char var7f1b10ac[] = "";
const char var7f1b10b0[] = "";
const char var7f1b10b4[] = "";
const char var7f1b10b8[] = "";
const char var7f1b10bc[] = "";
const char var7f1b10c0[] = "";
const char var7f1b10c4[] = "";
const char var7f1b10c8[] = "";
const char var7f1b10cc[] = "";
const char var7f1b10d0[] = "";
const char var7f1b10d4[] = "";
const char var7f1b10d8[] = "";
const char var7f1b10dc[] = "";
const char var7f1b10e0[] = "";
const char var7f1b10e4[] = "";
const char var7f1b10e8[] = "";
const char var7f1b10ec[] = "";
const char var7f1b10f0[] = "";
const char var7f1b10f4[] = "";
const char var7f1b10f8[] = "";
const char var7f1b10fc[] = "";
const char var7f1b1100[] = "";
const char var7f1b1104[] = "";
const char var7f1b1108[] = "";
const char var7f1b110c[] = "";
const char var7f1b1110[] = "";
const char var7f1b1114[] = "";
const char var7f1b1118[] = "";
const char var7f1b111c[] = "";
const char var7f1b1120[] = "";
const char var7f1b1124[] = "";
const char var7f1b1128[] = "";
const char var7f1b112c[] = "";
const char var7f1b1130[] = "";
const char var7f1b1134[] = "";
const char var7f1b1138[] = "";
const char var7f1b113c[] = "";
const char var7f1b1140[] = "";
const char var7f1b1144[] = "";
const char var7f1b1148[] = "";
const char var7f1b114c[] = "";
const char var7f1b1150[] = "";
const char var7f1b1154[] = "";
const char var7f1b1158[] = "";
const char var7f1b115c[] = "";
const char var7f1b1160[] = "";
const char var7f1b1164[] = "";
const char var7f1b1168[] = "";
const char var7f1b116c[] = "";
const char var7f1b1170[] = "";
const char var7f1b1174[] = "";
const char var7f1b1178[] = "";
const char var7f1b117c[] = "";
const char var7f1b1180[] = "";
const char var7f1b1184[] = "";
const char var7f1b1188[] = "";
const char var7f1b118c[] = "";
const char var7f1b1190[] = "";
const char var7f1b1194[] = "";
const char var7f1b1198[] = "";
const char var7f1b119c[] = "";
const char var7f1b11a0[] = "";
const char var7f1b11a4[] = "";
const char var7f1b11a8[] = "";
const char var7f1b11ac[] = "";
const char var7f1b11b0[] = "";
const char var7f1b11b4[] = "";
const char var7f1b11b8[] = "";
const char var7f1b11bc[] = "";
const char var7f1b11c0[] = "";
const char var7f1b11c4[] = "";
const char var7f1b11c8[] = "";
const char var7f1b11cc[] = "";
const char var7f1b11d0[] = "";
const char var7f1b11d4[] = "";
const char var7f1b11d8[] = "";
const char var7f1b11dc[] = "";
const char var7f1b11e0[] = "";
const char var7f1b11e4[] = "";
const char var7f1b11e8[] = "";
const char var7f1b11ec[] = "";
const char var7f1b11f0[] = "";
const char var7f1b11f4[] = "";
const char var7f1b11f8[] = "";
const char var7f1b11fc[] = "";
const char var7f1b1200[] = "";
const char var7f1b1204[] = "";
const char var7f1b1208[] = "";
const char var7f1b120c[] = "";
const char var7f1b1210[] = "";
const char var7f1b1214[] = "";
const char var7f1b1218[] = "";
const char var7f1b121c[] = "";
const char var7f1b1220[] = "";
const char var7f1b1224[] = "";
const char var7f1b1228[] = "";
const char var7f1b122c[] = "";
const char var7f1b1230[] = "";
const char var7f1b1234[] = "";
const char var7f1b1238[] = "";
const char var7f1b123c[] = "";
const char var7f1b1240[] = "";
const char var7f1b1244[] = "";
const char var7f1b1248[] = "";
const char var7f1b124c[] = "";
const char var7f1b1250[] = "";
const char var7f1b1254[] = "";
const char var7f1b1258[] = "";
const char var7f1b125c[] = "";
const char var7f1b1260[] = "";
const char var7f1b1264[] = "";
const char var7f1b1268[] = "";
const char var7f1b126c[] = "";
const char var7f1b1270[] = "";
const char var7f1b1274[] = "";
const char var7f1b1278[] = "";
const char var7f1b127c[] = "";
const char var7f1b1280[] = "";
const char var7f1b1284[] = "";
const char var7f1b1288[] = "";
const char var7f1b128c[] = "";
const char var7f1b1290[] = "";
const char var7f1b1294[] = "";
const char var7f1b1298[] = "";
const char var7f1b129c[] = "";
const char var7f1b12a0[] = "";
const char var7f1b12a4[] = "";
const char var7f1b12a8[] = "";
const char var7f1b12ac[] = "";
const char var7f1b12b0[] = "";
const char var7f1b12b4[] = "";
const char var7f1b12b8[] = "";
const char var7f1b12bc[] = "";
const char var7f1b12c0[] = "";
const char var7f1b12c4[] = "";
const char var7f1b12c8[] = "";
const char var7f1b12cc[] = "";
const char var7f1b12d0[] = "";
const char var7f1b12d4[] = "";
const char var7f1b12d8[] = "";
const char var7f1b12dc[] = "";
const char var7f1b12e0[] = "";
const char var7f1b12e4[] = "";
const char var7f1b12e8[] = "";
const char var7f1b12ec[] = "";
const char var7f1b12f0[] = "";
const char var7f1b12f4[] = "";
const char var7f1b12f8[] = "";
const char var7f1b12fc[] = "";
const char var7f1b1300[] = "";
const char var7f1b1304[] = "";
const char var7f1b1308[] = "";
const char var7f1b130c[] = "";
const char var7f1b1310[] = "";
const char var7f1b1314[] = "";
const char var7f1b1318[] = "";
const char var7f1b131c[] = "";
const char var7f1b1320[] = "";
const char var7f1b1324[] = "";
const char var7f1b1328[] = "";
const char var7f1b132c[] = "";
const char var7f1b1330[] = "";
const char var7f1b1334[] = "";
const char var7f1b1338[] = "";
const char var7f1b133c[] = "";
const char var7f1b1340[] = "";
const char var7f1b1344[] = "";
const char var7f1b1348[] = "";
const char var7f1b134c[] = "";
const char var7f1b1350[] = "";
const char var7f1b1354[] = "";
const char var7f1b1358[] = "";
const char var7f1b135c[] = "";
const char var7f1b1360[] = "";
const char var7f1b1364[] = "";
const char var7f1b1368[] = "";
const char var7f1b136c[] = "";
const char var7f1b1370[] = "";
const char var7f1b1374[] = "";
const char var7f1b1378[] = "";
const char var7f1b137c[] = "";
const char var7f1b1380[] = "";
const char var7f1b1384[] = "";
const char var7f1b1388[] = "";
const char var7f1b138c[] = "";
const char var7f1b1390[] = "";
const char var7f1b1394[] = "";
const char var7f1b1398[] = "";
const char var7f1b139c[] = "";
const char var7f1b13a0[] = "";
const char var7f1b13a4[] = "";
const char var7f1b13a8[] = "";
const char var7f1b13ac[] = "";
const char var7f1b13b0[] = "";
const char var7f1b13b4[] = "";
const char var7f1b13b8[] = "";
const char var7f1b13bc[] = "";
const char var7f1b13c0[] = "";
const char var7f1b13c4[] = "";
const char var7f1b13c8[] = "";
const char var7f1b13cc[] = "";
const char var7f1b13d0[] = "";
const char var7f1b13d4[] = "";
const char var7f1b13d8[] = "";
const char var7f1b13dc[] = "";
const char var7f1b13e0[] = "";
const char var7f1b13e4[] = "";
const char var7f1b13e8[] = "";
const char var7f1b13ec[] = "";
const char var7f1b13f0[] = "";
const char var7f1b13f4[] = "";
const char var7f1b13f8[] = "";
const char var7f1b13fc[] = "";
const char var7f1b1400[] = "";
const char var7f1b1404[] = "";
const char var7f1b1408[] = "";
const char var7f1b140c[] = "";
const char var7f1b1410[] = "";
const char var7f1b1414[] = "";
const char var7f1b1418[] = "";
const char var7f1b141c[] = "";
const char var7f1b1420[] = "";
const char var7f1b1424[] = "";
const char var7f1b1428[] = "";
const char var7f1b142c[] = "";
const char var7f1b1430[] = "";
const char var7f1b1434[] = "";
const char var7f1b1438[] = "";
const char var7f1b143c[] = "";
const char var7f1b1440[] = "";
const char var7f1b1444[] = "";
const char var7f1b1448[] = "";
const char var7f1b144c[] = "";
const char var7f1b1450[] = "";
const char var7f1b1454[] = "";
const char var7f1b1458[] = "";
const char var7f1b145c[] = "";
const char var7f1b1460[] = "";
const char var7f1b1464[] = "";
const char var7f1b1468[] = "";
const char var7f1b146c[] = "";
const char var7f1b1470[] = "";
const char var7f1b1474[] = "";
const char var7f1b1478[] = "";
const char var7f1b147c[] = "";
const char var7f1b1480[] = "";
const char var7f1b1484[] = "";
const char var7f1b1488[] = "";
const char var7f1b148c[] = "";
const char var7f1b1490[] = "";
const char var7f1b1494[] = "";
const char var7f1b1498[] = "";
const char var7f1b149c[] = "";
const char var7f1b14a0[] = "";
const char var7f1b14a4[] = "";
const char var7f1b14a8[] = "";
const char var7f1b14ac[] = "";
const char var7f1b14b0[] = "";
const char var7f1b14b4[] = "";
const char var7f1b14b8[] = "";
const char var7f1b14bc[] = "";
const char var7f1b14c0[] = "";
const char var7f1b14c4[] = "";
const char var7f1b14c8[] = "";
const char var7f1b14cc[] = "";
const char var7f1b14d0[] = "";
const char var7f1b14d4[] = "";
const char var7f1b14d8[] = "";
const char var7f1b14dc[] = "";
const char var7f1b14e0[] = "";
const char var7f1b14e4[] = "";
const char var7f1b14e8[] = "";
const char var7f1b14ec[] = "";
const char var7f1b14f0[] = "";
const char var7f1b14f4[] = "";
const char var7f1b14f8[] = "";
const char var7f1b14fc[] = "";
const char var7f1b1500[] = "";
const char var7f1b1504[] = "";
const char var7f1b1508[] = "";
const char var7f1b150c[] = "";
const char var7f1b1510[] = "";
const char var7f1b1514[] = "";
const char var7f1b1518[] = "";
const char var7f1b151c[] = "";
const char var7f1b1520[] = "";
const char var7f1b1524[] = "";
const char var7f1b1528[] = "";
const char var7f1b152c[] = "";
const char var7f1b1530[] = "";
const char var7f1b1534[] = "";
const char var7f1b1538[] = "";
const char var7f1b153c[] = "";
const char var7f1b1540[] = "";
const char var7f1b1544[] = "";
const char var7f1b1548[] = "";
const char var7f1b154c[] = "";
const char var7f1b1550[] = "";
const char var7f1b1554[] = "";
const char var7f1b1558[] = "";
const char var7f1b155c[] = "";
const char var7f1b1560[] = "";
const char var7f1b1564[] = "";
const char var7f1b1568[] = "";
const char var7f1b156c[] = "";
const char var7f1b1570[] = "";
const char var7f1b1574[] = "";
const char var7f1b1578[] = "";
const char var7f1b157c[] = "";
const char var7f1b1580[] = "";
const char var7f1b1584[] = "";
const char var7f1b1588[] = "";
const char var7f1b158c[] = "";
const char var7f1b1590[] = "";
const char var7f1b1594[] = "";
const char var7f1b1598[] = "";
const char var7f1b159c[] = "";
const char var7f1b15a0[] = "";
const char var7f1b15a4[] = "";
const char var7f1b15a8[] = "";
const char var7f1b15ac[] = "";
const char var7f1b15b0[] = "";
const char var7f1b15b4[] = "";
const char var7f1b15b8[] = "";
const char var7f1b15bc[] = "";
const char var7f1b15c0[] = "";
const char var7f1b15c4[] = "";
const char var7f1b15c8[] = "";
const char var7f1b15cc[] = "";
const char var7f1b15d0[] = "";
const char var7f1b15d4[] = "";
const char var7f1b15d8[] = "";
const char var7f1b15dc[] = "";
const char var7f1b15e0[] = "";
const char var7f1b15e4[] = "";
const char var7f1b15e8[] = "";
const char var7f1b15ec[] = "";
const char var7f1b15f0[] = "";
const char var7f1b15f4[] = "";
const char var7f1b15f8[] = "";
const char var7f1b15fc[] = "";
const char var7f1b1600[] = "";
const char var7f1b1604[] = "";
const char var7f1b1608[] = "";
const char var7f1b160c[] = "";
const char var7f1b1610[] = "";
const char var7f1b1614[] = "";
const char var7f1b1618[] = "";
const char var7f1b161c[] = "";
const char var7f1b1620[] = "";
const char var7f1b1624[] = "";
const char var7f1b1628[] = "";
const char var7f1b162c[] = "";
const char var7f1b1630[] = "";
const char var7f1b1634[] = "";
const char var7f1b1638[] = "";
const char var7f1b163c[] = "";
const char var7f1b1640[] = "";
const char var7f1b1644[] = "";
const char var7f1b1648[] = "";
const char var7f1b164c[] = "";
const char var7f1b1650[] = "";
const char var7f1b1654[] = "";
const char var7f1b1658[] = "";
const char var7f1b165c[] = "";
const char var7f1b1660[] = "";
const char var7f1b1664[] = "";
const char var7f1b1668[] = "";
const char var7f1b166c[] = "";
const char var7f1b1670[] = "";
const char var7f1b1674[] = "";
const char var7f1b1678[] = "";
const char var7f1b167c[] = "";
const char var7f1b1680[] = "";
const char var7f1b1684[] = "";
const char var7f1b1688[] = "";
const char var7f1b168c[] = "";
const char var7f1b1690[] = "";
const char var7f1b1694[] = "";
const char var7f1b1698[] = "";
const char var7f1b169c[] = "";
const char var7f1b16a0[] = "";
const char var7f1b16a4[] = "";
const char var7f1b16a8[] = "";
const char var7f1b16ac[] = "";
const char var7f1b16b0[] = "";
const char var7f1b16b4[] = "";
const char var7f1b16b8[] = "";
const char var7f1b16bc[] = "";
const char var7f1b16c0[] = "";
const char var7f1b16c4[] = "";
const char var7f1b16c8[] = "";
const char var7f1b16cc[] = "";
const char var7f1b16d0[] = "";
const char var7f1b16d4[] = "";
const char var7f1b16d8[] = "";
const char var7f1b16dc[] = "";
const char var7f1b16e0[] = "";
const char var7f1b16e4[] = "";
const char var7f1b16e8[] = "";
const char var7f1b16ec[] = "";
const char var7f1b16f0[] = "";
const char var7f1b16f4[] = "";
const char var7f1b16f8[] = "";
const char var7f1b16fc[] = "";
const char var7f1b1700[] = "";
const char var7f1b1704[] = "";
const char var7f1b1708[] = "";
const char var7f1b170c[] = "";
const char var7f1b1710[] = "";
const char var7f1b1714[] = "";
const char var7f1b1718[] = "";
const char var7f1b171c[] = "";
const char var7f1b1720[] = "";
const char var7f1b1724[] = "";
const char var7f1b1728[] = "";
const char var7f1b172c[] = "";
const char var7f1b1730[] = "";
const char var7f1b1734[] = "";
const char var7f1b1738[] = "";
const char var7f1b173c[] = "";
const char var7f1b1740[] = "";
const char var7f1b1744[] = "";
const char var7f1b1748[] = "";
const char var7f1b174c[] = "";
const char var7f1b1750[] = "";
const char var7f1b1754[] = "";
const char var7f1b1758[] = "";
const char var7f1b175c[] = "";
const char var7f1b1760[] = "";
const char var7f1b1764[] = "";
const char var7f1b1768[] = "";
const char var7f1b176c[] = "";
const char var7f1b1770[] = "";
const char var7f1b1774[] = "";
const char var7f1b1778[] = "";
const char var7f1b177c[] = "";
const char var7f1b1780[] = "";
const char var7f1b1784[] = "";
const char var7f1b1788[] = "";
const char var7f1b178c[] = "";
const char var7f1b1790[] = "";
const char var7f1b1794[] = "";
const char var7f1b1798[] = "";
const char var7f1b179c[] = "";
const char var7f1b17a0[] = "";
const char var7f1b17a4[] = "";
const char var7f1b17a8[] = "";
const char var7f1b17ac[] = "";
const char var7f1b17b0[] = "";
const char var7f1b17b4[] = "";
const char var7f1b17b8[] = "";
const char var7f1b17bc[] = "";
const char var7f1b17c0[] = "";
const char var7f1b17c4[] = "";
const char var7f1b17c8[] = "";
const char var7f1b17cc[] = "";
const char var7f1b17d0[] = "";
const char var7f1b17d4[] = "";
const char var7f1b17d8[] = "";
const char var7f1b17dc[] = "";
const char var7f1b17e0[] = "";
const char var7f1b17e4[] = "";
const char var7f1b17e8[] = "";
const char var7f1b17ec[] = "";
const char var7f1b17f0[] = "";
const char var7f1b17f4[] = "";
const char var7f1b17f8[] = "";
const char var7f1b17fc[] = "";
const char var7f1b1800[] = "";
const char var7f1b1804[] = "";
const char var7f1b1808[] = "";
const char var7f1b180c[] = "";
const char var7f1b1810[] = "";
const char var7f1b1814[] = "";
const char var7f1b1818[] = "";
const char var7f1b181c[] = "";
const char var7f1b1820[] = "";
const char var7f1b1824[] = "";
const char var7f1b1828[] = "";
const char var7f1b182c[] = "";
const char var7f1b1830[] = "";
const char var7f1b1834[] = "";
const char var7f1b1838[] = "";
const char var7f1b183c[] = "";
const char var7f1b1840[] = "";
const char var7f1b1844[] = "";
const char var7f1b1848[] = "";
const char var7f1b184c[] = "";
const char var7f1b1850[] = "";
const char var7f1b1854[] = "";
const char var7f1b1858[] = "";
const char var7f1b185c[] = "";
const char var7f1b1860[] = "";
const char var7f1b1864[] = "";
const char var7f1b1868[] = "";
const char var7f1b186c[] = "";
const char var7f1b1870[] = "";
const char var7f1b1874[] = "";
const char var7f1b1878[] = "";
const char var7f1b187c[] = "";
const char var7f1b1880[] = "";
const char var7f1b1884[] = "";
const char var7f1b1888[] = "";
const char var7f1b188c[] = "";
const char var7f1b1890[] = "";
const char var7f1b1894[] = "";
const char var7f1b1898[] = "";
const char var7f1b189c[] = "";
const char var7f1b18a0[] = "";
const char var7f1b18a4[] = "";
const char var7f1b18a8[] = "";
const char var7f1b18ac[] = "";
const char var7f1b18b0[] = "";
const char var7f1b18b4[] = "";
const char var7f1b18b8[] = "";
const char var7f1b18bc[] = "";
const char var7f1b18c0[] = "";
const char var7f1b18c4[] = "";
const char var7f1b18c8[] = "";
const char var7f1b18cc[] = "";
const char var7f1b18d0[] = "";
const char var7f1b18d4[] = "";
const char var7f1b18d8[] = "";
const char var7f1b18dc[] = "";
const char var7f1b18e0[] = "";
const char var7f1b18e4[] = "";
const char var7f1b18e8[] = "";
const char var7f1b18ec[] = "";
const char var7f1b18f0[] = "";
const char var7f1b18f4[] = "";
const char var7f1b18f8[] = "";
const char var7f1b18fc[] = "";
const char var7f1b1900[] = "";
const char var7f1b1904[] = "";
const char var7f1b1908[] = "";
const char var7f1b190c[] = "";
const char var7f1b1910[] = "";
const char var7f1b1914[] = "";
const char var7f1b1918[] = "";
const char var7f1b191c[] = "";
const char var7f1b1920[] = "";
const char var7f1b1924[] = "";
const char var7f1b1928[] = "";
const char var7f1b192c[] = "";
const char var7f1b1930[] = "";
const char var7f1b1934[] = "";
const char var7f1b1938[] = "";
const char var7f1b193c[] = "";
const char var7f1b1940[] = "";
const char var7f1b1944[] = "";
const char var7f1b1948[] = "";
const char var7f1b194c[] = "";
const char var7f1b1950[] = "";
const char var7f1b1954[] = "";
const char var7f1b1958[] = "";
const char var7f1b195c[] = "";
const char var7f1b1960[] = "";
const char var7f1b1964[] = "";
const char var7f1b1968[] = "";
const char var7f1b196c[] = "";
const char var7f1b1970[] = "";
const char var7f1b1974[] = "";
const char var7f1b1978[] = "";
const char var7f1b197c[] = "";
const char var7f1b1980[] = "";
const char var7f1b1984[] = "";
const char var7f1b1988[] = "";
const char var7f1b198c[] = "";
const char var7f1b1990[] = "";
const char var7f1b1994[] = "";
const char var7f1b1998[] = "";
const char var7f1b199c[] = "";
const char var7f1b19a0[] = "";
const char var7f1b19a4[] = "";
const char var7f1b19a8[] = "";
const char var7f1b19ac[] = "";
const char var7f1b19b0[] = "";
const char var7f1b19b4[] = "";
const char var7f1b19b8[] = "";
const char var7f1b19bc[] = "";
const char var7f1b19c0[] = "";
const char var7f1b19c4[] = "";
const char var7f1b19c8[] = "";
const char var7f1b19cc[] = "";
const char var7f1b19d0[] = "";
const char var7f1b19d4[] = "";
const char var7f1b19d8[] = "";
const char var7f1b19dc[] = "";
const char var7f1b19e0[] = "";
const char var7f1b19e4[] = "";
const char var7f1b19e8[] = "";
const char var7f1b19ec[] = "";
const char var7f1b19f0[] = "";
const char var7f1b19f4[] = "";
const char var7f1b19f8[] = "";
const char var7f1b19fc[] = "";
const char var7f1b1a00[] = "";
const char var7f1b1a04[] = "";
const char var7f1b1a08[] = "";
const char var7f1b1a0c[] = "";
const char var7f1b1a10[] = "";
const char var7f1b1a14[] = "";
const char var7f1b1a18[] = "";
const char var7f1b1a1c[] = "";
const char var7f1b1a20[] = "";
const char var7f1b1a24[] = "";
const char var7f1b1a28[] = "";
const char var7f1b1a2c[] = "";
const char var7f1b1a30[] = "";
const char var7f1b1a34[] = "";
const char var7f1b1a38[] = "";
const char var7f1b1a3c[] = "";
const char var7f1b1a40[] = "";
const char var7f1b1a44[] = "";
const char var7f1b1a48[] = "";
const char var7f1b1a4c[] = "";
const char var7f1b1a50[] = "";
const char var7f1b1a54[] = "";
const char var7f1b1a58[] = "";
const char var7f1b1a5c[] = "";
const char var7f1b1a60[] = "";
const char var7f1b1a64[] = "";
const char var7f1b1a68[] = "";
const char var7f1b1a6c[] = "";
const char var7f1b1a70[] = "";
const char var7f1b1a74[] = "";
const char var7f1b1a78[] = "";
const char var7f1b1a7c[] = "";
const char var7f1b1a80[] = "";
const char var7f1b1a84[] = "";
const char var7f1b1a88[] = "";
const char var7f1b1a8c[] = "";
const char var7f1b1a90[] = "";
const char var7f1b1a94[] = "";
const char var7f1b1a98[] = "";
const char var7f1b1a9c[] = "";
const char var7f1b1aa0[] = "";
const char var7f1b1aa4[] = "";
const char var7f1b1aa8[] = "";
const char var7f1b1aac[] = "";
const char var7f1b1ab0[] = "";
const char var7f1b1ab4[] = "";
const char var7f1b1ab8[] = "";
const char var7f1b1abc[] = "";
const char var7f1b1ac0[] = "";
const char var7f1b1ac4[] = "";
const char var7f1b1ac8[] = "";
const char var7f1b1acc[] = "";
const char var7f1b1ad0[] = "";
const char var7f1b1ad4[] = "";
const char var7f1b1ad8[] = "";
const char var7f1b1adc[] = "";
const char var7f1b1ae0[] = "";
const char var7f1b1ae4[] = "";
const char var7f1b1ae8[] = "";
const char var7f1b1aec[] = "";
const char var7f1b1af0[] = "";
const char var7f1b1af4[] = "";
const char var7f1b1af8[] = "";
const char var7f1b1afc[] = "";
const char var7f1b1b00[] = "";
const char var7f1b1b04[] = "";
const char var7f1b1b08[] = "";
const char var7f1b1b0c[] = "";
const char var7f1b1b10[] = "";
const char var7f1b1b14[] = "";
const char var7f1b1b18[] = "";
const char var7f1b1b1c[] = "";
const char var7f1b1b20[] = "";
const char var7f1b1b24[] = "";
const char var7f1b1b28[] = "";
const char var7f1b1b2c[] = "";
const char var7f1b1b30[] = "";
const char var7f1b1b34[] = "";
const char var7f1b1b38[] = "";
const char var7f1b1b3c[] = "";
const char var7f1b1b40[] = "";
const char var7f1b1b44[] = "";
const char var7f1b1b48[] = "";
const char var7f1b1b4c[] = "";
const char var7f1b1b50[] = "";
const char var7f1b1b54[] = "";
const char var7f1b1b58[] = "";
const char var7f1b1b5c[] = "";
const char var7f1b1b60[] = "";
const char var7f1b1b64[] = "";
const char var7f1b1b68[] = "";
const char var7f1b1b6c[] = "";
const char var7f1b1b70[] = "";
const char var7f1b1b74[] = "";
const char var7f1b1b78[] = "";
const char var7f1b1b7c[] = "";
const char var7f1b1b80[] = "";
const char var7f1b1b84[] = "";
const char var7f1b1b88[] = "";
const char var7f1b1b8c[] = "";
const char var7f1b1b90[] = "";
const char var7f1b1b94[] = "";
const char var7f1b1b98[] = "";
const char var7f1b1b9c[] = "";
const char var7f1b1ba0[] = "";
const char var7f1b1ba4[] = "";
const char var7f1b1ba8[] = "";
const char var7f1b1bac[] = "";
const char var7f1b1bb0[] = "";
const char var7f1b1bb4[] = "";
const char var7f1b1bb8[] = "";
const char var7f1b1bbc[] = "";
const char var7f1b1bc0[] = "";
const char var7f1b1bc4[] = "";
const char var7f1b1bc8[] = "";
const char var7f1b1bcc[] = "";
const char var7f1b1bd0[] = "";
const char var7f1b1bd4[] = "";
const char var7f1b1bd8[] = "";
const char var7f1b1bdc[] = "";
const char var7f1b1be0[] = "";
const char var7f1b1be4[] = "";
const char var7f1b1be8[] = "";
const char var7f1b1bec[] = "";
const char var7f1b1bf0[] = "";
const char var7f1b1bf4[] = "";
const char var7f1b1bf8[] = "";
const char var7f1b1bfc[] = "";
const char var7f1b1c00[] = "";
const char var7f1b1c04[] = "";
const char var7f1b1c08[] = "";
const char var7f1b1c0c[] = "";
const char var7f1b1c10[] = "";
const char var7f1b1c14[] = "";
const char var7f1b1c18[] = "";
const char var7f1b1c1c[] = "";
const char var7f1b1c20[] = "";
const char var7f1b1c24[] = "";
const char var7f1b1c28[] = "";
const char var7f1b1c2c[] = "";
const char var7f1b1c30[] = "";
const char var7f1b1c34[] = "";
const char var7f1b1c38[] = "";
const char var7f1b1c3c[] = "";
const char var7f1b1c40[] = "";
const char var7f1b1c44[] = "";
const char var7f1b1c48[] = "";
const char var7f1b1c4c[] = "";
const char var7f1b1c50[] = "";
const char var7f1b1c54[] = "";
const char var7f1b1c58[] = "";
const char var7f1b1c5c[] = "";
const char var7f1b1c60[] = "";
const char var7f1b1c64[] = "";
const char var7f1b1c68[] = "";
const char var7f1b1c6c[] = "";
const char var7f1b1c70[] = "";
const char var7f1b1c74[] = "";
const char var7f1b1c78[] = "";
const char var7f1b1c7c[] = "";
const char var7f1b1c80[] = "";
const char var7f1b1c84[] = "";
const char var7f1b1c88[] = "";
const char var7f1b1c8c[] = "";
const char var7f1b1c90[] = "";
const char var7f1b1c94[] = "";
const char var7f1b1c98[] = "";
const char var7f1b1c9c[] = "";
const char var7f1b1ca0[] = "";
const char var7f1b1ca4[] = "";
const char var7f1b1ca8[] = "";
const char var7f1b1cac[] = "";
const char var7f1b1cb0[] = "";
const char var7f1b1cb4[] = "";
const char var7f1b1cb8[] = "";
const char var7f1b1cbc[] = "";
const char var7f1b1cc0[] = "";
const char var7f1b1cc4[] = "";
const char var7f1b1cc8[] = "";
const char var7f1b1ccc[] = "";
const char var7f1b1cd0[] = "";
const char var7f1b1cd4[] = "";
const char var7f1b1cd8[] = "";
const char var7f1b1cdc[] = "";
const char var7f1b1ce0[] = "";
const char var7f1b1ce4[] = "";
const char var7f1b1ce8[] = "";
const char var7f1b1cec[] = "";
const char var7f1b1cf0[] = "";
const char var7f1b1cf4[] = "";
const char var7f1b1cf8[] = "";
const char var7f1b1cfc[] = "";
const char var7f1b1d00[] = "";
const char var7f1b1d04[] = "";
const char var7f1b1d08[] = "";
const char var7f1b1d0c[] = "";
const char var7f1b1d10[] = "";
const char var7f1b1d14[] = "";
const char var7f1b1d18[] = "";
const char var7f1b1d1c[] = "";
const char var7f1b1d20[] = "";
const char var7f1b1d24[] = "";
const char var7f1b1d28[] = "";
const char var7f1b1d2c[] = "";
const char var7f1b1d30[] = "";
const char var7f1b1d34[] = "";
const char var7f1b1d38[] = "";
const char var7f1b1d3c[] = "";
const char var7f1b1d40[] = "";
const char var7f1b1d44[] = "";
const char var7f1b1d48[] = "";
const char var7f1b1d4c[] = "";
const char var7f1b1d50[] = "";
const char var7f1b1d54[] = "";
const char var7f1b1d58[] = "";
const char var7f1b1d5c[] = "";
const char var7f1b1d60[] = "";
const char var7f1b1d64[] = "";
const char var7f1b1d68[] = "";
const char var7f1b1d6c[] = "";
const char var7f1b1d70[] = "";
const char var7f1b1d74[] = "";
const char var7f1b1d78[] = "";
const char var7f1b1d7c[] = "";
const char var7f1b1d80[] = "";
const char var7f1b1d84[] = "";
const char var7f1b1d88[] = "";
const char var7f1b1d8c[] = "";
const char var7f1b1d90[] = "";
const char var7f1b1d94[] = "";
const char var7f1b1d98[] = "";
const char var7f1b1d9c[] = "";
const char var7f1b1da0[] = "";
const char var7f1b1da4[] = "";
const char var7f1b1da8[] = "";
const char var7f1b1dac[] = "";
const char var7f1b1db0[] = "";
const char var7f1b1db4[] = "";
const char var7f1b1db8[] = "";
const char var7f1b1dbc[] = "";
const char var7f1b1dc0[] = "";
const char var7f1b1dc4[] = "";
const char var7f1b1dc8[] = "";
const char var7f1b1dcc[] = "";
const char var7f1b1dd0[] = "";
const char var7f1b1dd4[] = "";
const char var7f1b1dd8[] = "";
const char var7f1b1ddc[] = "";
const char var7f1b1de0[] = "";
const char var7f1b1de4[] = "";
const char var7f1b1de8[] = "";
const char var7f1b1dec[] = "";
const char var7f1b1df0[] = "";
const char var7f1b1df4[] = "";
const char var7f1b1df8[] = "";
const char var7f1b1dfc[] = "";
const char var7f1b1e00[] = "";
const char var7f1b1e04[] = "";
const char var7f1b1e08[] = "";
const char var7f1b1e0c[] = "";
const char var7f1b1e10[] = "";
const char var7f1b1e14[] = "";
const char var7f1b1e18[] = "";
const char var7f1b1e1c[] = "";
const char var7f1b1e20[] = "";
const char var7f1b1e24[] = "";
const char var7f1b1e28[] = "";
const char var7f1b1e2c[] = "";
const char var7f1b1e30[] = "";
const char var7f1b1e34[] = "";
const char var7f1b1e38[] = "";
const char var7f1b1e3c[] = "";
const char var7f1b1e40[] = "";
const char var7f1b1e44[] = "%d\n";
const char var7f1b1e48[] = "%d\n";
const char var7f1b1e4c[] = "%d\n";
const char var7f1b1e50[] = "%d\n";
const char var7f1b1e54[] = "%d\n";

u32 var80071190 = 0x00000000;
u32 var80071194 = 0x00000000;
u32 var80071198 = 0x00000000;
u32 var8007119c = 0x00000000;
u32 var800711a0 = 0x00000000;
u32 var800711a4 = 0x00000000;
u32 var800711a8 = 0x0000000b;
u32 var800711ac = 0x30313233;
u32 var800711b0 = 0x34353637;
u32 var800711b4 = 0x38394142;
u32 var800711b8 = 0x43444546;
u32 var800711bc = 0x4748494a;
u32 var800711c0 = 0x4b4c4d4e;
u32 var800711c4 = 0x4f505152;
u32 var800711c8 = 0x53545556;
u32 var800711cc = 0x5758595a;
u32 var800711d0 = 0x203f212e;
u32 var800711d4 = 0x31323132;
u32 var800711d8 = 0x31323331;
u32 var800711dc = 0x32330000;
u32 var800711e0 = 0x573a573b;
u32 var800711e4 = 0x573c573d;
u32 var800711e8 = 0x00000000;
u32 var800711ec = 0x20000000;
u32 var800711f0 = 0x00000002;
u32 var800711f4 = 0x0000000c;
u32 var800711f8 = 0x0000000a;
u32 var800711fc = 0xffffffff;
u32 var80071200 = 0x00000003;
u32 var80071204 = 0x00000033;
u32 var80071208 = 0x0000000a;
u32 var8007120c = 0xffffffff;
u32 var80071210 = 0x00000003;
u32 var80071214 = 0x0000000c;
u32 var80071218 = 0x00000003;
u32 var8007121c = 0x0000004b;
u32 var80071220 = 0xffffffff;
u32 var80071224 = 0x00000037;
u32 var80071228 = 0x00000013;
u32 var8007122c = 0x00000040;
u32 var80071230 = 0xffffffff;
u32 var80071234 = 0x0000003f;
u32 var80071238 = 0x00000013;
u32 var8007123c = 0xffffffff;
u32 var80071240 = 0x0000000a;
u32 var80071244 = 0x0000003f;
u32 var80071248 = 0x0000000a;
u32 var8007124c = 0x0000004b;
u32 var80071250 = 0xffffffff;
u32 var80071254 = 0x00000033;
u32 var80071258 = 0x00000017;
u32 var8007125c = 0x00000037;
u32 var80071260 = 0xffffffff;
u32 var80071264 = 0x0000003b;
u32 var80071268 = 0x00000017;
u32 var8007126c = 0x00000044;
u32 var80071270 = 0xffffffff;
u32 var80071274 = 0x00000043;
u32 var80071278 = 0x00000017;
u32 var8007127c = 0xffffffff;
u32 var80071280 = 0x00000011;
u32 var80071284 = 0x00000043;
u32 var80071288 = 0x00000011;
u32 var8007128c = 0x0000004b;
u32 var80071290 = 0xffffffff;
u32 var80071294 = 0x00000037;
u32 var80071298 = 0x0000001b;
u32 var8007129c = 0x00000048;
u32 var800712a0 = 0xffffffff;
u32 var800712a4 = 0x00000047;
u32 var800712a8 = 0x0000001b;
u32 var800712ac = 0xffffffff;
u32 var800712b0 = 0x00000018;
u32 var800712b4 = 0x00000047;
u32 var800712b8 = 0x00000018;
u32 var800712bc = 0x0000004b;
u32 var800712c0 = 0xffffffff;
u32 var800712c4 = 0x00000031;
u32 var800712c8 = 0x0000001f;
u32 var800712cc = 0x0000004b;
u32 var800712d0 = 0xffffffff;
u32 var800712d4 = 0x0000002b;
u32 var800712d8 = 0x0000001c;
u32 var800712dc = 0xffffffff;
u32 var800712e0 = 0x00000026;
u32 var800712e4 = 0x0000002b;
u32 var800712e8 = 0x00000026;
u32 var800712ec = 0x0000004b;
u32 var800712f0 = 0xffffffff;
u32 var800712f4 = 0x0000001e;
u32 var800712f8 = 0x00000023;
u32 var800712fc = 0x00000025;
u32 var80071300 = 0xffffffff;
u32 var80071304 = 0x00000025;
u32 var80071308 = 0x00000023;
u32 var8007130c = 0xffffffff;
u32 var80071310 = 0x0000002d;
u32 var80071314 = 0x00000025;
u32 var80071318 = 0x0000002d;
u32 var8007131c = 0x0000004b;
u32 var80071320 = 0xffffffff;
u32 var80071324 = 0x00000022;
u32 var80071328 = 0x00000034;
u32 var8007132c = 0x0000004b;
u32 var80071330 = 0xffffffff;
u32 var80071334 = 0x0000000c;
u32 var80071338 = 0x0000001e;
u32 var8007133c = 0xffffffff;
u32 var80071340 = 0x0000003b;
u32 var80071344 = 0x0000000c;
u32 var80071348 = 0x0000003b;
u32 var8007134c = 0x0000004b;
u32 var80071350 = 0xffffffff;
u32 var80071354 = 0x54c254c4;
u32 var80071358 = 0x54ca54c5;
u32 var8007135c = 0x54cb54cc;
u32 var80071360 = 0x54ce54cd;
u32 var80071364 = 0x54d254c2;
u32 var80071368 = 0x54c854ca;
u32 var8007136c = 0x54c954cb;
u32 var80071370 = 0x54cc54cf;
u32 var80071374 = 0x54cd54d2;
u32 var80071378 = 0x54cb54c4;
u32 var8007137c = 0x54ca54c5;
u32 var80071380 = 0x54cd54cc;
u32 var80071384 = 0x54ce54c2;
u32 var80071388 = 0x54d254cb;
u32 var8007138c = 0x54c854ca;
u32 var80071390 = 0x54c954cd;
u32 var80071394 = 0x54cc54cf;
u32 var80071398 = 0x54c254d2;
u32 var8007139c = 0x56035603;
u32 var800713a0 = 0x54d35603;
u32 var800713a4 = 0x54cb54cc;
u32 var800713a8 = 0x54ce54cd;
u32 var800713ac = 0x56035603;
u32 var800713b0 = 0x560354d3;
u32 var800713b4 = 0x560354cb;
u32 var800713b8 = 0x54cc54cf;
u32 var800713bc = 0x54cd5603;
u32 var800713c0 = 0x56035603;
u32 var800713c4 = 0x54d35603;
u32 var800713c8 = 0x54cb54cc;
u32 var800713cc = 0x54ce54c2;
u32 var800713d0 = 0x56035603;
u32 var800713d4 = 0x560354d3;
u32 var800713d8 = 0x560354cb;
u32 var800713dc = 0x54cc54cf;
u32 var800713e0 = 0x54c25603;
u32 var800713e4 = 0x56035603;
u32 var800713e8 = 0x54d45603;
u32 var800713ec = 0x54cb54cc;
u32 var800713f0 = 0x54d154c2;
u32 var800713f4 = 0x56035603;
u32 var800713f8 = 0x560354d4;
u32 var800713fc = 0x560354cb;
u32 var80071400 = 0x54cc54d0;
u32 var80071404 = 0x54c25603;
u32 var80071408 = 0x56035603;
u32 var8007140c = 0x54d45603;
u32 var80071410 = 0x54cb54cc;
u32 var80071414 = 0x54d154cd;
u32 var80071418 = 0x56035603;
u32 var8007141c = 0x560354d4;
u32 var80071420 = 0x560354cb;
u32 var80071424 = 0x54cc54d0;
u32 var80071428 = 0x54cd5603;
u32 var8007142c = 0x54b954ba;
u32 var80071430 = 0x54bb54bc;
u32 var80071434 = 0x54bd54be;
u32 var80071438 = 0x54bf54c0;
u32 var8007143c = 0x54c10000;

GLOBAL_ASM(
glabel func0f0e5ce0
/*  f0e5ce0:	3c038007 */ 	lui	$v1,%hi(var800711a4)
/*  f0e5ce4:	246311a4 */ 	addiu	$v1,$v1,%lo(var800711a4)
/*  f0e5ce8:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0e5cec:	3c058007 */ 	lui	$a1,%hi(var800711a0)
/*  f0e5cf0:	24a511a0 */ 	addiu	$a1,$a1,%lo(var800711a0)
/*  f0e5cf4:	008e082a */ 	slt	$at,$a0,$t6
/*  f0e5cf8:	10200007 */ 	beqz	$at,.L0f0e5d18
/*  f0e5cfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e5d00:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f0e5d04:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f0e5d08:	2b010141 */ 	slti	$at,$t8,0x141
/*  f0e5d0c:	14200002 */ 	bnez	$at,.L0f0e5d18
/*  f0e5d10:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f0e5d14:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f0e5d18:
/*  f0e5d18:	3c058007 */ 	lui	$a1,%hi(var800711a0)
/*  f0e5d1c:	24a511a0 */ 	addiu	$a1,$a1,%lo(var800711a0)
/*  f0e5d20:	ac640000 */ 	sw	$a0,0x0($v1)
/*  f0e5d24:	03e00008 */ 	jr	$ra
/*  f0e5d28:	8ca20000 */ 	lw	$v0,0x0($a1)
);

GLOBAL_ASM(
glabel func0f0e5d2c
/*  f0e5d2c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0e5d30:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e5d34:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0e5d38:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0e5d3c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0e5d40:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0e5d44:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e5d48:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e5d4c:	8cae0010 */ 	lw	$t6,0x10($a1)
/*  f0e5d50:	00a09825 */ 	or	$s3,$a1,$zero
/*  f0e5d54:	00803825 */ 	or	$a3,$a0,$zero
/*  f0e5d58:	15c00003 */ 	bnez	$t6,.L0f0e5d68
/*  f0e5d5c:	27b50050 */ 	addiu	$s5,$sp,0x50
/*  f0e5d60:	1000005c */ 	beqz	$zero,.L0f0e5ed4
/*  f0e5d64:	00001025 */ 	or	$v0,$zero,$zero
.L0f0e5d68:
/*  f0e5d68:	afa00050 */ 	sw	$zero,0x50($sp)
/*  f0e5d6c:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f0e5d70:	afa70060 */ 	sw	$a3,0x60($sp)
/*  f0e5d74:	8e790010 */ 	lw	$t9,0x10($s3)
/*  f0e5d78:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0e5d7c:	02602825 */ 	or	$a1,$s3,$zero
/*  f0e5d80:	0320f809 */ 	jalr	$t9
/*  f0e5d84:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e5d88:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0e5d8c:	8fa70060 */ 	lw	$a3,0x60($sp)
/*  f0e5d90:	54c00011 */ 	bnezl	$a2,.L0f0e5dd8
/*  f0e5d94:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f0e5d98:	3c0f8007 */ 	lui	$t7,%hi(var800711a8)
/*  f0e5d9c:	8def11a8 */ 	lw	$t7,%lo(var800711a8)($t7)
/*  f0e5da0:	00ef001a */ 	div	$zero,$a3,$t7
/*  f0e5da4:	00008812 */ 	mflo	$s1
/*  f0e5da8:	15e00002 */ 	bnez	$t7,.L0f0e5db4
/*  f0e5dac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e5db0:	0007000d */ 	break	0x7
.L0f0e5db4:
/*  f0e5db4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e5db8:	15e10004 */ 	bne	$t7,$at,.L0f0e5dcc
/*  f0e5dbc:	3c018000 */ 	lui	$at,0x8000
/*  f0e5dc0:	14e10002 */ 	bne	$a3,$at,.L0f0e5dcc
/*  f0e5dc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e5dc8:	0006000d */ 	break	0x6
.L0f0e5dcc:
/*  f0e5dcc:	1000003d */ 	beqz	$zero,.L0f0e5ec4
/*  f0e5dd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e5dd4:	00c0a025 */ 	or	$s4,$a2,$zero
.L0f0e5dd8:
/*  f0e5dd8:	00e08025 */ 	or	$s0,$a3,$zero
/*  f0e5ddc:	00009025 */ 	or	$s2,$zero,$zero
/*  f0e5de0:	00008825 */ 	or	$s1,$zero,$zero
/*  f0e5de4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0e5de8:	afa00054 */ 	sw	$zero,0x54($sp)
/*  f0e5dec:	00d4082a */ 	slt	$at,$a2,$s4
.L0f0e5df0:
/*  f0e5df0:	10200018 */ 	beqz	$at,.L0f0e5e54
/*  f0e5df4:	3c038007 */ 	lui	$v1,%hi(var800711a8)
/*  f0e5df8:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0e5dfc:	8e790010 */ 	lw	$t9,0x10($s3)
/*  f0e5e00:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e5e04:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e5e08:	0320f809 */ 	jalr	$t9
/*  f0e5e0c:	02602825 */ 	or	$a1,$s3,$zero
/*  f0e5e10:	3c038007 */ 	lui	$v1,%hi(var800711a8)
/*  f0e5e14:	8c6311a8 */ 	lw	$v1,%lo(var800711a8)($v1)
/*  f0e5e18:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f0e5e1c:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0e5e20:	0203001a */ 	div	$zero,$s0,$v1
/*  f0e5e24:	00001012 */ 	mflo	$v0
/*  f0e5e28:	14600002 */ 	bnez	$v1,.L0f0e5e34
/*  f0e5e2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e5e30:	0007000d */ 	break	0x7
.L0f0e5e34:
/*  f0e5e34:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e5e38:	14610004 */ 	bne	$v1,$at,.L0f0e5e4c
/*  f0e5e3c:	3c018000 */ 	lui	$at,0x8000
/*  f0e5e40:	16010002 */ 	bne	$s0,$at,.L0f0e5e4c
/*  f0e5e44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e5e48:	0006000d */ 	break	0x6
.L0f0e5e4c:
/*  f0e5e4c:	1000000f */ 	beqz	$zero,.L0f0e5e8c
/*  f0e5e50:	00512821 */ 	addu	$a1,$v0,$s1
.L0f0e5e54:
/*  f0e5e54:	8c6311a8 */ 	lw	$v1,%lo(var800711a8)($v1)
/*  f0e5e58:	2404270f */ 	addiu	$a0,$zero,0x270f
/*  f0e5e5c:	0203001a */ 	div	$zero,$s0,$v1
/*  f0e5e60:	00001012 */ 	mflo	$v0
/*  f0e5e64:	14600002 */ 	bnez	$v1,.L0f0e5e70
/*  f0e5e68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e5e6c:	0007000d */ 	break	0x7
.L0f0e5e70:
/*  f0e5e70:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e5e74:	14610004 */ 	bne	$v1,$at,.L0f0e5e88
/*  f0e5e78:	3c018000 */ 	lui	$at,0x8000
/*  f0e5e7c:	16010002 */ 	bne	$s0,$at,.L0f0e5e88
/*  f0e5e80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e5e84:	0006000d */ 	break	0x6
.L0f0e5e88:
/*  f0e5e88:	00512821 */ 	addu	$a1,$v0,$s1
.L0f0e5e8c:
/*  f0e5e8c:	00a4082a */ 	slt	$at,$a1,$a0
/*  f0e5e90:	14200008 */ 	bnez	$at,.L0f0e5eb4
/*  f0e5e94:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0e5e98:	00911023 */ 	subu	$v0,$a0,$s1
/*  f0e5e9c:	00430019 */ 	multu	$v0,$v1
/*  f0e5ea0:	02228821 */ 	addu	$s1,$s1,$v0
/*  f0e5ea4:	0000c012 */ 	mflo	$t8
/*  f0e5ea8:	02188023 */ 	subu	$s0,$s0,$t8
/*  f0e5eac:	10000003 */ 	beqz	$zero,.L0f0e5ebc
/*  f0e5eb0:	2610fff5 */ 	addiu	$s0,$s0,-11
.L0f0e5eb4:
/*  f0e5eb4:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0e5eb8:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f0e5ebc:
/*  f0e5ebc:	5240ffcc */ 	beqzl	$s2,.L0f0e5df0
/*  f0e5ec0:	00d4082a */ 	slt	$at,$a2,$s4
.L0f0e5ec4:
/*  f0e5ec4:	06230003 */ 	bgezl	$s1,.L0f0e5ed4
/*  f0e5ec8:	02201025 */ 	or	$v0,$s1,$zero
/*  f0e5ecc:	00008825 */ 	or	$s1,$zero,$zero
/*  f0e5ed0:	02201025 */ 	or	$v0,$s1,$zero
.L0f0e5ed4:
/*  f0e5ed4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e5ed8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0e5edc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0e5ee0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0e5ee4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0e5ee8:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0e5eec:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0e5ef0:	03e00008 */ 	jr	$ra
/*  f0e5ef4:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f0e5ef8
/*  f0e5ef8:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0e5efc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e5f00:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0e5f04:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0e5f08:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0e5f0c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0e5f10:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e5f14:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e5f18:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0e5f1c:	8caf0010 */ 	lw	$t7,0x10($a1)
/*  f0e5f20:	0004a400 */ 	sll	$s4,$a0,0x10
/*  f0e5f24:	00147403 */ 	sra	$t6,$s4,0x10
/*  f0e5f28:	01c0a025 */ 	or	$s4,$t6,$zero
/*  f0e5f2c:	15e00003 */ 	bnez	$t7,.L0f0e5f3c
/*  f0e5f30:	00a09025 */ 	or	$s2,$a1,$zero
/*  f0e5f34:	10000037 */ 	beqz	$zero,.L0f0e6014
/*  f0e5f38:	00001025 */ 	or	$v0,$zero,$zero
.L0f0e5f3c:
/*  f0e5f3c:	06810002 */ 	bgez	$s4,.L0f0e5f48
/*  f0e5f40:	27b50040 */ 	addiu	$s5,$sp,0x40
/*  f0e5f44:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0e5f48:
/*  f0e5f48:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f0e5f4c:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f0e5f50:	8e590010 */ 	lw	$t9,0x10($s2)
/*  f0e5f54:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0e5f58:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e5f5c:	0320f809 */ 	jalr	$t9
/*  f0e5f60:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e5f64:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0e5f68:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e5f6c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0e5f70:	14400008 */ 	bnez	$v0,.L0f0e5f94
/*  f0e5f74:	00409825 */ 	or	$s3,$v0,$zero
/*  f0e5f78:	3c188007 */ 	lui	$t8,%hi(var800711a8)
/*  f0e5f7c:	8f1811a8 */ 	lw	$t8,%lo(var800711a8)($t8)
/*  f0e5f80:	02980019 */ 	multu	$s4,$t8
/*  f0e5f84:	00001012 */ 	mflo	$v0
/*  f0e5f88:	00024400 */ 	sll	$t0,$v0,0x10
/*  f0e5f8c:	10000021 */ 	beqz	$zero,.L0f0e6014
/*  f0e5f90:	00081403 */ 	sra	$v0,$t0,0x10
.L0f0e5f94:
/*  f0e5f94:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f0e5f98:	1a600013 */ 	blez	$s3,.L0f0e5fe8
/*  f0e5f9c:	afa00040 */ 	sw	$zero,0x40($sp)
.L0f0e5fa0:
/*  f0e5fa0:	8e590010 */ 	lw	$t9,0x10($s2)
/*  f0e5fa4:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e5fa8:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e5fac:	0320f809 */ 	jalr	$t9
/*  f0e5fb0:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e5fb4:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f0e5fb8:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0e5fbc:	028a082a */ 	slt	$at,$s4,$t2
/*  f0e5fc0:	54200004 */ 	bnezl	$at,.L0f0e5fd4
/*  f0e5fc4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e5fc8:	10000002 */ 	beqz	$zero,.L0f0e5fd4
/*  f0e5fcc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0e5fd0:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0e5fd4:
/*  f0e5fd4:	16000004 */ 	bnez	$s0,.L0f0e5fe8
/*  f0e5fd8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0e5fdc:	0053082a */ 	slt	$at,$v0,$s3
/*  f0e5fe0:	1420ffef */ 	bnez	$at,.L0f0e5fa0
/*  f0e5fe4:	afa20040 */ 	sw	$v0,0x40($sp)
.L0f0e5fe8:
/*  f0e5fe8:	3c0b8007 */ 	lui	$t3,%hi(var800711a8)
/*  f0e5fec:	8d6b11a8 */ 	lw	$t3,%lo(var800711a8)($t3)
/*  f0e5ff0:	00116880 */ 	sll	$t5,$s1,0x2
/*  f0e5ff4:	01b16823 */ 	subu	$t5,$t5,$s1
/*  f0e5ff8:	028b0019 */ 	multu	$s4,$t3
/*  f0e5ffc:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e6000:	01b16823 */ 	subu	$t5,$t5,$s1
/*  f0e6004:	00006012 */ 	mflo	$t4
/*  f0e6008:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f0e600c:	00027400 */ 	sll	$t6,$v0,0x10
/*  f0e6010:	000e1403 */ 	sra	$v0,$t6,0x10
.L0f0e6014:
/*  f0e6014:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e6018:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0e601c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0e6020:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0e6024:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0e6028:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0e602c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0e6030:	03e00008 */ 	jr	$ra
/*  f0e6034:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f0e6038
/*  f0e6038:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0e603c:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0e6040:	8fb1006c */ 	lw	$s1,0x6c($sp)
/*  f0e6044:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e6048:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0e604c:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0e6050:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0e6054:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f0e6058:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0e605c:	44803000 */ 	mtc1	$zero,$f6
/*  f0e6060:	c6240040 */ 	lwc1	$f4,0x40($s1)
/*  f0e6064:	3c087f1b */ 	lui	$t0,%hi(var7f1b1fb0)
/*  f0e6068:	25081fb0 */ 	addiu	$t0,$t0,%lo(var7f1b1fb0)
/*  f0e606c:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e6070:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6074:	4502000a */ 	bc1fl	.L0f0e60a0
/*  f0e6078:	9238003d */ 	lbu	$t8,0x3d($s1)
/*  f0e607c:	922e003c */ 	lbu	$t6,0x3c($s1)
/*  f0e6080:	3c107f1b */ 	lui	$s0,%hi(var7f1b1fdc)
/*  f0e6084:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f0e6088:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0e608c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0e6090:	020f8021 */ 	addu	$s0,$s0,$t7
/*  f0e6094:	10000010 */ 	beqz	$zero,.L0f0e60d8
/*  f0e6098:	8e101fdc */ 	lw	$s0,%lo(var7f1b1fdc)($s0)
/*  f0e609c:	9238003d */ 	lbu	$t8,0x3d($s1)
.L0f0e60a0:
/*  f0e60a0:	922a003c */ 	lbu	$t2,0x3c($s1)
/*  f0e60a4:	8e260044 */ 	lw	$a2,0x44($s1)
/*  f0e60a8:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0e60ac:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f0e60b0:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0e60b4:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0e60b8:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0e60bc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0e60c0:	03284821 */ 	addu	$t1,$t9,$t0
/*  f0e60c4:	01686021 */ 	addu	$t4,$t3,$t0
/*  f0e60c8:	8d85002c */ 	lw	$a1,0x2c($t4)
/*  f0e60cc:	0fc01a40 */ 	jal	func0f006900
/*  f0e60d0:	8d24002c */ 	lw	$a0,0x2c($t1)
/*  f0e60d4:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e60d8:
/*  f0e60d8:	8e2d000c */ 	lw	$t5,0xc($s1)
/*  f0e60dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e60e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e60e4:	11a00007 */ 	beqz	$t5,.L0f0e6104
/*  f0e60e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e60ec:	0fc01a40 */ 	jal	func0f006900
/*  f0e60f0:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0e60f4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e60f8:	00417024 */ 	and	$t6,$v0,$at
/*  f0e60fc:	320f00ff */ 	andi	$t7,$s0,0xff
/*  f0e6100:	01cf8025 */ 	or	$s0,$t6,$t7
.L0f0e6104:
/*  f0e6104:	0fc54de0 */ 	jal	func0f153780
/*  f0e6108:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0e610c:	87a50056 */ 	lh	$a1,0x56($sp)
/*  f0e6110:	87a6005a */ 	lh	$a2,0x5a($sp)
/*  f0e6114:	87a90066 */ 	lh	$t1,0x66($sp)
/*  f0e6118:	87ab0062 */ 	lh	$t3,0x62($sp)
/*  f0e611c:	87b9005e */ 	lh	$t9,0x5e($sp)
/*  f0e6120:	320c00ff */ 	andi	$t4,$s0,0xff
/*  f0e6124:	00c95021 */ 	addu	$t2,$a2,$t1
/*  f0e6128:	00ab4021 */ 	addu	$t0,$a1,$t3
/*  f0e612c:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0e6130:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e6134:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0e6138:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e613c:	0fc38653 */ 	jal	func0f0e194c
/*  f0e6140:	00b93821 */ 	addu	$a3,$a1,$t9
/*  f0e6144:	0fc54d8a */ 	jal	func0f153628
/*  f0e6148:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e614c:	87ad0056 */ 	lh	$t5,0x56($sp)
/*  f0e6150:	87af005a */ 	lh	$t7,0x5a($sp)
/*  f0e6154:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f0e6158:	25ae0003 */ 	addiu	$t6,$t5,0x3
/*  f0e615c:	25f90002 */ 	addiu	$t9,$t7,0x2
/*  f0e6160:	afae004c */ 	sw	$t6,0x4c($sp)
/*  f0e6164:	afb90048 */ 	sw	$t9,0x48($sp)
/*  f0e6168:	c6280040 */ 	lwc1	$f8,0x40($s1)
/*  f0e616c:	44805000 */ 	mtc1	$zero,$f10
/*  f0e6170:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0e6174:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0e6178:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0e617c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6180:	4502000a */ 	bc1fl	.L0f0e61ac
/*  f0e6184:	922a003d */ 	lbu	$t2,0x3d($s1)
/*  f0e6188:	9238003c */ 	lbu	$t8,0x3c($s1)
/*  f0e618c:	3c107f1b */ 	lui	$s0,%hi(var7f1b1fe0)
/*  f0e6190:	00184900 */ 	sll	$t1,$t8,0x4
/*  f0e6194:	01384823 */ 	subu	$t1,$t1,$t8
/*  f0e6198:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0e619c:	02098021 */ 	addu	$s0,$s0,$t1
/*  f0e61a0:	10000010 */ 	beqz	$zero,.L0f0e61e4
/*  f0e61a4:	8e101fe0 */ 	lw	$s0,%lo(var7f1b1fe0)($s0)
/*  f0e61a8:	922a003d */ 	lbu	$t2,0x3d($s1)
.L0f0e61ac:
/*  f0e61ac:	922c003c */ 	lbu	$t4,0x3c($s1)
/*  f0e61b0:	8e260044 */ 	lw	$a2,0x44($s1)
/*  f0e61b4:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f0e61b8:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0e61bc:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0e61c0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0e61c4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e61c8:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0e61cc:	004b4021 */ 	addu	$t0,$v0,$t3
/*  f0e61d0:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0e61d4:	8dc50030 */ 	lw	$a1,0x30($t6)
/*  f0e61d8:	0fc01a40 */ 	jal	func0f006900
/*  f0e61dc:	8d040030 */ 	lw	$a0,0x30($t0)
/*  f0e61e0:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e61e4:
/*  f0e61e4:	8e2f000c */ 	lw	$t7,0xc($s1)
/*  f0e61e8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e61ec:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e61f0:	51e00008 */ 	beqzl	$t7,.L0f0e6214
/*  f0e61f4:	9222003c */ 	lbu	$v0,0x3c($s1)
/*  f0e61f8:	0fc01a40 */ 	jal	func0f006900
/*  f0e61fc:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0e6200:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e6204:	0041c824 */ 	and	$t9,$v0,$at
/*  f0e6208:	321800ff */ 	andi	$t8,$s0,0xff
/*  f0e620c:	03388025 */ 	or	$s0,$t9,$t8
/*  f0e6210:	9222003c */ 	lbu	$v0,0x3c($s1)
.L0f0e6214:
/*  f0e6214:	3c047f1b */ 	lui	$a0,%hi(var7f1b22b0)
/*  f0e6218:	3c057f1b */ 	lui	$a1,%hi(var7f1b2148)
/*  f0e621c:	00024900 */ 	sll	$t1,$v0,0x4
/*  f0e6220:	01224823 */ 	subu	$t1,$t1,$v0
/*  f0e6224:	00091080 */ 	sll	$v0,$t1,0x2
/*  f0e6228:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e622c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e6230:	8ca52148 */ 	lw	$a1,%lo(var7f1b2148)($a1)
/*  f0e6234:	0fc54f8e */ 	jal	func0f153e38
/*  f0e6238:	8c8422b0 */ 	lw	$a0,%lo(var7f1b22b0)($a0)
/*  f0e623c:	3c0a8008 */ 	lui	$t2,%hi(var8007fb10)
/*  f0e6240:	3c0b8008 */ 	lui	$t3,%hi(var8007fb0c)
/*  f0e6244:	8d6bfb0c */ 	lw	$t3,%lo(var8007fb0c)($t3)
/*  f0e6248:	8d4afb10 */ 	lw	$t2,%lo(var8007fb10)($t2)
/*  f0e624c:	87a8005e */ 	lh	$t0,0x5e($sp)
/*  f0e6250:	87ac0066 */ 	lh	$t4,0x66($sp)
/*  f0e6254:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0e6258:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0e625c:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f0e6260:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0e6264:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e6268:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e626c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e6270:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e6274:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e6278:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0e627c:	0fc5580f */ 	jal	func0f15603c
/*  f0e6280:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0e6284:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e6288:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0e628c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0e6290:	03e00008 */ 	jr	$ra
/*  f0e6294:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f0e6298
/*  f0e6298:	3c088008 */ 	lui	$t0,%hi(var8007fac0)
/*  f0e629c:	2508fac0 */ 	addiu	$t0,$t0,%lo(var8007fac0)
/*  f0e62a0:	8d0c0000 */ 	lw	$t4,0x0($t0)
/*  f0e62a4:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f0e62a8:	00057400 */ 	sll	$t6,$a1,0x10
/*  f0e62ac:	00074c00 */ 	sll	$t1,$a3,0x10
/*  f0e62b0:	00095403 */ 	sra	$t2,$t1,0x10
/*  f0e62b4:	000e2c03 */ 	sra	$a1,$t6,0x10
/*  f0e62b8:	00aa5821 */ 	addu	$t3,$a1,$t2
/*  f0e62bc:	016c0019 */ 	multu	$t3,$t4
/*  f0e62c0:	87b90012 */ 	lh	$t9,0x12($sp)
/*  f0e62c4:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f0e62c8:	00c0c025 */ 	or	$t8,$a2,$zero
/*  f0e62cc:	03003025 */ 	or	$a2,$t8,$zero
/*  f0e62d0:	00d94821 */ 	addu	$t1,$a2,$t9
/*  f0e62d4:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0e62d8:	3c01f600 */ 	lui	$at,0xf600
/*  f0e62dc:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f0e62e0:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f0e62e4:	00006812 */ 	mflo	$t5
/*  f0e62e8:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f0e62ec:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0e62f0:	01e1c025 */ 	or	$t8,$t7,$at
/*  f0e62f4:	030b6025 */ 	or	$t4,$t8,$t3
/*  f0e62f8:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f0e62fc:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f0e6300:	30c903ff */ 	andi	$t1,$a2,0x3ff
/*  f0e6304:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0e6308:	00ad0019 */ 	multu	$a1,$t5
/*  f0e630c:	24820008 */ 	addiu	$v0,$a0,0x8
/*  f0e6310:	00007012 */ 	mflo	$t6
/*  f0e6314:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0e6318:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f0e631c:	032ac025 */ 	or	$t8,$t9,$t2
/*  f0e6320:	03e00008 */ 	jr	$ra
/*  f0e6324:	ac980004 */ 	sw	$t8,0x4($a0)
);

GLOBAL_ASM(
glabel func0f0e6328
/*  f0e6328:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f0e632c:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f0e6330:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f0e6334:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f0e6338:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f0e633c:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f0e6340:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f0e6344:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f0e6348:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0e634c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0e6350:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0e6354:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0e6358:	afa00120 */ 	sw	$zero,0x120($sp)
/*  f0e635c:	3c0a8008 */ 	lui	$t2,%hi(var8007fb0c)
/*  f0e6360:	afae016c */ 	sw	$t6,0x16c($sp)
/*  f0e6364:	84af0000 */ 	lh	$t7,0x0($a1)
/*  f0e6368:	3c0b8008 */ 	lui	$t3,%hi(var8007fb10)
/*  f0e636c:	8d4afb0c */ 	lw	$t2,%lo(var8007fb0c)($t2)
/*  f0e6370:	8d6bfb10 */ 	lw	$t3,%lo(var8007fb10)($t3)
/*  f0e6374:	2419270f */ 	addiu	$t9,$zero,0x270f
/*  f0e6378:	25f80002 */ 	addiu	$t8,$t7,0x2
/*  f0e637c:	afb8011c */ 	sw	$t8,0x11c($sp)
/*  f0e6380:	afb900fc */ 	sw	$t9,0xfc($sp)
/*  f0e6384:	a3a000ed */ 	sb	$zero,0xed($sp)
/*  f0e6388:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0e638c:	afab00e8 */ 	sw	$t3,0xe8($sp)
/*  f0e6390:	8ca70008 */ 	lw	$a3,0x8($a1)
/*  f0e6394:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0e6398:	00809025 */ 	or	$s2,$a0,$zero
/*  f0e639c:	8cec0004 */ 	lw	$t4,0x4($a3)
/*  f0e63a0:	000c6a80 */ 	sll	$t5,$t4,0xa
/*  f0e63a4:	05a3000b */ 	bgezl	$t5,.L0f0e63d4
/*  f0e63a8:	240f000b */ 	addiu	$t7,$zero,0xb
/*  f0e63ac:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e63b0:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f0e63b4:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e63b8:	0320f809 */ 	jalr	$t9
/*  f0e63bc:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f0e63c0:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*  f0e63c4:	3c018007 */ 	lui	$at,%hi(var800711a8)
/*  f0e63c8:	10000004 */ 	beqz	$zero,.L0f0e63dc
/*  f0e63cc:	ac2e11a8 */ 	sw	$t6,%lo(var800711a8)($at)
/*  f0e63d0:	240f000b */ 	addiu	$t7,$zero,0xb
.L0f0e63d4:
/*  f0e63d4:	3c018007 */ 	lui	$at,%hi(var800711a8)
/*  f0e63d8:	ac2f11a8 */ 	sw	$t7,%lo(var800711a8)($at)
.L0f0e63dc:
/*  f0e63dc:	8e2a0008 */ 	lw	$t2,0x8($s1)
/*  f0e63e0:	8e380010 */ 	lw	$t8,0x10($s1)
/*  f0e63e4:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0e63e8:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f0e63ec:	8705001e */ 	lh	$a1,0x1e($t8)
/*  f0e63f0:	000b6200 */ 	sll	$t4,$t3,0x8
/*  f0e63f4:	05810002 */ 	bgez	$t4,.L0f0e6400
/*  f0e63f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e63fc:	86250004 */ 	lh	$a1,0x4($s1)
.L0f0e6400:
/*  f0e6400:	8c63fac0 */ 	lw	$v1,%lo(var8007fac0)($v1)
/*  f0e6404:	862d0000 */ 	lh	$t5,0x0($s1)
/*  f0e6408:	3c028007 */ 	lui	$v0,%hi(var80071190)
/*  f0e640c:	24421190 */ 	addiu	$v0,$v0,%lo(var80071190)
/*  f0e6410:	01a30019 */ 	multu	$t5,$v1
/*  f0e6414:	3c178007 */ 	lui	$s7,%hi(var80071194)
/*  f0e6418:	26f71194 */ 	addiu	$s7,$s7,%lo(var80071194)
/*  f0e641c:	3c048007 */ 	lui	$a0,%hi(var80071198)
/*  f0e6420:	24841198 */ 	addiu	$a0,$a0,%lo(var80071198)
/*  f0e6424:	3c1e8007 */ 	lui	$s8,%hi(var8007119c)
/*  f0e6428:	27de119c */ 	addiu	$s8,$s8,%lo(var8007119c)
/*  f0e642c:	0000c812 */ 	mflo	$t9
/*  f0e6430:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0e6434:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f0e6438:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0e643c:	01e30019 */ 	multu	$t7,$v1
/*  f0e6440:	0000c012 */ 	mflo	$t8
/*  f0e6444:	aef80000 */ 	sw	$t8,0x0($s7)
/*  f0e6448:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e644c:	ac8a0000 */ 	sw	$t2,0x0($a0)
/*  f0e6450:	862c0006 */ 	lh	$t4,0x6($s1)
/*  f0e6454:	862b0002 */ 	lh	$t3,0x2($s1)
/*  f0e6458:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f0e645c:	07210002 */ 	bgez	$t9,.L0f0e6468
/*  f0e6460:	afcd0000 */ 	sw	$t5,0x0($s8)
/*  f0e6464:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f0e6468:
/*  f0e6468:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0e646c:	05c30003 */ 	bgezl	$t6,.L0f0e647c
/*  f0e6470:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0e6474:	aee00000 */ 	sw	$zero,0x0($s7)
/*  f0e6478:	8c8f0000 */ 	lw	$t7,0x0($a0)
.L0f0e647c:
/*  f0e647c:	05e30003 */ 	bgezl	$t7,.L0f0e648c
/*  f0e6480:	8fd80000 */ 	lw	$t8,0x0($s8)
/*  f0e6484:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0e6488:	8fd80000 */ 	lw	$t8,0x0($s8)
.L0f0e648c:
/*  f0e648c:	07010002 */ 	bgez	$t8,.L0f0e6498
/*  f0e6490:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6494:	afc00000 */ 	sw	$zero,0x0($s8)
.L0f0e6498:
/*  f0e6498:	0c002ef1 */ 	jal	func0000bbc4
/*  f0e649c:	a7a500ee */ 	sh	$a1,0xee($sp)
/*  f0e64a0:	3c0a8007 */ 	lui	$t2,%hi(var80071190)
/*  f0e64a4:	8d4a1190 */ 	lw	$t2,%lo(var80071190)($t2)
/*  f0e64a8:	004a082a */ 	slt	$at,$v0,$t2
/*  f0e64ac:	10200005 */ 	beqz	$at,.L0f0e64c4
/*  f0e64b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e64b4:	0c002ef1 */ 	jal	func0000bbc4
/*  f0e64b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e64bc:	3c018007 */ 	lui	$at,%hi(var80071190)
/*  f0e64c0:	ac221190 */ 	sw	$v0,%lo(var80071190)($at)
.L0f0e64c4:
/*  f0e64c4:	0c002ef1 */ 	jal	func0000bbc4
/*  f0e64c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e64cc:	8eeb0000 */ 	lw	$t3,0x0($s7)
/*  f0e64d0:	004b082a */ 	slt	$at,$v0,$t3
/*  f0e64d4:	10200004 */ 	beqz	$at,.L0f0e64e8
/*  f0e64d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e64dc:	0c002ef1 */ 	jal	func0000bbc4
/*  f0e64e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e64e4:	aee20000 */ 	sw	$v0,0x0($s7)
.L0f0e64e8:
/*  f0e64e8:	0c002ef5 */ 	jal	func0000bbd4
/*  f0e64ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e64f0:	3c0c8007 */ 	lui	$t4,%hi(var80071198)
/*  f0e64f4:	8d8c1198 */ 	lw	$t4,%lo(var80071198)($t4)
/*  f0e64f8:	004c082a */ 	slt	$at,$v0,$t4
/*  f0e64fc:	10200005 */ 	beqz	$at,.L0f0e6514
/*  f0e6500:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6504:	0c002ef5 */ 	jal	func0000bbd4
/*  f0e6508:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e650c:	3c018007 */ 	lui	$at,%hi(var80071198)
/*  f0e6510:	ac221198 */ 	sw	$v0,%lo(var80071198)($at)
.L0f0e6514:
/*  f0e6514:	0c002ef5 */ 	jal	func0000bbd4
/*  f0e6518:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e651c:	8fc30000 */ 	lw	$v1,0x0($s8)
/*  f0e6520:	0043082a */ 	slt	$at,$v0,$v1
/*  f0e6524:	10200005 */ 	beqz	$at,.L0f0e653c
/*  f0e6528:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e652c:	0c002ef5 */ 	jal	func0000bbd4
/*  f0e6530:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6534:	afc20000 */ 	sw	$v0,0x0($s8)
/*  f0e6538:	00401825 */ 	or	$v1,$v0,$zero
.L0f0e653c:
/*  f0e653c:	3c098007 */ 	lui	$t1,%hi(var80071190)
/*  f0e6540:	8d291190 */ 	lw	$t1,%lo(var80071190)($t1)
/*  f0e6544:	8eed0000 */ 	lw	$t5,0x0($s7)
/*  f0e6548:	3c088007 */ 	lui	$t0,%hi(var80071198)
/*  f0e654c:	44892000 */ 	mtc1	$t1,$f4
/*  f0e6550:	01a9082a */ 	slt	$at,$t5,$t1
/*  f0e6554:	10200002 */ 	beqz	$at,.L0f0e6560
/*  f0e6558:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e655c:	aee90000 */ 	sw	$t1,0x0($s7)
.L0f0e6560:
/*  f0e6560:	8d081198 */ 	lw	$t0,%lo(var80071198)($t0)
/*  f0e6564:	0068082a */ 	slt	$at,$v1,$t0
/*  f0e6568:	50200003 */ 	beqzl	$at,.L0f0e6578
/*  f0e656c:	44888000 */ 	mtc1	$t0,$f16
/*  f0e6570:	afc80000 */ 	sw	$t0,0x0($s8)
/*  f0e6574:	44888000 */ 	mtc1	$t0,$f16
.L0f0e6578:
/*  f0e6578:	3c014080 */ 	lui	$at,0x4080
/*  f0e657c:	44810000 */ 	mtc1	$at,$f0
/*  f0e6580:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0e6584:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e6588:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0e658c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e6590:	3c058007 */ 	lui	$a1,%hi(var800711a8)
/*  f0e6594:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e6598:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0e659c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e65a0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e65a4:	440e5000 */ 	mfc1	$t6,$f10
/*  f0e65a8:	440c3000 */ 	mfc1	$t4,$f6
/*  f0e65ac:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f0e65b0:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0e65b4:	03015025 */ 	or	$t2,$t8,$at
/*  f0e65b8:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f0e65bc:	014dc825 */ 	or	$t9,$t2,$t5
/*  f0e65c0:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f0e65c4:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0e65c8:	8fca0000 */ 	lw	$t2,0x0($s8)
/*  f0e65cc:	448e4000 */ 	mtc1	$t6,$f8
/*  f0e65d0:	448a2000 */ 	mtc1	$t2,$f4
/*  f0e65d4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e65d8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e65dc:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0e65e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e65e4:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0e65e8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e65ec:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e65f0:	44189000 */ 	mfc1	$t8,$f18
/*  f0e65f4:	44195000 */ 	mfc1	$t9,$f10
/*  f0e65f8:	330b0fff */ 	andi	$t3,$t8,0xfff
/*  f0e65fc:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f0e6600:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f0e6604:	018e7825 */ 	or	$t7,$t4,$t6
/*  f0e6608:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0e660c:	86220006 */ 	lh	$v0,0x6($s1)
/*  f0e6610:	8ca511a8 */ 	lw	$a1,%lo(var800711a8)($a1)
/*  f0e6614:	8fb8016c */ 	lw	$t8,0x16c($sp)
/*  f0e6618:	04410003 */ 	bgez	$v0,.L0f0e6628
/*  f0e661c:	0002b043 */ 	sra	$s6,$v0,0x1
/*  f0e6620:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0e6624:	0001b043 */ 	sra	$s6,$at,0x1
.L0f0e6628:
/*  f0e6628:	02c5001a */ 	div	$zero,$s6,$a1
/*  f0e662c:	14a00002 */ 	bnez	$a1,.L0f0e6638
/*  f0e6630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6634:	0007000d */ 	break	0x7
.L0f0e6638:
/*  f0e6638:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e663c:	14a10004 */ 	bne	$a1,$at,.L0f0e6650
/*  f0e6640:	3c018000 */ 	lui	$at,0x8000
/*  f0e6644:	16c10002 */ 	bne	$s6,$at,.L0f0e6650
/*  f0e6648:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e664c:	0006000d */ 	break	0x6
.L0f0e6650:
/*  f0e6650:	0000b012 */ 	mflo	$s6
/*  f0e6654:	a7020006 */ 	sh	$v0,0x6($t8)
/*  f0e6658:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e665c:	02c50019 */ 	multu	$s6,$a1
/*  f0e6660:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0e6664:	90e30000 */ 	lbu	$v1,0x0($a3)
/*  f0e6668:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e666c:	0000b012 */ 	mflo	$s6
/*  f0e6670:	10610004 */ 	beq	$v1,$at,.L0f0e6684
/*  f0e6674:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6678:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0e667c:	54610050 */ 	bnel	$v1,$at,.L0f0e67c0
/*  f0e6680:	8cf90010 */ 	lw	$t9,0x10($a3)
.L0f0e6684:
/*  f0e6684:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e6688:	862a0006 */ 	lh	$t2,0x6($s1)
/*  f0e668c:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e6690:	862b0004 */ 	lh	$t3,0x4($s1)
/*  f0e6694:	00ca6821 */ 	addu	$t5,$a2,$t2
/*  f0e6698:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e669c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e66a0:	0fc3859a */ 	jal	func0f0e1668
/*  f0e66a4:	020b3821 */ 	addu	$a3,$s0,$t3
/*  f0e66a8:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e66ac:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e66b0:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0e66b4:	240e007f */ 	addiu	$t6,$zero,0x7f
/*  f0e66b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e66bc:	2418000f */ 	addiu	$t8,$zero,0xf
/*  f0e66c0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e66c4:	00d96021 */ 	addu	$t4,$a2,$t9
/*  f0e66c8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e66cc:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0e66d0:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e66d4:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e66d8:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e66dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e66e0:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e66e4:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0e66e8:	26070001 */ 	addiu	$a3,$s0,0x1
/*  f0e66ec:	862a0000 */ 	lh	$t2,0x0($s1)
/*  f0e66f0:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0e66f4:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e66f8:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0e66fc:	240e007f */ 	addiu	$t6,$zero,0x7f
/*  f0e6700:	240f000f */ 	addiu	$t7,$zero,0xf
/*  f0e6704:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0e6708:	014d2821 */ 	addu	$a1,$t2,$t5
/*  f0e670c:	00d96021 */ 	addu	$t4,$a2,$t9
/*  f0e6710:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e6714:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e6718:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0e671c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0e6720:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e6724:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e6728:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0e672c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6730:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e6734:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e6738:	862b0004 */ 	lh	$t3,0x4($s1)
/*  f0e673c:	240d007f */ 	addiu	$t5,$zero,0x7f
/*  f0e6740:	2419000f */ 	addiu	$t9,$zero,0xf
/*  f0e6744:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0e6748:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0e674c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e6750:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0e6754:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e6758:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e675c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e6760:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6764:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e6768:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0e676c:	020b3821 */ 	addu	$a3,$s0,$t3
/*  f0e6770:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e6774:	862e0002 */ 	lh	$t6,0x2($s1)
/*  f0e6778:	862f0006 */ 	lh	$t7,0x6($s1)
/*  f0e677c:	86380004 */ 	lh	$t8,0x4($s1)
/*  f0e6780:	240a007f */ 	addiu	$t2,$zero,0x7f
/*  f0e6784:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f0e6788:	24cb0001 */ 	addiu	$t3,$a2,0x1
/*  f0e678c:	240d000f */ 	addiu	$t5,$zero,0xf
/*  f0e6790:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e6794:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e6798:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e679c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0e67a0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e67a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e67a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e67ac:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0e67b0:	02183821 */ 	addu	$a3,$s0,$t8
/*  f0e67b4:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e67b8:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e67bc:	8cf90010 */ 	lw	$t9,0x10($a3)
.L0f0e67c0:
/*  f0e67c0:	57200004 */ 	bnezl	$t9,.L0f0e67d4
/*  f0e67c4:	afa0015c */ 	sw	$zero,0x15c($sp)
/*  f0e67c8:	10000369 */ 	beqz	$zero,.L0f0e7570
/*  f0e67cc:	02401025 */ 	or	$v0,$s2,$zero
/*  f0e67d0:	afa0015c */ 	sw	$zero,0x15c($sp)
.L0f0e67d4:
/*  f0e67d4:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e67d8:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0e67dc:	27a6015c */ 	addiu	$a2,$sp,0x15c
/*  f0e67e0:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e67e4:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e67e8:	0320f809 */ 	jalr	$t9
/*  f0e67ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e67f0:	8fa8015c */ 	lw	$t0,0x15c($sp)
/*  f0e67f4:	3c010001 */ 	lui	$at,0x1
/*  f0e67f8:	0101082b */ 	sltu	$at,$t0,$at
/*  f0e67fc:	54200003 */ 	bnezl	$at,.L0f0e680c
/*  f0e6800:	862c0002 */ 	lh	$t4,0x2($s1)
/*  f0e6804:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0e6808:	862c0002 */ 	lh	$t4,0x2($s1)
.L0f0e680c:
/*  f0e680c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0e6810:	27a6015c */ 	addiu	$a2,$sp,0x15c
/*  f0e6814:	258e0001 */ 	addiu	$t6,$t4,0x1
/*  f0e6818:	afae0104 */ 	sw	$t6,0x104($sp)
/*  f0e681c:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e6820:	afa800f0 */ 	sw	$t0,0xf0($sp)
/*  f0e6824:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e6828:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e682c:	0320f809 */ 	jalr	$t9
/*  f0e6830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6834:	8faf015c */ 	lw	$t7,0x15c($sp)
/*  f0e6838:	8fb8016c */ 	lw	$t8,0x16c($sp)
/*  f0e683c:	afaf0108 */ 	sw	$t7,0x108($sp)
/*  f0e6840:	870b0000 */ 	lh	$t3,0x0($t8)
/*  f0e6844:	8e250008 */ 	lw	$a1,0x8($s1)
/*  f0e6848:	01762023 */ 	subu	$a0,$t3,$s6
/*  f0e684c:	0fc3974b */ 	jal	func0f0e5d2c
/*  f0e6850:	00808025 */ 	or	$s0,$a0,$zero
/*  f0e6854:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e6858:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0e685c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e6860:	01506821 */ 	addu	$t5,$t2,$s0
/*  f0e6864:	0fc54d8a */ 	jal	func0f153628
/*  f0e6868:	afad012c */ 	sw	$t5,0x12c($sp)
/*  f0e686c:	00152400 */ 	sll	$a0,$s5,0x10
/*  f0e6870:	afa00160 */ 	sw	$zero,0x160($sp)
/*  f0e6874:	00046403 */ 	sra	$t4,$a0,0x10
/*  f0e6878:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e687c:	02a09825 */ 	or	$s3,$s5,$zero
/*  f0e6880:	01802025 */ 	or	$a0,$t4,$zero
/*  f0e6884:	0fc397be */ 	jal	func0f0e5ef8
/*  f0e6888:	8e250008 */ 	lw	$a1,0x8($s1)
/*  f0e688c:	8fb9016c */ 	lw	$t9,0x16c($sp)
/*  f0e6890:	00567021 */ 	addu	$t6,$v0,$s6
/*  f0e6894:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0e6898:	872f0000 */ 	lh	$t7,0x0($t9)
/*  f0e689c:	afa0014c */ 	sw	$zero,0x14c($sp)
/*  f0e68a0:	afa00158 */ 	sw	$zero,0x158($sp)
/*  f0e68a4:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e68a8:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e68ac:	01cfa023 */ 	subu	$s4,$t6,$t7
/*  f0e68b0:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e68b4:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e68b8:	0320f809 */ 	jalr	$t9
/*  f0e68bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e68c0:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0e68c4:	8fa3014c */ 	lw	$v1,0x14c($sp)
/*  f0e68c8:	1b0002d7 */ 	blez	$t8,.L0f0e7428
/*  f0e68cc:	afa30100 */ 	sw	$v1,0x100($sp)
/*  f0e68d0:	1060005d */ 	beqz	$v1,.L0f0e6a48
/*  f0e68d4:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e68d8:	00004025 */ 	or	$t0,$zero,$zero
/*  f0e68dc:	afa000fc */ 	sw	$zero,0xfc($sp)
/*  f0e68e0:	afa0014c */ 	sw	$zero,0x14c($sp)
/*  f0e68e4:	1860001a */ 	blez	$v1,.L0f0e6950
/*  f0e68e8:	afa00150 */ 	sw	$zero,0x150($sp)
/*  f0e68ec:	8e270008 */ 	lw	$a3,0x8($s1)
.L0f0e68f0:
/*  f0e68f0:	afa800c8 */ 	sw	$t0,0xc8($sp)
/*  f0e68f4:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e68f8:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e68fc:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e6900:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e6904:	0320f809 */ 	jalr	$t9
/*  f0e6908:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e690c:	8fa30154 */ 	lw	$v1,0x154($sp)
/*  f0e6910:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*  f0e6914:	02a3082a */ 	slt	$at,$s5,$v1
/*  f0e6918:	54200007 */ 	bnezl	$at,.L0f0e6938
/*  f0e691c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e6920:	8fa8014c */ 	lw	$t0,0x14c($sp)
/*  f0e6924:	afa300fc */ 	sw	$v1,0xfc($sp)
/*  f0e6928:	250d0001 */ 	addiu	$t5,$t0,0x1
/*  f0e692c:	10000002 */ 	beqz	$zero,.L0f0e6938
/*  f0e6930:	afad014c */ 	sw	$t5,0x14c($sp)
/*  f0e6934:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0e6938:
/*  f0e6938:	16000005 */ 	bnez	$s0,.L0f0e6950
/*  f0e693c:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f0e6940:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f0e6944:	018e082a */ 	slt	$at,$t4,$t6
/*  f0e6948:	5420ffe9 */ 	bnezl	$at,.L0f0e68f0
/*  f0e694c:	8e270008 */ 	lw	$a3,0x8($s1)
.L0f0e6950:
/*  f0e6950:	8fb800fc */ 	lw	$t8,0xfc($sp)
/*  f0e6954:	8faf0158 */ 	lw	$t7,0x158($sp)
/*  f0e6958:	afa8013c */ 	sw	$t0,0x13c($sp)
/*  f0e695c:	0315082a */ 	slt	$at,$t8,$s5
/*  f0e6960:	afa00140 */ 	sw	$zero,0x140($sp)
/*  f0e6964:	14200004 */ 	bnez	$at,.L0f0e6978
/*  f0e6968:	afaf0148 */ 	sw	$t7,0x148($sp)
/*  f0e696c:	2a81000b */ 	slti	$at,$s4,0xb
/*  f0e6970:	50200036 */ 	beqzl	$at,.L0f0e6a4c
/*  f0e6974:	8faa00fc */ 	lw	$t2,0xfc($sp)
.L0f0e6978:
/*  f0e6978:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e697c:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0e6980:	27a6013c */ 	addiu	$a2,$sp,0x13c
/*  f0e6984:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e6988:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e698c:	0320f809 */ 	jalr	$t9
/*  f0e6990:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6994:	3c0b8007 */ 	lui	$t3,%hi(var800711a8)
/*  f0e6998:	8d6b11a8 */ 	lw	$t3,%lo(var800711a8)($t3)
/*  f0e699c:	87ad00ee */ 	lh	$t5,0xee($sp)
/*  f0e69a0:	240c000b */ 	addiu	$t4,$zero,0xb
/*  f0e69a4:	028b5021 */ 	addu	$t2,$s4,$t3
/*  f0e69a8:	5940000f */ 	blezl	$t2,.L0f0e69e8
/*  f0e69ac:	8fb80104 */ 	lw	$t8,0x104($sp)
/*  f0e69b0:	86250000 */ 	lh	$a1,0x0($s1)
/*  f0e69b4:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e69b8:	86270004 */ 	lh	$a3,0x4($s1)
/*  f0e69bc:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0e69c0:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e69c4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e69c8:	8e2e0010 */ 	lw	$t6,0x10($s1)
/*  f0e69cc:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e69d0:	0fc3980e */ 	jal	func0f0e6038
/*  f0e69d4:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0e69d8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e69dc:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e69e0:	a3af00ed */ 	sb	$t7,0xed($sp)
/*  f0e69e4:	8fb80104 */ 	lw	$t8,0x104($sp)
.L0f0e69e8:
/*  f0e69e8:	8fab013c */ 	lw	$t3,0x13c($sp)
/*  f0e69ec:	8fad014c */ 	lw	$t5,0x14c($sp)
/*  f0e69f0:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f0e69f4:	2719000b */ 	addiu	$t9,$t8,0xb
/*  f0e69f8:	256a0001 */ 	addiu	$t2,$t3,0x1
/*  f0e69fc:	01ac082a */ 	slt	$at,$t5,$t4
/*  f0e6a00:	afb90104 */ 	sw	$t9,0x104($sp)
/*  f0e6a04:	1020000e */ 	beqz	$at,.L0f0e6a40
/*  f0e6a08:	afaa013c */ 	sw	$t2,0x13c($sp)
/*  f0e6a0c:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e6a10:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e6a14:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e6a18:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e6a1c:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e6a20:	0320f809 */ 	jalr	$t9
/*  f0e6a24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6a28:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0e6a2c:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e6a30:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f0e6a34:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f0e6a38:	10000003 */ 	beqz	$zero,.L0f0e6a48
/*  f0e6a3c:	afae00fc */ 	sw	$t6,0xfc($sp)
.L0f0e6a40:
/*  f0e6a40:	240b270f */ 	addiu	$t3,$zero,0x270f
/*  f0e6a44:	afab00fc */ 	sw	$t3,0xfc($sp)
.L0f0e6a48:
/*  f0e6a48:	8faa00fc */ 	lw	$t2,0xfc($sp)
.L0f0e6a4c:
/*  f0e6a4c:	3c167f1b */ 	lui	$s6,%hi(var7f1b1fb0)
/*  f0e6a50:	26d61fb0 */ 	addiu	$s6,$s6,%lo(var7f1b1fb0)
/*  f0e6a54:	56aa0003 */ 	bnel	$s5,$t2,.L0f0e6a64
/*  f0e6a58:	2415003c */ 	addiu	$s5,$zero,0x3c
/*  f0e6a5c:	2694fff5 */ 	addiu	$s4,$s4,-11
/*  f0e6a60:	2415003c */ 	addiu	$s5,$zero,0x3c
.L0f0e6a64:
/*  f0e6a64:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0e6a68:
/*  f0e6a68:	44809000 */ 	mtc1	$zero,$f18
/*  f0e6a6c:	c4700040 */ 	lwc1	$f16,0x40($v1)
/*  f0e6a70:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0e6a74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6a78:	45020008 */ 	bc1fl	.L0f0e6a9c
/*  f0e6a7c:	906e003d */ 	lbu	$t6,0x3d($v1)
/*  f0e6a80:	906d003c */ 	lbu	$t5,0x3c($v1)
/*  f0e6a84:	01b50019 */ 	multu	$t5,$s5
/*  f0e6a88:	00006012 */ 	mflo	$t4
/*  f0e6a8c:	02ccc821 */ 	addu	$t9,$s6,$t4
/*  f0e6a90:	1000000f */ 	beqz	$zero,.L0f0e6ad0
/*  f0e6a94:	8f300018 */ 	lw	$s0,0x18($t9)
/*  f0e6a98:	906e003d */ 	lbu	$t6,0x3d($v1)
.L0f0e6a9c:
/*  f0e6a9c:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0e6aa0:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e6aa4:	01d50019 */ 	multu	$t6,$s5
/*  f0e6aa8:	00007812 */ 	mflo	$t7
/*  f0e6aac:	02cfc021 */ 	addu	$t8,$s6,$t7
/*  f0e6ab0:	8f040018 */ 	lw	$a0,0x18($t8)
/*  f0e6ab4:	01750019 */ 	multu	$t3,$s5
/*  f0e6ab8:	00005012 */ 	mflo	$t2
/*  f0e6abc:	02ca6821 */ 	addu	$t5,$s6,$t2
/*  f0e6ac0:	0fc01a40 */ 	jal	func0f006900
/*  f0e6ac4:	8da50018 */ 	lw	$a1,0x18($t5)
/*  f0e6ac8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e6acc:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0e6ad0:
/*  f0e6ad0:	8c6c000c */ 	lw	$t4,0xc($v1)
/*  f0e6ad4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e6ad8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e6adc:	51800009 */ 	beqzl	$t4,.L0f0e6b04
/*  f0e6ae0:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0e6ae4:	0fc01a40 */ 	jal	func0f006900
/*  f0e6ae8:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e6aec:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e6af0:	0041c824 */ 	and	$t9,$v0,$at
/*  f0e6af4:	320e00ff */ 	andi	$t6,$s0,0xff
/*  f0e6af8:	032e8025 */ 	or	$s0,$t9,$t6
/*  f0e6afc:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e6b00:	906f003c */ 	lbu	$t7,0x3c($v1)
.L0f0e6b04:
/*  f0e6b04:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0e6b08:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0e6b0c:	01f50019 */ 	multu	$t7,$s5
/*  f0e6b10:	00001012 */ 	mflo	$v0
/*  f0e6b14:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e6b18:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e6b1c:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0e6b20:	0fc54f8e */ 	jal	func0f153e38
/*  f0e6b24:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
/*  f0e6b28:	8fb800fc */ 	lw	$t8,0xfc($sp)
/*  f0e6b2c:	8faa0108 */ 	lw	$t2,0x108($sp)
/*  f0e6b30:	1678003f */ 	bne	$s3,$t8,.L0f0e6c30
/*  f0e6b34:	026a082a */ 	slt	$at,$s3,$t2
/*  f0e6b38:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e6b3c:	8ceb0004 */ 	lw	$t3,0x4($a3)
/*  f0e6b40:	000b5280 */ 	sll	$t2,$t3,0xa
/*  f0e6b44:	05430006 */ 	bgezl	$t2,.L0f0e6b60
/*  f0e6b48:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e6b4c:	0fc3d43f */ 	jal	func0f0f50fc
/*  f0e6b50:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e6b54:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e6b58:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e6b5c:	8cf90010 */ 	lw	$t9,0x10($a3)
.L0f0e6b60:
/*  f0e6b60:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0e6b64:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e6b68:	0320f809 */ 	jalr	$t9
/*  f0e6b6c:	27a6013c */ 	addiu	$a2,$sp,0x13c
/*  f0e6b70:	8fad013c */ 	lw	$t5,0x13c($sp)
/*  f0e6b74:	00404025 */ 	or	$t0,$v0,$zero
/*  f0e6b78:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e6b7c:	25ac0001 */ 	addiu	$t4,$t5,0x1
/*  f0e6b80:	afac013c */ 	sw	$t4,0x13c($sp)
/*  f0e6b84:	862e0006 */ 	lh	$t6,0x6($s1)
/*  f0e6b88:	87aa00ee */ 	lh	$t2,0xee($sp)
/*  f0e6b8c:	01d41823 */ 	subu	$v1,$t6,$s4
/*  f0e6b90:	2861000c */ 	slti	$at,$v1,0xc
/*  f0e6b94:	54200003 */ 	bnezl	$at,.L0f0e6ba4
/*  f0e6b98:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0e6b9c:	2403000b */ 	addiu	$v1,$zero,0xb
/*  f0e6ba0:	862f0002 */ 	lh	$t7,0x2($s1)
.L0f0e6ba4:
/*  f0e6ba4:	86250000 */ 	lh	$a1,0x0($s1)
/*  f0e6ba8:	86270004 */ 	lh	$a3,0x4($s1)
/*  f0e6bac:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0e6bb0:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e6bb4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e6bb8:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e6bbc:	01f43021 */ 	addu	$a2,$t7,$s4
/*  f0e6bc0:	0006c400 */ 	sll	$t8,$a2,0x10
/*  f0e6bc4:	00183403 */ 	sra	$a2,$t8,0x10
/*  f0e6bc8:	0fc3980e */ 	jal	func0f0e6038
/*  f0e6bcc:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e6bd0:	8fad014c */ 	lw	$t5,0x14c($sp)
/*  f0e6bd4:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f0e6bd8:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e6bdc:	240b270f */ 	addiu	$t3,$zero,0x270f
/*  f0e6be0:	01ac082a */ 	slt	$at,$t5,$t4
/*  f0e6be4:	50200010 */ 	beqzl	$at,.L0f0e6c28
/*  f0e6be8:	afab00fc */ 	sw	$t3,0xfc($sp)
/*  f0e6bec:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e6bf0:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e6bf4:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e6bf8:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e6bfc:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e6c00:	0320f809 */ 	jalr	$t9
/*  f0e6c04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6c08:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0e6c0c:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e6c10:	2694000b */ 	addiu	$s4,$s4,0xb
/*  f0e6c14:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f0e6c18:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f0e6c1c:	100001f5 */ 	beqz	$zero,.L0f0e73f4
/*  f0e6c20:	afae00fc */ 	sw	$t6,0xfc($sp)
/*  f0e6c24:	afab00fc */ 	sw	$t3,0xfc($sp)
.L0f0e6c28:
/*  f0e6c28:	100001f2 */ 	beqz	$zero,.L0f0e73f4
/*  f0e6c2c:	2694000b */ 	addiu	$s4,$s4,0xb
.L0f0e6c30:
/*  f0e6c30:	502001e8 */ 	beqzl	$at,.L0f0e73d4
/*  f0e6c34:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0e6c38:	8fad00f0 */ 	lw	$t5,0xf0($sp)
/*  f0e6c3c:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f0e6c40:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e6c44:	15b30003 */ 	bne	$t5,$s3,.L0f0e6c54
/*  f0e6c48:	8fb9016c */ 	lw	$t9,0x16c($sp)
/*  f0e6c4c:	02016025 */ 	or	$t4,$s0,$at
/*  f0e6c50:	01808025 */ 	or	$s0,$t4,$zero
.L0f0e6c54:
/*  f0e6c54:	872e0002 */ 	lh	$t6,0x2($t9)
/*  f0e6c58:	566e0069 */ 	bnel	$s3,$t6,.L0f0e6e00
/*  f0e6c5c:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0e6c60:	8e2f000c */ 	lw	$t7,0xc($s1)
/*  f0e6c64:	3c014220 */ 	lui	$at,0x4220
/*  f0e6c68:	51e00065 */ 	beqzl	$t7,.L0f0e6e00
/*  f0e6c6c:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0e6c70:	44816000 */ 	mtc1	$at,$f12
/*  f0e6c74:	0fc01ac2 */ 	jal	func0f006b08
/*  f0e6c78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6c7c:	3c01437f */ 	lui	$at,0x437f
/*  f0e6c80:	44812000 */ 	mtc1	$at,$f4
/*  f0e6c84:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e6c88:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e6c8c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0e6c90:	4458f800 */ 	cfc1	$t8,$31
/*  f0e6c94:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e6c98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6c9c:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0e6ca0:	444bf800 */ 	cfc1	$t3,$31
/*  f0e6ca4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6ca8:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e6cac:	51600013 */ 	beqzl	$t3,.L0f0e6cfc
/*  f0e6cb0:	440b4000 */ 	mfc1	$t3,$f8
/*  f0e6cb4:	44814000 */ 	mtc1	$at,$f8
/*  f0e6cb8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e6cbc:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0e6cc0:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e6cc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6cc8:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0e6ccc:	444bf800 */ 	cfc1	$t3,$31
/*  f0e6cd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6cd4:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e6cd8:	15600005 */ 	bnez	$t3,.L0f0e6cf0
/*  f0e6cdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6ce0:	440b4000 */ 	mfc1	$t3,$f8
/*  f0e6ce4:	3c018000 */ 	lui	$at,0x8000
/*  f0e6ce8:	10000007 */ 	beqz	$zero,.L0f0e6d08
/*  f0e6cec:	01615825 */ 	or	$t3,$t3,$at
.L0f0e6cf0:
/*  f0e6cf0:	10000005 */ 	beqz	$zero,.L0f0e6d08
/*  f0e6cf4:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0e6cf8:	440b4000 */ 	mfc1	$t3,$f8
.L0f0e6cfc:
/*  f0e6cfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6d00:	0560fffb */ 	bltz	$t3,.L0f0e6cf0
/*  f0e6d04:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0e6d08:
/*  f0e6d08:	afab00ac */ 	sw	$t3,0xac($sp)
/*  f0e6d0c:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e6d10:	44d8f800 */ 	ctc1	$t8,$31
/*  f0e6d14:	44808000 */ 	mtc1	$zero,$f16
/*  f0e6d18:	c46a0040 */ 	lwc1	$f10,0x40($v1)
/*  f0e6d1c:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0e6d20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6d24:	45020008 */ 	bc1fl	.L0f0e6d48
/*  f0e6d28:	9079003d */ 	lbu	$t9,0x3d($v1)
/*  f0e6d2c:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0e6d30:	01550019 */ 	multu	$t2,$s5
/*  f0e6d34:	00006812 */ 	mflo	$t5
/*  f0e6d38:	02cd6021 */ 	addu	$t4,$s6,$t5
/*  f0e6d3c:	1000000e */ 	beqz	$zero,.L0f0e6d78
/*  f0e6d40:	8d870020 */ 	lw	$a3,0x20($t4)
/*  f0e6d44:	9079003d */ 	lbu	$t9,0x3d($v1)
.L0f0e6d48:
/*  f0e6d48:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e6d4c:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e6d50:	03350019 */ 	multu	$t9,$s5
/*  f0e6d54:	00007012 */ 	mflo	$t6
/*  f0e6d58:	02ce7821 */ 	addu	$t7,$s6,$t6
/*  f0e6d5c:	8de40020 */ 	lw	$a0,0x20($t7)
/*  f0e6d60:	03150019 */ 	multu	$t8,$s5
/*  f0e6d64:	00005812 */ 	mflo	$t3
/*  f0e6d68:	02cb5021 */ 	addu	$t2,$s6,$t3
/*  f0e6d6c:	0fc01a40 */ 	jal	func0f006900
/*  f0e6d70:	8d450020 */ 	lw	$a1,0x20($t2)
/*  f0e6d74:	00403825 */ 	or	$a3,$v0,$zero
.L0f0e6d78:
/*  f0e6d78:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e6d7c:	320500ff */ 	andi	$a1,$s0,0xff
/*  f0e6d80:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e6d84:	0fc01a40 */ 	jal	func0f006900
/*  f0e6d88:	afa700b0 */ 	sw	$a3,0xb0($sp)
/*  f0e6d8c:	8fa500b0 */ 	lw	$a1,0xb0($sp)
/*  f0e6d90:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6d94:	0fc01a40 */ 	jal	func0f006900
/*  f0e6d98:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e6d9c:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e6da0:	44809000 */ 	mtc1	$zero,$f18
/*  f0e6da4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e6da8:	c4600040 */ 	lwc1	$f0,0x40($v1)
/*  f0e6dac:	4600903e */ 	c.le.s	$f18,$f0
/*  f0e6db0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6db4:	45020005 */ 	bc1fl	.L0f0e6dcc
/*  f0e6db8:	44802000 */ 	mtc1	$zero,$f4
/*  f0e6dbc:	906d003d */ 	lbu	$t5,0x3d($v1)
/*  f0e6dc0:	51a0000f */ 	beqzl	$t5,.L0f0e6e00
/*  f0e6dc4:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0e6dc8:	44802000 */ 	mtc1	$zero,$f4
.L0f0e6dcc:
/*  f0e6dcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6dd0:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0e6dd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6dd8:	45000004 */ 	bc1f	.L0f0e6dec
/*  f0e6ddc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6de0:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0e6de4:	51800006 */ 	beqzl	$t4,.L0f0e6e00
/*  f0e6de8:	8e2e0008 */ 	lw	$t6,0x8($s1)
.L0f0e6dec:
/*  f0e6dec:	0fc55809 */ 	jal	func0f156024
/*  f0e6df0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0e6df4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0e6df8:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f0e6dfc:	8e2e0008 */ 	lw	$t6,0x8($s1)
.L0f0e6e00:
/*  f0e6e00:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f0e6e04:	000fc280 */ 	sll	$t8,$t7,0xa
/*  f0e6e08:	07030116 */ 	bgezl	$t8,.L0f0e7264
/*  f0e6e0c:	afb3015c */ 	sw	$s3,0x15c($sp)
/*  f0e6e10:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0e6e14:	8fb9016c */ 	lw	$t9,0x16c($sp)
/*  f0e6e18:	3c0d8007 */ 	lui	$t5,%hi(var800711a8)
/*  f0e6e1c:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0e6e20:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e6e24:	8dad11a8 */ 	lw	$t5,%lo(var800711a8)($t5)
/*  f0e6e28:	8fb80098 */ 	lw	$t8,0x98($sp)
/*  f0e6e2c:	01542821 */ 	addu	$a1,$t2,$s4
/*  f0e6e30:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0e6e34:	862c0004 */ 	lh	$t4,0x4($s1)
/*  f0e6e38:	afb000a4 */ 	sw	$s0,0xa4($sp)
/*  f0e6e3c:	afac00a0 */ 	sw	$t4,0xa0($sp)
/*  f0e6e40:	872e0002 */ 	lh	$t6,0x2($t9)
/*  f0e6e44:	008c1821 */ 	addu	$v1,$a0,$t4
/*  f0e6e48:	00ad6021 */ 	addu	$t4,$a1,$t5
/*  f0e6e4c:	026e7826 */ 	xor	$t7,$s3,$t6
/*  f0e6e50:	2def0001 */ 	sltiu	$t7,$t7,0x1
/*  f0e6e54:	a3af00a8 */ 	sb	$t7,0xa8($sp)
/*  f0e6e58:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0e6e5c:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e6e60:	27b90098 */ 	addiu	$t9,$sp,0x98
/*  f0e6e64:	00603825 */ 	or	$a3,$v1,$zero
/*  f0e6e68:	00a6082a */ 	slt	$at,$a1,$a2
/*  f0e6e6c:	afb90068 */ 	sw	$t9,0x68($sp)
/*  f0e6e70:	10200002 */ 	beqz	$at,.L0f0e6e7c
/*  f0e6e74:	93af00ed */ 	lbu	$t7,0xed($sp)
/*  f0e6e78:	00c02825 */ 	or	$a1,$a2,$zero
.L0f0e6e7c:
/*  f0e6e7c:	862e0006 */ 	lh	$t6,0x6($s1)
/*  f0e6e80:	8fb00088 */ 	lw	$s0,0x88($sp)
/*  f0e6e84:	00ce1021 */ 	addu	$v0,$a2,$t6
/*  f0e6e88:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0e6e8c:	0050082a */ 	slt	$at,$v0,$s0
/*  f0e6e90:	10200002 */ 	beqz	$at,.L0f0e6e9c
/*  f0e6e94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6e98:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e6e9c:
/*  f0e6e9c:	11e00005 */ 	beqz	$t7,.L0f0e6eb4
/*  f0e6ea0:	24c2000b */ 	addiu	$v0,$a2,0xb
/*  f0e6ea4:	00a2082a */ 	slt	$at,$a1,$v0
/*  f0e6ea8:	10200002 */ 	beqz	$at,.L0f0e6eb4
/*  f0e6eac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6eb0:	00402825 */ 	or	$a1,$v0,$zero
.L0f0e6eb4:
/*  f0e6eb4:	07010002 */ 	bgez	$t8,.L0f0e6ec0
/*  f0e6eb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6ebc:	00002025 */ 	or	$a0,$zero,$zero
.L0f0e6ec0:
/*  f0e6ec0:	04630003 */ 	bgezl	$v1,.L0f0e6ed0
/*  f0e6ec4:	afa40094 */ 	sw	$a0,0x94($sp)
/*  f0e6ec8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e6ecc:	afa40094 */ 	sw	$a0,0x94($sp)
.L0f0e6ed0:
/*  f0e6ed0:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0e6ed4:	0c002f02 */ 	jal	func0000bc08
/*  f0e6ed8:	afa7008c */ 	sw	$a3,0x8c($sp)
/*  f0e6edc:	3c0a8008 */ 	lui	$t2,%hi(var8007fac0)
/*  f0e6ee0:	8d4afac0 */ 	lw	$t2,%lo(var8007fac0)($t2)
/*  f0e6ee4:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0e6ee8:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0e6eec:	8fa7008c */ 	lw	$a3,0x8c($sp)
/*  f0e6ef0:	008a001a */ 	div	$zero,$a0,$t2
/*  f0e6ef4:	15400002 */ 	bnez	$t2,.L0f0e6f00
/*  f0e6ef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6efc:	0007000d */ 	break	0x7
.L0f0e6f00:
/*  f0e6f00:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e6f04:	15410004 */ 	bne	$t2,$at,.L0f0e6f18
/*  f0e6f08:	3c018000 */ 	lui	$at,0x8000
/*  f0e6f0c:	14810002 */ 	bne	$a0,$at,.L0f0e6f18
/*  f0e6f10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6f14:	0006000d */ 	break	0x6
.L0f0e6f18:
/*  f0e6f18:	00006812 */ 	mflo	$t5
/*  f0e6f1c:	004d082a */ 	slt	$at,$v0,$t5
/*  f0e6f20:	50200014 */ 	beqzl	$at,.L0f0e6f74
/*  f0e6f24:	afa40094 */ 	sw	$a0,0x94($sp)
/*  f0e6f28:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0e6f2c:	0c002f02 */ 	jal	func0000bc08
/*  f0e6f30:	afa7008c */ 	sw	$a3,0x8c($sp)
/*  f0e6f34:	3c198008 */ 	lui	$t9,%hi(var8007fac0)
/*  f0e6f38:	8f39fac0 */ 	lw	$t9,%lo(var8007fac0)($t9)
/*  f0e6f3c:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0e6f40:	8fa7008c */ 	lw	$a3,0x8c($sp)
/*  f0e6f44:	0059001a */ 	div	$zero,$v0,$t9
/*  f0e6f48:	00002012 */ 	mflo	$a0
/*  f0e6f4c:	17200002 */ 	bnez	$t9,.L0f0e6f58
/*  f0e6f50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6f54:	0007000d */ 	break	0x7
.L0f0e6f58:
/*  f0e6f58:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e6f5c:	17210004 */ 	bne	$t9,$at,.L0f0e6f70
/*  f0e6f60:	3c018000 */ 	lui	$at,0x8000
/*  f0e6f64:	14410002 */ 	bne	$v0,$at,.L0f0e6f70
/*  f0e6f68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6f6c:	0006000d */ 	break	0x6
.L0f0e6f70:
/*  f0e6f70:	afa40094 */ 	sw	$a0,0x94($sp)
.L0f0e6f74:
/*  f0e6f74:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0e6f78:	0c002f02 */ 	jal	func0000bc08
/*  f0e6f7c:	afa7008c */ 	sw	$a3,0x8c($sp)
/*  f0e6f80:	3c0b8008 */ 	lui	$t3,%hi(var8007fac0)
/*  f0e6f84:	8d6bfac0 */ 	lw	$t3,%lo(var8007fac0)($t3)
/*  f0e6f88:	8fa7008c */ 	lw	$a3,0x8c($sp)
/*  f0e6f8c:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0e6f90:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0e6f94:	00eb001a */ 	div	$zero,$a3,$t3
/*  f0e6f98:	15600002 */ 	bnez	$t3,.L0f0e6fa4
/*  f0e6f9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6fa0:	0007000d */ 	break	0x7
.L0f0e6fa4:
/*  f0e6fa4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e6fa8:	15610004 */ 	bne	$t3,$at,.L0f0e6fbc
/*  f0e6fac:	3c018000 */ 	lui	$at,0x8000
/*  f0e6fb0:	14e10002 */ 	bne	$a3,$at,.L0f0e6fbc
/*  f0e6fb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6fb8:	0006000d */ 	break	0x6
.L0f0e6fbc:
/*  f0e6fbc:	00006012 */ 	mflo	$t4
/*  f0e6fc0:	004c082a */ 	slt	$at,$v0,$t4
/*  f0e6fc4:	50200014 */ 	beqzl	$at,.L0f0e7018
/*  f0e6fc8:	02401025 */ 	or	$v0,$s2,$zero
/*  f0e6fcc:	afa40094 */ 	sw	$a0,0x94($sp)
/*  f0e6fd0:	0c002f02 */ 	jal	func0000bc08
/*  f0e6fd4:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0e6fd8:	3c0e8008 */ 	lui	$t6,%hi(var8007fac0)
/*  f0e6fdc:	8dcefac0 */ 	lw	$t6,%lo(var8007fac0)($t6)
/*  f0e6fe0:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0e6fe4:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0e6fe8:	004e001a */ 	div	$zero,$v0,$t6
/*  f0e6fec:	00003812 */ 	mflo	$a3
/*  f0e6ff0:	15c00002 */ 	bnez	$t6,.L0f0e6ffc
/*  f0e6ff4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6ff8:	0007000d */ 	break	0x7
.L0f0e6ffc:
/*  f0e6ffc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e7000:	15c10004 */ 	bne	$t6,$at,.L0f0e7014
/*  f0e7004:	3c018000 */ 	lui	$at,0x8000
/*  f0e7008:	14410002 */ 	bne	$v0,$at,.L0f0e7014
/*  f0e700c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7010:	0006000d */ 	break	0x6
.L0f0e7014:
/*  f0e7014:	02401025 */ 	or	$v0,$s2,$zero
.L0f0e7018:
/*  f0e7018:	3c0fe700 */ 	lui	$t7,0xe700
/*  f0e701c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0e7020:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0e7024:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0e7028:	8c63fac0 */ 	lw	$v1,%lo(var8007fac0)($v1)
/*  f0e702c:	3c068007 */ 	lui	$a2,%hi(var80071190)
/*  f0e7030:	24c61190 */ 	addiu	$a2,$a2,%lo(var80071190)
/*  f0e7034:	00830019 */ 	multu	$a0,$v1
/*  f0e7038:	3c018007 */ 	lui	$at,%hi(var80071198)
/*  f0e703c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e7040:	3c0b8007 */ 	lui	$t3,%hi(var80071198)
/*  f0e7044:	0000c012 */ 	mflo	$t8
/*  f0e7048:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0e704c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7050:	00e30019 */ 	multu	$a3,$v1
/*  f0e7054:	00005012 */ 	mflo	$t2
/*  f0e7058:	aeea0000 */ 	sw	$t2,0x0($s7)
/*  f0e705c:	ac251198 */ 	sw	$a1,%lo(var80071198)($at)
/*  f0e7060:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f0e7064:	afd00000 */ 	sw	$s0,0x0($s8)
/*  f0e7068:	3c018007 */ 	lui	$at,%hi(var80071190)
/*  f0e706c:	05a30003 */ 	bgezl	$t5,.L0f0e707c
/*  f0e7070:	8ef90000 */ 	lw	$t9,0x0($s7)
/*  f0e7074:	ac201190 */ 	sw	$zero,%lo(var80071190)($at)
/*  f0e7078:	8ef90000 */ 	lw	$t9,0x0($s7)
.L0f0e707c:
/*  f0e707c:	3c018007 */ 	lui	$at,%hi(var80071198)
/*  f0e7080:	07210002 */ 	bgez	$t9,.L0f0e708c
/*  f0e7084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7088:	aee00000 */ 	sw	$zero,0x0($s7)
.L0f0e708c:
/*  f0e708c:	8d6b1198 */ 	lw	$t3,%lo(var80071198)($t3)
/*  f0e7090:	05630003 */ 	bgezl	$t3,.L0f0e70a0
/*  f0e7094:	8fcc0000 */ 	lw	$t4,0x0($s8)
/*  f0e7098:	ac201198 */ 	sw	$zero,%lo(var80071198)($at)
/*  f0e709c:	8fcc0000 */ 	lw	$t4,0x0($s8)
.L0f0e70a0:
/*  f0e70a0:	05810002 */ 	bgez	$t4,.L0f0e70ac
/*  f0e70a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e70a8:	afc00000 */ 	sw	$zero,0x0($s8)
.L0f0e70ac:
/*  f0e70ac:	0c002ef1 */ 	jal	func0000bbc4
/*  f0e70b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e70b4:	3c0e8007 */ 	lui	$t6,%hi(var80071190)
/*  f0e70b8:	8dce1190 */ 	lw	$t6,%lo(var80071190)($t6)
/*  f0e70bc:	004e082a */ 	slt	$at,$v0,$t6
/*  f0e70c0:	10200005 */ 	beqz	$at,.L0f0e70d8
/*  f0e70c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e70c8:	0c002ef1 */ 	jal	func0000bbc4
/*  f0e70cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e70d0:	3c018007 */ 	lui	$at,%hi(var80071190)
/*  f0e70d4:	ac221190 */ 	sw	$v0,%lo(var80071190)($at)
.L0f0e70d8:
/*  f0e70d8:	0c002ef1 */ 	jal	func0000bbc4
/*  f0e70dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e70e0:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0e70e4:	004f082a */ 	slt	$at,$v0,$t7
/*  f0e70e8:	10200004 */ 	beqz	$at,.L0f0e70fc
/*  f0e70ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e70f0:	0c002ef1 */ 	jal	func0000bbc4
/*  f0e70f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e70f8:	aee20000 */ 	sw	$v0,0x0($s7)
.L0f0e70fc:
/*  f0e70fc:	0c002ef5 */ 	jal	func0000bbd4
/*  f0e7100:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7104:	3c188007 */ 	lui	$t8,%hi(var80071198)
/*  f0e7108:	8f181198 */ 	lw	$t8,%lo(var80071198)($t8)
/*  f0e710c:	0058082a */ 	slt	$at,$v0,$t8
/*  f0e7110:	10200005 */ 	beqz	$at,.L0f0e7128
/*  f0e7114:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7118:	0c002ef5 */ 	jal	func0000bbd4
/*  f0e711c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7120:	3c018007 */ 	lui	$at,%hi(var80071198)
/*  f0e7124:	ac221198 */ 	sw	$v0,%lo(var80071198)($at)
.L0f0e7128:
/*  f0e7128:	0c002ef5 */ 	jal	func0000bbd4
/*  f0e712c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7130:	8fc30000 */ 	lw	$v1,0x0($s8)
/*  f0e7134:	0043082a */ 	slt	$at,$v0,$v1
/*  f0e7138:	10200005 */ 	beqz	$at,.L0f0e7150
/*  f0e713c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7140:	0c002ef5 */ 	jal	func0000bbd4
/*  f0e7144:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7148:	afc20000 */ 	sw	$v0,0x0($s8)
/*  f0e714c:	00401825 */ 	or	$v1,$v0,$zero
.L0f0e7150:
/*  f0e7150:	3c098007 */ 	lui	$t1,%hi(var80071190)
/*  f0e7154:	8d291190 */ 	lw	$t1,%lo(var80071190)($t1)
/*  f0e7158:	8eea0000 */ 	lw	$t2,0x0($s7)
/*  f0e715c:	3c088007 */ 	lui	$t0,%hi(var80071198)
/*  f0e7160:	44893000 */ 	mtc1	$t1,$f6
/*  f0e7164:	0149082a */ 	slt	$at,$t2,$t1
/*  f0e7168:	10200002 */ 	beqz	$at,.L0f0e7174
/*  f0e716c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0e7170:	aee90000 */ 	sw	$t1,0x0($s7)
.L0f0e7174:
/*  f0e7174:	8d081198 */ 	lw	$t0,%lo(var80071198)($t0)
/*  f0e7178:	0068082a */ 	slt	$at,$v1,$t0
/*  f0e717c:	50200003 */ 	beqzl	$at,.L0f0e718c
/*  f0e7180:	44889000 */ 	mtc1	$t0,$f18
/*  f0e7184:	afc80000 */ 	sw	$t0,0x0($s8)
/*  f0e7188:	44889000 */ 	mtc1	$t0,$f18
.L0f0e718c:
/*  f0e718c:	3c014080 */ 	lui	$at,0x4080
/*  f0e7190:	44810000 */ 	mtc1	$at,$f0
/*  f0e7194:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0e7198:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e719c:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0e71a0:	02401025 */ 	or	$v0,$s2,$zero
/*  f0e71a4:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e71a8:	24040013 */ 	addiu	$a0,$zero,0x13
/*  f0e71ac:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0e71b0:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f0e71b4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e71b8:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e71bc:	44198000 */ 	mfc1	$t9,$f16
/*  f0e71c0:	44184000 */ 	mfc1	$t8,$f8
/*  f0e71c4:	332b0fff */ 	andi	$t3,$t9,0xfff
/*  f0e71c8:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f0e71cc:	01817025 */ 	or	$t6,$t4,$at
/*  f0e71d0:	330a0fff */ 	andi	$t2,$t8,0xfff
/*  f0e71d4:	01ca6825 */ 	or	$t5,$t6,$t2
/*  f0e71d8:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f0e71dc:	8ef90000 */ 	lw	$t9,0x0($s7)
/*  f0e71e0:	8fce0000 */ 	lw	$t6,0x0($s8)
/*  f0e71e4:	44995000 */ 	mtc1	$t9,$f10
/*  f0e71e8:	448e3000 */ 	mtc1	$t6,$f6
/*  f0e71ec:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e71f0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0e71f4:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0e71f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e71fc:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0e7200:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e7204:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e7208:	440c2000 */ 	mfc1	$t4,$f4
/*  f0e720c:	440d8000 */ 	mfc1	$t5,$f16
/*  f0e7210:	318f0fff */ 	andi	$t7,$t4,0xfff
/*  f0e7214:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0e7218:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f0e721c:	03195825 */ 	or	$t3,$t8,$t9
/*  f0e7220:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f0e7224:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0e7228:	8faf0160 */ 	lw	$t7,0x160($sp)
/*  f0e722c:	afb200b8 */ 	sw	$s2,0xb8($sp)
/*  f0e7230:	afb300bc */ 	sw	$s3,0xbc($sp)
/*  f0e7234:	afac00c0 */ 	sw	$t4,0xc0($sp)
/*  f0e7238:	afaf00c4 */ 	sw	$t7,0xc4($sp)
/*  f0e723c:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7240:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e7244:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e7248:	0320f809 */ 	jalr	$t9
/*  f0e724c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7250:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f0e7254:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e7258:	10000058 */ 	beqz	$zero,.L0f0e73bc
/*  f0e725c:	afae0160 */ 	sw	$t6,0x160($sp)
/*  f0e7260:	afb3015c */ 	sw	$s3,0x15c($sp)
.L0f0e7264:
/*  f0e7264:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7268:	afa00128 */ 	sw	$zero,0x128($sp)
/*  f0e726c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e7270:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e7274:	27a6015c */ 	addiu	$a2,$sp,0x15c
/*  f0e7278:	00004025 */ 	or	$t0,$zero,$zero
/*  f0e727c:	0320f809 */ 	jalr	$t9
/*  f0e7280:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e7284:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e7288:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0e728c:	8fa80128 */ 	lw	$t0,0x128($sp)
/*  f0e7290:	01546821 */ 	addu	$t5,$t2,$s4
/*  f0e7294:	25b80001 */ 	addiu	$t8,$t5,0x1
/*  f0e7298:	afb8012c */ 	sw	$t8,0x12c($sp)
/*  f0e729c:	8e2b0008 */ 	lw	$t3,0x8($s1)
/*  f0e72a0:	00403825 */ 	or	$a3,$v0,$zero
/*  f0e72a4:	8fac011c */ 	lw	$t4,0x11c($sp)
/*  f0e72a8:	91630000 */ 	lbu	$v1,0x0($t3)
/*  f0e72ac:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e72b0:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f0e72b4:	10610004 */ 	beq	$v1,$at,.L0f0e72c8
/*  f0e72b8:	27a6012c */ 	addiu	$a2,$sp,0x12c
/*  f0e72bc:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0e72c0:	14610003 */ 	bne	$v1,$at,.L0f0e72d0
/*  f0e72c4:	8faf011c */ 	lw	$t7,0x11c($sp)
.L0f0e72c8:
/*  f0e72c8:	10000003 */ 	beqz	$zero,.L0f0e72d8
/*  f0e72cc:	afac0130 */ 	sw	$t4,0x130($sp)
.L0f0e72d0:
/*  f0e72d0:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f0e72d4:	afae0130 */ 	sw	$t6,0x130($sp)
.L0f0e72d8:
/*  f0e72d8:	8fa2012c */ 	lw	$v0,0x12c($sp)
/*  f0e72dc:	8fb90104 */ 	lw	$t9,0x104($sp)
/*  f0e72e0:	0059082a */ 	slt	$at,$v0,$t9
/*  f0e72e4:	50200004 */ 	beqzl	$at,.L0f0e72f8
/*  f0e72e8:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e72ec:	00594023 */ 	subu	$t0,$v0,$t9
/*  f0e72f0:	afb9012c */ 	sw	$t9,0x12c($sp)
/*  f0e72f4:	862a0002 */ 	lh	$t2,0x2($s1)
.L0f0e72f8:
/*  f0e72f8:	862d0006 */ 	lh	$t5,0x6($s1)
/*  f0e72fc:	8fab012c */ 	lw	$t3,0x12c($sp)
/*  f0e7300:	8fac00e8 */ 	lw	$t4,0xe8($sp)
/*  f0e7304:	014dc021 */ 	addu	$t8,$t2,$t5
/*  f0e7308:	030b1823 */ 	subu	$v1,$t8,$t3
/*  f0e730c:	04630003 */ 	bgezl	$v1,.L0f0e731c
/*  f0e7310:	8faf00f4 */ 	lw	$t7,0xf4($sp)
/*  f0e7314:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e7318:	8faf00f4 */ 	lw	$t7,0xf4($sp)
.L0f0e731c:
/*  f0e731c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e7320:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7324:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e7328:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0e732c:	8fb9011c */ 	lw	$t9,0x11c($sp)
/*  f0e7330:	862d0000 */ 	lh	$t5,0x0($s1)
/*  f0e7334:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e7338:	01d95023 */ 	subu	$t2,$t6,$t9
/*  f0e733c:	014dc021 */ 	addu	$t8,$t2,$t5
/*  f0e7340:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e7344:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f0e7348:	0fc5580f */ 	jal	func0f15603c
/*  f0e734c:	afa30020 */ 	sw	$v1,0x20($sp)
/*  f0e7350:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f0e7354:	afb300b8 */ 	sw	$s3,0xb8($sp)
/*  f0e7358:	afab00bc */ 	sw	$t3,0xbc($sp)
/*  f0e735c:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7360:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e7364:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f0e7368:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e736c:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f0e7370:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e7374:	0320f809 */ 	jalr	$t9
/*  f0e7378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e737c:	8fac00bc */ 	lw	$t4,0xbc($sp)
/*  f0e7380:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0e7384:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e7388:	1181000c */ 	beq	$t4,$at,.L0f0e73bc
/*  f0e738c:	8fa5011c */ 	lw	$a1,0x11c($sp)
/*  f0e7390:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0e7394:	3c0eff00 */ 	lui	$t6,0xff00
/*  f0e7398:	35ce007f */ 	ori	$t6,$t6,0x7f
/*  f0e739c:	01f43021 */ 	addu	$a2,$t7,$s4
/*  f0e73a0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0e73a4:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0e73a8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e73ac:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e73b0:	0fc38dec */ 	jal	func0f0e37b0
/*  f0e73b4:	24070006 */ 	addiu	$a3,$zero,0x6
/*  f0e73b8:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e73bc:
/*  f0e73bc:	8faa00b4 */ 	lw	$t2,0xb4($sp)
/*  f0e73c0:	51400004 */ 	beqzl	$t2,.L0f0e73d4
/*  f0e73c4:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0e73c8:	0fc55809 */ 	jal	func0f156024
/*  f0e73cc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0e73d0:	8fb80108 */ 	lw	$t8,0x108($sp)
.L0f0e73d4:
/*  f0e73d4:	3c0d8007 */ 	lui	$t5,%hi(var800711a8)
/*  f0e73d8:	8dad11a8 */ 	lw	$t5,%lo(var800711a8)($t5)
/*  f0e73dc:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0e73e0:	0278082a */ 	slt	$at,$s3,$t8
/*  f0e73e4:	14200003 */ 	bnez	$at,.L0f0e73f4
/*  f0e73e8:	028da021 */ 	addu	$s4,$s4,$t5
/*  f0e73ec:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e73f0:	afab0120 */ 	sw	$t3,0x120($sp)
.L0f0e73f4:
/*  f0e73f4:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0e73f8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e73fc:	0334082a */ 	slt	$at,$t9,$s4
/*  f0e7400:	50200003 */ 	beqzl	$at,.L0f0e7410
/*  f0e7404:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f0e7408:	afaf0120 */ 	sw	$t7,0x120($sp)
/*  f0e740c:	8fac0120 */ 	lw	$t4,0x120($sp)
.L0f0e7410:
/*  f0e7410:	5180fd95 */ 	beqzl	$t4,.L0f0e6a68
/*  f0e7414:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e7418:	0fc3d43f */ 	jal	func0f0f50fc
/*  f0e741c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e7420:	10000051 */ 	beqz	$zero,.L0f0e7568
/*  f0e7424:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e7428:
/*  f0e7428:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e742c:	44802000 */ 	mtc1	$zero,$f4
/*  f0e7430:	c4720040 */ 	lwc1	$f18,0x40($v1)
/*  f0e7434:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0e7438:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e743c:	4502000b */ 	bc1fl	.L0f0e746c
/*  f0e7440:	9078003d */ 	lbu	$t8,0x3d($v1)
/*  f0e7444:	906e003c */ 	lbu	$t6,0x3c($v1)
/*  f0e7448:	2415003c */ 	addiu	$s5,$zero,0x3c
/*  f0e744c:	3c167f1b */ 	lui	$s6,%hi(var7f1b1fb0)
/*  f0e7450:	01d50019 */ 	multu	$t6,$s5
/*  f0e7454:	26d61fb0 */ 	addiu	$s6,$s6,%lo(var7f1b1fb0)
/*  f0e7458:	00005012 */ 	mflo	$t2
/*  f0e745c:	02ca6821 */ 	addu	$t5,$s6,$t2
/*  f0e7460:	10000012 */ 	beqz	$zero,.L0f0e74ac
/*  f0e7464:	8db00018 */ 	lw	$s0,0x18($t5)
/*  f0e7468:	9078003d */ 	lbu	$t8,0x3d($v1)
.L0f0e746c:
/*  f0e746c:	2415003c */ 	addiu	$s5,$zero,0x3c
/*  f0e7470:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0e7474:	03150019 */ 	multu	$t8,$s5
/*  f0e7478:	3c167f1b */ 	lui	$s6,%hi(var7f1b1fb0)
/*  f0e747c:	26d61fb0 */ 	addiu	$s6,$s6,%lo(var7f1b1fb0)
/*  f0e7480:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e7484:	00005812 */ 	mflo	$t3
/*  f0e7488:	02cbc821 */ 	addu	$t9,$s6,$t3
/*  f0e748c:	8f240018 */ 	lw	$a0,0x18($t9)
/*  f0e7490:	01f50019 */ 	multu	$t7,$s5
/*  f0e7494:	00006012 */ 	mflo	$t4
/*  f0e7498:	02cc7021 */ 	addu	$t6,$s6,$t4
/*  f0e749c:	0fc01a40 */ 	jal	func0f006900
/*  f0e74a0:	8dc50018 */ 	lw	$a1,0x18($t6)
/*  f0e74a4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e74a8:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0e74ac:
/*  f0e74ac:	8c6a000c */ 	lw	$t2,0xc($v1)
/*  f0e74b0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e74b4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e74b8:	51400008 */ 	beqzl	$t2,.L0f0e74dc
/*  f0e74bc:	8fab011c */ 	lw	$t3,0x11c($sp)
/*  f0e74c0:	0fc01a40 */ 	jal	func0f006900
/*  f0e74c4:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e74c8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e74cc:	00416824 */ 	and	$t5,$v0,$at
/*  f0e74d0:	321800ff */ 	andi	$t8,$s0,0xff
/*  f0e74d4:	01b88025 */ 	or	$s0,$t5,$t8
/*  f0e74d8:	8fab011c */ 	lw	$t3,0x11c($sp)
.L0f0e74dc:
/*  f0e74dc:	24045739 */ 	addiu	$a0,$zero,0x5739
/*  f0e74e0:	25790008 */ 	addiu	$t9,$t3,0x8
/*  f0e74e4:	afb90130 */ 	sw	$t9,0x130($sp)
/*  f0e74e8:	862c0006 */ 	lh	$t4,0x6($s1)
/*  f0e74ec:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0e74f0:	05810003 */ 	bgez	$t4,.L0f0e7500
/*  f0e74f4:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f0e74f8:	25810001 */ 	addiu	$at,$t4,0x1
/*  f0e74fc:	00017043 */ 	sra	$t6,$at,0x1
.L0f0e7500:
/*  f0e7500:	01ee5021 */ 	addu	$t2,$t7,$t6
/*  f0e7504:	0fc5b9f1 */ 	jal	langGet
/*  f0e7508:	afaa012c */ 	sw	$t2,0x12c($sp)
/*  f0e750c:	0c002f06 */ 	jal	func0000bc18
/*  f0e7510:	00409825 */ 	or	$s3,$v0,$zero
/*  f0e7514:	8fad00e8 */ 	lw	$t5,0xe8($sp)
/*  f0e7518:	8fb800f4 */ 	lw	$t8,0xf4($sp)
/*  f0e751c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7520:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e7524:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e7528:	862b0004 */ 	lh	$t3,0x4($s1)
/*  f0e752c:	8fb9011c */ 	lw	$t9,0x11c($sp)
/*  f0e7530:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0e7534:	8fa80128 */ 	lw	$t0,0x128($sp)
/*  f0e7538:	01796023 */ 	subu	$t4,$t3,$t9
/*  f0e753c:	018f7021 */ 	addu	$t6,$t4,$t7
/*  f0e7540:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0e7544:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e7548:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e754c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e7550:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f0e7554:	27a6012c */ 	addiu	$a2,$sp,0x12c
/*  f0e7558:	02603825 */ 	or	$a3,$s3,$zero
/*  f0e755c:	0fc5580f */ 	jal	func0f15603c
/*  f0e7560:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f0e7564:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e7568:
/*  f0e7568:	0fc54de0 */ 	jal	func0f153780
/*  f0e756c:	02402025 */ 	or	$a0,$s2,$zero
.L0f0e7570:
/*  f0e7570:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f0e7574:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0e7578:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0e757c:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0e7580:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f0e7584:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f0e7588:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f0e758c:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f0e7590:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f0e7594:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f0e7598:	03e00008 */ 	jr	$ra
/*  f0e759c:	27bd0170 */ 	addiu	$sp,$sp,0x170
);

GLOBAL_ASM(
glabel func0f0e75a0
.late_rodata
glabel var7f1b1e58
.word 0x3eb33333
glabel var7f1b1e5c
.word 0x3f266666
.text
/*  f0e75a0:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0e75a4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0e75a8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e75ac:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e75b0:	afa5006c */ 	sw	$a1,0x6c($sp)
/*  f0e75b4:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f0e75b8:	8c820010 */ 	lw	$v0,0x10($a0)
/*  f0e75bc:	00e08025 */ 	or	$s0,$a3,$zero
/*  f0e75c0:	00808825 */ 	or	$s1,$a0,$zero
/*  f0e75c4:	54400004 */ 	bnezl	$v0,.L0f0e75d8
/*  f0e75c8:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*  f0e75cc:	100000ed */ 	beqz	$zero,.L0f0e7984
/*  f0e75d0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0e75d4:	8e2e0004 */ 	lw	$t6,0x4($s1)
.L0f0e75d8:
/*  f0e75d8:	3c010020 */ 	lui	$at,0x20
/*  f0e75dc:	2419000b */ 	addiu	$t9,$zero,0xb
/*  f0e75e0:	01c17824 */ 	and	$t7,$t6,$at
/*  f0e75e4:	11e00009 */ 	beqz	$t7,.L0f0e760c
/*  f0e75e8:	3c018007 */ 	lui	$at,0x8007
/*  f0e75ec:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f0e75f0:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e75f4:	0040f809 */ 	jalr	$v0
/*  f0e75f8:	27a60044 */ 	addiu	$a2,$sp,0x44
/*  f0e75fc:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f0e7600:	3c018007 */ 	lui	$at,%hi(var800711a8)
/*  f0e7604:	10000002 */ 	beqz	$zero,.L0f0e7610
/*  f0e7608:	ac3811a8 */ 	sw	$t8,%lo(var800711a8)($at)
.L0f0e760c:
/*  f0e760c:	ac3911a8 */ 	sw	$t9,0x11a8($at)
.L0f0e7610:
/*  f0e7610:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f0e7614:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0e7618:	10410003 */ 	beq	$v0,$at,.L0f0e7628
/*  f0e761c:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0e7620:	5441003d */ 	bnel	$v0,$at,.L0f0e7718
/*  f0e7624:	86040000 */ 	lh	$a0,0x0($s0)
.L0f0e7628:
/*  f0e7628:	86030006 */ 	lh	$v1,0x6($s0)
/*  f0e762c:	3c028007 */ 	lui	$v0,%hi(var800711a8)
/*  f0e7630:	8c4211a8 */ 	lw	$v0,%lo(var800711a8)($v0)
/*  f0e7634:	04610003 */ 	bgez	$v1,.L0f0e7644
/*  f0e7638:	00034843 */ 	sra	$t1,$v1,0x1
/*  f0e763c:	24610001 */ 	addiu	$at,$v1,0x1
/*  f0e7640:	00014843 */ 	sra	$t1,$at,0x1
.L0f0e7644:
/*  f0e7644:	00095400 */ 	sll	$t2,$t1,0x10
/*  f0e7648:	000a5c03 */ 	sra	$t3,$t2,0x10
/*  f0e764c:	0162001a */ 	div	$zero,$t3,$v0
/*  f0e7650:	01601825 */ 	or	$v1,$t3,$zero
/*  f0e7654:	14400002 */ 	bnez	$v0,.L0f0e7660
/*  f0e7658:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e765c:	0007000d */ 	break	0x7
.L0f0e7660:
/*  f0e7660:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e7664:	14410004 */ 	bne	$v0,$at,.L0f0e7678
/*  f0e7668:	3c018000 */ 	lui	$at,0x8000
/*  f0e766c:	14610002 */ 	bne	$v1,$at,.L0f0e7678
/*  f0e7670:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7674:	0006000d */ 	break	0x6
.L0f0e7678:
/*  f0e7678:	00001812 */ 	mflo	$v1
/*  f0e767c:	00036400 */ 	sll	$t4,$v1,0x10
/*  f0e7680:	000c6c03 */ 	sra	$t5,$t4,0x10
/*  f0e7684:	01a20019 */ 	multu	$t5,$v0
/*  f0e7688:	86040002 */ 	lh	$a0,0x2($s0)
/*  f0e768c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e7690:	00007812 */ 	mflo	$t7
/*  f0e7694:	a7af0042 */ 	sh	$t7,0x42($sp)
/*  f0e7698:	0fc397be */ 	jal	func0f0e5ef8
/*  f0e769c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e76a0:	87a30042 */ 	lh	$v1,0x42($sp)
/*  f0e76a4:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f0e76a8:	86180004 */ 	lh	$t8,0x4($s0)
/*  f0e76ac:	0303082a */ 	slt	$at,$t8,$v1
/*  f0e76b0:	50200003 */ 	beqzl	$at,.L0f0e76c0
/*  f0e76b4:	a7a30042 */ 	sh	$v1,0x42($sp)
/*  f0e76b8:	a6030004 */ 	sh	$v1,0x4($s0)
/*  f0e76bc:	a7a30042 */ 	sh	$v1,0x42($sp)
.L0f0e76c0:
/*  f0e76c0:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e76c4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0e76c8:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e76cc:	0320f809 */ 	jalr	$t9
/*  f0e76d0:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0e76d4:	3c0a8007 */ 	lui	$t2,%hi(var800711a8)
/*  f0e76d8:	8d4a11a8 */ 	lw	$t2,%lo(var800711a8)($t2)
/*  f0e76dc:	87a90056 */ 	lh	$t1,0x56($sp)
/*  f0e76e0:	860c0006 */ 	lh	$t4,0x6($s0)
/*  f0e76e4:	87a30042 */ 	lh	$v1,0x42($sp)
/*  f0e76e8:	012a0019 */ 	multu	$t1,$t2
/*  f0e76ec:	86180004 */ 	lh	$t8,0x4($s0)
/*  f0e76f0:	00005812 */ 	mflo	$t3
/*  f0e76f4:	016c6823 */ 	subu	$t5,$t3,$t4
/*  f0e76f8:	01a32021 */ 	addu	$a0,$t5,$v1
/*  f0e76fc:	00047400 */ 	sll	$t6,$a0,0x10
/*  f0e7700:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f0e7704:	01f8082a */ 	slt	$at,$t7,$t8
/*  f0e7708:	50200003 */ 	beqzl	$at,.L0f0e7718
/*  f0e770c:	86040000 */ 	lh	$a0,0x0($s0)
/*  f0e7710:	a60f0004 */ 	sh	$t7,0x4($s0)
/*  f0e7714:	86040000 */ 	lh	$a0,0x0($s0)
.L0f0e7718:
/*  f0e7718:	86050004 */ 	lh	$a1,0x4($s0)
/*  f0e771c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e7720:	00043400 */ 	sll	$a2,$a0,0x10
/*  f0e7724:	10a40023 */ 	beq	$a1,$a0,.L0f0e77b4
/*  f0e7728:	0006cc03 */ 	sra	$t9,$a2,0x10
/*  f0e772c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0e7730:	8c639fc0 */ 	lw	$v1,%lo(g_Vars)($v1)
/*  f0e7734:	44842000 */ 	mtc1	$a0,$f4
/*  f0e7738:	03203025 */ 	or	$a2,$t9,$zero
/*  f0e773c:	1860000e */ 	blez	$v1,.L0f0e7778
/*  f0e7740:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0e7744:	44853000 */ 	mtc1	$a1,$f6
/*  f0e7748:	3c017f1b */ 	lui	$at,%hi(var7f1b1e58)
/*  f0e774c:	c42a1e58 */ 	lwc1	$f10,%lo(var7f1b1e58)($at)
/*  f0e7750:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0e7754:	3c017f1b */ 	lui	$at,%hi(var7f1b1e5c)
/*  f0e7758:	c4221e5c */ 	lwc1	$f2,%lo(var7f1b1e5c)($at)
/*  f0e775c:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*  f0e7760:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0e7764:
/*  f0e7764:	46001402 */ 	mul.s	$f16,$f2,$f0
/*  f0e7768:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0e776c:	0043082a */ 	slt	$at,$v0,$v1
/*  f0e7770:	1420fffc */ 	bnez	$at,.L0f0e7764
/*  f0e7774:	46106000 */ 	add.s	$f0,$f12,$f16
.L0f0e7778:
/*  f0e7778:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f0e777c:	440a9000 */ 	mfc1	$t2,$f18
/*  f0e7780:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7784:	a60a0000 */ 	sh	$t2,0x0($s0)
/*  f0e7788:	86040000 */ 	lh	$a0,0x0($s0)
/*  f0e778c:	50a4000a */ 	beql	$a1,$a0,.L0f0e77b8
/*  f0e7790:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0e7794:	14c40007 */ 	bne	$a2,$a0,.L0f0e77b4
/*  f0e7798:	0085082a */ 	slt	$at,$a0,$a1
/*  f0e779c:	10200004 */ 	beqz	$at,.L0f0e77b0
/*  f0e77a0:	248cffff */ 	addiu	$t4,$a0,-1
/*  f0e77a4:	248b0001 */ 	addiu	$t3,$a0,0x1
/*  f0e77a8:	10000002 */ 	beqz	$zero,.L0f0e77b4
/*  f0e77ac:	a60b0000 */ 	sh	$t3,0x0($s0)
.L0f0e77b0:
/*  f0e77b0:	a60c0000 */ 	sh	$t4,0x0($s0)
.L0f0e77b4:
/*  f0e77b4:	8fad0070 */ 	lw	$t5,0x70($sp)
.L0f0e77b8:
/*  f0e77b8:	31ae0002 */ 	andi	$t6,$t5,0x2
/*  f0e77bc:	11c00057 */ 	beqz	$t6,.L0f0e791c
/*  f0e77c0:	afae0028 */ 	sw	$t6,0x28($sp)
/*  f0e77c4:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e77c8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0e77cc:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e77d0:	0320f809 */ 	jalr	$t9
/*  f0e77d4:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0e77d8:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f0e77dc:	51e00050 */ 	beqzl	$t7,.L0f0e7920
/*  f0e77e0:	86020002 */ 	lh	$v0,0x2($s0)
/*  f0e77e4:	86180002 */ 	lh	$t8,0x2($s0)
/*  f0e77e8:	25e2ffff */ 	addiu	$v0,$t7,-1
/*  f0e77ec:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e77f0:	0058082b */ 	sltu	$at,$v0,$t8
/*  f0e77f4:	50200006 */ 	beqzl	$at,.L0f0e7810
/*  f0e77f8:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f0e77fc:	a6020002 */ 	sh	$v0,0x2($s0)
/*  f0e7800:	0fc397be */ 	jal	func0f0e5ef8
/*  f0e7804:	86040002 */ 	lh	$a0,0x2($s0)
/*  f0e7808:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f0e780c:	8fa8006c */ 	lw	$t0,0x6c($sp)
.L0f0e7810:
/*  f0e7810:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e7814:	81020001 */ 	lb	$v0,0x1($t0)
/*  f0e7818:	50400026 */ 	beqzl	$v0,.L0f0e78b4
/*  f0e781c:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f0e7820:	86070002 */ 	lh	$a3,0x2($s0)
/*  f0e7824:	00e25021 */ 	addu	$t2,$a3,$v0
/*  f0e7828:	a60a0002 */ 	sh	$t2,0x2($s0)
/*  f0e782c:	00071c00 */ 	sll	$v1,$a3,0x10
/*  f0e7830:	86070002 */ 	lh	$a3,0x2($s0)
/*  f0e7834:	00034c03 */ 	sra	$t1,$v1,0x10
/*  f0e7838:	01201825 */ 	or	$v1,$t1,$zero
/*  f0e783c:	04e10004 */ 	bgez	$a3,.L0f0e7850
/*  f0e7840:	8fab0054 */ 	lw	$t3,0x54($sp)
/*  f0e7844:	256cffff */ 	addiu	$t4,$t3,-1
/*  f0e7848:	a60c0002 */ 	sh	$t4,0x2($s0)
/*  f0e784c:	86070002 */ 	lh	$a3,0x2($s0)
.L0f0e7850:
/*  f0e7850:	87ad0056 */ 	lh	$t5,0x56($sp)
/*  f0e7854:	00ed082a */ 	slt	$at,$a3,$t5
/*  f0e7858:	54200004 */ 	bnezl	$at,.L0f0e786c
/*  f0e785c:	00072400 */ 	sll	$a0,$a3,0x10
/*  f0e7860:	a6000002 */ 	sh	$zero,0x2($s0)
/*  f0e7864:	86070002 */ 	lh	$a3,0x2($s0)
/*  f0e7868:	00072400 */ 	sll	$a0,$a3,0x10
.L0f0e786c:
/*  f0e786c:	00047403 */ 	sra	$t6,$a0,0x10
/*  f0e7870:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0e7874:	0fc397be */ 	jal	func0f0e5ef8
/*  f0e7878:	a7a30032 */ 	sh	$v1,0x32($sp)
/*  f0e787c:	87a30032 */ 	lh	$v1,0x32($sp)
/*  f0e7880:	86070002 */ 	lh	$a3,0x2($s0)
/*  f0e7884:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f0e7888:	5067000a */ 	beql	$v1,$a3,.L0f0e78b4
/*  f0e788c:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f0e7890:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e7894:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e7898:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f0e789c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e78a0:	0320f809 */ 	jalr	$t9
/*  f0e78a4:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0e78a8:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0e78ac:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0e78b0:	8fa8006c */ 	lw	$t0,0x6c($sp)
.L0f0e78b4:
/*  f0e78b4:	910f0002 */ 	lbu	$t7,0x2($t0)
/*  f0e78b8:	51e00017 */ 	beqzl	$t7,.L0f0e7918
/*  f0e78bc:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f0e78c0:	86180002 */ 	lh	$t8,0x2($s0)
/*  f0e78c4:	afa00058 */ 	sw	$zero,0x58($sp)
/*  f0e78c8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0e78cc:	afb80054 */ 	sw	$t8,0x54($sp)
/*  f0e78d0:	8109000a */ 	lb	$t1,0xa($t0)
/*  f0e78d4:	51200003 */ 	beqzl	$t1,.L0f0e78e4
/*  f0e78d8:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e78dc:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0e78e0:	8e390010 */ 	lw	$t9,0x10($s1)
.L0f0e78e4:
/*  f0e78e4:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0e78e8:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e78ec:	0320f809 */ 	jalr	$t9
/*  f0e78f0:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0e78f4:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0e78f8:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e78fc:	8fab0058 */ 	lw	$t3,0x58($sp)
/*  f0e7900:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e7904:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f0e7908:	55610003 */ 	bnel	$t3,$at,.L0f0e7918
/*  f0e790c:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f0e7910:	a180000a */ 	sb	$zero,0xa($t4)
/*  f0e7914:	8fa8006c */ 	lw	$t0,0x6c($sp)
.L0f0e7918:
/*  f0e7918:	a1000001 */ 	sb	$zero,0x1($t0)
.L0f0e791c:
/*  f0e791c:	86020002 */ 	lh	$v0,0x2($s0)
.L0f0e7920:
/*  f0e7920:	8fae0028 */ 	lw	$t6,0x28($sp)
/*  f0e7924:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0e7928:	afad0058 */ 	sw	$t5,0x58($sp)
/*  f0e792c:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f0e7930:	11c00004 */ 	beqz	$t6,.L0f0e7944
/*  f0e7934:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f0e7938:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e793c:	10000002 */ 	beqz	$zero,.L0f0e7948
/*  f0e7940:	afaf005c */ 	sw	$t7,0x5c($sp)
.L0f0e7944:
/*  f0e7944:	afa0005c */ 	sw	$zero,0x5c($sp)
.L0f0e7948:
/*  f0e7948:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e794c:	24040019 */ 	addiu	$a0,$zero,0x19
/*  f0e7950:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e7954:	0320f809 */ 	jalr	$t9
/*  f0e7958:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0e795c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0e7960:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f0e7964:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e7968:	53090006 */ 	beql	$t8,$t1,.L0f0e7984
/*  f0e796c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0e7970:	a6090002 */ 	sh	$t1,0x2($s0)
/*  f0e7974:	0fc397be */ 	jal	func0f0e5ef8
/*  f0e7978:	86040002 */ 	lh	$a0,0x2($s0)
/*  f0e797c:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f0e7980:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0e7984:
/*  f0e7984:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0e7988:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0e798c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0e7990:	03e00008 */ 	jr	$ra
/*  f0e7994:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f0e7998
/*  f0e7998:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0e799c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0e79a0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e79a4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e79a8:	a4a00000 */ 	sh	$zero,0x0($a1)
/*  f0e79ac:	a4a00002 */ 	sh	$zero,0x2($a1)
/*  f0e79b0:	a4a00008 */ 	sh	$zero,0x8($a1)
/*  f0e79b4:	a4a0000a */ 	sh	$zero,0xa($a1)
/*  f0e79b8:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f0e79bc:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f0e79c0:	00808025 */ 	or	$s0,$a0,$zero
/*  f0e79c4:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0e79c8:	000e7a80 */ 	sll	$t7,$t6,0xa
/*  f0e79cc:	05e10009 */ 	bgez	$t7,.L0f0e79f4
/*  f0e79d0:	8c820010 */ 	lw	$v0,0x10($a0)
/*  f0e79d4:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f0e79d8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e79dc:	0040f809 */ 	jalr	$v0
/*  f0e79e0:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f0e79e4:	8fb80024 */ 	lw	$t8,0x24($sp)
/*  f0e79e8:	3c018007 */ 	lui	$at,%hi(var800711a8)
/*  f0e79ec:	10000004 */ 	beqz	$zero,.L0f0e7a00
/*  f0e79f0:	ac3811a8 */ 	sw	$t8,%lo(var800711a8)($at)
.L0f0e79f4:
/*  f0e79f4:	2419000b */ 	addiu	$t9,$zero,0xb
/*  f0e79f8:	3c018007 */ 	lui	$at,%hi(var800711a8)
/*  f0e79fc:	ac3911a8 */ 	sw	$t9,%lo(var800711a8)($at)
.L0f0e7a00:
/*  f0e7a00:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f0e7a04:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0e7a08:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e7a0c:	0320f809 */ 	jalr	$t9
/*  f0e7a10:	27a60034 */ 	addiu	$a2,$sp,0x34
/*  f0e7a14:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f0e7a18:	3401ffff */ 	dli	$at,0xffff
/*  f0e7a1c:	0101082b */ 	sltu	$at,$t0,$at
/*  f0e7a20:	50200004 */ 	beqzl	$at,.L0f0e7a34
/*  f0e7a24:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f0e7a28:	1000000a */ 	beqz	$zero,.L0f0e7a54
/*  f0e7a2c:	a6280002 */ 	sh	$t0,0x2($s1)
/*  f0e7a30:	afa00034 */ 	sw	$zero,0x34($sp)
.L0f0e7a34:
/*  f0e7a34:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f0e7a38:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f0e7a3c:	24040019 */ 	addiu	$a0,$zero,0x19
/*  f0e7a40:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e7a44:	0320f809 */ 	jalr	$t9
/*  f0e7a48:	27a60034 */ 	addiu	$a2,$sp,0x34
/*  f0e7a4c:	8fa90034 */ 	lw	$t1,0x34($sp)
/*  f0e7a50:	a6290002 */ 	sh	$t1,0x2($s1)
.L0f0e7a54:
/*  f0e7a54:	86240002 */ 	lh	$a0,0x2($s1)
/*  f0e7a58:	0fc397be */ 	jal	func0f0e5ef8
/*  f0e7a5c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e7a60:	a6220004 */ 	sh	$v0,0x4($s1)
/*  f0e7a64:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f0e7a68:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f0e7a6c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e7a70:	0320f809 */ 	jalr	$t9
/*  f0e7a74:	27a60034 */ 	addiu	$a2,$sp,0x34
/*  f0e7a78:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0e7a7c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0e7a80:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0e7a84:	03e00008 */ 	jr	$ra
/*  f0e7a88:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f0e7a8c
/*  f0e7a8c:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0e7a90:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e7a94:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0e7a98:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0e7a9c:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f0e7aa0:	84ae0000 */ 	lh	$t6,0x0($a1)
/*  f0e7aa4:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0e7aa8:	afae0074 */ 	sw	$t6,0x74($sp)
/*  f0e7aac:	84af0002 */ 	lh	$t7,0x2($a1)
/*  f0e7ab0:	afaf0070 */ 	sw	$t7,0x70($sp)
/*  f0e7ab4:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0e7ab8:	8ca40008 */ 	lw	$a0,0x8($a1)
/*  f0e7abc:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0e7ac0:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e7ac4:	44803000 */ 	mtc1	$zero,$f6
/*  f0e7ac8:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0e7acc:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e7ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7ad4:	4502000a */ 	bc1fl	.L0f0e7b00
/*  f0e7ad8:	9068003d */ 	lbu	$t0,0x3d($v1)
/*  f0e7adc:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e7ae0:	3c117f1b */ 	lui	$s1,%hi(var7f1b1fc8)
/*  f0e7ae4:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0e7ae8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0e7aec:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0e7af0:	02398821 */ 	addu	$s1,$s1,$t9
/*  f0e7af4:	10000013 */ 	beqz	$zero,.L0f0e7b44
/*  f0e7af8:	8e311fc8 */ 	lw	$s1,%lo(var7f1b1fc8)($s1)
/*  f0e7afc:	9068003d */ 	lbu	$t0,0x3d($v1)
.L0f0e7b00:
/*  f0e7b00:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0e7b04:	3c0a7f1b */ 	lui	$t2,%hi(var7f1b1fb0)
/*  f0e7b08:	00084900 */ 	sll	$t1,$t0,0x4
/*  f0e7b0c:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0e7b10:	254a1fb0 */ 	addiu	$t2,$t2,%lo(var7f1b1fb0)
/*  f0e7b14:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0e7b18:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0e7b1c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e7b20:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0e7b24:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f0e7b28:	01aa7021 */ 	addu	$t6,$t5,$t2
/*  f0e7b2c:	8dc50018 */ 	lw	$a1,0x18($t6)
/*  f0e7b30:	8d640018 */ 	lw	$a0,0x18($t3)
/*  f0e7b34:	0fc01a40 */ 	jal	func0f006900
/*  f0e7b38:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e7b3c:	00408825 */ 	or	$s1,$v0,$zero
/*  f0e7b40:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0e7b44:
/*  f0e7b44:	8c6f000c */ 	lw	$t7,0xc($v1)
/*  f0e7b48:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e7b4c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e7b50:	51e00008 */ 	beqzl	$t7,.L0f0e7b74
/*  f0e7b54:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0e7b58:	0fc01a40 */ 	jal	func0f006900
/*  f0e7b5c:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e7b60:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e7b64:	0041c024 */ 	and	$t8,$v0,$at
/*  f0e7b68:	323900ff */ 	andi	$t9,$s1,0xff
/*  f0e7b6c:	03198825 */ 	or	$s1,$t8,$t9
/*  f0e7b70:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f0e7b74:
/*  f0e7b74:	104000b7 */ 	beqz	$v0,.L0f0e7e54
/*  f0e7b78:	30480002 */ 	andi	$t0,$v0,0x2
/*  f0e7b7c:	11000055 */ 	beqz	$t0,.L0f0e7cd4
/*  f0e7b80:	3c014220 */ 	lui	$at,0x4220
/*  f0e7b84:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0e7b88:	44816000 */ 	mtc1	$at,$f12
/*  f0e7b8c:	0fc01ac2 */ 	jal	func0f006b08
/*  f0e7b90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7b94:	3c01437f */ 	lui	$at,0x437f
/*  f0e7b98:	44814000 */ 	mtc1	$at,$f8
/*  f0e7b9c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e7ba0:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0e7ba4:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0e7ba8:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0e7bac:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e7bb0:	4449f800 */ 	cfc1	$t1,$31
/*  f0e7bb4:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e7bb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7bbc:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0e7bc0:	444bf800 */ 	cfc1	$t3,$31
/*  f0e7bc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7bc8:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e7bcc:	51600013 */ 	beqzl	$t3,.L0f0e7c1c
/*  f0e7bd0:	440b8000 */ 	mfc1	$t3,$f16
/*  f0e7bd4:	44818000 */ 	mtc1	$at,$f16
/*  f0e7bd8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e7bdc:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0e7be0:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e7be4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7be8:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0e7bec:	444bf800 */ 	cfc1	$t3,$31
/*  f0e7bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7bf4:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e7bf8:	15600005 */ 	bnez	$t3,.L0f0e7c10
/*  f0e7bfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7c00:	440b8000 */ 	mfc1	$t3,$f16
/*  f0e7c04:	3c018000 */ 	lui	$at,0x8000
/*  f0e7c08:	10000007 */ 	beqz	$zero,.L0f0e7c28
/*  f0e7c0c:	01615825 */ 	or	$t3,$t3,$at
.L0f0e7c10:
/*  f0e7c10:	10000005 */ 	beqz	$zero,.L0f0e7c28
/*  f0e7c14:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0e7c18:	440b8000 */ 	mfc1	$t3,$f16
.L0f0e7c1c:
/*  f0e7c1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7c20:	0560fffb */ 	bltz	$t3,.L0f0e7c10
/*  f0e7c24:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0e7c28:
/*  f0e7c28:	afab0058 */ 	sw	$t3,0x58($sp)
/*  f0e7c2c:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e7c30:	44c9f800 */ 	ctc1	$t1,$31
/*  f0e7c34:	44802000 */ 	mtc1	$zero,$f4
/*  f0e7c38:	c4720040 */ 	lwc1	$f18,0x40($v1)
/*  f0e7c3c:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0e7c40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7c44:	4502000a */ 	bc1fl	.L0f0e7c70
/*  f0e7c48:	906a003d */ 	lbu	$t2,0x3d($v1)
/*  f0e7c4c:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0e7c50:	3c077f1b */ 	lui	$a3,%hi(var7f1b1fd0)
/*  f0e7c54:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0e7c58:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0e7c5c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e7c60:	00ed3821 */ 	addu	$a3,$a3,$t5
/*  f0e7c64:	10000010 */ 	beqz	$zero,.L0f0e7ca8
/*  f0e7c68:	8ce71fd0 */ 	lw	$a3,%lo(var7f1b1fd0)($a3)
/*  f0e7c6c:	906a003d */ 	lbu	$t2,0x3d($v1)
.L0f0e7c70:
/*  f0e7c70:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e7c74:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e7c78:	000a7100 */ 	sll	$t6,$t2,0x4
/*  f0e7c7c:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0e7c80:	01ca7023 */ 	subu	$t6,$t6,$t2
/*  f0e7c84:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0e7c88:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0e7c8c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0e7c90:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0e7c94:	00594021 */ 	addu	$t0,$v0,$t9
/*  f0e7c98:	8d050020 */ 	lw	$a1,0x20($t0)
/*  f0e7c9c:	0fc01a40 */ 	jal	func0f006900
/*  f0e7ca0:	8de40020 */ 	lw	$a0,0x20($t7)
/*  f0e7ca4:	00403825 */ 	or	$a3,$v0,$zero
.L0f0e7ca8:
/*  f0e7ca8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e7cac:	322500ff */ 	andi	$a1,$s1,0xff
/*  f0e7cb0:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e7cb4:	0fc01a40 */ 	jal	func0f006900
/*  f0e7cb8:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0e7cbc:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f0e7cc0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7cc4:	0fc01a40 */ 	jal	func0f006900
/*  f0e7cc8:	8fa60058 */ 	lw	$a2,0x58($sp)
/*  f0e7ccc:	10000053 */ 	beqz	$zero,.L0f0e7e1c
/*  f0e7cd0:	00408825 */ 	or	$s1,$v0,$zero
.L0f0e7cd4:
/*  f0e7cd4:	44816000 */ 	mtc1	$at,$f12
/*  f0e7cd8:	0fc01ac2 */ 	jal	func0f006b08
/*  f0e7cdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7ce0:	3c01437f */ 	lui	$at,0x437f
/*  f0e7ce4:	44813000 */ 	mtc1	$at,$f6
/*  f0e7ce8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e7cec:	3c0f7f1b */ 	lui	$t7,%hi(var7f1b1fb0)
/*  f0e7cf0:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0e7cf4:	25ef1fb0 */ 	addiu	$t7,$t7,%lo(var7f1b1fb0)
/*  f0e7cf8:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e7cfc:	4449f800 */ 	cfc1	$t1,$31
/*  f0e7d00:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e7d04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7d08:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0e7d0c:	444bf800 */ 	cfc1	$t3,$31
/*  f0e7d10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7d14:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e7d18:	51600013 */ 	beqzl	$t3,.L0f0e7d68
/*  f0e7d1c:	440b5000 */ 	mfc1	$t3,$f10
/*  f0e7d20:	44815000 */ 	mtc1	$at,$f10
/*  f0e7d24:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e7d28:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0e7d2c:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e7d30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7d34:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0e7d38:	444bf800 */ 	cfc1	$t3,$31
/*  f0e7d3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7d40:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e7d44:	15600005 */ 	bnez	$t3,.L0f0e7d5c
/*  f0e7d48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7d4c:	440b5000 */ 	mfc1	$t3,$f10
/*  f0e7d50:	3c018000 */ 	lui	$at,0x8000
/*  f0e7d54:	10000007 */ 	beqz	$zero,.L0f0e7d74
/*  f0e7d58:	01615825 */ 	or	$t3,$t3,$at
.L0f0e7d5c:
/*  f0e7d5c:	10000005 */ 	beqz	$zero,.L0f0e7d74
/*  f0e7d60:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0e7d64:	440b5000 */ 	mfc1	$t3,$f10
.L0f0e7d68:
/*  f0e7d68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7d6c:	0560fffb */ 	bltz	$t3,.L0f0e7d5c
/*  f0e7d70:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0e7d74:
/*  f0e7d74:	afab0050 */ 	sw	$t3,0x50($sp)
/*  f0e7d78:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e7d7c:	44c9f800 */ 	ctc1	$t1,$31
/*  f0e7d80:	44809000 */ 	mtc1	$zero,$f18
/*  f0e7d84:	c4700040 */ 	lwc1	$f16,0x40($v1)
/*  f0e7d88:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0e7d8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7d90:	4502000a */ 	bc1fl	.L0f0e7dbc
/*  f0e7d94:	906a003d */ 	lbu	$t2,0x3d($v1)
/*  f0e7d98:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0e7d9c:	3c077f1b */ 	lui	$a3,%hi(var7f1b1fd0)
/*  f0e7da0:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0e7da4:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0e7da8:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e7dac:	00ed3821 */ 	addu	$a3,$a3,$t5
/*  f0e7db0:	10000010 */ 	beqz	$zero,.L0f0e7df4
/*  f0e7db4:	8ce71fd0 */ 	lw	$a3,%lo(var7f1b1fd0)($a3)
/*  f0e7db8:	906a003d */ 	lbu	$t2,0x3d($v1)
.L0f0e7dbc:
/*  f0e7dbc:	9079003c */ 	lbu	$t9,0x3c($v1)
/*  f0e7dc0:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e7dc4:	000a7100 */ 	sll	$t6,$t2,0x4
/*  f0e7dc8:	00194100 */ 	sll	$t0,$t9,0x4
/*  f0e7dcc:	01ca7023 */ 	subu	$t6,$t6,$t2
/*  f0e7dd0:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0e7dd4:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0e7dd8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0e7ddc:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0e7de0:	010f4821 */ 	addu	$t1,$t0,$t7
/*  f0e7de4:	8d250020 */ 	lw	$a1,0x20($t1)
/*  f0e7de8:	0fc01a40 */ 	jal	func0f006900
/*  f0e7dec:	8f040020 */ 	lw	$a0,0x20($t8)
/*  f0e7df0:	00403825 */ 	or	$a3,$v0,$zero
.L0f0e7df4:
/*  f0e7df4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e7df8:	322500ff */ 	andi	$a1,$s1,0xff
/*  f0e7dfc:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e7e00:	0fc01a40 */ 	jal	func0f006900
/*  f0e7e04:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e7e08:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e7e0c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7e10:	0fc01a40 */ 	jal	func0f006900
/*  f0e7e14:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0e7e18:	00408825 */ 	or	$s1,$v0,$zero
.L0f0e7e1c:
/*  f0e7e1c:	8e0b0010 */ 	lw	$t3,0x10($s0)
/*  f0e7e20:	3c047f1b */ 	lui	$a0,%hi(var7f1b22a0)
/*  f0e7e24:	3c057f1b */ 	lui	$a1,%hi(var7f1b2138)
/*  f0e7e28:	9162003c */ 	lbu	$v0,0x3c($t3)
/*  f0e7e2c:	00026100 */ 	sll	$t4,$v0,0x4
/*  f0e7e30:	01826023 */ 	subu	$t4,$t4,$v0
/*  f0e7e34:	000c1080 */ 	sll	$v0,$t4,0x2
/*  f0e7e38:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e7e3c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e7e40:	8ca52138 */ 	lw	$a1,%lo(var7f1b2138)($a1)
/*  f0e7e44:	0fc54f8e */ 	jal	func0f153e38
/*  f0e7e48:	8c8422a0 */ 	lw	$a0,%lo(var7f1b22a0)($a0)
/*  f0e7e4c:	1000000e */ 	beqz	$zero,.L0f0e7e88
/*  f0e7e50:	8e040008 */ 	lw	$a0,0x8($s0)
.L0f0e7e54:
/*  f0e7e54:	8e0d0010 */ 	lw	$t5,0x10($s0)
/*  f0e7e58:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0e7e5c:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0e7e60:	91a2003c */ 	lbu	$v0,0x3c($t5)
/*  f0e7e64:	00025100 */ 	sll	$t2,$v0,0x4
/*  f0e7e68:	01425023 */ 	subu	$t2,$t2,$v0
/*  f0e7e6c:	000a1080 */ 	sll	$v0,$t2,0x2
/*  f0e7e70:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e7e74:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e7e78:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0e7e7c:	0fc54f8e */ 	jal	func0f153e38
/*  f0e7e80:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
/*  f0e7e84:	8e040008 */ 	lw	$a0,0x8($s0)
.L0f0e7e88:
/*  f0e7e88:	0fc3c962 */ 	jal	func0f0f2588
/*  f0e7e8c:	8e050010 */ 	lw	$a1,0x10($s0)
/*  f0e7e90:	10400038 */ 	beqz	$v0,.L0f0e7f74
/*  f0e7e94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7e98:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e7e9c:	44803000 */ 	mtc1	$zero,$f6
/*  f0e7ea0:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0e7ea4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e7ea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e7eac:	4502000a */ 	bc1fl	.L0f0e7ed8
/*  f0e7eb0:	9079003d */ 	lbu	$t9,0x3d($v1)
/*  f0e7eb4:	906e003c */ 	lbu	$t6,0x3c($v1)
/*  f0e7eb8:	3c117f1b */ 	lui	$s1,%hi(var7f1b1fcc)
/*  f0e7ebc:	000ec100 */ 	sll	$t8,$t6,0x4
/*  f0e7ec0:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f0e7ec4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0e7ec8:	02388821 */ 	addu	$s1,$s1,$t8
/*  f0e7ecc:	10000012 */ 	beqz	$zero,.L0f0e7f18
/*  f0e7ed0:	8e311fcc */ 	lw	$s1,%lo(var7f1b1fcc)($s1)
/*  f0e7ed4:	9079003d */ 	lbu	$t9,0x3d($v1)
.L0f0e7ed8:
/*  f0e7ed8:	2407003c */ 	addiu	$a3,$zero,0x3c
/*  f0e7edc:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0e7ee0:	03270019 */ 	multu	$t9,$a3
/*  f0e7ee4:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0e7ee8:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0e7eec:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e7ef0:	00004012 */ 	mflo	$t0
/*  f0e7ef4:	00487821 */ 	addu	$t7,$v0,$t0
/*  f0e7ef8:	8de4001c */ 	lw	$a0,0x1c($t7)
/*  f0e7efc:	01270019 */ 	multu	$t1,$a3
/*  f0e7f00:	00005812 */ 	mflo	$t3
/*  f0e7f04:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f0e7f08:	0fc01a40 */ 	jal	func0f006900
/*  f0e7f0c:	8d85001c */ 	lw	$a1,0x1c($t4)
/*  f0e7f10:	00408825 */ 	or	$s1,$v0,$zero
/*  f0e7f14:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0e7f18:
/*  f0e7f18:	8c6d000c */ 	lw	$t5,0xc($v1)
/*  f0e7f1c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e7f20:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e7f24:	51a00009 */ 	beqzl	$t5,.L0f0e7f4c
/*  f0e7f28:	9062003c */ 	lbu	$v0,0x3c($v1)
/*  f0e7f2c:	0fc01a40 */ 	jal	func0f006900
/*  f0e7f30:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e7f34:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e7f38:	00415024 */ 	and	$t2,$v0,$at
/*  f0e7f3c:	322e00ff */ 	andi	$t6,$s1,0xff
/*  f0e7f40:	014e8825 */ 	or	$s1,$t2,$t6
/*  f0e7f44:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e7f48:	9062003c */ 	lbu	$v0,0x3c($v1)
.L0f0e7f4c:
/*  f0e7f4c:	3c047f1b */ 	lui	$a0,%hi(var7f1b229c)
/*  f0e7f50:	3c057f1b */ 	lui	$a1,%hi(var7f1b2134)
/*  f0e7f54:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f0e7f58:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f0e7f5c:	00181080 */ 	sll	$v0,$t8,0x2
/*  f0e7f60:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e7f64:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e7f68:	8ca52134 */ 	lw	$a1,%lo(var7f1b2134)($a1)
/*  f0e7f6c:	0fc54f8e */ 	jal	func0f153e38
/*  f0e7f70:	8c84229c */ 	lw	$a0,%lo(var7f1b229c)($a0)
.L0f0e7f74:
/*  f0e7f74:	0fc54d8a */ 	jal	func0f153628
/*  f0e7f78:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0e7f7c:	86190000 */ 	lh	$t9,0x0($s0)
/*  f0e7f80:	3c0b8008 */ 	lui	$t3,%hi(var8007fb10)
/*  f0e7f84:	3c0c8008 */ 	lui	$t4,%hi(var8007fb0c)
/*  f0e7f88:	2728000a */ 	addiu	$t0,$t9,0xa
/*  f0e7f8c:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0e7f90:	860f0002 */ 	lh	$t7,0x2($s0)
/*  f0e7f94:	8d8cfb0c */ 	lw	$t4,%lo(var8007fb0c)($t4)
/*  f0e7f98:	8d6bfb10 */ 	lw	$t3,%lo(var8007fb10)($t3)
/*  f0e7f9c:	25e90002 */ 	addiu	$t1,$t7,0x2
/*  f0e7fa0:	afa90070 */ 	sw	$t1,0x70($sp)
/*  f0e7fa4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e7fa8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e7fac:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e7fb0:	860d0004 */ 	lh	$t5,0x4($s0)
/*  f0e7fb4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7fb8:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f0e7fbc:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e7fc0:	860a0006 */ 	lh	$t2,0x6($s0)
/*  f0e7fc4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e7fc8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e7fcc:	27a60070 */ 	addiu	$a2,$sp,0x70
/*  f0e7fd0:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0e7fd4:	0fc5580f */ 	jal	func0f15603c
/*  f0e7fd8:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0e7fdc:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f0e7fe0:	8e0e0010 */ 	lw	$t6,0x10($s0)
/*  f0e7fe4:	91d8006e */ 	lbu	$t8,0x6e($t6)
/*  f0e7fe8:	53000006 */ 	beqzl	$t8,.L0f0e8004
/*  f0e7fec:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f0e7ff0:	86190000 */ 	lh	$t9,0x0($s0)
/*  f0e7ff4:	27280050 */ 	addiu	$t0,$t9,0x50
/*  f0e7ff8:	10000006 */ 	beqz	$zero,.L0f0e8014
/*  f0e7ffc:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0e8000:	860f0000 */ 	lh	$t7,0x0($s0)
.L0f0e8004:
/*  f0e8004:	86090004 */ 	lh	$t1,0x4($s0)
/*  f0e8008:	01e95821 */ 	addu	$t3,$t7,$t1
/*  f0e800c:	256cffc4 */ 	addiu	$t4,$t3,-60
/*  f0e8010:	afac0074 */ 	sw	$t4,0x74($sp)
.L0f0e8014:
/*  f0e8014:	8e0d0008 */ 	lw	$t5,0x8($s0)
/*  f0e8018:	8daa0004 */ 	lw	$t2,0x4($t5)
/*  f0e801c:	314e0080 */ 	andi	$t6,$t2,0x80
/*  f0e8020:	51c00005 */ 	beqzl	$t6,.L0f0e8038
/*  f0e8024:	86080002 */ 	lh	$t0,0x2($s0)
/*  f0e8028:	86180000 */ 	lh	$t8,0x0($s0)
/*  f0e802c:	2719001e */ 	addiu	$t9,$t8,0x1e
/*  f0e8030:	afb90074 */ 	sw	$t9,0x74($sp)
/*  f0e8034:	86080002 */ 	lh	$t0,0x2($s0)
.L0f0e8038:
/*  f0e8038:	250f0002 */ 	addiu	$t7,$t0,0x2
/*  f0e803c:	afaf0070 */ 	sw	$t7,0x70($sp)
/*  f0e8040:	8e090008 */ 	lw	$t1,0x8($s0)
/*  f0e8044:	8d2b0010 */ 	lw	$t3,0x10($t1)
/*  f0e8048:	11600034 */ 	beqz	$t3,.L0f0e811c
/*  f0e804c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8050:	afa00060 */ 	sw	$zero,0x60($sp)
/*  f0e8054:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f0e8058:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0e805c:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f0e8060:	8cb90010 */ 	lw	$t9,0x10($a1)
/*  f0e8064:	0320f809 */ 	jalr	$t9
/*  f0e8068:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e806c:	afa00064 */ 	sw	$zero,0x64($sp)
/*  f0e8070:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f0e8074:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e8078:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f0e807c:	8cb90010 */ 	lw	$t9,0x10($a1)
/*  f0e8080:	0320f809 */ 	jalr	$t9
/*  f0e8084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8088:	3c0c8008 */ 	lui	$t4,%hi(var8007fb0c)
/*  f0e808c:	8d8cfb0c */ 	lw	$t4,%lo(var8007fb0c)($t4)
/*  f0e8090:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0e8094:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0e8098:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0e809c:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f0e80a0:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f0e80a4:	00403025 */ 	or	$a2,$v0,$zero
/*  f0e80a8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e80ac:	0fc55cbe */ 	jal	func0f1572f8
/*  f0e80b0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e80b4:	860d0000 */ 	lh	$t5,0x0($s0)
/*  f0e80b8:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f0e80bc:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f0e80c0:	3c098008 */ 	lui	$t1,%hi(var8007fb10)
/*  f0e80c4:	3c0b8008 */ 	lui	$t3,%hi(var8007fb0c)
/*  f0e80c8:	8d6bfb0c */ 	lw	$t3,%lo(var8007fb0c)($t3)
/*  f0e80cc:	8d29fb10 */ 	lw	$t1,%lo(var8007fb10)($t1)
/*  f0e80d0:	01aa7021 */ 	addu	$t6,$t5,$t2
/*  f0e80d4:	01d84023 */ 	subu	$t0,$t6,$t8
/*  f0e80d8:	250ffff6 */ 	addiu	$t7,$t0,-10
/*  f0e80dc:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f0e80e0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e80e4:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e80e8:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0e80ec:	86190004 */ 	lh	$t9,0x4($s0)
/*  f0e80f0:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0e80f4:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f0e80f8:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e80fc:	860c0006 */ 	lh	$t4,0x6($s0)
/*  f0e8100:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e8104:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e8108:	27a60070 */ 	addiu	$a2,$sp,0x70
/*  f0e810c:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0e8110:	0fc5580f */ 	jal	func0f15603c
/*  f0e8114:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0e8118:	afa20080 */ 	sw	$v0,0x80($sp)
.L0f0e811c:
/*  f0e811c:	0fc54de0 */ 	jal	func0f153780
/*  f0e8120:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0e8124:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e8128:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0e812c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0e8130:	03e00008 */ 	jr	$ra
/*  f0e8134:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

GLOBAL_ASM(
glabel func0f0e8138
/*  f0e8138:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0e813c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e8140:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e8144:	30ef0002 */ 	andi	$t7,$a3,0x2
/*  f0e8148:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0e814c:	00808825 */ 	or	$s1,$a0,$zero
/*  f0e8150:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0e8154:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0e8158:	11e00047 */ 	beqz	$t7,.L0f0e8278
/*  f0e815c:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f0e8160:	8c980010 */ 	lw	$t8,0x10($a0)
/*  f0e8164:	53000045 */ 	beqzl	$t8,.L0f0e827c
/*  f0e8168:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0e816c:	8cb9000c */ 	lw	$t9,0xc($a1)
/*  f0e8170:	53200018 */ 	beqzl	$t9,.L0f0e81d4
/*  f0e8174:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0e8178:	8ca80008 */ 	lw	$t0,0x8($a1)
/*  f0e817c:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0e8180:	00e03025 */ 	or	$a2,$a3,$zero
/*  f0e8184:	54880013 */ 	bnel	$a0,$t0,.L0f0e81d4
/*  f0e8188:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0e818c:	0fc39d68 */ 	jal	func0f0e75a0
/*  f0e8190:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0e8194:	3c048007 */ 	lui	$a0,%hi(g_MpPlayerNum)
/*  f0e8198:	0fc62ff6 */ 	jal	mpIsPlayerLockedOut
/*  f0e819c:	8c841448 */ 	lw	$a0,%lo(g_MpPlayerNum)($a0)
/*  f0e81a0:	5040000c */ 	beqzl	$v0,.L0f0e81d4
/*  f0e81a4:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0e81a8:	8e290004 */ 	lw	$t1,0x4($s1)
/*  f0e81ac:	00095340 */ 	sll	$t2,$t1,0xd
/*  f0e81b0:	05420007 */ 	bltzl	$t2,.L0f0e81d0
/*  f0e81b4:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f0e81b8:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f0e81bc:	8d6c0010 */ 	lw	$t4,0x10($t3)
/*  f0e81c0:	318d0010 */ 	andi	$t5,$t4,0x10
/*  f0e81c4:	51a00003 */ 	beqzl	$t5,.L0f0e81d4
/*  f0e81c8:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0e81cc:	ae00000c */ 	sw	$zero,0xc($s0)
.L0f0e81d0:
/*  f0e81d0:	8faf0040 */ 	lw	$t7,0x40($sp)
.L0f0e81d4:
/*  f0e81d4:	91f80003 */ 	lbu	$t8,0x3($t7)
/*  f0e81d8:	5300000a */ 	beqzl	$t8,.L0f0e8204
/*  f0e81dc:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0e81e0:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f0e81e4:	53200007 */ 	beqzl	$t9,.L0f0e8204
/*  f0e81e8:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0e81ec:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f0e81f0:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f0e81f4:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0e81f8:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0e81fc:	a1000003 */ 	sb	$zero,0x3($t0)
/*  f0e8200:	8fae0040 */ 	lw	$t6,0x40($sp)
.L0f0e8204:
/*  f0e8204:	91c90002 */ 	lbu	$t1,0x2($t6)
/*  f0e8208:	5120001c */ 	beqzl	$t1,.L0f0e827c
/*  f0e820c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0e8210:	8e0a000c */ 	lw	$t2,0xc($s0)
/*  f0e8214:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e8218:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e821c:	51400004 */ 	beqzl	$t2,.L0f0e8230
/*  f0e8220:	ae0b000c */ 	sw	$t3,0xc($s0)
/*  f0e8224:	10000014 */ 	beqz	$zero,.L0f0e8278
/*  f0e8228:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f0e822c:	ae0b000c */ 	sw	$t3,0xc($s0)
.L0f0e8230:
/*  f0e8230:	0fc39e66 */ 	jal	func0f0e7998
/*  f0e8234:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f0e8238:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e823c:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e8240:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0e8244:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e8248:	0320f809 */ 	jalr	$t9
/*  f0e824c:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f0e8250:	3c0d8007 */ 	lui	$t5,%hi(var800711a8)
/*  f0e8254:	8dad11a8 */ 	lw	$t5,%lo(var800711a8)($t5)
/*  f0e8258:	8fac0024 */ 	lw	$t4,0x24($sp)
/*  f0e825c:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f0e8260:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0e8264:	018d0019 */ 	multu	$t4,$t5
/*  f0e8268:	00007812 */ 	mflo	$t7
/*  f0e826c:	a70f000e */ 	sh	$t7,0xe($t8)
/*  f0e8270:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0e8274:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0e8278:
/*  f0e8278:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0e827c:
/*  f0e827c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0e8280:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0e8284:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0e8288:	03e00008 */ 	jr	$ra
/*  f0e828c:	24020001 */ 	addiu	$v0,$zero,0x1
);

GLOBAL_ASM(
glabel func0f0e8290
/*  f0e8290:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f0e8294:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0e8298:	8fb000b8 */ 	lw	$s0,0xb8($sp)
/*  f0e829c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e82a0:	afb70038 */ 	sw	$s7,0x38($sp)
/*  f0e82a4:	afb60034 */ 	sw	$s6,0x34($sp)
/*  f0e82a8:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f0e82ac:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f0e82b0:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f0e82b4:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0e82b8:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e82bc:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f0e82c0:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f0e82c4:	afa600a8 */ 	sw	$a2,0xa8($sp)
/*  f0e82c8:	afa700ac */ 	sw	$a3,0xac($sp)
/*  f0e82cc:	9219006e */ 	lbu	$t9,0x6e($s0)
/*  f0e82d0:	00059400 */ 	sll	$s2,$a1,0x10
/*  f0e82d4:	00127403 */ 	sra	$t6,$s2,0x10
/*  f0e82d8:	00067c00 */ 	sll	$t7,$a2,0x10
/*  f0e82dc:	000f3403 */ 	sra	$a2,$t7,0x10
/*  f0e82e0:	13200004 */ 	beqz	$t9,.L0f0e82f4
/*  f0e82e4:	01c09025 */ 	or	$s2,$t6,$zero
/*  f0e82e8:	25c8004e */ 	addiu	$t0,$t6,0x4e
/*  f0e82ec:	1000000a */ 	beqz	$zero,.L0f0e8318
/*  f0e82f0:	a7a8006c */ 	sh	$t0,0x6c($sp)
.L0f0e82f4:
/*  f0e82f4:	87a900ae */ 	lh	$t1,0xae($sp)
/*  f0e82f8:	87ab00ae */ 	lh	$t3,0xae($sp)
/*  f0e82fc:	264a0002 */ 	addiu	$t2,$s2,0x2
/*  f0e8300:	05210003 */ 	bgez	$t1,.L0f0e8310
/*  f0e8304:	024b6021 */ 	addu	$t4,$s2,$t3
/*  f0e8308:	10000003 */ 	beqz	$zero,.L0f0e8318
/*  f0e830c:	a7aa006c */ 	sh	$t2,0x6c($sp)
.L0f0e8310:
/*  f0e8310:	258dffc2 */ 	addiu	$t5,$t4,-62
/*  f0e8314:	a7ad006c */ 	sh	$t5,0x6c($sp)
.L0f0e8318:
/*  f0e8318:	8fb100b4 */ 	lw	$s1,0xb4($sp)
/*  f0e831c:	2658001e */ 	addiu	$t8,$s2,0x1e
/*  f0e8320:	24d90001 */ 	addiu	$t9,$a2,0x1
/*  f0e8324:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*  f0e8328:	24080038 */ 	addiu	$t0,$zero,0x38
/*  f0e832c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0e8330:	31cf0080 */ 	andi	$t7,$t6,0x80
/*  f0e8334:	51e00003 */ 	beqzl	$t7,.L0f0e8344
/*  f0e8338:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f0e833c:	a7b8006c */ 	sh	$t8,0x6c($sp)
/*  f0e8340:	8faa00bc */ 	lw	$t2,0xbc($sp)
.L0f0e8344:
/*  f0e8344:	a7b9006e */ 	sh	$t9,0x6e($sp)
/*  f0e8348:	a7a80070 */ 	sh	$t0,0x70($sp)
/*  f0e834c:	afb10074 */ 	sw	$s1,0x74($sp)
/*  f0e8350:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0e8354:	afb0007c */ 	sw	$s0,0x7c($sp)
/*  f0e8358:	afaa0080 */ 	sw	$t2,0x80($sp)
/*  f0e835c:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f0e8360:	51600073 */ 	beqzl	$t3,.L0f0e8530
/*  f0e8364:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e8368:	8e220010 */ 	lw	$v0,0x10($s1)
/*  f0e836c:	50400070 */ 	beqzl	$v0,.L0f0e8530
/*  f0e8370:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e8374:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f0e8378:	562c006d */ 	bnel	$s1,$t4,.L0f0e8530
/*  f0e837c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e8380:	8e2d0004 */ 	lw	$t5,0x4($s1)
/*  f0e8384:	2418000b */ 	addiu	$t8,$zero,0xb
/*  f0e8388:	3c018007 */ 	lui	$at,0x8007
/*  f0e838c:	000d7280 */ 	sll	$t6,$t5,0xa
/*  f0e8390:	05c10009 */ 	bgez	$t6,.L0f0e83b8
/*  f0e8394:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f0e8398:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e839c:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*  f0e83a0:	0040f809 */ 	jalr	$v0
/*  f0e83a4:	a7b200a6 */ 	sh	$s2,0xa6($sp)
/*  f0e83a8:	8faf004c */ 	lw	$t7,0x4c($sp)
/*  f0e83ac:	3c018007 */ 	lui	$at,%hi(var800711a8)
/*  f0e83b0:	10000003 */ 	beqz	$zero,.L0f0e83c0
/*  f0e83b4:	ac2f11a8 */ 	sw	$t7,%lo(var800711a8)($at)
.L0f0e83b8:
/*  f0e83b8:	ac3811a8 */ 	sw	$t8,0x11a8($at)
/*  f0e83bc:	a7b200a6 */ 	sh	$s2,0xa6($sp)
.L0f0e83c0:
/*  f0e83c0:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e83c4:	27b7005c */ 	addiu	$s7,$sp,0x5c
/*  f0e83c8:	87b200a6 */ 	lh	$s2,0xa6($sp)
/*  f0e83cc:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0e83d0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0e83d4:	0320f809 */ 	jalr	$t9
/*  f0e83d8:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e83dc:	3c088007 */ 	lui	$t0,%hi(var800711a8)
/*  f0e83e0:	8fb6005c */ 	lw	$s6,0x5c($sp)
/*  f0e83e4:	8d0811a8 */ 	lw	$t0,%lo(var800711a8)($t0)
/*  f0e83e8:	a7a00070 */ 	sh	$zero,0x70($sp)
/*  f0e83ec:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e83f0:	01160019 */ 	multu	$t0,$s6
/*  f0e83f4:	00004812 */ 	mflo	$t1
/*  f0e83f8:	a7a90072 */ 	sh	$t1,0x72($sp)
/*  f0e83fc:	52c00021 */ 	beqzl	$s6,.L0f0e8484
/*  f0e8400:	87ac00ae */ 	lh	$t4,0xae($sp)
/*  f0e8404:	3c158008 */ 	lui	$s5,%hi(var8007fb0c)
/*  f0e8408:	3c148008 */ 	lui	$s4,%hi(var8007fb10)
/*  f0e840c:	2694fb10 */ 	addiu	$s4,$s4,%lo(var8007fb10)
/*  f0e8410:	26b5fb0c */ 	addiu	$s5,$s5,%lo(var8007fb0c)
/*  f0e8414:	27b30098 */ 	addiu	$s3,$sp,0x98
/*  f0e8418:	27b20094 */ 	addiu	$s2,$sp,0x94
/*  f0e841c:	afb0005c */ 	sw	$s0,0x5c($sp)
.L0f0e8420:
/*  f0e8420:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e8424:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e8428:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e842c:	0320f809 */ 	jalr	$t9
/*  f0e8430:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0e8434:	8eaa0000 */ 	lw	$t2,0x0($s5)
/*  f0e8438:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e843c:	02602825 */ 	or	$a1,$s3,$zero
/*  f0e8440:	00403025 */ 	or	$a2,$v0,$zero
/*  f0e8444:	8e870000 */ 	lw	$a3,0x0($s4)
/*  f0e8448:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e844c:	0fc55cbe */ 	jal	func0f1572f8
/*  f0e8450:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e8454:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0e8458:	87ab0070 */ 	lh	$t3,0x70($sp)
/*  f0e845c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0e8460:	24420006 */ 	addiu	$v0,$v0,0x6
/*  f0e8464:	0162082a */ 	slt	$at,$t3,$v0
/*  f0e8468:	10200003 */ 	beqz	$at,.L0f0e8478
/*  f0e846c:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0e8470:	a7a20070 */ 	sh	$v0,0x70($sp)
/*  f0e8474:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0e8478:
/*  f0e8478:	5616ffe9 */ 	bnel	$s0,$s6,.L0f0e8420
/*  f0e847c:	afb0005c */ 	sw	$s0,0x5c($sp)
/*  f0e8480:	87ac00ae */ 	lh	$t4,0xae($sp)
.L0f0e8484:
/*  f0e8484:	87ad00a6 */ 	lh	$t5,0xa6($sp)
/*  f0e8488:	59800007 */ 	blezl	$t4,.L0f0e84a8
/*  f0e848c:	8fa500b8 */ 	lw	$a1,0xb8($sp)
/*  f0e8490:	87af0070 */ 	lh	$t7,0x70($sp)
/*  f0e8494:	01ac7021 */ 	addu	$t6,$t5,$t4
/*  f0e8498:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f0e849c:	2708fff9 */ 	addiu	$t0,$t8,-7
/*  f0e84a0:	a7a8006c */ 	sh	$t0,0x6c($sp)
/*  f0e84a4:	8fa500b8 */ 	lw	$a1,0xb8($sp)
.L0f0e84a8:
/*  f0e84a8:	87b9006e */ 	lh	$t9,0x6e($sp)
/*  f0e84ac:	87aa0072 */ 	lh	$t2,0x72($sp)
/*  f0e84b0:	8ca30020 */ 	lw	$v1,0x20($a1)
/*  f0e84b4:	8ca90018 */ 	lw	$t1,0x18($a1)
/*  f0e84b8:	032a5821 */ 	addu	$t3,$t9,$t2
/*  f0e84bc:	01232021 */ 	addu	$a0,$t1,$v1
/*  f0e84c0:	248d0002 */ 	addiu	$t5,$a0,0x2
/*  f0e84c4:	01ab082a */ 	slt	$at,$t5,$t3
/*  f0e84c8:	10200014 */ 	beqz	$at,.L0f0e851c
/*  f0e84cc:	006a082a */ 	slt	$at,$v1,$t2
/*  f0e84d0:	1020000e */ 	beqz	$at,.L0f0e850c
/*  f0e84d4:	3c028007 */ 	lui	$v0,%hi(var800711a8)
/*  f0e84d8:	8c4211a8 */ 	lw	$v0,%lo(var800711a8)($v0)
/*  f0e84dc:	00608025 */ 	or	$s0,$v1,$zero
/*  f0e84e0:	0062001b */ 	divu	$zero,$v1,$v0
/*  f0e84e4:	00008012 */ 	mflo	$s0
/*  f0e84e8:	14400002 */ 	bnez	$v0,.L0f0e84f4
/*  f0e84ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e84f0:	0007000d */ 	break	0x7
.L0f0e84f4:
/*  f0e84f4:	02020019 */ 	multu	$s0,$v0
/*  f0e84f8:	00008012 */ 	mflo	$s0
/*  f0e84fc:	a7b00072 */ 	sh	$s0,0x72($sp)
/*  f0e8500:	8cae0020 */ 	lw	$t6,0x20($a1)
/*  f0e8504:	8cac0018 */ 	lw	$t4,0x18($a1)
/*  f0e8508:	018e2021 */ 	addu	$a0,$t4,$t6
.L0f0e850c:
/*  f0e850c:	87af0072 */ 	lh	$t7,0x72($sp)
/*  f0e8510:	008fc023 */ 	subu	$t8,$a0,$t7
/*  f0e8514:	27080002 */ 	addiu	$t0,$t8,0x2
/*  f0e8518:	a7a8006e */ 	sh	$t0,0x6e($sp)
.L0f0e851c:
/*  f0e851c:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0e8520:	0fc398ca */ 	jal	func0f0e6328
/*  f0e8524:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0e8528:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0e852c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0e8530:
/*  f0e8530:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f0e8534:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0e8538:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0e853c:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f0e8540:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f0e8544:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f0e8548:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f0e854c:	8fb60034 */ 	lw	$s6,0x34($sp)
/*  f0e8550:	8fb70038 */ 	lw	$s7,0x38($sp)
/*  f0e8554:	03e00008 */ 	jr	$ra
/*  f0e8558:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

GLOBAL_ASM(
glabel func0f0e855c
/*  f0e855c:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f0e8560:	14400003 */ 	bnez	$v0,.L0f0e8570
/*  f0e8564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8568:	03e00008 */ 	jr	$ra
/*  f0e856c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0e8570:
/*  f0e8570:	1040000b */ 	beqz	$v0,.L0f0e85a0
/*  f0e8574:	00801025 */ 	or	$v0,$a0,$zero
/*  f0e8578:	90830000 */ 	lbu	$v1,0x0($a0)
/*  f0e857c:	24040020 */ 	addiu	$a0,$zero,0x20
.L0f0e8580:
/*  f0e8580:	50830004 */ 	beql	$a0,$v1,.L0f0e8594
/*  f0e8584:	90430001 */ 	lbu	$v1,0x1($v0)
/*  f0e8588:	03e00008 */ 	jr	$ra
/*  f0e858c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e8590:	90430001 */ 	lbu	$v1,0x1($v0)
.L0f0e8594:
/*  f0e8594:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0e8598:	1460fff9 */ 	bnez	$v1,.L0f0e8580
/*  f0e859c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0e85a0:
/*  f0e85a0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0e85a4:	03e00008 */ 	jr	$ra
/*  f0e85a8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0e85ac
/*  f0e85ac:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f0e85b0:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f0e85b4:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f0e85b8:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f0e85bc:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f0e85c0:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f0e85c4:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f0e85c8:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f0e85cc:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f0e85d0:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f0e85d4:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f0e85d8:	f7b80048 */ 	sdc1	$f24,0x48($sp)
/*  f0e85dc:	f7b60040 */ 	sdc1	$f22,0x40($sp)
/*  f0e85e0:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f0e85e4:	afa400f8 */ 	sw	$a0,0xf8($sp)
/*  f0e85e8:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0e85ec:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f0e85f0:	a3af00f1 */ 	sb	$t7,0xf1($sp)
/*  f0e85f4:	a3a000f2 */ 	sb	$zero,0xf2($sp)
/*  f0e85f8:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f0e85fc:	8cb80010 */ 	lw	$t8,0x10($a1)
/*  f0e8600:	2415003c */ 	addiu	$s5,$zero,0x3c
/*  f0e8604:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f0e8608:	9319003c */ 	lbu	$t9,0x3c($t8)
/*  f0e860c:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0e8610:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0e8614:	03350019 */ 	multu	$t9,$s5
/*  f0e8618:	00001012 */ 	mflo	$v0
/*  f0e861c:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e8620:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e8624:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0e8628:	0fc54f8e */ 	jal	func0f153e38
/*  f0e862c:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
/*  f0e8630:	8fa400f8 */ 	lw	$a0,0xf8($sp)
/*  f0e8634:	0fc54df7 */ 	jal	func0f1537dc
/*  f0e8638:	3405ff7f */ 	dli	$a1,0xff7f
/*  f0e863c:	8e8a0008 */ 	lw	$t2,0x8($s4)
/*  f0e8640:	8d4b000c */ 	lw	$t3,0xc($t2)
/*  f0e8644:	15600021 */ 	bnez	$t3,.L0f0e86cc
/*  f0e8648:	244c0008 */ 	addiu	$t4,$v0,0x8
/*  f0e864c:	3c128008 */ 	lui	$s2,%hi(var8007fac0)
/*  f0e8650:	afac00f8 */ 	sw	$t4,0xf8($sp)
/*  f0e8654:	868d0000 */ 	lh	$t5,0x0($s4)
/*  f0e8658:	2652fac0 */ 	addiu	$s2,$s2,%lo(var8007fac0)
/*  f0e865c:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f0e8660:	25ae003f */ 	addiu	$t6,$t5,0x3f
/*  f0e8664:	868c0002 */ 	lh	$t4,0x2($s4)
/*  f0e8668:	01cf0019 */ 	multu	$t6,$t7
/*  f0e866c:	3c16f600 */ 	lui	$s6,0xf600
/*  f0e8670:	258d000a */ 	addiu	$t5,$t4,0xa
/*  f0e8674:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f0e8678:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0e867c:	0000c012 */ 	mflo	$t8
/*  f0e8680:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0e8684:	00195380 */ 	sll	$t2,$t9,0xe
/*  f0e8688:	01565825 */ 	or	$t3,$t2,$s6
/*  f0e868c:	016fc025 */ 	or	$t8,$t3,$t7
/*  f0e8690:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0e8694:	86990000 */ 	lh	$t9,0x0($s4)
/*  f0e8698:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f0e869c:	868f0002 */ 	lh	$t7,0x2($s4)
/*  f0e86a0:	272a0004 */ 	addiu	$t2,$t9,0x4
/*  f0e86a4:	014c0019 */ 	multu	$t2,$t4
/*  f0e86a8:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f0e86ac:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0e86b0:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0e86b4:	00006812 */ 	mflo	$t5
/*  f0e86b8:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f0e86bc:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f0e86c0:	016a6025 */ 	or	$t4,$t3,$t2
/*  f0e86c4:	10000021 */ 	beqz	$zero,.L0f0e874c
/*  f0e86c8:	ac4c0004 */ 	sw	$t4,0x4($v0)
.L0f0e86cc:
/*  f0e86cc:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f0e86d0:	3c128008 */ 	lui	$s2,%hi(var8007fac0)
/*  f0e86d4:	afad00f8 */ 	sw	$t5,0xf8($sp)
/*  f0e86d8:	868e0000 */ 	lh	$t6,0x0($s4)
/*  f0e86dc:	2652fac0 */ 	addiu	$s2,$s2,%lo(var8007fac0)
/*  f0e86e0:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0e86e4:	25cf007d */ 	addiu	$t7,$t6,0x7d
/*  f0e86e8:	868d0002 */ 	lh	$t5,0x2($s4)
/*  f0e86ec:	01f80019 */ 	multu	$t7,$t8
/*  f0e86f0:	3c16f600 */ 	lui	$s6,0xf600
/*  f0e86f4:	25ae000a */ 	addiu	$t6,$t5,0xa
/*  f0e86f8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0e86fc:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0e8700:	0000c812 */ 	mflo	$t9
/*  f0e8704:	332b03ff */ 	andi	$t3,$t9,0x3ff
/*  f0e8708:	000b5380 */ 	sll	$t2,$t3,0xe
/*  f0e870c:	01566025 */ 	or	$t4,$t2,$s6
/*  f0e8710:	0198c825 */ 	or	$t9,$t4,$t8
/*  f0e8714:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0e8718:	868b0000 */ 	lh	$t3,0x0($s4)
/*  f0e871c:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f0e8720:	86980002 */ 	lh	$t8,0x2($s4)
/*  f0e8724:	256a0004 */ 	addiu	$t2,$t3,0x4
/*  f0e8728:	014d0019 */ 	multu	$t2,$t5
/*  f0e872c:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0e8730:	332b03ff */ 	andi	$t3,$t9,0x3ff
/*  f0e8734:	000b5080 */ 	sll	$t2,$t3,0x2
/*  f0e8738:	00007012 */ 	mflo	$t6
/*  f0e873c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0e8740:	000f6380 */ 	sll	$t4,$t7,0xe
/*  f0e8744:	018a6825 */ 	or	$t5,$t4,$t2
/*  f0e8748:	ac4d0004 */ 	sw	$t5,0x4($v0)
.L0f0e874c:
/*  f0e874c:	0fc54e0e */ 	jal	func0f153838
/*  f0e8750:	8fa400f8 */ 	lw	$a0,0xf8($sp)
/*  f0e8754:	868e0000 */ 	lh	$t6,0x0($s4)
/*  f0e8758:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e875c:	25cf0004 */ 	addiu	$t7,$t6,0x4
/*  f0e8760:	afaf00ec */ 	sw	$t7,0xec($sp)
/*  f0e8764:	86980002 */ 	lh	$t8,0x2($s4)
/*  f0e8768:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f0e876c:	0fc54d8a */ 	jal	func0f153628
/*  f0e8770:	afb900e8 */ 	sw	$t9,0xe8($sp)
/*  f0e8774:	3c0b8008 */ 	lui	$t3,%hi(var8007fb10)
/*  f0e8778:	3c0c8008 */ 	lui	$t4,%hi(var8007fb0c)
/*  f0e877c:	8d8cfb0c */ 	lw	$t4,%lo(var8007fb0c)($t4)
/*  f0e8780:	8d6bfb10 */ 	lw	$t3,%lo(var8007fb10)($t3)
/*  f0e8784:	240affff */ 	addiu	$t2,$zero,-1
/*  f0e8788:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0e878c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e8790:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e8794:	868d0004 */ 	lh	$t5,0x4($s4)
/*  f0e8798:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e879c:	27a500ec */ 	addiu	$a1,$sp,0xec
/*  f0e87a0:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e87a4:	868e0006 */ 	lh	$t6,0x6($s4)
/*  f0e87a8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e87ac:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e87b0:	27a600e8 */ 	addiu	$a2,$sp,0xe8
/*  f0e87b4:	8fa700e4 */ 	lw	$a3,0xe4($sp)
/*  f0e87b8:	0fc5580f */ 	jal	func0f15603c
/*  f0e87bc:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f0e87c0:	0fc54de0 */ 	jal	func0f153780
/*  f0e87c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e87c8:	3c014220 */ 	lui	$at,0x4220
/*  f0e87cc:	4481b000 */ 	mtc1	$at,$f22
/*  f0e87d0:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0e87d4:	0fc01ac2 */ 	jal	func0f006b08
/*  f0e87d8:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e87dc:	3c01437f */ 	lui	$at,0x437f
/*  f0e87e0:	4481c000 */ 	mtc1	$at,$f24
/*  f0e87e4:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f0e87e8:	4480a000 */ 	mtc1	$zero,$f20
/*  f0e87ec:	46180102 */ 	mul.s	$f4,$f0,$f24
/*  f0e87f0:	444ff800 */ 	cfc1	$t7,$31
/*  f0e87f4:	44d3f800 */ 	ctc1	$s3,$31
/*  f0e87f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e87fc:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f0e8800:	4453f800 */ 	cfc1	$s3,$31
/*  f0e8804:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8808:	32730078 */ 	andi	$s3,$s3,0x78
/*  f0e880c:	12600012 */ 	beqz	$s3,.L0f0e8858
/*  f0e8810:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e8814:	44813000 */ 	mtc1	$at,$f6
/*  f0e8818:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f0e881c:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f0e8820:	44d3f800 */ 	ctc1	$s3,$31
/*  f0e8824:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8828:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0e882c:	4453f800 */ 	cfc1	$s3,$31
/*  f0e8830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8834:	32730078 */ 	andi	$s3,$s3,0x78
/*  f0e8838:	16600005 */ 	bnez	$s3,.L0f0e8850
/*  f0e883c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8840:	44133000 */ 	mfc1	$s3,$f6
/*  f0e8844:	3c018000 */ 	lui	$at,0x8000
/*  f0e8848:	10000007 */ 	beqz	$zero,.L0f0e8868
/*  f0e884c:	02619825 */ 	or	$s3,$s3,$at
.L0f0e8850:
/*  f0e8850:	10000005 */ 	beqz	$zero,.L0f0e8868
/*  f0e8854:	2413ffff */ 	addiu	$s3,$zero,-1
.L0f0e8858:
/*  f0e8858:	44133000 */ 	mfc1	$s3,$f6
/*  f0e885c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8860:	0660fffb */ 	bltz	$s3,.L0f0e8850
/*  f0e8864:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0e8868:
/*  f0e8868:	8e900010 */ 	lw	$s0,0x10($s4)
/*  f0e886c:	44cff800 */ 	ctc1	$t7,$31
/*  f0e8870:	c6080040 */ 	lwc1	$f8,0x40($s0)
/*  f0e8874:	4614403c */ 	c.lt.s	$f8,$f20
/*  f0e8878:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e887c:	4502000a */ 	bc1fl	.L0f0e88a8
/*  f0e8880:	920c003d */ 	lbu	$t4,0x3d($s0)
/*  f0e8884:	9218003c */ 	lbu	$t8,0x3c($s0)
/*  f0e8888:	3c1e7f1b */ 	lui	$s8,%hi(var7f1b1fb0)
/*  f0e888c:	27de1fb0 */ 	addiu	$s8,$s8,%lo(var7f1b1fb0)
/*  f0e8890:	03150019 */ 	multu	$t8,$s5
/*  f0e8894:	0000c812 */ 	mflo	$t9
/*  f0e8898:	03d95821 */ 	addu	$t3,$s8,$t9
/*  f0e889c:	10000010 */ 	beqz	$zero,.L0f0e88e0
/*  f0e88a0:	8d710020 */ 	lw	$s1,0x20($t3)
/*  f0e88a4:	920c003d */ 	lbu	$t4,0x3d($s0)
.L0f0e88a8:
/*  f0e88a8:	920e003c */ 	lbu	$t6,0x3c($s0)
/*  f0e88ac:	3c1e7f1b */ 	lui	$s8,%hi(var7f1b1fb0)
/*  f0e88b0:	01950019 */ 	multu	$t4,$s5
/*  f0e88b4:	27de1fb0 */ 	addiu	$s8,$s8,%lo(var7f1b1fb0)
/*  f0e88b8:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0e88bc:	00005012 */ 	mflo	$t2
/*  f0e88c0:	03ca6821 */ 	addu	$t5,$s8,$t2
/*  f0e88c4:	8da40020 */ 	lw	$a0,0x20($t5)
/*  f0e88c8:	01d50019 */ 	multu	$t6,$s5
/*  f0e88cc:	00007812 */ 	mflo	$t7
/*  f0e88d0:	03cfc021 */ 	addu	$t8,$s8,$t7
/*  f0e88d4:	0fc01a40 */ 	jal	func0f006900
/*  f0e88d8:	8f050020 */ 	lw	$a1,0x20($t8)
/*  f0e88dc:	00408825 */ 	or	$s1,$v0,$zero
.L0f0e88e0:
/*  f0e88e0:	3404ffff */ 	dli	$a0,0xffff
/*  f0e88e4:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f0e88e8:	0fc01a40 */ 	jal	func0f006900
/*  f0e88ec:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e88f0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e88f4:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e88f8:	0fc01a40 */ 	jal	func0f006900
/*  f0e88fc:	02603025 */ 	or	$a2,$s3,$zero
/*  f0e8900:	8fa400f8 */ 	lw	$a0,0xf8($sp)
/*  f0e8904:	0fc54df7 */ 	jal	func0f1537dc
/*  f0e8908:	00402825 */ 	or	$a1,$v0,$zero
/*  f0e890c:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0e8910:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f0e8914:	86980002 */ 	lh	$t8,0x2($s4)
/*  f0e8918:	272b0003 */ 	addiu	$t3,$t9,0x3
/*  f0e891c:	016c0019 */ 	multu	$t3,$t4
/*  f0e8920:	27190009 */ 	addiu	$t9,$t8,0x9
/*  f0e8924:	332b03ff */ 	andi	$t3,$t9,0x3ff
/*  f0e8928:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0e892c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0e8930:	00005012 */ 	mflo	$t2
/*  f0e8934:	314d03ff */ 	andi	$t5,$t2,0x3ff
/*  f0e8938:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f0e893c:	01d67825 */ 	or	$t7,$t6,$s6
/*  f0e8940:	01ec5025 */ 	or	$t2,$t7,$t4
/*  f0e8944:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f0e8948:	8fad00ec */ 	lw	$t5,0xec($sp)
/*  f0e894c:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0e8950:	868c0002 */ 	lh	$t4,0x2($s4)
/*  f0e8954:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0e8958:	01d80019 */ 	multu	$t6,$t8
/*  f0e895c:	258a0002 */ 	addiu	$t2,$t4,0x2
/*  f0e8960:	314d03ff */ 	andi	$t5,$t2,0x3ff
/*  f0e8964:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0e8968:	0000c812 */ 	mflo	$t9
/*  f0e896c:	332b03ff */ 	andi	$t3,$t9,0x3ff
/*  f0e8970:	000b7b80 */ 	sll	$t7,$t3,0xe
/*  f0e8974:	01eec025 */ 	or	$t8,$t7,$t6
/*  f0e8978:	0fc54e0e */ 	jal	func0f153838
/*  f0e897c:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0e8980:	3c1000ff */ 	lui	$s0,0xff
/*  f0e8984:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e8988:	3610ff7f */ 	ori	$s0,$s0,0xff7f
/*  f0e898c:	afa00088 */ 	sw	$zero,0x88($sp)
/*  f0e8990:	24110042 */ 	addiu	$s1,$zero,0x42
.L0f0e8994:
/*  f0e8994:	8fa80088 */ 	lw	$t0,0x88($sp)
/*  f0e8998:	86990002 */ 	lh	$t9,0x2($s4)
/*  f0e899c:	86820000 */ 	lh	$v0,0x0($s4)
/*  f0e89a0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e89a4:	03281821 */ 	addu	$v1,$t9,$t0
/*  f0e89a8:	246b000e */ 	addiu	$t3,$v1,0xe
/*  f0e89ac:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e89b0:	2466000d */ 	addiu	$a2,$v1,0xd
/*  f0e89b4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e89b8:	24450004 */ 	addiu	$a1,$v0,0x4
/*  f0e89bc:	0fc38bd7 */ 	jal	func0f0e2f5c
/*  f0e89c0:	2447007c */ 	addiu	$a3,$v0,0x7c
/*  f0e89c4:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f0e89c8:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0e89cc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e89d0:	2463000b */ 	addiu	$v1,$v1,0xb
/*  f0e89d4:	1471ffef */ 	bne	$v1,$s1,.L0f0e8994
/*  f0e89d8:	afa30088 */ 	sw	$v1,0x88($sp)
/*  f0e89dc:	afa00084 */ 	sw	$zero,0x84($sp)
/*  f0e89e0:	24170054 */ 	addiu	$s7,$zero,0x54
/*  f0e89e4:	24160048 */ 	addiu	$s6,$zero,0x48
/*  f0e89e8:	24130030 */ 	addiu	$s3,$zero,0x30
/*  f0e89ec:	24120024 */ 	addiu	$s2,$zero,0x24
/*  f0e89f0:	2411000c */ 	addiu	$s1,$zero,0xc
.L0f0e89f4:
/*  f0e89f4:	8fa80084 */ 	lw	$t0,0x84($sp)
/*  f0e89f8:	24090005 */ 	addiu	$t1,$zero,0x5
/*  f0e89fc:	5111000c */ 	beql	$t0,$s1,.L0f0e8a30
/*  f0e8a00:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f0e8a04:	5112000a */ 	beql	$t0,$s2,.L0f0e8a30
/*  f0e8a08:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f0e8a0c:	51130008 */ 	beql	$t0,$s3,.L0f0e8a30
/*  f0e8a10:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f0e8a14:	51160006 */ 	beql	$t0,$s6,.L0f0e8a30
/*  f0e8a18:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f0e8a1c:	11170003 */ 	beq	$t0,$s7,.L0f0e8a2c
/*  f0e8a20:	2401006c */ 	addiu	$at,$zero,0x6c
/*  f0e8a24:	55010003 */ 	bnel	$t0,$at,.L0f0e8a34
/*  f0e8a28:	00095080 */ 	sll	$t2,$t1,0x2
.L0f0e8a2c:
/*  f0e8a2c:	24090004 */ 	addiu	$t1,$zero,0x4
.L0f0e8a30:
/*  f0e8a30:	00095080 */ 	sll	$t2,$t1,0x2
.L0f0e8a34:
/*  f0e8a34:	86820002 */ 	lh	$v0,0x2($s4)
/*  f0e8a38:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e8a3c:	868c0000 */ 	lh	$t4,0x0($s4)
/*  f0e8a40:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0e8a44:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e8a48:	004a6821 */ 	addu	$t5,$v0,$t2
/*  f0e8a4c:	25af000e */ 	addiu	$t7,$t5,0xe
/*  f0e8a50:	01881821 */ 	addu	$v1,$t4,$t0
/*  f0e8a54:	24650004 */ 	addiu	$a1,$v1,0x4
/*  f0e8a58:	24670005 */ 	addiu	$a3,$v1,0x5
/*  f0e8a5c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e8a60:	afa80084 */ 	sw	$t0,0x84($sp)
/*  f0e8a64:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e8a68:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e8a6c:	0fc38bd7 */ 	jal	func0f0e2f5c
/*  f0e8a70:	2446000d */ 	addiu	$a2,$v0,0xd
/*  f0e8a74:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0e8a78:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0e8a7c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e8a80:	25d8000c */ 	addiu	$t8,$t6,0xc
/*  f0e8a84:	2b010084 */ 	slti	$at,$t8,0x84
/*  f0e8a88:	1420ffda */ 	bnez	$at,.L0f0e89f4
/*  f0e8a8c:	afb80084 */ 	sw	$t8,0x84($sp)
/*  f0e8a90:	0fc54d8a */ 	jal	func0f153628
/*  f0e8a94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8a98:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0e8a9c:	86990000 */ 	lh	$t9,0x0($s4)
/*  f0e8aa0:	0000b825 */ 	or	$s7,$zero,$zero
/*  f0e8aa4:	272b000a */ 	addiu	$t3,$t9,0xa
/*  f0e8aa8:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f0e8aac:	868c0002 */ 	lh	$t4,0x2($s4)
/*  f0e8ab0:	afa00084 */ 	sw	$zero,0x84($sp)
/*  f0e8ab4:	258a0002 */ 	addiu	$t2,$t4,0x2
/*  f0e8ab8:	afaa00e8 */ 	sw	$t2,0xe8($sp)
.L0f0e8abc:
/*  f0e8abc:	0000b025 */ 	or	$s6,$zero,$zero
/*  f0e8ac0:	afa00088 */ 	sw	$zero,0x88($sp)
.L0f0e8ac4:
/*  f0e8ac4:	8e900010 */ 	lw	$s0,0x10($s4)
/*  f0e8ac8:	c60a0040 */ 	lwc1	$f10,0x40($s0)
/*  f0e8acc:	4614503c */ 	c.lt.s	$f10,$f20
/*  f0e8ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8ad4:	45020008 */ 	bc1fl	.L0f0e8af8
/*  f0e8ad8:	9218003d */ 	lbu	$t8,0x3d($s0)
/*  f0e8adc:	920d003c */ 	lbu	$t5,0x3c($s0)
/*  f0e8ae0:	01b50019 */ 	multu	$t5,$s5
/*  f0e8ae4:	00007812 */ 	mflo	$t7
/*  f0e8ae8:	03cf7021 */ 	addu	$t6,$s8,$t7
/*  f0e8aec:	1000000f */ 	beqz	$zero,.L0f0e8b2c
/*  f0e8af0:	8dd20018 */ 	lw	$s2,0x18($t6)
/*  f0e8af4:	9218003d */ 	lbu	$t8,0x3d($s0)
.L0f0e8af8:
/*  f0e8af8:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0e8afc:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0e8b00:	03150019 */ 	multu	$t8,$s5
/*  f0e8b04:	0000c812 */ 	mflo	$t9
/*  f0e8b08:	03d95821 */ 	addu	$t3,$s8,$t9
/*  f0e8b0c:	8d640018 */ 	lw	$a0,0x18($t3)
/*  f0e8b10:	01950019 */ 	multu	$t4,$s5
/*  f0e8b14:	00005012 */ 	mflo	$t2
/*  f0e8b18:	03ca6821 */ 	addu	$t5,$s8,$t2
/*  f0e8b1c:	0fc01a40 */ 	jal	func0f006900
/*  f0e8b20:	8da50018 */ 	lw	$a1,0x18($t5)
/*  f0e8b24:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e8b28:	8e900010 */ 	lw	$s0,0x10($s4)
.L0f0e8b2c:
/*  f0e8b2c:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0e8b30:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e8b34:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e8b38:	51e00008 */ 	beqzl	$t7,.L0f0e8b5c
/*  f0e8b3c:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f0e8b40:	0fc01a40 */ 	jal	func0f006900
/*  f0e8b44:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e8b48:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e8b4c:	00417024 */ 	and	$t6,$v0,$at
/*  f0e8b50:	325800ff */ 	andi	$t8,$s2,0xff
/*  f0e8b54:	01d89025 */ 	or	$s2,$t6,$t8
/*  f0e8b58:	8fb900e4 */ 	lw	$t9,0xe4($sp)
.L0f0e8b5c:
/*  f0e8b5c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e8b60:	8fae00e4 */ 	lw	$t6,0xe4($sp)
/*  f0e8b64:	932b000d */ 	lbu	$t3,0xd($t9)
/*  f0e8b68:	000b5640 */ 	sll	$t2,$t3,0x19
/*  f0e8b6c:	05430008 */ 	bgezl	$t2,.L0f0e8b90
/*  f0e8b70:	81d8000b */ 	lb	$t8,0xb($t6)
/*  f0e8b74:	16e10005 */ 	bne	$s7,$at,.L0f0e8b8c
/*  f0e8b78:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0e8b7c:	16c10003 */ 	bne	$s6,$at,.L0f0e8b8c
/*  f0e8b80:	324d00ff */ 	andi	$t5,$s2,0xff
/*  f0e8b84:	3c01ffff */ 	lui	$at,0xffff
/*  f0e8b88:	01a19025 */ 	or	$s2,$t5,$at
.L0f0e8b8c:
/*  f0e8b8c:	81d8000b */ 	lb	$t8,0xb($t6)
.L0f0e8b90:
/*  f0e8b90:	56f8004b */ 	bnel	$s7,$t8,.L0f0e8cc0
/*  f0e8b94:	868a0000 */ 	lh	$t2,0x0($s4)
/*  f0e8b98:	81d9000c */ 	lb	$t9,0xc($t6)
/*  f0e8b9c:	56d90048 */ 	bnel	$s6,$t9,.L0f0e8cc0
/*  f0e8ba0:	868a0000 */ 	lh	$t2,0x0($s4)
/*  f0e8ba4:	0fc01ac2 */ 	jal	func0f006b08
/*  f0e8ba8:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e8bac:	46180402 */ 	mul.s	$f16,$f0,$f24
/*  f0e8bb0:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f0e8bb4:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e8bb8:	444bf800 */ 	cfc1	$t3,$31
/*  f0e8bbc:	44d3f800 */ 	ctc1	$s3,$31
/*  f0e8bc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8bc4:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f0e8bc8:	4453f800 */ 	cfc1	$s3,$31
/*  f0e8bcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8bd0:	32730078 */ 	andi	$s3,$s3,0x78
/*  f0e8bd4:	52600013 */ 	beqzl	$s3,.L0f0e8c24
/*  f0e8bd8:	44139000 */ 	mfc1	$s3,$f18
/*  f0e8bdc:	44819000 */ 	mtc1	$at,$f18
/*  f0e8be0:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f0e8be4:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f0e8be8:	44d3f800 */ 	ctc1	$s3,$31
/*  f0e8bec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8bf0:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f0e8bf4:	4453f800 */ 	cfc1	$s3,$31
/*  f0e8bf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8bfc:	32730078 */ 	andi	$s3,$s3,0x78
/*  f0e8c00:	16600005 */ 	bnez	$s3,.L0f0e8c18
/*  f0e8c04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8c08:	44139000 */ 	mfc1	$s3,$f18
/*  f0e8c0c:	3c018000 */ 	lui	$at,0x8000
/*  f0e8c10:	10000007 */ 	beqz	$zero,.L0f0e8c30
/*  f0e8c14:	02619825 */ 	or	$s3,$s3,$at
.L0f0e8c18:
/*  f0e8c18:	10000005 */ 	beqz	$zero,.L0f0e8c30
/*  f0e8c1c:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0e8c20:	44139000 */ 	mfc1	$s3,$f18
.L0f0e8c24:
/*  f0e8c24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8c28:	0660fffb */ 	bltz	$s3,.L0f0e8c18
/*  f0e8c2c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0e8c30:
/*  f0e8c30:	8e900010 */ 	lw	$s0,0x10($s4)
/*  f0e8c34:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e8c38:	c6040040 */ 	lwc1	$f4,0x40($s0)
/*  f0e8c3c:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0e8c40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8c44:	45020008 */ 	bc1fl	.L0f0e8c68
/*  f0e8c48:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f0e8c4c:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0e8c50:	01950019 */ 	multu	$t4,$s5
/*  f0e8c54:	00005012 */ 	mflo	$t2
/*  f0e8c58:	03ca6821 */ 	addu	$t5,$s8,$t2
/*  f0e8c5c:	1000000e */ 	beqz	$zero,.L0f0e8c98
/*  f0e8c60:	8db10020 */ 	lw	$s1,0x20($t5)
/*  f0e8c64:	920f003d */ 	lbu	$t7,0x3d($s0)
.L0f0e8c68:
/*  f0e8c68:	9219003c */ 	lbu	$t9,0x3c($s0)
/*  f0e8c6c:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0e8c70:	01f50019 */ 	multu	$t7,$s5
/*  f0e8c74:	0000c012 */ 	mflo	$t8
/*  f0e8c78:	03d87021 */ 	addu	$t6,$s8,$t8
/*  f0e8c7c:	8dc40020 */ 	lw	$a0,0x20($t6)
/*  f0e8c80:	03350019 */ 	multu	$t9,$s5
/*  f0e8c84:	00005812 */ 	mflo	$t3
/*  f0e8c88:	03cb6021 */ 	addu	$t4,$s8,$t3
/*  f0e8c8c:	0fc01a40 */ 	jal	func0f006900
/*  f0e8c90:	8d850020 */ 	lw	$a1,0x20($t4)
/*  f0e8c94:	00408825 */ 	or	$s1,$v0,$zero
.L0f0e8c98:
/*  f0e8c98:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e8c9c:	324500ff */ 	andi	$a1,$s2,0xff
/*  f0e8ca0:	0fc01a40 */ 	jal	func0f006900
/*  f0e8ca4:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e8ca8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e8cac:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e8cb0:	0fc01a40 */ 	jal	func0f006900
/*  f0e8cb4:	02603025 */ 	or	$a2,$s3,$zero
/*  f0e8cb8:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e8cbc:	868a0000 */ 	lh	$t2,0x0($s4)
.L0f0e8cc0:
/*  f0e8cc0:	8fad0084 */ 	lw	$t5,0x84($sp)
/*  f0e8cc4:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f0e8cc8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0e8ccc:	014d7821 */ 	addu	$t7,$t2,$t5
/*  f0e8cd0:	25f80004 */ 	addiu	$t8,$t7,0x4
/*  f0e8cd4:	afb800ec */ 	sw	$t8,0xec($sp)
/*  f0e8cd8:	868e0002 */ 	lh	$t6,0x2($s4)
/*  f0e8cdc:	0016c080 */ 	sll	$t8,$s6,0x2
/*  f0e8ce0:	0316c021 */ 	addu	$t8,$t8,$s6
/*  f0e8ce4:	01d95821 */ 	addu	$t3,$t6,$t9
/*  f0e8ce8:	256c000f */ 	addiu	$t4,$t3,0xf
/*  f0e8cec:	16c10095 */ 	bne	$s6,$at,.L0f0e8f44
/*  f0e8cf0:	afac00e8 */ 	sw	$t4,0xe8($sp)
/*  f0e8cf4:	3c0d8007 */ 	lui	$t5,%hi(var800711e0)
/*  f0e8cf8:	25ad11e0 */ 	addiu	$t5,$t5,%lo(var800711e0)
/*  f0e8cfc:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0e8d00:	8db80004 */ 	lw	$t8,0x4($t5)
/*  f0e8d04:	27aa00a8 */ 	addiu	$t2,$sp,0xa8
/*  f0e8d08:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0e8d0c:	ad410000 */ 	sw	$at,0x0($t2)
/*  f0e8d10:	16e00002 */ 	bnez	$s7,.L0f0e8d1c
/*  f0e8d14:	ad580004 */ 	sw	$t8,0x4($t2)
/*  f0e8d18:	00001025 */ 	or	$v0,$zero,$zero
.L0f0e8d1c:
/*  f0e8d1c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e8d20:	16e10002 */ 	bne	$s7,$at,.L0f0e8d2c
/*  f0e8d24:	8fae00e8 */ 	lw	$t6,0xe8($sp)
/*  f0e8d28:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0e8d2c:
/*  f0e8d2c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0e8d30:	16e10002 */ 	bne	$s7,$at,.L0f0e8d3c
/*  f0e8d34:	24100018 */ 	addiu	$s0,$zero,0x18
/*  f0e8d38:	24020002 */ 	addiu	$v0,$zero,0x2
.L0f0e8d3c:
/*  f0e8d3c:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0e8d40:	16e10002 */ 	bne	$s7,$at,.L0f0e8d4c
/*  f0e8d44:	25d90001 */ 	addiu	$t9,$t6,0x1
/*  f0e8d48:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f0e8d4c:
/*  f0e8d4c:	044000b5 */ 	bltz	$v0,.L0f0e9024
/*  f0e8d50:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e8d54:	10410004 */ 	beq	$v0,$at,.L0f0e8d68
/*  f0e8d58:	afb900e8 */ 	sw	$t9,0xe8($sp)
/*  f0e8d5c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e8d60:	54410003 */ 	bnel	$v0,$at,.L0f0e8d70
/*  f0e8d64:	00025840 */ 	sll	$t3,$v0,0x1
.L0f0e8d68:
/*  f0e8d68:	24100024 */ 	addiu	$s0,$zero,0x24
/*  f0e8d6c:	00025840 */ 	sll	$t3,$v0,0x1
.L0f0e8d70:
/*  f0e8d70:	27ac00a8 */ 	addiu	$t4,$sp,0xa8
/*  f0e8d74:	016c8821 */ 	addu	$s1,$t3,$t4
/*  f0e8d78:	0fc5b9f1 */ 	jal	langGet
/*  f0e8d7c:	96240000 */ 	lhu	$a0,0x0($s1)
/*  f0e8d80:	3c0f8008 */ 	lui	$t7,%hi(var8007fb04)
/*  f0e8d84:	8deffb04 */ 	lw	$t7,%lo(var8007fb04)($t7)
/*  f0e8d88:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f0e8d8c:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f0e8d90:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e8d94:	27a500bc */ 	addiu	$a1,$sp,0xbc
/*  f0e8d98:	00403025 */ 	or	$a2,$v0,$zero
/*  f0e8d9c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e8da0:	0fc55cbe */ 	jal	func0f1572f8
/*  f0e8da4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e8da8:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f0e8dac:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f0e8db0:	27ab00ae */ 	addiu	$t3,$sp,0xae
/*  f0e8db4:	020a6823 */ 	subu	$t5,$s0,$t2
/*  f0e8db8:	05a10003 */ 	bgez	$t5,.L0f0e8dc8
/*  f0e8dbc:	000dc043 */ 	sra	$t8,$t5,0x1
/*  f0e8dc0:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f0e8dc4:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0e8dc8:
/*  f0e8dc8:	030ec821 */ 	addu	$t9,$t8,$t6
/*  f0e8dcc:	162b0035 */ 	bne	$s1,$t3,.L0f0e8ea4
/*  f0e8dd0:	afb900ec */ 	sw	$t9,0xec($sp)
/*  f0e8dd4:	0fc3a157 */ 	jal	func0f0e855c
/*  f0e8dd8:	8fa400e4 */ 	lw	$a0,0xe4($sp)
/*  f0e8ddc:	10400031 */ 	beqz	$v0,.L0f0e8ea4
/*  f0e8de0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8de4:	8e900010 */ 	lw	$s0,0x10($s4)
/*  f0e8de8:	c6060040 */ 	lwc1	$f6,0x40($s0)
/*  f0e8dec:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0e8df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e8df4:	45020008 */ 	bc1fl	.L0f0e8e18
/*  f0e8df8:	920d003d */ 	lbu	$t5,0x3d($s0)
/*  f0e8dfc:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0e8e00:	01950019 */ 	multu	$t4,$s5
/*  f0e8e04:	00007812 */ 	mflo	$t7
/*  f0e8e08:	03cf5021 */ 	addu	$t2,$s8,$t7
/*  f0e8e0c:	1000000f */ 	beqz	$zero,.L0f0e8e4c
/*  f0e8e10:	8d52001c */ 	lw	$s2,0x1c($t2)
/*  f0e8e14:	920d003d */ 	lbu	$t5,0x3d($s0)
.L0f0e8e18:
/*  f0e8e18:	9219003c */ 	lbu	$t9,0x3c($s0)
/*  f0e8e1c:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0e8e20:	01b50019 */ 	multu	$t5,$s5
/*  f0e8e24:	0000c012 */ 	mflo	$t8
/*  f0e8e28:	03d87021 */ 	addu	$t6,$s8,$t8
/*  f0e8e2c:	8dc4001c */ 	lw	$a0,0x1c($t6)
/*  f0e8e30:	03350019 */ 	multu	$t9,$s5
/*  f0e8e34:	00005812 */ 	mflo	$t3
/*  f0e8e38:	03cb6021 */ 	addu	$t4,$s8,$t3
/*  f0e8e3c:	0fc01a40 */ 	jal	func0f006900
/*  f0e8e40:	8d85001c */ 	lw	$a1,0x1c($t4)
/*  f0e8e44:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e8e48:	8e900010 */ 	lw	$s0,0x10($s4)
.L0f0e8e4c:
/*  f0e8e4c:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0e8e50:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e8e54:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e8e58:	51e00009 */ 	beqzl	$t7,.L0f0e8e80
/*  f0e8e5c:	9218003c */ 	lbu	$t8,0x3c($s0)
/*  f0e8e60:	0fc01a40 */ 	jal	func0f006900
/*  f0e8e64:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e8e68:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e8e6c:	00415024 */ 	and	$t2,$v0,$at
/*  f0e8e70:	324d00ff */ 	andi	$t5,$s2,0xff
/*  f0e8e74:	014d9025 */ 	or	$s2,$t2,$t5
/*  f0e8e78:	8e900010 */ 	lw	$s0,0x10($s4)
/*  f0e8e7c:	9218003c */ 	lbu	$t8,0x3c($s0)
.L0f0e8e80:
/*  f0e8e80:	3c047f1b */ 	lui	$a0,%hi(var7f1b229c)
/*  f0e8e84:	3c057f1b */ 	lui	$a1,%hi(var7f1b2134)
/*  f0e8e88:	03150019 */ 	multu	$t8,$s5
/*  f0e8e8c:	00001012 */ 	mflo	$v0
/*  f0e8e90:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e8e94:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e8e98:	8ca52134 */ 	lw	$a1,%lo(var7f1b2134)($a1)
/*  f0e8e9c:	0fc54f8e */ 	jal	func0f153e38
/*  f0e8ea0:	8c84229c */ 	lw	$a0,%lo(var7f1b229c)($a0)
.L0f0e8ea4:
/*  f0e8ea4:	0fc5b9f1 */ 	jal	langGet
/*  f0e8ea8:	96240000 */ 	lhu	$a0,0x0($s1)
/*  f0e8eac:	3c0e8008 */ 	lui	$t6,%hi(var8007fb08)
/*  f0e8eb0:	3c198008 */ 	lui	$t9,%hi(var8007fb04)
/*  f0e8eb4:	8f39fb04 */ 	lw	$t9,%lo(var8007fb04)($t9)
/*  f0e8eb8:	8dcefb08 */ 	lw	$t6,%lo(var8007fb08)($t6)
/*  f0e8ebc:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0e8ec0:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e8ec4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e8ec8:	868b0004 */ 	lh	$t3,0x4($s4)
/*  f0e8ecc:	8fa400f8 */ 	lw	$a0,0xf8($sp)
/*  f0e8ed0:	27a500ec */ 	addiu	$a1,$sp,0xec
/*  f0e8ed4:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0e8ed8:	868c0006 */ 	lh	$t4,0x6($s4)
/*  f0e8edc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e8ee0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e8ee4:	27a600e8 */ 	addiu	$a2,$sp,0xe8
/*  f0e8ee8:	00403825 */ 	or	$a3,$v0,$zero
/*  f0e8eec:	0fc5580f */ 	jal	func0f15603c
/*  f0e8ef0:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0e8ef4:	27af00ae */ 	addiu	$t7,$sp,0xae
/*  f0e8ef8:	162f004a */ 	bne	$s1,$t7,.L0f0e9024
/*  f0e8efc:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0e8f00:	0fc3a157 */ 	jal	func0f0e855c
/*  f0e8f04:	8fa400e4 */ 	lw	$a0,0xe4($sp)
/*  f0e8f08:	50400047 */ 	beqzl	$v0,.L0f0e9028
/*  f0e8f0c:	8fab0088 */ 	lw	$t3,0x88($sp)
/*  f0e8f10:	8e8a0010 */ 	lw	$t2,0x10($s4)
/*  f0e8f14:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0e8f18:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0e8f1c:	914d003c */ 	lbu	$t5,0x3c($t2)
/*  f0e8f20:	01b50019 */ 	multu	$t5,$s5
/*  f0e8f24:	00001012 */ 	mflo	$v0
/*  f0e8f28:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e8f2c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e8f30:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0e8f34:	0fc54f8e */ 	jal	func0f153e38
/*  f0e8f38:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
/*  f0e8f3c:	1000003a */ 	beqz	$zero,.L0f0e9028
/*  f0e8f40:	8fab0088 */ 	lw	$t3,0x88($sp)
.L0f0e8f44:
/*  f0e8f44:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f0e8f48:	03177021 */ 	addu	$t6,$t8,$s7
/*  f0e8f4c:	3c198007 */ 	lui	$t9,%hi(var800711ac)
/*  f0e8f50:	032ec821 */ 	addu	$t9,$t9,$t6
/*  f0e8f54:	933911ac */ 	lbu	$t9,%lo(var800711ac)($t9)
/*  f0e8f58:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0e8f5c:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e8f60:	a3b900f0 */ 	sb	$t9,0xf0($sp)
/*  f0e8f64:	916c000d */ 	lbu	$t4,0xd($t3)
/*  f0e8f68:	27a500bc */ 	addiu	$a1,$sp,0xbc
/*  f0e8f6c:	27a600f0 */ 	addiu	$a2,$sp,0xf0
/*  f0e8f70:	000c5640 */ 	sll	$t2,$t4,0x19
/*  f0e8f74:	05400008 */ 	bltz	$t2,.L0f0e8f98
/*  f0e8f78:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0e8f7c:	332200ff */ 	andi	$v0,$t9,0xff
/*  f0e8f80:	28410041 */ 	slti	$at,$v0,0x41
/*  f0e8f84:	14200004 */ 	bnez	$at,.L0f0e8f98
/*  f0e8f88:	2841005b */ 	slti	$at,$v0,0x5b
/*  f0e8f8c:	10200002 */ 	beqz	$at,.L0f0e8f98
/*  f0e8f90:	244d0020 */ 	addiu	$t5,$v0,0x20
/*  f0e8f94:	a3ad00f0 */ 	sb	$t5,0xf0($sp)
.L0f0e8f98:
/*  f0e8f98:	3c188008 */ 	lui	$t8,%hi(var8007fb0c)
/*  f0e8f9c:	8f18fb0c */ 	lw	$t8,%lo(var8007fb0c)($t8)
/*  f0e8fa0:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0e8fa4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e8fa8:	0fc55cbe */ 	jal	func0f1572f8
/*  f0e8fac:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e8fb0:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f0e8fb4:	2419000c */ 	addiu	$t9,$zero,0xc
/*  f0e8fb8:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f0e8fbc:	3c0d8008 */ 	lui	$t5,%hi(var8007fb10)
/*  f0e8fc0:	3c188008 */ 	lui	$t8,%hi(var8007fb0c)
/*  f0e8fc4:	032e5823 */ 	subu	$t3,$t9,$t6
/*  f0e8fc8:	8f18fb0c */ 	lw	$t8,%lo(var8007fb0c)($t8)
/*  f0e8fcc:	8dadfb10 */ 	lw	$t5,%lo(var8007fb10)($t5)
/*  f0e8fd0:	05610003 */ 	bgez	$t3,.L0f0e8fe0
/*  f0e8fd4:	000b6043 */ 	sra	$t4,$t3,0x1
/*  f0e8fd8:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0e8fdc:	00016043 */ 	sra	$t4,$at,0x1
.L0f0e8fe0:
/*  f0e8fe0:	018f5021 */ 	addu	$t2,$t4,$t7
/*  f0e8fe4:	afaa00ec */ 	sw	$t2,0xec($sp)
/*  f0e8fe8:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0e8fec:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e8ff0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e8ff4:	86990004 */ 	lh	$t9,0x4($s4)
/*  f0e8ff8:	8fa400f8 */ 	lw	$a0,0xf8($sp)
/*  f0e8ffc:	27a500ec */ 	addiu	$a1,$sp,0xec
/*  f0e9000:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e9004:	868e0006 */ 	lh	$t6,0x6($s4)
/*  f0e9008:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e900c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9010:	27a600e8 */ 	addiu	$a2,$sp,0xe8
/*  f0e9014:	27a700f0 */ 	addiu	$a3,$sp,0xf0
/*  f0e9018:	0fc5580f */ 	jal	func0f15603c
/*  f0e901c:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f0e9020:	afa200f8 */ 	sw	$v0,0xf8($sp)
.L0f0e9024:
/*  f0e9024:	8fab0088 */ 	lw	$t3,0x88($sp)
.L0f0e9028:
/*  f0e9028:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f0e902c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0e9030:	256c000b */ 	addiu	$t4,$t3,0xb
/*  f0e9034:	16c1fea3 */ 	bne	$s6,$at,.L0f0e8ac4
/*  f0e9038:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0e903c:	8faf0084 */ 	lw	$t7,0x84($sp)
/*  f0e9040:	26f70001 */ 	addiu	$s7,$s7,0x1
/*  f0e9044:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0e9048:	25ea000c */ 	addiu	$t2,$t7,0xc
/*  f0e904c:	16e1fe9b */ 	bne	$s7,$at,.L0f0e8abc
/*  f0e9050:	afaa0084 */ 	sw	$t2,0x84($sp)
/*  f0e9054:	0fc54de0 */ 	jal	func0f153780
/*  f0e9058:	8fa400f8 */ 	lw	$a0,0xf8($sp)
/*  f0e905c:	8fad00e4 */ 	lw	$t5,0xe4($sp)
/*  f0e9060:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0e9064:	86980000 */ 	lh	$t8,0x0($s4)
/*  f0e9068:	81a3000c */ 	lb	$v1,0xc($t5)
/*  f0e906c:	81a6000b */ 	lb	$a2,0xb($t5)
/*  f0e9070:	868e0002 */ 	lh	$t6,0x2($s4)
/*  f0e9074:	00035880 */ 	sll	$t3,$v1,0x2
/*  f0e9078:	01635823 */ 	subu	$t3,$t3,$v1
/*  f0e907c:	0006c880 */ 	sll	$t9,$a2,0x2
/*  f0e9080:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0e9084:	0326c823 */ 	subu	$t9,$t9,$a2
/*  f0e9088:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0e908c:	01635823 */ 	subu	$t3,$t3,$v1
/*  f0e9090:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0e9094:	03192021 */ 	addu	$a0,$t8,$t9
/*  f0e9098:	01cb2821 */ 	addu	$a1,$t6,$t3
/*  f0e909c:	24920004 */ 	addiu	$s2,$a0,0x4
/*  f0e90a0:	24900010 */ 	addiu	$s0,$a0,0x10
/*  f0e90a4:	24b3000d */ 	addiu	$s3,$a1,0xd
/*  f0e90a8:	14610010 */ 	bne	$v1,$at,.L0f0e90ec
/*  f0e90ac:	24b50018 */ 	addiu	$s5,$a1,0x18
/*  f0e90b0:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0e90b4:	54c10003 */ 	bnel	$a2,$at,.L0f0e90c4
/*  f0e90b8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0e90bc:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0e90c0:	24010005 */ 	addiu	$at,$zero,0x5
.L0f0e90c4:
/*  f0e90c4:	54c10003 */ 	bnel	$a2,$at,.L0f0e90d4
/*  f0e90c8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e90cc:	26100018 */ 	addiu	$s0,$s0,0x18
/*  f0e90d0:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0e90d4:
/*  f0e90d4:	14c10002 */ 	bne	$a2,$at,.L0f0e90e0
/*  f0e90d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e90dc:	26100018 */ 	addiu	$s0,$s0,0x18
.L0f0e90e0:
/*  f0e90e0:	54c00003 */ 	bnezl	$a2,.L0f0e90f0
/*  f0e90e4:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f0e90e8:	2610000c */ 	addiu	$s0,$s0,0xc
.L0f0e90ec:
/*  f0e90ec:	266c0001 */ 	addiu	$t4,$s3,0x1
.L0f0e90f0:
/*  f0e90f0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0e90f4:	240affff */ 	addiu	$t2,$zero,-1
/*  f0e90f8:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0e90fc:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e9100:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e9104:	8fa400f8 */ 	lw	$a0,0xf8($sp)
/*  f0e9108:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e910c:	02603025 */ 	or	$a2,$s3,$zero
/*  f0e9110:	0fc389bb */ 	jal	func0f0e26ec
/*  f0e9114:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9118:	26b10001 */ 	addiu	$s1,$s5,0x1
/*  f0e911c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0e9120:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0e9124:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0e9128:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e912c:	afb10010 */ 	sw	$s1,0x10($sp)
/*  f0e9130:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9134:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e9138:	02603025 */ 	or	$a2,$s3,$zero
/*  f0e913c:	0fc389bb */ 	jal	func0f0e26ec
/*  f0e9140:	26070001 */ 	addiu	$a3,$s0,0x1
/*  f0e9144:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0e9148:	240effff */ 	addiu	$t6,$zero,-1
/*  f0e914c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0e9150:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e9154:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9158:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e915c:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e9160:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9164:	0fc389bb */ 	jal	func0f0e26ec
/*  f0e9168:	afb10010 */ 	sw	$s1,0x10($sp)
/*  f0e916c:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0e9170:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0e9174:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0e9178:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e917c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9180:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e9184:	02603025 */ 	or	$a2,$s3,$zero
/*  f0e9188:	26470001 */ 	addiu	$a3,$s2,0x1
/*  f0e918c:	0fc389bb */ 	jal	func0f0e26ec
/*  f0e9190:	afb10010 */ 	sw	$s1,0x10($sp)
/*  f0e9194:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f0e9198:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f0e919c:	d7b60040 */ 	ldc1	$f22,0x40($sp)
/*  f0e91a0:	d7b80048 */ 	ldc1	$f24,0x48($sp)
/*  f0e91a4:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f0e91a8:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f0e91ac:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f0e91b0:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f0e91b4:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f0e91b8:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f0e91bc:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f0e91c0:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f0e91c4:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f0e91c8:	03e00008 */ 	jr	$ra
/*  f0e91cc:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
);

GLOBAL_ASM(
glabel func0f0e91d0
/*  f0e91d0:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f0e91d4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0e91d8:	30ce0002 */ 	andi	$t6,$a2,0x2
/*  f0e91dc:	00e08025 */ 	or	$s0,$a3,$zero
/*  f0e91e0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0e91e4:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f0e91e8:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f0e91ec:	00e04025 */ 	or	$t0,$a3,$zero
/*  f0e91f0:	afa00060 */ 	sw	$zero,0x60($sp)
/*  f0e91f4:	11c00128 */ 	beqz	$t6,.L0f0e9698
/*  f0e91f8:	afae0034 */ 	sw	$t6,0x34($sp)
/*  f0e91fc:	8fac007c */ 	lw	$t4,0x7c($sp)
/*  f0e9200:	80e2000b */ 	lb	$v0,0xb($a3)
/*  f0e9204:	80e3000c */ 	lb	$v1,0xc($a3)
/*  f0e9208:	818d0000 */ 	lb	$t5,0x0($t4)
/*  f0e920c:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0e9210:	00033400 */ 	sll	$a2,$v1,0x10
/*  f0e9214:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f0e9218:	0006cc03 */ 	sra	$t9,$a2,0x10
/*  f0e921c:	03002825 */ 	or	$a1,$t8,$zero
/*  f0e9220:	11a00020 */ 	beqz	$t5,.L0f0e92a4
/*  f0e9224:	03203025 */ 	or	$a2,$t9,$zero
/*  f0e9228:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f0e922c:	240a0005 */ 	addiu	$t2,$zero,0x5
/*  f0e9230:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f0e9234:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f0e9238:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0e923c:	8fae007c */ 	lw	$t6,0x7c($sp)
.L0f0e9240:
/*  f0e9240:	81cf0000 */ 	lb	$t7,0x0($t6)
/*  f0e9244:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0e9248:	a218000b */ 	sb	$t8,0xb($s0)
/*  f0e924c:	8202000b */ 	lb	$v0,0xb($s0)
/*  f0e9250:	04430004 */ 	bgezl	$v0,.L0f0e9264
/*  f0e9254:	2841000a */ 	slti	$at,$v0,0xa
/*  f0e9258:	a204000b */ 	sb	$a0,0xb($s0)
/*  f0e925c:	8202000b */ 	lb	$v0,0xb($s0)
/*  f0e9260:	2841000a */ 	slti	$at,$v0,0xa
.L0f0e9264:
/*  f0e9264:	54200003 */ 	bnezl	$at,.L0f0e9274
/*  f0e9268:	8203000c */ 	lb	$v1,0xc($s0)
/*  f0e926c:	a200000b */ 	sb	$zero,0xb($s0)
/*  f0e9270:	8203000c */ 	lb	$v1,0xc($s0)
.L0f0e9274:
/*  f0e9274:	54e3000c */ 	bnel	$a3,$v1,.L0f0e92a8
/*  f0e9278:	8fac007c */ 	lw	$t4,0x7c($sp)
/*  f0e927c:	8202000b */ 	lb	$v0,0xb($s0)
/*  f0e9280:	50400009 */ 	beqzl	$v0,.L0f0e92a8
/*  f0e9284:	8fac007c */ 	lw	$t4,0x7c($sp)
/*  f0e9288:	51220007 */ 	beql	$t1,$v0,.L0f0e92a8
/*  f0e928c:	8fac007c */ 	lw	$t4,0x7c($sp)
/*  f0e9290:	51420005 */ 	beql	$t2,$v0,.L0f0e92a8
/*  f0e9294:	8fac007c */ 	lw	$t4,0x7c($sp)
/*  f0e9298:	8119000b */ 	lb	$t9,0xb($t0)
/*  f0e929c:	5579ffe8 */ 	bnel	$t3,$t9,.L0f0e9240
/*  f0e92a0:	8fae007c */ 	lw	$t6,0x7c($sp)
.L0f0e92a4:
/*  f0e92a4:	8fac007c */ 	lw	$t4,0x7c($sp)
.L0f0e92a8:
/*  f0e92a8:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0e92ac:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f0e92b0:	81820001 */ 	lb	$v0,0x1($t4)
/*  f0e92b4:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f0e92b8:	240a0005 */ 	addiu	$t2,$zero,0x5
/*  f0e92bc:	10400025 */ 	beqz	$v0,.L0f0e9354
/*  f0e92c0:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f0e92c4:	00626821 */ 	addu	$t5,$v1,$v0
/*  f0e92c8:	a20d000c */ 	sb	$t5,0xc($s0)
/*  f0e92cc:	8203000c */ 	lb	$v1,0xc($s0)
/*  f0e92d0:	04630004 */ 	bgezl	$v1,.L0f0e92e4
/*  f0e92d4:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e92d8:	a207000c */ 	sb	$a3,0xc($s0)
/*  f0e92dc:	8203000c */ 	lb	$v1,0xc($s0)
/*  f0e92e0:	28610005 */ 	slti	$at,$v1,0x5
.L0f0e92e4:
/*  f0e92e4:	14200003 */ 	bnez	$at,.L0f0e92f4
/*  f0e92e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e92ec:	a200000c */ 	sb	$zero,0xc($s0)
/*  f0e92f0:	8203000c */ 	lb	$v1,0xc($s0)
.L0f0e92f4:
/*  f0e92f4:	14e30017 */ 	bne	$a3,$v1,.L0f0e9354
/*  f0e92f8:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0e92fc:	8202000b */ 	lb	$v0,0xb($s0)
/*  f0e9300:	14820003 */ 	bne	$a0,$v0,.L0f0e9310
/*  f0e9304:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9308:	a20b000b */ 	sb	$t3,0xb($s0)
/*  f0e930c:	8202000b */ 	lb	$v0,0xb($s0)
.L0f0e9310:
/*  f0e9310:	10410003 */ 	beq	$v0,$at,.L0f0e9320
/*  f0e9314:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0e9318:	54410004 */ 	bnel	$v0,$at,.L0f0e932c
/*  f0e931c:	24010003 */ 	addiu	$at,$zero,0x3
.L0f0e9320:
/*  f0e9320:	a20a000b */ 	sb	$t2,0xb($s0)
/*  f0e9324:	8202000b */ 	lb	$v0,0xb($s0)
/*  f0e9328:	24010003 */ 	addiu	$at,$zero,0x3
.L0f0e932c:
/*  f0e932c:	50410004 */ 	beql	$v0,$at,.L0f0e9340
/*  f0e9330:	a209000b */ 	sb	$t1,0xb($s0)
/*  f0e9334:	54e20004 */ 	bnel	$a3,$v0,.L0f0e9348
/*  f0e9338:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e933c:	a209000b */ 	sb	$t1,0xb($s0)
.L0f0e9340:
/*  f0e9340:	8202000b */ 	lb	$v0,0xb($s0)
/*  f0e9344:	24010001 */ 	addiu	$at,$zero,0x1
.L0f0e9348:
/*  f0e9348:	54410003 */ 	bnel	$v0,$at,.L0f0e9358
/*  f0e934c:	820e000b */ 	lb	$t6,0xb($s0)
/*  f0e9350:	a200000b */ 	sb	$zero,0xb($s0)
.L0f0e9354:
/*  f0e9354:	820e000b */ 	lb	$t6,0xb($s0)
.L0f0e9358:
/*  f0e9358:	14ae0004 */ 	bne	$a1,$t6,.L0f0e936c
/*  f0e935c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9360:	820f000c */ 	lb	$t7,0xc($s0)
/*  f0e9364:	50cf0008 */ 	beql	$a2,$t7,.L0f0e9388
/*  f0e9368:	8fb8007c */ 	lw	$t8,0x7c($sp)
.L0f0e936c:
/*  f0e936c:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0e9370:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f0e9374:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f0e9378:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f0e937c:	240a0005 */ 	addiu	$t2,$zero,0x5
/*  f0e9380:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f0e9384:	8fb8007c */ 	lw	$t8,0x7c($sp)
.L0f0e9388:
/*  f0e9388:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0e938c:	93190007 */ 	lbu	$t9,0x7($t8)
/*  f0e9390:	53200003 */ 	beqzl	$t9,.L0f0e93a0
/*  f0e9394:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f0e9398:	afac0060 */ 	sw	$t4,0x60($sp)
/*  f0e939c:	8fad007c */ 	lw	$t5,0x7c($sp)
.L0f0e93a0:
/*  f0e93a0:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0e93a4:	81ae000a */ 	lb	$t6,0xa($t5)
/*  f0e93a8:	51c00023 */ 	beqzl	$t6,.L0f0e9438
/*  f0e93ac:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0e93b0:	8df80010 */ 	lw	$t8,0x10($t7)
/*  f0e93b4:	5300001e */ 	beqzl	$t8,.L0f0e9430
/*  f0e93b8:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f0e93bc:	0fc3a157 */ 	jal	func0f0e855c
/*  f0e93c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e93c4:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f0e93c8:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f0e93cc:	240a0005 */ 	addiu	$t2,$zero,0x5
/*  f0e93d0:	14400016 */ 	bnez	$v0,.L0f0e942c
/*  f0e93d4:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f0e93d8:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0e93dc:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e93e0:	8fa50078 */ 	lw	$a1,0x78($sp)
/*  f0e93e4:	afb00064 */ 	sw	$s0,0x64($sp)
/*  f0e93e8:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f0e93ec:	8cb90010 */ 	lw	$t9,0x10($a1)
/*  f0e93f0:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0e93f4:	0320f809 */ 	jalr	$t9
/*  f0e93f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e93fc:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0e9400:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9404:	8fa50078 */ 	lw	$a1,0x78($sp)
/*  f0e9408:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0e940c:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0e9410:	8cb90010 */ 	lw	$t9,0x10($a1)
/*  f0e9414:	0320f809 */ 	jalr	$t9
/*  f0e9418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e941c:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f0e9420:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f0e9424:	240a0005 */ 	addiu	$t2,$zero,0x5
/*  f0e9428:	240b0008 */ 	addiu	$t3,$zero,0x8
.L0f0e942c:
/*  f0e942c:	8fad007c */ 	lw	$t5,0x7c($sp)
.L0f0e9430:
/*  f0e9430:	a1a0000a */ 	sb	$zero,0xa($t5)
/*  f0e9434:	8fae007c */ 	lw	$t6,0x7c($sp)
.L0f0e9438:
/*  f0e9438:	91cf0002 */ 	lbu	$t7,0x2($t6)
/*  f0e943c:	51e00082 */ 	beqzl	$t7,.L0f0e9648
/*  f0e9440:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0e9444:	8218000c */ 	lb	$t8,0xc($s0)
/*  f0e9448:	54f80046 */ 	bnel	$a3,$t8,.L0f0e9564
/*  f0e944c:	920f0009 */ 	lbu	$t7,0x9($s0)
/*  f0e9450:	8202000b */ 	lb	$v0,0xb($s0)
/*  f0e9454:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0e9458:	14400002 */ 	bnez	$v0,.L0f0e9464
/*  f0e945c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9460:	afac0060 */ 	sw	$t4,0x60($sp)
.L0f0e9464:
/*  f0e9464:	1522000a */ 	bne	$t1,$v0,.L0f0e9490
/*  f0e9468:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e946c:	9203000d */ 	lbu	$v1,0xd($s0)
/*  f0e9470:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0e9474:	8202000b */ 	lb	$v0,0xb($s0)
/*  f0e9478:	0003c9c2 */ 	srl	$t9,$v1,0x7
/*  f0e947c:	01b97823 */ 	subu	$t7,$t5,$t9
/*  f0e9480:	000f61c0 */ 	sll	$t4,$t7,0x7
/*  f0e9484:	306dff7f */ 	andi	$t5,$v1,0xff7f
/*  f0e9488:	018dc825 */ 	or	$t9,$t4,$t5
/*  f0e948c:	a219000d */ 	sb	$t9,0xd($s0)
.L0f0e9490:
/*  f0e9490:	15620012 */ 	bne	$t3,$v0,.L0f0e94dc
/*  f0e9494:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f0e9498:	8dcf0010 */ 	lw	$t7,0x10($t6)
/*  f0e949c:	51e00010 */ 	beqzl	$t7,.L0f0e94e0
/*  f0e94a0:	8202000b */ 	lb	$v0,0xb($s0)
/*  f0e94a4:	0fc3a157 */ 	jal	func0f0e855c
/*  f0e94a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e94ac:	240a0005 */ 	addiu	$t2,$zero,0x5
/*  f0e94b0:	1440000a */ 	bnez	$v0,.L0f0e94dc
/*  f0e94b4:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f0e94b8:	8fa50078 */ 	lw	$a1,0x78($sp)
/*  f0e94bc:	afb00064 */ 	sw	$s0,0x64($sp)
/*  f0e94c0:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f0e94c4:	8cb90010 */ 	lw	$t9,0x10($a1)
/*  f0e94c8:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0e94cc:	0320f809 */ 	jalr	$t9
/*  f0e94d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e94d4:	240a0005 */ 	addiu	$t2,$zero,0x5
/*  f0e94d8:	240b0008 */ 	addiu	$t3,$zero,0x8
.L0f0e94dc:
/*  f0e94dc:	8202000b */ 	lb	$v0,0xb($s0)
.L0f0e94e0:
/*  f0e94e0:	01621826 */ 	xor	$v1,$t3,$v0
/*  f0e94e4:	2c630001 */ 	sltiu	$v1,$v1,0x1
/*  f0e94e8:	14600003 */ 	bnez	$v1,.L0f0e94f8
/*  f0e94ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e94f0:	55420055 */ 	bnel	$t2,$v0,.L0f0e9648
/*  f0e94f4:	8fae0060 */ 	lw	$t6,0x60($sp)
.L0f0e94f8:
/*  f0e94f8:	11420005 */ 	beq	$t2,$v0,.L0f0e9510
/*  f0e94fc:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f0e9500:	0fc3a157 */ 	jal	func0f0e855c
/*  f0e9504:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e9508:	5440004f */ 	bnezl	$v0,.L0f0e9648
/*  f0e950c:	8fae0060 */ 	lw	$t6,0x60($sp)
.L0f0e9510:
/*  f0e9510:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0e9514:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9518:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f0e951c:	8fa50078 */ 	lw	$a1,0x78($sp)
/*  f0e9520:	1180000a */ 	beqz	$t4,.L0f0e954c
/*  f0e9524:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9528:	8cb90010 */ 	lw	$t9,0x10($a1)
/*  f0e952c:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0e9530:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0e9534:	0320f809 */ 	jalr	$t9
/*  f0e9538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e953c:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0e9540:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e9544:	10000004 */ 	beqz	$zero,.L0f0e9558
/*  f0e9548:	8fae007c */ 	lw	$t6,0x7c($sp)
.L0f0e954c:
/*  f0e954c:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0e9550:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f0e9554:	8fae007c */ 	lw	$t6,0x7c($sp)
.L0f0e9558:
/*  f0e9558:	1000003a */ 	beqz	$zero,.L0f0e9644
/*  f0e955c:	a1c00002 */ 	sb	$zero,0x2($t6)
/*  f0e9560:	920f0009 */ 	lbu	$t7,0x9($s0)
.L0f0e9564:
/*  f0e9564:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e9568:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e956c:	15e00035 */ 	bnez	$t7,.L0f0e9644
/*  f0e9570:	3c068007 */ 	lui	$a2,%hi(var800711ac)
/*  f0e9574:	24c611ac */ 	addiu	$a2,$a2,%lo(var800711ac)
.L0f0e9578:
/*  f0e9578:	90980000 */ 	lbu	$t8,0x0($a0)
/*  f0e957c:	17000017 */ 	bnez	$t8,.L0f0e95dc
/*  f0e9580:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9584:	820c000c */ 	lb	$t4,0xc($s0)
/*  f0e9588:	820e000b */ 	lb	$t6,0xb($s0)
/*  f0e958c:	9218000d */ 	lbu	$t8,0xd($s0)
/*  f0e9590:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0e9594:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0e9598:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f0e959c:	00cdc821 */ 	addu	$t9,$a2,$t5
/*  f0e95a0:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f0e95a4:	00186e40 */ 	sll	$t5,$t8,0x19
/*  f0e95a8:	91e20000 */ 	lbu	$v0,0x0($t7)
/*  f0e95ac:	05a0000a */ 	bltz	$t5,.L0f0e95d8
/*  f0e95b0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0e95b4:	28410041 */ 	slti	$at,$v0,0x41
/*  f0e95b8:	14200007 */ 	bnez	$at,.L0f0e95d8
/*  f0e95bc:	00401825 */ 	or	$v1,$v0,$zero
/*  f0e95c0:	2861005b */ 	slti	$at,$v1,0x5b
/*  f0e95c4:	50200005 */ 	beqzl	$at,.L0f0e95dc
/*  f0e95c8:	a0820000 */ 	sb	$v0,0x0($a0)
/*  f0e95cc:	24620020 */ 	addiu	$v0,$v1,0x20
/*  f0e95d0:	305900ff */ 	andi	$t9,$v0,0xff
/*  f0e95d4:	03201025 */ 	or	$v0,$t9,$zero
.L0f0e95d8:
/*  f0e95d8:	a0820000 */ 	sb	$v0,0x0($a0)
.L0f0e95dc:
/*  f0e95dc:	10a0ffe6 */ 	beqz	$a1,.L0f0e9578
/*  f0e95e0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0e95e4:	3c0e8008 */ 	lui	$t6,%hi(var8007fb0c)
/*  f0e95e8:	8dcefb0c */ 	lw	$t6,%lo(var8007fb0c)($t6)
/*  f0e95ec:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0e95f0:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0e95f4:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f0e95f8:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0e95fc:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e9600:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e9604:	0fc55cbe */ 	jal	func0f1572f8
/*  f0e9608:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e960c:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0e9610:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0e9614:	8df8000c */ 	lw	$t8,0xc($t7)
/*  f0e9618:	2981003b */ 	slti	$at,$t4,0x3b
/*  f0e961c:	57000005 */ 	bnezl	$t8,.L0f0e9634
/*  f0e9620:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0e9624:	14200002 */ 	bnez	$at,.L0f0e9630
/*  f0e9628:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0e962c:	afad0060 */ 	sw	$t5,0x60($sp)
.L0f0e9630:
/*  f0e9630:	8fb90060 */ 	lw	$t9,0x60($sp)
.L0f0e9634:
/*  f0e9634:	57200004 */ 	bnezl	$t9,.L0f0e9648
/*  f0e9638:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0e963c:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0e9640:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f0e9644:
/*  f0e9644:	8fae0060 */ 	lw	$t6,0x60($sp)
.L0f0e9648:
/*  f0e9648:	51c00014 */ 	beqzl	$t6,.L0f0e969c
/*  f0e964c:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f0e9650:	920f0000 */ 	lbu	$t7,0x0($s0)
/*  f0e9654:	2418000a */ 	addiu	$t8,$zero,0xa
/*  f0e9658:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0e965c:	51e0000f */ 	beqzl	$t7,.L0f0e969c
/*  f0e9660:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f0e9664:	afb8003c */ 	sw	$t8,0x3c($sp)
/*  f0e9668:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0e966c:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f0e9670:	8fac003c */ 	lw	$t4,0x3c($sp)
/*  f0e9674:	8fa30040 */ 	lw	$v1,0x40($sp)
/*  f0e9678:	020c1021 */ 	addu	$v0,$s0,$t4
.L0f0e967c:
/*  f0e967c:	904d0000 */ 	lbu	$t5,0x0($v0)
/*  f0e9680:	11a00003 */ 	beqz	$t5,.L0f0e9690
/*  f0e9684:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9688:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f0e968c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0e9690:
/*  f0e9690:	1060fffa */ 	beqz	$v1,.L0f0e967c
/*  f0e9694:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f0e9698:
/*  f0e9698:	8fb90034 */ 	lw	$t9,0x34($sp)
.L0f0e969c:
/*  f0e969c:	53200025 */ 	beqzl	$t9,.L0f0e9734
/*  f0e96a0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0e96a4:	9203000d */ 	lbu	$v1,0xd($s0)
/*  f0e96a8:	000379c2 */ 	srl	$t7,$v1,0x7
/*  f0e96ac:	000fc180 */ 	sll	$t8,$t7,0x6
/*  f0e96b0:	330c0040 */ 	andi	$t4,$t8,0x40
/*  f0e96b4:	00032640 */ 	sll	$a0,$v1,0x19
/*  f0e96b8:	306dffbf */ 	andi	$t5,$v1,0xffbf
/*  f0e96bc:	000477c2 */ 	srl	$t6,$a0,0x1f
/*  f0e96c0:	018dc825 */ 	or	$t9,$t4,$t5
/*  f0e96c4:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0e96c8:	a219000d */ 	sb	$t9,0xd($s0)
/*  f0e96cc:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0e96d0:	0019c640 */ 	sll	$t8,$t9,0x19
/*  f0e96d4:	001867c2 */ 	srl	$t4,$t8,0x1f
/*  f0e96d8:	91cf0006 */ 	lbu	$t7,0x6($t6)
/*  f0e96dc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0e96e0:	01ac7023 */ 	subu	$t6,$t5,$t4
/*  f0e96e4:	11e00005 */ 	beqz	$t7,.L0f0e96fc
/*  f0e96e8:	332dffbf */ 	andi	$t5,$t9,0xffbf
/*  f0e96ec:	000e7980 */ 	sll	$t7,$t6,0x6
/*  f0e96f0:	31f80040 */ 	andi	$t8,$t7,0x40
/*  f0e96f4:	030d6025 */ 	or	$t4,$t8,$t5
/*  f0e96f8:	a20c000d */ 	sb	$t4,0xd($s0)
.L0f0e96fc:
/*  f0e96fc:	9202000d */ 	lbu	$v0,0xd($s0)
/*  f0e9700:	0002ce40 */ 	sll	$t9,$v0,0x19
/*  f0e9704:	001977c2 */ 	srl	$t6,$t9,0x1f
/*  f0e9708:	508e000a */ 	beql	$a0,$t6,.L0f0e9734
/*  f0e970c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0e9710:	11c00005 */ 	beqz	$t6,.L0f0e9728
/*  f0e9714:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9718:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0e971c:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0e9720:	10000004 */ 	beqz	$zero,.L0f0e9734
/*  f0e9724:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0e9728:
/*  f0e9728:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0e972c:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0e9730:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0e9734:
/*  f0e9734:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0e9738:	27bd0078 */ 	addiu	$sp,$sp,0x78
/*  f0e973c:	03e00008 */ 	jr	$ra
/*  f0e9740:	24020001 */ 	addiu	$v0,$zero,0x1
);

GLOBAL_ASM(
glabel func0f0e9744
/*  f0e9744:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0e9748:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0e974c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0e9750:	00a03825 */ 	or	$a3,$a1,$zero
/*  f0e9754:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f0e9758:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e975c:	00a01825 */ 	or	$v1,$a1,$zero
.L0f0e9760:
/*  f0e9760:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0e9764:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f0e9768:	1444fffd */ 	bne	$v0,$a0,.L0f0e9760
/*  f0e976c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e9770:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f0e9774:	8dcf0010 */ 	lw	$t7,0x10($t6)
/*  f0e9778:	51e0000a */ 	beqzl	$t7,.L0f0e97a4
/*  f0e977c:	90e8000d */ 	lbu	$t0,0xd($a3)
/*  f0e9780:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f0e9784:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f0e9788:	8dd90010 */ 	lw	$t9,0x10($t6)
/*  f0e978c:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f0e9790:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0e9794:	0320f809 */ 	jalr	$t9
/*  f0e9798:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f0e979c:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f0e97a0:	90e8000d */ 	lbu	$t0,0xd($a3)
.L0f0e97a4:
/*  f0e97a4:	24180004 */ 	addiu	$t8,$zero,0x4
/*  f0e97a8:	a0e0000b */ 	sb	$zero,0xb($a3)
/*  f0e97ac:	310affbf */ 	andi	$t2,$t0,0xffbf
/*  f0e97b0:	a0ea000d */ 	sb	$t2,0xd($a3)
/*  f0e97b4:	314b007f */ 	andi	$t3,$t2,0x7f
/*  f0e97b8:	a0f8000c */ 	sb	$t8,0xc($a3)
/*  f0e97bc:	a0eb000d */ 	sb	$t3,0xd($a3)
/*  f0e97c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0e97c4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0e97c8:	03e00008 */ 	jr	$ra
/*  f0e97cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0e97d0
/*  f0e97d0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0e97d4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0e97d8:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f0e97dc:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f0e97e0:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f0e97e4:	44803000 */ 	mtc1	$zero,$f6
/*  f0e97e8:	c4440040 */ 	lwc1	$f4,0x40($v0)
/*  f0e97ec:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e97f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e97f4:	4502000b */ 	bc1fl	.L0f0e9824
/*  f0e97f8:	9049003d */ 	lbu	$t1,0x3d($v0)
/*  f0e97fc:	904f003c */ 	lbu	$t7,0x3c($v0)
/*  f0e9800:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0e9804:	3c077f1b */ 	lui	$a3,%hi(var7f1b1fb0)
/*  f0e9808:	01e80019 */ 	multu	$t7,$t0
/*  f0e980c:	24e71fb0 */ 	addiu	$a3,$a3,%lo(var7f1b1fb0)
/*  f0e9810:	0000c012 */ 	mflo	$t8
/*  f0e9814:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f0e9818:	10000011 */ 	beqz	$zero,.L0f0e9860
/*  f0e981c:	8f230018 */ 	lw	$v1,0x18($t9)
/*  f0e9820:	9049003d */ 	lbu	$t1,0x3d($v0)
.L0f0e9824:
/*  f0e9824:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0e9828:	904c003c */ 	lbu	$t4,0x3c($v0)
/*  f0e982c:	01280019 */ 	multu	$t1,$t0
/*  f0e9830:	3c077f1b */ 	lui	$a3,%hi(var7f1b1fb0)
/*  f0e9834:	24e71fb0 */ 	addiu	$a3,$a3,%lo(var7f1b1fb0)
/*  f0e9838:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0e983c:	00005012 */ 	mflo	$t2
/*  f0e9840:	00ea5821 */ 	addu	$t3,$a3,$t2
/*  f0e9844:	8d640018 */ 	lw	$a0,0x18($t3)
/*  f0e9848:	01880019 */ 	multu	$t4,$t0
/*  f0e984c:	00006812 */ 	mflo	$t5
/*  f0e9850:	00ed7021 */ 	addu	$t6,$a3,$t5
/*  f0e9854:	0fc01a40 */ 	jal	func0f006900
/*  f0e9858:	8dc50018 */ 	lw	$a1,0x18($t6)
/*  f0e985c:	00401825 */ 	or	$v1,$v0,$zero
.L0f0e9860:
/*  f0e9860:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*  f0e9864:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e9868:	00617824 */ 	and	$t7,$v1,$at
/*  f0e986c:	87220002 */ 	lh	$v0,0x2($t9)
/*  f0e9870:	87250000 */ 	lh	$a1,0x0($t9)
/*  f0e9874:	87290004 */ 	lh	$t1,0x4($t9)
/*  f0e9878:	35f8003f */ 	ori	$t8,$t7,0x3f
/*  f0e987c:	244a0003 */ 	addiu	$t2,$v0,0x3
/*  f0e9880:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e9884:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e9888:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0e988c:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f0e9890:	24460002 */ 	addiu	$a2,$v0,0x2
/*  f0e9894:	0fc38bd7 */ 	jal	func0f0e2f5c
/*  f0e9898:	00a93821 */ 	addu	$a3,$a1,$t1
/*  f0e989c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0e98a0:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0e98a4:	03e00008 */ 	jr	$ra
/*  f0e98a8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0e98ac
/*  f0e98ac:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0e98b0:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e98b4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e98b8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0e98bc:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f0e98c0:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f0e98c4:	afa60138 */ 	sw	$a2,0x138($sp)
/*  f0e98c8:	afa7013c */ 	sw	$a3,0x13c($sp)
/*  f0e98cc:	11c00002 */ 	beqz	$t6,.L0f0e98d8
/*  f0e98d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e98d4:	2402000c */ 	addiu	$v0,$zero,0xc
.L0f0e98d8:
/*  f0e98d8:	3c047f1b */ 	lui	$a0,%hi(var7f1adfa0)
/*  f0e98dc:	3c058007 */ 	lui	$a1,%hi(var800711e8)
/*  f0e98e0:	24a511e8 */ 	addiu	$a1,$a1,%lo(var800711e8)
/*  f0e98e4:	2484dfa0 */ 	addiu	$a0,$a0,%lo(var7f1adfa0)
/*  f0e98e8:	0c0036cc */ 	jal	func0000db30
/*  f0e98ec:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0e98f0:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0e98f4:	3c04800a */ 	lui	$a0,%hi(g_Briefing+0x2)
/*  f0e98f8:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f0e98fc:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0e9900:	0fc5b9f1 */ 	jal	langGet
/*  f0e9904:	9484dfca */ 	lhu	$a0,%lo(g_Briefing+0x2)($a0)
/*  f0e9908:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e990c:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e9910:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0e9914:	afb90124 */ 	sw	$t9,0x124($sp)
/*  f0e9918:	44803000 */ 	mtc1	$zero,$f6
/*  f0e991c:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0e9920:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e9924:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9928:	4502000b */ 	bc1fl	.L0f0e9958
/*  f0e992c:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0e9930:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0e9934:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e9938:	3c0b7f1b */ 	lui	$t3,%hi(var7f1b1fc8)
/*  f0e993c:	01300019 */ 	multu	$t1,$s0
/*  f0e9940:	00005012 */ 	mflo	$t2
/*  f0e9944:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0e9948:	8d6b1fc8 */ 	lw	$t3,%lo(var7f1b1fc8)($t3)
/*  f0e994c:	10000012 */ 	beqz	$zero,.L0f0e9998
/*  f0e9950:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0e9954:	906c003d */ 	lbu	$t4,0x3d($v1)
.L0f0e9958:
/*  f0e9958:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e995c:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e9960:	01900019 */ 	multu	$t4,$s0
/*  f0e9964:	3c0e7f1b */ 	lui	$t6,%hi(var7f1b1fb0)
/*  f0e9968:	25ce1fb0 */ 	addiu	$t6,$t6,%lo(var7f1b1fb0)
/*  f0e996c:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e9970:	00006812 */ 	mflo	$t5
/*  f0e9974:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0e9978:	8de40018 */ 	lw	$a0,0x18($t7)
/*  f0e997c:	03100019 */ 	multu	$t8,$s0
/*  f0e9980:	0000c812 */ 	mflo	$t9
/*  f0e9984:	032e4821 */ 	addu	$t1,$t9,$t6
/*  f0e9988:	0fc01a40 */ 	jal	func0f006900
/*  f0e998c:	8d250018 */ 	lw	$a1,0x18($t1)
/*  f0e9990:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f0e9994:	8fa30134 */ 	lw	$v1,0x134($sp)
.L0f0e9998:
/*  f0e9998:	8c6a000c */ 	lw	$t2,0xc($v1)
/*  f0e999c:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f0e99a0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e99a4:	5140000b */ 	beqzl	$t2,.L0f0e99d4
/*  f0e99a8:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e99ac:	0fc01a40 */ 	jal	func0f006900
/*  f0e99b0:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0e99b4:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0e99b8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e99bc:	00415824 */ 	and	$t3,$v0,$at
/*  f0e99c0:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0e99c4:	016d7825 */ 	or	$t7,$t3,$t5
/*  f0e99c8:	afaf012c */ 	sw	$t7,0x12c($sp)
/*  f0e99cc:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e99d0:	9078003c */ 	lbu	$t8,0x3c($v1)
.L0f0e99d4:
/*  f0e99d4:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0e99d8:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0e99dc:	03100019 */ 	multu	$t8,$s0
/*  f0e99e0:	00001012 */ 	mflo	$v0
/*  f0e99e4:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e99e8:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e99ec:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0e99f0:	0fc54f8e */ 	jal	func0f153e38
/*  f0e99f4:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
/*  f0e99f8:	a3a000d0 */ 	sb	$zero,0xd0($sp)
/*  f0e99fc:	0fc54d8a */ 	jal	func0f153628
/*  f0e9a00:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9a04:	27b000d0 */ 	addiu	$s0,$sp,0xd0
/*  f0e9a08:	3c057f1b */ 	lui	$a1,%hi(var7f1adfa8)
/*  f0e9a0c:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e9a10:	24a5dfa8 */ 	addiu	$a1,$a1,%lo(var7f1adfa8)
/*  f0e9a14:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e9a18:	0c004dad */ 	jal	sprintf
/*  f0e9a1c:	8fa6013c */ 	lw	$a2,0x13c($sp)
/*  f0e9a20:	3c198008 */ 	lui	$t9,%hi(var8007fb0c)
/*  f0e9a24:	8f39fb0c */ 	lw	$t9,%lo(var8007fb0c)($t9)
/*  f0e9a28:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0e9a2c:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0e9a30:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9a34:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9a38:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e9a3c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e9a40:	0fc55cbe */ 	jal	func0f1572f8
/*  f0e9a44:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e9a48:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e9a4c:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f0e9a50:	3c0b8008 */ 	lui	$t3,%hi(var8007fb10)
/*  f0e9a54:	3c0d8008 */ 	lui	$t5,%hi(var8007fb0c)
/*  f0e9a58:	8dadfb0c */ 	lw	$t5,%lo(var8007fb0c)($t5)
/*  f0e9a5c:	8d6bfb10 */ 	lw	$t3,%lo(var8007fb10)($t3)
/*  f0e9a60:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e9a64:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e9a68:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e9a6c:	01c95023 */ 	subu	$t2,$t6,$t1
/*  f0e9a70:	254c0019 */ 	addiu	$t4,$t2,0x19
/*  f0e9a74:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f0e9a78:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9a7c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9a80:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9a84:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9a88:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9a8c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9a90:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e9a94:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9a98:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e9a9c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e9aa0:	0fc5580f */ 	jal	func0f15603c
/*  f0e9aa4:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e9aa8:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e9aac:	8faa0154 */ 	lw	$t2,0x154($sp)
/*  f0e9ab0:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e9ab4:	25c90019 */ 	addiu	$t1,$t6,0x19
/*  f0e9ab8:	1140001f */ 	beqz	$t2,.L0f0e9b38
/*  f0e9abc:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9ac0:	3c0c8008 */ 	lui	$t4,%hi(var8007fb04)
/*  f0e9ac4:	8d8cfb04 */ 	lw	$t4,%lo(var8007fb04)($t4)
/*  f0e9ac8:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f0e9acc:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f0e9ad0:	24040055 */ 	addiu	$a0,$zero,0x55
/*  f0e9ad4:	8fa50120 */ 	lw	$a1,0x120($sp)
/*  f0e9ad8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e9adc:	0fc55d48 */ 	jal	func0f157520
/*  f0e9ae0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e9ae4:	3c0b8008 */ 	lui	$t3,%hi(var8007fb08)
/*  f0e9ae8:	3c0d8008 */ 	lui	$t5,%hi(var8007fb04)
/*  f0e9aec:	8dadfb04 */ 	lw	$t5,%lo(var8007fb04)($t5)
/*  f0e9af0:	8d6bfb08 */ 	lw	$t3,%lo(var8007fb08)($t3)
/*  f0e9af4:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e9af8:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e9afc:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e9b00:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9b04:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9b08:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9b0c:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9b10:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9b14:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9b18:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e9b1c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9b20:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e9b24:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e9b28:	0fc5580f */ 	jal	func0f15603c
/*  f0e9b2c:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e9b30:	1000001a */ 	beqz	$zero,.L0f0e9b9c
/*  f0e9b34:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0e9b38:
/*  f0e9b38:	3c057f1b */ 	lui	$a1,%hi(var7f1adfb0)
/*  f0e9b3c:	24a5dfb0 */ 	addiu	$a1,$a1,%lo(var7f1adfb0)
/*  f0e9b40:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e9b44:	0c004dad */ 	jal	sprintf
/*  f0e9b48:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0e9b4c:	3c0e8008 */ 	lui	$t6,%hi(var8007fb10)
/*  f0e9b50:	3c098008 */ 	lui	$t1,%hi(var8007fb0c)
/*  f0e9b54:	8d29fb0c */ 	lw	$t1,%lo(var8007fb0c)($t1)
/*  f0e9b58:	8dcefb10 */ 	lw	$t6,%lo(var8007fb10)($t6)
/*  f0e9b5c:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f0e9b60:	87ac014a */ 	lh	$t4,0x14a($sp)
/*  f0e9b64:	87ab014e */ 	lh	$t3,0x14e($sp)
/*  f0e9b68:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9b6c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9b70:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9b74:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9b78:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9b7c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9b80:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e9b84:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e9b88:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0e9b8c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e9b90:	0fc5580f */ 	jal	func0f15603c
/*  f0e9b94:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0e9b98:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0e9b9c:
/*  f0e9b9c:	8fad0150 */ 	lw	$t5,0x150($sp)
/*  f0e9ba0:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9ba4:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9ba8:	11a00141 */ 	beqz	$t5,.L0f0ea0b0
/*  f0e9bac:	3c078008 */ 	lui	$a3,0x8008
/*  f0e9bb0:	0fc255a1 */ 	jal	objectiveGetStatus
/*  f0e9bb4:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f0e9bb8:	10400007 */ 	beqz	$v0,.L0f0e9bd8
/*  f0e9bbc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e9bc0:	1041000c */ 	beq	$v0,$at,.L0f0e9bf4
/*  f0e9bc4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e9bc8:	10410011 */ 	beq	$v0,$at,.L0f0e9c10
/*  f0e9bcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9bd0:	10000015 */ 	beqz	$zero,.L0f0e9c28
/*  f0e9bd4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0e9bd8:
/*  f0e9bd8:	0fc5b9f1 */ 	jal	langGet
/*  f0e9bdc:	24045601 */ 	addiu	$a0,$zero,0x5601
/*  f0e9be0:	3c0fffff */ 	lui	$t7,0xffff
/*  f0e9be4:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f0e9be8:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9bec:	1000000e */ 	beqz	$zero,.L0f0e9c28
/*  f0e9bf0:	afaf00c8 */ 	sw	$t7,0xc8($sp)
.L0f0e9bf4:
/*  f0e9bf4:	0fc5b9f1 */ 	jal	langGet
/*  f0e9bf8:	24045600 */ 	addiu	$a0,$zero,0x5600
/*  f0e9bfc:	3c1800ff */ 	lui	$t8,0xff
/*  f0e9c00:	371800ff */ 	ori	$t8,$t8,0xff
/*  f0e9c04:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9c08:	10000007 */ 	beqz	$zero,.L0f0e9c28
/*  f0e9c0c:	afb800c8 */ 	sw	$t8,0xc8($sp)
.L0f0e9c10:
/*  f0e9c10:	0fc5b9f1 */ 	jal	langGet
/*  f0e9c14:	24045602 */ 	addiu	$a0,$zero,0x5602
/*  f0e9c18:	3c19ff40 */ 	lui	$t9,0xff40
/*  f0e9c1c:	373940ff */ 	ori	$t9,$t9,0x40ff
/*  f0e9c20:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9c24:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L0f0e9c28:
/*  f0e9c28:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f0e9c2c:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f0e9c30:	3c0c800a */ 	lui	$t4,%hi(g_MenuStack+0x4f8)
/*  f0e9c34:	8fae0134 */ 	lw	$t6,0x134($sp)
/*  f0e9c38:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0e9c3c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e9c40:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0e9c44:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0e9c48:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0e9c4c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e9c50:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0e9c54:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f0e9c58:	8d8ce4f8 */ 	lw	$t4,%lo(g_MenuStack+0x4f8)($t4)
/*  f0e9c5c:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9c60:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9c64:	11cc0004 */ 	beq	$t6,$t4,.L0f0e9c78
/*  f0e9c68:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f0e9c6c:	3c0b7f1b */ 	lui	$t3,%hi(var7f1b1fc8)
/*  f0e9c70:	8d6b1fc8 */ 	lw	$t3,%lo(var7f1b1fc8)($t3)
/*  f0e9c74:	afab00c8 */ 	sw	$t3,0xc8($sp)
.L0f0e9c78:
/*  f0e9c78:	3c0d8008 */ 	lui	$t5,%hi(var8007fb04)
/*  f0e9c7c:	8dadfb04 */ 	lw	$t5,%lo(var8007fb04)($t5)
/*  f0e9c80:	8fa600cc */ 	lw	$a2,0xcc($sp)
/*  f0e9c84:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f0e9c88:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e9c8c:	0fc55cbe */ 	jal	func0f1572f8
/*  f0e9c90:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e9c94:	3c028007 */ 	lui	$v0,%hi(var800711e8)
/*  f0e9c98:	8c4211e8 */ 	lw	$v0,%lo(var800711e8)($v0)
/*  f0e9c9c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9ca0:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9ca4:	10400002 */ 	beqz	$v0,.L0f0e9cb0
/*  f0e9ca8:	3c0c8008 */ 	lui	$t4,%hi(var8007fb08)
/*  f0e9cac:	afa200c8 */ 	sw	$v0,0xc8($sp)
.L0f0e9cb0:
/*  f0e9cb0:	87a2014a */ 	lh	$v0,0x14a($sp)
/*  f0e9cb4:	87af0142 */ 	lh	$t7,0x142($sp)
/*  f0e9cb8:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9cbc:	87aa0146 */ 	lh	$t2,0x146($sp)
/*  f0e9cc0:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f0e9cc4:	01e28021 */ 	addu	$s0,$t7,$v0
/*  f0e9cc8:	3c0b8008 */ 	lui	$t3,%hi(var8007fb04)
/*  f0e9ccc:	8d6bfb04 */ 	lw	$t3,%lo(var8007fb04)($t3)
/*  f0e9cd0:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e9cd4:	8d8cfb08 */ 	lw	$t4,%lo(var8007fb08)($t4)
/*  f0e9cd8:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f0e9cdc:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e9ce0:	014e1821 */ 	addu	$v1,$t2,$t6
/*  f0e9ce4:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e9ce8:	24630009 */ 	addiu	$v1,$v1,0x9
/*  f0e9cec:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9cf0:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e9cf4:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f0e9cf8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9cfc:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e9d00:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9d04:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9d08:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0e9d0c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e9d10:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e9d14:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e9d18:	0fc5580f */ 	jal	func0f15603c
/*  f0e9d1c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0e9d20:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9d24:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*  f0e9d28:	3c0a8008 */ 	lui	$t2,%hi(var8007fb08)
/*  f0e9d2c:	3c0e8008 */ 	lui	$t6,%hi(var8007fb04)
/*  f0e9d30:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f0e9d34:	8dcefb04 */ 	lw	$t6,%lo(var8007fb04)($t6)
/*  f0e9d38:	8d4afb08 */ 	lw	$t2,%lo(var8007fb08)($t2)
/*  f0e9d3c:	87ad014a */ 	lh	$t5,0x14a($sp)
/*  f0e9d40:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e9d44:	2401ff7f */ 	addiu	$at,$zero,-129
/*  f0e9d48:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e9d4c:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e9d50:	01815824 */ 	and	$t3,$t4,$at
/*  f0e9d54:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9d58:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0e9d5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9d60:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9d64:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9d68:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e9d6c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9d70:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9d74:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e9d78:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e9d7c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e9d80:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e9d84:	0fc5580f */ 	jal	func0f15603c
/*  f0e9d88:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e9d8c:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9d90:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e9d94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9d98:	02183023 */ 	subu	$a2,$s0,$t8
/*  f0e9d9c:	24c6fff3 */ 	addiu	$a2,$a2,-13
/*  f0e9da0:	27290009 */ 	addiu	$t1,$t9,0x9
/*  f0e9da4:	afa90124 */ 	sw	$t1,0x124($sp)
/*  f0e9da8:	0fc54de0 */ 	jal	func0f153780
/*  f0e9dac:	afa60128 */ 	sw	$a2,0x128($sp)
/*  f0e9db0:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9db4:	87ae0146 */ 	lh	$t6,0x146($sp)
/*  f0e9db8:	8fa60128 */ 	lw	$a2,0x128($sp)
/*  f0e9dbc:	00054880 */ 	sll	$t1,$a1,0x2
/*  f0e9dc0:	01254823 */ 	subu	$t1,$t1,$a1
/*  f0e9dc4:	25cb0008 */ 	addiu	$t3,$t6,0x8
/*  f0e9dc8:	8fad0124 */ 	lw	$t5,0x124($sp)
/*  f0e9dcc:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*  f0e9dd0:	afab00ac */ 	sw	$t3,0xac($sp)
/*  f0e9dd4:	24aa0016 */ 	addiu	$t2,$a1,0x16
/*  f0e9dd8:	01251821 */ 	addu	$v1,$t1,$a1
/*  f0e9ddc:	8fab013c */ 	lw	$t3,0x13c($sp)
/*  f0e9de0:	afaa00b4 */ 	sw	$t2,0xb4($sp)
/*  f0e9de4:	24630042 */ 	addiu	$v1,$v1,0x42
/*  f0e9de8:	25ccfffe */ 	addiu	$t4,$t6,-2
/*  f0e9dec:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f0e9df0:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0e9df4:	256dffff */ 	addiu	$t5,$t3,-1
/*  f0e9df8:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f0e9dfc:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0e9e00:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e04:	afa6009c */ 	sw	$a2,0x9c($sp)
/*  f0e9e08:	04610003 */ 	bgez	$v1,.L0f0e9e18
/*  f0e9e0c:	00035083 */ 	sra	$t2,$v1,0x2
/*  f0e9e10:	24610003 */ 	addiu	$at,$v1,0x3
/*  f0e9e14:	00015083 */ 	sra	$t2,$at,0x2
.L0f0e9e18:
/*  f0e9e18:	00ca6023 */ 	subu	$t4,$a2,$t2
/*  f0e9e1c:	258effe8 */ 	addiu	$t6,$t4,-24
/*  f0e9e20:	01cd0019 */ 	multu	$t6,$t5
/*  f0e9e24:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0e9e28:	afaa005c */ 	sw	$t2,0x5c($sp)
/*  f0e9e2c:	00007812 */ 	mflo	$t7
/*  f0e9e30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9e34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e9e38:	01e1001a */ 	div	$zero,$t7,$at
/*  f0e9e3c:	0000c012 */ 	mflo	$t8
/*  f0e9e40:	0158c821 */ 	addu	$t9,$t2,$t8
/*  f0e9e44:	27290013 */ 	addiu	$t1,$t9,0x13
/*  f0e9e48:	0fc38926 */ 	jal	func0f0e2498
/*  f0e9e4c:	afa90098 */ 	sw	$t1,0x98($sp)
/*  f0e9e50:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0e9e54:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e9e58:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e9e5c:	00616024 */ 	and	$t4,$v1,$at
/*  f0e9e60:	3590003f */ 	ori	$s0,$t4,0x3f
/*  f0e9e64:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0e9e68:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e9e6c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9e70:	01801825 */ 	or	$v1,$t4,$zero
/*  f0e9e74:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e9e78:	afac0054 */ 	sw	$t4,0x54($sp)
/*  f0e9e7c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e80:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9e84:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9e88:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0e9e8c:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f0e9e90:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f0e9e94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e98:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e9e9c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0e9ea0:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e9ea4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9ea8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9eac:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9eb0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9eb4:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9eb8:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e9ebc:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0e9ec0:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0e9ec4:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f0e9ec8:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0e9ecc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e9ed0:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0e9ed4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ed8:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9edc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9ee0:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9ee4:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e9ee8:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9eec:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0e9ef0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ef4:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0e9ef8:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0e9efc:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f00:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0e9f04:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f08:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f0c:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9f10:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e9f14:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e9f18:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9f1c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f20:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0e9f24:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9f28:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0e9f2c:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f30:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f34:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f38:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9f3c:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e9f40:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9f44:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0e9f48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f4c:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0e9f50:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0e9f54:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f58:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e9f5c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f60:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f64:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9f68:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e9f6c:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e9f70:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e9f74:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0e9f78:	24c30001 */ 	addiu	$v1,$a2,0x1
/*  f0e9f7c:	24e7000e */ 	addiu	$a3,$a3,0xe
/*  f0e9f80:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e9f84:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9f88:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0e9f8c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f90:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f94:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9f98:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f9c:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e9fa0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9fa4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9fa8:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0e9fac:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9fb0:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0e9fb4:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e9fb8:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e9fbc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9fc0:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9fc4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fc8:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f0e9fcc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9fd0:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9fd4:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e9fd8:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0e9fdc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9fe0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fe4:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9fe8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e9fec:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0e9ff0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ff4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9ff8:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e9ffc:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0ea000:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea004:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea008:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea00c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ea010:	8fa300c8 */ 	lw	$v1,0xc8($sp)
/*  f0ea014:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f0ea018:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea01c:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0ea020:	00614824 */ 	and	$t1,$v1,$at
/*  f0ea024:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0ea028:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea02c:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0ea030:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea034:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea038:	01201825 */ 	or	$v1,$t1,$zero
/*  f0ea03c:	afa9005c */ 	sw	$t1,0x5c($sp)
/*  f0ea040:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea044:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0ea048:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea04c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea050:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ea054:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f0ea058:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea05c:	24e7fffc */ 	addiu	$a3,$a3,-4
/*  f0ea060:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0ea064:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0ea068:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ea06c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea070:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea074:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea078:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ea07c:	8fab005c */ 	lw	$t3,0x5c($sp)
/*  f0ea080:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0ea084:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea088:	356e00cf */ 	ori	$t6,$t3,0xcf
/*  f0ea08c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0ea090:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0ea094:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ea098:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ea09c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea0a0:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea0a4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ea0a8:	10000074 */ 	beqz	$zero,.L0f0ea27c
/*  f0ea0ac:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0ea0b0:
/*  f0ea0b0:	87b80146 */ 	lh	$t8,0x146($sp)
/*  f0ea0b4:	87ad0142 */ 	lh	$t5,0x142($sp)
/*  f0ea0b8:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f0ea0bc:	3c0b8008 */ 	lui	$t3,%hi(var8007fb0c)
/*  f0ea0c0:	8d6bfb0c */ 	lw	$t3,%lo(var8007fb0c)($t3)
/*  f0ea0c4:	2719fffe */ 	addiu	$t9,$t8,-2
/*  f0ea0c8:	27090008 */ 	addiu	$t1,$t8,0x8
/*  f0ea0cc:	25af0016 */ 	addiu	$t7,$t5,0x16
/*  f0ea0d0:	254c0001 */ 	addiu	$t4,$t2,0x1
/*  f0ea0d4:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f0ea0d8:	afb9007c */ 	sw	$t9,0x7c($sp)
/*  f0ea0dc:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0ea0e0:	afac0074 */ 	sw	$t4,0x74($sp)
/*  f0ea0e4:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0ea0e8:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
/*  f0ea0ec:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ea0f0:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ea0f4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ea0f8:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0ea0fc:	8fad00c4 */ 	lw	$t5,0xc4($sp)
/*  f0ea100:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea104:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0ea108:	25f90019 */ 	addiu	$t9,$t7,0x19
/*  f0ea10c:	0fc54de0 */ 	jal	func0f153780
/*  f0ea110:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f0ea114:	0fc38926 */ 	jal	func0f0e2498
/*  f0ea118:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea11c:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0ea120:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ea124:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea128:	00614824 */ 	and	$t1,$v1,$at
/*  f0ea12c:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0ea130:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0ea134:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ea138:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea13c:	01201825 */ 	or	$v1,$t1,$zero
/*  f0ea140:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0ea144:	afa90054 */ 	sw	$t1,0x54($sp)
/*  f0ea148:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea14c:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0ea150:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea154:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0ea158:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0ea15c:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0ea160:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea164:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea168:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0ea16c:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ea170:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea174:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea178:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea17c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ea180:	87ab0142 */ 	lh	$t3,0x142($sp)
/*  f0ea184:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea188:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0ea18c:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0ea190:	01cb7023 */ 	subu	$t6,$t6,$t3
/*  f0ea194:	01cb3821 */ 	addu	$a3,$t6,$t3
/*  f0ea198:	24e70042 */ 	addiu	$a3,$a3,0x42
/*  f0ea19c:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0ea1a0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ea1a4:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f0ea1a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea1ac:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea1b0:	01602825 */ 	or	$a1,$t3,$zero
/*  f0ea1b4:	04e10003 */ 	bgez	$a3,.L0f0ea1c4
/*  f0ea1b8:	00076883 */ 	sra	$t5,$a3,0x2
/*  f0ea1bc:	24e10003 */ 	addiu	$at,$a3,0x3
/*  f0ea1c0:	00016883 */ 	sra	$t5,$at,0x2
.L0f0ea1c4:
/*  f0ea1c4:	25a7ffff */ 	addiu	$a3,$t5,-1
/*  f0ea1c8:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0ea1cc:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea1d0:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0ea1d4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea1d8:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f0ea1dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea1e0:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0ea1e4:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0ea1e8:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea1ec:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0ea1f0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea1f4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea1f8:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea1fc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ea200:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0ea204:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea208:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea20c:	25f90002 */ 	addiu	$t9,$t7,0x2
/*  f0ea210:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea214:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea218:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea21c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea220:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea224:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea228:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea22c:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0ea230:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea234:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0ea238:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0ea23c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea240:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0ea244:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea248:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea24c:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea250:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ea254:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0ea258:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0ea25c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea260:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0ea264:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ea268:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0ea26c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea270:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea274:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea278:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0ea27c:
/*  f0ea27c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ea280:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f0ea284:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ea288:	03e00008 */ 	jr	$ra
/*  f0ea28c:	27bd0130 */ 	addiu	$sp,$sp,0x130
);

GLOBAL_ASM(
glabel func0f0ea290
/*  f0ea290:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f0ea294:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f0ea298:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f0ea29c:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f0ea2a0:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f0ea2a4:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f0ea2a8:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f0ea2ac:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f0ea2b0:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f0ea2b4:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f0ea2b8:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0ea2bc:	84b10002 */ 	lh	$s1,0x2($a1)
/*  f0ea2c0:	3c14800a */ 	lui	$s4,%hi(g_Briefing)
/*  f0ea2c4:	00a09025 */ 	or	$s2,$a1,$zero
/*  f0ea2c8:	0080b025 */ 	or	$s6,$a0,$zero
/*  f0ea2cc:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f0ea2d0:	2694dfc8 */ 	addiu	$s4,$s4,%lo(g_Briefing)
/*  f0ea2d4:	00009825 */ 	or	$s3,$zero,$zero
/*  f0ea2d8:	24170002 */ 	addiu	$s7,$zero,0x2
/*  f0ea2dc:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f0ea2e0:	26310005 */ 	addiu	$s1,$s1,0x5
.L0f0ea2e4:
/*  f0ea2e4:	968e0002 */ 	lhu	$t6,0x2($s4)
/*  f0ea2e8:	51c0002b */ 	beqzl	$t6,.L0f0ea398
/*  f0ea2ec:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0ea2f0:	0fc5b367 */ 	jal	getDifficulty
/*  f0ea2f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea2f8:	9699000e */ 	lhu	$t9,0xe($s4)
/*  f0ea2fc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0ea300:	004fc004 */ 	sllv	$t8,$t7,$v0
/*  f0ea304:	03194024 */ 	and	$t0,$t8,$t9
/*  f0ea308:	51000023 */ 	beqzl	$t0,.L0f0ea398
/*  f0ea30c:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0ea310:	86490000 */ 	lh	$t1,0x0($s2)
/*  f0ea314:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f0ea318:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0ea31c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0ea320:	864a0004 */ 	lh	$t2,0x4($s2)
/*  f0ea324:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0ea328:	02603025 */ 	or	$a2,$s3,$zero
/*  f0ea32c:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0ea330:	864b0006 */ 	lh	$t3,0x6($s2)
/*  f0ea334:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0ea338:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0ea33c:	8e4c0008 */ 	lw	$t4,0x8($s2)
/*  f0ea340:	91900001 */ 	lbu	$s0,0x1($t4)
/*  f0ea344:	03d06826 */ 	xor	$t5,$s8,$s0
/*  f0ea348:	02f07026 */ 	xor	$t6,$s7,$s0
/*  f0ea34c:	2dce0001 */ 	sltiu	$t6,$t6,0x1
/*  f0ea350:	000d682b */ 	sltu	$t5,$zero,$t5
/*  f0ea354:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f0ea358:	0fc3a62b */ 	jal	func0f0e98ac
/*  f0ea35c:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f0ea360:	8e4f0008 */ 	lw	$t7,0x8($s2)
/*  f0ea364:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0ea368:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0ea36c:	91f00001 */ 	lbu	$s0,0x1($t7)
/*  f0ea370:	16000003 */ 	bnez	$s0,.L0f0ea380
/*  f0ea374:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea378:	10000006 */ 	beqz	$zero,.L0f0ea394
/*  f0ea37c:	26310012 */ 	addiu	$s1,$s1,0x12
.L0f0ea380:
/*  f0ea380:	56f00004 */ 	bnel	$s7,$s0,.L0f0ea394
/*  f0ea384:	2631000e */ 	addiu	$s1,$s1,0xe
/*  f0ea388:	10000002 */ 	beqz	$zero,.L0f0ea394
/*  f0ea38c:	2631001e */ 	addiu	$s1,$s1,0x1e
/*  f0ea390:	2631000e */ 	addiu	$s1,$s1,0xe
.L0f0ea394:
/*  f0ea394:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f0ea398:
/*  f0ea398:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0ea39c:	1661ffd1 */ 	bne	$s3,$at,.L0f0ea2e4
/*  f0ea3a0:	26940002 */ 	addiu	$s4,$s4,0x2
/*  f0ea3a4:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f0ea3a8:	02c01025 */ 	or	$v0,$s6,$zero
/*  f0ea3ac:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f0ea3b0:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0ea3b4:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f0ea3b8:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f0ea3bc:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f0ea3c0:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f0ea3c4:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f0ea3c8:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f0ea3cc:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f0ea3d0:	03e00008 */ 	jr	$ra
/*  f0ea3d4:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func0f0ea3d8
/*  f0ea3d8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0ea3dc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ea3e0:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f0ea3e4:	8cae0008 */ 	lw	$t6,0x8($a1)
/*  f0ea3e8:	00a03825 */ 	or	$a3,$a1,$zero
/*  f0ea3ec:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f0ea3f0:	000fc280 */ 	sll	$t8,$t7,0xa
/*  f0ea3f4:	07030049 */ 	bgezl	$t8,.L0f0ea51c
/*  f0ea3f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ea3fc:	84b90000 */ 	lh	$t9,0x0($a1)
/*  f0ea400:	44803000 */ 	mtc1	$zero,$f6
/*  f0ea404:	afb9002c */ 	sw	$t9,0x2c($sp)
/*  f0ea408:	84a90002 */ 	lh	$t1,0x2($a1)
/*  f0ea40c:	afa90030 */ 	sw	$t1,0x30($sp)
/*  f0ea410:	84aa0004 */ 	lh	$t2,0x4($a1)
/*  f0ea414:	afaa0034 */ 	sw	$t2,0x34($sp)
/*  f0ea418:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f0ea41c:	c4440040 */ 	lwc1	$f4,0x40($v0)
/*  f0ea420:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ea424:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea428:	4502000c */ 	bc1fl	.L0f0ea45c
/*  f0ea42c:	904f003d */ 	lbu	$t7,0x3d($v0)
/*  f0ea430:	904b003c */ 	lbu	$t3,0x3c($v0)
/*  f0ea434:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0ea438:	3c037f1b */ 	lui	$v1,%hi(var7f1b1fb0)
/*  f0ea43c:	01680019 */ 	multu	$t3,$t0
/*  f0ea440:	24631fb0 */ 	addiu	$v1,$v1,%lo(var7f1b1fb0)
/*  f0ea444:	00006012 */ 	mflo	$t4
/*  f0ea448:	006c6821 */ 	addu	$t5,$v1,$t4
/*  f0ea44c:	8dae0020 */ 	lw	$t6,0x20($t5)
/*  f0ea450:	10000013 */ 	beqz	$zero,.L0f0ea4a0
/*  f0ea454:	afae0038 */ 	sw	$t6,0x38($sp)
/*  f0ea458:	904f003d */ 	lbu	$t7,0x3d($v0)
.L0f0ea45c:
/*  f0ea45c:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0ea460:	9049003c */ 	lbu	$t1,0x3c($v0)
/*  f0ea464:	01e80019 */ 	multu	$t7,$t0
/*  f0ea468:	3c037f1b */ 	lui	$v1,%hi(var7f1b1fb0)
/*  f0ea46c:	24631fb0 */ 	addiu	$v1,$v1,%lo(var7f1b1fb0)
/*  f0ea470:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0ea474:	0000c012 */ 	mflo	$t8
/*  f0ea478:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f0ea47c:	8f240020 */ 	lw	$a0,0x20($t9)
/*  f0ea480:	01280019 */ 	multu	$t1,$t0
/*  f0ea484:	00005012 */ 	mflo	$t2
/*  f0ea488:	006a5821 */ 	addu	$t3,$v1,$t2
/*  f0ea48c:	8d650020 */ 	lw	$a1,0x20($t3)
/*  f0ea490:	0fc01a40 */ 	jal	func0f006900
/*  f0ea494:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f0ea498:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0ea49c:	afa20038 */ 	sw	$v0,0x38($sp)
.L0f0ea4a0:
/*  f0ea4a0:	8cec0010 */ 	lw	$t4,0x10($a3)
/*  f0ea4a4:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0ea4a8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ea4ac:	8d8d000c */ 	lw	$t5,0xc($t4)
/*  f0ea4b0:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ea4b4:	51a0000b */ 	beqzl	$t5,.L0f0ea4e4
/*  f0ea4b8:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f0ea4bc:	0fc01a40 */ 	jal	func0f006900
/*  f0ea4c0:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f0ea4c4:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f0ea4c8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea4cc:	00417024 */ 	and	$t6,$v0,$at
/*  f0ea4d0:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0ea4d4:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0ea4d8:	afb90038 */ 	sw	$t9,0x38($sp)
/*  f0ea4dc:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0ea4e0:	8faa0040 */ 	lw	$t2,0x40($sp)
.L0f0ea4e4:
/*  f0ea4e4:	27a2002c */ 	addiu	$v0,$sp,0x2c
/*  f0ea4e8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0ea4ec:	a3a9003c */ 	sb	$t1,0x3c($sp)
/*  f0ea4f0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0ea4f4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0ea4f8:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0ea4fc:	8ce50008 */ 	lw	$a1,0x8($a3)
/*  f0ea500:	24040013 */ 	addiu	$a0,$zero,0x13
/*  f0ea504:	27a6001c */ 	addiu	$a2,$sp,0x1c
/*  f0ea508:	8cb90010 */ 	lw	$t9,0x10($a1)
/*  f0ea50c:	0320f809 */ 	jalr	$t9
/*  f0ea510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea514:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0ea518:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ea51c:
/*  f0ea51c:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0ea520:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0ea524:	03e00008 */ 	jr	$ra
/*  f0ea528:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ea52c
/*  f0ea52c:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f0ea530:	3c0e8008 */ 	lui	$t6,%hi(var8007fb9c)
/*  f0ea534:	3c0f8008 */ 	lui	$t7,%hi(var8007fb10)
/*  f0ea538:	3c188008 */ 	lui	$t8,%hi(var8007fb0c)
/*  f0ea53c:	8dcefb9c */ 	lw	$t6,%lo(var8007fb9c)($t6)
/*  f0ea540:	8deffb10 */ 	lw	$t7,%lo(var8007fb10)($t7)
/*  f0ea544:	8f18fb0c */ 	lw	$t8,%lo(var8007fb0c)($t8)
/*  f0ea548:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ea54c:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0ea550:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0ea554:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f0ea558:	a3ae0097 */ 	sb	$t6,0x97($sp)
/*  f0ea55c:	afaf0090 */ 	sw	$t7,0x90($sp)
/*  f0ea560:	afb8008c */ 	sw	$t8,0x8c($sp)
/*  f0ea564:	84b90000 */ 	lh	$t9,0x0($a1)
/*  f0ea568:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0ea56c:	2728000a */ 	addiu	$t0,$t9,0xa
/*  f0ea570:	afa800a0 */ 	sw	$t0,0xa0($sp)
/*  f0ea574:	84a90002 */ 	lh	$t1,0x2($a1)
/*  f0ea578:	250efffa */ 	addiu	$t6,$t0,-6
/*  f0ea57c:	252a0002 */ 	addiu	$t2,$t1,0x2
/*  f0ea580:	afaa009c */ 	sw	$t2,0x9c($sp)
/*  f0ea584:	8ca70008 */ 	lw	$a3,0x8($a1)
/*  f0ea588:	8ceb0004 */ 	lw	$t3,0x4($a3)
/*  f0ea58c:	316c0010 */ 	andi	$t4,$t3,0x10
/*  f0ea590:	11800003 */ 	beqz	$t4,.L0f0ea5a0
/*  f0ea594:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea598:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f0ea59c:	8ca70008 */ 	lw	$a3,0x8($a1)
.L0f0ea5a0:
/*  f0ea5a0:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0ea5a4:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0ea5a8:	14400003 */ 	bnez	$v0,.L0f0ea5b8
/*  f0ea5ac:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f0ea5b0:	10000194 */ 	beqz	$zero,.L0f0eac04
/*  f0ea5b4:	8fa200b0 */ 	lw	$v0,0xb0($sp)
.L0f0ea5b8:
/*  f0ea5b8:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f0ea5bc:	3c198008 */ 	lui	$t9,%hi(var8007fb08)
/*  f0ea5c0:	3c088008 */ 	lui	$t0,%hi(var8007fb04)
/*  f0ea5c4:	8de20004 */ 	lw	$v0,0x4($t7)
/*  f0ea5c8:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f0ea5cc:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f0ea5d0:	30580200 */ 	andi	$t8,$v0,0x200
/*  f0ea5d4:	5300000b */ 	beqzl	$t8,.L0f0ea604
/*  f0ea5d8:	304c0020 */ 	andi	$t4,$v0,0x20
/*  f0ea5dc:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*  f0ea5e0:	8f39fb08 */ 	lw	$t9,%lo(var8007fb08)($t9)
/*  f0ea5e4:	8d08fb04 */ 	lw	$t0,%lo(var8007fb04)($t0)
/*  f0ea5e8:	252afffe */ 	addiu	$t2,$t1,-2
/*  f0ea5ec:	afaa009c */ 	sw	$t2,0x9c($sp)
/*  f0ea5f0:	afb90090 */ 	sw	$t9,0x90($sp)
/*  f0ea5f4:	afa8008c */ 	sw	$t0,0x8c($sp)
/*  f0ea5f8:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f0ea5fc:	8d620004 */ 	lw	$v0,0x4($t3)
/*  f0ea600:	304c0020 */ 	andi	$t4,$v0,0x20
.L0f0ea604:
/*  f0ea604:	11800012 */ 	beqz	$t4,.L0f0ea650
/*  f0ea608:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0ea60c:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f0ea610:	8fa70090 */ 	lw	$a3,0x90($sp)
/*  f0ea614:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ea618:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ea61c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0ea620:	860e0004 */ 	lh	$t6,0x4($s0)
/*  f0ea624:	8faf0084 */ 	lw	$t7,0x84($sp)
/*  f0ea628:	86080000 */ 	lh	$t0,0x0($s0)
/*  f0ea62c:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f0ea630:	07010003 */ 	bgez	$t8,.L0f0ea640
/*  f0ea634:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0ea638:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0ea63c:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0ea640:
/*  f0ea640:	01194821 */ 	addu	$t1,$t0,$t9
/*  f0ea644:	afa900a0 */ 	sw	$t1,0xa0($sp)
/*  f0ea648:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f0ea64c:	8d420004 */ 	lw	$v0,0x4($t2)
.L0f0ea650:
/*  f0ea650:	304b0100 */ 	andi	$t3,$v0,0x100
/*  f0ea654:	5160003c */ 	beqzl	$t3,.L0f0ea748
/*  f0ea658:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0ea65c:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0ea660:	44803000 */ 	mtc1	$zero,$f6
/*  f0ea664:	3c187f1b */ 	lui	$t8,%hi(var7f1b1fb0)
/*  f0ea668:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0ea66c:	27181fb0 */ 	addiu	$t8,$t8,%lo(var7f1b1fb0)
/*  f0ea670:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ea674:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea678:	4502000a */ 	bc1fl	.L0f0ea6a4
/*  f0ea67c:	906e003d */ 	lbu	$t6,0x3d($v1)
/*  f0ea680:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0ea684:	3c117f1b */ 	lui	$s1,%hi(var7f1b1fd4)
/*  f0ea688:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0ea68c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0ea690:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0ea694:	022d8821 */ 	addu	$s1,$s1,$t5
/*  f0ea698:	10000011 */ 	beqz	$zero,.L0f0ea6e0
/*  f0ea69c:	8e311fd4 */ 	lw	$s1,%lo(var7f1b1fd4)($s1)
/*  f0ea6a0:	906e003d */ 	lbu	$t6,0x3d($v1)
.L0f0ea6a4:
/*  f0ea6a4:	9079003c */ 	lbu	$t9,0x3c($v1)
/*  f0ea6a8:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ea6ac:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f0ea6b0:	00194900 */ 	sll	$t1,$t9,0x4
/*  f0ea6b4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0ea6b8:	01394823 */ 	subu	$t1,$t1,$t9
/*  f0ea6bc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0ea6c0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0ea6c4:	01f84021 */ 	addu	$t0,$t7,$t8
/*  f0ea6c8:	01385021 */ 	addu	$t2,$t1,$t8
/*  f0ea6cc:	8d450024 */ 	lw	$a1,0x24($t2)
/*  f0ea6d0:	0fc01a40 */ 	jal	func0f006900
/*  f0ea6d4:	8d040024 */ 	lw	$a0,0x24($t0)
/*  f0ea6d8:	00408825 */ 	or	$s1,$v0,$zero
/*  f0ea6dc:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0ea6e0:
/*  f0ea6e0:	8c6b000c */ 	lw	$t3,0xc($v1)
/*  f0ea6e4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0ea6e8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ea6ec:	51600009 */ 	beqzl	$t3,.L0f0ea714
/*  f0ea6f0:	9062003c */ 	lbu	$v0,0x3c($v1)
/*  f0ea6f4:	0fc01a40 */ 	jal	func0f006900
/*  f0ea6f8:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ea6fc:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea700:	00416024 */ 	and	$t4,$v0,$at
/*  f0ea704:	322d00ff */ 	andi	$t5,$s1,0xff
/*  f0ea708:	018d8825 */ 	or	$s1,$t4,$t5
/*  f0ea70c:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0ea710:	9062003c */ 	lbu	$v0,0x3c($v1)
.L0f0ea714:
/*  f0ea714:	3c047f1b */ 	lui	$a0,%hi(var7f1b22a4)
/*  f0ea718:	3c057f1b */ 	lui	$a1,%hi(var7f1b213c)
/*  f0ea71c:	00027100 */ 	sll	$t6,$v0,0x4
/*  f0ea720:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f0ea724:	000e1080 */ 	sll	$v0,$t6,0x2
/*  f0ea728:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ea72c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0ea730:	8ca5213c */ 	lw	$a1,%lo(var7f1b213c)($a1)
/*  f0ea734:	0fc54f8e */ 	jal	func0f153e38
/*  f0ea738:	8c8422a4 */ 	lw	$a0,%lo(var7f1b22a4)($a0)
/*  f0ea73c:	1000003a */ 	beqz	$zero,.L0f0ea828
/*  f0ea740:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f0ea744:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0ea748:
/*  f0ea748:	44805000 */ 	mtc1	$zero,$f10
/*  f0ea74c:	3c187f1b */ 	lui	$t8,%hi(var7f1b1fb0)
/*  f0ea750:	c4680040 */ 	lwc1	$f8,0x40($v1)
/*  f0ea754:	27181fb0 */ 	addiu	$t8,$t8,%lo(var7f1b1fb0)
/*  f0ea758:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0ea75c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea760:	4502000a */ 	bc1fl	.L0f0ea78c
/*  f0ea764:	9079003d */ 	lbu	$t9,0x3d($v1)
/*  f0ea768:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0ea76c:	3c117f1b */ 	lui	$s1,%hi(var7f1b1fc8)
/*  f0ea770:	000f4100 */ 	sll	$t0,$t7,0x4
/*  f0ea774:	010f4023 */ 	subu	$t0,$t0,$t7
/*  f0ea778:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ea77c:	02288821 */ 	addu	$s1,$s1,$t0
/*  f0ea780:	10000011 */ 	beqz	$zero,.L0f0ea7c8
/*  f0ea784:	8e311fc8 */ 	lw	$s1,%lo(var7f1b1fc8)($s1)
/*  f0ea788:	9079003d */ 	lbu	$t9,0x3d($v1)
.L0f0ea78c:
/*  f0ea78c:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0ea790:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ea794:	00194900 */ 	sll	$t1,$t9,0x4
/*  f0ea798:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f0ea79c:	01394823 */ 	subu	$t1,$t1,$t9
/*  f0ea7a0:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0ea7a4:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0ea7a8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0ea7ac:	01385021 */ 	addu	$t2,$t1,$t8
/*  f0ea7b0:	01986821 */ 	addu	$t5,$t4,$t8
/*  f0ea7b4:	8da50018 */ 	lw	$a1,0x18($t5)
/*  f0ea7b8:	0fc01a40 */ 	jal	func0f006900
/*  f0ea7bc:	8d440018 */ 	lw	$a0,0x18($t2)
/*  f0ea7c0:	00408825 */ 	or	$s1,$v0,$zero
/*  f0ea7c4:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0ea7c8:
/*  f0ea7c8:	8c6e000c */ 	lw	$t6,0xc($v1)
/*  f0ea7cc:	02202025 */ 	or	$a0,$s1,$zero
/*  f0ea7d0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ea7d4:	51c00009 */ 	beqzl	$t6,.L0f0ea7fc
/*  f0ea7d8:	9062003c */ 	lbu	$v0,0x3c($v1)
/*  f0ea7dc:	0fc01a40 */ 	jal	func0f006900
/*  f0ea7e0:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ea7e4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea7e8:	00417824 */ 	and	$t7,$v0,$at
/*  f0ea7ec:	322800ff */ 	andi	$t0,$s1,0xff
/*  f0ea7f0:	01e88825 */ 	or	$s1,$t7,$t0
/*  f0ea7f4:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0ea7f8:	9062003c */ 	lbu	$v0,0x3c($v1)
.L0f0ea7fc:
/*  f0ea7fc:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0ea800:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0ea804:	0002c900 */ 	sll	$t9,$v0,0x4
/*  f0ea808:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f0ea80c:	00191080 */ 	sll	$v0,$t9,0x2
/*  f0ea810:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ea814:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0ea818:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0ea81c:	0fc54f8e */ 	jal	func0f153e38
/*  f0ea820:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
/*  f0ea824:	8e040008 */ 	lw	$a0,0x8($s0)
.L0f0ea828:
/*  f0ea828:	0fc3c962 */ 	jal	func0f0f2588
/*  f0ea82c:	8e050010 */ 	lw	$a1,0x10($s0)
/*  f0ea830:	10400038 */ 	beqz	$v0,.L0f0ea914
/*  f0ea834:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea838:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0ea83c:	44809000 */ 	mtc1	$zero,$f18
/*  f0ea840:	c4700040 */ 	lwc1	$f16,0x40($v1)
/*  f0ea844:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0ea848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea84c:	4502000a */ 	bc1fl	.L0f0ea878
/*  f0ea850:	906b003d */ 	lbu	$t3,0x3d($v1)
/*  f0ea854:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0ea858:	3c117f1b */ 	lui	$s1,%hi(var7f1b1fcc)
/*  f0ea85c:	00095100 */ 	sll	$t2,$t1,0x4
/*  f0ea860:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0ea864:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0ea868:	022a8821 */ 	addu	$s1,$s1,$t2
/*  f0ea86c:	10000012 */ 	beqz	$zero,.L0f0ea8b8
/*  f0ea870:	8e311fcc */ 	lw	$s1,%lo(var7f1b1fcc)($s1)
/*  f0ea874:	906b003d */ 	lbu	$t3,0x3d($v1)
.L0f0ea878:
/*  f0ea878:	2407003c */ 	addiu	$a3,$zero,0x3c
/*  f0ea87c:	906d003c */ 	lbu	$t5,0x3c($v1)
/*  f0ea880:	01670019 */ 	multu	$t3,$a3
/*  f0ea884:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0ea888:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0ea88c:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ea890:	00006012 */ 	mflo	$t4
/*  f0ea894:	004cc021 */ 	addu	$t8,$v0,$t4
/*  f0ea898:	8f04001c */ 	lw	$a0,0x1c($t8)
/*  f0ea89c:	01a70019 */ 	multu	$t5,$a3
/*  f0ea8a0:	00007012 */ 	mflo	$t6
/*  f0ea8a4:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0ea8a8:	0fc01a40 */ 	jal	func0f006900
/*  f0ea8ac:	8de5001c */ 	lw	$a1,0x1c($t7)
/*  f0ea8b0:	00408825 */ 	or	$s1,$v0,$zero
/*  f0ea8b4:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0ea8b8:
/*  f0ea8b8:	8c68000c */ 	lw	$t0,0xc($v1)
/*  f0ea8bc:	02202025 */ 	or	$a0,$s1,$zero
/*  f0ea8c0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ea8c4:	51000009 */ 	beqzl	$t0,.L0f0ea8ec
/*  f0ea8c8:	9062003c */ 	lbu	$v0,0x3c($v1)
/*  f0ea8cc:	0fc01a40 */ 	jal	func0f006900
/*  f0ea8d0:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ea8d4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea8d8:	0041c824 */ 	and	$t9,$v0,$at
/*  f0ea8dc:	322900ff */ 	andi	$t1,$s1,0xff
/*  f0ea8e0:	03298825 */ 	or	$s1,$t9,$t1
/*  f0ea8e4:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0ea8e8:	9062003c */ 	lbu	$v0,0x3c($v1)
.L0f0ea8ec:
/*  f0ea8ec:	3c047f1b */ 	lui	$a0,%hi(var7f1b229c)
/*  f0ea8f0:	3c057f1b */ 	lui	$a1,%hi(var7f1b2134)
/*  f0ea8f4:	00025100 */ 	sll	$t2,$v0,0x4
/*  f0ea8f8:	01425023 */ 	subu	$t2,$t2,$v0
/*  f0ea8fc:	000a1080 */ 	sll	$v0,$t2,0x2
/*  f0ea900:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ea904:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0ea908:	8ca52134 */ 	lw	$a1,%lo(var7f1b2134)($a1)
/*  f0ea90c:	0fc54f8e */ 	jal	func0f153e38
/*  f0ea910:	8c84229c */ 	lw	$a0,%lo(var7f1b229c)($a0)
.L0f0ea914:
/*  f0ea914:	0fc3c4ce */ 	jal	func0f0f1338
/*  f0ea918:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f0ea91c:	1040001a */ 	beqz	$v0,.L0f0ea988
/*  f0ea920:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0ea924:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f0ea928:	44803000 */ 	mtc1	$zero,$f6
/*  f0ea92c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea930:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ea934:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea938:	45000003 */ 	bc1f	.L0f0ea948
/*  f0ea93c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea940:	100000b0 */ 	beqz	$zero,.L0f0eac04
/*  f0ea944:	8fa200b0 */ 	lw	$v0,0xb0($sp)
.L0f0ea948:
/*  f0ea948:	0fc54f14 */ 	jal	func0f153c50
/*  f0ea94c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea950:	8fab0098 */ 	lw	$t3,0x98($sp)
/*  f0ea954:	3c014396 */ 	lui	$at,0x4396
/*  f0ea958:	44815000 */ 	mtc1	$at,$f10
/*  f0ea95c:	c5680004 */ 	lwc1	$f8,0x4($t3)
/*  f0ea960:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0ea964:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f0ea968:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0ea96c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0ea970:	44068000 */ 	mfc1	$a2,$f16
/*  f0ea974:	0fc54f08 */ 	jal	func0f153c20
/*  f0ea978:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea97c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0ea980:	3c018008 */ 	lui	$at,%hi(var8007fb9c)
/*  f0ea984:	ac2cfb9c */ 	sw	$t4,%lo(var8007fb9c)($at)
.L0f0ea988:
/*  f0ea988:	afb100a8 */ 	sw	$s1,0xa8($sp)
/*  f0ea98c:	8e180008 */ 	lw	$t8,0x8($s0)
/*  f0ea990:	8f0d0004 */ 	lw	$t5,0x4($t8)
/*  f0ea994:	000d71c0 */ 	sll	$t6,$t5,0x7
/*  f0ea998:	05c1000e */ 	bgez	$t6,.L0f0ea9d4
/*  f0ea99c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea9a0:	afb10078 */ 	sw	$s1,0x78($sp)
/*  f0ea9a4:	afb10074 */ 	sw	$s1,0x74($sp)
/*  f0ea9a8:	8e070008 */ 	lw	$a3,0x8($s0)
/*  f0ea9ac:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f0ea9b0:	8ce20010 */ 	lw	$v0,0x10($a3)
/*  f0ea9b4:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0ea9b8:	50400004 */ 	beqzl	$v0,.L0f0ea9cc
/*  f0ea9bc:	8fa80078 */ 	lw	$t0,0x78($sp)
/*  f0ea9c0:	0040f809 */ 	jalr	$v0
/*  f0ea9c4:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0ea9c8:	8fa80078 */ 	lw	$t0,0x78($sp)
.L0f0ea9cc:
/*  f0ea9cc:	8fb10074 */ 	lw	$s1,0x74($sp)
/*  f0ea9d0:	afa800a8 */ 	sw	$t0,0xa8($sp)
.L0f0ea9d4:
/*  f0ea9d4:	0fc54d8a */ 	jal	func0f153628
/*  f0ea9d8:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f0ea9dc:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f0ea9e0:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f0ea9e4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0ea9e8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea9ec:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0ea9f0:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f0ea9f4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea9f8:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f0ea9fc:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0eaa00:	860b0006 */ 	lh	$t3,0x6($s0)
/*  f0eaa04:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eaa08:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eaa0c:	27a6009c */ 	addiu	$a2,$sp,0x9c
/*  f0eaa10:	8fa700a4 */ 	lw	$a3,0xa4($sp)
/*  f0eaa14:	0fc5580f */ 	jal	func0f15603c
/*  f0eaa18:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0eaa1c:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0eaa20:	8e070008 */ 	lw	$a3,0x8($s0)
/*  f0eaa24:	8cec0004 */ 	lw	$t4,0x4($a3)
/*  f0eaa28:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0eaa2c:	31988000 */ 	andi	$t8,$t4,0x8000
/*  f0eaa30:	1700003a */ 	bnez	$t8,.L0f0eab1c
/*  f0eaa34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eaa38:	0fc3c539 */ 	jal	menuResolveText
/*  f0eaa3c:	8ce4000c */ 	lw	$a0,0xc($a3)
/*  f0eaa40:	10400036 */ 	beqz	$v0,.L0f0eab1c
/*  f0eaa44:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f0eaa48:	3c0d7f1b */ 	lui	$t5,%hi(var7f1adfb4)
/*  f0eaa4c:	25addfb4 */ 	addiu	$t5,$t5,%lo(var7f1adfb4)
/*  f0eaa50:	104d0032 */ 	beq	$v0,$t5,.L0f0eab1c
/*  f0eaa54:	27a40070 */ 	addiu	$a0,$sp,0x70
/*  f0eaa58:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f0eaa5c:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0eaa60:	25cf0002 */ 	addiu	$t7,$t6,0x2
/*  f0eaa64:	afaf009c */ 	sw	$t7,0x9c($sp)
/*  f0eaa68:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0eaa6c:	25ebfffe */ 	addiu	$t3,$t7,-2
/*  f0eaa70:	8d190004 */ 	lw	$t9,0x4($t0)
/*  f0eaa74:	33290200 */ 	andi	$t1,$t9,0x200
/*  f0eaa78:	51200003 */ 	beqzl	$t1,.L0f0eaa88
/*  f0eaa7c:	8fac008c */ 	lw	$t4,0x8c($sp)
/*  f0eaa80:	afab009c */ 	sw	$t3,0x9c($sp)
/*  f0eaa84:	8fac008c */ 	lw	$t4,0x8c($sp)
.L0f0eaa88:
/*  f0eaa88:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0eaa8c:	8fa70090 */ 	lw	$a3,0x90($sp)
/*  f0eaa90:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eaa94:	0fc55cbe */ 	jal	func0f1572f8
/*  f0eaa98:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0eaa9c:	86180000 */ 	lh	$t8,0x0($s0)
/*  f0eaaa0:	860d0004 */ 	lh	$t5,0x4($s0)
/*  f0eaaa4:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f0eaaa8:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f0eaaac:	030d7021 */ 	addu	$t6,$t8,$t5
/*  f0eaab0:	01cf4023 */ 	subu	$t0,$t6,$t7
/*  f0eaab4:	2519fff6 */ 	addiu	$t9,$t0,-10
/*  f0eaab8:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*  f0eaabc:	8e090008 */ 	lw	$t1,0x8($s0)
/*  f0eaac0:	272c0006 */ 	addiu	$t4,$t9,0x6
/*  f0eaac4:	27a6009c */ 	addiu	$a2,$sp,0x9c
/*  f0eaac8:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*  f0eaacc:	314b0010 */ 	andi	$t3,$t2,0x10
/*  f0eaad0:	51600003 */ 	beqzl	$t3,.L0f0eaae0
/*  f0eaad4:	8fb80090 */ 	lw	$t8,0x90($sp)
/*  f0eaad8:	afac00a0 */ 	sw	$t4,0xa0($sp)
/*  f0eaadc:	8fb80090 */ 	lw	$t8,0x90($sp)
.L0f0eaae0:
/*  f0eaae0:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f0eaae4:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0eaae8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0eaaec:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0eaaf0:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0eaaf4:	860f0004 */ 	lh	$t7,0x4($s0)
/*  f0eaaf8:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f0eaafc:	8fa700a4 */ 	lw	$a3,0xa4($sp)
/*  f0eab00:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0eab04:	86080006 */ 	lh	$t0,0x6($s0)
/*  f0eab08:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eab0c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eab10:	0fc5580f */ 	jal	func0f15603c
/*  f0eab14:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0eab18:	afa200b0 */ 	sw	$v0,0xb0($sp)
.L0f0eab1c:
/*  f0eab1c:	0fc54de0 */ 	jal	func0f153780
/*  f0eab20:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f0eab24:	8fa90098 */ 	lw	$t1,0x98($sp)
/*  f0eab28:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0eab2c:	3c014396 */ 	lui	$at,0x4396
/*  f0eab30:	5120001a */ 	beqzl	$t1,.L0f0eab9c
/*  f0eab34:	8e180008 */ 	lw	$t8,0x8($s0)
/*  f0eab38:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f0eab3c:	c5260004 */ 	lwc1	$f6,0x4($t1)
/*  f0eab40:	44814000 */ 	mtc1	$at,$f8
/*  f0eab44:	254b00c8 */ 	addiu	$t3,$t2,0xc8
/*  f0eab48:	448b9000 */ 	mtc1	$t3,$f18
/*  f0eab4c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0eab50:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0eab54:	460a203c */ 	c.lt.s	$f4,$f10
/*  f0eab58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eab5c:	4502000b */ 	bc1fl	.L0f0eab8c
/*  f0eab60:	93ac0097 */ 	lbu	$t4,0x97($sp)
/*  f0eab64:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f0eab68:	44809000 */ 	mtc1	$zero,$f18
/*  f0eab6c:	c7300048 */ 	lwc1	$f16,0x48($t9)
/*  f0eab70:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0eab74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eab78:	45020004 */ 	bc1fl	.L0f0eab8c
/*  f0eab7c:	93ac0097 */ 	lbu	$t4,0x97($sp)
/*  f0eab80:	0fc3c4fb */ 	jal	func0f0f13ec
/*  f0eab84:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f0eab88:	93ac0097 */ 	lbu	$t4,0x97($sp)
.L0f0eab8c:
/*  f0eab8c:	3c018008 */ 	lui	$at,%hi(var8007fb9c)
/*  f0eab90:	0fc54f22 */ 	jal	func0f153c88
/*  f0eab94:	ac2cfb9c */ 	sw	$t4,%lo(var8007fb9c)($at)
/*  f0eab98:	8e180008 */ 	lw	$t8,0x8($s0)
.L0f0eab9c:
/*  f0eab9c:	8f0d0004 */ 	lw	$t5,0x4($t8)
/*  f0eaba0:	000d7280 */ 	sll	$t6,$t5,0xa
/*  f0eaba4:	05c30017 */ 	bgezl	$t6,.L0f0eac04
/*  f0eaba8:	8fa200b0 */ 	lw	$v0,0xb0($sp)
/*  f0eabac:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f0eabb0:	8fab00b0 */ 	lw	$t3,0xb0($sp)
/*  f0eabb4:	27a90058 */ 	addiu	$t1,$sp,0x58
/*  f0eabb8:	afaf0058 */ 	sw	$t7,0x58($sp)
/*  f0eabbc:	86080002 */ 	lh	$t0,0x2($s0)
/*  f0eabc0:	24040013 */ 	addiu	$a0,$zero,0x13
/*  f0eabc4:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f0eabc8:	afa8005c */ 	sw	$t0,0x5c($sp)
/*  f0eabcc:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f0eabd0:	afb10064 */ 	sw	$s1,0x64($sp)
/*  f0eabd4:	a3a00068 */ 	sb	$zero,0x68($sp)
/*  f0eabd8:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f0eabdc:	afa90050 */ 	sw	$t1,0x50($sp)
/*  f0eabe0:	afab0048 */ 	sw	$t3,0x48($sp)
/*  f0eabe4:	afaa0060 */ 	sw	$t2,0x60($sp)
/*  f0eabe8:	8e070008 */ 	lw	$a3,0x8($s0)
/*  f0eabec:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0eabf0:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0eabf4:	0320f809 */ 	jalr	$t9
/*  f0eabf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eabfc:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0eac00:	8fa200b0 */ 	lw	$v0,0xb0($sp)
.L0f0eac04:
/*  f0eac04:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0eac08:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0eac0c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0eac10:	03e00008 */ 	jr	$ra
/*  f0eac14:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

GLOBAL_ASM(
glabel func0f0eac18
/*  f0eac18:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f0eac1c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0eac20:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0eac24:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0eac28:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f0eac2c:	8ca30010 */ 	lw	$v1,0x10($a1)
/*  f0eac30:	44803000 */ 	mtc1	$zero,$f6
/*  f0eac34:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0eac38:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0eac3c:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0eac40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eac44:	4502000b */ 	bc1fl	.L0f0eac74
/*  f0eac48:	9079003d */ 	lbu	$t9,0x3d($v1)
/*  f0eac4c:	906e003c */ 	lbu	$t6,0x3c($v1)
/*  f0eac50:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0eac54:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0eac58:	01c80019 */ 	multu	$t6,$t0
/*  f0eac5c:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0eac60:	00007812 */ 	mflo	$t7
/*  f0eac64:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0eac68:	10000012 */ 	beqz	$zero,.L0f0eacb4
/*  f0eac6c:	8f070018 */ 	lw	$a3,0x18($t8)
/*  f0eac70:	9079003d */ 	lbu	$t9,0x3d($v1)
.L0f0eac74:
/*  f0eac74:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0eac78:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0eac7c:	03280019 */ 	multu	$t9,$t0
/*  f0eac80:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0eac84:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0eac88:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eac8c:	00004812 */ 	mflo	$t1
/*  f0eac90:	00495021 */ 	addu	$t2,$v0,$t1
/*  f0eac94:	8d440018 */ 	lw	$a0,0x18($t2)
/*  f0eac98:	01680019 */ 	multu	$t3,$t0
/*  f0eac9c:	00006012 */ 	mflo	$t4
/*  f0eaca0:	004c6821 */ 	addu	$t5,$v0,$t4
/*  f0eaca4:	0fc01a40 */ 	jal	func0f006900
/*  f0eaca8:	8da50018 */ 	lw	$a1,0x18($t5)
/*  f0eacac:	00403825 */ 	or	$a3,$v0,$zero
/*  f0eacb0:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0eacb4:
/*  f0eacb4:	8c6e000c */ 	lw	$t6,0xc($v1)
/*  f0eacb8:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0eacbc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eacc0:	11c00008 */ 	beqz	$t6,.L0f0eace4
/*  f0eacc4:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eacc8:	0fc01a40 */ 	jal	func0f006900
/*  f0eaccc:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0eacd0:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0eacd4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0eacd8:	00417824 */ 	and	$t7,$v0,$at
/*  f0eacdc:	30f800ff */ 	andi	$t8,$a3,0xff
/*  f0eace0:	01f83825 */ 	or	$a3,$t7,$t8
.L0f0eace4:
/*  f0eace4:	30f100ff */ 	andi	$s1,$a3,0xff
/*  f0eace8:	3c01ffff */ 	lui	$at,0xffff
/*  f0eacec:	02212025 */ 	or	$a0,$s1,$at
/*  f0eacf0:	00808825 */ 	or	$s1,$a0,$zero
/*  f0eacf4:	308500ff */ 	andi	$a1,$a0,0xff
/*  f0eacf8:	0fc01a40 */ 	jal	func0f006900
/*  f0eacfc:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ead00:	86060000 */ 	lh	$a2,0x0($s0)
/*  f0ead04:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f0ead08:	00402825 */ 	or	$a1,$v0,$zero
/*  f0ead0c:	24c60020 */ 	addiu	$a2,$a2,0x20
/*  f0ead10:	24c30009 */ 	addiu	$v1,$a2,0x9
/*  f0ead14:	24690006 */ 	addiu	$t1,$v1,0x6
/*  f0ead18:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f0ead1c:	afa90050 */ 	sw	$t1,0x50($sp)
/*  f0ead20:	0fc54df7 */ 	jal	func0f1537dc
/*  f0ead24:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f0ead28:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0ead2c:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f0ead30:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f0ead34:	8faa0054 */ 	lw	$t2,0x54($sp)
/*  f0ead38:	86180002 */ 	lh	$t8,0x2($s0)
/*  f0ead3c:	3c01f600 */ 	lui	$at,0xf600
/*  f0ead40:	014b0019 */ 	multu	$t2,$t3
/*  f0ead44:	27190005 */ 	addiu	$t9,$t8,0x5
/*  f0ead48:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f0ead4c:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0ead50:	8fa60058 */ 	lw	$a2,0x58($sp)
/*  f0ead54:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0ead58:	00006012 */ 	mflo	$t4
/*  f0ead5c:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f0ead60:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f0ead64:	01c17825 */ 	or	$t7,$t6,$at
/*  f0ead68:	01ea5825 */ 	or	$t3,$t7,$t2
/*  f0ead6c:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f0ead70:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0ead74:	86190002 */ 	lh	$t9,0x2($s0)
/*  f0ead78:	00cc0019 */ 	multu	$a2,$t4
/*  f0ead7c:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f0ead80:	00097880 */ 	sll	$t7,$t1,0x2
/*  f0ead84:	00006812 */ 	mflo	$t5
/*  f0ead88:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f0ead8c:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0ead90:	030f5025 */ 	or	$t2,$t8,$t7
/*  f0ead94:	0fc54e0e */ 	jal	func0f153838
/*  f0ead98:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f0ead9c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eada0:	0fc54df7 */ 	jal	func0f1537dc
/*  f0eada4:	02202825 */ 	or	$a1,$s1,$zero
/*  f0eada8:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0eadac:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f0eadb0:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0eadb4:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f0eadb8:	86180002 */ 	lh	$t8,0x2($s0)
/*  f0eadbc:	3c01f600 */ 	lui	$at,0xf600
/*  f0eadc0:	016c0019 */ 	multu	$t3,$t4
/*  f0eadc4:	270f0005 */ 	addiu	$t7,$t8,0x5
/*  f0eadc8:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f0eadcc:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f0eadd0:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0eadd4:	00006812 */ 	mflo	$t5
/*  f0eadd8:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f0eaddc:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0eade0:	03214825 */ 	or	$t1,$t9,$at
/*  f0eade4:	012b6025 */ 	or	$t4,$t1,$t3
/*  f0eade8:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0eadec:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0eadf0:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f0eadf4:	860a0002 */ 	lh	$t2,0x2($s0)
/*  f0eadf8:	01ae0019 */ 	multu	$t5,$t6
/*  f0eadfc:	314903ff */ 	andi	$t1,$t2,0x3ff
/*  f0eae00:	00095880 */ 	sll	$t3,$t1,0x2
/*  f0eae04:	0000c812 */ 	mflo	$t9
/*  f0eae08:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0eae0c:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f0eae10:	01eb6025 */ 	or	$t4,$t7,$t3
/*  f0eae14:	0fc54e0e */ 	jal	func0f153838
/*  f0eae18:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0eae1c:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0eae20:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0eae24:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f0eae28:	1040001f */ 	beqz	$v0,.L0f0eaea8
/*  f0eae2c:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f0eae30:	0fc54d8a */ 	jal	func0f153628
/*  f0eae34:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f0eae38:	860d0000 */ 	lh	$t5,0x0($s0)
/*  f0eae3c:	3c188008 */ 	lui	$t8,%hi(var8007fb08)
/*  f0eae40:	3c0a8008 */ 	lui	$t2,%hi(var8007fb04)
/*  f0eae44:	afad006c */ 	sw	$t5,0x6c($sp)
/*  f0eae48:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f0eae4c:	8d4afb04 */ 	lw	$t2,%lo(var8007fb04)($t2)
/*  f0eae50:	8f18fb08 */ 	lw	$t8,%lo(var8007fb08)($t8)
/*  f0eae54:	2401ff7f */ 	addiu	$at,$zero,-129
/*  f0eae58:	02214824 */ 	and	$t1,$s1,$at
/*  f0eae5c:	25d9ffff */ 	addiu	$t9,$t6,-1
/*  f0eae60:	afb90068 */ 	sw	$t9,0x68($sp)
/*  f0eae64:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0eae68:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0eae6c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0eae70:	860f0004 */ 	lh	$t7,0x4($s0)
/*  f0eae74:	8fa70070 */ 	lw	$a3,0x70($sp)
/*  f0eae78:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eae7c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0eae80:	860b0006 */ 	lh	$t3,0x6($s0)
/*  f0eae84:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eae88:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eae8c:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0eae90:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f0eae94:	0fc5580f */ 	jal	func0f15603c
/*  f0eae98:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0eae9c:	0fc54de0 */ 	jal	func0f153780
/*  f0eaea0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eaea4:	afa20078 */ 	sw	$v0,0x78($sp)
.L0f0eaea8:
/*  f0eaea8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0eaeac:	8fa20078 */ 	lw	$v0,0x78($sp)
/*  f0eaeb0:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0eaeb4:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0eaeb8:	03e00008 */ 	jr	$ra
/*  f0eaebc:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f0eaec0
/*  f0eaec0:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0eaec4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0eaec8:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0eaecc:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0eaed0:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f0eaed4:	84ae0000 */ 	lh	$t6,0x0($a1)
/*  f0eaed8:	3c038008 */ 	lui	$v1,%hi(var8007fb10)
/*  f0eaedc:	3c078008 */ 	lui	$a3,%hi(var8007fb0c)
/*  f0eaee0:	25cf000a */ 	addiu	$t7,$t6,0xa
/*  f0eaee4:	afaf0070 */ 	sw	$t7,0x70($sp)
/*  f0eaee8:	84b80002 */ 	lh	$t8,0x2($a1)
/*  f0eaeec:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0eaef0:	8c63fb10 */ 	lw	$v1,%lo(var8007fb10)($v1)
/*  f0eaef4:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f0eaef8:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f0eaefc:	8ca60008 */ 	lw	$a2,0x8($a1)
/*  f0eaf00:	8ce7fb0c */ 	lw	$a3,%lo(var8007fb0c)($a3)
/*  f0eaf04:	8cc20004 */ 	lw	$v0,0x4($a2)
/*  f0eaf08:	30480010 */ 	andi	$t0,$v0,0x10
/*  f0eaf0c:	11000004 */ 	beqz	$t0,.L0f0eaf20
/*  f0eaf10:	25eafffa */ 	addiu	$t2,$t7,-6
/*  f0eaf14:	afaa0070 */ 	sw	$t2,0x70($sp)
/*  f0eaf18:	8ca60008 */ 	lw	$a2,0x8($a1)
/*  f0eaf1c:	8cc20004 */ 	lw	$v0,0x4($a2)
.L0f0eaf20:
/*  f0eaf20:	00025a40 */ 	sll	$t3,$v0,0x9
/*  f0eaf24:	05610005 */ 	bgez	$t3,.L0f0eaf3c
/*  f0eaf28:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0eaf2c:	3c038008 */ 	lui	$v1,%hi(var8007fb18)
/*  f0eaf30:	3c078008 */ 	lui	$a3,%hi(var8007fb14)
/*  f0eaf34:	8c63fb18 */ 	lw	$v1,%lo(var8007fb18)($v1)
/*  f0eaf38:	8ce7fb14 */ 	lw	$a3,%lo(var8007fb14)($a3)
.L0f0eaf3c:
/*  f0eaf3c:	afa30068 */ 	sw	$v1,0x68($sp)
/*  f0eaf40:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0eaf44:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f0eaf48:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0eaf4c:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0eaf50:	44803000 */ 	mtc1	$zero,$f6
/*  f0eaf54:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0eaf58:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0eaf5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eaf60:	4502000a */ 	bc1fl	.L0f0eaf8c
/*  f0eaf64:	906e003d */ 	lbu	$t6,0x3d($v1)
/*  f0eaf68:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0eaf6c:	3c117f1b */ 	lui	$s1,%hi(var7f1b1fc8)
/*  f0eaf70:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0eaf74:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0eaf78:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0eaf7c:	022d8821 */ 	addu	$s1,$s1,$t5
/*  f0eaf80:	10000013 */ 	beqz	$zero,.L0f0eafd0
/*  f0eaf84:	8e311fc8 */ 	lw	$s1,%lo(var7f1b1fc8)($s1)
/*  f0eaf88:	906e003d */ 	lbu	$t6,0x3d($v1)
.L0f0eaf8c:
/*  f0eaf8c:	9068003c */ 	lbu	$t0,0x3c($v1)
/*  f0eaf90:	3c187f1b */ 	lui	$t8,%hi(var7f1b1fb0)
/*  f0eaf94:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f0eaf98:	00084900 */ 	sll	$t1,$t0,0x4
/*  f0eaf9c:	27181fb0 */ 	addiu	$t8,$t8,%lo(var7f1b1fb0)
/*  f0eafa0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0eafa4:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0eafa8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0eafac:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0eafb0:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0eafb4:	01385021 */ 	addu	$t2,$t1,$t8
/*  f0eafb8:	8d450018 */ 	lw	$a1,0x18($t2)
/*  f0eafbc:	8f240018 */ 	lw	$a0,0x18($t9)
/*  f0eafc0:	0fc01a40 */ 	jal	func0f006900
/*  f0eafc4:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eafc8:	00408825 */ 	or	$s1,$v0,$zero
/*  f0eafcc:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0eafd0:
/*  f0eafd0:	8c6b000c */ 	lw	$t3,0xc($v1)
/*  f0eafd4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0eafd8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eafdc:	51600008 */ 	beqzl	$t3,.L0f0eb000
/*  f0eafe0:	afb10078 */ 	sw	$s1,0x78($sp)
/*  f0eafe4:	0fc01a40 */ 	jal	func0f006900
/*  f0eafe8:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eafec:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0eaff0:	00416024 */ 	and	$t4,$v0,$at
/*  f0eaff4:	322d00ff */ 	andi	$t5,$s1,0xff
/*  f0eaff8:	018d8825 */ 	or	$s1,$t4,$t5
/*  f0eaffc:	afb10078 */ 	sw	$s1,0x78($sp)
.L0f0eb000:
/*  f0eb000:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f0eb004:	3c014220 */ 	lui	$at,0x4220
/*  f0eb008:	51c00062 */ 	beqzl	$t6,.L0f0eb194
/*  f0eb00c:	8e090010 */ 	lw	$t1,0x10($s0)
/*  f0eb010:	44816000 */ 	mtc1	$at,$f12
/*  f0eb014:	0fc01ac2 */ 	jal	func0f006b08
/*  f0eb018:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb01c:	3c01437f */ 	lui	$at,0x437f
/*  f0eb020:	44814000 */ 	mtc1	$at,$f8
/*  f0eb024:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0eb028:	3c0b7f1b */ 	lui	$t3,%hi(var7f1b1fb0)
/*  f0eb02c:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0eb030:	256b1fb0 */ 	addiu	$t3,$t3,%lo(var7f1b1fb0)
/*  f0eb034:	3c014f00 */ 	lui	$at,0x4f00
/*  f0eb038:	444ff800 */ 	cfc1	$t7,$31
/*  f0eb03c:	44d9f800 */ 	ctc1	$t9,$31
/*  f0eb040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb044:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0eb048:	4459f800 */ 	cfc1	$t9,$31
/*  f0eb04c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb050:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0eb054:	53200013 */ 	beqzl	$t9,.L0f0eb0a4
/*  f0eb058:	44198000 */ 	mfc1	$t9,$f16
/*  f0eb05c:	44818000 */ 	mtc1	$at,$f16
/*  f0eb060:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0eb064:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0eb068:	44d9f800 */ 	ctc1	$t9,$31
/*  f0eb06c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb070:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0eb074:	4459f800 */ 	cfc1	$t9,$31
/*  f0eb078:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb07c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0eb080:	17200005 */ 	bnez	$t9,.L0f0eb098
/*  f0eb084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb088:	44198000 */ 	mfc1	$t9,$f16
/*  f0eb08c:	3c018000 */ 	lui	$at,0x8000
/*  f0eb090:	10000007 */ 	beqz	$zero,.L0f0eb0b0
/*  f0eb094:	0321c825 */ 	or	$t9,$t9,$at
.L0f0eb098:
/*  f0eb098:	10000005 */ 	beqz	$zero,.L0f0eb0b0
/*  f0eb09c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0eb0a0:	44198000 */ 	mfc1	$t9,$f16
.L0f0eb0a4:
/*  f0eb0a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb0a8:	0720fffb */ 	bltz	$t9,.L0f0eb098
/*  f0eb0ac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0eb0b0:
/*  f0eb0b0:	afb9005c */ 	sw	$t9,0x5c($sp)
/*  f0eb0b4:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0eb0b8:	44cff800 */ 	ctc1	$t7,$31
/*  f0eb0bc:	44802000 */ 	mtc1	$zero,$f4
/*  f0eb0c0:	c4720040 */ 	lwc1	$f18,0x40($v1)
/*  f0eb0c4:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0eb0c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb0cc:	4502000a */ 	bc1fl	.L0f0eb0f8
/*  f0eb0d0:	9078003d */ 	lbu	$t8,0x3d($v1)
/*  f0eb0d4:	9068003c */ 	lbu	$t0,0x3c($v1)
/*  f0eb0d8:	3c077f1b */ 	lui	$a3,%hi(var7f1b1fd0)
/*  f0eb0dc:	00084900 */ 	sll	$t1,$t0,0x4
/*  f0eb0e0:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0eb0e4:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0eb0e8:	00e93821 */ 	addu	$a3,$a3,$t1
/*  f0eb0ec:	10000010 */ 	beqz	$zero,.L0f0eb130
/*  f0eb0f0:	8ce71fd0 */ 	lw	$a3,%lo(var7f1b1fd0)($a3)
/*  f0eb0f4:	9078003d */ 	lbu	$t8,0x3d($v1)
.L0f0eb0f8:
/*  f0eb0f8:	906d003c */ 	lbu	$t5,0x3c($v1)
/*  f0eb0fc:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eb100:	00185100 */ 	sll	$t2,$t8,0x4
/*  f0eb104:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f0eb108:	01585023 */ 	subu	$t2,$t2,$t8
/*  f0eb10c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0eb110:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0eb114:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0eb118:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f0eb11c:	01cb7821 */ 	addu	$t7,$t6,$t3
/*  f0eb120:	8de50020 */ 	lw	$a1,0x20($t7)
/*  f0eb124:	0fc01a40 */ 	jal	func0f006900
/*  f0eb128:	8d840020 */ 	lw	$a0,0x20($t4)
/*  f0eb12c:	00403825 */ 	or	$a3,$v0,$zero
.L0f0eb130:
/*  f0eb130:	02202025 */ 	or	$a0,$s1,$zero
/*  f0eb134:	322500ff */ 	andi	$a1,$s1,0xff
/*  f0eb138:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eb13c:	0fc01a40 */ 	jal	func0f006900
/*  f0eb140:	afa70060 */ 	sw	$a3,0x60($sp)
/*  f0eb144:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f0eb148:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eb14c:	0fc01a40 */ 	jal	func0f006900
/*  f0eb150:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f0eb154:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f0eb158:	3c047f1b */ 	lui	$a0,%hi(var7f1b22a0)
/*  f0eb15c:	3c057f1b */ 	lui	$a1,%hi(var7f1b2138)
/*  f0eb160:	9326003c */ 	lbu	$a2,0x3c($t9)
/*  f0eb164:	00408825 */ 	or	$s1,$v0,$zero
/*  f0eb168:	00064100 */ 	sll	$t0,$a2,0x4
/*  f0eb16c:	01064023 */ 	subu	$t0,$t0,$a2
/*  f0eb170:	00083080 */ 	sll	$a2,$t0,0x2
/*  f0eb174:	00862021 */ 	addu	$a0,$a0,$a2
/*  f0eb178:	00a62821 */ 	addu	$a1,$a1,$a2
/*  f0eb17c:	8ca52138 */ 	lw	$a1,%lo(var7f1b2138)($a1)
/*  f0eb180:	0fc54f8e */ 	jal	func0f153e38
/*  f0eb184:	8c8422a0 */ 	lw	$a0,%lo(var7f1b22a0)($a0)
/*  f0eb188:	1000000e */ 	beqz	$zero,.L0f0eb1c4
/*  f0eb18c:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f0eb190:	8e090010 */ 	lw	$t1,0x10($s0)
.L0f0eb194:
/*  f0eb194:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0eb198:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0eb19c:	9126003c */ 	lbu	$a2,0x3c($t1)
/*  f0eb1a0:	0006c100 */ 	sll	$t8,$a2,0x4
/*  f0eb1a4:	0306c023 */ 	subu	$t8,$t8,$a2
/*  f0eb1a8:	00183080 */ 	sll	$a2,$t8,0x2
/*  f0eb1ac:	00862021 */ 	addu	$a0,$a0,$a2
/*  f0eb1b0:	00a62821 */ 	addu	$a1,$a1,$a2
/*  f0eb1b4:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0eb1b8:	0fc54f8e */ 	jal	func0f153e38
/*  f0eb1bc:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
/*  f0eb1c0:	8e040008 */ 	lw	$a0,0x8($s0)
.L0f0eb1c4:
/*  f0eb1c4:	0fc3c962 */ 	jal	func0f0f2588
/*  f0eb1c8:	8e050010 */ 	lw	$a1,0x10($s0)
/*  f0eb1cc:	5040003b */ 	beqzl	$v0,.L0f0eb2bc
/*  f0eb1d0:	8e0d0008 */ 	lw	$t5,0x8($s0)
/*  f0eb1d4:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0eb1d8:	44804000 */ 	mtc1	$zero,$f8
/*  f0eb1dc:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0eb1e0:	c4660040 */ 	lwc1	$f6,0x40($v1)
/*  f0eb1e4:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0eb1e8:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0eb1ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb1f0:	4502000a */ 	bc1fl	.L0f0eb21c
/*  f0eb1f4:	906d003d */ 	lbu	$t5,0x3d($v1)
/*  f0eb1f8:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0eb1fc:	3c117f1b */ 	lui	$s1,%hi(var7f1b1fcc)
/*  f0eb200:	000a6100 */ 	sll	$t4,$t2,0x4
/*  f0eb204:	018a6023 */ 	subu	$t4,$t4,$t2
/*  f0eb208:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0eb20c:	022c8821 */ 	addu	$s1,$s1,$t4
/*  f0eb210:	10000011 */ 	beqz	$zero,.L0f0eb258
/*  f0eb214:	8e311fcc */ 	lw	$s1,%lo(var7f1b1fcc)($s1)
/*  f0eb218:	906d003d */ 	lbu	$t5,0x3d($v1)
.L0f0eb21c:
/*  f0eb21c:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0eb220:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eb224:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f0eb228:	000fc900 */ 	sll	$t9,$t7,0x4
/*  f0eb22c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0eb230:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f0eb234:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0eb238:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0eb23c:	004e5821 */ 	addu	$t3,$v0,$t6
/*  f0eb240:	00594021 */ 	addu	$t0,$v0,$t9
/*  f0eb244:	8d05001c */ 	lw	$a1,0x1c($t0)
/*  f0eb248:	0fc01a40 */ 	jal	func0f006900
/*  f0eb24c:	8d64001c */ 	lw	$a0,0x1c($t3)
/*  f0eb250:	00408825 */ 	or	$s1,$v0,$zero
/*  f0eb254:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0eb258:
/*  f0eb258:	8c69000c */ 	lw	$t1,0xc($v1)
/*  f0eb25c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0eb260:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eb264:	51200009 */ 	beqzl	$t1,.L0f0eb28c
/*  f0eb268:	afb10078 */ 	sw	$s1,0x78($sp)
/*  f0eb26c:	0fc01a40 */ 	jal	func0f006900
/*  f0eb270:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eb274:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0eb278:	0041c024 */ 	and	$t8,$v0,$at
/*  f0eb27c:	322a00ff */ 	andi	$t2,$s1,0xff
/*  f0eb280:	030a8825 */ 	or	$s1,$t8,$t2
/*  f0eb284:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0eb288:	afb10078 */ 	sw	$s1,0x78($sp)
.L0f0eb28c:
/*  f0eb28c:	9066003c */ 	lbu	$a2,0x3c($v1)
/*  f0eb290:	3c047f1b */ 	lui	$a0,%hi(var7f1b229c)
/*  f0eb294:	3c057f1b */ 	lui	$a1,%hi(var7f1b2134)
/*  f0eb298:	00066100 */ 	sll	$t4,$a2,0x4
/*  f0eb29c:	01866023 */ 	subu	$t4,$t4,$a2
/*  f0eb2a0:	000c3080 */ 	sll	$a2,$t4,0x2
/*  f0eb2a4:	00862021 */ 	addu	$a0,$a0,$a2
/*  f0eb2a8:	00a62821 */ 	addu	$a1,$a1,$a2
/*  f0eb2ac:	8ca52134 */ 	lw	$a1,%lo(var7f1b2134)($a1)
/*  f0eb2b0:	0fc54f8e */ 	jal	func0f153e38
/*  f0eb2b4:	8c84229c */ 	lw	$a0,%lo(var7f1b229c)($a0)
/*  f0eb2b8:	8e0d0008 */ 	lw	$t5,0x8($s0)
.L0f0eb2bc:
/*  f0eb2bc:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f0eb2c0:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0eb2c4:	8da20004 */ 	lw	$v0,0x4($t5)
/*  f0eb2c8:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0eb2cc:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0eb2d0:	304e0020 */ 	andi	$t6,$v0,0x20
/*  f0eb2d4:	11c00010 */ 	beqz	$t6,.L0f0eb318
/*  f0eb2d8:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0eb2dc:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0eb2e0:	0fc55cbe */ 	jal	func0f1572f8
/*  f0eb2e4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eb2e8:	860f0004 */ 	lh	$t7,0x4($s0)
/*  f0eb2ec:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f0eb2f0:	86180000 */ 	lh	$t8,0x0($s0)
/*  f0eb2f4:	01f94023 */ 	subu	$t0,$t7,$t9
/*  f0eb2f8:	05010003 */ 	bgez	$t0,.L0f0eb308
/*  f0eb2fc:	00084843 */ 	sra	$t1,$t0,0x1
/*  f0eb300:	25010001 */ 	addiu	$at,$t0,0x1
/*  f0eb304:	00014843 */ 	sra	$t1,$at,0x1
.L0f0eb308:
/*  f0eb308:	03095021 */ 	addu	$t2,$t8,$t1
/*  f0eb30c:	afaa0070 */ 	sw	$t2,0x70($sp)
/*  f0eb310:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f0eb314:	8d820004 */ 	lw	$v0,0x4($t4)
.L0f0eb318:
/*  f0eb318:	00026a40 */ 	sll	$t5,$v0,0x9
/*  f0eb31c:	05a10006 */ 	bgez	$t5,.L0f0eb338
/*  f0eb320:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f0eb324:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f0eb328:	25cb0023 */ 	addiu	$t3,$t6,0x23
/*  f0eb32c:	afab0070 */ 	sw	$t3,0x70($sp)
/*  f0eb330:	25f90006 */ 	addiu	$t9,$t7,0x6
/*  f0eb334:	afb9006c */ 	sw	$t9,0x6c($sp)
.L0f0eb338:
/*  f0eb338:	0fc54d8a */ 	jal	func0f153628
/*  f0eb33c:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0eb340:	8fa80068 */ 	lw	$t0,0x68($sp)
/*  f0eb344:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f0eb348:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0eb34c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eb350:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0eb354:	86090004 */ 	lh	$t1,0x4($s0)
/*  f0eb358:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eb35c:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0eb360:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0eb364:	860a0006 */ 	lh	$t2,0x6($s0)
/*  f0eb368:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eb36c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eb370:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f0eb374:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f0eb378:	0fc5580f */ 	jal	func0f15603c
/*  f0eb37c:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0eb380:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f0eb384:	8e060008 */ 	lw	$a2,0x8($s0)
/*  f0eb388:	3c010040 */ 	lui	$at,0x40
/*  f0eb38c:	34218000 */ 	ori	$at,$at,0x8000
/*  f0eb390:	8ccc0004 */ 	lw	$t4,0x4($a2)
/*  f0eb394:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0eb398:	01816824 */ 	and	$t5,$t4,$at
/*  f0eb39c:	15a0002c */ 	bnez	$t5,.L0f0eb450
/*  f0eb3a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb3a4:	0fc3c539 */ 	jal	menuResolveText
/*  f0eb3a8:	8cc4000c */ 	lw	$a0,0xc($a2)
/*  f0eb3ac:	10400028 */ 	beqz	$v0,.L0f0eb450
/*  f0eb3b0:	00403025 */ 	or	$a2,$v0,$zero
/*  f0eb3b4:	3c0e7f1b */ 	lui	$t6,%hi(var7f1adfb8)
/*  f0eb3b8:	25cedfb8 */ 	addiu	$t6,$t6,%lo(var7f1adfb8)
/*  f0eb3bc:	104e0024 */ 	beq	$v0,$t6,.L0f0eb450
/*  f0eb3c0:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f0eb3c4:	860b0002 */ 	lh	$t3,0x2($s0)
/*  f0eb3c8:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0eb3cc:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0eb3d0:	256f0002 */ 	addiu	$t7,$t3,0x2
/*  f0eb3d4:	afaf006c */ 	sw	$t7,0x6c($sp)
/*  f0eb3d8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eb3dc:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0eb3e0:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0eb3e4:	0fc55cbe */ 	jal	func0f1572f8
/*  f0eb3e8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0eb3ec:	86080000 */ 	lh	$t0,0x0($s0)
/*  f0eb3f0:	86180004 */ 	lh	$t8,0x4($s0)
/*  f0eb3f4:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f0eb3f8:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f0eb3fc:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0eb400:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0eb404:	01184821 */ 	addu	$t1,$t0,$t8
/*  f0eb408:	012a6023 */ 	subu	$t4,$t1,$t2
/*  f0eb40c:	258dfff6 */ 	addiu	$t5,$t4,-10
/*  f0eb410:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f0eb414:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0eb418:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0eb41c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0eb420:	86190004 */ 	lh	$t9,0x4($s0)
/*  f0eb424:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0eb428:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0eb42c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0eb430:	86080006 */ 	lh	$t0,0x6($s0)
/*  f0eb434:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eb438:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eb43c:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f0eb440:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f0eb444:	0fc5580f */ 	jal	func0f15603c
/*  f0eb448:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0eb44c:	afa20080 */ 	sw	$v0,0x80($sp)
.L0f0eb450:
/*  f0eb450:	0fc54de0 */ 	jal	func0f153780
/*  f0eb454:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0eb458:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0eb45c:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0eb460:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0eb464:	03e00008 */ 	jr	$ra
/*  f0eb468:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

GLOBAL_ASM(
glabel func0f0eb46c
/*  f0eb46c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0eb470:	30ce0002 */ 	andi	$t6,$a2,0x2
/*  f0eb474:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0eb478:	11c0001e */ 	beqz	$t6,.L0f0eb4f4
/*  f0eb47c:	00803825 */ 	or	$a3,$a0,$zero
/*  f0eb480:	90af0002 */ 	lbu	$t7,0x2($a1)
/*  f0eb484:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0eb488:	51e0001b */ 	beqzl	$t7,.L0f0eb4f8
/*  f0eb48c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0eb490:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0eb494:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0eb498:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0eb49c:	8ce20004 */ 	lw	$v0,0x4($a3)
/*  f0eb4a0:	30580008 */ 	andi	$t8,$v0,0x8
/*  f0eb4a4:	53000006 */ 	beqzl	$t8,.L0f0eb4c0
/*  f0eb4a8:	30590004 */ 	andi	$t9,$v0,0x4
/*  f0eb4ac:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0eb4b0:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0eb4b4:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0eb4b8:	8ce20004 */ 	lw	$v0,0x4($a3)
/*  f0eb4bc:	30590004 */ 	andi	$t9,$v0,0x4
.L0f0eb4c0:
/*  f0eb4c0:	53200006 */ 	beqzl	$t9,.L0f0eb4dc
/*  f0eb4c4:	8ce20010 */ 	lw	$v0,0x10($a3)
/*  f0eb4c8:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0eb4cc:	8ce40010 */ 	lw	$a0,0x10($a3)
/*  f0eb4d0:	10000009 */ 	beqz	$zero,.L0f0eb4f8
/*  f0eb4d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0eb4d8:	8ce20010 */ 	lw	$v0,0x10($a3)
.L0f0eb4dc:
/*  f0eb4dc:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0eb4e0:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0eb4e4:	50400004 */ 	beqzl	$v0,.L0f0eb4f8
/*  f0eb4e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0eb4ec:	0040f809 */ 	jalr	$v0
/*  f0eb4f0:	27a60020 */ 	addiu	$a2,$sp,0x20
.L0f0eb4f4:
/*  f0eb4f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0eb4f8:
/*  f0eb4f8:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0eb4fc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0eb500:	03e00008 */ 	jr	$ra
/*  f0eb504:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0eb508
/*  f0eb508:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f0eb50c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0eb510:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0eb514:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0eb518:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0eb51c:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f0eb520:	afa0008c */ 	sw	$zero,0x8c($sp)
/*  f0eb524:	8ca70008 */ 	lw	$a3,0x8($a1)
/*  f0eb528:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0eb52c:	8ce20010 */ 	lw	$v0,0x10($a3)
/*  f0eb530:	10400008 */ 	beqz	$v0,.L0f0eb554
/*  f0eb534:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0eb538:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0eb53c:	0040f809 */ 	jalr	$v0
/*  f0eb540:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0eb544:	87ae0076 */ 	lh	$t6,0x76($sp)
/*  f0eb548:	afae0070 */ 	sw	$t6,0x70($sp)
/*  f0eb54c:	10000002 */ 	beqz	$zero,.L0f0eb558
/*  f0eb550:	8e270008 */ 	lw	$a3,0x8($s1)
.L0f0eb554:
/*  f0eb554:	afa00070 */ 	sw	$zero,0x70($sp)
.L0f0eb558:
/*  f0eb558:	8e2f0010 */ 	lw	$t7,0x10($s1)
/*  f0eb55c:	91f8006e */ 	lbu	$t8,0x6e($t7)
/*  f0eb560:	13000002 */ 	beqz	$t8,.L0f0eb56c
/*  f0eb564:	2419000a */ 	addiu	$t9,$zero,0xa
/*  f0eb568:	afb9008c */ 	sw	$t9,0x8c($sp)
.L0f0eb56c:
/*  f0eb56c:	8ce80004 */ 	lw	$t0,0x4($a3)
/*  f0eb570:	00084ac0 */ 	sll	$t1,$t0,0xb
/*  f0eb574:	05210002 */ 	bgez	$t1,.L0f0eb580
/*  f0eb578:	240a000a */ 	addiu	$t2,$zero,0xa
/*  f0eb57c:	afaa008c */ 	sw	$t2,0x8c($sp)
.L0f0eb580:
/*  f0eb580:	862b0000 */ 	lh	$t3,0x0($s1)
/*  f0eb584:	256c000a */ 	addiu	$t4,$t3,0xa
/*  f0eb588:	afac0094 */ 	sw	$t4,0x94($sp)
/*  f0eb58c:	862d0002 */ 	lh	$t5,0x2($s1)
/*  f0eb590:	25ae0002 */ 	addiu	$t6,$t5,0x2
/*  f0eb594:	afae0090 */ 	sw	$t6,0x90($sp)
/*  f0eb598:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0eb59c:	8cef0004 */ 	lw	$t7,0x4($a3)
/*  f0eb5a0:	31f80010 */ 	andi	$t8,$t7,0x10
/*  f0eb5a4:	13000003 */ 	beqz	$t8,.L0f0eb5b4
/*  f0eb5a8:	2588fffa */ 	addiu	$t0,$t4,-6
/*  f0eb5ac:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f0eb5b0:	8e270008 */ 	lw	$a3,0x8($s1)
.L0f0eb5b4:
/*  f0eb5b4:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0eb5b8:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0eb5bc:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f0eb5c0:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f0eb5c4:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0eb5c8:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0eb5cc:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0eb5d0:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0eb5d4:	8dcf000c */ 	lw	$t7,0xc($t6)
/*  f0eb5d8:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0eb5dc:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0eb5e0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0eb5e4:	01af001a */ 	div	$zero,$t5,$t7
/*  f0eb5e8:	862a0004 */ 	lh	$t2,0x4($s1)
/*  f0eb5ec:	86290000 */ 	lh	$t1,0x0($s1)
/*  f0eb5f0:	0000c012 */ 	mflo	$t8
/*  f0eb5f4:	44803000 */ 	mtc1	$zero,$f6
/*  f0eb5f8:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f0eb5fc:	0178c821 */ 	addu	$t9,$t3,$t8
/*  f0eb600:	2728ffae */ 	addiu	$t0,$t9,-82
/*  f0eb604:	afa8006c */ 	sw	$t0,0x6c($sp)
/*  f0eb608:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0eb60c:	15e00002 */ 	bnez	$t7,.L0f0eb618
/*  f0eb610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb614:	0007000d */ 	break	0x7
.L0f0eb618:
/*  f0eb618:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0eb61c:	15e10004 */ 	bne	$t7,$at,.L0f0eb630
/*  f0eb620:	3c018000 */ 	lui	$at,0x8000
/*  f0eb624:	15a10002 */ 	bne	$t5,$at,.L0f0eb630
/*  f0eb628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb62c:	0006000d */ 	break	0x6
.L0f0eb630:
/*  f0eb630:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0eb634:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0eb638:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb63c:	4502000a */ 	bc1fl	.L0f0eb668
/*  f0eb640:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0eb644:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0eb648:	2412003c */ 	addiu	$s2,$zero,0x3c
/*  f0eb64c:	3c107f1b */ 	lui	$s0,%hi(var7f1b1fc8)
/*  f0eb650:	01320019 */ 	multu	$t1,$s2
/*  f0eb654:	00005012 */ 	mflo	$t2
/*  f0eb658:	020a8021 */ 	addu	$s0,$s0,$t2
/*  f0eb65c:	10000012 */ 	beqz	$zero,.L0f0eb6a8
/*  f0eb660:	8e101fc8 */ 	lw	$s0,%lo(var7f1b1fc8)($s0)
/*  f0eb664:	906c003d */ 	lbu	$t4,0x3d($v1)
.L0f0eb668:
/*  f0eb668:	2412003c */ 	addiu	$s2,$zero,0x3c
/*  f0eb66c:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0eb670:	01920019 */ 	multu	$t4,$s2
/*  f0eb674:	3c0d7f1b */ 	lui	$t5,%hi(var7f1b1fb0)
/*  f0eb678:	25ad1fb0 */ 	addiu	$t5,$t5,%lo(var7f1b1fb0)
/*  f0eb67c:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eb680:	00007012 */ 	mflo	$t6
/*  f0eb684:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0eb688:	8de40018 */ 	lw	$a0,0x18($t7)
/*  f0eb68c:	01720019 */ 	multu	$t3,$s2
/*  f0eb690:	0000c012 */ 	mflo	$t8
/*  f0eb694:	030dc821 */ 	addu	$t9,$t8,$t5
/*  f0eb698:	0fc01a40 */ 	jal	func0f006900
/*  f0eb69c:	8f250018 */ 	lw	$a1,0x18($t9)
/*  f0eb6a0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0eb6a4:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0eb6a8:
/*  f0eb6a8:	8c68000c */ 	lw	$t0,0xc($v1)
/*  f0eb6ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eb6b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eb6b4:	51000008 */ 	beqzl	$t0,.L0f0eb6d8
/*  f0eb6b8:	8e22000c */ 	lw	$v0,0xc($s1)
/*  f0eb6bc:	0fc01a40 */ 	jal	func0f006900
/*  f0eb6c0:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eb6c4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0eb6c8:	00414824 */ 	and	$t1,$v0,$at
/*  f0eb6cc:	320a00ff */ 	andi	$t2,$s0,0xff
/*  f0eb6d0:	012a8025 */ 	or	$s0,$t1,$t2
/*  f0eb6d4:	8e22000c */ 	lw	$v0,0xc($s1)
.L0f0eb6d8:
/*  f0eb6d8:	1040005f */ 	beqz	$v0,.L0f0eb858
/*  f0eb6dc:	304c0002 */ 	andi	$t4,$v0,0x2
/*  f0eb6e0:	11800050 */ 	beqz	$t4,.L0f0eb824
/*  f0eb6e4:	3c014220 */ 	lui	$at,0x4220
/*  f0eb6e8:	44816000 */ 	mtc1	$at,$f12
/*  f0eb6ec:	0fc01ac2 */ 	jal	func0f006b08
/*  f0eb6f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb6f4:	3c01437f */ 	lui	$at,0x437f
/*  f0eb6f8:	44814000 */ 	mtc1	$at,$f8
/*  f0eb6fc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0eb700:	3c014f00 */ 	lui	$at,0x4f00
/*  f0eb704:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0eb708:	444ef800 */ 	cfc1	$t6,$31
/*  f0eb70c:	44cff800 */ 	ctc1	$t7,$31
/*  f0eb710:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb714:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0eb718:	444ff800 */ 	cfc1	$t7,$31
/*  f0eb71c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb720:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0eb724:	51e00013 */ 	beqzl	$t7,.L0f0eb774
/*  f0eb728:	440f8000 */ 	mfc1	$t7,$f16
/*  f0eb72c:	44818000 */ 	mtc1	$at,$f16
/*  f0eb730:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0eb734:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0eb738:	44cff800 */ 	ctc1	$t7,$31
/*  f0eb73c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb740:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0eb744:	444ff800 */ 	cfc1	$t7,$31
/*  f0eb748:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb74c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0eb750:	15e00005 */ 	bnez	$t7,.L0f0eb768
/*  f0eb754:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb758:	440f8000 */ 	mfc1	$t7,$f16
/*  f0eb75c:	3c018000 */ 	lui	$at,0x8000
/*  f0eb760:	10000007 */ 	beqz	$zero,.L0f0eb780
/*  f0eb764:	01e17825 */ 	or	$t7,$t7,$at
.L0f0eb768:
/*  f0eb768:	10000005 */ 	beqz	$zero,.L0f0eb780
/*  f0eb76c:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0eb770:	440f8000 */ 	mfc1	$t7,$f16
.L0f0eb774:
/*  f0eb774:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb778:	05e0fffb */ 	bltz	$t7,.L0f0eb768
/*  f0eb77c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0eb780:
/*  f0eb780:	afaf0064 */ 	sw	$t7,0x64($sp)
/*  f0eb784:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0eb788:	44cef800 */ 	ctc1	$t6,$31
/*  f0eb78c:	44802000 */ 	mtc1	$zero,$f4
/*  f0eb790:	c4720040 */ 	lwc1	$f18,0x40($v1)
/*  f0eb794:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0eb798:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb79c:	45020009 */ 	bc1fl	.L0f0eb7c4
/*  f0eb7a0:	906d003d */ 	lbu	$t5,0x3d($v1)
/*  f0eb7a4:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0eb7a8:	3c077f1b */ 	lui	$a3,%hi(var7f1b1fd0)
/*  f0eb7ac:	01720019 */ 	multu	$t3,$s2
/*  f0eb7b0:	0000c012 */ 	mflo	$t8
/*  f0eb7b4:	00f83821 */ 	addu	$a3,$a3,$t8
/*  f0eb7b8:	10000010 */ 	beqz	$zero,.L0f0eb7fc
/*  f0eb7bc:	8ce71fd0 */ 	lw	$a3,%lo(var7f1b1fd0)($a3)
/*  f0eb7c0:	906d003d */ 	lbu	$t5,0x3d($v1)
.L0f0eb7c4:
/*  f0eb7c4:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0eb7c8:	3c087f1b */ 	lui	$t0,%hi(var7f1b1fb0)
/*  f0eb7cc:	01b20019 */ 	multu	$t5,$s2
/*  f0eb7d0:	25081fb0 */ 	addiu	$t0,$t0,%lo(var7f1b1fb0)
/*  f0eb7d4:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eb7d8:	0000c812 */ 	mflo	$t9
/*  f0eb7dc:	03284821 */ 	addu	$t1,$t9,$t0
/*  f0eb7e0:	8d240020 */ 	lw	$a0,0x20($t1)
/*  f0eb7e4:	01520019 */ 	multu	$t2,$s2
/*  f0eb7e8:	00006012 */ 	mflo	$t4
/*  f0eb7ec:	01887021 */ 	addu	$t6,$t4,$t0
/*  f0eb7f0:	0fc01a40 */ 	jal	func0f006900
/*  f0eb7f4:	8dc50020 */ 	lw	$a1,0x20($t6)
/*  f0eb7f8:	00403825 */ 	or	$a3,$v0,$zero
.L0f0eb7fc:
/*  f0eb7fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eb800:	320500ff */ 	andi	$a1,$s0,0xff
/*  f0eb804:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eb808:	0fc01a40 */ 	jal	func0f006900
/*  f0eb80c:	afa70068 */ 	sw	$a3,0x68($sp)
/*  f0eb810:	8fa50068 */ 	lw	$a1,0x68($sp)
/*  f0eb814:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eb818:	0fc01a40 */ 	jal	func0f006900
/*  f0eb81c:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f0eb820:	345000ff */ 	ori	$s0,$v0,0xff
.L0f0eb824:
/*  f0eb824:	8e2f0010 */ 	lw	$t7,0x10($s1)
/*  f0eb828:	3c047f1b */ 	lui	$a0,%hi(var7f1b22a0)
/*  f0eb82c:	3c057f1b */ 	lui	$a1,%hi(var7f1b2138)
/*  f0eb830:	91eb003c */ 	lbu	$t3,0x3c($t7)
/*  f0eb834:	01720019 */ 	multu	$t3,$s2
/*  f0eb838:	00001012 */ 	mflo	$v0
/*  f0eb83c:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0eb840:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0eb844:	8ca52138 */ 	lw	$a1,%lo(var7f1b2138)($a1)
/*  f0eb848:	0fc54f8e */ 	jal	func0f153e38
/*  f0eb84c:	8c8422a0 */ 	lw	$a0,%lo(var7f1b22a0)($a0)
/*  f0eb850:	1000000d */ 	beqz	$zero,.L0f0eb888
/*  f0eb854:	862a0002 */ 	lh	$t2,0x2($s1)
.L0f0eb858:
/*  f0eb858:	8e380010 */ 	lw	$t8,0x10($s1)
/*  f0eb85c:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0eb860:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0eb864:	930d003c */ 	lbu	$t5,0x3c($t8)
/*  f0eb868:	01b20019 */ 	multu	$t5,$s2
/*  f0eb86c:	00001012 */ 	mflo	$v0
/*  f0eb870:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0eb874:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0eb878:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0eb87c:	0fc54f8e */ 	jal	func0f153e38
/*  f0eb880:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
/*  f0eb884:	862a0002 */ 	lh	$t2,0x2($s1)
.L0f0eb888:
/*  f0eb888:	8fac008c */ 	lw	$t4,0x8c($sp)
/*  f0eb88c:	86390000 */ 	lh	$t9,0x0($s1)
/*  f0eb890:	86290004 */ 	lh	$t1,0x4($s1)
/*  f0eb894:	8fae006c */ 	lw	$t6,0x6c($sp)
/*  f0eb898:	014c1821 */ 	addu	$v1,$t2,$t4
/*  f0eb89c:	2468000b */ 	addiu	$t0,$v1,0xb
/*  f0eb8a0:	03291021 */ 	addu	$v0,$t9,$t1
/*  f0eb8a4:	2445ffae */ 	addiu	$a1,$v0,-82
/*  f0eb8a8:	2447fff9 */ 	addiu	$a3,$v0,-7
/*  f0eb8ac:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eb8b0:	24660005 */ 	addiu	$a2,$v1,0x5
/*  f0eb8b4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eb8b8:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f0eb8bc:	0fc387eb */ 	jal	func0f0e1fac
/*  f0eb8c0:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0eb8c4:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0eb8c8:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0eb8cc:	44804000 */ 	mtc1	$zero,$f8
/*  f0eb8d0:	c4660040 */ 	lwc1	$f6,0x40($v1)
/*  f0eb8d4:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0eb8d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb8dc:	45020009 */ 	bc1fl	.L0f0eb904
/*  f0eb8e0:	9078003d */ 	lbu	$t8,0x3d($v1)
/*  f0eb8e4:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0eb8e8:	3c107f1b */ 	lui	$s0,%hi(var7f1b1fc8)
/*  f0eb8ec:	01f20019 */ 	multu	$t7,$s2
/*  f0eb8f0:	00005812 */ 	mflo	$t3
/*  f0eb8f4:	020b8021 */ 	addu	$s0,$s0,$t3
/*  f0eb8f8:	10000011 */ 	beqz	$zero,.L0f0eb940
/*  f0eb8fc:	8e101fc8 */ 	lw	$s0,%lo(var7f1b1fc8)($s0)
/*  f0eb900:	9078003d */ 	lbu	$t8,0x3d($v1)
.L0f0eb904:
/*  f0eb904:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0eb908:	3c197f1b */ 	lui	$t9,%hi(var7f1b1fb0)
/*  f0eb90c:	03120019 */ 	multu	$t8,$s2
/*  f0eb910:	27391fb0 */ 	addiu	$t9,$t9,%lo(var7f1b1fb0)
/*  f0eb914:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eb918:	00006812 */ 	mflo	$t5
/*  f0eb91c:	01b94821 */ 	addu	$t1,$t5,$t9
/*  f0eb920:	8d240018 */ 	lw	$a0,0x18($t1)
/*  f0eb924:	01520019 */ 	multu	$t2,$s2
/*  f0eb928:	00006012 */ 	mflo	$t4
/*  f0eb92c:	01994021 */ 	addu	$t0,$t4,$t9
/*  f0eb930:	0fc01a40 */ 	jal	func0f006900
/*  f0eb934:	8d050018 */ 	lw	$a1,0x18($t0)
/*  f0eb938:	00408025 */ 	or	$s0,$v0,$zero
/*  f0eb93c:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0eb940:
/*  f0eb940:	8c6e000c */ 	lw	$t6,0xc($v1)
/*  f0eb944:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eb948:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eb94c:	51c00008 */ 	beqzl	$t6,.L0f0eb970
/*  f0eb950:	8e22000c */ 	lw	$v0,0xc($s1)
/*  f0eb954:	0fc01a40 */ 	jal	func0f006900
/*  f0eb958:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eb95c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0eb960:	00417824 */ 	and	$t7,$v0,$at
/*  f0eb964:	320b00ff */ 	andi	$t3,$s0,0xff
/*  f0eb968:	01eb8025 */ 	or	$s0,$t7,$t3
/*  f0eb96c:	8e22000c */ 	lw	$v0,0xc($s1)
.L0f0eb970:
/*  f0eb970:	104000b0 */ 	beqz	$v0,.L0f0ebc34
/*  f0eb974:	30580002 */ 	andi	$t8,$v0,0x2
/*  f0eb978:	13000052 */ 	beqz	$t8,.L0f0ebac4
/*  f0eb97c:	3c014220 */ 	lui	$at,0x4220
/*  f0eb980:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0eb984:	44816000 */ 	mtc1	$at,$f12
/*  f0eb988:	0fc01ac2 */ 	jal	func0f006b08
/*  f0eb98c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb990:	3c01437f */ 	lui	$at,0x437f
/*  f0eb994:	44815000 */ 	mtc1	$at,$f10
/*  f0eb998:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0eb99c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0eb9a0:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f0eb9a4:	444df800 */ 	cfc1	$t5,$31
/*  f0eb9a8:	44c9f800 */ 	ctc1	$t1,$31
/*  f0eb9ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb9b0:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f0eb9b4:	4449f800 */ 	cfc1	$t1,$31
/*  f0eb9b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb9bc:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0eb9c0:	51200013 */ 	beqzl	$t1,.L0f0eba10
/*  f0eb9c4:	44099000 */ 	mfc1	$t1,$f18
/*  f0eb9c8:	44819000 */ 	mtc1	$at,$f18
/*  f0eb9cc:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0eb9d0:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f0eb9d4:	44c9f800 */ 	ctc1	$t1,$31
/*  f0eb9d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb9dc:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f0eb9e0:	4449f800 */ 	cfc1	$t1,$31
/*  f0eb9e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb9e8:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0eb9ec:	15200005 */ 	bnez	$t1,.L0f0eba04
/*  f0eb9f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb9f4:	44099000 */ 	mfc1	$t1,$f18
/*  f0eb9f8:	3c018000 */ 	lui	$at,0x8000
/*  f0eb9fc:	10000007 */ 	beqz	$zero,.L0f0eba1c
/*  f0eba00:	01214825 */ 	or	$t1,$t1,$at
.L0f0eba04:
/*  f0eba04:	10000005 */ 	beqz	$zero,.L0f0eba1c
/*  f0eba08:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0eba0c:	44099000 */ 	mfc1	$t1,$f18
.L0f0eba10:
/*  f0eba10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eba14:	0520fffb */ 	bltz	$t1,.L0f0eba04
/*  f0eba18:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0eba1c:
/*  f0eba1c:	afa9005c */ 	sw	$t1,0x5c($sp)
/*  f0eba20:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0eba24:	44cdf800 */ 	ctc1	$t5,$31
/*  f0eba28:	44803000 */ 	mtc1	$zero,$f6
/*  f0eba2c:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0eba30:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0eba34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eba38:	45020009 */ 	bc1fl	.L0f0eba60
/*  f0eba3c:	9079003d */ 	lbu	$t9,0x3d($v1)
/*  f0eba40:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0eba44:	3c077f1b */ 	lui	$a3,%hi(var7f1b1fd0)
/*  f0eba48:	01520019 */ 	multu	$t2,$s2
/*  f0eba4c:	00006012 */ 	mflo	$t4
/*  f0eba50:	00ec3821 */ 	addu	$a3,$a3,$t4
/*  f0eba54:	10000010 */ 	beqz	$zero,.L0f0eba98
/*  f0eba58:	8ce71fd0 */ 	lw	$a3,%lo(var7f1b1fd0)($a3)
/*  f0eba5c:	9079003d */ 	lbu	$t9,0x3d($v1)
.L0f0eba60:
/*  f0eba60:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0eba64:	3c0e7f1b */ 	lui	$t6,%hi(var7f1b1fb0)
/*  f0eba68:	03320019 */ 	multu	$t9,$s2
/*  f0eba6c:	25ce1fb0 */ 	addiu	$t6,$t6,%lo(var7f1b1fb0)
/*  f0eba70:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eba74:	00004012 */ 	mflo	$t0
/*  f0eba78:	010e7821 */ 	addu	$t7,$t0,$t6
/*  f0eba7c:	8de40020 */ 	lw	$a0,0x20($t7)
/*  f0eba80:	01720019 */ 	multu	$t3,$s2
/*  f0eba84:	0000c012 */ 	mflo	$t8
/*  f0eba88:	030e6821 */ 	addu	$t5,$t8,$t6
/*  f0eba8c:	0fc01a40 */ 	jal	func0f006900
/*  f0eba90:	8da50020 */ 	lw	$a1,0x20($t5)
/*  f0eba94:	00403825 */ 	or	$a3,$v0,$zero
.L0f0eba98:
/*  f0eba98:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eba9c:	320500ff */ 	andi	$a1,$s0,0xff
/*  f0ebaa0:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ebaa4:	0fc01a40 */ 	jal	func0f006900
/*  f0ebaa8:	afa70060 */ 	sw	$a3,0x60($sp)
/*  f0ebaac:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f0ebab0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ebab4:	0fc01a40 */ 	jal	func0f006900
/*  f0ebab8:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f0ebabc:	10000050 */ 	beqz	$zero,.L0f0ebc00
/*  f0ebac0:	00408025 */ 	or	$s0,$v0,$zero
.L0f0ebac4:
/*  f0ebac4:	44816000 */ 	mtc1	$at,$f12
/*  f0ebac8:	0fc01ac2 */ 	jal	func0f006b08
/*  f0ebacc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebad0:	3c01437f */ 	lui	$at,0x437f
/*  f0ebad4:	44814000 */ 	mtc1	$at,$f8
/*  f0ebad8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ebadc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0ebae0:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0ebae4:	4449f800 */ 	cfc1	$t1,$31
/*  f0ebae8:	44caf800 */ 	ctc1	$t2,$31
/*  f0ebaec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebaf0:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0ebaf4:	444af800 */ 	cfc1	$t2,$31
/*  f0ebaf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebafc:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0ebb00:	51400013 */ 	beqzl	$t2,.L0f0ebb50
/*  f0ebb04:	440a8000 */ 	mfc1	$t2,$f16
/*  f0ebb08:	44818000 */ 	mtc1	$at,$f16
/*  f0ebb0c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ebb10:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0ebb14:	44caf800 */ 	ctc1	$t2,$31
/*  f0ebb18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebb1c:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0ebb20:	444af800 */ 	cfc1	$t2,$31
/*  f0ebb24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebb28:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0ebb2c:	15400005 */ 	bnez	$t2,.L0f0ebb44
/*  f0ebb30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebb34:	440a8000 */ 	mfc1	$t2,$f16
/*  f0ebb38:	3c018000 */ 	lui	$at,0x8000
/*  f0ebb3c:	10000007 */ 	beqz	$zero,.L0f0ebb5c
/*  f0ebb40:	01415025 */ 	or	$t2,$t2,$at
.L0f0ebb44:
/*  f0ebb44:	10000005 */ 	beqz	$zero,.L0f0ebb5c
/*  f0ebb48:	240affff */ 	addiu	$t2,$zero,-1
/*  f0ebb4c:	440a8000 */ 	mfc1	$t2,$f16
.L0f0ebb50:
/*  f0ebb50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebb54:	0540fffb */ 	bltz	$t2,.L0f0ebb44
/*  f0ebb58:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ebb5c:
/*  f0ebb5c:	afaa0054 */ 	sw	$t2,0x54($sp)
/*  f0ebb60:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0ebb64:	44c9f800 */ 	ctc1	$t1,$31
/*  f0ebb68:	44802000 */ 	mtc1	$zero,$f4
/*  f0ebb6c:	c4720040 */ 	lwc1	$f18,0x40($v1)
/*  f0ebb70:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0ebb74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebb78:	45020009 */ 	bc1fl	.L0f0ebba0
/*  f0ebb7c:	9068003d */ 	lbu	$t0,0x3d($v1)
/*  f0ebb80:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0ebb84:	3c077f1b */ 	lui	$a3,%hi(var7f1b1fd0)
/*  f0ebb88:	01920019 */ 	multu	$t4,$s2
/*  f0ebb8c:	0000c812 */ 	mflo	$t9
/*  f0ebb90:	00f93821 */ 	addu	$a3,$a3,$t9
/*  f0ebb94:	10000010 */ 	beqz	$zero,.L0f0ebbd8
/*  f0ebb98:	8ce71fd0 */ 	lw	$a3,%lo(var7f1b1fd0)($a3)
/*  f0ebb9c:	9068003d */ 	lbu	$t0,0x3d($v1)
.L0f0ebba0:
/*  f0ebba0:	906e003c */ 	lbu	$t6,0x3c($v1)
/*  f0ebba4:	3c0b7f1b */ 	lui	$t3,%hi(var7f1b1fb0)
/*  f0ebba8:	01120019 */ 	multu	$t0,$s2
/*  f0ebbac:	256b1fb0 */ 	addiu	$t3,$t3,%lo(var7f1b1fb0)
/*  f0ebbb0:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ebbb4:	00007812 */ 	mflo	$t7
/*  f0ebbb8:	01ebc021 */ 	addu	$t8,$t7,$t3
/*  f0ebbbc:	8f040020 */ 	lw	$a0,0x20($t8)
/*  f0ebbc0:	01d20019 */ 	multu	$t6,$s2
/*  f0ebbc4:	00006812 */ 	mflo	$t5
/*  f0ebbc8:	01ab4821 */ 	addu	$t1,$t5,$t3
/*  f0ebbcc:	0fc01a40 */ 	jal	func0f006900
/*  f0ebbd0:	8d250020 */ 	lw	$a1,0x20($t1)
/*  f0ebbd4:	00403825 */ 	or	$a3,$v0,$zero
.L0f0ebbd8:
/*  f0ebbd8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ebbdc:	320500ff */ 	andi	$a1,$s0,0xff
/*  f0ebbe0:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ebbe4:	0fc01a40 */ 	jal	func0f006900
/*  f0ebbe8:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0ebbec:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ebbf0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ebbf4:	0fc01a40 */ 	jal	func0f006900
/*  f0ebbf8:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0ebbfc:	00408025 */ 	or	$s0,$v0,$zero
.L0f0ebc00:
/*  f0ebc00:	8e2a0010 */ 	lw	$t2,0x10($s1)
/*  f0ebc04:	3c047f1b */ 	lui	$a0,%hi(var7f1b22a0)
/*  f0ebc08:	3c057f1b */ 	lui	$a1,%hi(var7f1b2138)
/*  f0ebc0c:	914c003c */ 	lbu	$t4,0x3c($t2)
/*  f0ebc10:	01920019 */ 	multu	$t4,$s2
/*  f0ebc14:	00001012 */ 	mflo	$v0
/*  f0ebc18:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ebc1c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0ebc20:	8ca52138 */ 	lw	$a1,%lo(var7f1b2138)($a1)
/*  f0ebc24:	0fc54f8e */ 	jal	func0f153e38
/*  f0ebc28:	8c8422a0 */ 	lw	$a0,%lo(var7f1b22a0)($a0)
/*  f0ebc2c:	1000000c */ 	beqz	$zero,.L0f0ebc60
/*  f0ebc30:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ebc34:
/*  f0ebc34:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0ebc38:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0ebc3c:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0ebc40:	9328003c */ 	lbu	$t0,0x3c($t9)
/*  f0ebc44:	01120019 */ 	multu	$t0,$s2
/*  f0ebc48:	00001012 */ 	mflo	$v0
/*  f0ebc4c:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ebc50:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0ebc54:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0ebc58:	0fc54f8e */ 	jal	func0f153e38
/*  f0ebc5c:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
.L0f0ebc60:
/*  f0ebc60:	0fc54d8a */ 	jal	func0f153628
/*  f0ebc64:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f0ebc68:	3c0f8008 */ 	lui	$t7,%hi(var8007fb10)
/*  f0ebc6c:	3c188008 */ 	lui	$t8,%hi(var8007fb0c)
/*  f0ebc70:	8f18fb0c */ 	lw	$t8,%lo(var8007fb0c)($t8)
/*  f0ebc74:	8deffb10 */ 	lw	$t7,%lo(var8007fb10)($t7)
/*  f0ebc78:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ebc7c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0ebc80:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ebc84:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0ebc88:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ebc8c:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0ebc90:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0ebc94:	862d0006 */ 	lh	$t5,0x6($s1)
/*  f0ebc98:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ebc9c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ebca0:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0ebca4:	8fa700a8 */ 	lw	$a3,0xa8($sp)
/*  f0ebca8:	0fc5580f */ 	jal	func0f15603c
/*  f0ebcac:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f0ebcb0:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0ebcb4:	8e2b0008 */ 	lw	$t3,0x8($s1)
/*  f0ebcb8:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f0ebcbc:	3c057f1b */ 	lui	$a1,%hi(var7f1adfbc)
/*  f0ebcc0:	8d690004 */ 	lw	$t1,0x4($t3)
/*  f0ebcc4:	312a2000 */ 	andi	$t2,$t1,0x2000
/*  f0ebcc8:	15400077 */ 	bnez	$t2,.L0f0ebea8
/*  f0ebccc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebcd0:	0c004c4c */ 	jal	strcpy
/*  f0ebcd4:	24a5dfbc */ 	addiu	$a1,$a1,%lo(var7f1adfbc)
/*  f0ebcd8:	3c057f1b */ 	lui	$a1,%hi(var7f1adfc0)
/*  f0ebcdc:	24a5dfc0 */ 	addiu	$a1,$a1,%lo(var7f1adfc0)
/*  f0ebce0:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f0ebce4:	0c004dad */ 	jal	sprintf
/*  f0ebce8:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f0ebcec:	8e2c0008 */ 	lw	$t4,0x8($s1)
/*  f0ebcf0:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0ebcf4:	27af0098 */ 	addiu	$t7,$sp,0x98
/*  f0ebcf8:	8d990010 */ 	lw	$t9,0x10($t4)
/*  f0ebcfc:	1320000a */ 	beqz	$t9,.L0f0ebd28
/*  f0ebd00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebd04:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0ebd08:	afaf0078 */ 	sw	$t7,0x78($sp)
/*  f0ebd0c:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0ebd10:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0ebd14:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0ebd18:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0ebd1c:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0ebd20:	0320f809 */ 	jalr	$t9
/*  f0ebd24:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ebd28:
/*  f0ebd28:	3c188008 */ 	lui	$t8,%hi(var8007fb0c)
/*  f0ebd2c:	8f18fb0c */ 	lw	$t8,%lo(var8007fb0c)($t8)
/*  f0ebd30:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0ebd34:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0ebd38:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0ebd3c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0ebd40:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f0ebd44:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ebd48:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ebd4c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ebd50:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f0ebd54:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0ebd58:	8fa90088 */ 	lw	$t1,0x88($sp)
/*  f0ebd5c:	44804000 */ 	mtc1	$zero,$f8
/*  f0ebd60:	01cd5821 */ 	addu	$t3,$t6,$t5
/*  f0ebd64:	01695023 */ 	subu	$t2,$t3,$t1
/*  f0ebd68:	254cfff9 */ 	addiu	$t4,$t2,-7
/*  f0ebd6c:	afac0094 */ 	sw	$t4,0x94($sp)
/*  f0ebd70:	86280002 */ 	lh	$t0,0x2($s1)
/*  f0ebd74:	250f0002 */ 	addiu	$t7,$t0,0x2
/*  f0ebd78:	afaf0090 */ 	sw	$t7,0x90($sp)
/*  f0ebd7c:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0ebd80:	c4660040 */ 	lwc1	$f6,0x40($v1)
/*  f0ebd84:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0ebd88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebd8c:	45020009 */ 	bc1fl	.L0f0ebdb4
/*  f0ebd90:	906e003d */ 	lbu	$t6,0x3d($v1)
/*  f0ebd94:	9079003c */ 	lbu	$t9,0x3c($v1)
/*  f0ebd98:	3c107f1b */ 	lui	$s0,%hi(var7f1b1fc8)
/*  f0ebd9c:	03320019 */ 	multu	$t9,$s2
/*  f0ebda0:	0000c012 */ 	mflo	$t8
/*  f0ebda4:	02188021 */ 	addu	$s0,$s0,$t8
/*  f0ebda8:	10000011 */ 	beqz	$zero,.L0f0ebdf0
/*  f0ebdac:	8e101fc8 */ 	lw	$s0,%lo(var7f1b1fc8)($s0)
/*  f0ebdb0:	906e003d */ 	lbu	$t6,0x3d($v1)
.L0f0ebdb4:
/*  f0ebdb4:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0ebdb8:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0ebdbc:	01d20019 */ 	multu	$t6,$s2
/*  f0ebdc0:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0ebdc4:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ebdc8:	00006812 */ 	mflo	$t5
/*  f0ebdcc:	004d5821 */ 	addu	$t3,$v0,$t5
/*  f0ebdd0:	8d640018 */ 	lw	$a0,0x18($t3)
/*  f0ebdd4:	01320019 */ 	multu	$t1,$s2
/*  f0ebdd8:	00005012 */ 	mflo	$t2
/*  f0ebddc:	004a6021 */ 	addu	$t4,$v0,$t2
/*  f0ebde0:	0fc01a40 */ 	jal	func0f006900
/*  f0ebde4:	8d850018 */ 	lw	$a1,0x18($t4)
/*  f0ebde8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0ebdec:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0ebdf0:
/*  f0ebdf0:	8c68000c */ 	lw	$t0,0xc($v1)
/*  f0ebdf4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ebdf8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ebdfc:	51000009 */ 	beqzl	$t0,.L0f0ebe24
/*  f0ebe00:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0ebe04:	0fc01a40 */ 	jal	func0f006900
/*  f0ebe08:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ebe0c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ebe10:	00417824 */ 	and	$t7,$v0,$at
/*  f0ebe14:	321900ff */ 	andi	$t9,$s0,0xff
/*  f0ebe18:	01f98025 */ 	or	$s0,$t7,$t9
/*  f0ebe1c:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0ebe20:	9078003c */ 	lbu	$t8,0x3c($v1)
.L0f0ebe24:
/*  f0ebe24:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0ebe28:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0ebe2c:	03120019 */ 	multu	$t8,$s2
/*  f0ebe30:	00001012 */ 	mflo	$v0
/*  f0ebe34:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ebe38:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0ebe3c:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0ebe40:	0fc54f8e */ 	jal	func0f153e38
/*  f0ebe44:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
/*  f0ebe48:	3c098008 */ 	lui	$t1,%hi(var8007fb10)
/*  f0ebe4c:	3c0a8008 */ 	lui	$t2,%hi(var8007fb0c)
/*  f0ebe50:	8d4afb0c */ 	lw	$t2,%lo(var8007fb0c)($t2)
/*  f0ebe54:	8d29fb10 */ 	lw	$t1,%lo(var8007fb10)($t1)
/*  f0ebe58:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ebe5c:	320d00ff */ 	andi	$t5,$s0,0xff
/*  f0ebe60:	000d5842 */ 	srl	$t3,$t5,0x1
/*  f0ebe64:	02017024 */ 	and	$t6,$s0,$at
/*  f0ebe68:	01cb8025 */ 	or	$s0,$t6,$t3
/*  f0ebe6c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ebe70:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0ebe74:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0ebe78:	862c0004 */ 	lh	$t4,0x4($s1)
/*  f0ebe7c:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f0ebe80:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0ebe84:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0ebe88:	86280006 */ 	lh	$t0,0x6($s1)
/*  f0ebe8c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ebe90:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ebe94:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0ebe98:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f0ebe9c:	0fc5580f */ 	jal	func0f15603c
/*  f0ebea0:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0ebea4:	afa200b0 */ 	sw	$v0,0xb0($sp)
.L0f0ebea8:
/*  f0ebea8:	0fc54de0 */ 	jal	func0f153780
/*  f0ebeac:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f0ebeb0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0ebeb4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ebeb8:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0ebebc:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0ebec0:	03e00008 */ 	jr	$ra
/*  f0ebec4:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

GLOBAL_ASM(
glabel func0f0ebec8
/*  f0ebec8:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0ebecc:	30ee0002 */ 	andi	$t6,$a3,0x2
/*  f0ebed0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ebed4:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f0ebed8:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f0ebedc:	11c000cb */ 	beqz	$t6,.L0f0ec20c
/*  f0ebee0:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0ebee4:	30ef0004 */ 	andi	$t7,$a3,0x4
/*  f0ebee8:	11e000c3 */ 	beqz	$t7,.L0f0ec1f8
/*  f0ebeec:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f0ebef0:	8c820010 */ 	lw	$v0,0x10($a0)
/*  f0ebef4:	0080c025 */ 	or	$t8,$a0,$zero
/*  f0ebef8:	03002825 */ 	or	$a1,$t8,$zero
/*  f0ebefc:	10400006 */ 	beqz	$v0,.L0f0ebf18
/*  f0ebf00:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ebf04:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0ebf08:	0040f809 */ 	jalr	$v0
/*  f0ebf0c:	27a60034 */ 	addiu	$a2,$sp,0x34
/*  f0ebf10:	10000001 */ 	beqz	$zero,.L0f0ebf18
/*  f0ebf14:	87a40036 */ 	lh	$a0,0x36($sp)
.L0f0ebf18:
/*  f0ebf18:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f0ebf1c:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f0ebf20:	8fa60058 */ 	lw	$a2,0x58($sp)
/*  f0ebf24:	8f250004 */ 	lw	$a1,0x4($t9)
/*  f0ebf28:	30a80800 */ 	andi	$t0,$a1,0x800
/*  f0ebf2c:	15000017 */ 	bnez	$t0,.L0f0ebf8c
/*  f0ebf30:	01002825 */ 	or	$a1,$t0,$zero
/*  f0ebf34:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f0ebf38:	3c0b800a */ 	lui	$t3,%hi(g_MenuStack+0x82c)
/*  f0ebf3c:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f0ebf40:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0ebf44:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0ebf48:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0ebf4c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0ebf50:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0ebf54:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0ebf58:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0ebf5c:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0ebf60:	856be82c */ 	lh	$t3,%lo(g_MenuStack+0x82c)($t3)
/*  f0ebf64:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0ebf68:	55600009 */ 	bnezl	$t3,.L0f0ebf90
/*  f0ebf6c:	84ce0000 */ 	lh	$t6,0x0($a2)
/*  f0ebf70:	44819000 */ 	mtc1	$at,$f18
/*  f0ebf74:	818d0000 */ 	lb	$t5,0x0($t4)
/*  f0ebf78:	3c01447a */ 	lui	$at,0x447a
/*  f0ebf7c:	44818000 */ 	mtc1	$at,$f16
/*  f0ebf80:	8fa60058 */ 	lw	$a2,0x58($sp)
/*  f0ebf84:	1000002b */ 	beqz	$zero,.L0f0ec034
/*  f0ebf88:	01a42021 */ 	addu	$a0,$t5,$a0
.L0f0ebf8c:
/*  f0ebf8c:	84ce0000 */ 	lh	$t6,0x0($a2)
.L0f0ebf90:
/*  f0ebf90:	3c01447a */ 	lui	$at,0x447a
/*  f0ebf94:	44818000 */ 	mtc1	$at,$f16
/*  f0ebf98:	448e2000 */ 	mtc1	$t6,$f4
/*  f0ebf9c:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f0ebfa0:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0ebfa4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ebfa8:	8df8000c */ 	lw	$t8,0xc($t7)
/*  f0ebfac:	44819000 */ 	mtc1	$at,$f18
/*  f0ebfb0:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0ebfb4:	44984000 */ 	mtc1	$t8,$f8
/*  f0ebfb8:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0ebfbc:	46103003 */ 	div.s	$f0,$f6,$f16
/*  f0ebfc0:	8d299fc0 */ 	lw	$t1,%lo(g_Vars)($t1)
/*  f0ebfc4:	83280008 */ 	lb	$t0,0x8($t9)
/*  f0ebfc8:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f0ebfcc:	01090019 */ 	multu	$t0,$t1
/*  f0ebfd0:	00005012 */ 	mflo	$t2
/*  f0ebfd4:	448a2000 */ 	mtc1	$t2,$f4
/*  f0ebfd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebfdc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ebfe0:	46120282 */ 	mul.s	$f10,$f0,$f18
/*  f0ebfe4:	460c5003 */ 	div.s	$f0,$f10,$f12
/*  f0ebfe8:	46003000 */ 	add.s	$f0,$f6,$f0
/*  f0ebfec:	46006202 */ 	mul.s	$f8,$f12,$f0
/*  f0ebff0:	46124003 */ 	div.s	$f0,$f8,$f18
/*  f0ebff4:	4600028d */ 	trunc.w.s	$f10,$f0
/*  f0ebff8:	44025000 */ 	mfc1	$v0,$f10
/*  f0ebffc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec000:	44822000 */ 	mtc1	$v0,$f4
/*  f0ec004:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ec008:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ec00c:	46060001 */ 	sub.s	$f0,$f0,$f6
/*  f0ec010:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f0ec014:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ec018:	440d5000 */ 	mfc1	$t5,$f10
/*  f0ec01c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec020:	a4cd0000 */ 	sh	$t5,0x0($a2)
/*  f0ec024:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0ec028:	8dc50004 */ 	lw	$a1,0x4($t6)
/*  f0ec02c:	30af0800 */ 	andi	$t7,$a1,0x800
/*  f0ec030:	01e02825 */ 	or	$a1,$t7,$zero
.L0f0ec034:
/*  f0ec034:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f0ec038:	3c014220 */ 	lui	$at,0x4220
/*  f0ec03c:	83020004 */ 	lb	$v0,0x4($t8)
/*  f0ec040:	04430007 */ 	bgezl	$v0,.L0f0ec060
/*  f0ec044:	44823000 */ 	mtc1	$v0,$f6
/*  f0ec048:	44822000 */ 	mtc1	$v0,$f4
/*  f0ec04c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec050:	468023a0 */ 	cvt.s.w	$f14,$f4
/*  f0ec054:	10000005 */ 	beqz	$zero,.L0f0ec06c
/*  f0ec058:	46007087 */ 	neg.s	$f2,$f14
/*  f0ec05c:	44823000 */ 	mtc1	$v0,$f6
.L0f0ec060:
/*  f0ec060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec064:	468033a0 */ 	cvt.s.w	$f14,$f6
/*  f0ec068:	46007086 */ 	mov.s	$f2,$f14
.L0f0ec06c:
/*  f0ec06c:	54a00019 */ 	bnezl	$a1,.L0f0ec0d4
/*  f0ec070:	84cc0000 */ 	lh	$t4,0x0($a2)
/*  f0ec074:	44814000 */ 	mtc1	$at,$f8
/*  f0ec078:	3c198007 */ 	lui	$t9,%hi(g_MpPlayerNum)
/*  f0ec07c:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0ec080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec084:	45020013 */ 	bc1fl	.L0f0ec0d4
/*  f0ec088:	84cc0000 */ 	lh	$t4,0x0($a2)
/*  f0ec08c:	8f391448 */ 	lw	$t9,%lo(g_MpPlayerNum)($t9)
/*  f0ec090:	3c09800a */ 	lui	$t1,%hi(g_MenuStack+0x82c)
/*  f0ec094:	8faa0050 */ 	lw	$t2,0x50($sp)
/*  f0ec098:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f0ec09c:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0ec0a0:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ec0a4:	01194021 */ 	addu	$t0,$t0,$t9
/*  f0ec0a8:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f0ec0ac:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0ec0b0:	00084100 */ 	sll	$t0,$t0,0x4
/*  f0ec0b4:	01284821 */ 	addu	$t1,$t1,$t0
/*  f0ec0b8:	8529e82c */ 	lh	$t1,%lo(g_MenuStack+0x82c)($t1)
/*  f0ec0bc:	11200034 */ 	beqz	$t1,.L0f0ec190
/*  f0ec0c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec0c4:	814b0000 */ 	lb	$t3,0x0($t2)
/*  f0ec0c8:	10000031 */ 	beqz	$zero,.L0f0ec190
/*  f0ec0cc:	01642021 */ 	addu	$a0,$t3,$a0
/*  f0ec0d0:	84cc0000 */ 	lh	$t4,0x0($a2)
.L0f0ec0d4:
/*  f0ec0d4:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f0ec0d8:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0ec0dc:	448c5000 */ 	mtc1	$t4,$f10
/*  f0ec0e0:	8dae000c */ 	lw	$t6,0xc($t5)
/*  f0ec0e4:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0ec0e8:	448e3000 */ 	mtc1	$t6,$f6
/*  f0ec0ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec0f0:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f0ec0f4:	46102003 */ 	div.s	$f0,$f4,$f16
/*  f0ec0f8:	46120202 */ 	mul.s	$f8,$f0,$f18
/*  f0ec0fc:	04410003 */ 	bgez	$v0,.L0f0ec10c
/*  f0ec100:	460c4003 */ 	div.s	$f0,$f8,$f12
/*  f0ec104:	10000002 */ 	beqz	$zero,.L0f0ec110
/*  f0ec108:	46007087 */ 	neg.s	$f2,$f14
.L0f0ec10c:
/*  f0ec10c:	46007086 */ 	mov.s	$f2,$f14
.L0f0ec110:
/*  f0ec110:	44817000 */ 	mtc1	$at,$f14
/*  f0ec114:	3c013d80 */ 	lui	$at,0x3d80
/*  f0ec118:	4602703c */ 	c.lt.s	$f14,$f2
/*  f0ec11c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec120:	4500000d */ 	bc1f	.L0f0ec158
/*  f0ec124:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec128:	460e1281 */ 	sub.s	$f10,$f2,$f14
/*  f0ec12c:	44812000 */ 	mtc1	$at,$f4
/*  f0ec130:	3c01800a */ 	lui	$at,0x800a
/*  f0ec134:	c4269fc4 */ 	lwc1	$f6,-0x603c($at)
/*  f0ec138:	46045082 */ 	mul.s	$f2,$f10,$f4
/*  f0ec13c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec140:	46061082 */ 	mul.s	$f2,$f2,$f6
/*  f0ec144:	04410003 */ 	bgez	$v0,.L0f0ec154
/*  f0ec148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec14c:	10000002 */ 	beqz	$zero,.L0f0ec158
/*  f0ec150:	46020001 */ 	sub.s	$f0,$f0,$f2
.L0f0ec154:
/*  f0ec154:	46020000 */ 	add.s	$f0,$f0,$f2
.L0f0ec158:
/*  f0ec158:	46006202 */ 	mul.s	$f8,$f12,$f0
/*  f0ec15c:	46124003 */ 	div.s	$f0,$f8,$f18
/*  f0ec160:	4600028d */ 	trunc.w.s	$f10,$f0
/*  f0ec164:	44025000 */ 	mfc1	$v0,$f10
/*  f0ec168:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec16c:	44822000 */ 	mtc1	$v0,$f4
/*  f0ec170:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ec174:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ec178:	46060001 */ 	sub.s	$f0,$f0,$f6
/*  f0ec17c:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f0ec180:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ec184:	44195000 */ 	mfc1	$t9,$f10
/*  f0ec188:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec18c:	a4d90000 */ 	sh	$t9,0x0($a2)
.L0f0ec190:
/*  f0ec190:	04810002 */ 	bgez	$a0,.L0f0ec19c
/*  f0ec194:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0ec198:	00002025 */ 	or	$a0,$zero,$zero
.L0f0ec19c:
/*  f0ec19c:	8d02000c */ 	lw	$v0,0xc($t0)
/*  f0ec1a0:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f0ec1a4:	27a60034 */ 	addiu	$a2,$sp,0x34
/*  f0ec1a8:	0044082a */ 	slt	$at,$v0,$a0
/*  f0ec1ac:	50200003 */ 	beqzl	$at,.L0f0ec1bc
/*  f0ec1b0:	a1200000 */ 	sb	$zero,0x0($t1)
/*  f0ec1b4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ec1b8:	a1200000 */ 	sb	$zero,0x0($t1)
.L0f0ec1bc:
/*  f0ec1bc:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f0ec1c0:	afa40034 */ 	sw	$a0,0x34($sp)
/*  f0ec1c4:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0ec1c8:	8d420010 */ 	lw	$v0,0x10($t2)
/*  f0ec1cc:	50400004 */ 	beqzl	$v0,.L0f0ec1e0
/*  f0ec1d0:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f0ec1d4:	0040f809 */ 	jalr	$v0
/*  f0ec1d8:	01402825 */ 	or	$a1,$t2,$zero
/*  f0ec1dc:	8fab0050 */ 	lw	$t3,0x50($sp)
.L0f0ec1e0:
/*  f0ec1e0:	8fad004c */ 	lw	$t5,0x4c($sp)
/*  f0ec1e4:	916c0002 */ 	lbu	$t4,0x2($t3)
/*  f0ec1e8:	51800009 */ 	beqzl	$t4,.L0f0ec210
/*  f0ec1ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ec1f0:	10000006 */ 	beqz	$zero,.L0f0ec20c
/*  f0ec1f4:	ada0000c */ 	sw	$zero,0xc($t5)
.L0f0ec1f8:
/*  f0ec1f8:	91cf0002 */ 	lbu	$t7,0x2($t6)
/*  f0ec1fc:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f0ec200:	11e00002 */ 	beqz	$t7,.L0f0ec20c
/*  f0ec204:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0ec208:	af38000c */ 	sw	$t8,0xc($t9)
.L0f0ec20c:
/*  f0ec20c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ec210:
/*  f0ec210:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0ec214:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0ec218:	03e00008 */ 	jr	$ra
/*  f0ec21c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ec220
/*  f0ec220:	03e00008 */ 	jr	$ra
/*  f0ec224:	a4800000 */ 	sh	$zero,0x0($a0)
);

GLOBAL_ASM(
glabel func0f0ec228
/*  f0ec228:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f0ec22c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0ec230:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0ec234:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f0ec238:	8cae000c */ 	lw	$t6,0xc($a1)
/*  f0ec23c:	3c03ff00 */ 	lui	$v1,0xff00
/*  f0ec240:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0ec244:	11c00055 */ 	beqz	$t6,.L0f0ec39c
/*  f0ec248:	346300ff */ 	ori	$v1,$v1,0xff
/*  f0ec24c:	3c014220 */ 	lui	$at,0x4220
/*  f0ec250:	44816000 */ 	mtc1	$at,$f12
/*  f0ec254:	0fc01ac2 */ 	jal	func0f006b08
/*  f0ec258:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec25c:	3c01437f */ 	lui	$at,0x437f
/*  f0ec260:	44812000 */ 	mtc1	$at,$f4
/*  f0ec264:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0ec268:	3c014f00 */ 	lui	$at,0x4f00
/*  f0ec26c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0ec270:	444ff800 */ 	cfc1	$t7,$31
/*  f0ec274:	44d8f800 */ 	ctc1	$t8,$31
/*  f0ec278:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec27c:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0ec280:	4458f800 */ 	cfc1	$t8,$31
/*  f0ec284:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec288:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0ec28c:	53000013 */ 	beqzl	$t8,.L0f0ec2dc
/*  f0ec290:	44184000 */ 	mfc1	$t8,$f8
/*  f0ec294:	44814000 */ 	mtc1	$at,$f8
/*  f0ec298:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0ec29c:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0ec2a0:	44d8f800 */ 	ctc1	$t8,$31
/*  f0ec2a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec2a8:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0ec2ac:	4458f800 */ 	cfc1	$t8,$31
/*  f0ec2b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec2b4:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0ec2b8:	17000005 */ 	bnez	$t8,.L0f0ec2d0
/*  f0ec2bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec2c0:	44184000 */ 	mfc1	$t8,$f8
/*  f0ec2c4:	3c018000 */ 	lui	$at,0x8000
/*  f0ec2c8:	10000007 */ 	beqz	$zero,.L0f0ec2e8
/*  f0ec2cc:	0301c025 */ 	or	$t8,$t8,$at
.L0f0ec2d0:
/*  f0ec2d0:	10000005 */ 	beqz	$zero,.L0f0ec2e8
/*  f0ec2d4:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0ec2d8:	44184000 */ 	mfc1	$t8,$f8
.L0f0ec2dc:
/*  f0ec2dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec2e0:	0700fffb */ 	bltz	$t8,.L0f0ec2d0
/*  f0ec2e4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ec2e8:
/*  f0ec2e8:	afb80064 */ 	sw	$t8,0x64($sp)
/*  f0ec2ec:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f0ec2f0:	44cff800 */ 	ctc1	$t7,$31
/*  f0ec2f4:	44808000 */ 	mtc1	$zero,$f16
/*  f0ec2f8:	c44a0040 */ 	lwc1	$f10,0x40($v0)
/*  f0ec2fc:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0ec300:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec304:	4502000b */ 	bc1fl	.L0f0ec334
/*  f0ec308:	904b003d */ 	lbu	$t3,0x3d($v0)
/*  f0ec30c:	9059003c */ 	lbu	$t9,0x3c($v0)
/*  f0ec310:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0ec314:	3c037f1b */ 	lui	$v1,%hi(var7f1b1fb0)
/*  f0ec318:	03280019 */ 	multu	$t9,$t0
/*  f0ec31c:	24631fb0 */ 	addiu	$v1,$v1,%lo(var7f1b1fb0)
/*  f0ec320:	00004812 */ 	mflo	$t1
/*  f0ec324:	00695021 */ 	addu	$t2,$v1,$t1
/*  f0ec328:	10000011 */ 	beqz	$zero,.L0f0ec370
/*  f0ec32c:	8d470020 */ 	lw	$a3,0x20($t2)
/*  f0ec330:	904b003d */ 	lbu	$t3,0x3d($v0)
.L0f0ec334:
/*  f0ec334:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0ec338:	904e003c */ 	lbu	$t6,0x3c($v0)
/*  f0ec33c:	01680019 */ 	multu	$t3,$t0
/*  f0ec340:	3c037f1b */ 	lui	$v1,%hi(var7f1b1fb0)
/*  f0ec344:	24631fb0 */ 	addiu	$v1,$v1,%lo(var7f1b1fb0)
/*  f0ec348:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0ec34c:	00006012 */ 	mflo	$t4
/*  f0ec350:	006c6821 */ 	addu	$t5,$v1,$t4
/*  f0ec354:	8da40020 */ 	lw	$a0,0x20($t5)
/*  f0ec358:	01c80019 */ 	multu	$t6,$t0
/*  f0ec35c:	00007812 */ 	mflo	$t7
/*  f0ec360:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f0ec364:	0fc01a40 */ 	jal	func0f006900
/*  f0ec368:	8f050020 */ 	lw	$a1,0x20($t8)
/*  f0ec36c:	00403825 */ 	or	$a3,$v0,$zero
.L0f0ec370:
/*  f0ec370:	3c04ff00 */ 	lui	$a0,0xff00
/*  f0ec374:	348400ff */ 	ori	$a0,$a0,0xff
/*  f0ec378:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f0ec37c:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ec380:	0fc01a40 */ 	jal	func0f006900
/*  f0ec384:	afa70068 */ 	sw	$a3,0x68($sp)
/*  f0ec388:	8fa50068 */ 	lw	$a1,0x68($sp)
/*  f0ec38c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ec390:	0fc01a40 */ 	jal	func0f006900
/*  f0ec394:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f0ec398:	00401825 */ 	or	$v1,$v0,$zero
.L0f0ec39c:
/*  f0ec39c:	86090006 */ 	lh	$t1,0x6($s0)
/*  f0ec3a0:	86190002 */ 	lh	$t9,0x2($s0)
/*  f0ec3a4:	86050000 */ 	lh	$a1,0x0($s0)
/*  f0ec3a8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0ec3ac:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0ec3b0:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0ec3b4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ec3b8:	afa3006c */ 	sw	$v1,0x6c($sp)
/*  f0ec3bc:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0ec3c0:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0ec3c4:	05210003 */ 	bgez	$t1,.L0f0ec3d4
/*  f0ec3c8:	00095043 */ 	sra	$t2,$t1,0x1
/*  f0ec3cc:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0ec3d0:	00015043 */ 	sra	$t2,$at,0x1
.L0f0ec3d4:
/*  f0ec3d4:	24070008 */ 	addiu	$a3,$zero,0x8
/*  f0ec3d8:	0fc38bf9 */ 	jal	func0f0e2fe4
/*  f0ec3dc:	032a3021 */ 	addu	$a2,$t9,$t2
/*  f0ec3e0:	86180006 */ 	lh	$t8,0x6($s0)
/*  f0ec3e4:	860d0000 */ 	lh	$t5,0x0($s0)
/*  f0ec3e8:	860e0004 */ 	lh	$t6,0x4($s0)
/*  f0ec3ec:	860f0002 */ 	lh	$t7,0x2($s0)
/*  f0ec3f0:	8fa3006c */ 	lw	$v1,0x6c($sp)
/*  f0ec3f4:	24190003 */ 	addiu	$t9,$zero,0x3
/*  f0ec3f8:	240affff */ 	addiu	$t2,$zero,-1
/*  f0ec3fc:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0ec400:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ec404:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ec408:	24070008 */ 	addiu	$a3,$zero,0x8
/*  f0ec40c:	01ae2821 */ 	addu	$a1,$t5,$t6
/*  f0ec410:	07010003 */ 	bgez	$t8,.L0f0ec420
/*  f0ec414:	00184843 */ 	sra	$t1,$t8,0x1
/*  f0ec418:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0ec41c:	00014843 */ 	sra	$t1,$at,0x1
.L0f0ec420:
/*  f0ec420:	01e93021 */ 	addu	$a2,$t7,$t1
/*  f0ec424:	0fc38bf9 */ 	jal	func0f0e2fe4
/*  f0ec428:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0ec42c:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f0ec430:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f0ec434:	2401007b */ 	addiu	$at,$zero,0x7b
/*  f0ec438:	8ca30008 */ 	lw	$v1,0x8($a1)
/*  f0ec43c:	5461001a */ 	bnel	$v1,$at,.L0f0ec4a8
/*  f0ec440:	2401007c */ 	addiu	$at,$zero,0x7c
/*  f0ec444:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f0ec448:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0ec44c:	50400016 */ 	beqzl	$v0,.L0f0ec4a8
/*  f0ec450:	2401007c */ 	addiu	$at,$zero,0x7c
/*  f0ec454:	0040f809 */ 	jalr	$v0
/*  f0ec458:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0ec45c:	860c0004 */ 	lh	$t4,0x4($s0)
/*  f0ec460:	860b0000 */ 	lh	$t3,0x0($s0)
/*  f0ec464:	86070002 */ 	lh	$a3,0x2($s0)
/*  f0ec468:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0ec46c:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0ec470:	05810003 */ 	bgez	$t4,.L0f0ec480
/*  f0ec474:	000c6843 */ 	sra	$t5,$t4,0x1
/*  f0ec478:	25810001 */ 	addiu	$at,$t4,0x1
/*  f0ec47c:	00016843 */ 	sra	$t5,$at,0x1
.L0f0ec480:
/*  f0ec480:	016d1821 */ 	addu	$v1,$t3,$t5
/*  f0ec484:	246e0020 */ 	addiu	$t6,$v1,0x20
/*  f0ec488:	24f80040 */ 	addiu	$t8,$a3,0x40
/*  f0ec48c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0ec490:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ec494:	0fc53c1f */ 	jal	func0f14f07c
/*  f0ec498:	2466ffe0 */ 	addiu	$a2,$v1,-32
/*  f0ec49c:	1000000c */ 	beqz	$zero,.L0f0ec4d0
/*  f0ec4a0:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f0ec4a4:	2401007c */ 	addiu	$at,$zero,0x7c
.L0f0ec4a8:
/*  f0ec4a8:	10610003 */ 	beq	$v1,$at,.L0f0ec4b8
/*  f0ec4ac:	2401007d */ 	addiu	$at,$zero,0x7d
/*  f0ec4b0:	54610008 */ 	bnel	$v1,$at,.L0f0ec4d4
/*  f0ec4b4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0ec4b8:
/*  f0ec4b8:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f0ec4bc:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0ec4c0:	50400004 */ 	beqzl	$v0,.L0f0ec4d4
/*  f0ec4c4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ec4c8:	0040f809 */ 	jalr	$v0
/*  f0ec4cc:	27a60040 */ 	addiu	$a2,$sp,0x40
.L0f0ec4d0:
/*  f0ec4d0:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0ec4d4:
/*  f0ec4d4:	8fa20070 */ 	lw	$v0,0x70($sp)
/*  f0ec4d8:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0ec4dc:	03e00008 */ 	jr	$ra
/*  f0ec4e0:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func0f0ec4e4
/*  f0ec4e4:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f0ec4e8:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0ec4ec:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0ec4f0:	30ce0002 */ 	andi	$t6,$a2,0x2
/*  f0ec4f4:	00809825 */ 	or	$s3,$a0,$zero
/*  f0ec4f8:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f0ec4fc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0ec500:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0ec504:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0ec508:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0ec50c:	15c00005 */ 	bnez	$t6,.L0f0ec524
/*  f0ec510:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ec514:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f0ec518:	000fc140 */ 	sll	$t8,$t7,0x5
/*  f0ec51c:	07030042 */ 	bgezl	$t8,.L0f0ec628
/*  f0ec520:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0ec524:
/*  f0ec524:	8e790010 */ 	lw	$t9,0x10($s3)
/*  f0ec528:	5320003f */ 	beqzl	$t9,.L0f0ec628
/*  f0ec52c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ec530:	82a80000 */ 	lb	$t0,0x0($s5)
/*  f0ec534:	3c048007 */ 	lui	$a0,%hi(g_MpPlayerNum)
/*  f0ec538:	51000034 */ 	beqzl	$t0,.L0f0ec60c
/*  f0ec53c:	8e620010 */ 	lw	$v0,0x10($s3)
/*  f0ec540:	0fc62ff6 */ 	jal	mpIsPlayerLockedOut
/*  f0ec544:	8c841448 */ 	lw	$a0,%lo(g_MpPlayerNum)($a0)
/*  f0ec548:	10400005 */ 	beqz	$v0,.L0f0ec560
/*  f0ec54c:	27b40048 */ 	addiu	$s4,$sp,0x48
/*  f0ec550:	8e690004 */ 	lw	$t1,0x4($s3)
/*  f0ec554:	00095380 */ 	sll	$t2,$t1,0xe
/*  f0ec558:	0542002c */ 	bltzl	$t2,.L0f0ec60c
/*  f0ec55c:	8e620010 */ 	lw	$v0,0x10($s3)
.L0f0ec560:
/*  f0ec560:	8e790010 */ 	lw	$t9,0x10($s3)
/*  f0ec564:	00008825 */ 	or	$s1,$zero,$zero
/*  f0ec568:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ec56c:	02602825 */ 	or	$a1,$s3,$zero
/*  f0ec570:	0320f809 */ 	jalr	$t9
/*  f0ec574:	02803025 */ 	or	$a2,$s4,$zero
/*  f0ec578:	8e790010 */ 	lw	$t9,0x10($s3)
/*  f0ec57c:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f0ec580:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0ec584:	02602825 */ 	or	$a1,$s3,$zero
/*  f0ec588:	0320f809 */ 	jalr	$t9
/*  f0ec58c:	02803025 */ 	or	$a2,$s4,$zero
/*  f0ec590:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0ec594:	82ab0000 */ 	lb	$t3,0x0($s5)
.L0f0ec598:
/*  f0ec598:	01708021 */ 	addu	$s0,$t3,$s0
/*  f0ec59c:	0212082a */ 	slt	$at,$s0,$s2
/*  f0ec5a0:	14200002 */ 	bnez	$at,.L0f0ec5ac
/*  f0ec5a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec5a8:	00008025 */ 	or	$s0,$zero,$zero
.L0f0ec5ac:
/*  f0ec5ac:	06030003 */ 	bgezl	$s0,.L0f0ec5bc
/*  f0ec5b0:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f0ec5b4:	2650ffff */ 	addiu	$s0,$s2,-1
/*  f0ec5b8:	afb00048 */ 	sw	$s0,0x48($sp)
.L0f0ec5bc:
/*  f0ec5bc:	8e790010 */ 	lw	$t9,0x10($s3)
/*  f0ec5c0:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f0ec5c4:	02602825 */ 	or	$a1,$s3,$zero
/*  f0ec5c8:	0320f809 */ 	jalr	$t9
/*  f0ec5cc:	02803025 */ 	or	$a2,$s4,$zero
/*  f0ec5d0:	14400002 */ 	bnez	$v0,.L0f0ec5dc
/*  f0ec5d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec5d8:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f0ec5dc:
/*  f0ec5dc:	5220ffee */ 	beqzl	$s1,.L0f0ec598
/*  f0ec5e0:	82ab0000 */ 	lb	$t3,0x0($s5)
/*  f0ec5e4:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f0ec5e8:	92ac0006 */ 	lbu	$t4,0x6($s5)
/*  f0ec5ec:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0ec5f0:	02602825 */ 	or	$a1,$s3,$zero
/*  f0ec5f4:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f0ec5f8:	8e790010 */ 	lw	$t9,0x10($s3)
/*  f0ec5fc:	02803025 */ 	or	$a2,$s4,$zero
/*  f0ec600:	0320f809 */ 	jalr	$t9
/*  f0ec604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec608:	8e620010 */ 	lw	$v0,0x10($s3)
.L0f0ec60c:
/*  f0ec60c:	27b40048 */ 	addiu	$s4,$sp,0x48
/*  f0ec610:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f0ec614:	10400003 */ 	beqz	$v0,.L0f0ec624
/*  f0ec618:	02602825 */ 	or	$a1,$s3,$zero
/*  f0ec61c:	0040f809 */ 	jalr	$v0
/*  f0ec620:	02803025 */ 	or	$a2,$s4,$zero
.L0f0ec624:
/*  f0ec624:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0ec628:
/*  f0ec628:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0ec62c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0ec630:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0ec634:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0ec638:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0ec63c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0ec640:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f0ec644:	03e00008 */ 	jr	$ra
/*  f0ec648:	24020001 */ 	addiu	$v0,$zero,0x1
);

GLOBAL_ASM(
glabel func0f0ec64c
/*  f0ec64c:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f0ec650:	3c0eff00 */ 	lui	$t6,0xff00
/*  f0ec654:	35ce2faf */ 	ori	$t6,$t6,0x2faf
/*  f0ec658:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ec65c:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0ec660:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0ec664:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f0ec668:	afa00060 */ 	sw	$zero,0x60($sp)
/*  f0ec66c:	afae005c */ 	sw	$t6,0x5c($sp)
/*  f0ec670:	8caf0008 */ 	lw	$t7,0x8($a1)
/*  f0ec674:	3c028008 */ 	lui	$v0,%hi(var8007fb0c)
/*  f0ec678:	3c038008 */ 	lui	$v1,%hi(var8007fb10)
/*  f0ec67c:	8df80004 */ 	lw	$t8,0x4($t7)
/*  f0ec680:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0ec684:	8c42fb0c */ 	lw	$v0,%lo(var8007fb0c)($v0)
/*  f0ec688:	33190200 */ 	andi	$t9,$t8,0x200
/*  f0ec68c:	13200005 */ 	beqz	$t9,.L0f0ec6a4
/*  f0ec690:	8c63fb10 */ 	lw	$v1,%lo(var8007fb10)($v1)
/*  f0ec694:	3c028008 */ 	lui	$v0,%hi(var8007fb04)
/*  f0ec698:	3c038008 */ 	lui	$v1,%hi(var8007fb08)
/*  f0ec69c:	8c42fb04 */ 	lw	$v0,%lo(var8007fb04)($v0)
/*  f0ec6a0:	8c63fb08 */ 	lw	$v1,%lo(var8007fb08)($v1)
.L0f0ec6a4:
/*  f0ec6a4:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0ec6a8:	afa8006c */ 	sw	$t0,0x6c($sp)
/*  f0ec6ac:	86290002 */ 	lh	$t1,0x2($s1)
/*  f0ec6b0:	afa90068 */ 	sw	$t1,0x68($sp)
/*  f0ec6b4:	8e240008 */ 	lw	$a0,0x8($s1)
/*  f0ec6b8:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f0ec6bc:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0ec6c0:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f0ec6c4:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f0ec6c8:	a3a00064 */ 	sb	$zero,0x64($sp)
/*  f0ec6cc:	8e250008 */ 	lw	$a1,0x8($s1)
/*  f0ec6d0:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0ec6d4:	8ca30010 */ 	lw	$v1,0x10($a1)
/*  f0ec6d8:	50600042 */ 	beqzl	$v1,.L0f0ec7e4
/*  f0ec6dc:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0ec6e0:	0060f809 */ 	jalr	$v1
/*  f0ec6e4:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0ec6e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ec6ec:	1441003c */ 	bne	$v0,$at,.L0f0ec7e0
/*  f0ec6f0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ec6f4:	afaa0060 */ 	sw	$t2,0x60($sp)
/*  f0ec6f8:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0ec6fc:	44803000 */ 	mtc1	$zero,$f6
/*  f0ec700:	3c0f7f1b */ 	lui	$t7,%hi(var7f1b1fb0)
/*  f0ec704:	c4e40040 */ 	lwc1	$f4,0x40($a3)
/*  f0ec708:	25ef1fb0 */ 	addiu	$t7,$t7,%lo(var7f1b1fb0)
/*  f0ec70c:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ec710:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec714:	4502000a */ 	bc1fl	.L0f0ec740
/*  f0ec718:	90ed003d */ 	lbu	$t5,0x3d($a3)
/*  f0ec71c:	90eb003c */ 	lbu	$t3,0x3c($a3)
/*  f0ec720:	3c107f1b */ 	lui	$s0,%hi(var7f1b1fd4)
/*  f0ec724:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f0ec728:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0ec72c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0ec730:	020c8021 */ 	addu	$s0,$s0,$t4
/*  f0ec734:	10000011 */ 	beqz	$zero,.L0f0ec77c
/*  f0ec738:	8e101fd4 */ 	lw	$s0,%lo(var7f1b1fd4)($s0)
/*  f0ec73c:	90ed003d */ 	lbu	$t5,0x3d($a3)
.L0f0ec740:
/*  f0ec740:	90f9003c */ 	lbu	$t9,0x3c($a3)
/*  f0ec744:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0ec748:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f0ec74c:	00194100 */ 	sll	$t0,$t9,0x4
/*  f0ec750:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0ec754:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0ec758:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ec75c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0ec760:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0ec764:	010f4821 */ 	addu	$t1,$t0,$t7
/*  f0ec768:	8d250024 */ 	lw	$a1,0x24($t1)
/*  f0ec76c:	0fc01a40 */ 	jal	func0f006900
/*  f0ec770:	8f040024 */ 	lw	$a0,0x24($t8)
/*  f0ec774:	00408025 */ 	or	$s0,$v0,$zero
/*  f0ec778:	8e270010 */ 	lw	$a3,0x10($s1)
.L0f0ec77c:
/*  f0ec77c:	8cea000c */ 	lw	$t2,0xc($a3)
/*  f0ec780:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ec784:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ec788:	51400009 */ 	beqzl	$t2,.L0f0ec7b0
/*  f0ec78c:	90e3003c */ 	lbu	$v1,0x3c($a3)
/*  f0ec790:	0fc01a40 */ 	jal	func0f006900
/*  f0ec794:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ec798:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ec79c:	00415824 */ 	and	$t3,$v0,$at
/*  f0ec7a0:	320c00ff */ 	andi	$t4,$s0,0xff
/*  f0ec7a4:	016c8025 */ 	or	$s0,$t3,$t4
/*  f0ec7a8:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0ec7ac:	90e3003c */ 	lbu	$v1,0x3c($a3)
.L0f0ec7b0:
/*  f0ec7b0:	3c047f1b */ 	lui	$a0,%hi(var7f1b22a4)
/*  f0ec7b4:	3c057f1b */ 	lui	$a1,%hi(var7f1b213c)
/*  f0ec7b8:	00036900 */ 	sll	$t5,$v1,0x4
/*  f0ec7bc:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f0ec7c0:	000d1880 */ 	sll	$v1,$t5,0x2
/*  f0ec7c4:	00832021 */ 	addu	$a0,$a0,$v1
/*  f0ec7c8:	00a32821 */ 	addu	$a1,$a1,$v1
/*  f0ec7cc:	8ca5213c */ 	lw	$a1,%lo(var7f1b213c)($a1)
/*  f0ec7d0:	0fc54f8e */ 	jal	func0f153e38
/*  f0ec7d4:	8c8422a4 */ 	lw	$a0,%lo(var7f1b22a4)($a0)
/*  f0ec7d8:	10000039 */ 	beqz	$zero,.L0f0ec8c0
/*  f0ec7dc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ec7e0:
/*  f0ec7e0:	8e270010 */ 	lw	$a3,0x10($s1)
.L0f0ec7e4:
/*  f0ec7e4:	44805000 */ 	mtc1	$zero,$f10
/*  f0ec7e8:	3c0f7f1b */ 	lui	$t7,%hi(var7f1b1fb0)
/*  f0ec7ec:	c4e80040 */ 	lwc1	$f8,0x40($a3)
/*  f0ec7f0:	25ef1fb0 */ 	addiu	$t7,$t7,%lo(var7f1b1fb0)
/*  f0ec7f4:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0ec7f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec7fc:	4502000a */ 	bc1fl	.L0f0ec828
/*  f0ec800:	90f9003d */ 	lbu	$t9,0x3d($a3)
/*  f0ec804:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0ec808:	3c107f1b */ 	lui	$s0,%hi(var7f1b1fc8)
/*  f0ec80c:	000ec100 */ 	sll	$t8,$t6,0x4
/*  f0ec810:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f0ec814:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0ec818:	02188021 */ 	addu	$s0,$s0,$t8
/*  f0ec81c:	10000011 */ 	beqz	$zero,.L0f0ec864
/*  f0ec820:	8e101fc8 */ 	lw	$s0,%lo(var7f1b1fc8)($s0)
/*  f0ec824:	90f9003d */ 	lbu	$t9,0x3d($a3)
.L0f0ec828:
/*  f0ec828:	90ea003c */ 	lbu	$t2,0x3c($a3)
/*  f0ec82c:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0ec830:	00194100 */ 	sll	$t0,$t9,0x4
/*  f0ec834:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f0ec838:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0ec83c:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0ec840:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0ec844:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ec848:	010f4821 */ 	addu	$t1,$t0,$t7
/*  f0ec84c:	016f6021 */ 	addu	$t4,$t3,$t7
/*  f0ec850:	8d850018 */ 	lw	$a1,0x18($t4)
/*  f0ec854:	0fc01a40 */ 	jal	func0f006900
/*  f0ec858:	8d240018 */ 	lw	$a0,0x18($t1)
/*  f0ec85c:	00408025 */ 	or	$s0,$v0,$zero
/*  f0ec860:	8e270010 */ 	lw	$a3,0x10($s1)
.L0f0ec864:
/*  f0ec864:	8ced000c */ 	lw	$t5,0xc($a3)
/*  f0ec868:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ec86c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ec870:	51a00009 */ 	beqzl	$t5,.L0f0ec898
/*  f0ec874:	90e3003c */ 	lbu	$v1,0x3c($a3)
/*  f0ec878:	0fc01a40 */ 	jal	func0f006900
/*  f0ec87c:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ec880:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ec884:	00417024 */ 	and	$t6,$v0,$at
/*  f0ec888:	321800ff */ 	andi	$t8,$s0,0xff
/*  f0ec88c:	01d88025 */ 	or	$s0,$t6,$t8
/*  f0ec890:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0ec894:	90e3003c */ 	lbu	$v1,0x3c($a3)
.L0f0ec898:
/*  f0ec898:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0ec89c:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0ec8a0:	0003c900 */ 	sll	$t9,$v1,0x4
/*  f0ec8a4:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0ec8a8:	00191880 */ 	sll	$v1,$t9,0x2
/*  f0ec8ac:	00832021 */ 	addu	$a0,$a0,$v1
/*  f0ec8b0:	00a32821 */ 	addu	$a1,$a1,$v1
/*  f0ec8b4:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0ec8b8:	0fc54f8e */ 	jal	func0f153e38
/*  f0ec8bc:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
.L0f0ec8c0:
/*  f0ec8c0:	0fc54d8a */ 	jal	func0f153628
/*  f0ec8c4:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f0ec8c8:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0ec8cc:	8e28000c */ 	lw	$t0,0xc($s1)
/*  f0ec8d0:	3c014220 */ 	lui	$at,0x4220
/*  f0ec8d4:	51000060 */ 	beqzl	$t0,.L0f0eca58
/*  f0ec8d8:	8e240008 */ 	lw	$a0,0x8($s1)
/*  f0ec8dc:	44816000 */ 	mtc1	$at,$f12
/*  f0ec8e0:	0fc01ac2 */ 	jal	func0f006b08
/*  f0ec8e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec8e8:	3c01437f */ 	lui	$at,0x437f
/*  f0ec8ec:	44818000 */ 	mtc1	$at,$f16
/*  f0ec8f0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ec8f4:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0ec8f8:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f0ec8fc:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0ec900:	3c014f00 */ 	lui	$at,0x4f00
/*  f0ec904:	4449f800 */ 	cfc1	$t1,$31
/*  f0ec908:	44caf800 */ 	ctc1	$t2,$31
/*  f0ec90c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec910:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f0ec914:	444af800 */ 	cfc1	$t2,$31
/*  f0ec918:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec91c:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0ec920:	51400013 */ 	beqzl	$t2,.L0f0ec970
/*  f0ec924:	440a2000 */ 	mfc1	$t2,$f4
/*  f0ec928:	44812000 */ 	mtc1	$at,$f4
/*  f0ec92c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ec930:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f0ec934:	44caf800 */ 	ctc1	$t2,$31
/*  f0ec938:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec93c:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0ec940:	444af800 */ 	cfc1	$t2,$31
/*  f0ec944:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec948:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0ec94c:	15400005 */ 	bnez	$t2,.L0f0ec964
/*  f0ec950:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec954:	440a2000 */ 	mfc1	$t2,$f4
/*  f0ec958:	3c018000 */ 	lui	$at,0x8000
/*  f0ec95c:	10000007 */ 	beqz	$zero,.L0f0ec97c
/*  f0ec960:	01415025 */ 	or	$t2,$t2,$at
.L0f0ec964:
/*  f0ec964:	10000005 */ 	beqz	$zero,.L0f0ec97c
/*  f0ec968:	240affff */ 	addiu	$t2,$zero,-1
/*  f0ec96c:	440a2000 */ 	mfc1	$t2,$f4
.L0f0ec970:
/*  f0ec970:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec974:	0540fffb */ 	bltz	$t2,.L0f0ec964
/*  f0ec978:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ec97c:
/*  f0ec97c:	afaa004c */ 	sw	$t2,0x4c($sp)
/*  f0ec980:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0ec984:	44c9f800 */ 	ctc1	$t1,$31
/*  f0ec988:	44804000 */ 	mtc1	$zero,$f8
/*  f0ec98c:	c4e60040 */ 	lwc1	$f6,0x40($a3)
/*  f0ec990:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0ec994:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ec998:	4502000b */ 	bc1fl	.L0f0ec9c8
/*  f0ec99c:	90ed003d */ 	lbu	$t5,0x3d($a3)
/*  f0ec9a0:	90eb003c */ 	lbu	$t3,0x3c($a3)
/*  f0ec9a4:	3c0c7f1b */ 	lui	$t4,%hi(var7f1b1fd0)
/*  f0ec9a8:	000b7900 */ 	sll	$t7,$t3,0x4
/*  f0ec9ac:	01eb7823 */ 	subu	$t7,$t7,$t3
/*  f0ec9b0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0ec9b4:	018f6021 */ 	addu	$t4,$t4,$t7
/*  f0ec9b8:	8d8c1fd0 */ 	lw	$t4,%lo(var7f1b1fd0)($t4)
/*  f0ec9bc:	10000010 */ 	beqz	$zero,.L0f0eca00
/*  f0ec9c0:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0ec9c4:	90ed003d */ 	lbu	$t5,0x3d($a3)
.L0f0ec9c8:
/*  f0ec9c8:	90f9003c */ 	lbu	$t9,0x3c($a3)
/*  f0ec9cc:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0ec9d0:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f0ec9d4:	00194100 */ 	sll	$t0,$t9,0x4
/*  f0ec9d8:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0ec9dc:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0ec9e0:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ec9e4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0ec9e8:	004ec021 */ 	addu	$t8,$v0,$t6
/*  f0ec9ec:	00484821 */ 	addu	$t1,$v0,$t0
/*  f0ec9f0:	8d250020 */ 	lw	$a1,0x20($t1)
/*  f0ec9f4:	0fc01a40 */ 	jal	func0f006900
/*  f0ec9f8:	8f040020 */ 	lw	$a0,0x20($t8)
/*  f0ec9fc:	afa20050 */ 	sw	$v0,0x50($sp)
.L0f0eca00:
/*  f0eca00:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eca04:	320500ff */ 	andi	$a1,$s0,0xff
/*  f0eca08:	0fc01a40 */ 	jal	func0f006900
/*  f0eca0c:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eca10:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eca14:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0eca18:	0fc01a40 */ 	jal	func0f006900
/*  f0eca1c:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0eca20:	8e2a0010 */ 	lw	$t2,0x10($s1)
/*  f0eca24:	3c047f1b */ 	lui	$a0,%hi(var7f1b22a0)
/*  f0eca28:	3c057f1b */ 	lui	$a1,%hi(var7f1b2138)
/*  f0eca2c:	9143003c */ 	lbu	$v1,0x3c($t2)
/*  f0eca30:	00408025 */ 	or	$s0,$v0,$zero
/*  f0eca34:	00035900 */ 	sll	$t3,$v1,0x4
/*  f0eca38:	01635823 */ 	subu	$t3,$t3,$v1
/*  f0eca3c:	000b1880 */ 	sll	$v1,$t3,0x2
/*  f0eca40:	00832021 */ 	addu	$a0,$a0,$v1
/*  f0eca44:	00a32821 */ 	addu	$a1,$a1,$v1
/*  f0eca48:	8ca52138 */ 	lw	$a1,%lo(var7f1b2138)($a1)
/*  f0eca4c:	0fc54f8e */ 	jal	func0f153e38
/*  f0eca50:	8c8422a0 */ 	lw	$a0,%lo(var7f1b22a0)($a0)
/*  f0eca54:	8e240008 */ 	lw	$a0,0x8($s1)
.L0f0eca58:
/*  f0eca58:	0fc3c962 */ 	jal	func0f0f2588
/*  f0eca5c:	8e250010 */ 	lw	$a1,0x10($s1)
/*  f0eca60:	5040003c */ 	beqzl	$v0,.L0f0ecb54
/*  f0eca64:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f0eca68:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0eca6c:	44808000 */ 	mtc1	$zero,$f16
/*  f0eca70:	c4ea0040 */ 	lwc1	$f10,0x40($a3)
/*  f0eca74:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0eca78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eca7c:	4502000a */ 	bc1fl	.L0f0ecaa8
/*  f0eca80:	90ed003d */ 	lbu	$t5,0x3d($a3)
/*  f0eca84:	90ef003c */ 	lbu	$t7,0x3c($a3)
/*  f0eca88:	3c107f1b */ 	lui	$s0,%hi(var7f1b1fcc)
/*  f0eca8c:	000f6100 */ 	sll	$t4,$t7,0x4
/*  f0eca90:	018f6023 */ 	subu	$t4,$t4,$t7
/*  f0eca94:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0eca98:	020c8021 */ 	addu	$s0,$s0,$t4
/*  f0eca9c:	10000012 */ 	beqz	$zero,.L0f0ecae8
/*  f0ecaa0:	8e101fcc */ 	lw	$s0,%lo(var7f1b1fcc)($s0)
/*  f0ecaa4:	90ed003d */ 	lbu	$t5,0x3d($a3)
.L0f0ecaa8:
/*  f0ecaa8:	2403003c */ 	addiu	$v1,$zero,0x3c
/*  f0ecaac:	90f9003c */ 	lbu	$t9,0x3c($a3)
/*  f0ecab0:	01a30019 */ 	multu	$t5,$v1
/*  f0ecab4:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0ecab8:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0ecabc:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0ecac0:	00007012 */ 	mflo	$t6
/*  f0ecac4:	004ec021 */ 	addu	$t8,$v0,$t6
/*  f0ecac8:	8f04001c */ 	lw	$a0,0x1c($t8)
/*  f0ecacc:	03230019 */ 	multu	$t9,$v1
/*  f0ecad0:	00004012 */ 	mflo	$t0
/*  f0ecad4:	00484821 */ 	addu	$t1,$v0,$t0
/*  f0ecad8:	0fc01a40 */ 	jal	func0f006900
/*  f0ecadc:	8d25001c */ 	lw	$a1,0x1c($t1)
/*  f0ecae0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0ecae4:	8e270010 */ 	lw	$a3,0x10($s1)
.L0f0ecae8:
/*  f0ecae8:	8cea000c */ 	lw	$t2,0xc($a3)
/*  f0ecaec:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ecaf0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ecaf4:	51400009 */ 	beqzl	$t2,.L0f0ecb1c
/*  f0ecaf8:	90e3003c */ 	lbu	$v1,0x3c($a3)
/*  f0ecafc:	0fc01a40 */ 	jal	func0f006900
/*  f0ecb00:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ecb04:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ecb08:	00415824 */ 	and	$t3,$v0,$at
/*  f0ecb0c:	320f00ff */ 	andi	$t7,$s0,0xff
/*  f0ecb10:	016f8025 */ 	or	$s0,$t3,$t7
/*  f0ecb14:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0ecb18:	90e3003c */ 	lbu	$v1,0x3c($a3)
.L0f0ecb1c:
/*  f0ecb1c:	3c047f1b */ 	lui	$a0,%hi(var7f1b229c)
/*  f0ecb20:	3c057f1b */ 	lui	$a1,%hi(var7f1b2134)
/*  f0ecb24:	00036100 */ 	sll	$t4,$v1,0x4
/*  f0ecb28:	01836023 */ 	subu	$t4,$t4,$v1
/*  f0ecb2c:	000c1880 */ 	sll	$v1,$t4,0x2
/*  f0ecb30:	00832021 */ 	addu	$a0,$a0,$v1
/*  f0ecb34:	00a32821 */ 	addu	$a1,$a1,$v1
/*  f0ecb38:	8ca52134 */ 	lw	$a1,%lo(var7f1b2134)($a1)
/*  f0ecb3c:	0fc54f8e */ 	jal	func0f153e38
/*  f0ecb40:	8c84229c */ 	lw	$a0,%lo(var7f1b229c)($a0)
/*  f0ecb44:	3c0d7f00 */ 	lui	$t5,0x7f00
/*  f0ecb48:	35ad2faf */ 	ori	$t5,$t5,0x2faf
/*  f0ecb4c:	afad005c */ 	sw	$t5,0x5c($sp)
/*  f0ecb50:	862e0000 */ 	lh	$t6,0x0($s1)
.L0f0ecb54:
/*  f0ecb54:	86380004 */ 	lh	$t8,0x4($s1)
/*  f0ecb58:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0ecb5c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0ecb60:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*  f0ecb64:	01d82821 */ 	addu	$a1,$t6,$t8
/*  f0ecb68:	24a5fff0 */ 	addiu	$a1,$a1,-16
/*  f0ecb6c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ecb70:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f0ecb74:	24070006 */ 	addiu	$a3,$zero,0x6
/*  f0ecb78:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f0ecb7c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ecb80:	0fc38dec */ 	jal	func0f0e37b0
/*  f0ecb84:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0ecb88:	86290000 */ 	lh	$t1,0x0($s1)
/*  f0ecb8c:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f0ecb90:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0ecb94:	252a000a */ 	addiu	$t2,$t1,0xa
/*  f0ecb98:	afaa006c */ 	sw	$t2,0x6c($sp)
/*  f0ecb9c:	862b0002 */ 	lh	$t3,0x2($s1)
/*  f0ecba0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ecba4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ecba8:	256f0002 */ 	addiu	$t7,$t3,0x2
/*  f0ecbac:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f0ecbb0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ecbb4:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0ecbb8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ecbbc:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0ecbc0:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0ecbc4:	86380006 */ 	lh	$t8,0x6($s1)
/*  f0ecbc8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ecbcc:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ecbd0:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f0ecbd4:	8fa70070 */ 	lw	$a3,0x70($sp)
/*  f0ecbd8:	0fc5580f */ 	jal	func0f15603c
/*  f0ecbdc:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0ecbe0:	0fc54de0 */ 	jal	func0f153780
/*  f0ecbe4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ecbe8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ecbec:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0ecbf0:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0ecbf4:	03e00008 */ 	jr	$ra
/*  f0ecbf8:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f0ecbfc
/*  f0ecbfc:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0ecc00:	30ce0002 */ 	andi	$t6,$a2,0x2
/*  f0ecc04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ecc08:	11c0001e */ 	beqz	$t6,.L0f0ecc84
/*  f0ecc0c:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0ecc10:	90af0002 */ 	lbu	$t7,0x2($a1)
/*  f0ecc14:	51e0001c */ 	beqzl	$t7,.L0f0ecc88
/*  f0ecc18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecc1c:	8c820010 */ 	lw	$v0,0x10($a0)
/*  f0ecc20:	0080c025 */ 	or	$t8,$a0,$zero
/*  f0ecc24:	03002825 */ 	or	$a1,$t8,$zero
/*  f0ecc28:	1040000a */ 	beqz	$v0,.L0f0ecc54
/*  f0ecc2c:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0ecc30:	0040f809 */ 	jalr	$v0
/*  f0ecc34:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f0ecc38:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ecc3c:	14410005 */ 	bne	$v0,$at,.L0f0ecc54
/*  f0ecc40:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0ecc44:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0ecc48:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0ecc4c:	10000006 */ 	beqz	$zero,.L0f0ecc68
/*  f0ecc50:	8fa80030 */ 	lw	$t0,0x30($sp)
.L0f0ecc54:
/*  f0ecc54:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0ecc58:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0ecc5c:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0ecc60:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0ecc64:	8fa80030 */ 	lw	$t0,0x30($sp)
.L0f0ecc68:
/*  f0ecc68:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0ecc6c:	8d020010 */ 	lw	$v0,0x10($t0)
/*  f0ecc70:	01002825 */ 	or	$a1,$t0,$zero
/*  f0ecc74:	50400004 */ 	beqzl	$v0,.L0f0ecc88
/*  f0ecc78:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecc7c:	0040f809 */ 	jalr	$v0
/*  f0ecc80:	27a60020 */ 	addiu	$a2,$sp,0x20
.L0f0ecc84:
/*  f0ecc84:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ecc88:
/*  f0ecc88:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0ecc8c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0ecc90:	03e00008 */ 	jr	$ra
/*  f0ecc94:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ecc98
.late_rodata
glabel var7f1b1e60
.word func0f0ecc98+0x2c # f0eccc4
glabel var7f1b1e64
.word func0f0ecc98+0x68 # f0ecd00
glabel var7f1b1e68
.word func0f0ecc98+0xcc # f0ecd64
glabel var7f1b1e6c
.word func0f0ecc98+0xdc # f0ecd74
glabel var7f1b1e70
.word func0f0ecc98+0xec # f0ecd84
glabel var7f1b1e74
.word func0f0ecc98+0xfc # f0ecd94
glabel var7f1b1e78
.word func0f0ecc98+0x10c # f0ecda4
glabel var7f1b1e7c
.word func0f0ecc98+0x11c # f0ecdb4
glabel var7f1b1e80
.word func0f0ecc98+0x12c # f0ecdc4
glabel var7f1b1e84
.word func0f0ecc98+0x13c # f0ecdd4
glabel var7f1b1e88
.word func0f0ecc98+0x14c # f0ecde4
glabel var7f1b1e8c
.word func0f0ecc98+0x15c # f0ecdf4
.text
/*  f0ecc98:	248effff */ 	addiu	$t6,$a0,-1
/*  f0ecc9c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0ecca0:	2dc1000c */ 	sltiu	$at,$t6,0xc
/*  f0ecca4:	10200057 */ 	beqz	$at,.L0f0ece04
/*  f0ecca8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0eccac:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0eccb0:	3c017f1b */ 	lui	$at,%hi(var7f1b1e60)
/*  f0eccb4:	002e0821 */ 	addu	$at,$at,$t6
/*  f0eccb8:	8c2e1e60 */ 	lw	$t6,%lo(var7f1b1e60)($at)
/*  f0eccbc:	01c00008 */ 	jr	$t6
/*  f0eccc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eccc4:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0eccc8:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0ecccc:	3c04800a */ 	lui	$a0,%hi(g_MenuStack+0xe20)
/*  f0eccd0:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0eccd4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0eccd8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0eccdc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0ecce0:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0ecce4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0ecce8:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0eccec:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0eccf0:	0fc670ac */ 	jal	func0f19c2b0
/*  f0eccf4:	8c84ee20 */ 	lw	$a0,%lo(g_MenuStack+0xe20)($a0)
/*  f0eccf8:	10000046 */ 	beqz	$zero,.L0f0ece14
/*  f0eccfc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecd00:	0fc6709d */ 	jal	mpIsVar800884b4NonZero
/*  f0ecd04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecd08:	14400012 */ 	bnez	$v0,.L0f0ecd54
/*  f0ecd0c:	3c198007 */ 	lui	$t9,%hi(g_MpPlayerNum)
/*  f0ecd10:	8f391448 */ 	lw	$t9,%lo(g_MpPlayerNum)($t9)
/*  f0ecd14:	3c09800a */ 	lui	$t1,0x800a
/*  f0ecd18:	2529e000 */ 	addiu	$t1,$t1,-8192
/*  f0ecd1c:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f0ecd20:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0ecd24:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ecd28:	01194021 */ 	addu	$t0,$t0,$t9
/*  f0ecd2c:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f0ecd30:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0ecd34:	00084100 */ 	sll	$t0,$t0,0x4
/*  f0ecd38:	01091021 */ 	addu	$v0,$t0,$t1
/*  f0ecd3c:	3c0a4fac */ 	lui	$t2,0x4fac
/*  f0ecd40:	354a5ace */ 	ori	$t2,$t2,0x5ace
/*  f0ecd44:	ac4a0850 */ 	sw	$t2,0x850($v0)
/*  f0ecd48:	8c440844 */ 	lw	$a0,0x844($v0)
/*  f0ecd4c:	0fc67091 */ 	jal	mpCalculateVar800884b4
/*  f0ecd50:	8c450848 */ 	lw	$a1,0x848($v0)
.L0f0ecd54:
/*  f0ecd54:	0fc670a2 */ 	jal	func0f19c288
/*  f0ecd58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecd5c:	1000002d */ 	beqz	$zero,.L0f0ece14
/*  f0ecd60:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecd64:	0fc68461 */ 	jal	func0f1a1184
/*  f0ecd68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecd6c:	10000029 */ 	beqz	$zero,.L0f0ece14
/*  f0ecd70:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecd74:	0fc6851a */ 	jal	func0f1a1468
/*  f0ecd78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecd7c:	10000025 */ 	beqz	$zero,.L0f0ece14
/*  f0ecd80:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecd84:	0fc687a4 */ 	jal	func0f1a1e90
/*  f0ecd88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecd8c:	10000021 */ 	beqz	$zero,.L0f0ece14
/*  f0ecd90:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecd94:	0fc67aa0 */ 	jal	func0f19ea80
/*  f0ecd98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecd9c:	1000001d */ 	beqz	$zero,.L0f0ece14
/*  f0ecda0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecda4:	0fc685f9 */ 	jal	func0f1a17e4
/*  f0ecda8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecdac:	10000019 */ 	beqz	$zero,.L0f0ece14
/*  f0ecdb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecdb4:	0fc68989 */ 	jal	func0f1a2624
/*  f0ecdb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecdbc:	10000015 */ 	beqz	$zero,.L0f0ece14
/*  f0ecdc0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecdc4:	0fc689a7 */ 	jal	func0f1a269c
/*  f0ecdc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecdcc:	10000011 */ 	beqz	$zero,.L0f0ece14
/*  f0ecdd0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecdd4:	0fc689c5 */ 	jal	func0f1a2714
/*  f0ecdd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecddc:	1000000d */ 	beqz	$zero,.L0f0ece14
/*  f0ecde0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecde4:	0fc687c0 */ 	jal	func0f1a1f00
/*  f0ecde8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecdec:	10000009 */ 	beqz	$zero,.L0f0ece14
/*  f0ecdf0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ecdf4:	0fc687dc */ 	jal	func0f1a1f70
/*  f0ecdf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecdfc:	10000005 */ 	beqz	$zero,.L0f0ece14
/*  f0ece00:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ece04:
/*  f0ece04:	3c04800a */ 	lui	$a0,%hi(g_Briefing)
/*  f0ece08:	0fc5b9f1 */ 	jal	langGet
/*  f0ece0c:	9484dfc8 */ 	lhu	$a0,%lo(g_Briefing)($a0)
/*  f0ece10:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ece14:
/*  f0ece14:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0ece18:	03e00008 */ 	jr	$ra
/*  f0ece1c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ece20
/*  f0ece20:	27bda1c8 */ 	addiu	$sp,$sp,-24120
/*  f0ece24:	3c0f7f1b */ 	lui	$t7,%hi(var7f1adfc4)
/*  f0ece28:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0ece2c:	25efdfc4 */ 	addiu	$t7,$t7,%lo(var7f1adfc4)
/*  f0ece30:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0ece34:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ece38:	afa45e38 */ 	sw	$a0,0x5e38($sp)
/*  f0ece3c:	25ea1f38 */ 	addiu	$t2,$t7,0x1f38
/*  f0ece40:	27ae3ef8 */ 	addiu	$t6,$sp,0x3ef8
.L0f0ece44:
/*  f0ece44:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0ece48:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f0ece4c:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f0ece50:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f0ece54:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f0ece58:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f0ece5c:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f0ece60:	15eafff8 */ 	bne	$t7,$t2,.L0f0ece44
/*  f0ece64:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f0ece68:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0ece6c:	8dea0004 */ 	lw	$t2,0x4($t7)
/*  f0ece70:	240c0018 */ 	addiu	$t4,$zero,0x18
/*  f0ece74:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0ece78:	adca0004 */ 	sw	$t2,0x4($t6)
/*  f0ece7c:	8e0b0014 */ 	lw	$t3,0x14($s0)
/*  f0ece80:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f0ece84:	afab0060 */ 	sw	$t3,0x60($sp)
/*  f0ece88:	8e0d0008 */ 	lw	$t5,0x8($s0)
/*  f0ece8c:	0fc3b326 */ 	jal	func0f0ecc98
/*  f0ece90:	91a40001 */ 	lbu	$a0,0x1($t5)
/*  f0ece94:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f0ece98:	0fc3c94d */ 	jal	func0f0f2534
/*  f0ece9c:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f0ecea0:	10400003 */ 	beqz	$v0,.L0f0eceb0
/*  f0ecea4:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0ecea8:	2419000a */ 	addiu	$t9,$zero,0xa
/*  f0eceac:	afb9004c */ 	sw	$t9,0x4c($sp)
.L0f0eceb0:
/*  f0eceb0:	10a0000a */ 	beqz	$a1,.L0f0ecedc
/*  f0eceb4:	3c0f8008 */ 	lui	$t7,%hi(var8007fb0c)
/*  f0eceb8:	8deffb0c */ 	lw	$t7,%lo(var8007fb0c)($t7)
/*  f0ecebc:	86180004 */ 	lh	$t8,0x4($s0)
/*  f0ecec0:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f0ecec4:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0ecec8:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0ececc:	27a63ef8 */ 	addiu	$a2,$sp,0x3ef8
/*  f0eced0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0eced4:	0fc55d48 */ 	jal	func0f157520
/*  f0eced8:	030a2023 */ 	subu	$a0,$t8,$t2
.L0f0ecedc:
/*  f0ecedc:	93ad3ef8 */ 	lbu	$t5,0x3ef8($sp)
/*  f0ecee0:	27ae3ef8 */ 	addiu	$t6,$sp,0x3ef8
/*  f0ecee4:	27ab1fb8 */ 	addiu	$t3,$sp,0x1fb8
/*  f0ecee8:	27ac0078 */ 	addiu	$t4,$sp,0x78
/*  f0eceec:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0ecef0:	afab0070 */ 	sw	$t3,0x70($sp)
/*  f0ecef4:	afac006c */ 	sw	$t4,0x6c($sp)
/*  f0ecef8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ecefc:	11a00027 */ 	beqz	$t5,.L0f0ecf9c
/*  f0ecf00:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ecf04:	91c30000 */ 	lbu	$v1,0x0($t6)
/*  f0ecf08:	27a9006c */ 	addiu	$t1,$sp,0x6c
/*  f0ecf0c:	2408000a */ 	addiu	$t0,$zero,0xa
/*  f0ecf10:	2407007c */ 	addiu	$a3,$zero,0x7c
/*  f0ecf14:	00601025 */ 	or	$v0,$v1,$zero
.L0f0ecf18:
/*  f0ecf18:	14e20003 */ 	bne	$a3,$v0,.L0f0ecf28
/*  f0ecf1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecf20:	1000001a */ 	beqz	$zero,.L0f0ecf8c
/*  f0ecf24:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ecf28:
/*  f0ecf28:	15020011 */ 	bne	$t0,$v0,.L0f0ecf70
/*  f0ecf2c:	00057080 */ 	sll	$t6,$a1,0x2
/*  f0ecf30:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*  f0ecf34:	0006102b */ 	sltu	$v0,$zero,$a2
/*  f0ecf38:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0ecf3c:	a3230000 */ 	sb	$v1,0x0($t9)
/*  f0ecf40:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f0ecf44:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f0ecf48:	270a0001 */ 	addiu	$t2,$t8,0x1
/*  f0ecf4c:	afaa006c */ 	sw	$t2,0x6c($sp)
/*  f0ecf50:	908f0000 */ 	lbu	$t7,0x0($a0)
/*  f0ecf54:	a16f0000 */ 	sb	$t7,0x0($t3)
/*  f0ecf58:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f0ecf5c:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f0ecf60:	1040000a */ 	beqz	$v0,.L0f0ecf8c
/*  f0ecf64:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f0ecf68:	10000008 */ 	beqz	$zero,.L0f0ecf8c
/*  f0ecf6c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0ecf70:
/*  f0ecf70:	012e1021 */ 	addu	$v0,$t1,$t6
/*  f0ecf74:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f0ecf78:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ecf7c:	a3230000 */ 	sb	$v1,0x0($t9)
/*  f0ecf80:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f0ecf84:	270a0001 */ 	addiu	$t2,$t8,0x1
/*  f0ecf88:	ac4a0000 */ 	sw	$t2,0x0($v0)
.L0f0ecf8c:
/*  f0ecf8c:	90830001 */ 	lbu	$v1,0x1($a0)
/*  f0ecf90:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0ecf94:	1460ffe0 */ 	bnez	$v1,.L0f0ecf18
/*  f0ecf98:	00601025 */ 	or	$v0,$v1,$zero
.L0f0ecf9c:
/*  f0ecf9c:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f0ecfa0:	44803000 */ 	mtc1	$zero,$f6
/*  f0ecfa4:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0ecfa8:	a1e00000 */ 	sb	$zero,0x0($t7)
/*  f0ecfac:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f0ecfb0:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0ecfb4:	a1600000 */ 	sb	$zero,0x0($t3)
/*  f0ecfb8:	860c0000 */ 	lh	$t4,0x0($s0)
/*  f0ecfbc:	258d0002 */ 	addiu	$t5,$t4,0x2
/*  f0ecfc0:	afad0058 */ 	sw	$t5,0x58($sp)
/*  f0ecfc4:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f0ecfc8:	25d90002 */ 	addiu	$t9,$t6,0x2
/*  f0ecfcc:	afb90054 */ 	sw	$t9,0x54($sp)
/*  f0ecfd0:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0ecfd4:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0ecfd8:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ecfdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecfe0:	4502000c */ 	bc1fl	.L0f0ed014
/*  f0ecfe4:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0ecfe8:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0ecfec:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0ecff0:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0ecff4:	00185100 */ 	sll	$t2,$t8,0x4
/*  f0ecff8:	01585023 */ 	subu	$t2,$t2,$t8
/*  f0ecffc:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0ed000:	004a7821 */ 	addu	$t7,$v0,$t2
/*  f0ed004:	8deb0018 */ 	lw	$t3,0x18($t7)
/*  f0ed008:	10000011 */ 	beqz	$zero,.L0f0ed050
/*  f0ed00c:	afab005c */ 	sw	$t3,0x5c($sp)
/*  f0ed010:	906c003d */ 	lbu	$t4,0x3d($v1)
.L0f0ed014:
/*  f0ed014:	9079003c */ 	lbu	$t9,0x3c($v1)
/*  f0ed018:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ed01c:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0ed020:	0019c100 */ 	sll	$t8,$t9,0x4
/*  f0ed024:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0ed028:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f0ed02c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0ed030:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0ed034:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0ed038:	00585021 */ 	addu	$t2,$v0,$t8
/*  f0ed03c:	8d450018 */ 	lw	$a1,0x18($t2)
/*  f0ed040:	0fc01a40 */ 	jal	func0f006900
/*  f0ed044:	8dc40018 */ 	lw	$a0,0x18($t6)
/*  f0ed048:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f0ed04c:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0ed050:
/*  f0ed050:	8c6f000c */ 	lw	$t7,0xc($v1)
/*  f0ed054:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f0ed058:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ed05c:	51e0000b */ 	beqzl	$t7,.L0f0ed08c
/*  f0ed060:	9062003c */ 	lbu	$v0,0x3c($v1)
/*  f0ed064:	0fc01a40 */ 	jal	func0f006900
/*  f0ed068:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ed06c:	8fac005c */ 	lw	$t4,0x5c($sp)
/*  f0ed070:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ed074:	00415824 */ 	and	$t3,$v0,$at
/*  f0ed078:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0ed07c:	016d7025 */ 	or	$t6,$t3,$t5
/*  f0ed080:	afae005c */ 	sw	$t6,0x5c($sp)
/*  f0ed084:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0ed088:	9062003c */ 	lbu	$v0,0x3c($v1)
.L0f0ed08c:
/*  f0ed08c:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0ed090:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0ed094:	0002c900 */ 	sll	$t9,$v0,0x4
/*  f0ed098:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f0ed09c:	00191080 */ 	sll	$v0,$t9,0x2
/*  f0ed0a0:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ed0a4:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0ed0a8:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0ed0ac:	0fc54f8e */ 	jal	func0f153e38
/*  f0ed0b0:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
/*  f0ed0b4:	0fc54d8a */ 	jal	func0f153628
/*  f0ed0b8:	8fa45e38 */ 	lw	$a0,0x5e38($sp)
/*  f0ed0bc:	86180000 */ 	lh	$t8,0x0($s0)
/*  f0ed0c0:	3c0b8008 */ 	lui	$t3,%hi(var8007fb10)
/*  f0ed0c4:	3c0d8008 */ 	lui	$t5,%hi(var8007fb0c)
/*  f0ed0c8:	270a0003 */ 	addiu	$t2,$t8,0x3
/*  f0ed0cc:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ed0d0:	860f0002 */ 	lh	$t7,0x2($s0)
/*  f0ed0d4:	8dadfb0c */ 	lw	$t5,%lo(var8007fb0c)($t5)
/*  f0ed0d8:	8d6bfb10 */ 	lw	$t3,%lo(var8007fb10)($t3)
/*  f0ed0dc:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f0ed0e0:	25ec0003 */ 	addiu	$t4,$t7,0x3
/*  f0ed0e4:	afac0054 */ 	sw	$t4,0x54($sp)
/*  f0ed0e8:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0ed0ec:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ed0f0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ed0f4:	86190004 */ 	lh	$t9,0x4($s0)
/*  f0ed0f8:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0ed0fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ed100:	2738fffc */ 	addiu	$t8,$t9,-4
/*  f0ed104:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0ed108:	860a0006 */ 	lh	$t2,0x6($s0)
/*  f0ed10c:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f0ed110:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0ed114:	254ffffc */ 	addiu	$t7,$t2,-4
/*  f0ed118:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0ed11c:	858b0000 */ 	lh	$t3,0x0($t4)
/*  f0ed120:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ed124:	27a71fb8 */ 	addiu	$a3,$sp,0x1fb8
/*  f0ed128:	000b6823 */ 	negu	$t5,$t3
/*  f0ed12c:	0fc5580f */ 	jal	func0f15603c
/*  f0ed130:	afad0024 */ 	sw	$t5,0x24($sp)
/*  f0ed134:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f0ed138:	3c0f8008 */ 	lui	$t7,%hi(var8007fb10)
/*  f0ed13c:	3c0c8008 */ 	lui	$t4,%hi(var8007fb0c)
/*  f0ed140:	25d90002 */ 	addiu	$t9,$t6,0x2
/*  f0ed144:	afb90058 */ 	sw	$t9,0x58($sp)
/*  f0ed148:	86180002 */ 	lh	$t8,0x2($s0)
/*  f0ed14c:	8d8cfb0c */ 	lw	$t4,%lo(var8007fb0c)($t4)
/*  f0ed150:	8deffb10 */ 	lw	$t7,%lo(var8007fb10)($t7)
/*  f0ed154:	3c0bff44 */ 	lui	$t3,0xff44
/*  f0ed158:	356b44ff */ 	ori	$t3,$t3,0x44ff
/*  f0ed15c:	270a0002 */ 	addiu	$t2,$t8,0x2
/*  f0ed160:	afaa0054 */ 	sw	$t2,0x54($sp)
/*  f0ed164:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0ed168:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0ed16c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ed170:	860d0004 */ 	lh	$t5,0x4($s0)
/*  f0ed174:	8faa0060 */ 	lw	$t2,0x60($sp)
/*  f0ed178:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ed17c:	25aefffc */ 	addiu	$t6,$t5,-4
/*  f0ed180:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0ed184:	86190006 */ 	lh	$t9,0x6($s0)
/*  f0ed188:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f0ed18c:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0ed190:	2738fffc */ 	addiu	$t8,$t9,-4
/*  f0ed194:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0ed198:	854f0000 */ 	lh	$t7,0x0($t2)
/*  f0ed19c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ed1a0:	27a71fb8 */ 	addiu	$a3,$sp,0x1fb8
/*  f0ed1a4:	000f6023 */ 	negu	$t4,$t7
/*  f0ed1a8:	0fc5580f */ 	jal	func0f15603c
/*  f0ed1ac:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f0ed1b0:	afa25e38 */ 	sw	$v0,0x5e38($sp)
/*  f0ed1b4:	0fc3c94d */ 	jal	func0f0f2534
/*  f0ed1b8:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f0ed1bc:	10400005 */ 	beqz	$v0,.L0f0ed1d4
/*  f0ed1c0:	3c0f8008 */ 	lui	$t7,%hi(var8007fb10)
/*  f0ed1c4:	860b0000 */ 	lh	$t3,0x0($s0)
/*  f0ed1c8:	256d0005 */ 	addiu	$t5,$t3,0x5
/*  f0ed1cc:	10000004 */ 	beqz	$zero,.L0f0ed1e0
/*  f0ed1d0:	afad0058 */ 	sw	$t5,0x58($sp)
.L0f0ed1d4:
/*  f0ed1d4:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f0ed1d8:	25d9000c */ 	addiu	$t9,$t6,0xc
/*  f0ed1dc:	afb90058 */ 	sw	$t9,0x58($sp)
.L0f0ed1e0:
/*  f0ed1e0:	86180002 */ 	lh	$t8,0x2($s0)
/*  f0ed1e4:	3c0c8008 */ 	lui	$t4,%hi(var8007fb0c)
/*  f0ed1e8:	8d8cfb0c */ 	lw	$t4,%lo(var8007fb0c)($t4)
/*  f0ed1ec:	8deffb10 */ 	lw	$t7,%lo(var8007fb10)($t7)
/*  f0ed1f0:	8fab005c */ 	lw	$t3,0x5c($sp)
/*  f0ed1f4:	270a0002 */ 	addiu	$t2,$t8,0x2
/*  f0ed1f8:	afaa0054 */ 	sw	$t2,0x54($sp)
/*  f0ed1fc:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0ed200:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ed204:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0ed208:	860d0004 */ 	lh	$t5,0x4($s0)
/*  f0ed20c:	8faa0060 */ 	lw	$t2,0x60($sp)
/*  f0ed210:	8fa45e38 */ 	lw	$a0,0x5e38($sp)
/*  f0ed214:	25aefffc */ 	addiu	$t6,$t5,-4
/*  f0ed218:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0ed21c:	86190006 */ 	lh	$t9,0x6($s0)
/*  f0ed220:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f0ed224:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0ed228:	2738ffff */ 	addiu	$t8,$t9,-1
/*  f0ed22c:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0ed230:	854f0000 */ 	lh	$t7,0x0($t2)
/*  f0ed234:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ed238:	27a70078 */ 	addiu	$a3,$sp,0x78
/*  f0ed23c:	000f6023 */ 	negu	$t4,$t7
/*  f0ed240:	0fc5580f */ 	jal	func0f15603c
/*  f0ed244:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f0ed248:	0fc54de0 */ 	jal	func0f153780
/*  f0ed24c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ed250:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ed254:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ed258:	27bd5e38 */ 	addiu	$sp,$sp,0x5e38
/*  f0ed25c:	03e00008 */ 	jr	$ra
/*  f0ed260:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ed264
/*  f0ed264:	27bde068 */ 	addiu	$sp,$sp,-8088
/*  f0ed268:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0ed26c:	8fb01fa8 */ 	lw	$s0,0x1fa8($sp)
/*  f0ed270:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0ed274:	afa41f98 */ 	sw	$a0,0x1f98($sp)
/*  f0ed278:	afa51f9c */ 	sw	$a1,0x1f9c($sp)
/*  f0ed27c:	afa61fa0 */ 	sw	$a2,0x1fa0($sp)
/*  f0ed280:	afa71fa4 */ 	sw	$a3,0x1fa4($sp)
/*  f0ed284:	84b80022 */ 	lh	$t8,0x22($a1)
/*  f0ed288:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f0ed28c:	3c087f1b */ 	lui	$t0,%hi(var7f1aff04)
/*  f0ed290:	2508ff04 */ 	addiu	$t0,$t0,%lo(var7f1aff04)
/*  f0ed294:	11d8005a */ 	beq	$t6,$t8,.L0f0ed400
/*  f0ed298:	27b90054 */ 	addiu	$t9,$sp,0x54
/*  f0ed29c:	250a1f38 */ 	addiu	$t2,$t0,0x1f38
.L0f0ed2a0:
/*  f0ed2a0:	8d010000 */ 	lw	$at,0x0($t0)
/*  f0ed2a4:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f0ed2a8:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f0ed2ac:	af21fff4 */ 	sw	$at,-0xc($t9)
/*  f0ed2b0:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*  f0ed2b4:	af21fff8 */ 	sw	$at,-0x8($t9)
/*  f0ed2b8:	8d01fffc */ 	lw	$at,-0x4($t0)
/*  f0ed2bc:	150afff8 */ 	bne	$t0,$t2,.L0f0ed2a0
/*  f0ed2c0:	af21fffc */ 	sw	$at,-0x4($t9)
/*  f0ed2c4:	8d010000 */ 	lw	$at,0x0($t0)
/*  f0ed2c8:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*  f0ed2cc:	27a60044 */ 	addiu	$a2,$sp,0x44
/*  f0ed2d0:	af210000 */ 	sw	$at,0x0($t9)
/*  f0ed2d4:	af2a0004 */ 	sw	$t2,0x4($t9)
/*  f0ed2d8:	8fa51f98 */ 	lw	$a1,0x1f98($sp)
/*  f0ed2dc:	8fa41f9c */ 	lw	$a0,0x1f9c($sp)
/*  f0ed2e0:	0fc3c8d5 */ 	jal	func0f0f2354
/*  f0ed2e4:	27a70040 */ 	addiu	$a3,$sp,0x40
/*  f0ed2e8:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f0ed2ec:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f0ed2f0:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0ed2f4:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f0ed2f8:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f0ed2fc:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0ed300:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0ed304:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f0ed308:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0ed30c:	3c0d800a */ 	lui	$t5,0x800a
/*  f0ed310:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0ed314:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f0ed318:	25ade000 */ 	addiu	$t5,$t5,-8192
/*  f0ed31c:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f0ed320:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f0ed324:	01cf7021 */ 	addu	$t6,$t6,$t7
/*  f0ed328:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f0ed32c:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0ed330:	006ec021 */ 	addu	$t8,$v1,$t6
/*  f0ed334:	006a4021 */ 	addu	$t0,$v1,$t2
/*  f0ed338:	87050660 */ 	lh	$a1,0x660($t8)
/*  f0ed33c:	851904fc */ 	lh	$t9,0x4fc($t0)
/*  f0ed340:	8fa41f98 */ 	lw	$a0,0x1f98($sp)
/*  f0ed344:	a7a5003e */ 	sh	$a1,0x3e($sp)
/*  f0ed348:	0fc3c94d */ 	jal	func0f0f2534
/*  f0ed34c:	a7b9003c */ 	sh	$t9,0x3c($sp)
/*  f0ed350:	10400004 */ 	beqz	$v0,.L0f0ed364
/*  f0ed354:	87a5003e */ 	lh	$a1,0x3e($sp)
/*  f0ed358:	24abfff6 */ 	addiu	$t3,$a1,-10
/*  f0ed35c:	10000003 */ 	beqz	$zero,.L0f0ed36c
/*  f0ed360:	afab004c */ 	sw	$t3,0x4c($sp)
.L0f0ed364:
/*  f0ed364:	24acffe8 */ 	addiu	$t4,$a1,-24
/*  f0ed368:	afac004c */ 	sw	$t4,0x4c($sp)
.L0f0ed36c:
/*  f0ed36c:	8fad1f98 */ 	lw	$t5,0x1f98($sp)
/*  f0ed370:	0fc3b326 */ 	jal	func0f0ecc98
/*  f0ed374:	91a40001 */ 	lbu	$a0,0x1($t5)
/*  f0ed378:	10400009 */ 	beqz	$v0,.L0f0ed3a0
/*  f0ed37c:	00402825 */ 	or	$a1,$v0,$zero
/*  f0ed380:	3c0f8008 */ 	lui	$t7,%hi(var8007fb0c)
/*  f0ed384:	8deffb0c */ 	lw	$t7,%lo(var8007fb0c)($t7)
/*  f0ed388:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0ed38c:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0ed390:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*  f0ed394:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0ed398:	0fc55d48 */ 	jal	func0f157520
/*  f0ed39c:	afaf0010 */ 	sw	$t7,0x10($sp)
.L0f0ed3a0:
/*  f0ed3a0:	3c0e8008 */ 	lui	$t6,%hi(var8007fb0c)
/*  f0ed3a4:	8dcefb0c */ 	lw	$t6,%lo(var8007fb0c)($t6)
/*  f0ed3a8:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0ed3ac:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0ed3b0:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f0ed3b4:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0ed3b8:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0ed3bc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ed3c0:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ed3c4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ed3c8:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f0ed3cc:	87a9003c */ 	lh	$t1,0x3c($sp)
/*  f0ed3d0:	240bfff6 */ 	addiu	$t3,$zero,-10
/*  f0ed3d4:	03095023 */ 	subu	$t2,$t8,$t1
/*  f0ed3d8:	25480005 */ 	addiu	$t0,$t2,0x5
/*  f0ed3dc:	a6080004 */ 	sh	$t0,0x4($s0)
/*  f0ed3e0:	86190004 */ 	lh	$t9,0x4($s0)
/*  f0ed3e4:	2b21fff6 */ 	slti	$at,$t9,-10
/*  f0ed3e8:	50200003 */ 	beqzl	$at,.L0f0ed3f8
/*  f0ed3ec:	8fac1f9c */ 	lw	$t4,0x1f9c($sp)
/*  f0ed3f0:	a60b0004 */ 	sh	$t3,0x4($s0)
/*  f0ed3f4:	8fac1f9c */ 	lw	$t4,0x1f9c($sp)
.L0f0ed3f8:
/*  f0ed3f8:	8d8d0020 */ 	lw	$t5,0x20($t4)
/*  f0ed3fc:	a60d0006 */ 	sh	$t5,0x6($s0)
.L0f0ed400:
/*  f0ed400:	0fc3c94d */ 	jal	func0f0f2534
/*  f0ed404:	8fa41f98 */ 	lw	$a0,0x1f98($sp)
/*  f0ed408:	10400003 */ 	beqz	$v0,.L0f0ed418
/*  f0ed40c:	8faf1fa4 */ 	lw	$t7,0x1fa4($sp)
/*  f0ed410:	1000003b */ 	beqz	$zero,.L0f0ed500
/*  f0ed414:	a6000000 */ 	sh	$zero,0x0($s0)
.L0f0ed418:
/*  f0ed418:	31ee0002 */ 	andi	$t6,$t7,0x2
/*  f0ed41c:	11c00038 */ 	beqz	$t6,.L0f0ed500
/*  f0ed420:	8fb81fa0 */ 	lw	$t8,0x1fa0($sp)
/*  f0ed424:	83020005 */ 	lb	$v0,0x5($t8)
/*  f0ed428:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0ed42c:	44811000 */ 	mtc1	$at,$f2
/*  f0ed430:	04410006 */ 	bgez	$v0,.L0f0ed44c
/*  f0ed434:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ed438:	44822000 */ 	mtc1	$v0,$f4
/*  f0ed43c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed440:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0ed444:	10000004 */ 	beqz	$zero,.L0f0ed458
/*  f0ed448:	46000007 */ 	neg.s	$f0,$f0
.L0f0ed44c:
/*  f0ed44c:	44823000 */ 	mtc1	$v0,$f6
/*  f0ed450:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed454:	46803020 */ 	cvt.s.w	$f0,$f6
.L0f0ed458:
/*  f0ed458:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0ed45c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0ed460:	8fa81fa0 */ 	lw	$t0,0x1fa0($sp)
/*  f0ed464:	3c0c800a */ 	lui	$t4,%hi(g_Vars)
/*  f0ed468:	45000011 */ 	bc1f	.L0f0ed4b0
/*  f0ed46c:	2418fff6 */ 	addiu	$t8,$zero,-10
/*  f0ed470:	46020201 */ 	sub.s	$f8,$f0,$f2
/*  f0ed474:	44815000 */ 	mtc1	$at,$f10
/*  f0ed478:	3c01800a */ 	lui	$at,0x800a
/*  f0ed47c:	c4309fc4 */ 	lwc1	$f16,-0x603c($at)
/*  f0ed480:	460a4003 */ 	div.s	$f0,$f8,$f10
/*  f0ed484:	46100002 */ 	mul.s	$f0,$f0,$f16
/*  f0ed488:	04430006 */ 	bgezl	$v0,.L0f0ed4a4
/*  f0ed48c:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f0ed490:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f0ed494:	44039000 */ 	mfc1	$v1,$f18
/*  f0ed498:	10000006 */ 	beqz	$zero,.L0f0ed4b4
/*  f0ed49c:	81190009 */ 	lb	$t9,0x9($t0)
/*  f0ed4a0:	4600010d */ 	trunc.w.s	$f4,$f0
.L0f0ed4a4:
/*  f0ed4a4:	44032000 */ 	mfc1	$v1,$f4
/*  f0ed4a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed4ac:	00031823 */ 	negu	$v1,$v1
.L0f0ed4b0:
/*  f0ed4b0:	81190009 */ 	lb	$t9,0x9($t0)
.L0f0ed4b4:
/*  f0ed4b4:	8d8c9fc0 */ 	lw	$t4,%lo(g_Vars)($t4)
/*  f0ed4b8:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f0ed4bc:	00195840 */ 	sll	$t3,$t9,0x1
/*  f0ed4c0:	016c0019 */ 	multu	$t3,$t4
/*  f0ed4c4:	00006812 */ 	mflo	$t5
/*  f0ed4c8:	006d1821 */ 	addu	$v1,$v1,$t5
/*  f0ed4cc:	01e37021 */ 	addu	$t6,$t7,$v1
/*  f0ed4d0:	a60e0000 */ 	sh	$t6,0x0($s0)
/*  f0ed4d4:	86020000 */ 	lh	$v0,0x0($s0)
/*  f0ed4d8:	2841fff6 */ 	slti	$at,$v0,-10
/*  f0ed4dc:	50200004 */ 	beqzl	$at,.L0f0ed4f0
/*  f0ed4e0:	86030004 */ 	lh	$v1,0x4($s0)
/*  f0ed4e4:	a6180000 */ 	sh	$t8,0x0($s0)
/*  f0ed4e8:	86020000 */ 	lh	$v0,0x0($s0)
/*  f0ed4ec:	86030004 */ 	lh	$v1,0x4($s0)
.L0f0ed4f0:
/*  f0ed4f0:	0062082a */ 	slt	$at,$v1,$v0
/*  f0ed4f4:	50200003 */ 	beqzl	$at,.L0f0ed504
/*  f0ed4f8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0ed4fc:	a6030000 */ 	sh	$v1,0x0($s0)
.L0f0ed500:
/*  f0ed500:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0ed504:
/*  f0ed504:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0ed508:	27bd1f98 */ 	addiu	$sp,$sp,0x1f98
/*  f0ed50c:	03e00008 */ 	jr	$ra
/*  f0ed510:	24020001 */ 	addiu	$v0,$zero,0x1
);

GLOBAL_ASM(
glabel func0f0ed514
/*  f0ed514:	240effff */ 	addiu	$t6,$zero,-1
/*  f0ed518:	240ffff6 */ 	addiu	$t7,$zero,-10
/*  f0ed51c:	a48e0006 */ 	sh	$t6,0x6($a0)
/*  f0ed520:	03e00008 */ 	jr	$ra
/*  f0ed524:	a48f0000 */ 	sh	$t7,0x0($a0)
);

GLOBAL_ASM(
glabel func0f0ed528
/*  f0ed528:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f0ed52c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ed530:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0ed534:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0ed538:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f0ed53c:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0ed540:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0ed544:	afae0084 */ 	sw	$t6,0x84($sp)
/*  f0ed548:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0ed54c:	8ca40008 */ 	lw	$a0,0x8($a1)
/*  f0ed550:	3c0f8007 */ 	lui	$t7,%hi(var800711ec)
/*  f0ed554:	3c188008 */ 	lui	$t8,%hi(var8007fb0c)
/*  f0ed558:	3c198008 */ 	lui	$t9,%hi(var8007fb10)
/*  f0ed55c:	95ef11ec */ 	lhu	$t7,%lo(var800711ec)($t7)
/*  f0ed560:	8f18fb0c */ 	lw	$t8,%lo(var8007fb0c)($t8)
/*  f0ed564:	8f39fb10 */ 	lw	$t9,%lo(var8007fb10)($t9)
/*  f0ed568:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f0ed56c:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f0ed570:	a7af0064 */ 	sh	$t7,0x64($sp)
/*  f0ed574:	afb8005c */ 	sw	$t8,0x5c($sp)
/*  f0ed578:	afb90058 */ 	sw	$t9,0x58($sp)
/*  f0ed57c:	8e280008 */ 	lw	$t0,0x8($s1)
/*  f0ed580:	3c0b8008 */ 	lui	$t3,%hi(var8007fb04)
/*  f0ed584:	3c0c8008 */ 	lui	$t4,%hi(var8007fb08)
/*  f0ed588:	8d090004 */ 	lw	$t1,0x4($t0)
/*  f0ed58c:	312a0200 */ 	andi	$t2,$t1,0x200
/*  f0ed590:	11400005 */ 	beqz	$t2,.L0f0ed5a8
/*  f0ed594:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed598:	8d6bfb04 */ 	lw	$t3,%lo(var8007fb04)($t3)
/*  f0ed59c:	8d8cfb08 */ 	lw	$t4,%lo(var8007fb08)($t4)
/*  f0ed5a0:	afab005c */ 	sw	$t3,0x5c($sp)
/*  f0ed5a4:	afac0058 */ 	sw	$t4,0x58($sp)
.L0f0ed5a8:
/*  f0ed5a8:	54400004 */ 	bnezl	$v0,.L0f0ed5bc
/*  f0ed5ac:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0ed5b0:	1000011b */ 	beqz	$zero,.L0f0eda20
/*  f0ed5b4:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f0ed5b8:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0ed5bc:
/*  f0ed5bc:	44803000 */ 	mtc1	$zero,$f6
/*  f0ed5c0:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0ed5c4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ed5c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed5cc:	4502000c */ 	bc1fl	.L0f0ed600
/*  f0ed5d0:	9079003d */ 	lbu	$t9,0x3d($v1)
/*  f0ed5d4:	906d003c */ 	lbu	$t5,0x3c($v1)
/*  f0ed5d8:	2407003c */ 	addiu	$a3,$zero,0x3c
/*  f0ed5dc:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0ed5e0:	01a70019 */ 	multu	$t5,$a3
/*  f0ed5e4:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0ed5e8:	00007012 */ 	mflo	$t6
/*  f0ed5ec:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0ed5f0:	8df80018 */ 	lw	$t8,0x18($t7)
/*  f0ed5f4:	10000012 */ 	beqz	$zero,.L0f0ed640
/*  f0ed5f8:	afb80074 */ 	sw	$t8,0x74($sp)
/*  f0ed5fc:	9079003d */ 	lbu	$t9,0x3d($v1)
.L0f0ed600:
/*  f0ed600:	2407003c */ 	addiu	$a3,$zero,0x3c
/*  f0ed604:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0ed608:	03270019 */ 	multu	$t9,$a3
/*  f0ed60c:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0ed610:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0ed614:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ed618:	00004012 */ 	mflo	$t0
/*  f0ed61c:	00484821 */ 	addu	$t1,$v0,$t0
/*  f0ed620:	8d240018 */ 	lw	$a0,0x18($t1)
/*  f0ed624:	01470019 */ 	multu	$t2,$a3
/*  f0ed628:	00005812 */ 	mflo	$t3
/*  f0ed62c:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f0ed630:	0fc01a40 */ 	jal	func0f006900
/*  f0ed634:	8d850018 */ 	lw	$a1,0x18($t4)
/*  f0ed638:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0ed63c:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0ed640:
/*  f0ed640:	8c6d000c */ 	lw	$t5,0xc($v1)
/*  f0ed644:	51a0000c */ 	beqzl	$t5,.L0f0ed678
/*  f0ed648:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0ed64c:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0ed650:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ed654:	0fc01a40 */ 	jal	func0f006900
/*  f0ed658:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ed65c:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0ed660:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ed664:	00417024 */ 	and	$t6,$v0,$at
/*  f0ed668:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0ed66c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0ed670:	afb90074 */ 	sw	$t9,0x74($sp)
/*  f0ed674:	8fab0084 */ 	lw	$t3,0x84($sp)
.L0f0ed678:
/*  f0ed678:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0ed67c:	86290004 */ 	lh	$t1,0x4($s1)
/*  f0ed680:	956c0000 */ 	lhu	$t4,0x0($t3)
/*  f0ed684:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f0ed688:	01095021 */ 	addu	$t2,$t0,$t1
/*  f0ed68c:	014c6823 */ 	subu	$t5,$t2,$t4
/*  f0ed690:	afad007c */ 	sw	$t5,0x7c($sp)
/*  f0ed694:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0ed698:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f0ed69c:	25ee0002 */ 	addiu	$t6,$t7,0x2
/*  f0ed6a0:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f0ed6a4:	03198021 */ 	addu	$s0,$t8,$t9
/*  f0ed6a8:	92020000 */ 	lbu	$v0,0x0($s0)
.L0f0ed6ac:
/*  f0ed6ac:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0ed6b0:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0ed6b4:	14400003 */ 	bnez	$v0,.L0f0ed6c4
/*  f0ed6b8:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0ed6bc:	10000013 */ 	beqz	$zero,.L0f0ed70c
/*  f0ed6c0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0ed6c4:
/*  f0ed6c4:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*  f0ed6c8:	a3a20064 */ 	sb	$v0,0x64($sp)
/*  f0ed6cc:	8fa70058 */ 	lw	$a3,0x58($sp)
/*  f0ed6d0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ed6d4:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ed6d8:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ed6dc:	8fa9007c */ 	lw	$t1,0x7c($sp)
/*  f0ed6e0:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f0ed6e4:	862a0000 */ 	lh	$t2,0x0($s1)
/*  f0ed6e8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0ed6ec:	012b1821 */ 	addu	$v1,$t1,$t3
/*  f0ed6f0:	0143082a */ 	slt	$at,$t2,$v1
/*  f0ed6f4:	50200004 */ 	beqzl	$at,.L0f0ed708
/*  f0ed6f8:	afa3007c */ 	sw	$v1,0x7c($sp)
/*  f0ed6fc:	10000003 */ 	beqz	$zero,.L0f0ed70c
/*  f0ed700:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ed704:	afa3007c */ 	sw	$v1,0x7c($sp)
.L0f0ed708:
/*  f0ed708:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0ed70c:
/*  f0ed70c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ed710:	5041ffe6 */ 	beql	$v0,$at,.L0f0ed6ac
/*  f0ed714:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0ed718:	3c028008 */ 	lui	$v0,%hi(var8007fac0)
/*  f0ed71c:	8c42fac0 */ 	lw	$v0,%lo(var8007fac0)($v0)
/*  f0ed720:	862c0000 */ 	lh	$t4,0x0($s1)
/*  f0ed724:	3c038007 */ 	lui	$v1,%hi(var80071190)
/*  f0ed728:	24631190 */ 	addiu	$v1,$v1,%lo(var80071190)
/*  f0ed72c:	01820019 */ 	multu	$t4,$v0
/*  f0ed730:	3c048007 */ 	lui	$a0,%hi(var80071194)
/*  f0ed734:	24841194 */ 	addiu	$a0,$a0,%lo(var80071194)
/*  f0ed738:	3c068007 */ 	lui	$a2,%hi(var80071198)
/*  f0ed73c:	24c61198 */ 	addiu	$a2,$a2,%lo(var80071198)
/*  f0ed740:	3c058007 */ 	lui	$a1,%hi(var8007119c)
/*  f0ed744:	24a5119c */ 	addiu	$a1,$a1,%lo(var8007119c)
/*  f0ed748:	00006812 */ 	mflo	$t5
/*  f0ed74c:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0ed750:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0ed754:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0ed758:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0ed75c:	03020019 */ 	multu	$t8,$v0
/*  f0ed760:	0000c812 */ 	mflo	$t9
/*  f0ed764:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f0ed768:	86280002 */ 	lh	$t0,0x2($s1)
/*  f0ed76c:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f0ed770:	862b0006 */ 	lh	$t3,0x6($s1)
/*  f0ed774:	86290002 */ 	lh	$t1,0x2($s1)
/*  f0ed778:	012b5021 */ 	addu	$t2,$t1,$t3
/*  f0ed77c:	254cffff */ 	addiu	$t4,$t2,-1
/*  f0ed780:	05a10002 */ 	bgez	$t5,.L0f0ed78c
/*  f0ed784:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f0ed788:	ac600000 */ 	sw	$zero,0x0($v1)
.L0f0ed78c:
/*  f0ed78c:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0ed790:	05e30003 */ 	bgezl	$t7,.L0f0ed7a0
/*  f0ed794:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f0ed798:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0ed79c:	8cce0000 */ 	lw	$t6,0x0($a2)
.L0f0ed7a0:
/*  f0ed7a0:	05c30003 */ 	bgezl	$t6,.L0f0ed7b0
/*  f0ed7a4:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f0ed7a8:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f0ed7ac:	8cb80000 */ 	lw	$t8,0x0($a1)
.L0f0ed7b0:
/*  f0ed7b0:	07010002 */ 	bgez	$t8,.L0f0ed7bc
/*  f0ed7b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed7b8:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f0ed7bc:
/*  f0ed7bc:	0c002ef1 */ 	jal	func0000bbc4
/*  f0ed7c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed7c4:	3c198007 */ 	lui	$t9,%hi(var80071190)
/*  f0ed7c8:	8f391190 */ 	lw	$t9,%lo(var80071190)($t9)
/*  f0ed7cc:	0059082a */ 	slt	$at,$v0,$t9
/*  f0ed7d0:	10200005 */ 	beqz	$at,.L0f0ed7e8
/*  f0ed7d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed7d8:	0c002ef1 */ 	jal	func0000bbc4
/*  f0ed7dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed7e0:	3c018007 */ 	lui	$at,%hi(var80071190)
/*  f0ed7e4:	ac221190 */ 	sw	$v0,%lo(var80071190)($at)
.L0f0ed7e8:
/*  f0ed7e8:	0c002ef1 */ 	jal	func0000bbc4
/*  f0ed7ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed7f0:	3c088007 */ 	lui	$t0,%hi(var80071194)
/*  f0ed7f4:	8d081194 */ 	lw	$t0,%lo(var80071194)($t0)
/*  f0ed7f8:	0048082a */ 	slt	$at,$v0,$t0
/*  f0ed7fc:	10200005 */ 	beqz	$at,.L0f0ed814
/*  f0ed800:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed804:	0c002ef1 */ 	jal	func0000bbc4
/*  f0ed808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed80c:	3c018007 */ 	lui	$at,%hi(var80071194)
/*  f0ed810:	ac221194 */ 	sw	$v0,%lo(var80071194)($at)
.L0f0ed814:
/*  f0ed814:	0c002ef5 */ 	jal	func0000bbd4
/*  f0ed818:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed81c:	3c098007 */ 	lui	$t1,%hi(var80071198)
/*  f0ed820:	8d291198 */ 	lw	$t1,%lo(var80071198)($t1)
/*  f0ed824:	0049082a */ 	slt	$at,$v0,$t1
/*  f0ed828:	10200005 */ 	beqz	$at,.L0f0ed840
/*  f0ed82c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed830:	0c002ef5 */ 	jal	func0000bbd4
/*  f0ed834:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed838:	3c018007 */ 	lui	$at,%hi(var80071198)
/*  f0ed83c:	ac221198 */ 	sw	$v0,%lo(var80071198)($at)
.L0f0ed840:
/*  f0ed840:	0c002ef5 */ 	jal	func0000bbd4
/*  f0ed844:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed848:	3c068007 */ 	lui	$a2,%hi(var8007119c)
/*  f0ed84c:	24c6119c */ 	addiu	$a2,$a2,%lo(var8007119c)
/*  f0ed850:	8cc50000 */ 	lw	$a1,0x0($a2)
/*  f0ed854:	0045082a */ 	slt	$at,$v0,$a1
/*  f0ed858:	10200009 */ 	beqz	$at,.L0f0ed880
/*  f0ed85c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed860:	0c002ef5 */ 	jal	func0000bbd4
/*  f0ed864:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed868:	3c018007 */ 	lui	$at,%hi(var8007119c)
/*  f0ed86c:	ac22119c */ 	sw	$v0,%lo(var8007119c)($at)
/*  f0ed870:	3c058007 */ 	lui	$a1,%hi(var8007119c)
/*  f0ed874:	3c068007 */ 	lui	$a2,%hi(var8007119c)
/*  f0ed878:	24c6119c */ 	addiu	$a2,$a2,%lo(var8007119c)
/*  f0ed87c:	8ca5119c */ 	lw	$a1,%lo(var8007119c)($a1)
.L0f0ed880:
/*  f0ed880:	3c078007 */ 	lui	$a3,%hi(var80071194)
/*  f0ed884:	3c038007 */ 	lui	$v1,%hi(var80071190)
/*  f0ed888:	8c631190 */ 	lw	$v1,%lo(var80071190)($v1)
/*  f0ed88c:	24e71194 */ 	addiu	$a3,$a3,%lo(var80071194)
/*  f0ed890:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f0ed894:	44834000 */ 	mtc1	$v1,$f8
/*  f0ed898:	3c048007 */ 	lui	$a0,%hi(var80071198)
/*  f0ed89c:	0163082a */ 	slt	$at,$t3,$v1
/*  f0ed8a0:	10200002 */ 	beqz	$at,.L0f0ed8ac
/*  f0ed8a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ed8a8:	ace30000 */ 	sw	$v1,0x0($a3)
.L0f0ed8ac:
/*  f0ed8ac:	8c841198 */ 	lw	$a0,%lo(var80071198)($a0)
/*  f0ed8b0:	00a4082a */ 	slt	$at,$a1,$a0
/*  f0ed8b4:	50200003 */ 	beqzl	$at,.L0f0ed8c4
/*  f0ed8b8:	44842000 */ 	mtc1	$a0,$f4
/*  f0ed8bc:	acc40000 */ 	sw	$a0,0x0($a2)
/*  f0ed8c0:	44842000 */ 	mtc1	$a0,$f4
.L0f0ed8c4:
/*  f0ed8c4:	3c014080 */ 	lui	$at,0x4080
/*  f0ed8c8:	44810000 */ 	mtc1	$at,$f0
/*  f0ed8cc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ed8d0:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f0ed8d4:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ed8d8:	3c01ed00 */ 	lui	$at,0xed00
/*  f0ed8dc:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f0ed8e0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ed8e4:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ed8e8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ed8ec:	440c9000 */ 	mfc1	$t4,$f18
/*  f0ed8f0:	44195000 */ 	mfc1	$t9,$f10
/*  f0ed8f4:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f0ed8f8:	000d7b00 */ 	sll	$t7,$t5,0xc
/*  f0ed8fc:	01e17025 */ 	or	$t6,$t7,$at
/*  f0ed900:	33280fff */ 	andi	$t0,$t9,0xfff
/*  f0ed904:	01c84825 */ 	or	$t1,$t6,$t0
/*  f0ed908:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f0ed90c:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f0ed910:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f0ed914:	448b8000 */ 	mtc1	$t3,$f16
/*  f0ed918:	44984000 */ 	mtc1	$t8,$f8
/*  f0ed91c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ed920:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ed924:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0ed928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed92c:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ed930:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0ed934:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ed938:	440c3000 */ 	mfc1	$t4,$f6
/*  f0ed93c:	440e9000 */ 	mfc1	$t6,$f18
/*  f0ed940:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f0ed944:	000d7b00 */ 	sll	$t7,$t5,0xc
/*  f0ed948:	31c80fff */ 	andi	$t0,$t6,0xfff
/*  f0ed94c:	01e84825 */ 	or	$t1,$t7,$t0
/*  f0ed950:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f0ed954:	0fc54f49 */ 	jal	func0f153d24
/*  f0ed958:	afa50088 */ 	sw	$a1,0x88($sp)
/*  f0ed95c:	8e2b0008 */ 	lw	$t3,0x8($s1)
/*  f0ed960:	8d6a0004 */ 	lw	$t2,0x4($t3)
/*  f0ed964:	314c0800 */ 	andi	$t4,$t2,0x800
/*  f0ed968:	51800009 */ 	beqzl	$t4,.L0f0ed990
/*  f0ed96c:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ed970:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ed974:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0ed978:	2406000e */ 	addiu	$a2,$zero,0xe
/*  f0ed97c:	0fc54f3a */ 	jal	func0f153ce8
/*  f0ed980:	008d2821 */ 	addu	$a1,$a0,$t5
/*  f0ed984:	10000005 */ 	beqz	$zero,.L0f0ed99c
/*  f0ed988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ed98c:	86240000 */ 	lh	$a0,0x0($s1)
.L0f0ed990:
/*  f0ed990:	2406000e */ 	addiu	$a2,$zero,0xe
/*  f0ed994:	0fc54f3a */ 	jal	func0f153ce8
/*  f0ed998:	00802825 */ 	or	$a1,$a0,$zero
.L0f0ed99c:
/*  f0ed99c:	0fc54d8a */ 	jal	func0f153628
/*  f0ed9a0:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f0ed9a4:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f0ed9a8:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*  f0ed9ac:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f0ed9b0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ed9b4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0ed9b8:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0ed9bc:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0ed9c0:	862f0004 */ 	lh	$t7,0x4($s1)
/*  f0ed9c4:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f0ed9c8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ed9cc:	01e84821 */ 	addu	$t1,$t7,$t0
/*  f0ed9d0:	012b5023 */ 	subu	$t2,$t1,$t3
/*  f0ed9d4:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0ed9d8:	862c0006 */ 	lh	$t4,0x6($s1)
/*  f0ed9dc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ed9e0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ed9e4:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f0ed9e8:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f0ed9ec:	02003825 */ 	or	$a3,$s0,$zero
/*  f0ed9f0:	0fc5580f */ 	jal	func0f15603c
/*  f0ed9f4:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0ed9f8:	0fc54de0 */ 	jal	func0f153780
/*  f0ed9fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eda00:	0fc3d43f */ 	jal	func0f0f50fc
/*  f0eda04:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eda08:	0fc54f4f */ 	jal	func0f153d3c
/*  f0eda0c:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0eda10:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0eda14:	8fb80084 */ 	lw	$t8,0x84($sp)
/*  f0eda18:	a70d0004 */ 	sh	$t5,0x4($t8)
/*  f0eda1c:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f0eda20:
/*  f0eda20:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0eda24:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0eda28:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0eda2c:	03e00008 */ 	jr	$ra
/*  f0eda30:	27bd0088 */ 	addiu	$sp,$sp,0x88
);

GLOBAL_ASM(
glabel func0f0eda34
/*  f0eda34:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f0eda38:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0eda3c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0eda40:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0eda44:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f0eda48:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0eda4c:	a7a0003e */ 	sh	$zero,0x3e($sp)
/*  f0eda50:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f0eda54:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f0eda58:	3c088008 */ 	lui	$t0,%hi(var8007fb0c)
/*  f0eda5c:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f0eda60:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0eda64:	97a6003e */ 	lhu	$a2,0x3e($sp)
/*  f0eda68:	31f80200 */ 	andi	$t8,$t7,0x200
/*  f0eda6c:	8d08fb0c */ 	lw	$t0,%lo(var8007fb0c)($t0)
/*  f0eda70:	13000005 */ 	beqz	$t8,.L0f0eda88
/*  f0eda74:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0eda78:	3c088008 */ 	lui	$t0,%hi(var8007fb04)
/*  f0eda7c:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f0eda80:	8d08fb04 */ 	lw	$t0,%lo(var8007fb04)($t0)
/*  f0eda84:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
.L0f0eda88:
/*  f0eda88:	14400003 */ 	bnez	$v0,.L0f0eda98
/*  f0eda8c:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0eda90:	1000002a */ 	beqz	$zero,.L0f0edb3c
/*  f0eda94:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0eda98:
/*  f0eda98:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f0eda9c:	00401825 */ 	or	$v1,$v0,$zero
/*  f0edaa0:	53200009 */ 	beqzl	$t9,.L0f0edac8
/*  f0edaa4:	960a0002 */ 	lhu	$t2,0x2($s0)
/*  f0edaa8:	90440000 */ 	lbu	$a0,0x0($v0)
.L0f0edaac:
/*  f0edaac:	00c43021 */ 	addu	$a2,$a2,$a0
/*  f0edab0:	90640001 */ 	lbu	$a0,0x1($v1)
/*  f0edab4:	30c9ffff */ 	andi	$t1,$a2,0xffff
/*  f0edab8:	01203025 */ 	or	$a2,$t1,$zero
/*  f0edabc:	1480fffb */ 	bnez	$a0,.L0f0edaac
/*  f0edac0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0edac4:	960a0002 */ 	lhu	$t2,0x2($s0)
.L0f0edac8:
/*  f0edac8:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f0edacc:	50ca0004 */ 	beql	$a2,$t2,.L0f0edae0
/*  f0edad0:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f0edad4:	a6000000 */ 	sh	$zero,0x0($s0)
/*  f0edad8:	a6060002 */ 	sh	$a2,0x2($s0)
/*  f0edadc:	8fa60038 */ 	lw	$a2,0x38($sp)
.L0f0edae0:
/*  f0edae0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0edae4:	0fc55cbe */ 	jal	func0f1572f8
/*  f0edae8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0edaec:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0edaf0:	8c429fc0 */ 	lw	$v0,%lo(g_Vars)($v0)
/*  f0edaf4:	960b0004 */ 	lhu	$t3,0x4($s0)
/*  f0edaf8:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0edafc:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f0edb00:	04410003 */ 	bgez	$v0,.L0f0edb10
/*  f0edb04:	00026843 */ 	sra	$t5,$v0,0x1
/*  f0edb08:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0edb0c:	00016843 */ 	sra	$t5,$at,0x1
.L0f0edb10:
/*  f0edb10:	1da00002 */ 	bgtz	$t5,.L0f0edb1c
/*  f0edb14:	01a01025 */ 	or	$v0,$t5,$zero
/*  f0edb18:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0edb1c:
/*  f0edb1c:	960e0000 */ 	lhu	$t6,0x0($s0)
/*  f0edb20:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f0edb24:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*  f0edb28:	0078082a */ 	slt	$at,$v1,$t8
/*  f0edb2c:	10200002 */ 	beqz	$at,.L0f0edb38
/*  f0edb30:	a60f0000 */ 	sh	$t7,0x0($s0)
/*  f0edb34:	a6000000 */ 	sh	$zero,0x0($s0)
.L0f0edb38:
/*  f0edb38:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0edb3c:
/*  f0edb3c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0edb40:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0edb44:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f0edb48:	03e00008 */ 	jr	$ra
/*  f0edb4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0edb50
/*  f0edb50:	240e0032 */ 	addiu	$t6,$zero,0x32
/*  f0edb54:	a4800000 */ 	sh	$zero,0x0($a0)
/*  f0edb58:	a48e0004 */ 	sh	$t6,0x4($a0)
/*  f0edb5c:	03e00008 */ 	jr	$ra
/*  f0edb60:	a4800006 */ 	sh	$zero,0x6($a0)
);

u32 func0f0edb64(u32 arg)
{
	return arg;
}

GLOBAL_ASM(
glabel func0f0edb6c
/*  f0edb6c:	27bdfe50 */ 	addiu	$sp,$sp,-432
/*  f0edb70:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f0edb74:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f0edb78:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f0edb7c:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f0edb80:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f0edb84:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f0edb88:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f0edb8c:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0edb90:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0edb94:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0edb98:	afa401b0 */ 	sw	$a0,0x1b0($sp)
/*  f0edb9c:	afa000a0 */ 	sw	$zero,0xa0($sp)
/*  f0edba0:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0edba4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0edba8:	00a0f025 */ 	or	$s8,$a1,$zero
/*  f0edbac:	afae0098 */ 	sw	$t6,0x98($sp)
/*  f0edbb0:	8caf0008 */ 	lw	$t7,0x8($a1)
/*  f0edbb4:	8df80008 */ 	lw	$t8,0x8($t7)
/*  f0edbb8:	17010006 */ 	bne	$t8,$at,.L0f0edbd4
/*  f0edbbc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0edbc0:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*  f0edbc4:	0fc622a1 */ 	jal	func0f188a84
/*  f0edbc8:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0edbcc:	10000004 */ 	beqz	$zero,.L0f0edbe0
/*  f0edbd0:	afa200bc */ 	sw	$v0,0xbc($sp)
.L0f0edbd4:
/*  f0edbd4:	0fc62179 */ 	jal	func0f1885e4
/*  f0edbd8:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0edbdc:	afa200bc */ 	sw	$v0,0xbc($sp)
.L0f0edbe0:
/*  f0edbe0:	0fc54d8a */ 	jal	func0f153628
/*  f0edbe4:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0edbe8:	8fa800bc */ 	lw	$t0,0xbc($sp)
/*  f0edbec:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0edbf0:	87ca0006 */ 	lh	$t2,0x6($s8)
/*  f0edbf4:	00084880 */ 	sll	$t1,$t0,0x2
/*  f0edbf8:	01284821 */ 	addu	$t1,$t1,$t0
/*  f0edbfc:	00094840 */ 	sll	$t1,$t1,0x1
/*  f0edc00:	012a1823 */ 	subu	$v1,$t1,$t2
/*  f0edc04:	24630012 */ 	addiu	$v1,$v1,0x12
/*  f0edc08:	04610002 */ 	bgez	$v1,.L0f0edc14
/*  f0edc0c:	8fab0098 */ 	lw	$t3,0x98($sp)
/*  f0edc10:	00001825 */ 	or	$v1,$zero,$zero
.L0f0edc14:
/*  f0edc14:	856c0000 */ 	lh	$t4,0x0($t3)
/*  f0edc18:	006c082a */ 	slt	$at,$v1,$t4
/*  f0edc1c:	50200003 */ 	beqzl	$at,.L0f0edc2c
/*  f0edc20:	8fd10010 */ 	lw	$s1,0x10($s8)
/*  f0edc24:	a5630000 */ 	sh	$v1,0x0($t3)
/*  f0edc28:	8fd10010 */ 	lw	$s1,0x10($s8)
.L0f0edc2c:
/*  f0edc2c:	44803000 */ 	mtc1	$zero,$f6
/*  f0edc30:	c6240040 */ 	lwc1	$f4,0x40($s1)
/*  f0edc34:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0edc38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0edc3c:	4502000b */ 	bc1fl	.L0f0edc6c
/*  f0edc40:	9238003d */ 	lbu	$t8,0x3d($s1)
/*  f0edc44:	922d003c */ 	lbu	$t5,0x3c($s1)
/*  f0edc48:	2414003c */ 	addiu	$s4,$zero,0x3c
/*  f0edc4c:	3c137f1b */ 	lui	$s3,%hi(var7f1b1fb0)
/*  f0edc50:	01b40019 */ 	multu	$t5,$s4
/*  f0edc54:	26731fb0 */ 	addiu	$s3,$s3,%lo(var7f1b1fb0)
/*  f0edc58:	00007012 */ 	mflo	$t6
/*  f0edc5c:	026e7821 */ 	addu	$t7,$s3,$t6
/*  f0edc60:	10000012 */ 	beqz	$zero,.L0f0edcac
/*  f0edc64:	8df00018 */ 	lw	$s0,0x18($t7)
/*  f0edc68:	9238003d */ 	lbu	$t8,0x3d($s1)
.L0f0edc6c:
/*  f0edc6c:	2414003c */ 	addiu	$s4,$zero,0x3c
/*  f0edc70:	9229003c */ 	lbu	$t1,0x3c($s1)
/*  f0edc74:	03140019 */ 	multu	$t8,$s4
/*  f0edc78:	3c137f1b */ 	lui	$s3,%hi(var7f1b1fb0)
/*  f0edc7c:	26731fb0 */ 	addiu	$s3,$s3,%lo(var7f1b1fb0)
/*  f0edc80:	8e260044 */ 	lw	$a2,0x44($s1)
/*  f0edc84:	0000c812 */ 	mflo	$t9
/*  f0edc88:	02794021 */ 	addu	$t0,$s3,$t9
/*  f0edc8c:	8d040018 */ 	lw	$a0,0x18($t0)
/*  f0edc90:	01340019 */ 	multu	$t1,$s4
/*  f0edc94:	00005012 */ 	mflo	$t2
/*  f0edc98:	026a6021 */ 	addu	$t4,$s3,$t2
/*  f0edc9c:	0fc01a40 */ 	jal	func0f006900
/*  f0edca0:	8d850018 */ 	lw	$a1,0x18($t4)
/*  f0edca4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0edca8:	8fd10010 */ 	lw	$s1,0x10($s8)
.L0f0edcac:
/*  f0edcac:	8e2b000c */ 	lw	$t3,0xc($s1)
/*  f0edcb0:	11600008 */ 	beqz	$t3,.L0f0edcd4
/*  f0edcb4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0edcb8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0edcbc:	0fc01a40 */ 	jal	func0f006900
/*  f0edcc0:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0edcc4:	2415ff00 */ 	addiu	$s5,$zero,-256
/*  f0edcc8:	00556824 */ 	and	$t5,$v0,$s5
/*  f0edccc:	320e00ff */ 	andi	$t6,$s0,0xff
/*  f0edcd0:	01ae8025 */ 	or	$s0,$t5,$t6
.L0f0edcd4:
/*  f0edcd4:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0edcd8:	2415ff00 */ 	addiu	$s5,$zero,-256
/*  f0edcdc:	15e0002a */ 	bnez	$t7,.L0f0edd88
/*  f0edce0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0edce4:	0fc5b9f1 */ 	jal	langGet
/*  f0edce8:	24045115 */ 	addiu	$a0,$zero,0x5115
/*  f0edcec:	3c128008 */ 	lui	$s2,%hi(var8007fb04)
/*  f0edcf0:	2652fb04 */ 	addiu	$s2,$s2,%lo(var8007fb04)
/*  f0edcf4:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0edcf8:	3c118008 */ 	lui	$s1,%hi(var8007fb08)
/*  f0edcfc:	2631fb08 */ 	addiu	$s1,$s1,%lo(var8007fb08)
/*  f0edd00:	8e270000 */ 	lw	$a3,0x0($s1)
/*  f0edd04:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0edd08:	27a500a8 */ 	addiu	$a1,$sp,0xa8
/*  f0edd0c:	00403025 */ 	or	$a2,$v0,$zero
/*  f0edd10:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0edd14:	0fc55cbe */ 	jal	func0f1572f8
/*  f0edd18:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0edd1c:	87d90000 */ 	lh	$t9,0x0($s8)
/*  f0edd20:	8fa800a8 */ 	lw	$t0,0xa8($sp)
/*  f0edd24:	24045115 */ 	addiu	$a0,$zero,0x5115
/*  f0edd28:	03284823 */ 	subu	$t1,$t9,$t0
/*  f0edd2c:	252a005b */ 	addiu	$t2,$t1,0x5b
/*  f0edd30:	afaa00b4 */ 	sw	$t2,0xb4($sp)
/*  f0edd34:	87cc0002 */ 	lh	$t4,0x2($s8)
/*  f0edd38:	258b0001 */ 	addiu	$t3,$t4,0x1
/*  f0edd3c:	0fc5b9f1 */ 	jal	langGet
/*  f0edd40:	afab00b0 */ 	sw	$t3,0xb0($sp)
/*  f0edd44:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f0edd48:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f0edd4c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0edd50:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0edd54:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0edd58:	87cf0004 */ 	lh	$t7,0x4($s8)
/*  f0edd5c:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0edd60:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0edd64:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0edd68:	87d80006 */ 	lh	$t8,0x6($s8)
/*  f0edd6c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0edd70:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0edd74:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0edd78:	00403825 */ 	or	$a3,$v0,$zero
/*  f0edd7c:	0fc5580f */ 	jal	func0f15603c
/*  f0edd80:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0edd84:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.L0f0edd88:
/*  f0edd88:	3c118008 */ 	lui	$s1,%hi(var8007fb08)
/*  f0edd8c:	3c128008 */ 	lui	$s2,%hi(var8007fb04)
/*  f0edd90:	2652fb04 */ 	addiu	$s2,$s2,%lo(var8007fb04)
/*  f0edd94:	2631fb08 */ 	addiu	$s1,$s1,%lo(var8007fb08)
/*  f0edd98:	0fc5b9f1 */ 	jal	langGet
/*  f0edd9c:	24045116 */ 	addiu	$a0,$zero,0x5116
/*  f0edda0:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f0edda4:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0edda8:	27a500a8 */ 	addiu	$a1,$sp,0xa8
/*  f0eddac:	00403025 */ 	or	$a2,$v0,$zero
/*  f0eddb0:	8e270000 */ 	lw	$a3,0x0($s1)
/*  f0eddb4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eddb8:	0fc55cbe */ 	jal	func0f1572f8
/*  f0eddbc:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0eddc0:	87c80000 */ 	lh	$t0,0x0($s8)
/*  f0eddc4:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*  f0eddc8:	24045116 */ 	addiu	$a0,$zero,0x5116
/*  f0eddcc:	01095023 */ 	subu	$t2,$t0,$t1
/*  f0eddd0:	254c0078 */ 	addiu	$t4,$t2,0x78
/*  f0eddd4:	afac00b4 */ 	sw	$t4,0xb4($sp)
/*  f0eddd8:	87cb0002 */ 	lh	$t3,0x2($s8)
/*  f0edddc:	256d0001 */ 	addiu	$t5,$t3,0x1
/*  f0edde0:	0fc5b9f1 */ 	jal	langGet
/*  f0edde4:	afad00b0 */ 	sw	$t5,0xb0($sp)
/*  f0edde8:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0eddec:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f0eddf0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eddf4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0eddf8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0eddfc:	87d80004 */ 	lh	$t8,0x4($s8)
/*  f0ede00:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0ede04:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0ede08:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0ede0c:	87d90006 */ 	lh	$t9,0x6($s8)
/*  f0ede10:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ede14:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ede18:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0ede1c:	00403825 */ 	or	$a3,$v0,$zero
/*  f0ede20:	0fc5580f */ 	jal	func0f15603c
/*  f0ede24:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0ede28:	0fc54de0 */ 	jal	func0f153780
/*  f0ede2c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ede30:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0ede34:	8fd00010 */ 	lw	$s0,0x10($s8)
/*  f0ede38:	44805000 */ 	mtc1	$zero,$f10
/*  f0ede3c:	c6080040 */ 	lwc1	$f8,0x40($s0)
/*  f0ede40:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0ede44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ede48:	45020008 */ 	bc1fl	.L0f0ede6c
/*  f0ede4c:	920c003d */ 	lbu	$t4,0x3d($s0)
/*  f0ede50:	9208003c */ 	lbu	$t0,0x3c($s0)
/*  f0ede54:	01140019 */ 	multu	$t0,$s4
/*  f0ede58:	00004812 */ 	mflo	$t1
/*  f0ede5c:	02695021 */ 	addu	$t2,$s3,$t1
/*  f0ede60:	1000000e */ 	beqz	$zero,.L0f0ede9c
/*  f0ede64:	8d520000 */ 	lw	$s2,0x0($t2)
/*  f0ede68:	920c003d */ 	lbu	$t4,0x3d($s0)
.L0f0ede6c:
/*  f0ede6c:	920e003c */ 	lbu	$t6,0x3c($s0)
/*  f0ede70:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0ede74:	01940019 */ 	multu	$t4,$s4
/*  f0ede78:	00005812 */ 	mflo	$t3
/*  f0ede7c:	026b6821 */ 	addu	$t5,$s3,$t3
/*  f0ede80:	8da40000 */ 	lw	$a0,0x0($t5)
/*  f0ede84:	01d40019 */ 	multu	$t6,$s4
/*  f0ede88:	00007812 */ 	mflo	$t7
/*  f0ede8c:	026fc021 */ 	addu	$t8,$s3,$t7
/*  f0ede90:	0fc01a40 */ 	jal	func0f006900
/*  f0ede94:	8f050000 */ 	lw	$a1,0x0($t8)
/*  f0ede98:	00409025 */ 	or	$s2,$v0,$zero
.L0f0ede9c:
/*  f0ede9c:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f0edea0:	13200007 */ 	beqz	$t9,.L0f0edec0
/*  f0edea4:	02402025 */ 	or	$a0,$s2,$zero
/*  f0edea8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0edeac:	0fc01a40 */ 	jal	func0f006900
/*  f0edeb0:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0edeb4:	00554024 */ 	and	$t0,$v0,$s5
/*  f0edeb8:	324900ff */ 	andi	$t1,$s2,0xff
/*  f0edebc:	01099025 */ 	or	$s2,$t0,$t1
.L0f0edec0:
/*  f0edec0:	c6100040 */ 	lwc1	$f16,0x40($s0)
/*  f0edec4:	44809000 */ 	mtc1	$zero,$f18
/*  f0edec8:	920a003c */ 	lbu	$t2,0x3c($s0)
/*  f0edecc:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0eded0:	000a6100 */ 	sll	$t4,$t2,0x4
/*  f0eded4:	018a6023 */ 	subu	$t4,$t4,$t2
/*  f0eded8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0ededc:	45000004 */ 	bc1f	.L0f0edef0
/*  f0edee0:	026c1021 */ 	addu	$v0,$s3,$t4
/*  f0edee4:	8c510008 */ 	lw	$s1,0x8($v0)
/*  f0edee8:	1000000b */ 	beqz	$zero,.L0f0edf18
/*  f0edeec:	8e03000c */ 	lw	$v1,0xc($s0)
.L0f0edef0:
/*  f0edef0:	920b003d */ 	lbu	$t3,0x3d($s0)
/*  f0edef4:	8c450008 */ 	lw	$a1,0x8($v0)
/*  f0edef8:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0edefc:	01740019 */ 	multu	$t3,$s4
/*  f0edf00:	00006812 */ 	mflo	$t5
/*  f0edf04:	026d7021 */ 	addu	$t6,$s3,$t5
/*  f0edf08:	0fc01a40 */ 	jal	func0f006900
/*  f0edf0c:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f0edf10:	00408825 */ 	or	$s1,$v0,$zero
/*  f0edf14:	8e03000c */ 	lw	$v1,0xc($s0)
.L0f0edf18:
/*  f0edf18:	10600004 */ 	beqz	$v1,.L0f0edf2c
/*  f0edf1c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0edf20:	00002825 */ 	or	$a1,$zero,$zero
/*  f0edf24:	0fc01a40 */ 	jal	func0f006900
/*  f0edf28:	2406002c */ 	addiu	$a2,$zero,0x2c
.L0f0edf2c:
/*  f0edf2c:	87c50002 */ 	lh	$a1,0x2($s8)
/*  f0edf30:	87c40000 */ 	lh	$a0,0x0($s8)
/*  f0edf34:	2406ff7f */ 	addiu	$a2,$zero,-129
/*  f0edf38:	0fc54fa5 */ 	jal	func0f153e94
/*  f0edf3c:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0edf40:	87c90000 */ 	lh	$t1,0x0($s8)
/*  f0edf44:	87ca0004 */ 	lh	$t2,0x4($s8)
/*  f0edf48:	87c50002 */ 	lh	$a1,0x2($s8)
/*  f0edf4c:	305900ff */ 	andi	$t9,$v0,0xff
/*  f0edf50:	02554024 */ 	and	$t0,$s2,$s5
/*  f0edf54:	03289025 */ 	or	$s2,$t9,$t0
/*  f0edf58:	2406ff7f */ 	addiu	$a2,$zero,-129
/*  f0edf5c:	012a2021 */ 	addu	$a0,$t1,$t2
/*  f0edf60:	0fc54fa5 */ 	jal	func0f153e94
/*  f0edf64:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0edf68:	87c30002 */ 	lh	$v1,0x2($s8)
/*  f0edf6c:	87c50000 */ 	lh	$a1,0x0($s8)
/*  f0edf70:	87cc0004 */ 	lh	$t4,0x4($s8)
/*  f0edf74:	246b000a */ 	addiu	$t3,$v1,0xa
/*  f0edf78:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0edf7c:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0edf80:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0edf84:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0edf88:	24660009 */ 	addiu	$a2,$v1,0x9
/*  f0edf8c:	0fc38bd7 */ 	jal	func0f0e2f5c
/*  f0edf90:	00ac3821 */ 	addu	$a3,$a1,$t4
/*  f0edf94:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f0edf98:	afad01b0 */ 	sw	$t5,0x1b0($sp)
/*  f0edf9c:	3c0ee700 */ 	lui	$t6,0xe700
/*  f0edfa0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0edfa4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0edfa8:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0edfac:	8c63fac0 */ 	lw	$v1,%lo(var8007fac0)($v1)
/*  f0edfb0:	87cf0000 */ 	lh	$t7,0x0($s8)
/*  f0edfb4:	3c128007 */ 	lui	$s2,%hi(var80071190)
/*  f0edfb8:	26521190 */ 	addiu	$s2,$s2,%lo(var80071190)
/*  f0edfbc:	01e30019 */ 	multu	$t7,$v1
/*  f0edfc0:	3c108007 */ 	lui	$s0,%hi(var80071194)
/*  f0edfc4:	26101194 */ 	addiu	$s0,$s0,%lo(var80071194)
/*  f0edfc8:	3c138007 */ 	lui	$s3,%hi(var80071198)
/*  f0edfcc:	26731198 */ 	addiu	$s3,$s3,%lo(var80071198)
/*  f0edfd0:	3c118007 */ 	lui	$s1,%hi(var8007119c)
/*  f0edfd4:	2631119c */ 	addiu	$s1,$s1,%lo(var8007119c)
/*  f0edfd8:	0000c012 */ 	mflo	$t8
/*  f0edfdc:	ae580000 */ 	sw	$t8,0x0($s2)
/*  f0edfe0:	87c80004 */ 	lh	$t0,0x4($s8)
/*  f0edfe4:	87d90000 */ 	lh	$t9,0x0($s8)
/*  f0edfe8:	03284821 */ 	addu	$t1,$t9,$t0
/*  f0edfec:	01230019 */ 	multu	$t1,$v1
/*  f0edff0:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f0edff4:	00005012 */ 	mflo	$t2
/*  f0edff8:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f0edffc:	87cc0002 */ 	lh	$t4,0x2($s8)
/*  f0ee000:	258b000a */ 	addiu	$t3,$t4,0xa
/*  f0ee004:	ae6b0000 */ 	sw	$t3,0x0($s3)
/*  f0ee008:	87ce0006 */ 	lh	$t6,0x6($s8)
/*  f0ee00c:	87cd0002 */ 	lh	$t5,0x2($s8)
/*  f0ee010:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0ee014:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f0ee018:	07210002 */ 	bgez	$t9,.L0f0ee024
/*  f0ee01c:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f0ee020:	ae400000 */ 	sw	$zero,0x0($s2)
.L0f0ee024:
/*  f0ee024:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f0ee028:	05030003 */ 	bgezl	$t0,.L0f0ee038
/*  f0ee02c:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f0ee030:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f0ee034:	8e690000 */ 	lw	$t1,0x0($s3)
.L0f0ee038:
/*  f0ee038:	05230003 */ 	bgezl	$t1,.L0f0ee048
/*  f0ee03c:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f0ee040:	ae600000 */ 	sw	$zero,0x0($s3)
/*  f0ee044:	8e2a0000 */ 	lw	$t2,0x0($s1)
.L0f0ee048:
/*  f0ee048:	05410002 */ 	bgez	$t2,.L0f0ee054
/*  f0ee04c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee050:	ae200000 */ 	sw	$zero,0x0($s1)
.L0f0ee054:
/*  f0ee054:	0c002ef1 */ 	jal	func0000bbc4
/*  f0ee058:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee05c:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f0ee060:	004c082a */ 	slt	$at,$v0,$t4
/*  f0ee064:	10200004 */ 	beqz	$at,.L0f0ee078
/*  f0ee068:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee06c:	0c002ef1 */ 	jal	func0000bbc4
/*  f0ee070:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee074:	ae420000 */ 	sw	$v0,0x0($s2)
.L0f0ee078:
/*  f0ee078:	0c002ef1 */ 	jal	func0000bbc4
/*  f0ee07c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee080:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f0ee084:	004b082a */ 	slt	$at,$v0,$t3
/*  f0ee088:	10200004 */ 	beqz	$at,.L0f0ee09c
/*  f0ee08c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee090:	0c002ef1 */ 	jal	func0000bbc4
/*  f0ee094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee098:	ae020000 */ 	sw	$v0,0x0($s0)
.L0f0ee09c:
/*  f0ee09c:	0c002ef5 */ 	jal	func0000bbd4
/*  f0ee0a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee0a4:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f0ee0a8:	004d082a */ 	slt	$at,$v0,$t5
/*  f0ee0ac:	10200004 */ 	beqz	$at,.L0f0ee0c0
/*  f0ee0b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee0b4:	0c002ef5 */ 	jal	func0000bbd4
/*  f0ee0b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee0bc:	ae620000 */ 	sw	$v0,0x0($s3)
.L0f0ee0c0:
/*  f0ee0c0:	0c002ef5 */ 	jal	func0000bbd4
/*  f0ee0c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee0c8:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f0ee0cc:	0044082a */ 	slt	$at,$v0,$a0
/*  f0ee0d0:	50200006 */ 	beqzl	$at,.L0f0ee0ec
/*  f0ee0d4:	8e430000 */ 	lw	$v1,0x0($s2)
/*  f0ee0d8:	0c002ef5 */ 	jal	func0000bbd4
/*  f0ee0dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee0e0:	ae220000 */ 	sw	$v0,0x0($s1)
/*  f0ee0e4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ee0e8:	8e430000 */ 	lw	$v1,0x0($s2)
.L0f0ee0ec:
/*  f0ee0ec:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0ee0f0:	44832000 */ 	mtc1	$v1,$f4
/*  f0ee0f4:	01c3082a */ 	slt	$at,$t6,$v1
/*  f0ee0f8:	10200002 */ 	beqz	$at,.L0f0ee104
/*  f0ee0fc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ee100:	ae030000 */ 	sw	$v1,0x0($s0)
.L0f0ee104:
/*  f0ee104:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f0ee108:	0085082a */ 	slt	$at,$a0,$a1
/*  f0ee10c:	50200003 */ 	beqzl	$at,.L0f0ee11c
/*  f0ee110:	44858000 */ 	mtc1	$a1,$f16
/*  f0ee114:	ae250000 */ 	sw	$a1,0x0($s1)
/*  f0ee118:	44858000 */ 	mtc1	$a1,$f16
.L0f0ee11c:
/*  f0ee11c:	3c014080 */ 	lui	$at,0x4080
/*  f0ee120:	44810000 */ 	mtc1	$at,$f0
/*  f0ee124:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ee128:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0ee12c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ee130:	3c01ed00 */ 	lui	$at,0xed00
/*  f0ee134:	24580008 */ 	addiu	$t8,$v0,0x8
/*  f0ee138:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0ee13c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0ee140:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ee144:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0ee148:	44085000 */ 	mfc1	$t0,$f10
/*  f0ee14c:	440d3000 */ 	mfc1	$t5,$f6
/*  f0ee150:	31090fff */ 	andi	$t1,$t0,0xfff
/*  f0ee154:	00095300 */ 	sll	$t2,$t1,0xc
/*  f0ee158:	01416025 */ 	or	$t4,$t2,$at
/*  f0ee15c:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f0ee160:	018e7825 */ 	or	$t7,$t4,$t6
/*  f0ee164:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0ee168:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0ee16c:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f0ee170:	44984000 */ 	mtc1	$t8,$f8
/*  f0ee174:	448b2000 */ 	mtc1	$t3,$f4
/*  f0ee178:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ee17c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ee180:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ee184:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee188:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ee18c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ee190:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ee194:	44089000 */ 	mfc1	$t0,$f18
/*  f0ee198:	440c5000 */ 	mfc1	$t4,$f10
/*  f0ee19c:	31090fff */ 	andi	$t1,$t0,0xfff
/*  f0ee1a0:	00095300 */ 	sll	$t2,$t1,0xc
/*  f0ee1a4:	318e0fff */ 	andi	$t6,$t4,0xfff
/*  f0ee1a8:	014e7825 */ 	or	$t7,$t2,$t6
/*  f0ee1ac:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0ee1b0:	0fc54d8a */ 	jal	func0f153628
/*  f0ee1b4:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0ee1b8:	8fa300bc */ 	lw	$v1,0xbc($sp)
/*  f0ee1bc:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0ee1c0:	0000b825 */ 	or	$s7,$zero,$zero
/*  f0ee1c4:	186000dd */ 	blez	$v1,.L0f0ee53c
/*  f0ee1c8:	27b100c0 */ 	addiu	$s1,$sp,0xc0
/*  f0ee1cc:	3c148008 */ 	lui	$s4,%hi(var8007fb0c)
/*  f0ee1d0:	3c138008 */ 	lui	$s3,%hi(var8007fb10)
/*  f0ee1d4:	2673fb10 */ 	addiu	$s3,$s3,%lo(var8007fb10)
/*  f0ee1d8:	2694fb0c */ 	addiu	$s4,$s4,%lo(var8007fb0c)
/*  f0ee1dc:	0000b025 */ 	or	$s6,$zero,$zero
/*  f0ee1e0:	27b50074 */ 	addiu	$s5,$sp,0x74
.L0f0ee1e4:
/*  f0ee1e4:	8fa300bc */ 	lw	$v1,0xbc($sp)
/*  f0ee1e8:	3c040088 */ 	lui	$a0,0x88
/*  f0ee1ec:	00009025 */ 	or	$s2,$zero,$zero
/*  f0ee1f0:	28610002 */ 	slti	$at,$v1,0x2
/*  f0ee1f4:	1420002d */ 	bnez	$at,.L0f0ee2ac
/*  f0ee1f8:	348488ff */ 	ori	$a0,$a0,0x88ff
/*  f0ee1fc:	2478ffff */ 	addiu	$t8,$v1,-1
/*  f0ee200:	44982000 */ 	mtc1	$t8,$f4
/*  f0ee204:	44978000 */ 	mtc1	$s7,$f16
/*  f0ee208:	3c01437f */ 	lui	$at,0x437f
/*  f0ee20c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ee210:	44815000 */ 	mtc1	$at,$f10
/*  f0ee214:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0ee218:	3c014f00 */ 	lui	$at,0x4f00
/*  f0ee21c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ee220:	46069203 */ 	div.s	$f8,$f18,$f6
/*  f0ee224:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0ee228:	4459f800 */ 	cfc1	$t9,$31
/*  f0ee22c:	44d2f800 */ 	ctc1	$s2,$31
/*  f0ee230:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee234:	46008124 */ 	cvt.w.s	$f4,$f16
/*  f0ee238:	4452f800 */ 	cfc1	$s2,$31
/*  f0ee23c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee240:	32520078 */ 	andi	$s2,$s2,0x78
/*  f0ee244:	52400013 */ 	beqzl	$s2,.L0f0ee294
/*  f0ee248:	44122000 */ 	mfc1	$s2,$f4
/*  f0ee24c:	44812000 */ 	mtc1	$at,$f4
/*  f0ee250:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0ee254:	46048101 */ 	sub.s	$f4,$f16,$f4
/*  f0ee258:	44d2f800 */ 	ctc1	$s2,$31
/*  f0ee25c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee260:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0ee264:	4452f800 */ 	cfc1	$s2,$31
/*  f0ee268:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee26c:	32520078 */ 	andi	$s2,$s2,0x78
/*  f0ee270:	16400005 */ 	bnez	$s2,.L0f0ee288
/*  f0ee274:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee278:	44122000 */ 	mfc1	$s2,$f4
/*  f0ee27c:	3c018000 */ 	lui	$at,0x8000
/*  f0ee280:	10000007 */ 	beqz	$zero,.L0f0ee2a0
/*  f0ee284:	02419025 */ 	or	$s2,$s2,$at
.L0f0ee288:
/*  f0ee288:	10000005 */ 	beqz	$zero,.L0f0ee2a0
/*  f0ee28c:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f0ee290:	44122000 */ 	mfc1	$s2,$f4
.L0f0ee294:
/*  f0ee294:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee298:	0640fffb */ 	bltz	$s2,.L0f0ee288
/*  f0ee29c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ee2a0:
/*  f0ee2a0:	44d9f800 */ 	ctc1	$t9,$31
/*  f0ee2a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee2a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ee2ac:
/*  f0ee2ac:	3c0500ff */ 	lui	$a1,0xff
/*  f0ee2b0:	34a5ffff */ 	ori	$a1,$a1,0xffff
/*  f0ee2b4:	0fc01a40 */ 	jal	func0f006900
/*  f0ee2b8:	02403025 */ 	or	$a2,$s2,$zero
/*  f0ee2bc:	87c80000 */ 	lh	$t0,0x0($s8)
/*  f0ee2c0:	8fac0098 */ 	lw	$t4,0x98($sp)
/*  f0ee2c4:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0ee2c8:	25090005 */ 	addiu	$t1,$t0,0x5
/*  f0ee2cc:	afa900b4 */ 	sw	$t1,0xb4($sp)
/*  f0ee2d0:	87cb0002 */ 	lh	$t3,0x2($s8)
/*  f0ee2d4:	858a0000 */ 	lh	$t2,0x0($t4)
/*  f0ee2d8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0ee2dc:	01766821 */ 	addu	$t5,$t3,$s6
/*  f0ee2e0:	01aa7023 */ 	subu	$t6,$t5,$t2
/*  f0ee2e4:	25cf000e */ 	addiu	$t7,$t6,0xe
/*  f0ee2e8:	13000019 */ 	beqz	$t8,.L0f0ee350
/*  f0ee2ec:	afaf00b0 */ 	sw	$t7,0xb0($sp)
/*  f0ee2f0:	8e390004 */ 	lw	$t9,0x4($s1)
/*  f0ee2f4:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f0ee2f8:	8e8c0000 */ 	lw	$t4,0x0($s4)
/*  f0ee2fc:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0ee300:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ee304:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0ee308:	87cd0004 */ 	lh	$t5,0x4($s8)
/*  f0ee30c:	00194080 */ 	sll	$t0,$t9,0x2
/*  f0ee310:	3c09800b */ 	lui	$t1,%hi(g_MpSetup+0x28)
/*  f0ee314:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0ee318:	87ca0006 */ 	lh	$t2,0x6($s8)
/*  f0ee31c:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0ee320:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ee324:	2529cbb0 */ 	addiu	$t1,$t1,%lo(g_MpSetup+0x28)
/*  f0ee328:	01093821 */ 	addu	$a3,$t0,$t1
/*  f0ee32c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ee330:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ee334:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0ee338:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0ee33c:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0ee340:	0fc5580f */ 	jal	func0f15603c
/*  f0ee344:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0ee348:	10000012 */ 	beqz	$zero,.L0f0ee394
/*  f0ee34c:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.L0f0ee350:
/*  f0ee350:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0ee354:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f0ee358:	8e270000 */ 	lw	$a3,0x0($s1)
/*  f0ee35c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ee360:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ee364:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0ee368:	87d80004 */ 	lh	$t8,0x4($s8)
/*  f0ee36c:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0ee370:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0ee374:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0ee378:	87d90006 */ 	lh	$t9,0x6($s8)
/*  f0ee37c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ee380:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ee384:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0ee388:	0fc5580f */ 	jal	func0f15603c
/*  f0ee38c:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0ee390:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.L0f0ee394:
/*  f0ee394:	8fa800a0 */ 	lw	$t0,0xa0($sp)
/*  f0ee398:	3c04cf00 */ 	lui	$a0,0xcf00
/*  f0ee39c:	348400ff */ 	ori	$a0,$a0,0xff
/*  f0ee3a0:	15000030 */ 	bnez	$t0,.L0f0ee464
/*  f0ee3a4:	3c05ff40 */ 	lui	$a1,0xff40
/*  f0ee3a8:	34a540ff */ 	ori	$a1,$a1,0x40ff
/*  f0ee3ac:	0fc01a40 */ 	jal	func0f006900
/*  f0ee3b0:	02403025 */ 	or	$a2,$s2,$zero
/*  f0ee3b4:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f0ee3b8:	3c057f1b */ 	lui	$a1,%hi(var7f1b1e44)
/*  f0ee3bc:	00408025 */ 	or	$s0,$v0,$zero
/*  f0ee3c0:	24a51e44 */ 	addiu	$a1,$a1,%lo(var7f1b1e44)
/*  f0ee3c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0ee3c8:	0c004dad */ 	jal	sprintf
/*  f0ee3cc:	8526003c */ 	lh	$a2,0x3c($t1)
/*  f0ee3d0:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f0ee3d4:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0ee3d8:	27a500a8 */ 	addiu	$a1,$sp,0xa8
/*  f0ee3dc:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0ee3e0:	8e670000 */ 	lw	$a3,0x0($s3)
/*  f0ee3e4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ee3e8:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ee3ec:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ee3f0:	87cc0000 */ 	lh	$t4,0x0($s8)
/*  f0ee3f4:	8fad00a8 */ 	lw	$t5,0xa8($sp)
/*  f0ee3f8:	8fb90098 */ 	lw	$t9,0x98($sp)
/*  f0ee3fc:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0ee400:	018d5023 */ 	subu	$t2,$t4,$t5
/*  f0ee404:	254e005b */ 	addiu	$t6,$t2,0x5b
/*  f0ee408:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*  f0ee40c:	87cf0002 */ 	lh	$t7,0x2($s8)
/*  f0ee410:	87280000 */ 	lh	$t0,0x0($t9)
/*  f0ee414:	8e8d0000 */ 	lw	$t5,0x0($s4)
/*  f0ee418:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f0ee41c:	01f6c021 */ 	addu	$t8,$t7,$s6
/*  f0ee420:	03084823 */ 	subu	$t1,$t8,$t0
/*  f0ee424:	252b000e */ 	addiu	$t3,$t1,0xe
/*  f0ee428:	afab00b0 */ 	sw	$t3,0xb0($sp)
/*  f0ee42c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ee430:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ee434:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ee438:	87ca0004 */ 	lh	$t2,0x4($s8)
/*  f0ee43c:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0ee440:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0ee444:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0ee448:	87ce0006 */ 	lh	$t6,0x6($s8)
/*  f0ee44c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ee450:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ee454:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0ee458:	0fc5580f */ 	jal	func0f15603c
/*  f0ee45c:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f0ee460:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.L0f0ee464:
/*  f0ee464:	3c04009f */ 	lui	$a0,0x9f
/*  f0ee468:	3c0500ff */ 	lui	$a1,0xff
/*  f0ee46c:	34a500ff */ 	ori	$a1,$a1,0xff
/*  f0ee470:	348400ff */ 	ori	$a0,$a0,0xff
/*  f0ee474:	0fc01a40 */ 	jal	func0f006900
/*  f0ee478:	02403025 */ 	or	$a2,$s2,$zero
/*  f0ee47c:	3c057f1b */ 	lui	$a1,%hi(var7f1b1e48)
/*  f0ee480:	00408025 */ 	or	$s0,$v0,$zero
/*  f0ee484:	24a51e48 */ 	addiu	$a1,$a1,%lo(var7f1b1e48)
/*  f0ee488:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0ee48c:	0c004dad */ 	jal	sprintf
/*  f0ee490:	8e260010 */ 	lw	$a2,0x10($s1)
/*  f0ee494:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f0ee498:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0ee49c:	27a500a8 */ 	addiu	$a1,$sp,0xa8
/*  f0ee4a0:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0ee4a4:	8e670000 */ 	lw	$a3,0x0($s3)
/*  f0ee4a8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ee4ac:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ee4b0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ee4b4:	87d90000 */ 	lh	$t9,0x0($s8)
/*  f0ee4b8:	8fb800a8 */ 	lw	$t8,0xa8($sp)
/*  f0ee4bc:	8fad0098 */ 	lw	$t5,0x98($sp)
/*  f0ee4c0:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0ee4c4:	03384023 */ 	subu	$t0,$t9,$t8
/*  f0ee4c8:	25090078 */ 	addiu	$t1,$t0,0x78
/*  f0ee4cc:	afa900b4 */ 	sw	$t1,0xb4($sp)
/*  f0ee4d0:	87cb0002 */ 	lh	$t3,0x2($s8)
/*  f0ee4d4:	85aa0000 */ 	lh	$t2,0x0($t5)
/*  f0ee4d8:	8e980000 */ 	lw	$t8,0x0($s4)
/*  f0ee4dc:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0ee4e0:	01766021 */ 	addu	$t4,$t3,$s6
/*  f0ee4e4:	018a7023 */ 	subu	$t6,$t4,$t2
/*  f0ee4e8:	25cf000e */ 	addiu	$t7,$t6,0xe
/*  f0ee4ec:	afaf00b0 */ 	sw	$t7,0xb0($sp)
/*  f0ee4f0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ee4f4:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0ee4f8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ee4fc:	87c80004 */ 	lh	$t0,0x4($s8)
/*  f0ee500:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0ee504:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0ee508:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0ee50c:	87c90006 */ 	lh	$t1,0x6($s8)
/*  f0ee510:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ee514:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ee518:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0ee51c:	0fc5580f */ 	jal	func0f15603c
/*  f0ee520:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f0ee524:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f0ee528:	26f70001 */ 	addiu	$s7,$s7,0x1
/*  f0ee52c:	26310014 */ 	addiu	$s1,$s1,0x14
/*  f0ee530:	26d6000a */ 	addiu	$s6,$s6,0xa
/*  f0ee534:	16ebff2b */ 	bne	$s7,$t3,.L0f0ee1e4
/*  f0ee538:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.L0f0ee53c:
/*  f0ee53c:	0fc54de0 */ 	jal	func0f153780
/*  f0ee540:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0ee544:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f0ee548:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ee54c:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0ee550:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0ee554:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f0ee558:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f0ee55c:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f0ee560:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f0ee564:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f0ee568:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f0ee56c:	03e00008 */ 	jr	$ra
/*  f0ee570:	27bd01b0 */ 	addiu	$sp,$sp,0x1b0
);

GLOBAL_ASM(
glabel func0f0ee574
/*  f0ee574:	30ae0002 */ 	andi	$t6,$a1,0x2
/*  f0ee578:	11c0002f */ 	beqz	$t6,.L0f0ee638
/*  f0ee57c:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0ee580:	80830005 */ 	lb	$v1,0x5($a0)
/*  f0ee584:	44811000 */ 	mtc1	$at,$f2
/*  f0ee588:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ee58c:	04610006 */ 	bgez	$v1,.L0f0ee5a8
/*  f0ee590:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0ee594:	44832000 */ 	mtc1	$v1,$f4
/*  f0ee598:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee59c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0ee5a0:	10000004 */ 	beqz	$zero,.L0f0ee5b4
/*  f0ee5a4:	46000007 */ 	neg.s	$f0,$f0
.L0f0ee5a8:
/*  f0ee5a8:	44833000 */ 	mtc1	$v1,$f6
/*  f0ee5ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee5b0:	46803020 */ 	cvt.s.w	$f0,$f6
.L0f0ee5b4:
/*  f0ee5b4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0ee5b8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0ee5bc:	45020012 */ 	bc1fl	.L0f0ee608
/*  f0ee5c0:	80990009 */ 	lb	$t9,0x9($a0)
/*  f0ee5c4:	46020201 */ 	sub.s	$f8,$f0,$f2
/*  f0ee5c8:	44815000 */ 	mtc1	$at,$f10
/*  f0ee5cc:	3c01800a */ 	lui	$at,0x800a
/*  f0ee5d0:	c4309fc4 */ 	lwc1	$f16,-0x603c($at)
/*  f0ee5d4:	460a4003 */ 	div.s	$f0,$f8,$f10
/*  f0ee5d8:	46100002 */ 	mul.s	$f0,$f0,$f16
/*  f0ee5dc:	04630006 */ 	bgezl	$v1,.L0f0ee5f8
/*  f0ee5e0:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f0ee5e4:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f0ee5e8:	44029000 */ 	mfc1	$v0,$f18
/*  f0ee5ec:	10000006 */ 	beqz	$zero,.L0f0ee608
/*  f0ee5f0:	80990009 */ 	lb	$t9,0x9($a0)
/*  f0ee5f4:	4600010d */ 	trunc.w.s	$f4,$f0
.L0f0ee5f8:
/*  f0ee5f8:	44022000 */ 	mfc1	$v0,$f4
/*  f0ee5fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee600:	00021023 */ 	negu	$v0,$v0
/*  f0ee604:	80990009 */ 	lb	$t9,0x9($a0)
.L0f0ee608:
/*  f0ee608:	8d299fc0 */ 	lw	$t1,%lo(g_Vars)($t1)
/*  f0ee60c:	84cb0000 */ 	lh	$t3,0x0($a2)
/*  f0ee610:	00194040 */ 	sll	$t0,$t9,0x1
/*  f0ee614:	01090019 */ 	multu	$t0,$t1
/*  f0ee618:	00005012 */ 	mflo	$t2
/*  f0ee61c:	004a1021 */ 	addu	$v0,$v0,$t2
/*  f0ee620:	01626021 */ 	addu	$t4,$t3,$v0
/*  f0ee624:	a4cc0000 */ 	sh	$t4,0x0($a2)
/*  f0ee628:	84cd0000 */ 	lh	$t5,0x0($a2)
/*  f0ee62c:	05a10002 */ 	bgez	$t5,.L0f0ee638
/*  f0ee630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee634:	a4c00000 */ 	sh	$zero,0x0($a2)
.L0f0ee638:
/*  f0ee638:	03e00008 */ 	jr	$ra
/*  f0ee63c:	24020001 */ 	addiu	$v0,$zero,0x1
);

GLOBAL_ASM(
glabel func0f0ee640
/*  f0ee640:	03e00008 */ 	jr	$ra
/*  f0ee644:	a4800000 */ 	sh	$zero,0x0($a0)
);

GLOBAL_ASM(
glabel func0f0ee648
/*  f0ee648:	27bdff38 */ 	addiu	$sp,$sp,-200
/*  f0ee64c:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0ee650:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0ee654:	3c18800a */ 	lui	$t8,%hi(var8009deb0)
/*  f0ee658:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f0ee65c:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f0ee660:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f0ee664:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f0ee668:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f0ee66c:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f0ee670:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f0ee674:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0ee678:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0ee67c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0ee680:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0ee684:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0ee688:	9318deb0 */ 	lbu	$t8,%lo(var8009deb0)($t8)
/*  f0ee68c:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0ee690:	0080a025 */ 	or	$s4,$a0,$zero
/*  f0ee694:	afae00c4 */ 	sw	$t6,0xc4($sp)
/*  f0ee698:	0fc6321f */ 	jal	func0f18c87c
/*  f0ee69c:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f0ee6a0:	8fa300b4 */ 	lw	$v1,0xb4($sp)
/*  f0ee6a4:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0ee6a8:	28610004 */ 	slti	$at,$v1,0x4
/*  f0ee6ac:	10200008 */ 	beqz	$at,.L0f0ee6d0
/*  f0ee6b0:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f0ee6b4:	0323c821 */ 	addu	$t9,$t9,$v1
/*  f0ee6b8:	3c08800b */ 	lui	$t0,%hi(g_MpPlayers)
/*  f0ee6bc:	2508c7b8 */ 	addiu	$t0,$t0,%lo(g_MpPlayers)
/*  f0ee6c0:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f0ee6c4:	03284821 */ 	addu	$t1,$t9,$t0
/*  f0ee6c8:	1000000b */ 	beqz	$zero,.L0f0ee6f8
/*  f0ee6cc:	afa900b0 */ 	sw	$t1,0xb0($sp)
.L0f0ee6d0:
/*  f0ee6d0:	00035080 */ 	sll	$t2,$v1,0x2
/*  f0ee6d4:	01435021 */ 	addu	$t2,$t2,$v1
/*  f0ee6d8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0ee6dc:	01435023 */ 	subu	$t2,$t2,$v1
/*  f0ee6e0:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0ee6e4:	3c0c800b */ 	lui	$t4,%hi(g_MpSimulants)
/*  f0ee6e8:	258cc538 */ 	addiu	$t4,$t4,%lo(g_MpSimulants)
/*  f0ee6ec:	254bfed0 */ 	addiu	$t3,$t2,-304
/*  f0ee6f0:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f0ee6f4:	afad00b0 */ 	sw	$t5,0xb0($sp)
.L0f0ee6f8:
/*  f0ee6f8:	0fc54d8a */ 	jal	func0f153628
/*  f0ee6fc:	02802025 */ 	or	$a0,$s4,$zero
/*  f0ee700:	3c014220 */ 	lui	$at,0x4220
/*  f0ee704:	44816000 */ 	mtc1	$at,$f12
/*  f0ee708:	0fc01ac2 */ 	jal	func0f006b08
/*  f0ee70c:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0ee710:	3c01437f */ 	lui	$at,0x437f
/*  f0ee714:	44812000 */ 	mtc1	$at,$f4
/*  f0ee718:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f0ee71c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0ee720:	444ef800 */ 	cfc1	$t6,$31
/*  f0ee724:	44d3f800 */ 	ctc1	$s3,$31
/*  f0ee728:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee72c:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0ee730:	4453f800 */ 	cfc1	$s3,$31
/*  f0ee734:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee738:	32730078 */ 	andi	$s3,$s3,0x78
/*  f0ee73c:	12600012 */ 	beqz	$s3,.L0f0ee788
/*  f0ee740:	3c014f00 */ 	lui	$at,0x4f00
/*  f0ee744:	44814000 */ 	mtc1	$at,$f8
/*  f0ee748:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f0ee74c:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0ee750:	44d3f800 */ 	ctc1	$s3,$31
/*  f0ee754:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee758:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0ee75c:	4453f800 */ 	cfc1	$s3,$31
/*  f0ee760:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee764:	32730078 */ 	andi	$s3,$s3,0x78
/*  f0ee768:	16600005 */ 	bnez	$s3,.L0f0ee780
/*  f0ee76c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee770:	44134000 */ 	mfc1	$s3,$f8
/*  f0ee774:	3c018000 */ 	lui	$at,0x8000
/*  f0ee778:	10000007 */ 	beqz	$zero,.L0f0ee798
/*  f0ee77c:	02619825 */ 	or	$s3,$s3,$at
.L0f0ee780:
/*  f0ee780:	10000005 */ 	beqz	$zero,.L0f0ee798
/*  f0ee784:	2413ffff */ 	addiu	$s3,$zero,-1
.L0f0ee788:
/*  f0ee788:	44134000 */ 	mfc1	$s3,$f8
/*  f0ee78c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee790:	0660fffb */ 	bltz	$s3,.L0f0ee780
/*  f0ee794:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ee798:
/*  f0ee798:	8e300010 */ 	lw	$s0,0x10($s1)
/*  f0ee79c:	44cef800 */ 	ctc1	$t6,$31
/*  f0ee7a0:	44808000 */ 	mtc1	$zero,$f16
/*  f0ee7a4:	c60a0040 */ 	lwc1	$f10,0x40($s0)
/*  f0ee7a8:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0ee7ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee7b0:	4502000a */ 	bc1fl	.L0f0ee7dc
/*  f0ee7b4:	9219003d */ 	lbu	$t9,0x3d($s0)
/*  f0ee7b8:	920f003c */ 	lbu	$t7,0x3c($s0)
/*  f0ee7bc:	3c127f1b */ 	lui	$s2,%hi(var7f1b1fd0)
/*  f0ee7c0:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0ee7c4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0ee7c8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0ee7cc:	02589021 */ 	addu	$s2,$s2,$t8
/*  f0ee7d0:	10000012 */ 	beqz	$zero,.L0f0ee81c
/*  f0ee7d4:	8e521fd0 */ 	lw	$s2,%lo(var7f1b1fd0)($s2)
/*  f0ee7d8:	9219003d */ 	lbu	$t9,0x3d($s0)
.L0f0ee7dc:
/*  f0ee7dc:	920b003c */ 	lbu	$t3,0x3c($s0)
/*  f0ee7e0:	3c097f1b */ 	lui	$t1,%hi(var7f1b1fb0)
/*  f0ee7e4:	00194100 */ 	sll	$t0,$t9,0x4
/*  f0ee7e8:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f0ee7ec:	25291fb0 */ 	addiu	$t1,$t1,%lo(var7f1b1fb0)
/*  f0ee7f0:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0ee7f4:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0ee7f8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0ee7fc:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ee800:	01095021 */ 	addu	$t2,$t0,$t1
/*  f0ee804:	01896821 */ 	addu	$t5,$t4,$t1
/*  f0ee808:	8da50020 */ 	lw	$a1,0x20($t5)
/*  f0ee80c:	8d440020 */ 	lw	$a0,0x20($t2)
/*  f0ee810:	0fc01a40 */ 	jal	func0f006900
/*  f0ee814:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0ee818:	00409025 */ 	or	$s2,$v0,$zero
.L0f0ee81c:
/*  f0ee81c:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0ee820:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f0ee824:	0fc01a40 */ 	jal	func0f006900
/*  f0ee828:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ee82c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ee830:	02402825 */ 	or	$a1,$s2,$zero
/*  f0ee834:	0fc01a40 */ 	jal	func0f006900
/*  f0ee838:	02603025 */ 	or	$a2,$s3,$zero
/*  f0ee83c:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f0ee840:	3c158008 */ 	lui	$s5,%hi(var8007fb10)
/*  f0ee844:	3c168008 */ 	lui	$s6,%hi(var8007fb0c)
/*  f0ee848:	25cf0002 */ 	addiu	$t7,$t6,0x2
/*  f0ee84c:	afaf00c0 */ 	sw	$t7,0xc0($sp)
/*  f0ee850:	86380002 */ 	lh	$t8,0x2($s1)
/*  f0ee854:	26d6fb0c */ 	addiu	$s6,$s6,%lo(var8007fb0c)
/*  f0ee858:	26b5fb10 */ 	addiu	$s5,$s5,%lo(var8007fb10)
/*  f0ee85c:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f0ee860:	8eca0000 */ 	lw	$t2,0x0($s6)
/*  f0ee864:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0ee868:	afb900bc */ 	sw	$t9,0xbc($sp)
/*  f0ee86c:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0ee870:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ee874:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0ee878:	862b0004 */ 	lh	$t3,0x4($s1)
/*  f0ee87c:	27b700c0 */ 	addiu	$s7,$sp,0xc0
/*  f0ee880:	27be00bc */ 	addiu	$s8,$sp,0xbc
/*  f0ee884:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0ee888:	862c0006 */ 	lh	$t4,0x6($s1)
/*  f0ee88c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ee890:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ee894:	03c03025 */ 	or	$a2,$s8,$zero
/*  f0ee898:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0ee89c:	02802025 */ 	or	$a0,$s4,$zero
/*  f0ee8a0:	8fa700b0 */ 	lw	$a3,0xb0($sp)
/*  f0ee8a4:	0fc5580f */ 	jal	func0f15603c
/*  f0ee8a8:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0ee8ac:	8e300010 */ 	lw	$s0,0x10($s1)
/*  f0ee8b0:	44802000 */ 	mtc1	$zero,$f4
/*  f0ee8b4:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0ee8b8:	c6120040 */ 	lwc1	$f18,0x40($s0)
/*  f0ee8bc:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0ee8c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee8c4:	4502000b */ 	bc1fl	.L0f0ee8f4
/*  f0ee8c8:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f0ee8cc:	9209003c */ 	lbu	$t1,0x3c($s0)
/*  f0ee8d0:	3c0e7f1b */ 	lui	$t6,%hi(var7f1b1fc8)
/*  f0ee8d4:	00096900 */ 	sll	$t5,$t1,0x4
/*  f0ee8d8:	01a96823 */ 	subu	$t5,$t5,$t1
/*  f0ee8dc:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0ee8e0:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0ee8e4:	8dce1fc8 */ 	lw	$t6,%lo(var7f1b1fc8)($t6)
/*  f0ee8e8:	10000013 */ 	beqz	$zero,.L0f0ee938
/*  f0ee8ec:	afae00b8 */ 	sw	$t6,0xb8($sp)
/*  f0ee8f0:	920f003d */ 	lbu	$t7,0x3d($s0)
.L0f0ee8f4:
/*  f0ee8f4:	920a003c */ 	lbu	$t2,0x3c($s0)
/*  f0ee8f8:	3c197f1b */ 	lui	$t9,%hi(var7f1b1fb0)
/*  f0ee8fc:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0ee900:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f0ee904:	27391fb0 */ 	addiu	$t9,$t9,%lo(var7f1b1fb0)
/*  f0ee908:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0ee90c:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0ee910:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0ee914:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0ee918:	03194021 */ 	addu	$t0,$t8,$t9
/*  f0ee91c:	01796021 */ 	addu	$t4,$t3,$t9
/*  f0ee920:	8d850018 */ 	lw	$a1,0x18($t4)
/*  f0ee924:	8d040018 */ 	lw	$a0,0x18($t0)
/*  f0ee928:	0fc01a40 */ 	jal	func0f006900
/*  f0ee92c:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0ee930:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0ee934:	8e300010 */ 	lw	$s0,0x10($s1)
.L0f0ee938:
/*  f0ee938:	8e09000c */ 	lw	$t1,0xc($s0)
/*  f0ee93c:	1120000b */ 	beqz	$t1,.L0f0ee96c
/*  f0ee940:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ee944:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*  f0ee948:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ee94c:	0fc01a40 */ 	jal	func0f006900
/*  f0ee950:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ee954:	8fb000b8 */ 	lw	$s0,0xb8($sp)
/*  f0ee958:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ee95c:	00416824 */ 	and	$t5,$v0,$at
/*  f0ee960:	320e00ff */ 	andi	$t6,$s0,0xff
/*  f0ee964:	01ae8025 */ 	or	$s0,$t5,$t6
/*  f0ee968:	afb000b8 */ 	sw	$s0,0xb8($sp)
.L0f0ee96c:
/*  f0ee96c:	0fc5b9f1 */ 	jal	langGet
/*  f0ee970:	24045119 */ 	addiu	$a0,$zero,0x5119
/*  f0ee974:	3c0f8008 */ 	lui	$t7,%hi(var8007fb04)
/*  f0ee978:	8deffb04 */ 	lw	$t7,%lo(var8007fb04)($t7)
/*  f0ee97c:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f0ee980:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f0ee984:	8fb000b8 */ 	lw	$s0,0xb8($sp)
/*  f0ee988:	27a400a8 */ 	addiu	$a0,$sp,0xa8
/*  f0ee98c:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0ee990:	00403025 */ 	or	$a2,$v0,$zero
/*  f0ee994:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ee998:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ee99c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ee9a0:	86380000 */ 	lh	$t8,0x0($s1)
/*  f0ee9a4:	8fa800a4 */ 	lw	$t0,0xa4($sp)
/*  f0ee9a8:	24045119 */ 	addiu	$a0,$zero,0x5119
/*  f0ee9ac:	03085023 */ 	subu	$t2,$t8,$t0
/*  f0ee9b0:	254b0079 */ 	addiu	$t3,$t2,0x79
/*  f0ee9b4:	afab00c0 */ 	sw	$t3,0xc0($sp)
/*  f0ee9b8:	86390002 */ 	lh	$t9,0x2($s1)
/*  f0ee9bc:	272c0001 */ 	addiu	$t4,$t9,0x1
/*  f0ee9c0:	0fc5b9f1 */ 	jal	langGet
/*  f0ee9c4:	afac00bc */ 	sw	$t4,0xbc($sp)
/*  f0ee9c8:	3c098008 */ 	lui	$t1,%hi(var8007fb08)
/*  f0ee9cc:	3c0d8008 */ 	lui	$t5,%hi(var8007fb04)
/*  f0ee9d0:	8dadfb04 */ 	lw	$t5,%lo(var8007fb04)($t5)
/*  f0ee9d4:	8d29fb08 */ 	lw	$t1,%lo(var8007fb08)($t1)
/*  f0ee9d8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ee9dc:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ee9e0:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0ee9e4:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0ee9e8:	02802025 */ 	or	$a0,$s4,$zero
/*  f0ee9ec:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0ee9f0:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0ee9f4:	862f0006 */ 	lh	$t7,0x6($s1)
/*  f0ee9f8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ee9fc:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eea00:	03c03025 */ 	or	$a2,$s8,$zero
/*  f0eea04:	00403825 */ 	or	$a3,$v0,$zero
/*  f0eea08:	0fc5580f */ 	jal	func0f15603c
/*  f0eea0c:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0eea10:	86380000 */ 	lh	$t8,0x0($s1)
/*  f0eea14:	8fa800a4 */ 	lw	$t0,0xa4($sp)
/*  f0eea18:	8fa300b4 */ 	lw	$v1,0xb4($sp)
/*  f0eea1c:	8fac00b0 */ 	lw	$t4,0xb0($sp)
/*  f0eea20:	03085023 */ 	subu	$t2,$t8,$t0
/*  f0eea24:	254b0077 */ 	addiu	$t3,$t2,0x77
/*  f0eea28:	0003c840 */ 	sll	$t9,$v1,0x1
/*  f0eea2c:	afab00c0 */ 	sw	$t3,0xc0($sp)
/*  f0eea30:	01994821 */ 	addu	$t1,$t4,$t9
/*  f0eea34:	27b30094 */ 	addiu	$s3,$sp,0x94
/*  f0eea38:	85260024 */ 	lh	$a2,0x24($t1)
/*  f0eea3c:	3c057f1b */ 	lui	$a1,%hi(var7f1b1e4c)
/*  f0eea40:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0eea44:	24a51e4c */ 	addiu	$a1,$a1,%lo(var7f1b1e4c)
/*  f0eea48:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f0eea4c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0eea50:	0c004dad */ 	jal	sprintf
/*  f0eea54:	03201825 */ 	or	$v1,$t9,$zero
/*  f0eea58:	8ecd0000 */ 	lw	$t5,0x0($s6)
/*  f0eea5c:	27a400a8 */ 	addiu	$a0,$sp,0xa8
/*  f0eea60:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0eea64:	02603025 */ 	or	$a2,$s3,$zero
/*  f0eea68:	8ea70000 */ 	lw	$a3,0x0($s5)
/*  f0eea6c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eea70:	0fc55cbe */ 	jal	func0f1572f8
/*  f0eea74:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0eea78:	8fae00c0 */ 	lw	$t6,0xc0($sp)
/*  f0eea7c:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f0eea80:	8eab0000 */ 	lw	$t3,0x0($s5)
/*  f0eea84:	8ed90000 */ 	lw	$t9,0x0($s6)
/*  f0eea88:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f0eea8c:	afb800c0 */ 	sw	$t8,0xc0($sp)
/*  f0eea90:	86280002 */ 	lh	$t0,0x2($s1)
/*  f0eea94:	3c0cffff */ 	lui	$t4,0xffff
/*  f0eea98:	358c00ff */ 	ori	$t4,$t4,0xff
/*  f0eea9c:	250a0001 */ 	addiu	$t2,$t0,0x1
/*  f0eeaa0:	afaa00bc */ 	sw	$t2,0xbc($sp)
/*  f0eeaa4:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0eeaa8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0eeaac:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0eeab0:	86290004 */ 	lh	$t1,0x4($s1)
/*  f0eeab4:	02802025 */ 	or	$a0,$s4,$zero
/*  f0eeab8:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0eeabc:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0eeac0:	862d0006 */ 	lh	$t5,0x6($s1)
/*  f0eeac4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eeac8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eeacc:	03c03025 */ 	or	$a2,$s8,$zero
/*  f0eead0:	02603825 */ 	or	$a3,$s3,$zero
/*  f0eead4:	0fc5580f */ 	jal	func0f15603c
/*  f0eead8:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f0eeadc:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0eeae0:	0fc6321f */ 	jal	func0f18c87c
/*  f0eeae4:	2412000c */ 	addiu	$s2,$zero,0xc
/*  f0eeae8:	28410002 */ 	slti	$at,$v0,0x2
/*  f0eeaec:	142001b6 */ 	bnez	$at,.L0f0ef1c8
/*  f0eeaf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eeaf4:	8e300010 */ 	lw	$s0,0x10($s1)
/*  f0eeaf8:	44804000 */ 	mtc1	$zero,$f8
/*  f0eeafc:	c6060040 */ 	lwc1	$f6,0x40($s0)
/*  f0eeb00:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0eeb04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eeb08:	4502000b */ 	bc1fl	.L0f0eeb38
/*  f0eeb0c:	9208003d */ 	lbu	$t0,0x3d($s0)
/*  f0eeb10:	920e003c */ 	lbu	$t6,0x3c($s0)
/*  f0eeb14:	3c187f1b */ 	lui	$t8,%hi(var7f1b1fc8)
/*  f0eeb18:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f0eeb1c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0eeb20:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0eeb24:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0eeb28:	8f181fc8 */ 	lw	$t8,%lo(var7f1b1fc8)($t8)
/*  f0eeb2c:	10000012 */ 	beqz	$zero,.L0f0eeb78
/*  f0eeb30:	afb800b8 */ 	sw	$t8,0xb8($sp)
/*  f0eeb34:	9208003d */ 	lbu	$t0,0x3d($s0)
.L0f0eeb38:
/*  f0eeb38:	2403003c */ 	addiu	$v1,$zero,0x3c
/*  f0eeb3c:	9219003c */ 	lbu	$t9,0x3c($s0)
/*  f0eeb40:	01030019 */ 	multu	$t0,$v1
/*  f0eeb44:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0eeb48:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0eeb4c:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0eeb50:	00005012 */ 	mflo	$t2
/*  f0eeb54:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f0eeb58:	8d640018 */ 	lw	$a0,0x18($t3)
/*  f0eeb5c:	03230019 */ 	multu	$t9,$v1
/*  f0eeb60:	00006012 */ 	mflo	$t4
/*  f0eeb64:	004c4821 */ 	addu	$t1,$v0,$t4
/*  f0eeb68:	0fc01a40 */ 	jal	func0f006900
/*  f0eeb6c:	8d250018 */ 	lw	$a1,0x18($t1)
/*  f0eeb70:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0eeb74:	8e300010 */ 	lw	$s0,0x10($s1)
.L0f0eeb78:
/*  f0eeb78:	8e0d000c */ 	lw	$t5,0xc($s0)
/*  f0eeb7c:	11a0000b */ 	beqz	$t5,.L0f0eebac
/*  f0eeb80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eeb84:	8fb000b8 */ 	lw	$s0,0xb8($sp)
/*  f0eeb88:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eeb8c:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eeb90:	0fc01a40 */ 	jal	func0f006900
/*  f0eeb94:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eeb98:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0eeb9c:	00417024 */ 	and	$t6,$v0,$at
/*  f0eeba0:	320f00ff */ 	andi	$t7,$s0,0xff
/*  f0eeba4:	01cf8025 */ 	or	$s0,$t6,$t7
/*  f0eeba8:	afb000b8 */ 	sw	$s0,0xb8($sp)
.L0f0eebac:
/*  f0eebac:	0fc5b9f1 */ 	jal	langGet
/*  f0eebb0:	2404511a */ 	addiu	$a0,$zero,0x511a
/*  f0eebb4:	3c188008 */ 	lui	$t8,%hi(var8007fb04)
/*  f0eebb8:	8f18fb04 */ 	lw	$t8,%lo(var8007fb04)($t8)
/*  f0eebbc:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f0eebc0:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f0eebc4:	8fb000b8 */ 	lw	$s0,0xb8($sp)
/*  f0eebc8:	27a400a8 */ 	addiu	$a0,$sp,0xa8
/*  f0eebcc:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0eebd0:	00403025 */ 	or	$a2,$v0,$zero
/*  f0eebd4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eebd8:	0fc55cbe */ 	jal	func0f1572f8
/*  f0eebdc:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0eebe0:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0eebe4:	8faa00a4 */ 	lw	$t2,0xa4($sp)
/*  f0eebe8:	2404511a */ 	addiu	$a0,$zero,0x511a
/*  f0eebec:	010a5823 */ 	subu	$t3,$t0,$t2
/*  f0eebf0:	25790078 */ 	addiu	$t9,$t3,0x78
/*  f0eebf4:	afb900c0 */ 	sw	$t9,0xc0($sp)
/*  f0eebf8:	862c0002 */ 	lh	$t4,0x2($s1)
/*  f0eebfc:	01924821 */ 	addu	$t1,$t4,$s2
/*  f0eec00:	0fc5b9f1 */ 	jal	langGet
/*  f0eec04:	afa900bc */ 	sw	$t1,0xbc($sp)
/*  f0eec08:	3c0d8008 */ 	lui	$t5,%hi(var8007fb08)
/*  f0eec0c:	3c0e8008 */ 	lui	$t6,%hi(var8007fb04)
/*  f0eec10:	8dcefb04 */ 	lw	$t6,%lo(var8007fb04)($t6)
/*  f0eec14:	8dadfb08 */ 	lw	$t5,%lo(var8007fb08)($t5)
/*  f0eec18:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eec1c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0eec20:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0eec24:	862f0004 */ 	lh	$t7,0x4($s1)
/*  f0eec28:	02802025 */ 	or	$a0,$s4,$zero
/*  f0eec2c:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0eec30:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0eec34:	86380006 */ 	lh	$t8,0x6($s1)
/*  f0eec38:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eec3c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eec40:	03c03025 */ 	or	$a2,$s8,$zero
/*  f0eec44:	00403825 */ 	or	$a3,$v0,$zero
/*  f0eec48:	0fc5580f */ 	jal	func0f15603c
/*  f0eec4c:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0eec50:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0eec54:	0fc5b9f1 */ 	jal	langGet
/*  f0eec58:	2404511b */ 	addiu	$a0,$zero,0x511b
/*  f0eec5c:	3c088008 */ 	lui	$t0,%hi(var8007fb04)
/*  f0eec60:	8d08fb04 */ 	lw	$t0,%lo(var8007fb04)($t0)
/*  f0eec64:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f0eec68:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f0eec6c:	27a400a8 */ 	addiu	$a0,$sp,0xa8
/*  f0eec70:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0eec74:	00403025 */ 	or	$a2,$v0,$zero
/*  f0eec78:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eec7c:	0fc55cbe */ 	jal	func0f1572f8
/*  f0eec80:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eec84:	862a0000 */ 	lh	$t2,0x0($s1)
/*  f0eec88:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f0eec8c:	2404511b */ 	addiu	$a0,$zero,0x511b
/*  f0eec90:	014bc823 */ 	subu	$t9,$t2,$t3
/*  f0eec94:	272c0019 */ 	addiu	$t4,$t9,0x19
/*  f0eec98:	afac00c0 */ 	sw	$t4,0xc0($sp)
/*  f0eec9c:	86290002 */ 	lh	$t1,0x2($s1)
/*  f0eeca0:	01326821 */ 	addu	$t5,$t1,$s2
/*  f0eeca4:	0fc5b9f1 */ 	jal	langGet
/*  f0eeca8:	afad00bc */ 	sw	$t5,0xbc($sp)
/*  f0eecac:	3c0e8008 */ 	lui	$t6,%hi(var8007fb08)
/*  f0eecb0:	3c0f8008 */ 	lui	$t7,%hi(var8007fb04)
/*  f0eecb4:	8deffb04 */ 	lw	$t7,%lo(var8007fb04)($t7)
/*  f0eecb8:	8dcefb08 */ 	lw	$t6,%lo(var8007fb08)($t6)
/*  f0eecbc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eecc0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0eecc4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0eecc8:	86380004 */ 	lh	$t8,0x4($s1)
/*  f0eeccc:	02802025 */ 	or	$a0,$s4,$zero
/*  f0eecd0:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0eecd4:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0eecd8:	86280006 */ 	lh	$t0,0x6($s1)
/*  f0eecdc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eece0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eece4:	03c03025 */ 	or	$a2,$s8,$zero
/*  f0eece8:	00403825 */ 	or	$a3,$v0,$zero
/*  f0eecec:	0fc5580f */ 	jal	func0f15603c
/*  f0eecf0:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0eecf4:	8faa00a0 */ 	lw	$t2,0xa0($sp)
/*  f0eecf8:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0eecfc:	26520007 */ 	addiu	$s2,$s2,0x7
/*  f0eed00:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f0eed04:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0eed08:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f0eed0c:	01796023 */ 	subu	$t4,$t3,$t9
/*  f0eed10:	01921821 */ 	addu	$v1,$t4,$s2
/*  f0eed14:	2463fff6 */ 	addiu	$v1,$v1,-10
/*  f0eed18:	04610002 */ 	bgez	$v1,.L0f0eed24
/*  f0eed1c:	8fa700c4 */ 	lw	$a3,0xc4($sp)
/*  f0eed20:	00001825 */ 	or	$v1,$zero,$zero
.L0f0eed24:
/*  f0eed24:	84e9000c */ 	lh	$t1,0xc($a3)
/*  f0eed28:	3c0de700 */ 	lui	$t5,0xe700
/*  f0eed2c:	3c048008 */ 	lui	$a0,%hi(var8007fac0)
/*  f0eed30:	0069082a */ 	slt	$at,$v1,$t1
/*  f0eed34:	50200003 */ 	beqzl	$at,.L0f0eed44
/*  f0eed38:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f0eed3c:	a4e3000c */ 	sh	$v1,0xc($a3)
/*  f0eed40:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L0f0eed44:
/*  f0eed44:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0eed48:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f0eed4c:	8c84fac0 */ 	lw	$a0,%lo(var8007fac0)($a0)
/*  f0eed50:	3c108007 */ 	lui	$s0,%hi(var80071190)
/*  f0eed54:	26101190 */ 	addiu	$s0,$s0,%lo(var80071190)
/*  f0eed58:	01c40019 */ 	multu	$t6,$a0
/*  f0eed5c:	3c058007 */ 	lui	$a1,%hi(var80071194)
/*  f0eed60:	24a51194 */ 	addiu	$a1,$a1,%lo(var80071194)
/*  f0eed64:	3c018007 */ 	lui	$at,%hi(var80071198)
/*  f0eed68:	3c068007 */ 	lui	$a2,%hi(var8007119c)
/*  f0eed6c:	24540008 */ 	addiu	$s4,$v0,0x8
/*  f0eed70:	24c6119c */ 	addiu	$a2,$a2,%lo(var8007119c)
/*  f0eed74:	3c028007 */ 	lui	$v0,%hi(var80071198)
/*  f0eed78:	24421198 */ 	addiu	$v0,$v0,%lo(var80071198)
/*  f0eed7c:	00007812 */ 	mflo	$t7
/*  f0eed80:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f0eed84:	86280004 */ 	lh	$t0,0x4($s1)
/*  f0eed88:	86380000 */ 	lh	$t8,0x0($s1)
/*  f0eed8c:	03085021 */ 	addu	$t2,$t8,$t0
/*  f0eed90:	01440019 */ 	multu	$t2,$a0
/*  f0eed94:	00005812 */ 	mflo	$t3
/*  f0eed98:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f0eed9c:	86390002 */ 	lh	$t9,0x2($s1)
/*  f0eeda0:	03326021 */ 	addu	$t4,$t9,$s2
/*  f0eeda4:	ac2c1198 */ 	sw	$t4,%lo(var80071198)($at)
/*  f0eeda8:	862d0006 */ 	lh	$t5,0x6($s1)
/*  f0eedac:	86290002 */ 	lh	$t1,0x2($s1)
/*  f0eedb0:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0eedb4:	012d7021 */ 	addu	$t6,$t1,$t5
/*  f0eedb8:	05e10002 */ 	bgez	$t7,.L0f0eedc4
/*  f0eedbc:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f0eedc0:	ae000000 */ 	sw	$zero,0x0($s0)
.L0f0eedc4:
/*  f0eedc4:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f0eedc8:	07030003 */ 	bgezl	$t8,.L0f0eedd8
/*  f0eedcc:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f0eedd0:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f0eedd4:	8c480000 */ 	lw	$t0,0x0($v0)
.L0f0eedd8:
/*  f0eedd8:	05030003 */ 	bgezl	$t0,.L0f0eede8
/*  f0eeddc:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f0eede0:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f0eede4:	8cca0000 */ 	lw	$t2,0x0($a2)
.L0f0eede8:
/*  f0eede8:	05410002 */ 	bgez	$t2,.L0f0eedf4
/*  f0eedec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eedf0:	acc00000 */ 	sw	$zero,0x0($a2)
.L0f0eedf4:
/*  f0eedf4:	0c002ef1 */ 	jal	func0000bbc4
/*  f0eedf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eedfc:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f0eee00:	004b082a */ 	slt	$at,$v0,$t3
/*  f0eee04:	10200004 */ 	beqz	$at,.L0f0eee18
/*  f0eee08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eee0c:	0c002ef1 */ 	jal	func0000bbc4
/*  f0eee10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eee14:	ae020000 */ 	sw	$v0,0x0($s0)
.L0f0eee18:
/*  f0eee18:	0c002ef1 */ 	jal	func0000bbc4
/*  f0eee1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eee20:	3c198007 */ 	lui	$t9,%hi(var80071194)
/*  f0eee24:	8f391194 */ 	lw	$t9,%lo(var80071194)($t9)
/*  f0eee28:	0059082a */ 	slt	$at,$v0,$t9
/*  f0eee2c:	10200005 */ 	beqz	$at,.L0f0eee44
/*  f0eee30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eee34:	0c002ef1 */ 	jal	func0000bbc4
/*  f0eee38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eee3c:	3c018007 */ 	lui	$at,%hi(var80071194)
/*  f0eee40:	ac221194 */ 	sw	$v0,%lo(var80071194)($at)
.L0f0eee44:
/*  f0eee44:	0c002ef5 */ 	jal	func0000bbd4
/*  f0eee48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eee4c:	3c0c8007 */ 	lui	$t4,%hi(var80071198)
/*  f0eee50:	8d8c1198 */ 	lw	$t4,%lo(var80071198)($t4)
/*  f0eee54:	004c082a */ 	slt	$at,$v0,$t4
/*  f0eee58:	10200005 */ 	beqz	$at,.L0f0eee70
/*  f0eee5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eee60:	0c002ef5 */ 	jal	func0000bbd4
/*  f0eee64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eee68:	3c018007 */ 	lui	$at,%hi(var80071198)
/*  f0eee6c:	ac221198 */ 	sw	$v0,%lo(var80071198)($at)
.L0f0eee70:
/*  f0eee70:	0c002ef5 */ 	jal	func0000bbd4
/*  f0eee74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eee78:	3c058007 */ 	lui	$a1,%hi(var8007119c)
/*  f0eee7c:	8ca5119c */ 	lw	$a1,%lo(var8007119c)($a1)
/*  f0eee80:	0045082a */ 	slt	$at,$v0,$a1
/*  f0eee84:	10200007 */ 	beqz	$at,.L0f0eeea4
/*  f0eee88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eee8c:	0c002ef5 */ 	jal	func0000bbd4
/*  f0eee90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eee94:	3c018007 */ 	lui	$at,%hi(var8007119c)
/*  f0eee98:	ac22119c */ 	sw	$v0,%lo(var8007119c)($at)
/*  f0eee9c:	3c058007 */ 	lui	$a1,%hi(var8007119c)
/*  f0eeea0:	8ca5119c */ 	lw	$a1,%lo(var8007119c)($a1)
.L0f0eeea4:
/*  f0eeea4:	3c068007 */ 	lui	$a2,%hi(var80071194)
/*  f0eeea8:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f0eeeac:	24c61194 */ 	addiu	$a2,$a2,%lo(var80071194)
/*  f0eeeb0:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f0eeeb4:	44835000 */ 	mtc1	$v1,$f10
/*  f0eeeb8:	3c048007 */ 	lui	$a0,%hi(var80071198)
/*  f0eeebc:	0123082a */ 	slt	$at,$t1,$v1
/*  f0eeec0:	10200002 */ 	beqz	$at,.L0f0eeecc
/*  f0eeec4:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0eeec8:	acc30000 */ 	sw	$v1,0x0($a2)
.L0f0eeecc:
/*  f0eeecc:	8c841198 */ 	lw	$a0,%lo(var80071198)($a0)
/*  f0eeed0:	00a4082a */ 	slt	$at,$a1,$a0
/*  f0eeed4:	10200002 */ 	beqz	$at,.L0f0eeee0
/*  f0eeed8:	3c018007 */ 	lui	$at,%hi(var8007119c)
/*  f0eeedc:	ac24119c */ 	sw	$a0,%lo(var8007119c)($at)
.L0f0eeee0:
/*  f0eeee0:	44843000 */ 	mtc1	$a0,$f6
/*  f0eeee4:	3c014080 */ 	lui	$at,0x4080
/*  f0eeee8:	44810000 */ 	mtc1	$at,$f0
/*  f0eeeec:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0eeef0:	3c01ed00 */ 	lui	$at,0xed00
/*  f0eeef4:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0eeef8:	02801025 */ 	or	$v0,$s4,$zero
/*  f0eeefc:	3c0a8007 */ 	lui	$t2,%hi(var8007119c)
/*  f0eef00:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f0eef04:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0eef08:	00008025 */ 	or	$s0,$zero,$zero
/*  f0eef0c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0eef10:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0eef14:	440e2000 */ 	mfc1	$t6,$f4
/*  f0eef18:	440b8000 */ 	mfc1	$t3,$f16
/*  f0eef1c:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f0eef20:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0eef24:	03014025 */ 	or	$t0,$t8,$at
/*  f0eef28:	31790fff */ 	andi	$t9,$t3,0xfff
/*  f0eef2c:	01196025 */ 	or	$t4,$t0,$t9
/*  f0eef30:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0eef34:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f0eef38:	8d4a119c */ 	lw	$t2,%lo(var8007119c)($t2)
/*  f0eef3c:	44899000 */ 	mtc1	$t1,$f18
/*  f0eef40:	448a5000 */ 	mtc1	$t2,$f10
/*  f0eef44:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0eef48:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0eef4c:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0eef50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eef54:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0eef58:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0eef5c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0eef60:	440e4000 */ 	mfc1	$t6,$f8
/*  f0eef64:	44082000 */ 	mfc1	$t0,$f4
/*  f0eef68:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f0eef6c:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0eef70:	31190fff */ 	andi	$t9,$t0,0xfff
/*  f0eef74:	03196025 */ 	or	$t4,$t8,$t9
/*  f0eef78:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0eef7c:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f0eef80:	852d000c */ 	lh	$t5,0xc($t1)
/*  f0eef84:	024d9023 */ 	subu	$s2,$s2,$t5
.L0f0eef88:
/*  f0eef88:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup+0x16)
/*  f0eef8c:	95cecb9e */ 	lhu	$t6,%lo(g_MpSetup+0x16)($t6)
/*  f0eef90:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0eef94:	020f5004 */ 	sllv	$t2,$t7,$s0
/*  f0eef98:	01ca5824 */ 	and	$t3,$t6,$t2
/*  f0eef9c:	11600086 */ 	beqz	$t3,.L0f0ef1b8
/*  f0eefa0:	2a010004 */ 	slti	$at,$s0,0x4
/*  f0eefa4:	10200008 */ 	beqz	$at,.L0f0eefc8
/*  f0eefa8:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f0eefac:	00104080 */ 	sll	$t0,$s0,0x2
/*  f0eefb0:	01104021 */ 	addu	$t0,$t0,$s0
/*  f0eefb4:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f0eefb8:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f0eefbc:	00084140 */ 	sll	$t0,$t0,0x5
/*  f0eefc0:	1000000a */ 	beqz	$zero,.L0f0eefec
/*  f0eefc4:	01183821 */ 	addu	$a3,$t0,$t8
.L0f0eefc8:
/*  f0eefc8:	0010c880 */ 	sll	$t9,$s0,0x2
/*  f0eefcc:	0330c821 */ 	addu	$t9,$t9,$s0
/*  f0eefd0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0eefd4:	0330c823 */ 	subu	$t9,$t9,$s0
/*  f0eefd8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0eefdc:	3c09800b */ 	lui	$t1,%hi(g_MpSimulants)
/*  f0eefe0:	2529c538 */ 	addiu	$t1,$t1,%lo(g_MpSimulants)
/*  f0eefe4:	272cfed0 */ 	addiu	$t4,$t9,-304
/*  f0eefe8:	01893821 */ 	addu	$a3,$t4,$t1
.L0f0eefec:
/*  f0eefec:	120d0072 */ 	beq	$s0,$t5,.L0f0ef1b8
/*  f0eeff0:	02802025 */ 	or	$a0,$s4,$zero
/*  f0eeff4:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0eeff8:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f0eeffc:	8ed80000 */ 	lw	$t8,0x0($s6)
/*  f0ef000:	25ee001d */ 	addiu	$t6,$t7,0x1d
/*  f0ef004:	afae00c0 */ 	sw	$t6,0xc0($sp)
/*  f0ef008:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0ef00c:	3c1900ff */ 	lui	$t9,0xff
/*  f0ef010:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f0ef014:	01525821 */ 	addu	$t3,$t2,$s2
/*  f0ef018:	afab00bc */ 	sw	$t3,0xbc($sp)
/*  f0ef01c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0ef020:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ef024:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0ef028:	862c0004 */ 	lh	$t4,0x4($s1)
/*  f0ef02c:	8fad00b0 */ 	lw	$t5,0xb0($sp)
/*  f0ef030:	00107840 */ 	sll	$t7,$s0,0x1
/*  f0ef034:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0ef038:	86290006 */ 	lh	$t1,0x6($s1)
/*  f0ef03c:	01af7021 */ 	addu	$t6,$t5,$t7
/*  f0ef040:	afae0070 */ 	sw	$t6,0x70($sp)
/*  f0ef044:	afa70078 */ 	sw	$a3,0x78($sp)
/*  f0ef048:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ef04c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ef050:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0ef054:	03c03025 */ 	or	$a2,$s8,$zero
/*  f0ef058:	0fc5580f */ 	jal	func0f15603c
/*  f0ef05c:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f0ef060:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0ef064:	8faa006c */ 	lw	$t2,0x6c($sp)
/*  f0ef068:	3c057f1b */ 	lui	$a1,%hi(var7f1b1e50)
/*  f0ef06c:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0ef070:	00ea5821 */ 	addu	$t3,$a3,$t2
/*  f0ef074:	85660024 */ 	lh	$a2,0x24($t3)
/*  f0ef078:	24a51e50 */ 	addiu	$a1,$a1,%lo(var7f1b1e50)
/*  f0ef07c:	0c004dad */ 	jal	sprintf
/*  f0ef080:	02602025 */ 	or	$a0,$s3,$zero
/*  f0ef084:	8ec80000 */ 	lw	$t0,0x0($s6)
/*  f0ef088:	27a400a8 */ 	addiu	$a0,$sp,0xa8
/*  f0ef08c:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0ef090:	02603025 */ 	or	$a2,$s3,$zero
/*  f0ef094:	8ea70000 */ 	lw	$a3,0x0($s5)
/*  f0ef098:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ef09c:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ef0a0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ef0a4:	86380000 */ 	lh	$t8,0x0($s1)
/*  f0ef0a8:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f0ef0ac:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f0ef0b0:	8eca0000 */ 	lw	$t2,0x0($s6)
/*  f0ef0b4:	03196023 */ 	subu	$t4,$t8,$t9
/*  f0ef0b8:	25890078 */ 	addiu	$t1,$t4,0x78
/*  f0ef0bc:	afa900c0 */ 	sw	$t1,0xc0($sp)
/*  f0ef0c0:	862d0002 */ 	lh	$t5,0x2($s1)
/*  f0ef0c4:	3c0bff40 */ 	lui	$t3,0xff40
/*  f0ef0c8:	356b40ff */ 	ori	$t3,$t3,0x40ff
/*  f0ef0cc:	01b27821 */ 	addu	$t7,$t5,$s2
/*  f0ef0d0:	afaf00bc */ 	sw	$t7,0xbc($sp)
/*  f0ef0d4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0ef0d8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ef0dc:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0ef0e0:	86280004 */ 	lh	$t0,0x4($s1)
/*  f0ef0e4:	02802025 */ 	or	$a0,$s4,$zero
/*  f0ef0e8:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0ef0ec:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0ef0f0:	86380006 */ 	lh	$t8,0x6($s1)
/*  f0ef0f4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ef0f8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ef0fc:	03c03025 */ 	or	$a2,$s8,$zero
/*  f0ef100:	02603825 */ 	or	$a3,$s3,$zero
/*  f0ef104:	0fc5580f */ 	jal	func0f15603c
/*  f0ef108:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0ef10c:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f0ef110:	3c057f1b */ 	lui	$a1,%hi(var7f1b1e54)
/*  f0ef114:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0ef118:	24a51e54 */ 	addiu	$a1,$a1,%lo(var7f1b1e54)
/*  f0ef11c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0ef120:	0c004dad */ 	jal	sprintf
/*  f0ef124:	87260024 */ 	lh	$a2,0x24($t9)
/*  f0ef128:	8ecc0000 */ 	lw	$t4,0x0($s6)
/*  f0ef12c:	27a400a8 */ 	addiu	$a0,$sp,0xa8
/*  f0ef130:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0ef134:	02603025 */ 	or	$a2,$s3,$zero
/*  f0ef138:	8ea70000 */ 	lw	$a3,0x0($s5)
/*  f0ef13c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ef140:	0fc55cbe */ 	jal	func0f1572f8
/*  f0ef144:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ef148:	86290000 */ 	lh	$t1,0x0($s1)
/*  f0ef14c:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f0ef150:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f0ef154:	8ed80000 */ 	lw	$t8,0x0($s6)
/*  f0ef158:	012d7823 */ 	subu	$t7,$t1,$t5
/*  f0ef15c:	25ee0019 */ 	addiu	$t6,$t7,0x19
/*  f0ef160:	afae00c0 */ 	sw	$t6,0xc0($sp)
/*  f0ef164:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0ef168:	3c1900ff */ 	lui	$t9,0xff
/*  f0ef16c:	373900ff */ 	ori	$t9,$t9,0xff
/*  f0ef170:	01525821 */ 	addu	$t3,$t2,$s2
/*  f0ef174:	afab00bc */ 	sw	$t3,0xbc($sp)
/*  f0ef178:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0ef17c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ef180:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0ef184:	862c0004 */ 	lh	$t4,0x4($s1)
/*  f0ef188:	02802025 */ 	or	$a0,$s4,$zero
/*  f0ef18c:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0ef190:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0ef194:	86290006 */ 	lh	$t1,0x6($s1)
/*  f0ef198:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ef19c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ef1a0:	03c03025 */ 	or	$a2,$s8,$zero
/*  f0ef1a4:	02603825 */ 	or	$a3,$s3,$zero
/*  f0ef1a8:	0fc5580f */ 	jal	func0f15603c
/*  f0ef1ac:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f0ef1b0:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0ef1b4:	2652000a */ 	addiu	$s2,$s2,0xa
.L0f0ef1b8:
/*  f0ef1b8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ef1bc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0ef1c0:	1601ff71 */ 	bne	$s0,$at,.L0f0eef88
/*  f0ef1c4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ef1c8:
/*  f0ef1c8:	0fc54de0 */ 	jal	func0f153780
/*  f0ef1cc:	02802025 */ 	or	$a0,$s4,$zero
/*  f0ef1d0:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f0ef1d4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ef1d8:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0ef1dc:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0ef1e0:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f0ef1e4:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f0ef1e8:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f0ef1ec:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f0ef1f0:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f0ef1f4:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f0ef1f8:	03e00008 */ 	jr	$ra
/*  f0ef1fc:	27bd00c8 */ 	addiu	$sp,$sp,0xc8
);

GLOBAL_ASM(
glabel func0f0ef200
/*  f0ef200:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0ef204:	30ee0002 */ 	andi	$t6,$a3,0x2
/*  f0ef208:	11c00035 */ 	beqz	$t6,.L0f0ef2e0
/*  f0ef20c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0ef210:	8caf000c */ 	lw	$t7,0xc($a1)
/*  f0ef214:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0ef218:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0ef21c:	55e00031 */ 	bnezl	$t7,.L0f0ef2e4
/*  f0ef220:	8fa20030 */ 	lw	$v0,0x30($sp)
/*  f0ef224:	80c20005 */ 	lb	$v0,0x5($a2)
/*  f0ef228:	44811000 */ 	mtc1	$at,$f2
/*  f0ef22c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ef230:	04410006 */ 	bgez	$v0,.L0f0ef24c
/*  f0ef234:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0ef238:	44822000 */ 	mtc1	$v0,$f4
/*  f0ef23c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ef240:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0ef244:	10000004 */ 	beqz	$zero,.L0f0ef258
/*  f0ef248:	46000007 */ 	neg.s	$f0,$f0
.L0f0ef24c:
/*  f0ef24c:	44823000 */ 	mtc1	$v0,$f6
/*  f0ef250:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ef254:	46803020 */ 	cvt.s.w	$f0,$f6
.L0f0ef258:
/*  f0ef258:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0ef25c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ef260:	45020012 */ 	bc1fl	.L0f0ef2ac
/*  f0ef264:	80c80009 */ 	lb	$t0,0x9($a2)
/*  f0ef268:	46020201 */ 	sub.s	$f8,$f0,$f2
/*  f0ef26c:	44815000 */ 	mtc1	$at,$f10
/*  f0ef270:	3c01800a */ 	lui	$at,0x800a
/*  f0ef274:	c4309fc4 */ 	lwc1	$f16,-0x603c($at)
/*  f0ef278:	460a4003 */ 	div.s	$f0,$f8,$f10
/*  f0ef27c:	46100002 */ 	mul.s	$f0,$f0,$f16
/*  f0ef280:	04430006 */ 	bgezl	$v0,.L0f0ef29c
/*  f0ef284:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f0ef288:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f0ef28c:	44039000 */ 	mfc1	$v1,$f18
/*  f0ef290:	10000006 */ 	beqz	$zero,.L0f0ef2ac
/*  f0ef294:	80c80009 */ 	lb	$t0,0x9($a2)
/*  f0ef298:	4600010d */ 	trunc.w.s	$f4,$f0
.L0f0ef29c:
/*  f0ef29c:	44032000 */ 	mfc1	$v1,$f4
/*  f0ef2a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ef2a4:	00031823 */ 	negu	$v1,$v1
/*  f0ef2a8:	80c80009 */ 	lb	$t0,0x9($a2)
.L0f0ef2ac:
/*  f0ef2ac:	8d4a9fc0 */ 	lw	$t2,%lo(g_Vars)($t2)
/*  f0ef2b0:	8fa20030 */ 	lw	$v0,0x30($sp)
/*  f0ef2b4:	00084840 */ 	sll	$t1,$t0,0x1
/*  f0ef2b8:	012a0019 */ 	multu	$t1,$t2
/*  f0ef2bc:	844c000c */ 	lh	$t4,0xc($v0)
/*  f0ef2c0:	00005812 */ 	mflo	$t3
/*  f0ef2c4:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f0ef2c8:	01836821 */ 	addu	$t5,$t4,$v1
/*  f0ef2cc:	a44d000c */ 	sh	$t5,0xc($v0)
/*  f0ef2d0:	844e000c */ 	lh	$t6,0xc($v0)
/*  f0ef2d4:	05c30003 */ 	bgezl	$t6,.L0f0ef2e4
/*  f0ef2d8:	8fa20030 */ 	lw	$v0,0x30($sp)
/*  f0ef2dc:	a440000c */ 	sh	$zero,0xc($v0)
.L0f0ef2e0:
/*  f0ef2e0:	8fa20030 */ 	lw	$v0,0x30($sp)
.L0f0ef2e4:
/*  f0ef2e4:	0fc3a04e */ 	jal	func0f0e8138
/*  f0ef2e8:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0ef2ec:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0ef2f0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0ef2f4:	03e00008 */ 	jr	$ra
/*  f0ef2f8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ef2fc
/*  f0ef2fc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0ef300:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f0ef304:	87a5002e */ 	lh	$a1,0x2e($sp)
/*  f0ef308:	87a8003a */ 	lh	$t0,0x3a($sp)
/*  f0ef30c:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f0ef310:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f0ef314:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f0ef318:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0ef31c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0ef320:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f0ef324:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f0ef328:	00067400 */ 	sll	$t6,$a2,0x10
/*  f0ef32c:	0005c400 */ 	sll	$t8,$a1,0x10
/*  f0ef330:	000e3403 */ 	sra	$a2,$t6,0x10
/*  f0ef334:	00182c03 */ 	sra	$a1,$t8,0x10
/*  f0ef338:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0ef33c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ef340:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0ef344:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0ef348:	0fc3a0a4 */ 	jal	func0f0e8290
/*  f0ef34c:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0ef350:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0ef354:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0ef358:	03e00008 */ 	jr	$ra
/*  f0ef35c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ef360
/*  f0ef360:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0ef364:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ef368:	a4a0000c */ 	sh	$zero,0xc($a1)
/*  f0ef36c:	3c028007 */ 	lui	$v0,%hi(g_MpPlayerNum)
/*  f0ef370:	8c421448 */ 	lw	$v0,%lo(g_MpPlayerNum)($v0)
/*  f0ef374:	3c01800a */ 	lui	$at,%hi(var8009deb0)
/*  f0ef378:	00220821 */ 	addu	$at,$at,$v0
/*  f0ef37c:	0fc39e66 */ 	jal	func0f0e7998
/*  f0ef380:	a022deb0 */ 	sb	$v0,%lo(var8009deb0)($at)
/*  f0ef384:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ef388:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0ef38c:	03e00008 */ 	jr	$ra
/*  f0ef390:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ef394
/*  f0ef394:	3c098008 */ 	lui	$t1,%hi(var8007fac0)
/*  f0ef398:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f0ef39c:	2529fac0 */ 	addiu	$t1,$t1,%lo(var8007fac0)
/*  f0ef3a0:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f0ef3a4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0ef3a8:	04c10004 */ 	bgez	$a2,.L0f0ef3bc
/*  f0ef3ac:	30ce0003 */ 	andi	$t6,$a2,0x3
/*  f0ef3b0:	11c00002 */ 	beqz	$t6,.L0f0ef3bc
/*  f0ef3b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ef3b8:	25cefffc */ 	addiu	$t6,$t6,-4
.L0f0ef3bc:
/*  f0ef3bc:	03190019 */ 	multu	$t8,$t9
/*  f0ef3c0:	01c52821 */ 	addu	$a1,$t6,$a1
/*  f0ef3c4:	8fae0014 */ 	lw	$t6,0x14($sp)
/*  f0ef3c8:	3c01e400 */ 	lui	$at,0xe400
/*  f0ef3cc:	00801025 */ 	or	$v0,$a0,$zero
/*  f0ef3d0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0ef3d4:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f0ef3d8:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0ef3dc:	00801825 */ 	or	$v1,$a0,$zero
/*  f0ef3e0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0ef3e4:	00005012 */ 	mflo	$t2
/*  f0ef3e8:	314b0fff */ 	andi	$t3,$t2,0xfff
/*  f0ef3ec:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f0ef3f0:	01816825 */ 	or	$t5,$t4,$at
/*  f0ef3f4:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f0ef3f8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0ef3fc:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*  f0ef400:	00065080 */ 	sll	$t2,$a2,0x2
/*  f0ef404:	00076880 */ 	sll	$t5,$a3,0x2
/*  f0ef408:	014b0019 */ 	multu	$t2,$t3
/*  f0ef40c:	31b80fff */ 	andi	$t8,$t5,0xfff
/*  f0ef410:	00055940 */ 	sll	$t3,$a1,0x5
/*  f0ef414:	3c0ab400 */ 	lui	$t2,0xb400
/*  f0ef418:	00804025 */ 	or	$t0,$a0,$zero
/*  f0ef41c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0ef420:	00006012 */ 	mflo	$t4
/*  f0ef424:	318e0fff */ 	andi	$t6,$t4,0xfff
/*  f0ef428:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f0ef42c:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f0ef430:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0ef434:	01606025 */ 	or	$t4,$t3,$zero
/*  f0ef438:	000c7400 */ 	sll	$t6,$t4,0x10
/*  f0ef43c:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0ef440:	04e10004 */ 	bgez	$a3,.L0f0ef454
/*  f0ef444:	30ed0003 */ 	andi	$t5,$a3,0x3
/*  f0ef448:	11a00002 */ 	beqz	$t5,.L0f0ef454
/*  f0ef44c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ef450:	25adfffc */ 	addiu	$t5,$t5,-4
.L0f0ef454:
/*  f0ef454:	000d7940 */ 	sll	$t7,$t5,0x5
/*  f0ef458:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*  f0ef45c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0ef460:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f0ef464:	3c0ab300 */ 	lui	$t2,0xb300
/*  f0ef468:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f0ef46c:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*  f0ef470:	240c0400 */ 	addiu	$t4,$zero,0x400
/*  f0ef474:	00801025 */ 	or	$v0,$a0,$zero
/*  f0ef478:	018b001a */ 	div	$zero,$t4,$t3
/*  f0ef47c:	00006812 */ 	mflo	$t5
/*  f0ef480:	31afffff */ 	andi	$t7,$t5,0xffff
/*  f0ef484:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f0ef488:	35d80400 */ 	ori	$t8,$t6,0x400
/*  f0ef48c:	15600002 */ 	bnez	$t3,.L0f0ef498
/*  f0ef490:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ef494:	0007000d */ 	break	0x7
.L0f0ef498:
/*  f0ef498:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ef49c:	15610004 */ 	bne	$t3,$at,.L0f0ef4b0
/*  f0ef4a0:	3c018000 */ 	lui	$at,0x8000
/*  f0ef4a4:	15810002 */ 	bne	$t4,$at,.L0f0ef4b0
/*  f0ef4a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ef4ac:	0006000d */ 	break	0x6
.L0f0ef4b0:
/*  f0ef4b0:	ad180004 */ 	sw	$t8,0x4($t0)
/*  f0ef4b4:	03e00008 */ 	jr	$ra
/*  f0ef4b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ef4bc
/*  f0ef4bc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0ef4c0:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f0ef4c4:	248f0008 */ 	addiu	$t7,$a0,0x8
/*  f0ef4c8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0ef4cc:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f0ef4d0:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f0ef4d4:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f0ef4d8:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f0ef4dc:	3c18e700 */ 	lui	$t8,0xe700
/*  f0ef4e0:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f0ef4e4:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f0ef4e8:	8fb90028 */ 	lw	$t9,0x28($sp)
/*  f0ef4ec:	3c0bba00 */ 	lui	$t3,0xba00
/*  f0ef4f0:	356b1301 */ 	ori	$t3,$t3,0x1301
/*  f0ef4f4:	272a0008 */ 	addiu	$t2,$t9,0x8
/*  f0ef4f8:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f0ef4fc:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0ef500:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f0ef504:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f0ef508:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0ef50c:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f0ef510:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f0ef514:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f0ef518:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f0ef51c:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f0ef520:	8faf0028 */ 	lw	$t7,0x28($sp)
/*  f0ef524:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0ef528:	37391001 */ 	ori	$t9,$t9,0x1001
/*  f0ef52c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0ef530:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f0ef534:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f0ef538:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0ef53c:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f0ef540:	3c0cba00 */ 	lui	$t4,0xba00
/*  f0ef544:	358c0903 */ 	ori	$t4,$t4,0x903
/*  f0ef548:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0ef54c:	afab0028 */ 	sw	$t3,0x28($sp)
/*  f0ef550:	240d0c00 */ 	addiu	$t5,$zero,0xc00
/*  f0ef554:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0ef558:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0ef55c:	8fae0034 */ 	lw	$t6,0x34($sp)
/*  f0ef560:	3c18800b */ 	lui	$t8,%hi(var800ab5a8)
/*  f0ef564:	8f18b5a8 */ 	lw	$t8,%lo(var800ab5a8)($t8)
/*  f0ef568:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0ef56c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0ef570:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0ef574:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ef578:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0ef57c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ef580:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0ef584:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0ef588:	27a40028 */ 	addiu	$a0,$sp,0x28
/*  f0ef58c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0ef590:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0ef594:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0ef598:	01f82821 */ 	addu	$a1,$t7,$t8
/*  f0ef59c:	8fab0028 */ 	lw	$t3,0x28($sp)
/*  f0ef5a0:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f0ef5a4:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f0ef5a8:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f0ef5ac:	afac0028 */ 	sw	$t4,0x28($sp)
/*  f0ef5b0:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0ef5b4:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*  f0ef5b8:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f0ef5bc:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f0ef5c0:	8fae0028 */ 	lw	$t6,0x28($sp)
/*  f0ef5c4:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0ef5c8:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f0ef5cc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0ef5d0:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f0ef5d4:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0ef5d8:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0ef5dc:	8fb90028 */ 	lw	$t9,0x28($sp)
/*  f0ef5e0:	01601025 */ 	or	$v0,$t3,$zero
/*  f0ef5e4:	3c0bfcff */ 	lui	$t3,0xfcff
/*  f0ef5e8:	272a0008 */ 	addiu	$t2,$t9,0x8
/*  f0ef5ec:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f0ef5f0:	3c0cfffc */ 	lui	$t4,0xfffc
/*  f0ef5f4:	358cf279 */ 	ori	$t4,$t4,0xf279
/*  f0ef5f8:	356bffff */ 	ori	$t3,$t3,0xffff
/*  f0ef5fc:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f0ef600:	af2c0004 */ 	sw	$t4,0x4($t9)
/*  f0ef604:	8fad0028 */ 	lw	$t5,0x28($sp)
/*  f0ef608:	3c18ff37 */ 	lui	$t8,0xff37
/*  f0ef60c:	3c0ffc12 */ 	lui	$t7,0xfc12
/*  f0ef610:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0ef614:	afae0028 */ 	sw	$t6,0x28($sp)
/*  f0ef618:	35ef9a25 */ 	ori	$t7,$t7,0x9a25
/*  f0ef61c:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f0ef620:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0ef624:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0ef628:	8fb90028 */ 	lw	$t9,0x28($sp)
/*  f0ef62c:	3c0bfb00 */ 	lui	$t3,0xfb00
/*  f0ef630:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ef634:	272a0008 */ 	addiu	$t2,$t9,0x8
/*  f0ef638:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f0ef63c:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f0ef640:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f0ef644:	3c068008 */ 	lui	$a2,%hi(var8007fac0)
/*  f0ef648:	24c6fac0 */ 	addiu	$a2,$a2,%lo(var8007fac0)
/*  f0ef64c:	01816825 */ 	or	$t5,$t4,$at
/*  f0ef650:	af2d0004 */ 	sw	$t5,0x4($t9)
/*  f0ef654:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f0ef658:	24f80020 */ 	addiu	$t8,$a3,0x20
/*  f0ef65c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0ef660:	032a0019 */ 	multu	$t9,$t2
/*  f0ef664:	8fae0028 */ 	lw	$t6,0x28($sp)
/*  f0ef668:	3c01e400 */ 	lui	$at,0xe400
/*  f0ef66c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0ef670:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f0ef674:	250f0020 */ 	addiu	$t7,$t0,0x20
/*  f0ef678:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0ef67c:	01c01825 */ 	or	$v1,$t6,$zero
/*  f0ef680:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f0ef684:	00005812 */ 	mflo	$t3
/*  f0ef688:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f0ef68c:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f0ef690:	01a17025 */ 	or	$t6,$t5,$at
/*  f0ef694:	01d95025 */ 	or	$t2,$t6,$t9
/*  f0ef698:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0ef69c:	8ccc0000 */ 	lw	$t4,0x0($a2)
/*  f0ef6a0:	00075880 */ 	sll	$t3,$a3,0x2
/*  f0ef6a4:	00087080 */ 	sll	$t6,$t0,0x2
/*  f0ef6a8:	016c0019 */ 	multu	$t3,$t4
/*  f0ef6ac:	31d90fff */ 	andi	$t9,$t6,0xfff
/*  f0ef6b0:	00006812 */ 	mflo	$t5
/*  f0ef6b4:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f0ef6b8:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0ef6bc:	03195025 */ 	or	$t2,$t8,$t9
/*  f0ef6c0:	ac6a0004 */ 	sw	$t2,0x4($v1)
/*  f0ef6c4:	8fab0028 */ 	lw	$t3,0x28($sp)
/*  f0ef6c8:	3c0f0010 */ 	lui	$t7,0x10
/*  f0ef6cc:	35ef03f0 */ 	ori	$t7,$t7,0x3f0
/*  f0ef6d0:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f0ef6d4:	afac0028 */ 	sw	$t4,0x28($sp)
/*  f0ef6d8:	3c0db400 */ 	lui	$t5,0xb400
/*  f0ef6dc:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f0ef6e0:	ad6f0004 */ 	sw	$t7,0x4($t3)
/*  f0ef6e4:	8fae0028 */ 	lw	$t6,0x28($sp)
/*  f0ef6e8:	3c19b300 */ 	lui	$t9,0xb300
/*  f0ef6ec:	01602025 */ 	or	$a0,$t3,$zero
/*  f0ef6f0:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f0ef6f4:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f0ef6f8:	add90000 */ 	sw	$t9,0x0($t6)
/*  f0ef6fc:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f0ef700:	240b0400 */ 	addiu	$t3,$zero,0x400
/*  f0ef704:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0ef708:	016a001a */ 	div	$zero,$t3,$t2
/*  f0ef70c:	00006012 */ 	mflo	$t4
/*  f0ef710:	318dffff */ 	andi	$t5,$t4,0xffff
/*  f0ef714:	000d7c00 */ 	sll	$t7,$t5,0x10
/*  f0ef718:	35eefc00 */ 	ori	$t6,$t7,0xfc00
/*  f0ef71c:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f0ef720:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0ef724:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f0ef728:	15400002 */ 	bnez	$t2,.L0f0ef734
/*  f0ef72c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ef730:	0007000d */ 	break	0x7
.L0f0ef734:
/*  f0ef734:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ef738:	15410004 */ 	bne	$t2,$at,.L0f0ef74c
/*  f0ef73c:	3c018000 */ 	lui	$at,0x8000
/*  f0ef740:	15610002 */ 	bne	$t3,$at,.L0f0ef74c
/*  f0ef744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ef748:	0006000d */ 	break	0x6
.L0f0ef74c:
/*  f0ef74c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0ef750:	03e00008 */ 	jr	$ra
/*  f0ef754:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ef758
/*  f0ef758:	3c018006 */ 	lui	$at,0x8006
/*  f0ef75c:	c4241630 */ 	lwc1	$f4,0x1630($at)
/*  f0ef760:	3c014080 */ 	lui	$at,0x4080
/*  f0ef764:	44814000 */ 	mtc1	$at,$f8
/*  f0ef768:	46002187 */ 	neg.s	$f6,$f4
/*  f0ef76c:	3c014248 */ 	lui	$at,0x4248
/*  f0ef770:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0ef774:	44818000 */ 	mtc1	$at,$f16
/*  f0ef778:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f0ef77c:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f0ef780:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f0ef784:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*  f0ef788:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0ef78c:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0ef790:	8fb000b8 */ 	lw	$s0,0xb8($sp)
/*  f0ef794:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0ef798:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0ef79c:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f0ef7a0:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f0ef7a4:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f0ef7a8:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0ef7ac:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0ef7b0:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f0ef7b4:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0ef7b8:	44152000 */ 	mfc1	$s5,$f4
/*  f0ef7bc:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0ef7c0:	afad00a0 */ 	sw	$t5,0xa0($sp)
/*  f0ef7c4:	3c0ee700 */ 	lui	$t6,0xe700
/*  f0ef7c8:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0ef7cc:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0ef7d0:	0010c042 */ 	srl	$t8,$s0,0x1
/*  f0ef7d4:	03008025 */ 	or	$s0,$t8,$zero
/*  f0ef7d8:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0ef7dc:	37391301 */ 	ori	$t9,$t9,0x1301
/*  f0ef7e0:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f0ef7e4:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f0ef7e8:	00c09025 */ 	or	$s2,$a2,$zero
/*  f0ef7ec:	00e09825 */ 	or	$s3,$a3,$zero
/*  f0ef7f0:	06a10004 */ 	bgez	$s5,.L0f0ef804
/*  f0ef7f4:	32af0003 */ 	andi	$t7,$s5,0x3
/*  f0ef7f8:	11e00002 */ 	beqz	$t7,.L0f0ef804
/*  f0ef7fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ef800:	25effffc */ 	addiu	$t7,$t7,-4
.L0f0ef804:
/*  f0ef804:	01e0a825 */ 	or	$s5,$t7,$zero
/*  f0ef808:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0ef80c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0ef810:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0ef814:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0ef818:	afb800a0 */ 	sw	$t8,0xa0($sp)
/*  f0ef81c:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f0ef820:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0ef824:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*  f0ef828:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0ef82c:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f0ef830:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0ef834:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f0ef838:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0ef83c:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0ef840:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0ef844:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0ef848:	35ad1001 */ 	ori	$t5,$t5,0x1001
/*  f0ef84c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0ef850:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*  f0ef854:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0ef858:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0ef85c:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f0ef860:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0ef864:	37180903 */ 	ori	$t8,$t8,0x903
/*  f0ef868:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0ef86c:	afaf00a0 */ 	sw	$t7,0xa0($sp)
/*  f0ef870:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f0ef874:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0ef878:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0ef87c:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f0ef880:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0ef884:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f0ef888:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0ef88c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0ef890:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0ef894:	27a400a0 */ 	addiu	$a0,$sp,0xa0
/*  f0ef898:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0ef89c:	24a50294 */ 	addiu	$a1,$a1,0x0294
/*  f0ef8a0:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0ef8a4:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0ef8a8:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f0ef8ac:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0ef8b0:	afb800a0 */ 	sw	$t8,0xa0($sp)
/*  f0ef8b4:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f0ef8b8:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0ef8bc:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*  f0ef8c0:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0ef8c4:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f0ef8c8:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0ef8cc:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f0ef8d0:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0ef8d4:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0ef8d8:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0ef8dc:	3c0dfc12 */ 	lui	$t5,0xfc12
/*  f0ef8e0:	3c0eff37 */ 	lui	$t6,0xff37
/*  f0ef8e4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0ef8e8:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*  f0ef8ec:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f0ef8f0:	35ad9a25 */ 	ori	$t5,$t5,0x9a25
/*  f0ef8f4:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0ef8f8:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f0ef8fc:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0ef900:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ef904:	02016825 */ 	or	$t5,$s0,$at
/*  f0ef908:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0ef90c:	afb800a0 */ 	sw	$t8,0xa0($sp)
/*  f0ef910:	3c19fb00 */ 	lui	$t9,0xfb00
/*  f0ef914:	0272082a */ 	slt	$at,$s3,$s2
/*  f0ef918:	02408825 */ 	or	$s1,$s2,$zero
/*  f0ef91c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0ef920:	1420004e */ 	bnez	$at,.L0f0efa5c
/*  f0ef924:	aded0004 */ 	sw	$t5,0x4($t7)
/*  f0ef928:	00127100 */ 	sll	$t6,$s2,0x4
/*  f0ef92c:	3c0f8007 */ 	lui	$t7,%hi(var800711f4)
/*  f0ef930:	25ef11f4 */ 	addiu	$t7,$t7,%lo(var800711f4)
/*  f0ef934:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f0ef938:	8fb300b4 */ 	lw	$s3,0xb4($sp)
/*  f0ef93c:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f0ef940:	8fb200b0 */ 	lw	$s2,0xb0($sp)
/*  f0ef944:	241e0011 */ 	addiu	$s8,$zero,0x11
/*  f0ef948:	2417000e */ 	addiu	$s7,$zero,0xe
/*  f0ef94c:	2414ffff */ 	addiu	$s4,$zero,-1
.L0f0ef950:
/*  f0ef950:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f0ef954:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0ef958:	56980005 */ 	bnel	$s4,$t8,.L0f0ef970
/*  f0ef95c:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0ef960:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0ef964:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f0ef968:	ae0d000c */ 	sw	$t5,0xc($s0)
/*  f0ef96c:	8e080008 */ 	lw	$t0,0x8($s0)
.L0f0ef970:
/*  f0ef970:	56880005 */ 	bnel	$s4,$t0,.L0f0ef988
/*  f0ef974:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0ef978:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0ef97c:	25c80001 */ 	addiu	$t0,$t6,0x1
/*  f0ef980:	ae080008 */ 	sw	$t0,0x8($s0)
/*  f0ef984:	8e0a0000 */ 	lw	$t2,0x0($s0)
.L0f0ef988:
/*  f0ef988:	150a0002 */ 	bne	$t0,$t2,.L0f0ef994
/*  f0ef98c:	25580001 */ 	addiu	$t8,$t2,0x1
/*  f0ef990:	ae180008 */ 	sw	$t8,0x8($s0)
.L0f0ef994:
/*  f0ef994:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0ef998:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f0ef99c:	252d0001 */ 	addiu	$t5,$t1,0x1
/*  f0ef9a0:	57290004 */ 	bnel	$t9,$t1,.L0f0ef9b4
/*  f0ef9a4:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0ef9a8:	ae0d000c */ 	sw	$t5,0xc($s0)
/*  f0ef9ac:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0ef9b0:	8e080008 */ 	lw	$t0,0x8($s0)
.L0f0ef9b4:
/*  f0ef9b4:	010a082a */ 	slt	$at,$t0,$t2
/*  f0ef9b8:	50200005 */ 	beqzl	$at,.L0f0ef9d0
/*  f0ef9bc:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f0ef9c0:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f0ef9c4:	ae0a0008 */ 	sw	$t2,0x8($s0)
/*  f0ef9c8:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0ef9cc:	8e0b000c */ 	lw	$t3,0xc($s0)
.L0f0ef9d0:
/*  f0ef9d0:	0169082a */ 	slt	$at,$t3,$t1
/*  f0ef9d4:	50200006 */ 	beqzl	$at,.L0f0ef9f0
/*  f0ef9d8:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0ef9dc:	ae0b0004 */ 	sw	$t3,0x4($s0)
/*  f0ef9e0:	01205825 */ 	or	$t3,$t1,$zero
/*  f0ef9e4:	ae09000c */ 	sw	$t1,0xc($s0)
/*  f0ef9e8:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0ef9ec:	8e080008 */ 	lw	$t0,0x8($s0)
.L0f0ef9f0:
/*  f0ef9f0:	12370005 */ 	beq	$s1,$s7,.L0f0efa08
/*  f0ef9f4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0ef9f8:	123e0003 */ 	beq	$s1,$s8,.L0f0efa08
/*  f0ef9fc:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0efa00:	56210003 */ 	bnel	$s1,$at,.L0f0efa10
/*  f0efa04:	86c20000 */ 	lh	$v0,0x0($s6)
.L0f0efa08:
/*  f0efa08:	00152823 */ 	negu	$a1,$s5
/*  f0efa0c:	86c20000 */ 	lh	$v0,0x0($s6)
.L0f0efa10:
/*  f0efa10:	86c30002 */ 	lh	$v1,0x2($s6)
/*  f0efa14:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0efa18:	01427021 */ 	addu	$t6,$t2,$v0
/*  f0efa1c:	01d23021 */ 	addu	$a2,$t6,$s2
/*  f0efa20:	0102c021 */ 	addu	$t8,$t0,$v0
/*  f0efa24:	01636821 */ 	addu	$t5,$t3,$v1
/*  f0efa28:	01b37021 */ 	addu	$t6,$t5,$s3
/*  f0efa2c:	0312c821 */ 	addu	$t9,$t8,$s2
/*  f0efa30:	01237821 */ 	addu	$t7,$t1,$v1
/*  f0efa34:	01f33821 */ 	addu	$a3,$t7,$s3
/*  f0efa38:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0efa3c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0efa40:	0fc3bce5 */ 	jal	func0f0ef394
/*  f0efa44:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0efa48:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f0efa4c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0efa50:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f0efa54:	1591ffbe */ 	bne	$t4,$s1,.L0f0ef950
/*  f0efa58:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L0f0efa5c:
/*  f0efa5c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0efa60:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f0efa64:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0efa68:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0efa6c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0efa70:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0efa74:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0efa78:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0efa7c:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0efa80:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f0efa84:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f0efa88:	03e00008 */ 	jr	$ra
/*  f0efa8c:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

GLOBAL_ASM(
glabel func0f0efa90
/*  f0efa90:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f0efa94:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f0efa98:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f0efa9c:	00057840 */ 	sll	$t7,$a1,0x1
/*  f0efaa0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0efaa4:	3c038007 */ 	lui	$v1,%hi(var80071354)
/*  f0efaa8:	00781821 */ 	addu	$v1,$v1,$t8
/*  f0efaac:	94631354 */ 	lhu	$v1,%lo(var80071354)($v1)
/*  f0efab0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0efab4:	240154c2 */ 	addiu	$at,$zero,0x54c2
/*  f0efab8:	14610013 */ 	bne	$v1,$at,.L0f0efb08
/*  f0efabc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0efac0:	3c198007 */ 	lui	$t9,%hi(g_MpPlayerNum)
/*  f0efac4:	8f391448 */ 	lw	$t9,%lo(g_MpPlayerNum)($t9)
/*  f0efac8:	3c04800a */ 	lui	$a0,%hi(g_MenuStack+0xe24)
/*  f0efacc:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0efad0:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f0efad4:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0efad8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0efadc:	01194021 */ 	addu	$t0,$t0,$t9
/*  f0efae0:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f0efae4:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0efae8:	00084100 */ 	sll	$t0,$t0,0x4
/*  f0efaec:	00882021 */ 	addu	$a0,$a0,$t0
/*  f0efaf0:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0efaf4:	8c84ee24 */ 	lw	$a0,%lo(g_MenuStack+0xe24)($a0)
/*  f0efaf8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0efafc:	14410002 */ 	bne	$v0,$at,.L0f0efb08
/*  f0efb00:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0efb04:	240354c3 */ 	addiu	$v1,$zero,0x54c3
.L0f0efb08:
/*  f0efb08:	240154c4 */ 	addiu	$at,$zero,0x54c4
/*  f0efb0c:	14610011 */ 	bne	$v1,$at,.L0f0efb54
/*  f0efb10:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f0efb14:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f0efb18:	3c04800a */ 	lui	$a0,%hi(g_MenuStack+0xe24)
/*  f0efb1c:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0efb20:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0efb24:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0efb28:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0efb2c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0efb30:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0efb34:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0efb38:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0efb3c:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f0efb40:	0fc549e0 */ 	jal	optionsGetForwardPitch
/*  f0efb44:	8c84ee24 */ 	lw	$a0,%lo(g_MenuStack+0xe24)($a0)
/*  f0efb48:	14400002 */ 	bnez	$v0,.L0f0efb54
/*  f0efb4c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0efb50:	240354c6 */ 	addiu	$v1,$zero,0x54c6
.L0f0efb54:
/*  f0efb54:	240154c5 */ 	addiu	$at,$zero,0x54c5
/*  f0efb58:	14610011 */ 	bne	$v1,$at,.L0f0efba0
/*  f0efb5c:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f0efb60:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f0efb64:	3c04800a */ 	lui	$a0,%hi(g_MenuStack+0xe24)
/*  f0efb68:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0efb6c:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f0efb70:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0efb74:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0efb78:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f0efb7c:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0efb80:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0efb84:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f0efb88:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f0efb8c:	0fc549e0 */ 	jal	optionsGetForwardPitch
/*  f0efb90:	8c84ee24 */ 	lw	$a0,%lo(g_MenuStack+0xe24)($a0)
/*  f0efb94:	14400002 */ 	bnez	$v0,.L0f0efba0
/*  f0efb98:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0efb9c:	240354c7 */ 	addiu	$v1,$zero,0x54c7
.L0f0efba0:
/*  f0efba0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0efba4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0efba8:	3062ffff */ 	andi	$v0,$v1,0xffff
/*  f0efbac:	03e00008 */ 	jr	$ra
/*  f0efbb0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0efbb4
/*  f0efbb4:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0efbb8:	3c0f8007 */ 	lui	$t7,%hi(var8007142c)
/*  f0efbbc:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f0efbc0:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f0efbc4:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f0efbc8:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f0efbcc:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f0efbd0:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f0efbd4:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f0efbd8:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0efbdc:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0efbe0:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0efbe4:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f0efbe8:	afa700a4 */ 	sw	$a3,0xa4($sp)
/*  f0efbec:	25ef142c */ 	addiu	$t7,$t7,%lo(var8007142c)
/*  f0efbf0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0efbf4:	27ae0074 */ 	addiu	$t6,$sp,0x74
/*  f0efbf8:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f0efbfc:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0efc00:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0efc04:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f0efc08:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f0efc0c:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0efc10:	95e10010 */ 	lhu	$at,0x10($t7)
/*  f0efc14:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f0efc18:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f0efc1c:	0fc54d8a */ 	jal	func0f153628
/*  f0efc20:	a5c10010 */ 	sh	$at,0x10($t6)
/*  f0efc24:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0efc28:	00009825 */ 	or	$s3,$zero,$zero
/*  f0efc2c:	0000b825 */ 	or	$s7,$zero,$zero
/*  f0efc30:	83be00b7 */ 	lb	$s8,0xb7($sp)
/*  f0efc34:	8fb400b0 */ 	lw	$s4,0xb0($sp)
.L0f0efc38:
/*  f0efc38:	8fa900a0 */ 	lw	$t1,0xa0($sp)
/*  f0efc3c:	8fac00a8 */ 	lw	$t4,0xa8($sp)
/*  f0efc40:	2ac10004 */ 	slti	$at,$s6,0x4
/*  f0efc44:	852a0002 */ 	lh	$t2,0x2($t1)
/*  f0efc48:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*  f0efc4c:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f0efc50:	02ea5821 */ 	addu	$t3,$s7,$t2
/*  f0efc54:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f0efc58:	14200006 */ 	bnez	$at,.L0f0efc74
/*  f0efc5c:	afad0090 */ 	sw	$t5,0x90($sp)
/*  f0efc60:	2a610004 */ 	slti	$at,$s3,0x4
/*  f0efc64:	14200022 */ 	bnez	$at,.L0f0efcf0
/*  f0efc68:	2a610008 */ 	slti	$at,$s3,0x8
/*  f0efc6c:	50200021 */ 	beqzl	$at,.L0f0efcf4
/*  f0efc70:	02c02025 */ 	or	$a0,$s6,$zero
.L0f0efc74:
/*  f0efc74:	87380000 */ 	lh	$t8,0x0($t9)
/*  f0efc78:	00134840 */ 	sll	$t1,$s3,0x1
/*  f0efc7c:	03a92021 */ 	addu	$a0,$sp,$t1
/*  f0efc80:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f0efc84:	25e8004c */ 	addiu	$t0,$t7,0x4c
/*  f0efc88:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f0efc8c:	0fc5b9f1 */ 	jal	langGet
/*  f0efc90:	94840074 */ 	lhu	$a0,0x74($a0)
/*  f0efc94:	0c002f02 */ 	jal	func0000bc08
/*  f0efc98:	00409025 */ 	or	$s2,$v0,$zero
/*  f0efc9c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0efca0:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0efca4:	0c002f06 */ 	jal	func0000bc18
/*  f0efca8:	01408025 */ 	or	$s0,$t2,$zero
/*  f0efcac:	3c0b8008 */ 	lui	$t3,%hi(var8007fb08)
/*  f0efcb0:	3c0c8008 */ 	lui	$t4,%hi(var8007fb04)
/*  f0efcb4:	8d8cfb04 */ 	lw	$t4,%lo(var8007fb04)($t4)
/*  f0efcb8:	8d6bfb08 */ 	lw	$t3,%lo(var8007fb08)($t3)
/*  f0efcbc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0efcc0:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0efcc4:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0efcc8:	02403825 */ 	or	$a3,$s2,$zero
/*  f0efccc:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f0efcd0:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0efcd4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0efcd8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0efcdc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0efce0:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0efce4:	0fc5580f */ 	jal	func0f15603c
/*  f0efce8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0efcec:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0efcf0:
/*  f0efcf0:	02c02025 */ 	or	$a0,$s6,$zero
.L0f0efcf4:
/*  f0efcf4:	0fc3bea4 */ 	jal	func0f0efa90
/*  f0efcf8:	02602825 */ 	or	$a1,$s3,$zero
/*  f0efcfc:	3050ffff */ 	andi	$s0,$v0,0xffff
/*  f0efd00:	07c00010 */ 	bltz	$s8,.L0f0efd44
/*  f0efd04:	8fb100ac */ 	lw	$s1,0xac($sp)
/*  f0efd08:	2ac10008 */ 	slti	$at,$s6,0x8
/*  f0efd0c:	14200008 */ 	bnez	$at,.L0f0efd30
/*  f0efd10:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0efd14:	27c40004 */ 	addiu	$a0,$s8,0x4
/*  f0efd18:	0fc3bea4 */ 	jal	func0f0efa90
/*  f0efd1c:	02602825 */ 	or	$a1,$s3,$zero
/*  f0efd20:	56020009 */ 	bnel	$s0,$v0,.L0f0efd48
/*  f0efd24:	2ac10004 */ 	slti	$at,$s6,0x4
/*  f0efd28:	10000006 */ 	beqz	$zero,.L0f0efd44
/*  f0efd2c:	02808825 */ 	or	$s1,$s4,$zero
.L0f0efd30:
/*  f0efd30:	0fc3bea4 */ 	jal	func0f0efa90
/*  f0efd34:	02602825 */ 	or	$a1,$s3,$zero
/*  f0efd38:	56020003 */ 	bnel	$s0,$v0,.L0f0efd48
/*  f0efd3c:	2ac10004 */ 	slti	$at,$s6,0x4
/*  f0efd40:	02808825 */ 	or	$s1,$s4,$zero
.L0f0efd44:
/*  f0efd44:	2ac10004 */ 	slti	$at,$s6,0x4
.L0f0efd48:
/*  f0efd48:	1420000b */ 	bnez	$at,.L0f0efd78
/*  f0efd4c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0efd50:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0efd54:	16610008 */ 	bne	$s3,$at,.L0f0efd78
/*  f0efd58:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*  f0efd5c:	85b90000 */ 	lh	$t9,0x0($t5)
/*  f0efd60:	8fb800a4 */ 	lw	$t8,0xa4($sp)
/*  f0efd64:	02808825 */ 	or	$s1,$s4,$zero
/*  f0efd68:	03387021 */ 	addu	$t6,$t9,$t8
/*  f0efd6c:	25cf003f */ 	addiu	$t7,$t6,0x3f
/*  f0efd70:	10000004 */ 	beqz	$zero,.L0f0efd84
/*  f0efd74:	afaf0094 */ 	sw	$t7,0x94($sp)
.L0f0efd78:
/*  f0efd78:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0efd7c:	02214025 */ 	or	$t0,$s1,$at
/*  f0efd80:	01008825 */ 	or	$s1,$t0,$zero
.L0f0efd84:
/*  f0efd84:	0fc5b9f1 */ 	jal	langGet
/*  f0efd88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0efd8c:	0c002f02 */ 	jal	func0000bc08
/*  f0efd90:	00409025 */ 	or	$s2,$v0,$zero
/*  f0efd94:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0efd98:	00104c03 */ 	sra	$t1,$s0,0x10
/*  f0efd9c:	0c002f06 */ 	jal	func0000bc18
/*  f0efda0:	01208025 */ 	or	$s0,$t1,$zero
/*  f0efda4:	3c0a8008 */ 	lui	$t2,%hi(var8007fb08)
/*  f0efda8:	3c0b8008 */ 	lui	$t3,%hi(var8007fb04)
/*  f0efdac:	8d6bfb04 */ 	lw	$t3,%lo(var8007fb04)($t3)
/*  f0efdb0:	8d4afb08 */ 	lw	$t2,%lo(var8007fb08)($t2)
/*  f0efdb4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0efdb8:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0efdbc:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0efdc0:	02403825 */ 	or	$a3,$s2,$zero
/*  f0efdc4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0efdc8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0efdcc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0efdd0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0efdd4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0efdd8:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0efddc:	0fc5580f */ 	jal	func0f15603c
/*  f0efde0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0efde4:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0efde8:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0efdec:	26f70007 */ 	addiu	$s7,$s7,0x7
/*  f0efdf0:	1661ff91 */ 	bne	$s3,$at,.L0f0efc38
/*  f0efdf4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0efdf8:	0fc54de0 */ 	jal	func0f153780
/*  f0efdfc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0efe00:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f0efe04:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0efe08:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0efe0c:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0efe10:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f0efe14:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f0efe18:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f0efe1c:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f0efe20:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f0efe24:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f0efe28:	03e00008 */ 	jr	$ra
/*  f0efe2c:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

GLOBAL_ASM(
glabel func0f0efe30
/*  f0efe30:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0efe34:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0efe38:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0efe3c:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0efe40:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0efe44:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0efe48:	84ae0000 */ 	lh	$t6,0x0($a1)
/*  f0efe4c:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0efe50:	86380002 */ 	lh	$t8,0x2($s1)
/*  f0efe54:	01c62821 */ 	addu	$a1,$t6,$a2
/*  f0efe58:	8fb00054 */ 	lw	$s0,0x54($sp)
/*  f0efe5c:	03073021 */ 	addu	$a2,$t8,$a3
/*  f0efe60:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f0efe64:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f0efe68:	24070033 */ 	addiu	$a3,$zero,0x33
/*  f0efe6c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0efe70:	0fc3bd2f */ 	jal	func0f0ef4bc
/*  f0efe74:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0efe78:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0efe7c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0efe80:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f0efe84:	24a50020 */ 	addiu	$a1,$a1,0x20
/*  f0efe88:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0efe8c:	24070034 */ 	addiu	$a3,$zero,0x34
/*  f0efe90:	0fc3bd2f */ 	jal	func0f0ef4bc
/*  f0efe94:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0efe98:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f0efe9c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0efea0:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0efea4:	24c60020 */ 	addiu	$a2,$a2,0x20
/*  f0efea8:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f0efeac:	24070035 */ 	addiu	$a3,$zero,0x35
/*  f0efeb0:	0fc3bd2f */ 	jal	func0f0ef4bc
/*  f0efeb4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0efeb8:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f0efebc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0efec0:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f0efec4:	24070036 */ 	addiu	$a3,$zero,0x36
/*  f0efec8:	0fc3bd2f */ 	jal	func0f0ef4bc
/*  f0efecc:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0efed0:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f0efed4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0efed8:	02202825 */ 	or	$a1,$s1,$zero
/*  f0efedc:	29010004 */ 	slti	$at,$t0,0x4
/*  f0efee0:	1420000c */ 	bnez	$at,.L0f0eff14
/*  f0efee4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0efee8:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f0efeec:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f0efef0:	02202825 */ 	or	$a1,$s1,$zero
/*  f0efef4:	2406000d */ 	addiu	$a2,$zero,0xd
/*  f0efef8:	24070013 */ 	addiu	$a3,$zero,0x13
/*  f0efefc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eff00:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0eff04:	0fc3bdd6 */ 	jal	func0f0ef758
/*  f0eff08:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0eff0c:	10000009 */ 	beqz	$zero,.L0f0eff34
/*  f0eff10:	00402025 */ 	or	$a0,$v0,$zero
.L0f0eff14:
/*  f0eff14:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f0eff18:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0eff1c:	24070015 */ 	addiu	$a3,$zero,0x15
/*  f0eff20:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eff24:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0eff28:	0fc3bdd6 */ 	jal	func0f0ef758
/*  f0eff2c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0eff30:	00402025 */ 	or	$a0,$v0,$zero
.L0f0eff34:
/*  f0eff34:	8fad004c */ 	lw	$t5,0x4c($sp)
/*  f0eff38:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f0eff3c:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f0eff40:	83b80063 */ 	lb	$t8,0x63($sp)
/*  f0eff44:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0eff48:	02203025 */ 	or	$a2,$s1,$zero
/*  f0eff4c:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0eff50:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0eff54:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0eff58:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0eff5c:	0fc3beed */ 	jal	func0f0efbb4
/*  f0eff60:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0eff64:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0eff68:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0eff6c:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0eff70:	03e00008 */ 	jr	$ra
/*  f0eff74:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f0eff78
/*  f0eff78:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f0eff7c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0eff80:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0eff84:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f0eff88:	8ca70010 */ 	lw	$a3,0x10($a1)
/*  f0eff8c:	8cb00014 */ 	lw	$s0,0x14($a1)
/*  f0eff90:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f0eff94:	0fc54f49 */ 	jal	func0f153d24
/*  f0eff98:	afa70068 */ 	sw	$a3,0x68($sp)
/*  f0eff9c:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f0effa0:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
/*  f0effa4:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f0effa8:	24080e70 */ 	addiu	$t0,$zero,0xe70
/*  f0effac:	3c05800a */ 	lui	$a1,0x800a
/*  f0effb0:	01c80019 */ 	multu	$t6,$t0
/*  f0effb4:	24a5e000 */ 	addiu	$a1,$a1,-8192
/*  f0effb8:	92020002 */ 	lbu	$v0,0x2($s0)
/*  f0effbc:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0effc0:	00007812 */ 	mflo	$t7
/*  f0effc4:	00afc021 */ 	addu	$t8,$a1,$t7
/*  f0effc8:	8f030e20 */ 	lw	$v1,0xe20($t8)
/*  f0effcc:	307900ff */ 	andi	$t9,$v1,0xff
/*  f0effd0:	50590014 */ 	beql	$v0,$t9,.L0f0f0024
/*  f0effd4:	92180003 */ 	lbu	$t8,0x3($s0)
/*  f0effd8:	a2020004 */ 	sb	$v0,0x4($s0)
/*  f0effdc:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f0effe0:	01280019 */ 	multu	$t1,$t0
/*  f0effe4:	00005012 */ 	mflo	$t2
/*  f0effe8:	00aa5821 */ 	addu	$t3,$a1,$t2
/*  f0effec:	8d6c0e20 */ 	lw	$t4,0xe20($t3)
/*  f0efff0:	a2000000 */ 	sb	$zero,0x0($s0)
/*  f0efff4:	a20c0002 */ 	sb	$t4,0x2($s0)
/*  f0efff8:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f0efffc:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f0f0000:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f0004:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f0008:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0f000c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f0010:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f0014:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f0018:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f0f001c:	8de30e20 */ 	lw	$v1,0xe20($t7)
/*  f0f0020:	92180003 */ 	lbu	$t8,0x3($s0)
.L0f0f0024:
/*  f0f0024:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f0028:	17010008 */ 	bne	$t8,$at,.L0f0f004c
/*  f0f002c:	2c610004 */ 	sltiu	$at,$v1,0x4
/*  f0f0030:	1020000d */ 	beqz	$at,.L0f0f0068
/*  f0f0034:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0f0038:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0f003c:	a2190003 */ 	sb	$t9,0x3($s0)
/*  f0f0040:	a2000001 */ 	sb	$zero,0x1($s0)
/*  f0f0044:	10000008 */ 	beqz	$zero,.L0f0f0068
/*  f0f0048:	a2090004 */ 	sb	$t1,0x4($s0)
.L0f0f004c:
/*  f0f004c:	2c610004 */ 	sltiu	$at,$v1,0x4
/*  f0f0050:	14200005 */ 	bnez	$at,.L0f0f0068
/*  f0f0054:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f0058:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0f005c:	a20a0003 */ 	sb	$t2,0x3($s0)
/*  f0f0060:	a2000001 */ 	sb	$zero,0x1($s0)
/*  f0f0064:	a20b0004 */ 	sb	$t3,0x4($s0)
.L0f0f0068:
/*  f0f0068:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f0f006c:	286100ff */ 	slti	$at,$v1,0xff
/*  f0f0070:	10200009 */ 	beqz	$at,.L0f0f0098
/*  f0f0074:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x40)
/*  f0f0078:	8d8ca000 */ 	lw	$t4,%lo(g_Vars+0x40)($t4)
/*  f0f007c:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f0f0080:	006d1021 */ 	addu	$v0,$v1,$t5
/*  f0f0084:	28410100 */ 	slti	$at,$v0,0x100
/*  f0f0088:	54200003 */ 	bnezl	$at,.L0f0f0098
/*  f0f008c:	a2020000 */ 	sb	$v0,0x0($s0)
/*  f0f0090:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f0f0094:	a2020000 */ 	sb	$v0,0x0($s0)
.L0f0f0098:
/*  f0f0098:	92020001 */ 	lbu	$v0,0x1($s0)
/*  f0f009c:	284100ff */ 	slti	$at,$v0,0xff
/*  f0f00a0:	1020000b */ 	beqz	$at,.L0f0f00d0
/*  f0f00a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f00a8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x40)
/*  f0f00ac:	8dcea000 */ 	lw	$t6,%lo(g_Vars+0x40)($t6)
/*  f0f00b0:	000e7840 */ 	sll	$t7,$t6,0x1
/*  f0f00b4:	008f1821 */ 	addu	$v1,$a0,$t7
/*  f0f00b8:	28610100 */ 	slti	$at,$v1,0x100
/*  f0f00bc:	54200003 */ 	bnezl	$at,.L0f0f00cc
/*  f0f00c0:	a2030001 */ 	sb	$v1,0x1($s0)
/*  f0f00c4:	240300ff */ 	addiu	$v1,$zero,0xff
/*  f0f00c8:	a2030001 */ 	sb	$v1,0x1($s0)
.L0f0f00cc:
/*  f0f00cc:	306200ff */ 	andi	$v0,$v1,0xff
.L0f0f00d0:
/*  f0f00d0:	92180000 */ 	lbu	$t8,0x0($s0)
/*  f0f00d4:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f0f00d8:	afa70068 */ 	sw	$a3,0x68($sp)
/*  f0f00dc:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0f00e0:	0fc54d8a */ 	jal	func0f153628
/*  f0f00e4:	afb80060 */ 	sw	$t8,0x60($sp)
/*  f0f00e8:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f00ec:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0f00f0:	44803000 */ 	mtc1	$zero,$f6
/*  f0f00f4:	c4e40040 */ 	lwc1	$f4,0x40($a3)
/*  f0f00f8:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0f00fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0100:	4502000c */ 	bc1fl	.L0f0f0134
/*  f0f0104:	90ec003d */ 	lbu	$t4,0x3d($a3)
/*  f0f0108:	90f9003c */ 	lbu	$t9,0x3c($a3)
/*  f0f010c:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0f0110:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0f0114:	00194900 */ 	sll	$t1,$t9,0x4
/*  f0f0118:	01394823 */ 	subu	$t1,$t1,$t9
/*  f0f011c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0f0120:	00495021 */ 	addu	$t2,$v0,$t1
/*  f0f0124:	8d4b0018 */ 	lw	$t3,0x18($t2)
/*  f0f0128:	10000014 */ 	beqz	$zero,.L0f0f017c
/*  f0f012c:	afab0098 */ 	sw	$t3,0x98($sp)
/*  f0f0130:	90ec003d */ 	lbu	$t4,0x3d($a3)
.L0f0f0134:
/*  f0f0134:	90ef003c */ 	lbu	$t7,0x3c($a3)
/*  f0f0138:	3c027f1b */ 	lui	$v0,%hi(var7f1b1fb0)
/*  f0f013c:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0f0140:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0f0144:	24421fb0 */ 	addiu	$v0,$v0,%lo(var7f1b1fb0)
/*  f0f0148:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f014c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f0150:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f0154:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f0158:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0f015c:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f0f0160:	8f250018 */ 	lw	$a1,0x18($t9)
/*  f0f0164:	8dc40018 */ 	lw	$a0,0x18($t6)
/*  f0f0168:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f016c:	0fc01a40 */ 	jal	func0f006900
/*  f0f0170:	afa70068 */ 	sw	$a3,0x68($sp)
/*  f0f0174:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f0178:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0f017c:
/*  f0f017c:	8ce9000c */ 	lw	$t1,0xc($a3)
/*  f0f0180:	5120000e */ 	beqzl	$t1,.L0f0f01bc
/*  f0f0184:	90e2003c */ 	lbu	$v0,0x3c($a3)
/*  f0f0188:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f018c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f0190:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0f0194:	0fc01a40 */ 	jal	func0f006900
/*  f0f0198:	afa70068 */ 	sw	$a3,0x68($sp)
/*  f0f019c:	8fab0098 */ 	lw	$t3,0x98($sp)
/*  f0f01a0:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f01a4:	00415024 */ 	and	$t2,$v0,$at
/*  f0f01a8:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f0f01ac:	014c6825 */ 	or	$t5,$t2,$t4
/*  f0f01b0:	afad0098 */ 	sw	$t5,0x98($sp)
/*  f0f01b4:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f01b8:	90e2003c */ 	lbu	$v0,0x3c($a3)
.L0f0f01bc:
/*  f0f01bc:	3c047f1b */ 	lui	$a0,%hi(var7f1b2298)
/*  f0f01c0:	3c057f1b */ 	lui	$a1,%hi(var7f1b2130)
/*  f0f01c4:	00027100 */ 	sll	$t6,$v0,0x4
/*  f0f01c8:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f0f01cc:	000e1080 */ 	sll	$v0,$t6,0x2
/*  f0f01d0:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0f01d4:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0f01d8:	8ca52130 */ 	lw	$a1,%lo(var7f1b2130)($a1)
/*  f0f01dc:	0fc54f8e */ 	jal	func0f153e38
/*  f0f01e0:	8c842298 */ 	lw	$a0,%lo(var7f1b2298)($a0)
/*  f0f01e4:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0f01e8:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0f01ec:	3c19800a */ 	lui	$t9,%hi(g_MenuStack+0xe20)
/*  f0f01f0:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f01f4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f01f8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f01fc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f0200:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f0204:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f0208:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f020c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f0210:	8f39ee20 */ 	lw	$t9,%lo(g_MenuStack+0xe20)($t9)
/*  f0f0214:	2f210004 */ 	sltiu	$at,$t9,0x4
/*  f0f0218:	1420001f */ 	bnez	$at,.L0f0f0298
/*  f0f021c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0220:	0fc5b9f1 */ 	jal	langGet
/*  f0f0224:	240454d5 */ 	addiu	$a0,$zero,0x54d5
/*  f0f0228:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f0f022c:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f0f0230:	3c0a800a */ 	lui	$t2,%hi(g_MenuStack+0xe20)
/*  f0f0234:	3c048007 */ 	lui	$a0,%hi(g_ControlStyleOptions)
/*  f0f0238:	000958c0 */ 	sll	$t3,$t1,0x3
/*  f0f023c:	01695823 */ 	subu	$t3,$t3,$t1
/*  f0f0240:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f0244:	01695821 */ 	addu	$t3,$t3,$t1
/*  f0f0248:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0f024c:	01695823 */ 	subu	$t3,$t3,$t1
/*  f0f0250:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f0f0254:	014b5021 */ 	addu	$t2,$t2,$t3
/*  f0f0258:	8d4aee20 */ 	lw	$t2,%lo(g_MenuStack+0xe20)($t2)
/*  f0f025c:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f0260:	000a6040 */ 	sll	$t4,$t2,0x1
/*  f0f0264:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f0f0268:	0fc5b9f1 */ 	jal	langGet
/*  f0f026c:	948419d0 */ 	lhu	$a0,%lo(g_ControlStyleOptions)($a0)
/*  f0f0270:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f0f0274:	0fc5b9f1 */ 	jal	langGet
/*  f0f0278:	240454d7 */ 	addiu	$a0,$zero,0x54d7
/*  f0f027c:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0f0280:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f0f0284:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0f0288:	0c004dad */ 	jal	sprintf
/*  f0f028c:	00403825 */ 	or	$a3,$v0,$zero
/*  f0f0290:	1000001e */ 	beqz	$zero,.L0f0f030c
/*  f0f0294:	8fa200a4 */ 	lw	$v0,0xa4($sp)
.L0f0f0298:
/*  f0f0298:	0fc5b9f1 */ 	jal	langGet
/*  f0f029c:	240454d5 */ 	addiu	$a0,$zero,0x54d5
/*  f0f02a0:	3c0d8007 */ 	lui	$t5,%hi(g_MpPlayerNum)
/*  f0f02a4:	8dad1448 */ 	lw	$t5,%lo(g_MpPlayerNum)($t5)
/*  f0f02a8:	3c0f800a */ 	lui	$t7,%hi(g_MenuStack+0xe20)
/*  f0f02ac:	3c048007 */ 	lui	$a0,%hi(g_ControlStyleOptions)
/*  f0f02b0:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f0f02b4:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f02b8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f02bc:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0f02c0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f02c4:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f02c8:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f02cc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f02d0:	8defee20 */ 	lw	$t7,%lo(g_MenuStack+0xe20)($t7)
/*  f0f02d4:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f02d8:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f0f02dc:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0f02e0:	0fc5b9f1 */ 	jal	langGet
/*  f0f02e4:	948419d0 */ 	lhu	$a0,%lo(g_ControlStyleOptions)($a0)
/*  f0f02e8:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f0f02ec:	0fc5b9f1 */ 	jal	langGet
/*  f0f02f0:	240454d6 */ 	addiu	$a0,$zero,0x54d6
/*  f0f02f4:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0f02f8:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f0f02fc:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0f0300:	0c004dad */ 	jal	sprintf
/*  f0f0304:	00403825 */ 	or	$a3,$v0,$zero
/*  f0f0308:	8fa200a4 */ 	lw	$v0,0xa4($sp)
.L0f0f030c:
/*  f0f030c:	84590000 */ 	lh	$t9,0x0($v0)
/*  f0f0310:	27290002 */ 	addiu	$t1,$t9,0x2
/*  f0f0314:	afa90090 */ 	sw	$t1,0x90($sp)
/*  f0f0318:	844b0002 */ 	lh	$t3,0x2($v0)
/*  f0f031c:	256a0002 */ 	addiu	$t2,$t3,0x2
/*  f0f0320:	0c002f02 */ 	jal	func0000bc08
/*  f0f0324:	afaa008c */ 	sw	$t2,0x8c($sp)
/*  f0f0328:	0c002f06 */ 	jal	func0000bc18
/*  f0f032c:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f0f0330:	3c0c8008 */ 	lui	$t4,%hi(var8007fb10)
/*  f0f0334:	3c0d8008 */ 	lui	$t5,%hi(var8007fb0c)
/*  f0f0338:	8dadfb0c */ 	lw	$t5,%lo(var8007fb0c)($t5)
/*  f0f033c:	8d8cfb10 */ 	lw	$t4,%lo(var8007fb10)($t4)
/*  f0f0340:	8fae0098 */ 	lw	$t6,0x98($sp)
/*  f0f0344:	87af0048 */ 	lh	$t7,0x48($sp)
/*  f0f0348:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0f034c:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0f0350:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0f0354:	27a7006c */ 	addiu	$a3,$sp,0x6c
/*  f0f0358:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f035c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f0360:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f0364:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0f0368:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f036c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0f0370:	0fc5580f */ 	jal	func0f15603c
/*  f0f0374:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f0378:	0fc54de0 */ 	jal	func0f153780
/*  f0f037c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f0380:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f0384:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f0388:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0f038c:	00812824 */ 	and	$a1,$a0,$at
/*  f0f0390:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0f0394:	0fc01a40 */ 	jal	func0f006900
/*  f0f0398:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f0f039c:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0f03a0:	afa20094 */ 	sw	$v0,0x94($sp)
/*  f0f03a4:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f03a8:	0fc01a40 */ 	jal	func0f006900
/*  f0f03ac:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f0f03b0:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f0f03b4:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f0f03b8:	3c03800a */ 	lui	$v1,%hi(g_MenuStack+0xe20)
/*  f0f03bc:	00404025 */ 	or	$t0,$v0,$zero
/*  f0f03c0:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0f03c4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f03c8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f03cc:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f03d0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f03d4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f03d8:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f03dc:	00791821 */ 	addu	$v1,$v1,$t9
/*  f0f03e0:	8c63ee20 */ 	lw	$v1,%lo(g_MenuStack+0xe20)($v1)
/*  f0f03e4:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0f03e8:	8fa500a4 */ 	lw	$a1,0xa4($sp)
/*  f0f03ec:	2c610004 */ 	sltiu	$at,$v1,0x4
/*  f0f03f0:	1420002c */ 	bnez	$at,.L0f0f04a4
/*  f0f03f4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f03f8:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f0f03fc:	8fab0094 */ 	lw	$t3,0x94($sp)
/*  f0f0400:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0f0404:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0f0408:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0f040c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f0410:	820a0004 */ 	lb	$t2,0x4($s0)
/*  f0f0414:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0f0418:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0f041c:	8fa500a4 */ 	lw	$a1,0xa4($sp)
/*  f0f0420:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f0424:	2407000c */ 	addiu	$a3,$zero,0xc
/*  f0f0428:	0fc3bf8c */ 	jal	func0f0efe30
/*  f0f042c:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0f0430:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f0f0434:	8d8c1448 */ 	lw	$t4,%lo(g_MpPlayerNum)($t4)
/*  f0f0438:	3c0e800a */ 	lui	$t6,%hi(g_MenuStack+0xe20)
/*  f0f043c:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f0f0440:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f0f0444:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f0448:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f044c:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0f0450:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0f0454:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f0458:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f0f045c:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0f0460:	8dceee20 */ 	lw	$t6,%lo(g_MenuStack+0xe20)($t6)
/*  f0f0464:	8fb90094 */ 	lw	$t9,0x94($sp)
/*  f0f0468:	8fa90098 */ 	lw	$t1,0x98($sp)
/*  f0f046c:	25cf0004 */ 	addiu	$t7,$t6,0x4
/*  f0f0470:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0f0474:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f0478:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0f047c:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0f0480:	820b0004 */ 	lb	$t3,0x4($s0)
/*  f0f0484:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f0488:	8fa500a4 */ 	lw	$a1,0xa4($sp)
/*  f0f048c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f0490:	24070050 */ 	addiu	$a3,$zero,0x50
/*  f0f0494:	0fc3bf8c */ 	jal	func0f0efe30
/*  f0f0498:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0f049c:	10000030 */ 	beqz	$zero,.L0f0f0560
/*  f0f04a0:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L0f0f04a4:
/*  f0f04a4:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f0f04a8:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f0f04ac:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0f04b0:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0f04b4:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0f04b8:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0f04bc:	820d0004 */ 	lb	$t5,0x4($s0)
/*  f0f04c0:	afa80098 */ 	sw	$t0,0x98($sp)
/*  f0f04c4:	2407000f */ 	addiu	$a3,$zero,0xf
/*  f0f04c8:	0fc3bf8c */ 	jal	func0f0efe30
/*  f0f04cc:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f0f04d0:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f0f04d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f04d8:	85cf0000 */ 	lh	$t7,0x0($t6)
/*  f0f04dc:	afaf0090 */ 	sw	$t7,0x90($sp)
/*  f0f04e0:	85d80002 */ 	lh	$t8,0x2($t6)
/*  f0f04e4:	2719005c */ 	addiu	$t9,$t8,0x5c
/*  f0f04e8:	0fc54d8a */ 	jal	func0f153628
/*  f0f04ec:	afb9008c */ 	sw	$t9,0x8c($sp)
/*  f0f04f0:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0f04f4:	0fc5b9f1 */ 	jal	langGet
/*  f0f04f8:	240454d8 */ 	addiu	$a0,$zero,0x54d8
/*  f0f04fc:	0c002f02 */ 	jal	func0000bc08
/*  f0f0500:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f0504:	0c002f06 */ 	jal	func0000bc18
/*  f0f0508:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f0f050c:	3c098008 */ 	lui	$t1,%hi(var8007fb10)
/*  f0f0510:	3c0b8008 */ 	lui	$t3,%hi(var8007fb0c)
/*  f0f0514:	8d6bfb0c */ 	lw	$t3,%lo(var8007fb0c)($t3)
/*  f0f0518:	8d29fb10 */ 	lw	$t1,%lo(var8007fb10)($t1)
/*  f0f051c:	8faa0098 */ 	lw	$t2,0x98($sp)
/*  f0f0520:	87ac0048 */ 	lh	$t4,0x48($sp)
/*  f0f0524:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0f0528:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0f052c:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0f0530:	02003825 */ 	or	$a3,$s0,$zero
/*  f0f0534:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f0538:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f053c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f0540:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f0544:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0f0548:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0f054c:	0fc5580f */ 	jal	func0f15603c
/*  f0f0550:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0f0554:	0fc54de0 */ 	jal	func0f153780
/*  f0f0558:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f055c:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L0f0f0560:
/*  f0f0560:	0fc54f4f */ 	jal	func0f153d3c
/*  f0f0564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0568:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f056c:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f0f0570:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0f0574:	03e00008 */ 	jr	$ra
/*  f0f0578:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

GLOBAL_ASM(
glabel func0f0f057c
/*  f0f057c:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f0f0580:	240effff */ 	addiu	$t6,$zero,-1
/*  f0f0584:	a0800000 */ 	sb	$zero,0x0($a0)
/*  f0f0588:	a0800001 */ 	sb	$zero,0x1($a0)
/*  f0f058c:	a0820002 */ 	sb	$v0,0x2($a0)
/*  f0f0590:	a0820003 */ 	sb	$v0,0x3($a0)
/*  f0f0594:	03e00008 */ 	jr	$ra
/*  f0f0598:	a08e0004 */ 	sb	$t6,0x4($a0)
);

GLOBAL_ASM(
glabel func0f0f059c
.late_rodata
glabel var7f1b1e90
.word func0f0f059c+0x94 # f0f0630
glabel var7f1b1e94
.word func0f0f059c+0x34 # f0f05d0
glabel var7f1b1e98
.word func0f0f059c+0x154 # f0f06f0
glabel var7f1b1e9c
.word func0f0f059c+0x44 # f0f05e0
glabel var7f1b1ea0
.word func0f0f059c+0x74 # f0f0610
glabel var7f1b1ea4
.word func0f0f059c+0xc4 # f0f0660
glabel var7f1b1ea8
.word func0f0f059c+0xd4 # f0f0670
glabel var7f1b1eac
.word func0f0f059c+0x54 # f0f05f0
glabel var7f1b1eb0
.word func0f0f059c+0x64 # f0f0600
glabel var7f1b1eb4
.word func0f0f059c+0x154 # f0f06f0
glabel var7f1b1eb8
.word func0f0f059c+0xb4 # f0f0650
glabel var7f1b1ebc
.word func0f0f059c+0xe4 # f0f0680
glabel var7f1b1ec0
.word func0f0f059c+0xf4 # f0f0690
glabel var7f1b1ec4
.word func0f0f059c+0x104 # f0f06a0
glabel var7f1b1ec8
.word func0f0f059c+0x114 # f0f06b0
glabel var7f1b1ecc
.word func0f0f059c+0x154 # f0f06f0
glabel var7f1b1ed0
.word func0f0f059c+0x124 # f0f06c0
glabel var7f1b1ed4
.word func0f0f059c+0x134 # f0f06d0
glabel var7f1b1ed8
.word func0f0f059c+0x154 # f0f06f0
glabel var7f1b1edc
.word func0f0f059c+0x154 # f0f06f0
glabel var7f1b1ee0
.word func0f0f059c+0xa4 # f0f0640
glabel var7f1b1ee4
.word func0f0f059c+0x154 # f0f06f0
glabel var7f1b1ee8
.word func0f0f059c+0x84 # f0f0620
glabel var7f1b1eec
.word func0f0f059c+0x154 # f0f06f0
glabel var7f1b1ef0
.word func0f0f059c+0x144 # f0f06e0
.text
/*  f0f059c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f05a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f05a4:	8cae0008 */ 	lw	$t6,0x8($a1)
/*  f0f05a8:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*  f0f05ac:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f0f05b0:	2f010019 */ 	sltiu	$at,$t8,0x19
/*  f0f05b4:	1020004e */ 	beqz	$at,.L0f0f06f0
/*  f0f05b8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f05bc:	3c017f1b */ 	lui	$at,%hi(var7f1b1e90)
/*  f0f05c0:	00380821 */ 	addu	$at,$at,$t8
/*  f0f05c4:	8c381e90 */ 	lw	$t8,%lo(var7f1b1e90)($at)
/*  f0f05c8:	03000008 */ 	jr	$t8
/*  f0f05cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f05d0:	0fc398ca */ 	jal	func0f0e6328
/*  f0f05d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f05d8:	10000047 */ 	beqz	$zero,.L0f0f06f8
/*  f0f05dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f05e0:	0fc3abb0 */ 	jal	func0f0eaec0
/*  f0f05e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f05e8:	10000043 */ 	beqz	$zero,.L0f0f06f8
/*  f0f05ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f05f0:	0fc3ad42 */ 	jal	func0f0eb508
/*  f0f05f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f05f8:	1000003f */ 	beqz	$zero,.L0f0f06f8
/*  f0f05fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f0600:	0fc3b193 */ 	jal	func0f0ec64c
/*  f0f0604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0608:	1000003b */ 	beqz	$zero,.L0f0f06f8
/*  f0f060c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f0610:	0fc3b388 */ 	jal	func0f0ece20
/*  f0f0614:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0618:	10000037 */ 	beqz	$zero,.L0f0f06f8
/*  f0f061c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f0620:	0fc3b54a */ 	jal	func0f0ed528
/*  f0f0624:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0628:	10000033 */ 	beqz	$zero,.L0f0f06f8
/*  f0f062c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f0630:	0fc3a94b */ 	jal	func0f0ea52c
/*  f0f0634:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0638:	1000002f */ 	beqz	$zero,.L0f0f06f8
/*  f0f063c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f0640:	0fc3ab06 */ 	jal	func0f0eac18
/*  f0f0644:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0648:	1000002b */ 	beqz	$zero,.L0f0f06f8
/*  f0f064c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f0650:	0fc3a5f4 */ 	jal	func0f0e97d0
/*  f0f0654:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0658:	10000027 */ 	beqz	$zero,.L0f0f06f8
/*  f0f065c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f0660:	0fc3a8a4 */ 	jal	func0f0ea290
/*  f0f0664:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0668:	10000023 */ 	beqz	$zero,.L0f0f06f8
/*  f0f066c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f0670:	0fc3b6d9 */ 	jal	func0f0edb64
/*  f0f0674:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0678:	1000001f */ 	beqz	$zero,.L0f0f06f8
/*  f0f067c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f0680:	0fc39ea3 */ 	jal	func0f0e7a8c
/*  f0f0684:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0688:	1000001b */ 	beqz	$zero,.L0f0f06f8
/*  f0f068c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f0690:	0fc3a16b */ 	jal	func0f0e85ac
/*  f0f0694:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0698:	10000017 */ 	beqz	$zero,.L0f0f06f8
/*  f0f069c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f06a0:	0fc3b6db */ 	jal	func0f0edb6c
/*  f0f06a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f06a8:	10000013 */ 	beqz	$zero,.L0f0f06f8
/*  f0f06ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f06b0:	0fc3b992 */ 	jal	func0f0ee648
/*  f0f06b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f06b8:	1000000f */ 	beqz	$zero,.L0f0f06f8
/*  f0f06bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f06c0:	0fc3b08a */ 	jal	func0f0ec228
/*  f0f06c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f06c8:	1000000b */ 	beqz	$zero,.L0f0f06f8
/*  f0f06cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f06d0:	0fc3a8f6 */ 	jal	func0f0ea3d8
/*  f0f06d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f06d8:	10000007 */ 	beqz	$zero,.L0f0f06f8
/*  f0f06dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f06e0:	0fc3bfde */ 	jal	func0f0eff78
/*  f0f06e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f06e8:	10000003 */ 	beqz	$zero,.L0f0f06f8
/*  f0f06ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f06f0:
/*  f0f06f0:	00801025 */ 	or	$v0,$a0,$zero
/*  f0f06f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f06f8:
/*  f0f06f8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f06fc:	03e00008 */ 	jr	$ra
/*  f0f0700:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0f0704
.late_rodata
glabel var7f1b1ef4
.word func0f0f0704+0x40 # f0f0744
glabel var7f1b1ef8
.word func0f0f0704+0x144 # f0f0848
glabel var7f1b1efc
.word func0f0f0704+0x58 # f0f075c
glabel var7f1b1f00
.word func0f0f0704+0x9c # f0f07a0
glabel var7f1b1f04
.word func0f0f0704+0x144 # f0f0848
glabel var7f1b1f08
.word func0f0f0704+0x144 # f0f0848
glabel var7f1b1f0c
.word func0f0f0704+0x6c # f0f0770
glabel var7f1b1f10
.word func0f0f0704+0x88 # f0f078c
glabel var7f1b1f14
.word func0f0f0704+0x144 # f0f0848
glabel var7f1b1f18
.word func0f0f0704+0x144 # f0f0848
glabel var7f1b1f1c
.word func0f0f0704+0xe0 # f0f07e4
glabel var7f1b1f20
.word func0f0f0704+0xfc # f0f0800
glabel var7f1b1f24
.word func0f0f0704+0xc8 # f0f07cc
glabel var7f1b1f28
.word func0f0f0704+0x128 # f0f082c
glabel var7f1b1f2c
.word func0f0f0704+0x144 # f0f0848
glabel var7f1b1f30
.word func0f0f0704+0x114 # f0f0818
glabel var7f1b1f34
.word func0f0f0704+0x144 # f0f0848
glabel var7f1b1f38
.word func0f0f0704+0x144 # f0f0848
glabel var7f1b1f3c
.word func0f0f0704+0x144 # f0f0848
glabel var7f1b1f40
.word func0f0f0704+0x144 # f0f0848
glabel var7f1b1f44
.word func0f0f0704+0x144 # f0f0848
glabel var7f1b1f48
.word func0f0f0704+0xb8 # f0f07bc
.text
/*  f0f0704:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0f0708:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0f070c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0f0710:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f0714:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0f0718:	00c08025 */ 	or	$s0,$a2,$zero
/*  f0f071c:	00e08825 */ 	or	$s1,$a3,$zero
/*  f0f0720:	25cffffe */ 	addiu	$t7,$t6,-2
/*  f0f0724:	2de10016 */ 	sltiu	$at,$t7,0x16
/*  f0f0728:	10200047 */ 	beqz	$at,.L0f0f0848
/*  f0f072c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f0730:	3c017f1b */ 	lui	$at,%hi(var7f1b1ef4)
/*  f0f0734:	002f0821 */ 	addu	$at,$at,$t7
/*  f0f0738:	8c2f1ef4 */ 	lw	$t7,%lo(var7f1b1ef4)($at)
/*  f0f073c:	01e00008 */ 	jr	$t7
/*  f0f0740:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0744:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f0748:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f074c:	0fc39d68 */ 	jal	func0f0e75a0
/*  f0f0750:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f0f0754:	1000003e */ 	beqz	$zero,.L0f0f0850
/*  f0f0758:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f075c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f0760:	0fc3ad1b */ 	jal	func0f0eb46c
/*  f0f0764:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f0768:	10000039 */ 	beqz	$zero,.L0f0f0850
/*  f0f076c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f0770:	8fb80038 */ 	lw	$t8,0x38($sp)
/*  f0f0774:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f0778:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f077c:	0fc3afb2 */ 	jal	func0f0ebec8
/*  f0f0780:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f0784:	10000032 */ 	beqz	$zero,.L0f0f0850
/*  f0f0788:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f078c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f0790:	0fc3b2ff */ 	jal	func0f0ecbfc
/*  f0f0794:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f0798:	1000002d */ 	beqz	$zero,.L0f0f0850
/*  f0f079c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f07a0:	8fb90038 */ 	lw	$t9,0x38($sp)
/*  f0f07a4:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f07a8:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f07ac:	0fc3b499 */ 	jal	func0f0ed264
/*  f0f07b0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f07b4:	10000026 */ 	beqz	$zero,.L0f0f0850
/*  f0f07b8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f07bc:	0fc3b68d */ 	jal	func0f0eda34
/*  f0f07c0:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f0f07c4:	10000022 */ 	beqz	$zero,.L0f0f0850
/*  f0f07c8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f07cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f07d0:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f07d4:	0fc3b95d */ 	jal	func0f0ee574
/*  f0f07d8:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f0f07dc:	1000001c */ 	beqz	$zero,.L0f0f0850
/*  f0f07e0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f07e4:	8fa80038 */ 	lw	$t0,0x38($sp)
/*  f0f07e8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f07ec:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f07f0:	0fc3a04e */ 	jal	func0f0e8138
/*  f0f07f4:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0f07f8:	10000015 */ 	beqz	$zero,.L0f0f0850
/*  f0f07fc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f0800:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f0804:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f0808:	0fc3a474 */ 	jal	func0f0e91d0
/*  f0f080c:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f0f0810:	1000000f */ 	beqz	$zero,.L0f0f0850
/*  f0f0814:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f0818:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f081c:	0fc3b139 */ 	jal	func0f0ec4e4
/*  f0f0820:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f0824:	1000000a */ 	beqz	$zero,.L0f0f0850
/*  f0f0828:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f082c:	8fa90038 */ 	lw	$t1,0x38($sp)
/*  f0f0830:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f0834:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f0838:	0fc3bc80 */ 	jal	func0f0ef200
/*  f0f083c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0f0840:	10000003 */ 	beqz	$zero,.L0f0f0850
/*  f0f0844:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0f0848:
/*  f0f0848:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0f084c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0f0850:
/*  f0f0850:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0f0854:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0f0858:	03e00008 */ 	jr	$ra
/*  f0f085c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

void func0f0f0860(u8 *arg0, u32 *arg1)
{
	switch (*arg0) {
	case 2:
	case 12:
		func0f0e7998(arg0, arg1);
		break;
	case 5:
		func0f0ed514(arg1);
		break;
	case 23:
		func0f0edb50(arg1);
		break;
	case 14:
		func0f0ee640(arg1);
		break;
	case 8:
		func0f0ec220(arg1);
		break;
	case 15:
		func0f0ef360(arg0, arg1);
		break;
	case 13:
		func0f0e9744(arg0, arg1);
		break;
	case 25:
		func0f0f057c(arg1);
		break;
	}
}

GLOBAL_ASM(
glabel func0f0f0918
/*  f0f0918:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0f091c:	8faa003c */ 	lw	$t2,0x3c($sp)
/*  f0f0920:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0f0924:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f0f0928:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f0f092c:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f0f0930:	91420000 */ 	lbu	$v0,0x0($t2)
/*  f0f0934:	00057400 */ 	sll	$t6,$a1,0x10
/*  f0f0938:	0006c400 */ 	sll	$t8,$a2,0x10
/*  f0f093c:	00074400 */ 	sll	$t0,$a3,0x10
/*  f0f0940:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f0944:	00083c03 */ 	sra	$a3,$t0,0x10
/*  f0f0948:	00183403 */ 	sra	$a2,$t8,0x10
/*  f0f094c:	10410009 */ 	beq	$v0,$at,.L0f0f0974
/*  f0f0950:	000e2c03 */ 	sra	$a1,$t6,0x10
/*  f0f0954:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0f0958:	1041000b */ 	beq	$v0,$at,.L0f0f0988
/*  f0f095c:	87ac003a */ 	lh	$t4,0x3a($sp)
/*  f0f0960:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0f0964:	10410012 */ 	beq	$v0,$at,.L0f0f09b0
/*  f0f0968:	87b8003a */ 	lh	$t8,0x3a($sp)
/*  f0f096c:	1000001a */ 	beqz	$zero,.L0f0f09d8
/*  f0f0970:	00801025 */ 	or	$v0,$a0,$zero
.L0f0f0974:
/*  f0f0974:	87ab003a */ 	lh	$t3,0x3a($sp)
/*  f0f0978:	0fc398a6 */ 	jal	func0f0e6298
/*  f0f097c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f0980:	10000016 */ 	beqz	$zero,.L0f0f09dc
/*  f0f0984:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0f0988:
/*  f0f0988:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f0f098c:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0f0990:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f0994:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f0998:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0f099c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0f09a0:	0fc3a0a4 */ 	jal	func0f0e8290
/*  f0f09a4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f09a8:	1000000c */ 	beqz	$zero,.L0f0f09dc
/*  f0f09ac:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0f09b0:
/*  f0f09b0:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f0f09b4:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f0f09b8:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f0f09bc:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f09c0:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f09c4:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0f09c8:	0fc3bcbf */ 	jal	func0f0ef2fc
/*  f0f09cc:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0f09d0:	10000002 */ 	beqz	$zero,.L0f0f09dc
/*  f0f09d4:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0f09d8:
/*  f0f09d8:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0f09dc:
/*  f0f09dc:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0f09e0:	03e00008 */ 	jr	$ra
/*  f0f09e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f09e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f09ec:	00000000 */ 	sll	$zero,$zero,0x0
);
